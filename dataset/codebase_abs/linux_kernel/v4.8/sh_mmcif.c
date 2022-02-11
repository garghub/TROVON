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
F_19 ( struct V_1 * V_2 , T_3 V_40 )
{
T_4 V_41 ;
F_20 ( V_41 ) ;
F_21 ( V_42 , V_41 ) ;
if ( V_40 <= 0 )
return NULL ;
return F_22 ( V_41 , V_43 , ( void * ) V_40 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
enum V_44 V_45 )
{
struct V_46 * V_47 ;
struct V_48 V_49 = { 0 , } ;
V_47 = F_24 ( V_2 -> V_50 , V_51 , 0 ) ;
V_49 . V_45 = V_45 ;
if ( V_45 == V_27 ) {
V_49 . V_52 = V_47 -> V_53 + V_54 ;
V_49 . V_55 = V_56 ;
} else {
V_49 . V_57 = V_47 -> V_53 + V_54 ;
V_49 . V_58 = V_56 ;
}
return F_25 ( V_19 , & V_49 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
V_2 -> V_26 = false ;
if ( F_27 ( V_59 ) && V_10 -> V_60 ) {
struct V_61 * V_62 = V_10 -> V_60 ;
V_2 -> V_36 = F_19 ( V_2 ,
V_62 -> V_63 ) ;
V_2 -> V_20 = F_19 ( V_2 ,
V_62 -> V_64 ) ;
} else {
V_2 -> V_36 = F_28 ( V_10 , L_7 ) ;
V_2 -> V_20 = F_28 ( V_10 , L_8 ) ;
}
F_7 ( V_10 , L_9 , V_34 , V_2 -> V_36 ,
V_2 -> V_20 ) ;
if ( ! V_2 -> V_36 || ! V_2 -> V_20 ||
F_23 ( V_2 , V_2 -> V_36 , V_39 ) ||
F_23 ( V_2 , V_2 -> V_20 , V_27 ) )
goto error;
return;
error:
if ( V_2 -> V_36 )
F_16 ( V_2 -> V_36 ) ;
if ( V_2 -> V_20 )
F_16 ( V_2 -> V_20 ) ;
V_2 -> V_36 = V_2 -> V_20 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
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
static void F_30 ( struct V_1 * V_2 , unsigned int V_65 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_61 * V_66 = V_10 -> V_60 ;
bool V_67 = V_66 ? V_66 -> V_67 : false ;
unsigned int V_68 = F_31 ( V_2 -> V_65 ) ;
unsigned int V_69 ;
F_4 ( V_2 , V_70 , V_71 ) ;
F_4 ( V_2 , V_70 , V_72 ) ;
if ( ! V_65 )
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
V_74 = F_32 ( V_2 -> V_65 , V_65 * div ) ;
V_76 = V_74 / div ;
V_78 = ( V_76 > V_65 ) ? V_76 - V_65 : V_65 - V_76 ;
if ( V_78 <= V_77 ) {
V_75 = V_74 ;
V_69 = V_79 ;
V_77 = V_78 ;
}
}
F_7 ( V_10 , L_10 ,
( V_75 / ( 1 << ( V_69 + 1 ) ) ) , V_65 ,
V_75 , V_69 ) ;
F_33 ( V_2 -> V_65 , V_75 ) ;
V_69 = V_69 << 16 ;
} else if ( V_67 && V_65 == V_68 ) {
V_69 = V_80 ;
} else {
V_69 = ( F_34 ( F_35 ( V_68 , V_65 ) - 1 ) - 1 ) << 16 ;
}
F_1 ( V_2 , V_70 , V_72 & V_69 ) ;
F_1 ( V_2 , V_70 , V_71 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_81 ;
V_81 = 0x010f0000 & F_37 ( V_2 -> V_5 , V_70 ) ;
F_38 ( V_2 -> V_5 , V_82 , V_83 ) ;
F_38 ( V_2 -> V_5 , V_82 , V_84 ) ;
if ( V_2 -> V_85 )
V_81 |= V_86 ;
if ( V_2 -> V_87 )
F_38 ( V_2 -> V_5 , V_88 , 0x0F0F0000 ) ;
F_1 ( V_2 , V_70 , V_81 |
V_89 | V_90 | V_91 ) ;
F_1 ( V_2 , V_32 , V_92 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_93 , V_94 ;
int V_23 , V_95 ;
V_2 -> V_96 = false ;
V_93 = F_37 ( V_2 -> V_5 , V_97 ) ;
V_94 = F_37 ( V_2 -> V_5 , V_98 ) ;
F_7 ( V_10 , L_11 , V_93 ) ;
F_7 ( V_10 , L_12 , V_94 ) ;
if ( V_93 & V_99 ) {
F_1 ( V_2 , V_100 , V_101 ) ;
F_1 ( V_2 , V_100 , ~ V_101 ) ;
for ( V_95 = 10000 ; V_95 ; V_95 -- ) {
if ( ! ( F_37 ( V_2 -> V_5 , V_97 )
& V_99 ) )
break;
F_40 ( 1 ) ;
}
if ( ! V_95 ) {
F_41 ( V_10 ,
L_13 ) ;
return - V_35 ;
}
F_36 ( V_2 ) ;
F_7 ( V_10 , L_14 ) ;
return - V_35 ;
}
if ( V_94 & V_102 ) {
F_41 ( V_10 , L_15 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
V_23 = - V_35 ;
} else if ( V_94 & V_105 ) {
F_41 ( V_10 , L_16 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
V_23 = - V_106 ;
} else {
F_7 ( V_10 , L_17 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
V_23 = - V_35 ;
}
return V_23 ;
}
static bool F_42 ( struct V_1 * V_2 , T_1 * V_66 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
V_2 -> V_107 += V_2 -> V_108 ;
F_43 ( V_2 -> V_107 > V_11 -> V_15 -> V_109 ) ;
if ( V_2 -> V_107 == V_11 -> V_15 -> V_109 ) {
V_2 -> V_107 = 0 ;
if ( ++ V_2 -> V_110 < V_11 -> V_24 )
V_2 -> V_111 = F_44 ( ++ V_11 -> V_15 ) ;
} else {
V_2 -> V_111 = V_66 ;
}
return V_2 -> V_110 != V_11 -> V_24 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_108 = ( F_37 ( V_2 -> V_5 , V_112 ) &
V_113 ) + 3 ;
V_2 -> V_104 = V_114 ;
F_1 ( V_2 , V_115 , V_116 ) ;
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_66 = F_44 ( V_11 -> V_15 ) ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_39 ( V_2 ) ;
F_7 ( V_10 , L_18 , V_34 , V_11 -> error ) ;
return false ;
}
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
* V_66 ++ = F_37 ( V_2 -> V_5 , V_54 ) ;
F_1 ( V_2 , V_115 , V_117 ) ;
V_2 -> V_104 = V_118 ;
return true ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_24 || ! V_11 -> V_15 -> V_109 )
return;
V_2 -> V_108 = F_37 ( V_2 -> V_5 , V_112 ) &
V_113 ;
V_2 -> V_104 = V_119 ;
V_2 -> V_110 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_111 = F_44 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_115 , V_116 ) ;
}
static bool F_48 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_66 = V_2 -> V_111 ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_39 ( V_2 ) ;
F_7 ( V_10 , L_18 , V_34 , V_11 -> error ) ;
return false ;
}
F_43 ( ! V_11 -> V_15 -> V_109 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
* V_66 ++ = F_37 ( V_2 -> V_5 , V_54 ) ;
if ( ! F_42 ( V_2 , V_66 ) )
return false ;
F_1 ( V_2 , V_115 , V_116 ) ;
return true ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_108 = ( F_37 ( V_2 -> V_5 , V_112 ) &
V_113 ) + 3 ;
V_2 -> V_104 = V_120 ;
F_1 ( V_2 , V_115 , V_121 ) ;
}
static bool F_50 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_66 = F_44 ( V_11 -> V_15 ) ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_39 ( V_2 ) ;
F_7 ( V_10 , L_18 , V_34 , V_11 -> error ) ;
return false ;
}
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
F_38 ( V_2 -> V_5 , V_54 , * V_66 ++ ) ;
F_1 ( V_2 , V_115 , V_122 ) ;
V_2 -> V_104 = V_123 ;
return true ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_24 || ! V_11 -> V_15 -> V_109 )
return;
V_2 -> V_108 = F_37 ( V_2 -> V_5 , V_112 ) &
V_113 ;
V_2 -> V_104 = V_124 ;
V_2 -> V_110 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_111 = F_44 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_115 , V_121 ) ;
}
static bool F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_66 = V_2 -> V_111 ;
int V_79 ;
if ( V_2 -> V_96 ) {
V_11 -> error = F_39 ( V_2 ) ;
F_7 ( V_10 , L_18 , V_34 , V_11 -> error ) ;
return false ;
}
F_43 ( ! V_11 -> V_15 -> V_109 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_108 / 4 ; V_79 ++ )
F_38 ( V_2 -> V_5 , V_54 , * V_66 ++ ) ;
if ( ! F_42 ( V_2 , V_66 ) )
return false ;
F_1 ( V_2 , V_115 , V_121 ) ;
return true ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
if ( V_126 -> V_127 & V_128 ) {
V_126 -> V_129 [ 0 ] = F_37 ( V_2 -> V_5 , V_130 ) ;
V_126 -> V_129 [ 1 ] = F_37 ( V_2 -> V_5 , V_131 ) ;
V_126 -> V_129 [ 2 ] = F_37 ( V_2 -> V_5 , V_132 ) ;
V_126 -> V_129 [ 3 ] = F_37 ( V_2 -> V_5 , V_133 ) ;
} else
V_126 -> V_129 [ 0 ] = F_37 ( V_2 -> V_5 , V_133 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
V_126 -> V_129 [ 0 ] = F_37 ( V_2 -> V_5 , V_134 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_13 * V_11 = V_8 -> V_11 ;
struct V_125 * V_126 = V_8 -> V_126 ;
T_1 V_135 = V_126 -> V_136 ;
T_1 V_81 = 0 ;
switch ( F_56 ( V_126 ) ) {
case V_137 :
V_81 |= V_138 ;
break;
case V_139 :
case V_140 :
V_81 |= V_141 ;
break;
case V_142 :
V_81 |= V_143 | V_141 ;
break;
case V_144 :
V_81 |= V_145 ;
break;
default:
F_41 ( V_10 , L_19 ) ;
break;
}
if ( V_11 ) {
V_81 |= V_146 ;
switch ( V_2 -> V_147 ) {
case V_148 :
V_81 |= V_149 ;
break;
case V_150 :
V_81 |= V_151 ;
break;
case V_152 :
V_81 |= V_153 ;
break;
default:
F_41 ( V_10 , L_20 ) ;
break;
}
switch ( V_2 -> V_154 ) {
case V_155 :
V_81 |= V_156 ;
break;
}
}
if ( V_135 == V_157 || V_135 == V_158 )
V_81 |= V_159 ;
if ( V_135 == V_160 || V_135 == V_158 ) {
V_81 |= V_161 | V_162 ;
F_1 ( V_2 , V_112 ,
V_11 -> V_163 << 16 ) ;
}
if ( V_135 == V_164 || V_135 == V_165 ||
V_135 == V_166 || V_135 == V_167 )
V_81 |= V_168 ;
if ( V_135 == V_164 )
V_81 |= V_169 ;
if ( V_135 == V_165 ||
V_135 == V_166 || V_135 == V_167 )
V_81 |= V_170 ;
return ( V_135 << 24 ) | V_81 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_7 * V_8 , T_1 V_135 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
switch ( V_135 ) {
case V_160 :
F_47 ( V_2 , V_8 ) ;
return 0 ;
case V_158 :
F_51 ( V_2 , V_8 ) ;
return 0 ;
case V_157 :
F_49 ( V_2 , V_8 ) ;
return 0 ;
case V_171 :
case V_172 :
F_45 ( V_2 , V_8 ) ;
return 0 ;
default:
F_41 ( V_10 , L_21 , V_135 ) ;
return - V_22 ;
}
}
static void F_58 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_125 * V_126 = V_8 -> V_126 ;
T_1 V_135 = V_126 -> V_136 ;
T_1 V_41 = 0 ;
unsigned long V_127 ;
if ( V_126 -> V_127 & V_173 )
V_41 = V_174 | V_175 ;
else
V_41 = V_174 | V_176 ;
if ( V_2 -> V_85 )
V_41 |= V_177 ;
if ( V_8 -> V_11 ) {
F_38 ( V_2 -> V_5 , V_112 , 0 ) ;
F_38 ( V_2 -> V_5 , V_112 ,
V_8 -> V_11 -> V_178 ) ;
}
V_135 = F_55 ( V_2 , V_8 ) ;
if ( V_2 -> V_85 )
F_38 ( V_2 -> V_5 , V_179 , 0xD80430C0 ) ;
else
F_38 ( V_2 -> V_5 , V_179 , 0xD80430C0 | V_180 ) ;
F_38 ( V_2 -> V_5 , V_115 , V_41 ) ;
F_38 ( V_2 -> V_5 , V_181 , V_126 -> V_6 ) ;
F_59 ( & V_2 -> V_182 , V_127 ) ;
F_38 ( V_2 -> V_5 , V_183 , V_135 ) ;
V_2 -> V_104 = V_184 ;
F_60 ( & V_2 -> V_185 , V_2 -> V_95 ) ;
F_61 ( & V_2 -> V_182 , V_127 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
switch ( V_8 -> V_126 -> V_136 ) {
case V_160 :
F_1 ( V_2 , V_115 , V_186 ) ;
break;
case V_158 :
F_1 ( V_2 , V_115 , V_187 ) ;
break;
default:
F_41 ( V_10 , L_22 ) ;
V_8 -> V_188 -> error = F_39 ( V_2 ) ;
return;
}
V_2 -> V_104 = V_189 ;
}
static void F_63 ( struct V_190 * V_191 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_64 ( V_191 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
unsigned long V_127 ;
F_59 ( & V_2 -> V_182 , V_127 ) ;
if ( V_2 -> V_103 != V_192 ) {
F_7 ( V_10 , L_23 ,
V_34 , V_2 -> V_103 ) ;
F_61 ( & V_2 -> V_182 , V_127 ) ;
V_8 -> V_126 -> error = - V_193 ;
F_65 ( V_191 , V_8 ) ;
return;
}
V_2 -> V_103 = V_194 ;
F_61 ( & V_2 -> V_182 , V_127 ) ;
V_2 -> V_8 = V_8 ;
F_58 ( V_2 , V_8 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
if ( V_2 -> V_191 -> V_195 ) {
unsigned int V_195 , V_196 = 0 , V_197 ;
V_195 = V_2 -> V_191 -> V_195 ;
for ( V_197 = V_195 ; V_197 > 2 ; ) {
V_196 = F_32 ( V_2 -> V_65 , V_197 / 2 ) ;
if ( V_196 == V_197 )
break;
V_197 = V_196 ;
}
V_2 -> V_73 = 0x3ff ;
V_2 -> V_191 -> V_195 = V_195 / ( 1 << F_67 ( V_2 -> V_73 ) ) ;
V_2 -> V_191 -> V_196 = V_196 / ( 1 << F_34 ( V_2 -> V_73 ) ) ;
} else {
unsigned int V_65 = F_31 ( V_2 -> V_65 ) ;
V_2 -> V_191 -> V_195 = V_65 / 2 ;
V_2 -> V_191 -> V_196 = V_65 / 512 ;
}
F_7 ( V_10 , L_24 ,
V_2 -> V_191 -> V_195 , V_2 -> V_191 -> V_196 ) ;
}
static void F_68 ( struct V_190 * V_191 , struct V_198 * V_199 )
{
struct V_1 * V_2 = F_64 ( V_191 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
unsigned long V_127 ;
F_59 ( & V_2 -> V_182 , V_127 ) ;
if ( V_2 -> V_103 != V_192 ) {
F_7 ( V_10 , L_23 ,
V_34 , V_2 -> V_103 ) ;
F_61 ( & V_2 -> V_182 , V_127 ) ;
return;
}
V_2 -> V_103 = V_200 ;
F_61 ( & V_2 -> V_182 , V_127 ) ;
switch ( V_199 -> V_201 ) {
case V_202 :
if ( ! F_69 ( V_191 -> V_203 . V_204 ) )
F_70 ( V_191 , V_191 -> V_203 . V_204 , V_199 -> V_205 ) ;
if ( ! V_2 -> V_206 ) {
F_71 ( V_2 -> V_65 ) ;
F_72 ( V_10 ) ;
F_36 ( V_2 ) ;
F_26 ( V_2 ) ;
V_2 -> V_206 = true ;
}
break;
case V_207 :
if ( ! F_69 ( V_191 -> V_203 . V_204 ) )
F_70 ( V_191 , V_191 -> V_203 . V_204 , 0 ) ;
if ( V_2 -> V_206 ) {
F_30 ( V_2 , 0 ) ;
F_29 ( V_2 ) ;
F_73 ( V_10 ) ;
F_74 ( V_2 -> V_65 ) ;
V_2 -> V_206 = false ;
}
break;
case V_208 :
F_30 ( V_2 , V_199 -> clock ) ;
break;
}
V_2 -> V_154 = V_199 -> V_154 ;
V_2 -> V_147 = V_199 -> V_147 ;
V_2 -> V_103 = V_192 ;
}
static int F_75 ( struct V_190 * V_191 )
{
struct V_1 * V_2 = F_64 ( V_191 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_61 * V_66 = V_10 -> V_60 ;
int V_23 = F_76 ( V_191 ) ;
if ( V_23 >= 0 )
return V_23 ;
if ( ! V_66 || ! V_66 -> V_209 )
return - V_210 ;
else
return V_66 -> V_209 ( V_2 -> V_50 ) ;
}
static bool F_77 ( struct V_1 * V_2 )
{
struct V_125 * V_126 = V_2 -> V_8 -> V_126 ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
long time ;
if ( V_2 -> V_96 ) {
switch ( V_126 -> V_136 ) {
case V_165 :
case V_211 :
case V_212 :
V_126 -> error = - V_106 ;
break;
default:
V_126 -> error = F_39 ( V_2 ) ;
break;
}
F_7 ( V_10 , L_25 ,
V_126 -> V_136 , V_126 -> error ) ;
V_2 -> V_96 = false ;
return false ;
}
if ( ! ( V_126 -> V_127 & V_213 ) ) {
V_126 -> error = 0 ;
return false ;
}
F_53 ( V_2 , V_126 ) ;
if ( ! V_11 )
return false ;
F_78 ( & V_2 -> V_12 ) ;
if ( V_11 -> V_127 & V_214 ) {
if ( V_2 -> V_20 )
F_11 ( V_2 ) ;
} else {
if ( V_2 -> V_36 )
F_18 ( V_2 ) ;
}
if ( ! V_2 -> V_26 ) {
V_11 -> error = F_57 ( V_2 , V_2 -> V_8 , V_126 -> V_136 ) ;
return ! V_11 -> error ;
}
time = F_79 ( & V_2 -> V_12 ,
V_2 -> V_95 ) ;
if ( V_11 -> V_127 & V_214 )
F_80 ( V_2 -> V_20 -> V_9 -> V_10 ,
V_11 -> V_15 , V_11 -> V_24 ,
V_25 ) ;
else
F_80 ( V_2 -> V_36 -> V_9 -> V_10 ,
V_11 -> V_15 , V_11 -> V_24 ,
V_38 ) ;
if ( V_2 -> V_96 ) {
F_41 ( V_2 -> V_191 -> V_215 ,
L_26 ) ;
V_11 -> error = F_39 ( V_2 ) ;
} else if ( ! time ) {
F_41 ( V_2 -> V_191 -> V_215 , L_27 ) ;
V_11 -> error = - V_106 ;
} else if ( time < 0 ) {
F_41 ( V_2 -> V_191 -> V_215 ,
L_28 , time ) ;
V_11 -> error = time ;
}
F_4 ( V_2 , V_32 ,
V_33 | V_37 ) ;
V_2 -> V_26 = false ;
if ( V_11 -> error ) {
V_11 -> V_216 = 0 ;
if ( V_11 -> V_127 & V_214 )
F_81 ( V_2 -> V_20 ) ;
else
F_81 ( V_2 -> V_36 ) ;
}
return false ;
}
static T_5 F_82 ( int V_217 , void * V_218 )
{
struct V_1 * V_2 = V_218 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
bool V_219 = false ;
unsigned long V_127 ;
int V_220 ;
F_59 ( & V_2 -> V_182 , V_127 ) ;
V_220 = V_2 -> V_104 ;
F_61 ( & V_2 -> V_182 , V_127 ) ;
F_83 ( & V_2 -> V_185 ) ;
F_84 ( & V_2 -> V_221 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_7 ( V_10 , L_29 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
F_85 ( & V_2 -> V_221 ) ;
return V_222 ;
}
switch ( V_220 ) {
case V_223 :
F_85 ( & V_2 -> V_221 ) ;
return V_222 ;
case V_184 :
V_219 = F_77 ( V_2 ) ;
break;
case V_119 :
V_219 = F_48 ( V_2 ) ;
break;
case V_114 :
V_219 = F_46 ( V_2 ) ;
break;
case V_124 :
V_219 = F_52 ( V_2 ) ;
break;
case V_120 :
V_219 = F_50 ( V_2 ) ;
break;
case V_189 :
if ( V_2 -> V_96 ) {
V_8 -> V_188 -> error = F_39 ( V_2 ) ;
F_7 ( V_10 , L_18 , V_34 , V_8 -> V_188 -> error ) ;
break;
}
F_54 ( V_2 , V_8 -> V_188 ) ;
V_8 -> V_188 -> error = 0 ;
break;
case V_118 :
case V_123 :
if ( V_2 -> V_96 ) {
V_8 -> V_11 -> error = F_39 ( V_2 ) ;
F_7 ( V_10 , L_18 , V_34 , V_8 -> V_11 -> error ) ;
}
break;
default:
F_86 () ;
}
if ( V_219 ) {
F_60 ( & V_2 -> V_185 , V_2 -> V_95 ) ;
F_85 ( & V_2 -> V_221 ) ;
return V_222 ;
}
if ( V_2 -> V_104 != V_189 ) {
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_8 -> V_126 -> error && V_11 && ! V_11 -> error )
V_11 -> V_216 =
V_11 -> V_163 * V_11 -> V_178 ;
if ( V_8 -> V_188 && ! V_8 -> V_126 -> error && ( ! V_11 || ! V_11 -> error ) ) {
F_62 ( V_2 , V_8 ) ;
if ( ! V_8 -> V_188 -> error ) {
F_60 ( & V_2 -> V_185 , V_2 -> V_95 ) ;
F_85 ( & V_2 -> V_221 ) ;
return V_222 ;
}
}
}
V_2 -> V_104 = V_223 ;
V_2 -> V_103 = V_192 ;
V_2 -> V_8 = NULL ;
F_65 ( V_2 -> V_191 , V_8 ) ;
F_85 ( & V_2 -> V_221 ) ;
return V_222 ;
}
static T_5 F_87 ( int V_217 , void * V_218 )
{
struct V_1 * V_2 = V_218 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_103 , V_41 ;
V_103 = F_37 ( V_2 -> V_5 , V_179 ) ;
V_41 = F_37 ( V_2 -> V_5 , V_115 ) ;
if ( V_2 -> V_85 )
F_38 ( V_2 -> V_5 , V_179 , ~ ( V_103 & V_41 ) ) ;
else
F_38 ( V_2 -> V_5 , V_179 , V_180 | ~ ( V_103 & V_41 ) ) ;
F_4 ( V_2 , V_115 , V_103 & V_224 ) ;
if ( V_103 & ~ V_224 )
F_7 ( V_10 , L_30 ,
V_103 ) ;
if ( V_103 & V_225 || V_103 & ~ V_226 ) {
V_2 -> V_96 = true ;
F_7 ( V_10 , L_31 , V_103 ) ;
}
if ( V_103 & ~ ( V_227 | V_228 ) ) {
if ( ! V_2 -> V_8 )
F_7 ( V_10 , L_32 , V_103 ) ;
if ( ! V_2 -> V_26 )
return V_229 ;
else if ( V_2 -> V_96 )
F_5 ( V_2 ) ;
} else {
F_7 ( V_10 , L_33 , V_103 ) ;
}
return V_222 ;
}
static void F_88 ( struct V_230 * V_231 )
{
struct V_232 * V_233 = F_89 ( V_231 ) ;
struct V_1 * V_2 = F_90 ( V_233 , struct V_1 , V_185 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
unsigned long V_127 ;
if ( V_2 -> V_234 )
return;
F_59 ( & V_2 -> V_182 , V_127 ) ;
if ( V_2 -> V_103 == V_192 ) {
F_61 ( & V_2 -> V_182 , V_127 ) ;
return;
}
F_41 ( V_10 , L_34 ,
V_2 -> V_104 , V_8 -> V_126 -> V_136 ) ;
V_2 -> V_103 = V_235 ;
F_61 ( & V_2 -> V_182 , V_127 ) ;
switch ( V_2 -> V_104 ) {
case V_184 :
V_8 -> V_126 -> error = F_39 ( V_2 ) ;
break;
case V_189 :
V_8 -> V_188 -> error = F_39 ( V_2 ) ;
break;
case V_119 :
case V_124 :
case V_114 :
case V_120 :
case V_118 :
case V_123 :
V_8 -> V_11 -> error = F_39 ( V_2 ) ;
break;
default:
F_86 () ;
}
V_2 -> V_103 = V_192 ;
V_2 -> V_104 = V_223 ;
V_2 -> V_8 = NULL ;
F_65 ( V_2 -> V_191 , V_8 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_61 * V_50 = V_10 -> V_60 ;
struct V_190 * V_191 = V_2 -> V_191 ;
F_92 ( V_191 ) ;
if ( ! V_50 )
return;
if ( ! V_191 -> V_236 )
V_191 -> V_236 = V_50 -> V_237 ;
else if ( V_50 -> V_237 )
F_17 ( F_93 ( V_191 ) , L_35 ) ;
}
static int F_94 ( struct V_238 * V_239 )
{
int V_23 = 0 , V_217 [ 2 ] ;
struct V_190 * V_191 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = & V_239 -> V_10 ;
struct V_61 * V_50 = V_10 -> V_60 ;
struct V_46 * V_47 ;
void T_6 * V_3 ;
const char * V_240 ;
V_217 [ 0 ] = F_95 ( V_239 , 0 ) ;
V_217 [ 1 ] = F_95 ( V_239 , 1 ) ;
if ( V_217 [ 0 ] < 0 ) {
F_41 ( V_10 , L_36 ) ;
return - V_241 ;
}
V_47 = F_24 ( V_239 , V_51 , 0 ) ;
V_3 = F_96 ( V_10 , V_47 ) ;
if ( F_69 ( V_3 ) )
return F_97 ( V_3 ) ;
V_191 = F_98 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_191 )
return - V_242 ;
V_23 = F_99 ( V_191 ) ;
if ( V_23 < 0 )
goto V_243;
V_2 = F_64 ( V_191 ) ;
V_2 -> V_191 = V_191 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_95 = F_100 ( 10000 ) ;
V_2 -> V_85 = ! V_50 || ! V_50 -> V_244 ;
V_2 -> V_87 = V_50 && V_50 -> V_245 ;
V_2 -> V_50 = V_239 ;
F_101 ( & V_2 -> V_182 ) ;
V_191 -> V_246 = & V_247 ;
F_91 ( V_2 ) ;
V_191 -> V_248 |= V_249 | V_250 ;
V_191 -> V_251 |= V_252 | V_253 ;
V_191 -> V_254 = 10000 ;
if ( V_50 && V_50 -> V_248 )
V_191 -> V_248 |= V_50 -> V_248 ;
V_191 -> V_255 = 32 ;
V_191 -> V_256 = 512 ;
V_191 -> V_257 = V_258 * V_191 -> V_255 ;
V_191 -> V_259 = V_191 -> V_257 / V_191 -> V_256 ;
V_191 -> V_260 = V_191 -> V_257 ;
F_102 ( V_239 , V_2 ) ;
V_2 -> V_65 = F_103 ( V_10 , NULL ) ;
if ( F_69 ( V_2 -> V_65 ) ) {
V_23 = F_97 ( V_2 -> V_65 ) ;
F_41 ( V_10 , L_37 , V_23 ) ;
goto V_243;
}
V_23 = F_71 ( V_2 -> V_65 ) ;
if ( V_23 < 0 )
goto V_243;
F_66 ( V_2 ) ;
F_104 ( V_10 ) ;
V_2 -> V_206 = false ;
V_23 = F_72 ( V_10 ) ;
if ( V_23 < 0 )
goto V_261;
F_105 ( & V_2 -> V_185 , F_88 ) ;
F_36 ( V_2 ) ;
F_38 ( V_2 -> V_5 , V_115 , V_262 ) ;
V_240 = V_217 [ 1 ] < 0 ? F_9 ( V_10 ) : L_38 ;
V_23 = F_106 ( V_10 , V_217 [ 0 ] , F_87 ,
F_82 , 0 , V_240 , V_2 ) ;
if ( V_23 ) {
F_41 ( V_10 , L_39 , V_240 ) ;
goto V_261;
}
if ( V_217 [ 1 ] >= 0 ) {
V_23 = F_106 ( V_10 , V_217 [ 1 ] ,
F_87 , F_82 ,
0 , L_40 , V_2 ) ;
if ( V_23 ) {
F_41 ( V_10 , L_41 ) ;
goto V_261;
}
}
if ( V_50 && V_50 -> V_263 ) {
V_23 = F_107 ( V_191 , V_50 -> V_264 , 0 ) ;
if ( V_23 < 0 )
goto V_261;
}
F_108 ( & V_2 -> V_221 ) ;
V_23 = F_109 ( V_191 ) ;
if ( V_23 < 0 )
goto V_261;
F_110 ( V_10 , 100 ) ;
F_111 ( V_10 , L_42 ,
F_37 ( V_2 -> V_5 , V_82 ) & 0xffff ,
F_31 ( V_2 -> V_65 ) / 1000000UL ) ;
F_73 ( V_10 ) ;
F_74 ( V_2 -> V_65 ) ;
return V_23 ;
V_261:
F_74 ( V_2 -> V_65 ) ;
F_112 ( V_10 ) ;
F_113 ( V_10 ) ;
V_243:
F_114 ( V_191 ) ;
return V_23 ;
}
static int F_115 ( struct V_238 * V_239 )
{
struct V_1 * V_2 = F_116 ( V_239 ) ;
V_2 -> V_234 = true ;
F_71 ( V_2 -> V_65 ) ;
F_72 ( & V_239 -> V_10 ) ;
F_117 ( & V_239 -> V_10 ) ;
F_118 ( V_2 -> V_191 ) ;
F_38 ( V_2 -> V_5 , V_115 , V_262 ) ;
F_83 ( & V_2 -> V_185 ) ;
F_74 ( V_2 -> V_65 ) ;
F_114 ( V_2 -> V_191 ) ;
F_112 ( & V_239 -> V_10 ) ;
F_113 ( & V_239 -> V_10 ) ;
return 0 ;
}
static int F_119 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_120 ( V_10 ) ;
F_72 ( V_10 ) ;
F_38 ( V_2 -> V_5 , V_115 , V_262 ) ;
F_73 ( V_10 ) ;
return 0 ;
}
static int F_121 ( struct V_9 * V_10 )
{
return 0 ;
}
