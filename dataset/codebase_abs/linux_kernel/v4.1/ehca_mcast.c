int F_1 ( struct V_1 * V_2 , union V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_1 ) ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 , struct V_8 ,
V_11 ) ;
union V_3 V_12 ;
T_2 V_13 , V_14 , V_15 ;
if ( V_2 -> V_16 != V_17 ) {
F_3 ( V_2 -> V_10 , L_1 , V_2 -> V_16 ) ;
return - V_18 ;
}
if ( ! ( F_4 ( V_4 -> V_19 ) ) ) {
F_3 ( V_2 -> V_10 , L_2 ) ;
return - V_18 ;
} else if ( ( V_5 < V_20 ) || ( V_5 > V_21 ) ) {
F_3 ( V_2 -> V_10 , L_3 , V_5 ) ;
return - V_18 ;
}
memcpy ( & V_12 , V_4 -> V_19 , sizeof( union V_3 ) ) ;
V_13 = F_5 ( V_12 . V_22 . V_13 ) ;
V_14 = F_5 ( V_12 . V_22 . V_14 ) ;
V_15 = F_6 ( V_9 -> V_23 ,
V_7 -> V_24 ,
V_7 -> V_25 . V_26 ,
V_5 , V_13 , V_14 ) ;
if ( V_15 != V_27 )
F_3 ( V_2 -> V_10 ,
L_4
L_5 , V_7 , V_2 -> V_28 , V_15 ) ;
return F_7 ( V_15 ) ;
}
int F_8 ( struct V_1 * V_2 , union V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_1 ) ;
struct V_8 * V_9 = F_2 ( V_2 -> V_29 -> V_10 ,
struct V_8 , V_11 ) ;
union V_3 V_12 ;
T_2 V_13 , V_14 , V_15 ;
if ( V_2 -> V_16 != V_17 ) {
F_3 ( V_2 -> V_10 , L_6 , V_2 -> V_16 ) ;
return - V_18 ;
}
if ( ! ( F_4 ( V_4 -> V_19 ) ) ) {
F_3 ( V_2 -> V_10 , L_2 ) ;
return - V_18 ;
} else if ( ( V_5 < V_20 ) || ( V_5 > V_21 ) ) {
F_3 ( V_2 -> V_10 , L_3 , V_5 ) ;
return - V_18 ;
}
memcpy ( & V_12 , V_4 -> V_19 , sizeof( union V_3 ) ) ;
V_13 = F_5 ( V_12 . V_22 . V_13 ) ;
V_14 = F_5 ( V_12 . V_22 . V_14 ) ;
V_15 = F_9 ( V_9 -> V_23 ,
V_7 -> V_24 ,
V_7 -> V_25 . V_26 ,
V_5 , V_13 , V_14 ) ;
if ( V_15 != V_27 )
F_3 ( V_2 -> V_10 ,
L_7
L_5 , V_7 , V_2 -> V_28 , V_15 ) ;
return F_7 ( V_15 ) ;
}
