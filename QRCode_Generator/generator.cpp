
#include"header.h"

int calalign_n(int ver) //计算校正图形数，同时为校正图形坐标赋值
{

	if (ver == 1)
		return 0;
	if (ver>1 && ver <= 6)
		return 1;
	if (ver>6 && ver <= 13)
		return 6;
	if (ver>13 && ver <= 20)
		return 13;
	if (ver>20 && ver <= 27)
		return 22;
	if (ver>27 && ver <= 34)
		return 33;
	if (ver>34 && ver <= 40)
		return 46;
	else
		return -1;
}

int calcoord_n(int ver)
{
	if (ver == 1)
		return 0;
	if (ver >= 2 && ver <= 6)
		return 2;
	if (ver >= 7 && ver <= 13)
		return 3;
	if (ver >= 14 && ver <= 20)
		return 4;
	if (ver >= 21 && ver <= 27)
		return 5;
	if (ver >= 28 && ver <= 34)
		return 6;
	else
		return 7;
}

void getalign_coord(Qrcodeinfo *qrcode, int ver)
{
	//P84 Table E.1
	if (ver > 1)
		qrcode->align_coord[0] = 6;
	if (ver >= 2 && ver <= 6)
		qrcode->align_coord[1] = 4 * ver + 10;
	if (ver > 6 && ver <= 13){
		qrcode->align_coord[1] = 2 * ver + 8;
		qrcode->align_coord[2] = 4 * ver + 10;
	}
	if (ver >= 14 && ver <= 16){
		qrcode->align_coord[1] = 26;
		qrcode->align_coord[2] = 2 * ver + 18;
		qrcode->align_coord[3] = 4 * ver + 10;
	}
	if (ver >= 17 && ver <= 19){
		qrcode->align_coord[1] = 30;
		qrcode->align_coord[2] = 2 * ver + 20;
		qrcode->align_coord[3] = 4 * ver + 10;
	}
	if (ver == 20){
		qrcode->align_coord[1] = 34;
		qrcode->align_coord[2] = 62;
		qrcode->align_coord[3] = 90;
	}
	if (ver >= 21 && ver <= 27) {
		qrcode->align_coord[3] = 2 * ver + 30;
		qrcode->align_coord[4] = 4 * ver + 10;
	}
	if (ver == 21) {
		qrcode->align_coord[1] = 28;
		qrcode->align_coord[2] = 50;
	}
	if (ver == 22){
		qrcode->align_coord[1] = 26;
		qrcode->align_coord[2] = 50;
	}
	if (ver == 23) {
		qrcode->align_coord[1] = 30;
		qrcode->align_coord[2] = 54;
	}
	if (ver == 24) {
		qrcode->align_coord[1] = 28;
		qrcode->align_coord[2] = 54;
	}
	if (ver == 25) {
		qrcode->align_coord[1] = 32;
		qrcode->align_coord[2] = 58;
	}
	if (ver == 26) {
		qrcode->align_coord[1] = 32;
		qrcode->align_coord[2] = 58;
	}
	if (ver == 27) {
		qrcode->align_coord[1] = 34;
		qrcode->align_coord[2] = 62;
	}
	if (ver >= 28 && ver <= 34)
		qrcode->align_coord[5] = 4 * ver + 10;
	if (ver >= 28 && ver <= 29)
		qrcode->align_coord[4] = 4 * ver - 14;
	if (ver == 28) {
		qrcode->align_coord[1] = 26;
		qrcode->align_coord[2] = 50;
		qrcode->align_coord[3] = 74;
	}
	if (ver == 29) {
		qrcode->align_coord[1] = 30;
		qrcode->align_coord[2] = 54;
		qrcode->align_coord[3] = 78;
	}
	if (ver >= 30 && ver <= 34)
		qrcode->align_coord[4] = 4 * ver - 16;
	if (ver == 30) {
		qrcode->align_coord[1] = 26;
		qrcode->align_coord[2] = 52;
		qrcode->align_coord[3] = 78;
	}
	if (ver == 31) {
		qrcode->align_coord[1] = 30;
		qrcode->align_coord[2] = 56;
		qrcode->align_coord[3] = 82;
	}
	if (ver == 32) {
		qrcode->align_coord[1] = 34;
		qrcode->align_coord[2] = 60;
		qrcode->align_coord[3] = 86;
	}
	if (ver == 34) {
		qrcode->align_coord[1] = 34;
		qrcode->align_coord[2] = 62;
		qrcode->align_coord[3] = 90;
	}
	if (ver >= 35 && ver <= 40)
		qrcode->align_coord[6] = 4 * ver + 10;
	if (ver == 35) {
		qrcode->align_coord[1] = 30;
		qrcode->align_coord[2] = qrcode->align_coord[1] + 24;
		qrcode->align_coord[3] = qrcode->align_coord[2] + 24;
		qrcode->align_coord[4] = qrcode->align_coord[3] + 24;
		qrcode->align_coord[5] = qrcode->align_coord[4] + 24;
	}
	if (ver == 36) {
		qrcode->align_coord[1] = 24;
		qrcode->align_coord[2] = qrcode->align_coord[1] + 26;
		qrcode->align_coord[3] = qrcode->align_coord[2] + 26;
		qrcode->align_coord[4] = qrcode->align_coord[3] + 26;
		qrcode->align_coord[5] = qrcode->align_coord[4] + 26;
	}
	if (ver == 37) {
		qrcode->align_coord[1] = 28;
		qrcode->align_coord[2] = qrcode->align_coord[1] + 26;
		qrcode->align_coord[3] = qrcode->align_coord[2] + 26;
		qrcode->align_coord[4] = qrcode->align_coord[3] + 26;
		qrcode->align_coord[5] = qrcode->align_coord[4] + 26;
	}
	if (ver == 38) {
		qrcode->align_coord[1] = 32;
		qrcode->align_coord[2] = qrcode->align_coord[1] + 26;
		qrcode->align_coord[3] = qrcode->align_coord[2] + 26;
		qrcode->align_coord[4] = qrcode->align_coord[3] + 26;
		qrcode->align_coord[5] = qrcode->align_coord[4] + 26;
	}
	if (ver == 39) {
		qrcode->align_coord[1] = 26;
		qrcode->align_coord[2] = qrcode->align_coord[1] + 28;
		qrcode->align_coord[3] = qrcode->align_coord[2] + 28;
		qrcode->align_coord[4] = qrcode->align_coord[3] + 28;
		qrcode->align_coord[5] = qrcode->align_coord[4] + 28;
	}
	if (ver == 40) {
		qrcode->align_coord[1] = 30;
		qrcode->align_coord[2] = qrcode->align_coord[1] + 28;
		qrcode->align_coord[3] = qrcode->align_coord[2] + 28;
		qrcode->align_coord[4] = qrcode->align_coord[3] + 28;
		qrcode->align_coord[5] = qrcode->align_coord[4] + 28;
	}
}

