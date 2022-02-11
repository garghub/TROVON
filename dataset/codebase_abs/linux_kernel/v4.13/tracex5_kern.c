int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( int ) F_2 ( V_2 ) ;
F_3 ( V_2 , & V_4 , V_3 ) ;
if ( V_3 >= V_5 && V_3 <= V_6 ) {
char V_7 [] = L_1 ;
F_4 ( V_7 , sizeof( V_7 ) , V_3 ) ;
}
return 0 ;
}
T_1 (F_5)( struct V_1 * V_2 )
{
struct V_8 V_9 ;
F_6 ( & V_9 , sizeof( V_9 ) , ( void * ) F_7 ( V_2 ) ) ;
if ( V_9 . args [ 2 ] == 512 ) {
char V_7 [] = L_2 ;
F_4 ( V_7 , sizeof( V_7 ) ,
V_9 . args [ 0 ] , V_9 . args [ 1 ] , V_9 . args [ 2 ] ) ;
}
return 0 ;
}
T_1 (F_8)( struct V_1 * V_2 )
{
struct V_8 V_9 ;
F_6 ( & V_9 , sizeof( V_9 ) , ( void * ) F_7 ( V_2 ) ) ;
if ( V_9 . args [ 2 ] > 128 && V_9 . args [ 2 ] <= 1024 ) {
char V_7 [] = L_3 ;
F_4 ( V_7 , sizeof( V_7 ) ,
V_9 . args [ 0 ] , V_9 . args [ 1 ] , V_9 . args [ 2 ] ) ;
}
return 0 ;
}
T_1 (F_9)( struct V_1 * V_2 )
{
char V_7 [] = L_4 ;
F_4 ( V_7 , sizeof( V_7 ) ) ;
return 0 ;
}
