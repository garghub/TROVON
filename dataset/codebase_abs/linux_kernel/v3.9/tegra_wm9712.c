static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
F_2 ( V_8 , L_1 ) ;
return F_3 ( V_8 ) ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_15 * V_16 = & V_17 ;
struct V_18 * V_19 ;
int V_20 ;
if ( ! V_10 -> V_13 . V_14 ) {
F_5 ( & V_10 -> V_13 , L_2 ) ;
return - V_21 ;
}
V_19 = F_6 ( & V_10 -> V_13 , sizeof( struct V_18 ) ,
V_22 ) ;
if ( ! V_19 ) {
F_5 ( & V_10 -> V_13 , L_3 ) ;
return - V_23 ;
}
V_16 -> V_13 = & V_10 -> V_13 ;
F_7 ( V_10 , V_16 ) ;
F_8 ( V_16 , V_19 ) ;
V_19 -> V_6 = F_9 ( L_4 , - 1 ) ;
if ( ! V_19 -> V_6 ) {
F_5 ( & V_10 -> V_13 , L_5 ) ;
return - V_23 ;
}
V_20 = F_10 ( V_19 -> V_6 ) ;
if ( V_20 )
goto V_24;
V_20 = F_11 ( V_16 , L_6 ) ;
if ( V_20 )
goto V_25;
V_20 = F_12 ( V_16 , L_7 ) ;
if ( V_20 )
goto V_25;
V_26 . V_27 = F_13 ( V_12 ,
L_8 , 0 ) ;
if ( ! V_26 . V_27 ) {
F_5 ( & V_10 -> V_13 ,
L_9 ) ;
V_20 = - V_21 ;
goto V_25;
}
V_26 . V_28 = V_26 . V_27 ;
V_20 = F_14 ( V_16 ) ;
if ( V_20 ) {
F_5 ( & V_10 -> V_13 , L_10 ,
V_20 ) ;
goto V_25;
}
return 0 ;
V_25:
F_15 ( V_19 -> V_6 ) ;
V_24:
F_16 ( V_19 -> V_6 ) ;
return V_20 ;
}
static int F_17 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_18 ( V_10 ) ;
struct V_18 * V_19 = F_19 ( V_16 ) ;
F_20 ( V_16 ) ;
F_21 ( V_19 -> V_6 ) ;
return 0 ;
}
