static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 , L_1 ) ;
return F_3 ( F_4 ( V_2 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
int V_7 ;
V_6 -> V_8 = V_9 ;
F_6 ( V_9 , & V_6 -> V_10 -> V_11 ) ;
V_7 = F_7 ( V_6 ) ;
if ( V_7 < 0 ) {
F_8 ( V_2 -> V_3 . V_4 , L_2 ) ;
F_9 ( V_2 ) ;
}
return V_7 ;
}
static int T_1 F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
struct V_1 * V_2 = NULL ;
void T_2 * V_10 = NULL ;
struct V_16 * V_17 ;
int V_7 = - V_18 ;
int V_19 ;
if ( F_11 () )
goto V_20;
if ( ! V_15 -> V_21 ) {
F_8 ( V_15 , L_3 ) ;
return - V_18 ;
}
V_19 = F_12 ( V_13 , L_4 ) ;
if ( V_19 < 0 ) {
F_8 ( V_15 , L_5 ) ;
return - V_18 ;
}
V_17 = F_13 ( V_13 ,
V_22 , L_6 ) ;
if ( ! V_7 ) {
F_8 ( V_15 , L_7 ) ;
return - V_23 ;
}
V_10 = F_14 ( V_17 -> V_24 , F_15 ( V_17 ) ) ;
if ( ! V_10 ) {
F_8 ( V_15 , L_8 ) ;
return - V_23 ;
}
V_2 = F_16 ( & V_25 , V_15 ,
F_17 ( V_15 ) ) ;
if ( ! V_2 ) {
F_8 ( V_15 , L_9 ) ;
goto V_26;
}
V_2 -> V_27 = V_17 -> V_24 ;
V_2 -> V_28 = F_15 ( V_17 ) ;
V_2 -> V_10 = V_10 ;
V_7 = F_18 ( V_15 ) ;
if ( V_7 ) {
F_2 ( V_15 , L_10 ) ;
goto V_20;
}
F_19 ( F_4 ( V_2 ) ) ;
V_7 = F_20 ( V_2 , V_19 , V_29 ) ;
if ( V_7 ) {
F_2 ( V_15 , L_11 , V_7 ) ;
goto V_30;
}
return 0 ;
V_30:
F_21 ( V_15 ) ;
V_20:
F_22 ( V_2 ) ;
V_26:
F_23 ( V_10 ) ;
return V_7 ;
}
static int T_3 F_24 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
struct V_1 * V_2 = F_25 ( V_15 ) ;
F_23 ( V_2 -> V_10 ) ;
F_26 ( V_2 ) ;
F_21 ( V_15 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_25 ( & V_13 -> V_15 ) ;
if ( V_2 -> V_31 -> V_32 )
V_2 -> V_31 -> V_32 ( V_2 ) ;
}
