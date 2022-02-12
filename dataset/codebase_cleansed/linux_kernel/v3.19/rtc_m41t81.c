static int m41t81_read(uint8_t addr)
{
while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
;
__raw_writeq(addr & 0xff, SMB_CSR(R_SMB_CMD));
__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_WR1BYTE,
SMB_CSR(R_SMB_START));
while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
;
__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_RD1BYTE,
SMB_CSR(R_SMB_START));
while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
;
if (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_ERROR) {
__raw_writeq(M_SMB_ERROR, SMB_CSR(R_SMB_STATUS));
return -1;
}
return __raw_readq(SMB_CSR(R_SMB_DATA)) & 0xff;
}
static int m41t81_write(uint8_t addr, int b)
{
while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
;
__raw_writeq(addr & 0xff, SMB_CSR(R_SMB_CMD));
__raw_writeq(b & 0xff, SMB_CSR(R_SMB_DATA));
__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_WR2BYTE,
SMB_CSR(R_SMB_START));
while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
;
if (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_ERROR) {
__raw_writeq(M_SMB_ERROR, SMB_CSR(R_SMB_STATUS));
return -1;
}
__raw_writeq(V_SMB_ADDR(M41T81_CCR_ADDRESS) | V_SMB_TT_RD1BYTE,
SMB_CSR(R_SMB_START));
while (__raw_readq(SMB_CSR(R_SMB_STATUS)) & M_SMB_BUSY)
;
return 0;
}
int m41t81_set_time(unsigned long t)
{
struct rtc_time tm;
unsigned long flags;
rtc_time_to_tm(t, &tm);
spin_lock_irqsave(&rtc_lock, flags);
tm.tm_sec = bin2bcd(tm.tm_sec);
m41t81_write(M41T81REG_SC, tm.tm_sec);
tm.tm_min = bin2bcd(tm.tm_min);
m41t81_write(M41T81REG_MN, tm.tm_min);
tm.tm_hour = bin2bcd(tm.tm_hour);
tm.tm_hour = (tm.tm_hour & 0x3f) | (m41t81_read(M41T81REG_HR) & 0xc0);
m41t81_write(M41T81REG_HR, tm.tm_hour);
if (tm.tm_wday == 0) tm.tm_wday = 7;
tm.tm_wday = bin2bcd(tm.tm_wday);
m41t81_write(M41T81REG_DY, tm.tm_wday);
tm.tm_mday = bin2bcd(tm.tm_mday);
m41t81_write(M41T81REG_DT, tm.tm_mday);
tm.tm_mon ++;
tm.tm_mon = bin2bcd(tm.tm_mon);
m41t81_write(M41T81REG_MO, tm.tm_mon);
tm.tm_year %= 100;
tm.tm_year = bin2bcd(tm.tm_year);
m41t81_write(M41T81REG_YR, tm.tm_year);
spin_unlock_irqrestore(&rtc_lock, flags);
return 0;
}
unsigned long m41t81_get_time(void)
{
unsigned int year, mon, day, hour, min, sec;
unsigned long flags;
for (;;) {
spin_lock_irqsave(&rtc_lock, flags);
sec = m41t81_read(M41T81REG_SC);
min = m41t81_read(M41T81REG_MN);
if (sec == m41t81_read(M41T81REG_SC)) break;
spin_unlock_irqrestore(&rtc_lock, flags);
}
hour = m41t81_read(M41T81REG_HR) & 0x3f;
day = m41t81_read(M41T81REG_DT);
mon = m41t81_read(M41T81REG_MO);
year = m41t81_read(M41T81REG_YR);
spin_unlock_irqrestore(&rtc_lock, flags);
sec = bcd2bin(sec);
min = bcd2bin(min);
hour = bcd2bin(hour);
day = bcd2bin(day);
mon = bcd2bin(mon);
year = bcd2bin(year);
year += 2000;
return mktime(year, mon, day, hour, min, sec);
}
int m41t81_probe(void)
{
unsigned int tmp;
tmp = m41t81_read(M41T81REG_SC);
m41t81_write(M41T81REG_SC, tmp & 0x7f);
return m41t81_read(M41T81REG_SC) != -1;
}
