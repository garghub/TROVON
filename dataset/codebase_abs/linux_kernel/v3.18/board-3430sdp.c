static void T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( V_2 ,
V_3 , L_1 ) ;
if ( V_1 )
F_3 ( L_2 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
unsigned V_6 , unsigned V_7 )
{
V_8 [ 0 ] . V_9 = V_6 + 0 ;
V_8 [ 1 ] . V_9 = V_6 + 1 ;
F_5 ( V_8 ) ;
F_2 ( V_6 + 7 , V_10 , L_3 ) ;
F_2 ( V_6 + 15 , V_10 , L_4 ) ;
V_11 . V_12 = V_6 + 2 ;
F_6 ( L_5 , & V_11 ) ;
return 0 ;
}
static int T_1 F_7 ( void )
{
F_8 ( & V_13 ,
V_14 | V_15 |
V_16 | V_17 ,
V_18 | V_19 ) ;
V_13 . V_20 -> V_21 . V_22 = true ;
V_13 . V_23 -> V_21 . V_22 = true ;
V_13 . V_23 -> V_21 . V_24 = L_6 ;
V_13 . V_25 -> V_26 -> V_27 = 1 ;
V_13 . V_25 -> V_26 -> V_28 = - V_29 ;
F_9 ( L_7 , & V_13 ) ;
F_10 ( 2 , 400 , NULL , 0 ) ;
F_10 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_11 ( void )
{
if ( F_12 () > V_30 )
V_31 . V_32 = 6 ;
else
V_31 . V_32 = 29 ;
F_13 ( & V_31 ) ;
}
static inline void F_11 ( void )
{
}
static void F_14 ( void )
{
F_15 ( L_8 ,
V_33 | V_34 ) ;
}
static void T_1 F_16 ( void )
{
int V_35 ;
F_17 ( V_36 , V_37 ) ;
F_18 ( V_8 ) ;
F_7 () ;
F_19 ( & V_38 ) ;
F_20 ( & V_39 ) ;
F_20 ( & V_40 ) ;
F_20 ( & V_41 ) ;
F_20 ( & V_42 ) ;
if ( F_12 () > V_30 )
V_35 = V_43 ;
else
V_35 = V_44 ;
F_21 ( 1 , V_35 , 310 , NULL ) ;
F_22 () ;
F_23 ( V_45 , NULL ) ;
F_24 ( L_9 , 0 , L_10 ) ;
F_25 ( NULL ) ;
F_11 () ;
F_26 ( V_46 , V_47 , 0 ) ;
F_1 () ;
F_14 () ;
F_27 ( V_48 , F_28 ( V_48 ) ) ;
F_29 ( & V_49 ) ;
}
