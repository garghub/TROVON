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
struct V_42 * V_43 , * V_44 ;
V_2 -> V_28 = false ;
if ( V_41 -> V_45 ) {
F_16 ( & V_2 -> V_7 -> V_8 ,
L_8 ) ;
V_43 = & V_41 -> V_45 -> V_46 ;
V_44 = & V_41 -> V_45 -> V_47 ;
} else {
V_43 = & V_2 -> V_48 ;
V_43 -> V_49 = V_41 -> V_50 ;
V_44 = & V_2 -> V_51 ;
V_44 -> V_49 = V_41 -> V_52 ;
}
if ( V_43 -> V_49 > 0 && V_44 -> V_49 > 0 ) {
T_3 V_53 ;
F_20 ( V_53 ) ;
F_21 ( V_54 , V_53 ) ;
V_2 -> V_17 = F_22 ( V_53 , F_18 , V_43 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_9 , V_36 ,
V_2 -> V_17 ) ;
if ( ! V_2 -> V_17 )
return;
V_2 -> V_12 = F_22 ( V_53 , F_18 , V_44 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_10 , V_36 ,
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
static void F_25 ( struct V_1 * V_2 , unsigned int V_55 )
{
struct V_40 * V_56 = V_2 -> V_7 -> V_8 . V_57 ;
F_4 ( V_2 , V_58 , V_59 ) ;
F_4 ( V_2 , V_58 , V_60 ) ;
if ( ! V_55 )
return;
if ( V_56 -> V_61 && V_55 == V_2 -> V_55 )
F_1 ( V_2 , V_58 , V_62 ) ;
else
F_1 ( V_2 , V_58 , V_60 &
( F_26 ( F_27 ( V_2 -> V_55 / V_55 ) ) << 16 ) ) ;
F_1 ( V_2 , V_58 , V_59 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_63 ;
V_63 = 0x010f0000 & F_29 ( V_2 -> V_5 , V_58 ) ;
F_30 ( V_2 -> V_5 , V_64 , V_65 ) ;
F_30 ( V_2 -> V_5 , V_64 , V_66 ) ;
F_1 ( V_2 , V_58 , V_63 |
V_67 | V_68 | V_69 | V_70 ) ;
F_1 ( V_2 , V_34 , V_71 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_72 , V_73 ;
int V_27 , V_74 = 10000000 ;
V_2 -> V_75 = false ;
V_72 = F_29 ( V_2 -> V_5 , V_76 ) ;
V_73 = F_29 ( V_2 -> V_5 , V_77 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_11 , V_72 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_12 , V_73 ) ;
if ( V_72 & V_78 ) {
F_1 ( V_2 , V_79 , V_80 ) ;
F_1 ( V_2 , V_79 , ~ V_80 ) ;
while ( 1 ) {
V_74 -- ;
if ( V_74 < 0 ) {
F_32 ( & V_2 -> V_7 -> V_8 ,
L_13 ) ;
return - V_37 ;
}
if ( ! ( F_29 ( V_2 -> V_5 , V_76 )
& V_78 ) )
break;
F_33 ( 1 ) ;
}
F_28 ( V_2 ) ;
F_6 ( & V_2 -> V_7 -> V_8 , L_14 ) ;
return - V_37 ;
}
if ( V_73 & V_81 ) {
F_6 ( & V_2 -> V_7 -> V_8 , L_15 ) ;
V_27 = - V_37 ;
} else if ( V_73 & V_82 ) {
F_6 ( & V_2 -> V_7 -> V_8 , L_16 ) ;
V_27 = - V_83 ;
} else {
F_6 ( & V_2 -> V_7 -> V_8 , L_17 ) ;
V_27 = - V_37 ;
}
return V_27 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_86 * V_9 = V_85 -> V_9 ;
long time ;
T_1 V_87 , V_88 , * V_56 = F_35 ( V_9 -> V_14 ) ;
F_1 ( V_2 , V_89 , V_90 ) ;
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 || V_2 -> V_75 )
return F_31 ( V_2 ) ;
V_87 = ( V_92 &
F_29 ( V_2 -> V_5 , V_93 ) ) + 3 ;
for ( V_88 = 0 ; V_88 < V_87 / 4 ; V_88 ++ )
* V_56 ++ = F_29 ( V_2 -> V_5 , V_94 ) ;
F_1 ( V_2 , V_89 , V_95 ) ;
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 || V_2 -> V_75 )
return F_31 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_86 * V_9 = V_85 -> V_9 ;
long time ;
T_1 V_87 , V_88 , V_96 , V_97 , * V_56 ;
V_87 = V_92 & F_29 ( V_2 -> V_5 ,
V_93 ) ;
for ( V_96 = 0 ; V_96 < V_9 -> V_15 ; V_96 ++ ) {
V_56 = F_35 ( V_9 -> V_14 ) ;
for ( V_97 = 0 ; V_97 < V_9 -> V_14 -> V_98 / V_87 ; V_97 ++ ) {
F_1 ( V_2 , V_89 , V_90 ) ;
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 || V_2 -> V_75 )
return F_31 ( V_2 ) ;
for ( V_88 = 0 ; V_88 < V_87 / 4 ; V_88 ++ )
* V_56 ++ = F_29 ( V_2 -> V_5 ,
V_94 ) ;
}
if ( V_96 < V_9 -> V_15 - 1 )
V_9 -> V_14 ++ ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_86 * V_9 = V_85 -> V_9 ;
long time ;
T_1 V_87 , V_88 , * V_56 = F_35 ( V_9 -> V_14 ) ;
F_1 ( V_2 , V_89 , V_99 ) ;
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 || V_2 -> V_75 )
return F_31 ( V_2 ) ;
V_87 = ( V_92 &
F_29 ( V_2 -> V_5 , V_93 ) ) + 3 ;
for ( V_88 = 0 ; V_88 < V_87 / 4 ; V_88 ++ )
F_30 ( V_2 -> V_5 , V_94 , * V_56 ++ ) ;
F_1 ( V_2 , V_89 , V_100 ) ;
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 || V_2 -> V_75 )
return F_31 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_86 * V_9 = V_85 -> V_9 ;
long time ;
T_1 V_88 , V_97 , V_96 , V_87 , * V_56 ;
V_87 = V_92 & F_29 ( V_2 -> V_5 ,
V_93 ) ;
for ( V_96 = 0 ; V_96 < V_9 -> V_15 ; V_96 ++ ) {
V_56 = F_35 ( V_9 -> V_14 ) ;
for ( V_97 = 0 ; V_97 < V_9 -> V_14 -> V_98 / V_87 ; V_97 ++ ) {
F_1 ( V_2 , V_89 , V_99 ) ;
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 || V_2 -> V_75 )
return F_31 ( V_2 ) ;
for ( V_88 = 0 ; V_88 < V_87 / 4 ; V_88 ++ )
F_30 ( V_2 -> V_5 ,
V_94 , * V_56 ++ ) ;
}
if ( V_96 < V_9 -> V_15 - 1 )
V_9 -> V_14 ++ ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
if ( V_102 -> V_10 & V_103 ) {
V_102 -> V_104 [ 0 ] = F_29 ( V_2 -> V_5 , V_105 ) ;
V_102 -> V_104 [ 1 ] = F_29 ( V_2 -> V_5 , V_106 ) ;
V_102 -> V_104 [ 2 ] = F_29 ( V_2 -> V_5 , V_107 ) ;
V_102 -> V_104 [ 3 ] = F_29 ( V_2 -> V_5 , V_108 ) ;
} else
V_102 -> V_104 [ 0 ] = F_29 ( V_2 -> V_5 , V_108 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
V_102 -> V_104 [ 0 ] = F_29 ( V_2 -> V_5 , V_109 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_84 * V_85 , struct V_101 * V_102 , T_1 V_110 )
{
T_1 V_63 = 0 ;
switch ( F_43 ( V_102 ) ) {
case V_111 :
V_63 |= V_112 ;
break;
case V_113 :
case V_114 :
case V_115 :
V_63 |= V_116 ;
break;
case V_117 :
V_63 |= V_118 ;
break;
default:
F_32 ( & V_2 -> V_7 -> V_8 , L_18 ) ;
break;
}
switch ( V_110 ) {
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_63 |= V_125 ;
break;
}
if ( V_2 -> V_9 ) {
V_63 |= V_126 ;
switch ( V_2 -> V_127 ) {
case V_128 :
V_63 |= V_129 ;
break;
case V_130 :
V_63 |= V_131 ;
break;
case V_132 :
V_63 |= V_133 ;
break;
default:
F_32 ( & V_2 -> V_7 -> V_8 , L_19 ) ;
break;
}
}
if ( V_110 == V_134 || V_110 == V_135 )
V_63 |= V_136 ;
if ( V_110 == V_137 || V_110 == V_135 ) {
V_63 |= V_138 | V_139 ;
F_1 ( V_2 , V_93 ,
V_85 -> V_9 -> V_140 << 16 ) ;
}
if ( V_110 == V_141 || V_110 == V_142 ||
V_110 == V_143 || V_110 == V_144 )
V_63 |= V_145 ;
if ( V_110 == V_141 )
V_63 |= V_146 ;
if ( V_110 == V_142 ||
V_110 == V_143 || V_110 == V_144 )
V_63 |= V_147 ;
return V_110 = ( ( V_110 << 24 ) | V_63 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_84 * V_85 , T_1 V_110 )
{
int V_27 ;
switch ( V_110 ) {
case V_137 :
V_27 = F_37 ( V_2 , V_85 ) ;
break;
case V_135 :
V_27 = F_39 ( V_2 , V_85 ) ;
break;
case V_134 :
V_27 = F_38 ( V_2 , V_85 ) ;
break;
case V_148 :
case V_149 :
V_27 = F_34 ( V_2 , V_85 ) ;
break;
default:
F_32 ( & V_2 -> V_7 -> V_8 , L_20 , V_110 ) ;
V_27 = - V_26 ;
break;
}
return V_27 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_84 * V_85 , struct V_101 * V_102 )
{
long time ;
int V_27 = 0 , V_53 = 0 ;
T_1 V_110 = V_102 -> V_150 ;
switch ( V_110 ) {
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_53 = V_151 ;
break;
default:
V_53 = V_152 ;
break;
}
V_53 |= V_153 | V_154 | V_155 |
V_156 | V_157 | V_158 |
V_159 | V_160 | V_161 |
V_162 | V_163 | V_164 ;
if ( V_2 -> V_9 ) {
F_30 ( V_2 -> V_5 , V_93 , 0 ) ;
F_30 ( V_2 -> V_5 , V_93 ,
V_85 -> V_9 -> V_165 ) ;
}
V_110 = F_42 ( V_2 , V_85 , V_102 , V_110 ) ;
F_30 ( V_2 -> V_5 , V_166 , 0xD80430C0 ) ;
F_30 ( V_2 -> V_5 , V_89 , V_53 ) ;
F_30 ( V_2 -> V_5 , V_167 , V_102 -> V_6 ) ;
F_30 ( V_2 -> V_5 , V_168 , V_110 ) ;
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 ) {
V_102 -> error = F_31 ( V_2 ) ;
return;
}
if ( V_2 -> V_75 ) {
switch ( V_102 -> V_150 ) {
case V_142 :
case V_169 :
case V_170 :
V_102 -> error = - V_83 ;
break;
default:
F_6 ( & V_2 -> V_7 -> V_8 , L_21 ,
V_102 -> V_150 ) ;
V_102 -> error = F_31 ( V_2 ) ;
break;
}
V_2 -> V_75 = false ;
return;
}
if ( ! ( V_102 -> V_10 & V_171 ) ) {
V_102 -> error = 0 ;
return;
}
F_40 ( V_2 , V_102 ) ;
if ( V_2 -> V_9 ) {
if ( ! V_2 -> V_28 ) {
V_27 = F_44 ( V_2 , V_85 , V_102 -> V_150 ) ;
} else {
long time =
F_36 ( & V_2 -> V_19 ,
V_2 -> V_74 ) ;
if ( ! time )
V_27 = - V_83 ;
else if ( time < 0 )
V_27 = time ;
F_4 ( V_2 , V_34 ,
V_35 | V_38 ) ;
V_2 -> V_28 = false ;
}
if ( V_27 < 0 )
V_85 -> V_9 -> V_172 = 0 ;
else
V_85 -> V_9 -> V_172 =
V_85 -> V_9 -> V_140 * V_85 -> V_9 -> V_165 ;
}
V_102 -> error = V_27 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_84 * V_85 , struct V_101 * V_102 )
{
long time ;
if ( V_85 -> V_102 -> V_150 == V_137 )
F_1 ( V_2 , V_89 , V_173 ) ;
else if ( V_85 -> V_102 -> V_150 == V_135 )
F_1 ( V_2 , V_89 , V_174 ) ;
else {
F_32 ( & V_2 -> V_7 -> V_8 , L_22 ) ;
V_102 -> error = F_31 ( V_2 ) ;
return;
}
time = F_36 ( & V_2 -> V_91 ,
V_2 -> V_74 ) ;
if ( time <= 0 || V_2 -> V_75 ) {
V_102 -> error = F_31 ( V_2 ) ;
return;
}
F_41 ( V_2 , V_102 ) ;
V_102 -> error = 0 ;
}
static void F_47 ( struct V_175 * V_176 , struct V_84 * V_85 )
{
struct V_1 * V_2 = F_48 ( V_176 ) ;
unsigned long V_10 ;
F_49 ( & V_2 -> V_177 , V_10 ) ;
if ( V_2 -> V_178 != V_179 ) {
F_50 ( & V_2 -> V_177 , V_10 ) ;
V_85 -> V_102 -> error = - V_180 ;
F_51 ( V_176 , V_85 ) ;
return;
}
V_2 -> V_178 = V_181 ;
F_50 ( & V_2 -> V_177 , V_10 ) ;
switch ( V_85 -> V_102 -> V_150 ) {
case V_182 :
case V_170 :
V_2 -> V_178 = V_179 ;
V_85 -> V_102 -> error = - V_83 ;
F_51 ( V_176 , V_85 ) ;
return;
case V_149 :
if ( ! V_85 -> V_9 ) {
V_2 -> V_178 = V_179 ;
V_85 -> V_102 -> error = - V_83 ;
F_51 ( V_176 , V_85 ) ;
return;
}
break;
default:
break;
}
V_2 -> V_9 = V_85 -> V_9 ;
if ( V_85 -> V_9 ) {
if ( V_85 -> V_9 -> V_10 & V_11 ) {
if ( V_2 -> V_12 )
F_11 ( V_2 ) ;
} else {
if ( V_2 -> V_17 )
F_17 ( V_2 ) ;
}
}
F_45 ( V_2 , V_85 , V_85 -> V_102 ) ;
V_2 -> V_9 = NULL ;
if ( ! V_85 -> V_102 -> error && V_85 -> V_183 )
F_46 ( V_2 , V_85 , V_85 -> V_183 ) ;
V_2 -> V_178 = V_179 ;
F_51 ( V_176 , V_85 ) ;
}
static void F_52 ( struct V_175 * V_176 , struct V_184 * V_185 )
{
struct V_1 * V_2 = F_48 ( V_176 ) ;
struct V_40 * V_56 = V_2 -> V_7 -> V_8 . V_57 ;
unsigned long V_10 ;
F_49 ( & V_2 -> V_177 , V_10 ) ;
if ( V_2 -> V_178 != V_179 ) {
F_50 ( & V_2 -> V_177 , V_10 ) ;
return;
}
V_2 -> V_178 = V_186 ;
F_50 ( & V_2 -> V_177 , V_10 ) ;
if ( V_185 -> V_187 == V_188 ) {
if ( ! V_2 -> V_189 ) {
F_19 ( V_2 , V_2 -> V_7 -> V_8 . V_57 ) ;
V_2 -> V_189 = true ;
}
} else if ( V_185 -> V_187 == V_190 || ! V_185 -> clock ) {
F_25 ( V_2 , 0 ) ;
if ( V_185 -> V_187 == V_190 ) {
if ( V_2 -> V_189 ) {
F_24 ( V_2 ) ;
V_2 -> V_189 = false ;
}
}
if ( V_2 -> V_191 ) {
F_53 ( & V_2 -> V_7 -> V_8 ) ;
V_2 -> V_191 = false ;
if ( V_56 -> V_192 && V_185 -> V_187 == V_190 )
V_56 -> V_192 ( V_2 -> V_7 ) ;
}
V_2 -> V_178 = V_179 ;
return;
}
if ( V_185 -> clock ) {
if ( ! V_2 -> V_191 ) {
if ( V_56 -> V_193 )
V_56 -> V_193 ( V_2 -> V_7 , V_185 -> V_187 ) ;
F_54 ( & V_2 -> V_7 -> V_8 ) ;
V_2 -> V_191 = true ;
F_28 ( V_2 ) ;
}
F_25 ( V_2 , V_185 -> clock ) ;
}
V_2 -> V_127 = V_185 -> V_127 ;
V_2 -> V_178 = V_179 ;
}
static int F_55 ( struct V_175 * V_176 )
{
struct V_1 * V_2 = F_48 ( V_176 ) ;
struct V_40 * V_56 = V_2 -> V_7 -> V_8 . V_57 ;
if ( ! V_56 -> V_194 )
return - V_195 ;
else
return V_56 -> V_194 ( V_2 -> V_7 ) ;
}
static void F_56 ( struct V_175 * V_176 )
{
F_57 ( V_176 , 0 ) ;
}
static T_4 F_58 ( int V_196 , void * V_197 )
{
struct V_1 * V_2 = V_197 ;
T_1 V_178 ;
int V_198 = 0 ;
V_178 = F_29 ( V_2 -> V_5 , V_166 ) ;
if ( V_178 & V_199 ) {
F_30 ( V_2 -> V_5 , V_166 ,
~ ( V_199 | V_200 ) ) ;
F_4 ( V_2 , V_89 , V_151 ) ;
} else if ( V_178 & V_200 ) {
F_30 ( V_2 -> V_5 , V_166 , ~ V_200 ) ;
F_4 ( V_2 , V_89 , V_152 ) ;
} else if ( V_178 & V_201 ) {
F_30 ( V_2 -> V_5 , V_166 , ~ V_201 ) ;
F_4 ( V_2 , V_89 , V_90 ) ;
} else if ( V_178 & V_202 ) {
F_30 ( V_2 -> V_5 , V_166 , ~ V_202 ) ;
F_4 ( V_2 , V_89 , V_99 ) ;
} else if ( V_178 & V_203 ) {
F_30 ( V_2 -> V_5 , V_166 ,
~ ( V_203 | V_204 |
V_205 | V_206 ) ) ;
F_4 ( V_2 , V_89 , V_173 ) ;
} else if ( V_178 & V_206 ) {
F_30 ( V_2 -> V_5 , V_166 , ~ V_206 ) ;
F_4 ( V_2 , V_89 , V_95 ) ;
} else if ( V_178 & V_207 ) {
F_30 ( V_2 -> V_5 , V_166 , ~ V_207 ) ;
F_4 ( V_2 , V_89 , V_100 ) ;
} else if ( V_178 & V_204 ) {
F_30 ( V_2 -> V_5 , V_166 ,
~ ( V_204 | V_205 ) ) ;
F_4 ( V_2 , V_89 , V_174 ) ;
} else if ( V_178 & V_208 ) {
F_30 ( V_2 -> V_5 , V_166 , ~ V_178 ) ;
F_4 ( V_2 , V_89 , V_178 ) ;
V_198 = 1 ;
} else {
F_6 ( & V_2 -> V_7 -> V_8 , L_23 , V_178 ) ;
F_30 ( V_2 -> V_5 , V_166 , ~ V_178 ) ;
F_4 ( V_2 , V_89 , V_178 ) ;
V_198 = 1 ;
}
if ( V_198 ) {
V_2 -> V_75 = true ;
F_6 ( & V_2 -> V_7 -> V_8 , L_24 , V_178 ) ;
}
if ( V_178 & ~ ( V_204 | V_205 ) )
F_10 ( & V_2 -> V_91 ) ;
else
F_6 ( & V_2 -> V_7 -> V_8 , L_25 , V_178 ) ;
return V_209 ;
}
static int T_5 F_59 ( struct V_210 * V_211 )
{
int V_27 = 0 , V_196 [ 2 ] ;
struct V_175 * V_176 ;
struct V_1 * V_2 ;
struct V_40 * V_7 ;
struct V_212 * V_213 ;
void T_6 * V_3 ;
char V_214 [ 8 ] ;
V_196 [ 0 ] = F_60 ( V_211 , 0 ) ;
V_196 [ 1 ] = F_60 ( V_211 , 1 ) ;
if ( V_196 [ 0 ] < 0 || V_196 [ 1 ] < 0 ) {
F_32 ( & V_211 -> V_8 , L_26 ) ;
return - V_215 ;
}
V_213 = F_61 ( V_211 , V_216 , 0 ) ;
if ( ! V_213 ) {
F_32 ( & V_211 -> V_8 , L_27 ) ;
return - V_215 ;
}
V_3 = F_62 ( V_213 -> V_217 , F_63 ( V_213 ) ) ;
if ( ! V_3 ) {
F_32 ( & V_211 -> V_8 , L_28 ) ;
return - V_218 ;
}
V_7 = V_211 -> V_8 . V_57 ;
if ( ! V_7 ) {
F_32 ( & V_211 -> V_8 , L_29 ) ;
V_27 = - V_215 ;
goto V_219;
}
V_176 = F_64 ( sizeof( struct V_1 ) , & V_211 -> V_8 ) ;
if ( ! V_176 ) {
V_27 = - V_218 ;
goto V_219;
}
V_2 = F_48 ( V_176 ) ;
V_2 -> V_176 = V_176 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_74 = 1000 ;
snprintf ( V_214 , sizeof( V_214 ) , L_30 , V_211 -> V_220 ) ;
V_2 -> V_221 = F_65 ( & V_211 -> V_8 , V_214 ) ;
if ( F_66 ( V_2 -> V_221 ) ) {
F_32 ( & V_211 -> V_8 , L_31 , V_214 ) ;
V_27 = F_67 ( V_2 -> V_221 ) ;
goto V_222;
}
F_68 ( V_2 -> V_221 ) ;
V_2 -> V_55 = F_69 ( V_2 -> V_221 ) ;
V_2 -> V_7 = V_211 ;
F_23 ( & V_2 -> V_91 ) ;
F_70 ( & V_2 -> V_177 ) ;
V_176 -> V_223 = & V_224 ;
V_176 -> V_225 = V_2 -> V_55 ;
if ( V_176 -> V_225 < 51200000 )
V_176 -> V_226 = V_176 -> V_225 / 128 ;
else if ( V_176 -> V_225 < 102400000 )
V_176 -> V_226 = V_176 -> V_225 / 256 ;
else
V_176 -> V_226 = V_176 -> V_225 / 512 ;
if ( V_7 -> V_227 )
V_176 -> V_228 = V_7 -> V_227 ;
V_176 -> V_229 = V_230 ;
if ( V_7 -> V_229 )
V_176 -> V_229 |= V_7 -> V_229 ;
V_176 -> V_231 = 32 ;
V_176 -> V_232 = 512 ;
V_176 -> V_233 = V_234 * V_176 -> V_231 ;
V_176 -> V_235 = V_176 -> V_233 / V_176 -> V_232 ;
V_176 -> V_236 = V_176 -> V_233 ;
F_28 ( V_2 ) ;
F_71 ( V_211 , V_2 ) ;
F_72 ( & V_211 -> V_8 ) ;
V_2 -> V_191 = false ;
V_27 = F_73 ( & V_211 -> V_8 ) ;
if ( V_27 < 0 )
goto V_237;
F_74 ( V_176 ) ;
F_30 ( V_2 -> V_5 , V_89 , V_238 ) ;
V_27 = F_75 ( V_196 [ 0 ] , F_58 , 0 , L_32 , V_2 ) ;
if ( V_27 ) {
F_32 ( & V_211 -> V_8 , L_33 ) ;
goto V_239;
}
V_27 = F_75 ( V_196 [ 1 ] , F_58 , 0 , L_34 , V_2 ) ;
if ( V_27 ) {
F_76 ( V_196 [ 0 ] , V_2 ) ;
F_32 ( & V_211 -> V_8 , L_35 ) ;
goto V_239;
}
F_56 ( V_2 -> V_176 ) ;
F_77 ( & V_211 -> V_8 , L_36 , V_240 ) ;
F_6 ( & V_211 -> V_8 , L_37 ,
F_29 ( V_2 -> V_5 , V_64 ) & 0x0000ffff ) ;
return V_27 ;
V_239:
F_78 ( V_176 ) ;
F_79 ( & V_211 -> V_8 ) ;
V_237:
F_80 ( & V_211 -> V_8 ) ;
F_81 ( V_2 -> V_221 ) ;
V_222:
F_82 ( V_176 ) ;
V_219:
if ( V_3 )
F_83 ( V_3 ) ;
return V_27 ;
}
static int T_7 F_84 ( struct V_210 * V_211 )
{
struct V_1 * V_2 = F_85 ( V_211 ) ;
int V_196 [ 2 ] ;
F_54 ( & V_211 -> V_8 ) ;
F_78 ( V_2 -> V_176 ) ;
F_30 ( V_2 -> V_5 , V_89 , V_238 ) ;
if ( V_2 -> V_5 )
F_83 ( V_2 -> V_5 ) ;
V_196 [ 0 ] = F_60 ( V_211 , 0 ) ;
V_196 [ 1 ] = F_60 ( V_211 , 1 ) ;
F_76 ( V_196 [ 0 ] , V_2 ) ;
F_76 ( V_196 [ 1 ] , V_2 ) ;
F_71 ( V_211 , NULL ) ;
F_81 ( V_2 -> V_221 ) ;
F_82 ( V_2 -> V_176 ) ;
F_86 ( & V_211 -> V_8 ) ;
F_80 ( & V_211 -> V_8 ) ;
return 0 ;
}
static int F_87 ( struct V_13 * V_8 )
{
struct V_210 * V_211 = F_88 ( V_8 ) ;
struct V_1 * V_2 = F_85 ( V_211 ) ;
int V_27 = F_89 ( V_2 -> V_176 ) ;
if ( ! V_27 ) {
F_30 ( V_2 -> V_5 , V_89 , V_238 ) ;
F_81 ( V_2 -> V_221 ) ;
}
return V_27 ;
}
static int F_90 ( struct V_13 * V_8 )
{
struct V_210 * V_211 = F_88 ( V_8 ) ;
struct V_1 * V_2 = F_85 ( V_211 ) ;
F_68 ( V_2 -> V_221 ) ;
return F_91 ( V_2 -> V_176 ) ;
}
static int T_8 F_92 ( void )
{
return F_93 ( & V_241 ) ;
}
static void T_9 F_94 ( void )
{
F_95 ( & V_241 ) ;
}
