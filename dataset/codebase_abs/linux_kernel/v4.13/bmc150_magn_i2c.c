static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
const char * V_6 = NULL ;
V_5 = F_2 ( V_2 , & V_7 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( & V_2 -> V_8 , L_1 ) ;
return F_5 ( V_5 ) ;
}
if ( V_4 )
V_6 = V_4 -> V_6 ;
return F_6 ( & V_2 -> V_8 , V_5 , V_2 -> V_9 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_8 ) ;
}
