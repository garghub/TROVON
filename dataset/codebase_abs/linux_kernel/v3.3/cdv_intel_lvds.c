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
V_6 = ( ( V_4 -> V_10 &
V_8 ) >>
V_9 ) * 2 ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 = V_4 -> V_13 ;
T_2 V_14 [ 2 ] ;
unsigned int V_15 ;
struct V_16 V_17 [] = {
{
. V_18 = V_13 -> V_19 ,
. V_20 = 0 ,
. V_21 = 2 ,
. V_22 = V_14 ,
}
} ;
V_15 = V_23 & ( ( unsigned int ) V_11 *
V_23 /
V_24 ) ;
if ( V_4 -> V_25 -> V_26 == V_27 )
V_15 = V_23 - V_15 ;
V_14 [ 0 ] = V_4 -> V_25 -> V_28 ;
V_14 [ 1 ] = ( T_2 ) V_15 ;
if ( F_6 ( & V_13 -> V_29 , V_17 , 1 ) == 1 )
return 0 ;
F_7 ( L_1 ) ;
return - 1 ;
}
static int F_8 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_30 ;
T_1 V_31 ;
V_30 = F_1 ( V_2 ) ;
F_9 ( ( V_30 & V_32 ) == 0 ) ;
V_31 = V_11 * V_30 / V_24 ;
if ( V_4 -> V_25 -> V_26 == V_27 )
V_31 = V_30 - V_31 ;
V_31 &= V_33 ;
F_10 ( V_7 ,
( V_30 << V_34 ) |
( V_31 ) ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_25 ) {
F_7 ( L_2 ) ;
return;
}
if ( V_4 -> V_25 -> type == V_35 )
F_5 ( V_2 , V_11 ) ;
else
F_8 ( V_2 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_36 ;
if ( F_2 ( V_2 , false ) ) {
V_36 =
F_3 ( V_7 ) & ~ V_37 ;
F_10 ( V_7 ,
( V_36 |
( V_11 << V_38 ) ) ) ;
F_4 ( V_2 ) ;
} else {
V_36 = V_4 -> V_10 &
~ V_37 ;
V_4 -> V_10 = ( V_36 |
( V_11 << V_38 ) ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_39 * V_40 , bool V_41 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 ;
if ( ! F_2 ( V_2 , true ) )
return;
if ( V_41 ) {
F_10 ( V_43 , F_3 ( V_43 ) |
V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( ( V_42 & V_46 ) == 0 );
F_12 ( V_2 ,
V_4 -> V_47 . V_48 ) ;
} else {
F_12 ( V_2 , 0 ) ;
F_10 ( V_43 , F_3 ( V_43 ) &
~ V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( V_42 & V_46 );
}
F_4 ( V_2 ) ;
}
static void F_14 ( struct V_39 * V_40 , int V_49 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
if ( V_49 == V_50 )
F_13 ( V_2 , V_40 , true ) ;
else
F_13 ( V_2 , V_40 , false ) ;
}
static void F_15 ( struct V_51 * V_52 )
{
}
static void F_16 ( struct V_51 * V_52 )
{
}
int F_17 ( struct V_51 * V_52 ,
struct V_53 * V_49 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_53 * V_54 =
V_4 -> V_47 . V_55 ;
if ( V_49 -> V_20 & V_56 )
return V_57 ;
if ( V_49 -> V_20 & V_58 )
return V_59 ;
if ( V_54 ) {
if ( V_49 -> V_60 > V_54 -> V_60 )
return V_61 ;
if ( V_49 -> V_62 > V_54 -> V_62 )
return V_61 ;
}
return V_63 ;
}
bool F_18 ( struct V_39 * V_40 ,
struct V_53 * V_49 ,
struct V_53 * V_64 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * V_47 = & V_4 -> V_47 ;
struct V_39 * V_66 ;
struct V_53 * V_55 = V_47 -> V_55 ;
F_19 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_66 != V_40
&& V_66 -> V_67 == V_40 -> V_67 ) {
F_20 ( V_68 L_3
L_4 ) ;
return false ;
}
}
if ( V_55 != NULL ) {
V_64 -> V_60 = V_55 -> V_60 ;
V_64 -> V_69 = V_55 -> V_69 ;
V_64 -> V_70 = V_55 -> V_70 ;
V_64 -> V_71 = V_55 -> V_71 ;
V_64 -> V_62 = V_55 -> V_62 ;
V_64 -> V_72 = V_55 -> V_72 ;
V_64 -> V_73 = V_55 -> V_73 ;
V_64 -> V_74 = V_55 -> V_74 ;
V_64 -> clock = V_55 -> clock ;
F_21 ( V_64 ,
V_75 ) ;
}
return true ;
}
static void F_22 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * V_47 = & V_4 -> V_47 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_47 -> V_10 = F_3 ( V_7 ) ;
V_47 -> V_48 = ( V_47 -> V_10 &
V_37 ) ;
F_13 ( V_2 , V_40 , false ) ;
F_4 ( V_2 ) ;
}
static void F_23 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * V_47 = & V_4 -> V_47 ;
if ( V_47 -> V_48 == 0 )
V_47 -> V_48 =
F_1 ( V_2 ) ;
F_13 ( V_2 , V_40 , true ) ;
}
static void F_24 ( struct V_39 * V_40 ,
struct V_53 * V_49 ,
struct V_53 * V_64 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_76 ;
if ( V_49 -> V_60 != V_64 -> V_60 ||
V_49 -> V_62 != V_64 -> V_62 )
V_76 = ( V_77 | V_78 |
V_79 | V_80 |
V_81 ) ;
else
V_76 = 0 ;
if ( V_4 -> V_82 )
V_76 |= V_83 ;
F_10 ( V_84 , V_76 ) ;
}
static enum V_85 F_25 (
struct V_51 * V_52 , bool V_86 )
{
return V_87 ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_88 * V_88 =
F_27 ( V_52 ) ;
struct V_65 * V_47 = & V_4 -> V_47 ;
int V_89 ;
V_89 = F_28 ( V_52 , & V_88 -> V_90 -> V_29 ) ;
if ( V_89 )
return V_89 ;
V_52 -> V_91 . V_92 = 0 ;
V_52 -> V_91 . V_93 = 200 ;
V_52 -> V_91 . V_94 = 0 ;
V_52 -> V_91 . V_95 = 200 ;
if ( V_47 -> V_55 != NULL ) {
struct V_53 * V_49 =
F_29 ( V_2 , V_47 -> V_55 ) ;
F_30 ( V_52 , V_49 ) ;
return 1 ;
}
return 0 ;
}
void F_31 ( struct V_51 * V_52 )
{
struct V_88 * V_88 =
F_27 ( V_52 ) ;
if ( V_88 -> V_90 )
F_32 ( V_88 -> V_90 ) ;
F_33 ( V_52 ) ;
F_34 ( V_52 ) ;
F_35 ( V_52 ) ;
}
int F_36 ( struct V_51 * V_52 ,
struct V_96 * V_97 ,
T_3 V_98 )
{
struct V_39 * V_40 = V_52 -> V_40 ;
if ( ! strcmp ( V_97 -> V_99 , L_5 ) && V_40 ) {
struct V_100 * V_67 =
F_37 ( V_40 -> V_67 ) ;
T_3 V_101 ;
if ( ! V_67 )
return - 1 ;
switch ( V_98 ) {
case V_102 :
break;
case V_103 :
break;
case V_104 :
break;
default:
return - 1 ;
}
if ( F_38 ( V_52 ,
V_97 ,
& V_101 ) )
return - 1 ;
if ( V_101 == V_98 )
return 0 ;
if ( F_39 ( V_52 ,
V_97 ,
V_98 ) )
return - 1 ;
if ( V_67 -> V_105 . V_60 != 0 &&
V_67 -> V_105 . V_62 != 0 ) {
if ( ! F_40 ( V_40 -> V_67 ,
& V_67 -> V_105 ,
V_40 -> V_67 -> V_106 ,
V_40 -> V_67 -> V_107 ,
V_40 -> V_67 -> V_108 ) )
return - 1 ;
}
} else if ( ! strcmp ( V_97 -> V_99 , L_6 ) && V_40 ) {
if ( F_39 ( V_52 ,
V_97 ,
V_98 ) )
return - 1 ;
else {
#ifdef F_41
struct V_3 * V_4 =
V_40 -> V_2 -> V_5 ;
struct V_109 * V_110 =
V_4 -> V_109 ;
V_110 -> V_111 . V_112 = V_98 ;
F_42 ( V_110 ) ;
#endif
}
} else if ( ! strcmp ( V_97 -> V_99 , L_7 ) && V_40 ) {
struct V_113 * V_114 =
V_40 -> V_115 ;
V_114 -> V_116 ( V_40 , V_98 ) ;
}
return 0 ;
}
static void F_43 ( struct V_39 * V_40 )
{
F_44 ( V_40 ) ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_65 * V_47 )
{
struct V_88 * V_88 ;
struct V_117 * V_117 ;
struct V_118 * V_119 ;
struct V_51 * V_52 ;
struct V_39 * V_40 ;
struct V_53 * V_120 ;
struct V_121 * V_67 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_122 ;
int V_123 ;
V_88 = F_46 ( sizeof( struct V_88 ) ,
V_124 ) ;
if ( ! V_88 )
return;
V_117 = F_46 ( sizeof( struct V_117 ) ,
V_124 ) ;
if ( ! V_117 )
goto V_125;
V_119 = F_46 ( sizeof( struct V_118 ) , V_124 ) ;
if ( ! V_119 )
goto V_126;
V_88 -> V_4 = V_119 ;
V_52 = & V_117 -> V_127 ;
V_40 = & V_88 -> V_127 ;
F_47 ( V_2 , V_52 ,
& V_128 ,
V_129 ) ;
F_48 ( V_2 , V_40 ,
& V_130 ,
V_131 ) ;
F_49 ( V_117 ,
V_88 ) ;
V_88 -> type = V_132 ;
F_50 ( V_40 , & V_133 ) ;
F_51 ( V_52 ,
& V_134 ) ;
V_52 -> V_91 . V_135 = V_136 ;
V_52 -> V_137 = false ;
V_52 -> V_138 = false ;
F_52 ( V_52 ,
V_2 -> V_139 . V_140 ,
V_102 ) ;
F_52 ( V_52 ,
V_4 -> V_141 ,
V_24 ) ;
V_88 -> V_90 = F_53 ( V_2 ,
V_142 ,
L_8 ) ;
if ( ! V_88 -> V_90 ) {
F_54 ( V_68 ,
& V_2 -> V_143 -> V_2 , L_9 ) ;
goto V_144;
}
V_88 -> V_90 -> V_19 = 0x2C ;
V_4 -> V_13 = V_88 -> V_90 ;
V_88 -> V_145 = F_53 ( V_2 ,
V_146 ,
L_10 ) ;
if ( ! V_88 -> V_145 ) {
F_54 ( V_68 , & V_2 -> V_143 -> V_2 ,
L_11 L_12 ) ;
goto V_147;
}
F_28 ( V_52 ,
& V_88 -> V_145 -> V_29 ) ;
F_19 (scan, &connector->probed_modes, head) {
if ( V_120 -> type & V_148 ) {
V_47 -> V_55 =
F_29 ( V_2 , V_120 ) ;
goto V_149;
}
}
if ( V_4 -> V_150 ) {
V_47 -> V_55 =
F_29 ( V_2 , V_4 -> V_150 ) ;
if ( V_47 -> V_55 ) {
V_47 -> V_55 -> type |=
V_148 ;
goto V_149;
}
}
V_122 = F_3 ( V_151 ) ;
V_123 = ( V_122 & V_152 ) ? 1 : 0 ;
V_67 = F_55 ( V_2 , V_123 ) ;
if ( V_67 && ( V_122 & V_153 ) ) {
V_47 -> V_55 =
F_56 ( V_2 , V_67 ) ;
if ( V_47 -> V_55 ) {
V_47 -> V_55 -> type |=
V_148 ;
goto V_149;
}
}
if ( ! V_47 -> V_55 ) {
F_57
( L_13 ) ;
goto V_154;
}
V_149:
F_58 ( V_52 ) ;
return;
V_154:
F_20 ( V_68 L_14 ) ;
if ( V_88 -> V_145 )
F_32 ( V_88 -> V_145 ) ;
V_147:
F_20 ( V_68 L_15 ) ;
if ( V_88 -> V_90 )
F_32 ( V_88 -> V_90 ) ;
V_144:
F_20 ( V_68 L_16 ) ;
F_44 ( V_40 ) ;
F_34 ( V_52 ) ;
F_35 ( V_119 ) ;
V_126:
F_35 ( V_117 ) ;
V_125:
F_35 ( V_88 ) ;
}
