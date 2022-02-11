static void T_1
F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 T_2 * V_4 ;
V_2 = F_2 ( NULL , V_5 ) ;
V_4 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_4 ) {
F_5 ( V_6 L_1 ,
V_7 ) ;
return;
}
F_6 ( & V_4 -> V_8 , 0x00 ) ;
F_6 ( & V_4 -> V_9 , 0x01 ) ;
if ( F_7 ( & V_4 -> V_10 ) & 0x40 )
F_8 ( & V_4 -> V_11 , 0x0001 ) ;
else
F_8 ( & V_4 -> V_11 , 0x5555 ) ;
F_9 ( V_4 ) ;
}
static void T_1
F_10 ( void )
{
struct V_1 * V_2 ;
struct V_12 T_2 * V_13 ;
T_3 V_14 ;
V_2 = F_2 ( NULL , V_15 ) ;
V_13 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_13 ) {
F_5 ( V_6 L_2 ,
V_7 ) ;
return;
}
V_14 = F_7 ( & V_13 -> V_14 ) ;
V_14 &= ~ 0x00800000 ;
V_14 &= ~ 0x00007000 ;
V_14 |= 0x00001000 ;
V_14 &= ~ 0x03000000 ;
V_14 |= 0x01000000 ;
F_11 ( L_3 ,
F_7 ( & V_13 -> V_14 ) , V_14 ) ;
F_12 ( & V_13 -> V_14 , V_14 ) ;
F_9 ( V_13 ) ;
}
static void F_13 ( void T_2 * V_16 )
{
T_4 V_17 = 1 ;
T_4 V_18 = 0 ;
F_14 ( V_17 , V_18 ) ;
F_12 ( V_16 + 0x1048 , F_7 ( V_16 + 0x1048 ) & ~ 0x300 ) ;
F_12 ( V_16 + 0x1050 , 0x00000001 ) ;
}
static void F_15 ( void T_2 * V_16 )
{
F_12 ( V_16 + 0x1050 , 0x00010000 ) ;
}
static void T_1 F_16 ( void )
{
if ( V_19 . V_20 )
V_19 . V_20 ( L_4 , 0 ) ;
F_17 () ;
F_18 () ;
F_1 () ;
F_10 () ;
#ifdef F_19
V_21 . V_22 = F_13 ;
V_21 . V_23 = F_15 ;
F_20 () ;
#endif
F_21 () ;
}
static int T_1 F_22 ( void )
{
return F_23 ( F_24 () , V_24 ) ;
}
