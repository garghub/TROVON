int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
T_1 V_5 ,
T_2 V_6 ,
T_3 V_7 ,
T_3 V_8 ,
struct V_9 * V_10 )
{
int V_11 = - V_12 ;
struct V_3 * V_13 = NULL ;
T_1 V_14 = V_6 << 16 | V_5 ;
if ( ! V_4 )
return - V_15 ;
V_11 = F_2 ( V_2 , V_4 ) ;
if ( V_11 != 0 )
return V_11 ;
V_13 = * V_4 ;
V_13 -> V_16 . V_17 . V_5 = F_3 ( V_14 ) ;
V_13 -> V_16 . V_17 . V_18 = V_7 ;
V_13 -> V_16 . V_17 . V_19 = V_8 ;
V_13 -> V_20 = V_21 ;
V_13 -> V_22 = V_10 -> V_22 ;
V_13 -> V_23 . V_24 = 0 ;
switch ( V_13 -> V_22 ) {
case V_25 :
V_13 -> V_26 . V_27 = & V_13 -> V_23 ;
break;
case V_28 :
if ( ! V_10 -> V_29 )
return - V_12 ;
V_13 -> V_26 . V_27 = V_10 -> V_29 -> V_27 ;
break;
case V_30 :
if ( ! V_10 -> V_29 )
V_13 -> V_26 . V_31 = NULL ;
else
V_13 -> V_26 = * V_10 -> V_29 ;
break;
default:
F_4 ( V_2 , L_1 ,
V_13 -> V_22 ) ;
return - V_12 ;
}
F_5 ( V_2 , V_32 ,
L_2 ,
V_14 , V_7 , V_8 ,
( unsigned long ) & V_13 -> V_33 ,
F_6 ( V_13 -> V_22 , V_25 ,
V_28 , L_3 , L_4 ,
L_5 ) ) ;
if ( V_10 -> V_34 )
memset ( & V_13 -> V_33 , 0 , V_10 -> V_34 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
enum V_35 V_36 )
{
struct V_9 V_37 ;
struct V_38 * V_39 = NULL ;
T_2 V_40 = F_8 ( V_2 ) ;
T_3 V_41 = V_2 -> V_42 -> V_43 ;
struct V_3 * V_13 = NULL ;
int V_11 = - V_12 ;
F_9 ( V_2 ,
F_10 ( & V_2 -> V_42 -> V_44 ) ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_34 = sizeof( * V_39 ) ;
V_37 . V_22 = V_25 ;
V_11 = F_1 ( V_2 ,
& V_13 ,
F_11 ( V_2 ) ,
V_2 -> V_45 . V_6 ,
V_46 ,
V_47 ,
& V_37 ) ;
if ( V_11 )
return V_11 ;
V_39 = & V_13 -> V_33 . V_48 ;
V_39 -> V_49 = F_12 ( V_40 ) ;
V_39 -> V_50 = V_41 ;
V_39 -> V_51 = F_13 ( V_2 ) ;
V_39 -> V_52 = 0 ;
V_39 -> V_53 = F_12 ( 0xf ) ;
V_39 -> V_35 = V_36 ;
V_39 -> V_54 = V_2 -> V_45 . V_55 ;
V_39 -> V_56 . V_57 =
F_14 ( V_2 -> V_42 -> V_44 . V_58 . V_59 ) ;
V_39 -> V_56 . V_60 =
F_15 ( V_2 -> V_42 -> V_44 . V_58 . V_59 ) ;
V_39 -> V_61 = ( T_3 ) V_2 -> V_42 -> V_44 . V_62 ;
V_39 -> V_63 . V_57 =
F_14 ( V_2 -> V_64 -> V_44 . V_58 . V_59 ) ;
V_39 -> V_63 . V_60 =
F_15 ( V_2 -> V_64 -> V_44 . V_58 . V_59 ) ;
V_2 -> V_45 . V_65 = V_66 ;
F_5 ( V_2 , V_32 ,
L_6 ,
V_40 , V_41 ,
( V_39 -> V_35 == V_67 ) ? L_7 : L_8 ,
V_39 -> V_54 ) ;
return F_16 ( V_2 , V_13 , NULL ) ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_9 V_37 ;
struct V_3 * V_13 = NULL ;
int V_11 = - V_12 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_22 = V_25 ;
V_11 = F_1 ( V_2 , & V_13 , F_11 ( V_2 ) ,
V_2 -> V_45 . V_6 ,
V_68 , V_47 ,
& V_37 ) ;
if ( V_11 )
return V_11 ;
return F_16 ( V_2 , V_13 , NULL ) ;
}
