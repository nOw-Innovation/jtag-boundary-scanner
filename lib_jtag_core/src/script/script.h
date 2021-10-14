/*
 * JTAG Boundary Scanner
 * Copyright (c) 2008 - 2021 Viveris Technologies
 *
 * JTAG Boundary Scanner is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * JTAG Boundary Scanner is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 3 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with JTAG Boundary Scanners; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
* @file   script.h
* @brief  JTAG Boundary Scanner scripts support header file.
* @author Jean-François DEL NERO <Jean-Francois.DELNERO@viveris.fr>
*/

#define _script_ctx_

#ifndef _jtag_script_printf_func_
typedef int (* JTAG_SCRIPT_PRINTF_FUNC)(int MSGTYPE, char * string, ... );
#define _jtag_script_printf_func_
#endif

typedef struct _script_ctx
{
	JTAG_SCRIPT_PRINTF_FUNC script_printf;
	void * app_ctx;
} script_ctx;

script_ctx * init_script(jtag_core * jc);
int execute_file_script( script_ctx * ctx, char * filename );
int execute_line_script( script_ctx * ctx, char * line );
int execute_ram_script( script_ctx * ctx, unsigned char * script_buffer, int buffersize );
void setOutputFunc_script( script_ctx * ctx, JTAG_SCRIPT_PRINTF_FUNC ext_printf );
script_ctx * deinit_script(script_ctx * ctx);
