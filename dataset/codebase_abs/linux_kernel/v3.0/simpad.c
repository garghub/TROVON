long F_1 ( void )
{
return V_1 ;
}
void F_2 ( long V_2 )
{
* ( V_3 * ) ( V_4 ) = V_1 = V_2 ;
}
void F_3 ( int V_2 )
{
V_1 |= V_2 ;
* ( V_3 * ) ( V_4 ) = V_1 ;
}
void F_4 ( int V_2 )
{
V_1 &= ~ V_2 ;
* ( V_3 * ) ( V_4 ) = V_1 ;
}
static void F_5 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
if ( V_6 -> V_9 == ( T_1 ) & V_10 ) {
if ( V_7 )
{
F_4 ( V_11 ) ;
F_4 ( V_12 ) ;
} else
{
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
}
}
}
static void T_2 F_6 ( void )
{
F_7 () ;
F_8 ( V_13 , F_9 ( V_13 ) ) ;
F_3 ( V_14 | V_15 | V_16 | V_17 | V_11 |
V_18 | V_19 | V_12 ) ;
F_10 ( & V_20 ) ;
F_11 ( 0 , 3 ) ;
F_11 ( 1 , 1 ) ;
V_21 |= V_22 | V_23 ;
V_24 |= V_22 | V_25 | V_26 ;
V_24 &= ~ V_23 ;
V_27 |= V_28 ;
V_29 = V_30 | V_31 ;
V_32 = 0x818 ;
V_33 = 0 ;
V_34 = 0 ;
}
static void F_12 ( void )
{
F_13 () ;
F_2 ( 0x800 ) ;
V_33 = ( V_35 | V_36 | V_37 ) ;
V_29 = V_38 = V_39 = 1 ;
V_40 = 0 ;
V_32 = 0 ;
V_41 = V_42 ;
while( 1 ) ;
F_14 () ;
}
static int T_2 F_15 ( void )
{
int V_43 ;
V_44 = F_12 ;
F_16 ( & V_45 , V_46 ,
F_9 ( V_46 ) ) ;
F_17 ( & V_47 ) ;
V_43 = F_18 ( V_48 , F_9 ( V_48 ) ) ;
if( V_43 )
F_19 ( V_49 L_1 ) ;
return 0 ;
}
