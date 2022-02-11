T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 , V_7 ;
T_1 V_8 ;
T_3 V_9 = V_5 -> V_10 ;
int V_11 ;
V_2 -> V_12 [ V_9 - 1 ] . V_13 = V_14 ;
switch ( V_5 -> V_15 ) {
case V_16 :
break;
case V_17 :
V_8 = F_2 ( V_2 -> V_18 ,
V_3 -> V_19 ,
V_3 -> V_20 . V_21 ,
( T_2 ) V_5 -> V_10 ,
& V_6 , & V_7 ) ;
if ( V_8 != V_22 ) {
F_3 ( & V_2 -> V_23 ,
L_1 ,
V_9 , V_8 ) ;
return V_8 ;
}
V_2 -> V_12 [ V_9 - 1 ] . V_6 = V_6 ;
F_4 ( & V_2 -> V_23 , L_2 ,
V_9 , V_6 ) ;
break;
default:
F_3 ( & V_2 -> V_23 , L_3 ,
V_5 -> V_15 ) ;
return V_24 ;
}
if ( V_25 < 0 )
return V_22 ;
for ( V_11 = 0 ;
V_2 -> V_12 [ V_9 - 1 ] . V_13 != V_26 &&
V_11 < V_27 ;
V_11 ++ ) {
F_4 ( & V_2 -> V_23 , L_4 ,
V_9 ) ;
F_5 ( 1000 ) ;
}
if ( V_11 == V_27 ) {
F_3 ( & V_2 -> V_23 , L_5 , V_9 ) ;
return V_28 ;
}
return V_22 ;
}
static int F_6 ( struct V_23 * V_29 , T_3 V_10 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
struct V_34 * V_35 , struct V_34 * V_36 )
{
struct V_37 * V_38 = (struct V_37 * ) V_35 ;
struct V_37 * V_39 = (struct V_37 * ) V_36 ;
struct V_40 * V_41 =
(struct V_40 * ) V_39 -> V_42 ;
struct V_43 * V_43 =
(struct V_43 * ) & V_41 -> V_44 ;
struct V_1 * V_2 =
F_7 ( V_29 , struct V_1 , V_23 ) ;
struct V_45 * V_12 = & V_2 -> V_12 [ V_10 - 1 ] ;
F_4 ( V_29 , L_6 , V_38 -> V_46 . V_47 ) ;
* V_36 = * V_35 ;
if ( V_38 -> V_46 . V_48 != 1 ) {
F_8 ( V_29 , L_7 ,
V_38 -> V_46 . V_48 ) ;
V_39 -> V_46 . V_49 = V_50 ;
goto V_51;
}
switch ( V_38 -> V_46 . V_47 ) {
case V_52 :
case V_53 :
V_39 -> V_46 . V_54 = V_55 ;
V_39 -> V_46 . V_49 = V_56 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_57 = 1 ;
V_41 -> V_48 = 1 ;
V_41 -> V_58 = 18 ;
V_43 -> V_59 = V_31 -> V_59 ;
V_41 -> V_60 =
V_12 -> V_61 . V_62 | V_31 -> V_63 ;
V_41 -> V_64 = V_12 -> V_6 ;
V_41 -> V_65 = V_66 ;
F_9 ( V_29 , V_10 , V_31 -> V_67 ,
& V_41 -> V_68 ) ;
if ( V_33 ) {
struct V_69 * V_69 =
(struct V_69 * ) & V_33 -> V_70 ;
memcpy ( V_41 -> V_71 , V_33 -> V_72 . V_73 ,
sizeof( V_41 -> V_71 ) ) ;
V_43 -> V_74 = V_69 -> V_74 ;
V_43 -> V_75 = V_69 -> V_75 ;
} else
F_10 ( V_29 , V_10 , 0 ,
(union V_76 * ) & V_41 -> V_71 ) ;
F_4 ( V_29 , L_8 ,
V_12 -> V_61 . V_62 , V_12 -> V_6 ) ;
break;
case V_77 :
return V_78 ;
default:
V_39 -> V_46 . V_49 = V_79 ;
break;
}
V_51:
V_39 -> V_46 . V_47 = V_77 ;
return V_80 | V_81 ;
}
int F_11 ( struct V_23 * V_29 , int V_82 , T_3 V_10 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
struct V_34 * V_35 , struct V_34 * V_36 )
{
int V_8 ;
if ( ! V_10 || V_10 > V_29 -> V_83 || ! V_31 )
return V_78 ;
if ( V_35 -> V_46 . V_84 != V_85 )
return V_80 ;
F_4 ( V_29 , L_9 , V_10 , V_31 -> V_86 ) ;
V_8 = F_6 ( V_29 , V_10 , V_31 , V_33 ,
V_35 , V_36 ) ;
return V_8 ;
}
