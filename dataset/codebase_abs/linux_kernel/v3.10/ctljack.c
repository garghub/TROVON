static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_2 -> V_6 ;
return 0 ;
}
struct V_1 *
F_2 ( const char * V_7 , int V_8 , void * V_9 )
{
struct V_1 * V_10 ;
V_10 = F_3 ( & V_11 , V_9 ) ;
if ( ! V_10 )
return NULL ;
snprintf ( V_10 -> V_12 . V_7 , sizeof( V_10 -> V_12 . V_7 ) , L_1 , V_7 ) ;
V_10 -> V_12 . V_13 = V_8 ;
V_10 -> V_6 = 0 ;
return V_10 ;
}
void F_4 ( struct V_14 * V_15 ,
struct V_1 * V_10 , bool V_16 )
{
if ( V_10 -> V_6 == V_16 )
return;
V_10 -> V_6 = V_16 ;
F_5 ( V_15 , V_17 , & V_10 -> V_12 ) ;
}
