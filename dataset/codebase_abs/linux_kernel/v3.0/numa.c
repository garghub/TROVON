void T_1 F_1 ( int V_1 , int V_2 )
{
int V_3 ;
if ( V_2 < 0 ) {
V_4 [ V_1 ] = 0 ;
return;
}
V_3 = V_4 [ V_1 ] ;
if ( F_2 ( V_1 , V_5 [ V_3 ] ) ) {
return;
}
if ( ! F_3 ( V_2 ) )
V_2 = V_6 ;
V_4 [ V_1 ] = V_2 ;
F_4 ( V_1 , V_5 [ V_2 ] ) ;
return;
}
void T_1 F_5 ( int V_1 , int V_2 )
{
F_6 ( ! F_2 ( V_1 , V_5 [ V_2 ] ) ) ;
F_6 ( V_4 [ V_1 ] != V_2 ) ;
V_4 [ V_1 ] = 0 ;
F_7 ( V_1 , V_5 [ V_2 ] ) ;
}
void T_2 F_8 ( void )
{
int V_1 , V_7 , V_8 ;
for( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_9 ( V_5 [ V_8 ] ) ;
F_10 (cpu) {
V_8 = - 1 ;
for ( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
if ( F_11 ( V_1 ) == V_11 [ V_7 ] . V_12 ) {
V_8 = V_11 [ V_7 ] . V_2 ;
break;
}
F_1 ( V_1 , V_8 ) ;
}
}
