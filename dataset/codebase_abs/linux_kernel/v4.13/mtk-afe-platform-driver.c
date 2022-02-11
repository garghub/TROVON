static T_1 F_1
( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_4 -> V_11 -> V_12 ] ;
const struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_16 = V_7 -> V_16 ;
struct V_17 * V_18 = V_7 -> V_18 ;
int V_19 = V_14 -> V_19 ;
int V_20 = V_14 -> V_20 ;
unsigned int V_21 = 0 , V_22 = 0 ;
int V_23 , V_24 ;
V_23 = F_3 ( V_16 , V_20 , & V_21 ) ;
if ( V_23 || V_21 == 0 ) {
F_4 ( V_18 , L_1 , V_25 ) ;
V_24 = 0 ;
goto V_26;
}
V_23 = F_3 ( V_16 , V_19 , & V_22 ) ;
if ( V_23 || V_22 == 0 ) {
F_4 ( V_18 , L_1 , V_25 ) ;
V_24 = 0 ;
goto V_26;
}
V_24 = V_21 - V_22 ;
V_26:
return F_5 ( V_2 -> V_27 , V_24 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
T_2 V_28 ;
struct V_29 * V_30 = V_4 -> V_30 -> V_29 ;
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
V_28 = V_7 -> V_33 -> V_34 ;
return F_7 ( V_32 , V_35 ,
V_30 -> V_18 , V_28 , V_28 ) ;
}
static void F_8 ( struct V_31 * V_32 )
{
F_9 ( V_32 ) ;
}
