void T_1 F_1 ( void )
{
void T_2 * V_1 ;
V_2 = F_2 ( V_3 , V_4 ) ;
F_3 ( ! V_2 ) ;
V_1 = F_2 ( V_5 , V_6 ) ;
F_3 ( ! V_1 ) ;
F_4 ( 0 , 29 , V_2 , V_1 ) ;
}
static void F_5 ( void )
{
F_6 ( 0x102 , 0x0 ) ;
}
static void F_7 ( unsigned long V_7 )
{
F_6 ( 0x100 , V_7 ) ;
}
static int T_1 F_8 ( void )
{
T_3 V_8 = 0 ;
if ( ! F_9 () )
return - V_9 ;
V_10 = F_2 ( V_11 , V_4 ) ;
F_3 ( ! V_10 ) ;
V_8 = ( ( 1 << V_12 ) |
( 0x1 << 25 ) |
( 0x1 << V_13 ) |
( 0x1 << V_14 ) ) ;
if ( F_10 () == V_15 ) {
V_8 |= 0x2 << V_16 ;
} else {
V_8 |= ( ( 0x3 << V_16 ) |
( 1 << V_17 ) |
( 1 << V_18 ) |
( 1 << V_19 ) |
( 1 << V_20 ) ) ;
}
if ( F_10 () != V_15 )
F_6 ( 0x109 , V_8 ) ;
F_6 ( 0x102 , 0x1 ) ;
F_11 ( V_10 , V_8 , V_21 ) ;
V_22 . V_23 = F_5 ;
V_22 . V_24 = F_7 ;
return 0 ;
}
