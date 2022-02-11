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
* V_28 = F_7 ( * ( ( T_1 * ) V_32 ) ) ;
F_8 ( 3 , V_39 , V_26 , L_1 , V_27 , * V_28 ) ;
return V_33 == 2 ? 0 : V_33 ;
}
static int F_9 ( struct V_25 * V_26 , T_1 V_27 , T_1 V_28 )
{
T_2 V_36 [ 4 ] = { V_27 >> 8 , V_27 & 0xFF , V_28 >> 8 , V_28 & 0xFF } ;
int V_33 = F_10 ( V_26 , V_36 , 4 ) ;
F_8 ( 3 , V_39 , V_26 , L_2 , V_27 , V_28 ) ;
return V_33 == 4 ? 0 : V_33 ;
}
static int F_11 ( struct V_25 * V_40 , T_1 V_27 , T_1 V_28 )
{
int V_33 = F_9 ( V_40 , V_41 , V_27 ) ;
if ( V_33 )
return V_33 ;
return F_9 ( V_40 , V_42 , V_28 ) ;
}
static int F_12 ( struct V_25 * V_26 , T_1 V_27 , T_1 * V_28 )
{
int V_33 = F_9 ( V_26 , V_43 , V_27 ) ;
if ( V_33 )
return V_33 ;
return F_5 ( V_26 , V_42 , V_28 ) ;
}
static int F_13 ( struct V_1 * V_7 ,
const struct V_44 * V_31 )
{
struct V_25 * V_26 = F_14 ( V_7 ) ;
T_1 V_45 = 0 ;
int V_33 = 0 ;
while ( V_31 -> V_27 != V_46 ) {
if ( V_45 != 2 )
V_33 = F_9 ( V_26 , V_41 ,
V_31 -> V_27 ) ;
if ( V_33 )
break;
V_33 = F_9 ( V_26 , V_42 , V_31 -> V_28 ) ;
if ( V_33 )
break;
V_45 = ( V_31 + 1 ) -> V_27 - V_31 -> V_27 ;
V_31 ++ ;
}
return V_33 ;
}
static int F_15 ( struct V_25 * V_26 )
{
int V_33 = F_9 ( V_26 , V_47 , V_48 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_9 ( V_26 , V_49 , V_50 ) ;
if ( V_33 )
return V_33 ;
return F_9 ( V_26 , V_51 , V_50 ) ;
}
static int F_16 ( struct V_5 * V_5 )
{
struct V_25 * V_40 = F_14 ( & V_5 -> V_7 ) ;
unsigned long V_52 = V_5 -> V_53 / 1000 ;
T_1 V_54 ;
int V_33 ;
if ( F_17 ( V_52 < V_55 || V_52 > V_56 ,
L_3 , V_52 ) )
return - V_57 ;
V_5 -> V_58 = V_59 ;
V_5 -> V_60 = V_61 ;
V_5 -> V_62 = V_63 ;
V_33 = F_11 ( V_40 , V_64 , V_52 >> 16 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_65 , V_52 & 0xFFFF ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_66 , 1 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , F_18 ( 0 ) , V_5 -> V_62 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , F_19 ( 0 ) ,
V_5 -> V_58 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , F_20 ( 0 ) ,
V_5 -> V_60 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_67 , 1 ) ;
if ( ! V_33 )
V_33 = F_12 ( V_40 , V_68 , & V_54 ) ;
return V_33 ? V_33 : ( V_54 ? - V_57 : 0 ) ;
}
static int F_21 ( struct V_5 * V_5 , int V_69 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_20 = V_5 -> V_9 -> V_20 ;
unsigned int V_70 = V_5 -> V_6 . V_70 -> V_28 ^ V_5 -> V_71 ;
unsigned int V_72 = ( V_69 ^ V_5 -> V_73 ) | ( V_70 << 1 ) ;
return F_11 ( V_26 , F_22 ( V_20 ) , V_72 ) ;
}
static int F_23 ( struct V_5 * V_5 , int V_74 )
{
struct V_25 * V_40 = F_14 ( & V_5 -> V_7 ) ;
struct V_75 * V_6 = & V_5 -> V_6 ;
T_1 V_76 ;
int V_33 = F_12 ( V_40 , V_77 , & V_76 ) ;
if ( ! V_33 && ! V_74 ) {
V_33 = F_11 ( V_40 , V_78 , V_6 -> V_79 -> V_28 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_80 , 1 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_11 ( V_40 , V_81 , V_6 -> V_82 -> V_28 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_83 , 1 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_11 ( V_40 , V_84 , V_6 -> V_85 -> V_28 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_86 , 1 ) ;
}
if ( ! V_33 ) {
V_76 = V_74 ? V_76 | V_87 : V_76 & ~ V_87 ;
V_33 = F_11 ( V_40 , V_77 , V_76 ) ;
}
return V_33 ;
}
static int F_24 ( struct V_25 * V_26 , int V_88 )
{
unsigned int time = V_88 / 10 ;
int V_33 = F_11 ( V_26 , V_89 , time & 0xffff ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_90 , time >> 16 ) ;
if ( V_33 )
return V_33 ;
return F_11 ( V_26 , V_91 , 1 ) ;
}
static int F_25 ( struct V_25 * V_26 , int V_92 )
{
int V_33 = F_11 ( V_26 , V_93 , V_92 ) ;
if ( V_33 )
return V_33 ;
return F_11 ( V_26 , V_94 , 1 ) ;
}
static int F_26 ( struct V_5 * V_5 , int V_95 )
{
struct V_25 * V_40 = F_14 ( & V_5 -> V_7 ) ;
unsigned int V_96 = V_5 -> V_6 . V_88 -> V_28 ;
T_1 V_97 ;
int V_33 = F_12 ( V_40 , V_77 , & V_97 ) ;
if ( V_33 )
return V_33 ;
F_8 ( 1 , V_39 , V_40 , L_4 ,
V_96 , V_95 , V_97 ) ;
if ( V_95 == V_98 ) {
V_97 |= V_99 | V_100 ;
} else {
V_33 = F_24 ( V_40 , V_96 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_25 ( V_40 , V_5 -> V_6 . V_92 -> V_28 ) ;
if ( V_33 )
return V_33 ;
V_97 &= ~ ( V_99 | V_100 ) ;
}
return F_11 ( V_40 , V_77 , V_97 ) ;
}
static int F_27 ( struct V_5 * V_5 , int V_95 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
T_1 V_97 ;
int V_33 ;
V_33 = F_12 ( V_26 , V_77 , & V_97 ) ;
if ( V_33 )
return V_33 ;
if ( V_95 == V_101 ) {
V_97 |= V_102 ;
} else {
V_97 &= ~ V_102 ;
V_33 = F_11 ( V_26 , V_103 , V_95 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_11 ( V_26 , V_104 , 1 ) ;
if ( V_33 )
return V_33 ;
}
return F_11 ( V_26 , V_77 , V_97 ) ;
}
static int F_28 ( struct V_5 * V_5 , int V_28 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
static const struct V_105 V_106 [] = {
{ V_107 , 0 } ,
{ V_108 , 1 } ,
{ V_109 , 2 } ,
{ V_110 , 3 } ,
{ V_111 , 4 } ,
{ V_112 , 5 } ,
} ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_106 ) ; V_11 ++ ) {
if ( V_106 [ V_11 ] . V_113 == V_28 )
return F_11 ( V_26 , V_114 ,
V_106 [ V_11 ] . V_95 ) ;
}
return - V_57 ;
}
static int F_30 ( struct V_25 * V_26 )
{
T_1 error = 0 ;
int V_33 = F_12 ( V_26 , V_115 , & error ) ;
F_8 ( 1 , V_39 , V_26 , L_5 , error , V_33 ) ;
return V_33 ? V_33 : ( error ? - V_57 : 0 ) ;
}
static int F_31 ( struct V_5 * V_5 ,
struct V_116 * V_117 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_19 ) ; V_11 ++ )
if ( V_117 -> V_118 == V_19 [ V_11 ] . V_118 &&
V_117 -> V_18 == V_19 [ V_11 ] . V_18 )
return V_11 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_5 ,
struct V_8 * V_9 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_119 = F_31 ( V_5 , & V_9 -> V_13 ) ;
int V_33 ;
V_33 = F_11 ( V_26 , F_33 ( V_9 -> V_20 ) ,
V_9 -> V_13 . V_14 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_34 ( V_9 -> V_20 ) ,
V_9 -> V_13 . V_16 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_35 ( V_9 -> V_20 ) ,
V_19 [ V_119 ] . V_120 ) ;
return V_33 ;
}
static int F_36 ( struct V_5 * V_5 )
{
struct V_25 * V_40 = F_14 ( & V_5 -> V_7 ) ;
struct V_121 * V_122 = & V_5 -> V_123 ;
int V_33 ;
V_33 = F_11 ( V_40 , V_124 , V_122 -> V_14 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_125 , V_122 -> V_16 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_126 , V_122 -> V_127 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_128 , V_122 -> V_129 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_40 , V_130 , 1 ) ;
if ( ! V_33 )
V_5 -> V_131 = 0 ;
return V_33 ;
}
static int F_37 ( struct V_5 * V_5 ,
enum V_132 V_133 , int V_134 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
T_1 V_135 = 0 ;
int V_33 ;
if ( V_133 == V_136 )
V_135 = V_134 ;
else if ( V_133 != V_137 )
return - V_57 ;
V_33 = F_11 ( V_26 , V_138 , V_135 ) ;
if ( V_33 )
return V_33 ;
return F_11 ( V_26 , V_139 , 1 ) ;
}
static int F_38 ( struct V_25 * V_26 , int V_140 ,
int V_141 )
{
unsigned long V_142 = V_143 + F_39 ( V_140 ) ;
T_1 V_76 = 1 ;
int V_33 ;
V_33 = F_11 ( V_26 , V_144 , V_141 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_145 , 1 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_146 , 1 ) ;
if ( V_140 == 0 )
return V_33 ;
while ( V_33 >= 0 && F_40 ( V_142 ) ) {
V_33 = F_12 ( V_26 , V_146 , & V_76 ) ;
if ( ! V_76 )
return 0 ;
F_41 ( 1000 , 5000 ) ;
}
return V_33 ? V_33 : - V_147 ;
}
static int F_42 ( struct V_5 * V_5 ,
struct V_8 * V_9 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_148 = V_9 -> V_20 ;
T_1 V_149 ;
int V_33 ;
if ( V_5 -> V_22 -> V_150 >= V_151 )
V_149 = V_152 ;
else
V_149 = V_153 ;
V_33 = F_32 ( V_5 , V_9 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_43 ( V_148 ) ,
V_5 -> V_60 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_44 ( V_148 ) ,
V_5 -> V_58 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_45 ( V_148 ) ,
V_9 -> V_21 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_46 ( V_148 ) ,
V_154 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_47 ( V_148 ) ,
V_149 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_48 ( V_148 ) ,
V_5 -> V_22 -> V_150 + 33 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , F_49 ( V_148 ) ,
V_5 -> V_22 -> V_150 - 33 ) ;
if ( ! V_33 )
V_33 = F_38 ( V_26 , 250 , V_148 ) ;
if ( ! V_33 )
V_33 = F_30 ( V_26 ) ;
if ( ! V_33 )
V_5 -> V_155 = 0 ;
F_8 ( 1 , V_39 , V_26 , L_6 ,
V_5 -> V_22 -> V_150 , V_33 ) ;
return V_33 ;
}
static int F_50 ( struct V_1 * V_7 )
{
struct V_25 * V_26 = F_14 ( V_7 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 ;
V_5 -> V_131 = 1 ;
V_5 -> V_155 = 1 ;
F_51 ( 100 ) ;
V_33 = F_15 ( V_26 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_37 ( V_5 , V_5 -> V_133 ,
V_5 -> V_156 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_13 ( V_7 , V_157 ) ;
if ( V_33 )
return V_33 ;
F_51 ( 20 ) ;
return F_16 ( V_5 ) ;
}
static int F_52 ( struct V_5 * V_158 , int V_113 , T_3 V_28 )
{
if ( ! F_53 ( V_158 -> V_159 [ V_113 ] . V_159 ) )
return 0 ;
F_54 ( V_158 -> V_159 [ V_113 ] . V_159 , ! ! V_28 ) ;
return 1 ;
}
static int F_55 ( struct V_5 * V_158 , int V_113 )
{
return F_52 ( V_158 , V_113 , V_158 -> V_159 [ V_113 ] . V_160 ) ;
}
static int F_56 ( struct V_5 * V_158 , int V_113 )
{
return F_52 ( V_158 , V_113 , ! V_158 -> V_159 [ V_113 ] . V_160 ) ;
}
static int F_57 ( struct V_5 * V_5 )
{
int V_33 ;
V_33 = F_58 ( V_161 , V_5 -> V_162 ) ;
if ( V_33 )
return V_33 ;
if ( F_56 ( V_5 , V_163 ) )
F_41 ( 150 , 200 ) ;
if ( V_5 -> V_164 )
V_33 = V_5 -> V_164 ( 1 ) ;
F_41 ( 4000 , 4000 ) ;
if ( F_56 ( V_5 , V_165 ) )
F_51 ( 20 ) ;
return V_33 ;
}
static int F_59 ( struct V_5 * V_5 )
{
int V_33 ;
if ( F_55 ( V_5 , V_165 ) )
F_41 ( 100 , 150 ) ;
if ( V_5 -> V_164 ) {
V_33 = V_5 -> V_164 ( 0 ) ;
if ( V_33 )
return V_33 ;
}
if ( F_55 ( V_5 , V_163 ) )
F_41 ( 50 , 100 ) ;
V_5 -> V_166 = 0 ;
return F_60 ( V_161 , V_5 -> V_162 ) ;
}
static int F_61 ( struct V_1 * V_7 , int V_167 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 = 0 ;
F_62 ( & V_5 -> V_168 ) ;
if ( ! V_167 == V_5 -> V_169 ) {
if ( V_167 ) {
V_33 = F_57 ( V_5 ) ;
if ( ! V_33 )
V_33 = F_50 ( V_7 ) ;
} else {
V_33 = F_59 ( V_5 ) ;
}
if ( ! V_33 )
V_5 -> V_169 += V_167 ? 1 : - 1 ;
}
F_63 ( & V_5 -> V_168 ) ;
if ( ! V_167 || V_33 || V_5 -> V_169 != 1 )
return V_33 ;
return F_64 ( V_7 -> V_170 ) ;
}
static int F_65 ( struct V_5 * V_5 , int V_171 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
int V_33 = 0 ;
V_33 = F_11 ( V_26 , V_172 , V_171 ) ;
if ( ! V_33 )
V_33 = F_11 ( V_26 , V_173 , 1 ) ;
if ( ! V_33 )
V_5 -> V_166 = V_171 ;
return V_33 ;
}
static int F_66 ( struct V_1 * V_7 , int V_167 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 = 0 ;
F_62 ( & V_5 -> V_168 ) ;
if ( V_5 -> V_166 == ! V_167 ) {
if ( ! V_33 && V_5 -> V_155 )
V_33 = F_42 ( V_5 , V_5 -> V_9 ) ;
if ( V_5 -> V_131 )
V_33 = F_36 ( V_5 ) ;
if ( ! V_33 )
V_33 = F_65 ( V_5 , ! ! V_167 ) ;
}
F_63 ( & V_5 -> V_168 ) ;
return V_33 ;
}
static int F_67 ( struct V_1 * V_7 ,
struct V_174 * V_175 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
F_62 ( & V_5 -> V_168 ) ;
V_175 -> V_176 = V_5 -> V_22 -> V_176 ;
F_63 ( & V_5 -> V_168 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_5 ,
struct V_174 * V_175 )
{
struct V_116 * V_13 = & V_5 -> V_9 -> V_13 ;
const struct V_177 * V_22 = & V_23 [ 0 ] ;
unsigned int V_178 , V_179 = V_180 ;
unsigned int V_11 , V_181 ;
if ( V_175 -> V_176 . V_182 == 0 )
return - V_57 ;
V_181 = V_175 -> V_176 . V_183 * 10000 / V_175 -> V_176 . V_182 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_23 ) ; V_11 ++ ) {
const struct V_177 * V_184 = & V_23 [ V_11 ] ;
if ( V_13 -> V_14 > V_184 -> V_185 . V_14 ||
V_13 -> V_16 > V_184 -> V_185 . V_16 )
continue;
V_178 = abs ( V_184 -> V_150 - V_181 ) ;
if ( V_178 < V_179 ) {
V_22 = V_184 ;
V_179 = V_178 ;
}
}
V_5 -> V_22 = V_22 ;
F_8 ( 1 , V_39 , & V_5 -> V_7 , L_7 ,
V_22 -> V_150 * 100 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_7 ,
struct V_174 * V_175 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 ;
F_8 ( 1 , V_39 , V_7 , L_8 ,
V_175 -> V_176 . V_183 , V_175 -> V_176 . V_182 ) ;
F_62 ( & V_5 -> V_168 ) ;
V_33 = F_68 ( V_5 , V_175 ) ;
V_5 -> V_155 = 1 ;
F_63 ( & V_5 -> V_168 ) ;
return V_33 ;
}
static int F_70 ( struct V_1 * V_7 ,
struct V_186 * V_187 ,
struct V_188 * V_189 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
const struct V_177 * V_175 ;
int V_33 = 0 ;
if ( V_189 -> V_20 > F_29 ( V_23 ) )
return - V_57 ;
F_71 ( & V_189 -> V_14 , V_190 ,
V_191 , 1 ,
& V_189 -> V_16 , V_192 ,
V_193 , 1 , 0 ) ;
F_62 ( & V_5 -> V_168 ) ;
V_175 = & V_23 [ V_189 -> V_20 ] ;
if ( V_189 -> V_14 > V_175 -> V_185 . V_14 || V_189 -> V_16 > V_175 -> V_185 . V_16 )
V_33 = - V_57 ;
else
V_189 -> V_176 = V_175 -> V_176 ;
F_63 ( & V_5 -> V_168 ) ;
return V_33 ;
}
static int F_72 ( struct V_1 * V_7 ,
struct V_186 * V_187 ,
struct V_194 * V_18 )
{
if ( V_18 -> V_20 >= F_29 ( V_19 ) )
return - V_57 ;
V_18 -> V_18 = V_19 [ V_18 -> V_20 ] . V_18 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_7 ,
struct V_186 * V_187 ,
struct V_195 * V_196 )
{
int V_11 = F_29 ( V_19 ) ;
if ( V_196 -> V_20 > 0 )
return - V_57 ;
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
static struct V_121 *
F_74 ( struct V_5 * V_5 , struct V_186 * V_187 ,
enum V_201 V_202 )
{
if ( V_202 == V_203 )
return & V_5 -> V_123 ;
F_75 ( V_202 != V_204 ) ;
return F_76 ( V_187 , 0 ) ;
}
static void F_77 ( struct V_5 * V_5 ,
struct V_116 * V_117 )
{
unsigned int V_20 ;
F_71 ( & V_117 -> V_14 , V_190 ,
V_191 , 1 ,
& V_117 -> V_16 , V_192 ,
V_193 , 1 , 0 ) ;
if ( V_117 -> V_118 != V_205 &&
V_117 -> V_118 != V_206 )
V_117 -> V_118 = V_205 ;
V_20 = F_31 ( V_5 , V_117 ) ;
V_117 -> V_118 = V_19 [ V_20 ] . V_118 ;
V_117 -> V_18 = V_19 [ V_20 ] . V_18 ;
V_117 -> V_207 = V_208 ;
}
static int F_78 ( struct V_1 * V_7 , struct V_186 * V_187 ,
struct V_209 * V_210 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_116 * V_117 ;
memset ( V_210 -> V_211 , 0 , sizeof( V_210 -> V_211 ) ) ;
if ( V_210 -> V_202 == V_204 ) {
V_117 = F_79 ( V_187 , 0 ) ;
V_210 -> V_212 = * V_117 ;
return 0 ;
}
F_62 ( & V_5 -> V_168 ) ;
V_210 -> V_212 = V_5 -> V_9 -> V_13 ;
F_63 ( & V_5 -> V_168 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_7 , struct V_186 * V_187 ,
struct V_209 * V_210 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_8 * V_9 = V_5 -> V_9 ;
struct V_116 * V_117 ;
struct V_121 * V_213 ;
int V_33 = 0 ;
F_62 ( & V_5 -> V_168 ) ;
F_77 ( V_5 , & V_210 -> V_212 ) ;
if ( V_210 -> V_202 == V_204 ) {
V_117 = F_79 ( V_187 , V_210 -> V_214 ) ;
V_213 = F_76 ( V_187 , 0 ) ;
} else {
if ( V_5 -> V_166 ) {
V_33 = - V_215 ;
} else {
V_117 = & V_9 -> V_13 ;
V_213 = & V_5 -> V_123 ;
V_5 -> V_155 = 1 ;
}
}
if ( V_33 == 0 ) {
struct V_174 V_22 = {
. V_176 = { 0 , 1 }
} ;
* V_117 = V_210 -> V_212 ;
V_213 -> V_14 = F_81 (unsigned int, crop->width, mf->width,
S5K6AA_WIN_WIDTH_MAX) ;
V_213 -> V_16 = F_81 (unsigned int, crop->height, mf->height,
S5K6AA_WIN_HEIGHT_MAX) ;
V_213 -> V_127 = F_81 (unsigned int, crop->left, 0 ,
S5K6AA_WIN_WIDTH_MAX - crop->width) ;
V_213 -> V_129 = F_81 (unsigned int, crop->top, 0 ,
S5K6AA_WIN_HEIGHT_MAX - crop->height) ;
V_33 = F_68 ( V_5 , & V_22 ) ;
}
F_63 ( & V_5 -> V_168 ) ;
return V_33 ;
}
static int F_82 ( struct V_1 * V_7 , struct V_186 * V_187 ,
struct V_216 * V_213 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_121 * V_217 ;
memset ( V_213 -> V_211 , 0 , sizeof( V_213 -> V_211 ) ) ;
F_62 ( & V_5 -> V_168 ) ;
V_217 = F_74 ( V_5 , V_187 , V_213 -> V_202 ) ;
V_213 -> V_217 = * V_217 ;
F_63 ( & V_5 -> V_168 ) ;
F_8 ( 1 , V_39 , V_7 , L_9 ,
V_217 -> V_127 , V_217 -> V_129 , V_217 -> V_14 , V_217 -> V_16 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_7 , struct V_186 * V_187 ,
struct V_216 * V_213 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
struct V_116 * V_117 ;
unsigned int V_218 , V_219 ;
struct V_121 * V_220 ;
F_62 ( & V_5 -> V_168 ) ;
V_220 = F_74 ( V_5 , V_187 , V_213 -> V_202 ) ;
if ( V_213 -> V_202 == V_203 ) {
V_117 = & V_5 -> V_9 -> V_13 ;
V_5 -> V_131 = 1 ;
} else {
V_117 = F_79 ( V_187 , 0 ) ;
}
F_71 ( & V_213 -> V_217 . V_14 , V_117 -> V_14 ,
V_191 , 1 ,
& V_213 -> V_217 . V_16 , V_117 -> V_16 ,
V_193 , 1 , 0 ) ;
V_218 = ( V_191 - V_213 -> V_217 . V_14 ) & ~ 1 ;
V_219 = ( V_193 - V_213 -> V_217 . V_16 ) & ~ 1 ;
V_213 -> V_217 . V_127 = F_81 (unsigned int, crop->rect.left, 0 , max_x) ;
V_213 -> V_217 . V_129 = F_81 (unsigned int, crop->rect.top, 0 , max_y) ;
* V_220 = V_213 -> V_217 ;
F_63 ( & V_5 -> V_168 ) ;
F_8 ( 1 , V_39 , V_7 , L_10 ,
V_220 -> V_127 , V_220 -> V_129 , V_220 -> V_14 , V_220 -> V_16 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_25 * V_26 = F_14 ( V_7 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_148 , V_178 = 0 ;
F_8 ( 1 , V_39 , V_7 , L_11 , V_3 -> V_113 , V_3 -> V_28 ) ;
F_62 ( & V_5 -> V_168 ) ;
if ( V_5 -> V_169 == 0 )
goto V_221;
V_148 = V_5 -> V_9 -> V_20 ;
switch ( V_3 -> V_113 ) {
case V_222 :
V_178 = F_23 ( V_5 , V_3 -> V_28 ) ;
break;
case V_223 :
V_178 = F_11 ( V_26 , V_224 , V_3 -> V_28 ) ;
break;
case V_225 :
V_178 = F_28 ( V_5 , V_3 -> V_28 ) ;
break;
case V_226 :
V_178 = F_11 ( V_26 , V_227 , V_3 -> V_28 ) ;
break;
case V_228 :
V_178 = F_26 ( V_5 , V_3 -> V_28 ) ;
break;
case V_229 :
V_178 = F_21 ( V_5 , V_3 -> V_28 ) ;
if ( V_178 )
break;
V_178 = F_11 ( V_26 , V_145 , 1 ) ;
break;
case V_230 :
V_178 = F_27 ( V_5 , V_3 -> V_28 ) ;
break;
case V_231 :
V_178 = F_11 ( V_26 , V_232 , V_3 -> V_28 ) ;
break;
case V_233 :
V_178 = F_11 ( V_26 , V_234 , V_3 -> V_28 ) ;
break;
case V_235 :
V_178 = F_11 ( V_26 , F_85 ( V_148 ) , V_3 -> V_28 ) ;
if ( V_178 )
break;
V_178 = F_11 ( V_26 , V_145 , 1 ) ;
break;
}
V_221:
F_63 ( & V_5 -> V_168 ) ;
return V_178 ;
}
static int F_86 ( struct V_1 * V_7 )
{
F_87 ( V_7 -> V_170 , V_7 -> V_236 ) ;
return 0 ;
}
static int F_88 ( struct V_5 * V_5 )
{
const struct V_237 * V_238 = & V_239 ;
struct V_75 * V_6 = & V_5 -> V_6 ;
struct V_240 * V_241 = & V_6 -> V_4 ;
int V_33 = F_89 ( V_241 , 16 ) ;
if ( V_33 )
return V_33 ;
V_6 -> V_74 = F_90 ( V_241 , V_238 , V_222 ,
0 , 1 , 1 , 1 ) ;
V_6 -> V_79 = F_91 ( V_241 , & V_75 [ 0 ] , NULL ) ;
V_6 -> V_82 = F_91 ( V_241 , & V_75 [ 1 ] , NULL ) ;
V_6 -> V_85 = F_91 ( V_241 , & V_75 [ 2 ] , NULL ) ;
F_92 ( 4 , & V_6 -> V_74 , 0 , false ) ;
V_6 -> V_242 = F_90 ( V_241 , V_238 , V_229 , 0 , 1 , 1 , 0 ) ;
V_6 -> V_70 = F_90 ( V_241 , V_238 , V_243 , 0 , 1 , 1 , 0 ) ;
F_93 ( 2 , & V_6 -> V_242 ) ;
V_6 -> V_244 = F_94 ( V_241 , V_238 ,
V_228 ,
V_245 , 0 , V_98 ) ;
V_6 -> V_88 = F_90 ( V_241 , V_238 , V_246 ,
0 , 6000000U , 1 , 100000U ) ;
V_6 -> V_92 = F_90 ( V_241 , V_238 , V_247 ,
0 , 256 , 1 , 256 ) ;
F_92 ( 3 , & V_6 -> V_244 , 0 , false ) ;
F_94 ( V_241 , V_238 , V_230 ,
V_101 , 0 ,
V_101 ) ;
F_94 ( V_241 , V_238 , V_225 ,
V_111 , ~ 0x6f , V_107 ) ;
F_90 ( V_241 , V_238 , V_235 ,
0 , 256 , 1 , 0 ) ;
F_90 ( V_241 , V_238 , V_231 , - 127 , 127 , 1 , 0 ) ;
F_90 ( V_241 , V_238 , V_223 , - 127 , 127 , 1 , 0 ) ;
F_90 ( V_241 , V_238 , V_226 , - 127 , 127 , 1 , 0 ) ;
F_90 ( V_241 , V_238 , V_233 , - 127 , 127 , 1 , 0 ) ;
if ( V_241 -> error ) {
V_33 = V_241 -> error ;
F_95 ( V_241 ) ;
return V_33 ;
}
V_5 -> V_7 . V_170 = V_241 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_7 , struct V_186 * V_187 )
{
struct V_116 * V_212 = F_79 ( V_187 , 0 ) ;
struct V_121 * V_213 = F_76 ( V_187 , 0 ) ;
V_212 -> V_118 = V_19 [ 0 ] . V_118 ;
V_212 -> V_18 = V_19 [ 0 ] . V_18 ;
V_212 -> V_14 = V_15 ;
V_212 -> V_16 = V_17 ;
V_212 -> V_207 = V_208 ;
V_213 -> V_14 = V_191 ;
V_213 -> V_16 = V_193 ;
V_213 -> V_127 = 0 ;
V_213 -> V_129 = 0 ;
return 0 ;
}
static int F_97 ( struct V_5 * V_5 )
{
struct V_25 * V_26 = F_14 ( & V_5 -> V_7 ) ;
T_1 V_248 = 0 , V_249 = 0 ;
int V_33 = F_15 ( V_26 ) ;
if ( ! V_33 )
V_33 = F_12 ( V_26 , V_250 , & V_248 ) ;
if ( ! V_33 )
V_33 = F_12 ( V_26 , V_251 , & V_249 ) ;
if ( V_33 ) {
F_98 ( & V_5 -> V_7 , L_12 ) ;
return V_33 ;
}
F_99 ( & V_5 -> V_7 , L_13 ,
V_248 , V_249 ) ;
return V_248 == V_252 ? 0 : - V_253 ;
}
static int F_100 ( struct V_1 * V_7 )
{
struct V_5 * V_5 = F_3 ( V_7 ) ;
int V_33 ;
F_62 ( & V_5 -> V_168 ) ;
V_33 = F_57 ( V_5 ) ;
if ( ! V_33 ) {
F_51 ( 100 ) ;
V_33 = F_97 ( V_5 ) ;
F_59 ( V_5 ) ;
}
F_63 ( & V_5 -> V_168 ) ;
return V_33 ;
}
static int F_101 ( int V_254 , int V_28 , const char * V_236 )
{
unsigned long V_34 = V_28 ? V_255 : V_256 ;
int V_33 ;
if ( ! F_53 ( V_254 ) )
return 0 ;
V_33 = F_102 ( V_254 , V_34 , V_236 ) ;
if ( ! V_33 )
F_103 ( V_254 , 0 ) ;
return V_33 ;
}
static void F_104 ( struct V_5 * V_5 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_5 -> V_159 ) ; V_11 ++ ) {
if ( ! F_53 ( V_5 -> V_159 [ V_11 ] . V_159 ) )
continue;
F_105 ( V_5 -> V_159 [ V_11 ] . V_159 ) ;
V_5 -> V_159 [ V_11 ] . V_159 = - V_57 ;
}
}
static int F_106 ( struct V_5 * V_5 ,
const struct V_257 * V_258 )
{
const struct V_259 * V_159 = & V_258 -> V_260 ;
int V_33 ;
V_5 -> V_159 [ V_163 ] . V_159 = - V_57 ;
V_5 -> V_159 [ V_165 ] . V_159 = - V_57 ;
V_33 = F_101 ( V_159 -> V_159 , V_159 -> V_160 , L_14 ) ;
if ( V_33 ) {
F_104 ( V_5 ) ;
return V_33 ;
}
V_5 -> V_159 [ V_163 ] = * V_159 ;
if ( F_53 ( V_159 -> V_159 ) )
F_54 ( V_159 -> V_159 , 0 ) ;
V_159 = & V_258 -> V_261 ;
V_33 = F_101 ( V_159 -> V_159 , V_159 -> V_160 , L_15 ) ;
if ( V_33 ) {
F_104 ( V_5 ) ;
return V_33 ;
}
V_5 -> V_159 [ V_165 ] = * V_159 ;
if ( F_53 ( V_159 -> V_159 ) )
F_54 ( V_159 -> V_159 , 0 ) ;
return 0 ;
}
static int F_107 ( struct V_25 * V_26 ,
const struct V_262 * V_113 )
{
const struct V_257 * V_258 = V_26 -> V_263 . V_264 ;
struct V_1 * V_7 ;
struct V_5 * V_5 ;
int V_11 , V_33 ;
if ( V_258 == NULL ) {
F_108 ( & V_26 -> V_263 , L_16 ) ;
return - V_57 ;
}
if ( V_258 -> V_53 == 0 ) {
F_108 ( & V_26 -> V_263 , L_17 ) ;
return - V_57 ;
}
V_5 = F_109 ( & V_26 -> V_263 , sizeof( * V_5 ) , V_265 ) ;
if ( ! V_5 )
return - V_266 ;
F_110 ( & V_5 -> V_168 ) ;
V_5 -> V_53 = V_258 -> V_53 ;
V_5 -> V_133 = V_258 -> V_133 ;
V_5 -> V_156 = V_258 -> V_134 ;
V_5 -> V_164 = V_258 -> V_267 ;
V_5 -> V_73 = V_258 -> V_69 ;
V_5 -> V_71 = V_258 -> V_268 ;
V_7 = & V_5 -> V_7 ;
F_111 ( V_7 , V_26 , & V_269 ) ;
F_112 ( V_7 -> V_236 , V_270 , sizeof( V_7 -> V_236 ) ) ;
V_7 -> V_271 = & V_272 ;
V_7 -> V_34 |= V_273 ;
V_5 -> V_214 . V_34 = V_274 ;
V_7 -> V_275 . type = V_276 ;
V_33 = F_113 ( & V_7 -> V_275 , 1 , & V_5 -> V_214 , 0 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_106 ( V_5 , V_258 ) ;
if ( V_33 )
goto V_277;
for ( V_11 = 0 ; V_11 < V_161 ; V_11 ++ )
V_5 -> V_162 [ V_11 ] . V_278 = V_279 [ V_11 ] ;
V_33 = F_114 ( & V_26 -> V_263 , V_161 ,
V_5 -> V_162 ) ;
if ( V_33 ) {
F_108 ( & V_26 -> V_263 , L_18 ) ;
goto V_280;
}
V_33 = F_88 ( V_5 ) ;
if ( V_33 )
goto V_280;
F_4 ( V_5 ) ;
V_5 -> V_123 . V_14 = V_191 ;
V_5 -> V_123 . V_16 = V_193 ;
V_5 -> V_123 . V_127 = 0 ;
V_5 -> V_123 . V_129 = 0 ;
return 0 ;
V_280:
F_104 ( V_5 ) ;
V_277:
F_115 ( & V_5 -> V_7 . V_275 ) ;
return V_33 ;
}
static int F_116 ( struct V_25 * V_26 )
{
struct V_1 * V_7 = F_117 ( V_26 ) ;
struct V_5 * V_5 = F_3 ( V_7 ) ;
F_118 ( V_7 ) ;
F_95 ( V_7 -> V_170 ) ;
F_115 ( & V_7 -> V_275 ) ;
F_104 ( V_5 ) ;
return 0 ;
}
