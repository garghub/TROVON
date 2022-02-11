int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
T_1 V_7 , T_2 * V_8 ,
struct V_9 * V_10 )
{
enum V_5 V_11 ;
int V_12 ;
T_2 V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 = {} ;
const struct V_18 * V_19 ;
const struct V_20 * V_21 ;
int V_22 = - 1 ;
V_19 = V_4 -> V_19 ;
V_21 = V_4 -> V_21 ;
if ( V_7 & ( V_23 |
V_24 ) ) {
V_19 = NULL ;
V_21 = NULL ;
}
if ( V_7 & V_25 )
V_21 = NULL ;
if ( V_4 -> V_26 ) {
if ( ! F_2 (
V_4 -> V_26 -> V_27 ,
& V_11 ) ) {
F_3 ( V_2 ,
L_1 ,
V_4 -> V_26 -> V_27 ) ;
return - V_28 ;
}
V_13 = V_4 -> V_26 -> V_29 ;
V_10 -> V_30 = V_4 -> V_26 -> V_30 ;
V_10 -> V_31 = V_4 -> V_26 -> V_31 ;
} else if ( V_4 -> V_32 ) {
V_11 = V_6 ;
V_13 = V_4 -> V_32 -> V_29 ;
V_10 -> V_30 = V_4 -> V_32 -> V_30 ;
V_10 -> V_31 = V_4 -> V_32 -> V_31 ;
} else {
return 1 ;
}
if ( V_4 -> V_33 ) {
V_10 -> V_34 = V_4 -> V_33 -> V_35 ;
V_10 -> V_31 = V_4 -> V_33 -> V_36 ;
V_10 -> V_37 = F_4 (
V_4 -> V_33 -> V_38 ) ;
}
V_12 = F_5 ( V_13 , V_11 ) ;
V_15 = F_6 ( V_2 -> V_39 -> V_40 . V_41 , V_12 ) ;
if ( ! V_15 || V_15 -> V_42 & V_43 ) {
F_3 ( V_2 ,
L_2 ,
V_8 , V_12 ) ;
return - V_28 ;
}
if ( V_19 ) {
V_22 = V_19 -> V_19 ;
} else if ( ! ( V_7 & V_23 ) ) {
V_22 = V_44 ;
}
switch ( V_22 ) {
default:
case V_44 :
F_7 ( & V_10 -> V_45 , V_15 ,
V_46 ) ;
break;
case V_47 :
F_7 ( & V_10 -> V_45 , V_15 ,
V_48 ) ;
break;
case V_49 :
F_7 ( & V_10 -> V_45 , V_15 ,
V_50 ) ;
break;
case - 1 :
F_7 ( & V_10 -> V_45 , V_15 ,
V_51 ) ;
switch ( V_2 -> V_52 . V_53 . V_45 . V_54 ) {
case V_55 :
case V_56 :
V_10 -> V_45 . V_54 =
V_2 -> V_52 . V_53 . V_45 . V_54 ;
break;
default:
break;
}
break;
}
if ( V_21 ) {
V_17 . V_57 = V_15 ;
V_17 . V_58 =
F_5 (
V_21 -> V_59 ,
V_11 ) ;
switch ( V_21 -> V_60 ) {
default:
case V_61 :
V_17 . V_57 = NULL ;
break;
case V_62 :
V_17 . V_54 = V_63 ;
break;
case V_64 :
V_17 . V_54 = V_65 ;
break;
case V_66 :
V_17 . V_67 =
F_5 (
V_21 -> V_68 ,
V_11 ) ;
V_17 . V_54 = V_69 ;
break;
}
if ( V_7 & V_70 &&
V_17 . V_54 == V_69 )
F_8 ( & V_17 ) ;
if ( V_7 & V_71 &&
V_17 . V_54 == V_65 )
F_8 ( & V_17 ) ;
if ( V_7 & V_24 &&
V_17 . V_54 > V_72 )
F_8 ( & V_17 ) ;
}
if ( V_17 . V_57 ) {
if ( ! F_9 ( & V_17 ,
& V_10 -> V_45 ) ) {
F_3 ( V_2 ,
L_3 ,
V_8 ) ;
return - V_28 ;
}
V_10 -> V_45 = V_17 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
const T_2 * V_75 , const T_2 * V_8 ,
T_2 V_76 )
{
struct V_77 * V_39 = V_2 -> V_39 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
V_79 = F_11 ( sizeof( * V_81 ) + V_39 -> V_40 . V_82 +
sizeof( struct V_73 ) ) ;
if ( ! V_79 )
return;
F_12 ( V_79 , V_39 -> V_40 . V_82 ) ;
V_81 = (struct V_80 * ) F_13 ( V_79 , 24 ) ;
memset ( V_81 , 0 , 24 ) ;
memcpy ( V_81 -> V_75 , V_75 , V_83 ) ;
memcpy ( V_81 -> V_84 , V_2 -> V_52 . V_85 , V_83 ) ;
memcpy ( V_81 -> V_8 , V_8 , V_83 ) ;
V_81 -> V_86 = F_14 ( V_87 |
V_88 ) ;
F_13 ( V_79 , 1 + sizeof( V_81 -> V_89 . V_90 . V_89 . V_91 ) ) ;
V_81 -> V_89 . V_90 . V_92 = V_93 ;
V_81 -> V_89 . V_90 . V_89 . V_91 . V_94 =
V_95 ;
V_81 -> V_89 . V_90 . V_89 . V_91 . V_76 = V_76 ;
V_81 -> V_89 . V_90 . V_89 . V_91 . V_96 = V_97 ;
V_81 -> V_89 . V_90 . V_89 . V_91 . V_98 =
sizeof( struct V_73 ) ;
memset ( & V_81 -> V_89 . V_90 . V_89 . V_91 . V_99 , 0 ,
sizeof( struct V_73 ) ) ;
V_81 -> V_89 . V_90 . V_89 . V_91 . V_99 . V_100 = V_74 -> V_100 ;
V_81 -> V_89 . V_90 . V_89 . V_91 . V_99 . V_31 |=
V_101 ;
V_81 -> V_89 . V_90 . V_89 . V_91 . V_99 . type = V_74 -> type ;
F_15 ( V_2 , V_79 ) ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_80 * V_102 ,
T_3 V_103 )
{
F_10 ( V_2 ,
& V_102 -> V_89 . V_90 . V_89 . V_91 . V_99 ,
V_102 -> V_84 , V_102 -> V_8 ,
V_102 -> V_89 . V_90 . V_89 . V_91 . V_76 ) ;
}
