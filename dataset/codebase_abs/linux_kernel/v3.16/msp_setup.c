void F_1 ( void )
{
void * V_1 , * V_2 , * V_3 ;
register int V_4 ;
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
for ( V_3 = ( void * ) ( ( unsigned int ) V_1 & ~ ( V_5 - 1 ) ) ;
V_3 < V_2 ; V_3 += V_5 )
F_5 ( V_6 , V_3 ) ;
__asm__ __volatile__ (
"startpoint: \n"
);
F_6 ( F_7 ( 10 ) , 0xb , 1 << 16 ) ;
for ( V_4 = 0 ; V_4 < 100000000 ; V_4 ++ ) ;
#if F_8 ( V_7 )
F_9 ( V_8 , 0xf000 , 0x8000 ) ;
F_10 ( V_9 , 8 ) ;
#endif
* V_10 = 0x00000001 ;
__asm__ __volatile__ (
"endpoint: \n"
);
}
void F_11 ( char * V_11 )
{
F_12 ( V_12 L_1 ) ;
#if F_8 ( V_13 ) || \
F_8 ( V_7 ) || \
F_8 ( V_14 )
F_1 () ;
#else
F_13 ( V_15 | V_16 ) ;
F_14 ( V_17 , V_18 ) ;
F_15 () ;
F_16 ( 0 ) ;
__asm__ __volatile__("jr\t%0"::"r"(0xbfc00000));
#endif
}
void F_17 ( void )
{
F_12 ( V_12 L_2 ) ;
while ( 1 )
if ( V_19 )
(* V_19)() ;
else
__asm__(".set\tmips3\n\t" "wait\n\t" ".set\tmips0");
}
void F_18 ( void )
{
F_17 () ;
}
void T_1 F_19 ( void )
{
V_20 = F_11 ;
V_21 = F_17 ;
V_22 = F_18 ;
}
void T_1 F_20 ( void )
{
unsigned long V_23 ;
unsigned long V_24 ;
V_25 = V_26 ;
V_27 = ( char * * ) V_28 ;
V_29 = ( char * * ) V_30 ;
V_23 = F_21 () ;
V_24 = F_22 () ;
switch ( V_23 ) {
case V_31 :
if ( F_23 ( V_24 ) ) {
V_32 = V_33 ;
} else {
V_32 = V_34 ;
}
break;
case V_35 :
#if F_8 ( V_36 )
V_32 = V_37 ;
#elif F_8 ( V_38 )
V_32 = V_39 ;
#else
V_32 = V_34 ;
#endif
break;
case V_40 :
V_32 = V_33 ;
break;
case V_41 :
#if F_8 ( V_13 )
V_32 = V_42 ;
#elif F_8 ( V_7 )
V_32 = V_43 ;
#else
V_32 = V_34 ;
#endif
break;
case V_44 :
V_32 = V_45 ;
break;
default:
V_32 = V_46 ;
F_24 ( L_3 ) ;
break;
}
F_25 () ;
F_26 () ;
F_27 () ;
F_28 () ;
}
