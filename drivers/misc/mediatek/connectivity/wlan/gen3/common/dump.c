/*
** Id: //Department/DaVinci/BRANCHES/MT6620_WIFI_DRIVER_V2_3/common/dump.c#1
*/

/*! \file   "dump.c"
    \brief  Provide memory dump function for debugging.

    Provide memory dump function for debugging.
*/

/*
** Log: dump.c
**
** 09 17 2012 cm.chang
** [BORA00002149] [MT6630 Wi-Fi] Initial software development
** Duplicate source from MT6620 v2.3 driver branch
** (Davinci label: MT6620_WIFI_Driver_V2_3_120913_1942_As_MT6630_Base)
 *
 * 11 24 2011 wh.su
 * [WCXRP00001078] [MT6620 Wi-Fi][Driver] Adding the mediatek log improment support : XLOG
 * Adjust code for DBG and CONFIG_XLOG.
 *
 * 11 10 2011 wh.su
 * [WCXRP00001078] [MT6620 Wi-Fi][Driver] Adding the mediatek log improment support : XLOG
 * Using the new XLOG define for dum Memory.
 *
 * 11 03 2011 wh.su
 * [WCXRP00001078] [MT6620 Wi-Fi][Driver] Adding the mediatek log improment support : XLOG
 * Add dumpMemory8 at XLOG support.
 *
 * 07 08 2010 cp.wu
 *
 * [WPD00003833] [MT6620 and MT5931] Driver migration - move to new repository.
 *
 * 06 06 2010 kevin.huang
 * [WPD00003832][MT6620 5931] Create driver base
 * [MT6620 5931] Create driver base
**  \main\maintrunk.MT6620WiFiDriver_Prj\2 2009-03-10 19:58:51 GMT mtk01426
**  Init develop
**
*/

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/
#include "precomp.h"

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/

/*******************************************************************************
*                   F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/

/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

/*----------------------------------------------------------------------------*/
/*!
* \brief This routine is called to dump a segment of memory in bytes.
*
* \param[in] pucStartAddr   Pointer to the starting address of the memory to be dumped.
* \param[in] u4Length       Length of the memory to be dumped.
*
* \return (none)
*/
/*----------------------------------------------------------------------------*/
VOID dumpMemory8(IN UINT_32 u4DbgIndex, IN UINT_8 ucDbgClass, IN PUINT_8 pucStartAddr, IN UINT_32 u4Length)
{
	ASSERT(pucStartAddr);

	DBGFUNC(u4DbgIndex, ucDbgClass, "DUMP8 ADDRESS: %x, Length: %d\n", (ULONG) pucStartAddr, u4Length);

	while (u4Length > 0) {
		if (u4Length >= 16) {
			DBGFUNC(u4DbgIndex, ucDbgClass,
			"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x %02x %02x %02x  %02x %02x %02x %02x\n",
				 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
				 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4], pucStartAddr[5],
				 pucStartAddr[6], pucStartAddr[7], pucStartAddr[8], pucStartAddr[9],
				 pucStartAddr[10], pucStartAddr[11], pucStartAddr[12],
				 pucStartAddr[13], pucStartAddr[14], pucStartAddr[15]);
			u4Length -= 16;
			pucStartAddr += 16;
		} else {
			switch (u4Length) {
			case 1:
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %02x\n",
					(ULONG) pucStartAddr, pucStartAddr[0]);
				break;
			case 2:
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %02x %02x\n",
					(ULONG) pucStartAddr,
					pucStartAddr[0], pucStartAddr[1]);
				break;
			case 3:
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %02x %02x %02x\n",
					(ULONG) pucStartAddr,
					pucStartAddr[0], pucStartAddr[1], pucStartAddr[2]);
				break;
			case 4:
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %02x %02x %02x %02x\n",
					(ULONG) pucStartAddr,
					pucStartAddr[0], pucStartAddr[1],
					pucStartAddr[2], pucStartAddr[3]);
				break;
			case 5:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4]);
				break;
			case 6:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4], pucStartAddr[5]);
				break;
			case 7:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x %02x %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
					 pucStartAddr[5], pucStartAddr[6]);
				break;
			case 8:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
					 pucStartAddr[5], pucStartAddr[6], pucStartAddr[7]);
				break;
			case 9:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
					 pucStartAddr[5], pucStartAddr[6], pucStartAddr[7], pucStartAddr[8]);
				break;
			case 10:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
					 pucStartAddr[5], pucStartAddr[6], pucStartAddr[7],
					 pucStartAddr[8], pucStartAddr[9]);
				break;
			case 11:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x %02x %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
					 pucStartAddr[5], pucStartAddr[6], pucStartAddr[7],
					 pucStartAddr[8], pucStartAddr[9], pucStartAddr[10]);
				break;
			case 12:
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x %02x %02x %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
					 pucStartAddr[5], pucStartAddr[6], pucStartAddr[7],
					 pucStartAddr[8], pucStartAddr[9], pucStartAddr[10], pucStartAddr[11]);
				break;
			case 13:
				DBGFUNC(u4DbgIndex, ucDbgClass,
				"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x %02x %02x %02x  %02x\n",
					 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
					 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
					 pucStartAddr[5], pucStartAddr[6], pucStartAddr[7],
					 pucStartAddr[8], pucStartAddr[9], pucStartAddr[10],
					 pucStartAddr[11], pucStartAddr[12]);
				break;
			case 14:
			DBGFUNC(u4DbgIndex, ucDbgClass,
			"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x %02x %02x %02x  %02x %02x\n",
				 (ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
				 pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
				 pucStartAddr[5], pucStartAddr[6], pucStartAddr[7],
				 pucStartAddr[8], pucStartAddr[9], pucStartAddr[10],
				 pucStartAddr[11], pucStartAddr[12], pucStartAddr[13]);
				break;
			case 15:
			DBGFUNC(u4DbgIndex, ucDbgClass,
			"(%08x) %02x %02x %02x %02x  %02x %02x %02x %02x - %02x %02x %02x %02x  %02x %02x %02x\n",
				(ULONG) pucStartAddr, pucStartAddr[0], pucStartAddr[1],
				pucStartAddr[2], pucStartAddr[3], pucStartAddr[4],
				pucStartAddr[5], pucStartAddr[6], pucStartAddr[7],
				pucStartAddr[8], pucStartAddr[9], pucStartAddr[10],
				pucStartAddr[11], pucStartAddr[12], pucStartAddr[13], pucStartAddr[14]);
				break;
			default:
				break;
			}
			u4Length = 0;
		}
	}

	DBGFUNC(u4DbgIndex, ucDbgClass, "\n");
}				/* end of dumpMemory8() */

