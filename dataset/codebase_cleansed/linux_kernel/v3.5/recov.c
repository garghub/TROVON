static void raid6_2data_recov_intx1(int disks, size_t bytes, int faila,
int failb, void **ptrs)
{
u8 *p, *q, *dp, *dq;
u8 px, qx, db;
const u8 *pbmul;
const u8 *qmul;
p = (u8 *)ptrs[disks-2];
q = (u8 *)ptrs[disks-1];
dp = (u8 *)ptrs[faila];
ptrs[faila] = (void *)raid6_empty_zero_page;
ptrs[disks-2] = dp;
dq = (u8 *)ptrs[failb];
ptrs[failb] = (void *)raid6_empty_zero_page;
ptrs[disks-1] = dq;
raid6_call.gen_syndrome(disks, bytes, ptrs);
ptrs[faila] = dp;
ptrs[failb] = dq;
ptrs[disks-2] = p;
ptrs[disks-1] = q;
pbmul = raid6_gfmul[raid6_gfexi[failb-faila]];
qmul = raid6_gfmul[raid6_gfinv[raid6_gfexp[faila]^raid6_gfexp[failb]]];
while ( bytes-- ) {
px = *p ^ *dp;
qx = qmul[*q ^ *dq];
*dq++ = db = pbmul[px] ^ qx;
*dp++ = db ^ px;
p++; q++;
}
}
static void raid6_datap_recov_intx1(int disks, size_t bytes, int faila,
void **ptrs)
{
u8 *p, *q, *dq;
const u8 *qmul;
p = (u8 *)ptrs[disks-2];
q = (u8 *)ptrs[disks-1];
dq = (u8 *)ptrs[faila];
ptrs[faila] = (void *)raid6_empty_zero_page;
ptrs[disks-1] = dq;
raid6_call.gen_syndrome(disks, bytes, ptrs);
ptrs[faila] = dq;
ptrs[disks-1] = q;
qmul = raid6_gfmul[raid6_gfinv[raid6_gfexp[faila]]];
while ( bytes-- ) {
*p++ ^= *dq = qmul[*q ^ *dq];
q++; dq++;
}
}
void raid6_dual_recov(int disks, size_t bytes, int faila, int failb, void **ptrs)
{
if ( faila > failb ) {
int tmp = faila;
faila = failb;
failb = tmp;
}
if ( failb == disks-1 ) {
if ( faila == disks-2 ) {
raid6_call.gen_syndrome(disks, bytes, ptrs);
} else {
}
} else {
if ( failb == disks-2 ) {
raid6_datap_recov(disks, bytes, faila, ptrs);
} else {
raid6_2data_recov(disks, bytes, faila, failb, ptrs);
}
}
}
