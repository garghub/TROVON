void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
}
static bool V_4 ( struct V_7 * V_8 , struct V_9 * V_10 ,
enum V_11 type , unsigned int V_12 )
{
int V_13 ;
V_13 = F_2 ( V_10 , V_14 , & V_8 -> V_15 ) ;
if ( V_13 != 0 )
return false ;
V_8 -> V_16 = V_8 -> V_15 -> V_17 ;
V_8 -> V_18 = V_8 -> V_15 -> V_19 ;
memset ( V_8 -> V_18 , 0 , V_14 ) ;
return true ;
}
static void V_6 ( struct V_7 * V_8 )
{
F_3 ( V_8 -> V_10 , V_8 -> V_15 ) ;
}
