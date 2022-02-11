static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & F_2 ( V_3 -> V_4 , struct V_5 , V_6 . V_4 ) -> V_7 ;
}
static inline struct V_5 * F_3 ( struct V_1 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static void F_4 ( struct V_5 * V_5 )
{
struct V_8 * V_9 = & V_5 -> V_10 [ 0 ] ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_9 -> V_13 . V_14 = V_15 ;
V_9 -> V_13 . V_16 = V_17 ;
V_9 -> V_13 . V_18 = V_19 [ 0 ] . V_18 ;
V_9 -> V_20 = V_11 ;
V_9 -> V_21 = 0 ;
V_9 ++ ;
}
V_5 -> V_22 = & V_23 [ V_24 ] ;
V_5 -> V_9 = & V_5 -> V_10 [ 0 ] ;
}
static int F_5 ( struct V_25 * V_26 , T_1 V_27 , T_1 * V_28 )
{
T_2 V_29 [ 2 ] = { V_27 >> 8 , V_27 & 0xFF } ;
struct V_30 V_31 [ 2 ] ;
T_2 V_32 [ 2 ] ;
int V_33 ;
V_31 [ 0 ] . V_27 = V_26 -> V_27 ;
V_31 [ 0 ] . V_34 = 0 ;
V_31 [ 0 ] . V_35 = 2 ;
V_31 [ 0 ] . V_36 = V_29 ;
V_31 [ 1 ] . V_27 = V_26 -> V_27 ;
V_31 [ 1 ] . V_34 = V_37 ;
V_31 [ 1 ] . V_35 = 2 ;
V_31 [ 1 ] . V_36 = V_32 ;
V_33 = F_6 ( V_26 -> V_38 , V_31 , 2 ) ;
* V_28 = F_7 ( * ( ( V_39 * ) V_32 ) ) ;
F_8 ( 3 , V_40 , V_26 , L_1 , V_27 , * V_28 ) ;
return V_33 == 2 ? 0 : V_33 ;
}
static int F_9 ( struct V_25 * V_26 , T_1 V_27 , T_1 V_28 )
{
T_2 V_36 [ 4 ] = { V_27 >> 8 , V_27 & 0xFF , V_28 >> 8 , V_28 & 0xFF } ;
int V_33 = F_10 ( V_26 , V_36 , 4 ) ;
F_8 ( 3 , V_40 , V_26 , L_2 , V_27 , V_28 ) ;
return V_33 == 4 ? 0 : V_33 ;
}
static int F_11 ( struct V_25 * V_41 , T_1 V_27 , T_1 V_28 )
{
int V_33 = F_9 ( V_41 , V_42 , V_27 ) ;
if ( V_33 )
return V_33 ;
return F_9 ( V_41 , V_43 , V_28 ) ;
}
static int F_12 ( struct V_25 * V_26 , T_1 V_27 , T_1 * V_28 )
{
int V_33 = F_9 ( V_26 , V_44 , V_27 ) ;
if ( V_33 )
return V_33 ;
return F_5 ( V_26 , V_43 , V_28 ) ;
}
static int F_13 ( struct V_1 * V_7 ,
const struct V_45 * V_31 )
{
struct V_25 * V_26 = F_14 ( V_7 ) ;
T_1 V_46 = 0 ;
int V_33 = 0 ;
while ( V_31 -> V_27 != V_47 ) {
if ( V_46 != 2 )
V_33 = F_9 ( V_26 , V_42 ,
V_31 -> V_27 ) ;
if ( V_33 )
break;
V_33 = F_9 ( V_26 , V_43 , V_31 -> V_28 ) ;
if ( V_33 )
break;
V_46 = ( V_31 + 1 ) -> V_27 - V_31 -> V_27 ;
V_31 ++ ;
}
return V_33 ;
}
static int F_15 ( struct V_25 * V_26 )
{
int V_33 = F_9 ( V_26 , V_48 , V_49 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_9 ( V_26 , V_50 , V_51 ) ;
if ( V_33 )
return V_33 ;
return F_9 ( V_26 , V_52 , V_51 ) ;
}
static int F_16 ( struct V_5 * V_5 )
{
struct V_25 * V_41 = F_14 ( & V_5 -> V_7 ) ;
unsigned long V_53 = V_5 -> V_54 / 1000 ;
T_1 V_55 ;
int V_33 ;
if ( F_17 ( V_53 < V_56 || V_53 > V_57 ,
L_3 , V_53 ) )
return - V_58 ;
V_5 -> V_59 = V_60 ;
V_5 -> V_61 = V_62 ;
V_5 -> V_63 = V_64 ;
V_33 = F_11 ( V_41 , V_65 , V_53 >> 16 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_66 , V_53 & 0xFFFF ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_67 , 1 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , F_18 ( 0 ) , V_5 -> V_63 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , F_19 ( 0 ) ,
V_5 -> V_59 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , F_20 ( 0 ) ,
V_5 -> V_61 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_68 , 1 ) ;
if ( ! V_33 )
V_33 = F_12 ( V_41 , V_69 , & V_55 ) ;
return V_33 ? V_33 : ( V_55 ? - V_58 : 0 ) ;
}
static int F_21 ( struct V_5 * V_5 , int V_70 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_20 = V_5 -> V_9 -> V_20 ;
unsigned int V_71 = V_5 -> V_6 . V_71 -> V_28 ^ V_5 -> V_72 ;
unsigned int V_73 = ( V_70 ^ V_5 -> V_74 ) | ( V_71 << 1 ) ;
return F_11 ( V_26 , F_22 ( V_20 ) , V_73 ) ;
}
static int F_23 ( struct V_5 * V_5 , int V_75 )
{
struct V_25 * V_41 = F_14 ( & V_5 -> V_7 ) ;
struct V_76 * V_6 = & V_5 -> V_6 ;
T_1 V_77 ;
int V_33 = F_12 ( V_41 , V_78 , & V_77 ) ;
if ( ! V_33 && ! V_75 ) {
V_33 = F_11 ( V_41 , V_79 , V_6 -> V_80 -> V_28 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_81 , 1 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_11 ( V_41 , V_82 , V_6 -> V_83 -> V_28 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_84 , 1 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_11 ( V_41 , V_85 , V_6 -> V_86 -> V_28 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_87 , 1 ) ;
}
if ( ! V_33 ) {
V_77 = V_75 ? V_77 | V_88 : V_77 & ~ V_88 ;
V_33 = F_11 ( V_41 , V_78 , V_77 ) ;
}
return V_33 ;
}
static int F_24 ( struct V_25 * V_26 , int V_89 )
{
unsigned int time = V_89 / 10 ;
int V_33 = F_11 ( V_26 , V_90 , time & 0xffff ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_91 , time >> 16 ) ;
if ( V_33 )
return V_33 ;
return F_11 ( V_26 , V_92 , 1 ) ;
}
static int F_25 ( struct V_25 * V_26 , int V_93 )
{
int V_33 = F_11 ( V_26 , V_94 , V_93 ) ;
if ( V_33 )
return V_33 ;
return F_11 ( V_26 , V_95 , 1 ) ;
}
static int F_26 ( struct V_5 * V_5 , int V_96 )
{
struct V_25 * V_41 = F_14 ( & V_5 -> V_7 ) ;
unsigned int V_97 = V_5 -> V_6 . V_89 -> V_28 ;
T_1 V_98 ;
int V_33 = F_12 ( V_41 , V_78 , & V_98 ) ;
if ( V_33 )
return V_33 ;
F_8 ( 1 , V_40 , V_41 , L_4 ,
V_97 , V_96 , V_98 ) ;
if ( V_96 == V_99 ) {
V_98 |= V_100 | V_101 ;
} else {
V_33 = F_24 ( V_41 , V_97 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_25 ( V_41 , V_5 -> V_6 . V_93 -> V_28 ) ;
if ( V_33 )
return V_33 ;
V_98 &= ~ ( V_100 | V_101 ) ;
}
return F_11 ( V_41 , V_78 , V_98 ) ;
}
static int F_27 ( struct V_5 * V_5 , int V_96 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
T_1 V_98 ;
int V_33 ;
V_33 = F_12 ( V_26 , V_78 , & V_98 ) ;
if ( V_33 )
return V_33 ;
if ( V_96 == V_102 ) {
V_98 |= V_103 ;
} else {
V_98 &= ~ V_103 ;
V_33 = F_11 ( V_26 , V_104 , V_96 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_11 ( V_26 , V_105 , 1 ) ;
if ( V_33 )
return V_33 ;
}
return F_11 ( V_26 , V_78 , V_98 ) ;
}
static int F_28 ( struct V_5 * V_5 , int V_28 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
static const struct V_106 V_107 [] = {
{ V_108 , 0 } ,
{ V_109 , 1 } ,
{ V_110 , 2 } ,
{ V_111 , 3 } ,
{ V_112 , 4 } ,
{ V_113 , 5 } ,
} ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_107 ) ; V_11 ++ ) {
if ( V_107 [ V_11 ] . V_114 == V_28 )
return F_11 ( V_26 , V_115 ,
V_107 [ V_11 ] . V_96 ) ;
}
return - V_58 ;
}
static int F_30 ( struct V_25 * V_26 )
{
T_1 error = 0 ;
int V_33 = F_12 ( V_26 , V_116 , & error ) ;
F_8 ( 1 , V_40 , V_26 , L_5 , error , V_33 ) ;
return V_33 ? V_33 : ( error ? - V_58 : 0 ) ;
}
static int F_31 ( struct V_5 * V_5 ,
struct V_117 * V_118 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_19 ) ; V_11 ++ )
if ( V_118 -> V_119 == V_19 [ V_11 ] . V_119 &&
V_118 -> V_18 == V_19 [ V_11 ] . V_18 )
return V_11 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_5 ,
struct V_8 * V_9 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_120 = F_31 ( V_5 , & V_9 -> V_13 ) ;
int V_33 ;
V_33 = F_11 ( V_26 , F_33 ( V_9 -> V_20 ) ,
V_9 -> V_13 . V_14 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_34 ( V_9 -> V_20 ) ,
V_9 -> V_13 . V_16 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_35 ( V_9 -> V_20 ) ,
V_19 [ V_120 ] . V_121 ) ;
return V_33 ;
}
static int F_36 ( struct V_5 * V_5 )
{
struct V_25 * V_41 = F_14 ( & V_5 -> V_7 ) ;
struct V_122 * V_123 = & V_5 -> V_124 ;
int V_33 ;
V_33 = F_11 ( V_41 , V_125 , V_123 -> V_14 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_126 , V_123 -> V_16 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_127 , V_123 -> V_128 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_129 , V_123 -> V_130 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_41 , V_131 , 1 ) ;
if ( ! V_33 )
V_5 -> V_132 = 0 ;
return V_33 ;
}
static int F_37 ( struct V_5 * V_5 ,
enum V_133 V_134 , int V_135 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
T_1 V_136 = 0 ;
int V_33 ;
if ( V_134 == V_137 )
V_136 = V_135 ;
else if ( V_134 != V_138 )
return - V_58 ;
V_33 = F_11 ( V_26 , V_139 , V_136 ) ;
if ( V_33 )
return V_33 ;
return F_11 ( V_26 , V_140 , 1 ) ;
}
static int F_38 ( struct V_25 * V_26 , int V_141 ,
int V_142 )
{
unsigned long V_143 = V_144 + F_39 ( V_141 ) ;
T_1 V_77 = 1 ;
int V_33 ;
V_33 = F_11 ( V_26 , V_145 , V_142 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_146 , 1 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_147 , 1 ) ;
if ( V_141 == 0 )
return V_33 ;
while ( V_33 >= 0 && F_40 ( V_143 ) ) {
V_33 = F_12 ( V_26 , V_147 , & V_77 ) ;
if ( ! V_77 )
return 0 ;
F_41 ( 1000 , 5000 ) ;
}
return V_33 ? V_33 : - V_148 ;
}
static int F_42 ( struct V_5 * V_5 ,
struct V_8 * V_9 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_149 = V_9 -> V_20 ;
T_1 V_150 ;
int V_33 ;
if ( V_5 -> V_22 -> V_151 >= V_152 )
V_150 = V_153 ;
else
V_150 = V_154 ;
V_33 = F_32 ( V_5 , V_9 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_43 ( V_149 ) ,
V_5 -> V_61 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_44 ( V_149 ) ,
V_5 -> V_59 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_45 ( V_149 ) ,
V_9 -> V_21 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_46 ( V_149 ) ,
V_155 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_47 ( V_149 ) ,
V_150 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_48 ( V_149 ) ,
V_5 -> V_22 -> V_151 + 33 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_49 ( V_149 ) ,
V_5 -> V_22 -> V_151 - 33 ) ;
if ( ! V_33 )
V_33 = F_38 ( V_26 , 250 , V_149 ) ;
if ( ! V_33 )
V_33 = F_30 ( V_26 ) ;
if ( ! V_33 )
V_5 -> V_156 = 0 ;
F_8 ( 1 , V_40 , V_26 , L_6 ,
V_5 -> V_22 -> V_151 , V_33 ) ;
return V_33 ;
}
static int F_50 ( struct V_1 * V_7 )
{
struct V_25 * V_26 = F_14 ( V_7 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 ;
V_5 -> V_132 = 1 ;
V_5 -> V_156 = 1 ;
F_51 ( 100 ) ;
V_33 = F_15 ( V_26 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_37 ( V_5 , V_5 -> V_134 ,
V_5 -> V_157 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_13 ( V_7 , V_158 ) ;
if ( V_33 )
return V_33 ;
F_51 ( 20 ) ;
return F_16 ( V_5 ) ;
}
static int F_52 ( struct V_5 * V_159 , int V_114 , T_3 V_28 )
{
if ( ! F_53 ( V_159 -> V_160 [ V_114 ] . V_160 ) )
return 0 ;
F_54 ( V_159 -> V_160 [ V_114 ] . V_160 , ! ! V_28 ) ;
return 1 ;
}
static int F_55 ( struct V_5 * V_159 , int V_114 )
{
return F_52 ( V_159 , V_114 , V_159 -> V_160 [ V_114 ] . V_161 ) ;
}
static int F_56 ( struct V_5 * V_159 , int V_114 )
{
return F_52 ( V_159 , V_114 , ! V_159 -> V_160 [ V_114 ] . V_161 ) ;
}
static int F_57 ( struct V_5 * V_5 )
{
int V_33 ;
V_33 = F_58 ( V_162 , V_5 -> V_163 ) ;
if ( V_33 )
return V_33 ;
if ( F_56 ( V_5 , V_164 ) )
F_41 ( 150 , 200 ) ;
if ( V_5 -> V_165 )
V_33 = V_5 -> V_165 ( 1 ) ;
F_41 ( 4000 , 4000 ) ;
if ( F_56 ( V_5 , V_166 ) )
F_51 ( 20 ) ;
return V_33 ;
}
static int F_59 ( struct V_5 * V_5 )
{
int V_33 ;
if ( F_55 ( V_5 , V_166 ) )
F_41 ( 100 , 150 ) ;
if ( V_5 -> V_165 ) {
V_33 = V_5 -> V_165 ( 0 ) ;
if ( V_33 )
return V_33 ;
}
if ( F_55 ( V_5 , V_164 ) )
F_41 ( 50 , 100 ) ;
V_5 -> V_167 = 0 ;
return F_60 ( V_162 , V_5 -> V_163 ) ;
}
static int F_61 ( struct V_1 * V_7 , int V_168 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 = 0 ;
F_62 ( & V_5 -> V_169 ) ;
if ( ! V_168 == V_5 -> V_170 ) {
if ( V_168 ) {
V_33 = F_57 ( V_5 ) ;
if ( ! V_33 )
V_33 = F_50 ( V_7 ) ;
} else {
V_33 = F_59 ( V_5 ) ;
}
if ( ! V_33 )
V_5 -> V_170 += V_168 ? 1 : - 1 ;
}
F_63 ( & V_5 -> V_169 ) ;
if ( ! V_168 || V_33 || V_5 -> V_170 != 1 )
return V_33 ;
return F_64 ( V_7 -> V_171 ) ;
}
static int F_65 ( struct V_5 * V_5 , int V_172 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_33 = 0 ;
V_33 = F_11 ( V_26 , V_173 , V_172 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_174 , 1 ) ;
if ( ! V_33 )
V_5 -> V_167 = V_172 ;
return V_33 ;
}
static int F_66 ( struct V_1 * V_7 , int V_168 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 = 0 ;
F_62 ( & V_5 -> V_169 ) ;
if ( V_5 -> V_167 == ! V_168 ) {
if ( ! V_33 && V_5 -> V_156 )
V_33 = F_42 ( V_5 , V_5 -> V_9 ) ;
if ( V_5 -> V_132 )
V_33 = F_36 ( V_5 ) ;
if ( ! V_33 )
V_33 = F_65 ( V_5 , ! ! V_168 ) ;
}
F_63 ( & V_5 -> V_169 ) ;
return V_33 ;
}
static int F_67 ( struct V_1 * V_7 ,
struct V_175 * V_176 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
F_62 ( & V_5 -> V_169 ) ;
V_176 -> V_177 = V_5 -> V_22 -> V_177 ;
F_63 ( & V_5 -> V_169 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_5 ,
struct V_175 * V_176 )
{
struct V_117 * V_13 = & V_5 -> V_9 -> V_13 ;
const struct V_178 * V_22 = & V_23 [ 0 ] ;
unsigned int V_179 , V_180 = V_181 ;
unsigned int V_11 , V_182 ;
if ( V_176 -> V_177 . V_183 == 0 )
return - V_58 ;
V_182 = V_176 -> V_177 . V_184 * 10000 / V_176 -> V_177 . V_183 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_23 ) ; V_11 ++ ) {
const struct V_178 * V_185 = & V_23 [ V_11 ] ;
if ( V_13 -> V_14 > V_185 -> V_186 . V_14 ||
V_13 -> V_16 > V_185 -> V_186 . V_16 )
continue;
V_179 = abs ( V_185 -> V_151 - V_182 ) ;
if ( V_179 < V_180 ) {
V_22 = V_185 ;
V_180 = V_179 ;
}
}
V_5 -> V_22 = V_22 ;
F_8 ( 1 , V_40 , & V_5 -> V_7 , L_7 ,
V_22 -> V_151 * 100 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_7 ,
struct V_175 * V_176 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 ;
F_8 ( 1 , V_40 , V_7 , L_8 ,
V_176 -> V_177 . V_184 , V_176 -> V_177 . V_183 ) ;
F_62 ( & V_5 -> V_169 ) ;
V_33 = F_68 ( V_5 , V_176 ) ;
V_5 -> V_156 = 1 ;
F_63 ( & V_5 -> V_169 ) ;
return V_33 ;
}
static int F_70 ( struct V_1 * V_7 ,
struct V_187 * V_136 ,
struct V_188 * V_189 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
const struct V_178 * V_176 ;
int V_33 = 0 ;
if ( V_189 -> V_20 >= F_29 ( V_23 ) )
return - V_58 ;
F_71 ( & V_189 -> V_14 , V_190 ,
V_191 , 1 ,
& V_189 -> V_16 , V_192 ,
V_193 , 1 , 0 ) ;
F_62 ( & V_5 -> V_169 ) ;
V_176 = & V_23 [ V_189 -> V_20 ] ;
if ( V_189 -> V_14 > V_176 -> V_186 . V_14 || V_189 -> V_16 > V_176 -> V_186 . V_16 )
V_33 = - V_58 ;
else
V_189 -> V_177 = V_176 -> V_177 ;
F_63 ( & V_5 -> V_169 ) ;
return V_33 ;
}
static int F_72 ( struct V_1 * V_7 ,
struct V_187 * V_136 ,
struct V_194 * V_18 )
{
if ( V_18 -> V_20 >= F_29 ( V_19 ) )
return - V_58 ;
V_18 -> V_18 = V_19 [ V_18 -> V_20 ] . V_18 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_7 ,
struct V_187 * V_136 ,
struct V_195 * V_196 )
{
int V_11 = F_29 ( V_19 ) ;
if ( V_196 -> V_20 > 0 )
return - V_58 ;
while ( -- V_11 )
if ( V_196 -> V_18 == V_19 [ V_11 ] . V_18 )
break;
V_196 -> V_18 = V_19 [ V_11 ] . V_18 ;
V_196 -> V_197 = V_190 ;
V_196 -> V_198 = V_191 ;
V_196 -> V_199 = V_192 ;
V_196 -> V_200 = V_193 ;
return 0 ;
}
static struct V_122 *
F_74 ( struct V_5 * V_5 , struct V_187 * V_136 ,
enum V_201 V_202 )
{
if ( V_202 == V_203 )
return & V_5 -> V_124 ;
F_75 ( V_202 != V_204 ) ;
return F_76 ( & V_5 -> V_7 , V_136 , 0 ) ;
}
static void F_77 ( struct V_5 * V_5 ,
struct V_117 * V_118 )
{
unsigned int V_20 ;
F_71 ( & V_118 -> V_14 , V_190 ,
V_191 , 1 ,
& V_118 -> V_16 , V_192 ,
V_193 , 1 , 0 ) ;
if ( V_118 -> V_119 != V_205 &&
V_118 -> V_119 != V_206 )
V_118 -> V_119 = V_205 ;
V_20 = F_31 ( V_5 , V_118 ) ;
V_118 -> V_119 = V_19 [ V_20 ] . V_119 ;
V_118 -> V_18 = V_19 [ V_20 ] . V_18 ;
V_118 -> V_207 = V_208 ;
}
static int F_78 ( struct V_1 * V_7 , struct V_187 * V_136 ,
struct V_209 * V_210 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_117 * V_118 ;
memset ( V_210 -> V_211 , 0 , sizeof( V_210 -> V_211 ) ) ;
if ( V_210 -> V_202 == V_204 ) {
V_118 = F_79 ( V_7 , V_136 , 0 ) ;
V_210 -> V_212 = * V_118 ;
return 0 ;
}
F_62 ( & V_5 -> V_169 ) ;
V_210 -> V_212 = V_5 -> V_9 -> V_13 ;
F_63 ( & V_5 -> V_169 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_7 , struct V_187 * V_136 ,
struct V_209 * V_210 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_8 * V_9 = V_5 -> V_9 ;
struct V_117 * V_118 ;
struct V_122 * V_213 ;
int V_33 = 0 ;
F_62 ( & V_5 -> V_169 ) ;
F_77 ( V_5 , & V_210 -> V_212 ) ;
if ( V_210 -> V_202 == V_204 ) {
V_118 = F_79 ( V_7 , V_136 , V_210 -> V_214 ) ;
V_213 = F_76 ( V_7 , V_136 , 0 ) ;
} else {
if ( V_5 -> V_167 ) {
V_33 = - V_215 ;
} else {
V_118 = & V_9 -> V_13 ;
V_213 = & V_5 -> V_124 ;
V_5 -> V_156 = 1 ;
}
}
if ( V_33 == 0 ) {
struct V_175 V_22 = {
. V_177 = { 0 , 1 }
} ;
* V_118 = V_210 -> V_212 ;
V_213 -> V_14 = F_81 (unsigned int, crop->width, mf->width,
S5K6AA_WIN_WIDTH_MAX) ;
V_213 -> V_16 = F_81 (unsigned int, crop->height, mf->height,
S5K6AA_WIN_HEIGHT_MAX) ;
V_213 -> V_128 = F_81 (unsigned int, crop->left, 0 ,
S5K6AA_WIN_WIDTH_MAX - crop->width) ;
V_213 -> V_130 = F_81 (unsigned int, crop->top, 0 ,
S5K6AA_WIN_HEIGHT_MAX - crop->height) ;
V_33 = F_68 ( V_5 , & V_22 ) ;
}
F_63 ( & V_5 -> V_169 ) ;
return V_33 ;
}
static int F_82 ( struct V_1 * V_7 ,
struct V_187 * V_136 ,
struct V_216 * V_217 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_122 * V_218 ;
if ( V_217 -> V_219 != V_220 )
return - V_58 ;
memset ( V_217 -> V_211 , 0 , sizeof( V_217 -> V_211 ) ) ;
F_62 ( & V_5 -> V_169 ) ;
V_218 = F_74 ( V_5 , V_136 , V_217 -> V_202 ) ;
V_217 -> V_123 = * V_218 ;
F_63 ( & V_5 -> V_169 ) ;
F_8 ( 1 , V_40 , V_7 , L_9 ,
V_218 -> V_128 , V_218 -> V_130 , V_218 -> V_14 , V_218 -> V_16 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_7 ,
struct V_187 * V_136 ,
struct V_216 * V_217 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_117 * V_118 ;
unsigned int V_221 , V_222 ;
struct V_122 * V_223 ;
if ( V_217 -> V_219 != V_220 )
return - V_58 ;
F_62 ( & V_5 -> V_169 ) ;
V_223 = F_74 ( V_5 , V_136 , V_217 -> V_202 ) ;
if ( V_217 -> V_202 == V_203 ) {
V_118 = & V_5 -> V_9 -> V_13 ;
V_5 -> V_132 = 1 ;
} else {
V_118 = F_79 ( V_7 , V_136 , 0 ) ;
}
F_71 ( & V_217 -> V_123 . V_14 , V_118 -> V_14 ,
V_191 , 1 ,
& V_217 -> V_123 . V_16 , V_118 -> V_16 ,
V_193 , 1 , 0 ) ;
V_221 = ( V_191 - V_217 -> V_123 . V_14 ) & ~ 1 ;
V_222 = ( V_193 - V_217 -> V_123 . V_16 ) & ~ 1 ;
V_217 -> V_123 . V_128 = F_81 (unsigned int, sel->r.left, 0 , max_x) ;
V_217 -> V_123 . V_130 = F_81 (unsigned int, sel->r.top, 0 , max_y) ;
* V_223 = V_217 -> V_123 ;
F_63 ( & V_5 -> V_169 ) ;
F_8 ( 1 , V_40 , V_7 , L_10 ,
V_223 -> V_128 , V_223 -> V_130 , V_223 -> V_14 , V_223 -> V_16 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_25 * V_26 = F_14 ( V_7 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_149 , V_179 = 0 ;
F_8 ( 1 , V_40 , V_7 , L_11 , V_3 -> V_114 , V_3 -> V_28 ) ;
F_62 ( & V_5 -> V_169 ) ;
if ( V_5 -> V_170 == 0 )
goto V_224;
V_149 = V_5 -> V_9 -> V_20 ;
switch ( V_3 -> V_114 ) {
case V_225 :
V_179 = F_23 ( V_5 , V_3 -> V_28 ) ;
break;
case V_226 :
V_179 = F_11 ( V_26 , V_227 , V_3 -> V_28 ) ;
break;
case V_228 :
V_179 = F_28 ( V_5 , V_3 -> V_28 ) ;
break;
case V_229 :
V_179 = F_11 ( V_26 , V_230 , V_3 -> V_28 ) ;
break;
case V_231 :
V_179 = F_26 ( V_5 , V_3 -> V_28 ) ;
break;
case V_232 :
V_179 = F_21 ( V_5 , V_3 -> V_28 ) ;
if ( V_179 )
break;
V_179 = F_11 ( V_26 , V_146 , 1 ) ;
break;
case V_233 :
V_179 = F_27 ( V_5 , V_3 -> V_28 ) ;
break;
case V_234 :
V_179 = F_11 ( V_26 , V_235 , V_3 -> V_28 ) ;
break;
case V_236 :
V_179 = F_11 ( V_26 , V_237 , V_3 -> V_28 ) ;
break;
case V_238 :
V_179 = F_11 ( V_26 , F_85 ( V_149 ) , V_3 -> V_28 ) ;
if ( V_179 )
break;
V_179 = F_11 ( V_26 , V_146 , 1 ) ;
break;
}
V_224:
F_63 ( & V_5 -> V_169 ) ;
return V_179 ;
}
static int F_86 ( struct V_1 * V_7 )
{
F_87 ( V_7 -> V_171 , V_7 -> V_239 ) ;
return 0 ;
}
static int F_88 ( struct V_5 * V_5 )
{
const struct V_240 * V_241 = & V_242 ;
struct V_76 * V_6 = & V_5 -> V_6 ;
struct V_243 * V_244 = & V_6 -> V_4 ;
int V_33 = F_89 ( V_244 , 16 ) ;
if ( V_33 )
return V_33 ;
V_6 -> V_75 = F_90 ( V_244 , V_241 , V_225 ,
0 , 1 , 1 , 1 ) ;
V_6 -> V_80 = F_91 ( V_244 , & V_76 [ 0 ] , NULL ) ;
V_6 -> V_83 = F_91 ( V_244 , & V_76 [ 1 ] , NULL ) ;
V_6 -> V_86 = F_91 ( V_244 , & V_76 [ 2 ] , NULL ) ;
F_92 ( 4 , & V_6 -> V_75 , 0 , false ) ;
V_6 -> V_245 = F_90 ( V_244 , V_241 , V_232 , 0 , 1 , 1 , 0 ) ;
V_6 -> V_71 = F_90 ( V_244 , V_241 , V_246 , 0 , 1 , 1 , 0 ) ;
F_93 ( 2 , & V_6 -> V_245 ) ;
V_6 -> V_247 = F_94 ( V_244 , V_241 ,
V_231 ,
V_248 , 0 , V_99 ) ;
V_6 -> V_89 = F_90 ( V_244 , V_241 , V_249 ,
0 , 6000000U , 1 , 100000U ) ;
V_6 -> V_93 = F_90 ( V_244 , V_241 , V_250 ,
0 , 256 , 1 , 256 ) ;
F_92 ( 3 , & V_6 -> V_247 , 0 , false ) ;
F_94 ( V_244 , V_241 , V_233 ,
V_102 , 0 ,
V_102 ) ;
F_94 ( V_244 , V_241 , V_228 ,
V_112 , ~ 0x6f , V_108 ) ;
F_90 ( V_244 , V_241 , V_238 ,
0 , 256 , 1 , 0 ) ;
F_90 ( V_244 , V_241 , V_234 , - 127 , 127 , 1 , 0 ) ;
F_90 ( V_244 , V_241 , V_226 , - 127 , 127 , 1 , 0 ) ;
F_90 ( V_244 , V_241 , V_229 , - 127 , 127 , 1 , 0 ) ;
F_90 ( V_244 , V_241 , V_236 , - 127 , 127 , 1 , 0 ) ;
if ( V_244 -> error ) {
V_33 = V_244 -> error ;
F_95 ( V_244 ) ;
return V_33 ;
}
V_5 -> V_7 . V_171 = V_244 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_7 , struct V_251 * V_252 )
{
struct V_117 * V_212 = F_79 ( V_7 , V_252 -> V_214 , 0 ) ;
struct V_122 * V_213 = F_76 ( V_7 , V_252 -> V_214 , 0 ) ;
V_212 -> V_119 = V_19 [ 0 ] . V_119 ;
V_212 -> V_18 = V_19 [ 0 ] . V_18 ;
V_212 -> V_14 = V_15 ;
V_212 -> V_16 = V_17 ;
V_212 -> V_207 = V_208 ;
V_213 -> V_14 = V_191 ;
V_213 -> V_16 = V_193 ;
V_213 -> V_128 = 0 ;
V_213 -> V_130 = 0 ;
return 0 ;
}
static int F_97 ( struct V_5 * V_5 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
T_1 V_253 = 0 , V_254 = 0 ;
int V_33 = F_15 ( V_26 ) ;
if ( ! V_33 )
V_33 = F_12 ( V_26 , V_255 , & V_253 ) ;
if ( ! V_33 )
V_33 = F_12 ( V_26 , V_256 , & V_254 ) ;
if ( V_33 ) {
F_98 ( & V_5 -> V_7 , L_12 ) ;
return V_33 ;
}
F_99 ( & V_5 -> V_7 , L_13 ,
V_253 , V_254 ) ;
return V_253 == V_257 ? 0 : - V_258 ;
}
static int F_100 ( struct V_1 * V_7 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 ;
F_62 ( & V_5 -> V_169 ) ;
V_33 = F_57 ( V_5 ) ;
if ( ! V_33 ) {
F_51 ( 100 ) ;
V_33 = F_97 ( V_5 ) ;
F_59 ( V_5 ) ;
}
F_63 ( & V_5 -> V_169 ) ;
return V_33 ;
}
static int F_101 ( struct V_5 * V_5 ,
const struct V_259 * V_260 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
const struct V_261 * V_160 ;
unsigned long V_34 ;
int V_33 ;
V_5 -> V_160 [ V_164 ] . V_160 = - V_58 ;
V_5 -> V_160 [ V_166 ] . V_160 = - V_58 ;
V_160 = & V_260 -> V_262 ;
if ( F_53 ( V_160 -> V_160 ) ) {
V_34 = ( V_160 -> V_161 ? V_263 : V_264 )
| V_265 ;
V_33 = F_102 ( & V_26 -> V_266 , V_160 -> V_160 , V_34 ,
L_14 ) ;
if ( V_33 < 0 )
return V_33 ;
V_5 -> V_160 [ V_164 ] = * V_160 ;
}
V_160 = & V_260 -> V_267 ;
if ( F_53 ( V_160 -> V_160 ) ) {
V_34 = ( V_160 -> V_161 ? V_263 : V_264 )
| V_265 ;
V_33 = F_102 ( & V_26 -> V_266 , V_160 -> V_160 , V_34 ,
L_15 ) ;
if ( V_33 < 0 )
return V_33 ;
V_5 -> V_160 [ V_166 ] = * V_160 ;
}
return 0 ;
}
static int F_103 ( struct V_25 * V_26 ,
const struct V_268 * V_114 )
{
const struct V_259 * V_260 = V_26 -> V_266 . V_269 ;
struct V_1 * V_7 ;
struct V_5 * V_5 ;
int V_11 , V_33 ;
if ( V_260 == NULL ) {
F_104 ( & V_26 -> V_266 , L_16 ) ;
return - V_58 ;
}
if ( V_260 -> V_54 == 0 ) {
F_104 ( & V_26 -> V_266 , L_17 ) ;
return - V_58 ;
}
V_5 = F_105 ( & V_26 -> V_266 , sizeof( * V_5 ) , V_270 ) ;
if ( ! V_5 )
return - V_271 ;
F_106 ( & V_5 -> V_169 ) ;
V_5 -> V_54 = V_260 -> V_54 ;
V_5 -> V_134 = V_260 -> V_134 ;
V_5 -> V_157 = V_260 -> V_135 ;
V_5 -> V_165 = V_260 -> V_272 ;
V_5 -> V_74 = V_260 -> V_70 ;
V_5 -> V_72 = V_260 -> V_273 ;
V_7 = & V_5 -> V_7 ;
F_107 ( V_7 , V_26 , & V_274 ) ;
F_108 ( V_7 -> V_239 , V_275 , sizeof( V_7 -> V_239 ) ) ;
V_7 -> V_276 = & V_277 ;
V_7 -> V_34 |= V_278 ;
V_5 -> V_214 . V_34 = V_279 ;
V_7 -> V_280 . type = V_281 ;
V_33 = F_109 ( & V_7 -> V_280 , 1 , & V_5 -> V_214 , 0 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_101 ( V_5 , V_260 ) ;
if ( V_33 )
goto V_282;
for ( V_11 = 0 ; V_11 < V_162 ; V_11 ++ )
V_5 -> V_163 [ V_11 ] . V_283 = V_284 [ V_11 ] ;
V_33 = F_110 ( & V_26 -> V_266 , V_162 ,
V_5 -> V_163 ) ;
if ( V_33 ) {
F_104 ( & V_26 -> V_266 , L_18 ) ;
goto V_282;
}
V_33 = F_88 ( V_5 ) ;
if ( V_33 )
goto V_282;
F_4 ( V_5 ) ;
V_5 -> V_124 . V_14 = V_191 ;
V_5 -> V_124 . V_16 = V_193 ;
V_5 -> V_124 . V_128 = 0 ;
V_5 -> V_124 . V_130 = 0 ;
return 0 ;
V_282:
F_111 ( & V_5 -> V_7 . V_280 ) ;
return V_33 ;
}
static int F_112 ( struct V_25 * V_26 )
{
struct V_1 * V_7 = F_113 ( V_26 ) ;
F_114 ( V_7 ) ;
F_95 ( V_7 -> V_171 ) ;
F_111 ( & V_7 -> V_280 ) ;
return 0 ;
}
