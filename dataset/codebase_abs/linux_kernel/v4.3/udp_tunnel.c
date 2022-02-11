int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
int V_6 ;
struct V_4 * V_7 = NULL ;
struct V_8 V_9 ;
V_6 = F_2 ( V_1 , V_10 , V_11 , 0 , & V_7 ) ;
if ( V_6 < 0 )
goto error;
V_9 . V_12 = V_10 ;
V_9 . V_13 = V_3 -> V_14 ;
V_9 . V_15 = V_3 -> V_16 ;
V_6 = F_3 ( V_7 , (struct V_17 * ) & V_9 ,
sizeof( V_9 ) ) ;
if ( V_6 < 0 )
goto error;
if ( V_3 -> V_18 ) {
V_9 . V_12 = V_10 ;
V_9 . V_13 = V_3 -> V_19 ;
V_9 . V_15 = V_3 -> V_18 ;
V_6 = F_4 ( V_7 , (struct V_17 * ) & V_9 ,
sizeof( V_9 ) , 0 ) ;
if ( V_6 < 0 )
goto error;
}
V_7 -> V_20 -> V_21 = ! V_3 -> V_22 ;
* V_5 = V_7 ;
return 0 ;
error:
if ( V_7 ) {
F_5 ( V_7 , V_23 ) ;
F_6 ( V_7 ) ;
}
* V_5 = NULL ;
return V_6 ;
}
void F_7 ( struct V_1 * V_1 , struct V_4 * V_7 ,
struct V_24 * V_3 )
{
struct V_7 * V_20 = V_7 -> V_20 ;
F_8 ( V_20 ) -> V_25 = 0 ;
F_9 ( V_20 ) ;
F_10 ( V_20 , V_3 -> V_26 ) ;
F_11 ( V_20 ) -> V_27 = V_3 -> V_27 ;
F_11 ( V_20 ) -> V_28 = V_3 -> V_28 ;
F_11 ( V_20 ) -> V_29 = V_3 -> V_29 ;
F_12 ( V_7 ) ;
}
int F_13 ( struct V_30 * V_31 , struct V_7 * V_20 , struct V_32 * V_33 ,
T_1 V_34 , T_1 V_35 , T_2 V_36 , T_2 V_37 ,
T_3 V_38 , T_3 V_39 , T_3 V_40 ,
bool V_41 , bool V_42 )
{
struct V_43 * V_44 ;
F_14 ( V_33 , sizeof( * V_44 ) ) ;
F_15 ( V_33 ) ;
V_44 = F_16 ( V_33 ) ;
V_44 -> V_45 = V_40 ;
V_44 -> V_46 = V_39 ;
V_44 -> V_47 = F_17 ( V_33 -> V_47 ) ;
F_18 ( V_42 , V_33 , V_34 , V_35 , V_33 -> V_47 ) ;
return F_19 ( V_20 , V_31 , V_33 , V_34 , V_35 , V_48 ,
V_36 , V_37 , V_38 , V_41 ) ;
}
void F_20 ( struct V_4 * V_7 )
{
F_10 ( V_7 -> V_20 , NULL ) ;
F_5 ( V_7 , V_23 ) ;
F_6 ( V_7 ) ;
}
struct V_49 * F_21 ( struct V_32 * V_33 , unsigned short V_50 ,
T_3 V_51 , T_4 V_52 , int V_53 )
{
struct V_49 * V_54 ;
struct V_55 * V_56 ;
if ( V_50 == V_10 )
V_54 = F_22 ( V_33 , V_51 , V_52 , V_53 ) ;
else
V_54 = F_23 ( V_33 , V_51 , V_52 , V_53 ) ;
if ( ! V_54 )
return NULL ;
V_56 = & V_54 -> V_57 . V_58 ;
V_56 -> V_59 . V_60 = F_16 ( V_33 ) -> V_46 ;
V_56 -> V_59 . V_61 = F_16 ( V_33 ) -> V_45 ;
if ( F_16 ( V_33 ) -> V_62 )
V_56 -> V_59 . V_63 |= V_64 ;
return V_54 ;
}
