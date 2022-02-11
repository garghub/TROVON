static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_2 ( V_11 , struct V_12 ,
V_14 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
const T_3 V_23 = sizeof( V_19 -> V_24 ) ;
const T_3 V_25 = sizeof( struct V_26 ) ;
const T_3 V_27 = F_3 ( V_23 , V_25 ) ;
V_21 = F_4 ( sizeof( * V_21 ) + V_27 , V_28 ) ;
if ( ! V_21 )
return - V_29 ;
V_19 = (struct V_18 * ) V_21 -> V_30 ;
V_19 -> V_24 = V_31 ;
V_21 -> V_32 = V_33 ;
V_21 -> V_34 = V_35 ;
V_21 -> V_36 = V_23 ;
V_21 -> V_37 = V_25 ;
V_22 = F_5 ( V_16 , V_21 ) ;
if ( V_22 < 0 ) {
F_6 ( V_11 , L_1 , V_22 ) ;
F_7 ( V_21 ) ;
return V_22 ;
}
memcpy ( V_7 , V_21 -> V_30 , V_25 ) ;
F_7 ( V_21 ) ;
return V_25 ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_38 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_2 ( V_11 , struct V_12 ,
V_14 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
const T_3 V_23 = sizeof( * V_19 ) ;
const T_3 V_39 = sizeof( V_19 -> V_40 ) ;
if ( V_9 != V_39 )
return - V_41 ;
V_21 = F_4 ( sizeof( * V_21 ) + V_23 , V_28 ) ;
if ( ! V_21 )
return - V_29 ;
V_19 = (struct V_18 * ) V_21 -> V_30 ;
V_19 -> V_24 = V_42 ;
memcpy ( V_19 -> V_40 , V_7 , V_39 ) ;
V_21 -> V_32 = V_33 ;
V_21 -> V_34 = V_35 ;
V_21 -> V_36 = V_23 ;
V_21 -> V_37 = 0 ;
V_22 = F_5 ( V_16 , V_21 ) ;
if ( V_22 < 0 ) {
F_6 ( V_11 , L_2 , V_22 ) ;
F_7 ( V_21 ) ;
return V_22 ;
}
F_7 ( V_21 ) ;
return V_39 ;
}
static T_4 F_9 ( struct V_3 * V_4 ,
struct V_5 * V_43 , int V_44 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_2 ( V_11 , struct V_12 ,
V_14 ) ;
struct V_45 * V_46 = V_13 -> V_17 -> V_11 -> V_47 ;
if ( F_10 ( V_48 ) && V_46 ) {
if ( F_11 ( V_46 , L_3 ) )
return V_43 -> V_38 . V_49 ;
}
return 0 ;
}
