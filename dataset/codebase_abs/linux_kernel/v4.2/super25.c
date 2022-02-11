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
T_2 V_14 ;
struct V_15 V_16 ;
int V_17 , V_18 , V_19 [ 2 ] ;
F_13 ( sizeof( V_20 ) == V_21 + 1 ) ;
F_14 ( V_22 , L_1 ,
& V_23 ) ;
V_18 = - V_24 ;
V_7 = F_15 ( L_2 ,
sizeof( struct V_4 ) ,
0 , V_25 , NULL ) ;
if ( V_7 == NULL )
goto V_26;
V_27 = F_15 ( L_3 ,
sizeof( struct V_28 ) , 0 ,
V_25 , NULL ) ;
if ( V_27 == NULL )
goto V_26;
V_29 = F_15 ( L_4 ,
sizeof( struct V_30 ) ,
0 , 0 , NULL ) ;
if ( V_29 == NULL )
goto V_26;
V_31 = F_15 ( L_5 ,
V_32 *
sizeof( struct V_33 ) ,
0 , 0 , NULL ) ;
if ( V_31 == NULL )
goto V_26;
V_34 = F_16 ( L_6 , V_35 ) ;
if ( F_17 ( V_34 ) ) {
V_18 = V_34 ? F_18 ( V_34 ) : - V_24 ;
V_34 = NULL ;
goto V_26;
}
V_36 = F_19 ( L_6 , NULL , V_37 ) ;
if ( ! V_36 ) {
V_18 = - V_24 ;
goto V_38;
}
F_20 ( V_19 , sizeof( V_19 ) ) ;
for ( V_17 = 0 ; ; V_17 ++ ) {
if ( F_21 ( V_17 , & V_14 ) == - V_39 )
break;
if ( F_22 ( F_23 ( V_14 . V_40 ) ) != V_41 )
V_19 [ 0 ] ^= F_24 ( V_14 . V_40 ) ;
}
F_25 ( & V_16 ) ;
F_26 ( V_16 . V_42 ^ V_19 [ 0 ] , V_16 . V_43 ^ V_19 [ 1 ] ) ;
F_27 ( & V_44 , V_45 , 0 ) ;
V_18 = F_28 () ;
if ( V_18 != 0 )
goto V_46;
V_18 = F_29 () ;
if ( V_18 != 0 )
goto V_47;
V_18 = F_30 () ;
if ( V_18 != 0 )
goto V_48;
F_31 ( V_49 ) ;
F_32 ( V_50 ) ;
F_33 ( V_51 ) ;
return 0 ;
V_48:
F_34 () ;
V_47:
F_35 ( & V_44 ) ;
F_36 () ;
V_46:
F_37 ( V_36 ) ;
V_38:
F_38 ( V_34 ) ;
V_26:
if ( V_7 != NULL )
F_39 ( V_7 ) ;
if ( V_27 != NULL )
F_39 ( V_27 ) ;
if ( V_29 != NULL )
F_39 ( V_29 ) ;
if ( V_31 != NULL )
F_39 ( V_31 ) ;
return V_18 ;
}
static void T_3 F_40 ( void )
{
F_31 ( NULL ) ;
F_32 ( NULL ) ;
F_33 ( NULL ) ;
F_38 ( V_34 ) ;
F_37 ( V_36 ) ;
F_41 () ;
F_34 () ;
F_35 ( & V_44 ) ;
F_36 () ;
F_42 ( V_52 [ V_53 ] == 0 ,
L_7 ,
V_52 [ V_53 ] ) ;
F_39 ( V_7 ) ;
F_39 ( V_31 ) ;
F_39 ( V_29 ) ;
F_39 ( V_27 ) ;
}
