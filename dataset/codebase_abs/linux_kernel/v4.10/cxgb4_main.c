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
NULL , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
const struct V_1 * V_2 = V_13 -> V_39 [ V_31 ] ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_11 -> V_41 == V_42 )
F_3 ( V_2 , L_21 ) ;
else if ( V_11 -> V_41 < F_20 ( V_40 ) )
F_3 ( V_2 , L_22 , V_40 [ V_11 -> V_41 ] ) ;
else if ( V_11 -> V_41 == V_43 )
F_3 ( V_2 , L_23 ,
V_2 -> V_9 ) ;
else if ( V_11 -> V_41 == V_44 )
F_3 ( V_2 , L_24 ,
V_2 -> V_9 ) ;
else if ( V_11 -> V_41 == V_45 )
F_3 ( V_2 , L_25 , V_2 -> V_9 ) ;
else
F_3 ( V_2 , L_26 ,
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
F_11 ( V_25 -> V_13 -> V_30 , L_27
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
L_28 , V_88 ) ;
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
snprintf ( V_13 -> V_141 [ 0 ] . V_142 , V_140 , L_29 , V_13 -> V_39 [ 0 ] -> V_9 ) ;
snprintf ( V_13 -> V_141 [ 1 ] . V_142 , V_140 , L_30 ,
V_13 -> V_39 [ 0 ] -> V_9 ) ;
F_73 (adap, j) {
struct V_1 * V_143 = V_13 -> V_39 [ V_138 ] ;
const struct V_5 * V_11 = F_4 ( V_143 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_139 ++ )
snprintf ( V_13 -> V_141 [ V_139 ] . V_142 , V_140 , L_31 ,
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
if ( V_25 && V_25 -> V_166 ) {
F_88 ( & V_25 -> V_167 ) ;
F_43 () ;
while ( ! F_89 ( V_25 ) )
F_90 ( 1 ) ;
F_45 () ;
}
}
}
static void F_91 ( struct V_12 * V_13 )
{
if ( V_13 -> V_68 & V_168 ) {
F_92 ( V_13 ) ;
if ( V_13 -> V_68 & V_127 ) {
F_78 ( V_13 ) ;
F_77 ( V_13 -> V_141 [ 0 ] . V_46 , V_13 ) ;
} else {
F_77 ( V_13 -> V_128 -> V_130 , V_13 ) ;
}
F_87 ( V_13 ) ;
}
}
static void F_93 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_165 ; V_19 ++ ) {
struct V_84 * V_25 = V_13 -> V_16 . V_164 [ V_19 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_166 ) {
F_94 ( V_25 ) ;
F_95 ( & V_25 -> V_167 ) ;
}
F_70 ( V_13 , F_69 ( V_169 ) ,
F_96 ( V_25 -> V_170 ) |
F_97 ( V_25 -> V_26 ) ) ;
}
}
static int F_98 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 = 0 ;
F_99 ( V_4 -> V_171 , V_4 -> V_172 ) ;
F_99 ( V_4 -> V_173 , V_4 -> V_172 ) ;
if ( V_13 -> V_68 & V_127 )
V_13 -> V_139 = 1 ;
else {
V_22 = F_100 ( V_13 , & V_4 -> V_174 , false , V_13 -> V_39 [ 0 ] , 0 ,
NULL , NULL , NULL , - 1 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_139 = - ( ( int ) V_4 -> V_174 . V_157 + 1 ) ;
}
V_22 = F_100 ( V_13 , & V_4 -> V_147 , true , V_13 -> V_39 [ 0 ] ,
V_13 -> V_139 , NULL , F_50 , NULL , - 1 ) ;
if ( V_22 )
F_101 ( V_13 ) ;
return V_22 ;
}
static int F_102 ( struct V_12 * V_13 )
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
V_22 = F_100 ( V_13 , & V_25 -> V_149 , false , V_2 ,
V_13 -> V_139 , & V_25 -> V_181 ,
V_182 ,
NULL ,
F_103 ( V_13 ,
V_11 -> V_76 ) ) ;
if ( V_22 )
goto V_183;
V_25 -> V_149 . V_184 = V_138 ;
memset ( & V_25 -> V_185 , 0 , sizeof( V_25 -> V_185 ) ) ;
}
for ( V_138 = 0 ; V_138 < V_11 -> V_20 ; V_138 ++ , V_180 ++ ) {
V_22 = F_104 ( V_13 , V_180 , V_2 ,
F_105 ( V_2 , V_138 ) ,
V_4 -> V_147 . V_26 ) ;
if ( V_22 )
goto V_183;
}
}
F_73 (adap, i) {
if ( V_176 )
V_179 = V_176 -> V_186 [ V_19 ] . V_149 . V_26 ;
V_22 = F_106 ( V_13 , & V_4 -> V_187 [ V_19 ] , V_13 -> V_39 [ V_19 ] ,
V_4 -> V_147 . V_26 , V_179 ) ;
if ( V_22 )
goto V_183;
}
F_70 ( V_13 , F_107 ( V_13 -> V_188 . V_189 ) ?
V_190 :
V_191 ,
F_108 ( F_86 ( V_13 -> V_39 [ 0 ] ) -> V_76 ) |
F_109 ( V_4 -> V_148 [ 0 ] . V_149 . V_157 ) ) ;
return 0 ;
V_183:
F_101 ( V_13 ) ;
return V_22 ;
}
void * F_110 ( T_7 V_192 )
{
void * V_6 = F_27 ( V_192 , V_156 | V_193 ) ;
if ( ! V_6 )
V_6 = F_111 ( V_192 ) ;
return V_6 ;
}
void F_112 ( void * V_50 )
{
F_113 ( V_50 ) ;
}
static T_6 F_114 ( struct V_1 * V_2 , struct V_194 * V_195 ,
void * V_196 , T_8 V_197 )
{
int V_15 ;
#ifdef F_16
if ( F_12 ( V_2 ) ) {
T_6 V_198 ;
int V_22 ;
V_22 = F_115 ( V_195 , & V_198 ) ;
if ( F_51 ( V_22 ) ) {
if ( F_116 () )
F_117 ( V_2 ,
L_32 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_198 & V_199 ) >> V_200 ;
#ifdef F_118
if ( V_195 -> V_201 == F_119 ( V_202 ) )
V_15 = V_195 -> V_203 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_204 ) {
V_15 = ( F_120 ( V_195 )
? F_121 ( V_195 )
: F_122 () ) ;
while ( F_51 ( V_15 >= V_2 -> V_205 ) )
V_15 -= V_2 -> V_205 ;
return V_15 ;
}
return V_197 ( V_2 , V_195 ) % V_2 -> V_205 ;
}
static int F_123 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_206 , V_207 = 0 , V_208 = V_209 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_210 ) ; V_19 ++ ) {
V_206 = time - V_4 -> V_210 [ V_19 ] ;
if ( V_206 < 0 )
V_206 = - V_206 ;
if ( V_206 < V_208 ) {
V_208 = V_206 ;
V_207 = V_19 ;
}
}
return V_207 ;
}
static int F_124 ( const struct V_16 * V_4 , int V_211 )
{
int V_19 , V_206 , V_207 = 0 , V_208 = V_209 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_212 ) ; V_19 ++ ) {
V_206 = V_211 - V_4 -> V_212 [ V_19 ] ;
if ( V_206 < 0 )
V_206 = - V_206 ;
if ( V_206 < V_208 ) {
V_208 = V_206 ;
V_207 = V_19 ;
}
}
return V_207 ;
}
int F_125 ( struct V_84 * V_25 ,
unsigned int V_213 , unsigned int V_214 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_213 | V_214 ) == 0 )
V_214 = 1 ;
if ( V_214 ) {
int V_22 ;
T_1 V_132 , V_215 ;
V_215 = F_124 ( & V_13 -> V_16 , V_214 ) ;
if ( V_25 -> V_142 && V_25 -> V_216 != V_215 ) {
V_132 = F_7 ( V_23 ) |
F_8 (
V_217 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_126 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_132 , & V_215 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_216 = V_215 ;
}
V_213 = V_213 == 0 ? 6 : F_123 ( & V_13 -> V_16 , V_213 ) ;
V_25 -> V_170 = F_127 ( V_213 ) | F_128 ( V_214 > 0 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , T_9 V_72 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_9 V_218 = V_2 -> V_72 ^ V_72 ;
int V_22 ;
if ( ! ( V_218 & V_73 ) )
return 0 ;
V_22 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_72 & V_73 ) , true ) ;
if ( F_51 ( V_22 ) )
V_2 -> V_72 = V_72 ^ V_73 ;
return V_22 ;
}
static int F_130 ( struct V_12 * V_13 )
{
if ( F_131 ( V_13 -> V_219 ) )
return - 1 ;
#ifdef F_132
F_133 ( V_13 ) ;
#endif
return 0 ;
}
int F_134 ( struct V_220 * V_180 , void * V_109 )
{
int V_221 = - 1 ;
F_135 ( & V_180 -> V_222 ) ;
if ( V_180 -> V_223 ) {
union V_224 * V_6 = V_180 -> V_223 ;
V_221 = ( V_6 - V_180 -> V_225 ) + V_180 -> V_226 ;
V_180 -> V_223 = V_6 -> V_227 ;
V_6 -> V_109 = V_109 ;
V_180 -> V_228 ++ ;
}
F_136 ( & V_180 -> V_222 ) ;
return V_221 ;
}
void F_137 ( struct V_220 * V_180 , unsigned int V_221 )
{
union V_224 * V_6 = & V_180 -> V_225 [ V_221 - V_180 -> V_226 ] ;
F_135 ( & V_180 -> V_222 ) ;
V_6 -> V_227 = V_180 -> V_223 ;
V_180 -> V_223 = V_6 ;
V_180 -> V_228 -- ;
F_136 ( & V_180 -> V_222 ) ;
}
int F_138 ( struct V_220 * V_180 , int V_229 , void * V_109 )
{
int V_230 ;
F_135 ( & V_180 -> V_231 ) ;
if ( V_229 == V_232 ) {
V_230 = F_139 ( V_180 -> V_233 , V_180 -> V_234 ) ;
if ( V_230 < V_180 -> V_234 )
F_140 ( V_230 , V_180 -> V_233 ) ;
else
V_230 = - 1 ;
} else {
V_230 = F_141 ( V_180 -> V_233 , V_180 -> V_234 , 1 ) ;
if ( V_230 < 0 )
V_230 = - 1 ;
}
if ( V_230 >= 0 ) {
V_180 -> V_235 [ V_230 ] . V_109 = V_109 ;
V_230 += V_180 -> V_236 ;
if ( V_229 == V_232 )
V_180 -> V_237 ++ ;
else
V_180 -> V_237 += 2 ;
}
F_136 ( & V_180 -> V_231 ) ;
return V_230 ;
}
int F_142 ( struct V_220 * V_180 , int V_229 , void * V_109 )
{
int V_230 ;
F_135 ( & V_180 -> V_231 ) ;
if ( V_229 == V_232 ) {
V_230 = F_143 ( V_180 -> V_233 ,
V_180 -> V_234 + V_180 -> V_238 , V_180 -> V_234 ) ;
if ( V_230 < ( V_180 -> V_234 + V_180 -> V_238 ) )
F_140 ( V_230 , V_180 -> V_233 ) ;
else
V_230 = - 1 ;
} else {
V_230 = - 1 ;
}
if ( V_230 >= 0 ) {
V_180 -> V_235 [ V_230 ] . V_109 = V_109 ;
V_230 -= V_180 -> V_234 ;
V_230 += V_180 -> V_239 ;
V_180 -> V_240 ++ ;
}
F_136 ( & V_180 -> V_231 ) ;
return V_230 ;
}
void F_144 ( struct V_220 * V_180 , unsigned int V_230 , int V_229 )
{
if ( V_180 -> V_238 && ( V_230 >= V_180 -> V_239 ) ) {
V_230 -= V_180 -> V_239 ;
V_230 += V_180 -> V_234 ;
} else {
V_230 -= V_180 -> V_236 ;
}
F_135 ( & V_180 -> V_231 ) ;
if ( V_229 == V_232 )
F_145 ( V_230 , V_180 -> V_233 ) ;
else
F_146 ( V_180 -> V_233 , V_230 , 1 ) ;
V_180 -> V_235 [ V_230 ] . V_109 = NULL ;
if ( V_230 < V_180 -> V_234 ) {
if ( V_229 == V_232 )
V_180 -> V_237 -- ;
else
V_180 -> V_237 -= 2 ;
} else {
V_180 -> V_240 -- ;
}
F_136 ( & V_180 -> V_231 ) ;
}
static void F_147 ( struct V_194 * V_195 , unsigned int V_241 ,
unsigned int V_242 )
{
struct V_243 * V_244 ;
F_148 ( V_195 , V_245 , V_241 ) ;
V_244 = (struct V_243 * ) F_149 ( V_195 , sizeof( * V_244 ) ) ;
F_150 ( V_244 , V_242 ) ;
F_151 ( V_244 ) = F_152 ( F_153 ( V_246 , V_242 ) ) ;
}
static void F_154 ( struct V_220 * V_180 , unsigned int V_241 ,
unsigned int V_242 )
{
void * * V_6 = & V_180 -> V_247 [ V_242 ] ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_248 ) ;
F_135 ( & V_13 -> V_249 ) ;
* V_6 = V_13 -> V_250 ;
V_13 -> V_250 = ( void * * ) ( ( V_251 ) V_6 | V_241 ) ;
if ( ! V_13 -> V_252 ) {
V_13 -> V_252 = true ;
F_155 ( V_13 -> V_253 , & V_13 -> V_254 ) ;
}
F_136 ( & V_13 -> V_249 ) ;
}
static void F_156 ( struct V_255 * V_256 )
{
struct V_194 * V_195 ;
struct V_12 * V_13 ;
V_13 = F_54 ( V_256 , struct V_12 , V_254 ) ;
F_135 ( & V_13 -> V_249 ) ;
while ( V_13 -> V_250 ) {
void * * V_6 = V_13 -> V_250 ;
unsigned int V_241 = ( V_251 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_241 ;
V_13 -> V_250 = * V_6 ;
* V_6 = NULL ;
F_136 ( & V_13 -> V_249 ) ;
while ( ! ( V_195 = F_157 ( sizeof( struct V_243 ) ,
V_156 ) ) )
F_158 ( 1 ) ;
F_147 ( V_195 , V_241 , V_6 - V_13 -> V_248 . V_247 ) ;
F_159 ( V_13 , V_195 ) ;
F_135 ( & V_13 -> V_249 ) ;
}
V_13 -> V_252 = false ;
F_136 ( & V_13 -> V_249 ) ;
}
void F_160 ( struct V_220 * V_180 , unsigned int V_241 , unsigned int V_242 )
{
struct V_194 * V_195 ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_248 ) ;
F_161 ( V_242 >= V_180 -> V_257 ) ;
if ( V_180 -> V_247 [ V_242 ] ) {
V_180 -> V_247 [ V_242 ] = NULL ;
if ( V_180 -> V_258 && ( V_242 >= V_180 -> V_258 ) )
F_162 ( & V_180 -> V_259 ) ;
else
F_162 ( & V_180 -> V_260 ) ;
}
V_195 = F_157 ( sizeof( struct V_243 ) , V_60 ) ;
if ( F_52 ( V_195 ) ) {
F_147 ( V_195 , V_241 , V_242 ) ;
F_159 ( V_13 , V_195 ) ;
} else
F_154 ( V_180 , V_241 , V_242 ) ;
}
static int F_163 ( struct V_220 * V_180 )
{
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_248 ) ;
unsigned int V_261 = V_180 -> V_262 + V_180 -> V_238 ;
unsigned int V_263 = V_180 -> V_263 ;
unsigned int V_264 ;
unsigned int V_265 ;
T_7 V_192 ;
V_264 = F_164 ( V_180 -> V_234 + V_180 -> V_238 ) ;
V_265 = F_164 ( V_180 -> V_262 ) ;
V_192 = V_180 -> V_257 * sizeof( * V_180 -> V_247 ) +
V_263 * sizeof( * V_180 -> V_225 ) +
V_180 -> V_234 * sizeof( * V_180 -> V_235 ) +
V_180 -> V_238 * sizeof( * V_180 -> V_235 ) +
V_264 * sizeof( long ) +
V_261 * sizeof( * V_180 -> V_266 ) +
V_265 * sizeof( long ) ;
V_180 -> V_247 = F_110 ( V_192 ) ;
if ( ! V_180 -> V_247 )
return - V_61 ;
V_180 -> V_225 = (union V_224 * ) & V_180 -> V_247 [ V_180 -> V_257 ] ;
V_180 -> V_235 = (struct V_267 * ) & V_180 -> V_225 [ V_263 ] ;
V_180 -> V_233 = ( unsigned long * ) & V_180 -> V_235 [ V_180 -> V_234 + V_180 -> V_238 ] ;
V_180 -> V_266 = (struct V_268 * ) & V_180 -> V_233 [ V_264 ] ;
V_180 -> V_269 = ( unsigned long * ) & V_180 -> V_266 [ V_261 ] ;
F_165 ( & V_180 -> V_231 ) ;
F_165 ( & V_180 -> V_222 ) ;
F_165 ( & V_180 -> V_270 ) ;
V_180 -> V_237 = 0 ;
V_180 -> V_240 = 0 ;
V_180 -> V_223 = NULL ;
V_180 -> V_228 = 0 ;
F_166 ( & V_180 -> V_260 , 0 ) ;
F_166 ( & V_180 -> V_259 , 0 ) ;
if ( V_263 ) {
while ( -- V_263 )
V_180 -> V_225 [ V_263 - 1 ] . V_227 = & V_180 -> V_225 [ V_263 ] ;
V_180 -> V_223 = V_180 -> V_225 ;
}
if ( F_167 ( V_13 ) ) {
F_99 ( V_180 -> V_233 , V_180 -> V_234 + V_180 -> V_238 ) ;
if ( ! V_180 -> V_236 &&
F_168 ( V_13 -> V_188 . V_189 ) <= V_271 )
F_140 ( 0 , V_180 -> V_233 ) ;
}
F_99 ( V_180 -> V_269 , V_180 -> V_262 ) ;
return 0 ;
}
int F_169 ( const struct V_1 * V_2 , unsigned int V_230 ,
T_10 V_272 , T_11 V_273 , T_11 V_274 ,
unsigned int V_275 )
{
unsigned int V_241 ;
struct V_194 * V_195 ;
struct V_12 * V_13 ;
struct V_276 * V_244 ;
int V_54 ;
V_195 = F_157 ( sizeof( * V_244 ) , V_156 ) ;
if ( ! V_195 )
return - V_61 ;
V_13 = F_170 ( V_2 ) ;
V_244 = (struct V_276 * ) F_149 ( V_195 , sizeof( * V_244 ) ) ;
F_150 ( V_244 , 0 ) ;
F_151 ( V_244 ) = F_152 ( F_153 ( V_277 , V_230 ) ) ;
V_244 -> V_278 = V_273 ;
V_244 -> V_279 = F_119 ( 0 ) ;
V_244 -> V_280 = V_272 ;
V_244 -> V_281 = F_152 ( 0 ) ;
V_241 = F_85 ( & V_13 -> V_16 , V_275 ) ;
V_244 -> V_282 = F_171 ( F_172 ( V_241 ) ) ;
V_244 -> V_283 = F_171 ( F_173 ( V_284 ) |
V_285 | F_174 ( V_275 ) ) ;
V_54 = F_175 ( V_13 , V_195 ) ;
return F_176 ( V_54 ) ;
}
int F_177 ( const struct V_1 * V_2 , unsigned int V_230 ,
const struct V_286 * V_272 , T_11 V_273 ,
unsigned int V_275 )
{
unsigned int V_241 ;
struct V_194 * V_195 ;
struct V_12 * V_13 ;
struct V_287 * V_244 ;
int V_54 ;
V_195 = F_157 ( sizeof( * V_244 ) , V_156 ) ;
if ( ! V_195 )
return - V_61 ;
V_13 = F_170 ( V_2 ) ;
V_244 = (struct V_287 * ) F_149 ( V_195 , sizeof( * V_244 ) ) ;
F_150 ( V_244 , 0 ) ;
F_151 ( V_244 ) = F_152 ( F_153 ( V_288 , V_230 ) ) ;
V_244 -> V_278 = V_273 ;
V_244 -> V_279 = F_119 ( 0 ) ;
V_244 -> V_289 = * ( T_4 * ) ( V_272 -> V_290 ) ;
V_244 -> V_291 = * ( T_4 * ) ( V_272 -> V_290 + 8 ) ;
V_244 -> V_292 = F_171 ( 0 ) ;
V_244 -> V_293 = F_171 ( 0 ) ;
V_241 = F_85 ( & V_13 -> V_16 , V_275 ) ;
V_244 -> V_282 = F_171 ( F_172 ( V_241 ) ) ;
V_244 -> V_283 = F_171 ( F_173 ( V_284 ) |
V_285 | F_174 ( V_275 ) ) ;
V_54 = F_175 ( V_13 , V_195 ) ;
return F_176 ( V_54 ) ;
}
int F_178 ( const struct V_1 * V_2 , unsigned int V_230 ,
unsigned int V_275 , bool V_294 )
{
struct V_194 * V_195 ;
struct V_12 * V_13 ;
struct V_295 * V_244 ;
int V_54 ;
V_13 = F_170 ( V_2 ) ;
V_195 = F_157 ( sizeof( * V_244 ) , V_156 ) ;
if ( ! V_195 )
return - V_61 ;
V_244 = (struct V_295 * ) F_149 ( V_195 , sizeof( * V_244 ) ) ;
F_150 ( V_244 , 0 ) ;
F_151 ( V_244 ) = F_152 ( F_153 ( V_296 , V_230 ) ) ;
V_244 -> V_297 = F_119 ( F_179 ( 0 ) | ( V_294 ? F_180 ( 1 ) :
F_180 ( 0 ) ) | F_181 ( V_275 ) ) ;
V_54 = F_175 ( V_13 , V_195 ) ;
return F_176 ( V_54 ) ;
}
unsigned int F_182 ( const unsigned short * V_298 , unsigned short V_66 ,
unsigned int * V_184 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_299 - 1 && V_298 [ V_19 + 1 ] <= V_66 )
++ V_19 ;
if ( V_184 )
* V_184 = V_19 ;
return V_298 [ V_19 ] ;
}
unsigned int F_183 ( const unsigned short * V_298 ,
unsigned short V_300 ,
unsigned short V_301 ,
unsigned short V_302 ,
unsigned int * V_303 )
{
unsigned short V_304 = V_300 + V_301 ;
unsigned short V_305 = V_302 - 1 ;
int V_306 , V_307 ;
for ( V_306 = 0 , V_307 = - 1 ; V_306 < V_299 ; V_306 ++ ) {
unsigned short V_308 = V_298 [ V_306 ] - V_300 ;
if ( ( V_308 & V_305 ) == 0 )
V_307 = V_306 ;
if ( V_306 + 1 < V_299 && V_298 [ V_306 + 1 ] > V_304 )
break;
}
if ( V_306 == V_299 )
V_306 -- ;
if ( V_307 >= 0 &&
V_306 - V_307 <= 1 )
V_306 = V_307 ;
if ( V_303 )
* V_303 = V_306 ;
return V_298 [ V_306 ] ;
}
unsigned int F_184 ( enum V_309 V_189 , unsigned int V_51 )
{
if ( F_168 ( V_189 ) <= V_271 )
return ( ( V_51 & 0x7f ) << 1 ) ;
else
return ( V_51 & 0x7f ) ;
}
unsigned int F_185 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_76 ;
}
unsigned int F_186 ( const struct V_1 * V_2 , int V_310 )
{
struct V_12 * V_13 = F_170 ( V_2 ) ;
T_1 V_311 , V_312 , V_313 , V_314 ;
V_311 = F_68 ( V_13 , V_315 ) ;
V_312 = F_68 ( V_13 , V_316 ) ;
if ( F_107 ( V_13 -> V_188 . V_189 ) ) {
V_313 = F_187 ( V_311 ) ;
V_314 = F_188 ( V_311 ) ;
} else {
V_313 = F_189 ( V_311 ) ;
V_314 = F_190 ( V_312 ) ;
}
return V_310 ? V_313 : V_314 ;
}
unsigned int F_191 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_51 ;
}
unsigned int F_192 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_31 ;
}
void F_193 ( struct V_317 * V_128 , struct V_318 * V_319 ,
struct V_318 * V_320 )
{
struct V_12 * V_13 = F_194 ( V_128 ) ;
F_195 ( & V_13 -> V_321 ) ;
F_196 ( V_13 , V_319 , V_320 ) ;
F_197 ( & V_13 -> V_321 ) ;
}
void F_198 ( struct V_1 * V_2 , unsigned int V_322 ,
const unsigned int * V_323 )
{
struct V_12 * V_13 = F_170 ( V_2 ) ;
F_70 ( V_13 , V_324 , V_322 ) ;
F_70 ( V_13 , V_325 , F_199 ( V_323 [ 0 ] ) |
F_200 ( V_323 [ 1 ] ) | F_201 ( V_323 [ 2 ] ) |
F_202 ( V_323 [ 3 ] ) ) ;
}
int F_203 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_170 ( V_2 ) ;
return F_204 ( V_13 , V_13 -> V_27 ) ;
}
static int F_205 ( struct V_12 * V_13 , T_6 V_95 , T_6 * V_326 , T_6 * V_327 )
{
T_1 V_50 = F_68 ( V_13 , V_328 ) + 24 * V_95 + 8 ;
T_4 V_329 ;
int V_54 ;
F_195 ( & V_13 -> V_330 ) ;
V_54 = F_206 ( V_13 , 0 , V_331 , V_50 ,
sizeof( V_329 ) , ( T_10 * ) & V_329 ,
V_332 ) ;
F_197 ( & V_13 -> V_330 ) ;
if ( ! V_54 ) {
* V_327 = ( F_207 ( V_329 ) >> 25 ) & 0xffff ;
* V_326 = ( F_207 ( V_329 ) >> 9 ) & 0xffff ;
}
return V_54 ;
}
int F_208 ( struct V_1 * V_2 , T_6 V_95 , T_6 V_326 ,
T_6 V_192 )
{
struct V_12 * V_13 = F_170 ( V_2 ) ;
T_6 V_333 , V_334 ;
int V_54 ;
V_54 = F_205 ( V_13 , V_95 , & V_333 , & V_334 ) ;
if ( V_54 )
goto V_59;
if ( V_326 != V_333 ) {
T_6 V_206 ;
T_1 V_335 ;
if ( V_326 >= V_333 )
V_206 = V_326 - V_333 ;
else
V_206 = V_192 - V_333 + V_326 ;
if ( F_107 ( V_13 -> V_188 . V_189 ) )
V_335 = F_209 ( V_206 ) ;
else
V_335 = F_210 ( V_206 ) ;
F_211 () ;
F_70 ( V_13 , F_69 ( V_336 ) ,
F_212 ( V_95 ) | V_335 ) ;
}
V_59:
return V_54 ;
}
int F_213 ( struct V_1 * V_2 , T_1 V_337 , T_10 * V_338 )
{
struct V_12 * V_13 ;
T_1 V_339 , V_340 , V_341 ;
T_1 V_342 , V_343 , V_344 , V_345 , V_192 ;
T_1 V_346 , V_347 , V_348 , V_349 ;
int V_54 ;
V_13 = F_170 ( V_2 ) ;
V_339 = ( ( V_337 >> 8 ) * 32 ) + V_13 -> V_350 . V_337 . V_351 ;
V_192 = F_68 ( V_13 , V_352 ) ;
V_342 = F_214 ( V_192 ) << 20 ;
V_192 = F_68 ( V_13 , V_353 ) ;
V_343 = F_215 ( V_192 ) << 20 ;
V_192 = F_68 ( V_13 , V_354 ) ;
V_344 = F_216 ( V_192 ) << 20 ;
V_346 = V_342 ;
V_347 = V_346 + V_343 ;
V_348 = V_347 + V_344 ;
if ( V_339 < V_346 ) {
V_340 = V_331 ;
V_341 = V_339 ;
} else if ( V_339 < V_347 ) {
V_340 = V_355 ;
V_341 = V_339 - V_346 ;
} else {
if ( V_339 < V_348 ) {
V_340 = V_356 ;
V_341 = V_339 - V_347 ;
} else if ( F_217 ( V_13 -> V_188 . V_189 ) ) {
V_192 = F_68 ( V_13 , V_357 ) ;
V_345 = F_218 ( V_192 ) << 20 ;
V_349 = V_348 + V_345 ;
if ( V_339 < V_349 ) {
V_340 = V_358 ;
V_341 = V_339 - V_348 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_195 ( & V_13 -> V_330 ) ;
V_54 = F_206 ( V_13 , 0 , V_340 , V_341 , 32 , V_338 , V_332 ) ;
F_197 ( & V_13 -> V_330 ) ;
return V_54 ;
V_22:
F_11 ( V_13 -> V_30 , L_33 ,
V_337 , V_339 ) ;
return - V_65 ;
}
T_2 F_219 ( struct V_1 * V_2 )
{
T_1 V_359 , V_360 ;
struct V_12 * V_13 ;
V_13 = F_170 ( V_2 ) ;
V_360 = F_68 ( V_13 , V_361 ) ;
V_359 = F_220 ( F_68 ( V_13 , V_362 ) ) ;
return ( ( T_2 ) V_359 << 32 ) | ( T_2 ) V_360 ;
}
int F_221 ( struct V_1 * V_2 ,
unsigned int V_95 ,
enum V_363 V_364 ,
int V_365 ,
T_2 * V_366 ,
unsigned int * V_367 )
{
return F_222 ( F_170 ( V_2 ) ,
V_95 ,
( V_364 == V_368
? V_369
: V_370 ) ,
V_365 ,
V_366 ,
V_367 ) ;
}
static void F_223 ( struct V_371 * V_372 )
{
const struct V_373 * V_374 ;
const struct V_1 * V_52 = V_372 -> V_2 ;
if ( V_52 -> V_375 & V_376 )
V_52 = F_224 ( V_52 ) ;
V_374 = V_52 -> V_2 . V_374 ;
if ( V_374 && V_374 -> V_377 == & V_378 . V_377 )
F_225 ( F_226 ( V_374 ) , V_372 ) ;
}
static int F_227 ( struct V_379 * V_380 , unsigned long V_381 ,
void * V_109 )
{
switch ( V_381 ) {
case V_382 :
F_223 ( V_109 ) ;
break;
case V_383 :
default:
break;
}
return 0 ;
}
static void F_228 ( struct V_12 * V_13 , int V_384 )
{
T_1 V_311 , V_312 , V_313 , V_314 ;
do {
V_311 = F_68 ( V_13 , V_315 ) ;
V_312 = F_68 ( V_13 , V_316 ) ;
if ( F_107 ( V_13 -> V_188 . V_189 ) ) {
V_313 = F_187 ( V_311 ) ;
V_314 = F_188 ( V_311 ) ;
} else {
V_313 = F_189 ( V_311 ) ;
V_314 = F_190 ( V_312 ) ;
}
if ( V_313 == 0 && V_314 == 0 )
break;
F_229 ( V_385 ) ;
F_230 ( F_231 ( V_384 ) ) ;
} while ( 1 );
}
static void F_232 ( struct V_97 * V_25 )
{
unsigned long V_68 ;
F_233 ( & V_25 -> V_386 , V_68 ) ;
V_25 -> V_387 = 1 ;
F_234 ( & V_25 -> V_386 , V_68 ) ;
}
static void F_235 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
F_236 ( & V_25 -> V_386 ) ;
if ( V_25 -> V_388 ) {
F_211 () ;
F_70 ( V_13 , F_69 ( V_336 ) ,
F_212 ( V_25 -> V_26 ) | F_209 ( V_25 -> V_388 ) ) ;
V_25 -> V_388 = 0 ;
}
V_25 -> V_387 = 0 ;
F_237 ( & V_25 -> V_386 ) ;
}
static void F_238 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_232 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_167 ( V_13 ) ) {
struct V_389 * V_390 =
V_13 -> V_16 . V_391 [ V_392 ] ;
if ( V_390 ) {
F_239 (&adap->sge, i) {
struct V_104 * V_15 = & V_390 -> V_393 [ V_19 ] ;
F_232 ( & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_232 ( & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_240 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_235 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_167 ( V_13 ) ) {
struct V_389 * V_390 =
V_13 -> V_16 . V_391 [ V_392 ] ;
if ( V_390 ) {
F_239 (&adap->sge, i) {
struct V_104 * V_15 = & V_390 -> V_393 [ V_19 ] ;
F_235 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_235 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_241 ( struct V_12 * V_13 , enum V_394 V_110 )
{
enum V_395 type = V_178 ;
if ( V_13 -> V_396 && V_13 -> V_396 [ type ] . V_397 )
V_13 -> V_396 [ type ] . F_242 ( V_13 -> V_396 [ type ] . V_397 , V_110 ) ;
}
static void F_243 ( struct V_255 * V_256 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_256 , struct V_12 , V_398 ) ;
F_228 ( V_13 , V_399 ) ;
F_240 ( V_13 ) ;
F_241 ( V_13 , V_400 ) ;
if ( F_168 ( V_13 -> V_188 . V_189 ) <= V_271 )
F_244 ( V_13 , V_401 ,
V_402 | V_403 ,
V_402 | V_403 ) ;
else
F_244 ( V_13 , V_401 ,
V_403 , V_403 ) ;
}
static void F_245 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
T_6 V_333 , V_334 ;
int V_54 ;
F_236 ( & V_25 -> V_386 ) ;
V_54 = F_205 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_333 , & V_334 ) ;
if ( V_54 )
goto V_59;
if ( V_25 -> V_404 != V_333 ) {
T_6 V_206 ;
T_1 V_335 ;
if ( V_25 -> V_404 >= V_333 )
V_206 = V_25 -> V_404 - V_333 ;
else
V_206 = V_25 -> V_192 - V_333 + V_25 -> V_404 ;
if ( F_107 ( V_13 -> V_188 . V_189 ) )
V_335 = F_209 ( V_206 ) ;
else
V_335 = F_210 ( V_206 ) ;
F_211 () ;
F_70 ( V_13 , F_69 ( V_336 ) ,
F_212 ( V_25 -> V_26 ) | V_335 ) ;
}
V_59:
V_25 -> V_387 = 0 ;
V_25 -> V_388 = 0 ;
F_237 ( & V_25 -> V_386 ) ;
if ( V_54 )
F_246 ( V_13 , L_34 ) ;
}
static void F_247 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_245 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_167 ( V_13 ) ) {
struct V_389 * V_390 =
V_13 -> V_16 . V_391 [ V_392 ] ;
if ( V_390 ) {
F_239 (&adap->sge, i) {
struct V_104 * V_15 = & V_390 -> V_393 [ V_19 ] ;
F_245 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_245 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_248 ( struct V_255 * V_256 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_256 , struct V_12 , V_405 ) ;
if ( F_107 ( V_13 -> V_188 . V_189 ) ) {
F_228 ( V_13 , V_399 ) ;
F_241 ( V_13 , V_406 ) ;
F_228 ( V_13 , V_399 ) ;
F_247 ( V_13 ) ;
F_228 ( V_13 , V_399 ) ;
F_240 ( V_13 ) ;
F_241 ( V_13 , V_400 ) ;
} else if ( F_217 ( V_13 -> V_188 . V_189 ) ) {
T_1 V_407 = F_68 ( V_13 , 0x010ac ) ;
T_6 V_95 = ( V_407 >> 15 ) & 0x1ffff ;
T_6 V_408 = V_407 & 0x1fff ;
T_2 V_409 ;
unsigned int V_410 ;
int V_54 ;
V_54 = F_222 ( V_13 , V_95 , V_369 ,
0 , & V_409 , & V_410 ) ;
if ( V_54 )
F_11 ( V_13 -> V_30 , L_35
L_36 , V_95 , V_408 ) ;
else
F_249 ( F_210 ( V_408 ) | F_212 ( V_410 ) ,
V_13 -> V_411 + V_409 + V_412 ) ;
F_244 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_168 ( V_13 -> V_188 . V_189 ) <= V_271 )
F_244 ( V_13 , V_413 , V_414 , 0 ) ;
}
void F_250 ( struct V_12 * V_13 )
{
if ( F_107 ( V_13 -> V_188 . V_189 ) ) {
F_238 ( V_13 ) ;
F_241 ( V_13 , V_415 ) ;
F_244 ( V_13 , V_401 ,
V_402 | V_403 , 0 ) ;
F_155 ( V_13 -> V_253 , & V_13 -> V_398 ) ;
}
}
void F_251 ( struct V_12 * V_13 )
{
if ( F_107 ( V_13 -> V_188 . V_189 ) ) {
F_238 ( V_13 ) ;
F_241 ( V_13 , V_415 ) ;
}
F_155 ( V_13 -> V_253 , & V_13 -> V_405 ) ;
}
void F_252 ( void )
{
if ( ! V_416 ) {
F_253 ( & V_417 ) ;
V_416 = true ;
}
}
static void F_254 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_255 ( & V_418 ) ;
F_33 ( & V_13 -> V_419 ) ;
for ( V_19 = 0 ; V_19 < V_420 ; V_19 ++ )
if ( V_13 -> V_396 && V_13 -> V_396 [ V_19 ] . V_397 ) {
V_13 -> V_396 [ V_19 ] . F_256 ( V_13 -> V_396 [ V_19 ] . V_397 ,
V_421 ) ;
V_13 -> V_396 [ V_19 ] . V_397 = NULL ;
}
if ( V_416 && F_257 ( & V_422 ) ) {
F_258 ( & V_417 ) ;
V_416 = false ;
}
F_259 ( & V_418 ) ;
}
static void F_260 ( struct V_12 * V_13 , enum V_423 V_424 )
{
unsigned int V_19 ;
F_255 ( & V_418 ) ;
for ( V_19 = 0 ; V_19 < V_420 ; V_19 ++ )
if ( V_13 -> V_396 && V_13 -> V_396 [ V_19 ] . V_397 )
V_13 -> V_396 [ V_19 ] . F_256 ( V_13 -> V_396 [ V_19 ] . V_397 ,
V_424 ) ;
F_259 ( & V_418 ) ;
}
static int F_261 ( struct V_379 * V_425 ,
unsigned long V_381 , void * V_109 )
{
struct V_426 * V_427 = V_109 ;
struct V_1 * V_428 = V_427 -> V_429 -> V_2 ;
const struct V_373 * V_374 = NULL ;
#if F_262 ( V_430 )
struct V_12 * V_13 ;
#endif
if ( V_428 -> V_375 & V_376 )
V_428 = F_224 ( V_428 ) ;
#if F_262 ( V_430 )
if ( V_428 -> V_68 & V_431 ) {
F_22 (adap, &adapter_list, list_node) {
switch ( V_381 ) {
case V_432 :
F_263 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_427 , 1 ) ;
break;
case V_433 :
F_264 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_427 , 1 ) ;
break;
default:
break;
}
}
return V_434 ;
}
#endif
if ( V_428 )
V_374 = V_428 -> V_2 . V_374 ;
if ( V_374 && V_374 -> V_377 == & V_378 . V_377 ) {
switch ( V_381 ) {
case V_432 :
F_263 ( V_428 , ( const T_1 * ) V_427 , 1 ) ;
break;
case V_433 :
F_264 ( V_428 , ( const T_1 * ) V_427 , 1 ) ;
break;
default:
break;
}
}
return V_434 ;
}
static void F_265 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_54 ;
F_266 () ;
for ( V_19 = 0 ; V_19 < V_435 ; V_19 ++ ) {
V_2 = V_13 -> V_39 [ V_19 ] ;
V_54 = 0 ;
if ( V_2 )
V_54 = F_267 ( V_2 ) ;
if ( V_54 < 0 )
break;
}
F_268 () ;
}
static int F_269 ( struct V_12 * V_13 )
{
int V_22 ;
V_22 = F_102 ( V_13 ) ;
if ( V_22 )
goto V_59;
V_22 = F_83 ( V_13 ) ;
if ( V_22 )
goto V_436;
if ( V_13 -> V_68 & V_127 ) {
F_72 ( V_13 ) ;
V_22 = F_75 ( V_13 -> V_141 [ 0 ] . V_46 , F_67 , 0 ,
V_13 -> V_141 [ 0 ] . V_142 , V_13 ) ;
if ( V_22 )
goto V_437;
V_22 = F_74 ( V_13 ) ;
if ( V_22 ) {
F_77 ( V_13 -> V_141 [ 0 ] . V_46 , V_13 ) ;
goto V_437;
}
} else {
V_22 = F_75 ( V_13 -> V_128 -> V_130 , F_270 ( V_13 ) ,
( V_13 -> V_68 & V_129 ) ? 0 : V_438 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_437;
}
F_93 ( V_13 ) ;
F_271 ( V_13 ) ;
F_272 ( V_13 ) ;
V_13 -> V_68 |= V_168 ;
F_260 ( V_13 , V_439 ) ;
#if F_262 ( V_440 )
F_265 ( V_13 ) ;
#endif
F_273 ( & V_13 -> V_63 ) ;
V_59:
return V_22 ;
V_437:
F_11 ( V_13 -> V_30 , L_37 , V_22 ) ;
V_436:
F_101 ( V_13 ) ;
goto V_59;
}
static void F_274 ( struct V_12 * V_12 )
{
F_275 ( & V_12 -> V_254 ) ;
F_275 ( & V_12 -> V_398 ) ;
F_275 ( & V_12 -> V_405 ) ;
V_12 -> V_252 = false ;
V_12 -> V_250 = NULL ;
F_276 ( V_12 ) ;
F_101 ( V_12 ) ;
V_12 -> V_68 &= ~ V_168 ;
}
static int F_277 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_18 ( V_2 ) ;
if ( ! ( V_12 -> V_68 & V_168 ) ) {
V_22 = F_269 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
F_278 ( V_2 ) ;
return V_22 ;
}
static int F_279 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_280 ( V_2 ) ;
F_18 ( V_2 ) ;
return F_281 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , false , false ) ;
}
int F_282 ( const struct V_1 * V_2 , unsigned int V_230 ,
T_10 V_272 , T_11 V_273 , T_11 V_274 ,
unsigned int V_275 , unsigned char V_39 , unsigned char V_441 )
{
int V_54 ;
struct V_268 * V_442 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_335 ;
V_13 = F_170 ( V_2 ) ;
V_230 -= V_13 -> V_248 . V_239 ;
V_230 += V_13 -> V_248 . V_262 ;
V_442 = & V_13 -> V_248 . V_266 [ V_230 ] ;
V_54 = F_283 ( V_442 ) ;
if ( V_54 )
return V_54 ;
if ( V_442 -> V_443 )
F_284 ( V_13 , V_442 ) ;
memset ( & V_442 -> V_444 , 0 , sizeof( struct V_445 ) ) ;
V_442 -> V_444 . V_335 . V_446 = F_285 ( V_273 ) ;
V_442 -> V_444 . V_441 . V_446 = ~ 0 ;
V_335 = ( T_3 * ) & V_272 ;
if ( ( V_335 [ 0 ] | V_335 [ 1 ] | V_335 [ 2 ] | V_335 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_442 -> V_444 . V_335 . V_447 [ V_19 ] = V_335 [ V_19 ] ;
V_442 -> V_444 . V_441 . V_447 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_188 . V_448 . V_449 & V_450 ) {
V_442 -> V_444 . V_335 . V_451 = V_39 ;
V_442 -> V_444 . V_441 . V_451 = V_441 ;
}
}
if ( V_13 -> V_188 . V_448 . V_449 & V_452 ) {
V_442 -> V_444 . V_335 . V_453 = V_454 ;
V_442 -> V_444 . V_441 . V_453 = ~ 0 ;
}
V_442 -> V_444 . V_455 = 1 ;
V_442 -> V_444 . V_456 = V_275 ;
V_442 -> V_457 = 1 ;
V_442 -> V_444 . V_458 = 1 ;
V_54 = F_286 ( V_13 , V_230 ) ;
if ( V_54 ) {
F_284 ( V_13 , V_442 ) ;
return V_54 ;
}
return 0 ;
}
int F_287 ( const struct V_1 * V_2 , unsigned int V_230 ,
unsigned int V_275 , bool V_294 )
{
struct V_268 * V_442 ;
struct V_12 * V_13 ;
V_13 = F_170 ( V_2 ) ;
V_230 -= V_13 -> V_248 . V_239 ;
V_230 += V_13 -> V_248 . V_262 ;
V_442 = & V_13 -> V_248 . V_266 [ V_230 ] ;
V_442 -> V_457 = 0 ;
return F_288 ( V_13 , V_230 ) ;
}
static struct V_459 * F_289 ( struct V_1 * V_2 ,
struct V_459 * V_460 )
{
struct V_461 V_185 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_195 ( & V_12 -> V_321 ) ;
if ( ! F_290 ( V_2 ) ) {
F_197 ( & V_12 -> V_321 ) ;
return V_460 ;
}
F_291 ( V_12 , V_6 -> V_76 , & V_185 ,
& V_6 -> V_462 ) ;
F_197 ( & V_12 -> V_321 ) ;
V_460 -> V_463 = V_185 . V_464 ;
V_460 -> V_465 = V_185 . V_466 ;
V_460 -> V_467 = V_185 . V_468 ;
V_460 -> V_469 = V_185 . V_470 ;
V_460 -> V_471 = V_185 . V_472 ;
V_460 -> V_473 = V_185 . V_474 + V_185 . V_475 +
V_185 . V_476 ;
V_460 -> V_477 = 0 ;
V_460 -> V_478 = V_185 . V_479 ;
V_460 -> V_480 = V_185 . V_481 ;
V_460 -> V_482 = V_185 . V_483 + V_185 . V_484 +
V_185 . V_485 + V_185 . V_486 +
V_185 . V_487 + V_185 . V_488 +
V_185 . V_489 + V_185 . V_490 ;
V_460 -> V_491 = 0 ;
V_460 -> V_492 = 0 ;
V_460 -> V_493 = 0 ;
V_460 -> V_494 = 0 ;
V_460 -> V_495 = 0 ;
V_460 -> V_496 = 0 ;
V_460 -> V_497 = V_185 . V_498 ;
V_460 -> V_499 = V_185 . V_481 + V_185 . V_479 +
V_460 -> V_473 + V_185 . V_500 + V_460 -> V_482 ;
return V_460 ;
}
static int F_292 ( struct V_1 * V_2 , struct V_501 * V_244 , int V_110 )
{
unsigned int V_27 ;
int V_54 = 0 , V_502 , V_503 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_504 * V_109 = (struct V_504 * ) & V_244 -> V_505 ;
switch ( V_110 ) {
case V_506 :
if ( V_11 -> V_507 < 0 )
return - V_508 ;
V_109 -> V_509 = V_11 -> V_507 ;
break;
case V_510 :
case V_511 :
if ( F_293 ( V_109 -> V_509 ) ) {
V_502 = F_294 ( V_109 -> V_509 ) ;
V_503 = F_295 ( V_109 -> V_509 ) ;
} else if ( V_109 -> V_509 < 32 ) {
V_502 = V_109 -> V_509 ;
V_503 = 0 ;
V_109 -> V_512 &= 0x1f ;
} else
return - V_65 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_110 == V_510 )
V_54 = F_296 ( V_11 -> V_12 , V_27 , V_502 , V_503 ,
V_109 -> V_512 , & V_109 -> V_513 ) ;
else
V_54 = F_297 ( V_11 -> V_12 , V_27 , V_502 , V_503 ,
V_109 -> V_512 , V_109 -> V_514 ) ;
break;
case V_515 :
return F_298 ( V_244 -> V_505 , & V_11 -> V_516 ,
sizeof( V_11 -> V_516 ) ) ?
- V_517 : 0 ;
case V_518 :
if ( F_299 ( & V_11 -> V_516 , V_244 -> V_505 ,
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
return F_298 ( V_244 -> V_505 , & V_11 -> V_516 ,
sizeof( V_11 -> V_516 ) ) ?
- V_517 : 0 ;
default:
return - V_508 ;
}
return V_54 ;
}
static void F_300 ( struct V_1 * V_2 )
{
F_36 ( V_2 , - 1 , false ) ;
}
static int F_301 ( struct V_1 * V_2 , int V_524 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
V_54 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , V_524 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_54 )
V_2 -> V_66 = V_524 ;
return V_54 ;
}
static int F_302 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
return 0 ;
}
static void F_303 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
T_3 V_525 [ V_526 ] , V_527 [ V_526 ] ;
int V_22 ;
T_3 * V_528 ;
T_6 V_529 , V_530 ;
V_22 = F_304 ( V_13 , & V_13 -> V_188 . V_531 ) ;
if ( ! V_22 ) {
V_528 = V_13 -> V_188 . V_531 . V_528 ;
for ( V_19 = 0 ; V_19 < V_526 ; V_19 ++ )
V_525 [ V_19 ] = ( F_305 ( V_528 [ 2 * V_19 + 0 ] ) * 16 +
F_305 ( V_528 [ 2 * V_19 + 1 ] ) ) ;
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
static int F_306 ( struct V_1 * V_2 , int V_535 , T_3 * V_536 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
if ( ! F_307 ( V_536 ) ) {
F_11 ( V_11 -> V_12 -> V_30 ,
L_38 ,
V_536 , V_535 ) ;
return - V_65 ;
}
F_308 ( V_11 -> V_12 -> V_30 ,
L_39 , V_536 , V_535 ) ;
V_54 = F_309 ( V_13 , V_535 + 1 , 1 , V_536 ) ;
if ( ! V_54 )
F_28 ( V_13 -> V_533 [ V_535 ] . V_534 , V_536 ) ;
return V_54 ;
}
static int F_310 ( struct V_1 * V_2 ,
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
static int F_311 ( struct V_1 * V_2 , void * V_6 )
{
int V_54 ;
struct V_539 * V_50 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_307 ( V_50 -> V_540 ) )
return - V_541 ;
V_54 = F_41 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 ,
V_11 -> V_74 , V_50 -> V_540 , true , true ) ;
if ( V_54 < 0 )
return V_54 ;
memcpy ( V_2 -> V_75 , V_50 -> V_540 , V_2 -> V_542 ) ;
V_11 -> V_74 = V_54 ;
return 0 ;
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_68 & V_127 ) {
int V_19 ;
struct V_153 * V_543 = & V_13 -> V_16 . V_148 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_543 ++ )
V_146 ( 0 , & V_543 -> V_149 ) ;
} else
F_270 ( V_13 ) ( 0 , V_13 ) ;
}
static int F_313 ( struct V_1 * V_2 , int V_544 , T_1 V_545 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_546 * V_547 ;
struct V_548 V_6 ;
struct V_549 V_550 ;
T_1 V_551 ;
int V_22 = 0 ;
if ( ! F_314 ( V_2 ) )
return - V_552 ;
if ( V_544 < 0 || V_544 > V_11 -> V_20 - 1 )
return - V_65 ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_40 ,
V_544 ) ;
return - V_65 ;
}
V_551 = V_545 << 10 ;
if ( V_551 >= V_553 ) {
F_11 ( V_13 -> V_30 ,
L_41 ,
V_545 , V_553 ) ;
return - V_523 ;
}
memset ( & V_550 , 0 , sizeof( V_550 ) ) ;
V_550 . V_275 = V_544 ;
V_550 . V_554 = V_555 ;
V_22 = F_315 ( V_2 , ( void * ) ( & V_550 ) , V_556 ) ;
if ( V_22 ) {
F_11 ( V_13 -> V_30 ,
L_42 ,
V_544 , V_11 -> V_31 , V_22 ) ;
return V_22 ;
}
if ( ! V_551 )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_557 ;
V_6 . V_116 . V_188 . V_558 = V_559 ;
V_6 . V_116 . V_188 . V_560 = V_561 ;
V_6 . V_116 . V_188 . V_562 = V_563 ;
V_6 . V_116 . V_188 . V_564 = V_565 ;
V_6 . V_116 . V_188 . V_566 = V_11 -> V_76 ;
V_6 . V_116 . V_188 . V_554 = V_555 ;
V_6 . V_116 . V_188 . V_567 = 0 ;
V_6 . V_116 . V_188 . V_568 = V_551 ;
V_6 . V_116 . V_188 . V_569 = 0 ;
V_6 . V_116 . V_188 . V_570 = V_2 -> V_66 ;
V_547 = F_316 ( V_2 , & V_6 ) ;
if ( ! V_547 )
return - V_61 ;
memset ( & V_550 , 0 , sizeof( V_550 ) ) ;
V_550 . V_275 = V_544 ;
V_550 . V_554 = V_547 -> V_184 ;
V_22 = F_317 ( V_2 , ( void * ) ( & V_550 ) , V_556 ) ;
if ( V_22 )
F_11 ( V_13 -> V_30 ,
L_43 , V_22 ) ;
return V_22 ;
}
static int F_318 ( struct V_1 * V_2 , T_1 V_397 , T_11 V_453 ,
struct V_571 * V_572 )
{
struct V_5 * V_11 = F_86 ( V_2 ) ;
struct V_12 * V_13 = F_170 ( V_2 ) ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_44 ,
V_11 -> V_31 ) ;
return - V_65 ;
}
if ( F_319 ( V_397 ) == F_319 ( V_573 ) &&
V_572 -> type == V_574 ) {
switch ( V_572 -> V_575 -> V_576 ) {
case V_577 :
case V_578 :
return F_320 ( V_2 , V_453 , V_572 -> V_575 ) ;
case V_579 :
return F_321 ( V_2 , V_453 , V_572 -> V_575 ) ;
default:
return - V_508 ;
}
}
return - V_508 ;
}
static void F_322 ( struct V_1 * V_2 , struct V_580 * V_117 )
{
struct V_12 * V_12 = F_170 ( V_2 ) ;
F_323 ( V_117 -> V_377 , V_581 , sizeof( V_117 -> V_377 ) ) ;
F_323 ( V_117 -> V_582 , V_583 ,
sizeof( V_117 -> V_582 ) ) ;
F_323 ( V_117 -> V_584 , F_324 ( V_12 -> V_128 ) ,
sizeof( V_117 -> V_584 ) ) ;
}
void F_325 ( struct V_12 * V_13 )
{
F_244 ( V_13 , V_585 , V_586 , 0 ) ;
F_92 ( V_13 ) ;
F_326 ( V_13 -> V_30 , L_45 ) ;
}
static void F_327 ( struct V_12 * V_13 )
{
T_1 V_587 = F_328 ( V_13 ) ;
F_329 ( V_13 , V_587 , V_588 ) ;
}
static void F_330 ( struct V_12 * V_13 )
{
if ( V_13 -> V_350 . V_589 . V_192 ) {
T_1 V_351 ;
unsigned int V_590 ;
V_351 = F_331 ( V_13 , V_591 ) ;
V_351 &= V_592 ;
V_351 += F_332 ( V_13 -> V_128 , & V_13 -> V_350 ) ;
V_590 = F_333 ( V_13 -> V_350 . V_589 . V_192 ) >> 10 ;
F_70 ( V_13 ,
F_334 ( V_593 , 3 ) ,
V_351 | F_335 ( 1 ) | F_336 ( F_337 ( V_590 ) ) ) ;
F_70 ( V_13 ,
F_334 ( V_594 , 3 ) ,
V_13 -> V_350 . V_589 . V_351 ) ;
F_68 ( V_13 ,
F_334 ( V_594 , 3 ) ) ;
}
}
static int F_338 ( struct V_12 * V_13 , struct V_595 * V_596 )
{
T_1 V_132 ;
int V_54 ;
memset ( V_596 , 0 , sizeof( * V_596 ) ) ;
V_596 -> V_597 = F_152 ( F_339 ( V_598 ) |
V_599 | V_600 ) ;
V_596 -> V_601 = F_152 ( F_340 ( * V_596 ) ) ;
V_54 = F_341 ( V_13 , V_13 -> V_27 , V_596 , sizeof( * V_596 ) , V_596 ) ;
if ( V_54 < 0 )
return V_54 ;
V_596 -> V_597 = F_152 ( F_339 ( V_598 ) |
V_599 | V_602 ) ;
V_54 = F_341 ( V_13 , V_13 -> V_27 , V_596 , sizeof( * V_596 ) , NULL ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_342 ( V_13 , V_13 -> V_28 ,
V_603 ,
V_604 |
V_605 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_343 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_172 , 64 ,
V_606 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_607 ,
V_607 ) ;
if ( V_54 < 0 )
return V_54 ;
F_344 ( V_13 ) ;
F_70 ( V_13 , V_608 , 0x64f8849 ) ;
F_70 ( V_13 , V_609 , F_199 ( V_610 - 12 ) ) ;
F_70 ( V_13 , V_611 , V_612 ) ;
V_132 = F_68 ( V_13 , V_613 ) ;
F_70 ( V_13 , V_613 , V_132 & ~ V_614 ) ;
V_13 -> V_188 . V_448 . V_615 = 0xE4 ;
F_70 ( V_13 , V_616 ,
F_345 ( V_13 -> V_188 . V_448 . V_615 ) ) ;
V_132 = 0x84218421 ;
F_346 ( V_13 , V_611 , V_613 ,
& V_132 , 1 , V_617 ) ;
F_346 ( V_13 , V_611 , V_613 ,
& V_132 , 1 , V_618 ) ;
F_346 ( V_13 , V_611 , V_613 ,
& V_132 , 1 , V_619 ) ;
#define F_347 16
if ( F_167 ( V_13 ) ) {
F_70 ( V_13 , V_620 ,
F_348 ( F_347 ) |
F_349 ( F_347 ) |
F_350 ( F_347 ) |
F_351 ( F_347 ) ) ;
F_70 ( V_13 , V_621 ,
F_348 ( F_347 ) |
F_349 ( F_347 ) |
F_350 ( F_347 ) |
F_351 ( F_347 ) ) ;
}
return F_352 ( V_13 , V_13 -> V_28 ) ;
}
static int F_353 ( struct V_12 * V_12 )
{
F_354 ( V_12 , V_622 , V_623 ) ;
if ( V_624 != 2 && V_624 != 0 ) {
F_11 ( & V_12 -> V_128 -> V_2 ,
L_46 ,
V_624 ) ;
V_624 = 2 ;
}
F_244 ( V_12 , V_585 ,
F_355 ( V_625 ) ,
F_355 ( V_624 ) ) ;
F_356 ( V_12 , V_612 ,
V_614 , 0 ) ;
return 0 ;
}
static int F_357 ( const T_3 * V_626 ,
T_7 V_627 )
{
int V_339 ;
#define F_358 ( T_12 ) (((__p)[0] << 8) | (__p)[1])
#define F_359 ( T_12 ) ((__p)[0] | ((__p)[1] << 8))
#define F_360 ( T_12 ) (le16(__p) | ((__p)[2] << 16))
V_339 = F_360 ( V_626 + 0x8 ) << 12 ;
V_339 = F_360 ( V_626 + V_339 + 0xa ) ;
return F_358 ( V_626 + V_339 + 0x27e ) ;
#undef F_358
#undef F_359
#undef F_360
}
static struct V_628 * F_361 ( int V_629 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_630 ) ; V_19 ++ ) {
if ( V_630 [ V_19 ] . V_631 == V_629 )
return & V_630 [ V_19 ] ;
}
return NULL ;
}
static int F_362 ( struct V_12 * V_13 )
{
const struct V_632 * V_633 ;
int V_54 ;
struct V_628 * V_634 ;
V_634 = F_361 ( V_13 -> V_128 -> V_373 ) ;
if ( ! V_634 ) {
F_363 ( V_13 -> V_30 ,
L_47 ) ;
return - V_508 ;
}
V_54 = F_364 ( & V_633 , V_634 -> V_635 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_48
L_49 ,
V_634 -> V_635 , - V_54 ) ;
if ( V_634 -> V_636 ) {
int V_637 = 0 ;
F_365 ( V_13 , & V_637 ) ;
F_363 ( V_13 -> V_30 , L_50
L_51 , V_637 ) ;
V_54 = 0 ;
}
return V_54 ;
}
V_54 = F_366 ( V_13 , V_588 , & V_13 -> V_330 ,
V_634 -> V_638 ,
( T_3 * ) V_633 -> V_109 , V_633 -> V_192 ) ;
if ( V_54 < 0 )
F_11 ( V_13 -> V_30 , L_52 ,
- V_54 ) ;
else if ( V_54 > 0 ) {
int V_639 = 0 ;
if ( V_634 -> V_638 )
V_639 = V_634 -> V_638 ( V_633 -> V_109 ,
V_633 -> V_192 ) ;
F_308 ( V_13 -> V_30 , L_53
L_54 ,
V_634 -> V_635 , V_639 ) ;
}
F_367 ( V_633 ) ;
return V_54 ;
}
static int F_368 ( struct V_12 * V_12 , int V_640 )
{
struct V_595 V_641 ;
const struct V_632 * V_642 ;
unsigned long V_643 = 0 , V_644 = 0 ;
T_1 V_645 , V_646 , V_647 ;
int V_54 ;
int V_648 = 0 ;
char * V_649 , V_650 [ 256 ] ;
char * V_651 = NULL ;
if ( V_640 ) {
V_54 = F_369 ( V_12 , V_12 -> V_27 ,
V_652 | V_653 ) ;
if ( V_54 < 0 )
goto V_654;
}
if ( F_370 ( V_12 -> V_128 -> V_373 ) ) {
V_54 = F_362 ( V_12 ) ;
if ( V_54 < 0 )
goto V_654;
}
switch ( F_168 ( V_12 -> V_188 . V_189 ) ) {
case V_655 :
V_649 = V_656 ;
break;
case V_271 :
V_649 = V_657 ;
break;
case V_658 :
V_649 = V_659 ;
break;
default:
F_11 ( V_12 -> V_30 , L_55 ,
V_12 -> V_128 -> V_373 ) ;
V_54 = - V_65 ;
goto V_654;
}
V_54 = F_371 ( & V_642 , V_649 , V_12 -> V_30 ) ;
if ( V_54 < 0 ) {
V_651 = L_56 ;
V_643 = V_660 ;
V_644 = F_372 ( V_12 ) ;
} else {
T_1 V_188 [ 7 ] , V_335 [ 7 ] ;
sprintf ( V_650 ,
L_57 , V_649 ) ;
V_651 = V_650 ;
if ( V_642 -> V_192 >= V_661 )
V_54 = - V_61 ;
else {
V_188 [ 0 ] = ( F_7 ( V_662 ) |
F_8 ( V_663 ) ) ;
V_54 = F_373 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_188 , V_335 ) ;
if ( V_54 == 0 ) {
T_7 V_664 = V_642 -> V_192 & 0x3 ;
T_7 V_192 = V_642 -> V_192 & ~ 0x3 ;
T_10 * V_109 = ( T_10 * ) V_642 -> V_109 ;
V_643 = F_374 ( V_335 [ 0 ] ) ;
V_644 = F_375 ( V_335 [ 0 ] ) << 16 ;
F_195 ( & V_12 -> V_330 ) ;
V_54 = F_206 ( V_12 , 0 , V_643 , V_644 ,
V_192 , V_109 , V_665 ) ;
if ( V_54 == 0 && V_664 != 0 ) {
union {
T_10 V_666 ;
char V_667 [ 4 ] ;
} V_668 ;
int V_19 ;
V_668 . V_666 = V_109 [ V_192 >> 2 ] ;
for ( V_19 = V_664 ; V_19 < 4 ; V_19 ++ )
V_668 . V_667 [ V_19 ] = 0 ;
V_54 = F_206 ( V_12 , 0 , V_643 ,
V_644 + V_192 ,
4 , & V_668 . V_666 ,
V_665 ) ;
}
F_197 ( & V_12 -> V_330 ) ;
}
}
F_367 ( V_642 ) ;
if ( V_54 )
goto V_654;
}
memset ( & V_641 , 0 , sizeof( V_641 ) ) ;
V_641 . V_597 =
F_152 ( F_339 ( V_598 ) |
V_599 |
V_600 ) ;
V_641 . V_601 =
F_152 ( V_669 |
F_376 ( V_643 ) |
F_377 ( V_644 >> 16 ) |
F_340 ( V_641 ) ) ;
V_54 = F_341 ( V_12 , V_12 -> V_27 , & V_641 , sizeof( V_641 ) ,
& V_641 ) ;
if ( V_54 == - V_670 ) {
memset ( & V_641 , 0 , sizeof( V_641 ) ) ;
V_641 . V_597 =
F_152 ( F_339 ( V_598 ) |
V_599 |
V_600 ) ;
V_641 . V_601 = F_152 ( F_340 ( V_641 ) ) ;
V_54 = F_341 ( V_12 , V_12 -> V_27 , & V_641 ,
sizeof( V_641 ) , & V_641 ) ;
V_651 = L_58 ;
}
V_648 = 1 ;
if ( V_54 < 0 )
goto V_654;
V_645 = F_48 ( V_641 . V_645 ) ;
V_646 = F_48 ( V_641 . V_646 ) ;
V_647 = F_48 ( V_641 . V_647 ) ;
if ( V_646 != V_647 )
F_363 ( V_12 -> V_30 , L_59\
L_60 ,
V_646 , V_647 ) ;
V_641 . V_597 =
F_152 ( F_339 ( V_598 ) |
V_599 |
V_602 ) ;
V_641 . V_601 = F_152 ( F_340 ( V_641 ) ) ;
V_54 = F_341 ( V_12 , V_12 -> V_27 , & V_641 , sizeof( V_641 ) ,
NULL ) ;
if ( V_54 < 0 )
goto V_654;
V_54 = F_353 ( V_12 ) ;
if ( V_54 < 0 )
goto V_654;
V_54 = F_378 ( V_12 , V_12 -> V_27 ) ;
if ( V_54 < 0 )
goto V_654;
F_308 ( V_12 -> V_30 , L_61\
L_62 ,
V_651 , V_645 , V_647 ) ;
return 0 ;
V_654:
if ( V_648 && V_54 != - V_670 )
F_363 ( V_12 -> V_30 , L_63 ,
V_651 , - V_54 ) ;
return V_54 ;
}
static struct V_671 * F_379 ( int V_189 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_672 ) ; V_19 ++ ) {
if ( V_672 [ V_19 ] . V_189 == V_189 )
return & V_672 [ V_19 ] ;
}
return NULL ;
}
static int F_380 ( struct V_12 * V_13 )
{
int V_54 ;
T_1 V_132 , V_673 ;
enum V_674 V_35 ;
T_1 V_188 [ 7 ] , V_335 [ 7 ] ;
struct V_595 V_641 ;
int V_640 = 1 ;
V_54 = F_381 ( V_13 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_382 ( V_13 , V_13 -> V_27 , V_13 -> V_27 ,
F_383 () ? V_675 : V_676 , & V_35 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_64 ,
V_54 ) ;
return V_54 ;
}
if ( V_54 == V_13 -> V_27 )
V_13 -> V_68 |= V_136 ;
F_384 ( V_13 , & V_13 -> V_188 . V_677 ) ;
F_385 ( V_13 , & V_13 -> V_188 . V_678 ) ;
F_386 ( V_13 , & V_13 -> V_188 . V_679 ) ;
F_387 ( V_13 , & V_13 -> V_188 . V_680 ) ;
V_54 = F_388 ( V_13 ) ;
if ( V_54 )
V_35 = V_681 ;
if ( ( V_13 -> V_68 & V_136 ) && V_35 != V_682 ) {
struct V_671 * V_671 ;
struct V_683 * V_684 ;
const struct V_632 * V_685 ;
const T_3 * V_686 = NULL ;
unsigned int V_687 = 0 ;
V_671 = F_379 ( F_168 ( V_13 -> V_188 . V_189 ) ) ;
if ( V_671 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_65 ,
F_168 ( V_13 -> V_188 . V_189 ) ) ;
return - V_65 ;
}
V_684 = F_110 ( sizeof( * V_684 ) ) ;
V_54 = F_371 ( & V_685 , V_671 -> V_688 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_66 ,
V_671 -> V_688 , V_54 ) ;
} else {
V_686 = V_685 -> V_109 ;
V_687 = V_685 -> V_192 ;
}
V_54 = F_389 ( V_13 , V_671 , V_686 , V_687 , V_684 ,
V_35 , & V_640 ) ;
F_367 ( V_685 ) ;
F_112 ( V_684 ) ;
if ( V_54 < 0 )
goto V_654;
}
V_54 = F_390 ( V_13 , & V_13 -> V_188 . V_531 ) ;
if ( V_54 < 0 )
goto V_654;
V_132 =
F_7 ( V_662 ) |
F_8 ( V_689 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_132 , & V_673 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_188 . V_690 = F_391 ( V_673 ) ;
V_13 -> V_188 . V_691 = V_673 ;
if ( V_35 == V_682 ) {
F_308 ( V_13 -> V_30 , L_67\
L_68 ,
V_13 -> V_68 & V_136 ? L_69 : L_70 ) ;
} else {
F_308 ( V_13 -> V_30 , L_71\
L_72 ) ;
V_188 [ 0 ] = ( F_7 ( V_662 ) |
F_8 ( V_663 ) ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_188 , V_335 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_73
L_74 ) ;
goto V_654;
}
V_54 = F_368 ( V_13 , V_640 ) ;
if ( V_54 == - V_670 ) {
F_11 ( V_13 -> V_30 , L_75
L_76 ) ;
goto V_654;
}
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_77
L_78 , - V_54 ) ;
goto V_654;
}
}
V_54 = F_344 ( V_13 ) ;
if ( V_54 < 0 )
goto V_654;
if ( F_392 ( V_13 -> V_128 -> V_373 ) )
V_13 -> V_188 . V_692 = 1 ;
#define F_393 ( T_13 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_394 ( T_13 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_188 [ 0 ] = F_394 ( V_693 ) ;
V_188 [ 1 ] = F_394 ( V_694 ) ;
V_188 [ 2 ] = F_394 ( V_695 ) ;
V_188 [ 3 ] = F_394 ( V_696 ) ;
V_188 [ 4 ] = F_394 ( V_697 ) ;
V_188 [ 5 ] = F_394 ( V_698 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_16 . V_99 = V_335 [ 0 ] ;
V_13 -> V_699 = V_335 [ 1 ] ;
V_13 -> V_700 = V_335 [ 2 ] ;
V_13 -> V_248 . V_701 = V_335 [ 3 ] ;
V_13 -> V_248 . V_262 = V_335 [ 4 ] - V_335 [ 3 ] + 1 ;
V_13 -> V_16 . V_163 = V_335 [ 5 ] ;
V_188 [ 0 ] = F_394 ( V_702 ) ;
V_188 [ 1 ] = F_394 ( V_703 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_16 . V_172 = V_335 [ 0 ] - V_13 -> V_16 . V_99 + 1 ;
V_13 -> V_16 . V_165 = V_335 [ 1 ] - V_13 -> V_16 . V_163 + 1 ;
V_13 -> V_16 . V_98 = F_395 ( V_13 -> V_16 . V_172 ,
sizeof( * V_13 -> V_16 . V_98 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_98 ) {
V_54 = - V_61 ;
goto V_654;
}
V_13 -> V_16 . V_164 = F_395 ( V_13 -> V_16 . V_165 ,
sizeof( * V_13 -> V_16 . V_164 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_164 ) {
V_54 = - V_61 ;
goto V_654;
}
V_13 -> V_16 . V_171 = F_395 ( F_164 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_171 ) {
V_54 = - V_61 ;
goto V_654;
}
V_13 -> V_16 . V_173 = F_395 ( F_164 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_173 ) {
V_54 = - V_61 ;
goto V_654;
}
#ifdef F_132
V_13 -> V_16 . V_704 = F_395 ( F_164 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_704 ) {
V_54 = - V_61 ;
goto V_654;
}
#endif
V_188 [ 0 ] = F_394 ( V_705 ) ;
V_188 [ 1 ] = F_394 ( V_706 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_707 = V_335 [ 0 ] ;
V_13 -> V_708 = V_335 [ 1 ] ;
V_13 -> V_188 . V_709 = F_107 ( V_13 -> V_188 . V_189 ) ? 15 : 16 ;
V_188 [ 0 ] = F_394 ( V_710 ) ;
V_188 [ 1 ] = F_394 ( V_711 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_335 ) ;
if ( ( V_335 [ 0 ] != V_335 [ 1 ] ) && ( V_54 >= 0 ) ) {
V_13 -> V_68 |= V_712 ;
V_13 -> V_248 . V_713 = V_335 [ 0 ] ;
V_13 -> V_248 . V_714 = V_335 [ 1 ] ;
}
V_188 [ 0 ] = F_394 ( V_715 ) ;
V_335 [ 0 ] = 1 ;
( void ) F_126 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_188 , V_335 ) ;
if ( F_107 ( V_13 -> V_188 . V_189 ) ) {
V_13 -> V_188 . V_716 = false ;
} else {
V_188 [ 0 ] = F_393 ( V_717 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_335 ) ;
V_13 -> V_188 . V_716 = ( V_54 == 0 && V_335 [ 0 ] != 0 ) ;
}
V_188 [ 0 ] = F_393 ( V_718 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_335 ) ;
V_13 -> V_188 . V_719 = ( V_54 == 0 && V_335 [ 0 ] != 0 ) ;
memset ( & V_641 , 0 , sizeof( V_641 ) ) ;
V_641 . V_597 = F_152 ( F_339 ( V_598 ) |
V_599 | V_600 ) ;
V_641 . V_601 = F_152 ( F_340 ( V_641 ) ) ;
V_54 = F_341 ( V_13 , V_13 -> V_27 , & V_641 , sizeof( V_641 ) ,
& V_641 ) ;
if ( V_54 < 0 )
goto V_654;
if ( V_641 . V_720 ) {
V_188 [ 0 ] = F_393 ( V_721 ) ;
V_188 [ 1 ] = F_394 ( V_722 ) ;
V_188 [ 2 ] = F_394 ( V_723 ) ;
V_188 [ 3 ] = F_394 ( V_724 ) ;
V_188 [ 4 ] = F_394 ( V_725 ) ;
V_188 [ 5 ] = F_393 ( V_726 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_248 . V_257 = V_335 [ 0 ] ;
V_13 -> V_248 . V_263 = F_396 ( V_13 -> V_248 . V_257 / 2 , V_727 ) ;
V_13 -> V_248 . V_236 = V_335 [ 1 ] ;
V_13 -> V_248 . V_234 = V_335 [ 2 ] - V_335 [ 1 ] + 1 ;
if ( V_13 -> V_68 & V_712 && ! F_397 ( V_13 ) ) {
V_13 -> V_248 . V_239 = V_13 -> V_248 . V_701 +
F_398 ( V_13 -> V_248 . V_262 , 3 ) ;
V_13 -> V_248 . V_238 = V_13 -> V_248 . V_262 -
F_398 ( V_13 -> V_248 . V_262 , 3 ) ;
V_13 -> V_248 . V_262 = V_13 -> V_248 . V_239 -
V_13 -> V_248 . V_701 ;
}
V_13 -> V_350 . V_728 . V_351 = V_335 [ 3 ] ;
V_13 -> V_350 . V_728 . V_192 = V_335 [ 4 ] - V_335 [ 3 ] + 1 ;
V_13 -> V_188 . V_729 = V_335 [ 5 ] ;
V_13 -> V_188 . V_730 = 1 ;
V_13 -> V_731 += 1 ;
}
if ( V_641 . V_732 ) {
V_188 [ 0 ] = F_394 ( V_733 ) ;
V_188 [ 1 ] = F_394 ( V_734 ) ;
V_188 [ 2 ] = F_394 ( V_735 ) ;
V_188 [ 3 ] = F_394 ( V_736 ) ;
V_188 [ 4 ] = F_394 ( V_737 ) ;
V_188 [ 5 ] = F_394 ( V_738 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_350 . V_337 . V_351 = V_335 [ 0 ] ;
V_13 -> V_350 . V_337 . V_192 = V_335 [ 1 ] - V_335 [ 0 ] + 1 ;
V_13 -> V_350 . V_739 . V_351 = V_335 [ 2 ] ;
V_13 -> V_350 . V_739 . V_192 = V_335 [ 3 ] - V_335 [ 2 ] + 1 ;
V_13 -> V_350 . V_740 . V_351 = V_335 [ 4 ] ;
V_13 -> V_350 . V_740 . V_192 = V_335 [ 5 ] - V_335 [ 4 ] + 1 ;
V_188 [ 0 ] = F_394 ( V_741 ) ;
V_188 [ 1 ] = F_394 ( V_742 ) ;
V_188 [ 2 ] = F_394 ( V_743 ) ;
V_188 [ 3 ] = F_394 ( V_744 ) ;
V_188 [ 4 ] = F_394 ( V_745 ) ;
V_188 [ 5 ] = F_394 ( V_746 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 ,
V_335 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_350 . V_747 . V_351 = V_335 [ 0 ] ;
V_13 -> V_350 . V_747 . V_192 = V_335 [ 1 ] - V_335 [ 0 ] + 1 ;
V_13 -> V_350 . V_748 . V_351 = V_335 [ 2 ] ;
V_13 -> V_350 . V_748 . V_192 = V_335 [ 3 ] - V_335 [ 2 ] + 1 ;
V_13 -> V_350 . V_589 . V_351 = V_335 [ 4 ] ;
V_13 -> V_350 . V_589 . V_192 = V_335 [ 5 ] - V_335 [ 4 ] + 1 ;
V_188 [ 0 ] = F_393 ( V_749 ) ;
V_188 [ 1 ] = F_393 ( V_750 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 ,
V_335 ) ;
if ( V_54 < 0 ) {
V_13 -> V_188 . V_751 = 8 ;
V_13 -> V_188 . V_752 = 32 * V_13 -> V_248 . V_257 ;
V_54 = 0 ;
} else {
V_13 -> V_188 . V_751 = V_335 [ 0 ] ;
V_13 -> V_188 . V_752 = V_335 [ 1 ] ;
}
F_308 ( V_13 -> V_30 ,
L_79 ,
V_13 -> V_188 . V_751 ,
V_13 -> V_188 . V_752 ) ;
V_13 -> V_731 += 2 ;
}
if ( V_641 . V_753 ) {
V_188 [ 0 ] = F_394 ( V_754 ) ;
V_188 [ 1 ] = F_394 ( V_755 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_654;
V_13 -> V_350 . V_756 . V_351 = V_335 [ 0 ] ;
V_13 -> V_350 . V_756 . V_192 = V_335 [ 1 ] - V_335 [ 0 ] + 1 ;
V_13 -> V_731 += 2 ;
}
if ( V_641 . V_757 ) {
V_13 -> V_188 . V_758 |= V_759 ;
V_13 -> V_760 += 1 ;
}
#undef F_394
#undef F_393
F_399 ( V_13 , V_13 -> V_188 . V_298 , NULL ) ;
if ( V_35 != V_682 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_299 ; V_19 ++ )
if ( V_13 -> V_188 . V_298 [ V_19 ] == 1492 ) {
V_13 -> V_188 . V_298 [ V_19 ] = 1488 ;
break;
}
F_400 ( V_13 , V_13 -> V_188 . V_298 , V_13 -> V_188 . V_761 ,
V_13 -> V_188 . V_762 ) ;
}
F_401 ( V_13 ) ;
V_13 -> V_68 |= V_763 ;
F_402 ( V_13 ) ;
return 0 ;
V_654:
F_34 ( V_13 -> V_16 . V_98 ) ;
F_34 ( V_13 -> V_16 . V_164 ) ;
F_34 ( V_13 -> V_16 . V_171 ) ;
F_34 ( V_13 -> V_16 . V_173 ) ;
#ifdef F_132
F_34 ( V_13 -> V_16 . V_704 ) ;
#endif
if ( V_54 != - V_764 && V_54 != - V_765 )
F_403 ( V_13 , V_13 -> V_27 ) ;
return V_54 ;
}
static T_14 F_404 ( struct V_317 * V_128 ,
T_15 V_35 )
{
int V_19 ;
struct V_12 * V_13 = F_194 ( V_128 ) ;
if ( ! V_13 )
goto V_59;
F_405 () ;
V_13 -> V_68 &= ~ V_763 ;
F_260 ( V_13 , V_766 ) ;
F_195 ( & V_13 -> V_321 ) ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
F_406 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_197 ( & V_13 -> V_321 ) ;
F_91 ( V_13 ) ;
if ( V_13 -> V_68 & V_168 )
F_274 ( V_13 ) ;
F_407 () ;
if ( ( V_13 -> V_68 & V_767 ) ) {
F_408 ( V_128 ) ;
V_13 -> V_68 &= ~ V_767 ;
}
V_59: return V_35 == V_768 ?
V_769 : V_770 ;
}
static T_14 F_409 ( struct V_317 * V_128 )
{
int V_19 , V_54 ;
struct V_595 V_596 ;
struct V_12 * V_13 = F_194 ( V_128 ) ;
if ( ! V_13 ) {
F_410 ( V_128 ) ;
F_411 ( V_128 ) ;
return V_771 ;
}
if ( ! ( V_13 -> V_68 & V_767 ) ) {
if ( F_412 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 , L_80
L_81 ) ;
return V_769 ;
}
V_13 -> V_68 |= V_767 ;
}
F_413 ( V_128 ) ;
F_410 ( V_128 ) ;
F_411 ( V_128 ) ;
F_414 ( V_128 ) ;
if ( F_415 ( V_13 -> V_772 ) < 0 )
return V_769 ;
if ( F_382 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_675 , NULL ) < 0 )
return V_769 ;
V_13 -> V_68 |= V_763 ;
if ( F_338 ( V_13 , & V_596 ) )
return V_769 ;
F_73 (adap, i) {
struct V_5 * V_6 = F_84 ( V_13 , V_19 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_6 -> V_76 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_54 < 0 )
return V_769 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_74 = - 1 ;
}
F_400 ( V_13 , V_13 -> V_188 . V_298 , V_13 -> V_188 . V_761 ,
V_13 -> V_188 . V_762 ) ;
F_327 ( V_13 ) ;
if ( F_269 ( V_13 ) )
return V_769 ;
return V_771 ;
}
static void F_417 ( struct V_317 * V_128 )
{
int V_19 ;
struct V_12 * V_13 = F_194 ( V_128 ) ;
if ( ! V_13 )
return;
F_405 () ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( F_14 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_300 ( V_2 ) ;
}
F_418 ( V_2 ) ;
}
F_407 () ;
}
static inline bool F_419 ( const struct V_773 * V_774 )
{
unsigned int V_775 , V_776 ;
V_775 = F_420 ( F_421 ( V_774 -> V_777 ) ) ;
V_776 = V_775 & ~ ( V_778 | V_779 ) ;
return V_776 != 0 ;
}
static void F_422 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 = 0 , V_780 = 0 , V_781 = 0 ;
#ifndef F_16
int V_782 = 0 ;
#endif
if ( F_383 () ) {
V_13 -> V_188 . V_730 = 0 ;
V_13 -> V_188 . V_758 = 0 ;
} else if ( F_423 ( V_13 ) && F_424 ( V_13 ) ) {
V_13 -> V_188 . V_730 = 0 ;
V_13 -> V_188 . V_758 = 0 ;
}
V_780 += F_419 ( & F_84 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_16
if ( V_13 -> V_188 . V_690 * 8 > V_783 ) {
F_11 ( V_13 -> V_30 , L_82 ,
V_783 , V_13 -> V_188 . V_690 * 8 ) ;
F_425 ( 1 ) ;
}
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_781 ;
V_11 -> V_20 = 8 ;
V_781 += V_11 -> V_20 ;
}
#else
if ( V_780 )
V_782 = ( V_783 - ( V_13 -> V_188 . V_690 - V_780 ) ) / V_780 ;
if ( V_782 > F_426 () )
V_782 = F_426 () ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_781 ;
V_11 -> V_20 = F_419 ( & V_11 -> V_7 ) ? V_782 : 1 ;
V_781 += V_11 -> V_20 ;
}
#endif
V_4 -> V_784 = V_781 ;
V_4 -> V_785 = V_781 ;
if ( F_423 ( V_13 ) ) {
if ( V_780 ) {
V_19 = F_427 ( int , V_786 , F_428 () ) ;
V_4 -> V_787 = F_429 ( V_19 , V_13 -> V_188 . V_690 ) ;
} else {
V_4 -> V_787 = V_13 -> V_188 . V_690 ;
}
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_148 ) ; V_19 ++ ) {
struct V_153 * V_788 = & V_4 -> V_148 [ V_19 ] ;
F_430 ( V_13 , & V_788 -> V_149 , 5 , 10 , 1024 , 64 ) ;
V_788 -> V_181 . V_192 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_192 = 1024 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_187 ) ; V_19 ++ )
V_4 -> V_187 [ V_19 ] . V_25 . V_192 = 512 ;
F_430 ( V_13 , & V_4 -> V_147 , 0 , 1 , 1024 , 64 ) ;
F_430 ( V_13 , & V_4 -> V_174 , 0 , 1 , 512 , 64 ) ;
}
static void F_431 ( struct V_12 * V_13 , int V_140 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_140 < V_13 -> V_16 . V_784 )
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_784 -- ;
if ( V_13 -> V_16 . V_784 <= V_140 )
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
static int F_432 ( struct V_12 * V_13 )
{
struct V_789 * V_141 ;
unsigned int V_790 = 0 ;
if ( F_167 ( V_13 ) )
V_790 += V_786 * V_13 -> V_731 ;
if ( F_433 ( V_13 ) )
V_790 += V_786 * V_13 -> V_760 ;
if ( ! V_790 )
goto V_59;
V_141 = F_395 ( V_790 , sizeof( * V_141 ) , V_156 ) ;
if ( ! V_141 )
return - V_61 ;
V_13 -> V_791 . V_792 = F_395 ( F_164 ( V_790 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_791 . V_792 ) {
F_34 ( V_141 ) ;
return - V_61 ;
}
F_165 ( & V_13 -> V_791 . V_793 ) ;
V_13 -> V_794 = V_141 ;
V_59:
return 0 ;
}
static void F_434 ( struct V_12 * V_13 )
{
if ( ! ( V_13 -> V_760 && V_13 -> V_731 ) )
return;
F_34 ( V_13 -> V_794 ) ;
F_34 ( V_13 -> V_791 . V_792 ) ;
}
static int F_435 ( struct V_12 * V_13 )
{
int V_795 = 0 , V_796 = 0 ;
int V_19 , V_138 , V_797 , V_798 , V_799 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_800 = V_13 -> V_188 . V_690 ;
struct V_801 * V_802 ;
int V_790 = V_606 ;
if ( F_433 ( V_13 ) )
V_790 += ( V_786 * V_13 -> V_760 ) ;
if ( F_167 ( V_13 ) )
V_790 += ( V_786 * V_13 -> V_731 ) ;
V_802 = F_80 ( sizeof( * V_802 ) * ( V_790 + 1 ) ,
V_156 ) ;
if ( ! V_802 )
return - V_61 ;
if ( F_432 ( V_13 ) ) {
V_13 -> V_188 . V_730 = 0 ;
V_13 -> V_188 . V_758 = 0 ;
}
for ( V_19 = 0 ; V_19 < V_790 + 1 ; ++ V_19 )
V_802 [ V_19 ] . V_49 = V_19 ;
V_797 = V_4 -> V_785 + V_803 ;
if ( F_167 ( V_13 ) ) {
V_797 += V_13 -> V_731 * V_4 -> V_787 ;
V_795 = V_13 -> V_731 * V_800 ;
}
if ( F_433 ( V_13 ) ) {
V_797 += V_13 -> V_760 * V_4 -> V_787 ;
V_796 = V_13 -> V_760 * V_800 ;
}
#ifdef F_16
V_798 = 8 * V_13 -> V_188 . V_690 + V_803 + V_795 + V_796 ;
#else
V_798 = V_13 -> V_188 . V_690 + V_803 + V_795 + V_796 ;
#endif
V_799 = F_436 ( V_13 -> V_128 , V_802 , V_798 , V_797 ) ;
if ( V_799 < 0 ) {
F_308 ( V_13 -> V_30 , L_83
L_84 ) ;
F_34 ( V_802 ) ;
return V_799 ;
}
V_19 = V_799 - V_803 - V_795 - V_796 ;
if ( V_19 < V_4 -> V_785 ) {
V_4 -> V_785 = V_19 ;
if ( V_19 < V_4 -> V_784 )
F_431 ( V_13 , V_19 ) ;
}
if ( F_423 ( V_13 ) ) {
if ( V_799 < V_797 )
V_4 -> V_804 = V_800 ;
else
V_4 -> V_804 = V_4 -> V_787 ;
}
for ( V_19 = 0 ; V_19 < ( V_4 -> V_785 + V_803 ) ; ++ V_19 )
V_13 -> V_141 [ V_19 ] . V_46 = V_802 [ V_19 ] . V_805 ;
if ( F_423 ( V_13 ) ) {
for ( V_138 = 0 ; V_19 < V_799 ; ++ V_19 , V_138 ++ ) {
V_13 -> V_794 [ V_138 ] . V_46 = V_802 [ V_19 ] . V_805 ;
V_13 -> V_794 [ V_138 ] . V_184 = V_19 ;
}
V_13 -> V_791 . V_806 = V_138 ;
}
F_308 ( V_13 -> V_30 , L_85
L_86 ,
V_799 , V_4 -> V_785 , V_4 -> V_804 ) ;
F_34 ( V_802 ) ;
return 0 ;
}
static int F_437 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_438 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_152 = F_395 ( V_11 -> V_155 , sizeof( T_6 ) , V_156 ) ;
if ( ! V_11 -> V_152 )
return - V_61 ;
}
return 0 ;
}
static int F_439 ( struct V_12 * V_13 ,
enum V_807 * V_8 ,
enum V_808 * V_809 )
{
T_1 V_810 , V_811 ;
int V_812 , V_813 ;
#define F_440 4
* V_8 = V_814 ;
* V_809 = V_815 ;
V_812 = F_441 ( V_13 -> V_128 , V_816 ,
& V_810 ) ;
V_813 = F_441 ( V_13 -> V_128 , V_817 ,
& V_811 ) ;
if ( ! V_813 && V_811 ) {
if ( V_811 & V_818 )
* V_8 = V_819 ;
else if ( V_811 & V_820 )
* V_8 = V_821 ;
else if ( V_811 & V_822 )
* V_8 = V_823 ;
}
if ( ! V_812 ) {
* V_809 = ( V_810 & V_824 ) >> F_440 ;
if ( ! V_811 ) {
if ( V_810 & V_825 )
* V_8 = V_821 ;
else if ( V_810 & V_826 )
* V_8 = V_823 ;
}
}
if ( * V_8 == V_814 || * V_809 == V_815 )
return V_812 ? V_812 : V_813 ? V_813 : - V_65 ;
return 0 ;
}
static void F_442 ( struct V_12 * V_13 )
{
enum V_808 V_809 , V_827 ;
enum V_807 V_8 , V_828 ;
#define F_443 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_439 ( V_13 , & V_828 , & V_827 ) ) {
F_363 ( V_13 -> V_30 ,
L_87 ) ;
return;
}
if ( F_444 ( V_13 -> V_128 , & V_8 , & V_809 ) ||
V_8 == V_814 || V_809 == V_815 ) {
F_363 ( V_13 -> V_30 ,
L_88 ) ;
return;
}
F_308 ( V_13 -> V_30 , L_89 ,
F_443 ( V_8 ) , F_443 ( V_828 ) ) ;
F_308 ( V_13 -> V_30 , L_90 ,
V_809 , V_827 ) ;
if ( V_8 < V_828 || V_809 < V_827 )
F_308 ( V_13 -> V_30 ,
L_91
L_92 ) ;
}
static void F_445 ( struct V_12 * V_12 )
{
F_308 ( V_12 -> V_30 , L_93 ,
V_12 -> V_188 . V_531 . V_829 ,
F_446 ( V_12 -> V_188 . V_189 ) ) ;
F_308 ( V_12 -> V_30 , L_94 ,
V_12 -> V_188 . V_531 . V_830 , V_12 -> V_188 . V_531 . V_831 ) ;
if ( ! V_12 -> V_188 . V_677 )
F_363 ( V_12 -> V_30 , L_95 ) ;
else
F_308 ( V_12 -> V_30 , L_96 ,
F_447 ( V_12 -> V_188 . V_677 ) ,
F_448 ( V_12 -> V_188 . V_677 ) ,
F_449 ( V_12 -> V_188 . V_677 ) ,
F_450 ( V_12 -> V_188 . V_677 ) ) ;
if ( ! V_12 -> V_188 . V_678 )
F_308 ( V_12 -> V_30 , L_97 ) ;
else
F_308 ( V_12 -> V_30 , L_98 ,
F_447 ( V_12 -> V_188 . V_678 ) ,
F_448 ( V_12 -> V_188 . V_678 ) ,
F_449 ( V_12 -> V_188 . V_678 ) ,
F_450 ( V_12 -> V_188 . V_678 ) ) ;
if ( ! V_12 -> V_188 . V_679 )
F_363 ( V_12 -> V_30 , L_99 ) ;
else
F_308 ( V_12 -> V_30 ,
L_100 ,
F_447 ( V_12 -> V_188 . V_679 ) ,
F_448 ( V_12 -> V_188 . V_679 ) ,
F_449 ( V_12 -> V_188 . V_679 ) ,
F_450 ( V_12 -> V_188 . V_679 ) ) ;
if ( ! V_12 -> V_188 . V_680 )
F_308 ( V_12 -> V_30 , L_101 ) ;
else
F_308 ( V_12 -> V_30 ,
L_102 ,
F_447 ( V_12 -> V_188 . V_680 ) ,
F_448 ( V_12 -> V_188 . V_680 ) ,
F_449 ( V_12 -> V_188 . V_680 ) ,
F_450 ( V_12 -> V_188 . V_680 ) ) ;
F_308 ( V_12 -> V_30 , L_103 ,
F_167 ( V_12 ) ? L_104 : L_105 ,
( ( V_12 -> V_68 & V_127 ) ? L_106 :
( V_12 -> V_68 & V_129 ) ? L_107 : L_105 ) ,
F_167 ( V_12 ) ? L_108 : L_109 ) ;
}
static void F_451 ( const struct V_1 * V_2 )
{
char V_667 [ 80 ] ;
char * V_832 = V_667 ;
const char * V_833 = L_105 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_188 . V_834 . V_8 == V_835 )
V_833 = L_110 ;
else if ( V_13 -> V_188 . V_834 . V_8 == V_836 )
V_833 = L_111 ;
else if ( V_13 -> V_188 . V_834 . V_8 == V_837 )
V_833 = L_112 ;
if ( V_11 -> V_7 . V_777 & V_778 )
V_832 += sprintf ( V_832 , L_113 ) ;
if ( V_11 -> V_7 . V_777 & V_779 )
V_832 += sprintf ( V_832 , L_114 ) ;
if ( V_11 -> V_7 . V_777 & V_838 )
V_832 += sprintf ( V_832 , L_115 ) ;
if ( V_11 -> V_7 . V_777 & V_839 )
V_832 += sprintf ( V_832 , L_116 ) ;
if ( V_11 -> V_7 . V_777 & V_840 )
V_832 += sprintf ( V_832 , L_117 ) ;
if ( V_11 -> V_7 . V_777 & V_841 )
V_832 += sprintf ( V_832 , L_118 ) ;
if ( V_832 != V_667 )
-- V_832 ;
sprintf ( V_832 , L_119 , F_452 ( V_11 -> V_842 ) ) ;
F_3 ( V_2 , L_120 ,
V_2 -> V_9 , V_13 -> V_188 . V_531 . V_829 , V_13 -> V_9 , V_667 ) ;
}
static void F_453 ( struct V_317 * V_2 )
{
F_454 ( V_2 , V_843 , V_844 ) ;
}
static void F_455 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_112 ( V_12 -> V_845 ) ;
F_456 ( V_12 ) ;
F_112 ( V_12 -> V_248 . V_247 ) ;
F_457 ( V_12 ) ;
F_34 ( V_12 -> V_16 . V_98 ) ;
F_34 ( V_12 -> V_16 . V_164 ) ;
F_34 ( V_12 -> V_16 . V_171 ) ;
F_34 ( V_12 -> V_16 . V_173 ) ;
#ifdef F_132
F_34 ( V_12 -> V_16 . V_704 ) ;
#endif
F_64 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] ) {
struct V_5 * V_11 = F_84 ( V_12 , V_19 ) ;
if ( V_11 -> V_51 != 0 )
F_458 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_51 ) ;
F_34 ( F_84 ( V_12 , V_19 ) -> V_152 ) ;
F_459 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_12 -> V_68 & V_763 )
F_403 ( V_12 , V_12 -> V_28 ) ;
}
static int F_460 ( struct V_317 * V_128 , T_1 V_846 )
{
T_6 V_847 ;
F_461 ( V_128 , V_848 , & V_847 ) ;
switch ( V_847 >> 12 ) {
case V_655 :
return F_462 ( V_655 , V_846 ) ;
case V_271 :
return F_462 ( V_271 , V_846 ) ;
case V_658 :
return F_462 ( V_658 , V_846 ) ;
default:
F_11 ( & V_128 -> V_2 , L_55 ,
V_847 ) ;
}
return - V_65 ;
}
static void F_463 ( struct V_1 * V_2 )
{
V_2 -> type = V_849 ;
V_2 -> V_66 = 0 ;
V_2 -> V_850 = 0 ;
V_2 -> V_542 = 0 ;
V_2 -> V_851 = 0 ;
V_2 -> V_68 |= V_852 ;
V_2 -> V_375 |= V_853 ;
V_2 -> V_854 = & V_855 ;
V_2 -> V_856 = & V_857 ;
V_2 -> V_858 = F_459 ;
}
static int F_464 ( struct V_317 * V_128 )
{
struct V_12 * V_13 = F_194 ( V_128 ) ;
struct V_1 * V_52 ;
struct V_5 * V_11 ;
char V_9 [ V_859 ] ;
int V_22 ;
snprintf ( V_9 , V_859 , L_121 , V_13 -> V_860 , V_13 -> V_28 ) ;
V_52 = F_465 ( 0 , V_9 , V_861 , F_463 ) ;
if ( ! V_52 )
return - V_61 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_13 ;
F_466 ( V_52 , & V_128 -> V_2 ) ;
V_13 -> V_39 [ 0 ] = V_52 ;
V_22 = F_467 ( V_13 -> V_39 [ 0 ] ) ;
if ( V_22 ) {
F_5 ( L_122 , V_9 ) ;
F_459 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
return V_22 ;
}
return 0 ;
}
static int F_468 ( struct V_317 * V_128 , int V_532 )
{
struct V_12 * V_13 = F_194 ( V_128 ) ;
int V_22 = 0 ;
int V_862 = F_469 ( V_128 ) ;
T_1 V_863 ;
V_863 = F_470 ( V_13 -> V_772 + V_864 ) ;
if ( ! ( V_863 & V_865 ) ||
! ( V_863 & V_866 ) ||
F_471 ( V_863 ) != 4 ) {
F_363 ( & V_128 -> V_2 ,
L_123 ) ;
return - V_508 ;
}
if ( V_862 && F_472 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 ,
L_124 ) ;
V_532 = V_862 ;
return V_532 ;
}
if ( ! V_532 ) {
F_473 ( V_128 ) ;
if ( V_13 -> V_39 [ 0 ] ) {
F_474 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
}
F_34 ( V_13 -> V_533 ) ;
V_13 -> V_533 = NULL ;
V_13 -> V_532 = 0 ;
return V_532 ;
}
if ( V_532 != V_862 ) {
V_22 = F_475 ( V_128 , V_532 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_532 = V_532 ;
V_22 = F_464 ( V_128 ) ;
if ( V_22 )
return V_22 ;
}
V_13 -> V_533 = F_395 ( V_13 -> V_532 ,
sizeof( struct V_867 ) , V_156 ) ;
if ( V_13 -> V_533 )
F_303 ( V_13 ) ;
return V_532 ;
}
static int F_476 ( struct V_317 * V_128 , const struct V_868 * V_869 )
{
int V_870 , V_19 , V_22 , V_871 , V_872 , V_873 ;
struct V_5 * V_11 ;
bool V_874 = false ;
struct V_12 * V_12 = NULL ;
struct V_1 * V_52 ;
void T_16 * V_772 ;
T_1 V_875 , V_846 ;
enum V_309 V_189 ;
static int V_860 = 1 ;
F_477 ( V_876 L_125 , V_877 , V_878 ) ;
V_22 = F_478 ( V_128 , V_879 ) ;
if ( V_22 ) {
F_308 ( & V_128 -> V_2 , L_126 ) ;
return V_22 ;
}
V_22 = F_412 ( V_128 ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_127 ) ;
goto V_880;
}
V_772 = F_479 ( V_128 , 0 ) ;
if ( ! V_772 ) {
F_11 ( & V_128 -> V_2 , L_128 ) ;
V_22 = - V_61 ;
goto V_881;
}
V_22 = F_415 ( V_772 ) ;
if ( V_22 < 0 )
goto V_882;
V_875 = F_470 ( V_772 + V_883 ) ;
V_846 = F_480 ( F_470 ( V_772 + V_884 ) ) ;
V_189 = F_460 ( V_128 , V_846 ) ;
V_870 = F_168 ( V_189 ) <= V_271 ?
F_481 ( V_875 ) : F_482 ( V_875 ) ;
if ( V_870 != V_869 -> V_885 ) {
#ifndef F_483
F_484 ( V_772 ) ;
#endif
F_408 ( V_128 ) ;
F_411 ( V_128 ) ;
goto V_886;
}
if ( ! F_485 ( V_128 , F_486 ( 64 ) ) ) {
V_874 = true ;
V_22 = F_487 ( V_128 , F_486 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_129
L_130 ) ;
goto V_882;
}
} else {
V_22 = F_485 ( V_128 , F_486 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_131 ) ;
goto V_882;
}
}
F_488 ( V_128 ) ;
F_453 ( V_128 ) ;
F_413 ( V_128 ) ;
F_411 ( V_128 ) ;
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_882;
}
V_860 ++ ;
V_12 -> V_253 = F_489 ( L_132 ) ;
if ( ! V_12 -> V_253 ) {
V_22 = - V_61 ;
goto V_887;
}
V_12 -> V_888 = F_27 ( sizeof( * V_12 -> V_888 ) +
( sizeof( struct V_889 ) *
V_890 ) ,
V_156 ) ;
if ( ! V_12 -> V_888 ) {
V_22 = - V_61 ;
goto V_887;
}
V_12 -> V_888 -> V_192 = V_890 ;
V_12 -> V_68 |= V_767 ;
V_12 -> V_772 = V_772 ;
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_324 ( V_128 ) ;
V_12 -> V_27 = V_870 ;
V_12 -> V_28 = V_870 ;
V_12 -> V_891 = V_892 ;
memset ( V_12 -> V_81 , 0xff , sizeof( V_12 -> V_81 ) ) ;
F_165 ( & V_12 -> V_321 ) ;
F_165 ( & V_12 -> V_249 ) ;
F_165 ( & V_12 -> V_330 ) ;
F_490 ( & V_12 -> V_254 , F_156 ) ;
F_490 ( & V_12 -> V_398 , F_243 ) ;
F_490 ( & V_12 -> V_405 , F_248 ) ;
V_22 = F_491 ( V_12 ) ;
if ( V_22 )
goto V_887;
if ( ! F_107 ( V_12 -> V_188 . V_189 ) ) {
V_871 = ( V_893 +
( V_894 - V_893 ) *
V_12 -> V_28 ) ;
V_872 = 1 << F_492 ( F_68 ( V_12 ,
V_895 ) >> V_871 ) ;
V_873 = V_622 / V_896 ;
if ( V_872 > V_873 ) {
F_11 ( & V_128 -> V_2 ,
L_133 ) ;
V_22 = - V_65 ;
goto V_887;
}
V_12 -> V_411 = F_493 ( F_494 ( V_128 , 2 ) ,
F_495 ( V_128 , 2 ) ) ;
if ( ! V_12 -> V_411 ) {
F_11 ( & V_128 -> V_2 , L_134 ) ;
V_22 = - V_61 ;
goto V_887;
}
}
F_327 ( V_12 ) ;
V_22 = F_380 ( V_12 ) ;
#ifdef F_132
F_99 ( V_12 -> V_16 . V_704 , V_12 -> V_16 . V_172 ) ;
#endif
F_330 ( V_12 ) ;
if ( V_22 )
goto V_897;
if ( ! F_107 ( V_12 -> V_188 . V_189 ) )
F_70 ( V_12 , V_898 , F_496 ( 7 ) |
( F_217 ( V_12 -> V_188 . V_189 ) ? F_497 ( 0 ) :
F_498 ( 0 ) ) ) ;
F_73 (adapter, i) {
V_52 = F_499 ( sizeof( struct V_5 ) ,
V_783 ) ;
if ( ! V_52 ) {
V_22 = - V_61 ;
goto V_899;
}
F_466 ( V_52 , & V_128 -> V_2 ) ;
V_12 -> V_39 [ V_19 ] = V_52 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_74 = - 1 ;
V_11 -> V_31 = V_19 ;
V_52 -> V_130 = V_128 -> V_130 ;
V_52 -> V_900 = V_901 | V_902 |
V_903 | V_904 |
V_905 | V_906 |
V_907 | V_73 |
V_908 ;
if ( V_874 )
V_52 -> V_900 |= V_909 ;
V_52 -> V_72 |= V_52 -> V_900 ;
V_52 -> V_910 = V_52 -> V_72 & V_911 ;
V_52 -> V_375 |= V_912 ;
V_52 -> V_913 = 81 ;
V_52 -> V_304 = V_914 ;
V_52 -> V_854 = & V_915 ;
#ifdef F_16
V_52 -> V_916 = & V_917 ;
F_17 ( V_52 ) ;
#endif
F_500 ( V_52 ) ;
}
F_501 ( V_128 , V_12 ) ;
if ( V_12 -> V_68 & V_763 ) {
V_22 = F_502 ( V_12 , V_870 , V_870 , 0 ) ;
if ( V_22 )
goto V_899;
} else if ( V_12 -> V_188 . V_690 == 1 ) {
T_3 V_525 [ V_526 ] ;
T_3 * V_528 = V_12 -> V_188 . V_531 . V_528 ;
V_22 = F_304 ( V_12 , & V_12 -> V_188 . V_531 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_526 ; V_19 ++ )
V_525 [ V_19 ] = ( F_305 ( V_528 [ 2 * V_19 + 0 ] ) * 16 +
F_305 ( V_528 [ 2 * V_19 + 1 ] ) ) ;
F_503 ( V_12 , 0 , V_525 ) ;
}
}
F_422 ( V_12 ) ;
V_12 -> V_845 = F_504 ( V_12 -> V_699 , V_12 -> V_700 ) ;
if ( ! V_12 -> V_845 ) {
F_363 ( & V_128 -> V_2 , L_135 ) ;
V_12 -> V_188 . V_730 = 0 ;
}
#if F_262 ( V_440 )
if ( ( F_168 ( V_12 -> V_188 . V_189 ) <= V_271 ) &&
( ! ( F_68 ( V_12 , V_918 ) & V_919 ) ) ) {
F_363 ( & V_128 -> V_2 ,
L_136 ) ;
V_12 -> V_188 . V_730 = 0 ;
} else {
V_12 -> V_920 = F_505 ( V_12 -> V_707 ,
V_12 -> V_708 ) ;
if ( ! V_12 -> V_920 ) {
F_363 ( & V_128 -> V_2 ,
L_137 ) ;
V_12 -> V_188 . V_730 = 0 ;
}
}
#endif
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_11 -> V_921 = F_506 ( V_12 -> V_188 . V_709 ) ;
if ( ! V_11 -> V_921 )
F_363 ( & V_128 -> V_2 ,
L_138 ,
V_19 ) ;
}
if ( F_163 ( & V_12 -> V_248 ) < 0 ) {
F_363 ( & V_128 -> V_2 , L_139
L_140 ) ;
V_12 -> V_188 . V_730 = 0 ;
} else {
V_12 -> V_922 = F_507 ( V_12 ,
V_923 ) ;
if ( ! V_12 -> V_922 )
F_363 ( & V_128 -> V_2 ,
L_141 ) ;
}
if ( F_167 ( V_12 ) ) {
if ( F_68 ( V_12 , V_918 ) & V_924 ) {
T_1 V_258 , V_925 ;
if ( V_189 <= V_271 ) {
V_925 = V_926 ;
V_258 = F_68 ( V_12 , V_925 ) ;
V_12 -> V_248 . V_258 = V_258 / 4 ;
} else {
V_925 = V_927 ;
V_258 = F_68 ( V_12 , V_925 ) ;
V_12 -> V_248 . V_258 = V_258 ;
}
}
}
if ( V_928 > 1 && F_435 ( V_12 ) == 0 )
V_12 -> V_68 |= V_127 ;
else if ( V_928 > 0 && F_508 ( V_128 ) == 0 ) {
V_12 -> V_68 |= V_129 ;
if ( V_928 > 1 )
F_434 ( V_12 ) ;
}
F_442 ( V_12 ) ;
V_22 = F_437 ( V_12 ) ;
if ( V_22 )
goto V_899;
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_12 -> V_39 [ V_19 ] -> V_929 = V_11 -> V_446 ;
F_509 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_510 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_467 ( V_12 -> V_39 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_81 [ V_11 -> V_76 ] = V_19 ;
F_451 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_128 -> V_2 , L_142 ) ;
goto V_899;
}
if ( V_22 ) {
F_363 ( & V_128 -> V_2 , L_143 , V_19 ) ;
V_22 = 0 ;
}
if ( V_930 ) {
V_12 -> V_219 = F_511 ( F_324 ( V_128 ) ,
V_930 ) ;
F_130 ( V_12 ) ;
}
V_128 -> V_931 = 1 ;
if ( F_423 ( V_12 ) ) {
F_255 ( & V_418 ) ;
F_29 ( & V_12 -> V_419 , & V_422 ) ;
F_259 ( & V_418 ) ;
}
F_445 ( V_12 ) ;
F_98 ( V_12 ) ;
return 0 ;
V_886:
#ifdef F_483
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_932;
}
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_324 ( V_128 ) ;
V_12 -> V_27 = V_870 ;
V_12 -> V_28 = V_870 ;
V_12 -> V_772 = V_772 ;
V_12 -> V_860 = V_860 ;
V_12 -> V_888 = F_27 ( sizeof( * V_12 -> V_888 ) +
( sizeof( struct V_889 ) *
V_890 ) ,
V_156 ) ;
if ( ! V_12 -> V_888 ) {
V_22 = - V_61 ;
goto V_933;
}
F_501 ( V_128 , V_12 ) ;
return 0 ;
V_933:
F_34 ( V_12 ) ;
V_932:
F_484 ( V_772 ) ;
F_473 ( V_128 ) ;
F_512 ( V_128 ) ;
return V_22 ;
#else
return 0 ;
#endif
V_899:
F_455 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_434 ( V_12 ) ;
if ( V_12 -> V_760 || V_12 -> V_731 )
F_513 ( V_12 ) ;
V_897:
if ( ! F_107 ( V_12 -> V_188 . V_189 ) )
F_484 ( V_12 -> V_411 ) ;
V_887:
if ( V_12 -> V_253 )
F_514 ( V_12 -> V_253 ) ;
F_34 ( V_12 -> V_888 ) ;
F_34 ( V_12 ) ;
V_882:
F_484 ( V_772 ) ;
V_881:
F_515 ( V_128 ) ;
F_408 ( V_128 ) ;
V_880:
F_512 ( V_128 ) ;
return V_22 ;
}
static void F_516 ( struct V_317 * V_128 )
{
struct V_12 * V_12 = F_194 ( V_128 ) ;
if ( ! V_12 ) {
F_512 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_514 ( V_12 -> V_253 ) ;
if ( F_423 ( V_12 ) )
F_254 ( V_12 ) ;
F_91 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_934 == V_935 )
F_474 ( V_12 -> V_39 [ V_19 ] ) ;
F_517 ( V_12 -> V_219 ) ;
F_518 ( V_12 ) ;
if ( V_12 -> V_68 & V_168 )
F_274 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_434 ( V_12 ) ;
if ( V_12 -> V_760 || V_12 -> V_731 )
F_513 ( V_12 ) ;
F_455 ( V_12 ) ;
#if F_262 ( V_440 )
F_519 ( V_12 ) ;
#endif
F_484 ( V_12 -> V_772 ) ;
if ( ! F_107 ( V_12 -> V_188 . V_189 ) )
F_484 ( V_12 -> V_411 ) ;
F_515 ( V_128 ) ;
if ( ( V_12 -> V_68 & V_767 ) ) {
F_408 ( V_128 ) ;
V_12 -> V_68 &= ~ V_767 ;
}
F_512 ( V_128 ) ;
F_34 ( V_12 -> V_888 ) ;
F_520 () ;
F_34 ( V_12 ) ;
}
#ifdef F_483
else {
if ( V_12 -> V_39 [ 0 ] )
F_474 ( V_12 -> V_39 [ 0 ] ) ;
F_484 ( V_12 -> V_772 ) ;
F_34 ( V_12 -> V_533 ) ;
F_34 ( V_12 ) ;
F_473 ( V_128 ) ;
F_512 ( V_128 ) ;
}
#endif
}
static void F_521 ( struct V_317 * V_128 )
{
struct V_12 * V_12 = F_194 ( V_128 ) ;
if ( ! V_12 ) {
F_512 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_934 == V_935 )
F_279 ( V_12 -> V_39 [ V_19 ] ) ;
F_522 ( V_12 ) ;
F_91 ( V_12 ) ;
F_64 ( V_12 ) ;
F_276 ( V_12 ) ;
if ( V_12 -> V_68 & V_763 )
F_403 ( V_12 , V_12 -> V_27 ) ;
}
#ifdef F_483
else {
if ( V_12 -> V_39 [ 0 ] )
F_474 ( V_12 -> V_39 [ 0 ] ) ;
F_484 ( V_12 -> V_772 ) ;
F_34 ( V_12 -> V_533 ) ;
F_34 ( V_12 ) ;
F_473 ( V_128 ) ;
F_512 ( V_128 ) ;
}
#endif
}
static int T_17 F_523 ( void )
{
int V_54 ;
V_930 = F_511 ( V_879 , NULL ) ;
if ( ! V_930 )
F_524 ( L_144 ) ;
V_54 = F_525 ( & V_378 ) ;
if ( V_54 < 0 )
F_526 ( V_930 ) ;
#if F_262 ( V_440 )
if ( ! V_936 ) {
F_527 ( & V_937 ) ;
V_936 = true ;
}
#endif
return V_54 ;
}
static void T_18 F_528 ( void )
{
#if F_262 ( V_440 )
if ( V_936 ) {
F_529 ( & V_937 ) ;
V_936 = false ;
}
#endif
F_530 ( & V_378 ) ;
F_526 ( V_930 ) ;
}
