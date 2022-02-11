void T_1 F_1 ( void T_2 * V_1 , void T_2 * V_2 )
{
V_3 = V_1 ;
V_4 = V_2 ;
}
int F_2 ( void T_2 * V_5 , T_3 * V_6 ,
T_4 * V_7 )
{
if ( ! V_8 -> V_9 ) {
F_3 ( 1 , L_1 ,
V_10 ) ;
return - V_11 ;
}
return V_8 -> V_9 ( V_5 , V_6 ,
V_7 ) ;
}
int F_4 ( T_4 V_12 , T_3 V_13 , T_5 V_5 ,
T_4 V_14 )
{
if ( ! V_8 -> V_15 ) {
F_3 ( 1 , L_1 ,
V_10 ) ;
return - V_11 ;
}
return V_8 -> V_15 ( V_12 , V_13 , V_5 ,
V_14 ) ;
}
int F_5 ( T_4 V_12 , T_3 V_13 , T_5 V_5 ,
T_4 V_14 )
{
if ( ! V_8 -> V_16 ) {
F_3 ( 1 , L_1 ,
V_10 ) ;
return - V_11 ;
}
return V_8 -> V_16 ( V_12 , V_13 , V_5 ,
V_14 ) ;
}
int F_6 ( T_4 V_17 , T_4 V_12 , T_5 V_18 , T_5 V_19 )
{
if ( ! V_8 -> V_20 ) {
F_3 ( 1 , L_1 ,
V_10 ) ;
return - V_11 ;
}
V_8 -> V_20 ( V_17 , V_12 , V_18 , V_19 ) ;
return 0 ;
}
int F_7 ( T_4 V_12 , T_5 V_18 , T_5 V_19 )
{
if ( ! V_8 -> V_21 ) {
F_3 ( 1 , L_1 ,
V_10 ) ;
return - V_11 ;
}
V_8 -> V_21 ( V_12 , V_18 , V_19 ) ;
return 0 ;
}
int F_8 ( struct V_8 * V_22 )
{
if ( ! V_22 )
return - V_11 ;
if ( V_8 != & V_23 )
return - V_24 ;
V_8 = V_22 ;
return 0 ;
}
int F_9 ( struct V_8 * V_22 )
{
if ( ! V_22 || V_8 != V_22 )
return - V_11 ;
V_8 = & V_23 ;
return 0 ;
}
int T_1 F_10 ( void )
{
struct V_25 * V_26 ;
const struct V_27 * V_28 ;
struct V_29 * V_30 ;
void T_2 * V_31 ;
F_11 (np, omap_cm_dt_match_table, &match) {
V_30 = (struct V_29 * ) V_28 -> V_30 ;
V_31 = F_12 ( V_26 , 0 ) ;
if ( ! V_31 )
return - V_32 ;
if ( V_30 -> V_33 == V_34 )
V_3 = V_31 + V_30 -> V_35 ;
if ( V_30 -> V_33 == V_36 )
V_4 = V_31 + V_30 -> V_35 ;
V_30 -> V_31 = V_31 ;
V_30 -> V_26 = V_26 ;
if ( V_30 -> V_37 && ( V_30 -> V_38 & V_39 ||
( V_3 && V_4 ) ) )
V_30 -> V_37 ( V_30 ) ;
}
return 0 ;
}
int T_1 F_13 ( void )
{
struct V_25 * V_26 ;
const struct V_27 * V_28 ;
const struct V_29 * V_30 ;
int V_40 ;
F_11 (np, omap_cm_dt_match_table, &match) {
V_30 = V_28 -> V_30 ;
if ( V_30 -> V_38 & V_41 )
continue;
V_40 = F_14 ( V_26 , V_30 -> V_33 , NULL , V_30 -> V_31 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
