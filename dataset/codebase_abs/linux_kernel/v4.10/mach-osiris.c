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
F_17 ( V_23 , F_18 ( V_23 ) ) ;
F_19 ( V_24 , F_18 ( V_24 ) ) ;
F_20 ( V_25 , V_26 ) ;
if ( ( F_3 ( V_27 ) & V_28 ) >= 4 ) {
F_21 ( V_29 L_3 ,
F_3 ( V_27 ) & V_28 ) ;
V_30 [ 0 ] . V_31 = V_32 ;
V_30 [ 0 ] . V_33 = F_18 ( V_32 ) ;
} else {
F_6 ( F_7 ( 0 ) , V_10 , NULL ) ;
F_8 ( F_7 ( 0 ) ) ;
}
F_22 ( V_22 ) ;
F_23 ( F_24 ( V_34 ) | V_35 | V_36 | V_37 | V_38 | V_39 , V_34 ) ;
F_25 ( V_22 ) ;
}
static void T_1 F_26 ( void )
{
F_27 ( 12000000 ) ;
F_28 () ;
}
static void T_1 F_29 ( void )
{
F_30 ( & V_40 ) ;
F_31 ( NULL ) ;
F_32 ( & V_41 ) ;
F_33 ( & V_42 ) ;
F_34 ( 0 , V_43 ,
F_18 ( V_43 ) ) ;
F_35 ( V_44 , F_18 ( V_44 ) ) ;
}
