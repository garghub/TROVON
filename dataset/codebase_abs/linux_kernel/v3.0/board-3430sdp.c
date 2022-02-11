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
F_19 ( L_6 , & V_19 ) ;
F_20 ( 2 , 400 , NULL , 0 ) ;
F_20 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_21 ( void )
{
if ( F_22 () > V_20 )
V_21 . V_22 = 6 ;
else
V_21 . V_22 = 29 ;
F_23 ( & V_21 ) ;
}
static inline void F_21 ( void )
{
}
static void F_24 ( void )
{
F_25 ( L_7 ,
V_23 | V_24 ) ;
}
static inline void F_26 ( void )
{
F_27 ( & V_25 ) ;
F_27 ( & V_26 ) ;
F_27 ( & V_27 ) ;
}
static inline void F_26 ( void )
{
F_28 () ;
}
static void T_1 F_29 ( void )
{
int V_28 ;
F_30 ( V_29 , V_30 ) ;
V_31 = V_32 ;
V_33 = F_3 ( V_32 ) ;
F_18 () ;
F_31 ( & V_34 ) ;
if ( F_22 () > V_20 )
V_28 = V_35 ;
else
V_28 = V_36 ;
F_32 ( 1 , V_28 , 310 , NULL ) ;
F_26 () ;
F_33 ( NULL ) ;
F_21 () ;
F_34 ( V_37 , V_38 , 0 ) ;
F_1 () ;
F_24 () ;
F_35 ( & V_39 ) ;
}
