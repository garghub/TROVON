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
return 0 ;
}
static int T_1 F_13 ( void )
{
F_14 ( & V_15 ,
V_16 | V_17 |
V_18 | V_19 ,
V_20 | V_21 ) ;
V_15 . V_22 -> V_23 . V_24 = true ;
V_15 . V_25 -> V_23 . V_24 = true ;
V_15 . V_25 -> V_23 . V_26 = L_4 ;
F_15 ( L_5 , & V_15 ) ;
F_16 ( 2 , 400 , NULL , 0 ) ;
F_16 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_17 ( void )
{
if ( F_18 () > V_27 )
V_28 . V_29 = 6 ;
else
V_28 . V_29 = 29 ;
F_19 ( & V_28 ) ;
}
static inline void F_17 ( void )
{
}
static void F_20 ( void )
{
F_21 ( L_6 ,
V_30 | V_31 ) ;
}
static void T_1 F_22 ( void )
{
int V_32 ;
F_23 ( V_33 , V_34 ) ;
F_24 ( V_12 ) ;
F_13 () ;
F_25 ( & V_35 ) ;
if ( F_18 () > V_27 )
V_32 = V_36 ;
else
V_32 = V_37 ;
F_26 ( 1 , V_32 , 310 , NULL ) ;
F_27 () ;
F_28 ( V_38 , NULL ) ;
F_29 ( NULL ) ;
F_17 () ;
F_30 ( V_39 , V_40 , 0 ) ;
F_1 () ;
F_20 () ;
F_31 ( & V_41 ) ;
}
