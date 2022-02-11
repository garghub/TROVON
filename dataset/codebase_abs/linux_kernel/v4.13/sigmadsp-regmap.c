static int F_1 ( void * V_1 ,
unsigned int V_2 , const T_1 V_3 [] , T_2 V_4 )
{
return F_2 ( V_1 , V_2 ,
V_3 , V_4 ) ;
}
static int F_3 ( void * V_1 ,
unsigned int V_2 , T_1 V_3 [] , T_2 V_4 )
{
return F_4 ( V_1 , V_2 ,
V_3 , V_4 ) ;
}
struct V_5 * F_5 ( struct V_6 * V_7 ,
struct V_8 * V_8 , const struct V_9 * V_10 ,
const char * V_11 )
{
struct V_5 * V_5 ;
V_5 = F_6 ( V_7 , V_10 , V_11 ) ;
if ( F_7 ( V_5 ) )
return V_5 ;
V_5 -> V_1 = V_8 ;
V_5 -> V_12 = F_1 ;
V_5 -> V_13 = F_3 ;
return V_5 ;
}
