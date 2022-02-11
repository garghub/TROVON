static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_9 ;
if ( ! V_8 ) {
V_8 = F_3 ( V_4 , sizeof( * V_8 ) , V_10 ) ;
* V_8 = V_11 ;
}
V_6 = F_4 ( V_4 , sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return - V_12 ;
V_6 -> V_13 = F_5 ( V_4 , NULL ) ;
if ( ! F_6 ( V_6 -> V_13 ) ) {
V_9 = F_7 ( V_6 -> V_13 ) ;
if ( V_9 ) {
F_8 ( V_4 , L_1 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_9 ( V_4 , F_10 ( 32 ) ) ;
if ( V_9 )
goto V_14;
V_8 -> V_15 = F_11 ( V_4 ) ;
V_6 -> V_16 = F_12 ( V_4 , V_2 -> V_17 ,
V_2 -> V_18 , V_8 ) ;
if ( F_6 ( V_6 -> V_16 ) ) {
V_9 = F_13 ( V_6 -> V_16 ) ;
if ( V_9 != - V_19 )
F_8 ( V_4 ,
L_2 ,
V_9 ) ;
goto V_14;
}
F_14 ( V_2 , V_6 ) ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
return 0 ;
V_14:
if ( ! F_6 ( V_6 -> V_13 ) )
F_17 ( V_6 -> V_13 ) ;
return V_9 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_19 ( V_2 ) ;
F_20 ( & V_2 -> V_4 ) ;
F_21 ( V_6 -> V_16 ) ;
F_17 ( V_6 -> V_13 ) ;
return 0 ;
}
