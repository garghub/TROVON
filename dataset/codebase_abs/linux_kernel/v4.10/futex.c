static inline int F_1 ( int V_1 , T_1 T_2 * V_2 , int * V_3 )
{
int V_4 , V_5 ;
asm("0: \n"
" orcc gr0,gr0,gr0,icc3 \n"
" ckeq icc3,cc7 \n"
"1: ld.p %M0,%1 \n"
" orcr cc7,cc7,cc3 \n"
"2: cst.p %3,%M0 ,cc3,#1 \n"
" corcc gr29,gr29,gr0 ,cc3,#1 \n"
" beq icc3,#0,0b \n"
" setlos 0,%2 \n"
"3: \n"
".subsection 2 \n"
"4: setlos %5,%2 \n"
" bra 3b \n"
".previous \n"
".section __ex_table,\"a\" \n"
" .balign 8 \n"
" .long 1b,4b \n"
" .long 2b,4b \n"
".previous"
: "+U"(*uaddr), "=&r"(oldval), "=&r"(ret), "=r"(oparg)
: "3"(oparg), "i"(-EFAULT)
: "memory", "cc7", "cc3", "icc3"
);
* V_3 = V_4 ;
return V_5 ;
}
static inline int F_2 ( int V_1 , T_1 T_2 * V_2 , int * V_3 )
{
int V_4 , V_5 ;
asm("0: \n"
" orcc gr0,gr0,gr0,icc3 \n"
" ckeq icc3,cc7 \n"
"1: ld.p %M0,%1 \n"
" orcr cc7,cc7,cc3 \n"
" add %1,%3,%3 \n"
"2: cst.p %3,%M0 ,cc3,#1 \n"
" corcc gr29,gr29,gr0 ,cc3,#1 \n"
" beq icc3,#0,0b \n"
" setlos 0,%2 \n"
"3: \n"
".subsection 2 \n"
"4: setlos %5,%2 \n"
" bra 3b \n"
".previous \n"
".section __ex_table,\"a\" \n"
" .balign 8 \n"
" .long 1b,4b \n"
" .long 2b,4b \n"
".previous"
: "+U"(*uaddr), "=&r"(oldval), "=&r"(ret), "=r"(oparg)
: "3"(oparg), "i"(-EFAULT)
: "memory", "cc7", "cc3", "icc3"
);
* V_3 = V_4 ;
return V_5 ;
}
static inline int F_3 ( int V_1 , T_1 T_2 * V_2 , int * V_3 )
{
int V_4 , V_5 ;
asm("0: \n"
" orcc gr0,gr0,gr0,icc3 \n"
" ckeq icc3,cc7 \n"
"1: ld.p %M0,%1 \n"
" orcr cc7,cc7,cc3 \n"
" or %1,%3,%3 \n"
"2: cst.p %3,%M0 ,cc3,#1 \n"
" corcc gr29,gr29,gr0 ,cc3,#1 \n"
" beq icc3,#0,0b \n"
" setlos 0,%2 \n"
"3: \n"
".subsection 2 \n"
"4: setlos %5,%2 \n"
" bra 3b \n"
".previous \n"
".section __ex_table,\"a\" \n"
" .balign 8 \n"
" .long 1b,4b \n"
" .long 2b,4b \n"
".previous"
: "+U"(*uaddr), "=&r"(oldval), "=&r"(ret), "=r"(oparg)
: "3"(oparg), "i"(-EFAULT)
: "memory", "cc7", "cc3", "icc3"
);
* V_3 = V_4 ;
return V_5 ;
}
static inline int F_4 ( int V_1 , T_1 T_2 * V_2 , int * V_3 )
{
int V_4 , V_5 ;
asm("0: \n"
" orcc gr0,gr0,gr0,icc3 \n"
" ckeq icc3,cc7 \n"
"1: ld.p %M0,%1 \n"
" orcr cc7,cc7,cc3 \n"
" and %1,%3,%3 \n"
"2: cst.p %3,%M0 ,cc3,#1 \n"
" corcc gr29,gr29,gr0 ,cc3,#1 \n"
" beq icc3,#0,0b \n"
" setlos 0,%2 \n"
"3: \n"
".subsection 2 \n"
"4: setlos %5,%2 \n"
" bra 3b \n"
".previous \n"
".section __ex_table,\"a\" \n"
" .balign 8 \n"
" .long 1b,4b \n"
" .long 2b,4b \n"
".previous"
: "+U"(*uaddr), "=&r"(oldval), "=&r"(ret), "=r"(oparg)
: "3"(oparg), "i"(-EFAULT)
: "memory", "cc7", "cc3", "icc3"
);
* V_3 = V_4 ;
return V_5 ;
}
static inline int F_5 ( int V_1 , T_1 T_2 * V_2 , int * V_3 )
{
int V_4 , V_5 ;
asm("0: \n"
" orcc gr0,gr0,gr0,icc3 \n"
" ckeq icc3,cc7 \n"
"1: ld.p %M0,%1 \n"
" orcr cc7,cc7,cc3 \n"
" xor %1,%3,%3 \n"
"2: cst.p %3,%M0 ,cc3,#1 \n"
" corcc gr29,gr29,gr0 ,cc3,#1 \n"
" beq icc3,#0,0b \n"
" setlos 0,%2 \n"
"3: \n"
".subsection 2 \n"
"4: setlos %5,%2 \n"
" bra 3b \n"
".previous \n"
".section __ex_table,\"a\" \n"
" .balign 8 \n"
" .long 1b,4b \n"
" .long 2b,4b \n"
".previous"
: "+U"(*uaddr), "=&r"(oldval), "=&r"(ret), "=r"(oparg)
: "3"(oparg), "i"(-EFAULT)
: "memory", "cc7", "cc3", "icc3"
);
* V_3 = V_4 ;
return V_5 ;
}
int F_6 ( int V_6 , T_1 T_2 * V_2 )
{
int V_7 = ( V_6 >> 28 ) & 7 ;
int V_8 = ( V_6 >> 24 ) & 15 ;
int V_1 = ( V_6 << 8 ) >> 20 ;
int V_9 = ( V_6 << 20 ) >> 20 ;
int V_4 = 0 , V_5 ;
if ( V_6 & ( V_10 << 28 ) )
V_1 = 1 << V_1 ;
if ( ! F_7 ( V_11 , V_2 , sizeof( T_1 ) ) )
return - V_12 ;
F_8 () ;
switch ( V_7 ) {
case V_13 :
V_5 = F_1 ( V_1 , V_2 , & V_4 ) ;
break;
case V_14 :
V_5 = F_2 ( V_1 , V_2 , & V_4 ) ;
break;
case V_15 :
V_5 = F_3 ( V_1 , V_2 , & V_4 ) ;
break;
case V_16 :
V_5 = F_4 ( ~ V_1 , V_2 , & V_4 ) ;
break;
case V_17 :
V_5 = F_5 ( V_1 , V_2 , & V_4 ) ;
break;
default:
V_5 = - V_18 ;
break;
}
F_9 () ;
if ( ! V_5 ) {
switch ( V_8 ) {
case V_19 : V_5 = ( V_4 == V_9 ) ; break;
case V_20 : V_5 = ( V_4 != V_9 ) ; break;
case V_21 : V_5 = ( V_4 < V_9 ) ; break;
case V_22 : V_5 = ( V_4 >= V_9 ) ; break;
case V_23 : V_5 = ( V_4 <= V_9 ) ; break;
case V_24 : V_5 = ( V_4 > V_9 ) ; break;
default: V_5 = - V_18 ; break;
}
}
return V_5 ;
}