/*----------------------------------------------------------------------------*/
/*!
* \brief This routine is called to dump a segment of memory in double words.
*
* \param[in] pucStartAddr   Pointer to the starting address of the memory to be dumped.
* \param[in] u4Length       Length of the memory to be dumped.
*
* \return (none)
*/
/*----------------------------------------------------------------------------*/
VOID dumpMemory32(IN UINT_32 u4DbgIndex, IN UINT_8 ucDbgClass, IN PUINT_32 pu4StartAddr, IN UINT_32 u4Length)
{
	PUINT_8 pucAddr;

	ASSERT(pu4StartAddr);

	DBGFUNC(u4DbgIndex, ucDbgClass, "DUMP32 ADDRESS: %08x, Length: %d\n", (ULONG) pu4StartAddr, u4Length);

	if (IS_NOT_ALIGN_4((ULONG) pu4StartAddr)) {
		UINT_32 u4ProtrudeLen = sizeof(UINT_32) - ((ULONG) pu4StartAddr % 4);

		u4ProtrudeLen = ((u4Length < u4ProtrudeLen) ? u4Length : u4ProtrudeLen);
		DBGFUNC(u4DbgIndex, ucDbgClass, "pu4StartAddr is not at DW boundary.\n");
		pucAddr = (PUINT_8) &pu4StartAddr[0];

		switch (u4ProtrudeLen) {
		case 1:
			DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %02x------\n", (ULONG) pu4StartAddr, pucAddr[0]);
			break;
		case 2:
			DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %02x%02x----\n",
							 (ULONG) pu4StartAddr, pucAddr[1], pucAddr[0]);
			break;
		case 3:
			DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %02x%02x%02x--\n",
							 (ULONG) pu4StartAddr, pucAddr[2], pucAddr[1], pucAddr[0]);
			break;
		default:
			break;
		}

		u4Length -= u4ProtrudeLen;
		pu4StartAddr = (PUINT_32) ((ULONG) pu4StartAddr + u4ProtrudeLen);
	}

	while (u4Length > 0) {
		if (u4Length >= 16) {
			DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x %08x %08x %08x\n",
							 (ULONG) pu4StartAddr,
							 pu4StartAddr[0], pu4StartAddr[1],
							 pu4StartAddr[2], pu4StartAddr[3]);
			pu4StartAddr += 4;
			u4Length -= 16;
		} else {
			switch (u4Length) {
			case 1:
				pucAddr = (PUINT_8) &pu4StartAddr[0];
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) ------%02x\n",
								 (ULONG) pu4StartAddr, pucAddr[0]);
				break;
			case 2:
				pucAddr = (PUINT_8) &pu4StartAddr[0];
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) ----%02x%02x\n",
								 (ULONG) pu4StartAddr, pucAddr[1], pucAddr[0]);
				break;
			case 3:
				pucAddr = (PUINT_8) &pu4StartAddr[0];
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) --%02x%02x%02x\n",
								 (ULONG) pu4StartAddr,
								 pucAddr[2], pucAddr[1], pucAddr[0]);
				break;
			case 4:
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x\n",
								 (ULONG) pu4StartAddr, pu4StartAddr[0]);
				break;
			case 5:
				pucAddr = (PUINT_8) &pu4StartAddr[1];
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x ------%02x\n",
								 (ULONG) pu4StartAddr, pu4StartAddr[0], pucAddr[0]);
				break;
			case 6:
				pucAddr = (PUINT_8) &pu4StartAddr[1];
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x ----%02x%02x\n",
								 (ULONG) pu4StartAddr,
								 pu4StartAddr[0], pucAddr[1], pucAddr[0]);
				break;
			case 7:
				pucAddr = (PUINT_8) &pu4StartAddr[1];
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x --%02x%02x%02x\n",
								 (ULONG) pu4StartAddr,
								 pu4StartAddr[0], pucAddr[2], pucAddr[1], pucAddr[0]);
				break;
			case 8:
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x %08x\n",
								 (ULONG) pu4StartAddr,
								 pu4StartAddr[0], pu4StartAddr[1]);
				break;
			case 9:
				pucAddr = (PUINT_8) &pu4StartAddr[2];
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x %08x ------%02x\n",
								 (ULONG) pu4StartAddr,
								 pu4StartAddr[0], pu4StartAddr[1], pucAddr[0]);
				break;
			case 10:
				pucAddr = (PUINT_8) &pu4StartAddr[2];
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %08x %08x ----%02x%02x\n",
					 (ULONG) pu4StartAddr, pu4StartAddr[0], pu4StartAddr[1],
					 pucAddr[1], pucAddr[0]);
				break;
			case 11:
				pucAddr = (PUINT_8) &pu4StartAddr[2];
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %08x %08x --%02x%02x%02x\n",
					 (ULONG) pu4StartAddr, pu4StartAddr[0], pu4StartAddr[1],
					 pucAddr[2], pucAddr[1], pucAddr[0]);
				break;
			case 12:
				DBGFUNC(u4DbgIndex, ucDbgClass, "(%08x) %08x %08x %08x\n",
								 (ULONG) pu4StartAddr,
								 pu4StartAddr[0], pu4StartAddr[1], pu4StartAddr[2]);
				break;
			case 13:
				pucAddr = (PUINT_8) &pu4StartAddr[3];
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %08x %08x %08x ------%02x\n",
					 (ULONG) pu4StartAddr, pu4StartAddr[0], pu4StartAddr[1],
					 pu4StartAddr[2], pucAddr[0]);
				break;
			case 14:
				pucAddr = (PUINT_8) &pu4StartAddr[3];
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %08x %08x %08x ----%02x%02x\n",
					 (ULONG) pu4StartAddr, pu4StartAddr[0], pu4StartAddr[1],
					 pu4StartAddr[2], pucAddr[1], pucAddr[0]);
				break;
			case 15:
				pucAddr = (PUINT_8) &pu4StartAddr[3];
				DBGFUNC(u4DbgIndex, ucDbgClass,
					"(%08x) %08x %08x %08x --%02x%02x%02x\n",
					 (ULONG) pu4StartAddr, pu4StartAddr[0], pu4StartAddr[1],
					 pu4StartAddr[2], pucAddr[2], pucAddr[1], pucAddr[0]);
				break;
			default:
				break;
			}
			u4Length = 0;
		}
	}
}				/* end of dumpMemory32() */
