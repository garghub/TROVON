static unsigned int F_1 ( struct V_1 * V_1 ,
unsigned int V_2 , unsigned int V_3 )
{
unsigned int V_4 , V_5 ;
if ( V_3 == 0 )
return V_6 ;
if ( V_1 -> V_7 . V_8 == 0 )
return 0 ;
V_4 = V_2 % V_1 -> V_7 . V_8 ;
V_5 = V_1 -> V_7 . V_5 ;
for (; ; ) {
unsigned int V_9 = V_5 ^ ( V_5 & ( V_5 - 1 ) ) ;
if ( V_4 == 0 )
return V_9 ;
V_4 -- ;
V_5 &= ~ V_9 ;
}
}
static void F_2 ( struct V_10 * V_11 )
{
if ( ! F_3 ( V_11 ) )
F_4 ( V_11 , L_1 ) ;
else {
static const char * V_12 [] = { L_2 , L_3 , L_4 , L_5 } ;
const char * V_13 = L_6 ;
const struct V_14 * V_15 = F_5 ( V_11 ) ;
switch ( V_15 -> V_16 . V_17 ) {
case V_18 :
V_13 = L_7 ;
break;
case V_19 :
V_13 = L_8 ;
break;
case V_20 :
V_13 = L_9 ;
break;
}
F_4 ( V_11 , L_10 , V_13 ,
V_12 [ V_15 -> V_16 . V_12 ] ) ;
}
}
void F_6 ( struct V_1 * V_1 , int V_21 , int V_22 )
{
struct V_10 * V_11 = V_1 -> V_23 [ V_21 ] ;
if ( F_7 ( V_11 ) && V_22 != F_3 ( V_11 ) ) {
if ( V_22 )
F_8 ( V_11 ) ;
else
F_9 ( V_11 ) ;
F_2 ( V_11 ) ;
}
}
void F_10 ( const struct V_1 * V_24 , int V_21 )
{
static const char * V_25 [] = {
NULL , L_11 , L_12 , L_13 , L_14 , L_15 , L_16
} ;
const struct V_10 * V_11 = V_24 -> V_23 [ V_21 ] ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_26 -> V_27 == V_28 )
F_4 ( V_11 , L_17 ) ;
else if ( V_26 -> V_27 < F_11 ( V_25 ) )
F_4 ( V_11 , L_18 , V_25 [ V_26 -> V_27 ] ) ;
}
static int F_12 ( const struct V_10 * V_11 , bool V_29 )
{
T_1 V_30 = 0 ;
T_1 V_31 = 0 ;
bool free = true ;
T_2 V_32 [ 7 ] ;
const T_3 * V_33 [ 7 ] ;
int V_34 , V_35 = 0 ;
const struct V_36 * V_37 ;
int V_38 = F_13 ( V_11 ) ;
int V_39 = F_14 ( V_11 ) ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
unsigned int V_40 = V_26 -> V_1 -> V_41 ;
F_15 (ha, dev) {
V_33 [ V_35 ++ ] = V_37 -> V_33 ;
if ( -- V_38 == 0 || V_35 >= F_11 ( V_33 ) ) {
V_34 = F_16 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , free ,
V_35 , V_33 , V_32 , & V_31 , V_29 ) ;
if ( V_34 < 0 )
return V_34 ;
free = false ;
V_35 = 0 ;
}
}
F_17 (ha, dev) {
V_33 [ V_35 ++ ] = V_37 -> V_33 ;
if ( -- V_39 == 0 || V_35 >= F_11 ( V_33 ) ) {
V_34 = F_16 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , free ,
V_35 , V_33 , V_32 , & V_30 , V_29 ) ;
if ( V_34 < 0 )
return V_34 ;
free = false ;
V_35 = 0 ;
}
}
return F_18 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , V_31 != 0 ,
V_31 | V_30 , V_29 ) ;
}
static int F_19 ( struct V_10 * V_11 , int V_43 , bool V_44 )
{
int V_34 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
V_34 = F_12 ( V_11 , V_44 ) ;
if ( V_34 == 0 )
V_34 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , V_43 ,
( V_11 -> V_45 & V_46 ) ? 1 : 0 ,
( V_11 -> V_45 & V_47 ) ? 1 : 0 , 1 , - 1 ,
V_44 ) ;
return V_34 ;
}
static int F_21 ( struct V_10 * V_11 )
{
int V_34 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
unsigned int V_40 = V_26 -> V_1 -> V_41 ;
V_34 = F_20 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , V_11 -> V_43 , - 1 , - 1 , - 1 ,
! ! ( V_11 -> V_48 & V_49 ) , true ) ;
if ( V_34 == 0 ) {
V_34 = F_22 ( V_26 -> V_1 , V_40 , V_26 -> V_42 ,
V_26 -> V_50 , V_11 -> V_51 , true ,
true ) ;
if ( V_34 >= 0 ) {
V_26 -> V_50 = V_34 ;
V_34 = 0 ;
}
}
if ( V_34 == 0 )
V_34 = F_23 ( V_26 -> V_1 , V_40 , V_26 -> V_52 ,
& V_26 -> V_16 ) ;
if ( V_34 == 0 )
V_34 = F_24 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , true , true ) ;
return V_34 ;
}
static void F_25 ( struct V_1 * V_24 , struct V_53 * V_54 )
{
if ( V_54 -> V_55 )
F_26 ( V_54 -> V_55 ) ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
}
static void F_27 ( struct V_1 * V_24 , const struct V_56 * V_57 )
{
unsigned int V_58 = F_28 ( V_57 ) ;
unsigned int V_59 = V_58 - V_24 -> V_60 . V_61 ;
unsigned int V_34 ;
struct V_53 * V_54 ;
if ( V_58 >= V_24 -> V_60 . V_61 && V_59 <
( V_24 -> V_60 . V_62 + V_24 -> V_60 . V_63 ) ) {
V_58 = V_59 ;
V_34 = F_29 ( V_57 -> V_64 ) ;
V_54 = & V_24 -> V_60 . V_65 [ V_58 ] ;
if ( V_34 == V_66 ) {
F_25 ( V_24 , V_54 ) ;
} else if ( V_34 == V_67 ) {
F_30 ( V_24 -> V_68 , L_19 ,
V_58 ) ;
F_25 ( V_24 , V_54 ) ;
} else if ( V_34 == V_69 ) {
V_54 -> V_70 = ( F_31 ( V_57 -> V_71 ) >> 24 ) & 0xff ;
V_54 -> V_72 = 0 ;
V_54 -> V_73 = 1 ;
} else {
F_30 ( V_24 -> V_68 , L_20 ,
V_58 , V_34 ) ;
F_25 ( V_24 , V_54 ) ;
}
}
}
static int F_32 ( struct V_74 * V_75 , const T_4 * V_76 ,
const struct V_77 * V_78 )
{
T_3 V_79 = ( ( const struct V_80 * ) V_76 ) -> V_79 ;
V_76 ++ ;
if ( F_33 ( V_79 == V_81 ) ) {
const struct V_82 * V_15 = ( void * ) V_76 ;
unsigned int V_83 = F_34 ( F_35 ( V_15 -> V_84 ) ) ;
struct V_85 * V_86 ;
V_86 = V_75 -> V_24 -> V_87 . V_88 [ V_83 - V_75 -> V_24 -> V_87 . V_89 ] ;
V_86 -> V_90 ++ ;
if ( ( T_3 * ) V_86 < ( T_3 * ) V_75 -> V_24 -> V_87 . V_91 ) {
struct V_92 * V_93 ;
V_93 = F_36 ( V_86 , struct V_92 , V_75 ) ;
F_37 ( V_93 -> V_86 ) ;
} else {
struct V_94 * V_95 ;
V_95 = F_36 ( V_86 , struct V_94 , V_75 ) ;
F_38 ( & V_95 -> V_96 ) ;
}
} else if ( V_79 == V_97 || V_79 == V_98 ) {
const struct V_99 * V_15 = ( void * ) V_76 ;
if ( V_15 -> type == 0 )
F_39 ( V_75 -> V_24 , V_15 -> V_100 ) ;
} else if ( V_79 == V_101 ) {
const struct V_102 * V_15 = ( void * ) V_76 ;
F_40 ( V_75 -> V_24 , V_15 ) ;
} else if ( V_79 == V_103 ) {
const struct V_56 * V_15 = ( void * ) V_76 ;
F_27 ( V_75 -> V_24 , V_15 ) ;
} else
F_30 ( V_75 -> V_24 -> V_68 ,
L_21 , V_79 ) ;
return 0 ;
}
static int F_41 ( struct V_74 * V_75 , const T_4 * V_76 ,
const struct V_77 * V_78 )
{
struct V_104 * V_105 = F_36 ( V_75 , struct V_104 , V_106 ) ;
if ( V_107 [ V_75 -> V_108 ] . F_42 ( V_75 -> V_24 -> V_109 [ V_75 -> V_108 ] , V_76 , V_78 ) ) {
V_105 -> V_110 . V_111 ++ ;
return - 1 ;
}
if ( V_78 == NULL )
V_105 -> V_110 . V_112 ++ ;
else if ( V_78 == V_113 )
V_105 -> V_110 . V_114 ++ ;
else
V_105 -> V_110 . V_115 ++ ;
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
if ( V_1 -> V_45 & V_116 ) {
F_44 ( V_1 -> V_117 ) ;
V_1 -> V_45 &= ~ V_116 ;
} else if ( V_1 -> V_45 & V_118 ) {
F_45 ( V_1 -> V_117 ) ;
V_1 -> V_45 &= ~ V_118 ;
}
}
static T_5 F_46 ( int V_119 , void * V_64 )
{
struct V_1 * V_24 = V_64 ;
T_6 V_120 = F_47 ( V_24 , F_48 ( V_121 ) ) ;
if ( V_120 & V_122 ) {
V_24 -> V_123 = 1 ;
F_49 ( V_24 , F_48 ( V_121 ) , V_120 ) ;
}
F_50 ( V_24 ) ;
return V_124 ;
}
static void F_51 ( struct V_1 * V_24 )
{
int V_125 , V_126 , V_127 = 2 , V_128 = sizeof( V_24 -> V_129 [ 0 ] . V_130 ) ;
snprintf ( V_24 -> V_129 [ 0 ] . V_130 , V_128 , L_22 , V_24 -> V_23 [ 0 ] -> V_131 ) ;
snprintf ( V_24 -> V_129 [ 1 ] . V_130 , V_128 , L_23 ,
V_24 -> V_23 [ 0 ] -> V_131 ) ;
F_52 (adap, j) {
struct V_10 * V_132 = V_24 -> V_23 [ V_126 ] ;
const struct V_14 * V_26 = F_5 ( V_132 ) ;
for ( V_125 = 0 ; V_125 < V_26 -> V_133 ; V_125 ++ , V_127 ++ )
snprintf ( V_24 -> V_129 [ V_127 ] . V_130 , V_128 , L_24 ,
V_132 -> V_131 , V_125 ) ;
}
F_53 (&adap->sge, i)
snprintf ( V_24 -> V_129 [ V_127 ++ ] . V_130 , V_128 , L_25 ,
V_24 -> V_23 [ 0 ] -> V_131 , V_125 ) ;
F_54 (&adap->sge, i)
snprintf ( V_24 -> V_129 [ V_127 ++ ] . V_130 , V_128 , L_26 ,
V_24 -> V_23 [ 0 ] -> V_131 , V_125 ) ;
}
static int F_55 ( struct V_1 * V_24 )
{
struct V_87 * V_13 = & V_24 -> V_87 ;
int V_134 , V_135 , V_136 = 0 , V_137 = 0 , V_138 = 2 ;
V_134 = F_56 ( V_24 -> V_129 [ 1 ] . V_139 , V_140 , 0 ,
V_24 -> V_129 [ 1 ] . V_130 , & V_13 -> V_141 ) ;
if ( V_134 )
return V_134 ;
F_57 (s, ethqidx) {
V_134 = F_56 ( V_24 -> V_129 [ V_138 ] . V_139 ,
V_140 , 0 ,
V_24 -> V_129 [ V_138 ] . V_130 ,
& V_13 -> V_142 [ V_135 ] . V_106 ) ;
if ( V_134 )
goto V_143;
V_138 ++ ;
}
F_53 (s, ofldqidx) {
V_134 = F_56 ( V_24 -> V_129 [ V_138 ] . V_139 ,
V_140 , 0 ,
V_24 -> V_129 [ V_138 ] . V_130 ,
& V_13 -> V_144 [ V_136 ] . V_106 ) ;
if ( V_134 )
goto V_143;
V_138 ++ ;
}
F_54 (s, rdmaqidx) {
V_134 = F_56 ( V_24 -> V_129 [ V_138 ] . V_139 ,
V_140 , 0 ,
V_24 -> V_129 [ V_138 ] . V_130 ,
& V_13 -> V_145 [ V_137 ] . V_106 ) ;
if ( V_134 )
goto V_143;
V_138 ++ ;
}
return 0 ;
V_143:
while ( -- V_137 >= 0 )
F_58 ( V_24 -> V_129 [ -- V_138 ] . V_139 ,
& V_13 -> V_145 [ V_137 ] . V_106 ) ;
while ( -- V_136 >= 0 )
F_58 ( V_24 -> V_129 [ -- V_138 ] . V_139 ,
& V_13 -> V_144 [ V_136 ] . V_106 ) ;
while ( -- V_135 >= 0 )
F_58 ( V_24 -> V_129 [ -- V_138 ] . V_139 ,
& V_13 -> V_142 [ V_135 ] . V_106 ) ;
F_58 ( V_24 -> V_129 [ 1 ] . V_139 , & V_13 -> V_141 ) ;
return V_134 ;
}
static void F_59 ( struct V_1 * V_24 )
{
int V_125 , V_138 = 2 ;
struct V_87 * V_13 = & V_24 -> V_87 ;
F_58 ( V_24 -> V_129 [ 1 ] . V_139 , & V_13 -> V_141 ) ;
F_57 (s, i)
F_58 ( V_24 -> V_129 [ V_138 ++ ] . V_139 , & V_13 -> V_142 [ V_125 ] . V_106 ) ;
F_53 (s, i)
F_58 ( V_24 -> V_129 [ V_138 ++ ] . V_139 , & V_13 -> V_144 [ V_125 ] . V_106 ) ;
F_54 (s, i)
F_58 ( V_24 -> V_129 [ V_138 ++ ] . V_139 , & V_13 -> V_145 [ V_125 ] . V_106 ) ;
}
static int F_60 ( const struct V_14 * V_26 , const T_2 * V_146 )
{
T_2 * V_147 ;
int V_125 , V_134 ;
const struct V_148 * V_75 = & V_26 -> V_1 -> V_87 . V_142 [ V_26 -> V_149 ] ;
V_147 = F_61 ( V_26 -> V_150 * sizeof( T_2 ) , V_151 ) ;
if ( ! V_147 )
return - V_152 ;
for ( V_125 = 0 ; V_125 < V_26 -> V_150 ; V_125 ++ , V_146 ++ )
V_147 [ V_125 ] = V_75 [ * V_146 ] . V_106 . V_153 ;
V_134 = F_62 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , 0 ,
V_26 -> V_150 , V_147 , V_26 -> V_150 ) ;
F_63 ( V_147 ) ;
return V_134 ;
}
static int F_64 ( struct V_1 * V_24 )
{
int V_125 , V_134 ;
F_52 (adap, i) {
const struct V_14 * V_26 = F_65 ( V_24 , V_125 ) ;
V_134 = F_60 ( V_26 , V_26 -> V_147 ) ;
if ( V_134 )
return V_134 ;
}
return 0 ;
}
static unsigned int F_66 ( const struct V_87 * V_15 , unsigned int V_83 )
{
V_83 -= V_15 -> V_154 ;
return F_67 ( V_15 -> V_155 [ V_83 ] -> V_156 ) -> V_52 ;
}
static void F_68 ( struct V_1 * V_24 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < F_11 ( V_24 -> V_87 . V_155 ) ; V_125 ++ ) {
struct V_74 * V_75 = V_24 -> V_87 . V_155 [ V_125 ] ;
if ( V_75 && V_75 -> V_157 )
F_69 ( & V_75 -> V_158 ) ;
}
}
static void F_70 ( struct V_1 * V_24 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < F_11 ( V_24 -> V_87 . V_155 ) ; V_125 ++ ) {
struct V_74 * V_75 = V_24 -> V_87 . V_155 [ V_125 ] ;
if ( ! V_75 )
continue;
if ( V_75 -> V_157 )
F_71 ( & V_75 -> V_158 ) ;
F_49 ( V_24 , F_48 ( V_159 ) ,
F_72 ( V_75 -> V_160 ) |
F_73 ( V_75 -> V_161 ) ) ;
}
}
static int F_74 ( struct V_1 * V_24 )
{
int V_134 , V_127 , V_125 , V_126 ;
struct V_87 * V_13 = & V_24 -> V_87 ;
F_75 ( V_13 -> V_162 , V_163 ) ;
F_75 ( V_13 -> V_164 , V_163 ) ;
if ( V_24 -> V_45 & V_116 )
V_127 = 1 ;
else {
V_134 = F_76 ( V_24 , & V_13 -> V_165 , false , V_24 -> V_23 [ 0 ] , 0 ,
NULL , NULL ) ;
if ( V_134 )
return V_134 ;
V_127 = - ( ( int ) V_13 -> V_165 . V_153 + 1 ) ;
}
V_134 = F_76 ( V_24 , & V_13 -> V_141 , true , V_24 -> V_23 [ 0 ] ,
V_127 , NULL , F_32 ) ;
if ( V_134 ) {
V_166: F_77 ( V_24 ) ;
return V_134 ;
}
F_52 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_125 ] ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_148 * V_75 = & V_13 -> V_142 [ V_26 -> V_149 ] ;
struct V_92 * V_167 = & V_13 -> V_168 [ V_26 -> V_149 ] ;
for ( V_126 = 0 ; V_126 < V_26 -> V_133 ; V_126 ++ , V_75 ++ ) {
if ( V_127 > 0 )
V_127 ++ ;
V_134 = F_76 ( V_24 , & V_75 -> V_106 , false , V_11 ,
V_127 , & V_75 -> V_169 ,
V_170 ) ;
if ( V_134 )
goto V_166;
V_75 -> V_106 . V_58 = V_126 ;
memset ( & V_75 -> V_110 , 0 , sizeof( V_75 -> V_110 ) ) ;
}
for ( V_126 = 0 ; V_126 < V_26 -> V_133 ; V_126 ++ , V_167 ++ ) {
V_134 = F_78 ( V_24 , V_167 , V_11 ,
F_79 ( V_11 , V_126 ) ,
V_13 -> V_141 . V_161 ) ;
if ( V_134 )
goto V_166;
}
}
V_126 = V_13 -> V_171 / V_24 -> V_7 . V_8 ;
F_53 (s, i) {
struct V_104 * V_75 = & V_13 -> V_144 [ V_125 ] ;
struct V_10 * V_11 = V_24 -> V_23 [ V_125 / V_126 ] ;
if ( V_127 > 0 )
V_127 ++ ;
V_134 = F_76 ( V_24 , & V_75 -> V_106 , false , V_11 , V_127 ,
& V_75 -> V_169 , F_41 ) ;
if ( V_134 )
goto V_166;
memset ( & V_75 -> V_110 , 0 , sizeof( V_75 -> V_110 ) ) ;
V_13 -> V_172 [ V_125 ] = V_75 -> V_106 . V_153 ;
V_134 = F_80 ( V_24 , & V_13 -> V_91 [ V_125 ] , V_11 ,
V_13 -> V_141 . V_161 ) ;
if ( V_134 )
goto V_166;
}
F_54 (s, i) {
struct V_104 * V_75 = & V_13 -> V_145 [ V_125 ] ;
if ( V_127 > 0 )
V_127 ++ ;
V_134 = F_76 ( V_24 , & V_75 -> V_106 , false , V_24 -> V_23 [ V_125 ] ,
V_127 , & V_75 -> V_169 , F_41 ) ;
if ( V_134 )
goto V_166;
memset ( & V_75 -> V_110 , 0 , sizeof( V_75 -> V_110 ) ) ;
V_13 -> V_173 [ V_125 ] = V_75 -> V_106 . V_153 ;
}
F_52 (adap, i) {
V_134 = F_81 ( V_24 , & V_13 -> V_174 [ V_125 ] , V_24 -> V_23 [ V_125 ] ,
V_13 -> V_141 . V_161 ,
V_13 -> V_145 [ V_125 ] . V_106 . V_161 ) ;
if ( V_134 )
goto V_166;
}
F_49 ( V_24 , V_175 ,
F_82 ( F_67 ( V_24 -> V_23 [ 0 ] ) -> V_52 ) |
F_83 ( V_13 -> V_142 [ 0 ] . V_106 . V_153 ) ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_24 )
{
int V_34 ;
T_6 V_176 ;
const struct V_177 * V_178 ;
const struct V_179 * V_180 ;
struct V_181 * V_11 = V_24 -> V_68 ;
V_34 = F_85 ( & V_180 , V_182 , V_11 ) ;
if ( V_34 < 0 ) {
F_30 ( V_11 , L_27 V_182
L_28 , V_34 ) ;
return V_34 ;
}
V_178 = ( const struct V_177 * ) V_180 -> V_100 ;
V_176 = F_35 ( V_178 -> V_183 ) ;
if ( F_86 ( V_176 ) != V_184 ) {
V_34 = - V_185 ;
goto V_186;
}
if ( F_86 ( V_24 -> V_7 . V_187 ) != V_184 ||
V_176 > V_24 -> V_7 . V_187 ) {
F_87 ( V_11 , L_29 ) ;
V_34 = F_88 ( V_24 , V_24 -> V_188 , V_180 -> V_100 , V_180 -> V_189 ,
false ) ;
if ( ! V_34 )
F_87 ( V_11 , L_30
V_182 L_31 ,
F_86 ( V_176 ) ,
F_89 ( V_176 ) ,
F_90 ( V_176 ) ,
F_91 ( V_176 ) ) ;
else
F_30 ( V_11 , L_32 , - V_34 ) ;
} else {
V_34 = - V_185 ;
}
V_186: F_92 ( V_180 ) ;
return V_34 ;
}
void * F_93 ( T_7 V_189 )
{
void * V_15 = F_94 ( V_189 , V_151 ) ;
if ( ! V_15 )
V_15 = F_95 ( V_189 ) ;
return V_15 ;
}
static void F_96 ( void * V_33 )
{
if ( F_97 ( V_33 ) )
F_98 ( V_33 ) ;
else
F_63 ( V_33 ) ;
}
static int F_99 ( struct V_1 * V_1 , int V_190 )
{
struct V_53 * V_54 = & V_1 -> V_60 . V_65 [ V_190 ] ;
struct V_191 * V_192 ;
struct V_193 * V_194 ;
unsigned int V_195 ;
if ( V_54 -> V_196 . V_197 || V_54 -> V_196 . V_198 ) {
V_54 -> V_55 = F_100 ( V_1 -> V_55 ) ;
if ( V_54 -> V_55 == NULL )
return - V_199 ;
if ( F_101 ( V_1 , V_54 -> V_55 , V_54 -> V_196 . V_200 ,
V_54 -> V_196 . V_201 , V_54 -> V_196 . V_202 ) ) {
F_26 ( V_54 -> V_55 ) ;
V_54 -> V_55 = NULL ;
return - V_152 ;
}
}
V_195 = V_1 -> V_60 . V_61 + V_190 ;
V_192 = F_102 ( sizeof( * V_194 ) , V_151 | V_203 ) ;
V_194 = (struct V_193 * ) F_103 ( V_192 , sizeof( * V_194 ) ) ;
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
V_194 -> V_204 = F_104 ( F_105 ( V_205 ) ) ;
V_194 -> V_206 = F_104 ( F_106 ( sizeof( * V_194 ) / 16 ) ) ;
V_194 -> V_207 =
F_104 ( F_107 ( V_195 ) |
F_108 ( V_54 -> V_196 . type ) |
F_109 ( 0 ) |
F_110 ( V_54 -> V_196 . V_208 ) ) ;
V_194 -> V_209 =
F_104 ( F_111 ( V_54 -> V_196 . V_210 ) |
F_112 ( V_54 -> V_196 . V_211 == V_212 ) |
F_113 ( V_54 -> V_196 . V_213 ) |
F_114 ( V_54 -> V_196 . V_214 ) |
F_115 ( V_54 -> V_196 . V_215 ) |
F_116 ( V_54 -> V_196 . V_211 == V_216 ) |
F_117 ( V_54 -> V_196 . V_197 ) |
F_118 ( V_54 -> V_196 . V_217 ) |
F_119 ( V_54 -> V_196 . V_198 == V_218 ||
V_54 -> V_196 . V_198 == V_219 ) |
F_120 ( V_54 -> V_196 . V_198 == V_220 ||
V_54 -> V_196 . V_198 == V_219 ) |
F_121 ( V_54 -> V_196 . V_221 ) |
F_122 ( V_54 -> V_196 . V_201 ) |
F_123 ( V_54 -> V_196 . V_222 ) |
F_124 ( V_54 -> V_55 ? V_54 -> V_55 -> V_58 : 0 ) ) ;
V_194 -> V_223 = F_125 ( V_54 -> V_196 . V_224 . V_223 ) ;
V_194 -> V_225 = F_125 ( V_54 -> V_196 . V_226 . V_223 ) ;
V_194 -> V_227 =
( F_126 ( V_54 -> V_196 . V_224 . V_228 ) |
F_127 ( V_54 -> V_196 . V_226 . V_228 ) |
F_128 ( V_54 -> V_196 . V_224 . V_229 ) |
F_129 ( V_54 -> V_196 . V_224 . V_230 ) |
F_130 ( V_54 -> V_196 . V_226 . V_229 ) |
F_131 ( V_54 -> V_196 . V_226 . V_230 ) ) ;
V_194 -> V_231 = 0 ;
V_194 -> V_232 =
F_125 ( F_132 ( 0 ) |
F_133 ( V_1 -> V_87 . V_141 . V_153 ) ) ;
V_194 -> V_233 =
F_104 ( F_134 ( V_54 -> V_196 . V_224 . V_234 ) |
F_135 ( V_54 -> V_196 . V_226 . V_234 ) |
F_136 ( V_54 -> V_196 . V_224 . V_235 ) |
F_137 ( V_54 -> V_196 . V_226 . V_235 ) |
F_138 ( V_54 -> V_196 . V_224 . V_236 ) |
F_139 ( V_54 -> V_196 . V_226 . V_236 ) |
F_140 ( V_54 -> V_196 . V_224 . V_237 ) |
F_141 ( V_54 -> V_196 . V_226 . V_237 ) ) ;
V_194 -> V_238 = V_54 -> V_196 . V_224 . V_239 ;
V_194 -> V_240 = V_54 -> V_196 . V_226 . V_239 ;
V_194 -> V_241 = V_54 -> V_196 . V_224 . V_242 ;
V_194 -> V_243 = V_54 -> V_196 . V_226 . V_242 ;
V_194 -> V_244 = F_125 ( V_54 -> V_196 . V_224 . V_244 ) ;
V_194 -> V_245 = F_125 ( V_54 -> V_196 . V_226 . V_244 ) ;
V_194 -> V_246 = F_125 ( V_54 -> V_196 . V_224 . V_246 ) ;
V_194 -> V_247 = F_125 ( V_54 -> V_196 . V_226 . V_246 ) ;
memcpy ( V_194 -> V_248 , V_54 -> V_196 . V_224 . V_248 , sizeof( V_194 -> V_248 ) ) ;
memcpy ( V_194 -> V_249 , V_54 -> V_196 . V_226 . V_248 , sizeof( V_194 -> V_249 ) ) ;
memcpy ( V_194 -> V_250 , V_54 -> V_196 . V_224 . V_250 , sizeof( V_194 -> V_250 ) ) ;
memcpy ( V_194 -> V_251 , V_54 -> V_196 . V_226 . V_250 , sizeof( V_194 -> V_251 ) ) ;
V_194 -> V_252 = F_125 ( V_54 -> V_196 . V_224 . V_253 ) ;
V_194 -> V_254 = F_125 ( V_54 -> V_196 . V_226 . V_253 ) ;
V_194 -> V_255 = F_125 ( V_54 -> V_196 . V_224 . V_256 ) ;
V_194 -> V_257 = F_125 ( V_54 -> V_196 . V_226 . V_256 ) ;
if ( V_54 -> V_196 . V_217 )
memcpy ( V_194 -> V_258 , V_54 -> V_196 . V_259 , sizeof( V_194 -> V_258 ) ) ;
V_54 -> V_72 = 1 ;
F_142 ( V_192 , V_260 , V_54 -> V_196 . V_224 . V_236 & 0x3 ) ;
F_143 ( V_1 , V_192 ) ;
return 0 ;
}
static int F_144 ( struct V_1 * V_1 , int V_190 )
{
struct V_53 * V_54 = & V_1 -> V_60 . V_65 [ V_190 ] ;
struct V_191 * V_192 ;
struct V_193 * V_194 ;
unsigned int V_261 , V_195 ;
V_261 = sizeof( * V_194 ) ;
V_195 = V_1 -> V_60 . V_61 + V_190 ;
V_192 = F_102 ( V_261 , V_151 | V_203 ) ;
V_194 = (struct V_193 * ) F_103 ( V_192 , V_261 ) ;
F_145 ( V_195 , V_194 , V_1 -> V_87 . V_141 . V_153 ) ;
V_54 -> V_72 = 1 ;
F_146 ( V_1 , V_192 ) ;
return 0 ;
}
static inline int F_147 ( const struct V_1 * V_24 )
{
return V_24 -> V_7 . V_262 ;
}
static T_6 F_148 ( struct V_10 * V_11 )
{
return F_149 ( V_11 ) -> V_263 ;
}
static void F_150 ( struct V_10 * V_11 , T_6 V_224 )
{
F_149 ( V_11 ) -> V_263 = V_224 ;
}
static int F_151 ( struct V_10 * V_11 , int V_264 )
{
switch ( V_264 ) {
case V_265 :
return F_11 ( V_266 ) ;
default:
return - V_267 ;
}
}
static int F_152 ( struct V_10 * V_11 )
{
return V_268 ;
}
static int F_153 ( struct V_10 * V_11 )
{
return V_269 ;
}
static void F_154 ( struct V_10 * V_11 , struct V_270 * V_271 )
{
struct V_1 * V_1 = F_149 ( V_11 ) ;
F_155 ( V_271 -> V_272 , V_273 , sizeof( V_271 -> V_272 ) ) ;
F_155 ( V_271 -> V_274 , V_275 , sizeof( V_271 -> V_274 ) ) ;
F_155 ( V_271 -> V_276 , F_156 ( V_1 -> V_117 ) ,
sizeof( V_271 -> V_276 ) ) ;
if ( V_1 -> V_7 . V_187 )
snprintf ( V_271 -> V_277 , sizeof( V_271 -> V_277 ) ,
L_33 ,
F_86 ( V_1 -> V_7 . V_187 ) ,
F_89 ( V_1 -> V_7 . V_187 ) ,
F_90 ( V_1 -> V_7 . V_187 ) ,
F_91 ( V_1 -> V_7 . V_187 ) ,
F_86 ( V_1 -> V_7 . V_278 ) ,
F_89 ( V_1 -> V_7 . V_278 ) ,
F_90 ( V_1 -> V_7 . V_278 ) ,
F_91 ( V_1 -> V_7 . V_278 ) ) ;
}
static void F_157 ( struct V_10 * V_11 , T_6 V_279 , T_3 * V_100 )
{
if ( V_279 == V_265 )
memcpy ( V_100 , V_266 , sizeof( V_266 ) ) ;
}
static void F_158 ( const struct V_1 * V_24 ,
const struct V_14 * V_15 , struct V_280 * V_13 )
{
int V_125 ;
const struct V_92 * V_281 = & V_24 -> V_87 . V_168 [ V_15 -> V_149 ] ;
const struct V_148 * V_282 = & V_24 -> V_87 . V_142 [ V_15 -> V_149 ] ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
for ( V_125 = 0 ; V_125 < V_15 -> V_133 ; V_125 ++ , V_282 ++ , V_281 ++ ) {
V_13 -> V_283 += V_281 -> V_283 ;
V_13 -> V_284 += V_281 -> V_285 ;
V_13 -> V_286 += V_282 -> V_110 . V_287 ;
V_13 -> V_288 += V_282 -> V_110 . V_288 ;
V_13 -> V_289 += V_281 -> V_289 ;
V_13 -> V_290 += V_282 -> V_110 . V_291 ;
V_13 -> V_292 += V_282 -> V_110 . V_293 ;
}
}
static void F_159 ( struct V_10 * V_11 , struct V_294 * V_110 ,
T_1 * V_100 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_160 ( V_1 , V_26 -> V_52 , (struct V_295 * ) V_100 ) ;
V_100 += sizeof( struct V_295 ) / sizeof( T_1 ) ;
F_158 ( V_1 , V_26 , (struct V_280 * ) V_100 ) ;
}
static inline unsigned int F_161 ( const struct V_1 * V_296 )
{
return 4 | ( V_296 -> V_7 . V_297 << 10 ) | ( 1 << 16 ) ;
}
static void F_162 ( struct V_1 * V_296 , void * V_298 , unsigned int V_299 ,
unsigned int V_300 )
{
T_6 * V_15 = V_298 + V_299 ;
for ( ; V_299 <= V_300 ; V_299 += sizeof( T_6 ) )
* V_15 ++ = F_47 ( V_296 , V_299 ) ;
}
static void F_163 ( struct V_10 * V_11 , struct V_301 * V_302 ,
void * V_298 )
{
static const unsigned int V_303 [] = {
0x1008 , 0x1108 ,
0x1180 , 0x11b4 ,
0x11fc , 0x123c ,
0x1300 , 0x173c ,
0x1800 , 0x18fc ,
0x3000 , 0x30d8 ,
0x30e0 , 0x5924 ,
0x5960 , 0x59d4 ,
0x5a00 , 0x5af8 ,
0x6000 , 0x6098 ,
0x6100 , 0x6150 ,
0x6200 , 0x6208 ,
0x6240 , 0x6248 ,
0x6280 , 0x6338 ,
0x6370 , 0x638c ,
0x6400 , 0x643c ,
0x6500 , 0x6524 ,
0x6a00 , 0x6a38 ,
0x6a60 , 0x6a78 ,
0x6b00 , 0x6b84 ,
0x6bf0 , 0x6c84 ,
0x6cf0 , 0x6d84 ,
0x6df0 , 0x6e84 ,
0x6ef0 , 0x6f84 ,
0x6ff0 , 0x7084 ,
0x70f0 , 0x7184 ,
0x71f0 , 0x7284 ,
0x72f0 , 0x7384 ,
0x73f0 , 0x7450 ,
0x7500 , 0x7530 ,
0x7600 , 0x761c ,
0x7680 , 0x76cc ,
0x7700 , 0x7798 ,
0x77c0 , 0x77fc ,
0x7900 , 0x79fc ,
0x7b00 , 0x7c38 ,
0x7d00 , 0x7efc ,
0x8dc0 , 0x8e1c ,
0x8e30 , 0x8e78 ,
0x8ea0 , 0x8f6c ,
0x8fc0 , 0x9074 ,
0x90fc , 0x90fc ,
0x9400 , 0x9458 ,
0x9600 , 0x96bc ,
0x9800 , 0x9808 ,
0x9820 , 0x983c ,
0x9850 , 0x9864 ,
0x9c00 , 0x9c6c ,
0x9c80 , 0x9cec ,
0x9d00 , 0x9d6c ,
0x9d80 , 0x9dec ,
0x9e00 , 0x9e6c ,
0x9e80 , 0x9eec ,
0x9f00 , 0x9f6c ,
0x9f80 , 0x9fec ,
0xd004 , 0xd03c ,
0xdfc0 , 0xdfe0 ,
0xe000 , 0xea7c ,
0xf000 , 0x11190 ,
0x19040 , 0x1906c ,
0x19078 , 0x19080 ,
0x1908c , 0x19124 ,
0x19150 , 0x191b0 ,
0x191d0 , 0x191e8 ,
0x19238 , 0x1924c ,
0x193f8 , 0x19474 ,
0x19490 , 0x194f8 ,
0x19800 , 0x19f30 ,
0x1a000 , 0x1a06c ,
0x1a0b0 , 0x1a120 ,
0x1a128 , 0x1a138 ,
0x1a190 , 0x1a1c4 ,
0x1a1fc , 0x1a1fc ,
0x1e040 , 0x1e04c ,
0x1e284 , 0x1e28c ,
0x1e2c0 , 0x1e2c0 ,
0x1e2e0 , 0x1e2e0 ,
0x1e300 , 0x1e384 ,
0x1e3c0 , 0x1e3c8 ,
0x1e440 , 0x1e44c ,
0x1e684 , 0x1e68c ,
0x1e6c0 , 0x1e6c0 ,
0x1e6e0 , 0x1e6e0 ,
0x1e700 , 0x1e784 ,
0x1e7c0 , 0x1e7c8 ,
0x1e840 , 0x1e84c ,
0x1ea84 , 0x1ea8c ,
0x1eac0 , 0x1eac0 ,
0x1eae0 , 0x1eae0 ,
0x1eb00 , 0x1eb84 ,
0x1ebc0 , 0x1ebc8 ,
0x1ec40 , 0x1ec4c ,
0x1ee84 , 0x1ee8c ,
0x1eec0 , 0x1eec0 ,
0x1eee0 , 0x1eee0 ,
0x1ef00 , 0x1ef84 ,
0x1efc0 , 0x1efc8 ,
0x1f040 , 0x1f04c ,
0x1f284 , 0x1f28c ,
0x1f2c0 , 0x1f2c0 ,
0x1f2e0 , 0x1f2e0 ,
0x1f300 , 0x1f384 ,
0x1f3c0 , 0x1f3c8 ,
0x1f440 , 0x1f44c ,
0x1f684 , 0x1f68c ,
0x1f6c0 , 0x1f6c0 ,
0x1f6e0 , 0x1f6e0 ,
0x1f700 , 0x1f784 ,
0x1f7c0 , 0x1f7c8 ,
0x1f840 , 0x1f84c ,
0x1fa84 , 0x1fa8c ,
0x1fac0 , 0x1fac0 ,
0x1fae0 , 0x1fae0 ,
0x1fb00 , 0x1fb84 ,
0x1fbc0 , 0x1fbc8 ,
0x1fc40 , 0x1fc4c ,
0x1fe84 , 0x1fe8c ,
0x1fec0 , 0x1fec0 ,
0x1fee0 , 0x1fee0 ,
0x1ff00 , 0x1ff84 ,
0x1ffc0 , 0x1ffc8 ,
0x20000 , 0x2002c ,
0x20100 , 0x2013c ,
0x20190 , 0x201c8 ,
0x20200 , 0x20318 ,
0x20400 , 0x20528 ,
0x20540 , 0x20614 ,
0x21000 , 0x21040 ,
0x2104c , 0x21060 ,
0x210c0 , 0x210ec ,
0x21200 , 0x21268 ,
0x21270 , 0x21284 ,
0x212fc , 0x21388 ,
0x21400 , 0x21404 ,
0x21500 , 0x21518 ,
0x2152c , 0x2153c ,
0x21550 , 0x21554 ,
0x21600 , 0x21600 ,
0x21608 , 0x21628 ,
0x21630 , 0x2163c ,
0x21700 , 0x2171c ,
0x21780 , 0x2178c ,
0x21800 , 0x21c38 ,
0x21c80 , 0x21d7c ,
0x21e00 , 0x21e04 ,
0x22000 , 0x2202c ,
0x22100 , 0x2213c ,
0x22190 , 0x221c8 ,
0x22200 , 0x22318 ,
0x22400 , 0x22528 ,
0x22540 , 0x22614 ,
0x23000 , 0x23040 ,
0x2304c , 0x23060 ,
0x230c0 , 0x230ec ,
0x23200 , 0x23268 ,
0x23270 , 0x23284 ,
0x232fc , 0x23388 ,
0x23400 , 0x23404 ,
0x23500 , 0x23518 ,
0x2352c , 0x2353c ,
0x23550 , 0x23554 ,
0x23600 , 0x23600 ,
0x23608 , 0x23628 ,
0x23630 , 0x2363c ,
0x23700 , 0x2371c ,
0x23780 , 0x2378c ,
0x23800 , 0x23c38 ,
0x23c80 , 0x23d7c ,
0x23e00 , 0x23e04 ,
0x24000 , 0x2402c ,
0x24100 , 0x2413c ,
0x24190 , 0x241c8 ,
0x24200 , 0x24318 ,
0x24400 , 0x24528 ,
0x24540 , 0x24614 ,
0x25000 , 0x25040 ,
0x2504c , 0x25060 ,
0x250c0 , 0x250ec ,
0x25200 , 0x25268 ,
0x25270 , 0x25284 ,
0x252fc , 0x25388 ,
0x25400 , 0x25404 ,
0x25500 , 0x25518 ,
0x2552c , 0x2553c ,
0x25550 , 0x25554 ,
0x25600 , 0x25600 ,
0x25608 , 0x25628 ,
0x25630 , 0x2563c ,
0x25700 , 0x2571c ,
0x25780 , 0x2578c ,
0x25800 , 0x25c38 ,
0x25c80 , 0x25d7c ,
0x25e00 , 0x25e04 ,
0x26000 , 0x2602c ,
0x26100 , 0x2613c ,
0x26190 , 0x261c8 ,
0x26200 , 0x26318 ,
0x26400 , 0x26528 ,
0x26540 , 0x26614 ,
0x27000 , 0x27040 ,
0x2704c , 0x27060 ,
0x270c0 , 0x270ec ,
0x27200 , 0x27268 ,
0x27270 , 0x27284 ,
0x272fc , 0x27388 ,
0x27400 , 0x27404 ,
0x27500 , 0x27518 ,
0x2752c , 0x2753c ,
0x27550 , 0x27554 ,
0x27600 , 0x27600 ,
0x27608 , 0x27628 ,
0x27630 , 0x2763c ,
0x27700 , 0x2771c ,
0x27780 , 0x2778c ,
0x27800 , 0x27c38 ,
0x27c80 , 0x27d7c ,
0x27e00 , 0x27e04
} ;
int V_125 ;
struct V_1 * V_296 = F_149 ( V_11 ) ;
V_302 -> V_274 = F_161 ( V_296 ) ;
memset ( V_298 , 0 , V_268 ) ;
for ( V_125 = 0 ; V_125 < F_11 ( V_303 ) ; V_125 += 2 )
F_162 ( V_296 , V_298 , V_303 [ V_125 ] , V_303 [ V_125 + 1 ] ) ;
}
static int F_164 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
if ( ! F_7 ( V_11 ) )
return - V_199 ;
if ( V_15 -> V_16 . V_304 != V_305 )
return - V_185 ;
F_165 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ) ;
return 0 ;
}
static int F_166 ( struct V_10 * V_11 ,
enum V_306 V_307 )
{
unsigned int V_224 ;
struct V_1 * V_24 = F_149 ( V_11 ) ;
if ( V_307 == V_308 )
V_224 = 0xffff ;
else if ( V_307 == V_309 )
V_224 = 0 ;
else
return - V_185 ;
return F_167 ( V_24 , V_24 -> V_41 , F_67 ( V_11 ) -> V_42 , V_224 ) ;
}
static unsigned int F_168 ( unsigned int type , unsigned int V_310 )
{
unsigned int V_120 = 0 ;
if ( type == V_311 || type == V_312 ||
type == V_313 ) {
V_120 |= V_314 ;
if ( V_310 & V_315 )
V_120 |= V_316 ;
if ( V_310 & V_317 )
V_120 |= V_318 ;
if ( V_310 & V_319 )
V_120 |= V_320 ;
} else if ( type == V_321 || type == V_322 ) {
V_120 |= V_323 ;
if ( V_310 & V_317 )
V_120 |= V_324 ;
if ( V_310 & V_319 )
V_120 |= V_325 ;
} else if ( type == V_326 )
V_120 |= V_323 | V_327 ;
else if ( type == V_328 )
V_120 |= V_323 | V_329 |
V_327 | V_324 ;
else if ( type == V_330 )
V_120 |= V_323 | V_329 |
V_327 | V_324 |
V_325 ;
else if ( type == V_331 ||
type == V_332 || type == V_333 )
V_120 |= V_334 ;
if ( V_310 & V_335 )
V_120 |= V_336 ;
return V_120 ;
}
static unsigned int F_169 ( unsigned int V_310 )
{
unsigned int V_120 = 0 ;
if ( V_310 & V_337 )
V_120 |= V_315 ;
if ( V_310 & V_338 )
V_120 |= V_317 ;
if ( V_310 & V_339 )
V_120 |= V_319 ;
return V_120 ;
}
static int F_170 ( struct V_10 * V_11 , struct V_340 * V_341 )
{
const struct V_14 * V_15 = F_5 ( V_11 ) ;
if ( V_15 -> V_342 == V_311 ||
V_15 -> V_342 == V_312 ||
V_15 -> V_342 == V_313 )
V_341 -> V_23 = V_343 ;
else if ( V_15 -> V_342 == V_331 ||
V_15 -> V_342 == V_332 )
V_341 -> V_23 = V_344 ;
else if ( V_15 -> V_342 == V_333 ) {
if ( V_15 -> V_27 == V_345 ||
V_15 -> V_27 == V_346 )
V_341 -> V_23 = V_347 ;
else
V_341 -> V_23 = V_344 ;
} else
V_341 -> V_23 = V_348 ;
if ( V_15 -> V_349 >= 0 ) {
V_341 -> V_350 = V_15 -> V_349 ;
V_341 -> V_351 = V_352 ;
V_341 -> V_353 = V_15 -> V_342 == V_311 ?
V_354 : V_355 ;
} else {
V_341 -> V_350 = 0 ;
V_341 -> V_351 = V_356 ;
V_341 -> V_353 = 0 ;
}
V_341 -> V_357 = F_168 ( V_15 -> V_342 , V_15 -> V_16 . V_357 ) ;
V_341 -> V_358 = F_168 ( V_15 -> V_342 ,
V_15 -> V_16 . V_358 ) ;
F_171 ( V_341 ,
F_3 ( V_11 ) ? V_15 -> V_16 . V_17 : 0 ) ;
V_341 -> V_359 = V_360 ;
V_341 -> V_304 = V_15 -> V_16 . V_304 ;
V_341 -> V_361 = 0 ;
V_341 -> V_362 = 0 ;
return 0 ;
}
static unsigned int F_172 ( int V_17 )
{
if ( V_17 == V_20 )
return V_315 ;
if ( V_17 == V_19 )
return V_317 ;
if ( V_17 == V_18 )
return V_319 ;
return 0 ;
}
static int F_173 ( struct V_10 * V_11 , struct V_340 * V_341 )
{
unsigned int V_363 ;
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_364 * V_365 = & V_15 -> V_16 ;
T_6 V_17 = F_174 ( V_341 ) ;
if ( V_341 -> V_359 != V_360 )
return - V_185 ;
if ( ! ( V_365 -> V_357 & V_335 ) ) {
if ( V_341 -> V_304 == V_366 &&
( V_365 -> V_357 & F_172 ( V_17 ) ) )
return 0 ;
return - V_185 ;
}
if ( V_341 -> V_304 == V_366 ) {
V_363 = F_172 ( V_17 ) ;
if ( ! ( V_365 -> V_357 & V_363 ) || ( V_17 == V_19 ) ||
( V_17 == V_18 ) )
return - V_185 ;
V_365 -> V_367 = V_363 ;
V_365 -> V_358 = 0 ;
} else {
V_363 = F_169 ( V_341 -> V_358 ) ;
if ( ! ( V_365 -> V_357 & V_363 ) )
return - V_185 ;
V_365 -> V_367 = 0 ;
V_365 -> V_358 = V_363 | V_335 ;
}
V_365 -> V_304 = V_341 -> V_304 ;
if ( F_7 ( V_11 ) )
return F_23 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ,
V_365 ) ;
return 0 ;
}
static void F_175 ( struct V_10 * V_11 ,
struct V_368 * V_369 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
V_369 -> V_304 = ( V_15 -> V_16 . V_370 & V_371 ) != 0 ;
V_369 -> V_372 = ( V_15 -> V_16 . V_12 & V_373 ) != 0 ;
V_369 -> V_374 = ( V_15 -> V_16 . V_12 & V_375 ) != 0 ;
}
static int F_176 ( struct V_10 * V_11 ,
struct V_368 * V_369 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_364 * V_365 = & V_15 -> V_16 ;
if ( V_369 -> V_304 == V_366 )
V_365 -> V_370 = 0 ;
else if ( V_365 -> V_357 & V_335 )
V_365 -> V_370 = V_371 ;
else
return - V_185 ;
if ( V_369 -> V_372 )
V_365 -> V_370 |= V_373 ;
if ( V_369 -> V_374 )
V_365 -> V_370 |= V_375 ;
if ( F_7 ( V_11 ) )
return F_23 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ,
V_365 ) ;
return 0 ;
}
static void F_177 ( struct V_10 * V_11 , struct V_376 * V_377 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_87 * V_13 = & V_26 -> V_1 -> V_87 ;
V_377 -> V_378 = V_379 ;
V_377 -> V_380 = V_381 ;
V_377 -> V_382 = 0 ;
V_377 -> V_383 = V_384 ;
V_377 -> V_385 = V_13 -> V_142 [ V_26 -> V_149 ] . V_169 . V_189 - 8 ;
V_377 -> V_386 = V_13 -> V_142 [ V_26 -> V_149 ] . V_106 . V_189 ;
V_377 -> V_387 = 0 ;
V_377 -> V_388 = V_13 -> V_168 [ V_26 -> V_149 ] . V_75 . V_189 ;
}
static int F_178 ( struct V_10 * V_11 , struct V_376 * V_377 )
{
int V_125 ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
struct V_87 * V_13 = & V_1 -> V_87 ;
if ( V_377 -> V_385 > V_379 || V_377 -> V_387 ||
V_377 -> V_388 > V_384 ||
V_377 -> V_386 > V_381 ||
V_377 -> V_386 < V_389 ||
V_377 -> V_385 < V_390 || V_377 -> V_388 < V_391 )
return - V_185 ;
if ( V_1 -> V_45 & V_392 )
return - V_393 ;
for ( V_125 = 0 ; V_125 < V_26 -> V_133 ; ++ V_125 ) {
V_13 -> V_168 [ V_26 -> V_149 + V_125 ] . V_75 . V_189 = V_377 -> V_388 ;
V_13 -> V_142 [ V_26 -> V_149 + V_125 ] . V_169 . V_189 = V_377 -> V_385 + 8 ;
V_13 -> V_142 [ V_26 -> V_149 + V_125 ] . V_106 . V_189 = V_377 -> V_386 ;
}
return 0 ;
}
static int F_179 ( const struct V_87 * V_13 , int time )
{
int V_125 , V_394 , V_395 = 0 , V_396 = V_397 ;
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_398 ) ; V_125 ++ ) {
V_394 = time - V_13 -> V_398 [ V_125 ] ;
if ( V_394 < 0 )
V_394 = - V_394 ;
if ( V_394 < V_396 ) {
V_396 = V_394 ;
V_395 = V_125 ;
}
}
return V_395 ;
}
static int F_180 ( const struct V_87 * V_13 , int V_399 )
{
int V_125 , V_394 , V_395 = 0 , V_396 = V_397 ;
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_400 ) ; V_125 ++ ) {
V_394 = V_399 - V_13 -> V_400 [ V_125 ] ;
if ( V_394 < 0 )
V_394 = - V_394 ;
if ( V_394 < V_396 ) {
V_396 = V_394 ;
V_395 = V_125 ;
}
}
return V_395 ;
}
static unsigned int F_181 ( const struct V_1 * V_24 ,
const struct V_74 * V_75 )
{
unsigned int V_58 = V_75 -> V_160 >> 1 ;
return V_58 < V_401 ? V_24 -> V_87 . V_398 [ V_58 ] : 0 ;
}
static int F_182 ( struct V_1 * V_24 , struct V_74 * V_75 ,
unsigned int V_402 , unsigned int V_403 )
{
if ( ( V_402 | V_403 ) == 0 )
V_403 = 1 ;
if ( V_403 ) {
int V_134 ;
T_6 V_120 , V_404 ;
V_404 = F_180 ( & V_24 -> V_87 , V_403 ) ;
if ( V_75 -> V_130 && V_75 -> V_405 != V_404 ) {
V_120 = F_183 ( V_406 ) |
F_184 ( V_407 ) |
F_185 ( V_75 -> V_161 ) ;
V_134 = F_186 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 1 , & V_120 ,
& V_404 ) ;
if ( V_134 )
return V_134 ;
}
V_75 -> V_405 = V_404 ;
}
V_402 = V_402 == 0 ? 6 : F_179 ( & V_24 -> V_87 , V_402 ) ;
V_75 -> V_160 = F_187 ( V_402 ) | ( V_403 > 0 ? V_408 : 0 ) ;
return 0 ;
}
static int F_188 ( struct V_10 * V_11 , struct V_409 * V_410 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_24 = V_26 -> V_1 ;
struct V_74 * V_75 ;
int V_125 ;
int V_411 = 0 ;
for ( V_125 = V_26 -> V_149 ; V_125 < V_26 -> V_149 + V_26 -> V_133 ; V_125 ++ ) {
V_75 = & V_24 -> V_87 . V_142 [ V_125 ] . V_106 ;
V_411 = F_182 ( V_24 , V_75 , V_410 -> V_412 ,
V_410 -> V_413 ) ;
if ( V_411 ) {
F_30 ( & V_11 -> V_11 , L_34 , V_411 ) ;
break;
}
}
return V_411 ;
}
static int F_189 ( struct V_10 * V_11 , struct V_409 * V_410 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_1 * V_24 = V_26 -> V_1 ;
const struct V_74 * V_414 = & V_24 -> V_87 . V_142 [ V_26 -> V_149 ] . V_106 ;
V_410 -> V_412 = F_181 ( V_24 , V_414 ) ;
V_410 -> V_413 = ( V_414 -> V_160 & V_408 ) ?
V_24 -> V_87 . V_400 [ V_414 -> V_405 ] : 0 ;
return 0 ;
}
static int F_190 ( unsigned int V_415 , unsigned int V_41 , unsigned int V_416 )
{
V_41 *= V_416 ;
if ( V_415 < 1024 )
return V_415 + ( 31 << 10 ) ;
if ( V_415 < 1024 + V_41 )
return 31744 - V_41 + V_415 - 1024 ;
if ( V_415 < V_269 )
return V_415 - 1024 - V_41 ;
return - V_185 ;
}
static int F_191 ( struct V_1 * V_24 , unsigned int V_415 , T_6 * V_120 )
{
int V_417 = F_190 ( V_415 , V_24 -> V_41 , V_418 ) ;
if ( V_417 >= 0 )
V_417 = F_192 ( V_24 -> V_117 , V_417 , sizeof( T_6 ) , V_120 ) ;
return V_417 < 0 ? V_417 : 0 ;
}
static int F_193 ( struct V_1 * V_24 , unsigned int V_415 , T_6 V_120 )
{
int V_417 = F_190 ( V_415 , V_24 -> V_41 , V_418 ) ;
if ( V_417 >= 0 )
V_417 = F_194 ( V_24 -> V_117 , V_417 , sizeof( T_6 ) , & V_120 ) ;
return V_417 < 0 ? V_417 : 0 ;
}
static int F_195 ( struct V_10 * V_11 , struct V_419 * V_377 ,
T_3 * V_100 )
{
int V_125 , V_134 = 0 ;
struct V_1 * V_1 = F_149 ( V_11 ) ;
T_3 * V_298 = F_61 ( V_269 , V_151 ) ;
if ( ! V_298 )
return - V_152 ;
V_377 -> V_420 = V_421 ;
for ( V_125 = V_377 -> V_422 & ~ 3 ; ! V_134 && V_125 < V_377 -> V_422 + V_377 -> V_261 ; V_125 += 4 )
V_134 = F_191 ( V_1 , V_125 , ( T_6 * ) & V_298 [ V_125 ] ) ;
if ( ! V_134 )
memcpy ( V_100 , V_298 + V_377 -> V_422 , V_377 -> V_261 ) ;
F_63 ( V_298 ) ;
return V_134 ;
}
static int F_196 ( struct V_10 * V_11 , struct V_419 * V_423 ,
T_3 * V_100 )
{
T_3 * V_298 ;
int V_134 = 0 ;
T_6 V_424 , V_425 , * V_15 ;
struct V_1 * V_1 = F_149 ( V_11 ) ;
if ( V_423 -> V_420 != V_421 )
return - V_185 ;
V_424 = V_423 -> V_422 & ~ 3 ;
V_425 = ( V_423 -> V_261 + ( V_423 -> V_422 & 3 ) + 3 ) & ~ 3 ;
if ( V_1 -> V_41 > 0 ) {
T_6 V_299 = 1024 + V_1 -> V_41 * V_418 ;
if ( V_424 < V_299 ||
V_424 + V_425 > V_299 + V_418 )
return - V_426 ;
}
if ( V_424 != V_423 -> V_422 || V_425 != V_423 -> V_261 ) {
V_298 = F_61 ( V_425 , V_151 ) ;
if ( ! V_298 )
return - V_152 ;
V_134 = F_191 ( V_1 , V_424 , ( T_6 * ) V_298 ) ;
if ( ! V_134 && V_425 > 4 )
V_134 = F_191 ( V_1 ,
V_424 + V_425 - 4 ,
( T_6 * ) & V_298 [ V_425 - 4 ] ) ;
if ( V_134 )
goto V_186;
memcpy ( V_298 + ( V_423 -> V_422 & 3 ) , V_100 , V_423 -> V_261 ) ;
} else
V_298 = V_100 ;
V_134 = F_197 ( V_1 , false ) ;
if ( V_134 )
goto V_186;
for ( V_15 = ( T_6 * ) V_298 ; ! V_134 && V_425 ; V_425 -= 4 , V_15 ++ ) {
V_134 = F_193 ( V_1 , V_424 , * V_15 ) ;
V_424 += 4 ;
}
if ( ! V_134 )
V_134 = F_197 ( V_1 , true ) ;
V_186:
if ( V_298 != V_100 )
F_63 ( V_298 ) ;
return V_134 ;
}
static int F_198 ( struct V_10 * V_156 , struct V_427 * V_428 )
{
int V_34 ;
const struct V_179 * V_180 ;
struct V_1 * V_24 = F_149 ( V_156 ) ;
V_428 -> V_100 [ sizeof( V_428 -> V_100 ) - 1 ] = '\0' ;
V_34 = F_85 ( & V_180 , V_428 -> V_100 , V_24 -> V_68 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_199 ( V_24 , V_180 -> V_100 , V_180 -> V_189 ) ;
F_92 ( V_180 ) ;
if ( ! V_34 )
F_87 ( V_24 -> V_68 , L_35 , V_428 -> V_100 ) ;
return V_34 ;
}
static void F_200 ( struct V_10 * V_11 , struct V_429 * V_430 )
{
V_430 -> V_357 = V_431 | V_432 ;
V_430 -> V_433 = F_149 ( V_11 ) -> V_430 ;
memset ( & V_430 -> V_434 , 0 , sizeof( V_430 -> V_434 ) ) ;
}
static int F_201 ( struct V_10 * V_11 , struct V_429 * V_430 )
{
int V_134 = 0 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_430 -> V_433 & ~ V_435 )
return - V_185 ;
F_202 ( V_26 -> V_1 , V_26 -> V_52 ,
( V_430 -> V_433 & V_432 ) ? V_11 -> V_51 : NULL ) ;
if ( V_430 -> V_433 & V_431 ) {
V_134 = F_203 ( V_26 -> V_1 , V_26 -> V_52 , 0xfe , ~ 0ULL ,
~ 0ULL , 0 , false ) ;
if ( ! V_134 )
V_134 = F_203 ( V_26 -> V_1 , V_26 -> V_52 , 1 ,
~ 6ULL , ~ 0ULL , V_436 , true ) ;
} else
F_203 ( V_26 -> V_1 , V_26 -> V_52 , 0 , 0 , 0 , 0 , false ) ;
return V_134 ;
}
static int F_204 ( struct V_10 * V_11 , T_8 V_48 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
T_8 V_437 = V_11 -> V_48 ^ V_48 ;
int V_134 ;
if ( ! ( V_437 & V_49 ) )
return 0 ;
V_134 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_48 & V_49 ) , true ) ;
if ( F_205 ( V_134 ) )
V_11 -> V_48 = V_48 ^ V_49 ;
return V_134 ;
}
static T_6 F_206 ( struct V_10 * V_11 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
return V_26 -> V_150 ;
}
static int F_207 ( struct V_10 * V_11 , T_6 * V_15 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
unsigned int V_128 = V_26 -> V_150 ;
while ( V_128 -- )
V_15 [ V_128 ] = V_26 -> V_147 [ V_128 ] ;
return 0 ;
}
static int F_208 ( struct V_10 * V_11 , const T_6 * V_15 )
{
unsigned int V_125 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
for ( V_125 = 0 ; V_125 < V_26 -> V_150 ; V_125 ++ )
V_26 -> V_147 [ V_125 ] = V_15 [ V_125 ] ;
if ( V_26 -> V_1 -> V_45 & V_392 )
return F_60 ( V_26 , V_26 -> V_147 ) ;
return 0 ;
}
static int F_209 ( struct V_10 * V_11 , struct V_438 * V_271 ,
T_6 * V_439 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
switch ( V_271 -> V_341 ) {
case V_440 : {
unsigned int V_120 = V_26 -> V_441 ;
V_271 -> V_100 = 0 ;
switch ( V_271 -> V_442 ) {
case V_443 :
if ( V_120 & V_444 )
V_271 -> V_100 = V_445 | V_446 |
V_447 | V_448 ;
else if ( V_120 & V_449 )
V_271 -> V_100 = V_445 | V_446 ;
break;
case V_450 :
if ( ( V_120 & V_444 ) &&
( V_120 & V_451 ) )
V_271 -> V_100 = V_445 | V_446 |
V_447 | V_448 ;
else if ( V_120 & V_449 )
V_271 -> V_100 = V_445 | V_446 ;
break;
case V_452 :
case V_453 :
case V_454 :
if ( V_120 & V_449 )
V_271 -> V_100 = V_445 | V_446 ;
break;
case V_455 :
if ( V_120 & V_456 )
V_271 -> V_100 = V_445 | V_446 |
V_447 | V_448 ;
else if ( V_120 & V_457 )
V_271 -> V_100 = V_445 | V_446 ;
break;
case V_458 :
if ( ( V_120 & V_456 ) &&
( V_120 & V_451 ) )
V_271 -> V_100 = V_445 | V_446 |
V_447 | V_448 ;
else if ( V_120 & V_457 )
V_271 -> V_100 = V_445 | V_446 ;
break;
case V_459 :
case V_460 :
case V_461 :
if ( V_120 & V_457 )
V_271 -> V_100 = V_445 | V_446 ;
break;
}
return 0 ;
}
case V_462 :
V_271 -> V_100 = V_26 -> V_133 ;
return 0 ;
}
return - V_267 ;
}
static T_9 F_210 ( struct V_463 * V_463 , char T_10 * V_298 , T_7 V_464 ,
T_11 * V_465 )
{
T_11 V_466 = * V_465 ;
T_11 V_467 = F_211 ( V_463 ) -> V_468 ;
unsigned int V_469 = ( V_470 ) V_463 -> V_471 & 3 ;
struct V_1 * V_24 = V_463 -> V_471 - V_469 ;
if ( V_466 < 0 )
return - V_185 ;
if ( V_466 >= V_467 )
return 0 ;
if ( V_464 > V_467 - V_466 )
V_464 = V_467 - V_466 ;
while ( V_464 ) {
T_7 V_261 ;
int V_34 , V_472 ;
T_12 V_100 [ 16 ] ;
if ( V_469 == V_473 )
V_34 = F_212 ( V_24 , V_466 , V_100 , NULL ) ;
else
V_34 = F_213 ( V_24 , V_469 , V_466 , V_100 , NULL ) ;
if ( V_34 )
return V_34 ;
V_472 = V_466 % sizeof( V_100 ) ;
V_261 = F_214 ( V_464 , sizeof( V_100 ) - V_472 ) ;
if ( F_215 ( V_298 , ( T_3 * ) V_100 + V_472 , V_261 ) )
return - V_474 ;
V_298 += V_261 ;
V_466 += V_261 ;
V_464 -= V_261 ;
}
V_464 = V_466 - * V_465 ;
* V_465 = V_466 ;
return V_464 ;
}
static void F_216 ( struct V_1 * V_24 , const char * V_131 ,
unsigned int V_58 , unsigned int V_475 )
{
struct V_476 * V_477 ;
V_477 = F_217 ( V_131 , V_478 , V_24 -> V_479 ,
( void * ) V_24 + V_58 , & V_480 ) ;
if ( V_477 && V_477 -> V_481 )
V_477 -> V_481 -> V_468 = V_475 << 20 ;
}
static int F_218 ( struct V_1 * V_24 )
{
int V_125 ;
if ( F_219 ( V_24 -> V_479 ) )
return - 1 ;
V_125 = F_47 ( V_24 , V_482 ) ;
if ( V_125 & V_483 )
F_216 ( V_24 , L_36 , V_484 , 5 ) ;
if ( V_125 & V_485 )
F_216 ( V_24 , L_37 , V_486 , 5 ) ;
if ( V_125 & V_487 )
F_216 ( V_24 , L_38 , V_473 ,
F_220 ( F_47 ( V_24 , V_488 ) ) ) ;
if ( V_24 -> V_55 )
F_217 ( L_39 , V_478 , V_24 -> V_479 , V_24 ,
& V_489 ) ;
return 0 ;
}
int F_221 ( struct V_490 * V_167 , void * V_100 )
{
int V_491 = - 1 ;
F_222 ( & V_167 -> V_492 ) ;
if ( V_167 -> V_493 ) {
union V_494 * V_15 = V_167 -> V_493 ;
V_491 = ( V_15 - V_167 -> V_495 ) + V_167 -> V_496 ;
V_167 -> V_493 = V_15 -> V_497 ;
V_15 -> V_100 = V_100 ;
V_167 -> V_498 ++ ;
}
F_223 ( & V_167 -> V_492 ) ;
return V_491 ;
}
void F_224 ( struct V_490 * V_167 , unsigned int V_491 )
{
union V_494 * V_15 = & V_167 -> V_495 [ V_491 - V_167 -> V_496 ] ;
F_222 ( & V_167 -> V_492 ) ;
V_15 -> V_497 = V_167 -> V_493 ;
V_167 -> V_493 = V_15 ;
V_167 -> V_498 -- ;
F_223 ( & V_167 -> V_492 ) ;
}
int F_225 ( struct V_490 * V_167 , int V_499 , void * V_100 )
{
int V_500 ;
F_222 ( & V_167 -> V_501 ) ;
if ( V_499 == V_502 ) {
V_500 = F_226 ( V_167 -> V_503 , V_167 -> V_504 ) ;
if ( V_500 < V_167 -> V_504 )
F_227 ( V_500 , V_167 -> V_503 ) ;
else
V_500 = - 1 ;
} else {
V_500 = F_228 ( V_167 -> V_503 , V_167 -> V_504 , 2 ) ;
if ( V_500 < 0 )
V_500 = - 1 ;
}
if ( V_500 >= 0 ) {
V_167 -> V_505 [ V_500 ] . V_100 = V_100 ;
V_500 += V_167 -> V_506 ;
V_167 -> V_507 ++ ;
}
F_223 ( & V_167 -> V_501 ) ;
return V_500 ;
}
int F_229 ( struct V_490 * V_167 , int V_499 , void * V_100 )
{
int V_500 ;
F_222 ( & V_167 -> V_501 ) ;
if ( V_499 == V_502 ) {
V_500 = F_230 ( V_167 -> V_503 ,
V_167 -> V_504 + V_167 -> V_63 , V_167 -> V_504 ) ;
if ( V_500 < ( V_167 -> V_504 + V_167 -> V_63 ) )
F_227 ( V_500 , V_167 -> V_503 ) ;
else
V_500 = - 1 ;
} else {
V_500 = - 1 ;
}
if ( V_500 >= 0 ) {
V_167 -> V_505 [ V_500 ] . V_100 = V_100 ;
V_500 += V_167 -> V_506 ;
V_167 -> V_507 ++ ;
}
F_223 ( & V_167 -> V_501 ) ;
return V_500 ;
}
void F_231 ( struct V_490 * V_167 , unsigned int V_500 , int V_499 )
{
V_500 -= V_167 -> V_506 ;
F_222 ( & V_167 -> V_501 ) ;
if ( V_499 == V_502 )
F_232 ( V_500 , V_167 -> V_503 ) ;
else
F_233 ( V_167 -> V_503 , V_500 , 2 ) ;
V_167 -> V_505 [ V_500 ] . V_100 = NULL ;
V_167 -> V_507 -- ;
F_223 ( & V_167 -> V_501 ) ;
}
static void F_234 ( struct V_191 * V_192 , unsigned int V_508 ,
unsigned int V_509 )
{
struct V_510 * V_511 ;
F_142 ( V_192 , V_512 , V_508 ) ;
V_511 = (struct V_510 * ) F_103 ( V_192 , sizeof( * V_511 ) ) ;
F_235 ( V_511 , V_509 ) ;
F_236 ( V_511 ) = F_104 ( F_237 ( V_513 , V_509 ) ) ;
}
static void F_238 ( struct V_490 * V_167 , unsigned int V_508 ,
unsigned int V_509 )
{
void * * V_15 = & V_167 -> V_514 [ V_509 ] ;
struct V_1 * V_24 = F_36 ( V_167 , struct V_1 , V_60 ) ;
F_222 ( & V_24 -> V_515 ) ;
* V_15 = V_24 -> V_516 ;
V_24 -> V_516 = ( void * * ) ( ( V_470 ) V_15 | V_508 ) ;
if ( ! V_24 -> V_517 ) {
V_24 -> V_517 = true ;
F_239 ( V_518 , & V_24 -> V_519 ) ;
}
F_223 ( & V_24 -> V_515 ) ;
}
static void F_240 ( struct V_520 * V_521 )
{
struct V_191 * V_192 ;
struct V_1 * V_24 ;
V_24 = F_36 ( V_521 , struct V_1 , V_519 ) ;
F_222 ( & V_24 -> V_515 ) ;
while ( V_24 -> V_516 ) {
void * * V_15 = V_24 -> V_516 ;
unsigned int V_508 = ( V_470 ) V_15 & 3 ;
V_15 = ( void * ) V_15 - V_508 ;
V_24 -> V_516 = * V_15 ;
* V_15 = NULL ;
F_223 ( & V_24 -> V_515 ) ;
while ( ! ( V_192 = F_102 ( sizeof( struct V_510 ) ,
V_151 ) ) )
F_241 ( 1 ) ;
F_234 ( V_192 , V_508 , V_15 - V_24 -> V_60 . V_514 ) ;
F_143 ( V_24 , V_192 ) ;
F_222 ( & V_24 -> V_515 ) ;
}
V_24 -> V_517 = false ;
F_223 ( & V_24 -> V_515 ) ;
}
void F_242 ( struct V_490 * V_167 , unsigned int V_508 , unsigned int V_509 )
{
void * V_522 ;
struct V_191 * V_192 ;
struct V_1 * V_24 = F_36 ( V_167 , struct V_1 , V_60 ) ;
V_522 = V_167 -> V_514 [ V_509 ] ;
V_192 = F_102 ( sizeof( struct V_510 ) , V_523 ) ;
if ( F_33 ( V_192 ) ) {
V_167 -> V_514 [ V_509 ] = NULL ;
F_234 ( V_192 , V_508 , V_509 ) ;
F_143 ( V_24 , V_192 ) ;
} else
F_238 ( V_167 , V_508 , V_509 ) ;
if ( V_522 )
F_243 ( & V_167 -> V_524 ) ;
}
static int F_244 ( struct V_490 * V_167 )
{
T_7 V_189 ;
unsigned int V_525 ;
unsigned int V_526 = V_167 -> V_526 ;
V_525 = F_245 ( V_167 -> V_504 + V_167 -> V_63 ) ;
V_189 = V_167 -> V_527 * sizeof( * V_167 -> V_514 ) +
V_526 * sizeof( * V_167 -> V_495 ) +
V_167 -> V_504 * sizeof( * V_167 -> V_505 ) +
V_167 -> V_63 * sizeof( * V_167 -> V_505 ) +
V_525 * sizeof( long ) +
V_167 -> V_62 * sizeof( * V_167 -> V_65 ) +
V_167 -> V_63 * sizeof( * V_167 -> V_65 ) ;
V_167 -> V_514 = F_93 ( V_189 ) ;
if ( ! V_167 -> V_514 )
return - V_152 ;
V_167 -> V_495 = (union V_494 * ) & V_167 -> V_514 [ V_167 -> V_527 ] ;
V_167 -> V_505 = (struct V_528 * ) & V_167 -> V_495 [ V_526 ] ;
V_167 -> V_503 = ( unsigned long * ) & V_167 -> V_505 [ V_167 -> V_504 + V_167 -> V_63 ] ;
V_167 -> V_65 = (struct V_53 * ) & V_167 -> V_503 [ V_525 ] ;
F_246 ( & V_167 -> V_501 ) ;
F_246 ( & V_167 -> V_492 ) ;
V_167 -> V_507 = 0 ;
V_167 -> V_493 = NULL ;
V_167 -> V_498 = 0 ;
F_247 ( & V_167 -> V_524 , 0 ) ;
if ( V_526 ) {
while ( -- V_526 )
V_167 -> V_495 [ V_526 - 1 ] . V_497 = & V_167 -> V_495 [ V_526 ] ;
V_167 -> V_493 = V_167 -> V_495 ;
}
F_75 ( V_167 -> V_503 , V_167 -> V_504 + V_167 -> V_63 ) ;
return 0 ;
}
int F_248 ( const struct V_10 * V_11 , unsigned int V_500 ,
T_12 V_529 , T_13 V_530 , T_13 V_200 ,
unsigned int V_531 )
{
unsigned int V_508 ;
struct V_191 * V_192 ;
struct V_1 * V_24 ;
struct V_532 * V_511 ;
V_192 = F_102 ( sizeof( * V_511 ) , V_151 ) ;
if ( ! V_192 )
return - V_152 ;
V_24 = F_149 ( V_11 ) ;
V_511 = (struct V_532 * ) F_103 ( V_192 , sizeof( * V_511 ) ) ;
F_235 ( V_511 , 0 ) ;
F_236 ( V_511 ) = F_104 ( F_237 ( V_533 , V_500 ) ) ;
V_511 -> V_534 = V_530 ;
V_511 -> V_535 = F_125 ( 0 ) ;
V_511 -> V_536 = V_529 ;
V_511 -> V_537 = F_104 ( 0 ) ;
V_508 = F_66 ( & V_24 -> V_87 , V_531 ) ;
V_511 -> V_538 = F_249 ( F_250 ( V_508 ) ) ;
V_511 -> V_539 = F_249 ( V_540 |
V_541 | F_251 ( V_531 ) ) ;
return F_146 ( V_24 , V_192 ) ;
}
unsigned int F_252 ( const unsigned short * V_542 , unsigned short V_43 ,
unsigned int * V_58 )
{
unsigned int V_125 = 0 ;
while ( V_125 < V_543 - 1 && V_542 [ V_125 + 1 ] <= V_43 )
++ V_125 ;
if ( V_58 )
* V_58 = V_125 ;
return V_542 [ V_125 ] ;
}
unsigned int F_253 ( const struct V_10 * V_11 )
{
return F_67 ( V_11 ) -> V_52 ;
}
unsigned int F_254 ( const struct V_10 * V_11 , int V_544 )
{
struct V_1 * V_24 = F_149 ( V_11 ) ;
T_6 V_120 ;
V_120 = F_47 ( V_24 , V_545 ) ;
return V_544 ? F_255 ( V_120 ) : F_256 ( V_120 ) ;
}
unsigned int F_257 ( const struct V_10 * V_11 )
{
return F_67 ( V_11 ) -> V_42 ;
}
unsigned int F_258 ( const struct V_10 * V_11 )
{
return F_67 ( V_11 ) -> V_21 ;
}
void F_259 ( struct V_546 * V_117 , struct V_547 * V_548 ,
struct V_547 * V_549 )
{
struct V_1 * V_24 = F_260 ( V_117 ) ;
F_261 ( & V_24 -> V_550 ) ;
F_262 ( V_24 , V_548 , V_549 ) ;
F_263 ( & V_24 -> V_550 ) ;
}
void F_264 ( struct V_10 * V_11 , unsigned int V_551 ,
const unsigned int * V_552 )
{
struct V_1 * V_24 = F_149 ( V_11 ) ;
F_49 ( V_24 , V_553 , V_551 ) ;
F_49 ( V_24 , V_554 , F_265 ( V_552 [ 0 ] ) |
F_266 ( V_552 [ 1 ] ) | F_267 ( V_552 [ 2 ] ) |
F_268 ( V_552 [ 3 ] ) ) ;
}
int F_269 ( struct V_10 * V_11 )
{
struct V_1 * V_24 = F_149 ( V_11 ) ;
int V_34 ;
V_34 = F_270 ( V_24 , V_24 -> V_188 ,
0xe1000000 + V_555 , 0x20000000 ) ;
return V_34 ;
}
static int F_271 ( struct V_1 * V_24 , T_2 V_83 , T_2 * V_556 , T_2 * V_557 )
{
T_6 V_33 = F_47 ( V_24 , V_558 ) + 24 * V_83 + 8 ;
T_4 V_559 ;
int V_34 ;
V_34 = F_272 ( V_24 , V_33 , ( T_12 * ) & V_559 , 8 ) ;
if ( ! V_34 ) {
* V_557 = ( F_31 ( V_559 ) >> 25 ) & 0xffff ;
* V_556 = ( F_31 ( V_559 ) >> 9 ) & 0xffff ;
}
return V_34 ;
}
int F_273 ( struct V_10 * V_11 , T_2 V_83 , T_2 V_556 ,
T_2 V_189 )
{
struct V_1 * V_24 = F_149 ( V_11 ) ;
T_2 V_560 , V_561 ;
int V_34 ;
V_34 = F_271 ( V_24 , V_83 , & V_560 , & V_561 ) ;
if ( V_34 )
goto V_186;
if ( V_556 != V_560 ) {
T_2 V_394 ;
if ( V_556 >= V_560 )
V_394 = V_556 - V_560 ;
else
V_394 = V_189 - V_560 + V_556 ;
F_274 () ;
F_49 ( V_24 , F_48 ( V_562 ) ,
F_275 ( V_83 ) | F_276 ( V_394 ) ) ;
}
V_186:
return V_34 ;
}
static void F_277 ( struct V_563 * V_564 )
{
const struct V_181 * V_565 ;
const struct V_10 * V_156 = V_564 -> V_11 ;
if ( V_156 -> V_566 & V_567 )
V_156 = F_278 ( V_156 ) ;
V_565 = V_156 -> V_11 . V_565 ;
if ( V_565 && V_565 -> V_272 == & V_568 . V_272 )
F_279 ( F_280 ( V_565 ) , V_564 ) ;
}
static int F_281 ( struct V_569 * V_570 , unsigned long V_571 ,
void * V_100 )
{
switch ( V_571 ) {
case V_572 :
F_277 ( V_100 ) ;
break;
case V_573 :
default:
break;
}
return 0 ;
}
static void F_282 ( struct V_1 * V_24 , int V_574 )
{
T_6 V_120 ;
do {
F_283 ( V_575 ) ;
F_284 ( F_285 ( V_574 ) ) ;
V_120 = F_47 ( V_24 , V_545 ) ;
if ( F_255 ( V_120 ) == 0 && F_256 ( V_120 ) == 0 )
break;
} while ( 1 );
}
static void F_286 ( struct V_85 * V_75 )
{
F_287 ( & V_75 -> V_576 ) ;
V_75 -> V_577 = 1 ;
F_288 ( & V_75 -> V_576 ) ;
}
static void F_289 ( struct V_85 * V_75 )
{
F_287 ( & V_75 -> V_576 ) ;
V_75 -> V_577 = 0 ;
F_288 ( & V_75 -> V_576 ) ;
}
static void F_290 ( struct V_1 * V_24 )
{
int V_125 ;
F_57 (&adap->sge, i)
F_286 ( & V_24 -> V_87 . V_168 [ V_125 ] . V_75 ) ;
F_53 (&adap->sge, i)
F_286 ( & V_24 -> V_87 . V_91 [ V_125 ] . V_75 ) ;
F_52 (adap, i)
F_286 ( & V_24 -> V_87 . V_174 [ V_125 ] . V_75 ) ;
}
static void F_291 ( struct V_1 * V_24 )
{
int V_125 ;
F_57 (&adap->sge, i)
F_289 ( & V_24 -> V_87 . V_168 [ V_125 ] . V_75 ) ;
F_53 (&adap->sge, i)
F_289 ( & V_24 -> V_87 . V_91 [ V_125 ] . V_75 ) ;
F_52 (adap, i)
F_289 ( & V_24 -> V_87 . V_174 [ V_125 ] . V_75 ) ;
}
static void F_292 ( struct V_1 * V_24 , struct V_85 * V_75 )
{
T_2 V_560 , V_561 ;
int V_34 ;
F_222 ( & V_75 -> V_576 ) ;
V_34 = F_271 ( V_24 , ( T_2 ) V_75 -> V_161 , & V_560 , & V_561 ) ;
if ( V_34 )
goto V_186;
if ( V_75 -> V_578 != V_560 ) {
T_2 V_394 ;
if ( V_75 -> V_578 >= V_560 )
V_394 = V_75 -> V_578 - V_560 ;
else
V_394 = V_75 -> V_189 - V_560 + V_75 -> V_578 ;
F_274 () ;
F_49 ( V_24 , F_48 ( V_562 ) ,
F_275 ( V_75 -> V_161 ) | F_276 ( V_394 ) ) ;
}
V_186:
V_75 -> V_577 = 0 ;
F_223 ( & V_75 -> V_576 ) ;
if ( V_34 )
F_293 ( V_24 , L_40 ) ;
}
static void F_294 ( struct V_1 * V_24 )
{
int V_125 ;
F_57 (&adap->sge, i)
F_292 ( V_24 , & V_24 -> V_87 . V_168 [ V_125 ] . V_75 ) ;
F_53 (&adap->sge, i)
F_292 ( V_24 , & V_24 -> V_87 . V_91 [ V_125 ] . V_75 ) ;
F_52 (adap, i)
F_292 ( V_24 , & V_24 -> V_87 . V_174 [ V_125 ] . V_75 ) ;
}
static void F_295 ( struct V_1 * V_24 , enum V_579 V_341 )
{
F_296 ( & V_580 ) ;
if ( V_24 -> V_109 [ V_581 ] )
V_107 [ V_581 ] . F_297 ( V_24 -> V_109 [ V_581 ] ,
V_341 ) ;
F_298 ( & V_580 ) ;
}
static void F_299 ( struct V_520 * V_521 )
{
struct V_1 * V_24 ;
V_24 = F_36 ( V_521 , struct V_1 , V_582 ) ;
F_295 ( V_24 , V_583 ) ;
F_282 ( V_24 , V_584 ) ;
F_300 ( V_24 , V_585 ,
V_586 | V_587 ,
V_586 | V_587 ) ;
F_295 ( V_24 , V_588 ) ;
}
static void F_301 ( struct V_520 * V_521 )
{
struct V_1 * V_24 ;
V_24 = F_36 ( V_521 , struct V_1 , V_589 ) ;
F_300 ( V_24 , V_590 , V_591 , 0 ) ;
F_290 ( V_24 ) ;
F_295 ( V_24 , V_592 ) ;
F_282 ( V_24 , 1 ) ;
F_294 ( V_24 ) ;
F_291 ( V_24 ) ;
}
void F_302 ( struct V_1 * V_24 )
{
F_300 ( V_24 , V_585 ,
V_586 | V_587 , 0 ) ;
F_239 ( V_518 , & V_24 -> V_582 ) ;
}
void F_303 ( struct V_1 * V_24 )
{
F_239 ( V_518 , & V_24 -> V_589 ) ;
}
static void F_304 ( struct V_1 * V_24 , unsigned int V_108 )
{
void * V_593 ;
struct V_594 V_595 ;
unsigned short V_125 ;
V_595 . V_117 = V_24 -> V_117 ;
V_595 . V_55 = V_24 -> V_55 ;
V_595 . V_60 = & V_24 -> V_60 ;
V_595 . V_596 = V_24 -> V_23 ;
V_595 . V_597 = & V_24 -> V_598 ;
V_595 . V_542 = V_24 -> V_7 . V_542 ;
if ( V_108 == V_581 ) {
V_595 . V_599 = V_24 -> V_87 . V_173 ;
V_595 . V_600 = V_24 -> V_87 . V_601 ;
} else if ( V_108 == V_602 ) {
V_595 . V_599 = V_24 -> V_87 . V_172 ;
V_595 . V_600 = V_24 -> V_87 . V_171 ;
}
V_595 . V_603 = V_24 -> V_87 . V_171 ;
V_595 . V_604 = V_24 -> V_7 . V_8 ;
V_595 . V_8 = V_24 -> V_7 . V_8 ;
V_595 . V_605 = V_24 -> V_7 . V_606 ;
V_595 . V_607 = V_24 -> V_7 . V_297 ;
V_595 . V_608 = F_305 ( F_47 ( V_24 , V_609 ) ) ;
V_595 . V_610 = 1 << F_306 (
F_47 ( V_24 , V_611 ) >>
( V_24 -> V_41 * 4 ) ) ;
V_595 . V_612 = 1 << F_306 (
F_47 ( V_24 , V_613 ) >>
( V_24 -> V_41 * 4 ) ) ;
V_595 . V_614 = V_24 -> V_615 ;
for ( V_125 = 0 ; V_125 < V_616 ; V_125 ++ )
V_595 . V_617 [ V_125 ] = V_125 ;
V_595 . V_618 = V_24 -> V_302 + F_48 ( V_159 ) ;
V_595 . V_619 = V_24 -> V_302 + F_48 ( V_562 ) ;
V_595 . V_187 = V_24 -> V_7 . V_187 ;
V_595 . V_620 = V_620 ;
V_595 . V_621 = V_24 -> V_87 . V_622 ;
V_595 . V_623 = V_24 -> V_45 & V_624 ;
V_593 = V_107 [ V_108 ] . F_307 ( & V_595 ) ;
if ( F_308 ( V_593 ) ) {
F_309 ( V_24 -> V_68 ,
L_41 ,
V_625 [ V_108 ] , F_310 ( V_593 ) ) ;
return;
}
V_24 -> V_109 [ V_108 ] = V_593 ;
if ( ! V_626 ) {
F_311 ( & V_627 ) ;
V_626 = true ;
}
if ( V_24 -> V_45 & V_392 )
V_107 [ V_108 ] . F_312 ( V_593 , V_628 ) ;
}
static void F_313 ( struct V_1 * V_24 )
{
unsigned int V_125 ;
F_296 ( & V_580 ) ;
F_314 ( & V_24 -> V_629 , & V_630 ) ;
for ( V_125 = 0 ; V_125 < V_631 ; V_125 ++ )
if ( V_107 [ V_125 ] . F_307 )
F_304 ( V_24 , V_125 ) ;
F_298 ( & V_580 ) ;
}
static void F_315 ( struct V_1 * V_24 )
{
unsigned int V_125 ;
F_296 ( & V_580 ) ;
F_316 ( & V_24 -> V_629 ) ;
for ( V_125 = 0 ; V_125 < V_631 ; V_125 ++ )
if ( V_24 -> V_109 [ V_125 ] ) {
V_107 [ V_125 ] . F_312 ( V_24 -> V_109 [ V_125 ] ,
V_632 ) ;
V_24 -> V_109 [ V_125 ] = NULL ;
}
if ( V_626 && F_317 ( & V_630 ) ) {
F_318 ( & V_627 ) ;
V_626 = false ;
}
F_298 ( & V_580 ) ;
}
static void F_319 ( struct V_1 * V_24 , enum V_633 V_634 )
{
unsigned int V_125 ;
F_296 ( & V_580 ) ;
for ( V_125 = 0 ; V_125 < V_631 ; V_125 ++ )
if ( V_24 -> V_109 [ V_125 ] )
V_107 [ V_125 ] . F_312 ( V_24 -> V_109 [ V_125 ] , V_634 ) ;
F_298 ( & V_580 ) ;
}
int F_320 ( enum V_635 type , const struct V_636 * V_15 )
{
int V_34 = 0 ;
struct V_1 * V_24 ;
if ( type >= V_631 )
return - V_185 ;
F_296 ( & V_580 ) ;
if ( V_107 [ type ] . F_307 ) {
V_34 = - V_393 ;
goto V_186;
}
V_107 [ type ] = * V_15 ;
F_321 (adap, &adapter_list, list_node)
F_304 ( V_24 , type ) ;
V_186: F_298 ( & V_580 ) ;
return V_34 ;
}
int F_322 ( enum V_635 type )
{
struct V_1 * V_24 ;
if ( type >= V_631 )
return - V_185 ;
F_296 ( & V_580 ) ;
F_321 (adap, &adapter_list, list_node)
V_24 -> V_109 [ type ] = NULL ;
V_107 [ type ] . F_307 = NULL ;
F_298 ( & V_580 ) ;
return 0 ;
}
static int F_323 ( struct V_1 * V_24 )
{
int V_134 ;
V_134 = F_74 ( V_24 ) ;
if ( V_134 )
goto V_186;
V_134 = F_64 ( V_24 ) ;
if ( V_134 )
goto V_637;
if ( V_24 -> V_45 & V_116 ) {
F_51 ( V_24 ) ;
V_134 = F_56 ( V_24 -> V_129 [ 0 ] . V_139 , F_46 , 0 ,
V_24 -> V_129 [ 0 ] . V_130 , V_24 ) ;
if ( V_134 )
goto V_638;
V_134 = F_55 ( V_24 ) ;
if ( V_134 ) {
F_58 ( V_24 -> V_129 [ 0 ] . V_139 , V_24 ) ;
goto V_638;
}
} else {
V_134 = F_56 ( V_24 -> V_117 -> V_119 , F_324 ( V_24 ) ,
( V_24 -> V_45 & V_118 ) ? 0 : V_639 ,
V_24 -> V_23 [ 0 ] -> V_131 , V_24 ) ;
if ( V_134 )
goto V_638;
}
F_70 ( V_24 ) ;
F_325 ( V_24 ) ;
F_326 ( V_24 ) ;
V_24 -> V_45 |= V_392 ;
F_319 ( V_24 , V_628 ) ;
V_186:
return V_134 ;
V_638:
F_30 ( V_24 -> V_68 , L_42 , V_134 ) ;
V_637:
F_77 ( V_24 ) ;
goto V_186;
}
static void F_327 ( struct V_1 * V_1 )
{
F_328 ( V_1 ) ;
F_329 ( & V_1 -> V_519 ) ;
F_329 ( & V_1 -> V_582 ) ;
F_329 ( & V_1 -> V_589 ) ;
V_1 -> V_517 = false ;
V_1 -> V_516 = NULL ;
if ( V_1 -> V_45 & V_116 ) {
F_59 ( V_1 ) ;
F_58 ( V_1 -> V_129 [ 0 ] . V_139 , V_1 ) ;
} else
F_58 ( V_1 -> V_117 -> V_119 , V_1 ) ;
F_68 ( V_1 ) ;
F_330 ( V_1 ) ;
F_77 ( V_1 ) ;
V_1 -> V_45 &= ~ V_392 ;
}
static int F_331 ( struct V_10 * V_11 )
{
int V_134 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_9 ( V_11 ) ;
if ( ! ( V_1 -> V_45 & V_392 ) ) {
V_134 = F_323 ( V_1 ) ;
if ( V_134 < 0 )
return V_134 ;
}
V_134 = F_21 ( V_11 ) ;
if ( ! V_134 )
F_332 ( V_11 ) ;
return V_134 ;
}
static int F_333 ( struct V_10 * V_11 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_334 ( V_11 ) ;
F_9 ( V_11 ) ;
return F_24 ( V_1 , V_1 -> V_41 , V_26 -> V_42 , false , false ) ;
}
static int F_335 ( struct V_53 * V_54 )
{
if ( V_54 -> V_640 )
return - V_426 ;
if ( V_54 -> V_72 )
return - V_393 ;
return 0 ;
}
static int F_336 ( struct V_1 * V_1 , unsigned int V_190 )
{
struct V_53 * V_54 ;
int V_34 ;
if ( V_190 >= V_1 -> V_60 . V_62 + V_1 -> V_60 . V_63 )
return - V_185 ;
V_54 = & V_1 -> V_60 . V_65 [ V_190 ] ;
V_34 = F_335 ( V_54 ) ;
if ( V_34 )
return V_34 ;
if ( V_54 -> V_73 )
return F_144 ( V_1 , V_190 ) ;
return 0 ;
}
int F_337 ( const struct V_10 * V_11 , unsigned int V_500 ,
T_12 V_529 , T_13 V_530 , T_13 V_200 ,
unsigned int V_531 , unsigned char V_23 , unsigned char V_226 )
{
int V_34 ;
struct V_53 * V_54 ;
struct V_1 * V_24 ;
int V_125 ;
T_3 * V_224 ;
V_24 = F_149 ( V_11 ) ;
V_500 -= V_24 -> V_60 . V_504 ;
V_500 += V_24 -> V_60 . V_62 ;
V_54 = & V_24 -> V_60 . V_65 [ V_500 ] ;
V_34 = F_335 ( V_54 ) ;
if ( V_34 )
return V_34 ;
if ( V_54 -> V_73 )
F_25 ( V_24 , V_54 ) ;
memset ( & V_54 -> V_196 , 0 , sizeof( struct V_641 ) ) ;
V_54 -> V_196 . V_224 . V_253 = F_338 ( V_530 ) ;
V_54 -> V_196 . V_226 . V_253 = ~ 0 ;
V_224 = ( T_3 * ) & V_529 ;
if ( ( V_224 [ 0 ] | V_224 [ 1 ] | V_224 [ 2 ] | V_224 [ 3 ] ) != 0 ) {
for ( V_125 = 0 ; V_125 < 4 ; V_125 ++ ) {
V_54 -> V_196 . V_224 . V_248 [ V_125 ] = V_224 [ V_125 ] ;
V_54 -> V_196 . V_226 . V_248 [ V_125 ] = ~ 0 ;
}
if ( V_24 -> V_615 & V_642 ) {
V_54 -> V_196 . V_224 . V_236 = V_23 ;
V_54 -> V_196 . V_226 . V_236 = V_226 ;
}
}
V_54 -> V_196 . V_213 = 1 ;
V_54 -> V_196 . V_208 = V_531 ;
V_54 -> V_640 = 1 ;
V_54 -> V_196 . V_210 = 1 ;
V_34 = F_99 ( V_24 , V_500 ) ;
if ( V_34 ) {
F_25 ( V_24 , V_54 ) ;
return V_34 ;
}
return 0 ;
}
int F_339 ( const struct V_10 * V_11 , unsigned int V_500 ,
unsigned int V_531 , bool V_643 )
{
int V_34 ;
struct V_53 * V_54 ;
struct V_1 * V_24 ;
V_24 = F_149 ( V_11 ) ;
V_500 -= V_24 -> V_60 . V_504 ;
V_500 += V_24 -> V_60 . V_62 ;
V_54 = & V_24 -> V_60 . V_65 [ V_500 ] ;
V_54 -> V_640 = 0 ;
V_34 = F_336 ( V_24 , V_500 ) ;
if ( V_34 )
return V_34 ;
return 0 ;
}
static struct V_644 * F_340 ( struct V_10 * V_11 ,
struct V_644 * V_645 )
{
struct V_295 V_110 ;
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_15 -> V_1 ;
F_261 ( & V_1 -> V_550 ) ;
F_160 ( V_1 , V_15 -> V_52 , & V_110 ) ;
F_263 ( & V_1 -> V_550 ) ;
V_645 -> V_646 = V_110 . V_647 ;
V_645 -> V_648 = V_110 . V_649 ;
V_645 -> V_650 = V_110 . V_651 ;
V_645 -> V_652 = V_110 . V_653 ;
V_645 -> V_654 = V_110 . V_655 ;
V_645 -> V_656 = V_110 . V_657 + V_110 . V_658 +
V_110 . V_659 ;
V_645 -> V_660 = 0 ;
V_645 -> V_661 = V_110 . V_662 ;
V_645 -> V_663 = V_110 . V_664 ;
V_645 -> V_665 = V_110 . V_666 + V_110 . V_667 +
V_110 . V_668 + V_110 . V_669 +
V_110 . V_670 + V_110 . V_671 +
V_110 . V_672 + V_110 . V_673 ;
V_645 -> V_674 = 0 ;
V_645 -> V_675 = 0 ;
V_645 -> V_676 = 0 ;
V_645 -> V_677 = 0 ;
V_645 -> V_678 = 0 ;
V_645 -> V_679 = 0 ;
V_645 -> V_680 = V_110 . V_681 ;
V_645 -> V_682 = V_110 . V_664 + V_110 . V_662 +
V_645 -> V_656 + V_110 . V_683 + V_645 -> V_665 ;
return V_645 ;
}
static int F_341 ( struct V_10 * V_11 , struct V_684 * V_511 , int V_341 )
{
unsigned int V_188 ;
int V_34 = 0 , V_685 , V_686 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_687 * V_100 = (struct V_687 * ) & V_511 -> V_688 ;
switch ( V_341 ) {
case V_689 :
if ( V_26 -> V_349 < 0 )
return - V_267 ;
V_100 -> V_690 = V_26 -> V_349 ;
break;
case V_691 :
case V_692 :
if ( F_342 ( V_100 -> V_690 ) ) {
V_685 = F_343 ( V_100 -> V_690 ) ;
V_686 = F_344 ( V_100 -> V_690 ) ;
} else if ( V_100 -> V_690 < 32 ) {
V_685 = V_100 -> V_690 ;
V_686 = 0 ;
V_100 -> V_693 &= 0x1f ;
} else
return - V_185 ;
V_188 = V_26 -> V_1 -> V_41 ;
if ( V_341 == V_691 )
V_34 = F_345 ( V_26 -> V_1 , V_188 , V_685 , V_686 ,
V_100 -> V_693 , & V_100 -> V_694 ) ;
else
V_34 = F_346 ( V_26 -> V_1 , V_188 , V_685 , V_686 ,
V_100 -> V_693 , V_100 -> V_695 ) ;
break;
default:
return - V_267 ;
}
return V_34 ;
}
static void F_347 ( struct V_10 * V_11 )
{
F_19 ( V_11 , - 1 , false ) ;
}
static int F_348 ( struct V_10 * V_11 , int V_696 )
{
int V_34 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_696 < 81 || V_696 > V_697 )
return - V_185 ;
V_34 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , V_696 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_34 )
V_11 -> V_43 = V_696 ;
return V_34 ;
}
static int F_349 ( struct V_10 * V_11 , void * V_15 )
{
int V_34 ;
struct V_698 * V_33 = V_15 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( ! F_350 ( V_33 -> V_699 ) )
return - V_700 ;
V_34 = F_22 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 ,
V_26 -> V_50 , V_33 -> V_699 , true , true ) ;
if ( V_34 < 0 )
return V_34 ;
memcpy ( V_11 -> V_51 , V_33 -> V_699 , V_11 -> V_701 ) ;
V_26 -> V_50 = V_34 ;
return 0 ;
}
static void F_351 ( struct V_10 * V_11 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_24 = V_26 -> V_1 ;
if ( V_24 -> V_45 & V_116 ) {
int V_125 ;
struct V_148 * V_282 = & V_24 -> V_87 . V_142 [ V_26 -> V_149 ] ;
for ( V_125 = V_26 -> V_133 ; V_125 ; V_125 -- , V_282 ++ )
V_140 ( 0 , & V_282 -> V_106 ) ;
} else
F_324 ( V_24 ) ( 0 , V_24 ) ;
}
void F_352 ( struct V_1 * V_24 )
{
F_300 ( V_24 , V_702 , V_703 , 0 ) ;
F_328 ( V_24 ) ;
F_353 ( V_24 -> V_68 , L_43 ) ;
}
static void F_354 ( struct V_1 * V_24 )
{
T_6 V_704 ;
V_704 = F_355 ( V_24 -> V_117 , 0 ) ;
F_49 ( V_24 , F_356 ( V_705 , 0 ) ,
( V_704 + V_706 ) | F_357 ( 0 ) |
F_358 ( F_359 ( V_707 ) - 10 ) ) ;
F_49 ( V_24 , F_356 ( V_705 , 1 ) ,
( V_704 + V_708 ) | F_357 ( 0 ) |
F_358 ( F_359 ( V_709 ) - 10 ) ) ;
F_49 ( V_24 , F_356 ( V_705 , 2 ) ,
( V_704 + V_710 ) | F_357 ( 0 ) |
F_358 ( F_359 ( V_711 ) - 10 ) ) ;
}
static void F_360 ( struct V_1 * V_24 )
{
if ( V_24 -> V_598 . V_712 . V_189 ) {
unsigned int V_299 , V_713 ;
V_299 = F_355 ( V_24 -> V_117 , 2 ) +
F_361 ( V_24 -> V_117 , & V_24 -> V_598 ) ;
V_713 = F_362 ( V_24 -> V_598 . V_712 . V_189 ) >> 10 ;
F_49 ( V_24 ,
F_356 ( V_705 , 3 ) ,
V_299 | F_357 ( 1 ) | F_358 ( F_359 ( V_713 ) ) ) ;
F_49 ( V_24 ,
F_356 ( V_714 , 3 ) ,
V_24 -> V_598 . V_712 . V_299 ) ;
F_47 ( V_24 ,
F_356 ( V_714 , 3 ) ) ;
}
}
static int F_363 ( struct V_1 * V_24 , struct V_715 * V_410 )
{
T_6 V_120 ;
int V_34 ;
memset ( V_410 , 0 , sizeof( * V_410 ) ) ;
V_410 -> V_716 = F_104 ( F_364 ( V_717 ) |
V_718 | V_719 ) ;
V_410 -> V_720 = F_104 ( F_365 ( * V_410 ) ) ;
V_34 = F_366 ( V_24 , V_24 -> V_41 , V_410 , sizeof( * V_410 ) , V_410 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_410 -> V_721 & F_125 ( V_722 ) ) {
if ( ! V_723 )
V_410 -> V_721 ^= F_125 ( V_722 ) ;
else
V_410 -> V_721 = F_125 ( V_722 ) ;
} else if ( V_723 ) {
F_30 ( V_24 -> V_68 , L_44 ) ;
return V_34 ;
}
V_410 -> V_716 = F_104 ( F_364 ( V_717 ) |
V_718 | V_724 ) ;
V_34 = F_366 ( V_24 , V_24 -> V_41 , V_410 , sizeof( * V_410 ) , NULL ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_367 ( V_24 , V_24 -> V_41 ,
V_725 ,
V_726 |
V_727 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_368 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , V_163 , 64 , V_728 ,
0 , 0 , 4 , 0xf , 0xf , 16 , V_729 , V_729 ) ;
if ( V_34 < 0 )
return V_34 ;
F_369 ( V_24 ) ;
F_49 ( V_24 , V_730 , 0x64f8849 ) ;
F_49 ( V_24 , V_731 , F_265 ( V_732 - 12 ) ) ;
F_49 ( V_24 , V_733 , V_734 ) ;
V_120 = F_47 ( V_24 , V_735 ) ;
F_49 ( V_24 , V_735 , V_120 & ~ V_736 ) ;
V_24 -> V_7 . V_737 . V_738 = 0xE4 ;
F_49 ( V_24 , V_739 ,
F_370 ( V_24 -> V_7 . V_737 . V_738 ) ) ;
V_120 = 0x84218421 ;
F_371 ( V_24 , V_733 , V_735 ,
& V_120 , 1 , V_740 ) ;
F_371 ( V_24 , V_733 , V_735 ,
& V_120 , 1 , V_741 ) ;
F_371 ( V_24 , V_733 , V_735 ,
& V_120 , 1 , V_742 ) ;
#define F_372 16
if ( F_147 ( V_24 ) ) {
F_49 ( V_24 , V_743 ,
F_373 ( F_372 ) |
F_374 ( F_372 ) |
F_375 ( F_372 ) |
F_376 ( F_372 ) ) ;
F_49 ( V_24 , V_744 ,
F_373 ( F_372 ) |
F_374 ( F_372 ) |
F_375 ( F_372 ) |
F_376 ( F_372 ) ) ;
}
return F_377 ( V_24 , V_24 -> V_41 ) ;
}
static int F_378 ( struct V_1 * V_1 )
{
F_379 ( V_1 , V_745 , V_746 ) ;
if ( V_747 != 2 && V_747 != 0 ) {
F_30 ( & V_1 -> V_117 -> V_11 ,
L_45 ,
V_747 ) ;
V_747 = 2 ;
}
F_300 ( V_1 , V_702 ,
V_748 ,
F_380 ( V_747 ) ) ;
F_381 ( V_1 , V_734 ,
V_736 , 0 ) ;
return 0 ;
}
static int F_382 ( struct V_1 * V_1 , int V_749 )
{
struct V_715 V_750 ;
const struct V_179 * V_751 ;
unsigned long V_752 = 0 , V_753 = 0 ;
T_6 V_754 , V_755 , V_756 ;
int V_34 , V_757 ;
if ( V_749 ) {
V_34 = F_383 ( V_1 , V_1 -> V_188 ,
V_758 | V_759 ) ;
if ( V_34 < 0 )
goto V_760;
}
V_34 = F_85 ( & V_751 , V_761 , V_1 -> V_68 ) ;
if ( V_34 < 0 ) {
V_757 = 1 ;
V_752 = V_762 ;
V_753 = F_384 ( V_1 ) ;
} else {
T_6 V_7 [ 7 ] , V_224 [ 7 ] ;
V_757 = 0 ;
if ( V_751 -> V_189 >= V_763 )
V_34 = - V_152 ;
else {
V_7 [ 0 ] = ( F_183 ( V_764 ) |
F_184 ( V_765 ) ) ;
V_34 = F_385 ( V_1 , V_1 -> V_188 ,
V_1 -> V_41 , 0 , 1 , V_7 , V_224 ) ;
if ( V_34 == 0 ) {
T_7 V_766 = V_751 -> V_189 & 0x3 ;
T_7 V_189 = V_751 -> V_189 & ~ 0x3 ;
T_12 * V_100 = ( T_12 * ) V_751 -> V_100 ;
V_752 = F_386 ( V_224 [ 0 ] ) ;
V_753 = F_387 ( V_224 [ 0 ] ) << 16 ;
V_34 = F_388 ( V_1 , V_752 , V_753 ,
V_189 , V_100 ) ;
if ( V_34 == 0 && V_766 != 0 ) {
union {
T_12 V_767 ;
char V_298 [ 4 ] ;
} V_768 ;
int V_125 ;
V_768 . V_767 = V_100 [ V_189 >> 2 ] ;
for ( V_125 = V_766 ; V_125 < 4 ; V_125 ++ )
V_768 . V_298 [ V_125 ] = 0 ;
V_34 = F_388 ( V_1 , V_752 ,
V_753 + V_189 ,
4 , & V_768 . V_767 ) ;
}
}
}
F_92 ( V_751 ) ;
if ( V_34 )
goto V_760;
}
memset ( & V_750 , 0 , sizeof( V_750 ) ) ;
V_750 . V_716 =
F_104 ( F_364 ( V_717 ) |
V_718 |
V_719 ) ;
V_750 . V_720 =
F_104 ( V_769 |
F_389 ( V_752 ) |
F_390 ( V_753 >> 16 ) |
F_365 ( V_750 ) ) ;
V_34 = F_366 ( V_1 , V_1 -> V_188 , & V_750 , sizeof( V_750 ) ,
& V_750 ) ;
if ( V_34 < 0 )
goto V_760;
V_754 = F_35 ( V_750 . V_754 ) ;
V_755 = F_35 ( V_750 . V_755 ) ;
V_756 = F_35 ( V_750 . V_756 ) ;
if ( V_755 != V_756 )
F_309 ( V_1 -> V_68 , L_46\
L_47 ,
V_755 , V_756 ) ;
V_750 . V_716 =
F_104 ( F_364 ( V_717 ) |
V_718 |
V_724 ) ;
V_750 . V_720 = F_104 ( F_365 ( V_750 ) ) ;
V_34 = F_366 ( V_1 , V_1 -> V_188 , & V_750 , sizeof( V_750 ) ,
NULL ) ;
if ( V_34 < 0 )
goto V_760;
V_34 = F_378 ( V_1 ) ;
if ( V_34 < 0 )
goto V_760;
V_34 = F_391 ( V_1 , V_1 -> V_188 ) ;
if ( V_34 < 0 )
goto V_760;
V_1 -> V_45 |= V_770 ;
F_87 ( V_1 -> V_68 , L_48\
L_49 ,
( V_757
? L_50
: L_51 V_761 ) ,
V_754 , V_756 ) ;
return 0 ;
V_760:
if ( V_34 != - V_771 )
F_309 ( V_1 -> V_68 , L_52 ,
- V_34 ) ;
return V_34 ;
}
static int F_392 ( struct V_1 * V_1 , int V_749 )
{
struct V_87 * V_13 = & V_1 -> V_87 ;
struct V_715 V_750 ;
T_6 V_120 ;
int V_125 , V_34 ;
if ( V_749 ) {
V_34 = F_383 ( V_1 , V_1 -> V_188 ,
V_758 | V_759 ) ;
if ( V_34 < 0 )
goto V_760;
}
memset ( & V_750 , 0 , sizeof( V_750 ) ) ;
V_750 . V_716 = F_104 ( F_364 ( V_717 ) |
V_718 | V_719 ) ;
V_750 . V_720 = F_104 ( F_365 ( V_750 ) ) ;
V_34 = F_366 ( V_1 , V_1 -> V_188 , & V_750 , sizeof( V_750 ) ,
& V_750 ) ;
if ( V_34 < 0 )
goto V_760;
if ( V_750 . V_721 & F_125 ( V_722 ) ) {
if ( ! V_723 )
V_750 . V_721 ^= F_125 ( V_722 ) ;
else
V_750 . V_721 = F_125 ( V_722 ) ;
} else if ( V_723 ) {
F_30 ( V_1 -> V_68 , L_44 ) ;
goto V_760;
}
V_750 . V_716 = F_104 ( F_364 ( V_717 ) |
V_718 | V_724 ) ;
V_34 = F_366 ( V_1 , V_1 -> V_188 , & V_750 , sizeof( V_750 ) ,
NULL ) ;
if ( V_34 < 0 )
goto V_760;
V_34 = F_378 ( V_1 ) ;
if ( V_34 < 0 )
goto V_760;
V_1 -> V_45 |= V_772 ;
V_34 = F_367 ( V_1 , V_1 -> V_188 ,
V_725 ,
V_726 |
V_773 |
( ( V_1 -> V_45 & V_772 ) ?
V_727 : 0 ) ) ;
if ( V_34 < 0 )
goto V_760;
V_34 = F_368 ( V_1 , V_1 -> V_188 , V_1 -> V_41 , 0 ,
V_774 , V_775 ,
V_776 , V_777 ,
V_778 , V_779 ,
V_780 ,
F_1 ( V_1 , V_1 -> V_41 , 0 ) ,
V_781 ,
V_782 , V_783 ) ;
if ( V_34 < 0 )
goto V_760;
for ( V_125 = 0 ; V_125 < V_401 - 1 ; V_125 ++ )
V_13 -> V_398 [ V_125 ] = F_214 ( V_784 [ V_125 ] , V_785 ) ;
V_13 -> V_398 [ V_401 - 1 ] = V_785 ;
V_13 -> V_400 [ 0 ] = 1 ;
for ( V_125 = 1 ; V_125 < V_786 ; V_125 ++ )
V_13 -> V_400 [ V_125 ] = F_214 ( V_787 [ V_125 - 1 ] ,
F_393 ( V_788 ) ) ;
F_369 ( V_1 ) ;
#ifdef F_394
{
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < F_11 ( V_789 ) ; V_2 ++ ) {
if ( V_789 [ V_2 ] <= 0 )
continue;
for ( V_3 = 1 ; V_3 <= V_789 [ V_2 ] ; V_3 ++ ) {
V_34 = F_368 ( V_1 , V_1 -> V_188 ,
V_2 , V_3 ,
V_790 , V_791 ,
V_792 , V_793 ,
V_794 , V_795 ,
V_780 ,
F_1 (
V_1 , V_2 , V_3 ) ,
V_796 ,
V_797 , V_798 ) ;
if ( V_34 < 0 )
F_309 ( V_1 -> V_68 ,
L_53\
L_54
L_55 , V_2 , V_3 , V_34 ) ;
}
}
}
#endif
if ( V_799 != V_800 ) {
int V_126 , V_801 = 0 ;
for ( V_126 = V_802 ; V_126 <= V_803 ; V_126 ++ )
switch ( V_799 & ( 1 << V_126 ) ) {
case 0 :
break;
case V_804 :
V_801 += 1 ;
break;
case V_805 :
V_801 += 3 ;
break;
case V_806 :
V_801 += 17 ;
break;
case V_807 :
V_801 += 17 ;
break;
case V_808 :
V_801 += 8 ;
break;
case V_809 :
V_801 += 8 ;
break;
case V_810 :
V_801 += 16 ;
break;
case V_811 :
V_801 += 9 ;
break;
case V_812 :
V_801 += 3 ;
break;
case V_813 :
V_801 += 1 ;
break;
}
if ( V_801 > 36 ) {
F_30 ( V_1 -> V_68 ,
L_56\
L_57 , V_799 , V_801 ,
V_800 ) ;
V_799 = V_800 ;
}
}
V_120 = V_799 ;
F_371 ( V_1 , V_733 , V_735 ,
& V_120 , 1 , V_814 ) ;
if ( V_799 )
F_300 ( V_1 , V_815 ,
V_816 ,
V_816 ) ;
F_49 ( V_1 , V_730 , F_395 ( 6 ) |
F_396 ( 4 ) | F_397 ( 15 ) |
F_398 ( 8 ) | F_399 ( 8 ) |
F_400 ( 4 ) | F_401 ( 9 ) ) ;
V_34 = F_391 ( V_1 , V_1 -> V_188 ) ;
if ( V_34 < 0 )
goto V_760;
F_87 ( V_1 -> V_68 , L_58\
L_59 ) ;
return 0 ;
V_760:
return V_34 ;
}
static int F_402 ( struct V_1 * V_24 )
{
int V_34 ;
T_6 V_120 , V_817 ;
enum V_818 V_307 ;
T_6 V_7 [ 7 ] , V_224 [ 7 ] ;
struct V_715 V_750 ;
int V_749 = 1 , V_126 ;
V_34 = F_403 ( V_24 , V_24 -> V_188 , V_24 -> V_41 ,
V_819 ? V_820 : V_821 ,
& V_307 ) ;
if ( V_34 < 0 ) {
F_30 ( V_24 -> V_68 , L_60 ,
V_34 ) ;
return V_34 ;
}
if ( V_34 == V_24 -> V_188 )
V_24 -> V_45 |= V_822 ;
if ( V_819 && V_307 == V_823 )
V_307 = V_824 ;
V_34 = F_404 ( V_24 ) ;
if ( ( V_24 -> V_45 & V_822 ) && V_307 != V_823 ) {
if ( V_34 == - V_185 || V_34 > 0 ) {
if ( F_84 ( V_24 ) >= 0 ) {
V_749 = 0 ;
V_34 = F_404 ( V_24 ) ;
}
}
if ( V_34 < 0 )
return V_34 ;
}
V_34 = F_405 ( V_24 , & V_24 -> V_7 . V_825 ) ;
if ( V_34 < 0 )
goto V_760;
V_120 =
F_183 ( V_764 ) |
F_184 ( V_826 ) ;
V_34 = F_385 ( V_24 , V_24 -> V_188 , V_24 -> V_41 , 0 , 1 , & V_120 , & V_817 ) ;
if ( V_34 < 0 )
goto V_760;
V_24 -> V_7 . V_8 = F_406 ( V_817 ) ;
V_24 -> V_7 . V_5 = V_817 ;
if ( V_307 == V_823 ) {
F_87 ( V_24 -> V_68 , L_61\
L_62 ,
V_24 -> V_45 & V_822 ? L_63 : L_64 ) ;
V_24 -> V_45 |= V_770 ;
} else {
F_87 ( V_24 -> V_68 , L_65\
L_66 ) ;
if ( V_34 < 0 )
F_309 ( V_24 -> V_68 , L_67
L_68 ) ;
if ( V_827 )
V_34 = F_392 ( V_24 , V_749 ) ;
else {
V_7 [ 0 ] = ( F_183 ( V_764 ) |
F_184 ( V_765 ) ) ;
V_34 = F_385 ( V_24 , V_24 -> V_188 , V_24 -> V_41 , 0 , 1 ,
V_7 , V_224 ) ;
if ( V_34 < 0 )
V_34 = F_392 ( V_24 , V_749 ) ;
else {
V_34 = F_382 ( V_24 , V_749 ) ;
if ( V_34 == - V_771 ) {
F_87 ( V_24 -> V_68 ,
L_69
L_70
L_71 ) ;
V_34 = F_392 ( V_24 , V_749 ) ;
}
}
}
if ( V_34 < 0 ) {
F_30 ( V_24 -> V_68 ,
L_72 ,
- V_34 ) ;
goto V_760;
}
}
if ( V_24 -> V_45 & V_770 ) {
V_34 = F_369 ( V_24 ) ;
if ( V_34 < 0 )
goto V_760;
}
if ( F_407 ( V_24 -> V_117 -> V_181 ) )
V_24 -> V_7 . V_828 = 1 ;
#define F_408 ( T_14 ) \
(FW_PARAMS_MNEM(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X(FW_PARAMS_PARAM_DEV_##param))
#define F_409 ( T_14 ) \
FW_PARAMS_MNEM(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y(0) | \
FW_PARAMS_PARAM_Z(0)
V_7 [ 0 ] = F_409 ( V_829 ) ;
V_7 [ 1 ] = F_409 ( V_830 ) ;
V_7 [ 2 ] = F_409 ( V_831 ) ;
V_7 [ 3 ] = F_409 ( V_832 ) ;
V_7 [ 4 ] = F_409 ( V_833 ) ;
V_7 [ 5 ] = F_409 ( V_834 ) ;
V_34 = F_385 ( V_24 , V_24 -> V_188 , V_24 -> V_41 , 0 , 6 , V_7 , V_224 ) ;
if ( V_34 < 0 )
goto V_760;
V_24 -> V_87 . V_89 = V_224 [ 0 ] ;
V_24 -> V_835 = V_224 [ 1 ] ;
V_24 -> V_836 = V_224 [ 2 ] ;
V_24 -> V_60 . V_61 = V_224 [ 3 ] ;
V_24 -> V_60 . V_62 = V_224 [ 4 ] - V_224 [ 3 ] + 1 ;
V_24 -> V_87 . V_154 = V_224 [ 5 ] ;
V_7 [ 0 ] = F_409 ( V_837 ) ;
V_7 [ 1 ] = F_409 ( V_838 ) ;
V_34 = F_385 ( V_24 , V_24 -> V_188 , V_24 -> V_41 , 0 , 2 , V_7 , V_224 ) ;
if ( ( V_224 [ 0 ] != V_224 [ 1 ] ) && ( V_34 >= 0 ) ) {
V_24 -> V_45 |= V_624 ;
V_24 -> V_60 . V_839 = V_224 [ 0 ] ;
V_24 -> V_60 . V_840 = V_224 [ 1 ] ;
}
memset ( & V_750 , 0 , sizeof( V_750 ) ) ;
V_750 . V_716 = F_104 ( F_364 ( V_717 ) |
V_718 | V_719 ) ;
V_750 . V_720 = F_104 ( F_365 ( V_750 ) ) ;
V_34 = F_366 ( V_24 , V_24 -> V_188 , & V_750 , sizeof( V_750 ) ,
& V_750 ) ;
if ( V_34 < 0 )
goto V_760;
if ( V_750 . V_841 ) {
V_7 [ 0 ] = F_408 ( V_842 ) ;
V_7 [ 1 ] = F_409 ( V_843 ) ;
V_7 [ 2 ] = F_409 ( V_844 ) ;
V_7 [ 3 ] = F_409 ( V_845 ) ;
V_7 [ 4 ] = F_409 ( V_846 ) ;
V_7 [ 5 ] = F_408 ( V_847 ) ;
V_34 = F_385 ( V_24 , V_24 -> V_188 , V_24 -> V_41 , 0 , 6 ,
V_7 , V_224 ) ;
if ( V_34 < 0 )
goto V_760;
V_24 -> V_60 . V_527 = V_224 [ 0 ] ;
V_24 -> V_60 . V_526 = F_214 ( V_24 -> V_60 . V_527 / 2 , V_848 ) ;
V_24 -> V_60 . V_506 = V_224 [ 1 ] ;
V_24 -> V_60 . V_504 = V_224 [ 2 ] - V_224 [ 1 ] + 1 ;
if ( V_24 -> V_45 & V_624 && ! F_410 ( V_24 ) ) {
V_24 -> V_60 . V_849 = V_24 -> V_60 . V_61 +
F_411 ( V_24 -> V_60 . V_62 , 3 ) ;
V_24 -> V_60 . V_63 = V_24 -> V_60 . V_62 -
F_411 ( V_24 -> V_60 . V_62 , 3 ) ;
V_24 -> V_60 . V_62 = V_24 -> V_60 . V_849 -
V_24 -> V_60 . V_61 ;
}
V_24 -> V_598 . V_850 . V_299 = V_224 [ 3 ] ;
V_24 -> V_598 . V_850 . V_189 = V_224 [ 4 ] - V_224 [ 3 ] + 1 ;
V_24 -> V_7 . V_606 = V_224 [ 5 ] ;
V_24 -> V_7 . V_262 = 1 ;
}
if ( V_750 . V_851 ) {
V_7 [ 0 ] = F_409 ( V_852 ) ;
V_7 [ 1 ] = F_409 ( V_853 ) ;
V_7 [ 2 ] = F_409 ( V_854 ) ;
V_7 [ 3 ] = F_409 ( V_855 ) ;
V_7 [ 4 ] = F_409 ( V_856 ) ;
V_7 [ 5 ] = F_409 ( V_857 ) ;
V_34 = F_385 ( V_24 , V_24 -> V_188 , V_24 -> V_41 , 0 , 6 ,
V_7 , V_224 ) ;
if ( V_34 < 0 )
goto V_760;
V_24 -> V_598 . V_858 . V_299 = V_224 [ 0 ] ;
V_24 -> V_598 . V_858 . V_189 = V_224 [ 1 ] - V_224 [ 0 ] + 1 ;
V_24 -> V_598 . V_414 . V_299 = V_224 [ 2 ] ;
V_24 -> V_598 . V_414 . V_189 = V_224 [ 3 ] - V_224 [ 2 ] + 1 ;
V_24 -> V_598 . V_859 . V_299 = V_224 [ 4 ] ;
V_24 -> V_598 . V_859 . V_189 = V_224 [ 5 ] - V_224 [ 4 ] + 1 ;
V_7 [ 0 ] = F_409 ( V_860 ) ;
V_7 [ 1 ] = F_409 ( V_861 ) ;
V_7 [ 2 ] = F_409 ( V_862 ) ;
V_7 [ 3 ] = F_409 ( V_863 ) ;
V_7 [ 4 ] = F_409 ( V_864 ) ;
V_7 [ 5 ] = F_409 ( V_865 ) ;
V_34 = F_385 ( V_24 , 0 , 0 , 0 , 6 , V_7 , V_224 ) ;
if ( V_34 < 0 )
goto V_760;
V_24 -> V_598 . V_866 . V_299 = V_224 [ 0 ] ;
V_24 -> V_598 . V_866 . V_189 = V_224 [ 1 ] - V_224 [ 0 ] + 1 ;
V_24 -> V_598 . V_867 . V_299 = V_224 [ 2 ] ;
V_24 -> V_598 . V_867 . V_189 = V_224 [ 3 ] - V_224 [ 2 ] + 1 ;
V_24 -> V_598 . V_712 . V_299 = V_224 [ 4 ] ;
V_24 -> V_598 . V_712 . V_189 = V_224 [ 5 ] - V_224 [ 4 ] + 1 ;
}
if ( V_750 . V_868 ) {
V_7 [ 0 ] = F_409 ( V_869 ) ;
V_7 [ 1 ] = F_409 ( V_870 ) ;
V_34 = F_385 ( V_24 , V_24 -> V_188 , V_24 -> V_41 , 0 , 2 ,
V_7 , V_224 ) ;
if ( V_34 < 0 )
goto V_760;
V_24 -> V_598 . V_871 . V_299 = V_224 [ 0 ] ;
V_24 -> V_598 . V_871 . V_189 = V_224 [ 1 ] - V_224 [ 0 ] + 1 ;
}
#undef F_409
#undef F_408
V_120 = F_47 ( V_24 , V_872 ) ;
V_24 -> V_7 . V_737 . V_873 = F_412 ( V_120 ) ;
V_24 -> V_7 . V_737 . V_874 = F_413 ( V_120 ) ;
F_414 ( V_24 , V_24 -> V_7 . V_542 , NULL ) ;
F_415 ( V_24 , V_24 -> V_7 . V_542 , V_24 -> V_7 . V_875 ,
V_24 -> V_7 . V_876 ) ;
for ( V_126 = 0 ; V_126 < V_616 ; V_126 ++ )
V_24 -> V_7 . V_737 . V_617 [ V_126 ] = V_126 ;
F_416 ( V_24 , V_733 , V_735 ,
& V_24 -> V_615 , 1 ,
V_814 ) ;
V_24 -> V_45 |= V_877 ;
return 0 ;
V_760:
if ( V_34 != - V_878 && V_34 != - V_879 )
F_417 ( V_24 , V_24 -> V_188 ) ;
return V_34 ;
}
static T_15 F_418 ( struct V_546 * V_117 ,
T_16 V_307 )
{
int V_125 ;
struct V_1 * V_24 = F_260 ( V_117 ) ;
if ( ! V_24 )
goto V_186;
F_419 () ;
V_24 -> V_45 &= ~ V_877 ;
F_319 ( V_24 , V_880 ) ;
F_52 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_125 ] ;
F_420 ( V_11 ) ;
F_9 ( V_11 ) ;
}
if ( V_24 -> V_45 & V_392 )
F_327 ( V_24 ) ;
F_421 () ;
F_422 ( V_117 ) ;
V_186: return V_307 == V_881 ?
V_882 : V_883 ;
}
static T_15 F_423 ( struct V_546 * V_117 )
{
int V_125 , V_34 ;
struct V_715 V_410 ;
struct V_1 * V_24 = F_260 ( V_117 ) ;
if ( ! V_24 ) {
F_424 ( V_117 ) ;
F_425 ( V_117 ) ;
return V_884 ;
}
if ( F_426 ( V_117 ) ) {
F_30 ( & V_117 -> V_11 , L_73 ) ;
return V_882 ;
}
F_427 ( V_117 ) ;
F_424 ( V_117 ) ;
F_425 ( V_117 ) ;
F_428 ( V_117 ) ;
if ( F_429 ( V_24 ) < 0 )
return V_882 ;
if ( F_403 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , V_820 , NULL ) )
return V_882 ;
V_24 -> V_45 |= V_877 ;
if ( F_363 ( V_24 , & V_410 ) )
return V_882 ;
F_52 (adap, i) {
struct V_14 * V_15 = F_65 ( V_24 , V_125 ) ;
V_34 = F_430 ( V_24 , V_24 -> V_41 , V_15 -> V_52 , V_24 -> V_41 , 0 , 1 ,
NULL , NULL ) ;
if ( V_34 < 0 )
return V_882 ;
V_15 -> V_42 = V_34 ;
V_15 -> V_50 = - 1 ;
}
F_415 ( V_24 , V_24 -> V_7 . V_542 , V_24 -> V_7 . V_875 ,
V_24 -> V_7 . V_876 ) ;
F_354 ( V_24 ) ;
if ( F_323 ( V_24 ) )
return V_882 ;
return V_884 ;
}
static void F_431 ( struct V_546 * V_117 )
{
int V_125 ;
struct V_1 * V_24 = F_260 ( V_117 ) ;
if ( ! V_24 )
return;
F_419 () ;
F_52 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_125 ] ;
if ( F_7 ( V_11 ) ) {
F_21 ( V_11 ) ;
F_347 ( V_11 ) ;
}
F_432 ( V_11 ) ;
}
F_421 () ;
}
static inline bool F_433 ( const struct V_364 * V_365 )
{
return ( V_365 -> V_357 & V_319 ) != 0 ;
}
static inline void F_434 ( struct V_74 * V_75 , T_3 V_885 , T_3 V_886 ,
unsigned int V_189 , unsigned int V_887 )
{
V_75 -> V_160 = F_187 ( V_885 ) |
( V_886 < V_786 ? V_408 : 0 ) ;
V_75 -> V_405 = V_886 < V_786 ? V_886 : 0 ;
V_75 -> V_888 = V_887 ;
V_75 -> V_189 = V_189 ;
}
static void F_435 ( struct V_1 * V_24 )
{
struct V_87 * V_13 = & V_24 -> V_87 ;
int V_125 , V_889 = 0 , V_890 = 0 , V_891 = 0 ;
F_52 (adap, i)
V_890 += F_433 ( & F_65 ( V_24 , V_125 ) -> V_16 ) ;
if ( V_890 )
V_889 = ( V_892 - ( V_24 -> V_7 . V_8 - V_890 ) ) / V_890 ;
if ( V_889 > F_436 () )
V_889 = F_436 () ;
F_52 (adap, i) {
struct V_14 * V_26 = F_65 ( V_24 , V_125 ) ;
V_26 -> V_149 = V_891 ;
V_26 -> V_133 = F_433 ( & V_26 -> V_16 ) ? V_889 : 1 ;
V_891 += V_26 -> V_133 ;
}
V_13 -> V_893 = V_891 ;
V_13 -> V_894 = V_891 ;
if ( F_147 ( V_24 ) ) {
if ( V_890 ) {
V_125 = F_437 ( int , F_11 ( V_13 -> V_144 ) ,
F_438 () ) ;
V_13 -> V_171 = F_439 ( V_125 , V_24 -> V_7 . V_8 ) ;
} else
V_13 -> V_171 = V_24 -> V_7 . V_8 ;
V_13 -> V_601 = V_24 -> V_7 . V_8 ;
}
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_142 ) ; V_125 ++ ) {
struct V_148 * V_411 = & V_13 -> V_142 [ V_125 ] ;
F_434 ( & V_411 -> V_106 , 0 , 0 , 1024 , 64 ) ;
V_411 -> V_169 . V_189 = 72 ;
}
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_168 ) ; V_125 ++ )
V_13 -> V_168 [ V_125 ] . V_75 . V_189 = 1024 ;
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_174 ) ; V_125 ++ )
V_13 -> V_174 [ V_125 ] . V_75 . V_189 = 512 ;
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_91 ) ; V_125 ++ )
V_13 -> V_91 [ V_125 ] . V_75 . V_189 = 1024 ;
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_144 ) ; V_125 ++ ) {
struct V_104 * V_411 = & V_13 -> V_144 [ V_125 ] ;
F_434 ( & V_411 -> V_106 , 0 , 0 , 1024 , 64 ) ;
V_411 -> V_106 . V_108 = V_602 ;
V_411 -> V_169 . V_189 = 72 ;
}
for ( V_125 = 0 ; V_125 < F_11 ( V_13 -> V_145 ) ; V_125 ++ ) {
struct V_104 * V_411 = & V_13 -> V_145 [ V_125 ] ;
F_434 ( & V_411 -> V_106 , 0 , 0 , 511 , 64 ) ;
V_411 -> V_106 . V_108 = V_581 ;
V_411 -> V_169 . V_189 = 72 ;
}
F_434 ( & V_13 -> V_141 , 6 , 0 , 512 , 64 ) ;
F_434 ( & V_13 -> V_165 , 6 , 0 , 2 * V_728 , 64 ) ;
}
static void F_440 ( struct V_1 * V_24 , int V_128 )
{
int V_125 ;
struct V_14 * V_26 ;
while ( V_128 < V_24 -> V_87 . V_893 )
F_52 (adap, i) {
V_26 = F_65 ( V_24 , V_125 ) ;
if ( V_26 -> V_133 > 1 ) {
V_26 -> V_133 -- ;
V_24 -> V_87 . V_893 -- ;
if ( V_24 -> V_87 . V_893 <= V_128 )
break;
}
}
V_128 = 0 ;
F_52 (adap, i) {
V_26 = F_65 ( V_24 , V_125 ) ;
V_26 -> V_149 = V_128 ;
V_128 += V_26 -> V_133 ;
}
}
static int F_441 ( struct V_1 * V_24 )
{
int V_895 = 0 ;
int V_125 , V_134 , V_896 , V_897 ;
struct V_87 * V_13 = & V_24 -> V_87 ;
unsigned int V_604 = V_24 -> V_7 . V_8 ;
struct V_898 V_899 [ V_728 + 1 ] ;
for ( V_125 = 0 ; V_125 < F_11 ( V_899 ) ; ++ V_125 )
V_899 [ V_125 ] . V_900 = V_125 ;
V_896 = V_13 -> V_894 + V_901 ;
if ( F_147 ( V_24 ) ) {
V_896 += V_13 -> V_601 + V_13 -> V_171 ;
V_895 = 2 * V_604 ;
}
V_897 = V_24 -> V_7 . V_8 + V_901 + V_895 ;
while ( ( V_134 = F_442 ( V_24 -> V_117 , V_899 , V_896 ) ) >= V_897 )
V_896 = V_134 ;
if ( ! V_134 ) {
V_125 = V_896 - V_901 - V_895 ;
if ( V_125 < V_13 -> V_894 ) {
V_13 -> V_894 = V_125 ;
if ( V_125 < V_13 -> V_893 )
F_440 ( V_24 , V_125 ) ;
}
if ( F_147 ( V_24 ) ) {
V_125 = V_896 - V_901 - V_13 -> V_894 ;
V_125 -= V_895 - V_604 ;
V_13 -> V_171 = ( V_125 / V_604 ) * V_604 ;
}
for ( V_125 = 0 ; V_125 < V_896 ; ++ V_125 )
V_24 -> V_129 [ V_125 ] . V_139 = V_899 [ V_125 ] . V_902 ;
} else if ( V_134 > 0 )
F_87 ( V_24 -> V_68 ,
L_74 , V_134 ) ;
return V_134 ;
}
static int F_443 ( struct V_1 * V_24 )
{
unsigned int V_125 , V_126 ;
F_52 (adap, i) {
struct V_14 * V_26 = F_65 ( V_24 , V_125 ) ;
V_26 -> V_147 = F_444 ( V_26 -> V_150 , sizeof( T_2 ) , V_151 ) ;
if ( ! V_26 -> V_147 )
return - V_152 ;
for ( V_126 = 0 ; V_126 < V_26 -> V_150 ; V_126 ++ )
V_26 -> V_147 [ V_126 ] = F_445 ( V_126 , V_26 -> V_133 ) ;
}
return 0 ;
}
static void F_446 ( const struct V_10 * V_11 )
{
static const char * V_903 [] = {
L_75 , L_76 , L_77 , L_78 , L_79 , L_80 , L_81 ,
L_82 , L_83 , L_84 , L_85 , L_86
} ;
char V_298 [ 80 ] ;
char * V_904 = V_298 ;
const char * V_905 = L_87 ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_1 * V_24 = V_26 -> V_1 ;
if ( V_24 -> V_7 . V_906 . V_17 == V_907 )
V_905 = L_88 ;
else if ( V_24 -> V_7 . V_906 . V_17 == V_908 )
V_905 = L_89 ;
if ( V_26 -> V_16 . V_357 & V_315 )
V_904 += sprintf ( V_904 , L_90 ) ;
if ( V_26 -> V_16 . V_357 & V_317 )
V_904 += sprintf ( V_904 , L_91 ) ;
if ( V_26 -> V_16 . V_357 & V_319 )
V_904 += sprintf ( V_904 , L_92 ) ;
if ( V_904 != V_298 )
-- V_904 ;
sprintf ( V_904 , L_93 , V_903 [ V_26 -> V_342 ] ) ;
F_4 ( V_11 , L_94 ,
V_24 -> V_7 . V_825 . V_909 , V_24 -> V_7 . V_297 , V_298 ,
F_147 ( V_24 ) ? L_95 : L_87 , V_24 -> V_7 . V_906 . V_910 , V_905 ,
( V_24 -> V_45 & V_116 ) ? L_96 :
( V_24 -> V_45 & V_118 ) ? L_97 : L_87 ) ;
F_4 ( V_11 , L_98 ,
V_24 -> V_7 . V_825 . V_911 , V_24 -> V_7 . V_825 . V_912 ) ;
}
static void F_447 ( struct V_546 * V_11 )
{
F_448 ( V_11 , V_913 , V_914 ) ;
}
static void F_449 ( struct V_1 * V_1 )
{
unsigned int V_125 ;
F_96 ( V_1 -> V_55 ) ;
F_96 ( V_1 -> V_60 . V_514 ) ;
F_43 ( V_1 ) ;
F_52 (adapter, i)
if ( V_1 -> V_23 [ V_125 ] ) {
F_63 ( F_65 ( V_1 , V_125 ) -> V_147 ) ;
F_450 ( V_1 -> V_23 [ V_125 ] ) ;
}
if ( V_1 -> V_45 & V_877 )
F_417 ( V_1 , V_1 -> V_41 ) ;
}
static int F_451 ( struct V_546 * V_117 , const struct V_915 * V_916 )
{
int V_917 , V_125 , V_134 ;
struct V_14 * V_26 ;
bool V_918 = false ;
struct V_1 * V_1 = NULL ;
F_452 ( V_919 L_99 , V_920 , V_275 ) ;
V_134 = F_453 ( V_117 , V_273 ) ;
if ( V_134 ) {
F_87 ( & V_117 -> V_11 , L_100 ) ;
return V_134 ;
}
V_917 = F_454 ( V_117 -> V_921 ) ;
if ( V_917 != V_916 -> V_922 ) {
F_425 ( V_117 ) ;
goto V_923;
}
V_134 = F_426 ( V_117 ) ;
if ( V_134 ) {
F_30 ( & V_117 -> V_11 , L_101 ) ;
goto V_924;
}
if ( ! F_455 ( V_117 , F_456 ( 64 ) ) ) {
V_918 = true ;
V_134 = F_457 ( V_117 , F_456 ( 64 ) ) ;
if ( V_134 ) {
F_30 ( & V_117 -> V_11 , L_102
L_103 ) ;
goto V_925;
}
} else {
V_134 = F_455 ( V_117 , F_456 ( 32 ) ) ;
if ( V_134 ) {
F_30 ( & V_117 -> V_11 , L_104 ) ;
goto V_925;
}
}
F_458 ( V_117 ) ;
F_447 ( V_117 ) ;
F_427 ( V_117 ) ;
F_425 ( V_117 ) ;
V_1 = F_94 ( sizeof( * V_1 ) , V_151 ) ;
if ( ! V_1 ) {
V_134 = - V_152 ;
goto V_925;
}
V_1 -> V_302 = F_459 ( V_117 , 0 ) ;
if ( ! V_1 -> V_302 ) {
F_30 ( & V_117 -> V_11 , L_105 ) ;
V_134 = - V_152 ;
goto V_926;
}
V_1 -> V_117 = V_117 ;
V_1 -> V_68 = & V_117 -> V_11 ;
V_1 -> V_188 = V_917 ;
V_1 -> V_41 = V_917 ;
V_1 -> V_263 = V_927 ;
memset ( V_1 -> V_928 , 0xff , sizeof( V_1 -> V_928 ) ) ;
F_246 ( & V_1 -> V_550 ) ;
F_246 ( & V_1 -> V_515 ) ;
F_460 ( & V_1 -> V_519 , F_240 ) ;
F_460 ( & V_1 -> V_582 , F_299 ) ;
F_460 ( & V_1 -> V_589 , F_301 ) ;
V_134 = F_461 ( V_1 ) ;
if ( V_134 )
goto V_929;
F_354 ( V_1 ) ;
V_134 = F_402 ( V_1 ) ;
F_360 ( V_1 ) ;
if ( V_134 )
goto V_929;
F_52 (adapter, i) {
struct V_10 * V_156 ;
V_156 = F_462 ( sizeof( struct V_14 ) ,
V_892 ) ;
if ( ! V_156 ) {
V_134 = - V_152 ;
goto V_930;
}
F_463 ( V_156 , & V_117 -> V_11 ) ;
V_1 -> V_23 [ V_125 ] = V_156 ;
V_26 = F_5 ( V_156 ) ;
V_26 -> V_1 = V_1 ;
V_26 -> V_50 = - 1 ;
V_26 -> V_21 = V_125 ;
V_156 -> V_119 = V_117 -> V_119 ;
V_156 -> V_931 = V_932 | V_933 |
V_934 | V_935 |
V_936 | V_937 |
V_938 | V_49 ;
if ( V_918 )
V_156 -> V_931 |= V_939 ;
V_156 -> V_48 |= V_156 -> V_931 ;
V_156 -> V_940 = V_156 -> V_48 & V_941 ;
V_156 -> V_566 |= V_942 ;
V_156 -> V_943 = & V_944 ;
F_464 ( V_156 , & V_945 ) ;
}
F_465 ( V_117 , V_1 ) ;
if ( V_1 -> V_45 & V_877 ) {
V_134 = F_466 ( V_1 , V_917 , V_917 , 0 ) ;
if ( V_134 )
goto V_930;
}
F_435 ( V_1 ) ;
V_1 -> V_55 = F_467 () ;
if ( ! V_1 -> V_55 ) {
F_309 ( & V_117 -> V_11 , L_106 ) ;
V_1 -> V_7 . V_262 = 0 ;
}
if ( F_147 ( V_1 ) && F_244 ( & V_1 -> V_60 ) < 0 ) {
F_309 ( & V_117 -> V_11 , L_107
L_108 ) ;
V_1 -> V_7 . V_262 = 0 ;
}
if ( V_946 > 1 && F_441 ( V_1 ) == 0 )
V_1 -> V_45 |= V_116 ;
else if ( V_946 > 0 && F_468 ( V_117 ) == 0 )
V_1 -> V_45 |= V_118 ;
V_134 = F_443 ( V_1 ) ;
if ( V_134 )
goto V_930;
F_52 (adapter, i) {
V_26 = F_65 ( V_1 , V_125 ) ;
F_469 ( V_1 -> V_23 [ V_125 ] , V_26 -> V_133 ) ;
F_470 ( V_1 -> V_23 [ V_125 ] , V_26 -> V_133 ) ;
V_134 = F_471 ( V_1 -> V_23 [ V_125 ] ) ;
if ( V_134 )
break;
V_1 -> V_928 [ V_26 -> V_52 ] = V_125 ;
F_446 ( V_1 -> V_23 [ V_125 ] ) ;
}
if ( V_125 == 0 ) {
F_30 ( & V_117 -> V_11 , L_109 ) ;
goto V_930;
}
if ( V_134 ) {
F_309 ( & V_117 -> V_11 , L_110 , V_125 ) ;
V_134 = 0 ;
}
if ( V_947 ) {
V_1 -> V_479 = F_472 ( F_156 ( V_117 ) ,
V_947 ) ;
F_218 ( V_1 ) ;
}
V_117 -> V_948 = 1 ;
if ( F_147 ( V_1 ) )
F_313 ( V_1 ) ;
V_923:
#ifdef F_394
if ( V_917 < F_11 ( V_789 ) && V_789 [ V_917 ] > 0 )
if ( F_473 ( V_117 , V_789 [ V_917 ] ) == 0 )
F_87 ( & V_117 -> V_11 ,
L_111 ,
V_789 [ V_917 ] ) ;
#endif
return 0 ;
V_930:
F_449 ( V_1 ) ;
V_929:
F_474 ( V_1 -> V_302 ) ;
V_926:
F_63 ( V_1 ) ;
V_925:
F_475 ( V_117 ) ;
F_422 ( V_117 ) ;
V_924:
F_476 ( V_117 ) ;
F_465 ( V_117 , NULL ) ;
return V_134 ;
}
static void F_477 ( struct V_546 * V_117 )
{
struct V_1 * V_1 = F_260 ( V_117 ) ;
#ifdef F_394
F_478 ( V_117 ) ;
#endif
if ( V_1 ) {
int V_125 ;
if ( F_147 ( V_1 ) )
F_315 ( V_1 ) ;
F_52 (adapter, i)
if ( V_1 -> V_23 [ V_125 ] -> V_949 == V_950 )
F_479 ( V_1 -> V_23 [ V_125 ] ) ;
if ( V_1 -> V_479 )
F_480 ( V_1 -> V_479 ) ;
if ( V_1 -> V_60 . V_65 ) {
struct V_53 * V_54 = & V_1 -> V_60 . V_65 [ 0 ] ;
for ( V_125 = 0 ; V_125 < ( V_1 -> V_60 . V_62 +
V_1 -> V_60 . V_63 ) ; V_125 ++ , V_54 ++ )
if ( V_54 -> V_73 )
F_25 ( V_1 , V_54 ) ;
}
if ( V_1 -> V_45 & V_392 )
F_327 ( V_1 ) ;
F_449 ( V_1 ) ;
F_474 ( V_1 -> V_302 ) ;
F_63 ( V_1 ) ;
F_475 ( V_117 ) ;
F_422 ( V_117 ) ;
F_476 ( V_117 ) ;
F_465 ( V_117 , NULL ) ;
} else
F_476 ( V_117 ) ;
}
static int T_17 F_481 ( void )
{
int V_34 ;
V_518 = F_482 ( L_112 ) ;
if ( ! V_518 )
return - V_152 ;
V_947 = F_472 ( V_273 , NULL ) ;
if ( ! V_947 )
F_483 ( L_113 ) ;
V_34 = F_484 ( & V_568 ) ;
if ( V_34 < 0 )
F_485 ( V_947 ) ;
return V_34 ;
}
static void T_18 F_486 ( void )
{
F_487 ( & V_568 ) ;
F_485 ( V_947 ) ;
F_488 ( V_518 ) ;
F_489 ( V_518 ) ;
}
