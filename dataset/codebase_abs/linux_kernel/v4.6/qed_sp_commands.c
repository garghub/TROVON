int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
T_1 V_5 ,
T_1 V_6 ,
struct V_7 * V_8 )
{
T_2 V_9 = V_8 -> V_10 << 16 | V_8 -> V_11 ;
struct V_3 * V_12 = NULL ;
int V_13 ;
if ( ! V_4 )
return - V_14 ;
V_13 = F_2 ( V_2 , V_4 ) ;
if ( V_13 != 0 )
return V_13 ;
V_12 = * V_4 ;
V_12 -> V_15 . V_16 . V_11 = F_3 ( V_9 ) ;
V_12 -> V_15 . V_16 . V_17 = V_5 ;
V_12 -> V_15 . V_16 . V_18 = V_6 ;
V_12 -> V_19 = V_20 ;
V_12 -> V_21 = V_8 -> V_21 ;
V_12 -> V_22 . V_23 = 0 ;
switch ( V_12 -> V_21 ) {
case V_24 :
V_12 -> V_25 . V_26 = & V_12 -> V_22 ;
break;
case V_27 :
if ( ! V_8 -> V_28 )
return - V_29 ;
V_12 -> V_25 . V_26 = V_8 -> V_28 -> V_26 ;
break;
case V_30 :
if ( ! V_8 -> V_28 )
V_12 -> V_25 . V_31 = NULL ;
else
V_12 -> V_25 = * V_8 -> V_28 ;
break;
default:
F_4 ( V_2 , L_1 ,
V_12 -> V_21 ) ;
return - V_29 ;
}
F_5 ( V_2 , V_32 ,
L_2 ,
V_9 , V_5 , V_6 ,
( unsigned long ) & V_12 -> V_33 ,
F_6 ( V_12 -> V_21 , V_24 ,
V_27 , L_3 , L_4 ,
L_5 ) ) ;
memset ( & V_12 -> V_33 , 0 , sizeof( V_12 -> V_33 ) ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_36 * V_37 = NULL ;
T_3 V_38 = F_8 ( V_2 ) ;
T_1 V_39 = V_2 -> V_40 -> V_41 ;
struct V_3 * V_12 = NULL ;
struct V_7 V_42 ;
int V_13 = - V_29 ;
F_9 ( V_2 ,
F_10 ( & V_2 -> V_40 -> V_43 ) ) ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_11 = F_11 ( V_2 ) ;
V_42 . V_10 = V_2 -> V_44 . V_10 ;
V_42 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_45 ,
V_46 ,
& V_42 ) ;
if ( V_13 )
return V_13 ;
V_37 = & V_12 -> V_33 . V_47 ;
V_37 -> V_48 = F_12 ( V_38 ) ;
V_37 -> V_49 = V_39 ;
V_37 -> V_50 = F_13 ( V_2 ) ;
V_37 -> V_51 = 0 ;
V_37 -> V_52 = F_12 ( 0xf ) ;
V_37 -> V_53 = V_35 ;
switch ( V_35 ) {
case V_54 :
case V_55 :
V_37 -> V_53 = V_56 ;
break;
case V_57 :
V_37 -> V_53 = V_58 ;
break;
default:
F_4 ( V_2 , L_6 ) ;
V_37 -> V_53 = V_56 ;
}
V_37 -> V_59 = V_2 -> V_44 . V_60 ;
F_14 ( V_37 -> V_61 ,
V_2 -> V_40 -> V_43 . V_62 . V_63 ) ;
V_37 -> V_64 = ( T_1 ) V_2 -> V_40 -> V_43 . V_65 ;
F_14 ( V_37 -> V_66 ,
V_2 -> V_67 -> V_43 . V_62 . V_63 ) ;
V_2 -> V_44 . V_68 = V_69 ;
F_5 ( V_2 , V_32 ,
L_7 ,
V_38 , V_39 ,
V_37 -> V_59 ) ;
return F_15 ( V_2 , V_12 , NULL ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_12 = NULL ;
struct V_7 V_42 ;
int V_13 = - V_29 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_11 = F_11 ( V_2 ) ;
V_42 . V_10 = V_2 -> V_44 . V_10 ;
V_42 . V_21 = V_24 ;
V_13 = F_1 ( V_2 , & V_12 ,
V_70 , V_46 ,
& V_42 ) ;
if ( V_13 )
return V_13 ;
return F_15 ( V_2 , V_12 , NULL ) ;
}
