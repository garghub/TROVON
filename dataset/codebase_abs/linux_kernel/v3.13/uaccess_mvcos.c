static T_1 F_1 ( T_1 V_1 , const void T_2 * V_2 , void * V_3 )
{
register unsigned long T_3 V_4 ( L_1 ) = 0x81UL ;
unsigned long V_5 , V_6 ;
V_5 = - 4096UL ;
asm volatile(
"0: .insn ss,0xc80000000000,0(%0,%2),0(%1),0\n"
"9: jz 7f\n"
"1:"ALR" %0,%3\n"
" "SLR" %1,%3\n"
" "SLR" %2,%3\n"
" j 0b\n"
"2: la %4,4095(%1)\n"
" nr %4,%3\n"
" "SLR" %4,%1\n"
" "CLR" %0,%4\n"
" jnh 4f\n"
"3: .insn ss,0xc80000000000,0(%4,%2),0(%1),0\n"
"10:"SLR" %0,%4\n"
" "ALR" %2,%4\n"
"4:"LHI" %4,-1\n"
" "ALR" %4,%0\n"
" bras %3,6f\n"
" xc 0(1,%2),0(%2)\n"
"5: xc 0(256,%2),0(%2)\n"
" la %2,256(%2)\n"
"6:"AHI" %4,-256\n"
" jnm 5b\n"
" ex %4,0(%3)\n"
" j 8f\n"
"7:"SLR" %0,%0\n"
"8: \n"
EX_TABLE(0b,2b) EX_TABLE(3b,4b) EX_TABLE(9b,2b) EX_TABLE(10b,4b)
: "+a" (size), "+a" (ptr), "+a" (x), "+a" (tmp1), "=a" (tmp2)
: "d" (reg0) : "cc", "memory");
return V_1 ;
}
static T_1 F_2 ( T_1 V_1 , void T_2 * V_2 , const void * V_3 )
{
register unsigned long T_3 V_4 ( L_1 ) = 0x810000UL ;
unsigned long V_5 , V_6 ;
V_5 = - 4096UL ;
asm volatile(
"0: .insn ss,0xc80000000000,0(%0,%1),0(%2),0\n"
"6: jz 4f\n"
"1:"ALR" %0,%3\n"
" "SLR" %1,%3\n"
" "SLR" %2,%3\n"
" j 0b\n"
"2: la %4,4095(%1)\n"
" nr %4,%3\n"
" "SLR" %4,%1\n"
" "CLR" %0,%4\n"
" jnh 5f\n"
"3: .insn ss,0xc80000000000,0(%4,%1),0(%2),0\n"
"7:"SLR" %0,%4\n"
" j 5f\n"
"4:"SLR" %0,%0\n"
"5: \n"
EX_TABLE(0b,2b) EX_TABLE(3b,5b) EX_TABLE(6b,2b) EX_TABLE(7b,5b)
: "+a" (size), "+a" (ptr), "+a" (x), "+a" (tmp1), "=a" (tmp2)
: "d" (reg0) : "cc", "memory");
return V_1 ;
}
static T_1 F_3 ( T_1 V_1 , void T_2 * V_7 ,
const void T_2 * V_8 )
{
register unsigned long T_3 V_4 ( L_1 ) = 0x810081UL ;
unsigned long V_5 , V_6 ;
V_5 = - 4096UL ;
asm volatile(
"0: .insn ss,0xc80000000000,0(%0,%1),0(%2),0\n"
" jz 2f\n"
"1:"ALR" %0,%3\n"
" "SLR" %1,%3\n"
" "SLR" %2,%3\n"
" j 0b\n"
"2:"SLR" %0,%0\n"
"3: \n"
EX_TABLE(0b,3b)
: "+a" (size), "+a" (to), "+a" (from), "+a" (tmp1), "=a" (tmp2)
: "d" (reg0) : "cc", "memory");
return V_1 ;
}
static T_1 F_4 ( T_1 V_1 , void T_2 * V_7 )
{
register unsigned long T_3 V_4 ( L_1 ) = 0x810000UL ;
unsigned long V_5 , V_6 ;
V_5 = - 4096UL ;
asm volatile(
"0: .insn ss,0xc80000000000,0(%0,%1),0(%4),0\n"
" jz 4f\n"
"1:"ALR" %0,%2\n"
" "SLR" %1,%2\n"
" j 0b\n"
"2: la %3,4095(%1)\n"
" nr %3,%2\n"
" "SLR" %3,%1\n"
" "CLR" %0,%3\n"
" jnh 5f\n"
"3: .insn ss,0xc80000000000,0(%3,%1),0(%4),0\n"
" "SLR" %0,%3\n"
" j 5f\n"
"4:"SLR" %0,%0\n"
"5: \n"
EX_TABLE(0b,2b) EX_TABLE(3b,5b)
: "+a" (size), "+a" (to), "+a" (tmp1), "=a" (tmp2)
: "a" (empty_zero_page), "d" (reg0) : "cc", "memory");
return V_1 ;
}
static T_1 F_5 ( T_1 V_9 , const char T_2 * V_10 )
{
T_1 V_11 , V_12 , V_13 , V_14 ;
char V_15 [ 256 ] ;
V_11 = 0 ;
do {
V_13 = ( T_1 ) V_10 & ~ V_16 ;
V_12 = F_6 ( 256UL , V_17 - V_13 ) ;
V_12 = F_6 ( V_9 - V_11 , V_12 ) ;
if ( F_1 ( V_12 , V_10 , V_15 ) )
return 0 ;
V_14 = F_7 ( V_15 , V_12 ) ;
V_11 += V_14 ;
V_10 += V_14 ;
} while ( ( V_14 == V_12 ) && ( V_11 < V_9 ) );
return V_11 + 1 ;
}
static T_1 F_8 ( T_1 V_9 , const char T_2 * V_10 ,
char * V_18 )
{
T_1 V_11 , V_12 , V_13 , V_14 ;
if ( F_9 ( ! V_9 ) )
return 0 ;
V_11 = 0 ;
do {
V_13 = ( T_1 ) V_10 & ~ V_16 ;
V_12 = F_6 ( V_9 - V_11 , V_17 - V_13 ) ;
if ( F_1 ( V_12 , V_10 , V_18 ) )
return - V_19 ;
V_14 = F_7 ( V_18 , V_12 ) ;
V_11 += V_14 ;
V_10 += V_14 ;
V_18 += V_14 ;
} while ( ( V_14 == V_12 ) && ( V_11 < V_9 ) );
return V_11 ;
}
