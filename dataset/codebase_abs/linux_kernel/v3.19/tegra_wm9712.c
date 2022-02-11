static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
return F_2 ( V_8 , L_1 ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_15 * V_16 = & V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_19 = F_4 ( & V_10 -> V_13 , sizeof( struct V_18 ) ,
V_21 ) ;
if ( ! V_19 ) {
F_5 ( & V_10 -> V_13 , L_2 ) ;
return - V_22 ;
}
V_16 -> V_13 = & V_10 -> V_13 ;
F_6 ( V_10 , V_16 ) ;
F_7 ( V_16 , V_19 ) ;
V_19 -> V_6 = F_8 ( L_3 , - 1 ) ;
if ( ! V_19 -> V_6 ) {
F_5 ( & V_10 -> V_13 , L_4 ) ;
return - V_22 ;
}
V_20 = F_9 ( V_19 -> V_6 ) ;
if ( V_20 )
goto V_23;
V_20 = F_10 ( V_16 , L_5 ) ;
if ( V_20 )
goto V_24;
V_20 = F_11 ( V_16 , L_6 ) ;
if ( V_20 )
goto V_24;
V_25 . V_26 = F_12 ( V_12 ,
L_7 , 0 ) ;
if ( ! V_25 . V_26 ) {
F_5 ( & V_10 -> V_13 ,
L_8 ) ;
V_20 = - V_27 ;
goto V_24;
}
V_25 . V_28 = V_25 . V_26 ;
V_20 = F_13 ( & V_19 -> V_29 , & V_10 -> V_13 ) ;
if ( V_20 )
goto V_24;
V_20 = F_14 ( & V_19 -> V_29 ) ;
if ( V_20 )
goto V_30;
V_20 = F_15 ( V_16 ) ;
if ( V_20 ) {
F_5 ( & V_10 -> V_13 , L_9 ,
V_20 ) ;
goto V_30;
}
return 0 ;
V_30:
F_16 ( & V_19 -> V_29 ) ;
V_24:
F_17 ( V_19 -> V_6 ) ;
V_23:
F_18 ( V_19 -> V_6 ) ;
return V_20 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_20 ( V_10 ) ;
struct V_18 * V_19 = F_21 ( V_16 ) ;
F_22 ( V_16 ) ;
F_16 ( & V_19 -> V_29 ) ;
F_23 ( V_19 -> V_6 ) ;
return 0 ;
}
