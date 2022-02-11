int F_1 ( struct V_1 * V_2 )
{
char V_3 [ V_4 ] = {} ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = (struct V_7 * ) F_2 ( V_2 ) ;
V_6 = _ ( V_8 -> V_6 ) ;
V_9 = _ ( V_8 -> V_9 ) ;
F_3 ( V_3 , sizeof( V_3 ) , V_6 -> V_10 ) ;
if ( V_3 [ 0 ] == 'l' && V_3 [ 1 ] == 'o' ) {
char V_11 [] = L_1 ;
F_4 ( V_11 , sizeof( V_11 ) , V_8 , V_9 ) ;
}
return 0 ;
}
