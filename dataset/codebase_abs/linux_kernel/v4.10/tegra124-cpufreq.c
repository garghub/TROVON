static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_7 ) ) ;
if ( V_5 )
return V_5 ;
V_4 = F_4 ( V_2 -> V_7 ) ;
F_5 ( V_2 -> V_7 , V_2 -> V_8 ) ;
V_5 = F_6 ( V_2 -> V_6 ) ;
if ( V_5 )
goto V_9;
F_5 ( V_2 -> V_7 , V_2 -> V_6 ) ;
return 0 ;
V_9:
F_5 ( V_2 -> V_7 , V_4 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_7 , V_2 -> V_8 ) ;
F_8 ( V_2 -> V_6 ) ;
F_9 ( V_2 -> V_10 ) ;
F_5 ( V_2 -> V_7 , V_2 -> V_11 ) ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 V_19 = {} ;
int V_5 ;
V_2 = F_11 ( & V_13 -> V_20 , sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_22 ;
V_17 = F_12 ( 0 ) ;
if ( ! V_17 )
return - V_23 ;
V_15 = F_13 ( 0 ) ;
if ( ! V_15 )
return - V_23 ;
V_2 -> V_10 = F_14 ( V_17 , L_1 ) ;
if ( F_15 ( V_2 -> V_10 ) ) {
V_5 = F_16 ( V_2 -> V_10 ) ;
goto V_24;
}
V_2 -> V_7 = F_17 ( V_15 , L_2 ) ;
if ( F_15 ( V_2 -> V_7 ) ) {
V_5 = F_16 ( V_2 -> V_7 ) ;
goto V_25;
}
V_2 -> V_6 = F_17 ( V_15 , L_3 ) ;
if ( F_15 ( V_2 -> V_6 ) ) {
V_5 = F_16 ( V_2 -> V_6 ) ;
goto V_26;
}
V_2 -> V_11 = F_17 ( V_15 , L_4 ) ;
if ( F_15 ( V_2 -> V_11 ) ) {
V_5 = F_16 ( V_2 -> V_11 ) ;
goto V_27;
}
V_2 -> V_8 = F_17 ( V_15 , L_5 ) ;
if ( F_15 ( V_2 -> V_8 ) ) {
V_5 = F_16 ( V_2 -> V_8 ) ;
goto V_28;
}
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
goto V_29;
V_19 . V_30 = L_6 ;
V_19 . V_31 = & V_13 -> V_20 ;
V_2 -> V_32 =
F_18 ( & V_19 ) ;
if ( F_15 ( V_2 -> V_32 ) ) {
V_5 = F_16 ( V_2 -> V_32 ) ;
goto V_33;
}
F_19 ( V_13 , V_2 ) ;
return 0 ;
V_33:
F_7 ( V_2 ) ;
V_29:
F_20 ( V_2 -> V_8 ) ;
V_28:
F_20 ( V_2 -> V_11 ) ;
V_27:
F_20 ( V_2 -> V_6 ) ;
V_26:
F_20 ( V_2 -> V_7 ) ;
V_25:
F_21 ( V_2 -> V_10 ) ;
V_24:
F_22 ( V_15 ) ;
return V_5 ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
F_25 ( V_2 -> V_32 ) ;
F_7 ( V_2 ) ;
F_20 ( V_2 -> V_8 ) ;
F_20 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_6 ) ;
F_20 ( V_2 -> V_7 ) ;
F_21 ( V_2 -> V_10 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
int V_5 ;
struct V_12 * V_13 ;
if ( ! F_27 ( L_7 ) )
return - V_23 ;
V_5 = F_28 ( & V_34 ) ;
if ( V_5 )
return V_5 ;
V_13 = F_29 ( L_8 , - 1 , NULL , 0 ) ;
if ( F_15 ( V_13 ) ) {
F_30 ( & V_34 ) ;
return F_16 ( V_13 ) ;
}
return 0 ;
}
