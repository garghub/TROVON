long F_1 ( void )
{
return F_2 ( V_1 ) ;
}
long F_3 ( void )
{
return V_2 ;
}
static void F_4 ( void )
{
F_5 ( V_2 , V_1 ) ;
}
void F_6 ( int V_3 )
{
unsigned long V_4 ;
F_7 ( & V_5 , V_4 ) ;
V_2 |= V_3 ;
F_4 () ;
F_8 ( & V_5 , V_4 ) ;
}
void F_9 ( int V_3 )
{
unsigned long V_4 ;
F_7 ( & V_5 , V_4 ) ;
V_2 &= ~ V_3 ;
F_4 () ;
F_8 ( & V_5 , V_4 ) ;
}
static void F_10 ( struct V_6 * V_7 , unsigned V_8 , int V_3 )
{
if ( V_8 > 15 )
return;
if ( V_3 )
F_6 ( 1 << V_8 ) ;
else
F_9 ( 1 << V_8 ) ;
}
static int F_11 ( struct V_6 * V_7 , unsigned V_8 )
{
if ( V_8 > 15 )
return ! ! ( F_1 () & ( 1 << ( V_8 - 16 ) ) ) ;
return ! ! ( F_3 () & ( 1 << V_8 ) ) ;
}
static int F_12 ( struct V_6 * V_7 , unsigned V_8 )
{
if ( V_8 > 15 )
return 0 ;
return - V_9 ;
}
static int F_13 ( struct V_6 * V_7 , unsigned V_8 ,
int V_3 )
{
if ( V_8 > 15 )
return - V_9 ;
F_10 ( V_7 , V_8 , V_3 ) ;
return 0 ;
}
static void F_14 ( struct V_10 * V_11 , T_1 V_12 , T_1 V_13 )
{
if ( V_11 -> V_14 == ( T_1 ) & V_15 ) {
if ( V_12 )
{
F_9 ( V_16 ) ;
F_9 ( V_17 ) ;
} else
{
F_6 ( V_16 ) ;
F_6 ( V_17 ) ;
}
}
}
static void T_2 F_15 ( void )
{
F_16 () ;
F_17 ( V_18 , F_18 ( V_18 ) ) ;
V_2 = ( V_19 | V_20 | V_21 | V_22 |
V_16 | V_23 | V_24 | V_17 ) ;
F_4 () ;
F_19 ( & V_25 ) ;
F_20 ( 0 , 3 ) ;
F_20 ( 1 , 1 ) ;
V_26 |= V_27 | V_28 ;
V_29 |= V_27 | V_30 | V_31 ;
V_29 &= ~ V_28 ;
V_32 |= V_33 ;
V_34 = V_35 | V_36 ;
V_37 = 0x818 ;
V_38 = 0 ;
V_39 = 0 ;
}
static void F_21 ( void )
{
F_22 () ;
V_2 = V_40 ;
F_4 () ;
V_38 = ( V_41 | V_42 | V_43 ) ;
V_34 = V_44 = V_45 = V_35 ;
V_46 = 0 ;
V_37 = 0 ;
V_47 = V_48 ;
while( 1 ) ;
F_23 () ;
}
static int T_2 F_24 ( void )
{
int V_49 ;
F_25 ( & V_5 ) ;
V_50 . V_51 = L_1 ;
V_50 . V_52 = V_53 ;
V_50 . V_54 = 24 ;
V_50 . V_55 = F_10 ;
V_50 . V_56 = F_11 ;
V_50 . V_57 = F_12 ;
V_50 . V_58 = F_13 ;
V_49 = F_26 ( & V_50 ) ;
if ( V_49 )
F_27 ( V_59 L_2 ) ;
V_60 = F_21 ;
F_28 () ;
F_29 ( & V_61 , V_62 ,
F_18 ( V_62 ) ) ;
F_30 ( & V_63 ) ;
V_49 = F_31 ( V_64 , F_18 ( V_64 ) ) ;
if( V_49 )
F_27 ( V_59 L_3 ) ;
return 0 ;
}
