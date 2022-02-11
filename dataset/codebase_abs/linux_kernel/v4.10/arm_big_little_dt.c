static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
if ( ! F_3 ( V_3 , L_1 , NULL ) ) {
F_4 ( V_3 ) ;
V_3 = NULL ;
}
return V_3 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_3 ;
T_1 V_6 = V_7 ;
V_3 = F_6 ( V_5 -> V_8 ) ;
if ( ! V_3 ) {
F_7 ( L_2 ) ;
return V_7 ;
}
F_8 ( V_3 , L_3 , & V_6 ) ;
F_4 ( V_3 ) ;
F_9 ( L_4 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( 0 ) ;
if ( ! V_3 )
return - V_12 ;
F_4 ( V_3 ) ;
return F_11 ( & V_13 ) ;
}
static int F_12 ( struct V_10 * V_11 )
{
F_13 ( & V_13 ) ;
return 0 ;
}
