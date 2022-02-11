static int F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x00C3 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_1 F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_3 ;
struct V_4 * V_5 ;
#ifdef F_7
T_2 V_6 ;
V_3 = F_8 ( L_1 ) ;
if ( V_3 == - V_7 )
return 0 ;
if ( V_3 ) {
V_6 = F_9 () ;
if ( ( ( V_6 >> 16 ) != 0x4474 ) || ( ( V_6 & 0xffff ) == 0x8960 ) )
return 0 ;
}
#endif
V_3 = F_10 ( & V_8 ) ;
if ( ! V_3 ) {
V_5 = & V_9 . V_10 ;
V_5 -> V_11 = 800 ;
V_5 -> V_12 = 480 ;
V_5 -> type = V_13 ;
V_5 -> V_14 = V_15 ;
V_5 -> V_16 . V_17 = V_18 ;
V_5 -> V_19 = 0 ;
V_5 -> V_20 = 18 ;
V_5 -> V_21 = 2 ;
V_5 -> V_22 = 153600000 ;
V_5 -> V_23 = 150000000 ;
V_5 -> V_24 = 160000000 ;
V_5 -> V_25 . V_26 = TRUE ;
V_5 -> V_25 . V_27 = 6050 ;
V_5 -> V_25 . V_28 = 23 ;
V_5 -> V_25 . V_29 = 20 ;
V_5 -> V_25 . V_30 = 105 ;
V_5 -> V_25 . V_31 = TRUE ;
V_5 -> V_25 . V_32 = 0 ;
V_3 = F_11 ( & V_33 ) ;
if ( V_3 )
F_12 ( & V_8 ) ;
}
return V_3 ;
}
