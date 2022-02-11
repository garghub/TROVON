static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
F_3 ( V_2 , L_1 ) ;
else {
static const char * V_3 [] = { L_2 , L_3 , L_4 , L_5 } ;
const char * V_4 ;
const struct V_5 * V_6 = F_4 ( V_2 ) ;
switch ( V_6 -> V_7 . V_8 ) {
case 10000 :
V_4 = L_6 ;
break;
case 1000 :
V_4 = L_7 ;
break;
case 100 :
V_4 = L_8 ;
break;
case 40000 :
V_4 = L_9 ;
break;
default:
F_5 ( L_10 ,
V_2 -> V_9 , V_6 -> V_7 . V_8 ) ;
return;
}
F_3 ( V_2 , L_11 , V_4 ,
V_3 [ V_6 -> V_7 . V_3 ] ) ;
}
}
static void F_6 ( struct V_1 * V_2 , int V_10 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_14 * V_15 = & V_13 -> V_16 . V_17 [ V_11 -> V_18 ] ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_15 ++ ) {
T_1 V_9 , V_21 ;
int V_22 ;
V_9 = ( F_7 ( V_23 ) |
F_8 (
V_24 ) |
F_9 ( V_15 -> V_25 . V_26 ) ) ;
V_21 = V_10 ? V_19 : 0xffffffff ;
V_22 = F_10 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_9 , & V_21 ,
- V_29 ) ;
if ( V_22 )
F_11 ( V_13 -> V_30 ,
L_12 ,
V_10 ? L_13 : L_14 , V_11 -> V_31 , V_19 , - V_22 ) ;
else
V_15 -> V_32 = V_21 ;
}
}
void F_12 ( struct V_12 * V_12 , int V_31 , int V_33 )
{
struct V_1 * V_2 = V_12 -> V_34 [ V_31 ] ;
if ( F_13 ( V_2 ) && V_33 != F_2 ( V_2 ) ) {
if ( V_33 )
F_14 ( V_2 ) ;
else {
#ifdef F_15
F_16 ( V_2 ) ;
F_6 ( V_2 , false ) ;
#endif
F_17 ( V_2 ) ;
}
F_1 ( V_2 ) ;
}
}
void F_18 ( const struct V_12 * V_13 , int V_31 )
{
static const char * V_35 [] = {
NULL , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
const struct V_1 * V_2 = V_13 -> V_34 [ V_31 ] ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_11 -> V_36 == V_37 )
F_3 ( V_2 , L_21 ) ;
else if ( V_11 -> V_36 < F_19 ( V_35 ) )
F_3 ( V_2 , L_22 , V_35 [ V_11 -> V_36 ] ) ;
}
static int F_20 ( const struct V_1 * V_2 , bool V_38 )
{
T_2 V_39 = 0 ;
T_2 V_40 = 0 ;
bool free = true ;
T_3 V_41 [ 7 ] ;
const T_4 * V_42 [ 7 ] ;
int V_43 , V_44 = 0 ;
const struct V_45 * V_46 ;
int V_47 = F_21 ( V_2 ) ;
int V_48 = F_22 ( V_2 ) ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_49 = V_11 -> V_12 -> V_28 ;
F_23 (ha, dev) {
V_42 [ V_44 ++ ] = V_46 -> V_42 ;
if ( -- V_47 == 0 || V_44 >= F_19 ( V_42 ) ) {
V_43 = F_24 ( V_11 -> V_12 , V_49 , V_11 -> V_50 , free ,
V_44 , V_42 , V_41 , & V_40 , V_38 ) ;
if ( V_43 < 0 )
return V_43 ;
free = false ;
V_44 = 0 ;
}
}
F_25 (ha, dev) {
V_42 [ V_44 ++ ] = V_46 -> V_42 ;
if ( -- V_48 == 0 || V_44 >= F_19 ( V_42 ) ) {
V_43 = F_24 ( V_11 -> V_12 , V_49 , V_11 -> V_50 , free ,
V_44 , V_42 , V_41 , & V_39 , V_38 ) ;
if ( V_43 < 0 )
return V_43 ;
free = false ;
V_44 = 0 ;
}
}
return F_26 ( V_11 -> V_12 , V_49 , V_11 -> V_50 , V_40 != 0 ,
V_40 | V_39 , V_38 ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_51 , bool V_52 )
{
int V_43 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
V_43 = F_20 ( V_2 , V_52 ) ;
if ( V_43 == 0 )
V_43 = F_28 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_50 , V_51 ,
( V_2 -> V_53 & V_54 ) ? 1 : 0 ,
( V_2 -> V_53 & V_55 ) ? 1 : 0 , 1 , - 1 ,
V_52 ) ;
return V_43 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_43 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_49 = V_11 -> V_12 -> V_28 ;
V_43 = F_28 ( V_11 -> V_12 , V_49 , V_11 -> V_50 , V_2 -> V_51 , - 1 , - 1 , - 1 ,
! ! ( V_2 -> V_56 & V_57 ) , true ) ;
if ( V_43 == 0 ) {
V_43 = F_30 ( V_11 -> V_12 , V_49 , V_11 -> V_50 ,
V_11 -> V_58 , V_2 -> V_59 , true ,
true ) ;
if ( V_43 >= 0 ) {
V_11 -> V_58 = V_43 ;
V_43 = 0 ;
}
}
if ( V_43 == 0 )
V_43 = F_31 ( V_11 -> V_12 , V_49 , V_11 -> V_60 ,
& V_11 -> V_7 ) ;
if ( V_43 == 0 ) {
F_32 () ;
V_43 = F_33 ( V_11 -> V_12 , V_49 , V_11 -> V_50 , true ,
true , V_61 ) ;
F_34 () ;
}
return V_43 ;
}
int F_35 ( const struct V_1 * V_2 )
{
#ifdef F_15
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! V_11 -> V_62 . V_63 )
return 0 ;
return ( ( V_11 -> V_62 . V_64 == V_65 ) ||
( V_11 -> V_62 . V_64 == V_66 ) ) ;
#else
return 0 ;
#endif
}
static void F_36 ( struct V_12 * V_13 , const struct V_67 * V_68 )
{
int V_34 = F_37 ( F_38 ( V_68 -> V_69 ) ) ;
struct V_1 * V_2 = V_13 -> V_34 [ V_34 ] ;
int V_70 = F_35 ( V_2 ) ;
int V_71 ;
F_39 ( V_13 , V_68 ) ;
V_71 = F_35 ( V_2 ) ;
if ( V_71 != V_70 )
F_6 ( V_2 , V_71 ) ;
}
static void F_40 ( struct V_12 * V_13 , struct V_72 * V_73 )
{
if ( V_73 -> V_74 )
F_41 ( V_73 -> V_74 ) ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
}
static void F_42 ( struct V_12 * V_13 , const struct V_75 * V_76 )
{
unsigned int V_77 = F_43 ( V_76 ) ;
unsigned int V_78 = V_77 - V_13 -> V_79 . V_80 ;
unsigned int V_43 ;
struct V_72 * V_73 ;
if ( V_77 >= V_13 -> V_79 . V_80 && V_78 <
( V_13 -> V_79 . V_81 + V_13 -> V_79 . V_82 ) ) {
V_77 = V_78 ;
V_43 = F_44 ( V_76 -> V_83 ) ;
V_73 = & V_13 -> V_79 . V_84 [ V_77 ] ;
if ( V_43 == V_85 ) {
F_40 ( V_13 , V_73 ) ;
} else if ( V_43 == V_86 ) {
F_11 ( V_13 -> V_30 , L_23 ,
V_77 ) ;
F_40 ( V_13 , V_73 ) ;
} else if ( V_43 == V_87 ) {
V_73 -> V_88 = ( F_45 ( V_76 -> V_89 ) >> 24 ) & 0xff ;
V_73 -> V_90 = 0 ;
V_73 -> V_91 = 1 ;
} else {
F_11 ( V_13 -> V_30 , L_24 ,
V_77 , V_43 ) ;
F_40 ( V_13 , V_73 ) ;
}
}
}
static int F_46 ( struct V_92 * V_25 , const T_5 * V_93 ,
const struct V_94 * V_95 )
{
T_4 V_96 = ( ( const struct V_97 * ) V_93 ) -> V_96 ;
V_93 ++ ;
if ( F_47 ( V_96 == V_98 &&
( ( const struct V_99 * ) V_93 ) -> type == V_100 ) ) {
V_93 ++ ;
V_96 = ( ( const struct V_97 * ) V_93 ) -> V_96 ;
V_93 ++ ;
if ( V_96 != V_101 ) {
F_11 ( V_25 -> V_13 -> V_30 , L_25
, V_96 ) ;
goto V_102;
}
}
if ( F_48 ( V_96 == V_101 ) ) {
const struct V_103 * V_6 = ( void * ) V_93 ;
unsigned int V_104 = F_49 ( F_38 ( V_6 -> V_105 ) ) ;
struct V_106 * V_15 ;
V_15 = V_25 -> V_13 -> V_16 . V_107 [ V_104 - V_25 -> V_13 -> V_16 . V_108 ] ;
V_15 -> V_109 ++ ;
if ( ( T_4 * ) V_15 < ( T_4 * ) V_25 -> V_13 -> V_16 . V_110 ) {
struct V_14 * V_111 ;
V_111 = F_50 ( V_15 , struct V_14 , V_25 ) ;
F_51 ( V_111 -> V_15 ) ;
} else {
struct V_112 * V_113 ;
V_113 = F_50 ( V_15 , struct V_112 , V_25 ) ;
F_52 ( & V_113 -> V_114 ) ;
}
} else if ( V_96 == V_115 || V_96 == V_98 ) {
const struct V_116 * V_6 = ( void * ) V_93 ;
#ifdef F_15
const struct V_67 * V_68 = ( const void * ) V_6 -> V_117 ;
unsigned int V_118 = F_53 ( F_38 ( V_68 -> V_69 ) ) ;
unsigned int V_119 =
F_54 ( F_38 ( V_68 -> V_120 ) ) ;
if ( V_118 == V_121 &&
V_119 == V_122 ) {
int V_34 = F_37 (
F_55 ( V_68 -> V_69 ) ) ;
struct V_1 * V_2 = V_25 -> V_13 -> V_34 [ V_34 ] ;
int V_123 = ( ( V_68 -> V_124 . V_125 . V_126 &
V_127 )
? V_128
: V_129 ) ;
F_56 ( V_2 , V_123 ) ;
}
if ( V_118 == V_121 &&
V_119 == V_130 )
F_36 ( V_25 -> V_13 , V_68 ) ;
else
#endif
if ( V_6 -> type == 0 )
F_57 ( V_25 -> V_13 , V_6 -> V_117 ) ;
} else if ( V_96 == V_131 ) {
const struct V_132 * V_6 = ( void * ) V_93 ;
F_58 ( V_25 -> V_13 , V_6 ) ;
} else if ( V_96 == V_133 ) {
const struct V_75 * V_6 = ( void * ) V_93 ;
F_42 ( V_25 -> V_13 , V_6 ) ;
} else
F_11 ( V_25 -> V_13 -> V_30 ,
L_26 , V_96 ) ;
V_102:
return 0 ;
}
static int F_59 ( struct V_92 * V_25 , const T_5 * V_93 ,
const struct V_94 * V_95 )
{
struct V_134 * V_135 = F_50 ( V_25 , struct V_134 , V_136 ) ;
if ( ( ( const struct V_97 * ) V_93 ) -> V_96 == V_98 &&
( ( const struct V_99 * ) ( V_93 + 1 ) ) -> type == V_100 )
V_93 += 2 ;
if ( V_137 [ V_25 -> V_138 ] . F_60 ( V_25 -> V_13 -> V_139 [ V_25 -> V_138 ] , V_93 , V_95 ) ) {
V_135 -> V_140 . V_141 ++ ;
return - 1 ;
}
if ( V_95 == NULL )
V_135 -> V_140 . V_142 ++ ;
else if ( V_95 == V_143 )
V_135 -> V_140 . V_144 ++ ;
else
V_135 -> V_140 . V_145 ++ ;
return 0 ;
}
static void F_61 ( struct V_12 * V_12 )
{
if ( V_12 -> V_53 & V_146 ) {
F_62 ( V_12 -> V_147 ) ;
V_12 -> V_53 &= ~ V_146 ;
} else if ( V_12 -> V_53 & V_148 ) {
F_63 ( V_12 -> V_147 ) ;
V_12 -> V_53 &= ~ V_148 ;
}
}
static T_6 F_64 ( int V_149 , void * V_83 )
{
struct V_12 * V_13 = V_83 ;
T_1 V_150 = F_65 ( V_13 , F_66 ( V_151 ) ) ;
if ( V_150 & V_152 ) {
V_13 -> V_153 = 1 ;
F_67 ( V_13 , F_66 ( V_151 ) , V_150 ) ;
}
if ( V_13 -> V_53 & V_154 )
F_68 ( V_13 ) ;
return V_155 ;
}
static void F_69 ( struct V_12 * V_13 )
{
int V_19 , V_156 , V_157 = 2 , V_158 = sizeof( V_13 -> V_159 [ 0 ] . V_160 ) ;
snprintf ( V_13 -> V_159 [ 0 ] . V_160 , V_158 , L_27 , V_13 -> V_34 [ 0 ] -> V_9 ) ;
snprintf ( V_13 -> V_159 [ 1 ] . V_160 , V_158 , L_28 ,
V_13 -> V_34 [ 0 ] -> V_9 ) ;
F_70 (adap, j) {
struct V_1 * V_161 = V_13 -> V_34 [ V_156 ] ;
const struct V_5 * V_11 = F_4 ( V_161 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_157 ++ )
snprintf ( V_13 -> V_159 [ V_157 ] . V_160 , V_158 , L_29 ,
V_161 -> V_9 , V_19 ) ;
}
F_71 (&adap->sge, i)
snprintf ( V_13 -> V_159 [ V_157 ++ ] . V_160 , V_158 , L_30 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_19 ) ;
F_72 (&adap->sge, i)
snprintf ( V_13 -> V_159 [ V_157 ++ ] . V_160 , V_158 , L_31 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_19 ) ;
F_73 (&adap->sge, i)
snprintf ( V_13 -> V_159 [ V_157 ++ ] . V_160 , V_158 , L_32 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_19 ) ;
}
static int F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 , V_162 , V_163 = 0 , V_164 = 0 , V_165 = 0 ;
int V_166 = 2 ;
V_22 = F_75 ( V_13 -> V_159 [ 1 ] . V_167 , V_168 , 0 ,
V_13 -> V_159 [ 1 ] . V_160 , & V_4 -> V_169 ) ;
if ( V_22 )
return V_22 ;
F_76 (s, ethqidx) {
V_22 = F_75 ( V_13 -> V_159 [ V_166 ] . V_167 ,
V_168 , 0 ,
V_13 -> V_159 [ V_166 ] . V_160 ,
& V_4 -> V_170 [ V_162 ] . V_136 ) ;
if ( V_22 )
goto V_171;
V_166 ++ ;
}
F_71 (s, ofldqidx) {
V_22 = F_75 ( V_13 -> V_159 [ V_166 ] . V_167 ,
V_168 , 0 ,
V_13 -> V_159 [ V_166 ] . V_160 ,
& V_4 -> V_172 [ V_163 ] . V_136 ) ;
if ( V_22 )
goto V_171;
V_166 ++ ;
}
F_72 (s, rdmaqidx) {
V_22 = F_75 ( V_13 -> V_159 [ V_166 ] . V_167 ,
V_168 , 0 ,
V_13 -> V_159 [ V_166 ] . V_160 ,
& V_4 -> V_173 [ V_164 ] . V_136 ) ;
if ( V_22 )
goto V_171;
V_166 ++ ;
}
F_73 (s, rdmaciqqidx) {
V_22 = F_75 ( V_13 -> V_159 [ V_166 ] . V_167 ,
V_168 , 0 ,
V_13 -> V_159 [ V_166 ] . V_160 ,
& V_4 -> V_174 [ V_165 ] . V_136 ) ;
if ( V_22 )
goto V_171;
V_166 ++ ;
}
return 0 ;
V_171:
while ( -- V_165 >= 0 )
F_77 ( V_13 -> V_159 [ -- V_166 ] . V_167 ,
& V_4 -> V_174 [ V_165 ] . V_136 ) ;
while ( -- V_164 >= 0 )
F_77 ( V_13 -> V_159 [ -- V_166 ] . V_167 ,
& V_4 -> V_173 [ V_164 ] . V_136 ) ;
while ( -- V_163 >= 0 )
F_77 ( V_13 -> V_159 [ -- V_166 ] . V_167 ,
& V_4 -> V_172 [ V_163 ] . V_136 ) ;
while ( -- V_162 >= 0 )
F_77 ( V_13 -> V_159 [ -- V_166 ] . V_167 ,
& V_4 -> V_170 [ V_162 ] . V_136 ) ;
F_77 ( V_13 -> V_159 [ 1 ] . V_167 , & V_4 -> V_169 ) ;
return V_22 ;
}
static void F_78 ( struct V_12 * V_13 )
{
int V_19 , V_166 = 2 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_77 ( V_13 -> V_159 [ 1 ] . V_167 , & V_4 -> V_169 ) ;
F_76 (s, i)
F_77 ( V_13 -> V_159 [ V_166 ++ ] . V_167 , & V_4 -> V_170 [ V_19 ] . V_136 ) ;
F_71 (s, i)
F_77 ( V_13 -> V_159 [ V_166 ++ ] . V_167 , & V_4 -> V_172 [ V_19 ] . V_136 ) ;
F_72 (s, i)
F_77 ( V_13 -> V_159 [ V_166 ++ ] . V_167 , & V_4 -> V_173 [ V_19 ] . V_136 ) ;
F_73 (s, i)
F_77 ( V_13 -> V_159 [ V_166 ++ ] . V_167 , & V_4 -> V_174 [ V_19 ] . V_136 ) ;
}
int F_79 ( const struct V_5 * V_11 , const T_3 * V_175 )
{
T_3 * V_176 ;
int V_19 , V_22 ;
struct V_12 * V_12 = V_11 -> V_12 ;
const struct V_177 * V_135 ;
V_135 = & V_12 -> V_16 . V_170 [ V_11 -> V_18 ] ;
V_176 = F_80 ( V_11 -> V_178 * sizeof( T_3 ) , V_179 ) ;
if ( ! V_176 )
return - V_180 ;
for ( V_19 = 0 ; V_19 < V_11 -> V_178 ; V_19 ++ , V_175 ++ )
V_176 [ V_19 ] = V_135 [ * V_175 ] . V_136 . V_181 ;
V_22 = F_81 ( V_12 , V_12 -> V_28 , V_11 -> V_50 , 0 ,
V_11 -> V_178 , V_176 , V_11 -> V_178 ) ;
if ( ! V_22 )
V_22 = F_82 ( V_12 , V_12 -> V_27 , V_11 -> V_50 ,
V_182 |
V_183 |
V_184 |
V_185 |
V_186 ,
V_176 [ 0 ] ) ;
F_83 ( V_176 ) ;
return V_22 ;
}
static int F_84 ( struct V_12 * V_13 )
{
int V_19 , V_156 , V_22 ;
F_70 (adap, i) {
const struct V_5 * V_11 = F_85 ( V_13 , V_19 ) ;
for ( V_156 = 0 ; V_156 < V_11 -> V_178 ; V_156 ++ )
V_11 -> V_176 [ V_156 ] = V_156 % V_11 -> V_20 ;
V_22 = F_79 ( V_11 , V_11 -> V_176 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static unsigned int F_86 ( const struct V_16 * V_6 , unsigned int V_104 )
{
V_104 -= V_6 -> V_187 ;
return F_87 ( V_6 -> V_188 [ V_104 ] -> V_189 ) -> V_60 ;
}
static void F_88 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_190 ; V_19 ++ ) {
struct V_92 * V_25 = V_13 -> V_16 . V_188 [ V_19 ] ;
if ( V_25 && V_25 -> V_191 ) {
F_89 ( & V_25 -> V_192 ) ;
F_32 () ;
while ( ! F_90 ( V_25 ) )
F_91 ( 1 ) ;
F_34 () ;
}
}
}
static void F_92 ( struct V_12 * V_13 )
{
if ( V_13 -> V_53 & V_193 ) {
F_93 ( V_13 ) ;
if ( V_13 -> V_53 & V_146 ) {
F_78 ( V_13 ) ;
F_77 ( V_13 -> V_159 [ 0 ] . V_167 , V_13 ) ;
} else {
F_77 ( V_13 -> V_147 -> V_149 , V_13 ) ;
}
F_88 ( V_13 ) ;
}
}
static void F_94 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_190 ; V_19 ++ ) {
struct V_92 * V_25 = V_13 -> V_16 . V_188 [ V_19 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_191 ) {
F_95 ( V_25 ) ;
F_96 ( & V_25 -> V_192 ) ;
}
F_67 ( V_13 , F_66 ( V_194 ) ,
F_97 ( V_25 -> V_195 ) |
F_98 ( V_25 -> V_26 ) ) ;
}
}
static int F_99 ( struct V_12 * V_13 , struct V_134 * V_25 ,
unsigned int V_196 , unsigned int V_197 , int V_157 ,
T_3 * V_198 )
{
int V_19 , V_22 ;
for ( V_19 = 0 ; V_19 < V_196 ; V_19 ++ , V_25 ++ ) {
if ( V_157 > 0 )
V_157 ++ ;
V_22 = F_100 ( V_13 , & V_25 -> V_136 , false ,
V_13 -> V_34 [ V_19 / V_197 ] ,
V_157 , V_25 -> V_199 . V_200 ? & V_25 -> V_199 : NULL ,
F_59 , 0 ) ;
if ( V_22 )
return V_22 ;
memset ( & V_25 -> V_140 , 0 , sizeof( V_25 -> V_140 ) ) ;
if ( V_198 )
V_198 [ V_19 ] = V_25 -> V_136 . V_181 ;
}
return 0 ;
}
static int F_101 ( struct V_12 * V_13 )
{
int V_22 , V_157 , V_19 , V_156 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_102 ( V_4 -> V_201 , V_4 -> V_202 ) ;
F_102 ( V_4 -> V_203 , V_4 -> V_202 ) ;
if ( V_13 -> V_53 & V_146 )
V_157 = 1 ;
else {
V_22 = F_100 ( V_13 , & V_4 -> V_204 , false , V_13 -> V_34 [ 0 ] , 0 ,
NULL , NULL , - 1 ) ;
if ( V_22 )
return V_22 ;
V_157 = - ( ( int ) V_4 -> V_204 . V_181 + 1 ) ;
}
V_22 = F_100 ( V_13 , & V_4 -> V_169 , true , V_13 -> V_34 [ 0 ] ,
V_157 , NULL , F_46 , - 1 ) ;
if ( V_22 ) {
V_205: F_103 ( V_13 ) ;
return V_22 ;
}
F_70 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_177 * V_25 = & V_4 -> V_170 [ V_11 -> V_18 ] ;
struct V_14 * V_206 = & V_4 -> V_17 [ V_11 -> V_18 ] ;
for ( V_156 = 0 ; V_156 < V_11 -> V_20 ; V_156 ++ , V_25 ++ ) {
if ( V_157 > 0 )
V_157 ++ ;
V_22 = F_100 ( V_13 , & V_25 -> V_136 , false , V_2 ,
V_157 , & V_25 -> V_199 ,
V_207 ,
F_104 ( V_13 ,
V_11 -> V_60 ) ) ;
if ( V_22 )
goto V_205;
V_25 -> V_136 . V_77 = V_156 ;
memset ( & V_25 -> V_140 , 0 , sizeof( V_25 -> V_140 ) ) ;
}
for ( V_156 = 0 ; V_156 < V_11 -> V_20 ; V_156 ++ , V_206 ++ ) {
V_22 = F_105 ( V_13 , V_206 , V_2 ,
F_106 ( V_2 , V_156 ) ,
V_4 -> V_169 . V_26 ) ;
if ( V_22 )
goto V_205;
}
}
V_156 = V_4 -> V_208 / V_13 -> V_209 . V_210 ;
F_71 (s, i) {
V_22 = F_107 ( V_13 , & V_4 -> V_110 [ V_19 ] ,
V_13 -> V_34 [ V_19 / V_156 ] ,
V_4 -> V_169 . V_26 ) ;
if ( V_22 )
goto V_205;
}
#define F_108 ( T_7 , V_196 , V_197 , V_198 ) do { \
err = alloc_ofld_rxqs(adap, firstq, nq, per_chan, msi_idx, ids); \
if (err) \
goto freeout; \
if (msi_idx > 0) \
msi_idx += nq; \
} while (0)
F_108 ( V_4 -> V_172 , V_4 -> V_208 , V_156 , V_4 -> V_211 ) ;
F_108 ( V_4 -> V_173 , V_4 -> V_212 , 1 , V_4 -> V_213 ) ;
V_156 = V_4 -> V_214 / V_13 -> V_209 . V_210 ;
F_108 ( V_4 -> V_174 , V_4 -> V_214 , V_156 , V_4 -> V_215 ) ;
#undef F_108
F_70 (adap, i) {
V_22 = F_109 ( V_13 , & V_4 -> V_216 [ V_19 ] , V_13 -> V_34 [ V_19 ] ,
V_4 -> V_169 . V_26 ,
V_4 -> V_173 [ V_19 ] . V_136 . V_26 ) ;
if ( V_22 )
goto V_205;
}
F_67 ( V_13 , F_110 ( V_13 -> V_209 . V_217 ) ?
V_218 :
V_219 ,
F_111 ( F_87 ( V_13 -> V_34 [ 0 ] ) -> V_60 ) |
F_112 ( V_4 -> V_170 [ 0 ] . V_136 . V_181 ) ) ;
return 0 ;
}
void * F_113 ( T_8 V_200 )
{
void * V_6 = F_114 ( V_200 , V_179 | V_220 ) ;
if ( ! V_6 )
V_6 = F_115 ( V_200 ) ;
return V_6 ;
}
void F_116 ( void * V_42 )
{
F_117 ( V_42 ) ;
}
static int F_118 ( struct V_12 * V_12 , int V_221 )
{
struct V_72 * V_73 = & V_12 -> V_79 . V_84 [ V_221 ] ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
unsigned int V_226 ;
V_223 = F_119 ( sizeof( * V_225 ) , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
if ( V_73 -> V_227 . V_228 || V_73 -> V_227 . V_229 ) {
V_73 -> V_74 = F_120 ( V_12 -> V_74 ) ;
if ( V_73 -> V_74 == NULL ) {
F_121 ( V_223 ) ;
return - V_230 ;
}
if ( F_122 ( V_12 , V_73 -> V_74 , V_73 -> V_227 . V_231 ,
V_73 -> V_227 . V_232 , V_73 -> V_227 . V_233 ) ) {
F_41 ( V_73 -> V_74 ) ;
V_73 -> V_74 = NULL ;
F_121 ( V_223 ) ;
return - V_180 ;
}
}
V_226 = V_12 -> V_79 . V_80 + V_221 ;
V_225 = (struct V_224 * ) F_123 ( V_223 , sizeof( * V_225 ) ) ;
memset ( V_225 , 0 , sizeof( * V_225 ) ) ;
V_225 -> V_234 = F_124 ( F_125 ( V_235 ) ) ;
V_225 -> V_236 = F_124 ( F_126 ( sizeof( * V_225 ) / 16 ) ) ;
V_225 -> V_237 =
F_124 ( F_127 ( V_226 ) |
F_128 ( V_73 -> V_227 . type ) |
F_129 ( 0 ) |
F_130 ( V_73 -> V_227 . V_238 ) ) ;
V_225 -> V_239 =
F_124 ( F_131 ( V_73 -> V_227 . V_240 ) |
F_132 ( V_73 -> V_227 . V_119 == V_241 ) |
F_133 ( V_73 -> V_227 . V_242 ) |
F_134 ( V_73 -> V_227 . V_243 ) |
F_135 ( V_73 -> V_227 . V_244 ) |
F_136 ( V_73 -> V_227 . V_119 == V_245 ) |
F_137 ( V_73 -> V_227 . V_228 ) |
F_138 ( V_73 -> V_227 . V_246 ) |
F_139 ( V_73 -> V_227 . V_229 == V_247 ||
V_73 -> V_227 . V_229 == V_248 ) |
F_140 ( V_73 -> V_227 . V_229 == V_249 ||
V_73 -> V_227 . V_229 == V_248 ) |
F_141 ( V_73 -> V_227 . V_250 ) |
F_142 ( V_73 -> V_227 . V_232 ) |
F_143 ( V_73 -> V_227 . V_251 ) |
F_144 ( V_73 -> V_74 ? V_73 -> V_74 -> V_77 : 0 ) ) ;
V_225 -> V_252 = F_145 ( V_73 -> V_227 . V_253 . V_252 ) ;
V_225 -> V_254 = F_145 ( V_73 -> V_227 . V_255 . V_252 ) ;
V_225 -> V_256 =
( F_146 ( V_73 -> V_227 . V_253 . V_257 ) |
F_147 ( V_73 -> V_227 . V_255 . V_257 ) |
F_148 ( V_73 -> V_227 . V_253 . V_258 ) |
F_149 ( V_73 -> V_227 . V_253 . V_259 ) |
F_150 ( V_73 -> V_227 . V_255 . V_258 ) |
F_151 ( V_73 -> V_227 . V_255 . V_259 ) ) ;
V_225 -> V_260 = 0 ;
V_225 -> V_261 =
F_145 ( F_152 ( 0 ) |
F_153 ( V_12 -> V_16 . V_169 . V_181 ) ) ;
V_225 -> V_262 =
F_124 ( F_154 ( V_73 -> V_227 . V_253 . V_263 ) |
F_155 ( V_73 -> V_227 . V_255 . V_263 ) |
F_156 ( V_73 -> V_227 . V_253 . V_264 ) |
F_157 ( V_73 -> V_227 . V_255 . V_264 ) |
F_158 ( V_73 -> V_227 . V_253 . V_265 ) |
F_159 ( V_73 -> V_227 . V_255 . V_265 ) |
F_160 ( V_73 -> V_227 . V_253 . V_266 ) |
F_161 ( V_73 -> V_227 . V_255 . V_266 ) ) ;
V_225 -> V_267 = V_73 -> V_227 . V_253 . V_268 ;
V_225 -> V_269 = V_73 -> V_227 . V_255 . V_268 ;
V_225 -> V_270 = V_73 -> V_227 . V_253 . V_271 ;
V_225 -> V_272 = V_73 -> V_227 . V_255 . V_271 ;
V_225 -> V_273 = F_145 ( V_73 -> V_227 . V_253 . V_273 ) ;
V_225 -> V_274 = F_145 ( V_73 -> V_227 . V_255 . V_273 ) ;
V_225 -> V_275 = F_145 ( V_73 -> V_227 . V_253 . V_275 ) ;
V_225 -> V_276 = F_145 ( V_73 -> V_227 . V_255 . V_275 ) ;
memcpy ( V_225 -> V_277 , V_73 -> V_227 . V_253 . V_277 , sizeof( V_225 -> V_277 ) ) ;
memcpy ( V_225 -> V_278 , V_73 -> V_227 . V_255 . V_277 , sizeof( V_225 -> V_278 ) ) ;
memcpy ( V_225 -> V_279 , V_73 -> V_227 . V_253 . V_279 , sizeof( V_225 -> V_279 ) ) ;
memcpy ( V_225 -> V_280 , V_73 -> V_227 . V_255 . V_279 , sizeof( V_225 -> V_280 ) ) ;
V_225 -> V_281 = F_145 ( V_73 -> V_227 . V_253 . V_282 ) ;
V_225 -> V_283 = F_145 ( V_73 -> V_227 . V_255 . V_282 ) ;
V_225 -> V_284 = F_145 ( V_73 -> V_227 . V_253 . V_285 ) ;
V_225 -> V_286 = F_145 ( V_73 -> V_227 . V_255 . V_285 ) ;
if ( V_73 -> V_227 . V_246 )
memcpy ( V_225 -> V_287 , V_73 -> V_227 . V_288 , sizeof( V_225 -> V_287 ) ) ;
V_73 -> V_90 = 1 ;
F_162 ( V_223 , V_289 , V_73 -> V_227 . V_253 . V_265 & 0x3 ) ;
F_163 ( V_12 , V_223 ) ;
return 0 ;
}
static int F_164 ( struct V_12 * V_12 , int V_221 )
{
struct V_72 * V_73 = & V_12 -> V_79 . V_84 [ V_221 ] ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
unsigned int V_290 , V_226 ;
V_290 = sizeof( * V_225 ) ;
V_226 = V_12 -> V_79 . V_80 + V_221 ;
V_223 = F_119 ( V_290 , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_225 = (struct V_224 * ) F_123 ( V_223 , V_290 ) ;
F_165 ( V_226 , V_225 , V_12 -> V_16 . V_169 . V_181 ) ;
V_73 -> V_90 = 1 ;
F_166 ( V_12 , V_223 ) ;
return 0 ;
}
static T_3 F_167 ( struct V_1 * V_2 , struct V_222 * V_223 ,
void * V_291 , T_9 V_292 )
{
int V_15 ;
#ifdef F_15
if ( F_35 ( V_2 ) ) {
T_3 V_293 ;
int V_22 ;
V_22 = F_168 ( V_223 , & V_293 ) ;
if ( F_47 ( V_22 ) ) {
if ( F_169 () )
F_170 ( V_2 ,
L_33 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_293 & V_294 ) >> V_295 ;
#ifdef F_171
if ( V_223 -> V_296 == F_145 ( V_297 ) )
V_15 = V_223 -> V_298 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_299 ) {
V_15 = ( F_172 ( V_223 )
? F_173 ( V_223 )
: F_174 () ) ;
while ( F_47 ( V_15 >= V_2 -> V_300 ) )
V_15 -= V_2 -> V_300 ;
return V_15 ;
}
return V_292 ( V_2 , V_223 ) % V_2 -> V_300 ;
}
static int F_175 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_301 , V_302 = 0 , V_303 = V_304 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_305 ) ; V_19 ++ ) {
V_301 = time - V_4 -> V_305 [ V_19 ] ;
if ( V_301 < 0 )
V_301 = - V_301 ;
if ( V_301 < V_303 ) {
V_303 = V_301 ;
V_302 = V_19 ;
}
}
return V_302 ;
}
static int F_176 ( const struct V_16 * V_4 , int V_306 )
{
int V_19 , V_301 , V_302 = 0 , V_303 = V_304 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_307 ) ; V_19 ++ ) {
V_301 = V_306 - V_4 -> V_307 [ V_19 ] ;
if ( V_301 < 0 )
V_301 = - V_301 ;
if ( V_301 < V_303 ) {
V_303 = V_301 ;
V_302 = V_19 ;
}
}
return V_302 ;
}
int F_177 ( struct V_92 * V_25 ,
unsigned int V_308 , unsigned int V_309 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_308 | V_309 ) == 0 )
V_309 = 1 ;
if ( V_309 ) {
int V_22 ;
T_1 V_150 , V_310 ;
V_310 = F_176 ( & V_13 -> V_16 , V_309 ) ;
if ( V_25 -> V_160 && V_25 -> V_311 != V_310 ) {
V_150 = F_7 ( V_23 ) |
F_8 (
V_312 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_178 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_150 , & V_310 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_311 = V_310 ;
}
V_308 = V_308 == 0 ? 6 : F_175 ( & V_13 -> V_16 , V_308 ) ;
V_25 -> V_195 = F_179 ( V_308 ) | F_180 ( V_309 > 0 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , T_10 V_56 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_10 V_313 = V_2 -> V_56 ^ V_56 ;
int V_22 ;
if ( ! ( V_313 & V_57 ) )
return 0 ;
V_22 = F_28 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_50 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_56 & V_57 ) , true ) ;
if ( F_47 ( V_22 ) )
V_2 -> V_56 = V_56 ^ V_57 ;
return V_22 ;
}
static int F_182 ( struct V_12 * V_13 )
{
if ( F_183 ( V_13 -> V_314 ) )
return - 1 ;
#ifdef F_184
F_185 ( V_13 ) ;
#endif
return 0 ;
}
int F_186 ( struct V_315 * V_206 , void * V_117 )
{
int V_316 = - 1 ;
F_187 ( & V_206 -> V_317 ) ;
if ( V_206 -> V_318 ) {
union V_319 * V_6 = V_206 -> V_318 ;
V_316 = ( V_6 - V_206 -> V_320 ) + V_206 -> V_321 ;
V_206 -> V_318 = V_6 -> V_322 ;
V_6 -> V_117 = V_117 ;
V_206 -> V_323 ++ ;
}
F_188 ( & V_206 -> V_317 ) ;
return V_316 ;
}
void F_189 ( struct V_315 * V_206 , unsigned int V_316 )
{
union V_319 * V_6 = & V_206 -> V_320 [ V_316 - V_206 -> V_321 ] ;
F_187 ( & V_206 -> V_317 ) ;
V_6 -> V_322 = V_206 -> V_318 ;
V_206 -> V_318 = V_6 ;
V_206 -> V_323 -- ;
F_188 ( & V_206 -> V_317 ) ;
}
int F_190 ( struct V_315 * V_206 , int V_324 , void * V_117 )
{
int V_325 ;
F_187 ( & V_206 -> V_326 ) ;
if ( V_324 == V_327 ) {
V_325 = F_191 ( V_206 -> V_328 , V_206 -> V_329 ) ;
if ( V_325 < V_206 -> V_329 )
F_192 ( V_325 , V_206 -> V_328 ) ;
else
V_325 = - 1 ;
} else {
V_325 = F_193 ( V_206 -> V_328 , V_206 -> V_329 , 2 ) ;
if ( V_325 < 0 )
V_325 = - 1 ;
}
if ( V_325 >= 0 ) {
V_206 -> V_330 [ V_325 ] . V_117 = V_117 ;
V_325 += V_206 -> V_331 ;
if ( V_324 == V_327 )
V_206 -> V_332 ++ ;
else
V_206 -> V_332 += 4 ;
}
F_188 ( & V_206 -> V_326 ) ;
return V_325 ;
}
int F_194 ( struct V_315 * V_206 , int V_324 , void * V_117 )
{
int V_325 ;
F_187 ( & V_206 -> V_326 ) ;
if ( V_324 == V_327 ) {
V_325 = F_195 ( V_206 -> V_328 ,
V_206 -> V_329 + V_206 -> V_82 , V_206 -> V_329 ) ;
if ( V_325 < ( V_206 -> V_329 + V_206 -> V_82 ) )
F_192 ( V_325 , V_206 -> V_328 ) ;
else
V_325 = - 1 ;
} else {
V_325 = - 1 ;
}
if ( V_325 >= 0 ) {
V_206 -> V_330 [ V_325 ] . V_117 = V_117 ;
V_325 -= V_206 -> V_329 ;
V_325 += V_206 -> V_333 ;
V_206 -> V_334 ++ ;
}
F_188 ( & V_206 -> V_326 ) ;
return V_325 ;
}
void F_196 ( struct V_315 * V_206 , unsigned int V_325 , int V_324 )
{
if ( V_206 -> V_82 && ( V_325 >= V_206 -> V_333 ) ) {
V_325 -= V_206 -> V_333 ;
V_325 += V_206 -> V_329 ;
} else {
V_325 -= V_206 -> V_331 ;
}
F_187 ( & V_206 -> V_326 ) ;
if ( V_324 == V_327 )
F_197 ( V_325 , V_206 -> V_328 ) ;
else
F_198 ( V_206 -> V_328 , V_325 , 2 ) ;
V_206 -> V_330 [ V_325 ] . V_117 = NULL ;
if ( V_325 < V_206 -> V_329 ) {
if ( V_324 == V_327 )
V_206 -> V_332 -- ;
else
V_206 -> V_332 -= 4 ;
} else {
V_206 -> V_334 -- ;
}
F_188 ( & V_206 -> V_326 ) ;
}
static void F_199 ( struct V_222 * V_223 , unsigned int V_335 ,
unsigned int V_336 )
{
struct V_337 * V_338 ;
F_162 ( V_223 , V_339 , V_335 ) ;
V_338 = (struct V_337 * ) F_123 ( V_223 , sizeof( * V_338 ) ) ;
F_200 ( V_338 , V_336 ) ;
F_201 ( V_338 ) = F_124 ( F_202 ( V_340 , V_336 ) ) ;
}
static void F_203 ( struct V_315 * V_206 , unsigned int V_335 ,
unsigned int V_336 )
{
void * * V_6 = & V_206 -> V_341 [ V_336 ] ;
struct V_12 * V_13 = F_50 ( V_206 , struct V_12 , V_79 ) ;
F_187 ( & V_13 -> V_342 ) ;
* V_6 = V_13 -> V_343 ;
V_13 -> V_343 = ( void * * ) ( ( V_344 ) V_6 | V_335 ) ;
if ( ! V_13 -> V_345 ) {
V_13 -> V_345 = true ;
F_204 ( V_13 -> V_346 , & V_13 -> V_347 ) ;
}
F_188 ( & V_13 -> V_342 ) ;
}
static void F_205 ( struct V_348 * V_349 )
{
struct V_222 * V_223 ;
struct V_12 * V_13 ;
V_13 = F_50 ( V_349 , struct V_12 , V_347 ) ;
F_187 ( & V_13 -> V_342 ) ;
while ( V_13 -> V_343 ) {
void * * V_6 = V_13 -> V_343 ;
unsigned int V_335 = ( V_344 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_335 ;
V_13 -> V_343 = * V_6 ;
* V_6 = NULL ;
F_188 ( & V_13 -> V_342 ) ;
while ( ! ( V_223 = F_119 ( sizeof( struct V_337 ) ,
V_179 ) ) )
F_206 ( 1 ) ;
F_199 ( V_223 , V_335 , V_6 - V_13 -> V_79 . V_341 ) ;
F_163 ( V_13 , V_223 ) ;
F_187 ( & V_13 -> V_342 ) ;
}
V_13 -> V_345 = false ;
F_188 ( & V_13 -> V_342 ) ;
}
void F_207 ( struct V_315 * V_206 , unsigned int V_335 , unsigned int V_336 )
{
struct V_222 * V_223 ;
struct V_12 * V_13 = F_50 ( V_206 , struct V_12 , V_79 ) ;
F_208 ( V_336 >= V_206 -> V_350 ) ;
if ( V_206 -> V_341 [ V_336 ] ) {
V_206 -> V_341 [ V_336 ] = NULL ;
if ( V_206 -> V_351 && ( V_336 >= V_206 -> V_351 ) )
F_209 ( & V_206 -> V_352 ) ;
else
F_209 ( & V_206 -> V_353 ) ;
}
V_223 = F_119 ( sizeof( struct V_337 ) , V_354 ) ;
if ( F_48 ( V_223 ) ) {
F_199 ( V_223 , V_335 , V_336 ) ;
F_163 ( V_13 , V_223 ) ;
} else
F_203 ( V_206 , V_335 , V_336 ) ;
}
static int F_210 ( struct V_315 * V_206 )
{
T_8 V_200 ;
unsigned int V_355 ;
unsigned int V_356 = V_206 -> V_356 ;
struct V_12 * V_13 = F_50 ( V_206 , struct V_12 , V_79 ) ;
V_355 = F_211 ( V_206 -> V_329 + V_206 -> V_82 ) ;
V_200 = V_206 -> V_350 * sizeof( * V_206 -> V_341 ) +
V_356 * sizeof( * V_206 -> V_320 ) +
V_206 -> V_329 * sizeof( * V_206 -> V_330 ) +
V_206 -> V_82 * sizeof( * V_206 -> V_330 ) +
V_355 * sizeof( long ) +
V_206 -> V_81 * sizeof( * V_206 -> V_84 ) +
V_206 -> V_82 * sizeof( * V_206 -> V_84 ) ;
V_206 -> V_341 = F_113 ( V_200 ) ;
if ( ! V_206 -> V_341 )
return - V_180 ;
V_206 -> V_320 = (union V_319 * ) & V_206 -> V_341 [ V_206 -> V_350 ] ;
V_206 -> V_330 = (struct V_357 * ) & V_206 -> V_320 [ V_356 ] ;
V_206 -> V_328 = ( unsigned long * ) & V_206 -> V_330 [ V_206 -> V_329 + V_206 -> V_82 ] ;
V_206 -> V_84 = (struct V_72 * ) & V_206 -> V_328 [ V_355 ] ;
F_212 ( & V_206 -> V_326 ) ;
F_212 ( & V_206 -> V_317 ) ;
V_206 -> V_332 = 0 ;
V_206 -> V_334 = 0 ;
V_206 -> V_318 = NULL ;
V_206 -> V_323 = 0 ;
F_213 ( & V_206 -> V_353 , 0 ) ;
F_213 ( & V_206 -> V_352 , 0 ) ;
if ( V_356 ) {
while ( -- V_356 )
V_206 -> V_320 [ V_356 - 1 ] . V_322 = & V_206 -> V_320 [ V_356 ] ;
V_206 -> V_318 = V_206 -> V_320 ;
}
F_102 ( V_206 -> V_328 , V_206 -> V_329 + V_206 -> V_82 ) ;
if ( ! V_206 -> V_331 &&
( F_214 ( V_13 -> V_209 . V_217 ) <= V_358 ) )
F_192 ( 0 , V_206 -> V_328 ) ;
return 0 ;
}
int F_215 ( const struct V_1 * V_2 , unsigned int V_325 ,
T_11 V_359 , T_12 V_360 , T_12 V_231 ,
unsigned int V_361 )
{
unsigned int V_335 ;
struct V_222 * V_223 ;
struct V_12 * V_13 ;
struct V_362 * V_338 ;
int V_43 ;
V_223 = F_119 ( sizeof( * V_338 ) , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_13 = F_216 ( V_2 ) ;
V_338 = (struct V_362 * ) F_123 ( V_223 , sizeof( * V_338 ) ) ;
F_200 ( V_338 , 0 ) ;
F_201 ( V_338 ) = F_124 ( F_202 ( V_363 , V_325 ) ) ;
V_338 -> V_364 = V_360 ;
V_338 -> V_365 = F_145 ( 0 ) ;
V_338 -> V_366 = V_359 ;
V_338 -> V_367 = F_124 ( 0 ) ;
V_335 = F_86 ( & V_13 -> V_16 , V_361 ) ;
V_338 -> V_368 = F_217 ( F_218 ( V_335 ) ) ;
V_338 -> V_369 = F_217 ( F_219 ( V_370 ) |
V_371 | F_220 ( V_361 ) ) ;
V_43 = F_166 ( V_13 , V_223 ) ;
return F_221 ( V_43 ) ;
}
int F_222 ( const struct V_1 * V_2 , unsigned int V_325 ,
const struct V_372 * V_359 , T_12 V_360 ,
unsigned int V_361 )
{
unsigned int V_335 ;
struct V_222 * V_223 ;
struct V_12 * V_13 ;
struct V_373 * V_338 ;
int V_43 ;
V_223 = F_119 ( sizeof( * V_338 ) , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_13 = F_216 ( V_2 ) ;
V_338 = (struct V_373 * ) F_123 ( V_223 , sizeof( * V_338 ) ) ;
F_200 ( V_338 , 0 ) ;
F_201 ( V_338 ) = F_124 ( F_202 ( V_374 , V_325 ) ) ;
V_338 -> V_364 = V_360 ;
V_338 -> V_365 = F_145 ( 0 ) ;
V_338 -> V_375 = * ( T_5 * ) ( V_359 -> V_376 ) ;
V_338 -> V_377 = * ( T_5 * ) ( V_359 -> V_376 + 8 ) ;
V_338 -> V_378 = F_217 ( 0 ) ;
V_338 -> V_379 = F_217 ( 0 ) ;
V_335 = F_86 ( & V_13 -> V_16 , V_361 ) ;
V_338 -> V_368 = F_217 ( F_218 ( V_335 ) ) ;
V_338 -> V_369 = F_217 ( F_219 ( V_370 ) |
V_371 | F_220 ( V_361 ) ) ;
V_43 = F_166 ( V_13 , V_223 ) ;
return F_221 ( V_43 ) ;
}
int F_223 ( const struct V_1 * V_2 , unsigned int V_325 ,
unsigned int V_361 , bool V_380 )
{
struct V_222 * V_223 ;
struct V_12 * V_13 ;
struct V_381 * V_338 ;
int V_43 ;
V_13 = F_216 ( V_2 ) ;
V_223 = F_119 ( sizeof( * V_338 ) , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_338 = (struct V_381 * ) F_123 ( V_223 , sizeof( * V_338 ) ) ;
F_200 ( V_338 , 0 ) ;
F_201 ( V_338 ) = F_124 ( F_202 ( V_382 , V_325 ) ) ;
V_338 -> V_383 = F_145 ( F_224 ( 0 ) | ( V_380 ? F_225 ( 1 ) :
F_225 ( 0 ) ) | F_226 ( V_361 ) ) ;
V_43 = F_166 ( V_13 , V_223 ) ;
return F_221 ( V_43 ) ;
}
unsigned int F_227 ( const unsigned short * V_384 , unsigned short V_51 ,
unsigned int * V_77 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_385 - 1 && V_384 [ V_19 + 1 ] <= V_51 )
++ V_19 ;
if ( V_77 )
* V_77 = V_19 ;
return V_384 [ V_19 ] ;
}
unsigned int F_228 ( const unsigned short * V_384 ,
unsigned short V_386 ,
unsigned short V_387 ,
unsigned short V_388 ,
unsigned int * V_389 )
{
unsigned short V_390 = V_386 + V_387 ;
unsigned short V_391 = V_388 - 1 ;
int V_392 , V_393 ;
for ( V_392 = 0 , V_393 = - 1 ; V_392 < V_385 ; V_392 ++ ) {
unsigned short V_394 = V_384 [ V_392 ] - V_386 ;
if ( ( V_394 & V_391 ) == 0 )
V_393 = V_392 ;
if ( V_392 + 1 < V_385 && V_384 [ V_392 + 1 ] > V_390 )
break;
}
if ( V_392 == V_385 )
V_392 -- ;
if ( V_393 >= 0 &&
V_392 - V_393 <= 1 )
V_392 = V_393 ;
if ( V_389 )
* V_389 = V_392 ;
return V_384 [ V_392 ] ;
}
unsigned int F_229 ( enum V_395 V_217 , unsigned int V_50 )
{
if ( F_214 ( V_217 ) <= V_358 )
return ( ( V_50 & 0x7f ) << 1 ) ;
else
return ( V_50 & 0x7f ) ;
}
unsigned int F_230 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 ) -> V_60 ;
}
unsigned int F_231 ( const struct V_1 * V_2 , int V_396 )
{
struct V_12 * V_13 = F_216 ( V_2 ) ;
T_1 V_397 , V_398 , V_399 , V_400 ;
V_397 = F_65 ( V_13 , V_401 ) ;
V_398 = F_65 ( V_13 , V_402 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
V_399 = F_232 ( V_397 ) ;
V_400 = F_233 ( V_397 ) ;
} else {
V_399 = F_234 ( V_397 ) ;
V_400 = F_235 ( V_398 ) ;
}
return V_396 ? V_399 : V_400 ;
}
unsigned int F_236 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 ) -> V_50 ;
}
unsigned int F_237 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 ) -> V_31 ;
}
void F_238 ( struct V_403 * V_147 , struct V_404 * V_405 ,
struct V_404 * V_406 )
{
struct V_12 * V_13 = F_239 ( V_147 ) ;
F_240 ( & V_13 -> V_407 ) ;
F_241 ( V_13 , V_405 , V_406 ) ;
F_242 ( & V_13 -> V_407 ) ;
}
void F_243 ( struct V_1 * V_2 , unsigned int V_408 ,
const unsigned int * V_409 )
{
struct V_12 * V_13 = F_216 ( V_2 ) ;
F_67 ( V_13 , V_410 , V_408 ) ;
F_67 ( V_13 , V_411 , F_244 ( V_409 [ 0 ] ) |
F_245 ( V_409 [ 1 ] ) | F_246 ( V_409 [ 2 ] ) |
F_247 ( V_409 [ 3 ] ) ) ;
}
int F_248 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_216 ( V_2 ) ;
return F_249 ( V_13 , V_13 -> V_27 ) ;
}
static int F_250 ( struct V_12 * V_13 , T_3 V_104 , T_3 * V_412 , T_3 * V_413 )
{
T_1 V_42 = F_65 ( V_13 , V_414 ) + 24 * V_104 + 8 ;
T_5 V_415 ;
int V_43 ;
F_240 ( & V_13 -> V_416 ) ;
V_43 = F_251 ( V_13 , 0 , V_417 , V_42 ,
sizeof( V_415 ) , ( T_11 * ) & V_415 ,
V_418 ) ;
F_242 ( & V_13 -> V_416 ) ;
if ( ! V_43 ) {
* V_413 = ( F_45 ( V_415 ) >> 25 ) & 0xffff ;
* V_412 = ( F_45 ( V_415 ) >> 9 ) & 0xffff ;
}
return V_43 ;
}
int F_252 ( struct V_1 * V_2 , T_3 V_104 , T_3 V_412 ,
T_3 V_200 )
{
struct V_12 * V_13 = F_216 ( V_2 ) ;
T_3 V_419 , V_420 ;
int V_43 ;
V_43 = F_250 ( V_13 , V_104 , & V_419 , & V_420 ) ;
if ( V_43 )
goto V_102;
if ( V_412 != V_419 ) {
T_3 V_301 ;
T_1 V_253 ;
if ( V_412 >= V_419 )
V_301 = V_412 - V_419 ;
else
V_301 = V_200 - V_419 + V_412 ;
if ( F_110 ( V_13 -> V_209 . V_217 ) )
V_253 = F_253 ( V_301 ) ;
else
V_253 = F_254 ( V_301 ) ;
F_255 () ;
F_67 ( V_13 , F_66 ( V_421 ) ,
F_256 ( V_104 ) | V_253 ) ;
}
V_102:
return V_43 ;
}
int F_257 ( struct V_1 * V_2 , T_1 V_422 , T_11 * V_423 )
{
struct V_12 * V_13 ;
T_1 V_424 , V_425 , V_426 ;
T_1 V_427 , V_428 , V_429 , V_430 , V_200 ;
T_1 V_431 , V_432 , V_433 , V_434 ;
int V_43 ;
V_13 = F_216 ( V_2 ) ;
V_424 = ( ( V_422 >> 8 ) * 32 ) + V_13 -> V_435 . V_422 . V_436 ;
V_200 = F_65 ( V_13 , V_437 ) ;
V_427 = F_258 ( V_200 ) << 20 ;
V_200 = F_65 ( V_13 , V_438 ) ;
V_428 = F_259 ( V_200 ) << 20 ;
V_200 = F_65 ( V_13 , V_439 ) ;
V_429 = F_260 ( V_200 ) << 20 ;
V_431 = V_427 ;
V_432 = V_431 + V_428 ;
V_433 = V_432 + V_429 ;
if ( V_424 < V_431 ) {
V_425 = V_417 ;
V_426 = V_424 ;
} else if ( V_424 < V_432 ) {
V_425 = V_440 ;
V_426 = V_424 - V_431 ;
} else {
if ( V_424 < V_433 ) {
V_425 = V_441 ;
V_426 = V_424 - V_432 ;
} else if ( F_261 ( V_13 -> V_209 . V_217 ) ) {
V_200 = F_65 ( V_13 , V_442 ) ;
V_430 = F_262 ( V_200 ) << 20 ;
V_434 = V_433 + V_430 ;
if ( V_424 < V_434 ) {
V_425 = V_443 ;
V_426 = V_424 - V_433 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_240 ( & V_13 -> V_416 ) ;
V_43 = F_251 ( V_13 , 0 , V_425 , V_426 , 32 , V_423 , V_418 ) ;
F_242 ( & V_13 -> V_416 ) ;
return V_43 ;
V_22:
F_11 ( V_13 -> V_30 , L_34 ,
V_422 , V_424 ) ;
return - V_444 ;
}
T_2 F_263 ( struct V_1 * V_2 )
{
T_1 V_445 , V_446 ;
struct V_12 * V_13 ;
V_13 = F_216 ( V_2 ) ;
V_446 = F_65 ( V_13 , V_447 ) ;
V_445 = F_264 ( F_65 ( V_13 , V_448 ) ) ;
return ( ( T_2 ) V_445 << 32 ) | ( T_2 ) V_446 ;
}
int F_265 ( struct V_1 * V_2 ,
unsigned int V_104 ,
enum V_449 V_450 ,
int V_451 ,
T_2 * V_452 ,
unsigned int * V_453 )
{
return F_266 ( F_216 ( V_2 ) ,
V_104 ,
( V_450 == V_454
? V_455
: V_456 ) ,
V_451 ,
V_452 ,
V_453 ) ;
}
static void F_267 ( struct V_457 * V_458 )
{
const struct V_459 * V_460 ;
const struct V_1 * V_189 = V_458 -> V_2 ;
if ( V_189 -> V_461 & V_462 )
V_189 = F_268 ( V_189 ) ;
V_460 = V_189 -> V_2 . V_460 ;
if ( V_460 && V_460 -> V_463 == & V_464 . V_463 )
F_269 ( F_270 ( V_460 ) , V_458 ) ;
}
static int F_271 ( struct V_465 * V_466 , unsigned long V_467 ,
void * V_117 )
{
switch ( V_467 ) {
case V_468 :
F_267 ( V_117 ) ;
break;
case V_469 :
default:
break;
}
return 0 ;
}
static void F_272 ( struct V_12 * V_13 , int V_470 )
{
T_1 V_397 , V_398 , V_399 , V_400 ;
do {
V_397 = F_65 ( V_13 , V_401 ) ;
V_398 = F_65 ( V_13 , V_402 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
V_399 = F_232 ( V_397 ) ;
V_400 = F_233 ( V_397 ) ;
} else {
V_399 = F_234 ( V_397 ) ;
V_400 = F_235 ( V_398 ) ;
}
if ( V_399 == 0 && V_400 == 0 )
break;
F_273 ( V_471 ) ;
F_274 ( F_275 ( V_470 ) ) ;
} while ( 1 );
}
static void F_276 ( struct V_106 * V_25 )
{
unsigned long V_53 ;
F_277 ( & V_25 -> V_472 , V_53 ) ;
V_25 -> V_473 = 1 ;
F_278 ( & V_25 -> V_472 , V_53 ) ;
}
static void F_279 ( struct V_12 * V_13 , struct V_106 * V_25 )
{
F_280 ( & V_25 -> V_472 ) ;
if ( V_25 -> V_474 ) {
F_255 () ;
F_67 ( V_13 , F_66 ( V_421 ) ,
F_256 ( V_25 -> V_26 ) | F_253 ( V_25 -> V_474 ) ) ;
V_25 -> V_474 = 0 ;
}
V_25 -> V_473 = 0 ;
F_281 ( & V_25 -> V_472 ) ;
}
static void F_282 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_276 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_71 (&adap->sge, i)
F_276 ( & V_13 -> V_16 . V_110 [ V_19 ] . V_25 ) ;
F_70 (adap, i)
F_276 ( & V_13 -> V_16 . V_216 [ V_19 ] . V_25 ) ;
}
static void F_283 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_279 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_71 (&adap->sge, i)
F_279 ( V_13 , & V_13 -> V_16 . V_110 [ V_19 ] . V_25 ) ;
F_70 (adap, i)
F_279 ( V_13 , & V_13 -> V_16 . V_216 [ V_19 ] . V_25 ) ;
}
static void F_284 ( struct V_12 * V_13 , enum V_475 V_118 )
{
if ( V_13 -> V_139 [ V_476 ] )
V_137 [ V_476 ] . F_285 ( V_13 -> V_139 [ V_476 ] ,
V_118 ) ;
}
static void F_286 ( struct V_348 * V_349 )
{
struct V_12 * V_13 ;
V_13 = F_50 ( V_349 , struct V_12 , V_477 ) ;
F_272 ( V_13 , V_478 ) ;
F_283 ( V_13 ) ;
F_284 ( V_13 , V_479 ) ;
if ( F_214 ( V_13 -> V_209 . V_217 ) <= V_358 )
F_287 ( V_13 , V_480 ,
V_481 | V_482 ,
V_481 | V_482 ) ;
else
F_287 ( V_13 , V_480 ,
V_482 , V_482 ) ;
}
static void F_288 ( struct V_12 * V_13 , struct V_106 * V_25 )
{
T_3 V_419 , V_420 ;
int V_43 ;
F_280 ( & V_25 -> V_472 ) ;
V_43 = F_250 ( V_13 , ( T_3 ) V_25 -> V_26 , & V_419 , & V_420 ) ;
if ( V_43 )
goto V_102;
if ( V_25 -> V_483 != V_419 ) {
T_3 V_301 ;
T_1 V_253 ;
if ( V_25 -> V_483 >= V_419 )
V_301 = V_25 -> V_483 - V_419 ;
else
V_301 = V_25 -> V_200 - V_419 + V_25 -> V_483 ;
if ( F_110 ( V_13 -> V_209 . V_217 ) )
V_253 = F_253 ( V_301 ) ;
else
V_253 = F_254 ( V_301 ) ;
F_255 () ;
F_67 ( V_13 , F_66 ( V_421 ) ,
F_256 ( V_25 -> V_26 ) | V_253 ) ;
}
V_102:
V_25 -> V_473 = 0 ;
V_25 -> V_474 = 0 ;
F_281 ( & V_25 -> V_472 ) ;
if ( V_43 )
F_289 ( V_13 , L_35 ) ;
}
static void F_290 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_288 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_71 (&adap->sge, i)
F_288 ( V_13 , & V_13 -> V_16 . V_110 [ V_19 ] . V_25 ) ;
F_70 (adap, i)
F_288 ( V_13 , & V_13 -> V_16 . V_216 [ V_19 ] . V_25 ) ;
}
static void F_291 ( struct V_348 * V_349 )
{
struct V_12 * V_13 ;
V_13 = F_50 ( V_349 , struct V_12 , V_484 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
F_272 ( V_13 , V_478 ) ;
F_284 ( V_13 , V_485 ) ;
F_272 ( V_13 , V_478 ) ;
F_290 ( V_13 ) ;
F_272 ( V_13 , V_478 ) ;
F_283 ( V_13 ) ;
F_284 ( V_13 , V_479 ) ;
} else if ( F_261 ( V_13 -> V_209 . V_217 ) ) {
T_1 V_486 = F_65 ( V_13 , 0x010ac ) ;
T_3 V_104 = ( V_486 >> 15 ) & 0x1ffff ;
T_3 V_487 = V_486 & 0x1fff ;
T_2 V_488 ;
unsigned int V_489 ;
int V_43 ;
V_43 = F_266 ( V_13 , V_104 , V_455 ,
0 , & V_488 , & V_489 ) ;
if ( V_43 )
F_11 ( V_13 -> V_30 , L_36
L_37 , V_104 , V_487 ) ;
else
F_292 ( F_254 ( V_487 ) | F_256 ( V_489 ) ,
V_13 -> V_490 + V_488 + V_491 ) ;
F_287 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_214 ( V_13 -> V_209 . V_217 ) <= V_358 )
F_287 ( V_13 , V_492 , V_493 , 0 ) ;
}
void F_293 ( struct V_12 * V_13 )
{
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
F_282 ( V_13 ) ;
F_284 ( V_13 , V_494 ) ;
F_287 ( V_13 , V_480 ,
V_481 | V_482 , 0 ) ;
F_204 ( V_13 -> V_346 , & V_13 -> V_477 ) ;
}
}
void F_294 ( struct V_12 * V_13 )
{
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
F_282 ( V_13 ) ;
F_284 ( V_13 , V_494 ) ;
}
F_204 ( V_13 -> V_346 , & V_13 -> V_484 ) ;
}
static void F_295 ( struct V_12 * V_13 , unsigned int V_138 )
{
void * V_495 ;
struct V_496 V_497 ;
unsigned short V_19 ;
V_497 . V_147 = V_13 -> V_147 ;
V_497 . V_28 = V_13 -> V_28 ;
V_497 . V_74 = V_13 -> V_74 ;
V_497 . V_79 = & V_13 -> V_79 ;
V_497 . V_498 = V_13 -> V_34 ;
V_497 . V_499 = & V_13 -> V_435 ;
V_497 . V_384 = V_13 -> V_209 . V_384 ;
if ( V_138 == V_476 ) {
V_497 . V_500 = V_13 -> V_16 . V_213 ;
V_497 . V_501 = V_13 -> V_16 . V_215 ;
V_497 . V_502 = V_13 -> V_16 . V_212 ;
V_497 . V_503 = V_13 -> V_16 . V_214 ;
} else if ( V_138 == V_504 ) {
V_497 . V_500 = V_13 -> V_16 . V_211 ;
V_497 . V_502 = V_13 -> V_16 . V_208 ;
}
V_497 . V_505 = V_13 -> V_16 . V_208 ;
V_497 . V_506 = V_13 -> V_209 . V_210 ;
V_497 . V_210 = V_13 -> V_209 . V_210 ;
V_497 . V_507 = V_13 -> V_209 . V_508 ;
V_497 . V_509 = V_13 -> V_209 . V_217 ;
V_497 . V_510 = F_296 ( F_65 ( V_13 , V_511 ) ) ;
V_497 . V_512 = 1000000000 / V_13 -> V_209 . V_513 . V_514 ;
V_497 . V_515 = 1 << V_13 -> V_209 . V_16 . V_516 ;
V_497 . V_517 = 1 << V_13 -> V_209 . V_16 . V_518 ;
V_497 . V_519 = V_13 -> V_209 . V_520 . V_521 ;
for ( V_19 = 0 ; V_19 < V_522 ; V_19 ++ )
V_497 . V_523 [ V_19 ] = V_19 ;
V_497 . V_524 = V_13 -> V_525 + F_66 ( V_194 ) ;
V_497 . V_526 = V_13 -> V_525 + F_66 ( V_421 ) ;
V_497 . V_527 = V_13 -> V_209 . V_527 ;
V_497 . V_528 = V_528 ;
V_497 . V_529 = V_13 -> V_16 . V_530 ;
V_497 . V_531 = V_13 -> V_16 . V_532 ;
V_497 . V_533 = V_13 -> V_16 . V_534 ;
V_497 . V_535 = V_13 -> V_53 & V_536 ;
V_497 . V_537 = V_13 -> V_209 . V_537 ;
V_497 . V_538 = V_13 -> V_209 . V_538 ;
V_497 . V_539 = V_13 -> V_209 . V_539 ;
V_497 . V_540 = F_297 ( V_13 -> V_30 ) ;
V_495 = V_137 [ V_138 ] . F_298 ( & V_497 ) ;
if ( F_299 ( V_495 ) ) {
F_300 ( V_13 -> V_30 ,
L_38 ,
V_541 [ V_138 ] , F_301 ( V_495 ) ) ;
return;
}
V_13 -> V_139 [ V_138 ] = V_495 ;
if ( ! V_542 ) {
F_302 ( & V_543 ) ;
V_542 = true ;
}
if ( V_13 -> V_53 & V_193 )
V_137 [ V_138 ] . F_303 ( V_495 , V_544 ) ;
}
static void F_304 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_240 ( & V_545 ) ;
F_305 ( & V_13 -> V_546 , & V_547 ) ;
F_242 ( & V_545 ) ;
F_306 ( & V_548 ) ;
F_307 ( & V_13 -> V_549 , & V_550 ) ;
for ( V_19 = 0 ; V_19 < V_551 ; V_19 ++ )
if ( V_137 [ V_19 ] . F_298 )
F_295 ( V_13 , V_19 ) ;
F_308 ( & V_548 ) ;
}
static void F_309 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_306 ( & V_548 ) ;
F_310 ( & V_13 -> V_549 ) ;
for ( V_19 = 0 ; V_19 < V_551 ; V_19 ++ )
if ( V_13 -> V_139 [ V_19 ] ) {
V_137 [ V_19 ] . F_303 ( V_13 -> V_139 [ V_19 ] ,
V_552 ) ;
V_13 -> V_139 [ V_19 ] = NULL ;
}
if ( V_542 && F_311 ( & V_550 ) ) {
F_312 ( & V_543 ) ;
V_542 = false ;
}
F_308 ( & V_548 ) ;
F_240 ( & V_545 ) ;
F_313 ( & V_13 -> V_546 ) ;
F_242 ( & V_545 ) ;
}
static void F_314 ( struct V_12 * V_13 , enum V_553 V_554 )
{
unsigned int V_19 ;
F_306 ( & V_548 ) ;
for ( V_19 = 0 ; V_19 < V_551 ; V_19 ++ )
if ( V_13 -> V_139 [ V_19 ] )
V_137 [ V_19 ] . F_303 ( V_13 -> V_139 [ V_19 ] , V_554 ) ;
F_308 ( & V_548 ) ;
}
int F_315 ( enum V_555 type , const struct V_556 * V_6 )
{
int V_43 = 0 ;
struct V_12 * V_13 ;
if ( type >= V_551 )
return - V_444 ;
F_306 ( & V_548 ) ;
if ( V_137 [ type ] . F_298 ) {
V_43 = - V_557 ;
goto V_102;
}
V_137 [ type ] = * V_6 ;
F_316 (adap, &adapter_list, list_node)
F_295 ( V_13 , type ) ;
V_102: F_308 ( & V_548 ) ;
return V_43 ;
}
int F_317 ( enum V_555 type )
{
struct V_12 * V_13 ;
if ( type >= V_551 )
return - V_444 ;
F_306 ( & V_548 ) ;
F_316 (adap, &adapter_list, list_node)
V_13 -> V_139 [ type ] = NULL ;
V_137 [ type ] . F_298 = NULL ;
F_308 ( & V_548 ) ;
return 0 ;
}
static int F_318 ( struct V_465 * V_558 ,
unsigned long V_467 , void * V_117 )
{
struct V_559 * V_560 = V_117 ;
struct V_1 * V_561 = V_560 -> V_562 -> V_2 ;
const struct V_459 * V_460 = NULL ;
#if F_319 ( V_563 )
struct V_12 * V_13 ;
#endif
if ( V_561 -> V_461 & V_462 )
V_561 = F_268 ( V_561 ) ;
#if F_319 ( V_563 )
if ( V_561 -> V_53 & V_564 ) {
F_316 (adap, &adapter_list, list_node) {
switch ( V_467 ) {
case V_565 :
F_320 ( V_13 -> V_34 [ 0 ] ,
( const T_1 * ) V_560 , 1 ) ;
break;
case V_566 :
F_321 ( V_13 -> V_34 [ 0 ] ,
( const T_1 * ) V_560 , 1 ) ;
break;
default:
break;
}
}
return V_567 ;
}
#endif
if ( V_561 )
V_460 = V_561 -> V_2 . V_460 ;
if ( V_460 && V_460 -> V_463 == & V_464 . V_463 ) {
switch ( V_467 ) {
case V_565 :
F_320 ( V_561 , ( const T_1 * ) V_560 , 1 ) ;
break;
case V_566 :
F_321 ( V_561 , ( const T_1 * ) V_560 , 1 ) ;
break;
default:
break;
}
}
return V_567 ;
}
static void F_322 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_43 ;
F_323 () ;
for ( V_19 = 0 ; V_19 < V_568 ; V_19 ++ ) {
V_2 = V_13 -> V_34 [ V_19 ] ;
V_43 = 0 ;
if ( V_2 )
V_43 = F_324 ( V_2 ) ;
if ( V_43 < 0 )
break;
}
F_325 () ;
}
static int F_326 ( struct V_12 * V_13 )
{
int V_22 ;
V_22 = F_101 ( V_13 ) ;
if ( V_22 )
goto V_102;
V_22 = F_84 ( V_13 ) ;
if ( V_22 )
goto V_569;
if ( V_13 -> V_53 & V_146 ) {
F_69 ( V_13 ) ;
V_22 = F_75 ( V_13 -> V_159 [ 0 ] . V_167 , F_64 , 0 ,
V_13 -> V_159 [ 0 ] . V_160 , V_13 ) ;
if ( V_22 )
goto V_570;
V_22 = F_74 ( V_13 ) ;
if ( V_22 ) {
F_77 ( V_13 -> V_159 [ 0 ] . V_167 , V_13 ) ;
goto V_570;
}
} else {
V_22 = F_75 ( V_13 -> V_147 -> V_149 , F_327 ( V_13 ) ,
( V_13 -> V_53 & V_148 ) ? 0 : V_571 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_570;
}
F_94 ( V_13 ) ;
F_328 ( V_13 ) ;
F_329 ( V_13 ) ;
V_13 -> V_53 |= V_193 ;
F_314 ( V_13 , V_544 ) ;
#if F_319 ( V_572 )
F_322 ( V_13 ) ;
#endif
V_102:
return V_22 ;
V_570:
F_11 ( V_13 -> V_30 , L_39 , V_22 ) ;
V_569:
F_103 ( V_13 ) ;
goto V_102;
}
static void F_330 ( struct V_12 * V_12 )
{
F_331 ( & V_12 -> V_347 ) ;
F_331 ( & V_12 -> V_477 ) ;
F_331 ( & V_12 -> V_484 ) ;
V_12 -> V_345 = false ;
V_12 -> V_343 = NULL ;
F_332 ( V_12 ) ;
F_103 ( V_12 ) ;
V_12 -> V_53 &= ~ V_193 ;
}
static int F_333 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_17 ( V_2 ) ;
if ( ! ( V_12 -> V_53 & V_193 ) ) {
V_22 = F_326 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_29 ( V_2 ) ;
if ( ! V_22 )
F_334 ( V_2 ) ;
return V_22 ;
}
static int F_335 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_336 ( V_2 ) ;
F_17 ( V_2 ) ;
return F_337 ( V_12 , V_12 -> V_28 , V_11 -> V_50 , false , false ) ;
}
static int F_338 ( struct V_72 * V_73 )
{
if ( V_73 -> V_573 )
return - V_574 ;
if ( V_73 -> V_90 )
return - V_557 ;
return 0 ;
}
static int F_339 ( struct V_12 * V_12 , unsigned int V_221 )
{
struct V_72 * V_73 ;
int V_43 ;
if ( V_221 >= V_12 -> V_79 . V_81 + V_12 -> V_79 . V_82 )
return - V_444 ;
V_73 = & V_12 -> V_79 . V_84 [ V_221 ] ;
V_43 = F_338 ( V_73 ) ;
if ( V_43 )
return V_43 ;
if ( V_73 -> V_91 )
return F_164 ( V_12 , V_221 ) ;
return 0 ;
}
int F_340 ( const struct V_1 * V_2 , unsigned int V_325 ,
T_11 V_359 , T_12 V_360 , T_12 V_231 ,
unsigned int V_361 , unsigned char V_34 , unsigned char V_255 )
{
int V_43 ;
struct V_72 * V_73 ;
struct V_12 * V_13 ;
int V_19 ;
T_4 * V_253 ;
V_13 = F_216 ( V_2 ) ;
V_325 -= V_13 -> V_79 . V_333 ;
V_325 += V_13 -> V_79 . V_81 ;
V_73 = & V_13 -> V_79 . V_84 [ V_325 ] ;
V_43 = F_338 ( V_73 ) ;
if ( V_43 )
return V_43 ;
if ( V_73 -> V_91 )
F_40 ( V_13 , V_73 ) ;
memset ( & V_73 -> V_227 , 0 , sizeof( struct V_575 ) ) ;
V_73 -> V_227 . V_253 . V_282 = F_341 ( V_360 ) ;
V_73 -> V_227 . V_255 . V_282 = ~ 0 ;
V_253 = ( T_4 * ) & V_359 ;
if ( ( V_253 [ 0 ] | V_253 [ 1 ] | V_253 [ 2 ] | V_253 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_73 -> V_227 . V_253 . V_277 [ V_19 ] = V_253 [ V_19 ] ;
V_73 -> V_227 . V_255 . V_277 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_209 . V_520 . V_521 & V_576 ) {
V_73 -> V_227 . V_253 . V_265 = V_34 ;
V_73 -> V_227 . V_255 . V_265 = V_255 ;
}
}
if ( V_13 -> V_209 . V_520 . V_521 & V_577 ) {
V_73 -> V_227 . V_253 . V_268 = V_578 ;
V_73 -> V_227 . V_255 . V_268 = ~ 0 ;
}
V_73 -> V_227 . V_242 = 1 ;
V_73 -> V_227 . V_238 = V_361 ;
V_73 -> V_573 = 1 ;
V_73 -> V_227 . V_240 = 1 ;
V_43 = F_118 ( V_13 , V_325 ) ;
if ( V_43 ) {
F_40 ( V_13 , V_73 ) ;
return V_43 ;
}
return 0 ;
}
int F_342 ( const struct V_1 * V_2 , unsigned int V_325 ,
unsigned int V_361 , bool V_380 )
{
int V_43 ;
struct V_72 * V_73 ;
struct V_12 * V_13 ;
V_13 = F_216 ( V_2 ) ;
V_325 -= V_13 -> V_79 . V_333 ;
V_325 += V_13 -> V_79 . V_81 ;
V_73 = & V_13 -> V_79 . V_84 [ V_325 ] ;
V_73 -> V_573 = 0 ;
V_43 = F_339 ( V_13 , V_325 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
static struct V_579 * F_343 ( struct V_1 * V_2 ,
struct V_579 * V_580 )
{
struct V_581 V_140 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_240 ( & V_12 -> V_407 ) ;
if ( ! F_344 ( V_2 ) ) {
F_242 ( & V_12 -> V_407 ) ;
return V_580 ;
}
F_345 ( V_12 , V_6 -> V_60 , & V_140 ,
& V_6 -> V_582 ) ;
F_242 ( & V_12 -> V_407 ) ;
V_580 -> V_583 = V_140 . V_584 ;
V_580 -> V_585 = V_140 . V_586 ;
V_580 -> V_587 = V_140 . V_588 ;
V_580 -> V_589 = V_140 . V_590 ;
V_580 -> V_591 = V_140 . V_592 ;
V_580 -> V_593 = V_140 . V_594 + V_140 . V_595 +
V_140 . V_596 ;
V_580 -> V_597 = 0 ;
V_580 -> V_598 = V_140 . V_599 ;
V_580 -> V_600 = V_140 . V_601 ;
V_580 -> V_602 = V_140 . V_603 + V_140 . V_604 +
V_140 . V_605 + V_140 . V_606 +
V_140 . V_607 + V_140 . V_608 +
V_140 . V_609 + V_140 . V_610 ;
V_580 -> V_611 = 0 ;
V_580 -> V_612 = 0 ;
V_580 -> V_613 = 0 ;
V_580 -> V_614 = 0 ;
V_580 -> V_615 = 0 ;
V_580 -> V_616 = 0 ;
V_580 -> V_617 = V_140 . V_618 ;
V_580 -> V_619 = V_140 . V_601 + V_140 . V_599 +
V_580 -> V_593 + V_140 . V_620 + V_580 -> V_602 ;
return V_580 ;
}
static int F_346 ( struct V_1 * V_2 , struct V_621 * V_338 , int V_118 )
{
unsigned int V_27 ;
int V_43 = 0 , V_622 , V_623 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_624 * V_117 = (struct V_624 * ) & V_338 -> V_625 ;
switch ( V_118 ) {
case V_626 :
if ( V_11 -> V_627 < 0 )
return - V_628 ;
V_117 -> V_629 = V_11 -> V_627 ;
break;
case V_630 :
case V_631 :
if ( F_347 ( V_117 -> V_629 ) ) {
V_622 = F_348 ( V_117 -> V_629 ) ;
V_623 = F_349 ( V_117 -> V_629 ) ;
} else if ( V_117 -> V_629 < 32 ) {
V_622 = V_117 -> V_629 ;
V_623 = 0 ;
V_117 -> V_632 &= 0x1f ;
} else
return - V_444 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_118 == V_630 )
V_43 = F_350 ( V_11 -> V_12 , V_27 , V_622 , V_623 ,
V_117 -> V_632 , & V_117 -> V_633 ) ;
else
V_43 = F_351 ( V_11 -> V_12 , V_27 , V_622 , V_623 ,
V_117 -> V_632 , V_117 -> V_634 ) ;
break;
case V_635 :
return F_352 ( V_338 -> V_625 , & V_11 -> V_636 ,
sizeof( V_11 -> V_636 ) ) ?
- V_637 : 0 ;
case V_638 :
if ( F_353 ( & V_11 -> V_636 , V_338 -> V_625 ,
sizeof( V_11 -> V_636 ) ) )
return - V_637 ;
switch ( V_11 -> V_636 . V_639 ) {
case V_640 :
V_11 -> V_641 = false ;
break;
case V_642 :
V_11 -> V_641 = true ;
break;
default:
V_11 -> V_636 . V_639 = V_640 ;
return - V_643 ;
}
return F_352 ( V_338 -> V_625 , & V_11 -> V_636 ,
sizeof( V_11 -> V_636 ) ) ?
- V_637 : 0 ;
default:
return - V_628 ;
}
return V_43 ;
}
static void F_354 ( struct V_1 * V_2 )
{
F_27 ( V_2 , - 1 , false ) ;
}
static int F_355 ( struct V_1 * V_2 , int V_644 )
{
int V_43 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_644 < 81 || V_644 > V_645 )
return - V_444 ;
V_43 = F_28 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_50 , V_644 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_43 )
V_2 -> V_51 = V_644 ;
return V_43 ;
}
static int F_356 ( struct V_1 * V_2 , void * V_6 )
{
int V_43 ;
struct V_646 * V_42 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_357 ( V_42 -> V_647 ) )
return - V_648 ;
V_43 = F_30 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_50 ,
V_11 -> V_58 , V_42 -> V_647 , true , true ) ;
if ( V_43 < 0 )
return V_43 ;
memcpy ( V_2 -> V_59 , V_42 -> V_647 , V_2 -> V_649 ) ;
V_11 -> V_58 = V_43 ;
return 0 ;
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_53 & V_146 ) {
int V_19 ;
struct V_177 * V_650 = & V_13 -> V_16 . V_170 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_650 ++ )
V_168 ( 0 , & V_650 -> V_136 ) ;
} else
F_327 ( V_13 ) ( 0 , V_13 ) ;
}
void F_359 ( struct V_12 * V_13 )
{
F_287 ( V_13 , V_651 , V_652 , 0 ) ;
F_93 ( V_13 ) ;
F_360 ( V_13 -> V_30 , L_40 ) ;
}
static void F_361 ( struct V_12 * V_13 )
{
T_1 V_653 = F_362 ( V_13 ) ;
F_363 ( V_13 , V_653 , V_654 ) ;
}
static void F_364 ( struct V_12 * V_13 )
{
if ( V_13 -> V_435 . V_655 . V_200 ) {
T_1 V_436 ;
unsigned int V_656 ;
V_436 = F_365 ( V_13 , V_657 ) ;
V_436 &= V_658 ;
V_436 += F_366 ( V_13 -> V_147 , & V_13 -> V_435 ) ;
V_656 = F_367 ( V_13 -> V_435 . V_655 . V_200 ) >> 10 ;
F_67 ( V_13 ,
F_368 ( V_659 , 3 ) ,
V_436 | F_369 ( 1 ) | F_370 ( F_371 ( V_656 ) ) ) ;
F_67 ( V_13 ,
F_368 ( V_660 , 3 ) ,
V_13 -> V_435 . V_655 . V_436 ) ;
F_65 ( V_13 ,
F_368 ( V_660 , 3 ) ) ;
}
}
static int F_372 ( struct V_12 * V_13 , struct V_661 * V_662 )
{
T_1 V_150 ;
int V_43 ;
memset ( V_662 , 0 , sizeof( * V_662 ) ) ;
V_662 -> V_663 = F_124 ( F_373 ( V_664 ) |
V_665 | V_666 ) ;
V_662 -> V_667 = F_124 ( F_374 ( * V_662 ) ) ;
V_43 = F_375 ( V_13 , V_13 -> V_27 , V_662 , sizeof( * V_662 ) , V_662 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_662 -> V_668 & F_145 ( V_669 ) ) {
if ( ! V_670 )
V_662 -> V_668 ^= F_145 ( V_669 ) ;
else
V_662 -> V_668 = F_145 ( V_669 ) ;
} else if ( V_670 ) {
F_11 ( V_13 -> V_30 , L_41 ) ;
return V_43 ;
}
V_662 -> V_663 = F_124 ( F_373 ( V_664 ) |
V_665 | V_671 ) ;
V_43 = F_375 ( V_13 , V_13 -> V_27 , V_662 , sizeof( * V_662 ) , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_376 ( V_13 , V_13 -> V_28 ,
V_672 ,
V_673 |
V_674 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_377 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_202 , 64 ,
V_675 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_676 ,
V_676 ) ;
if ( V_43 < 0 )
return V_43 ;
F_378 ( V_13 ) ;
F_67 ( V_13 , V_677 , 0x64f8849 ) ;
F_67 ( V_13 , V_678 , F_244 ( V_679 - 12 ) ) ;
F_67 ( V_13 , V_680 , V_681 ) ;
V_150 = F_65 ( V_13 , V_682 ) ;
F_67 ( V_13 , V_682 , V_150 & ~ V_683 ) ;
V_13 -> V_209 . V_520 . V_684 = 0xE4 ;
F_67 ( V_13 , V_685 ,
F_379 ( V_13 -> V_209 . V_520 . V_684 ) ) ;
V_150 = 0x84218421 ;
F_380 ( V_13 , V_680 , V_682 ,
& V_150 , 1 , V_686 ) ;
F_380 ( V_13 , V_680 , V_682 ,
& V_150 , 1 , V_687 ) ;
F_380 ( V_13 , V_680 , V_682 ,
& V_150 , 1 , V_688 ) ;
#define F_381 16
if ( F_382 ( V_13 ) ) {
F_67 ( V_13 , V_689 ,
F_383 ( F_381 ) |
F_384 ( F_381 ) |
F_385 ( F_381 ) |
F_386 ( F_381 ) ) ;
F_67 ( V_13 , V_690 ,
F_383 ( F_381 ) |
F_384 ( F_381 ) |
F_385 ( F_381 ) |
F_386 ( F_381 ) ) ;
}
return F_387 ( V_13 , V_13 -> V_28 ) ;
}
static int F_388 ( struct V_12 * V_12 )
{
F_389 ( V_12 , V_691 , V_692 ) ;
if ( V_693 != 2 && V_693 != 0 ) {
F_11 ( & V_12 -> V_147 -> V_2 ,
L_42 ,
V_693 ) ;
V_693 = 2 ;
}
F_287 ( V_12 , V_651 ,
F_390 ( V_694 ) ,
F_390 ( V_693 ) ) ;
F_391 ( V_12 , V_681 ,
V_683 , 0 ) ;
return 0 ;
}
static int F_392 ( const T_4 * V_695 ,
T_8 V_696 )
{
int V_424 ;
#define F_393 ( T_13 ) (((__p)[0] << 8) | (__p)[1])
#define F_394 ( T_13 ) ((__p)[0] | ((__p)[1] << 8))
#define F_395 ( T_13 ) (le16(__p) | ((__p)[2] << 16))
V_424 = F_395 ( V_695 + 0x8 ) << 12 ;
V_424 = F_395 ( V_695 + V_424 + 0xa ) ;
return F_393 ( V_695 + V_424 + 0x27e ) ;
#undef F_393
#undef F_394
#undef F_395
}
static struct V_697 * F_396 ( int V_698 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_699 ) ; V_19 ++ ) {
if ( V_699 [ V_19 ] . V_700 == V_698 )
return & V_699 [ V_19 ] ;
}
return NULL ;
}
static int F_397 ( struct V_12 * V_13 )
{
const struct V_701 * V_702 ;
int V_43 ;
struct V_697 * V_703 ;
V_703 = F_396 ( V_13 -> V_147 -> V_459 ) ;
if ( ! V_703 ) {
F_300 ( V_13 -> V_30 ,
L_43 ) ;
return - V_628 ;
}
V_43 = F_398 ( & V_702 , V_703 -> V_704 ,
V_13 -> V_30 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_44
L_45 ,
V_703 -> V_704 , - V_43 ) ;
if ( V_703 -> V_705 ) {
int V_706 = 0 ;
F_399 ( V_13 , & V_706 ) ;
F_300 ( V_13 -> V_30 , L_46
L_47 , V_706 ) ;
V_43 = 0 ;
}
return V_43 ;
}
V_43 = F_400 ( V_13 , V_654 , & V_13 -> V_416 ,
V_703 -> V_707 ,
( T_4 * ) V_702 -> V_117 , V_702 -> V_200 ) ;
if ( V_43 < 0 )
F_11 ( V_13 -> V_30 , L_48 ,
- V_43 ) ;
else if ( V_43 > 0 ) {
int V_708 = 0 ;
if ( V_703 -> V_707 )
V_708 = V_703 -> V_707 ( V_702 -> V_117 ,
V_702 -> V_200 ) ;
F_401 ( V_13 -> V_30 , L_49
L_50 ,
V_703 -> V_704 , V_708 ) ;
}
F_402 ( V_702 ) ;
return V_43 ;
}
static int F_403 ( struct V_12 * V_12 , int V_709 )
{
struct V_661 V_710 ;
const struct V_701 * V_711 ;
unsigned long V_712 = 0 , V_713 = 0 ;
T_1 V_714 , V_715 , V_716 ;
int V_43 ;
int V_717 = 0 ;
char * V_718 , V_719 [ 256 ] ;
char * V_720 = NULL ;
if ( V_709 ) {
V_43 = F_404 ( V_12 , V_12 -> V_27 ,
V_721 | V_722 ) ;
if ( V_43 < 0 )
goto V_723;
}
if ( F_405 ( V_12 -> V_147 -> V_459 ) ) {
V_43 = F_397 ( V_12 ) ;
if ( V_43 < 0 )
goto V_723;
}
switch ( F_214 ( V_12 -> V_209 . V_217 ) ) {
case V_724 :
V_718 = V_725 ;
break;
case V_358 :
V_718 = V_726 ;
break;
case V_727 :
V_718 = V_728 ;
break;
default:
F_11 ( V_12 -> V_30 , L_51 ,
V_12 -> V_147 -> V_459 ) ;
V_43 = - V_444 ;
goto V_723;
}
V_43 = F_406 ( & V_711 , V_718 , V_12 -> V_30 ) ;
if ( V_43 < 0 ) {
V_720 = L_52 ;
V_712 = V_729 ;
V_713 = F_407 ( V_12 ) ;
} else {
T_1 V_209 [ 7 ] , V_253 [ 7 ] ;
sprintf ( V_719 ,
L_53 , V_718 ) ;
V_720 = V_719 ;
if ( V_711 -> V_200 >= V_730 )
V_43 = - V_180 ;
else {
V_209 [ 0 ] = ( F_7 ( V_731 ) |
F_8 ( V_732 ) ) ;
V_43 = F_408 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_209 , V_253 ) ;
if ( V_43 == 0 ) {
T_8 V_733 = V_711 -> V_200 & 0x3 ;
T_8 V_200 = V_711 -> V_200 & ~ 0x3 ;
T_11 * V_117 = ( T_11 * ) V_711 -> V_117 ;
V_712 = F_409 ( V_253 [ 0 ] ) ;
V_713 = F_410 ( V_253 [ 0 ] ) << 16 ;
F_240 ( & V_12 -> V_416 ) ;
V_43 = F_251 ( V_12 , 0 , V_712 , V_713 ,
V_200 , V_117 , V_734 ) ;
if ( V_43 == 0 && V_733 != 0 ) {
union {
T_11 V_735 ;
char V_736 [ 4 ] ;
} V_737 ;
int V_19 ;
V_737 . V_735 = V_117 [ V_200 >> 2 ] ;
for ( V_19 = V_733 ; V_19 < 4 ; V_19 ++ )
V_737 . V_736 [ V_19 ] = 0 ;
V_43 = F_251 ( V_12 , 0 , V_712 ,
V_713 + V_200 ,
4 , & V_737 . V_735 ,
V_734 ) ;
}
F_242 ( & V_12 -> V_416 ) ;
}
}
F_402 ( V_711 ) ;
if ( V_43 )
goto V_723;
}
memset ( & V_710 , 0 , sizeof( V_710 ) ) ;
V_710 . V_663 =
F_124 ( F_373 ( V_664 ) |
V_665 |
V_666 ) ;
V_710 . V_667 =
F_124 ( V_738 |
F_411 ( V_712 ) |
F_412 ( V_713 >> 16 ) |
F_374 ( V_710 ) ) ;
V_43 = F_375 ( V_12 , V_12 -> V_27 , & V_710 , sizeof( V_710 ) ,
& V_710 ) ;
if ( V_43 == - V_739 ) {
memset ( & V_710 , 0 , sizeof( V_710 ) ) ;
V_710 . V_663 =
F_124 ( F_373 ( V_664 ) |
V_665 |
V_666 ) ;
V_710 . V_667 = F_124 ( F_374 ( V_710 ) ) ;
V_43 = F_375 ( V_12 , V_12 -> V_27 , & V_710 ,
sizeof( V_710 ) , & V_710 ) ;
V_720 = L_54 ;
}
V_717 = 1 ;
if ( V_43 < 0 )
goto V_723;
V_714 = F_38 ( V_710 . V_714 ) ;
V_715 = F_38 ( V_710 . V_715 ) ;
V_716 = F_38 ( V_710 . V_716 ) ;
if ( V_715 != V_716 )
F_300 ( V_12 -> V_30 , L_55\
L_56 ,
V_715 , V_716 ) ;
V_710 . V_663 =
F_124 ( F_373 ( V_664 ) |
V_665 |
V_671 ) ;
V_710 . V_667 = F_124 ( F_374 ( V_710 ) ) ;
V_43 = F_375 ( V_12 , V_12 -> V_27 , & V_710 , sizeof( V_710 ) ,
NULL ) ;
if ( V_43 < 0 )
goto V_723;
V_43 = F_388 ( V_12 ) ;
if ( V_43 < 0 )
goto V_723;
V_43 = F_413 ( V_12 , V_12 -> V_27 ) ;
if ( V_43 < 0 )
goto V_723;
F_401 ( V_12 -> V_30 , L_57\
L_58 ,
V_720 , V_714 , V_716 ) ;
return 0 ;
V_723:
if ( V_717 && V_43 != - V_739 )
F_300 ( V_12 -> V_30 , L_59 ,
V_720 , - V_43 ) ;
return V_43 ;
}
static struct V_740 * F_414 ( int V_217 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_741 ) ; V_19 ++ ) {
if ( V_741 [ V_19 ] . V_217 == V_217 )
return & V_741 [ V_19 ] ;
}
return NULL ;
}
static int F_415 ( struct V_12 * V_13 )
{
int V_43 ;
T_1 V_150 , V_742 ;
enum V_743 V_64 ;
T_1 V_209 [ 7 ] , V_253 [ 7 ] ;
struct V_661 V_710 ;
int V_709 = 1 ;
V_43 = F_416 ( V_13 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_417 ( V_13 , V_13 -> V_27 , V_13 -> V_27 , V_744 , & V_64 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_60 ,
V_43 ) ;
return V_43 ;
}
if ( V_43 == V_13 -> V_27 )
V_13 -> V_53 |= V_154 ;
F_418 ( V_13 , & V_13 -> V_209 . V_527 ) ;
F_419 ( V_13 , & V_13 -> V_209 . V_745 ) ;
V_43 = F_420 ( V_13 ) ;
if ( V_43 )
V_64 = V_746 ;
if ( ( V_13 -> V_53 & V_154 ) && V_64 != V_747 ) {
struct V_740 * V_740 ;
struct V_748 * V_749 ;
const struct V_701 * V_750 ;
const T_4 * V_751 = NULL ;
unsigned int V_752 = 0 ;
V_740 = F_414 ( F_214 ( V_13 -> V_209 . V_217 ) ) ;
if ( V_740 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_61 ,
F_214 ( V_13 -> V_209 . V_217 ) ) ;
return - V_444 ;
}
V_749 = F_113 ( sizeof( * V_749 ) ) ;
V_43 = F_406 ( & V_750 , V_740 -> V_753 ,
V_13 -> V_30 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_62 ,
V_740 -> V_753 , V_43 ) ;
} else {
V_751 = V_750 -> V_117 ;
V_752 = V_750 -> V_200 ;
}
V_43 = F_421 ( V_13 , V_740 , V_751 , V_752 , V_749 ,
V_64 , & V_709 ) ;
F_402 ( V_750 ) ;
F_116 ( V_749 ) ;
if ( V_43 < 0 )
goto V_723;
}
V_43 = F_422 ( V_13 , & V_13 -> V_209 . V_513 ) ;
if ( V_43 < 0 )
goto V_723;
V_150 =
F_7 ( V_731 ) |
F_8 ( V_754 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_150 , & V_742 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_209 . V_210 = F_423 ( V_742 ) ;
V_13 -> V_209 . V_755 = V_742 ;
if ( V_64 == V_747 ) {
F_401 ( V_13 -> V_30 , L_63\
L_64 ,
V_13 -> V_53 & V_154 ? L_65 : L_66 ) ;
} else {
F_401 ( V_13 -> V_30 , L_67\
L_68 ) ;
V_209 [ 0 ] = ( F_7 ( V_731 ) |
F_8 ( V_732 ) ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_209 , V_253 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_69
L_70 ) ;
goto V_723;
}
V_43 = F_403 ( V_13 , V_709 ) ;
if ( V_43 == - V_739 ) {
F_11 ( V_13 -> V_30 , L_71
L_72 ) ;
goto V_723;
}
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_73
L_74 , - V_43 ) ;
goto V_723;
}
}
V_43 = F_378 ( V_13 ) ;
if ( V_43 < 0 )
goto V_723;
if ( F_424 ( V_13 -> V_147 -> V_459 ) )
V_13 -> V_209 . V_756 = 1 ;
#define F_425 ( T_14 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_426 ( T_14 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_209 [ 0 ] = F_426 ( V_757 ) ;
V_209 [ 1 ] = F_426 ( V_758 ) ;
V_209 [ 2 ] = F_426 ( V_759 ) ;
V_209 [ 3 ] = F_426 ( V_760 ) ;
V_209 [ 4 ] = F_426 ( V_761 ) ;
V_209 [ 5 ] = F_426 ( V_762 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_209 , V_253 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_16 . V_108 = V_253 [ 0 ] ;
V_13 -> V_763 = V_253 [ 1 ] ;
V_13 -> V_764 = V_253 [ 2 ] ;
V_13 -> V_79 . V_80 = V_253 [ 3 ] ;
V_13 -> V_79 . V_81 = V_253 [ 4 ] - V_253 [ 3 ] + 1 ;
V_13 -> V_16 . V_187 = V_253 [ 5 ] ;
V_209 [ 0 ] = F_426 ( V_765 ) ;
V_209 [ 1 ] = F_426 ( V_766 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 , V_253 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_16 . V_202 = V_253 [ 0 ] - V_13 -> V_16 . V_108 + 1 ;
V_13 -> V_16 . V_190 = V_253 [ 1 ] - V_13 -> V_16 . V_187 + 1 ;
V_13 -> V_16 . V_107 = F_427 ( V_13 -> V_16 . V_202 ,
sizeof( * V_13 -> V_16 . V_107 ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_107 ) {
V_43 = - V_180 ;
goto V_723;
}
V_13 -> V_16 . V_188 = F_427 ( V_13 -> V_16 . V_190 ,
sizeof( * V_13 -> V_16 . V_188 ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_188 ) {
V_43 = - V_180 ;
goto V_723;
}
V_13 -> V_16 . V_201 = F_427 ( F_211 ( V_13 -> V_16 . V_202 ) ,
sizeof( long ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_201 ) {
V_43 = - V_180 ;
goto V_723;
}
V_13 -> V_16 . V_203 = F_427 ( F_211 ( V_13 -> V_16 . V_202 ) ,
sizeof( long ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_203 ) {
V_43 = - V_180 ;
goto V_723;
}
#ifdef F_184
V_13 -> V_16 . V_767 = F_427 ( F_211 ( V_13 -> V_16 . V_202 ) ,
sizeof( long ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_767 ) {
V_43 = - V_180 ;
goto V_723;
}
#endif
V_209 [ 0 ] = F_426 ( V_768 ) ;
V_209 [ 1 ] = F_426 ( V_769 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 , V_253 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_770 = V_253 [ 0 ] ;
V_13 -> V_771 = V_253 [ 1 ] ;
V_209 [ 0 ] = F_426 ( V_772 ) ;
V_209 [ 1 ] = F_426 ( V_773 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 , V_253 ) ;
if ( ( V_253 [ 0 ] != V_253 [ 1 ] ) && ( V_43 >= 0 ) ) {
V_13 -> V_53 |= V_536 ;
V_13 -> V_79 . V_774 = V_253 [ 0 ] ;
V_13 -> V_79 . V_775 = V_253 [ 1 ] ;
}
V_209 [ 0 ] = F_426 ( V_776 ) ;
V_253 [ 0 ] = 1 ;
( void ) F_178 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_209 , V_253 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
V_13 -> V_209 . V_539 = false ;
} else {
V_209 [ 0 ] = F_425 ( V_777 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_209 , V_253 ) ;
V_13 -> V_209 . V_539 = ( V_43 == 0 && V_253 [ 0 ] != 0 ) ;
}
memset ( & V_710 , 0 , sizeof( V_710 ) ) ;
V_710 . V_663 = F_124 ( F_373 ( V_664 ) |
V_665 | V_666 ) ;
V_710 . V_667 = F_124 ( F_374 ( V_710 ) ) ;
V_43 = F_375 ( V_13 , V_13 -> V_27 , & V_710 , sizeof( V_710 ) ,
& V_710 ) ;
if ( V_43 < 0 )
goto V_723;
if ( V_710 . V_778 ) {
V_209 [ 0 ] = F_425 ( V_779 ) ;
V_209 [ 1 ] = F_426 ( V_780 ) ;
V_209 [ 2 ] = F_426 ( V_781 ) ;
V_209 [ 3 ] = F_426 ( V_782 ) ;
V_209 [ 4 ] = F_426 ( V_783 ) ;
V_209 [ 5 ] = F_425 ( V_784 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_209 , V_253 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_79 . V_350 = V_253 [ 0 ] ;
V_13 -> V_79 . V_356 = F_428 ( V_13 -> V_79 . V_350 / 2 , V_785 ) ;
V_13 -> V_79 . V_331 = V_253 [ 1 ] ;
V_13 -> V_79 . V_329 = V_253 [ 2 ] - V_253 [ 1 ] + 1 ;
if ( V_13 -> V_53 & V_536 && ! F_429 ( V_13 ) ) {
V_13 -> V_79 . V_333 = V_13 -> V_79 . V_80 +
F_430 ( V_13 -> V_79 . V_81 , 3 ) ;
V_13 -> V_79 . V_82 = V_13 -> V_79 . V_81 -
F_430 ( V_13 -> V_79 . V_81 , 3 ) ;
V_13 -> V_79 . V_81 = V_13 -> V_79 . V_333 -
V_13 -> V_79 . V_80 ;
}
V_13 -> V_435 . V_786 . V_436 = V_253 [ 3 ] ;
V_13 -> V_435 . V_786 . V_200 = V_253 [ 4 ] - V_253 [ 3 ] + 1 ;
V_13 -> V_209 . V_508 = V_253 [ 5 ] ;
V_13 -> V_209 . V_787 = 1 ;
}
if ( V_710 . V_788 ) {
V_209 [ 0 ] = F_426 ( V_789 ) ;
V_209 [ 1 ] = F_426 ( V_790 ) ;
V_209 [ 2 ] = F_426 ( V_791 ) ;
V_209 [ 3 ] = F_426 ( V_792 ) ;
V_209 [ 4 ] = F_426 ( V_793 ) ;
V_209 [ 5 ] = F_426 ( V_794 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_209 , V_253 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_435 . V_422 . V_436 = V_253 [ 0 ] ;
V_13 -> V_435 . V_422 . V_200 = V_253 [ 1 ] - V_253 [ 0 ] + 1 ;
V_13 -> V_435 . V_795 . V_436 = V_253 [ 2 ] ;
V_13 -> V_435 . V_795 . V_200 = V_253 [ 3 ] - V_253 [ 2 ] + 1 ;
V_13 -> V_435 . V_796 . V_436 = V_253 [ 4 ] ;
V_13 -> V_435 . V_796 . V_200 = V_253 [ 5 ] - V_253 [ 4 ] + 1 ;
V_209 [ 0 ] = F_426 ( V_797 ) ;
V_209 [ 1 ] = F_426 ( V_798 ) ;
V_209 [ 2 ] = F_426 ( V_799 ) ;
V_209 [ 3 ] = F_426 ( V_800 ) ;
V_209 [ 4 ] = F_426 ( V_801 ) ;
V_209 [ 5 ] = F_426 ( V_802 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_209 ,
V_253 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_435 . V_803 . V_436 = V_253 [ 0 ] ;
V_13 -> V_435 . V_803 . V_200 = V_253 [ 1 ] - V_253 [ 0 ] + 1 ;
V_13 -> V_435 . V_804 . V_436 = V_253 [ 2 ] ;
V_13 -> V_435 . V_804 . V_200 = V_253 [ 3 ] - V_253 [ 2 ] + 1 ;
V_13 -> V_435 . V_655 . V_436 = V_253 [ 4 ] ;
V_13 -> V_435 . V_655 . V_200 = V_253 [ 5 ] - V_253 [ 4 ] + 1 ;
V_209 [ 0 ] = F_425 ( V_805 ) ;
V_209 [ 1 ] = F_425 ( V_806 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 ,
V_253 ) ;
if ( V_43 < 0 ) {
V_13 -> V_209 . V_537 = 8 ;
V_13 -> V_209 . V_538 = 32 * V_13 -> V_79 . V_350 ;
V_43 = 0 ;
} else {
V_13 -> V_209 . V_537 = V_253 [ 0 ] ;
V_13 -> V_209 . V_538 = V_253 [ 1 ] ;
}
F_401 ( V_13 -> V_30 ,
L_75 ,
V_13 -> V_209 . V_537 ,
V_13 -> V_209 . V_538 ) ;
}
if ( V_710 . V_807 ) {
V_209 [ 0 ] = F_426 ( V_808 ) ;
V_209 [ 1 ] = F_426 ( V_809 ) ;
V_43 = F_408 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_209 , V_253 ) ;
if ( V_43 < 0 )
goto V_723;
V_13 -> V_435 . V_810 . V_436 = V_253 [ 0 ] ;
V_13 -> V_435 . V_810 . V_200 = V_253 [ 1 ] - V_253 [ 0 ] + 1 ;
}
#undef F_426
#undef F_425
F_431 ( V_13 , V_13 -> V_209 . V_384 , NULL ) ;
if ( V_64 != V_747 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_385 ; V_19 ++ )
if ( V_13 -> V_209 . V_384 [ V_19 ] == 1492 ) {
V_13 -> V_209 . V_384 [ V_19 ] = 1488 ;
break;
}
F_432 ( V_13 , V_13 -> V_209 . V_384 , V_13 -> V_209 . V_811 ,
V_13 -> V_209 . V_812 ) ;
}
F_433 ( V_13 ) ;
V_13 -> V_53 |= V_813 ;
F_434 ( V_13 ) ;
return 0 ;
V_723:
F_83 ( V_13 -> V_16 . V_107 ) ;
F_83 ( V_13 -> V_16 . V_188 ) ;
F_83 ( V_13 -> V_16 . V_201 ) ;
F_83 ( V_13 -> V_16 . V_203 ) ;
#ifdef F_184
F_83 ( V_13 -> V_16 . V_767 ) ;
#endif
if ( V_43 != - V_814 && V_43 != - V_815 )
F_435 ( V_13 , V_13 -> V_27 ) ;
return V_43 ;
}
static T_15 F_436 ( struct V_403 * V_147 ,
T_16 V_64 )
{
int V_19 ;
struct V_12 * V_13 = F_239 ( V_147 ) ;
if ( ! V_13 )
goto V_102;
F_437 () ;
V_13 -> V_53 &= ~ V_813 ;
F_314 ( V_13 , V_816 ) ;
F_240 ( & V_13 -> V_407 ) ;
F_70 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
F_438 ( V_2 ) ;
F_17 ( V_2 ) ;
}
F_242 ( & V_13 -> V_407 ) ;
F_92 ( V_13 ) ;
if ( V_13 -> V_53 & V_193 )
F_330 ( V_13 ) ;
F_439 () ;
if ( ( V_13 -> V_53 & V_817 ) ) {
F_440 ( V_147 ) ;
V_13 -> V_53 &= ~ V_817 ;
}
V_102: return V_64 == V_818 ?
V_819 : V_820 ;
}
static T_15 F_441 ( struct V_403 * V_147 )
{
int V_19 , V_43 ;
struct V_661 V_662 ;
struct V_12 * V_13 = F_239 ( V_147 ) ;
if ( ! V_13 ) {
F_442 ( V_147 ) ;
F_443 ( V_147 ) ;
return V_821 ;
}
if ( ! ( V_13 -> V_53 & V_817 ) ) {
if ( F_444 ( V_147 ) ) {
F_11 ( & V_147 -> V_2 , L_76
L_77 ) ;
return V_819 ;
}
V_13 -> V_53 |= V_817 ;
}
F_445 ( V_147 ) ;
F_442 ( V_147 ) ;
F_443 ( V_147 ) ;
F_446 ( V_147 ) ;
if ( F_447 ( V_13 -> V_525 ) < 0 )
return V_819 ;
if ( F_417 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_822 , NULL ) < 0 )
return V_819 ;
V_13 -> V_53 |= V_813 ;
if ( F_372 ( V_13 , & V_662 ) )
return V_819 ;
F_70 (adap, i) {
struct V_5 * V_6 = F_85 ( V_13 , V_19 ) ;
V_43 = F_448 ( V_13 , V_13 -> V_27 , V_6 -> V_60 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_43 < 0 )
return V_819 ;
V_6 -> V_50 = V_43 ;
V_6 -> V_58 = - 1 ;
}
F_432 ( V_13 , V_13 -> V_209 . V_384 , V_13 -> V_209 . V_811 ,
V_13 -> V_209 . V_812 ) ;
F_361 ( V_13 ) ;
if ( F_326 ( V_13 ) )
return V_819 ;
return V_821 ;
}
static void F_449 ( struct V_403 * V_147 )
{
int V_19 ;
struct V_12 * V_13 = F_239 ( V_147 ) ;
if ( ! V_13 )
return;
F_437 () ;
F_70 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
if ( F_13 ( V_2 ) ) {
F_29 ( V_2 ) ;
F_354 ( V_2 ) ;
}
F_450 ( V_2 ) ;
}
F_439 () ;
}
static inline bool F_451 ( const struct V_823 * V_824 )
{
return ( V_824 -> V_825 & V_826 ) != 0 ||
( V_824 -> V_825 & V_827 ) != 0 ;
}
static inline void F_452 ( struct V_12 * V_13 , struct V_92 * V_25 ,
unsigned int V_308 , unsigned int V_309 ,
unsigned int V_200 , unsigned int V_828 )
{
V_25 -> V_13 = V_13 ;
F_177 ( V_25 , V_308 , V_309 ) ;
V_25 -> V_829 = V_828 ;
V_25 -> V_200 = V_200 ;
}
static void F_453 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 , V_830 = 0 , V_831 = 0 ;
#ifndef F_15
int V_832 = 0 ;
#endif
int V_833 ;
F_70 (adap, i)
V_830 += F_451 ( & F_85 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_15
if ( V_13 -> V_209 . V_210 * 8 > V_834 ) {
F_11 ( V_13 -> V_30 , L_78 ,
V_834 , V_13 -> V_209 . V_210 * 8 ) ;
F_454 ( 1 ) ;
}
F_70 (adap, i) {
struct V_5 * V_11 = F_85 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_831 ;
V_11 -> V_20 = 8 ;
V_831 += V_11 -> V_20 ;
}
#else
if ( V_830 )
V_832 = ( V_834 - ( V_13 -> V_209 . V_210 - V_830 ) ) / V_830 ;
if ( V_832 > F_455 () )
V_832 = F_455 () ;
F_70 (adap, i) {
struct V_5 * V_11 = F_85 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_831 ;
V_11 -> V_20 = F_451 ( & V_11 -> V_7 ) ? V_832 : 1 ;
V_831 += V_11 -> V_20 ;
}
#endif
V_4 -> V_835 = V_831 ;
V_4 -> V_836 = V_831 ;
if ( F_382 ( V_13 ) ) {
if ( V_830 ) {
V_19 = F_456 ( int , F_19 ( V_4 -> V_172 ) ,
F_457 () ) ;
V_4 -> V_208 = F_458 ( V_19 , V_13 -> V_209 . V_210 ) ;
} else
V_4 -> V_208 = V_13 -> V_209 . V_210 ;
V_4 -> V_212 = V_13 -> V_209 . V_210 ;
V_4 -> V_214 = F_456 ( int , V_837 , F_457 () ) ;
V_4 -> V_214 = ( V_4 -> V_214 / V_13 -> V_209 . V_210 ) *
V_13 -> V_209 . V_210 ;
V_4 -> V_214 = F_459 ( int , V_4 -> V_214 , V_13 -> V_209 . V_210 ) ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_170 ) ; V_19 ++ ) {
struct V_177 * V_838 = & V_4 -> V_170 [ V_19 ] ;
F_452 ( V_13 , & V_838 -> V_136 , 5 , 10 , 1024 , 64 ) ;
V_838 -> V_199 . V_200 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_200 = 1024 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_216 ) ; V_19 ++ )
V_4 -> V_216 [ V_19 ] . V_25 . V_200 = 512 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_110 ) ; V_19 ++ )
V_4 -> V_110 [ V_19 ] . V_25 . V_200 = 1024 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_172 ) ; V_19 ++ ) {
struct V_134 * V_838 = & V_4 -> V_172 [ V_19 ] ;
F_452 ( V_13 , & V_838 -> V_136 , 5 , 1 , 1024 , 64 ) ;
V_838 -> V_136 . V_138 = V_504 ;
V_838 -> V_199 . V_200 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_173 ) ; V_19 ++ ) {
struct V_134 * V_838 = & V_4 -> V_173 [ V_19 ] ;
F_452 ( V_13 , & V_838 -> V_136 , 5 , 1 , 511 , 64 ) ;
V_838 -> V_136 . V_138 = V_476 ;
V_838 -> V_199 . V_200 = 72 ;
}
V_833 = 64 + V_13 -> V_435 . V_804 . V_200 + V_13 -> V_79 . V_81 ;
if ( V_833 > V_839 ) {
F_289 ( V_13 , L_79 ) ;
V_833 = V_839 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_174 ) ; V_19 ++ ) {
struct V_134 * V_838 = & V_4 -> V_174 [ V_19 ] ;
F_452 ( V_13 , & V_838 -> V_136 , 5 , 1 , V_833 , 64 ) ;
V_838 -> V_136 . V_138 = V_476 ;
}
F_452 ( V_13 , & V_4 -> V_169 , 0 , 1 , 1024 , 64 ) ;
F_452 ( V_13 , & V_4 -> V_204 , 0 , 1 , 2 * V_675 , 64 ) ;
}
static void F_460 ( struct V_12 * V_13 , int V_158 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_158 < V_13 -> V_16 . V_835 )
F_70 (adap, i) {
V_11 = F_85 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_835 -- ;
if ( V_13 -> V_16 . V_835 <= V_158 )
break;
}
}
V_158 = 0 ;
F_70 (adap, i) {
V_11 = F_85 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_158 ;
V_158 += V_11 -> V_20 ;
}
}
static int F_461 ( struct V_12 * V_13 )
{
int V_840 = 0 ;
int V_19 , V_841 , V_842 , V_843 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_506 = V_13 -> V_209 . V_210 ;
struct V_844 * V_845 ;
V_845 = F_80 ( sizeof( * V_845 ) * ( V_675 + 1 ) ,
V_179 ) ;
if ( ! V_845 )
return - V_180 ;
for ( V_19 = 0 ; V_19 < V_675 + 1 ; ++ V_19 )
V_845 [ V_19 ] . V_846 = V_19 ;
V_841 = V_4 -> V_836 + V_847 ;
if ( F_382 ( V_13 ) ) {
V_841 += V_4 -> V_212 + V_4 -> V_214 + V_4 -> V_208 ;
V_840 = 3 * V_506 ;
}
#ifdef F_15
V_842 = 8 * V_13 -> V_209 . V_210 + V_847 + V_840 ;
#else
V_842 = V_13 -> V_209 . V_210 + V_847 + V_840 ;
#endif
V_843 = F_462 ( V_13 -> V_147 , V_845 , V_842 , V_841 ) ;
if ( V_843 < 0 ) {
F_401 ( V_13 -> V_30 , L_80
L_81 ) ;
F_83 ( V_845 ) ;
return V_843 ;
}
V_19 = V_843 - V_847 - V_840 ;
if ( V_19 < V_4 -> V_836 ) {
V_4 -> V_836 = V_19 ;
if ( V_19 < V_4 -> V_835 )
F_460 ( V_13 , V_19 ) ;
}
if ( F_382 ( V_13 ) ) {
if ( V_843 < V_841 ) {
V_4 -> V_212 = V_506 ;
V_4 -> V_214 = V_506 ;
}
V_19 = V_843 - V_847 - V_4 -> V_836 -
V_4 -> V_212 - V_4 -> V_214 ;
V_4 -> V_208 = ( V_19 / V_506 ) * V_506 ;
}
for ( V_19 = 0 ; V_19 < V_843 ; ++ V_19 )
V_13 -> V_159 [ V_19 ] . V_167 = V_845 [ V_19 ] . V_848 ;
F_401 ( V_13 -> V_30 , L_82
L_83 ,
V_843 , V_4 -> V_836 , V_4 -> V_208 , V_4 -> V_212 ,
V_4 -> V_214 ) ;
F_83 ( V_845 ) ;
return 0 ;
}
static int F_463 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_464 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_70 (adap, i) {
struct V_5 * V_11 = F_85 ( V_13 , V_19 ) ;
V_11 -> V_176 = F_427 ( V_11 -> V_178 , sizeof( T_3 ) , V_179 ) ;
if ( ! V_11 -> V_176 )
return - V_180 ;
}
return 0 ;
}
static void F_465 ( const struct V_1 * V_2 )
{
char V_736 [ 80 ] ;
char * V_849 = V_736 ;
const char * V_850 = L_84 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_209 . V_851 . V_8 == V_852 )
V_850 = L_85 ;
else if ( V_13 -> V_209 . V_851 . V_8 == V_853 )
V_850 = L_86 ;
else if ( V_13 -> V_209 . V_851 . V_8 == V_854 )
V_850 = L_87 ;
if ( V_11 -> V_7 . V_825 & V_855 )
V_849 += sprintf ( V_849 , L_88 ) ;
if ( V_11 -> V_7 . V_825 & V_856 )
V_849 += sprintf ( V_849 , L_89 ) ;
if ( V_11 -> V_7 . V_825 & V_826 )
V_849 += sprintf ( V_849 , L_90 ) ;
if ( V_11 -> V_7 . V_825 & V_827 )
V_849 += sprintf ( V_849 , L_91 ) ;
if ( V_849 != V_736 )
-- V_849 ;
sprintf ( V_849 , L_92 , F_466 ( V_11 -> V_857 ) ) ;
F_3 ( V_2 , L_93 ,
V_13 -> V_209 . V_513 . V_858 ,
F_467 ( V_13 -> V_209 . V_217 ) , V_736 ,
F_382 ( V_13 ) ? L_94 : L_84 , V_13 -> V_209 . V_851 . V_859 , V_850 ,
( V_13 -> V_53 & V_146 ) ? L_95 :
( V_13 -> V_53 & V_148 ) ? L_96 : L_84 ) ;
F_3 ( V_2 , L_97 ,
V_13 -> V_209 . V_513 . V_860 , V_13 -> V_209 . V_513 . V_861 ) ;
}
static void F_468 ( struct V_403 * V_2 )
{
F_469 ( V_2 , V_862 , V_863 ) ;
}
static void F_470 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_116 ( V_12 -> V_74 ) ;
F_116 ( V_12 -> V_79 . V_341 ) ;
F_83 ( V_12 -> V_16 . V_107 ) ;
F_83 ( V_12 -> V_16 . V_188 ) ;
F_83 ( V_12 -> V_16 . V_201 ) ;
F_83 ( V_12 -> V_16 . V_203 ) ;
#ifdef F_184
F_83 ( V_12 -> V_16 . V_767 ) ;
#endif
F_61 ( V_12 ) ;
F_70 (adapter, i)
if ( V_12 -> V_34 [ V_19 ] ) {
struct V_5 * V_11 = F_85 ( V_12 , V_19 ) ;
if ( V_11 -> V_50 != 0 )
F_471 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_50 ) ;
F_83 ( F_85 ( V_12 , V_19 ) -> V_176 ) ;
F_472 ( V_12 -> V_34 [ V_19 ] ) ;
}
if ( V_12 -> V_53 & V_813 )
F_435 ( V_12 , V_12 -> V_28 ) ;
}
static int F_473 ( struct V_403 * V_147 , T_1 V_864 )
{
T_3 V_865 ;
F_474 ( V_147 , V_866 , & V_865 ) ;
switch ( V_865 >> 12 ) {
case V_724 :
return F_475 ( V_724 , V_864 ) ;
case V_358 :
return F_475 ( V_358 , V_864 ) ;
case V_727 :
return F_475 ( V_727 , V_864 ) ;
default:
F_11 ( & V_147 -> V_2 , L_51 ,
V_865 ) ;
}
return - V_444 ;
}
static int F_476 ( struct V_403 * V_147 , const struct V_867 * V_868 )
{
int V_869 , V_19 , V_22 , V_870 , V_871 , V_872 ;
struct V_5 * V_11 ;
bool V_873 = false ;
struct V_12 * V_12 = NULL ;
void T_17 * V_525 ;
T_1 V_874 , V_864 ;
enum V_395 V_217 ;
F_477 ( V_875 L_98 , V_876 , V_877 ) ;
V_22 = F_478 ( V_147 , V_878 ) ;
if ( V_22 ) {
F_401 ( & V_147 -> V_2 , L_99 ) ;
return V_22 ;
}
V_22 = F_444 ( V_147 ) ;
if ( V_22 ) {
F_11 ( & V_147 -> V_2 , L_100 ) ;
goto V_879;
}
V_525 = F_479 ( V_147 , 0 ) ;
if ( ! V_525 ) {
F_11 ( & V_147 -> V_2 , L_101 ) ;
V_22 = - V_180 ;
goto V_880;
}
V_22 = F_447 ( V_525 ) ;
if ( V_22 < 0 )
goto V_881;
V_874 = F_480 ( V_525 + V_882 ) ;
V_864 = F_481 ( F_480 ( V_525 + V_883 ) ) ;
V_217 = F_473 ( V_147 , V_864 ) ;
V_869 = F_214 ( V_217 ) <= V_358 ?
F_482 ( V_874 ) : F_483 ( V_874 ) ;
if ( V_869 != V_868 -> V_884 ) {
F_484 ( V_525 ) ;
F_440 ( V_147 ) ;
F_443 ( V_147 ) ;
goto V_885;
}
if ( ! F_485 ( V_147 , F_486 ( 64 ) ) ) {
V_873 = true ;
V_22 = F_487 ( V_147 , F_486 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_147 -> V_2 , L_102
L_103 ) ;
goto V_881;
}
} else {
V_22 = F_485 ( V_147 , F_486 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_147 -> V_2 , L_104 ) ;
goto V_881;
}
}
F_488 ( V_147 ) ;
F_468 ( V_147 ) ;
F_445 ( V_147 ) ;
F_443 ( V_147 ) ;
V_12 = F_114 ( sizeof( * V_12 ) , V_179 ) ;
if ( ! V_12 ) {
V_22 = - V_180 ;
goto V_881;
}
V_12 -> V_346 = F_489 ( L_105 ) ;
if ( ! V_12 -> V_346 ) {
V_22 = - V_180 ;
goto V_886;
}
V_12 -> V_53 |= V_817 ;
V_12 -> V_525 = V_525 ;
V_12 -> V_147 = V_147 ;
V_12 -> V_30 = & V_147 -> V_2 ;
V_12 -> V_27 = V_869 ;
V_12 -> V_28 = V_869 ;
V_12 -> V_887 = V_888 ;
memset ( V_12 -> V_889 , 0xff , sizeof( V_12 -> V_889 ) ) ;
F_212 ( & V_12 -> V_407 ) ;
F_212 ( & V_12 -> V_342 ) ;
F_212 ( & V_12 -> V_416 ) ;
F_490 ( & V_12 -> V_347 , F_205 ) ;
F_490 ( & V_12 -> V_477 , F_286 ) ;
F_490 ( & V_12 -> V_484 , F_291 ) ;
V_22 = F_491 ( V_12 ) ;
if ( V_22 )
goto V_886;
if ( ! F_110 ( V_12 -> V_209 . V_217 ) ) {
V_870 = ( V_890 +
( V_891 - V_890 ) *
V_12 -> V_28 ) ;
V_871 = 1 << F_492 ( F_65 ( V_12 ,
V_892 ) >> V_870 ) ;
V_872 = V_691 / V_893 ;
if ( V_871 > V_872 ) {
F_11 ( & V_147 -> V_2 ,
L_106 ) ;
V_22 = - V_444 ;
goto V_886;
}
V_12 -> V_490 = F_493 ( F_494 ( V_147 , 2 ) ,
F_495 ( V_147 , 2 ) ) ;
if ( ! V_12 -> V_490 ) {
F_11 ( & V_147 -> V_2 , L_107 ) ;
V_22 = - V_180 ;
goto V_886;
}
}
F_361 ( V_12 ) ;
V_22 = F_415 ( V_12 ) ;
#ifdef F_184
F_102 ( V_12 -> V_16 . V_767 , V_12 -> V_16 . V_202 ) ;
#endif
F_364 ( V_12 ) ;
if ( V_22 )
goto V_894;
if ( ! F_110 ( V_12 -> V_209 . V_217 ) )
F_67 ( V_12 , V_895 ,
F_496 ( 7 ) | F_497 ( 0 ) ) ;
F_70 (adapter, i) {
struct V_1 * V_189 ;
V_189 = F_498 ( sizeof( struct V_5 ) ,
V_834 ) ;
if ( ! V_189 ) {
V_22 = - V_180 ;
goto V_896;
}
F_499 ( V_189 , & V_147 -> V_2 ) ;
V_12 -> V_34 [ V_19 ] = V_189 ;
V_11 = F_4 ( V_189 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_58 = - 1 ;
V_11 -> V_31 = V_19 ;
V_189 -> V_149 = V_147 -> V_149 ;
V_189 -> V_897 = V_898 | V_899 |
V_900 | V_901 |
V_902 | V_903 |
V_904 | V_57 ;
if ( V_873 )
V_189 -> V_897 |= V_905 ;
V_189 -> V_56 |= V_189 -> V_897 ;
V_189 -> V_906 = V_189 -> V_56 & V_907 ;
V_189 -> V_461 |= V_908 ;
V_189 -> V_909 = & V_910 ;
#ifdef F_15
V_189 -> V_911 = & V_912 ;
F_16 ( V_189 ) ;
#endif
F_500 ( V_189 ) ;
}
F_501 ( V_147 , V_12 ) ;
if ( V_12 -> V_53 & V_813 ) {
V_22 = F_502 ( V_12 , V_869 , V_869 , 0 ) ;
if ( V_22 )
goto V_896;
} else if ( V_12 -> V_209 . V_210 == 1 ) {
T_4 V_913 [ V_914 ] ;
T_4 * V_915 = V_12 -> V_209 . V_513 . V_915 ;
V_22 = F_503 ( V_12 , & V_12 -> V_209 . V_513 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_914 ; V_19 ++ )
V_913 [ V_19 ] = ( F_504 ( V_915 [ 2 * V_19 + 0 ] ) * 16 +
F_504 ( V_915 [ 2 * V_19 + 1 ] ) ) ;
F_505 ( V_12 , 0 , V_913 ) ;
}
}
F_453 ( V_12 ) ;
V_12 -> V_74 = F_506 ( V_12 -> V_763 , V_12 -> V_764 ) ;
if ( ! V_12 -> V_74 ) {
F_300 ( & V_147 -> V_2 , L_108 ) ;
V_12 -> V_209 . V_787 = 0 ;
}
#if F_319 ( V_572 )
V_12 -> V_916 = F_507 ( V_12 -> V_770 ,
V_12 -> V_771 ) ;
if ( ! V_12 -> V_916 ) {
F_300 ( & V_147 -> V_2 ,
L_109 ) ;
V_12 -> V_209 . V_787 = 0 ;
}
#endif
if ( F_382 ( V_12 ) && F_210 ( & V_12 -> V_79 ) < 0 ) {
F_300 ( & V_147 -> V_2 , L_110
L_111 ) ;
V_12 -> V_209 . V_787 = 0 ;
}
if ( F_382 ( V_12 ) ) {
if ( F_65 ( V_12 , V_917 ) & V_918 ) {
T_1 V_351 , V_919 ;
if ( V_217 <= V_358 ) {
V_919 = V_920 ;
V_351 = F_65 ( V_12 , V_919 ) ;
V_12 -> V_79 . V_351 = V_351 / 4 ;
} else {
V_919 = V_921 ;
V_351 = F_65 ( V_12 , V_919 ) ;
V_12 -> V_79 . V_351 = V_351 ;
}
}
}
if ( V_922 > 1 && F_461 ( V_12 ) == 0 )
V_12 -> V_53 |= V_146 ;
else if ( V_922 > 0 && F_508 ( V_147 ) == 0 )
V_12 -> V_53 |= V_148 ;
V_22 = F_463 ( V_12 ) ;
if ( V_22 )
goto V_896;
F_70 (adapter, i) {
V_11 = F_85 ( V_12 , V_19 ) ;
F_509 ( V_12 -> V_34 [ V_19 ] , V_11 -> V_20 ) ;
F_510 ( V_12 -> V_34 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_511 ( V_12 -> V_34 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_889 [ V_11 -> V_60 ] = V_19 ;
F_465 ( V_12 -> V_34 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_147 -> V_2 , L_112 ) ;
goto V_896;
}
if ( V_22 ) {
F_300 ( & V_147 -> V_2 , L_113 , V_19 ) ;
V_22 = 0 ;
}
if ( V_923 ) {
V_12 -> V_314 = F_512 ( F_513 ( V_147 ) ,
V_923 ) ;
F_182 ( V_12 ) ;
}
V_147 -> V_924 = 1 ;
if ( F_382 ( V_12 ) )
F_304 ( V_12 ) ;
V_885:
#ifdef F_514
if ( V_869 < F_19 ( V_925 ) && V_925 [ V_869 ] > 0 )
if ( F_515 ( V_147 , V_925 [ V_869 ] ) == 0 )
F_401 ( & V_147 -> V_2 ,
L_114 ,
V_925 [ V_869 ] ) ;
#endif
return 0 ;
V_896:
F_470 ( V_12 ) ;
V_894:
if ( ! F_110 ( V_12 -> V_209 . V_217 ) )
F_484 ( V_12 -> V_490 ) ;
V_886:
if ( V_12 -> V_346 )
F_516 ( V_12 -> V_346 ) ;
F_83 ( V_12 ) ;
V_881:
F_484 ( V_525 ) ;
V_880:
F_517 ( V_147 ) ;
F_440 ( V_147 ) ;
V_879:
F_518 ( V_147 ) ;
return V_22 ;
}
static void F_519 ( struct V_403 * V_147 )
{
struct V_12 * V_12 = F_239 ( V_147 ) ;
#ifdef F_514
F_520 ( V_147 ) ;
#endif
if ( V_12 ) {
int V_19 ;
F_516 ( V_12 -> V_346 ) ;
if ( F_382 ( V_12 ) )
F_309 ( V_12 ) ;
F_92 ( V_12 ) ;
F_70 (adapter, i)
if ( V_12 -> V_34 [ V_19 ] -> V_926 == V_927 )
F_521 ( V_12 -> V_34 [ V_19 ] ) ;
F_522 ( V_12 -> V_314 ) ;
if ( V_12 -> V_79 . V_84 ) {
struct V_72 * V_73 = & V_12 -> V_79 . V_84 [ 0 ] ;
for ( V_19 = 0 ; V_19 < ( V_12 -> V_79 . V_81 +
V_12 -> V_79 . V_82 ) ; V_19 ++ , V_73 ++ )
if ( V_73 -> V_91 )
F_40 ( V_12 , V_73 ) ;
}
if ( V_12 -> V_53 & V_193 )
F_330 ( V_12 ) ;
F_470 ( V_12 ) ;
#if F_319 ( V_572 )
F_523 ( V_12 ) ;
#endif
F_484 ( V_12 -> V_525 ) ;
if ( ! F_110 ( V_12 -> V_209 . V_217 ) )
F_484 ( V_12 -> V_490 ) ;
F_517 ( V_147 ) ;
if ( ( V_12 -> V_53 & V_817 ) ) {
F_440 ( V_147 ) ;
V_12 -> V_53 &= ~ V_817 ;
}
F_518 ( V_147 ) ;
F_524 () ;
F_83 ( V_12 ) ;
} else
F_518 ( V_147 ) ;
}
static int T_18 F_525 ( void )
{
int V_43 ;
V_923 = F_512 ( V_878 , NULL ) ;
if ( ! V_923 )
F_526 ( L_115 ) ;
V_43 = F_527 ( & V_464 ) ;
if ( V_43 < 0 )
F_528 ( V_923 ) ;
#if F_319 ( V_572 )
if ( ! V_928 ) {
F_529 ( & V_929 ) ;
V_928 = true ;
}
#endif
return V_43 ;
}
static void T_19 F_530 ( void )
{
#if F_319 ( V_572 )
if ( V_928 ) {
F_531 ( & V_929 ) ;
V_928 = false ;
}
#endif
F_532 ( & V_464 ) ;
F_528 ( V_923 ) ;
}
