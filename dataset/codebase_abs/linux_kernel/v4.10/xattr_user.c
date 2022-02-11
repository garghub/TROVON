static int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 , const char * V_6 , void * V_7 , T_1 V_8 )
{
if ( ! F_2 ( V_5 -> V_9 ) )
return - V_10 ;
return F_3 ( V_5 , F_4 ( V_2 , V_6 ) ,
V_7 , V_8 ) ;
}
static int
F_5 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 , const char * V_6 , const void * V_7 ,
T_1 V_8 , int V_11 )
{
if ( ! F_2 ( V_5 -> V_9 ) )
return - V_10 ;
return F_6 ( V_5 ,
F_4 ( V_2 , V_6 ) ,
V_7 , V_8 , V_11 ) ;
}
static bool F_7 ( struct V_3 * V_3 )
{
return F_2 ( V_3 -> V_12 ) ;
}
