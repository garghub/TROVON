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
F_6 ( & V_2 -> V_9 -> V_10 , L_1 ) ;
if ( F_7 ( ! V_8 || ! V_8 -> V_11 , L_2 ,
F_8 ( & V_2 -> V_9 -> V_10 ) ) )
return;
F_9 ( & V_2 -> V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
struct V_14 * V_15 = V_11 -> V_15 ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = V_2 -> V_20 ;
T_2 V_21 = - V_22 ;
int V_23 ;
V_23 = F_11 ( V_19 -> V_24 -> V_10 , V_15 , V_11 -> V_25 ,
V_26 ) ;
if ( V_23 > 0 ) {
V_2 -> V_27 = true ;
V_17 = F_12 ( V_19 , V_15 , V_23 ,
V_28 , V_29 | V_30 ) ;
}
if ( V_17 ) {
V_17 -> V_31 = F_5 ;
V_17 -> V_32 = V_2 ;
V_21 = F_13 ( V_17 ) ;
F_1 ( V_2 , V_33 , V_34 ) ;
F_14 ( V_19 ) ;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_3 ,
V_35 , V_11 -> V_25 , V_23 , V_21 ) ;
if ( ! V_17 ) {
if ( V_23 >= 0 )
V_23 = - V_36 ;
V_2 -> V_20 = NULL ;
V_2 -> V_27 = false ;
F_15 ( V_19 ) ;
V_19 = V_2 -> V_37 ;
if ( V_19 ) {
V_2 -> V_37 = NULL ;
F_15 ( V_19 ) ;
}
F_16 ( & V_2 -> V_9 -> V_10 ,
L_4 , V_23 ) ;
F_4 ( V_2 , V_33 , V_34 | V_38 ) ;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_5 , V_35 ,
V_17 , V_21 , V_11 -> V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
struct V_14 * V_15 = V_11 -> V_15 ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = V_2 -> V_37 ;
T_2 V_21 = - V_22 ;
int V_23 ;
V_23 = F_11 ( V_19 -> V_24 -> V_10 , V_15 , V_11 -> V_25 ,
V_39 ) ;
if ( V_23 > 0 ) {
V_2 -> V_27 = true ;
V_17 = F_12 ( V_19 , V_15 , V_23 ,
V_40 , V_29 | V_30 ) ;
}
if ( V_17 ) {
V_17 -> V_31 = F_5 ;
V_17 -> V_32 = V_2 ;
V_21 = F_13 ( V_17 ) ;
F_1 ( V_2 , V_33 , V_38 ) ;
F_14 ( V_19 ) ;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_3 ,
V_35 , V_11 -> V_25 , V_23 , V_21 ) ;
if ( ! V_17 ) {
if ( V_23 >= 0 )
V_23 = - V_36 ;
V_2 -> V_37 = NULL ;
V_2 -> V_27 = false ;
F_15 ( V_19 ) ;
V_19 = V_2 -> V_20 ;
if ( V_19 ) {
V_2 -> V_20 = NULL ;
F_15 ( V_19 ) ;
}
F_16 ( & V_2 -> V_9 -> V_10 ,
L_4 , V_23 ) ;
F_4 ( V_2 , V_33 , V_34 | V_38 ) ;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_6 , V_35 ,
V_17 , V_21 ) ;
}
static struct V_18 *
F_18 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
enum V_43 V_44 )
{
struct V_45 V_46 = { 0 , } ;
struct V_18 * V_19 ;
void * V_47 = NULL ;
struct V_48 * V_49 ;
T_3 V_50 ;
int V_23 ;
F_19 ( V_50 ) ;
F_20 ( V_51 , V_50 ) ;
if ( V_42 )
V_47 = V_44 == V_40 ?
( void * ) V_42 -> V_52 :
( void * ) V_42 -> V_53 ;
V_19 = F_21 ( V_50 , V_54 ,
V_47 , & V_2 -> V_9 -> V_10 ,
V_44 == V_40 ? L_7 : L_8 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_9 , V_35 ,
V_44 == V_40 ? L_10 : L_11 , V_19 ) ;
if ( ! V_19 )
return NULL ;
V_49 = F_22 ( V_2 -> V_9 , V_55 , 0 ) ;
V_46 . V_44 = V_44 ;
if ( V_44 == V_28 ) {
V_46 . V_56 = V_49 -> V_57 + V_58 ;
V_46 . V_59 = V_60 ;
} else {
V_46 . V_61 = V_49 -> V_57 + V_58 ;
V_46 . V_62 = V_60 ;
}
V_23 = F_23 ( V_19 , & V_46 ) ;
if ( V_23 < 0 ) {
F_15 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
V_2 -> V_27 = false ;
if ( V_42 ) {
if ( V_42 -> V_52 <= 0 || V_42 -> V_53 <= 0 )
return;
} else if ( ! V_2 -> V_9 -> V_10 . V_63 ) {
return;
}
V_2 -> V_37 = F_18 ( V_2 , V_42 , V_40 ) ;
if ( ! V_2 -> V_37 )
return;
V_2 -> V_20 = F_18 ( V_2 , V_42 , V_28 ) ;
if ( ! V_2 -> V_20 ) {
F_15 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_33 , V_34 | V_38 ) ;
if ( V_2 -> V_37 ) {
struct V_18 * V_19 = V_2 -> V_37 ;
V_2 -> V_37 = NULL ;
F_15 ( V_19 ) ;
}
if ( V_2 -> V_20 ) {
struct V_18 * V_19 = V_2 -> V_20 ;
V_2 -> V_20 = NULL ;
F_15 ( V_19 ) ;
}
V_2 -> V_27 = false ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_64 )
{
struct V_41 * V_65 = V_2 -> V_9 -> V_10 . V_66 ;
bool V_67 = V_65 ? V_65 -> V_67 : false ;
F_4 ( V_2 , V_68 , V_69 ) ;
F_4 ( V_2 , V_68 , V_70 ) ;
if ( ! V_64 )
return;
if ( V_67 && V_64 == V_2 -> V_64 )
F_1 ( V_2 , V_68 , V_71 ) ;
else
F_1 ( V_2 , V_68 , V_70 &
( ( F_27 ( F_28 ( V_2 -> V_64 ,
V_64 ) - 1 ) - 1 ) << 16 ) ) ;
F_1 ( V_2 , V_68 , V_69 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_72 ;
V_72 = 0x010f0000 & F_30 ( V_2 -> V_5 , V_68 ) ;
F_31 ( V_2 -> V_5 , V_73 , V_74 ) ;
F_31 ( V_2 -> V_5 , V_73 , V_75 ) ;
if ( V_2 -> V_76 )
V_72 |= V_77 ;
if ( V_2 -> V_78 )
F_31 ( V_2 -> V_5 , V_79 , 0x0F0F0000 ) ;
F_1 ( V_2 , V_68 , V_72 |
V_80 | V_81 | V_82 ) ;
F_1 ( V_2 , V_33 , V_83 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_84 , V_85 ;
int V_23 , V_86 ;
V_2 -> V_87 = false ;
V_84 = F_30 ( V_2 -> V_5 , V_88 ) ;
V_85 = F_30 ( V_2 -> V_5 , V_89 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_12 , V_84 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_13 , V_85 ) ;
if ( V_84 & V_90 ) {
F_1 ( V_2 , V_91 , V_92 ) ;
F_1 ( V_2 , V_91 , ~ V_92 ) ;
for ( V_86 = 10000000 ; V_86 ; V_86 -- ) {
if ( ! ( F_30 ( V_2 -> V_5 , V_88 )
& V_90 ) )
break;
F_33 ( 1 ) ;
}
if ( ! V_86 ) {
F_34 ( & V_2 -> V_9 -> V_10 ,
L_14 ) ;
return - V_36 ;
}
F_29 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_15 ) ;
return - V_36 ;
}
if ( V_85 & V_93 ) {
F_34 ( & V_2 -> V_9 -> V_10 , L_16 ,
V_2 -> V_94 , V_2 -> V_95 ) ;
V_23 = - V_36 ;
} else if ( V_85 & V_96 ) {
F_34 ( & V_2 -> V_9 -> V_10 , L_17 ,
V_2 -> V_94 , V_2 -> V_95 ) ;
V_23 = - V_97 ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_18 ,
V_2 -> V_94 , V_2 -> V_95 ) ;
V_23 = - V_36 ;
}
return V_23 ;
}
static bool F_35 ( struct V_1 * V_2 , T_1 * V_65 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
V_2 -> V_98 += V_2 -> V_99 ;
F_36 ( V_2 -> V_98 > V_11 -> V_15 -> V_100 ) ;
if ( V_2 -> V_98 == V_11 -> V_15 -> V_100 ) {
V_2 -> V_98 = 0 ;
if ( ++ V_2 -> V_101 < V_11 -> V_25 )
V_2 -> V_102 = F_37 ( ++ V_11 -> V_15 ) ;
} else {
V_2 -> V_102 = V_65 ;
}
return V_2 -> V_101 != V_11 -> V_25 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_99 = ( F_30 ( V_2 -> V_5 , V_103 ) &
V_104 ) + 3 ;
V_2 -> V_95 = V_105 ;
F_1 ( V_2 , V_106 , V_107 ) ;
}
static bool F_39 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = F_37 ( V_11 -> V_15 ) ;
int V_108 ;
if ( V_2 -> V_87 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_108 = 0 ; V_108 < V_2 -> V_99 / 4 ; V_108 ++ )
* V_65 ++ = F_30 ( V_2 -> V_5 , V_58 ) ;
F_1 ( V_2 , V_106 , V_109 ) ;
V_2 -> V_95 = V_110 ;
return true ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_100 )
return;
V_2 -> V_99 = F_30 ( V_2 -> V_5 , V_103 ) &
V_104 ;
V_2 -> V_95 = V_111 ;
V_2 -> V_101 = 0 ;
V_2 -> V_98 = 0 ;
V_2 -> V_102 = F_37 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_106 , V_107 ) ;
}
static bool F_41 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = V_2 -> V_102 ;
int V_108 ;
if ( V_2 -> V_87 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
F_36 ( ! V_11 -> V_15 -> V_100 ) ;
for ( V_108 = 0 ; V_108 < V_2 -> V_99 / 4 ; V_108 ++ )
* V_65 ++ = F_30 ( V_2 -> V_5 , V_58 ) ;
if ( ! F_35 ( V_2 , V_65 ) )
return false ;
F_1 ( V_2 , V_106 , V_107 ) ;
return true ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_99 = ( F_30 ( V_2 -> V_5 , V_103 ) &
V_104 ) + 3 ;
V_2 -> V_95 = V_112 ;
F_1 ( V_2 , V_106 , V_113 ) ;
}
static bool F_43 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = F_37 ( V_11 -> V_15 ) ;
int V_108 ;
if ( V_2 -> V_87 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_108 = 0 ; V_108 < V_2 -> V_99 / 4 ; V_108 ++ )
F_31 ( V_2 -> V_5 , V_58 , * V_65 ++ ) ;
F_1 ( V_2 , V_106 , V_114 ) ;
V_2 -> V_95 = V_115 ;
return true ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_100 )
return;
V_2 -> V_99 = F_30 ( V_2 -> V_5 , V_103 ) &
V_104 ;
V_2 -> V_95 = V_116 ;
V_2 -> V_101 = 0 ;
V_2 -> V_98 = 0 ;
V_2 -> V_102 = F_37 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_106 , V_113 ) ;
}
static bool F_45 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_65 = V_2 -> V_102 ;
int V_108 ;
if ( V_2 -> V_87 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
F_36 ( ! V_11 -> V_15 -> V_100 ) ;
for ( V_108 = 0 ; V_108 < V_2 -> V_99 / 4 ; V_108 ++ )
F_31 ( V_2 -> V_5 , V_58 , * V_65 ++ ) ;
if ( ! F_35 ( V_2 , V_65 ) )
return false ;
F_1 ( V_2 , V_106 , V_113 ) ;
return true ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
if ( V_118 -> V_119 & V_120 ) {
V_118 -> V_121 [ 0 ] = F_30 ( V_2 -> V_5 , V_122 ) ;
V_118 -> V_121 [ 1 ] = F_30 ( V_2 -> V_5 , V_123 ) ;
V_118 -> V_121 [ 2 ] = F_30 ( V_2 -> V_5 , V_124 ) ;
V_118 -> V_121 [ 3 ] = F_30 ( V_2 -> V_5 , V_125 ) ;
} else
V_118 -> V_121 [ 0 ] = F_30 ( V_2 -> V_5 , V_125 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
V_118 -> V_121 [ 0 ] = F_30 ( V_2 -> V_5 , V_126 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
struct V_117 * V_118 = V_8 -> V_118 ;
T_1 V_127 = V_118 -> V_128 ;
T_1 V_72 = 0 ;
switch ( F_49 ( V_118 ) ) {
case V_129 :
V_72 |= V_130 ;
break;
case V_131 :
case V_132 :
case V_133 :
V_72 |= V_134 ;
break;
case V_135 :
V_72 |= V_136 ;
break;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_20 ) ;
break;
}
switch ( V_127 ) {
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
V_72 |= V_143 ;
break;
}
if ( V_11 ) {
V_72 |= V_144 ;
switch ( V_2 -> V_145 ) {
case V_146 :
V_72 |= V_147 ;
break;
case V_148 :
V_72 |= V_149 ;
break;
case V_150 :
V_72 |= V_151 ;
break;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_21 ) ;
break;
}
switch ( V_2 -> V_152 ) {
case V_153 :
V_72 |= V_154 ;
break;
}
}
if ( V_127 == V_155 || V_127 == V_156 )
V_72 |= V_157 ;
if ( V_127 == V_158 || V_127 == V_156 ) {
V_72 |= V_159 | V_160 ;
F_1 ( V_2 , V_103 ,
V_11 -> V_161 << 16 ) ;
}
if ( V_127 == V_162 || V_127 == V_163 ||
V_127 == V_164 || V_127 == V_165 )
V_72 |= V_166 ;
if ( V_127 == V_162 )
V_72 |= V_167 ;
if ( V_127 == V_163 ||
V_127 == V_164 || V_127 == V_165 )
V_72 |= V_168 ;
return ( V_127 << 24 ) | V_72 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 , T_1 V_127 )
{
switch ( V_127 ) {
case V_158 :
F_40 ( V_2 , V_8 ) ;
return 0 ;
case V_156 :
F_44 ( V_2 , V_8 ) ;
return 0 ;
case V_155 :
F_42 ( V_2 , V_8 ) ;
return 0 ;
case V_169 :
case V_170 :
F_38 ( V_2 , V_8 ) ;
return 0 ;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_22 , V_127 ) ;
return - V_22 ;
}
}
static void F_51 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_117 * V_118 = V_8 -> V_118 ;
T_1 V_127 = V_118 -> V_128 ;
T_1 V_50 ;
unsigned long V_119 ;
switch ( V_127 ) {
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
V_50 = V_171 | V_172 ;
break;
default:
V_50 = V_171 | V_173 ;
break;
}
if ( V_2 -> V_76 )
V_50 |= V_174 ;
if ( V_8 -> V_11 ) {
F_31 ( V_2 -> V_5 , V_103 , 0 ) ;
F_31 ( V_2 -> V_5 , V_103 ,
V_8 -> V_11 -> V_175 ) ;
}
V_127 = F_48 ( V_2 , V_8 ) ;
if ( V_2 -> V_76 )
F_31 ( V_2 -> V_5 , V_176 , 0xD80430C0 ) ;
else
F_31 ( V_2 -> V_5 , V_176 , 0xD80430C0 | V_177 ) ;
F_31 ( V_2 -> V_5 , V_106 , V_50 ) ;
F_31 ( V_2 -> V_5 , V_178 , V_118 -> V_6 ) ;
F_52 ( & V_2 -> V_179 , V_119 ) ;
F_31 ( V_2 -> V_5 , V_180 , V_127 ) ;
V_2 -> V_95 = V_181 ;
F_53 ( & V_2 -> V_182 , V_2 -> V_86 ) ;
F_54 ( & V_2 -> V_179 , V_119 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
switch ( V_8 -> V_118 -> V_128 ) {
case V_158 :
F_1 ( V_2 , V_106 , V_183 ) ;
break;
case V_156 :
F_1 ( V_2 , V_106 , V_184 ) ;
break;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_23 ) ;
V_8 -> V_185 -> error = F_32 ( V_2 ) ;
return;
}
V_2 -> V_95 = V_186 ;
}
static void F_56 ( struct V_187 * V_188 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_57 ( V_188 ) ;
unsigned long V_119 ;
F_52 ( & V_2 -> V_179 , V_119 ) ;
if ( V_2 -> V_94 != V_189 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_24 , V_35 , V_2 -> V_94 ) ;
F_54 ( & V_2 -> V_179 , V_119 ) ;
V_8 -> V_118 -> error = - V_190 ;
F_58 ( V_188 , V_8 ) ;
return;
}
V_2 -> V_94 = V_191 ;
F_54 ( & V_2 -> V_179 , V_119 ) ;
switch ( V_8 -> V_118 -> V_128 ) {
case V_137 :
case V_170 :
if ( ( V_8 -> V_118 -> V_119 & V_192 ) != V_193 )
break;
case V_194 :
case V_195 :
V_2 -> V_94 = V_189 ;
V_8 -> V_118 -> error = - V_97 ;
F_58 ( V_188 , V_8 ) ;
return;
default:
break;
}
V_2 -> V_8 = V_8 ;
F_51 ( V_2 , V_8 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_23 = F_60 ( V_2 -> V_196 ) ;
if ( ! V_23 ) {
V_2 -> V_64 = F_61 ( V_2 -> V_196 ) ;
V_2 -> V_188 -> V_197 = V_2 -> V_64 / 2 ;
V_2 -> V_188 -> V_198 = V_2 -> V_64 / 512 ;
}
return V_23 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_199 * V_200 )
{
struct V_187 * V_188 = V_2 -> V_188 ;
if ( ! F_63 ( V_188 -> V_201 . V_202 ) )
F_64 ( V_188 , V_188 -> V_201 . V_202 ,
V_200 -> V_203 ? V_200 -> V_204 : 0 ) ;
}
static void F_65 ( struct V_187 * V_188 , struct V_199 * V_200 )
{
struct V_1 * V_2 = F_57 ( V_188 ) ;
unsigned long V_119 ;
F_52 ( & V_2 -> V_179 , V_119 ) ;
if ( V_2 -> V_94 != V_189 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_24 , V_35 , V_2 -> V_94 ) ;
F_54 ( & V_2 -> V_179 , V_119 ) ;
return;
}
V_2 -> V_94 = V_205 ;
F_54 ( & V_2 -> V_179 , V_119 ) ;
if ( V_200 -> V_203 == V_206 ) {
if ( ! V_2 -> V_207 ) {
F_24 ( V_2 , V_2 -> V_9 -> V_10 . V_66 ) ;
V_2 -> V_207 = true ;
}
F_62 ( V_2 , V_200 ) ;
} else if ( V_200 -> V_203 == V_208 || ! V_200 -> clock ) {
F_26 ( V_2 , 0 ) ;
if ( V_200 -> V_203 == V_208 ) {
if ( V_2 -> V_207 ) {
F_25 ( V_2 ) ;
V_2 -> V_207 = false ;
}
}
if ( V_2 -> V_209 ) {
F_66 ( & V_2 -> V_9 -> V_10 ) ;
F_67 ( V_2 -> V_196 ) ;
V_2 -> V_209 = false ;
if ( V_200 -> V_203 == V_208 )
F_62 ( V_2 , V_200 ) ;
}
V_2 -> V_94 = V_189 ;
return;
}
if ( V_200 -> clock ) {
if ( ! V_2 -> V_209 ) {
F_59 ( V_2 ) ;
F_68 ( & V_2 -> V_9 -> V_10 ) ;
V_2 -> V_209 = true ;
F_29 ( V_2 ) ;
}
F_26 ( V_2 , V_200 -> clock ) ;
}
V_2 -> V_152 = V_200 -> V_152 ;
V_2 -> V_145 = V_200 -> V_145 ;
V_2 -> V_94 = V_189 ;
}
static int F_69 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_57 ( V_188 ) ;
struct V_41 * V_65 = V_2 -> V_9 -> V_10 . V_66 ;
int V_23 = F_70 ( V_188 ) ;
if ( V_23 >= 0 )
return V_23 ;
if ( ! V_65 || ! V_65 -> V_210 )
return - V_211 ;
else
return V_65 -> V_210 ( V_2 -> V_9 ) ;
}
static bool F_71 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = V_2 -> V_8 -> V_118 ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
long time ;
if ( V_2 -> V_87 ) {
switch ( V_118 -> V_128 ) {
case V_163 :
case V_212 :
case V_194 :
V_118 -> error = - V_97 ;
break;
default:
V_118 -> error = F_32 ( V_2 ) ;
break;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_25 ,
V_118 -> V_128 , V_118 -> error ) ;
V_2 -> V_87 = false ;
return false ;
}
if ( ! ( V_118 -> V_119 & V_213 ) ) {
V_118 -> error = 0 ;
return false ;
}
F_46 ( V_2 , V_118 ) ;
if ( ! V_11 )
return false ;
F_72 ( & V_2 -> V_12 ) ;
if ( V_11 -> V_119 & V_214 ) {
if ( V_2 -> V_20 )
F_10 ( V_2 ) ;
} else {
if ( V_2 -> V_37 )
F_17 ( V_2 ) ;
}
if ( ! V_2 -> V_27 ) {
V_11 -> error = F_50 ( V_2 , V_2 -> V_8 , V_118 -> V_128 ) ;
return ! V_11 -> error ;
}
time = F_73 ( & V_2 -> V_12 ,
V_2 -> V_86 ) ;
if ( V_11 -> V_119 & V_214 )
F_74 ( V_2 -> V_20 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_26 ) ;
else
F_74 ( V_2 -> V_37 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_39 ) ;
if ( V_2 -> V_87 ) {
F_34 ( V_2 -> V_188 -> V_215 ,
L_26 ) ;
V_11 -> error = F_32 ( V_2 ) ;
} else if ( ! time ) {
F_34 ( V_2 -> V_188 -> V_215 , L_27 ) ;
V_11 -> error = - V_97 ;
} else if ( time < 0 ) {
F_34 ( V_2 -> V_188 -> V_215 ,
L_28 , time ) ;
V_11 -> error = time ;
}
F_4 ( V_2 , V_33 ,
V_34 | V_38 ) ;
V_2 -> V_27 = false ;
if ( V_11 -> error ) {
V_11 -> V_216 = 0 ;
if ( V_11 -> V_119 & V_214 )
F_75 ( V_2 -> V_20 ) ;
else
F_75 ( V_2 -> V_37 ) ;
}
return false ;
}
static T_4 F_76 ( int V_217 , void * V_218 )
{
struct V_1 * V_2 = V_218 ;
struct V_7 * V_8 ;
bool V_219 = false ;
unsigned long V_119 ;
int V_220 ;
F_52 ( & V_2 -> V_179 , V_119 ) ;
V_220 = V_2 -> V_95 ;
F_54 ( & V_2 -> V_179 , V_119 ) ;
F_77 ( & V_2 -> V_182 ) ;
F_78 ( & V_2 -> V_221 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_29 ,
V_2 -> V_94 , V_2 -> V_95 ) ;
F_79 ( & V_2 -> V_221 ) ;
return V_222 ;
}
switch ( V_220 ) {
case V_223 :
F_79 ( & V_2 -> V_221 ) ;
return V_222 ;
case V_181 :
V_219 = F_71 ( V_2 ) ;
break;
case V_111 :
V_219 = F_41 ( V_2 ) ;
break;
case V_105 :
V_219 = F_39 ( V_2 ) ;
break;
case V_116 :
V_219 = F_45 ( V_2 ) ;
break;
case V_112 :
V_219 = F_43 ( V_2 ) ;
break;
case V_186 :
if ( V_2 -> V_87 ) {
V_8 -> V_185 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_8 -> V_185 -> error ) ;
break;
}
F_47 ( V_2 , V_8 -> V_185 ) ;
V_8 -> V_185 -> error = 0 ;
break;
case V_110 :
case V_115 :
if ( V_2 -> V_87 ) {
V_8 -> V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_8 -> V_11 -> error ) ;
}
break;
default:
F_80 () ;
}
if ( V_219 ) {
F_53 ( & V_2 -> V_182 , V_2 -> V_86 ) ;
F_79 ( & V_2 -> V_221 ) ;
return V_222 ;
}
if ( V_2 -> V_95 != V_186 ) {
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_8 -> V_118 -> error && V_11 && ! V_11 -> error )
V_11 -> V_216 =
V_11 -> V_161 * V_11 -> V_175 ;
if ( V_8 -> V_185 && ! V_8 -> V_118 -> error && ( ! V_11 || ! V_11 -> error ) ) {
F_55 ( V_2 , V_8 ) ;
if ( ! V_8 -> V_185 -> error ) {
F_53 ( & V_2 -> V_182 , V_2 -> V_86 ) ;
F_79 ( & V_2 -> V_221 ) ;
return V_222 ;
}
}
}
V_2 -> V_95 = V_223 ;
V_2 -> V_94 = V_189 ;
V_2 -> V_8 = NULL ;
F_58 ( V_2 -> V_188 , V_8 ) ;
F_79 ( & V_2 -> V_221 ) ;
return V_222 ;
}
static T_4 F_81 ( int V_217 , void * V_218 )
{
struct V_1 * V_2 = V_218 ;
T_1 V_94 , V_50 ;
V_94 = F_30 ( V_2 -> V_5 , V_176 ) ;
V_50 = F_30 ( V_2 -> V_5 , V_106 ) ;
if ( V_2 -> V_76 )
F_31 ( V_2 -> V_5 , V_176 , ~ ( V_94 & V_50 ) ) ;
else
F_31 ( V_2 -> V_5 , V_176 , V_177 | ~ ( V_94 & V_50 ) ) ;
F_4 ( V_2 , V_106 , V_94 & V_224 ) ;
if ( V_94 & ~ V_224 )
F_6 ( & V_2 -> V_9 -> V_10 , L_30 ,
V_94 ) ;
if ( V_94 & V_225 || V_94 & ~ V_226 ) {
V_2 -> V_87 = true ;
F_6 ( & V_2 -> V_9 -> V_10 , L_31 , V_94 ) ;
}
if ( V_94 & ~ ( V_227 | V_228 ) ) {
if ( ! V_2 -> V_8 )
F_6 ( & V_2 -> V_9 -> V_10 , L_32 , V_94 ) ;
if ( ! V_2 -> V_27 )
return V_229 ;
else if ( V_2 -> V_87 )
F_5 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_33 , V_94 ) ;
}
return V_222 ;
}
static void F_82 ( struct V_230 * V_231 )
{
struct V_232 * V_233 = F_83 ( V_231 , struct V_232 , V_231 ) ;
struct V_1 * V_2 = F_83 ( V_233 , struct V_1 , V_182 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_119 ;
if ( V_2 -> V_234 )
return;
F_52 ( & V_2 -> V_179 , V_119 ) ;
if ( V_2 -> V_94 == V_189 ) {
F_54 ( & V_2 -> V_179 , V_119 ) ;
return;
}
F_34 ( & V_2 -> V_9 -> V_10 , L_34 ,
V_2 -> V_95 , V_8 -> V_118 -> V_128 ) ;
V_2 -> V_94 = V_235 ;
F_54 ( & V_2 -> V_179 , V_119 ) ;
switch ( V_2 -> V_95 ) {
case V_181 :
V_8 -> V_118 -> error = F_32 ( V_2 ) ;
break;
case V_186 :
V_8 -> V_185 -> error = F_32 ( V_2 ) ;
break;
case V_111 :
case V_116 :
case V_105 :
case V_112 :
case V_110 :
case V_115 :
V_8 -> V_11 -> error = F_32 ( V_2 ) ;
break;
default:
F_80 () ;
}
V_2 -> V_94 = V_189 ;
V_2 -> V_95 = V_223 ;
V_2 -> V_8 = NULL ;
F_58 ( V_2 -> V_188 , V_8 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_41 * V_9 = V_2 -> V_9 -> V_10 . V_66 ;
struct V_187 * V_188 = V_2 -> V_188 ;
F_85 ( V_188 ) ;
if ( ! V_9 )
return;
if ( ! V_188 -> V_236 )
V_188 -> V_236 = V_9 -> V_237 ;
else if ( V_9 -> V_237 )
F_16 ( F_86 ( V_188 ) , L_35 ) ;
}
static int F_87 ( struct V_238 * V_239 )
{
int V_23 = 0 , V_217 [ 2 ] ;
struct V_187 * V_188 ;
struct V_1 * V_2 ;
struct V_41 * V_9 = V_239 -> V_10 . V_66 ;
struct V_48 * V_49 ;
void T_5 * V_3 ;
const char * V_240 ;
V_217 [ 0 ] = F_88 ( V_239 , 0 ) ;
V_217 [ 1 ] = F_88 ( V_239 , 1 ) ;
if ( V_217 [ 0 ] < 0 ) {
F_34 ( & V_239 -> V_10 , L_36 ) ;
return - V_241 ;
}
V_49 = F_22 ( V_239 , V_55 , 0 ) ;
V_3 = F_89 ( & V_239 -> V_10 , V_49 ) ;
if ( F_63 ( V_3 ) )
return F_90 ( V_3 ) ;
V_188 = F_91 ( sizeof( struct V_1 ) , & V_239 -> V_10 ) ;
if ( ! V_188 )
return - V_242 ;
V_23 = F_92 ( V_188 ) ;
if ( V_23 < 0 )
goto V_243;
V_2 = F_57 ( V_188 ) ;
V_2 -> V_188 = V_188 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_86 = F_93 ( 10000 ) ;
V_2 -> V_76 = ! V_9 || ! V_9 -> V_244 ;
V_2 -> V_78 = V_9 && V_9 -> V_245 ;
V_2 -> V_9 = V_239 ;
F_94 ( & V_2 -> V_179 ) ;
V_188 -> V_246 = & V_247 ;
F_84 ( V_2 ) ;
V_188 -> V_248 |= V_249 | V_250 ;
if ( V_9 && V_9 -> V_248 )
V_188 -> V_248 |= V_9 -> V_248 ;
V_188 -> V_251 = 32 ;
V_188 -> V_252 = 512 ;
V_188 -> V_253 = V_254 * V_188 -> V_251 ;
V_188 -> V_255 = V_188 -> V_253 / V_188 -> V_252 ;
V_188 -> V_256 = V_188 -> V_253 ;
F_95 ( V_239 , V_2 ) ;
F_96 ( & V_239 -> V_10 ) ;
V_2 -> V_209 = false ;
V_2 -> V_196 = F_97 ( & V_239 -> V_10 , NULL ) ;
if ( F_63 ( V_2 -> V_196 ) ) {
V_23 = F_90 ( V_2 -> V_196 ) ;
F_34 ( & V_239 -> V_10 , L_37 , V_23 ) ;
goto V_257;
}
V_23 = F_59 ( V_2 ) ;
if ( V_23 < 0 )
goto V_257;
V_23 = F_98 ( & V_239 -> V_10 ) ;
if ( V_23 < 0 )
goto V_258;
F_99 ( & V_2 -> V_182 , F_82 ) ;
F_29 ( V_2 ) ;
F_31 ( V_2 -> V_5 , V_106 , V_259 ) ;
V_240 = V_217 [ 1 ] < 0 ? F_8 ( & V_239 -> V_10 ) : L_38 ;
V_23 = F_100 ( & V_239 -> V_10 , V_217 [ 0 ] , F_81 ,
F_76 , 0 , V_240 , V_2 ) ;
if ( V_23 ) {
F_34 ( & V_239 -> V_10 , L_39 , V_240 ) ;
goto V_258;
}
if ( V_217 [ 1 ] >= 0 ) {
V_23 = F_100 ( & V_239 -> V_10 , V_217 [ 1 ] ,
F_81 , F_76 ,
0 , L_40 , V_2 ) ;
if ( V_23 ) {
F_34 ( & V_239 -> V_10 , L_41 ) ;
goto V_258;
}
}
if ( V_9 && V_9 -> V_260 ) {
V_23 = F_101 ( V_188 , V_9 -> V_261 , 0 ) ;
if ( V_23 < 0 )
goto V_258;
}
F_102 ( & V_2 -> V_221 ) ;
V_23 = F_103 ( V_188 ) ;
if ( V_23 < 0 )
goto V_258;
F_104 ( & V_239 -> V_10 , 100 ) ;
F_105 ( & V_239 -> V_10 , L_42 ,
F_30 ( V_2 -> V_5 , V_73 ) & 0xffff ,
F_61 ( V_2 -> V_196 ) / 1000000UL ) ;
F_67 ( V_2 -> V_196 ) ;
return V_23 ;
V_258:
F_67 ( V_2 -> V_196 ) ;
V_257:
F_106 ( & V_239 -> V_10 ) ;
V_243:
F_107 ( V_188 ) ;
return V_23 ;
}
static int F_108 ( struct V_238 * V_239 )
{
struct V_1 * V_2 = F_109 ( V_239 ) ;
V_2 -> V_234 = true ;
F_60 ( V_2 -> V_196 ) ;
F_68 ( & V_239 -> V_10 ) ;
F_110 ( & V_239 -> V_10 ) ;
F_111 ( V_2 -> V_188 ) ;
F_31 ( V_2 -> V_5 , V_106 , V_259 ) ;
F_77 ( & V_2 -> V_182 ) ;
F_67 ( V_2 -> V_196 ) ;
F_107 ( V_2 -> V_188 ) ;
F_66 ( & V_239 -> V_10 ) ;
F_106 ( & V_239 -> V_10 ) ;
return 0 ;
}
static int F_112 ( struct V_24 * V_10 )
{
struct V_1 * V_2 = F_113 ( V_10 ) ;
F_31 ( V_2 -> V_5 , V_106 , V_259 ) ;
return 0 ;
}
static int F_114 ( struct V_24 * V_10 )
{
return 0 ;
}
