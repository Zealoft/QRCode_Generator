#include "header.h"

//�����������ͣ�����ֵ˵����0�����֣�1��8λ�ֽ�
int str_analysis(char *text)
{
	for (; *text; text++)
		if (*text<'0' || *text>'9')
			return 1;
	return 0;
}

//����ģʽ�������������������λ��
//��������Ϊһ�飬�����������
int numcal(int n)
{
	int finn;
	int coden = n / 3;
	int leftn = n % 3;
	//����1��2λת��4��7bits
	switch (leftn) {
	case 0:
		finn = coden * 10;
		break;
	case 1:
		finn = coden * 10 + 4;
		break;
	case 2:
		finn = coden * 10 + 7;
		break;
	}
	if (n <= 235)
		finn += 10 + 4;
	//4:���ֱ���ı�־
	//10:���ָ����ı�־ 
	else if (n <= 1425)
		finn += 12 + 4;
	else
		finn += 14 + 4;
	return finn;
}

//ASCIIģʽ����λ�ֽ�
int asciical(int n)
{
	int finn = 8 * n;
	if (n <= 98)
		finn += 4 + 8;
	else
		finn += 4 + 16;
	return finn;
}




int ver_determine(char *text, int mode)
{
	unsigned int len = strlen(text);
	unsigned int num;
	if (mode == NUMBERMODE)
		num = numcal(len);
	else if (mode == ASCIIMODE)
		num = asciical(len);
	else {
		printf("����ʶ��Ĵ���\n");
		return -1;
	}
	for (unsigned int ver = 1; ver <= MAXVERSION; ver++)
	{
		unsigned int msgn = getmsgn(ver);
		if (msgn < num) {
			if (ver == MAXVERSION)
				return -1;
			msgn = getmsgn(ver + 1);
			if (msgn >= num)
				return (ver + 1);
		}
		else if (ver == 1)
			return 1;
	}
	return -2;
}

//����Ϣģ�������޾���
unsigned int getmsgn(unsigned int ver)
{
	unsigned int funcn;
	unsigned int formatn = ver <= 6 ? 31 : 67;
	if (ver == 1)
		funcn = 202;
	else
		funcn = 180 + 25 * calalign_n(ver) + 2 * (17 + 4 * ver) - 10 * (int)sqrt(3 + calalign_n(ver));
	unsigned int datan = (17 + 4 * ver)*(17 + 4 * ver) - funcn - formatn;//����version
	unsigned int msgn = (datan - econfig[ver - 1].ecoden * 8) / 8 * 8; //���ձ�׼����Ϣλ������������ӦΪ8�ı���
	return msgn;
}

//�ڶ������������ģʽָʾ���ͼ���ָʾ��
void bin_init(int ver, int mode, char *bin, int n)
{
	// ReSharper disable CppJoinDeclarationAndAssignment
	char temp[16], *p;
	// ReSharper restore CppJoinDeclarationAndAssignment
	int len;
	strcat(bin, modeindic[mode]);

	_itoa(n, temp, 2);//���ַ���ת��Ϊ�������ַ�����
	int reallen = strlen(temp);
	if (ver >= 1 && ver <= 9) {
		len = 11;
		if (mode == ASCIIMODE)
			len = 9;
	}
	if (ver >= 10 && ver <= 26) {
		len = 13;
		if (mode == ASCIIMODE)
			len = 17;
	}
	if (ver >= 27 && ver <= 40) {
		len = 15;
		if (mode == ASCIIMODE)
			len = 17;
	}
	char *data = (char *)malloc(len);
	for (p = data; p < data + len - reallen - 1; p++)
		*p = '0';
	strcpy(p, temp);
	strcat(bin, data);
	free(data);
}

char(*num_strdivide(char* text))[4] //��ԭ�ı����飬����һ����ָ��
{
	static char part[200][4];
	char(*p)[4] = part, *q = text;
	int j = 0;
	for (; *q; j++) {
		if (j != 0 && j % 3 == 0)
			p++;//��һ��
		(*p)[j % 3] = *q++;
	}
	return part;
}

void numtobin(char(*part)[4], char *bin)//������������������
{
	int dint;
	unsigned int l, len;
	char temp[12], *data, *p;
	for (; (*part)[0]; part++)
	{
		dint = atoi(*part);
		_itoa(dint, temp, 2);
		l = strlen(temp);
		if (strlen(*part) == 2)
			len = 8;
		else if (strlen(*part) == 1)
			len = 5;
		else
			len = 11;
		data = (char *)malloc(len);
		for (p = data; p < data + len - l - 1; p++)
			*p = '0';
		strcpy(p, temp);
		strcat(bin, data);
		free(data);
	}
}



void QRinit(Qrcodeinfo *qrcode, int ver)
{
	qrcode->ver = ver;
	if (ver > MAXVERSION) {
		cout << "������ǰ�汾���ƣ�" << endl;
		return;
	}
	qrcode->length = 17 + 4 * ver;
	qrcode->align_n = calalign_n(ver);
	getalign_coord(qrcode, ver);
	if (ver == 1)
		qrcode->funcn = 202;
	else
		qrcode->funcn = 180 + 25 * qrcode->align_n + 2 * qrcode->length - 10 * (int)sqrt(3 + qrcode->align_n);
	qrcode->formatn = ver <= 6 ? 31 : 67;
	qrcode->datan = qrcode->length*qrcode->length - qrcode->funcn - qrcode->formatn;//D=A^2-B-C
	qrcode->coden = qrcode->datan / 8;//data capacity
	qrcode->ecodata = econfig[ver - 1];
	qrcode->msgn = (qrcode->datan - qrcode->ecodata.ecoden * 8) / 8 * 8; //���ձ�׼����Ϣλ������������ӦΪ8�ı���
	qrcode->msgcode = qrcode->msgn / 8;
	qrcode->remainbit = qrcode->datan % 8;
}

