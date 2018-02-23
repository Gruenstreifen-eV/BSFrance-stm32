/*
  ili9325.cpp add
*/

UTFT_ILI9325::UTFT_ILI9325()
             :UTFT(ILI9325D_16,239,319,16)
{
	
};


void UTFT_ILI9325::Init(byte orientation){
#include "tft_drivers/common/head1.h"
	switch(display_model)
	{

#include "tft_drivers/ili9325d/default/initlcd.h"
    }

#include "tft_drivers/common/head2.h"
}
