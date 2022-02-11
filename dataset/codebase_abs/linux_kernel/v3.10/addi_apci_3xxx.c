static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
const struct V_4 * V_5 = NULL ;
if ( V_3 < F_2 ( V_6 ) )
V_5 = & V_6 [ V_3 ] ;
if ( ! V_5 )
return - V_7 ;
V_2 -> V_8 = V_5 ;
return F_3 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_9 * V_2 ,
const struct V_10 * V_11 )
{
return F_5 ( V_2 , & V_12 , V_11 -> V_13 ) ;
}
