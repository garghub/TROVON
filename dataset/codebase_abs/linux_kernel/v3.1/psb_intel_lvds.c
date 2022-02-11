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
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
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
if ( F_6 ( & V_13 -> V_29 , V_17 , 1 ) == 1 ) {
F_7 ( V_2 -> V_2 , L_1 ,
V_4 -> V_25 -> V_28 ,
V_15 ) ;
return 0 ;
}
F_8 ( V_2 -> V_2 , L_2 ) ;
return - 1 ;
}
static int F_9 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
T_1 V_30 ;
T_1 V_31 ;
V_30 = F_1 ( V_2 ) ;
F_10 ( ( V_30 & V_32 ) == 0 ) ;
V_31 = V_11 * V_30 / V_24 ;
if ( V_4 -> V_25 -> V_26 == V_27 )
V_31 = V_30 - V_31 ;
V_31 &= V_33 ;
F_11 ( V_7 ,
( V_30 << V_34 ) |
( V_31 ) ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
F_7 ( V_2 -> V_2 , L_3 , V_11 ) ;
if ( ! V_4 -> V_25 ) {
F_8 ( V_2 -> V_2 , L_4 ) ;
return;
}
if ( V_4 -> V_25 -> type == V_35 )
F_5 ( V_2 , V_11 ) ;
else
F_9 ( V_2 , V_11 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_36 ;
if ( F_2 ( V_2 , false ) ) {
V_36 =
F_3 ( V_7 ) & ~ V_37 ;
F_11 ( V_7 ,
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
static void F_14 ( struct V_1 * V_2 ,
struct V_39 * V_40 , bool V_41 )
{
T_1 V_42 ;
if ( ! F_2 ( V_2 , true ) )
return;
if ( V_41 ) {
F_11 ( V_43 , F_3 ( V_43 ) |
V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( ( V_42 & V_46 ) == 0 );
F_13 ( V_2 ,
V_40 ->
V_47 -> V_48 ) ;
} else {
F_13 ( V_2 , 0 ) ;
F_11 ( V_43 , F_3 ( V_43 ) &
~ V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( V_42 & V_46 );
}
F_4 ( V_2 ) ;
}
static void F_15 ( struct V_49 * V_50 , int V_51 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_16 ( V_50 ) ;
if ( V_51 == V_52 )
F_14 ( V_2 , V_40 , true ) ;
else
F_14 ( V_2 , V_40 , false ) ;
}
static void F_17 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
struct V_39 * V_39 =
F_18 ( V_54 ) ;
struct V_55 * V_56 =
(struct V_55 * ) V_39 -> V_4 ;
V_56 -> V_57 = F_3 ( V_58 ) ;
V_56 -> V_59 = F_3 ( V_60 ) ;
V_56 -> V_61 = F_3 ( V_62 ) ;
V_56 -> V_63 = F_3 ( V_43 ) ;
V_56 -> V_64 = F_3 ( V_65 ) ;
V_56 -> V_10 = F_3 ( V_7 ) ;
V_56 -> V_66 = F_3 ( V_67 ) ;
V_56 -> V_68 = F_3 ( V_69 ) ;
V_4 -> V_48 = ( V_4 -> V_10 &
V_37 ) ;
if ( V_4 -> V_48 == 0 )
V_4 -> V_48 =
F_1 ( V_2 ) ;
F_7 ( V_2 -> V_2 , L_5 ,
V_56 -> V_57 ,
V_56 -> V_59 ,
V_56 -> V_61 ,
V_56 -> V_63 ,
V_56 -> V_64 ,
V_56 -> V_10 ) ;
}
static void F_19 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
T_1 V_42 ;
struct V_39 * V_39 =
F_18 ( V_54 ) ;
struct V_55 * V_56 =
(struct V_55 * ) V_39 -> V_4 ;
F_7 ( V_2 -> V_2 , L_5 ,
V_56 -> V_57 ,
V_56 -> V_59 ,
V_56 -> V_61 ,
V_56 -> V_63 ,
V_56 -> V_64 ,
V_56 -> V_10 ) ;
F_11 ( V_7 , V_56 -> V_10 ) ;
F_11 ( V_67 , V_56 -> V_66 ) ;
F_11 ( V_69 , V_56 -> V_68 ) ;
F_11 ( V_58 , V_56 -> V_57 ) ;
F_11 ( V_60 , V_56 -> V_59 ) ;
F_11 ( V_65 , V_56 -> V_64 ) ;
F_11 ( V_43 , V_56 -> V_63 ) ;
F_11 ( V_62 , V_56 -> V_61 ) ;
if ( V_56 -> V_63 & V_44 ) {
F_11 ( V_43 , F_3 ( V_43 ) |
V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( ( V_42 & V_46 ) == 0 );
} else {
F_11 ( V_43 , F_3 ( V_43 ) &
~ V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( V_42 & V_46 );
}
}
int F_20 ( struct V_53 * V_54 ,
struct V_70 * V_51 )
{
struct V_39 * V_39 =
F_18 ( V_54 ) ;
struct V_70 * V_71 =
V_39 -> V_47 -> V_72 ;
if ( V_39 -> type == V_73 )
V_71 = V_39 -> V_47 -> V_74 ;
if ( V_51 -> V_20 & V_75 )
return V_76 ;
if ( V_51 -> V_20 & V_77 )
return V_78 ;
if ( V_71 ) {
if ( V_51 -> V_79 > V_71 -> V_79 )
return V_80 ;
if ( V_51 -> V_81 > V_71 -> V_81 )
return V_80 ;
}
return V_82 ;
}
bool F_21 ( struct V_49 * V_50 ,
struct V_70 * V_51 ,
struct V_70 * V_83 )
{
struct V_84 * V_47 =
F_16 ( V_50 ) -> V_47 ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_85 * V_85 =
F_22 ( V_50 -> V_86 ) ;
struct V_49 * V_87 ;
struct V_70 * V_72 = V_47 -> V_72 ;
struct V_39 * V_39 =
F_16 ( V_50 ) ;
if ( V_39 -> type == V_73 )
V_72 = V_47 -> V_74 ;
if ( ! F_23 ( V_2 ) && V_85 -> V_88 == 0 ) {
F_24 ( V_89 L_6 ) ;
return false ;
}
if ( F_23 ( V_2 ) && V_85 -> V_88 != 0 ) {
F_24 ( V_89 L_7 ) ;
return false ;
}
F_25 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_87 != V_50
&& V_87 -> V_86 == V_50 -> V_86 ) {
F_24 ( V_89 L_8
L_9 ) ;
return false ;
}
}
if ( V_72 != NULL ) {
V_83 -> V_79 = V_72 -> V_79 ;
V_83 -> V_90 = V_72 -> V_90 ;
V_83 -> V_91 = V_72 -> V_91 ;
V_83 -> V_92 = V_72 -> V_92 ;
V_83 -> V_81 = V_72 -> V_81 ;
V_83 -> V_93 = V_72 -> V_93 ;
V_83 -> V_94 = V_72 -> V_94 ;
V_83 -> V_95 = V_72 -> V_95 ;
V_83 -> clock = V_72 -> clock ;
F_26 ( V_83 ,
V_96 ) ;
}
return true ;
}
static void F_27 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_16 ( V_50 ) ;
struct V_84 * V_47 = V_40 -> V_47 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_47 -> V_10 = F_3 ( V_7 ) ;
V_47 -> V_48 = ( V_47 -> V_10 &
V_37 ) ;
F_14 ( V_2 , V_40 , false ) ;
F_4 ( V_2 ) ;
}
static void F_28 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_16 ( V_50 ) ;
struct V_84 * V_47 = V_40 -> V_47 ;
if ( V_47 -> V_48 == 0 )
V_47 -> V_48 =
F_1 ( V_2 ) ;
F_14 ( V_2 , V_40 , true ) ;
}
static void F_29 ( struct V_49 * V_50 ,
struct V_70 * V_51 ,
struct V_70 * V_83 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_97 ;
if ( V_51 -> V_79 != V_83 -> V_79 ||
V_51 -> V_81 != V_83 -> V_81 )
V_97 = ( V_98 | V_99 |
V_100 | V_101 |
V_102 ) ;
else
V_97 = 0 ;
if ( V_4 -> V_103 )
V_97 |= V_104 ;
F_11 ( V_67 , V_97 ) ;
}
static enum V_105 F_30 ( struct V_53
* V_54 , bool V_106 )
{
return V_107 ;
}
static int F_31 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_39 * V_39 =
F_18 ( V_54 ) ;
struct V_84 * V_47 =
V_39 -> V_47 ;
int V_108 = 0 ;
if ( ! F_23 ( V_2 ) )
V_108 = F_32 ( V_39 ) ;
if ( V_108 )
return V_108 ;
V_54 -> V_109 . V_110 = 0 ;
V_54 -> V_109 . V_111 = 200 ;
V_54 -> V_109 . V_112 = 0 ;
V_54 -> V_109 . V_113 = 200 ;
if ( V_47 -> V_72 != NULL ) {
struct V_70 * V_51 =
F_33 ( V_2 , V_47 -> V_72 ) ;
F_34 ( V_54 , V_51 ) ;
return 1 ;
}
return 0 ;
}
void F_35 ( struct V_53 * V_54 )
{
struct V_39 * V_39 =
F_18 ( V_54 ) ;
if ( V_39 -> V_114 )
F_36 ( V_39 -> V_114 ) ;
F_37 ( V_54 ) ;
F_38 ( V_54 ) ;
F_39 ( V_54 ) ;
}
int F_40 ( struct V_53 * V_54 ,
struct V_115 * V_116 ,
T_3 V_117 )
{
struct V_49 * V_50 = V_54 -> V_50 ;
if ( ! V_50 )
return - 1 ;
if ( ! strcmp ( V_116 -> V_118 , L_10 ) ) {
struct V_85 * V_86 =
F_22 ( V_50 -> V_86 ) ;
T_3 V_119 ;
if ( ! V_86 )
goto V_120;
switch ( V_117 ) {
case V_121 :
break;
case V_122 :
break;
case V_123 :
break;
default:
goto V_120;
}
if ( F_41 ( V_54 ,
V_116 ,
& V_119 ) )
goto V_120;
if ( V_119 == V_117 )
goto V_124;
if ( F_42 ( V_54 ,
V_116 ,
V_117 ) )
goto V_120;
if ( V_86 -> V_125 . V_79 != 0 &&
V_86 -> V_125 . V_81 != 0 ) {
if ( ! F_43 ( V_50 -> V_86 ,
& V_86 -> V_125 ,
V_50 -> V_86 -> V_126 ,
V_50 -> V_86 -> V_127 ,
V_50 -> V_86 -> V_128 ) )
goto V_120;
}
} else if ( ! strcmp ( V_116 -> V_118 , L_11 ) ) {
if ( F_42 ( V_54 ,
V_116 ,
V_117 ) )
goto V_120;
else {
#ifdef F_44
struct V_3 * V_129 = V_50 -> V_2 -> V_5 ;
struct V_130 * V_131 = V_129 -> V_130 ;
if ( V_131 ) {
V_131 -> V_132 . V_133 = V_117 ;
F_45 ( V_131 ) ;
}
#endif
}
} else if ( ! strcmp ( V_116 -> V_118 , L_12 ) ) {
struct V_134 * V_135
= V_50 -> V_136 ;
V_135 -> V_137 ( V_50 , V_117 ) ;
}
V_124:
return 0 ;
V_120:
return - 1 ;
}
static void F_46 ( struct V_49 * V_50 )
{
F_47 ( V_50 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_84 * V_47 )
{
struct V_39 * V_39 ;
struct V_55 * V_56 ;
struct V_53 * V_54 ;
struct V_49 * V_50 ;
struct V_70 * V_138 ;
struct V_139 * V_86 ;
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
T_1 V_140 ;
int V_88 ;
V_39 = F_49 ( sizeof( struct V_39 ) , V_141 ) ;
if ( ! V_39 )
return;
V_56 = F_49 ( sizeof( struct V_55 ) , V_141 ) ;
if ( ! V_56 ) {
F_39 ( V_39 ) ;
F_8 ( V_2 -> V_2 , L_13 ) ;
return;
}
V_39 -> V_4 = V_56 ;
V_39 -> V_47 = V_47 ;
V_54 = & V_39 -> V_142 ;
V_50 = & V_39 -> V_143 ;
F_50 ( V_2 , & V_39 -> V_142 ,
& V_144 ,
V_145 ) ;
F_51 ( V_2 , & V_39 -> V_143 ,
& V_146 ,
V_147 ) ;
F_52 ( & V_39 -> V_142 ,
& V_39 -> V_143 ) ;
V_39 -> type = V_148 ;
F_53 ( V_50 , & V_149 ) ;
F_54 ( V_54 ,
& V_150 ) ;
V_54 -> V_109 . V_151 = V_152 ;
V_54 -> V_153 = false ;
V_54 -> V_154 = false ;
F_55 ( V_54 ,
V_2 -> V_155 . V_156 ,
V_121 ) ;
F_55 ( V_54 ,
V_4 -> V_157 ,
V_24 ) ;
V_39 -> V_158 = F_56 ( V_2 ,
V_159 ,
L_14 ) ;
if ( ! V_39 -> V_158 ) {
F_57 ( V_89 ,
& V_2 -> V_160 -> V_2 , L_15 ) ;
goto V_161;
}
V_39 -> V_158 -> V_19 = 0x2C ;
V_4 -> V_13 = V_39 -> V_158 ;
V_39 -> V_114 = F_56 ( V_2 ,
V_162 ,
L_16 ) ;
if ( ! V_39 -> V_114 ) {
F_57 ( V_89 , & V_2 -> V_160 -> V_2 ,
L_17 L_18 ) ;
goto V_163;
}
F_32 ( V_39 ) ;
F_25 (scan, &connector->probed_modes, head) {
if ( V_138 -> type & V_164 ) {
V_47 -> V_72 =
F_33 ( V_2 , V_138 ) ;
goto V_165;
}
}
if ( V_47 -> V_166 )
V_47 -> V_72 =
F_33 ( V_2 , V_47 -> V_166 ) ;
if ( ! V_47 -> V_72 )
if ( V_4 -> V_167 )
V_47 -> V_72 =
F_33 ( V_2 ,
V_4 -> V_167 ) ;
V_140 = F_3 ( V_62 ) ;
V_88 = ( V_140 & V_168 ) ? 1 : 0 ;
V_86 = F_58 ( V_2 , V_88 ) ;
if ( V_86 && ( V_140 & V_169 ) ) {
V_47 -> V_72 =
F_59 ( V_2 , V_86 ) ;
if ( V_47 -> V_72 ) {
V_47 -> V_72 -> type |=
V_164 ;
goto V_165;
}
}
if ( ! V_47 -> V_72 ) {
F_8 ( V_2 -> V_2 , L_19 ) ;
goto V_170;
}
V_165:
F_60 ( V_54 ) ;
return;
V_170:
if ( V_39 -> V_114 )
F_36 ( V_39 -> V_114 ) ;
V_163:
if ( V_39 -> V_158 )
F_36 ( V_39 -> V_158 ) ;
V_161:
F_47 ( V_50 ) ;
F_38 ( V_54 ) ;
F_39 ( V_54 ) ;
}
