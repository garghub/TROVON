int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {} ;
F_2 ( & V_4 , sizeof( V_4 ) , ( void * ) V_2 -> V_5 ) ;
F_3 ( V_2 , & V_6 , V_4 . V_7 ) ;
if ( V_4 . V_7 >= V_8 && V_4 . V_7 <= V_9 ) {
char V_10 [] = L_1 ;
F_4 ( V_10 , sizeof( V_10 ) , V_4 . V_7 ) ;
}
return 0 ;
}
T_1 (F_5)( struct V_1 * V_2 )
{
struct V_3 V_4 = {} ;
F_2 ( & V_4 , sizeof( V_4 ) , ( void * ) V_2 -> V_5 ) ;
if ( V_4 . args [ 2 ] == 512 ) {
char V_10 [] = L_2 ;
F_4 ( V_10 , sizeof( V_10 ) ,
V_4 . args [ 0 ] , V_4 . args [ 1 ] , V_4 . args [ 2 ] ) ;
}
return 0 ;
}
T_1 (F_6)( struct V_1 * V_2 )
{
struct V_3 V_4 = {} ;
F_2 ( & V_4 , sizeof( V_4 ) , ( void * ) V_2 -> V_5 ) ;
if ( V_4 . args [ 2 ] > 128 && V_4 . args [ 2 ] <= 1024 ) {
char V_10 [] = L_3 ;
F_4 ( V_10 , sizeof( V_10 ) ,
V_4 . args [ 0 ] , V_4 . args [ 1 ] , V_4 . args [ 2 ] ) ;
}
return 0 ;
}
T_1 (F_7)( struct V_1 * V_2 )
{
char V_10 [] = L_4 ;
F_4 ( V_10 , sizeof( V_10 ) ) ;
return 0 ;
}
