static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( V_2 , & V_4 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_7 = F_5 ( V_6 , 0 ) ;
if ( V_7 < 0 ) {
F_6 ( V_6 ) ;
return V_7 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_8 = F_8 ( V_2 ) ;
F_9 ( V_8 ) ;
return 0 ;
}
