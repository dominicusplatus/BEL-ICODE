#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/spi.c mcc_generated_files/tmr1.c mcc_generated_files/tmr0.c mcc_generated_files/pin_manager.c mcc_generated_files/mcc.c mcc_generated_files/interrupt_manager.c main.c ../NXP/comps/phalI15693/src/phalI15693.c ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c ../NXP/comps/phalSli/src/phalSli.c ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c ../NXP/comps/phbalReg/src/phbalReg.c ../NXP/comps/phhalHw/src/phhalHw.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c ../NXP/comps/phpalSli15693/src/phpalSli15693.c ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c ../NXP/comps/phTools/src/phTools.c ../NXP/src/icode_common.c ../NXP/src/icode_ilt_commands.c ../NXP/src/icode_ilt_ui.c ../NXP/src/icode_sli_commands.c ../NXP/src/icode_sli_ui.c ../NXP/src/main.c ../NXP/phhwConfig.c ../NXP/Stub/phbalReg_Stub.c ../NXP/Stub/phOsal_Lpc17xx_Int.c ../NXP/Stub/phPlatform.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/spi.p1 ${OBJECTDIR}/mcc_generated_files/tmr1.p1 ${OBJECTDIR}/mcc_generated_files/tmr0.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/_ext/1543058690/phalI15693.p1 ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1 ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1 ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1 ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1 ${OBJECTDIR}/_ext/192958335/phalSli.p1 ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1 ${OBJECTDIR}/_ext/1147107305/phbalReg.p1 ${OBJECTDIR}/_ext/1870330116/phhalHw.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1 ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1 ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1 ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1 ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1 ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1 ${OBJECTDIR}/_ext/2056939211/phTools.p1 ${OBJECTDIR}/_ext/1420065484/icode_common.p1 ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1 ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1 ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1 ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1 ${OBJECTDIR}/_ext/1420065484/main.p1 ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1 ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1 ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1 ${OBJECTDIR}/_ext/1071406310/phPlatform.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/spi.p1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/_ext/1543058690/phalI15693.p1.d ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1.d ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1.d ${OBJECTDIR}/_ext/192958335/phalSli.p1.d ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1.d ${OBJECTDIR}/_ext/1147107305/phbalReg.p1.d ${OBJECTDIR}/_ext/1870330116/phhalHw.p1.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1.d ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1.d ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1.d ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1.d ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1.d ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1.d ${OBJECTDIR}/_ext/2056939211/phTools.p1.d ${OBJECTDIR}/_ext/1420065484/icode_common.p1.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1.d ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1.d ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1.d ${OBJECTDIR}/_ext/1420065484/main.p1.d ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1.d ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1.d ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1.d ${OBJECTDIR}/_ext/1071406310/phPlatform.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/spi.p1 ${OBJECTDIR}/mcc_generated_files/tmr1.p1 ${OBJECTDIR}/mcc_generated_files/tmr0.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/_ext/1543058690/phalI15693.p1 ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1 ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1 ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1 ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1 ${OBJECTDIR}/_ext/192958335/phalSli.p1 ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1 ${OBJECTDIR}/_ext/1147107305/phbalReg.p1 ${OBJECTDIR}/_ext/1870330116/phhalHw.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1 ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1 ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1 ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1 ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1 ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1 ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1 ${OBJECTDIR}/_ext/2056939211/phTools.p1 ${OBJECTDIR}/_ext/1420065484/icode_common.p1 ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1 ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1 ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1 ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1 ${OBJECTDIR}/_ext/1420065484/main.p1 ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1 ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1 ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1 ${OBJECTDIR}/_ext/1071406310/phPlatform.p1

