static void * F_1 ( void * V_1 , T_1 * V_2 ,
int V_3 )
{
if ( V_2 -> type == V_4 ) {
F_2 ((L_1))
return ( NULL ) ;
} else if ( V_2 -> type == V_5 ) {
if ( V_3 ) {
F_3 () ;
} else {
F_4 ( L_2 , V_6 , V_7 ) ;
}
}
return ( NULL ) ;
}
static int T_2 F_5 ( void )
{
int V_8 = 0 ;
int V_9 = 0 ;
T_3 V_10 ;
T_1 V_11 [ V_12 ] ;
F_6 ( V_11 , sizeof( V_11 ) ) ;
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ ) {
if ( V_11 [ V_8 ] . type == V_4 ) {
V_9 = 1 ;
memcpy ( & V_13 , & V_11 [ V_8 ] , sizeof( V_13 ) ) ;
V_10 . V_14 . V_15 . V_16 = 0 ;
V_10 . V_14 . V_15 . V_17 =
V_18 ;
V_10 . V_14 . V_19 . V_20 = ( void * ) F_1 ;
V_10 . V_14 . V_19 . V_1 = NULL ;
V_13 . V_21 ( ( V_22 * ) & V_10 ) ;
if ( V_10 . V_14 . V_15 . V_17 != 0xff )
return ( 0 ) ;
V_23 = V_10 . V_14 . V_19 . V_24 ;
} else if ( V_11 [ V_8 ] . type == V_5 ) {
F_4 ( L_2 , V_6 , V_7 ) ;
}
}
return ( V_9 ) ;
}
static void T_4 F_7 ( void )
{
T_3 V_10 ;
V_10 . V_14 . V_15 . V_16 = 0 ;
V_10 . V_14 . V_15 . V_17 = V_25 ;
V_10 . V_14 . V_19 . V_24 = V_23 ;
V_13 . V_21 ( ( V_22 * ) & V_10 ) ;
}
int T_2 F_8 ( void )
{
F_9 () ;
if ( ! F_5 () ) {
F_2 ((L_3))
F_10 () ;
return ( 0 ) ;
}
return ( 1 ) ;
}
void T_4 F_11 ( void )
{
F_3 () ;
F_7 () ;
F_10 () ;
}
