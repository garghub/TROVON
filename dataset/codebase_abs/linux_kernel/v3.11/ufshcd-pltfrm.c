static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_4 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_6 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
void T_1 * V_8 ;
struct V_9 * V_10 ;
int V_7 , V_11 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
V_10 = F_8 ( V_4 , V_12 , 0 ) ;
if ( ! V_10 ) {
F_9 ( V_2 , L_1 ) ;
V_11 = - V_13 ;
goto V_14;
}
V_8 = F_10 ( V_2 , V_10 ) ;
if ( F_11 ( V_8 ) ) {
F_9 ( V_2 , L_2 ) ;
V_11 = F_12 ( V_8 ) ;
goto V_14;
}
V_7 = F_13 ( V_4 , 0 ) ;
if ( V_7 < 0 ) {
F_9 ( V_2 , L_3 ) ;
V_11 = - V_13 ;
goto V_14;
}
V_11 = F_14 ( V_2 , & V_6 , V_8 , V_7 ) ;
if ( V_11 ) {
F_9 ( V_2 , L_4 ) ;
goto V_14;
}
F_15 ( V_4 , V_6 ) ;
V_14:
return V_11 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_4 ( V_6 -> V_7 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
