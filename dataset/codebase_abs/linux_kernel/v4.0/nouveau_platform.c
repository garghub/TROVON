static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 )
goto V_5;
V_3 = F_3 ( V_2 -> V_6 ) ;
if ( V_3 )
goto V_7;
V_3 = F_3 ( V_2 -> V_8 ) ;
if ( V_3 )
goto V_9;
F_4 ( V_2 -> V_8 , 204000000 ) ;
F_5 ( 10 ) ;
F_6 ( V_2 -> V_10 ) ;
F_5 ( 10 ) ;
V_3 = F_7 ( V_11 ) ;
if ( V_3 )
goto V_12;
F_5 ( 10 ) ;
F_8 ( V_2 -> V_10 ) ;
F_5 ( 10 ) ;
return 0 ;
V_12:
F_9 ( V_2 -> V_8 ) ;
V_9:
F_9 ( V_2 -> V_6 ) ;
V_7:
F_10 ( V_2 -> V_4 ) ;
V_5:
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 ;
F_6 ( V_2 -> V_10 ) ;
F_5 ( 10 ) ;
F_9 ( V_2 -> V_8 ) ;
F_9 ( V_2 -> V_6 ) ;
F_5 ( 10 ) ;
V_3 = F_10 ( V_2 -> V_4 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_3 ;
V_2 = F_13 ( & V_14 -> V_19 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_4 = F_14 ( & V_14 -> V_19 , L_1 ) ;
if ( F_15 ( V_2 -> V_4 ) )
return F_16 ( V_2 -> V_4 ) ;
V_2 -> V_10 = F_17 ( & V_14 -> V_19 , L_2 ) ;
if ( F_15 ( V_2 -> V_10 ) )
return F_16 ( V_2 -> V_10 ) ;
V_2 -> V_6 = F_18 ( & V_14 -> V_19 , L_2 ) ;
if ( F_15 ( V_2 -> V_6 ) )
return F_16 ( V_2 -> V_6 ) ;
V_2 -> V_8 = F_18 ( & V_14 -> V_19 , L_3 ) ;
if ( F_15 ( V_2 -> V_8 ) )
return F_16 ( V_2 -> V_8 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_18 = F_19 ( V_14 , & V_16 ) ;
if ( F_15 ( V_18 ) ) {
V_3 = F_16 ( V_18 ) ;
goto V_22;
}
V_16 -> V_2 = V_2 ;
V_16 -> V_23 = V_24 . V_25 ;
V_3 = F_20 ( V_18 , 0 ) ;
if ( V_3 < 0 )
goto V_26;
return 0 ;
V_26:
F_21 ( V_18 ) ;
return 0 ;
V_22:
F_11 ( V_2 ) ;
return V_3 ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_17 * V_27 = F_23 ( V_14 ) ;
struct V_28 * V_18 = V_28 ( V_27 ) ;
struct V_29 * V_16 = F_24 ( & V_18 -> V_16 ) ;
struct V_1 * V_2 = F_25 ( V_16 ) -> V_2 ;
F_26 ( V_27 ) ;
return F_11 ( V_2 ) ;
}
