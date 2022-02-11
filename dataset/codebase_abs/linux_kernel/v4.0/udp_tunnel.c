int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
int V_6 ;
struct V_4 * V_7 = NULL ;
struct V_8 V_9 ;
V_6 = F_2 ( V_10 , V_11 , 0 , & V_7 ) ;
if ( V_6 < 0 )
goto error;
F_3 ( V_7 -> V_12 , V_1 ) ;
V_9 . V_13 = V_10 ;
V_9 . V_14 = V_3 -> V_15 ;
V_9 . V_16 = V_3 -> V_17 ;
V_6 = F_4 ( V_7 , (struct V_18 * ) & V_9 ,
sizeof( V_9 ) ) ;
if ( V_6 < 0 )
goto error;
if ( V_3 -> V_19 ) {
V_9 . V_13 = V_10 ;
V_9 . V_14 = V_3 -> V_20 ;
V_9 . V_16 = V_3 -> V_19 ;
V_6 = F_5 ( V_7 , (struct V_18 * ) & V_9 ,
sizeof( V_9 ) , 0 ) ;
if ( V_6 < 0 )
goto error;
}
V_7 -> V_12 -> V_21 = ! V_3 -> V_22 ;
* V_5 = V_7 ;
return 0 ;
error:
if ( V_7 ) {
F_6 ( V_7 , V_23 ) ;
F_7 ( V_7 -> V_12 ) ;
}
* V_5 = NULL ;
return V_6 ;
}
void F_8 ( struct V_1 * V_1 , struct V_4 * V_7 ,
struct V_24 * V_3 )
{
struct V_7 * V_12 = V_7 -> V_12 ;
F_9 ( V_12 ) -> V_25 = 0 ;
F_10 ( V_12 ) ;
F_11 ( V_12 , V_3 -> V_26 ) ;
F_12 ( V_12 ) -> V_27 = V_3 -> V_27 ;
F_12 ( V_12 ) -> V_28 = V_3 -> V_28 ;
F_12 ( V_12 ) -> V_29 = V_3 -> V_29 ;
F_13 ( V_7 ) ;
}
int F_14 ( struct V_30 * V_31 , struct V_32 * V_33 ,
T_1 V_34 , T_1 V_35 , T_2 V_36 , T_2 V_37 ,
T_3 V_38 , T_3 V_39 , T_3 V_40 ,
bool V_41 , bool V_42 )
{
struct V_43 * V_44 ;
F_15 ( V_33 , sizeof( * V_44 ) ) ;
F_16 ( V_33 ) ;
V_44 = F_17 ( V_33 ) ;
V_44 -> V_45 = V_40 ;
V_44 -> V_46 = V_39 ;
V_44 -> V_47 = F_18 ( V_33 -> V_47 ) ;
F_19 ( V_42 , V_33 , V_34 , V_35 , V_33 -> V_47 ) ;
return F_20 ( V_33 -> V_12 , V_31 , V_33 , V_34 , V_35 , V_48 ,
V_36 , V_37 , V_38 , V_41 ) ;
}
void F_21 ( struct V_4 * V_7 )
{
F_11 ( V_7 -> V_12 , NULL ) ;
F_6 ( V_7 , V_23 ) ;
F_7 ( V_7 -> V_12 ) ;
}
