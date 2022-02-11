static int F_1 ( struct V_1 * V_2 )
{
return V_3 -> V_4 ( V_2 ) ;
}
static int F_2 ( const struct V_5 * V_5 )
{
int V_6 ;
struct V_1 * V_2 = F_3 ( F_4 ( V_5 ) ) ;
V_6 = V_3 -> V_7 ( V_2 ) ;
if ( V_6 ) {
F_5 ( V_2 , L_1 ) ;
return V_6 ;
}
V_6 = F_6 ( V_2 , V_5 ) ;
if ( V_6 )
F_7 ( V_2 , L_2 ,
V_8 , V_6 ) ;
return V_6 ;
}
static int F_8 ( struct V_9 * V_10 )
{
V_3 = F_9 () ;
if ( ! V_3 )
return - V_11 ;
return F_10 ( & V_12 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
F_12 ( & V_12 ) ;
V_3 = NULL ;
return 0 ;
}
