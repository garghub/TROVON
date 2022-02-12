static void AirPDcapTkipMixingPhase1(
UINT16 *TTAK,
const UINT8 *TK,
const UINT8 *TA,
UINT32 TSC)
{
UINT16 i, j;
TTAK[0] = Lo16(TSC);
TTAK[1] = Hi16(TSC);
TTAK[2] = Mk16(TA[1], TA[0]);
TTAK[3] = Mk16(TA[3], TA[2]);
TTAK[4] = Mk16(TA[5], TA[4]);
for (i = 0; i < PHASE1_LOOP_COUNT; i++) {
j = (UINT16)(2 * (i & 1));
TTAK[0] = (UINT16)(TTAK[0] + _S_((UINT16)(TTAK[4] ^ Mk16(TK[1 + j], TK[0 + j]))));
TTAK[1] = (UINT16)(TTAK[1] + _S_((UINT16)(TTAK[0] ^ Mk16(TK[5 + j], TK[4 + j]))));
TTAK[2] = (UINT16)(TTAK[2] + _S_((UINT16)(TTAK[1] ^ Mk16(TK[9 + j], TK[8 + j]))));
TTAK[3] = (UINT16)(TTAK[3] + _S_((UINT16)(TTAK[2] ^ Mk16(TK[13 + j], TK[12 + j]))));
TTAK[4] = (UINT16)(TTAK[4] + _S_((UINT16)(TTAK[3] ^ Mk16(TK[1 + j], TK[0 + j]))) + i);
}
}
static void AirPDcapTkipMixingPhase2(
UINT8 *wep_seed,
const UINT8 *TK,
UINT16 *TTAK,
UINT16 TSC16)
{
INT i;
TTAK[5] = (UINT16)(TTAK[4] + TSC16);
TTAK[0] = (UINT16)(TTAK[0] + _S_((UINT16)(TTAK[5] ^ Mk16_le(&TK[0]))));
TTAK[1] = (UINT16)(TTAK[1] + _S_((UINT16)(TTAK[0] ^ Mk16_le(&TK[2]))));
TTAK[2] = (UINT16)(TTAK[2] + _S_((UINT16)(TTAK[1] ^ Mk16_le(&TK[4]))));
TTAK[3] = (UINT16)(TTAK[3] + _S_((UINT16)(TTAK[2] ^ Mk16_le(&TK[6]))));
TTAK[4] = (UINT16)(TTAK[4] + _S_((UINT16)(TTAK[3] ^ Mk16_le(&TK[8]))));
TTAK[5] = (UINT16)(TTAK[5] + _S_((UINT16)(TTAK[4] ^ Mk16_le(&TK[10]))));
TTAK[0] = (UINT16)(TTAK[0] + RotR1((UINT16)(TTAK[5] ^ Mk16_le(&TK[12]))));
TTAK[1] = (UINT16)(TTAK[1] + RotR1((UINT16)(TTAK[0] ^ Mk16_le(&TK[14]))));
TTAK[2] = (UINT16)(TTAK[2] + RotR1(TTAK[1]));
TTAK[3] = (UINT16)(TTAK[3] + RotR1(TTAK[2]));
TTAK[4] = (UINT16)(TTAK[4] + RotR1(TTAK[3]));
TTAK[5] = (UINT16)(TTAK[5] + RotR1(TTAK[4]));
wep_seed[0] = Hi8(TSC16);
wep_seed[1] = (UINT8)((Hi8(TSC16) | 0x20) & 0x7F);
wep_seed[2] = Lo8(TSC16);
wep_seed[3] = Lo8((UINT16)((TTAK[5] ^ Mk16_le(&TK[0])) >> 1));
for (i = 0; i < 6; i++)
{
wep_seed[4 + ( 2 * i)] = Lo8( TTAK[i] );
wep_seed[5 + ( 2 * i)] = Hi8( TTAK[i] );
}
}
INT AirPDcapTkipDecrypt(
UCHAR *tkip_mpdu,
size_t mpdu_len,
UCHAR TA[AIRPDCAP_MAC_LEN],
UCHAR TK[AIRPDCAP_TK_LEN])
{
UINT64 TSC64;
UINT32 TSC;
UINT16 TSC16;
UINT8 *IV;
UINT16 TTAK[AIRPDCAP_TTAK_LEN];
UINT8 wep_seed[AIRPDCAP_WEP_128_KEY_LEN];
IV = tkip_mpdu;
TSC64 = READ_6(IV[2], IV[0], IV[4], IV[5], IV[6], IV[7]);
TSC16 = (UINT16)TSC64;
TSC = (UINT32)(TSC64 >> 16);
AirPDcapTkipMixingPhase1(TTAK, TK, TA, TSC);
AirPDcapTkipMixingPhase2(wep_seed, TK, TTAK, TSC16);
return AirPDcapWepDecrypt(
wep_seed,
AIRPDCAP_WEP_128_KEY_LEN,
tkip_mpdu + AIRPDCAP_TKIP_HEADER,
mpdu_len-(AIRPDCAP_TKIP_HEADER+AIRPDCAP_WEP_ICV));
}
