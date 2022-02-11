static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_9 ;
const struct V_10 * V_11 ;
if ( ! V_8 ) {
V_8 = F_3 ( V_4 , sizeof( * V_8 ) , V_12 ) ;
* V_8 = V_13 ;
}
V_11 = F_4 ( V_14 , & V_2 -> V_4 ) ;
if ( V_11 && V_11 -> V_15 ) {
* V_8 = * (struct V_7 * ) V_11 -> V_15 ;
}
V_6 = F_5 ( V_4 , sizeof( * V_6 ) , V_12 ) ;
if ( ! V_6 )
return - V_16 ;
V_6 -> V_17 = F_6 ( V_4 , NULL ) ;
if ( ! F_7 ( V_6 -> V_17 ) ) {
V_9 = F_8 ( V_6 -> V_17 ) ;
if ( V_9 ) {
F_9 ( V_4 , L_1 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_10 ( V_4 , F_11 ( 32 ) ) ;
if ( V_9 )
goto V_18;
V_8 -> V_19 = F_12 ( V_4 ) ;
V_6 -> V_20 = F_13 ( V_4 , V_2 -> V_21 ,
V_2 -> V_22 , V_8 ) ;
if ( F_7 ( V_6 -> V_20 ) ) {
V_9 = F_14 ( V_6 -> V_20 ) ;
if ( V_9 != - V_23 )
F_9 ( V_4 ,
L_2 ,
V_9 ) ;
goto V_18;
}
F_15 ( V_2 , V_6 ) ;
F_16 ( V_4 ) ;
F_17 ( V_4 ) ;
return 0 ;
V_18:
if ( ! F_7 ( V_6 -> V_17 ) )
F_18 ( V_6 -> V_17 ) ;
return V_9 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
F_21 ( & V_2 -> V_4 ) ;
F_22 ( V_6 -> V_20 ) ;
F_18 ( V_6 -> V_17 ) ;
return 0 ;
}
