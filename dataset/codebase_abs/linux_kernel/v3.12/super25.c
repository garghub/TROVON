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
int F_12 ( void )
{
V_7 = F_13 ( L_1 ,
sizeof( struct V_4 ) ,
0 , V_14 , NULL ) ;
if ( V_7 == NULL )
return - V_15 ;
return 0 ;
}
void F_14 ( void )
{
F_15 ( V_7 ) ;
}
static int T_1 F_16 ( void )
{
int V_16 , V_17 , V_18 [ 2 ] ;
struct V_19 V_20 ;
T_2 V_21 ;
F_17 ( sizeof( V_22 ) == V_23 + 1 ) ;
F_18 ( V_24 , L_2 ,
& V_25 ) ;
V_17 = F_12 () ;
if ( V_17 )
return - V_15 ;
V_26 = F_13 ( L_3 ,
sizeof( struct V_27 ) , 0 ,
V_14 , NULL ) ;
if ( V_26 == NULL ) {
F_14 () ;
return - V_15 ;
}
V_28 = F_13 ( L_4 ,
sizeof( struct V_29 ) ,
0 , 0 , NULL ) ;
if ( V_28 == NULL ) {
F_15 ( V_26 ) ;
V_26 = NULL ;
F_14 () ;
return - V_15 ;
}
V_30 = F_13 ( L_5 ,
V_31 *
sizeof( struct V_32 ) ,
0 , 0 , NULL ) ;
if ( V_30 == NULL ) {
F_15 ( V_28 ) ;
V_28 = NULL ;
F_15 ( V_26 ) ;
V_26 = NULL ;
F_14 () ;
return - V_15 ;
}
V_33 = V_34 ?
F_19 ( L_6 , V_34 , NULL , NULL ) : NULL ;
F_20 ( V_35 ) ;
F_21 ( V_36 ) ;
F_22 ( V_37 ) ;
F_23 ( V_18 , sizeof( V_18 ) ) ;
for ( V_16 = 0 ; ; V_16 ++ ) {
if ( F_24 ( V_16 , & V_21 ) == - V_38 ) {
break;
}
if ( F_25 ( F_26 ( V_21 . V_39 ) ) != V_40 ) {
V_18 [ 0 ] ^= F_27 ( V_21 . V_39 ) ;
}
}
F_28 ( & V_20 ) ;
F_29 ( V_20 . V_41 ^ V_18 [ 0 ] , V_20 . V_42 ^ V_18 [ 1 ] ) ;
F_30 ( & V_43 ) ;
V_43 . V_44 = V_45 ;
V_17 = F_31 () ;
if ( V_17 == 0 )
V_17 = F_32 () ;
return V_17 ;
}
static void T_3 F_33 ( void )
{
F_34 () ;
F_35 ( & V_43 ) ;
F_36 () ;
F_37 ( V_46 [ V_47 ] == 0 ,
L_7 ,
V_46 [ V_47 ] ) ;
F_20 ( NULL ) ;
F_21 ( NULL ) ;
F_22 ( NULL ) ;
F_14 () ;
F_15 ( V_30 ) ;
V_30 = NULL ;
F_15 ( V_28 ) ;
V_28 = NULL ;
F_15 ( V_26 ) ;
if ( V_33 && ! F_38 ( V_33 ) )
F_39 ( & V_33 ) ;
}
