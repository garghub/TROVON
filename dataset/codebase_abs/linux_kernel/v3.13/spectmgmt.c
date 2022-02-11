int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 ,
enum V_6 V_7 ,
T_1 V_8 , T_2 * V_9 ,
struct V_10 * V_11 )
{
enum V_6 V_12 ;
int V_13 ;
T_2 V_14 ;
struct V_15 * V_16 ;
struct V_17 V_18 = {} ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
const struct V_23 * V_24 ;
int V_25 = - 1 ;
V_20 = V_4 -> V_20 ;
V_22 = V_4 -> V_22 ;
V_24 = V_4 -> V_26 ;
if ( V_8 & ( V_27 |
V_28 ) ) {
V_20 = NULL ;
V_22 = NULL ;
V_24 = NULL ;
}
if ( V_8 & V_29 )
V_22 = NULL ;
if ( V_4 -> V_30 ) {
if ( ! F_2 (
V_4 -> V_30 -> V_31 ,
& V_12 ) ) {
F_3 ( V_2 ,
L_1 ,
V_4 -> V_30 -> V_31 ) ;
return - V_32 ;
}
V_14 = V_4 -> V_30 -> V_33 ;
V_11 -> V_34 = V_4 -> V_30 -> V_34 ;
V_11 -> V_35 = V_4 -> V_30 -> V_35 ;
} else if ( V_4 -> V_36 ) {
V_12 = V_7 ;
V_14 = V_4 -> V_36 -> V_33 ;
V_11 -> V_34 = V_4 -> V_36 -> V_34 ;
V_11 -> V_35 = V_4 -> V_36 -> V_35 ;
} else {
return 1 ;
}
if ( V_4 -> V_37 ) {
V_11 -> V_38 = V_4 -> V_37 -> V_39 ;
V_11 -> V_35 = V_4 -> V_37 -> V_40 ;
V_11 -> V_41 = F_4 (
V_4 -> V_37 -> V_42 ) ;
}
V_13 = F_5 ( V_14 , V_12 ) ;
V_16 = F_6 ( V_2 -> V_43 -> V_44 . V_45 , V_13 ) ;
if ( ! V_16 || V_16 -> V_46 & V_47 ) {
F_3 ( V_2 ,
L_2 ,
V_9 , V_13 ) ;
return - V_32 ;
}
if ( ! V_5 && V_20 ) {
V_25 = V_20 -> V_20 ;
} else if ( V_5 && V_24 ) {
V_25 =
V_24 -> V_48 & V_49 ;
} else if ( ! ( V_8 & V_27 ) ) {
V_25 = V_50 ;
}
switch ( V_25 ) {
default:
case V_50 :
F_7 ( & V_11 -> V_51 , V_16 ,
V_52 ) ;
break;
case V_53 :
F_7 ( & V_11 -> V_51 , V_16 ,
V_54 ) ;
break;
case V_55 :
F_7 ( & V_11 -> V_51 , V_16 ,
V_56 ) ;
break;
case - 1 :
F_7 ( & V_11 -> V_51 , V_16 ,
V_57 ) ;
switch ( V_2 -> V_58 . V_59 . V_51 . V_60 ) {
case V_61 :
case V_62 :
V_11 -> V_51 . V_60 =
V_2 -> V_58 . V_59 . V_51 . V_60 ;
break;
default:
break;
}
break;
}
if ( V_22 ) {
V_18 . V_63 = V_16 ;
V_18 . V_64 =
F_5 (
V_22 -> V_65 ,
V_12 ) ;
switch ( V_22 -> V_66 ) {
default:
case V_67 :
V_18 . V_63 = NULL ;
break;
case V_68 :
V_18 . V_60 = V_69 ;
break;
case V_70 :
V_18 . V_60 = V_71 ;
break;
case V_72 :
V_18 . V_73 =
F_5 (
V_22 -> V_74 ,
V_12 ) ;
V_18 . V_60 = V_75 ;
break;
}
if ( V_8 & V_76 &&
V_18 . V_60 == V_75 )
F_8 ( & V_18 ) ;
if ( V_8 & V_77 &&
V_18 . V_60 == V_71 )
F_8 ( & V_18 ) ;
if ( V_8 & V_28 &&
V_18 . V_60 > V_78 )
F_8 ( & V_18 ) ;
}
if ( V_18 . V_63 ) {
if ( ! F_9 ( & V_18 ,
& V_11 -> V_51 ) ) {
F_3 ( V_2 ,
L_3 ,
V_9 ) ;
return - V_32 ;
}
V_11 -> V_51 = V_18 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
const T_2 * V_81 , const T_2 * V_9 ,
T_2 V_82 )
{
struct V_83 * V_43 = V_2 -> V_43 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
V_85 = F_11 ( sizeof( * V_87 ) + V_43 -> V_44 . V_88 +
sizeof( struct V_79 ) ) ;
if ( ! V_85 )
return;
F_12 ( V_85 , V_43 -> V_44 . V_88 ) ;
V_87 = (struct V_86 * ) F_13 ( V_85 , 24 ) ;
memset ( V_87 , 0 , 24 ) ;
memcpy ( V_87 -> V_81 , V_81 , V_89 ) ;
memcpy ( V_87 -> V_90 , V_2 -> V_58 . V_91 , V_89 ) ;
memcpy ( V_87 -> V_9 , V_9 , V_89 ) ;
V_87 -> V_92 = F_14 ( V_93 |
V_94 ) ;
F_13 ( V_85 , 1 + sizeof( V_87 -> V_95 . V_96 . V_95 . V_97 ) ) ;
V_87 -> V_95 . V_96 . V_98 = V_99 ;
V_87 -> V_95 . V_96 . V_95 . V_97 . V_100 =
V_101 ;
V_87 -> V_95 . V_96 . V_95 . V_97 . V_82 = V_82 ;
V_87 -> V_95 . V_96 . V_95 . V_97 . V_102 = V_103 ;
V_87 -> V_95 . V_96 . V_95 . V_97 . V_104 =
sizeof( struct V_79 ) ;
memset ( & V_87 -> V_95 . V_96 . V_95 . V_97 . V_105 , 0 ,
sizeof( struct V_79 ) ) ;
V_87 -> V_95 . V_96 . V_95 . V_97 . V_105 . V_106 = V_80 -> V_106 ;
V_87 -> V_95 . V_96 . V_95 . V_97 . V_105 . V_35 |=
V_107 ;
V_87 -> V_95 . V_96 . V_95 . V_97 . V_105 . type = V_80 -> type ;
F_15 ( V_2 , V_85 ) ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_86 * V_108 ,
T_3 V_109 )
{
F_10 ( V_2 ,
& V_108 -> V_95 . V_96 . V_95 . V_97 . V_105 ,
V_108 -> V_90 , V_108 -> V_9 ,
V_108 -> V_95 . V_96 . V_95 . V_97 . V_82 ) ;
}
