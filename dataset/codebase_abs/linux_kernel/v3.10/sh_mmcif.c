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
static void F_18 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = F_19 ( V_2 -> V_9 , V_45 , 0 ) ;
struct V_46 V_47 ;
T_3 V_48 ;
int V_23 ;
V_2 -> V_27 = false ;
if ( ! V_42 )
return;
if ( V_42 -> V_49 <= 0 || V_42 -> V_50 <= 0 )
return;
F_20 ( V_48 ) ;
F_21 ( V_51 , V_48 ) ;
V_2 -> V_37 = F_22 ( V_48 , V_52 ,
( void * ) V_42 -> V_49 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_7 , V_35 ,
V_2 -> V_37 ) ;
if ( ! V_2 -> V_37 )
return;
V_47 . V_53 = V_42 -> V_49 ;
V_47 . V_54 = V_40 ;
V_47 . V_55 = V_44 -> V_56 + V_57 ;
V_47 . V_58 = 0 ;
V_23 = F_23 ( V_2 -> V_37 , & V_47 ) ;
if ( V_23 < 0 )
goto V_59;
V_2 -> V_20 = F_22 ( V_48 , V_52 ,
( void * ) V_42 -> V_50 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_8 , V_35 ,
V_2 -> V_20 ) ;
if ( ! V_2 -> V_20 )
goto V_60;
V_47 . V_53 = V_42 -> V_50 ;
V_47 . V_54 = V_28 ;
V_47 . V_55 = 0 ;
V_47 . V_58 = V_44 -> V_56 + V_57 ;
V_23 = F_23 ( V_2 -> V_20 , & V_47 ) ;
if ( V_23 < 0 )
goto V_61;
return;
V_61:
F_15 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_60:
V_59:
F_15 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
static void F_24 ( struct V_1 * V_2 )
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
static void F_25 ( struct V_1 * V_2 , unsigned int V_62 )
{
struct V_41 * V_63 = V_2 -> V_9 -> V_10 . V_64 ;
bool V_65 = V_63 ? V_63 -> V_65 : false ;
F_4 ( V_2 , V_66 , V_67 ) ;
F_4 ( V_2 , V_66 , V_68 ) ;
if ( ! V_62 )
return;
if ( V_65 && V_62 == V_2 -> V_62 )
F_1 ( V_2 , V_66 , V_69 ) ;
else
F_1 ( V_2 , V_66 , V_68 &
( ( F_26 ( F_27 ( V_2 -> V_62 ,
V_62 ) - 1 ) - 1 ) << 16 ) ) ;
F_1 ( V_2 , V_66 , V_67 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_70 ;
V_70 = 0x010f0000 & F_29 ( V_2 -> V_5 , V_66 ) ;
F_30 ( V_2 -> V_5 , V_71 , V_72 ) ;
F_30 ( V_2 -> V_5 , V_71 , V_73 ) ;
F_1 ( V_2 , V_66 , V_70 |
V_74 | V_75 | V_76 | V_77 ) ;
F_1 ( V_2 , V_33 , V_78 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_79 , V_80 ;
int V_23 , V_81 ;
V_2 -> V_82 = false ;
V_79 = F_29 ( V_2 -> V_5 , V_83 ) ;
V_80 = F_29 ( V_2 -> V_5 , V_84 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_9 , V_79 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_10 , V_80 ) ;
if ( V_79 & V_85 ) {
F_1 ( V_2 , V_86 , V_87 ) ;
F_1 ( V_2 , V_86 , ~ V_87 ) ;
for ( V_81 = 10000000 ; V_81 ; V_81 -- ) {
if ( ! ( F_29 ( V_2 -> V_5 , V_83 )
& V_85 ) )
break;
F_32 ( 1 ) ;
}
if ( ! V_81 ) {
F_33 ( & V_2 -> V_9 -> V_10 ,
L_11 ) ;
return - V_36 ;
}
F_28 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_12 ) ;
return - V_36 ;
}
if ( V_80 & V_88 ) {
F_33 ( & V_2 -> V_9 -> V_10 , L_13 ,
V_2 -> V_89 , V_2 -> V_90 ) ;
V_23 = - V_36 ;
} else if ( V_80 & V_91 ) {
F_33 ( & V_2 -> V_9 -> V_10 , L_14 ,
V_2 -> V_89 , V_2 -> V_90 ) ;
V_23 = - V_92 ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_15 ,
V_2 -> V_89 , V_2 -> V_90 ) ;
V_23 = - V_36 ;
}
return V_23 ;
}
static bool F_34 ( struct V_1 * V_2 , T_1 * V_63 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
V_2 -> V_93 += V_2 -> V_94 ;
F_35 ( V_2 -> V_93 > V_11 -> V_15 -> V_95 ) ;
if ( V_2 -> V_93 == V_11 -> V_15 -> V_95 ) {
V_2 -> V_93 = 0 ;
if ( ++ V_2 -> V_96 < V_11 -> V_25 )
V_2 -> V_97 = F_36 ( ++ V_11 -> V_15 ) ;
} else {
V_2 -> V_97 = V_63 ;
}
return V_2 -> V_96 != V_11 -> V_25 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_94 = ( F_29 ( V_2 -> V_5 , V_98 ) &
V_99 ) + 3 ;
V_2 -> V_90 = V_100 ;
F_1 ( V_2 , V_101 , V_102 ) ;
}
static bool F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_63 = F_36 ( V_11 -> V_15 ) ;
int V_103 ;
if ( V_2 -> V_82 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_16 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_94 / 4 ; V_103 ++ )
* V_63 ++ = F_29 ( V_2 -> V_5 , V_57 ) ;
F_1 ( V_2 , V_101 , V_104 ) ;
V_2 -> V_90 = V_105 ;
return true ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_95 )
return;
V_2 -> V_94 = F_29 ( V_2 -> V_5 , V_98 ) &
V_99 ;
V_2 -> V_90 = V_106 ;
V_2 -> V_96 = 0 ;
V_2 -> V_93 = 0 ;
V_2 -> V_97 = F_36 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_101 , V_102 ) ;
}
static bool F_40 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_63 = V_2 -> V_97 ;
int V_103 ;
if ( V_2 -> V_82 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_16 , V_35 , V_11 -> error ) ;
return false ;
}
F_35 ( ! V_11 -> V_15 -> V_95 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_94 / 4 ; V_103 ++ )
* V_63 ++ = F_29 ( V_2 -> V_5 , V_57 ) ;
if ( ! F_34 ( V_2 , V_63 ) )
return false ;
F_1 ( V_2 , V_101 , V_102 ) ;
return true ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_94 = ( F_29 ( V_2 -> V_5 , V_98 ) &
V_99 ) + 3 ;
V_2 -> V_90 = V_107 ;
F_1 ( V_2 , V_101 , V_108 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_63 = F_36 ( V_11 -> V_15 ) ;
int V_103 ;
if ( V_2 -> V_82 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_16 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_94 / 4 ; V_103 ++ )
F_30 ( V_2 -> V_5 , V_57 , * V_63 ++ ) ;
F_1 ( V_2 , V_101 , V_109 ) ;
V_2 -> V_90 = V_110 ;
return true ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_95 )
return;
V_2 -> V_94 = F_29 ( V_2 -> V_5 , V_98 ) &
V_99 ;
V_2 -> V_90 = V_111 ;
V_2 -> V_96 = 0 ;
V_2 -> V_93 = 0 ;
V_2 -> V_97 = F_36 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_101 , V_108 ) ;
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_63 = V_2 -> V_97 ;
int V_103 ;
if ( V_2 -> V_82 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_16 , V_35 , V_11 -> error ) ;
return false ;
}
F_35 ( ! V_11 -> V_15 -> V_95 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_94 / 4 ; V_103 ++ )
F_30 ( V_2 -> V_5 , V_57 , * V_63 ++ ) ;
if ( ! F_34 ( V_2 , V_63 ) )
return false ;
F_1 ( V_2 , V_101 , V_108 ) ;
return true ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
if ( V_113 -> V_114 & V_115 ) {
V_113 -> V_116 [ 0 ] = F_29 ( V_2 -> V_5 , V_117 ) ;
V_113 -> V_116 [ 1 ] = F_29 ( V_2 -> V_5 , V_118 ) ;
V_113 -> V_116 [ 2 ] = F_29 ( V_2 -> V_5 , V_119 ) ;
V_113 -> V_116 [ 3 ] = F_29 ( V_2 -> V_5 , V_120 ) ;
} else
V_113 -> V_116 [ 0 ] = F_29 ( V_2 -> V_5 , V_120 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
V_113 -> V_116 [ 0 ] = F_29 ( V_2 -> V_5 , V_121 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
struct V_112 * V_113 = V_8 -> V_113 ;
T_1 V_122 = V_113 -> V_123 ;
T_1 V_70 = 0 ;
switch ( F_48 ( V_113 ) ) {
case V_124 :
V_70 |= V_125 ;
break;
case V_126 :
case V_127 :
case V_128 :
V_70 |= V_129 ;
break;
case V_130 :
V_70 |= V_131 ;
break;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_17 ) ;
break;
}
switch ( V_122 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_70 |= V_138 ;
break;
}
if ( V_11 ) {
V_70 |= V_139 ;
switch ( V_2 -> V_140 ) {
case V_141 :
V_70 |= V_142 ;
break;
case V_143 :
V_70 |= V_144 ;
break;
case V_145 :
V_70 |= V_146 ;
break;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_18 ) ;
break;
}
switch ( V_2 -> V_147 ) {
case V_148 :
V_70 |= V_149 ;
break;
}
}
if ( V_122 == V_150 || V_122 == V_151 )
V_70 |= V_152 ;
if ( V_122 == V_153 || V_122 == V_151 ) {
V_70 |= V_154 | V_155 ;
F_1 ( V_2 , V_98 ,
V_11 -> V_156 << 16 ) ;
}
if ( V_122 == V_157 || V_122 == V_158 ||
V_122 == V_159 || V_122 == V_160 )
V_70 |= V_161 ;
if ( V_122 == V_157 )
V_70 |= V_162 ;
if ( V_122 == V_158 ||
V_122 == V_159 || V_122 == V_160 )
V_70 |= V_163 ;
return ( V_122 << 24 ) | V_70 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_7 * V_8 , T_1 V_122 )
{
switch ( V_122 ) {
case V_153 :
F_39 ( V_2 , V_8 ) ;
return 0 ;
case V_151 :
F_43 ( V_2 , V_8 ) ;
return 0 ;
case V_150 :
F_41 ( V_2 , V_8 ) ;
return 0 ;
case V_164 :
case V_165 :
F_37 ( V_2 , V_8 ) ;
return 0 ;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_19 , V_122 ) ;
return - V_22 ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_112 * V_113 = V_8 -> V_113 ;
T_1 V_122 = V_113 -> V_123 ;
T_1 V_48 ;
switch ( V_122 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_48 = V_166 | V_167 ;
break;
default:
V_48 = V_166 | V_168 ;
break;
}
if ( V_8 -> V_11 ) {
F_30 ( V_2 -> V_5 , V_98 , 0 ) ;
F_30 ( V_2 -> V_5 , V_98 ,
V_8 -> V_11 -> V_169 ) ;
}
V_122 = F_47 ( V_2 , V_8 ) ;
F_30 ( V_2 -> V_5 , V_170 , 0xD80430C0 ) ;
F_30 ( V_2 -> V_5 , V_101 , V_48 ) ;
F_30 ( V_2 -> V_5 , V_171 , V_113 -> V_6 ) ;
F_30 ( V_2 -> V_5 , V_172 , V_122 ) ;
V_2 -> V_90 = V_173 ;
F_51 ( & V_2 -> V_174 , V_2 -> V_81 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
switch ( V_8 -> V_113 -> V_123 ) {
case V_153 :
F_1 ( V_2 , V_101 , V_175 ) ;
break;
case V_151 :
F_1 ( V_2 , V_101 , V_176 ) ;
break;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_20 ) ;
V_8 -> V_177 -> error = F_31 ( V_2 ) ;
return;
}
V_2 -> V_90 = V_178 ;
}
static void F_53 ( struct V_179 * V_180 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_54 ( V_180 ) ;
unsigned long V_114 ;
F_55 ( & V_2 -> V_181 , V_114 ) ;
if ( V_2 -> V_89 != V_182 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_21 , V_35 , V_2 -> V_89 ) ;
F_56 ( & V_2 -> V_181 , V_114 ) ;
V_8 -> V_113 -> error = - V_183 ;
F_57 ( V_180 , V_8 ) ;
return;
}
V_2 -> V_89 = V_184 ;
F_56 ( & V_2 -> V_181 , V_114 ) ;
switch ( V_8 -> V_113 -> V_123 ) {
case V_132 :
case V_165 :
if ( ( V_8 -> V_113 -> V_114 & V_185 ) != V_186 )
break;
case V_187 :
case V_188 :
V_2 -> V_89 = V_182 ;
V_8 -> V_113 -> error = - V_92 ;
F_57 ( V_180 , V_8 ) ;
return;
default:
break;
}
V_2 -> V_8 = V_8 ;
F_50 ( V_2 , V_8 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_23 = F_59 ( V_2 -> V_189 ) ;
if ( ! V_23 ) {
V_2 -> V_62 = F_60 ( V_2 -> V_189 ) ;
V_2 -> V_180 -> V_190 = V_2 -> V_62 / 2 ;
V_2 -> V_180 -> V_191 = V_2 -> V_62 / 512 ;
}
return V_23 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
struct V_41 * V_9 = V_2 -> V_9 -> V_10 . V_64 ;
struct V_179 * V_180 = V_2 -> V_180 ;
if ( V_9 && V_9 -> V_194 )
V_9 -> V_194 ( V_2 -> V_9 , V_193 -> V_195 != V_196 ) ;
if ( ! F_62 ( V_180 -> V_197 . V_198 ) )
F_63 ( V_180 , V_180 -> V_197 . V_198 ,
V_193 -> V_195 ? V_193 -> V_199 : 0 ) ;
}
static void F_64 ( struct V_179 * V_180 , struct V_192 * V_193 )
{
struct V_1 * V_2 = F_54 ( V_180 ) ;
unsigned long V_114 ;
F_55 ( & V_2 -> V_181 , V_114 ) ;
if ( V_2 -> V_89 != V_182 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_21 , V_35 , V_2 -> V_89 ) ;
F_56 ( & V_2 -> V_181 , V_114 ) ;
return;
}
V_2 -> V_89 = V_200 ;
F_56 ( & V_2 -> V_181 , V_114 ) ;
if ( V_193 -> V_195 == V_201 ) {
if ( ! V_2 -> V_202 ) {
F_18 ( V_2 , V_2 -> V_9 -> V_10 . V_64 ) ;
V_2 -> V_202 = true ;
}
F_61 ( V_2 , V_193 ) ;
} else if ( V_193 -> V_195 == V_196 || ! V_193 -> clock ) {
F_25 ( V_2 , 0 ) ;
if ( V_193 -> V_195 == V_196 ) {
if ( V_2 -> V_202 ) {
F_24 ( V_2 ) ;
V_2 -> V_202 = false ;
}
}
if ( V_2 -> V_203 ) {
F_65 ( & V_2 -> V_9 -> V_10 ) ;
F_66 ( V_2 -> V_189 ) ;
V_2 -> V_203 = false ;
if ( V_193 -> V_195 == V_196 )
F_61 ( V_2 , V_193 ) ;
}
V_2 -> V_89 = V_182 ;
return;
}
if ( V_193 -> clock ) {
if ( ! V_2 -> V_203 ) {
F_58 ( V_2 ) ;
F_67 ( & V_2 -> V_9 -> V_10 ) ;
V_2 -> V_203 = true ;
F_28 ( V_2 ) ;
}
F_25 ( V_2 , V_193 -> clock ) ;
}
V_2 -> V_147 = V_193 -> V_147 ;
V_2 -> V_140 = V_193 -> V_140 ;
V_2 -> V_89 = V_182 ;
}
static int F_68 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = F_54 ( V_180 ) ;
struct V_41 * V_63 = V_2 -> V_9 -> V_10 . V_64 ;
int V_23 = F_69 ( V_180 ) ;
if ( V_23 >= 0 )
return V_23 ;
if ( ! V_63 || ! V_63 -> V_204 )
return - V_205 ;
else
return V_63 -> V_204 ( V_2 -> V_9 ) ;
}
static bool F_70 ( struct V_1 * V_2 )
{
struct V_112 * V_113 = V_2 -> V_8 -> V_113 ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
long time ;
if ( V_2 -> V_82 ) {
switch ( V_113 -> V_123 ) {
case V_158 :
case V_206 :
case V_187 :
V_113 -> error = - V_92 ;
break;
default:
V_113 -> error = F_31 ( V_2 ) ;
break;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_22 ,
V_113 -> V_123 , V_113 -> error ) ;
V_2 -> V_82 = false ;
return false ;
}
if ( ! ( V_113 -> V_114 & V_207 ) ) {
V_113 -> error = 0 ;
return false ;
}
F_45 ( V_2 , V_113 ) ;
if ( ! V_11 )
return false ;
F_71 ( & V_2 -> V_12 ) ;
if ( V_11 -> V_114 & V_208 ) {
if ( V_2 -> V_20 )
F_10 ( V_2 ) ;
} else {
if ( V_2 -> V_37 )
F_17 ( V_2 ) ;
}
if ( ! V_2 -> V_27 ) {
V_11 -> error = F_49 ( V_2 , V_2 -> V_8 , V_113 -> V_123 ) ;
return ! V_11 -> error ;
}
time = F_72 ( & V_2 -> V_12 ,
V_2 -> V_81 ) ;
if ( V_11 -> V_114 & V_208 )
F_73 ( V_2 -> V_20 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_26 ) ;
else
F_73 ( V_2 -> V_37 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_39 ) ;
if ( V_2 -> V_82 ) {
F_33 ( V_2 -> V_180 -> V_209 ,
L_23 ) ;
V_11 -> error = F_31 ( V_2 ) ;
} else if ( ! time ) {
F_33 ( V_2 -> V_180 -> V_209 , L_24 ) ;
V_11 -> error = - V_92 ;
} else if ( time < 0 ) {
F_33 ( V_2 -> V_180 -> V_209 ,
L_25 , time ) ;
V_11 -> error = time ;
}
F_4 ( V_2 , V_33 ,
V_34 | V_38 ) ;
V_2 -> V_27 = false ;
if ( V_11 -> error ) {
V_11 -> V_210 = 0 ;
if ( V_11 -> V_114 & V_208 )
F_74 ( V_2 -> V_20 ) ;
else
F_74 ( V_2 -> V_37 ) ;
}
return false ;
}
static T_4 F_75 ( int V_211 , void * V_212 )
{
struct V_1 * V_2 = V_212 ;
struct V_7 * V_8 ;
bool V_213 = false ;
F_76 ( & V_2 -> V_174 ) ;
F_77 ( & V_2 -> V_214 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_26 ,
V_2 -> V_89 , V_2 -> V_90 ) ;
F_78 ( & V_2 -> V_214 ) ;
return V_215 ;
}
switch ( V_2 -> V_90 ) {
case V_216 :
F_78 ( & V_2 -> V_214 ) ;
return V_215 ;
case V_173 :
V_213 = F_70 ( V_2 ) ;
break;
case V_106 :
V_213 = F_40 ( V_2 ) ;
break;
case V_100 :
V_213 = F_38 ( V_2 ) ;
break;
case V_111 :
V_213 = F_44 ( V_2 ) ;
break;
case V_107 :
V_213 = F_42 ( V_2 ) ;
break;
case V_178 :
if ( V_2 -> V_82 ) {
V_8 -> V_177 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_16 , V_35 , V_8 -> V_177 -> error ) ;
break;
}
F_46 ( V_2 , V_8 -> V_177 ) ;
V_8 -> V_177 -> error = 0 ;
break;
case V_105 :
case V_110 :
if ( V_2 -> V_82 ) {
V_8 -> V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_16 , V_35 , V_8 -> V_11 -> error ) ;
}
break;
default:
F_79 () ;
}
if ( V_213 ) {
F_51 ( & V_2 -> V_174 , V_2 -> V_81 ) ;
F_78 ( & V_2 -> V_214 ) ;
return V_215 ;
}
if ( V_2 -> V_90 != V_178 ) {
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_8 -> V_113 -> error && V_11 && ! V_11 -> error )
V_11 -> V_210 =
V_11 -> V_156 * V_11 -> V_169 ;
if ( V_8 -> V_177 && ! V_8 -> V_113 -> error && ( ! V_11 || ! V_11 -> error ) ) {
F_52 ( V_2 , V_8 ) ;
if ( ! V_8 -> V_177 -> error ) {
F_51 ( & V_2 -> V_174 , V_2 -> V_81 ) ;
F_78 ( & V_2 -> V_214 ) ;
return V_215 ;
}
}
}
V_2 -> V_90 = V_216 ;
V_2 -> V_89 = V_182 ;
V_2 -> V_8 = NULL ;
F_57 ( V_2 -> V_180 , V_8 ) ;
F_78 ( & V_2 -> V_214 ) ;
return V_215 ;
}
static T_4 F_80 ( int V_211 , void * V_212 )
{
struct V_1 * V_2 = V_212 ;
T_1 V_89 ;
V_89 = F_29 ( V_2 -> V_5 , V_170 ) ;
F_30 ( V_2 -> V_5 , V_170 , ~ V_89 ) ;
F_4 ( V_2 , V_101 , V_89 & V_217 ) ;
if ( V_89 & ~ V_217 )
F_6 ( & V_2 -> V_9 -> V_10 , L_27 ,
V_89 ) ;
if ( V_89 & V_218 || V_89 & ~ V_219 ) {
V_2 -> V_82 = true ;
F_6 ( & V_2 -> V_9 -> V_10 , L_28 , V_89 ) ;
}
if ( V_89 & ~ ( V_220 | V_221 ) ) {
if ( ! V_2 -> V_8 )
F_6 ( & V_2 -> V_9 -> V_10 , L_29 , V_89 ) ;
if ( ! V_2 -> V_27 )
return V_222 ;
else if ( V_2 -> V_82 )
F_5 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_30 , V_89 ) ;
}
return V_215 ;
}
static void F_81 ( struct V_223 * V_224 )
{
struct V_225 * V_226 = F_82 ( V_224 , struct V_225 , V_224 ) ;
struct V_1 * V_2 = F_82 ( V_226 , struct V_1 , V_174 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_114 ;
if ( V_2 -> V_227 )
return;
F_33 ( & V_2 -> V_9 -> V_10 , L_31 ,
V_2 -> V_90 , V_8 -> V_113 -> V_123 ) ;
F_55 ( & V_2 -> V_181 , V_114 ) ;
if ( V_2 -> V_89 == V_182 ) {
F_56 ( & V_2 -> V_181 , V_114 ) ;
return;
}
V_2 -> V_89 = V_228 ;
F_56 ( & V_2 -> V_181 , V_114 ) ;
switch ( V_2 -> V_90 ) {
case V_173 :
V_8 -> V_113 -> error = F_31 ( V_2 ) ;
break;
case V_178 :
V_8 -> V_177 -> error = F_31 ( V_2 ) ;
break;
case V_106 :
case V_111 :
case V_100 :
case V_107 :
case V_105 :
case V_110 :
V_8 -> V_11 -> error = F_31 ( V_2 ) ;
break;
default:
F_79 () ;
}
V_2 -> V_89 = V_182 ;
V_2 -> V_90 = V_216 ;
V_2 -> V_8 = NULL ;
F_57 ( V_2 -> V_180 , V_8 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_41 * V_9 = V_2 -> V_9 -> V_10 . V_64 ;
struct V_179 * V_180 = V_2 -> V_180 ;
F_84 ( V_180 ) ;
if ( ! V_9 )
return;
if ( ! V_180 -> V_229 )
V_180 -> V_229 = V_9 -> V_230 ;
else if ( V_9 -> V_230 )
F_16 ( F_85 ( V_180 ) , L_32 ) ;
}
static int F_86 ( struct V_231 * V_232 )
{
int V_23 = 0 , V_211 [ 2 ] ;
struct V_179 * V_180 ;
struct V_1 * V_2 ;
struct V_41 * V_9 = V_232 -> V_10 . V_64 ;
struct V_43 * V_44 ;
void T_5 * V_3 ;
const char * V_233 ;
V_211 [ 0 ] = F_87 ( V_232 , 0 ) ;
V_211 [ 1 ] = F_87 ( V_232 , 1 ) ;
if ( V_211 [ 0 ] < 0 ) {
F_33 ( & V_232 -> V_10 , L_33 ) ;
return - V_234 ;
}
V_44 = F_19 ( V_232 , V_45 , 0 ) ;
if ( ! V_44 ) {
F_33 ( & V_232 -> V_10 , L_34 ) ;
return - V_234 ;
}
V_3 = F_88 ( V_44 -> V_56 , F_89 ( V_44 ) ) ;
if ( ! V_3 ) {
F_33 ( & V_232 -> V_10 , L_35 ) ;
return - V_235 ;
}
V_180 = F_90 ( sizeof( struct V_1 ) , & V_232 -> V_10 ) ;
if ( ! V_180 ) {
V_23 = - V_235 ;
goto V_236;
}
F_91 ( V_180 ) ;
V_2 = F_54 ( V_180 ) ;
V_2 -> V_180 = V_180 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_81 = F_92 ( 1000 ) ;
V_2 -> V_9 = V_232 ;
F_93 ( & V_2 -> V_181 ) ;
V_180 -> V_237 = & V_238 ;
F_83 ( V_2 ) ;
V_180 -> V_239 |= V_240 | V_241 ;
if ( V_9 && V_9 -> V_239 )
V_180 -> V_239 |= V_9 -> V_239 ;
V_180 -> V_242 = 32 ;
V_180 -> V_243 = 512 ;
V_180 -> V_244 = V_245 * V_180 -> V_242 ;
V_180 -> V_246 = V_180 -> V_244 / V_180 -> V_243 ;
V_180 -> V_247 = V_180 -> V_244 ;
F_94 ( V_232 , V_2 ) ;
F_95 ( & V_232 -> V_10 ) ;
V_2 -> V_203 = false ;
V_2 -> V_189 = F_96 ( & V_232 -> V_10 , NULL ) ;
if ( F_62 ( V_2 -> V_189 ) ) {
V_23 = F_97 ( V_2 -> V_189 ) ;
F_33 ( & V_232 -> V_10 , L_36 , V_23 ) ;
goto V_248;
}
V_23 = F_58 ( V_2 ) ;
if ( V_23 < 0 )
goto V_249;
V_23 = F_98 ( & V_232 -> V_10 ) ;
if ( V_23 < 0 )
goto V_250;
F_99 ( & V_2 -> V_174 , F_81 ) ;
F_28 ( V_2 ) ;
F_30 ( V_2 -> V_5 , V_101 , V_251 ) ;
V_233 = V_211 [ 1 ] < 0 ? F_8 ( & V_232 -> V_10 ) : L_37 ;
V_23 = F_100 ( V_211 [ 0 ] , F_80 , F_75 , 0 , V_233 , V_2 ) ;
if ( V_23 ) {
F_33 ( & V_232 -> V_10 , L_38 , V_233 ) ;
goto V_252;
}
if ( V_211 [ 1 ] >= 0 ) {
V_23 = F_100 ( V_211 [ 1 ] , F_80 , F_75 ,
0 , L_39 , V_2 ) ;
if ( V_23 ) {
F_33 ( & V_232 -> V_10 , L_40 ) ;
goto V_253;
}
}
if ( V_9 && V_9 -> V_254 ) {
V_23 = F_101 ( V_180 , V_9 -> V_255 ) ;
if ( V_23 < 0 )
goto V_256;
}
F_102 ( & V_2 -> V_214 ) ;
F_66 ( V_2 -> V_189 ) ;
V_23 = F_103 ( V_180 ) ;
if ( V_23 < 0 )
goto V_257;
F_104 ( & V_232 -> V_10 , 100 ) ;
F_105 ( & V_232 -> V_10 , L_41 , V_258 ) ;
F_6 ( & V_232 -> V_10 , L_42 ,
F_29 ( V_2 -> V_5 , V_71 ) & 0x0000ffff ) ;
return V_23 ;
V_257:
V_256:
if ( V_211 [ 1 ] >= 0 )
F_106 ( V_211 [ 1 ] , V_2 ) ;
V_253:
F_106 ( V_211 [ 0 ] , V_2 ) ;
V_252:
F_107 ( & V_232 -> V_10 ) ;
V_250:
F_66 ( V_2 -> V_189 ) ;
V_249:
F_108 ( V_2 -> V_189 ) ;
V_248:
F_109 ( & V_232 -> V_10 ) ;
F_110 ( V_180 ) ;
V_236:
F_111 ( V_3 ) ;
return V_23 ;
}
static int F_112 ( struct V_231 * V_232 )
{
struct V_1 * V_2 = F_113 ( V_232 ) ;
int V_211 [ 2 ] ;
V_2 -> V_227 = true ;
F_59 ( V_2 -> V_189 ) ;
F_67 ( & V_232 -> V_10 ) ;
F_114 ( & V_232 -> V_10 ) ;
F_115 ( V_2 -> V_180 ) ;
F_30 ( V_2 -> V_5 , V_101 , V_251 ) ;
F_76 ( & V_2 -> V_174 ) ;
if ( V_2 -> V_5 )
F_111 ( V_2 -> V_5 ) ;
V_211 [ 0 ] = F_87 ( V_232 , 0 ) ;
V_211 [ 1 ] = F_87 ( V_232 , 1 ) ;
F_106 ( V_211 [ 0 ] , V_2 ) ;
if ( V_211 [ 1 ] >= 0 )
F_106 ( V_211 [ 1 ] , V_2 ) ;
F_94 ( V_232 , NULL ) ;
F_66 ( V_2 -> V_189 ) ;
F_110 ( V_2 -> V_180 ) ;
F_65 ( & V_232 -> V_10 ) ;
F_109 ( & V_232 -> V_10 ) ;
return 0 ;
}
static int F_116 ( struct V_24 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
int V_23 = F_118 ( V_2 -> V_180 ) ;
if ( ! V_23 )
F_30 ( V_2 -> V_5 , V_101 , V_251 ) ;
return V_23 ;
}
static int F_119 ( struct V_24 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
return F_120 ( V_2 -> V_180 ) ;
}
