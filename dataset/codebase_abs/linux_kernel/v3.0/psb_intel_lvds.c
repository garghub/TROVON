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
F_7 ( L_1 ,
V_4 -> V_25 -> V_28 ,
V_15 ) ;
return 0 ;
}
F_8 ( L_2 ) ;
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
F_7 ( L_3 , V_11 ) ;
if ( ! V_4 -> V_25 ) {
F_8 ( L_4 ) ;
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
F_7 ( L_5 ,
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
F_7 ( L_5 ,
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
F_21 ( L_6 ) ;
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
bool F_22 ( struct V_49 * V_50 ,
struct V_70 * V_51 ,
struct V_70 * V_83 )
{
struct V_84 * V_47 =
F_16 ( V_50 ) -> V_47 ;
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_85 * V_85 =
F_23 ( V_50 -> V_86 ) ;
struct V_49 * V_87 ;
struct V_70 * V_72 = V_47 -> V_72 ;
struct V_39 * V_39 =
F_16 ( V_50 ) ;
F_21 ( L_7 ,
V_39 -> type , V_85 -> V_88 ) ;
if ( V_39 -> type == V_73 )
V_72 = V_47 -> V_74 ;
if ( ! F_24 ( V_2 ) && V_85 -> V_88 == 0 ) {
F_25 ( V_89 L_8 ) ;
return false ;
}
if ( F_24 ( V_2 ) && V_85 -> V_88 != 0 ) {
F_25 ( V_89 L_9 ) ;
return false ;
}
F_26 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_87 != V_50
&& V_87 -> V_86 == V_50 -> V_86 ) {
F_25 ( V_89 L_10
L_11 ) ;
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
F_27 ( V_83 ,
V_96 ) ;
}
return true ;
}
void F_28 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_16 ( V_50 ) ;
struct V_84 * V_47 = V_40 -> V_47 ;
F_21 ( L_6 ) ;
if ( ! F_2 ( V_2 , true ) )
return;
V_47 -> V_10 = F_3 ( V_7 ) ;
V_47 -> V_48 = ( V_47 -> V_10 &
V_37 ) ;
F_14 ( V_2 , V_40 , false ) ;
F_4 ( V_2 ) ;
}
void F_29 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_39 * V_40 = F_16 ( V_50 ) ;
struct V_84 * V_47 = V_40 -> V_47 ;
F_21 ( L_6 ) ;
if ( V_47 -> V_48 == 0 )
V_47 -> V_48 =
F_1 ( V_2 ) ;
F_14 ( V_2 , V_40 , true ) ;
}
static void F_30 ( struct V_49 * V_50 ,
struct V_70 * V_51 ,
struct V_70 * V_83 )
{
struct V_84 * V_47 =
F_16 ( V_50 ) -> V_47 ;
struct V_1 * V_2 = V_50 -> V_2 ;
T_1 V_97 ;
if ( V_51 -> V_79 != V_83 -> V_79 ||
V_51 -> V_81 != V_83 -> V_81 )
V_97 = ( V_98 | V_99 |
V_100 | V_101 |
V_102 ) ;
else
V_97 = 0 ;
if ( V_47 -> V_103 )
V_97 |= V_104 ;
F_11 ( V_67 , V_97 ) ;
}
static enum V_105 F_31 ( struct V_53
* V_54 , bool V_106 )
{
return V_107 ;
}
static int F_32 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_39 * V_39 =
F_18 ( V_54 ) ;
struct V_84 * V_47 =
V_39 -> V_47 ;
int V_108 = 0 ;
V_108 = F_33 ( V_39 ) ;
if ( V_108 )
return V_108 ;
V_54 -> V_109 . V_110 = 0 ;
V_54 -> V_109 . V_111 = 200 ;
V_54 -> V_109 . V_112 = 0 ;
V_54 -> V_109 . V_113 = 200 ;
if ( V_47 -> V_72 != NULL ) {
struct V_70 * V_51 =
F_34 ( V_2 , V_47 -> V_72 ) ;
F_35 ( V_54 , V_51 ) ;
return 1 ;
}
return 0 ;
}
void F_36 ( struct V_53 * V_54 )
{
struct V_39 * V_39 =
F_18 ( V_54 ) ;
if ( V_39 -> V_114 )
F_37 ( V_39 -> V_114 ) ;
F_38 ( V_54 ) ;
F_39 ( V_54 ) ;
F_40 ( V_54 ) ;
}
int F_41 ( struct V_53 * V_54 ,
struct V_115 * V_116 ,
T_3 V_117 )
{
struct V_49 * V_118 = V_54 -> V_50 ;
F_21 ( L_6 ) ;
if ( ! strcmp ( V_116 -> V_119 , L_12 ) && V_118 ) {
struct V_85 * V_120 =
F_23 ( V_118 -> V_86 ) ;
T_3 V_121 ;
F_21 ( L_13 ) ;
if ( ! V_120 )
goto V_122;
switch ( V_117 ) {
case V_123 :
break;
case V_124 :
break;
case V_125 :
break;
default:
goto V_122;
}
if ( F_42 ( V_54 ,
V_116 ,
& V_121 ) )
goto V_122;
if ( V_121 == V_117 )
goto V_126;
if ( F_43 ( V_54 ,
V_116 ,
V_117 ) )
goto V_122;
if ( V_120 -> V_127 . V_79 != 0 &&
V_120 -> V_127 . V_81 != 0 ) {
if ( ! F_44 ( V_118 -> V_86 ,
& V_120 -> V_127 ,
V_118 -> V_86 -> V_128 ,
V_118 -> V_86 -> V_129 ,
V_118 -> V_86 -> V_130 ) )
goto V_122;
}
} else if ( ! strcmp ( V_116 -> V_119 , L_14 ) && V_118 ) {
F_21 ( L_15 ) ;
if ( F_43 ( V_54 ,
V_116 ,
V_117 ) )
goto V_122;
else {
#ifdef F_45
struct V_131 V_132 ;
V_132 . V_133 . V_134 = V_117 ;
F_46 ( & V_132 ) ;
#endif
}
} else if ( ! strcmp ( V_116 -> V_119 , L_16 ) && V_118 ) {
struct V_135 * V_136
= V_118 -> V_137 ;
F_21 ( L_17 ) ;
V_136 -> V_138 ( V_118 , V_117 ) ;
}
V_126:
return 0 ;
V_122:
return - 1 ;
}
static void F_47 ( struct V_49 * V_50 )
{
F_48 ( V_50 ) ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_84 * V_47 )
{
struct V_39 * V_39 ;
struct V_55 * V_56 ;
struct V_53 * V_54 ;
struct V_49 * V_50 ;
struct V_70 * V_139 ;
struct V_140 * V_86 ;
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
T_1 V_141 ;
int V_88 ;
V_39 = F_50 ( sizeof( struct V_39 ) , V_142 ) ;
if ( ! V_39 )
return;
V_56 = F_50 ( sizeof( struct V_55 ) , V_142 ) ;
if ( ! V_56 ) {
F_40 ( V_39 ) ;
F_7 ( L_18 ) ;
return;
}
V_39 -> V_4 = V_56 ;
V_39 -> V_47 = V_47 ;
V_54 = & V_39 -> V_143 ;
V_50 = & V_39 -> V_144 ;
F_51 ( V_2 , & V_39 -> V_143 ,
& V_145 ,
V_146 ) ;
F_52 ( V_2 , & V_39 -> V_144 ,
& V_147 ,
V_148 ) ;
F_53 ( & V_39 -> V_143 ,
& V_39 -> V_144 ) ;
V_39 -> type = V_149 ;
F_54 ( V_50 , & V_150 ) ;
F_55 ( V_54 ,
& V_151 ) ;
V_54 -> V_109 . V_152 = V_153 ;
V_54 -> V_154 = false ;
V_54 -> V_155 = false ;
F_56 ( V_54 ,
V_2 -> V_156 . V_157 ,
V_123 ) ;
F_56 ( V_54 ,
V_4 -> V_158 ,
V_24 ) ;
V_39 -> V_159 = F_57 ( V_2 ,
V_160 ,
L_19 ) ;
if ( ! V_39 -> V_159 ) {
F_58 ( V_89 ,
& V_2 -> V_161 -> V_2 , L_20 ) ;
goto V_162;
}
V_39 -> V_159 -> V_19 = 0x2C ;
V_4 -> V_13 = V_39 -> V_159 ;
V_39 -> V_114 = F_57 ( V_2 ,
V_163 ,
L_21 ) ;
if ( ! V_39 -> V_114 ) {
F_58 ( V_89 , & V_2 -> V_161 -> V_2 ,
L_22 L_23 ) ;
goto V_164;
}
F_33 ( V_39 ) ;
F_26 (scan, &connector->probed_modes, head) {
if ( V_139 -> type & V_165 ) {
V_47 -> V_72 =
F_34 ( V_2 , V_139 ) ;
goto V_166;
}
}
if ( V_47 -> V_167 )
V_47 -> V_72 =
F_34 ( V_2 , V_47 -> V_167 ) ;
if ( ! V_47 -> V_72 )
if ( V_4 -> V_168 )
V_47 -> V_72 =
F_34 ( V_2 ,
V_4 -> V_168 ) ;
V_141 = F_3 ( V_62 ) ;
V_88 = ( V_141 & V_169 ) ? 1 : 0 ;
V_86 = F_59 ( V_2 , V_88 ) ;
if ( V_86 && ( V_141 & V_170 ) ) {
V_47 -> V_72 =
F_60 ( V_2 , V_86 ) ;
if ( V_47 -> V_72 ) {
V_47 -> V_72 -> type |=
V_165 ;
goto V_166;
}
}
if ( ! V_47 -> V_72 ) {
F_7
( L_24 ) ;
goto V_171;
}
V_166:
F_61 ( V_54 ) ;
F_21 ( L_25 ,
V_47 -> V_72 -> V_79 ) ;
F_21 ( L_26 ,
V_47 -> V_72 -> V_81 ) ;
F_21 ( L_27 ,
V_47 -> V_72 -> V_90 ) ;
F_21 ( L_28 ,
V_47 -> V_72 -> V_91 ) ;
F_21 ( L_29 ,
V_47 -> V_72 -> V_92 ) ;
F_21 ( L_30 ,
V_47 -> V_72 -> V_93 ) ;
F_21 ( L_31 ,
V_47 -> V_72 -> V_94 ) ;
F_21 ( L_32 ,
V_47 -> V_72 -> V_95 ) ;
F_21 ( L_33 ,
V_47 -> V_72 -> clock ) ;
return;
V_171:
if ( V_39 -> V_114 )
F_37 ( V_39 -> V_114 ) ;
V_164:
if ( V_39 -> V_159 )
F_37 ( V_39 -> V_159 ) ;
V_162:
F_48 ( V_50 ) ;
F_39 ( V_54 ) ;
F_40 ( V_54 ) ;
}
