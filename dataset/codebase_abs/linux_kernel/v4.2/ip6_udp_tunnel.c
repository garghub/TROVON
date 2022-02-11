int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
struct V_6 V_7 ;
int V_8 ;
struct V_4 * V_9 = NULL ;
V_8 = F_2 ( V_1 , V_10 , V_11 , 0 , & V_9 ) ;
if ( V_8 < 0 )
goto error;
V_7 . V_12 = V_10 ;
memcpy ( & V_7 . V_13 , & V_3 -> V_14 ,
sizeof( V_7 . V_13 ) ) ;
V_7 . V_15 = V_3 -> V_16 ;
V_8 = F_3 ( V_9 , (struct V_17 * ) & V_7 ,
sizeof( V_7 ) ) ;
if ( V_8 < 0 )
goto error;
if ( V_3 -> V_18 ) {
V_7 . V_12 = V_10 ;
memcpy ( & V_7 . V_13 , & V_3 -> V_19 ,
sizeof( V_7 . V_13 ) ) ;
V_7 . V_15 = V_3 -> V_18 ;
V_8 = F_4 ( V_9 ,
(struct V_17 * ) & V_7 ,
sizeof( V_7 ) , 0 ) ;
}
if ( V_8 < 0 )
goto error;
F_5 ( V_9 -> V_20 , ! V_3 -> V_21 ) ;
F_6 ( V_9 -> V_20 , ! V_3 -> V_22 ) ;
* V_5 = V_9 ;
return 0 ;
error:
if ( V_9 ) {
F_7 ( V_9 , V_23 ) ;
F_8 ( V_9 ) ;
}
* V_5 = NULL ;
return V_8 ;
}
int F_9 ( struct V_24 * V_25 , struct V_9 * V_20 ,
struct V_26 * V_27 ,
struct V_28 * V_29 , struct V_30 * V_31 ,
struct V_30 * V_32 ,
T_1 V_33 , T_1 V_34 , T_2 V_35 ,
T_2 V_36 , bool V_37 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
F_10 ( V_27 , sizeof( * V_39 ) ) ;
F_11 ( V_27 ) ;
V_39 = F_12 ( V_27 ) ;
V_39 -> V_42 = V_36 ;
V_39 -> V_43 = V_35 ;
V_39 -> V_44 = F_13 ( V_27 -> V_44 ) ;
memset ( & ( F_14 ( V_27 ) -> V_45 ) , 0 , sizeof( F_14 ( V_27 ) -> V_45 ) ) ;
F_14 ( V_27 ) -> V_46 &= ~ ( V_47 | V_48
| V_49 ) ;
F_15 ( V_27 , V_25 ) ;
F_16 ( V_37 , V_27 , V_31 , V_32 , V_27 -> V_44 ) ;
F_10 ( V_27 , sizeof( * V_41 ) ) ;
F_17 ( V_27 ) ;
V_41 = F_18 ( V_27 ) ;
F_19 ( V_41 , V_33 , F_20 ( 0 ) ) ;
V_41 -> V_50 = F_13 ( V_27 -> V_44 ) ;
V_41 -> V_51 = V_52 ;
V_41 -> V_53 = V_34 ;
V_41 -> V_32 = * V_32 ;
V_41 -> V_31 = * V_31 ;
F_21 ( V_20 , V_27 , V_29 ) ;
return 0 ;
}
