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
F_11 ( V_20 ) -> V_30 = V_3 -> V_30 ;
F_11 ( V_20 ) -> V_31 = V_3 -> V_31 ;
F_12 ( V_7 ) ;
}
void F_13 ( struct V_32 * V_33 , struct V_7 * V_20 , struct V_34 * V_35 ,
T_1 V_36 , T_1 V_37 , T_2 V_38 , T_2 V_39 ,
T_3 V_40 , T_3 V_41 , T_3 V_42 ,
bool V_43 , bool V_44 )
{
struct V_45 * V_46 ;
F_14 ( V_35 , sizeof( * V_46 ) ) ;
F_15 ( V_35 ) ;
V_46 = F_16 ( V_35 ) ;
V_46 -> V_47 = V_42 ;
V_46 -> V_48 = V_41 ;
V_46 -> V_49 = F_17 ( V_35 -> V_49 ) ;
memset ( & ( F_18 ( V_35 ) -> V_50 ) , 0 , sizeof( F_18 ( V_35 ) -> V_50 ) ) ;
F_19 ( V_44 , V_35 , V_36 , V_37 , V_35 -> V_49 ) ;
F_20 ( V_20 , V_33 , V_35 , V_36 , V_37 , V_51 , V_38 , V_39 , V_40 , V_43 ) ;
}
void F_21 ( struct V_4 * V_7 )
{
F_10 ( V_7 -> V_20 , NULL ) ;
F_5 ( V_7 , V_23 ) ;
F_6 ( V_7 ) ;
}
struct V_52 * F_22 ( struct V_34 * V_35 , unsigned short V_53 ,
T_3 V_54 , T_4 V_55 , int V_56 )
{
struct V_52 * V_57 ;
struct V_58 * V_59 ;
if ( V_53 == V_10 )
V_57 = F_23 ( V_35 , V_54 , V_55 , V_56 ) ;
else
V_57 = F_24 ( V_35 , V_54 , V_55 , V_56 ) ;
if ( ! V_57 )
return NULL ;
V_59 = & V_57 -> V_60 . V_61 ;
V_59 -> V_62 . V_63 = F_16 ( V_35 ) -> V_48 ;
V_59 -> V_62 . V_64 = F_16 ( V_35 ) -> V_47 ;
if ( F_16 ( V_35 ) -> V_65 )
V_59 -> V_62 . V_66 |= V_67 ;
return V_57 ;
}
