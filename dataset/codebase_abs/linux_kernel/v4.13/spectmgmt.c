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
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
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
if ( V_4 -> V_33 -> V_36 &
V_39 )
V_10 -> V_40 = F_4 (
V_4 -> V_33 -> V_41 ) ;
}
V_12 = F_5 ( V_13 , V_11 ) ;
V_15 = F_6 ( V_2 -> V_42 -> V_43 . V_44 , V_12 ) ;
if ( ! V_15 || V_15 -> V_45 & V_46 ) {
F_3 ( V_2 ,
L_2 ,
V_8 , V_12 ) ;
return - V_28 ;
}
if ( V_19 ) {
V_22 = V_19 -> V_19 ;
} else if ( ! ( V_7 & V_23 ) ) {
V_22 = V_47 ;
}
switch ( V_22 ) {
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
struct V_60 V_61 = {
. V_62 =
V_21 -> V_63 ,
. V_64 =
V_21 -> V_65 ,
. V_66 =
V_21 -> V_67 ,
} ;
V_17 = V_10 -> V_48 ;
if ( ! F_8 ( & V_61 , & V_17 ) )
V_17 . V_68 = NULL ;
if ( V_7 & V_69 &&
V_17 . V_57 == V_70 )
F_9 ( & V_17 ) ;
if ( V_7 & V_71 &&
V_17 . V_57 == V_72 )
F_9 ( & V_17 ) ;
}
if ( V_17 . V_68 ) {
if ( ! F_10 ( & V_17 ,
& V_10 -> V_48 ) ) {
F_3 ( V_2 ,
L_3 ,
V_8 ) ;
return - V_28 ;
}
V_10 -> V_48 = V_17 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
const T_2 * V_75 , const T_2 * V_8 ,
T_2 V_76 )
{
struct V_77 * V_42 = V_2 -> V_42 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
V_79 = F_12 ( sizeof( * V_81 ) + V_42 -> V_43 . V_82 +
sizeof( struct V_73 ) ) ;
if ( ! V_79 )
return;
F_13 ( V_79 , V_42 -> V_43 . V_82 ) ;
V_81 = F_14 ( V_79 , 24 ) ;
memcpy ( V_81 -> V_75 , V_75 , V_83 ) ;
memcpy ( V_81 -> V_84 , V_2 -> V_55 . V_85 , V_83 ) ;
memcpy ( V_81 -> V_8 , V_8 , V_83 ) ;
V_81 -> V_86 = F_15 ( V_87 |
V_88 ) ;
F_16 ( V_79 , 1 + sizeof( V_81 -> V_89 . V_90 . V_89 . V_91 ) ) ;
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
F_17 ( V_2 , V_79 ) ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_80 * V_102 ,
T_3 V_103 )
{
F_11 ( V_2 ,
& V_102 -> V_89 . V_90 . V_89 . V_91 . V_99 ,
V_102 -> V_84 , V_102 -> V_8 ,
V_102 -> V_89 . V_90 . V_89 . V_91 . V_76 ) ;
}
