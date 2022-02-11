static int F_1 ( struct V_1 * V_1 , int V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
* V_4 = ( V_5 & V_3 ) ? 1 : 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , int V_2 ,
int V_7 , bool V_8 )
{
return F_4 ( V_1 , V_2 , V_7 , V_8 ? 1 : 0 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 -> V_13 . V_14 ) ;
return F_7 ( & V_10 -> V_13 ,
F_8 ( V_10 -> V_13 . V_14 ) ,
V_12 -> V_1 ,
& V_15 ) ;
}
