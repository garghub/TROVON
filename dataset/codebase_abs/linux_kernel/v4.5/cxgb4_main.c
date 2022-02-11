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
F_71 (s, iscsiqidx) {
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
F_77 ( V_13 -> V_159 [ V_166 ++ ] . V_167 ,
& V_4 -> V_172 [ V_19 ] . V_136 ) ;
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
V_73 -> V_74 = F_120 ( V_12 , V_73 -> V_227 . V_230 ,
V_73 -> V_227 . V_231 , V_73 -> V_227 . V_232 ) ;
if ( V_73 -> V_74 == NULL ) {
F_121 ( V_223 ) ;
return - V_180 ;
}
}
V_226 = V_12 -> V_79 . V_80 + V_221 ;
V_225 = (struct V_224 * ) F_122 ( V_223 , sizeof( * V_225 ) ) ;
memset ( V_225 , 0 , sizeof( * V_225 ) ) ;
V_225 -> V_233 = F_123 ( F_124 ( V_234 ) ) ;
V_225 -> V_235 = F_123 ( F_125 ( sizeof( * V_225 ) / 16 ) ) ;
V_225 -> V_236 =
F_123 ( F_126 ( V_226 ) |
F_127 ( V_73 -> V_227 . type ) |
F_128 ( 0 ) |
F_129 ( V_73 -> V_227 . V_237 ) ) ;
V_225 -> V_238 =
F_123 ( F_130 ( V_73 -> V_227 . V_239 ) |
F_131 ( V_73 -> V_227 . V_119 == V_240 ) |
F_132 ( V_73 -> V_227 . V_241 ) |
F_133 ( V_73 -> V_227 . V_242 ) |
F_134 ( V_73 -> V_227 . V_243 ) |
F_135 ( V_73 -> V_227 . V_119 == V_244 ) |
F_136 ( V_73 -> V_227 . V_228 ) |
F_137 ( V_73 -> V_227 . V_245 ) |
F_138 ( V_73 -> V_227 . V_229 == V_246 ||
V_73 -> V_227 . V_229 == V_247 ) |
F_139 ( V_73 -> V_227 . V_229 == V_248 ||
V_73 -> V_227 . V_229 == V_247 ) |
F_140 ( V_73 -> V_227 . V_249 ) |
F_141 ( V_73 -> V_227 . V_231 ) |
F_142 ( V_73 -> V_227 . V_250 ) |
F_143 ( V_73 -> V_74 ? V_73 -> V_74 -> V_77 : 0 ) ) ;
V_225 -> V_251 = F_144 ( V_73 -> V_227 . V_252 . V_251 ) ;
V_225 -> V_253 = F_144 ( V_73 -> V_227 . V_254 . V_251 ) ;
V_225 -> V_255 =
( F_145 ( V_73 -> V_227 . V_252 . V_256 ) |
F_146 ( V_73 -> V_227 . V_254 . V_256 ) |
F_147 ( V_73 -> V_227 . V_252 . V_257 ) |
F_148 ( V_73 -> V_227 . V_252 . V_258 ) |
F_149 ( V_73 -> V_227 . V_254 . V_257 ) |
F_150 ( V_73 -> V_227 . V_254 . V_258 ) ) ;
V_225 -> V_259 = 0 ;
V_225 -> V_260 =
F_144 ( F_151 ( 0 ) |
F_152 ( V_12 -> V_16 . V_169 . V_181 ) ) ;
V_225 -> V_261 =
F_123 ( F_153 ( V_73 -> V_227 . V_252 . V_262 ) |
F_154 ( V_73 -> V_227 . V_254 . V_262 ) |
F_155 ( V_73 -> V_227 . V_252 . V_263 ) |
F_156 ( V_73 -> V_227 . V_254 . V_263 ) |
F_157 ( V_73 -> V_227 . V_252 . V_264 ) |
F_158 ( V_73 -> V_227 . V_254 . V_264 ) |
F_159 ( V_73 -> V_227 . V_252 . V_265 ) |
F_160 ( V_73 -> V_227 . V_254 . V_265 ) ) ;
V_225 -> V_266 = V_73 -> V_227 . V_252 . V_267 ;
V_225 -> V_268 = V_73 -> V_227 . V_254 . V_267 ;
V_225 -> V_269 = V_73 -> V_227 . V_252 . V_270 ;
V_225 -> V_271 = V_73 -> V_227 . V_254 . V_270 ;
V_225 -> V_272 = F_144 ( V_73 -> V_227 . V_252 . V_272 ) ;
V_225 -> V_273 = F_144 ( V_73 -> V_227 . V_254 . V_272 ) ;
V_225 -> V_274 = F_144 ( V_73 -> V_227 . V_252 . V_274 ) ;
V_225 -> V_275 = F_144 ( V_73 -> V_227 . V_254 . V_274 ) ;
memcpy ( V_225 -> V_276 , V_73 -> V_227 . V_252 . V_276 , sizeof( V_225 -> V_276 ) ) ;
memcpy ( V_225 -> V_277 , V_73 -> V_227 . V_254 . V_276 , sizeof( V_225 -> V_277 ) ) ;
memcpy ( V_225 -> V_278 , V_73 -> V_227 . V_252 . V_278 , sizeof( V_225 -> V_278 ) ) ;
memcpy ( V_225 -> V_279 , V_73 -> V_227 . V_254 . V_278 , sizeof( V_225 -> V_279 ) ) ;
V_225 -> V_280 = F_144 ( V_73 -> V_227 . V_252 . V_281 ) ;
V_225 -> V_282 = F_144 ( V_73 -> V_227 . V_254 . V_281 ) ;
V_225 -> V_283 = F_144 ( V_73 -> V_227 . V_252 . V_284 ) ;
V_225 -> V_285 = F_144 ( V_73 -> V_227 . V_254 . V_284 ) ;
if ( V_73 -> V_227 . V_245 )
memcpy ( V_225 -> V_286 , V_73 -> V_227 . V_287 , sizeof( V_225 -> V_286 ) ) ;
V_73 -> V_90 = 1 ;
F_161 ( V_223 , V_288 , V_73 -> V_227 . V_252 . V_264 & 0x3 ) ;
F_162 ( V_12 , V_223 ) ;
return 0 ;
}
static int F_163 ( struct V_12 * V_12 , int V_221 )
{
struct V_72 * V_73 = & V_12 -> V_79 . V_84 [ V_221 ] ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
unsigned int V_289 , V_226 ;
V_289 = sizeof( * V_225 ) ;
V_226 = V_12 -> V_79 . V_80 + V_221 ;
V_223 = F_119 ( V_289 , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_225 = (struct V_224 * ) F_122 ( V_223 , V_289 ) ;
F_164 ( V_226 , V_225 , V_12 -> V_16 . V_169 . V_181 ) ;
V_73 -> V_90 = 1 ;
F_165 ( V_12 , V_223 ) ;
return 0 ;
}
static T_3 F_166 ( struct V_1 * V_2 , struct V_222 * V_223 ,
void * V_290 , T_9 V_291 )
{
int V_15 ;
#ifdef F_15
if ( F_35 ( V_2 ) ) {
T_3 V_292 ;
int V_22 ;
V_22 = F_167 ( V_223 , & V_292 ) ;
if ( F_47 ( V_22 ) ) {
if ( F_168 () )
F_169 ( V_2 ,
L_33 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_292 & V_293 ) >> V_294 ;
#ifdef F_170
if ( V_223 -> V_295 == F_144 ( V_296 ) )
V_15 = V_223 -> V_297 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_298 ) {
V_15 = ( F_171 ( V_223 )
? F_172 ( V_223 )
: F_173 () ) ;
while ( F_47 ( V_15 >= V_2 -> V_299 ) )
V_15 -= V_2 -> V_299 ;
return V_15 ;
}
return V_291 ( V_2 , V_223 ) % V_2 -> V_299 ;
}
static int F_174 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_300 , V_301 = 0 , V_302 = V_303 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_304 ) ; V_19 ++ ) {
V_300 = time - V_4 -> V_304 [ V_19 ] ;
if ( V_300 < 0 )
V_300 = - V_300 ;
if ( V_300 < V_302 ) {
V_302 = V_300 ;
V_301 = V_19 ;
}
}
return V_301 ;
}
static int F_175 ( const struct V_16 * V_4 , int V_305 )
{
int V_19 , V_300 , V_301 = 0 , V_302 = V_303 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_306 ) ; V_19 ++ ) {
V_300 = V_305 - V_4 -> V_306 [ V_19 ] ;
if ( V_300 < 0 )
V_300 = - V_300 ;
if ( V_300 < V_302 ) {
V_302 = V_300 ;
V_301 = V_19 ;
}
}
return V_301 ;
}
int F_176 ( struct V_92 * V_25 ,
unsigned int V_307 , unsigned int V_308 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_307 | V_308 ) == 0 )
V_308 = 1 ;
if ( V_308 ) {
int V_22 ;
T_1 V_150 , V_309 ;
V_309 = F_175 ( & V_13 -> V_16 , V_308 ) ;
if ( V_25 -> V_160 && V_25 -> V_310 != V_309 ) {
V_150 = F_7 ( V_23 ) |
F_8 (
V_311 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_177 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_150 , & V_309 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_310 = V_309 ;
}
V_307 = V_307 == 0 ? 6 : F_174 ( & V_13 -> V_16 , V_307 ) ;
V_25 -> V_195 = F_178 ( V_307 ) | F_179 ( V_308 > 0 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , T_10 V_56 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_10 V_312 = V_2 -> V_56 ^ V_56 ;
int V_22 ;
if ( ! ( V_312 & V_57 ) )
return 0 ;
V_22 = F_28 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_50 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_56 & V_57 ) , true ) ;
if ( F_47 ( V_22 ) )
V_2 -> V_56 = V_56 ^ V_57 ;
return V_22 ;
}
static int F_181 ( struct V_12 * V_13 )
{
if ( F_182 ( V_13 -> V_313 ) )
return - 1 ;
#ifdef F_183
F_184 ( V_13 ) ;
#endif
return 0 ;
}
int F_185 ( struct V_314 * V_206 , void * V_117 )
{
int V_315 = - 1 ;
F_186 ( & V_206 -> V_316 ) ;
if ( V_206 -> V_317 ) {
union V_318 * V_6 = V_206 -> V_317 ;
V_315 = ( V_6 - V_206 -> V_319 ) + V_206 -> V_320 ;
V_206 -> V_317 = V_6 -> V_321 ;
V_6 -> V_117 = V_117 ;
V_206 -> V_322 ++ ;
}
F_187 ( & V_206 -> V_316 ) ;
return V_315 ;
}
void F_188 ( struct V_314 * V_206 , unsigned int V_315 )
{
union V_318 * V_6 = & V_206 -> V_319 [ V_315 - V_206 -> V_320 ] ;
F_186 ( & V_206 -> V_316 ) ;
V_6 -> V_321 = V_206 -> V_317 ;
V_206 -> V_317 = V_6 ;
V_206 -> V_322 -- ;
F_187 ( & V_206 -> V_316 ) ;
}
int F_189 ( struct V_314 * V_206 , int V_323 , void * V_117 )
{
int V_324 ;
F_186 ( & V_206 -> V_325 ) ;
if ( V_323 == V_326 ) {
V_324 = F_190 ( V_206 -> V_327 , V_206 -> V_328 ) ;
if ( V_324 < V_206 -> V_328 )
F_191 ( V_324 , V_206 -> V_327 ) ;
else
V_324 = - 1 ;
} else {
V_324 = F_192 ( V_206 -> V_327 , V_206 -> V_328 , 1 ) ;
if ( V_324 < 0 )
V_324 = - 1 ;
}
if ( V_324 >= 0 ) {
V_206 -> V_329 [ V_324 ] . V_117 = V_117 ;
V_324 += V_206 -> V_330 ;
if ( V_323 == V_326 )
V_206 -> V_331 ++ ;
else
V_206 -> V_331 += 2 ;
}
F_187 ( & V_206 -> V_325 ) ;
return V_324 ;
}
int F_193 ( struct V_314 * V_206 , int V_323 , void * V_117 )
{
int V_324 ;
F_186 ( & V_206 -> V_325 ) ;
if ( V_323 == V_326 ) {
V_324 = F_194 ( V_206 -> V_327 ,
V_206 -> V_328 + V_206 -> V_82 , V_206 -> V_328 ) ;
if ( V_324 < ( V_206 -> V_328 + V_206 -> V_82 ) )
F_191 ( V_324 , V_206 -> V_327 ) ;
else
V_324 = - 1 ;
} else {
V_324 = - 1 ;
}
if ( V_324 >= 0 ) {
V_206 -> V_329 [ V_324 ] . V_117 = V_117 ;
V_324 -= V_206 -> V_328 ;
V_324 += V_206 -> V_332 ;
V_206 -> V_333 ++ ;
}
F_187 ( & V_206 -> V_325 ) ;
return V_324 ;
}
void F_195 ( struct V_314 * V_206 , unsigned int V_324 , int V_323 )
{
if ( V_206 -> V_82 && ( V_324 >= V_206 -> V_332 ) ) {
V_324 -= V_206 -> V_332 ;
V_324 += V_206 -> V_328 ;
} else {
V_324 -= V_206 -> V_330 ;
}
F_186 ( & V_206 -> V_325 ) ;
if ( V_323 == V_326 )
F_196 ( V_324 , V_206 -> V_327 ) ;
else
F_197 ( V_206 -> V_327 , V_324 , 1 ) ;
V_206 -> V_329 [ V_324 ] . V_117 = NULL ;
if ( V_324 < V_206 -> V_328 ) {
if ( V_323 == V_326 )
V_206 -> V_331 -- ;
else
V_206 -> V_331 -= 2 ;
} else {
V_206 -> V_333 -- ;
}
F_187 ( & V_206 -> V_325 ) ;
}
static void F_198 ( struct V_222 * V_223 , unsigned int V_334 ,
unsigned int V_335 )
{
struct V_336 * V_337 ;
F_161 ( V_223 , V_338 , V_334 ) ;
V_337 = (struct V_336 * ) F_122 ( V_223 , sizeof( * V_337 ) ) ;
F_199 ( V_337 , V_335 ) ;
F_200 ( V_337 ) = F_123 ( F_201 ( V_339 , V_335 ) ) ;
}
static void F_202 ( struct V_314 * V_206 , unsigned int V_334 ,
unsigned int V_335 )
{
void * * V_6 = & V_206 -> V_340 [ V_335 ] ;
struct V_12 * V_13 = F_50 ( V_206 , struct V_12 , V_79 ) ;
F_186 ( & V_13 -> V_341 ) ;
* V_6 = V_13 -> V_342 ;
V_13 -> V_342 = ( void * * ) ( ( V_343 ) V_6 | V_334 ) ;
if ( ! V_13 -> V_344 ) {
V_13 -> V_344 = true ;
F_203 ( V_13 -> V_345 , & V_13 -> V_346 ) ;
}
F_187 ( & V_13 -> V_341 ) ;
}
static void F_204 ( struct V_347 * V_348 )
{
struct V_222 * V_223 ;
struct V_12 * V_13 ;
V_13 = F_50 ( V_348 , struct V_12 , V_346 ) ;
F_186 ( & V_13 -> V_341 ) ;
while ( V_13 -> V_342 ) {
void * * V_6 = V_13 -> V_342 ;
unsigned int V_334 = ( V_343 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_334 ;
V_13 -> V_342 = * V_6 ;
* V_6 = NULL ;
F_187 ( & V_13 -> V_341 ) ;
while ( ! ( V_223 = F_119 ( sizeof( struct V_336 ) ,
V_179 ) ) )
F_205 ( 1 ) ;
F_198 ( V_223 , V_334 , V_6 - V_13 -> V_79 . V_340 ) ;
F_162 ( V_13 , V_223 ) ;
F_186 ( & V_13 -> V_341 ) ;
}
V_13 -> V_344 = false ;
F_187 ( & V_13 -> V_341 ) ;
}
void F_206 ( struct V_314 * V_206 , unsigned int V_334 , unsigned int V_335 )
{
struct V_222 * V_223 ;
struct V_12 * V_13 = F_50 ( V_206 , struct V_12 , V_79 ) ;
F_207 ( V_335 >= V_206 -> V_349 ) ;
if ( V_206 -> V_340 [ V_335 ] ) {
V_206 -> V_340 [ V_335 ] = NULL ;
if ( V_206 -> V_350 && ( V_335 >= V_206 -> V_350 ) )
F_208 ( & V_206 -> V_351 ) ;
else
F_208 ( & V_206 -> V_352 ) ;
}
V_223 = F_119 ( sizeof( struct V_336 ) , V_353 ) ;
if ( F_48 ( V_223 ) ) {
F_198 ( V_223 , V_334 , V_335 ) ;
F_162 ( V_13 , V_223 ) ;
} else
F_202 ( V_206 , V_334 , V_335 ) ;
}
static int F_209 ( struct V_314 * V_206 )
{
T_8 V_200 ;
unsigned int V_354 ;
unsigned int V_355 = V_206 -> V_355 ;
struct V_12 * V_13 = F_50 ( V_206 , struct V_12 , V_79 ) ;
V_354 = F_210 ( V_206 -> V_328 + V_206 -> V_82 ) ;
V_200 = V_206 -> V_349 * sizeof( * V_206 -> V_340 ) +
V_355 * sizeof( * V_206 -> V_319 ) +
V_206 -> V_328 * sizeof( * V_206 -> V_329 ) +
V_206 -> V_82 * sizeof( * V_206 -> V_329 ) +
V_354 * sizeof( long ) +
V_206 -> V_81 * sizeof( * V_206 -> V_84 ) +
V_206 -> V_82 * sizeof( * V_206 -> V_84 ) ;
V_206 -> V_340 = F_113 ( V_200 ) ;
if ( ! V_206 -> V_340 )
return - V_180 ;
V_206 -> V_319 = (union V_318 * ) & V_206 -> V_340 [ V_206 -> V_349 ] ;
V_206 -> V_329 = (struct V_356 * ) & V_206 -> V_319 [ V_355 ] ;
V_206 -> V_327 = ( unsigned long * ) & V_206 -> V_329 [ V_206 -> V_328 + V_206 -> V_82 ] ;
V_206 -> V_84 = (struct V_72 * ) & V_206 -> V_327 [ V_354 ] ;
F_211 ( & V_206 -> V_325 ) ;
F_211 ( & V_206 -> V_316 ) ;
V_206 -> V_331 = 0 ;
V_206 -> V_333 = 0 ;
V_206 -> V_317 = NULL ;
V_206 -> V_322 = 0 ;
F_212 ( & V_206 -> V_352 , 0 ) ;
F_212 ( & V_206 -> V_351 , 0 ) ;
if ( V_355 ) {
while ( -- V_355 )
V_206 -> V_319 [ V_355 - 1 ] . V_321 = & V_206 -> V_319 [ V_355 ] ;
V_206 -> V_317 = V_206 -> V_319 ;
}
F_102 ( V_206 -> V_327 , V_206 -> V_328 + V_206 -> V_82 ) ;
if ( ! V_206 -> V_330 &&
( F_213 ( V_13 -> V_209 . V_217 ) <= V_357 ) )
F_191 ( 0 , V_206 -> V_327 ) ;
return 0 ;
}
int F_214 ( const struct V_1 * V_2 , unsigned int V_324 ,
T_11 V_358 , T_12 V_359 , T_12 V_230 ,
unsigned int V_360 )
{
unsigned int V_334 ;
struct V_222 * V_223 ;
struct V_12 * V_13 ;
struct V_361 * V_337 ;
int V_43 ;
V_223 = F_119 ( sizeof( * V_337 ) , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_13 = F_215 ( V_2 ) ;
V_337 = (struct V_361 * ) F_122 ( V_223 , sizeof( * V_337 ) ) ;
F_199 ( V_337 , 0 ) ;
F_200 ( V_337 ) = F_123 ( F_201 ( V_362 , V_324 ) ) ;
V_337 -> V_363 = V_359 ;
V_337 -> V_364 = F_144 ( 0 ) ;
V_337 -> V_365 = V_358 ;
V_337 -> V_366 = F_123 ( 0 ) ;
V_334 = F_86 ( & V_13 -> V_16 , V_360 ) ;
V_337 -> V_367 = F_216 ( F_217 ( V_334 ) ) ;
V_337 -> V_368 = F_216 ( F_218 ( V_369 ) |
V_370 | F_219 ( V_360 ) ) ;
V_43 = F_165 ( V_13 , V_223 ) ;
return F_220 ( V_43 ) ;
}
int F_221 ( const struct V_1 * V_2 , unsigned int V_324 ,
const struct V_371 * V_358 , T_12 V_359 ,
unsigned int V_360 )
{
unsigned int V_334 ;
struct V_222 * V_223 ;
struct V_12 * V_13 ;
struct V_372 * V_337 ;
int V_43 ;
V_223 = F_119 ( sizeof( * V_337 ) , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_13 = F_215 ( V_2 ) ;
V_337 = (struct V_372 * ) F_122 ( V_223 , sizeof( * V_337 ) ) ;
F_199 ( V_337 , 0 ) ;
F_200 ( V_337 ) = F_123 ( F_201 ( V_373 , V_324 ) ) ;
V_337 -> V_363 = V_359 ;
V_337 -> V_364 = F_144 ( 0 ) ;
V_337 -> V_374 = * ( T_5 * ) ( V_358 -> V_375 ) ;
V_337 -> V_376 = * ( T_5 * ) ( V_358 -> V_375 + 8 ) ;
V_337 -> V_377 = F_216 ( 0 ) ;
V_337 -> V_378 = F_216 ( 0 ) ;
V_334 = F_86 ( & V_13 -> V_16 , V_360 ) ;
V_337 -> V_367 = F_216 ( F_217 ( V_334 ) ) ;
V_337 -> V_368 = F_216 ( F_218 ( V_369 ) |
V_370 | F_219 ( V_360 ) ) ;
V_43 = F_165 ( V_13 , V_223 ) ;
return F_220 ( V_43 ) ;
}
int F_222 ( const struct V_1 * V_2 , unsigned int V_324 ,
unsigned int V_360 , bool V_379 )
{
struct V_222 * V_223 ;
struct V_12 * V_13 ;
struct V_380 * V_337 ;
int V_43 ;
V_13 = F_215 ( V_2 ) ;
V_223 = F_119 ( sizeof( * V_337 ) , V_179 ) ;
if ( ! V_223 )
return - V_180 ;
V_337 = (struct V_380 * ) F_122 ( V_223 , sizeof( * V_337 ) ) ;
F_199 ( V_337 , 0 ) ;
F_200 ( V_337 ) = F_123 ( F_201 ( V_381 , V_324 ) ) ;
V_337 -> V_382 = F_144 ( F_223 ( 0 ) | ( V_379 ? F_224 ( 1 ) :
F_224 ( 0 ) ) | F_225 ( V_360 ) ) ;
V_43 = F_165 ( V_13 , V_223 ) ;
return F_220 ( V_43 ) ;
}
unsigned int F_226 ( const unsigned short * V_383 , unsigned short V_51 ,
unsigned int * V_77 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_384 - 1 && V_383 [ V_19 + 1 ] <= V_51 )
++ V_19 ;
if ( V_77 )
* V_77 = V_19 ;
return V_383 [ V_19 ] ;
}
unsigned int F_227 ( const unsigned short * V_383 ,
unsigned short V_385 ,
unsigned short V_386 ,
unsigned short V_387 ,
unsigned int * V_388 )
{
unsigned short V_389 = V_385 + V_386 ;
unsigned short V_390 = V_387 - 1 ;
int V_391 , V_392 ;
for ( V_391 = 0 , V_392 = - 1 ; V_391 < V_384 ; V_391 ++ ) {
unsigned short V_393 = V_383 [ V_391 ] - V_385 ;
if ( ( V_393 & V_390 ) == 0 )
V_392 = V_391 ;
if ( V_391 + 1 < V_384 && V_383 [ V_391 + 1 ] > V_389 )
break;
}
if ( V_391 == V_384 )
V_391 -- ;
if ( V_392 >= 0 &&
V_391 - V_392 <= 1 )
V_391 = V_392 ;
if ( V_388 )
* V_388 = V_391 ;
return V_383 [ V_391 ] ;
}
unsigned int F_228 ( enum V_394 V_217 , unsigned int V_50 )
{
if ( F_213 ( V_217 ) <= V_357 )
return ( ( V_50 & 0x7f ) << 1 ) ;
else
return ( V_50 & 0x7f ) ;
}
unsigned int F_229 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 ) -> V_60 ;
}
unsigned int F_230 ( const struct V_1 * V_2 , int V_395 )
{
struct V_12 * V_13 = F_215 ( V_2 ) ;
T_1 V_396 , V_397 , V_398 , V_399 ;
V_396 = F_65 ( V_13 , V_400 ) ;
V_397 = F_65 ( V_13 , V_401 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
V_398 = F_231 ( V_396 ) ;
V_399 = F_232 ( V_396 ) ;
} else {
V_398 = F_233 ( V_396 ) ;
V_399 = F_234 ( V_397 ) ;
}
return V_395 ? V_398 : V_399 ;
}
unsigned int F_235 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 ) -> V_50 ;
}
unsigned int F_236 ( const struct V_1 * V_2 )
{
return F_87 ( V_2 ) -> V_31 ;
}
void F_237 ( struct V_402 * V_147 , struct V_403 * V_404 ,
struct V_403 * V_405 )
{
struct V_12 * V_13 = F_238 ( V_147 ) ;
F_239 ( & V_13 -> V_406 ) ;
F_240 ( V_13 , V_404 , V_405 ) ;
F_241 ( & V_13 -> V_406 ) ;
}
void F_242 ( struct V_1 * V_2 , unsigned int V_407 ,
const unsigned int * V_408 )
{
struct V_12 * V_13 = F_215 ( V_2 ) ;
F_67 ( V_13 , V_409 , V_407 ) ;
F_67 ( V_13 , V_410 , F_243 ( V_408 [ 0 ] ) |
F_244 ( V_408 [ 1 ] ) | F_245 ( V_408 [ 2 ] ) |
F_246 ( V_408 [ 3 ] ) ) ;
}
int F_247 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_215 ( V_2 ) ;
return F_248 ( V_13 , V_13 -> V_27 ) ;
}
static int F_249 ( struct V_12 * V_13 , T_3 V_104 , T_3 * V_411 , T_3 * V_412 )
{
T_1 V_42 = F_65 ( V_13 , V_413 ) + 24 * V_104 + 8 ;
T_5 V_414 ;
int V_43 ;
F_239 ( & V_13 -> V_415 ) ;
V_43 = F_250 ( V_13 , 0 , V_416 , V_42 ,
sizeof( V_414 ) , ( T_11 * ) & V_414 ,
V_417 ) ;
F_241 ( & V_13 -> V_415 ) ;
if ( ! V_43 ) {
* V_412 = ( F_45 ( V_414 ) >> 25 ) & 0xffff ;
* V_411 = ( F_45 ( V_414 ) >> 9 ) & 0xffff ;
}
return V_43 ;
}
int F_251 ( struct V_1 * V_2 , T_3 V_104 , T_3 V_411 ,
T_3 V_200 )
{
struct V_12 * V_13 = F_215 ( V_2 ) ;
T_3 V_418 , V_419 ;
int V_43 ;
V_43 = F_249 ( V_13 , V_104 , & V_418 , & V_419 ) ;
if ( V_43 )
goto V_102;
if ( V_411 != V_418 ) {
T_3 V_300 ;
T_1 V_252 ;
if ( V_411 >= V_418 )
V_300 = V_411 - V_418 ;
else
V_300 = V_200 - V_418 + V_411 ;
if ( F_110 ( V_13 -> V_209 . V_217 ) )
V_252 = F_252 ( V_300 ) ;
else
V_252 = F_253 ( V_300 ) ;
F_254 () ;
F_67 ( V_13 , F_66 ( V_420 ) ,
F_255 ( V_104 ) | V_252 ) ;
}
V_102:
return V_43 ;
}
int F_256 ( struct V_1 * V_2 , T_1 V_421 , T_11 * V_422 )
{
struct V_12 * V_13 ;
T_1 V_423 , V_424 , V_425 ;
T_1 V_426 , V_427 , V_428 , V_429 , V_200 ;
T_1 V_430 , V_431 , V_432 , V_433 ;
int V_43 ;
V_13 = F_215 ( V_2 ) ;
V_423 = ( ( V_421 >> 8 ) * 32 ) + V_13 -> V_434 . V_421 . V_435 ;
V_200 = F_65 ( V_13 , V_436 ) ;
V_426 = F_257 ( V_200 ) << 20 ;
V_200 = F_65 ( V_13 , V_437 ) ;
V_427 = F_258 ( V_200 ) << 20 ;
V_200 = F_65 ( V_13 , V_438 ) ;
V_428 = F_259 ( V_200 ) << 20 ;
V_430 = V_426 ;
V_431 = V_430 + V_427 ;
V_432 = V_431 + V_428 ;
if ( V_423 < V_430 ) {
V_424 = V_416 ;
V_425 = V_423 ;
} else if ( V_423 < V_431 ) {
V_424 = V_439 ;
V_425 = V_423 - V_430 ;
} else {
if ( V_423 < V_432 ) {
V_424 = V_440 ;
V_425 = V_423 - V_431 ;
} else if ( F_260 ( V_13 -> V_209 . V_217 ) ) {
V_200 = F_65 ( V_13 , V_441 ) ;
V_429 = F_261 ( V_200 ) << 20 ;
V_433 = V_432 + V_429 ;
if ( V_423 < V_433 ) {
V_424 = V_442 ;
V_425 = V_423 - V_432 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_239 ( & V_13 -> V_415 ) ;
V_43 = F_250 ( V_13 , 0 , V_424 , V_425 , 32 , V_422 , V_417 ) ;
F_241 ( & V_13 -> V_415 ) ;
return V_43 ;
V_22:
F_11 ( V_13 -> V_30 , L_34 ,
V_421 , V_423 ) ;
return - V_443 ;
}
T_2 F_262 ( struct V_1 * V_2 )
{
T_1 V_444 , V_445 ;
struct V_12 * V_13 ;
V_13 = F_215 ( V_2 ) ;
V_445 = F_65 ( V_13 , V_446 ) ;
V_444 = F_263 ( F_65 ( V_13 , V_447 ) ) ;
return ( ( T_2 ) V_444 << 32 ) | ( T_2 ) V_445 ;
}
int F_264 ( struct V_1 * V_2 ,
unsigned int V_104 ,
enum V_448 V_449 ,
int V_450 ,
T_2 * V_451 ,
unsigned int * V_452 )
{
return F_265 ( F_215 ( V_2 ) ,
V_104 ,
( V_449 == V_453
? V_454
: V_455 ) ,
V_450 ,
V_451 ,
V_452 ) ;
}
static void F_266 ( struct V_456 * V_457 )
{
const struct V_458 * V_459 ;
const struct V_1 * V_189 = V_457 -> V_2 ;
if ( V_189 -> V_460 & V_461 )
V_189 = F_267 ( V_189 ) ;
V_459 = V_189 -> V_2 . V_459 ;
if ( V_459 && V_459 -> V_462 == & V_463 . V_462 )
F_268 ( F_269 ( V_459 ) , V_457 ) ;
}
static int F_270 ( struct V_464 * V_465 , unsigned long V_466 ,
void * V_117 )
{
switch ( V_466 ) {
case V_467 :
F_266 ( V_117 ) ;
break;
case V_468 :
default:
break;
}
return 0 ;
}
static void F_271 ( struct V_12 * V_13 , int V_469 )
{
T_1 V_396 , V_397 , V_398 , V_399 ;
do {
V_396 = F_65 ( V_13 , V_400 ) ;
V_397 = F_65 ( V_13 , V_401 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
V_398 = F_231 ( V_396 ) ;
V_399 = F_232 ( V_396 ) ;
} else {
V_398 = F_233 ( V_396 ) ;
V_399 = F_234 ( V_397 ) ;
}
if ( V_398 == 0 && V_399 == 0 )
break;
F_272 ( V_470 ) ;
F_273 ( F_274 ( V_469 ) ) ;
} while ( 1 );
}
static void F_275 ( struct V_106 * V_25 )
{
unsigned long V_53 ;
F_276 ( & V_25 -> V_471 , V_53 ) ;
V_25 -> V_472 = 1 ;
F_277 ( & V_25 -> V_471 , V_53 ) ;
}
static void F_278 ( struct V_12 * V_13 , struct V_106 * V_25 )
{
F_279 ( & V_25 -> V_471 ) ;
if ( V_25 -> V_473 ) {
F_254 () ;
F_67 ( V_13 , F_66 ( V_420 ) ,
F_255 ( V_25 -> V_26 ) | F_252 ( V_25 -> V_473 ) ) ;
V_25 -> V_473 = 0 ;
}
V_25 -> V_472 = 0 ;
F_280 ( & V_25 -> V_471 ) ;
}
static void F_281 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_275 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_71 (&adap->sge, i)
F_275 ( & V_13 -> V_16 . V_110 [ V_19 ] . V_25 ) ;
F_70 (adap, i)
F_275 ( & V_13 -> V_16 . V_216 [ V_19 ] . V_25 ) ;
}
static void F_282 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_278 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_71 (&adap->sge, i)
F_278 ( V_13 , & V_13 -> V_16 . V_110 [ V_19 ] . V_25 ) ;
F_70 (adap, i)
F_278 ( V_13 , & V_13 -> V_16 . V_216 [ V_19 ] . V_25 ) ;
}
static void F_283 ( struct V_12 * V_13 , enum V_474 V_118 )
{
if ( V_13 -> V_139 [ V_475 ] )
V_137 [ V_475 ] . F_284 ( V_13 -> V_139 [ V_475 ] ,
V_118 ) ;
}
static void F_285 ( struct V_347 * V_348 )
{
struct V_12 * V_13 ;
V_13 = F_50 ( V_348 , struct V_12 , V_476 ) ;
F_271 ( V_13 , V_477 ) ;
F_282 ( V_13 ) ;
F_283 ( V_13 , V_478 ) ;
if ( F_213 ( V_13 -> V_209 . V_217 ) <= V_357 )
F_286 ( V_13 , V_479 ,
V_480 | V_481 ,
V_480 | V_481 ) ;
else
F_286 ( V_13 , V_479 ,
V_481 , V_481 ) ;
}
static void F_287 ( struct V_12 * V_13 , struct V_106 * V_25 )
{
T_3 V_418 , V_419 ;
int V_43 ;
F_279 ( & V_25 -> V_471 ) ;
V_43 = F_249 ( V_13 , ( T_3 ) V_25 -> V_26 , & V_418 , & V_419 ) ;
if ( V_43 )
goto V_102;
if ( V_25 -> V_482 != V_418 ) {
T_3 V_300 ;
T_1 V_252 ;
if ( V_25 -> V_482 >= V_418 )
V_300 = V_25 -> V_482 - V_418 ;
else
V_300 = V_25 -> V_200 - V_418 + V_25 -> V_482 ;
if ( F_110 ( V_13 -> V_209 . V_217 ) )
V_252 = F_252 ( V_300 ) ;
else
V_252 = F_253 ( V_300 ) ;
F_254 () ;
F_67 ( V_13 , F_66 ( V_420 ) ,
F_255 ( V_25 -> V_26 ) | V_252 ) ;
}
V_102:
V_25 -> V_472 = 0 ;
V_25 -> V_473 = 0 ;
F_280 ( & V_25 -> V_471 ) ;
if ( V_43 )
F_288 ( V_13 , L_35 ) ;
}
static void F_289 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_287 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_71 (&adap->sge, i)
F_287 ( V_13 , & V_13 -> V_16 . V_110 [ V_19 ] . V_25 ) ;
F_70 (adap, i)
F_287 ( V_13 , & V_13 -> V_16 . V_216 [ V_19 ] . V_25 ) ;
}
static void F_290 ( struct V_347 * V_348 )
{
struct V_12 * V_13 ;
V_13 = F_50 ( V_348 , struct V_12 , V_483 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
F_271 ( V_13 , V_477 ) ;
F_283 ( V_13 , V_484 ) ;
F_271 ( V_13 , V_477 ) ;
F_289 ( V_13 ) ;
F_271 ( V_13 , V_477 ) ;
F_282 ( V_13 ) ;
F_283 ( V_13 , V_478 ) ;
} else if ( F_260 ( V_13 -> V_209 . V_217 ) ) {
T_1 V_485 = F_65 ( V_13 , 0x010ac ) ;
T_3 V_104 = ( V_485 >> 15 ) & 0x1ffff ;
T_3 V_486 = V_485 & 0x1fff ;
T_2 V_487 ;
unsigned int V_488 ;
int V_43 ;
V_43 = F_265 ( V_13 , V_104 , V_454 ,
0 , & V_487 , & V_488 ) ;
if ( V_43 )
F_11 ( V_13 -> V_30 , L_36
L_37 , V_104 , V_486 ) ;
else
F_291 ( F_253 ( V_486 ) | F_255 ( V_488 ) ,
V_13 -> V_489 + V_487 + V_490 ) ;
F_286 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_213 ( V_13 -> V_209 . V_217 ) <= V_357 )
F_286 ( V_13 , V_491 , V_492 , 0 ) ;
}
void F_292 ( struct V_12 * V_13 )
{
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
F_281 ( V_13 ) ;
F_283 ( V_13 , V_493 ) ;
F_286 ( V_13 , V_479 ,
V_480 | V_481 , 0 ) ;
F_203 ( V_13 -> V_345 , & V_13 -> V_476 ) ;
}
}
void F_293 ( struct V_12 * V_13 )
{
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
F_281 ( V_13 ) ;
F_283 ( V_13 , V_493 ) ;
}
F_203 ( V_13 -> V_345 , & V_13 -> V_483 ) ;
}
static void F_294 ( struct V_12 * V_13 , unsigned int V_138 )
{
void * V_494 ;
struct V_495 V_496 ;
unsigned short V_19 ;
V_496 . V_147 = V_13 -> V_147 ;
V_496 . V_28 = V_13 -> V_28 ;
V_496 . V_74 = V_13 -> V_74 ;
V_496 . V_79 = & V_13 -> V_79 ;
V_496 . V_497 = V_13 -> V_34 ;
V_496 . V_498 = & V_13 -> V_434 ;
V_496 . V_383 = V_13 -> V_209 . V_383 ;
if ( V_138 == V_475 ) {
V_496 . V_499 = V_13 -> V_16 . V_213 ;
V_496 . V_500 = V_13 -> V_16 . V_215 ;
V_496 . V_501 = V_13 -> V_16 . V_212 ;
V_496 . V_502 = V_13 -> V_16 . V_214 ;
} else if ( V_138 == V_503 ) {
V_496 . V_499 = V_13 -> V_16 . V_211 ;
V_496 . V_501 = V_13 -> V_16 . V_208 ;
}
V_496 . V_504 = V_13 -> V_16 . V_208 ;
V_496 . V_505 = V_13 -> V_209 . V_210 ;
V_496 . V_210 = V_13 -> V_209 . V_210 ;
V_496 . V_506 = V_13 -> V_209 . V_507 ;
V_496 . V_508 = V_13 -> V_209 . V_217 ;
V_496 . V_509 = F_295 ( F_65 ( V_13 , V_510 ) ) ;
V_496 . V_511 = 1000000000 / V_13 -> V_209 . V_512 . V_513 ;
V_496 . V_514 = 1 << V_13 -> V_209 . V_16 . V_515 ;
V_496 . V_516 = 1 << V_13 -> V_209 . V_16 . V_517 ;
V_496 . V_518 = V_13 -> V_209 . V_519 . V_520 ;
for ( V_19 = 0 ; V_19 < V_521 ; V_19 ++ )
V_496 . V_522 [ V_19 ] = V_19 ;
V_496 . V_523 = V_13 -> V_524 + F_66 ( V_194 ) ;
V_496 . V_525 = V_13 -> V_524 + F_66 ( V_420 ) ;
V_496 . V_526 = V_13 -> V_209 . V_526 ;
V_496 . V_527 = V_527 ;
V_496 . V_528 = V_13 -> V_16 . V_529 ;
V_496 . V_530 = V_13 -> V_16 . V_531 ;
V_496 . V_532 = V_13 -> V_16 . V_533 ;
V_496 . V_534 = V_13 -> V_53 & V_535 ;
V_496 . V_536 = V_13 -> V_209 . V_536 ;
V_496 . V_537 = V_13 -> V_209 . V_537 ;
V_496 . V_538 = V_13 -> V_209 . V_538 ;
V_496 . V_539 = F_296 ( V_13 -> V_30 ) ;
V_494 = V_137 [ V_138 ] . F_297 ( & V_496 ) ;
if ( F_298 ( V_494 ) ) {
F_299 ( V_13 -> V_30 ,
L_38 ,
V_540 [ V_138 ] , F_300 ( V_494 ) ) ;
return;
}
V_13 -> V_139 [ V_138 ] = V_494 ;
if ( ! V_541 ) {
F_301 ( & V_542 ) ;
V_541 = true ;
}
if ( V_13 -> V_53 & V_193 )
V_137 [ V_138 ] . F_302 ( V_494 , V_543 ) ;
}
static void F_303 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_239 ( & V_544 ) ;
F_304 ( & V_13 -> V_545 , & V_546 ) ;
F_241 ( & V_544 ) ;
F_305 ( & V_547 ) ;
F_306 ( & V_13 -> V_548 , & V_549 ) ;
for ( V_19 = 0 ; V_19 < V_550 ; V_19 ++ )
if ( V_137 [ V_19 ] . F_297 )
F_294 ( V_13 , V_19 ) ;
F_307 ( & V_547 ) ;
}
static void F_308 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_305 ( & V_547 ) ;
F_309 ( & V_13 -> V_548 ) ;
for ( V_19 = 0 ; V_19 < V_550 ; V_19 ++ )
if ( V_13 -> V_139 [ V_19 ] ) {
V_137 [ V_19 ] . F_302 ( V_13 -> V_139 [ V_19 ] ,
V_551 ) ;
V_13 -> V_139 [ V_19 ] = NULL ;
}
if ( V_541 && F_310 ( & V_549 ) ) {
F_311 ( & V_542 ) ;
V_541 = false ;
}
F_307 ( & V_547 ) ;
F_239 ( & V_544 ) ;
F_312 ( & V_13 -> V_545 ) ;
F_241 ( & V_544 ) ;
}
static void F_313 ( struct V_12 * V_13 , enum V_552 V_553 )
{
unsigned int V_19 ;
F_305 ( & V_547 ) ;
for ( V_19 = 0 ; V_19 < V_550 ; V_19 ++ )
if ( V_13 -> V_139 [ V_19 ] )
V_137 [ V_19 ] . F_302 ( V_13 -> V_139 [ V_19 ] , V_553 ) ;
F_307 ( & V_547 ) ;
}
int F_314 ( enum V_554 type , const struct V_555 * V_6 )
{
int V_43 = 0 ;
struct V_12 * V_13 ;
if ( type >= V_550 )
return - V_443 ;
F_305 ( & V_547 ) ;
if ( V_137 [ type ] . F_297 ) {
V_43 = - V_556 ;
goto V_102;
}
V_137 [ type ] = * V_6 ;
F_315 (adap, &adapter_list, list_node)
F_294 ( V_13 , type ) ;
V_102: F_307 ( & V_547 ) ;
return V_43 ;
}
int F_316 ( enum V_554 type )
{
struct V_12 * V_13 ;
if ( type >= V_550 )
return - V_443 ;
F_305 ( & V_547 ) ;
F_315 (adap, &adapter_list, list_node)
V_13 -> V_139 [ type ] = NULL ;
V_137 [ type ] . F_297 = NULL ;
F_307 ( & V_547 ) ;
return 0 ;
}
static int F_317 ( struct V_464 * V_557 ,
unsigned long V_466 , void * V_117 )
{
struct V_558 * V_559 = V_117 ;
struct V_1 * V_560 = V_559 -> V_561 -> V_2 ;
const struct V_458 * V_459 = NULL ;
#if F_318 ( V_562 )
struct V_12 * V_13 ;
#endif
if ( V_560 -> V_460 & V_461 )
V_560 = F_267 ( V_560 ) ;
#if F_318 ( V_562 )
if ( V_560 -> V_53 & V_563 ) {
F_315 (adap, &adapter_list, list_node) {
switch ( V_466 ) {
case V_564 :
F_319 ( V_13 -> V_34 [ 0 ] ,
( const T_1 * ) V_559 , 1 ) ;
break;
case V_565 :
F_320 ( V_13 -> V_34 [ 0 ] ,
( const T_1 * ) V_559 , 1 ) ;
break;
default:
break;
}
}
return V_566 ;
}
#endif
if ( V_560 )
V_459 = V_560 -> V_2 . V_459 ;
if ( V_459 && V_459 -> V_462 == & V_463 . V_462 ) {
switch ( V_466 ) {
case V_564 :
F_319 ( V_560 , ( const T_1 * ) V_559 , 1 ) ;
break;
case V_565 :
F_320 ( V_560 , ( const T_1 * ) V_559 , 1 ) ;
break;
default:
break;
}
}
return V_566 ;
}
static void F_321 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_43 ;
F_322 () ;
for ( V_19 = 0 ; V_19 < V_567 ; V_19 ++ ) {
V_2 = V_13 -> V_34 [ V_19 ] ;
V_43 = 0 ;
if ( V_2 )
V_43 = F_323 ( V_2 ) ;
if ( V_43 < 0 )
break;
}
F_324 () ;
}
static int F_325 ( struct V_12 * V_13 )
{
int V_22 ;
V_22 = F_101 ( V_13 ) ;
if ( V_22 )
goto V_102;
V_22 = F_84 ( V_13 ) ;
if ( V_22 )
goto V_568;
if ( V_13 -> V_53 & V_146 ) {
F_69 ( V_13 ) ;
V_22 = F_75 ( V_13 -> V_159 [ 0 ] . V_167 , F_64 , 0 ,
V_13 -> V_159 [ 0 ] . V_160 , V_13 ) ;
if ( V_22 )
goto V_569;
V_22 = F_74 ( V_13 ) ;
if ( V_22 ) {
F_77 ( V_13 -> V_159 [ 0 ] . V_167 , V_13 ) ;
goto V_569;
}
} else {
V_22 = F_75 ( V_13 -> V_147 -> V_149 , F_326 ( V_13 ) ,
( V_13 -> V_53 & V_148 ) ? 0 : V_570 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_569;
}
F_94 ( V_13 ) ;
F_327 ( V_13 ) ;
F_328 ( V_13 ) ;
V_13 -> V_53 |= V_193 ;
F_313 ( V_13 , V_543 ) ;
#if F_318 ( V_571 )
F_321 ( V_13 ) ;
#endif
V_102:
return V_22 ;
V_569:
F_11 ( V_13 -> V_30 , L_39 , V_22 ) ;
V_568:
F_103 ( V_13 ) ;
goto V_102;
}
static void F_329 ( struct V_12 * V_12 )
{
F_330 ( & V_12 -> V_346 ) ;
F_330 ( & V_12 -> V_476 ) ;
F_330 ( & V_12 -> V_483 ) ;
V_12 -> V_344 = false ;
V_12 -> V_342 = NULL ;
F_331 ( V_12 ) ;
F_103 ( V_12 ) ;
V_12 -> V_53 &= ~ V_193 ;
}
static int F_332 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_17 ( V_2 ) ;
if ( ! ( V_12 -> V_53 & V_193 ) ) {
V_22 = F_325 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_29 ( V_2 ) ;
if ( ! V_22 )
F_333 ( V_2 ) ;
return V_22 ;
}
static int F_334 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_335 ( V_2 ) ;
F_17 ( V_2 ) ;
return F_336 ( V_12 , V_12 -> V_28 , V_11 -> V_50 , false , false ) ;
}
static int F_337 ( struct V_72 * V_73 )
{
if ( V_73 -> V_572 )
return - V_573 ;
if ( V_73 -> V_90 )
return - V_556 ;
return 0 ;
}
static int F_338 ( struct V_12 * V_12 , unsigned int V_221 )
{
struct V_72 * V_73 ;
int V_43 ;
if ( V_221 >= V_12 -> V_79 . V_81 + V_12 -> V_79 . V_82 )
return - V_443 ;
V_73 = & V_12 -> V_79 . V_84 [ V_221 ] ;
V_43 = F_337 ( V_73 ) ;
if ( V_43 )
return V_43 ;
if ( V_73 -> V_91 )
return F_163 ( V_12 , V_221 ) ;
return 0 ;
}
int F_339 ( const struct V_1 * V_2 , unsigned int V_324 ,
T_11 V_358 , T_12 V_359 , T_12 V_230 ,
unsigned int V_360 , unsigned char V_34 , unsigned char V_254 )
{
int V_43 ;
struct V_72 * V_73 ;
struct V_12 * V_13 ;
int V_19 ;
T_4 * V_252 ;
V_13 = F_215 ( V_2 ) ;
V_324 -= V_13 -> V_79 . V_332 ;
V_324 += V_13 -> V_79 . V_81 ;
V_73 = & V_13 -> V_79 . V_84 [ V_324 ] ;
V_43 = F_337 ( V_73 ) ;
if ( V_43 )
return V_43 ;
if ( V_73 -> V_91 )
F_40 ( V_13 , V_73 ) ;
memset ( & V_73 -> V_227 , 0 , sizeof( struct V_574 ) ) ;
V_73 -> V_227 . V_252 . V_281 = F_340 ( V_359 ) ;
V_73 -> V_227 . V_254 . V_281 = ~ 0 ;
V_252 = ( T_4 * ) & V_358 ;
if ( ( V_252 [ 0 ] | V_252 [ 1 ] | V_252 [ 2 ] | V_252 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_73 -> V_227 . V_252 . V_276 [ V_19 ] = V_252 [ V_19 ] ;
V_73 -> V_227 . V_254 . V_276 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_209 . V_519 . V_520 & V_575 ) {
V_73 -> V_227 . V_252 . V_264 = V_34 ;
V_73 -> V_227 . V_254 . V_264 = V_254 ;
}
}
if ( V_13 -> V_209 . V_519 . V_520 & V_576 ) {
V_73 -> V_227 . V_252 . V_267 = V_577 ;
V_73 -> V_227 . V_254 . V_267 = ~ 0 ;
}
V_73 -> V_227 . V_241 = 1 ;
V_73 -> V_227 . V_237 = V_360 ;
V_73 -> V_572 = 1 ;
V_73 -> V_227 . V_239 = 1 ;
V_43 = F_118 ( V_13 , V_324 ) ;
if ( V_43 ) {
F_40 ( V_13 , V_73 ) ;
return V_43 ;
}
return 0 ;
}
int F_341 ( const struct V_1 * V_2 , unsigned int V_324 ,
unsigned int V_360 , bool V_379 )
{
int V_43 ;
struct V_72 * V_73 ;
struct V_12 * V_13 ;
V_13 = F_215 ( V_2 ) ;
V_324 -= V_13 -> V_79 . V_332 ;
V_324 += V_13 -> V_79 . V_81 ;
V_73 = & V_13 -> V_79 . V_84 [ V_324 ] ;
V_73 -> V_572 = 0 ;
V_43 = F_338 ( V_13 , V_324 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
static struct V_578 * F_342 ( struct V_1 * V_2 ,
struct V_578 * V_579 )
{
struct V_580 V_140 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_239 ( & V_12 -> V_406 ) ;
if ( ! F_343 ( V_2 ) ) {
F_241 ( & V_12 -> V_406 ) ;
return V_579 ;
}
F_344 ( V_12 , V_6 -> V_60 , & V_140 ,
& V_6 -> V_581 ) ;
F_241 ( & V_12 -> V_406 ) ;
V_579 -> V_582 = V_140 . V_583 ;
V_579 -> V_584 = V_140 . V_585 ;
V_579 -> V_586 = V_140 . V_587 ;
V_579 -> V_588 = V_140 . V_589 ;
V_579 -> V_590 = V_140 . V_591 ;
V_579 -> V_592 = V_140 . V_593 + V_140 . V_594 +
V_140 . V_595 ;
V_579 -> V_596 = 0 ;
V_579 -> V_597 = V_140 . V_598 ;
V_579 -> V_599 = V_140 . V_600 ;
V_579 -> V_601 = V_140 . V_602 + V_140 . V_603 +
V_140 . V_604 + V_140 . V_605 +
V_140 . V_606 + V_140 . V_607 +
V_140 . V_608 + V_140 . V_609 ;
V_579 -> V_610 = 0 ;
V_579 -> V_611 = 0 ;
V_579 -> V_612 = 0 ;
V_579 -> V_613 = 0 ;
V_579 -> V_614 = 0 ;
V_579 -> V_615 = 0 ;
V_579 -> V_616 = V_140 . V_617 ;
V_579 -> V_618 = V_140 . V_600 + V_140 . V_598 +
V_579 -> V_592 + V_140 . V_619 + V_579 -> V_601 ;
return V_579 ;
}
static int F_345 ( struct V_1 * V_2 , struct V_620 * V_337 , int V_118 )
{
unsigned int V_27 ;
int V_43 = 0 , V_621 , V_622 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_623 * V_117 = (struct V_623 * ) & V_337 -> V_624 ;
switch ( V_118 ) {
case V_625 :
if ( V_11 -> V_626 < 0 )
return - V_627 ;
V_117 -> V_628 = V_11 -> V_626 ;
break;
case V_629 :
case V_630 :
if ( F_346 ( V_117 -> V_628 ) ) {
V_621 = F_347 ( V_117 -> V_628 ) ;
V_622 = F_348 ( V_117 -> V_628 ) ;
} else if ( V_117 -> V_628 < 32 ) {
V_621 = V_117 -> V_628 ;
V_622 = 0 ;
V_117 -> V_631 &= 0x1f ;
} else
return - V_443 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_118 == V_629 )
V_43 = F_349 ( V_11 -> V_12 , V_27 , V_621 , V_622 ,
V_117 -> V_631 , & V_117 -> V_632 ) ;
else
V_43 = F_350 ( V_11 -> V_12 , V_27 , V_621 , V_622 ,
V_117 -> V_631 , V_117 -> V_633 ) ;
break;
case V_634 :
return F_351 ( V_337 -> V_624 , & V_11 -> V_635 ,
sizeof( V_11 -> V_635 ) ) ?
- V_636 : 0 ;
case V_637 :
if ( F_352 ( & V_11 -> V_635 , V_337 -> V_624 ,
sizeof( V_11 -> V_635 ) ) )
return - V_636 ;
switch ( V_11 -> V_635 . V_638 ) {
case V_639 :
V_11 -> V_640 = false ;
break;
case V_641 :
V_11 -> V_640 = true ;
break;
default:
V_11 -> V_635 . V_638 = V_639 ;
return - V_642 ;
}
return F_351 ( V_337 -> V_624 , & V_11 -> V_635 ,
sizeof( V_11 -> V_635 ) ) ?
- V_636 : 0 ;
default:
return - V_627 ;
}
return V_43 ;
}
static void F_353 ( struct V_1 * V_2 )
{
F_27 ( V_2 , - 1 , false ) ;
}
static int F_354 ( struct V_1 * V_2 , int V_643 )
{
int V_43 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_643 < 81 || V_643 > V_644 )
return - V_443 ;
V_43 = F_28 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_50 , V_643 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_43 )
V_2 -> V_51 = V_643 ;
return V_43 ;
}
static int F_355 ( struct V_1 * V_2 , void * V_6 )
{
int V_43 ;
struct V_645 * V_42 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_356 ( V_42 -> V_646 ) )
return - V_647 ;
V_43 = F_30 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_50 ,
V_11 -> V_58 , V_42 -> V_646 , true , true ) ;
if ( V_43 < 0 )
return V_43 ;
memcpy ( V_2 -> V_59 , V_42 -> V_646 , V_2 -> V_648 ) ;
V_11 -> V_58 = V_43 ;
return 0 ;
}
static void F_357 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_53 & V_146 ) {
int V_19 ;
struct V_177 * V_649 = & V_13 -> V_16 . V_170 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_649 ++ )
V_168 ( 0 , & V_649 -> V_136 ) ;
} else
F_326 ( V_13 ) ( 0 , V_13 ) ;
}
void F_358 ( struct V_12 * V_13 )
{
F_286 ( V_13 , V_650 , V_651 , 0 ) ;
F_93 ( V_13 ) ;
F_359 ( V_13 -> V_30 , L_40 ) ;
}
static void F_360 ( struct V_12 * V_13 )
{
T_1 V_652 = F_361 ( V_13 ) ;
F_362 ( V_13 , V_652 , V_653 ) ;
}
static void F_363 ( struct V_12 * V_13 )
{
if ( V_13 -> V_434 . V_654 . V_200 ) {
T_1 V_435 ;
unsigned int V_655 ;
V_435 = F_364 ( V_13 , V_656 ) ;
V_435 &= V_657 ;
V_435 += F_365 ( V_13 -> V_147 , & V_13 -> V_434 ) ;
V_655 = F_366 ( V_13 -> V_434 . V_654 . V_200 ) >> 10 ;
F_67 ( V_13 ,
F_367 ( V_658 , 3 ) ,
V_435 | F_368 ( 1 ) | F_369 ( F_370 ( V_655 ) ) ) ;
F_67 ( V_13 ,
F_367 ( V_659 , 3 ) ,
V_13 -> V_434 . V_654 . V_435 ) ;
F_65 ( V_13 ,
F_367 ( V_659 , 3 ) ) ;
}
}
static int F_371 ( struct V_12 * V_13 , struct V_660 * V_661 )
{
T_1 V_150 ;
int V_43 ;
memset ( V_661 , 0 , sizeof( * V_661 ) ) ;
V_661 -> V_662 = F_123 ( F_372 ( V_663 ) |
V_664 | V_665 ) ;
V_661 -> V_666 = F_123 ( F_373 ( * V_661 ) ) ;
V_43 = F_374 ( V_13 , V_13 -> V_27 , V_661 , sizeof( * V_661 ) , V_661 ) ;
if ( V_43 < 0 )
return V_43 ;
V_661 -> V_662 = F_123 ( F_372 ( V_663 ) |
V_664 | V_667 ) ;
V_43 = F_374 ( V_13 , V_13 -> V_27 , V_661 , sizeof( * V_661 ) , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_375 ( V_13 , V_13 -> V_28 ,
V_668 ,
V_669 |
V_670 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_376 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_202 , 64 ,
V_671 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_672 ,
V_672 ) ;
if ( V_43 < 0 )
return V_43 ;
F_377 ( V_13 ) ;
F_67 ( V_13 , V_673 , 0x64f8849 ) ;
F_67 ( V_13 , V_674 , F_243 ( V_675 - 12 ) ) ;
F_67 ( V_13 , V_676 , V_677 ) ;
V_150 = F_65 ( V_13 , V_678 ) ;
F_67 ( V_13 , V_678 , V_150 & ~ V_679 ) ;
V_13 -> V_209 . V_519 . V_680 = 0xE4 ;
F_67 ( V_13 , V_681 ,
F_378 ( V_13 -> V_209 . V_519 . V_680 ) ) ;
V_150 = 0x84218421 ;
F_379 ( V_13 , V_676 , V_678 ,
& V_150 , 1 , V_682 ) ;
F_379 ( V_13 , V_676 , V_678 ,
& V_150 , 1 , V_683 ) ;
F_379 ( V_13 , V_676 , V_678 ,
& V_150 , 1 , V_684 ) ;
#define F_380 16
if ( F_381 ( V_13 ) ) {
F_67 ( V_13 , V_685 ,
F_382 ( F_380 ) |
F_383 ( F_380 ) |
F_384 ( F_380 ) |
F_385 ( F_380 ) ) ;
F_67 ( V_13 , V_686 ,
F_382 ( F_380 ) |
F_383 ( F_380 ) |
F_384 ( F_380 ) |
F_385 ( F_380 ) ) ;
}
return F_386 ( V_13 , V_13 -> V_28 ) ;
}
static int F_387 ( struct V_12 * V_12 )
{
F_388 ( V_12 , V_687 , V_688 ) ;
if ( V_689 != 2 && V_689 != 0 ) {
F_11 ( & V_12 -> V_147 -> V_2 ,
L_41 ,
V_689 ) ;
V_689 = 2 ;
}
F_286 ( V_12 , V_650 ,
F_389 ( V_690 ) ,
F_389 ( V_689 ) ) ;
F_390 ( V_12 , V_677 ,
V_679 , 0 ) ;
return 0 ;
}
static int F_391 ( const T_4 * V_691 ,
T_8 V_692 )
{
int V_423 ;
#define F_392 ( T_13 ) (((__p)[0] << 8) | (__p)[1])
#define F_393 ( T_13 ) ((__p)[0] | ((__p)[1] << 8))
#define F_394 ( T_13 ) (le16(__p) | ((__p)[2] << 16))
V_423 = F_394 ( V_691 + 0x8 ) << 12 ;
V_423 = F_394 ( V_691 + V_423 + 0xa ) ;
return F_392 ( V_691 + V_423 + 0x27e ) ;
#undef F_392
#undef F_393
#undef F_394
}
static struct V_693 * F_395 ( int V_694 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_695 ) ; V_19 ++ ) {
if ( V_695 [ V_19 ] . V_696 == V_694 )
return & V_695 [ V_19 ] ;
}
return NULL ;
}
static int F_396 ( struct V_12 * V_13 )
{
const struct V_697 * V_698 ;
int V_43 ;
struct V_693 * V_699 ;
V_699 = F_395 ( V_13 -> V_147 -> V_458 ) ;
if ( ! V_699 ) {
F_299 ( V_13 -> V_30 ,
L_42 ) ;
return - V_627 ;
}
V_43 = F_397 ( & V_698 , V_699 -> V_700 ,
V_13 -> V_30 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_43
L_44 ,
V_699 -> V_700 , - V_43 ) ;
if ( V_699 -> V_701 ) {
int V_702 = 0 ;
F_398 ( V_13 , & V_702 ) ;
F_299 ( V_13 -> V_30 , L_45
L_46 , V_702 ) ;
V_43 = 0 ;
}
return V_43 ;
}
V_43 = F_399 ( V_13 , V_653 , & V_13 -> V_415 ,
V_699 -> V_703 ,
( T_4 * ) V_698 -> V_117 , V_698 -> V_200 ) ;
if ( V_43 < 0 )
F_11 ( V_13 -> V_30 , L_47 ,
- V_43 ) ;
else if ( V_43 > 0 ) {
int V_704 = 0 ;
if ( V_699 -> V_703 )
V_704 = V_699 -> V_703 ( V_698 -> V_117 ,
V_698 -> V_200 ) ;
F_400 ( V_13 -> V_30 , L_48
L_49 ,
V_699 -> V_700 , V_704 ) ;
}
F_401 ( V_698 ) ;
return V_43 ;
}
static int F_402 ( struct V_12 * V_12 , int V_705 )
{
struct V_660 V_706 ;
const struct V_697 * V_707 ;
unsigned long V_708 = 0 , V_709 = 0 ;
T_1 V_710 , V_711 , V_712 ;
int V_43 ;
int V_713 = 0 ;
char * V_714 , V_715 [ 256 ] ;
char * V_716 = NULL ;
if ( V_705 ) {
V_43 = F_403 ( V_12 , V_12 -> V_27 ,
V_717 | V_718 ) ;
if ( V_43 < 0 )
goto V_719;
}
if ( F_404 ( V_12 -> V_147 -> V_458 ) ) {
V_43 = F_396 ( V_12 ) ;
if ( V_43 < 0 )
goto V_719;
}
switch ( F_213 ( V_12 -> V_209 . V_217 ) ) {
case V_720 :
V_714 = V_721 ;
break;
case V_357 :
V_714 = V_722 ;
break;
case V_723 :
V_714 = V_724 ;
break;
default:
F_11 ( V_12 -> V_30 , L_50 ,
V_12 -> V_147 -> V_458 ) ;
V_43 = - V_443 ;
goto V_719;
}
V_43 = F_405 ( & V_707 , V_714 , V_12 -> V_30 ) ;
if ( V_43 < 0 ) {
V_716 = L_51 ;
V_708 = V_725 ;
V_709 = F_406 ( V_12 ) ;
} else {
T_1 V_209 [ 7 ] , V_252 [ 7 ] ;
sprintf ( V_715 ,
L_52 , V_714 ) ;
V_716 = V_715 ;
if ( V_707 -> V_200 >= V_726 )
V_43 = - V_180 ;
else {
V_209 [ 0 ] = ( F_7 ( V_727 ) |
F_8 ( V_728 ) ) ;
V_43 = F_407 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_209 , V_252 ) ;
if ( V_43 == 0 ) {
T_8 V_729 = V_707 -> V_200 & 0x3 ;
T_8 V_200 = V_707 -> V_200 & ~ 0x3 ;
T_11 * V_117 = ( T_11 * ) V_707 -> V_117 ;
V_708 = F_408 ( V_252 [ 0 ] ) ;
V_709 = F_409 ( V_252 [ 0 ] ) << 16 ;
F_239 ( & V_12 -> V_415 ) ;
V_43 = F_250 ( V_12 , 0 , V_708 , V_709 ,
V_200 , V_117 , V_730 ) ;
if ( V_43 == 0 && V_729 != 0 ) {
union {
T_11 V_731 ;
char V_732 [ 4 ] ;
} V_733 ;
int V_19 ;
V_733 . V_731 = V_117 [ V_200 >> 2 ] ;
for ( V_19 = V_729 ; V_19 < 4 ; V_19 ++ )
V_733 . V_732 [ V_19 ] = 0 ;
V_43 = F_250 ( V_12 , 0 , V_708 ,
V_709 + V_200 ,
4 , & V_733 . V_731 ,
V_730 ) ;
}
F_241 ( & V_12 -> V_415 ) ;
}
}
F_401 ( V_707 ) ;
if ( V_43 )
goto V_719;
}
memset ( & V_706 , 0 , sizeof( V_706 ) ) ;
V_706 . V_662 =
F_123 ( F_372 ( V_663 ) |
V_664 |
V_665 ) ;
V_706 . V_666 =
F_123 ( V_734 |
F_410 ( V_708 ) |
F_411 ( V_709 >> 16 ) |
F_373 ( V_706 ) ) ;
V_43 = F_374 ( V_12 , V_12 -> V_27 , & V_706 , sizeof( V_706 ) ,
& V_706 ) ;
if ( V_43 == - V_735 ) {
memset ( & V_706 , 0 , sizeof( V_706 ) ) ;
V_706 . V_662 =
F_123 ( F_372 ( V_663 ) |
V_664 |
V_665 ) ;
V_706 . V_666 = F_123 ( F_373 ( V_706 ) ) ;
V_43 = F_374 ( V_12 , V_12 -> V_27 , & V_706 ,
sizeof( V_706 ) , & V_706 ) ;
V_716 = L_53 ;
}
V_713 = 1 ;
if ( V_43 < 0 )
goto V_719;
V_710 = F_38 ( V_706 . V_710 ) ;
V_711 = F_38 ( V_706 . V_711 ) ;
V_712 = F_38 ( V_706 . V_712 ) ;
if ( V_711 != V_712 )
F_299 ( V_12 -> V_30 , L_54\
L_55 ,
V_711 , V_712 ) ;
V_706 . V_662 =
F_123 ( F_372 ( V_663 ) |
V_664 |
V_667 ) ;
V_706 . V_666 = F_123 ( F_373 ( V_706 ) ) ;
V_43 = F_374 ( V_12 , V_12 -> V_27 , & V_706 , sizeof( V_706 ) ,
NULL ) ;
if ( V_43 < 0 )
goto V_719;
V_43 = F_387 ( V_12 ) ;
if ( V_43 < 0 )
goto V_719;
V_43 = F_412 ( V_12 , V_12 -> V_27 ) ;
if ( V_43 < 0 )
goto V_719;
F_400 ( V_12 -> V_30 , L_56\
L_57 ,
V_716 , V_710 , V_712 ) ;
return 0 ;
V_719:
if ( V_713 && V_43 != - V_735 )
F_299 ( V_12 -> V_30 , L_58 ,
V_716 , - V_43 ) ;
return V_43 ;
}
static struct V_736 * F_413 ( int V_217 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_737 ) ; V_19 ++ ) {
if ( V_737 [ V_19 ] . V_217 == V_217 )
return & V_737 [ V_19 ] ;
}
return NULL ;
}
static int F_414 ( struct V_12 * V_13 )
{
int V_43 ;
T_1 V_150 , V_738 ;
enum V_739 V_64 ;
T_1 V_209 [ 7 ] , V_252 [ 7 ] ;
struct V_660 V_706 ;
int V_705 = 1 ;
V_43 = F_415 ( V_13 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_27 , V_740 , & V_64 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_59 ,
V_43 ) ;
return V_43 ;
}
if ( V_43 == V_13 -> V_27 )
V_13 -> V_53 |= V_154 ;
F_417 ( V_13 , & V_13 -> V_209 . V_526 ) ;
F_418 ( V_13 , & V_13 -> V_209 . V_741 ) ;
V_43 = F_419 ( V_13 ) ;
if ( V_43 )
V_64 = V_742 ;
if ( ( V_13 -> V_53 & V_154 ) && V_64 != V_743 ) {
struct V_736 * V_736 ;
struct V_744 * V_745 ;
const struct V_697 * V_746 ;
const T_4 * V_747 = NULL ;
unsigned int V_748 = 0 ;
V_736 = F_413 ( F_213 ( V_13 -> V_209 . V_217 ) ) ;
if ( V_736 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_60 ,
F_213 ( V_13 -> V_209 . V_217 ) ) ;
return - V_443 ;
}
V_745 = F_113 ( sizeof( * V_745 ) ) ;
V_43 = F_405 ( & V_746 , V_736 -> V_749 ,
V_13 -> V_30 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_61 ,
V_736 -> V_749 , V_43 ) ;
} else {
V_747 = V_746 -> V_117 ;
V_748 = V_746 -> V_200 ;
}
V_43 = F_420 ( V_13 , V_736 , V_747 , V_748 , V_745 ,
V_64 , & V_705 ) ;
F_401 ( V_746 ) ;
F_116 ( V_745 ) ;
if ( V_43 < 0 )
goto V_719;
}
V_43 = F_421 ( V_13 , & V_13 -> V_209 . V_512 ) ;
if ( V_43 < 0 )
goto V_719;
V_150 =
F_7 ( V_727 ) |
F_8 ( V_750 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_150 , & V_738 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_209 . V_210 = F_422 ( V_738 ) ;
V_13 -> V_209 . V_751 = V_738 ;
if ( V_64 == V_743 ) {
F_400 ( V_13 -> V_30 , L_62\
L_63 ,
V_13 -> V_53 & V_154 ? L_64 : L_65 ) ;
} else {
F_400 ( V_13 -> V_30 , L_66\
L_67 ) ;
V_209 [ 0 ] = ( F_7 ( V_727 ) |
F_8 ( V_728 ) ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_209 , V_252 ) ;
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_68
L_69 ) ;
goto V_719;
}
V_43 = F_402 ( V_13 , V_705 ) ;
if ( V_43 == - V_735 ) {
F_11 ( V_13 -> V_30 , L_70
L_71 ) ;
goto V_719;
}
if ( V_43 < 0 ) {
F_11 ( V_13 -> V_30 , L_72
L_73 , - V_43 ) ;
goto V_719;
}
}
V_43 = F_377 ( V_13 ) ;
if ( V_43 < 0 )
goto V_719;
if ( F_423 ( V_13 -> V_147 -> V_458 ) )
V_13 -> V_209 . V_752 = 1 ;
#define F_424 ( T_14 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_425 ( T_14 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_209 [ 0 ] = F_425 ( V_753 ) ;
V_209 [ 1 ] = F_425 ( V_754 ) ;
V_209 [ 2 ] = F_425 ( V_755 ) ;
V_209 [ 3 ] = F_425 ( V_756 ) ;
V_209 [ 4 ] = F_425 ( V_757 ) ;
V_209 [ 5 ] = F_425 ( V_758 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_209 , V_252 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_16 . V_108 = V_252 [ 0 ] ;
V_13 -> V_759 = V_252 [ 1 ] ;
V_13 -> V_760 = V_252 [ 2 ] ;
V_13 -> V_79 . V_80 = V_252 [ 3 ] ;
V_13 -> V_79 . V_81 = V_252 [ 4 ] - V_252 [ 3 ] + 1 ;
V_13 -> V_16 . V_187 = V_252 [ 5 ] ;
V_209 [ 0 ] = F_425 ( V_761 ) ;
V_209 [ 1 ] = F_425 ( V_762 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 , V_252 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_16 . V_202 = V_252 [ 0 ] - V_13 -> V_16 . V_108 + 1 ;
V_13 -> V_16 . V_190 = V_252 [ 1 ] - V_13 -> V_16 . V_187 + 1 ;
V_13 -> V_16 . V_107 = F_426 ( V_13 -> V_16 . V_202 ,
sizeof( * V_13 -> V_16 . V_107 ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_107 ) {
V_43 = - V_180 ;
goto V_719;
}
V_13 -> V_16 . V_188 = F_426 ( V_13 -> V_16 . V_190 ,
sizeof( * V_13 -> V_16 . V_188 ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_188 ) {
V_43 = - V_180 ;
goto V_719;
}
V_13 -> V_16 . V_201 = F_426 ( F_210 ( V_13 -> V_16 . V_202 ) ,
sizeof( long ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_201 ) {
V_43 = - V_180 ;
goto V_719;
}
V_13 -> V_16 . V_203 = F_426 ( F_210 ( V_13 -> V_16 . V_202 ) ,
sizeof( long ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_203 ) {
V_43 = - V_180 ;
goto V_719;
}
#ifdef F_183
V_13 -> V_16 . V_763 = F_426 ( F_210 ( V_13 -> V_16 . V_202 ) ,
sizeof( long ) , V_179 ) ;
if ( ! V_13 -> V_16 . V_763 ) {
V_43 = - V_180 ;
goto V_719;
}
#endif
V_209 [ 0 ] = F_425 ( V_764 ) ;
V_209 [ 1 ] = F_425 ( V_765 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 , V_252 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_766 = V_252 [ 0 ] ;
V_13 -> V_767 = V_252 [ 1 ] ;
V_209 [ 0 ] = F_425 ( V_768 ) ;
V_209 [ 1 ] = F_425 ( V_769 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 , V_252 ) ;
if ( ( V_252 [ 0 ] != V_252 [ 1 ] ) && ( V_43 >= 0 ) ) {
V_13 -> V_53 |= V_535 ;
V_13 -> V_79 . V_770 = V_252 [ 0 ] ;
V_13 -> V_79 . V_771 = V_252 [ 1 ] ;
}
V_209 [ 0 ] = F_425 ( V_772 ) ;
V_252 [ 0 ] = 1 ;
( void ) F_177 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_209 , V_252 ) ;
if ( F_110 ( V_13 -> V_209 . V_217 ) ) {
V_13 -> V_209 . V_538 = false ;
} else {
V_209 [ 0 ] = F_424 ( V_773 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_209 , V_252 ) ;
V_13 -> V_209 . V_538 = ( V_43 == 0 && V_252 [ 0 ] != 0 ) ;
}
memset ( & V_706 , 0 , sizeof( V_706 ) ) ;
V_706 . V_662 = F_123 ( F_372 ( V_663 ) |
V_664 | V_665 ) ;
V_706 . V_666 = F_123 ( F_373 ( V_706 ) ) ;
V_43 = F_374 ( V_13 , V_13 -> V_27 , & V_706 , sizeof( V_706 ) ,
& V_706 ) ;
if ( V_43 < 0 )
goto V_719;
if ( V_706 . V_774 ) {
V_209 [ 0 ] = F_424 ( V_775 ) ;
V_209 [ 1 ] = F_425 ( V_776 ) ;
V_209 [ 2 ] = F_425 ( V_777 ) ;
V_209 [ 3 ] = F_425 ( V_778 ) ;
V_209 [ 4 ] = F_425 ( V_779 ) ;
V_209 [ 5 ] = F_424 ( V_780 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_209 , V_252 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_79 . V_349 = V_252 [ 0 ] ;
V_13 -> V_79 . V_355 = F_427 ( V_13 -> V_79 . V_349 / 2 , V_781 ) ;
V_13 -> V_79 . V_330 = V_252 [ 1 ] ;
V_13 -> V_79 . V_328 = V_252 [ 2 ] - V_252 [ 1 ] + 1 ;
if ( V_13 -> V_53 & V_535 && ! F_428 ( V_13 ) ) {
V_13 -> V_79 . V_332 = V_13 -> V_79 . V_80 +
F_429 ( V_13 -> V_79 . V_81 , 3 ) ;
V_13 -> V_79 . V_82 = V_13 -> V_79 . V_81 -
F_429 ( V_13 -> V_79 . V_81 , 3 ) ;
V_13 -> V_79 . V_81 = V_13 -> V_79 . V_332 -
V_13 -> V_79 . V_80 ;
}
V_13 -> V_434 . V_782 . V_435 = V_252 [ 3 ] ;
V_13 -> V_434 . V_782 . V_200 = V_252 [ 4 ] - V_252 [ 3 ] + 1 ;
V_13 -> V_209 . V_507 = V_252 [ 5 ] ;
V_13 -> V_209 . V_783 = 1 ;
}
if ( V_706 . V_784 ) {
V_209 [ 0 ] = F_425 ( V_785 ) ;
V_209 [ 1 ] = F_425 ( V_786 ) ;
V_209 [ 2 ] = F_425 ( V_787 ) ;
V_209 [ 3 ] = F_425 ( V_788 ) ;
V_209 [ 4 ] = F_425 ( V_789 ) ;
V_209 [ 5 ] = F_425 ( V_790 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_209 , V_252 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_434 . V_421 . V_435 = V_252 [ 0 ] ;
V_13 -> V_434 . V_421 . V_200 = V_252 [ 1 ] - V_252 [ 0 ] + 1 ;
V_13 -> V_434 . V_791 . V_435 = V_252 [ 2 ] ;
V_13 -> V_434 . V_791 . V_200 = V_252 [ 3 ] - V_252 [ 2 ] + 1 ;
V_13 -> V_434 . V_792 . V_435 = V_252 [ 4 ] ;
V_13 -> V_434 . V_792 . V_200 = V_252 [ 5 ] - V_252 [ 4 ] + 1 ;
V_209 [ 0 ] = F_425 ( V_793 ) ;
V_209 [ 1 ] = F_425 ( V_794 ) ;
V_209 [ 2 ] = F_425 ( V_795 ) ;
V_209 [ 3 ] = F_425 ( V_796 ) ;
V_209 [ 4 ] = F_425 ( V_797 ) ;
V_209 [ 5 ] = F_425 ( V_798 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_209 ,
V_252 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_434 . V_799 . V_435 = V_252 [ 0 ] ;
V_13 -> V_434 . V_799 . V_200 = V_252 [ 1 ] - V_252 [ 0 ] + 1 ;
V_13 -> V_434 . V_800 . V_435 = V_252 [ 2 ] ;
V_13 -> V_434 . V_800 . V_200 = V_252 [ 3 ] - V_252 [ 2 ] + 1 ;
V_13 -> V_434 . V_654 . V_435 = V_252 [ 4 ] ;
V_13 -> V_434 . V_654 . V_200 = V_252 [ 5 ] - V_252 [ 4 ] + 1 ;
V_209 [ 0 ] = F_424 ( V_801 ) ;
V_209 [ 1 ] = F_424 ( V_802 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_209 ,
V_252 ) ;
if ( V_43 < 0 ) {
V_13 -> V_209 . V_536 = 8 ;
V_13 -> V_209 . V_537 = 32 * V_13 -> V_79 . V_349 ;
V_43 = 0 ;
} else {
V_13 -> V_209 . V_536 = V_252 [ 0 ] ;
V_13 -> V_209 . V_537 = V_252 [ 1 ] ;
}
F_400 ( V_13 -> V_30 ,
L_74 ,
V_13 -> V_209 . V_536 ,
V_13 -> V_209 . V_537 ) ;
}
if ( V_706 . V_803 ) {
V_209 [ 0 ] = F_425 ( V_804 ) ;
V_209 [ 1 ] = F_425 ( V_805 ) ;
V_43 = F_407 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_209 , V_252 ) ;
if ( V_43 < 0 )
goto V_719;
V_13 -> V_434 . V_806 . V_435 = V_252 [ 0 ] ;
V_13 -> V_434 . V_806 . V_200 = V_252 [ 1 ] - V_252 [ 0 ] + 1 ;
}
#undef F_425
#undef F_424
F_430 ( V_13 , V_13 -> V_209 . V_383 , NULL ) ;
if ( V_64 != V_743 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_384 ; V_19 ++ )
if ( V_13 -> V_209 . V_383 [ V_19 ] == 1492 ) {
V_13 -> V_209 . V_383 [ V_19 ] = 1488 ;
break;
}
F_431 ( V_13 , V_13 -> V_209 . V_383 , V_13 -> V_209 . V_807 ,
V_13 -> V_209 . V_808 ) ;
}
F_432 ( V_13 ) ;
V_13 -> V_53 |= V_809 ;
F_433 ( V_13 ) ;
return 0 ;
V_719:
F_83 ( V_13 -> V_16 . V_107 ) ;
F_83 ( V_13 -> V_16 . V_188 ) ;
F_83 ( V_13 -> V_16 . V_201 ) ;
F_83 ( V_13 -> V_16 . V_203 ) ;
#ifdef F_183
F_83 ( V_13 -> V_16 . V_763 ) ;
#endif
if ( V_43 != - V_810 && V_43 != - V_811 )
F_434 ( V_13 , V_13 -> V_27 ) ;
return V_43 ;
}
static T_15 F_435 ( struct V_402 * V_147 ,
T_16 V_64 )
{
int V_19 ;
struct V_12 * V_13 = F_238 ( V_147 ) ;
if ( ! V_13 )
goto V_102;
F_436 () ;
V_13 -> V_53 &= ~ V_809 ;
F_313 ( V_13 , V_812 ) ;
F_239 ( & V_13 -> V_406 ) ;
F_70 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
F_437 ( V_2 ) ;
F_17 ( V_2 ) ;
}
F_241 ( & V_13 -> V_406 ) ;
F_92 ( V_13 ) ;
if ( V_13 -> V_53 & V_193 )
F_329 ( V_13 ) ;
F_438 () ;
if ( ( V_13 -> V_53 & V_813 ) ) {
F_439 ( V_147 ) ;
V_13 -> V_53 &= ~ V_813 ;
}
V_102: return V_64 == V_814 ?
V_815 : V_816 ;
}
static T_15 F_440 ( struct V_402 * V_147 )
{
int V_19 , V_43 ;
struct V_660 V_661 ;
struct V_12 * V_13 = F_238 ( V_147 ) ;
if ( ! V_13 ) {
F_441 ( V_147 ) ;
F_442 ( V_147 ) ;
return V_817 ;
}
if ( ! ( V_13 -> V_53 & V_813 ) ) {
if ( F_443 ( V_147 ) ) {
F_11 ( & V_147 -> V_2 , L_75
L_76 ) ;
return V_815 ;
}
V_13 -> V_53 |= V_813 ;
}
F_444 ( V_147 ) ;
F_441 ( V_147 ) ;
F_442 ( V_147 ) ;
F_445 ( V_147 ) ;
if ( F_446 ( V_13 -> V_524 ) < 0 )
return V_815 ;
if ( F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_818 , NULL ) < 0 )
return V_815 ;
V_13 -> V_53 |= V_809 ;
if ( F_371 ( V_13 , & V_661 ) )
return V_815 ;
F_70 (adap, i) {
struct V_5 * V_6 = F_85 ( V_13 , V_19 ) ;
V_43 = F_447 ( V_13 , V_13 -> V_27 , V_6 -> V_60 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_43 < 0 )
return V_815 ;
V_6 -> V_50 = V_43 ;
V_6 -> V_58 = - 1 ;
}
F_431 ( V_13 , V_13 -> V_209 . V_383 , V_13 -> V_209 . V_807 ,
V_13 -> V_209 . V_808 ) ;
F_360 ( V_13 ) ;
if ( F_325 ( V_13 ) )
return V_815 ;
return V_817 ;
}
static void F_448 ( struct V_402 * V_147 )
{
int V_19 ;
struct V_12 * V_13 = F_238 ( V_147 ) ;
if ( ! V_13 )
return;
F_436 () ;
F_70 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
if ( F_13 ( V_2 ) ) {
F_29 ( V_2 ) ;
F_353 ( V_2 ) ;
}
F_449 ( V_2 ) ;
}
F_438 () ;
}
static inline bool F_450 ( const struct V_819 * V_820 )
{
return ( V_820 -> V_821 & V_822 ) != 0 ||
( V_820 -> V_821 & V_823 ) != 0 ;
}
static inline void F_451 ( struct V_12 * V_13 , struct V_92 * V_25 ,
unsigned int V_307 , unsigned int V_308 ,
unsigned int V_200 , unsigned int V_824 )
{
V_25 -> V_13 = V_13 ;
F_176 ( V_25 , V_307 , V_308 ) ;
V_25 -> V_825 = V_824 ;
V_25 -> V_200 = V_200 ;
}
static void F_452 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 , V_826 = 0 , V_827 = 0 ;
#ifndef F_15
int V_828 = 0 ;
#endif
int V_829 ;
F_70 (adap, i)
V_826 += F_450 ( & F_85 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_15
if ( V_13 -> V_209 . V_210 * 8 > V_830 ) {
F_11 ( V_13 -> V_30 , L_77 ,
V_830 , V_13 -> V_209 . V_210 * 8 ) ;
F_453 ( 1 ) ;
}
F_70 (adap, i) {
struct V_5 * V_11 = F_85 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_827 ;
V_11 -> V_20 = 8 ;
V_827 += V_11 -> V_20 ;
}
#else
if ( V_826 )
V_828 = ( V_830 - ( V_13 -> V_209 . V_210 - V_826 ) ) / V_826 ;
if ( V_828 > F_454 () )
V_828 = F_454 () ;
F_70 (adap, i) {
struct V_5 * V_11 = F_85 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_827 ;
V_11 -> V_20 = F_450 ( & V_11 -> V_7 ) ? V_828 : 1 ;
V_827 += V_11 -> V_20 ;
}
#endif
V_4 -> V_831 = V_827 ;
V_4 -> V_832 = V_827 ;
if ( F_381 ( V_13 ) ) {
if ( V_826 ) {
V_19 = F_455 ( int , F_19 ( V_4 -> V_172 ) ,
F_456 () ) ;
V_4 -> V_208 = F_457 ( V_19 , V_13 -> V_209 . V_210 ) ;
} else
V_4 -> V_208 = V_13 -> V_209 . V_210 ;
V_4 -> V_212 = V_13 -> V_209 . V_210 ;
V_4 -> V_214 = F_455 ( int , V_833 , F_456 () ) ;
V_4 -> V_214 = ( V_4 -> V_214 / V_13 -> V_209 . V_210 ) *
V_13 -> V_209 . V_210 ;
V_4 -> V_214 = F_458 ( int , V_4 -> V_214 , V_13 -> V_209 . V_210 ) ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_170 ) ; V_19 ++ ) {
struct V_177 * V_834 = & V_4 -> V_170 [ V_19 ] ;
F_451 ( V_13 , & V_834 -> V_136 , 5 , 10 , 1024 , 64 ) ;
V_834 -> V_199 . V_200 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_200 = 1024 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_216 ) ; V_19 ++ )
V_4 -> V_216 [ V_19 ] . V_25 . V_200 = 512 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_110 ) ; V_19 ++ )
V_4 -> V_110 [ V_19 ] . V_25 . V_200 = 1024 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_172 ) ; V_19 ++ ) {
struct V_134 * V_834 = & V_4 -> V_172 [ V_19 ] ;
F_451 ( V_13 , & V_834 -> V_136 , 5 , 1 , 1024 , 64 ) ;
V_834 -> V_136 . V_138 = V_503 ;
V_834 -> V_199 . V_200 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_173 ) ; V_19 ++ ) {
struct V_134 * V_834 = & V_4 -> V_173 [ V_19 ] ;
F_451 ( V_13 , & V_834 -> V_136 , 5 , 1 , 511 , 64 ) ;
V_834 -> V_136 . V_138 = V_475 ;
V_834 -> V_199 . V_200 = 72 ;
}
V_829 = 64 + V_13 -> V_434 . V_800 . V_200 + V_13 -> V_79 . V_81 ;
if ( V_829 > V_835 ) {
F_288 ( V_13 , L_78 ) ;
V_829 = V_835 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_174 ) ; V_19 ++ ) {
struct V_134 * V_834 = & V_4 -> V_174 [ V_19 ] ;
F_451 ( V_13 , & V_834 -> V_136 , 5 , 1 , V_829 , 64 ) ;
V_834 -> V_136 . V_138 = V_475 ;
}
F_451 ( V_13 , & V_4 -> V_169 , 0 , 1 , 1024 , 64 ) ;
F_451 ( V_13 , & V_4 -> V_204 , 0 , 1 , 2 * V_671 , 64 ) ;
}
static void F_459 ( struct V_12 * V_13 , int V_158 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_158 < V_13 -> V_16 . V_831 )
F_70 (adap, i) {
V_11 = F_85 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_831 -- ;
if ( V_13 -> V_16 . V_831 <= V_158 )
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
static int F_460 ( struct V_12 * V_13 )
{
int V_836 = 0 ;
int V_19 , V_837 , V_838 , V_839 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_505 = V_13 -> V_209 . V_210 ;
struct V_840 * V_841 ;
V_841 = F_80 ( sizeof( * V_841 ) * ( V_671 + 1 ) ,
V_179 ) ;
if ( ! V_841 )
return - V_180 ;
for ( V_19 = 0 ; V_19 < V_671 + 1 ; ++ V_19 )
V_841 [ V_19 ] . V_842 = V_19 ;
V_837 = V_4 -> V_832 + V_843 ;
if ( F_381 ( V_13 ) ) {
V_837 += V_4 -> V_212 + V_4 -> V_214 + V_4 -> V_208 ;
V_836 = 3 * V_505 ;
}
#ifdef F_15
V_838 = 8 * V_13 -> V_209 . V_210 + V_843 + V_836 ;
#else
V_838 = V_13 -> V_209 . V_210 + V_843 + V_836 ;
#endif
V_839 = F_461 ( V_13 -> V_147 , V_841 , V_838 , V_837 ) ;
if ( V_839 < 0 ) {
F_400 ( V_13 -> V_30 , L_79
L_80 ) ;
F_83 ( V_841 ) ;
return V_839 ;
}
V_19 = V_839 - V_843 - V_836 ;
if ( V_19 < V_4 -> V_832 ) {
V_4 -> V_832 = V_19 ;
if ( V_19 < V_4 -> V_831 )
F_459 ( V_13 , V_19 ) ;
}
if ( F_381 ( V_13 ) ) {
if ( V_839 < V_837 ) {
V_4 -> V_212 = V_505 ;
V_4 -> V_214 = V_505 ;
}
V_19 = V_839 - V_843 - V_4 -> V_832 -
V_4 -> V_212 - V_4 -> V_214 ;
V_4 -> V_208 = ( V_19 / V_505 ) * V_505 ;
}
for ( V_19 = 0 ; V_19 < V_839 ; ++ V_19 )
V_13 -> V_159 [ V_19 ] . V_167 = V_841 [ V_19 ] . V_844 ;
F_400 ( V_13 -> V_30 , L_81
L_82 ,
V_839 , V_4 -> V_832 , V_4 -> V_208 , V_4 -> V_212 ,
V_4 -> V_214 ) ;
F_83 ( V_841 ) ;
return 0 ;
}
static int F_462 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_463 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_70 (adap, i) {
struct V_5 * V_11 = F_85 ( V_13 , V_19 ) ;
V_11 -> V_176 = F_426 ( V_11 -> V_178 , sizeof( T_3 ) , V_179 ) ;
if ( ! V_11 -> V_176 )
return - V_180 ;
}
return 0 ;
}
static int F_464 ( struct V_12 * V_13 ,
enum V_845 * V_8 ,
enum V_846 * V_847 )
{
T_1 V_848 , V_849 ;
int V_850 , V_851 ;
#define F_465 4
* V_8 = V_852 ;
* V_847 = V_853 ;
V_850 = F_466 ( V_13 -> V_147 , V_854 ,
& V_848 ) ;
V_851 = F_466 ( V_13 -> V_147 , V_855 ,
& V_849 ) ;
if ( ! V_851 && V_849 ) {
if ( V_849 & V_856 )
* V_8 = V_857 ;
else if ( V_849 & V_858 )
* V_8 = V_859 ;
else if ( V_849 & V_860 )
* V_8 = V_861 ;
}
if ( ! V_850 ) {
* V_847 = ( V_848 & V_862 ) >> F_465 ;
if ( ! V_849 ) {
if ( V_848 & V_863 )
* V_8 = V_859 ;
else if ( V_848 & V_864 )
* V_8 = V_861 ;
}
}
if ( * V_8 == V_852 || * V_847 == V_853 )
return V_850 ? V_850 : V_851 ? V_851 : - V_443 ;
return 0 ;
}
static void F_467 ( struct V_12 * V_13 )
{
enum V_846 V_847 , V_865 ;
enum V_845 V_8 , V_866 ;
#define F_468 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_464 ( V_13 , & V_866 , & V_865 ) ) {
F_299 ( V_13 -> V_30 ,
L_83 ) ;
return;
}
if ( F_469 ( V_13 -> V_147 , & V_8 , & V_847 ) ||
V_8 == V_852 || V_847 == V_853 ) {
F_299 ( V_13 -> V_30 ,
L_84 ) ;
return;
}
F_400 ( V_13 -> V_30 , L_85 ,
F_468 ( V_8 ) , F_468 ( V_866 ) ) ;
F_400 ( V_13 -> V_30 , L_86 ,
V_847 , V_865 ) ;
if ( V_8 < V_866 || V_847 < V_865 )
F_400 ( V_13 -> V_30 ,
L_87
L_88 ) ;
}
static void F_470 ( const struct V_1 * V_2 )
{
char V_732 [ 80 ] ;
char * V_867 = V_732 ;
const char * V_868 = L_89 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_209 . V_869 . V_8 == V_870 )
V_868 = L_90 ;
else if ( V_13 -> V_209 . V_869 . V_8 == V_871 )
V_868 = L_91 ;
else if ( V_13 -> V_209 . V_869 . V_8 == V_872 )
V_868 = L_92 ;
if ( V_11 -> V_7 . V_821 & V_873 )
V_867 += sprintf ( V_867 , L_93 ) ;
if ( V_11 -> V_7 . V_821 & V_874 )
V_867 += sprintf ( V_867 , L_94 ) ;
if ( V_11 -> V_7 . V_821 & V_822 )
V_867 += sprintf ( V_867 , L_95 ) ;
if ( V_11 -> V_7 . V_821 & V_823 )
V_867 += sprintf ( V_867 , L_96 ) ;
if ( V_867 != V_732 )
-- V_867 ;
sprintf ( V_867 , L_97 , F_471 ( V_11 -> V_875 ) ) ;
F_3 ( V_2 , L_98 ,
V_13 -> V_209 . V_512 . V_876 ,
F_472 ( V_13 -> V_209 . V_217 ) , V_732 ,
F_381 ( V_13 ) ? L_99 : L_89 ,
( V_13 -> V_53 & V_146 ) ? L_100 :
( V_13 -> V_53 & V_148 ) ? L_101 : L_89 ) ;
F_3 ( V_2 , L_102 ,
V_13 -> V_209 . V_512 . V_877 , V_13 -> V_209 . V_512 . V_878 ) ;
}
static void F_473 ( struct V_402 * V_2 )
{
F_474 ( V_2 , V_879 , V_880 ) ;
}
static void F_475 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_116 ( V_12 -> V_74 ) ;
F_116 ( V_12 -> V_79 . V_340 ) ;
F_83 ( V_12 -> V_16 . V_107 ) ;
F_83 ( V_12 -> V_16 . V_188 ) ;
F_83 ( V_12 -> V_16 . V_201 ) ;
F_83 ( V_12 -> V_16 . V_203 ) ;
#ifdef F_183
F_83 ( V_12 -> V_16 . V_763 ) ;
#endif
F_61 ( V_12 ) ;
F_70 (adapter, i)
if ( V_12 -> V_34 [ V_19 ] ) {
struct V_5 * V_11 = F_85 ( V_12 , V_19 ) ;
if ( V_11 -> V_50 != 0 )
F_476 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_50 ) ;
F_83 ( F_85 ( V_12 , V_19 ) -> V_176 ) ;
F_477 ( V_12 -> V_34 [ V_19 ] ) ;
}
if ( V_12 -> V_53 & V_809 )
F_434 ( V_12 , V_12 -> V_28 ) ;
}
static int F_478 ( struct V_402 * V_147 , T_1 V_881 )
{
T_3 V_882 ;
F_479 ( V_147 , V_883 , & V_882 ) ;
switch ( V_882 >> 12 ) {
case V_720 :
return F_480 ( V_720 , V_881 ) ;
case V_357 :
return F_480 ( V_357 , V_881 ) ;
case V_723 :
return F_480 ( V_723 , V_881 ) ;
default:
F_11 ( & V_147 -> V_2 , L_50 ,
V_882 ) ;
}
return - V_443 ;
}
static int F_481 ( struct V_402 * V_147 , const struct V_884 * V_885 )
{
int V_886 , V_19 , V_22 , V_887 , V_888 , V_889 ;
struct V_5 * V_11 ;
bool V_890 = false ;
struct V_12 * V_12 = NULL ;
void T_17 * V_524 ;
T_1 V_891 , V_881 ;
enum V_394 V_217 ;
F_482 ( V_892 L_103 , V_893 , V_894 ) ;
V_22 = F_483 ( V_147 , V_895 ) ;
if ( V_22 ) {
F_400 ( & V_147 -> V_2 , L_104 ) ;
return V_22 ;
}
V_22 = F_443 ( V_147 ) ;
if ( V_22 ) {
F_11 ( & V_147 -> V_2 , L_105 ) ;
goto V_896;
}
V_524 = F_484 ( V_147 , 0 ) ;
if ( ! V_524 ) {
F_11 ( & V_147 -> V_2 , L_106 ) ;
V_22 = - V_180 ;
goto V_897;
}
V_22 = F_446 ( V_524 ) ;
if ( V_22 < 0 )
goto V_898;
V_891 = F_485 ( V_524 + V_899 ) ;
V_881 = F_486 ( F_485 ( V_524 + V_900 ) ) ;
V_217 = F_478 ( V_147 , V_881 ) ;
V_886 = F_213 ( V_217 ) <= V_357 ?
F_487 ( V_891 ) : F_488 ( V_891 ) ;
if ( V_886 != V_885 -> V_901 ) {
F_489 ( V_524 ) ;
F_439 ( V_147 ) ;
F_442 ( V_147 ) ;
goto V_902;
}
if ( ! F_490 ( V_147 , F_491 ( 64 ) ) ) {
V_890 = true ;
V_22 = F_492 ( V_147 , F_491 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_147 -> V_2 , L_107
L_108 ) ;
goto V_898;
}
} else {
V_22 = F_490 ( V_147 , F_491 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_147 -> V_2 , L_109 ) ;
goto V_898;
}
}
F_493 ( V_147 ) ;
F_473 ( V_147 ) ;
F_444 ( V_147 ) ;
F_442 ( V_147 ) ;
V_12 = F_114 ( sizeof( * V_12 ) , V_179 ) ;
if ( ! V_12 ) {
V_22 = - V_180 ;
goto V_898;
}
V_12 -> V_345 = F_494 ( L_110 ) ;
if ( ! V_12 -> V_345 ) {
V_22 = - V_180 ;
goto V_903;
}
V_12 -> V_53 |= V_813 ;
V_12 -> V_524 = V_524 ;
V_12 -> V_147 = V_147 ;
V_12 -> V_30 = & V_147 -> V_2 ;
V_12 -> V_27 = V_886 ;
V_12 -> V_28 = V_886 ;
V_12 -> V_904 = V_905 ;
memset ( V_12 -> V_906 , 0xff , sizeof( V_12 -> V_906 ) ) ;
F_211 ( & V_12 -> V_406 ) ;
F_211 ( & V_12 -> V_341 ) ;
F_211 ( & V_12 -> V_415 ) ;
F_495 ( & V_12 -> V_346 , F_204 ) ;
F_495 ( & V_12 -> V_476 , F_285 ) ;
F_495 ( & V_12 -> V_483 , F_290 ) ;
V_22 = F_496 ( V_12 ) ;
if ( V_22 )
goto V_903;
if ( ! F_110 ( V_12 -> V_209 . V_217 ) ) {
V_887 = ( V_907 +
( V_908 - V_907 ) *
V_12 -> V_28 ) ;
V_888 = 1 << F_497 ( F_65 ( V_12 ,
V_909 ) >> V_887 ) ;
V_889 = V_687 / V_910 ;
if ( V_888 > V_889 ) {
F_11 ( & V_147 -> V_2 ,
L_111 ) ;
V_22 = - V_443 ;
goto V_903;
}
V_12 -> V_489 = F_498 ( F_499 ( V_147 , 2 ) ,
F_500 ( V_147 , 2 ) ) ;
if ( ! V_12 -> V_489 ) {
F_11 ( & V_147 -> V_2 , L_112 ) ;
V_22 = - V_180 ;
goto V_903;
}
}
F_360 ( V_12 ) ;
V_22 = F_414 ( V_12 ) ;
#ifdef F_183
F_102 ( V_12 -> V_16 . V_763 , V_12 -> V_16 . V_202 ) ;
#endif
F_363 ( V_12 ) ;
if ( V_22 )
goto V_911;
if ( ! F_110 ( V_12 -> V_209 . V_217 ) )
F_67 ( V_12 , V_912 , F_501 ( 7 ) |
( F_260 ( V_12 -> V_209 . V_217 ) ? F_502 ( 0 ) :
F_503 ( 0 ) ) ) ;
F_70 (adapter, i) {
struct V_1 * V_189 ;
V_189 = F_504 ( sizeof( struct V_5 ) ,
V_830 ) ;
if ( ! V_189 ) {
V_22 = - V_180 ;
goto V_913;
}
F_505 ( V_189 , & V_147 -> V_2 ) ;
V_12 -> V_34 [ V_19 ] = V_189 ;
V_11 = F_4 ( V_189 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_58 = - 1 ;
V_11 -> V_31 = V_19 ;
V_189 -> V_149 = V_147 -> V_149 ;
V_189 -> V_914 = V_915 | V_916 |
V_917 | V_918 |
V_919 | V_920 |
V_921 | V_57 ;
if ( V_890 )
V_189 -> V_914 |= V_922 ;
V_189 -> V_56 |= V_189 -> V_914 ;
V_189 -> V_923 = V_189 -> V_56 & V_924 ;
V_189 -> V_460 |= V_925 ;
V_189 -> V_926 = & V_927 ;
#ifdef F_15
V_189 -> V_928 = & V_929 ;
F_16 ( V_189 ) ;
#endif
F_506 ( V_189 ) ;
}
F_507 ( V_147 , V_12 ) ;
if ( V_12 -> V_53 & V_809 ) {
V_22 = F_508 ( V_12 , V_886 , V_886 , 0 ) ;
if ( V_22 )
goto V_913;
} else if ( V_12 -> V_209 . V_210 == 1 ) {
T_4 V_930 [ V_931 ] ;
T_4 * V_932 = V_12 -> V_209 . V_512 . V_932 ;
V_22 = F_509 ( V_12 , & V_12 -> V_209 . V_512 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_931 ; V_19 ++ )
V_930 [ V_19 ] = ( F_510 ( V_932 [ 2 * V_19 + 0 ] ) * 16 +
F_510 ( V_932 [ 2 * V_19 + 1 ] ) ) ;
F_511 ( V_12 , 0 , V_930 ) ;
}
}
F_452 ( V_12 ) ;
V_12 -> V_74 = F_512 ( V_12 -> V_759 , V_12 -> V_760 ) ;
if ( ! V_12 -> V_74 ) {
F_299 ( & V_147 -> V_2 , L_113 ) ;
V_12 -> V_209 . V_783 = 0 ;
}
#if F_318 ( V_571 )
if ( ( F_213 ( V_12 -> V_209 . V_217 ) <= V_357 ) &&
( ! ( F_65 ( V_12 , V_933 ) & V_934 ) ) ) {
F_299 ( & V_147 -> V_2 ,
L_114 ) ;
V_12 -> V_209 . V_783 = 0 ;
} else {
V_12 -> V_935 = F_513 ( V_12 -> V_766 ,
V_12 -> V_767 ) ;
if ( ! V_12 -> V_935 ) {
F_299 ( & V_147 -> V_2 ,
L_115 ) ;
V_12 -> V_209 . V_783 = 0 ;
}
}
#endif
if ( F_381 ( V_12 ) && F_209 ( & V_12 -> V_79 ) < 0 ) {
F_299 ( & V_147 -> V_2 , L_116
L_117 ) ;
V_12 -> V_209 . V_783 = 0 ;
}
if ( F_381 ( V_12 ) ) {
if ( F_65 ( V_12 , V_933 ) & V_936 ) {
T_1 V_350 , V_937 ;
if ( V_217 <= V_357 ) {
V_937 = V_938 ;
V_350 = F_65 ( V_12 , V_937 ) ;
V_12 -> V_79 . V_350 = V_350 / 4 ;
} else {
V_937 = V_939 ;
V_350 = F_65 ( V_12 , V_937 ) ;
V_12 -> V_79 . V_350 = V_350 ;
}
}
}
if ( V_940 > 1 && F_460 ( V_12 ) == 0 )
V_12 -> V_53 |= V_146 ;
else if ( V_940 > 0 && F_514 ( V_147 ) == 0 )
V_12 -> V_53 |= V_148 ;
F_467 ( V_12 ) ;
V_22 = F_462 ( V_12 ) ;
if ( V_22 )
goto V_913;
F_70 (adapter, i) {
V_11 = F_85 ( V_12 , V_19 ) ;
F_515 ( V_12 -> V_34 [ V_19 ] , V_11 -> V_20 ) ;
F_516 ( V_12 -> V_34 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_517 ( V_12 -> V_34 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_906 [ V_11 -> V_60 ] = V_19 ;
F_470 ( V_12 -> V_34 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_147 -> V_2 , L_118 ) ;
goto V_913;
}
if ( V_22 ) {
F_299 ( & V_147 -> V_2 , L_119 , V_19 ) ;
V_22 = 0 ;
}
if ( V_941 ) {
V_12 -> V_313 = F_518 ( F_519 ( V_147 ) ,
V_941 ) ;
F_181 ( V_12 ) ;
}
V_147 -> V_942 = 1 ;
if ( F_381 ( V_12 ) )
F_303 ( V_12 ) ;
V_902:
#ifdef F_520
if ( V_886 < F_19 ( V_943 ) && V_943 [ V_886 ] > 0 )
if ( F_521 ( V_147 , V_943 [ V_886 ] ) == 0 )
F_400 ( & V_147 -> V_2 ,
L_120 ,
V_943 [ V_886 ] ) ;
#endif
return 0 ;
V_913:
F_475 ( V_12 ) ;
V_911:
if ( ! F_110 ( V_12 -> V_209 . V_217 ) )
F_489 ( V_12 -> V_489 ) ;
V_903:
if ( V_12 -> V_345 )
F_522 ( V_12 -> V_345 ) ;
F_83 ( V_12 ) ;
V_898:
F_489 ( V_524 ) ;
V_897:
F_523 ( V_147 ) ;
F_439 ( V_147 ) ;
V_896:
F_524 ( V_147 ) ;
return V_22 ;
}
static void F_525 ( struct V_402 * V_147 )
{
struct V_12 * V_12 = F_238 ( V_147 ) ;
#ifdef F_520
F_526 ( V_147 ) ;
#endif
if ( V_12 ) {
int V_19 ;
F_522 ( V_12 -> V_345 ) ;
if ( F_381 ( V_12 ) )
F_308 ( V_12 ) ;
F_92 ( V_12 ) ;
F_70 (adapter, i)
if ( V_12 -> V_34 [ V_19 ] -> V_944 == V_945 )
F_527 ( V_12 -> V_34 [ V_19 ] ) ;
F_528 ( V_12 -> V_313 ) ;
if ( V_12 -> V_79 . V_84 ) {
struct V_72 * V_73 = & V_12 -> V_79 . V_84 [ 0 ] ;
for ( V_19 = 0 ; V_19 < ( V_12 -> V_79 . V_81 +
V_12 -> V_79 . V_82 ) ; V_19 ++ , V_73 ++ )
if ( V_73 -> V_91 )
F_40 ( V_12 , V_73 ) ;
}
if ( V_12 -> V_53 & V_193 )
F_329 ( V_12 ) ;
F_475 ( V_12 ) ;
#if F_318 ( V_571 )
F_529 ( V_12 ) ;
#endif
F_489 ( V_12 -> V_524 ) ;
if ( ! F_110 ( V_12 -> V_209 . V_217 ) )
F_489 ( V_12 -> V_489 ) ;
F_523 ( V_147 ) ;
if ( ( V_12 -> V_53 & V_813 ) ) {
F_439 ( V_147 ) ;
V_12 -> V_53 &= ~ V_813 ;
}
F_524 ( V_147 ) ;
F_530 () ;
F_83 ( V_12 ) ;
} else
F_524 ( V_147 ) ;
}
static int T_18 F_531 ( void )
{
int V_43 ;
V_941 = F_518 ( V_895 , NULL ) ;
if ( ! V_941 )
F_532 ( L_121 ) ;
V_43 = F_533 ( & V_463 ) ;
if ( V_43 < 0 )
F_534 ( V_941 ) ;
#if F_318 ( V_571 )
if ( ! V_946 ) {
F_535 ( & V_947 ) ;
V_946 = true ;
}
#endif
return V_43 ;
}
static void T_19 F_536 ( void )
{
#if F_318 ( V_571 )
if ( V_946 ) {
F_537 ( & V_947 ) ;
V_946 = false ;
}
#endif
F_538 ( & V_463 ) ;
F_534 ( V_941 ) ;
}
