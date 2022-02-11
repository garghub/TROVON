static int T_1 F_1 ( void )
{
struct V_1 * V_2 = V_3 ;
int V_4 , V_5 , V_6 = 0 ;
V_5 = sizeof( V_3 ) / sizeof( struct V_1 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_2 [ V_4 ] . V_7 = F_2 ( V_2 [ V_4 ] . V_8 ) ;
F_3 ( L_1 , V_4 , V_2 [ V_4 ] . V_8 ,
V_2 [ V_4 ] . V_7 ) ;
if ( V_2 [ V_4 ] . V_7 == - 1 )
continue;
if ( V_4 != V_6 )
V_2 [ V_6 ] = V_2 [ V_4 ] ;
V_6 ++ ;
}
if ( V_6 ) {
V_9 . V_10 = V_6 ;
return F_4 ( & V_11 ) ;
}
return 0 ;
}
