/*
 *
 * @Component			OMAPCONF
 * @Filename			pwrdm54xx.h
 * @Description			OMAP5 Power Domain Definitions & APIs
 * @Author			Patrick Titiano (p-titiano@ti.com)
 * @Date			2011
 * @Copyright			Texas Instruments Incorporated
 *
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef __PWRDM54XX_H__
#define __PWRDM54XX_H__


#include <prcm-pwrdm.h>
#include <voltdm54xx.h>


#define PWRDM54XX_MAX_NAME_LENGTH		16


typedef enum {
	PWRDM54XX_EMU,
	PWRDM54XX_WKUPAON,
	PWRDM54XX_COREAON,
	PWRDM54XX_CAM,
	PWRDM54XX_CORE,
	PWRDM54XX_DSS,
	PWRDM54XX_CUST_EFUSE,
	PWRDM54XX_L3_INIT,
	PWRDM54XX_L4_PER,
	PWRDM54XX_ABE,
	PWRDM54XX_DSP,
	PWRDM54XX_GPU,
	PWRDM54XX_MMAON,
	PWRDM54XX_IVA,
	PWRDM54XX_MPUAON,
	PWRDM54XX_MPU,
	PWRDM54XX_ID_MAX
} pwrdm54xx_id;


const char *pwrdm54xx_name_get(pwrdm54xx_id id);
voltdm54xx_id pwrdm54xx_voltdm_get(pwrdm54xx_id id);
unsigned int pwrdm54xx_properties_get(pwrdm54xx_id id);
unsigned int pwrdm54xx_has_pwrstctrl_reg(pwrdm54xx_id id);
reg *pwrdm54xx_pwrstctrl_reg_get(pwrdm54xx_id id);
unsigned int pwrdm54xx_has_pwrstst_reg(pwrdm54xx_id id);
reg *pwrdm54xx_pwrstst_reg_get(pwrdm54xx_id id);
unsigned int pwrdm54xx_has_last_power_state(pwrdm54xx_id id);
unsigned int pwrdm54xx_has_logic_ret_state_ctrl_bit(pwrdm54xx_id id);
pwrdm_state pwrdm54xx_target_logic_ret_state_get(pwrdm54xx_id id);
pwrdm_state pwrdm54xx_logic_state_get(pwrdm54xx_id id);
pwrdm_state pwrdm54xx_state_get(pwrdm54xx_id id, pwrdm_state_type type);
unsigned int pwrdm54xx_in_transition(pwrdm54xx_id id);

int pwrdm54xx_config_show(FILE *stream, pwrdm54xx_id id);


#endif
