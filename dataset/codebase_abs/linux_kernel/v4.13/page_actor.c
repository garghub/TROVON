static void * F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
return V_2 -> V_4 [ 0 ] ;
}
static void * F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_2 -> V_5 )
return NULL ;
return V_2 -> V_4 [ V_2 -> V_3 ++ ] ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
struct V_1 * F_4 ( void * * V_4 ,
int V_5 , int V_6 )
{
struct V_1 * V_2 = F_5 ( sizeof( * V_2 ) , V_7 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_6 = V_6 ? : V_5 * V_8 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = 0 ;
V_2 -> V_9 = F_1 ;
V_2 -> V_10 = F_2 ;
V_2 -> V_11 = F_3 ;
return V_2 ;
}
static void * F_6 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
return V_2 -> V_12 = F_7 ( V_2 -> V_13 [ 0 ] ) ;
}
static void * F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
F_9 ( V_2 -> V_12 ) ;
return V_2 -> V_12 = V_2 -> V_3 == V_2 -> V_5 ? NULL :
F_7 ( V_2 -> V_13 [ V_2 -> V_3 ++ ] ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
F_9 ( V_2 -> V_12 ) ;
}
struct V_1 * F_11 ( struct V_13 * * V_13 ,
int V_5 , int V_6 )
{
struct V_1 * V_2 = F_5 ( sizeof( * V_2 ) , V_7 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_6 = V_6 ? : V_5 * V_8 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = 0 ;
V_2 -> V_12 = NULL ;
V_2 -> V_9 = F_6 ;
V_2 -> V_10 = F_8 ;
V_2 -> V_11 = F_10 ;
return V_2 ;
}
