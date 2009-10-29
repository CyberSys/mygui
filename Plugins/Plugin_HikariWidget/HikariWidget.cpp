/*!
	@file
	@author		Albert Semenov
	@date		10/2009
	@module
*/
#include "HikariWidget.h"
#include "MyGUI_WidgetSkinInfo.h"

namespace Hikari
{

	HikariWidget::HikariWidget(MyGUI::WidgetStyle _style, const MyGUI::IntCoord& _coord, MyGUI::Align _align, const MyGUI::WidgetSkinInfoPtr _info, MyGUI::WidgetPtr _parent, MyGUI::ICroppedRectangle * _croppedParent, MyGUI::IWidgetCreator * _creator, const std::string& _name) :
		Base(_style, _coord, _align, _info, _parent, _croppedParent, _creator, _name),
		mControl(0)
	{
		initialiseWidgetSkin(_info);

		createTexture(TRM_PT_VIEW_REQUESTED);
		requestUpdateCanvas = newDelegate(this, &HikariWidget::notifyUpdateCanvas);

		mControl = new Hikari::FlashControl(this, factory::HikariWidgetFactory::getLibHandle());
		updateTexture();

		MyGUI::Gui::getInstance().eventFrameStart += MyGUI::newDelegate(this, &HikariWidget::notifyFrameStart);
	}

	HikariWidget::~HikariWidget()
	{
		MyGUI::Gui::getInstance().eventFrameStart -= MyGUI::newDelegate(this, &HikariWidget::notifyFrameStart);

		requestUpdateCanvas = nullptr;
		delete mControl;
		mControl = 0;

		shutdownWidgetSkin();
	}

	void HikariWidget::baseChangeWidgetSkin(MyGUI::WidgetSkinInfoPtr _info)
	{
		shutdownWidgetSkin();
		Base::baseChangeWidgetSkin(_info);
		initialiseWidgetSkin(_info);
	}

	void HikariWidget::initialiseWidgetSkin(MyGUI::WidgetSkinInfoPtr _info)
	{
	}

	void HikariWidget::shutdownWidgetSkin()
	{
	}

	void HikariWidget::notifyUpdateCanvas(MyGUI::CanvasPtr _canvas, MyGUI::Canvas::Event _event)
	{
		if (mControl)
		{
			bool resizeOnly = _event.widgetResized && !_event.requested && !_event.textureChanged;
			if (resizeOnly)
			{
				if (mControl->getWidth() != getWidth() || mControl->getHeight() != getHeight())
				{
					mControl->setSize(getWidth(), getHeight());
				}
			}
			else
			{
				if (mControl->getWidth() != getWidth() || mControl->getHeight() != getHeight())
				{
					mControl->setSize(getWidth(), getHeight());
				}
				else
				{
					mControl->invalidateTotally();
				}
			}

			mControl->update();
		}
	}

	void HikariWidget::notifyFrameStart(float _time)
	{
		if (mControl)
			mControl->update();
	}

	void HikariWidget::load(const Ogre::String& movieFilename)
	{
		mControl->load(movieFilename);
	}

	void HikariWidget::play()
	{
		mControl->play();
	}

	void HikariWidget::stop()
	{
		mControl->stop();
	}

	void HikariWidget::rewind()
	{
		mControl->rewind();
	}

	void HikariWidget::gotoFrame(long frameNum)
	{
		mControl->gotoFrame(frameNum);
	}	

	void HikariWidget::setLoop(bool shouldLoop)
	{
		mControl->setLoop(shouldLoop);
	}

	void HikariWidget::setTransparent(bool isTransparent)
	{
		mControl->setTransparent(isTransparent);
	}

	void HikariWidget::setQuality(short renderQuality)
	{
		mControl->setQuality(renderQuality);
	}

	void HikariWidget::setScaleMode(short scaleMode)
	{
		mControl->setScaleMode(scaleMode);
	}

	void HikariWidget::bind(const Ogre::UTFString& funcName, FlashDelegate::IDelegate* callback)
	{
		mControl->bind(funcName, callback);
	}

	void HikariWidget::unbind(const Ogre::UTFString& funcName)
	{
		mControl->unbind(funcName);
	}

	FlashValue HikariWidget::callFunction(Ogre::UTFString funcName, const Arguments& args)
	{
		return mControl->callFunction(funcName, args);
	}

	void HikariWidget::onMouseDrag(int _left, int _top)
	{
		mControl->injectMouseMove(_left - getAbsoluteLeft(), _top - getAbsoluteTop());
		Base::onMouseDrag(_left, _top);
	}

	void HikariWidget::onMouseMove(int _left, int _top)
	{
		mControl->injectMouseMove(_left - getAbsoluteLeft(), _top - getAbsoluteTop());
		Base::onMouseDrag(_left, _top);
	}

	void HikariWidget::onMouseWheel(int _rel)
	{
		const MyGUI::IntPoint& point = MyGUI::InputManager::getInstance().getMousePosition();
		mControl->injectMouseWheel(_rel, point.left - getAbsoluteLeft(), point.top - getAbsoluteTop());
		Base::onMouseWheel(_rel);
	}

	void HikariWidget::onMouseButtonPressed(int _left, int _top, MyGUI::MouseButton _id)
	{
		if (_id == MyGUI::MouseButton::Left)
			mControl->injectMouseDown(_left - getAbsoluteLeft(), _top - getAbsoluteTop());
		Base::onMouseButtonPressed(_left, _top, _id);
	}

	void HikariWidget::onMouseButtonReleased(int _left, int _top, MyGUI::MouseButton _id)
	{
		if (_id == MyGUI::MouseButton::Left)
			mControl->injectMouseUp(_left - getAbsoluteLeft(), _top - getAbsoluteTop());
		Base::onMouseButtonReleased(_left, _top, _id);
	}

} // namespace Hikari
