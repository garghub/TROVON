void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_3 ;
F_2 ( & V_6 -> V_11 , & V_10 -> V_12 ) ;
F_3 ( V_10 -> V_13 ) ;
F_4 ( V_10 -> V_4 ) ;
V_10 -> V_4 = NULL ;
}
F_5 ( V_2 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_14 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_9 * V_10 ;
struct V_15 * V_4 ;
int V_16 ;
V_10 = & V_2 -> V_3 ;
V_10 -> V_4 = F_7 ( sizeof( struct V_9 ) , V_17 ) ;
if ( V_10 -> V_4 == NULL )
return - V_18 ;
V_4 = V_10 -> V_4 ;
V_4 -> type = V_19 ;
V_4 -> V_20 = V_2 -> V_20 ;
V_4 -> V_21 = V_2 ;
V_10 -> V_13 = F_8 ( & V_6 -> V_22 ,
V_2 -> V_20 / V_23 , 0 , 0 ) ;
if ( ! V_10 -> V_13 ) {
F_9 ( V_7 -> V_7 , L_1 ,
V_2 -> V_24 ) ;
V_16 = - V_25 ;
goto V_26;
}
V_10 -> V_13 = F_10 ( V_10 -> V_13 ,
V_2 -> V_20 / V_23 , 0 ) ;
if ( ! V_10 -> V_13 ) {
V_16 = - V_18 ;
goto V_26;
}
V_10 -> V_12 . V_27 = V_10 -> V_13 -> V_28 ;
V_16 = F_11 ( & V_6 -> V_11 , & V_10 -> V_12 ) ;
if ( V_16 ) {
F_9 ( V_7 -> V_7 , L_2 ) ;
goto V_29;
}
return 0 ;
V_29:
F_3 ( V_10 -> V_13 ) ;
V_26:
F_4 ( V_10 -> V_4 ) ;
V_10 -> V_4 = NULL ;
return V_16 ;
}
