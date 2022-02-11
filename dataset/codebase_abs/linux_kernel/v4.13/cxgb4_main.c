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
struct V_175 * V_176 = NULL ;
unsigned int V_177 = 0 ;
if ( F_100 ( V_13 ) )
V_176 = V_4 -> V_178 [ V_179 ] ;
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
F_101 ( V_13 ,
V_11 -> V_76 ) ) ;
if ( V_22 )
goto V_183;
V_25 -> V_149 . V_184 = V_138 ;
memset ( & V_25 -> V_185 , 0 , sizeof( V_25 -> V_185 ) ) ;
}
for ( V_138 = 0 ; V_138 < V_11 -> V_20 ; V_138 ++ , V_180 ++ ) {
V_22 = F_102 ( V_13 , V_180 , V_2 ,
F_103 ( V_2 , V_138 ) ,
V_4 -> V_147 . V_26 ) ;
if ( V_22 )
goto V_183;
}
}
F_73 (adap, i) {
if ( V_176 )
V_177 = V_176 -> V_186 [ V_19 ] . V_149 . V_26 ;
V_22 = F_104 ( V_13 , & V_4 -> V_187 [ V_19 ] , V_13 -> V_39 [ V_19 ] ,
V_4 -> V_147 . V_26 , V_177 ) ;
if ( V_22 )
goto V_183;
}
if ( ! F_105 ( V_13 -> V_188 . V_189 ) ) {
V_22 = F_102 ( V_13 , & V_4 -> V_190 , V_13 -> V_39 [ 0 ] ,
F_103 ( V_13 -> V_39 [ 0 ] , 0 )
, V_4 -> V_147 . V_26 ) ;
if ( V_22 )
goto V_183;
}
F_70 ( V_13 , F_105 ( V_13 -> V_188 . V_189 ) ?
V_191 :
V_192 ,
F_106 ( F_86 ( V_13 -> V_39 [ 0 ] ) -> V_76 ) |
F_107 ( V_4 -> V_148 [ 0 ] . V_149 . V_157 ) ) ;
return 0 ;
V_183:
F_98 ( V_13 ) ;
return V_22 ;
}
static T_6 F_108 ( struct V_1 * V_2 , struct V_193 * V_194 ,
void * V_195 , T_7 V_196 )
{
int V_15 ;
#ifdef F_16
if ( F_12 ( V_2 ) && ! F_109 () ) {
T_6 V_197 ;
int V_22 ;
V_22 = F_110 ( V_194 , & V_197 ) ;
if ( F_51 ( V_22 ) ) {
if ( F_111 () )
F_112 ( V_2 ,
L_34 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_197 & V_198 ) >> V_199 ;
#ifdef F_113
if ( V_194 -> V_200 == F_114 ( V_201 ) )
V_15 = V_194 -> V_202 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_203 ) {
V_15 = ( F_115 ( V_194 )
? F_116 ( V_194 )
: F_117 () ) ;
while ( F_51 ( V_15 >= V_2 -> V_204 ) )
V_15 -= V_2 -> V_204 ;
return V_15 ;
}
return V_196 ( V_2 , V_194 ) % V_2 -> V_204 ;
}
static int F_118 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_205 , V_206 = 0 , V_207 = V_208 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_209 ) ; V_19 ++ ) {
V_205 = time - V_4 -> V_209 [ V_19 ] ;
if ( V_205 < 0 )
V_205 = - V_205 ;
if ( V_205 < V_207 ) {
V_207 = V_205 ;
V_206 = V_19 ;
}
}
return V_206 ;
}
static int F_119 ( const struct V_16 * V_4 , int V_210 )
{
int V_19 , V_205 , V_206 = 0 , V_207 = V_208 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_211 ) ; V_19 ++ ) {
V_205 = V_210 - V_4 -> V_211 [ V_19 ] ;
if ( V_205 < 0 )
V_205 = - V_205 ;
if ( V_205 < V_207 ) {
V_207 = V_205 ;
V_206 = V_19 ;
}
}
return V_206 ;
}
int F_120 ( struct V_84 * V_25 ,
unsigned int V_212 , unsigned int V_213 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_212 | V_213 ) == 0 )
V_213 = 1 ;
if ( V_213 ) {
int V_22 ;
T_1 V_132 , V_214 ;
V_214 = F_119 ( & V_13 -> V_16 , V_213 ) ;
if ( V_25 -> V_142 && V_25 -> V_215 != V_214 ) {
V_132 = F_7 ( V_23 ) |
F_8 (
V_216 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_121 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_132 , & V_214 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_215 = V_214 ;
}
V_212 = V_212 == 0 ? 6 : F_118 ( & V_13 -> V_16 , V_212 ) ;
V_25 -> V_170 = F_122 ( V_212 ) | F_123 ( V_213 > 0 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , T_8 V_72 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_8 V_217 = V_2 -> V_72 ^ V_72 ;
int V_22 ;
if ( ! ( V_217 & V_73 ) )
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
if ( F_126 ( V_13 -> V_218 ) )
return - 1 ;
#ifdef F_127
F_128 ( V_13 ) ;
#endif
return 0 ;
}
int F_129 ( struct V_219 * V_180 , void * V_109 )
{
int V_220 = - 1 ;
F_130 ( & V_180 -> V_221 ) ;
if ( V_180 -> V_222 ) {
union V_223 * V_6 = V_180 -> V_222 ;
V_220 = ( V_6 - V_180 -> V_224 ) + V_180 -> V_225 ;
V_180 -> V_222 = V_6 -> V_226 ;
V_6 -> V_109 = V_109 ;
V_180 -> V_227 ++ ;
}
F_131 ( & V_180 -> V_221 ) ;
return V_220 ;
}
void F_132 ( struct V_219 * V_180 , unsigned int V_220 )
{
union V_223 * V_6 = & V_180 -> V_224 [ V_220 - V_180 -> V_225 ] ;
F_130 ( & V_180 -> V_221 ) ;
V_6 -> V_226 = V_180 -> V_222 ;
V_180 -> V_222 = V_6 ;
V_180 -> V_227 -- ;
F_131 ( & V_180 -> V_221 ) ;
}
int F_133 ( struct V_219 * V_180 , int V_228 , void * V_109 )
{
int V_229 ;
F_130 ( & V_180 -> V_230 ) ;
if ( V_228 == V_231 ) {
V_229 = F_134 ( V_180 -> V_232 , V_180 -> V_233 ) ;
if ( V_229 < V_180 -> V_233 )
F_135 ( V_229 , V_180 -> V_232 ) ;
else
V_229 = - 1 ;
} else {
V_229 = F_136 ( V_180 -> V_232 , V_180 -> V_233 , 1 ) ;
if ( V_229 < 0 )
V_229 = - 1 ;
}
if ( V_229 >= 0 ) {
V_180 -> V_234 [ V_229 ] . V_109 = V_109 ;
V_229 += V_180 -> V_235 ;
if ( V_228 == V_236 ) {
V_180 -> V_237 += 2 ;
V_180 -> V_238 += 2 ;
} else {
V_180 -> V_237 ++ ;
}
}
F_131 ( & V_180 -> V_230 ) ;
return V_229 ;
}
int F_137 ( struct V_219 * V_180 , int V_228 , void * V_109 )
{
int V_229 ;
F_130 ( & V_180 -> V_230 ) ;
if ( V_228 == V_231 ) {
V_229 = F_138 ( V_180 -> V_232 ,
V_180 -> V_233 + V_180 -> V_239 , V_180 -> V_233 ) ;
if ( V_229 < ( V_180 -> V_233 + V_180 -> V_239 ) )
F_135 ( V_229 , V_180 -> V_232 ) ;
else
V_229 = - 1 ;
} else {
V_229 = - 1 ;
}
if ( V_229 >= 0 ) {
V_180 -> V_234 [ V_229 ] . V_109 = V_109 ;
V_229 -= V_180 -> V_233 ;
V_229 += V_180 -> V_240 ;
V_180 -> V_241 ++ ;
}
F_131 ( & V_180 -> V_230 ) ;
return V_229 ;
}
void F_139 ( struct V_219 * V_180 , unsigned int V_229 , int V_228 )
{
if ( V_180 -> V_239 && ( V_229 >= V_180 -> V_240 ) ) {
V_229 -= V_180 -> V_240 ;
V_229 += V_180 -> V_233 ;
} else {
V_229 -= V_180 -> V_235 ;
}
F_130 ( & V_180 -> V_230 ) ;
if ( V_228 == V_231 )
F_140 ( V_229 , V_180 -> V_232 ) ;
else
F_141 ( V_180 -> V_232 , V_229 , 1 ) ;
V_180 -> V_234 [ V_229 ] . V_109 = NULL ;
if ( V_229 < V_180 -> V_233 ) {
if ( V_228 == V_236 ) {
V_180 -> V_237 -= 2 ;
V_180 -> V_238 -= 2 ;
} else {
V_180 -> V_237 -- ;
}
} else {
V_180 -> V_241 -- ;
}
F_131 ( & V_180 -> V_230 ) ;
}
static void F_142 ( struct V_193 * V_194 , unsigned int V_242 ,
unsigned int V_243 )
{
struct V_244 * V_245 ;
F_143 ( V_194 , V_246 , V_242 ) ;
V_245 = F_144 ( V_194 , sizeof( * V_245 ) ) ;
F_145 ( V_245 , V_243 ) ;
F_146 ( V_245 ) = F_147 ( F_148 ( V_247 , V_243 ) ) ;
}
static void F_149 ( struct V_219 * V_180 , unsigned int V_242 ,
unsigned int V_243 )
{
void * * V_6 = & V_180 -> V_248 [ V_243 ] ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_249 ) ;
F_130 ( & V_13 -> V_250 ) ;
* V_6 = V_13 -> V_251 ;
V_13 -> V_251 = ( void * * ) ( ( V_252 ) V_6 | V_242 ) ;
if ( ! V_13 -> V_253 ) {
V_13 -> V_253 = true ;
F_150 ( V_13 -> V_254 , & V_13 -> V_255 ) ;
}
F_131 ( & V_13 -> V_250 ) ;
}
static void F_151 ( struct V_256 * V_257 )
{
struct V_193 * V_194 ;
struct V_12 * V_13 ;
V_13 = F_54 ( V_257 , struct V_12 , V_255 ) ;
F_130 ( & V_13 -> V_250 ) ;
while ( V_13 -> V_251 ) {
void * * V_6 = V_13 -> V_251 ;
unsigned int V_242 = ( V_252 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_242 ;
V_13 -> V_251 = * V_6 ;
* V_6 = NULL ;
F_131 ( & V_13 -> V_250 ) ;
while ( ! ( V_194 = F_152 ( sizeof( struct V_244 ) ,
V_156 ) ) )
F_153 ( 1 ) ;
F_142 ( V_194 , V_242 , V_6 - V_13 -> V_249 . V_248 ) ;
F_154 ( V_13 , V_194 ) ;
F_130 ( & V_13 -> V_250 ) ;
}
V_13 -> V_253 = false ;
F_131 ( & V_13 -> V_250 ) ;
}
void F_155 ( struct V_219 * V_180 , unsigned int V_242 , unsigned int V_243 ,
unsigned short V_228 )
{
struct V_193 * V_194 ;
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_249 ) ;
F_156 ( V_243 >= V_180 -> V_258 ) ;
if ( V_180 -> V_248 [ V_243 ] ) {
V_180 -> V_248 [ V_243 ] = NULL ;
F_157 ( & V_180 -> V_259 ) ;
if ( V_180 -> V_260 && ( V_243 >= V_180 -> V_260 ) ) {
if ( V_228 == V_261 )
F_158 ( 2 , & V_180 -> V_262 ) ;
else
F_157 ( & V_180 -> V_262 ) ;
} else {
if ( V_228 == V_261 )
F_158 ( 2 , & V_180 -> V_263 ) ;
else
F_157 ( & V_180 -> V_263 ) ;
}
}
V_194 = F_152 ( sizeof( struct V_244 ) , V_60 ) ;
if ( F_52 ( V_194 ) ) {
F_142 ( V_194 , V_242 , V_243 ) ;
F_154 ( V_13 , V_194 ) ;
} else
F_149 ( V_180 , V_242 , V_243 ) ;
}
static int F_159 ( struct V_219 * V_180 )
{
struct V_12 * V_13 = F_54 ( V_180 , struct V_12 , V_249 ) ;
unsigned int V_264 = V_180 -> V_265 + V_180 -> V_239 ;
unsigned int V_266 = V_180 -> V_266 ;
unsigned int V_267 ;
unsigned int V_268 ;
T_9 V_269 ;
V_267 = F_160 ( V_180 -> V_233 + V_180 -> V_239 ) ;
V_268 = F_160 ( V_180 -> V_265 ) ;
V_269 = V_180 -> V_258 * sizeof( * V_180 -> V_248 ) +
V_266 * sizeof( * V_180 -> V_224 ) +
V_180 -> V_233 * sizeof( * V_180 -> V_234 ) +
V_180 -> V_239 * sizeof( * V_180 -> V_234 ) +
V_267 * sizeof( long ) +
V_264 * sizeof( * V_180 -> V_270 ) +
V_268 * sizeof( long ) ;
V_180 -> V_248 = F_161 ( V_269 , V_156 ) ;
if ( ! V_180 -> V_248 )
return - V_61 ;
V_180 -> V_224 = (union V_223 * ) & V_180 -> V_248 [ V_180 -> V_258 ] ;
V_180 -> V_234 = (struct V_271 * ) & V_180 -> V_224 [ V_266 ] ;
V_180 -> V_232 = ( unsigned long * ) & V_180 -> V_234 [ V_180 -> V_233 + V_180 -> V_239 ] ;
V_180 -> V_270 = (struct V_272 * ) & V_180 -> V_232 [ V_267 ] ;
V_180 -> V_273 = ( unsigned long * ) & V_180 -> V_270 [ V_264 ] ;
F_162 ( & V_180 -> V_230 ) ;
F_162 ( & V_180 -> V_221 ) ;
F_162 ( & V_180 -> V_274 ) ;
V_180 -> V_237 = 0 ;
V_180 -> V_238 = 0 ;
V_180 -> V_241 = 0 ;
V_180 -> V_222 = NULL ;
V_180 -> V_227 = 0 ;
F_163 ( & V_180 -> V_263 , 0 ) ;
F_163 ( & V_180 -> V_259 , 0 ) ;
F_163 ( & V_180 -> V_262 , 0 ) ;
if ( V_266 ) {
while ( -- V_266 )
V_180 -> V_224 [ V_266 - 1 ] . V_226 = & V_180 -> V_224 [ V_266 ] ;
V_180 -> V_222 = V_180 -> V_224 ;
}
if ( F_164 ( V_13 ) ) {
F_96 ( V_180 -> V_232 , V_180 -> V_233 + V_180 -> V_239 ) ;
if ( ! V_180 -> V_235 &&
F_165 ( V_13 -> V_188 . V_189 ) <= V_275 )
F_135 ( 0 , V_180 -> V_232 ) ;
}
F_96 ( V_180 -> V_273 , V_180 -> V_265 ) ;
return 0 ;
}
int F_166 ( const struct V_1 * V_2 , unsigned int V_229 ,
T_10 V_276 , T_11 V_277 , T_11 V_278 ,
unsigned int V_279 )
{
unsigned int V_242 ;
struct V_193 * V_194 ;
struct V_12 * V_13 ;
struct V_280 * V_245 ;
int V_54 ;
V_194 = F_152 ( sizeof( * V_245 ) , V_156 ) ;
if ( ! V_194 )
return - V_61 ;
V_13 = F_167 ( V_2 ) ;
V_245 = F_144 ( V_194 , sizeof( * V_245 ) ) ;
F_145 ( V_245 , 0 ) ;
F_146 ( V_245 ) = F_147 ( F_148 ( V_281 , V_229 ) ) ;
V_245 -> V_282 = V_277 ;
V_245 -> V_283 = F_114 ( 0 ) ;
V_245 -> V_284 = V_276 ;
V_245 -> V_285 = F_147 ( 0 ) ;
V_242 = F_85 ( & V_13 -> V_16 , V_279 ) ;
V_245 -> V_286 = F_168 ( F_169 ( V_242 ) ) ;
V_245 -> V_287 = F_168 ( F_170 ( V_288 ) |
V_289 | F_171 ( V_279 ) ) ;
V_54 = F_172 ( V_13 , V_194 ) ;
return F_173 ( V_54 ) ;
}
int F_174 ( const struct V_1 * V_2 , unsigned int V_229 ,
const struct V_290 * V_276 , T_11 V_277 ,
unsigned int V_279 )
{
unsigned int V_242 ;
struct V_193 * V_194 ;
struct V_12 * V_13 ;
struct V_291 * V_245 ;
int V_54 ;
V_194 = F_152 ( sizeof( * V_245 ) , V_156 ) ;
if ( ! V_194 )
return - V_61 ;
V_13 = F_167 ( V_2 ) ;
V_245 = F_144 ( V_194 , sizeof( * V_245 ) ) ;
F_145 ( V_245 , 0 ) ;
F_146 ( V_245 ) = F_147 ( F_148 ( V_292 , V_229 ) ) ;
V_245 -> V_282 = V_277 ;
V_245 -> V_283 = F_114 ( 0 ) ;
V_245 -> V_293 = * ( T_4 * ) ( V_276 -> V_294 ) ;
V_245 -> V_295 = * ( T_4 * ) ( V_276 -> V_294 + 8 ) ;
V_245 -> V_296 = F_168 ( 0 ) ;
V_245 -> V_297 = F_168 ( 0 ) ;
V_242 = F_85 ( & V_13 -> V_16 , V_279 ) ;
V_245 -> V_286 = F_168 ( F_169 ( V_242 ) ) ;
V_245 -> V_287 = F_168 ( F_170 ( V_288 ) |
V_289 | F_171 ( V_279 ) ) ;
V_54 = F_172 ( V_13 , V_194 ) ;
return F_173 ( V_54 ) ;
}
int F_175 ( const struct V_1 * V_2 , unsigned int V_229 ,
unsigned int V_279 , bool V_298 )
{
struct V_193 * V_194 ;
struct V_12 * V_13 ;
struct V_299 * V_245 ;
int V_54 ;
V_13 = F_167 ( V_2 ) ;
V_194 = F_152 ( sizeof( * V_245 ) , V_156 ) ;
if ( ! V_194 )
return - V_61 ;
V_245 = F_144 ( V_194 , sizeof( * V_245 ) ) ;
F_145 ( V_245 , 0 ) ;
F_146 ( V_245 ) = F_147 ( F_148 ( V_300 , V_229 ) ) ;
V_245 -> V_301 = F_114 ( F_176 ( 0 ) | ( V_298 ? F_177 ( 1 ) :
F_177 ( 0 ) ) | F_178 ( V_279 ) ) ;
V_54 = F_172 ( V_13 , V_194 ) ;
return F_173 ( V_54 ) ;
}
unsigned int F_179 ( const unsigned short * V_302 , unsigned short V_66 ,
unsigned int * V_184 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_303 - 1 && V_302 [ V_19 + 1 ] <= V_66 )
++ V_19 ;
if ( V_184 )
* V_184 = V_19 ;
return V_302 [ V_19 ] ;
}
unsigned int F_180 ( const unsigned short * V_302 ,
unsigned short V_304 ,
unsigned short V_305 ,
unsigned short V_306 ,
unsigned int * V_307 )
{
unsigned short V_308 = V_304 + V_305 ;
unsigned short V_309 = V_306 - 1 ;
int V_310 , V_311 ;
for ( V_310 = 0 , V_311 = - 1 ; V_310 < V_303 ; V_310 ++ ) {
unsigned short V_312 = V_302 [ V_310 ] - V_304 ;
if ( ( V_312 & V_309 ) == 0 )
V_311 = V_310 ;
if ( V_310 + 1 < V_303 && V_302 [ V_310 + 1 ] > V_308 )
break;
}
if ( V_310 == V_303 )
V_310 -- ;
if ( V_311 >= 0 &&
V_310 - V_311 <= 1 )
V_310 = V_311 ;
if ( V_307 )
* V_307 = V_310 ;
return V_302 [ V_310 ] ;
}
unsigned int F_181 ( enum V_313 V_189 , unsigned int V_51 )
{
if ( F_165 ( V_189 ) <= V_275 )
return ( ( V_51 & 0x7f ) << 1 ) ;
else
return ( V_51 & 0x7f ) ;
}
unsigned int F_182 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_76 ;
}
unsigned int F_183 ( const struct V_1 * V_2 , int V_314 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
T_1 V_315 , V_316 , V_317 , V_318 ;
V_315 = F_68 ( V_13 , V_319 ) ;
V_316 = F_68 ( V_13 , V_320 ) ;
if ( F_105 ( V_13 -> V_188 . V_189 ) ) {
V_317 = F_184 ( V_315 ) ;
V_318 = F_185 ( V_315 ) ;
} else {
V_317 = F_186 ( V_315 ) ;
V_318 = F_187 ( V_316 ) ;
}
return V_314 ? V_317 : V_318 ;
}
unsigned int F_188 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_51 ;
}
unsigned int F_189 ( const struct V_1 * V_2 )
{
return F_86 ( V_2 ) -> V_31 ;
}
void F_190 ( struct V_321 * V_128 , struct V_322 * V_323 ,
struct V_322 * V_324 )
{
struct V_12 * V_13 = F_191 ( V_128 ) ;
F_192 ( & V_13 -> V_325 ) ;
F_193 ( V_13 , V_323 , V_324 ) ;
F_194 ( & V_13 -> V_325 ) ;
}
void F_195 ( struct V_1 * V_2 , unsigned int V_326 ,
const unsigned int * V_327 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
F_70 ( V_13 , V_328 , V_326 ) ;
F_70 ( V_13 , V_329 , F_196 ( V_327 [ 0 ] ) |
F_197 ( V_327 [ 1 ] ) | F_198 ( V_327 [ 2 ] ) |
F_199 ( V_327 [ 3 ] ) ) ;
}
int F_200 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
return F_201 ( V_13 , V_13 -> V_27 ) ;
}
static int F_202 ( struct V_12 * V_13 , T_6 V_95 , T_6 * V_330 , T_6 * V_331 )
{
T_1 V_50 = F_68 ( V_13 , V_332 ) + 24 * V_95 + 8 ;
T_4 V_333 ;
int V_54 ;
F_192 ( & V_13 -> V_334 ) ;
V_54 = F_203 ( V_13 , 0 , V_335 , V_50 ,
sizeof( V_333 ) , ( T_10 * ) & V_333 ,
V_336 ) ;
F_194 ( & V_13 -> V_334 ) ;
if ( ! V_54 ) {
* V_331 = ( F_204 ( V_333 ) >> 25 ) & 0xffff ;
* V_330 = ( F_204 ( V_333 ) >> 9 ) & 0xffff ;
}
return V_54 ;
}
int F_205 ( struct V_1 * V_2 , T_6 V_95 , T_6 V_330 ,
T_6 V_269 )
{
struct V_12 * V_13 = F_167 ( V_2 ) ;
T_6 V_337 , V_338 ;
int V_54 ;
V_54 = F_202 ( V_13 , V_95 , & V_337 , & V_338 ) ;
if ( V_54 )
goto V_59;
if ( V_330 != V_337 ) {
T_6 V_205 ;
T_1 V_339 ;
if ( V_330 >= V_337 )
V_205 = V_330 - V_337 ;
else
V_205 = V_269 - V_337 + V_330 ;
if ( F_105 ( V_13 -> V_188 . V_189 ) )
V_339 = F_206 ( V_205 ) ;
else
V_339 = F_207 ( V_205 ) ;
F_208 () ;
F_70 ( V_13 , F_69 ( V_340 ) ,
F_209 ( V_95 ) | V_339 ) ;
}
V_59:
return V_54 ;
}
int F_210 ( struct V_1 * V_2 , T_1 V_341 , T_10 * V_342 )
{
struct V_12 * V_13 ;
T_1 V_343 , V_344 , V_345 ;
T_1 V_346 , V_347 , V_348 , V_349 , V_269 ;
T_1 V_350 , V_351 , V_352 , V_353 ;
int V_54 ;
V_13 = F_167 ( V_2 ) ;
V_343 = ( ( V_341 >> 8 ) * 32 ) + V_13 -> V_354 . V_341 . V_355 ;
V_269 = F_68 ( V_13 , V_356 ) ;
V_346 = F_211 ( V_269 ) << 20 ;
V_269 = F_68 ( V_13 , V_357 ) ;
V_347 = F_212 ( V_269 ) << 20 ;
V_269 = F_68 ( V_13 , V_358 ) ;
V_348 = F_213 ( V_269 ) << 20 ;
V_350 = V_346 ;
V_351 = V_350 + V_347 ;
V_352 = V_351 + V_348 ;
if ( V_343 < V_350 ) {
V_344 = V_335 ;
V_345 = V_343 ;
} else if ( V_343 < V_351 ) {
V_344 = V_359 ;
V_345 = V_343 - V_350 ;
} else {
if ( V_343 < V_352 ) {
V_344 = V_360 ;
V_345 = V_343 - V_351 ;
} else if ( F_214 ( V_13 -> V_188 . V_189 ) ) {
V_269 = F_68 ( V_13 , V_361 ) ;
V_349 = F_215 ( V_269 ) << 20 ;
V_353 = V_352 + V_349 ;
if ( V_343 < V_353 ) {
V_344 = V_362 ;
V_345 = V_343 - V_352 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_192 ( & V_13 -> V_334 ) ;
V_54 = F_203 ( V_13 , 0 , V_344 , V_345 , 32 , V_342 , V_336 ) ;
F_194 ( & V_13 -> V_334 ) ;
return V_54 ;
V_22:
F_11 ( V_13 -> V_30 , L_35 ,
V_341 , V_343 ) ;
return - V_65 ;
}
T_2 F_216 ( struct V_1 * V_2 )
{
T_1 V_363 , V_364 ;
struct V_12 * V_13 ;
V_13 = F_167 ( V_2 ) ;
V_364 = F_68 ( V_13 , V_365 ) ;
V_363 = F_217 ( F_68 ( V_13 , V_366 ) ) ;
return ( ( T_2 ) V_363 << 32 ) | ( T_2 ) V_364 ;
}
int F_218 ( struct V_1 * V_2 ,
unsigned int V_95 ,
enum V_367 V_368 ,
int V_369 ,
T_2 * V_370 ,
unsigned int * V_371 )
{
return F_219 ( F_167 ( V_2 ) ,
V_95 ,
( V_368 == V_372
? V_373
: V_374 ) ,
V_369 ,
V_370 ,
V_371 ) ;
}
static void F_220 ( struct V_375 * V_376 )
{
const struct V_377 * V_378 ;
const struct V_1 * V_52 = V_376 -> V_2 ;
if ( F_221 ( V_52 ) )
V_52 = F_222 ( V_52 ) ;
V_378 = V_52 -> V_2 . V_378 ;
if ( V_378 && V_378 -> V_379 == & V_380 . V_379 )
F_223 ( F_224 ( V_378 ) , V_376 ) ;
}
static int F_225 ( struct V_381 * V_382 , unsigned long V_383 ,
void * V_109 )
{
switch ( V_383 ) {
case V_384 :
F_220 ( V_109 ) ;
break;
case V_385 :
default:
break;
}
return 0 ;
}
static void F_226 ( struct V_12 * V_13 , int V_386 )
{
T_1 V_315 , V_316 , V_317 , V_318 ;
do {
V_315 = F_68 ( V_13 , V_319 ) ;
V_316 = F_68 ( V_13 , V_320 ) ;
if ( F_105 ( V_13 -> V_188 . V_189 ) ) {
V_317 = F_184 ( V_315 ) ;
V_318 = F_185 ( V_315 ) ;
} else {
V_317 = F_186 ( V_315 ) ;
V_318 = F_187 ( V_316 ) ;
}
if ( V_317 == 0 && V_318 == 0 )
break;
F_227 ( V_387 ) ;
F_228 ( F_229 ( V_386 ) ) ;
} while ( 1 );
}
static void F_230 ( struct V_97 * V_25 )
{
unsigned long V_68 ;
F_231 ( & V_25 -> V_388 , V_68 ) ;
V_25 -> V_389 = 1 ;
F_232 ( & V_25 -> V_388 , V_68 ) ;
}
static void F_233 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
F_234 ( & V_25 -> V_388 ) ;
if ( V_25 -> V_390 ) {
F_208 () ;
F_70 ( V_13 , F_69 ( V_340 ) ,
F_209 ( V_25 -> V_26 ) | F_206 ( V_25 -> V_390 ) ) ;
V_25 -> V_390 = 0 ;
}
V_25 -> V_389 = 0 ;
F_235 ( & V_25 -> V_388 ) ;
}
static void F_236 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_230 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_391 * V_392 =
V_13 -> V_16 . V_393 [ V_394 ] ;
if ( V_392 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_392 -> V_395 [ V_19 ] ;
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
struct V_391 * V_392 =
V_13 -> V_16 . V_393 [ V_394 ] ;
if ( V_392 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_392 -> V_395 [ V_19 ] ;
F_233 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_233 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_239 ( struct V_12 * V_13 , enum V_396 V_110 )
{
enum V_397 type = V_179 ;
if ( V_13 -> V_398 && V_13 -> V_398 [ type ] . V_399 )
V_13 -> V_398 [ type ] . F_240 ( V_13 -> V_398 [ type ] . V_399 , V_110 ) ;
}
static void F_241 ( struct V_256 * V_257 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_257 , struct V_12 , V_400 ) ;
F_226 ( V_13 , V_401 ) ;
F_238 ( V_13 ) ;
F_239 ( V_13 , V_402 ) ;
if ( F_165 ( V_13 -> V_188 . V_189 ) <= V_275 )
F_242 ( V_13 , V_403 ,
V_404 | V_405 ,
V_404 | V_405 ) ;
else
F_242 ( V_13 , V_403 ,
V_405 , V_405 ) ;
}
static void F_243 ( struct V_12 * V_13 , struct V_97 * V_25 )
{
T_6 V_337 , V_338 ;
int V_54 ;
F_234 ( & V_25 -> V_388 ) ;
V_54 = F_202 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_337 , & V_338 ) ;
if ( V_54 )
goto V_59;
if ( V_25 -> V_406 != V_337 ) {
T_6 V_205 ;
T_1 V_339 ;
if ( V_25 -> V_406 >= V_337 )
V_205 = V_25 -> V_406 - V_337 ;
else
V_205 = V_25 -> V_269 - V_337 + V_25 -> V_406 ;
if ( F_105 ( V_13 -> V_188 . V_189 ) )
V_339 = F_206 ( V_205 ) ;
else
V_339 = F_207 ( V_205 ) ;
F_208 () ;
F_70 ( V_13 , F_69 ( V_340 ) ,
F_209 ( V_25 -> V_26 ) | V_339 ) ;
}
V_59:
V_25 -> V_389 = 0 ;
V_25 -> V_390 = 0 ;
F_235 ( & V_25 -> V_388 ) ;
if ( V_54 )
F_244 ( V_13 , L_36 ) ;
}
static void F_245 ( struct V_12 * V_13 )
{
int V_19 ;
F_76 (&adap->sge, i)
F_243 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
if ( F_164 ( V_13 ) ) {
struct V_391 * V_392 =
V_13 -> V_16 . V_393 [ V_394 ] ;
if ( V_392 ) {
F_237 (&adap->sge, i) {
struct V_104 * V_15 = & V_392 -> V_395 [ V_19 ] ;
F_243 ( V_13 , & V_15 -> V_25 ) ;
}
}
}
F_73 (adap, i)
F_243 ( V_13 , & V_13 -> V_16 . V_187 [ V_19 ] . V_25 ) ;
}
static void F_246 ( struct V_256 * V_257 )
{
struct V_12 * V_13 ;
V_13 = F_54 ( V_257 , struct V_12 , V_407 ) ;
if ( F_105 ( V_13 -> V_188 . V_189 ) ) {
F_226 ( V_13 , V_401 ) ;
F_239 ( V_13 , V_408 ) ;
F_226 ( V_13 , V_401 ) ;
F_245 ( V_13 ) ;
F_226 ( V_13 , V_401 ) ;
F_238 ( V_13 ) ;
F_239 ( V_13 , V_402 ) ;
} else if ( F_214 ( V_13 -> V_188 . V_189 ) ) {
T_1 V_409 = F_68 ( V_13 , 0x010ac ) ;
T_6 V_95 = ( V_409 >> 15 ) & 0x1ffff ;
T_6 V_410 = V_409 & 0x1fff ;
T_2 V_411 ;
unsigned int V_412 ;
int V_54 ;
V_54 = F_219 ( V_13 , V_95 , V_373 ,
0 , & V_411 , & V_412 ) ;
if ( V_54 )
F_11 ( V_13 -> V_30 , L_37
L_38 , V_95 , V_410 ) ;
else
F_247 ( F_207 ( V_410 ) | F_209 ( V_412 ) ,
V_13 -> V_413 + V_411 + V_414 ) ;
F_242 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_165 ( V_13 -> V_188 . V_189 ) <= V_275 )
F_242 ( V_13 , V_415 , V_416 , 0 ) ;
}
void F_248 ( struct V_12 * V_13 )
{
if ( F_105 ( V_13 -> V_188 . V_189 ) ) {
F_236 ( V_13 ) ;
F_239 ( V_13 , V_417 ) ;
F_242 ( V_13 , V_403 ,
V_404 | V_405 , 0 ) ;
F_150 ( V_13 -> V_254 , & V_13 -> V_400 ) ;
}
}
void F_249 ( struct V_12 * V_13 )
{
if ( F_105 ( V_13 -> V_188 . V_189 ) ) {
F_236 ( V_13 ) ;
F_239 ( V_13 , V_417 ) ;
}
F_150 ( V_13 -> V_254 , & V_13 -> V_407 ) ;
}
void F_250 ( void )
{
if ( ! V_418 ) {
F_251 ( & V_419 ) ;
V_418 = true ;
}
}
static void F_252 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_253 ( & V_420 ) ;
F_33 ( & V_13 -> V_421 ) ;
for ( V_19 = 0 ; V_19 < V_422 ; V_19 ++ )
if ( V_13 -> V_398 && V_13 -> V_398 [ V_19 ] . V_399 )
V_13 -> V_398 [ V_19 ] . F_254 ( V_13 -> V_398 [ V_19 ] . V_399 ,
V_423 ) ;
if ( V_418 && F_255 ( & V_424 ) ) {
F_256 ( & V_419 ) ;
V_418 = false ;
}
F_257 ( & V_420 ) ;
}
static void F_258 ( struct V_12 * V_13 , enum V_425 V_426 )
{
unsigned int V_19 ;
F_253 ( & V_420 ) ;
for ( V_19 = 0 ; V_19 < V_422 ; V_19 ++ )
if ( V_13 -> V_398 && V_13 -> V_398 [ V_19 ] . V_399 )
V_13 -> V_398 [ V_19 ] . F_254 ( V_13 -> V_398 [ V_19 ] . V_399 ,
V_426 ) ;
F_257 ( & V_420 ) ;
}
static int F_259 ( struct V_381 * V_427 ,
unsigned long V_383 , void * V_109 )
{
struct V_428 * V_429 = V_109 ;
struct V_1 * V_430 = V_429 -> V_431 -> V_2 ;
const struct V_377 * V_378 = NULL ;
#if F_260 ( V_432 )
struct V_12 * V_13 ;
#endif
if ( F_221 ( V_430 ) )
V_430 = F_222 ( V_430 ) ;
#if F_260 ( V_432 )
if ( V_430 -> V_68 & V_433 ) {
F_22 (adap, &adapter_list, list_node) {
switch ( V_383 ) {
case V_434 :
F_261 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_429 , 1 ) ;
break;
case V_435 :
F_262 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_429 , 1 ) ;
break;
default:
break;
}
}
return V_436 ;
}
#endif
if ( V_430 )
V_378 = V_430 -> V_2 . V_378 ;
if ( V_378 && V_378 -> V_379 == & V_380 . V_379 ) {
switch ( V_383 ) {
case V_434 :
F_261 ( V_430 , ( const T_1 * ) V_429 , 1 ) ;
break;
case V_435 :
F_262 ( V_430 , ( const T_1 * ) V_429 , 1 ) ;
break;
default:
break;
}
}
return V_436 ;
}
static void F_263 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_54 ;
F_264 () ;
for ( V_19 = 0 ; V_19 < V_437 ; V_19 ++ ) {
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
F_253 ( & V_420 ) ;
V_22 = F_99 ( V_13 ) ;
if ( V_22 )
goto V_438;
V_22 = F_83 ( V_13 ) ;
if ( V_22 )
goto V_439;
if ( V_13 -> V_68 & V_127 ) {
F_72 ( V_13 ) ;
V_22 = F_75 ( V_13 -> V_141 [ 0 ] . V_46 , F_67 , 0 ,
V_13 -> V_141 [ 0 ] . V_142 , V_13 ) ;
if ( V_22 )
goto V_440;
V_22 = F_74 ( V_13 ) ;
if ( V_22 ) {
F_77 ( V_13 -> V_141 [ 0 ] . V_46 , V_13 ) ;
goto V_440;
}
} else {
V_22 = F_75 ( V_13 -> V_128 -> V_130 , F_268 ( V_13 ) ,
( V_13 -> V_68 & V_129 ) ? 0 : V_441 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_440;
}
F_91 ( V_13 ) ;
F_269 ( V_13 ) ;
F_270 ( V_13 ) ;
V_13 -> V_68 |= V_168 ;
F_257 ( & V_420 ) ;
F_258 ( V_13 , V_442 ) ;
#if F_260 ( V_443 )
F_263 ( V_13 ) ;
#endif
F_271 ( & V_13 -> V_63 ) ;
return V_22 ;
V_440:
F_11 ( V_13 -> V_30 , L_39 , V_22 ) ;
V_439:
F_98 ( V_13 ) ;
V_438:
F_257 ( & V_420 ) ;
return V_22 ;
}
static void F_272 ( struct V_12 * V_12 )
{
F_273 ( & V_12 -> V_255 ) ;
F_273 ( & V_12 -> V_400 ) ;
F_273 ( & V_12 -> V_407 ) ;
V_12 -> V_253 = false ;
V_12 -> V_251 = NULL ;
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
int F_281 ( const struct V_1 * V_2 , unsigned int V_229 ,
T_10 V_276 , T_11 V_277 , T_11 V_278 ,
unsigned int V_279 , unsigned char V_39 , unsigned char V_444 )
{
int V_54 ;
struct V_272 * V_445 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_339 ;
V_13 = F_167 ( V_2 ) ;
V_229 -= V_13 -> V_249 . V_240 ;
V_229 += V_13 -> V_249 . V_265 ;
V_445 = & V_13 -> V_249 . V_270 [ V_229 ] ;
V_54 = F_282 ( V_445 ) ;
if ( V_54 )
return V_54 ;
if ( V_445 -> V_446 )
F_283 ( V_13 , V_445 ) ;
memset ( & V_445 -> V_447 , 0 , sizeof( struct V_448 ) ) ;
V_445 -> V_447 . V_339 . V_449 = F_284 ( V_277 ) ;
V_445 -> V_447 . V_444 . V_449 = ~ 0 ;
V_339 = ( T_3 * ) & V_276 ;
if ( ( V_339 [ 0 ] | V_339 [ 1 ] | V_339 [ 2 ] | V_339 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_445 -> V_447 . V_339 . V_450 [ V_19 ] = V_339 [ V_19 ] ;
V_445 -> V_447 . V_444 . V_450 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_188 . V_451 . V_452 & V_453 ) {
V_445 -> V_447 . V_339 . V_454 = V_39 ;
V_445 -> V_447 . V_444 . V_454 = V_444 ;
}
}
if ( V_13 -> V_188 . V_451 . V_452 & V_455 ) {
V_445 -> V_447 . V_339 . V_456 = V_457 ;
V_445 -> V_447 . V_444 . V_456 = ~ 0 ;
}
V_445 -> V_447 . V_458 = 1 ;
V_445 -> V_447 . V_459 = V_279 ;
V_445 -> V_460 = 1 ;
V_445 -> V_447 . V_461 = 1 ;
V_445 -> V_243 = V_229 + V_13 -> V_249 . V_462 ;
V_54 = F_285 ( V_13 , V_229 ) ;
if ( V_54 ) {
F_283 ( V_13 , V_445 ) ;
return V_54 ;
}
return 0 ;
}
int F_286 ( const struct V_1 * V_2 , unsigned int V_229 ,
unsigned int V_279 , bool V_298 )
{
struct V_272 * V_445 ;
struct V_12 * V_13 ;
V_13 = F_167 ( V_2 ) ;
V_229 -= V_13 -> V_249 . V_240 ;
V_229 += V_13 -> V_249 . V_265 ;
V_445 = & V_13 -> V_249 . V_270 [ V_229 ] ;
V_445 -> V_460 = 0 ;
return F_287 ( V_13 , V_229 ) ;
}
static void F_288 ( struct V_1 * V_2 ,
struct V_463 * V_464 )
{
struct V_465 V_185 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_192 ( & V_12 -> V_325 ) ;
if ( ! F_289 ( V_2 ) ) {
F_194 ( & V_12 -> V_325 ) ;
return;
}
F_290 ( V_12 , V_6 -> V_76 , & V_185 ,
& V_6 -> V_466 ) ;
F_194 ( & V_12 -> V_325 ) ;
V_464 -> V_467 = V_185 . V_468 ;
V_464 -> V_469 = V_185 . V_470 ;
V_464 -> V_471 = V_185 . V_472 ;
V_464 -> V_473 = V_185 . V_474 ;
V_464 -> V_475 = V_185 . V_476 ;
V_464 -> V_477 = V_185 . V_478 + V_185 . V_479 +
V_185 . V_480 ;
V_464 -> V_481 = 0 ;
V_464 -> V_482 = V_185 . V_483 ;
V_464 -> V_484 = V_185 . V_485 ;
V_464 -> V_486 = V_185 . V_487 + V_185 . V_488 +
V_185 . V_489 + V_185 . V_490 +
V_185 . V_491 + V_185 . V_492 +
V_185 . V_493 + V_185 . V_494 ;
V_464 -> V_495 = 0 ;
V_464 -> V_496 = 0 ;
V_464 -> V_497 = 0 ;
V_464 -> V_498 = 0 ;
V_464 -> V_499 = 0 ;
V_464 -> V_500 = 0 ;
V_464 -> V_501 = V_185 . V_502 ;
V_464 -> V_503 = V_185 . V_485 + V_185 . V_483 +
V_464 -> V_477 + V_185 . V_504 + V_464 -> V_505 ;
}
static int F_291 ( struct V_1 * V_2 , struct V_506 * V_245 , int V_110 )
{
unsigned int V_27 ;
int V_54 = 0 , V_507 , V_508 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
struct V_509 * V_109 = (struct V_509 * ) & V_245 -> V_510 ;
switch ( V_110 ) {
case V_511 :
if ( V_11 -> V_512 < 0 )
return - V_513 ;
V_109 -> V_514 = V_11 -> V_512 ;
break;
case V_515 :
case V_516 :
if ( F_292 ( V_109 -> V_514 ) ) {
V_507 = F_293 ( V_109 -> V_514 ) ;
V_508 = F_294 ( V_109 -> V_514 ) ;
} else if ( V_109 -> V_514 < 32 ) {
V_507 = V_109 -> V_514 ;
V_508 = 0 ;
V_109 -> V_517 &= 0x1f ;
} else
return - V_65 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_110 == V_515 )
V_54 = F_295 ( V_11 -> V_12 , V_27 , V_507 , V_508 ,
V_109 -> V_517 , & V_109 -> V_518 ) ;
else
V_54 = F_296 ( V_11 -> V_12 , V_27 , V_507 , V_508 ,
V_109 -> V_517 , V_109 -> V_519 ) ;
break;
case V_520 :
return F_297 ( V_245 -> V_510 , & V_11 -> V_521 ,
sizeof( V_11 -> V_521 ) ) ?
- V_522 : 0 ;
case V_523 :
if ( F_298 ( & V_11 -> V_521 , V_245 -> V_510 ,
sizeof( V_11 -> V_521 ) ) )
return - V_522 ;
if ( ! F_105 ( V_12 -> V_188 . V_189 ) ) {
switch ( V_11 -> V_521 . V_524 ) {
case V_525 :
case V_526 :
break;
default:
return - V_527 ;
}
switch ( V_11 -> V_521 . V_528 ) {
case V_529 :
V_11 -> V_530 = false ;
break;
case V_531 :
case V_532 :
F_299 ( V_11 , V_11 -> V_31 ,
V_533 ) ;
break;
case V_534 :
F_299 ( V_11 , V_11 -> V_31 ,
V_535 ) ;
break;
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_540 :
V_11 -> V_530 = true ;
break;
default:
V_11 -> V_521 . V_528 =
V_529 ;
return - V_527 ;
}
if ( ( V_11 -> V_521 . V_524 == V_525 ) &&
( V_11 -> V_521 . V_528 ==
V_529 ) ) {
if ( F_300 ( V_12 , V_11 -> V_31 ) >= 0 )
V_11 -> V_541 = false ;
}
if ( V_11 -> V_521 . V_528 !=
V_529 ) {
if ( F_301 ( V_12 ,
V_11 ) >= 0 )
V_11 -> V_541 = true ;
}
} else {
switch ( V_11 -> V_521 . V_528 ) {
case V_529 :
V_11 -> V_530 = false ;
break;
case V_536 :
V_11 -> V_530 = true ;
break;
default:
V_11 -> V_521 . V_528 =
V_529 ;
return - V_527 ;
}
}
return F_297 ( V_245 -> V_510 , & V_11 -> V_521 ,
sizeof( V_11 -> V_521 ) ) ?
- V_522 : 0 ;
default:
return - V_513 ;
}
return V_54 ;
}
static void F_302 ( struct V_1 * V_2 )
{
F_36 ( V_2 , - 1 , false ) ;
}
static int F_303 ( struct V_1 * V_2 , int V_542 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
V_54 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , V_542 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_54 )
V_2 -> V_66 = V_542 ;
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
T_3 V_543 [ V_544 ] , V_545 [ V_544 ] ;
int V_22 ;
T_3 * V_546 ;
T_6 V_547 , V_548 ;
V_22 = F_306 ( V_13 , & V_13 -> V_188 . V_549 ) ;
if ( ! V_22 ) {
V_546 = V_13 -> V_188 . V_549 . V_546 ;
for ( V_19 = 0 ; V_19 < V_544 ; V_19 ++ )
V_543 [ V_19 ] = ( F_307 ( V_546 [ 2 * V_19 + 0 ] ) * 16 +
F_307 ( V_546 [ 2 * V_19 + 1 ] ) ) ;
V_547 = ( V_543 [ 0 ] << 8 ) | V_543 [ 1 ] ;
V_548 = ( V_543 [ 1 ] << 8 ) | V_543 [ 2 ] ;
V_547 ^= V_548 ;
V_547 |= 0x0200 ;
V_547 &= ~ 0x0100 ;
V_545 [ 0 ] = V_547 >> 8 ;
V_545 [ 1 ] = V_547 & 0xff ;
for ( V_19 = 2 ; V_19 < 5 ; V_19 ++ )
V_545 [ V_19 ] = V_543 [ V_19 + 1 ] ;
for ( V_19 = 0 ; V_19 < V_13 -> V_550 ; V_19 ++ ) {
V_545 [ 5 ] = V_13 -> V_28 * 16 + V_19 ;
F_28 ( V_13 -> V_551 [ V_19 ] . V_552 , V_545 ) ;
}
}
}
static int F_308 ( struct V_1 * V_2 , int V_553 , T_3 * V_554 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_54 ;
if ( ! F_309 ( V_554 ) ) {
F_11 ( V_11 -> V_12 -> V_30 ,
L_40 ,
V_554 , V_553 ) ;
return - V_65 ;
}
F_310 ( V_11 -> V_12 -> V_30 ,
L_41 , V_554 , V_553 ) ;
V_54 = F_311 ( V_13 , V_553 + 1 , 1 , V_554 ) ;
if ( ! V_54 )
F_28 ( V_13 -> V_551 [ V_553 ] . V_552 , V_554 ) ;
return V_54 ;
}
static int F_312 ( struct V_1 * V_2 ,
int V_553 , struct V_555 * V_556 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_553 >= V_13 -> V_550 )
return - V_65 ;
V_556 -> V_553 = V_553 ;
V_556 -> V_557 = V_13 -> V_551 [ V_553 ] . V_558 ;
V_556 -> V_559 = 0 ;
F_28 ( V_556 -> V_554 , V_13 -> V_551 [ V_553 ] . V_552 ) ;
return 0 ;
}
static int F_313 ( struct V_1 * V_2 ,
struct V_560 * V_561 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_562 ;
V_562 = V_11 -> V_12 -> V_563 * 10 + V_11 -> V_31 ;
V_561 -> V_564 = sizeof( V_562 ) ;
memcpy ( V_561 -> V_565 , & V_562 , V_561 -> V_564 ) ;
return 0 ;
}
static int F_314 ( struct V_1 * V_2 , int V_553 , int V_559 ,
int V_557 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_78 V_566 , V_567 ;
T_1 V_568 , V_8 = 0 ;
T_1 V_569 , V_570 ;
int V_571 = V_553 ;
int V_572 , V_54 ;
T_6 V_573 ;
if ( V_553 >= V_13 -> V_550 )
return - V_65 ;
if ( V_559 ) {
F_11 ( V_13 -> V_30 ,
L_42 ,
V_559 , V_553 ) ;
return - V_65 ;
}
memset ( & V_566 , 0 , sizeof( V_566 ) ) ;
V_566 . V_80 = F_315 ( F_316 ( V_113 ) |
V_574 |
V_575 |
F_317 ( V_11 -> V_31 ) ) ;
V_566 . V_112 =
F_315 ( F_318 ( V_114 ) |
F_319 ( V_566 ) ) ;
V_54 = F_320 ( V_13 , V_13 -> V_27 , & V_566 , sizeof( V_566 ) ,
& V_567 ) ;
if ( V_54 != V_576 ) {
F_11 ( V_13 -> V_30 ,
L_43 , V_553 ) ;
return - V_65 ;
}
V_568 = F_59 ( V_567 . V_116 . V_117 . V_577 ) ;
V_572 = ( V_568 & V_578 ) != 0 ;
if ( ! V_572 ) {
F_11 ( V_13 -> V_30 , L_44 , V_553 ) ;
return - V_65 ;
}
if ( V_568 & F_321 ( V_579 ) )
V_8 = 100 ;
else if ( V_568 & F_321 ( V_580 ) )
V_8 = 1000 ;
else if ( V_568 & F_321 ( V_581 ) )
V_8 = 10000 ;
else if ( V_568 & F_321 ( V_582 ) )
V_8 = 25000 ;
else if ( V_568 & F_321 ( V_583 ) )
V_8 = 40000 ;
else if ( V_568 & F_321 ( V_584 ) )
V_8 = 100000 ;
if ( V_557 > V_8 ) {
F_11 ( V_13 -> V_30 ,
L_45 ,
V_557 , V_553 , V_8 ) ;
return - V_65 ;
}
V_573 = F_322 ( V_567 . V_116 . V_117 . V_66 ) ;
V_573 = V_573 - sizeof( struct V_585 ) - 4 ;
V_573 = V_573 - sizeof( struct V_586 ) - sizeof( struct V_587 ) ;
V_54 = F_323 ( V_13 , V_588 ,
V_589 ,
V_590 ,
V_591 ,
V_592 ,
V_11 -> V_31 , V_571 , 0 ,
V_557 * 1000 , 0 , V_573 ) ;
if ( V_54 ) {
F_11 ( V_13 -> V_30 , L_46 ,
V_54 ) ;
return - V_65 ;
}
F_310 ( V_13 -> V_30 ,
L_47 ,
V_571 , V_573 , V_557 ) ;
V_569 = ( F_7 ( V_593 ) |
F_8 ( V_594 ) ) ;
V_570 = V_571 ;
V_54 = F_121 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_553 + 1 , 1 , & V_569 ,
& V_570 ) ;
if ( V_54 ) {
F_11 ( V_13 -> V_30 ,
L_48 ,
V_54 , V_553 , V_571 ) ;
return - V_65 ;
}
F_310 ( V_13 -> V_30 , L_49 ,
V_13 -> V_28 , V_553 , V_571 ) ;
V_13 -> V_551 [ V_553 ] . V_558 = V_557 ;
return 0 ;
}
static int F_324 ( struct V_1 * V_2 , void * V_6 )
{
int V_54 ;
struct V_595 * V_50 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_309 ( V_50 -> V_596 ) )
return - V_597 ;
V_54 = F_41 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 ,
V_11 -> V_74 , V_50 -> V_596 , true , true ) ;
if ( V_54 < 0 )
return V_54 ;
memcpy ( V_2 -> V_75 , V_50 -> V_596 , V_2 -> V_598 ) ;
V_11 -> V_74 = V_54 ;
return 0 ;
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_68 & V_127 ) {
int V_19 ;
struct V_153 * V_599 = & V_13 -> V_16 . V_148 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_599 ++ )
V_146 ( 0 , & V_599 -> V_149 ) ;
} else
F_268 ( V_13 ) ( 0 , V_13 ) ;
}
static int F_326 ( struct V_1 * V_2 , int V_600 , T_1 V_601 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
struct V_602 * V_603 ;
struct V_604 V_6 ;
struct V_605 V_606 ;
T_1 V_607 ;
int V_22 = 0 ;
if ( ! F_327 ( V_2 ) )
return - V_608 ;
if ( V_600 < 0 || V_600 > V_11 -> V_20 - 1 )
return - V_65 ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_50 ,
V_600 ) ;
return - V_65 ;
}
V_607 = V_601 << 10 ;
if ( V_607 >= V_609 ) {
F_11 ( V_13 -> V_30 ,
L_51 ,
V_601 , V_609 ) ;
return - V_527 ;
}
memset ( & V_606 , 0 , sizeof( V_606 ) ) ;
V_606 . V_279 = V_600 ;
V_606 . V_610 = V_611 ;
V_22 = F_328 ( V_2 , ( void * ) ( & V_606 ) , V_612 ) ;
if ( V_22 ) {
F_11 ( V_13 -> V_30 ,
L_52 ,
V_600 , V_11 -> V_31 , V_22 ) ;
return V_22 ;
}
if ( ! V_607 )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_588 ;
V_6 . V_116 . V_188 . V_613 = V_589 ;
V_6 . V_116 . V_188 . V_614 = V_590 ;
V_6 . V_116 . V_188 . V_615 = V_591 ;
V_6 . V_116 . V_188 . V_616 = V_592 ;
V_6 . V_116 . V_188 . V_617 = V_11 -> V_76 ;
V_6 . V_116 . V_188 . V_610 = V_611 ;
V_6 . V_116 . V_188 . V_618 = 0 ;
V_6 . V_116 . V_188 . V_619 = V_607 ;
V_6 . V_116 . V_188 . V_620 = 0 ;
V_6 . V_116 . V_188 . V_573 = V_2 -> V_66 ;
V_603 = F_329 ( V_2 , & V_6 ) ;
if ( ! V_603 )
return - V_61 ;
memset ( & V_606 , 0 , sizeof( V_606 ) ) ;
V_606 . V_279 = V_600 ;
V_606 . V_610 = V_603 -> V_184 ;
V_22 = F_330 ( V_2 , ( void * ) ( & V_606 ) , V_612 ) ;
if ( V_22 )
F_11 ( V_13 -> V_30 ,
L_53 , V_22 ) ;
return V_22 ;
}
static int F_331 ( struct V_1 * V_2 , T_1 V_399 , T_1 V_621 ,
T_11 V_456 , struct V_622 * V_623 )
{
struct V_5 * V_11 = F_86 ( V_2 ) ;
struct V_12 * V_13 = F_167 ( V_2 ) ;
if ( V_621 )
return - V_513 ;
if ( ! ( V_13 -> V_68 & V_168 ) ) {
F_11 ( V_13 -> V_30 ,
L_54 ,
V_11 -> V_31 ) ;
return - V_65 ;
}
if ( F_332 ( V_399 ) == F_332 ( V_624 ) &&
V_623 -> type == V_625 ) {
switch ( V_623 -> V_626 -> V_627 ) {
case V_628 :
case V_629 :
return F_333 ( V_2 , V_456 , V_623 -> V_626 ) ;
case V_630 :
return F_334 ( V_2 , V_456 , V_623 -> V_626 ) ;
default:
return - V_513 ;
}
}
return - V_513 ;
}
static T_8 F_335 ( struct V_1 * V_2 ,
T_8 V_72 )
{
if ( ! ( V_72 & V_631 ) )
V_72 &= ~ V_632 ;
return V_72 ;
}
static void F_336 ( struct V_1 * V_2 , struct V_633 * V_117 )
{
struct V_12 * V_12 = F_167 ( V_2 ) ;
F_337 ( V_117 -> V_379 , V_634 , sizeof( V_117 -> V_379 ) ) ;
F_337 ( V_117 -> V_635 , V_636 ,
sizeof( V_117 -> V_635 ) ) ;
F_337 ( V_117 -> V_637 , F_338 ( V_12 -> V_128 ) ,
sizeof( V_117 -> V_637 ) ) ;
}
void F_339 ( struct V_12 * V_13 )
{
int V_39 ;
if ( F_340 ( V_13 -> V_128 ) )
return;
F_341 ( V_13 ) ;
F_73 (adap, port) {
struct V_1 * V_2 = V_13 -> V_39 [ V_39 ] ;
if ( ! V_2 )
continue;
F_279 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_342 ( V_13 -> V_30 , L_55 ) ;
}
static void F_343 ( struct V_12 * V_13 )
{
T_1 V_638 = F_344 ( V_13 ) ;
F_345 ( V_13 , V_638 , V_639 ) ;
}
static void F_346 ( struct V_12 * V_13 )
{
if ( V_13 -> V_354 . V_640 . V_269 ) {
T_1 V_355 ;
unsigned int V_641 ;
V_355 = F_347 ( V_13 , V_642 ) ;
V_355 &= V_643 ;
V_355 += F_348 ( V_13 -> V_128 , & V_13 -> V_354 ) ;
V_641 = F_349 ( V_13 -> V_354 . V_640 . V_269 ) >> 10 ;
F_70 ( V_13 ,
F_350 ( V_644 , 3 ) ,
V_355 | F_351 ( 1 ) | F_352 ( F_353 ( V_641 ) ) ) ;
F_70 ( V_13 ,
F_350 ( V_645 , 3 ) ,
V_13 -> V_354 . V_640 . V_355 ) ;
F_68 ( V_13 ,
F_350 ( V_645 , 3 ) ) ;
}
}
static int F_354 ( struct V_12 * V_13 , struct V_646 * V_647 )
{
T_1 V_132 ;
int V_54 ;
memset ( V_647 , 0 , sizeof( * V_647 ) ) ;
V_647 -> V_648 = F_147 ( F_316 ( V_649 ) |
V_574 | V_575 ) ;
V_647 -> V_650 = F_147 ( F_319 ( * V_647 ) ) ;
V_54 = F_320 ( V_13 , V_13 -> V_27 , V_647 , sizeof( * V_647 ) , V_647 ) ;
if ( V_54 < 0 )
return V_54 ;
V_647 -> V_648 = F_147 ( F_316 ( V_649 ) |
V_574 | V_651 ) ;
V_54 = F_320 ( V_13 , V_13 -> V_27 , V_647 , sizeof( * V_647 ) , NULL ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_355 ( V_13 , V_13 -> V_28 ,
V_652 ,
V_653 |
V_654 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_356 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_172 , 64 ,
V_655 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_656 ,
V_656 ) ;
if ( V_54 < 0 )
return V_54 ;
F_357 ( V_13 ) ;
F_70 ( V_13 , V_657 , 0x64f8849 ) ;
F_70 ( V_13 , V_658 , F_196 ( V_659 - 12 ) ) ;
F_70 ( V_13 , V_660 , V_661 ) ;
V_132 = F_68 ( V_13 , V_662 ) ;
F_70 ( V_13 , V_662 , V_132 & ~ V_663 ) ;
V_13 -> V_188 . V_451 . V_664 = 0xE4 ;
F_70 ( V_13 , V_665 ,
F_358 ( V_13 -> V_188 . V_451 . V_664 ) ) ;
V_132 = 0x84218421 ;
F_359 ( V_13 , V_660 , V_662 ,
& V_132 , 1 , V_666 ) ;
F_359 ( V_13 , V_660 , V_662 ,
& V_132 , 1 , V_667 ) ;
F_359 ( V_13 , V_660 , V_662 ,
& V_132 , 1 , V_668 ) ;
#define F_360 16
if ( F_164 ( V_13 ) ) {
F_70 ( V_13 , V_669 ,
F_361 ( F_360 ) |
F_362 ( F_360 ) |
F_363 ( F_360 ) |
F_364 ( F_360 ) ) ;
F_70 ( V_13 , V_670 ,
F_361 ( F_360 ) |
F_362 ( F_360 ) |
F_363 ( F_360 ) |
F_364 ( F_360 ) ) ;
}
return F_365 ( V_13 , V_13 -> V_28 ) ;
}
static int F_366 ( struct V_12 * V_12 )
{
F_367 ( V_12 , V_671 , V_672 ) ;
if ( V_673 != 2 && V_673 != 0 ) {
F_11 ( & V_12 -> V_128 -> V_2 ,
L_56 ,
V_673 ) ;
V_673 = 2 ;
}
F_242 ( V_12 , V_674 ,
F_368 ( V_675 ) ,
F_368 ( V_673 ) ) ;
F_369 ( V_12 , V_661 ,
V_663 , 0 ) ;
return 0 ;
}
static int F_370 ( const T_3 * V_676 ,
T_9 V_677 )
{
int V_343 ;
#define F_371 ( T_12 ) (((__p)[0] << 8) | (__p)[1])
#define F_372 ( T_12 ) ((__p)[0] | ((__p)[1] << 8))
#define F_373 ( T_12 ) (le16(__p) | ((__p)[2] << 16))
V_343 = F_373 ( V_676 + 0x8 ) << 12 ;
V_343 = F_373 ( V_676 + V_343 + 0xa ) ;
return F_371 ( V_676 + V_343 + 0x27e ) ;
#undef F_371
#undef F_372
#undef F_373
}
static struct V_678 * F_374 ( int V_679 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_680 ) ; V_19 ++ ) {
if ( V_680 [ V_19 ] . V_681 == V_679 )
return & V_680 [ V_19 ] ;
}
return NULL ;
}
static int F_375 ( struct V_12 * V_13 )
{
const struct V_682 * V_683 ;
int V_54 ;
struct V_678 * V_684 ;
V_684 = F_374 ( V_13 -> V_128 -> V_377 ) ;
if ( ! V_684 ) {
F_376 ( V_13 -> V_30 ,
L_57 ) ;
return - V_513 ;
}
V_54 = F_377 ( & V_683 , V_684 -> V_685 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_58
L_59 ,
V_684 -> V_685 , - V_54 ) ;
if ( V_684 -> V_686 ) {
int V_687 = 0 ;
F_378 ( V_13 , & V_687 ) ;
F_376 ( V_13 -> V_30 , L_60
L_61 , V_687 ) ;
V_54 = 0 ;
}
return V_54 ;
}
V_54 = F_379 ( V_13 , V_639 , & V_13 -> V_334 ,
V_684 -> V_688 ,
( T_3 * ) V_683 -> V_109 , V_683 -> V_269 ) ;
if ( V_54 < 0 )
F_11 ( V_13 -> V_30 , L_62 ,
- V_54 ) ;
else if ( V_54 > 0 ) {
int V_689 = 0 ;
if ( V_684 -> V_688 )
V_689 = V_684 -> V_688 ( V_683 -> V_109 ,
V_683 -> V_269 ) ;
F_310 ( V_13 -> V_30 , L_63
L_64 ,
V_684 -> V_685 , V_689 ) ;
}
F_380 ( V_683 ) ;
return V_54 ;
}
static int F_381 ( struct V_12 * V_12 , int V_690 )
{
struct V_646 V_691 ;
const struct V_682 * V_692 ;
unsigned long V_693 = 0 , V_694 = 0 ;
T_1 V_695 , V_696 , V_697 ;
int V_54 ;
int V_698 = 0 ;
char * V_699 , V_700 [ 256 ] ;
char * V_701 = NULL ;
if ( V_690 ) {
V_54 = F_382 ( V_12 , V_12 -> V_27 ,
V_702 | V_703 ) ;
if ( V_54 < 0 )
goto V_704;
}
if ( F_383 ( V_12 -> V_128 -> V_377 ) ) {
V_54 = F_375 ( V_12 ) ;
if ( V_54 < 0 )
goto V_704;
}
switch ( F_165 ( V_12 -> V_188 . V_189 ) ) {
case V_705 :
V_699 = V_706 ;
break;
case V_275 :
V_699 = V_707 ;
break;
case V_708 :
V_699 = V_709 ;
break;
default:
F_11 ( V_12 -> V_30 , L_65 ,
V_12 -> V_128 -> V_377 ) ;
V_54 = - V_65 ;
goto V_704;
}
V_54 = F_384 ( & V_692 , V_699 , V_12 -> V_30 ) ;
if ( V_54 < 0 ) {
V_701 = L_66 ;
V_693 = V_710 ;
V_694 = F_385 ( V_12 ) ;
} else {
T_1 V_188 [ 7 ] , V_339 [ 7 ] ;
sprintf ( V_700 ,
L_67 , V_699 ) ;
V_701 = V_700 ;
if ( V_692 -> V_269 >= V_711 )
V_54 = - V_61 ;
else {
V_188 [ 0 ] = ( F_7 ( V_712 ) |
F_8 ( V_713 ) ) ;
V_54 = F_386 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_188 , V_339 ) ;
if ( V_54 == 0 ) {
T_9 V_714 = V_692 -> V_269 & 0x3 ;
T_9 V_269 = V_692 -> V_269 & ~ 0x3 ;
T_10 * V_109 = ( T_10 * ) V_692 -> V_109 ;
V_693 = F_387 ( V_339 [ 0 ] ) ;
V_694 = F_388 ( V_339 [ 0 ] ) << 16 ;
F_192 ( & V_12 -> V_334 ) ;
V_54 = F_203 ( V_12 , 0 , V_693 , V_694 ,
V_269 , V_109 , V_715 ) ;
if ( V_54 == 0 && V_714 != 0 ) {
union {
T_10 V_716 ;
char V_717 [ 4 ] ;
} V_718 ;
int V_19 ;
V_718 . V_716 = V_109 [ V_269 >> 2 ] ;
for ( V_19 = V_714 ; V_19 < 4 ; V_19 ++ )
V_718 . V_717 [ V_19 ] = 0 ;
V_54 = F_203 ( V_12 , 0 , V_693 ,
V_694 + V_269 ,
4 , & V_718 . V_716 ,
V_715 ) ;
}
F_194 ( & V_12 -> V_334 ) ;
}
}
F_380 ( V_692 ) ;
if ( V_54 )
goto V_704;
}
memset ( & V_691 , 0 , sizeof( V_691 ) ) ;
V_691 . V_648 =
F_147 ( F_316 ( V_649 ) |
V_574 |
V_575 ) ;
V_691 . V_650 =
F_147 ( V_719 |
F_389 ( V_693 ) |
F_390 ( V_694 >> 16 ) |
F_319 ( V_691 ) ) ;
V_54 = F_320 ( V_12 , V_12 -> V_27 , & V_691 , sizeof( V_691 ) ,
& V_691 ) ;
if ( V_54 == - V_720 ) {
memset ( & V_691 , 0 , sizeof( V_691 ) ) ;
V_691 . V_648 =
F_147 ( F_316 ( V_649 ) |
V_574 |
V_575 ) ;
V_691 . V_650 = F_147 ( F_319 ( V_691 ) ) ;
V_54 = F_320 ( V_12 , V_12 -> V_27 , & V_691 ,
sizeof( V_691 ) , & V_691 ) ;
V_701 = L_68 ;
}
V_698 = 1 ;
if ( V_54 < 0 )
goto V_704;
V_695 = F_48 ( V_691 . V_695 ) ;
V_696 = F_48 ( V_691 . V_696 ) ;
V_697 = F_48 ( V_691 . V_697 ) ;
if ( V_696 != V_697 )
F_376 ( V_12 -> V_30 , L_69\
L_70 ,
V_696 , V_697 ) ;
V_691 . V_648 =
F_147 ( F_316 ( V_649 ) |
V_574 |
V_651 ) ;
V_691 . V_650 = F_147 ( F_319 ( V_691 ) ) ;
V_54 = F_320 ( V_12 , V_12 -> V_27 , & V_691 , sizeof( V_691 ) ,
NULL ) ;
if ( V_54 < 0 )
goto V_704;
V_54 = F_366 ( V_12 ) ;
if ( V_54 < 0 )
goto V_704;
V_54 = F_391 ( V_12 , V_12 -> V_27 ) ;
if ( V_54 < 0 )
goto V_704;
F_310 ( V_12 -> V_30 , L_71\
L_72 ,
V_701 , V_695 , V_697 ) ;
return 0 ;
V_704:
if ( V_698 && V_54 != - V_720 )
F_376 ( V_12 -> V_30 , L_73 ,
V_701 , - V_54 ) ;
return V_54 ;
}
static struct V_721 * F_392 ( int V_189 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_722 ) ; V_19 ++ ) {
if ( V_722 [ V_19 ] . V_189 == V_189 )
return & V_722 [ V_19 ] ;
}
return NULL ;
}
static int F_393 ( struct V_12 * V_13 )
{
int V_54 ;
T_1 V_132 , V_723 ;
enum V_724 V_35 ;
T_1 V_188 [ 7 ] , V_339 [ 7 ] ;
struct V_646 V_691 ;
int V_690 = 1 ;
V_54 = F_394 ( V_13 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_395 ( V_13 , V_13 -> V_27 , V_13 -> V_27 ,
F_109 () ? V_725 : V_726 , & V_35 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_74 ,
V_54 ) ;
return V_54 ;
}
if ( V_54 == V_13 -> V_27 )
V_13 -> V_68 |= V_136 ;
F_396 ( V_13 , & V_13 -> V_188 . V_727 ) ;
F_397 ( V_13 , & V_13 -> V_188 . V_728 ) ;
F_398 ( V_13 , & V_13 -> V_188 . V_729 ) ;
F_399 ( V_13 , & V_13 -> V_188 . V_730 ) ;
V_54 = F_400 ( V_13 ) ;
if ( V_54 )
V_35 = V_731 ;
if ( ( V_13 -> V_68 & V_136 ) && V_35 != V_732 ) {
struct V_721 * V_721 ;
struct V_733 * V_734 ;
const struct V_682 * V_735 ;
const T_3 * V_736 = NULL ;
unsigned int V_737 = 0 ;
V_721 = F_392 ( F_165 ( V_13 -> V_188 . V_189 ) ) ;
if ( V_721 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_75 ,
F_165 ( V_13 -> V_188 . V_189 ) ) ;
return - V_65 ;
}
V_734 = F_161 ( sizeof( * V_734 ) , V_156 ) ;
V_54 = F_384 ( & V_735 , V_721 -> V_738 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_76 ,
V_721 -> V_738 , V_54 ) ;
} else {
V_736 = V_735 -> V_109 ;
V_737 = V_735 -> V_269 ;
}
V_54 = F_401 ( V_13 , V_721 , V_736 , V_737 , V_734 ,
V_35 , & V_690 ) ;
F_380 ( V_735 ) ;
F_402 ( V_734 ) ;
if ( V_54 < 0 )
goto V_704;
}
V_54 = F_403 ( V_13 , & V_13 -> V_188 . V_549 ) ;
if ( V_54 < 0 )
goto V_704;
V_132 =
F_7 ( V_712 ) |
F_8 ( V_739 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_132 , & V_723 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_188 . V_740 = F_404 ( V_723 ) ;
V_13 -> V_188 . V_741 = V_723 ;
if ( V_35 == V_732 ) {
F_310 ( V_13 -> V_30 , L_77\
L_78 ,
V_13 -> V_68 & V_136 ? L_79 : L_80 ) ;
} else {
F_310 ( V_13 -> V_30 , L_81\
L_82 ) ;
V_188 [ 0 ] = ( F_7 ( V_712 ) |
F_8 ( V_713 ) ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_188 , V_339 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_83
L_84 ) ;
goto V_704;
}
V_54 = F_381 ( V_13 , V_690 ) ;
if ( V_54 == - V_720 ) {
F_11 ( V_13 -> V_30 , L_85
L_86 ) ;
goto V_704;
}
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_87
L_88 , - V_54 ) ;
goto V_704;
}
}
V_54 = F_357 ( V_13 ) ;
if ( V_54 < 0 )
goto V_704;
if ( F_405 ( V_13 -> V_128 -> V_377 ) )
V_13 -> V_188 . V_742 = 1 ;
#define F_406 ( T_13 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_407 ( T_13 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_188 [ 0 ] = F_407 ( V_743 ) ;
V_188 [ 1 ] = F_407 ( V_744 ) ;
V_188 [ 2 ] = F_407 ( V_745 ) ;
V_188 [ 3 ] = F_407 ( V_746 ) ;
V_188 [ 4 ] = F_407 ( V_747 ) ;
V_188 [ 5 ] = F_407 ( V_748 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 , V_339 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_16 . V_99 = V_339 [ 0 ] ;
V_13 -> V_749 = V_339 [ 1 ] ;
V_13 -> V_750 = V_339 [ 2 ] ;
V_13 -> V_249 . V_462 = V_339 [ 3 ] ;
V_13 -> V_249 . V_265 = V_339 [ 4 ] - V_339 [ 3 ] + 1 ;
V_13 -> V_16 . V_163 = V_339 [ 5 ] ;
V_188 [ 0 ] = F_407 ( V_751 ) ;
V_188 [ 1 ] = F_407 ( V_752 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_339 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_16 . V_172 = V_339 [ 0 ] - V_13 -> V_16 . V_99 + 1 ;
V_13 -> V_16 . V_165 = V_339 [ 1 ] - V_13 -> V_16 . V_163 + 1 ;
V_13 -> V_16 . V_98 = F_408 ( V_13 -> V_16 . V_172 ,
sizeof( * V_13 -> V_16 . V_98 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_98 ) {
V_54 = - V_61 ;
goto V_704;
}
V_13 -> V_16 . V_164 = F_408 ( V_13 -> V_16 . V_165 ,
sizeof( * V_13 -> V_16 . V_164 ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_164 ) {
V_54 = - V_61 ;
goto V_704;
}
V_13 -> V_16 . V_171 = F_408 ( F_160 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_171 ) {
V_54 = - V_61 ;
goto V_704;
}
V_13 -> V_16 . V_173 = F_408 ( F_160 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_173 ) {
V_54 = - V_61 ;
goto V_704;
}
#ifdef F_127
V_13 -> V_16 . V_753 = F_408 ( F_160 ( V_13 -> V_16 . V_172 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_16 . V_753 ) {
V_54 = - V_61 ;
goto V_704;
}
#endif
V_188 [ 0 ] = F_407 ( V_754 ) ;
V_188 [ 1 ] = F_407 ( V_755 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_339 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_756 = V_339 [ 0 ] ;
V_13 -> V_757 = V_339 [ 1 ] ;
V_13 -> V_188 . V_758 = F_105 ( V_13 -> V_188 . V_189 ) ? 15 : 16 ;
V_188 [ 0 ] = F_407 ( V_759 ) ;
V_188 [ 1 ] = F_407 ( V_760 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 , V_339 ) ;
if ( ( V_339 [ 0 ] != V_339 [ 1 ] ) && ( V_54 >= 0 ) ) {
V_13 -> V_68 |= V_761 ;
V_13 -> V_249 . V_762 = V_339 [ 0 ] ;
V_13 -> V_249 . V_763 = V_339 [ 1 ] ;
}
V_188 [ 0 ] = F_407 ( V_764 ) ;
V_339 [ 0 ] = 1 ;
( void ) F_121 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_188 , V_339 ) ;
if ( F_105 ( V_13 -> V_188 . V_189 ) ) {
V_13 -> V_188 . V_765 = false ;
} else {
V_188 [ 0 ] = F_406 ( V_766 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_339 ) ;
V_13 -> V_188 . V_765 = ( V_54 == 0 && V_339 [ 0 ] != 0 ) ;
}
V_188 [ 0 ] = F_406 ( V_767 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_188 , V_339 ) ;
V_13 -> V_188 . V_768 = ( V_54 == 0 && V_339 [ 0 ] != 0 ) ;
memset ( & V_691 , 0 , sizeof( V_691 ) ) ;
V_691 . V_648 = F_147 ( F_316 ( V_649 ) |
V_574 | V_575 ) ;
V_691 . V_650 = F_147 ( F_319 ( V_691 ) ) ;
V_54 = F_320 ( V_13 , V_13 -> V_27 , & V_691 , sizeof( V_691 ) ,
& V_691 ) ;
if ( V_54 < 0 )
goto V_704;
if ( V_691 . V_769 ) {
V_188 [ 0 ] = F_406 ( V_770 ) ;
V_188 [ 1 ] = F_407 ( V_771 ) ;
V_188 [ 2 ] = F_407 ( V_772 ) ;
V_188 [ 3 ] = F_407 ( V_773 ) ;
V_188 [ 4 ] = F_407 ( V_774 ) ;
V_188 [ 5 ] = F_406 ( V_775 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_339 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_249 . V_258 = V_339 [ 0 ] ;
V_13 -> V_249 . V_266 = F_409 ( V_13 -> V_249 . V_258 / 2 , V_776 ) ;
V_13 -> V_249 . V_235 = V_339 [ 1 ] ;
V_13 -> V_249 . V_233 = V_339 [ 2 ] - V_339 [ 1 ] + 1 ;
if ( V_13 -> V_68 & V_761 && ! F_410 ( V_13 ) ) {
V_13 -> V_249 . V_240 = V_13 -> V_249 . V_462 +
F_411 ( V_13 -> V_249 . V_265 , 3 ) ;
V_13 -> V_249 . V_239 = V_13 -> V_249 . V_265 -
F_411 ( V_13 -> V_249 . V_265 , 3 ) ;
V_13 -> V_249 . V_265 = V_13 -> V_249 . V_240 -
V_13 -> V_249 . V_462 ;
}
V_13 -> V_354 . V_777 . V_355 = V_339 [ 3 ] ;
V_13 -> V_354 . V_777 . V_269 = V_339 [ 4 ] - V_339 [ 3 ] + 1 ;
V_13 -> V_188 . V_778 = V_339 [ 5 ] ;
V_13 -> V_188 . V_779 = 1 ;
V_13 -> V_780 += 1 ;
}
if ( V_691 . V_781 ) {
V_188 [ 0 ] = F_407 ( V_782 ) ;
V_188 [ 1 ] = F_407 ( V_783 ) ;
V_188 [ 2 ] = F_407 ( V_784 ) ;
V_188 [ 3 ] = F_407 ( V_785 ) ;
V_188 [ 4 ] = F_407 ( V_786 ) ;
V_188 [ 5 ] = F_407 ( V_787 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_188 , V_339 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_354 . V_341 . V_355 = V_339 [ 0 ] ;
V_13 -> V_354 . V_341 . V_269 = V_339 [ 1 ] - V_339 [ 0 ] + 1 ;
V_13 -> V_354 . V_788 . V_355 = V_339 [ 2 ] ;
V_13 -> V_354 . V_788 . V_269 = V_339 [ 3 ] - V_339 [ 2 ] + 1 ;
V_13 -> V_354 . V_789 . V_355 = V_339 [ 4 ] ;
V_13 -> V_354 . V_789 . V_269 = V_339 [ 5 ] - V_339 [ 4 ] + 1 ;
V_188 [ 0 ] = F_407 ( V_790 ) ;
V_188 [ 1 ] = F_407 ( V_791 ) ;
V_188 [ 2 ] = F_407 ( V_792 ) ;
V_188 [ 3 ] = F_407 ( V_793 ) ;
V_188 [ 4 ] = F_407 ( V_794 ) ;
V_188 [ 5 ] = F_407 ( V_795 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_188 ,
V_339 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_354 . V_796 . V_355 = V_339 [ 0 ] ;
V_13 -> V_354 . V_796 . V_269 = V_339 [ 1 ] - V_339 [ 0 ] + 1 ;
V_13 -> V_354 . V_797 . V_355 = V_339 [ 2 ] ;
V_13 -> V_354 . V_797 . V_269 = V_339 [ 3 ] - V_339 [ 2 ] + 1 ;
V_13 -> V_354 . V_640 . V_355 = V_339 [ 4 ] ;
V_13 -> V_354 . V_640 . V_269 = V_339 [ 5 ] - V_339 [ 4 ] + 1 ;
V_188 [ 0 ] = F_406 ( V_798 ) ;
V_188 [ 1 ] = F_406 ( V_799 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_188 ,
V_339 ) ;
if ( V_54 < 0 ) {
V_13 -> V_188 . V_800 = 8 ;
V_13 -> V_188 . V_801 = 32 * V_13 -> V_249 . V_258 ;
V_54 = 0 ;
} else {
V_13 -> V_188 . V_800 = V_339 [ 0 ] ;
V_13 -> V_188 . V_801 = V_339 [ 1 ] ;
}
F_310 ( V_13 -> V_30 ,
L_89 ,
V_13 -> V_188 . V_800 ,
V_13 -> V_188 . V_801 ) ;
V_13 -> V_780 += 2 ;
}
if ( V_691 . V_802 ) {
V_188 [ 0 ] = F_407 ( V_803 ) ;
V_188 [ 1 ] = F_407 ( V_804 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_188 , V_339 ) ;
if ( V_54 < 0 )
goto V_704;
V_13 -> V_354 . V_805 . V_355 = V_339 [ 0 ] ;
V_13 -> V_354 . V_805 . V_269 = V_339 [ 1 ] - V_339 [ 0 ] + 1 ;
V_13 -> V_780 += 2 ;
}
if ( V_691 . V_806 ) {
V_188 [ 0 ] = F_407 ( V_807 ) ;
V_54 = F_386 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_188 , V_339 ) ;
if ( V_54 < 0 ) {
if ( V_54 != - V_65 )
goto V_704;
} else {
V_13 -> V_354 . V_808 = V_339 [ 0 ] ;
}
V_13 -> V_188 . V_809 |= V_810 ;
V_13 -> V_811 += 1 ;
}
#undef F_407
#undef F_406
F_412 ( V_13 , V_13 -> V_188 . V_302 , NULL ) ;
if ( V_35 != V_732 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_303 ; V_19 ++ )
if ( V_13 -> V_188 . V_302 [ V_19 ] == 1492 ) {
V_13 -> V_188 . V_302 [ V_19 ] = 1488 ;
break;
}
F_413 ( V_13 , V_13 -> V_188 . V_302 , V_13 -> V_188 . V_812 ,
V_13 -> V_188 . V_813 ) ;
}
F_414 ( V_13 ) ;
V_13 -> V_68 |= V_814 ;
F_415 ( V_13 ) ;
return 0 ;
V_704:
F_34 ( V_13 -> V_16 . V_98 ) ;
F_34 ( V_13 -> V_16 . V_164 ) ;
F_34 ( V_13 -> V_16 . V_171 ) ;
F_34 ( V_13 -> V_16 . V_173 ) ;
#ifdef F_127
F_34 ( V_13 -> V_16 . V_753 ) ;
#endif
if ( V_54 != - V_815 && V_54 != - V_816 )
F_416 ( V_13 , V_13 -> V_27 ) ;
return V_54 ;
}
static T_14 F_417 ( struct V_321 * V_128 ,
T_15 V_35 )
{
int V_19 ;
struct V_12 * V_13 = F_191 ( V_128 ) ;
if ( ! V_13 )
goto V_59;
F_418 () ;
V_13 -> V_68 &= ~ V_814 ;
F_258 ( V_13 , V_817 ) ;
F_192 ( & V_13 -> V_325 ) ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( V_2 ) {
F_419 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
F_194 ( & V_13 -> V_325 ) ;
F_89 ( V_13 ) ;
if ( V_13 -> V_68 & V_168 )
F_272 ( V_13 ) ;
F_420 () ;
if ( ( V_13 -> V_68 & V_818 ) ) {
F_421 ( V_128 ) ;
V_13 -> V_68 &= ~ V_818 ;
}
V_59: return V_35 == V_819 ?
V_820 : V_821 ;
}
static T_14 F_422 ( struct V_321 * V_128 )
{
int V_19 , V_54 ;
struct V_646 V_647 ;
struct V_12 * V_13 = F_191 ( V_128 ) ;
if ( ! V_13 ) {
F_423 ( V_128 ) ;
F_424 ( V_128 ) ;
return V_822 ;
}
if ( ! ( V_13 -> V_68 & V_818 ) ) {
if ( F_425 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 , L_90
L_91 ) ;
return V_820 ;
}
V_13 -> V_68 |= V_818 ;
}
F_426 ( V_128 ) ;
F_423 ( V_128 ) ;
F_424 ( V_128 ) ;
F_427 ( V_128 ) ;
if ( F_428 ( V_13 -> V_823 ) < 0 )
return V_820 ;
if ( F_395 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_725 , NULL ) < 0 )
return V_820 ;
V_13 -> V_68 |= V_814 ;
if ( F_354 ( V_13 , & V_647 ) )
return V_820 ;
F_73 (adap, i) {
struct V_5 * V_6 = F_84 ( V_13 , V_19 ) ;
V_54 = F_429 ( V_13 , V_13 -> V_27 , V_6 -> V_76 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_54 < 0 )
return V_820 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_74 = - 1 ;
}
F_413 ( V_13 , V_13 -> V_188 . V_302 , V_13 -> V_188 . V_812 ,
V_13 -> V_188 . V_813 ) ;
F_343 ( V_13 ) ;
if ( F_267 ( V_13 ) )
return V_820 ;
return V_822 ;
}
static void F_430 ( struct V_321 * V_128 )
{
int V_19 ;
struct V_12 * V_13 = F_191 ( V_128 ) ;
if ( ! V_13 )
return;
F_418 () ;
F_73 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( V_2 ) {
if ( F_14 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_302 ( V_2 ) ;
}
F_431 ( V_2 ) ;
}
}
F_420 () ;
}
static inline bool F_432 ( const struct V_824 * V_825 )
{
unsigned int V_826 , V_827 ;
V_826 = F_433 ( F_434 ( V_825 -> V_828 ) ) ;
V_827 = V_826 & ~ ( V_579 | V_580 ) ;
return V_827 != 0 ;
}
static void F_435 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 = 0 , V_829 = 0 , V_830 = 0 ;
#ifndef F_16
int V_831 = 0 ;
#endif
if ( F_109 () || ( F_100 ( V_13 ) && F_436 ( V_13 ) ) ) {
V_13 -> V_188 . V_779 = 0 ;
V_13 -> V_188 . V_809 = 0 ;
}
V_829 += F_432 ( & F_84 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_16
if ( V_13 -> V_188 . V_740 * 8 > V_832 ) {
F_11 ( V_13 -> V_30 , L_92 ,
V_832 , V_13 -> V_188 . V_740 * 8 ) ;
F_437 ( 1 ) ;
}
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_830 ;
V_11 -> V_20 = F_109 () ? 1 : 8 ;
V_830 += V_11 -> V_20 ;
}
#else
if ( V_829 )
V_831 = ( V_832 - ( V_13 -> V_188 . V_740 - V_829 ) ) / V_829 ;
if ( V_831 > F_438 () )
V_831 = F_438 () ;
if ( F_109 () )
V_831 = 1 ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_830 ;
V_11 -> V_20 = F_432 ( & V_11 -> V_7 ) ? V_831 : 1 ;
V_830 += V_11 -> V_20 ;
}
#endif
V_4 -> V_833 = V_830 ;
V_4 -> V_834 = V_830 ;
if ( F_100 ( V_13 ) ) {
if ( V_829 ) {
V_19 = F_439 ( int , V_835 , F_440 () ) ;
V_4 -> V_836 = F_441 ( V_19 , V_13 -> V_188 . V_740 ) ;
} else {
V_4 -> V_836 = V_13 -> V_188 . V_740 ;
}
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_148 ) ; V_19 ++ ) {
struct V_153 * V_837 = & V_4 -> V_148 [ V_19 ] ;
F_442 ( V_13 , & V_837 -> V_149 , 5 , 10 , 1024 , 64 ) ;
V_837 -> V_181 . V_269 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_269 = 1024 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_187 ) ; V_19 ++ )
V_4 -> V_187 [ V_19 ] . V_25 . V_269 = 512 ;
if ( ! F_105 ( V_13 -> V_188 . V_189 ) )
V_4 -> V_190 . V_25 . V_269 = 8 ;
F_442 ( V_13 , & V_4 -> V_147 , 0 , 1 , 1024 , 64 ) ;
F_442 ( V_13 , & V_4 -> V_174 , 0 , 1 , 512 , 64 ) ;
}
static void F_443 ( struct V_12 * V_13 , int V_140 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_140 < V_13 -> V_16 . V_833 )
F_73 (adap, i) {
V_11 = F_84 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_833 -- ;
if ( V_13 -> V_16 . V_833 <= V_140 )
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
static int F_444 ( struct V_12 * V_13 )
{
struct V_838 * V_141 ;
unsigned int V_839 = 0 ;
if ( F_164 ( V_13 ) )
V_839 += V_835 * V_13 -> V_780 ;
if ( F_445 ( V_13 ) )
V_839 += V_835 * V_13 -> V_811 ;
if ( ! V_839 )
goto V_59;
V_141 = F_408 ( V_839 , sizeof( * V_141 ) , V_156 ) ;
if ( ! V_141 )
return - V_61 ;
V_13 -> V_840 . V_841 = F_408 ( F_160 ( V_839 ) ,
sizeof( long ) , V_156 ) ;
if ( ! V_13 -> V_840 . V_841 ) {
F_34 ( V_141 ) ;
return - V_61 ;
}
F_162 ( & V_13 -> V_840 . V_842 ) ;
V_13 -> V_843 = V_141 ;
V_59:
return 0 ;
}
static void F_446 ( struct V_12 * V_13 )
{
if ( ! ( V_13 -> V_811 && V_13 -> V_780 ) )
return;
F_34 ( V_13 -> V_843 ) ;
F_34 ( V_13 -> V_840 . V_841 ) ;
}
static int F_447 ( struct V_12 * V_13 )
{
int V_844 = 0 , V_845 = 0 ;
int V_19 , V_138 , V_846 , V_847 , V_848 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_849 = V_13 -> V_188 . V_740 ;
struct V_850 * V_851 ;
int V_839 = V_655 ;
if ( F_445 ( V_13 ) )
V_839 += ( V_835 * V_13 -> V_811 ) ;
if ( F_164 ( V_13 ) )
V_839 += ( V_835 * V_13 -> V_780 ) ;
V_851 = F_80 ( sizeof( * V_851 ) * ( V_839 + 1 ) ,
V_156 ) ;
if ( ! V_851 )
return - V_61 ;
if ( F_444 ( V_13 ) ) {
V_13 -> V_188 . V_779 = 0 ;
V_13 -> V_188 . V_809 = 0 ;
}
for ( V_19 = 0 ; V_19 < V_839 + 1 ; ++ V_19 )
V_851 [ V_19 ] . V_49 = V_19 ;
V_846 = V_4 -> V_834 + V_852 ;
if ( F_164 ( V_13 ) ) {
V_846 += V_13 -> V_780 * V_4 -> V_836 ;
V_844 = V_13 -> V_780 * V_849 ;
}
if ( F_445 ( V_13 ) ) {
V_846 += V_13 -> V_811 * V_4 -> V_836 ;
V_845 = V_13 -> V_811 * V_849 ;
}
#ifdef F_16
V_847 = 8 * V_13 -> V_188 . V_740 + V_852 + V_844 + V_845 ;
#else
V_847 = V_13 -> V_188 . V_740 + V_852 + V_844 + V_845 ;
#endif
V_848 = F_448 ( V_13 -> V_128 , V_851 , V_847 , V_846 ) ;
if ( V_848 < 0 ) {
F_310 ( V_13 -> V_30 , L_93
L_94 ) ;
F_34 ( V_851 ) ;
return V_848 ;
}
V_19 = V_848 - V_852 - V_844 - V_845 ;
if ( V_19 < V_4 -> V_834 ) {
V_4 -> V_834 = V_19 ;
if ( V_19 < V_4 -> V_833 )
F_443 ( V_13 , V_19 ) ;
}
if ( F_100 ( V_13 ) ) {
if ( V_848 < V_846 )
V_4 -> V_853 = V_849 ;
else
V_4 -> V_853 = V_4 -> V_836 ;
}
for ( V_19 = 0 ; V_19 < ( V_4 -> V_834 + V_852 ) ; ++ V_19 )
V_13 -> V_141 [ V_19 ] . V_46 = V_851 [ V_19 ] . V_854 ;
if ( F_100 ( V_13 ) ) {
for ( V_138 = 0 ; V_19 < V_848 ; ++ V_19 , V_138 ++ ) {
V_13 -> V_843 [ V_138 ] . V_46 = V_851 [ V_19 ] . V_854 ;
V_13 -> V_843 [ V_138 ] . V_184 = V_19 ;
}
V_13 -> V_840 . V_855 = V_138 ;
}
F_310 ( V_13 -> V_30 , L_95
L_96 ,
V_848 , V_4 -> V_834 , V_4 -> V_853 ) ;
F_34 ( V_851 ) ;
return 0 ;
}
static int F_449 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_450 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_73 (adap, i) {
struct V_5 * V_11 = F_84 ( V_13 , V_19 ) ;
V_11 -> V_152 = F_408 ( V_11 -> V_155 , sizeof( T_6 ) , V_156 ) ;
if ( ! V_11 -> V_152 )
return - V_61 ;
}
return 0 ;
}
static int F_451 ( struct V_12 * V_13 ,
enum V_856 * V_8 ,
enum V_857 * V_858 )
{
T_1 V_859 , V_860 ;
int V_861 , V_862 ;
#define F_452 4
* V_8 = V_863 ;
* V_858 = V_864 ;
V_861 = F_453 ( V_13 -> V_128 , V_865 ,
& V_859 ) ;
V_862 = F_453 ( V_13 -> V_128 , V_866 ,
& V_860 ) ;
if ( ! V_862 && V_860 ) {
if ( V_860 & V_867 )
* V_8 = V_868 ;
else if ( V_860 & V_869 )
* V_8 = V_870 ;
else if ( V_860 & V_871 )
* V_8 = V_872 ;
}
if ( ! V_861 ) {
* V_858 = ( V_859 & V_873 ) >> F_452 ;
if ( ! V_860 ) {
if ( V_859 & V_874 )
* V_8 = V_870 ;
else if ( V_859 & V_875 )
* V_8 = V_872 ;
}
}
if ( * V_8 == V_863 || * V_858 == V_864 )
return V_861 ? V_861 : V_862 ? V_862 : - V_65 ;
return 0 ;
}
static void F_454 ( struct V_12 * V_13 )
{
enum V_857 V_858 , V_876 ;
enum V_856 V_8 , V_877 ;
#define F_455 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_451 ( V_13 , & V_877 , & V_876 ) ) {
F_376 ( V_13 -> V_30 ,
L_97 ) ;
return;
}
if ( F_456 ( V_13 -> V_128 , & V_8 , & V_858 ) ||
V_8 == V_863 || V_858 == V_864 ) {
F_376 ( V_13 -> V_30 ,
L_98 ) ;
return;
}
F_310 ( V_13 -> V_30 , L_99 ,
F_455 ( V_8 ) , F_455 ( V_877 ) ) ;
F_310 ( V_13 -> V_30 , L_100 ,
V_858 , V_876 ) ;
if ( V_8 < V_877 || V_858 < V_876 )
F_310 ( V_13 -> V_30 ,
L_101
L_102 ) ;
}
static void F_457 ( struct V_12 * V_12 )
{
F_310 ( V_12 -> V_30 , L_103 ,
V_12 -> V_188 . V_549 . V_565 ,
F_458 ( V_12 -> V_188 . V_189 ) ) ;
F_310 ( V_12 -> V_30 , L_104 ,
V_12 -> V_188 . V_549 . V_878 , V_12 -> V_188 . V_549 . V_879 ) ;
if ( ! V_12 -> V_188 . V_727 )
F_376 ( V_12 -> V_30 , L_105 ) ;
else
F_310 ( V_12 -> V_30 , L_106 ,
F_459 ( V_12 -> V_188 . V_727 ) ,
F_460 ( V_12 -> V_188 . V_727 ) ,
F_461 ( V_12 -> V_188 . V_727 ) ,
F_462 ( V_12 -> V_188 . V_727 ) ) ;
if ( ! V_12 -> V_188 . V_728 )
F_310 ( V_12 -> V_30 , L_107 ) ;
else
F_310 ( V_12 -> V_30 , L_108 ,
F_459 ( V_12 -> V_188 . V_728 ) ,
F_460 ( V_12 -> V_188 . V_728 ) ,
F_461 ( V_12 -> V_188 . V_728 ) ,
F_462 ( V_12 -> V_188 . V_728 ) ) ;
if ( ! V_12 -> V_188 . V_729 )
F_376 ( V_12 -> V_30 , L_109 ) ;
else
F_310 ( V_12 -> V_30 ,
L_110 ,
F_459 ( V_12 -> V_188 . V_729 ) ,
F_460 ( V_12 -> V_188 . V_729 ) ,
F_461 ( V_12 -> V_188 . V_729 ) ,
F_462 ( V_12 -> V_188 . V_729 ) ) ;
if ( ! V_12 -> V_188 . V_730 )
F_310 ( V_12 -> V_30 , L_111 ) ;
else
F_310 ( V_12 -> V_30 ,
L_112 ,
F_459 ( V_12 -> V_188 . V_730 ) ,
F_460 ( V_12 -> V_188 . V_730 ) ,
F_461 ( V_12 -> V_188 . V_730 ) ,
F_462 ( V_12 -> V_188 . V_730 ) ) ;
F_310 ( V_12 -> V_30 , L_113 ,
F_164 ( V_12 ) ? L_114 : L_115 ,
( ( V_12 -> V_68 & V_127 ) ? L_116 :
( V_12 -> V_68 & V_129 ) ? L_117 : L_115 ) ,
F_164 ( V_12 ) ? L_118 : L_119 ) ;
}
static void F_463 ( const struct V_1 * V_2 )
{
char V_717 [ 80 ] ;
char * V_880 = V_717 ;
const char * V_881 = L_115 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_188 . V_882 . V_8 == V_883 )
V_881 = L_120 ;
else if ( V_13 -> V_188 . V_882 . V_8 == V_884 )
V_881 = L_121 ;
else if ( V_13 -> V_188 . V_882 . V_8 == V_885 )
V_881 = L_122 ;
if ( V_11 -> V_7 . V_828 & V_579 )
V_880 += sprintf ( V_880 , L_123 ) ;
if ( V_11 -> V_7 . V_828 & V_580 )
V_880 += sprintf ( V_880 , L_124 ) ;
if ( V_11 -> V_7 . V_828 & V_581 )
V_880 += sprintf ( V_880 , L_125 ) ;
if ( V_11 -> V_7 . V_828 & V_582 )
V_880 += sprintf ( V_880 , L_126 ) ;
if ( V_11 -> V_7 . V_828 & V_583 )
V_880 += sprintf ( V_880 , L_127 ) ;
if ( V_11 -> V_7 . V_828 & V_584 )
V_880 += sprintf ( V_880 , L_128 ) ;
if ( V_880 != V_717 )
-- V_880 ;
sprintf ( V_880 , L_129 , F_464 ( V_11 -> V_886 ) ) ;
F_3 ( V_2 , L_130 ,
V_2 -> V_9 , V_13 -> V_188 . V_549 . V_565 , V_13 -> V_9 , V_717 ) ;
}
static void F_465 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_402 ( V_12 -> V_887 ) ;
F_466 ( V_12 ) ;
F_402 ( V_12 -> V_249 . V_248 ) ;
F_467 ( V_12 ) ;
F_34 ( V_12 -> V_16 . V_98 ) ;
F_34 ( V_12 -> V_16 . V_164 ) ;
F_34 ( V_12 -> V_16 . V_171 ) ;
F_34 ( V_12 -> V_16 . V_173 ) ;
#ifdef F_127
F_34 ( V_12 -> V_16 . V_753 ) ;
#endif
F_64 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] ) {
struct V_5 * V_11 = F_84 ( V_12 , V_19 ) ;
if ( V_11 -> V_51 != 0 )
F_468 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_51 ) ;
F_34 ( F_84 ( V_12 , V_19 ) -> V_152 ) ;
F_469 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_12 -> V_68 & V_814 )
F_416 ( V_12 , V_12 -> V_28 ) ;
}
static int F_470 ( struct V_321 * V_128 , T_1 V_888 )
{
T_6 V_889 ;
F_471 ( V_128 , V_890 , & V_889 ) ;
switch ( V_889 >> 12 ) {
case V_705 :
return F_472 ( V_705 , V_888 ) ;
case V_275 :
return F_472 ( V_275 , V_888 ) ;
case V_708 :
return F_472 ( V_708 , V_888 ) ;
default:
F_11 ( & V_128 -> V_2 , L_65 ,
V_889 ) ;
}
return - V_65 ;
}
static void F_473 ( struct V_1 * V_2 )
{
V_2 -> type = V_891 ;
V_2 -> V_66 = 0 ;
V_2 -> V_892 = 0 ;
V_2 -> V_598 = 0 ;
V_2 -> V_893 = 0 ;
V_2 -> V_68 |= V_894 ;
V_2 -> V_895 |= V_896 ;
V_2 -> V_897 = & V_898 ;
V_2 -> V_899 = & V_900 ;
V_2 -> V_901 = true ;
}
static int F_474 ( struct V_321 * V_128 )
{
struct V_12 * V_13 = F_191 ( V_128 ) ;
struct V_1 * V_52 ;
struct V_5 * V_11 ;
char V_9 [ V_902 ] ;
int V_22 ;
snprintf ( V_9 , V_902 , L_131 , V_13 -> V_563 , V_13 -> V_28 ) ;
V_52 = F_475 ( sizeof( struct V_5 ) , V_9 , V_903 ,
F_473 ) ;
if ( ! V_52 )
return - V_61 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_13 ;
V_11 -> V_31 = V_13 -> V_28 % V_13 -> V_188 . V_740 ;
F_476 ( V_52 , & V_128 -> V_2 ) ;
V_13 -> V_39 [ 0 ] = V_52 ;
V_22 = F_477 ( V_13 -> V_39 [ 0 ] ) ;
if ( V_22 ) {
F_5 ( L_132 , V_9 ) ;
F_469 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
return V_22 ;
}
return 0 ;
}
static int F_478 ( struct V_321 * V_128 , int V_550 )
{
struct V_12 * V_13 = F_191 ( V_128 ) ;
int V_22 = 0 ;
int V_904 = F_479 ( V_128 ) ;
T_1 V_905 ;
V_905 = F_480 ( V_13 -> V_823 + V_906 ) ;
if ( ! ( V_905 & V_907 ) ||
! ( V_905 & V_908 ) ||
F_481 ( V_905 ) != 4 ) {
F_376 ( & V_128 -> V_2 ,
L_133 ) ;
return - V_513 ;
}
if ( V_904 && F_482 ( V_128 ) ) {
F_11 ( & V_128 -> V_2 ,
L_134 ) ;
V_550 = V_904 ;
return V_550 ;
}
if ( ! V_550 ) {
F_483 ( V_128 ) ;
if ( V_13 -> V_39 [ 0 ] ) {
F_484 ( V_13 -> V_39 [ 0 ] ) ;
V_13 -> V_39 [ 0 ] = NULL ;
}
F_34 ( V_13 -> V_551 ) ;
V_13 -> V_551 = NULL ;
V_13 -> V_550 = 0 ;
return V_550 ;
}
if ( V_550 != V_904 ) {
V_22 = F_485 ( V_128 , V_550 ) ;
if ( V_22 )
return V_22 ;
V_13 -> V_550 = V_550 ;
V_22 = F_474 ( V_128 ) ;
if ( V_22 )
return V_22 ;
}
V_13 -> V_551 = F_408 ( V_13 -> V_550 ,
sizeof( struct V_909 ) , V_156 ) ;
if ( V_13 -> V_551 )
F_305 ( V_13 ) ;
return V_550 ;
}
static int F_486 ( struct V_321 * V_128 , const struct V_910 * V_911 )
{
int V_912 , V_19 , V_22 , V_913 , V_914 , V_915 ;
struct V_5 * V_11 ;
bool V_916 = false ;
struct V_12 * V_12 = NULL ;
struct V_1 * V_52 ;
void T_16 * V_823 ;
T_1 V_917 , V_888 ;
enum V_313 V_189 ;
static int V_563 = 1 ;
#ifdef F_487
T_1 V_132 , V_723 ;
#endif
F_488 ( V_918 L_135 , V_919 , V_920 ) ;
V_22 = F_489 ( V_128 , V_921 ) ;
if ( V_22 ) {
F_310 ( & V_128 -> V_2 , L_136 ) ;
return V_22 ;
}
V_22 = F_425 ( V_128 ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_137 ) ;
goto V_922;
}
V_823 = F_490 ( V_128 , 0 ) ;
if ( ! V_823 ) {
F_11 ( & V_128 -> V_2 , L_138 ) ;
V_22 = - V_61 ;
goto V_923;
}
V_22 = F_428 ( V_823 ) ;
if ( V_22 < 0 )
goto V_924;
V_917 = F_480 ( V_823 + V_925 ) ;
V_888 = F_491 ( F_480 ( V_823 + V_926 ) ) ;
V_189 = F_470 ( V_128 , V_888 ) ;
V_912 = F_165 ( V_189 ) <= V_275 ?
F_492 ( V_917 ) : F_493 ( V_917 ) ;
if ( V_912 != V_911 -> V_927 ) {
#ifndef F_487
F_494 ( V_823 ) ;
#endif
F_421 ( V_128 ) ;
F_424 ( V_128 ) ;
goto V_928;
}
if ( ! F_495 ( V_128 , F_496 ( 64 ) ) ) {
V_916 = true ;
V_22 = F_497 ( V_128 , F_496 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_139
L_140 ) ;
goto V_924;
}
} else {
V_22 = F_495 ( V_128 , F_496 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_128 -> V_2 , L_141 ) ;
goto V_924;
}
}
F_498 ( V_128 ) ;
F_426 ( V_128 ) ;
F_424 ( V_128 ) ;
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_924;
}
V_563 ++ ;
V_12 -> V_254 = F_499 ( L_142 ) ;
if ( ! V_12 -> V_254 ) {
V_22 = - V_61 ;
goto V_929;
}
V_12 -> V_930 = F_27 ( sizeof( * V_12 -> V_930 ) +
( sizeof( struct V_931 ) *
V_932 ) ,
V_156 ) ;
if ( ! V_12 -> V_930 ) {
V_22 = - V_61 ;
goto V_929;
}
V_12 -> V_930 -> V_269 = V_932 ;
V_12 -> V_68 |= V_818 ;
V_12 -> V_823 = V_823 ;
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_338 ( V_128 ) ;
V_12 -> V_27 = V_912 ;
V_12 -> V_28 = V_912 ;
V_12 -> V_933 = V_934 ;
memset ( V_12 -> V_81 , 0xff , sizeof( V_12 -> V_81 ) ) ;
if ( ! F_500 ( V_128 ) )
V_12 -> V_68 |= V_935 ;
F_162 ( & V_12 -> V_325 ) ;
F_162 ( & V_12 -> V_250 ) ;
F_162 ( & V_12 -> V_334 ) ;
F_162 ( & V_12 -> V_936 ) ;
F_271 ( & V_12 -> V_937 . V_62 ) ;
F_501 ( & V_12 -> V_255 , F_151 ) ;
F_501 ( & V_12 -> V_400 , F_241 ) ;
F_501 ( & V_12 -> V_407 , F_246 ) ;
V_22 = F_502 ( V_12 ) ;
if ( V_22 )
goto V_929;
if ( ! F_105 ( V_12 -> V_188 . V_189 ) ) {
V_913 = ( V_938 +
( V_939 - V_938 ) *
V_12 -> V_28 ) ;
V_914 = 1 << F_503 ( F_68 ( V_12 ,
V_940 ) >> V_913 ) ;
V_915 = V_671 / V_941 ;
if ( V_914 > V_915 ) {
F_11 ( & V_128 -> V_2 ,
L_143 ) ;
V_22 = - V_65 ;
goto V_929;
}
V_12 -> V_413 = F_504 ( F_505 ( V_128 , 2 ) ,
F_506 ( V_128 , 2 ) ) ;
if ( ! V_12 -> V_413 ) {
F_11 ( & V_128 -> V_2 , L_144 ) ;
V_22 = - V_61 ;
goto V_929;
}
}
F_343 ( V_12 ) ;
V_22 = F_393 ( V_12 ) ;
#ifdef F_127
F_96 ( V_12 -> V_16 . V_753 , V_12 -> V_16 . V_172 ) ;
#endif
F_346 ( V_12 ) ;
if ( V_22 )
goto V_942;
if ( ! F_105 ( V_12 -> V_188 . V_189 ) )
F_70 ( V_12 , V_943 , F_507 ( 7 ) |
( F_214 ( V_12 -> V_188 . V_189 ) ? F_508 ( 0 ) :
F_509 ( 0 ) ) ) ;
F_73 (adapter, i) {
V_52 = F_510 ( sizeof( struct V_5 ) ,
V_832 ) ;
if ( ! V_52 ) {
V_22 = - V_61 ;
goto V_944;
}
F_476 ( V_52 , & V_128 -> V_2 ) ;
V_12 -> V_39 [ V_19 ] = V_52 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_74 = - 1 ;
V_11 -> V_31 = V_19 ;
V_52 -> V_130 = V_128 -> V_130 ;
V_52 -> V_945 = V_946 | V_947 |
V_948 | V_949 |
V_631 | V_950 |
V_951 | V_73 |
V_952 ;
if ( V_916 )
V_52 -> V_945 |= V_953 ;
V_52 -> V_72 |= V_52 -> V_945 ;
V_52 -> V_954 = V_52 -> V_72 & V_955 ;
V_52 -> V_895 |= V_956 ;
V_52 -> V_957 = 81 ;
V_52 -> V_308 = V_958 ;
V_52 -> V_897 = & V_959 ;
#ifdef F_16
V_52 -> V_960 = & V_961 ;
F_17 ( V_52 ) ;
#endif
F_511 ( V_52 ) ;
}
F_512 ( V_128 , V_12 ) ;
if ( V_12 -> V_68 & V_814 ) {
V_22 = F_513 ( V_12 , V_912 , V_912 , 0 ) ;
if ( V_22 )
goto V_944;
} else if ( V_12 -> V_188 . V_740 == 1 ) {
T_3 V_543 [ V_544 ] ;
T_3 * V_546 = V_12 -> V_188 . V_549 . V_546 ;
V_22 = F_306 ( V_12 , & V_12 -> V_188 . V_549 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_544 ; V_19 ++ )
V_543 [ V_19 ] = ( F_307 ( V_546 [ 2 * V_19 + 0 ] ) * 16 +
F_307 ( V_546 [ 2 * V_19 + 1 ] ) ) ;
F_514 ( V_12 , 0 , V_543 ) ;
}
}
F_435 ( V_12 ) ;
V_12 -> V_887 = F_515 ( V_12 -> V_749 , V_12 -> V_750 ) ;
if ( ! V_12 -> V_887 ) {
F_376 ( & V_128 -> V_2 , L_145 ) ;
V_12 -> V_188 . V_779 = 0 ;
}
#if F_260 ( V_443 )
if ( ( F_165 ( V_12 -> V_188 . V_189 ) <= V_275 ) &&
( ! ( F_68 ( V_12 , V_962 ) & V_963 ) ) ) {
F_376 ( & V_128 -> V_2 ,
L_146 ) ;
V_12 -> V_188 . V_779 = 0 ;
} else {
V_12 -> V_964 = F_516 ( V_12 -> V_756 ,
V_12 -> V_757 ) ;
if ( ! V_12 -> V_964 ) {
F_376 ( & V_128 -> V_2 ,
L_147 ) ;
V_12 -> V_188 . V_779 = 0 ;
}
}
#endif
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_11 -> V_965 = F_517 ( V_12 -> V_188 . V_758 ) ;
if ( ! V_11 -> V_965 )
F_376 ( & V_128 -> V_2 ,
L_148 ,
V_19 ) ;
}
if ( F_159 ( & V_12 -> V_249 ) < 0 ) {
F_376 ( & V_128 -> V_2 , L_149
L_150 ) ;
V_12 -> V_188 . V_779 = 0 ;
} else {
V_12 -> V_966 = F_518 ( V_12 ) ;
if ( ! V_12 -> V_966 )
F_376 ( & V_128 -> V_2 ,
L_151 ) ;
}
if ( F_164 ( V_12 ) ) {
if ( F_68 ( V_12 , V_962 ) & V_967 ) {
T_1 V_260 , V_968 ;
if ( V_189 <= V_275 ) {
V_968 = V_969 ;
V_260 = F_68 ( V_12 , V_968 ) ;
V_12 -> V_249 . V_260 = V_260 / 4 ;
} else {
V_968 = V_970 ;
V_260 = F_68 ( V_12 , V_968 ) ;
V_12 -> V_249 . V_260 = V_260 ;
}
}
}
if ( V_971 > 1 && F_447 ( V_12 ) == 0 )
V_12 -> V_68 |= V_127 ;
else if ( V_971 > 0 && F_519 ( V_128 ) == 0 ) {
V_12 -> V_68 |= V_129 ;
if ( V_971 > 1 )
F_446 ( V_12 ) ;
}
F_454 ( V_12 ) ;
V_22 = F_449 ( V_12 ) ;
if ( V_22 )
goto V_944;
F_73 (adapter, i) {
V_11 = F_84 ( V_12 , V_19 ) ;
V_12 -> V_39 [ V_19 ] -> V_972 = V_11 -> V_449 ;
F_520 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_521 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_18 ( V_12 -> V_39 [ V_19 ] ) ;
V_22 = F_477 ( V_12 -> V_39 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_81 [ V_11 -> V_76 ] = V_19 ;
F_463 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_128 -> V_2 , L_152 ) ;
goto V_944;
}
if ( V_22 ) {
F_376 ( & V_128 -> V_2 , L_153 , V_19 ) ;
V_22 = 0 ;
}
if ( V_973 ) {
V_12 -> V_218 = F_522 ( F_338 ( V_128 ) ,
V_973 ) ;
F_125 ( V_12 ) ;
}
V_128 -> V_974 = 1 ;
if ( F_100 ( V_12 ) ) {
F_253 ( & V_420 ) ;
F_29 ( & V_12 -> V_421 , & V_424 ) ;
F_257 ( & V_420 ) ;
}
if ( ! F_105 ( V_12 -> V_188 . V_189 ) )
F_523 ( V_12 ) ;
F_457 ( V_12 ) ;
F_95 ( V_12 ) ;
return 0 ;
V_928:
#ifdef F_487
V_12 = F_27 ( sizeof( * V_12 ) , V_156 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_975;
}
V_12 -> V_128 = V_128 ;
V_12 -> V_30 = & V_128 -> V_2 ;
V_12 -> V_9 = F_338 ( V_128 ) ;
V_12 -> V_27 = V_912 ;
V_12 -> V_28 = V_912 ;
V_12 -> V_823 = V_823 ;
V_12 -> V_563 = V_563 ;
V_12 -> V_930 = F_27 ( sizeof( * V_12 -> V_930 ) +
( sizeof( struct V_931 ) *
V_932 ) ,
V_156 ) ;
if ( ! V_12 -> V_930 ) {
V_22 = - V_61 ;
goto V_976;
}
F_162 ( & V_12 -> V_936 ) ;
F_271 ( & V_12 -> V_937 . V_62 ) ;
V_132 = F_7 ( V_712 ) |
F_8 ( V_739 ) ;
V_22 = F_386 ( V_12 , V_12 -> V_27 , V_12 -> V_28 , 0 , 1 ,
& V_132 , & V_723 ) ;
if ( V_22 < 0 ) {
F_11 ( V_12 -> V_30 , L_154 ) ;
goto V_977;
}
V_12 -> V_188 . V_740 = F_404 ( V_723 ) ;
F_512 ( V_128 , V_12 ) ;
return 0 ;
V_977:
F_34 ( V_12 -> V_930 ) ;
V_976:
F_34 ( V_12 ) ;
V_975:
F_494 ( V_823 ) ;
F_483 ( V_128 ) ;
F_524 ( V_128 ) ;
return V_22 ;
#else
return 0 ;
#endif
V_944:
F_465 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_446 ( V_12 ) ;
if ( V_12 -> V_811 || V_12 -> V_780 )
F_525 ( V_12 ) ;
V_942:
if ( ! F_105 ( V_12 -> V_188 . V_189 ) )
F_494 ( V_12 -> V_413 ) ;
V_929:
if ( V_12 -> V_254 )
F_526 ( V_12 -> V_254 ) ;
F_34 ( V_12 -> V_930 ) ;
F_34 ( V_12 ) ;
V_924:
F_494 ( V_823 ) ;
V_923:
F_527 ( V_128 ) ;
F_421 ( V_128 ) ;
V_922:
F_524 ( V_128 ) ;
return V_22 ;
}
static void F_528 ( struct V_321 * V_128 )
{
struct V_12 * V_12 = F_191 ( V_128 ) ;
if ( ! V_12 ) {
F_524 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_526 ( V_12 -> V_254 ) ;
if ( F_100 ( V_12 ) ) {
F_252 ( V_12 ) ;
F_529 ( V_12 ) ;
}
F_89 ( V_12 ) ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_978 == V_979 )
F_484 ( V_12 -> V_39 [ V_19 ] ) ;
F_530 ( V_12 -> V_218 ) ;
if ( ! F_105 ( V_12 -> V_188 . V_189 ) )
F_531 ( V_12 ) ;
F_532 ( V_12 ) ;
if ( V_12 -> V_68 & V_168 )
F_272 ( V_12 ) ;
if ( V_12 -> V_68 & V_127 )
F_446 ( V_12 ) ;
if ( V_12 -> V_811 || V_12 -> V_780 )
F_525 ( V_12 ) ;
F_465 ( V_12 ) ;
#if F_260 ( V_443 )
F_533 ( V_12 ) ;
#endif
F_494 ( V_12 -> V_823 ) ;
if ( ! F_105 ( V_12 -> V_188 . V_189 ) )
F_494 ( V_12 -> V_413 ) ;
F_527 ( V_128 ) ;
if ( ( V_12 -> V_68 & V_818 ) ) {
F_421 ( V_128 ) ;
V_12 -> V_68 &= ~ V_818 ;
}
F_524 ( V_128 ) ;
F_34 ( V_12 -> V_930 ) ;
F_534 () ;
F_34 ( V_12 ) ;
}
#ifdef F_487
else {
if ( V_12 -> V_39 [ 0 ] )
F_484 ( V_12 -> V_39 [ 0 ] ) ;
F_494 ( V_12 -> V_823 ) ;
F_34 ( V_12 -> V_551 ) ;
F_34 ( V_12 -> V_930 ) ;
F_34 ( V_12 ) ;
F_483 ( V_128 ) ;
F_524 ( V_128 ) ;
}
#endif
}
static void F_535 ( struct V_321 * V_128 )
{
struct V_12 * V_12 = F_191 ( V_128 ) ;
if ( ! V_12 ) {
F_524 ( V_128 ) ;
return;
}
if ( V_12 -> V_28 == 4 ) {
int V_19 ;
F_73 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_978 == V_979 )
F_278 ( V_12 -> V_39 [ V_19 ] ) ;
if ( F_100 ( V_12 ) ) {
F_252 ( V_12 ) ;
F_529 ( V_12 ) ;
}
F_89 ( V_12 ) ;
F_64 ( V_12 ) ;
F_274 ( V_12 ) ;
if ( V_12 -> V_68 & V_814 )
F_416 ( V_12 , V_12 -> V_27 ) ;
}
#ifdef F_487
else {
if ( V_12 -> V_39 [ 0 ] )
F_484 ( V_12 -> V_39 [ 0 ] ) ;
F_494 ( V_12 -> V_823 ) ;
F_34 ( V_12 -> V_551 ) ;
F_34 ( V_12 -> V_930 ) ;
F_34 ( V_12 ) ;
F_483 ( V_128 ) ;
F_524 ( V_128 ) ;
}
#endif
}
static int T_17 F_536 ( void )
{
int V_54 ;
V_973 = F_522 ( V_921 , NULL ) ;
if ( ! V_973 )
F_537 ( L_155 ) ;
V_54 = F_538 ( & V_380 ) ;
if ( V_54 < 0 )
F_539 ( V_973 ) ;
#if F_260 ( V_443 )
if ( ! V_980 ) {
F_540 ( & V_981 ) ;
V_980 = true ;
}
#endif
return V_54 ;
}
static void T_18 F_541 ( void )
{
#if F_260 ( V_443 )
if ( V_980 ) {
F_542 ( & V_981 ) ;
V_980 = false ;
}
#endif
F_543 ( & V_380 ) ;
F_539 ( V_973 ) ;
}
