static int F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 = F_2 () ;
if ( ! V_1 -> V_2 ) {
F_3 ( L_1 ) ;
return - V_3 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 )
{
F_5 ( V_1 -> V_2 ) ;
return 0 ;
}
static int T_1 F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 . V_9 ;
struct V_4 * V_1 ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
int V_13 = - V_14 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 ) {
F_8 ( & V_5 -> V_8 , L_2 ) ;
goto V_16;
}
V_1 = F_9 ( L_3 , - 1 ) ;
if ( ! V_1 ) {
F_8 ( & V_5 -> V_8 , L_4 ) ;
goto V_17;
}
V_12 = F_10 ( & V_5 -> V_8 , L_5 ) ;
if ( F_11 ( V_12 ) ) {
F_8 ( & V_5 -> V_8 , L_6 ) ;
V_13 = F_12 ( V_12 ) ;
goto V_18;
}
V_13 = F_13 ( V_12 ) ;
if ( V_13 ) {
F_8 ( & V_5 -> V_8 , L_7 ) ;
goto V_19;
}
V_1 -> V_8 . V_20 = & V_5 -> V_8 ;
V_1 -> V_8 . V_21 = V_5 -> V_8 . V_21 ;
V_1 -> V_8 . V_22 = V_5 -> V_8 . V_22 ;
V_11 -> V_8 = & V_5 -> V_8 ;
V_11 -> V_1 = V_1 ;
V_11 -> V_12 = V_12 ;
V_7 -> V_23 = & V_24 ;
F_14 ( V_5 , V_11 ) ;
V_13 = F_15 ( V_1 , V_5 -> V_25 ,
V_5 -> V_26 ) ;
if ( V_13 ) {
F_8 ( & V_5 -> V_8 , L_8 ) ;
goto V_27;
}
V_13 = F_16 ( V_1 , V_7 , sizeof( * V_7 ) ) ;
if ( V_13 ) {
F_8 ( & V_5 -> V_8 , L_9 ) ;
goto V_27;
}
V_13 = F_17 ( V_1 ) ;
if ( V_13 ) {
F_8 ( & V_5 -> V_8 , L_10 ) ;
goto V_27;
}
return 0 ;
V_27:
F_18 ( V_12 ) ;
V_19:
F_19 ( V_12 ) ;
V_18:
F_20 ( V_1 ) ;
V_17:
F_21 ( V_11 ) ;
V_16:
return V_13 ;
}
static int T_2 F_22 ( struct V_4 * V_5 )
{
struct V_10 * V_11 = F_23 ( V_5 ) ;
F_24 ( V_11 -> V_1 ) ;
F_20 ( V_11 -> V_1 ) ;
F_18 ( V_11 -> V_12 ) ;
F_19 ( V_11 -> V_12 ) ;
F_21 ( V_11 ) ;
return 0 ;
}
static int F_25 ( struct V_28 * V_8 )
{
struct V_10 * V_11 = F_26 ( V_8 ) ;
struct V_1 * V_1 = F_27 ( V_11 ) ;
F_28 ( V_1 -> V_2 , 1 ) ;
F_18 ( V_11 -> V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_28 * V_8 )
{
struct V_10 * V_11 = F_26 ( V_8 ) ;
struct V_1 * V_1 = F_27 ( V_11 ) ;
int V_13 ;
V_13 = F_13 ( V_11 -> V_12 ) ;
if ( V_13 ) {
F_8 ( V_8 , L_7 ) ;
return V_13 ;
}
F_28 ( V_1 -> V_2 , 0 ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
return F_31 ( & V_29 , F_6 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_29 ) ;
}
