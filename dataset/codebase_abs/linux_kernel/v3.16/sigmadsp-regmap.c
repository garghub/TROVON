static int F_1 ( void * V_1 ,
const struct V_2 * V_3 , T_1 V_4 )
{
return F_2 ( V_1 , F_3 ( V_3 -> V_5 ) ,
V_3 -> V_6 , V_4 - 2 ) ;
}
int F_4 ( struct V_7 * V_8 , struct V_9 * V_9 ,
const char * V_10 )
{
struct V_11 V_12 ;
V_12 . V_1 = V_9 ;
V_12 . V_13 = F_1 ;
return F_5 ( V_8 , & V_12 , V_10 ) ;
}
