T_1 void F_1 ( void )
{
unsigned long V_1 ;
int type = 0 ;
static T_2 V_2 = 0 ;
if ( ! V_2 ) {
F_2 () ;
type = - 1 ;
V_2 = 1 ;
}
V_1 = F_3 ( 0 ) ;
if ( V_1 & V_3 )
F_4 ( 0 , V_1 & ~ V_3 ) ;
V_4 . V_5 &= ~ V_6 ;
if ( V_7 -> V_8 == ( unsigned long ) V_9 ) {
* V_7 = * V_10 ;
V_10 = V_7 -> V_11 ;
V_4 . V_12 = ( V_7 -> V_13 & V_14 ) << 12 ;
V_4 . V_12 |= V_15 ;
}
if ( V_7 -> V_8 == ( unsigned long ) V_16 + 4 ) {
V_7 -> V_8 = V_7 -> V_17 ;
type = V_7 -> V_18 ;
}
#ifdef F_5
F_6 ( type ) ;
#endif
if ( V_1 & V_3 )
F_4 ( 0 , F_3 ( 0 ) | V_3 ) ;
}
static void T_3 F_2 ( void )
{
F_7 ( 6 , 0xff000000 ) ;
F_8 ( 1 , 0x20000000 ) ;
asm volatile(" movgs gr0,ibar0 \n"
" movgs gr0,ibar1 \n"
" movgs gr0,ibar2 \n"
" movgs gr0,ibar3 \n"
" movgs gr0,dbar0 \n"
" movgs gr0,dbmr00 \n"
" movgs gr0,dbmr01 \n"
" movgs gr0,dbdr00 \n"
" movgs gr0,dbdr01 \n"
" movgs gr0,dbar1 \n"
" movgs gr0,dbmr10 \n"
" movgs gr0,dbmr11 \n"
" movgs gr0,dbdr10 \n"
" movgs gr0,dbdr11 \n"
);
if ( V_7 -> V_8 == ( unsigned long ) V_19 )
V_7 -> V_8 = ( unsigned long ) V_20 ;
V_4 . V_5 = V_21 ;
#ifdef F_5
F_9 () ;
#endif
F_10 () ;
F_11 ( 15 ) ;
F_12 ( 15 ) ;
}
void F_13 ( int V_22 )
{
#ifdef F_5
F_14 ( V_22 ) ;
#endif
}
void F_15 ( const char * V_23 , int V_24 )
{
char V_25 ;
for (; V_24 > 0 ; V_24 -- ) {
V_25 = * V_23 ++ ;
F_16 ( V_26 ) ;
F_17 ( V_27 ) ;
if ( V_25 == 0x0a ) {
F_18 ( V_28 ) = 0x0d ;
F_19 () ;
F_17 ( V_27 ) ;
}
F_18 ( V_28 ) = V_25 ;
F_19 () ;
F_20 ( V_26 ) ;
}
}
void F_21 ( const char * V_29 , ... )
{
T_4 V_30 ;
char V_31 [ 64 ] ;
int V_24 ;
va_start ( V_30 , V_29 ) ;
V_24 = vsprintf ( V_31 , V_29 , V_30 ) ;
va_end ( V_30 ) ;
F_15 ( V_31 , V_24 ) ;
}
void T_3 F_22 ( unsigned V_32 )
{
unsigned V_33 , V_34 , V_35 ;
T_2 V_36 ;
V_33 = V_37 / 16 / V_32 ;
V_34 = V_37 / 16 / V_33 ;
V_35 = V_37 / 16 / ( V_33 + 1 ) ;
if ( V_35 + ( V_34 - V_35 ) / 2 > V_32 )
V_33 ++ ;
V_36 = F_18 ( V_38 ) ;
F_18 ( V_38 ) |= V_39 ;
F_19 () ;
F_18 ( V_40 ) = V_33 & 0xff ;
F_18 ( V_41 ) = ( V_33 >> 8 ) & 0xff ;
F_19 () ;
F_18 ( V_38 ) = V_36 ;
F_19 () ;
}
int T_3 F_23 ( void )
{
unsigned V_33 ;
T_2 V_36 ;
V_36 = F_18 ( V_38 ) ;
F_18 ( V_38 ) |= V_39 ;
F_19 () ;
V_33 = F_18 ( V_41 ) << 8 ;
V_33 |= F_18 ( V_40 ) ;
F_18 ( V_38 ) = V_36 ;
F_19 () ;
return V_33 ;
}
void F_24 ( const char * V_42 , unsigned line )
{
F_25 ( L_1 , V_42 , line ) ;
}
