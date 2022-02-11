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
if ( V_6 ) {
F_4 ( V_3 L_2 ) ;
return - V_7 ;
}
F_6 ( V_8 , 1 ) ;
F_6 ( V_9 , 1 ) ;
V_10 = 1 ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
V_10 = 0 ;
F_6 ( V_8 , 0 ) ;
F_6 ( V_9 , 0 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
if ( V_10 ) {
F_4 ( V_3 L_3 ) ;
return - V_7 ;
}
V_6 = 1 ;
return 0 ;
}
static void F_9 ( struct V_4 * V_5 )
{
V_6 = 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
return 0 ;
}
static void F_11 ( struct V_4 * V_5 )
{
}
static int F_12 ( struct V_11 * V_12 ,
unsigned V_13 , unsigned V_14 )
{
V_15 [ 0 ] . V_16 = V_13 + 0 ;
V_15 [ 1 ] . V_16 = V_13 + 1 ;
F_13 ( V_15 ) ;
F_14 ( V_13 + 7 , V_17 , L_4 ) ;
F_14 ( V_13 + 15 , V_17 , L_5 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
F_16 ( & V_18 ,
V_19 | V_20 |
V_21 | V_22 ,
V_23 | V_24 ) ;
V_18 . V_25 -> V_26 . V_27 = true ;
V_18 . V_28 -> V_26 . V_27 = true ;
V_18 . V_28 -> V_26 . V_29 = L_6 ;
F_17 ( L_7 , & V_18 ) ;
F_18 ( 2 , 400 , NULL , 0 ) ;
F_18 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_19 ( void )
{
if ( F_20 () > V_30 )
V_31 . V_32 = 6 ;
else
V_31 . V_32 = 29 ;
F_21 ( & V_31 ) ;
}
static inline void F_19 ( void )
{
}
static void F_22 ( void )
{
F_23 ( L_8 ,
V_33 | V_34 ) ;
}
static inline void F_24 ( void )
{
F_25 ( & V_35 ) ;
F_25 ( & V_36 ) ;
F_25 ( & V_37 ) ;
}
static inline void F_24 ( void )
{
F_26 () ;
}
static void T_1 F_27 ( void )
{
int V_38 ;
F_28 ( V_39 , V_40 ) ;
V_41 = V_42 ;
V_43 = F_3 ( V_42 ) ;
F_15 () ;
F_29 ( & V_44 ) ;
if ( F_20 () > V_30 )
V_38 = V_45 ;
else
V_38 = V_46 ;
F_30 ( 1 , V_38 , 310 , NULL ) ;
F_24 () ;
F_31 ( V_47 , NULL ) ;
F_32 ( NULL ) ;
F_19 () ;
F_33 ( V_48 , V_49 , 0 ) ;
F_1 () ;
F_22 () ;
F_34 ( & V_50 ) ;
}
