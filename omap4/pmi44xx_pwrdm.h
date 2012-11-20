/*
 *
 * @Component			OMAPCONF
 * @Filename			pmi44xx_pwrdm.h
 * @Description			OMAP4 PMI Power Domain Transition Trace
 *				Decoding library
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


#ifndef __PMI_PWRDM44XX_H__
#define __PMI_PWRDM44XX_H__


#include <prcm-pwrdm.h>
#include <coresight44xx.h>
#include <pmi44xx.h>


typedef enum {
	OMAP4_PMI_LOGIC_PWRDM_NA1 = 0,
	OMAP4_PMI_LOGIC_PWRDM_NA2 = 1,
	OMAP4_PMI_LOGIC_PWRDM_NA3 = 2,
	OMAP4_PMI_LOGIC_PWRDM_CEFUSE = 3,
	OMAP4_PMI_LOGIC_PWRDM_L4PER = 4,
	OMAP4_PMI_LOGIC_PWRDM_L3INT = 5,
	OMAP4_PMI_LOGIC_PWRDM_GFX = 6,
	OMAP4_PMI_LOGIC_PWRDM_DSS = 7,
	OMAP4_PMI_LOGIC_PWRDM_CAM = 8,
	OMAP4_PMI_LOGIC_PWRDM_IVAHD = 9,
	OMAP4_PMI_LOGIC_PWRDM_CORE = 10,
	OMAP4_PMI_LOGIC_PWRDM_ABE = 11,
	OMAP4_PMI_LOGIC_PWRDM_DSP = 12,
	OMAP4_PMI_LOGIC_PWRDM_A9_C1 = 13,
	OMAP4_PMI_LOGIC_PWRDM_A9_C0 = 14,
	OMAP4_PMI_LOGIC_PWRDM_MPU = 15,
	OMAP4_PMI_LOGIC_PWRDM_MAX = 16
} omap4_pmi_logic_pwrdm_id;

typedef enum {
	OMAP4_PMI_MEM_PWRDM_NA1 = 0,
	OMAP4_PMI_MEM_PWRDM_NA2 = 1,
	OMAP4_PMI_MEM_PWRDM_NA3 = 2,
	OMAP4_PMI_MEM_PWRDM_NA4 = 3,
	OMAP4_PMI_MEM_PWRDM_NA5 = 4,
	OMAP4_PMI_MEM_PWRDM_NA6 = 5,
	OMAP4_PMI_MEM_PWRDM_NA7 = 6,
	OMAP4_PMI_MEM_PWRDM_L4_PER2 = 7,
	OMAP4_PMI_MEM_PWRDM_L4_PER1 = 8,
	OMAP4_PMI_MEM_PWRDM_L3_INIT_BANK1 = 9,
	OMAP4_PMI_MEM_PWRDM_GFX = 10,
	OMAP4_PMI_MEM_PWRDM_DSS = 11,
	OMAP4_PMI_MEM_PWRDM_CAM = 12,
	OMAP4_PMI_MEM_PWRDM_IVAHD_TCM2 = 13,
	OMAP4_PMI_MEM_PWRDM_IVAHD_TCM1 = 14,
	OMAP4_PMI_MEM_PWRDM_IVAHD_SL2 = 15,
	OMAP4_PMI_MEM_PWRDM_IVAHD_HWA = 16,
	OMAP4_PMI_MEM_PWRDM_CORE_OTHER_BANKS = 17,
	OMAP4_PMI_MEM_PWRDM_MPU_M3_UNICACHE = 18,
	OMAP4_PMI_MEM_PWRDM_MPU_M3_L2_RAM = 19,
	OMAP4_PMI_MEM_PWRDM_OCM_RAM = 20,
	OMAP4_PMI_MEM_PWRDM_CORE_NON_RET = 21,
	OMAP4_PMI_MEM_PWRDM_AUDIO_PER = 22,
	OMAP4_PMI_MEM_PWRDM_AUDIO_ENGINE = 23,
	OMAP4_PMI_MEM_PWRDM_DSP_EDMA = 24,
	OMAP4_PMI_MEM_PWRDM_DSP_L2 = 25,
	OMAP4_PMI_MEM_PWRDM_DSP_L1 = 26,
	OMAP4_PMI_MEM_PWRDM_MPU_M1 = 27,
	OMAP4_PMI_MEM_PWRDM_MPU_M0 = 28,
	OMAP4_PMI_MEM_PWRDM_MPU_RAM = 29,
	OMAP4_PMI_MEM_PWRDM_MPU_L2 = 30,
	OMAP4_PMI_MEM_PWRDM_MPU_L1 = 31,
	OMAP4_PMI_MEM_PWRDM_MAX = 32
} omap4_pmi_mem_pwrdm_id;

#define OMAP4_PMI_PWRDM_MAX \
	(OMAP4_PMI_LOGIC_PWRDM_MAX + OMAP4_PMI_MEM_PWRDM_MAX)
#define OMAP4_PMI_PWRDM_NAME_MAX 21

static const char
	omap4_pmi_logic_pwrdm_names_table
		[OMAP4_PMI_LOGIC_PWRDM_MAX][OMAP4_PMI_PWRDM_NAME_MAX] = {
		"LOGIC_NA1",
		"LOGIC_NA2",
		"LOGIC_NA3",
		"LOGIC_CEFUSE",
		"LOGIC_L4PER",
		"LOGIC_L3INT",
		"LOGIC_GFX",
		"LOGIC_DSS",
		"LOGIC_CAM",
		"LOGIC_IVAHD",
		"LOGIC_CORE",
		"LOGIC_ABE",
		"LOGIC_DSP",
		"LOGIC_A9_C1",
		"LOGIC_A9_C0",
		"LOGIC_MPU"};

static const char
	omap4_pmi_mem_pwrdm_names_table
		[OMAP4_PMI_MEM_PWRDM_MAX][OMAP4_PMI_PWRDM_NAME_MAX] = {
		"MEM_NA1",
		"MEM_NA2",
		"MEM_NA3",
		"MEM_NA4",
		"MEM_NA5",
		"MEM_NA6",
		"MEM_NA7",
		"MEM_L4_PER2",
		"MEM_L4_PER1",
		"MEM_L3_INIT_BANK1",
		"MEM_GFX",
		"MEM_DSS",
		"MEM_CAM",
		"MEM_IVAHD_TCM2",
		"MEM_IVAHD_TCM1",
		"MEM_IVAHD_SL2",
		"MEM_IVAHD_HWA",
		"MEM_CORE_OTHER_BANKS",
		"MEM_MPU_M3_UNICACHE",
		"MEM_MPU_M3_L2_RAM",
		"MEM_OCM_RAM",
		"MEM_CORE_NON_RET",
		"MEM_AUDIO_PER",
		"MEM_AUDIO_ENGINE",
		"MEM_DSP_EDMA",
		"MEM_DSP_L2",
		"MEM_DSP_L1",
		"MEM_MPU_M1",
		"MEM_MPU_M0",
		"MEM_MPU_RAM",
		"MEM_MPU_L2",
		"MEM_MPU_L1"};


#define OMAP4_USED_PMI_PWRDMS	37

static const unsigned int sorted_domain_ids[OMAP4_USED_PMI_PWRDMS] = {
	OMAP4_PMI_LOGIC_PWRDM_L4PER,
	OMAP4_PMI_MEM_PWRDM_L4_PER2,
	OMAP4_PMI_MEM_PWRDM_L4_PER1,
	OMAP4_PMI_LOGIC_PWRDM_L3INT,
	OMAP4_PMI_MEM_PWRDM_L3_INIT_BANK1,
	OMAP4_PMI_LOGIC_PWRDM_GFX,
	OMAP4_PMI_MEM_PWRDM_GFX,
	OMAP4_PMI_LOGIC_PWRDM_DSS,
	OMAP4_PMI_MEM_PWRDM_DSS,
	OMAP4_PMI_LOGIC_PWRDM_CAM,
	OMAP4_PMI_MEM_PWRDM_CAM,
	OMAP4_PMI_LOGIC_PWRDM_IVAHD,
	OMAP4_PMI_MEM_PWRDM_IVAHD_TCM2,
	OMAP4_PMI_MEM_PWRDM_IVAHD_TCM1,
	OMAP4_PMI_MEM_PWRDM_IVAHD_SL2,
	OMAP4_PMI_MEM_PWRDM_IVAHD_HWA,
	OMAP4_PMI_LOGIC_PWRDM_CORE,
	OMAP4_PMI_MEM_PWRDM_CORE_OTHER_BANKS,
	OMAP4_PMI_MEM_PWRDM_MPU_M3_UNICACHE,
	OMAP4_PMI_MEM_PWRDM_MPU_M3_L2_RAM,
	OMAP4_PMI_MEM_PWRDM_OCM_RAM,
	OMAP4_PMI_MEM_PWRDM_CORE_NON_RET,
	OMAP4_PMI_LOGIC_PWRDM_ABE,
	OMAP4_PMI_MEM_PWRDM_AUDIO_PER,
	OMAP4_PMI_MEM_PWRDM_AUDIO_ENGINE,
	OMAP4_PMI_LOGIC_PWRDM_DSP,
	OMAP4_PMI_MEM_PWRDM_DSP_EDMA,
	OMAP4_PMI_MEM_PWRDM_DSP_L2,
	OMAP4_PMI_MEM_PWRDM_DSP_L1,
	OMAP4_PMI_LOGIC_PWRDM_A9_C1,
	OMAP4_PMI_MEM_PWRDM_MPU_M1,
	OMAP4_PMI_LOGIC_PWRDM_A9_C0,
	OMAP4_PMI_MEM_PWRDM_MPU_M0,
	OMAP4_PMI_LOGIC_PWRDM_MPU,
	OMAP4_PMI_MEM_PWRDM_MPU_RAM,
	OMAP4_PMI_MEM_PWRDM_MPU_L2,
	OMAP4_PMI_MEM_PWRDM_MPU_L1};


static const unsigned int sorted_domain_class[OMAP4_USED_PMI_PWRDMS] = {
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_LOGIC,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM,
	PMI_PWRDM_CLASS_MEM};


typedef struct {
	unsigned char id;
	pmi_event_class class;
	pwrdm_state state;
	double ts; /* relative timestamp, in micro-seconds */
} pwrdm_transition;


typedef genlist
	pwrdm_transitions[OMAP4_PMI_PWRDM_MAX];


int pmi_pwrdm_events_get(char *filename, genlist *pm_events);
int pmi_pwrdm_transitions_find(genlist *pm_events,
	double duration, pwrdm_transitions transitions);
int pmi_pwrdm_transitions_save(char *filename,
	pwrdm_transitions transitions, double duration);


#endif