void getxy_coord(position *posi, Qrcodeinfo *qrcode,int n)
{
	//例：6,24,42
	//(6,24) (24,6) (24,24) (24,42) (42,24) (42,42)
	int min_coord = qrcode->align_coord[0], max_coord = qrcode->align_coord[calcoord_n(qrcode->ver) - 1];
	int k = 0;
	for (int i = 0; i < calcoord_n(qrcode->ver); i++) {
		for (int j = 0; j < calcoord_n(qrcode->ver); j++) {
			if (j == i&&i == 0)
				continue;//(6,6)
			if ((j == 0 && i == calcoord_n(qrcode->ver) - 1) || (i == 0 && j == calcoord_n(qrcode->ver) - 1))
				continue;//(6,42) (42,6)
			posi[k].x= qrcode->align_coord[j];
			posi[k].y= qrcode->align_coord[i];
			k++;
		}
	}
}


int code_to_num(char *str)
{
	//把二进制数转化为十进制
	int sum = 0;
	for (int i = 0; i <= 7; i++) {
		sum += (str[i] - '0')*(int)pow(2, 7 - i);
	}
	return sum;
}

void addfuncpart(char **finbin, Qrcodeinfo* qrcode)
{
	//功能图形区域不参与掩膜
	add_separator(finbin, qrcode);
	add_finderpattern(finbin, qrcode);
	add_alignmentpatt(finbin, qrcode);
	add_timingpatt(finbin, qrcode);
	add_verinfo(finbin, qrcode);
	add_formatinfo(finbin, qrcode);
}

void draw_outside(Qrcodeinfo *qrcode)
{
	int i, j, len = qrcode->length;
	for(i=0;i<len+2;i++)
		for (j = 0; j < len + 2; j++) {
			gotoxy(hout, 2 * j, i);
			setcolor(hout, 15, 0);
			cout << "  ";
		}
}


void draw_finbin(char **finbin, Qrcodeinfo *qrcode)
{
	int i, j, len = qrcode->length;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			gotoxy(hout, 2 * j + 2, i + 1);
			if (finbin[i][j] == '0')
				setcolor(hout, 15, 0);
			else if (finbin[i][j] == '1')
				setcolor(hout, 0, 15);
			else
				continue;
			cout << "  ";
		}
	}
}

