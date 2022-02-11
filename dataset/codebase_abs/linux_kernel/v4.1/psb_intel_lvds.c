static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
if ( F_2 ( V_2 , false ) ) {
V_6 = F_3 ( V_7 ) ;
F_4 ( V_2 ) ;
} else
V_6 = V_4 -> V_8 . V_9 ;
V_6 = ( V_6 & V_10 ) >>
V_11 ;
V_6 *= 2 ;
if ( V_6 == 0 )
F_5 ( V_2 -> V_2 , L_1 ,
F_3 ( V_7 ) , V_4 -> V_8 . V_9 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
struct V_13 * V_14 = V_4 -> V_14 ;
T_2 V_15 [ 2 ] ;
unsigned int V_16 ;
struct V_17 V_18 [] = {
{
. V_19 = V_14 -> V_20 ,
. V_21 = 0 ,
. V_22 = 2 ,
. V_23 = V_15 ,
}
} ;
V_16 = V_24 & ( ( unsigned int ) V_12 *
V_24 /
V_25 ) ;
if ( V_4 -> V_26 -> V_27 == V_28 )
V_16 = V_24 - V_16 ;
V_15 [ 0 ] = V_4 -> V_26 -> V_29 ;
V_15 [ 1 ] = ( T_2 ) V_16 ;
if ( F_7 ( & V_14 -> V_30 , V_18 , 1 ) == 1 ) {
F_8 ( V_2 -> V_2 , L_2 ,
V_4 -> V_26 -> V_29 ,
V_16 ) ;
return 0 ;
}
F_5 ( V_2 -> V_2 , L_3 ) ;
return - 1 ;
}
static int F_9 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
T_1 V_31 ;
T_1 V_32 ;
V_31 = F_1 ( V_2 ) ;
F_10 ( V_31 == 0 ) ;
V_32 = V_12 * V_31 / V_25 ;
if ( V_4 -> V_26 -> V_27 == V_28 )
V_32 = V_31 - V_32 ;
V_32 &= V_33 ;
F_11 ( V_7 ,
( V_31 << V_34 ) |
( V_32 ) ) ;
F_12 ( V_2 -> V_2 , L_4 ,
( V_31 << V_34 ) |
( V_32 ) ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( V_2 -> V_2 , L_5 , V_12 ) ;
if ( ! V_4 -> V_26 ) {
F_5 ( V_2 -> V_2 , L_6 ) ;
return;
}
if ( V_4 -> V_26 -> type == V_35 )
F_6 ( V_2 , V_12 ) ;
else
F_9 ( V_2 , V_12 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_36 ;
if ( F_2 ( V_2 , false ) ) {
V_36 = F_3 ( V_7 ) ;
V_36 &= ~ V_37 ;
F_11 ( V_7 ,
( V_36 |
( V_12 << V_38 ) ) ) ;
V_4 -> V_8 . V_9 = ( V_36 |
( V_12 << V_38 ) ) ;
F_4 ( V_2 ) ;
} else {
V_36 = V_4 -> V_8 . V_9 &
~ V_37 ;
V_4 -> V_8 . V_9 = ( V_36 |
( V_12 << V_38 ) ) ;
}
}
static void F_15 ( struct V_1 * V_2 , bool V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 = & V_4 -> V_41 ;
T_1 V_42 ;
if ( ! F_2 ( V_2 , true ) ) {
F_5 ( V_2 -> V_2 , L_7 ) ;
return;
}
if ( V_39 ) {
F_11 ( V_43 , F_3 ( V_43 ) |
V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( ( V_42 & V_46 ) == 0 );
F_14 ( V_2 ,
V_41 -> V_47 ) ;
} else {
F_14 ( V_2 , 0 ) ;
F_11 ( V_43 , F_3 ( V_43 ) &
~ V_44 ) ;
do {
V_42 = F_3 ( V_45 ) ;
} while ( V_42 & V_46 );
}
F_4 ( V_2 ) ;
}
static void F_16 ( struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
if ( V_50 == V_51 )
F_15 ( V_2 , true ) ;
else
F_15 ( V_2 , false ) ;
}
static void F_17 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
struct V_54 * V_54 = F_18 ( V_53 ) ;
struct V_55 * V_56 =
(struct V_55 * ) V_54 -> V_4 ;
V_56 -> V_57 = F_3 ( V_58 ) ;
V_56 -> V_59 = F_3 ( V_60 ) ;
V_56 -> V_61 = F_3 ( V_62 ) ;
V_56 -> V_63 = F_3 ( V_43 ) ;
V_56 -> V_64 = F_3 ( V_65 ) ;
V_56 -> V_9 = F_3 ( V_7 ) ;
V_56 -> V_66 = F_3 ( V_67 ) ;
V_56 -> V_68 = F_3 ( V_69 ) ;
V_4 -> V_47 = ( V_4 -> V_8 . V_9 &
V_37 ) ;
if ( V_4 -> V_47 == 0 )
V_4 -> V_47 =
F_1 ( V_2 ) ;
F_8 ( V_2 -> V_2 , L_8 ,
V_56 -> V_57 ,
V_56 -> V_59 ,
V_56 -> V_61 ,
V_56 -> V_63 ,
V_56 -> V_64 ,
V_56 -> V_9 ) ;
}
static void F_19 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_1 V_42 ;
struct V_54 * V_54 = F_18 ( V_53 ) ;
struct V_55 * V_56 =
(struct V_55 * ) V_54 -> V_4 ;
F_8 ( V_2 -> V_2 , L_8 ,
V_56 -> V_57 ,
V_56 -> V_59 ,
V_56 -> V_61 ,
V_56 -> V_63 ,
V_56 -> V_64 ,
V_56 -> V_9 ) ;
F_11 ( V_7 , V_56 -> V_9 ) ;
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
int F_20 ( struct V_52 * V_53 ,
struct V_70 * V_50 )
{
struct V_3 * V_4 = V_53 -> V_2 -> V_5 ;
struct V_54 * V_54 = F_18 ( V_53 ) ;
struct V_70 * V_71 =
V_4 -> V_41 . V_72 ;
if ( V_54 -> type == V_73 )
V_71 = V_4 -> V_41 . V_74 ;
if ( V_50 -> V_21 & V_75 )
return V_76 ;
if ( V_50 -> V_21 & V_77 )
return V_78 ;
if ( V_71 ) {
if ( V_50 -> V_79 > V_71 -> V_79 )
return V_80 ;
if ( V_50 -> V_81 > V_71 -> V_81 )
return V_80 ;
}
return V_82 ;
}
bool F_21 ( struct V_48 * V_49 ,
const struct V_70 * V_50 ,
struct V_70 * V_83 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 = & V_4 -> V_41 ;
struct V_84 * V_84 = F_22 ( V_49 -> V_85 ) ;
struct V_48 * V_86 ;
struct V_70 * V_72 = V_41 -> V_72 ;
struct V_54 * V_54 = F_23 ( V_49 ) ;
if ( V_54 -> type == V_73 )
V_72 = V_41 -> V_74 ;
if ( ! F_24 ( V_2 ) && V_84 -> V_87 == 0 ) {
F_25 ( V_88 L_9 ) ;
return false ;
}
if ( F_24 ( V_2 ) && V_84 -> V_87 != 0 ) {
F_25 ( V_88 L_10 ) ;
return false ;
}
F_26 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_86 != V_49
&& V_86 -> V_85 == V_49 -> V_85 ) {
F_25 ( V_88 L_11
L_12 ) ;
return false ;
}
}
if ( V_72 != NULL ) {
V_83 -> V_79 = V_72 -> V_79 ;
V_83 -> V_89 = V_72 -> V_89 ;
V_83 -> V_90 = V_72 -> V_90 ;
V_83 -> V_91 = V_72 -> V_91 ;
V_83 -> V_81 = V_72 -> V_81 ;
V_83 -> V_92 = V_72 -> V_92 ;
V_83 -> V_93 = V_72 -> V_93 ;
V_83 -> V_94 = V_72 -> V_94 ;
V_83 -> clock = V_72 -> clock ;
F_27 ( V_83 ,
V_95 ) ;
}
return true ;
}
static void F_28 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 = & V_4 -> V_41 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_41 -> V_9 = F_3 ( V_7 ) ;
V_41 -> V_47 = ( V_41 -> V_9 &
V_37 ) ;
F_15 ( V_2 , false ) ;
F_4 ( V_2 ) ;
}
static void F_29 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 = & V_4 -> V_41 ;
if ( V_41 -> V_47 == 0 )
V_41 -> V_47 =
F_1 ( V_2 ) ;
F_15 ( V_2 , true ) ;
}
static void F_30 ( struct V_48 * V_49 ,
struct V_70 * V_50 ,
struct V_70 * V_83 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_96 ;
if ( V_50 -> V_79 != V_83 -> V_79 ||
V_50 -> V_81 != V_83 -> V_81 )
V_96 = ( V_97 | V_98 |
V_99 | V_100 |
V_101 ) ;
else
V_96 = 0 ;
if ( V_4 -> V_102 )
V_96 |= V_103 ;
F_11 ( V_67 , V_96 ) ;
}
static enum V_104 F_31 ( struct V_52
* V_53 , bool V_105 )
{
return V_106 ;
}
static int F_32 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 = & V_4 -> V_41 ;
struct V_54 * V_54 = F_18 ( V_53 ) ;
struct V_55 * V_56 = V_54 -> V_4 ;
int V_6 = 0 ;
if ( ! F_24 ( V_2 ) )
V_6 = F_33 ( V_53 , & V_56 -> V_107 -> V_30 ) ;
if ( V_6 )
return V_6 ;
V_53 -> V_108 . V_109 = 0 ;
V_53 -> V_108 . V_110 = 200 ;
V_53 -> V_108 . V_111 = 0 ;
V_53 -> V_108 . V_112 = 200 ;
if ( V_41 -> V_72 != NULL ) {
struct V_70 * V_50 =
F_34 ( V_2 , V_41 -> V_72 ) ;
F_35 ( V_53 , V_50 ) ;
return 1 ;
}
return 0 ;
}
void F_36 ( struct V_52 * V_53 )
{
struct V_54 * V_54 = F_18 ( V_53 ) ;
struct V_55 * V_56 = V_54 -> V_4 ;
if ( V_56 -> V_113 )
F_37 ( V_56 -> V_113 ) ;
F_38 ( V_53 ) ;
F_39 ( V_53 ) ;
F_40 ( V_53 ) ;
}
int F_41 ( struct V_52 * V_53 ,
struct V_114 * V_115 ,
T_3 V_116 )
{
struct V_48 * V_49 = V_53 -> V_49 ;
if ( ! V_49 )
return - 1 ;
if ( ! strcmp ( V_115 -> V_117 , L_13 ) ) {
struct V_84 * V_85 = F_22 ( V_49 -> V_85 ) ;
T_3 V_118 ;
if ( ! V_85 )
goto V_119;
switch ( V_116 ) {
case V_120 :
break;
case V_121 :
break;
case V_122 :
break;
default:
goto V_119;
}
if ( F_42 ( & V_53 -> V_123 ,
V_115 ,
& V_118 ) )
goto V_119;
if ( V_118 == V_116 )
goto V_124;
if ( F_43 ( & V_53 -> V_123 ,
V_115 ,
V_116 ) )
goto V_119;
if ( V_85 -> V_125 . V_79 != 0 &&
V_85 -> V_125 . V_81 != 0 ) {
if ( ! F_44 ( V_49 -> V_85 ,
& V_85 -> V_125 ,
V_49 -> V_85 -> V_126 ,
V_49 -> V_85 -> V_127 ,
V_49 -> V_85 -> V_128 -> V_129 ) )
goto V_119;
}
} else if ( ! strcmp ( V_115 -> V_117 , L_14 ) ) {
if ( F_43 ( & V_53 -> V_123 ,
V_115 ,
V_116 ) )
goto V_119;
else
F_45 ( V_49 -> V_2 , V_116 ) ;
} else if ( ! strcmp ( V_115 -> V_117 , L_15 ) ) {
const struct V_130 * V_131
= V_49 -> V_132 ;
V_131 -> V_133 ( V_49 , V_116 ) ;
}
V_124:
return 0 ;
V_119:
return - 1 ;
}
static void F_46 ( struct V_48 * V_49 )
{
F_47 ( V_49 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_54 * V_54 ;
struct V_134 * V_134 ;
struct V_55 * V_56 ;
struct V_52 * V_53 ;
struct V_48 * V_49 ;
struct V_70 * V_135 ;
struct V_136 * V_85 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_137 ;
int V_87 ;
V_54 = F_49 ( sizeof( struct V_54 ) , V_138 ) ;
if ( ! V_54 ) {
F_5 ( V_2 -> V_2 , L_16 ) ;
return;
}
V_134 = F_49 ( sizeof( struct V_134 ) , V_138 ) ;
if ( ! V_134 ) {
F_5 ( V_2 -> V_2 , L_17 ) ;
goto V_139;
}
V_56 = F_49 ( sizeof( struct V_55 ) , V_138 ) ;
if ( ! V_56 ) {
F_5 ( V_2 -> V_2 , L_18 ) ;
goto V_140;
}
V_54 -> V_4 = V_56 ;
V_53 = & V_134 -> V_123 ;
V_49 = & V_54 -> V_123 ;
F_50 ( V_2 , V_53 ,
& V_141 ,
V_142 ) ;
F_51 ( V_2 , V_49 ,
& V_143 ,
V_144 ) ;
F_52 ( V_134 , V_54 ) ;
V_54 -> type = V_145 ;
F_53 ( V_49 , & V_146 ) ;
F_54 ( V_53 ,
& V_147 ) ;
V_53 -> V_108 . V_148 = V_149 ;
V_53 -> V_150 = false ;
V_53 -> V_151 = false ;
F_55 ( & V_53 -> V_123 ,
V_2 -> V_152 . V_153 ,
V_120 ) ;
F_55 ( & V_53 -> V_123 ,
V_4 -> V_154 ,
V_25 ) ;
V_56 -> V_107 = F_56 ( V_2 , V_155 , L_19 ) ;
if ( ! V_56 -> V_107 ) {
F_57 ( V_88 ,
& V_2 -> V_156 -> V_2 , L_20 ) ;
goto V_157;
}
V_56 -> V_107 -> V_20 = 0x2C ;
V_4 -> V_14 = V_56 -> V_107 ;
V_56 -> V_113 = F_56 ( V_2 , V_158 , L_21 ) ;
if ( ! V_56 -> V_113 ) {
F_57 ( V_88 , & V_2 -> V_156 -> V_2 ,
L_22 L_23 ) ;
goto V_159;
}
F_58 ( & V_2 -> V_152 . V_160 ) ;
F_33 ( V_53 , & V_56 -> V_113 -> V_30 ) ;
F_26 (scan, &connector->probed_modes, head) {
if ( V_135 -> type & V_161 ) {
V_41 -> V_72 =
F_34 ( V_2 , V_135 ) ;
goto V_162;
}
}
if ( V_41 -> V_163 )
V_41 -> V_72 =
F_34 ( V_2 , V_41 -> V_163 ) ;
if ( ! V_41 -> V_72 )
if ( V_4 -> V_164 )
V_41 -> V_72 =
F_34 ( V_2 ,
V_4 -> V_164 ) ;
V_137 = F_3 ( V_62 ) ;
V_87 = ( V_137 & V_165 ) ? 1 : 0 ;
V_85 = F_59 ( V_2 , V_87 ) ;
if ( V_85 && ( V_137 & V_166 ) ) {
V_41 -> V_72 =
F_60 ( V_2 , V_85 ) ;
if ( V_41 -> V_72 ) {
V_41 -> V_72 -> type |=
V_161 ;
goto V_162;
}
}
if ( ! V_41 -> V_72 ) {
F_5 ( V_2 -> V_2 , L_24 ) ;
goto V_167;
}
V_162:
F_61 ( & V_2 -> V_152 . V_160 ) ;
F_62 ( V_53 ) ;
return;
V_167:
F_61 ( & V_2 -> V_152 . V_160 ) ;
if ( V_56 -> V_113 )
F_37 ( V_56 -> V_113 ) ;
V_159:
if ( V_56 -> V_107 )
F_37 ( V_56 -> V_107 ) ;
V_157:
F_47 ( V_49 ) ;
F_39 ( V_53 ) ;
V_140:
F_40 ( V_134 ) ;
V_139:
F_40 ( V_54 ) ;
}
