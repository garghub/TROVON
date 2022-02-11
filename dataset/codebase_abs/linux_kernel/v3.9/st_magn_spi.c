static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( sizeof( * V_6 ) ) ;
if ( V_4 == NULL ) {
V_7 = - V_8 ;
goto V_9;
}
V_6 = F_3 ( V_4 ) ;
V_6 -> V_10 = & V_2 -> V_10 ;
F_4 ( V_4 , V_2 , V_6 ) ;
V_7 = F_5 ( V_4 ) ;
if ( V_7 < 0 )
goto V_11;
return 0 ;
V_11:
F_6 ( V_4 ) ;
V_9:
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_8 ( V_2 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
