static int F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 = F_2 ( V_3 ) ;
if ( F_3 ( V_1 -> V_2 ) ) {
F_4 ( L_1 ) ;
return - V_4 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
F_6 ( V_1 -> V_2 ) ;
return 0 ;
}
static int T_1 F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
struct V_5 * V_1 ;
struct V_11 * V_12 ;
struct V_13 * V_13 ;
int V_14 = - V_15 ;
V_12 = F_8 ( sizeof( * V_12 ) , V_16 ) ;
if ( ! V_12 ) {
F_9 ( & V_6 -> V_9 , L_2 ) ;
goto V_17;
}
V_1 = F_10 ( L_3 , - 1 ) ;
if ( ! V_1 ) {
F_9 ( & V_6 -> V_9 , L_4 ) ;
goto V_18;
}
V_13 = F_11 ( & V_6 -> V_9 , L_5 ) ;
if ( F_12 ( V_13 ) ) {
F_9 ( & V_6 -> V_9 , L_6 ) ;
V_14 = F_13 ( V_13 ) ;
goto V_19;
}
V_14 = F_14 ( V_13 ) ;
if ( V_14 ) {
F_9 ( & V_6 -> V_9 , L_7 ) ;
goto V_20;
}
V_1 -> V_9 . V_21 = & V_6 -> V_9 ;
V_1 -> V_9 . V_22 = V_6 -> V_9 . V_22 ;
V_1 -> V_9 . V_23 = V_6 -> V_9 . V_23 ;
V_12 -> V_9 = & V_6 -> V_9 ;
V_12 -> V_1 = V_1 ;
V_12 -> V_13 = V_13 ;
V_8 -> V_24 = & V_25 ;
F_15 ( V_6 , V_12 ) ;
V_14 = F_16 ( V_1 , V_6 -> V_26 ,
V_6 -> V_27 ) ;
if ( V_14 ) {
F_9 ( & V_6 -> V_9 , L_8 ) ;
goto V_28;
}
V_14 = F_17 ( V_1 , V_8 , sizeof( * V_8 ) ) ;
if ( V_14 ) {
F_9 ( & V_6 -> V_9 , L_9 ) ;
goto V_28;
}
V_14 = F_18 ( V_1 ) ;
if ( V_14 ) {
F_9 ( & V_6 -> V_9 , L_10 ) ;
goto V_28;
}
return 0 ;
V_28:
F_19 ( V_13 ) ;
V_20:
F_20 ( V_13 ) ;
V_19:
F_21 ( V_1 ) ;
V_18:
F_22 ( V_12 ) ;
V_17:
return V_14 ;
}
static int T_2 F_23 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_24 ( V_6 ) ;
F_25 ( V_12 -> V_1 ) ;
F_21 ( V_12 -> V_1 ) ;
F_19 ( V_12 -> V_13 ) ;
F_20 ( V_12 -> V_13 ) ;
F_22 ( V_12 ) ;
return 0 ;
}
static int F_26 ( struct V_29 * V_9 )
{
struct V_11 * V_12 = F_27 ( V_9 ) ;
struct V_1 * V_1 = F_28 ( V_12 ) ;
F_29 ( V_1 -> V_2 , 1 ) ;
F_19 ( V_12 -> V_13 ) ;
return 0 ;
}
static int F_30 ( struct V_29 * V_9 )
{
struct V_11 * V_12 = F_27 ( V_9 ) ;
struct V_1 * V_1 = F_28 ( V_12 ) ;
int V_14 ;
V_14 = F_14 ( V_12 -> V_13 ) ;
if ( V_14 ) {
F_9 ( V_9 , L_7 ) ;
return V_14 ;
}
F_29 ( V_1 -> V_2 , 0 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_30 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_30 ) ;
}
