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
F_5 ( V_7 ) ;
F_6 ( V_7 , V_14 , & V_10 ) ;
V_11 = V_10 ;
V_13 = V_10 >> 16 ;
if ( ! ( V_13 & V_16 ) )
goto V_17;
V_12 = V_11 | V_18 ;
if ( V_12 != V_11 )
F_7 ( V_7 , V_14 , V_12 ) ;
V_8 = V_19 ;
V_17:
F_8 ( V_7 ) ;
return V_8 ;
}
static int T_4 F_9 ( struct V_6 * V_7 )
{
T_3 V_20 , V_21 ;
int V_22 = 0 ;
F_5 ( V_7 ) ;
F_10 ( V_7 , V_14 , & V_20 ) ;
F_7 ( V_7 , V_14 ,
V_20 ^ V_18 ) ;
F_10 ( V_7 , V_14 , & V_21 ) ;
if ( ( V_21 ^ V_20 ) & ~ V_18 ) {
V_22 = - V_23 ;
F_11 ( & V_7 -> V_24 , L_1
L_2 , V_20 , V_21 ) ;
goto V_22;
}
if ( ! ( ( V_21 ^ V_20 ) & V_18 ) ) {
F_12 ( & V_7 -> V_24 , L_3
L_4 ) ;
V_22 = - V_25 ;
goto V_22;
}
F_7 ( V_7 , V_14 , V_20 ) ;
V_22:
F_8 ( V_7 ) ;
return V_22 ;
}
static int T_4 F_13 ( struct V_6 * V_7 ,
const struct V_26 * V_27 )
{
struct V_1 * V_5 ;
int V_22 ;
V_22 = F_14 ( V_7 ) ;
if ( V_22 ) {
F_11 ( & V_7 -> V_24 , L_5 ,
V_28 , V_22 ) ;
return V_22 ;
}
if ( ! V_7 -> V_4 ) {
F_12 ( & V_7 -> V_24 , L_6
L_7 ) ;
F_15 ( V_7 ) ;
return - V_25 ;
}
V_22 = F_9 ( V_7 ) ;
if ( V_22 )
goto V_29;
V_5 = F_16 ( sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_5 ) {
V_22 = - V_31 ;
goto V_32;
}
V_5 -> V_3 . V_33 = L_8 ;
V_5 -> V_3 . V_34 = V_35 ;
V_5 -> V_3 . V_4 = V_7 -> V_4 ;
V_5 -> V_3 . V_36 = V_37 ;
V_5 -> V_3 . V_38 = F_3 ;
V_5 -> V_7 = V_7 ;
if ( F_17 ( & V_7 -> V_24 , & V_5 -> V_3 ) )
goto V_39;
F_18 ( V_7 , V_5 ) ;
return 0 ;
V_39:
F_19 ( V_5 ) ;
V_32:
V_29:
F_15 ( V_7 ) ;
return V_22 ;
}
static void remove ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_20 ( V_7 ) ;
F_21 ( & V_5 -> V_3 ) ;
F_15 ( V_7 ) ;
F_19 ( V_5 ) ;
}
static int T_5 F_22 ( void )
{
F_23 ( V_40 L_9 V_35 L_10 ) ;
return F_24 ( & V_41 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_41 ) ;
}
