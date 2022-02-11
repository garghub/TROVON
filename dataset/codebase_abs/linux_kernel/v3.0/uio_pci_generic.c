static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( int V_4 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 = V_9 ;
T_2 V_10 ;
T_3 V_11 , V_12 , V_13 ;
F_4 ( V_14 % 4 ) ;
F_4 ( V_14 + 2 != V_15 ) ;
F_5 ( & V_5 -> V_16 ) ;
F_6 ( V_7 ) ;
F_7 ( V_7 , V_14 , & V_10 ) ;
V_11 = V_10 ;
V_13 = V_10 >> 16 ;
if ( ! ( V_13 & V_17 ) )
goto V_18;
V_12 = V_11 | V_19 ;
if ( V_12 != V_11 )
F_8 ( V_7 , V_14 , V_12 ) ;
V_8 = V_20 ;
V_18:
F_9 ( V_7 ) ;
F_10 ( & V_5 -> V_16 ) ;
return V_8 ;
}
static int T_4 F_11 ( struct V_6 * V_7 )
{
T_3 V_21 , V_22 ;
int V_23 = 0 ;
F_6 ( V_7 ) ;
F_12 ( V_7 , V_14 , & V_21 ) ;
F_8 ( V_7 , V_14 ,
V_21 ^ V_19 ) ;
F_12 ( V_7 , V_14 , & V_22 ) ;
if ( ( V_22 ^ V_21 ) & ~ V_19 ) {
V_23 = - V_24 ;
F_13 ( & V_7 -> V_25 , L_1
L_2 , V_21 , V_22 ) ;
goto V_23;
}
if ( ! ( ( V_22 ^ V_21 ) & V_19 ) ) {
F_14 ( & V_7 -> V_25 , L_3
L_4 ) ;
V_23 = - V_26 ;
goto V_23;
}
F_8 ( V_7 , V_14 , V_21 ) ;
V_23:
F_9 ( V_7 ) ;
return V_23 ;
}
static int T_4 F_15 ( struct V_6 * V_7 ,
const struct V_27 * V_28 )
{
struct V_1 * V_5 ;
int V_23 ;
V_23 = F_16 ( V_7 ) ;
if ( V_23 ) {
F_13 ( & V_7 -> V_25 , L_5 ,
V_29 , V_23 ) ;
return V_23 ;
}
if ( ! V_7 -> V_4 ) {
F_14 ( & V_7 -> V_25 , L_6
L_7 ) ;
F_17 ( V_7 ) ;
return - V_26 ;
}
V_23 = F_11 ( V_7 ) ;
if ( V_23 )
goto V_30;
V_5 = F_18 ( sizeof( struct V_1 ) , V_31 ) ;
if ( ! V_5 ) {
V_23 = - V_32 ;
goto V_33;
}
V_5 -> V_3 . V_34 = L_8 ;
V_5 -> V_3 . V_35 = V_36 ;
V_5 -> V_3 . V_4 = V_7 -> V_4 ;
V_5 -> V_3 . V_37 = V_38 ;
V_5 -> V_3 . V_39 = F_3 ;
V_5 -> V_7 = V_7 ;
F_19 ( & V_5 -> V_16 ) ;
if ( F_20 ( & V_7 -> V_25 , & V_5 -> V_3 ) )
goto V_40;
F_21 ( V_7 , V_5 ) ;
return 0 ;
V_40:
F_22 ( V_5 ) ;
V_33:
V_30:
F_17 ( V_7 ) ;
return V_23 ;
}
static void remove ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_23 ( V_7 ) ;
F_24 ( & V_5 -> V_3 ) ;
F_17 ( V_7 ) ;
F_22 ( V_5 ) ;
}
static int T_5 F_25 ( void )
{
F_26 ( V_41 L_9 V_36 L_10 ) ;
return F_27 ( & V_42 ) ;
}
static void T_6 F_28 ( void )
{
F_29 ( & V_42 ) ;
}
