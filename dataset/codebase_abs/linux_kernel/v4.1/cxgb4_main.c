static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
F_3 ( V_2 , L_1 ) ;
else {
static const char * V_3 [] = { L_2 , L_3 , L_4 , L_5 } ;
const char * V_4 = L_6 ;
const struct V_5 * V_6 = F_4 ( V_2 ) ;
switch ( V_6 -> V_7 . V_8 ) {
case 10000 :
V_4 = L_7 ;
break;
case 1000 :
V_4 = L_8 ;
break;
case 100 :
V_4 = L_9 ;
break;
case 40000 :
V_4 = L_10 ;
break;
}
F_3 ( V_2 , L_11 , V_4 ,
V_3 [ V_6 -> V_7 . V_3 ] ) ;
}
}
static void F_5 ( struct V_1 * V_2 , int V_9 )
{
struct V_5 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_11 ;
struct V_13 * V_14 = & V_12 -> V_15 . V_16 [ V_10 -> V_17 ] ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_10 -> V_19 ; V_18 ++ , V_14 ++ ) {
T_1 V_20 , V_21 ;
int V_22 ;
V_20 = ( F_6 ( V_23 ) |
F_7 (
V_24 ) |
F_8 ( V_14 -> V_25 . V_26 ) ) ;
V_21 = V_9 ? V_18 : 0xffffffff ;
V_22 = F_9 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 ,
& V_20 , & V_21 ) ;
if ( V_22 )
F_10 ( V_12 -> V_29 ,
L_12 ,
V_9 ? L_13 : L_14 , V_10 -> V_30 , V_18 , - V_22 ) ;
else
V_14 -> V_31 = V_21 ;
}
}
void F_11 ( struct V_11 * V_11 , int V_30 , int V_32 )
{
struct V_1 * V_2 = V_11 -> V_33 [ V_30 ] ;
if ( F_12 ( V_2 ) && V_32 != F_2 ( V_2 ) ) {
if ( V_32 )
F_13 ( V_2 ) ;
else {
#ifdef F_14
F_15 ( V_2 ) ;
F_5 ( V_2 , false ) ;
#endif
F_16 ( V_2 ) ;
}
F_1 ( V_2 ) ;
}
}
void F_17 ( const struct V_11 * V_12 , int V_30 )
{
static const char * V_34 [] = {
NULL , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
const struct V_1 * V_2 = V_12 -> V_33 [ V_30 ] ;
const struct V_5 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_35 == V_36 )
F_3 ( V_2 , L_21 ) ;
else if ( V_10 -> V_35 < F_18 ( V_34 ) )
F_3 ( V_2 , L_22 , V_34 [ V_10 -> V_35 ] ) ;
}
static int F_19 ( const struct V_1 * V_2 , bool V_37 )
{
T_2 V_38 = 0 ;
T_2 V_39 = 0 ;
bool free = true ;
T_3 V_40 [ 7 ] ;
const T_4 * V_41 [ 7 ] ;
int V_42 , V_43 = 0 ;
const struct V_44 * V_45 ;
int V_46 = F_20 ( V_2 ) ;
int V_47 = F_21 ( V_2 ) ;
const struct V_5 * V_10 = F_4 ( V_2 ) ;
unsigned int V_48 = V_10 -> V_11 -> V_28 ;
F_22 (ha, dev) {
V_41 [ V_43 ++ ] = V_45 -> V_41 ;
if ( -- V_46 == 0 || V_43 >= F_18 ( V_41 ) ) {
V_42 = F_23 ( V_10 -> V_11 , V_48 , V_10 -> V_49 , free ,
V_43 , V_41 , V_40 , & V_39 , V_37 ) ;
if ( V_42 < 0 )
return V_42 ;
free = false ;
V_43 = 0 ;
}
}
F_24 (ha, dev) {
V_41 [ V_43 ++ ] = V_45 -> V_41 ;
if ( -- V_47 == 0 || V_43 >= F_18 ( V_41 ) ) {
V_42 = F_23 ( V_10 -> V_11 , V_48 , V_10 -> V_49 , free ,
V_43 , V_41 , V_40 , & V_38 , V_37 ) ;
if ( V_42 < 0 )
return V_42 ;
free = false ;
V_43 = 0 ;
}
}
return F_25 ( V_10 -> V_11 , V_48 , V_10 -> V_49 , V_39 != 0 ,
V_39 | V_38 , V_37 ) ;
}
static int F_26 ( struct V_1 * V_2 , int V_50 , bool V_51 )
{
int V_42 ;
struct V_5 * V_10 = F_4 ( V_2 ) ;
V_42 = F_19 ( V_2 , V_51 ) ;
if ( V_42 == 0 )
V_42 = F_27 ( V_10 -> V_11 , V_10 -> V_11 -> V_28 , V_10 -> V_49 , V_50 ,
( V_2 -> V_52 & V_53 ) ? 1 : 0 ,
( V_2 -> V_52 & V_54 ) ? 1 : 0 , 1 , - 1 ,
V_51 ) ;
return V_42 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_5 * V_10 = F_4 ( V_2 ) ;
unsigned int V_48 = V_10 -> V_11 -> V_28 ;
V_42 = F_27 ( V_10 -> V_11 , V_48 , V_10 -> V_49 , V_2 -> V_50 , - 1 , - 1 , - 1 ,
! ! ( V_2 -> V_55 & V_56 ) , true ) ;
if ( V_42 == 0 ) {
V_42 = F_29 ( V_10 -> V_11 , V_48 , V_10 -> V_49 ,
V_10 -> V_57 , V_2 -> V_58 , true ,
true ) ;
if ( V_42 >= 0 ) {
V_10 -> V_57 = V_42 ;
V_42 = 0 ;
}
}
if ( V_42 == 0 )
V_42 = F_30 ( V_10 -> V_11 , V_48 , V_10 -> V_59 ,
& V_10 -> V_7 ) ;
if ( V_42 == 0 ) {
F_31 () ;
V_42 = F_32 ( V_10 -> V_11 , V_48 , V_10 -> V_49 , true ,
true , V_60 ) ;
F_33 () ;
}
return V_42 ;
}
int F_34 ( const struct V_1 * V_2 )
{
#ifdef F_14
struct V_5 * V_10 = F_4 ( V_2 ) ;
if ( ! V_10 -> V_61 . V_62 )
return 0 ;
return ( ( V_10 -> V_61 . V_63 == V_64 ) ||
( V_10 -> V_61 . V_63 == V_65 ) ) ;
#else
return 0 ;
#endif
}
static void F_35 ( struct V_11 * V_12 , const struct V_66 * V_67 )
{
int V_33 = F_36 ( F_37 ( V_67 -> V_68 ) ) ;
struct V_1 * V_2 = V_12 -> V_33 [ V_33 ] ;
int V_69 = F_34 ( V_2 ) ;
int V_70 ;
F_38 ( V_12 , V_67 ) ;
V_70 = F_34 ( V_2 ) ;
if ( V_70 != V_69 )
F_5 ( V_2 , V_70 ) ;
}
static void F_39 ( struct V_11 * V_12 , struct V_71 * V_72 )
{
if ( V_72 -> V_73 )
F_40 ( V_72 -> V_73 ) ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
}
static void F_41 ( struct V_11 * V_12 , const struct V_74 * V_75 )
{
unsigned int V_76 = F_42 ( V_75 ) ;
unsigned int V_77 = V_76 - V_12 -> V_78 . V_79 ;
unsigned int V_42 ;
struct V_71 * V_72 ;
if ( V_76 >= V_12 -> V_78 . V_79 && V_77 <
( V_12 -> V_78 . V_80 + V_12 -> V_78 . V_81 ) ) {
V_76 = V_77 ;
V_42 = F_43 ( V_75 -> V_82 ) ;
V_72 = & V_12 -> V_78 . V_83 [ V_76 ] ;
if ( V_42 == V_84 ) {
F_39 ( V_12 , V_72 ) ;
} else if ( V_42 == V_85 ) {
F_10 ( V_12 -> V_29 , L_23 ,
V_76 ) ;
F_39 ( V_12 , V_72 ) ;
} else if ( V_42 == V_86 ) {
V_72 -> V_87 = ( F_44 ( V_75 -> V_88 ) >> 24 ) & 0xff ;
V_72 -> V_89 = 0 ;
V_72 -> V_90 = 1 ;
} else {
F_10 ( V_12 -> V_29 , L_24 ,
V_76 , V_42 ) ;
F_39 ( V_12 , V_72 ) ;
}
}
}
static int F_45 ( struct V_91 * V_25 , const T_5 * V_92 ,
const struct V_93 * V_94 )
{
T_4 V_95 = ( ( const struct V_96 * ) V_92 ) -> V_95 ;
V_92 ++ ;
if ( F_46 ( V_95 == V_97 &&
( ( const struct V_98 * ) V_92 ) -> type == V_99 ) ) {
V_92 ++ ;
V_95 = ( ( const struct V_96 * ) V_92 ) -> V_95 ;
V_92 ++ ;
if ( V_95 != V_100 ) {
F_10 ( V_25 -> V_12 -> V_29 , L_25
, V_95 ) ;
goto V_101;
}
}
if ( F_47 ( V_95 == V_100 ) ) {
const struct V_102 * V_6 = ( void * ) V_92 ;
unsigned int V_103 = F_48 ( F_37 ( V_6 -> V_104 ) ) ;
struct V_105 * V_14 ;
V_14 = V_25 -> V_12 -> V_15 . V_106 [ V_103 - V_25 -> V_12 -> V_15 . V_107 ] ;
V_14 -> V_108 ++ ;
if ( ( T_4 * ) V_14 < ( T_4 * ) V_25 -> V_12 -> V_15 . V_109 ) {
struct V_13 * V_110 ;
V_110 = F_49 ( V_14 , struct V_13 , V_25 ) ;
F_50 ( V_110 -> V_14 ) ;
} else {
struct V_111 * V_112 ;
V_112 = F_49 ( V_14 , struct V_111 , V_25 ) ;
F_51 ( & V_112 -> V_113 ) ;
}
} else if ( V_95 == V_114 || V_95 == V_97 ) {
const struct V_115 * V_6 = ( void * ) V_92 ;
#ifdef F_14
const struct V_66 * V_67 = ( const void * ) V_6 -> V_116 ;
unsigned int V_117 = F_52 ( F_37 ( V_67 -> V_68 ) ) ;
unsigned int V_118 =
F_53 ( F_37 ( V_67 -> V_119 ) ) ;
if ( V_117 == V_120 &&
V_118 == V_121 ) {
int V_33 = F_36 (
F_54 ( V_67 -> V_68 ) ) ;
struct V_1 * V_2 = V_25 -> V_12 -> V_33 [ V_33 ] ;
int V_122 = ( ( V_67 -> V_123 . V_124 . V_125 &
V_126 )
? V_127
: V_128 ) ;
F_55 ( V_2 , V_122 ) ;
}
if ( V_117 == V_120 &&
V_118 == V_129 )
F_35 ( V_25 -> V_12 , V_67 ) ;
else
#endif
if ( V_6 -> type == 0 )
F_56 ( V_25 -> V_12 , V_6 -> V_116 ) ;
} else if ( V_95 == V_130 ) {
const struct V_131 * V_6 = ( void * ) V_92 ;
F_57 ( V_25 -> V_12 , V_6 ) ;
} else if ( V_95 == V_132 ) {
const struct V_74 * V_6 = ( void * ) V_92 ;
F_41 ( V_25 -> V_12 , V_6 ) ;
} else
F_10 ( V_25 -> V_12 -> V_29 ,
L_26 , V_95 ) ;
V_101:
return 0 ;
}
static int F_58 ( struct V_91 * V_25 , const T_5 * V_92 ,
const struct V_93 * V_94 )
{
struct V_133 * V_134 = F_49 ( V_25 , struct V_133 , V_135 ) ;
if ( ( ( const struct V_96 * ) V_92 ) -> V_95 == V_97 &&
( ( const struct V_98 * ) ( V_92 + 1 ) ) -> type == V_99 )
V_92 += 2 ;
if ( V_136 [ V_25 -> V_137 ] . F_59 ( V_25 -> V_12 -> V_138 [ V_25 -> V_137 ] , V_92 , V_94 ) ) {
V_134 -> V_139 . V_140 ++ ;
return - 1 ;
}
if ( V_94 == NULL )
V_134 -> V_139 . V_141 ++ ;
else if ( V_94 == V_142 )
V_134 -> V_139 . V_143 ++ ;
else
V_134 -> V_139 . V_144 ++ ;
return 0 ;
}
static void F_60 ( struct V_11 * V_11 )
{
if ( V_11 -> V_52 & V_145 ) {
F_61 ( V_11 -> V_146 ) ;
V_11 -> V_52 &= ~ V_145 ;
} else if ( V_11 -> V_52 & V_147 ) {
F_62 ( V_11 -> V_146 ) ;
V_11 -> V_52 &= ~ V_147 ;
}
}
static T_6 F_63 ( int V_148 , void * V_82 )
{
struct V_11 * V_12 = V_82 ;
T_1 V_149 = F_64 ( V_12 , F_65 ( V_150 ) ) ;
if ( V_149 & V_151 ) {
V_12 -> V_152 = 1 ;
F_66 ( V_12 , F_65 ( V_150 ) , V_149 ) ;
}
if ( V_12 -> V_52 & V_153 )
F_67 ( V_12 ) ;
return V_154 ;
}
static void F_68 ( struct V_11 * V_12 )
{
int V_18 , V_155 , V_156 = 2 , V_157 = sizeof( V_12 -> V_158 [ 0 ] . V_159 ) ;
snprintf ( V_12 -> V_158 [ 0 ] . V_159 , V_157 , L_27 , V_12 -> V_33 [ 0 ] -> V_20 ) ;
snprintf ( V_12 -> V_158 [ 1 ] . V_159 , V_157 , L_28 ,
V_12 -> V_33 [ 0 ] -> V_20 ) ;
F_69 (adap, j) {
struct V_1 * V_160 = V_12 -> V_33 [ V_155 ] ;
const struct V_5 * V_10 = F_4 ( V_160 ) ;
for ( V_18 = 0 ; V_18 < V_10 -> V_19 ; V_18 ++ , V_156 ++ )
snprintf ( V_12 -> V_158 [ V_156 ] . V_159 , V_157 , L_29 ,
V_160 -> V_20 , V_18 ) ;
}
F_70 (&adap->sge, i)
snprintf ( V_12 -> V_158 [ V_156 ++ ] . V_159 , V_157 , L_30 ,
V_12 -> V_33 [ 0 ] -> V_20 , V_18 ) ;
F_71 (&adap->sge, i)
snprintf ( V_12 -> V_158 [ V_156 ++ ] . V_159 , V_157 , L_31 ,
V_12 -> V_33 [ 0 ] -> V_20 , V_18 ) ;
F_72 (&adap->sge, i)
snprintf ( V_12 -> V_158 [ V_156 ++ ] . V_159 , V_157 , L_32 ,
V_12 -> V_33 [ 0 ] -> V_20 , V_18 ) ;
}
static int F_73 ( struct V_11 * V_12 )
{
struct V_15 * V_4 = & V_12 -> V_15 ;
int V_22 , V_161 , V_162 = 0 , V_163 = 0 , V_164 = 0 ;
int V_165 = 2 ;
V_22 = F_74 ( V_12 -> V_158 [ 1 ] . V_166 , V_167 , 0 ,
V_12 -> V_158 [ 1 ] . V_159 , & V_4 -> V_168 ) ;
if ( V_22 )
return V_22 ;
F_75 (s, ethqidx) {
V_22 = F_74 ( V_12 -> V_158 [ V_165 ] . V_166 ,
V_167 , 0 ,
V_12 -> V_158 [ V_165 ] . V_159 ,
& V_4 -> V_169 [ V_161 ] . V_135 ) ;
if ( V_22 )
goto V_170;
V_165 ++ ;
}
F_70 (s, ofldqidx) {
V_22 = F_74 ( V_12 -> V_158 [ V_165 ] . V_166 ,
V_167 , 0 ,
V_12 -> V_158 [ V_165 ] . V_159 ,
& V_4 -> V_171 [ V_162 ] . V_135 ) ;
if ( V_22 )
goto V_170;
V_165 ++ ;
}
F_71 (s, rdmaqidx) {
V_22 = F_74 ( V_12 -> V_158 [ V_165 ] . V_166 ,
V_167 , 0 ,
V_12 -> V_158 [ V_165 ] . V_159 ,
& V_4 -> V_172 [ V_163 ] . V_135 ) ;
if ( V_22 )
goto V_170;
V_165 ++ ;
}
F_72 (s, rdmaciqqidx) {
V_22 = F_74 ( V_12 -> V_158 [ V_165 ] . V_166 ,
V_167 , 0 ,
V_12 -> V_158 [ V_165 ] . V_159 ,
& V_4 -> V_173 [ V_164 ] . V_135 ) ;
if ( V_22 )
goto V_170;
V_165 ++ ;
}
return 0 ;
V_170:
while ( -- V_164 >= 0 )
F_76 ( V_12 -> V_158 [ -- V_165 ] . V_166 ,
& V_4 -> V_173 [ V_164 ] . V_135 ) ;
while ( -- V_163 >= 0 )
F_76 ( V_12 -> V_158 [ -- V_165 ] . V_166 ,
& V_4 -> V_172 [ V_163 ] . V_135 ) ;
while ( -- V_162 >= 0 )
F_76 ( V_12 -> V_158 [ -- V_165 ] . V_166 ,
& V_4 -> V_171 [ V_162 ] . V_135 ) ;
while ( -- V_161 >= 0 )
F_76 ( V_12 -> V_158 [ -- V_165 ] . V_166 ,
& V_4 -> V_169 [ V_161 ] . V_135 ) ;
F_76 ( V_12 -> V_158 [ 1 ] . V_166 , & V_4 -> V_168 ) ;
return V_22 ;
}
static void F_77 ( struct V_11 * V_12 )
{
int V_18 , V_165 = 2 ;
struct V_15 * V_4 = & V_12 -> V_15 ;
F_76 ( V_12 -> V_158 [ 1 ] . V_166 , & V_4 -> V_168 ) ;
F_75 (s, i)
F_76 ( V_12 -> V_158 [ V_165 ++ ] . V_166 , & V_4 -> V_169 [ V_18 ] . V_135 ) ;
F_70 (s, i)
F_76 ( V_12 -> V_158 [ V_165 ++ ] . V_166 , & V_4 -> V_171 [ V_18 ] . V_135 ) ;
F_71 (s, i)
F_76 ( V_12 -> V_158 [ V_165 ++ ] . V_166 , & V_4 -> V_172 [ V_18 ] . V_135 ) ;
F_72 (s, i)
F_76 ( V_12 -> V_158 [ V_165 ++ ] . V_166 , & V_4 -> V_173 [ V_18 ] . V_135 ) ;
}
int F_78 ( const struct V_5 * V_10 , const T_3 * V_174 )
{
T_3 * V_175 ;
int V_18 , V_22 ;
const struct V_176 * V_25 = & V_10 -> V_11 -> V_15 . V_169 [ V_10 -> V_17 ] ;
V_175 = F_79 ( V_10 -> V_177 * sizeof( T_3 ) , V_178 ) ;
if ( ! V_175 )
return - V_179 ;
for ( V_18 = 0 ; V_18 < V_10 -> V_177 ; V_18 ++ , V_174 ++ )
V_175 [ V_18 ] = V_25 [ * V_174 ] . V_135 . V_180 ;
V_22 = F_80 ( V_10 -> V_11 , V_10 -> V_11 -> V_28 , V_10 -> V_49 , 0 ,
V_10 -> V_177 , V_175 , V_10 -> V_177 ) ;
F_81 ( V_175 ) ;
return V_22 ;
}
static int F_82 ( struct V_11 * V_12 )
{
int V_18 , V_22 ;
F_69 (adap, i) {
const struct V_5 * V_10 = F_83 ( V_12 , V_18 ) ;
V_22 = F_78 ( V_10 , V_10 -> V_175 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static unsigned int F_84 ( const struct V_15 * V_6 , unsigned int V_103 )
{
V_103 -= V_6 -> V_181 ;
return F_85 ( V_6 -> V_182 [ V_103 ] -> V_183 ) -> V_59 ;
}
static void F_86 ( struct V_11 * V_12 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_15 . V_184 ; V_18 ++ ) {
struct V_91 * V_25 = V_12 -> V_15 . V_182 [ V_18 ] ;
if ( V_25 && V_25 -> V_185 ) {
F_87 ( & V_25 -> V_186 ) ;
F_31 () ;
while ( ! F_88 ( V_25 ) )
F_89 ( 1 ) ;
F_33 () ;
}
}
}
static void F_90 ( struct V_11 * V_12 )
{
if ( V_12 -> V_52 & V_187 ) {
F_91 ( V_12 ) ;
if ( V_12 -> V_52 & V_145 ) {
F_77 ( V_12 ) ;
F_76 ( V_12 -> V_158 [ 0 ] . V_166 , V_12 ) ;
} else {
F_76 ( V_12 -> V_146 -> V_148 , V_12 ) ;
}
F_86 ( V_12 ) ;
}
}
static void F_92 ( struct V_11 * V_12 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_15 . V_184 ; V_18 ++ ) {
struct V_91 * V_25 = V_12 -> V_15 . V_182 [ V_18 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_185 ) {
F_93 ( V_25 ) ;
F_94 ( & V_25 -> V_186 ) ;
}
F_66 ( V_12 , F_65 ( V_188 ) ,
F_95 ( V_25 -> V_189 ) |
F_96 ( V_25 -> V_26 ) ) ;
}
}
static int F_97 ( struct V_11 * V_12 , struct V_133 * V_25 ,
unsigned int V_190 , unsigned int V_191 , int V_156 ,
T_3 * V_192 )
{
int V_18 , V_22 ;
for ( V_18 = 0 ; V_18 < V_190 ; V_18 ++ , V_25 ++ ) {
if ( V_156 > 0 )
V_156 ++ ;
V_22 = F_98 ( V_12 , & V_25 -> V_135 , false ,
V_12 -> V_33 [ V_18 / V_191 ] ,
V_156 , V_25 -> V_193 . V_194 ? & V_25 -> V_193 : NULL ,
F_58 ) ;
if ( V_22 )
return V_22 ;
memset ( & V_25 -> V_139 , 0 , sizeof( V_25 -> V_139 ) ) ;
if ( V_192 )
V_192 [ V_18 ] = V_25 -> V_135 . V_180 ;
}
return 0 ;
}
static int F_99 ( struct V_11 * V_12 )
{
int V_22 , V_156 , V_18 , V_155 ;
struct V_15 * V_4 = & V_12 -> V_15 ;
F_100 ( V_4 -> V_195 , V_4 -> V_196 ) ;
F_100 ( V_4 -> V_197 , V_4 -> V_196 ) ;
if ( V_12 -> V_52 & V_145 )
V_156 = 1 ;
else {
V_22 = F_98 ( V_12 , & V_4 -> V_198 , false , V_12 -> V_33 [ 0 ] , 0 ,
NULL , NULL ) ;
if ( V_22 )
return V_22 ;
V_156 = - ( ( int ) V_4 -> V_198 . V_180 + 1 ) ;
}
V_22 = F_98 ( V_12 , & V_4 -> V_168 , true , V_12 -> V_33 [ 0 ] ,
V_156 , NULL , F_45 ) ;
if ( V_22 ) {
V_199: F_101 ( V_12 ) ;
return V_22 ;
}
F_69 (adap, i) {
struct V_1 * V_2 = V_12 -> V_33 [ V_18 ] ;
struct V_5 * V_10 = F_4 ( V_2 ) ;
struct V_176 * V_25 = & V_4 -> V_169 [ V_10 -> V_17 ] ;
struct V_13 * V_200 = & V_4 -> V_16 [ V_10 -> V_17 ] ;
for ( V_155 = 0 ; V_155 < V_10 -> V_19 ; V_155 ++ , V_25 ++ ) {
if ( V_156 > 0 )
V_156 ++ ;
V_22 = F_98 ( V_12 , & V_25 -> V_135 , false , V_2 ,
V_156 , & V_25 -> V_193 ,
V_201 ) ;
if ( V_22 )
goto V_199;
V_25 -> V_135 . V_76 = V_155 ;
memset ( & V_25 -> V_139 , 0 , sizeof( V_25 -> V_139 ) ) ;
}
for ( V_155 = 0 ; V_155 < V_10 -> V_19 ; V_155 ++ , V_200 ++ ) {
V_22 = F_102 ( V_12 , V_200 , V_2 ,
F_103 ( V_2 , V_155 ) ,
V_4 -> V_168 . V_26 ) ;
if ( V_22 )
goto V_199;
}
}
V_155 = V_4 -> V_202 / V_12 -> V_203 . V_204 ;
F_70 (s, i) {
V_22 = F_104 ( V_12 , & V_4 -> V_109 [ V_18 ] ,
V_12 -> V_33 [ V_18 / V_155 ] ,
V_4 -> V_168 . V_26 ) ;
if ( V_22 )
goto V_199;
}
#define F_105 ( T_7 , V_190 , V_191 , V_192 ) do { \
err = alloc_ofld_rxqs(adap, firstq, nq, per_chan, msi_idx, ids); \
if (err) \
goto freeout; \
if (msi_idx > 0) \
msi_idx += nq; \
} while (0)
F_105 ( V_4 -> V_171 , V_4 -> V_202 , V_155 , V_4 -> V_205 ) ;
F_105 ( V_4 -> V_172 , V_4 -> V_206 , 1 , V_4 -> V_207 ) ;
V_155 = V_4 -> V_208 / V_12 -> V_203 . V_204 ;
F_105 ( V_4 -> V_173 , V_4 -> V_208 , V_155 , V_4 -> V_209 ) ;
#undef F_105
F_69 (adap, i) {
V_22 = F_106 ( V_12 , & V_4 -> V_210 [ V_18 ] , V_12 -> V_33 [ V_18 ] ,
V_4 -> V_168 . V_26 ,
V_4 -> V_172 [ V_18 ] . V_135 . V_26 ) ;
if ( V_22 )
goto V_199;
}
F_66 ( V_12 , F_107 ( V_12 -> V_203 . V_211 ) ?
V_212 :
V_213 ,
F_108 ( F_85 ( V_12 -> V_33 [ 0 ] ) -> V_59 ) |
F_109 ( V_4 -> V_169 [ 0 ] . V_135 . V_180 ) ) ;
return 0 ;
}
void * F_110 ( T_8 V_194 )
{
void * V_6 = F_111 ( V_194 , V_178 | V_214 ) ;
if ( ! V_6 )
V_6 = F_112 ( V_194 ) ;
return V_6 ;
}
void F_113 ( void * V_41 )
{
if ( F_114 ( V_41 ) )
F_115 ( V_41 ) ;
else
F_81 ( V_41 ) ;
}
static int F_116 ( struct V_11 * V_11 , int V_215 )
{
struct V_71 * V_72 = & V_11 -> V_78 . V_83 [ V_215 ] ;
struct V_216 * V_217 ;
struct V_218 * V_219 ;
unsigned int V_220 ;
V_217 = F_117 ( sizeof( * V_219 ) , V_178 ) ;
if ( ! V_217 )
return - V_179 ;
if ( V_72 -> V_221 . V_222 || V_72 -> V_221 . V_223 ) {
V_72 -> V_73 = F_118 ( V_11 -> V_73 ) ;
if ( V_72 -> V_73 == NULL ) {
F_119 ( V_217 ) ;
return - V_224 ;
}
if ( F_120 ( V_11 , V_72 -> V_73 , V_72 -> V_221 . V_225 ,
V_72 -> V_221 . V_226 , V_72 -> V_221 . V_227 ) ) {
F_40 ( V_72 -> V_73 ) ;
V_72 -> V_73 = NULL ;
F_119 ( V_217 ) ;
return - V_179 ;
}
}
V_220 = V_11 -> V_78 . V_79 + V_215 ;
V_219 = (struct V_218 * ) F_121 ( V_217 , sizeof( * V_219 ) ) ;
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
V_219 -> V_228 = F_122 ( F_123 ( V_229 ) ) ;
V_219 -> V_230 = F_122 ( F_124 ( sizeof( * V_219 ) / 16 ) ) ;
V_219 -> V_231 =
F_122 ( F_125 ( V_220 ) |
F_126 ( V_72 -> V_221 . type ) |
F_127 ( 0 ) |
F_128 ( V_72 -> V_221 . V_232 ) ) ;
V_219 -> V_233 =
F_122 ( F_129 ( V_72 -> V_221 . V_234 ) |
F_130 ( V_72 -> V_221 . V_118 == V_235 ) |
F_131 ( V_72 -> V_221 . V_236 ) |
F_132 ( V_72 -> V_221 . V_237 ) |
F_133 ( V_72 -> V_221 . V_238 ) |
F_134 ( V_72 -> V_221 . V_118 == V_239 ) |
F_135 ( V_72 -> V_221 . V_222 ) |
F_136 ( V_72 -> V_221 . V_240 ) |
F_137 ( V_72 -> V_221 . V_223 == V_241 ||
V_72 -> V_221 . V_223 == V_242 ) |
F_138 ( V_72 -> V_221 . V_223 == V_243 ||
V_72 -> V_221 . V_223 == V_242 ) |
F_139 ( V_72 -> V_221 . V_244 ) |
F_140 ( V_72 -> V_221 . V_226 ) |
F_141 ( V_72 -> V_221 . V_245 ) |
F_142 ( V_72 -> V_73 ? V_72 -> V_73 -> V_76 : 0 ) ) ;
V_219 -> V_246 = F_143 ( V_72 -> V_221 . V_247 . V_246 ) ;
V_219 -> V_248 = F_143 ( V_72 -> V_221 . V_249 . V_246 ) ;
V_219 -> V_250 =
( F_144 ( V_72 -> V_221 . V_247 . V_251 ) |
F_145 ( V_72 -> V_221 . V_249 . V_251 ) |
F_146 ( V_72 -> V_221 . V_247 . V_252 ) |
F_147 ( V_72 -> V_221 . V_247 . V_253 ) |
F_148 ( V_72 -> V_221 . V_249 . V_252 ) |
F_149 ( V_72 -> V_221 . V_249 . V_253 ) ) ;
V_219 -> V_254 = 0 ;
V_219 -> V_255 =
F_143 ( F_150 ( 0 ) |
F_151 ( V_11 -> V_15 . V_168 . V_180 ) ) ;
V_219 -> V_256 =
F_122 ( F_152 ( V_72 -> V_221 . V_247 . V_257 ) |
F_153 ( V_72 -> V_221 . V_249 . V_257 ) |
F_154 ( V_72 -> V_221 . V_247 . V_258 ) |
F_155 ( V_72 -> V_221 . V_249 . V_258 ) |
F_156 ( V_72 -> V_221 . V_247 . V_259 ) |
F_157 ( V_72 -> V_221 . V_249 . V_259 ) |
F_158 ( V_72 -> V_221 . V_247 . V_260 ) |
F_159 ( V_72 -> V_221 . V_249 . V_260 ) ) ;
V_219 -> V_261 = V_72 -> V_221 . V_247 . V_262 ;
V_219 -> V_263 = V_72 -> V_221 . V_249 . V_262 ;
V_219 -> V_264 = V_72 -> V_221 . V_247 . V_265 ;
V_219 -> V_266 = V_72 -> V_221 . V_249 . V_265 ;
V_219 -> V_267 = F_143 ( V_72 -> V_221 . V_247 . V_267 ) ;
V_219 -> V_268 = F_143 ( V_72 -> V_221 . V_249 . V_267 ) ;
V_219 -> V_269 = F_143 ( V_72 -> V_221 . V_247 . V_269 ) ;
V_219 -> V_270 = F_143 ( V_72 -> V_221 . V_249 . V_269 ) ;
memcpy ( V_219 -> V_271 , V_72 -> V_221 . V_247 . V_271 , sizeof( V_219 -> V_271 ) ) ;
memcpy ( V_219 -> V_272 , V_72 -> V_221 . V_249 . V_271 , sizeof( V_219 -> V_272 ) ) ;
memcpy ( V_219 -> V_273 , V_72 -> V_221 . V_247 . V_273 , sizeof( V_219 -> V_273 ) ) ;
memcpy ( V_219 -> V_274 , V_72 -> V_221 . V_249 . V_273 , sizeof( V_219 -> V_274 ) ) ;
V_219 -> V_275 = F_143 ( V_72 -> V_221 . V_247 . V_276 ) ;
V_219 -> V_277 = F_143 ( V_72 -> V_221 . V_249 . V_276 ) ;
V_219 -> V_278 = F_143 ( V_72 -> V_221 . V_247 . V_279 ) ;
V_219 -> V_280 = F_143 ( V_72 -> V_221 . V_249 . V_279 ) ;
if ( V_72 -> V_221 . V_240 )
memcpy ( V_219 -> V_281 , V_72 -> V_221 . V_282 , sizeof( V_219 -> V_281 ) ) ;
V_72 -> V_89 = 1 ;
F_160 ( V_217 , V_283 , V_72 -> V_221 . V_247 . V_259 & 0x3 ) ;
F_161 ( V_11 , V_217 ) ;
return 0 ;
}
static int F_162 ( struct V_11 * V_11 , int V_215 )
{
struct V_71 * V_72 = & V_11 -> V_78 . V_83 [ V_215 ] ;
struct V_216 * V_217 ;
struct V_218 * V_219 ;
unsigned int V_284 , V_220 ;
V_284 = sizeof( * V_219 ) ;
V_220 = V_11 -> V_78 . V_79 + V_215 ;
V_217 = F_117 ( V_284 , V_178 ) ;
if ( ! V_217 )
return - V_179 ;
V_219 = (struct V_218 * ) F_121 ( V_217 , V_284 ) ;
F_163 ( V_220 , V_219 , V_11 -> V_15 . V_168 . V_180 ) ;
V_72 -> V_89 = 1 ;
F_164 ( V_11 , V_217 ) ;
return 0 ;
}
static T_3 F_165 ( struct V_1 * V_2 , struct V_216 * V_217 ,
void * V_285 , T_9 V_286 )
{
int V_14 ;
#ifdef F_14
if ( F_34 ( V_2 ) ) {
T_3 V_287 ;
int V_22 ;
V_22 = F_166 ( V_217 , & V_287 ) ;
if ( F_46 ( V_22 ) ) {
if ( F_167 () )
F_168 ( V_2 ,
L_33 ) ;
V_14 = 0 ;
} else {
V_14 = ( V_287 & V_288 ) >> V_289 ;
#ifdef F_169
if ( V_217 -> V_290 == F_143 ( V_291 ) )
V_14 = V_217 -> V_292 & 0x7 ;
#endif
}
return V_14 ;
}
#endif
if ( V_293 ) {
V_14 = ( F_170 ( V_217 )
? F_171 ( V_217 )
: F_172 () ) ;
while ( F_46 ( V_14 >= V_2 -> V_294 ) )
V_14 -= V_2 -> V_294 ;
return V_14 ;
}
return V_286 ( V_2 , V_217 ) % V_2 -> V_294 ;
}
static inline int F_173 ( const struct V_11 * V_12 )
{
return V_12 -> V_203 . V_295 ;
}
static int F_174 ( const struct V_15 * V_4 , int time )
{
int V_18 , V_296 , V_297 = 0 , V_298 = V_299 ;
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_300 ) ; V_18 ++ ) {
V_296 = time - V_4 -> V_300 [ V_18 ] ;
if ( V_296 < 0 )
V_296 = - V_296 ;
if ( V_296 < V_298 ) {
V_298 = V_296 ;
V_297 = V_18 ;
}
}
return V_297 ;
}
static int F_175 ( const struct V_15 * V_4 , int V_301 )
{
int V_18 , V_296 , V_297 = 0 , V_298 = V_299 ;
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_302 ) ; V_18 ++ ) {
V_296 = V_301 - V_4 -> V_302 [ V_18 ] ;
if ( V_296 < 0 )
V_296 = - V_296 ;
if ( V_296 < V_298 ) {
V_298 = V_296 ;
V_297 = V_18 ;
}
}
return V_297 ;
}
int F_176 ( struct V_91 * V_25 ,
unsigned int V_303 , unsigned int V_304 )
{
struct V_11 * V_12 = V_25 -> V_12 ;
if ( ( V_303 | V_304 ) == 0 )
V_304 = 1 ;
if ( V_304 ) {
int V_22 ;
T_1 V_149 , V_305 ;
V_305 = F_175 ( & V_12 -> V_15 , V_304 ) ;
if ( V_25 -> V_159 && V_25 -> V_306 != V_305 ) {
V_149 = F_6 ( V_23 ) |
F_7 (
V_307 ) |
F_8 ( V_25 -> V_26 ) ;
V_22 = F_177 ( V_12 , V_12 -> V_28 , V_12 -> V_28 , 0 , 1 , & V_149 ,
& V_305 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_306 = V_305 ;
}
V_303 = V_303 == 0 ? 6 : F_174 ( & V_12 -> V_15 , V_303 ) ;
V_25 -> V_189 = F_178 ( V_303 ) | ( V_304 > 0 ? V_308 : 0 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , T_10 V_55 )
{
const struct V_5 * V_10 = F_4 ( V_2 ) ;
T_10 V_309 = V_2 -> V_55 ^ V_55 ;
int V_22 ;
if ( ! ( V_309 & V_56 ) )
return 0 ;
V_22 = F_27 ( V_10 -> V_11 , V_10 -> V_11 -> V_28 , V_10 -> V_49 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_55 & V_56 ) , true ) ;
if ( F_46 ( V_22 ) )
V_2 -> V_55 = V_55 ^ V_56 ;
return V_22 ;
}
static int F_180 ( struct V_11 * V_12 )
{
if ( F_181 ( V_12 -> V_310 ) )
return - 1 ;
#ifdef F_182
F_183 ( V_12 ) ;
#endif
return 0 ;
}
int F_184 ( struct V_311 * V_200 , void * V_116 )
{
int V_312 = - 1 ;
F_185 ( & V_200 -> V_313 ) ;
if ( V_200 -> V_314 ) {
union V_315 * V_6 = V_200 -> V_314 ;
V_312 = ( V_6 - V_200 -> V_316 ) + V_200 -> V_317 ;
V_200 -> V_314 = V_6 -> V_318 ;
V_6 -> V_116 = V_116 ;
V_200 -> V_319 ++ ;
}
F_186 ( & V_200 -> V_313 ) ;
return V_312 ;
}
void F_187 ( struct V_311 * V_200 , unsigned int V_312 )
{
union V_315 * V_6 = & V_200 -> V_316 [ V_312 - V_200 -> V_317 ] ;
F_185 ( & V_200 -> V_313 ) ;
V_6 -> V_318 = V_200 -> V_314 ;
V_200 -> V_314 = V_6 ;
V_200 -> V_319 -- ;
F_186 ( & V_200 -> V_313 ) ;
}
int F_188 ( struct V_311 * V_200 , int V_320 , void * V_116 )
{
int V_321 ;
F_185 ( & V_200 -> V_322 ) ;
if ( V_320 == V_323 ) {
V_321 = F_189 ( V_200 -> V_324 , V_200 -> V_325 ) ;
if ( V_321 < V_200 -> V_325 )
F_190 ( V_321 , V_200 -> V_324 ) ;
else
V_321 = - 1 ;
} else {
V_321 = F_191 ( V_200 -> V_324 , V_200 -> V_325 , 2 ) ;
if ( V_321 < 0 )
V_321 = - 1 ;
}
if ( V_321 >= 0 ) {
V_200 -> V_326 [ V_321 ] . V_116 = V_116 ;
V_321 += V_200 -> V_327 ;
if ( V_320 == V_323 )
V_200 -> V_328 ++ ;
else
V_200 -> V_328 += 4 ;
}
F_186 ( & V_200 -> V_322 ) ;
return V_321 ;
}
int F_192 ( struct V_311 * V_200 , int V_320 , void * V_116 )
{
int V_321 ;
F_185 ( & V_200 -> V_322 ) ;
if ( V_320 == V_323 ) {
V_321 = F_193 ( V_200 -> V_324 ,
V_200 -> V_325 + V_200 -> V_81 , V_200 -> V_325 ) ;
if ( V_321 < ( V_200 -> V_325 + V_200 -> V_81 ) )
F_190 ( V_321 , V_200 -> V_324 ) ;
else
V_321 = - 1 ;
} else {
V_321 = - 1 ;
}
if ( V_321 >= 0 ) {
V_200 -> V_326 [ V_321 ] . V_116 = V_116 ;
V_321 -= V_200 -> V_325 ;
V_321 += V_200 -> V_329 ;
V_200 -> V_328 ++ ;
}
F_186 ( & V_200 -> V_322 ) ;
return V_321 ;
}
void F_194 ( struct V_311 * V_200 , unsigned int V_321 , int V_320 )
{
if ( V_200 -> V_81 && ( V_321 >= V_200 -> V_329 ) ) {
V_321 -= V_200 -> V_329 ;
V_321 += V_200 -> V_325 ;
} else {
V_321 -= V_200 -> V_327 ;
}
F_185 ( & V_200 -> V_322 ) ;
if ( V_320 == V_323 )
F_195 ( V_321 , V_200 -> V_324 ) ;
else
F_196 ( V_200 -> V_324 , V_321 , 2 ) ;
V_200 -> V_326 [ V_321 ] . V_116 = NULL ;
if ( V_320 == V_323 )
V_200 -> V_328 -- ;
else
V_200 -> V_328 -= 4 ;
F_186 ( & V_200 -> V_322 ) ;
}
static void F_197 ( struct V_216 * V_217 , unsigned int V_330 ,
unsigned int V_331 )
{
struct V_332 * V_333 ;
F_160 ( V_217 , V_334 , V_330 ) ;
V_333 = (struct V_332 * ) F_121 ( V_217 , sizeof( * V_333 ) ) ;
F_198 ( V_333 , V_331 ) ;
F_199 ( V_333 ) = F_122 ( F_200 ( V_335 , V_331 ) ) ;
}
static void F_201 ( struct V_311 * V_200 , unsigned int V_330 ,
unsigned int V_331 )
{
void * * V_6 = & V_200 -> V_336 [ V_331 ] ;
struct V_11 * V_12 = F_49 ( V_200 , struct V_11 , V_78 ) ;
F_185 ( & V_12 -> V_337 ) ;
* V_6 = V_12 -> V_338 ;
V_12 -> V_338 = ( void * * ) ( ( V_339 ) V_6 | V_330 ) ;
if ( ! V_12 -> V_340 ) {
V_12 -> V_340 = true ;
F_202 ( V_12 -> V_341 , & V_12 -> V_342 ) ;
}
F_186 ( & V_12 -> V_337 ) ;
}
static void F_203 ( struct V_343 * V_344 )
{
struct V_216 * V_217 ;
struct V_11 * V_12 ;
V_12 = F_49 ( V_344 , struct V_11 , V_342 ) ;
F_185 ( & V_12 -> V_337 ) ;
while ( V_12 -> V_338 ) {
void * * V_6 = V_12 -> V_338 ;
unsigned int V_330 = ( V_339 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_330 ;
V_12 -> V_338 = * V_6 ;
* V_6 = NULL ;
F_186 ( & V_12 -> V_337 ) ;
while ( ! ( V_217 = F_117 ( sizeof( struct V_332 ) ,
V_178 ) ) )
F_204 ( 1 ) ;
F_197 ( V_217 , V_330 , V_6 - V_12 -> V_78 . V_336 ) ;
F_161 ( V_12 , V_217 ) ;
F_185 ( & V_12 -> V_337 ) ;
}
V_12 -> V_340 = false ;
F_186 ( & V_12 -> V_337 ) ;
}
void F_205 ( struct V_311 * V_200 , unsigned int V_330 , unsigned int V_331 )
{
void * V_345 ;
struct V_216 * V_217 ;
struct V_11 * V_12 = F_49 ( V_200 , struct V_11 , V_78 ) ;
V_345 = V_200 -> V_336 [ V_331 ] ;
V_217 = F_117 ( sizeof( struct V_332 ) , V_346 ) ;
if ( F_47 ( V_217 ) ) {
V_200 -> V_336 [ V_331 ] = NULL ;
F_197 ( V_217 , V_330 , V_331 ) ;
F_161 ( V_12 , V_217 ) ;
} else
F_201 ( V_200 , V_330 , V_331 ) ;
if ( V_345 )
F_206 ( & V_200 -> V_347 ) ;
}
static int F_207 ( struct V_311 * V_200 )
{
T_8 V_194 ;
unsigned int V_348 ;
unsigned int V_349 = V_200 -> V_349 ;
struct V_11 * V_12 = F_49 ( V_200 , struct V_11 , V_78 ) ;
V_348 = F_208 ( V_200 -> V_325 + V_200 -> V_81 ) ;
V_194 = V_200 -> V_350 * sizeof( * V_200 -> V_336 ) +
V_349 * sizeof( * V_200 -> V_316 ) +
V_200 -> V_325 * sizeof( * V_200 -> V_326 ) +
V_200 -> V_81 * sizeof( * V_200 -> V_326 ) +
V_348 * sizeof( long ) +
V_200 -> V_80 * sizeof( * V_200 -> V_83 ) +
V_200 -> V_81 * sizeof( * V_200 -> V_83 ) ;
V_200 -> V_336 = F_110 ( V_194 ) ;
if ( ! V_200 -> V_336 )
return - V_179 ;
V_200 -> V_316 = (union V_315 * ) & V_200 -> V_336 [ V_200 -> V_350 ] ;
V_200 -> V_326 = (struct V_351 * ) & V_200 -> V_316 [ V_349 ] ;
V_200 -> V_324 = ( unsigned long * ) & V_200 -> V_326 [ V_200 -> V_325 + V_200 -> V_81 ] ;
V_200 -> V_83 = (struct V_71 * ) & V_200 -> V_324 [ V_348 ] ;
F_209 ( & V_200 -> V_322 ) ;
F_209 ( & V_200 -> V_313 ) ;
V_200 -> V_328 = 0 ;
V_200 -> V_314 = NULL ;
V_200 -> V_319 = 0 ;
F_210 ( & V_200 -> V_347 , 0 ) ;
if ( V_349 ) {
while ( -- V_349 )
V_200 -> V_316 [ V_349 - 1 ] . V_318 = & V_200 -> V_316 [ V_349 ] ;
V_200 -> V_314 = V_200 -> V_316 ;
}
F_100 ( V_200 -> V_324 , V_200 -> V_325 + V_200 -> V_81 ) ;
if ( ! V_200 -> V_327 &&
( F_107 ( V_12 -> V_203 . V_211 ) || F_211 ( V_12 -> V_203 . V_211 ) ) )
F_190 ( 0 , V_200 -> V_324 ) ;
return 0 ;
}
int F_212 ( const struct V_1 * V_2 , unsigned int V_321 ,
T_11 V_352 , T_12 V_353 , T_12 V_225 ,
unsigned int V_354 )
{
unsigned int V_330 ;
struct V_216 * V_217 ;
struct V_11 * V_12 ;
struct V_355 * V_333 ;
int V_42 ;
V_217 = F_117 ( sizeof( * V_333 ) , V_178 ) ;
if ( ! V_217 )
return - V_179 ;
V_12 = F_213 ( V_2 ) ;
V_333 = (struct V_355 * ) F_121 ( V_217 , sizeof( * V_333 ) ) ;
F_198 ( V_333 , 0 ) ;
F_199 ( V_333 ) = F_122 ( F_200 ( V_356 , V_321 ) ) ;
V_333 -> V_357 = V_353 ;
V_333 -> V_358 = F_143 ( 0 ) ;
V_333 -> V_359 = V_352 ;
V_333 -> V_360 = F_122 ( 0 ) ;
V_330 = F_84 ( & V_12 -> V_15 , V_354 ) ;
V_333 -> V_361 = F_214 ( F_215 ( V_330 ) ) ;
V_333 -> V_362 = F_214 ( F_216 ( V_363 ) |
V_364 | F_217 ( V_354 ) ) ;
V_42 = F_164 ( V_12 , V_217 ) ;
return F_218 ( V_42 ) ;
}
int F_219 ( const struct V_1 * V_2 , unsigned int V_321 ,
const struct V_365 * V_352 , T_12 V_353 ,
unsigned int V_354 )
{
unsigned int V_330 ;
struct V_216 * V_217 ;
struct V_11 * V_12 ;
struct V_366 * V_333 ;
int V_42 ;
V_217 = F_117 ( sizeof( * V_333 ) , V_178 ) ;
if ( ! V_217 )
return - V_179 ;
V_12 = F_213 ( V_2 ) ;
V_333 = (struct V_366 * ) F_121 ( V_217 , sizeof( * V_333 ) ) ;
F_198 ( V_333 , 0 ) ;
F_199 ( V_333 ) = F_122 ( F_200 ( V_367 , V_321 ) ) ;
V_333 -> V_357 = V_353 ;
V_333 -> V_358 = F_143 ( 0 ) ;
V_333 -> V_368 = * ( T_5 * ) ( V_352 -> V_369 ) ;
V_333 -> V_370 = * ( T_5 * ) ( V_352 -> V_369 + 8 ) ;
V_333 -> V_371 = F_214 ( 0 ) ;
V_333 -> V_372 = F_214 ( 0 ) ;
V_330 = F_84 ( & V_12 -> V_15 , V_354 ) ;
V_333 -> V_361 = F_214 ( F_215 ( V_330 ) ) ;
V_333 -> V_362 = F_214 ( F_216 ( V_363 ) |
V_364 | F_217 ( V_354 ) ) ;
V_42 = F_164 ( V_12 , V_217 ) ;
return F_218 ( V_42 ) ;
}
int F_220 ( const struct V_1 * V_2 , unsigned int V_321 ,
unsigned int V_354 , bool V_373 )
{
struct V_216 * V_217 ;
struct V_11 * V_12 ;
struct V_374 * V_333 ;
int V_42 ;
V_12 = F_213 ( V_2 ) ;
V_217 = F_117 ( sizeof( * V_333 ) , V_178 ) ;
if ( ! V_217 )
return - V_179 ;
V_333 = (struct V_374 * ) F_121 ( V_217 , sizeof( * V_333 ) ) ;
F_198 ( V_333 , 0 ) ;
F_199 ( V_333 ) = F_122 ( F_200 ( V_375 , V_321 ) ) ;
V_333 -> V_376 = F_143 ( F_221 ( 0 ) | ( V_373 ? F_222 ( 1 ) :
F_222 ( 0 ) ) | F_223 ( V_354 ) ) ;
V_42 = F_164 ( V_12 , V_217 ) ;
return F_218 ( V_42 ) ;
}
unsigned int F_224 ( const unsigned short * V_377 , unsigned short V_50 ,
unsigned int * V_76 )
{
unsigned int V_18 = 0 ;
while ( V_18 < V_378 - 1 && V_377 [ V_18 + 1 ] <= V_50 )
++ V_18 ;
if ( V_76 )
* V_76 = V_18 ;
return V_377 [ V_18 ] ;
}
unsigned int F_225 ( const unsigned short * V_377 ,
unsigned short V_379 ,
unsigned short V_380 ,
unsigned short V_381 ,
unsigned int * V_382 )
{
unsigned short V_383 = V_379 + V_380 ;
unsigned short V_384 = V_381 - 1 ;
int V_385 , V_386 ;
for ( V_385 = 0 , V_386 = - 1 ; V_385 < V_378 ; V_385 ++ ) {
unsigned short V_387 = V_377 [ V_385 ] - V_379 ;
if ( ( V_387 & V_384 ) == 0 )
V_386 = V_385 ;
if ( V_385 + 1 < V_378 && V_377 [ V_385 + 1 ] > V_383 )
break;
}
if ( V_385 == V_378 )
V_385 -- ;
if ( V_386 >= 0 &&
V_385 - V_386 <= 1 )
V_385 = V_386 ;
if ( V_382 )
* V_382 = V_385 ;
return V_377 [ V_385 ] ;
}
unsigned int F_226 ( const struct V_1 * V_2 )
{
return F_85 ( V_2 ) -> V_59 ;
}
unsigned int F_227 ( const struct V_1 * V_2 , int V_388 )
{
struct V_11 * V_12 = F_213 ( V_2 ) ;
T_1 V_389 , V_390 , V_391 , V_392 ;
V_389 = F_64 ( V_12 , V_393 ) ;
V_390 = F_64 ( V_12 , V_394 ) ;
if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
V_391 = F_228 ( V_389 ) ;
V_392 = F_229 ( V_389 ) ;
} else {
V_391 = F_230 ( V_389 ) ;
V_392 = F_231 ( V_390 ) ;
}
return V_388 ? V_391 : V_392 ;
}
unsigned int F_232 ( const struct V_1 * V_2 )
{
return F_85 ( V_2 ) -> V_49 ;
}
unsigned int F_233 ( const struct V_1 * V_2 )
{
return F_85 ( V_2 ) -> V_30 ;
}
void F_234 ( struct V_395 * V_146 , struct V_396 * V_397 ,
struct V_396 * V_398 )
{
struct V_11 * V_12 = F_235 ( V_146 ) ;
F_236 ( & V_12 -> V_399 ) ;
F_237 ( V_12 , V_397 , V_398 ) ;
F_238 ( & V_12 -> V_399 ) ;
}
void F_239 ( struct V_1 * V_2 , unsigned int V_400 ,
const unsigned int * V_401 )
{
struct V_11 * V_12 = F_213 ( V_2 ) ;
F_66 ( V_12 , V_402 , V_400 ) ;
F_66 ( V_12 , V_403 , F_240 ( V_401 [ 0 ] ) |
F_241 ( V_401 [ 1 ] ) | F_242 ( V_401 [ 2 ] ) |
F_243 ( V_401 [ 3 ] ) ) ;
}
int F_244 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_213 ( V_2 ) ;
int V_42 ;
V_42 = F_245 ( V_12 , V_12 -> V_27 ,
0xe1000000 + V_404 , 0x20000000 ) ;
return V_42 ;
}
static int F_246 ( struct V_11 * V_12 , T_3 V_103 , T_3 * V_405 , T_3 * V_406 )
{
T_1 V_41 = F_64 ( V_12 , V_407 ) + 24 * V_103 + 8 ;
T_5 V_408 ;
int V_42 ;
F_236 ( & V_12 -> V_409 ) ;
V_42 = F_247 ( V_12 , 0 , V_410 , V_41 ,
sizeof( V_408 ) , ( T_11 * ) & V_408 ,
V_411 ) ;
F_238 ( & V_12 -> V_409 ) ;
if ( ! V_42 ) {
* V_406 = ( F_44 ( V_408 ) >> 25 ) & 0xffff ;
* V_405 = ( F_44 ( V_408 ) >> 9 ) & 0xffff ;
}
return V_42 ;
}
int F_248 ( struct V_1 * V_2 , T_3 V_103 , T_3 V_405 ,
T_3 V_194 )
{
struct V_11 * V_12 = F_213 ( V_2 ) ;
T_3 V_412 , V_413 ;
int V_42 ;
V_42 = F_246 ( V_12 , V_103 , & V_412 , & V_413 ) ;
if ( V_42 )
goto V_101;
if ( V_405 != V_412 ) {
T_3 V_296 ;
T_1 V_247 ;
if ( V_405 >= V_412 )
V_296 = V_405 - V_412 ;
else
V_296 = V_194 - V_412 + V_405 ;
if ( F_107 ( V_12 -> V_203 . V_211 ) )
V_247 = F_249 ( V_296 ) ;
else
V_247 = F_250 ( V_296 ) ;
F_251 () ;
F_66 ( V_12 , F_65 ( V_414 ) ,
F_252 ( V_103 ) | V_247 ) ;
}
V_101:
return V_42 ;
}
void F_253 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_213 ( V_2 ) ;
F_254 ( V_12 , V_415 , V_416 ,
V_416 ) ;
}
void F_255 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_213 ( V_2 ) ;
F_254 ( V_12 , V_415 , V_416 , 0 ) ;
}
int F_256 ( struct V_1 * V_2 , T_1 V_417 , T_11 * V_418 )
{
struct V_11 * V_12 ;
T_1 V_419 , V_420 , V_421 ;
T_1 V_422 , V_423 , V_424 , V_425 , V_194 ;
T_1 V_426 , V_427 , V_428 , V_429 ;
int V_42 ;
V_12 = F_213 ( V_2 ) ;
V_419 = ( ( V_417 >> 8 ) * 32 ) + V_12 -> V_430 . V_417 . V_431 ;
V_194 = F_64 ( V_12 , V_432 ) ;
V_422 = F_257 ( V_194 ) << 20 ;
V_194 = F_64 ( V_12 , V_433 ) ;
V_423 = F_258 ( V_194 ) << 20 ;
V_194 = F_64 ( V_12 , V_434 ) ;
V_424 = F_259 ( V_194 ) << 20 ;
V_426 = V_422 ;
V_427 = V_426 + V_423 ;
V_428 = V_427 + V_424 ;
if ( V_419 < V_426 ) {
V_420 = V_410 ;
V_421 = V_419 ;
} else if ( V_419 < V_427 ) {
V_420 = V_435 ;
V_421 = V_419 - V_426 ;
} else {
if ( V_419 < V_428 ) {
V_420 = V_436 ;
V_421 = V_419 - V_427 ;
} else if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
goto V_22;
} else {
V_194 = F_64 ( V_12 , V_437 ) ;
V_425 = F_260 ( V_194 ) << 20 ;
V_429 = V_428 + V_425 ;
if ( V_419 < V_429 ) {
V_420 = V_438 ;
V_421 = V_419 - V_428 ;
} else {
goto V_22;
}
}
}
F_236 ( & V_12 -> V_409 ) ;
V_42 = F_247 ( V_12 , 0 , V_420 , V_421 , 32 , V_418 , V_411 ) ;
F_238 ( & V_12 -> V_409 ) ;
return V_42 ;
V_22:
F_10 ( V_12 -> V_29 , L_34 ,
V_417 , V_419 ) ;
return - V_439 ;
}
T_2 F_261 ( struct V_1 * V_2 )
{
T_1 V_440 , V_441 ;
struct V_11 * V_12 ;
V_12 = F_213 ( V_2 ) ;
V_441 = F_64 ( V_12 , V_442 ) ;
V_440 = F_262 ( F_64 ( V_12 , V_443 ) ) ;
return ( ( T_2 ) V_440 << 32 ) | ( T_2 ) V_441 ;
}
int F_263 ( struct V_1 * V_2 ,
unsigned int V_103 ,
enum V_444 V_445 ,
T_2 * V_446 ,
unsigned int * V_447 )
{
return F_264 ( F_213 ( V_2 ) ,
V_103 ,
( V_445 == V_448
? V_449
: V_450 ) ,
V_446 ,
V_447 ) ;
}
static void F_265 ( struct V_451 * V_452 )
{
const struct V_453 * V_454 ;
const struct V_1 * V_183 = V_452 -> V_2 ;
if ( V_183 -> V_455 & V_456 )
V_183 = F_266 ( V_183 ) ;
V_454 = V_183 -> V_2 . V_454 ;
if ( V_454 && V_454 -> V_457 == & V_458 . V_457 )
F_267 ( F_268 ( V_454 ) , V_452 ) ;
}
static int F_269 ( struct V_459 * V_460 , unsigned long V_461 ,
void * V_116 )
{
switch ( V_461 ) {
case V_462 :
F_265 ( V_116 ) ;
break;
case V_463 :
default:
break;
}
return 0 ;
}
static void F_270 ( struct V_11 * V_12 , int V_464 )
{
T_1 V_389 , V_390 , V_391 , V_392 ;
do {
V_389 = F_64 ( V_12 , V_393 ) ;
V_390 = F_64 ( V_12 , V_394 ) ;
if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
V_391 = F_228 ( V_389 ) ;
V_392 = F_229 ( V_389 ) ;
} else {
V_391 = F_230 ( V_389 ) ;
V_392 = F_231 ( V_390 ) ;
}
if ( V_391 == 0 && V_392 == 0 )
break;
F_271 ( V_465 ) ;
F_272 ( F_273 ( V_464 ) ) ;
} while ( 1 );
}
static void F_274 ( struct V_105 * V_25 )
{
unsigned long V_52 ;
F_275 ( & V_25 -> V_466 , V_52 ) ;
V_25 -> V_467 = 1 ;
F_276 ( & V_25 -> V_466 , V_52 ) ;
}
static void F_277 ( struct V_11 * V_12 , struct V_105 * V_25 )
{
F_278 ( & V_25 -> V_466 ) ;
if ( V_25 -> V_468 ) {
F_251 () ;
F_66 ( V_12 , F_65 ( V_414 ) ,
F_252 ( V_25 -> V_26 ) | F_249 ( V_25 -> V_468 ) ) ;
V_25 -> V_468 = 0 ;
}
V_25 -> V_467 = 0 ;
F_279 ( & V_25 -> V_466 ) ;
}
static void F_280 ( struct V_11 * V_12 )
{
int V_18 ;
F_75 (&adap->sge, i)
F_274 ( & V_12 -> V_15 . V_16 [ V_18 ] . V_25 ) ;
F_70 (&adap->sge, i)
F_274 ( & V_12 -> V_15 . V_109 [ V_18 ] . V_25 ) ;
F_69 (adap, i)
F_274 ( & V_12 -> V_15 . V_210 [ V_18 ] . V_25 ) ;
}
static void F_281 ( struct V_11 * V_12 )
{
int V_18 ;
F_75 (&adap->sge, i)
F_277 ( V_12 , & V_12 -> V_15 . V_16 [ V_18 ] . V_25 ) ;
F_70 (&adap->sge, i)
F_277 ( V_12 , & V_12 -> V_15 . V_109 [ V_18 ] . V_25 ) ;
F_69 (adap, i)
F_277 ( V_12 , & V_12 -> V_15 . V_210 [ V_18 ] . V_25 ) ;
}
static void F_282 ( struct V_11 * V_12 , enum V_469 V_117 )
{
if ( V_12 -> V_138 [ V_470 ] )
V_136 [ V_470 ] . F_283 ( V_12 -> V_138 [ V_470 ] ,
V_117 ) ;
}
static void F_284 ( struct V_343 * V_344 )
{
struct V_11 * V_12 ;
V_12 = F_49 ( V_344 , struct V_11 , V_471 ) ;
F_270 ( V_12 , V_472 ) ;
F_281 ( V_12 ) ;
F_282 ( V_12 , V_473 ) ;
F_254 ( V_12 , V_474 ,
V_475 | V_476 ,
V_475 | V_476 ) ;
}
static void F_285 ( struct V_11 * V_12 , struct V_105 * V_25 )
{
T_3 V_412 , V_413 ;
int V_42 ;
F_278 ( & V_25 -> V_466 ) ;
V_42 = F_246 ( V_12 , ( T_3 ) V_25 -> V_26 , & V_412 , & V_413 ) ;
if ( V_42 )
goto V_101;
if ( V_25 -> V_477 != V_412 ) {
T_3 V_296 ;
T_1 V_247 ;
if ( V_25 -> V_477 >= V_412 )
V_296 = V_25 -> V_477 - V_412 ;
else
V_296 = V_25 -> V_194 - V_412 + V_25 -> V_477 ;
if ( F_107 ( V_12 -> V_203 . V_211 ) )
V_247 = F_249 ( V_296 ) ;
else
V_247 = F_250 ( V_296 ) ;
F_251 () ;
F_66 ( V_12 , F_65 ( V_414 ) ,
F_252 ( V_25 -> V_26 ) | V_247 ) ;
}
V_101:
V_25 -> V_467 = 0 ;
V_25 -> V_468 = 0 ;
F_279 ( & V_25 -> V_466 ) ;
if ( V_42 )
F_286 ( V_12 , L_35 ) ;
}
static void F_287 ( struct V_11 * V_12 )
{
int V_18 ;
F_75 (&adap->sge, i)
F_285 ( V_12 , & V_12 -> V_15 . V_16 [ V_18 ] . V_25 ) ;
F_70 (&adap->sge, i)
F_285 ( V_12 , & V_12 -> V_15 . V_109 [ V_18 ] . V_25 ) ;
F_69 (adap, i)
F_285 ( V_12 , & V_12 -> V_15 . V_210 [ V_18 ] . V_25 ) ;
}
static void F_288 ( struct V_343 * V_344 )
{
struct V_11 * V_12 ;
V_12 = F_49 ( V_344 , struct V_11 , V_478 ) ;
if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
F_270 ( V_12 , V_472 ) ;
F_282 ( V_12 , V_479 ) ;
F_270 ( V_12 , V_472 ) ;
F_287 ( V_12 ) ;
F_270 ( V_12 , V_472 ) ;
F_281 ( V_12 ) ;
F_282 ( V_12 , V_473 ) ;
} else {
T_1 V_480 = F_64 ( V_12 , 0x010ac ) ;
T_3 V_103 = ( V_480 >> 15 ) & 0x1ffff ;
T_3 V_481 = V_480 & 0x1fff ;
T_2 V_482 ;
unsigned int V_483 ;
int V_42 ;
V_42 = F_264 ( V_12 , V_103 , V_449 ,
& V_482 , & V_483 ) ;
if ( V_42 )
F_10 ( V_12 -> V_29 , L_36
L_37 , V_103 , V_481 ) ;
else
F_289 ( F_250 ( V_481 ) | F_252 ( V_483 ) ,
V_12 -> V_484 + V_482 + V_485 ) ;
F_254 ( V_12 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
F_254 ( V_12 , V_415 , V_486 , 0 ) ;
}
void F_290 ( struct V_11 * V_12 )
{
if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
F_280 ( V_12 ) ;
F_282 ( V_12 , V_487 ) ;
F_254 ( V_12 , V_474 ,
V_475 | V_476 , 0 ) ;
F_202 ( V_12 -> V_341 , & V_12 -> V_471 ) ;
}
}
void F_291 ( struct V_11 * V_12 )
{
if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
F_280 ( V_12 ) ;
F_282 ( V_12 , V_487 ) ;
}
F_202 ( V_12 -> V_341 , & V_12 -> V_478 ) ;
}
static void F_292 ( struct V_11 * V_12 , unsigned int V_137 )
{
void * V_488 ;
struct V_489 V_490 ;
unsigned short V_18 ;
V_490 . V_146 = V_12 -> V_146 ;
V_490 . V_491 = V_12 -> V_28 ;
V_490 . V_73 = V_12 -> V_73 ;
V_490 . V_78 = & V_12 -> V_78 ;
V_490 . V_492 = V_12 -> V_33 ;
V_490 . V_493 = & V_12 -> V_430 ;
V_490 . V_377 = V_12 -> V_203 . V_377 ;
if ( V_137 == V_470 ) {
V_490 . V_494 = V_12 -> V_15 . V_207 ;
V_490 . V_495 = V_12 -> V_15 . V_209 ;
V_490 . V_496 = V_12 -> V_15 . V_206 ;
V_490 . V_497 = V_12 -> V_15 . V_208 ;
} else if ( V_137 == V_498 ) {
V_490 . V_494 = V_12 -> V_15 . V_205 ;
V_490 . V_496 = V_12 -> V_15 . V_202 ;
}
V_490 . V_499 = V_12 -> V_15 . V_202 ;
V_490 . V_500 = V_12 -> V_203 . V_204 ;
V_490 . V_204 = V_12 -> V_203 . V_204 ;
V_490 . V_501 = V_12 -> V_203 . V_502 ;
V_490 . V_503 = V_12 -> V_203 . V_211 ;
V_490 . V_504 = F_293 ( F_64 ( V_12 , V_505 ) ) ;
V_490 . V_506 = 1000000000 / V_12 -> V_203 . V_507 . V_508 ;
V_490 . V_509 = 1 << V_12 -> V_203 . V_15 . V_510 ;
V_490 . V_511 = 1 << V_12 -> V_203 . V_15 . V_512 ;
V_490 . V_513 = V_12 -> V_203 . V_514 . V_515 ;
for ( V_18 = 0 ; V_18 < V_516 ; V_18 ++ )
V_490 . V_517 [ V_18 ] = V_18 ;
V_490 . V_518 = V_12 -> V_519 + F_65 ( V_188 ) ;
V_490 . V_520 = V_12 -> V_519 + F_65 ( V_414 ) ;
V_490 . V_521 = V_12 -> V_203 . V_521 ;
V_490 . V_522 = V_522 ;
V_490 . V_523 = V_12 -> V_15 . V_524 ;
V_490 . V_525 = V_12 -> V_15 . V_526 ;
V_490 . V_527 = V_12 -> V_15 . V_528 ;
V_490 . V_529 = V_12 -> V_52 & V_530 ;
V_490 . V_531 = V_12 -> V_203 . V_531 ;
V_490 . V_532 = V_12 -> V_203 . V_532 ;
V_490 . V_533 = V_12 -> V_203 . V_533 ;
V_488 = V_136 [ V_137 ] . F_294 ( & V_490 ) ;
if ( F_295 ( V_488 ) ) {
F_296 ( V_12 -> V_29 ,
L_38 ,
V_534 [ V_137 ] , F_297 ( V_488 ) ) ;
return;
}
V_12 -> V_138 [ V_137 ] = V_488 ;
if ( ! V_535 ) {
F_298 ( & V_536 ) ;
V_535 = true ;
}
if ( V_12 -> V_52 & V_187 )
V_136 [ V_137 ] . F_299 ( V_488 , V_537 ) ;
}
static void F_300 ( struct V_11 * V_12 )
{
unsigned int V_18 ;
F_236 ( & V_538 ) ;
F_301 ( & V_12 -> V_539 , & V_540 ) ;
F_238 ( & V_538 ) ;
F_302 ( & V_541 ) ;
F_303 ( & V_12 -> V_542 , & V_543 ) ;
for ( V_18 = 0 ; V_18 < V_544 ; V_18 ++ )
if ( V_136 [ V_18 ] . F_294 )
F_292 ( V_12 , V_18 ) ;
F_304 ( & V_541 ) ;
}
static void F_305 ( struct V_11 * V_12 )
{
unsigned int V_18 ;
F_302 ( & V_541 ) ;
F_306 ( & V_12 -> V_542 ) ;
for ( V_18 = 0 ; V_18 < V_544 ; V_18 ++ )
if ( V_12 -> V_138 [ V_18 ] ) {
V_136 [ V_18 ] . F_299 ( V_12 -> V_138 [ V_18 ] ,
V_545 ) ;
V_12 -> V_138 [ V_18 ] = NULL ;
}
if ( V_535 && F_307 ( & V_543 ) ) {
F_308 ( & V_536 ) ;
V_535 = false ;
}
F_304 ( & V_541 ) ;
F_236 ( & V_538 ) ;
F_309 ( & V_12 -> V_539 ) ;
F_238 ( & V_538 ) ;
}
static void F_310 ( struct V_11 * V_12 , enum V_546 V_547 )
{
unsigned int V_18 ;
F_302 ( & V_541 ) ;
for ( V_18 = 0 ; V_18 < V_544 ; V_18 ++ )
if ( V_12 -> V_138 [ V_18 ] )
V_136 [ V_18 ] . F_299 ( V_12 -> V_138 [ V_18 ] , V_547 ) ;
F_304 ( & V_541 ) ;
}
int F_311 ( enum V_548 type , const struct V_549 * V_6 )
{
int V_42 = 0 ;
struct V_11 * V_12 ;
if ( type >= V_544 )
return - V_439 ;
F_302 ( & V_541 ) ;
if ( V_136 [ type ] . F_294 ) {
V_42 = - V_550 ;
goto V_101;
}
V_136 [ type ] = * V_6 ;
F_312 (adap, &adapter_list, list_node)
F_292 ( V_12 , type ) ;
V_101: F_304 ( & V_541 ) ;
return V_42 ;
}
int F_313 ( enum V_548 type )
{
struct V_11 * V_12 ;
if ( type >= V_544 )
return - V_439 ;
F_302 ( & V_541 ) ;
F_312 (adap, &adapter_list, list_node)
V_12 -> V_138 [ type ] = NULL ;
V_136 [ type ] . F_294 = NULL ;
F_304 ( & V_541 ) ;
return 0 ;
}
static int F_314 ( struct V_459 * V_551 ,
unsigned long V_461 , void * V_116 )
{
struct V_552 * V_553 = V_116 ;
struct V_1 * V_554 = V_553 -> V_555 -> V_2 ;
const struct V_453 * V_454 = NULL ;
#if F_315 ( V_556 )
struct V_11 * V_12 ;
#endif
if ( V_554 -> V_455 & V_456 )
V_554 = F_266 ( V_554 ) ;
#if F_315 ( V_556 )
if ( V_554 -> V_52 & V_557 ) {
F_312 (adap, &adapter_list, list_node) {
switch ( V_461 ) {
case V_558 :
F_316 ( V_12 -> V_33 [ 0 ] ,
( const T_1 * ) V_553 , 1 ) ;
break;
case V_559 :
F_317 ( V_12 -> V_33 [ 0 ] ,
( const T_1 * ) V_553 , 1 ) ;
break;
default:
break;
}
}
return V_560 ;
}
#endif
if ( V_554 )
V_454 = V_554 -> V_2 . V_454 ;
if ( V_454 && V_454 -> V_457 == & V_458 . V_457 ) {
switch ( V_461 ) {
case V_558 :
F_316 ( V_554 , ( const T_1 * ) V_553 , 1 ) ;
break;
case V_559 :
F_317 ( V_554 , ( const T_1 * ) V_553 , 1 ) ;
break;
default:
break;
}
}
return V_560 ;
}
static void F_318 ( const struct V_11 * V_12 )
{
int V_18 ;
struct V_1 * V_2 ;
int V_42 ;
F_319 () ;
for ( V_18 = 0 ; V_18 < V_561 ; V_18 ++ ) {
V_2 = V_12 -> V_33 [ V_18 ] ;
V_42 = 0 ;
if ( V_2 )
V_42 = F_320 ( V_2 ) ;
if ( V_42 < 0 )
break;
}
F_321 () ;
}
static int F_322 ( struct V_11 * V_12 )
{
int V_22 ;
V_22 = F_99 ( V_12 ) ;
if ( V_22 )
goto V_101;
V_22 = F_82 ( V_12 ) ;
if ( V_22 )
goto V_562;
if ( V_12 -> V_52 & V_145 ) {
F_68 ( V_12 ) ;
V_22 = F_74 ( V_12 -> V_158 [ 0 ] . V_166 , F_63 , 0 ,
V_12 -> V_158 [ 0 ] . V_159 , V_12 ) ;
if ( V_22 )
goto V_563;
V_22 = F_73 ( V_12 ) ;
if ( V_22 ) {
F_76 ( V_12 -> V_158 [ 0 ] . V_166 , V_12 ) ;
goto V_563;
}
} else {
V_22 = F_74 ( V_12 -> V_146 -> V_148 , F_323 ( V_12 ) ,
( V_12 -> V_52 & V_147 ) ? 0 : V_564 ,
V_12 -> V_33 [ 0 ] -> V_20 , V_12 ) ;
if ( V_22 )
goto V_563;
}
F_92 ( V_12 ) ;
F_324 ( V_12 ) ;
F_325 ( V_12 ) ;
V_12 -> V_52 |= V_187 ;
F_310 ( V_12 , V_537 ) ;
#if F_315 ( V_565 )
F_318 ( V_12 ) ;
#endif
V_101:
return V_22 ;
V_563:
F_10 ( V_12 -> V_29 , L_39 , V_22 ) ;
V_562:
F_101 ( V_12 ) ;
goto V_101;
}
static void F_326 ( struct V_11 * V_11 )
{
F_327 ( & V_11 -> V_342 ) ;
F_327 ( & V_11 -> V_471 ) ;
F_327 ( & V_11 -> V_478 ) ;
V_11 -> V_340 = false ;
V_11 -> V_338 = NULL ;
F_328 ( V_11 ) ;
F_101 ( V_11 ) ;
V_11 -> V_52 &= ~ V_187 ;
}
static int F_329 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
F_16 ( V_2 ) ;
if ( ! ( V_11 -> V_52 & V_187 ) ) {
V_22 = F_322 ( V_11 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_28 ( V_2 ) ;
if ( ! V_22 )
F_330 ( V_2 ) ;
return V_22 ;
}
static int F_331 ( struct V_1 * V_2 )
{
struct V_5 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
F_332 ( V_2 ) ;
F_16 ( V_2 ) ;
return F_333 ( V_11 , V_11 -> V_28 , V_10 -> V_49 , false , false ) ;
}
static int F_334 ( struct V_71 * V_72 )
{
if ( V_72 -> V_566 )
return - V_567 ;
if ( V_72 -> V_89 )
return - V_550 ;
return 0 ;
}
static int F_335 ( struct V_11 * V_11 , unsigned int V_215 )
{
struct V_71 * V_72 ;
int V_42 ;
if ( V_215 >= V_11 -> V_78 . V_80 + V_11 -> V_78 . V_81 )
return - V_439 ;
V_72 = & V_11 -> V_78 . V_83 [ V_215 ] ;
V_42 = F_334 ( V_72 ) ;
if ( V_42 )
return V_42 ;
if ( V_72 -> V_90 )
return F_162 ( V_11 , V_215 ) ;
return 0 ;
}
int F_336 ( const struct V_1 * V_2 , unsigned int V_321 ,
T_11 V_352 , T_12 V_353 , T_12 V_225 ,
unsigned int V_354 , unsigned char V_33 , unsigned char V_249 )
{
int V_42 ;
struct V_71 * V_72 ;
struct V_11 * V_12 ;
int V_18 ;
T_4 * V_247 ;
V_12 = F_213 ( V_2 ) ;
V_321 -= V_12 -> V_78 . V_329 ;
V_321 += V_12 -> V_78 . V_80 ;
V_72 = & V_12 -> V_78 . V_83 [ V_321 ] ;
V_42 = F_334 ( V_72 ) ;
if ( V_42 )
return V_42 ;
if ( V_72 -> V_90 )
F_39 ( V_12 , V_72 ) ;
memset ( & V_72 -> V_221 , 0 , sizeof( struct V_568 ) ) ;
V_72 -> V_221 . V_247 . V_276 = F_337 ( V_353 ) ;
V_72 -> V_221 . V_249 . V_276 = ~ 0 ;
V_247 = ( T_4 * ) & V_352 ;
if ( ( V_247 [ 0 ] | V_247 [ 1 ] | V_247 [ 2 ] | V_247 [ 3 ] ) != 0 ) {
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_72 -> V_221 . V_247 . V_271 [ V_18 ] = V_247 [ V_18 ] ;
V_72 -> V_221 . V_249 . V_271 [ V_18 ] = ~ 0 ;
}
if ( V_12 -> V_203 . V_514 . V_515 & V_569 ) {
V_72 -> V_221 . V_247 . V_259 = V_33 ;
V_72 -> V_221 . V_249 . V_259 = V_249 ;
}
}
if ( V_12 -> V_203 . V_514 . V_515 & V_570 ) {
V_72 -> V_221 . V_247 . V_262 = V_571 ;
V_72 -> V_221 . V_249 . V_262 = ~ 0 ;
}
V_72 -> V_221 . V_236 = 1 ;
V_72 -> V_221 . V_232 = V_354 ;
V_72 -> V_566 = 1 ;
V_72 -> V_221 . V_234 = 1 ;
V_42 = F_116 ( V_12 , V_321 ) ;
if ( V_42 ) {
F_39 ( V_12 , V_72 ) ;
return V_42 ;
}
return 0 ;
}
int F_338 ( const struct V_1 * V_2 , unsigned int V_321 ,
unsigned int V_354 , bool V_373 )
{
int V_42 ;
struct V_71 * V_72 ;
struct V_11 * V_12 ;
V_12 = F_213 ( V_2 ) ;
V_321 -= V_12 -> V_78 . V_329 ;
V_321 += V_12 -> V_78 . V_80 ;
V_72 = & V_12 -> V_78 . V_83 [ V_321 ] ;
V_72 -> V_566 = 0 ;
V_42 = F_335 ( V_12 , V_321 ) ;
if ( V_42 )
return V_42 ;
return 0 ;
}
static struct V_572 * F_339 ( struct V_1 * V_2 ,
struct V_572 * V_573 )
{
struct V_574 V_139 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_11 * V_11 = V_6 -> V_11 ;
F_236 ( & V_11 -> V_399 ) ;
if ( ! F_340 ( V_2 ) ) {
F_238 ( & V_11 -> V_399 ) ;
return V_573 ;
}
F_341 ( V_11 , V_6 -> V_59 , & V_139 ) ;
F_238 ( & V_11 -> V_399 ) ;
V_573 -> V_575 = V_139 . V_576 ;
V_573 -> V_577 = V_139 . V_578 ;
V_573 -> V_579 = V_139 . V_580 ;
V_573 -> V_581 = V_139 . V_582 ;
V_573 -> V_583 = V_139 . V_584 ;
V_573 -> V_585 = V_139 . V_586 + V_139 . V_587 +
V_139 . V_588 ;
V_573 -> V_589 = 0 ;
V_573 -> V_590 = V_139 . V_591 ;
V_573 -> V_592 = V_139 . V_593 ;
V_573 -> V_594 = V_139 . V_595 + V_139 . V_596 +
V_139 . V_597 + V_139 . V_598 +
V_139 . V_599 + V_139 . V_600 +
V_139 . V_601 + V_139 . V_602 ;
V_573 -> V_603 = 0 ;
V_573 -> V_604 = 0 ;
V_573 -> V_605 = 0 ;
V_573 -> V_606 = 0 ;
V_573 -> V_607 = 0 ;
V_573 -> V_608 = 0 ;
V_573 -> V_609 = V_139 . V_610 ;
V_573 -> V_611 = V_139 . V_593 + V_139 . V_591 +
V_573 -> V_585 + V_139 . V_612 + V_573 -> V_594 ;
return V_573 ;
}
static int F_342 ( struct V_1 * V_2 , struct V_613 * V_333 , int V_117 )
{
unsigned int V_27 ;
int V_42 = 0 , V_614 , V_615 ;
struct V_5 * V_10 = F_4 ( V_2 ) ;
struct V_616 * V_116 = (struct V_616 * ) & V_333 -> V_617 ;
switch ( V_117 ) {
case V_618 :
if ( V_10 -> V_619 < 0 )
return - V_620 ;
V_116 -> V_621 = V_10 -> V_619 ;
break;
case V_622 :
case V_623 :
if ( F_343 ( V_116 -> V_621 ) ) {
V_614 = F_344 ( V_116 -> V_621 ) ;
V_615 = F_345 ( V_116 -> V_621 ) ;
} else if ( V_116 -> V_621 < 32 ) {
V_614 = V_116 -> V_621 ;
V_615 = 0 ;
V_116 -> V_624 &= 0x1f ;
} else
return - V_439 ;
V_27 = V_10 -> V_11 -> V_28 ;
if ( V_117 == V_622 )
V_42 = F_346 ( V_10 -> V_11 , V_27 , V_614 , V_615 ,
V_116 -> V_624 , & V_116 -> V_625 ) ;
else
V_42 = F_347 ( V_10 -> V_11 , V_27 , V_614 , V_615 ,
V_116 -> V_624 , V_116 -> V_626 ) ;
break;
default:
return - V_620 ;
}
return V_42 ;
}
static void F_348 ( struct V_1 * V_2 )
{
F_26 ( V_2 , - 1 , false ) ;
}
static int F_349 ( struct V_1 * V_2 , int V_627 )
{
int V_42 ;
struct V_5 * V_10 = F_4 ( V_2 ) ;
if ( V_627 < 81 || V_627 > V_628 )
return - V_439 ;
V_42 = F_27 ( V_10 -> V_11 , V_10 -> V_11 -> V_28 , V_10 -> V_49 , V_627 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_42 )
V_2 -> V_50 = V_627 ;
return V_42 ;
}
static int F_350 ( struct V_1 * V_2 , void * V_6 )
{
int V_42 ;
struct V_629 * V_41 = V_6 ;
struct V_5 * V_10 = F_4 ( V_2 ) ;
if ( ! F_351 ( V_41 -> V_630 ) )
return - V_631 ;
V_42 = F_29 ( V_10 -> V_11 , V_10 -> V_11 -> V_28 , V_10 -> V_49 ,
V_10 -> V_57 , V_41 -> V_630 , true , true ) ;
if ( V_42 < 0 )
return V_42 ;
memcpy ( V_2 -> V_58 , V_41 -> V_630 , V_2 -> V_632 ) ;
V_10 -> V_57 = V_42 ;
return 0 ;
}
static void F_352 ( struct V_1 * V_2 )
{
struct V_5 * V_10 = F_4 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_11 ;
if ( V_12 -> V_52 & V_145 ) {
int V_18 ;
struct V_176 * V_633 = & V_12 -> V_15 . V_169 [ V_10 -> V_17 ] ;
for ( V_18 = V_10 -> V_19 ; V_18 ; V_18 -- , V_633 ++ )
V_167 ( 0 , & V_633 -> V_135 ) ;
} else
F_323 ( V_12 ) ( 0 , V_12 ) ;
}
void F_353 ( struct V_11 * V_12 )
{
F_254 ( V_12 , V_634 , V_635 , 0 ) ;
F_91 ( V_12 ) ;
F_354 ( V_12 -> V_29 , L_40 ) ;
}
static T_1 F_355 ( struct V_11 * V_12 , int V_636 )
{
struct V_637 V_638 ;
T_1 V_247 ;
int V_42 ;
memset ( & V_638 , 0 , sizeof( V_638 ) ) ;
V_638 . V_639 =
F_122 ( F_356 ( V_640 ) |
V_641 |
V_642 |
F_357 ( V_643 ) ) ;
V_638 . V_644 = F_122 ( F_358 ( V_638 ) ) ;
V_638 . V_123 . V_645 . V_646 = F_359 ( 1 ) ;
V_638 . V_123 . V_645 . V_647 =
( V_648 | F_360 ( V_12 -> V_28 ) ) ;
V_638 . V_123 . V_645 . V_649 = V_636 ;
V_42 = F_361 ( V_12 , V_12 -> V_27 , & V_638 , sizeof( V_638 ) ,
& V_638 ) ;
if ( V_42 == 0 )
V_247 = F_37 ( V_638 . V_123 . V_645 . V_116 [ 0 ] ) ;
else
F_362 ( V_12 , V_636 , & V_247 ) ;
return V_247 ;
}
static void F_363 ( struct V_11 * V_12 )
{
T_1 V_650 , V_651 , V_652 , V_653 ;
if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
T_1 V_654 ;
V_654 = F_355 ( V_12 , V_655 ) ;
V_654 &= V_656 ;
V_12 -> V_657 = V_654 ;
V_650 = V_654 + V_658 ;
V_651 = V_654 + V_659 ;
V_652 = V_654 + V_660 ;
V_653 = V_661 ;
} else {
V_650 = V_658 ;
V_651 = V_659 ;
V_652 = V_662 ;
V_653 = V_663 ;
}
F_66 ( V_12 , F_364 ( V_664 , 0 ) ,
V_650 | F_365 ( 0 ) |
F_366 ( F_367 ( V_665 ) - 10 ) ) ;
F_66 ( V_12 , F_364 ( V_664 , 1 ) ,
V_651 | F_365 ( 0 ) |
F_366 ( F_367 ( V_666 ) - 10 ) ) ;
F_66 ( V_12 , F_364 ( V_664 , 2 ) ,
V_652 | F_365 ( 0 ) |
F_366 ( F_367 ( V_653 ) - 10 ) ) ;
F_64 ( V_12 , F_364 ( V_664 , 2 ) ) ;
}
static void F_368 ( struct V_11 * V_12 )
{
if ( V_12 -> V_430 . V_667 . V_194 ) {
T_1 V_431 ;
unsigned int V_668 ;
V_431 = F_355 ( V_12 , V_669 ) ;
V_431 &= V_656 ;
V_431 += F_369 ( V_12 -> V_146 , & V_12 -> V_430 ) ;
V_668 = F_370 ( V_12 -> V_430 . V_667 . V_194 ) >> 10 ;
F_66 ( V_12 ,
F_364 ( V_664 , 3 ) ,
V_431 | F_365 ( 1 ) | F_366 ( F_367 ( V_668 ) ) ) ;
F_66 ( V_12 ,
F_364 ( V_670 , 3 ) ,
V_12 -> V_430 . V_667 . V_431 ) ;
F_64 ( V_12 ,
F_364 ( V_670 , 3 ) ) ;
}
}
static int F_371 ( struct V_11 * V_12 , struct V_671 * V_672 )
{
T_1 V_149 ;
int V_42 ;
memset ( V_672 , 0 , sizeof( * V_672 ) ) ;
V_672 -> V_673 = F_122 ( F_356 ( V_674 ) |
V_641 | V_642 ) ;
V_672 -> V_675 = F_122 ( F_358 ( * V_672 ) ) ;
V_42 = F_361 ( V_12 , V_12 -> V_28 , V_672 , sizeof( * V_672 ) , V_672 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_672 -> V_676 & F_143 ( V_677 ) ) {
if ( ! V_678 )
V_672 -> V_676 ^= F_143 ( V_677 ) ;
else
V_672 -> V_676 = F_143 ( V_677 ) ;
} else if ( V_678 ) {
F_10 ( V_12 -> V_29 , L_41 ) ;
return V_42 ;
}
V_672 -> V_673 = F_122 ( F_356 ( V_674 ) |
V_641 | V_679 ) ;
V_42 = F_361 ( V_12 , V_12 -> V_28 , V_672 , sizeof( * V_672 ) , NULL ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_372 ( V_12 , V_12 -> V_28 ,
V_680 ,
V_681 |
V_682 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_373 ( V_12 , V_12 -> V_28 , V_12 -> V_28 , 0 , V_12 -> V_15 . V_196 , 64 ,
V_683 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_684 ,
V_684 ) ;
if ( V_42 < 0 )
return V_42 ;
F_374 ( V_12 ) ;
F_66 ( V_12 , V_685 , 0x64f8849 ) ;
F_66 ( V_12 , V_686 , F_240 ( V_687 - 12 ) ) ;
F_66 ( V_12 , V_688 , V_689 ) ;
V_149 = F_64 ( V_12 , V_690 ) ;
F_66 ( V_12 , V_690 , V_149 & ~ V_691 ) ;
V_12 -> V_203 . V_514 . V_692 = 0xE4 ;
F_66 ( V_12 , V_693 ,
F_375 ( V_12 -> V_203 . V_514 . V_692 ) ) ;
V_149 = 0x84218421 ;
F_376 ( V_12 , V_688 , V_690 ,
& V_149 , 1 , V_694 ) ;
F_376 ( V_12 , V_688 , V_690 ,
& V_149 , 1 , V_695 ) ;
F_376 ( V_12 , V_688 , V_690 ,
& V_149 , 1 , V_696 ) ;
#define F_377 16
if ( F_173 ( V_12 ) ) {
F_66 ( V_12 , V_697 ,
F_378 ( F_377 ) |
F_379 ( F_377 ) |
F_380 ( F_377 ) |
F_381 ( F_377 ) ) ;
F_66 ( V_12 , V_698 ,
F_378 ( F_377 ) |
F_379 ( F_377 ) |
F_380 ( F_377 ) |
F_381 ( F_377 ) ) ;
}
return F_382 ( V_12 , V_12 -> V_28 ) ;
}
static int F_383 ( struct V_11 * V_11 )
{
F_384 ( V_11 , V_699 , V_700 ) ;
if ( V_701 != 2 && V_701 != 0 ) {
F_10 ( & V_11 -> V_146 -> V_2 ,
L_42 ,
V_701 ) ;
V_701 = 2 ;
}
F_254 ( V_11 , V_634 ,
F_385 ( V_702 ) ,
F_385 ( V_701 ) ) ;
F_386 ( V_11 , V_689 ,
V_691 , 0 ) ;
return 0 ;
}
static int F_387 ( struct V_11 * V_11 , int V_703 )
{
struct V_671 V_704 ;
const struct V_705 * V_706 ;
unsigned long V_707 = 0 , V_708 = 0 ;
T_1 V_709 , V_710 , V_711 ;
int V_42 ;
int V_712 = 0 ;
char * V_713 , V_714 [ 256 ] ;
char * V_715 = NULL ;
if ( V_703 ) {
V_42 = F_388 ( V_11 , V_11 -> V_27 ,
V_716 | V_717 ) ;
if ( V_42 < 0 )
goto V_718;
}
switch ( F_389 ( V_11 -> V_203 . V_211 ) ) {
case V_719 :
V_713 = V_720 ;
break;
case V_721 :
V_713 = V_722 ;
break;
default:
F_10 ( V_11 -> V_29 , L_43 ,
V_11 -> V_146 -> V_453 ) ;
V_42 = - V_439 ;
goto V_718;
}
V_42 = F_390 ( & V_706 , V_713 , V_11 -> V_29 ) ;
if ( V_42 < 0 ) {
V_715 = L_44 ;
V_707 = V_723 ;
V_708 = F_391 ( V_11 ) ;
} else {
T_1 V_203 [ 7 ] , V_247 [ 7 ] ;
sprintf ( V_714 ,
L_45 , V_713 ) ;
V_715 = V_714 ;
if ( V_706 -> V_194 >= V_724 )
V_42 = - V_179 ;
else {
V_203 [ 0 ] = ( F_6 ( V_725 ) |
F_7 ( V_726 ) ) ;
V_42 = F_392 ( V_11 , V_11 -> V_27 ,
V_11 -> V_28 , 0 , 1 , V_203 , V_247 ) ;
if ( V_42 == 0 ) {
T_8 V_727 = V_706 -> V_194 & 0x3 ;
T_8 V_194 = V_706 -> V_194 & ~ 0x3 ;
T_11 * V_116 = ( T_11 * ) V_706 -> V_116 ;
V_707 = F_393 ( V_247 [ 0 ] ) ;
V_708 = F_394 ( V_247 [ 0 ] ) << 16 ;
F_236 ( & V_11 -> V_409 ) ;
V_42 = F_247 ( V_11 , 0 , V_707 , V_708 ,
V_194 , V_116 , V_728 ) ;
if ( V_42 == 0 && V_727 != 0 ) {
union {
T_11 V_729 ;
char V_730 [ 4 ] ;
} V_731 ;
int V_18 ;
V_731 . V_729 = V_116 [ V_194 >> 2 ] ;
for ( V_18 = V_727 ; V_18 < 4 ; V_18 ++ )
V_731 . V_730 [ V_18 ] = 0 ;
V_42 = F_247 ( V_11 , 0 , V_707 ,
V_708 + V_194 ,
4 , & V_731 . V_729 ,
V_728 ) ;
}
F_238 ( & V_11 -> V_409 ) ;
}
}
F_395 ( V_706 ) ;
if ( V_42 )
goto V_718;
}
memset ( & V_704 , 0 , sizeof( V_704 ) ) ;
V_704 . V_673 =
F_122 ( F_356 ( V_674 ) |
V_641 |
V_642 ) ;
V_704 . V_675 =
F_122 ( V_732 |
F_396 ( V_707 ) |
F_397 ( V_708 >> 16 ) |
F_358 ( V_704 ) ) ;
V_42 = F_361 ( V_11 , V_11 -> V_27 , & V_704 , sizeof( V_704 ) ,
& V_704 ) ;
if ( V_42 == - V_733 ) {
memset ( & V_704 , 0 , sizeof( V_704 ) ) ;
V_704 . V_673 =
F_122 ( F_356 ( V_674 ) |
V_641 |
V_642 ) ;
V_704 . V_675 = F_122 ( F_358 ( V_704 ) ) ;
V_42 = F_361 ( V_11 , V_11 -> V_27 , & V_704 ,
sizeof( V_704 ) , & V_704 ) ;
V_715 = L_46 ;
}
V_712 = 1 ;
if ( V_42 < 0 )
goto V_718;
V_709 = F_37 ( V_704 . V_709 ) ;
V_710 = F_37 ( V_704 . V_710 ) ;
V_711 = F_37 ( V_704 . V_711 ) ;
if ( V_710 != V_711 )
F_296 ( V_11 -> V_29 , L_47\
L_48 ,
V_710 , V_711 ) ;
V_704 . V_673 =
F_122 ( F_356 ( V_674 ) |
V_641 |
V_679 ) ;
V_704 . V_675 = F_122 ( F_358 ( V_704 ) ) ;
V_42 = F_361 ( V_11 , V_11 -> V_27 , & V_704 , sizeof( V_704 ) ,
NULL ) ;
if ( V_42 < 0 )
goto V_718;
V_42 = F_383 ( V_11 ) ;
if ( V_42 < 0 )
goto V_718;
V_42 = F_398 ( V_11 , V_11 -> V_27 ) ;
if ( V_42 < 0 )
goto V_718;
F_399 ( V_11 -> V_29 , L_49\
L_50 ,
V_715 , V_709 , V_711 ) ;
return 0 ;
V_718:
if ( V_712 && V_42 != - V_733 )
F_296 ( V_11 -> V_29 , L_51 ,
V_715 , - V_42 ) ;
return V_42 ;
}
static struct V_734 * F_400 ( int V_211 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_18 ( V_735 ) ; V_18 ++ ) {
if ( V_735 [ V_18 ] . V_211 == V_211 )
return & V_735 [ V_18 ] ;
}
return NULL ;
}
static int F_401 ( struct V_11 * V_12 )
{
int V_42 ;
T_1 V_149 , V_736 ;
enum V_737 V_63 ;
T_1 V_203 [ 7 ] , V_247 [ 7 ] ;
struct V_671 V_704 ;
int V_703 = 1 ;
V_42 = F_402 ( V_12 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_403 ( V_12 , V_12 -> V_27 , V_12 -> V_27 , V_738 , & V_63 ) ;
if ( V_42 < 0 ) {
F_10 ( V_12 -> V_29 , L_52 ,
V_42 ) ;
return V_42 ;
}
if ( V_42 == V_12 -> V_27 )
V_12 -> V_52 |= V_153 ;
F_404 ( V_12 , & V_12 -> V_203 . V_521 ) ;
F_405 ( V_12 , & V_12 -> V_203 . V_739 ) ;
if ( ( V_12 -> V_52 & V_153 ) && V_63 != V_740 ) {
struct V_734 * V_734 ;
struct V_741 * V_742 ;
const struct V_705 * V_743 ;
const T_4 * V_744 = NULL ;
unsigned int V_745 = 0 ;
V_734 = F_400 ( F_389 ( V_12 -> V_203 . V_211 ) ) ;
if ( V_734 == NULL ) {
F_10 ( V_12 -> V_29 ,
L_53 ,
F_389 ( V_12 -> V_203 . V_211 ) ) ;
return - V_439 ;
}
V_742 = F_110 ( sizeof( * V_742 ) ) ;
V_42 = F_390 ( & V_743 , V_734 -> V_746 ,
V_12 -> V_29 ) ;
if ( V_42 < 0 ) {
F_10 ( V_12 -> V_29 ,
L_54 ,
V_734 -> V_746 , V_42 ) ;
} else {
V_744 = V_743 -> V_116 ;
V_745 = V_743 -> V_194 ;
}
V_42 = F_406 ( V_12 , V_734 , V_744 , V_745 , V_742 ,
V_63 , & V_703 ) ;
F_395 ( V_743 ) ;
F_113 ( V_742 ) ;
if ( V_42 < 0 )
goto V_718;
}
V_42 = F_407 ( V_12 , & V_12 -> V_203 . V_507 ) ;
if ( V_42 < 0 )
goto V_718;
V_149 =
F_6 ( V_725 ) |
F_7 ( V_747 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 , & V_149 , & V_736 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_203 . V_204 = F_408 ( V_736 ) ;
V_12 -> V_203 . V_748 = V_736 ;
if ( V_63 == V_740 ) {
F_399 ( V_12 -> V_29 , L_55\
L_56 ,
V_12 -> V_52 & V_153 ? L_57 : L_58 ) ;
} else {
F_399 ( V_12 -> V_29 , L_59\
L_60 ) ;
V_203 [ 0 ] = ( F_6 ( V_725 ) |
F_7 ( V_726 ) ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 ,
V_203 , V_247 ) ;
if ( V_42 < 0 ) {
F_10 ( V_12 -> V_29 , L_61
L_62 ) ;
goto V_718;
}
V_42 = F_387 ( V_12 , V_703 ) ;
if ( V_42 == - V_733 ) {
F_10 ( V_12 -> V_29 , L_63
L_64 ) ;
goto V_718;
}
if ( V_42 < 0 ) {
F_10 ( V_12 -> V_29 , L_65
L_66 , - V_42 ) ;
goto V_718;
}
}
V_42 = F_374 ( V_12 ) ;
if ( V_42 < 0 )
goto V_718;
if ( F_409 ( V_12 -> V_146 -> V_453 ) )
V_12 -> V_203 . V_749 = 1 ;
#define F_410 ( T_13 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_411 ( T_13 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_203 [ 0 ] = F_411 ( V_750 ) ;
V_203 [ 1 ] = F_411 ( V_751 ) ;
V_203 [ 2 ] = F_411 ( V_752 ) ;
V_203 [ 3 ] = F_411 ( V_753 ) ;
V_203 [ 4 ] = F_411 ( V_754 ) ;
V_203 [ 5 ] = F_411 ( V_755 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 6 , V_203 , V_247 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_15 . V_107 = V_247 [ 0 ] ;
V_12 -> V_756 = V_247 [ 1 ] ;
V_12 -> V_757 = V_247 [ 2 ] ;
V_12 -> V_78 . V_79 = V_247 [ 3 ] ;
V_12 -> V_78 . V_80 = V_247 [ 4 ] - V_247 [ 3 ] + 1 ;
V_12 -> V_15 . V_181 = V_247 [ 5 ] ;
V_203 [ 0 ] = F_411 ( V_758 ) ;
V_203 [ 1 ] = F_411 ( V_759 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 2 , V_203 , V_247 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_15 . V_196 = V_247 [ 0 ] - V_12 -> V_15 . V_107 + 1 ;
V_12 -> V_15 . V_184 = V_247 [ 1 ] - V_12 -> V_15 . V_181 + 1 ;
V_12 -> V_15 . V_106 = F_412 ( V_12 -> V_15 . V_196 ,
sizeof( * V_12 -> V_15 . V_106 ) , V_178 ) ;
if ( ! V_12 -> V_15 . V_106 ) {
V_42 = - V_179 ;
goto V_718;
}
V_12 -> V_15 . V_182 = F_412 ( V_12 -> V_15 . V_184 ,
sizeof( * V_12 -> V_15 . V_182 ) , V_178 ) ;
if ( ! V_12 -> V_15 . V_182 ) {
V_42 = - V_179 ;
goto V_718;
}
V_12 -> V_15 . V_195 = F_412 ( F_208 ( V_12 -> V_15 . V_196 ) ,
sizeof( long ) , V_178 ) ;
if ( ! V_12 -> V_15 . V_195 ) {
V_42 = - V_179 ;
goto V_718;
}
V_12 -> V_15 . V_197 = F_412 ( F_208 ( V_12 -> V_15 . V_196 ) ,
sizeof( long ) , V_178 ) ;
if ( ! V_12 -> V_15 . V_197 ) {
V_42 = - V_179 ;
goto V_718;
}
V_203 [ 0 ] = F_411 ( V_760 ) ;
V_203 [ 1 ] = F_411 ( V_761 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 2 , V_203 , V_247 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_762 = V_247 [ 0 ] ;
V_12 -> V_763 = V_247 [ 1 ] ;
V_203 [ 0 ] = F_411 ( V_764 ) ;
V_203 [ 1 ] = F_411 ( V_765 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 2 , V_203 , V_247 ) ;
if ( ( V_247 [ 0 ] != V_247 [ 1 ] ) && ( V_42 >= 0 ) ) {
V_12 -> V_52 |= V_530 ;
V_12 -> V_78 . V_766 = V_247 [ 0 ] ;
V_12 -> V_78 . V_767 = V_247 [ 1 ] ;
}
V_203 [ 0 ] = F_411 ( V_768 ) ;
V_247 [ 0 ] = 1 ;
( void ) F_177 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 , V_203 , V_247 ) ;
if ( F_107 ( V_12 -> V_203 . V_211 ) ) {
V_12 -> V_203 . V_533 = false ;
} else {
V_203 [ 0 ] = F_410 ( V_769 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 ,
1 , V_203 , V_247 ) ;
V_12 -> V_203 . V_533 = ( V_42 == 0 && V_247 [ 0 ] != 0 ) ;
}
memset ( & V_704 , 0 , sizeof( V_704 ) ) ;
V_704 . V_673 = F_122 ( F_356 ( V_674 ) |
V_641 | V_642 ) ;
V_704 . V_675 = F_122 ( F_358 ( V_704 ) ) ;
V_42 = F_361 ( V_12 , V_12 -> V_27 , & V_704 , sizeof( V_704 ) ,
& V_704 ) ;
if ( V_42 < 0 )
goto V_718;
if ( V_704 . V_770 ) {
V_203 [ 0 ] = F_410 ( V_771 ) ;
V_203 [ 1 ] = F_411 ( V_772 ) ;
V_203 [ 2 ] = F_411 ( V_773 ) ;
V_203 [ 3 ] = F_411 ( V_774 ) ;
V_203 [ 4 ] = F_411 ( V_775 ) ;
V_203 [ 5 ] = F_410 ( V_776 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 6 ,
V_203 , V_247 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_78 . V_350 = V_247 [ 0 ] ;
V_12 -> V_78 . V_349 = F_413 ( V_12 -> V_78 . V_350 / 2 , V_777 ) ;
V_12 -> V_78 . V_327 = V_247 [ 1 ] ;
V_12 -> V_78 . V_325 = V_247 [ 2 ] - V_247 [ 1 ] + 1 ;
if ( V_12 -> V_52 & V_530 && ! F_414 ( V_12 ) ) {
V_12 -> V_78 . V_329 = V_12 -> V_78 . V_79 +
F_415 ( V_12 -> V_78 . V_80 , 3 ) ;
V_12 -> V_78 . V_81 = V_12 -> V_78 . V_80 -
F_415 ( V_12 -> V_78 . V_80 , 3 ) ;
V_12 -> V_78 . V_80 = V_12 -> V_78 . V_329 -
V_12 -> V_78 . V_79 ;
}
V_12 -> V_430 . V_778 . V_431 = V_247 [ 3 ] ;
V_12 -> V_430 . V_778 . V_194 = V_247 [ 4 ] - V_247 [ 3 ] + 1 ;
V_12 -> V_203 . V_502 = V_247 [ 5 ] ;
V_12 -> V_203 . V_295 = 1 ;
}
if ( V_704 . V_779 ) {
V_203 [ 0 ] = F_411 ( V_780 ) ;
V_203 [ 1 ] = F_411 ( V_781 ) ;
V_203 [ 2 ] = F_411 ( V_782 ) ;
V_203 [ 3 ] = F_411 ( V_783 ) ;
V_203 [ 4 ] = F_411 ( V_784 ) ;
V_203 [ 5 ] = F_411 ( V_785 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 6 ,
V_203 , V_247 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_430 . V_417 . V_431 = V_247 [ 0 ] ;
V_12 -> V_430 . V_417 . V_194 = V_247 [ 1 ] - V_247 [ 0 ] + 1 ;
V_12 -> V_430 . V_786 . V_431 = V_247 [ 2 ] ;
V_12 -> V_430 . V_786 . V_194 = V_247 [ 3 ] - V_247 [ 2 ] + 1 ;
V_12 -> V_430 . V_787 . V_431 = V_247 [ 4 ] ;
V_12 -> V_430 . V_787 . V_194 = V_247 [ 5 ] - V_247 [ 4 ] + 1 ;
V_203 [ 0 ] = F_411 ( V_788 ) ;
V_203 [ 1 ] = F_411 ( V_789 ) ;
V_203 [ 2 ] = F_411 ( V_790 ) ;
V_203 [ 3 ] = F_411 ( V_791 ) ;
V_203 [ 4 ] = F_411 ( V_792 ) ;
V_203 [ 5 ] = F_411 ( V_793 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 6 , V_203 ,
V_247 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_430 . V_794 . V_431 = V_247 [ 0 ] ;
V_12 -> V_430 . V_794 . V_194 = V_247 [ 1 ] - V_247 [ 0 ] + 1 ;
V_12 -> V_430 . V_795 . V_431 = V_247 [ 2 ] ;
V_12 -> V_430 . V_795 . V_194 = V_247 [ 3 ] - V_247 [ 2 ] + 1 ;
V_12 -> V_430 . V_667 . V_431 = V_247 [ 4 ] ;
V_12 -> V_430 . V_667 . V_194 = V_247 [ 5 ] - V_247 [ 4 ] + 1 ;
V_203 [ 0 ] = F_410 ( V_796 ) ;
V_203 [ 1 ] = F_410 ( V_797 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 2 , V_203 ,
V_247 ) ;
if ( V_42 < 0 ) {
V_12 -> V_203 . V_531 = 8 ;
V_12 -> V_203 . V_532 = 32 * V_12 -> V_78 . V_350 ;
V_42 = 0 ;
} else {
V_12 -> V_203 . V_531 = V_247 [ 0 ] ;
V_12 -> V_203 . V_532 = V_247 [ 1 ] ;
}
F_399 ( V_12 -> V_29 ,
L_67 ,
V_12 -> V_203 . V_531 ,
V_12 -> V_203 . V_532 ) ;
}
if ( V_704 . V_798 ) {
V_203 [ 0 ] = F_411 ( V_799 ) ;
V_203 [ 1 ] = F_411 ( V_800 ) ;
V_42 = F_392 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 2 ,
V_203 , V_247 ) ;
if ( V_42 < 0 )
goto V_718;
V_12 -> V_430 . V_801 . V_431 = V_247 [ 0 ] ;
V_12 -> V_430 . V_801 . V_194 = V_247 [ 1 ] - V_247 [ 0 ] + 1 ;
}
#undef F_411
#undef F_410
F_416 ( V_12 , V_12 -> V_203 . V_377 , NULL ) ;
if ( V_63 != V_740 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_378 ; V_18 ++ )
if ( V_12 -> V_203 . V_377 [ V_18 ] == 1492 ) {
V_12 -> V_203 . V_377 [ V_18 ] = 1488 ;
break;
}
F_417 ( V_12 , V_12 -> V_203 . V_377 , V_12 -> V_203 . V_802 ,
V_12 -> V_203 . V_803 ) ;
}
F_418 ( V_12 ) ;
F_419 ( V_12 ) ;
V_12 -> V_52 |= V_804 ;
return 0 ;
V_718:
F_81 ( V_12 -> V_15 . V_106 ) ;
F_81 ( V_12 -> V_15 . V_182 ) ;
F_81 ( V_12 -> V_15 . V_195 ) ;
F_81 ( V_12 -> V_15 . V_197 ) ;
if ( V_42 != - V_805 && V_42 != - V_806 )
F_420 ( V_12 , V_12 -> V_27 ) ;
return V_42 ;
}
static T_14 F_421 ( struct V_395 * V_146 ,
T_15 V_63 )
{
int V_18 ;
struct V_11 * V_12 = F_235 ( V_146 ) ;
if ( ! V_12 )
goto V_101;
F_422 () ;
V_12 -> V_52 &= ~ V_804 ;
F_310 ( V_12 , V_807 ) ;
F_236 ( & V_12 -> V_399 ) ;
F_69 (adap, i) {
struct V_1 * V_2 = V_12 -> V_33 [ V_18 ] ;
F_423 ( V_2 ) ;
F_16 ( V_2 ) ;
}
F_238 ( & V_12 -> V_399 ) ;
F_90 ( V_12 ) ;
if ( V_12 -> V_52 & V_187 )
F_326 ( V_12 ) ;
F_424 () ;
if ( ( V_12 -> V_52 & V_808 ) ) {
F_425 ( V_146 ) ;
V_12 -> V_52 &= ~ V_808 ;
}
V_101: return V_63 == V_809 ?
V_810 : V_811 ;
}
static T_14 F_426 ( struct V_395 * V_146 )
{
int V_18 , V_42 ;
struct V_671 V_672 ;
struct V_11 * V_12 = F_235 ( V_146 ) ;
if ( ! V_12 ) {
F_427 ( V_146 ) ;
F_428 ( V_146 ) ;
return V_812 ;
}
if ( ! ( V_12 -> V_52 & V_808 ) ) {
if ( F_429 ( V_146 ) ) {
F_10 ( & V_146 -> V_2 , L_68
L_69 ) ;
return V_810 ;
}
V_12 -> V_52 |= V_808 ;
}
F_430 ( V_146 ) ;
F_427 ( V_146 ) ;
F_428 ( V_146 ) ;
F_431 ( V_146 ) ;
if ( F_432 ( V_12 -> V_519 ) < 0 )
return V_810 ;
if ( F_403 ( V_12 , V_12 -> V_28 , V_12 -> V_28 , V_813 , NULL ) < 0 )
return V_810 ;
V_12 -> V_52 |= V_804 ;
if ( F_371 ( V_12 , & V_672 ) )
return V_810 ;
F_69 (adap, i) {
struct V_5 * V_6 = F_83 ( V_12 , V_18 ) ;
V_42 = F_433 ( V_12 , V_12 -> V_28 , V_6 -> V_59 , V_12 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_42 < 0 )
return V_810 ;
V_6 -> V_49 = V_42 ;
V_6 -> V_57 = - 1 ;
}
F_417 ( V_12 , V_12 -> V_203 . V_377 , V_12 -> V_203 . V_802 ,
V_12 -> V_203 . V_803 ) ;
F_363 ( V_12 ) ;
if ( F_322 ( V_12 ) )
return V_810 ;
return V_812 ;
}
static void F_434 ( struct V_395 * V_146 )
{
int V_18 ;
struct V_11 * V_12 = F_235 ( V_146 ) ;
if ( ! V_12 )
return;
F_422 () ;
F_69 (adap, i) {
struct V_1 * V_2 = V_12 -> V_33 [ V_18 ] ;
if ( F_12 ( V_2 ) ) {
F_28 ( V_2 ) ;
F_348 ( V_2 ) ;
}
F_435 ( V_2 ) ;
}
F_424 () ;
}
static inline bool F_436 ( const struct V_814 * V_815 )
{
return ( V_815 -> V_816 & V_817 ) != 0 ||
( V_815 -> V_816 & V_818 ) != 0 ;
}
static inline void F_437 ( struct V_11 * V_12 , struct V_91 * V_25 ,
unsigned int V_303 , unsigned int V_304 ,
unsigned int V_194 , unsigned int V_819 )
{
V_25 -> V_12 = V_12 ;
F_176 ( V_25 , V_303 , V_304 ) ;
V_25 -> V_820 = V_819 ;
V_25 -> V_194 = V_194 ;
}
static void F_438 ( struct V_11 * V_12 )
{
struct V_15 * V_4 = & V_12 -> V_15 ;
int V_18 , V_821 = 0 , V_822 = 0 ;
#ifndef F_14
int V_823 = 0 ;
#endif
int V_824 ;
F_69 (adap, i)
V_821 += F_436 ( & F_83 ( V_12 , V_18 ) -> V_7 ) ;
#ifdef F_14
if ( V_12 -> V_203 . V_204 * 8 > V_825 ) {
F_10 ( V_12 -> V_29 , L_70 ,
V_825 , V_12 -> V_203 . V_204 * 8 ) ;
F_439 ( 1 ) ;
}
F_69 (adap, i) {
struct V_5 * V_10 = F_83 ( V_12 , V_18 ) ;
V_10 -> V_17 = V_822 ;
V_10 -> V_19 = 8 ;
V_822 += V_10 -> V_19 ;
}
#else
if ( V_821 )
V_823 = ( V_825 - ( V_12 -> V_203 . V_204 - V_821 ) ) / V_821 ;
if ( V_823 > F_440 () )
V_823 = F_440 () ;
F_69 (adap, i) {
struct V_5 * V_10 = F_83 ( V_12 , V_18 ) ;
V_10 -> V_17 = V_822 ;
V_10 -> V_19 = F_436 ( & V_10 -> V_7 ) ? V_823 : 1 ;
V_822 += V_10 -> V_19 ;
}
#endif
V_4 -> V_826 = V_822 ;
V_4 -> V_827 = V_822 ;
if ( F_173 ( V_12 ) ) {
if ( V_821 ) {
V_18 = F_441 ( int , F_18 ( V_4 -> V_171 ) ,
F_442 () ) ;
V_4 -> V_202 = F_443 ( V_18 , V_12 -> V_203 . V_204 ) ;
} else
V_4 -> V_202 = V_12 -> V_203 . V_204 ;
V_4 -> V_206 = V_12 -> V_203 . V_204 ;
V_4 -> V_208 = F_441 ( int , V_828 , F_442 () ) ;
V_4 -> V_208 = ( V_4 -> V_208 / V_12 -> V_203 . V_204 ) *
V_12 -> V_203 . V_204 ;
V_4 -> V_208 = F_444 ( int , V_4 -> V_208 , V_12 -> V_203 . V_204 ) ;
}
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_169 ) ; V_18 ++ ) {
struct V_176 * V_649 = & V_4 -> V_169 [ V_18 ] ;
F_437 ( V_12 , & V_649 -> V_135 , 5 , 10 , 1024 , 64 ) ;
V_649 -> V_193 . V_194 = 72 ;
}
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_16 ) ; V_18 ++ )
V_4 -> V_16 [ V_18 ] . V_25 . V_194 = 1024 ;
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_210 ) ; V_18 ++ )
V_4 -> V_210 [ V_18 ] . V_25 . V_194 = 512 ;
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_109 ) ; V_18 ++ )
V_4 -> V_109 [ V_18 ] . V_25 . V_194 = 1024 ;
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_171 ) ; V_18 ++ ) {
struct V_133 * V_649 = & V_4 -> V_171 [ V_18 ] ;
F_437 ( V_12 , & V_649 -> V_135 , 5 , 1 , 1024 , 64 ) ;
V_649 -> V_135 . V_137 = V_498 ;
V_649 -> V_193 . V_194 = 72 ;
}
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_172 ) ; V_18 ++ ) {
struct V_133 * V_649 = & V_4 -> V_172 [ V_18 ] ;
F_437 ( V_12 , & V_649 -> V_135 , 5 , 1 , 511 , 64 ) ;
V_649 -> V_135 . V_137 = V_470 ;
V_649 -> V_193 . V_194 = 72 ;
}
V_824 = 64 + V_12 -> V_430 . V_795 . V_194 + V_12 -> V_78 . V_80 ;
if ( V_824 > V_829 ) {
F_286 ( V_12 , L_71 ) ;
V_824 = V_829 ;
}
for ( V_18 = 0 ; V_18 < F_18 ( V_4 -> V_173 ) ; V_18 ++ ) {
struct V_133 * V_649 = & V_4 -> V_173 [ V_18 ] ;
F_437 ( V_12 , & V_649 -> V_135 , 5 , 1 , V_824 , 64 ) ;
V_649 -> V_135 . V_137 = V_470 ;
}
F_437 ( V_12 , & V_4 -> V_168 , 0 , 1 , 1024 , 64 ) ;
F_437 ( V_12 , & V_4 -> V_198 , 0 , 1 , 2 * V_683 , 64 ) ;
}
static void F_445 ( struct V_11 * V_12 , int V_157 )
{
int V_18 ;
struct V_5 * V_10 ;
while ( V_157 < V_12 -> V_15 . V_826 )
F_69 (adap, i) {
V_10 = F_83 ( V_12 , V_18 ) ;
if ( V_10 -> V_19 > 1 ) {
V_10 -> V_19 -- ;
V_12 -> V_15 . V_826 -- ;
if ( V_12 -> V_15 . V_826 <= V_157 )
break;
}
}
V_157 = 0 ;
F_69 (adap, i) {
V_10 = F_83 ( V_12 , V_18 ) ;
V_10 -> V_17 = V_157 ;
V_157 += V_10 -> V_19 ;
}
}
static int F_446 ( struct V_11 * V_12 )
{
int V_830 = 0 ;
int V_18 , V_831 , V_832 , V_833 ;
struct V_15 * V_4 = & V_12 -> V_15 ;
unsigned int V_500 = V_12 -> V_203 . V_204 ;
struct V_834 * V_835 ;
V_835 = F_79 ( sizeof( * V_835 ) * ( V_683 + 1 ) ,
V_178 ) ;
if ( ! V_835 )
return - V_179 ;
for ( V_18 = 0 ; V_18 < V_683 + 1 ; ++ V_18 )
V_835 [ V_18 ] . V_836 = V_18 ;
V_831 = V_4 -> V_827 + V_837 ;
if ( F_173 ( V_12 ) ) {
V_831 += V_4 -> V_206 + V_4 -> V_208 + V_4 -> V_202 ;
V_830 = 3 * V_500 ;
}
#ifdef F_14
V_832 = 8 * V_12 -> V_203 . V_204 + V_837 + V_830 ;
#else
V_832 = V_12 -> V_203 . V_204 + V_837 + V_830 ;
#endif
V_833 = F_447 ( V_12 -> V_146 , V_835 , V_832 , V_831 ) ;
if ( V_833 < 0 ) {
F_399 ( V_12 -> V_29 , L_72
L_73 ) ;
F_81 ( V_835 ) ;
return V_833 ;
}
V_18 = V_833 - V_837 - V_830 ;
if ( V_18 < V_4 -> V_827 ) {
V_4 -> V_827 = V_18 ;
if ( V_18 < V_4 -> V_826 )
F_445 ( V_12 , V_18 ) ;
}
if ( F_173 ( V_12 ) ) {
if ( V_833 < V_831 ) {
V_4 -> V_206 = V_500 ;
V_4 -> V_208 = V_500 ;
}
V_18 = V_833 - V_837 - V_4 -> V_827 -
V_4 -> V_206 - V_4 -> V_208 ;
V_4 -> V_202 = ( V_18 / V_500 ) * V_500 ;
}
for ( V_18 = 0 ; V_18 < V_833 ; ++ V_18 )
V_12 -> V_158 [ V_18 ] . V_166 = V_835 [ V_18 ] . V_838 ;
F_81 ( V_835 ) ;
return 0 ;
}
static int F_448 ( struct V_11 * V_12 )
{
unsigned int V_18 , V_155 ;
F_69 (adap, i) {
struct V_5 * V_10 = F_83 ( V_12 , V_18 ) ;
V_10 -> V_175 = F_412 ( V_10 -> V_177 , sizeof( T_3 ) , V_178 ) ;
if ( ! V_10 -> V_175 )
return - V_179 ;
for ( V_155 = 0 ; V_155 < V_10 -> V_177 ; V_155 ++ )
V_10 -> V_175 [ V_155 ] = F_449 ( V_155 , V_10 -> V_19 ) ;
}
return 0 ;
}
static void F_450 ( const struct V_1 * V_2 )
{
char V_730 [ 80 ] ;
char * V_839 = V_730 ;
const char * V_840 = L_74 ;
const struct V_5 * V_10 = F_4 ( V_2 ) ;
const struct V_11 * V_12 = V_10 -> V_11 ;
if ( V_12 -> V_203 . V_841 . V_8 == V_842 )
V_840 = L_75 ;
else if ( V_12 -> V_203 . V_841 . V_8 == V_843 )
V_840 = L_76 ;
else if ( V_12 -> V_203 . V_841 . V_8 == V_844 )
V_840 = L_77 ;
if ( V_10 -> V_7 . V_816 & V_845 )
V_839 += sprintf ( V_839 , L_78 ) ;
if ( V_10 -> V_7 . V_816 & V_846 )
V_839 += sprintf ( V_839 , L_79 ) ;
if ( V_10 -> V_7 . V_816 & V_817 )
V_839 += sprintf ( V_839 , L_80 ) ;
if ( V_10 -> V_7 . V_816 & V_818 )
V_839 += sprintf ( V_839 , L_81 ) ;
if ( V_839 != V_730 )
-- V_839 ;
sprintf ( V_839 , L_82 , F_451 ( V_10 -> V_847 ) ) ;
F_3 ( V_2 , L_83 ,
V_12 -> V_203 . V_507 . V_848 ,
F_452 ( V_12 -> V_203 . V_211 ) , V_730 ,
F_173 ( V_12 ) ? L_84 : L_74 , V_12 -> V_203 . V_841 . V_849 , V_840 ,
( V_12 -> V_52 & V_145 ) ? L_85 :
( V_12 -> V_52 & V_147 ) ? L_86 : L_74 ) ;
F_3 ( V_2 , L_87 ,
V_12 -> V_203 . V_507 . V_850 , V_12 -> V_203 . V_507 . V_851 ) ;
}
static void F_453 ( struct V_395 * V_2 )
{
F_454 ( V_2 , V_852 , V_853 ) ;
}
static void F_455 ( struct V_11 * V_11 )
{
unsigned int V_18 ;
F_113 ( V_11 -> V_73 ) ;
F_113 ( V_11 -> V_78 . V_336 ) ;
F_81 ( V_11 -> V_15 . V_106 ) ;
F_81 ( V_11 -> V_15 . V_182 ) ;
F_81 ( V_11 -> V_15 . V_195 ) ;
F_81 ( V_11 -> V_15 . V_197 ) ;
F_60 ( V_11 ) ;
F_69 (adapter, i)
if ( V_11 -> V_33 [ V_18 ] ) {
F_81 ( F_83 ( V_11 , V_18 ) -> V_175 ) ;
F_456 ( V_11 -> V_33 [ V_18 ] ) ;
}
if ( V_11 -> V_52 & V_804 )
F_420 ( V_11 , V_11 -> V_28 ) ;
}
static int F_457 ( struct V_395 * V_146 , const struct V_854 * V_855 )
{
int V_856 , V_18 , V_22 , V_857 , V_858 , V_859 ;
struct V_5 * V_10 ;
bool V_860 = false ;
struct V_11 * V_11 = NULL ;
void T_16 * V_519 ;
F_458 ( V_861 L_88 , V_862 , V_863 ) ;
V_22 = F_459 ( V_146 , V_864 ) ;
if ( V_22 ) {
F_399 ( & V_146 -> V_2 , L_89 ) ;
return V_22 ;
}
V_22 = F_429 ( V_146 ) ;
if ( V_22 ) {
F_10 ( & V_146 -> V_2 , L_90 ) ;
goto V_865;
}
V_519 = F_460 ( V_146 , 0 ) ;
if ( ! V_519 ) {
F_10 ( & V_146 -> V_2 , L_91 ) ;
V_22 = - V_179 ;
goto V_866;
}
V_22 = F_432 ( V_519 ) ;
if ( V_22 < 0 )
goto V_867;
V_856 = F_461 ( F_462 ( V_519 + V_868 ) ) ;
if ( V_856 != V_855 -> V_869 ) {
F_463 ( V_519 ) ;
F_425 ( V_146 ) ;
F_428 ( V_146 ) ;
goto V_870;
}
if ( ! F_464 ( V_146 , F_465 ( 64 ) ) ) {
V_860 = true ;
V_22 = F_466 ( V_146 , F_465 ( 64 ) ) ;
if ( V_22 ) {
F_10 ( & V_146 -> V_2 , L_92
L_93 ) ;
goto V_867;
}
} else {
V_22 = F_464 ( V_146 , F_465 ( 32 ) ) ;
if ( V_22 ) {
F_10 ( & V_146 -> V_2 , L_94 ) ;
goto V_867;
}
}
F_467 ( V_146 ) ;
F_453 ( V_146 ) ;
F_430 ( V_146 ) ;
F_428 ( V_146 ) ;
V_11 = F_111 ( sizeof( * V_11 ) , V_178 ) ;
if ( ! V_11 ) {
V_22 = - V_179 ;
goto V_867;
}
V_11 -> V_341 = F_468 ( L_95 ) ;
if ( ! V_11 -> V_341 ) {
V_22 = - V_179 ;
goto V_871;
}
V_11 -> V_52 |= V_808 ;
V_11 -> V_519 = V_519 ;
V_11 -> V_146 = V_146 ;
V_11 -> V_29 = & V_146 -> V_2 ;
V_11 -> V_27 = V_856 ;
V_11 -> V_28 = V_856 ;
V_11 -> V_872 = V_873 ;
memset ( V_11 -> V_874 , 0xff , sizeof( V_11 -> V_874 ) ) ;
F_209 ( & V_11 -> V_399 ) ;
F_209 ( & V_11 -> V_337 ) ;
F_209 ( & V_11 -> V_409 ) ;
F_469 ( & V_11 -> V_342 , F_203 ) ;
F_469 ( & V_11 -> V_471 , F_284 ) ;
F_469 ( & V_11 -> V_478 , F_288 ) ;
V_22 = F_470 ( V_11 ) ;
if ( V_22 )
goto V_871;
if ( ! F_107 ( V_11 -> V_203 . V_211 ) ) {
V_857 = ( V_875 +
( V_876 - V_875 ) *
V_11 -> V_28 ) ;
V_858 = 1 << F_471 ( F_64 ( V_11 ,
V_877 ) >> V_857 ) ;
V_859 = V_699 / V_878 ;
if ( V_858 > V_859 ) {
F_10 ( & V_146 -> V_2 ,
L_96 ) ;
V_22 = - V_439 ;
goto V_871;
}
V_11 -> V_484 = F_472 ( F_473 ( V_146 , 2 ) ,
F_474 ( V_146 , 2 ) ) ;
if ( ! V_11 -> V_484 ) {
F_10 ( & V_146 -> V_2 , L_97 ) ;
V_22 = - V_179 ;
goto V_871;
}
}
F_363 ( V_11 ) ;
V_22 = F_401 ( V_11 ) ;
F_368 ( V_11 ) ;
if ( V_22 )
goto V_879;
F_69 (adapter, i) {
struct V_1 * V_183 ;
V_183 = F_475 ( sizeof( struct V_5 ) ,
V_825 ) ;
if ( ! V_183 ) {
V_22 = - V_179 ;
goto V_880;
}
F_476 ( V_183 , & V_146 -> V_2 ) ;
V_11 -> V_33 [ V_18 ] = V_183 ;
V_10 = F_4 ( V_183 ) ;
V_10 -> V_11 = V_11 ;
V_10 -> V_57 = - 1 ;
V_10 -> V_30 = V_18 ;
V_183 -> V_148 = V_146 -> V_148 ;
V_183 -> V_881 = V_882 | V_883 |
V_884 | V_885 |
V_886 | V_887 |
V_888 | V_56 ;
if ( V_860 )
V_183 -> V_881 |= V_889 ;
V_183 -> V_55 |= V_183 -> V_881 ;
V_183 -> V_890 = V_183 -> V_55 & V_891 ;
V_183 -> V_455 |= V_892 ;
V_183 -> V_893 = & V_894 ;
#ifdef F_14
V_183 -> V_895 = & V_896 ;
F_15 ( V_183 ) ;
#endif
F_477 ( V_183 ) ;
}
F_478 ( V_146 , V_11 ) ;
if ( V_11 -> V_52 & V_804 ) {
V_22 = F_479 ( V_11 , V_856 , V_856 , 0 ) ;
if ( V_22 )
goto V_880;
}
F_438 ( V_11 ) ;
V_11 -> V_73 = F_480 () ;
if ( ! V_11 -> V_73 ) {
F_296 ( & V_146 -> V_2 , L_98 ) ;
V_11 -> V_203 . V_295 = 0 ;
}
#if F_315 ( V_565 )
V_11 -> V_897 = F_481 ( V_11 -> V_762 ,
V_11 -> V_763 ) ;
if ( ! V_11 -> V_897 ) {
F_296 ( & V_146 -> V_2 ,
L_99 ) ;
V_11 -> V_203 . V_295 = 0 ;
}
#endif
if ( F_173 ( V_11 ) && F_207 ( & V_11 -> V_78 ) < 0 ) {
F_296 ( & V_146 -> V_2 , L_100
L_101 ) ;
V_11 -> V_203 . V_295 = 0 ;
}
if ( V_898 > 1 && F_446 ( V_11 ) == 0 )
V_11 -> V_52 |= V_145 ;
else if ( V_898 > 0 && F_482 ( V_146 ) == 0 )
V_11 -> V_52 |= V_147 ;
V_22 = F_448 ( V_11 ) ;
if ( V_22 )
goto V_880;
F_69 (adapter, i) {
V_10 = F_83 ( V_11 , V_18 ) ;
F_483 ( V_11 -> V_33 [ V_18 ] , V_10 -> V_19 ) ;
F_484 ( V_11 -> V_33 [ V_18 ] , V_10 -> V_19 ) ;
V_22 = F_485 ( V_11 -> V_33 [ V_18 ] ) ;
if ( V_22 )
break;
V_11 -> V_874 [ V_10 -> V_59 ] = V_18 ;
F_450 ( V_11 -> V_33 [ V_18 ] ) ;
}
if ( V_18 == 0 ) {
F_10 ( & V_146 -> V_2 , L_102 ) ;
goto V_880;
}
if ( V_22 ) {
F_296 ( & V_146 -> V_2 , L_103 , V_18 ) ;
V_22 = 0 ;
}
if ( V_899 ) {
V_11 -> V_310 = F_486 ( F_487 ( V_146 ) ,
V_899 ) ;
F_180 ( V_11 ) ;
}
V_146 -> V_900 = 1 ;
if ( F_173 ( V_11 ) )
F_300 ( V_11 ) ;
V_870:
#ifdef F_488
if ( V_856 < F_18 ( V_901 ) && V_901 [ V_856 ] > 0 )
if ( F_489 ( V_146 , V_901 [ V_856 ] ) == 0 )
F_399 ( & V_146 -> V_2 ,
L_104 ,
V_901 [ V_856 ] ) ;
#endif
return 0 ;
V_880:
F_455 ( V_11 ) ;
V_879:
if ( ! F_107 ( V_11 -> V_203 . V_211 ) )
F_463 ( V_11 -> V_484 ) ;
V_871:
if ( V_11 -> V_341 )
F_490 ( V_11 -> V_341 ) ;
F_81 ( V_11 ) ;
V_867:
F_463 ( V_519 ) ;
V_866:
F_491 ( V_146 ) ;
F_425 ( V_146 ) ;
V_865:
F_492 ( V_146 ) ;
return V_22 ;
}
static void F_493 ( struct V_395 * V_146 )
{
struct V_11 * V_11 = F_235 ( V_146 ) ;
#ifdef F_488
F_494 ( V_146 ) ;
#endif
if ( V_11 ) {
int V_18 ;
F_490 ( V_11 -> V_341 ) ;
if ( F_173 ( V_11 ) )
F_305 ( V_11 ) ;
F_90 ( V_11 ) ;
F_69 (adapter, i)
if ( V_11 -> V_33 [ V_18 ] -> V_902 == V_903 )
F_495 ( V_11 -> V_33 [ V_18 ] ) ;
F_496 ( V_11 -> V_310 ) ;
if ( V_11 -> V_78 . V_83 ) {
struct V_71 * V_72 = & V_11 -> V_78 . V_83 [ 0 ] ;
for ( V_18 = 0 ; V_18 < ( V_11 -> V_78 . V_80 +
V_11 -> V_78 . V_81 ) ; V_18 ++ , V_72 ++ )
if ( V_72 -> V_90 )
F_39 ( V_11 , V_72 ) ;
}
if ( V_11 -> V_52 & V_187 )
F_326 ( V_11 ) ;
F_455 ( V_11 ) ;
#if F_315 ( V_565 )
F_497 ( V_11 ) ;
#endif
F_463 ( V_11 -> V_519 ) ;
if ( ! F_107 ( V_11 -> V_203 . V_211 ) )
F_463 ( V_11 -> V_484 ) ;
F_491 ( V_146 ) ;
if ( ( V_11 -> V_52 & V_808 ) ) {
F_425 ( V_146 ) ;
V_11 -> V_52 &= ~ V_808 ;
}
F_492 ( V_146 ) ;
F_498 () ;
F_81 ( V_11 ) ;
} else
F_492 ( V_146 ) ;
}
static int T_17 F_499 ( void )
{
int V_42 ;
V_899 = F_486 ( V_864 , NULL ) ;
if ( ! V_899 )
F_500 ( L_105 ) ;
V_42 = F_501 ( & V_458 ) ;
if ( V_42 < 0 )
F_502 ( V_899 ) ;
#if F_315 ( V_565 )
if ( ! V_904 ) {
F_503 ( & V_905 ) ;
V_904 = true ;
}
#endif
return V_42 ;
}
static void T_18 F_504 ( void )
{
#if F_315 ( V_565 )
if ( V_904 ) {
F_505 ( & V_905 ) ;
V_904 = false ;
}
#endif
F_506 ( & V_458 ) ;
F_502 ( V_899 ) ;
}
