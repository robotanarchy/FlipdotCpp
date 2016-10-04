#pragma once

#include <stdint.h>

#include "IFlipdotGfx.h"

class FlipdotGfx : public IFlipdotGfx
{
	public:
		FlipdotGfx(IFlipdotFramebuffer &framebuffer);
		~FlipdotGfx() override;

		void update(unsigned ticks) override;

		void clear() override;
		void setPixel(unsigned x, unsigned y, bool value) override;
		bool getPixel(unsigned x, unsigned y) override;
		void drawRect(unsigned x, unsigned y, unsigned dx, unsigned dy, bool value) override;
		void drawChar(unsigned x, unsigned y, char ch, bool invert) override;

		unsigned getScreenWidth() override;
		unsigned getScreenHeight() override;

	private:
		IFlipdotFramebuffer &_fb;
		uint16_t getCharData(char ch);

};