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
const struct V_22 * V_23 ;
int V_24 = - 1 ;
V_19 = V_4 -> V_19 ;
V_21 = V_4 -> V_21 ;
V_23 = V_4 -> V_25 ;
if ( V_7 & ( V_26 |
V_27 ) ) {
V_19 = NULL ;
V_21 = NULL ;
V_23 = NULL ;
}
if ( V_7 & V_28 )
V_21 = NULL ;
if ( V_4 -> V_29 ) {
if ( ! F_2 (
V_4 -> V_29 -> V_30 ,
& V_11 ) ) {
F_3 ( V_2 ,
L_1 ,
V_4 -> V_29 -> V_30 ) ;
return - V_31 ;
}
V_13 = V_4 -> V_29 -> V_32 ;
V_10 -> V_33 = V_4 -> V_29 -> V_33 ;
V_10 -> V_34 = V_4 -> V_29 -> V_34 ;
} else if ( V_4 -> V_35 ) {
V_11 = V_6 ;
V_13 = V_4 -> V_35 -> V_32 ;
V_10 -> V_33 = V_4 -> V_35 -> V_33 ;
V_10 -> V_34 = V_4 -> V_35 -> V_34 ;
} else {
return 1 ;
}
if ( V_4 -> V_36 ) {
V_10 -> V_37 = V_4 -> V_36 -> V_38 ;
V_10 -> V_34 = V_4 -> V_36 -> V_39 ;
V_10 -> V_40 = F_4 (
V_4 -> V_36 -> V_41 ) ;
}
V_12 = F_5 ( V_13 , V_11 ) ;
V_15 = F_6 ( V_2 -> V_42 -> V_43 . V_44 , V_12 ) ;
if ( ! V_15 || V_15 -> V_45 & V_46 ) {
F_3 ( V_2 ,
L_2 ,
V_8 , V_12 ) ;
return - V_31 ;
}
if ( V_19 ) {
V_24 = V_19 -> V_19 ;
} else if ( ! ( V_7 & V_26 ) ) {
V_24 = V_47 ;
}
switch ( V_24 ) {
default:
case V_47 :
F_7 ( & V_10 -> V_48 , V_15 ,
V_49 ) ;
break;
case V_50 :
F_7 ( & V_10 -> V_48 , V_15 ,
V_51 ) ;
break;
case V_52 :
F_7 ( & V_10 -> V_48 , V_15 ,
V_53 ) ;
break;
case - 1 :
F_7 ( & V_10 -> V_48 , V_15 ,
V_54 ) ;
switch ( V_2 -> V_55 . V_56 . V_48 . V_57 ) {
case V_58 :
case V_59 :
V_10 -> V_48 . V_57 =
V_2 -> V_55 . V_56 . V_48 . V_57 ;
break;
default:
break;
}
break;
}
if ( V_21 ) {
V_17 . V_60 = V_15 ;
V_17 . V_61 =
F_5 (
V_21 -> V_62 ,
V_11 ) ;
switch ( V_21 -> V_63 ) {
default:
case V_64 :
V_17 . V_60 = NULL ;
break;
case V_65 :
V_17 . V_57 = V_66 ;
break;
case V_67 :
V_17 . V_57 = V_68 ;
break;
case V_69 :
V_17 . V_70 =
F_5 (
V_21 -> V_71 ,
V_11 ) ;
V_17 . V_57 = V_72 ;
break;
}
if ( V_7 & V_73 &&
V_17 . V_57 == V_72 )
F_8 ( & V_17 ) ;
if ( V_7 & V_74 &&
V_17 . V_57 == V_68 )
F_8 ( & V_17 ) ;
if ( V_7 & V_27 &&
V_17 . V_57 > V_75 )
F_8 ( & V_17 ) ;
}
if ( V_17 . V_60 ) {
if ( ! F_9 ( & V_17 ,
& V_10 -> V_48 ) ) {
F_3 ( V_2 ,
L_3 ,
V_8 ) ;
return - V_31 ;
}
V_10 -> V_48 = V_17 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
const T_2 * V_78 , const T_2 * V_8 ,
T_2 V_79 )
{
struct V_80 * V_42 = V_2 -> V_42 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
V_82 = F_11 ( sizeof( * V_84 ) + V_42 -> V_43 . V_85 +
sizeof( struct V_76 ) ) ;
if ( ! V_82 )
return;
F_12 ( V_82 , V_42 -> V_43 . V_85 ) ;
V_84 = (struct V_83 * ) F_13 ( V_82 , 24 ) ;
memset ( V_84 , 0 , 24 ) ;
memcpy ( V_84 -> V_78 , V_78 , V_86 ) ;
memcpy ( V_84 -> V_87 , V_2 -> V_55 . V_88 , V_86 ) ;
memcpy ( V_84 -> V_8 , V_8 , V_86 ) ;
V_84 -> V_89 = F_14 ( V_90 |
V_91 ) ;
F_13 ( V_82 , 1 + sizeof( V_84 -> V_92 . V_93 . V_92 . V_94 ) ) ;
V_84 -> V_92 . V_93 . V_95 = V_96 ;
V_84 -> V_92 . V_93 . V_92 . V_94 . V_97 =
V_98 ;
V_84 -> V_92 . V_93 . V_92 . V_94 . V_79 = V_79 ;
V_84 -> V_92 . V_93 . V_92 . V_94 . V_99 = V_100 ;
V_84 -> V_92 . V_93 . V_92 . V_94 . V_101 =
sizeof( struct V_76 ) ;
memset ( & V_84 -> V_92 . V_93 . V_92 . V_94 . V_102 , 0 ,
sizeof( struct V_76 ) ) ;
V_84 -> V_92 . V_93 . V_92 . V_94 . V_102 . V_103 = V_77 -> V_103 ;
V_84 -> V_92 . V_93 . V_92 . V_94 . V_102 . V_34 |=
V_104 ;
V_84 -> V_92 . V_93 . V_92 . V_94 . V_102 . type = V_77 -> type ;
F_15 ( V_2 , V_82 ) ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_83 * V_105 ,
T_3 V_106 )
{
F_10 ( V_2 ,
& V_105 -> V_92 . V_93 . V_92 . V_94 . V_102 ,
V_105 -> V_87 , V_105 -> V_8 ,
V_105 -> V_92 . V_93 . V_92 . V_94 . V_79 ) ;
}
