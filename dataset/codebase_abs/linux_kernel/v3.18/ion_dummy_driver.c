static int T_1 F_1 ( void )
{
int V_1 , V_2 ;
V_3 = F_2 ( NULL ) ;
V_4 = F_3 ( V_5 . V_6 , sizeof( struct V_7 * ) ,
V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_10 = F_4 (
V_11 [ V_12 ] . V_13 ,
V_8 ) ;
if ( V_10 )
V_11 [ V_12 ] . V_14 =
F_5 ( V_10 ) ;
else
F_6 ( L_1 ) ;
V_15 = F_4 (
V_11 [ V_16 ] . V_13 ,
V_8 ) ;
if ( V_15 )
V_11 [ V_16 ] . V_14 = F_5 ( V_15 ) ;
else
F_6 ( L_2 ) ;
for ( V_1 = 0 ; V_1 < V_5 . V_6 ; V_1 ++ ) {
struct V_17 * V_18 = & V_5 . V_4 [ V_1 ] ;
if ( V_18 -> type == V_12 &&
! V_18 -> V_14 )
continue;
if ( V_18 -> type == V_16 && ! V_18 -> V_14 )
continue;
V_4 [ V_1 ] = F_7 ( V_18 ) ;
if ( F_8 ( V_4 [ V_1 ] ) ) {
V_2 = F_9 ( V_4 [ V_1 ] ) ;
goto V_2;
}
F_10 ( V_3 , V_4 [ V_1 ] ) ;
}
return 0 ;
V_2:
for ( V_1 = 0 ; V_1 < V_5 . V_6 ; V_1 ++ ) {
if ( V_4 [ V_1 ] )
F_11 ( V_4 [ V_1 ] ) ;
}
F_12 ( V_4 ) ;
if ( V_10 ) {
F_13 ( V_10 ,
V_11 [ V_12 ] . V_13 ) ;
V_10 = NULL ;
}
if ( V_15 ) {
F_13 ( V_15 ,
V_11 [ V_16 ] . V_13 ) ;
V_15 = NULL ;
}
return V_2 ;
}
static void T_2 F_14 ( void )
{
int V_1 ;
F_15 ( V_3 ) ;
for ( V_1 = 0 ; V_1 < V_5 . V_6 ; V_1 ++ )
F_11 ( V_4 [ V_1 ] ) ;
F_12 ( V_4 ) ;
if ( V_10 ) {
F_13 ( V_10 ,
V_11 [ V_12 ] . V_13 ) ;
V_10 = NULL ;
}
if ( V_15 ) {
F_13 ( V_15 ,
V_11 [ V_16 ] . V_13 ) ;
V_15 = NULL ;
}
}
