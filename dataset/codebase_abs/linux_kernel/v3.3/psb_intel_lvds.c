static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
if ( F_2 ( V_2 , false ) ) {
V_6 = F_3 ( V_7 ) ;
F_4 ( V_2 ) ;
} else
V_6 = V_4 -> V_8 ;
V_6 = ( V_6 & V_9 ) >>
V_10 ;
V_6 *= 2 ;
if ( V_6 == 0 )
F_5 ( V_2 -> V_2 , L_1 ,
F_3 ( V_7 ) , V_4 -> V_8 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
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
if ( F_7 ( & V_13 -> V_29 , V_17 , 1 ) == 1 ) {
F_8 ( V_2 -> V_2 , L_2 ,
V_4 -> V_25 -> V_28 ,
V_15 ) ;
return 0 ;
}
F_5 ( V_2 -> V_2 , L_3 ) ;
return - 1 ;
}
static int F_9 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
T_1 V_30 ;
T_1 V_31 ;
V_30 = F_1 ( V_2 ) ;
F_10 ( V_30 == 0 ) ;
V_31 = V_11 * V_30 / V_24 ;
if ( V_4 -> V_25 -> V_26 == V_27 )
V_31 = V_30 - V_31 ;
V_31 &= V_32 ;
F_11 ( V_7 ,
( V_30 << V_33 ) |
( V_31 ) ) ;
F_12 ( V_2 -> V_2 , L_4 ,
( V_30 << V_33 ) |
( V_31 ) ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( V_2 -> V_2 , L_5 , V_11 ) ;
if ( ! V_4 -> V_25 ) {
F_5 ( V_2 -> V_2 , L_6 ) ;
return;
}
if ( V_4 -> V_25 -> type == V_34 )
F_6 ( V_2 , V_11 ) ;
else
F_9 ( V_2 , V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_35 ;
if ( F_2 ( V_2 , false ) ) {
V_35 = F_3 ( V_7 ) ;
V_35 &= ~ V_36 ;
F_11 ( V_7 ,
( V_35 |
( V_11 << V_37 ) ) ) ;
V_4 -> V_8 = ( V_35 |
( V_11 << V_37 ) ) ;
F_4 ( V_2 ) ;
} else {
V_35 = V_4 -> V_8 &
~ V_36 ;
V_4 -> V_8 = ( V_35 |
( V_11 << V_37 ) ) ;
}
}
static void F_15 ( struct V_1 * V_2 , bool V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 = & V_4 -> V_40 ;
T_1 V_41 ;
if ( ! F_2 ( V_2 , true ) ) {
F_5 ( V_2 -> V_2 , L_7 ) ;
return;
}
if ( V_38 ) {
F_11 ( V_42 , F_3 ( V_42 ) |
V_43 ) ;
do {
V_41 = F_3 ( V_44 ) ;
} while ( ( V_41 & V_45 ) == 0 );
F_14 ( V_2 ,
V_40 -> V_46 ) ;
} else {
F_14 ( V_2 , 0 ) ;
F_11 ( V_42 , F_3 ( V_42 ) &
~ V_43 ) ;
do {
V_41 = F_3 ( V_44 ) ;
} while ( V_41 & V_45 );
}
F_4 ( V_2 ) ;
}
static void F_16 ( struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
if ( V_49 == V_50 )
F_15 ( V_2 , true ) ;
else
F_15 ( V_2 , false ) ;
}
static void F_17 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
struct V_53 * V_53 =
F_18 ( V_52 ) ;
struct V_54 * V_55 =
(struct V_54 * ) V_53 -> V_4 ;
V_55 -> V_56 = F_3 ( V_57 ) ;
V_55 -> V_58 = F_3 ( V_59 ) ;
V_55 -> V_60 = F_3 ( V_61 ) ;
V_55 -> V_62 = F_3 ( V_42 ) ;
V_55 -> V_63 = F_3 ( V_64 ) ;
V_55 -> V_8 = F_3 ( V_7 ) ;
V_55 -> V_65 = F_3 ( V_66 ) ;
V_55 -> V_67 = F_3 ( V_68 ) ;
V_4 -> V_46 = ( V_4 -> V_8 &
V_36 ) ;
if ( V_4 -> V_46 == 0 )
V_4 -> V_46 =
F_1 ( V_2 ) ;
F_8 ( V_2 -> V_2 , L_8 ,
V_55 -> V_56 ,
V_55 -> V_58 ,
V_55 -> V_60 ,
V_55 -> V_62 ,
V_55 -> V_63 ,
V_55 -> V_8 ) ;
}
static void F_19 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_41 ;
struct V_53 * V_53 =
F_18 ( V_52 ) ;
struct V_54 * V_55 =
(struct V_54 * ) V_53 -> V_4 ;
F_8 ( V_2 -> V_2 , L_8 ,
V_55 -> V_56 ,
V_55 -> V_58 ,
V_55 -> V_60 ,
V_55 -> V_62 ,
V_55 -> V_63 ,
V_55 -> V_8 ) ;
F_11 ( V_7 , V_55 -> V_8 ) ;
F_11 ( V_66 , V_55 -> V_65 ) ;
F_11 ( V_68 , V_55 -> V_67 ) ;
F_11 ( V_57 , V_55 -> V_56 ) ;
F_11 ( V_59 , V_55 -> V_58 ) ;
F_11 ( V_64 , V_55 -> V_63 ) ;
F_11 ( V_42 , V_55 -> V_62 ) ;
F_11 ( V_61 , V_55 -> V_60 ) ;
if ( V_55 -> V_62 & V_43 ) {
F_11 ( V_42 , F_3 ( V_42 ) |
V_43 ) ;
do {
V_41 = F_3 ( V_44 ) ;
} while ( ( V_41 & V_45 ) == 0 );
} else {
F_11 ( V_42 , F_3 ( V_42 ) &
~ V_43 ) ;
do {
V_41 = F_3 ( V_44 ) ;
} while ( V_41 & V_45 );
}
}
int F_20 ( struct V_51 * V_52 ,
struct V_69 * V_49 )
{
struct V_3 * V_4 = V_52 -> V_2 -> V_5 ;
struct V_53 * V_53 =
F_18 ( V_52 ) ;
struct V_69 * V_70 =
V_4 -> V_40 . V_71 ;
if ( V_53 -> type == V_72 )
V_70 = V_4 -> V_40 . V_73 ;
if ( V_49 -> V_20 & V_74 )
return V_75 ;
if ( V_49 -> V_20 & V_76 )
return V_77 ;
if ( V_70 ) {
if ( V_49 -> V_78 > V_70 -> V_78 )
return V_79 ;
if ( V_49 -> V_80 > V_70 -> V_80 )
return V_79 ;
}
return V_81 ;
}
bool F_21 ( struct V_47 * V_48 ,
struct V_69 * V_49 ,
struct V_69 * V_82 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 = & V_4 -> V_40 ;
struct V_83 * V_83 =
F_22 ( V_48 -> V_84 ) ;
struct V_47 * V_85 ;
struct V_69 * V_71 = V_40 -> V_71 ;
struct V_53 * V_53 =
F_23 ( V_48 ) ;
if ( V_53 -> type == V_72 )
V_71 = V_40 -> V_73 ;
if ( ! F_24 ( V_2 ) && V_83 -> V_86 == 0 ) {
F_25 ( V_87 L_9 ) ;
return false ;
}
if ( F_24 ( V_2 ) && V_83 -> V_86 != 0 ) {
F_25 ( V_87 L_10 ) ;
return false ;
}
F_26 (tmp_encoder, &dev->mode_config.encoder_list,
head) {
if ( V_85 != V_48
&& V_85 -> V_84 == V_48 -> V_84 ) {
F_25 ( V_87 L_11
L_12 ) ;
return false ;
}
}
if ( V_71 != NULL ) {
V_82 -> V_78 = V_71 -> V_78 ;
V_82 -> V_88 = V_71 -> V_88 ;
V_82 -> V_89 = V_71 -> V_89 ;
V_82 -> V_90 = V_71 -> V_90 ;
V_82 -> V_80 = V_71 -> V_80 ;
V_82 -> V_91 = V_71 -> V_91 ;
V_82 -> V_92 = V_71 -> V_92 ;
V_82 -> V_93 = V_71 -> V_93 ;
V_82 -> clock = V_71 -> clock ;
F_27 ( V_82 ,
V_94 ) ;
}
return true ;
}
static void F_28 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 = & V_4 -> V_40 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_40 -> V_8 = F_3 ( V_7 ) ;
V_40 -> V_46 = ( V_40 -> V_8 &
V_36 ) ;
F_15 ( V_2 , false ) ;
F_4 ( V_2 ) ;
}
static void F_29 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 = & V_4 -> V_40 ;
if ( V_40 -> V_46 == 0 )
V_40 -> V_46 =
F_1 ( V_2 ) ;
F_15 ( V_2 , true ) ;
}
static void F_30 ( struct V_47 * V_48 ,
struct V_69 * V_49 ,
struct V_69 * V_82 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_95 ;
if ( V_49 -> V_78 != V_82 -> V_78 ||
V_49 -> V_80 != V_82 -> V_80 )
V_95 = ( V_96 | V_97 |
V_98 | V_99 |
V_100 ) ;
else
V_95 = 0 ;
if ( V_4 -> V_101 )
V_95 |= V_102 ;
F_11 ( V_66 , V_95 ) ;
}
static enum V_103 F_31 ( struct V_51
* V_52 , bool V_104 )
{
return V_105 ;
}
static int F_32 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_39 * V_40 = & V_4 -> V_40 ;
struct V_53 * V_53 =
F_18 ( V_52 ) ;
struct V_54 * V_55 = V_53 -> V_4 ;
int V_6 = 0 ;
if ( ! F_24 ( V_2 ) )
V_6 = F_33 ( V_52 , & V_55 -> V_106 -> V_29 ) ;
if ( V_6 )
return V_6 ;
V_52 -> V_107 . V_108 = 0 ;
V_52 -> V_107 . V_109 = 200 ;
V_52 -> V_107 . V_110 = 0 ;
V_52 -> V_107 . V_111 = 200 ;
if ( V_40 -> V_71 != NULL ) {
struct V_69 * V_49 =
F_34 ( V_2 , V_40 -> V_71 ) ;
F_35 ( V_52 , V_49 ) ;
return 1 ;
}
return 0 ;
}
void F_36 ( struct V_51 * V_52 )
{
struct V_53 * V_53 =
F_18 ( V_52 ) ;
struct V_54 * V_55 = V_53 -> V_4 ;
if ( V_55 -> V_112 )
F_37 ( V_55 -> V_112 ) ;
F_38 ( V_52 ) ;
F_39 ( V_52 ) ;
F_40 ( V_52 ) ;
}
int F_41 ( struct V_51 * V_52 ,
struct V_113 * V_114 ,
T_3 V_115 )
{
struct V_47 * V_48 = V_52 -> V_48 ;
if ( ! V_48 )
return - 1 ;
if ( ! strcmp ( V_114 -> V_116 , L_13 ) ) {
struct V_83 * V_84 =
F_22 ( V_48 -> V_84 ) ;
T_3 V_117 ;
if ( ! V_84 )
goto V_118;
switch ( V_115 ) {
case V_119 :
break;
case V_120 :
break;
case V_121 :
break;
default:
goto V_118;
}
if ( F_42 ( V_52 ,
V_114 ,
& V_117 ) )
goto V_118;
if ( V_117 == V_115 )
goto V_122;
if ( F_43 ( V_52 ,
V_114 ,
V_115 ) )
goto V_118;
if ( V_84 -> V_123 . V_78 != 0 &&
V_84 -> V_123 . V_80 != 0 ) {
if ( ! F_44 ( V_48 -> V_84 ,
& V_84 -> V_123 ,
V_48 -> V_84 -> V_124 ,
V_48 -> V_84 -> V_125 ,
V_48 -> V_84 -> V_126 ) )
goto V_118;
}
} else if ( ! strcmp ( V_114 -> V_116 , L_14 ) ) {
if ( F_43 ( V_52 ,
V_114 ,
V_115 ) )
goto V_118;
else {
#ifdef F_45
struct V_3 * V_127 =
V_48 -> V_2 -> V_5 ;
struct V_128 * V_129 = V_127 -> V_128 ;
if ( V_129 ) {
V_129 -> V_130 . V_131 = V_115 ;
F_46 ( V_129 ) ;
}
#endif
}
} else if ( ! strcmp ( V_114 -> V_116 , L_15 ) ) {
struct V_132 * V_133
= V_48 -> V_134 ;
V_133 -> V_135 ( V_48 , V_115 ) ;
}
V_122:
return 0 ;
V_118:
return - 1 ;
}
static void F_47 ( struct V_47 * V_48 )
{
F_48 ( V_48 ) ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_53 * V_53 ;
struct V_136 * V_136 ;
struct V_54 * V_55 ;
struct V_51 * V_52 ;
struct V_47 * V_48 ;
struct V_69 * V_137 ;
struct V_138 * V_84 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_139 ;
int V_86 ;
V_53 =
F_50 ( sizeof( struct V_53 ) , V_140 ) ;
if ( ! V_53 ) {
F_5 ( V_2 -> V_2 , L_16 ) ;
return;
}
V_136 =
F_50 ( sizeof( struct V_136 ) , V_140 ) ;
if ( ! V_136 ) {
F_40 ( V_53 ) ;
F_5 ( V_2 -> V_2 , L_17 ) ;
}
V_55 = F_50 ( sizeof( struct V_54 ) , V_140 ) ;
if ( ! V_55 ) {
F_5 ( V_2 -> V_2 , L_18 ) ;
goto V_141;
}
V_53 -> V_4 = V_55 ;
V_52 = & V_136 -> V_142 ;
V_48 = & V_53 -> V_142 ;
F_51 ( V_2 , V_52 ,
& V_143 ,
V_144 ) ;
F_52 ( V_2 , V_48 ,
& V_145 ,
V_146 ) ;
F_53 ( V_136 ,
V_53 ) ;
V_53 -> type = V_147 ;
F_54 ( V_48 , & V_148 ) ;
F_55 ( V_52 ,
& V_149 ) ;
V_52 -> V_107 . V_150 = V_151 ;
V_52 -> V_152 = false ;
V_52 -> V_153 = false ;
F_56 ( V_52 ,
V_2 -> V_154 . V_155 ,
V_119 ) ;
F_56 ( V_52 ,
V_4 -> V_156 ,
V_24 ) ;
V_55 -> V_106 = F_57 ( V_2 , V_157 , L_19 ) ;
if ( ! V_55 -> V_106 ) {
F_58 ( V_87 ,
& V_2 -> V_158 -> V_2 , L_20 ) ;
goto V_159;
}
V_55 -> V_106 -> V_19 = 0x2C ;
V_4 -> V_13 = V_55 -> V_106 ;
V_55 -> V_112 = F_57 ( V_2 , V_160 , L_21 ) ;
if ( ! V_55 -> V_112 ) {
F_58 ( V_87 , & V_2 -> V_158 -> V_2 ,
L_22 L_23 ) ;
goto V_161;
}
F_33 ( V_52 , & V_55 -> V_112 -> V_29 ) ;
F_26 (scan, &connector->probed_modes, head) {
if ( V_137 -> type & V_162 ) {
V_40 -> V_71 =
F_34 ( V_2 , V_137 ) ;
goto V_163;
}
}
if ( V_40 -> V_164 )
V_40 -> V_71 =
F_34 ( V_2 , V_40 -> V_164 ) ;
if ( ! V_40 -> V_71 )
if ( V_4 -> V_165 )
V_40 -> V_71 =
F_34 ( V_2 ,
V_4 -> V_165 ) ;
V_139 = F_3 ( V_61 ) ;
V_86 = ( V_139 & V_166 ) ? 1 : 0 ;
V_84 = F_59 ( V_2 , V_86 ) ;
if ( V_84 && ( V_139 & V_167 ) ) {
V_40 -> V_71 =
F_60 ( V_2 , V_84 ) ;
if ( V_40 -> V_71 ) {
V_40 -> V_71 -> type |=
V_162 ;
goto V_163;
}
}
if ( ! V_40 -> V_71 ) {
F_5 ( V_2 -> V_2 , L_24 ) ;
goto V_168;
}
V_163:
F_61 ( V_52 ) ;
return;
V_168:
if ( V_55 -> V_112 )
F_37 ( V_55 -> V_112 ) ;
V_161:
if ( V_55 -> V_106 )
F_37 ( V_55 -> V_106 ) ;
V_159:
F_48 ( V_48 ) ;
F_39 ( V_52 ) ;
V_141:
if ( V_136 )
F_40 ( V_136 ) ;
}
