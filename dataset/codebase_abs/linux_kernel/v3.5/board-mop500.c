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
F_4 ( V_4 , & V_5 ) ;
F_5 ( V_4 , & V_6 ) ;
F_6 ( V_4 , & V_7 ) ;
F_7 ( V_4 , & V_8 ) ;
}
static int F_8 ( struct V_3 * V_9 )
{
V_10 = F_9 ( & V_11 . V_9 ,
L_1 ) ;
if ( F_10 ( V_10 ) ) {
F_11 ( & V_11 . V_9 ,
L_2 ) ;
return F_12 ( V_10 ) ;
}
F_13 ( V_10 ) ;
return 0 ;
}
static void F_14 ( struct V_3 * V_9 )
{
F_15 ( V_10 ) ;
F_16 ( V_10 ) ;
}
static void T_1 F_17 ( struct V_3 * V_4 )
{
F_18 ( V_4 , & V_12 ) ;
}
static void F_19 ( void )
{
void T_2 * V_13 , * V_14 ;
V_13 = ( void T_2 * ) F_20 ( V_15 +
V_16 ) ;
V_14 = ( void T_2 * ) F_20 ( V_15 +
V_17 ) ;
F_21 ( ( F_22 ( V_14 ) | 0x1 ) , V_14 ) ;
F_23 ( 1 ) ;
F_21 ( ( F_22 ( V_13 ) | 0x1 ) , V_13 ) ;
F_23 ( 1 ) ;
}
static void T_1 F_24 ( struct V_3 * V_4 )
{
F_25 ( V_4 , & V_18 ) ;
F_26 ( V_4 , & V_19 ) ;
F_27 ( V_4 , & V_20 ) ;
}
static void T_1 F_28 ( struct V_3 * V_4 )
{
F_29 ( V_4 , & V_21 ) ;
F_30 ( V_4 , & V_22 ) ;
}
static void T_1 F_31 ( void )
{
struct V_3 * V_4 = NULL ;
int V_23 ;
int V_24 ;
V_25 [ 0 ] . V_26 = V_27 ;
F_32 () ;
V_4 = F_33 () ;
for ( V_24 = 0 ; V_24 < F_34 ( V_28 ) ; V_24 ++ )
V_28 [ V_24 ] -> V_9 . V_4 = V_4 ;
F_35 ( V_28 ,
F_34 ( V_28 ) ) ;
F_3 ( V_4 ) ;
F_36 ( V_4 ) ;
F_17 ( V_4 ) ;
F_37 ( V_4 ) ;
F_24 ( V_4 ) ;
F_28 ( V_4 ) ;
V_23 = F_34 ( V_29 ) ;
F_38 ( 0 , V_29 , V_23 ) ;
F_38 ( 2 , V_30 ,
F_34 ( V_30 ) ) ;
F_39 () ;
F_40 () ;
}
static void T_1 F_41 ( void )
{
struct V_3 * V_4 = NULL ;
int V_24 ;
F_42 () ;
V_4 = F_33 () ;
for ( V_24 = 0 ; V_24 < F_34 ( V_31 ) ; V_24 ++ )
V_31 [ V_24 ] -> V_9 . V_4 = V_4 ;
F_35 ( V_31 ,
F_34 ( V_31 ) ) ;
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
int V_23 ;
int V_24 ;
V_25 [ 0 ] . V_26 = V_32 ;
F_45 () ;
V_4 = F_33 () ;
for ( V_24 = 0 ; V_24 < F_34 ( V_28 ) ; V_24 ++ )
V_28 [ V_24 ] -> V_9 . V_4 = V_4 ;
F_35 ( V_28 ,
F_34 ( V_28 ) ) ;
F_3 ( V_4 ) ;
F_46 ( V_4 ) ;
F_17 ( V_4 ) ;
F_37 ( V_4 ) ;
F_24 ( V_4 ) ;
V_23 = F_34 ( V_29 ) ;
V_23 -= V_33 ;
F_38 ( 0 , V_29 , V_23 ) ;
F_38 ( 2 , V_30 ,
F_34 ( V_30 ) ) ;
F_39 () ;
F_40 () ;
}
static void T_1 F_47 ( void )
{
struct V_3 * V_4 = NULL ;
int V_23 ;
int V_24 ;
if ( F_48 ( L_3 ) )
F_32 () ;
else if ( F_48 ( L_4 ) )
F_42 () ;
else if ( F_48 ( L_5 ) )
F_45 () ;
V_4 = F_49 () ;
for ( V_24 = 0 ; V_24 < F_34 ( V_28 ) ; V_24 ++ )
V_28 [ V_24 ] -> V_9 . V_4 = V_4 ;
for ( V_24 = 0 ; V_24 < F_34 ( V_31 ) ; V_24 ++ )
V_31 [ V_24 ] -> V_9 . V_4 = V_4 ;
F_50 ( NULL , V_34 , V_35 , V_4 ) ;
if ( F_48 ( L_3 ) ) {
V_25 [ 0 ] . V_26 = V_27 ;
F_35 ( V_28 ,
F_34 ( V_28 ) ) ;
F_36 ( V_4 ) ;
V_23 = F_34 ( V_29 ) ;
F_38 ( 0 , V_29 , V_23 ) ;
F_38 ( 2 , V_30 ,
F_34 ( V_30 ) ) ;
F_40 () ;
} else if ( F_48 ( L_4 ) ) {
F_35 ( V_36 ,
F_34 ( V_36 ) ) ;
F_43 ( V_4 ) ;
} else if ( F_48 ( L_5 ) ) {
V_25 [ 0 ] . V_26 = V_32 ;
F_35 ( V_28 ,
F_34 ( V_28 ) ) ;
F_46 ( V_4 ) ;
V_23 = F_34 ( V_29 ) ;
V_23 -= V_33 ;
F_38 ( 0 , V_29 , V_23 ) ;
F_38 ( 2 , V_30 ,
F_34 ( V_30 ) ) ;
F_40 () ;
}
F_3 ( V_4 ) ;
F_39 () ;
}