# Source Files
SOURCEFILES=mcc_generated_files/spi.c mcc_generated_files/tmr1.c mcc_generated_files/tmr0.c mcc_generated_files/pin_manager.c mcc_generated_files/mcc.c mcc_generated_files/interrupt_manager.c main.c ../NXP/comps/phalI15693/src/phalI15693.c ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c ../NXP/comps/phalSli/src/phalSli.c ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c ../NXP/comps/phbalReg/src/phbalReg.c ../NXP/comps/phhalHw/src/phhalHw.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c ../NXP/comps/phpalSli15693/src/phpalSli15693.c ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c ../NXP/comps/phTools/src/phTools.c ../NXP/src/icode_common.c ../NXP/src/icode_ilt_commands.c ../NXP/src/icode_ilt_ui.c ../NXP/src/icode_sli_commands.c ../NXP/src/icode_sli_ui.c ../NXP/src/main.c ../NXP/phhwConfig.c ../NXP/Stub/phbalReg_Stub.c ../NXP/Stub/phOsal_Lpc17xx_Int.c ../NXP/Stub/phPlatform.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18LF46K80
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/spi.p1: mcc_generated_files/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/spi.p1  mcc_generated_files/spi.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/spi.d ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr1.p1: mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/tmr1.p1  mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr0.p1: mcc_generated_files/tmr0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/tmr0.p1  mcc_generated_files/tmr0.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr0.d ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/pin_manager.p1  mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/mcc.p1  mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1: mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1  mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1543058690/phalI15693.p1: ../NXP/comps/phalI15693/src/phalI15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1543058690" 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1543058690/phalI15693.p1  ../NXP/comps/phalI15693/src/phalI15693.c 
	@-${MV} ${OBJECTDIR}/_ext/1543058690/phalI15693.d ${OBJECTDIR}/_ext/1543058690/phalI15693.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1543058690/phalI15693.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1: ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/226416843" 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1  ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.d ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1: ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1083465500" 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1  ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c 
	@-${MV} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.d ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1  ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1  ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c 
	@-${MV} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/192958335/phalSli.p1: ../NXP/comps/phalSli/src/phalSli.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/192958335" 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.p1.d 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/192958335/phalSli.p1  ../NXP/comps/phalSli/src/phalSli.c 
	@-${MV} ${OBJECTDIR}/_ext/192958335/phalSli.d ${OBJECTDIR}/_ext/192958335/phalSli.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/192958335/phalSli.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1: ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755563796" 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1  ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.d ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1147107305/phbalReg.p1: ../NXP/comps/phbalReg/src/phbalReg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1147107305" 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1147107305/phbalReg.p1  ../NXP/comps/phbalReg/src/phbalReg.c 
	@-${MV} ${OBJECTDIR}/_ext/1147107305/phbalReg.d ${OBJECTDIR}/_ext/1147107305/phbalReg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1147107305/phbalReg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1870330116/phhalHw.p1: ../NXP/comps/phhalHw/src/phhalHw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1870330116" 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1870330116/phhalHw.p1  ../NXP/comps/phhalHw/src/phhalHw.c 
	@-${MV} ${OBJECTDIR}/_ext/1870330116/phhalHw.d ${OBJECTDIR}/_ext/1870330116/phhalHw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1870330116/phhalHw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1: ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/424603049" 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1.d 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1  ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c 
	@-${MV} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.d ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1: ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2062512958" 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1  ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c 
	@-${MV} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.d ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1: ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/521443061" 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1  ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.d ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/75335025/phpalSli15693.p1: ../NXP/comps/phpalSli15693/src/phpalSli15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/75335025" 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1.d 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/75335025/phpalSli15693.p1  ../NXP/comps/phpalSli15693/src/phpalSli15693.c 
	@-${MV} ${OBJECTDIR}/_ext/75335025/phpalSli15693.d ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1: ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1962118174" 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1  ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.d ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2056939211/phTools.p1: ../NXP/comps/phTools/src/phTools.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2056939211" 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2056939211/phTools.p1  ../NXP/comps/phTools/src/phTools.c 
	@-${MV} ${OBJECTDIR}/_ext/2056939211/phTools.d ${OBJECTDIR}/_ext/2056939211/phTools.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2056939211/phTools.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_common.p1: ../NXP/src/icode_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_common.p1  ../NXP/src/icode_common.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_common.d ${OBJECTDIR}/_ext/1420065484/icode_common.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_common.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1: ../NXP/src/icode_ilt_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1  ../NXP/src/icode_ilt_commands.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1: ../NXP/src/icode_ilt_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1  ../NXP/src/icode_ilt_ui.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1: ../NXP/src/icode_sli_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1  ../NXP/src/icode_sli_commands.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.d ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1: ../NXP/src/icode_sli_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1  ../NXP/src/icode_sli_ui.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.d ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/main.p1: ../NXP/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/main.p1  ../NXP/src/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/main.d ${OBJECTDIR}/_ext/1420065484/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360900855/phhwConfig.p1: ../NXP/phhwConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360900855" 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360900855/phhwConfig.p1  ../NXP/phhwConfig.c 
	@-${MV} ${OBJECTDIR}/_ext/1360900855/phhwConfig.d ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1: ../NXP/Stub/phbalReg_Stub.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1  ../NXP/Stub/phbalReg_Stub.c 
	@-${MV} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.d ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1: ../NXP/Stub/phOsal_Lpc17xx_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1  ../NXP/Stub/phOsal_Lpc17xx_Int.c 
	@-${MV} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.d ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1071406310/phPlatform.p1: ../NXP/Stub/phPlatform.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1071406310/phPlatform.p1  ../NXP/Stub/phPlatform.c 
	@-${MV} ${OBJECTDIR}/_ext/1071406310/phPlatform.d ${OBJECTDIR}/_ext/1071406310/phPlatform.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1071406310/phPlatform.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/mcc_generated_files/spi.p1: mcc_generated_files/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/spi.p1  mcc_generated_files/spi.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/spi.d ${OBJECTDIR}/mcc_generated_files/spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr1.p1: mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/tmr1.p1  mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr0.p1: mcc_generated_files/tmr0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/tmr0.p1  mcc_generated_files/tmr0.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr0.d ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/pin_manager.p1  mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/mcc.p1  mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1: mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1  mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1543058690/phalI15693.p1: ../NXP/comps/phalI15693/src/phalI15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1543058690" 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1543058690/phalI15693.p1  ../NXP/comps/phalI15693/src/phalI15693.c 
	@-${MV} ${OBJECTDIR}/_ext/1543058690/phalI15693.d ${OBJECTDIR}/_ext/1543058690/phalI15693.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1543058690/phalI15693.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1: ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/226416843" 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1  ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.d ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1: ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1083465500" 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1  ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c 
	@-${MV} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.d ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1  ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1  ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c 
	@-${MV} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/192958335/phalSli.p1: ../NXP/comps/phalSli/src/phalSli.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/192958335" 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.p1.d 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/192958335/phalSli.p1  ../NXP/comps/phalSli/src/phalSli.c 
	@-${MV} ${OBJECTDIR}/_ext/192958335/phalSli.d ${OBJECTDIR}/_ext/192958335/phalSli.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/192958335/phalSli.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1: ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755563796" 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1  ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.d ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1147107305/phbalReg.p1: ../NXP/comps/phbalReg/src/phbalReg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1147107305" 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1147107305/phbalReg.p1  ../NXP/comps/phbalReg/src/phbalReg.c 
	@-${MV} ${OBJECTDIR}/_ext/1147107305/phbalReg.d ${OBJECTDIR}/_ext/1147107305/phbalReg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1147107305/phbalReg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1870330116/phhalHw.p1: ../NXP/comps/phhalHw/src/phhalHw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1870330116" 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1870330116/phhalHw.p1  ../NXP/comps/phhalHw/src/phhalHw.c 
	@-${MV} ${OBJECTDIR}/_ext/1870330116/phhalHw.d ${OBJECTDIR}/_ext/1870330116/phhalHw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1870330116/phhalHw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1  ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c 
	@-${MV} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1: ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/424603049" 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1.d 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1  ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c 
	@-${MV} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.d ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1: ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2062512958" 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1  ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c 
	@-${MV} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.d ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1: ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/521443061" 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1  ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.d ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/75335025/phpalSli15693.p1: ../NXP/comps/phpalSli15693/src/phpalSli15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/75335025" 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1.d 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/75335025/phpalSli15693.p1  ../NXP/comps/phpalSli15693/src/phpalSli15693.c 
	@-${MV} ${OBJECTDIR}/_ext/75335025/phpalSli15693.d ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/75335025/phpalSli15693.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1: ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1962118174" 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1  ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c 
	@-${MV} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.d ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2056939211/phTools.p1: ../NXP/comps/phTools/src/phTools.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2056939211" 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2056939211/phTools.p1  ../NXP/comps/phTools/src/phTools.c 
	@-${MV} ${OBJECTDIR}/_ext/2056939211/phTools.d ${OBJECTDIR}/_ext/2056939211/phTools.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2056939211/phTools.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_common.p1: ../NXP/src/icode_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_common.p1  ../NXP/src/icode_common.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_common.d ${OBJECTDIR}/_ext/1420065484/icode_common.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_common.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1: ../NXP/src/icode_ilt_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1  ../NXP/src/icode_ilt_commands.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1: ../NXP/src/icode_ilt_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1  ../NXP/src/icode_ilt_ui.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1: ../NXP/src/icode_sli_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1  ../NXP/src/icode_sli_commands.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.d ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1: ../NXP/src/icode_sli_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1  ../NXP/src/icode_sli_ui.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.d ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1420065484/main.p1: ../NXP/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1420065484/main.p1  ../NXP/src/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1420065484/main.d ${OBJECTDIR}/_ext/1420065484/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1420065484/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360900855/phhwConfig.p1: ../NXP/phhwConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360900855" 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360900855/phhwConfig.p1  ../NXP/phhwConfig.c 
	@-${MV} ${OBJECTDIR}/_ext/1360900855/phhwConfig.d ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360900855/phhwConfig.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1: ../NXP/Stub/phbalReg_Stub.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1  ../NXP/Stub/phbalReg_Stub.c 
	@-${MV} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.d ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1: ../NXP/Stub/phOsal_Lpc17xx_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1  ../NXP/Stub/phOsal_Lpc17xx_Int.c 
	@-${MV} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.d ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1071406310/phPlatform.p1: ../NXP/Stub/phPlatform.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1071406310/phPlatform.p1  ../NXP/Stub/phPlatform.c 
	@-${MV} ${OBJECTDIR}/_ext/1071406310/phPlatform.d ${OBJECTDIR}/_ext/1071406310/phPlatform.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1071406310/phPlatform.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"        $(COMPARISON_BUILD)  -odist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 -I"../NXP" -I"../NXP/intfs" -I"../NXP/types" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/Stub" -I"../NXP/comps/phbalReg/src/Stub" --warn=-3 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD)  -odist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
