void T_1 F_1 ( void T_2 * V_1 , void T_2 * V_2 )
{
V_3 . V_4 = V_1 ;
V_5 . V_4 = V_2 ;
}
int F_2 ( struct V_6 * V_7 , T_3 * V_8 ,
T_4 * V_9 )
{
if ( ! V_10 -> V_11 ) {
F_3 ( 1 , L_1 ,
V_12 ) ;
return - V_13 ;
}
return V_10 -> V_11 ( V_7 , V_8 ,
V_9 ) ;
}
int F_4 ( T_4 V_14 , T_3 V_15 , T_5 V_7 ,
T_4 V_16 )
{
if ( ! V_10 -> V_17 ) {
F_3 ( 1 , L_1 ,
V_12 ) ;
return - V_13 ;
}
return V_10 -> V_17 ( V_14 , V_15 , V_7 ,
V_16 ) ;
}
int F_5 ( T_4 V_14 , T_3 V_15 , T_5 V_7 ,
T_4 V_16 )
{
if ( ! V_10 -> V_18 ) {
F_3 ( 1 , L_1 ,
V_12 ) ;
return - V_13 ;
}
return V_10 -> V_18 ( V_14 , V_15 , V_7 ,
V_16 ) ;
}
int F_6 ( T_4 V_19 , T_4 V_14 , T_5 V_20 , T_5 V_21 )
{
if ( ! V_10 -> V_22 ) {
F_3 ( 1 , L_1 ,
V_12 ) ;
return - V_13 ;
}
V_10 -> V_22 ( V_19 , V_14 , V_20 , V_21 ) ;
return 0 ;
}
int F_7 ( T_4 V_14 , T_5 V_20 , T_5 V_21 )
{
if ( ! V_10 -> V_23 ) {
F_3 ( 1 , L_1 ,
V_12 ) ;
return - V_13 ;
}
V_10 -> V_23 ( V_14 , V_20 , V_21 ) ;
return 0 ;
}
int F_8 ( struct V_10 * V_24 )
{
if ( ! V_24 )
return - V_13 ;
if ( V_10 != & V_25 )
return - V_26 ;
V_10 = V_24 ;
return 0 ;
}
int F_9 ( struct V_10 * V_24 )
{
if ( ! V_24 || V_10 != V_24 )
return - V_13 ;
V_10 = & V_25 ;
return 0 ;
}
int T_1 F_10 ( void )
{
struct V_27 * V_28 ;
const struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
int V_35 ;
struct V_36 * V_37 = NULL ;
F_11 (np, omap_cm_dt_match_table, &match) {
V_32 = (struct V_31 * ) V_30 -> V_32 ;
V_35 = F_12 ( V_28 , 0 , & V_34 ) ;
if ( V_35 )
return V_35 ;
if ( V_32 -> V_38 == V_39 )
V_37 = & V_3 ;
if ( V_32 -> V_38 == V_40 )
V_37 = & V_5 ;
V_32 -> V_37 = F_13 ( V_34 . V_41 , F_14 ( & V_34 ) ) ;
if ( V_37 ) {
V_37 -> V_42 = V_34 . V_41 + V_32 -> V_43 ;
V_37 -> V_4 = V_32 -> V_37 + V_32 -> V_43 ;
}
V_32 -> V_28 = V_28 ;
if ( V_32 -> V_44 && ( V_32 -> V_45 & V_46 ||
( V_3 . V_4 && V_5 . V_4 ) ) )
V_32 -> V_44 ( V_32 ) ;
}
return 0 ;
}
int T_1 F_15 ( void )
{
struct V_27 * V_28 ;
const struct V_29 * V_30 ;
const struct V_31 * V_32 ;
int V_35 ;
F_11 (np, omap_cm_dt_match_table, &match) {
V_32 = V_30 -> V_32 ;
if ( V_32 -> V_45 & V_47 )
continue;
V_35 = F_16 ( V_28 , V_32 -> V_38 , NULL , V_32 -> V_37 ) ;
if ( V_35 )
return V_35 ;
}
return 0 ;
}
