static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_2 , V_5 ) ;
return 0 ;
}
static int F_3 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
return F_4 ( V_8 , F_1 , V_7 -> V_9 ) ;
}
int F_5 ( struct V_4 * V_5 , const char * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_10 , 0400 , NULL , V_5 , & V_13 ) ;
return V_12 ? 0 : - V_14 ;
}
