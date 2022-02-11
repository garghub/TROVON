static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
F_3 ( V_2 , L_1 ) ;
else {
static const char * V_3 [] = { L_2 , L_3 , L_4 , L_5 } ;
const char * V_4 ;
const struct V_5 * V_6 = F_4 ( V_2 ) ;
switch ( V_6 -> V_7 . V_8 ) {
case 100 :
V_4 = L_6 ;
break;
case 1000 :
V_4 = L_7 ;
break;
case 10000 :
V_4 = L_8 ;
break;
case 25000 :
V_4 = L_9 ;
break;
case 40000 :
V_4 = L_10 ;
break;
case 100000 :
V_4 = L_11 ;
break;
default:
F_5 ( L_12 ,
V_2 -> V_9 , V_6 -> V_7 . V_8 ) ;
return;
}
F_3 ( V_2 , L_13 , V_4 ,
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
L_14 ,
V_10 ? L_15 : L_16 , V_11 -> V_31 , V_19 , - V_22 ) ;
else
V_15 -> V_32 = V_21 ;
}
}
static int F_12 ( const struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! V_11 -> V_33 . V_34 )
return 0 ;
return ( ( V_11 -> V_33 . V_35 == V_36 ) ||
( V_11 -> V_33 . V_35 == V_37 ) ) ;
}
void F_13 ( struct V_12 * V_12 , int V_31 , int V_38 )
{
struct V_1 * V_2 = V_12 -> V_39 [ V_31 ] ;
if ( F_14 ( V_2 ) && V_38 != F_2 ( V_2 ) ) {
if ( V_38 )
F_15 ( V_2 ) ;
else {
#ifdef F_16
if ( F_12 ( V_2 ) ) {
F_17 ( V_2 ) ;
F_6 ( V_2 , false ) ;
}
#endif
F_18 ( V_2 ) ;
}
F_1 ( V_2 ) ;
}
}
void F_19 ( const struct V_12 * V_13 , int V_31 )
{
static const char * V_40 [] = {
NULL , L_17 , L_18 , L_19 , L_20 , L_21 , L_22
} ;
const struct V_1 * V_2 = V_13 -> V_39 [ V_31 ] ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_11 -> V_41 == V_42 )
F_3 ( V_2 , L_23 ) ;
else if ( V_11 -> V_41 < F_20 ( V_40 ) )
F_3 ( V_2 , L_24 , V_40 [ V_11 -> V_41 ] ) ;
else if ( V_11 -> V_41 == V_43 )
F_3 ( V_2 , L_25 ,
V_2 -> V_9 ) ;
else if ( V_11 -> V_41 == V_44 )
F_3 ( V_2 , L_26 ,
V_2 -> V_9 ) ;
else if ( V_11 -> V_41 == V_45 )
F_3 ( V_2 , L_27 , V_2 -> V_9 ) ;
else
F_3 ( V_2 , L_28 ,
V_2 -> V_9 , V_11 -> V_41 ) ;
}
static inline int F_21 ( struct V_5 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_12 ;
T_2 V_46 = 0 ;
bool V_47 = false ;
struct V_48 * V_49 ;
F_22 (entry, &adap->mac_hlist, list) {
V_47 |= F_23 ( V_49 -> V_50 ) ;
V_46 |= ( 1ULL << V_48 ( V_49 -> V_50 ) ) ;
}
return F_24 ( V_13 , V_13 -> V_27 , V_11 -> V_51 , V_47 ,
V_46 , false ) ;
}
static int F_25 ( struct V_1 * V_52 , const T_3 * V_53 )
{
struct V_5 * V_11 = F_4 ( V_52 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
bool free = false ;
bool V_47 = F_23 ( V_53 ) ;
const T_3 * V_57 [ 1 ] = { V_53 } ;
struct V_48 * V_58 ;
V_54 = F_26 ( V_13 , V_13 -> V_27 , V_11 -> V_51 , free , 1 , V_57 ,
NULL , V_47 ? & V_56 : & V_55 , false ) ;
if ( V_54 < 0 )
goto V_59;
if ( V_56 || V_55 ) {
V_58 = F_27 ( sizeof( * V_58 ) , V_60 ) ;
if ( ! V_58 )
return - V_61 ;
F_28 ( V_58 -> V_50 , V_53 ) ;
F_29 ( & V_58 -> V_62 , & V_13 -> V_63 ) ;
V_54 = F_21 ( V_11 ) ;
}
V_59:
return V_54 < 0 ? V_54 : 0 ;
}
static int F_30 ( struct V_1 * V_52 , const T_3 * V_53 )
{
struct V_5 * V_11 = F_4 ( V_52 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
const T_3 * V_57 [ 1 ] = { V_53 } ;
struct V_48 * V_49 , * V_64 ;
F_31 (entry, tmp, &adap->mac_hlist, list) {
if ( F_32 ( V_49 -> V_50 , V_53 ) ) {
F_33 ( & V_49 -> V_62 ) ;
F_34 ( V_49 ) ;
return F_21 ( V_11 ) ;
}
}
V_54 = F_35 ( V_13 , V_13 -> V_27 , V_11 -> V_51 , 1 , V_57 , false ) ;
return V_54 < 0 ? - V_65 : 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_66 , bool V_67 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_37 ( V_2 , F_25 , F_30 ) ;
F_38 ( V_2 , F_25 , F_30 ) ;
return F_39 ( V_12 , V_12 -> V_27 , V_11 -> V_51 , V_66 ,
( V_2 -> V_68 & V_69 ) ? 1 : 0 ,
( V_2 -> V_68 & V_70 ) ? 1 : 0 , 1 , - 1 ,
V_67 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_71 = V_11 -> V_12 -> V_28 ;
V_54 = F_39 ( V_11 -> V_12 , V_71 , V_11 -> V_51 , V_2 -> V_66 , - 1 , - 1 , - 1 ,
! ! ( V_2 -> V_72 & V_73 ) , true ) ;
if ( V_54 == 0 ) {
V_54 = F_41 ( V_11 -> V_12 , V_71 , V_11 -> V_51 ,
V_11 -> V_74 , V_2 -> V_75 , true ,
true ) ;
if ( V_54 >= 0 ) {
V_11 -> V_74 = V_54 ;
V_54 = 0 ;
}
}
if ( V_54 == 0 )
V_54 = F_42 ( V_11 -> V_12 , V_71 , V_11 -> V_76 ,
& V_11 -> V_7 ) ;
if ( V_54 == 0 ) {
F_43 () ;
V_54 = F_44 ( V_11 -> V_12 , V_71 , V_11 -> V_51 , true ,
true , V_77 ) ;
F_45 () ;
}
return V_54 ;
}
static void F_46 ( struct V_12 * V_13 , const struct V_78 * V_79 )
{
int V_39 = F_47 ( F_48 ( V_79 -> V_80 ) ) ;
struct V_1 * V_2 = V_13 -> V_39 [ V_13 -> V_81 [ V_39 ] ] ;
int V_82 = F_12 ( V_2 ) ;
int V_83 ;
F_49 ( V_13 , V_79 ) ;
V_83 = F_12 ( V_2 ) ;
if ( V_83 != V_82 )
F_6 ( V_2 , V_83 ) ;
}
static int F_50 ( struct V_84 * V_25 , const T_4 * V_85 ,
const struct V_86 * V_87 )
{
T_3 V_88 = ( ( const struct V_89 * ) V_85 ) -> V_88 ;
V_85 ++ ;
if ( F_51 ( V_88 == V_90 &&
( ( const struct V_91 * ) V_85 ) -> type == V_92 ) ) {
V_85 ++ ;
V_88 = ( ( const struct V_89 * ) V_85 ) -> V_88 ;
V_85 ++ ;
if ( V_88 != V_93 ) {
F_11 ( V_25 -> V_13 -> V_30 , L_29
, V_88 ) ;
goto V_59;
}
}
if ( F_52 ( V_88 == V_93 ) ) {
const struct V_94 * V_6 = ( void * ) V_85 ;
unsigned int V_95 = F_53 ( F_48 ( V_6 -> V_96 ) ) ;
struct V_97 * V_15 ;
V_15 = V_25 -> V_13 -> V_16 . V_98 [ V_95 - V_25 -> V_13 -> V_16 . V_99 ] ;
V_15 -> V_100 ++ ;
if ( V_15 -> V_101 == V_102 ) {
struct V_14 * V_103 ;
V_103 = F_54 ( V_15 , struct V_14 , V_25 ) ;
F_55 ( V_103 -> V_15 ) ;
} else {
struct V_104 * V_105 ;
V_105 = F_54 ( V_15 , struct V_104 , V_25 ) ;
F_56 ( & V_105 -> V_106 ) ;
}
} else if ( V_88 == V_107 || V_88 == V_90 ) {
const struct V_108 * V_6 = ( void * ) V_85 ;
#ifdef F_16
const struct V_78 * V_79 = ( const void * ) V_6 -> V_109 ;
unsigned int V_110 = F_57 ( F_48 ( V_79 -> V_80 ) ) ;
unsigned int V_111 =
F_58 ( F_48 ( V_79 -> V_112 ) ) ;
if ( V_110 == V_113 &&
V_111 == V_114 ) {
int V_39 = F_47 (
F_59 ( V_79 -> V_80 ) ) ;
struct V_1 * V_2 =
V_25 -> V_13 -> V_39 [ V_25 -> V_13 -> V_81 [ V_39 ] ] ;
int V_115 = ( ( V_79 -> V_116 . V_117 . V_118 &
V_119 )
? V_120
: V_121 ) ;
F_60 ( V_2 , V_115 ) ;
}
if ( V_110 == V_113 &&
V_111 == V_122 )
F_46 ( V_25 -> V_13 , V_79 ) ;
else
#endif
if ( V_6 -> type == 0 )
F_61 ( V_25 -> V_13 , V_6 -> V_109 ) ;
} else if ( V_88 == V_123 ) {
const struct V_124 * V_6 = ( void * ) V_85 ;
F_62 ( V_25 -> V_13 , V_6 ) ;
} else if ( V_88 == V_125 ) {
const struct V_126 * V_6 = ( void * ) V_85 ;
F_63 ( V_25 -> V_13 , V_6 ) ;
} else
F_11 ( V_25 -> V_13 -> V_30 ,
L_30 , V_88 ) ;
V_59:
return 0 ;
}
static void F_64 ( struct V_12 * V_12 )
{
if ( V_12 -> V_68 & V_127 ) {
F_65 ( V_12 -> V_128 ) ;
V_12 -> V_68 &= ~ V_127 ;
} else if ( V_12 -> V_68 & V_129 ) {
F_66 ( V_12 -> V_128 ) ;
V_12 -> V_68 &= ~ V_129 ;
}
}
static T_5 F_67 ( int V_130 , void * V_131 )
{
struct V_12 * V_13 = V_131 ;
T_1 V_132 = F_68 ( V_13 , F_69 ( V_133 ) ) ;
if ( V_132 & V_134 ) {
V_13 -> V_135 = 1 ;
F_70 ( V_13 , F_69 ( V_133 ) , V_132 ) ;
}
if ( V_13 -> V_68 & V_136 )
F_71 ( V_13 ) ;
return V_137 ;
}
static void F_72 ( struct V_12 * V_13 )
{
int V_19 , V_138 , V_139 = 2 , V_140 = sizeof( V_13 -> V_141 [ 0 ] . V_142 ) ;
snprintf ( V_13 -> V_141 [ 0 ] . V_142 , V_140 , L_31 , V_13 -> V_39 [ 0 ] -> V_9 ) ;
snprintf ( V_13 -> V_141 [ 1 ] . V_142 , V_140 , L_32 ,
V_13 -> V_39 [ 0 ] -> V_9 ) ;
F_73 (adap, j) {
struct V_1 * V_143 = V_13 -> V_39 [ V_138 ] ;
const struct V_5 * V_11 = F_4 ( V_143 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_139 ++ )
snprintf ( V_13 -> V_141 [ V_139 ] . V_142 , V_140 , L_33 ,
V_143 -> V_9 , V_19 ) ;
}
}
static int F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 , V_144 ;
int V_145 = 2 ;
V_22 = F_75 ( V_13 -> V_141 [ 1 ] . V_46 , V_146 , 0 ,
V_13 -> V_141 [ 1 ] . V_142 , & V_4 -> V_147 ) ;
if ( V_22 )
return V_22 ;
F_76 (s, ethqidx) {
V_22 = F_75 ( V_13 -> V_141 [ V_145 ] . V_46 ,
V_146 , 0 ,
V_13 -> V_141 [ V_145 ] . V_142 ,
& V_4 -> V_148 [ V_144 ] . V_149 ) ;
if ( V_22 )
goto V_150;
V_145 ++ ;
}
return 0 ;
V_150:
while ( -- V_144 >= 0 )
F_77 ( V_13 -> V_141 [ -- V_145 ] . V_46 ,
& V_4 -> V_148 [ V_144 ] . V_149 ) ;
F_77 ( V_13 -> V_141 [ 1 ] . V_46 , & V_4 -> V_147 ) ;
return V_22 ;
}
static void F_78 ( struct V_12 * V_13 )
{
int V_19 , V_145 = 2 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_77 ( V_13 -> V_141 [ 1 ] . V_46 , & V_4 -> V_147 ) ;
F_76 (s, i)
F_77 ( V_13 -> V_141 [ V_145 ++ ] . V_46 , & V_4 -> V_148 [ V_19 ] . V_149 ) ;
}
int F_79 ( const struct V_5 * V_11 , const T_6 * V_151 )
{
T_6 * V_152 ;
int V_19 , V_22 ;
struct V_12 * V_12 = V_11 -> V_12 ;
const struct V_153 * V_154 ;
V_154 = & V_12 -> V_16 . V_148 [ V_11 -> V_18 ] ;
V_152 = F_80 ( V_11 -> V_155 * sizeof( T_6 ) , V_156 ) ;
if ( ! V_152 )
return - V_61 ;
for ( V_19 = 0 ; V_19 < V_11 -> V_155 ; V_19 ++ , V_151 ++ )
V_152 [ V_19 ] = V_154 [ * V_151 ] . V_149 . V_157 ;
V_22 = F_81 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , 0 ,
V_11 -> V_155 , V_152 , V_11 -> V_155 ) ;
if ( ! V_22 )
V_22 = F_82 ( V_12 , V_12 -> V_27 , V_11 -> V_51 ,
V_158 |
V_159 |
V_160 |
V_161 |
V_162 ,
V_152 [ 0 ] ) ;
F_34 ( V_152 ) ;
return V_22 ;
}
static int F_83 ( struct V_12 * V_13 )
{
int V_19 , V_138 , V_22 ;
F_73 (adap, i) {
const struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
for ( V_138 = 0 ; V_138 < V_11 -> V_155 ; V_138 ++ )
V_11 -> V_152 [ V_138 ] = V_138 % V_11 -> V_20 ;
V_22 = F_79 ( V_11 , V_11 -> V_152 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static unsigned int F_85 ( const struct V_16 * V_6 , unsigned int V_95 )
{
V_95 -= V_6 -> V_163 ;
return F_86 ( V_6 -> V_164 [ V_95 ] -> V_52 ) -> V_76 ;
}
static void F_87 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_165 ; V_19 ++ ) {
struct V_84 * V_25 = V_13 -> V_16 . V_164 [ V_19 ] ;
if ( V_25 && V_25 -> V_166 )
F_88 ( & V_25 -> V_167 ) ;
}
}
static void F_89 ( struct V_12 * V_13 )
{
if ( V_13 -> V_68 & V_168 ) {
F_90 ( V_13 ) ;
if ( V_13 -> V_68 & V_127 ) {
F_78 ( V_13 ) ;
F_77 ( V_13 -> V_141 [ 0 ] . V_46 , V_13 ) ;
} else {
F_77 ( V_13 -> V_128 -> V_130 , V_13 ) ;
}
F_87 ( V_13 ) ;
}
}
static void F_91 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_165 ; V_19 ++ ) {
struct V_84 * V_25 = V_13 -> V_16 . V_164 [ V_19 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_166 )
F_92 ( & V_25 -> V_167 ) ;
F_70 ( V_13 , F_69 ( V_169 ) ,
F_93 ( V_25 -> V_170 ) |
F_94 ( V_25 -> V_26 ) ) ;
}
}
static int F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 = 0 ;
F_96 ( V_4 -> V_171 , V_4 -> V_172 ) ;
F_96 ( V_4 -> V_173 , V_4 -> V_172 ) ;
if ( V_13 -> V_68 & V_127 )
V_13 -> V_139 = 1 ;
else {
V_22 = F_97 ( V_13 , & V_4 -> V_174 , false , V_13 -> V_39 [ 0 ] , 0 ,
NULL , NULL , NULL , - 1 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_139 = - ( ( int ) V_4 -> V_174 . V_157 + 1 ) ;
}
V_22 = F_97 ( V_13 , & V_4 -> V_147 , true , V_13 -> V_39 [ 0 ] ,
V_13 -> V_139 , NULL , F_50 , NULL , - 1 ) ;
if ( V_22 )
F_98 ( V_13 ) ;
return V_22 ;
}
static int F_99 ( struct V_12 * V_13 )
{
int V_22 , V_19 , V_138 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
struct V_175 * V_176 = V_4 -> V_177 [ V_178 ] ;
unsigned int V_179 = 0 ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_153 * V_25 = & V_4 -> V_148 [ V_11 -> V_18 ] ;
struct V_14 * V_180 = & V_4 -> V_17 [ V_11 -> V_18 ] ;
for ( V_138 = 0 ; V_138 < V_11 -> V_20 ; V_138 ++ , V_25 ++ ) {
if ( V_13 -> V_139 > 0 )
V_13 -> V_139 ++ ;
V_22 = F_97 ( V_13 , & V_25 -> V_149 , false , V_2 ,
V_13 -> V_139 , & V_25 -> V_181 ,
V_182 ,
NULL ,
F_100 ( V_13 ,
V_11 -> V_76 ) ) ;
if ( V_22 )
goto V_183;
V_25 -> V_149 . V_184 = V_138 ;
memset ( & V_25 -> V_185 , 0 , sizeof( V_25 -> V_185 ) ) ;
}
for ( V_138 = 0 ; V_138 < V_11 -> V_20 ; V_138 ++ , V_180 ++ ) {
V_22 = F_101 ( V_13 , V_180 , V_2 ,
F_102 ( V_2 , V_138 ) ,
V_4 -> V_147 . V_26 ) ;
if ( V_22 )
goto V_183;
}
}
F_73 (adap, i) {
if ( V_176 )
V_179 = V_176 -> V_186 [ V_19 ] . V_149 . V_26 ;
V_22 = F_103 ( V_13 , & V_4 -> V_187 [ V_19 ] , V_13 -> V_39 [ V_19 ] ,
V_4 -> V_147 . V_26 , V_179 ) ;
if ( V_22 )
goto V_183;
}
F_70 ( V_13 , F_104 ( V_13 -> V_188 . V_189 ) ?
V_190 :
V_191 ,
F_105 ( F_86 ( V_13 -> V_39 [ 0 ] ) -> V_76 ) |
F_106 ( V_4 -> V_148 [ 0 ] . V_149 . V_157 ) ) ;
return 0 ;
V_183:
F_98 ( V_13 ) ;
return V_22 ;
}
static T_6 F_107 ( struct V_1 * V_2 , struct V_192 * V_193 ,
void * V_194 , T_7 V_195 )
{
int V_15 ;
#ifdef F_16
if ( F_12 ( V_2 ) ) {
T_6 V_196 ;
int V_22 ;
V_22 = F_108 ( V_193 , & V_196 ) ;
if ( F_51 ( V_22 ) ) {
if ( F_109 () )
F_110 ( V_2 ,
L_34 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_196 & V_197 ) >> V_198 ;
#ifdef F_111
if ( V_193 -> V_199 == F_112 ( V_200 ) )
V_15 = V_193 -> V_201 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_202 ) {
V_15 = ( F_113 ( V_193 )
? F_114 ( V_193 )
: F_115 () ) ;
while ( F_51 ( V_15 >= V_2 -> V_203 ) )
V_15 -= V_2 -> V_203 ;
return V_15 ;
}
return V_195 ( V_2 , V_193 ) % V_2 -> V_203 ;
}
static int F_116 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_204 , V_205 = 0 , V_206 = V_207 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_208 ) ; V_19 ++ ) {
V_204 = time - V_4 -> V_208 [ V_19 ] ;
if ( V_204 < 0 )
V_204 = - V_204 ;
if ( V_204 < V_206 ) {
V_206 = V_204 ;
V_205 = V_19 ;
}
}
return V_205 ;
}
static int F_117 ( const struct V_16 * V_4 , int V_209 )
{
int V_19 , V_204 , V_205 = 0 , V_206 = V_207 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_210 ) ; V_19 ++ ) {
V_204 = V_209 - V_4 -> V_210 [ V_19 ] ;
if ( V_204 < 0 )
V_204 = - V_204 ;
if ( V_204 < V_206 ) {
V_206 = V_204 ;
V_205 = V_19 ;
}
}
return V_205 ;
}
int F_118 ( struct V_84 * V_25 ,
unsigned int V_211 , unsigned int V_212 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_211 | V_212 ) == 0 )
V_212 = 1 ;
if ( V_212 ) {
int V_22 ;
T_1 V_132 , V_213 ;
V_213 = F_117 ( & V_13 -> V_16 , V_212 ) ;
if ( V_25 -> V_142 && V_25 -> V_214 != V_213 ) {
V_132 = F_7 ( V_23 ) |
F_8 (
V_215 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_119 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_132 , & V_213 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_214 = V_213 ;
}
V_211 = V_211 == 0 ? 6 : F_116 ( & V_13 -> V_16 , V_211 ) ;
V_25 -> V_170 = F_120 ( V_211 ) | F_121 ( V_212 > 0 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , T_8 V_72 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_8 V_216 = V_2 -> V_72 ^ V_72 ;
int V_22 ;
if ( ! ( V_216 & V_73 ) )
return 0 ;
V_22 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_72 & V_73 ) , true ) ;
if ( F_51 ( V_22 ) )
V_2 -> V_72 = V_72 ^ V_73 ;
return V_22 ;
}
static int F_123 ( struct V_12 * V_13 )
{
if ( F_124 ( V_13 -> V_217 ) )
return - 1 ;
#ifdef F_125
F_126 ( V_13 ) ;
#endif
return 0 ;
}
int F_127 ( struct V_218 * V_180 , void * V_109 )
{
int V_219 = - 1 ;
F_128 ( & V_180 -> V_220 ) ;
if ( V_180 -> V_221 ) {
union V_222 * V_6 = V_180 -> V_221 ;
V_219 = ( V_6 - V_180 -> V_223 ) + V_180 -> V_224 ;
V_180 -> V_221 = V_6 -> V_225 ;
V_6 -> V_109 = V_109 ;
V_180 -> V_226 ++ ;
}
F_129 ( & V_180 -> V_220 ) ;
return V_219 ;
}
void F_130 ( struct V_218 * V_180 , unsigned int V_219 )
{
union V_222 * V_6 = & V_180 -> V_223 [ V_219 - V_180 -> V_224 ] ;
F_128 ( & V_180 -> V_220 ) ;
V_6 -> V_225 = V_180 -> V_221 ;
V_180 -> V_221 = V_6 ;
V_180 -> V_226 -- ;
F_129 ( & V_180 -> V_220 ) ;
}
int F_131 ( struct V_218 * V_180 , int V_227 , void * V_109 )
{
int V_228 ;
F_128 ( & V_180 -> V_229 ) ;
if ( V_227 == V_230 ) {
V_228 = F_132 ( V_180 -> V_231 , V_180 -> V_232 ) ;
if ( V_228 < V_180 -> V_232 )
F_133 ( V_228 , V_180 -> V_231 ) ;
else
V_228 = - 1 ;
} else {
V_228 = F_134 ( V_180 -> V_231 , V_180 -> V_232 , 1 ) ;
if ( V_228 < 0 )
V_228 = - 1 ;
}
if ( V_228 >= 0 ) {
V_180 -> V_233 [ V_228 ] . V_109 = V_109 ;
V_228 += V_180 -> V_234 ;
if ( V_227 == V_230 )
V_180 -> V_235 ++ ;
else
V_180 -> V_235 += 2 ;
}
F_129 ( & V_180 -> V_229 ) ;
return V_228 ;
}
int F_135 ( struct V_218 * V_180 , int V_227 , void * V_109 )
{
int V_228 ;
F_128 ( & V_180 -> V_229 ) ;
if ( V_227 == V_230 ) {
V_228 = F_136 ( V_180 -> V_231 ,
V_180 -> V_232 + V_180 -> V_236 , V_180 -> V_232 ) ;
if ( V_228 < ( V_180 -> V_232 + V_180 -> V_236 ) )
F_133 ( V_228 , V_180 -> V_231 ) ;
else
V_228 = - 1 ;
} else {
V_228 = - 1 ;
}
if ( V_228 >= 0 ) {
V_180 -> V_233 [ V_228 ] . V_109 = V_109 ;
V_228 -= V_180 -> V_232 ;
V_228 += V_180 -> V_237 ;
V_180 -> V_238 ++ ;
}
F_129 ( & V_180 -> V_229 ) ;
return V_228 ;
}
void F_137 ( struct V_218 * V_180 , unsigned int V_228 , int V_227 )
{
if ( V_180 -> V_236 && ( V_228 >= V_180 -> V_237 ) ) {
V_228 -= V_180 -> V_237 ;
V_228 += V_180 -> V_232 ;
} else {
V_228 -= V_180 -> V_234 ;
}
F_128 ( & V_180 -> V_229 ) ;
if ( V_227 == V_230 )
F_138 ( V_228 , V_180 -> V_231 ) ;
else
F_139 ( V_180 -> V_231 , V_228 , 1 ) ;
V_180 -> V_233 [ V_228 ] . V_109 = NULL ;
if ( V_228 < V_180 -> V_232 ) {
if ( V_227 == V_230 )
V_180 -> V_235 -- ;
else
V_180 -> V_235 -= 2 ;
} else {
V_180 -> V_238 -- ;
}
F_129 ( & V_180 -> V_229 ) ;
}
static void F_140 ( struct V_192 * V_193 , unsigned int V_239 ,
unsigned int V_240 )
{
struct V_241 * V_242 ;
F_141 ( V_193 , V_243 , V_239 ) ;
V_242 = (struct V_241 * ) F_142 ( V_193 , sizeof( * V_242 ) ) ;
F_143 ( V_242 , V_240 ) ;
F_144 ( V_242 ) = F_145 ( F_146 ( V_244 , V_240 ) ) ;
}
static void F_147 ( struct V_218 * V_180 , unsigned int V_239 ,
unsigned int V_240 )
{
void * * V_6 = & V_180 -> V_245 [ V_240 ] ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_246 ) ;
F_128 ( & V_13 -> V_247 ) ;
* V_6 = V_13 -> V_248 ;
V_13 -> V_248 = ( void * * ) ( ( V_249 ) V_6 | V_239 ) ;
if ( ! V_13 -> V_250 ) {
V_13 -> V_250 = true ;
F_148 ( V_13 -> V_251 , & V_13 -> V_252 ) ;
}
F_129 ( & V_13 -> V_247 ) ;
}
static void F_149 ( struct V_253 * V_254 )
{
struct V_192 * V_193 ;
struct V_12 * V_13 ;
V_13 = F_54 ( V_254 , struct V_12 , V_252 ) ;
F_128 ( & V_13 -> V_247 ) ;
while ( V_13 -> V_248 ) {
void * * V_6 = V_13 -> V_248 ;
unsigned int V_239 = ( V_249 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_239 ;
V_13 -> V_248 = * V_6 ;
* V_6 = NULL ;
F_129 ( & V_13 -> V_247 ) ;
while ( ! ( V_193 = F_150 ( sizeof( struct V_241 ) ,
V_156 ) ) )
F_151 ( 1 ) ;
F_140 ( V_193 , V_239 , V_6 - V_13 -> V_246 . V_245 ) ;
F_152 ( V_13 , V_193 ) ;
F_128 ( & V_13 -> V_247 ) ;
}
V_13 -> V_250 = false ;
F_129 ( & V_13 -> V_247 ) ;
}
void F_153 ( struct V_218 * V_180 , unsigned int V_239 , unsigned int V_240 )
{
struct V_192 * V_193 ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_246 ) ;
F_154 ( V_240 >= V_180 -> V_255 ) ;
if ( V_180 -> V_245 [ V_240 ] ) {
V_180 -> V_245 [ V_240 ] = NULL ;
if ( V_180 -> V_256 && ( V_240 >= V_180 -> V_256 ) )
F_155 ( & V_180 -> V_257 ) ;
else
F_155 ( & V_180 -> V_258 ) ;
}
V_193 = F_150 ( sizeof( struct V_241 ) , V_60 ) ;
if ( F_52 ( V_193 ) ) {
F_140 ( V_193 , V_239 , V_240 ) ;
F_152 ( V_13 , V_193 ) ;
} else
F_147 ( V_180 , V_239 , V_240 ) ;
}
static int F_156 ( struct V_218 * V_180 )
{
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_246 ) ;
unsigned int V_259 = V_180 -> V_260 + V_180 -> V_236 ;
unsigned int V_261 = V_180 -> V_261 ;
unsigned int V_262 ;
unsigned int V_263 ;
T_9 V_264 ;
V_262 = F_157 ( V_180 -> V_232 + V_180 -> V_236 ) ;
V_263 = F_157 ( V_180 -> V_260 ) ;
V_264 = V_180 -> V_255 * sizeof( * V_180 -> V_245 ) +
V_261 * sizeof( * V_180 -> V_223 ) +
V_180 -> V_232 * sizeof( * V_180 -> V_233 ) +
V_180 -> V_236 * sizeof( * V_180 -> V_233 ) +
V_262 * sizeof( long ) +
V_259 * sizeof( * V_180 -> V_265 ) +
V_263 * sizeof( long ) ;
V_180 -> V_245 = F_158 ( V_264 , V_156 ) ;
if ( ! V_180 -> V_245 )
return - V_61 ;
V_180 -> V_223 = (union V_222 * ) & V_180 -> V_245 [ V_180 -> V_255 ] ;
V_180 -> V_233 = (struct V_266 * ) & V_180 -> V_223 [ V_261 ] ;
V_180 -> V_231 = ( unsigned long * ) & V_180 -> V_233 [ V_180 -> V_232 + V_180 -> V_236 ] ;
V_180 -> V_265 = (struct V_267 * ) & V_180 -> V_231 [ V_262 ] ;
V_180 -> V_268 = ( unsigned long * ) & V_180 -> V_265 [ V_259 ] ;
F_159 ( & V_180 -> V_229 ) ;
F_159 ( & V_180 -> V_220 ) ;
F_159 ( & V_180 -> V_269 ) ;
V_180 -> V_235 = 0 ;
V_180 -> V_238 = 0 ;
V_180 -> V_221 = NULL ;
V_180 -> V_226 = 0 ;
F_160 ( & V_180 -> V_258 , 0 ) ;
F_160 ( & V_180 -> V_257 , 0 ) ;
if ( V_261 ) {
while ( -- V_261 )
V_180 -> V_223 [ V_261 - 1 ] . V_225 = & V_180 -> V_223 [ V_261 ] ;
V_180 -> V_221 = V_180 -> V_223 ;
}
if ( F_161 ( V_13 ) ) {
F_96 ( V_180 -> V_231 , V_180 -> V_232 + V_180 -> V_236 ) ;
if ( ! V_180 -> V_234 &&
F_162 ( V_13 -> V_188 . V_189 ) <= V_270 )
F_133 ( 0 , V_180 -> V_231 ) ;
}
F_96 ( V_180 -> V_268 , V_180 -> V_260 ) ;
return 0 ;
}
int F_163 ( const struct V_1 * V_2 , unsigned int V_228 ,
T_10 V_271 , T_11 V_272 , T_11 V_273 ,
unsigned int V_274 )
{
unsigned int V_239 ;
struct V_192 * V_193 ;
struct V_12 * V_13 ;
struct V_275 * V_242 ;
int V_54 ;
V_193 = F_150 ( sizeof( * V_242 ) , V_156 ) ;
if ( ! V_193 )
return - V_61 ;
V_13 = F_164 ( V_2 ) ;
V_242 = (struct V_275 * ) F_142 ( V_193 , sizeof( * V_242 ) ) ;
F_143 ( V_242 , 0 ) ;
F_144 ( V_242 ) = F_145 ( F_146 ( V_276 , V_228 ) ) ;
V_242 -> V_277 = V_272 ;
V_242 -> V_278 = F_112 ( 0 ) ;
V_242 -> V_279 = V_271 ;
V_242 -> V_280 = F_145 ( 0 ) ;
V_239 = F_85 ( & V_13 -> V_16 , V_274 ) ;
V_242 -> V_281 = F_165 ( F_166 ( V_239 ) ) ;
V_242 -> V_282 = F_165 ( F_167 ( V_283 ) |
V_284 | F_168 ( V_274 ) ) ;
V_54 = F_169 ( V_13 , V_193 ) ;
return F_170 ( V_54 ) ;
}
int F_171 ( const struct V_1 * V_2 , unsigned int V_228 ,
const struct V_285 * V_271 , T_11 V_272 ,
unsigned int V_274 )
{
unsigned int V_239 ;
struct V_192 * V_193 ;
struct V_12 * V_13 ;
struct V_286 * V_242 ;
int V_54 ;
V_193 = F_150 ( sizeof( * V_242 ) , V_156 ) ;
if ( ! V_193 )
return - V_61 ;
V_13 = F_164 ( V_2 ) ;
V_242 = (struct V_286 * ) F_142 ( V_193 , sizeof( * V_242 ) ) ;
F_143 ( V_242 , 0 ) ;
F_144 ( V_242 ) = F_145 ( F_146 ( V_287 , V_228 ) ) ;
V_242 -> V_277 = V_272 ;
V_242 -> V_278 = F_112 ( 0 ) ;
V_242 -> V_288 = * ( T_4 * ) ( V_271 -> V_289 ) ;
V_242 -> V_290 = * ( T_4 * ) ( V_271 -> V_289 + 8 ) ;
V_242 -> V_291 = F_165 ( 0 ) ;
V_242 -> V_292 = F_165 ( 0 ) ;
V_239 = F_85 ( & V_13 -> V_16 , V_274 ) ;
V_242 -> V_281 = F_165 ( F_166 ( V_239 ) ) ;
V_242 -> V_282 = F_165 ( F_167 ( V_283 ) |
V_284 | F_168 ( V_274 ) ) ;
V_54 = F_169 ( V_13 , V_193 ) ;
return F_170 ( V_54 ) ;
}
int F_172 ( const struct V_1 * V_2 , unsigned int V_228 ,
unsigned int V_274 , bool V_293 )
{
struct V_192 * V_193 ;
struct V_12 * V_13 ;
struct V_294 * V_242 ;
int V_54 ;
V_13 = F_164 ( V_2 ) ;
V_193 = F_150 ( sizeof( * V_242 ) , V_156 ) ;
if ( ! V_193 )
return - V_61 ;
V_242 = (struct V_294 * ) F_142 ( V_193 , sizeof( * V_242 ) ) ;
F_143 ( V_242 , 0 ) ;
F_144 ( V_242 ) = F_145 ( F_146 ( V_295 , V_228 ) ) ;
V_242 -> V_296 = F_112 ( F_173 ( 0 ) | ( V_293 ? F_174 ( 1 ) :
F_174 ( 0 ) ) | F_175 ( V_274 ) ) ;
V_54 = F_169 ( V_13 , V_193 ) ;
return F_170 ( V_54 ) ;
}
unsigned int F_176 ( const unsigned short * V_297 , unsigned short V_66 ,
unsigned int * V_184 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_298 - 1 && V_297 [ V_19 + 1 ] <= V_66 )
++ V_19 ;
if ( V_184 )
* V_184 = V_19 ;
return V_297 [ V_19 ] ;
}
unsigned int F_177 ( const unsigned short * V_297 ,
unsigned short V_299 ,
unsigned short V_300 ,
unsigned short V_301 ,
unsigned int * V_302 )
{
unsigned short V_303 = V_299 + V_300 ;
unsigned short V_304 = V_301 - 1 ;
int V_305 , V_306 ;
for ( V_305 = 0 , V_306 = - 1 ; V_305 < V_298 ; V_305 ++ ) {
unsigned short V_307 = V_297 [ V_305 ] - V_299 ;
if ( ( V_307 & V_304 ) == 0 )
V_306 = V_305 ;
if ( V_305 + 1 < V_298 && V_297 [ V_305 + 1 ] > V_303 )
break;
}
if ( V_305 == V_298 )
V_305 -- ;
if ( V_306 >= 0 &&
V_305 - V_306 <= 1 )
V_305 = V_306 ;
if ( V_302 )
* V_302 = V_305 ;
return V_297 [ V_305 ] ;
}
unsigned int F_178 ( enum V_308 V_189 , unsigned int V_51 )
{
if ( F_162 ( V_189 ) <= V_270 )
return ( ( V_51 & 0x7f ) << 1 ) ;
else
return ( V_51 & 0x7f ) ;
}
unsigned int F_179 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_76 ;
}
unsigned int F_180 ( const struct V_1 * V_2 , int V_309 )
{
struct V_12 * V_13 = F_164 ( V_2 ) ;
T_1 V_310 , V_311 , V_312 , V_313 ;
V_310 = F_68 ( V_13 , V_314 ) ;
V_311 = F_68 ( V_13 , V_315 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
V_312 = F_181 ( V_310 ) ;
V_313 = F_182 ( V_310 ) ;
} else {
V_312 = F_183 ( V_310 ) ;
V_313 = F_184 ( V_311 ) ;
}
return V_309 ? V_312 : V_313 ;
}
unsigned int F_185 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_51 ;
}
unsigned int F_186 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_31 ;
}
void F_187 ( struct V_316 * V_128 , struct V_317 * V_318 ,
struct V_317 * V_319 )
{
struct V_12 * V_13 = F_188 ( V_128 ) ;
F_189 ( & V_13 -> V_320 ) ;
F_190 ( V_13 , V_318 , V_319 ) ;
F_191 ( & V_13 -> V_320 ) ;
}
void F_192 ( struct V_1 * V_2 , unsigned int V_321 ,
const unsigned int * V_322 )
{
struct V_12 * V_13 = F_164 ( V_2 ) ;
F_70 ( V_13 , V_323 , V_321 ) ;
F_70 ( V_13 , V_324 , F_193 ( V_322 [ 0 ] ) |
F_194 ( V_322 [ 1 ] ) | F_195 ( V_322 [ 2 ] ) |
F_196 ( V_322 [ 3 ] ) ) ;
}
int F_197 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_164 ( V_2 ) ;
return F_198 ( V_13 , V_13 -> V_27 ) ;
}
static int F_199 ( struct V_12 * V_13 , T_6 V_95 , T_6 * V_325 , T_6 * V_326 )
{
T_1 V_50 = F_68 ( V_13 , V_327 ) + 24 * V_95 + 8 ;
T_4 V_328 ;
int V_54 ;
F_189 ( & V_13 -> V_329 ) ;
V_54 = F_200 ( V_13 , 0 , V_330 , V_50 ,
sizeof( V_328 ) , ( T_10 * ) & V_328 ,
V_331 ) ;
F_191 ( & V_13 -> V_329 ) ;
if ( ! V_54 ) {
* V_326 = ( F_201 ( V_328 ) >> 25 ) & 0xffff ;
* V_325 = ( F_201 ( V_328 ) >> 9 ) & 0xffff ;
}
return V_54 ;
}
int F_202 ( struct V_1 * V_2 , T_6 V_95 , T_6 V_325 ,
T_6 V_264 )
{
struct V_12 * V_13 = F_164 ( V_2 ) ;
T_6 V_332 , V_333 ;
int V_54 ;
V_54 = F_199 ( V_13 , V_95 , & V_332 , & V_333 ) ;
if ( V_54 )
goto V_59;
if ( V_325 != V_332 ) {
T_6 V_204 ;
T_1 V_334 ;
if ( V_325 >= V_332 )
V_204 = V_325 - V_332 ;
else
V_204 = V_264 - V_332 + V_325 ;
if ( F_104 ( V_13 -> V_188 . V_189 ) )
V_334 = F_203 ( V_204 ) ;
else
V_334 = F_204 ( V_204 ) ;
F_205 () ;
F_70 ( V_13 , F_69 ( V_335 ) ,
F_206 ( V_95 ) | V_334 ) ;
}
V_59:
return V_54 ;
}
int F_207 ( struct V_1 * V_2 , T_1 V_336 , T_10 * V_337 )
{
struct V_12 * V_13 ;
T_1 V_338 , V_339 , V_340 ;
T_1 V_341 , V_342 , V_343 , V_344 , V_264 ;
T_1 V_345 , V_346 , V_347 , V_348 ;
int V_54 ;
V_13 = F_164 ( V_2 ) ;
V_338 = ( ( V_336 >> 8 ) * 32 ) + V_13 -> V_349 . V_336 . V_350 ;
V_264 = F_68 ( V_13 , V_351 ) ;
V_341 = F_208 ( V_264 ) << 20 ;
V_264 = F_68 ( V_13 , V_352 ) ;
V_342 = F_209 ( V_264 ) << 20 ;
V_264 = F_68 ( V_13 , V_353 ) ;
V_343 = F_210 ( V_264 ) << 20 ;
V_345 = V_341 ;
V_346 = V_345 + V_342 ;
V_347 = V_346 + V_343 ;
if ( V_338 < V_345 ) {
V_339 = V_330 ;
V_340 = V_338 ;
} else if ( V_338 < V_346 ) {
V_339 = V_354 ;
V_340 = V_338 - V_345 ;
} else {
if ( V_338 < V_347 ) {
V_339 = V_355 ;
V_340 = V_338 - V_346 ;
} else if ( F_211 ( V_13 -> V_188 . V_189 ) ) {
V_264 = F_68 ( V_13 , V_356 ) ;
V_344 = F_212 ( V_264 ) << 20 ;
V_348 = V_347 + V_344 ;
if ( V_338 < V_348 ) {
V_339 = V_357 ;
V_340 = V_338 - V_347 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_189 ( & V_13 -> V_329 ) ;
V_54 = F_200 ( V_13 , 0 , V_339 , V_340 , 32 , V_337 , V_331 ) ;
F_191 ( & V_13 -> V_329 ) ;
return V_54 ;
V_22:
F_11 ( V_13 -> V_30 , L_35 ,
V_336 , V_338 ) ;
return - V_65 ;
}
T_2 F_213 ( struct V_1 * V_2 )
{
T_1 V_358 , V_359 ;
struct V_12 * V_13 ;
V_13 = F_164 ( V_2 ) ;
V_359 = F_68 ( V_13 , V_360 ) ;
V_358 = F_214 ( F_68 ( V_13 , V_361 ) ) ;
return ( ( T_2 ) V_358 << 32 ) | ( T_2 ) V_359 ;
}
int F_215 ( struct V_1 * V_2 ,
unsigned int V_95 ,
enum V_362 V_363 ,
int V_364 ,
T_2 * V_365 ,
unsigned int * V_366 )
{
return F_216 ( F_164 ( V_2 ) ,
V_95 ,
( V_363 == V_367
? V_368
: V_369 ) ,
V_364 ,
V_365 ,
V_366 ) ;
}
static void F_217 ( struct V_370 * V_371 )
{
const struct V_372 * V_373 ;
const struct V_1 * V_52 = V_371 -> V_2 ;
if ( F_218 ( V_52 ) )
V_52 = F_219 ( V_52 ) ;
V_373 = V_52 -> V_2 . V_373 ;
if ( V_373 && V_373 -> V_374 == & V_375 . V_374 )
F_220 ( F_221 ( V_373 ) , V_371 ) ;
}
static int F_222 ( struct V_376 * V_377 , unsigned long V_378 ,
void * V_109 )
{
switch ( V_378 ) {
case V_379 :
F_217 ( V_109 ) ;
break;
case V_380 :
default:
break;
}
return 0 ;
}
static void F_223 ( struct V_12 * V_13 , int V_381 )
{
T_1 V_310 , V_311 , V_312 , V_313 ;
do {
V_310 = F_68 ( V_13 , V_314 ) ;
V_311 = F_68 ( V_13 , V_315 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
V_312 = F_181 ( V_310 ) ;
V_313 = F_182 ( V_310 ) ;
} else {
V_312 = F_183 ( V_310 ) ;
V_313 = F_184 ( V_311 ) ;
}
if ( V_312 == 0 && V_313 == 0 )
break;
F_224 ( V_382 ) ;
F_225 ( F_226 ( V_381 ) ) ;
} while ( 1 );
}
static void F_227 ( struct V_97 * V_25 )
{
unsigned long V_68 ;
F_228 ( & V_25 -> V_383 , V_68 ) ;
V_25 -> V_384 = 1 ;
F_229 ( & V_25 -> V_383 , V_68 ) ;
}
static void F_230 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
F_231 ( & V_25 -> V_383 ) ;
if ( V_25 -> V_385 ) {
F_205 () ;
F_70 ( V_13 , F_69 ( V_335 ) ,
F_206 ( V_25 -> V_26 ) | F_203 ( V_25 -> V_385 ) ) ;
V_25 -> V_385 = 0 ;
}
V_25 -> V_384 = 0 ;
F_232 ( & V_25 -> V_383 ) ;
}
static void F_233 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_227 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_161 ( V_13 ) ) {
struct V_386 * V_387 =
V_13 -> V_16 . V_388 [ V_389 ] ;
if ( V_387 ) {
F_234 (&adap->sge, i) {
struct V_104 * V_15 = & V_387 -> V_390 [ V_19 ] ;
F_227 ( & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_227 ( & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_235 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_230 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_161 ( V_13 ) ) {
struct V_386 * V_387 =
V_13 -> V_16 . V_388 [ V_389 ] ;
if ( V_387 ) {
F_234 (&adap->sge, i) {
struct V_104 * V_15 = & V_387 -> V_390 [ V_19 ] ;
F_230 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_230 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_236 ( struct V_12 * V_13 , enum V_391 V_110 )
{
enum V_392 type = V_178 ;
if ( V_13 -> V_393 && V_13 -> V_393 [ type ] . V_394 )
V_13 -> V_393 [ type ] . F_237 ( V_13 -> V_393 [ type ] . V_394 , V_110 ) ;
}
static void F_238 ( struct V_253 * V_254 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_254 , struct V_12 , V_395 ) ;
F_223 ( V_13 , V_396 ) ;
F_235 ( V_13 ) ;
F_236 ( V_13 , V_397 ) ;
if ( F_162 ( V_13 -> V_188 . V_189 ) <= V_270 )
F_239 ( V_13 , V_398 ,
V_399 | V_400 ,
V_399 | V_400 ) ;
else
F_239 ( V_13 , V_398 ,
V_400 , V_400 ) ;
}
static void F_240 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
T_6 V_332 , V_333 ;
int V_54 ;
F_231 ( & V_25 -> V_383 ) ;
V_54 = F_199 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_332 , & V_333 ) ;
if ( V_54 )
goto V_59;
if ( V_25 -> V_401 != V_332 ) {
T_6 V_204 ;
T_1 V_334 ;
if ( V_25 -> V_401 >= V_332 )
V_204 = V_25 -> V_401 - V_332 ;
else
V_204 = V_25 -> V_264 - V_332 + V_25 -> V_401 ;
if ( F_104 ( V_13 -> V_188 . V_189 ) )
V_334 = F_203 ( V_204 ) ;
else
V_334 = F_204 ( V_204 ) ;
F_205 () ;
F_70 ( V_13 , F_69 ( V_335 ) ,
F_206 ( V_25 -> V_26 ) | V_334 ) ;
}
V_59:
V_25 -> V_384 = 0 ;
V_25 -> V_385 = 0 ;
F_232 ( & V_25 -> V_383 ) ;
if ( V_54 )
F_241 ( V_13 , L_36 ) ;
}
static void F_242 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_240 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_161 ( V_13 ) ) {
struct V_386 * V_387 =
V_13 -> V_16 . V_388 [ V_389 ] ;
if ( V_387 ) {
F_234 (&adap->sge, i) {
struct V_104 * V_15 = & V_387 -> V_390 [ V_19 ] ;
F_240 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_240 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_243 ( struct V_253 * V_254 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_254 , struct V_12 , V_402 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
F_223 ( V_13 , V_396 ) ;
F_236 ( V_13 , V_403 ) ;
F_223 ( V_13 , V_396 ) ;
F_242 ( V_13 ) ;
F_223 ( V_13 , V_396 ) ;
F_235 ( V_13 ) ;
F_236 ( V_13 , V_397 ) ;
} else if ( F_211 ( V_13 -> V_188 . V_189 ) ) {
T_1 V_404 = F_68 ( V_13 , 0x010ac ) ;
T_6 V_95 = ( V_404 >> 15 ) & 0x1ffff ;
T_6 V_405 = V_404 & 0x1fff ;
T_2 V_406 ;
unsigned int V_407 ;
int V_54 ;
V_54 = F_216 ( V_13 , V_95 , V_368 ,
0 , & V_406 , & V_407 ) ;
if ( V_54 )
F_11 ( V_13 -> V_30 , L_37
L_38 , V_95 , V_405 ) ;
else
F_244 ( F_204 ( V_405 ) | F_206 ( V_407 ) ,
V_13 -> V_408 + V_406 + V_409 ) ;
F_239 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_162 ( V_13 -> V_188 . V_189 ) <= V_270 )
F_239 ( V_13 , V_410 , V_411 , 0 ) ;
}
void F_245 ( struct V_12 * V_13 )
{
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
F_233 ( V_13 ) ;
F_236 ( V_13 , V_412 ) ;
F_239 ( V_13 , V_398 ,
V_399 | V_400 , 0 ) ;
F_148 ( V_13 -> V_251 , & V_13 -> V_395 ) ;
}
}
void F_246 ( struct V_12 * V_13 )
{
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
F_233 ( V_13 ) ;
F_236 ( V_13 , V_412 ) ;
}
F_148 ( V_13 -> V_251 , & V_13 -> V_402 ) ;
}
void F_247 ( void )
{
if ( ! V_413 ) {
F_248 ( & V_414 ) ;
V_413 = true ;
}
}
static void F_249 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_250 ( & V_415 ) ;
F_33 ( & V_13 -> V_416 ) ;
for ( V_19 = 0 ; V_19 < V_417 ; V_19 ++ )
if ( V_13 -> V_393 && V_13 -> V_393 [ V_19 ] . V_394 ) {
V_13 -> V_393 [ V_19 ] . F_251 ( V_13 -> V_393 [ V_19 ] . V_394 ,
V_418 ) ;
V_13 -> V_393 [ V_19 ] . V_394 = NULL ;
}
if ( V_413 && F_252 ( & V_419 ) ) {
F_253 ( & V_414 ) ;
V_413 = false ;
}
F_254 ( & V_415 ) ;
}
static void F_255 ( struct V_12 * V_13 , enum V_420 V_421 )
{
unsigned int V_19 ;
F_250 ( & V_415 ) ;
for ( V_19 = 0 ; V_19 < V_417 ; V_19 ++ )
if ( V_13 -> V_393 && V_13 -> V_393 [ V_19 ] . V_394 )
V_13 -> V_393 [ V_19 ] . F_251 ( V_13 -> V_393 [ V_19 ] . V_394 ,
V_421 ) ;
F_254 ( & V_415 ) ;
}
static int F_256 ( struct V_376 * V_422 ,
unsigned long V_378 , void * V_109 )
{
struct V_423 * V_424 = V_109 ;
struct V_1 * V_425 = V_424 -> V_426 -> V_2 ;
const struct V_372 * V_373 = NULL ;
#if F_257 ( V_427 )
struct V_12 * V_13 ;
#endif
if ( F_218 ( V_425 ) )
V_425 = F_219 ( V_425 ) ;
#if F_257 ( V_427 )
if ( V_425 -> V_68 & V_428 ) {
F_22 (adap, &adapter_list, list_node) {
switch ( V_378 ) {
case V_429 :
F_258 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_424 , 1 ) ;
break;
case V_430 :
F_259 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_424 , 1 ) ;
break;
default:
break;
}
}
return V_431 ;
}
#endif
if ( V_425 )
V_373 = V_425 -> V_2 . V_373 ;
if ( V_373 && V_373 -> V_374 == & V_375 . V_374 ) {
switch ( V_378 ) {
case V_429 :
F_258 ( V_425 , ( const T_1 * ) V_424 , 1 ) ;
break;
case V_430 :
F_259 ( V_425 , ( const T_1 * ) V_424 , 1 ) ;
break;
default:
break;
}
}
return V_431 ;
}
static void F_260 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_54 ;
F_261 () ;
for ( V_19 = 0 ; V_19 < V_432 ; V_19 ++ ) {
V_2 = V_13 -> V_39 [ V_19 ] ;
V_54 = 0 ;
if ( V_2 )
V_54 = F_262 ( V_2 ) ;
if ( V_54 < 0 )
break;
}
F_263 () ;
}
static int F_264 ( struct V_12 * V_13 )
{
int V_22 ;
F_250 ( & V_415 ) ;
V_22 = F_99 ( V_13 ) ;
if ( V_22 )
goto V_433;
V_22 = F_83 ( V_13 ) ;
if ( V_22 )
goto V_434;
if ( V_13 -> V_68 & V_127 ) {
F_72 ( V_13 ) ;
V_22 = F_75 ( V_13 -> V_141 [ 0 ] . V_46 , F_67 , 0 ,
V_13 -> V_141 [ 0 ] . V_142 , V_13 ) ;
if ( V_22 )
goto V_435;
V_22 = F_74 ( V_13 ) ;
if ( V_22 ) {
F_77 ( V_13 -> V_141 [ 0 ] . V_46 , V_13 ) ;
goto V_435;
}
} else {
V_22 = F_75 ( V_13 -> V_128 -> V_130 , F_265 ( V_13 ) ,
( V_13 -> V_68 & V_129 ) ? 0 : V_436 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_435;
}
F_91 ( V_13 ) ;
F_266 ( V_13 ) ;
F_267 ( V_13 ) ;
V_13 -> V_68 |= V_168 ;
F_254 ( & V_415 ) ;
F_255 ( V_13 , V_437 ) ;
#if F_257 ( V_438 )
F_260 ( V_13 ) ;
#endif
F_268 ( & V_13 -> V_63 ) ;
return V_22 ;
V_435:
F_11 ( V_13 -> V_30 , L_39 , V_22 ) ;
V_434:
F_98 ( V_13 ) ;
V_433:
F_254 ( & V_415 ) ;
return V_22 ;
}
static void F_269 ( struct V_12 * V_12 )
{
F_270 ( & V_12 -> V_252 ) ;
F_270 ( & V_12 -> V_395 ) ;
F_270 ( & V_12 -> V_402 ) ;
V_12 -> V_250 = false ;
V_12 -> V_248 = NULL ;
F_271 ( V_12 ) ;
F_98 ( V_12 ) ;
V_12 -> V_68 &= ~ V_168 ;
}
static int F_272 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_18 ( V_2 ) ;
if ( ! ( V_12 -> V_68 & V_168 ) ) {
V_22 = F_264 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
F_273 ( V_2 ) ;
return V_22 ;
}
static int F_274 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_275 ( V_2 ) ;
F_18 ( V_2 ) ;
return F_276 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , false , false ) ;
}
int F_277 ( const struct V_1 * V_2 , unsigned int V_228 ,
T_10 V_271 , T_11 V_272 , T_11 V_273 ,
unsigned int V_274 , unsigned char V_39 , unsigned char V_439 )
{
int V_54 ;
struct V_267 * V_440 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_334 ;
V_13 = F_164 ( V_2 ) ;
V_228 -= V_13 -> V_246 . V_237 ;
V_228 += V_13 -> V_246 . V_260 ;
V_440 = & V_13 -> V_246 . V_265 [ V_228 ] ;
V_54 = F_278 ( V_440 ) ;
if ( V_54 )
return V_54 ;
if ( V_440 -> V_441 )
F_279 ( V_13 , V_440 ) ;
memset ( & V_440 -> V_442 , 0 , sizeof( struct V_443 ) ) ;
V_440 -> V_442 . V_334 . V_444 = F_280 ( V_272 ) ;
V_440 -> V_442 . V_439 . V_444 = ~ 0 ;
V_334 = ( T_3 * ) & V_271 ;
if ( ( V_334 [ 0 ] | V_334 [ 1 ] | V_334 [ 2 ] | V_334 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_440 -> V_442 . V_334 . V_445 [ V_19 ] = V_334 [ V_19 ] ;
V_440 -> V_442 . V_439 . V_445 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_188 . V_446 . V_447 & V_448 ) {
V_440 -> V_442 . V_334 . V_449 = V_39 ;
V_440 -> V_442 . V_439 . V_449 = V_439 ;
}
}
if ( V_13 -> V_188 . V_446 . V_447 & V_450 ) {
V_440 -> V_442 . V_334 . V_451 = V_452 ;
V_440 -> V_442 . V_439 . V_451 = ~ 0 ;
}
V_440 -> V_442 . V_453 = 1 ;
V_440 -> V_442 . V_454 = V_274 ;
V_440 -> V_455 = 1 ;
V_440 -> V_442 . V_456 = 1 ;
V_440 -> V_240 = V_228 + V_13 -> V_246 . V_457 ;
V_54 = F_281 ( V_13 , V_228 ) ;
if ( V_54 ) {
F_279 ( V_13 , V_440 ) ;
return V_54 ;
}
return 0 ;
}
int F_282 ( const struct V_1 * V_2 , unsigned int V_228 ,
unsigned int V_274 , bool V_293 )
{
struct V_267 * V_440 ;
struct V_12 * V_13 ;
V_13 = F_164 ( V_2 ) ;
V_228 -= V_13 -> V_246 . V_237 ;
V_228 += V_13 -> V_246 . V_260 ;
V_440 = & V_13 -> V_246 . V_265 [ V_228 ] ;
V_440 -> V_455 = 0 ;
return F_283 ( V_13 , V_228 ) ;
}
static void F_284 ( struct V_1 * V_2 ,
struct V_458 * V_459 )
{
struct V_460 V_185 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_189 ( & V_12 -> V_320 ) ;
if ( ! F_285 ( V_2 ) ) {
F_191 ( & V_12 -> V_320 ) ;
return;
}
F_286 ( V_12 , V_6 -> V_76 , & V_185 ,
& V_6 -> V_461 ) ;
F_191 ( & V_12 -> V_320 ) ;
V_459 -> V_462 = V_185 . V_463 ;
V_459 -> V_464 = V_185 . V_465 ;
V_459 -> V_466 = V_185 . V_467 ;
V_459 -> V_468 = V_185 . V_469 ;
V_459 -> V_470 = V_185 . V_471 ;
V_459 -> V_472 = V_185 . V_473 + V_185 . V_474 +
V_185 . V_475 ;
V_459 -> V_476 = 0 ;
V_459 -> V_477 = V_185 . V_478 ;
V_459 -> V_479 = V_185 . V_480 ;
V_459 -> V_481 = V_185 . V_482 + V_185 . V_483 +
V_185 . V_484 + V_185 . V_485 +
V_185 . V_486 + V_185 . V_487 +
V_185 . V_488 + V_185 . V_489 ;
V_459 -> V_490 = 0 ;
V_459 -> V_491 = 0 ;
V_459 -> V_492 = 0 ;
V_459 -> V_493 = 0 ;
V_459 -> V_494 = 0 ;
V_459 -> V_495 = 0 ;
V_459 -> V_496 = V_185 . V_497 ;
V_459 -> V_498 = V_185 . V_480 + V_185 . V_478 +
V_459 -> V_472 + V_185 . V_499 + V_459 -> V_500 ;
}
static int F_287 ( struct V_1 * V_2 , struct V_501 * V_242 , int V_110 )
{
unsigned int V_27 ;
int V_54 = 0 , V_502 , V_503 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_504 * V_109 = (struct V_504 * ) & V_242 -> V_505 ;
switch ( V_110 ) {
case V_506 :
if ( V_11 -> V_507 < 0 )
return - V_508 ;
V_109 -> V_509 = V_11 -> V_507 ;
break;
case V_510 :
case V_511 :
if ( F_288 ( V_109 -> V_509 ) ) {
V_502 = F_289 ( V_109 -> V_509 ) ;
V_503 = F_290 ( V_109 -> V_509 ) ;
} else if ( V_109 -> V_509 < 32 ) {
V_502 = V_109 -> V_509 ;
V_503 = 0 ;
V_109 -> V_512 &= 0x1f ;
} else
return - V_65 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_110 == V_510 )
V_54 = F_291 ( V_11 -> V_12 , V_27 , V_502 , V_503 ,
V_109 -> V_512 , & V_109 -> V_513 ) ;
else
V_54 = F_292 ( V_11 -> V_12 , V_27 , V_502 , V_503 ,
V_109 -> V_512 , V_109 -> V_514 ) ;
break;
case V_515 :
return F_293 ( V_242 -> V_505 , & V_11 -> V_516 ,
sizeof( V_11 -> V_516 ) ) ?
- V_517 : 0 ;
case V_518 :
if ( F_294 ( & V_11 -> V_516 , V_242 -> V_505 ,
sizeof( V_11 -> V_516 ) ) )
return - V_517 ;
switch ( V_11 -> V_516 . V_519 ) {
case V_520 :
V_11 -> V_521 = false ;
break;
case V_522 :
V_11 -> V_521 = true ;
break;
default:
V_11 -> V_516 . V_519 = V_520 ;
return - V_523 ;
}
return F_293 ( V_242 -> V_505 , & V_11 -> V_516 ,
sizeof( V_11 -> V_516 ) ) ?
- V_517 : 0 ;
default:
return - V_508 ;
}
return V_54 ;
}
static void F_295 ( struct V_1 * V_2 )
{
F_36 ( V_2 , - 1 , false ) ;
}
static int F_296 ( struct V_1 * V_2 , int V_524 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
V_54 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , V_524 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_54 )
V_2 -> V_66 = V_524 ;
return V_54 ;
}
static int F_297 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
return 0 ;
}
static void F_298 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
T_3 V_525 [ V_526 ] , V_527 [ V_526 ] ;
int V_22 ;
T_3 * V_528 ;
T_6 V_529 , V_530 ;
V_22 = F_299 ( V_13 , & V_13 -> V_188 . V_531 ) ;
if ( ! V_22 ) {
V_528 = V_13 -> V_188 . V_531 . V_528 ;
for ( V_19 = 0 ; V_19 < V_526 ; V_19 ++ )
V_525 [ V_19 ] = ( F_300 ( V_528 [ 2 * V_19 + 0 ] ) * 16 +
F_300 ( V_528 [ 2 * V_19 + 1 ] ) ) ;
V_529 = ( V_525 [ 0 ] << 8 ) | V_525 [ 1 ] ;
V_530 = ( V_525 [ 1 ] << 8 ) | V_525 [ 2 ] ;
V_529 ^= V_530 ;
V_529 |= 0x0200 ;
V_529 &= ~ 0x0100 ;
V_527 [ 0 ] = V_529 >> 8 ;
V_527 [ 1 ] = V_529 & 0xff ;
for ( V_19 = 2 ; V_19 < 5 ; V_19 ++ )
V_527 [ V_19 ] = V_525 [ V_19 + 1 ] ;
for ( V_19 = 0 ; V_19 < V_13 -> V_532 ; V_19 ++ ) {
V_527 [ 5 ] = V_13 -> V_28 * 16 + V_19 ;
F_28 ( V_13 -> V_533 [ V_19 ] . V_534 , V_527 ) ;
}
}
}
static int F_301 ( struct V_1 * V_2 , int V_535 , T_3 * V_536 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
if ( ! F_302 ( V_536 ) ) {
F_11 ( V_11 -> V_12 -> V_30 ,
L_40 ,
V_536 , V_535 ) ;
return - V_65 ;
}
F_303 ( V_11 -> V_12 -> V_30 ,
L_41 , V_536 , V_535 ) ;
V_54 = F_304 ( V_13 , V_535 + 1 , 1 , V_536 ) ;
if ( ! V_54 )
F_28 ( V_13 -> V_533 [ V_535 ] . V_534 , V_536 ) ;
return V_54 ;
}
static int F_305 ( struct V_1 * V_2 ,
int V_535 , struct V_537 * V_538 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_535 >= V_13 -> V_532 )
return - V_65 ;
V_538 -> V_535 = V_535 ;
F_28 ( V_538 -> V_536 , V_13 -> V_533 [ V_535 ] . V_534 ) ;
return 0 ;
}
static int F_306 ( struct V_1 * V_2 ,
struct V_539 * V_540 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_541 ;
V_541 = V_11 -> V_12 -> V_542 * 10 + V_11 -> V_31 ;
V_540 -> V_543 = sizeof( V_541 ) ;
memcpy ( V_540 -> V_544 , & V_541 , V_540 -> V_543 ) ;
return 0 ;
}
static int F_307 ( struct V_1 * V_2 , void * V_6 )
{
int V_54 ;
struct V_545 * V_50 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_302 ( V_50 -> V_546 ) )
return - V_547 ;
V_54 = F_41 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 ,
V_11 -> V_74 , V_50 -> V_546 , true , true ) ;
if ( V_54 < 0 )
return V_54 ;
memcpy ( V_2 -> V_75 , V_50 -> V_546 , V_2 -> V_548 ) ;
V_11 -> V_74 = V_54 ;
return 0 ;
}
static void F_308 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_68 & V_127 ) {
int V_19 ;
struct V_153 * V_549 = & V_13 -> V_16 . V_148 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_549 ++ )
V_146 ( 0 , & V_549 -> V_149 ) ;
} else
F_265 ( V_13 ) ( 0 , V_13 ) ;
}
static int F_309 ( struct V_1 * V_2 , int V_550 , T_1 V_551 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_552 * V_553 ;
struct V_554 V_6 ;
struct V_555 V_556 ;
T_1 V_557 ;
int V_22 = 0 ;
if ( ! F_310 ( V_2 ) )
return - V_558 ;
if ( V_550 < 0 || V_550 > V_11 -> V_20 - 1 )
return - V_65 ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_42 ,
V_550 ) ;
return - V_65 ;
}
V_557 = V_551 << 10 ;
if ( V_557 >= V_559 ) {
F_11 ( V_13 -> V_30 ,
L_43 ,
V_551 , V_559 ) ;
return - V_523 ;
}
memset ( & V_556 , 0 , sizeof( V_556 ) ) ;
V_556 . V_274 = V_550 ;
V_556 . V_560 = V_561 ;
V_22 = F_311 ( V_2 , ( void * ) ( & V_556 ) , V_562 ) ;
if ( V_22 ) {
F_11 ( V_13 -> V_30 ,
L_44 ,
V_550 , V_11 -> V_31 , V_22 ) ;
return V_22 ;
}
if ( ! V_557 )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_563 ;
V_6 . V_116 . V_188 . V_564 = V_565 ;
V_6 . V_116 . V_188 . V_566 = V_567 ;
V_6 . V_116 . V_188 . V_568 = V_569 ;
V_6 . V_116 . V_188 . V_570 = V_571 ;
V_6 . V_116 . V_188 . V_572 = V_11 -> V_76 ;
V_6 . V_116 . V_188 . V_560 = V_561 ;
V_6 . V_116 . V_188 . V_573 = 0 ;
V_6 . V_116 . V_188 . V_574 = V_557 ;
V_6 . V_116 . V_188 . V_575 = 0 ;
V_6 . V_116 . V_188 . V_576 = V_2 -> V_66 ;
V_553 = F_312 ( V_2 , & V_6 ) ;
if ( ! V_553 )
return - V_61 ;
memset ( & V_556 , 0 , sizeof( V_556 ) ) ;
V_556 . V_274 = V_550 ;
V_556 . V_560 = V_553 -> V_184 ;
V_22 = F_313 ( V_2 , ( void * ) ( & V_556 ) , V_562 ) ;
if ( V_22 )
F_11 ( V_13 -> V_30 ,
L_45 , V_22 ) ;
return V_22 ;
}
static int F_314 ( struct V_1 * V_2 , T_1 V_394 , T_11 V_451 ,
struct V_577 * V_578 )
{
struct V_5 * V_11 = F_86 ( V_2 ) ;
struct V_12 * V_13 = F_164 ( V_2 ) ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_46 ,
V_11 -> V_31 ) ;
return - V_65 ;
}
if ( F_315 ( V_394 ) == F_315 ( V_579 ) &&
V_578 -> type == V_580 ) {
switch ( V_578 -> V_581 -> V_582 ) {
case V_583 :
case V_584 :
return F_316 ( V_2 , V_451 , V_578 -> V_581 ) ;
case V_585 :
return F_317 ( V_2 , V_451 , V_578 -> V_581 ) ;
default:
return - V_508 ;
}
}
return - V_508 ;
}
static void F_318 ( struct V_1 * V_2 , struct V_586 * V_117 )
{
struct V_12 * V_12 = F_164 ( V_2 ) ;
F_319 ( V_117 -> V_374 , V_587 , sizeof( V_117 -> V_374 ) ) ;
F_319 ( V_117 -> V_588 , V_589 ,
sizeof( V_117 -> V_588 ) ) ;
F_319 ( V_117 -> V_590 , F_320 ( V_12 -> V_128 ) ,
sizeof( V_117 -> V_590 ) ) ;
}
void F_321 ( struct V_12 * V_13 )
{
int V_39 ;
if ( F_322 ( V_13 -> V_128 ) )
return;
F_323 ( V_13 ) ;
F_73 (adap, port) {
struct V_1 * V_2 = V_13 -> V_39 [ V_39 ] ;
if ( ! V_2 )
continue;
F_275 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_324 ( V_13 -> V_30 , L_47 ) ;
}
static void F_325 ( struct V_12 * V_13 )
{
T_1 V_591 = F_326 ( V_13 ) ;
F_327 ( V_13 , V_591 , V_592 ) ;
}
static void F_328 ( struct V_12 * V_13 )
{
if ( V_13 -> V_349 . V_593 . V_264 ) {
T_1 V_350 ;
unsigned int V_594 ;
V_350 = F_329 ( V_13 , V_595 ) ;
V_350 &= V_596 ;
V_350 += F_330 ( V_13 -> V_128 , & V_13 -> V_349 ) ;
V_594 = F_331 ( V_13 -> V_349 . V_593 . V_264 ) >> 10 ;
F_70 ( V_13 ,
F_332 ( V_597 , 3 ) ,
V_350 | F_333 ( 1 ) | F_334 ( F_335 ( V_594 ) ) ) ;
F_70 ( V_13 ,
F_332 ( V_598 , 3 ) ,
V_13 -> V_349 . V_593 . V_350 ) ;
F_68 ( V_13 ,
F_332 ( V_598 , 3 ) ) ;
}
}
static int F_336 ( struct V_12 * V_13 , struct V_599 * V_600 )
{
T_1 V_132 ;
int V_54 ;
memset ( V_600 , 0 , sizeof( * V_600 ) ) ;
V_600 -> V_601 = F_145 ( F_337 ( V_602 ) |
V_603 | V_604 ) ;
V_600 -> V_605 = F_145 ( F_338 ( * V_600 ) ) ;
V_54 = F_339 ( V_13 , V_13 -> V_27 , V_600 , sizeof( * V_600 ) , V_600 ) ;
if ( V_54 < 0 )
return V_54 ;
V_600 -> V_601 = F_145 ( F_337 ( V_602 ) |
V_603 | V_606 ) ;
V_54 = F_339 ( V_13 , V_13 -> V_27 , V_600 , sizeof( * V_600 ) , NULL ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_340 ( V_13 , V_13 -> V_28 ,
V_607 ,
V_608 |
V_609 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_341 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_172 , 64 ,
V_610 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_611 ,
V_611 ) ;
if ( V_54 < 0 )
return V_54 ;
F_342 ( V_13 ) ;
F_70 ( V_13 , V_612 , 0x64f8849 ) ;
F_70 ( V_13 , V_613 , F_193 ( V_614 - 12 ) ) ;
F_70 ( V_13 , V_615 , V_616 ) ;
V_132 = F_68 ( V_13 , V_617 ) ;
F_70 ( V_13 , V_617 , V_132 & ~ V_618 ) ;
V_13 -> V_188 . V_446 . V_619 = 0xE4 ;
F_70 ( V_13 , V_620 ,
F_343 ( V_13 -> V_188 . V_446 . V_619 ) ) ;
V_132 = 0x84218421 ;
F_344 ( V_13 , V_615 , V_617 ,
& V_132 , 1 , V_621 ) ;
F_344 ( V_13 , V_615 , V_617 ,
& V_132 , 1 , V_622 ) ;
F_344 ( V_13 , V_615 , V_617 ,
& V_132 , 1 , V_623 ) ;
#define F_345 16
if ( F_161 ( V_13 ) ) {
F_70 ( V_13 , V_624 ,
F_346 ( F_345 ) |
F_347 ( F_345 ) |
F_348 ( F_345 ) |
F_349 ( F_345 ) ) ;
F_70 ( V_13 , V_625 ,
F_346 ( F_345 ) |
F_347 ( F_345 ) |
F_348 ( F_345 ) |
F_349 ( F_345 ) ) ;
}
return F_350 ( V_13 , V_13 -> V_28 ) ;
}
static int F_351 ( struct V_12 * V_12 )
{
F_352 ( V_12 , V_626 , V_627 ) ;
if ( V_628 != 2 && V_628 != 0 ) {
F_11 ( & V_12 -> V_128 -> V_2 ,
L_48 ,
V_628 ) ;
V_628 = 2 ;
}
F_239 ( V_12 , V_629 ,
F_353 ( V_630 ) ,
F_353 ( V_628 ) ) ;
F_354 ( V_12 , V_616 ,
V_618 , 0 ) ;
return 0 ;
}
static int F_355 ( const T_3 * V_631 ,
T_9 V_632 )
{
int V_338 ;
#define F_356 ( T_12 ) (((__p)[0] << 8) | (__p)[1])
#define F_357 ( T_12 ) ((__p)[0] | ((__p)[1] << 8))
#define F_358 ( T_12 ) (le16(__p) | ((__p)[2] << 16))
V_338 = F_358 ( V_631 + 0x8 ) << 12 ;
V_338 = F_358 ( V_631 + V_338 + 0xa ) ;
return F_356 ( V_631 + V_338 + 0x27e ) ;
#undef F_356
#undef F_357
#undef F_358
}
static struct V_633 * F_359 ( int V_634 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_635 ) ; V_19 ++ ) {
if ( V_635 [ V_19 ] . V_636 == V_634 )
return & V_635 [ V_19 ] ;
}
return NULL ;
}
static int F_360 ( struct V_12 * V_13 )
{
const struct V_637 * V_638 ;
int V_54 ;
struct V_633 * V_639 ;
V_639 = F_359 ( V_13 -> V_128 -> V_372 ) ;
if ( ! V_639 ) {
F_361 ( V_13 -> V_30 ,
L_49 ) ;
return - V_508 ;
}
V_54 = F_362 ( & V_638 , V_639 -> V_640 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_50
L_51 ,
V_639 -> V_640 , - V_54 ) ;
if ( V_639 -> V_641 ) {
int V_642 = 0 ;
F_363 ( V_13 , & V_642 ) ;
F_361 ( V_13 -> V_30 , L_52
L_53 , V_642 ) ;
V_54 = 0 ;
}
return V_54 ;
}
V_54 = F_364 ( V_13 , V_592 , & V_13 -> V_329 ,
V_639 -> V_643 ,
( T_3 * ) V_638 -> V_109 , V_638 -> V_264 ) ;
if ( V_54 < 0 )
F_11 ( V_13 -> V_30 , L_54 ,
- V_54 ) ;
else if ( V_54 > 0 ) {
int V_644 = 0 ;
if ( V_639 -> V_643 )
V_644 = V_639 -> V_643 ( V_638 -> V_109 ,
V_638 -> V_264 ) ;
F_303 ( V_13 -> V_30 , L_55
L_56 ,
V_639 -> V_640 , V_644 ) ;
}
F_365 ( V_638 ) ;
return V_54 ;
}
static int F_366 ( struct V_12 * V_12 , int V_645 )
{
struct V_599 V_646 ;
const struct V_637 * V_647 ;
unsigned long V_648 = 0 , V_649 = 0 ;
T_1 V_650 , V_651 , V_652 ;
int V_54 ;
int V_653 = 0 ;
char * V_654 , V_655 [ 256 ] ;
char * V_656 = NULL ;
if ( V_645 ) {
V_54 = F_367 ( V_12 , V_12 -> V_27 ,
V_657 | V_658 ) ;
if ( V_54 < 0 )
goto V_659;
}
if ( F_368 ( V_12 -> V_128 -> V_372 ) ) {
V_54 = F_360 ( V_12 ) ;
if ( V_54 < 0 )
goto V_659;
}
switch ( F_162 ( V_12 -> V_188 . V_189 ) ) {
case V_660 :
V_654 = V_661 ;
break;
case V_270 :
V_654 = V_662 ;
break;
case V_663 :
V_654 = V_664 ;
break;
default:
F_11 ( V_12 -> V_30 , L_57 ,
V_12 -> V_128 -> V_372 ) ;
V_54 = - V_65 ;
goto V_659;
}
V_54 = F_369 ( & V_647 , V_654 , V_12 -> V_30 ) ;
if ( V_54 < 0 ) {
V_656 = L_58 ;
V_648 = V_665 ;
V_649 = F_370 ( V_12 ) ;
} else {
T_1 V_188 [ 7 ] , V_334 [ 7 ] ;
sprintf ( V_655 ,
L_59 , V_654 ) ;
V_656 = V_655 ;
if ( V_647 -> V_264 >= V_666 )
V_54 = - V_61 ;
else {
V_188 [ 0 ] = ( F_7 ( V_667 ) |
F_8 ( V_668 ) ) ;
V_54 = F_371 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_188 , V_334 ) ;
if ( V_54 == 0 ) {
T_9 V_669 = V_647 -> V_264 & 0x3 ;
T_9 V_264 = V_647 -> V_264 & ~ 0x3 ;
T_10 * V_109 = ( T_10 * ) V_647 -> V_109 ;
V_648 = F_372 ( V_334 [ 0 ] ) ;
V_649 = F_373 ( V_334 [ 0 ] ) << 16 ;
F_189 ( & V_12 -> V_329 ) ;
V_54 = F_200 ( V_12 , 0 , V_648 , V_649 ,
V_264 , V_109 , V_670 ) ;
if ( V_54 == 0 && V_669 != 0 ) {
union {
T_10 V_671 ;
char V_672 [ 4 ] ;
} V_673 ;
int V_19 ;
V_673 . V_671 = V_109 [ V_264 >> 2 ] ;
for ( V_19 = V_669 ; V_19 < 4 ; V_19 ++ )
V_673 . V_672 [ V_19 ] = 0 ;
V_54 = F_200 ( V_12 , 0 , V_648 ,
V_649 + V_264 ,
4 , & V_673 . V_671 ,
V_670 ) ;
}
F_191 ( & V_12 -> V_329 ) ;
}
}
F_365 ( V_647 ) ;
if ( V_54 )
goto V_659;
}
memset ( & V_646 , 0 , sizeof( V_646 ) ) ;
V_646 . V_601 =
F_145 ( F_337 ( V_602 ) |
V_603 |
V_604 ) ;
V_646 . V_605 =
F_145 ( V_674 |
F_374 ( V_648 ) |
F_375 ( V_649 >> 16 ) |
F_338 ( V_646 ) ) ;
V_54 = F_339 ( V_12 , V_12 -> V_27 , & V_646 , sizeof( V_646 ) ,
& V_646 ) ;
if ( V_54 == - V_675 ) {
memset ( & V_646 , 0 , sizeof( V_646 ) ) ;
V_646 . V_601 =
F_145 ( F_337 ( V_602 ) |
V_603 |
V_604 ) ;
V_646 . V_605 = F_145 ( F_338 ( V_646 ) ) ;
V_54 = F_339 ( V_12 , V_12 -> V_27 , & V_646 ,
sizeof( V_646 ) , & V_646 ) ;
V_656 = L_60 ;
}
V_653 = 1 ;
if ( V_54 < 0 )
goto V_659;
V_650 = F_48 ( V_646 . V_650 ) ;
V_651 = F_48 ( V_646 . V_651 ) ;
V_652 = F_48 ( V_646 . V_652 ) ;
if ( V_651 != V_652 )
F_361 ( V_12 -> V_30 , L_61\
L_62 ,
V_651 , V_652 ) ;
V_646 . V_601 =
F_145 ( F_337 ( V_602 ) |
V_603 |
V_606 ) ;
V_646 . V_605 = F_145 ( F_338 ( V_646 ) ) ;
V_54 = F_339 ( V_12 , V_12 -> V_27 , & V_646 , sizeof( V_646 ) ,
NULL ) ;
if ( V_54 < 0 )
goto V_659;
V_54 = F_351 ( V_12 ) ;
if ( V_54 < 0 )
goto V_659;
V_54 = F_376 ( V_12 , V_12 -> V_27 ) ;
if ( V_54 < 0 )
goto V_659;
F_303 ( V_12 -> V_30 , L_63\
L_64 ,
V_656 , V_650 , V_652 ) ;
return 0 ;
V_659:
if ( V_653 && V_54 != - V_675 )
F_361 ( V_12 -> V_30 , L_65 ,
V_656 , - V_54 ) ;
return V_54 ;
}
static struct V_676 * F_377 ( int V_189 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_677 ) ; V_19 ++ ) {
if ( V_677 [ V_19 ] . V_189 == V_189 )
return & V_677 [ V_19 ] ;
}
return NULL ;
}
static int F_378 ( struct V_12 * V_13 )
{
int V_54 ;
T_1 V_132 , V_678 ;
enum V_679 V_35 ;
T_1 V_188 [ 7 ] , V_334 [ 7 ] ;
struct V_599 V_646 ;
int V_645 = 1 ;
V_54 = F_379 ( V_13 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_380 ( V_13 , V_13 -> V_27 , V_13 -> V_27 ,
F_381 () ? V_680 : V_681 , & V_35 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_66 ,
V_54 ) ;
return V_54 ;
}
if ( V_54 == V_13 -> V_27 )
V_13 -> V_68 |= V_136 ;
F_382 ( V_13 , & V_13 -> V_188 . V_682 ) ;
F_383 ( V_13 , & V_13 -> V_188 . V_683 ) ;
F_384 ( V_13 , & V_13 -> V_188 . V_684 ) ;
F_385 ( V_13 , & V_13 -> V_188 . V_685 ) ;
V_54 = F_386 ( V_13 ) ;
if ( V_54 )
V_35 = V_686 ;
if ( ( V_13 -> V_68 & V_136 ) && V_35 != V_687 ) {
struct V_676 * V_676 ;
struct V_688 * V_689 ;
const struct V_637 * V_690 ;
const T_3 * V_691 = NULL ;
unsigned int V_692 = 0 ;
V_676 = F_377 ( F_162 ( V_13 -> V_188 . V_189 ) ) ;
if ( V_676 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_67 ,
F_162 ( V_13 -> V_188 . V_189 ) ) ;
return - V_65 ;
}
V_689 = F_158 ( sizeof( * V_689 ) , V_156 ) ;
V_54 = F_369 ( & V_690 , V_676 -> V_693 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_68 ,
V_676 -> V_693 , V_54 ) ;
} else {
V_691 = V_690 -> V_109 ;
V_692 = V_690 -> V_264 ;
}
V_54 = F_387 ( V_13 , V_676 , V_691 , V_692 , V_689 ,
V_35 , & V_645 ) ;
F_365 ( V_690 ) ;
F_388 ( V_689 ) ;
if ( V_54 < 0 )
goto V_659;
}
V_54 = F_389 ( V_13 , & V_13 -> V_188 . V_531 ) ;
if ( V_54 < 0 )
goto V_659;
V_132 =
F_7 ( V_667 ) |
F_8 ( V_694 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_132 , & V_678 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_188 . V_695 = F_390 ( V_678 ) ;
V_13 -> V_188 . V_696 = V_678 ;
if ( V_35 == V_687 ) {
F_303 ( V_13 -> V_30 , L_69\
L_70 ,
V_13 -> V_68 & V_136 ? L_71 : L_72 ) ;
} else {
F_303 ( V_13 -> V_30 , L_73\
L_74 ) ;
V_188 [ 0 ] = ( F_7 ( V_667 ) |
F_8 ( V_668 ) ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_188 , V_334 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_75
L_76 ) ;
goto V_659;
}
V_54 = F_366 ( V_13 , V_645 ) ;
if ( V_54 == - V_675 ) {
F_11 ( V_13 -> V_30 , L_77
L_78 ) ;
goto V_659;
}
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_79
L_80 , - V_54 ) ;
goto V_659;
}
}
V_54 = F_342 ( V_13 ) ;
if ( V_54 < 0 )
goto V_659;
if ( F_391 ( V_13 -> V_128 -> V_372 ) )
V_13 -> V_188 . V_697 = 1 ;
#define F_392 ( T_13 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_393 ( T_13 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_188 [ 0 ] = F_393 ( V_698 ) ;
V_188 [ 1 ] = F_393 ( V_699 ) ;
V_188 [ 2 ] = F_393 ( V_700 ) ;
V_188 [ 3 ] = F_393 ( V_701 ) ;
V_188 [ 4 ] = F_393 ( V_702 ) ;
V_188 [ 5 ] = F_393 ( V_703 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 , V_334 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_16 . V_99 = V_334 [ 0 ] ;
V_13 -> V_704 = V_334 [ 1 ] ;
V_13 -> V_705 = V_334 [ 2 ] ;
V_13 -> V_246 . V_457 = V_334 [ 3 ] ;
V_13 -> V_246 . V_260 = V_334 [ 4 ] - V_334 [ 3 ] + 1 ;
V_13 -> V_16 . V_163 = V_334 [ 5 ] ;
V_188 [ 0 ] = F_393 ( V_706 ) ;
V_188 [ 1 ] = F_393 ( V_707 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_334 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_16 . V_172 = V_334 [ 0 ] - V_13 -> V_16 . V_99 + 1 ;
V_13 -> V_16 . V_165 = V_334 [ 1 ] - V_13 -> V_16 . V_163 + 1 ;
V_13 -> V_16 . V_98 = F_394 ( V_13 -> V_16 . V_172 ,
sizeof( * V_13 -> V_16 . V_98 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_98 ) {
V_54 = - V_61 ;
goto V_659;
}
V_13 -> V_16 . V_164 = F_394 ( V_13 -> V_16 . V_165 ,
sizeof( * V_13 -> V_16 . V_164 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_164 ) {
V_54 = - V_61 ;
goto V_659;
}
V_13 -> V_16 . V_171 = F_394 ( F_157 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_171 ) {
V_54 = - V_61 ;
goto V_659;
}
V_13 -> V_16 . V_173 = F_394 ( F_157 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_173 ) {
V_54 = - V_61 ;
goto V_659;
}
#ifdef F_125
V_13 -> V_16 . V_708 = F_394 ( F_157 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_708 ) {
V_54 = - V_61 ;
goto V_659;
}
#endif
V_188 [ 0 ] = F_393 ( V_709 ) ;
V_188 [ 1 ] = F_393 ( V_710 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_334 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_711 = V_334 [ 0 ] ;
V_13 -> V_712 = V_334 [ 1 ] ;
V_13 -> V_188 . V_713 = F_104 ( V_13 -> V_188 . V_189 ) ? 15 : 16 ;
V_188 [ 0 ] = F_393 ( V_714 ) ;
V_188 [ 1 ] = F_393 ( V_715 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_334 ) ;
if ( ( V_334 [ 0 ] != V_334 [ 1 ] ) && ( V_54 >= 0 ) ) {
V_13 -> V_68 |= V_716 ;
V_13 -> V_246 . V_717 = V_334 [ 0 ] ;
V_13 -> V_246 . V_718 = V_334 [ 1 ] ;
}
V_188 [ 0 ] = F_393 ( V_719 ) ;
V_334 [ 0 ] = 1 ;
( void ) F_119 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_188 , V_334 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
V_13 -> V_188 . V_720 = false ;
} else {
V_188 [ 0 ] = F_392 ( V_721 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_334 ) ;
V_13 -> V_188 . V_720 = ( V_54 == 0 && V_334 [ 0 ] != 0 ) ;
}
V_188 [ 0 ] = F_392 ( V_722 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_334 ) ;
V_13 -> V_188 . V_723 = ( V_54 == 0 && V_334 [ 0 ] != 0 ) ;
memset ( & V_646 , 0 , sizeof( V_646 ) ) ;
V_646 . V_601 = F_145 ( F_337 ( V_602 ) |
V_603 | V_604 ) ;
V_646 . V_605 = F_145 ( F_338 ( V_646 ) ) ;
V_54 = F_339 ( V_13 , V_13 -> V_27 , & V_646 , sizeof( V_646 ) ,
& V_646 ) ;
if ( V_54 < 0 )
goto V_659;
if ( V_646 . V_724 ) {
V_188 [ 0 ] = F_392 ( V_725 ) ;
V_188 [ 1 ] = F_393 ( V_726 ) ;
V_188 [ 2 ] = F_393 ( V_727 ) ;
V_188 [ 3 ] = F_393 ( V_728 ) ;
V_188 [ 4 ] = F_393 ( V_729 ) ;
V_188 [ 5 ] = F_392 ( V_730 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_334 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_246 . V_255 = V_334 [ 0 ] ;
V_13 -> V_246 . V_261 = F_395 ( V_13 -> V_246 . V_255 / 2 , V_731 ) ;
V_13 -> V_246 . V_234 = V_334 [ 1 ] ;
V_13 -> V_246 . V_232 = V_334 [ 2 ] - V_334 [ 1 ] + 1 ;
if ( V_13 -> V_68 & V_716 && ! F_396 ( V_13 ) ) {
V_13 -> V_246 . V_237 = V_13 -> V_246 . V_457 +
F_397 ( V_13 -> V_246 . V_260 , 3 ) ;
V_13 -> V_246 . V_236 = V_13 -> V_246 . V_260 -
F_397 ( V_13 -> V_246 . V_260 , 3 ) ;
V_13 -> V_246 . V_260 = V_13 -> V_246 . V_237 -
V_13 -> V_246 . V_457 ;
}
V_13 -> V_349 . V_732 . V_350 = V_334 [ 3 ] ;
V_13 -> V_349 . V_732 . V_264 = V_334 [ 4 ] - V_334 [ 3 ] + 1 ;
V_13 -> V_188 . V_733 = V_334 [ 5 ] ;
V_13 -> V_188 . V_734 = 1 ;
V_13 -> V_735 += 1 ;
}
if ( V_646 . V_736 ) {
V_188 [ 0 ] = F_393 ( V_737 ) ;
V_188 [ 1 ] = F_393 ( V_738 ) ;
V_188 [ 2 ] = F_393 ( V_739 ) ;
V_188 [ 3 ] = F_393 ( V_740 ) ;
V_188 [ 4 ] = F_393 ( V_741 ) ;
V_188 [ 5 ] = F_393 ( V_742 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_334 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_349 . V_336 . V_350 = V_334 [ 0 ] ;
V_13 -> V_349 . V_336 . V_264 = V_334 [ 1 ] - V_334 [ 0 ] + 1 ;
V_13 -> V_349 . V_743 . V_350 = V_334 [ 2 ] ;
V_13 -> V_349 . V_743 . V_264 = V_334 [ 3 ] - V_334 [ 2 ] + 1 ;
V_13 -> V_349 . V_744 . V_350 = V_334 [ 4 ] ;
V_13 -> V_349 . V_744 . V_264 = V_334 [ 5 ] - V_334 [ 4 ] + 1 ;
V_188 [ 0 ] = F_393 ( V_745 ) ;
V_188 [ 1 ] = F_393 ( V_746 ) ;
V_188 [ 2 ] = F_393 ( V_747 ) ;
V_188 [ 3 ] = F_393 ( V_748 ) ;
V_188 [ 4 ] = F_393 ( V_749 ) ;
V_188 [ 5 ] = F_393 ( V_750 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 ,
V_334 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_349 . V_751 . V_350 = V_334 [ 0 ] ;
V_13 -> V_349 . V_751 . V_264 = V_334 [ 1 ] - V_334 [ 0 ] + 1 ;
V_13 -> V_349 . V_752 . V_350 = V_334 [ 2 ] ;
V_13 -> V_349 . V_752 . V_264 = V_334 [ 3 ] - V_334 [ 2 ] + 1 ;
V_13 -> V_349 . V_593 . V_350 = V_334 [ 4 ] ;
V_13 -> V_349 . V_593 . V_264 = V_334 [ 5 ] - V_334 [ 4 ] + 1 ;
V_188 [ 0 ] = F_392 ( V_753 ) ;
V_188 [ 1 ] = F_392 ( V_754 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 ,
V_334 ) ;
if ( V_54 < 0 ) {
V_13 -> V_188 . V_755 = 8 ;
V_13 -> V_188 . V_756 = 32 * V_13 -> V_246 . V_255 ;
V_54 = 0 ;
} else {
V_13 -> V_188 . V_755 = V_334 [ 0 ] ;
V_13 -> V_188 . V_756 = V_334 [ 1 ] ;
}
F_303 ( V_13 -> V_30 ,
L_81 ,
V_13 -> V_188 . V_755 ,
V_13 -> V_188 . V_756 ) ;
V_13 -> V_735 += 2 ;
}
if ( V_646 . V_757 ) {
V_188 [ 0 ] = F_393 ( V_758 ) ;
V_188 [ 1 ] = F_393 ( V_759 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_188 , V_334 ) ;
if ( V_54 < 0 )
goto V_659;
V_13 -> V_349 . V_760 . V_350 = V_334 [ 0 ] ;
V_13 -> V_349 . V_760 . V_264 = V_334 [ 1 ] - V_334 [ 0 ] + 1 ;
V_13 -> V_735 += 2 ;
}
if ( V_646 . V_761 ) {
V_188 [ 0 ] = F_393 ( V_762 ) ;
V_54 = F_371 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_188 , V_334 ) ;
if ( V_54 < 0 ) {
if ( V_54 != - V_65 )
goto V_659;
} else {
V_13 -> V_349 . V_763 = V_334 [ 0 ] ;
}
V_13 -> V_188 . V_764 |= V_765 ;
V_13 -> V_766 += 1 ;
}
#undef F_393
#undef F_392
F_398 ( V_13 , V_13 -> V_188 . V_297 , NULL ) ;
if ( V_35 != V_687 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_298 ; V_19 ++ )
if ( V_13 -> V_188 . V_297 [ V_19 ] == 1492 ) {
V_13 -> V_188 . V_297 [ V_19 ] = 1488 ;
break;
}
F_399 ( V_13 , V_13 -> V_188 . V_297 , V_13 -> V_188 . V_767 ,
V_13 -> V_188 . V_768 ) ;
}
F_400 ( V_13 ) ;
V_13 -> V_68 |= V_769 ;
F_401 ( V_13 ) ;
return 0 ;
V_659:
F_34 ( V_13 -> V_16 . V_98 ) ;
F_34 ( V_13 -> V_16 . V_164 ) ;
F_34 ( V_13 -> V_16 . V_171 ) ;
F_34 ( V_13 -> V_16 . V_173 ) ;
#ifdef F_125
F_34 ( V_13 -> V_16 . V_708 ) ;
#endif
if ( V_54 != - V_770 && V_54 != - V_771 )
F_402 ( V_13 , V_13 -> V_27 ) ;
return V_54 ;
}
static T_14 F_403 ( struct V_316 * V_128 ,
T_15 V_35 )
{
int V_19 ;
struct V_12 * V_13 = F_188 ( V_128 ) ;
if ( ! V_13 )
goto V_59;
F_404 () ;
V_13 -> V_68 &= ~ V_769 ;
F_255 ( V_13 , V_772 ) ;
F_189 ( & V_13 -> V_320 ) ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( V_2 ) {
F_405 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
F_191 ( & V_13 -> V_320 ) ;
F_89 ( V_13 ) ;
if ( V_13 -> V_68 & V_168 )
F_269 ( V_13 ) ;
F_406 () ;
if ( ( V_13 -> V_68 & V_773 ) ) {
F_407 ( V_128 ) ;
V_13 -> V_68 &= ~ V_773 ;
}
V_59: return V_35 == V_774 ?
V_775 : V_776 ;
}
static T_14 F_408 ( struct V_316 * V_128 )
{
int V_19 , V_54 ;
struct V_599 V_600 ;
struct V_12 * V_13 = F_188 ( V_128 ) ;
if ( ! V_13 ) {
F_409 ( V_128 ) ;
F_410 ( V_128 ) ;
return V_777 ;
}
if ( ! ( V_13 -> V_68 & V_773 ) ) {
if ( F_411 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 , L_82
L_83 ) ;
return V_775 ;
}
V_13 -> V_68 |= V_773 ;
}
F_412 ( V_128 ) ;
F_409 ( V_128 ) ;
F_410 ( V_128 ) ;
F_413 ( V_128 ) ;
if ( F_414 ( V_13 -> V_778 ) < 0 )
return V_775 ;
if ( F_380 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_680 , NULL ) < 0 )
return V_775 ;
V_13 -> V_68 |= V_769 ;
if ( F_336 ( V_13 , & V_600 ) )
return V_775 ;
F_73 (adap, i) {
struct V_5 * V_6 = F_84 ( V_13 , V_19 ) ;
V_54 = F_415 ( V_13 , V_13 -> V_27 , V_6 -> V_76 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_54 < 0 )
return V_775 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_74 = - 1 ;
}
F_399 ( V_13 , V_13 -> V_188 . V_297 , V_13 -> V_188 . V_767 ,
V_13 -> V_188 . V_768 ) ;
F_325 ( V_13 ) ;
if ( F_264 ( V_13 ) )
return V_775 ;
return V_777 ;
}
static void F_416 ( struct V_316 * V_128 )
{
int V_19 ;
struct V_12 * V_13 = F_188 ( V_128 ) ;
if ( ! V_13 )
return;
F_404 () ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( V_2 ) {
if ( F_14 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_295 ( V_2 ) ;
}
F_417 ( V_2 ) ;
}
}
F_406 () ;
}
static inline bool F_418 ( const struct V_779 * V_780 )
{
unsigned int V_781 , V_782 ;
V_781 = F_419 ( F_420 ( V_780 -> V_783 ) ) ;
V_782 = V_781 & ~ ( V_784 | V_785 ) ;
return V_782 != 0 ;
}
static void F_421 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 = 0 , V_786 = 0 , V_787 = 0 ;
#ifndef F_16
int V_788 = 0 ;
#endif
if ( F_381 () ) {
V_13 -> V_188 . V_734 = 0 ;
V_13 -> V_188 . V_764 = 0 ;
} else if ( F_422 ( V_13 ) && F_423 ( V_13 ) ) {
V_13 -> V_188 . V_734 = 0 ;
V_13 -> V_188 . V_764 = 0 ;
}
V_786 += F_418 ( & F_84 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_16
if ( V_13 -> V_188 . V_695 * 8 > V_789 ) {
F_11 ( V_13 -> V_30 , L_84 ,
V_789 , V_13 -> V_188 . V_695 * 8 ) ;
F_424 ( 1 ) ;
}
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_787 ;
V_11 -> V_20 = 8 ;
V_787 += V_11 -> V_20 ;
}
#else
if ( V_786 )
V_788 = ( V_789 - ( V_13 -> V_188 . V_695 - V_786 ) ) / V_786 ;
if ( V_788 > F_425 () )
V_788 = F_425 () ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_787 ;
V_11 -> V_20 = F_418 ( & V_11 -> V_7 ) ? V_788 : 1 ;
V_787 += V_11 -> V_20 ;
}
#endif
V_4 -> V_790 = V_787 ;
V_4 -> V_791 = V_787 ;
if ( F_422 ( V_13 ) ) {
if ( V_786 ) {
V_19 = F_426 ( int , V_792 , F_427 () ) ;
V_4 -> V_793 = F_428 ( V_19 , V_13 -> V_188 . V_695 ) ;
} else {
V_4 -> V_793 = V_13 -> V_188 . V_695 ;
}
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_148 ) ; V_19 ++ ) {
struct V_153 * V_794 = & V_4 -> V_148 [ V_19 ] ;
F_429 ( V_13 , & V_794 -> V_149 , 5 , 10 , 1024 , 64 ) ;
V_794 -> V_181 . V_264 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_264 = 1024 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_187 ) ; V_19 ++ )
V_4 -> V_187 [ V_19 ] . V_25 . V_264 = 512 ;
F_429 ( V_13 , & V_4 -> V_147 , 0 , 1 , 1024 , 64 ) ;
F_429 ( V_13 , & V_4 -> V_174 , 0 , 1 , 512 , 64 ) ;
}
static void F_430 ( struct V_12 * V_13 , int V_140 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_140 < V_13 -> V_16 . V_790 )
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_790 -- ;
if ( V_13 -> V_16 . V_790 <= V_140 )
break;
}
}
V_140 = 0 ;
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_140 ;
V_140 += V_11 -> V_20 ;
}
}
static int F_431 ( struct V_12 * V_13 )
{
struct V_795 * V_141 ;
unsigned int V_796 = 0 ;
if ( F_161 ( V_13 ) )
V_796 += V_792 * V_13 -> V_735 ;
if ( F_432 ( V_13 ) )
V_796 += V_792 * V_13 -> V_766 ;
if ( ! V_796 )
goto V_59;
V_141 = F_394 ( V_796 , sizeof( * V_141 ) , V_156 ) ;
if ( ! V_141 )
return - V_61 ;
V_13 -> V_797 . V_798 = F_394 ( F_157 ( V_796 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_797 . V_798 ) {
F_34 ( V_141 ) ;
return - V_61 ;
}
F_159 ( & V_13 -> V_797 . V_799 ) ;
V_13 -> V_800 = V_141 ;
V_59:
return 0 ;
}
static void F_433 ( struct V_12 * V_13 )
{
if ( ! ( V_13 -> V_766 && V_13 -> V_735 ) )
return;
F_34 ( V_13 -> V_800 ) ;
F_34 ( V_13 -> V_797 . V_798 ) ;
}
static int F_434 ( struct V_12 * V_13 )
{
int V_801 = 0 , V_802 = 0 ;
int V_19 , V_138 , V_803 , V_804 , V_805 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_806 = V_13 -> V_188 . V_695 ;
struct V_807 * V_808 ;
int V_796 = V_610 ;
if ( F_432 ( V_13 ) )
V_796 += ( V_792 * V_13 -> V_766 ) ;
if ( F_161 ( V_13 ) )
V_796 += ( V_792 * V_13 -> V_735 ) ;
V_808 = F_80 ( sizeof( * V_808 ) * ( V_796 + 1 ) ,
V_156 ) ;
if ( ! V_808 )
return - V_61 ;
if ( F_431 ( V_13 ) ) {
V_13 -> V_188 . V_734 = 0 ;
V_13 -> V_188 . V_764 = 0 ;
}
for ( V_19 = 0 ; V_19 < V_796 + 1 ; ++ V_19 )
V_808 [ V_19 ] . V_49 = V_19 ;
V_803 = V_4 -> V_791 + V_809 ;
if ( F_161 ( V_13 ) ) {
V_803 += V_13 -> V_735 * V_4 -> V_793 ;
V_801 = V_13 -> V_735 * V_806 ;
}
if ( F_432 ( V_13 ) ) {
V_803 += V_13 -> V_766 * V_4 -> V_793 ;
V_802 = V_13 -> V_766 * V_806 ;
}
#ifdef F_16
V_804 = 8 * V_13 -> V_188 . V_695 + V_809 + V_801 + V_802 ;
#else
V_804 = V_13 -> V_188 . V_695 + V_809 + V_801 + V_802 ;
#endif
V_805 = F_435 ( V_13 -> V_128 , V_808 , V_804 , V_803 ) ;
if ( V_805 < 0 ) {
F_303 ( V_13 -> V_30 , L_85
L_86 ) ;
F_34 ( V_808 ) ;
return V_805 ;
}
V_19 = V_805 - V_809 - V_801 - V_802 ;
if ( V_19 < V_4 -> V_791 ) {
V_4 -> V_791 = V_19 ;
if ( V_19 < V_4 -> V_790 )
F_430 ( V_13 , V_19 ) ;
}
if ( F_422 ( V_13 ) ) {
if ( V_805 < V_803 )
V_4 -> V_810 = V_806 ;
else
V_4 -> V_810 = V_4 -> V_793 ;
}
for ( V_19 = 0 ; V_19 < ( V_4 -> V_791 + V_809 ) ; ++ V_19 )
V_13 -> V_141 [ V_19 ] . V_46 = V_808 [ V_19 ] . V_811 ;
if ( F_422 ( V_13 ) ) {
for ( V_138 = 0 ; V_19 < V_805 ; ++ V_19 , V_138 ++ ) {
V_13 -> V_800 [ V_138 ] . V_46 = V_808 [ V_19 ] . V_811 ;
V_13 -> V_800 [ V_138 ] . V_184 = V_19 ;
}
V_13 -> V_797 . V_812 = V_138 ;
}
F_303 ( V_13 -> V_30 , L_87
L_88 ,
V_805 , V_4 -> V_791 , V_4 -> V_810 ) ;
F_34 ( V_808 ) ;
return 0 ;
}
static int F_436 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_437 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_152 = F_394 ( V_11 -> V_155 , sizeof( T_6 ) , V_156 ) ;
if ( ! V_11 -> V_152 )
return - V_61 ;
}
return 0 ;
}
static int F_438 ( struct V_12 * V_13 ,
enum V_813 * V_8 ,
enum V_814 * V_815 )
{
T_1 V_816 , V_817 ;
int V_818 , V_819 ;
#define F_439 4
* V_8 = V_820 ;
* V_815 = V_821 ;
V_818 = F_440 ( V_13 -> V_128 , V_822 ,
& V_816 ) ;
V_819 = F_440 ( V_13 -> V_128 , V_823 ,
& V_817 ) ;
if ( ! V_819 && V_817 ) {
if ( V_817 & V_824 )
* V_8 = V_825 ;
else if ( V_817 & V_826 )
* V_8 = V_827 ;
else if ( V_817 & V_828 )
* V_8 = V_829 ;
}
if ( ! V_818 ) {
* V_815 = ( V_816 & V_830 ) >> F_439 ;
if ( ! V_817 ) {
if ( V_816 & V_831 )
* V_8 = V_827 ;
else if ( V_816 & V_832 )
* V_8 = V_829 ;
}
}
if ( * V_8 == V_820 || * V_815 == V_821 )
return V_818 ? V_818 : V_819 ? V_819 : - V_65 ;
return 0 ;
}
static void F_441 ( struct V_12 * V_13 )
{
enum V_814 V_815 , V_833 ;
enum V_813 V_8 , V_834 ;
#define F_442 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_438 ( V_13 , & V_834 , & V_833 ) ) {
F_361 ( V_13 -> V_30 ,
L_89 ) ;
return;
}
if ( F_443 ( V_13 -> V_128 , & V_8 , & V_815 ) ||
V_8 == V_820 || V_815 == V_821 ) {
F_361 ( V_13 -> V_30 ,
L_90 ) ;
return;
}
F_303 ( V_13 -> V_30 , L_91 ,
F_442 ( V_8 ) , F_442 ( V_834 ) ) ;
F_303 ( V_13 -> V_30 , L_92 ,
V_815 , V_833 ) ;
if ( V_8 < V_834 || V_815 < V_833 )
F_303 ( V_13 -> V_30 ,
L_93
L_94 ) ;
}
static void F_444 ( struct V_12 * V_12 )
{
F_303 ( V_12 -> V_30 , L_95 ,
V_12 -> V_188 . V_531 . V_544 ,
F_445 ( V_12 -> V_188 . V_189 ) ) ;
F_303 ( V_12 -> V_30 , L_96 ,
V_12 -> V_188 . V_531 . V_835 , V_12 -> V_188 . V_531 . V_836 ) ;
if ( ! V_12 -> V_188 . V_682 )
F_361 ( V_12 -> V_30 , L_97 ) ;
else
F_303 ( V_12 -> V_30 , L_98 ,
F_446 ( V_12 -> V_188 . V_682 ) ,
F_447 ( V_12 -> V_188 . V_682 ) ,
F_448 ( V_12 -> V_188 . V_682 ) ,
F_449 ( V_12 -> V_188 . V_682 ) ) ;
if ( ! V_12 -> V_188 . V_683 )
F_303 ( V_12 -> V_30 , L_99 ) ;
else
F_303 ( V_12 -> V_30 , L_100 ,
F_446 ( V_12 -> V_188 . V_683 ) ,
F_447 ( V_12 -> V_188 . V_683 ) ,
F_448 ( V_12 -> V_188 . V_683 ) ,
F_449 ( V_12 -> V_188 . V_683 ) ) ;
if ( ! V_12 -> V_188 . V_684 )
F_361 ( V_12 -> V_30 , L_101 ) ;
else
F_303 ( V_12 -> V_30 ,
L_102 ,
F_446 ( V_12 -> V_188 . V_684 ) ,
F_447 ( V_12 -> V_188 . V_684 ) ,
F_448 ( V_12 -> V_188 . V_684 ) ,
F_449 ( V_12 -> V_188 . V_684 ) ) ;
if ( ! V_12 -> V_188 . V_685 )
F_303 ( V_12 -> V_30 , L_103 ) ;
else
F_303 ( V_12 -> V_30 ,
L_104 ,
F_446 ( V_12 -> V_188 . V_685 ) ,
F_447 ( V_12 -> V_188 . V_685 ) ,
F_448 ( V_12 -> V_188 . V_685 ) ,
F_449 ( V_12 -> V_188 . V_685 ) ) ;
F_303 ( V_12 -> V_30 , L_105 ,
F_161 ( V_12 ) ? L_106 : L_107 ,
( ( V_12 -> V_68 & V_127 ) ? L_108 :
( V_12 -> V_68 & V_129 ) ? L_109 : L_107 ) ,
F_161 ( V_12 ) ? L_110 : L_111 ) ;
}
static void F_450 ( const struct V_1 * V_2 )
{
char V_672 [ 80 ] ;
char * V_837 = V_672 ;
const char * V_838 = L_107 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_188 . V_839 . V_8 == V_840 )
V_838 = L_112 ;
else if ( V_13 -> V_188 . V_839 . V_8 == V_841 )
V_838 = L_113 ;
else if ( V_13 -> V_188 . V_839 . V_8 == V_842 )
V_838 = L_114 ;
if ( V_11 -> V_7 . V_783 & V_784 )
V_837 += sprintf ( V_837 , L_115 ) ;
if ( V_11 -> V_7 . V_783 & V_785 )
V_837 += sprintf ( V_837 , L_116 ) ;
if ( V_11 -> V_7 . V_783 & V_843 )
V_837 += sprintf ( V_837 , L_117 ) ;
if ( V_11 -> V_7 . V_783 & V_844 )
V_837 += sprintf ( V_837 , L_118 ) ;
if ( V_11 -> V_7 . V_783 & V_845 )
V_837 += sprintf ( V_837 , L_119 ) ;
if ( V_11 -> V_7 . V_783 & V_846 )
V_837 += sprintf ( V_837 , L_120 ) ;
if ( V_837 != V_672 )
-- V_837 ;
sprintf ( V_837 , L_121 , F_451 ( V_11 -> V_847 ) ) ;
F_3 ( V_2 , L_122 ,
V_2 -> V_9 , V_13 -> V_188 . V_531 . V_544 , V_13 -> V_9 , V_672 ) ;
}
static void F_452 ( struct V_316 * V_2 )
{
F_453 ( V_2 , V_848 , V_849 ) ;
}
static void F_454 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_388 ( V_12 -> V_850 ) ;
F_455 ( V_12 ) ;
F_388 ( V_12 -> V_246 . V_245 ) ;
F_456 ( V_12 ) ;
F_34 ( V_12 -> V_16 . V_98 ) ;
F_34 ( V_12 -> V_16 . V_164 ) ;
F_34 ( V_12 -> V_16 . V_171 ) ;
F_34 ( V_12 -> V_16 . V_173 ) ;
#ifdef F_125
F_34 ( V_12 -> V_16 . V_708 ) ;
#endif
F_64 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] ) {
struct V_5 * V_11 = F_84 ( V_12 , V_19 ) ;
if ( V_11 -> V_51 != 0 )
F_457 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_51 ) ;
F_34 ( F_84 ( V_12 , V_19 ) -> V_152 ) ;
F_458 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_12 -> V_68 & V_769 )
F_402 ( V_12 , V_12 -> V_28 ) ;
}
static int F_459 ( struct V_316 * V_128 , T_1 V_851 )
{
T_6 V_852 ;
F_460 ( V_128 , V_853 , & V_852 ) ;
switch ( V_852 >> 12 ) {
case V_660 :
return F_461 ( V_660 , V_851 ) ;
case V_270 :
return F_461 ( V_270 , V_851 ) ;
case V_663 :
return F_461 ( V_663 , V_851 ) ;
default:
F_11 ( & V_128 -> V_2 , L_57 ,
V_852 ) ;
}
return - V_65 ;
}
static void F_462 ( struct V_1 * V_2 )
{
V_2 -> type = V_854 ;
V_2 -> V_66 = 0 ;
V_2 -> V_855 = 0 ;
V_2 -> V_548 = 0 ;
V_2 -> V_856 = 0 ;
V_2 -> V_68 |= V_857 ;
V_2 -> V_858 |= V_859 ;
V_2 -> V_860 = & V_861 ;
V_2 -> V_862 = & V_863 ;
V_2 -> V_864 = true ;
}
static int F_463 ( struct V_316 * V_128 )
{
struct V_12 * V_13 = F_188 ( V_128 ) ;
struct V_1 * V_52 ;
struct V_5 * V_11 ;
char V_9 [ V_865 ] ;
int V_22 ;
snprintf ( V_9 , V_865 , L_123 , V_13 -> V_542 , V_13 -> V_28 ) ;
V_52 = F_464 ( sizeof( struct V_5 ) , V_9 , V_866 ,
F_462 ) ;
if ( ! V_52 )
return - V_61 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_13 ;
V_11 -> V_31 = V_13 -> V_28 % V_13 -> V_188 . V_695 ;
F_465 ( V_52 , & V_128 -> V_2 ) ;
V_13 -> V_39 [ 0 ] = V_52 ;
V_22 = F_466 ( V_13 -> V_39 [ 0 ] ) ;
if ( V_22 ) {
F_5 ( L_124 , V_9 ) ;
F_458 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
return V_22 ;
}
return 0 ;
}
static int F_467 ( struct V_316 * V_128 , int V_532 )
{
struct V_12 * V_13 = F_188 ( V_128 ) ;
int V_22 = 0 ;
int V_867 = F_468 ( V_128 ) ;
T_1 V_868 ;
V_868 = F_469 ( V_13 -> V_778 + V_869 ) ;
if ( ! ( V_868 & V_870 ) ||
! ( V_868 & V_871 ) ||
F_470 ( V_868 ) != 4 ) {
F_361 ( & V_128 -> V_2 ,
L_125 ) ;
return - V_508 ;
}
if ( V_867 && F_471 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 ,
L_126 ) ;
V_532 = V_867 ;
return V_532 ;
}
if ( ! V_532 ) {
F_472 ( V_128 ) ;
if ( V_13 -> V_39 [ 0 ] ) {
F_473 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
}
F_34 ( V_13 -> V_533 ) ;
V_13 -> V_533 = NULL ;
V_13 -> V_532 = 0 ;
return V_532 ;
}
if ( V_532 != V_867 ) {
V_22 = F_474 ( V_128 , V_532 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_532 = V_532 ;
V_22 = F_463 ( V_128 ) ;
if ( V_22 )
return V_22 ;
}
V_13 -> V_533 = F_394 ( V_13 -> V_532 ,
sizeof( struct V_872 ) , V_156 ) ;
if ( V_13 -> V_533 )
F_298 ( V_13 ) ;
return V_532 ;
}
static int F_475 ( struct V_316 * V_128 , const struct V_873 * V_874 )
{
int V_875 , V_19 , V_22 , V_876 , V_877 , V_878 ;
struct V_5 * V_11 ;
bool V_879 = false ;
struct V_12 * V_12 = NULL ;
struct V_1 * V_52 ;
void T_16 * V_778 ;
T_1 V_880 , V_851 ;
enum V_308 V_189 ;
static int V_542 = 1 ;
#ifdef F_476
T_1 V_132 , V_678 ;
#endif
F_477 ( V_881 L_127 , V_882 , V_883 ) ;
V_22 = F_478 ( V_128 , V_884 ) ;
if ( V_22 ) {
F_303 ( & V_128 -> V_2 , L_128 ) ;
return V_22 ;
}
V_22 = F_411 ( V_128 ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_129 ) ;
goto V_885;
}
V_778 = F_479 ( V_128 , 0 ) ;
if ( ! V_778 ) {
F_11 ( & V_128 -> V_2 , L_130 ) ;
V_22 = - V_61 ;
goto V_886;
}
V_22 = F_414 ( V_778 ) ;
if ( V_22 < 0 )
goto V_887;
V_880 = F_469 ( V_778 + V_888 ) ;
V_851 = F_480 ( F_469 ( V_778 + V_889 ) ) ;
V_189 = F_459 ( V_128 , V_851 ) ;
V_875 = F_162 ( V_189 ) <= V_270 ?
F_481 ( V_880 ) : F_482 ( V_880 ) ;
if ( V_875 != V_874 -> V_890 ) {
#ifndef F_476
F_483 ( V_778 ) ;
#endif
F_407 ( V_128 ) ;
F_410 ( V_128 ) ;
goto V_891;
}
if ( ! F_484 ( V_128 , F_485 ( 64 ) ) ) {
V_879 = true ;
V_22 = F_486 ( V_128 , F_485 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_131
L_132 ) ;
goto V_887;
}
} else {
V_22 = F_484 ( V_128 , F_485 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_133 ) ;
goto V_887;
}
}
F_487 ( V_128 ) ;
F_452 ( V_128 ) ;
F_412 ( V_128 ) ;
F_410 ( V_128 ) ;
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_887;
}
V_542 ++ ;
V_12 -> V_251 = F_488 ( L_134 ) ;
if ( ! V_12 -> V_251 ) {
V_22 = - V_61 ;
goto V_892;
}
V_12 -> V_893 = F_27 ( sizeof( * V_12 -> V_893 ) +
( sizeof( struct V_894 ) *
V_895 ) ,
V_156 ) ;
if ( ! V_12 -> V_893 ) {
V_22 = - V_61 ;
goto V_892;
}
V_12 -> V_893 -> V_264 = V_895 ;
V_12 -> V_68 |= V_773 ;
V_12 -> V_778 = V_778 ;
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_320 ( V_128 ) ;
V_12 -> V_27 = V_875 ;
V_12 -> V_28 = V_875 ;
V_12 -> V_896 = V_897 ;
memset ( V_12 -> V_81 , 0xff , sizeof( V_12 -> V_81 ) ) ;
F_159 ( & V_12 -> V_320 ) ;
F_159 ( & V_12 -> V_247 ) ;
F_159 ( & V_12 -> V_329 ) ;
F_159 ( & V_12 -> V_898 ) ;
F_268 ( & V_12 -> V_899 . V_62 ) ;
F_489 ( & V_12 -> V_252 , F_149 ) ;
F_489 ( & V_12 -> V_395 , F_238 ) ;
F_489 ( & V_12 -> V_402 , F_243 ) ;
V_22 = F_490 ( V_12 ) ;
if ( V_22 )
goto V_892;
if ( ! F_104 ( V_12 -> V_188 . V_189 ) ) {
V_876 = ( V_900 +
( V_901 - V_900 ) *
V_12 -> V_28 ) ;
V_877 = 1 << F_491 ( F_68 ( V_12 ,
V_902 ) >> V_876 ) ;
V_878 = V_626 / V_903 ;
if ( V_877 > V_878 ) {
F_11 ( & V_128 -> V_2 ,
L_135 ) ;
V_22 = - V_65 ;
goto V_892;
}
V_12 -> V_408 = F_492 ( F_493 ( V_128 , 2 ) ,
F_494 ( V_128 , 2 ) ) ;
if ( ! V_12 -> V_408 ) {
F_11 ( & V_128 -> V_2 , L_136 ) ;
V_22 = - V_61 ;
goto V_892;
}
}
F_325 ( V_12 ) ;
V_22 = F_378 ( V_12 ) ;
#ifdef F_125
F_96 ( V_12 -> V_16 . V_708 , V_12 -> V_16 . V_172 ) ;
#endif
F_328 ( V_12 ) ;
if ( V_22 )
goto V_904;
if ( ! F_104 ( V_12 -> V_188 . V_189 ) )
F_70 ( V_12 , V_905 , F_495 ( 7 ) |
( F_211 ( V_12 -> V_188 . V_189 ) ? F_496 ( 0 ) :
F_497 ( 0 ) ) ) ;
F_73 (adapter, i) {
V_52 = F_498 ( sizeof( struct V_5 ) ,
V_789 ) ;
if ( ! V_52 ) {
V_22 = - V_61 ;
goto V_906;
}
F_465 ( V_52 , & V_128 -> V_2 ) ;
V_12 -> V_39 [ V_19 ] = V_52 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_74 = - 1 ;
V_11 -> V_31 = V_19 ;
V_52 -> V_130 = V_128 -> V_130 ;
V_52 -> V_907 = V_908 | V_909 |
V_910 | V_911 |
V_912 | V_913 |
V_914 | V_73 |
V_915 ;
if ( V_879 )
V_52 -> V_907 |= V_916 ;
V_52 -> V_72 |= V_52 -> V_907 ;
V_52 -> V_917 = V_52 -> V_72 & V_918 ;
V_52 -> V_858 |= V_919 ;
V_52 -> V_920 = 81 ;
V_52 -> V_303 = V_921 ;
V_52 -> V_860 = & V_922 ;
#ifdef F_16
V_52 -> V_923 = & V_924 ;
F_17 ( V_52 ) ;
#endif
F_499 ( V_52 ) ;
}
F_500 ( V_128 , V_12 ) ;
if ( V_12 -> V_68 & V_769 ) {
V_22 = F_501 ( V_12 , V_875 , V_875 , 0 ) ;
if ( V_22 )
goto V_906;
} else if ( V_12 -> V_188 . V_695 == 1 ) {
T_3 V_525 [ V_526 ] ;
T_3 * V_528 = V_12 -> V_188 . V_531 . V_528 ;
V_22 = F_299 ( V_12 , & V_12 -> V_188 . V_531 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_526 ; V_19 ++ )
V_525 [ V_19 ] = ( F_300 ( V_528 [ 2 * V_19 + 0 ] ) * 16 +
F_300 ( V_528 [ 2 * V_19 + 1 ] ) ) ;
F_502 ( V_12 , 0 , V_525 ) ;
}
}
F_421 ( V_12 ) ;
V_12 -> V_850 = F_503 ( V_12 -> V_704 , V_12 -> V_705 ) ;
if ( ! V_12 -> V_850 ) {
F_361 ( & V_128 -> V_2 , L_137 ) ;
V_12 -> V_188 . V_734 = 0 ;
}
#if F_257 ( V_438 )
if ( ( F_162 ( V_12 -> V_188 . V_189 ) <= V_270 ) &&
( ! ( F_68 ( V_12 , V_925 ) & V_926 ) ) ) {
F_361 ( & V_128 -> V_2 ,
L_138 ) ;
V_12 -> V_188 . V_734 = 0 ;
} else {
V_12 -> V_927 = F_504 ( V_12 -> V_711 ,
V_12 -> V_712 ) ;
if ( ! V_12 -> V_927 ) {
F_361 ( & V_128 -> V_2 ,
L_139 ) ;
V_12 -> V_188 . V_734 = 0 ;
}
}
#endif
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_11 -> V_928 = F_505 ( V_12 -> V_188 . V_713 ) ;
if ( ! V_11 -> V_928 )
F_361 ( & V_128 -> V_2 ,
L_140 ,
V_19 ) ;
}
if ( F_156 ( & V_12 -> V_246 ) < 0 ) {
F_361 ( & V_128 -> V_2 , L_141
L_142 ) ;
V_12 -> V_188 . V_734 = 0 ;
} else {
V_12 -> V_929 = F_506 ( V_12 ) ;
if ( ! V_12 -> V_929 )
F_361 ( & V_128 -> V_2 ,
L_143 ) ;
}
if ( F_161 ( V_12 ) ) {
if ( F_68 ( V_12 , V_925 ) & V_930 ) {
T_1 V_256 , V_931 ;
if ( V_189 <= V_270 ) {
V_931 = V_932 ;
V_256 = F_68 ( V_12 , V_931 ) ;
V_12 -> V_246 . V_256 = V_256 / 4 ;
} else {
V_931 = V_933 ;
V_256 = F_68 ( V_12 , V_931 ) ;
V_12 -> V_246 . V_256 = V_256 ;
}
}
}
if ( V_934 > 1 && F_434 ( V_12 ) == 0 )
V_12 -> V_68 |= V_127 ;
else if ( V_934 > 0 && F_507 ( V_128 ) == 0 ) {
V_12 -> V_68 |= V_129 ;
if ( V_934 > 1 )
F_433 ( V_12 ) ;
}
F_441 ( V_12 ) ;
V_22 = F_436 ( V_12 ) ;
if ( V_22 )
goto V_906;
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_12 -> V_39 [ V_19 ] -> V_935 = V_11 -> V_444 ;
F_508 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_509 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_466 ( V_12 -> V_39 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_81 [ V_11 -> V_76 ] = V_19 ;
F_450 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_128 -> V_2 , L_144 ) ;
goto V_906;
}
if ( V_22 ) {
F_361 ( & V_128 -> V_2 , L_145 , V_19 ) ;
V_22 = 0 ;
}
if ( V_936 ) {
V_12 -> V_217 = F_510 ( F_320 ( V_128 ) ,
V_936 ) ;
F_123 ( V_12 ) ;
}
V_128 -> V_937 = 1 ;
if ( F_422 ( V_12 ) ) {
F_250 ( & V_415 ) ;
F_29 ( & V_12 -> V_416 , & V_419 ) ;
F_254 ( & V_415 ) ;
}
F_444 ( V_12 ) ;
F_95 ( V_12 ) ;
return 0 ;
V_891:
#ifdef F_476
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_938;
}
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_320 ( V_128 ) ;
V_12 -> V_27 = V_875 ;
V_12 -> V_28 = V_875 ;
V_12 -> V_778 = V_778 ;
V_12 -> V_542 = V_542 ;
V_12 -> V_893 = F_27 ( sizeof( * V_12 -> V_893 ) +
( sizeof( struct V_894 ) *
V_895 ) ,
V_156 ) ;
if ( ! V_12 -> V_893 ) {
V_22 = - V_61 ;
goto V_939;
}
F_159 ( & V_12 -> V_898 ) ;
F_268 ( & V_12 -> V_899 . V_62 ) ;
V_132 = F_7 ( V_667 ) |
F_8 ( V_694 ) ;
V_22 = F_371 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 ,
& V_132 , & V_678 ) ;
if ( V_22 < 0 ) {
F_11 ( V_12 -> V_30 , L_146 ) ;
goto V_939;
}
V_12 -> V_188 . V_695 = F_390 ( V_678 ) ;
F_500 ( V_128 , V_12 ) ;
return 0 ;
V_939:
F_34 ( V_12 ) ;
V_938:
F_483 ( V_778 ) ;
F_472 ( V_128 ) ;
F_511 ( V_128 ) ;
return V_22 ;
#else
return 0 ;
#endif
V_906:
F_454 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_433 ( V_12 ) ;
if ( V_12 -> V_766 || V_12 -> V_735 )
F_512 ( V_12 ) ;
V_904:
if ( ! F_104 ( V_12 -> V_188 . V_189 ) )
F_483 ( V_12 -> V_408 ) ;
V_892:
if ( V_12 -> V_251 )
F_513 ( V_12 -> V_251 ) ;
F_34 ( V_12 -> V_893 ) ;
F_34 ( V_12 ) ;
V_887:
F_483 ( V_778 ) ;
V_886:
F_514 ( V_128 ) ;
F_407 ( V_128 ) ;
V_885:
F_511 ( V_128 ) ;
return V_22 ;
}
static void F_515 ( struct V_316 * V_128 )
{
struct V_12 * V_12 = F_188 ( V_128 ) ;
if ( ! V_12 ) {
F_511 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_513 ( V_12 -> V_251 ) ;
if ( F_422 ( V_12 ) )
F_249 ( V_12 ) ;
F_89 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_940 == V_941 )
F_473 ( V_12 -> V_39 [ V_19 ] ) ;
F_516 ( V_12 -> V_217 ) ;
F_517 ( V_12 ) ;
if ( V_12 -> V_68 & V_168 )
F_269 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_433 ( V_12 ) ;
if ( V_12 -> V_766 || V_12 -> V_735 )
F_512 ( V_12 ) ;
F_454 ( V_12 ) ;
#if F_257 ( V_438 )
F_518 ( V_12 ) ;
#endif
F_483 ( V_12 -> V_778 ) ;
if ( ! F_104 ( V_12 -> V_188 . V_189 ) )
F_483 ( V_12 -> V_408 ) ;
F_514 ( V_128 ) ;
if ( ( V_12 -> V_68 & V_773 ) ) {
F_407 ( V_128 ) ;
V_12 -> V_68 &= ~ V_773 ;
}
F_511 ( V_128 ) ;
F_34 ( V_12 -> V_893 ) ;
F_519 () ;
F_34 ( V_12 ) ;
}
#ifdef F_476
else {
if ( V_12 -> V_39 [ 0 ] )
F_473 ( V_12 -> V_39 [ 0 ] ) ;
F_483 ( V_12 -> V_778 ) ;
F_34 ( V_12 -> V_533 ) ;
F_34 ( V_12 ) ;
F_472 ( V_128 ) ;
F_511 ( V_128 ) ;
}
#endif
}
static void F_520 ( struct V_316 * V_128 )
{
struct V_12 * V_12 = F_188 ( V_128 ) ;
if ( ! V_12 ) {
F_511 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_940 == V_941 )
F_274 ( V_12 -> V_39 [ V_19 ] ) ;
F_521 ( V_12 ) ;
F_89 ( V_12 ) ;
F_64 ( V_12 ) ;
F_271 ( V_12 ) ;
if ( V_12 -> V_68 & V_769 )
F_402 ( V_12 , V_12 -> V_27 ) ;
}
#ifdef F_476
else {
if ( V_12 -> V_39 [ 0 ] )
F_473 ( V_12 -> V_39 [ 0 ] ) ;
F_483 ( V_12 -> V_778 ) ;
F_34 ( V_12 -> V_533 ) ;
F_34 ( V_12 ) ;
F_472 ( V_128 ) ;
F_511 ( V_128 ) ;
}
#endif
}
static int T_17 F_522 ( void )
{
int V_54 ;
V_936 = F_510 ( V_884 , NULL ) ;
if ( ! V_936 )
F_523 ( L_147 ) ;
V_54 = F_524 ( & V_375 ) ;
if ( V_54 < 0 )
F_525 ( V_936 ) ;
#if F_257 ( V_438 )
if ( ! V_942 ) {
F_526 ( & V_943 ) ;
V_942 = true ;
}
#endif
return V_54 ;
}
static void T_18 F_527 ( void )
{
#if F_257 ( V_438 )
if ( V_942 ) {
F_528 ( & V_943 ) ;
V_942 = false ;
}
#endif
F_529 ( & V_375 ) ;
F_525 ( V_936 ) ;
}
