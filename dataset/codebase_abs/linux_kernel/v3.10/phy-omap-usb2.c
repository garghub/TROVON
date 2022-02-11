int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( F_3 ( V_6 ) )
return - V_8 ;
V_4 = F_4 ( V_6 ) ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 , bool V_11 )
{
struct V_3 * V_4 = F_4 ( V_10 -> V_4 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_12 ( V_4 -> V_2 , V_11 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_10 -> V_4 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_13 ( V_4 -> V_2 ) ;
}
static int F_7 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
struct V_5 * V_4 = V_10 -> V_4 ;
V_10 -> V_15 = V_15 ;
if ( ! V_15 )
V_4 -> V_16 = V_17 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_5 * V_4 = V_10 -> V_4 ;
V_10 -> V_19 = V_19 ;
if ( ! V_19 )
V_4 -> V_16 = V_17 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , int V_20 )
{
T_1 V_21 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
if ( V_20 && ! V_4 -> V_22 ) {
F_10 ( V_4 -> V_23 , 0 ) ;
F_11 ( V_4 -> V_24 ) ;
V_4 -> V_22 = 1 ;
} else if ( ! V_20 && V_4 -> V_22 ) {
V_21 = F_12 ( V_4 -> V_24 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_24 , L_1 ,
V_21 ) ;
return V_21 ;
}
F_10 ( V_4 -> V_23 , 1 ) ;
V_4 -> V_22 = 0 ;
}
return 0 ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_9 * V_10 ;
V_4 = F_15 ( & V_26 -> V_24 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 ) {
F_13 ( & V_26 -> V_24 , L_2 ) ;
return - V_28 ;
}
V_10 = F_15 ( & V_26 -> V_24 , sizeof( * V_10 ) , V_27 ) ;
if ( ! V_10 ) {
F_13 ( & V_26 -> V_24 , L_3 ) ;
return - V_28 ;
}
V_4 -> V_24 = & V_26 -> V_24 ;
V_4 -> V_4 . V_24 = V_4 -> V_24 ;
V_4 -> V_4 . V_29 = L_4 ;
V_4 -> V_4 . V_30 = F_9 ;
V_4 -> V_4 . V_10 = V_10 ;
V_4 -> V_4 . type = V_7 ;
V_4 -> V_23 = F_16 () ;
if ( F_3 ( V_4 -> V_23 ) ) {
F_17 ( & V_26 -> V_24 , L_5 ) ;
return - V_8 ;
}
V_4 -> V_22 = 1 ;
F_10 ( V_4 -> V_23 , 0 ) ;
V_10 -> V_31 = F_7 ;
V_10 -> V_32 = F_8 ;
V_10 -> V_12 = F_5 ;
V_10 -> V_13 = F_6 ;
V_10 -> V_4 = & V_4 -> V_4 ;
V_4 -> V_33 = F_18 ( V_4 -> V_24 , L_6 ) ;
if ( F_3 ( V_4 -> V_33 ) ) {
F_13 ( & V_26 -> V_24 , L_7 ) ;
return F_19 ( V_4 -> V_33 ) ;
}
F_20 ( V_4 -> V_33 ) ;
V_4 -> V_34 = F_18 ( V_4 -> V_24 , L_8 ) ;
if ( F_3 ( V_4 -> V_34 ) )
F_21 ( & V_26 -> V_24 , L_9 ) ;
else
F_20 ( V_4 -> V_34 ) ;
F_22 ( & V_4 -> V_4 ) ;
F_23 ( V_26 , V_4 ) ;
F_24 ( V_4 -> V_24 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_26 ( V_26 ) ;
F_27 ( V_4 -> V_33 ) ;
if ( ! F_3 ( V_4 -> V_34 ) )
F_27 ( V_4 -> V_34 ) ;
F_28 ( & V_4 -> V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_24 )
{
struct V_25 * V_26 = F_30 ( V_24 ) ;
struct V_3 * V_4 = F_26 ( V_26 ) ;
F_31 ( V_4 -> V_33 ) ;
if ( ! F_3 ( V_4 -> V_34 ) )
F_31 ( V_4 -> V_34 ) ;
return 0 ;
}
static int F_32 ( struct V_35 * V_24 )
{
T_1 V_21 = 0 ;
struct V_25 * V_26 = F_30 ( V_24 ) ;
struct V_3 * V_4 = F_26 ( V_26 ) ;
V_21 = F_33 ( V_4 -> V_33 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_24 , L_10 , V_21 ) ;
goto V_36;
}
if ( ! F_3 ( V_4 -> V_34 ) ) {
V_21 = F_33 ( V_4 -> V_34 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_24 , L_11 , V_21 ) ;
goto V_37;
}
}
return 0 ;
V_37:
F_31 ( V_4 -> V_33 ) ;
V_36:
return V_21 ;
}
