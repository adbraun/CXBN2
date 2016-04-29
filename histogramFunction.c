//3-D array to store histogram for event energy on each pixel on each payload
unsigned int PayloadHisto[2][256][32];

void histogram(event) {
		
	// payload info on last byte
	// 0x00 for payload A, 0x01 for payload B
	unsigned char whichPayload = event & 0xFF;
	
	//determine which pixel
	//first byte in the event
	unsigned char pixel = (event << (8*5)) & 0xFF ;
	
	//determine event energy: byte 2-5
	unsigned long eventEnergy = ((event << (8*1)) & 0xFFFFFFFF);
	
	//scale energy to useful range of 0-31
	
	
	unsigned int x = 0;
	unsigned int n = 0;
	unsigned int i = 0;

	//loop through payloads
	for (x = 0; x < 2; x++){
		if (whichPayload == x){

			//loop through pixels
			for(n = 0; n < 256; n++){
				if (pixel = n){

					//loop through bins
					for (i = 0; i < 32; i++ ){

						//if the energy level is in the range of this bin and the bin is not maxed out, increment bin
						if (eventEnergy >= i && eventEnergy < 2*i &&  PayloadHisto[x][n][i] < 65536) {
							PayloadHisto[x][n][i] ++;
						}
					}
				}
			}
		}
	}	
	


}



