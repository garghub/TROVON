static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
if ( V_8 -> V_12 )
V_11 -> V_13 |= V_14 ;
if ( V_8 -> V_15 )
V_11 -> V_13 |= V_16 ;
if ( V_8 -> V_17 )
V_11 -> V_13 |= V_18 ;
if ( V_8 -> V_19 )
V_11 -> V_19 = V_8 -> V_19 ;
return F_5 ( V_2 ) ;
}
static int F_6 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
int V_22 ;
int V_23 = - V_24 ;
if ( ! V_8 ) {
F_7 ( 1 ) ;
return - V_25 ;
}
if ( F_8 () )
return - V_25 ;
V_22 = F_9 ( V_9 , 0 ) ;
if ( V_22 < 0 ) {
F_10 ( & V_9 -> V_9 , L_1 ) ;
return V_22 ;
}
V_21 = F_11 ( V_9 , V_26 , 0 ) ;
if ( ! V_21 ) {
F_10 ( & V_9 -> V_9 , L_2 ) ;
return - V_27 ;
}
if ( V_8 -> V_28 ) {
V_23 = V_8 -> V_28 ( V_9 ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_2 = F_12 ( & V_29 , & V_9 -> V_9 ,
F_13 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_23 = - V_24 ;
goto V_30;
}
V_2 -> V_31 = V_21 -> V_32 ;
V_2 -> V_33 = F_14 ( V_21 ) ;
V_2 -> V_34 = F_15 ( & V_9 -> V_9 , V_21 ) ;
if ( F_16 ( V_2 -> V_34 ) ) {
V_23 = F_17 ( V_2 -> V_34 ) ;
goto V_35;
}
V_23 = F_18 ( V_2 , V_22 , V_36 ) ;
if ( V_23 )
goto V_35;
F_19 ( V_9 , V_2 ) ;
return V_23 ;
V_35:
F_20 ( V_2 ) ;
V_30:
if ( V_8 -> V_37 )
V_8 -> V_37 ( V_9 ) ;
return V_23 ;
}
static int F_21 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
F_23 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( V_8 -> V_37 )
V_8 -> V_37 ( V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_38 * V_9 )
{
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_25 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_39 )
V_8 -> V_39 ( V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_38 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_25 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_28 ) {
int V_23 = V_8 -> V_28 ( V_4 ) ;
if ( V_23 < 0 )
return V_23 ;
}
F_28 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_29 ( void )
{
if ( F_8 () )
return - V_25 ;
F_30 ( L_3 V_40 L_4 , V_41 ) ;
F_31 ( & V_29 , & V_42 ) ;
return F_32 ( & V_43 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_43 ) ;
}
