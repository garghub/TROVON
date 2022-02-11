static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_3 ( F_4 ( V_2 ) , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_6 ( F_4 ( V_2 ) , V_3 , V_4 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! F_8 ( V_6 -> V_9 , V_10 ) )
return - V_11 ;
return F_9 ( & V_6 -> V_2 , V_8 -> V_12 , & V_13 ) ;
}
