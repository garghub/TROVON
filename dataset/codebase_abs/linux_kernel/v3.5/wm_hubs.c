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
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_27 ;
T_3 V_39 ;
T_2 V_6 , V_40 , V_41 , V_34 , V_42 ;
switch ( V_5 -> V_43 ) {
case 2 :
V_42 = V_44 ;
break;
default:
V_42 = V_45 ;
break;
}
if ( F_12 ( V_2 ) &&
F_14 ( V_2 , & V_27 ) ) {
F_4 ( V_2 -> V_13 , L_10 ,
V_27 -> V_34 , V_27 -> V_28 , V_27 -> V_29 ) ;
F_3 ( V_2 , V_42 , V_27 -> V_34 ) ;
F_1 ( V_2 ,
V_46 |
V_47 ) ;
return;
}
if ( V_5 -> V_48 ) {
F_20 ( V_2 , V_49 ,
V_50 ,
32 << V_51 ) ;
F_1 ( V_2 ,
V_52 |
V_53 ) ;
} else {
F_1 ( V_2 ,
V_54 |
V_55 ) ;
}
switch ( V_5 -> V_43 ) {
case 0 :
V_40 = F_8 ( V_2 , V_56 )
& V_57 ;
V_41 = F_8 ( V_2 , V_58 )
& V_59 ;
break;
case 2 :
case 1 :
V_6 = F_8 ( V_2 , V_42 ) ;
V_41 = ( V_6 & V_60 )
>> V_61 ;
V_40 = V_6 & V_62 ;
break;
default:
F_21 ( 1 , L_11 ) ;
return;
}
F_4 ( V_2 -> V_13 , L_12 , V_40 , V_41 ) ;
if ( V_5 -> V_63 || V_5 -> V_64 ) {
F_4 ( V_2 -> V_13 ,
L_13 ,
V_5 -> V_63 , V_5 -> V_64 ) ;
V_39 = V_41 ;
V_39 += V_5 -> V_64 ;
V_34 = ( V_65 ) V_39 << V_61 ;
V_39 = V_40 ;
V_39 += V_5 -> V_63 ;
V_34 |= ( V_65 ) V_39 ;
F_4 ( V_2 -> V_13 , L_14 , V_34 ) ;
F_3 ( V_2 , V_42 , V_34 ) ;
F_1 ( V_2 ,
V_46 |
V_47 ) ;
} else {
V_34 = V_41 << V_61 ;
V_34 |= V_40 ;
}
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_34 ) ;
}
static int F_22 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_23 ( V_67 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_70 ;
V_70 = F_24 ( V_67 , V_69 ) ;
if ( V_5 -> V_63 || V_5 -> V_64 || V_5 -> V_71 )
return V_70 ;
if ( F_8 ( V_2 , V_72 )
& ( V_73 | V_74 ) )
F_20 ( V_2 ,
V_12 ,
V_75 |
V_76 ,
V_75 |
V_76 ) ;
return V_70 ;
}
static int F_25 ( struct V_77 * V_78 ,
struct V_66 * V_67 , int V_79 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_79 ) {
case V_80 :
switch ( V_5 -> V_81 ) {
case 0 :
break;
case 1 :
F_20 ( V_2 , V_72 ,
V_73 |
V_74 ,
V_73 |
V_74 ) ;
F_20 ( V_2 , V_82 ,
V_83 |
V_84 ,
V_83 |
V_84 ) ;
break;
default:
F_9 ( V_2 -> V_13 , L_15 ,
V_5 -> V_81 ) ;
break;
}
case V_85 :
F_20 ( V_2 , V_86 ,
V_87 , 0 ) ;
break;
}
return 0 ;
}
static int F_26 ( struct V_77 * V_78 ,
struct V_66 * V_67 , int V_79 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
unsigned int V_6 = F_8 ( V_2 , V_82 ) ;
switch ( V_79 ) {
case V_88 :
F_20 ( V_2 , V_86 ,
V_87 , V_87 ) ;
F_7 ( 5 ) ;
F_20 ( V_2 , V_72 ,
V_73 | V_74 ,
V_73 | V_74 ) ;
V_6 |= V_83 | V_84 ;
F_3 ( V_2 , V_82 , V_6 ) ;
F_20 ( V_2 , V_49 ,
V_89 , 0 ) ;
F_19 ( V_2 ) ;
V_6 |= V_90 | V_91 |
V_92 | V_93 ;
F_3 ( V_2 , V_82 , V_6 ) ;
break;
case V_85 :
F_20 ( V_2 , V_82 ,
V_92 |
V_90 |
V_93 |
V_91 , 0 ) ;
F_20 ( V_2 , V_82 ,
V_83 |
V_84 , 0 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_20 ( V_2 , V_72 ,
V_73 | V_74 ,
0 ) ;
break;
}
return 0 ;
}
static int F_27 ( struct V_77 * V_78 ,
struct V_66 * V_94 , int V_79 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
T_2 V_6 = F_8 ( V_2 , V_95 ) & ~ V_96 ;
switch ( V_79 ) {
case V_80 :
V_6 |= V_96 ;
F_3 ( V_2 , V_95 , V_6 ) ;
F_28 ( 50 ) ;
break;
case V_97 :
F_3 ( V_2 , V_95 , V_6 ) ;
break;
default:
F_29 () ;
break;
}
return 0 ;
}
static int F_30 ( struct V_77 * V_78 ,
struct V_66 * V_94 , int V_79 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
bool * V_98 ;
switch ( V_78 -> V_99 ) {
case V_100 :
V_98 = & V_5 -> V_101 ;
break;
case V_102 :
V_98 = & V_5 -> V_103 ;
break;
case V_104 :
V_98 = & V_5 -> V_105 ;
break;
case V_106 :
V_98 = & V_5 -> V_107 ;
break;
default:
F_21 ( 1 , L_16 ) ;
return - V_108 ;
}
* V_98 = F_31 ( V_79 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_109 = V_110 | V_111 ;
if ( ! F_12 ( V_2 ) )
V_109 = false ;
if ( V_5 -> V_112 && ! V_5 -> V_112 ( V_2 ) )
V_109 = false ;
F_13 ( V_2 -> V_13 , L_17 , V_109 ? L_18 : L_19 ) ;
F_20 ( V_2 , V_113 ,
V_110 | V_111 , V_109 ) ;
}
static int F_33 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_114 * V_115 = F_23 ( V_67 ) ;
struct V_77 * V_116 = V_115 -> V_117 [ 0 ] ;
struct V_1 * V_2 = V_116 -> V_2 ;
int V_70 ;
V_70 = F_34 ( V_67 , V_69 ) ;
F_32 ( V_2 ) ;
return V_70 ;
}
static int F_35 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_114 * V_115 = F_23 ( V_67 ) ;
struct V_77 * V_116 = V_115 -> V_117 [ 0 ] ;
struct V_1 * V_2 = V_116 -> V_2 ;
int V_70 ;
V_70 = F_36 ( V_67 , V_69 ) ;
F_32 ( V_2 ) ;
return V_70 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_118 * V_119 = & V_2 -> V_119 ;
F_20 ( V_2 , V_120 ,
V_121 , V_121 ) ;
F_20 ( V_2 , V_122 ,
V_121 , V_121 ) ;
F_20 ( V_2 , V_123 ,
V_124 , V_124 ) ;
F_20 ( V_2 , V_125 ,
V_124 , V_124 ) ;
F_20 ( V_2 , V_126 ,
V_127 , V_127 ) ;
F_20 ( V_2 , V_128 ,
V_127 , V_127 ) ;
F_20 ( V_2 , V_30 ,
V_129 | V_130 ,
V_129 | V_130 ) ;
F_20 ( V_2 , V_32 ,
V_129 | V_131 ,
V_129 | V_131 ) ;
F_20 ( V_2 , V_132 ,
V_133 | V_134 ,
V_133 | V_134 ) ;
F_20 ( V_2 , V_135 ,
V_136 | V_134 ,
V_136 | V_134 ) ;
F_38 ( V_2 , V_137 ,
F_39 ( V_137 ) ) ;
F_40 ( V_119 , V_138 ,
F_39 ( V_138 ) ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
int V_139 , int V_140 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_118 * V_119 = & V_2 -> V_119 ;
F_42 ( & V_5 -> V_38 ) ;
F_43 ( & V_5 -> V_15 ) ;
F_44 ( V_119 , V_141 ,
F_39 ( V_141 ) ) ;
if ( V_139 )
F_44 ( V_119 ,
V_142 ,
F_39 ( V_142 ) ) ;
else
F_44 ( V_119 ,
V_143 ,
F_39 ( V_143 ) ) ;
if ( V_140 )
F_44 ( V_119 ,
V_144 ,
F_39 ( V_144 ) ) ;
else
F_44 ( V_119 ,
V_145 ,
F_39 ( V_145 ) ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 ,
int V_139 , int V_140 ,
int V_146 , int V_147 ,
int V_148 , int V_149 , int V_150 ,
int V_151 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_152 = ! V_139 ;
V_5 -> V_153 = ! V_140 ;
if ( ! V_139 )
F_20 ( V_2 , V_154 ,
V_155 ,
V_155 ) ;
if ( ! V_140 )
F_20 ( V_2 , V_156 ,
V_157 ,
V_157 ) ;
if ( ! V_139 && ! V_140 )
F_20 ( V_2 , V_95 ,
V_158 ,
V_158 ) ;
if ( V_146 )
F_20 ( V_2 , V_159 ,
V_160 , V_160 ) ;
if ( V_147 )
F_20 ( V_2 , V_159 ,
V_161 , V_161 ) ;
F_20 ( V_2 , V_162 ,
V_163 | V_164 |
V_165 | V_166 ,
V_148 << V_167 |
V_149 << V_168 |
V_150 |
V_151 << V_169 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_9 = 0 ;
if ( V_5 -> V_152 )
V_9 |= V_170 | V_171 ;
if ( V_5 -> V_153 )
V_9 |= V_172 | V_173 ;
F_20 ( V_2 , V_174 , V_9 , V_9 ) ;
}
void F_47 ( struct V_1 * V_2 ,
enum V_175 V_176 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_177 , V_9 ;
switch ( V_176 ) {
case V_178 :
F_20 ( V_2 , V_179 ,
V_180 , V_180 ) ;
break;
case V_181 :
V_9 = 0 ;
V_177 = 0 ;
if ( V_5 -> V_152 )
V_177 |= V_170 | V_171 ;
if ( V_5 -> V_153 )
V_177 |= V_172 | V_173 ;
if ( V_5 -> V_152 && V_5 -> V_101 )
V_9 |= V_170 ;
if ( V_5 -> V_152 && V_5 -> V_103 )
V_9 |= V_171 ;
if ( V_5 -> V_153 && V_5 -> V_105 )
V_9 |= V_172 ;
if ( V_5 -> V_153 && V_5 -> V_107 )
V_9 |= V_173 ;
F_20 ( V_2 , V_174 ,
V_177 , V_9 ) ;
F_20 ( V_2 , V_179 ,
V_180 , 0 ) ;
break;
default:
break;
}
}
