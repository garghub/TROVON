T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_1 * F_2 ( void )
{
return ( & V_2 ) ;
}
static int F_3 ( T_2 * V_3 , const unsigned char * V_4 ,
const unsigned char * V_5 , int V_6 )
{
memcpy ( & ( V_3 -> V_7 . V_8 . V_4 [ 0 ] ) , V_4 , F_4 ( V_3 ) ) ;
F_5 ( & ( V_3 -> V_7 . V_8 . V_9 ) , F_4 ( V_3 ) ,
V_3 -> V_7 . V_8 . V_4 ) ;
return 1 ;
}
static int F_6 ( T_2 * V_3 , unsigned char * V_10 ,
const unsigned char * V_11 , unsigned int V_12 )
{
F_7 ( & ( V_3 -> V_7 . V_8 . V_9 ) , V_12 , V_11 , V_10 ) ;
return 1 ;
}
