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
int V_6 ;
V_3 = F_6 ( V_5 -> V_7 ) ;
if ( ! V_3 ) {
F_7 ( L_2 , V_5 -> V_8 ) ;
return - V_9 ;
}
V_6 = F_8 ( V_5 ) ;
F_4 ( V_3 ) ;
return V_6 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_3 ;
T_1 V_10 = V_11 ;
V_3 = F_6 ( V_5 -> V_7 ) ;
if ( ! V_3 ) {
F_10 ( L_3 ) ;
return V_11 ;
}
F_11 ( V_3 , L_4 , & V_10 ) ;
F_4 ( V_3 ) ;
F_12 ( L_5 , V_12 , V_10 ) ;
return V_10 ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( 0 ) ;
if ( ! V_3 )
return - V_15 ;
F_4 ( V_3 ) ;
return F_14 ( & V_16 ) ;
}
static int F_15 ( struct V_13 * V_14 )
{
F_16 ( & V_16 ) ;
return 0 ;
}
