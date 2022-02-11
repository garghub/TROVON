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
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
F_6 ( & V_2 -> V_10 -> V_11 , L_1 ) ;
if ( F_7 ( ! V_8 , L_2 ,
F_8 ( & V_2 -> V_10 -> V_11 ) ) )
return;
if ( V_8 -> V_12 & V_13 )
F_9 ( V_2 -> V_14 -> V_15 -> V_11 ,
V_8 -> V_16 , V_8 -> V_17 ,
V_18 ) ;
else
F_9 ( V_2 -> V_19 -> V_15 -> V_11 ,
V_8 -> V_16 , V_8 -> V_17 ,
V_20 ) ;
F_10 ( & V_2 -> V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
struct V_22 * V_16 = V_8 -> V_16 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = V_2 -> V_14 ;
T_2 V_27 = - V_28 ;
int V_29 ;
V_29 = F_12 ( V_26 -> V_15 -> V_11 , V_16 , V_8 -> V_17 ,
V_18 ) ;
if ( V_29 > 0 ) {
V_2 -> V_30 = true ;
V_24 = F_13 ( V_26 , V_16 , V_29 ,
V_31 , V_32 | V_33 ) ;
}
if ( V_24 ) {
V_24 -> V_34 = F_5 ;
V_24 -> V_35 = V_2 ;
V_27 = F_14 ( V_24 ) ;
F_1 ( V_2 , V_36 , V_37 ) ;
F_15 ( V_26 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_38 , V_8 -> V_17 , V_29 , V_27 ) ;
if ( ! V_24 ) {
if ( V_29 >= 0 )
V_29 = - V_39 ;
V_2 -> V_14 = NULL ;
V_2 -> V_30 = false ;
F_16 ( V_26 ) ;
V_26 = V_2 -> V_19 ;
if ( V_26 ) {
V_2 -> V_19 = NULL ;
F_16 ( V_26 ) ;
}
F_17 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_29 ) ;
F_4 ( V_2 , V_36 , V_37 | V_40 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_5 , V_38 ,
V_24 , V_27 , V_8 -> V_17 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
struct V_22 * V_16 = V_8 -> V_16 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = V_2 -> V_19 ;
T_2 V_27 = - V_28 ;
int V_29 ;
V_29 = F_12 ( V_26 -> V_15 -> V_11 , V_16 , V_8 -> V_17 ,
V_20 ) ;
if ( V_29 > 0 ) {
V_2 -> V_30 = true ;
V_24 = F_13 ( V_26 , V_16 , V_29 ,
V_41 , V_32 | V_33 ) ;
}
if ( V_24 ) {
V_24 -> V_34 = F_5 ;
V_24 -> V_35 = V_2 ;
V_27 = F_14 ( V_24 ) ;
F_1 ( V_2 , V_36 , V_40 ) ;
F_15 ( V_26 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_38 , V_8 -> V_17 , V_29 , V_27 ) ;
if ( ! V_24 ) {
if ( V_29 >= 0 )
V_29 = - V_39 ;
V_2 -> V_19 = NULL ;
V_2 -> V_30 = false ;
F_16 ( V_26 ) ;
V_26 = V_2 -> V_14 ;
if ( V_26 ) {
V_2 -> V_14 = NULL ;
F_16 ( V_26 ) ;
}
F_17 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_29 ) ;
F_4 ( V_2 , V_36 , V_37 | V_40 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_6 , V_38 ,
V_24 , V_27 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = F_20 ( V_2 -> V_10 , V_46 , 0 ) ;
struct V_47 V_48 ;
T_3 V_49 ;
int V_29 ;
V_2 -> V_30 = false ;
if ( ! V_43 )
return;
if ( V_43 -> V_50 <= 0 || V_43 -> V_51 <= 0 )
return;
F_21 ( V_49 ) ;
F_22 ( V_52 , V_49 ) ;
V_2 -> V_19 = F_23 ( V_49 , V_53 ,
( void * ) V_43 -> V_50 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_7 , V_38 ,
V_2 -> V_19 ) ;
if ( ! V_2 -> V_19 )
return;
V_48 . V_54 = V_43 -> V_50 ;
V_48 . V_55 = V_41 ;
V_48 . V_56 = V_45 -> V_57 + V_58 ;
V_48 . V_59 = 0 ;
V_29 = F_24 ( V_2 -> V_19 , & V_48 ) ;
if ( V_29 < 0 )
goto V_60;
V_2 -> V_14 = F_23 ( V_49 , V_53 ,
( void * ) V_43 -> V_51 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_8 , V_38 ,
V_2 -> V_14 ) ;
if ( ! V_2 -> V_14 )
goto V_61;
V_48 . V_54 = V_43 -> V_51 ;
V_48 . V_55 = V_31 ;
V_48 . V_56 = 0 ;
V_48 . V_59 = V_45 -> V_57 + V_58 ;
V_29 = F_24 ( V_2 -> V_14 , & V_48 ) ;
if ( V_29 < 0 )
goto V_62;
F_25 ( & V_2 -> V_21 ) ;
return;
V_62:
F_16 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
V_61:
V_60:
F_16 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_36 , V_37 | V_40 ) ;
if ( V_2 -> V_19 ) {
struct V_25 * V_26 = V_2 -> V_19 ;
V_2 -> V_19 = NULL ;
F_16 ( V_26 ) ;
}
if ( V_2 -> V_14 ) {
struct V_25 * V_26 = V_2 -> V_14 ;
V_2 -> V_14 = NULL ;
F_16 ( V_26 ) ;
}
V_2 -> V_30 = false ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_42 * V_64 = V_2 -> V_10 -> V_11 . V_65 ;
bool V_66 = V_64 ? V_64 -> V_66 : false ;
F_4 ( V_2 , V_67 , V_68 ) ;
F_4 ( V_2 , V_67 , V_69 ) ;
if ( ! V_63 )
return;
if ( V_66 && V_63 == V_2 -> V_63 )
F_1 ( V_2 , V_67 , V_70 ) ;
else
F_1 ( V_2 , V_67 , V_69 &
( ( F_28 ( F_29 ( V_2 -> V_63 ,
V_63 ) - 1 ) - 1 ) << 16 ) ) ;
F_1 ( V_2 , V_67 , V_68 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_71 ;
V_71 = 0x010f0000 & F_31 ( V_2 -> V_5 , V_67 ) ;
F_32 ( V_2 -> V_5 , V_72 , V_73 ) ;
F_32 ( V_2 -> V_5 , V_72 , V_74 ) ;
F_1 ( V_2 , V_67 , V_71 |
V_75 | V_76 | V_77 | V_78 ) ;
F_1 ( V_2 , V_36 , V_79 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_1 V_80 , V_81 ;
int V_29 , V_82 ;
V_2 -> V_83 = false ;
V_80 = F_31 ( V_2 -> V_5 , V_84 ) ;
V_81 = F_31 ( V_2 -> V_5 , V_85 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_9 , V_80 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_10 , V_81 ) ;
if ( V_80 & V_86 ) {
F_1 ( V_2 , V_87 , V_88 ) ;
F_1 ( V_2 , V_87 , ~ V_88 ) ;
for ( V_82 = 10000000 ; V_82 ; V_82 -- ) {
if ( ! ( F_31 ( V_2 -> V_5 , V_84 )
& V_86 ) )
break;
F_34 ( 1 ) ;
}
if ( ! V_82 ) {
F_35 ( & V_2 -> V_10 -> V_11 ,
L_11 ) ;
return - V_39 ;
}
F_30 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_12 ) ;
return - V_39 ;
}
if ( V_81 & V_89 ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_13 ) ;
V_29 = - V_39 ;
} else if ( V_81 & V_90 ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_14 ) ;
V_29 = - V_91 ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_15 ) ;
V_29 = - V_39 ;
}
return V_29 ;
}
static bool F_36 ( struct V_1 * V_2 , T_1 * V_64 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
V_2 -> V_92 += V_2 -> V_93 ;
F_37 ( V_2 -> V_92 > V_8 -> V_16 -> V_94 ) ;
if ( V_2 -> V_92 == V_8 -> V_16 -> V_94 ) {
V_2 -> V_92 = 0 ;
if ( ++ V_2 -> V_95 < V_8 -> V_17 )
V_2 -> V_96 = F_38 ( ++ V_8 -> V_16 ) ;
} else {
V_2 -> V_96 = V_64 ;
}
if ( V_2 -> V_95 == V_8 -> V_17 )
return false ;
return true ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_97 * V_9 )
{
V_2 -> V_93 = ( F_31 ( V_2 -> V_5 , V_98 ) &
V_99 ) + 3 ;
V_2 -> V_100 = V_101 ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
F_1 ( V_2 , V_103 , V_104 ) ;
}
static bool F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_64 = F_38 ( V_8 -> V_16 ) ;
int V_105 ;
if ( V_2 -> V_83 ) {
V_8 -> error = F_33 ( V_2 ) ;
return false ;
}
for ( V_105 = 0 ; V_105 < V_2 -> V_93 / 4 ; V_105 ++ )
* V_64 ++ = F_31 ( V_2 -> V_5 , V_58 ) ;
F_1 ( V_2 , V_103 , V_106 ) ;
V_2 -> V_100 = V_107 ;
return true ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_97 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
if ( ! V_8 -> V_17 || ! V_8 -> V_16 -> V_94 )
return;
V_2 -> V_93 = F_31 ( V_2 -> V_5 , V_98 ) &
V_99 ;
V_2 -> V_100 = V_108 ;
V_2 -> V_95 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_96 = F_38 ( V_8 -> V_16 ) ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
F_1 ( V_2 , V_103 , V_104 ) ;
}
static bool F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_64 = V_2 -> V_96 ;
int V_105 ;
if ( V_2 -> V_83 ) {
V_8 -> error = F_33 ( V_2 ) ;
return false ;
}
F_37 ( ! V_8 -> V_16 -> V_94 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_93 / 4 ; V_105 ++ )
* V_64 ++ = F_31 ( V_2 -> V_5 , V_58 ) ;
if ( ! F_36 ( V_2 , V_64 ) )
return false ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
F_1 ( V_2 , V_103 , V_104 ) ;
return true ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_97 * V_9 )
{
V_2 -> V_93 = ( F_31 ( V_2 -> V_5 , V_98 ) &
V_99 ) + 3 ;
V_2 -> V_100 = V_109 ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
F_1 ( V_2 , V_103 , V_110 ) ;
}
static bool F_45 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_64 = F_38 ( V_8 -> V_16 ) ;
int V_105 ;
if ( V_2 -> V_83 ) {
V_8 -> error = F_33 ( V_2 ) ;
return false ;
}
for ( V_105 = 0 ; V_105 < V_2 -> V_93 / 4 ; V_105 ++ )
F_32 ( V_2 -> V_5 , V_58 , * V_64 ++ ) ;
F_1 ( V_2 , V_103 , V_111 ) ;
V_2 -> V_100 = V_112 ;
return true ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_97 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
if ( ! V_8 -> V_17 || ! V_8 -> V_16 -> V_94 )
return;
V_2 -> V_93 = F_31 ( V_2 -> V_5 , V_98 ) &
V_99 ;
V_2 -> V_100 = V_113 ;
V_2 -> V_95 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_96 = F_38 ( V_8 -> V_16 ) ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
F_1 ( V_2 , V_103 , V_110 ) ;
}
static bool F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_64 = V_2 -> V_96 ;
int V_105 ;
if ( V_2 -> V_83 ) {
V_8 -> error = F_33 ( V_2 ) ;
return false ;
}
F_37 ( ! V_8 -> V_16 -> V_94 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_93 / 4 ; V_105 ++ )
F_32 ( V_2 -> V_5 , V_58 , * V_64 ++ ) ;
if ( ! F_36 ( V_2 , V_64 ) )
return false ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
F_1 ( V_2 , V_103 , V_110 ) ;
return true ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
if ( V_115 -> V_12 & V_116 ) {
V_115 -> V_117 [ 0 ] = F_31 ( V_2 -> V_5 , V_118 ) ;
V_115 -> V_117 [ 1 ] = F_31 ( V_2 -> V_5 , V_119 ) ;
V_115 -> V_117 [ 2 ] = F_31 ( V_2 -> V_5 , V_120 ) ;
V_115 -> V_117 [ 3 ] = F_31 ( V_2 -> V_5 , V_121 ) ;
} else
V_115 -> V_117 [ 0 ] = F_31 ( V_2 -> V_5 , V_121 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
V_115 -> V_117 [ 0 ] = F_31 ( V_2 -> V_5 , V_122 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_97 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_114 * V_115 = V_9 -> V_115 ;
T_1 V_123 = V_115 -> V_124 ;
T_1 V_71 = 0 ;
switch ( F_51 ( V_115 ) ) {
case V_125 :
V_71 |= V_126 ;
break;
case V_127 :
case V_128 :
case V_129 :
V_71 |= V_130 ;
break;
case V_131 :
V_71 |= V_132 ;
break;
default:
F_35 ( & V_2 -> V_10 -> V_11 , L_16 ) ;
break;
}
switch ( V_123 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_71 |= V_138 ;
break;
}
if ( V_8 ) {
V_71 |= V_139 ;
switch ( V_2 -> V_140 ) {
case V_141 :
V_71 |= V_142 ;
break;
case V_143 :
V_71 |= V_144 ;
break;
case V_145 :
V_71 |= V_146 ;
break;
default:
F_35 ( & V_2 -> V_10 -> V_11 , L_17 ) ;
break;
}
}
if ( V_123 == V_147 || V_123 == V_148 )
V_71 |= V_149 ;
if ( V_123 == V_150 || V_123 == V_148 ) {
V_71 |= V_151 | V_152 ;
F_1 ( V_2 , V_98 ,
V_8 -> V_153 << 16 ) ;
}
if ( V_123 == V_154 || V_123 == V_155 ||
V_123 == V_156 || V_123 == V_157 )
V_71 |= V_158 ;
if ( V_123 == V_154 )
V_71 |= V_159 ;
if ( V_123 == V_155 ||
V_123 == V_156 || V_123 == V_157 )
V_71 |= V_160 ;
return ( V_123 << 24 ) | V_71 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_97 * V_9 , T_1 V_123 )
{
switch ( V_123 ) {
case V_150 :
F_42 ( V_2 , V_9 ) ;
return 0 ;
case V_148 :
F_46 ( V_2 , V_9 ) ;
return 0 ;
case V_147 :
F_44 ( V_2 , V_9 ) ;
return 0 ;
case V_161 :
case V_162 :
F_39 ( V_2 , V_9 ) ;
return 0 ;
default:
F_35 ( & V_2 -> V_10 -> V_11 , L_18 , V_123 ) ;
return - V_28 ;
}
}
static void F_53 ( struct V_1 * V_2 ,
struct V_97 * V_9 )
{
struct V_114 * V_115 = V_9 -> V_115 ;
T_1 V_123 = V_115 -> V_124 ;
T_1 V_49 ;
switch ( V_123 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_49 = V_163 | V_164 ;
break;
default:
V_49 = V_163 | V_165 ;
break;
}
if ( V_9 -> V_8 ) {
F_32 ( V_2 -> V_5 , V_98 , 0 ) ;
F_32 ( V_2 -> V_5 , V_98 ,
V_9 -> V_8 -> V_166 ) ;
}
V_123 = F_50 ( V_2 , V_9 ) ;
F_32 ( V_2 -> V_5 , V_167 , 0xD80430C0 ) ;
F_32 ( V_2 -> V_5 , V_103 , V_49 ) ;
F_32 ( V_2 -> V_5 , V_168 , V_115 -> V_6 ) ;
F_32 ( V_2 -> V_5 , V_169 , V_123 ) ;
V_2 -> V_100 = V_170 ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_97 * V_9 )
{
switch ( V_9 -> V_115 -> V_124 ) {
case V_150 :
F_1 ( V_2 , V_103 , V_171 ) ;
break;
case V_148 :
F_1 ( V_2 , V_103 , V_172 ) ;
break;
default:
F_35 ( & V_2 -> V_10 -> V_11 , L_19 ) ;
V_9 -> V_173 -> error = F_33 ( V_2 ) ;
return;
}
V_2 -> V_100 = V_174 ;
F_40 ( & V_2 -> V_102 , V_2 -> V_82 ) ;
}
static void F_55 ( struct V_175 * V_176 , struct V_97 * V_9 )
{
struct V_1 * V_2 = F_56 ( V_176 ) ;
unsigned long V_12 ;
F_57 ( & V_2 -> V_177 , V_12 ) ;
if ( V_2 -> V_178 != V_179 ) {
F_58 ( & V_2 -> V_177 , V_12 ) ;
V_9 -> V_115 -> error = - V_180 ;
F_59 ( V_176 , V_9 ) ;
return;
}
V_2 -> V_178 = V_181 ;
F_58 ( & V_2 -> V_177 , V_12 ) ;
switch ( V_9 -> V_115 -> V_124 ) {
case V_182 :
case V_162 :
if ( ( V_9 -> V_115 -> V_12 & V_183 ) != V_184 )
break;
case V_185 :
V_2 -> V_178 = V_179 ;
V_9 -> V_115 -> error = - V_91 ;
F_59 ( V_176 , V_9 ) ;
return;
default:
break;
}
V_2 -> V_9 = V_9 ;
F_53 ( V_2 , V_9 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_29 = F_61 ( V_2 -> V_186 ) ;
if ( ! V_29 ) {
V_2 -> V_63 = F_62 ( V_2 -> V_186 ) ;
V_2 -> V_176 -> V_187 = V_2 -> V_63 / 2 ;
V_2 -> V_176 -> V_188 = V_2 -> V_63 / 512 ;
}
return V_29 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
struct V_42 * V_10 = V_2 -> V_10 -> V_11 . V_65 ;
struct V_175 * V_176 = V_2 -> V_176 ;
if ( V_10 && V_10 -> V_191 )
V_10 -> V_191 ( V_2 -> V_10 , V_190 -> V_192 != V_193 ) ;
if ( ! F_64 ( V_176 -> V_194 . V_195 ) )
F_65 ( V_176 , V_176 -> V_194 . V_195 ,
V_190 -> V_192 ? V_190 -> V_196 : 0 ) ;
}
static void F_66 ( struct V_175 * V_176 , struct V_189 * V_190 )
{
struct V_1 * V_2 = F_56 ( V_176 ) ;
unsigned long V_12 ;
F_57 ( & V_2 -> V_177 , V_12 ) ;
if ( V_2 -> V_178 != V_179 ) {
F_58 ( & V_2 -> V_177 , V_12 ) ;
return;
}
V_2 -> V_178 = V_197 ;
F_58 ( & V_2 -> V_177 , V_12 ) ;
if ( V_190 -> V_192 == V_198 ) {
if ( ! V_2 -> V_199 ) {
F_19 ( V_2 , V_2 -> V_10 -> V_11 . V_65 ) ;
V_2 -> V_199 = true ;
}
F_63 ( V_2 , V_190 ) ;
} else if ( V_190 -> V_192 == V_193 || ! V_190 -> clock ) {
F_27 ( V_2 , 0 ) ;
if ( V_190 -> V_192 == V_193 ) {
if ( V_2 -> V_199 ) {
F_26 ( V_2 ) ;
V_2 -> V_199 = false ;
}
}
if ( V_2 -> V_200 ) {
F_67 ( & V_2 -> V_10 -> V_11 ) ;
F_68 ( V_2 -> V_186 ) ;
V_2 -> V_200 = false ;
if ( V_190 -> V_192 == V_193 )
F_63 ( V_2 , V_190 ) ;
}
V_2 -> V_178 = V_179 ;
return;
}
if ( V_190 -> clock ) {
if ( ! V_2 -> V_200 ) {
F_60 ( V_2 ) ;
F_69 ( & V_2 -> V_10 -> V_11 ) ;
V_2 -> V_200 = true ;
F_30 ( V_2 ) ;
}
F_27 ( V_2 , V_190 -> clock ) ;
}
V_2 -> V_140 = V_190 -> V_140 ;
V_2 -> V_178 = V_179 ;
}
static int F_70 ( struct V_175 * V_176 )
{
struct V_1 * V_2 = F_56 ( V_176 ) ;
struct V_42 * V_64 = V_2 -> V_10 -> V_11 . V_65 ;
int V_29 = F_71 ( V_176 ) ;
if ( V_29 >= 0 )
return V_29 ;
if ( ! V_64 || ! V_64 -> V_201 )
return - V_202 ;
else
return V_64 -> V_201 ( V_2 -> V_10 ) ;
}
static bool F_72 ( struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_9 -> V_115 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
long time ;
if ( V_2 -> V_83 ) {
switch ( V_115 -> V_124 ) {
case V_155 :
case V_203 :
case V_185 :
V_115 -> error = - V_91 ;
V_2 -> V_83 = false ;
break;
default:
V_115 -> error = F_33 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_20 ,
V_115 -> V_124 , V_115 -> error ) ;
break;
}
return false ;
}
if ( ! ( V_115 -> V_12 & V_204 ) ) {
V_115 -> error = 0 ;
return false ;
}
F_48 ( V_2 , V_115 ) ;
if ( ! V_8 )
return false ;
if ( V_8 -> V_12 & V_13 ) {
if ( V_2 -> V_14 )
F_11 ( V_2 ) ;
} else {
if ( V_2 -> V_19 )
F_18 ( V_2 ) ;
}
if ( ! V_2 -> V_30 ) {
V_8 -> error = F_52 ( V_2 , V_2 -> V_9 , V_115 -> V_124 ) ;
if ( ! V_8 -> error )
return true ;
return false ;
}
time = F_73 ( & V_2 -> V_21 ,
V_2 -> V_82 ) ;
if ( V_2 -> V_83 ) {
F_35 ( V_2 -> V_176 -> V_205 ,
L_21 ) ;
if ( V_8 -> V_12 & V_13 )
F_74 ( V_2 -> V_14 ) ;
else
F_74 ( V_2 -> V_19 ) ;
V_8 -> error = F_33 ( V_2 ) ;
} else if ( ! time ) {
V_8 -> error = - V_91 ;
} else if ( time < 0 ) {
V_8 -> error = time ;
}
F_4 ( V_2 , V_36 ,
V_37 | V_40 ) ;
V_2 -> V_30 = false ;
if ( V_8 -> error )
V_8 -> V_206 = 0 ;
return false ;
}
static T_4 F_75 ( int V_207 , void * V_208 )
{
struct V_1 * V_2 = V_208 ;
struct V_97 * V_9 = V_2 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_8 ;
F_76 ( & V_2 -> V_102 ) ;
switch ( V_2 -> V_100 ) {
case V_209 :
return V_210 ;
case V_170 :
if ( F_72 ( V_2 ) )
return V_210 ;
break;
case V_108 :
if ( F_43 ( V_2 ) )
return V_210 ;
break;
case V_101 :
if ( F_41 ( V_2 ) )
return V_210 ;
break;
case V_113 :
if ( F_47 ( V_2 ) )
return V_210 ;
break;
case V_109 :
if ( F_45 ( V_2 ) )
return V_210 ;
break;
case V_174 :
if ( V_2 -> V_83 ) {
V_9 -> V_173 -> error = F_33 ( V_2 ) ;
break;
}
F_49 ( V_2 , V_9 -> V_173 ) ;
V_9 -> V_173 -> error = 0 ;
break;
case V_107 :
case V_112 :
if ( V_2 -> V_83 )
V_8 -> error = F_33 ( V_2 ) ;
break;
default:
F_77 () ;
}
if ( V_2 -> V_100 != V_174 ) {
if ( ! V_9 -> V_115 -> error && V_8 && ! V_8 -> error )
V_8 -> V_206 =
V_8 -> V_153 * V_8 -> V_166 ;
if ( V_9 -> V_173 && ! V_9 -> V_115 -> error && ( ! V_8 || ! V_8 -> error ) ) {
F_54 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_173 -> error )
return V_210 ;
}
}
V_2 -> V_100 = V_209 ;
V_2 -> V_178 = V_179 ;
V_2 -> V_9 = NULL ;
F_59 ( V_2 -> V_176 , V_9 ) ;
return V_210 ;
}
static T_4 F_78 ( int V_207 , void * V_208 )
{
struct V_1 * V_2 = V_208 ;
T_1 V_178 ;
int V_211 = 0 ;
V_178 = F_31 ( V_2 -> V_5 , V_167 ) ;
if ( V_178 & V_212 ) {
F_32 ( V_2 -> V_5 , V_167 , ~ V_178 ) ;
F_4 ( V_2 , V_103 , V_178 ) ;
V_211 = 1 ;
} else if ( V_178 & V_213 ) {
F_32 ( V_2 -> V_5 , V_167 ,
~ ( V_213 | V_214 ) ) ;
F_4 ( V_2 , V_103 , V_164 ) ;
} else if ( V_178 & V_214 ) {
F_32 ( V_2 -> V_5 , V_167 , ~ V_214 ) ;
F_4 ( V_2 , V_103 , V_165 ) ;
} else if ( V_178 & V_215 ) {
F_32 ( V_2 -> V_5 , V_167 , ~ V_215 ) ;
F_4 ( V_2 , V_103 , V_104 ) ;
} else if ( V_178 & V_216 ) {
F_32 ( V_2 -> V_5 , V_167 , ~ V_216 ) ;
F_4 ( V_2 , V_103 , V_110 ) ;
} else if ( V_178 & V_217 ) {
F_32 ( V_2 -> V_5 , V_167 ,
~ ( V_217 | V_218 |
V_219 | V_220 ) ) ;
F_4 ( V_2 , V_103 , V_171 ) ;
} else if ( V_178 & V_220 ) {
F_32 ( V_2 -> V_5 , V_167 , ~ V_220 ) ;
F_4 ( V_2 , V_103 , V_106 ) ;
} else if ( V_178 & V_221 ) {
F_32 ( V_2 -> V_5 , V_167 , ~ V_221 ) ;
F_4 ( V_2 , V_103 , V_111 ) ;
} else if ( V_178 & V_218 ) {
F_32 ( V_2 -> V_5 , V_167 ,
~ ( V_218 | V_219 ) ) ;
F_4 ( V_2 , V_103 , V_172 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_22 , V_178 ) ;
F_32 ( V_2 -> V_5 , V_167 , ~ V_178 ) ;
F_4 ( V_2 , V_103 , V_178 ) ;
V_211 = 1 ;
}
if ( V_211 ) {
V_2 -> V_83 = true ;
F_6 ( & V_2 -> V_10 -> V_11 , L_23 , V_178 ) ;
}
if ( V_178 & ~ ( V_218 | V_219 ) ) {
if ( ! V_2 -> V_30 )
return V_222 ;
else if ( V_2 -> V_83 )
F_5 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_24 , V_178 ) ;
}
return V_210 ;
}
static void F_79 ( struct V_223 * V_224 )
{
struct V_225 * V_226 = F_80 ( V_224 , struct V_225 , V_224 ) ;
struct V_1 * V_2 = F_80 ( V_226 , struct V_1 , V_102 ) ;
struct V_97 * V_9 = V_2 -> V_9 ;
if ( V_2 -> V_227 )
return;
switch ( V_2 -> V_100 ) {
case V_170 :
V_9 -> V_115 -> error = F_33 ( V_2 ) ;
break;
case V_174 :
V_9 -> V_173 -> error = F_33 ( V_2 ) ;
break;
case V_108 :
case V_113 :
case V_101 :
case V_109 :
case V_107 :
case V_112 :
V_9 -> V_8 -> error = F_33 ( V_2 ) ;
break;
default:
F_77 () ;
}
V_2 -> V_178 = V_179 ;
V_2 -> V_100 = V_209 ;
V_2 -> V_9 = NULL ;
F_59 ( V_2 -> V_176 , V_9 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_42 * V_10 = V_2 -> V_10 -> V_11 . V_65 ;
struct V_175 * V_176 = V_2 -> V_176 ;
F_82 ( V_176 ) ;
if ( ! V_10 )
return;
if ( ! V_176 -> V_228 )
V_176 -> V_228 = V_10 -> V_229 ;
else if ( V_10 -> V_229 )
F_17 ( F_83 ( V_176 ) , L_25 ) ;
}
static int T_5 F_84 ( struct V_230 * V_231 )
{
int V_29 = 0 , V_207 [ 2 ] ;
struct V_175 * V_176 ;
struct V_1 * V_2 ;
struct V_42 * V_10 = V_231 -> V_11 . V_65 ;
struct V_44 * V_45 ;
void T_6 * V_3 ;
char V_232 [ 8 ] ;
V_207 [ 0 ] = F_85 ( V_231 , 0 ) ;
V_207 [ 1 ] = F_85 ( V_231 , 1 ) ;
if ( V_207 [ 0 ] < 0 || V_207 [ 1 ] < 0 ) {
F_35 ( & V_231 -> V_11 , L_26 ) ;
return - V_233 ;
}
V_45 = F_20 ( V_231 , V_46 , 0 ) ;
if ( ! V_45 ) {
F_35 ( & V_231 -> V_11 , L_27 ) ;
return - V_233 ;
}
V_3 = F_86 ( V_45 -> V_57 , F_87 ( V_45 ) ) ;
if ( ! V_3 ) {
F_35 ( & V_231 -> V_11 , L_28 ) ;
return - V_234 ;
}
V_176 = F_88 ( sizeof( struct V_1 ) , & V_231 -> V_11 ) ;
if ( ! V_176 ) {
V_29 = - V_234 ;
goto V_235;
}
V_2 = F_56 ( V_176 ) ;
V_2 -> V_176 = V_176 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_82 = 1000 ;
V_2 -> V_10 = V_231 ;
F_89 ( & V_2 -> V_177 ) ;
V_176 -> V_236 = & V_237 ;
F_81 ( V_2 ) ;
V_176 -> V_238 = V_239 ;
if ( V_10 && V_10 -> V_238 )
V_176 -> V_238 |= V_10 -> V_238 ;
V_176 -> V_240 = 32 ;
V_176 -> V_241 = 512 ;
V_176 -> V_242 = V_243 * V_176 -> V_240 ;
V_176 -> V_244 = V_176 -> V_242 / V_176 -> V_241 ;
V_176 -> V_245 = V_176 -> V_242 ;
F_90 ( V_231 , V_2 ) ;
F_91 ( & V_231 -> V_11 ) ;
V_2 -> V_200 = false ;
snprintf ( V_232 , sizeof( V_232 ) , L_29 , V_231 -> V_246 ) ;
V_2 -> V_186 = F_92 ( & V_231 -> V_11 , V_232 ) ;
if ( F_64 ( V_2 -> V_186 ) ) {
V_29 = F_93 ( V_2 -> V_186 ) ;
F_35 ( & V_231 -> V_11 , L_30 , V_232 , V_29 ) ;
goto V_247;
}
V_29 = F_60 ( V_2 ) ;
if ( V_29 < 0 )
goto V_248;
V_29 = F_94 ( & V_231 -> V_11 ) ;
if ( V_29 < 0 )
goto V_249;
F_95 ( & V_2 -> V_102 , F_79 ) ;
F_30 ( V_2 ) ;
F_32 ( V_2 -> V_5 , V_103 , V_250 ) ;
V_29 = F_96 ( V_207 [ 0 ] , F_78 , F_75 , 0 , L_31 , V_2 ) ;
if ( V_29 ) {
F_35 ( & V_231 -> V_11 , L_32 ) ;
goto V_251;
}
V_29 = F_96 ( V_207 [ 1 ] , F_78 , F_75 , 0 , L_33 , V_2 ) ;
if ( V_29 ) {
F_35 ( & V_231 -> V_11 , L_34 ) ;
goto V_252;
}
if ( V_10 && V_10 -> V_253 ) {
V_29 = F_97 ( V_176 , V_10 -> V_254 ) ;
if ( V_29 < 0 )
goto V_255;
}
F_68 ( V_2 -> V_186 ) ;
V_29 = F_98 ( V_176 ) ;
if ( V_29 < 0 )
goto V_256;
F_99 ( & V_231 -> V_11 , 100 ) ;
F_100 ( & V_231 -> V_11 , L_35 , V_257 ) ;
F_6 ( & V_231 -> V_11 , L_36 ,
F_31 ( V_2 -> V_5 , V_72 ) & 0x0000ffff ) ;
return V_29 ;
V_256:
if ( V_10 && V_10 -> V_253 )
F_101 ( V_176 ) ;
V_255:
F_102 ( V_207 [ 1 ] , V_2 ) ;
V_252:
F_102 ( V_207 [ 0 ] , V_2 ) ;
V_251:
F_103 ( & V_231 -> V_11 ) ;
V_249:
F_68 ( V_2 -> V_186 ) ;
V_248:
F_104 ( V_2 -> V_186 ) ;
V_247:
F_105 ( & V_231 -> V_11 ) ;
F_106 ( V_176 ) ;
V_235:
F_107 ( V_3 ) ;
return V_29 ;
}
static int T_7 F_108 ( struct V_230 * V_231 )
{
struct V_1 * V_2 = F_109 ( V_231 ) ;
struct V_42 * V_10 = V_231 -> V_11 . V_65 ;
int V_207 [ 2 ] ;
V_2 -> V_227 = true ;
F_61 ( V_2 -> V_186 ) ;
F_69 ( & V_231 -> V_11 ) ;
F_110 ( & V_231 -> V_11 ) ;
if ( V_10 && V_10 -> V_253 )
F_101 ( V_2 -> V_176 ) ;
F_111 ( V_2 -> V_176 ) ;
F_32 ( V_2 -> V_5 , V_103 , V_250 ) ;
F_76 ( & V_2 -> V_102 ) ;
if ( V_2 -> V_5 )
F_107 ( V_2 -> V_5 ) ;
V_207 [ 0 ] = F_85 ( V_231 , 0 ) ;
V_207 [ 1 ] = F_85 ( V_231 , 1 ) ;
F_102 ( V_207 [ 0 ] , V_2 ) ;
F_102 ( V_207 [ 1 ] , V_2 ) ;
F_90 ( V_231 , NULL ) ;
F_106 ( V_2 -> V_176 ) ;
F_112 ( & V_231 -> V_11 ) ;
F_68 ( V_2 -> V_186 ) ;
F_105 ( & V_231 -> V_11 ) ;
return 0 ;
}
static int F_113 ( struct V_15 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
int V_29 = F_115 ( V_2 -> V_176 ) ;
if ( ! V_29 )
F_32 ( V_2 -> V_5 , V_103 , V_250 ) ;
return V_29 ;
}
static int F_116 ( struct V_15 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
return F_117 ( V_2 -> V_176 ) ;
}
