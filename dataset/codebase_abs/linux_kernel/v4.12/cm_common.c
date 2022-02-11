void T_1 F_1 ( void T_2 * V_1 , void T_2 * V_2 )
{
V_3 = V_1 ;
V_4 = V_2 ;
}
int F_2 ( struct V_5 * V_6 , T_3 * V_7 ,
T_4 * V_8 )
{
if ( ! V_9 -> V_10 ) {
F_3 ( 1 , L_1 ,
V_11 ) ;
return - V_12 ;
}
return V_9 -> V_10 ( V_6 , V_7 ,
V_8 ) ;
}
int F_4 ( T_4 V_13 , T_3 V_14 , T_5 V_6 ,
T_4 V_15 )
{
if ( ! V_9 -> V_16 ) {
F_3 ( 1 , L_1 ,
V_11 ) ;
return - V_12 ;
}
return V_9 -> V_16 ( V_13 , V_14 , V_6 ,
V_15 ) ;
}
int F_5 ( T_4 V_13 , T_3 V_14 , T_5 V_6 ,
T_4 V_15 )
{
if ( ! V_9 -> V_17 ) {
F_3 ( 1 , L_1 ,
V_11 ) ;
return - V_12 ;
}
return V_9 -> V_17 ( V_13 , V_14 , V_6 ,
V_15 ) ;
}
int F_6 ( T_4 V_18 , T_4 V_13 , T_5 V_19 , T_5 V_20 )
{
if ( ! V_9 -> V_21 ) {
F_3 ( 1 , L_1 ,
V_11 ) ;
return - V_12 ;
}
V_9 -> V_21 ( V_18 , V_13 , V_19 , V_20 ) ;
return 0 ;
}
int F_7 ( T_4 V_13 , T_5 V_19 , T_5 V_20 )
{
if ( ! V_9 -> V_22 ) {
F_3 ( 1 , L_1 ,
V_11 ) ;
return - V_12 ;
}
V_9 -> V_22 ( V_13 , V_19 , V_20 ) ;
return 0 ;
}
int F_8 ( struct V_9 * V_23 )
{
if ( ! V_23 )
return - V_12 ;
if ( V_9 != & V_24 )
return - V_25 ;
V_9 = V_23 ;
return 0 ;
}
int F_9 ( struct V_9 * V_23 )
{
if ( ! V_23 || V_9 != V_23 )
return - V_12 ;
V_9 = & V_24 ;
return 0 ;
}
int T_1 F_10 ( void )
{
struct V_26 * V_27 ;
const struct V_28 * V_29 ;
struct V_30 * V_31 ;
void T_2 * V_32 ;
F_11 (np, omap_cm_dt_match_table, &match) {
V_31 = (struct V_30 * ) V_29 -> V_31 ;
V_32 = F_12 ( V_27 , 0 ) ;
if ( ! V_32 )
return - V_33 ;
if ( V_31 -> V_34 == V_35 )
V_3 = V_32 + V_31 -> V_36 ;
if ( V_31 -> V_34 == V_37 )
V_4 = V_32 + V_31 -> V_36 ;
V_31 -> V_32 = V_32 ;
V_31 -> V_27 = V_27 ;
if ( V_31 -> V_38 && ( V_31 -> V_39 & V_40 ||
( V_3 && V_4 ) ) )
V_31 -> V_38 ( V_31 ) ;
}
return 0 ;
}
int T_1 F_13 ( void )
{
struct V_26 * V_27 ;
const struct V_28 * V_29 ;
const struct V_30 * V_31 ;
int V_41 ;
F_11 (np, omap_cm_dt_match_table, &match) {
V_31 = V_29 -> V_31 ;
if ( V_31 -> V_39 & V_42 )
continue;
V_41 = F_14 ( V_27 , V_31 -> V_34 , NULL , V_31 -> V_32 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
