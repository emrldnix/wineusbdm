#include <stdio.h>
#include <stdlib.h>

typedef int (*icpCallBackT)(
    int status, unsigned int percent);
typedef int (__stdcall *WIN32_icpCallBackT)(
    int status, unsigned int percent);

int USBDM_Init(void);
int USBDM_Exit(void);
unsigned int USBDM_DLLVersion(void);
const char *USBDM_DLLVersionString(void);
const char *USBDM_GetErrorString(int errorCode);
int USBDM_FindDevices(unsigned int *deviceCount);
int USBDM_ReleaseDevices(void);
int USBDM_GetBDMSerialNumber(const char **deviceSerialNumber);
int USBDM_GetBDMDescription(const char **deviceDescription);
int USBDM_Open(unsigned char deviceNo);
int USBDM_Close(void);
int USBDM_GetVersion(void *version);
int USBDM_GetCapabilities(int *capabilities);
int USBDM_GetBdmInformation(void *info);
int USBDM_SetOptions(void *newBdmOptions);
int USBDM_GetDefaultExtendedOptions(void *bdmOptions);
int USBDM_SetExtendedOptions(const void *newBdmOptions);
int USBDM_GetExtendedOptions(void *currentBdmOptions);
int USBDM_SetTargetVdd(int targetVdd);
int USBDM_SetTargetVpp(int targetVpp);
int USBDM_ControlInterface(unsigned char duration_10us, unsigned int control);
int USBDM_ControlPins(unsigned int control, unsigned int *status);
int USBDM_SetTargetType(int targetType);
int USBDM_Debug(unsigned char *usb_data);
int USBDM_BDMCommand(unsigned int txSize, unsigned int rxSize, unsigned char data[]);
int USBDM_GetCommandStatus(void);
int USBDM_GetBDMStatus(void *USBDMStatus);
int USBDM_Connect(void);
int USBDM_SetSpeed(unsigned long frequency);
int USBDM_GetSpeed(unsigned long *frequency);
int USBDM_GetSpeedHz(unsigned long *frequency);
int USBDM_ReadStatusReg(unsigned long *BDMStatusReg);
int USBDM_WriteControlReg(unsigned int value);
int USBDM_TargetReset(int target_mode);
int USBDM_TargetStep(void);
int USBDM_TargetGo(void);
int USBDM_TargetHalt(void);
int USBDM_WriteReg(unsigned int regNo, unsigned long regValue);
int USBDM_ReadReg(unsigned int regNo, unsigned long *regValue);
int USBDM_ReadMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex);
int USBDM_WriteCReg(unsigned int regNo, unsigned long regValue);
int USBDM_ReadCReg(unsigned int regNo, unsigned long *regValue);
int USBDM_WriteDReg(unsigned int regNo, unsigned long regValue);
int USBDM_ReadDReg(unsigned int regNo, unsigned long *regValue);
int USBDM_WriteMemory(unsigned int memorySpace, unsigned int byteCount, unsigned int address, unsigned const char *data);
int USBDM_ReadMemory(unsigned int memorySpace, unsigned int byteCount, unsigned int address, unsigned char *data);
int USBDM_JTAG_Reset(void);
int USBDM_JTAG_SelectShift(unsigned char mode);
int USBDM_JTAG_Write(unsigned char bitCount, unsigned char exit, const unsigned char *buffer);
int USBDM_JTAG_Read(unsigned char bitCount, unsigned char exit, unsigned char *buffer);
int USBDM_JTAG_ReadWrite(unsigned char bitCount, unsigned char exit, const unsigned char *outBuffer, unsigned char *inBuffer);
int USBDM_JTAG_ExecuteSequence(unsigned char length, const unsigned char *sequence, unsigned char inLength, unsigned char *inBuffer);
void *USBDM_GetLogFile(void);
void USBDM_SetLogFile(void *fp);
void USBDM_RebootToICP(void);
int USBDM_ICP_Erase(unsigned int addr, unsigned int count);
int USBDM_ICP_Program(unsigned int addr, unsigned int count, unsigned char *data);
int USBDM_ICP_Verify(unsigned int addr, unsigned int count, unsigned char *data);
void USBDM_ICP_Reboot(void);
void USBDM_ICP_SetCallback(icpCallBackT icpCallBack_);

