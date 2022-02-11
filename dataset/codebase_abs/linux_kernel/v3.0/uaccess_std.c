T_1 F_1 ( T_1 V_1 , const void T_2 * V_2 , void * V_3 )
{
unsigned long V_4 , V_5 ;
V_4 = - 256UL ;
asm volatile(
"0: mvcp 0(%0,%2),0(%1),%3\n"
"10:jz 8f\n"
"1:"ALR" %0,%3\n"
" la %1,256(%1)\n"
" la %2,256(%2)\n"
"2: mvcp 0(%0,%2),0(%1),%3\n"
"11:jnz 1b\n"
" j 8f\n"
"3: la %4,255(%1)\n"
" "LHI" %3,-4096\n"
" nr %4,%3\n"
" "SLR" %4,%1\n"
" "CLR" %0,%4\n"
" jnh 5f\n"
"4: mvcp 0(%4,%2),0(%1),%3\n"
"12:"SLR" %0,%4\n"
" "ALR" %2,%4\n"
"5:"LHI" %4,-1\n"
" "ALR" %4,%0\n"
" bras %3,7f\n"
" xc 0(1,%2),0(%2)\n"
"6: xc 0(256,%2),0(%2)\n"
" la %2,256(%2)\n"
"7:"AHI" %4,-256\n"
" jnm 6b\n"
" ex %4,0(%3)\n"
" j 9f\n"
"8:"SLR" %0,%0\n"
"9: \n"
EX_TABLE(0b,3b) EX_TABLE(2b,3b) EX_TABLE(4b,5b)
EX_TABLE(10b,3b) EX_TABLE(11b,3b) EX_TABLE(12b,5b)
: "+a" (size), "+a" (ptr), "+a" (x), "+a" (tmp1), "=a" (tmp2)
: : "cc", "memory");
return V_1 ;
}
static T_1 F_2 ( T_1 V_1 , const void T_2 * V_2 ,
void * V_3 )
{
if ( V_1 <= 1024 )
return F_1 ( V_1 , V_2 , V_3 ) ;
return F_3 ( V_1 , V_2 , V_3 ) ;
}
T_1 F_4 ( T_1 V_1 , void T_2 * V_2 , const void * V_3 )
{
unsigned long V_4 , V_5 ;
V_4 = - 256UL ;
asm volatile(
"0: mvcs 0(%0,%1),0(%2),%3\n"
"7: jz 5f\n"
"1:"ALR" %0,%3\n"
" la %1,256(%1)\n"
" la %2,256(%2)\n"
"2: mvcs 0(%0,%1),0(%2),%3\n"
"8: jnz 1b\n"
" j 5f\n"
"3: la %4,255(%1)\n"
" "LHI" %3,-4096\n"
" nr %4,%3\n"
" "SLR" %4,%1\n"
" "CLR" %0,%4\n"
" jnh 6f\n"
"4: mvcs 0(%4,%1),0(%2),%3\n"
"9:"SLR" %0,%4\n"
" j 6f\n"
"5:"SLR" %0,%0\n"
"6: \n"
EX_TABLE(0b,3b) EX_TABLE(2b,3b) EX_TABLE(4b,6b)
EX_TABLE(7b,3b) EX_TABLE(8b,3b) EX_TABLE(9b,6b)
: "+a" (size), "+a" (ptr), "+a" (x), "+a" (tmp1), "=a" (tmp2)
: : "cc", "memory");
return V_1 ;
}
static T_1 F_5 ( T_1 V_1 , void T_2 * V_2 ,
const void * V_3 )
{
if ( V_1 <= 1024 )
return F_4 ( V_1 , V_2 , V_3 ) ;
return F_6 ( V_1 , V_2 , V_3 ) ;
}
static T_1 F_7 ( T_1 V_1 , void T_2 * V_6 ,
const void T_2 * V_7 )
{
unsigned long V_4 ;
asm volatile(
" sacf 256\n"
" "AHI" %0,-1\n"
" jo 5f\n"
" bras %3,3f\n"
"0:"AHI" %0,257\n"
"1: mvc 0(1,%1),0(%2)\n"
" la %1,1(%1)\n"
" la %2,1(%2)\n"
" "AHI" %0,-1\n"
" jnz 1b\n"
" j 5f\n"
"2: mvc 0(256,%1),0(%2)\n"
" la %1,256(%1)\n"
" la %2,256(%2)\n"
"3:"AHI" %0,-256\n"
" jnm 2b\n"
"4: ex %0,1b-0b(%3)\n"
"5: "SLR" %0,%0\n"
"6: sacf 0\n"
EX_TABLE(1b,6b) EX_TABLE(2b,0b) EX_TABLE(4b,0b)
: "+a" (size), "+a" (to), "+a" (from), "=a" (tmp1)
: : "cc", "memory");
return V_1 ;
}
static T_1 F_8 ( T_1 V_1 , void T_2 * V_6 )
{
unsigned long V_4 , V_5 ;
asm volatile(
" sacf 256\n"
" "AHI" %0,-1\n"
" jo 5f\n"
" bras %3,3f\n"
" xc 0(1,%1),0(%1)\n"
"0:"AHI" %0,257\n"
" la %2,255(%1)\n"
" srl %2,12\n"
" sll %2,12\n"
" "SLR" %2,%1\n"
" "CLR" %0,%2\n"
" jnh 5f\n"
" "AHI" %2,-1\n"
"1: ex %2,0(%3)\n"
" "AHI" %2,1\n"
" "SLR" %0,%2\n"
" j 5f\n"
"2: xc 0(256,%1),0(%1)\n"
" la %1,256(%1)\n"
"3:"AHI" %0,-256\n"
" jnm 2b\n"
"4: ex %0,0(%3)\n"
"5: "SLR" %0,%0\n"
"6: sacf 0\n"
EX_TABLE(1b,6b) EX_TABLE(2b,0b) EX_TABLE(4b,0b)
: "+a" (size), "+a" (to), "=a" (tmp1), "=a" (tmp2)
: : "cc", "memory");
return V_1 ;
}
T_1 F_9 ( T_1 V_1 , const char T_2 * V_8 )
{
register unsigned long T_3 V_9 ( L_1 ) = 0UL ;
unsigned long V_4 , V_5 ;
asm volatile(
" la %2,0(%1)\n"
" la %3,0(%0,%1)\n"
" "SLR" %0,%0\n"
" sacf 256\n"
"0: srst %3,%2\n"
" jo 0b\n"
" la %0,1(%3)\n"
" "SLR" %0,%1\n"
"1: sacf 0\n"
EX_TABLE(0b,1b)
: "+a" (size), "+a" (src), "=a" (tmp1), "=a" (tmp2)
: "d" (reg0) : "cc", "memory");
return V_1 ;
}
T_1 F_10 ( T_1 V_1 , const char T_2 * V_8 , char * V_10 )
{
register unsigned long T_3 V_9 ( L_1 ) = 0UL ;
unsigned long V_4 , V_5 ;
asm volatile(
" la %3,0(%1)\n"
" la %4,0(%0,%1)\n"
" sacf 256\n"
"0: srst %4,%3\n"
" jo 0b\n"
" sacf 0\n"
" la %0,0(%4)\n"
" jh 1f\n"
" "AHI" %4,1\n"
"1:"SLR" %0,%1\n"
" "SLR" %4,%1\n"
"2: mvcp 0(%4,%2),0(%1),%5\n"
" jz 9f\n"
"3:"AHI" %4,-256\n"
" la %1,256(%1)\n"
" la %2,256(%2)\n"
"4: mvcp 0(%4,%2),0(%1),%5\n"
" jnz 3b\n"
" j 9f\n"
"7: sacf 0\n"
"8:"LHI" %0,%6\n"
"9:\n"
EX_TABLE(0b,7b) EX_TABLE(2b,8b) EX_TABLE(4b,8b)
: "+a" (size), "+a" (src), "+d" (dst), "=a" (tmp1), "=a" (tmp2)
: "d" (reg0), "K" (-EFAULT) : "cc", "memory");
return V_1 ;
}
int F_11 ( int V_11 , T_4 T_2 * V_12 , int V_13 , int * V_14 )
{
int V_15 = 0 , V_16 , V_17 ;
switch ( V_11 ) {
case V_18 :
F_12 ( L_2 ,
V_17 , V_15 , V_16 , V_12 , V_13 ) ;
break;
case V_19 :
F_12 ( L_3 ,
V_17 , V_15 , V_16 , V_12 , V_13 ) ;
break;
case V_20 :
F_12 ( L_4 ,
V_17 , V_15 , V_16 , V_12 , V_13 ) ;
break;
case V_21 :
F_12 ( L_5 ,
V_17 , V_15 , V_16 , V_12 , V_13 ) ;
break;
case V_22 :
F_12 ( L_6 ,
V_17 , V_15 , V_16 , V_12 , V_13 ) ;
break;
default:
V_17 = - V_23 ;
}
* V_14 = V_15 ;
return V_17 ;
}
int F_13 ( T_4 * V_24 , T_4 T_2 * V_12 ,
T_4 V_15 , T_4 V_16 )
{
int V_17 ;
asm volatile(
" sacf 256\n"
"0: cs %1,%4,0(%5)\n"
"1: la %0,0\n"
"2: sacf 0\n"
EX_TABLE(0b,2b) EX_TABLE(1b,2b)
: "=d" (ret), "+d" (oldval), "=m" (*uaddr)
: "0" (-EFAULT), "d" (newval), "a" (uaddr), "m" (*uaddr)
: "cc", "memory" );
* V_24 = V_15 ;
return V_17 ;
}
