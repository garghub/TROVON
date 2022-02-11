static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
F_3 ( V_2 , V_6 , V_7 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
int F_7 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_16 ;
V_15 = F_8 ( V_9 -> V_17 , sizeof( * V_15 ) , V_18 ) ;
if ( V_15 == NULL )
return - V_19 ;
V_15 -> V_20 . V_21 = 1 ;
V_15 -> V_20 . V_22 = 0 ;
V_16 = F_9 ( V_9 , & V_15 -> V_20 , & V_23 ,
V_24 , NULL ) ;
if ( V_16 )
return V_16 ;
V_13 = F_8 ( V_9 -> V_17 , sizeof( * V_13 ) ,
V_18 ) ;
if ( ! V_13 ) {
V_16 = - V_19 ;
goto V_25;
}
V_2 = & V_13 -> V_2 ;
F_10 ( V_2 , & V_26 ) ;
V_16 = F_11 ( V_9 , V_2 , & V_27 ,
V_28 ) ;
if ( V_16 < 0 ) {
F_12 ( V_9 -> V_17 , L_1 ) ;
goto V_25;
}
V_16 = F_13 ( V_2 , & V_15 -> V_20 ) ;
if ( V_16 < 0 ) {
F_12 ( V_9 -> V_17 , L_2 ) ;
F_5 ( V_2 ) ;
goto V_29;
}
V_13 -> V_30 = V_15 ;
return 0 ;
V_29:
F_6 ( V_2 ) ;
V_25:
F_14 ( & V_15 -> V_20 ) ;
return V_16 ;
}
