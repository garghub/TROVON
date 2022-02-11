void F_1 ( void )
{
void * V_1 , * V_2 , * V_3 ;
F_2 () ;
#ifdef F_3
F_4 () ;
#endif
__asm__ __volatile__ (
" .set push \n"
" .set arch=r4000 \n"
" la %0,startpoint \n"
" la %1,endpoint \n"
" .set pop \n"
: "=r" (start), "=r" (end)
:
);
for ( V_3 = ( void * ) ( ( unsigned int ) V_1 & ~ ( V_4 - 1 ) ) ;
V_3 < V_2 ; V_3 += V_4 )
F_5 ( V_5 , V_3 ) ;
__asm__ __volatile__ (
"startpoint: \n"
);
F_6 ( F_7 ( 10 ) , 0xb , 1 << 16 ) ;
F_8 ( 125 ) ;
#if F_9 ( V_6 )
F_10 ( V_7 , 0xf000 , 0x8000 ) ;
F_11 ( V_8 , 8 ) ;
#endif
* V_9 = 0x00000001 ;
__asm__ __volatile__ (
"endpoint: \n"
);
}
void F_12 ( char * V_10 )
{
F_13 ( V_11 L_1 ) ;
#if F_9 ( V_12 ) || \
F_9 ( V_6 ) || \
F_9 ( V_13 )
F_1 () ;
#else
F_14 ( V_14 | V_15 ) ;
F_15 ( V_16 , V_17 ) ;
F_16 () ;
F_17 ( 0 ) ;
__asm__ __volatile__("jr\t%0"::"r"(0xbfc00000));
#endif
}
void F_18 ( void )
{
F_13 ( V_11 L_2 ) ;
while ( 1 )
if ( V_18 )
(* V_18)() ;
else
__asm__(".set\tmips3\n\t" "wait\n\t" ".set\tmips0");
}
void F_19 ( void )
{
F_18 () ;
}
void T_1 F_20 ( void )
{
V_19 = F_12 ;
V_20 = F_18 ;
V_21 = F_19 ;
}
void T_1 F_21 ( void )
{
unsigned long V_22 ;
unsigned long V_23 ;
V_24 = V_25 ;
V_26 = ( char * * ) V_27 ;
V_28 = ( char * * ) V_29 ;
V_22 = F_22 () ;
V_23 = F_23 () ;
switch ( V_22 ) {
case V_30 :
if ( F_24 ( V_23 ) ) {
V_31 = V_32 ;
} else {
V_31 = V_33 ;
}
break;
case V_34 :
#if F_9 ( V_35 )
V_31 = V_36 ;
#elif F_9 ( V_37 )
V_31 = V_38 ;
#else
V_31 = V_33 ;
#endif
break;
case V_39 :
V_31 = V_32 ;
break;
case V_40 :
#if F_9 ( V_12 )
V_31 = V_41 ;
#elif F_9 ( V_6 )
V_31 = V_42 ;
#else
V_31 = V_33 ;
#endif
break;
case V_43 :
V_31 = V_44 ;
break;
default:
V_31 = V_45 ;
F_25 ( L_3 ) ;
break;
}
F_26 () ;
F_27 () ;
F_28 () ;
F_29 () ;
}
