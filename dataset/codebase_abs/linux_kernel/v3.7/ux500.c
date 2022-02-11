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
int V_14 ;
int V_15 = - V_16 ;
V_12 = F_8 ( sizeof( * V_12 ) , V_17 ) ;
if ( ! V_12 ) {
F_9 ( & V_6 -> V_9 , L_2 ) ;
goto V_18;
}
V_14 = F_10 ( & V_6 -> V_9 , V_17 ) ;
if ( V_14 < 0 ) {
F_9 ( & V_6 -> V_9 , L_3 ) ;
V_15 = - V_16 ;
goto V_19;
}
V_1 = F_11 ( L_4 , V_14 ) ;
if ( ! V_1 ) {
F_9 ( & V_6 -> V_9 , L_5 ) ;
goto V_20;
}
V_13 = F_12 ( & V_6 -> V_9 , L_6 ) ;
if ( F_13 ( V_13 ) ) {
F_9 ( & V_6 -> V_9 , L_7 ) ;
V_15 = F_14 ( V_13 ) ;
goto V_21;
}
V_15 = F_15 ( V_13 ) ;
if ( V_15 ) {
F_9 ( & V_6 -> V_9 , L_8 ) ;
goto V_22;
}
V_1 -> V_23 = V_14 ;
V_1 -> V_9 . V_24 = & V_6 -> V_9 ;
V_1 -> V_9 . V_25 = V_6 -> V_9 . V_25 ;
V_1 -> V_9 . V_26 = V_6 -> V_9 . V_26 ;
V_12 -> V_9 = & V_6 -> V_9 ;
V_12 -> V_1 = V_1 ;
V_12 -> V_13 = V_13 ;
V_8 -> V_27 = & V_28 ;
F_16 ( V_6 , V_12 ) ;
V_15 = F_17 ( V_1 , V_6 -> V_29 ,
V_6 -> V_30 ) ;
if ( V_15 ) {
F_9 ( & V_6 -> V_9 , L_9 ) ;
goto V_31;
}
V_15 = F_18 ( V_1 , V_8 , sizeof( * V_8 ) ) ;
if ( V_15 ) {
F_9 ( & V_6 -> V_9 , L_10 ) ;
goto V_31;
}
V_15 = F_19 ( V_1 ) ;
if ( V_15 ) {
F_9 ( & V_6 -> V_9 , L_11 ) ;
goto V_31;
}
return 0 ;
V_31:
F_20 ( V_13 ) ;
V_22:
F_21 ( V_13 ) ;
V_21:
F_22 ( V_1 ) ;
V_20:
F_23 ( & V_6 -> V_9 , V_14 ) ;
V_19:
F_24 ( V_12 ) ;
V_18:
return V_15 ;
}
static int T_2 F_25 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_26 ( V_6 ) ;
F_23 ( & V_6 -> V_9 , V_12 -> V_1 -> V_23 ) ;
F_27 ( V_12 -> V_1 ) ;
F_22 ( V_12 -> V_1 ) ;
F_20 ( V_12 -> V_13 ) ;
F_21 ( V_12 -> V_13 ) ;
F_24 ( V_12 ) ;
return 0 ;
}
static int F_28 ( struct V_32 * V_9 )
{
struct V_11 * V_12 = F_29 ( V_9 ) ;
struct V_1 * V_1 = F_30 ( V_12 ) ;
F_31 ( V_1 -> V_2 , 1 ) ;
F_20 ( V_12 -> V_13 ) ;
return 0 ;
}
static int F_32 ( struct V_32 * V_9 )
{
struct V_11 * V_12 = F_29 ( V_9 ) ;
struct V_1 * V_1 = F_30 ( V_12 ) ;
int V_15 ;
V_15 = F_15 ( V_12 -> V_13 ) ;
if ( V_15 ) {
F_9 ( V_9 , L_8 ) ;
return V_15 ;
}
F_31 ( V_1 -> V_2 , 0 ) ;
return 0 ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_33 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_33 ) ;
}
