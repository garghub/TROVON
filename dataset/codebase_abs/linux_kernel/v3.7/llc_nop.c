static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_5 ,
int V_6 , int * V_7 , int * V_8 ,
T_3 V_9 )
{
struct V_10 * V_10 ;
* V_7 = 0 ;
* V_8 = 0 ;
V_10 = F_2 ( sizeof( struct V_10 ) , V_11 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_2 = V_2 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_9 = V_9 ;
return V_10 ;
}
static void F_3 ( struct V_12 * V_13 )
{
F_4 ( F_5 ( V_13 ) ) ;
}
static int F_6 ( struct V_12 * V_13 )
{
return 0 ;
}
static int F_7 ( struct V_12 * V_13 )
{
return 0 ;
}
static void F_8 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_10 * V_10 = F_5 ( V_13 ) ;
V_10 -> V_4 ( V_10 -> V_2 , V_15 ) ;
}
static int F_9 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_10 * V_10 = F_5 ( V_13 ) ;
return V_10 -> V_3 ( V_10 -> V_2 , V_15 ) ;
}
int F_10 ( void )
{
return F_11 ( V_16 , & V_17 ) ;
}
