// UTF-8Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "UTF-8.h"
#include "UTF-8Dlg.h"
#include <windows.h>
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUTF8Dlg 对话框




CUTF8Dlg::CUTF8Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUTF8Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUTF8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUTF8Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CUTF8Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CUTF8Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CUTF8Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CUTF8Dlg 消息处理程序

BOOL CUTF8Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUTF8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CUTF8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CUTF8Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
}

void CUTF8Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}


CString HexToBin(CString string)//将16进制数转换成2进制
{
	if( string == "0") return "0000";
	if( string == "1") return "0001";
	if( string == "2") return "0010";
	if( string == "3") return "0011";
	if( string == "4") return "0100";
	if( string == "5") return "0101";
	if( string == "6") return "0110";
	if( string == "7") return "0111";
	if( string == "8") return "1000";
	if( string == "9") return "1001";
	if( string == "a") return "1010";
	if( string == "b") return "1011";
	if( string == "c") return "1100";
	if( string == "d") return "1101";
	if( string == "e") return "1110";
	if( string == "f") return "1111";
	if( string == "A") return "1010";
	if( string == "B") return "1011";
	if( string == "C") return "1100";
	if( string == "D") return "1101";
	if( string == "E") return "1110";
	if( string == "F") return "1111";
	return "";
}


CString BinToHex(CString BinString)//将2进制数转换成16进制
{
	if( BinString == "0000") return "0";
	if( BinString == "0001") return "1";
	if( BinString == "0010") return "2";
	if( BinString == "0011") return "3";
	if( BinString == "0100") return "4";
	if( BinString == "0101") return "5";
	if( BinString == "0110") return "6";
	if( BinString == "0111") return "7";
	if( BinString == "1000") return "8";
	if( BinString == "1001") return "9";
	if( BinString == "1010") return "a";
	if( BinString == "1011") return "b";
	if( BinString == "1100") return "c";
	if( BinString == "1101") return "d";
	if( BinString == "1110") return "e";
	if( BinString == "1111") return "f";
	return "";
}

int BinToInt(CString string)//2进制字符数据转换成10进制整型
{
	int len =0;
	int tempInt = 0;
	int strInt = 0;
	for(int i =0 ;i < string.GetLength() ;i ++)
	{
	        tempInt = 1;
	        strInt = (int)string.GetAt(i)-48;
	        for(int k =0 ;k < 7-i ; k++)
	        {
			tempInt = 2*tempInt;
	        }
	        len += tempInt*strInt;
	}
	return len;
}      
VOID UTF_8ToUnicode(char ustart[3],char wcharo[2])  //把UTF-8转换成Unicode
{
	char char_one;
	char char_two;
	char char_three;
	int Hchar;
	int Lchar;
	CString string_one;
	CString string_two;
	CString string_three;
	CString combiString;
	char_one = ustart[0];
	char_two = ustart[1];
	char_three = ustart[2];
	string_one.Format("%x",char_one);
	string_two.Format("%x",char_two);
	string_three.Format("%x",char_three);
	string_three = string_three.Right(2);
	string_two = string_two.Right(2);
	string_one = string_one.Right(2);
	string_three = HexToBin(string_three.Left(1))+HexToBin(string_three.Right(1));
	string_two = HexToBin(string_two.Left(1))+HexToBin(string_two.Right(1));
	string_one = HexToBin(string_one.Left(1))+HexToBin(string_one.Right(1));
	combiString = string_one +string_two +string_three;
	combiString = combiString.Right(20);
	combiString.Delete(4,2);
	combiString.Delete(10,2);
	Hchar = BinToInt(combiString.Left(8));
	Lchar = BinToInt(combiString.Right(8));
	wcharo[1] = (char)Hchar;
	wcharo[0] = (char)Lchar;
}


char * UnicodeToGB2312(WCHAR uData[255])  //把Unicode 转换成 GB2312
{
	char *buffer ;
	WCHAR			data[255];
	data[0]=uData[0];
	data[1]=uData[1];
	data[2]=0;
	data[3]=0;
	data[4]=0;
	buffer = new char[sizeof(WCHAR)];
	WideCharToMultiByte(CP_ACP,NULL,(LPCWSTR)data,1,buffer,sizeof(WCHAR),NULL,NULL);
	return buffer;
} 

INT HexToInt(char *ch)
{
	CString lch,rch,revelue;
	lch.Format("%c",ch[0]);
	lch=HexToBin(lch);
	rch.Format("%c",ch[1]);
	rch=HexToBin(rch);
	revelue=lch+rch;
	return		BinToInt(revelue);
}

CString AnsiFromUtf8Chars(CString InStr)
{
	CString			OutS;
	char			temp[255],InChar[255],OutChar[255];
	char*			tempchar=new char[255];
	WCHAR			resault[255];

	tempchar=InStr.GetBuffer();
	
	temp[0]=tempchar[0];
	temp[1]=tempchar[1];
	temp[2]=0;
	InChar[0]=(char)HexToInt(temp);

	temp[0]=tempchar[3];
	temp[1]=tempchar[4];
	temp[2]=0;
	InChar[1]=(char)HexToInt(temp);

	temp[0]=tempchar[6];
	temp[1]=tempchar[7];
	temp[2]=0;
	InChar[2]=(char)HexToInt(temp);

	InChar[3]=0;

	memset(OutChar,0,255);

	UTF_8ToUnicode(InChar,OutChar);

	memcpy(resault,OutChar,4);

	tempchar=UnicodeToGB2312(resault);

	OutS.Format("%s",tempchar);

	OutS=OutS.Left(2);

	return		OutS;
}

void CUTF8Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString			in,out;
	char*			Inchar=new char[0x8000];
	INT				step=0,len;
	GetDlgItemText(IDC_EDIT1,in);
	len=in.GetLength();
	if (len>0x8000)
	{
		MessageBox("Too Long!",0,0);
		return;
	}
	Inchar=in.GetBuffer();
	while (len-step>=8)
	{
		char		temp[255];
		CString		tempstr;
		temp[0]=Inchar[step];
		temp[1]=Inchar[step+1];
		temp[2]=Inchar[step+2];
		temp[3]=Inchar[step+3];
		temp[4]=Inchar[step+4];
		temp[5]=Inchar[step+5];
		temp[6]=Inchar[step+6];
		temp[7]=Inchar[step+7];
		temp[8]=0;
		tempstr.Format("%s",temp);

		tempstr=AnsiFromUtf8Chars(tempstr);

		out=out+tempstr;
		step=step+9;
	}

	SetDlgItemText(IDC_EDIT2,out);
		
}

