static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
int V_6 ;
V_7 = F_2 ( L_1 ,
- 1 , NULL , 0 ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
V_4 -> V_8 = & V_2 -> V_8 ;
V_6 = F_5 ( V_4 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_8 , L_2 ,
V_6 ) ;
F_7 ( V_7 ) ;
}
return V_6 ;
}
static int T_2 F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_9 ( V_2 ) ;
F_10 ( V_4 ) ;
F_7 ( V_7 ) ;
return 0 ;
}
