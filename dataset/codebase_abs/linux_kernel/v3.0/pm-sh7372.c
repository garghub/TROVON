static void F_1 ( void )
{
void T_1 * V_1 = ( void T_1 * ) V_2 ;
F_2 ( 0 , V_3 ) ;
F_2 ( F_3 ( V_4 ) , V_5 ) ;
F_2 ( 0x10 , V_6 ) ;
F_2 ( 0 , V_1 + 0x3c ) ;
F_4 () ;
F_5 () ;
if ( F_6 ( V_1 + 0x3c ) ) {
F_2 ( F_6 ( V_1 + 0x40 ) ,
F_7 ( F_6 ( V_1 + 0x3c ) ) ) ;
F_8 () ;
F_9 ( F_6 ( V_1 + 0x38 ) ) ;
}
F_2 ( 0 , V_6 ) ;
F_2 ( 0 , V_5 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 = V_8 -> V_12 ;
V_10 = & V_8 -> V_13 [ V_11 ] ;
snprintf ( V_10 -> V_14 , V_15 , L_1 ) ;
strncpy ( V_10 -> V_16 , L_2 , V_17 ) ;
V_10 -> V_18 = 10 ;
V_10 -> V_19 = 20 + 10 ;
V_10 -> V_20 = 1 ;
V_10 -> V_21 = 0 ;
V_10 -> V_21 |= V_22 ;
V_23 [ V_11 ] = F_1 ;
V_8 -> V_12 = V_11 + 1 ;
}
static void F_11 ( void )
{
V_24 = F_10 ;
}
static void F_11 ( void ) {}
static int F_12 ( T_2 V_25 )
{
F_1 () ;
return 0 ;
}
static void F_13 ( void )
{
V_26 . V_27 = F_12 ;
}
static void F_13 ( void ) {}
void T_3 F_14 ( void )
{
F_2 ( 0x0000a500 , V_28 ) ;
F_2 ( 0x0000a501 , V_28 ) ;
F_2 ( 0x00000000 , V_29 ) ;
F_13 () ;
F_11 () ;
}
