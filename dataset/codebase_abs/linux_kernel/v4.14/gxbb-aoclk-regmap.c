static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 , V_6 ,
F_4 ( V_4 -> V_7 ) , F_4 ( V_4 -> V_7 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
F_4 ( V_4 -> V_7 ) , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_8 ;
int V_9 ;
V_9 = F_7 ( V_4 -> V_5 , V_6 , & V_8 ) ;
if ( V_9 )
return V_9 ;
return ( V_8 & F_4 ( V_4 -> V_7 ) ) != 0 ;
}
