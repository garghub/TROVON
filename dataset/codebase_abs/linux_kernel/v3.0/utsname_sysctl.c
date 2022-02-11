static void * F_1 ( T_1 * V_1 , int V_2 )
{
char * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 ;
V_6 = V_7 -> V_8 -> V_6 ;
V_3 = ( V_3 - ( char * ) & V_9 ) + ( char * ) V_6 ;
if ( ! V_2 )
F_2 ( & V_10 ) ;
else
F_3 ( & V_10 ) ;
return V_3 ;
}
static void F_4 ( T_1 * V_1 , int V_2 , void * V_3 )
{
if ( ! V_2 )
F_5 ( & V_10 ) ;
else
F_6 ( & V_10 ) ;
}
static int F_7 ( T_1 * V_1 , int V_2 ,
void T_2 * V_11 , T_3 * V_12 , T_4 * V_13 )
{
struct T_1 V_14 ;
int V_15 ;
memcpy ( & V_14 , V_1 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_1 , V_2 ) ;
V_15 = F_8 ( & V_14 , V_2 , V_11 , V_12 , V_13 ) ;
F_4 ( V_1 , V_2 , V_14 . V_4 ) ;
return V_15 ;
}
static int T_5 F_9 ( void )
{
F_10 ( V_16 ) ;
return 0 ;
}
