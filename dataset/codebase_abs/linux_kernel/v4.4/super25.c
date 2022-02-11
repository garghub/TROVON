static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( F_3 ( V_3 ) , V_6 , 1 ) ;
V_5 = F_4 ( V_7 , V_8 | V_9 ) ;
if ( V_5 == NULL )
return NULL ;
F_5 ( & V_5 -> V_10 ) ;
return & V_5 -> V_10 ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_7 ( V_12 , struct V_1 , V_13 ) ;
struct V_4 * V_14 = F_8 ( V_1 ) ;
F_9 ( V_7 , V_14 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_11 ( & V_1 -> V_13 , F_6 ) ;
}
static int T_1 F_12 ( void )
{
T_2 V_15 ;
struct V_16 V_17 ;
int V_18 , V_19 , V_20 [ 2 ] ;
F_13 ( sizeof( V_21 ) == V_22 + 1 ) ;
F_14 ( V_23 , L_1 ,
& V_24 ) ;
V_19 = - V_25 ;
V_7 = F_15 ( L_2 ,
sizeof( struct V_4 ) ,
0 , V_26 , NULL ) ;
if ( V_7 == NULL )
goto V_27;
V_28 = F_15 ( L_3 ,
sizeof( struct V_29 ) , 0 ,
V_26 , NULL ) ;
if ( V_28 == NULL )
goto V_27;
V_30 = F_15 ( L_4 ,
sizeof( struct V_31 ) ,
0 , 0 , NULL ) ;
if ( V_30 == NULL )
goto V_27;
V_32 = F_15 ( L_5 ,
V_33 *
sizeof( struct V_34 ) ,
0 , 0 , NULL ) ;
if ( V_32 == NULL )
goto V_27;
V_35 = F_16 ( L_6 , V_36 ) ;
if ( F_17 ( V_35 ) ) {
V_19 = V_35 ? F_18 ( V_35 ) : - V_25 ;
V_35 = NULL ;
goto V_27;
}
V_37 = F_19 ( L_6 , NULL , V_38 ) ;
if ( ! V_37 ) {
V_19 = - V_25 ;
goto V_39;
}
F_20 ( V_20 , sizeof( V_20 ) ) ;
for ( V_18 = 0 ; ; V_18 ++ ) {
if ( F_21 ( V_18 , & V_15 ) == - V_40 )
break;
if ( F_22 ( F_23 ( V_15 . V_41 ) ) != V_42 )
V_20 [ 0 ] ^= F_24 ( V_15 . V_41 ) ;
}
F_25 ( & V_17 ) ;
F_26 ( V_17 . V_43 ^ V_20 [ 0 ] , V_17 . V_44 ^ V_20 [ 1 ] ) ;
V_19 = F_27 () ;
if ( V_19 != 0 )
goto V_45;
V_19 = F_28 () ;
if ( V_19 != 0 )
goto V_46;
F_29 ( V_47 ) ;
F_30 ( V_48 ) ;
F_31 ( V_49 ) ;
return 0 ;
V_46:
F_32 () ;
V_45:
F_33 ( V_37 ) ;
V_39:
F_34 ( V_35 ) ;
V_27:
F_35 ( V_7 ) ;
F_35 ( V_28 ) ;
F_35 ( V_30 ) ;
F_35 ( V_32 ) ;
return V_19 ;
}
static void T_3 F_36 ( void )
{
F_29 ( NULL ) ;
F_30 ( NULL ) ;
F_31 ( NULL ) ;
F_34 ( V_35 ) ;
F_33 ( V_37 ) ;
F_37 () ;
F_32 () ;
F_35 ( V_7 ) ;
F_35 ( V_32 ) ;
F_35 ( V_30 ) ;
F_35 ( V_28 ) ;
}