void add_rect_frame(char** finbin, Qrcodeinfo *qrcode, int x, int y, int len, char to_add)
{
	//矩形边框数据
	//(x,y)为左上角的坐标
	int i, j;
	for (i = x, j = y; j < len + y; j++)
		finbin[i][j] = to_add;
	for (i = x, j = y; i < len + x; i++)
		finbin[i][j] = to_add;
	for (i = len + x - 1, j = y; j < len + y; j++)
		finbin[i][j] = to_add;
	for (i = x, j = len + y - 1; i < len + x; i++)
		finbin[i][j] = to_add;
}

void add_separator(char **finbin, Qrcodeinfo* qrcode)
{
	int l = qrcode->length;
	add_rect_frame(finbin, qrcode, 0, 0, 8, '0');
	add_rect_frame(finbin, qrcode, 0, l - 8, 8, '0');
	add_rect_frame(finbin, qrcode, l - 8, 0, 8, '0');
}

void add_finderpattern(char **finbin, Qrcodeinfo* qrcode)
{
	int i, j, len = qrcode->length;
	add_rect_frame(finbin, qrcode, 0, 0, 7, '1');
	add_rect_frame(finbin, qrcode, 0, len - 7, 7, '1');
	add_rect_frame(finbin, qrcode, len - 7, 0, 7, '1');
	add_rect_frame(finbin, qrcode, 1, 1, 5, '0');
	add_rect_frame(finbin, qrcode, 1, len - 6, 5, '0');
	add_rect_frame(finbin, qrcode, len - 6, 1, 5, '0');
	for (i = 2; i <= 4; i++){
		for (j = 2; j <= 4; j++) 
			finbin[i][j] = '1';
		for (j = len - 5; j <= len - 3; j++) 
			finbin[i][j] = '1';
	}
	for (i = len - 5; i <= len - 3; i++)
		for (j = 2; j <= 4; j++) 
			finbin[i][j] = '1';
}

void add_timingpatt(char **finbin, Qrcodeinfo* qrcode)
{
	int i, j, count = 1, len = qrcode->length;
	for (i = 6, j = 8; j <= len - 1; j++, count++) {
		if (finbin[i][j] == 0)
			finbin[i][j] = count % 2 + '0';//0 1交替
	}
	count = 1;
	for (i = 8, j = 6; i <= len - 1; i++, count++) {
		if (finbin[i][j] == 0)
			finbin[i][j] = count % 2 + '0';//0 1交替
	}
}

void add_verinfo(char **finbin, Qrcodeinfo* qrcode)
{
	if (qrcode->ver < 7)
		return;
	int i, j, len = qrcode->length, n = 0;
	for (i = 5; i >= 0; i--)//右上部分
		for (j = len - 9; j >= len - 11; j--)
			finbin[i][j] = verinfo[qrcode->ver - 7][n++];
	n = 0;
	for (j = 5; j >= 0; j--)
		for (i = len - 9; i >= len - 11; i--)
			finbin[i][j] = verinfo[qrcode->ver - 7][n++];
}

void add_alignmentpatt(char **finbin, Qrcodeinfo* qrcode)
{
	int i, j, l = qrcode->length, coordn = (int)sqrt(qrcode->align_n + 3);
	for(i=0;i<coordn;i++)
		for (j = 0; j < coordn; j++) {
			if (i == 0 && j == 0)
				continue;
			if (i == 0 && j == coordn - 1)
				continue;
			if (i == coordn - 1 && j == 0)
				continue;
			finbin[qrcode->align_coord[i]][qrcode->align_coord[j]] = '1';
			add_rect_frame(finbin, qrcode, qrcode->align_coord[i] - 1, qrcode->align_coord[j] - 1, 3, '0');
			add_rect_frame(finbin, qrcode, qrcode->align_coord[i] - 2, qrcode->align_coord[j] - 2, 5, '1');
		}
}

