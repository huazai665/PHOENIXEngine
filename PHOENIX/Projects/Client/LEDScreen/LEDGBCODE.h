// LEDGBCODE.h: interface for the LEDGBCODE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEDGBCODE_H__BFC05BE8_A5FA_4ED9_B0D2_B7AEDC9A3591__INCLUDED_)
#define AFX_LEDGBCODE_H__BFC05BE8_A5FA_4ED9_B0D2_B7AEDC9A3591__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//���庯��ָ������(TCP��ʽ)
typedef BOOL(__stdcall *openserver)(int port);
typedef BOOL(__stdcall *closeserver)();
typedef BOOL(__stdcall *ledshowtcp_nb)
(int mateuid, int movestyle, int movespeed, int stoptim,bool brownsave,int pixelcolor, 
 int fontcolor, int fontbody,int fontsize, CString str, int areaW, int areaH, CString ip);
//���庯��ָ������(UCP��ʽ)
typedef BOOL(__stdcall *ledshowudp_nb)
(int mateuid, int movestyle, int movespeed, int stoptim,bool brownsave,int pixelcolor, 
 int fontcolor, int fontbody,int fontsize, CString str, int areaW, int areaH, CString ip);
//���庯��ָ������(COM��ʽ)
typedef BOOL(__stdcall *ledshowcom_nb)
(int mateuid, int movestyle, int movespeed, int stoptim, bool brownsave, int pixelcolor, 
 int fontcolor, int fontbody, int fontsize, CString str, int areaw, int areah, int port, 
 int baud, int rstype, CString rsadr, int updStyle, int timOut, bool endTag);

class filedll
{
public:	
	HINSTANCE Ddll;					//QYLED.Dll�ļ����
	filedll();
	filedll(CString dllname);		//���캯��
	~filedll();						//��������	
};

class material
{
public:
	UINT mateuid;		//�ز�UID
	UINT areaW;			//������
	UINT areaH;			//����߶�
	UINT pixelcolor;	//������ɫ
	BOOL brownsave;		//���籣��
	
	UINT fontbody;		//��ʾ����
	UINT fontsize;		//��ʾ�ֺ�
	UINT movestyle;		//��ʾ��ʽ
	UINT movespeed;		//�ƶ��ٶ�	
	UINT fontcolor;		//��ʾ��ɫ
	UINT stoptim;		//ͣ��ʱ��
	CString str;		//��ʾ��Ϣ
	BOOL endTag;		//�������
};

class CLEDGBCODEtcp:public material  
{
public:
	CString ip;					 		   //Ŀ��IP
	UINT localport;				 		   //���ض˿�

	openserver Topenserver;		 		   //����ָ�����(TCPͨѶ)
	closeserver Tcloseserver;	 		   //����ָ�����
	ledshowtcp_nb Tledshowtcp_nb;		   //����ָ�����

	BOOL openserverC(const HINSTANCE Ddll); //��������
	BOOL closeserverC(const HINSTANCE Ddll);//�رշ���
	BOOL senddt(const HINSTANCE Ddll);		//�·�����
};

class CLEDGBCODEudp:public material
{
public:
	CString ip;					   		    //Ŀ��IP
	ledshowudp_nb Tledshowudp_nb;  		    //����ָ�����

	BOOL senddt(const HINSTANCE Ddll);	    //�·�����
};

class CLEDGBCODEcom:public material
{
public:
	UINT rstype;				 //COMͨѶ����(RS232/RS485)
	UINT port;					 //�˿ں�
	UINT baud;					 //������
	CString adr;				 //��ַ(��ͨѶ����ΪRS485����Ч����ͨѶΪRS232����Ч)
	ledshowcom_nb Tledshowcom_nb;//����ָ�����

	BOOL senddt(const HINSTANCE Ddll);//�·�����
};

#endif // !defined(AFX_LEDGBCODE_H__BFC05BE8_A5FA_4ED9_B0D2_B7AEDC9A3591__INCLUDED_)
