static void T_1 F_1 ( void )
{
V_1 [ 0 ] . V_2 = ( F_2 () > V_3 ) ?
V_4 :
V_5 ;
if ( F_3 ( V_1 , F_4 ( V_1 ) ) )
F_5 ( L_1 , V_6 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
return 0 ;
}
static void F_7 ( struct V_7 * V_8 )
{
}
static int F_8 ( struct V_7 * V_8 , int V_9 )
{
#ifdef F_9
unsigned char V_10 ;
T_2 V_11 , V_12 ;
if ( V_9 > 100 )
return - 1 ;
F_10 ( V_13 , & V_11 , V_14 ) ;
F_10 ( V_13 , & V_12 , V_15 ) ;
if ( V_9 == 0 ) {
V_12 = V_12 & 0xF5 ;
V_11 = V_11 & 0xCF ;
F_11 ( V_13 ,
V_12 , V_15 ) ;
F_11 ( V_13 ,
V_11 , V_14 ) ;
return 0 ;
}
if ( ! ( ( V_12 & 0xA ) && ( V_11 & 0x30 ) ) ) {
V_11 = V_11 | 0x30 ;
V_12 = V_12 | 0x0A ;
F_11 ( V_13 ,
V_11 , V_14 ) ;
F_11 ( V_13 ,
V_12 , V_15 ) ;
}
V_10 = ( ( 50 * ( 100 - V_9 ) ) / 100 ) + 1 ;
F_11 ( V_16 , 0x7F , V_17 ) ;
F_11 ( V_16 , V_10 , V_18 ) ;
#else
F_12 ( L_2 ) ;
#endif
return 0 ;
}
void T_1 F_13 ( void )
{
F_14 ( & V_19 ) ;
F_15 ( V_20 ,
F_4 ( V_20 ) ) ;
F_1 () ;
}
