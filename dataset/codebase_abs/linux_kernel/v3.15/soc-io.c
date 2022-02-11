static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_6 ;
unsigned int V_7 ;
V_6 = F_4 ( V_2 -> V_5 , V_3 , & V_7 ) ;
if ( V_6 == 0 )
return V_7 ;
else
return - 1 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_8 )
{
int V_6 ;
if ( ! V_8 )
V_2 -> V_5 = F_6 ( V_2 -> V_9 , NULL ) ;
else
V_2 -> V_5 = V_8 ;
if ( F_7 ( V_2 -> V_5 ) )
return F_8 ( V_2 -> V_5 ) ;
V_2 -> V_10 = F_1 ;
V_2 -> V_11 = F_3 ;
V_6 = F_9 ( V_2 -> V_5 ) ;
if ( V_6 > 0 )
V_2 -> V_12 = V_6 ;
V_2 -> V_13 = true ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_8 )
{
return - V_14 ;
}
