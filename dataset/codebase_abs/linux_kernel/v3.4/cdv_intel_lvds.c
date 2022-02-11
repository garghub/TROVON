static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
if ( F_2 ( V_2 , false ) ) {
V_6 = ( ( F_3 ( V_7 ) &
V_8 ) >>
V_9 ) * 2 ;
F_4 ( V_2 ) ;
} else
V_6 = ( ( V_4 -> V_10 . V_11 &
V_8 ) >>
V_9 ) * 2 ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_13 ;
if ( F_2 ( V_2 , false ) ) {
V_13 =
F_3 ( V_7 ) & ~ V_14 ;
F_6 ( V_7 ,
( V_13 |
( V_12 << V_15 ) ) ) ;
F_4 ( V_2 ) ;
} else {
V_13 = V_4 -> V_10 . V_11 &
~ V_14 ;
V_4 -> V_10 . V_11 = ( V_13 |
( V_12 << V_15 ) ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_16 * V_17 , bool V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_19 ;
if ( ! F_2 ( V_2 , true ) )
return;
if ( V_18 ) {
F_6 ( V_20 , F_3 ( V_20 ) |
V_21 ) ;
do {
V_19 = F_3 ( V_22 ) ;
} while ( ( V_19 & V_23 ) == 0 );
F_5 ( V_2 ,
V_4 -> V_24 . V_25 ) ;
} else {
F_5 ( V_2 , 0 ) ;
F_6 ( V_20 , F_3 ( V_20 ) &
~ V_21 ) ;
do {
V_19 = F_3 ( V_22 ) ;
} while ( V_19 & V_23 );
}
F_4 ( V_2 ) ;
}
static void F_8 ( struct V_16 * V_17 , int V_26 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
if ( V_26 == V_27 )
F_7 ( V_2 , V_17 , true ) ;
else
F_7 ( V_2 , V_17 , false ) ;
}
static void F_9 ( struct V_28 * V_29 )
{
}
static void F_10 ( struct V_28 * V_29 )
{
}
static int F_11 ( struct V_28 * V_29 ,
struct V_30 * V_26 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 =
V_4 -> V_24 . V_32 ;
if ( V_26 -> V_33 & V_34 )
return V_35 ;
if ( V_26 -> V_33 & V_36 )
return V_37 ;
if ( V_31 ) {
if ( V_26 -> V_38 > V_31 -> V_38 )
return V_39 ;
if ( V_26 -> V_40 > V_31 -> V_40 )
return V_39 ;
}
return V_41 ;
}
static bool F_12 ( struct V_16 * V_17 ,
struct V_30 * V_26 ,
struct V_30 * V_42 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_24 = & V_4 -> V_24 ;
struct V_16 * V_44 ;
struct V_30 * V_32 = V_24 -> V_32 ;
F_13 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_44 != V_17
&& V_44 -> V_45 == V_17 -> V_45 ) {
F_14 ( V_46 L_1
L_2 ) ;
return false ;
}
}
if ( V_32 != NULL ) {
V_42 -> V_38 = V_32 -> V_38 ;
V_42 -> V_47 = V_32 -> V_47 ;
V_42 -> V_48 = V_32 -> V_48 ;
V_42 -> V_49 = V_32 -> V_49 ;
V_42 -> V_40 = V_32 -> V_40 ;
V_42 -> V_50 = V_32 -> V_50 ;
V_42 -> V_51 = V_32 -> V_51 ;
V_42 -> V_52 = V_32 -> V_52 ;
V_42 -> clock = V_32 -> clock ;
F_15 ( V_42 ,
V_53 ) ;
}
return true ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_24 = & V_4 -> V_24 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_24 -> V_11 = F_3 ( V_7 ) ;
V_24 -> V_25 = ( V_24 -> V_11 &
V_14 ) ;
F_7 ( V_2 , V_17 , false ) ;
F_4 ( V_2 ) ;
}
static void F_17 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_43 * V_24 = & V_4 -> V_24 ;
if ( V_24 -> V_25 == 0 )
V_24 -> V_25 =
F_1 ( V_2 ) ;
F_7 ( V_2 , V_17 , true ) ;
}
static void F_18 ( struct V_16 * V_17 ,
struct V_30 * V_26 ,
struct V_30 * V_42 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_54 ;
if ( V_26 -> V_38 != V_42 -> V_38 ||
V_26 -> V_40 != V_42 -> V_40 )
V_54 = ( V_55 | V_56 |
V_57 | V_58 |
V_59 ) ;
else
V_54 = 0 ;
if ( V_4 -> V_60 )
V_54 |= V_61 ;
F_6 ( V_62 , V_54 ) ;
}
static enum V_63 F_19 (
struct V_28 * V_29 , bool V_64 )
{
return V_65 ;
}
static int F_20 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_66 * V_66 =
F_21 ( V_29 ) ;
struct V_43 * V_24 = & V_4 -> V_24 ;
int V_67 ;
V_67 = F_22 ( V_29 , & V_66 -> V_68 -> V_69 ) ;
if ( V_67 )
return V_67 ;
V_29 -> V_70 . V_71 = 0 ;
V_29 -> V_70 . V_72 = 200 ;
V_29 -> V_70 . V_73 = 0 ;
V_29 -> V_70 . V_74 = 200 ;
if ( V_24 -> V_32 != NULL ) {
struct V_30 * V_26 =
F_23 ( V_2 , V_24 -> V_32 ) ;
F_24 ( V_29 , V_26 ) ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_66 * V_66 =
F_21 ( V_29 ) ;
if ( V_66 -> V_68 )
F_26 ( V_66 -> V_68 ) ;
F_27 ( V_29 ) ;
F_28 ( V_29 ) ;
F_29 ( V_29 ) ;
}
static int F_30 ( struct V_28 * V_29 ,
struct V_75 * V_76 ,
T_2 V_77 )
{
struct V_16 * V_17 = V_29 -> V_17 ;
if ( ! strcmp ( V_76 -> V_78 , L_3 ) && V_17 ) {
struct V_79 * V_45 =
F_31 ( V_17 -> V_45 ) ;
T_2 V_80 ;
if ( ! V_45 )
return - 1 ;
switch ( V_77 ) {
case V_81 :
break;
case V_82 :
break;
case V_83 :
break;
default:
return - 1 ;
}
if ( F_32 ( V_29 ,
V_76 ,
& V_80 ) )
return - 1 ;
if ( V_80 == V_77 )
return 0 ;
if ( F_33 ( V_29 ,
V_76 ,
V_77 ) )
return - 1 ;
if ( V_45 -> V_84 . V_38 != 0 &&
V_45 -> V_84 . V_40 != 0 ) {
if ( ! F_34 ( V_17 -> V_45 ,
& V_45 -> V_84 ,
V_17 -> V_45 -> V_85 ,
V_17 -> V_45 -> V_86 ,
V_17 -> V_45 -> V_87 ) )
return - 1 ;
}
} else if ( ! strcmp ( V_76 -> V_78 , L_4 ) && V_17 ) {
if ( F_33 ( V_29 ,
V_76 ,
V_77 ) )
return - 1 ;
else {
#ifdef F_35
struct V_3 * V_4 =
V_17 -> V_2 -> V_5 ;
struct V_88 * V_89 =
V_4 -> V_88 ;
V_89 -> V_90 . V_91 = V_77 ;
F_36 ( V_89 ) ;
#endif
}
} else if ( ! strcmp ( V_76 -> V_78 , L_5 ) && V_17 ) {
struct V_92 * V_93 =
V_17 -> V_94 ;
V_93 -> V_95 ( V_17 , V_77 ) ;
}
return 0 ;
}
static void F_37 ( struct V_16 * V_17 )
{
F_38 ( V_17 ) ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_43 * V_24 )
{
struct V_66 * V_66 ;
struct V_96 * V_96 ;
struct V_97 * V_98 ;
struct V_28 * V_29 ;
struct V_16 * V_17 ;
struct V_30 * V_99 ;
struct V_100 * V_45 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_101 ;
int V_102 ;
V_66 = F_40 ( sizeof( struct V_66 ) ,
V_103 ) ;
if ( ! V_66 )
return;
V_96 = F_40 ( sizeof( struct V_96 ) ,
V_103 ) ;
if ( ! V_96 )
goto V_104;
V_98 = F_40 ( sizeof( struct V_97 ) , V_103 ) ;
if ( ! V_98 )
goto V_105;
V_66 -> V_4 = V_98 ;
V_29 = & V_96 -> V_106 ;
V_17 = & V_66 -> V_106 ;
F_41 ( V_2 , V_29 ,
& V_107 ,
V_108 ) ;
F_42 ( V_2 , V_17 ,
& V_109 ,
V_110 ) ;
F_43 ( V_96 ,
V_66 ) ;
V_66 -> type = V_111 ;
F_44 ( V_17 , & V_112 ) ;
F_45 ( V_29 ,
& V_113 ) ;
V_29 -> V_70 . V_114 = V_115 ;
V_29 -> V_116 = false ;
V_29 -> V_117 = false ;
F_46 ( V_29 ,
V_2 -> V_118 . V_119 ,
V_81 ) ;
F_46 ( V_29 ,
V_4 -> V_120 ,
V_121 ) ;
V_66 -> V_68 = F_47 ( V_2 ,
V_122 ,
L_6 ) ;
if ( ! V_66 -> V_68 ) {
F_48 ( V_46 ,
& V_2 -> V_123 -> V_2 , L_7 ) ;
goto V_124;
}
V_66 -> V_68 -> V_125 = 0x2C ;
V_4 -> V_126 = V_66 -> V_68 ;
V_66 -> V_127 = F_47 ( V_2 ,
V_128 ,
L_8 ) ;
if ( ! V_66 -> V_127 ) {
F_48 ( V_46 , & V_2 -> V_123 -> V_2 ,
L_9 L_10 ) ;
goto V_129;
}
F_22 ( V_29 ,
& V_66 -> V_127 -> V_69 ) ;
F_13 (scan, &connector->probed_modes, head) {
if ( V_99 -> type & V_130 ) {
V_24 -> V_32 =
F_23 ( V_2 , V_99 ) ;
goto V_131;
}
}
if ( V_4 -> V_132 ) {
V_24 -> V_32 =
F_23 ( V_2 , V_4 -> V_132 ) ;
if ( V_24 -> V_32 ) {
V_24 -> V_32 -> type |=
V_130 ;
goto V_131;
}
}
V_101 = F_3 ( V_133 ) ;
V_102 = ( V_101 & V_134 ) ? 1 : 0 ;
V_45 = F_49 ( V_2 , V_102 ) ;
if ( V_45 && ( V_101 & V_135 ) ) {
V_24 -> V_32 =
F_50 ( V_2 , V_45 ) ;
if ( V_24 -> V_32 ) {
V_24 -> V_32 -> type |=
V_130 ;
goto V_131;
}
}
if ( ! V_24 -> V_32 ) {
F_51
( L_11 ) ;
goto V_136;
}
V_131:
F_52 ( V_29 ) ;
return;
V_136:
F_14 ( V_46 L_12 ) ;
if ( V_66 -> V_127 )
F_26 ( V_66 -> V_127 ) ;
V_129:
F_14 ( V_46 L_13 ) ;
if ( V_66 -> V_68 )
F_26 ( V_66 -> V_68 ) ;
V_124:
F_14 ( V_46 L_14 ) ;
F_38 ( V_17 ) ;
F_28 ( V_29 ) ;
F_29 ( V_98 ) ;
V_105:
F_29 ( V_96 ) ;
V_104:
F_29 ( V_66 ) ;
}
