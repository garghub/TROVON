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
void F_17 ( void )
{
struct V_8 * V_8 ;
V_8 = F_18 ( L_3 , NULL ) ;
if ( ! F_10 ( V_8 ) )
F_19 ( V_8 ) ;
}
static void T_1 F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 , & V_9 ) ;
}
static void T_1 F_22 ( struct V_3 * V_4 )
{
F_23 ( V_4 , & V_10 ) ;
F_24 ( V_4 , & V_11 ) ;
F_25 ( V_4 , & V_12 ) ;
}
static void T_1 F_26 ( struct V_3 * V_4 )
{
F_27 ( V_4 , & V_13 ) ;
F_28 ( V_4 , & V_14 ) ;
}
static void T_1 F_29 ( void )
{
struct V_3 * V_4 = NULL ;
int V_15 ;
int V_16 ;
F_30 ( & V_17 ) ;
V_18 [ 0 ] . V_19 = V_20 ;
F_31 () ;
V_4 = F_32 ( & V_21 ) ;
for ( V_16 = 0 ; V_16 < F_33 ( V_22 ) ; V_16 ++ )
V_22 [ V_16 ] -> V_5 . V_4 = V_4 ;
F_34 ( V_22 ,
F_33 ( V_22 ) ) ;
F_3 ( V_4 ) ;
F_35 ( V_4 ) ;
F_20 ( V_4 ) ;
F_36 ( V_4 ) ;
F_22 ( V_4 ) ;
F_26 ( V_4 ) ;
V_15 = F_33 ( V_23 ) ;
F_37 ( 0 , V_23 , V_15 ) ;
F_37 ( 2 , V_24 ,
F_33 ( V_24 ) ) ;
F_38 () ;
}
static void T_1 F_39 ( void )
{
struct V_3 * V_4 = NULL ;
int V_16 ;
F_30 ( & V_17 ) ;
F_40 () ;
V_4 = F_32 ( & V_21 ) ;
for ( V_16 = 0 ; V_16 < F_33 ( V_25 ) ; V_16 ++ )
V_25 [ V_16 ] -> V_5 . V_4 = V_4 ;
F_34 ( V_25 ,
F_33 ( V_25 ) ) ;
F_3 ( V_4 ) ;
F_41 ( V_4 ) ;
F_20 ( V_4 ) ;
F_36 ( V_4 ) ;
F_22 ( V_4 ) ;
F_17 () ;
F_38 () ;
}
static void T_1 F_42 ( void )
{
struct V_3 * V_4 = NULL ;
int V_15 ;
int V_16 ;
F_30 ( & V_17 ) ;
V_18 [ 0 ] . V_19 = V_26 ;
F_43 () ;
V_4 = F_32 ( & V_21 ) ;
for ( V_16 = 0 ; V_16 < F_33 ( V_22 ) ; V_16 ++ )
V_22 [ V_16 ] -> V_5 . V_4 = V_4 ;
F_34 ( V_22 ,
F_33 ( V_22 ) ) ;
F_3 ( V_4 ) ;
F_44 ( V_4 ) ;
F_20 ( V_4 ) ;
F_36 ( V_4 ) ;
F_22 ( V_4 ) ;
V_15 = F_33 ( V_23 ) ;
V_15 -= V_27 ;
F_37 ( 0 , V_23 , V_15 ) ;
F_37 ( 2 , V_24 ,
F_33 ( V_24 ) ) ;
F_38 () ;
}
