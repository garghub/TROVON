static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
}
static void F_5 ( struct V_1 * V_2 )
{
}
static void F_6 ( struct V_1 * V_2 )
{
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
}
static void
F_8 ( struct V_1 * V_2 , int V_4 )
{
}
struct V_1 * F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
F_11 ( V_7 , V_2 , & V_9 , V_10 ,
NULL ) ;
F_12 ( V_2 , & V_11 ) ;
V_2 -> V_12 = 1 ;
return V_2 ;
}
