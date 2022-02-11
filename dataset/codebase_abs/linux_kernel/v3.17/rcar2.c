static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
V_6 = F_3 ( & V_2 -> V_7 , 0 ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
V_4 -> V_6 = V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_6 )
return 0 ;
F_7 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
void T_1 * V_8 , int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_6 )
return - V_10 ;
if ( V_9 ) {
int V_11 = F_9 ( V_4 -> V_6 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_4 -> V_6 , 0 ) ;
return V_11 ;
}
F_10 ( V_4 -> V_6 , 1 ) ;
F_11 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return V_12 ;
}
