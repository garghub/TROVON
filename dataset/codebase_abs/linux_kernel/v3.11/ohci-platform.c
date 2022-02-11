static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = V_4 -> V_9 . V_10 ;
struct V_11 * V_12 = F_3 ( V_2 ) ;
if ( V_8 -> V_13 )
V_12 -> V_14 |= V_15 ;
if ( V_8 -> V_16 )
V_12 -> V_14 |= V_17 ;
if ( V_8 -> V_18 )
V_12 -> V_14 |= V_19 ;
if ( V_8 -> V_20 )
V_12 -> V_20 = V_8 -> V_20 ;
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
int V_23 ;
int V_24 = - V_25 ;
if ( ! V_8 ) {
F_6 ( 1 ) ;
return - V_26 ;
}
if ( F_7 () )
return - V_26 ;
V_23 = F_8 ( V_9 , 0 ) ;
if ( V_23 < 0 ) {
F_9 ( & V_9 -> V_9 , L_1 ) ;
return V_23 ;
}
V_22 = F_10 ( V_9 , V_27 , 0 ) ;
if ( ! V_22 ) {
F_9 ( & V_9 -> V_9 , L_2 ) ;
return - V_28 ;
}
if ( V_8 -> V_29 ) {
V_24 = V_8 -> V_29 ( V_9 ) ;
if ( V_24 < 0 )
return V_24 ;
}
V_2 = F_11 ( & V_30 , & V_9 -> V_9 ,
F_12 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_24 = - V_25 ;
goto V_31;
}
V_2 -> V_32 = V_22 -> V_33 ;
V_2 -> V_34 = F_13 ( V_22 ) ;
V_2 -> V_35 = F_14 ( & V_9 -> V_9 , V_22 ) ;
if ( F_15 ( V_2 -> V_35 ) ) {
V_24 = F_16 ( V_2 -> V_35 ) ;
goto V_36;
}
V_24 = F_17 ( V_2 , V_23 , V_37 ) ;
if ( V_24 )
goto V_36;
F_18 ( V_9 , V_2 ) ;
return V_24 ;
V_36:
F_19 ( V_2 ) ;
V_31:
if ( V_8 -> V_38 )
V_8 -> V_38 ( V_9 ) ;
return V_24 ;
}
static int F_20 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_21 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
if ( V_8 -> V_38 )
V_8 -> V_38 ( V_9 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_24 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_40 )
V_8 -> V_40 ( V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_39 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_24 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_29 ) {
int V_24 = V_8 -> V_29 ( V_4 ) ;
if ( V_24 < 0 )
return V_24 ;
}
F_27 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( F_7 () )
return - V_26 ;
F_29 ( L_3 V_41 L_4 , V_42 ) ;
F_30 ( & V_30 , & V_43 ) ;
return F_31 ( & V_44 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_44 ) ;
}
