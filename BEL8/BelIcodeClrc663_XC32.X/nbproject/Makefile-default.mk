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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c ../NXP/comps/phalI15693/src/phalI15693.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c ../NXP/comps/phalSli/src/phalSli.c ../NXP/comps/phbalReg/src/phbalReg.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c ../NXP/comps/phhalHw/src/phhalHw.c ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c ../NXP/comps/phpalSli15693/src/phpalSli15693.c ../NXP/comps/phTools/src/phTools.c ../NXP/src/icode_common.c ../NXP/src/icode_ilt_commands.c ../NXP/src/icode_ilt_ui.c ../NXP/src/icode_sli_commands.c ../NXP/src/icode_sli_ui.c ../NXP/src/main.c ../NXP/Stub/phbalReg_Stub.c ../NXP/Stub/phOsal_Lpc17xx_Int.c ../NXP/Stub/phPlatform.c ../NXP/phhwConfig.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o ${OBJECTDIR}/_ext/1543058690/phalI15693.o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o ${OBJECTDIR}/_ext/192958335/phalSli.o ${OBJECTDIR}/_ext/1147107305/phbalReg.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o ${OBJECTDIR}/_ext/1870330116/phhalHw.o ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o ${OBJECTDIR}/_ext/75335025/phpalSli15693.o ${OBJECTDIR}/_ext/2056939211/phTools.o ${OBJECTDIR}/_ext/1420065484/icode_common.o ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o ${OBJECTDIR}/_ext/1420065484/main.o ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o ${OBJECTDIR}/_ext/1071406310/phPlatform.o ${OBJECTDIR}/_ext/1360900855/phhwConfig.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o.d ${OBJECTDIR}/_ext/1543058690/phalI15693.o.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o.d ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o.d ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o.d ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o.d ${OBJECTDIR}/_ext/192958335/phalSli.o.d ${OBJECTDIR}/_ext/1147107305/phbalReg.o.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o.d ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o.d ${OBJECTDIR}/_ext/1870330116/phhalHw.o.d ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o.d ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o.d ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o.d ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o.d ${OBJECTDIR}/_ext/75335025/phpalSli15693.o.d ${OBJECTDIR}/_ext/2056939211/phTools.o.d ${OBJECTDIR}/_ext/1420065484/icode_common.o.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o.d ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o.d ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o.d ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o.d ${OBJECTDIR}/_ext/1420065484/main.o.d ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o.d ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o.d ${OBJECTDIR}/_ext/1071406310/phPlatform.o.d ${OBJECTDIR}/_ext/1360900855/phhwConfig.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o ${OBJECTDIR}/_ext/1543058690/phalI15693.o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o ${OBJECTDIR}/_ext/192958335/phalSli.o ${OBJECTDIR}/_ext/1147107305/phbalReg.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o ${OBJECTDIR}/_ext/1870330116/phhalHw.o ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o ${OBJECTDIR}/_ext/75335025/phpalSli15693.o ${OBJECTDIR}/_ext/2056939211/phTools.o ${OBJECTDIR}/_ext/1420065484/icode_common.o ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o ${OBJECTDIR}/_ext/1420065484/main.o ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o ${OBJECTDIR}/_ext/1071406310/phPlatform.o ${OBJECTDIR}/_ext/1360900855/phhwConfig.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c ../NXP/comps/phalI15693/src/phalI15693.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c ../NXP/comps/phalSli/src/phalSli.c ../NXP/comps/phbalReg/src/phbalReg.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c ../NXP/comps/phhalHw/src/phhalHw.c ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c ../NXP/comps/phpalSli15693/src/phpalSli15693.c ../NXP/comps/phTools/src/phTools.c ../NXP/src/icode_common.c ../NXP/src/icode_ilt_commands.c ../NXP/src/icode_ilt_ui.c ../NXP/src/icode_sli_commands.c ../NXP/src/icode_sli_ui.c ../NXP/src/main.c ../NXP/Stub/phbalReg_Stub.c ../NXP/Stub/phOsal_Lpc17xx_Int.c ../NXP/Stub/phPlatform.c ../NXP/phhwConfig.c main.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o: ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/226416843" 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o.d" -o ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1543058690/phalI15693.o: ../NXP/comps/phalI15693/src/phalI15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1543058690" 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543058690/phalI15693.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1543058690/phalI15693.o.d" -o ${OBJECTDIR}/_ext/1543058690/phalI15693.o ../NXP/comps/phalI15693/src/phalI15693.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o.d" -o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o.d" -o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o: ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1083465500" 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o.d" -o ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o: ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755563796" 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o.d" -o ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/192958335/phalSli.o: ../NXP/comps/phalSli/src/phalSli.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/192958335" 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.o.d 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/192958335/phalSli.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/192958335/phalSli.o.d" -o ${OBJECTDIR}/_ext/192958335/phalSli.o ../NXP/comps/phalSli/src/phalSli.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1147107305/phbalReg.o: ../NXP/comps/phbalReg/src/phbalReg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1147107305" 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1147107305/phbalReg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1147107305/phbalReg.o.d" -o ${OBJECTDIR}/_ext/1147107305/phbalReg.o ../NXP/comps/phbalReg/src/phbalReg.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1870330116/phhalHw.o: ../NXP/comps/phhalHw/src/phhalHw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1870330116" 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1870330116/phhalHw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1870330116/phhalHw.o.d" -o ${OBJECTDIR}/_ext/1870330116/phhalHw.o ../NXP/comps/phhalHw/src/phhalHw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o: ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/424603049" 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o.d 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o.d" -o ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o: ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/521443061" 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o.d" -o ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o: ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2062512958" 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o.d 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o.d" -o ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o: ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1962118174" 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o.d" -o ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/75335025/phpalSli15693.o: ../NXP/comps/phpalSli15693/src/phpalSli15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/75335025" 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.o.d 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/75335025/phpalSli15693.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/75335025/phpalSli15693.o.d" -o ${OBJECTDIR}/_ext/75335025/phpalSli15693.o ../NXP/comps/phpalSli15693/src/phpalSli15693.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2056939211/phTools.o: ../NXP/comps/phTools/src/phTools.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2056939211" 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.o.d 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2056939211/phTools.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/2056939211/phTools.o.d" -o ${OBJECTDIR}/_ext/2056939211/phTools.o ../NXP/comps/phTools/src/phTools.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_common.o: ../NXP/src/icode_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_common.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_common.o ../NXP/src/icode_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o: ../NXP/src/icode_ilt_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o ../NXP/src/icode_ilt_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o: ../NXP/src/icode_ilt_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o ../NXP/src/icode_ilt_ui.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o: ../NXP/src/icode_sli_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o ../NXP/src/icode_sli_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o: ../NXP/src/icode_sli_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o ../NXP/src/icode_sli_ui.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/main.o: ../NXP/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/main.o.d" -o ${OBJECTDIR}/_ext/1420065484/main.o ../NXP/src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o: ../NXP/Stub/phbalReg_Stub.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o.d" -o ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o ../NXP/Stub/phbalReg_Stub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o: ../NXP/Stub/phOsal_Lpc17xx_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o.d" -o ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o ../NXP/Stub/phOsal_Lpc17xx_Int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1071406310/phPlatform.o: ../NXP/Stub/phPlatform.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.o.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1071406310/phPlatform.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1071406310/phPlatform.o.d" -o ${OBJECTDIR}/_ext/1071406310/phPlatform.o ../NXP/Stub/phPlatform.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360900855/phhwConfig.o: ../NXP/phhwConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360900855" 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360900855/phhwConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1360900855/phhwConfig.o.d" -o ${OBJECTDIR}/_ext/1360900855/phhwConfig.o ../NXP/phhwConfig.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o: ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/226416843" 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o.d" -o ${OBJECTDIR}/_ext/226416843/phalI15693_Sw.o ../NXP/comps/phalI15693/src/Sw/phalI15693_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1543058690/phalI15693.o: ../NXP/comps/phalI15693/src/phalI15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1543058690" 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.o.d 
	@${RM} ${OBJECTDIR}/_ext/1543058690/phalI15693.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1543058690/phalI15693.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1543058690/phalI15693.o.d" -o ${OBJECTDIR}/_ext/1543058690/phalI15693.o ../NXP/comps/phalI15693/src/phalI15693.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o.d" -o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw.o ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o: ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/841433201" 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o.d" -o ${OBJECTDIR}/_ext/841433201/phalI18000p3m3_Sw_Int.o ../NXP/comps/phalI18000p3m3/src/Sw/phalI18000p3m3_Sw_Int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o: ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1083465500" 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o.d" -o ${OBJECTDIR}/_ext/1083465500/phalI18000p3m3.o ../NXP/comps/phalI18000p3m3/src/phalI18000p3m3.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o: ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755563796" 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o.d" -o ${OBJECTDIR}/_ext/1755563796/phalSli_Sw.o ../NXP/comps/phalSli/src/Sw/phalSli_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/192958335/phalSli.o: ../NXP/comps/phalSli/src/phalSli.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/192958335" 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.o.d 
	@${RM} ${OBJECTDIR}/_ext/192958335/phalSli.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/192958335/phalSli.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/192958335/phalSli.o.d" -o ${OBJECTDIR}/_ext/192958335/phalSli.o ../NXP/comps/phalSli/src/phalSli.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1147107305/phbalReg.o: ../NXP/comps/phbalReg/src/phbalReg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1147107305" 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1147107305/phbalReg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1147107305/phbalReg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1147107305/phbalReg.o.d" -o ${OBJECTDIR}/_ext/1147107305/phbalReg.o ../NXP/comps/phbalReg/src/phbalReg.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Cmd.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Cmd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Int.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o: ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/632289455" 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o.d 
	@${RM} ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o.d" -o ${OBJECTDIR}/_ext/632289455/phhalHw_Rc663_Wait.o ../NXP/comps/phhalHw/src/Rc663/phhalHw_Rc663_Wait.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1870330116/phhalHw.o: ../NXP/comps/phhalHw/src/phhalHw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1870330116" 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1870330116/phhalHw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1870330116/phhalHw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1870330116/phhalHw.o.d" -o ${OBJECTDIR}/_ext/1870330116/phhalHw.o ../NXP/comps/phhalHw/src/phhalHw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o: ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/424603049" 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o.d 
	@${RM} ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o.d" -o ${OBJECTDIR}/_ext/424603049/phOsal_Nortos.o ../NXP/comps/phOsal/src/Nortos/phOsal_Nortos.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o: ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/521443061" 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o.d" -o ${OBJECTDIR}/_ext/521443061/phpalI18000p3m3_Sw.o ../NXP/comps/phpalI18000p3m3/src/Sw/phpalI18000p3m3_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o: ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2062512958" 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o.d 
	@${RM} ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o.d" -o ${OBJECTDIR}/_ext/2062512958/phpalI18000p3m3.o ../NXP/comps/phpalI18000p3m3/src/phpalI18000p3m3.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o: ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1962118174" 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o.d" -o ${OBJECTDIR}/_ext/1962118174/phpalSli15693_Sw.o ../NXP/comps/phpalSli15693/src/Sw/phpalSli15693_Sw.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/75335025/phpalSli15693.o: ../NXP/comps/phpalSli15693/src/phpalSli15693.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/75335025" 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.o.d 
	@${RM} ${OBJECTDIR}/_ext/75335025/phpalSli15693.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/75335025/phpalSli15693.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/75335025/phpalSli15693.o.d" -o ${OBJECTDIR}/_ext/75335025/phpalSli15693.o ../NXP/comps/phpalSli15693/src/phpalSli15693.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2056939211/phTools.o: ../NXP/comps/phTools/src/phTools.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2056939211" 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.o.d 
	@${RM} ${OBJECTDIR}/_ext/2056939211/phTools.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2056939211/phTools.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/2056939211/phTools.o.d" -o ${OBJECTDIR}/_ext/2056939211/phTools.o ../NXP/comps/phTools/src/phTools.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_common.o: ../NXP/src/icode_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_common.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_common.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_common.o ../NXP/src/icode_common.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o: ../NXP/src/icode_ilt_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_ilt_commands.o ../NXP/src/icode_ilt_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o: ../NXP/src/icode_ilt_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_ilt_ui.o ../NXP/src/icode_ilt_ui.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o: ../NXP/src/icode_sli_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_sli_commands.o ../NXP/src/icode_sli_commands.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o: ../NXP/src/icode_sli_ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o.d" -o ${OBJECTDIR}/_ext/1420065484/icode_sli_ui.o ../NXP/src/icode_sli_ui.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1420065484/main.o: ../NXP/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1420065484" 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1420065484/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1420065484/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1420065484/main.o.d" -o ${OBJECTDIR}/_ext/1420065484/main.o ../NXP/src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o: ../NXP/Stub/phbalReg_Stub.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o.d" -o ${OBJECTDIR}/_ext/1071406310/phbalReg_Stub.o ../NXP/Stub/phbalReg_Stub.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o: ../NXP/Stub/phOsal_Lpc17xx_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o.d" -o ${OBJECTDIR}/_ext/1071406310/phOsal_Lpc17xx_Int.o ../NXP/Stub/phOsal_Lpc17xx_Int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1071406310/phPlatform.o: ../NXP/Stub/phPlatform.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1071406310" 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.o.d 
	@${RM} ${OBJECTDIR}/_ext/1071406310/phPlatform.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1071406310/phPlatform.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1071406310/phPlatform.o.d" -o ${OBJECTDIR}/_ext/1071406310/phPlatform.o ../NXP/Stub/phPlatform.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360900855/phhwConfig.o: ../NXP/phhwConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360900855" 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360900855/phhwConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360900855/phhwConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/_ext/1360900855/phhwConfig.o.d" -o ${OBJECTDIR}/_ext/1360900855/phhwConfig.o ../NXP/phhwConfig.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -Os -I"../NXP" -I"../NXP/comps" -I"../NXP/inc" -I"../NXP/intfs" -I"../NXP/src" -I"../NXP/Stub" -I"../NXP/types" -I"../NXP/comps/phbalReg/src/Stub" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/BelIcodeClrc663_XC32.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
