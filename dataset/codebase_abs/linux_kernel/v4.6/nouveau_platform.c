static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
int V_9 ;
V_4 = F_2 ( & V_2 -> V_10 ) ;
V_8 = F_3 ( V_4 , V_2 , & V_6 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
V_9 = F_6 ( V_8 , 0 ) ;
if ( V_9 < 0 ) {
F_7 ( V_8 ) ;
return V_9 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_10 = F_9 ( V_2 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
