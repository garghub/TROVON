static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_9 = 0 ;
V_5 = F_3 ( & V_2 -> V_8 , sizeof( struct V_5 ) , V_10 ) ;
if ( V_5 == NULL )
return - V_11 ;
V_5 -> V_12 = F_4 ( V_2 , & V_13 ) ;
if ( F_5 ( V_5 -> V_12 ) ) {
V_9 = F_6 ( V_5 -> V_12 ) ;
F_7 ( & V_2 -> V_8 , L_1 ,
V_9 ) ;
return V_9 ;
}
F_8 ( V_2 , V_5 ) ;
V_5 -> V_8 = & V_2 -> V_8 ;
return F_9 ( V_5 , V_2 -> V_14 , V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_11 ( V_2 ) ;
F_12 ( V_5 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_15 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_15 ) ;
}
