static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 -> V_4 , L_1 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
struct V_11 * V_3 = & V_12 ;
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_4 ( & V_6 -> V_9 , sizeof( struct V_13 ) ,
V_16 ) ;
if ( ! V_14 )
return - V_17 ;
V_3 -> V_9 = & V_6 -> V_9 ;
F_5 ( V_3 , V_14 ) ;
V_14 -> V_18 = F_6 ( L_2 , - 1 ) ;
if ( ! V_14 -> V_18 ) {
F_7 ( & V_6 -> V_9 , L_3 ) ;
return - V_17 ;
}
V_15 = F_8 ( V_14 -> V_18 ) ;
if ( V_15 )
goto V_19;
V_15 = F_9 ( V_3 , L_4 ) ;
if ( V_15 )
goto V_20;
V_15 = F_10 ( V_3 , L_5 ) ;
if ( V_15 )
goto V_20;
V_21 . V_22 = F_11 ( V_8 ,
L_6 , 0 ) ;
if ( ! V_21 . V_22 ) {
F_7 ( & V_6 -> V_9 ,
L_7 ) ;
V_15 = - V_23 ;
goto V_20;
}
V_21 . V_24 = V_21 . V_22 ;
V_15 = F_12 ( & V_14 -> V_25 , & V_6 -> V_9 ) ;
if ( V_15 )
goto V_20;
V_15 = F_13 ( & V_14 -> V_25 ) ;
if ( V_15 )
goto V_26;
V_15 = F_14 ( V_3 ) ;
if ( V_15 ) {
F_7 ( & V_6 -> V_9 , L_8 ,
V_15 ) ;
goto V_26;
}
return 0 ;
V_26:
F_15 ( & V_14 -> V_25 ) ;
V_20:
F_16 ( V_14 -> V_18 ) ;
V_19:
F_17 ( V_14 -> V_18 ) ;
return V_15 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_11 * V_3 = F_19 ( V_6 ) ;
struct V_13 * V_14 = F_20 ( V_3 ) ;
F_21 ( V_3 ) ;
F_15 ( & V_14 -> V_25 ) ;
F_22 ( V_14 -> V_18 ) ;
return 0 ;
}
