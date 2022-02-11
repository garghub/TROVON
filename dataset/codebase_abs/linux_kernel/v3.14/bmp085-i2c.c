static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 != V_6 )
return - V_7 ;
return F_2 ( & V_2 -> V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_9 * V_10 )
{
int V_11 ;
struct V_12 * V_12 = F_4 ( V_2 ,
& V_13 ) ;
if ( F_5 ( V_12 ) ) {
V_11 = F_6 ( V_12 ) ;
F_7 ( & V_2 -> V_8 , L_1 , V_11 ) ;
return V_11 ;
}
return F_8 ( & V_2 -> V_8 , V_12 , V_2 -> V_14 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( & V_2 -> V_8 ) ;
}
