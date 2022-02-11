static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_3 = V_2 -> V_5 [ V_3 ] & 3 ;
F_2 ( L_1 ,
V_3 , V_2 , V_2 -> V_5 ) ;
V_4 = F_3 ( V_6 ) ;
V_4 &= ~ V_7 ;
V_4 |= V_3 ;
F_2 ( L_2 , V_4 ) ;
F_4 ( V_4 , V_6 ) ;
}
static int F_5 ( void )
{
unsigned int V_4 ;
V_8 = F_3 ( V_6 ) ;
V_4 = V_8 & ~ V_7 ;
if ( ( V_8 & V_9 ) == 0 )
V_4 |= 2 ;
F_4 ( V_4 , V_6 ) ;
F_6 ( F_7 ( 21 ) , 1 ) ;
F_8 ( F_7 ( 21 ) , V_10 ) ;
return 0 ;
}
static void F_9 ( void )
{
if ( V_8 & V_11 )
F_4 ( V_12 , V_13 ) ;
F_4 ( V_8 , V_6 ) ;
F_8 ( F_7 ( 21 ) , V_14 ) ;
}
static void F_10 ( struct V_15 * V_16 )
{
}
static int F_11 ( struct V_17 * V_18 , void * V_19 )
{
V_20 . V_16 . V_21 = & V_18 -> V_16 ;
return F_12 ( & V_20 ) ;
}
static int F_13 ( struct V_17 * V_18 , void * V_19 )
{
F_14 ( & V_20 ) ;
return 0 ;
}
static void T_1 F_15 ( void )
{
unsigned long V_22 ;
V_23 . V_21 = & V_24 ;
V_23 . V_25 = 12 * 1000 * 1000 ;
V_26 . V_21 = & V_24 ;
V_26 . V_25 = 24 * 1000 * 1000 ;
V_27 . V_21 = & V_23 ;
V_28 . V_21 = & V_26 ;
V_29 . V_21 = & V_28 ;
F_16 ( V_30 , F_17 ( V_30 ) ) ;
F_18 ( V_31 , F_17 ( V_31 ) ) ;
F_19 ( 0 ) ;
F_20 ( V_32 , F_17 ( V_32 ) ) ;
if ( ( F_3 ( V_33 ) & V_34 ) >= 4 ) {
F_21 ( V_35 L_3 ,
F_3 ( V_33 ) & V_34 ) ;
V_36 [ 0 ] . V_37 = V_38 ;
V_36 [ 0 ] . V_39 = F_17 ( V_38 ) ;
} else {
F_6 ( F_7 ( 0 ) , 1 ) ;
}
F_22 ( V_22 ) ;
F_23 ( F_24 ( V_40 ) | V_41 | V_42 | V_43 | V_44 | V_45 , V_40 ) ;
F_25 ( V_22 ) ;
}
static void T_1 F_26 ( void )
{
F_27 ( & V_46 ) ;
F_28 ( NULL ) ;
F_29 ( & V_47 ) ;
F_30 ( & V_48 ) ;
F_31 ( 0 , V_49 ,
F_17 ( V_49 ) ) ;
F_32 ( V_50 , F_17 ( V_50 ) ) ;
}
