void STAvUpdateIsrStatCounter(PSStatCounter pStatistic, unsigned long dwIsr)
{
if (dwIsr == 0) {
pStatistic->ISRStat.dwIsrUnknown++;
return;
}
if (dwIsr & ISR_TXDMA0)
pStatistic->ISRStat.dwIsrTx0OK++;
if (dwIsr & ISR_AC0DMA)
pStatistic->ISRStat.dwIsrAC0TxOK++;
if (dwIsr & ISR_BNTX)
pStatistic->ISRStat.dwIsrBeaconTxOK++;
if (dwIsr & ISR_RXDMA0)
pStatistic->ISRStat.dwIsrRx0OK++;
if (dwIsr & ISR_TBTT)
pStatistic->ISRStat.dwIsrTBTTInt++;
if (dwIsr & ISR_SOFTTIMER)
pStatistic->ISRStat.dwIsrSTIMERInt++;
if (dwIsr & ISR_WATCHDOG)
pStatistic->ISRStat.dwIsrWatchDog++;
if (dwIsr & ISR_FETALERR)
pStatistic->ISRStat.dwIsrUnrecoverableError++;
if (dwIsr & ISR_SOFTINT)
pStatistic->ISRStat.dwIsrSoftInterrupt++;
if (dwIsr & ISR_MIBNEARFULL)
pStatistic->ISRStat.dwIsrMIBNearfull++;
if (dwIsr & ISR_RXNOBUF)
pStatistic->ISRStat.dwIsrRxNoBuf++;
if (dwIsr & ISR_RXDMA1)
pStatistic->ISRStat.dwIsrRx1OK++;
if (dwIsr & ISR_SOFTTIMER1)
pStatistic->ISRStat.dwIsrSTIMER1Int++;
}
void
STAvUpdate802_11Counter(
PSDot11Counters p802_11Counter,
PSStatCounter pStatistic,
unsigned long dwCounter
)
{
p802_11Counter->RTSSuccessCount += (unsigned long long) (dwCounter & 0x000000ff);
p802_11Counter->RTSFailureCount += (unsigned long long) ((dwCounter & 0x0000ff00) >> 8);
p802_11Counter->ACKFailureCount += (unsigned long long) ((dwCounter & 0x00ff0000) >> 16);
p802_11Counter->FCSErrorCount += (unsigned long long) ((dwCounter & 0xff000000) >> 24);
}
