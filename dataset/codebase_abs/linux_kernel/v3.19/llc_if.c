int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 = - V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( F_3 ( V_10 -> V_11 == V_12 ) )
goto V_13;
V_7 = - V_14 ;
if ( F_3 ( F_4 ( V_10 -> V_11 ) ||
V_10 -> V_15 ) ) {
V_10 -> V_16 = 1 ;
goto V_13;
}
V_6 = F_5 ( V_4 ) ;
V_6 -> type = V_17 ;
V_6 -> V_18 = V_19 ;
V_6 -> V_20 = V_21 ;
V_4 -> V_22 = V_10 -> V_22 ;
V_7 = F_6 ( V_2 , V_4 ) ;
V_13:
return V_7 ;
}
int F_7 ( struct V_1 * V_2 , T_1 * V_23 , T_1 * V_24 , T_1 V_25 )
{
int V_7 = - V_26 ;
struct V_27 V_28 , V_29 ;
struct V_3 * V_4 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_1 * V_30 ;
V_28 . V_31 = V_10 -> V_32 -> V_28 . V_31 ;
V_29 . V_31 = V_25 ;
memcpy ( V_29 . V_33 , V_24 , sizeof( V_29 . V_33 ) ) ;
memcpy ( V_28 . V_33 , V_23 , sizeof( V_28 . V_33 ) ) ;
V_30 = F_8 ( V_10 -> V_32 , & V_29 , & V_28 ) ;
if ( V_30 ) {
if ( V_30 -> V_34 == V_35 ) {
V_2 = V_30 ;
goto V_36;
} else
F_9 ( V_30 ) ;
}
F_10 ( V_2 ) ;
V_7 = - V_37 ;
V_4 = F_11 ( 0 , V_38 ) ;
if ( V_4 ) {
struct V_5 * V_6 = F_5 ( V_4 ) ;
V_6 -> type = V_17 ;
V_6 -> V_18 = V_39 ;
V_6 -> V_20 = V_21 ;
F_12 ( V_4 , V_2 ) ;
V_7 = F_6 ( V_2 , V_4 ) ;
}
V_36:
F_9 ( V_2 ) ;
return V_7 ;
}
int F_13 ( struct V_1 * V_2 )
{
T_2 V_7 = 1 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
F_10 ( V_2 ) ;
if ( V_2 -> V_40 != V_41 || V_2 -> V_34 != V_35 ||
F_2 ( V_2 ) -> V_11 == V_12 ||
F_2 ( V_2 ) -> V_11 == V_42 )
goto V_13;
V_4 = F_11 ( 0 , V_38 ) ;
if ( ! V_4 )
goto V_13;
F_12 ( V_4 , V_2 ) ;
V_2 -> V_34 = V_43 ;
V_6 = F_5 ( V_4 ) ;
V_6 -> type = V_17 ;
V_6 -> V_18 = V_44 ;
V_6 -> V_20 = V_21 ;
V_7 = F_6 ( V_2 , V_4 ) ;
V_13:
F_9 ( V_2 ) ;
return V_7 ;
}
