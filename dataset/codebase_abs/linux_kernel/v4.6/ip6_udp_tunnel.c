int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
struct V_6 V_7 ;
int V_8 ;
struct V_4 * V_9 = NULL ;
V_8 = F_2 ( V_1 , V_10 , V_11 , 0 , & V_9 ) ;
if ( V_8 < 0 )
goto error;
if ( V_3 -> V_12 ) {
int V_13 = 1 ;
V_8 = F_3 ( V_9 , V_14 , V_15 ,
( char * ) & V_13 , sizeof( V_13 ) ) ;
if ( V_8 < 0 )
goto error;
}
V_7 . V_16 = V_10 ;
memcpy ( & V_7 . V_17 , & V_3 -> V_18 ,
sizeof( V_7 . V_17 ) ) ;
V_7 . V_19 = V_3 -> V_20 ;
V_8 = F_4 ( V_9 , (struct V_21 * ) & V_7 ,
sizeof( V_7 ) ) ;
if ( V_8 < 0 )
goto error;
if ( V_3 -> V_22 ) {
V_7 . V_16 = V_10 ;
memcpy ( & V_7 . V_17 , & V_3 -> V_23 ,
sizeof( V_7 . V_17 ) ) ;
V_7 . V_19 = V_3 -> V_22 ;
V_8 = F_5 ( V_9 ,
(struct V_21 * ) & V_7 ,
sizeof( V_7 ) , 0 ) ;
}
if ( V_8 < 0 )
goto error;
F_6 ( V_9 -> V_24 , ! V_3 -> V_25 ) ;
F_7 ( V_9 -> V_24 , ! V_3 -> V_26 ) ;
* V_5 = V_9 ;
return 0 ;
error:
if ( V_9 ) {
F_8 ( V_9 , V_27 ) ;
F_9 ( V_9 ) ;
}
* V_5 = NULL ;
return V_8 ;
}
int F_10 ( struct V_28 * V_29 , struct V_9 * V_24 ,
struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_34 * V_36 ,
T_1 V_37 , T_1 V_38 , T_2 V_39 ,
T_3 V_40 , T_3 V_41 , bool V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
F_11 ( V_31 , sizeof( * V_44 ) ) ;
F_12 ( V_31 ) ;
V_44 = F_13 ( V_31 ) ;
V_44 -> V_47 = V_41 ;
V_44 -> V_48 = V_40 ;
V_44 -> V_49 = F_14 ( V_31 -> V_49 ) ;
memset ( & ( F_15 ( V_31 ) -> V_50 ) , 0 , sizeof( F_15 ( V_31 ) -> V_50 ) ) ;
F_15 ( V_31 ) -> V_51 &= ~ ( V_52 | V_53
| V_54 ) ;
F_16 ( V_31 , V_29 ) ;
F_17 ( V_42 , V_31 , V_35 , V_36 , V_31 -> V_49 ) ;
F_11 ( V_31 , sizeof( * V_46 ) ) ;
F_18 ( V_31 ) ;
V_46 = F_19 ( V_31 ) ;
F_20 ( V_46 , V_37 , V_39 ) ;
V_46 -> V_55 = F_14 ( V_31 -> V_49 ) ;
V_46 -> V_56 = V_57 ;
V_46 -> V_58 = V_38 ;
V_46 -> V_36 = * V_36 ;
V_46 -> V_35 = * V_35 ;
F_21 ( V_24 , V_31 , V_33 ) ;
return 0 ;
}