__stdcall int _USBDM_Init(void)
{ return USBDM_Init(); }
__stdcall int _USBDM_Exit(void)
{ return USBDM_Exit(); }
__stdcall unsigned int _USBDM_DLLVersion(void)
{ return USBDM_DLLVersion(); }
__stdcall const char *_USBDM_DLLVersionString(void)
{ return USBDM_DLLVersionString(); }
__stdcall const char *_USBDM_GetErrorString(int errorCode)
{ return USBDM_GetErrorString(errorCode); }
__stdcall int _USBDM_FindDevices(unsigned int *deviceCount)
{ return USBDM_FindDevices(deviceCount); }
__stdcall int _USBDM_ReleaseDevices(void)
{ return USBDM_ReleaseDevices(); }
__stdcall int _USBDM_GetBDMSerialNumber(const char **deviceSerialNumber)
{ return USBDM_GetBDMSerialNumber(deviceSerialNumber); }
__stdcall int _USBDM_GetBDMDescription(const char **deviceDescription)
{ return USBDM_GetBDMDescription(deviceDescription); }
__stdcall int _USBDM_Open(unsigned char deviceNo)
{ return USBDM_Open(deviceNo); }
__stdcall int _USBDM_Close(void)
{ return USBDM_Close(); }
__stdcall int _USBDM_GetVersion(void *version)
{ return USBDM_GetVersion(version); }
__stdcall int _USBDM_GetCapabilities(int *capabilities)
{ return USBDM_GetCapabilities(capabilities); }
__stdcall int _USBDM_GetBdmInformation(void *info)
{ return USBDM_GetBdmInformation(info); }
__stdcall int _USBDM_SetOptions(void *newBdmOptions)
{ return USBDM_SetOptions(newBdmOptions); }
__stdcall int _USBDM_GetDefaultExtendedOptions(void *bdmOptions)
{ return USBDM_GetDefaultExtendedOptions(bdmOptions); }
__stdcall int _USBDM_SetExtendedOptions(const void *newBdmOptions)
{ return USBDM_SetExtendedOptions(newBdmOptions); }
__stdcall int _USBDM_GetExtendedOptions(void *currentBdmOptions)
{ return USBDM_GetExtendedOptions(currentBdmOptions); }
__stdcall int _USBDM_SetTargetVdd(int targetVdd)
{ return USBDM_SetTargetVdd(targetVdd); }
__stdcall int _USBDM_SetTargetVpp(int targetVpp)
{ return USBDM_SetTargetVpp(targetVpp); }
__stdcall int _USBDM_ControlInterface(unsigned char duration_10us, unsigned int control)
{ fprintf(stderr, "implement USBDM_ControlInterface"); abort(); }
__stdcall int _USBDM_ControlPins(unsigned int control, unsigned int *status)
{ return USBDM_ControlPins(control, status); }
__stdcall int _USBDM_SetTargetType(int targetType)
{ return USBDM_SetTargetType(targetType); }
__stdcall int _USBDM_Debug(unsigned char *usb_data)
{ return USBDM_Debug(usb_data); }
__stdcall int _USBDM_BDMCommand(unsigned int txSize, unsigned int rxSize, unsigned char data[])
{ return USBDM_BDMCommand(txSize, rxSize, data); }
__stdcall int _USBDM_GetCommandStatus(void)
{ return USBDM_GetCommandStatus(); }
__stdcall int _USBDM_GetBDMStatus(void *USBDMStatus)
{ return USBDM_GetBDMStatus(USBDMStatus); }
__stdcall int _USBDM_Connect(void)
{ return USBDM_Connect(); }
__stdcall int _USBDM_SetSpeed(unsigned long frequency)
{ return USBDM_SetSpeed(frequency); }
__stdcall int _USBDM_GetSpeed(unsigned long *frequency)
{ return USBDM_GetSpeed(frequency); }
__stdcall int _USBDM_GetSpeedHz(unsigned long *frequency)
{ return USBDM_GetSpeedHz(frequency); }
__stdcall int _USBDM_ReadStatusReg(unsigned long *BDMStatusReg)
{ return USBDM_ReadStatusReg(BDMStatusReg); }
__stdcall int _USBDM_WriteControlReg(unsigned int value)
{ return USBDM_WriteControlReg(value); }
__stdcall int _USBDM_TargetReset(int target_mode)
{ return USBDM_TargetReset(target_mode); }
__stdcall int _USBDM_TargetStep(void)
{ return USBDM_TargetStep(); }
__stdcall int _USBDM_TargetGo(void)
{ return USBDM_TargetGo(); }
__stdcall int _USBDM_TargetHalt(void)
{ return USBDM_TargetHalt(); }
__stdcall int _USBDM_WriteReg(unsigned int regNo, unsigned long regValue)
{ return USBDM_WriteReg(regNo, regValue); }
__stdcall int _USBDM_ReadReg(unsigned int regNo, unsigned long *regValue)
{ return USBDM_ReadReg(regNo, regValue); }
__stdcall int _USBDM_ReadMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex)
{ return USBDM_ReadMultipleRegs(regValueBuffer, startRegIndex, endRegIndex); }
__stdcall int _USBDM_WriteCReg(unsigned int regNo, unsigned long regValue)
{ return USBDM_WriteCReg(regNo, regValue); }
__stdcall int _USBDM_ReadCReg(unsigned int regNo, unsigned long *regValue)
{ return USBDM_ReadCReg(regNo, regValue); }
__stdcall int _USBDM_WriteDReg(unsigned int regNo, unsigned long regValue)
{ return USBDM_WriteDReg(regNo, regValue); }
__stdcall int _USBDM_ReadDReg(unsigned int regNo, unsigned long *regValue)
{ return USBDM_ReadDReg(regNo, regValue); }
__stdcall int _USBDM_WriteMemory(unsigned int memorySpace, unsigned int byteCount, unsigned int address, unsigned const char *data)
{ return USBDM_WriteMemory(memorySpace, byteCount, address, data); }
__stdcall int _USBDM_ReadMemory(unsigned int memorySpace, unsigned int byteCount, unsigned int address, unsigned char *data)
{ return USBDM_ReadMemory(memorySpace, byteCount, address, data); }
__stdcall int _USBDM_JTAG_Reset(void)
{ return USBDM_JTAG_Reset(); }
__stdcall int _USBDM_JTAG_SelectShift(unsigned char mode)
{ return USBDM_JTAG_SelectShift(mode); }
__stdcall int _USBDM_JTAG_Write(unsigned char bitCount, unsigned char exit, const unsigned char *buffer)
{ return USBDM_JTAG_Write(bitCount, exit, buffer); }
__stdcall int _USBDM_JTAG_Read(unsigned char bitCount, unsigned char exit, unsigned char *buffer)
{ return USBDM_JTAG_Read(bitCount, exit, buffer); }
__stdcall int _USBDM_JTAG_ReadWrite(unsigned char bitCount, unsigned char exit, const unsigned char *outBuffer, unsigned char *inBuffer)
{ return USBDM_JTAG_ReadWrite(bitCount, exit, outBuffer, inBuffer); }
__stdcall int _USBDM_JTAG_ExecuteSequence(unsigned char length, const unsigned char *sequence, unsigned char inLength, unsigned char *inBuffer)
{ return USBDM_JTAG_ExecuteSequence(length, sequence, inLength, inBuffer); }
__stdcall void *_USBDM_GetLogFile(void)
{ return USBDM_GetLogFile(); }
__stdcall void _USBDM_SetLogFile(void *fp)
{ USBDM_SetLogFile(fp); }
__stdcall void _USBDM_RebootToICP(void)
{ USBDM_RebootToICP(); }
__stdcall int _USBDM_ICP_Erase(unsigned int addr, unsigned int count)
{ return USBDM_ICP_Erase(addr, count); }
__stdcall int _USBDM_ICP_Program(unsigned int addr, unsigned int count, unsigned char *data)
{ return USBDM_ICP_Program(addr, count, data); }
__stdcall int _USBDM_ICP_Verify(unsigned int addr, unsigned int count, unsigned char *data)
{ return USBDM_ICP_Verify(addr, count, data); }
__stdcall void _USBDM_ICP_Reboot(void)
{ USBDM_ICP_Reboot(); }
__stdcall void _USBDM_ICP_SetCallback(WIN32_icpCallBackT icpCallBack_)
{ fprintf(stderr, "implement USBDM_ICP_SetCallback"); abort(); }
