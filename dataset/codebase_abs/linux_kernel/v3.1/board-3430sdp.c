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
static void T_1 F_12 ( void )
{
F_13 () ;
F_14 ( V_11 , NULL ) ;
}
static int F_15 ( struct V_12 * V_13 ,
unsigned V_14 , unsigned V_15 )
{
V_16 [ 0 ] . V_17 = V_14 + 0 ;
V_16 [ 1 ] . V_17 = V_14 + 1 ;
F_16 ( V_16 ) ;
F_17 ( V_14 + 7 , V_18 , L_4 ) ;
F_17 ( V_14 + 15 , V_18 , L_5 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
F_19 ( & V_19 ,
V_20 | V_21 |
V_22 | V_23 ,
V_24 | V_25 ) ;
V_19 . V_26 -> V_27 . V_28 = true ;
V_19 . V_29 -> V_27 . V_28 = true ;
V_19 . V_29 -> V_27 . V_30 = L_6 ;
F_20 ( L_7 , & V_19 ) ;
F_21 ( 2 , 400 , NULL , 0 ) ;
F_21 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_22 ( void )
{
if ( F_23 () > V_31 )
V_32 . V_33 = 6 ;
else
V_32 . V_33 = 29 ;
F_24 ( & V_32 ) ;
}
static inline void F_22 ( void )
{
}
static void F_25 ( void )
{
F_26 ( L_8 ,
V_34 | V_35 ) ;
}
static inline void F_27 ( void )
{
F_28 ( & V_36 ) ;
F_28 ( & V_37 ) ;
F_28 ( & V_38 ) ;
}
static inline void F_27 ( void )
{
F_29 () ;
}
static void T_1 F_30 ( void )
{
int V_39 ;
F_31 ( V_40 , V_41 ) ;
V_42 = V_43 ;
V_44 = F_3 ( V_43 ) ;
F_18 () ;
F_32 ( & V_45 ) ;
if ( F_23 () > V_31 )
V_39 = V_46 ;
else
V_39 = V_47 ;
F_33 ( 1 , V_39 , 310 , NULL ) ;
F_27 () ;
F_34 ( NULL ) ;
F_22 () ;
F_35 ( V_48 , V_49 , 0 ) ;
F_1 () ;
F_25 () ;
F_36 ( & V_50 ) ;
}
