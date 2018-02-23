/*
  Copyright (c) 2017 huaweiwx
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
  
*/

#include <SpiFlash.h>
#include "FlashBlock.h"
#include "SpiFlashBlock.h"

extern SPIFLASH SpiFlash;
#define SPI_SECTOR_SIZE 4096

bool SpiEmbeddedFlashBlock::Init() {
	SpiFlash.begin();
    return true;
}

bool SpiEmbeddedFlashBlock::erase(uint32_t offset, uint32_t size) {
	uint32_t secadr = (baseAddress+ offset + SPI_SECTOR_SIZE - 1) / SPI_SECTOR_SIZE;
	uint16_t pages = (size+SPI_SECTOR_SIZE - 1) / SPI_SECTOR_SIZE;
	for(uint16_t i=0;i<pages;i++,secadr++){
		SpiFlash.eraseSector(secadr);
	};
    return true;
}

bool SpiEmbeddedFlashBlock::write(uint32_t offset, uint32_t size, uint8_t *data) {
//    PRINT_DEBUG("Writing to flash at %u size %u", offset, size);
	SpiFlash.write(data,(baseAddress+offset),(uint16_t)size);
    return true;
}

bool SpiEmbeddedFlashBlock::read(uint32_t offset, uint32_t size, uint8_t *data) {
//    PRINT_TRACE("Reading from flash at %u size %u", offset, size);
	SpiFlash.read(data,(baseAddress+offset),(uint16_t)size);
    return true;
}