void add_formatinfo(char **finbin, Qrcodeinfo* qrcode)
{
	//init part
	int i, j, len = qrcode->length, n = 14;
	for (i = 0, j = 8; i <= 5; i++)
		finbin[i][j] = '0';
	//dark module
	for (i = 7, j = 8; i <= 8; i++)
		finbin[i][j] = '0';
	//dark module
	for (i = len - 8, j = 8; i <= len - 1; i++)
		finbin[i][j] = '0';
	for (i = 8, j = len - 1; j >= len - 8; j--)
		finbin[i][j] = '0';
	for (i = 8, j = 8; j >= 7; j--)
		finbin[i][j] = '0';
	//timing patt
	for (i = 8, j = 5; j >= 0; j--)
		finbin[i][j] = '0';

	//add part
	for (i = 0, j = 8; i <= 5; i++)
		finbin[i][j] = formatinfo[n--];
	for (i = 7, j = 8; i <= 8; i++)
		finbin[i][j] = formatinfo[n--];
	//dark module
	finbin[len - 8][8] = '1';
	for (i = len - 7, j = 8; i <= len - 1; i++)
		finbin[i][j] = formatinfo[n--];
	//第一组format info完毕 上下方向
	n = 14;
	//第二组：从右到左
	for (i = 8, j = len - 1; j >= len - 8; j--)
		finbin[i][j] = formatinfo[n--];
	//两线交点左侧的位置单独赋值
	finbin[8][7] = formatinfo[n--];
	for (i = 8, j = 5; j >= 0; j--)
		finbin[i][j] = formatinfo[n--];
}

void add_data(char **finbin, char **findbin, Qrcodeinfo* qrcode, CodeArray* datacode)
{
	int i, j, k, Dn1 = qrcode->ecodata.CKR[0][1], Dn2 = qrcode->ecodata.CKR[1][1];
	int En1 = qrcode->ecodata.CKR[0][0] - Dn1;
	//总块数
	int blockn = qrcode->ecodata.blockn[0] + qrcode->ecodata.blockn[1];
	int blockn1 = qrcode->ecodata.blockn[0], count = 0;
	//对较短长度的数据码字的填入
	for (i = 0; i < Dn1; i++)
		for (j = 0; j < blockn; j++)
			for (k = 0; k < 8; k++)
				fill_block_data(qrcode, finbin, findbin, datacode[j][i][k]);

	for (i = Dn1; i < Dn2; i++)
		for (j = blockn1; j < blockn; j++)
			for (k = 0; k < 8; k++)
				fill_block_data(qrcode, finbin, findbin, datacode[j][i][k]);
	//对纠错码字的填入
	for (i = 0; i < En1; i++)
		for (j = blockn; j < 2 * blockn; j++)
			for (k = 0; k < 8; k++)
				fill_block_data(qrcode, finbin, findbin, datacode[j][i][k]);
				//nextblock(qrcode, finbin, findbin, datacode[j][i][k]);
	for (i = 0; i <= 20; i++)
		fill_block_data(qrcode, finbin, findbin, '0');
}

void fill_block_data(Qrcodeinfo *qrcode, char **finbin, char **findbin, char data)
{
	//调用该函数时自动寻找下一个可填入数据的位置
	int len = qrcode->length, count;
	static int x = 0, y = 0, flag1 = 0, flag2 = 0, init = 1;
	//当填充的模块位于竖直栏的右侧时flag1=0 当向上填充时flag2=0
	//填充方式为两两向上或向下，即两侧不能横向跨越
	//检测
	if (init == 1) {
		//第一次调用时初始化坐标位置
		x = len - 1;
		y = len - 1;
		init = 0;
	}
	for (count = 0; count <= 10000; count++) {
		//寻找位置
		if (y == len - 9 && x == 0)
			break;
		if (finbin[y][x] == 0 && findbin[y][x] == 0)
			break;
		if (y == len - 1)
			if (flag2 == 1) {
				//已经在最下面位置 当前向下填充
				if (flag1 == 1) {
					//移动到下一个竖直栏，但可能出现本栏最后一个未填入的情况
					flag2 = 0;//改为向上填充模式
					if (is_col_full(qrcode, finbin, x - 1))
						x = x - 2;
					else
						x--;
					flag1 = 0;
					if (finbin[y][x] == 0)
						break;
					else
						continue;
				}
			}
		if (y == 0)
			if (flag2 == 0) {
				//已经在最上面 当前向上填充
				if (flag1 == 1) {
					flag2 = 1;
					if (is_col_full(qrcode, finbin, x - 1))
						x = x - 2;
					else
						x--;
					flag1 = 0;
					if (finbin[y][x] == 0)
						break;
					else
						continue;
				}
			}
		if (flag1 == 0 && flag2 == 0) {
			//已经在竖直栏右侧，只需向左移动一个单位即可
			x--;
			flag1 = 1;
		}
		else if (flag1 == 1 && flag2 == 0) {
			//向右上移动一格
			y--;
			x++;
			flag1 = 0;
		}
		else if (flag1 == 1 && flag2 == 1) {
			//向右下移动一格
			y++;
			x++;
			flag1 = 0;
		}
		else if (flag1 == 0 && flag2 == 1) {
			x--;
			flag1 = 1;
		}
		if (finbin[y][x] == 0)
			break;
	}
	if (finbin[y][x] == 0)
		findbin[y][x] = data;
}

