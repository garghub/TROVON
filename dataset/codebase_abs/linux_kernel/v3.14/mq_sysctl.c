static void * F_1 ( T_1 * V_1 )
{
char * V_2 = V_1 -> V_3 ;
struct V_4 * V_5 = V_6 -> V_7 -> V_5 ;
V_2 = ( V_2 - ( char * ) & V_8 ) + ( char * ) V_5 ;
return V_2 ;
}
static int F_2 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
return F_3 ( & V_13 , V_9 , V_10 , V_11 , V_12 ) ;
}
static int F_4 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
return F_5 ( & V_13 , V_9 , V_10 ,
V_11 , V_12 ) ;
}
struct V_14 * F_6 ( void )
{
return F_7 ( V_15 ) ;
}
