int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 , T_2 V_7 ,
T_2 V_8 , T_2 V_9 , T_3 V_10 , bool V_11 )
{
int V_12 = V_4 -> V_13 ;
struct V_14 * V_15 ;
int V_16 ;
F_2 ( V_4 , V_11 ) ;
V_4 -> V_17 = 0 ;
F_3 ( V_4 , & V_2 -> V_6 ) ;
memset ( F_4 ( V_4 ) , 0 , sizeof( * F_4 ( V_4 ) ) ) ;
F_5 ( V_4 , sizeof( struct V_14 ) ) ;
F_6 ( V_4 ) ;
V_15 = F_7 ( V_4 ) ;
V_15 -> V_18 = 4 ;
V_15 -> V_19 = sizeof( struct V_14 ) >> 2 ;
V_15 -> V_20 = V_10 ;
V_15 -> V_21 = V_7 ;
V_15 -> V_8 = V_8 ;
V_15 -> V_22 = V_6 ;
V_15 -> V_23 = V_5 ;
V_15 -> V_9 = V_9 ;
F_8 ( V_15 , & V_2 -> V_6 , ( F_9 ( V_4 ) -> V_24 ? : 1 ) - 1 ) ;
V_16 = F_10 ( V_4 ) ;
if ( F_11 ( F_12 ( V_16 ) ) )
V_12 = 0 ;
return V_12 ;
}
int F_13 ( struct V_3 * V_4 , int V_25 , T_3 V_26 )
{
if ( F_11 ( ! F_14 ( V_4 , V_25 ) ) )
return - V_27 ;
F_15 ( V_4 , V_25 ) ;
if ( V_26 == F_16 ( V_28 ) ) {
struct V_29 * V_30 = (struct V_29 * ) V_4 -> V_31 ;
if ( F_11 ( ! F_14 ( V_4 , V_32 ) ) )
return - V_27 ;
if ( F_17 ( F_18 ( V_30 -> V_33 ) >= V_34 ) )
V_4 -> V_21 = V_30 -> V_33 ;
else
V_4 -> V_21 = F_16 ( V_35 ) ;
} else {
V_4 -> V_21 = V_26 ;
}
F_19 ( V_4 ) ;
F_20 ( V_4 ) ;
if ( ! V_4 -> V_36 )
V_4 -> V_17 = 0 ;
F_21 ( V_4 ) ;
V_4 -> V_37 = 0 ;
F_22 ( V_4 , 0 ) ;
V_4 -> V_38 = V_39 ;
return 0 ;
}
struct V_3 * F_23 ( struct V_3 * V_4 ,
bool V_40 ,
int V_41 )
{
int V_16 ;
if ( F_17 ( ! V_4 -> V_42 ) ) {
F_24 ( V_4 ) ;
V_4 -> V_42 = 1 ;
}
if ( F_25 ( V_4 ) ) {
V_16 = F_26 ( V_4 , V_43 ) ;
if ( F_11 ( V_16 ) )
goto error;
F_9 ( V_4 ) -> V_44 |= V_41 ;
return V_4 ;
}
if ( V_4 -> V_45 == V_46 && V_40 ) {
V_16 = F_27 ( V_4 ) ;
if ( F_11 ( V_16 ) )
goto error;
} else if ( V_4 -> V_45 != V_46 )
V_4 -> V_45 = V_47 ;
return V_4 ;
error:
F_28 ( V_4 ) ;
return F_29 ( V_16 ) ;
}
