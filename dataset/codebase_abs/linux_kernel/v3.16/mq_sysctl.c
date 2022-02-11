static void * F_1 ( struct V_1 * V_2 )
{
char * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_7 -> V_8 -> V_6 ;
V_3 = ( V_3 - ( char * ) & V_9 ) + ( char * ) V_6 ;
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_3 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_5 ( & V_14 , V_10 , V_11 ,
V_12 , V_13 ) ;
}
struct V_15 * F_6 ( void )
{
return F_7 ( V_16 ) ;
}
