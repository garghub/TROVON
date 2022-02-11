static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
int V_7 = 0 ;
int V_8 ;
unsigned int V_9 ;
V_9 = V_3 | V_10 | V_11 ;
F_3 ( V_2 , V_12 , V_9 ) ;
F_4 ( V_2 -> V_13 , L_1 ) ;
if ( V_5 -> V_14 )
V_8 = 4 ;
else
V_8 = 400 ;
do {
V_7 ++ ;
if ( V_5 -> V_14 )
F_5 ( & V_5 -> V_15 ,
F_6 ( 250 ) ) ;
else
F_7 ( 1 ) ;
V_6 = F_8 ( V_2 , V_12 ) ;
F_4 ( V_2 -> V_13 , L_2 , V_6 ) ;
} while ( V_6 & V_3 && V_7 < V_8 );
if ( V_6 & V_3 )
F_9 ( V_2 -> V_13 , L_3 ,
V_3 ) ;
}
T_1 F_10 ( int V_16 , void * V_17 )
{
struct V_4 * V_5 = V_17 ;
F_11 ( & V_5 -> V_15 ) ;
return V_18 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_8 ( V_2 , V_19 ) ;
if ( ! ( V_6 & V_20 ) ) {
if ( V_6 & ~ V_21 ) {
F_13 ( V_2 -> V_13 , L_4 ,
V_6 & ~ V_20 ) ;
return false ;
} else {
F_13 ( V_2 -> V_13 , L_5 ) ;
}
} else {
F_13 ( V_2 -> V_13 , L_6 ) ;
}
V_6 = F_8 ( V_2 , V_22 ) ;
if ( ! ( V_6 & V_23 ) ) {
if ( V_6 & ~ V_24 ) {
F_13 ( V_2 -> V_13 , L_4 ,
V_6 & ~ V_23 ) ;
return false ;
} else {
F_13 ( V_2 -> V_13 , L_7 ) ;
}
} else {
F_13 ( V_2 -> V_13 , L_8 ) ;
}
return true ;
}
static bool F_14 ( struct V_1 * V_2 ,
struct V_25 * * V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_27 ;
unsigned int V_28 , V_29 ;
V_28 = F_8 ( V_2 , V_30 ) ;
V_28 &= V_31 ;
V_29 = F_8 ( V_2 , V_32 ) ;
V_29 &= V_33 ;
F_15 (cache, &hubs->dcs_cache, list) {
if ( V_27 -> V_28 != V_28 || V_27 -> V_29 != V_29 )
continue;
* V_26 = V_27 ;
return true ;
}
return false ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_34 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_27 ;
if ( V_5 -> V_35 )
return;
V_27 = F_17 ( V_2 -> V_13 , sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 ) {
F_9 ( V_2 -> V_13 , L_9 ) ;
return;
}
V_27 -> V_28 = F_8 ( V_2 , V_30 ) ;
V_27 -> V_28 &= V_31 ;
V_27 -> V_29 = F_8 ( V_2 , V_32 ) ;
V_27 -> V_29 &= V_33 ;
V_27 -> V_34 = V_34 ;
F_18 ( & V_27 -> V_37 , & V_5 -> V_38 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
T_2 * V_39 , T_2 * V_40 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_41 , V_6 ;
int V_42 = 0 ;
switch ( V_5 -> V_43 ) {
case 2 :
V_41 = V_44 ;
break;
case 1 :
V_41 = V_45 ;
break;
default:
V_41 = V_46 ;
break;
}
switch ( V_5 -> V_43 ) {
case 0 :
* V_39 = F_8 ( V_2 , V_47 )
& V_48 ;
* V_40 = F_8 ( V_2 , V_49 )
& V_50 ;
break;
case 2 :
case 1 :
V_6 = F_8 ( V_2 , V_41 ) ;
* V_40 = ( V_6 & V_51 )
>> V_52 ;
* V_39 = V_6 & V_53 ;
break;
default:
F_20 ( 1 , L_10 ) ;
V_42 = - 1 ;
}
return V_42 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_27 ;
T_3 V_54 ;
T_2 V_39 , V_40 , V_34 , V_41 ;
switch ( V_5 -> V_43 ) {
case 2 :
V_41 = V_44 ;
break;
default:
V_41 = V_46 ;
break;
}
if ( F_12 ( V_2 ) &&
F_14 ( V_2 , & V_27 ) ) {
F_4 ( V_2 -> V_13 , L_11 ,
V_27 -> V_34 , V_27 -> V_28 , V_27 -> V_29 ) ;
F_3 ( V_2 , V_41 , V_27 -> V_34 ) ;
F_1 ( V_2 ,
V_55 |
V_56 ) ;
return;
}
if ( V_5 -> V_57 ) {
F_22 ( V_2 , V_58 ,
V_59 ,
32 << V_60 ) ;
F_1 ( V_2 ,
V_61 |
V_62 ) ;
} else {
F_1 ( V_2 ,
V_63 |
V_64 ) ;
}
if ( F_19 ( V_2 , & V_39 , & V_40 ) < 0 )
return;
F_4 ( V_2 -> V_13 , L_12 , V_39 , V_40 ) ;
if ( V_5 -> V_65 || V_5 -> V_66 ) {
F_4 ( V_2 -> V_13 ,
L_13 ,
V_5 -> V_65 , V_5 -> V_66 ) ;
V_54 = ( T_3 ) V_40 ;
F_4 ( V_2 -> V_13 , L_14 , V_54 ,
V_54 + V_5 -> V_66 ) ;
V_54 += V_5 -> V_66 ;
V_34 = ( V_67 ) V_54 << V_52 ;
V_54 = ( T_3 ) V_39 ;
F_4 ( V_2 -> V_13 , L_15 , V_54 ,
V_54 + V_5 -> V_65 ) ;
V_54 += V_5 -> V_65 ;
V_34 |= ( V_67 ) V_54 ;
F_4 ( V_2 -> V_13 , L_16 , V_34 ) ;
F_3 ( V_2 , V_41 , V_34 ) ;
F_1 ( V_2 ,
V_55 |
V_56 ) ;
} else {
V_34 = V_40 << V_52 ;
V_34 |= V_39 ;
}
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_34 ) ;
}
static int F_23 ( struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_24 ( V_69 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_42 ;
V_42 = F_25 ( V_69 , V_71 ) ;
if ( V_5 -> V_65 || V_5 -> V_66 || V_5 -> V_72 )
return V_42 ;
if ( F_8 ( V_2 , V_73 )
& ( V_74 | V_75 ) )
F_22 ( V_2 ,
V_12 ,
V_76 |
V_77 ,
V_76 |
V_77 ) ;
return V_42 ;
}
static int F_26 ( struct V_78 * V_79 ,
struct V_68 * V_69 , int V_80 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_80 ) {
case V_81 :
switch ( V_5 -> V_82 ) {
case 0 :
break;
case 1 :
F_22 ( V_2 , V_73 ,
V_74 |
V_75 ,
V_74 |
V_75 ) ;
F_22 ( V_2 , V_83 ,
V_84 |
V_85 ,
V_84 |
V_85 ) ;
break;
default:
F_9 ( V_2 -> V_13 , L_17 ,
V_5 -> V_82 ) ;
break;
}
case V_86 :
F_22 ( V_2 , V_87 ,
V_88 , 0 ) ;
break;
}
return 0 ;
}
static int F_27 ( struct V_78 * V_79 ,
struct V_68 * V_69 , int V_80 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
unsigned int V_6 = F_8 ( V_2 , V_83 ) ;
switch ( V_80 ) {
case V_89 :
F_22 ( V_2 , V_87 ,
V_88 , V_88 ) ;
F_7 ( 5 ) ;
F_22 ( V_2 , V_73 ,
V_74 | V_75 ,
V_74 | V_75 ) ;
V_6 |= V_84 | V_85 ;
F_3 ( V_2 , V_83 , V_6 ) ;
F_22 ( V_2 , V_58 ,
V_90 , 0 ) ;
F_21 ( V_2 ) ;
V_6 |= V_91 | V_92 |
V_93 | V_94 ;
F_3 ( V_2 , V_83 , V_6 ) ;
break;
case V_86 :
F_22 ( V_2 , V_83 ,
V_93 |
V_91 |
V_94 |
V_92 , 0 ) ;
F_22 ( V_2 , V_83 ,
V_84 |
V_85 , 0 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_22 ( V_2 , V_73 ,
V_74 | V_75 ,
0 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_78 * V_79 ,
struct V_68 * V_95 , int V_80 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
T_2 V_6 = F_8 ( V_2 , V_96 ) & ~ V_97 ;
switch ( V_80 ) {
case V_81 :
V_6 |= V_97 ;
F_3 ( V_2 , V_96 , V_6 ) ;
F_29 ( 50 ) ;
break;
case V_98 :
F_3 ( V_2 , V_96 , V_6 ) ;
break;
default:
F_30 () ;
break;
}
return 0 ;
}
static int F_31 ( struct V_78 * V_79 ,
struct V_68 * V_95 , int V_80 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool * V_99 ;
switch ( V_79 -> V_100 ) {
case V_101 :
V_99 = & V_5 -> V_102 ;
break;
case V_103 :
V_99 = & V_5 -> V_104 ;
break;
case V_105 :
V_99 = & V_5 -> V_106 ;
break;
case V_107 :
V_99 = & V_5 -> V_108 ;
break;
default:
F_20 ( 1 , L_18 ) ;
return - V_109 ;
}
* V_99 = F_32 ( V_80 ) ;
return 0 ;
}
static int F_33 ( struct V_78 * V_79 ,
struct V_68 * V_69 , int V_80 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_79 -> V_100 ) {
case V_110 :
if ( V_5 -> V_111 )
F_7 ( V_5 -> V_111 ) ;
break;
case V_112 :
if ( V_5 -> V_113 )
F_7 ( V_5 -> V_113 ) ;
break;
default:
return - V_109 ;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_114 = V_115 | V_116 ;
if ( ! F_12 ( V_2 ) )
V_114 = false ;
if ( V_5 -> V_117 && ! V_5 -> V_117 ( V_2 ) )
V_114 = false ;
F_13 ( V_2 -> V_13 , L_19 , V_114 ? L_20 : L_21 ) ;
F_22 ( V_2 , V_118 ,
V_115 | V_116 , V_114 ) ;
F_3 ( V_2 , V_30 ,
F_8 ( V_2 , V_30 ) ) ;
F_3 ( V_2 , V_32 ,
F_8 ( V_2 , V_32 ) ) ;
}
static int F_35 ( struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_119 * V_120 = F_24 ( V_69 ) ;
struct V_78 * V_121 = V_120 -> V_122 [ 0 ] ;
struct V_1 * V_2 = V_121 -> V_2 ;
int V_42 ;
V_42 = F_36 ( V_69 , V_71 ) ;
F_34 ( V_2 ) ;
return V_42 ;
}
static int F_37 ( struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_119 * V_120 = F_24 ( V_69 ) ;
struct V_78 * V_121 = V_120 -> V_122 [ 0 ] ;
struct V_1 * V_2 = V_121 -> V_2 ;
int V_42 ;
V_42 = F_38 ( V_69 , V_71 ) ;
F_34 ( V_2 ) ;
return V_42 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = & V_2 -> V_124 ;
F_22 ( V_2 , V_125 ,
V_126 , V_126 ) ;
F_22 ( V_2 , V_127 ,
V_126 , V_126 ) ;
F_22 ( V_2 , V_128 ,
V_129 , V_129 ) ;
F_22 ( V_2 , V_130 ,
V_129 , V_129 ) ;
F_22 ( V_2 , V_131 ,
V_132 , V_132 ) ;
F_22 ( V_2 , V_133 ,
V_132 , V_132 ) ;
F_22 ( V_2 , V_30 ,
V_134 | V_135 ,
V_134 | V_135 ) ;
F_22 ( V_2 , V_32 ,
V_134 | V_136 ,
V_134 | V_136 ) ;
F_22 ( V_2 , V_137 ,
V_138 | V_139 ,
V_138 | V_139 ) ;
F_22 ( V_2 , V_140 ,
V_141 | V_139 ,
V_141 | V_139 ) ;
F_40 ( V_2 , V_142 ,
F_41 ( V_142 ) ) ;
F_42 ( V_124 , V_143 ,
F_41 ( V_143 ) ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
int V_144 , int V_145 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_123 * V_124 = & V_2 -> V_124 ;
V_5 -> V_2 = V_2 ;
F_44 ( & V_5 -> V_38 ) ;
F_45 ( & V_5 -> V_15 ) ;
F_46 ( V_124 , V_146 ,
F_41 ( V_146 ) ) ;
if ( V_144 )
F_46 ( V_124 ,
V_147 ,
F_41 ( V_147 ) ) ;
else
F_46 ( V_124 ,
V_148 ,
F_41 ( V_148 ) ) ;
if ( V_145 )
F_46 ( V_124 ,
V_149 ,
F_41 ( V_149 ) ) ;
else
F_46 ( V_124 ,
V_150 ,
F_41 ( V_150 ) ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
int V_144 , int V_145 ,
int V_151 , int V_152 ,
int V_153 , int V_154 ,
int V_155 , int V_156 ,
int V_157 , int V_158 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_159 = ! V_144 ;
V_5 -> V_160 = ! V_145 ;
V_5 -> V_111 = V_155 ;
V_5 -> V_113 = V_156 ;
if ( ! V_144 )
F_22 ( V_2 , V_161 ,
V_162 ,
V_162 ) ;
if ( ! V_145 )
F_22 ( V_2 , V_163 ,
V_164 ,
V_164 ) ;
if ( ! V_144 && ! V_145 )
F_22 ( V_2 , V_96 ,
V_165 ,
V_165 ) ;
if ( V_151 )
F_22 ( V_2 , V_166 ,
V_167 , V_167 ) ;
if ( V_152 )
F_22 ( V_2 , V_166 ,
V_168 , V_168 ) ;
F_22 ( V_2 , V_169 ,
V_170 | V_171 |
V_172 | V_173 ,
V_153 << V_174 |
V_154 << V_175 |
V_157 |
V_158 << V_176 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_9 = 0 ;
if ( V_5 -> V_159 )
V_9 |= V_177 | V_178 ;
if ( V_5 -> V_160 )
V_9 |= V_179 | V_180 ;
F_22 ( V_2 , V_181 , V_9 , V_9 ) ;
}
void F_49 ( struct V_1 * V_2 ,
enum V_182 V_183 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_184 , V_9 ;
switch ( V_183 ) {
case V_185 :
F_22 ( V_2 , V_186 ,
V_187 , V_187 ) ;
break;
case V_188 :
V_9 = 0 ;
V_184 = 0 ;
if ( V_5 -> V_159 )
V_184 |= V_177 | V_178 ;
if ( V_5 -> V_160 )
V_184 |= V_179 | V_180 ;
if ( V_5 -> V_159 && V_5 -> V_102 )
V_9 |= V_177 ;
if ( V_5 -> V_159 && V_5 -> V_104 )
V_9 |= V_178 ;
if ( V_5 -> V_160 && V_5 -> V_106 )
V_9 |= V_179 ;
if ( V_5 -> V_160 && V_5 -> V_108 )
V_9 |= V_180 ;
F_22 ( V_2 , V_181 ,
V_184 , V_9 ) ;
F_22 ( V_2 , V_186 ,
V_187 , 0 ) ;
break;
default:
break;
}
}
