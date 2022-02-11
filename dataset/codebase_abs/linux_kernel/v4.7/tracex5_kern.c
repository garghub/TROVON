int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_2 ( & V_4 , sizeof( V_4 ) , ( void * ) F_3 ( V_2 ) ) ;
F_4 ( V_2 , & V_5 , V_4 . V_6 ) ;
if ( V_4 . V_6 >= V_7 && V_4 . V_6 <= V_8 ) {
char V_9 [] = L_1 ;
F_5 ( V_9 , sizeof( V_9 ) , V_4 . V_6 ) ;
}
return 0 ;
}
T_1 (F_6)( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_2 ( & V_4 , sizeof( V_4 ) , ( void * ) F_3 ( V_2 ) ) ;
if ( V_4 . args [ 2 ] == 512 ) {
char V_9 [] = L_2 ;
F_5 ( V_9 , sizeof( V_9 ) ,
V_4 . args [ 0 ] , V_4 . args [ 1 ] , V_4 . args [ 2 ] ) ;
}
return 0 ;
}
T_1 (F_7)( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_2 ( & V_4 , sizeof( V_4 ) , ( void * ) F_3 ( V_2 ) ) ;
if ( V_4 . args [ 2 ] > 128 && V_4 . args [ 2 ] <= 1024 ) {
char V_9 [] = L_3 ;
F_5 ( V_9 , sizeof( V_9 ) ,
V_4 . args [ 0 ] , V_4 . args [ 1 ] , V_4 . args [ 2 ] ) ;
}
return 0 ;
}
T_1 (F_8)( struct V_1 * V_2 )
{
char V_9 [] = L_4 ;
F_5 ( V_9 , sizeof( V_9 ) ) ;
return 0 ;
}
