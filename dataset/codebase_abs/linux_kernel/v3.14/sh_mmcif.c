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
struct V_45 V_46 ;
struct V_18 * V_19 ;
unsigned int V_47 ;
struct V_48 * V_49 ;
T_3 V_50 ;
int V_23 ;
F_19 ( V_50 ) ;
F_20 ( V_51 , V_50 ) ;
if ( V_42 )
V_47 = V_44 == V_40
? V_42 -> V_52 : V_42 -> V_53 ;
else
V_47 = 0 ;
V_19 = F_21 ( V_50 , V_54 ,
( void * ) ( unsigned long ) V_47 , & V_2 -> V_9 -> V_10 ,
V_44 == V_40 ? L_7 : L_8 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_9 , V_35 ,
V_44 == V_40 ? L_10 : L_11 , V_19 ) ;
if ( ! V_19 )
return NULL ;
V_49 = F_22 ( V_2 -> V_9 , V_55 , 0 ) ;
V_46 . V_47 = V_47 ;
V_46 . V_44 = V_44 ;
V_46 . V_56 = V_49 -> V_57 + V_58 ;
V_46 . V_59 = 0 ;
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
} else if ( ! V_2 -> V_9 -> V_10 . V_60 ) {
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
static void F_26 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_41 * V_62 = V_2 -> V_9 -> V_10 . V_63 ;
bool V_64 = V_62 ? V_62 -> V_64 : false ;
F_4 ( V_2 , V_65 , V_66 ) ;
F_4 ( V_2 , V_65 , V_67 ) ;
if ( ! V_61 )
return;
if ( V_64 && V_61 == V_2 -> V_61 )
F_1 ( V_2 , V_65 , V_68 ) ;
else
F_1 ( V_2 , V_65 , V_67 &
( ( F_27 ( F_28 ( V_2 -> V_61 ,
V_61 ) - 1 ) - 1 ) << 16 ) ) ;
F_1 ( V_2 , V_65 , V_66 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_69 ;
V_69 = 0x010f0000 & F_30 ( V_2 -> V_5 , V_65 ) ;
F_31 ( V_2 -> V_5 , V_70 , V_71 ) ;
F_31 ( V_2 -> V_5 , V_70 , V_72 ) ;
if ( V_2 -> V_73 )
V_69 |= V_74 ;
if ( V_2 -> V_75 )
F_31 ( V_2 -> V_5 , V_76 , 0x0F0F0000 ) ;
F_1 ( V_2 , V_65 , V_69 |
V_77 | V_78 | V_79 ) ;
F_1 ( V_2 , V_33 , V_80 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_81 , V_82 ;
int V_23 , V_83 ;
V_2 -> V_84 = false ;
V_81 = F_30 ( V_2 -> V_5 , V_85 ) ;
V_82 = F_30 ( V_2 -> V_5 , V_86 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_12 , V_81 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_13 , V_82 ) ;
if ( V_81 & V_87 ) {
F_1 ( V_2 , V_88 , V_89 ) ;
F_1 ( V_2 , V_88 , ~ V_89 ) ;
for ( V_83 = 10000000 ; V_83 ; V_83 -- ) {
if ( ! ( F_30 ( V_2 -> V_5 , V_85 )
& V_87 ) )
break;
F_33 ( 1 ) ;
}
if ( ! V_83 ) {
F_34 ( & V_2 -> V_9 -> V_10 ,
L_14 ) ;
return - V_36 ;
}
F_29 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_15 ) ;
return - V_36 ;
}
if ( V_82 & V_90 ) {
F_34 ( & V_2 -> V_9 -> V_10 , L_16 ,
V_2 -> V_91 , V_2 -> V_92 ) ;
V_23 = - V_36 ;
} else if ( V_82 & V_93 ) {
F_34 ( & V_2 -> V_9 -> V_10 , L_17 ,
V_2 -> V_91 , V_2 -> V_92 ) ;
V_23 = - V_94 ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_18 ,
V_2 -> V_91 , V_2 -> V_92 ) ;
V_23 = - V_36 ;
}
return V_23 ;
}
static bool F_35 ( struct V_1 * V_2 , T_1 * V_62 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
V_2 -> V_95 += V_2 -> V_96 ;
F_36 ( V_2 -> V_95 > V_11 -> V_15 -> V_97 ) ;
if ( V_2 -> V_95 == V_11 -> V_15 -> V_97 ) {
V_2 -> V_95 = 0 ;
if ( ++ V_2 -> V_98 < V_11 -> V_25 )
V_2 -> V_99 = F_37 ( ++ V_11 -> V_15 ) ;
} else {
V_2 -> V_99 = V_62 ;
}
return V_2 -> V_98 != V_11 -> V_25 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_96 = ( F_30 ( V_2 -> V_5 , V_100 ) &
V_101 ) + 3 ;
V_2 -> V_92 = V_102 ;
F_1 ( V_2 , V_103 , V_104 ) ;
}
static bool F_39 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_62 = F_37 ( V_11 -> V_15 ) ;
int V_105 ;
if ( V_2 -> V_84 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_105 = 0 ; V_105 < V_2 -> V_96 / 4 ; V_105 ++ )
* V_62 ++ = F_30 ( V_2 -> V_5 , V_58 ) ;
F_1 ( V_2 , V_103 , V_106 ) ;
V_2 -> V_92 = V_107 ;
return true ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_97 )
return;
V_2 -> V_96 = F_30 ( V_2 -> V_5 , V_100 ) &
V_101 ;
V_2 -> V_92 = V_108 ;
V_2 -> V_98 = 0 ;
V_2 -> V_95 = 0 ;
V_2 -> V_99 = F_37 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_103 , V_104 ) ;
}
static bool F_41 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_62 = V_2 -> V_99 ;
int V_105 ;
if ( V_2 -> V_84 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
F_36 ( ! V_11 -> V_15 -> V_97 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_96 / 4 ; V_105 ++ )
* V_62 ++ = F_30 ( V_2 -> V_5 , V_58 ) ;
if ( ! F_35 ( V_2 , V_62 ) )
return false ;
F_1 ( V_2 , V_103 , V_104 ) ;
return true ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_96 = ( F_30 ( V_2 -> V_5 , V_100 ) &
V_101 ) + 3 ;
V_2 -> V_92 = V_109 ;
F_1 ( V_2 , V_103 , V_110 ) ;
}
static bool F_43 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_62 = F_37 ( V_11 -> V_15 ) ;
int V_105 ;
if ( V_2 -> V_84 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_105 = 0 ; V_105 < V_2 -> V_96 / 4 ; V_105 ++ )
F_31 ( V_2 -> V_5 , V_58 , * V_62 ++ ) ;
F_1 ( V_2 , V_103 , V_111 ) ;
V_2 -> V_92 = V_112 ;
return true ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_97 )
return;
V_2 -> V_96 = F_30 ( V_2 -> V_5 , V_100 ) &
V_101 ;
V_2 -> V_92 = V_113 ;
V_2 -> V_98 = 0 ;
V_2 -> V_95 = 0 ;
V_2 -> V_99 = F_37 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_103 , V_110 ) ;
}
static bool F_45 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_62 = V_2 -> V_99 ;
int V_105 ;
if ( V_2 -> V_84 ) {
V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_11 -> error ) ;
return false ;
}
F_36 ( ! V_11 -> V_15 -> V_97 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_96 / 4 ; V_105 ++ )
F_31 ( V_2 -> V_5 , V_58 , * V_62 ++ ) ;
if ( ! F_35 ( V_2 , V_62 ) )
return false ;
F_1 ( V_2 , V_103 , V_110 ) ;
return true ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
if ( V_115 -> V_116 & V_117 ) {
V_115 -> V_118 [ 0 ] = F_30 ( V_2 -> V_5 , V_119 ) ;
V_115 -> V_118 [ 1 ] = F_30 ( V_2 -> V_5 , V_120 ) ;
V_115 -> V_118 [ 2 ] = F_30 ( V_2 -> V_5 , V_121 ) ;
V_115 -> V_118 [ 3 ] = F_30 ( V_2 -> V_5 , V_122 ) ;
} else
V_115 -> V_118 [ 0 ] = F_30 ( V_2 -> V_5 , V_122 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
V_115 -> V_118 [ 0 ] = F_30 ( V_2 -> V_5 , V_123 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
struct V_114 * V_115 = V_8 -> V_115 ;
T_1 V_124 = V_115 -> V_125 ;
T_1 V_69 = 0 ;
switch ( F_49 ( V_115 ) ) {
case V_126 :
V_69 |= V_127 ;
break;
case V_128 :
case V_129 :
case V_130 :
V_69 |= V_131 ;
break;
case V_132 :
V_69 |= V_133 ;
break;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_20 ) ;
break;
}
switch ( V_124 ) {
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_69 |= V_140 ;
break;
}
if ( V_11 ) {
V_69 |= V_141 ;
switch ( V_2 -> V_142 ) {
case V_143 :
V_69 |= V_144 ;
break;
case V_145 :
V_69 |= V_146 ;
break;
case V_147 :
V_69 |= V_148 ;
break;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_21 ) ;
break;
}
switch ( V_2 -> V_149 ) {
case V_150 :
V_69 |= V_151 ;
break;
}
}
if ( V_124 == V_152 || V_124 == V_153 )
V_69 |= V_154 ;
if ( V_124 == V_155 || V_124 == V_153 ) {
V_69 |= V_156 | V_157 ;
F_1 ( V_2 , V_100 ,
V_11 -> V_158 << 16 ) ;
}
if ( V_124 == V_159 || V_124 == V_160 ||
V_124 == V_161 || V_124 == V_162 )
V_69 |= V_163 ;
if ( V_124 == V_159 )
V_69 |= V_164 ;
if ( V_124 == V_160 ||
V_124 == V_161 || V_124 == V_162 )
V_69 |= V_165 ;
return ( V_124 << 24 ) | V_69 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 , T_1 V_124 )
{
switch ( V_124 ) {
case V_155 :
F_40 ( V_2 , V_8 ) ;
return 0 ;
case V_153 :
F_44 ( V_2 , V_8 ) ;
return 0 ;
case V_152 :
F_42 ( V_2 , V_8 ) ;
return 0 ;
case V_166 :
case V_167 :
F_38 ( V_2 , V_8 ) ;
return 0 ;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_22 , V_124 ) ;
return - V_22 ;
}
}
static void F_51 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_114 * V_115 = V_8 -> V_115 ;
T_1 V_124 = V_115 -> V_125 ;
T_1 V_50 ;
switch ( V_124 ) {
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_50 = V_168 | V_169 ;
break;
default:
V_50 = V_168 | V_170 ;
break;
}
if ( V_2 -> V_73 )
V_50 |= V_171 ;
if ( V_8 -> V_11 ) {
F_31 ( V_2 -> V_5 , V_100 , 0 ) ;
F_31 ( V_2 -> V_5 , V_100 ,
V_8 -> V_11 -> V_172 ) ;
}
V_124 = F_48 ( V_2 , V_8 ) ;
if ( V_2 -> V_73 )
F_31 ( V_2 -> V_5 , V_173 , 0xD80430C0 ) ;
else
F_31 ( V_2 -> V_5 , V_173 , 0xD80430C0 | V_174 ) ;
F_31 ( V_2 -> V_5 , V_103 , V_50 ) ;
F_31 ( V_2 -> V_5 , V_175 , V_115 -> V_6 ) ;
F_31 ( V_2 -> V_5 , V_176 , V_124 ) ;
V_2 -> V_92 = V_177 ;
F_52 ( & V_2 -> V_178 , V_2 -> V_83 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
switch ( V_8 -> V_115 -> V_125 ) {
case V_155 :
F_1 ( V_2 , V_103 , V_179 ) ;
break;
case V_153 :
F_1 ( V_2 , V_103 , V_180 ) ;
break;
default:
F_34 ( & V_2 -> V_9 -> V_10 , L_23 ) ;
V_8 -> V_181 -> error = F_32 ( V_2 ) ;
return;
}
V_2 -> V_92 = V_182 ;
}
static void F_54 ( struct V_183 * V_184 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_55 ( V_184 ) ;
unsigned long V_116 ;
F_56 ( & V_2 -> V_185 , V_116 ) ;
if ( V_2 -> V_91 != V_186 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_24 , V_35 , V_2 -> V_91 ) ;
F_57 ( & V_2 -> V_185 , V_116 ) ;
V_8 -> V_115 -> error = - V_187 ;
F_58 ( V_184 , V_8 ) ;
return;
}
V_2 -> V_91 = V_188 ;
F_57 ( & V_2 -> V_185 , V_116 ) ;
switch ( V_8 -> V_115 -> V_125 ) {
case V_134 :
case V_167 :
if ( ( V_8 -> V_115 -> V_116 & V_189 ) != V_190 )
break;
case V_191 :
case V_192 :
V_2 -> V_91 = V_186 ;
V_8 -> V_115 -> error = - V_94 ;
F_58 ( V_184 , V_8 ) ;
return;
default:
break;
}
V_2 -> V_8 = V_8 ;
F_51 ( V_2 , V_8 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_23 = F_60 ( V_2 -> V_193 ) ;
if ( ! V_23 ) {
V_2 -> V_61 = F_61 ( V_2 -> V_193 ) ;
V_2 -> V_184 -> V_194 = V_2 -> V_61 / 2 ;
V_2 -> V_184 -> V_195 = V_2 -> V_61 / 512 ;
}
return V_23 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_196 * V_197 )
{
struct V_183 * V_184 = V_2 -> V_184 ;
if ( ! F_63 ( V_184 -> V_198 . V_199 ) )
F_64 ( V_184 , V_184 -> V_198 . V_199 ,
V_197 -> V_200 ? V_197 -> V_201 : 0 ) ;
}
static void F_65 ( struct V_183 * V_184 , struct V_196 * V_197 )
{
struct V_1 * V_2 = F_55 ( V_184 ) ;
unsigned long V_116 ;
F_56 ( & V_2 -> V_185 , V_116 ) ;
if ( V_2 -> V_91 != V_186 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_24 , V_35 , V_2 -> V_91 ) ;
F_57 ( & V_2 -> V_185 , V_116 ) ;
return;
}
V_2 -> V_91 = V_202 ;
F_57 ( & V_2 -> V_185 , V_116 ) ;
if ( V_197 -> V_200 == V_203 ) {
if ( ! V_2 -> V_204 ) {
F_24 ( V_2 , V_2 -> V_9 -> V_10 . V_63 ) ;
V_2 -> V_204 = true ;
}
F_62 ( V_2 , V_197 ) ;
} else if ( V_197 -> V_200 == V_205 || ! V_197 -> clock ) {
F_26 ( V_2 , 0 ) ;
if ( V_197 -> V_200 == V_205 ) {
if ( V_2 -> V_204 ) {
F_25 ( V_2 ) ;
V_2 -> V_204 = false ;
}
}
if ( V_2 -> V_206 ) {
F_66 ( & V_2 -> V_9 -> V_10 ) ;
F_67 ( V_2 -> V_193 ) ;
V_2 -> V_206 = false ;
if ( V_197 -> V_200 == V_205 )
F_62 ( V_2 , V_197 ) ;
}
V_2 -> V_91 = V_186 ;
return;
}
if ( V_197 -> clock ) {
if ( ! V_2 -> V_206 ) {
F_59 ( V_2 ) ;
F_68 ( & V_2 -> V_9 -> V_10 ) ;
V_2 -> V_206 = true ;
F_29 ( V_2 ) ;
}
F_26 ( V_2 , V_197 -> clock ) ;
}
V_2 -> V_149 = V_197 -> V_149 ;
V_2 -> V_142 = V_197 -> V_142 ;
V_2 -> V_91 = V_186 ;
}
static int F_69 ( struct V_183 * V_184 )
{
struct V_1 * V_2 = F_55 ( V_184 ) ;
struct V_41 * V_62 = V_2 -> V_9 -> V_10 . V_63 ;
int V_23 = F_70 ( V_184 ) ;
if ( V_23 >= 0 )
return V_23 ;
if ( ! V_62 || ! V_62 -> V_207 )
return - V_208 ;
else
return V_62 -> V_207 ( V_2 -> V_9 ) ;
}
static bool F_71 ( struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_8 -> V_115 ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
long time ;
if ( V_2 -> V_84 ) {
switch ( V_115 -> V_125 ) {
case V_160 :
case V_209 :
case V_191 :
V_115 -> error = - V_94 ;
break;
default:
V_115 -> error = F_32 ( V_2 ) ;
break;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_25 ,
V_115 -> V_125 , V_115 -> error ) ;
V_2 -> V_84 = false ;
return false ;
}
if ( ! ( V_115 -> V_116 & V_210 ) ) {
V_115 -> error = 0 ;
return false ;
}
F_46 ( V_2 , V_115 ) ;
if ( ! V_11 )
return false ;
F_72 ( & V_2 -> V_12 ) ;
if ( V_11 -> V_116 & V_211 ) {
if ( V_2 -> V_20 )
F_10 ( V_2 ) ;
} else {
if ( V_2 -> V_37 )
F_17 ( V_2 ) ;
}
if ( ! V_2 -> V_27 ) {
V_11 -> error = F_50 ( V_2 , V_2 -> V_8 , V_115 -> V_125 ) ;
return ! V_11 -> error ;
}
time = F_73 ( & V_2 -> V_12 ,
V_2 -> V_83 ) ;
if ( V_11 -> V_116 & V_211 )
F_74 ( V_2 -> V_20 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_26 ) ;
else
F_74 ( V_2 -> V_37 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_39 ) ;
if ( V_2 -> V_84 ) {
F_34 ( V_2 -> V_184 -> V_212 ,
L_26 ) ;
V_11 -> error = F_32 ( V_2 ) ;
} else if ( ! time ) {
F_34 ( V_2 -> V_184 -> V_212 , L_27 ) ;
V_11 -> error = - V_94 ;
} else if ( time < 0 ) {
F_34 ( V_2 -> V_184 -> V_212 ,
L_28 , time ) ;
V_11 -> error = time ;
}
F_4 ( V_2 , V_33 ,
V_34 | V_38 ) ;
V_2 -> V_27 = false ;
if ( V_11 -> error ) {
V_11 -> V_213 = 0 ;
if ( V_11 -> V_116 & V_211 )
F_75 ( V_2 -> V_20 ) ;
else
F_75 ( V_2 -> V_37 ) ;
}
return false ;
}
static T_4 F_76 ( int V_214 , void * V_215 )
{
struct V_1 * V_2 = V_215 ;
struct V_7 * V_8 ;
bool V_216 = false ;
F_77 ( & V_2 -> V_178 ) ;
F_78 ( & V_2 -> V_217 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_29 ,
V_2 -> V_91 , V_2 -> V_92 ) ;
F_79 ( & V_2 -> V_217 ) ;
return V_218 ;
}
switch ( V_2 -> V_92 ) {
case V_219 :
F_79 ( & V_2 -> V_217 ) ;
return V_218 ;
case V_177 :
V_216 = F_71 ( V_2 ) ;
break;
case V_108 :
V_216 = F_41 ( V_2 ) ;
break;
case V_102 :
V_216 = F_39 ( V_2 ) ;
break;
case V_113 :
V_216 = F_45 ( V_2 ) ;
break;
case V_109 :
V_216 = F_43 ( V_2 ) ;
break;
case V_182 :
if ( V_2 -> V_84 ) {
V_8 -> V_181 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_8 -> V_181 -> error ) ;
break;
}
F_47 ( V_2 , V_8 -> V_181 ) ;
V_8 -> V_181 -> error = 0 ;
break;
case V_107 :
case V_112 :
if ( V_2 -> V_84 ) {
V_8 -> V_11 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_19 , V_35 , V_8 -> V_11 -> error ) ;
}
break;
default:
F_80 () ;
}
if ( V_216 ) {
F_52 ( & V_2 -> V_178 , V_2 -> V_83 ) ;
F_79 ( & V_2 -> V_217 ) ;
return V_218 ;
}
if ( V_2 -> V_92 != V_182 ) {
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_8 -> V_115 -> error && V_11 && ! V_11 -> error )
V_11 -> V_213 =
V_11 -> V_158 * V_11 -> V_172 ;
if ( V_8 -> V_181 && ! V_8 -> V_115 -> error && ( ! V_11 || ! V_11 -> error ) ) {
F_53 ( V_2 , V_8 ) ;
if ( ! V_8 -> V_181 -> error ) {
F_52 ( & V_2 -> V_178 , V_2 -> V_83 ) ;
F_79 ( & V_2 -> V_217 ) ;
return V_218 ;
}
}
}
V_2 -> V_92 = V_219 ;
V_2 -> V_91 = V_186 ;
V_2 -> V_8 = NULL ;
F_58 ( V_2 -> V_184 , V_8 ) ;
F_79 ( & V_2 -> V_217 ) ;
return V_218 ;
}
static T_4 F_81 ( int V_214 , void * V_215 )
{
struct V_1 * V_2 = V_215 ;
T_1 V_91 , V_50 ;
V_91 = F_30 ( V_2 -> V_5 , V_173 ) ;
V_50 = F_30 ( V_2 -> V_5 , V_103 ) ;
if ( V_2 -> V_73 )
F_31 ( V_2 -> V_5 , V_173 , ~ ( V_91 & V_50 ) ) ;
else
F_31 ( V_2 -> V_5 , V_173 , V_174 | ~ ( V_91 & V_50 ) ) ;
F_4 ( V_2 , V_103 , V_91 & V_220 ) ;
if ( V_91 & ~ V_220 )
F_6 ( & V_2 -> V_9 -> V_10 , L_30 ,
V_91 ) ;
if ( V_91 & V_221 || V_91 & ~ V_222 ) {
V_2 -> V_84 = true ;
F_6 ( & V_2 -> V_9 -> V_10 , L_31 , V_91 ) ;
}
if ( V_91 & ~ ( V_223 | V_224 ) ) {
if ( ! V_2 -> V_8 )
F_6 ( & V_2 -> V_9 -> V_10 , L_32 , V_91 ) ;
if ( ! V_2 -> V_27 )
return V_225 ;
else if ( V_2 -> V_84 )
F_5 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_33 , V_91 ) ;
}
return V_218 ;
}
static void F_82 ( struct V_226 * V_227 )
{
struct V_228 * V_229 = F_83 ( V_227 , struct V_228 , V_227 ) ;
struct V_1 * V_2 = F_83 ( V_229 , struct V_1 , V_178 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_116 ;
if ( V_2 -> V_230 )
return;
F_34 ( & V_2 -> V_9 -> V_10 , L_34 ,
V_2 -> V_92 , V_8 -> V_115 -> V_125 ) ;
F_56 ( & V_2 -> V_185 , V_116 ) ;
if ( V_2 -> V_91 == V_186 ) {
F_57 ( & V_2 -> V_185 , V_116 ) ;
return;
}
V_2 -> V_91 = V_231 ;
F_57 ( & V_2 -> V_185 , V_116 ) ;
switch ( V_2 -> V_92 ) {
case V_177 :
V_8 -> V_115 -> error = F_32 ( V_2 ) ;
break;
case V_182 :
V_8 -> V_181 -> error = F_32 ( V_2 ) ;
break;
case V_108 :
case V_113 :
case V_102 :
case V_109 :
case V_107 :
case V_112 :
V_8 -> V_11 -> error = F_32 ( V_2 ) ;
break;
default:
F_80 () ;
}
V_2 -> V_91 = V_186 ;
V_2 -> V_92 = V_219 ;
V_2 -> V_8 = NULL ;
F_58 ( V_2 -> V_184 , V_8 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_41 * V_9 = V_2 -> V_9 -> V_10 . V_63 ;
struct V_183 * V_184 = V_2 -> V_184 ;
F_85 ( V_184 ) ;
if ( ! V_9 )
return;
if ( ! V_184 -> V_232 )
V_184 -> V_232 = V_9 -> V_233 ;
else if ( V_9 -> V_233 )
F_16 ( F_86 ( V_184 ) , L_35 ) ;
}
static int F_87 ( struct V_234 * V_235 )
{
int V_23 = 0 , V_214 [ 2 ] ;
struct V_183 * V_184 ;
struct V_1 * V_2 ;
struct V_41 * V_9 = V_235 -> V_10 . V_63 ;
struct V_48 * V_49 ;
void T_5 * V_3 ;
const char * V_236 ;
V_214 [ 0 ] = F_88 ( V_235 , 0 ) ;
V_214 [ 1 ] = F_88 ( V_235 , 1 ) ;
if ( V_214 [ 0 ] < 0 ) {
F_34 ( & V_235 -> V_10 , L_36 ) ;
return - V_237 ;
}
V_49 = F_22 ( V_235 , V_55 , 0 ) ;
if ( ! V_49 ) {
F_34 ( & V_235 -> V_10 , L_37 ) ;
return - V_237 ;
}
V_3 = F_89 ( V_49 -> V_57 , F_90 ( V_49 ) ) ;
if ( ! V_3 ) {
F_34 ( & V_235 -> V_10 , L_38 ) ;
return - V_238 ;
}
V_184 = F_91 ( sizeof( struct V_1 ) , & V_235 -> V_10 ) ;
if ( ! V_184 ) {
V_23 = - V_238 ;
goto V_239;
}
V_23 = F_92 ( V_184 ) ;
if ( V_23 < 0 )
goto V_240;
V_2 = F_55 ( V_184 ) ;
V_2 -> V_184 = V_184 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_83 = F_93 ( 1000 ) ;
V_2 -> V_73 = ! V_9 || ! V_9 -> V_241 ;
V_2 -> V_75 = V_9 && V_9 -> V_242 ;
V_2 -> V_9 = V_235 ;
F_94 ( & V_2 -> V_185 ) ;
V_184 -> V_243 = & V_244 ;
F_84 ( V_2 ) ;
V_184 -> V_245 |= V_246 | V_247 ;
if ( V_9 && V_9 -> V_245 )
V_184 -> V_245 |= V_9 -> V_245 ;
V_184 -> V_248 = 32 ;
V_184 -> V_249 = 512 ;
V_184 -> V_250 = V_251 * V_184 -> V_248 ;
V_184 -> V_252 = V_184 -> V_250 / V_184 -> V_249 ;
V_184 -> V_253 = V_184 -> V_250 ;
F_95 ( V_235 , V_2 ) ;
F_96 ( & V_235 -> V_10 ) ;
V_2 -> V_206 = false ;
V_2 -> V_193 = F_97 ( & V_235 -> V_10 , NULL ) ;
if ( F_63 ( V_2 -> V_193 ) ) {
V_23 = F_98 ( V_2 -> V_193 ) ;
F_34 ( & V_235 -> V_10 , L_39 , V_23 ) ;
goto V_254;
}
V_23 = F_59 ( V_2 ) ;
if ( V_23 < 0 )
goto V_255;
V_23 = F_99 ( & V_235 -> V_10 ) ;
if ( V_23 < 0 )
goto V_256;
F_100 ( & V_2 -> V_178 , F_82 ) ;
F_29 ( V_2 ) ;
F_31 ( V_2 -> V_5 , V_103 , V_257 ) ;
V_236 = V_214 [ 1 ] < 0 ? F_8 ( & V_235 -> V_10 ) : L_40 ;
V_23 = F_101 ( V_214 [ 0 ] , F_81 , F_76 , 0 , V_236 , V_2 ) ;
if ( V_23 ) {
F_34 ( & V_235 -> V_10 , L_41 , V_236 ) ;
goto V_258;
}
if ( V_214 [ 1 ] >= 0 ) {
V_23 = F_101 ( V_214 [ 1 ] , F_81 , F_76 ,
0 , L_42 , V_2 ) ;
if ( V_23 ) {
F_34 ( & V_235 -> V_10 , L_43 ) ;
goto V_259;
}
}
if ( V_9 && V_9 -> V_260 ) {
V_23 = F_102 ( V_184 , V_9 -> V_261 , 0 ) ;
if ( V_23 < 0 )
goto V_262;
}
F_103 ( & V_2 -> V_217 ) ;
F_67 ( V_2 -> V_193 ) ;
V_23 = F_104 ( V_184 ) ;
if ( V_23 < 0 )
goto V_263;
F_105 ( & V_235 -> V_10 , 100 ) ;
F_106 ( & V_235 -> V_10 , L_44 , V_264 ) ;
F_6 ( & V_235 -> V_10 , L_45 ,
F_30 ( V_2 -> V_5 , V_70 ) & 0x0000ffff ) ;
return V_23 ;
V_263:
V_262:
if ( V_214 [ 1 ] >= 0 )
F_107 ( V_214 [ 1 ] , V_2 ) ;
V_259:
F_107 ( V_214 [ 0 ] , V_2 ) ;
V_258:
F_108 ( & V_235 -> V_10 ) ;
V_256:
F_67 ( V_2 -> V_193 ) ;
V_255:
F_109 ( V_2 -> V_193 ) ;
V_254:
F_110 ( & V_235 -> V_10 ) ;
V_240:
F_111 ( V_184 ) ;
V_239:
F_112 ( V_3 ) ;
return V_23 ;
}
static int F_113 ( struct V_234 * V_235 )
{
struct V_1 * V_2 = F_114 ( V_235 ) ;
int V_214 [ 2 ] ;
V_2 -> V_230 = true ;
F_60 ( V_2 -> V_193 ) ;
F_68 ( & V_235 -> V_10 ) ;
F_115 ( & V_235 -> V_10 ) ;
F_116 ( V_2 -> V_184 ) ;
F_31 ( V_2 -> V_5 , V_103 , V_257 ) ;
F_77 ( & V_2 -> V_178 ) ;
if ( V_2 -> V_5 )
F_112 ( V_2 -> V_5 ) ;
V_214 [ 0 ] = F_88 ( V_235 , 0 ) ;
V_214 [ 1 ] = F_88 ( V_235 , 1 ) ;
F_107 ( V_214 [ 0 ] , V_2 ) ;
if ( V_214 [ 1 ] >= 0 )
F_107 ( V_214 [ 1 ] , V_2 ) ;
F_67 ( V_2 -> V_193 ) ;
F_111 ( V_2 -> V_184 ) ;
F_66 ( & V_235 -> V_10 ) ;
F_110 ( & V_235 -> V_10 ) ;
return 0 ;
}
static int F_117 ( struct V_24 * V_10 )
{
struct V_1 * V_2 = F_118 ( V_10 ) ;
F_31 ( V_2 -> V_5 , V_103 , V_257 ) ;
return 0 ;
}
static int F_119 ( struct V_24 * V_10 )
{
return 0 ;
}
