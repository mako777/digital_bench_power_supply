/*
    File:       DigitalOut.h
    Version:    0.1.0
    Date:       Feb. 21, 2013
	License:	GPL v2
    
	Header file defining Class to allow simple use of I/O pins
    
    ****************************************************************************
    Copyright (C) 2013 Radu Motisan  <radu.motisan@gmail.com>
	
	http://www.pocketmagic.net

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
    ****************************************************************************
 */


#pragma once

#include <avr/io.h>

class DigitalOut {	
	volatile uint8_t *m_pddr,
					 *m_pport;
	uint8_t m_ledstate, m_dq;
		
	volatile uint8_t* Port2DDR(volatile uint8_t *port) {
			return port - 1;
		}
	public:
	/************************************************************************/
	/* Set DDR for output and save globals                                  */
	/************************************************************************/
	void init( volatile uint8_t  *port, uint8_t  dq) ;
	/************************************************************************/
	/* Set turns led on (st=1) or off (st=0)                                */
	/************************************************************************/
	void set(uint8_t st);
	uint8_t get();
	/************************************************************************/
	/* Toggle led from current state to the opposite                        */
	/************************************************************************/
	void toggle();
};
