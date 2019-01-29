// SamplePlugin.hpp

#ifndef FBXIMPORTERPLUGIN_HPP
#define FBXIMPORTERPLUGIN_HPP

#include "PX2Plugin.hpp"
#include "SamplePre.hpp"

#include "PX2UI.hpp"
#include "PX2UITabFrame.hpp"
#include "PX2UIFPicBox.hpp"
#include "PX2UIColorSelect.hpp"
#include "PX2UIList.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIButton.hpp"
#include "PX2StringHelp.hpp"
#include "PX2Controller.hpp"
#include "PX2Animation.hpp"
#include "PX2AnimationFrames.hpp"
#include "PX2ModelController.hpp"
#include "PX2SizeNode.hpp"
#include "PX2InterpCurveUniformScaleCtrl.hpp"
#include "PX2VoiceSDK.hpp"
#include "PX2ScriptContext.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2Bluetooth.hpp"
#include "PX2RenderWindow.hpp"
#include "PX2Application.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2
{
	class SAMPLE_DLL_ITEM SamplePlugin : public Plugin, public EventHandler, public Singleton<SamplePlugin>
	{
	public:
		SamplePlugin();
		virtual ~SamplePlugin();
		virtual void OnInstall();
		virtual void OnUninstall();
		virtual void OnUpdate();

		// �������
		void PrintMsg(const std::string &str);
		// �Ƿ��ڽ�����ʾ
		virtual void Show();
		// ����ABCD��ʾ
		virtual void ShowABCD();
		// �������򡱵���ʾ
		virtual void ShowProject();
		// �������򡱵Ĵ���
		virtual void OnCreateProject();

	protected:
		// �����˶�
		virtual void _Play();
		
		// �¼���Ӧ
		virtual void OnEvent(Event *event);

		// �������
		void AddMusic();
		
		// ����ť����
		void MainButton();

		// ��Ӳ˵�������
		void AddMenuBoxProperties();

		// ��ӿ������
		void AddFrameType();

		// �����ڡ���
		void OnCreateUIFrameAbout();

		// ����ܡ���
		void OnCreateUIFrame();

		// ��ͼƬ����
		void OnCreateUIFPicBox();

		// �����֡���
		void OnCreateUIFText();

		// ����ť����
		void OnCreateUIButton();

		// ���жϡ���
		void OnCreateUICheckBox();

		// ��ѡ�񡱿�
		void OnCreateUIComboBox();


		virtual void Progressmove();
		
		//�Ƿ񴴽�����Ŀ
		bool mIsNewProject;

	private:
		static Plugin *sPlugin;

		UI* mUI;
		//��ť
		UIButton* mButBag;
		//����
		UIFrame* frame;
		UIFrame* MenuBg;
		//�˵���
		UITabFrame* mMenuCase;
		//���ڿ�
		UIFrame* mFrameAbout;
		UIFText* mAboutfText;
		//��ܿ�
		UIFrame* frameUIFrame;
		//ͼƬ��
		UIFrame* frameUIFPicBox;
		//���ֿ�
		UIFrame* frameUIFText;
		//��ť��
		UIFrame* frameUIButtom;
		//�жϿ�
		UIFrame* frameUICheckBox;
		//ѡ���
		UIFrame* frameUIComboBox;
		//�༭��
		UIFrame* frameUIEditBox;
		//������
		UIFrame* frameUIProgress;
		//��ɫѡ��
		UIFrame* frameUIColorSelect;
		//�б�
		UIFrame* frameUIList;
		//��
		UIFrame* frameUITree;
		//�ָ���
		UIFrame* frameUISplitter;
		//������
		UIFrame* frameUISlider;
		//������
		UIFrame* frameUIRound;
		//������
		UIFrame* frameServer;
		//���һ��������������
		UIList* MsgList;
		//��ťA
		UIButton* ButtonA;
		//��ťB
		UIButton* ButtonB;
		//��ťC
		UIButton* ButtonC;
		//��ťD
		UIButton* ButtonD;
		//�򿪰�ť
		UIFrame* ProjectBg;
		UIButton* ButtonMenu;
		//���ܻ����˱���
		UIFrame* background;
		//��Բ
		UIFrame* circleOut;
		//��Բ
		UIFrame* circleIn;
		//Բ����
		UIButton* uiBtn;
		//Բ���ĵ�̫����ͼ
		UIFrame* yiBackground;
		//�ı�
		UIFText* text;
		//��Բ����
		InterpCurveUniformScaleController* ctrlOut;
		InterpCurveUniformScaleController* circleOutCtrl;
		//��Բ����
		InterpCurveUniformScaleController* ctrlIn;
		InterpCurveUniformScaleController* circleInCtrl;
		//Բ������
		InterpCurveUniformScaleController* ctrlBtn;
		InterpCurveUniformScaleController* circleBtnCtrl;
		//������1
		UIProgressBar* progressBar1;
		float ch_MT;
		float ch_LT;
		float ch_LastDelay;
	};
}
#endif