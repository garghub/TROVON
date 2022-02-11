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
V_24 = V_26 -> V_15 -> V_31 ( V_26 , V_16 , V_29 ,
V_32 , V_33 | V_34 ) ;
}
if ( V_24 ) {
V_24 -> V_35 = F_5 ;
V_24 -> V_36 = V_2 ;
V_27 = F_13 ( V_24 ) ;
F_1 ( V_2 , V_37 , V_38 ) ;
F_14 ( V_26 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_39 , V_8 -> V_17 , V_29 , V_27 ) ;
if ( ! V_24 ) {
if ( V_29 >= 0 )
V_29 = - V_40 ;
V_2 -> V_14 = NULL ;
V_2 -> V_30 = false ;
F_15 ( V_26 ) ;
V_26 = V_2 -> V_19 ;
if ( V_26 ) {
V_2 -> V_19 = NULL ;
F_15 ( V_26 ) ;
}
F_16 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_29 ) ;
F_4 ( V_2 , V_37 , V_38 | V_41 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_5 , V_39 ,
V_24 , V_27 , V_8 -> V_17 ) ;
}
static void F_17 ( struct V_1 * V_2 )
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
V_24 = V_26 -> V_15 -> V_31 ( V_26 , V_16 , V_29 ,
V_42 , V_33 | V_34 ) ;
}
if ( V_24 ) {
V_24 -> V_35 = F_5 ;
V_24 -> V_36 = V_2 ;
V_27 = F_13 ( V_24 ) ;
F_1 ( V_2 , V_37 , V_41 ) ;
F_14 ( V_26 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_39 , V_8 -> V_17 , V_29 , V_27 ) ;
if ( ! V_24 ) {
if ( V_29 >= 0 )
V_29 = - V_40 ;
V_2 -> V_19 = NULL ;
V_2 -> V_30 = false ;
F_15 ( V_26 ) ;
V_26 = V_2 -> V_14 ;
if ( V_26 ) {
V_2 -> V_14 = NULL ;
F_15 ( V_26 ) ;
}
F_16 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_29 ) ;
F_4 ( V_2 , V_37 , V_38 | V_41 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_6 , V_39 ,
V_24 , V_27 ) ;
}
static bool F_18 ( struct V_25 * V_26 , void * V_6 )
{
F_6 ( V_26 -> V_15 -> V_11 , L_7 , V_39 , V_6 ) ;
V_26 -> V_43 = V_6 ;
return true ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 , * V_48 ;
V_2 -> V_30 = false ;
if ( V_45 -> V_49 ) {
F_16 ( & V_2 -> V_10 -> V_11 ,
L_8 ) ;
V_47 = & V_45 -> V_49 -> V_50 ;
V_48 = & V_45 -> V_49 -> V_51 ;
} else {
V_47 = & V_2 -> V_52 ;
V_47 -> V_53 = V_45 -> V_54 ;
V_48 = & V_2 -> V_55 ;
V_48 -> V_53 = V_45 -> V_56 ;
}
if ( V_47 -> V_53 > 0 && V_48 -> V_53 > 0 ) {
T_3 V_57 ;
F_20 ( V_57 ) ;
F_21 ( V_58 , V_57 ) ;
V_2 -> V_19 = F_22 ( V_57 , F_18 , V_47 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_9 , V_39 ,
V_2 -> V_19 ) ;
if ( ! V_2 -> V_19 )
return;
V_2 -> V_14 = F_22 ( V_57 , F_18 , V_48 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_10 , V_39 ,
V_2 -> V_14 ) ;
if ( ! V_2 -> V_14 ) {
F_15 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
return;
}
F_23 ( & V_2 -> V_21 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_37 , V_38 | V_41 ) ;
if ( V_2 -> V_19 ) {
struct V_25 * V_26 = V_2 -> V_19 ;
V_2 -> V_19 = NULL ;
F_15 ( V_26 ) ;
}
if ( V_2 -> V_14 ) {
struct V_25 * V_26 = V_2 -> V_14 ;
V_2 -> V_14 = NULL ;
F_15 ( V_26 ) ;
}
V_2 -> V_30 = false ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_44 * V_60 = V_2 -> V_10 -> V_11 . V_61 ;
F_4 ( V_2 , V_62 , V_63 ) ;
F_4 ( V_2 , V_62 , V_64 ) ;
if ( ! V_59 )
return;
if ( V_60 -> V_65 && V_59 == V_2 -> V_59 )
F_1 ( V_2 , V_62 , V_66 ) ;
else
F_1 ( V_2 , V_62 , V_64 &
( ( F_26 ( V_2 -> V_59 / V_59 ) - 1 ) << 16 ) ) ;
F_1 ( V_2 , V_62 , V_63 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_67 ;
V_67 = 0x010f0000 & F_28 ( V_2 -> V_5 , V_62 ) ;
F_29 ( V_2 -> V_5 , V_68 , V_69 ) ;
F_29 ( V_2 -> V_5 , V_68 , V_70 ) ;
F_1 ( V_2 , V_62 , V_67 |
V_71 | V_72 | V_73 | V_74 ) ;
F_1 ( V_2 , V_37 , V_75 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_76 , V_77 ;
int V_29 , V_78 ;
V_2 -> V_79 = false ;
V_76 = F_28 ( V_2 -> V_5 , V_80 ) ;
V_77 = F_28 ( V_2 -> V_5 , V_81 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_11 , V_76 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_12 , V_77 ) ;
if ( V_76 & V_82 ) {
F_1 ( V_2 , V_83 , V_84 ) ;
F_1 ( V_2 , V_83 , ~ V_84 ) ;
for ( V_78 = 10000000 ; V_78 ; V_78 -- ) {
if ( ! ( F_28 ( V_2 -> V_5 , V_80 )
& V_82 ) )
break;
F_31 ( 1 ) ;
}
if ( ! V_78 ) {
F_32 ( & V_2 -> V_10 -> V_11 ,
L_13 ) ;
return - V_40 ;
}
F_27 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_14 ) ;
return - V_40 ;
}
if ( V_77 & V_85 ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_15 ) ;
V_29 = - V_40 ;
} else if ( V_77 & V_86 ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_16 ) ;
V_29 = - V_87 ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_17 ) ;
V_29 = - V_40 ;
}
return V_29 ;
}
static bool F_33 ( struct V_1 * V_2 , T_1 * V_60 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
V_2 -> V_88 += V_2 -> V_89 ;
F_34 ( V_2 -> V_88 > V_8 -> V_16 -> V_90 ) ;
if ( V_2 -> V_88 == V_8 -> V_16 -> V_90 ) {
V_2 -> V_88 = 0 ;
if ( ++ V_2 -> V_91 < V_8 -> V_17 )
V_2 -> V_92 = F_35 ( ++ V_8 -> V_16 ) ;
} else {
V_2 -> V_92 = V_60 ;
}
if ( V_2 -> V_91 == V_8 -> V_17 )
return false ;
return true ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_93 * V_9 )
{
V_2 -> V_89 = ( F_28 ( V_2 -> V_5 , V_94 ) &
V_95 ) + 3 ;
V_2 -> V_96 = V_97 ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
F_1 ( V_2 , V_99 , V_100 ) ;
}
static bool F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_60 = F_35 ( V_8 -> V_16 ) ;
int V_101 ;
if ( V_2 -> V_79 ) {
V_8 -> error = F_30 ( V_2 ) ;
return false ;
}
for ( V_101 = 0 ; V_101 < V_2 -> V_89 / 4 ; V_101 ++ )
* V_60 ++ = F_28 ( V_2 -> V_5 , V_102 ) ;
F_1 ( V_2 , V_99 , V_103 ) ;
V_2 -> V_96 = V_104 ;
return true ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_93 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
if ( ! V_8 -> V_17 || ! V_8 -> V_16 -> V_90 )
return;
V_2 -> V_89 = F_28 ( V_2 -> V_5 , V_94 ) &
V_95 ;
V_2 -> V_96 = V_105 ;
V_2 -> V_91 = 0 ;
V_2 -> V_88 = 0 ;
V_2 -> V_92 = F_35 ( V_8 -> V_16 ) ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
F_1 ( V_2 , V_99 , V_100 ) ;
}
static bool F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_60 = V_2 -> V_92 ;
int V_101 ;
if ( V_2 -> V_79 ) {
V_8 -> error = F_30 ( V_2 ) ;
return false ;
}
F_34 ( ! V_8 -> V_16 -> V_90 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_89 / 4 ; V_101 ++ )
* V_60 ++ = F_28 ( V_2 -> V_5 , V_102 ) ;
if ( ! F_33 ( V_2 , V_60 ) )
return false ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
F_1 ( V_2 , V_99 , V_100 ) ;
return true ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_93 * V_9 )
{
V_2 -> V_89 = ( F_28 ( V_2 -> V_5 , V_94 ) &
V_95 ) + 3 ;
V_2 -> V_96 = V_106 ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
F_1 ( V_2 , V_99 , V_107 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_60 = F_35 ( V_8 -> V_16 ) ;
int V_101 ;
if ( V_2 -> V_79 ) {
V_8 -> error = F_30 ( V_2 ) ;
return false ;
}
for ( V_101 = 0 ; V_101 < V_2 -> V_89 / 4 ; V_101 ++ )
F_29 ( V_2 -> V_5 , V_102 , * V_60 ++ ) ;
F_1 ( V_2 , V_99 , V_108 ) ;
V_2 -> V_96 = V_109 ;
return true ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_93 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
if ( ! V_8 -> V_17 || ! V_8 -> V_16 -> V_90 )
return;
V_2 -> V_89 = F_28 ( V_2 -> V_5 , V_94 ) &
V_95 ;
V_2 -> V_96 = V_110 ;
V_2 -> V_91 = 0 ;
V_2 -> V_88 = 0 ;
V_2 -> V_92 = F_35 ( V_8 -> V_16 ) ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
F_1 ( V_2 , V_99 , V_107 ) ;
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_60 = V_2 -> V_92 ;
int V_101 ;
if ( V_2 -> V_79 ) {
V_8 -> error = F_30 ( V_2 ) ;
return false ;
}
F_34 ( ! V_8 -> V_16 -> V_90 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_89 / 4 ; V_101 ++ )
F_29 ( V_2 -> V_5 , V_102 , * V_60 ++ ) ;
if ( ! F_33 ( V_2 , V_60 ) )
return false ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
F_1 ( V_2 , V_99 , V_107 ) ;
return true ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
if ( V_112 -> V_12 & V_113 ) {
V_112 -> V_114 [ 0 ] = F_28 ( V_2 -> V_5 , V_115 ) ;
V_112 -> V_114 [ 1 ] = F_28 ( V_2 -> V_5 , V_116 ) ;
V_112 -> V_114 [ 2 ] = F_28 ( V_2 -> V_5 , V_117 ) ;
V_112 -> V_114 [ 3 ] = F_28 ( V_2 -> V_5 , V_118 ) ;
} else
V_112 -> V_114 [ 0 ] = F_28 ( V_2 -> V_5 , V_118 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
V_112 -> V_114 [ 0 ] = F_28 ( V_2 -> V_5 , V_119 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_93 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_111 * V_112 = V_9 -> V_112 ;
T_1 V_120 = V_112 -> V_121 ;
T_1 V_67 = 0 ;
switch ( F_48 ( V_112 ) ) {
case V_122 :
V_67 |= V_123 ;
break;
case V_124 :
case V_125 :
case V_126 :
V_67 |= V_127 ;
break;
case V_128 :
V_67 |= V_129 ;
break;
default:
F_32 ( & V_2 -> V_10 -> V_11 , L_18 ) ;
break;
}
switch ( V_120 ) {
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
V_67 |= V_136 ;
break;
}
if ( V_8 ) {
V_67 |= V_137 ;
switch ( V_2 -> V_138 ) {
case V_139 :
V_67 |= V_140 ;
break;
case V_141 :
V_67 |= V_142 ;
break;
case V_143 :
V_67 |= V_144 ;
break;
default:
F_32 ( & V_2 -> V_10 -> V_11 , L_19 ) ;
break;
}
}
if ( V_120 == V_145 || V_120 == V_146 )
V_67 |= V_147 ;
if ( V_120 == V_148 || V_120 == V_146 ) {
V_67 |= V_149 | V_150 ;
F_1 ( V_2 , V_94 ,
V_8 -> V_151 << 16 ) ;
}
if ( V_120 == V_152 || V_120 == V_153 ||
V_120 == V_154 || V_120 == V_155 )
V_67 |= V_156 ;
if ( V_120 == V_152 )
V_67 |= V_157 ;
if ( V_120 == V_153 ||
V_120 == V_154 || V_120 == V_155 )
V_67 |= V_158 ;
return ( V_120 << 24 ) | V_67 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_93 * V_9 , T_1 V_120 )
{
switch ( V_120 ) {
case V_148 :
F_39 ( V_2 , V_9 ) ;
return 0 ;
case V_146 :
F_43 ( V_2 , V_9 ) ;
return 0 ;
case V_145 :
F_41 ( V_2 , V_9 ) ;
return 0 ;
case V_159 :
case V_160 :
F_36 ( V_2 , V_9 ) ;
return 0 ;
default:
F_32 ( & V_2 -> V_10 -> V_11 , L_20 , V_120 ) ;
return - V_28 ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_93 * V_9 )
{
struct V_111 * V_112 = V_9 -> V_112 ;
T_1 V_120 = V_112 -> V_121 ;
T_1 V_57 ;
switch ( V_120 ) {
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
V_57 = V_161 | V_162 ;
break;
default:
V_57 = V_161 | V_163 ;
break;
}
if ( V_9 -> V_8 ) {
F_29 ( V_2 -> V_5 , V_94 , 0 ) ;
F_29 ( V_2 -> V_5 , V_94 ,
V_9 -> V_8 -> V_164 ) ;
}
V_120 = F_47 ( V_2 , V_9 ) ;
F_29 ( V_2 -> V_5 , V_165 , 0xD80430C0 ) ;
F_29 ( V_2 -> V_5 , V_99 , V_57 ) ;
F_29 ( V_2 -> V_5 , V_166 , V_112 -> V_6 ) ;
F_29 ( V_2 -> V_5 , V_167 , V_120 ) ;
V_2 -> V_96 = V_168 ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_93 * V_9 )
{
switch ( V_9 -> V_112 -> V_121 ) {
case V_148 :
F_1 ( V_2 , V_99 , V_169 ) ;
break;
case V_146 :
F_1 ( V_2 , V_99 , V_170 ) ;
break;
default:
F_32 ( & V_2 -> V_10 -> V_11 , L_21 ) ;
V_9 -> V_171 -> error = F_30 ( V_2 ) ;
return;
}
V_2 -> V_96 = V_172 ;
F_37 ( & V_2 -> V_98 , V_2 -> V_78 ) ;
}
static void F_52 ( struct V_173 * V_174 , struct V_93 * V_9 )
{
struct V_1 * V_2 = F_53 ( V_174 ) ;
unsigned long V_12 ;
F_54 ( & V_2 -> V_175 , V_12 ) ;
if ( V_2 -> V_176 != V_177 ) {
F_55 ( & V_2 -> V_175 , V_12 ) ;
V_9 -> V_112 -> error = - V_178 ;
F_56 ( V_174 , V_9 ) ;
return;
}
V_2 -> V_176 = V_179 ;
F_55 ( & V_2 -> V_175 , V_12 ) ;
switch ( V_9 -> V_112 -> V_121 ) {
case V_180 :
case V_181 :
V_2 -> V_176 = V_177 ;
V_9 -> V_112 -> error = - V_87 ;
F_56 ( V_174 , V_9 ) ;
return;
case V_160 :
if ( ! V_9 -> V_8 ) {
V_2 -> V_176 = V_177 ;
V_9 -> V_112 -> error = - V_87 ;
F_56 ( V_174 , V_9 ) ;
return;
}
break;
default:
break;
}
V_2 -> V_9 = V_9 ;
F_50 ( V_2 , V_9 ) ;
}
static void F_57 ( struct V_173 * V_174 , struct V_182 * V_183 )
{
struct V_1 * V_2 = F_53 ( V_174 ) ;
struct V_44 * V_60 = V_2 -> V_10 -> V_11 . V_61 ;
unsigned long V_12 ;
F_54 ( & V_2 -> V_175 , V_12 ) ;
if ( V_2 -> V_176 != V_177 ) {
F_55 ( & V_2 -> V_175 , V_12 ) ;
return;
}
V_2 -> V_176 = V_184 ;
F_55 ( & V_2 -> V_175 , V_12 ) ;
if ( V_183 -> V_185 == V_186 ) {
if ( ! V_2 -> V_187 ) {
F_19 ( V_2 , V_2 -> V_10 -> V_11 . V_61 ) ;
V_2 -> V_187 = true ;
}
} else if ( V_183 -> V_185 == V_188 || ! V_183 -> clock ) {
F_25 ( V_2 , 0 ) ;
if ( V_183 -> V_185 == V_188 ) {
if ( V_2 -> V_187 ) {
F_24 ( V_2 ) ;
V_2 -> V_187 = false ;
}
}
if ( V_2 -> V_189 ) {
F_58 ( & V_2 -> V_10 -> V_11 ) ;
V_2 -> V_189 = false ;
if ( V_60 -> V_190 && V_183 -> V_185 == V_188 )
V_60 -> V_190 ( V_2 -> V_10 ) ;
}
V_2 -> V_176 = V_177 ;
return;
}
if ( V_183 -> clock ) {
if ( ! V_2 -> V_189 ) {
if ( V_60 -> V_191 )
V_60 -> V_191 ( V_2 -> V_10 , V_183 -> V_185 ) ;
F_59 ( & V_2 -> V_10 -> V_11 ) ;
V_2 -> V_189 = true ;
F_27 ( V_2 ) ;
}
F_25 ( V_2 , V_183 -> clock ) ;
}
V_2 -> V_138 = V_183 -> V_138 ;
V_2 -> V_176 = V_177 ;
}
static int F_60 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = F_53 ( V_174 ) ;
struct V_44 * V_60 = V_2 -> V_10 -> V_11 . V_61 ;
if ( ! V_60 -> V_192 )
return - V_193 ;
else
return V_60 -> V_192 ( V_2 -> V_10 ) ;
}
static bool F_61 ( struct V_1 * V_2 )
{
struct V_111 * V_112 = V_2 -> V_9 -> V_112 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
long time ;
if ( V_2 -> V_79 ) {
switch ( V_112 -> V_121 ) {
case V_153 :
case V_194 :
case V_181 :
V_112 -> error = - V_87 ;
V_2 -> V_79 = false ;
break;
default:
V_112 -> error = F_30 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_22 ,
V_112 -> V_121 , V_112 -> error ) ;
break;
}
return false ;
}
if ( ! ( V_112 -> V_12 & V_195 ) ) {
V_112 -> error = 0 ;
return false ;
}
F_45 ( V_2 , V_112 ) ;
if ( ! V_8 )
return false ;
if ( V_8 -> V_12 & V_13 ) {
if ( V_2 -> V_14 )
F_11 ( V_2 ) ;
} else {
if ( V_2 -> V_19 )
F_17 ( V_2 ) ;
}
if ( ! V_2 -> V_30 ) {
V_8 -> error = F_49 ( V_2 , V_2 -> V_9 , V_112 -> V_121 ) ;
if ( ! V_8 -> error )
return true ;
return false ;
}
time = F_62 ( & V_2 -> V_21 ,
V_2 -> V_78 ) ;
if ( V_2 -> V_79 ) {
F_32 ( V_2 -> V_174 -> V_196 ,
L_23 ) ;
if ( V_8 -> V_12 & V_13 )
F_63 ( V_2 -> V_14 ) ;
else
F_63 ( V_2 -> V_19 ) ;
V_8 -> error = F_30 ( V_2 ) ;
} else if ( ! time ) {
V_8 -> error = - V_87 ;
} else if ( time < 0 ) {
V_8 -> error = time ;
}
F_4 ( V_2 , V_37 ,
V_38 | V_41 ) ;
V_2 -> V_30 = false ;
if ( V_8 -> error )
V_8 -> V_197 = 0 ;
return false ;
}
static T_4 F_64 ( int V_198 , void * V_199 )
{
struct V_1 * V_2 = V_199 ;
struct V_93 * V_9 = V_2 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_8 ;
F_65 ( & V_2 -> V_98 ) ;
switch ( V_2 -> V_96 ) {
case V_200 :
return V_201 ;
case V_168 :
if ( F_61 ( V_2 ) )
return V_201 ;
break;
case V_105 :
if ( F_40 ( V_2 ) )
return V_201 ;
break;
case V_97 :
if ( F_38 ( V_2 ) )
return V_201 ;
break;
case V_110 :
if ( F_44 ( V_2 ) )
return V_201 ;
break;
case V_106 :
if ( F_42 ( V_2 ) )
return V_201 ;
break;
case V_172 :
if ( V_2 -> V_79 ) {
V_9 -> V_171 -> error = F_30 ( V_2 ) ;
break;
}
F_46 ( V_2 , V_9 -> V_171 ) ;
V_9 -> V_171 -> error = 0 ;
break;
case V_104 :
case V_109 :
if ( V_2 -> V_79 )
V_8 -> error = F_30 ( V_2 ) ;
break;
default:
F_66 () ;
}
if ( V_2 -> V_96 != V_172 ) {
if ( ! V_9 -> V_112 -> error && V_8 && ! V_8 -> error )
V_8 -> V_197 =
V_8 -> V_151 * V_8 -> V_164 ;
if ( V_9 -> V_171 && ! V_9 -> V_112 -> error && ( ! V_8 || ! V_8 -> error ) ) {
F_51 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_171 -> error )
return V_201 ;
}
}
V_2 -> V_96 = V_200 ;
V_2 -> V_176 = V_177 ;
V_2 -> V_9 = NULL ;
F_56 ( V_2 -> V_174 , V_9 ) ;
return V_201 ;
}
static T_4 F_67 ( int V_198 , void * V_199 )
{
struct V_1 * V_2 = V_199 ;
T_1 V_176 ;
int V_202 = 0 ;
V_176 = F_28 ( V_2 -> V_5 , V_165 ) ;
if ( V_176 & V_203 ) {
F_29 ( V_2 -> V_5 , V_165 , ~ V_176 ) ;
F_4 ( V_2 , V_99 , V_176 ) ;
V_202 = 1 ;
} else if ( V_176 & V_204 ) {
F_29 ( V_2 -> V_5 , V_165 ,
~ ( V_204 | V_205 ) ) ;
F_4 ( V_2 , V_99 , V_162 ) ;
} else if ( V_176 & V_205 ) {
F_29 ( V_2 -> V_5 , V_165 , ~ V_205 ) ;
F_4 ( V_2 , V_99 , V_163 ) ;
} else if ( V_176 & V_206 ) {
F_29 ( V_2 -> V_5 , V_165 , ~ V_206 ) ;
F_4 ( V_2 , V_99 , V_100 ) ;
} else if ( V_176 & V_207 ) {
F_29 ( V_2 -> V_5 , V_165 , ~ V_207 ) ;
F_4 ( V_2 , V_99 , V_107 ) ;
} else if ( V_176 & V_208 ) {
F_29 ( V_2 -> V_5 , V_165 ,
~ ( V_208 | V_209 |
V_210 | V_211 ) ) ;
F_4 ( V_2 , V_99 , V_169 ) ;
} else if ( V_176 & V_211 ) {
F_29 ( V_2 -> V_5 , V_165 , ~ V_211 ) ;
F_4 ( V_2 , V_99 , V_103 ) ;
} else if ( V_176 & V_212 ) {
F_29 ( V_2 -> V_5 , V_165 , ~ V_212 ) ;
F_4 ( V_2 , V_99 , V_108 ) ;
} else if ( V_176 & V_209 ) {
F_29 ( V_2 -> V_5 , V_165 ,
~ ( V_209 | V_210 ) ) ;
F_4 ( V_2 , V_99 , V_170 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_24 , V_176 ) ;
F_29 ( V_2 -> V_5 , V_165 , ~ V_176 ) ;
F_4 ( V_2 , V_99 , V_176 ) ;
V_202 = 1 ;
}
if ( V_202 ) {
V_2 -> V_79 = true ;
F_6 ( & V_2 -> V_10 -> V_11 , L_25 , V_176 ) ;
}
if ( V_176 & ~ ( V_209 | V_210 ) ) {
if ( ! V_2 -> V_30 )
return V_213 ;
else if ( V_2 -> V_79 )
F_5 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_26 , V_176 ) ;
}
return V_201 ;
}
static void F_68 ( struct V_214 * V_215 )
{
struct V_216 * V_217 = F_69 ( V_215 , struct V_216 , V_215 ) ;
struct V_1 * V_2 = F_69 ( V_217 , struct V_1 , V_98 ) ;
struct V_93 * V_9 = V_2 -> V_9 ;
if ( V_2 -> V_218 )
return;
switch ( V_2 -> V_96 ) {
case V_168 :
V_9 -> V_112 -> error = F_30 ( V_2 ) ;
break;
case V_172 :
V_9 -> V_171 -> error = F_30 ( V_2 ) ;
break;
case V_105 :
case V_110 :
case V_97 :
case V_106 :
case V_104 :
case V_109 :
V_9 -> V_8 -> error = F_30 ( V_2 ) ;
break;
default:
F_66 () ;
}
V_2 -> V_176 = V_177 ;
V_2 -> V_96 = V_200 ;
V_2 -> V_9 = NULL ;
F_56 ( V_2 -> V_174 , V_9 ) ;
}
static int T_5 F_70 ( struct V_219 * V_220 )
{
int V_29 = 0 , V_198 [ 2 ] ;
struct V_173 * V_174 ;
struct V_1 * V_2 ;
struct V_44 * V_10 ;
struct V_221 * V_222 ;
void T_6 * V_3 ;
char V_223 [ 8 ] ;
V_198 [ 0 ] = F_71 ( V_220 , 0 ) ;
V_198 [ 1 ] = F_71 ( V_220 , 1 ) ;
if ( V_198 [ 0 ] < 0 || V_198 [ 1 ] < 0 ) {
F_32 ( & V_220 -> V_11 , L_27 ) ;
return - V_224 ;
}
V_222 = F_72 ( V_220 , V_225 , 0 ) ;
if ( ! V_222 ) {
F_32 ( & V_220 -> V_11 , L_28 ) ;
return - V_224 ;
}
V_3 = F_73 ( V_222 -> V_226 , F_74 ( V_222 ) ) ;
if ( ! V_3 ) {
F_32 ( & V_220 -> V_11 , L_29 ) ;
return - V_227 ;
}
V_10 = V_220 -> V_11 . V_61 ;
if ( ! V_10 ) {
F_32 ( & V_220 -> V_11 , L_30 ) ;
V_29 = - V_224 ;
goto V_228;
}
V_174 = F_75 ( sizeof( struct V_1 ) , & V_220 -> V_11 ) ;
if ( ! V_174 ) {
V_29 = - V_227 ;
goto V_228;
}
V_2 = F_53 ( V_174 ) ;
V_2 -> V_174 = V_174 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_78 = 1000 ;
snprintf ( V_223 , sizeof( V_223 ) , L_31 , V_220 -> V_229 ) ;
V_2 -> V_230 = F_76 ( & V_220 -> V_11 , V_223 ) ;
if ( F_77 ( V_2 -> V_230 ) ) {
F_32 ( & V_220 -> V_11 , L_32 , V_223 ) ;
V_29 = F_78 ( V_2 -> V_230 ) ;
goto V_231;
}
F_79 ( V_2 -> V_230 ) ;
V_2 -> V_59 = F_80 ( V_2 -> V_230 ) ;
V_2 -> V_10 = V_220 ;
F_81 ( & V_2 -> V_175 ) ;
V_174 -> V_232 = & V_233 ;
V_174 -> V_234 = V_2 -> V_59 ;
if ( V_174 -> V_234 < 51200000 )
V_174 -> V_235 = V_174 -> V_234 / 128 ;
else if ( V_174 -> V_234 < 102400000 )
V_174 -> V_235 = V_174 -> V_234 / 256 ;
else
V_174 -> V_235 = V_174 -> V_234 / 512 ;
if ( V_10 -> V_236 )
V_174 -> V_237 = V_10 -> V_236 ;
V_174 -> V_238 = V_239 ;
if ( V_10 -> V_238 )
V_174 -> V_238 |= V_10 -> V_238 ;
V_174 -> V_240 = 32 ;
V_174 -> V_241 = 512 ;
V_174 -> V_242 = V_243 * V_174 -> V_240 ;
V_174 -> V_244 = V_174 -> V_242 / V_174 -> V_241 ;
V_174 -> V_245 = V_174 -> V_242 ;
F_27 ( V_2 ) ;
F_82 ( V_220 , V_2 ) ;
F_83 ( & V_220 -> V_11 ) ;
V_2 -> V_189 = false ;
V_29 = F_84 ( & V_220 -> V_11 ) ;
if ( V_29 < 0 )
goto V_246;
F_85 ( & V_2 -> V_98 , F_68 ) ;
F_29 ( V_2 -> V_5 , V_99 , V_247 ) ;
V_29 = F_86 ( V_198 [ 0 ] , F_67 , F_64 , 0 , L_33 , V_2 ) ;
if ( V_29 ) {
F_32 ( & V_220 -> V_11 , L_34 ) ;
goto V_248;
}
V_29 = F_86 ( V_198 [ 1 ] , F_67 , F_64 , 0 , L_35 , V_2 ) ;
if ( V_29 ) {
F_32 ( & V_220 -> V_11 , L_36 ) ;
goto V_249;
}
V_29 = F_87 ( V_174 ) ;
if ( V_29 < 0 )
goto V_250;
F_88 ( & V_220 -> V_11 , L_37 , V_251 ) ;
F_6 ( & V_220 -> V_11 , L_38 ,
F_28 ( V_2 -> V_5 , V_68 ) & 0x0000ffff ) ;
return V_29 ;
V_250:
F_89 ( V_198 [ 1 ] , V_2 ) ;
V_249:
F_89 ( V_198 [ 0 ] , V_2 ) ;
V_248:
F_90 ( & V_220 -> V_11 ) ;
V_246:
F_91 ( & V_220 -> V_11 ) ;
F_92 ( V_2 -> V_230 ) ;
V_231:
F_93 ( V_174 ) ;
V_228:
if ( V_3 )
F_94 ( V_3 ) ;
return V_29 ;
}
static int T_7 F_95 ( struct V_219 * V_220 )
{
struct V_1 * V_2 = F_96 ( V_220 ) ;
int V_198 [ 2 ] ;
V_2 -> V_218 = true ;
F_59 ( & V_220 -> V_11 ) ;
F_97 ( V_2 -> V_174 ) ;
F_29 ( V_2 -> V_5 , V_99 , V_247 ) ;
F_65 ( & V_2 -> V_98 ) ;
if ( V_2 -> V_5 )
F_94 ( V_2 -> V_5 ) ;
V_198 [ 0 ] = F_71 ( V_220 , 0 ) ;
V_198 [ 1 ] = F_71 ( V_220 , 1 ) ;
F_89 ( V_198 [ 0 ] , V_2 ) ;
F_89 ( V_198 [ 1 ] , V_2 ) ;
F_82 ( V_220 , NULL ) ;
F_92 ( V_2 -> V_230 ) ;
F_93 ( V_2 -> V_174 ) ;
F_98 ( & V_220 -> V_11 ) ;
F_91 ( & V_220 -> V_11 ) ;
return 0 ;
}
static int F_99 ( struct V_15 * V_11 )
{
struct V_219 * V_220 = F_100 ( V_11 ) ;
struct V_1 * V_2 = F_96 ( V_220 ) ;
int V_29 = F_101 ( V_2 -> V_174 ) ;
if ( ! V_29 ) {
F_29 ( V_2 -> V_5 , V_99 , V_247 ) ;
F_92 ( V_2 -> V_230 ) ;
}
return V_29 ;
}
static int F_102 ( struct V_15 * V_11 )
{
struct V_219 * V_220 = F_100 ( V_11 ) ;
struct V_1 * V_2 = F_96 ( V_220 ) ;
F_79 ( V_2 -> V_230 ) ;
return F_103 ( V_2 -> V_174 ) ;
}
