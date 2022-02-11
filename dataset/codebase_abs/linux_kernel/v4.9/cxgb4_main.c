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
if ( ( T_3 * ) V_15 < ( T_3 * ) V_25 -> V_13 -> V_16 . V_101 ) {
struct V_14 * V_102 ;
V_102 = F_54 ( V_15 , struct V_14 , V_25 ) ;
F_55 ( V_102 -> V_15 ) ;
} else {
struct V_103 * V_104 ;
V_104 = F_54 ( V_15 , struct V_103 , V_25 ) ;
F_56 ( & V_104 -> V_105 ) ;
}
} else if ( V_88 == V_106 || V_88 == V_90 ) {
const struct V_107 * V_6 = ( void * ) V_85 ;
#ifdef F_16
const struct V_78 * V_79 = ( const void * ) V_6 -> V_108 ;
unsigned int V_109 = F_57 ( F_48 ( V_79 -> V_80 ) ) ;
unsigned int V_110 =
F_58 ( F_48 ( V_79 -> V_111 ) ) ;
if ( V_109 == V_112 &&
V_110 == V_113 ) {
int V_39 = F_47 (
F_59 ( V_79 -> V_80 ) ) ;
struct V_1 * V_2 =
V_25 -> V_13 -> V_39 [ V_25 -> V_13 -> V_81 [ V_39 ] ] ;
int V_114 = ( ( V_79 -> V_115 . V_116 . V_117 &
V_118 )
? V_119
: V_120 ) ;
F_60 ( V_2 , V_114 ) ;
}
if ( V_109 == V_112 &&
V_110 == V_121 )
F_46 ( V_25 -> V_13 , V_79 ) ;
else
#endif
if ( V_6 -> type == 0 )
F_61 ( V_25 -> V_13 , V_6 -> V_108 ) ;
} else if ( V_88 == V_122 ) {
const struct V_123 * V_6 = ( void * ) V_85 ;
F_62 ( V_25 -> V_13 , V_6 ) ;
} else if ( V_88 == V_124 ) {
const struct V_125 * V_6 = ( void * ) V_85 ;
F_63 ( V_25 -> V_13 , V_6 ) ;
} else
F_11 ( V_25 -> V_13 -> V_30 ,
L_28 , V_88 ) ;
V_59:
return 0 ;
}
static void F_64 ( struct V_12 * V_12 )
{
if ( V_12 -> V_68 & V_126 ) {
F_65 ( V_12 -> V_127 ) ;
V_12 -> V_68 &= ~ V_126 ;
} else if ( V_12 -> V_68 & V_128 ) {
F_66 ( V_12 -> V_127 ) ;
V_12 -> V_68 &= ~ V_128 ;
}
}
static T_5 F_67 ( int V_129 , void * V_130 )
{
struct V_12 * V_13 = V_130 ;
T_1 V_131 = F_68 ( V_13 , F_69 ( V_132 ) ) ;
if ( V_131 & V_133 ) {
V_13 -> V_134 = 1 ;
F_70 ( V_13 , F_69 ( V_132 ) , V_131 ) ;
}
if ( V_13 -> V_68 & V_135 )
F_71 ( V_13 ) ;
return V_136 ;
}
static void F_72 ( struct V_12 * V_13 )
{
int V_19 , V_137 , V_138 = 2 , V_139 = sizeof( V_13 -> V_140 [ 0 ] . V_141 ) ;
snprintf ( V_13 -> V_140 [ 0 ] . V_141 , V_139 , L_29 , V_13 -> V_39 [ 0 ] -> V_9 ) ;
snprintf ( V_13 -> V_140 [ 1 ] . V_141 , V_139 , L_30 ,
V_13 -> V_39 [ 0 ] -> V_9 ) ;
F_73 (adap, j) {
struct V_1 * V_142 = V_13 -> V_39 [ V_137 ] ;
const struct V_5 * V_11 = F_4 ( V_142 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_138 ++ )
snprintf ( V_13 -> V_140 [ V_138 ] . V_141 , V_139 , L_31 ,
V_142 -> V_9 , V_19 ) ;
}
}
static int F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 , V_143 ;
int V_144 = 2 ;
V_22 = F_75 ( V_13 -> V_140 [ 1 ] . V_46 , V_145 , 0 ,
V_13 -> V_140 [ 1 ] . V_141 , & V_4 -> V_146 ) ;
if ( V_22 )
return V_22 ;
F_76 (s, ethqidx) {
V_22 = F_75 ( V_13 -> V_140 [ V_144 ] . V_46 ,
V_145 , 0 ,
V_13 -> V_140 [ V_144 ] . V_141 ,
& V_4 -> V_147 [ V_143 ] . V_148 ) ;
if ( V_22 )
goto V_149;
V_144 ++ ;
}
return 0 ;
V_149:
while ( -- V_143 >= 0 )
F_77 ( V_13 -> V_140 [ -- V_144 ] . V_46 ,
& V_4 -> V_147 [ V_143 ] . V_148 ) ;
F_77 ( V_13 -> V_140 [ 1 ] . V_46 , & V_4 -> V_146 ) ;
return V_22 ;
}
static void F_78 ( struct V_12 * V_13 )
{
int V_19 , V_144 = 2 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_77 ( V_13 -> V_140 [ 1 ] . V_46 , & V_4 -> V_146 ) ;
F_76 (s, i)
F_77 ( V_13 -> V_140 [ V_144 ++ ] . V_46 , & V_4 -> V_147 [ V_19 ] . V_148 ) ;
}
int F_79 ( const struct V_5 * V_11 , const T_6 * V_150 )
{
T_6 * V_151 ;
int V_19 , V_22 ;
struct V_12 * V_12 = V_11 -> V_12 ;
const struct V_152 * V_153 ;
V_153 = & V_12 -> V_16 . V_147 [ V_11 -> V_18 ] ;
V_151 = F_80 ( V_11 -> V_154 * sizeof( T_6 ) , V_155 ) ;
if ( ! V_151 )
return - V_61 ;
for ( V_19 = 0 ; V_19 < V_11 -> V_154 ; V_19 ++ , V_150 ++ )
V_151 [ V_19 ] = V_153 [ * V_150 ] . V_148 . V_156 ;
V_22 = F_81 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , 0 ,
V_11 -> V_154 , V_151 , V_11 -> V_154 ) ;
if ( ! V_22 )
V_22 = F_82 ( V_12 , V_12 -> V_27 , V_11 -> V_51 ,
V_157 |
V_158 |
V_159 |
V_160 |
V_161 ,
V_151 [ 0 ] ) ;
F_34 ( V_151 ) ;
return V_22 ;
}
static int F_83 ( struct V_12 * V_13 )
{
int V_19 , V_137 , V_22 ;
F_73 (adap, i) {
const struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
for ( V_137 = 0 ; V_137 < V_11 -> V_154 ; V_137 ++ )
V_11 -> V_151 [ V_137 ] = V_137 % V_11 -> V_20 ;
V_22 = F_79 ( V_11 , V_11 -> V_151 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static unsigned int F_85 ( const struct V_16 * V_6 , unsigned int V_95 )
{
V_95 -= V_6 -> V_162 ;
return F_86 ( V_6 -> V_163 [ V_95 ] -> V_52 ) -> V_76 ;
}
static void F_87 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_164 ; V_19 ++ ) {
struct V_84 * V_25 = V_13 -> V_16 . V_163 [ V_19 ] ;
if ( V_25 && V_25 -> V_165 ) {
F_88 ( & V_25 -> V_166 ) ;
F_43 () ;
while ( ! F_89 ( V_25 ) )
F_90 ( 1 ) ;
F_45 () ;
}
}
}
static void F_91 ( struct V_12 * V_13 )
{
if ( V_13 -> V_68 & V_167 ) {
F_92 ( V_13 ) ;
if ( V_13 -> V_68 & V_126 ) {
F_78 ( V_13 ) ;
F_77 ( V_13 -> V_140 [ 0 ] . V_46 , V_13 ) ;
} else {
F_77 ( V_13 -> V_127 -> V_129 , V_13 ) ;
}
F_87 ( V_13 ) ;
}
}
static void F_93 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_164 ; V_19 ++ ) {
struct V_84 * V_25 = V_13 -> V_16 . V_163 [ V_19 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_165 ) {
F_94 ( V_25 ) ;
F_95 ( & V_25 -> V_166 ) ;
}
F_70 ( V_13 , F_69 ( V_168 ) ,
F_96 ( V_25 -> V_169 ) |
F_97 ( V_25 -> V_26 ) ) ;
}
}
static int F_98 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 = 0 ;
F_99 ( V_4 -> V_170 , V_4 -> V_171 ) ;
F_99 ( V_4 -> V_172 , V_4 -> V_171 ) ;
if ( V_13 -> V_68 & V_126 )
V_13 -> V_138 = 1 ;
else {
V_22 = F_100 ( V_13 , & V_4 -> V_173 , false , V_13 -> V_39 [ 0 ] , 0 ,
NULL , NULL , NULL , - 1 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_138 = - ( ( int ) V_4 -> V_173 . V_156 + 1 ) ;
}
V_22 = F_100 ( V_13 , & V_4 -> V_146 , true , V_13 -> V_39 [ 0 ] ,
V_13 -> V_138 , NULL , F_50 , NULL , - 1 ) ;
if ( V_22 )
F_101 ( V_13 ) ;
return V_22 ;
}
static int F_102 ( struct V_12 * V_13 )
{
int V_22 , V_19 , V_137 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
struct V_174 * V_175 = V_4 -> V_176 [ V_177 ] ;
unsigned int V_178 = 0 ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_152 * V_25 = & V_4 -> V_147 [ V_11 -> V_18 ] ;
struct V_14 * V_179 = & V_4 -> V_17 [ V_11 -> V_18 ] ;
for ( V_137 = 0 ; V_137 < V_11 -> V_20 ; V_137 ++ , V_25 ++ ) {
if ( V_13 -> V_138 > 0 )
V_13 -> V_138 ++ ;
V_22 = F_100 ( V_13 , & V_25 -> V_148 , false , V_2 ,
V_13 -> V_138 , & V_25 -> V_180 ,
V_181 ,
NULL ,
F_103 ( V_13 ,
V_11 -> V_76 ) ) ;
if ( V_22 )
goto V_182;
V_25 -> V_148 . V_183 = V_137 ;
memset ( & V_25 -> V_184 , 0 , sizeof( V_25 -> V_184 ) ) ;
}
for ( V_137 = 0 ; V_137 < V_11 -> V_20 ; V_137 ++ , V_179 ++ ) {
V_22 = F_104 ( V_13 , V_179 , V_2 ,
F_105 ( V_2 , V_137 ) ,
V_4 -> V_146 . V_26 ) ;
if ( V_22 )
goto V_182;
}
}
V_137 = V_4 -> V_185 / V_13 -> V_186 . V_187 ;
F_106 (s, i) {
V_22 = F_107 ( V_13 , & V_4 -> V_101 [ V_19 ] ,
V_13 -> V_39 [ V_19 / V_137 ] ,
V_4 -> V_146 . V_26 ) ;
if ( V_22 )
goto V_182;
}
F_73 (adap, i) {
if ( V_175 )
V_178 = V_175 -> V_188 [ V_19 ] . V_148 . V_26 ;
V_22 = F_108 ( V_13 , & V_4 -> V_189 [ V_19 ] , V_13 -> V_39 [ V_19 ] ,
V_4 -> V_146 . V_26 , V_178 ) ;
if ( V_22 )
goto V_182;
}
F_70 ( V_13 , F_109 ( V_13 -> V_186 . V_190 ) ?
V_191 :
V_192 ,
F_110 ( F_86 ( V_13 -> V_39 [ 0 ] ) -> V_76 ) |
F_111 ( V_4 -> V_147 [ 0 ] . V_148 . V_156 ) ) ;
return 0 ;
V_182:
F_101 ( V_13 ) ;
return V_22 ;
}
void * F_112 ( T_7 V_193 )
{
void * V_6 = F_27 ( V_193 , V_155 | V_194 ) ;
if ( ! V_6 )
V_6 = F_113 ( V_193 ) ;
return V_6 ;
}
void F_114 ( void * V_50 )
{
F_115 ( V_50 ) ;
}
static T_6 F_116 ( struct V_1 * V_2 , struct V_195 * V_196 ,
void * V_197 , T_8 V_198 )
{
int V_15 ;
#ifdef F_16
if ( F_12 ( V_2 ) ) {
T_6 V_199 ;
int V_22 ;
V_22 = F_117 ( V_196 , & V_199 ) ;
if ( F_51 ( V_22 ) ) {
if ( F_118 () )
F_119 ( V_2 ,
L_32 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_199 & V_200 ) >> V_201 ;
#ifdef F_120
if ( V_196 -> V_202 == F_121 ( V_203 ) )
V_15 = V_196 -> V_204 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_205 ) {
V_15 = ( F_122 ( V_196 )
? F_123 ( V_196 )
: F_124 () ) ;
while ( F_51 ( V_15 >= V_2 -> V_206 ) )
V_15 -= V_2 -> V_206 ;
return V_15 ;
}
return V_198 ( V_2 , V_196 ) % V_2 -> V_206 ;
}
static int F_125 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_207 , V_208 = 0 , V_209 = V_210 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_211 ) ; V_19 ++ ) {
V_207 = time - V_4 -> V_211 [ V_19 ] ;
if ( V_207 < 0 )
V_207 = - V_207 ;
if ( V_207 < V_209 ) {
V_209 = V_207 ;
V_208 = V_19 ;
}
}
return V_208 ;
}
static int F_126 ( const struct V_16 * V_4 , int V_212 )
{
int V_19 , V_207 , V_208 = 0 , V_209 = V_210 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_213 ) ; V_19 ++ ) {
V_207 = V_212 - V_4 -> V_213 [ V_19 ] ;
if ( V_207 < 0 )
V_207 = - V_207 ;
if ( V_207 < V_209 ) {
V_209 = V_207 ;
V_208 = V_19 ;
}
}
return V_208 ;
}
int F_127 ( struct V_84 * V_25 ,
unsigned int V_214 , unsigned int V_215 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_214 | V_215 ) == 0 )
V_215 = 1 ;
if ( V_215 ) {
int V_22 ;
T_1 V_131 , V_216 ;
V_216 = F_126 ( & V_13 -> V_16 , V_215 ) ;
if ( V_25 -> V_141 && V_25 -> V_217 != V_216 ) {
V_131 = F_7 ( V_23 ) |
F_8 (
V_218 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_128 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_131 , & V_216 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_217 = V_216 ;
}
V_214 = V_214 == 0 ? 6 : F_125 ( & V_13 -> V_16 , V_214 ) ;
V_25 -> V_169 = F_129 ( V_214 ) | F_130 ( V_215 > 0 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , T_9 V_72 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_9 V_219 = V_2 -> V_72 ^ V_72 ;
int V_22 ;
if ( ! ( V_219 & V_73 ) )
return 0 ;
V_22 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_72 & V_73 ) , true ) ;
if ( F_51 ( V_22 ) )
V_2 -> V_72 = V_72 ^ V_73 ;
return V_22 ;
}
static int F_132 ( struct V_12 * V_13 )
{
if ( F_133 ( V_13 -> V_220 ) )
return - 1 ;
#ifdef F_134
F_135 ( V_13 ) ;
#endif
return 0 ;
}
int F_136 ( struct V_221 * V_179 , void * V_108 )
{
int V_222 = - 1 ;
F_137 ( & V_179 -> V_223 ) ;
if ( V_179 -> V_224 ) {
union V_225 * V_6 = V_179 -> V_224 ;
V_222 = ( V_6 - V_179 -> V_226 ) + V_179 -> V_227 ;
V_179 -> V_224 = V_6 -> V_228 ;
V_6 -> V_108 = V_108 ;
V_179 -> V_229 ++ ;
}
F_138 ( & V_179 -> V_223 ) ;
return V_222 ;
}
void F_139 ( struct V_221 * V_179 , unsigned int V_222 )
{
union V_225 * V_6 = & V_179 -> V_226 [ V_222 - V_179 -> V_227 ] ;
F_137 ( & V_179 -> V_223 ) ;
V_6 -> V_228 = V_179 -> V_224 ;
V_179 -> V_224 = V_6 ;
V_179 -> V_229 -- ;
F_138 ( & V_179 -> V_223 ) ;
}
int F_140 ( struct V_221 * V_179 , int V_230 , void * V_108 )
{
int V_231 ;
F_137 ( & V_179 -> V_232 ) ;
if ( V_230 == V_233 ) {
V_231 = F_141 ( V_179 -> V_234 , V_179 -> V_235 ) ;
if ( V_231 < V_179 -> V_235 )
F_142 ( V_231 , V_179 -> V_234 ) ;
else
V_231 = - 1 ;
} else {
V_231 = F_143 ( V_179 -> V_234 , V_179 -> V_235 , 1 ) ;
if ( V_231 < 0 )
V_231 = - 1 ;
}
if ( V_231 >= 0 ) {
V_179 -> V_236 [ V_231 ] . V_108 = V_108 ;
V_231 += V_179 -> V_237 ;
if ( V_230 == V_233 )
V_179 -> V_238 ++ ;
else
V_179 -> V_238 += 2 ;
}
F_138 ( & V_179 -> V_232 ) ;
return V_231 ;
}
int F_144 ( struct V_221 * V_179 , int V_230 , void * V_108 )
{
int V_231 ;
F_137 ( & V_179 -> V_232 ) ;
if ( V_230 == V_233 ) {
V_231 = F_145 ( V_179 -> V_234 ,
V_179 -> V_235 + V_179 -> V_239 , V_179 -> V_235 ) ;
if ( V_231 < ( V_179 -> V_235 + V_179 -> V_239 ) )
F_142 ( V_231 , V_179 -> V_234 ) ;
else
V_231 = - 1 ;
} else {
V_231 = - 1 ;
}
if ( V_231 >= 0 ) {
V_179 -> V_236 [ V_231 ] . V_108 = V_108 ;
V_231 -= V_179 -> V_235 ;
V_231 += V_179 -> V_240 ;
V_179 -> V_241 ++ ;
}
F_138 ( & V_179 -> V_232 ) ;
return V_231 ;
}
void F_146 ( struct V_221 * V_179 , unsigned int V_231 , int V_230 )
{
if ( V_179 -> V_239 && ( V_231 >= V_179 -> V_240 ) ) {
V_231 -= V_179 -> V_240 ;
V_231 += V_179 -> V_235 ;
} else {
V_231 -= V_179 -> V_237 ;
}
F_137 ( & V_179 -> V_232 ) ;
if ( V_230 == V_233 )
F_147 ( V_231 , V_179 -> V_234 ) ;
else
F_148 ( V_179 -> V_234 , V_231 , 1 ) ;
V_179 -> V_236 [ V_231 ] . V_108 = NULL ;
if ( V_231 < V_179 -> V_235 ) {
if ( V_230 == V_233 )
V_179 -> V_238 -- ;
else
V_179 -> V_238 -= 2 ;
} else {
V_179 -> V_241 -- ;
}
F_138 ( & V_179 -> V_232 ) ;
}
static void F_149 ( struct V_195 * V_196 , unsigned int V_242 ,
unsigned int V_243 )
{
struct V_244 * V_245 ;
F_150 ( V_196 , V_246 , V_242 ) ;
V_245 = (struct V_244 * ) F_151 ( V_196 , sizeof( * V_245 ) ) ;
F_152 ( V_245 , V_243 ) ;
F_153 ( V_245 ) = F_154 ( F_155 ( V_247 , V_243 ) ) ;
}
static void F_156 ( struct V_221 * V_179 , unsigned int V_242 ,
unsigned int V_243 )
{
void * * V_6 = & V_179 -> V_248 [ V_243 ] ;
struct V_12 * V_13 = F_54 ( V_179 , struct V_12 , V_249 ) ;
F_137 ( & V_13 -> V_250 ) ;
* V_6 = V_13 -> V_251 ;
V_13 -> V_251 = ( void * * ) ( ( V_252 ) V_6 | V_242 ) ;
if ( ! V_13 -> V_253 ) {
V_13 -> V_253 = true ;
F_157 ( V_13 -> V_254 , & V_13 -> V_255 ) ;
}
F_138 ( & V_13 -> V_250 ) ;
}
static void F_158 ( struct V_256 * V_257 )
{
struct V_195 * V_196 ;
struct V_12 * V_13 ;
V_13 = F_54 ( V_257 , struct V_12 , V_255 ) ;
F_137 ( & V_13 -> V_250 ) ;
while ( V_13 -> V_251 ) {
void * * V_6 = V_13 -> V_251 ;
unsigned int V_242 = ( V_252 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_242 ;
V_13 -> V_251 = * V_6 ;
* V_6 = NULL ;
F_138 ( & V_13 -> V_250 ) ;
while ( ! ( V_196 = F_159 ( sizeof( struct V_244 ) ,
V_155 ) ) )
F_160 ( 1 ) ;
F_149 ( V_196 , V_242 , V_6 - V_13 -> V_249 . V_248 ) ;
F_161 ( V_13 , V_196 ) ;
F_137 ( & V_13 -> V_250 ) ;
}
V_13 -> V_253 = false ;
F_138 ( & V_13 -> V_250 ) ;
}
void F_162 ( struct V_221 * V_179 , unsigned int V_242 , unsigned int V_243 )
{
struct V_195 * V_196 ;
struct V_12 * V_13 = F_54 ( V_179 , struct V_12 , V_249 ) ;
F_163 ( V_243 >= V_179 -> V_258 ) ;
if ( V_179 -> V_248 [ V_243 ] ) {
V_179 -> V_248 [ V_243 ] = NULL ;
if ( V_179 -> V_259 && ( V_243 >= V_179 -> V_259 ) )
F_164 ( & V_179 -> V_260 ) ;
else
F_164 ( & V_179 -> V_261 ) ;
}
V_196 = F_159 ( sizeof( struct V_244 ) , V_60 ) ;
if ( F_52 ( V_196 ) ) {
F_149 ( V_196 , V_242 , V_243 ) ;
F_161 ( V_13 , V_196 ) ;
} else
F_156 ( V_179 , V_242 , V_243 ) ;
}
static int F_165 ( struct V_221 * V_179 )
{
struct V_12 * V_13 = F_54 ( V_179 , struct V_12 , V_249 ) ;
unsigned int V_262 = V_179 -> V_263 + V_179 -> V_239 ;
unsigned int V_264 = V_179 -> V_264 ;
unsigned int V_265 ;
unsigned int V_266 ;
T_7 V_193 ;
V_265 = F_166 ( V_179 -> V_235 + V_179 -> V_239 ) ;
V_266 = F_166 ( V_179 -> V_263 ) ;
V_193 = V_179 -> V_258 * sizeof( * V_179 -> V_248 ) +
V_264 * sizeof( * V_179 -> V_226 ) +
V_179 -> V_235 * sizeof( * V_179 -> V_236 ) +
V_179 -> V_239 * sizeof( * V_179 -> V_236 ) +
V_265 * sizeof( long ) +
V_262 * sizeof( * V_179 -> V_267 ) +
V_266 * sizeof( long ) ;
V_179 -> V_248 = F_112 ( V_193 ) ;
if ( ! V_179 -> V_248 )
return - V_61 ;
V_179 -> V_226 = (union V_225 * ) & V_179 -> V_248 [ V_179 -> V_258 ] ;
V_179 -> V_236 = (struct V_268 * ) & V_179 -> V_226 [ V_264 ] ;
V_179 -> V_234 = ( unsigned long * ) & V_179 -> V_236 [ V_179 -> V_235 + V_179 -> V_239 ] ;
V_179 -> V_267 = (struct V_269 * ) & V_179 -> V_234 [ V_265 ] ;
V_179 -> V_270 = ( unsigned long * ) & V_179 -> V_267 [ V_262 ] ;
F_167 ( & V_179 -> V_232 ) ;
F_167 ( & V_179 -> V_223 ) ;
F_167 ( & V_179 -> V_271 ) ;
V_179 -> V_238 = 0 ;
V_179 -> V_241 = 0 ;
V_179 -> V_224 = NULL ;
V_179 -> V_229 = 0 ;
F_168 ( & V_179 -> V_261 , 0 ) ;
F_168 ( & V_179 -> V_260 , 0 ) ;
if ( V_264 ) {
while ( -- V_264 )
V_179 -> V_226 [ V_264 - 1 ] . V_228 = & V_179 -> V_226 [ V_264 ] ;
V_179 -> V_224 = V_179 -> V_226 ;
}
if ( F_169 ( V_13 ) ) {
F_99 ( V_179 -> V_234 , V_179 -> V_235 + V_179 -> V_239 ) ;
if ( ! V_179 -> V_237 &&
F_170 ( V_13 -> V_186 . V_190 ) <= V_272 )
F_142 ( 0 , V_179 -> V_234 ) ;
}
F_99 ( V_179 -> V_270 , V_179 -> V_263 ) ;
return 0 ;
}
int F_171 ( const struct V_1 * V_2 , unsigned int V_231 ,
T_10 V_273 , T_11 V_274 , T_11 V_275 ,
unsigned int V_276 )
{
unsigned int V_242 ;
struct V_195 * V_196 ;
struct V_12 * V_13 ;
struct V_277 * V_245 ;
int V_54 ;
V_196 = F_159 ( sizeof( * V_245 ) , V_155 ) ;
if ( ! V_196 )
return - V_61 ;
V_13 = F_172 ( V_2 ) ;
V_245 = (struct V_277 * ) F_151 ( V_196 , sizeof( * V_245 ) ) ;
F_152 ( V_245 , 0 ) ;
F_153 ( V_245 ) = F_154 ( F_155 ( V_278 , V_231 ) ) ;
V_245 -> V_279 = V_274 ;
V_245 -> V_280 = F_121 ( 0 ) ;
V_245 -> V_281 = V_273 ;
V_245 -> V_282 = F_154 ( 0 ) ;
V_242 = F_85 ( & V_13 -> V_16 , V_276 ) ;
V_245 -> V_283 = F_173 ( F_174 ( V_242 ) ) ;
V_245 -> V_284 = F_173 ( F_175 ( V_285 ) |
V_286 | F_176 ( V_276 ) ) ;
V_54 = F_177 ( V_13 , V_196 ) ;
return F_178 ( V_54 ) ;
}
int F_179 ( const struct V_1 * V_2 , unsigned int V_231 ,
const struct V_287 * V_273 , T_11 V_274 ,
unsigned int V_276 )
{
unsigned int V_242 ;
struct V_195 * V_196 ;
struct V_12 * V_13 ;
struct V_288 * V_245 ;
int V_54 ;
V_196 = F_159 ( sizeof( * V_245 ) , V_155 ) ;
if ( ! V_196 )
return - V_61 ;
V_13 = F_172 ( V_2 ) ;
V_245 = (struct V_288 * ) F_151 ( V_196 , sizeof( * V_245 ) ) ;
F_152 ( V_245 , 0 ) ;
F_153 ( V_245 ) = F_154 ( F_155 ( V_289 , V_231 ) ) ;
V_245 -> V_279 = V_274 ;
V_245 -> V_280 = F_121 ( 0 ) ;
V_245 -> V_290 = * ( T_4 * ) ( V_273 -> V_291 ) ;
V_245 -> V_292 = * ( T_4 * ) ( V_273 -> V_291 + 8 ) ;
V_245 -> V_293 = F_173 ( 0 ) ;
V_245 -> V_294 = F_173 ( 0 ) ;
V_242 = F_85 ( & V_13 -> V_16 , V_276 ) ;
V_245 -> V_283 = F_173 ( F_174 ( V_242 ) ) ;
V_245 -> V_284 = F_173 ( F_175 ( V_285 ) |
V_286 | F_176 ( V_276 ) ) ;
V_54 = F_177 ( V_13 , V_196 ) ;
return F_178 ( V_54 ) ;
}
int F_180 ( const struct V_1 * V_2 , unsigned int V_231 ,
unsigned int V_276 , bool V_295 )
{
struct V_195 * V_196 ;
struct V_12 * V_13 ;
struct V_296 * V_245 ;
int V_54 ;
V_13 = F_172 ( V_2 ) ;
V_196 = F_159 ( sizeof( * V_245 ) , V_155 ) ;
if ( ! V_196 )
return - V_61 ;
V_245 = (struct V_296 * ) F_151 ( V_196 , sizeof( * V_245 ) ) ;
F_152 ( V_245 , 0 ) ;
F_153 ( V_245 ) = F_154 ( F_155 ( V_297 , V_231 ) ) ;
V_245 -> V_298 = F_121 ( F_181 ( 0 ) | ( V_295 ? F_182 ( 1 ) :
F_182 ( 0 ) ) | F_183 ( V_276 ) ) ;
V_54 = F_177 ( V_13 , V_196 ) ;
return F_178 ( V_54 ) ;
}
unsigned int F_184 ( const unsigned short * V_299 , unsigned short V_66 ,
unsigned int * V_183 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_300 - 1 && V_299 [ V_19 + 1 ] <= V_66 )
++ V_19 ;
if ( V_183 )
* V_183 = V_19 ;
return V_299 [ V_19 ] ;
}
unsigned int F_185 ( const unsigned short * V_299 ,
unsigned short V_301 ,
unsigned short V_302 ,
unsigned short V_303 ,
unsigned int * V_304 )
{
unsigned short V_305 = V_301 + V_302 ;
unsigned short V_306 = V_303 - 1 ;
int V_307 , V_308 ;
for ( V_307 = 0 , V_308 = - 1 ; V_307 < V_300 ; V_307 ++ ) {
unsigned short V_309 = V_299 [ V_307 ] - V_301 ;
if ( ( V_309 & V_306 ) == 0 )
V_308 = V_307 ;
if ( V_307 + 1 < V_300 && V_299 [ V_307 + 1 ] > V_305 )
break;
}
if ( V_307 == V_300 )
V_307 -- ;
if ( V_308 >= 0 &&
V_307 - V_308 <= 1 )
V_307 = V_308 ;
if ( V_304 )
* V_304 = V_307 ;
return V_299 [ V_307 ] ;
}
unsigned int F_186 ( enum V_310 V_190 , unsigned int V_51 )
{
if ( F_170 ( V_190 ) <= V_272 )
return ( ( V_51 & 0x7f ) << 1 ) ;
else
return ( V_51 & 0x7f ) ;
}
unsigned int F_187 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_76 ;
}
unsigned int F_188 ( const struct V_1 * V_2 , int V_311 )
{
struct V_12 * V_13 = F_172 ( V_2 ) ;
T_1 V_312 , V_313 , V_314 , V_315 ;
V_312 = F_68 ( V_13 , V_316 ) ;
V_313 = F_68 ( V_13 , V_317 ) ;
if ( F_109 ( V_13 -> V_186 . V_190 ) ) {
V_314 = F_189 ( V_312 ) ;
V_315 = F_190 ( V_312 ) ;
} else {
V_314 = F_191 ( V_312 ) ;
V_315 = F_192 ( V_313 ) ;
}
return V_311 ? V_314 : V_315 ;
}
unsigned int F_193 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_51 ;
}
unsigned int F_194 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_31 ;
}
void F_195 ( struct V_318 * V_127 , struct V_319 * V_320 ,
struct V_319 * V_321 )
{
struct V_12 * V_13 = F_196 ( V_127 ) ;
F_197 ( & V_13 -> V_322 ) ;
F_198 ( V_13 , V_320 , V_321 ) ;
F_199 ( & V_13 -> V_322 ) ;
}
void F_200 ( struct V_1 * V_2 , unsigned int V_323 ,
const unsigned int * V_324 )
{
struct V_12 * V_13 = F_172 ( V_2 ) ;
F_70 ( V_13 , V_325 , V_323 ) ;
F_70 ( V_13 , V_326 , F_201 ( V_324 [ 0 ] ) |
F_202 ( V_324 [ 1 ] ) | F_203 ( V_324 [ 2 ] ) |
F_204 ( V_324 [ 3 ] ) ) ;
}
int F_205 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_172 ( V_2 ) ;
return F_206 ( V_13 , V_13 -> V_27 ) ;
}
static int F_207 ( struct V_12 * V_13 , T_6 V_95 , T_6 * V_327 , T_6 * V_328 )
{
T_1 V_50 = F_68 ( V_13 , V_329 ) + 24 * V_95 + 8 ;
T_4 V_330 ;
int V_54 ;
F_197 ( & V_13 -> V_331 ) ;
V_54 = F_208 ( V_13 , 0 , V_332 , V_50 ,
sizeof( V_330 ) , ( T_10 * ) & V_330 ,
V_333 ) ;
F_199 ( & V_13 -> V_331 ) ;
if ( ! V_54 ) {
* V_328 = ( F_209 ( V_330 ) >> 25 ) & 0xffff ;
* V_327 = ( F_209 ( V_330 ) >> 9 ) & 0xffff ;
}
return V_54 ;
}
int F_210 ( struct V_1 * V_2 , T_6 V_95 , T_6 V_327 ,
T_6 V_193 )
{
struct V_12 * V_13 = F_172 ( V_2 ) ;
T_6 V_334 , V_335 ;
int V_54 ;
V_54 = F_207 ( V_13 , V_95 , & V_334 , & V_335 ) ;
if ( V_54 )
goto V_59;
if ( V_327 != V_334 ) {
T_6 V_207 ;
T_1 V_336 ;
if ( V_327 >= V_334 )
V_207 = V_327 - V_334 ;
else
V_207 = V_193 - V_334 + V_327 ;
if ( F_109 ( V_13 -> V_186 . V_190 ) )
V_336 = F_211 ( V_207 ) ;
else
V_336 = F_212 ( V_207 ) ;
F_213 () ;
F_70 ( V_13 , F_69 ( V_337 ) ,
F_214 ( V_95 ) | V_336 ) ;
}
V_59:
return V_54 ;
}
int F_215 ( struct V_1 * V_2 , T_1 V_338 , T_10 * V_339 )
{
struct V_12 * V_13 ;
T_1 V_340 , V_341 , V_342 ;
T_1 V_343 , V_344 , V_345 , V_346 , V_193 ;
T_1 V_347 , V_348 , V_349 , V_350 ;
int V_54 ;
V_13 = F_172 ( V_2 ) ;
V_340 = ( ( V_338 >> 8 ) * 32 ) + V_13 -> V_351 . V_338 . V_352 ;
V_193 = F_68 ( V_13 , V_353 ) ;
V_343 = F_216 ( V_193 ) << 20 ;
V_193 = F_68 ( V_13 , V_354 ) ;
V_344 = F_217 ( V_193 ) << 20 ;
V_193 = F_68 ( V_13 , V_355 ) ;
V_345 = F_218 ( V_193 ) << 20 ;
V_347 = V_343 ;
V_348 = V_347 + V_344 ;
V_349 = V_348 + V_345 ;
if ( V_340 < V_347 ) {
V_341 = V_332 ;
V_342 = V_340 ;
} else if ( V_340 < V_348 ) {
V_341 = V_356 ;
V_342 = V_340 - V_347 ;
} else {
if ( V_340 < V_349 ) {
V_341 = V_357 ;
V_342 = V_340 - V_348 ;
} else if ( F_219 ( V_13 -> V_186 . V_190 ) ) {
V_193 = F_68 ( V_13 , V_358 ) ;
V_346 = F_220 ( V_193 ) << 20 ;
V_350 = V_349 + V_346 ;
if ( V_340 < V_350 ) {
V_341 = V_359 ;
V_342 = V_340 - V_349 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_197 ( & V_13 -> V_331 ) ;
V_54 = F_208 ( V_13 , 0 , V_341 , V_342 , 32 , V_339 , V_333 ) ;
F_199 ( & V_13 -> V_331 ) ;
return V_54 ;
V_22:
F_11 ( V_13 -> V_30 , L_33 ,
V_338 , V_340 ) ;
return - V_65 ;
}
T_2 F_221 ( struct V_1 * V_2 )
{
T_1 V_360 , V_361 ;
struct V_12 * V_13 ;
V_13 = F_172 ( V_2 ) ;
V_361 = F_68 ( V_13 , V_362 ) ;
V_360 = F_222 ( F_68 ( V_13 , V_363 ) ) ;
return ( ( T_2 ) V_360 << 32 ) | ( T_2 ) V_361 ;
}
int F_223 ( struct V_1 * V_2 ,
unsigned int V_95 ,
enum V_364 V_365 ,
int V_366 ,
T_2 * V_367 ,
unsigned int * V_368 )
{
return F_224 ( F_172 ( V_2 ) ,
V_95 ,
( V_365 == V_369
? V_370
: V_371 ) ,
V_366 ,
V_367 ,
V_368 ) ;
}
static void F_225 ( struct V_372 * V_373 )
{
const struct V_374 * V_375 ;
const struct V_1 * V_52 = V_373 -> V_2 ;
if ( V_52 -> V_376 & V_377 )
V_52 = F_226 ( V_52 ) ;
V_375 = V_52 -> V_2 . V_375 ;
if ( V_375 && V_375 -> V_378 == & V_379 . V_378 )
F_227 ( F_228 ( V_375 ) , V_373 ) ;
}
static int F_229 ( struct V_380 * V_381 , unsigned long V_382 ,
void * V_108 )
{
switch ( V_382 ) {
case V_383 :
F_225 ( V_108 ) ;
break;
case V_384 :
default:
break;
}
return 0 ;
}
static void F_230 ( struct V_12 * V_13 , int V_385 )
{
T_1 V_312 , V_313 , V_314 , V_315 ;
do {
V_312 = F_68 ( V_13 , V_316 ) ;
V_313 = F_68 ( V_13 , V_317 ) ;
if ( F_109 ( V_13 -> V_186 . V_190 ) ) {
V_314 = F_189 ( V_312 ) ;
V_315 = F_190 ( V_312 ) ;
} else {
V_314 = F_191 ( V_312 ) ;
V_315 = F_192 ( V_313 ) ;
}
if ( V_314 == 0 && V_315 == 0 )
break;
F_231 ( V_386 ) ;
F_232 ( F_233 ( V_385 ) ) ;
} while ( 1 );
}
static void F_234 ( struct V_97 * V_25 )
{
unsigned long V_68 ;
F_235 ( & V_25 -> V_387 , V_68 ) ;
V_25 -> V_388 = 1 ;
F_236 ( & V_25 -> V_387 , V_68 ) ;
}
static void F_237 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
F_238 ( & V_25 -> V_387 ) ;
if ( V_25 -> V_389 ) {
F_213 () ;
F_70 ( V_13 , F_69 ( V_337 ) ,
F_214 ( V_25 -> V_26 ) | F_211 ( V_25 -> V_389 ) ) ;
V_25 -> V_389 = 0 ;
}
V_25 -> V_388 = 0 ;
F_239 ( & V_25 -> V_387 ) ;
}
static void F_240 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_234 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_106 (&adap->sge, i)
F_234 ( & V_13 -> V_16 . V_101 [ V_19 ] . V_25 ) ;
F_73 (adap, i)
F_234 ( & V_13 -> V_16 . V_189 [ V_19 ] . V_25 ) ;
}
static void F_241 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_237 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_106 (&adap->sge, i)
F_237 ( V_13 , & V_13 -> V_16 . V_101 [ V_19 ] . V_25 ) ;
F_73 (adap, i)
F_237 ( V_13 , & V_13 -> V_16 . V_189 [ V_19 ] . V_25 ) ;
}
static void F_242 ( struct V_12 * V_13 , enum V_390 V_109 )
{
enum V_391 type = V_177 ;
if ( V_13 -> V_392 && V_13 -> V_392 [ type ] . V_393 )
V_13 -> V_392 [ type ] . F_243 ( V_13 -> V_392 [ type ] . V_393 , V_109 ) ;
}
static void F_244 ( struct V_256 * V_257 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_257 , struct V_12 , V_394 ) ;
F_230 ( V_13 , V_395 ) ;
F_241 ( V_13 ) ;
F_242 ( V_13 , V_396 ) ;
if ( F_170 ( V_13 -> V_186 . V_190 ) <= V_272 )
F_245 ( V_13 , V_397 ,
V_398 | V_399 ,
V_398 | V_399 ) ;
else
F_245 ( V_13 , V_397 ,
V_399 , V_399 ) ;
}
static void F_246 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
T_6 V_334 , V_335 ;
int V_54 ;
F_238 ( & V_25 -> V_387 ) ;
V_54 = F_207 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_334 , & V_335 ) ;
if ( V_54 )
goto V_59;
if ( V_25 -> V_400 != V_334 ) {
T_6 V_207 ;
T_1 V_336 ;
if ( V_25 -> V_400 >= V_334 )
V_207 = V_25 -> V_400 - V_334 ;
else
V_207 = V_25 -> V_193 - V_334 + V_25 -> V_400 ;
if ( F_109 ( V_13 -> V_186 . V_190 ) )
V_336 = F_211 ( V_207 ) ;
else
V_336 = F_212 ( V_207 ) ;
F_213 () ;
F_70 ( V_13 , F_69 ( V_337 ) ,
F_214 ( V_25 -> V_26 ) | V_336 ) ;
}
V_59:
V_25 -> V_388 = 0 ;
V_25 -> V_389 = 0 ;
F_239 ( & V_25 -> V_387 ) ;
if ( V_54 )
F_247 ( V_13 , L_34 ) ;
}
static void F_248 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_246 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_106 (&adap->sge, i)
F_246 ( V_13 , & V_13 -> V_16 . V_101 [ V_19 ] . V_25 ) ;
F_73 (adap, i)
F_246 ( V_13 , & V_13 -> V_16 . V_189 [ V_19 ] . V_25 ) ;
}
static void F_249 ( struct V_256 * V_257 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_257 , struct V_12 , V_401 ) ;
if ( F_109 ( V_13 -> V_186 . V_190 ) ) {
F_230 ( V_13 , V_395 ) ;
F_242 ( V_13 , V_402 ) ;
F_230 ( V_13 , V_395 ) ;
F_248 ( V_13 ) ;
F_230 ( V_13 , V_395 ) ;
F_241 ( V_13 ) ;
F_242 ( V_13 , V_396 ) ;
} else if ( F_219 ( V_13 -> V_186 . V_190 ) ) {
T_1 V_403 = F_68 ( V_13 , 0x010ac ) ;
T_6 V_95 = ( V_403 >> 15 ) & 0x1ffff ;
T_6 V_404 = V_403 & 0x1fff ;
T_2 V_405 ;
unsigned int V_406 ;
int V_54 ;
V_54 = F_224 ( V_13 , V_95 , V_370 ,
0 , & V_405 , & V_406 ) ;
if ( V_54 )
F_11 ( V_13 -> V_30 , L_35
L_36 , V_95 , V_404 ) ;
else
F_250 ( F_212 ( V_404 ) | F_214 ( V_406 ) ,
V_13 -> V_407 + V_405 + V_408 ) ;
F_245 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_170 ( V_13 -> V_186 . V_190 ) <= V_272 )
F_245 ( V_13 , V_409 , V_410 , 0 ) ;
}
void F_251 ( struct V_12 * V_13 )
{
if ( F_109 ( V_13 -> V_186 . V_190 ) ) {
F_240 ( V_13 ) ;
F_242 ( V_13 , V_411 ) ;
F_245 ( V_13 , V_397 ,
V_398 | V_399 , 0 ) ;
F_157 ( V_13 -> V_254 , & V_13 -> V_394 ) ;
}
}
void F_252 ( struct V_12 * V_13 )
{
if ( F_109 ( V_13 -> V_186 . V_190 ) ) {
F_240 ( V_13 ) ;
F_242 ( V_13 , V_411 ) ;
}
F_157 ( V_13 -> V_254 , & V_13 -> V_401 ) ;
}
void F_253 ( void )
{
if ( ! V_412 ) {
F_254 ( & V_413 ) ;
V_412 = true ;
}
}
static void F_255 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_256 ( & V_414 ) ;
F_33 ( & V_13 -> V_415 ) ;
for ( V_19 = 0 ; V_19 < V_416 ; V_19 ++ )
if ( V_13 -> V_392 && V_13 -> V_392 [ V_19 ] . V_393 ) {
V_13 -> V_392 [ V_19 ] . F_257 ( V_13 -> V_392 [ V_19 ] . V_393 ,
V_417 ) ;
V_13 -> V_392 [ V_19 ] . V_393 = NULL ;
}
if ( V_412 && F_258 ( & V_418 ) ) {
F_259 ( & V_413 ) ;
V_412 = false ;
}
F_260 ( & V_414 ) ;
}
static void F_261 ( struct V_12 * V_13 , enum V_419 V_420 )
{
unsigned int V_19 ;
F_256 ( & V_414 ) ;
for ( V_19 = 0 ; V_19 < V_416 ; V_19 ++ )
if ( V_13 -> V_392 && V_13 -> V_392 [ V_19 ] . V_393 )
V_13 -> V_392 [ V_19 ] . F_257 ( V_13 -> V_392 [ V_19 ] . V_393 ,
V_420 ) ;
F_260 ( & V_414 ) ;
}
static int F_262 ( struct V_380 * V_421 ,
unsigned long V_382 , void * V_108 )
{
struct V_422 * V_423 = V_108 ;
struct V_1 * V_424 = V_423 -> V_425 -> V_2 ;
const struct V_374 * V_375 = NULL ;
#if F_263 ( V_426 )
struct V_12 * V_13 ;
#endif
if ( V_424 -> V_376 & V_377 )
V_424 = F_226 ( V_424 ) ;
#if F_263 ( V_426 )
if ( V_424 -> V_68 & V_427 ) {
F_22 (adap, &adapter_list, list_node) {
switch ( V_382 ) {
case V_428 :
F_264 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_423 , 1 ) ;
break;
case V_429 :
F_265 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_423 , 1 ) ;
break;
default:
break;
}
}
return V_430 ;
}
#endif
if ( V_424 )
V_375 = V_424 -> V_2 . V_375 ;
if ( V_375 && V_375 -> V_378 == & V_379 . V_378 ) {
switch ( V_382 ) {
case V_428 :
F_264 ( V_424 , ( const T_1 * ) V_423 , 1 ) ;
break;
case V_429 :
F_265 ( V_424 , ( const T_1 * ) V_423 , 1 ) ;
break;
default:
break;
}
}
return V_430 ;
}
static void F_266 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_54 ;
F_267 () ;
for ( V_19 = 0 ; V_19 < V_431 ; V_19 ++ ) {
V_2 = V_13 -> V_39 [ V_19 ] ;
V_54 = 0 ;
if ( V_2 )
V_54 = F_268 ( V_2 ) ;
if ( V_54 < 0 )
break;
}
F_269 () ;
}
static int F_270 ( struct V_12 * V_13 )
{
int V_22 ;
V_22 = F_102 ( V_13 ) ;
if ( V_22 )
goto V_59;
V_22 = F_83 ( V_13 ) ;
if ( V_22 )
goto V_432;
if ( V_13 -> V_68 & V_126 ) {
F_72 ( V_13 ) ;
V_22 = F_75 ( V_13 -> V_140 [ 0 ] . V_46 , F_67 , 0 ,
V_13 -> V_140 [ 0 ] . V_141 , V_13 ) ;
if ( V_22 )
goto V_433;
V_22 = F_74 ( V_13 ) ;
if ( V_22 ) {
F_77 ( V_13 -> V_140 [ 0 ] . V_46 , V_13 ) ;
goto V_433;
}
} else {
V_22 = F_75 ( V_13 -> V_127 -> V_129 , F_271 ( V_13 ) ,
( V_13 -> V_68 & V_128 ) ? 0 : V_434 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_433;
}
F_93 ( V_13 ) ;
F_272 ( V_13 ) ;
F_273 ( V_13 ) ;
V_13 -> V_68 |= V_167 ;
F_261 ( V_13 , V_435 ) ;
#if F_263 ( V_436 )
F_266 ( V_13 ) ;
#endif
F_274 ( & V_13 -> V_63 ) ;
V_59:
return V_22 ;
V_433:
F_11 ( V_13 -> V_30 , L_37 , V_22 ) ;
V_432:
F_101 ( V_13 ) ;
goto V_59;
}
static void F_275 ( struct V_12 * V_12 )
{
F_276 ( & V_12 -> V_255 ) ;
F_276 ( & V_12 -> V_394 ) ;
F_276 ( & V_12 -> V_401 ) ;
V_12 -> V_253 = false ;
V_12 -> V_251 = NULL ;
F_277 ( V_12 ) ;
F_101 ( V_12 ) ;
V_12 -> V_68 &= ~ V_167 ;
}
static int F_278 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_18 ( V_2 ) ;
if ( ! ( V_12 -> V_68 & V_167 ) ) {
V_22 = F_270 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
F_279 ( V_2 ) ;
return V_22 ;
}
static int F_280 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_281 ( V_2 ) ;
F_18 ( V_2 ) ;
return F_282 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , false , false ) ;
}
int F_283 ( const struct V_1 * V_2 , unsigned int V_231 ,
T_10 V_273 , T_11 V_274 , T_11 V_275 ,
unsigned int V_276 , unsigned char V_39 , unsigned char V_437 )
{
int V_54 ;
struct V_269 * V_438 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_336 ;
V_13 = F_172 ( V_2 ) ;
V_231 -= V_13 -> V_249 . V_240 ;
V_231 += V_13 -> V_249 . V_263 ;
V_438 = & V_13 -> V_249 . V_267 [ V_231 ] ;
V_54 = F_284 ( V_438 ) ;
if ( V_54 )
return V_54 ;
if ( V_438 -> V_439 )
F_285 ( V_13 , V_438 ) ;
memset ( & V_438 -> V_440 , 0 , sizeof( struct V_441 ) ) ;
V_438 -> V_440 . V_336 . V_442 = F_286 ( V_274 ) ;
V_438 -> V_440 . V_437 . V_442 = ~ 0 ;
V_336 = ( T_3 * ) & V_273 ;
if ( ( V_336 [ 0 ] | V_336 [ 1 ] | V_336 [ 2 ] | V_336 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_438 -> V_440 . V_336 . V_443 [ V_19 ] = V_336 [ V_19 ] ;
V_438 -> V_440 . V_437 . V_443 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_186 . V_444 . V_445 & V_446 ) {
V_438 -> V_440 . V_336 . V_447 = V_39 ;
V_438 -> V_440 . V_437 . V_447 = V_437 ;
}
}
if ( V_13 -> V_186 . V_444 . V_445 & V_448 ) {
V_438 -> V_440 . V_336 . V_449 = V_450 ;
V_438 -> V_440 . V_437 . V_449 = ~ 0 ;
}
V_438 -> V_440 . V_451 = 1 ;
V_438 -> V_440 . V_452 = V_276 ;
V_438 -> V_453 = 1 ;
V_438 -> V_440 . V_454 = 1 ;
V_54 = F_287 ( V_13 , V_231 ) ;
if ( V_54 ) {
F_285 ( V_13 , V_438 ) ;
return V_54 ;
}
return 0 ;
}
int F_288 ( const struct V_1 * V_2 , unsigned int V_231 ,
unsigned int V_276 , bool V_295 )
{
struct V_269 * V_438 ;
struct V_12 * V_13 ;
V_13 = F_172 ( V_2 ) ;
V_231 -= V_13 -> V_249 . V_240 ;
V_231 += V_13 -> V_249 . V_263 ;
V_438 = & V_13 -> V_249 . V_267 [ V_231 ] ;
V_438 -> V_453 = 0 ;
return F_289 ( V_13 , V_231 ) ;
}
static struct V_455 * F_290 ( struct V_1 * V_2 ,
struct V_455 * V_456 )
{
struct V_457 V_184 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_197 ( & V_12 -> V_322 ) ;
if ( ! F_291 ( V_2 ) ) {
F_199 ( & V_12 -> V_322 ) ;
return V_456 ;
}
F_292 ( V_12 , V_6 -> V_76 , & V_184 ,
& V_6 -> V_458 ) ;
F_199 ( & V_12 -> V_322 ) ;
V_456 -> V_459 = V_184 . V_460 ;
V_456 -> V_461 = V_184 . V_462 ;
V_456 -> V_463 = V_184 . V_464 ;
V_456 -> V_465 = V_184 . V_466 ;
V_456 -> V_467 = V_184 . V_468 ;
V_456 -> V_469 = V_184 . V_470 + V_184 . V_471 +
V_184 . V_472 ;
V_456 -> V_473 = 0 ;
V_456 -> V_474 = V_184 . V_475 ;
V_456 -> V_476 = V_184 . V_477 ;
V_456 -> V_478 = V_184 . V_479 + V_184 . V_480 +
V_184 . V_481 + V_184 . V_482 +
V_184 . V_483 + V_184 . V_484 +
V_184 . V_485 + V_184 . V_486 ;
V_456 -> V_487 = 0 ;
V_456 -> V_488 = 0 ;
V_456 -> V_489 = 0 ;
V_456 -> V_490 = 0 ;
V_456 -> V_491 = 0 ;
V_456 -> V_492 = 0 ;
V_456 -> V_493 = V_184 . V_494 ;
V_456 -> V_495 = V_184 . V_477 + V_184 . V_475 +
V_456 -> V_469 + V_184 . V_496 + V_456 -> V_478 ;
return V_456 ;
}
static int F_293 ( struct V_1 * V_2 , struct V_497 * V_245 , int V_109 )
{
unsigned int V_27 ;
int V_54 = 0 , V_498 , V_499 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_500 * V_108 = (struct V_500 * ) & V_245 -> V_501 ;
switch ( V_109 ) {
case V_502 :
if ( V_11 -> V_503 < 0 )
return - V_504 ;
V_108 -> V_505 = V_11 -> V_503 ;
break;
case V_506 :
case V_507 :
if ( F_294 ( V_108 -> V_505 ) ) {
V_498 = F_295 ( V_108 -> V_505 ) ;
V_499 = F_296 ( V_108 -> V_505 ) ;
} else if ( V_108 -> V_505 < 32 ) {
V_498 = V_108 -> V_505 ;
V_499 = 0 ;
V_108 -> V_508 &= 0x1f ;
} else
return - V_65 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_109 == V_506 )
V_54 = F_297 ( V_11 -> V_12 , V_27 , V_498 , V_499 ,
V_108 -> V_508 , & V_108 -> V_509 ) ;
else
V_54 = F_298 ( V_11 -> V_12 , V_27 , V_498 , V_499 ,
V_108 -> V_508 , V_108 -> V_510 ) ;
break;
case V_511 :
return F_299 ( V_245 -> V_501 , & V_11 -> V_512 ,
sizeof( V_11 -> V_512 ) ) ?
- V_513 : 0 ;
case V_514 :
if ( F_300 ( & V_11 -> V_512 , V_245 -> V_501 ,
sizeof( V_11 -> V_512 ) ) )
return - V_513 ;
switch ( V_11 -> V_512 . V_515 ) {
case V_516 :
V_11 -> V_517 = false ;
break;
case V_518 :
V_11 -> V_517 = true ;
break;
default:
V_11 -> V_512 . V_515 = V_516 ;
return - V_519 ;
}
return F_299 ( V_245 -> V_501 , & V_11 -> V_512 ,
sizeof( V_11 -> V_512 ) ) ?
- V_513 : 0 ;
default:
return - V_504 ;
}
return V_54 ;
}
static void F_301 ( struct V_1 * V_2 )
{
F_36 ( V_2 , - 1 , false ) ;
}
static int F_302 ( struct V_1 * V_2 , int V_520 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_520 < 81 || V_520 > V_521 )
return - V_65 ;
V_54 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , V_520 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_54 )
V_2 -> V_66 = V_520 ;
return V_54 ;
}
static int F_303 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
return 0 ;
}
static void F_304 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
T_3 V_522 [ V_523 ] , V_524 [ V_523 ] ;
int V_22 ;
T_3 * V_525 ;
T_6 V_526 , V_527 ;
V_22 = F_305 ( V_13 , & V_13 -> V_186 . V_528 ) ;
if ( ! V_22 ) {
V_525 = V_13 -> V_186 . V_528 . V_525 ;
for ( V_19 = 0 ; V_19 < V_523 ; V_19 ++ )
V_522 [ V_19 ] = ( F_306 ( V_525 [ 2 * V_19 + 0 ] ) * 16 +
F_306 ( V_525 [ 2 * V_19 + 1 ] ) ) ;
V_526 = ( V_522 [ 0 ] << 8 ) | V_522 [ 1 ] ;
V_527 = ( V_522 [ 1 ] << 8 ) | V_522 [ 2 ] ;
V_526 ^= V_527 ;
V_526 |= 0x0200 ;
V_526 &= ~ 0x0100 ;
V_524 [ 0 ] = V_526 >> 8 ;
V_524 [ 1 ] = V_526 & 0xff ;
for ( V_19 = 2 ; V_19 < 5 ; V_19 ++ )
V_524 [ V_19 ] = V_522 [ V_19 + 1 ] ;
for ( V_19 = 0 ; V_19 < V_13 -> V_529 ; V_19 ++ ) {
V_524 [ 5 ] = V_13 -> V_28 * 16 + V_19 ;
F_28 ( V_13 -> V_530 [ V_19 ] . V_531 , V_524 ) ;
}
}
}
static int F_307 ( struct V_1 * V_2 , int V_532 , T_3 * V_533 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
if ( ! F_308 ( V_533 ) ) {
F_11 ( V_11 -> V_12 -> V_30 ,
L_38 ,
V_533 , V_532 ) ;
return - V_65 ;
}
F_309 ( V_11 -> V_12 -> V_30 ,
L_39 , V_533 , V_532 ) ;
V_54 = F_310 ( V_13 , V_532 + 1 , 1 , V_533 ) ;
if ( ! V_54 )
F_28 ( V_13 -> V_530 [ V_532 ] . V_531 , V_533 ) ;
return V_54 ;
}
static int F_311 ( struct V_1 * V_2 ,
int V_532 , struct V_534 * V_535 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_532 >= V_13 -> V_529 )
return - V_65 ;
V_535 -> V_532 = V_532 ;
F_28 ( V_535 -> V_533 , V_13 -> V_530 [ V_532 ] . V_531 ) ;
return 0 ;
}
static int F_312 ( struct V_1 * V_2 , void * V_6 )
{
int V_54 ;
struct V_536 * V_50 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_308 ( V_50 -> V_537 ) )
return - V_538 ;
V_54 = F_41 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 ,
V_11 -> V_74 , V_50 -> V_537 , true , true ) ;
if ( V_54 < 0 )
return V_54 ;
memcpy ( V_2 -> V_75 , V_50 -> V_537 , V_2 -> V_539 ) ;
V_11 -> V_74 = V_54 ;
return 0 ;
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_68 & V_126 ) {
int V_19 ;
struct V_152 * V_540 = & V_13 -> V_16 . V_147 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_540 ++ )
V_145 ( 0 , & V_540 -> V_148 ) ;
} else
F_271 ( V_13 ) ( 0 , V_13 ) ;
}
static int F_314 ( struct V_1 * V_2 , int V_541 , T_1 V_542 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_543 * V_544 ;
struct V_545 V_6 ;
struct V_546 V_547 ;
T_1 V_548 ;
int V_22 = 0 ;
if ( ! F_315 ( V_2 ) )
return - V_549 ;
if ( V_541 < 0 || V_541 > V_11 -> V_20 - 1 )
return - V_65 ;
if ( ! ( V_13 -> V_68 & V_167 ) ) {
F_11 ( V_13 -> V_30 ,
L_40 ,
V_541 ) ;
return - V_65 ;
}
V_548 = V_542 << 10 ;
if ( V_548 >= V_550 ) {
F_11 ( V_13 -> V_30 ,
L_41 ,
V_542 , V_550 ) ;
return - V_519 ;
}
memset ( & V_547 , 0 , sizeof( V_547 ) ) ;
V_547 . V_276 = V_541 ;
V_547 . V_551 = V_552 ;
V_22 = F_316 ( V_2 , ( void * ) ( & V_547 ) , V_553 ) ;
if ( V_22 ) {
F_11 ( V_13 -> V_30 ,
L_42 ,
V_541 , V_11 -> V_31 , V_22 ) ;
return V_22 ;
}
if ( ! V_548 )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_554 ;
V_6 . V_115 . V_186 . V_555 = V_556 ;
V_6 . V_115 . V_186 . V_557 = V_558 ;
V_6 . V_115 . V_186 . V_559 = V_560 ;
V_6 . V_115 . V_186 . V_561 = V_562 ;
V_6 . V_115 . V_186 . V_563 = V_11 -> V_76 ;
V_6 . V_115 . V_186 . V_551 = V_552 ;
V_6 . V_115 . V_186 . V_564 = 0 ;
V_6 . V_115 . V_186 . V_565 = V_548 ;
V_6 . V_115 . V_186 . V_566 = 0 ;
V_6 . V_115 . V_186 . V_567 = V_2 -> V_66 ;
V_544 = F_317 ( V_2 , & V_6 ) ;
if ( ! V_544 )
return - V_61 ;
memset ( & V_547 , 0 , sizeof( V_547 ) ) ;
V_547 . V_276 = V_541 ;
V_547 . V_551 = V_544 -> V_183 ;
V_22 = F_318 ( V_2 , ( void * ) ( & V_547 ) , V_553 ) ;
if ( V_22 )
F_11 ( V_13 -> V_30 ,
L_43 , V_22 ) ;
return V_22 ;
}
static int F_319 ( struct V_1 * V_2 , T_1 V_393 , T_11 V_449 ,
struct V_568 * V_569 )
{
struct V_5 * V_11 = F_86 ( V_2 ) ;
struct V_12 * V_13 = F_172 ( V_2 ) ;
if ( ! ( V_13 -> V_68 & V_167 ) ) {
F_11 ( V_13 -> V_30 ,
L_44 ,
V_11 -> V_31 ) ;
return - V_65 ;
}
if ( F_320 ( V_393 ) == F_320 ( V_570 ) &&
V_569 -> type == V_571 ) {
switch ( V_569 -> V_572 -> V_573 ) {
case V_574 :
case V_575 :
return F_321 ( V_2 , V_449 , V_569 -> V_572 ) ;
case V_576 :
return F_322 ( V_2 , V_449 , V_569 -> V_572 ) ;
default:
return - V_504 ;
}
}
return - V_504 ;
}
static void F_323 ( struct V_1 * V_2 , struct V_577 * V_116 )
{
struct V_12 * V_12 = F_172 ( V_2 ) ;
F_324 ( V_116 -> V_378 , V_578 , sizeof( V_116 -> V_378 ) ) ;
F_324 ( V_116 -> V_579 , V_580 ,
sizeof( V_116 -> V_579 ) ) ;
F_324 ( V_116 -> V_581 , F_325 ( V_12 -> V_127 ) ,
sizeof( V_116 -> V_581 ) ) ;
}
void F_326 ( struct V_12 * V_13 )
{
F_245 ( V_13 , V_582 , V_583 , 0 ) ;
F_92 ( V_13 ) ;
F_327 ( V_13 -> V_30 , L_45 ) ;
}
static void F_328 ( struct V_12 * V_13 )
{
T_1 V_584 = F_329 ( V_13 ) ;
F_330 ( V_13 , V_584 , V_585 ) ;
}
static void F_331 ( struct V_12 * V_13 )
{
if ( V_13 -> V_351 . V_586 . V_193 ) {
T_1 V_352 ;
unsigned int V_587 ;
V_352 = F_332 ( V_13 , V_588 ) ;
V_352 &= V_589 ;
V_352 += F_333 ( V_13 -> V_127 , & V_13 -> V_351 ) ;
V_587 = F_334 ( V_13 -> V_351 . V_586 . V_193 ) >> 10 ;
F_70 ( V_13 ,
F_335 ( V_590 , 3 ) ,
V_352 | F_336 ( 1 ) | F_337 ( F_338 ( V_587 ) ) ) ;
F_70 ( V_13 ,
F_335 ( V_591 , 3 ) ,
V_13 -> V_351 . V_586 . V_352 ) ;
F_68 ( V_13 ,
F_335 ( V_591 , 3 ) ) ;
}
}
static int F_339 ( struct V_12 * V_13 , struct V_592 * V_593 )
{
T_1 V_131 ;
int V_54 ;
memset ( V_593 , 0 , sizeof( * V_593 ) ) ;
V_593 -> V_594 = F_154 ( F_340 ( V_595 ) |
V_596 | V_597 ) ;
V_593 -> V_598 = F_154 ( F_341 ( * V_593 ) ) ;
V_54 = F_342 ( V_13 , V_13 -> V_27 , V_593 , sizeof( * V_593 ) , V_593 ) ;
if ( V_54 < 0 )
return V_54 ;
V_593 -> V_594 = F_154 ( F_340 ( V_595 ) |
V_596 | V_599 ) ;
V_54 = F_342 ( V_13 , V_13 -> V_27 , V_593 , sizeof( * V_593 ) , NULL ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_343 ( V_13 , V_13 -> V_28 ,
V_600 ,
V_601 |
V_602 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_344 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_171 , 64 ,
V_603 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_604 ,
V_604 ) ;
if ( V_54 < 0 )
return V_54 ;
F_345 ( V_13 ) ;
F_70 ( V_13 , V_605 , 0x64f8849 ) ;
F_70 ( V_13 , V_606 , F_201 ( V_607 - 12 ) ) ;
F_70 ( V_13 , V_608 , V_609 ) ;
V_131 = F_68 ( V_13 , V_610 ) ;
F_70 ( V_13 , V_610 , V_131 & ~ V_611 ) ;
V_13 -> V_186 . V_444 . V_612 = 0xE4 ;
F_70 ( V_13 , V_613 ,
F_346 ( V_13 -> V_186 . V_444 . V_612 ) ) ;
V_131 = 0x84218421 ;
F_347 ( V_13 , V_608 , V_610 ,
& V_131 , 1 , V_614 ) ;
F_347 ( V_13 , V_608 , V_610 ,
& V_131 , 1 , V_615 ) ;
F_347 ( V_13 , V_608 , V_610 ,
& V_131 , 1 , V_616 ) ;
#define F_348 16
if ( F_169 ( V_13 ) ) {
F_70 ( V_13 , V_617 ,
F_349 ( F_348 ) |
F_350 ( F_348 ) |
F_351 ( F_348 ) |
F_352 ( F_348 ) ) ;
F_70 ( V_13 , V_618 ,
F_349 ( F_348 ) |
F_350 ( F_348 ) |
F_351 ( F_348 ) |
F_352 ( F_348 ) ) ;
}
return F_353 ( V_13 , V_13 -> V_28 ) ;
}
static int F_354 ( struct V_12 * V_12 )
{
F_355 ( V_12 , V_619 , V_620 ) ;
if ( V_621 != 2 && V_621 != 0 ) {
F_11 ( & V_12 -> V_127 -> V_2 ,
L_46 ,
V_621 ) ;
V_621 = 2 ;
}
F_245 ( V_12 , V_582 ,
F_356 ( V_622 ) ,
F_356 ( V_621 ) ) ;
F_357 ( V_12 , V_609 ,
V_611 , 0 ) ;
return 0 ;
}
static int F_358 ( const T_3 * V_623 ,
T_7 V_624 )
{
int V_340 ;
#define F_359 ( T_12 ) (((__p)[0] << 8) | (__p)[1])
#define F_360 ( T_12 ) ((__p)[0] | ((__p)[1] << 8))
#define F_361 ( T_12 ) (le16(__p) | ((__p)[2] << 16))
V_340 = F_361 ( V_623 + 0x8 ) << 12 ;
V_340 = F_361 ( V_623 + V_340 + 0xa ) ;
return F_359 ( V_623 + V_340 + 0x27e ) ;
#undef F_359
#undef F_360
#undef F_361
}
static struct V_625 * F_362 ( int V_626 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_627 ) ; V_19 ++ ) {
if ( V_627 [ V_19 ] . V_628 == V_626 )
return & V_627 [ V_19 ] ;
}
return NULL ;
}
static int F_363 ( struct V_12 * V_13 )
{
const struct V_629 * V_630 ;
int V_54 ;
struct V_625 * V_631 ;
V_631 = F_362 ( V_13 -> V_127 -> V_374 ) ;
if ( ! V_631 ) {
F_364 ( V_13 -> V_30 ,
L_47 ) ;
return - V_504 ;
}
V_54 = F_365 ( & V_630 , V_631 -> V_632 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_48
L_49 ,
V_631 -> V_632 , - V_54 ) ;
if ( V_631 -> V_633 ) {
int V_634 = 0 ;
F_366 ( V_13 , & V_634 ) ;
F_364 ( V_13 -> V_30 , L_50
L_51 , V_634 ) ;
V_54 = 0 ;
}
return V_54 ;
}
V_54 = F_367 ( V_13 , V_585 , & V_13 -> V_331 ,
V_631 -> V_635 ,
( T_3 * ) V_630 -> V_108 , V_630 -> V_193 ) ;
if ( V_54 < 0 )
F_11 ( V_13 -> V_30 , L_52 ,
- V_54 ) ;
else if ( V_54 > 0 ) {
int V_636 = 0 ;
if ( V_631 -> V_635 )
V_636 = V_631 -> V_635 ( V_630 -> V_108 ,
V_630 -> V_193 ) ;
F_309 ( V_13 -> V_30 , L_53
L_54 ,
V_631 -> V_632 , V_636 ) ;
}
F_368 ( V_630 ) ;
return V_54 ;
}
static int F_369 ( struct V_12 * V_12 , int V_637 )
{
struct V_592 V_638 ;
const struct V_629 * V_639 ;
unsigned long V_640 = 0 , V_641 = 0 ;
T_1 V_642 , V_643 , V_644 ;
int V_54 ;
int V_645 = 0 ;
char * V_646 , V_647 [ 256 ] ;
char * V_648 = NULL ;
if ( V_637 ) {
V_54 = F_370 ( V_12 , V_12 -> V_27 ,
V_649 | V_650 ) ;
if ( V_54 < 0 )
goto V_651;
}
if ( F_371 ( V_12 -> V_127 -> V_374 ) ) {
V_54 = F_363 ( V_12 ) ;
if ( V_54 < 0 )
goto V_651;
}
switch ( F_170 ( V_12 -> V_186 . V_190 ) ) {
case V_652 :
V_646 = V_653 ;
break;
case V_272 :
V_646 = V_654 ;
break;
case V_655 :
V_646 = V_656 ;
break;
default:
F_11 ( V_12 -> V_30 , L_55 ,
V_12 -> V_127 -> V_374 ) ;
V_54 = - V_65 ;
goto V_651;
}
V_54 = F_372 ( & V_639 , V_646 , V_12 -> V_30 ) ;
if ( V_54 < 0 ) {
V_648 = L_56 ;
V_640 = V_657 ;
V_641 = F_373 ( V_12 ) ;
} else {
T_1 V_186 [ 7 ] , V_336 [ 7 ] ;
sprintf ( V_647 ,
L_57 , V_646 ) ;
V_648 = V_647 ;
if ( V_639 -> V_193 >= V_658 )
V_54 = - V_61 ;
else {
V_186 [ 0 ] = ( F_7 ( V_659 ) |
F_8 ( V_660 ) ) ;
V_54 = F_374 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_186 , V_336 ) ;
if ( V_54 == 0 ) {
T_7 V_661 = V_639 -> V_193 & 0x3 ;
T_7 V_193 = V_639 -> V_193 & ~ 0x3 ;
T_10 * V_108 = ( T_10 * ) V_639 -> V_108 ;
V_640 = F_375 ( V_336 [ 0 ] ) ;
V_641 = F_376 ( V_336 [ 0 ] ) << 16 ;
F_197 ( & V_12 -> V_331 ) ;
V_54 = F_208 ( V_12 , 0 , V_640 , V_641 ,
V_193 , V_108 , V_662 ) ;
if ( V_54 == 0 && V_661 != 0 ) {
union {
T_10 V_663 ;
char V_664 [ 4 ] ;
} V_665 ;
int V_19 ;
V_665 . V_663 = V_108 [ V_193 >> 2 ] ;
for ( V_19 = V_661 ; V_19 < 4 ; V_19 ++ )
V_665 . V_664 [ V_19 ] = 0 ;
V_54 = F_208 ( V_12 , 0 , V_640 ,
V_641 + V_193 ,
4 , & V_665 . V_663 ,
V_662 ) ;
}
F_199 ( & V_12 -> V_331 ) ;
}
}
F_368 ( V_639 ) ;
if ( V_54 )
goto V_651;
}
memset ( & V_638 , 0 , sizeof( V_638 ) ) ;
V_638 . V_594 =
F_154 ( F_340 ( V_595 ) |
V_596 |
V_597 ) ;
V_638 . V_598 =
F_154 ( V_666 |
F_377 ( V_640 ) |
F_378 ( V_641 >> 16 ) |
F_341 ( V_638 ) ) ;
V_54 = F_342 ( V_12 , V_12 -> V_27 , & V_638 , sizeof( V_638 ) ,
& V_638 ) ;
if ( V_54 == - V_667 ) {
memset ( & V_638 , 0 , sizeof( V_638 ) ) ;
V_638 . V_594 =
F_154 ( F_340 ( V_595 ) |
V_596 |
V_597 ) ;
V_638 . V_598 = F_154 ( F_341 ( V_638 ) ) ;
V_54 = F_342 ( V_12 , V_12 -> V_27 , & V_638 ,
sizeof( V_638 ) , & V_638 ) ;
V_648 = L_58 ;
}
V_645 = 1 ;
if ( V_54 < 0 )
goto V_651;
V_642 = F_48 ( V_638 . V_642 ) ;
V_643 = F_48 ( V_638 . V_643 ) ;
V_644 = F_48 ( V_638 . V_644 ) ;
if ( V_643 != V_644 )
F_364 ( V_12 -> V_30 , L_59\
L_60 ,
V_643 , V_644 ) ;
V_638 . V_594 =
F_154 ( F_340 ( V_595 ) |
V_596 |
V_599 ) ;
V_638 . V_598 = F_154 ( F_341 ( V_638 ) ) ;
V_54 = F_342 ( V_12 , V_12 -> V_27 , & V_638 , sizeof( V_638 ) ,
NULL ) ;
if ( V_54 < 0 )
goto V_651;
V_54 = F_354 ( V_12 ) ;
if ( V_54 < 0 )
goto V_651;
V_54 = F_379 ( V_12 , V_12 -> V_27 ) ;
if ( V_54 < 0 )
goto V_651;
F_309 ( V_12 -> V_30 , L_61\
L_62 ,
V_648 , V_642 , V_644 ) ;
return 0 ;
V_651:
if ( V_645 && V_54 != - V_667 )
F_364 ( V_12 -> V_30 , L_63 ,
V_648 , - V_54 ) ;
return V_54 ;
}
static struct V_668 * F_380 ( int V_190 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_669 ) ; V_19 ++ ) {
if ( V_669 [ V_19 ] . V_190 == V_190 )
return & V_669 [ V_19 ] ;
}
return NULL ;
}
static int F_381 ( struct V_12 * V_13 )
{
int V_54 ;
T_1 V_131 , V_670 ;
enum V_671 V_35 ;
T_1 V_186 [ 7 ] , V_336 [ 7 ] ;
struct V_592 V_638 ;
int V_637 = 1 ;
V_54 = F_382 ( V_13 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_27 ,
F_384 () ? V_672 : V_673 , & V_35 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_64 ,
V_54 ) ;
return V_54 ;
}
if ( V_54 == V_13 -> V_27 )
V_13 -> V_68 |= V_135 ;
F_385 ( V_13 , & V_13 -> V_186 . V_674 ) ;
F_386 ( V_13 , & V_13 -> V_186 . V_675 ) ;
F_387 ( V_13 , & V_13 -> V_186 . V_676 ) ;
F_388 ( V_13 , & V_13 -> V_186 . V_677 ) ;
V_54 = F_389 ( V_13 ) ;
if ( V_54 )
V_35 = V_678 ;
if ( ( V_13 -> V_68 & V_135 ) && V_35 != V_679 ) {
struct V_668 * V_668 ;
struct V_680 * V_681 ;
const struct V_629 * V_682 ;
const T_3 * V_683 = NULL ;
unsigned int V_684 = 0 ;
V_668 = F_380 ( F_170 ( V_13 -> V_186 . V_190 ) ) ;
if ( V_668 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_65 ,
F_170 ( V_13 -> V_186 . V_190 ) ) ;
return - V_65 ;
}
V_681 = F_112 ( sizeof( * V_681 ) ) ;
V_54 = F_372 ( & V_682 , V_668 -> V_685 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_66 ,
V_668 -> V_685 , V_54 ) ;
} else {
V_683 = V_682 -> V_108 ;
V_684 = V_682 -> V_193 ;
}
V_54 = F_390 ( V_13 , V_668 , V_683 , V_684 , V_681 ,
V_35 , & V_637 ) ;
F_368 ( V_682 ) ;
F_114 ( V_681 ) ;
if ( V_54 < 0 )
goto V_651;
}
V_54 = F_391 ( V_13 , & V_13 -> V_186 . V_528 ) ;
if ( V_54 < 0 )
goto V_651;
V_131 =
F_7 ( V_659 ) |
F_8 ( V_686 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_131 , & V_670 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_186 . V_187 = F_392 ( V_670 ) ;
V_13 -> V_186 . V_687 = V_670 ;
if ( V_35 == V_679 ) {
F_309 ( V_13 -> V_30 , L_67\
L_68 ,
V_13 -> V_68 & V_135 ? L_69 : L_70 ) ;
} else {
F_309 ( V_13 -> V_30 , L_71\
L_72 ) ;
V_186 [ 0 ] = ( F_7 ( V_659 ) |
F_8 ( V_660 ) ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_186 , V_336 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_73
L_74 ) ;
goto V_651;
}
V_54 = F_369 ( V_13 , V_637 ) ;
if ( V_54 == - V_667 ) {
F_11 ( V_13 -> V_30 , L_75
L_76 ) ;
goto V_651;
}
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_77
L_78 , - V_54 ) ;
goto V_651;
}
}
V_54 = F_345 ( V_13 ) ;
if ( V_54 < 0 )
goto V_651;
if ( F_393 ( V_13 -> V_127 -> V_374 ) )
V_13 -> V_186 . V_688 = 1 ;
#define F_394 ( T_13 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_395 ( T_13 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_186 [ 0 ] = F_395 ( V_689 ) ;
V_186 [ 1 ] = F_395 ( V_690 ) ;
V_186 [ 2 ] = F_395 ( V_691 ) ;
V_186 [ 3 ] = F_395 ( V_692 ) ;
V_186 [ 4 ] = F_395 ( V_693 ) ;
V_186 [ 5 ] = F_395 ( V_694 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_186 , V_336 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_16 . V_99 = V_336 [ 0 ] ;
V_13 -> V_695 = V_336 [ 1 ] ;
V_13 -> V_696 = V_336 [ 2 ] ;
V_13 -> V_249 . V_697 = V_336 [ 3 ] ;
V_13 -> V_249 . V_263 = V_336 [ 4 ] - V_336 [ 3 ] + 1 ;
V_13 -> V_16 . V_162 = V_336 [ 5 ] ;
V_186 [ 0 ] = F_395 ( V_698 ) ;
V_186 [ 1 ] = F_395 ( V_699 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_186 , V_336 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_16 . V_171 = V_336 [ 0 ] - V_13 -> V_16 . V_99 + 1 ;
V_13 -> V_16 . V_164 = V_336 [ 1 ] - V_13 -> V_16 . V_162 + 1 ;
V_13 -> V_16 . V_98 = F_396 ( V_13 -> V_16 . V_171 ,
sizeof( * V_13 -> V_16 . V_98 ) , V_155 ) ;
if ( ! V_13 -> V_16 . V_98 ) {
V_54 = - V_61 ;
goto V_651;
}
V_13 -> V_16 . V_163 = F_396 ( V_13 -> V_16 . V_164 ,
sizeof( * V_13 -> V_16 . V_163 ) , V_155 ) ;
if ( ! V_13 -> V_16 . V_163 ) {
V_54 = - V_61 ;
goto V_651;
}
V_13 -> V_16 . V_170 = F_396 ( F_166 ( V_13 -> V_16 . V_171 ) ,
sizeof( long ) , V_155 ) ;
if ( ! V_13 -> V_16 . V_170 ) {
V_54 = - V_61 ;
goto V_651;
}
V_13 -> V_16 . V_172 = F_396 ( F_166 ( V_13 -> V_16 . V_171 ) ,
sizeof( long ) , V_155 ) ;
if ( ! V_13 -> V_16 . V_172 ) {
V_54 = - V_61 ;
goto V_651;
}
#ifdef F_134
V_13 -> V_16 . V_700 = F_396 ( F_166 ( V_13 -> V_16 . V_171 ) ,
sizeof( long ) , V_155 ) ;
if ( ! V_13 -> V_16 . V_700 ) {
V_54 = - V_61 ;
goto V_651;
}
#endif
V_186 [ 0 ] = F_395 ( V_701 ) ;
V_186 [ 1 ] = F_395 ( V_702 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_186 , V_336 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_703 = V_336 [ 0 ] ;
V_13 -> V_704 = V_336 [ 1 ] ;
V_13 -> V_186 . V_705 = F_109 ( V_13 -> V_186 . V_190 ) ? 15 : 16 ;
V_186 [ 0 ] = F_395 ( V_706 ) ;
V_186 [ 1 ] = F_395 ( V_707 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_186 , V_336 ) ;
if ( ( V_336 [ 0 ] != V_336 [ 1 ] ) && ( V_54 >= 0 ) ) {
V_13 -> V_68 |= V_708 ;
V_13 -> V_249 . V_709 = V_336 [ 0 ] ;
V_13 -> V_249 . V_710 = V_336 [ 1 ] ;
}
V_186 [ 0 ] = F_395 ( V_711 ) ;
V_336 [ 0 ] = 1 ;
( void ) F_128 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_186 , V_336 ) ;
if ( F_109 ( V_13 -> V_186 . V_190 ) ) {
V_13 -> V_186 . V_712 = false ;
} else {
V_186 [ 0 ] = F_394 ( V_713 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_186 , V_336 ) ;
V_13 -> V_186 . V_712 = ( V_54 == 0 && V_336 [ 0 ] != 0 ) ;
}
V_186 [ 0 ] = F_394 ( V_714 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_186 , V_336 ) ;
V_13 -> V_186 . V_715 = ( V_54 == 0 && V_336 [ 0 ] != 0 ) ;
memset ( & V_638 , 0 , sizeof( V_638 ) ) ;
V_638 . V_594 = F_154 ( F_340 ( V_595 ) |
V_596 | V_597 ) ;
V_638 . V_598 = F_154 ( F_341 ( V_638 ) ) ;
V_54 = F_342 ( V_13 , V_13 -> V_27 , & V_638 , sizeof( V_638 ) ,
& V_638 ) ;
if ( V_54 < 0 )
goto V_651;
if ( V_638 . V_716 ) {
V_186 [ 0 ] = F_394 ( V_717 ) ;
V_186 [ 1 ] = F_395 ( V_718 ) ;
V_186 [ 2 ] = F_395 ( V_719 ) ;
V_186 [ 3 ] = F_395 ( V_720 ) ;
V_186 [ 4 ] = F_395 ( V_721 ) ;
V_186 [ 5 ] = F_394 ( V_722 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_186 , V_336 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_249 . V_258 = V_336 [ 0 ] ;
V_13 -> V_249 . V_264 = F_397 ( V_13 -> V_249 . V_258 / 2 , V_723 ) ;
V_13 -> V_249 . V_237 = V_336 [ 1 ] ;
V_13 -> V_249 . V_235 = V_336 [ 2 ] - V_336 [ 1 ] + 1 ;
if ( V_13 -> V_68 & V_708 && ! F_398 ( V_13 ) ) {
V_13 -> V_249 . V_240 = V_13 -> V_249 . V_697 +
F_399 ( V_13 -> V_249 . V_263 , 3 ) ;
V_13 -> V_249 . V_239 = V_13 -> V_249 . V_263 -
F_399 ( V_13 -> V_249 . V_263 , 3 ) ;
V_13 -> V_249 . V_263 = V_13 -> V_249 . V_240 -
V_13 -> V_249 . V_697 ;
}
V_13 -> V_351 . V_724 . V_352 = V_336 [ 3 ] ;
V_13 -> V_351 . V_724 . V_193 = V_336 [ 4 ] - V_336 [ 3 ] + 1 ;
V_13 -> V_186 . V_725 = V_336 [ 5 ] ;
V_13 -> V_186 . V_726 = 1 ;
V_13 -> V_727 += 1 ;
}
if ( V_638 . V_728 ) {
V_186 [ 0 ] = F_395 ( V_729 ) ;
V_186 [ 1 ] = F_395 ( V_730 ) ;
V_186 [ 2 ] = F_395 ( V_731 ) ;
V_186 [ 3 ] = F_395 ( V_732 ) ;
V_186 [ 4 ] = F_395 ( V_733 ) ;
V_186 [ 5 ] = F_395 ( V_734 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_186 , V_336 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_351 . V_338 . V_352 = V_336 [ 0 ] ;
V_13 -> V_351 . V_338 . V_193 = V_336 [ 1 ] - V_336 [ 0 ] + 1 ;
V_13 -> V_351 . V_735 . V_352 = V_336 [ 2 ] ;
V_13 -> V_351 . V_735 . V_193 = V_336 [ 3 ] - V_336 [ 2 ] + 1 ;
V_13 -> V_351 . V_736 . V_352 = V_336 [ 4 ] ;
V_13 -> V_351 . V_736 . V_193 = V_336 [ 5 ] - V_336 [ 4 ] + 1 ;
V_186 [ 0 ] = F_395 ( V_737 ) ;
V_186 [ 1 ] = F_395 ( V_738 ) ;
V_186 [ 2 ] = F_395 ( V_739 ) ;
V_186 [ 3 ] = F_395 ( V_740 ) ;
V_186 [ 4 ] = F_395 ( V_741 ) ;
V_186 [ 5 ] = F_395 ( V_742 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_186 ,
V_336 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_351 . V_743 . V_352 = V_336 [ 0 ] ;
V_13 -> V_351 . V_743 . V_193 = V_336 [ 1 ] - V_336 [ 0 ] + 1 ;
V_13 -> V_351 . V_744 . V_352 = V_336 [ 2 ] ;
V_13 -> V_351 . V_744 . V_193 = V_336 [ 3 ] - V_336 [ 2 ] + 1 ;
V_13 -> V_351 . V_586 . V_352 = V_336 [ 4 ] ;
V_13 -> V_351 . V_586 . V_193 = V_336 [ 5 ] - V_336 [ 4 ] + 1 ;
V_186 [ 0 ] = F_394 ( V_745 ) ;
V_186 [ 1 ] = F_394 ( V_746 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_186 ,
V_336 ) ;
if ( V_54 < 0 ) {
V_13 -> V_186 . V_747 = 8 ;
V_13 -> V_186 . V_748 = 32 * V_13 -> V_249 . V_258 ;
V_54 = 0 ;
} else {
V_13 -> V_186 . V_747 = V_336 [ 0 ] ;
V_13 -> V_186 . V_748 = V_336 [ 1 ] ;
}
F_309 ( V_13 -> V_30 ,
L_79 ,
V_13 -> V_186 . V_747 ,
V_13 -> V_186 . V_748 ) ;
V_13 -> V_727 += 2 ;
}
if ( V_638 . V_749 ) {
V_186 [ 0 ] = F_395 ( V_750 ) ;
V_186 [ 1 ] = F_395 ( V_751 ) ;
V_54 = F_374 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_186 , V_336 ) ;
if ( V_54 < 0 )
goto V_651;
V_13 -> V_351 . V_752 . V_352 = V_336 [ 0 ] ;
V_13 -> V_351 . V_752 . V_193 = V_336 [ 1 ] - V_336 [ 0 ] + 1 ;
V_13 -> V_727 += 2 ;
}
if ( V_638 . V_753 ) {
V_13 -> V_186 . V_754 |= V_755 ;
V_13 -> V_756 += 1 ;
}
#undef F_395
#undef F_394
F_400 ( V_13 , V_13 -> V_186 . V_299 , NULL ) ;
if ( V_35 != V_679 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_300 ; V_19 ++ )
if ( V_13 -> V_186 . V_299 [ V_19 ] == 1492 ) {
V_13 -> V_186 . V_299 [ V_19 ] = 1488 ;
break;
}
F_401 ( V_13 , V_13 -> V_186 . V_299 , V_13 -> V_186 . V_757 ,
V_13 -> V_186 . V_758 ) ;
}
F_402 ( V_13 ) ;
V_13 -> V_68 |= V_759 ;
F_403 ( V_13 ) ;
return 0 ;
V_651:
F_34 ( V_13 -> V_16 . V_98 ) ;
F_34 ( V_13 -> V_16 . V_163 ) ;
F_34 ( V_13 -> V_16 . V_170 ) ;
F_34 ( V_13 -> V_16 . V_172 ) ;
#ifdef F_134
F_34 ( V_13 -> V_16 . V_700 ) ;
#endif
if ( V_54 != - V_760 && V_54 != - V_761 )
F_404 ( V_13 , V_13 -> V_27 ) ;
return V_54 ;
}
static T_14 F_405 ( struct V_318 * V_127 ,
T_15 V_35 )
{
int V_19 ;
struct V_12 * V_13 = F_196 ( V_127 ) ;
if ( ! V_13 )
goto V_59;
F_406 () ;
V_13 -> V_68 &= ~ V_759 ;
F_261 ( V_13 , V_762 ) ;
F_197 ( & V_13 -> V_322 ) ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
F_407 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_199 ( & V_13 -> V_322 ) ;
F_91 ( V_13 ) ;
if ( V_13 -> V_68 & V_167 )
F_275 ( V_13 ) ;
F_408 () ;
if ( ( V_13 -> V_68 & V_763 ) ) {
F_409 ( V_127 ) ;
V_13 -> V_68 &= ~ V_763 ;
}
V_59: return V_35 == V_764 ?
V_765 : V_766 ;
}
static T_14 F_410 ( struct V_318 * V_127 )
{
int V_19 , V_54 ;
struct V_592 V_593 ;
struct V_12 * V_13 = F_196 ( V_127 ) ;
if ( ! V_13 ) {
F_411 ( V_127 ) ;
F_412 ( V_127 ) ;
return V_767 ;
}
if ( ! ( V_13 -> V_68 & V_763 ) ) {
if ( F_413 ( V_127 ) ) {
F_11 ( & V_127 -> V_2 , L_80
L_81 ) ;
return V_765 ;
}
V_13 -> V_68 |= V_763 ;
}
F_414 ( V_127 ) ;
F_411 ( V_127 ) ;
F_412 ( V_127 ) ;
F_415 ( V_127 ) ;
if ( F_416 ( V_13 -> V_768 ) < 0 )
return V_765 ;
if ( F_383 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_672 , NULL ) < 0 )
return V_765 ;
V_13 -> V_68 |= V_759 ;
if ( F_339 ( V_13 , & V_593 ) )
return V_765 ;
F_73 (adap, i) {
struct V_5 * V_6 = F_84 ( V_13 , V_19 ) ;
V_54 = F_417 ( V_13 , V_13 -> V_27 , V_6 -> V_76 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_54 < 0 )
return V_765 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_74 = - 1 ;
}
F_401 ( V_13 , V_13 -> V_186 . V_299 , V_13 -> V_186 . V_757 ,
V_13 -> V_186 . V_758 ) ;
F_328 ( V_13 ) ;
if ( F_270 ( V_13 ) )
return V_765 ;
return V_767 ;
}
static void F_418 ( struct V_318 * V_127 )
{
int V_19 ;
struct V_12 * V_13 = F_196 ( V_127 ) ;
if ( ! V_13 )
return;
F_406 () ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( F_14 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_301 ( V_2 ) ;
}
F_419 ( V_2 ) ;
}
F_408 () ;
}
static inline bool F_420 ( const struct V_769 * V_770 )
{
unsigned int V_771 , V_772 ;
V_771 = F_421 ( F_422 ( V_770 -> V_773 ) ) ;
V_772 = V_771 & ~ ( V_774 | V_775 ) ;
return V_772 != 0 ;
}
static void F_423 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 , V_776 = 0 , V_777 = 0 ;
#ifndef F_16
int V_778 = 0 ;
#endif
if ( F_384 () ) {
V_13 -> V_186 . V_726 = 0 ;
V_13 -> V_186 . V_754 = 0 ;
} else if ( F_424 ( V_13 ) && F_425 ( V_13 ) ) {
V_13 -> V_186 . V_726 = 0 ;
V_13 -> V_186 . V_754 = 0 ;
}
F_73 (adap, i)
V_776 += F_420 ( & F_84 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_16
if ( V_13 -> V_186 . V_187 * 8 > V_779 ) {
F_11 ( V_13 -> V_30 , L_82 ,
V_779 , V_13 -> V_186 . V_187 * 8 ) ;
F_426 ( 1 ) ;
}
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_777 ;
V_11 -> V_20 = 8 ;
V_777 += V_11 -> V_20 ;
}
#else
if ( V_776 )
V_778 = ( V_779 - ( V_13 -> V_186 . V_187 - V_776 ) ) / V_776 ;
if ( V_778 > F_427 () )
V_778 = F_427 () ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_777 ;
V_11 -> V_20 = F_420 ( & V_11 -> V_7 ) ? V_778 : 1 ;
V_777 += V_11 -> V_20 ;
}
#endif
V_4 -> V_780 = V_777 ;
V_4 -> V_781 = V_777 ;
if ( F_424 ( V_13 ) ) {
if ( V_776 ) {
V_19 = F_428 ( int , V_782 , F_429 () ) ;
V_4 -> V_185 = F_430 ( V_19 , V_13 -> V_186 . V_187 ) ;
} else {
V_4 -> V_185 = V_13 -> V_186 . V_187 ;
}
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_147 ) ; V_19 ++ ) {
struct V_152 * V_783 = & V_4 -> V_147 [ V_19 ] ;
F_431 ( V_13 , & V_783 -> V_148 , 5 , 10 , 1024 , 64 ) ;
V_783 -> V_180 . V_193 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_193 = 1024 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_189 ) ; V_19 ++ )
V_4 -> V_189 [ V_19 ] . V_25 . V_193 = 512 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_101 ) ; V_19 ++ )
V_4 -> V_101 [ V_19 ] . V_25 . V_193 = 1024 ;
F_431 ( V_13 , & V_4 -> V_146 , 0 , 1 , 1024 , 64 ) ;
F_431 ( V_13 , & V_4 -> V_173 , 0 , 1 , 512 , 64 ) ;
}
static void F_432 ( struct V_12 * V_13 , int V_139 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_139 < V_13 -> V_16 . V_780 )
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_780 -- ;
if ( V_13 -> V_16 . V_780 <= V_139 )
break;
}
}
V_139 = 0 ;
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_139 ;
V_139 += V_11 -> V_20 ;
}
}
static int F_433 ( struct V_12 * V_13 )
{
struct V_784 * V_140 ;
unsigned int V_785 = 0 ;
if ( F_169 ( V_13 ) )
V_785 += V_782 * V_13 -> V_727 ;
if ( F_434 ( V_13 ) )
V_785 += V_782 * V_13 -> V_756 ;
if ( ! V_785 )
goto V_59;
V_140 = F_396 ( V_785 , sizeof( * V_140 ) , V_155 ) ;
if ( ! V_140 )
return - V_61 ;
V_13 -> V_786 . V_787 = F_396 ( F_166 ( V_785 ) ,
sizeof( long ) , V_155 ) ;
if ( ! V_13 -> V_786 . V_787 ) {
F_34 ( V_140 ) ;
return - V_61 ;
}
F_167 ( & V_13 -> V_786 . V_788 ) ;
V_13 -> V_789 = V_140 ;
V_59:
return 0 ;
}
static void F_435 ( struct V_12 * V_13 )
{
if ( ! ( V_13 -> V_756 && V_13 -> V_727 ) )
return;
F_34 ( V_13 -> V_789 ) ;
F_34 ( V_13 -> V_786 . V_787 ) ;
}
static int F_436 ( struct V_12 * V_13 )
{
int V_790 = 0 , V_791 = 0 ;
int V_19 , V_137 , V_792 , V_793 , V_794 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_795 = V_13 -> V_186 . V_187 ;
struct V_796 * V_797 ;
int V_785 = V_603 ;
if ( F_434 ( V_13 ) )
V_785 += ( V_782 * V_13 -> V_756 ) ;
if ( F_169 ( V_13 ) )
V_785 += ( V_782 * V_13 -> V_727 ) ;
V_797 = F_80 ( sizeof( * V_797 ) * ( V_785 + 1 ) ,
V_155 ) ;
if ( ! V_797 )
return - V_61 ;
if ( F_433 ( V_13 ) ) {
V_13 -> V_186 . V_726 = 0 ;
V_13 -> V_186 . V_754 = 0 ;
}
for ( V_19 = 0 ; V_19 < V_785 + 1 ; ++ V_19 )
V_797 [ V_19 ] . V_49 = V_19 ;
V_792 = V_4 -> V_781 + V_798 ;
if ( F_169 ( V_13 ) ) {
V_792 += V_13 -> V_727 * V_4 -> V_185 ;
V_790 = V_13 -> V_727 * V_795 ;
}
if ( F_434 ( V_13 ) ) {
V_792 += V_13 -> V_756 * V_4 -> V_185 ;
V_791 = V_13 -> V_756 * V_795 ;
}
#ifdef F_16
V_793 = 8 * V_13 -> V_186 . V_187 + V_798 + V_790 + V_791 ;
#else
V_793 = V_13 -> V_186 . V_187 + V_798 + V_790 + V_791 ;
#endif
V_794 = F_437 ( V_13 -> V_127 , V_797 , V_793 , V_792 ) ;
if ( V_794 < 0 ) {
F_309 ( V_13 -> V_30 , L_83
L_84 ) ;
F_34 ( V_797 ) ;
return V_794 ;
}
V_19 = V_794 - V_798 - V_790 - V_791 ;
if ( V_19 < V_4 -> V_781 ) {
V_4 -> V_781 = V_19 ;
if ( V_19 < V_4 -> V_780 )
F_432 ( V_13 , V_19 ) ;
}
if ( F_424 ( V_13 ) ) {
if ( V_794 < V_792 )
V_4 -> V_799 = V_795 ;
else
V_4 -> V_799 = V_4 -> V_185 ;
}
for ( V_19 = 0 ; V_19 < ( V_4 -> V_781 + V_798 ) ; ++ V_19 )
V_13 -> V_140 [ V_19 ] . V_46 = V_797 [ V_19 ] . V_800 ;
if ( F_424 ( V_13 ) ) {
for ( V_137 = 0 ; V_19 < V_794 ; ++ V_19 , V_137 ++ ) {
V_13 -> V_789 [ V_137 ] . V_46 = V_797 [ V_19 ] . V_800 ;
V_13 -> V_789 [ V_137 ] . V_183 = V_19 ;
}
V_13 -> V_786 . V_801 = V_137 ;
}
F_309 ( V_13 -> V_30 , L_85
L_86 ,
V_794 , V_4 -> V_781 , V_4 -> V_799 ) ;
F_34 ( V_797 ) ;
return 0 ;
}
static int F_438 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_439 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_151 = F_396 ( V_11 -> V_154 , sizeof( T_6 ) , V_155 ) ;
if ( ! V_11 -> V_151 )
return - V_61 ;
}
return 0 ;
}
static int F_440 ( struct V_12 * V_13 ,
enum V_802 * V_8 ,
enum V_803 * V_804 )
{
T_1 V_805 , V_806 ;
int V_807 , V_808 ;
#define F_441 4
* V_8 = V_809 ;
* V_804 = V_810 ;
V_807 = F_442 ( V_13 -> V_127 , V_811 ,
& V_805 ) ;
V_808 = F_442 ( V_13 -> V_127 , V_812 ,
& V_806 ) ;
if ( ! V_808 && V_806 ) {
if ( V_806 & V_813 )
* V_8 = V_814 ;
else if ( V_806 & V_815 )
* V_8 = V_816 ;
else if ( V_806 & V_817 )
* V_8 = V_818 ;
}
if ( ! V_807 ) {
* V_804 = ( V_805 & V_819 ) >> F_441 ;
if ( ! V_806 ) {
if ( V_805 & V_820 )
* V_8 = V_816 ;
else if ( V_805 & V_821 )
* V_8 = V_818 ;
}
}
if ( * V_8 == V_809 || * V_804 == V_810 )
return V_807 ? V_807 : V_808 ? V_808 : - V_65 ;
return 0 ;
}
static void F_443 ( struct V_12 * V_13 )
{
enum V_803 V_804 , V_822 ;
enum V_802 V_8 , V_823 ;
#define F_444 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_440 ( V_13 , & V_823 , & V_822 ) ) {
F_364 ( V_13 -> V_30 ,
L_87 ) ;
return;
}
if ( F_445 ( V_13 -> V_127 , & V_8 , & V_804 ) ||
V_8 == V_809 || V_804 == V_810 ) {
F_364 ( V_13 -> V_30 ,
L_88 ) ;
return;
}
F_309 ( V_13 -> V_30 , L_89 ,
F_444 ( V_8 ) , F_444 ( V_823 ) ) ;
F_309 ( V_13 -> V_30 , L_90 ,
V_804 , V_822 ) ;
if ( V_8 < V_823 || V_804 < V_822 )
F_309 ( V_13 -> V_30 ,
L_91
L_92 ) ;
}
static void F_446 ( struct V_12 * V_12 )
{
F_309 ( V_12 -> V_30 , L_93 ,
V_12 -> V_186 . V_528 . V_824 ,
F_447 ( V_12 -> V_186 . V_190 ) ) ;
F_309 ( V_12 -> V_30 , L_94 ,
V_12 -> V_186 . V_528 . V_825 , V_12 -> V_186 . V_528 . V_826 ) ;
if ( ! V_12 -> V_186 . V_674 )
F_364 ( V_12 -> V_30 , L_95 ) ;
else
F_309 ( V_12 -> V_30 , L_96 ,
F_448 ( V_12 -> V_186 . V_674 ) ,
F_449 ( V_12 -> V_186 . V_674 ) ,
F_450 ( V_12 -> V_186 . V_674 ) ,
F_451 ( V_12 -> V_186 . V_674 ) ) ;
if ( ! V_12 -> V_186 . V_675 )
F_309 ( V_12 -> V_30 , L_97 ) ;
else
F_309 ( V_12 -> V_30 , L_98 ,
F_448 ( V_12 -> V_186 . V_675 ) ,
F_449 ( V_12 -> V_186 . V_675 ) ,
F_450 ( V_12 -> V_186 . V_675 ) ,
F_451 ( V_12 -> V_186 . V_675 ) ) ;
if ( ! V_12 -> V_186 . V_676 )
F_364 ( V_12 -> V_30 , L_99 ) ;
else
F_309 ( V_12 -> V_30 ,
L_100 ,
F_448 ( V_12 -> V_186 . V_676 ) ,
F_449 ( V_12 -> V_186 . V_676 ) ,
F_450 ( V_12 -> V_186 . V_676 ) ,
F_451 ( V_12 -> V_186 . V_676 ) ) ;
if ( ! V_12 -> V_186 . V_677 )
F_309 ( V_12 -> V_30 , L_101 ) ;
else
F_309 ( V_12 -> V_30 ,
L_102 ,
F_448 ( V_12 -> V_186 . V_677 ) ,
F_449 ( V_12 -> V_186 . V_677 ) ,
F_450 ( V_12 -> V_186 . V_677 ) ,
F_451 ( V_12 -> V_186 . V_677 ) ) ;
F_309 ( V_12 -> V_30 , L_103 ,
F_169 ( V_12 ) ? L_104 : L_105 ,
( ( V_12 -> V_68 & V_126 ) ? L_106 :
( V_12 -> V_68 & V_128 ) ? L_107 : L_105 ) ,
F_169 ( V_12 ) ? L_108 : L_109 ) ;
}
static void F_452 ( const struct V_1 * V_2 )
{
char V_664 [ 80 ] ;
char * V_827 = V_664 ;
const char * V_828 = L_105 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_186 . V_829 . V_8 == V_830 )
V_828 = L_110 ;
else if ( V_13 -> V_186 . V_829 . V_8 == V_831 )
V_828 = L_111 ;
else if ( V_13 -> V_186 . V_829 . V_8 == V_832 )
V_828 = L_112 ;
if ( V_11 -> V_7 . V_773 & V_774 )
V_827 += sprintf ( V_827 , L_113 ) ;
if ( V_11 -> V_7 . V_773 & V_775 )
V_827 += sprintf ( V_827 , L_114 ) ;
if ( V_11 -> V_7 . V_773 & V_833 )
V_827 += sprintf ( V_827 , L_115 ) ;
if ( V_11 -> V_7 . V_773 & V_834 )
V_827 += sprintf ( V_827 , L_116 ) ;
if ( V_11 -> V_7 . V_773 & V_835 )
V_827 += sprintf ( V_827 , L_117 ) ;
if ( V_11 -> V_7 . V_773 & V_836 )
V_827 += sprintf ( V_827 , L_118 ) ;
if ( V_827 != V_664 )
-- V_827 ;
sprintf ( V_827 , L_119 , F_453 ( V_11 -> V_837 ) ) ;
F_3 ( V_2 , L_120 ,
V_2 -> V_9 , V_13 -> V_186 . V_528 . V_824 , V_13 -> V_9 , V_664 ) ;
}
static void F_454 ( struct V_318 * V_2 )
{
F_455 ( V_2 , V_838 , V_839 ) ;
}
static void F_456 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_114 ( V_12 -> V_840 ) ;
F_457 ( V_12 ) ;
F_114 ( V_12 -> V_249 . V_248 ) ;
F_458 ( V_12 ) ;
F_34 ( V_12 -> V_16 . V_98 ) ;
F_34 ( V_12 -> V_16 . V_163 ) ;
F_34 ( V_12 -> V_16 . V_170 ) ;
F_34 ( V_12 -> V_16 . V_172 ) ;
#ifdef F_134
F_34 ( V_12 -> V_16 . V_700 ) ;
#endif
F_64 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] ) {
struct V_5 * V_11 = F_84 ( V_12 , V_19 ) ;
if ( V_11 -> V_51 != 0 )
F_459 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_51 ) ;
F_34 ( F_84 ( V_12 , V_19 ) -> V_151 ) ;
F_460 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_12 -> V_68 & V_759 )
F_404 ( V_12 , V_12 -> V_28 ) ;
}
static int F_461 ( struct V_318 * V_127 , T_1 V_841 )
{
T_6 V_842 ;
F_462 ( V_127 , V_843 , & V_842 ) ;
switch ( V_842 >> 12 ) {
case V_652 :
return F_463 ( V_652 , V_841 ) ;
case V_272 :
return F_463 ( V_272 , V_841 ) ;
case V_655 :
return F_463 ( V_655 , V_841 ) ;
default:
F_11 ( & V_127 -> V_2 , L_55 ,
V_842 ) ;
}
return - V_65 ;
}
static void F_464 ( struct V_1 * V_2 )
{
V_2 -> type = V_844 ;
V_2 -> V_66 = 0 ;
V_2 -> V_845 = 0 ;
V_2 -> V_539 = 0 ;
V_2 -> V_846 = 0 ;
V_2 -> V_68 |= V_847 ;
V_2 -> V_376 |= V_848 ;
V_2 -> V_849 = & V_850 ;
V_2 -> V_851 = & V_852 ;
V_2 -> V_853 = F_460 ;
}
static int F_465 ( struct V_318 * V_127 )
{
struct V_12 * V_13 = F_196 ( V_127 ) ;
struct V_1 * V_52 ;
struct V_5 * V_11 ;
char V_9 [ V_854 ] ;
int V_22 ;
snprintf ( V_9 , V_854 , L_121 , V_13 -> V_855 , V_13 -> V_28 ) ;
V_52 = F_466 ( 0 , V_9 , V_856 , F_464 ) ;
if ( ! V_52 )
return - V_61 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_13 ;
F_467 ( V_52 , & V_127 -> V_2 ) ;
V_13 -> V_39 [ 0 ] = V_52 ;
V_22 = F_468 ( V_13 -> V_39 [ 0 ] ) ;
if ( V_22 ) {
F_5 ( L_122 , V_9 ) ;
F_460 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
return V_22 ;
}
return 0 ;
}
static int F_469 ( struct V_318 * V_127 , int V_529 )
{
struct V_12 * V_13 = F_196 ( V_127 ) ;
int V_22 = 0 ;
int V_857 = F_470 ( V_127 ) ;
T_1 V_858 ;
V_858 = F_471 ( V_13 -> V_768 + V_859 ) ;
if ( ! ( V_858 & V_860 ) ||
! ( V_858 & V_861 ) ||
F_472 ( V_858 ) != 4 ) {
F_364 ( & V_127 -> V_2 ,
L_123 ) ;
return - V_504 ;
}
if ( V_857 && F_473 ( V_127 ) ) {
F_11 ( & V_127 -> V_2 ,
L_124 ) ;
V_529 = V_857 ;
return V_529 ;
}
if ( ! V_529 ) {
F_474 ( V_127 ) ;
if ( V_13 -> V_39 [ 0 ] ) {
F_475 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
}
F_34 ( V_13 -> V_530 ) ;
V_13 -> V_530 = NULL ;
V_13 -> V_529 = 0 ;
return V_529 ;
}
if ( V_529 != V_857 ) {
V_22 = F_476 ( V_127 , V_529 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_529 = V_529 ;
V_22 = F_465 ( V_127 ) ;
if ( V_22 )
return V_22 ;
}
V_13 -> V_530 = F_396 ( V_13 -> V_529 ,
sizeof( struct V_862 ) , V_155 ) ;
if ( V_13 -> V_530 )
F_304 ( V_13 ) ;
return V_529 ;
}
static int F_477 ( struct V_318 * V_127 , const struct V_863 * V_864 )
{
int V_865 , V_19 , V_22 , V_866 , V_867 , V_868 ;
struct V_5 * V_11 ;
bool V_869 = false ;
struct V_12 * V_12 = NULL ;
struct V_1 * V_52 ;
void T_16 * V_768 ;
T_1 V_870 , V_841 ;
enum V_310 V_190 ;
static int V_855 = 1 ;
F_478 ( V_871 L_125 , V_872 , V_873 ) ;
V_22 = F_479 ( V_127 , V_874 ) ;
if ( V_22 ) {
F_309 ( & V_127 -> V_2 , L_126 ) ;
return V_22 ;
}
V_22 = F_413 ( V_127 ) ;
if ( V_22 ) {
F_11 ( & V_127 -> V_2 , L_127 ) ;
goto V_875;
}
V_768 = F_480 ( V_127 , 0 ) ;
if ( ! V_768 ) {
F_11 ( & V_127 -> V_2 , L_128 ) ;
V_22 = - V_61 ;
goto V_876;
}
V_22 = F_416 ( V_768 ) ;
if ( V_22 < 0 )
goto V_877;
V_870 = F_471 ( V_768 + V_878 ) ;
V_841 = F_481 ( F_471 ( V_768 + V_879 ) ) ;
V_190 = F_461 ( V_127 , V_841 ) ;
V_865 = F_170 ( V_190 ) <= V_272 ?
F_482 ( V_870 ) : F_483 ( V_870 ) ;
if ( V_865 != V_864 -> V_880 ) {
#ifndef F_484
F_485 ( V_768 ) ;
#endif
F_409 ( V_127 ) ;
F_412 ( V_127 ) ;
goto V_881;
}
if ( ! F_486 ( V_127 , F_487 ( 64 ) ) ) {
V_869 = true ;
V_22 = F_488 ( V_127 , F_487 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_127 -> V_2 , L_129
L_130 ) ;
goto V_877;
}
} else {
V_22 = F_486 ( V_127 , F_487 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_127 -> V_2 , L_131 ) ;
goto V_877;
}
}
F_489 ( V_127 ) ;
F_454 ( V_127 ) ;
F_414 ( V_127 ) ;
F_412 ( V_127 ) ;
V_12 = F_27 ( sizeof( * V_12 ) , V_155 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_877;
}
V_855 ++ ;
V_12 -> V_254 = F_490 ( L_132 ) ;
if ( ! V_12 -> V_254 ) {
V_22 = - V_61 ;
goto V_882;
}
V_12 -> V_883 = F_27 ( sizeof( * V_12 -> V_883 ) +
( sizeof( struct V_884 ) *
V_885 ) ,
V_155 ) ;
if ( ! V_12 -> V_883 ) {
V_22 = - V_61 ;
goto V_882;
}
V_12 -> V_883 -> V_193 = V_885 ;
V_12 -> V_68 |= V_763 ;
V_12 -> V_768 = V_768 ;
V_12 -> V_127 = V_127 ;
V_12 -> V_30 = & V_127 -> V_2 ;
V_12 -> V_9 = F_325 ( V_127 ) ;
V_12 -> V_27 = V_865 ;
V_12 -> V_28 = V_865 ;
V_12 -> V_886 = V_887 ;
memset ( V_12 -> V_81 , 0xff , sizeof( V_12 -> V_81 ) ) ;
F_167 ( & V_12 -> V_322 ) ;
F_167 ( & V_12 -> V_250 ) ;
F_167 ( & V_12 -> V_331 ) ;
F_491 ( & V_12 -> V_255 , F_158 ) ;
F_491 ( & V_12 -> V_394 , F_244 ) ;
F_491 ( & V_12 -> V_401 , F_249 ) ;
V_22 = F_492 ( V_12 ) ;
if ( V_22 )
goto V_882;
if ( ! F_109 ( V_12 -> V_186 . V_190 ) ) {
V_866 = ( V_888 +
( V_889 - V_888 ) *
V_12 -> V_28 ) ;
V_867 = 1 << F_493 ( F_68 ( V_12 ,
V_890 ) >> V_866 ) ;
V_868 = V_619 / V_891 ;
if ( V_867 > V_868 ) {
F_11 ( & V_127 -> V_2 ,
L_133 ) ;
V_22 = - V_65 ;
goto V_882;
}
V_12 -> V_407 = F_494 ( F_495 ( V_127 , 2 ) ,
F_496 ( V_127 , 2 ) ) ;
if ( ! V_12 -> V_407 ) {
F_11 ( & V_127 -> V_2 , L_134 ) ;
V_22 = - V_61 ;
goto V_882;
}
}
F_328 ( V_12 ) ;
V_22 = F_381 ( V_12 ) ;
#ifdef F_134
F_99 ( V_12 -> V_16 . V_700 , V_12 -> V_16 . V_171 ) ;
#endif
F_331 ( V_12 ) ;
if ( V_22 )
goto V_892;
if ( ! F_109 ( V_12 -> V_186 . V_190 ) )
F_70 ( V_12 , V_893 , F_497 ( 7 ) |
( F_219 ( V_12 -> V_186 . V_190 ) ? F_498 ( 0 ) :
F_499 ( 0 ) ) ) ;
F_73 (adapter, i) {
V_52 = F_500 ( sizeof( struct V_5 ) ,
V_779 ) ;
if ( ! V_52 ) {
V_22 = - V_61 ;
goto V_894;
}
F_467 ( V_52 , & V_127 -> V_2 ) ;
V_12 -> V_39 [ V_19 ] = V_52 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_74 = - 1 ;
V_11 -> V_31 = V_19 ;
V_52 -> V_129 = V_127 -> V_129 ;
V_52 -> V_895 = V_896 | V_897 |
V_898 | V_899 |
V_900 | V_901 |
V_902 | V_73 |
V_903 ;
if ( V_869 )
V_52 -> V_895 |= V_904 ;
V_52 -> V_72 |= V_52 -> V_895 ;
V_52 -> V_905 = V_52 -> V_72 & V_906 ;
V_52 -> V_376 |= V_907 ;
V_52 -> V_849 = & V_908 ;
#ifdef F_16
V_52 -> V_909 = & V_910 ;
F_17 ( V_52 ) ;
#endif
F_501 ( V_52 ) ;
}
F_502 ( V_127 , V_12 ) ;
if ( V_12 -> V_68 & V_759 ) {
V_22 = F_503 ( V_12 , V_865 , V_865 , 0 ) ;
if ( V_22 )
goto V_894;
} else if ( V_12 -> V_186 . V_187 == 1 ) {
T_3 V_522 [ V_523 ] ;
T_3 * V_525 = V_12 -> V_186 . V_528 . V_525 ;
V_22 = F_305 ( V_12 , & V_12 -> V_186 . V_528 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_523 ; V_19 ++ )
V_522 [ V_19 ] = ( F_306 ( V_525 [ 2 * V_19 + 0 ] ) * 16 +
F_306 ( V_525 [ 2 * V_19 + 1 ] ) ) ;
F_504 ( V_12 , 0 , V_522 ) ;
}
}
F_423 ( V_12 ) ;
V_12 -> V_840 = F_505 ( V_12 -> V_695 , V_12 -> V_696 ) ;
if ( ! V_12 -> V_840 ) {
F_364 ( & V_127 -> V_2 , L_135 ) ;
V_12 -> V_186 . V_726 = 0 ;
}
#if F_263 ( V_436 )
if ( ( F_170 ( V_12 -> V_186 . V_190 ) <= V_272 ) &&
( ! ( F_68 ( V_12 , V_911 ) & V_912 ) ) ) {
F_364 ( & V_127 -> V_2 ,
L_136 ) ;
V_12 -> V_186 . V_726 = 0 ;
} else {
V_12 -> V_913 = F_506 ( V_12 -> V_703 ,
V_12 -> V_704 ) ;
if ( ! V_12 -> V_913 ) {
F_364 ( & V_127 -> V_2 ,
L_137 ) ;
V_12 -> V_186 . V_726 = 0 ;
}
}
#endif
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_11 -> V_914 = F_507 ( V_12 -> V_186 . V_705 ) ;
if ( ! V_11 -> V_914 )
F_364 ( & V_127 -> V_2 ,
L_138 ,
V_19 ) ;
}
if ( F_165 ( & V_12 -> V_249 ) < 0 ) {
F_364 ( & V_127 -> V_2 , L_139
L_140 ) ;
V_12 -> V_186 . V_726 = 0 ;
} else {
V_12 -> V_915 = F_508 ( V_12 ,
V_916 ) ;
if ( ! V_12 -> V_915 )
F_364 ( & V_127 -> V_2 ,
L_141 ) ;
}
if ( F_169 ( V_12 ) ) {
if ( F_68 ( V_12 , V_911 ) & V_917 ) {
T_1 V_259 , V_918 ;
if ( V_190 <= V_272 ) {
V_918 = V_919 ;
V_259 = F_68 ( V_12 , V_918 ) ;
V_12 -> V_249 . V_259 = V_259 / 4 ;
} else {
V_918 = V_920 ;
V_259 = F_68 ( V_12 , V_918 ) ;
V_12 -> V_249 . V_259 = V_259 ;
}
}
}
if ( V_921 > 1 && F_436 ( V_12 ) == 0 )
V_12 -> V_68 |= V_126 ;
else if ( V_921 > 0 && F_509 ( V_127 ) == 0 ) {
V_12 -> V_68 |= V_128 ;
if ( V_921 > 1 )
F_435 ( V_12 ) ;
}
F_443 ( V_12 ) ;
V_22 = F_438 ( V_12 ) ;
if ( V_22 )
goto V_894;
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_12 -> V_39 [ V_19 ] -> V_922 = V_11 -> V_442 ;
F_510 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_511 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_468 ( V_12 -> V_39 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_81 [ V_11 -> V_76 ] = V_19 ;
F_452 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_127 -> V_2 , L_142 ) ;
goto V_894;
}
if ( V_22 ) {
F_364 ( & V_127 -> V_2 , L_143 , V_19 ) ;
V_22 = 0 ;
}
if ( V_923 ) {
V_12 -> V_220 = F_512 ( F_325 ( V_127 ) ,
V_923 ) ;
F_132 ( V_12 ) ;
}
V_127 -> V_924 = 1 ;
if ( F_424 ( V_12 ) ) {
F_256 ( & V_414 ) ;
F_29 ( & V_12 -> V_415 , & V_418 ) ;
F_260 ( & V_414 ) ;
}
F_446 ( V_12 ) ;
F_98 ( V_12 ) ;
return 0 ;
V_881:
#ifdef F_484
if ( V_865 < F_20 ( V_925 ) && V_925 [ V_865 ] > 0 ) {
F_364 ( & V_127 -> V_2 ,
L_144
L_145
L_146 ) ;
if ( F_476 ( V_127 , V_925 [ V_865 ] ) == 0 )
F_309 ( & V_127 -> V_2 ,
L_147 ,
V_925 [ V_865 ] ) ;
}
V_12 = F_27 ( sizeof( * V_12 ) , V_155 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_926;
}
V_12 -> V_127 = V_127 ;
V_12 -> V_30 = & V_127 -> V_2 ;
V_12 -> V_9 = F_325 ( V_127 ) ;
V_12 -> V_27 = V_865 ;
V_12 -> V_28 = V_865 ;
V_12 -> V_768 = V_768 ;
V_12 -> V_855 = V_855 ;
V_12 -> V_883 = F_27 ( sizeof( * V_12 -> V_883 ) +
( sizeof( struct V_884 ) *
V_885 ) ,
V_155 ) ;
if ( ! V_12 -> V_883 ) {
V_22 = - V_61 ;
goto V_927;
}
F_502 ( V_127 , V_12 ) ;
return 0 ;
V_927:
F_34 ( V_12 ) ;
V_926:
F_485 ( V_768 ) ;
F_474 ( V_127 ) ;
F_513 ( V_127 ) ;
return V_22 ;
#else
return 0 ;
#endif
V_894:
F_456 ( V_12 ) ;
if ( V_12 -> V_68 & V_126 )
F_435 ( V_12 ) ;
if ( V_12 -> V_756 || V_12 -> V_727 )
F_514 ( V_12 ) ;
V_892:
if ( ! F_109 ( V_12 -> V_186 . V_190 ) )
F_485 ( V_12 -> V_407 ) ;
V_882:
if ( V_12 -> V_254 )
F_515 ( V_12 -> V_254 ) ;
F_34 ( V_12 -> V_883 ) ;
F_34 ( V_12 ) ;
V_877:
F_485 ( V_768 ) ;
V_876:
F_516 ( V_127 ) ;
F_409 ( V_127 ) ;
V_875:
F_513 ( V_127 ) ;
return V_22 ;
}
static void F_517 ( struct V_318 * V_127 )
{
struct V_12 * V_12 = F_196 ( V_127 ) ;
if ( ! V_12 ) {
F_513 ( V_127 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_515 ( V_12 -> V_254 ) ;
if ( F_424 ( V_12 ) )
F_255 ( V_12 ) ;
F_91 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_928 == V_929 )
F_475 ( V_12 -> V_39 [ V_19 ] ) ;
F_518 ( V_12 -> V_220 ) ;
F_519 ( V_12 ) ;
if ( V_12 -> V_68 & V_167 )
F_275 ( V_12 ) ;
if ( V_12 -> V_68 & V_126 )
F_435 ( V_12 ) ;
if ( V_12 -> V_756 || V_12 -> V_727 )
F_514 ( V_12 ) ;
F_456 ( V_12 ) ;
#if F_263 ( V_436 )
F_520 ( V_12 ) ;
#endif
F_485 ( V_12 -> V_768 ) ;
if ( ! F_109 ( V_12 -> V_186 . V_190 ) )
F_485 ( V_12 -> V_407 ) ;
F_516 ( V_127 ) ;
if ( ( V_12 -> V_68 & V_763 ) ) {
F_409 ( V_127 ) ;
V_12 -> V_68 &= ~ V_763 ;
}
F_513 ( V_127 ) ;
F_34 ( V_12 -> V_883 ) ;
F_521 () ;
F_34 ( V_12 ) ;
}
#ifdef F_484
else {
if ( V_12 -> V_39 [ 0 ] )
F_475 ( V_12 -> V_39 [ 0 ] ) ;
F_485 ( V_12 -> V_768 ) ;
F_34 ( V_12 -> V_530 ) ;
F_34 ( V_12 ) ;
F_474 ( V_127 ) ;
F_513 ( V_127 ) ;
}
#endif
}
static void F_522 ( struct V_318 * V_127 )
{
struct V_12 * V_12 = F_196 ( V_127 ) ;
if ( ! V_12 ) {
F_513 ( V_127 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_928 == V_929 )
F_280 ( V_12 -> V_39 [ V_19 ] ) ;
F_523 ( V_12 ) ;
F_91 ( V_12 ) ;
F_64 ( V_12 ) ;
F_277 ( V_12 ) ;
if ( V_12 -> V_68 & V_759 )
F_404 ( V_12 , V_12 -> V_27 ) ;
}
#ifdef F_484
else {
if ( V_12 -> V_39 [ 0 ] )
F_475 ( V_12 -> V_39 [ 0 ] ) ;
F_485 ( V_12 -> V_768 ) ;
F_34 ( V_12 -> V_530 ) ;
F_34 ( V_12 ) ;
F_474 ( V_127 ) ;
F_513 ( V_127 ) ;
}
#endif
}
static int T_17 F_524 ( void )
{
int V_54 ;
V_923 = F_512 ( V_874 , NULL ) ;
if ( ! V_923 )
F_525 ( L_148 ) ;
V_54 = F_526 ( & V_379 ) ;
if ( V_54 < 0 )
F_527 ( V_923 ) ;
#if F_263 ( V_436 )
if ( ! V_930 ) {
F_528 ( & V_931 ) ;
V_930 = true ;
}
#endif
return V_54 ;
}
static void T_18 F_529 ( void )
{
#if F_263 ( V_436 )
if ( V_930 ) {
F_530 ( & V_931 ) ;
V_930 = false ;
}
#endif
F_531 ( & V_379 ) ;
F_527 ( V_923 ) ;
}
