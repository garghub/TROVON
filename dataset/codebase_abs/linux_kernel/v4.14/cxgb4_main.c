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
( V_111 == V_114 ||
V_111 == V_115 ) ) {
int V_39 = F_47 (
F_59 ( V_79 -> V_80 ) ) ;
struct V_1 * V_2 ;
int V_116 , V_117 ;
V_2 = V_25 -> V_13 -> V_39 [ V_25 -> V_13 -> V_81 [ V_39 ] ] ;
V_116 = ( V_111 == V_114
? ! ! ( V_79 -> V_118 . V_119 . V_120 &
V_121 )
: ! ! ( V_79 -> V_118 . V_122 . V_123 &
V_124 ) ) ;
V_117 = ( V_116
? V_125
: V_126 ) ;
F_60 ( V_2 , V_117 ) ;
}
if ( V_110 == V_113 &&
V_111 == V_127 )
F_46 ( V_25 -> V_13 , V_79 ) ;
else
#endif
if ( V_6 -> type == 0 )
F_61 ( V_25 -> V_13 , V_6 -> V_109 ) ;
} else if ( V_88 == V_128 ) {
const struct V_129 * V_6 = ( void * ) V_85 ;
F_62 ( V_25 -> V_13 , V_6 ) ;
} else if ( V_88 == V_130 ) {
const struct V_131 * V_6 = ( void * ) V_85 ;
F_63 ( V_25 -> V_13 , V_6 ) ;
} else
F_11 ( V_25 -> V_13 -> V_30 ,
L_30 , V_88 ) ;
V_59:
return 0 ;
}
static void F_64 ( struct V_12 * V_12 )
{
if ( V_12 -> V_68 & V_132 ) {
F_65 ( V_12 -> V_133 ) ;
V_12 -> V_68 &= ~ V_132 ;
} else if ( V_12 -> V_68 & V_134 ) {
F_66 ( V_12 -> V_133 ) ;
V_12 -> V_68 &= ~ V_134 ;
}
}
static T_5 F_67 ( int V_135 , void * V_136 )
{
struct V_12 * V_13 = V_136 ;
T_1 V_137 = F_68 ( V_13 , F_69 ( V_138 ) ) ;
if ( V_137 & V_139 ) {
V_13 -> V_140 = 1 ;
F_70 ( V_13 , F_69 ( V_138 ) , V_137 ) ;
}
if ( V_13 -> V_68 & V_141 )
F_71 ( V_13 ) ;
return V_142 ;
}
static void F_72 ( struct V_12 * V_13 )
{
int V_19 , V_143 , V_144 = 2 , V_145 = sizeof( V_13 -> V_146 [ 0 ] . V_147 ) ;
snprintf ( V_13 -> V_146 [ 0 ] . V_147 , V_145 , L_31 , V_13 -> V_39 [ 0 ] -> V_9 ) ;
snprintf ( V_13 -> V_146 [ 1 ] . V_147 , V_145 , L_32 ,
V_13 -> V_39 [ 0 ] -> V_9 ) ;
F_73 (adap, j) {
struct V_1 * V_148 = V_13 -> V_39 [ V_143 ] ;
const struct V_5 * V_11 = F_4 ( V_148 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_144 ++ )
snprintf ( V_13 -> V_146 [ V_144 ] . V_147 , V_145 , L_33 ,
V_148 -> V_9 , V_19 ) ;
}
}
static int F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 , V_149 ;
int V_150 = 2 ;
V_22 = F_75 ( V_13 -> V_146 [ 1 ] . V_46 , V_151 , 0 ,
V_13 -> V_146 [ 1 ] . V_147 , & V_4 -> V_152 ) ;
if ( V_22 )
return V_22 ;
F_76 (s, ethqidx) {
V_22 = F_75 ( V_13 -> V_146 [ V_150 ] . V_46 ,
V_151 , 0 ,
V_13 -> V_146 [ V_150 ] . V_147 ,
& V_4 -> V_153 [ V_149 ] . V_154 ) ;
if ( V_22 )
goto V_155;
V_150 ++ ;
}
return 0 ;
V_155:
while ( -- V_149 >= 0 )
F_77 ( V_13 -> V_146 [ -- V_150 ] . V_46 ,
& V_4 -> V_153 [ V_149 ] . V_154 ) ;
F_77 ( V_13 -> V_146 [ 1 ] . V_46 , & V_4 -> V_152 ) ;
return V_22 ;
}
static void F_78 ( struct V_12 * V_13 )
{
int V_19 , V_150 = 2 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_77 ( V_13 -> V_146 [ 1 ] . V_46 , & V_4 -> V_152 ) ;
F_76 (s, i)
F_77 ( V_13 -> V_146 [ V_150 ++ ] . V_46 , & V_4 -> V_153 [ V_19 ] . V_154 ) ;
}
int F_79 ( const struct V_5 * V_11 , const T_6 * V_156 )
{
T_6 * V_157 ;
int V_19 , V_22 ;
struct V_12 * V_12 = V_11 -> V_12 ;
const struct V_158 * V_159 ;
V_159 = & V_12 -> V_16 . V_153 [ V_11 -> V_18 ] ;
V_157 = F_80 ( V_11 -> V_160 * sizeof( T_6 ) , V_161 ) ;
if ( ! V_157 )
return - V_61 ;
for ( V_19 = 0 ; V_19 < V_11 -> V_160 ; V_19 ++ , V_156 ++ )
V_157 [ V_19 ] = V_159 [ * V_156 ] . V_154 . V_162 ;
V_22 = F_81 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , 0 ,
V_11 -> V_160 , V_157 , V_11 -> V_160 ) ;
if ( ! V_22 )
V_22 = F_82 ( V_12 , V_12 -> V_27 , V_11 -> V_51 ,
V_163 |
V_164 |
V_165 |
V_166 |
V_167 ,
V_157 [ 0 ] ) ;
F_34 ( V_157 ) ;
return V_22 ;
}
static int F_83 ( struct V_12 * V_13 )
{
int V_19 , V_143 , V_22 ;
F_73 (adap, i) {
const struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
for ( V_143 = 0 ; V_143 < V_11 -> V_160 ; V_143 ++ )
V_11 -> V_157 [ V_143 ] = V_143 % V_11 -> V_20 ;
V_22 = F_79 ( V_11 , V_11 -> V_157 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static unsigned int F_85 ( const struct V_16 * V_6 , unsigned int V_95 )
{
V_95 -= V_6 -> V_168 ;
return F_86 ( V_6 -> V_169 [ V_95 ] -> V_52 ) -> V_76 ;
}
static void F_87 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_170 ; V_19 ++ ) {
struct V_84 * V_25 = V_13 -> V_16 . V_169 [ V_19 ] ;
if ( V_25 && V_25 -> V_171 )
F_88 ( & V_25 -> V_172 ) ;
}
}
static void F_89 ( struct V_12 * V_13 )
{
if ( V_13 -> V_68 & V_173 ) {
F_90 ( V_13 ) ;
if ( V_13 -> V_68 & V_132 ) {
F_78 ( V_13 ) ;
F_77 ( V_13 -> V_146 [ 0 ] . V_46 , V_13 ) ;
} else {
F_77 ( V_13 -> V_133 -> V_135 , V_13 ) ;
}
F_87 ( V_13 ) ;
}
}
static void F_91 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_170 ; V_19 ++ ) {
struct V_84 * V_25 = V_13 -> V_16 . V_169 [ V_19 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_171 )
F_92 ( & V_25 -> V_172 ) ;
F_70 ( V_13 , F_69 ( V_174 ) ,
F_93 ( V_25 -> V_175 ) |
F_94 ( V_25 -> V_26 ) ) ;
}
}
static int F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 = 0 ;
F_96 ( V_4 -> V_176 , V_4 -> V_177 ) ;
F_96 ( V_4 -> V_178 , V_4 -> V_177 ) ;
if ( V_13 -> V_68 & V_132 )
V_13 -> V_144 = 1 ;
else {
V_22 = F_97 ( V_13 , & V_4 -> V_179 , false , V_13 -> V_39 [ 0 ] , 0 ,
NULL , NULL , NULL , - 1 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_144 = - ( ( int ) V_4 -> V_179 . V_162 + 1 ) ;
}
V_22 = F_97 ( V_13 , & V_4 -> V_152 , true , V_13 -> V_39 [ 0 ] ,
V_13 -> V_144 , NULL , F_50 , NULL , - 1 ) ;
if ( V_22 )
F_98 ( V_13 ) ;
return V_22 ;
}
static int F_99 ( struct V_12 * V_13 )
{
int V_22 , V_19 , V_143 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
struct V_180 * V_181 = NULL ;
unsigned int V_182 = 0 ;
if ( F_100 ( V_13 ) )
V_181 = V_4 -> V_183 [ V_184 ] ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_158 * V_25 = & V_4 -> V_153 [ V_11 -> V_18 ] ;
struct V_14 * V_185 = & V_4 -> V_17 [ V_11 -> V_18 ] ;
for ( V_143 = 0 ; V_143 < V_11 -> V_20 ; V_143 ++ , V_25 ++ ) {
if ( V_13 -> V_144 > 0 )
V_13 -> V_144 ++ ;
V_22 = F_97 ( V_13 , & V_25 -> V_154 , false , V_2 ,
V_13 -> V_144 , & V_25 -> V_186 ,
V_187 ,
NULL ,
F_101 ( V_13 ,
V_11 -> V_76 ) ) ;
if ( V_22 )
goto V_188;
V_25 -> V_154 . V_189 = V_143 ;
memset ( & V_25 -> V_190 , 0 , sizeof( V_25 -> V_190 ) ) ;
}
for ( V_143 = 0 ; V_143 < V_11 -> V_20 ; V_143 ++ , V_185 ++ ) {
V_22 = F_102 ( V_13 , V_185 , V_2 ,
F_103 ( V_2 , V_143 ) ,
V_4 -> V_152 . V_26 ) ;
if ( V_22 )
goto V_188;
}
}
F_73 (adap, i) {
if ( V_181 )
V_182 = V_181 -> V_191 [ V_19 ] . V_154 . V_26 ;
V_22 = F_104 ( V_13 , & V_4 -> V_192 [ V_19 ] , V_13 -> V_39 [ V_19 ] ,
V_4 -> V_152 . V_26 , V_182 ) ;
if ( V_22 )
goto V_188;
}
if ( ! F_105 ( V_13 -> V_193 . V_194 ) ) {
V_22 = F_102 ( V_13 , & V_4 -> V_195 , V_13 -> V_39 [ 0 ] ,
F_103 ( V_13 -> V_39 [ 0 ] , 0 )
, V_4 -> V_152 . V_26 ) ;
if ( V_22 )
goto V_188;
}
F_70 ( V_13 , F_105 ( V_13 -> V_193 . V_194 ) ?
V_196 :
V_197 ,
F_106 ( F_86 ( V_13 -> V_39 [ 0 ] ) -> V_76 ) |
F_107 ( V_4 -> V_153 [ 0 ] . V_154 . V_162 ) ) ;
return 0 ;
V_188:
F_98 ( V_13 ) ;
return V_22 ;
}
static T_6 F_108 ( struct V_1 * V_2 , struct V_198 * V_199 ,
void * V_200 , T_7 V_201 )
{
int V_15 ;
#ifdef F_16
if ( F_12 ( V_2 ) && ! F_109 () ) {
T_6 V_202 ;
int V_22 ;
V_22 = F_110 ( V_199 , & V_202 ) ;
if ( F_51 ( V_22 ) ) {
if ( F_111 () )
F_112 ( V_2 ,
L_34 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_202 & V_203 ) >> V_204 ;
#ifdef F_113
if ( V_199 -> V_205 == F_114 ( V_206 ) )
V_15 = V_199 -> V_207 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_208 ) {
V_15 = ( F_115 ( V_199 )
? F_116 ( V_199 )
: F_117 () ) ;
while ( F_51 ( V_15 >= V_2 -> V_209 ) )
V_15 -= V_2 -> V_209 ;
return V_15 ;
}
return V_201 ( V_2 , V_199 ) % V_2 -> V_209 ;
}
static int F_118 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_210 , V_211 = 0 , V_212 = V_213 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_214 ) ; V_19 ++ ) {
V_210 = time - V_4 -> V_214 [ V_19 ] ;
if ( V_210 < 0 )
V_210 = - V_210 ;
if ( V_210 < V_212 ) {
V_212 = V_210 ;
V_211 = V_19 ;
}
}
return V_211 ;
}
static int F_119 ( const struct V_16 * V_4 , int V_215 )
{
int V_19 , V_210 , V_211 = 0 , V_212 = V_213 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_216 ) ; V_19 ++ ) {
V_210 = V_215 - V_4 -> V_216 [ V_19 ] ;
if ( V_210 < 0 )
V_210 = - V_210 ;
if ( V_210 < V_212 ) {
V_212 = V_210 ;
V_211 = V_19 ;
}
}
return V_211 ;
}
int F_120 ( struct V_84 * V_25 ,
unsigned int V_217 , unsigned int V_218 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_217 | V_218 ) == 0 )
V_218 = 1 ;
if ( V_218 ) {
int V_22 ;
T_1 V_137 , V_219 ;
V_219 = F_119 ( & V_13 -> V_16 , V_218 ) ;
if ( V_25 -> V_147 && V_25 -> V_220 != V_219 ) {
V_137 = F_7 ( V_23 ) |
F_8 (
V_221 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_121 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_137 , & V_219 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_220 = V_219 ;
}
V_217 = V_217 == 0 ? 6 : F_118 ( & V_13 -> V_16 , V_217 ) ;
V_25 -> V_175 = F_122 ( V_217 ) | F_123 ( V_218 > 0 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , T_8 V_72 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_8 V_222 = V_2 -> V_72 ^ V_72 ;
int V_22 ;
if ( ! ( V_222 & V_73 ) )
return 0 ;
V_22 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_72 & V_73 ) , true ) ;
if ( F_51 ( V_22 ) )
V_2 -> V_72 = V_72 ^ V_73 ;
return V_22 ;
}
static int F_125 ( struct V_12 * V_13 )
{
if ( F_126 ( V_13 -> V_223 ) )
return - 1 ;
#ifdef F_127
F_128 ( V_13 ) ;
#endif
return 0 ;
}
int F_129 ( struct V_224 * V_185 , void * V_109 )
{
int V_225 = - 1 ;
F_130 ( & V_185 -> V_226 ) ;
if ( V_185 -> V_227 ) {
union V_228 * V_6 = V_185 -> V_227 ;
V_225 = ( V_6 - V_185 -> V_229 ) + V_185 -> V_230 ;
V_185 -> V_227 = V_6 -> V_231 ;
V_6 -> V_109 = V_109 ;
V_185 -> V_232 ++ ;
}
F_131 ( & V_185 -> V_226 ) ;
return V_225 ;
}
void F_132 ( struct V_224 * V_185 , unsigned int V_225 )
{
union V_228 * V_6 = & V_185 -> V_229 [ V_225 - V_185 -> V_230 ] ;
F_130 ( & V_185 -> V_226 ) ;
V_6 -> V_231 = V_185 -> V_227 ;
V_185 -> V_227 = V_6 ;
V_185 -> V_232 -- ;
F_131 ( & V_185 -> V_226 ) ;
}
int F_133 ( struct V_224 * V_185 , int V_233 , void * V_109 )
{
int V_234 ;
F_130 ( & V_185 -> V_235 ) ;
if ( V_233 == V_236 ) {
V_234 = F_134 ( V_185 -> V_237 , V_185 -> V_238 ) ;
if ( V_234 < V_185 -> V_238 )
F_135 ( V_234 , V_185 -> V_237 ) ;
else
V_234 = - 1 ;
} else {
V_234 = F_136 ( V_185 -> V_237 , V_185 -> V_238 , 1 ) ;
if ( V_234 < 0 )
V_234 = - 1 ;
}
if ( V_234 >= 0 ) {
V_185 -> V_239 [ V_234 ] . V_109 = V_109 ;
V_234 += V_185 -> V_240 ;
if ( V_233 == V_241 ) {
V_185 -> V_242 += 2 ;
V_185 -> V_243 += 2 ;
} else {
V_185 -> V_242 ++ ;
}
}
F_131 ( & V_185 -> V_235 ) ;
return V_234 ;
}
int F_137 ( struct V_224 * V_185 , int V_233 , void * V_109 )
{
int V_234 ;
F_130 ( & V_185 -> V_235 ) ;
if ( V_233 == V_236 ) {
V_234 = F_138 ( V_185 -> V_237 ,
V_185 -> V_238 + V_185 -> V_244 , V_185 -> V_238 ) ;
if ( V_234 < ( V_185 -> V_238 + V_185 -> V_244 ) )
F_135 ( V_234 , V_185 -> V_237 ) ;
else
V_234 = - 1 ;
} else {
V_234 = - 1 ;
}
if ( V_234 >= 0 ) {
V_185 -> V_239 [ V_234 ] . V_109 = V_109 ;
V_234 -= V_185 -> V_238 ;
V_234 += V_185 -> V_245 ;
V_185 -> V_246 ++ ;
}
F_131 ( & V_185 -> V_235 ) ;
return V_234 ;
}
void F_139 ( struct V_224 * V_185 , unsigned int V_234 , int V_233 )
{
if ( V_185 -> V_244 && ( V_234 >= V_185 -> V_245 ) ) {
V_234 -= V_185 -> V_245 ;
V_234 += V_185 -> V_238 ;
} else {
V_234 -= V_185 -> V_240 ;
}
F_130 ( & V_185 -> V_235 ) ;
if ( V_233 == V_236 )
F_140 ( V_234 , V_185 -> V_237 ) ;
else
F_141 ( V_185 -> V_237 , V_234 , 1 ) ;
V_185 -> V_239 [ V_234 ] . V_109 = NULL ;
if ( V_234 < V_185 -> V_238 ) {
if ( V_233 == V_241 ) {
V_185 -> V_242 -= 2 ;
V_185 -> V_243 -= 2 ;
} else {
V_185 -> V_242 -- ;
}
} else {
V_185 -> V_246 -- ;
}
F_131 ( & V_185 -> V_235 ) ;
}
static void F_142 ( struct V_198 * V_199 , unsigned int V_247 ,
unsigned int V_248 )
{
struct V_249 * V_250 ;
F_143 ( V_199 , V_251 , V_247 ) ;
V_250 = F_144 ( V_199 , sizeof( * V_250 ) ) ;
F_145 ( V_250 , V_248 ) ;
F_146 ( V_250 ) = F_147 ( F_148 ( V_252 , V_248 ) ) ;
}
static void F_149 ( struct V_224 * V_185 , unsigned int V_247 ,
unsigned int V_248 )
{
void * * V_6 = & V_185 -> V_253 [ V_248 ] ;
struct V_12 * V_13 = F_54 ( V_185 , struct V_12 , V_254 ) ;
F_130 ( & V_13 -> V_255 ) ;
* V_6 = V_13 -> V_256 ;
V_13 -> V_256 = ( void * * ) ( ( V_257 ) V_6 | V_247 ) ;
if ( ! V_13 -> V_258 ) {
V_13 -> V_258 = true ;
F_150 ( V_13 -> V_259 , & V_13 -> V_260 ) ;
}
F_131 ( & V_13 -> V_255 ) ;
}
static void F_151 ( struct V_261 * V_262 )
{
struct V_198 * V_199 ;
struct V_12 * V_13 ;
V_13 = F_54 ( V_262 , struct V_12 , V_260 ) ;
F_130 ( & V_13 -> V_255 ) ;
while ( V_13 -> V_256 ) {
void * * V_6 = V_13 -> V_256 ;
unsigned int V_247 = ( V_257 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_247 ;
V_13 -> V_256 = * V_6 ;
* V_6 = NULL ;
F_131 ( & V_13 -> V_255 ) ;
while ( ! ( V_199 = F_152 ( sizeof( struct V_249 ) ,
V_161 ) ) )
F_153 ( 1 ) ;
F_142 ( V_199 , V_247 , V_6 - V_13 -> V_254 . V_253 ) ;
F_154 ( V_13 , V_199 ) ;
F_130 ( & V_13 -> V_255 ) ;
}
V_13 -> V_258 = false ;
F_131 ( & V_13 -> V_255 ) ;
}
void F_155 ( struct V_224 * V_185 , unsigned int V_247 , unsigned int V_248 ,
unsigned short V_233 )
{
struct V_198 * V_199 ;
struct V_12 * V_13 = F_54 ( V_185 , struct V_12 , V_254 ) ;
F_156 ( V_248 >= V_185 -> V_263 ) ;
if ( V_185 -> V_253 [ V_248 ] ) {
V_185 -> V_253 [ V_248 ] = NULL ;
F_157 ( & V_185 -> V_264 ) ;
if ( V_185 -> V_265 && ( V_248 >= V_185 -> V_265 ) ) {
if ( V_233 == V_266 )
F_158 ( 2 , & V_185 -> V_267 ) ;
else
F_157 ( & V_185 -> V_267 ) ;
} else {
if ( V_233 == V_266 )
F_158 ( 2 , & V_185 -> V_268 ) ;
else
F_157 ( & V_185 -> V_268 ) ;
}
}
V_199 = F_152 ( sizeof( struct V_249 ) , V_60 ) ;
if ( F_52 ( V_199 ) ) {
F_142 ( V_199 , V_247 , V_248 ) ;
F_154 ( V_13 , V_199 ) ;
} else
F_149 ( V_185 , V_247 , V_248 ) ;
}
static int F_159 ( struct V_224 * V_185 )
{
struct V_12 * V_13 = F_54 ( V_185 , struct V_12 , V_254 ) ;
unsigned int V_269 = V_185 -> V_270 + V_185 -> V_244 ;
unsigned int V_271 = V_185 -> V_271 ;
unsigned int V_272 ;
unsigned int V_273 ;
T_9 V_274 ;
V_272 = F_160 ( V_185 -> V_238 + V_185 -> V_244 ) ;
V_273 = F_160 ( V_185 -> V_270 ) ;
V_274 = V_185 -> V_263 * sizeof( * V_185 -> V_253 ) +
V_271 * sizeof( * V_185 -> V_229 ) +
V_185 -> V_238 * sizeof( * V_185 -> V_239 ) +
V_185 -> V_244 * sizeof( * V_185 -> V_239 ) +
V_272 * sizeof( long ) +
V_269 * sizeof( * V_185 -> V_275 ) +
V_273 * sizeof( long ) ;
V_185 -> V_253 = F_161 ( V_274 , V_161 ) ;
if ( ! V_185 -> V_253 )
return - V_61 ;
V_185 -> V_229 = (union V_228 * ) & V_185 -> V_253 [ V_185 -> V_263 ] ;
V_185 -> V_239 = (struct V_276 * ) & V_185 -> V_229 [ V_271 ] ;
V_185 -> V_237 = ( unsigned long * ) & V_185 -> V_239 [ V_185 -> V_238 + V_185 -> V_244 ] ;
V_185 -> V_275 = (struct V_277 * ) & V_185 -> V_237 [ V_272 ] ;
V_185 -> V_278 = ( unsigned long * ) & V_185 -> V_275 [ V_269 ] ;
F_162 ( & V_185 -> V_235 ) ;
F_162 ( & V_185 -> V_226 ) ;
F_162 ( & V_185 -> V_279 ) ;
V_185 -> V_242 = 0 ;
V_185 -> V_243 = 0 ;
V_185 -> V_246 = 0 ;
V_185 -> V_227 = NULL ;
V_185 -> V_232 = 0 ;
F_163 ( & V_185 -> V_268 , 0 ) ;
F_163 ( & V_185 -> V_264 , 0 ) ;
F_163 ( & V_185 -> V_267 , 0 ) ;
if ( V_271 ) {
while ( -- V_271 )
V_185 -> V_229 [ V_271 - 1 ] . V_231 = & V_185 -> V_229 [ V_271 ] ;
V_185 -> V_227 = V_185 -> V_229 ;
}
if ( F_164 ( V_13 ) ) {
F_96 ( V_185 -> V_237 , V_185 -> V_238 + V_185 -> V_244 ) ;
if ( ! V_185 -> V_240 &&
F_165 ( V_13 -> V_193 . V_194 ) <= V_280 )
F_135 ( 0 , V_185 -> V_237 ) ;
}
F_96 ( V_185 -> V_278 , V_185 -> V_270 ) ;
return 0 ;
}
int F_166 ( const struct V_1 * V_2 , unsigned int V_234 ,
T_10 V_281 , T_11 V_282 , T_11 V_283 ,
unsigned int V_284 )
{
unsigned int V_247 ;
struct V_198 * V_199 ;
struct V_12 * V_13 ;
struct V_285 * V_250 ;
int V_54 ;
V_199 = F_152 ( sizeof( * V_250 ) , V_161 ) ;
if ( ! V_199 )
return - V_61 ;
V_13 = F_167 ( V_2 ) ;
V_250 = F_144 ( V_199 , sizeof( * V_250 ) ) ;
F_145 ( V_250 , 0 ) ;
F_146 ( V_250 ) = F_147 ( F_148 ( V_286 , V_234 ) ) ;
V_250 -> V_287 = V_282 ;
V_250 -> V_288 = F_114 ( 0 ) ;
V_250 -> V_289 = V_281 ;
V_250 -> V_290 = F_147 ( 0 ) ;
V_247 = F_85 ( & V_13 -> V_16 , V_284 ) ;
V_250 -> V_291 = F_168 ( F_169 ( V_247 ) ) ;
V_250 -> V_292 = F_168 ( F_170 ( V_293 ) |
V_294 | F_171 ( V_284 ) ) ;
V_54 = F_172 ( V_13 , V_199 ) ;
return F_173 ( V_54 ) ;
}
int F_174 ( const struct V_1 * V_2 , unsigned int V_234 ,
const struct V_295 * V_281 , T_11 V_282 ,
unsigned int V_284 )
{
unsigned int V_247 ;
struct V_198 * V_199 ;
struct V_12 * V_13 ;
struct V_296 * V_250 ;
int V_54 ;
V_199 = F_152 ( sizeof( * V_250 ) , V_161 ) ;
if ( ! V_199 )
return - V_61 ;
V_13 = F_167 ( V_2 ) ;
V_250 = F_144 ( V_199 , sizeof( * V_250 ) ) ;
F_145 ( V_250 , 0 ) ;
F_146 ( V_250 ) = F_147 ( F_148 ( V_297 , V_234 ) ) ;
V_250 -> V_287 = V_282 ;
V_250 -> V_288 = F_114 ( 0 ) ;
V_250 -> V_298 = * ( T_4 * ) ( V_281 -> V_299 ) ;
V_250 -> V_300 = * ( T_4 * ) ( V_281 -> V_299 + 8 ) ;
V_250 -> V_301 = F_168 ( 0 ) ;
V_250 -> V_302 = F_168 ( 0 ) ;
V_247 = F_85 ( & V_13 -> V_16 , V_284 ) ;
V_250 -> V_291 = F_168 ( F_169 ( V_247 ) ) ;
V_250 -> V_292 = F_168 ( F_170 ( V_293 ) |
V_294 | F_171 ( V_284 ) ) ;
V_54 = F_172 ( V_13 , V_199 ) ;
return F_173 ( V_54 ) ;
}
int F_175 ( const struct V_1 * V_2 , unsigned int V_234 ,
unsigned int V_284 , bool V_303 )
{
struct V_198 * V_199 ;
struct V_12 * V_13 ;
struct V_304 * V_250 ;
int V_54 ;
V_13 = F_167 ( V_2 ) ;
V_199 = F_152 ( sizeof( * V_250 ) , V_161 ) ;
if ( ! V_199 )
return - V_61 ;
V_250 = F_144 ( V_199 , sizeof( * V_250 ) ) ;
F_145 ( V_250 , 0 ) ;
F_146 ( V_250 ) = F_147 ( F_148 ( V_305 , V_234 ) ) ;
V_250 -> V_306 = F_114 ( F_176 ( 0 ) | ( V_303 ? F_177 ( 1 ) :
F_177 ( 0 ) ) | F_178 ( V_284 ) ) ;
V_54 = F_172 ( V_13 , V_199 ) ;
return F_173 ( V_54 ) ;
}
unsigned int F_179 ( const unsigned short * V_307 , unsigned short V_66 ,
unsigned int * V_189 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_308 - 1 && V_307 [ V_19 + 1 ] <= V_66 )
++ V_19 ;
if ( V_189 )
* V_189 = V_19 ;
return V_307 [ V_19 ] ;
}
unsigned int F_180 ( const unsigned short * V_307 ,
unsigned short V_309 ,
unsigned short V_310 ,
unsigned short V_311 ,
unsigned int * V_312 )
{
unsigned short V_313 = V_309 + V_310 ;
unsigned short V_314 = V_311 - 1 ;
int V_315 , V_316 ;
for ( V_315 = 0 , V_316 = - 1 ; V_315 < V_308 ; V_315 ++ ) {
unsigned short V_317 = V_307 [ V_315 ] - V_309 ;
if ( ( V_317 & V_314 ) == 0 )
V_316 = V_315 ;
if ( V_315 + 1 < V_308 && V_307 [ V_315 + 1 ] > V_313 )
break;
}
if ( V_315 == V_308 )
V_315 -- ;
if ( V_316 >= 0 &&
V_315 - V_316 <= 1 )
V_315 = V_316 ;
if ( V_312 )
* V_312 = V_315 ;
return V_307 [ V_315 ] ;
}
unsigned int F_181 ( enum V_318 V_194 , unsigned int V_51 )
{
if ( F_165 ( V_194 ) <= V_280 )
return ( ( V_51 & 0x7f ) << 1 ) ;
else
return ( V_51 & 0x7f ) ;
}
unsigned int F_182 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_76 ;
}
unsigned int F_183 ( const struct V_1 * V_2 , int V_319 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
T_1 V_320 , V_321 , V_322 , V_323 ;
V_320 = F_68 ( V_13 , V_324 ) ;
V_321 = F_68 ( V_13 , V_325 ) ;
if ( F_105 ( V_13 -> V_193 . V_194 ) ) {
V_322 = F_184 ( V_320 ) ;
V_323 = F_185 ( V_320 ) ;
} else {
V_322 = F_186 ( V_320 ) ;
V_323 = F_187 ( V_321 ) ;
}
return V_319 ? V_322 : V_323 ;
}
unsigned int F_188 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_51 ;
}
unsigned int F_189 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_31 ;
}
void F_190 ( struct V_326 * V_133 , struct V_327 * V_328 ,
struct V_327 * V_329 )
{
struct V_12 * V_13 = F_191 ( V_133 ) ;
F_192 ( & V_13 -> V_330 ) ;
F_193 ( V_13 , V_328 , V_329 ) ;
F_194 ( & V_13 -> V_330 ) ;
}
void F_195 ( struct V_1 * V_2 , unsigned int V_331 ,
const unsigned int * V_332 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
F_70 ( V_13 , V_333 , V_331 ) ;
F_70 ( V_13 , V_334 , F_196 ( V_332 [ 0 ] ) |
F_197 ( V_332 [ 1 ] ) | F_198 ( V_332 [ 2 ] ) |
F_199 ( V_332 [ 3 ] ) ) ;
}
int F_200 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
return F_201 ( V_13 , V_13 -> V_27 ) ;
}
static int F_202 ( struct V_12 * V_13 , T_6 V_95 , T_6 * V_335 , T_6 * V_336 )
{
T_1 V_50 = F_68 ( V_13 , V_337 ) + 24 * V_95 + 8 ;
T_4 V_338 ;
int V_54 ;
F_192 ( & V_13 -> V_339 ) ;
V_54 = F_203 ( V_13 , 0 , V_340 , V_50 ,
sizeof( V_338 ) , ( T_10 * ) & V_338 ,
V_341 ) ;
F_194 ( & V_13 -> V_339 ) ;
if ( ! V_54 ) {
* V_336 = ( F_204 ( V_338 ) >> 25 ) & 0xffff ;
* V_335 = ( F_204 ( V_338 ) >> 9 ) & 0xffff ;
}
return V_54 ;
}
int F_205 ( struct V_1 * V_2 , T_6 V_95 , T_6 V_335 ,
T_6 V_274 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
T_6 V_342 , V_343 ;
int V_54 ;
V_54 = F_202 ( V_13 , V_95 , & V_342 , & V_343 ) ;
if ( V_54 )
goto V_59;
if ( V_335 != V_342 ) {
T_6 V_210 ;
T_1 V_344 ;
if ( V_335 >= V_342 )
V_210 = V_335 - V_342 ;
else
V_210 = V_274 - V_342 + V_335 ;
if ( F_105 ( V_13 -> V_193 . V_194 ) )
V_344 = F_206 ( V_210 ) ;
else
V_344 = F_207 ( V_210 ) ;
F_208 () ;
F_70 ( V_13 , F_69 ( V_345 ) ,
F_209 ( V_95 ) | V_344 ) ;
}
V_59:
return V_54 ;
}
int F_210 ( struct V_1 * V_2 , T_1 V_346 , T_10 * V_347 )
{
struct V_12 * V_13 ;
T_1 V_348 , V_349 , V_350 ;
T_1 V_351 , V_352 , V_353 , V_354 , V_274 ;
T_1 V_355 , V_356 , V_357 , V_358 ;
int V_54 ;
V_13 = F_167 ( V_2 ) ;
V_348 = ( ( V_346 >> 8 ) * 32 ) + V_13 -> V_359 . V_346 . V_360 ;
V_274 = F_68 ( V_13 , V_361 ) ;
V_351 = F_211 ( V_274 ) << 20 ;
V_274 = F_68 ( V_13 , V_362 ) ;
V_352 = F_212 ( V_274 ) << 20 ;
V_274 = F_68 ( V_13 , V_363 ) ;
V_353 = F_213 ( V_274 ) << 20 ;
V_355 = V_351 ;
V_356 = V_355 + V_352 ;
V_357 = V_356 + V_353 ;
if ( V_348 < V_355 ) {
V_349 = V_340 ;
V_350 = V_348 ;
} else if ( V_348 < V_356 ) {
V_349 = V_364 ;
V_350 = V_348 - V_355 ;
} else {
if ( V_348 < V_357 ) {
V_349 = V_365 ;
V_350 = V_348 - V_356 ;
} else if ( F_214 ( V_13 -> V_193 . V_194 ) ) {
V_274 = F_68 ( V_13 , V_366 ) ;
V_354 = F_215 ( V_274 ) << 20 ;
V_358 = V_357 + V_354 ;
if ( V_348 < V_358 ) {
V_349 = V_367 ;
V_350 = V_348 - V_357 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_192 ( & V_13 -> V_339 ) ;
V_54 = F_203 ( V_13 , 0 , V_349 , V_350 , 32 , V_347 , V_341 ) ;
F_194 ( & V_13 -> V_339 ) ;
return V_54 ;
V_22:
F_11 ( V_13 -> V_30 , L_35 ,
V_346 , V_348 ) ;
return - V_65 ;
}
T_2 F_216 ( struct V_1 * V_2 )
{
T_1 V_368 , V_369 ;
struct V_12 * V_13 ;
V_13 = F_167 ( V_2 ) ;
V_369 = F_68 ( V_13 , V_370 ) ;
V_368 = F_217 ( F_68 ( V_13 , V_371 ) ) ;
return ( ( T_2 ) V_368 << 32 ) | ( T_2 ) V_369 ;
}
int F_218 ( struct V_1 * V_2 ,
unsigned int V_95 ,
enum V_372 V_373 ,
int V_374 ,
T_2 * V_375 ,
unsigned int * V_376 )
{
return F_219 ( F_167 ( V_2 ) ,
V_95 ,
( V_373 == V_377
? V_378
: V_379 ) ,
V_374 ,
V_375 ,
V_376 ) ;
}
static void F_220 ( struct V_380 * V_381 )
{
const struct V_382 * V_383 ;
const struct V_1 * V_52 = V_381 -> V_2 ;
if ( F_221 ( V_52 ) )
V_52 = F_222 ( V_52 ) ;
V_383 = V_52 -> V_2 . V_383 ;
if ( V_383 && V_383 -> V_384 == & V_385 . V_384 )
F_223 ( F_224 ( V_383 ) , V_381 ) ;
}
static int F_225 ( struct V_386 * V_387 , unsigned long V_388 ,
void * V_109 )
{
switch ( V_388 ) {
case V_389 :
F_220 ( V_109 ) ;
break;
case V_390 :
default:
break;
}
return 0 ;
}
static void F_226 ( struct V_12 * V_13 , int V_391 )
{
T_1 V_320 , V_321 , V_322 , V_323 ;
do {
V_320 = F_68 ( V_13 , V_324 ) ;
V_321 = F_68 ( V_13 , V_325 ) ;
if ( F_105 ( V_13 -> V_193 . V_194 ) ) {
V_322 = F_184 ( V_320 ) ;
V_323 = F_185 ( V_320 ) ;
} else {
V_322 = F_186 ( V_320 ) ;
V_323 = F_187 ( V_321 ) ;
}
if ( V_322 == 0 && V_323 == 0 )
break;
F_227 ( V_392 ) ;
F_228 ( F_229 ( V_391 ) ) ;
} while ( 1 );
}
static void F_230 ( struct V_97 * V_25 )
{
unsigned long V_68 ;
F_231 ( & V_25 -> V_393 , V_68 ) ;
V_25 -> V_394 = 1 ;
F_232 ( & V_25 -> V_393 , V_68 ) ;
}
static void F_233 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
F_234 ( & V_25 -> V_393 ) ;
if ( V_25 -> V_395 ) {
F_208 () ;
F_70 ( V_13 , F_69 ( V_345 ) ,
F_209 ( V_25 -> V_26 ) | F_206 ( V_25 -> V_395 ) ) ;
V_25 -> V_395 = 0 ;
}
V_25 -> V_394 = 0 ;
F_235 ( & V_25 -> V_393 ) ;
}
static void F_236 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_230 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_396 * V_397 =
V_13 -> V_16 . V_398 [ V_399 ] ;
if ( V_397 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_397 -> V_400 [ V_19 ] ;
F_230 ( & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_230 ( & V_13 -> V_16 . V_192 [ V_19 ] . V_25 ) ;
}
static void F_238 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_233 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_396 * V_397 =
V_13 -> V_16 . V_398 [ V_399 ] ;
if ( V_397 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_397 -> V_400 [ V_19 ] ;
F_233 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_233 ( V_13 , & V_13 -> V_16 . V_192 [ V_19 ] . V_25 ) ;
}
static void F_239 ( struct V_12 * V_13 , enum V_401 V_110 )
{
enum V_402 type = V_184 ;
if ( V_13 -> V_403 && V_13 -> V_403 [ type ] . V_404 )
V_13 -> V_403 [ type ] . F_240 ( V_13 -> V_403 [ type ] . V_404 , V_110 ) ;
}
static void F_241 ( struct V_261 * V_262 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_262 , struct V_12 , V_405 ) ;
F_226 ( V_13 , V_406 ) ;
F_238 ( V_13 ) ;
F_239 ( V_13 , V_407 ) ;
if ( F_165 ( V_13 -> V_193 . V_194 ) <= V_280 )
F_242 ( V_13 , V_408 ,
V_409 | V_410 ,
V_409 | V_410 ) ;
else
F_242 ( V_13 , V_408 ,
V_410 , V_410 ) ;
}
static void F_243 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
T_6 V_342 , V_343 ;
int V_54 ;
F_234 ( & V_25 -> V_393 ) ;
V_54 = F_202 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_342 , & V_343 ) ;
if ( V_54 )
goto V_59;
if ( V_25 -> V_411 != V_342 ) {
T_6 V_210 ;
T_1 V_344 ;
if ( V_25 -> V_411 >= V_342 )
V_210 = V_25 -> V_411 - V_342 ;
else
V_210 = V_25 -> V_274 - V_342 + V_25 -> V_411 ;
if ( F_105 ( V_13 -> V_193 . V_194 ) )
V_344 = F_206 ( V_210 ) ;
else
V_344 = F_207 ( V_210 ) ;
F_208 () ;
F_70 ( V_13 , F_69 ( V_345 ) ,
F_209 ( V_25 -> V_26 ) | V_344 ) ;
}
V_59:
V_25 -> V_394 = 0 ;
V_25 -> V_395 = 0 ;
F_235 ( & V_25 -> V_393 ) ;
if ( V_54 )
F_244 ( V_13 , L_36 ) ;
}
static void F_245 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_243 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_396 * V_397 =
V_13 -> V_16 . V_398 [ V_399 ] ;
if ( V_397 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_397 -> V_400 [ V_19 ] ;
F_243 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_243 ( V_13 , & V_13 -> V_16 . V_192 [ V_19 ] . V_25 ) ;
}
static void F_246 ( struct V_261 * V_262 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_262 , struct V_12 , V_412 ) ;
if ( F_105 ( V_13 -> V_193 . V_194 ) ) {
F_226 ( V_13 , V_406 ) ;
F_239 ( V_13 , V_413 ) ;
F_226 ( V_13 , V_406 ) ;
F_245 ( V_13 ) ;
F_226 ( V_13 , V_406 ) ;
F_238 ( V_13 ) ;
F_239 ( V_13 , V_407 ) ;
} else if ( F_214 ( V_13 -> V_193 . V_194 ) ) {
T_1 V_414 = F_68 ( V_13 , 0x010ac ) ;
T_6 V_95 = ( V_414 >> 15 ) & 0x1ffff ;
T_6 V_415 = V_414 & 0x1fff ;
T_2 V_416 ;
unsigned int V_417 ;
int V_54 ;
V_54 = F_219 ( V_13 , V_95 , V_378 ,
0 , & V_416 , & V_417 ) ;
if ( V_54 )
F_11 ( V_13 -> V_30 , L_37
L_38 , V_95 , V_415 ) ;
else
F_247 ( F_207 ( V_415 ) | F_209 ( V_417 ) ,
V_13 -> V_418 + V_416 + V_419 ) ;
F_242 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_165 ( V_13 -> V_193 . V_194 ) <= V_280 )
F_242 ( V_13 , V_420 , V_421 , 0 ) ;
}
void F_248 ( struct V_12 * V_13 )
{
if ( F_105 ( V_13 -> V_193 . V_194 ) ) {
F_236 ( V_13 ) ;
F_239 ( V_13 , V_422 ) ;
F_242 ( V_13 , V_408 ,
V_409 | V_410 , 0 ) ;
F_150 ( V_13 -> V_259 , & V_13 -> V_405 ) ;
}
}
void F_249 ( struct V_12 * V_13 )
{
if ( F_105 ( V_13 -> V_193 . V_194 ) ) {
F_236 ( V_13 ) ;
F_239 ( V_13 , V_422 ) ;
}
F_150 ( V_13 -> V_259 , & V_13 -> V_412 ) ;
}
void F_250 ( void )
{
if ( ! V_423 ) {
F_251 ( & V_424 ) ;
V_423 = true ;
}
}
static void F_252 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_253 ( & V_425 ) ;
F_33 ( & V_13 -> V_426 ) ;
for ( V_19 = 0 ; V_19 < V_427 ; V_19 ++ )
if ( V_13 -> V_403 && V_13 -> V_403 [ V_19 ] . V_404 )
V_13 -> V_403 [ V_19 ] . F_254 ( V_13 -> V_403 [ V_19 ] . V_404 ,
V_428 ) ;
if ( V_423 && F_255 ( & V_429 ) ) {
F_256 ( & V_424 ) ;
V_423 = false ;
}
F_257 ( & V_425 ) ;
}
static void F_258 ( struct V_12 * V_13 , enum V_430 V_431 )
{
unsigned int V_19 ;
F_253 ( & V_425 ) ;
for ( V_19 = 0 ; V_19 < V_427 ; V_19 ++ )
if ( V_13 -> V_403 && V_13 -> V_403 [ V_19 ] . V_404 )
V_13 -> V_403 [ V_19 ] . F_254 ( V_13 -> V_403 [ V_19 ] . V_404 ,
V_431 ) ;
F_257 ( & V_425 ) ;
}
static int F_259 ( struct V_386 * V_432 ,
unsigned long V_388 , void * V_109 )
{
struct V_433 * V_434 = V_109 ;
struct V_1 * V_435 = V_434 -> V_436 -> V_2 ;
const struct V_382 * V_383 = NULL ;
#if F_260 ( V_437 )
struct V_12 * V_13 ;
#endif
if ( F_221 ( V_435 ) )
V_435 = F_222 ( V_435 ) ;
#if F_260 ( V_437 )
if ( V_435 -> V_68 & V_438 ) {
F_22 (adap, &adapter_list, list_node) {
switch ( V_388 ) {
case V_439 :
F_261 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_434 , 1 ) ;
break;
case V_440 :
F_262 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_434 , 1 ) ;
break;
default:
break;
}
}
return V_441 ;
}
#endif
if ( V_435 )
V_383 = V_435 -> V_2 . V_383 ;
if ( V_383 && V_383 -> V_384 == & V_385 . V_384 ) {
switch ( V_388 ) {
case V_439 :
F_261 ( V_435 , ( const T_1 * ) V_434 , 1 ) ;
break;
case V_440 :
F_262 ( V_435 , ( const T_1 * ) V_434 , 1 ) ;
break;
default:
break;
}
}
return V_441 ;
}
static void F_263 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_54 ;
F_264 () ;
for ( V_19 = 0 ; V_19 < V_442 ; V_19 ++ ) {
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
F_253 ( & V_425 ) ;
V_22 = F_99 ( V_13 ) ;
if ( V_22 )
goto V_443;
V_22 = F_83 ( V_13 ) ;
if ( V_22 )
goto V_444;
if ( V_13 -> V_68 & V_132 ) {
F_72 ( V_13 ) ;
V_22 = F_75 ( V_13 -> V_146 [ 0 ] . V_46 , F_67 , 0 ,
V_13 -> V_146 [ 0 ] . V_147 , V_13 ) ;
if ( V_22 )
goto V_445;
V_22 = F_74 ( V_13 ) ;
if ( V_22 ) {
F_77 ( V_13 -> V_146 [ 0 ] . V_46 , V_13 ) ;
goto V_445;
}
} else {
V_22 = F_75 ( V_13 -> V_133 -> V_135 , F_268 ( V_13 ) ,
( V_13 -> V_68 & V_134 ) ? 0 : V_446 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_445;
}
F_91 ( V_13 ) ;
F_269 ( V_13 ) ;
F_270 ( V_13 ) ;
V_13 -> V_68 |= V_173 ;
F_257 ( & V_425 ) ;
F_258 ( V_13 , V_447 ) ;
#if F_260 ( V_448 )
F_263 ( V_13 ) ;
#endif
F_271 ( & V_13 -> V_63 ) ;
return V_22 ;
V_445:
F_11 ( V_13 -> V_30 , L_39 , V_22 ) ;
V_444:
F_98 ( V_13 ) ;
V_443:
F_257 ( & V_425 ) ;
return V_22 ;
}
static void F_272 ( struct V_12 * V_12 )
{
F_273 ( & V_12 -> V_260 ) ;
F_273 ( & V_12 -> V_405 ) ;
F_273 ( & V_12 -> V_412 ) ;
V_12 -> V_258 = false ;
V_12 -> V_256 = NULL ;
F_274 ( V_12 ) ;
F_98 ( V_12 ) ;
V_12 -> V_68 &= ~ V_173 ;
}
static int F_275 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_18 ( V_2 ) ;
if ( ! ( V_12 -> V_68 & V_173 ) ) {
V_22 = F_267 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_276 ( V_11 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
F_277 ( V_2 ) ;
return V_22 ;
}
static int F_278 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_279 ( V_2 ) ;
F_18 ( V_2 ) ;
return F_280 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , false , false ) ;
}
int F_281 ( const struct V_1 * V_2 , unsigned int V_234 ,
T_10 V_281 , T_11 V_282 , T_11 V_283 ,
unsigned int V_284 , unsigned char V_39 , unsigned char V_449 )
{
int V_54 ;
struct V_277 * V_450 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_344 ;
V_13 = F_167 ( V_2 ) ;
V_234 -= V_13 -> V_254 . V_245 ;
V_234 += V_13 -> V_254 . V_270 ;
V_450 = & V_13 -> V_254 . V_275 [ V_234 ] ;
V_54 = F_282 ( V_450 ) ;
if ( V_54 )
return V_54 ;
if ( V_450 -> V_451 )
F_283 ( V_13 , V_450 ) ;
memset ( & V_450 -> V_452 , 0 , sizeof( struct V_453 ) ) ;
V_450 -> V_452 . V_344 . V_454 = F_284 ( V_282 ) ;
V_450 -> V_452 . V_449 . V_454 = ~ 0 ;
V_344 = ( T_3 * ) & V_281 ;
if ( ( V_344 [ 0 ] | V_344 [ 1 ] | V_344 [ 2 ] | V_344 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_450 -> V_452 . V_344 . V_455 [ V_19 ] = V_344 [ V_19 ] ;
V_450 -> V_452 . V_449 . V_455 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_193 . V_456 . V_457 & V_458 ) {
V_450 -> V_452 . V_344 . V_459 = V_39 ;
V_450 -> V_452 . V_449 . V_459 = V_449 ;
}
}
if ( V_13 -> V_193 . V_456 . V_457 & V_460 ) {
V_450 -> V_452 . V_344 . V_461 = V_462 ;
V_450 -> V_452 . V_449 . V_461 = ~ 0 ;
}
V_450 -> V_452 . V_463 = 1 ;
V_450 -> V_452 . V_464 = V_284 ;
V_450 -> V_465 = 1 ;
V_450 -> V_452 . V_466 = 1 ;
V_450 -> V_248 = V_234 + V_13 -> V_254 . V_467 ;
V_54 = F_285 ( V_13 , V_234 ) ;
if ( V_54 ) {
F_283 ( V_13 , V_450 ) ;
return V_54 ;
}
return 0 ;
}
int F_286 ( const struct V_1 * V_2 , unsigned int V_234 ,
unsigned int V_284 , bool V_303 )
{
struct V_277 * V_450 ;
struct V_12 * V_13 ;
V_13 = F_167 ( V_2 ) ;
V_234 -= V_13 -> V_254 . V_245 ;
V_234 += V_13 -> V_254 . V_270 ;
V_450 = & V_13 -> V_254 . V_275 [ V_234 ] ;
V_450 -> V_465 = 0 ;
return F_287 ( V_13 , V_234 ) ;
}
static void F_288 ( struct V_1 * V_2 ,
struct V_468 * V_469 )
{
struct V_470 V_190 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_192 ( & V_12 -> V_330 ) ;
if ( ! F_289 ( V_2 ) ) {
F_194 ( & V_12 -> V_330 ) ;
return;
}
F_290 ( V_12 , V_6 -> V_76 , & V_190 ,
& V_6 -> V_471 ) ;
F_194 ( & V_12 -> V_330 ) ;
V_469 -> V_472 = V_190 . V_473 ;
V_469 -> V_474 = V_190 . V_475 ;
V_469 -> V_476 = V_190 . V_477 ;
V_469 -> V_478 = V_190 . V_479 ;
V_469 -> V_480 = V_190 . V_481 ;
V_469 -> V_482 = V_190 . V_483 + V_190 . V_484 +
V_190 . V_485 ;
V_469 -> V_486 = 0 ;
V_469 -> V_487 = V_190 . V_488 ;
V_469 -> V_489 = V_190 . V_490 ;
V_469 -> V_491 = V_190 . V_492 + V_190 . V_493 +
V_190 . V_494 + V_190 . V_495 +
V_190 . V_496 + V_190 . V_497 +
V_190 . V_498 + V_190 . V_499 ;
V_469 -> V_500 = 0 ;
V_469 -> V_501 = 0 ;
V_469 -> V_502 = 0 ;
V_469 -> V_503 = 0 ;
V_469 -> V_504 = 0 ;
V_469 -> V_505 = 0 ;
V_469 -> V_506 = V_190 . V_507 ;
V_469 -> V_508 = V_190 . V_490 + V_190 . V_488 +
V_469 -> V_482 + V_190 . V_509 + V_469 -> V_510 ;
}
static int F_291 ( struct V_1 * V_2 , struct V_511 * V_250 , int V_110 )
{
unsigned int V_27 ;
int V_54 = 0 , V_512 , V_513 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
struct V_514 * V_109 = (struct V_514 * ) & V_250 -> V_515 ;
switch ( V_110 ) {
case V_516 :
if ( V_11 -> V_517 < 0 )
return - V_518 ;
V_109 -> V_519 = V_11 -> V_517 ;
break;
case V_520 :
case V_521 :
if ( F_292 ( V_109 -> V_519 ) ) {
V_512 = F_293 ( V_109 -> V_519 ) ;
V_513 = F_294 ( V_109 -> V_519 ) ;
} else if ( V_109 -> V_519 < 32 ) {
V_512 = V_109 -> V_519 ;
V_513 = 0 ;
V_109 -> V_522 &= 0x1f ;
} else
return - V_65 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_110 == V_520 )
V_54 = F_295 ( V_11 -> V_12 , V_27 , V_512 , V_513 ,
V_109 -> V_522 , & V_109 -> V_523 ) ;
else
V_54 = F_296 ( V_11 -> V_12 , V_27 , V_512 , V_513 ,
V_109 -> V_522 , V_109 -> V_524 ) ;
break;
case V_525 :
return F_297 ( V_250 -> V_515 , & V_11 -> V_526 ,
sizeof( V_11 -> V_526 ) ) ?
- V_527 : 0 ;
case V_528 :
if ( F_298 ( & V_11 -> V_526 , V_250 -> V_515 ,
sizeof( V_11 -> V_526 ) ) )
return - V_527 ;
if ( ! F_105 ( V_12 -> V_193 . V_194 ) ) {
switch ( V_11 -> V_526 . V_529 ) {
case V_530 :
case V_531 :
break;
default:
return - V_532 ;
}
switch ( V_11 -> V_526 . V_533 ) {
case V_534 :
V_11 -> V_535 = false ;
break;
case V_536 :
case V_537 :
F_299 ( V_11 , V_11 -> V_31 ,
V_538 ) ;
break;
case V_539 :
F_299 ( V_11 , V_11 -> V_31 ,
V_540 ) ;
break;
case V_541 :
case V_542 :
case V_543 :
case V_544 :
case V_545 :
V_11 -> V_535 = true ;
break;
default:
V_11 -> V_526 . V_533 =
V_534 ;
return - V_532 ;
}
if ( ( V_11 -> V_526 . V_529 == V_530 ) &&
( V_11 -> V_526 . V_533 ==
V_534 ) ) {
if ( F_300 ( V_12 , V_11 -> V_31 ) >= 0 )
V_11 -> V_546 = false ;
}
if ( V_11 -> V_526 . V_533 !=
V_534 ) {
if ( F_301 ( V_12 ,
V_11 ) >= 0 )
V_11 -> V_546 = true ;
}
} else {
switch ( V_11 -> V_526 . V_533 ) {
case V_534 :
V_11 -> V_535 = false ;
break;
case V_541 :
V_11 -> V_535 = true ;
break;
default:
V_11 -> V_526 . V_533 =
V_534 ;
return - V_532 ;
}
}
return F_297 ( V_250 -> V_515 , & V_11 -> V_526 ,
sizeof( V_11 -> V_526 ) ) ?
- V_527 : 0 ;
default:
return - V_518 ;
}
return V_54 ;
}
static void F_302 ( struct V_1 * V_2 )
{
F_36 ( V_2 , - 1 , false ) ;
}
static int F_303 ( struct V_1 * V_2 , int V_547 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
V_54 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , V_547 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_54 )
V_2 -> V_66 = V_547 ;
return V_54 ;
}
static int F_304 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
return 0 ;
}
static void F_305 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
T_3 V_548 [ V_549 ] , V_550 [ V_549 ] ;
int V_22 ;
T_3 * V_551 ;
T_6 V_552 , V_553 ;
V_22 = F_306 ( V_13 , & V_13 -> V_193 . V_554 ) ;
if ( ! V_22 ) {
V_551 = V_13 -> V_193 . V_554 . V_551 ;
for ( V_19 = 0 ; V_19 < V_549 ; V_19 ++ )
V_548 [ V_19 ] = ( F_307 ( V_551 [ 2 * V_19 + 0 ] ) * 16 +
F_307 ( V_551 [ 2 * V_19 + 1 ] ) ) ;
V_552 = ( V_548 [ 0 ] << 8 ) | V_548 [ 1 ] ;
V_553 = ( V_548 [ 1 ] << 8 ) | V_548 [ 2 ] ;
V_552 ^= V_553 ;
V_552 |= 0x0200 ;
V_552 &= ~ 0x0100 ;
V_550 [ 0 ] = V_552 >> 8 ;
V_550 [ 1 ] = V_552 & 0xff ;
for ( V_19 = 2 ; V_19 < 5 ; V_19 ++ )
V_550 [ V_19 ] = V_548 [ V_19 + 1 ] ;
for ( V_19 = 0 ; V_19 < V_13 -> V_555 ; V_19 ++ ) {
V_550 [ 5 ] = V_13 -> V_28 * 16 + V_19 ;
F_28 ( V_13 -> V_556 [ V_19 ] . V_557 , V_550 ) ;
}
}
}
static int F_308 ( struct V_1 * V_2 , int V_558 , T_3 * V_559 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
if ( ! F_309 ( V_559 ) ) {
F_11 ( V_11 -> V_12 -> V_30 ,
L_40 ,
V_559 , V_558 ) ;
return - V_65 ;
}
F_310 ( V_11 -> V_12 -> V_30 ,
L_41 , V_559 , V_558 ) ;
V_54 = F_311 ( V_13 , V_558 + 1 , 1 , V_559 ) ;
if ( ! V_54 )
F_28 ( V_13 -> V_556 [ V_558 ] . V_557 , V_559 ) ;
return V_54 ;
}
static int F_312 ( struct V_1 * V_2 ,
int V_558 , struct V_560 * V_561 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_558 >= V_13 -> V_555 )
return - V_65 ;
V_561 -> V_558 = V_558 ;
V_561 -> V_562 = V_13 -> V_556 [ V_558 ] . V_563 ;
V_561 -> V_564 = 0 ;
F_28 ( V_561 -> V_559 , V_13 -> V_556 [ V_558 ] . V_557 ) ;
return 0 ;
}
static int F_313 ( struct V_1 * V_2 ,
struct V_565 * V_566 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_567 ;
V_567 = V_11 -> V_12 -> V_568 * 10 + V_11 -> V_31 ;
V_566 -> V_569 = sizeof( V_567 ) ;
memcpy ( V_566 -> V_570 , & V_567 , V_566 -> V_569 ) ;
return 0 ;
}
static int F_314 ( struct V_1 * V_2 , int V_558 , int V_564 ,
int V_562 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
unsigned int V_571 , V_8 , V_66 ;
T_1 V_572 , V_573 ;
int V_574 = V_558 ;
int V_54 ;
T_6 V_575 ;
if ( V_558 >= V_13 -> V_555 )
return - V_65 ;
if ( V_564 ) {
F_11 ( V_13 -> V_30 ,
L_42 ,
V_564 , V_558 ) ;
return - V_65 ;
}
V_54 = F_315 ( V_11 , & V_571 , & V_8 , & V_66 ) ;
if ( V_54 != V_576 ) {
F_11 ( V_13 -> V_30 ,
L_43 , V_558 ) ;
return - V_65 ;
}
if ( ! V_571 ) {
F_11 ( V_13 -> V_30 , L_44 , V_558 ) ;
return - V_65 ;
}
if ( V_562 > V_8 ) {
F_11 ( V_13 -> V_30 ,
L_45 ,
V_562 , V_558 , V_8 ) ;
return - V_65 ;
}
V_575 = V_66 ;
V_575 = V_575 - sizeof( struct V_577 ) - 4 ;
V_575 = V_575 - sizeof( struct V_578 ) - sizeof( struct V_579 ) ;
V_54 = F_316 ( V_13 , V_580 ,
V_581 ,
V_582 ,
V_583 ,
V_584 ,
V_11 -> V_76 , V_574 , 0 ,
V_562 * 1000 , 0 , V_575 ) ;
if ( V_54 ) {
F_11 ( V_13 -> V_30 , L_46 ,
V_54 ) ;
return - V_65 ;
}
F_310 ( V_13 -> V_30 ,
L_47 ,
V_574 , V_575 , V_562 ) ;
V_572 = ( F_7 ( V_585 ) |
F_8 ( V_586 ) ) ;
V_573 = V_574 ;
V_54 = F_121 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_558 + 1 , 1 , & V_572 ,
& V_573 ) ;
if ( V_54 ) {
F_11 ( V_13 -> V_30 ,
L_48 ,
V_54 , V_558 , V_574 ) ;
return - V_65 ;
}
F_310 ( V_13 -> V_30 , L_49 ,
V_13 -> V_28 , V_558 , V_574 ) ;
V_13 -> V_556 [ V_558 ] . V_563 = V_562 ;
return 0 ;
}
static int F_317 ( struct V_1 * V_2 , void * V_6 )
{
int V_54 ;
struct V_587 * V_50 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_309 ( V_50 -> V_588 ) )
return - V_589 ;
V_54 = F_41 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 ,
V_11 -> V_74 , V_50 -> V_588 , true , true ) ;
if ( V_54 < 0 )
return V_54 ;
memcpy ( V_2 -> V_75 , V_50 -> V_588 , V_2 -> V_590 ) ;
V_11 -> V_74 = V_54 ;
return 0 ;
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_68 & V_132 ) {
int V_19 ;
struct V_158 * V_591 = & V_13 -> V_16 . V_153 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_591 ++ )
V_151 ( 0 , & V_591 -> V_154 ) ;
} else
F_268 ( V_13 ) ( 0 , V_13 ) ;
}
static int F_319 ( struct V_1 * V_2 , int V_592 , T_1 V_593 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_594 * V_595 ;
struct V_596 V_6 ;
struct V_597 V_598 ;
T_1 V_599 ;
int V_22 = 0 ;
if ( ! F_320 ( V_2 ) )
return - V_600 ;
if ( V_592 < 0 || V_592 > V_11 -> V_20 - 1 )
return - V_65 ;
if ( ! ( V_13 -> V_68 & V_173 ) ) {
F_11 ( V_13 -> V_30 ,
L_50 ,
V_592 ) ;
return - V_65 ;
}
V_599 = V_593 << 10 ;
if ( V_599 >= V_601 ) {
F_11 ( V_13 -> V_30 ,
L_51 ,
V_593 , V_601 ) ;
return - V_532 ;
}
memset ( & V_598 , 0 , sizeof( V_598 ) ) ;
V_598 . V_284 = V_592 ;
V_598 . V_602 = V_603 ;
V_22 = F_321 ( V_2 , ( void * ) ( & V_598 ) , V_604 ) ;
if ( V_22 ) {
F_11 ( V_13 -> V_30 ,
L_52 ,
V_592 , V_11 -> V_31 , V_22 ) ;
return V_22 ;
}
if ( ! V_599 )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_580 ;
V_6 . V_118 . V_193 . V_605 = V_581 ;
V_6 . V_118 . V_193 . V_606 = V_582 ;
V_6 . V_118 . V_193 . V_607 = V_583 ;
V_6 . V_118 . V_193 . V_608 = V_584 ;
V_6 . V_118 . V_193 . V_609 = V_11 -> V_76 ;
V_6 . V_118 . V_193 . V_602 = V_603 ;
V_6 . V_118 . V_193 . V_610 = 0 ;
V_6 . V_118 . V_193 . V_611 = V_599 ;
V_6 . V_118 . V_193 . V_612 = 0 ;
V_6 . V_118 . V_193 . V_575 = V_2 -> V_66 ;
V_595 = F_322 ( V_2 , & V_6 ) ;
if ( ! V_595 )
return - V_61 ;
memset ( & V_598 , 0 , sizeof( V_598 ) ) ;
V_598 . V_284 = V_592 ;
V_598 . V_602 = V_595 -> V_189 ;
V_22 = F_323 ( V_2 , ( void * ) ( & V_598 ) , V_604 ) ;
if ( V_22 )
F_11 ( V_13 -> V_30 ,
L_53 , V_22 ) ;
return V_22 ;
}
static int F_324 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
if ( ! F_325 ( V_614 -> V_615 . V_616 ) ||
V_614 -> V_615 . V_617 )
return - V_518 ;
switch ( V_614 -> V_618 ) {
case V_619 :
case V_620 :
return F_326 ( V_2 , V_614 ) ;
case V_621 :
return F_327 ( V_2 , V_614 ) ;
default:
return - V_518 ;
}
}
static int F_328 ( struct V_1 * V_2 , enum V_622 type ,
void * V_623 )
{
struct V_5 * V_11 = F_86 ( V_2 ) ;
struct V_12 * V_13 = F_167 ( V_2 ) ;
if ( ! ( V_13 -> V_68 & V_173 ) ) {
F_11 ( V_13 -> V_30 ,
L_54 ,
V_11 -> V_31 ) ;
return - V_65 ;
}
switch ( type ) {
case V_624 :
return F_324 ( V_2 , V_623 ) ;
default:
return - V_518 ;
}
}
static T_8 F_329 ( struct V_1 * V_2 ,
T_8 V_72 )
{
if ( ! ( V_72 & V_625 ) )
V_72 &= ~ V_626 ;
return V_72 ;
}
static void F_330 ( struct V_1 * V_2 , struct V_627 * V_119 )
{
struct V_12 * V_12 = F_167 ( V_2 ) ;
F_331 ( V_119 -> V_384 , V_628 , sizeof( V_119 -> V_384 ) ) ;
F_331 ( V_119 -> V_629 , V_630 ,
sizeof( V_119 -> V_629 ) ) ;
F_331 ( V_119 -> V_631 , F_332 ( V_12 -> V_133 ) ,
sizeof( V_119 -> V_631 ) ) ;
}
void F_333 ( struct V_12 * V_13 )
{
int V_39 ;
if ( F_334 ( V_13 -> V_133 ) )
return;
F_335 ( V_13 ) ;
F_73 (adap, port) {
struct V_1 * V_2 = V_13 -> V_39 [ V_39 ] ;
if ( ! V_2 )
continue;
F_279 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_336 ( V_13 -> V_30 , L_55 ) ;
}
static void F_337 ( struct V_12 * V_13 )
{
T_1 V_632 = F_338 ( V_13 ) ;
F_339 ( V_13 , V_632 , V_633 ) ;
}
static void F_340 ( struct V_12 * V_13 )
{
if ( V_13 -> V_359 . V_634 . V_274 ) {
T_1 V_360 ;
unsigned int V_635 ;
V_360 = F_341 ( V_13 , V_636 ) ;
V_360 &= V_637 ;
V_360 += F_342 ( V_13 -> V_133 , & V_13 -> V_359 ) ;
V_635 = F_343 ( V_13 -> V_359 . V_634 . V_274 ) >> 10 ;
F_70 ( V_13 ,
F_344 ( V_638 , 3 ) ,
V_360 | F_345 ( 1 ) | F_346 ( F_347 ( V_635 ) ) ) ;
F_70 ( V_13 ,
F_344 ( V_639 , 3 ) ,
V_13 -> V_359 . V_634 . V_360 ) ;
F_68 ( V_13 ,
F_344 ( V_639 , 3 ) ) ;
}
}
static int F_348 ( struct V_12 * V_13 , struct V_640 * V_641 )
{
T_1 V_137 ;
int V_54 ;
memset ( V_641 , 0 , sizeof( * V_641 ) ) ;
V_641 -> V_642 = F_147 ( F_349 ( V_643 ) |
V_644 | V_645 ) ;
V_641 -> V_646 = F_147 ( F_350 ( * V_641 ) ) ;
V_54 = F_351 ( V_13 , V_13 -> V_27 , V_641 , sizeof( * V_641 ) , V_641 ) ;
if ( V_54 < 0 )
return V_54 ;
V_641 -> V_642 = F_147 ( F_349 ( V_643 ) |
V_644 | V_647 ) ;
V_54 = F_351 ( V_13 , V_13 -> V_27 , V_641 , sizeof( * V_641 ) , NULL ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_352 ( V_13 , V_13 -> V_28 ,
V_648 ,
V_649 |
V_650 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_353 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_177 , 64 ,
V_651 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_652 ,
V_652 ) ;
if ( V_54 < 0 )
return V_54 ;
F_354 ( V_13 ) ;
F_70 ( V_13 , V_653 , 0x64f8849 ) ;
F_70 ( V_13 , V_654 , F_196 ( V_655 - 12 ) ) ;
F_70 ( V_13 , V_656 , V_657 ) ;
V_137 = F_68 ( V_13 , V_658 ) ;
F_70 ( V_13 , V_658 , V_137 & ~ V_659 ) ;
V_13 -> V_193 . V_456 . V_660 = 0xE4 ;
F_70 ( V_13 , V_661 ,
F_355 ( V_13 -> V_193 . V_456 . V_660 ) ) ;
V_137 = 0x84218421 ;
F_356 ( V_13 , V_656 , V_658 ,
& V_137 , 1 , V_662 ) ;
F_356 ( V_13 , V_656 , V_658 ,
& V_137 , 1 , V_663 ) ;
F_356 ( V_13 , V_656 , V_658 ,
& V_137 , 1 , V_664 ) ;
#define F_357 16
if ( F_164 ( V_13 ) ) {
F_70 ( V_13 , V_665 ,
F_358 ( F_357 ) |
F_359 ( F_357 ) |
F_360 ( F_357 ) |
F_361 ( F_357 ) ) ;
F_70 ( V_13 , V_666 ,
F_358 ( F_357 ) |
F_359 ( F_357 ) |
F_360 ( F_357 ) |
F_361 ( F_357 ) ) ;
}
return F_362 ( V_13 , V_13 -> V_28 ) ;
}
static int F_363 ( struct V_12 * V_12 )
{
F_364 ( V_12 , V_667 , V_668 ) ;
if ( V_669 != 2 && V_669 != 0 ) {
F_11 ( & V_12 -> V_133 -> V_2 ,
L_56 ,
V_669 ) ;
V_669 = 2 ;
}
F_242 ( V_12 , V_670 ,
F_365 ( V_671 ) ,
F_365 ( V_669 ) ) ;
F_366 ( V_12 , V_657 ,
V_659 , 0 ) ;
return 0 ;
}
static int F_367 ( const T_3 * V_672 ,
T_9 V_673 )
{
int V_348 ;
#define F_368 ( T_12 ) (((__p)[0] << 8) | (__p)[1])
#define F_369 ( T_12 ) ((__p)[0] | ((__p)[1] << 8))
#define F_370 ( T_12 ) (le16(__p) | ((__p)[2] << 16))
V_348 = F_370 ( V_672 + 0x8 ) << 12 ;
V_348 = F_370 ( V_672 + V_348 + 0xa ) ;
return F_368 ( V_672 + V_348 + 0x27e ) ;
#undef F_368
#undef F_369
#undef F_370
}
static struct V_674 * F_371 ( int V_675 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_676 ) ; V_19 ++ ) {
if ( V_676 [ V_19 ] . V_677 == V_675 )
return & V_676 [ V_19 ] ;
}
return NULL ;
}
static int F_372 ( struct V_12 * V_13 )
{
const struct V_678 * V_679 ;
int V_54 ;
struct V_674 * V_680 ;
V_680 = F_371 ( V_13 -> V_133 -> V_382 ) ;
if ( ! V_680 ) {
F_373 ( V_13 -> V_30 ,
L_57 ) ;
return - V_518 ;
}
V_54 = F_374 ( & V_679 , V_680 -> V_681 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_58
L_59 ,
V_680 -> V_681 , - V_54 ) ;
if ( V_680 -> V_682 ) {
int V_683 = 0 ;
F_375 ( V_13 , & V_683 ) ;
F_373 ( V_13 -> V_30 , L_60
L_61 , V_683 ) ;
V_54 = 0 ;
}
return V_54 ;
}
V_54 = F_376 ( V_13 , V_633 , & V_13 -> V_339 ,
V_680 -> V_684 ,
( T_3 * ) V_679 -> V_109 , V_679 -> V_274 ) ;
if ( V_54 < 0 )
F_11 ( V_13 -> V_30 , L_62 ,
- V_54 ) ;
else if ( V_54 > 0 ) {
int V_685 = 0 ;
if ( V_680 -> V_684 )
V_685 = V_680 -> V_684 ( V_679 -> V_109 ,
V_679 -> V_274 ) ;
F_310 ( V_13 -> V_30 , L_63
L_64 ,
V_680 -> V_681 , V_685 ) ;
}
F_377 ( V_679 ) ;
return V_54 ;
}
static int F_378 ( struct V_12 * V_12 , int V_686 )
{
struct V_640 V_687 ;
const struct V_678 * V_688 ;
unsigned long V_689 = 0 , V_690 = 0 ;
T_1 V_691 , V_692 , V_693 ;
int V_54 ;
int V_694 = 0 ;
char * V_695 , V_696 [ 256 ] ;
char * V_697 = NULL ;
if ( V_686 ) {
V_54 = F_379 ( V_12 , V_12 -> V_27 ,
V_698 | V_699 ) ;
if ( V_54 < 0 )
goto V_700;
}
if ( F_380 ( V_12 -> V_133 -> V_382 ) ) {
V_54 = F_372 ( V_12 ) ;
if ( V_54 < 0 )
goto V_700;
}
switch ( F_165 ( V_12 -> V_193 . V_194 ) ) {
case V_701 :
V_695 = V_702 ;
break;
case V_280 :
V_695 = V_703 ;
break;
case V_704 :
V_695 = V_705 ;
break;
default:
F_11 ( V_12 -> V_30 , L_65 ,
V_12 -> V_133 -> V_382 ) ;
V_54 = - V_65 ;
goto V_700;
}
V_54 = F_381 ( & V_688 , V_695 , V_12 -> V_30 ) ;
if ( V_54 < 0 ) {
V_697 = L_66 ;
V_689 = V_706 ;
V_690 = F_382 ( V_12 ) ;
} else {
T_1 V_193 [ 7 ] , V_344 [ 7 ] ;
sprintf ( V_696 ,
L_67 , V_695 ) ;
V_697 = V_696 ;
if ( V_688 -> V_274 >= V_707 )
V_54 = - V_61 ;
else {
V_193 [ 0 ] = ( F_7 ( V_708 ) |
F_8 ( V_709 ) ) ;
V_54 = F_383 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_193 , V_344 ) ;
if ( V_54 == 0 ) {
T_9 V_710 = V_688 -> V_274 & 0x3 ;
T_9 V_274 = V_688 -> V_274 & ~ 0x3 ;
T_10 * V_109 = ( T_10 * ) V_688 -> V_109 ;
V_689 = F_384 ( V_344 [ 0 ] ) ;
V_690 = F_385 ( V_344 [ 0 ] ) << 16 ;
F_192 ( & V_12 -> V_339 ) ;
V_54 = F_203 ( V_12 , 0 , V_689 , V_690 ,
V_274 , V_109 , V_711 ) ;
if ( V_54 == 0 && V_710 != 0 ) {
union {
T_10 V_712 ;
char V_713 [ 4 ] ;
} V_714 ;
int V_19 ;
V_714 . V_712 = V_109 [ V_274 >> 2 ] ;
for ( V_19 = V_710 ; V_19 < 4 ; V_19 ++ )
V_714 . V_713 [ V_19 ] = 0 ;
V_54 = F_203 ( V_12 , 0 , V_689 ,
V_690 + V_274 ,
4 , & V_714 . V_712 ,
V_711 ) ;
}
F_194 ( & V_12 -> V_339 ) ;
}
}
F_377 ( V_688 ) ;
if ( V_54 )
goto V_700;
}
memset ( & V_687 , 0 , sizeof( V_687 ) ) ;
V_687 . V_642 =
F_147 ( F_349 ( V_643 ) |
V_644 |
V_645 ) ;
V_687 . V_646 =
F_147 ( V_715 |
F_386 ( V_689 ) |
F_387 ( V_690 >> 16 ) |
F_350 ( V_687 ) ) ;
V_54 = F_351 ( V_12 , V_12 -> V_27 , & V_687 , sizeof( V_687 ) ,
& V_687 ) ;
if ( V_54 == - V_716 ) {
memset ( & V_687 , 0 , sizeof( V_687 ) ) ;
V_687 . V_642 =
F_147 ( F_349 ( V_643 ) |
V_644 |
V_645 ) ;
V_687 . V_646 = F_147 ( F_350 ( V_687 ) ) ;
V_54 = F_351 ( V_12 , V_12 -> V_27 , & V_687 ,
sizeof( V_687 ) , & V_687 ) ;
V_697 = L_68 ;
}
V_694 = 1 ;
if ( V_54 < 0 )
goto V_700;
V_691 = F_48 ( V_687 . V_691 ) ;
V_692 = F_48 ( V_687 . V_692 ) ;
V_693 = F_48 ( V_687 . V_693 ) ;
if ( V_692 != V_693 )
F_373 ( V_12 -> V_30 , L_69\
L_70 ,
V_692 , V_693 ) ;
V_687 . V_642 =
F_147 ( F_349 ( V_643 ) |
V_644 |
V_647 ) ;
V_687 . V_646 = F_147 ( F_350 ( V_687 ) ) ;
V_54 = F_351 ( V_12 , V_12 -> V_27 , & V_687 , sizeof( V_687 ) ,
NULL ) ;
if ( V_54 < 0 )
goto V_700;
V_54 = F_363 ( V_12 ) ;
if ( V_54 < 0 )
goto V_700;
V_54 = F_388 ( V_12 , V_12 -> V_27 ) ;
if ( V_54 < 0 )
goto V_700;
F_310 ( V_12 -> V_30 , L_71\
L_72 ,
V_697 , V_691 , V_693 ) ;
return 0 ;
V_700:
if ( V_694 && V_54 != - V_716 )
F_373 ( V_12 -> V_30 , L_73 ,
V_697 , - V_54 ) ;
return V_54 ;
}
static struct V_717 * F_389 ( int V_194 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_718 ) ; V_19 ++ ) {
if ( V_718 [ V_19 ] . V_194 == V_194 )
return & V_718 [ V_19 ] ;
}
return NULL ;
}
static int F_390 ( struct V_12 * V_13 )
{
int V_54 ;
T_1 V_137 , V_719 ;
enum V_720 V_35 ;
T_1 V_193 [ 7 ] , V_344 [ 7 ] ;
struct V_640 V_687 ;
int V_686 = 1 ;
V_54 = F_391 ( V_13 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_392 ( V_13 , V_13 -> V_27 , V_13 -> V_27 ,
F_109 () ? V_721 : V_722 , & V_35 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_74 ,
V_54 ) ;
return V_54 ;
}
if ( V_54 == V_13 -> V_27 )
V_13 -> V_68 |= V_141 ;
F_393 ( V_13 ) ;
V_54 = F_394 ( V_13 ) ;
if ( V_54 )
V_35 = V_723 ;
if ( ( V_13 -> V_68 & V_141 ) && V_35 != V_724 ) {
struct V_717 * V_717 ;
struct V_725 * V_726 ;
const struct V_678 * V_727 ;
const T_3 * V_728 = NULL ;
unsigned int V_729 = 0 ;
V_717 = F_389 ( F_165 ( V_13 -> V_193 . V_194 ) ) ;
if ( V_717 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_75 ,
F_165 ( V_13 -> V_193 . V_194 ) ) ;
return - V_65 ;
}
V_726 = F_161 ( sizeof( * V_726 ) , V_161 ) ;
V_54 = F_381 ( & V_727 , V_717 -> V_730 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_76 ,
V_717 -> V_730 , V_54 ) ;
} else {
V_728 = V_727 -> V_109 ;
V_729 = V_727 -> V_274 ;
}
V_54 = F_395 ( V_13 , V_717 , V_728 , V_729 , V_726 ,
V_35 , & V_686 ) ;
F_377 ( V_727 ) ;
F_396 ( V_726 ) ;
if ( V_54 < 0 )
goto V_700;
}
V_54 = F_397 ( V_13 , & V_13 -> V_193 . V_554 ) ;
if ( V_54 < 0 )
goto V_700;
V_137 =
F_7 ( V_708 ) |
F_8 ( V_731 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_137 , & V_719 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_193 . V_732 = F_398 ( V_719 ) ;
V_13 -> V_193 . V_733 = V_719 ;
if ( V_35 == V_724 ) {
F_310 ( V_13 -> V_30 , L_77\
L_78 ,
V_13 -> V_68 & V_141 ? L_79 : L_80 ) ;
} else {
F_310 ( V_13 -> V_30 , L_81\
L_82 ) ;
V_193 [ 0 ] = ( F_7 ( V_708 ) |
F_8 ( V_709 ) ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_193 , V_344 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_83
L_84 ) ;
goto V_700;
}
V_54 = F_378 ( V_13 , V_686 ) ;
if ( V_54 == - V_716 ) {
F_11 ( V_13 -> V_30 , L_85
L_86 ) ;
goto V_700;
}
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_87
L_88 , - V_54 ) ;
goto V_700;
}
}
V_54 = F_354 ( V_13 ) ;
if ( V_54 < 0 )
goto V_700;
if ( F_399 ( V_13 -> V_133 -> V_382 ) )
V_13 -> V_193 . V_734 = 1 ;
#define F_400 ( T_13 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_401 ( T_13 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_193 [ 0 ] = F_401 ( V_735 ) ;
V_193 [ 1 ] = F_401 ( V_736 ) ;
V_193 [ 2 ] = F_401 ( V_737 ) ;
V_193 [ 3 ] = F_401 ( V_738 ) ;
V_193 [ 4 ] = F_401 ( V_739 ) ;
V_193 [ 5 ] = F_401 ( V_740 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_193 , V_344 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_16 . V_99 = V_344 [ 0 ] ;
V_13 -> V_741 = V_344 [ 1 ] ;
V_13 -> V_742 = V_344 [ 2 ] ;
V_13 -> V_254 . V_467 = V_344 [ 3 ] ;
V_13 -> V_254 . V_270 = V_344 [ 4 ] - V_344 [ 3 ] + 1 ;
V_13 -> V_16 . V_168 = V_344 [ 5 ] ;
V_193 [ 0 ] = F_401 ( V_743 ) ;
V_193 [ 1 ] = F_401 ( V_744 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_193 , V_344 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_16 . V_177 = V_344 [ 0 ] - V_13 -> V_16 . V_99 + 1 ;
V_13 -> V_16 . V_170 = V_344 [ 1 ] - V_13 -> V_16 . V_168 + 1 ;
V_13 -> V_16 . V_98 = F_402 ( V_13 -> V_16 . V_177 ,
sizeof( * V_13 -> V_16 . V_98 ) , V_161 ) ;
if ( ! V_13 -> V_16 . V_98 ) {
V_54 = - V_61 ;
goto V_700;
}
V_13 -> V_16 . V_169 = F_402 ( V_13 -> V_16 . V_170 ,
sizeof( * V_13 -> V_16 . V_169 ) , V_161 ) ;
if ( ! V_13 -> V_16 . V_169 ) {
V_54 = - V_61 ;
goto V_700;
}
V_13 -> V_16 . V_176 = F_402 ( F_160 ( V_13 -> V_16 . V_177 ) ,
sizeof( long ) , V_161 ) ;
if ( ! V_13 -> V_16 . V_176 ) {
V_54 = - V_61 ;
goto V_700;
}
V_13 -> V_16 . V_178 = F_402 ( F_160 ( V_13 -> V_16 . V_177 ) ,
sizeof( long ) , V_161 ) ;
if ( ! V_13 -> V_16 . V_178 ) {
V_54 = - V_61 ;
goto V_700;
}
#ifdef F_127
V_13 -> V_16 . V_745 = F_402 ( F_160 ( V_13 -> V_16 . V_177 ) ,
sizeof( long ) , V_161 ) ;
if ( ! V_13 -> V_16 . V_745 ) {
V_54 = - V_61 ;
goto V_700;
}
#endif
V_193 [ 0 ] = F_401 ( V_746 ) ;
V_193 [ 1 ] = F_401 ( V_747 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_193 , V_344 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_748 = V_344 [ 0 ] ;
V_13 -> V_749 = V_344 [ 1 ] ;
V_13 -> V_193 . V_750 = F_105 ( V_13 -> V_193 . V_194 ) ? 15 : 16 ;
V_193 [ 0 ] = F_401 ( V_751 ) ;
V_193 [ 1 ] = F_401 ( V_752 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_193 , V_344 ) ;
if ( ( V_344 [ 0 ] != V_344 [ 1 ] ) && ( V_54 >= 0 ) ) {
V_13 -> V_68 |= V_753 ;
V_13 -> V_254 . V_754 = V_344 [ 0 ] ;
V_13 -> V_254 . V_755 = V_344 [ 1 ] ;
}
V_193 [ 0 ] = F_401 ( V_756 ) ;
V_344 [ 0 ] = 1 ;
( void ) F_121 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_193 , V_344 ) ;
if ( F_105 ( V_13 -> V_193 . V_194 ) ) {
V_13 -> V_193 . V_757 = false ;
} else {
V_193 [ 0 ] = F_400 ( V_758 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_193 , V_344 ) ;
V_13 -> V_193 . V_757 = ( V_54 == 0 && V_344 [ 0 ] != 0 ) ;
}
V_193 [ 0 ] = F_400 ( V_759 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_193 , V_344 ) ;
V_13 -> V_193 . V_760 = ( V_54 == 0 && V_344 [ 0 ] != 0 ) ;
memset ( & V_687 , 0 , sizeof( V_687 ) ) ;
V_687 . V_642 = F_147 ( F_349 ( V_643 ) |
V_644 | V_645 ) ;
V_687 . V_646 = F_147 ( F_350 ( V_687 ) ) ;
V_54 = F_351 ( V_13 , V_13 -> V_27 , & V_687 , sizeof( V_687 ) ,
& V_687 ) ;
if ( V_54 < 0 )
goto V_700;
if ( V_687 . V_761 ) {
V_193 [ 0 ] = F_400 ( V_762 ) ;
V_193 [ 1 ] = F_401 ( V_763 ) ;
V_193 [ 2 ] = F_401 ( V_764 ) ;
V_193 [ 3 ] = F_401 ( V_765 ) ;
V_193 [ 4 ] = F_401 ( V_766 ) ;
V_193 [ 5 ] = F_400 ( V_767 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_193 , V_344 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_254 . V_263 = V_344 [ 0 ] ;
V_13 -> V_254 . V_271 = F_403 ( V_13 -> V_254 . V_263 / 2 , V_768 ) ;
V_13 -> V_254 . V_240 = V_344 [ 1 ] ;
V_13 -> V_254 . V_238 = V_344 [ 2 ] - V_344 [ 1 ] + 1 ;
if ( V_13 -> V_68 & V_753 && ! F_404 ( V_13 ) ) {
V_13 -> V_254 . V_245 = V_13 -> V_254 . V_467 +
F_405 ( V_13 -> V_254 . V_270 , 3 ) ;
V_13 -> V_254 . V_244 = V_13 -> V_254 . V_270 -
F_405 ( V_13 -> V_254 . V_270 , 3 ) ;
V_13 -> V_254 . V_270 = V_13 -> V_254 . V_245 -
V_13 -> V_254 . V_467 ;
}
V_13 -> V_359 . V_769 . V_360 = V_344 [ 3 ] ;
V_13 -> V_359 . V_769 . V_274 = V_344 [ 4 ] - V_344 [ 3 ] + 1 ;
V_13 -> V_193 . V_770 = V_344 [ 5 ] ;
V_13 -> V_193 . V_771 = 1 ;
V_13 -> V_772 += 1 ;
}
if ( V_687 . V_773 ) {
V_193 [ 0 ] = F_401 ( V_774 ) ;
V_193 [ 1 ] = F_401 ( V_775 ) ;
V_193 [ 2 ] = F_401 ( V_776 ) ;
V_193 [ 3 ] = F_401 ( V_777 ) ;
V_193 [ 4 ] = F_401 ( V_778 ) ;
V_193 [ 5 ] = F_401 ( V_779 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_193 , V_344 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_359 . V_346 . V_360 = V_344 [ 0 ] ;
V_13 -> V_359 . V_346 . V_274 = V_344 [ 1 ] - V_344 [ 0 ] + 1 ;
V_13 -> V_359 . V_780 . V_360 = V_344 [ 2 ] ;
V_13 -> V_359 . V_780 . V_274 = V_344 [ 3 ] - V_344 [ 2 ] + 1 ;
V_13 -> V_359 . V_781 . V_360 = V_344 [ 4 ] ;
V_13 -> V_359 . V_781 . V_274 = V_344 [ 5 ] - V_344 [ 4 ] + 1 ;
V_193 [ 0 ] = F_401 ( V_782 ) ;
V_193 [ 1 ] = F_401 ( V_783 ) ;
V_193 [ 2 ] = F_401 ( V_784 ) ;
V_193 [ 3 ] = F_401 ( V_785 ) ;
V_193 [ 4 ] = F_401 ( V_786 ) ;
V_193 [ 5 ] = F_401 ( V_787 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_193 ,
V_344 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_359 . V_788 . V_360 = V_344 [ 0 ] ;
V_13 -> V_359 . V_788 . V_274 = V_344 [ 1 ] - V_344 [ 0 ] + 1 ;
V_13 -> V_359 . V_789 . V_360 = V_344 [ 2 ] ;
V_13 -> V_359 . V_789 . V_274 = V_344 [ 3 ] - V_344 [ 2 ] + 1 ;
V_13 -> V_359 . V_634 . V_360 = V_344 [ 4 ] ;
V_13 -> V_359 . V_634 . V_274 = V_344 [ 5 ] - V_344 [ 4 ] + 1 ;
V_193 [ 0 ] = F_400 ( V_790 ) ;
V_193 [ 1 ] = F_400 ( V_791 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_193 ,
V_344 ) ;
if ( V_54 < 0 ) {
V_13 -> V_193 . V_792 = 8 ;
V_13 -> V_193 . V_793 = 32 * V_13 -> V_254 . V_263 ;
V_54 = 0 ;
} else {
V_13 -> V_193 . V_792 = V_344 [ 0 ] ;
V_13 -> V_193 . V_793 = V_344 [ 1 ] ;
}
F_310 ( V_13 -> V_30 ,
L_89 ,
V_13 -> V_193 . V_792 ,
V_13 -> V_193 . V_793 ) ;
V_13 -> V_772 += 2 ;
}
if ( V_687 . V_794 ) {
V_193 [ 0 ] = F_401 ( V_795 ) ;
V_193 [ 1 ] = F_401 ( V_796 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_193 , V_344 ) ;
if ( V_54 < 0 )
goto V_700;
V_13 -> V_359 . V_797 . V_360 = V_344 [ 0 ] ;
V_13 -> V_359 . V_797 . V_274 = V_344 [ 1 ] - V_344 [ 0 ] + 1 ;
V_13 -> V_772 += 2 ;
}
if ( V_687 . V_798 ) {
V_193 [ 0 ] = F_401 ( V_799 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_193 , V_344 ) ;
if ( V_54 < 0 ) {
if ( V_54 != - V_65 )
goto V_700;
} else {
V_13 -> V_359 . V_800 = V_344 [ 0 ] ;
}
V_13 -> V_193 . V_801 |= V_802 ;
V_13 -> V_803 += 1 ;
}
#undef F_401
#undef F_400
F_406 ( V_13 , V_13 -> V_193 . V_307 , NULL ) ;
if ( V_35 != V_724 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_308 ; V_19 ++ )
if ( V_13 -> V_193 . V_307 [ V_19 ] == 1492 ) {
V_13 -> V_193 . V_307 [ V_19 ] = 1488 ;
break;
}
F_407 ( V_13 , V_13 -> V_193 . V_307 , V_13 -> V_193 . V_804 ,
V_13 -> V_193 . V_805 ) ;
}
F_408 ( V_13 ) ;
V_13 -> V_68 |= V_806 ;
F_409 ( V_13 ) ;
return 0 ;
V_700:
F_34 ( V_13 -> V_16 . V_98 ) ;
F_34 ( V_13 -> V_16 . V_169 ) ;
F_34 ( V_13 -> V_16 . V_176 ) ;
F_34 ( V_13 -> V_16 . V_178 ) ;
#ifdef F_127
F_34 ( V_13 -> V_16 . V_745 ) ;
#endif
if ( V_54 != - V_807 && V_54 != - V_808 )
F_410 ( V_13 , V_13 -> V_27 ) ;
return V_54 ;
}
static T_14 F_411 ( struct V_326 * V_133 ,
T_15 V_35 )
{
int V_19 ;
struct V_12 * V_13 = F_191 ( V_133 ) ;
if ( ! V_13 )
goto V_59;
F_412 () ;
V_13 -> V_68 &= ~ V_806 ;
F_258 ( V_13 , V_809 ) ;
F_192 ( & V_13 -> V_330 ) ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( V_2 ) {
F_413 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
F_194 ( & V_13 -> V_330 ) ;
F_89 ( V_13 ) ;
if ( V_13 -> V_68 & V_173 )
F_272 ( V_13 ) ;
F_414 () ;
if ( ( V_13 -> V_68 & V_810 ) ) {
F_415 ( V_133 ) ;
V_13 -> V_68 &= ~ V_810 ;
}
V_59: return V_35 == V_811 ?
V_812 : V_813 ;
}
static T_14 F_416 ( struct V_326 * V_133 )
{
int V_19 , V_54 ;
struct V_640 V_641 ;
struct V_12 * V_13 = F_191 ( V_133 ) ;
if ( ! V_13 ) {
F_417 ( V_133 ) ;
F_418 ( V_133 ) ;
return V_814 ;
}
if ( ! ( V_13 -> V_68 & V_810 ) ) {
if ( F_419 ( V_133 ) ) {
F_11 ( & V_133 -> V_2 , L_90
L_91 ) ;
return V_812 ;
}
V_13 -> V_68 |= V_810 ;
}
F_420 ( V_133 ) ;
F_417 ( V_133 ) ;
F_418 ( V_133 ) ;
F_421 ( V_133 ) ;
if ( F_422 ( V_13 -> V_815 ) < 0 )
return V_812 ;
if ( F_392 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_721 , NULL ) < 0 )
return V_812 ;
V_13 -> V_68 |= V_806 ;
if ( F_348 ( V_13 , & V_641 ) )
return V_812 ;
F_73 (adap, i) {
struct V_5 * V_6 = F_84 ( V_13 , V_19 ) ;
V_54 = F_423 ( V_13 , V_13 -> V_27 , V_6 -> V_76 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_54 < 0 )
return V_812 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_74 = - 1 ;
}
F_407 ( V_13 , V_13 -> V_193 . V_307 , V_13 -> V_193 . V_804 ,
V_13 -> V_193 . V_805 ) ;
F_337 ( V_13 ) ;
if ( F_267 ( V_13 ) )
return V_812 ;
return V_814 ;
}
static void F_424 ( struct V_326 * V_133 )
{
int V_19 ;
struct V_12 * V_13 = F_191 ( V_133 ) ;
if ( ! V_13 )
return;
F_412 () ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( V_2 ) {
if ( F_14 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_302 ( V_2 ) ;
}
F_425 ( V_2 ) ;
}
}
F_414 () ;
}
static inline bool F_426 ( const struct V_816 * V_817 )
{
unsigned int V_818 , V_819 ;
V_818 = F_427 ( F_428 ( V_817 -> V_820 ) ) ;
V_819 = V_818 &
~ ( V_821 | V_822 ) ;
return V_819 != 0 ;
}
static void F_429 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 = 0 , V_823 = 0 , V_824 = 0 ;
#ifndef F_16
int V_825 = 0 ;
#endif
if ( F_109 () || ( F_100 ( V_13 ) && F_430 ( V_13 ) ) ) {
V_13 -> V_193 . V_771 = 0 ;
V_13 -> V_193 . V_801 = 0 ;
}
V_823 += F_426 ( & F_84 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_16
if ( V_13 -> V_193 . V_732 * 8 > V_826 ) {
F_11 ( V_13 -> V_30 , L_92 ,
V_826 , V_13 -> V_193 . V_732 * 8 ) ;
F_431 ( 1 ) ;
}
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_824 ;
V_11 -> V_20 = F_109 () ? 1 : 8 ;
V_824 += V_11 -> V_20 ;
}
#else
if ( V_823 )
V_825 = ( V_826 - ( V_13 -> V_193 . V_732 - V_823 ) ) / V_823 ;
if ( V_825 > F_432 () )
V_825 = F_432 () ;
if ( F_109 () )
V_825 = 1 ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_824 ;
V_11 -> V_20 = F_426 ( & V_11 -> V_7 ) ? V_825 : 1 ;
V_824 += V_11 -> V_20 ;
}
#endif
V_4 -> V_827 = V_824 ;
V_4 -> V_828 = V_824 ;
if ( F_100 ( V_13 ) ) {
if ( V_823 ) {
V_19 = F_433 ( int , V_829 , F_434 () ) ;
V_4 -> V_830 = F_435 ( V_19 , V_13 -> V_193 . V_732 ) ;
} else {
V_4 -> V_830 = V_13 -> V_193 . V_732 ;
}
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_153 ) ; V_19 ++ ) {
struct V_158 * V_831 = & V_4 -> V_153 [ V_19 ] ;
F_436 ( V_13 , & V_831 -> V_154 , 5 , 10 , 1024 , 64 ) ;
V_831 -> V_186 . V_274 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_274 = 1024 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_192 ) ; V_19 ++ )
V_4 -> V_192 [ V_19 ] . V_25 . V_274 = 512 ;
if ( ! F_105 ( V_13 -> V_193 . V_194 ) )
V_4 -> V_195 . V_25 . V_274 = 8 ;
F_436 ( V_13 , & V_4 -> V_152 , 0 , 1 , 1024 , 64 ) ;
F_436 ( V_13 , & V_4 -> V_179 , 0 , 1 , 512 , 64 ) ;
}
static void F_437 ( struct V_12 * V_13 , int V_145 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_145 < V_13 -> V_16 . V_827 )
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_827 -- ;
if ( V_13 -> V_16 . V_827 <= V_145 )
break;
}
}
V_145 = 0 ;
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_145 ;
V_145 += V_11 -> V_20 ;
}
}
static int F_438 ( struct V_12 * V_13 )
{
struct V_832 * V_146 ;
unsigned int V_833 = 0 ;
if ( F_164 ( V_13 ) )
V_833 += V_829 * V_13 -> V_772 ;
if ( F_439 ( V_13 ) )
V_833 += V_829 * V_13 -> V_803 ;
if ( ! V_833 )
goto V_59;
V_146 = F_402 ( V_833 , sizeof( * V_146 ) , V_161 ) ;
if ( ! V_146 )
return - V_61 ;
V_13 -> V_834 . V_835 = F_402 ( F_160 ( V_833 ) ,
sizeof( long ) , V_161 ) ;
if ( ! V_13 -> V_834 . V_835 ) {
F_34 ( V_146 ) ;
return - V_61 ;
}
F_162 ( & V_13 -> V_834 . V_836 ) ;
V_13 -> V_837 = V_146 ;
V_59:
return 0 ;
}
static void F_440 ( struct V_12 * V_13 )
{
if ( ! ( V_13 -> V_803 && V_13 -> V_772 ) )
return;
F_34 ( V_13 -> V_837 ) ;
F_34 ( V_13 -> V_834 . V_835 ) ;
}
static int F_441 ( struct V_12 * V_13 )
{
int V_838 = 0 , V_839 = 0 ;
int V_19 , V_143 , V_840 , V_841 , V_842 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_843 = V_13 -> V_193 . V_732 ;
struct V_844 * V_845 ;
int V_833 = V_651 ;
if ( F_439 ( V_13 ) )
V_833 += ( V_829 * V_13 -> V_803 ) ;
if ( F_164 ( V_13 ) )
V_833 += ( V_829 * V_13 -> V_772 ) ;
V_845 = F_80 ( sizeof( * V_845 ) * ( V_833 + 1 ) ,
V_161 ) ;
if ( ! V_845 )
return - V_61 ;
if ( F_438 ( V_13 ) ) {
V_13 -> V_193 . V_771 = 0 ;
V_13 -> V_193 . V_801 = 0 ;
}
for ( V_19 = 0 ; V_19 < V_833 + 1 ; ++ V_19 )
V_845 [ V_19 ] . V_49 = V_19 ;
V_840 = V_4 -> V_828 + V_846 ;
if ( F_164 ( V_13 ) ) {
V_840 += V_13 -> V_772 * V_4 -> V_830 ;
V_838 = V_13 -> V_772 * V_843 ;
}
if ( F_439 ( V_13 ) ) {
V_840 += V_13 -> V_803 * V_4 -> V_830 ;
V_839 = V_13 -> V_803 * V_843 ;
}
#ifdef F_16
V_841 = 8 * V_13 -> V_193 . V_732 + V_846 + V_838 + V_839 ;
#else
V_841 = V_13 -> V_193 . V_732 + V_846 + V_838 + V_839 ;
#endif
V_842 = F_442 ( V_13 -> V_133 , V_845 , V_841 , V_840 ) ;
if ( V_842 < 0 ) {
F_310 ( V_13 -> V_30 , L_93
L_94 ) ;
F_34 ( V_845 ) ;
return V_842 ;
}
V_19 = V_842 - V_846 - V_838 - V_839 ;
if ( V_19 < V_4 -> V_828 ) {
V_4 -> V_828 = V_19 ;
if ( V_19 < V_4 -> V_827 )
F_437 ( V_13 , V_19 ) ;
}
if ( F_100 ( V_13 ) ) {
if ( V_842 < V_840 )
V_4 -> V_847 = V_843 ;
else
V_4 -> V_847 = V_4 -> V_830 ;
}
for ( V_19 = 0 ; V_19 < ( V_4 -> V_828 + V_846 ) ; ++ V_19 )
V_13 -> V_146 [ V_19 ] . V_46 = V_845 [ V_19 ] . V_848 ;
if ( F_100 ( V_13 ) ) {
for ( V_143 = 0 ; V_19 < V_842 ; ++ V_19 , V_143 ++ ) {
V_13 -> V_837 [ V_143 ] . V_46 = V_845 [ V_19 ] . V_848 ;
V_13 -> V_837 [ V_143 ] . V_189 = V_19 ;
}
V_13 -> V_834 . V_849 = V_143 ;
}
F_310 ( V_13 -> V_30 , L_95
L_96 ,
V_842 , V_4 -> V_828 , V_4 -> V_847 ) ;
F_34 ( V_845 ) ;
return 0 ;
}
static int F_443 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_444 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_157 = F_402 ( V_11 -> V_160 , sizeof( T_6 ) , V_161 ) ;
if ( ! V_11 -> V_157 )
return - V_61 ;
}
return 0 ;
}
static int F_445 ( struct V_12 * V_13 ,
enum V_850 * V_8 ,
enum V_851 * V_852 )
{
T_1 V_853 , V_854 ;
int V_855 , V_856 ;
#define F_446 4
* V_8 = V_857 ;
* V_852 = V_858 ;
V_855 = F_447 ( V_13 -> V_133 , V_859 ,
& V_853 ) ;
V_856 = F_447 ( V_13 -> V_133 , V_860 ,
& V_854 ) ;
if ( ! V_856 && V_854 ) {
if ( V_854 & V_861 )
* V_8 = V_862 ;
else if ( V_854 & V_863 )
* V_8 = V_864 ;
else if ( V_854 & V_865 )
* V_8 = V_866 ;
}
if ( ! V_855 ) {
* V_852 = ( V_853 & V_867 ) >> F_446 ;
if ( ! V_854 ) {
if ( V_853 & V_868 )
* V_8 = V_864 ;
else if ( V_853 & V_869 )
* V_8 = V_866 ;
}
}
if ( * V_8 == V_857 || * V_852 == V_858 )
return V_855 ? V_855 : V_856 ? V_856 : - V_65 ;
return 0 ;
}
static void F_448 ( struct V_12 * V_13 )
{
enum V_851 V_852 , V_870 ;
enum V_850 V_8 , V_871 ;
#define F_449 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_445 ( V_13 , & V_871 , & V_870 ) ) {
F_373 ( V_13 -> V_30 ,
L_97 ) ;
return;
}
if ( F_450 ( V_13 -> V_133 , & V_8 , & V_852 ) ||
V_8 == V_857 || V_852 == V_858 ) {
F_373 ( V_13 -> V_30 ,
L_98 ) ;
return;
}
F_310 ( V_13 -> V_30 , L_99 ,
F_449 ( V_8 ) , F_449 ( V_871 ) ) ;
F_310 ( V_13 -> V_30 , L_100 ,
V_852 , V_870 ) ;
if ( V_8 < V_871 || V_852 < V_870 )
F_310 ( V_13 -> V_30 ,
L_101
L_102 ) ;
}
static void F_451 ( struct V_12 * V_12 )
{
F_452 ( V_12 ) ;
F_310 ( V_12 -> V_30 , L_103 ,
F_164 ( V_12 ) ? L_104 : L_105 ,
( ( V_12 -> V_68 & V_132 ) ? L_106 :
( V_12 -> V_68 & V_134 ) ? L_107 : L_105 ) ,
F_164 ( V_12 ) ? L_108 : L_109 ) ;
}
static void F_453 ( const struct V_1 * V_2 )
{
char V_713 [ 80 ] ;
char * V_872 = V_713 ;
const char * V_873 = L_105 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_193 . V_874 . V_8 == V_875 )
V_873 = L_110 ;
else if ( V_13 -> V_193 . V_874 . V_8 == V_876 )
V_873 = L_111 ;
else if ( V_13 -> V_193 . V_874 . V_8 == V_877 )
V_873 = L_112 ;
if ( V_11 -> V_7 . V_820 & V_821 )
V_872 += sprintf ( V_872 , L_113 ) ;
if ( V_11 -> V_7 . V_820 & V_822 )
V_872 += sprintf ( V_872 , L_114 ) ;
if ( V_11 -> V_7 . V_820 & V_878 )
V_872 += sprintf ( V_872 , L_115 ) ;
if ( V_11 -> V_7 . V_820 & V_879 )
V_872 += sprintf ( V_872 , L_116 ) ;
if ( V_11 -> V_7 . V_820 & V_880 )
V_872 += sprintf ( V_872 , L_117 ) ;
if ( V_11 -> V_7 . V_820 & V_881 )
V_872 += sprintf ( V_872 , L_118 ) ;
if ( V_11 -> V_7 . V_820 & V_882 )
V_872 += sprintf ( V_872 , L_119 ) ;
if ( V_11 -> V_7 . V_820 & V_883 )
V_872 += sprintf ( V_872 , L_120 ) ;
if ( V_11 -> V_7 . V_820 & V_884 )
V_872 += sprintf ( V_872 , L_121 ) ;
if ( V_872 != V_713 )
-- V_872 ;
sprintf ( V_872 , L_122 , F_454 ( V_11 -> V_885 ) ) ;
F_3 ( V_2 , L_123 ,
V_2 -> V_9 , V_13 -> V_193 . V_554 . V_570 , V_13 -> V_9 , V_713 ) ;
}
static void F_455 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_396 ( V_12 -> V_886 ) ;
F_456 ( V_12 ) ;
F_396 ( V_12 -> V_254 . V_253 ) ;
F_457 ( V_12 ) ;
F_34 ( V_12 -> V_16 . V_98 ) ;
F_34 ( V_12 -> V_16 . V_169 ) ;
F_34 ( V_12 -> V_16 . V_176 ) ;
F_34 ( V_12 -> V_16 . V_178 ) ;
#ifdef F_127
F_34 ( V_12 -> V_16 . V_745 ) ;
#endif
F_64 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] ) {
struct V_5 * V_11 = F_84 ( V_12 , V_19 ) ;
if ( V_11 -> V_51 != 0 )
F_458 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_51 ) ;
F_34 ( F_84 ( V_12 , V_19 ) -> V_157 ) ;
F_459 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_12 -> V_68 & V_806 )
F_410 ( V_12 , V_12 -> V_28 ) ;
}
static int F_460 ( struct V_326 * V_133 , T_1 V_887 )
{
T_6 V_888 ;
F_461 ( V_133 , V_889 , & V_888 ) ;
switch ( V_888 >> 12 ) {
case V_701 :
return F_462 ( V_701 , V_887 ) ;
case V_280 :
return F_462 ( V_280 , V_887 ) ;
case V_704 :
return F_462 ( V_704 , V_887 ) ;
default:
F_11 ( & V_133 -> V_2 , L_65 ,
V_888 ) ;
}
return - V_65 ;
}
static void F_463 ( struct V_1 * V_2 )
{
V_2 -> type = V_890 ;
V_2 -> V_66 = 0 ;
V_2 -> V_891 = 0 ;
V_2 -> V_590 = 0 ;
V_2 -> V_892 = 0 ;
V_2 -> V_68 |= V_893 ;
V_2 -> V_894 |= V_895 ;
V_2 -> V_896 = & V_897 ;
V_2 -> V_898 = & V_899 ;
V_2 -> V_900 = true ;
}
static int F_464 ( struct V_326 * V_133 )
{
struct V_12 * V_13 = F_191 ( V_133 ) ;
struct V_1 * V_52 ;
struct V_5 * V_11 ;
char V_9 [ V_901 ] ;
int V_22 ;
snprintf ( V_9 , V_901 , L_124 , V_13 -> V_568 , V_13 -> V_28 ) ;
V_52 = F_465 ( sizeof( struct V_5 ) , V_9 , V_902 ,
F_463 ) ;
if ( ! V_52 )
return - V_61 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_13 ;
V_11 -> V_76 = V_13 -> V_28 % V_13 -> V_193 . V_732 ;
F_466 ( V_52 , & V_133 -> V_2 ) ;
V_13 -> V_39 [ 0 ] = V_52 ;
V_11 -> V_31 = 0 ;
V_22 = F_467 ( V_13 -> V_39 [ 0 ] ) ;
if ( V_22 ) {
F_5 ( L_125 , V_9 ) ;
F_459 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
return V_22 ;
}
return 0 ;
}
static int F_468 ( struct V_326 * V_133 , int V_555 )
{
struct V_12 * V_13 = F_191 ( V_133 ) ;
int V_22 = 0 ;
int V_903 = F_469 ( V_133 ) ;
T_1 V_904 ;
V_904 = F_470 ( V_13 -> V_815 + V_905 ) ;
if ( ! ( V_904 & V_906 ) ||
! ( V_904 & V_907 ) ||
F_471 ( V_904 ) != 4 ) {
F_373 ( & V_133 -> V_2 ,
L_126 ) ;
return - V_518 ;
}
if ( V_903 && F_472 ( V_133 ) ) {
F_11 ( & V_133 -> V_2 ,
L_127 ) ;
V_555 = V_903 ;
return V_555 ;
}
if ( ! V_555 ) {
F_473 ( V_133 ) ;
if ( V_13 -> V_39 [ 0 ] ) {
F_474 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
}
F_34 ( V_13 -> V_556 ) ;
V_13 -> V_556 = NULL ;
V_13 -> V_555 = 0 ;
return V_555 ;
}
if ( V_555 != V_903 ) {
V_22 = F_475 ( V_133 , V_555 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_555 = V_555 ;
V_22 = F_464 ( V_133 ) ;
if ( V_22 )
return V_22 ;
}
V_13 -> V_556 = F_402 ( V_13 -> V_555 ,
sizeof( struct V_908 ) , V_161 ) ;
if ( V_13 -> V_556 )
F_305 ( V_13 ) ;
return V_555 ;
}
static int F_476 ( struct V_326 * V_133 , const struct V_909 * V_910 )
{
int V_911 , V_19 , V_22 , V_912 , V_913 , V_914 ;
struct V_5 * V_11 ;
bool V_915 = false ;
struct V_12 * V_12 = NULL ;
struct V_1 * V_52 ;
void T_16 * V_815 ;
T_1 V_916 , V_887 ;
enum V_318 V_194 ;
static int V_568 = 1 ;
#ifdef F_477
T_1 V_137 , V_719 ;
#endif
F_478 ( V_917 L_128 , V_918 , V_919 ) ;
V_22 = F_479 ( V_133 , V_920 ) ;
if ( V_22 ) {
F_310 ( & V_133 -> V_2 , L_129 ) ;
return V_22 ;
}
V_22 = F_419 ( V_133 ) ;
if ( V_22 ) {
F_11 ( & V_133 -> V_2 , L_130 ) ;
goto V_921;
}
V_815 = F_480 ( V_133 , 0 ) ;
if ( ! V_815 ) {
F_11 ( & V_133 -> V_2 , L_131 ) ;
V_22 = - V_61 ;
goto V_922;
}
V_22 = F_422 ( V_815 ) ;
if ( V_22 < 0 )
goto V_923;
V_916 = F_470 ( V_815 + V_924 ) ;
V_887 = F_481 ( F_470 ( V_815 + V_925 ) ) ;
V_194 = F_460 ( V_133 , V_887 ) ;
V_911 = F_165 ( V_194 ) <= V_280 ?
F_482 ( V_916 ) : F_483 ( V_916 ) ;
if ( V_911 != V_910 -> V_926 ) {
#ifndef F_477
F_484 ( V_815 ) ;
#endif
F_415 ( V_133 ) ;
F_418 ( V_133 ) ;
goto V_927;
}
if ( ! F_485 ( V_133 , F_486 ( 64 ) ) ) {
V_915 = true ;
V_22 = F_487 ( V_133 , F_486 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_133 -> V_2 , L_132
L_133 ) ;
goto V_923;
}
} else {
V_22 = F_485 ( V_133 , F_486 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_133 -> V_2 , L_134 ) ;
goto V_923;
}
}
F_488 ( V_133 ) ;
F_420 ( V_133 ) ;
F_418 ( V_133 ) ;
V_12 = F_27 ( sizeof( * V_12 ) , V_161 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_923;
}
V_568 ++ ;
V_12 -> V_259 = F_489 ( L_135 ) ;
if ( ! V_12 -> V_259 ) {
V_22 = - V_61 ;
goto V_928;
}
V_12 -> V_929 = F_27 ( sizeof( * V_12 -> V_929 ) +
( sizeof( struct V_930 ) *
V_931 ) ,
V_161 ) ;
if ( ! V_12 -> V_929 ) {
V_22 = - V_61 ;
goto V_928;
}
V_12 -> V_929 -> V_274 = V_931 ;
V_12 -> V_68 |= V_810 ;
V_12 -> V_815 = V_815 ;
V_12 -> V_133 = V_133 ;
V_12 -> V_30 = & V_133 -> V_2 ;
V_12 -> V_9 = F_332 ( V_133 ) ;
V_12 -> V_27 = V_911 ;
V_12 -> V_28 = V_911 ;
V_12 -> V_932 = V_933 ;
memset ( V_12 -> V_81 , 0xff , sizeof( V_12 -> V_81 ) ) ;
if ( ! F_490 ( V_133 ) )
V_12 -> V_68 |= V_934 ;
F_162 ( & V_12 -> V_330 ) ;
F_162 ( & V_12 -> V_255 ) ;
F_162 ( & V_12 -> V_339 ) ;
F_162 ( & V_12 -> V_935 ) ;
F_271 ( & V_12 -> V_936 . V_62 ) ;
F_491 ( & V_12 -> V_260 , F_151 ) ;
F_491 ( & V_12 -> V_405 , F_241 ) ;
F_491 ( & V_12 -> V_412 , F_246 ) ;
V_22 = F_492 ( V_12 ) ;
if ( V_22 )
goto V_928;
if ( ! F_105 ( V_12 -> V_193 . V_194 ) ) {
V_912 = ( V_937 +
( V_938 - V_937 ) *
V_12 -> V_28 ) ;
V_913 = 1 << F_493 ( F_68 ( V_12 ,
V_939 ) >> V_912 ) ;
V_914 = V_667 / V_940 ;
if ( V_913 > V_914 ) {
F_11 ( & V_133 -> V_2 ,
L_136 ) ;
V_22 = - V_65 ;
goto V_928;
}
V_12 -> V_418 = F_494 ( F_495 ( V_133 , 2 ) ,
F_496 ( V_133 , 2 ) ) ;
if ( ! V_12 -> V_418 ) {
F_11 ( & V_133 -> V_2 , L_137 ) ;
V_22 = - V_61 ;
goto V_928;
}
}
F_337 ( V_12 ) ;
V_22 = F_390 ( V_12 ) ;
#ifdef F_127
F_96 ( V_12 -> V_16 . V_745 , V_12 -> V_16 . V_177 ) ;
#endif
F_340 ( V_12 ) ;
if ( V_22 )
goto V_941;
if ( ! F_105 ( V_12 -> V_193 . V_194 ) )
F_70 ( V_12 , V_942 , F_497 ( 7 ) |
( F_214 ( V_12 -> V_193 . V_194 ) ? F_498 ( 0 ) :
F_499 ( 0 ) ) ) ;
F_73 (adapter, i) {
V_52 = F_500 ( sizeof( struct V_5 ) ,
V_826 ) ;
if ( ! V_52 ) {
V_22 = - V_61 ;
goto V_943;
}
F_466 ( V_52 , & V_133 -> V_2 ) ;
V_12 -> V_39 [ V_19 ] = V_52 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_74 = - 1 ;
V_11 -> V_31 = V_19 ;
V_52 -> V_135 = V_133 -> V_135 ;
V_52 -> V_944 = V_945 | V_946 |
V_947 | V_948 |
V_625 | V_949 |
V_950 | V_73 |
V_951 ;
if ( V_915 )
V_52 -> V_944 |= V_952 ;
V_52 -> V_72 |= V_52 -> V_944 ;
V_52 -> V_953 = V_52 -> V_72 & V_954 ;
V_52 -> V_894 |= V_955 ;
V_52 -> V_956 = 81 ;
V_52 -> V_313 = V_957 ;
V_52 -> V_896 = & V_958 ;
#ifdef F_16
V_52 -> V_959 = & V_960 ;
F_17 ( V_52 ) ;
#endif
F_501 ( V_52 ) ;
}
F_502 ( V_133 , V_12 ) ;
if ( V_12 -> V_68 & V_806 ) {
V_22 = F_503 ( V_12 , V_911 , V_911 , 0 ) ;
if ( V_22 )
goto V_943;
} else if ( V_12 -> V_193 . V_732 == 1 ) {
T_3 V_548 [ V_549 ] ;
T_3 * V_551 = V_12 -> V_193 . V_554 . V_551 ;
V_22 = F_306 ( V_12 , & V_12 -> V_193 . V_554 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_549 ; V_19 ++ )
V_548 [ V_19 ] = ( F_307 ( V_551 [ 2 * V_19 + 0 ] ) * 16 +
F_307 ( V_551 [ 2 * V_19 + 1 ] ) ) ;
F_504 ( V_12 , 0 , V_548 ) ;
}
}
F_429 ( V_12 ) ;
V_12 -> V_886 = F_505 ( V_12 -> V_741 , V_12 -> V_742 ) ;
if ( ! V_12 -> V_886 ) {
F_373 ( & V_133 -> V_2 , L_138 ) ;
V_12 -> V_193 . V_771 = 0 ;
}
#if F_260 ( V_448 )
if ( ( F_165 ( V_12 -> V_193 . V_194 ) <= V_280 ) &&
( ! ( F_68 ( V_12 , V_961 ) & V_962 ) ) ) {
F_373 ( & V_133 -> V_2 ,
L_139 ) ;
V_12 -> V_193 . V_771 = 0 ;
} else {
V_12 -> V_963 = F_506 ( V_12 -> V_748 ,
V_12 -> V_749 ) ;
if ( ! V_12 -> V_963 ) {
F_373 ( & V_133 -> V_2 ,
L_140 ) ;
V_12 -> V_193 . V_771 = 0 ;
}
}
#endif
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_11 -> V_964 = F_507 ( V_12 -> V_193 . V_750 ) ;
if ( ! V_11 -> V_964 )
F_373 ( & V_133 -> V_2 ,
L_141 ,
V_19 ) ;
}
if ( F_159 ( & V_12 -> V_254 ) < 0 ) {
F_373 ( & V_133 -> V_2 , L_142
L_143 ) ;
V_12 -> V_193 . V_771 = 0 ;
} else {
V_12 -> V_965 = F_508 ( V_12 ) ;
if ( ! V_12 -> V_965 )
F_373 ( & V_133 -> V_2 ,
L_144 ) ;
}
if ( F_164 ( V_12 ) ) {
if ( F_68 ( V_12 , V_961 ) & V_966 ) {
T_1 V_265 , V_967 ;
if ( V_194 <= V_280 ) {
V_967 = V_968 ;
V_265 = F_68 ( V_12 , V_967 ) ;
V_12 -> V_254 . V_265 = V_265 / 4 ;
} else {
V_967 = V_969 ;
V_265 = F_68 ( V_12 , V_967 ) ;
V_12 -> V_254 . V_265 = V_265 ;
}
}
}
if ( V_970 > 1 && F_441 ( V_12 ) == 0 )
V_12 -> V_68 |= V_132 ;
else if ( V_970 > 0 && F_509 ( V_133 ) == 0 ) {
V_12 -> V_68 |= V_134 ;
if ( V_970 > 1 )
F_440 ( V_12 ) ;
}
F_448 ( V_12 ) ;
V_22 = F_443 ( V_12 ) ;
if ( V_22 )
goto V_943;
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_12 -> V_39 [ V_19 ] -> V_971 = V_11 -> V_454 ;
F_510 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_511 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_18 ( V_12 -> V_39 [ V_19 ] ) ;
V_22 = F_467 ( V_12 -> V_39 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_81 [ V_11 -> V_76 ] = V_19 ;
F_453 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_133 -> V_2 , L_145 ) ;
goto V_943;
}
if ( V_22 ) {
F_373 ( & V_133 -> V_2 , L_146 , V_19 ) ;
V_22 = 0 ;
}
if ( V_972 ) {
V_12 -> V_223 = F_512 ( F_332 ( V_133 ) ,
V_972 ) ;
F_125 ( V_12 ) ;
}
V_133 -> V_973 = 1 ;
if ( F_100 ( V_12 ) ) {
F_253 ( & V_425 ) ;
F_29 ( & V_12 -> V_426 , & V_429 ) ;
F_257 ( & V_425 ) ;
}
if ( ! F_105 ( V_12 -> V_193 . V_194 ) )
F_513 ( V_12 ) ;
F_451 ( V_12 ) ;
F_95 ( V_12 ) ;
return 0 ;
V_927:
#ifdef F_477
V_12 = F_27 ( sizeof( * V_12 ) , V_161 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_974;
}
V_12 -> V_133 = V_133 ;
V_12 -> V_30 = & V_133 -> V_2 ;
V_12 -> V_9 = F_332 ( V_133 ) ;
V_12 -> V_27 = V_911 ;
V_12 -> V_28 = V_911 ;
V_12 -> V_815 = V_815 ;
V_12 -> V_568 = V_568 ;
V_12 -> V_929 = F_27 ( sizeof( * V_12 -> V_929 ) +
( sizeof( struct V_930 ) *
V_931 ) ,
V_161 ) ;
if ( ! V_12 -> V_929 ) {
V_22 = - V_61 ;
goto V_975;
}
F_162 ( & V_12 -> V_935 ) ;
F_271 ( & V_12 -> V_936 . V_62 ) ;
V_137 = F_7 ( V_708 ) |
F_8 ( V_731 ) ;
V_22 = F_383 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 ,
& V_137 , & V_719 ) ;
if ( V_22 < 0 ) {
F_11 ( V_12 -> V_30 , L_147 ) ;
goto V_976;
}
V_12 -> V_193 . V_732 = F_398 ( V_719 ) ;
F_502 ( V_133 , V_12 ) ;
return 0 ;
V_976:
F_34 ( V_12 -> V_929 ) ;
V_975:
F_34 ( V_12 ) ;
V_974:
F_484 ( V_815 ) ;
F_473 ( V_133 ) ;
F_514 ( V_133 ) ;
return V_22 ;
#else
return 0 ;
#endif
V_943:
F_455 ( V_12 ) ;
if ( V_12 -> V_68 & V_132 )
F_440 ( V_12 ) ;
if ( V_12 -> V_803 || V_12 -> V_772 )
F_515 ( V_12 ) ;
V_941:
if ( ! F_105 ( V_12 -> V_193 . V_194 ) )
F_484 ( V_12 -> V_418 ) ;
V_928:
if ( V_12 -> V_259 )
F_516 ( V_12 -> V_259 ) ;
F_34 ( V_12 -> V_929 ) ;
F_34 ( V_12 ) ;
V_923:
F_484 ( V_815 ) ;
V_922:
F_517 ( V_133 ) ;
F_415 ( V_133 ) ;
V_921:
F_514 ( V_133 ) ;
return V_22 ;
}
static void F_518 ( struct V_326 * V_133 )
{
struct V_12 * V_12 = F_191 ( V_133 ) ;
if ( ! V_12 ) {
F_514 ( V_133 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_516 ( V_12 -> V_259 ) ;
if ( F_100 ( V_12 ) ) {
F_252 ( V_12 ) ;
F_519 ( V_12 ) ;
}
F_89 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_977 == V_978 )
F_474 ( V_12 -> V_39 [ V_19 ] ) ;
F_520 ( V_12 -> V_223 ) ;
if ( ! F_105 ( V_12 -> V_193 . V_194 ) )
F_521 ( V_12 ) ;
F_522 ( V_12 ) ;
if ( V_12 -> V_68 & V_173 )
F_272 ( V_12 ) ;
if ( V_12 -> V_68 & V_132 )
F_440 ( V_12 ) ;
if ( V_12 -> V_803 || V_12 -> V_772 )
F_515 ( V_12 ) ;
F_455 ( V_12 ) ;
#if F_260 ( V_448 )
F_523 ( V_12 ) ;
#endif
F_484 ( V_12 -> V_815 ) ;
if ( ! F_105 ( V_12 -> V_193 . V_194 ) )
F_484 ( V_12 -> V_418 ) ;
F_517 ( V_133 ) ;
if ( ( V_12 -> V_68 & V_810 ) ) {
F_415 ( V_133 ) ;
V_12 -> V_68 &= ~ V_810 ;
}
F_514 ( V_133 ) ;
F_34 ( V_12 -> V_929 ) ;
F_524 () ;
F_34 ( V_12 ) ;
}
#ifdef F_477
else {
if ( V_12 -> V_39 [ 0 ] )
F_474 ( V_12 -> V_39 [ 0 ] ) ;
F_484 ( V_12 -> V_815 ) ;
F_34 ( V_12 -> V_556 ) ;
F_34 ( V_12 -> V_929 ) ;
F_34 ( V_12 ) ;
F_473 ( V_133 ) ;
F_514 ( V_133 ) ;
}
#endif
}
static void F_525 ( struct V_326 * V_133 )
{
struct V_12 * V_12 = F_191 ( V_133 ) ;
if ( ! V_12 ) {
F_514 ( V_133 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_977 == V_978 )
F_278 ( V_12 -> V_39 [ V_19 ] ) ;
if ( F_100 ( V_12 ) ) {
F_252 ( V_12 ) ;
F_519 ( V_12 ) ;
}
F_89 ( V_12 ) ;
F_64 ( V_12 ) ;
F_274 ( V_12 ) ;
if ( V_12 -> V_68 & V_806 )
F_410 ( V_12 , V_12 -> V_27 ) ;
}
#ifdef F_477
else {
if ( V_12 -> V_39 [ 0 ] )
F_474 ( V_12 -> V_39 [ 0 ] ) ;
F_484 ( V_12 -> V_815 ) ;
F_34 ( V_12 -> V_556 ) ;
F_34 ( V_12 -> V_929 ) ;
F_34 ( V_12 ) ;
F_473 ( V_133 ) ;
F_514 ( V_133 ) ;
}
#endif
}
static int T_17 F_526 ( void )
{
int V_54 ;
V_972 = F_512 ( V_920 , NULL ) ;
if ( ! V_972 )
F_527 ( L_148 ) ;
V_54 = F_528 ( & V_385 ) ;
if ( V_54 < 0 )
F_529 ( V_972 ) ;
#if F_260 ( V_448 )
if ( ! V_979 ) {
F_530 ( & V_980 ) ;
V_979 = true ;
}
#endif
return V_54 ;
}
static void T_18 F_531 ( void )
{
#if F_260 ( V_448 )
if ( V_979 ) {
F_532 ( & V_980 ) ;
V_979 = false ;
}
#endif
F_533 ( & V_385 ) ;
F_529 ( V_972 ) ;
}
