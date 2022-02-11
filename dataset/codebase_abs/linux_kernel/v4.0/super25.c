static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( F_3 ( V_3 ) , V_6 , 1 ) ;
F_4 ( V_5 , V_7 , V_8 ) ;
if ( V_5 == NULL )
return NULL ;
F_5 ( & V_5 -> V_9 ) ;
return & V_5 -> V_9 ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_7 ( V_11 , struct V_1 , V_12 ) ;
struct V_4 * V_13 = F_8 ( V_1 ) ;
F_9 ( V_13 , V_7 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_11 ( & V_1 -> V_12 , F_6 ) ;
}
static int T_1 F_12 ( void )
{
struct V_14 * V_15 ;
T_2 V_16 ;
struct V_17 V_18 ;
int V_19 , V_20 , V_21 [ 2 ] ;
F_13 ( sizeof( V_22 ) == V_23 + 1 ) ;
F_14 ( V_24 , L_1 ,
& V_25 ) ;
V_20 = - V_26 ;
V_7 = F_15 ( L_2 ,
sizeof( struct V_4 ) ,
0 , V_27 , NULL ) ;
if ( V_7 == NULL )
goto V_28;
V_29 = F_15 ( L_3 ,
sizeof( struct V_30 ) , 0 ,
V_27 , NULL ) ;
if ( V_29 == NULL )
goto V_28;
V_31 = F_15 ( L_4 ,
sizeof( struct V_32 ) ,
0 , 0 , NULL ) ;
if ( V_31 == NULL )
goto V_28;
V_33 = F_15 ( L_5 ,
V_34 *
sizeof( struct V_35 ) ,
0 , 0 , NULL ) ;
if ( V_33 == NULL )
goto V_28;
V_15 = F_16 ( L_6 , V_36 , NULL , NULL ) ;
if ( F_17 ( V_15 ) ) {
V_20 = F_18 ( V_15 ) ;
F_19 ( L_7 ,
V_20 ) ;
goto V_28;
}
V_37 = V_15 ;
F_20 ( V_21 , sizeof( V_21 ) ) ;
for ( V_19 = 0 ; ; V_19 ++ ) {
if ( F_21 ( V_19 , & V_16 ) == - V_38 )
break;
if ( F_22 ( F_23 ( V_16 . V_39 ) ) != V_40 )
V_21 [ 0 ] ^= F_24 ( V_16 . V_39 ) ;
}
F_25 ( & V_18 ) ;
F_26 ( V_18 . V_41 ^ V_21 [ 0 ] , V_18 . V_42 ^ V_21 [ 1 ] ) ;
F_27 ( & V_43 ) ;
V_43 . V_44 = V_45 ;
V_20 = F_28 () ;
if ( V_20 != 0 )
goto V_46;
V_20 = F_29 () ;
if ( V_20 != 0 )
goto V_47;
V_20 = F_30 () ;
if ( V_20 != 0 )
goto V_48;
F_31 ( V_49 ) ;
F_32 ( V_50 ) ;
F_33 ( V_51 ) ;
return 0 ;
V_48:
F_34 () ;
V_47:
F_35 ( & V_43 ) ;
F_36 () ;
V_46:
F_37 ( & V_37 ) ;
V_28:
if ( V_7 != NULL )
F_38 ( V_7 ) ;
if ( V_29 != NULL )
F_38 ( V_29 ) ;
if ( V_31 != NULL )
F_38 ( V_31 ) ;
if ( V_33 != NULL )
F_38 ( V_33 ) ;
return V_20 ;
}
static void T_3 F_39 ( void )
{
F_31 ( NULL ) ;
F_32 ( NULL ) ;
F_33 ( NULL ) ;
F_37 ( & V_37 ) ;
F_40 () ;
F_34 () ;
F_35 ( & V_43 ) ;
F_36 () ;
F_41 ( V_52 [ V_53 ] == 0 ,
L_8 ,
V_52 [ V_53 ] ) ;
F_38 ( V_7 ) ;
F_38 ( V_33 ) ;
F_38 ( V_31 ) ;
F_38 ( V_29 ) ;
}
