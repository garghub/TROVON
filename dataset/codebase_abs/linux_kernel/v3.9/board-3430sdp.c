static void T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( V_2 ,
F_3 ( V_2 ) ) ;
if ( V_1 )
F_4 ( V_3 L_1 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
F_6 ( V_6 , 1 ) ;
F_6 ( V_7 , 1 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_6 ( V_6 , 0 ) ;
F_6 ( V_7 , 0 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_9 ( struct V_4 * V_5 )
{
}
static int F_10 ( struct V_8 * V_9 ,
unsigned V_10 , unsigned V_11 )
{
V_12 [ 0 ] . V_13 = V_10 + 0 ;
V_12 [ 1 ] . V_13 = V_10 + 1 ;
F_11 ( V_12 ) ;
F_12 ( V_10 + 7 , V_14 , L_2 ) ;
F_12 ( V_10 + 15 , V_14 , L_3 ) ;
V_15 . V_16 = V_10 + 2 ;
F_13 ( L_4 , & V_15 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
F_15 ( & V_17 ,
V_18 | V_19 |
V_20 | V_21 ,
V_22 | V_23 ) ;
V_17 . V_24 -> V_25 . V_26 = true ;
V_17 . V_27 -> V_25 . V_26 = true ;
V_17 . V_27 -> V_25 . V_28 = L_5 ;
V_17 . V_29 -> V_30 -> V_31 = 1 ;
V_17 . V_29 -> V_30 -> V_32 = - V_33 ;
F_16 ( L_6 , & V_17 ) ;
F_17 ( 2 , 400 , NULL , 0 ) ;
F_17 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_18 ( void )
{
if ( F_19 () > V_34 )
V_35 . V_36 = 6 ;
else
V_35 . V_36 = 29 ;
F_20 ( & V_35 ) ;
}
static inline void F_18 ( void )
{
}
static void F_21 ( void )
{
F_22 ( L_7 ,
V_37 | V_38 ) ;
}
static void T_1 F_23 ( void )
{
int V_39 ;
F_24 ( V_40 , V_41 ) ;
F_25 ( V_12 ) ;
F_14 () ;
F_26 ( & V_42 ) ;
if ( F_19 () > V_34 )
V_39 = V_43 ;
else
V_39 = V_44 ;
F_27 ( 1 , V_39 , 310 , NULL ) ;
F_28 () ;
F_29 ( V_45 , NULL ) ;
F_30 ( L_8 , 0 , L_9 ) ;
F_31 ( NULL ) ;
F_18 () ;
F_32 ( V_46 , V_47 , 0 ) ;
F_1 () ;
F_21 () ;
F_33 ( & V_48 ) ;
}
