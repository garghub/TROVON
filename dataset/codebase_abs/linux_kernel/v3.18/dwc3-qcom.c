static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( & V_2 -> V_5 , sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return - V_11 ;
F_3 ( V_2 , V_8 ) ;
V_8 -> V_5 = & V_2 -> V_5 ;
V_8 -> V_12 = F_4 ( V_8 -> V_5 , L_1 ) ;
if ( F_5 ( V_8 -> V_12 ) ) {
F_6 ( V_8 -> V_5 , L_2 ) ;
return F_7 ( V_8 -> V_12 ) ;
}
V_8 -> V_13 = F_4 ( V_8 -> V_5 , L_3 ) ;
if ( F_5 ( V_8 -> V_13 ) ) {
F_8 ( V_8 -> V_5 , L_4 ) ;
V_8 -> V_13 = NULL ;
}
V_8 -> V_14 = F_4 ( V_8 -> V_5 , L_5 ) ;
if ( F_5 ( V_8 -> V_14 ) ) {
F_8 ( V_8 -> V_5 , L_6 ) ;
V_8 -> V_14 = NULL ;
}
V_9 = F_9 ( V_8 -> V_12 ) ;
if ( V_9 ) {
F_6 ( V_8 -> V_5 , L_7 ) ;
goto V_15;
}
V_9 = F_9 ( V_8 -> V_13 ) ;
if ( V_9 ) {
F_6 ( V_8 -> V_5 , L_8 ) ;
goto V_16;
}
V_9 = F_9 ( V_8 -> V_14 ) ;
if ( V_9 ) {
F_6 ( V_8 -> V_5 , L_9 ) ;
goto V_17;
}
V_9 = F_10 ( V_4 , NULL , NULL , V_8 -> V_5 ) ;
if ( V_9 ) {
F_6 ( V_8 -> V_5 , L_10 , V_9 ) ;
goto V_18;
}
return 0 ;
V_18:
F_11 ( V_8 -> V_14 ) ;
V_17:
F_11 ( V_8 -> V_13 ) ;
V_16:
F_11 ( V_8 -> V_12 ) ;
V_15:
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_5 ) ;
F_11 ( V_8 -> V_14 ) ;
F_11 ( V_8 -> V_13 ) ;
F_11 ( V_8 -> V_12 ) ;
return 0 ;
}
