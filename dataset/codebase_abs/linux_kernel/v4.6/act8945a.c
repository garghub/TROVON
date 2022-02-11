static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_6 ;
V_6 = F_2 ( V_2 , & V_7 ) ;
if ( F_3 ( V_6 ) ) {
V_5 = F_4 ( V_6 ) ;
F_5 ( & V_2 -> V_8 , L_1 , V_5 ) ;
return V_5 ;
}
F_6 ( V_2 , V_6 ) ;
V_5 = F_7 ( & V_2 -> V_8 , V_9 , V_10 ,
F_8 ( V_10 ) , NULL , 0 , NULL ) ;
if ( V_5 ) {
F_5 ( & V_2 -> V_8 , L_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_11 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_11 ) ;
}
