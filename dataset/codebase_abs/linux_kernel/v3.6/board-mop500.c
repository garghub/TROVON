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
static void F_19 ( void )
{
void T_2 * V_9 , * V_10 ;
V_9 = ( void T_2 * ) F_20 ( V_11 +
V_12 ) ;
V_10 = ( void T_2 * ) F_20 ( V_11 +
V_13 ) ;
F_21 ( ( F_22 ( V_10 ) | 0x1 ) , V_10 ) ;
F_23 ( 1 ) ;
F_21 ( ( F_22 ( V_9 ) | 0x1 ) , V_9 ) ;
F_23 ( 1 ) ;
}
static void T_1 F_24 ( struct V_3 * V_4 )
{
F_25 ( V_4 , & V_14 ) ;
F_26 ( V_4 , & V_15 ) ;
F_27 ( V_4 , & V_16 ) ;
}
static void T_1 F_28 ( struct V_3 * V_4 )
{
F_29 ( V_4 , & V_17 ) ;
F_30 ( V_4 , & V_18 ) ;
}
static void T_1 F_31 ( void )
{
struct V_3 * V_4 = NULL ;
int V_19 ;
int V_20 ;
V_21 [ 0 ] . V_22 = V_23 ;
F_32 () ;
V_4 = F_33 ( & V_24 ) ;
for ( V_20 = 0 ; V_20 < F_34 ( V_25 ) ; V_20 ++ )
V_25 [ V_20 ] -> V_5 . V_4 = V_4 ;
F_35 ( V_25 ,
F_34 ( V_25 ) ) ;
F_3 ( V_4 ) ;
F_36 ( V_4 ) ;
F_17 ( V_4 ) ;
F_37 ( V_4 ) ;
F_24 ( V_4 ) ;
F_28 ( V_4 ) ;
V_19 = F_34 ( V_26 ) ;
F_38 ( 0 , V_26 , V_19 ) ;
F_38 ( 2 , V_27 ,
F_34 ( V_27 ) ) ;
F_39 () ;
F_40 () ;
}
static void T_1 F_41 ( void )
{
struct V_3 * V_4 = NULL ;
int V_20 ;
F_42 () ;
V_4 = F_33 ( & V_24 ) ;
for ( V_20 = 0 ; V_20 < F_34 ( V_28 ) ; V_20 ++ )
V_28 [ V_20 ] -> V_5 . V_4 = V_4 ;
F_35 ( V_28 ,
F_34 ( V_28 ) ) ;
F_3 ( V_4 ) ;
F_43 ( V_4 ) ;
F_17 ( V_4 ) ;
F_37 ( V_4 ) ;
F_24 ( V_4 ) ;
F_39 () ;
}
static void T_1 F_44 ( void )
{
struct V_3 * V_4 = NULL ;
int V_19 ;
int V_20 ;
V_21 [ 0 ] . V_22 = V_29 ;
F_45 () ;
V_4 = F_33 ( & V_24 ) ;
for ( V_20 = 0 ; V_20 < F_34 ( V_25 ) ; V_20 ++ )
V_25 [ V_20 ] -> V_5 . V_4 = V_4 ;
F_35 ( V_25 ,
F_34 ( V_25 ) ) ;
F_3 ( V_4 ) ;
F_46 ( V_4 ) ;
F_17 ( V_4 ) ;
F_37 ( V_4 ) ;
F_24 ( V_4 ) ;
V_19 = F_34 ( V_26 ) ;
V_19 -= V_30 ;
F_38 ( 0 , V_26 , V_19 ) ;
F_38 ( 2 , V_27 ,
F_34 ( V_27 ) ) ;
F_39 () ;
F_40 () ;
}
static void T_1 F_47 ( void )
{
struct V_3 * V_4 = NULL ;
int V_19 ;
int V_20 ;
if ( F_48 ( L_3 ) )
F_32 () ;
else if ( F_48 ( L_4 ) )
F_42 () ;
else if ( F_48 ( L_5 ) )
F_45 () ;
V_4 = F_49 () ;
for ( V_20 = 0 ; V_20 < F_34 ( V_25 ) ; V_20 ++ )
V_25 [ V_20 ] -> V_5 . V_4 = V_4 ;
F_50 ( NULL , V_31 , V_32 , V_4 ) ;
if ( F_48 ( L_3 ) ) {
V_21 [ 0 ] . V_22 = V_23 ;
F_35 ( V_25 ,
F_34 ( V_25 ) ) ;
F_36 ( V_4 ) ;
F_37 ( V_4 ) ;
V_19 = F_34 ( V_26 ) ;
F_38 ( 0 , V_26 , V_19 ) ;
F_38 ( 2 , V_27 ,
F_34 ( V_27 ) ) ;
F_40 () ;
} else if ( F_48 ( L_4 ) ) {
F_37 ( V_4 ) ;
} else if ( F_48 ( L_5 ) ) {
V_21 [ 0 ] . V_22 = V_29 ;
F_35 ( V_25 ,
F_34 ( V_25 ) ) ;
F_46 ( V_4 ) ;
F_37 ( V_4 ) ;
V_19 = F_34 ( V_26 ) ;
V_19 -= V_30 ;
F_38 ( 0 , V_26 , V_19 ) ;
F_38 ( 2 , V_27 ,
F_34 ( V_27 ) ) ;
F_40 () ;
}
F_39 () ;
}
