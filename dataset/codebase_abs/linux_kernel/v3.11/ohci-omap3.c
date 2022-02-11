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
static int F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
struct V_1 * V_2 = NULL ;
void T_1 * V_10 = NULL ;
struct V_16 * V_17 ;
int V_7 = - V_18 ;
int V_19 ;
if ( F_11 () )
return - V_18 ;
if ( ! V_15 -> V_20 ) {
F_8 ( V_15 , L_3 ) ;
return - V_18 ;
}
V_19 = F_12 ( V_13 , 0 ) ;
if ( V_19 < 0 ) {
F_8 ( V_15 , L_4 ) ;
return - V_18 ;
}
V_17 = F_13 ( V_13 , V_21 , 0 ) ;
if ( ! V_17 ) {
F_8 ( V_15 , L_5 ) ;
return - V_22 ;
}
V_10 = F_14 ( V_17 -> V_23 , F_15 ( V_17 ) ) ;
if ( ! V_10 ) {
F_8 ( V_15 , L_6 ) ;
return - V_22 ;
}
if ( ! V_15 -> V_24 )
V_15 -> V_24 = & V_15 -> V_25 ;
if ( ! V_15 -> V_25 )
V_15 -> V_25 = F_16 ( 32 ) ;
V_2 = F_17 ( & V_26 , V_15 ,
F_18 ( V_15 ) ) ;
if ( ! V_2 ) {
F_8 ( V_15 , L_7 ) ;
goto V_27;
}
V_2 -> V_28 = V_17 -> V_23 ;
V_2 -> V_29 = F_15 ( V_17 ) ;
V_2 -> V_10 = V_10 ;
F_19 ( V_15 ) ;
F_20 ( V_15 ) ;
F_21 ( F_4 ( V_2 ) ) ;
V_7 = F_22 ( V_2 , V_19 , 0 ) ;
if ( V_7 ) {
F_2 ( V_15 , L_8 , V_7 ) ;
goto V_30;
}
return 0 ;
V_30:
F_23 ( V_15 ) ;
F_24 ( V_2 ) ;
V_27:
F_25 ( V_10 ) ;
return V_7 ;
}
static int F_26 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
struct V_1 * V_2 = F_27 ( V_15 ) ;
F_25 ( V_2 -> V_10 ) ;
F_28 ( V_2 ) ;
F_23 ( V_15 ) ;
F_29 ( V_15 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_27 ( & V_13 -> V_15 ) ;
if ( V_2 -> V_31 -> V_32 )
V_2 -> V_31 -> V_32 ( V_2 ) ;
}
