static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
F_2 ( V_4 | F_3 ( V_2 -> V_5 + V_3 ) , V_2 -> V_5 + V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
F_2 ( ~ V_4 & F_3 ( V_2 -> V_5 + V_3 ) , V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( void * V_6 )
{
struct V_1 * V_2 = V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
F_7 ( V_10 , L_1 ) ;
if ( F_8 ( ! V_8 || ! V_8 -> V_11 , L_2 ,
F_9 ( V_10 ) ) )
return;
F_10 ( & V_2 -> V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
struct V_14 * V_15 = V_11 -> V_15 ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_2 V_21 = - V_22 ;
int V_23 ;
V_23 = F_12 ( V_19 -> V_9 -> V_10 , V_15 , V_11 -> V_24 ,
V_25 ) ;
if ( V_23 > 0 ) {
V_2 -> V_26 = true ;
V_17 = F_13 ( V_19 , V_15 , V_23 ,
V_27 , V_28 | V_29 ) ;
}
if ( V_17 ) {
V_17 -> V_30 = F_5 ;
V_17 -> V_31 = V_2 ;
V_21 = F_14 ( V_17 ) ;
F_1 ( V_2 , V_32 , V_33 ) ;
F_15 ( V_19 ) ;
}
F_7 ( V_10 , L_3 ,
V_34 , V_11 -> V_24 , V_23 , V_21 ) ;
if ( ! V_17 ) {
if ( V_23 >= 0 )
V_23 = - V_35 ;
V_2 -> V_20 = NULL ;
V_2 -> V_26 = false ;
F_16 ( V_19 ) ;
V_19 = V_2 -> V_36 ;
if ( V_19 ) {
V_2 -> V_36 = NULL ;
F_16 ( V_19 ) ;
}
F_17 ( V_10 ,
L_4 , V_23 ) ;
F_4 ( V_2 , V_32 , V_33 | V_37 ) ;
}
F_7 ( V_10 , L_5 , V_34 ,
V_17 , V_21 , V_11 -> V_24 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
struct V_14 * V_15 = V_11 -> V_15 ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = V_2 -> V_36 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_2 V_21 = - V_22 ;
int V_23 ;
V_23 = F_12 ( V_19 -> V_9 -> V_10 , V_15 , V_11 -> V_24 ,
V_38 ) ;
if ( V_23 > 0 ) {
V_2 -> V_26 = true ;
V_17 = F_13 ( V_19 , V_15 , V_23 ,
V_39 , V_28 | V_29 ) ;
}
if ( V_17 ) {
V_17 -> V_30 = F_5 ;
V_17 -> V_31 = V_2 ;
V_21 = F_14 ( V_17 ) ;
F_1 ( V_2 , V_32 , V_37 ) ;
F_15 ( V_19 ) ;
}
F_7 ( V_10 , L_3 ,
V_34 , V_11 -> V_24 , V_23 , V_21 ) ;
if ( ! V_17 ) {
if ( V_23 >= 0 )
V_23 = - V_35 ;
V_2 -> V_36 = NULL ;
V_2 -> V_26 = false ;
F_16 ( V_19 ) ;
V_19 = V_2 -> V_20 ;
if ( V_19 ) {
V_2 -> V_20 = NULL ;
F_16 ( V_19 ) ;
}
F_17 ( V_10 ,
L_4 , V_23 ) ;
F_4 ( V_2 , V_32 , V_33 | V_37 ) ;
}
F_7 ( V_10 , L_6 , V_34 ,
V_17 , V_21 ) ;
}
static struct V_18 *
F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
enum V_42 V_43 )
{
struct V_44 V_45 = { 0 , } ;
struct V_18 * V_19 ;
void * V_46 = NULL ;
struct V_47 * V_48 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_3 V_49 ;
int V_23 ;
F_20 ( V_49 ) ;
F_21 ( V_50 , V_49 ) ;
if ( V_41 )
V_46 = V_43 == V_39 ?
( void * ) V_41 -> V_51 :
( void * ) V_41 -> V_52 ;
V_19 = F_22 ( V_49 , V_53 ,
V_46 , V_10 ,
V_43 == V_39 ? L_7 : L_8 ) ;
F_7 ( V_10 , L_9 , V_34 ,
V_43 == V_39 ? L_10 : L_11 , V_19 ) ;
if ( ! V_19 )
return NULL ;
V_48 = F_23 ( V_2 -> V_54 , V_55 , 0 ) ;
V_45 . V_43 = V_43 ;
if ( V_43 == V_27 ) {
V_45 . V_56 = V_48 -> V_57 + V_58 ;
V_45 . V_59 = V_60 ;
} else {
V_45 . V_61 = V_48 -> V_57 + V_58 ;
V_45 . V_62 = V_60 ;
}
V_23 = F_24 ( V_19 , & V_45 ) ;
if ( V_23 < 0 ) {
F_16 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
V_2 -> V_26 = false ;
if ( V_41 ) {
if ( V_41 -> V_51 <= 0 || V_41 -> V_52 <= 0 )
return;
} else if ( ! V_10 -> V_63 ) {
return;
}
V_2 -> V_36 = F_19 ( V_2 , V_41 , V_39 ) ;
if ( ! V_2 -> V_36 )
return;
V_2 -> V_20 = F_19 ( V_2 , V_41 , V_27 ) ;
if ( ! V_2 -> V_20 ) {
F_16 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_32 , V_33 | V_37 ) ;
if ( V_2 -> V_36 ) {
struct V_18 * V_19 = V_2 -> V_36 ;
V_2 -> V_36 = NULL ;
F_16 ( V_19 ) ;
}
if ( V_2 -> V_20 ) {
struct V_18 * V_19 = V_2 -> V_20 ;
V_2 -> V_20 = NULL ;
F_16 ( V_19 ) ;
}
V_2 -> V_26 = false ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_64 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_40 * V_65 = V_10 -> V_66 ;
bool V_67 = V_65 ? V_65 -> V_67 : false ;
unsigned int V_68 = F_28 ( V_2 -> V_64 ) ;
unsigned int V_69 ;
F_4 ( V_2 , V_70 , V_71 ) ;
F_4 ( V_2 , V_70 , V_72 ) ;
if ( ! V_64 )
return;
if ( V_2 -> V_73 ) {
unsigned int V_74 , V_75 , V_76 , div , V_77 , V_78 ;
int V_79 ;
V_69 = 0 ;
V_77 = ~ 0 ;
V_75 = 0 ;
for ( V_79 = 31 ; V_79 >= 0 ; V_79 -- ) {
if ( ! ( ( 1 << V_79 ) & V_2 -> V_73 ) )
continue;
div = 1 << ( V_79 + 1 ) ;
V_74 = F_29 ( V_2 -> V_64 , V_64 * div ) ;
V_76 = V_74 / div ;
V_78 = ( V_76 > V_64 ) ? V_76 - V_64 : V_64 - V_76 ;
if ( V_78 <= V_77 ) {
V_75 = V_74 ;
V_69 = V_79 ;
V_77 = V_78 ;
}
}
F_7 ( V_10 , L_12 ,
( V_75 / ( 1 << ( V_69 + 1 ) ) ) , V_64 ,
V_75 , V_69 ) ;
F_30 ( V_2 -> V_64 , V_75 ) ;
V_69 = V_69 << 16 ;
} else if ( V_67 && V_64 == V_68 ) {
V_69 = V_80 ;
} else {
V_69 = ( F_31 ( F_32 ( V_68 , V_64 ) - 1 ) - 1 ) << 16 ;
}
F_1 ( V_2 , V_70 , V_72 & V_69 ) ;
F_1 ( V_2 , V_70 , V_71 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_81 ;
V_81 = 0x010f0000 & F_34 ( V_2 -> V_5 , V_70 ) ;
F_35 ( V_2 -> V_5 , V_82 , V_83 ) ;
F_35 ( V_2 -> V_5 , V_82 , V_84 ) ;
if ( V_2 -> V_85 )
V_81 |= V_86 ;
if ( V_2 -> V_87 )
F_35 ( V_2 -> V_5 , V_88 , 0x0F0F0000 ) ;
F_1 ( V_2 , V_70 , V_81 |
V_89 | V_90 | V_91 ) ;
F_1 ( V_2 , V_32 , V_92 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_93 , V_94 ;
int V_23 , V_95 ;
V_2 -> V_96 = false ;
V_93 = F_34 ( V_2 -> V_5 , V_97 ) ;
V_94 = F_34 ( V_2 -> V_5 , V_98 ) ;
F_7 ( V_10 , L_13 , V_93 ) ;
F_7 ( V_10 , L_14 , V_94 ) ;
if ( V_93 & V_99 ) {
F_1 ( V_2 , V_100 , V_101 ) ;
F_1 ( V_2 , V_100 , ~ V_101 ) ;
for ( V_95 = 10000000 ; V_95 ; V_95 -- ) {
if ( ! ( F_34 ( V_2 -> V_5 , V_97 )
& V_99 ) )
break;
F_37 ( 1 ) ;
}
if ( ! V_95 ) {
F_38 ( V_10 ,
L_15 ) ;
return - V_35 ;
}
F_33 ( V_2 ) ;
F_7 ( V_10 , L_16 ) ;
return - V_35 ;
}
if ( V_94 & V_102 ) {
F_38 ( V_10 , L_17 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
V_23 = - V_35 ;
} else if ( V_94 & V_105 ) {
F_38 ( V_10 , L_18 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
V_23 = - V_106 ;
} else {
F_7 ( V_10 , L_19 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
V_23 = - V_35 ;
}
return V_23 ;
}
static bool F_39 ( struct V_1 * V_2 , T_1 * V_65 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
V_2 -> V_107 += V_2 -> V_108 ;
F_40 ( V_2 -> V_107 > V_11 -> V_15 -> V_109 ) ;
if ( V_2 -> V_107 == V_11 -> V_15 -> V_109 ) {
V_2 -> V_107 = 0 ;
if ( ++ V_2 -> V_110 < V_11 -> V_24 )
V_2 -> V_111 = F_41 ( ++ V_11 -> V_15 ) ;
} else {
V_2 -> V_111 = V_65 ;
}
return V_2 -> V_110 != V_11 -> V_24 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_108 = ( F_34 ( V_2 -> V_5 , V_112 ) &
V_113 ) + 3 ;
V_2 -> V_104 = V_114 ;
F_1 ( V_2 , V_115 , V_116 ) ;
}
static bool F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = F_41 ( V_11 -> V_15 ) ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_36 ( V_2 ) ;
F_7 ( V_10 , L_20 , V_34 , V_11 -> error ) ;
return false ;
}
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
* V_65 ++ = F_34 ( V_2 -> V_5 , V_58 ) ;
F_1 ( V_2 , V_115 , V_117 ) ;
V_2 -> V_104 = V_118 ;
return true ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_24 || ! V_11 -> V_15 -> V_109 )
return;
V_2 -> V_108 = F_34 ( V_2 -> V_5 , V_112 ) &
V_113 ;
V_2 -> V_104 = V_119 ;
V_2 -> V_110 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_111 = F_41 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_115 , V_116 ) ;
}
static bool F_45 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = V_2 -> V_111 ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_36 ( V_2 ) ;
F_7 ( V_10 , L_20 , V_34 , V_11 -> error ) ;
return false ;
}
F_40 ( ! V_11 -> V_15 -> V_109 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
* V_65 ++ = F_34 ( V_2 -> V_5 , V_58 ) ;
if ( ! F_39 ( V_2 , V_65 ) )
return false ;
F_1 ( V_2 , V_115 , V_116 ) ;
return true ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_108 = ( F_34 ( V_2 -> V_5 , V_112 ) &
V_113 ) + 3 ;
V_2 -> V_104 = V_120 ;
F_1 ( V_2 , V_115 , V_121 ) ;
}
static bool F_47 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = F_41 ( V_11 -> V_15 ) ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_36 ( V_2 ) ;
F_7 ( V_10 , L_20 , V_34 , V_11 -> error ) ;
return false ;
}
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
F_35 ( V_2 -> V_5 , V_58 , * V_65 ++ ) ;
F_1 ( V_2 , V_115 , V_122 ) ;
V_2 -> V_104 = V_123 ;
return true ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_24 || ! V_11 -> V_15 -> V_109 )
return;
V_2 -> V_108 = F_34 ( V_2 -> V_5 , V_112 ) &
V_113 ;
V_2 -> V_104 = V_124 ;
V_2 -> V_110 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_111 = F_41 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_115 , V_121 ) ;
}
static bool F_49 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = V_2 -> V_111 ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_36 ( V_2 ) ;
F_7 ( V_10 , L_20 , V_34 , V_11 -> error ) ;
return false ;
}
F_40 ( ! V_11 -> V_15 -> V_109 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
F_35 ( V_2 -> V_5 , V_58 , * V_65 ++ ) ;
if ( ! F_39 ( V_2 , V_65 ) )
return false ;
F_1 ( V_2 , V_115 , V_121 ) ;
return true ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
if ( V_126 -> V_127 & V_128 ) {
V_126 -> V_129 [ 0 ] = F_34 ( V_2 -> V_5 , V_130 ) ;
V_126 -> V_129 [ 1 ] = F_34 ( V_2 -> V_5 , V_131 ) ;
V_126 -> V_129 [ 2 ] = F_34 ( V_2 -> V_5 , V_132 ) ;
V_126 -> V_129 [ 3 ] = F_34 ( V_2 -> V_5 , V_133 ) ;
} else
V_126 -> V_129 [ 0 ] = F_34 ( V_2 -> V_5 , V_133 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
V_126 -> V_129 [ 0 ] = F_34 ( V_2 -> V_5 , V_134 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_8 -> V_11 ;
struct V_125 * V_126 = V_8 -> V_126 ;
T_1 V_135 = V_126 -> V_136 ;
T_1 V_81 = 0 ;
switch ( F_53 ( V_126 ) ) {
case V_137 :
V_81 |= V_138 ;
break;
case V_139 :
case V_140 :
case V_141 :
V_81 |= V_142 ;
break;
case V_143 :
V_81 |= V_144 ;
break;
default:
F_38 ( V_10 , L_21 ) ;
break;
}
switch ( V_135 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_81 |= V_151 ;
break;
}
if ( V_11 ) {
V_81 |= V_152 ;
switch ( V_2 -> V_153 ) {
case V_154 :
V_81 |= V_155 ;
break;
case V_156 :
V_81 |= V_157 ;
break;
case V_158 :
V_81 |= V_159 ;
break;
default:
F_38 ( V_10 , L_22 ) ;
break;
}
switch ( V_2 -> V_160 ) {
case V_161 :
V_81 |= V_162 ;
break;
}
}
if ( V_135 == V_163 || V_135 == V_164 )
V_81 |= V_165 ;
if ( V_135 == V_166 || V_135 == V_164 ) {
V_81 |= V_167 | V_168 ;
F_1 ( V_2 , V_112 ,
V_11 -> V_169 << 16 ) ;
}
if ( V_135 == V_170 || V_135 == V_171 ||
V_135 == V_172 || V_135 == V_173 )
V_81 |= V_174 ;
if ( V_135 == V_170 )
V_81 |= V_175 ;
if ( V_135 == V_171 ||
V_135 == V_172 || V_135 == V_173 )
V_81 |= V_176 ;
return ( V_135 << 24 ) | V_81 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_7 * V_8 , T_1 V_135 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
switch ( V_135 ) {
case V_166 :
F_44 ( V_2 , V_8 ) ;
return 0 ;
case V_164 :
F_48 ( V_2 , V_8 ) ;
return 0 ;
case V_163 :
F_46 ( V_2 , V_8 ) ;
return 0 ;
case V_177 :
case V_178 :
F_42 ( V_2 , V_8 ) ;
return 0 ;
default:
F_38 ( V_10 , L_23 , V_135 ) ;
return - V_22 ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_125 * V_126 = V_8 -> V_126 ;
T_1 V_135 = V_126 -> V_136 ;
T_1 V_49 ;
unsigned long V_127 ;
switch ( V_135 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_49 = V_179 | V_180 ;
break;
default:
V_49 = V_179 | V_181 ;
break;
}
if ( V_2 -> V_85 )
V_49 |= V_182 ;
if ( V_8 -> V_11 ) {
F_35 ( V_2 -> V_5 , V_112 , 0 ) ;
F_35 ( V_2 -> V_5 , V_112 ,
V_8 -> V_11 -> V_183 ) ;
}
V_135 = F_52 ( V_2 , V_8 ) ;
if ( V_2 -> V_85 )
F_35 ( V_2 -> V_5 , V_184 , 0xD80430C0 ) ;
else
F_35 ( V_2 -> V_5 , V_184 , 0xD80430C0 | V_185 ) ;
F_35 ( V_2 -> V_5 , V_115 , V_49 ) ;
F_35 ( V_2 -> V_5 , V_186 , V_126 -> V_6 ) ;
F_56 ( & V_2 -> V_187 , V_127 ) ;
F_35 ( V_2 -> V_5 , V_188 , V_135 ) ;
V_2 -> V_104 = V_189 ;
F_57 ( & V_2 -> V_190 , V_2 -> V_95 ) ;
F_58 ( & V_2 -> V_187 , V_127 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
switch ( V_8 -> V_126 -> V_136 ) {
case V_166 :
F_1 ( V_2 , V_115 , V_191 ) ;
break;
case V_164 :
F_1 ( V_2 , V_115 , V_192 ) ;
break;
default:
F_38 ( V_10 , L_24 ) ;
V_8 -> V_193 -> error = F_36 ( V_2 ) ;
return;
}
V_2 -> V_104 = V_194 ;
}
static void F_60 ( struct V_195 * V_196 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_61 ( V_196 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
unsigned long V_127 ;
F_56 ( & V_2 -> V_187 , V_127 ) ;
if ( V_2 -> V_103 != V_197 ) {
F_7 ( V_10 , L_25 ,
V_34 , V_2 -> V_103 ) ;
F_58 ( & V_2 -> V_187 , V_127 ) ;
V_8 -> V_126 -> error = - V_198 ;
F_62 ( V_196 , V_8 ) ;
return;
}
V_2 -> V_103 = V_199 ;
F_58 ( & V_2 -> V_187 , V_127 ) ;
switch ( V_8 -> V_126 -> V_136 ) {
case V_145 :
case V_178 :
if ( ( V_8 -> V_126 -> V_127 & V_200 ) != V_201 )
break;
case V_202 :
case V_203 :
V_2 -> V_103 = V_197 ;
V_8 -> V_126 -> error = - V_106 ;
F_62 ( V_196 , V_8 ) ;
return;
default:
break;
}
V_2 -> V_8 = V_8 ;
F_55 ( V_2 , V_8 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
if ( V_2 -> V_196 -> V_204 ) {
unsigned int V_204 , V_205 = 0 , V_206 ;
V_204 = V_2 -> V_196 -> V_204 ;
for ( V_206 = V_204 ; V_206 > 2 ; ) {
V_205 = F_29 ( V_2 -> V_64 , V_206 / 2 ) ;
if ( V_205 == V_206 )
break;
V_206 = V_205 ;
}
V_2 -> V_73 = 0x3ff ;
V_2 -> V_196 -> V_204 = V_204 / ( 1 << F_64 ( V_2 -> V_73 ) ) ;
V_2 -> V_196 -> V_205 = V_205 / ( 1 << F_31 ( V_2 -> V_73 ) ) ;
} else {
unsigned int V_64 = F_28 ( V_2 -> V_64 ) ;
V_2 -> V_196 -> V_204 = V_64 / 2 ;
V_2 -> V_196 -> V_205 = V_64 / 512 ;
}
F_7 ( V_10 , L_26 ,
V_2 -> V_196 -> V_204 , V_2 -> V_196 -> V_205 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_207 * V_208 )
{
struct V_195 * V_196 = V_2 -> V_196 ;
if ( ! F_66 ( V_196 -> V_209 . V_210 ) )
F_67 ( V_196 , V_196 -> V_209 . V_210 ,
V_208 -> V_211 ? V_208 -> V_212 : 0 ) ;
}
static void F_68 ( struct V_195 * V_196 , struct V_207 * V_208 )
{
struct V_1 * V_2 = F_61 ( V_196 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
unsigned long V_127 ;
F_56 ( & V_2 -> V_187 , V_127 ) ;
if ( V_2 -> V_103 != V_197 ) {
F_7 ( V_10 , L_25 ,
V_34 , V_2 -> V_103 ) ;
F_58 ( & V_2 -> V_187 , V_127 ) ;
return;
}
V_2 -> V_103 = V_213 ;
F_58 ( & V_2 -> V_187 , V_127 ) ;
if ( V_208 -> V_211 == V_214 ) {
if ( ! V_2 -> V_215 ) {
F_25 ( V_2 , V_10 -> V_66 ) ;
V_2 -> V_215 = true ;
}
F_65 ( V_2 , V_208 ) ;
} else if ( V_208 -> V_211 == V_216 || ! V_208 -> clock ) {
F_27 ( V_2 , 0 ) ;
if ( V_208 -> V_211 == V_216 ) {
if ( V_2 -> V_215 ) {
F_26 ( V_2 ) ;
V_2 -> V_215 = false ;
}
}
if ( V_2 -> V_217 ) {
F_69 ( V_10 ) ;
F_70 ( V_2 -> V_64 ) ;
V_2 -> V_217 = false ;
if ( V_208 -> V_211 == V_216 )
F_65 ( V_2 , V_208 ) ;
}
V_2 -> V_103 = V_197 ;
return;
}
if ( V_208 -> clock ) {
if ( ! V_2 -> V_217 ) {
F_71 ( V_2 -> V_64 ) ;
F_72 ( V_10 ) ;
V_2 -> V_217 = true ;
F_33 ( V_2 ) ;
}
F_27 ( V_2 , V_208 -> clock ) ;
}
V_2 -> V_160 = V_208 -> V_160 ;
V_2 -> V_153 = V_208 -> V_153 ;
V_2 -> V_103 = V_197 ;
}
static int F_73 ( struct V_195 * V_196 )
{
struct V_1 * V_2 = F_61 ( V_196 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_40 * V_65 = V_10 -> V_66 ;
int V_23 = F_74 ( V_196 ) ;
if ( V_23 >= 0 )
return V_23 ;
if ( ! V_65 || ! V_65 -> V_218 )
return - V_219 ;
else
return V_65 -> V_218 ( V_2 -> V_54 ) ;
}
static bool F_75 ( struct V_1 * V_2 )
{
struct V_125 * V_126 = V_2 -> V_8 -> V_126 ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
long time ;
if ( V_2 -> V_96 ) {
switch ( V_126 -> V_136 ) {
case V_171 :
case V_220 :
case V_202 :
V_126 -> error = - V_106 ;
break;
default:
V_126 -> error = F_36 ( V_2 ) ;
break;
}
F_7 ( V_10 , L_27 ,
V_126 -> V_136 , V_126 -> error ) ;
V_2 -> V_96 = false ;
return false ;
}
if ( ! ( V_126 -> V_127 & V_221 ) ) {
V_126 -> error = 0 ;
return false ;
}
F_50 ( V_2 , V_126 ) ;
if ( ! V_11 )
return false ;
F_76 ( & V_2 -> V_12 ) ;
if ( V_11 -> V_127 & V_222 ) {
if ( V_2 -> V_20 )
F_11 ( V_2 ) ;
} else {
if ( V_2 -> V_36 )
F_18 ( V_2 ) ;
}
if ( ! V_2 -> V_26 ) {
V_11 -> error = F_54 ( V_2 , V_2 -> V_8 , V_126 -> V_136 ) ;
return ! V_11 -> error ;
}
time = F_77 ( & V_2 -> V_12 ,
V_2 -> V_95 ) ;
if ( V_11 -> V_127 & V_222 )
F_78 ( V_2 -> V_20 -> V_9 -> V_10 ,
V_11 -> V_15 , V_11 -> V_24 ,
V_25 ) ;
else
F_78 ( V_2 -> V_36 -> V_9 -> V_10 ,
V_11 -> V_15 , V_11 -> V_24 ,
V_38 ) ;
if ( V_2 -> V_96 ) {
F_38 ( V_2 -> V_196 -> V_223 ,
L_28 ) ;
V_11 -> error = F_36 ( V_2 ) ;
} else if ( ! time ) {
F_38 ( V_2 -> V_196 -> V_223 , L_29 ) ;
V_11 -> error = - V_106 ;
} else if ( time < 0 ) {
F_38 ( V_2 -> V_196 -> V_223 ,
L_30 , time ) ;
V_11 -> error = time ;
}
F_4 ( V_2 , V_32 ,
V_33 | V_37 ) ;
V_2 -> V_26 = false ;
if ( V_11 -> error ) {
V_11 -> V_224 = 0 ;
if ( V_11 -> V_127 & V_222 )
F_79 ( V_2 -> V_20 ) ;
else
F_79 ( V_2 -> V_36 ) ;
}
return false ;
}
static T_4 F_80 ( int V_225 , void * V_226 )
{
struct V_1 * V_2 = V_226 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
bool V_227 = false ;
unsigned long V_127 ;
int V_228 ;
F_56 ( & V_2 -> V_187 , V_127 ) ;
V_228 = V_2 -> V_104 ;
F_58 ( & V_2 -> V_187 , V_127 ) ;
F_81 ( & V_2 -> V_190 ) ;
F_82 ( & V_2 -> V_229 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_7 ( V_10 , L_31 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
F_83 ( & V_2 -> V_229 ) ;
return V_230 ;
}
switch ( V_228 ) {
case V_231 :
F_83 ( & V_2 -> V_229 ) ;
return V_230 ;
case V_189 :
V_227 = F_75 ( V_2 ) ;
break;
case V_119 :
V_227 = F_45 ( V_2 ) ;
break;
case V_114 :
V_227 = F_43 ( V_2 ) ;
break;
case V_124 :
V_227 = F_49 ( V_2 ) ;
break;
case V_120 :
V_227 = F_47 ( V_2 ) ;
break;
case V_194 :
if ( V_2 -> V_96 ) {
V_8 -> V_193 -> error = F_36 ( V_2 ) ;
F_7 ( V_10 , L_20 , V_34 , V_8 -> V_193 -> error ) ;
break;
}
F_51 ( V_2 , V_8 -> V_193 ) ;
V_8 -> V_193 -> error = 0 ;
break;
case V_118 :
case V_123 :
if ( V_2 -> V_96 ) {
V_8 -> V_11 -> error = F_36 ( V_2 ) ;
F_7 ( V_10 , L_20 , V_34 , V_8 -> V_11 -> error ) ;
}
break;
default:
F_84 () ;
}
if ( V_227 ) {
F_57 ( & V_2 -> V_190 , V_2 -> V_95 ) ;
F_83 ( & V_2 -> V_229 ) ;
return V_230 ;
}
if ( V_2 -> V_104 != V_194 ) {
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_8 -> V_126 -> error && V_11 && ! V_11 -> error )
V_11 -> V_224 =
V_11 -> V_169 * V_11 -> V_183 ;
if ( V_8 -> V_193 && ! V_8 -> V_126 -> error && ( ! V_11 || ! V_11 -> error ) ) {
F_59 ( V_2 , V_8 ) ;
if ( ! V_8 -> V_193 -> error ) {
F_57 ( & V_2 -> V_190 , V_2 -> V_95 ) ;
F_83 ( & V_2 -> V_229 ) ;
return V_230 ;
}
}
}
V_2 -> V_104 = V_231 ;
V_2 -> V_103 = V_197 ;
V_2 -> V_8 = NULL ;
F_62 ( V_2 -> V_196 , V_8 ) ;
F_83 ( & V_2 -> V_229 ) ;
return V_230 ;
}
static T_4 F_85 ( int V_225 , void * V_226 )
{
struct V_1 * V_2 = V_226 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_103 , V_49 ;
V_103 = F_34 ( V_2 -> V_5 , V_184 ) ;
V_49 = F_34 ( V_2 -> V_5 , V_115 ) ;
if ( V_2 -> V_85 )
F_35 ( V_2 -> V_5 , V_184 , ~ ( V_103 & V_49 ) ) ;
else
F_35 ( V_2 -> V_5 , V_184 , V_185 | ~ ( V_103 & V_49 ) ) ;
F_4 ( V_2 , V_115 , V_103 & V_232 ) ;
if ( V_103 & ~ V_232 )
F_7 ( V_10 , L_32 ,
V_103 ) ;
if ( V_103 & V_233 || V_103 & ~ V_234 ) {
V_2 -> V_96 = true ;
F_7 ( V_10 , L_33 , V_103 ) ;
}
if ( V_103 & ~ ( V_235 | V_236 ) ) {
if ( ! V_2 -> V_8 )
F_7 ( V_10 , L_34 , V_103 ) ;
if ( ! V_2 -> V_26 )
return V_237 ;
else if ( V_2 -> V_96 )
F_5 ( V_2 ) ;
} else {
F_7 ( V_10 , L_35 , V_103 ) ;
}
return V_230 ;
}
static void F_86 ( struct V_238 * V_239 )
{
struct V_240 * V_241 = F_87 ( V_239 , struct V_240 , V_239 ) ;
struct V_1 * V_2 = F_87 ( V_241 , struct V_1 , V_190 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
unsigned long V_127 ;
if ( V_2 -> V_242 )
return;
F_56 ( & V_2 -> V_187 , V_127 ) ;
if ( V_2 -> V_103 == V_197 ) {
F_58 ( & V_2 -> V_187 , V_127 ) ;
return;
}
F_38 ( V_10 , L_36 ,
V_2 -> V_104 , V_8 -> V_126 -> V_136 ) ;
V_2 -> V_103 = V_243 ;
F_58 ( & V_2 -> V_187 , V_127 ) ;
switch ( V_2 -> V_104 ) {
case V_189 :
V_8 -> V_126 -> error = F_36 ( V_2 ) ;
break;
case V_194 :
V_8 -> V_193 -> error = F_36 ( V_2 ) ;
break;
case V_119 :
case V_124 :
case V_114 :
case V_120 :
case V_118 :
case V_123 :
V_8 -> V_11 -> error = F_36 ( V_2 ) ;
break;
default:
F_84 () ;
}
V_2 -> V_103 = V_197 ;
V_2 -> V_104 = V_231 ;
V_2 -> V_8 = NULL ;
F_62 ( V_2 -> V_196 , V_8 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_40 * V_54 = V_10 -> V_66 ;
struct V_195 * V_196 = V_2 -> V_196 ;
F_89 ( V_196 ) ;
if ( ! V_54 )
return;
if ( ! V_196 -> V_244 )
V_196 -> V_244 = V_54 -> V_245 ;
else if ( V_54 -> V_245 )
F_17 ( F_90 ( V_196 ) , L_37 ) ;
}
static int F_91 ( struct V_246 * V_247 )
{
int V_23 = 0 , V_225 [ 2 ] ;
struct V_195 * V_196 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = & V_247 -> V_10 ;
struct V_40 * V_54 = V_10 -> V_66 ;
struct V_47 * V_48 ;
void T_5 * V_3 ;
const char * V_248 ;
V_225 [ 0 ] = F_92 ( V_247 , 0 ) ;
V_225 [ 1 ] = F_92 ( V_247 , 1 ) ;
if ( V_225 [ 0 ] < 0 ) {
F_38 ( V_10 , L_38 ) ;
return - V_249 ;
}
V_48 = F_23 ( V_247 , V_55 , 0 ) ;
V_3 = F_93 ( V_10 , V_48 ) ;
if ( F_66 ( V_3 ) )
return F_94 ( V_3 ) ;
V_196 = F_95 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_196 )
return - V_250 ;
V_23 = F_96 ( V_196 ) ;
if ( V_23 < 0 )
goto V_251;
V_2 = F_61 ( V_196 ) ;
V_2 -> V_196 = V_196 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_95 = F_97 ( 10000 ) ;
V_2 -> V_85 = ! V_54 || ! V_54 -> V_252 ;
V_2 -> V_87 = V_54 && V_54 -> V_253 ;
V_2 -> V_54 = V_247 ;
F_98 ( & V_2 -> V_187 ) ;
V_196 -> V_254 = & V_255 ;
F_88 ( V_2 ) ;
V_196 -> V_256 |= V_257 | V_258 ;
if ( V_54 && V_54 -> V_256 )
V_196 -> V_256 |= V_54 -> V_256 ;
V_196 -> V_259 = 32 ;
V_196 -> V_260 = 512 ;
V_196 -> V_261 = V_262 * V_196 -> V_259 ;
V_196 -> V_263 = V_196 -> V_261 / V_196 -> V_260 ;
V_196 -> V_264 = V_196 -> V_261 ;
F_99 ( V_247 , V_2 ) ;
F_100 ( V_10 ) ;
V_2 -> V_217 = false ;
V_2 -> V_64 = F_101 ( V_10 , NULL ) ;
if ( F_66 ( V_2 -> V_64 ) ) {
V_23 = F_94 ( V_2 -> V_64 ) ;
F_38 ( V_10 , L_39 , V_23 ) ;
goto V_265;
}
V_23 = F_71 ( V_2 -> V_64 ) ;
if ( V_23 < 0 )
goto V_265;
F_63 ( V_2 ) ;
V_23 = F_102 ( V_10 ) ;
if ( V_23 < 0 )
goto V_266;
F_103 ( & V_2 -> V_190 , F_86 ) ;
F_33 ( V_2 ) ;
F_35 ( V_2 -> V_5 , V_115 , V_267 ) ;
V_248 = V_225 [ 1 ] < 0 ? F_9 ( V_10 ) : L_40 ;
V_23 = F_104 ( V_10 , V_225 [ 0 ] , F_85 ,
F_80 , 0 , V_248 , V_2 ) ;
if ( V_23 ) {
F_38 ( V_10 , L_41 , V_248 ) ;
goto V_266;
}
if ( V_225 [ 1 ] >= 0 ) {
V_23 = F_104 ( V_10 , V_225 [ 1 ] ,
F_85 , F_80 ,
0 , L_42 , V_2 ) ;
if ( V_23 ) {
F_38 ( V_10 , L_43 ) ;
goto V_266;
}
}
if ( V_54 && V_54 -> V_268 ) {
V_23 = F_105 ( V_196 , V_54 -> V_269 , 0 ) ;
if ( V_23 < 0 )
goto V_266;
}
F_106 ( & V_2 -> V_229 ) ;
V_23 = F_107 ( V_196 ) ;
if ( V_23 < 0 )
goto V_266;
F_108 ( V_10 , 100 ) ;
F_109 ( V_10 , L_44 ,
F_34 ( V_2 -> V_5 , V_82 ) & 0xffff ,
F_28 ( V_2 -> V_64 ) / 1000000UL ) ;
F_70 ( V_2 -> V_64 ) ;
return V_23 ;
V_266:
F_70 ( V_2 -> V_64 ) ;
V_265:
F_110 ( V_10 ) ;
V_251:
F_111 ( V_196 ) ;
return V_23 ;
}
static int F_112 ( struct V_246 * V_247 )
{
struct V_1 * V_2 = F_113 ( V_247 ) ;
V_2 -> V_242 = true ;
F_71 ( V_2 -> V_64 ) ;
F_72 ( & V_247 -> V_10 ) ;
F_114 ( & V_247 -> V_10 ) ;
F_115 ( V_2 -> V_196 ) ;
F_35 ( V_2 -> V_5 , V_115 , V_267 ) ;
F_81 ( & V_2 -> V_190 ) ;
F_70 ( V_2 -> V_64 ) ;
F_111 ( V_2 -> V_196 ) ;
F_69 ( & V_247 -> V_10 ) ;
F_110 ( & V_247 -> V_10 ) ;
return 0 ;
}
static int F_116 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
F_72 ( V_10 ) ;
F_35 ( V_2 -> V_5 , V_115 , V_267 ) ;
F_118 ( V_10 ) ;
return 0 ;
}
static int F_119 ( struct V_9 * V_10 )
{
return 0 ;
}
