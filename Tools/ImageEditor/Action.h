/*!
	@file
	@author		Albert Semenov
	@date		07/2012
*/

#ifndef _f5f8572b_08fb_4884_9643_d6b76ba91a57_
#define _f5f8572b_08fb_4884_9643_d6b76ba91a57_

#include "IFactoryItem.h"

namespace tools
{

	class Action :
		public components::IFactoryItem
	{
	public:
		Action();
		virtual ~Action();

		virtual void doAction();
		virtual void undoAction();
		virtual bool doMerge();

		void setMerge(bool _value);
		bool getMerge() const;

	private:
		bool mMerge;
	};

}

#endif