void finbin_init(Qrcodeinfo* qrcode, char** finbin)
{
	int i, j, len = qrcode->length;
	char **fbin = new char*[len];
	fbin = finbin;
	//char (*fbin)[len] = finbin;
	for (i = 0; i <= len - 1; i++)
		for (j = 0; j <= len - 1; j++)
			fbin[i][j] = 0;
}

int is_col_full(Qrcodeinfo* qrcode, char** finbin, int col)
{
	int len = qrcode->length, i;
	for (i = 0; i <= len - 1; i++)
		if (finbin[i][col] == 0) 
			return 0;
	return 1;
}

const byte* get_gp(unsigned int numBlocks)
{
	int i;
	for (i = 0; i < 31; i++) {
		if (gp[i][0] == numBlocks) {
			return (gp[i] + 1);
		}
	}
	return NULL;
}

void asciitobin(char* text, char* bin)
{
	char* p, *data;
	unsigned int len = 9, reallen;
	char temp[10];
	for (int i = 0; text[i]; i++)
	{
		if (text[i] > 0)
			_itoa(text[i], temp, 2);
		else 
			_itoa(-1 * text[i], temp, 2);
		reallen = strlen(temp);
		data = (char*)malloc(len);
		for (p = data; p < data + len - reallen - 1; p++)
			*p = '0';  //data：前有len-l-1个0
		strcpy(p, temp);
		p = data;
		if (text[i] < 0) {
			int j = 0;
			while (p[j]) {
				if (p[j] == '1')
					p[j] = '0';
				else if (p[j] == '0')
					p[j] = '1';
				if (j == strlen(p) - 1) {
					int k = j;
					while (k > 0 && p[k] == '1') {
						//进位
						p[k] = '0';
						k--;
					}
					p[k] = '1';
				}
				j++;
			}
		}
		strcat(bin, data);
		free(data);
	}
}


CodeArray Calecode(CodeArray msgcode, int n, int k)
{
	//myself version
	//n:总的码字数 k:数据码字数
	//n-k:纠错码字数
	//H级别：生成多项式项数多于消息多项式项数
	int i, j, *msgnum, len;
	msgnum = (int *)malloc(sizeof(int)*k);
	//数据码字的每项对应的十进制数
	for (int i = 0; i < k; i++) {
		msgnum[i] = code_to_num(msgcode[i]);//十进制数
	}
	CodeArray Ecode = (CodeArray)malloc((n - k) * 9);//纠错码
	char temp[9];
	int ecblocks = n - k;//每块需要纠错码字的个数
	const byte *genpoly = get_gp(ecblocks);//生成多项式
	//genpoly项数为ecblocks+1,第一项系数为0
	byte *Enum;//存储系数
	Enum = new(nothrow) byte[n];
	for (i = 0; i < n; i++) {
		//第一次计算用数据多项式 后面补0
		if (i < k)
			Enum[i] = msgnum[i];
		else
			Enum[i] = 0;
	}
	for (i = 0; i < k; i++) {
		//除法的次数必须等于消息多项式中的项数
		byte add = petoal(Enum[i]);
		for (j = 0; j < ecblocks+1; j++) {
			//生成多项式乘以消息多项式的第一项
			//如果i不为0则乘以前一步结果的第一项
			//将此项与上一步结果进行XOR操作
			unsigned int alpha = add + genpoly[j];
			if (alpha >255U) alpha -= 255U; // alpha mustn't overflow
			Enum[j + i] = altope(alpha) ^ Enum[j + i];
		}
		
	}
	for (i = 0; i <= n - k - 1; i++)
	{
		_itoa(Enum[i+k], temp, 2);
		len = strlen(temp);
		for (j = 0; j < 8 - len; j++)
			Ecode[i][j] = '0';
		strcpy(Ecode[i] + 8 - len, temp);
	}
	return Ecode;
}


int petoal(const byte integer) 
{
	int i;
	for (i = 0; i < 256; i++) {
		if (galois[i] == integer) return i;
	}
	return -1;
}

byte altope(const int alpha) 
{
	if (alpha < 0 || alpha > 255) 
		return 0; // not in range
	return galois[alpha];
}