void terminator(Qrcodeinfo* qrcode, char* bin)
{
	//4.1.22 terminator
	//used to end the bit string representing data
	int remainbit = qrcode->msgn - strlen(bin), i;
	if (remainbit < 4)
		for (i = 1; i <= remainbit; i++)
			strcat(bin, "0");
	unsigned int j = 0;
	for (i = 1; i <= 4; i++)
		strcat(bin, "0");
}

CodeArray tomsgcode(Qrcodeinfo* qrcode, char* bin)
{
	int num = qrcode->msgcode;
	CodeArray msgcode = (CodeArray)malloc(num * 9);
	CodeArray p = msgcode;
	unsigned int j = 0;
	for (; *bin; j++) {
		if (j != 0 && j % 8 == 0) {
			(*p)[8] = 0;
			p++;
		}
		(*p)[j % 8] = *bin++;
	}
	(*p)[8] = 0;
	if (j % 8 != 0)
		for (; j % 8; j++)
			(*p)[j % 8] = '0';//���뵽8λ
	(*p)[8] = 0;
	for (p = p + 1, j = 0; p <= msgcode + num - 1; p++, j++)
		strcpy(*p, filler[j % 2]);
	(*p)[0] = 0;
	return msgcode;
}



CodeArray* todatacode(Qrcodeinfo* qrcode, CodeArray msgcode)
{
	int m = 0, t = 0, i, j, k, n;
	int num = (qrcode->ecodata.blockn[0] + qrcode->ecodata.blockn[1]) * 2;//ÿ��blockn���������ֺ;������ָ���һ��CodeArray���ʳ�2
	CodeArray* datacode = (CodeArray*)malloc(num * sizeof(CodeArray));
	CodeArray p;
	for (j = 0; j <= 1; j++){
		int Dn = qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ������������
		n = qrcode->ecodata.blockn[j];  //�ڣ�j+1�����Ϳ�Ŀ���
		for (k = 0; k <= n - 1; k++){
			p = (CodeArray)malloc(Dn * 9);
			for (i = 0; i <= Dn - 1; i++)
				strcpy(p[i], *msgcode++);
			datacode[m++] = p;
		}
	}
	for (j = 0; j <= 1; j++){
		int Dn = qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ������������
		int En = qrcode->ecodata.CKR[j][0] - qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ�ľ���������
		n = qrcode->ecodata.blockn[j];
		for (k = 0; k <= n - 1; k++){
			p = Calecode(datacode[t++], Dn + En, Dn);
			//printf("��%d�����������Ѽ���,n=%d\n", k + 1, n);
			datacode[m++] = p;
		}
	}
	return datacode;
}


void maskinit(char **msk, Qrcodeinfo *qrcode, int mode)
{
	int i, j, len = qrcode->length;
	for (i = 0; i <= len - 1; i++)
		for (j = 0; j <= len - 1; j++) {
			if (mode == 0) {
				//000
				if ((i + j) % 2 == 0)
					msk[i][j] = '1';
				else
					msk[i][j] = '0';
			}
			if (mode == 1) {
				//001
				if (i % 2 == 0)
					msk[i][j] = '1';
				else msk[i][j] = '0';
			}
			if (mode == 2) {
				//010
				if (j % 3 == 0)
					msk[i][j] = '1';
				else
					msk[i][j] = '0';
			}
			if (mode == 3) {
				//011
				if ((i + j) % 3 == 0)
					msk[i][j] = '1';
				else
					msk[i][j] = '0';
			}
			if (mode == 4) {
				//100
				if ((i / 2 + j / 3) % 2 == 0)
					msk[i][j] = '1';
				else
					msk[i][j] = '0';
			}
			if (mode == 5) {
				//101
				if (i % 2 == 0)
					msk[i][j] = '1';
				else
					msk[i][j] = '0';
			}
			if (mode == 6) {
				//110
				if (i % 2 == 0)
					msk[i][j] = '1';
				else
					msk[i][j] = '0';
			}
			if (mode == 7) {
				//111
				if (i % 2 == 0)
					msk[i][j] = '1';
				else msk[i][j] = '0';
			}
		}
}

void calc_mask(char **msk, char **findbin, Qrcodeinfo *qrcode)
{
	//������������ָ��������������
	int i, j, mask, len = qrcode->length;
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++) {
			if (findbin[i][j]) {
				mask = (findbin[i][j] - '0') ^ (msk[i][j] - '0');
				findbin[i][j] = mask + '0';
			}
		}
}

char* G2U(const char* gb2312)
{
	//GB2312��UTF-8��ת��
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char *str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr)
		delete[] wstr;
	return str;
}

char* U2G(const char* utf8)
{
	//UTF-8��GB2312
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char *str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr)
		delete[] wstr;
	return str;
}