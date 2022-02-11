static void F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = NULL ;
#if 0
parent = tc3589x->dev;
#endif
F_2 ( V_4 ) ;
}
static void T_1 F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 , NULL ) ;
F_5 ( V_4 , NULL ) ;
F_6 ( V_4 , NULL ) ;
F_7 ( V_4 , NULL ) ;
}
static int F_8 ( struct V_3 * V_5 )
{
V_6 = F_9 ( & V_7 . V_5 ,
L_1 ) ;
if ( F_10 ( V_6 ) ) {
F_11 ( & V_7 . V_5 ,
L_2 ) ;
return F_12 ( V_6 ) ;
}
F_13 ( V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_3 * V_5 )
{
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
}
static void T_1 F_17 ( struct V_3 * V_4 )
{
F_18 ( V_4 , & V_8 ) ;
}
static void T_1 F_19 ( struct V_3 * V_4 )
{
F_20 ( V_4 , & V_9 ) ;
F_21 ( V_4 , & V_10 ) ;
F_22 ( V_4 , & V_11 ) ;
}
static void T_1 F_23 ( struct V_3 * V_4 )
{
F_24 ( V_4 , & V_12 ) ;
F_25 ( V_4 , & V_13 ) ;
}
static void T_1 F_26 ( void )
{
struct V_3 * V_4 = NULL ;
int V_14 ;
int V_15 ;
V_16 [ 0 ] . V_17 = V_18 ;
F_27 () ;
V_4 = F_28 ( & V_19 ) ;
for ( V_15 = 0 ; V_15 < F_29 ( V_20 ) ; V_15 ++ )
V_20 [ V_15 ] -> V_5 . V_4 = V_4 ;
F_30 ( V_20 ,
F_29 ( V_20 ) ) ;
F_3 ( V_4 ) ;
F_31 ( V_4 ) ;
F_17 ( V_4 ) ;
F_32 ( V_4 ) ;
F_19 ( V_4 ) ;
F_23 ( V_4 ) ;
V_14 = F_29 ( V_21 ) ;
F_33 ( 0 , V_21 , V_14 ) ;
F_33 ( 2 , V_22 ,
F_29 ( V_22 ) ) ;
F_34 () ;
}
static void T_1 F_35 ( void )
{
struct V_3 * V_4 = NULL ;
int V_15 ;
F_36 () ;
V_4 = F_28 ( & V_19 ) ;
for ( V_15 = 0 ; V_15 < F_29 ( V_23 ) ; V_15 ++ )
V_23 [ V_15 ] -> V_5 . V_4 = V_4 ;
F_30 ( V_23 ,
F_29 ( V_23 ) ) ;
F_3 ( V_4 ) ;
F_37 ( V_4 ) ;
F_17 ( V_4 ) ;
F_32 ( V_4 ) ;
F_19 ( V_4 ) ;
F_34 () ;
}
static void T_1 F_38 ( void )
{
struct V_3 * V_4 = NULL ;
int V_14 ;
int V_15 ;
V_16 [ 0 ] . V_17 = V_24 ;
F_39 () ;
V_4 = F_28 ( & V_19 ) ;
for ( V_15 = 0 ; V_15 < F_29 ( V_20 ) ; V_15 ++ )
V_20 [ V_15 ] -> V_5 . V_4 = V_4 ;
F_30 ( V_20 ,
F_29 ( V_20 ) ) ;
F_3 ( V_4 ) ;
F_40 ( V_4 ) ;
F_17 ( V_4 ) ;
F_32 ( V_4 ) ;
F_19 ( V_4 ) ;
V_14 = F_29 ( V_21 ) ;
V_14 -= V_25 ;
F_33 ( 0 , V_21 , V_14 ) ;
F_33 ( 2 , V_22 ,
F_29 ( V_22 ) ) ;
F_34 () ;
}
