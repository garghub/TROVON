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
void * F_107 ( T_7 V_192 )
{
void * V_6 = F_27 ( V_192 , V_156 | V_193 ) ;
if ( ! V_6 )
V_6 = F_108 ( V_192 ) ;
return V_6 ;
}
void F_109 ( void * V_50 )
{
F_110 ( V_50 ) ;
}
static T_6 F_111 ( struct V_1 * V_2 , struct V_194 * V_195 ,
void * V_196 , T_8 V_197 )
{
int V_15 ;
#ifdef F_16
if ( F_12 ( V_2 ) ) {
T_6 V_198 ;
int V_22 ;
V_22 = F_112 ( V_195 , & V_198 ) ;
if ( F_51 ( V_22 ) ) {
if ( F_113 () )
F_114 ( V_2 ,
L_34 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_198 & V_199 ) >> V_200 ;
#ifdef F_115
if ( V_195 -> V_201 == F_116 ( V_202 ) )
V_15 = V_195 -> V_203 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_204 ) {
V_15 = ( F_117 ( V_195 )
? F_118 ( V_195 )
: F_119 () ) ;
while ( F_51 ( V_15 >= V_2 -> V_205 ) )
V_15 -= V_2 -> V_205 ;
return V_15 ;
}
return V_197 ( V_2 , V_195 ) % V_2 -> V_205 ;
}
static int F_120 ( const struct V_16 * V_4 , int time )
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
static int F_121 ( const struct V_16 * V_4 , int V_211 )
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
int F_122 ( struct V_84 * V_25 ,
unsigned int V_213 , unsigned int V_214 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_213 | V_214 ) == 0 )
V_214 = 1 ;
if ( V_214 ) {
int V_22 ;
T_1 V_132 , V_215 ;
V_215 = F_121 ( & V_13 -> V_16 , V_214 ) ;
if ( V_25 -> V_142 && V_25 -> V_216 != V_215 ) {
V_132 = F_7 ( V_23 ) |
F_8 (
V_217 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_123 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_132 , & V_215 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_216 = V_215 ;
}
V_213 = V_213 == 0 ? 6 : F_120 ( & V_13 -> V_16 , V_213 ) ;
V_25 -> V_170 = F_124 ( V_213 ) | F_125 ( V_214 > 0 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , T_9 V_72 )
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
static int F_127 ( struct V_12 * V_13 )
{
if ( F_128 ( V_13 -> V_219 ) )
return - 1 ;
#ifdef F_129
F_130 ( V_13 ) ;
#endif
return 0 ;
}
int F_131 ( struct V_220 * V_180 , void * V_109 )
{
int V_221 = - 1 ;
F_132 ( & V_180 -> V_222 ) ;
if ( V_180 -> V_223 ) {
union V_224 * V_6 = V_180 -> V_223 ;
V_221 = ( V_6 - V_180 -> V_225 ) + V_180 -> V_226 ;
V_180 -> V_223 = V_6 -> V_227 ;
V_6 -> V_109 = V_109 ;
V_180 -> V_228 ++ ;
}
F_133 ( & V_180 -> V_222 ) ;
return V_221 ;
}
void F_134 ( struct V_220 * V_180 , unsigned int V_221 )
{
union V_224 * V_6 = & V_180 -> V_225 [ V_221 - V_180 -> V_226 ] ;
F_132 ( & V_180 -> V_222 ) ;
V_6 -> V_227 = V_180 -> V_223 ;
V_180 -> V_223 = V_6 ;
V_180 -> V_228 -- ;
F_133 ( & V_180 -> V_222 ) ;
}
int F_135 ( struct V_220 * V_180 , int V_229 , void * V_109 )
{
int V_230 ;
F_132 ( & V_180 -> V_231 ) ;
if ( V_229 == V_232 ) {
V_230 = F_136 ( V_180 -> V_233 , V_180 -> V_234 ) ;
if ( V_230 < V_180 -> V_234 )
F_137 ( V_230 , V_180 -> V_233 ) ;
else
V_230 = - 1 ;
} else {
V_230 = F_138 ( V_180 -> V_233 , V_180 -> V_234 , 1 ) ;
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
F_133 ( & V_180 -> V_231 ) ;
return V_230 ;
}
int F_139 ( struct V_220 * V_180 , int V_229 , void * V_109 )
{
int V_230 ;
F_132 ( & V_180 -> V_231 ) ;
if ( V_229 == V_232 ) {
V_230 = F_140 ( V_180 -> V_233 ,
V_180 -> V_234 + V_180 -> V_238 , V_180 -> V_234 ) ;
if ( V_230 < ( V_180 -> V_234 + V_180 -> V_238 ) )
F_137 ( V_230 , V_180 -> V_233 ) ;
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
F_133 ( & V_180 -> V_231 ) ;
return V_230 ;
}
void F_141 ( struct V_220 * V_180 , unsigned int V_230 , int V_229 )
{
if ( V_180 -> V_238 && ( V_230 >= V_180 -> V_239 ) ) {
V_230 -= V_180 -> V_239 ;
V_230 += V_180 -> V_234 ;
} else {
V_230 -= V_180 -> V_236 ;
}
F_132 ( & V_180 -> V_231 ) ;
if ( V_229 == V_232 )
F_142 ( V_230 , V_180 -> V_233 ) ;
else
F_143 ( V_180 -> V_233 , V_230 , 1 ) ;
V_180 -> V_235 [ V_230 ] . V_109 = NULL ;
if ( V_230 < V_180 -> V_234 ) {
if ( V_229 == V_232 )
V_180 -> V_237 -- ;
else
V_180 -> V_237 -= 2 ;
} else {
V_180 -> V_240 -- ;
}
F_133 ( & V_180 -> V_231 ) ;
}
static void F_144 ( struct V_194 * V_195 , unsigned int V_241 ,
unsigned int V_242 )
{
struct V_243 * V_244 ;
F_145 ( V_195 , V_245 , V_241 ) ;
V_244 = (struct V_243 * ) F_146 ( V_195 , sizeof( * V_244 ) ) ;
F_147 ( V_244 , V_242 ) ;
F_148 ( V_244 ) = F_149 ( F_150 ( V_246 , V_242 ) ) ;
}
static void F_151 ( struct V_220 * V_180 , unsigned int V_241 ,
unsigned int V_242 )
{
void * * V_6 = & V_180 -> V_247 [ V_242 ] ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_248 ) ;
F_132 ( & V_13 -> V_249 ) ;
* V_6 = V_13 -> V_250 ;
V_13 -> V_250 = ( void * * ) ( ( V_251 ) V_6 | V_241 ) ;
if ( ! V_13 -> V_252 ) {
V_13 -> V_252 = true ;
F_152 ( V_13 -> V_253 , & V_13 -> V_254 ) ;
}
F_133 ( & V_13 -> V_249 ) ;
}
static void F_153 ( struct V_255 * V_256 )
{
struct V_194 * V_195 ;
struct V_12 * V_13 ;
V_13 = F_54 ( V_256 , struct V_12 , V_254 ) ;
F_132 ( & V_13 -> V_249 ) ;
while ( V_13 -> V_250 ) {
void * * V_6 = V_13 -> V_250 ;
unsigned int V_241 = ( V_251 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_241 ;
V_13 -> V_250 = * V_6 ;
* V_6 = NULL ;
F_133 ( & V_13 -> V_249 ) ;
while ( ! ( V_195 = F_154 ( sizeof( struct V_243 ) ,
V_156 ) ) )
F_155 ( 1 ) ;
F_144 ( V_195 , V_241 , V_6 - V_13 -> V_248 . V_247 ) ;
F_156 ( V_13 , V_195 ) ;
F_132 ( & V_13 -> V_249 ) ;
}
V_13 -> V_252 = false ;
F_133 ( & V_13 -> V_249 ) ;
}
void F_157 ( struct V_220 * V_180 , unsigned int V_241 , unsigned int V_242 )
{
struct V_194 * V_195 ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_248 ) ;
F_158 ( V_242 >= V_180 -> V_257 ) ;
if ( V_180 -> V_247 [ V_242 ] ) {
V_180 -> V_247 [ V_242 ] = NULL ;
if ( V_180 -> V_258 && ( V_242 >= V_180 -> V_258 ) )
F_159 ( & V_180 -> V_259 ) ;
else
F_159 ( & V_180 -> V_260 ) ;
}
V_195 = F_154 ( sizeof( struct V_243 ) , V_60 ) ;
if ( F_52 ( V_195 ) ) {
F_144 ( V_195 , V_241 , V_242 ) ;
F_156 ( V_13 , V_195 ) ;
} else
F_151 ( V_180 , V_241 , V_242 ) ;
}
static int F_160 ( struct V_220 * V_180 )
{
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_248 ) ;
unsigned int V_261 = V_180 -> V_262 + V_180 -> V_238 ;
unsigned int V_263 = V_180 -> V_263 ;
unsigned int V_264 ;
unsigned int V_265 ;
T_7 V_192 ;
V_264 = F_161 ( V_180 -> V_234 + V_180 -> V_238 ) ;
V_265 = F_161 ( V_180 -> V_262 ) ;
V_192 = V_180 -> V_257 * sizeof( * V_180 -> V_247 ) +
V_263 * sizeof( * V_180 -> V_225 ) +
V_180 -> V_234 * sizeof( * V_180 -> V_235 ) +
V_180 -> V_238 * sizeof( * V_180 -> V_235 ) +
V_264 * sizeof( long ) +
V_261 * sizeof( * V_180 -> V_266 ) +
V_265 * sizeof( long ) ;
V_180 -> V_247 = F_107 ( V_192 ) ;
if ( ! V_180 -> V_247 )
return - V_61 ;
V_180 -> V_225 = (union V_224 * ) & V_180 -> V_247 [ V_180 -> V_257 ] ;
V_180 -> V_235 = (struct V_267 * ) & V_180 -> V_225 [ V_263 ] ;
V_180 -> V_233 = ( unsigned long * ) & V_180 -> V_235 [ V_180 -> V_234 + V_180 -> V_238 ] ;
V_180 -> V_266 = (struct V_268 * ) & V_180 -> V_233 [ V_264 ] ;
V_180 -> V_269 = ( unsigned long * ) & V_180 -> V_266 [ V_261 ] ;
F_162 ( & V_180 -> V_231 ) ;
F_162 ( & V_180 -> V_222 ) ;
F_162 ( & V_180 -> V_270 ) ;
V_180 -> V_237 = 0 ;
V_180 -> V_240 = 0 ;
V_180 -> V_223 = NULL ;
V_180 -> V_228 = 0 ;
F_163 ( & V_180 -> V_260 , 0 ) ;
F_163 ( & V_180 -> V_259 , 0 ) ;
if ( V_263 ) {
while ( -- V_263 )
V_180 -> V_225 [ V_263 - 1 ] . V_227 = & V_180 -> V_225 [ V_263 ] ;
V_180 -> V_223 = V_180 -> V_225 ;
}
if ( F_164 ( V_13 ) ) {
F_96 ( V_180 -> V_233 , V_180 -> V_234 + V_180 -> V_238 ) ;
if ( ! V_180 -> V_236 &&
F_165 ( V_13 -> V_188 . V_189 ) <= V_271 )
F_137 ( 0 , V_180 -> V_233 ) ;
}
F_96 ( V_180 -> V_269 , V_180 -> V_262 ) ;
return 0 ;
}
int F_166 ( const struct V_1 * V_2 , unsigned int V_230 ,
T_10 V_272 , T_11 V_273 , T_11 V_274 ,
unsigned int V_275 )
{
unsigned int V_241 ;
struct V_194 * V_195 ;
struct V_12 * V_13 ;
struct V_276 * V_244 ;
int V_54 ;
V_195 = F_154 ( sizeof( * V_244 ) , V_156 ) ;
if ( ! V_195 )
return - V_61 ;
V_13 = F_167 ( V_2 ) ;
V_244 = (struct V_276 * ) F_146 ( V_195 , sizeof( * V_244 ) ) ;
F_147 ( V_244 , 0 ) ;
F_148 ( V_244 ) = F_149 ( F_150 ( V_277 , V_230 ) ) ;
V_244 -> V_278 = V_273 ;
V_244 -> V_279 = F_116 ( 0 ) ;
V_244 -> V_280 = V_272 ;
V_244 -> V_281 = F_149 ( 0 ) ;
V_241 = F_85 ( & V_13 -> V_16 , V_275 ) ;
V_244 -> V_282 = F_168 ( F_169 ( V_241 ) ) ;
V_244 -> V_283 = F_168 ( F_170 ( V_284 ) |
V_285 | F_171 ( V_275 ) ) ;
V_54 = F_172 ( V_13 , V_195 ) ;
return F_173 ( V_54 ) ;
}
int F_174 ( const struct V_1 * V_2 , unsigned int V_230 ,
const struct V_286 * V_272 , T_11 V_273 ,
unsigned int V_275 )
{
unsigned int V_241 ;
struct V_194 * V_195 ;
struct V_12 * V_13 ;
struct V_287 * V_244 ;
int V_54 ;
V_195 = F_154 ( sizeof( * V_244 ) , V_156 ) ;
if ( ! V_195 )
return - V_61 ;
V_13 = F_167 ( V_2 ) ;
V_244 = (struct V_287 * ) F_146 ( V_195 , sizeof( * V_244 ) ) ;
F_147 ( V_244 , 0 ) ;
F_148 ( V_244 ) = F_149 ( F_150 ( V_288 , V_230 ) ) ;
V_244 -> V_278 = V_273 ;
V_244 -> V_279 = F_116 ( 0 ) ;
V_244 -> V_289 = * ( T_4 * ) ( V_272 -> V_290 ) ;
V_244 -> V_291 = * ( T_4 * ) ( V_272 -> V_290 + 8 ) ;
V_244 -> V_292 = F_168 ( 0 ) ;
V_244 -> V_293 = F_168 ( 0 ) ;
V_241 = F_85 ( & V_13 -> V_16 , V_275 ) ;
V_244 -> V_282 = F_168 ( F_169 ( V_241 ) ) ;
V_244 -> V_283 = F_168 ( F_170 ( V_284 ) |
V_285 | F_171 ( V_275 ) ) ;
V_54 = F_172 ( V_13 , V_195 ) ;
return F_173 ( V_54 ) ;
}
int F_175 ( const struct V_1 * V_2 , unsigned int V_230 ,
unsigned int V_275 , bool V_294 )
{
struct V_194 * V_195 ;
struct V_12 * V_13 ;
struct V_295 * V_244 ;
int V_54 ;
V_13 = F_167 ( V_2 ) ;
V_195 = F_154 ( sizeof( * V_244 ) , V_156 ) ;
if ( ! V_195 )
return - V_61 ;
V_244 = (struct V_295 * ) F_146 ( V_195 , sizeof( * V_244 ) ) ;
F_147 ( V_244 , 0 ) ;
F_148 ( V_244 ) = F_149 ( F_150 ( V_296 , V_230 ) ) ;
V_244 -> V_297 = F_116 ( F_176 ( 0 ) | ( V_294 ? F_177 ( 1 ) :
F_177 ( 0 ) ) | F_178 ( V_275 ) ) ;
V_54 = F_172 ( V_13 , V_195 ) ;
return F_173 ( V_54 ) ;
}
unsigned int F_179 ( const unsigned short * V_298 , unsigned short V_66 ,
unsigned int * V_184 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_299 - 1 && V_298 [ V_19 + 1 ] <= V_66 )
++ V_19 ;
if ( V_184 )
* V_184 = V_19 ;
return V_298 [ V_19 ] ;
}
unsigned int F_180 ( const unsigned short * V_298 ,
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
unsigned int F_181 ( enum V_309 V_189 , unsigned int V_51 )
{
if ( F_165 ( V_189 ) <= V_271 )
return ( ( V_51 & 0x7f ) << 1 ) ;
else
return ( V_51 & 0x7f ) ;
}
unsigned int F_182 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_76 ;
}
unsigned int F_183 ( const struct V_1 * V_2 , int V_310 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
T_1 V_311 , V_312 , V_313 , V_314 ;
V_311 = F_68 ( V_13 , V_315 ) ;
V_312 = F_68 ( V_13 , V_316 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
V_313 = F_184 ( V_311 ) ;
V_314 = F_185 ( V_311 ) ;
} else {
V_313 = F_186 ( V_311 ) ;
V_314 = F_187 ( V_312 ) ;
}
return V_310 ? V_313 : V_314 ;
}
unsigned int F_188 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_51 ;
}
unsigned int F_189 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_31 ;
}
void F_190 ( struct V_317 * V_128 , struct V_318 * V_319 ,
struct V_318 * V_320 )
{
struct V_12 * V_13 = F_191 ( V_128 ) ;
F_192 ( & V_13 -> V_321 ) ;
F_193 ( V_13 , V_319 , V_320 ) ;
F_194 ( & V_13 -> V_321 ) ;
}
void F_195 ( struct V_1 * V_2 , unsigned int V_322 ,
const unsigned int * V_323 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
F_70 ( V_13 , V_324 , V_322 ) ;
F_70 ( V_13 , V_325 , F_196 ( V_323 [ 0 ] ) |
F_197 ( V_323 [ 1 ] ) | F_198 ( V_323 [ 2 ] ) |
F_199 ( V_323 [ 3 ] ) ) ;
}
int F_200 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
return F_201 ( V_13 , V_13 -> V_27 ) ;
}
static int F_202 ( struct V_12 * V_13 , T_6 V_95 , T_6 * V_326 , T_6 * V_327 )
{
T_1 V_50 = F_68 ( V_13 , V_328 ) + 24 * V_95 + 8 ;
T_4 V_329 ;
int V_54 ;
F_192 ( & V_13 -> V_330 ) ;
V_54 = F_203 ( V_13 , 0 , V_331 , V_50 ,
sizeof( V_329 ) , ( T_10 * ) & V_329 ,
V_332 ) ;
F_194 ( & V_13 -> V_330 ) ;
if ( ! V_54 ) {
* V_327 = ( F_204 ( V_329 ) >> 25 ) & 0xffff ;
* V_326 = ( F_204 ( V_329 ) >> 9 ) & 0xffff ;
}
return V_54 ;
}
int F_205 ( struct V_1 * V_2 , T_6 V_95 , T_6 V_326 ,
T_6 V_192 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
T_6 V_333 , V_334 ;
int V_54 ;
V_54 = F_202 ( V_13 , V_95 , & V_333 , & V_334 ) ;
if ( V_54 )
goto V_59;
if ( V_326 != V_333 ) {
T_6 V_206 ;
T_1 V_335 ;
if ( V_326 >= V_333 )
V_206 = V_326 - V_333 ;
else
V_206 = V_192 - V_333 + V_326 ;
if ( F_104 ( V_13 -> V_188 . V_189 ) )
V_335 = F_206 ( V_206 ) ;
else
V_335 = F_207 ( V_206 ) ;
F_208 () ;
F_70 ( V_13 , F_69 ( V_336 ) ,
F_209 ( V_95 ) | V_335 ) ;
}
V_59:
return V_54 ;
}
int F_210 ( struct V_1 * V_2 , T_1 V_337 , T_10 * V_338 )
{
struct V_12 * V_13 ;
T_1 V_339 , V_340 , V_341 ;
T_1 V_342 , V_343 , V_344 , V_345 , V_192 ;
T_1 V_346 , V_347 , V_348 , V_349 ;
int V_54 ;
V_13 = F_167 ( V_2 ) ;
V_339 = ( ( V_337 >> 8 ) * 32 ) + V_13 -> V_350 . V_337 . V_351 ;
V_192 = F_68 ( V_13 , V_352 ) ;
V_342 = F_211 ( V_192 ) << 20 ;
V_192 = F_68 ( V_13 , V_353 ) ;
V_343 = F_212 ( V_192 ) << 20 ;
V_192 = F_68 ( V_13 , V_354 ) ;
V_344 = F_213 ( V_192 ) << 20 ;
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
} else if ( F_214 ( V_13 -> V_188 . V_189 ) ) {
V_192 = F_68 ( V_13 , V_357 ) ;
V_345 = F_215 ( V_192 ) << 20 ;
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
F_192 ( & V_13 -> V_330 ) ;
V_54 = F_203 ( V_13 , 0 , V_340 , V_341 , 32 , V_338 , V_332 ) ;
F_194 ( & V_13 -> V_330 ) ;
return V_54 ;
V_22:
F_11 ( V_13 -> V_30 , L_35 ,
V_337 , V_339 ) ;
return - V_65 ;
}
T_2 F_216 ( struct V_1 * V_2 )
{
T_1 V_359 , V_360 ;
struct V_12 * V_13 ;
V_13 = F_167 ( V_2 ) ;
V_360 = F_68 ( V_13 , V_361 ) ;
V_359 = F_217 ( F_68 ( V_13 , V_362 ) ) ;
return ( ( T_2 ) V_359 << 32 ) | ( T_2 ) V_360 ;
}
int F_218 ( struct V_1 * V_2 ,
unsigned int V_95 ,
enum V_363 V_364 ,
int V_365 ,
T_2 * V_366 ,
unsigned int * V_367 )
{
return F_219 ( F_167 ( V_2 ) ,
V_95 ,
( V_364 == V_368
? V_369
: V_370 ) ,
V_365 ,
V_366 ,
V_367 ) ;
}
static void F_220 ( struct V_371 * V_372 )
{
const struct V_373 * V_374 ;
const struct V_1 * V_52 = V_372 -> V_2 ;
if ( F_221 ( V_52 ) )
V_52 = F_222 ( V_52 ) ;
V_374 = V_52 -> V_2 . V_374 ;
if ( V_374 && V_374 -> V_375 == & V_376 . V_375 )
F_223 ( F_224 ( V_374 ) , V_372 ) ;
}
static int F_225 ( struct V_377 * V_378 , unsigned long V_379 ,
void * V_109 )
{
switch ( V_379 ) {
case V_380 :
F_220 ( V_109 ) ;
break;
case V_381 :
default:
break;
}
return 0 ;
}
static void F_226 ( struct V_12 * V_13 , int V_382 )
{
T_1 V_311 , V_312 , V_313 , V_314 ;
do {
V_311 = F_68 ( V_13 , V_315 ) ;
V_312 = F_68 ( V_13 , V_316 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
V_313 = F_184 ( V_311 ) ;
V_314 = F_185 ( V_311 ) ;
} else {
V_313 = F_186 ( V_311 ) ;
V_314 = F_187 ( V_312 ) ;
}
if ( V_313 == 0 && V_314 == 0 )
break;
F_227 ( V_383 ) ;
F_228 ( F_229 ( V_382 ) ) ;
} while ( 1 );
}
static void F_230 ( struct V_97 * V_25 )
{
unsigned long V_68 ;
F_231 ( & V_25 -> V_384 , V_68 ) ;
V_25 -> V_385 = 1 ;
F_232 ( & V_25 -> V_384 , V_68 ) ;
}
static void F_233 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
F_234 ( & V_25 -> V_384 ) ;
if ( V_25 -> V_386 ) {
F_208 () ;
F_70 ( V_13 , F_69 ( V_336 ) ,
F_209 ( V_25 -> V_26 ) | F_206 ( V_25 -> V_386 ) ) ;
V_25 -> V_386 = 0 ;
}
V_25 -> V_385 = 0 ;
F_235 ( & V_25 -> V_384 ) ;
}
static void F_236 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_230 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_387 * V_388 =
V_13 -> V_16 . V_389 [ V_390 ] ;
if ( V_388 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_388 -> V_391 [ V_19 ] ;
F_230 ( & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_230 ( & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_238 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_233 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_387 * V_388 =
V_13 -> V_16 . V_389 [ V_390 ] ;
if ( V_388 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_388 -> V_391 [ V_19 ] ;
F_233 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_233 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_239 ( struct V_12 * V_13 , enum V_392 V_110 )
{
enum V_393 type = V_178 ;
if ( V_13 -> V_394 && V_13 -> V_394 [ type ] . V_395 )
V_13 -> V_394 [ type ] . F_240 ( V_13 -> V_394 [ type ] . V_395 , V_110 ) ;
}
static void F_241 ( struct V_255 * V_256 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_256 , struct V_12 , V_396 ) ;
F_226 ( V_13 , V_397 ) ;
F_238 ( V_13 ) ;
F_239 ( V_13 , V_398 ) ;
if ( F_165 ( V_13 -> V_188 . V_189 ) <= V_271 )
F_242 ( V_13 , V_399 ,
V_400 | V_401 ,
V_400 | V_401 ) ;
else
F_242 ( V_13 , V_399 ,
V_401 , V_401 ) ;
}
static void F_243 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
T_6 V_333 , V_334 ;
int V_54 ;
F_234 ( & V_25 -> V_384 ) ;
V_54 = F_202 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_333 , & V_334 ) ;
if ( V_54 )
goto V_59;
if ( V_25 -> V_402 != V_333 ) {
T_6 V_206 ;
T_1 V_335 ;
if ( V_25 -> V_402 >= V_333 )
V_206 = V_25 -> V_402 - V_333 ;
else
V_206 = V_25 -> V_192 - V_333 + V_25 -> V_402 ;
if ( F_104 ( V_13 -> V_188 . V_189 ) )
V_335 = F_206 ( V_206 ) ;
else
V_335 = F_207 ( V_206 ) ;
F_208 () ;
F_70 ( V_13 , F_69 ( V_336 ) ,
F_209 ( V_25 -> V_26 ) | V_335 ) ;
}
V_59:
V_25 -> V_385 = 0 ;
V_25 -> V_386 = 0 ;
F_235 ( & V_25 -> V_384 ) ;
if ( V_54 )
F_244 ( V_13 , L_36 ) ;
}
static void F_245 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_243 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_387 * V_388 =
V_13 -> V_16 . V_389 [ V_390 ] ;
if ( V_388 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_388 -> V_391 [ V_19 ] ;
F_243 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_243 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_246 ( struct V_255 * V_256 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_256 , struct V_12 , V_403 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
F_226 ( V_13 , V_397 ) ;
F_239 ( V_13 , V_404 ) ;
F_226 ( V_13 , V_397 ) ;
F_245 ( V_13 ) ;
F_226 ( V_13 , V_397 ) ;
F_238 ( V_13 ) ;
F_239 ( V_13 , V_398 ) ;
} else if ( F_214 ( V_13 -> V_188 . V_189 ) ) {
T_1 V_405 = F_68 ( V_13 , 0x010ac ) ;
T_6 V_95 = ( V_405 >> 15 ) & 0x1ffff ;
T_6 V_406 = V_405 & 0x1fff ;
T_2 V_407 ;
unsigned int V_408 ;
int V_54 ;
V_54 = F_219 ( V_13 , V_95 , V_369 ,
0 , & V_407 , & V_408 ) ;
if ( V_54 )
F_11 ( V_13 -> V_30 , L_37
L_38 , V_95 , V_406 ) ;
else
F_247 ( F_207 ( V_406 ) | F_209 ( V_408 ) ,
V_13 -> V_409 + V_407 + V_410 ) ;
F_242 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_165 ( V_13 -> V_188 . V_189 ) <= V_271 )
F_242 ( V_13 , V_411 , V_412 , 0 ) ;
}
void F_248 ( struct V_12 * V_13 )
{
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
F_236 ( V_13 ) ;
F_239 ( V_13 , V_413 ) ;
F_242 ( V_13 , V_399 ,
V_400 | V_401 , 0 ) ;
F_152 ( V_13 -> V_253 , & V_13 -> V_396 ) ;
}
}
void F_249 ( struct V_12 * V_13 )
{
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
F_236 ( V_13 ) ;
F_239 ( V_13 , V_413 ) ;
}
F_152 ( V_13 -> V_253 , & V_13 -> V_403 ) ;
}
void F_250 ( void )
{
if ( ! V_414 ) {
F_251 ( & V_415 ) ;
V_414 = true ;
}
}
static void F_252 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_253 ( & V_416 ) ;
F_33 ( & V_13 -> V_417 ) ;
for ( V_19 = 0 ; V_19 < V_418 ; V_19 ++ )
if ( V_13 -> V_394 && V_13 -> V_394 [ V_19 ] . V_395 ) {
V_13 -> V_394 [ V_19 ] . F_254 ( V_13 -> V_394 [ V_19 ] . V_395 ,
V_419 ) ;
V_13 -> V_394 [ V_19 ] . V_395 = NULL ;
}
if ( V_414 && F_255 ( & V_420 ) ) {
F_256 ( & V_415 ) ;
V_414 = false ;
}
F_257 ( & V_416 ) ;
}
static void F_258 ( struct V_12 * V_13 , enum V_421 V_422 )
{
unsigned int V_19 ;
F_253 ( & V_416 ) ;
for ( V_19 = 0 ; V_19 < V_418 ; V_19 ++ )
if ( V_13 -> V_394 && V_13 -> V_394 [ V_19 ] . V_395 )
V_13 -> V_394 [ V_19 ] . F_254 ( V_13 -> V_394 [ V_19 ] . V_395 ,
V_422 ) ;
F_257 ( & V_416 ) ;
}
static int F_259 ( struct V_377 * V_423 ,
unsigned long V_379 , void * V_109 )
{
struct V_424 * V_425 = V_109 ;
struct V_1 * V_426 = V_425 -> V_427 -> V_2 ;
const struct V_373 * V_374 = NULL ;
#if F_260 ( V_428 )
struct V_12 * V_13 ;
#endif
if ( F_221 ( V_426 ) )
V_426 = F_222 ( V_426 ) ;
#if F_260 ( V_428 )
if ( V_426 -> V_68 & V_429 ) {
F_22 (adap, &adapter_list, list_node) {
switch ( V_379 ) {
case V_430 :
F_261 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_425 , 1 ) ;
break;
case V_431 :
F_262 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_425 , 1 ) ;
break;
default:
break;
}
}
return V_432 ;
}
#endif
if ( V_426 )
V_374 = V_426 -> V_2 . V_374 ;
if ( V_374 && V_374 -> V_375 == & V_376 . V_375 ) {
switch ( V_379 ) {
case V_430 :
F_261 ( V_426 , ( const T_1 * ) V_425 , 1 ) ;
break;
case V_431 :
F_262 ( V_426 , ( const T_1 * ) V_425 , 1 ) ;
break;
default:
break;
}
}
return V_432 ;
}
static void F_263 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_54 ;
F_264 () ;
for ( V_19 = 0 ; V_19 < V_433 ; V_19 ++ ) {
V_2 = V_13 -> V_39 [ V_19 ] ;
V_54 = 0 ;
if ( V_2 )
V_54 = F_265 ( V_2 ) ;
if ( V_54 < 0 )
break;
}
F_266 () ;
}
static int F_267 ( struct V_12 * V_13 )
{
int V_22 ;
V_22 = F_99 ( V_13 ) ;
if ( V_22 )
goto V_59;
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
V_22 = F_75 ( V_13 -> V_128 -> V_130 , F_268 ( V_13 ) ,
( V_13 -> V_68 & V_129 ) ? 0 : V_436 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_435;
}
F_91 ( V_13 ) ;
F_269 ( V_13 ) ;
F_270 ( V_13 ) ;
V_13 -> V_68 |= V_168 ;
F_258 ( V_13 , V_437 ) ;
#if F_260 ( V_438 )
F_263 ( V_13 ) ;
#endif
F_271 ( & V_13 -> V_63 ) ;
V_59:
return V_22 ;
V_435:
F_11 ( V_13 -> V_30 , L_39 , V_22 ) ;
V_434:
F_98 ( V_13 ) ;
goto V_59;
}
static void F_272 ( struct V_12 * V_12 )
{
F_273 ( & V_12 -> V_254 ) ;
F_273 ( & V_12 -> V_396 ) ;
F_273 ( & V_12 -> V_403 ) ;
V_12 -> V_252 = false ;
V_12 -> V_250 = NULL ;
F_274 ( V_12 ) ;
F_98 ( V_12 ) ;
V_12 -> V_68 &= ~ V_168 ;
}
static int F_275 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_18 ( V_2 ) ;
if ( ! ( V_12 -> V_68 & V_168 ) ) {
V_22 = F_267 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
F_276 ( V_2 ) ;
return V_22 ;
}
static int F_277 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_278 ( V_2 ) ;
F_18 ( V_2 ) ;
return F_279 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , false , false ) ;
}
int F_280 ( const struct V_1 * V_2 , unsigned int V_230 ,
T_10 V_272 , T_11 V_273 , T_11 V_274 ,
unsigned int V_275 , unsigned char V_39 , unsigned char V_439 )
{
int V_54 ;
struct V_268 * V_440 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_335 ;
V_13 = F_167 ( V_2 ) ;
V_230 -= V_13 -> V_248 . V_239 ;
V_230 += V_13 -> V_248 . V_262 ;
V_440 = & V_13 -> V_248 . V_266 [ V_230 ] ;
V_54 = F_281 ( V_440 ) ;
if ( V_54 )
return V_54 ;
if ( V_440 -> V_441 )
F_282 ( V_13 , V_440 ) ;
memset ( & V_440 -> V_442 , 0 , sizeof( struct V_443 ) ) ;
V_440 -> V_442 . V_335 . V_444 = F_283 ( V_273 ) ;
V_440 -> V_442 . V_439 . V_444 = ~ 0 ;
V_335 = ( T_3 * ) & V_272 ;
if ( ( V_335 [ 0 ] | V_335 [ 1 ] | V_335 [ 2 ] | V_335 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_440 -> V_442 . V_335 . V_445 [ V_19 ] = V_335 [ V_19 ] ;
V_440 -> V_442 . V_439 . V_445 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_188 . V_446 . V_447 & V_448 ) {
V_440 -> V_442 . V_335 . V_449 = V_39 ;
V_440 -> V_442 . V_439 . V_449 = V_439 ;
}
}
if ( V_13 -> V_188 . V_446 . V_447 & V_450 ) {
V_440 -> V_442 . V_335 . V_451 = V_452 ;
V_440 -> V_442 . V_439 . V_451 = ~ 0 ;
}
V_440 -> V_442 . V_453 = 1 ;
V_440 -> V_442 . V_454 = V_275 ;
V_440 -> V_455 = 1 ;
V_440 -> V_442 . V_456 = 1 ;
V_54 = F_284 ( V_13 , V_230 ) ;
if ( V_54 ) {
F_282 ( V_13 , V_440 ) ;
return V_54 ;
}
return 0 ;
}
int F_285 ( const struct V_1 * V_2 , unsigned int V_230 ,
unsigned int V_275 , bool V_294 )
{
struct V_268 * V_440 ;
struct V_12 * V_13 ;
V_13 = F_167 ( V_2 ) ;
V_230 -= V_13 -> V_248 . V_239 ;
V_230 += V_13 -> V_248 . V_262 ;
V_440 = & V_13 -> V_248 . V_266 [ V_230 ] ;
V_440 -> V_455 = 0 ;
return F_286 ( V_13 , V_230 ) ;
}
static void F_287 ( struct V_1 * V_2 ,
struct V_457 * V_458 )
{
struct V_459 V_185 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_192 ( & V_12 -> V_321 ) ;
if ( ! F_288 ( V_2 ) ) {
F_194 ( & V_12 -> V_321 ) ;
return;
}
F_289 ( V_12 , V_6 -> V_76 , & V_185 ,
& V_6 -> V_460 ) ;
F_194 ( & V_12 -> V_321 ) ;
V_458 -> V_461 = V_185 . V_462 ;
V_458 -> V_463 = V_185 . V_464 ;
V_458 -> V_465 = V_185 . V_466 ;
V_458 -> V_467 = V_185 . V_468 ;
V_458 -> V_469 = V_185 . V_470 ;
V_458 -> V_471 = V_185 . V_472 + V_185 . V_473 +
V_185 . V_474 ;
V_458 -> V_475 = 0 ;
V_458 -> V_476 = V_185 . V_477 ;
V_458 -> V_478 = V_185 . V_479 ;
V_458 -> V_480 = V_185 . V_481 + V_185 . V_482 +
V_185 . V_483 + V_185 . V_484 +
V_185 . V_485 + V_185 . V_486 +
V_185 . V_487 + V_185 . V_488 ;
V_458 -> V_489 = 0 ;
V_458 -> V_490 = 0 ;
V_458 -> V_491 = 0 ;
V_458 -> V_492 = 0 ;
V_458 -> V_493 = 0 ;
V_458 -> V_494 = 0 ;
V_458 -> V_495 = V_185 . V_496 ;
V_458 -> V_497 = V_185 . V_479 + V_185 . V_477 +
V_458 -> V_471 + V_185 . V_498 + V_458 -> V_499 ;
}
static int F_290 ( struct V_1 * V_2 , struct V_500 * V_244 , int V_110 )
{
unsigned int V_27 ;
int V_54 = 0 , V_501 , V_502 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_503 * V_109 = (struct V_503 * ) & V_244 -> V_504 ;
switch ( V_110 ) {
case V_505 :
if ( V_11 -> V_506 < 0 )
return - V_507 ;
V_109 -> V_508 = V_11 -> V_506 ;
break;
case V_509 :
case V_510 :
if ( F_291 ( V_109 -> V_508 ) ) {
V_501 = F_292 ( V_109 -> V_508 ) ;
V_502 = F_293 ( V_109 -> V_508 ) ;
} else if ( V_109 -> V_508 < 32 ) {
V_501 = V_109 -> V_508 ;
V_502 = 0 ;
V_109 -> V_511 &= 0x1f ;
} else
return - V_65 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_110 == V_509 )
V_54 = F_294 ( V_11 -> V_12 , V_27 , V_501 , V_502 ,
V_109 -> V_511 , & V_109 -> V_512 ) ;
else
V_54 = F_295 ( V_11 -> V_12 , V_27 , V_501 , V_502 ,
V_109 -> V_511 , V_109 -> V_513 ) ;
break;
case V_514 :
return F_296 ( V_244 -> V_504 , & V_11 -> V_515 ,
sizeof( V_11 -> V_515 ) ) ?
- V_516 : 0 ;
case V_517 :
if ( F_297 ( & V_11 -> V_515 , V_244 -> V_504 ,
sizeof( V_11 -> V_515 ) ) )
return - V_516 ;
switch ( V_11 -> V_515 . V_518 ) {
case V_519 :
V_11 -> V_520 = false ;
break;
case V_521 :
V_11 -> V_520 = true ;
break;
default:
V_11 -> V_515 . V_518 = V_519 ;
return - V_522 ;
}
return F_296 ( V_244 -> V_504 , & V_11 -> V_515 ,
sizeof( V_11 -> V_515 ) ) ?
- V_516 : 0 ;
default:
return - V_507 ;
}
return V_54 ;
}
static void F_298 ( struct V_1 * V_2 )
{
F_36 ( V_2 , - 1 , false ) ;
}
static int F_299 ( struct V_1 * V_2 , int V_523 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
V_54 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , V_523 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_54 )
V_2 -> V_66 = V_523 ;
return V_54 ;
}
static int F_300 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
return 0 ;
}
static void F_301 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
T_3 V_524 [ V_525 ] , V_526 [ V_525 ] ;
int V_22 ;
T_3 * V_527 ;
T_6 V_528 , V_529 ;
V_22 = F_302 ( V_13 , & V_13 -> V_188 . V_530 ) ;
if ( ! V_22 ) {
V_527 = V_13 -> V_188 . V_530 . V_527 ;
for ( V_19 = 0 ; V_19 < V_525 ; V_19 ++ )
V_524 [ V_19 ] = ( F_303 ( V_527 [ 2 * V_19 + 0 ] ) * 16 +
F_303 ( V_527 [ 2 * V_19 + 1 ] ) ) ;
V_528 = ( V_524 [ 0 ] << 8 ) | V_524 [ 1 ] ;
V_529 = ( V_524 [ 1 ] << 8 ) | V_524 [ 2 ] ;
V_528 ^= V_529 ;
V_528 |= 0x0200 ;
V_528 &= ~ 0x0100 ;
V_526 [ 0 ] = V_528 >> 8 ;
V_526 [ 1 ] = V_528 & 0xff ;
for ( V_19 = 2 ; V_19 < 5 ; V_19 ++ )
V_526 [ V_19 ] = V_524 [ V_19 + 1 ] ;
for ( V_19 = 0 ; V_19 < V_13 -> V_531 ; V_19 ++ ) {
V_526 [ 5 ] = V_13 -> V_28 * 16 + V_19 ;
F_28 ( V_13 -> V_532 [ V_19 ] . V_533 , V_526 ) ;
}
}
}
static int F_304 ( struct V_1 * V_2 , int V_534 , T_3 * V_535 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
if ( ! F_305 ( V_535 ) ) {
F_11 ( V_11 -> V_12 -> V_30 ,
L_40 ,
V_535 , V_534 ) ;
return - V_65 ;
}
F_306 ( V_11 -> V_12 -> V_30 ,
L_41 , V_535 , V_534 ) ;
V_54 = F_307 ( V_13 , V_534 + 1 , 1 , V_535 ) ;
if ( ! V_54 )
F_28 ( V_13 -> V_532 [ V_534 ] . V_533 , V_535 ) ;
return V_54 ;
}
static int F_308 ( struct V_1 * V_2 ,
int V_534 , struct V_536 * V_537 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_534 >= V_13 -> V_531 )
return - V_65 ;
V_537 -> V_534 = V_534 ;
F_28 ( V_537 -> V_535 , V_13 -> V_532 [ V_534 ] . V_533 ) ;
return 0 ;
}
static int F_309 ( struct V_1 * V_2 ,
struct V_538 * V_539 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_540 ;
V_540 = V_11 -> V_12 -> V_541 * 10 + V_11 -> V_31 ;
V_539 -> V_542 = sizeof( V_540 ) ;
memcpy ( V_539 -> V_543 , & V_540 , V_539 -> V_542 ) ;
return 0 ;
}
static int F_310 ( struct V_1 * V_2 , void * V_6 )
{
int V_54 ;
struct V_544 * V_50 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_305 ( V_50 -> V_545 ) )
return - V_546 ;
V_54 = F_41 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 ,
V_11 -> V_74 , V_50 -> V_545 , true , true ) ;
if ( V_54 < 0 )
return V_54 ;
memcpy ( V_2 -> V_75 , V_50 -> V_545 , V_2 -> V_547 ) ;
V_11 -> V_74 = V_54 ;
return 0 ;
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_68 & V_127 ) {
int V_19 ;
struct V_153 * V_548 = & V_13 -> V_16 . V_148 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_548 ++ )
V_146 ( 0 , & V_548 -> V_149 ) ;
} else
F_268 ( V_13 ) ( 0 , V_13 ) ;
}
static int F_312 ( struct V_1 * V_2 , int V_549 , T_1 V_550 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_551 * V_552 ;
struct V_553 V_6 ;
struct V_554 V_555 ;
T_1 V_556 ;
int V_22 = 0 ;
if ( ! F_313 ( V_2 ) )
return - V_557 ;
if ( V_549 < 0 || V_549 > V_11 -> V_20 - 1 )
return - V_65 ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_42 ,
V_549 ) ;
return - V_65 ;
}
V_556 = V_550 << 10 ;
if ( V_556 >= V_558 ) {
F_11 ( V_13 -> V_30 ,
L_43 ,
V_550 , V_558 ) ;
return - V_522 ;
}
memset ( & V_555 , 0 , sizeof( V_555 ) ) ;
V_555 . V_275 = V_549 ;
V_555 . V_559 = V_560 ;
V_22 = F_314 ( V_2 , ( void * ) ( & V_555 ) , V_561 ) ;
if ( V_22 ) {
F_11 ( V_13 -> V_30 ,
L_44 ,
V_549 , V_11 -> V_31 , V_22 ) ;
return V_22 ;
}
if ( ! V_556 )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_562 ;
V_6 . V_116 . V_188 . V_563 = V_564 ;
V_6 . V_116 . V_188 . V_565 = V_566 ;
V_6 . V_116 . V_188 . V_567 = V_568 ;
V_6 . V_116 . V_188 . V_569 = V_570 ;
V_6 . V_116 . V_188 . V_571 = V_11 -> V_76 ;
V_6 . V_116 . V_188 . V_559 = V_560 ;
V_6 . V_116 . V_188 . V_572 = 0 ;
V_6 . V_116 . V_188 . V_573 = V_556 ;
V_6 . V_116 . V_188 . V_574 = 0 ;
V_6 . V_116 . V_188 . V_575 = V_2 -> V_66 ;
V_552 = F_315 ( V_2 , & V_6 ) ;
if ( ! V_552 )
return - V_61 ;
memset ( & V_555 , 0 , sizeof( V_555 ) ) ;
V_555 . V_275 = V_549 ;
V_555 . V_559 = V_552 -> V_184 ;
V_22 = F_316 ( V_2 , ( void * ) ( & V_555 ) , V_561 ) ;
if ( V_22 )
F_11 ( V_13 -> V_30 ,
L_45 , V_22 ) ;
return V_22 ;
}
static int F_317 ( struct V_1 * V_2 , T_1 V_395 , T_11 V_451 ,
struct V_576 * V_577 )
{
struct V_5 * V_11 = F_86 ( V_2 ) ;
struct V_12 * V_13 = F_167 ( V_2 ) ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_46 ,
V_11 -> V_31 ) ;
return - V_65 ;
}
if ( F_318 ( V_395 ) == F_318 ( V_578 ) &&
V_577 -> type == V_579 ) {
switch ( V_577 -> V_580 -> V_581 ) {
case V_582 :
case V_583 :
return F_319 ( V_2 , V_451 , V_577 -> V_580 ) ;
case V_584 :
return F_320 ( V_2 , V_451 , V_577 -> V_580 ) ;
default:
return - V_507 ;
}
}
return - V_507 ;
}
static void F_321 ( struct V_1 * V_2 , struct V_585 * V_117 )
{
struct V_12 * V_12 = F_167 ( V_2 ) ;
F_322 ( V_117 -> V_375 , V_586 , sizeof( V_117 -> V_375 ) ) ;
F_322 ( V_117 -> V_587 , V_588 ,
sizeof( V_117 -> V_587 ) ) ;
F_322 ( V_117 -> V_589 , F_323 ( V_12 -> V_128 ) ,
sizeof( V_117 -> V_589 ) ) ;
}
void F_324 ( struct V_12 * V_13 )
{
int V_39 ;
F_325 ( V_13 ) ;
F_73 (adap, port) {
struct V_1 * V_2 = V_13 -> V_39 [ V_39 ] ;
if ( ! V_2 )
continue;
F_278 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_326 ( V_13 -> V_30 , L_47 ) ;
}
static void F_327 ( struct V_12 * V_13 )
{
T_1 V_590 = F_328 ( V_13 ) ;
F_329 ( V_13 , V_590 , V_591 ) ;
}
static void F_330 ( struct V_12 * V_13 )
{
if ( V_13 -> V_350 . V_592 . V_192 ) {
T_1 V_351 ;
unsigned int V_593 ;
V_351 = F_331 ( V_13 , V_594 ) ;
V_351 &= V_595 ;
V_351 += F_332 ( V_13 -> V_128 , & V_13 -> V_350 ) ;
V_593 = F_333 ( V_13 -> V_350 . V_592 . V_192 ) >> 10 ;
F_70 ( V_13 ,
F_334 ( V_596 , 3 ) ,
V_351 | F_335 ( 1 ) | F_336 ( F_337 ( V_593 ) ) ) ;
F_70 ( V_13 ,
F_334 ( V_597 , 3 ) ,
V_13 -> V_350 . V_592 . V_351 ) ;
F_68 ( V_13 ,
F_334 ( V_597 , 3 ) ) ;
}
}
static int F_338 ( struct V_12 * V_13 , struct V_598 * V_599 )
{
T_1 V_132 ;
int V_54 ;
memset ( V_599 , 0 , sizeof( * V_599 ) ) ;
V_599 -> V_600 = F_149 ( F_339 ( V_601 ) |
V_602 | V_603 ) ;
V_599 -> V_604 = F_149 ( F_340 ( * V_599 ) ) ;
V_54 = F_341 ( V_13 , V_13 -> V_27 , V_599 , sizeof( * V_599 ) , V_599 ) ;
if ( V_54 < 0 )
return V_54 ;
V_599 -> V_600 = F_149 ( F_339 ( V_601 ) |
V_602 | V_605 ) ;
V_54 = F_341 ( V_13 , V_13 -> V_27 , V_599 , sizeof( * V_599 ) , NULL ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_342 ( V_13 , V_13 -> V_28 ,
V_606 ,
V_607 |
V_608 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_343 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_172 , 64 ,
V_609 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_610 ,
V_610 ) ;
if ( V_54 < 0 )
return V_54 ;
F_344 ( V_13 ) ;
F_70 ( V_13 , V_611 , 0x64f8849 ) ;
F_70 ( V_13 , V_612 , F_196 ( V_613 - 12 ) ) ;
F_70 ( V_13 , V_614 , V_615 ) ;
V_132 = F_68 ( V_13 , V_616 ) ;
F_70 ( V_13 , V_616 , V_132 & ~ V_617 ) ;
V_13 -> V_188 . V_446 . V_618 = 0xE4 ;
F_70 ( V_13 , V_619 ,
F_345 ( V_13 -> V_188 . V_446 . V_618 ) ) ;
V_132 = 0x84218421 ;
F_346 ( V_13 , V_614 , V_616 ,
& V_132 , 1 , V_620 ) ;
F_346 ( V_13 , V_614 , V_616 ,
& V_132 , 1 , V_621 ) ;
F_346 ( V_13 , V_614 , V_616 ,
& V_132 , 1 , V_622 ) ;
#define F_347 16
if ( F_164 ( V_13 ) ) {
F_70 ( V_13 , V_623 ,
F_348 ( F_347 ) |
F_349 ( F_347 ) |
F_350 ( F_347 ) |
F_351 ( F_347 ) ) ;
F_70 ( V_13 , V_624 ,
F_348 ( F_347 ) |
F_349 ( F_347 ) |
F_350 ( F_347 ) |
F_351 ( F_347 ) ) ;
}
return F_352 ( V_13 , V_13 -> V_28 ) ;
}
static int F_353 ( struct V_12 * V_12 )
{
F_354 ( V_12 , V_625 , V_626 ) ;
if ( V_627 != 2 && V_627 != 0 ) {
F_11 ( & V_12 -> V_128 -> V_2 ,
L_48 ,
V_627 ) ;
V_627 = 2 ;
}
F_242 ( V_12 , V_628 ,
F_355 ( V_629 ) ,
F_355 ( V_627 ) ) ;
F_356 ( V_12 , V_615 ,
V_617 , 0 ) ;
return 0 ;
}
static int F_357 ( const T_3 * V_630 ,
T_7 V_631 )
{
int V_339 ;
#define F_358 ( T_12 ) (((__p)[0] << 8) | (__p)[1])
#define F_359 ( T_12 ) ((__p)[0] | ((__p)[1] << 8))
#define F_360 ( T_12 ) (le16(__p) | ((__p)[2] << 16))
V_339 = F_360 ( V_630 + 0x8 ) << 12 ;
V_339 = F_360 ( V_630 + V_339 + 0xa ) ;
return F_358 ( V_630 + V_339 + 0x27e ) ;
#undef F_358
#undef F_359
#undef F_360
}
static struct V_632 * F_361 ( int V_633 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_634 ) ; V_19 ++ ) {
if ( V_634 [ V_19 ] . V_635 == V_633 )
return & V_634 [ V_19 ] ;
}
return NULL ;
}
static int F_362 ( struct V_12 * V_13 )
{
const struct V_636 * V_637 ;
int V_54 ;
struct V_632 * V_638 ;
V_638 = F_361 ( V_13 -> V_128 -> V_373 ) ;
if ( ! V_638 ) {
F_363 ( V_13 -> V_30 ,
L_49 ) ;
return - V_507 ;
}
V_54 = F_364 ( & V_637 , V_638 -> V_639 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_50
L_51 ,
V_638 -> V_639 , - V_54 ) ;
if ( V_638 -> V_640 ) {
int V_641 = 0 ;
F_365 ( V_13 , & V_641 ) ;
F_363 ( V_13 -> V_30 , L_52
L_53 , V_641 ) ;
V_54 = 0 ;
}
return V_54 ;
}
V_54 = F_366 ( V_13 , V_591 , & V_13 -> V_330 ,
V_638 -> V_642 ,
( T_3 * ) V_637 -> V_109 , V_637 -> V_192 ) ;
if ( V_54 < 0 )
F_11 ( V_13 -> V_30 , L_54 ,
- V_54 ) ;
else if ( V_54 > 0 ) {
int V_643 = 0 ;
if ( V_638 -> V_642 )
V_643 = V_638 -> V_642 ( V_637 -> V_109 ,
V_637 -> V_192 ) ;
F_306 ( V_13 -> V_30 , L_55
L_56 ,
V_638 -> V_639 , V_643 ) ;
}
F_367 ( V_637 ) ;
return V_54 ;
}
static int F_368 ( struct V_12 * V_12 , int V_644 )
{
struct V_598 V_645 ;
const struct V_636 * V_646 ;
unsigned long V_647 = 0 , V_648 = 0 ;
T_1 V_649 , V_650 , V_651 ;
int V_54 ;
int V_652 = 0 ;
char * V_653 , V_654 [ 256 ] ;
char * V_655 = NULL ;
if ( V_644 ) {
V_54 = F_369 ( V_12 , V_12 -> V_27 ,
V_656 | V_657 ) ;
if ( V_54 < 0 )
goto V_658;
}
if ( F_370 ( V_12 -> V_128 -> V_373 ) ) {
V_54 = F_362 ( V_12 ) ;
if ( V_54 < 0 )
goto V_658;
}
switch ( F_165 ( V_12 -> V_188 . V_189 ) ) {
case V_659 :
V_653 = V_660 ;
break;
case V_271 :
V_653 = V_661 ;
break;
case V_662 :
V_653 = V_663 ;
break;
default:
F_11 ( V_12 -> V_30 , L_57 ,
V_12 -> V_128 -> V_373 ) ;
V_54 = - V_65 ;
goto V_658;
}
V_54 = F_371 ( & V_646 , V_653 , V_12 -> V_30 ) ;
if ( V_54 < 0 ) {
V_655 = L_58 ;
V_647 = V_664 ;
V_648 = F_372 ( V_12 ) ;
} else {
T_1 V_188 [ 7 ] , V_335 [ 7 ] ;
sprintf ( V_654 ,
L_59 , V_653 ) ;
V_655 = V_654 ;
if ( V_646 -> V_192 >= V_665 )
V_54 = - V_61 ;
else {
V_188 [ 0 ] = ( F_7 ( V_666 ) |
F_8 ( V_667 ) ) ;
V_54 = F_373 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_188 , V_335 ) ;
if ( V_54 == 0 ) {
T_7 V_668 = V_646 -> V_192 & 0x3 ;
T_7 V_192 = V_646 -> V_192 & ~ 0x3 ;
T_10 * V_109 = ( T_10 * ) V_646 -> V_109 ;
V_647 = F_374 ( V_335 [ 0 ] ) ;
V_648 = F_375 ( V_335 [ 0 ] ) << 16 ;
F_192 ( & V_12 -> V_330 ) ;
V_54 = F_203 ( V_12 , 0 , V_647 , V_648 ,
V_192 , V_109 , V_669 ) ;
if ( V_54 == 0 && V_668 != 0 ) {
union {
T_10 V_670 ;
char V_671 [ 4 ] ;
} V_672 ;
int V_19 ;
V_672 . V_670 = V_109 [ V_192 >> 2 ] ;
for ( V_19 = V_668 ; V_19 < 4 ; V_19 ++ )
V_672 . V_671 [ V_19 ] = 0 ;
V_54 = F_203 ( V_12 , 0 , V_647 ,
V_648 + V_192 ,
4 , & V_672 . V_670 ,
V_669 ) ;
}
F_194 ( & V_12 -> V_330 ) ;
}
}
F_367 ( V_646 ) ;
if ( V_54 )
goto V_658;
}
memset ( & V_645 , 0 , sizeof( V_645 ) ) ;
V_645 . V_600 =
F_149 ( F_339 ( V_601 ) |
V_602 |
V_603 ) ;
V_645 . V_604 =
F_149 ( V_673 |
F_376 ( V_647 ) |
F_377 ( V_648 >> 16 ) |
F_340 ( V_645 ) ) ;
V_54 = F_341 ( V_12 , V_12 -> V_27 , & V_645 , sizeof( V_645 ) ,
& V_645 ) ;
if ( V_54 == - V_674 ) {
memset ( & V_645 , 0 , sizeof( V_645 ) ) ;
V_645 . V_600 =
F_149 ( F_339 ( V_601 ) |
V_602 |
V_603 ) ;
V_645 . V_604 = F_149 ( F_340 ( V_645 ) ) ;
V_54 = F_341 ( V_12 , V_12 -> V_27 , & V_645 ,
sizeof( V_645 ) , & V_645 ) ;
V_655 = L_60 ;
}
V_652 = 1 ;
if ( V_54 < 0 )
goto V_658;
V_649 = F_48 ( V_645 . V_649 ) ;
V_650 = F_48 ( V_645 . V_650 ) ;
V_651 = F_48 ( V_645 . V_651 ) ;
if ( V_650 != V_651 )
F_363 ( V_12 -> V_30 , L_61\
L_62 ,
V_650 , V_651 ) ;
V_645 . V_600 =
F_149 ( F_339 ( V_601 ) |
V_602 |
V_605 ) ;
V_645 . V_604 = F_149 ( F_340 ( V_645 ) ) ;
V_54 = F_341 ( V_12 , V_12 -> V_27 , & V_645 , sizeof( V_645 ) ,
NULL ) ;
if ( V_54 < 0 )
goto V_658;
V_54 = F_353 ( V_12 ) ;
if ( V_54 < 0 )
goto V_658;
V_54 = F_378 ( V_12 , V_12 -> V_27 ) ;
if ( V_54 < 0 )
goto V_658;
F_306 ( V_12 -> V_30 , L_63\
L_64 ,
V_655 , V_649 , V_651 ) ;
return 0 ;
V_658:
if ( V_652 && V_54 != - V_674 )
F_363 ( V_12 -> V_30 , L_65 ,
V_655 , - V_54 ) ;
return V_54 ;
}
static struct V_675 * F_379 ( int V_189 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_676 ) ; V_19 ++ ) {
if ( V_676 [ V_19 ] . V_189 == V_189 )
return & V_676 [ V_19 ] ;
}
return NULL ;
}
static int F_380 ( struct V_12 * V_13 )
{
int V_54 ;
T_1 V_132 , V_677 ;
enum V_678 V_35 ;
T_1 V_188 [ 7 ] , V_335 [ 7 ] ;
struct V_598 V_645 ;
int V_644 = 1 ;
V_54 = F_381 ( V_13 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_382 ( V_13 , V_13 -> V_27 , V_13 -> V_27 ,
F_383 () ? V_679 : V_680 , & V_35 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_66 ,
V_54 ) ;
return V_54 ;
}
if ( V_54 == V_13 -> V_27 )
V_13 -> V_68 |= V_136 ;
F_384 ( V_13 , & V_13 -> V_188 . V_681 ) ;
F_385 ( V_13 , & V_13 -> V_188 . V_682 ) ;
F_386 ( V_13 , & V_13 -> V_188 . V_683 ) ;
F_387 ( V_13 , & V_13 -> V_188 . V_684 ) ;
V_54 = F_388 ( V_13 ) ;
if ( V_54 )
V_35 = V_685 ;
if ( ( V_13 -> V_68 & V_136 ) && V_35 != V_686 ) {
struct V_675 * V_675 ;
struct V_687 * V_688 ;
const struct V_636 * V_689 ;
const T_3 * V_690 = NULL ;
unsigned int V_691 = 0 ;
V_675 = F_379 ( F_165 ( V_13 -> V_188 . V_189 ) ) ;
if ( V_675 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_67 ,
F_165 ( V_13 -> V_188 . V_189 ) ) ;
return - V_65 ;
}
V_688 = F_107 ( sizeof( * V_688 ) ) ;
V_54 = F_371 ( & V_689 , V_675 -> V_692 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_68 ,
V_675 -> V_692 , V_54 ) ;
} else {
V_690 = V_689 -> V_109 ;
V_691 = V_689 -> V_192 ;
}
V_54 = F_389 ( V_13 , V_675 , V_690 , V_691 , V_688 ,
V_35 , & V_644 ) ;
F_367 ( V_689 ) ;
F_109 ( V_688 ) ;
if ( V_54 < 0 )
goto V_658;
}
V_54 = F_390 ( V_13 , & V_13 -> V_188 . V_530 ) ;
if ( V_54 < 0 )
goto V_658;
V_132 =
F_7 ( V_666 ) |
F_8 ( V_693 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_132 , & V_677 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_188 . V_694 = F_391 ( V_677 ) ;
V_13 -> V_188 . V_695 = V_677 ;
if ( V_35 == V_686 ) {
F_306 ( V_13 -> V_30 , L_69\
L_70 ,
V_13 -> V_68 & V_136 ? L_71 : L_72 ) ;
} else {
F_306 ( V_13 -> V_30 , L_73\
L_74 ) ;
V_188 [ 0 ] = ( F_7 ( V_666 ) |
F_8 ( V_667 ) ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_188 , V_335 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_75
L_76 ) ;
goto V_658;
}
V_54 = F_368 ( V_13 , V_644 ) ;
if ( V_54 == - V_674 ) {
F_11 ( V_13 -> V_30 , L_77
L_78 ) ;
goto V_658;
}
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_79
L_80 , - V_54 ) ;
goto V_658;
}
}
V_54 = F_344 ( V_13 ) ;
if ( V_54 < 0 )
goto V_658;
if ( F_392 ( V_13 -> V_128 -> V_373 ) )
V_13 -> V_188 . V_696 = 1 ;
#define F_393 ( T_13 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_394 ( T_13 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_188 [ 0 ] = F_394 ( V_697 ) ;
V_188 [ 1 ] = F_394 ( V_698 ) ;
V_188 [ 2 ] = F_394 ( V_699 ) ;
V_188 [ 3 ] = F_394 ( V_700 ) ;
V_188 [ 4 ] = F_394 ( V_701 ) ;
V_188 [ 5 ] = F_394 ( V_702 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_16 . V_99 = V_335 [ 0 ] ;
V_13 -> V_703 = V_335 [ 1 ] ;
V_13 -> V_704 = V_335 [ 2 ] ;
V_13 -> V_248 . V_705 = V_335 [ 3 ] ;
V_13 -> V_248 . V_262 = V_335 [ 4 ] - V_335 [ 3 ] + 1 ;
V_13 -> V_16 . V_163 = V_335 [ 5 ] ;
V_188 [ 0 ] = F_394 ( V_706 ) ;
V_188 [ 1 ] = F_394 ( V_707 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_16 . V_172 = V_335 [ 0 ] - V_13 -> V_16 . V_99 + 1 ;
V_13 -> V_16 . V_165 = V_335 [ 1 ] - V_13 -> V_16 . V_163 + 1 ;
V_13 -> V_16 . V_98 = F_395 ( V_13 -> V_16 . V_172 ,
sizeof( * V_13 -> V_16 . V_98 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_98 ) {
V_54 = - V_61 ;
goto V_658;
}
V_13 -> V_16 . V_164 = F_395 ( V_13 -> V_16 . V_165 ,
sizeof( * V_13 -> V_16 . V_164 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_164 ) {
V_54 = - V_61 ;
goto V_658;
}
V_13 -> V_16 . V_171 = F_395 ( F_161 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_171 ) {
V_54 = - V_61 ;
goto V_658;
}
V_13 -> V_16 . V_173 = F_395 ( F_161 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_173 ) {
V_54 = - V_61 ;
goto V_658;
}
#ifdef F_129
V_13 -> V_16 . V_708 = F_395 ( F_161 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_708 ) {
V_54 = - V_61 ;
goto V_658;
}
#endif
V_188 [ 0 ] = F_394 ( V_709 ) ;
V_188 [ 1 ] = F_394 ( V_710 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_711 = V_335 [ 0 ] ;
V_13 -> V_712 = V_335 [ 1 ] ;
V_13 -> V_188 . V_713 = F_104 ( V_13 -> V_188 . V_189 ) ? 15 : 16 ;
V_188 [ 0 ] = F_394 ( V_714 ) ;
V_188 [ 1 ] = F_394 ( V_715 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_335 ) ;
if ( ( V_335 [ 0 ] != V_335 [ 1 ] ) && ( V_54 >= 0 ) ) {
V_13 -> V_68 |= V_716 ;
V_13 -> V_248 . V_717 = V_335 [ 0 ] ;
V_13 -> V_248 . V_718 = V_335 [ 1 ] ;
}
V_188 [ 0 ] = F_394 ( V_719 ) ;
V_335 [ 0 ] = 1 ;
( void ) F_123 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_188 , V_335 ) ;
if ( F_104 ( V_13 -> V_188 . V_189 ) ) {
V_13 -> V_188 . V_720 = false ;
} else {
V_188 [ 0 ] = F_393 ( V_721 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_335 ) ;
V_13 -> V_188 . V_720 = ( V_54 == 0 && V_335 [ 0 ] != 0 ) ;
}
V_188 [ 0 ] = F_393 ( V_722 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_335 ) ;
V_13 -> V_188 . V_723 = ( V_54 == 0 && V_335 [ 0 ] != 0 ) ;
memset ( & V_645 , 0 , sizeof( V_645 ) ) ;
V_645 . V_600 = F_149 ( F_339 ( V_601 ) |
V_602 | V_603 ) ;
V_645 . V_604 = F_149 ( F_340 ( V_645 ) ) ;
V_54 = F_341 ( V_13 , V_13 -> V_27 , & V_645 , sizeof( V_645 ) ,
& V_645 ) ;
if ( V_54 < 0 )
goto V_658;
if ( V_645 . V_724 ) {
V_188 [ 0 ] = F_393 ( V_725 ) ;
V_188 [ 1 ] = F_394 ( V_726 ) ;
V_188 [ 2 ] = F_394 ( V_727 ) ;
V_188 [ 3 ] = F_394 ( V_728 ) ;
V_188 [ 4 ] = F_394 ( V_729 ) ;
V_188 [ 5 ] = F_393 ( V_730 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_248 . V_257 = V_335 [ 0 ] ;
V_13 -> V_248 . V_263 = F_396 ( V_13 -> V_248 . V_257 / 2 , V_731 ) ;
V_13 -> V_248 . V_236 = V_335 [ 1 ] ;
V_13 -> V_248 . V_234 = V_335 [ 2 ] - V_335 [ 1 ] + 1 ;
if ( V_13 -> V_68 & V_716 && ! F_397 ( V_13 ) ) {
V_13 -> V_248 . V_239 = V_13 -> V_248 . V_705 +
F_398 ( V_13 -> V_248 . V_262 , 3 ) ;
V_13 -> V_248 . V_238 = V_13 -> V_248 . V_262 -
F_398 ( V_13 -> V_248 . V_262 , 3 ) ;
V_13 -> V_248 . V_262 = V_13 -> V_248 . V_239 -
V_13 -> V_248 . V_705 ;
}
V_13 -> V_350 . V_732 . V_351 = V_335 [ 3 ] ;
V_13 -> V_350 . V_732 . V_192 = V_335 [ 4 ] - V_335 [ 3 ] + 1 ;
V_13 -> V_188 . V_733 = V_335 [ 5 ] ;
V_13 -> V_188 . V_734 = 1 ;
V_13 -> V_735 += 1 ;
}
if ( V_645 . V_736 ) {
V_188 [ 0 ] = F_394 ( V_737 ) ;
V_188 [ 1 ] = F_394 ( V_738 ) ;
V_188 [ 2 ] = F_394 ( V_739 ) ;
V_188 [ 3 ] = F_394 ( V_740 ) ;
V_188 [ 4 ] = F_394 ( V_741 ) ;
V_188 [ 5 ] = F_394 ( V_742 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_350 . V_337 . V_351 = V_335 [ 0 ] ;
V_13 -> V_350 . V_337 . V_192 = V_335 [ 1 ] - V_335 [ 0 ] + 1 ;
V_13 -> V_350 . V_743 . V_351 = V_335 [ 2 ] ;
V_13 -> V_350 . V_743 . V_192 = V_335 [ 3 ] - V_335 [ 2 ] + 1 ;
V_13 -> V_350 . V_744 . V_351 = V_335 [ 4 ] ;
V_13 -> V_350 . V_744 . V_192 = V_335 [ 5 ] - V_335 [ 4 ] + 1 ;
V_188 [ 0 ] = F_394 ( V_745 ) ;
V_188 [ 1 ] = F_394 ( V_746 ) ;
V_188 [ 2 ] = F_394 ( V_747 ) ;
V_188 [ 3 ] = F_394 ( V_748 ) ;
V_188 [ 4 ] = F_394 ( V_749 ) ;
V_188 [ 5 ] = F_394 ( V_750 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 ,
V_335 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_350 . V_751 . V_351 = V_335 [ 0 ] ;
V_13 -> V_350 . V_751 . V_192 = V_335 [ 1 ] - V_335 [ 0 ] + 1 ;
V_13 -> V_350 . V_752 . V_351 = V_335 [ 2 ] ;
V_13 -> V_350 . V_752 . V_192 = V_335 [ 3 ] - V_335 [ 2 ] + 1 ;
V_13 -> V_350 . V_592 . V_351 = V_335 [ 4 ] ;
V_13 -> V_350 . V_592 . V_192 = V_335 [ 5 ] - V_335 [ 4 ] + 1 ;
V_188 [ 0 ] = F_393 ( V_753 ) ;
V_188 [ 1 ] = F_393 ( V_754 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 ,
V_335 ) ;
if ( V_54 < 0 ) {
V_13 -> V_188 . V_755 = 8 ;
V_13 -> V_188 . V_756 = 32 * V_13 -> V_248 . V_257 ;
V_54 = 0 ;
} else {
V_13 -> V_188 . V_755 = V_335 [ 0 ] ;
V_13 -> V_188 . V_756 = V_335 [ 1 ] ;
}
F_306 ( V_13 -> V_30 ,
L_81 ,
V_13 -> V_188 . V_755 ,
V_13 -> V_188 . V_756 ) ;
V_13 -> V_735 += 2 ;
}
if ( V_645 . V_757 ) {
V_188 [ 0 ] = F_394 ( V_758 ) ;
V_188 [ 1 ] = F_394 ( V_759 ) ;
V_54 = F_373 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_188 , V_335 ) ;
if ( V_54 < 0 )
goto V_658;
V_13 -> V_350 . V_760 . V_351 = V_335 [ 0 ] ;
V_13 -> V_350 . V_760 . V_192 = V_335 [ 1 ] - V_335 [ 0 ] + 1 ;
V_13 -> V_735 += 2 ;
}
if ( V_645 . V_761 ) {
V_13 -> V_188 . V_762 |= V_763 ;
V_13 -> V_764 += 1 ;
}
#undef F_394
#undef F_393
F_399 ( V_13 , V_13 -> V_188 . V_298 , NULL ) ;
if ( V_35 != V_686 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_299 ; V_19 ++ )
if ( V_13 -> V_188 . V_298 [ V_19 ] == 1492 ) {
V_13 -> V_188 . V_298 [ V_19 ] = 1488 ;
break;
}
F_400 ( V_13 , V_13 -> V_188 . V_298 , V_13 -> V_188 . V_765 ,
V_13 -> V_188 . V_766 ) ;
}
F_401 ( V_13 ) ;
V_13 -> V_68 |= V_767 ;
F_402 ( V_13 ) ;
return 0 ;
V_658:
F_34 ( V_13 -> V_16 . V_98 ) ;
F_34 ( V_13 -> V_16 . V_164 ) ;
F_34 ( V_13 -> V_16 . V_171 ) ;
F_34 ( V_13 -> V_16 . V_173 ) ;
#ifdef F_129
F_34 ( V_13 -> V_16 . V_708 ) ;
#endif
if ( V_54 != - V_768 && V_54 != - V_769 )
F_403 ( V_13 , V_13 -> V_27 ) ;
return V_54 ;
}
static T_14 F_404 ( struct V_317 * V_128 ,
T_15 V_35 )
{
int V_19 ;
struct V_12 * V_13 = F_191 ( V_128 ) ;
if ( ! V_13 )
goto V_59;
F_405 () ;
V_13 -> V_68 &= ~ V_767 ;
F_258 ( V_13 , V_770 ) ;
F_192 ( & V_13 -> V_321 ) ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
F_406 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_194 ( & V_13 -> V_321 ) ;
F_89 ( V_13 ) ;
if ( V_13 -> V_68 & V_168 )
F_272 ( V_13 ) ;
F_407 () ;
if ( ( V_13 -> V_68 & V_771 ) ) {
F_408 ( V_128 ) ;
V_13 -> V_68 &= ~ V_771 ;
}
V_59: return V_35 == V_772 ?
V_773 : V_774 ;
}
static T_14 F_409 ( struct V_317 * V_128 )
{
int V_19 , V_54 ;
struct V_598 V_599 ;
struct V_12 * V_13 = F_191 ( V_128 ) ;
if ( ! V_13 ) {
F_410 ( V_128 ) ;
F_411 ( V_128 ) ;
return V_775 ;
}
if ( ! ( V_13 -> V_68 & V_771 ) ) {
if ( F_412 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 , L_82
L_83 ) ;
return V_773 ;
}
V_13 -> V_68 |= V_771 ;
}
F_413 ( V_128 ) ;
F_410 ( V_128 ) ;
F_411 ( V_128 ) ;
F_414 ( V_128 ) ;
if ( F_415 ( V_13 -> V_776 ) < 0 )
return V_773 ;
if ( F_382 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_679 , NULL ) < 0 )
return V_773 ;
V_13 -> V_68 |= V_767 ;
if ( F_338 ( V_13 , & V_599 ) )
return V_773 ;
F_73 (adap, i) {
struct V_5 * V_6 = F_84 ( V_13 , V_19 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_6 -> V_76 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_54 < 0 )
return V_773 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_74 = - 1 ;
}
F_400 ( V_13 , V_13 -> V_188 . V_298 , V_13 -> V_188 . V_765 ,
V_13 -> V_188 . V_766 ) ;
F_327 ( V_13 ) ;
if ( F_267 ( V_13 ) )
return V_773 ;
return V_775 ;
}
static void F_417 ( struct V_317 * V_128 )
{
int V_19 ;
struct V_12 * V_13 = F_191 ( V_128 ) ;
if ( ! V_13 )
return;
F_405 () ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( F_14 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_298 ( V_2 ) ;
}
F_418 ( V_2 ) ;
}
F_407 () ;
}
static inline bool F_419 ( const struct V_777 * V_778 )
{
unsigned int V_779 , V_780 ;
V_779 = F_420 ( F_421 ( V_778 -> V_781 ) ) ;
V_780 = V_779 & ~ ( V_782 | V_783 ) ;
return V_780 != 0 ;
}
static void F_422 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 = 0 , V_784 = 0 , V_785 = 0 ;
#ifndef F_16
int V_786 = 0 ;
#endif
if ( F_383 () ) {
V_13 -> V_188 . V_734 = 0 ;
V_13 -> V_188 . V_762 = 0 ;
} else if ( F_423 ( V_13 ) && F_424 ( V_13 ) ) {
V_13 -> V_188 . V_734 = 0 ;
V_13 -> V_188 . V_762 = 0 ;
}
V_784 += F_419 ( & F_84 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_16
if ( V_13 -> V_188 . V_694 * 8 > V_787 ) {
F_11 ( V_13 -> V_30 , L_84 ,
V_787 , V_13 -> V_188 . V_694 * 8 ) ;
F_425 ( 1 ) ;
}
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_785 ;
V_11 -> V_20 = 8 ;
V_785 += V_11 -> V_20 ;
}
#else
if ( V_784 )
V_786 = ( V_787 - ( V_13 -> V_188 . V_694 - V_784 ) ) / V_784 ;
if ( V_786 > F_426 () )
V_786 = F_426 () ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_785 ;
V_11 -> V_20 = F_419 ( & V_11 -> V_7 ) ? V_786 : 1 ;
V_785 += V_11 -> V_20 ;
}
#endif
V_4 -> V_788 = V_785 ;
V_4 -> V_789 = V_785 ;
if ( F_423 ( V_13 ) ) {
if ( V_784 ) {
V_19 = F_427 ( int , V_790 , F_428 () ) ;
V_4 -> V_791 = F_429 ( V_19 , V_13 -> V_188 . V_694 ) ;
} else {
V_4 -> V_791 = V_13 -> V_188 . V_694 ;
}
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_148 ) ; V_19 ++ ) {
struct V_153 * V_792 = & V_4 -> V_148 [ V_19 ] ;
F_430 ( V_13 , & V_792 -> V_149 , 5 , 10 , 1024 , 64 ) ;
V_792 -> V_181 . V_192 = 72 ;
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
while ( V_140 < V_13 -> V_16 . V_788 )
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_788 -- ;
if ( V_13 -> V_16 . V_788 <= V_140 )
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
struct V_793 * V_141 ;
unsigned int V_794 = 0 ;
if ( F_164 ( V_13 ) )
V_794 += V_790 * V_13 -> V_735 ;
if ( F_433 ( V_13 ) )
V_794 += V_790 * V_13 -> V_764 ;
if ( ! V_794 )
goto V_59;
V_141 = F_395 ( V_794 , sizeof( * V_141 ) , V_156 ) ;
if ( ! V_141 )
return - V_61 ;
V_13 -> V_795 . V_796 = F_395 ( F_161 ( V_794 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_795 . V_796 ) {
F_34 ( V_141 ) ;
return - V_61 ;
}
F_162 ( & V_13 -> V_795 . V_797 ) ;
V_13 -> V_798 = V_141 ;
V_59:
return 0 ;
}
static void F_434 ( struct V_12 * V_13 )
{
if ( ! ( V_13 -> V_764 && V_13 -> V_735 ) )
return;
F_34 ( V_13 -> V_798 ) ;
F_34 ( V_13 -> V_795 . V_796 ) ;
}
static int F_435 ( struct V_12 * V_13 )
{
int V_799 = 0 , V_800 = 0 ;
int V_19 , V_138 , V_801 , V_802 , V_803 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_804 = V_13 -> V_188 . V_694 ;
struct V_805 * V_806 ;
int V_794 = V_609 ;
if ( F_433 ( V_13 ) )
V_794 += ( V_790 * V_13 -> V_764 ) ;
if ( F_164 ( V_13 ) )
V_794 += ( V_790 * V_13 -> V_735 ) ;
V_806 = F_80 ( sizeof( * V_806 ) * ( V_794 + 1 ) ,
V_156 ) ;
if ( ! V_806 )
return - V_61 ;
if ( F_432 ( V_13 ) ) {
V_13 -> V_188 . V_734 = 0 ;
V_13 -> V_188 . V_762 = 0 ;
}
for ( V_19 = 0 ; V_19 < V_794 + 1 ; ++ V_19 )
V_806 [ V_19 ] . V_49 = V_19 ;
V_801 = V_4 -> V_789 + V_807 ;
if ( F_164 ( V_13 ) ) {
V_801 += V_13 -> V_735 * V_4 -> V_791 ;
V_799 = V_13 -> V_735 * V_804 ;
}
if ( F_433 ( V_13 ) ) {
V_801 += V_13 -> V_764 * V_4 -> V_791 ;
V_800 = V_13 -> V_764 * V_804 ;
}
#ifdef F_16
V_802 = 8 * V_13 -> V_188 . V_694 + V_807 + V_799 + V_800 ;
#else
V_802 = V_13 -> V_188 . V_694 + V_807 + V_799 + V_800 ;
#endif
V_803 = F_436 ( V_13 -> V_128 , V_806 , V_802 , V_801 ) ;
if ( V_803 < 0 ) {
F_306 ( V_13 -> V_30 , L_85
L_86 ) ;
F_34 ( V_806 ) ;
return V_803 ;
}
V_19 = V_803 - V_807 - V_799 - V_800 ;
if ( V_19 < V_4 -> V_789 ) {
V_4 -> V_789 = V_19 ;
if ( V_19 < V_4 -> V_788 )
F_431 ( V_13 , V_19 ) ;
}
if ( F_423 ( V_13 ) ) {
if ( V_803 < V_801 )
V_4 -> V_808 = V_804 ;
else
V_4 -> V_808 = V_4 -> V_791 ;
}
for ( V_19 = 0 ; V_19 < ( V_4 -> V_789 + V_807 ) ; ++ V_19 )
V_13 -> V_141 [ V_19 ] . V_46 = V_806 [ V_19 ] . V_809 ;
if ( F_423 ( V_13 ) ) {
for ( V_138 = 0 ; V_19 < V_803 ; ++ V_19 , V_138 ++ ) {
V_13 -> V_798 [ V_138 ] . V_46 = V_806 [ V_19 ] . V_809 ;
V_13 -> V_798 [ V_138 ] . V_184 = V_19 ;
}
V_13 -> V_795 . V_810 = V_138 ;
}
F_306 ( V_13 -> V_30 , L_87
L_88 ,
V_803 , V_4 -> V_789 , V_4 -> V_808 ) ;
F_34 ( V_806 ) ;
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
enum V_811 * V_8 ,
enum V_812 * V_813 )
{
T_1 V_814 , V_815 ;
int V_816 , V_817 ;
#define F_440 4
* V_8 = V_818 ;
* V_813 = V_819 ;
V_816 = F_441 ( V_13 -> V_128 , V_820 ,
& V_814 ) ;
V_817 = F_441 ( V_13 -> V_128 , V_821 ,
& V_815 ) ;
if ( ! V_817 && V_815 ) {
if ( V_815 & V_822 )
* V_8 = V_823 ;
else if ( V_815 & V_824 )
* V_8 = V_825 ;
else if ( V_815 & V_826 )
* V_8 = V_827 ;
}
if ( ! V_816 ) {
* V_813 = ( V_814 & V_828 ) >> F_440 ;
if ( ! V_815 ) {
if ( V_814 & V_829 )
* V_8 = V_825 ;
else if ( V_814 & V_830 )
* V_8 = V_827 ;
}
}
if ( * V_8 == V_818 || * V_813 == V_819 )
return V_816 ? V_816 : V_817 ? V_817 : - V_65 ;
return 0 ;
}
static void F_442 ( struct V_12 * V_13 )
{
enum V_812 V_813 , V_831 ;
enum V_811 V_8 , V_832 ;
#define F_443 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_439 ( V_13 , & V_832 , & V_831 ) ) {
F_363 ( V_13 -> V_30 ,
L_89 ) ;
return;
}
if ( F_444 ( V_13 -> V_128 , & V_8 , & V_813 ) ||
V_8 == V_818 || V_813 == V_819 ) {
F_363 ( V_13 -> V_30 ,
L_90 ) ;
return;
}
F_306 ( V_13 -> V_30 , L_91 ,
F_443 ( V_8 ) , F_443 ( V_832 ) ) ;
F_306 ( V_13 -> V_30 , L_92 ,
V_813 , V_831 ) ;
if ( V_8 < V_832 || V_813 < V_831 )
F_306 ( V_13 -> V_30 ,
L_93
L_94 ) ;
}
static void F_445 ( struct V_12 * V_12 )
{
F_306 ( V_12 -> V_30 , L_95 ,
V_12 -> V_188 . V_530 . V_543 ,
F_446 ( V_12 -> V_188 . V_189 ) ) ;
F_306 ( V_12 -> V_30 , L_96 ,
V_12 -> V_188 . V_530 . V_833 , V_12 -> V_188 . V_530 . V_834 ) ;
if ( ! V_12 -> V_188 . V_681 )
F_363 ( V_12 -> V_30 , L_97 ) ;
else
F_306 ( V_12 -> V_30 , L_98 ,
F_447 ( V_12 -> V_188 . V_681 ) ,
F_448 ( V_12 -> V_188 . V_681 ) ,
F_449 ( V_12 -> V_188 . V_681 ) ,
F_450 ( V_12 -> V_188 . V_681 ) ) ;
if ( ! V_12 -> V_188 . V_682 )
F_306 ( V_12 -> V_30 , L_99 ) ;
else
F_306 ( V_12 -> V_30 , L_100 ,
F_447 ( V_12 -> V_188 . V_682 ) ,
F_448 ( V_12 -> V_188 . V_682 ) ,
F_449 ( V_12 -> V_188 . V_682 ) ,
F_450 ( V_12 -> V_188 . V_682 ) ) ;
if ( ! V_12 -> V_188 . V_683 )
F_363 ( V_12 -> V_30 , L_101 ) ;
else
F_306 ( V_12 -> V_30 ,
L_102 ,
F_447 ( V_12 -> V_188 . V_683 ) ,
F_448 ( V_12 -> V_188 . V_683 ) ,
F_449 ( V_12 -> V_188 . V_683 ) ,
F_450 ( V_12 -> V_188 . V_683 ) ) ;
if ( ! V_12 -> V_188 . V_684 )
F_306 ( V_12 -> V_30 , L_103 ) ;
else
F_306 ( V_12 -> V_30 ,
L_104 ,
F_447 ( V_12 -> V_188 . V_684 ) ,
F_448 ( V_12 -> V_188 . V_684 ) ,
F_449 ( V_12 -> V_188 . V_684 ) ,
F_450 ( V_12 -> V_188 . V_684 ) ) ;
F_306 ( V_12 -> V_30 , L_105 ,
F_164 ( V_12 ) ? L_106 : L_107 ,
( ( V_12 -> V_68 & V_127 ) ? L_108 :
( V_12 -> V_68 & V_129 ) ? L_109 : L_107 ) ,
F_164 ( V_12 ) ? L_110 : L_111 ) ;
}
static void F_451 ( const struct V_1 * V_2 )
{
char V_671 [ 80 ] ;
char * V_835 = V_671 ;
const char * V_836 = L_107 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_188 . V_837 . V_8 == V_838 )
V_836 = L_112 ;
else if ( V_13 -> V_188 . V_837 . V_8 == V_839 )
V_836 = L_113 ;
else if ( V_13 -> V_188 . V_837 . V_8 == V_840 )
V_836 = L_114 ;
if ( V_11 -> V_7 . V_781 & V_782 )
V_835 += sprintf ( V_835 , L_115 ) ;
if ( V_11 -> V_7 . V_781 & V_783 )
V_835 += sprintf ( V_835 , L_116 ) ;
if ( V_11 -> V_7 . V_781 & V_841 )
V_835 += sprintf ( V_835 , L_117 ) ;
if ( V_11 -> V_7 . V_781 & V_842 )
V_835 += sprintf ( V_835 , L_118 ) ;
if ( V_11 -> V_7 . V_781 & V_843 )
V_835 += sprintf ( V_835 , L_119 ) ;
if ( V_11 -> V_7 . V_781 & V_844 )
V_835 += sprintf ( V_835 , L_120 ) ;
if ( V_835 != V_671 )
-- V_835 ;
sprintf ( V_835 , L_121 , F_452 ( V_11 -> V_845 ) ) ;
F_3 ( V_2 , L_122 ,
V_2 -> V_9 , V_13 -> V_188 . V_530 . V_543 , V_13 -> V_9 , V_671 ) ;
}
static void F_453 ( struct V_317 * V_2 )
{
F_454 ( V_2 , V_846 , V_847 ) ;
}
static void F_455 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_109 ( V_12 -> V_848 ) ;
F_456 ( V_12 ) ;
F_109 ( V_12 -> V_248 . V_247 ) ;
F_457 ( V_12 ) ;
F_34 ( V_12 -> V_16 . V_98 ) ;
F_34 ( V_12 -> V_16 . V_164 ) ;
F_34 ( V_12 -> V_16 . V_171 ) ;
F_34 ( V_12 -> V_16 . V_173 ) ;
#ifdef F_129
F_34 ( V_12 -> V_16 . V_708 ) ;
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
if ( V_12 -> V_68 & V_767 )
F_403 ( V_12 , V_12 -> V_28 ) ;
}
static int F_460 ( struct V_317 * V_128 , T_1 V_849 )
{
T_6 V_850 ;
F_461 ( V_128 , V_851 , & V_850 ) ;
switch ( V_850 >> 12 ) {
case V_659 :
return F_462 ( V_659 , V_849 ) ;
case V_271 :
return F_462 ( V_271 , V_849 ) ;
case V_662 :
return F_462 ( V_662 , V_849 ) ;
default:
F_11 ( & V_128 -> V_2 , L_57 ,
V_850 ) ;
}
return - V_65 ;
}
static void F_463 ( struct V_1 * V_2 )
{
V_2 -> type = V_852 ;
V_2 -> V_66 = 0 ;
V_2 -> V_853 = 0 ;
V_2 -> V_547 = 0 ;
V_2 -> V_854 = 0 ;
V_2 -> V_68 |= V_855 ;
V_2 -> V_856 |= V_857 ;
V_2 -> V_858 = & V_859 ;
V_2 -> V_860 = & V_861 ;
V_2 -> V_862 = F_459 ;
}
static int F_464 ( struct V_317 * V_128 )
{
struct V_12 * V_13 = F_191 ( V_128 ) ;
struct V_1 * V_52 ;
struct V_5 * V_11 ;
char V_9 [ V_863 ] ;
int V_22 ;
snprintf ( V_9 , V_863 , L_123 , V_13 -> V_541 , V_13 -> V_28 ) ;
V_52 = F_465 ( sizeof( struct V_5 ) , V_9 , V_864 ,
F_463 ) ;
if ( ! V_52 )
return - V_61 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_13 ;
V_11 -> V_31 = V_13 -> V_28 % V_13 -> V_188 . V_694 ;
F_466 ( V_52 , & V_128 -> V_2 ) ;
V_13 -> V_39 [ 0 ] = V_52 ;
V_22 = F_467 ( V_13 -> V_39 [ 0 ] ) ;
if ( V_22 ) {
F_5 ( L_124 , V_9 ) ;
F_459 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
return V_22 ;
}
return 0 ;
}
static int F_468 ( struct V_317 * V_128 , int V_531 )
{
struct V_12 * V_13 = F_191 ( V_128 ) ;
int V_22 = 0 ;
int V_865 = F_469 ( V_128 ) ;
T_1 V_866 ;
V_866 = F_470 ( V_13 -> V_776 + V_867 ) ;
if ( ! ( V_866 & V_868 ) ||
! ( V_866 & V_869 ) ||
F_471 ( V_866 ) != 4 ) {
F_363 ( & V_128 -> V_2 ,
L_125 ) ;
return - V_507 ;
}
if ( V_865 && F_472 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 ,
L_126 ) ;
V_531 = V_865 ;
return V_531 ;
}
if ( ! V_531 ) {
F_473 ( V_128 ) ;
if ( V_13 -> V_39 [ 0 ] ) {
F_474 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
}
F_34 ( V_13 -> V_532 ) ;
V_13 -> V_532 = NULL ;
V_13 -> V_531 = 0 ;
return V_531 ;
}
if ( V_531 != V_865 ) {
V_22 = F_475 ( V_128 , V_531 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_531 = V_531 ;
V_22 = F_464 ( V_128 ) ;
if ( V_22 )
return V_22 ;
}
V_13 -> V_532 = F_395 ( V_13 -> V_531 ,
sizeof( struct V_870 ) , V_156 ) ;
if ( V_13 -> V_532 )
F_301 ( V_13 ) ;
return V_531 ;
}
static int F_476 ( struct V_317 * V_128 , const struct V_871 * V_872 )
{
int V_873 , V_19 , V_22 , V_874 , V_875 , V_876 ;
struct V_5 * V_11 ;
bool V_877 = false ;
struct V_12 * V_12 = NULL ;
struct V_1 * V_52 ;
void T_16 * V_776 ;
T_1 V_878 , V_849 ;
enum V_309 V_189 ;
static int V_541 = 1 ;
#ifdef F_477
T_1 V_132 , V_677 ;
#endif
F_478 ( V_879 L_127 , V_880 , V_881 ) ;
V_22 = F_479 ( V_128 , V_882 ) ;
if ( V_22 ) {
F_306 ( & V_128 -> V_2 , L_128 ) ;
return V_22 ;
}
V_22 = F_412 ( V_128 ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_129 ) ;
goto V_883;
}
V_776 = F_480 ( V_128 , 0 ) ;
if ( ! V_776 ) {
F_11 ( & V_128 -> V_2 , L_130 ) ;
V_22 = - V_61 ;
goto V_884;
}
V_22 = F_415 ( V_776 ) ;
if ( V_22 < 0 )
goto V_885;
V_878 = F_470 ( V_776 + V_886 ) ;
V_849 = F_481 ( F_470 ( V_776 + V_887 ) ) ;
V_189 = F_460 ( V_128 , V_849 ) ;
V_873 = F_165 ( V_189 ) <= V_271 ?
F_482 ( V_878 ) : F_483 ( V_878 ) ;
if ( V_873 != V_872 -> V_888 ) {
#ifndef F_477
F_484 ( V_776 ) ;
#endif
F_408 ( V_128 ) ;
F_411 ( V_128 ) ;
goto V_889;
}
if ( ! F_485 ( V_128 , F_486 ( 64 ) ) ) {
V_877 = true ;
V_22 = F_487 ( V_128 , F_486 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_131
L_132 ) ;
goto V_885;
}
} else {
V_22 = F_485 ( V_128 , F_486 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_133 ) ;
goto V_885;
}
}
F_488 ( V_128 ) ;
F_453 ( V_128 ) ;
F_413 ( V_128 ) ;
F_411 ( V_128 ) ;
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_885;
}
V_541 ++ ;
V_12 -> V_253 = F_489 ( L_134 ) ;
if ( ! V_12 -> V_253 ) {
V_22 = - V_61 ;
goto V_890;
}
V_12 -> V_891 = F_27 ( sizeof( * V_12 -> V_891 ) +
( sizeof( struct V_892 ) *
V_893 ) ,
V_156 ) ;
if ( ! V_12 -> V_891 ) {
V_22 = - V_61 ;
goto V_890;
}
V_12 -> V_891 -> V_192 = V_893 ;
V_12 -> V_68 |= V_771 ;
V_12 -> V_776 = V_776 ;
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_323 ( V_128 ) ;
V_12 -> V_27 = V_873 ;
V_12 -> V_28 = V_873 ;
V_12 -> V_894 = V_895 ;
memset ( V_12 -> V_81 , 0xff , sizeof( V_12 -> V_81 ) ) ;
F_162 ( & V_12 -> V_321 ) ;
F_162 ( & V_12 -> V_249 ) ;
F_162 ( & V_12 -> V_330 ) ;
F_162 ( & V_12 -> V_896 ) ;
F_271 ( & V_12 -> V_897 . V_62 ) ;
F_490 ( & V_12 -> V_254 , F_153 ) ;
F_490 ( & V_12 -> V_396 , F_241 ) ;
F_490 ( & V_12 -> V_403 , F_246 ) ;
V_22 = F_491 ( V_12 ) ;
if ( V_22 )
goto V_890;
if ( ! F_104 ( V_12 -> V_188 . V_189 ) ) {
V_874 = ( V_898 +
( V_899 - V_898 ) *
V_12 -> V_28 ) ;
V_875 = 1 << F_492 ( F_68 ( V_12 ,
V_900 ) >> V_874 ) ;
V_876 = V_625 / V_901 ;
if ( V_875 > V_876 ) {
F_11 ( & V_128 -> V_2 ,
L_135 ) ;
V_22 = - V_65 ;
goto V_890;
}
V_12 -> V_409 = F_493 ( F_494 ( V_128 , 2 ) ,
F_495 ( V_128 , 2 ) ) ;
if ( ! V_12 -> V_409 ) {
F_11 ( & V_128 -> V_2 , L_136 ) ;
V_22 = - V_61 ;
goto V_890;
}
}
F_327 ( V_12 ) ;
V_22 = F_380 ( V_12 ) ;
#ifdef F_129
F_96 ( V_12 -> V_16 . V_708 , V_12 -> V_16 . V_172 ) ;
#endif
F_330 ( V_12 ) ;
if ( V_22 )
goto V_902;
if ( ! F_104 ( V_12 -> V_188 . V_189 ) )
F_70 ( V_12 , V_903 , F_496 ( 7 ) |
( F_214 ( V_12 -> V_188 . V_189 ) ? F_497 ( 0 ) :
F_498 ( 0 ) ) ) ;
F_73 (adapter, i) {
V_52 = F_499 ( sizeof( struct V_5 ) ,
V_787 ) ;
if ( ! V_52 ) {
V_22 = - V_61 ;
goto V_904;
}
F_466 ( V_52 , & V_128 -> V_2 ) ;
V_12 -> V_39 [ V_19 ] = V_52 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_74 = - 1 ;
V_11 -> V_31 = V_19 ;
V_52 -> V_130 = V_128 -> V_130 ;
V_52 -> V_905 = V_906 | V_907 |
V_908 | V_909 |
V_910 | V_911 |
V_912 | V_73 |
V_913 ;
if ( V_877 )
V_52 -> V_905 |= V_914 ;
V_52 -> V_72 |= V_52 -> V_905 ;
V_52 -> V_915 = V_52 -> V_72 & V_916 ;
V_52 -> V_856 |= V_917 ;
V_52 -> V_918 = 81 ;
V_52 -> V_304 = V_919 ;
V_52 -> V_858 = & V_920 ;
#ifdef F_16
V_52 -> V_921 = & V_922 ;
F_17 ( V_52 ) ;
#endif
F_500 ( V_52 ) ;
}
F_501 ( V_128 , V_12 ) ;
if ( V_12 -> V_68 & V_767 ) {
V_22 = F_502 ( V_12 , V_873 , V_873 , 0 ) ;
if ( V_22 )
goto V_904;
} else if ( V_12 -> V_188 . V_694 == 1 ) {
T_3 V_524 [ V_525 ] ;
T_3 * V_527 = V_12 -> V_188 . V_530 . V_527 ;
V_22 = F_302 ( V_12 , & V_12 -> V_188 . V_530 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_525 ; V_19 ++ )
V_524 [ V_19 ] = ( F_303 ( V_527 [ 2 * V_19 + 0 ] ) * 16 +
F_303 ( V_527 [ 2 * V_19 + 1 ] ) ) ;
F_503 ( V_12 , 0 , V_524 ) ;
}
}
F_422 ( V_12 ) ;
V_12 -> V_848 = F_504 ( V_12 -> V_703 , V_12 -> V_704 ) ;
if ( ! V_12 -> V_848 ) {
F_363 ( & V_128 -> V_2 , L_137 ) ;
V_12 -> V_188 . V_734 = 0 ;
}
#if F_260 ( V_438 )
if ( ( F_165 ( V_12 -> V_188 . V_189 ) <= V_271 ) &&
( ! ( F_68 ( V_12 , V_923 ) & V_924 ) ) ) {
F_363 ( & V_128 -> V_2 ,
L_138 ) ;
V_12 -> V_188 . V_734 = 0 ;
} else {
V_12 -> V_925 = F_505 ( V_12 -> V_711 ,
V_12 -> V_712 ) ;
if ( ! V_12 -> V_925 ) {
F_363 ( & V_128 -> V_2 ,
L_139 ) ;
V_12 -> V_188 . V_734 = 0 ;
}
}
#endif
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_11 -> V_926 = F_506 ( V_12 -> V_188 . V_713 ) ;
if ( ! V_11 -> V_926 )
F_363 ( & V_128 -> V_2 ,
L_140 ,
V_19 ) ;
}
if ( F_160 ( & V_12 -> V_248 ) < 0 ) {
F_363 ( & V_128 -> V_2 , L_141
L_142 ) ;
V_12 -> V_188 . V_734 = 0 ;
} else {
V_12 -> V_927 = F_507 ( V_12 ) ;
if ( ! V_12 -> V_927 )
F_363 ( & V_128 -> V_2 ,
L_143 ) ;
}
if ( F_164 ( V_12 ) ) {
if ( F_68 ( V_12 , V_923 ) & V_928 ) {
T_1 V_258 , V_929 ;
if ( V_189 <= V_271 ) {
V_929 = V_930 ;
V_258 = F_68 ( V_12 , V_929 ) ;
V_12 -> V_248 . V_258 = V_258 / 4 ;
} else {
V_929 = V_931 ;
V_258 = F_68 ( V_12 , V_929 ) ;
V_12 -> V_248 . V_258 = V_258 ;
}
}
}
if ( V_932 > 1 && F_435 ( V_12 ) == 0 )
V_12 -> V_68 |= V_127 ;
else if ( V_932 > 0 && F_508 ( V_128 ) == 0 ) {
V_12 -> V_68 |= V_129 ;
if ( V_932 > 1 )
F_434 ( V_12 ) ;
}
F_442 ( V_12 ) ;
V_22 = F_437 ( V_12 ) ;
if ( V_22 )
goto V_904;
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_12 -> V_39 [ V_19 ] -> V_933 = V_11 -> V_444 ;
F_509 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_510 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_467 ( V_12 -> V_39 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_81 [ V_11 -> V_76 ] = V_19 ;
F_451 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_128 -> V_2 , L_144 ) ;
goto V_904;
}
if ( V_22 ) {
F_363 ( & V_128 -> V_2 , L_145 , V_19 ) ;
V_22 = 0 ;
}
if ( V_934 ) {
V_12 -> V_219 = F_511 ( F_323 ( V_128 ) ,
V_934 ) ;
F_127 ( V_12 ) ;
}
V_128 -> V_935 = 1 ;
if ( F_423 ( V_12 ) ) {
F_253 ( & V_416 ) ;
F_29 ( & V_12 -> V_417 , & V_420 ) ;
F_257 ( & V_416 ) ;
}
F_445 ( V_12 ) ;
F_95 ( V_12 ) ;
return 0 ;
V_889:
#ifdef F_477
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_936;
}
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_323 ( V_128 ) ;
V_12 -> V_27 = V_873 ;
V_12 -> V_28 = V_873 ;
V_12 -> V_776 = V_776 ;
V_12 -> V_541 = V_541 ;
V_12 -> V_891 = F_27 ( sizeof( * V_12 -> V_891 ) +
( sizeof( struct V_892 ) *
V_893 ) ,
V_156 ) ;
if ( ! V_12 -> V_891 ) {
V_22 = - V_61 ;
goto V_937;
}
F_162 ( & V_12 -> V_896 ) ;
F_271 ( & V_12 -> V_897 . V_62 ) ;
V_132 = F_7 ( V_666 ) |
F_8 ( V_693 ) ;
V_22 = F_373 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 ,
& V_132 , & V_677 ) ;
if ( V_22 < 0 ) {
F_11 ( V_12 -> V_30 , L_146 ) ;
goto V_937;
}
V_12 -> V_188 . V_694 = F_391 ( V_677 ) ;
F_501 ( V_128 , V_12 ) ;
return 0 ;
V_937:
F_34 ( V_12 ) ;
V_936:
F_484 ( V_776 ) ;
F_473 ( V_128 ) ;
F_512 ( V_128 ) ;
return V_22 ;
#else
return 0 ;
#endif
V_904:
F_455 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_434 ( V_12 ) ;
if ( V_12 -> V_764 || V_12 -> V_735 )
F_513 ( V_12 ) ;
V_902:
if ( ! F_104 ( V_12 -> V_188 . V_189 ) )
F_484 ( V_12 -> V_409 ) ;
V_890:
if ( V_12 -> V_253 )
F_514 ( V_12 -> V_253 ) ;
F_34 ( V_12 -> V_891 ) ;
F_34 ( V_12 ) ;
V_885:
F_484 ( V_776 ) ;
V_884:
F_515 ( V_128 ) ;
F_408 ( V_128 ) ;
V_883:
F_512 ( V_128 ) ;
return V_22 ;
}
static void F_516 ( struct V_317 * V_128 )
{
struct V_12 * V_12 = F_191 ( V_128 ) ;
if ( ! V_12 ) {
F_512 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_514 ( V_12 -> V_253 ) ;
if ( F_423 ( V_12 ) )
F_252 ( V_12 ) ;
F_89 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_938 == V_939 )
F_474 ( V_12 -> V_39 [ V_19 ] ) ;
F_517 ( V_12 -> V_219 ) ;
F_518 ( V_12 ) ;
if ( V_12 -> V_68 & V_168 )
F_272 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_434 ( V_12 ) ;
if ( V_12 -> V_764 || V_12 -> V_735 )
F_513 ( V_12 ) ;
F_455 ( V_12 ) ;
#if F_260 ( V_438 )
F_519 ( V_12 ) ;
#endif
F_484 ( V_12 -> V_776 ) ;
if ( ! F_104 ( V_12 -> V_188 . V_189 ) )
F_484 ( V_12 -> V_409 ) ;
F_515 ( V_128 ) ;
if ( ( V_12 -> V_68 & V_771 ) ) {
F_408 ( V_128 ) ;
V_12 -> V_68 &= ~ V_771 ;
}
F_512 ( V_128 ) ;
F_34 ( V_12 -> V_891 ) ;
F_520 () ;
F_34 ( V_12 ) ;
}
#ifdef F_477
else {
if ( V_12 -> V_39 [ 0 ] )
F_474 ( V_12 -> V_39 [ 0 ] ) ;
F_484 ( V_12 -> V_776 ) ;
F_34 ( V_12 -> V_532 ) ;
F_34 ( V_12 ) ;
F_473 ( V_128 ) ;
F_512 ( V_128 ) ;
}
#endif
}
static void F_521 ( struct V_317 * V_128 )
{
struct V_12 * V_12 = F_191 ( V_128 ) ;
if ( ! V_12 ) {
F_512 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_938 == V_939 )
F_277 ( V_12 -> V_39 [ V_19 ] ) ;
F_522 ( V_12 ) ;
F_89 ( V_12 ) ;
F_64 ( V_12 ) ;
F_274 ( V_12 ) ;
if ( V_12 -> V_68 & V_767 )
F_403 ( V_12 , V_12 -> V_27 ) ;
}
#ifdef F_477
else {
if ( V_12 -> V_39 [ 0 ] )
F_474 ( V_12 -> V_39 [ 0 ] ) ;
F_484 ( V_12 -> V_776 ) ;
F_34 ( V_12 -> V_532 ) ;
F_34 ( V_12 ) ;
F_473 ( V_128 ) ;
F_512 ( V_128 ) ;
}
#endif
}
static int T_17 F_523 ( void )
{
int V_54 ;
V_934 = F_511 ( V_882 , NULL ) ;
if ( ! V_934 )
F_524 ( L_147 ) ;
V_54 = F_525 ( & V_376 ) ;
if ( V_54 < 0 )
F_526 ( V_934 ) ;
#if F_260 ( V_438 )
if ( ! V_940 ) {
F_527 ( & V_941 ) ;
V_940 = true ;
}
#endif
return V_54 ;
}
static void T_18 F_528 ( void )
{
#if F_260 ( V_438 )
if ( V_940 ) {
F_529 ( & V_941 ) ;
V_940 = false ;
}
#endif
F_530 ( & V_376 ) ;
F_526 ( V_934 ) ;
}
