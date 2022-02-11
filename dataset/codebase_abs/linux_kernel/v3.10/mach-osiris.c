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
F_6 ( F_7 ( 21 ) , V_10 , NULL ) ;
F_8 ( F_7 ( 21 ) ) ;
return 0 ;
}
static void F_9 ( void )
{
if ( V_8 & V_11 )
F_4 ( V_12 , V_13 ) ;
F_4 ( V_8 , V_6 ) ;
F_10 ( F_7 ( 21 ) , V_14 ) ;
}
static void F_11 ( struct V_15 * V_16 )
{
}
static int F_12 ( struct V_17 * V_18 , void * V_19 )
{
V_20 . V_16 . V_21 = & V_18 -> V_16 ;
return F_13 ( & V_20 ) ;
}
static int F_14 ( struct V_17 * V_18 , void * V_19 )
{
F_15 ( & V_20 ) ;
return 0 ;
}
static void T_1 F_16 ( void )
{
unsigned long V_22 ;
V_23 . V_21 = & V_24 ;
V_23 . V_25 = 12 * 1000 * 1000 ;
V_26 . V_21 = & V_24 ;
V_26 . V_25 = 24 * 1000 * 1000 ;
V_27 . V_21 = & V_23 ;
V_28 . V_21 = & V_26 ;
V_29 . V_21 = & V_28 ;
F_17 ( V_30 , F_18 ( V_30 ) ) ;
F_19 ( V_31 , F_18 ( V_31 ) ) ;
F_20 ( 0 ) ;
F_21 ( V_32 , F_18 ( V_32 ) ) ;
F_22 ( V_33 , V_34 ) ;
if ( ( F_3 ( V_35 ) & V_36 ) >= 4 ) {
F_23 ( V_37 L_3 ,
F_3 ( V_35 ) & V_36 ) ;
V_38 [ 0 ] . V_39 = V_40 ;
V_38 [ 0 ] . V_41 = F_18 ( V_40 ) ;
} else {
F_6 ( F_7 ( 0 ) , V_10 , NULL ) ;
F_8 ( F_7 ( 0 ) ) ;
}
F_24 ( V_22 ) ;
F_25 ( F_26 ( V_42 ) | V_43 | V_44 | V_45 | V_46 | V_47 , V_42 ) ;
F_27 ( V_22 ) ;
}
static void T_1 F_28 ( void )
{
F_29 ( & V_48 ) ;
F_30 ( NULL ) ;
F_31 ( & V_49 ) ;
F_32 ( & V_50 ) ;
F_33 ( 0 , V_51 ,
F_18 ( V_51 ) ) ;
F_34 ( V_52 , F_18 ( V_52 ) ) ;
}
