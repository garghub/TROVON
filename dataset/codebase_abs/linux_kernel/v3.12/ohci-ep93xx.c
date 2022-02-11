static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( ( V_5 = F_3 ( V_4 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_4 ( V_4 ) ) < 0 ) {
F_5 ( V_2 -> V_6 . V_7 , L_1 ,
V_2 -> V_6 . V_8 ) ;
F_6 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_13 ;
int V_5 ;
if ( F_8 () )
return - V_14 ;
V_13 = F_9 ( V_10 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_10 ( V_10 , V_15 , 0 ) ;
if ( ! V_12 )
return - V_16 ;
V_2 = F_11 ( & V_17 , & V_10 -> V_18 , L_2 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_20 = V_12 -> V_21 ;
V_2 -> V_22 = F_12 ( V_12 ) ;
V_2 -> V_23 = F_13 ( & V_10 -> V_18 , V_12 ) ;
if ( F_14 ( V_2 -> V_23 ) ) {
V_5 = F_15 ( V_2 -> V_23 ) ;
goto V_24;
}
V_25 = F_16 ( & V_10 -> V_18 , NULL ) ;
if ( F_14 ( V_25 ) ) {
V_5 = F_15 ( V_25 ) ;
goto V_24;
}
F_17 ( V_25 ) ;
F_18 ( F_2 ( V_2 ) ) ;
V_5 = F_19 ( V_2 , V_13 , 0 ) ;
if ( V_5 )
goto V_26;
return 0 ;
V_26:
F_20 ( V_25 ) ;
V_24:
F_21 ( V_2 ) ;
return V_5 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_23 ( V_10 ) ;
F_24 ( V_2 ) ;
F_20 ( V_25 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 , T_1 V_27 )
{
struct V_1 * V_2 = F_23 ( V_10 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_26 ( V_28 , V_4 -> V_29 ) )
F_27 ( 5 ) ;
V_4 -> V_29 = V_28 ;
F_20 ( V_25 ) ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_23 ( V_10 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_26 ( V_28 , V_4 -> V_29 ) )
F_27 ( 5 ) ;
V_4 -> V_29 = V_28 ;
F_17 ( V_25 ) ;
F_29 ( V_2 , false ) ;
return 0 ;
}
