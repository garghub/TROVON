static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( F_3 ( V_3 ) , V_6 , 1 ) ;
V_5 = F_4 ( V_7 , V_8 ) ;
if ( ! V_5 )
return NULL ;
F_5 ( & V_5 -> V_9 ) ;
return & V_5 -> V_9 ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_7 ( V_11 , struct V_1 , V_12 ) ;
struct V_4 * V_13 = F_8 ( V_1 ) ;
F_9 ( V_7 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_11 ( & V_1 -> V_12 , F_6 ) ;
}
static int T_1 F_12 ( void )
{
struct V_14 V_15 ;
struct V_16 V_17 ;
int V_18 , V_19 , V_20 [ 2 ] ;
F_13 ( sizeof( V_21 ) != V_22 + 1 ) ;
F_14 ( V_23 , L_1 ,
& V_24 ) ;
V_19 = - V_25 ;
V_7 = F_15 ( L_2 ,
sizeof( struct V_4 ) , 0 ,
V_26 | V_27 ,
NULL ) ;
if ( ! V_7 )
goto V_28;
V_29 = F_15 ( L_3 ,
sizeof( struct V_30 ) , 0 ,
V_26 , NULL ) ;
if ( ! V_29 )
goto V_28;
V_31 = F_16 ( L_4 , V_32 ) ;
if ( F_17 ( V_31 ) ) {
V_19 = V_31 ? F_18 ( V_31 ) : - V_25 ;
V_31 = NULL ;
goto V_28;
}
V_33 = F_19 ( L_4 , NULL , V_34 ) ;
if ( ! V_33 ) {
V_19 = - V_25 ;
goto V_35;
}
F_20 ( V_20 , sizeof( V_20 ) ) ;
for ( V_18 = 0 ; ; V_18 ++ ) {
if ( F_21 ( V_18 , & V_15 ) == - V_36 )
break;
if ( F_22 ( F_23 ( V_15 . V_37 ) ) != V_38 )
V_20 [ 0 ] ^= F_24 ( V_15 . V_37 ) ;
}
F_25 ( & V_17 ) ;
F_26 ( V_17 . V_39 ^ V_20 [ 0 ] , V_17 . V_40 ^ V_20 [ 1 ] ) ;
V_19 = F_27 () ;
if ( V_19 != 0 )
goto V_41;
V_42 = F_28 ( & V_43 ,
V_44 | V_45 ) ;
if ( F_29 ( V_42 ) ) {
V_19 = F_18 ( V_42 ) ;
goto V_46;
}
V_42 -> V_47 . V_48 = 0x4 ;
V_19 = F_30 () ;
if ( V_19 != 0 )
goto V_49;
F_31 ( V_50 ) ;
F_32 ( V_51 ) ;
F_33 ( V_52 ) ;
return 0 ;
V_49:
F_34 ( V_42 , & V_43 ) ;
V_46:
F_35 () ;
V_41:
F_36 ( V_33 ) ;
V_35:
F_37 ( V_31 ) ;
V_28:
F_38 ( V_7 ) ;
F_38 ( V_29 ) ;
return V_19 ;
}
static void T_2 F_39 ( void )
{
F_31 ( NULL ) ;
F_32 ( NULL ) ;
F_33 ( NULL ) ;
F_37 ( V_31 ) ;
F_36 ( V_33 ) ;
F_40 () ;
F_34 ( V_42 , & V_43 ) ;
F_35 () ;
F_38 ( V_7 ) ;
F_38 ( V_29 ) ;
}
