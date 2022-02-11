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
if ( V_42 ) {
if ( V_42 -> V_49 <= 0 || V_42 -> V_50 <= 0 )
return;
} else if ( ! V_2 -> V_9 -> V_10 . V_51 ) {
return;
}
F_20 ( V_48 ) ;
F_21 ( V_52 , V_48 ) ;
V_2 -> V_37 = F_22 ( V_48 , V_53 ,
V_42 ? ( void * ) V_42 -> V_49 : NULL ,
& V_2 -> V_9 -> V_10 , L_7 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_8 , V_35 ,
V_2 -> V_37 ) ;
if ( ! V_2 -> V_37 )
return;
if ( V_42 )
V_47 . V_54 = V_42 -> V_49 ;
V_47 . V_55 = V_40 ;
V_47 . V_56 = V_44 -> V_57 + V_58 ;
V_47 . V_59 = 0 ;
V_23 = F_23 ( V_2 -> V_37 , & V_47 ) ;
if ( V_23 < 0 )
goto V_60;
V_2 -> V_20 = F_22 ( V_48 , V_53 ,
V_42 ? ( void * ) V_42 -> V_50 : NULL ,
& V_2 -> V_9 -> V_10 , L_9 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_10 , V_35 ,
V_2 -> V_20 ) ;
if ( ! V_2 -> V_20 )
goto V_61;
if ( V_42 )
V_47 . V_54 = V_42 -> V_50 ;
V_47 . V_55 = V_28 ;
V_47 . V_56 = 0 ;
V_47 . V_59 = V_44 -> V_57 + V_58 ;
V_23 = F_23 ( V_2 -> V_20 , & V_47 ) ;
if ( V_23 < 0 )
goto V_62;
return;
V_62:
F_15 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_61:
V_60:
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
static void F_25 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_41 * V_64 = V_2 -> V_9 -> V_10 . V_65 ;
bool V_66 = V_64 ? V_64 -> V_66 : false ;
F_4 ( V_2 , V_67 , V_68 ) ;
F_4 ( V_2 , V_67 , V_69 ) ;
if ( ! V_63 )
return;
if ( V_66 && V_63 == V_2 -> V_63 )
F_1 ( V_2 , V_67 , V_70 ) ;
else
F_1 ( V_2 , V_67 , V_69 &
( ( F_26 ( F_27 ( V_2 -> V_63 ,
V_63 ) - 1 ) - 1 ) << 16 ) ) ;
F_1 ( V_2 , V_67 , V_68 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_71 ;
V_71 = 0x010f0000 & F_29 ( V_2 -> V_5 , V_67 ) ;
F_30 ( V_2 -> V_5 , V_72 , V_73 ) ;
F_30 ( V_2 -> V_5 , V_72 , V_74 ) ;
if ( V_2 -> V_75 )
V_71 |= V_76 ;
if ( V_2 -> V_77 )
F_30 ( V_2 -> V_5 , V_78 , 0x0F0F0000 ) ;
F_1 ( V_2 , V_67 , V_71 |
V_79 | V_80 | V_81 ) ;
F_1 ( V_2 , V_33 , V_82 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_83 , V_84 ;
int V_23 , V_85 ;
V_2 -> V_86 = false ;
V_83 = F_29 ( V_2 -> V_5 , V_87 ) ;
V_84 = F_29 ( V_2 -> V_5 , V_88 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_11 , V_83 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_12 , V_84 ) ;
if ( V_83 & V_89 ) {
F_1 ( V_2 , V_90 , V_91 ) ;
F_1 ( V_2 , V_90 , ~ V_91 ) ;
for ( V_85 = 10000000 ; V_85 ; V_85 -- ) {
if ( ! ( F_29 ( V_2 -> V_5 , V_87 )
& V_89 ) )
break;
F_32 ( 1 ) ;
}
if ( ! V_85 ) {
F_33 ( & V_2 -> V_9 -> V_10 ,
L_13 ) ;
return - V_36 ;
}
F_28 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_14 ) ;
return - V_36 ;
}
if ( V_84 & V_92 ) {
F_33 ( & V_2 -> V_9 -> V_10 , L_15 ,
V_2 -> V_93 , V_2 -> V_94 ) ;
V_23 = - V_36 ;
} else if ( V_84 & V_95 ) {
F_33 ( & V_2 -> V_9 -> V_10 , L_16 ,
V_2 -> V_93 , V_2 -> V_94 ) ;
V_23 = - V_96 ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_17 ,
V_2 -> V_93 , V_2 -> V_94 ) ;
V_23 = - V_36 ;
}
return V_23 ;
}
static bool F_34 ( struct V_1 * V_2 , T_1 * V_64 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
V_2 -> V_97 += V_2 -> V_98 ;
F_35 ( V_2 -> V_97 > V_11 -> V_15 -> V_99 ) ;
if ( V_2 -> V_97 == V_11 -> V_15 -> V_99 ) {
V_2 -> V_97 = 0 ;
if ( ++ V_2 -> V_100 < V_11 -> V_25 )
V_2 -> V_101 = F_36 ( ++ V_11 -> V_15 ) ;
} else {
V_2 -> V_101 = V_64 ;
}
return V_2 -> V_100 != V_11 -> V_25 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_98 = ( F_29 ( V_2 -> V_5 , V_102 ) &
V_103 ) + 3 ;
V_2 -> V_94 = V_104 ;
F_1 ( V_2 , V_105 , V_106 ) ;
}
static bool F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_64 = F_36 ( V_11 -> V_15 ) ;
int V_107 ;
if ( V_2 -> V_86 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_18 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_107 = 0 ; V_107 < V_2 -> V_98 / 4 ; V_107 ++ )
* V_64 ++ = F_29 ( V_2 -> V_5 , V_58 ) ;
F_1 ( V_2 , V_105 , V_108 ) ;
V_2 -> V_94 = V_109 ;
return true ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_99 )
return;
V_2 -> V_98 = F_29 ( V_2 -> V_5 , V_102 ) &
V_103 ;
V_2 -> V_94 = V_110 ;
V_2 -> V_100 = 0 ;
V_2 -> V_97 = 0 ;
V_2 -> V_101 = F_36 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_105 , V_106 ) ;
}
static bool F_40 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_64 = V_2 -> V_101 ;
int V_107 ;
if ( V_2 -> V_86 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_18 , V_35 , V_11 -> error ) ;
return false ;
}
F_35 ( ! V_11 -> V_15 -> V_99 ) ;
for ( V_107 = 0 ; V_107 < V_2 -> V_98 / 4 ; V_107 ++ )
* V_64 ++ = F_29 ( V_2 -> V_5 , V_58 ) ;
if ( ! F_34 ( V_2 , V_64 ) )
return false ;
F_1 ( V_2 , V_105 , V_106 ) ;
return true ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_98 = ( F_29 ( V_2 -> V_5 , V_102 ) &
V_103 ) + 3 ;
V_2 -> V_94 = V_111 ;
F_1 ( V_2 , V_105 , V_112 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_64 = F_36 ( V_11 -> V_15 ) ;
int V_107 ;
if ( V_2 -> V_86 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_18 , V_35 , V_11 -> error ) ;
return false ;
}
for ( V_107 = 0 ; V_107 < V_2 -> V_98 / 4 ; V_107 ++ )
F_30 ( V_2 -> V_5 , V_58 , * V_64 ++ ) ;
F_1 ( V_2 , V_105 , V_113 ) ;
V_2 -> V_94 = V_114 ;
return true ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_11 -> V_25 || ! V_11 -> V_15 -> V_99 )
return;
V_2 -> V_98 = F_29 ( V_2 -> V_5 , V_102 ) &
V_103 ;
V_2 -> V_94 = V_115 ;
V_2 -> V_100 = 0 ;
V_2 -> V_97 = 0 ;
V_2 -> V_101 = F_36 ( V_11 -> V_15 ) ;
F_1 ( V_2 , V_105 , V_112 ) ;
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
T_1 * V_64 = V_2 -> V_101 ;
int V_107 ;
if ( V_2 -> V_86 ) {
V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_18 , V_35 , V_11 -> error ) ;
return false ;
}
F_35 ( ! V_11 -> V_15 -> V_99 ) ;
for ( V_107 = 0 ; V_107 < V_2 -> V_98 / 4 ; V_107 ++ )
F_30 ( V_2 -> V_5 , V_58 , * V_64 ++ ) ;
if ( ! F_34 ( V_2 , V_64 ) )
return false ;
F_1 ( V_2 , V_105 , V_112 ) ;
return true ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
if ( V_117 -> V_118 & V_119 ) {
V_117 -> V_120 [ 0 ] = F_29 ( V_2 -> V_5 , V_121 ) ;
V_117 -> V_120 [ 1 ] = F_29 ( V_2 -> V_5 , V_122 ) ;
V_117 -> V_120 [ 2 ] = F_29 ( V_2 -> V_5 , V_123 ) ;
V_117 -> V_120 [ 3 ] = F_29 ( V_2 -> V_5 , V_124 ) ;
} else
V_117 -> V_120 [ 0 ] = F_29 ( V_2 -> V_5 , V_124 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
V_117 -> V_120 [ 0 ] = F_29 ( V_2 -> V_5 , V_125 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_11 = V_8 -> V_11 ;
struct V_116 * V_117 = V_8 -> V_117 ;
T_1 V_126 = V_117 -> V_127 ;
T_1 V_71 = 0 ;
switch ( F_48 ( V_117 ) ) {
case V_128 :
V_71 |= V_129 ;
break;
case V_130 :
case V_131 :
case V_132 :
V_71 |= V_133 ;
break;
case V_134 :
V_71 |= V_135 ;
break;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_19 ) ;
break;
}
switch ( V_126 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
V_71 |= V_142 ;
break;
}
if ( V_11 ) {
V_71 |= V_143 ;
switch ( V_2 -> V_144 ) {
case V_145 :
V_71 |= V_146 ;
break;
case V_147 :
V_71 |= V_148 ;
break;
case V_149 :
V_71 |= V_150 ;
break;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_20 ) ;
break;
}
switch ( V_2 -> V_151 ) {
case V_152 :
V_71 |= V_153 ;
break;
}
}
if ( V_126 == V_154 || V_126 == V_155 )
V_71 |= V_156 ;
if ( V_126 == V_157 || V_126 == V_155 ) {
V_71 |= V_158 | V_159 ;
F_1 ( V_2 , V_102 ,
V_11 -> V_160 << 16 ) ;
}
if ( V_126 == V_161 || V_126 == V_162 ||
V_126 == V_163 || V_126 == V_164 )
V_71 |= V_165 ;
if ( V_126 == V_161 )
V_71 |= V_166 ;
if ( V_126 == V_162 ||
V_126 == V_163 || V_126 == V_164 )
V_71 |= V_167 ;
return ( V_126 << 24 ) | V_71 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_7 * V_8 , T_1 V_126 )
{
switch ( V_126 ) {
case V_157 :
F_39 ( V_2 , V_8 ) ;
return 0 ;
case V_155 :
F_43 ( V_2 , V_8 ) ;
return 0 ;
case V_154 :
F_41 ( V_2 , V_8 ) ;
return 0 ;
case V_168 :
case V_169 :
F_37 ( V_2 , V_8 ) ;
return 0 ;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_21 , V_126 ) ;
return - V_22 ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_116 * V_117 = V_8 -> V_117 ;
T_1 V_126 = V_117 -> V_127 ;
T_1 V_48 ;
switch ( V_126 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
V_48 = V_170 | V_171 ;
break;
default:
V_48 = V_170 | V_172 ;
break;
}
if ( V_2 -> V_75 )
V_48 |= V_173 ;
if ( V_8 -> V_11 ) {
F_30 ( V_2 -> V_5 , V_102 , 0 ) ;
F_30 ( V_2 -> V_5 , V_102 ,
V_8 -> V_11 -> V_174 ) ;
}
V_126 = F_47 ( V_2 , V_8 ) ;
if ( V_2 -> V_75 )
F_30 ( V_2 -> V_5 , V_175 , 0xD80430C0 ) ;
else
F_30 ( V_2 -> V_5 , V_175 , 0xD80430C0 | V_176 ) ;
F_30 ( V_2 -> V_5 , V_105 , V_48 ) ;
F_30 ( V_2 -> V_5 , V_177 , V_117 -> V_6 ) ;
F_30 ( V_2 -> V_5 , V_178 , V_126 ) ;
V_2 -> V_94 = V_179 ;
F_51 ( & V_2 -> V_180 , V_2 -> V_85 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
switch ( V_8 -> V_117 -> V_127 ) {
case V_157 :
F_1 ( V_2 , V_105 , V_181 ) ;
break;
case V_155 :
F_1 ( V_2 , V_105 , V_182 ) ;
break;
default:
F_33 ( & V_2 -> V_9 -> V_10 , L_22 ) ;
V_8 -> V_183 -> error = F_31 ( V_2 ) ;
return;
}
V_2 -> V_94 = V_184 ;
}
static void F_53 ( struct V_185 * V_186 , struct V_7 * V_8 )
{
struct V_1 * V_2 = F_54 ( V_186 ) ;
unsigned long V_118 ;
F_55 ( & V_2 -> V_187 , V_118 ) ;
if ( V_2 -> V_93 != V_188 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_23 , V_35 , V_2 -> V_93 ) ;
F_56 ( & V_2 -> V_187 , V_118 ) ;
V_8 -> V_117 -> error = - V_189 ;
F_57 ( V_186 , V_8 ) ;
return;
}
V_2 -> V_93 = V_190 ;
F_56 ( & V_2 -> V_187 , V_118 ) ;
switch ( V_8 -> V_117 -> V_127 ) {
case V_136 :
case V_169 :
if ( ( V_8 -> V_117 -> V_118 & V_191 ) != V_192 )
break;
case V_193 :
case V_194 :
V_2 -> V_93 = V_188 ;
V_8 -> V_117 -> error = - V_96 ;
F_57 ( V_186 , V_8 ) ;
return;
default:
break;
}
V_2 -> V_8 = V_8 ;
F_50 ( V_2 , V_8 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_23 = F_59 ( V_2 -> V_195 ) ;
if ( ! V_23 ) {
V_2 -> V_63 = F_60 ( V_2 -> V_195 ) ;
V_2 -> V_186 -> V_196 = V_2 -> V_63 / 2 ;
V_2 -> V_186 -> V_197 = V_2 -> V_63 / 512 ;
}
return V_23 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_198 * V_199 )
{
struct V_185 * V_186 = V_2 -> V_186 ;
if ( ! F_62 ( V_186 -> V_200 . V_201 ) )
F_63 ( V_186 , V_186 -> V_200 . V_201 ,
V_199 -> V_202 ? V_199 -> V_203 : 0 ) ;
}
static void F_64 ( struct V_185 * V_186 , struct V_198 * V_199 )
{
struct V_1 * V_2 = F_54 ( V_186 ) ;
unsigned long V_118 ;
F_55 ( & V_2 -> V_187 , V_118 ) ;
if ( V_2 -> V_93 != V_188 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_23 , V_35 , V_2 -> V_93 ) ;
F_56 ( & V_2 -> V_187 , V_118 ) ;
return;
}
V_2 -> V_93 = V_204 ;
F_56 ( & V_2 -> V_187 , V_118 ) ;
if ( V_199 -> V_202 == V_205 ) {
if ( ! V_2 -> V_206 ) {
F_18 ( V_2 , V_2 -> V_9 -> V_10 . V_65 ) ;
V_2 -> V_206 = true ;
}
F_61 ( V_2 , V_199 ) ;
} else if ( V_199 -> V_202 == V_207 || ! V_199 -> clock ) {
F_25 ( V_2 , 0 ) ;
if ( V_199 -> V_202 == V_207 ) {
if ( V_2 -> V_206 ) {
F_24 ( V_2 ) ;
V_2 -> V_206 = false ;
}
}
if ( V_2 -> V_208 ) {
F_65 ( & V_2 -> V_9 -> V_10 ) ;
F_66 ( V_2 -> V_195 ) ;
V_2 -> V_208 = false ;
if ( V_199 -> V_202 == V_207 )
F_61 ( V_2 , V_199 ) ;
}
V_2 -> V_93 = V_188 ;
return;
}
if ( V_199 -> clock ) {
if ( ! V_2 -> V_208 ) {
F_58 ( V_2 ) ;
F_67 ( & V_2 -> V_9 -> V_10 ) ;
V_2 -> V_208 = true ;
F_28 ( V_2 ) ;
}
F_25 ( V_2 , V_199 -> clock ) ;
}
V_2 -> V_151 = V_199 -> V_151 ;
V_2 -> V_144 = V_199 -> V_144 ;
V_2 -> V_93 = V_188 ;
}
static int F_68 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_54 ( V_186 ) ;
struct V_41 * V_64 = V_2 -> V_9 -> V_10 . V_65 ;
int V_23 = F_69 ( V_186 ) ;
if ( V_23 >= 0 )
return V_23 ;
if ( ! V_64 || ! V_64 -> V_209 )
return - V_210 ;
else
return V_64 -> V_209 ( V_2 -> V_9 ) ;
}
static bool F_70 ( struct V_1 * V_2 )
{
struct V_116 * V_117 = V_2 -> V_8 -> V_117 ;
struct V_13 * V_11 = V_2 -> V_8 -> V_11 ;
long time ;
if ( V_2 -> V_86 ) {
switch ( V_117 -> V_127 ) {
case V_162 :
case V_211 :
case V_193 :
V_117 -> error = - V_96 ;
break;
default:
V_117 -> error = F_31 ( V_2 ) ;
break;
}
F_6 ( & V_2 -> V_9 -> V_10 , L_24 ,
V_117 -> V_127 , V_117 -> error ) ;
V_2 -> V_86 = false ;
return false ;
}
if ( ! ( V_117 -> V_118 & V_212 ) ) {
V_117 -> error = 0 ;
return false ;
}
F_45 ( V_2 , V_117 ) ;
if ( ! V_11 )
return false ;
F_71 ( & V_2 -> V_12 ) ;
if ( V_11 -> V_118 & V_213 ) {
if ( V_2 -> V_20 )
F_10 ( V_2 ) ;
} else {
if ( V_2 -> V_37 )
F_17 ( V_2 ) ;
}
if ( ! V_2 -> V_27 ) {
V_11 -> error = F_49 ( V_2 , V_2 -> V_8 , V_117 -> V_127 ) ;
return ! V_11 -> error ;
}
time = F_72 ( & V_2 -> V_12 ,
V_2 -> V_85 ) ;
if ( V_11 -> V_118 & V_213 )
F_73 ( V_2 -> V_20 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_26 ) ;
else
F_73 ( V_2 -> V_37 -> V_24 -> V_10 ,
V_11 -> V_15 , V_11 -> V_25 ,
V_39 ) ;
if ( V_2 -> V_86 ) {
F_33 ( V_2 -> V_186 -> V_214 ,
L_25 ) ;
V_11 -> error = F_31 ( V_2 ) ;
} else if ( ! time ) {
F_33 ( V_2 -> V_186 -> V_214 , L_26 ) ;
V_11 -> error = - V_96 ;
} else if ( time < 0 ) {
F_33 ( V_2 -> V_186 -> V_214 ,
L_27 , time ) ;
V_11 -> error = time ;
}
F_4 ( V_2 , V_33 ,
V_34 | V_38 ) ;
V_2 -> V_27 = false ;
if ( V_11 -> error ) {
V_11 -> V_215 = 0 ;
if ( V_11 -> V_118 & V_213 )
F_74 ( V_2 -> V_20 ) ;
else
F_74 ( V_2 -> V_37 ) ;
}
return false ;
}
static T_4 F_75 ( int V_216 , void * V_217 )
{
struct V_1 * V_2 = V_217 ;
struct V_7 * V_8 ;
bool V_218 = false ;
F_76 ( & V_2 -> V_180 ) ;
F_77 ( & V_2 -> V_219 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 ) {
F_6 ( & V_2 -> V_9 -> V_10 , L_28 ,
V_2 -> V_93 , V_2 -> V_94 ) ;
F_78 ( & V_2 -> V_219 ) ;
return V_220 ;
}
switch ( V_2 -> V_94 ) {
case V_221 :
F_78 ( & V_2 -> V_219 ) ;
return V_220 ;
case V_179 :
V_218 = F_70 ( V_2 ) ;
break;
case V_110 :
V_218 = F_40 ( V_2 ) ;
break;
case V_104 :
V_218 = F_38 ( V_2 ) ;
break;
case V_115 :
V_218 = F_44 ( V_2 ) ;
break;
case V_111 :
V_218 = F_42 ( V_2 ) ;
break;
case V_184 :
if ( V_2 -> V_86 ) {
V_8 -> V_183 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_18 , V_35 , V_8 -> V_183 -> error ) ;
break;
}
F_46 ( V_2 , V_8 -> V_183 ) ;
V_8 -> V_183 -> error = 0 ;
break;
case V_109 :
case V_114 :
if ( V_2 -> V_86 ) {
V_8 -> V_11 -> error = F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_18 , V_35 , V_8 -> V_11 -> error ) ;
}
break;
default:
F_79 () ;
}
if ( V_218 ) {
F_51 ( & V_2 -> V_180 , V_2 -> V_85 ) ;
F_78 ( & V_2 -> V_219 ) ;
return V_220 ;
}
if ( V_2 -> V_94 != V_184 ) {
struct V_13 * V_11 = V_8 -> V_11 ;
if ( ! V_8 -> V_117 -> error && V_11 && ! V_11 -> error )
V_11 -> V_215 =
V_11 -> V_160 * V_11 -> V_174 ;
if ( V_8 -> V_183 && ! V_8 -> V_117 -> error && ( ! V_11 || ! V_11 -> error ) ) {
F_52 ( V_2 , V_8 ) ;
if ( ! V_8 -> V_183 -> error ) {
F_51 ( & V_2 -> V_180 , V_2 -> V_85 ) ;
F_78 ( & V_2 -> V_219 ) ;
return V_220 ;
}
}
}
V_2 -> V_94 = V_221 ;
V_2 -> V_93 = V_188 ;
V_2 -> V_8 = NULL ;
F_57 ( V_2 -> V_186 , V_8 ) ;
F_78 ( & V_2 -> V_219 ) ;
return V_220 ;
}
static T_4 F_80 ( int V_216 , void * V_217 )
{
struct V_1 * V_2 = V_217 ;
T_1 V_93 , V_48 ;
V_93 = F_29 ( V_2 -> V_5 , V_175 ) ;
V_48 = F_29 ( V_2 -> V_5 , V_105 ) ;
if ( V_2 -> V_75 )
F_30 ( V_2 -> V_5 , V_175 , ~ ( V_93 & V_48 ) ) ;
else
F_30 ( V_2 -> V_5 , V_175 , V_176 | ~ ( V_93 & V_48 ) ) ;
F_4 ( V_2 , V_105 , V_93 & V_222 ) ;
if ( V_93 & ~ V_222 )
F_6 ( & V_2 -> V_9 -> V_10 , L_29 ,
V_93 ) ;
if ( V_93 & V_223 || V_93 & ~ V_224 ) {
V_2 -> V_86 = true ;
F_6 ( & V_2 -> V_9 -> V_10 , L_30 , V_93 ) ;
}
if ( V_93 & ~ ( V_225 | V_226 ) ) {
if ( ! V_2 -> V_8 )
F_6 ( & V_2 -> V_9 -> V_10 , L_31 , V_93 ) ;
if ( ! V_2 -> V_27 )
return V_227 ;
else if ( V_2 -> V_86 )
F_5 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_9 -> V_10 , L_32 , V_93 ) ;
}
return V_220 ;
}
static void F_81 ( struct V_228 * V_229 )
{
struct V_230 * V_231 = F_82 ( V_229 , struct V_230 , V_229 ) ;
struct V_1 * V_2 = F_82 ( V_231 , struct V_1 , V_180 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_118 ;
if ( V_2 -> V_232 )
return;
F_33 ( & V_2 -> V_9 -> V_10 , L_33 ,
V_2 -> V_94 , V_8 -> V_117 -> V_127 ) ;
F_55 ( & V_2 -> V_187 , V_118 ) ;
if ( V_2 -> V_93 == V_188 ) {
F_56 ( & V_2 -> V_187 , V_118 ) ;
return;
}
V_2 -> V_93 = V_233 ;
F_56 ( & V_2 -> V_187 , V_118 ) ;
switch ( V_2 -> V_94 ) {
case V_179 :
V_8 -> V_117 -> error = F_31 ( V_2 ) ;
break;
case V_184 :
V_8 -> V_183 -> error = F_31 ( V_2 ) ;
break;
case V_110 :
case V_115 :
case V_104 :
case V_111 :
case V_109 :
case V_114 :
V_8 -> V_11 -> error = F_31 ( V_2 ) ;
break;
default:
F_79 () ;
}
V_2 -> V_93 = V_188 ;
V_2 -> V_94 = V_221 ;
V_2 -> V_8 = NULL ;
F_57 ( V_2 -> V_186 , V_8 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_41 * V_9 = V_2 -> V_9 -> V_10 . V_65 ;
struct V_185 * V_186 = V_2 -> V_186 ;
F_84 ( V_186 ) ;
if ( ! V_9 )
return;
if ( ! V_186 -> V_234 )
V_186 -> V_234 = V_9 -> V_235 ;
else if ( V_9 -> V_235 )
F_16 ( F_85 ( V_186 ) , L_34 ) ;
}
static int F_86 ( struct V_236 * V_237 )
{
int V_23 = 0 , V_216 [ 2 ] ;
struct V_185 * V_186 ;
struct V_1 * V_2 ;
struct V_41 * V_9 = V_237 -> V_10 . V_65 ;
struct V_43 * V_44 ;
void T_5 * V_3 ;
const char * V_238 ;
V_216 [ 0 ] = F_87 ( V_237 , 0 ) ;
V_216 [ 1 ] = F_87 ( V_237 , 1 ) ;
if ( V_216 [ 0 ] < 0 ) {
F_33 ( & V_237 -> V_10 , L_35 ) ;
return - V_239 ;
}
V_44 = F_19 ( V_237 , V_45 , 0 ) ;
if ( ! V_44 ) {
F_33 ( & V_237 -> V_10 , L_36 ) ;
return - V_239 ;
}
V_3 = F_88 ( V_44 -> V_57 , F_89 ( V_44 ) ) ;
if ( ! V_3 ) {
F_33 ( & V_237 -> V_10 , L_37 ) ;
return - V_240 ;
}
V_186 = F_90 ( sizeof( struct V_1 ) , & V_237 -> V_10 ) ;
if ( ! V_186 ) {
V_23 = - V_240 ;
goto V_241;
}
V_23 = F_91 ( V_186 ) ;
if ( V_23 < 0 )
goto V_242;
V_2 = F_54 ( V_186 ) ;
V_2 -> V_186 = V_186 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_85 = F_92 ( 1000 ) ;
V_2 -> V_75 = ! V_9 || ! V_9 -> V_243 ;
V_2 -> V_77 = V_9 && V_9 -> V_244 ;
V_2 -> V_9 = V_237 ;
F_93 ( & V_2 -> V_187 ) ;
V_186 -> V_245 = & V_246 ;
F_83 ( V_2 ) ;
V_186 -> V_247 |= V_248 | V_249 ;
if ( V_9 && V_9 -> V_247 )
V_186 -> V_247 |= V_9 -> V_247 ;
V_186 -> V_250 = 32 ;
V_186 -> V_251 = 512 ;
V_186 -> V_252 = V_253 * V_186 -> V_250 ;
V_186 -> V_254 = V_186 -> V_252 / V_186 -> V_251 ;
V_186 -> V_255 = V_186 -> V_252 ;
F_94 ( V_237 , V_2 ) ;
F_95 ( & V_237 -> V_10 ) ;
V_2 -> V_208 = false ;
V_2 -> V_195 = F_96 ( & V_237 -> V_10 , NULL ) ;
if ( F_62 ( V_2 -> V_195 ) ) {
V_23 = F_97 ( V_2 -> V_195 ) ;
F_33 ( & V_237 -> V_10 , L_38 , V_23 ) ;
goto V_256;
}
V_23 = F_58 ( V_2 ) ;
if ( V_23 < 0 )
goto V_257;
V_23 = F_98 ( & V_237 -> V_10 ) ;
if ( V_23 < 0 )
goto V_258;
F_99 ( & V_2 -> V_180 , F_81 ) ;
F_28 ( V_2 ) ;
F_30 ( V_2 -> V_5 , V_105 , V_259 ) ;
V_238 = V_216 [ 1 ] < 0 ? F_8 ( & V_237 -> V_10 ) : L_39 ;
V_23 = F_100 ( V_216 [ 0 ] , F_80 , F_75 , 0 , V_238 , V_2 ) ;
if ( V_23 ) {
F_33 ( & V_237 -> V_10 , L_40 , V_238 ) ;
goto V_260;
}
if ( V_216 [ 1 ] >= 0 ) {
V_23 = F_100 ( V_216 [ 1 ] , F_80 , F_75 ,
0 , L_41 , V_2 ) ;
if ( V_23 ) {
F_33 ( & V_237 -> V_10 , L_42 ) ;
goto V_261;
}
}
if ( V_9 && V_9 -> V_262 ) {
V_23 = F_101 ( V_186 , V_9 -> V_263 , 0 ) ;
if ( V_23 < 0 )
goto V_264;
}
F_102 ( & V_2 -> V_219 ) ;
F_66 ( V_2 -> V_195 ) ;
V_23 = F_103 ( V_186 ) ;
if ( V_23 < 0 )
goto V_265;
F_104 ( & V_237 -> V_10 , 100 ) ;
F_105 ( & V_237 -> V_10 , L_43 , V_266 ) ;
F_6 ( & V_237 -> V_10 , L_44 ,
F_29 ( V_2 -> V_5 , V_72 ) & 0x0000ffff ) ;
return V_23 ;
V_265:
V_264:
if ( V_216 [ 1 ] >= 0 )
F_106 ( V_216 [ 1 ] , V_2 ) ;
V_261:
F_106 ( V_216 [ 0 ] , V_2 ) ;
V_260:
F_107 ( & V_237 -> V_10 ) ;
V_258:
F_66 ( V_2 -> V_195 ) ;
V_257:
F_108 ( V_2 -> V_195 ) ;
V_256:
F_109 ( & V_237 -> V_10 ) ;
V_242:
F_110 ( V_186 ) ;
V_241:
F_111 ( V_3 ) ;
return V_23 ;
}
static int F_112 ( struct V_236 * V_237 )
{
struct V_1 * V_2 = F_113 ( V_237 ) ;
int V_216 [ 2 ] ;
V_2 -> V_232 = true ;
F_59 ( V_2 -> V_195 ) ;
F_67 ( & V_237 -> V_10 ) ;
F_114 ( & V_237 -> V_10 ) ;
F_115 ( V_2 -> V_186 ) ;
F_30 ( V_2 -> V_5 , V_105 , V_259 ) ;
F_76 ( & V_2 -> V_180 ) ;
if ( V_2 -> V_5 )
F_111 ( V_2 -> V_5 ) ;
V_216 [ 0 ] = F_87 ( V_237 , 0 ) ;
V_216 [ 1 ] = F_87 ( V_237 , 1 ) ;
F_106 ( V_216 [ 0 ] , V_2 ) ;
if ( V_216 [ 1 ] >= 0 )
F_106 ( V_216 [ 1 ] , V_2 ) ;
F_66 ( V_2 -> V_195 ) ;
F_110 ( V_2 -> V_186 ) ;
F_65 ( & V_237 -> V_10 ) ;
F_109 ( & V_237 -> V_10 ) ;
return 0 ;
}
static int F_116 ( struct V_24 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
int V_23 = F_118 ( V_2 -> V_186 ) ;
if ( ! V_23 )
F_30 ( V_2 -> V_5 , V_105 , V_259 ) ;
return V_23 ;
}
static int F_119 ( struct V_24 * V_10 )
{
struct V_1 * V_2 = F_117 ( V_10 ) ;
return F_120 ( V_2 -> V_186 ) ;
}
