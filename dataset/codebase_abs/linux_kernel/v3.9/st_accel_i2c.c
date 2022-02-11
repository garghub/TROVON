static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_6 = F_2 ( sizeof( * V_8 ) ) ;
if ( V_6 == NULL ) {
V_9 = - V_10 ;
goto V_11;
}
V_8 = F_3 ( V_6 ) ;
V_8 -> V_12 = & V_2 -> V_12 ;
F_4 ( V_6 , V_2 , V_8 ) ;
V_9 = F_5 ( V_6 ) ;
if ( V_9 < 0 )
goto V_13;
return 0 ;
V_13:
F_6 ( V_6 ) ;
V_11:
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( F_9 ( V_2 ) ) ;
return 0 ;
}
