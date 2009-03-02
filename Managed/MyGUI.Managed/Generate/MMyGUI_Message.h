﻿/*!
	@file
	@author		Generate utility by Albert Semenov
	@date		01/2009
	@module
*/
#pragma once

#include "MMyGUI_Widget.h"
#include "MMyGUI_Window.h"

namespace MyGUI
{
	namespace Managed
	{

		public ref class MessageBox : public Window
		{

			//--------------------------------------------------------------------
			// объявление типов и конструкторов
			MMYGUI_DECLARE_DERIVED( MessageBox, Message, Window );

			

			//InsertPoint

   	public:
		delegate void HandleMessageBoxResult( Convert<MyGUI::Message *>::Type _sender, Convert<MyGUI::MessageBoxStyle>::Type _result );
		event HandleMessageBoxResult^ EventMessageBoxResult
		{
			void add(HandleMessageBoxResult^ _value)
			{
				mDelegateMessageBoxResult += _value;
				MMYGUI_CHECK_NATIVE(mNative);
				static_cast<ThisType*>(mNative)->eventMessageBoxResult =
					static_cast< MyGUI::delegates::IDelegate2< MyGUI::Message *, MyGUI::MessageBoxStyle > *>(
						new Delegate2< HandleMessageBoxResult^, MyGUI::Message *, MyGUI::MessageBoxStyle >(mDelegateMessageBoxResult) );
			}
			void remove(HandleMessageBoxResult^ _value)
			{
				mDelegateMessageBoxResult -= _value;
				MMYGUI_CHECK_NATIVE(mNative);
				if (mDelegateMessageBoxResult == nullptr)
					static_cast<ThisType*>(mNative)->eventMessageBoxResult = nullptr;
				else
					static_cast<ThisType*>(mNative)->eventMessageBoxResult =
						static_cast< MyGUI::delegates::IDelegate2< MyGUI::Message *, MyGUI::MessageBoxStyle > *>(
							new Delegate2< HandleMessageBoxResult^, MyGUI::Message *, MyGUI::MessageBoxStyle >(mDelegateMessageBoxResult) );
			}
		}
	private:
		HandleMessageBoxResult^ mDelegateMessageBoxResult;




   	public:
		void SetMessageStyle( Convert< MyGUI::MessageBoxStyle >::Type _style )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->setMessageStyle( Convert< MyGUI::MessageBoxStyle >::From(_style) );
		}



   	public:
		void SetMessageButton( Convert< MyGUI::MessageBoxStyle >::Type _button )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->setMessageButton( Convert< MyGUI::MessageBoxStyle >::From(_button) );
		}



   	public:
		void EndMessage( )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->endMessage( );
		}



   	public:
		void EndMessage( Convert< MyGUI::MessageBoxStyle >::Type _result )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->endMessage( Convert< MyGUI::MessageBoxStyle >::From(_result) );
		}



   	public:
		void SetWindowFade( Convert<bool>::Type _fade )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->setWindowFade( Convert<bool>::From(_fade) );
		}



   	public:
		void SetMessageIcon( Convert< MyGUI::MessageBoxStyle >::Type _icon )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->setMessageIcon( Convert< MyGUI::MessageBoxStyle >::From(_icon) );
		}



   	public:
		Convert<const std::string &>::Type GetDefaultLayer( )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			return Convert<const std::string &>::To( static_cast<ThisType*>(mNative)->getDefaultLayer( ) );
		}



   	public:
		void SetSmoothShow( Convert<bool>::Type _smooth )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->setSmoothShow( Convert<bool>::From(_smooth) );
		}



   	public:
		Convert< MyGUI::MessageBoxStyle >::Type AddButtonName( Convert<const Ogre::UTFString &>::Type _name )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			return Convert< MyGUI::MessageBoxStyle >::To( static_cast<ThisType*>(mNative)->addButtonName( Convert<const Ogre::UTFString &>::From(_name) ) );
		}



   	public:
		void SetMessageText( Convert<const Ogre::UTFString &>::Type _message )
		{
			MMYGUI_CHECK_NATIVE(mNative);
			static_cast<ThisType*>(mNative)->setMessageText( Convert<const Ogre::UTFString &>::From(_message) );
		}



		};

	} // namespace Managed
} // namespace MyGUI
