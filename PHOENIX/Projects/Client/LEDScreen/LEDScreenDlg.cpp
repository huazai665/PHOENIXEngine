
// LEDScreenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LEDScreen.h"
#include "LEDScreenDlg.h"
#include "afxdialogex.h"
#include "LEDGBCODE.h"
#include "Globals.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLEDScreenDlg �Ի���



CLEDScreenDlg::CLEDScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LEDSCREEN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLEDScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOG, mEditLog);
	DDX_Control(pDX, IDC_IP_SCREEN, mIP);
	DDX_Control(pDX, IDC_EDIT_TEXTSEND, mEditSend);
}

BEGIN_MESSAGE_MAP(CLEDScreenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START_SEVER, &CLEDScreenDlg::OnBnClickedButtonStartSever)
	ON_EN_CHANGE(IDC_EDIT_LOG, &CLEDScreenDlg::OnEnChangeEditLog)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CLEDScreenDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// CLEDScreenDlg ��Ϣ�������

BOOL CLEDScreenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	mIP.SetAddress(192, 168, 1, 149);
	SetDlgItemText(IDC_EDIT_TEXTSEND, CString("Test"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CLEDScreenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLEDScreenDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLEDScreenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLEDScreenDlg::OnBnClickedButtonStartSever()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLEDScreenDlg::OnEnChangeEditLog()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CLEDScreenDlg::OnBnClickedButtonSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	mIP.GetWindowText(str);		//Ŀ��ip
	CString ip = str;

	mEditSend.GetWindowText(str);	//��ʾ����
	CString info = str;

	UINT mateuid = 61;
	UINT areaW = 64;
	UINT areaH = 32;

	UINT movestyle = 1;	//��ʾ��ʽ
	UINT movespeed = 1;	//�ƶ��ٶ�
	UINT fontsize = 1;	//��ʾ�ֺ�
	UINT fontbody = 1;	//��ʾ����
	UINT fontcolor = 1;	//��ʾ��ɫ
	UINT stoptim = 0;	//ͣ��ʱ��
	BOOL brownsave = 1;		//���籣��

	UINT pixelcolor = 0; // ��˫��ɫ

	extern filedll qydll;
	HINSTANCE Ddll = qydll.Ddll;
	extern CLEDGBCODEudp LEDGBCODEudp;
	LEDGBCODEudp.ip = ip;
	LEDGBCODEudp.mateuid = mateuid;
	LEDGBCODEudp.areaW = areaW;
	LEDGBCODEudp.areaH = areaH;
	LEDGBCODEudp.movestyle = movestyle;
	LEDGBCODEudp.movespeed = movespeed;
	LEDGBCODEudp.fontsize = fontsize;
	LEDGBCODEudp.fontbody = fontbody;
	LEDGBCODEudp.fontcolor = fontcolor;
	LEDGBCODEudp.stoptim = stoptim;
	LEDGBCODEudp.brownsave = brownsave;
	LEDGBCODEudp.pixelcolor = pixelcolor;
	LEDGBCODEudp.str = info;

	BOOL sign = LEDGBCODEudp.senddt(Ddll);
	if (sign)
	{
		MessageBox(CString("�·��ɹ�"));
	}
	else
	{
		MessageBox(CString("�·�ʧ��"));
	}
}
