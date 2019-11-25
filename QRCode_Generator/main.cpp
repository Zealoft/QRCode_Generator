
#include "header.h"

int main()
{
	setcolor(hout, 0, 7);
	setconsoleborder(hout, 120, 30);
	system("cls");
	static Qrcodeinfo qrdata;
	Qrcodeinfo* qrcode = &qrdata;
	char input[100];
	
	cout << "请输入一段文字或网址(不大于100字符):";
	cin.getline(input, 100);
	
	char *utf, *gb2312;

	utf = G2U(input);
	gb2312 = U2G(input);
	
	int mode = str_analysis(utf);
	int ver = ver_determine(utf, mode);
	QRinit(qrcode, ver);
	int length = ver * 4 + 17;
	char bin[MAXNUM] = { 0 };
	bin_init(ver, mode, bin, strlen(utf));
	char **finbin = new(nothrow) char*[qrcode->length];
	for (unsigned int i = 0; i < qrcode->length; i++)
		finbin[i] = new(nothrow) char[qrcode->length];

	char **findbin = new(nothrow) char*[qrcode->length];
	for (unsigned int i = 0; i < qrcode->length; i++)
		findbin[i] = new(nothrow) char[qrcode->length];

	char **mask = new(nothrow) char*[qrcode->length];
	for (unsigned int i = 0; i < qrcode->length; i++)
		mask[i] = new(nothrow) char[qrcode->length];
	finbin_init(qrcode, finbin);
	finbin_init(qrcode, findbin);

	if (mode == NUMBERMODE) {
		char(*part)[4] = num_strdivide(input);
		numtobin(part, bin);
	}
	if (mode == ASCIIMODE) {
		asciitobin(utf, bin);
	}
	terminator(qrcode, bin);

	//cout << bin << endl;

	CodeArray msgcode, *datacode;
	msgcode = tomsgcode(qrcode, bin);
	datacode = todatacode(qrcode, msgcode);
	//system("pause");
	
	addfuncpart(finbin, qrcode);
	add_data(finbin, findbin, qrcode, datacode);
	maskinit(mask, qrcode, 3);
	calc_mask(mask, findbin, qrcode);

	setfontsize(hout, L"点阵字体", 14 - (ver + 1));
	setconsoleborder(hout, (length + 3) * 2, length + 4);
	setcolor(hout, 7, 0);
	system("cls");
	setcolor(hout, 7, 0);
	
	draw_finbin(finbin, qrcode);
	draw_finbin(findbin, qrcode);

	setcolor(hout, 0, 7);
	gotoxy(hout, 0, length + 2);

	//delete part
	for (unsigned int i = 0; i < qrcode->length; i++) {
		delete[]finbin[i];
		delete[]findbin[i];
		delete[]mask[i];
	}
	delete[]finbin;
	delete[]findbin;
	delete[]mask;

	return 0;
}

