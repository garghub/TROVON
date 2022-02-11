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
F_25 ( L_9 ) ;
return false ;
}
if ( F_24 ( V_2 ) && V_84 -> V_87 != 0 ) {
F_25 ( L_10 ) ;
return false ;
}
F_26 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_86 != V_49
&& V_86 -> V_85 == V_49 -> V_85 ) {
F_25 ( L_11 ) ;
return false ;
}
}
if ( V_72 != NULL ) {
V_83 -> V_79 = V_72 -> V_79 ;
V_83 -> V_88 = V_72 -> V_88 ;
V_83 -> V_89 = V_72 -> V_89 ;
V_83 -> V_90 = V_72 -> V_90 ;
V_83 -> V_81 = V_72 -> V_81 ;
V_83 -> V_91 = V_72 -> V_91 ;
V_83 -> V_92 = V_72 -> V_92 ;
V_83 -> V_93 = V_72 -> V_93 ;
V_83 -> clock = V_72 -> clock ;
F_27 ( V_83 ,
V_94 ) ;
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
T_1 V_95 ;
if ( V_50 -> V_79 != V_83 -> V_79 ||
V_50 -> V_81 != V_83 -> V_81 )
V_95 = ( V_96 | V_97 |
V_98 | V_99 |
V_100 ) ;
else
V_95 = 0 ;
if ( V_4 -> V_101 )
V_95 |= V_102 ;
F_11 ( V_67 , V_95 ) ;
}
static int F_31 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_41 = & V_4 -> V_41 ;
struct V_54 * V_54 = F_18 ( V_53 ) ;
struct V_55 * V_56 = V_54 -> V_4 ;
int V_6 = 0 ;
if ( ! F_24 ( V_2 ) )
V_6 = F_32 ( V_53 , & V_56 -> V_103 -> V_30 ) ;
if ( V_6 )
return V_6 ;
if ( V_41 -> V_72 != NULL ) {
struct V_70 * V_50 =
F_33 ( V_2 , V_41 -> V_72 ) ;
F_34 ( V_53 , V_50 ) ;
return 1 ;
}
return 0 ;
}
void F_35 ( struct V_52 * V_53 )
{
struct V_54 * V_54 = F_18 ( V_53 ) ;
struct V_55 * V_56 = V_54 -> V_4 ;
F_36 ( V_56 -> V_104 ) ;
F_37 ( V_53 ) ;
F_38 ( V_53 ) ;
F_39 ( V_53 ) ;
}
int F_40 ( struct V_52 * V_53 ,
struct V_105 * V_106 ,
T_3 V_107 )
{
struct V_48 * V_49 = V_53 -> V_49 ;
if ( ! V_49 )
return - 1 ;
if ( ! strcmp ( V_106 -> V_108 , L_12 ) ) {
struct V_84 * V_85 = F_22 ( V_49 -> V_85 ) ;
T_3 V_109 ;
if ( ! V_85 )
goto V_110;
switch ( V_107 ) {
case V_111 :
break;
case V_112 :
break;
case V_113 :
break;
default:
goto V_110;
}
if ( F_41 ( & V_53 -> V_114 ,
V_106 ,
& V_109 ) )
goto V_110;
if ( V_109 == V_107 )
goto V_115;
if ( F_42 ( & V_53 -> V_114 ,
V_106 ,
V_107 ) )
goto V_110;
if ( V_85 -> V_116 . V_79 != 0 &&
V_85 -> V_116 . V_81 != 0 ) {
if ( ! F_43 ( V_49 -> V_85 ,
& V_85 -> V_116 ,
V_49 -> V_85 -> V_117 ,
V_49 -> V_85 -> V_118 ,
V_49 -> V_85 -> V_119 -> V_120 ) )
goto V_110;
}
} else if ( ! strcmp ( V_106 -> V_108 , L_13 ) ) {
if ( F_42 ( & V_53 -> V_114 ,
V_106 ,
V_107 ) )
goto V_110;
else
F_44 ( V_49 -> V_2 , V_107 ) ;
} else if ( ! strcmp ( V_106 -> V_108 , L_14 ) ) {
const struct V_121 * V_122
= V_49 -> V_123 ;
V_122 -> V_124 ( V_49 , V_107 ) ;
}
V_115:
return 0 ;
V_110:
return - 1 ;
}
static void F_45 ( struct V_48 * V_49 )
{
F_46 ( V_49 ) ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_54 * V_54 ;
struct V_125 * V_125 ;
struct V_55 * V_56 ;
struct V_52 * V_53 ;
struct V_48 * V_49 ;
struct V_70 * V_126 ;
struct V_127 * V_85 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_128 ;
int V_87 ;
V_54 = F_48 ( sizeof( struct V_54 ) , V_129 ) ;
if ( ! V_54 ) {
F_5 ( V_2 -> V_2 , L_15 ) ;
return;
}
V_125 = F_48 ( sizeof( struct V_125 ) , V_129 ) ;
if ( ! V_125 ) {
F_5 ( V_2 -> V_2 , L_16 ) ;
goto V_130;
}
V_56 = F_48 ( sizeof( struct V_55 ) , V_129 ) ;
if ( ! V_56 ) {
F_5 ( V_2 -> V_2 , L_17 ) ;
goto V_131;
}
V_54 -> V_4 = V_56 ;
V_53 = & V_125 -> V_114 ;
V_125 -> V_132 = F_17 ;
V_125 -> V_133 = F_19 ;
V_49 = & V_54 -> V_114 ;
F_49 ( V_2 , V_53 ,
& V_134 ,
V_135 ) ;
F_50 ( V_2 , V_49 ,
& V_136 ,
V_137 , NULL ) ;
F_51 ( V_125 , V_54 ) ;
V_54 -> type = V_138 ;
F_52 ( V_49 , & V_139 ) ;
F_53 ( V_53 ,
& V_140 ) ;
V_53 -> V_141 . V_142 = V_143 ;
V_53 -> V_144 = false ;
V_53 -> V_145 = false ;
F_54 ( & V_53 -> V_114 ,
V_2 -> V_146 . V_147 ,
V_111 ) ;
F_54 ( & V_53 -> V_114 ,
V_4 -> V_148 ,
V_25 ) ;
V_56 -> V_103 = F_55 ( V_2 , V_149 , L_18 ) ;
if ( ! V_56 -> V_103 ) {
F_56 ( V_150 ,
& V_2 -> V_151 -> V_2 , L_19 ) ;
goto V_152;
}
V_56 -> V_103 -> V_20 = 0x2C ;
V_4 -> V_14 = V_56 -> V_103 ;
V_56 -> V_104 = F_55 ( V_2 , V_153 , L_20 ) ;
if ( ! V_56 -> V_104 ) {
F_56 ( V_150 , & V_2 -> V_151 -> V_2 ,
L_21 L_22 ) ;
goto V_154;
}
F_57 ( & V_2 -> V_146 . V_155 ) ;
F_32 ( V_53 , & V_56 -> V_104 -> V_30 ) ;
F_26 (scan, &connector->probed_modes, head) {
if ( V_126 -> type & V_156 ) {
V_41 -> V_72 =
F_33 ( V_2 , V_126 ) ;
F_58 ( L_23 ) ;
goto V_157;
}
}
if ( V_4 -> V_158 ) {
V_41 -> V_72 =
F_33 ( V_2 , V_4 -> V_158 ) ;
if ( V_41 -> V_72 ) {
V_41 -> V_72 -> type |=
V_156 ;
F_58 ( L_24 ) ;
goto V_157;
}
}
V_128 = F_3 ( V_62 ) ;
V_87 = ( V_128 & V_159 ) ? 1 : 0 ;
V_85 = F_59 ( V_2 , V_87 ) ;
if ( V_85 && ( V_128 & V_160 ) ) {
V_41 -> V_72 =
F_60 ( V_2 , V_85 ) ;
if ( V_41 -> V_72 ) {
V_41 -> V_72 -> type |=
V_156 ;
F_58 ( L_25 ) ;
goto V_157;
}
}
if ( ! V_41 -> V_72 ) {
F_5 ( V_2 -> V_2 , L_26 ) ;
goto V_161;
}
V_157:
F_61 ( & V_2 -> V_146 . V_155 ) ;
F_62 ( V_53 ) ;
return;
V_161:
F_61 ( & V_2 -> V_146 . V_155 ) ;
F_36 ( V_56 -> V_104 ) ;
V_154:
F_36 ( V_56 -> V_103 ) ;
V_152:
F_46 ( V_49 ) ;
F_38 ( V_53 ) ;
V_131:
F_39 ( V_125 ) ;
V_130:
F_39 ( V_54 ) ;
}
