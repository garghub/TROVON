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
F_6 ( & V_2 -> V_7 -> V_8 , L_1 ) ;
if ( F_7 ( ! V_2 -> V_9 , L_2 ,
F_8 ( & V_2 -> V_7 -> V_8 ) ) )
return;
if ( V_2 -> V_9 -> V_10 & V_11 )
F_9 ( V_2 -> V_12 -> V_13 -> V_8 ,
V_2 -> V_9 -> V_14 , V_2 -> V_9 -> V_15 ,
V_16 ) ;
else
F_9 ( V_2 -> V_17 -> V_13 -> V_8 ,
V_2 -> V_9 -> V_14 , V_2 -> V_9 -> V_15 ,
V_18 ) ;
F_10 ( & V_2 -> V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_20 * V_14 = V_2 -> V_9 -> V_14 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 = V_2 -> V_12 ;
T_2 V_25 = - V_26 ;
int V_27 ;
V_27 = F_12 ( V_24 -> V_13 -> V_8 , V_14 , V_2 -> V_9 -> V_15 ,
V_16 ) ;
if ( V_27 > 0 ) {
V_2 -> V_28 = true ;
V_22 = V_24 -> V_13 -> V_29 ( V_24 , V_14 , V_27 ,
V_16 , V_30 | V_31 ) ;
}
if ( V_22 ) {
V_22 -> V_32 = F_5 ;
V_22 -> V_33 = V_2 ;
V_25 = F_13 ( V_22 ) ;
F_1 ( V_2 , V_34 , V_35 ) ;
F_14 ( V_24 ) ;
}
F_6 ( & V_2 -> V_7 -> V_8 , L_3 ,
V_36 , V_2 -> V_9 -> V_15 , V_27 , V_25 ) ;
if ( ! V_22 ) {
if ( V_27 >= 0 )
V_27 = - V_37 ;
V_2 -> V_12 = NULL ;
V_2 -> V_28 = false ;
F_15 ( V_24 ) ;
V_24 = V_2 -> V_17 ;
if ( V_24 ) {
V_2 -> V_17 = NULL ;
F_15 ( V_24 ) ;
}
F_16 ( & V_2 -> V_7 -> V_8 ,
L_4 , V_27 ) ;
F_4 ( V_2 , V_34 , V_35 | V_38 ) ;
}
F_6 ( & V_2 -> V_7 -> V_8 , L_5 , V_36 ,
V_22 , V_25 , V_2 -> V_9 -> V_15 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_20 * V_14 = V_2 -> V_9 -> V_14 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 = V_2 -> V_17 ;
T_2 V_25 = - V_26 ;
int V_27 ;
V_27 = F_12 ( V_24 -> V_13 -> V_8 , V_14 , V_2 -> V_9 -> V_15 ,
V_18 ) ;
if ( V_27 > 0 ) {
V_2 -> V_28 = true ;
V_22 = V_24 -> V_13 -> V_29 ( V_24 , V_14 , V_27 ,
V_18 , V_30 | V_31 ) ;
}
if ( V_22 ) {
V_22 -> V_32 = F_5 ;
V_22 -> V_33 = V_2 ;
V_25 = F_13 ( V_22 ) ;
F_1 ( V_2 , V_34 , V_38 ) ;
F_14 ( V_24 ) ;
}
F_6 ( & V_2 -> V_7 -> V_8 , L_3 ,
V_36 , V_2 -> V_9 -> V_15 , V_27 , V_25 ) ;
if ( ! V_22 ) {
if ( V_27 >= 0 )
V_27 = - V_37 ;
V_2 -> V_17 = NULL ;
V_2 -> V_28 = false ;
F_15 ( V_24 ) ;
V_24 = V_2 -> V_12 ;
if ( V_24 ) {
V_2 -> V_12 = NULL ;
F_15 ( V_24 ) ;
}
F_16 ( & V_2 -> V_7 -> V_8 ,
L_4 , V_27 ) ;
F_4 ( V_2 , V_34 , V_35 | V_38 ) ;
}
F_6 ( & V_2 -> V_7 -> V_8 , L_6 , V_36 ,
V_22 , V_25 ) ;
}
static bool F_18 ( struct V_23 * V_24 , void * V_6 )
{
F_6 ( V_24 -> V_13 -> V_8 , L_7 , V_36 , V_6 ) ;
V_24 -> V_39 = V_6 ;
return true ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
V_2 -> V_28 = false ;
if ( V_41 -> V_42 ) {
T_3 V_43 ;
F_20 ( V_43 ) ;
F_21 ( V_44 , V_43 ) ;
V_2 -> V_17 = F_22 ( V_43 , F_18 ,
& V_41 -> V_42 -> V_45 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_8 , V_36 ,
V_2 -> V_17 ) ;
if ( ! V_2 -> V_17 )
return;
V_2 -> V_12 = F_22 ( V_43 , F_18 ,
& V_41 -> V_42 -> V_46 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_9 , V_36 ,
V_2 -> V_12 ) ;
if ( ! V_2 -> V_12 ) {
F_15 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return;
}
F_23 ( & V_2 -> V_19 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_34 , V_35 | V_38 ) ;
if ( V_2 -> V_17 ) {
struct V_23 * V_24 = V_2 -> V_17 ;
V_2 -> V_17 = NULL ;
F_15 ( V_24 ) ;
}
if ( V_2 -> V_12 ) {
struct V_23 * V_24 = V_2 -> V_12 ;
V_2 -> V_12 = NULL ;
F_15 ( V_24 ) ;
}
V_2 -> V_28 = false ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_47 )
{
struct V_40 * V_48 = V_2 -> V_7 -> V_8 . V_49 ;
F_4 ( V_2 , V_50 , V_51 ) ;
F_4 ( V_2 , V_50 , V_52 ) ;
if ( ! V_47 )
return;
if ( V_48 -> V_53 && V_47 == V_2 -> V_47 )
F_1 ( V_2 , V_50 , V_54 ) ;
else
F_1 ( V_2 , V_50 , V_52 &
( F_26 ( F_27 ( V_2 -> V_47 / V_47 ) ) << 16 ) ) ;
F_1 ( V_2 , V_50 , V_51 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_55 = 0x010f0000 & F_29 ( V_2 -> V_5 , V_50 ) ;
F_30 ( V_2 -> V_5 , V_56 , V_57 ) ;
F_30 ( V_2 -> V_5 , V_56 , V_58 ) ;
F_1 ( V_2 , V_50 , V_55 |
V_59 | V_60 | V_61 | V_62 ) ;
F_1 ( V_2 , V_34 , V_63 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_64 , V_65 ;
int V_27 , V_66 = 10000000 ;
V_2 -> V_67 = false ;
V_64 = F_29 ( V_2 -> V_5 , V_68 ) ;
V_65 = F_29 ( V_2 -> V_5 , V_69 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_10 , V_64 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_11 , V_65 ) ;
if ( V_64 & V_70 ) {
F_1 ( V_2 , V_71 , V_72 ) ;
F_1 ( V_2 , V_71 , ~ V_72 ) ;
while ( 1 ) {
V_66 -- ;
if ( V_66 < 0 ) {
F_32 ( & V_2 -> V_7 -> V_8 ,
L_12 ) ;
return - V_37 ;
}
if ( ! ( F_29 ( V_2 -> V_5 , V_68 )
& V_70 ) )
break;
F_33 ( 1 ) ;
}
F_28 ( V_2 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_13 ) ;
return - V_37 ;
}
if ( V_65 & V_73 ) {
F_6 ( & V_2 -> V_7 -> V_8 , L_14 ) ;
V_27 = - V_37 ;
} else if ( V_65 & V_74 ) {
F_6 ( & V_2 -> V_7 -> V_8 , L_15 ) ;
V_27 = - V_75 ;
} else {
F_6 ( & V_2 -> V_7 -> V_8 , L_16 ) ;
V_27 = - V_37 ;
}
return V_27 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_78 * V_9 = V_77 -> V_9 ;
long time ;
T_1 V_79 , V_80 , * V_48 = F_35 ( V_9 -> V_14 ) ;
F_1 ( V_2 , V_81 , V_82 ) ;
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 || V_2 -> V_67 )
return F_31 ( V_2 ) ;
V_79 = ( V_84 &
F_29 ( V_2 -> V_5 , V_85 ) ) + 3 ;
for ( V_80 = 0 ; V_80 < V_79 / 4 ; V_80 ++ )
* V_48 ++ = F_29 ( V_2 -> V_5 , V_86 ) ;
F_1 ( V_2 , V_81 , V_87 ) ;
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 || V_2 -> V_67 )
return F_31 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_78 * V_9 = V_77 -> V_9 ;
long time ;
T_1 V_79 , V_80 , V_88 , V_89 , * V_48 ;
V_79 = V_84 & F_29 ( V_2 -> V_5 ,
V_85 ) ;
for ( V_88 = 0 ; V_88 < V_9 -> V_15 ; V_88 ++ ) {
V_48 = F_35 ( V_9 -> V_14 ) ;
for ( V_89 = 0 ; V_89 < V_9 -> V_14 -> V_90 / V_79 ; V_89 ++ ) {
F_1 ( V_2 , V_81 , V_82 ) ;
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 || V_2 -> V_67 )
return F_31 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < V_79 / 4 ; V_80 ++ )
* V_48 ++ = F_29 ( V_2 -> V_5 ,
V_86 ) ;
}
if ( V_88 < V_9 -> V_15 - 1 )
V_9 -> V_14 ++ ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_78 * V_9 = V_77 -> V_9 ;
long time ;
T_1 V_79 , V_80 , * V_48 = F_35 ( V_9 -> V_14 ) ;
F_1 ( V_2 , V_81 , V_91 ) ;
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 || V_2 -> V_67 )
return F_31 ( V_2 ) ;
V_79 = ( V_84 &
F_29 ( V_2 -> V_5 , V_85 ) ) + 3 ;
for ( V_80 = 0 ; V_80 < V_79 / 4 ; V_80 ++ )
F_30 ( V_2 -> V_5 , V_86 , * V_48 ++ ) ;
F_1 ( V_2 , V_81 , V_92 ) ;
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 || V_2 -> V_67 )
return F_31 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_78 * V_9 = V_77 -> V_9 ;
long time ;
T_1 V_80 , V_89 , V_88 , V_79 , * V_48 ;
V_79 = V_84 & F_29 ( V_2 -> V_5 ,
V_85 ) ;
for ( V_88 = 0 ; V_88 < V_9 -> V_15 ; V_88 ++ ) {
V_48 = F_35 ( V_9 -> V_14 ) ;
for ( V_89 = 0 ; V_89 < V_9 -> V_14 -> V_90 / V_79 ; V_89 ++ ) {
F_1 ( V_2 , V_81 , V_91 ) ;
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 || V_2 -> V_67 )
return F_31 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < V_79 / 4 ; V_80 ++ )
F_30 ( V_2 -> V_5 ,
V_86 , * V_48 ++ ) ;
}
if ( V_88 < V_9 -> V_15 - 1 )
V_9 -> V_14 ++ ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
if ( V_94 -> V_10 & V_95 ) {
V_94 -> V_96 [ 0 ] = F_29 ( V_2 -> V_5 , V_97 ) ;
V_94 -> V_96 [ 1 ] = F_29 ( V_2 -> V_5 , V_98 ) ;
V_94 -> V_96 [ 2 ] = F_29 ( V_2 -> V_5 , V_99 ) ;
V_94 -> V_96 [ 3 ] = F_29 ( V_2 -> V_5 , V_100 ) ;
} else
V_94 -> V_96 [ 0 ] = F_29 ( V_2 -> V_5 , V_100 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
V_94 -> V_96 [ 0 ] = F_29 ( V_2 -> V_5 , V_101 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_76 * V_77 , struct V_93 * V_94 , T_1 V_102 )
{
T_1 V_55 = 0 ;
switch ( F_43 ( V_94 ) ) {
case V_103 :
V_55 |= V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
V_55 |= V_108 ;
break;
case V_109 :
V_55 |= V_110 ;
break;
default:
F_32 ( & V_2 -> V_7 -> V_8 , L_17 ) ;
break;
}
switch ( V_102 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_55 |= V_117 ;
break;
}
if ( V_2 -> V_9 ) {
V_55 |= V_118 ;
switch ( V_2 -> V_119 ) {
case V_120 :
V_55 |= V_121 ;
break;
case V_122 :
V_55 |= V_123 ;
break;
case V_124 :
V_55 |= V_125 ;
break;
default:
F_32 ( & V_2 -> V_7 -> V_8 , L_18 ) ;
break;
}
}
if ( V_102 == V_126 || V_102 == V_127 )
V_55 |= V_128 ;
if ( V_102 == V_129 || V_102 == V_127 ) {
V_55 |= V_130 | V_131 ;
F_1 ( V_2 , V_85 ,
V_77 -> V_9 -> V_132 << 16 ) ;
}
if ( V_102 == V_133 || V_102 == V_134 ||
V_102 == V_135 || V_102 == V_136 )
V_55 |= V_137 ;
if ( V_102 == V_133 )
V_55 |= V_138 ;
if ( V_102 == V_134 ||
V_102 == V_135 || V_102 == V_136 )
V_55 |= V_139 ;
return V_102 = ( ( V_102 << 24 ) | V_55 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_76 * V_77 , T_1 V_102 )
{
int V_27 ;
switch ( V_102 ) {
case V_129 :
V_27 = F_37 ( V_2 , V_77 ) ;
break;
case V_127 :
V_27 = F_39 ( V_2 , V_77 ) ;
break;
case V_126 :
V_27 = F_38 ( V_2 , V_77 ) ;
break;
case V_140 :
case V_141 :
V_27 = F_34 ( V_2 , V_77 ) ;
break;
default:
F_32 ( & V_2 -> V_7 -> V_8 , L_19 , V_102 ) ;
V_27 = - V_26 ;
break;
}
return V_27 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_76 * V_77 , struct V_93 * V_94 )
{
long time ;
int V_27 = 0 , V_43 = 0 ;
T_1 V_102 = V_94 -> V_142 ;
switch ( V_102 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_43 = V_143 ;
break;
default:
V_43 = V_144 ;
break;
}
V_43 |= V_145 | V_146 | V_147 |
V_148 | V_149 | V_150 |
V_151 | V_152 | V_153 |
V_154 | V_155 | V_156 ;
if ( V_2 -> V_9 ) {
F_30 ( V_2 -> V_5 , V_85 , 0 ) ;
F_30 ( V_2 -> V_5 , V_85 ,
V_77 -> V_9 -> V_157 ) ;
}
V_102 = F_42 ( V_2 , V_77 , V_94 , V_102 ) ;
F_30 ( V_2 -> V_5 , V_158 , 0xD80430C0 ) ;
F_30 ( V_2 -> V_5 , V_81 , V_43 ) ;
F_30 ( V_2 -> V_5 , V_159 , V_94 -> V_6 ) ;
F_30 ( V_2 -> V_5 , V_160 , V_102 ) ;
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 ) {
V_94 -> error = F_31 ( V_2 ) ;
return;
}
if ( V_2 -> V_67 ) {
switch ( V_94 -> V_142 ) {
case V_134 :
case V_161 :
case V_162 :
V_94 -> error = - V_75 ;
break;
default:
F_6 ( & V_2 -> V_7 -> V_8 , L_20 ,
V_94 -> V_142 ) ;
V_94 -> error = F_31 ( V_2 ) ;
break;
}
V_2 -> V_67 = false ;
return;
}
if ( ! ( V_94 -> V_10 & V_163 ) ) {
V_94 -> error = 0 ;
return;
}
F_40 ( V_2 , V_94 ) ;
if ( V_2 -> V_9 ) {
if ( ! V_2 -> V_28 ) {
V_27 = F_44 ( V_2 , V_77 , V_94 -> V_142 ) ;
} else {
long time =
F_36 ( & V_2 -> V_19 ,
V_2 -> V_66 ) ;
if ( ! time )
V_27 = - V_75 ;
else if ( time < 0 )
V_27 = time ;
F_4 ( V_2 , V_34 ,
V_35 | V_38 ) ;
V_2 -> V_28 = false ;
}
if ( V_27 < 0 )
V_77 -> V_9 -> V_164 = 0 ;
else
V_77 -> V_9 -> V_164 =
V_77 -> V_9 -> V_132 * V_77 -> V_9 -> V_157 ;
}
V_94 -> error = V_27 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_76 * V_77 , struct V_93 * V_94 )
{
long time ;
if ( V_77 -> V_94 -> V_142 == V_129 )
F_1 ( V_2 , V_81 , V_165 ) ;
else if ( V_77 -> V_94 -> V_142 == V_127 )
F_1 ( V_2 , V_81 , V_166 ) ;
else {
F_32 ( & V_2 -> V_7 -> V_8 , L_21 ) ;
V_94 -> error = F_31 ( V_2 ) ;
return;
}
time = F_36 ( & V_2 -> V_83 ,
V_2 -> V_66 ) ;
if ( time <= 0 || V_2 -> V_67 ) {
V_94 -> error = F_31 ( V_2 ) ;
return;
}
F_41 ( V_2 , V_94 ) ;
V_94 -> error = 0 ;
}
static void F_47 ( struct V_167 * V_168 , struct V_76 * V_77 )
{
struct V_1 * V_2 = F_48 ( V_168 ) ;
unsigned long V_10 ;
F_49 ( & V_2 -> V_169 , V_10 ) ;
if ( V_2 -> V_170 != V_171 ) {
F_50 ( & V_2 -> V_169 , V_10 ) ;
V_77 -> V_94 -> error = - V_172 ;
F_51 ( V_168 , V_77 ) ;
return;
}
V_2 -> V_170 = V_173 ;
F_50 ( & V_2 -> V_169 , V_10 ) ;
switch ( V_77 -> V_94 -> V_142 ) {
case V_174 :
case V_162 :
V_2 -> V_170 = V_171 ;
V_77 -> V_94 -> error = - V_75 ;
F_51 ( V_168 , V_77 ) ;
return;
case V_141 :
if ( ! V_77 -> V_9 ) {
V_2 -> V_170 = V_171 ;
V_77 -> V_94 -> error = - V_75 ;
F_51 ( V_168 , V_77 ) ;
return;
}
break;
default:
break;
}
V_2 -> V_9 = V_77 -> V_9 ;
if ( V_77 -> V_9 ) {
if ( V_77 -> V_9 -> V_10 & V_11 ) {
if ( V_2 -> V_12 )
F_11 ( V_2 ) ;
} else {
if ( V_2 -> V_17 )
F_17 ( V_2 ) ;
}
}
F_45 ( V_2 , V_77 , V_77 -> V_94 ) ;
V_2 -> V_9 = NULL ;
if ( ! V_77 -> V_94 -> error && V_77 -> V_175 )
F_46 ( V_2 , V_77 , V_77 -> V_175 ) ;
V_2 -> V_170 = V_171 ;
F_51 ( V_168 , V_77 ) ;
}
static void F_52 ( struct V_167 * V_168 , struct V_176 * V_177 )
{
struct V_1 * V_2 = F_48 ( V_168 ) ;
struct V_40 * V_48 = V_2 -> V_7 -> V_8 . V_49 ;
unsigned long V_10 ;
F_49 ( & V_2 -> V_169 , V_10 ) ;
if ( V_2 -> V_170 != V_171 ) {
F_50 ( & V_2 -> V_169 , V_10 ) ;
return;
}
V_2 -> V_170 = V_178 ;
F_50 ( & V_2 -> V_169 , V_10 ) ;
if ( V_177 -> V_179 == V_180 ) {
if ( ! V_2 -> V_181 ) {
F_19 ( V_2 , V_2 -> V_7 -> V_8 . V_49 ) ;
V_2 -> V_181 = true ;
}
} else if ( V_177 -> V_179 == V_182 || ! V_177 -> clock ) {
F_25 ( V_2 , 0 ) ;
if ( V_177 -> V_179 == V_182 ) {
if ( V_2 -> V_181 ) {
F_24 ( V_2 ) ;
V_2 -> V_181 = false ;
}
}
if ( V_2 -> V_183 ) {
F_53 ( & V_2 -> V_7 -> V_8 ) ;
V_2 -> V_183 = false ;
if ( V_48 -> V_184 )
V_48 -> V_184 ( V_2 -> V_7 ) ;
}
V_2 -> V_170 = V_171 ;
return;
}
if ( V_177 -> clock ) {
if ( ! V_2 -> V_183 ) {
if ( V_48 -> V_185 )
V_48 -> V_185 ( V_2 -> V_7 , V_177 -> V_179 ) ;
F_54 ( & V_2 -> V_7 -> V_8 ) ;
V_2 -> V_183 = true ;
F_28 ( V_2 ) ;
}
F_25 ( V_2 , V_177 -> clock ) ;
}
V_2 -> V_119 = V_177 -> V_119 ;
V_2 -> V_170 = V_171 ;
}
static int F_55 ( struct V_167 * V_168 )
{
struct V_1 * V_2 = F_48 ( V_168 ) ;
struct V_40 * V_48 = V_2 -> V_7 -> V_8 . V_49 ;
if ( ! V_48 -> V_186 )
return - V_187 ;
else
return V_48 -> V_186 ( V_2 -> V_7 ) ;
}
static void F_56 ( struct V_167 * V_168 )
{
F_57 ( V_168 , 0 ) ;
}
static T_4 F_58 ( int V_188 , void * V_189 )
{
struct V_1 * V_2 = V_189 ;
T_1 V_170 ;
int V_190 = 0 ;
V_170 = F_29 ( V_2 -> V_5 , V_158 ) ;
if ( V_170 & V_191 ) {
F_30 ( V_2 -> V_5 , V_158 ,
~ ( V_191 | V_192 ) ) ;
F_4 ( V_2 , V_81 , V_143 ) ;
} else if ( V_170 & V_192 ) {
F_30 ( V_2 -> V_5 , V_158 , ~ V_192 ) ;
F_4 ( V_2 , V_81 , V_144 ) ;
} else if ( V_170 & V_193 ) {
F_30 ( V_2 -> V_5 , V_158 , ~ V_193 ) ;
F_4 ( V_2 , V_81 , V_82 ) ;
} else if ( V_170 & V_194 ) {
F_30 ( V_2 -> V_5 , V_158 , ~ V_194 ) ;
F_4 ( V_2 , V_81 , V_91 ) ;
} else if ( V_170 & V_195 ) {
F_30 ( V_2 -> V_5 , V_158 ,
~ ( V_195 | V_196 |
V_197 | V_198 ) ) ;
F_4 ( V_2 , V_81 , V_165 ) ;
} else if ( V_170 & V_198 ) {
F_30 ( V_2 -> V_5 , V_158 , ~ V_198 ) ;
F_4 ( V_2 , V_81 , V_87 ) ;
} else if ( V_170 & V_199 ) {
F_30 ( V_2 -> V_5 , V_158 , ~ V_199 ) ;
F_4 ( V_2 , V_81 , V_92 ) ;
} else if ( V_170 & V_196 ) {
F_30 ( V_2 -> V_5 , V_158 ,
~ ( V_196 | V_197 ) ) ;
F_4 ( V_2 , V_81 , V_166 ) ;
} else if ( V_170 & V_200 ) {
F_30 ( V_2 -> V_5 , V_158 , ~ V_170 ) ;
F_4 ( V_2 , V_81 , V_170 ) ;
V_190 = 1 ;
} else {
F_6 ( & V_2 -> V_7 -> V_8 , L_22 , V_170 ) ;
F_30 ( V_2 -> V_5 , V_158 , ~ V_170 ) ;
F_4 ( V_2 , V_81 , V_170 ) ;
V_190 = 1 ;
}
if ( V_190 ) {
V_2 -> V_67 = true ;
F_6 ( & V_2 -> V_7 -> V_8 , L_23 , V_170 ) ;
}
if ( V_170 & ~ ( V_196 | V_197 ) )
F_10 ( & V_2 -> V_83 ) ;
else
F_6 ( & V_2 -> V_7 -> V_8 , L_24 , V_170 ) ;
return V_201 ;
}
static int T_5 F_59 ( struct V_202 * V_203 )
{
int V_27 = 0 , V_188 [ 2 ] ;
struct V_167 * V_168 ;
struct V_1 * V_2 ;
struct V_40 * V_7 ;
struct V_204 * V_205 ;
void T_6 * V_3 ;
char V_206 [ 8 ] ;
V_188 [ 0 ] = F_60 ( V_203 , 0 ) ;
V_188 [ 1 ] = F_60 ( V_203 , 1 ) ;
if ( V_188 [ 0 ] < 0 || V_188 [ 1 ] < 0 ) {
F_32 ( & V_203 -> V_8 , L_25 ) ;
return - V_207 ;
}
V_205 = F_61 ( V_203 , V_208 , 0 ) ;
if ( ! V_205 ) {
F_32 ( & V_203 -> V_8 , L_26 ) ;
return - V_207 ;
}
V_3 = F_62 ( V_205 -> V_209 , F_63 ( V_205 ) ) ;
if ( ! V_3 ) {
F_32 ( & V_203 -> V_8 , L_27 ) ;
return - V_210 ;
}
V_7 = V_203 -> V_8 . V_49 ;
if ( ! V_7 ) {
F_32 ( & V_203 -> V_8 , L_28 ) ;
V_27 = - V_207 ;
goto V_211;
}
V_168 = F_64 ( sizeof( struct V_1 ) , & V_203 -> V_8 ) ;
if ( ! V_168 ) {
V_27 = - V_210 ;
goto V_211;
}
V_2 = F_48 ( V_168 ) ;
V_2 -> V_168 = V_168 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_66 = 1000 ;
snprintf ( V_206 , sizeof( V_206 ) , L_29 , V_203 -> V_212 ) ;
V_2 -> V_213 = F_65 ( & V_203 -> V_8 , V_206 ) ;
if ( F_66 ( V_2 -> V_213 ) ) {
F_32 ( & V_203 -> V_8 , L_30 , V_206 ) ;
V_27 = F_67 ( V_2 -> V_213 ) ;
goto V_214;
}
F_68 ( V_2 -> V_213 ) ;
V_2 -> V_47 = F_69 ( V_2 -> V_213 ) ;
V_2 -> V_7 = V_203 ;
F_23 ( & V_2 -> V_83 ) ;
F_70 ( & V_2 -> V_169 ) ;
V_168 -> V_215 = & V_216 ;
V_168 -> V_217 = V_2 -> V_47 ;
if ( V_168 -> V_217 < 51200000 )
V_168 -> V_218 = V_168 -> V_217 / 128 ;
else if ( V_168 -> V_217 < 102400000 )
V_168 -> V_218 = V_168 -> V_217 / 256 ;
else
V_168 -> V_218 = V_168 -> V_217 / 512 ;
if ( V_7 -> V_219 )
V_168 -> V_220 = V_7 -> V_219 ;
V_168 -> V_221 = V_222 ;
if ( V_7 -> V_221 )
V_168 -> V_221 |= V_7 -> V_221 ;
V_168 -> V_223 = 32 ;
V_168 -> V_224 = 512 ;
V_168 -> V_225 = V_226 * V_168 -> V_223 ;
V_168 -> V_227 = V_168 -> V_225 / V_168 -> V_224 ;
V_168 -> V_228 = V_168 -> V_225 ;
F_28 ( V_2 ) ;
F_71 ( V_203 , V_2 ) ;
F_72 ( & V_203 -> V_8 ) ;
V_2 -> V_183 = false ;
V_27 = F_73 ( & V_203 -> V_8 ) ;
if ( V_27 < 0 )
goto V_229;
F_74 ( V_168 ) ;
F_30 ( V_2 -> V_5 , V_81 , V_230 ) ;
V_27 = F_75 ( V_188 [ 0 ] , F_58 , 0 , L_31 , V_2 ) ;
if ( V_27 ) {
F_32 ( & V_203 -> V_8 , L_32 ) ;
goto V_231;
}
V_27 = F_75 ( V_188 [ 1 ] , F_58 , 0 , L_33 , V_2 ) ;
if ( V_27 ) {
F_76 ( V_188 [ 0 ] , V_2 ) ;
F_32 ( & V_203 -> V_8 , L_34 ) ;
goto V_231;
}
F_56 ( V_2 -> V_168 ) ;
F_77 ( & V_203 -> V_8 , L_35 , V_232 ) ;
F_6 ( & V_203 -> V_8 , L_36 ,
F_29 ( V_2 -> V_5 , V_56 ) & 0x0000ffff ) ;
return V_27 ;
V_231:
F_78 ( V_168 ) ;
F_79 ( & V_203 -> V_8 ) ;
V_229:
F_80 ( & V_203 -> V_8 ) ;
F_81 ( V_2 -> V_213 ) ;
V_214:
F_82 ( V_168 ) ;
V_211:
if ( V_3 )
F_83 ( V_3 ) ;
return V_27 ;
}
static int T_7 F_84 ( struct V_202 * V_203 )
{
struct V_1 * V_2 = F_85 ( V_203 ) ;
int V_188 [ 2 ] ;
F_54 ( & V_203 -> V_8 ) ;
F_78 ( V_2 -> V_168 ) ;
F_30 ( V_2 -> V_5 , V_81 , V_230 ) ;
if ( V_2 -> V_5 )
F_83 ( V_2 -> V_5 ) ;
V_188 [ 0 ] = F_60 ( V_203 , 0 ) ;
V_188 [ 1 ] = F_60 ( V_203 , 1 ) ;
F_76 ( V_188 [ 0 ] , V_2 ) ;
F_76 ( V_188 [ 1 ] , V_2 ) ;
F_71 ( V_203 , NULL ) ;
F_81 ( V_2 -> V_213 ) ;
F_82 ( V_2 -> V_168 ) ;
F_86 ( & V_203 -> V_8 ) ;
F_80 ( & V_203 -> V_8 ) ;
return 0 ;
}
static int F_87 ( struct V_13 * V_8 )
{
struct V_202 * V_203 = F_88 ( V_8 ) ;
struct V_1 * V_2 = F_85 ( V_203 ) ;
int V_27 = F_89 ( V_2 -> V_168 ) ;
if ( ! V_27 ) {
F_30 ( V_2 -> V_5 , V_81 , V_230 ) ;
F_81 ( V_2 -> V_213 ) ;
}
return V_27 ;
}
static int F_90 ( struct V_13 * V_8 )
{
struct V_202 * V_203 = F_88 ( V_8 ) ;
struct V_1 * V_2 = F_85 ( V_203 ) ;
F_68 ( V_2 -> V_213 ) ;
return F_91 ( V_2 -> V_168 ) ;
}
static int T_8 F_92 ( void )
{
return F_93 ( & V_233 ) ;
}
static void T_9 F_94 ( void )
{
F_95 ( & V_233 ) ;
}
