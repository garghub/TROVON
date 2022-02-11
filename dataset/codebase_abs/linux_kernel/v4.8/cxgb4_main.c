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
int F_12 ( const struct V_1 * V_2 )
{
#ifdef F_13
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! V_11 -> V_33 . V_34 )
return 0 ;
return ( ( V_11 -> V_33 . V_35 == V_36 ) ||
( V_11 -> V_33 . V_35 == V_37 ) ) ;
#else
return 0 ;
#endif
}
void F_14 ( struct V_12 * V_12 , int V_31 , int V_38 )
{
struct V_1 * V_2 = V_12 -> V_39 [ V_31 ] ;
if ( F_15 ( V_2 ) && V_38 != F_2 ( V_2 ) ) {
if ( V_38 )
F_16 ( V_2 ) ;
else {
#ifdef F_13
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
static void F_50 ( struct V_12 * V_13 , struct V_84 * V_85 )
{
if ( V_85 -> V_86 )
F_51 ( V_85 -> V_86 ) ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
}
static void F_52 ( struct V_12 * V_13 , const struct V_87 * V_88 )
{
unsigned int V_89 = F_53 ( V_88 ) ;
unsigned int V_90 = V_89 - V_13 -> V_91 . V_92 ;
unsigned int V_54 ;
struct V_84 * V_85 ;
if ( V_89 >= V_13 -> V_91 . V_92 && V_90 <
( V_13 -> V_91 . V_93 + V_13 -> V_91 . V_94 ) ) {
V_89 = V_90 ;
V_54 = F_54 ( V_88 -> V_95 ) ;
V_85 = & V_13 -> V_91 . V_96 [ V_89 ] ;
if ( V_54 == V_97 ) {
F_50 ( V_13 , V_85 ) ;
} else if ( V_54 == V_98 ) {
F_11 ( V_13 -> V_30 , L_27 ,
V_89 ) ;
F_50 ( V_13 , V_85 ) ;
} else if ( V_54 == V_99 ) {
V_85 -> V_100 = ( F_55 ( V_88 -> V_101 ) >> 24 ) & 0xff ;
V_85 -> V_102 = 0 ;
V_85 -> V_103 = 1 ;
} else {
F_11 ( V_13 -> V_30 , L_28 ,
V_89 , V_54 ) ;
F_50 ( V_13 , V_85 ) ;
}
}
}
static int F_56 ( struct V_104 * V_25 , const T_4 * V_105 ,
const struct V_106 * V_107 )
{
T_3 V_108 = ( ( const struct V_109 * ) V_105 ) -> V_108 ;
V_105 ++ ;
if ( F_57 ( V_108 == V_110 &&
( ( const struct V_111 * ) V_105 ) -> type == V_112 ) ) {
V_105 ++ ;
V_108 = ( ( const struct V_109 * ) V_105 ) -> V_108 ;
V_105 ++ ;
if ( V_108 != V_113 ) {
F_11 ( V_25 -> V_13 -> V_30 , L_29
, V_108 ) ;
goto V_59;
}
}
if ( F_58 ( V_108 == V_113 ) ) {
const struct V_114 * V_6 = ( void * ) V_105 ;
unsigned int V_115 = F_59 ( F_48 ( V_6 -> V_116 ) ) ;
struct V_117 * V_15 ;
V_15 = V_25 -> V_13 -> V_16 . V_118 [ V_115 - V_25 -> V_13 -> V_16 . V_119 ] ;
V_15 -> V_120 ++ ;
if ( ( T_3 * ) V_15 < ( T_3 * ) V_25 -> V_13 -> V_16 . V_121 ) {
struct V_14 * V_122 ;
V_122 = F_60 ( V_15 , struct V_14 , V_25 ) ;
F_61 ( V_122 -> V_15 ) ;
} else {
struct V_123 * V_124 ;
V_124 = F_60 ( V_15 , struct V_123 , V_25 ) ;
F_62 ( & V_124 -> V_125 ) ;
}
} else if ( V_108 == V_126 || V_108 == V_110 ) {
const struct V_127 * V_6 = ( void * ) V_105 ;
#ifdef F_13
const struct V_78 * V_79 = ( const void * ) V_6 -> V_128 ;
unsigned int V_129 = F_63 ( F_48 ( V_79 -> V_80 ) ) ;
unsigned int V_130 =
F_64 ( F_48 ( V_79 -> V_131 ) ) ;
if ( V_129 == V_132 &&
V_130 == V_133 ) {
int V_39 = F_47 (
F_65 ( V_79 -> V_80 ) ) ;
struct V_1 * V_2 =
V_25 -> V_13 -> V_39 [ V_25 -> V_13 -> V_81 [ V_39 ] ] ;
int V_134 = ( ( V_79 -> V_135 . V_136 . V_137 &
V_138 )
? V_139
: V_140 ) ;
F_66 ( V_2 , V_134 ) ;
}
if ( V_129 == V_132 &&
V_130 == V_141 )
F_46 ( V_25 -> V_13 , V_79 ) ;
else
#endif
if ( V_6 -> type == 0 )
F_67 ( V_25 -> V_13 , V_6 -> V_128 ) ;
} else if ( V_108 == V_142 ) {
const struct V_143 * V_6 = ( void * ) V_105 ;
F_68 ( V_25 -> V_13 , V_6 ) ;
} else if ( V_108 == V_144 ) {
const struct V_87 * V_6 = ( void * ) V_105 ;
F_52 ( V_25 -> V_13 , V_6 ) ;
} else
F_11 ( V_25 -> V_13 -> V_30 ,
L_30 , V_108 ) ;
V_59:
return 0 ;
}
static void F_69 ( struct V_104 * V_25 )
{
if ( V_145 [ V_25 -> V_146 ] . V_147 )
V_145 [ V_25 -> V_146 ] . V_147 ( & V_25 -> V_148 ) ;
}
static int F_70 ( struct V_104 * V_25 , const T_4 * V_105 ,
const struct V_106 * V_107 )
{
struct V_149 * V_150 = F_60 ( V_25 , struct V_149 , V_151 ) ;
int V_54 ;
if ( ( ( const struct V_109 * ) V_105 ) -> V_108 == V_110 &&
( ( const struct V_111 * ) ( V_105 + 1 ) ) -> type == V_112 )
V_105 += 2 ;
if ( V_25 -> V_152 )
V_54 = V_145 [ V_25 -> V_146 ] . F_71 ( V_25 -> V_13 -> V_153 [ V_25 -> V_146 ] ,
V_105 , V_107 , & V_25 -> V_148 ,
& V_25 -> V_154 ) ;
else
V_54 = V_145 [ V_25 -> V_146 ] . F_72 ( V_25 -> V_13 -> V_153 [ V_25 -> V_146 ] ,
V_105 , V_107 ) ;
if ( V_54 ) {
V_150 -> V_155 . V_156 ++ ;
return - 1 ;
}
if ( V_107 == NULL )
V_150 -> V_155 . V_157 ++ ;
else if ( V_107 == V_158 )
V_150 -> V_155 . V_159 ++ ;
else
V_150 -> V_155 . V_160 ++ ;
return 0 ;
}
static void F_73 ( struct V_12 * V_12 )
{
if ( V_12 -> V_68 & V_161 ) {
F_74 ( V_12 -> V_162 ) ;
V_12 -> V_68 &= ~ V_161 ;
} else if ( V_12 -> V_68 & V_163 ) {
F_75 ( V_12 -> V_162 ) ;
V_12 -> V_68 &= ~ V_163 ;
}
}
static T_5 F_76 ( int V_164 , void * V_95 )
{
struct V_12 * V_13 = V_95 ;
T_1 V_165 = F_77 ( V_13 , F_78 ( V_166 ) ) ;
if ( V_165 & V_167 ) {
V_13 -> V_168 = 1 ;
F_79 ( V_13 , F_78 ( V_166 ) , V_165 ) ;
}
if ( V_13 -> V_68 & V_169 )
F_80 ( V_13 ) ;
return V_170 ;
}
static void F_81 ( struct V_12 * V_13 )
{
int V_19 , V_171 , V_172 = 2 , V_173 = sizeof( V_13 -> V_174 [ 0 ] . V_175 ) ;
snprintf ( V_13 -> V_174 [ 0 ] . V_175 , V_173 , L_31 , V_13 -> V_39 [ 0 ] -> V_9 ) ;
snprintf ( V_13 -> V_174 [ 1 ] . V_175 , V_173 , L_32 ,
V_13 -> V_39 [ 0 ] -> V_9 ) ;
F_82 (adap, j) {
struct V_1 * V_176 = V_13 -> V_39 [ V_171 ] ;
const struct V_5 * V_11 = F_4 ( V_176 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_172 ++ )
snprintf ( V_13 -> V_174 [ V_172 ] . V_175 , V_173 , L_33 ,
V_176 -> V_9 , V_19 ) ;
}
F_83 (&adap->sge, i)
snprintf ( V_13 -> V_174 [ V_172 ++ ] . V_175 , V_173 , L_34 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_19 ) ;
F_84 (&adap->sge, i)
snprintf ( V_13 -> V_174 [ V_172 ++ ] . V_175 , V_173 , L_35 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_19 ) ;
F_85 (&adap->sge, i)
snprintf ( V_13 -> V_174 [ V_172 ++ ] . V_175 , V_173 , L_36 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_19 ) ;
F_86 (&adap->sge, i)
snprintf ( V_13 -> V_174 [ V_172 ++ ] . V_175 , V_173 , L_37 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_19 ) ;
}
static int F_87 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 , V_177 , V_178 = 0 , V_179 = 0 , V_180 = 0 ;
int V_181 = 0 ;
int V_182 = 2 ;
V_22 = F_88 ( V_13 -> V_174 [ 1 ] . V_46 , V_183 , 0 ,
V_13 -> V_174 [ 1 ] . V_175 , & V_4 -> V_184 ) ;
if ( V_22 )
return V_22 ;
F_89 (s, ethqidx) {
V_22 = F_88 ( V_13 -> V_174 [ V_182 ] . V_46 ,
V_183 , 0 ,
V_13 -> V_174 [ V_182 ] . V_175 ,
& V_4 -> V_185 [ V_177 ] . V_151 ) ;
if ( V_22 )
goto V_186;
V_182 ++ ;
}
F_83 (s, iscsiqidx) {
V_22 = F_88 ( V_13 -> V_174 [ V_182 ] . V_46 ,
V_183 , 0 ,
V_13 -> V_174 [ V_182 ] . V_175 ,
& V_4 -> V_187 [ V_178 ] . V_151 ) ;
if ( V_22 )
goto V_186;
V_182 ++ ;
}
F_84 (s, iscsitqidx) {
V_22 = F_88 ( V_13 -> V_174 [ V_182 ] . V_46 ,
V_183 , 0 ,
V_13 -> V_174 [ V_182 ] . V_175 ,
& V_4 -> V_188 [ V_181 ] . V_151 ) ;
if ( V_22 )
goto V_186;
V_182 ++ ;
}
F_85 (s, rdmaqidx) {
V_22 = F_88 ( V_13 -> V_174 [ V_182 ] . V_46 ,
V_183 , 0 ,
V_13 -> V_174 [ V_182 ] . V_175 ,
& V_4 -> V_189 [ V_179 ] . V_151 ) ;
if ( V_22 )
goto V_186;
V_182 ++ ;
}
F_86 (s, rdmaciqqidx) {
V_22 = F_88 ( V_13 -> V_174 [ V_182 ] . V_46 ,
V_183 , 0 ,
V_13 -> V_174 [ V_182 ] . V_175 ,
& V_4 -> V_190 [ V_180 ] . V_151 ) ;
if ( V_22 )
goto V_186;
V_182 ++ ;
}
return 0 ;
V_186:
while ( -- V_180 >= 0 )
F_90 ( V_13 -> V_174 [ -- V_182 ] . V_46 ,
& V_4 -> V_190 [ V_180 ] . V_151 ) ;
while ( -- V_179 >= 0 )
F_90 ( V_13 -> V_174 [ -- V_182 ] . V_46 ,
& V_4 -> V_189 [ V_179 ] . V_151 ) ;
while ( -- V_181 >= 0 )
F_90 ( V_13 -> V_174 [ -- V_182 ] . V_46 ,
& V_4 -> V_188 [ V_181 ] . V_151 ) ;
while ( -- V_178 >= 0 )
F_90 ( V_13 -> V_174 [ -- V_182 ] . V_46 ,
& V_4 -> V_187 [ V_178 ] . V_151 ) ;
while ( -- V_177 >= 0 )
F_90 ( V_13 -> V_174 [ -- V_182 ] . V_46 ,
& V_4 -> V_185 [ V_177 ] . V_151 ) ;
F_90 ( V_13 -> V_174 [ 1 ] . V_46 , & V_4 -> V_184 ) ;
return V_22 ;
}
static void F_91 ( struct V_12 * V_13 )
{
int V_19 , V_182 = 2 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_90 ( V_13 -> V_174 [ 1 ] . V_46 , & V_4 -> V_184 ) ;
F_89 (s, i)
F_90 ( V_13 -> V_174 [ V_182 ++ ] . V_46 , & V_4 -> V_185 [ V_19 ] . V_151 ) ;
F_83 (s, i)
F_90 ( V_13 -> V_174 [ V_182 ++ ] . V_46 ,
& V_4 -> V_187 [ V_19 ] . V_151 ) ;
F_84 (s, i)
F_90 ( V_13 -> V_174 [ V_182 ++ ] . V_46 ,
& V_4 -> V_188 [ V_19 ] . V_151 ) ;
F_85 (s, i)
F_90 ( V_13 -> V_174 [ V_182 ++ ] . V_46 , & V_4 -> V_189 [ V_19 ] . V_151 ) ;
F_86 (s, i)
F_90 ( V_13 -> V_174 [ V_182 ++ ] . V_46 , & V_4 -> V_190 [ V_19 ] . V_151 ) ;
}
int F_92 ( const struct V_5 * V_11 , const T_6 * V_191 )
{
T_6 * V_192 ;
int V_19 , V_22 ;
struct V_12 * V_12 = V_11 -> V_12 ;
const struct V_193 * V_150 ;
V_150 = & V_12 -> V_16 . V_185 [ V_11 -> V_18 ] ;
V_192 = F_93 ( V_11 -> V_194 * sizeof( T_6 ) , V_195 ) ;
if ( ! V_192 )
return - V_61 ;
for ( V_19 = 0 ; V_19 < V_11 -> V_194 ; V_19 ++ , V_191 ++ )
V_192 [ V_19 ] = V_150 [ * V_191 ] . V_151 . V_196 ;
V_22 = F_94 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , 0 ,
V_11 -> V_194 , V_192 , V_11 -> V_194 ) ;
if ( ! V_22 )
V_22 = F_95 ( V_12 , V_12 -> V_27 , V_11 -> V_51 ,
V_197 |
V_198 |
V_199 |
V_200 |
V_201 ,
V_192 [ 0 ] ) ;
F_34 ( V_192 ) ;
return V_22 ;
}
static int F_96 ( struct V_12 * V_13 )
{
int V_19 , V_171 , V_22 ;
F_82 (adap, i) {
const struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
for ( V_171 = 0 ; V_171 < V_11 -> V_194 ; V_171 ++ )
V_11 -> V_192 [ V_171 ] = V_171 % V_11 -> V_20 ;
V_22 = F_92 ( V_11 , V_11 -> V_192 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static unsigned int F_98 ( const struct V_16 * V_6 , unsigned int V_115 )
{
V_115 -= V_6 -> V_202 ;
return F_99 ( V_6 -> V_203 [ V_115 ] -> V_52 ) -> V_76 ;
}
static void F_100 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_204 ; V_19 ++ ) {
struct V_104 * V_25 = V_13 -> V_16 . V_203 [ V_19 ] ;
if ( V_25 && V_25 -> V_205 ) {
F_101 ( & V_25 -> V_154 ) ;
F_43 () ;
while ( ! F_102 ( V_25 ) )
F_103 ( 1 ) ;
F_45 () ;
}
}
}
static void F_104 ( struct V_12 * V_13 )
{
if ( V_13 -> V_68 & V_206 ) {
F_105 ( V_13 ) ;
if ( V_13 -> V_68 & V_161 ) {
F_91 ( V_13 ) ;
F_90 ( V_13 -> V_174 [ 0 ] . V_46 , V_13 ) ;
} else {
F_90 ( V_13 -> V_162 -> V_164 , V_13 ) ;
}
F_100 ( V_13 ) ;
}
}
static void F_106 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_204 ; V_19 ++ ) {
struct V_104 * V_25 = V_13 -> V_16 . V_203 [ V_19 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_205 ) {
F_107 ( V_25 ) ;
F_108 ( & V_25 -> V_154 ) ;
}
F_79 ( V_13 , F_78 ( V_207 ) ,
F_109 ( V_25 -> V_208 ) |
F_110 ( V_25 -> V_26 ) ) ;
}
}
static int F_111 ( struct V_12 * V_13 , struct V_149 * V_25 ,
unsigned int V_209 , unsigned int V_210 , int V_172 ,
T_6 * V_211 , bool V_212 )
{
int V_19 , V_22 ;
for ( V_19 = 0 ; V_19 < V_209 ; V_19 ++ , V_25 ++ ) {
if ( V_172 > 0 )
V_172 ++ ;
V_22 = F_112 ( V_13 , & V_25 -> V_151 , false ,
V_13 -> V_39 [ V_19 / V_210 ] ,
V_172 , V_25 -> V_213 . V_214 ? & V_25 -> V_213 : NULL ,
F_70 ,
V_212 ? F_69 : NULL ,
0 ) ;
if ( V_22 )
return V_22 ;
memset ( & V_25 -> V_155 , 0 , sizeof( V_25 -> V_155 ) ) ;
if ( V_211 )
V_211 [ V_19 ] = V_25 -> V_151 . V_196 ;
}
return 0 ;
}
static int F_113 ( struct V_12 * V_13 )
{
int V_22 , V_172 , V_19 , V_171 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_114 ( V_4 -> V_215 , V_4 -> V_216 ) ;
F_114 ( V_4 -> V_217 , V_4 -> V_216 ) ;
if ( V_13 -> V_68 & V_161 )
V_172 = 1 ;
else {
V_22 = F_112 ( V_13 , & V_4 -> V_218 , false , V_13 -> V_39 [ 0 ] , 0 ,
NULL , NULL , NULL , - 1 ) ;
if ( V_22 )
return V_22 ;
V_172 = - ( ( int ) V_4 -> V_218 . V_196 + 1 ) ;
}
V_22 = F_112 ( V_13 , & V_4 -> V_184 , true , V_13 -> V_39 [ 0 ] ,
V_172 , NULL , F_56 , NULL , - 1 ) ;
if ( V_22 ) {
V_219: F_115 ( V_13 ) ;
return V_22 ;
}
F_82 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_193 * V_25 = & V_4 -> V_185 [ V_11 -> V_18 ] ;
struct V_14 * V_220 = & V_4 -> V_17 [ V_11 -> V_18 ] ;
for ( V_171 = 0 ; V_171 < V_11 -> V_20 ; V_171 ++ , V_25 ++ ) {
if ( V_172 > 0 )
V_172 ++ ;
V_22 = F_112 ( V_13 , & V_25 -> V_151 , false , V_2 ,
V_172 , & V_25 -> V_213 ,
V_221 ,
NULL ,
F_116 ( V_13 ,
V_11 -> V_76 ) ) ;
if ( V_22 )
goto V_219;
V_25 -> V_151 . V_89 = V_171 ;
memset ( & V_25 -> V_155 , 0 , sizeof( V_25 -> V_155 ) ) ;
}
for ( V_171 = 0 ; V_171 < V_11 -> V_20 ; V_171 ++ , V_220 ++ ) {
V_22 = F_117 ( V_13 , V_220 , V_2 ,
F_118 ( V_2 , V_171 ) ,
V_4 -> V_184 . V_26 ) ;
if ( V_22 )
goto V_219;
}
}
V_171 = V_4 -> V_222 / V_13 -> V_223 . V_224 ;
F_83 (s, i) {
V_22 = F_119 ( V_13 , & V_4 -> V_121 [ V_19 ] ,
V_13 -> V_39 [ V_19 / V_171 ] ,
V_4 -> V_184 . V_26 ) ;
if ( V_22 )
goto V_219;
}
#define F_120 ( T_7 , V_209 , V_210 , V_211 , V_212 ) do { \
err = alloc_ofld_rxqs(adap, firstq, nq, per_chan, msi_idx, ids, lro); \
if (err) \
goto freeout; \
if (msi_idx > 0) \
msi_idx += nq; \
} while (0)
F_120 ( V_4 -> V_187 , V_4 -> V_222 , V_171 , V_4 -> V_225 , false ) ;
F_120 ( V_4 -> V_188 , V_4 -> V_226 , V_171 , V_4 -> V_227 , true ) ;
F_120 ( V_4 -> V_189 , V_4 -> V_228 , 1 , V_4 -> V_229 , false ) ;
V_171 = V_4 -> V_230 / V_13 -> V_223 . V_224 ;
F_120 ( V_4 -> V_190 , V_4 -> V_230 , V_171 , V_4 -> V_231 , false ) ;
#undef F_120
F_82 (adap, i) {
V_22 = F_121 ( V_13 , & V_4 -> V_232 [ V_19 ] , V_13 -> V_39 [ V_19 ] ,
V_4 -> V_184 . V_26 ,
V_4 -> V_189 [ V_19 ] . V_151 . V_26 ) ;
if ( V_22 )
goto V_219;
}
F_79 ( V_13 , F_122 ( V_13 -> V_223 . V_233 ) ?
V_234 :
V_235 ,
F_123 ( F_99 ( V_13 -> V_39 [ 0 ] ) -> V_76 ) |
F_124 ( V_4 -> V_185 [ 0 ] . V_151 . V_196 ) ) ;
return 0 ;
}
void * F_125 ( T_8 V_214 )
{
void * V_6 = F_27 ( V_214 , V_195 | V_236 ) ;
if ( ! V_6 )
V_6 = F_126 ( V_214 ) ;
return V_6 ;
}
void F_127 ( void * V_50 )
{
F_128 ( V_50 ) ;
}
static int F_129 ( struct V_12 * V_12 , int V_237 )
{
struct V_84 * V_85 = & V_12 -> V_91 . V_96 [ V_237 ] ;
struct V_238 * V_239 ;
struct V_240 * V_241 ;
unsigned int V_242 ;
V_239 = F_130 ( sizeof( * V_241 ) , V_195 ) ;
if ( ! V_239 )
return - V_61 ;
if ( V_85 -> V_243 . V_244 || V_85 -> V_243 . V_245 ) {
V_85 -> V_86 = F_131 ( V_12 , V_85 -> V_243 . V_246 ,
V_85 -> V_243 . V_247 , V_85 -> V_243 . V_248 ) ;
if ( V_85 -> V_86 == NULL ) {
F_132 ( V_239 ) ;
return - V_61 ;
}
}
V_242 = V_12 -> V_91 . V_92 + V_237 ;
V_241 = (struct V_240 * ) F_133 ( V_239 , sizeof( * V_241 ) ) ;
memset ( V_241 , 0 , sizeof( * V_241 ) ) ;
V_241 -> V_249 = F_134 ( F_135 ( V_250 ) ) ;
V_241 -> V_251 = F_134 ( F_136 ( sizeof( * V_241 ) / 16 ) ) ;
V_241 -> V_252 =
F_134 ( F_137 ( V_242 ) |
F_138 ( V_85 -> V_243 . type ) |
F_139 ( 0 ) |
F_140 ( V_85 -> V_243 . V_253 ) ) ;
V_241 -> V_254 =
F_134 ( F_141 ( V_85 -> V_243 . V_255 ) |
F_142 ( V_85 -> V_243 . V_130 == V_256 ) |
F_143 ( V_85 -> V_243 . V_257 ) |
F_144 ( V_85 -> V_243 . V_258 ) |
F_145 ( V_85 -> V_243 . V_259 ) |
F_146 ( V_85 -> V_243 . V_130 == V_260 ) |
F_147 ( V_85 -> V_243 . V_244 ) |
F_148 ( V_85 -> V_243 . V_261 ) |
F_149 ( V_85 -> V_243 . V_245 == V_262 ||
V_85 -> V_243 . V_245 == V_263 ) |
F_150 ( V_85 -> V_243 . V_245 == V_264 ||
V_85 -> V_243 . V_245 == V_263 ) |
F_151 ( V_85 -> V_243 . V_265 ) |
F_152 ( V_85 -> V_243 . V_247 ) |
F_153 ( V_85 -> V_243 . V_266 ) |
F_154 ( V_85 -> V_86 ? V_85 -> V_86 -> V_89 : 0 ) ) ;
V_241 -> V_267 = F_155 ( V_85 -> V_243 . V_268 . V_267 ) ;
V_241 -> V_269 = F_155 ( V_85 -> V_243 . V_270 . V_267 ) ;
V_241 -> V_271 =
( F_156 ( V_85 -> V_243 . V_268 . V_272 ) |
F_157 ( V_85 -> V_243 . V_270 . V_272 ) |
F_158 ( V_85 -> V_243 . V_268 . V_273 ) |
F_159 ( V_85 -> V_243 . V_268 . V_274 ) |
F_160 ( V_85 -> V_243 . V_270 . V_273 ) |
F_161 ( V_85 -> V_243 . V_270 . V_274 ) ) ;
V_241 -> V_275 = 0 ;
V_241 -> V_276 =
F_155 ( F_162 ( 0 ) |
F_163 ( V_12 -> V_16 . V_184 . V_196 ) ) ;
V_241 -> V_277 =
F_134 ( F_164 ( V_85 -> V_243 . V_268 . V_278 ) |
F_165 ( V_85 -> V_243 . V_270 . V_278 ) |
F_166 ( V_85 -> V_243 . V_268 . V_279 ) |
F_167 ( V_85 -> V_243 . V_270 . V_279 ) |
F_168 ( V_85 -> V_243 . V_268 . V_280 ) |
F_169 ( V_85 -> V_243 . V_270 . V_280 ) |
F_170 ( V_85 -> V_243 . V_268 . V_281 ) |
F_171 ( V_85 -> V_243 . V_270 . V_281 ) ) ;
V_241 -> V_282 = V_85 -> V_243 . V_268 . V_283 ;
V_241 -> V_284 = V_85 -> V_243 . V_270 . V_283 ;
V_241 -> V_285 = V_85 -> V_243 . V_268 . V_286 ;
V_241 -> V_287 = V_85 -> V_243 . V_270 . V_286 ;
V_241 -> V_288 = F_155 ( V_85 -> V_243 . V_268 . V_288 ) ;
V_241 -> V_289 = F_155 ( V_85 -> V_243 . V_270 . V_288 ) ;
V_241 -> V_290 = F_155 ( V_85 -> V_243 . V_268 . V_290 ) ;
V_241 -> V_291 = F_155 ( V_85 -> V_243 . V_270 . V_290 ) ;
memcpy ( V_241 -> V_292 , V_85 -> V_243 . V_268 . V_292 , sizeof( V_241 -> V_292 ) ) ;
memcpy ( V_241 -> V_293 , V_85 -> V_243 . V_270 . V_292 , sizeof( V_241 -> V_293 ) ) ;
memcpy ( V_241 -> V_294 , V_85 -> V_243 . V_268 . V_294 , sizeof( V_241 -> V_294 ) ) ;
memcpy ( V_241 -> V_295 , V_85 -> V_243 . V_270 . V_294 , sizeof( V_241 -> V_295 ) ) ;
V_241 -> V_296 = F_155 ( V_85 -> V_243 . V_268 . V_297 ) ;
V_241 -> V_298 = F_155 ( V_85 -> V_243 . V_270 . V_297 ) ;
V_241 -> V_299 = F_155 ( V_85 -> V_243 . V_268 . V_300 ) ;
V_241 -> V_301 = F_155 ( V_85 -> V_243 . V_270 . V_300 ) ;
if ( V_85 -> V_243 . V_261 )
memcpy ( V_241 -> V_302 , V_85 -> V_243 . V_303 , sizeof( V_241 -> V_302 ) ) ;
V_85 -> V_102 = 1 ;
F_172 ( V_239 , V_304 , V_85 -> V_243 . V_268 . V_280 & 0x3 ) ;
F_173 ( V_12 , V_239 ) ;
return 0 ;
}
static int F_174 ( struct V_12 * V_12 , int V_237 )
{
struct V_84 * V_85 = & V_12 -> V_91 . V_96 [ V_237 ] ;
struct V_238 * V_239 ;
struct V_240 * V_241 ;
unsigned int V_305 , V_242 ;
V_305 = sizeof( * V_241 ) ;
V_242 = V_12 -> V_91 . V_92 + V_237 ;
V_239 = F_130 ( V_305 , V_195 ) ;
if ( ! V_239 )
return - V_61 ;
V_241 = (struct V_240 * ) F_133 ( V_239 , V_305 ) ;
F_175 ( V_242 , V_241 , V_12 -> V_16 . V_184 . V_196 ) ;
V_85 -> V_102 = 1 ;
F_176 ( V_12 , V_239 ) ;
return 0 ;
}
static T_6 F_177 ( struct V_1 * V_2 , struct V_238 * V_239 ,
void * V_306 , T_9 V_307 )
{
int V_15 ;
#ifdef F_13
if ( F_12 ( V_2 ) ) {
T_6 V_308 ;
int V_22 ;
V_22 = F_178 ( V_239 , & V_308 ) ;
if ( F_57 ( V_22 ) ) {
if ( F_179 () )
F_180 ( V_2 ,
L_38 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_308 & V_309 ) >> V_310 ;
#ifdef F_181
if ( V_239 -> V_311 == F_155 ( V_312 ) )
V_15 = V_239 -> V_313 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_314 ) {
V_15 = ( F_182 ( V_239 )
? F_183 ( V_239 )
: F_184 () ) ;
while ( F_57 ( V_15 >= V_2 -> V_315 ) )
V_15 -= V_2 -> V_315 ;
return V_15 ;
}
return V_307 ( V_2 , V_239 ) % V_2 -> V_315 ;
}
static int F_185 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_316 , V_317 = 0 , V_318 = V_319 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_320 ) ; V_19 ++ ) {
V_316 = time - V_4 -> V_320 [ V_19 ] ;
if ( V_316 < 0 )
V_316 = - V_316 ;
if ( V_316 < V_318 ) {
V_318 = V_316 ;
V_317 = V_19 ;
}
}
return V_317 ;
}
static int F_186 ( const struct V_16 * V_4 , int V_321 )
{
int V_19 , V_316 , V_317 = 0 , V_318 = V_319 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_322 ) ; V_19 ++ ) {
V_316 = V_321 - V_4 -> V_322 [ V_19 ] ;
if ( V_316 < 0 )
V_316 = - V_316 ;
if ( V_316 < V_318 ) {
V_318 = V_316 ;
V_317 = V_19 ;
}
}
return V_317 ;
}
int F_187 ( struct V_104 * V_25 ,
unsigned int V_323 , unsigned int V_324 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_323 | V_324 ) == 0 )
V_324 = 1 ;
if ( V_324 ) {
int V_22 ;
T_1 V_165 , V_325 ;
V_325 = F_186 ( & V_13 -> V_16 , V_324 ) ;
if ( V_25 -> V_175 && V_25 -> V_326 != V_325 ) {
V_165 = F_7 ( V_23 ) |
F_8 (
V_327 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_188 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_165 , & V_325 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_326 = V_325 ;
}
V_323 = V_323 == 0 ? 6 : F_185 ( & V_13 -> V_16 , V_323 ) ;
V_25 -> V_208 = F_189 ( V_323 ) | F_190 ( V_324 > 0 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , T_10 V_72 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_10 V_328 = V_2 -> V_72 ^ V_72 ;
int V_22 ;
if ( ! ( V_328 & V_73 ) )
return 0 ;
V_22 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_72 & V_73 ) , true ) ;
if ( F_57 ( V_22 ) )
V_2 -> V_72 = V_72 ^ V_73 ;
return V_22 ;
}
static int F_192 ( struct V_12 * V_13 )
{
if ( F_193 ( V_13 -> V_329 ) )
return - 1 ;
#ifdef F_194
F_195 ( V_13 ) ;
#endif
return 0 ;
}
int F_196 ( struct V_330 * V_220 , void * V_128 )
{
int V_331 = - 1 ;
F_197 ( & V_220 -> V_332 ) ;
if ( V_220 -> V_333 ) {
union V_334 * V_6 = V_220 -> V_333 ;
V_331 = ( V_6 - V_220 -> V_335 ) + V_220 -> V_336 ;
V_220 -> V_333 = V_6 -> V_337 ;
V_6 -> V_128 = V_128 ;
V_220 -> V_338 ++ ;
}
F_198 ( & V_220 -> V_332 ) ;
return V_331 ;
}
void F_199 ( struct V_330 * V_220 , unsigned int V_331 )
{
union V_334 * V_6 = & V_220 -> V_335 [ V_331 - V_220 -> V_336 ] ;
F_197 ( & V_220 -> V_332 ) ;
V_6 -> V_337 = V_220 -> V_333 ;
V_220 -> V_333 = V_6 ;
V_220 -> V_338 -- ;
F_198 ( & V_220 -> V_332 ) ;
}
int F_200 ( struct V_330 * V_220 , int V_339 , void * V_128 )
{
int V_340 ;
F_197 ( & V_220 -> V_341 ) ;
if ( V_339 == V_342 ) {
V_340 = F_201 ( V_220 -> V_343 , V_220 -> V_344 ) ;
if ( V_340 < V_220 -> V_344 )
F_202 ( V_340 , V_220 -> V_343 ) ;
else
V_340 = - 1 ;
} else {
V_340 = F_203 ( V_220 -> V_343 , V_220 -> V_344 , 1 ) ;
if ( V_340 < 0 )
V_340 = - 1 ;
}
if ( V_340 >= 0 ) {
V_220 -> V_345 [ V_340 ] . V_128 = V_128 ;
V_340 += V_220 -> V_346 ;
if ( V_339 == V_342 )
V_220 -> V_347 ++ ;
else
V_220 -> V_347 += 2 ;
}
F_198 ( & V_220 -> V_341 ) ;
return V_340 ;
}
int F_204 ( struct V_330 * V_220 , int V_339 , void * V_128 )
{
int V_340 ;
F_197 ( & V_220 -> V_341 ) ;
if ( V_339 == V_342 ) {
V_340 = F_205 ( V_220 -> V_343 ,
V_220 -> V_344 + V_220 -> V_94 , V_220 -> V_344 ) ;
if ( V_340 < ( V_220 -> V_344 + V_220 -> V_94 ) )
F_202 ( V_340 , V_220 -> V_343 ) ;
else
V_340 = - 1 ;
} else {
V_340 = - 1 ;
}
if ( V_340 >= 0 ) {
V_220 -> V_345 [ V_340 ] . V_128 = V_128 ;
V_340 -= V_220 -> V_344 ;
V_340 += V_220 -> V_348 ;
V_220 -> V_349 ++ ;
}
F_198 ( & V_220 -> V_341 ) ;
return V_340 ;
}
void F_206 ( struct V_330 * V_220 , unsigned int V_340 , int V_339 )
{
if ( V_220 -> V_94 && ( V_340 >= V_220 -> V_348 ) ) {
V_340 -= V_220 -> V_348 ;
V_340 += V_220 -> V_344 ;
} else {
V_340 -= V_220 -> V_346 ;
}
F_197 ( & V_220 -> V_341 ) ;
if ( V_339 == V_342 )
F_207 ( V_340 , V_220 -> V_343 ) ;
else
F_208 ( V_220 -> V_343 , V_340 , 1 ) ;
V_220 -> V_345 [ V_340 ] . V_128 = NULL ;
if ( V_340 < V_220 -> V_344 ) {
if ( V_339 == V_342 )
V_220 -> V_347 -- ;
else
V_220 -> V_347 -= 2 ;
} else {
V_220 -> V_349 -- ;
}
F_198 ( & V_220 -> V_341 ) ;
}
static void F_209 ( struct V_238 * V_239 , unsigned int V_350 ,
unsigned int V_351 )
{
struct V_352 * V_353 ;
F_172 ( V_239 , V_354 , V_350 ) ;
V_353 = (struct V_352 * ) F_133 ( V_239 , sizeof( * V_353 ) ) ;
F_210 ( V_353 , V_351 ) ;
F_211 ( V_353 ) = F_134 ( F_212 ( V_355 , V_351 ) ) ;
}
static void F_213 ( struct V_330 * V_220 , unsigned int V_350 ,
unsigned int V_351 )
{
void * * V_6 = & V_220 -> V_356 [ V_351 ] ;
struct V_12 * V_13 = F_60 ( V_220 , struct V_12 , V_91 ) ;
F_197 ( & V_13 -> V_357 ) ;
* V_6 = V_13 -> V_358 ;
V_13 -> V_358 = ( void * * ) ( ( V_359 ) V_6 | V_350 ) ;
if ( ! V_13 -> V_360 ) {
V_13 -> V_360 = true ;
F_214 ( V_13 -> V_361 , & V_13 -> V_362 ) ;
}
F_198 ( & V_13 -> V_357 ) ;
}
static void F_215 ( struct V_363 * V_364 )
{
struct V_238 * V_239 ;
struct V_12 * V_13 ;
V_13 = F_60 ( V_364 , struct V_12 , V_362 ) ;
F_197 ( & V_13 -> V_357 ) ;
while ( V_13 -> V_358 ) {
void * * V_6 = V_13 -> V_358 ;
unsigned int V_350 = ( V_359 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_350 ;
V_13 -> V_358 = * V_6 ;
* V_6 = NULL ;
F_198 ( & V_13 -> V_357 ) ;
while ( ! ( V_239 = F_130 ( sizeof( struct V_352 ) ,
V_195 ) ) )
F_216 ( 1 ) ;
F_209 ( V_239 , V_350 , V_6 - V_13 -> V_91 . V_356 ) ;
F_173 ( V_13 , V_239 ) ;
F_197 ( & V_13 -> V_357 ) ;
}
V_13 -> V_360 = false ;
F_198 ( & V_13 -> V_357 ) ;
}
void F_217 ( struct V_330 * V_220 , unsigned int V_350 , unsigned int V_351 )
{
struct V_238 * V_239 ;
struct V_12 * V_13 = F_60 ( V_220 , struct V_12 , V_91 ) ;
F_218 ( V_351 >= V_220 -> V_365 ) ;
if ( V_220 -> V_356 [ V_351 ] ) {
V_220 -> V_356 [ V_351 ] = NULL ;
if ( V_220 -> V_366 && ( V_351 >= V_220 -> V_366 ) )
F_219 ( & V_220 -> V_367 ) ;
else
F_219 ( & V_220 -> V_368 ) ;
}
V_239 = F_130 ( sizeof( struct V_352 ) , V_60 ) ;
if ( F_58 ( V_239 ) ) {
F_209 ( V_239 , V_350 , V_351 ) ;
F_173 ( V_13 , V_239 ) ;
} else
F_213 ( V_220 , V_350 , V_351 ) ;
}
static int F_220 ( struct V_330 * V_220 )
{
T_8 V_214 ;
unsigned int V_369 ;
unsigned int V_370 = V_220 -> V_370 ;
struct V_12 * V_13 = F_60 ( V_220 , struct V_12 , V_91 ) ;
V_369 = F_221 ( V_220 -> V_344 + V_220 -> V_94 ) ;
V_214 = V_220 -> V_365 * sizeof( * V_220 -> V_356 ) +
V_370 * sizeof( * V_220 -> V_335 ) +
V_220 -> V_344 * sizeof( * V_220 -> V_345 ) +
V_220 -> V_94 * sizeof( * V_220 -> V_345 ) +
V_369 * sizeof( long ) +
V_220 -> V_93 * sizeof( * V_220 -> V_96 ) +
V_220 -> V_94 * sizeof( * V_220 -> V_96 ) ;
V_220 -> V_356 = F_125 ( V_214 ) ;
if ( ! V_220 -> V_356 )
return - V_61 ;
V_220 -> V_335 = (union V_334 * ) & V_220 -> V_356 [ V_220 -> V_365 ] ;
V_220 -> V_345 = (struct V_371 * ) & V_220 -> V_335 [ V_370 ] ;
V_220 -> V_343 = ( unsigned long * ) & V_220 -> V_345 [ V_220 -> V_344 + V_220 -> V_94 ] ;
V_220 -> V_96 = (struct V_84 * ) & V_220 -> V_343 [ V_369 ] ;
F_222 ( & V_220 -> V_341 ) ;
F_222 ( & V_220 -> V_332 ) ;
V_220 -> V_347 = 0 ;
V_220 -> V_349 = 0 ;
V_220 -> V_333 = NULL ;
V_220 -> V_338 = 0 ;
F_223 ( & V_220 -> V_368 , 0 ) ;
F_223 ( & V_220 -> V_367 , 0 ) ;
if ( V_370 ) {
while ( -- V_370 )
V_220 -> V_335 [ V_370 - 1 ] . V_337 = & V_220 -> V_335 [ V_370 ] ;
V_220 -> V_333 = V_220 -> V_335 ;
}
F_114 ( V_220 -> V_343 , V_220 -> V_344 + V_220 -> V_94 ) ;
if ( ! V_220 -> V_346 &&
( F_224 ( V_13 -> V_223 . V_233 ) <= V_372 ) )
F_202 ( 0 , V_220 -> V_343 ) ;
return 0 ;
}
int F_225 ( const struct V_1 * V_2 , unsigned int V_340 ,
T_11 V_373 , T_12 V_374 , T_12 V_246 ,
unsigned int V_375 )
{
unsigned int V_350 ;
struct V_238 * V_239 ;
struct V_12 * V_13 ;
struct V_376 * V_353 ;
int V_54 ;
V_239 = F_130 ( sizeof( * V_353 ) , V_195 ) ;
if ( ! V_239 )
return - V_61 ;
V_13 = F_226 ( V_2 ) ;
V_353 = (struct V_376 * ) F_133 ( V_239 , sizeof( * V_353 ) ) ;
F_210 ( V_353 , 0 ) ;
F_211 ( V_353 ) = F_134 ( F_212 ( V_377 , V_340 ) ) ;
V_353 -> V_378 = V_374 ;
V_353 -> V_379 = F_155 ( 0 ) ;
V_353 -> V_380 = V_373 ;
V_353 -> V_381 = F_134 ( 0 ) ;
V_350 = F_98 ( & V_13 -> V_16 , V_375 ) ;
V_353 -> V_382 = F_227 ( F_228 ( V_350 ) ) ;
V_353 -> V_383 = F_227 ( F_229 ( V_384 ) |
V_385 | F_230 ( V_375 ) ) ;
V_54 = F_176 ( V_13 , V_239 ) ;
return F_231 ( V_54 ) ;
}
int F_232 ( const struct V_1 * V_2 , unsigned int V_340 ,
const struct V_386 * V_373 , T_12 V_374 ,
unsigned int V_375 )
{
unsigned int V_350 ;
struct V_238 * V_239 ;
struct V_12 * V_13 ;
struct V_387 * V_353 ;
int V_54 ;
V_239 = F_130 ( sizeof( * V_353 ) , V_195 ) ;
if ( ! V_239 )
return - V_61 ;
V_13 = F_226 ( V_2 ) ;
V_353 = (struct V_387 * ) F_133 ( V_239 , sizeof( * V_353 ) ) ;
F_210 ( V_353 , 0 ) ;
F_211 ( V_353 ) = F_134 ( F_212 ( V_388 , V_340 ) ) ;
V_353 -> V_378 = V_374 ;
V_353 -> V_379 = F_155 ( 0 ) ;
V_353 -> V_389 = * ( T_4 * ) ( V_373 -> V_390 ) ;
V_353 -> V_391 = * ( T_4 * ) ( V_373 -> V_390 + 8 ) ;
V_353 -> V_392 = F_227 ( 0 ) ;
V_353 -> V_393 = F_227 ( 0 ) ;
V_350 = F_98 ( & V_13 -> V_16 , V_375 ) ;
V_353 -> V_382 = F_227 ( F_228 ( V_350 ) ) ;
V_353 -> V_383 = F_227 ( F_229 ( V_384 ) |
V_385 | F_230 ( V_375 ) ) ;
V_54 = F_176 ( V_13 , V_239 ) ;
return F_231 ( V_54 ) ;
}
int F_233 ( const struct V_1 * V_2 , unsigned int V_340 ,
unsigned int V_375 , bool V_394 )
{
struct V_238 * V_239 ;
struct V_12 * V_13 ;
struct V_395 * V_353 ;
int V_54 ;
V_13 = F_226 ( V_2 ) ;
V_239 = F_130 ( sizeof( * V_353 ) , V_195 ) ;
if ( ! V_239 )
return - V_61 ;
V_353 = (struct V_395 * ) F_133 ( V_239 , sizeof( * V_353 ) ) ;
F_210 ( V_353 , 0 ) ;
F_211 ( V_353 ) = F_134 ( F_212 ( V_396 , V_340 ) ) ;
V_353 -> V_397 = F_155 ( F_234 ( 0 ) | ( V_394 ? F_235 ( 1 ) :
F_235 ( 0 ) ) | F_236 ( V_375 ) ) ;
V_54 = F_176 ( V_13 , V_239 ) ;
return F_231 ( V_54 ) ;
}
unsigned int F_237 ( const unsigned short * V_398 , unsigned short V_66 ,
unsigned int * V_89 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_399 - 1 && V_398 [ V_19 + 1 ] <= V_66 )
++ V_19 ;
if ( V_89 )
* V_89 = V_19 ;
return V_398 [ V_19 ] ;
}
unsigned int F_238 ( const unsigned short * V_398 ,
unsigned short V_400 ,
unsigned short V_401 ,
unsigned short V_402 ,
unsigned int * V_403 )
{
unsigned short V_404 = V_400 + V_401 ;
unsigned short V_405 = V_402 - 1 ;
int V_406 , V_407 ;
for ( V_406 = 0 , V_407 = - 1 ; V_406 < V_399 ; V_406 ++ ) {
unsigned short V_408 = V_398 [ V_406 ] - V_400 ;
if ( ( V_408 & V_405 ) == 0 )
V_407 = V_406 ;
if ( V_406 + 1 < V_399 && V_398 [ V_406 + 1 ] > V_404 )
break;
}
if ( V_406 == V_399 )
V_406 -- ;
if ( V_407 >= 0 &&
V_406 - V_407 <= 1 )
V_406 = V_407 ;
if ( V_403 )
* V_403 = V_406 ;
return V_398 [ V_406 ] ;
}
unsigned int F_239 ( enum V_409 V_233 , unsigned int V_51 )
{
if ( F_224 ( V_233 ) <= V_372 )
return ( ( V_51 & 0x7f ) << 1 ) ;
else
return ( V_51 & 0x7f ) ;
}
unsigned int F_240 ( const struct V_1 * V_2 )
{
return F_99 ( V_2 ) -> V_76 ;
}
unsigned int F_241 ( const struct V_1 * V_2 , int V_410 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
T_1 V_411 , V_412 , V_413 , V_414 ;
V_411 = F_77 ( V_13 , V_415 ) ;
V_412 = F_77 ( V_13 , V_416 ) ;
if ( F_122 ( V_13 -> V_223 . V_233 ) ) {
V_413 = F_242 ( V_411 ) ;
V_414 = F_243 ( V_411 ) ;
} else {
V_413 = F_244 ( V_411 ) ;
V_414 = F_245 ( V_412 ) ;
}
return V_410 ? V_413 : V_414 ;
}
unsigned int F_246 ( const struct V_1 * V_2 )
{
return F_99 ( V_2 ) -> V_51 ;
}
unsigned int F_247 ( const struct V_1 * V_2 )
{
return F_99 ( V_2 ) -> V_31 ;
}
void F_248 ( struct V_417 * V_162 , struct V_418 * V_419 ,
struct V_418 * V_420 )
{
struct V_12 * V_13 = F_249 ( V_162 ) ;
F_250 ( & V_13 -> V_421 ) ;
F_251 ( V_13 , V_419 , V_420 ) ;
F_252 ( & V_13 -> V_421 ) ;
}
void F_253 ( struct V_1 * V_2 , unsigned int V_422 ,
const unsigned int * V_423 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
F_79 ( V_13 , V_424 , V_422 ) ;
F_79 ( V_13 , V_425 , F_254 ( V_423 [ 0 ] ) |
F_255 ( V_423 [ 1 ] ) | F_256 ( V_423 [ 2 ] ) |
F_257 ( V_423 [ 3 ] ) ) ;
}
int F_258 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
return F_259 ( V_13 , V_13 -> V_27 ) ;
}
static int F_260 ( struct V_12 * V_13 , T_6 V_115 , T_6 * V_426 , T_6 * V_427 )
{
T_1 V_50 = F_77 ( V_13 , V_428 ) + 24 * V_115 + 8 ;
T_4 V_429 ;
int V_54 ;
F_250 ( & V_13 -> V_430 ) ;
V_54 = F_261 ( V_13 , 0 , V_431 , V_50 ,
sizeof( V_429 ) , ( T_11 * ) & V_429 ,
V_432 ) ;
F_252 ( & V_13 -> V_430 ) ;
if ( ! V_54 ) {
* V_427 = ( F_55 ( V_429 ) >> 25 ) & 0xffff ;
* V_426 = ( F_55 ( V_429 ) >> 9 ) & 0xffff ;
}
return V_54 ;
}
int F_262 ( struct V_1 * V_2 , T_6 V_115 , T_6 V_426 ,
T_6 V_214 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
T_6 V_433 , V_434 ;
int V_54 ;
V_54 = F_260 ( V_13 , V_115 , & V_433 , & V_434 ) ;
if ( V_54 )
goto V_59;
if ( V_426 != V_433 ) {
T_6 V_316 ;
T_1 V_268 ;
if ( V_426 >= V_433 )
V_316 = V_426 - V_433 ;
else
V_316 = V_214 - V_433 + V_426 ;
if ( F_122 ( V_13 -> V_223 . V_233 ) )
V_268 = F_263 ( V_316 ) ;
else
V_268 = F_264 ( V_316 ) ;
F_265 () ;
F_79 ( V_13 , F_78 ( V_435 ) ,
F_266 ( V_115 ) | V_268 ) ;
}
V_59:
return V_54 ;
}
int F_267 ( struct V_1 * V_2 , T_1 V_436 , T_11 * V_437 )
{
struct V_12 * V_13 ;
T_1 V_438 , V_439 , V_440 ;
T_1 V_441 , V_442 , V_443 , V_444 , V_214 ;
T_1 V_445 , V_446 , V_447 , V_448 ;
int V_54 ;
V_13 = F_226 ( V_2 ) ;
V_438 = ( ( V_436 >> 8 ) * 32 ) + V_13 -> V_449 . V_436 . V_450 ;
V_214 = F_77 ( V_13 , V_451 ) ;
V_441 = F_268 ( V_214 ) << 20 ;
V_214 = F_77 ( V_13 , V_452 ) ;
V_442 = F_269 ( V_214 ) << 20 ;
V_214 = F_77 ( V_13 , V_453 ) ;
V_443 = F_270 ( V_214 ) << 20 ;
V_445 = V_441 ;
V_446 = V_445 + V_442 ;
V_447 = V_446 + V_443 ;
if ( V_438 < V_445 ) {
V_439 = V_431 ;
V_440 = V_438 ;
} else if ( V_438 < V_446 ) {
V_439 = V_454 ;
V_440 = V_438 - V_445 ;
} else {
if ( V_438 < V_447 ) {
V_439 = V_455 ;
V_440 = V_438 - V_446 ;
} else if ( F_271 ( V_13 -> V_223 . V_233 ) ) {
V_214 = F_77 ( V_13 , V_456 ) ;
V_444 = F_272 ( V_214 ) << 20 ;
V_448 = V_447 + V_444 ;
if ( V_438 < V_448 ) {
V_439 = V_457 ;
V_440 = V_438 - V_447 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_250 ( & V_13 -> V_430 ) ;
V_54 = F_261 ( V_13 , 0 , V_439 , V_440 , 32 , V_437 , V_432 ) ;
F_252 ( & V_13 -> V_430 ) ;
return V_54 ;
V_22:
F_11 ( V_13 -> V_30 , L_39 ,
V_436 , V_438 ) ;
return - V_65 ;
}
T_2 F_273 ( struct V_1 * V_2 )
{
T_1 V_458 , V_459 ;
struct V_12 * V_13 ;
V_13 = F_226 ( V_2 ) ;
V_459 = F_77 ( V_13 , V_460 ) ;
V_458 = F_274 ( F_77 ( V_13 , V_461 ) ) ;
return ( ( T_2 ) V_458 << 32 ) | ( T_2 ) V_459 ;
}
int F_275 ( struct V_1 * V_2 ,
unsigned int V_115 ,
enum V_462 V_463 ,
int V_464 ,
T_2 * V_465 ,
unsigned int * V_466 )
{
return F_276 ( F_226 ( V_2 ) ,
V_115 ,
( V_463 == V_467
? V_468
: V_469 ) ,
V_464 ,
V_465 ,
V_466 ) ;
}
static void F_277 ( struct V_470 * V_471 )
{
const struct V_472 * V_473 ;
const struct V_1 * V_52 = V_471 -> V_2 ;
if ( V_52 -> V_474 & V_475 )
V_52 = F_278 ( V_52 ) ;
V_473 = V_52 -> V_2 . V_473 ;
if ( V_473 && V_473 -> V_476 == & V_477 . V_476 )
F_279 ( F_280 ( V_473 ) , V_471 ) ;
}
static int F_281 ( struct V_478 * V_479 , unsigned long V_480 ,
void * V_128 )
{
switch ( V_480 ) {
case V_481 :
F_277 ( V_128 ) ;
break;
case V_482 :
default:
break;
}
return 0 ;
}
static void F_282 ( struct V_12 * V_13 , int V_483 )
{
T_1 V_411 , V_412 , V_413 , V_414 ;
do {
V_411 = F_77 ( V_13 , V_415 ) ;
V_412 = F_77 ( V_13 , V_416 ) ;
if ( F_122 ( V_13 -> V_223 . V_233 ) ) {
V_413 = F_242 ( V_411 ) ;
V_414 = F_243 ( V_411 ) ;
} else {
V_413 = F_244 ( V_411 ) ;
V_414 = F_245 ( V_412 ) ;
}
if ( V_413 == 0 && V_414 == 0 )
break;
F_283 ( V_484 ) ;
F_284 ( F_285 ( V_483 ) ) ;
} while ( 1 );
}
static void F_286 ( struct V_117 * V_25 )
{
unsigned long V_68 ;
F_287 ( & V_25 -> V_485 , V_68 ) ;
V_25 -> V_486 = 1 ;
F_288 ( & V_25 -> V_485 , V_68 ) ;
}
static void F_289 ( struct V_12 * V_13 , struct V_117 * V_25 )
{
F_290 ( & V_25 -> V_485 ) ;
if ( V_25 -> V_487 ) {
F_265 () ;
F_79 ( V_13 , F_78 ( V_435 ) ,
F_266 ( V_25 -> V_26 ) | F_263 ( V_25 -> V_487 ) ) ;
V_25 -> V_487 = 0 ;
}
V_25 -> V_486 = 0 ;
F_291 ( & V_25 -> V_485 ) ;
}
static void F_292 ( struct V_12 * V_13 )
{
int V_19 ;
F_89 (&adap->sge, i)
F_286 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_83 (&adap->sge, i)
F_286 ( & V_13 -> V_16 . V_121 [ V_19 ] . V_25 ) ;
F_82 (adap, i)
F_286 ( & V_13 -> V_16 . V_232 [ V_19 ] . V_25 ) ;
}
static void F_293 ( struct V_12 * V_13 )
{
int V_19 ;
F_89 (&adap->sge, i)
F_289 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_83 (&adap->sge, i)
F_289 ( V_13 , & V_13 -> V_16 . V_121 [ V_19 ] . V_25 ) ;
F_82 (adap, i)
F_289 ( V_13 , & V_13 -> V_16 . V_232 [ V_19 ] . V_25 ) ;
}
static void F_294 ( struct V_12 * V_13 , enum V_488 V_129 )
{
if ( V_13 -> V_153 [ V_489 ] )
V_145 [ V_489 ] . F_295 ( V_13 -> V_153 [ V_489 ] ,
V_129 ) ;
}
static void F_296 ( struct V_363 * V_364 )
{
struct V_12 * V_13 ;
V_13 = F_60 ( V_364 , struct V_12 , V_490 ) ;
F_282 ( V_13 , V_491 ) ;
F_293 ( V_13 ) ;
F_294 ( V_13 , V_492 ) ;
if ( F_224 ( V_13 -> V_223 . V_233 ) <= V_372 )
F_297 ( V_13 , V_493 ,
V_494 | V_495 ,
V_494 | V_495 ) ;
else
F_297 ( V_13 , V_493 ,
V_495 , V_495 ) ;
}
static void F_298 ( struct V_12 * V_13 , struct V_117 * V_25 )
{
T_6 V_433 , V_434 ;
int V_54 ;
F_290 ( & V_25 -> V_485 ) ;
V_54 = F_260 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_433 , & V_434 ) ;
if ( V_54 )
goto V_59;
if ( V_25 -> V_496 != V_433 ) {
T_6 V_316 ;
T_1 V_268 ;
if ( V_25 -> V_496 >= V_433 )
V_316 = V_25 -> V_496 - V_433 ;
else
V_316 = V_25 -> V_214 - V_433 + V_25 -> V_496 ;
if ( F_122 ( V_13 -> V_223 . V_233 ) )
V_268 = F_263 ( V_316 ) ;
else
V_268 = F_264 ( V_316 ) ;
F_265 () ;
F_79 ( V_13 , F_78 ( V_435 ) ,
F_266 ( V_25 -> V_26 ) | V_268 ) ;
}
V_59:
V_25 -> V_486 = 0 ;
V_25 -> V_487 = 0 ;
F_291 ( & V_25 -> V_485 ) ;
if ( V_54 )
F_299 ( V_13 , L_40 ) ;
}
static void F_300 ( struct V_12 * V_13 )
{
int V_19 ;
F_89 (&adap->sge, i)
F_298 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_83 (&adap->sge, i)
F_298 ( V_13 , & V_13 -> V_16 . V_121 [ V_19 ] . V_25 ) ;
F_82 (adap, i)
F_298 ( V_13 , & V_13 -> V_16 . V_232 [ V_19 ] . V_25 ) ;
}
static void F_301 ( struct V_363 * V_364 )
{
struct V_12 * V_13 ;
V_13 = F_60 ( V_364 , struct V_12 , V_497 ) ;
if ( F_122 ( V_13 -> V_223 . V_233 ) ) {
F_282 ( V_13 , V_491 ) ;
F_294 ( V_13 , V_498 ) ;
F_282 ( V_13 , V_491 ) ;
F_300 ( V_13 ) ;
F_282 ( V_13 , V_491 ) ;
F_293 ( V_13 ) ;
F_294 ( V_13 , V_492 ) ;
} else if ( F_271 ( V_13 -> V_223 . V_233 ) ) {
T_1 V_499 = F_77 ( V_13 , 0x010ac ) ;
T_6 V_115 = ( V_499 >> 15 ) & 0x1ffff ;
T_6 V_500 = V_499 & 0x1fff ;
T_2 V_501 ;
unsigned int V_502 ;
int V_54 ;
V_54 = F_276 ( V_13 , V_115 , V_468 ,
0 , & V_501 , & V_502 ) ;
if ( V_54 )
F_11 ( V_13 -> V_30 , L_41
L_42 , V_115 , V_500 ) ;
else
F_302 ( F_264 ( V_500 ) | F_266 ( V_502 ) ,
V_13 -> V_503 + V_501 + V_504 ) ;
F_297 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_224 ( V_13 -> V_223 . V_233 ) <= V_372 )
F_297 ( V_13 , V_505 , V_506 , 0 ) ;
}
void F_303 ( struct V_12 * V_13 )
{
if ( F_122 ( V_13 -> V_223 . V_233 ) ) {
F_292 ( V_13 ) ;
F_294 ( V_13 , V_507 ) ;
F_297 ( V_13 , V_493 ,
V_494 | V_495 , 0 ) ;
F_214 ( V_13 -> V_361 , & V_13 -> V_490 ) ;
}
}
void F_304 ( struct V_12 * V_13 )
{
if ( F_122 ( V_13 -> V_223 . V_233 ) ) {
F_292 ( V_13 ) ;
F_294 ( V_13 , V_507 ) ;
}
F_214 ( V_13 -> V_361 , & V_13 -> V_497 ) ;
}
static void F_305 ( struct V_12 * V_13 , unsigned int V_146 )
{
void * V_508 ;
struct V_509 V_510 ;
unsigned short V_19 ;
V_510 . V_162 = V_13 -> V_162 ;
V_510 . V_28 = V_13 -> V_28 ;
V_510 . V_86 = V_13 -> V_86 ;
V_510 . V_91 = & V_13 -> V_91 ;
V_510 . V_511 = V_13 -> V_39 ;
V_510 . V_512 = & V_13 -> V_449 ;
V_510 . V_398 = V_13 -> V_223 . V_398 ;
if ( V_146 == V_489 ) {
V_510 . V_513 = V_13 -> V_16 . V_229 ;
V_510 . V_514 = V_13 -> V_16 . V_231 ;
V_510 . V_515 = V_13 -> V_16 . V_228 ;
V_510 . V_516 = V_13 -> V_16 . V_230 ;
} else if ( V_146 == V_517 ) {
V_510 . V_513 = V_13 -> V_16 . V_225 ;
V_510 . V_515 = V_13 -> V_16 . V_222 ;
} else if ( V_146 == V_518 ) {
V_510 . V_513 = V_13 -> V_16 . V_227 ;
V_510 . V_515 = V_13 -> V_16 . V_226 ;
}
V_510 . V_519 = V_13 -> V_16 . V_222 ;
V_510 . V_520 = V_13 -> V_223 . V_224 ;
V_510 . V_224 = V_13 -> V_223 . V_224 ;
V_510 . V_521 = V_13 -> V_223 . V_522 ;
V_510 . V_523 = V_13 -> V_223 . V_233 ;
V_510 . V_524 = F_306 ( F_77 ( V_13 , V_525 ) ) ;
V_510 . V_526 = F_77 ( V_13 , V_424 ) ;
V_510 . V_527 = F_77 ( V_13 , V_425 ) ;
V_510 . V_528 = F_77 ( V_13 , V_529 ) ;
V_510 . V_530 = & V_13 -> V_530 ;
V_510 . V_531 = 1000000000 / V_13 -> V_223 . V_532 . V_533 ;
V_510 . V_534 = 1 << V_13 -> V_223 . V_16 . V_535 ;
V_510 . V_536 = 1 << V_13 -> V_223 . V_16 . V_537 ;
V_510 . V_538 = V_13 -> V_223 . V_539 . V_540 ;
for ( V_19 = 0 ; V_19 < V_541 ; V_19 ++ )
V_510 . V_542 [ V_19 ] = V_19 ;
V_510 . V_543 = V_13 -> V_544 + F_78 ( V_207 ) ;
V_510 . V_545 = V_13 -> V_544 + F_78 ( V_435 ) ;
V_510 . V_546 = V_13 -> V_223 . V_546 ;
V_510 . V_547 = V_547 ;
V_510 . V_548 = V_13 -> V_16 . V_549 ;
V_510 . V_550 = V_13 -> V_16 . V_551 ;
V_510 . V_552 = V_13 -> V_16 . V_553 ;
V_510 . V_554 = V_13 -> V_68 & V_555 ;
V_510 . V_556 = V_13 -> V_223 . V_556 ;
V_510 . V_557 = V_13 -> V_223 . V_557 ;
V_510 . V_558 = V_13 -> V_223 . V_558 ;
V_510 . V_559 = F_307 ( V_13 -> V_30 ) ;
V_508 = V_145 [ V_146 ] . F_308 ( & V_510 ) ;
if ( F_309 ( V_508 ) ) {
F_310 ( V_13 -> V_30 ,
L_43 ,
V_560 [ V_146 ] , F_311 ( V_508 ) ) ;
return;
}
V_13 -> V_153 [ V_146 ] = V_508 ;
if ( ! V_561 ) {
F_312 ( & V_562 ) ;
V_561 = true ;
}
if ( V_13 -> V_68 & V_206 )
V_145 [ V_146 ] . F_313 ( V_508 , V_563 ) ;
}
static void F_314 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_250 ( & V_564 ) ;
F_315 ( & V_13 -> V_565 , & V_566 ) ;
F_252 ( & V_564 ) ;
F_316 ( & V_567 ) ;
F_29 ( & V_13 -> V_568 , & V_569 ) ;
for ( V_19 = 0 ; V_19 < V_570 ; V_19 ++ )
if ( V_145 [ V_19 ] . F_308 )
F_305 ( V_13 , V_19 ) ;
F_317 ( & V_567 ) ;
}
static void F_318 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_316 ( & V_567 ) ;
F_33 ( & V_13 -> V_568 ) ;
for ( V_19 = 0 ; V_19 < V_570 ; V_19 ++ )
if ( V_13 -> V_153 [ V_19 ] ) {
V_145 [ V_19 ] . F_313 ( V_13 -> V_153 [ V_19 ] ,
V_571 ) ;
V_13 -> V_153 [ V_19 ] = NULL ;
}
if ( V_561 && F_319 ( & V_569 ) ) {
F_320 ( & V_562 ) ;
V_561 = false ;
}
F_317 ( & V_567 ) ;
F_250 ( & V_564 ) ;
F_321 ( & V_13 -> V_565 ) ;
F_252 ( & V_564 ) ;
}
static void F_322 ( struct V_12 * V_13 , enum V_572 V_573 )
{
unsigned int V_19 ;
F_316 ( & V_567 ) ;
for ( V_19 = 0 ; V_19 < V_570 ; V_19 ++ )
if ( V_13 -> V_153 [ V_19 ] )
V_145 [ V_19 ] . F_313 ( V_13 -> V_153 [ V_19 ] , V_573 ) ;
F_317 ( & V_567 ) ;
}
int F_323 ( enum V_574 type , const struct V_575 * V_6 )
{
int V_54 = 0 ;
struct V_12 * V_13 ;
if ( type >= V_570 )
return - V_65 ;
F_316 ( & V_567 ) ;
if ( V_145 [ type ] . F_308 ) {
V_54 = - V_576 ;
goto V_59;
}
V_145 [ type ] = * V_6 ;
F_22 (adap, &adapter_list, list_node)
F_305 ( V_13 , type ) ;
V_59: F_317 ( & V_567 ) ;
return V_54 ;
}
int F_324 ( enum V_574 type )
{
struct V_12 * V_13 ;
if ( type >= V_570 )
return - V_65 ;
F_316 ( & V_567 ) ;
F_22 (adap, &adapter_list, list_node)
V_13 -> V_153 [ type ] = NULL ;
V_145 [ type ] . F_308 = NULL ;
F_317 ( & V_567 ) ;
return 0 ;
}
static int F_325 ( struct V_478 * V_577 ,
unsigned long V_480 , void * V_128 )
{
struct V_578 * V_579 = V_128 ;
struct V_1 * V_580 = V_579 -> V_581 -> V_2 ;
const struct V_472 * V_473 = NULL ;
#if F_326 ( V_582 )
struct V_12 * V_13 ;
#endif
if ( V_580 -> V_474 & V_475 )
V_580 = F_278 ( V_580 ) ;
#if F_326 ( V_582 )
if ( V_580 -> V_68 & V_583 ) {
F_22 (adap, &adapter_list, list_node) {
switch ( V_480 ) {
case V_584 :
F_327 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_579 , 1 ) ;
break;
case V_585 :
F_328 ( V_13 -> V_39 [ 0 ] ,
( const T_1 * ) V_579 , 1 ) ;
break;
default:
break;
}
}
return V_586 ;
}
#endif
if ( V_580 )
V_473 = V_580 -> V_2 . V_473 ;
if ( V_473 && V_473 -> V_476 == & V_477 . V_476 ) {
switch ( V_480 ) {
case V_584 :
F_327 ( V_580 , ( const T_1 * ) V_579 , 1 ) ;
break;
case V_585 :
F_328 ( V_580 , ( const T_1 * ) V_579 , 1 ) ;
break;
default:
break;
}
}
return V_586 ;
}
static void F_329 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_54 ;
F_330 () ;
for ( V_19 = 0 ; V_19 < V_587 ; V_19 ++ ) {
V_2 = V_13 -> V_39 [ V_19 ] ;
V_54 = 0 ;
if ( V_2 )
V_54 = F_331 ( V_2 ) ;
if ( V_54 < 0 )
break;
}
F_332 () ;
}
static int F_333 ( struct V_12 * V_13 )
{
int V_22 ;
V_22 = F_113 ( V_13 ) ;
if ( V_22 )
goto V_59;
V_22 = F_96 ( V_13 ) ;
if ( V_22 )
goto V_588;
if ( V_13 -> V_68 & V_161 ) {
F_81 ( V_13 ) ;
V_22 = F_88 ( V_13 -> V_174 [ 0 ] . V_46 , F_76 , 0 ,
V_13 -> V_174 [ 0 ] . V_175 , V_13 ) ;
if ( V_22 )
goto V_589;
V_22 = F_87 ( V_13 ) ;
if ( V_22 ) {
F_90 ( V_13 -> V_174 [ 0 ] . V_46 , V_13 ) ;
goto V_589;
}
} else {
V_22 = F_88 ( V_13 -> V_162 -> V_164 , F_334 ( V_13 ) ,
( V_13 -> V_68 & V_163 ) ? 0 : V_590 ,
V_13 -> V_39 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_589;
}
F_106 ( V_13 ) ;
F_335 ( V_13 ) ;
F_336 ( V_13 ) ;
V_13 -> V_68 |= V_206 ;
F_322 ( V_13 , V_563 ) ;
#if F_326 ( V_591 )
F_329 ( V_13 ) ;
#endif
F_337 ( & V_13 -> V_63 ) ;
V_59:
return V_22 ;
V_589:
F_11 ( V_13 -> V_30 , L_44 , V_22 ) ;
V_588:
F_115 ( V_13 ) ;
goto V_59;
}
static void F_338 ( struct V_12 * V_12 )
{
F_339 ( & V_12 -> V_362 ) ;
F_339 ( & V_12 -> V_490 ) ;
F_339 ( & V_12 -> V_497 ) ;
V_12 -> V_360 = false ;
V_12 -> V_358 = NULL ;
F_340 ( V_12 ) ;
F_115 ( V_12 ) ;
V_12 -> V_68 &= ~ V_206 ;
}
static int F_341 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_18 ( V_2 ) ;
if ( ! ( V_12 -> V_68 & V_206 ) ) {
V_22 = F_333 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_40 ( V_2 ) ;
if ( ! V_22 )
F_342 ( V_2 ) ;
return V_22 ;
}
static int F_343 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_344 ( V_2 ) ;
F_18 ( V_2 ) ;
return F_345 ( V_12 , V_12 -> V_28 , V_11 -> V_51 , false , false ) ;
}
static int F_346 ( struct V_84 * V_85 )
{
if ( V_85 -> V_592 )
return - V_593 ;
if ( V_85 -> V_102 )
return - V_576 ;
return 0 ;
}
static int F_347 ( struct V_12 * V_12 , unsigned int V_237 )
{
struct V_84 * V_85 ;
int V_54 ;
if ( V_237 >= V_12 -> V_91 . V_93 + V_12 -> V_91 . V_94 )
return - V_65 ;
V_85 = & V_12 -> V_91 . V_96 [ V_237 ] ;
V_54 = F_346 ( V_85 ) ;
if ( V_54 )
return V_54 ;
if ( V_85 -> V_103 )
return F_174 ( V_12 , V_237 ) ;
return 0 ;
}
int F_348 ( const struct V_1 * V_2 , unsigned int V_340 ,
T_11 V_373 , T_12 V_374 , T_12 V_246 ,
unsigned int V_375 , unsigned char V_39 , unsigned char V_270 )
{
int V_54 ;
struct V_84 * V_85 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_268 ;
V_13 = F_226 ( V_2 ) ;
V_340 -= V_13 -> V_91 . V_348 ;
V_340 += V_13 -> V_91 . V_93 ;
V_85 = & V_13 -> V_91 . V_96 [ V_340 ] ;
V_54 = F_346 ( V_85 ) ;
if ( V_54 )
return V_54 ;
if ( V_85 -> V_103 )
F_50 ( V_13 , V_85 ) ;
memset ( & V_85 -> V_243 , 0 , sizeof( struct V_594 ) ) ;
V_85 -> V_243 . V_268 . V_297 = F_349 ( V_374 ) ;
V_85 -> V_243 . V_270 . V_297 = ~ 0 ;
V_268 = ( T_3 * ) & V_373 ;
if ( ( V_268 [ 0 ] | V_268 [ 1 ] | V_268 [ 2 ] | V_268 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_85 -> V_243 . V_268 . V_292 [ V_19 ] = V_268 [ V_19 ] ;
V_85 -> V_243 . V_270 . V_292 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_223 . V_539 . V_540 & V_595 ) {
V_85 -> V_243 . V_268 . V_280 = V_39 ;
V_85 -> V_243 . V_270 . V_280 = V_270 ;
}
}
if ( V_13 -> V_223 . V_539 . V_540 & V_596 ) {
V_85 -> V_243 . V_268 . V_283 = V_597 ;
V_85 -> V_243 . V_270 . V_283 = ~ 0 ;
}
V_85 -> V_243 . V_257 = 1 ;
V_85 -> V_243 . V_253 = V_375 ;
V_85 -> V_592 = 1 ;
V_85 -> V_243 . V_255 = 1 ;
V_54 = F_129 ( V_13 , V_340 ) ;
if ( V_54 ) {
F_50 ( V_13 , V_85 ) ;
return V_54 ;
}
return 0 ;
}
int F_350 ( const struct V_1 * V_2 , unsigned int V_340 ,
unsigned int V_375 , bool V_394 )
{
int V_54 ;
struct V_84 * V_85 ;
struct V_12 * V_13 ;
V_13 = F_226 ( V_2 ) ;
V_340 -= V_13 -> V_91 . V_348 ;
V_340 += V_13 -> V_91 . V_93 ;
V_85 = & V_13 -> V_91 . V_96 [ V_340 ] ;
V_85 -> V_592 = 0 ;
V_54 = F_347 ( V_13 , V_340 ) ;
if ( V_54 )
return V_54 ;
return 0 ;
}
static struct V_598 * F_351 ( struct V_1 * V_2 ,
struct V_598 * V_599 )
{
struct V_600 V_155 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_250 ( & V_12 -> V_421 ) ;
if ( ! F_352 ( V_2 ) ) {
F_252 ( & V_12 -> V_421 ) ;
return V_599 ;
}
F_353 ( V_12 , V_6 -> V_76 , & V_155 ,
& V_6 -> V_601 ) ;
F_252 ( & V_12 -> V_421 ) ;
V_599 -> V_602 = V_155 . V_603 ;
V_599 -> V_604 = V_155 . V_605 ;
V_599 -> V_606 = V_155 . V_607 ;
V_599 -> V_608 = V_155 . V_609 ;
V_599 -> V_610 = V_155 . V_611 ;
V_599 -> V_612 = V_155 . V_613 + V_155 . V_614 +
V_155 . V_615 ;
V_599 -> V_616 = 0 ;
V_599 -> V_617 = V_155 . V_618 ;
V_599 -> V_619 = V_155 . V_620 ;
V_599 -> V_621 = V_155 . V_622 + V_155 . V_623 +
V_155 . V_624 + V_155 . V_625 +
V_155 . V_626 + V_155 . V_627 +
V_155 . V_628 + V_155 . V_629 ;
V_599 -> V_630 = 0 ;
V_599 -> V_631 = 0 ;
V_599 -> V_632 = 0 ;
V_599 -> V_633 = 0 ;
V_599 -> V_634 = 0 ;
V_599 -> V_635 = 0 ;
V_599 -> V_636 = V_155 . V_637 ;
V_599 -> V_638 = V_155 . V_620 + V_155 . V_618 +
V_599 -> V_612 + V_155 . V_639 + V_599 -> V_621 ;
return V_599 ;
}
static int F_354 ( struct V_1 * V_2 , struct V_640 * V_353 , int V_129 )
{
unsigned int V_27 ;
int V_54 = 0 , V_641 , V_642 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_643 * V_128 = (struct V_643 * ) & V_353 -> V_644 ;
switch ( V_129 ) {
case V_645 :
if ( V_11 -> V_646 < 0 )
return - V_647 ;
V_128 -> V_648 = V_11 -> V_646 ;
break;
case V_649 :
case V_650 :
if ( F_355 ( V_128 -> V_648 ) ) {
V_641 = F_356 ( V_128 -> V_648 ) ;
V_642 = F_357 ( V_128 -> V_648 ) ;
} else if ( V_128 -> V_648 < 32 ) {
V_641 = V_128 -> V_648 ;
V_642 = 0 ;
V_128 -> V_651 &= 0x1f ;
} else
return - V_65 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_129 == V_649 )
V_54 = F_358 ( V_11 -> V_12 , V_27 , V_641 , V_642 ,
V_128 -> V_651 , & V_128 -> V_652 ) ;
else
V_54 = F_359 ( V_11 -> V_12 , V_27 , V_641 , V_642 ,
V_128 -> V_651 , V_128 -> V_653 ) ;
break;
case V_654 :
return F_360 ( V_353 -> V_644 , & V_11 -> V_655 ,
sizeof( V_11 -> V_655 ) ) ?
- V_656 : 0 ;
case V_657 :
if ( F_361 ( & V_11 -> V_655 , V_353 -> V_644 ,
sizeof( V_11 -> V_655 ) ) )
return - V_656 ;
switch ( V_11 -> V_655 . V_658 ) {
case V_659 :
V_11 -> V_660 = false ;
break;
case V_661 :
V_11 -> V_660 = true ;
break;
default:
V_11 -> V_655 . V_658 = V_659 ;
return - V_662 ;
}
return F_360 ( V_353 -> V_644 , & V_11 -> V_655 ,
sizeof( V_11 -> V_655 ) ) ?
- V_656 : 0 ;
default:
return - V_647 ;
}
return V_54 ;
}
static void F_362 ( struct V_1 * V_2 )
{
F_36 ( V_2 , - 1 , false ) ;
}
static int F_363 ( struct V_1 * V_2 , int V_663 )
{
int V_54 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_663 < 81 || V_663 > V_664 )
return - V_65 ;
V_54 = F_39 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 , V_663 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_54 )
V_2 -> V_66 = V_663 ;
return V_54 ;
}
static int F_364 ( struct V_1 * V_2 , void * V_6 )
{
int V_54 ;
struct V_665 * V_50 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_365 ( V_50 -> V_666 ) )
return - V_667 ;
V_54 = F_41 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_51 ,
V_11 -> V_74 , V_50 -> V_666 , true , true ) ;
if ( V_54 < 0 )
return V_54 ;
memcpy ( V_2 -> V_75 , V_50 -> V_666 , V_2 -> V_668 ) ;
V_11 -> V_74 = V_54 ;
return 0 ;
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_68 & V_161 ) {
int V_19 ;
struct V_193 * V_669 = & V_13 -> V_16 . V_185 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_669 ++ )
V_183 ( 0 , & V_669 -> V_151 ) ;
} else
F_334 ( V_13 ) ( 0 , V_13 ) ;
}
void F_367 ( struct V_12 * V_13 )
{
F_297 ( V_13 , V_670 , V_671 , 0 ) ;
F_105 ( V_13 ) ;
F_368 ( V_13 -> V_30 , L_45 ) ;
}
static void F_369 ( struct V_12 * V_13 )
{
T_1 V_672 = F_370 ( V_13 ) ;
F_371 ( V_13 , V_672 , V_673 ) ;
}
static void F_372 ( struct V_12 * V_13 )
{
if ( V_13 -> V_449 . V_674 . V_214 ) {
T_1 V_450 ;
unsigned int V_675 ;
V_450 = F_373 ( V_13 , V_676 ) ;
V_450 &= V_677 ;
V_450 += F_374 ( V_13 -> V_162 , & V_13 -> V_449 ) ;
V_675 = F_375 ( V_13 -> V_449 . V_674 . V_214 ) >> 10 ;
F_79 ( V_13 ,
F_376 ( V_678 , 3 ) ,
V_450 | F_377 ( 1 ) | F_378 ( F_379 ( V_675 ) ) ) ;
F_79 ( V_13 ,
F_376 ( V_679 , 3 ) ,
V_13 -> V_449 . V_674 . V_450 ) ;
F_77 ( V_13 ,
F_376 ( V_679 , 3 ) ) ;
}
}
static int F_380 ( struct V_12 * V_13 , struct V_680 * V_681 )
{
T_1 V_165 ;
int V_54 ;
memset ( V_681 , 0 , sizeof( * V_681 ) ) ;
V_681 -> V_682 = F_134 ( F_381 ( V_683 ) |
V_684 | V_685 ) ;
V_681 -> V_686 = F_134 ( F_382 ( * V_681 ) ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_681 , sizeof( * V_681 ) , V_681 ) ;
if ( V_54 < 0 )
return V_54 ;
V_681 -> V_682 = F_134 ( F_381 ( V_683 ) |
V_684 | V_687 ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , V_681 , sizeof( * V_681 ) , NULL ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_384 ( V_13 , V_13 -> V_28 ,
V_688 ,
V_689 |
V_690 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_385 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_216 , 64 ,
V_691 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_692 ,
V_692 ) ;
if ( V_54 < 0 )
return V_54 ;
F_386 ( V_13 ) ;
F_79 ( V_13 , V_693 , 0x64f8849 ) ;
F_79 ( V_13 , V_694 , F_254 ( V_695 - 12 ) ) ;
F_79 ( V_13 , V_696 , V_697 ) ;
V_165 = F_77 ( V_13 , V_698 ) ;
F_79 ( V_13 , V_698 , V_165 & ~ V_699 ) ;
V_13 -> V_223 . V_539 . V_700 = 0xE4 ;
F_79 ( V_13 , V_701 ,
F_387 ( V_13 -> V_223 . V_539 . V_700 ) ) ;
V_165 = 0x84218421 ;
F_388 ( V_13 , V_696 , V_698 ,
& V_165 , 1 , V_702 ) ;
F_388 ( V_13 , V_696 , V_698 ,
& V_165 , 1 , V_703 ) ;
F_388 ( V_13 , V_696 , V_698 ,
& V_165 , 1 , V_704 ) ;
#define F_389 16
if ( F_390 ( V_13 ) ) {
F_79 ( V_13 , V_705 ,
F_391 ( F_389 ) |
F_392 ( F_389 ) |
F_393 ( F_389 ) |
F_394 ( F_389 ) ) ;
F_79 ( V_13 , V_706 ,
F_391 ( F_389 ) |
F_392 ( F_389 ) |
F_393 ( F_389 ) |
F_394 ( F_389 ) ) ;
}
return F_395 ( V_13 , V_13 -> V_28 ) ;
}
static int F_396 ( struct V_12 * V_12 )
{
F_397 ( V_12 , V_707 , V_708 ) ;
if ( V_709 != 2 && V_709 != 0 ) {
F_11 ( & V_12 -> V_162 -> V_2 ,
L_46 ,
V_709 ) ;
V_709 = 2 ;
}
F_297 ( V_12 , V_670 ,
F_398 ( V_710 ) ,
F_398 ( V_709 ) ) ;
F_399 ( V_12 , V_697 ,
V_699 , 0 ) ;
return 0 ;
}
static int F_400 ( const T_3 * V_711 ,
T_8 V_712 )
{
int V_438 ;
#define F_401 ( T_13 ) (((__p)[0] << 8) | (__p)[1])
#define F_402 ( T_13 ) ((__p)[0] | ((__p)[1] << 8))
#define F_403 ( T_13 ) (le16(__p) | ((__p)[2] << 16))
V_438 = F_403 ( V_711 + 0x8 ) << 12 ;
V_438 = F_403 ( V_711 + V_438 + 0xa ) ;
return F_401 ( V_711 + V_438 + 0x27e ) ;
#undef F_401
#undef F_402
#undef F_403
}
static struct V_713 * F_404 ( int V_714 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_715 ) ; V_19 ++ ) {
if ( V_715 [ V_19 ] . V_716 == V_714 )
return & V_715 [ V_19 ] ;
}
return NULL ;
}
static int F_405 ( struct V_12 * V_13 )
{
const struct V_717 * V_718 ;
int V_54 ;
struct V_713 * V_719 ;
V_719 = F_404 ( V_13 -> V_162 -> V_472 ) ;
if ( ! V_719 ) {
F_310 ( V_13 -> V_30 ,
L_47 ) ;
return - V_647 ;
}
V_54 = F_406 ( & V_718 , V_719 -> V_720 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_48
L_49 ,
V_719 -> V_720 , - V_54 ) ;
if ( V_719 -> V_721 ) {
int V_722 = 0 ;
F_407 ( V_13 , & V_722 ) ;
F_310 ( V_13 -> V_30 , L_50
L_51 , V_722 ) ;
V_54 = 0 ;
}
return V_54 ;
}
V_54 = F_408 ( V_13 , V_673 , & V_13 -> V_430 ,
V_719 -> V_723 ,
( T_3 * ) V_718 -> V_128 , V_718 -> V_214 ) ;
if ( V_54 < 0 )
F_11 ( V_13 -> V_30 , L_52 ,
- V_54 ) ;
else if ( V_54 > 0 ) {
int V_724 = 0 ;
if ( V_719 -> V_723 )
V_724 = V_719 -> V_723 ( V_718 -> V_128 ,
V_718 -> V_214 ) ;
F_409 ( V_13 -> V_30 , L_53
L_54 ,
V_719 -> V_720 , V_724 ) ;
}
F_410 ( V_718 ) ;
return V_54 ;
}
static int F_411 ( struct V_12 * V_12 , int V_725 )
{
struct V_680 V_726 ;
const struct V_717 * V_727 ;
unsigned long V_728 = 0 , V_729 = 0 ;
T_1 V_730 , V_731 , V_732 ;
int V_54 ;
int V_733 = 0 ;
char * V_734 , V_735 [ 256 ] ;
char * V_736 = NULL ;
if ( V_725 ) {
V_54 = F_412 ( V_12 , V_12 -> V_27 ,
V_737 | V_738 ) ;
if ( V_54 < 0 )
goto V_739;
}
if ( F_413 ( V_12 -> V_162 -> V_472 ) ) {
V_54 = F_405 ( V_12 ) ;
if ( V_54 < 0 )
goto V_739;
}
switch ( F_224 ( V_12 -> V_223 . V_233 ) ) {
case V_740 :
V_734 = V_741 ;
break;
case V_372 :
V_734 = V_742 ;
break;
case V_743 :
V_734 = V_744 ;
break;
default:
F_11 ( V_12 -> V_30 , L_55 ,
V_12 -> V_162 -> V_472 ) ;
V_54 = - V_65 ;
goto V_739;
}
V_54 = F_414 ( & V_727 , V_734 , V_12 -> V_30 ) ;
if ( V_54 < 0 ) {
V_736 = L_56 ;
V_728 = V_745 ;
V_729 = F_415 ( V_12 ) ;
} else {
T_1 V_223 [ 7 ] , V_268 [ 7 ] ;
sprintf ( V_735 ,
L_57 , V_734 ) ;
V_736 = V_735 ;
if ( V_727 -> V_214 >= V_746 )
V_54 = - V_61 ;
else {
V_223 [ 0 ] = ( F_7 ( V_747 ) |
F_8 ( V_748 ) ) ;
V_54 = F_416 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_223 , V_268 ) ;
if ( V_54 == 0 ) {
T_8 V_749 = V_727 -> V_214 & 0x3 ;
T_8 V_214 = V_727 -> V_214 & ~ 0x3 ;
T_11 * V_128 = ( T_11 * ) V_727 -> V_128 ;
V_728 = F_417 ( V_268 [ 0 ] ) ;
V_729 = F_418 ( V_268 [ 0 ] ) << 16 ;
F_250 ( & V_12 -> V_430 ) ;
V_54 = F_261 ( V_12 , 0 , V_728 , V_729 ,
V_214 , V_128 , V_750 ) ;
if ( V_54 == 0 && V_749 != 0 ) {
union {
T_11 V_751 ;
char V_752 [ 4 ] ;
} V_753 ;
int V_19 ;
V_753 . V_751 = V_128 [ V_214 >> 2 ] ;
for ( V_19 = V_749 ; V_19 < 4 ; V_19 ++ )
V_753 . V_752 [ V_19 ] = 0 ;
V_54 = F_261 ( V_12 , 0 , V_728 ,
V_729 + V_214 ,
4 , & V_753 . V_751 ,
V_750 ) ;
}
F_252 ( & V_12 -> V_430 ) ;
}
}
F_410 ( V_727 ) ;
if ( V_54 )
goto V_739;
}
memset ( & V_726 , 0 , sizeof( V_726 ) ) ;
V_726 . V_682 =
F_134 ( F_381 ( V_683 ) |
V_684 |
V_685 ) ;
V_726 . V_686 =
F_134 ( V_754 |
F_419 ( V_728 ) |
F_420 ( V_729 >> 16 ) |
F_382 ( V_726 ) ) ;
V_54 = F_383 ( V_12 , V_12 -> V_27 , & V_726 , sizeof( V_726 ) ,
& V_726 ) ;
if ( V_54 == - V_755 ) {
memset ( & V_726 , 0 , sizeof( V_726 ) ) ;
V_726 . V_682 =
F_134 ( F_381 ( V_683 ) |
V_684 |
V_685 ) ;
V_726 . V_686 = F_134 ( F_382 ( V_726 ) ) ;
V_54 = F_383 ( V_12 , V_12 -> V_27 , & V_726 ,
sizeof( V_726 ) , & V_726 ) ;
V_736 = L_58 ;
}
V_733 = 1 ;
if ( V_54 < 0 )
goto V_739;
V_730 = F_48 ( V_726 . V_730 ) ;
V_731 = F_48 ( V_726 . V_731 ) ;
V_732 = F_48 ( V_726 . V_732 ) ;
if ( V_731 != V_732 )
F_310 ( V_12 -> V_30 , L_59\
L_60 ,
V_731 , V_732 ) ;
V_726 . V_682 =
F_134 ( F_381 ( V_683 ) |
V_684 |
V_687 ) ;
V_726 . V_686 = F_134 ( F_382 ( V_726 ) ) ;
V_54 = F_383 ( V_12 , V_12 -> V_27 , & V_726 , sizeof( V_726 ) ,
NULL ) ;
if ( V_54 < 0 )
goto V_739;
V_54 = F_396 ( V_12 ) ;
if ( V_54 < 0 )
goto V_739;
V_54 = F_421 ( V_12 , V_12 -> V_27 ) ;
if ( V_54 < 0 )
goto V_739;
F_409 ( V_12 -> V_30 , L_61\
L_62 ,
V_736 , V_730 , V_732 ) ;
return 0 ;
V_739:
if ( V_733 && V_54 != - V_755 )
F_310 ( V_12 -> V_30 , L_63 ,
V_736 , - V_54 ) ;
return V_54 ;
}
static struct V_756 * F_422 ( int V_233 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_757 ) ; V_19 ++ ) {
if ( V_757 [ V_19 ] . V_233 == V_233 )
return & V_757 [ V_19 ] ;
}
return NULL ;
}
static int F_423 ( struct V_12 * V_13 )
{
int V_54 ;
T_1 V_165 , V_758 ;
enum V_759 V_35 ;
T_1 V_223 [ 7 ] , V_268 [ 7 ] ;
struct V_680 V_726 ;
int V_725 = 1 ;
V_54 = F_424 ( V_13 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_425 ( V_13 , V_13 -> V_27 , V_13 -> V_27 ,
F_426 () ? V_760 : V_761 , & V_35 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_64 ,
V_54 ) ;
return V_54 ;
}
if ( V_54 == V_13 -> V_27 )
V_13 -> V_68 |= V_169 ;
F_427 ( V_13 , & V_13 -> V_223 . V_546 ) ;
F_428 ( V_13 , & V_13 -> V_223 . V_762 ) ;
F_429 ( V_13 , & V_13 -> V_223 . V_763 ) ;
F_430 ( V_13 , & V_13 -> V_223 . V_764 ) ;
V_54 = F_431 ( V_13 ) ;
if ( V_54 )
V_35 = V_765 ;
if ( ( V_13 -> V_68 & V_169 ) && V_35 != V_766 ) {
struct V_756 * V_756 ;
struct V_767 * V_768 ;
const struct V_717 * V_769 ;
const T_3 * V_770 = NULL ;
unsigned int V_771 = 0 ;
V_756 = F_422 ( F_224 ( V_13 -> V_223 . V_233 ) ) ;
if ( V_756 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_65 ,
F_224 ( V_13 -> V_223 . V_233 ) ) ;
return - V_65 ;
}
V_768 = F_125 ( sizeof( * V_768 ) ) ;
V_54 = F_414 ( & V_769 , V_756 -> V_772 ,
V_13 -> V_30 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_66 ,
V_756 -> V_772 , V_54 ) ;
} else {
V_770 = V_769 -> V_128 ;
V_771 = V_769 -> V_214 ;
}
V_54 = F_432 ( V_13 , V_756 , V_770 , V_771 , V_768 ,
V_35 , & V_725 ) ;
F_410 ( V_769 ) ;
F_127 ( V_768 ) ;
if ( V_54 < 0 )
goto V_739;
}
V_54 = F_433 ( V_13 , & V_13 -> V_223 . V_532 ) ;
if ( V_54 < 0 )
goto V_739;
V_165 =
F_7 ( V_747 ) |
F_8 ( V_773 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_165 , & V_758 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_223 . V_224 = F_434 ( V_758 ) ;
V_13 -> V_223 . V_774 = V_758 ;
if ( V_35 == V_766 ) {
F_409 ( V_13 -> V_30 , L_67\
L_68 ,
V_13 -> V_68 & V_169 ? L_69 : L_70 ) ;
} else {
F_409 ( V_13 -> V_30 , L_71\
L_72 ) ;
V_223 [ 0 ] = ( F_7 ( V_747 ) |
F_8 ( V_748 ) ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_223 , V_268 ) ;
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_73
L_74 ) ;
goto V_739;
}
V_54 = F_411 ( V_13 , V_725 ) ;
if ( V_54 == - V_755 ) {
F_11 ( V_13 -> V_30 , L_75
L_76 ) ;
goto V_739;
}
if ( V_54 < 0 ) {
F_11 ( V_13 -> V_30 , L_77
L_78 , - V_54 ) ;
goto V_739;
}
}
V_54 = F_386 ( V_13 ) ;
if ( V_54 < 0 )
goto V_739;
if ( F_435 ( V_13 -> V_162 -> V_472 ) )
V_13 -> V_223 . V_775 = 1 ;
#define F_436 ( T_14 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_437 ( T_14 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_223 [ 0 ] = F_437 ( V_776 ) ;
V_223 [ 1 ] = F_437 ( V_777 ) ;
V_223 [ 2 ] = F_437 ( V_778 ) ;
V_223 [ 3 ] = F_437 ( V_779 ) ;
V_223 [ 4 ] = F_437 ( V_780 ) ;
V_223 [ 5 ] = F_437 ( V_781 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_223 , V_268 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_16 . V_119 = V_268 [ 0 ] ;
V_13 -> V_782 = V_268 [ 1 ] ;
V_13 -> V_783 = V_268 [ 2 ] ;
V_13 -> V_91 . V_92 = V_268 [ 3 ] ;
V_13 -> V_91 . V_93 = V_268 [ 4 ] - V_268 [ 3 ] + 1 ;
V_13 -> V_16 . V_202 = V_268 [ 5 ] ;
V_223 [ 0 ] = F_437 ( V_784 ) ;
V_223 [ 1 ] = F_437 ( V_785 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_223 , V_268 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_16 . V_216 = V_268 [ 0 ] - V_13 -> V_16 . V_119 + 1 ;
V_13 -> V_16 . V_204 = V_268 [ 1 ] - V_13 -> V_16 . V_202 + 1 ;
V_13 -> V_16 . V_118 = F_438 ( V_13 -> V_16 . V_216 ,
sizeof( * V_13 -> V_16 . V_118 ) , V_195 ) ;
if ( ! V_13 -> V_16 . V_118 ) {
V_54 = - V_61 ;
goto V_739;
}
V_13 -> V_16 . V_203 = F_438 ( V_13 -> V_16 . V_204 ,
sizeof( * V_13 -> V_16 . V_203 ) , V_195 ) ;
if ( ! V_13 -> V_16 . V_203 ) {
V_54 = - V_61 ;
goto V_739;
}
V_13 -> V_16 . V_215 = F_438 ( F_221 ( V_13 -> V_16 . V_216 ) ,
sizeof( long ) , V_195 ) ;
if ( ! V_13 -> V_16 . V_215 ) {
V_54 = - V_61 ;
goto V_739;
}
V_13 -> V_16 . V_217 = F_438 ( F_221 ( V_13 -> V_16 . V_216 ) ,
sizeof( long ) , V_195 ) ;
if ( ! V_13 -> V_16 . V_217 ) {
V_54 = - V_61 ;
goto V_739;
}
#ifdef F_194
V_13 -> V_16 . V_786 = F_438 ( F_221 ( V_13 -> V_16 . V_216 ) ,
sizeof( long ) , V_195 ) ;
if ( ! V_13 -> V_16 . V_786 ) {
V_54 = - V_61 ;
goto V_739;
}
#endif
V_223 [ 0 ] = F_437 ( V_787 ) ;
V_223 [ 1 ] = F_437 ( V_788 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_223 , V_268 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_789 = V_268 [ 0 ] ;
V_13 -> V_790 = V_268 [ 1 ] ;
V_223 [ 0 ] = F_437 ( V_791 ) ;
V_223 [ 1 ] = F_437 ( V_792 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_223 , V_268 ) ;
if ( ( V_268 [ 0 ] != V_268 [ 1 ] ) && ( V_54 >= 0 ) ) {
V_13 -> V_68 |= V_555 ;
V_13 -> V_91 . V_793 = V_268 [ 0 ] ;
V_13 -> V_91 . V_794 = V_268 [ 1 ] ;
}
V_223 [ 0 ] = F_437 ( V_795 ) ;
V_268 [ 0 ] = 1 ;
( void ) F_188 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_223 , V_268 ) ;
if ( F_122 ( V_13 -> V_223 . V_233 ) ) {
V_13 -> V_223 . V_558 = false ;
} else {
V_223 [ 0 ] = F_436 ( V_796 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_223 , V_268 ) ;
V_13 -> V_223 . V_558 = ( V_54 == 0 && V_268 [ 0 ] != 0 ) ;
}
memset ( & V_726 , 0 , sizeof( V_726 ) ) ;
V_726 . V_682 = F_134 ( F_381 ( V_683 ) |
V_684 | V_685 ) ;
V_726 . V_686 = F_134 ( F_382 ( V_726 ) ) ;
V_54 = F_383 ( V_13 , V_13 -> V_27 , & V_726 , sizeof( V_726 ) ,
& V_726 ) ;
if ( V_54 < 0 )
goto V_739;
if ( V_726 . V_797 ) {
V_223 [ 0 ] = F_436 ( V_798 ) ;
V_223 [ 1 ] = F_437 ( V_799 ) ;
V_223 [ 2 ] = F_437 ( V_800 ) ;
V_223 [ 3 ] = F_437 ( V_801 ) ;
V_223 [ 4 ] = F_437 ( V_802 ) ;
V_223 [ 5 ] = F_436 ( V_803 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_223 , V_268 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_91 . V_365 = V_268 [ 0 ] ;
V_13 -> V_91 . V_370 = F_439 ( V_13 -> V_91 . V_365 / 2 , V_804 ) ;
V_13 -> V_91 . V_346 = V_268 [ 1 ] ;
V_13 -> V_91 . V_344 = V_268 [ 2 ] - V_268 [ 1 ] + 1 ;
if ( V_13 -> V_68 & V_555 && ! F_440 ( V_13 ) ) {
V_13 -> V_91 . V_348 = V_13 -> V_91 . V_92 +
F_441 ( V_13 -> V_91 . V_93 , 3 ) ;
V_13 -> V_91 . V_94 = V_13 -> V_91 . V_93 -
F_441 ( V_13 -> V_91 . V_93 , 3 ) ;
V_13 -> V_91 . V_93 = V_13 -> V_91 . V_348 -
V_13 -> V_91 . V_92 ;
}
V_13 -> V_449 . V_805 . V_450 = V_268 [ 3 ] ;
V_13 -> V_449 . V_805 . V_214 = V_268 [ 4 ] - V_268 [ 3 ] + 1 ;
V_13 -> V_223 . V_522 = V_268 [ 5 ] ;
V_13 -> V_223 . V_806 = 1 ;
}
if ( V_726 . V_807 ) {
V_223 [ 0 ] = F_437 ( V_808 ) ;
V_223 [ 1 ] = F_437 ( V_809 ) ;
V_223 [ 2 ] = F_437 ( V_810 ) ;
V_223 [ 3 ] = F_437 ( V_811 ) ;
V_223 [ 4 ] = F_437 ( V_812 ) ;
V_223 [ 5 ] = F_437 ( V_813 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_223 , V_268 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_449 . V_436 . V_450 = V_268 [ 0 ] ;
V_13 -> V_449 . V_436 . V_214 = V_268 [ 1 ] - V_268 [ 0 ] + 1 ;
V_13 -> V_449 . V_814 . V_450 = V_268 [ 2 ] ;
V_13 -> V_449 . V_814 . V_214 = V_268 [ 3 ] - V_268 [ 2 ] + 1 ;
V_13 -> V_449 . V_815 . V_450 = V_268 [ 4 ] ;
V_13 -> V_449 . V_815 . V_214 = V_268 [ 5 ] - V_268 [ 4 ] + 1 ;
V_223 [ 0 ] = F_437 ( V_816 ) ;
V_223 [ 1 ] = F_437 ( V_817 ) ;
V_223 [ 2 ] = F_437 ( V_818 ) ;
V_223 [ 3 ] = F_437 ( V_819 ) ;
V_223 [ 4 ] = F_437 ( V_820 ) ;
V_223 [ 5 ] = F_437 ( V_821 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_223 ,
V_268 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_449 . V_822 . V_450 = V_268 [ 0 ] ;
V_13 -> V_449 . V_822 . V_214 = V_268 [ 1 ] - V_268 [ 0 ] + 1 ;
V_13 -> V_449 . V_823 . V_450 = V_268 [ 2 ] ;
V_13 -> V_449 . V_823 . V_214 = V_268 [ 3 ] - V_268 [ 2 ] + 1 ;
V_13 -> V_449 . V_674 . V_450 = V_268 [ 4 ] ;
V_13 -> V_449 . V_674 . V_214 = V_268 [ 5 ] - V_268 [ 4 ] + 1 ;
V_223 [ 0 ] = F_436 ( V_824 ) ;
V_223 [ 1 ] = F_436 ( V_825 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_223 ,
V_268 ) ;
if ( V_54 < 0 ) {
V_13 -> V_223 . V_556 = 8 ;
V_13 -> V_223 . V_557 = 32 * V_13 -> V_91 . V_365 ;
V_54 = 0 ;
} else {
V_13 -> V_223 . V_556 = V_268 [ 0 ] ;
V_13 -> V_223 . V_557 = V_268 [ 1 ] ;
}
F_409 ( V_13 -> V_30 ,
L_79 ,
V_13 -> V_223 . V_556 ,
V_13 -> V_223 . V_557 ) ;
}
if ( V_726 . V_826 ) {
V_223 [ 0 ] = F_437 ( V_827 ) ;
V_223 [ 1 ] = F_437 ( V_828 ) ;
V_54 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_223 , V_268 ) ;
if ( V_54 < 0 )
goto V_739;
V_13 -> V_449 . V_829 . V_450 = V_268 [ 0 ] ;
V_13 -> V_449 . V_829 . V_214 = V_268 [ 1 ] - V_268 [ 0 ] + 1 ;
}
#undef F_437
#undef F_436
F_442 ( V_13 , V_13 -> V_223 . V_398 , NULL ) ;
if ( V_35 != V_766 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_399 ; V_19 ++ )
if ( V_13 -> V_223 . V_398 [ V_19 ] == 1492 ) {
V_13 -> V_223 . V_398 [ V_19 ] = 1488 ;
break;
}
F_443 ( V_13 , V_13 -> V_223 . V_398 , V_13 -> V_223 . V_830 ,
V_13 -> V_223 . V_831 ) ;
}
F_444 ( V_13 ) ;
V_13 -> V_68 |= V_832 ;
F_445 ( V_13 ) ;
return 0 ;
V_739:
F_34 ( V_13 -> V_16 . V_118 ) ;
F_34 ( V_13 -> V_16 . V_203 ) ;
F_34 ( V_13 -> V_16 . V_215 ) ;
F_34 ( V_13 -> V_16 . V_217 ) ;
#ifdef F_194
F_34 ( V_13 -> V_16 . V_786 ) ;
#endif
if ( V_54 != - V_833 && V_54 != - V_834 )
F_446 ( V_13 , V_13 -> V_27 ) ;
return V_54 ;
}
static T_15 F_447 ( struct V_417 * V_162 ,
T_16 V_35 )
{
int V_19 ;
struct V_12 * V_13 = F_249 ( V_162 ) ;
if ( ! V_13 )
goto V_59;
F_448 () ;
V_13 -> V_68 &= ~ V_832 ;
F_322 ( V_13 , V_835 ) ;
F_250 ( & V_13 -> V_421 ) ;
F_82 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
F_449 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_252 ( & V_13 -> V_421 ) ;
F_104 ( V_13 ) ;
if ( V_13 -> V_68 & V_206 )
F_338 ( V_13 ) ;
F_450 () ;
if ( ( V_13 -> V_68 & V_836 ) ) {
F_451 ( V_162 ) ;
V_13 -> V_68 &= ~ V_836 ;
}
V_59: return V_35 == V_837 ?
V_838 : V_839 ;
}
static T_15 F_452 ( struct V_417 * V_162 )
{
int V_19 , V_54 ;
struct V_680 V_681 ;
struct V_12 * V_13 = F_249 ( V_162 ) ;
if ( ! V_13 ) {
F_453 ( V_162 ) ;
F_454 ( V_162 ) ;
return V_840 ;
}
if ( ! ( V_13 -> V_68 & V_836 ) ) {
if ( F_455 ( V_162 ) ) {
F_11 ( & V_162 -> V_2 , L_80
L_81 ) ;
return V_838 ;
}
V_13 -> V_68 |= V_836 ;
}
F_456 ( V_162 ) ;
F_453 ( V_162 ) ;
F_454 ( V_162 ) ;
F_457 ( V_162 ) ;
if ( F_458 ( V_13 -> V_544 ) < 0 )
return V_838 ;
if ( F_425 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_760 , NULL ) < 0 )
return V_838 ;
V_13 -> V_68 |= V_832 ;
if ( F_380 ( V_13 , & V_681 ) )
return V_838 ;
F_82 (adap, i) {
struct V_5 * V_6 = F_97 ( V_13 , V_19 ) ;
V_54 = F_459 ( V_13 , V_13 -> V_27 , V_6 -> V_76 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_54 < 0 )
return V_838 ;
V_6 -> V_51 = V_54 ;
V_6 -> V_74 = - 1 ;
}
F_443 ( V_13 , V_13 -> V_223 . V_398 , V_13 -> V_223 . V_830 ,
V_13 -> V_223 . V_831 ) ;
F_369 ( V_13 ) ;
if ( F_333 ( V_13 ) )
return V_838 ;
return V_840 ;
}
static void F_460 ( struct V_417 * V_162 )
{
int V_19 ;
struct V_12 * V_13 = F_249 ( V_162 ) ;
if ( ! V_13 )
return;
F_448 () ;
F_82 (adap, i) {
struct V_1 * V_2 = V_13 -> V_39 [ V_19 ] ;
if ( F_15 ( V_2 ) ) {
F_40 ( V_2 ) ;
F_362 ( V_2 ) ;
}
F_461 ( V_2 ) ;
}
F_450 () ;
}
static inline bool F_462 ( const struct V_841 * V_842 )
{
unsigned int V_843 , V_844 ;
V_843 = F_463 ( F_464 ( V_842 -> V_845 ) ) ;
V_844 = V_843 & ~ ( V_846 | V_847 ) ;
return V_844 != 0 ;
}
static inline void F_465 ( struct V_12 * V_13 , struct V_104 * V_25 ,
unsigned int V_323 , unsigned int V_324 ,
unsigned int V_214 , unsigned int V_848 )
{
V_25 -> V_13 = V_13 ;
F_187 ( V_25 , V_323 , V_324 ) ;
V_25 -> V_849 = V_848 ;
V_25 -> V_214 = V_214 ;
}
static void F_466 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 , V_850 = 0 , V_851 = 0 ;
#ifndef F_13
int V_852 = 0 ;
#endif
int V_853 ;
if ( F_426 () )
V_13 -> V_223 . V_806 = 0 ;
F_82 (adap, i)
V_850 += F_462 ( & F_97 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_13
if ( V_13 -> V_223 . V_224 * 8 > V_854 ) {
F_11 ( V_13 -> V_30 , L_82 ,
V_854 , V_13 -> V_223 . V_224 * 8 ) ;
F_467 ( 1 ) ;
}
F_82 (adap, i) {
struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_851 ;
V_11 -> V_20 = 8 ;
V_851 += V_11 -> V_20 ;
}
#else
if ( V_850 )
V_852 = ( V_854 - ( V_13 -> V_223 . V_224 - V_850 ) ) / V_850 ;
if ( V_852 > F_468 () )
V_852 = F_468 () ;
F_82 (adap, i) {
struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_851 ;
V_11 -> V_20 = F_462 ( & V_11 -> V_7 ) ? V_852 : 1 ;
V_851 += V_11 -> V_20 ;
}
#endif
V_4 -> V_855 = V_851 ;
V_4 -> V_856 = V_851 ;
if ( F_390 ( V_13 ) ) {
if ( V_850 ) {
V_19 = F_469 ( int , F_20 ( V_4 -> V_187 ) ,
F_470 () ) ;
V_4 -> V_222 = F_471 ( V_19 , V_13 -> V_223 . V_224 ) ;
} else
V_4 -> V_222 = V_13 -> V_223 . V_224 ;
V_4 -> V_228 = V_13 -> V_223 . V_224 ;
V_4 -> V_230 = F_469 ( int , V_857 , F_470 () ) ;
V_4 -> V_230 = ( V_4 -> V_230 / V_13 -> V_223 . V_224 ) *
V_13 -> V_223 . V_224 ;
V_4 -> V_230 = F_472 ( int , V_4 -> V_230 , V_13 -> V_223 . V_224 ) ;
if ( ! F_122 ( V_13 -> V_223 . V_233 ) )
V_4 -> V_226 = V_4 -> V_222 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_185 ) ; V_19 ++ ) {
struct V_193 * V_858 = & V_4 -> V_185 [ V_19 ] ;
F_465 ( V_13 , & V_858 -> V_151 , 5 , 10 , 1024 , 64 ) ;
V_858 -> V_213 . V_214 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_214 = 1024 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_232 ) ; V_19 ++ )
V_4 -> V_232 [ V_19 ] . V_25 . V_214 = 512 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_121 ) ; V_19 ++ )
V_4 -> V_121 [ V_19 ] . V_25 . V_214 = 1024 ;
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_187 ) ; V_19 ++ ) {
struct V_149 * V_858 = & V_4 -> V_187 [ V_19 ] ;
F_465 ( V_13 , & V_858 -> V_151 , 5 , 1 , 1024 , 64 ) ;
V_858 -> V_151 . V_146 = V_517 ;
V_858 -> V_213 . V_214 = 72 ;
}
if ( ! F_122 ( V_13 -> V_223 . V_233 ) ) {
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_188 ) ; V_19 ++ ) {
struct V_149 * V_858 = & V_4 -> V_188 [ V_19 ] ;
F_465 ( V_13 , & V_858 -> V_151 , 5 , 1 , 1024 , 64 ) ;
V_858 -> V_151 . V_146 = V_518 ;
V_858 -> V_213 . V_214 = 72 ;
}
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_189 ) ; V_19 ++ ) {
struct V_149 * V_858 = & V_4 -> V_189 [ V_19 ] ;
F_465 ( V_13 , & V_858 -> V_151 , 5 , 1 , 511 , 64 ) ;
V_858 -> V_151 . V_146 = V_489 ;
V_858 -> V_213 . V_214 = 72 ;
}
V_853 = 64 + V_13 -> V_449 . V_823 . V_214 + V_13 -> V_91 . V_93 ;
if ( V_853 > V_859 ) {
F_299 ( V_13 , L_83 ) ;
V_853 = V_859 ;
}
for ( V_19 = 0 ; V_19 < F_20 ( V_4 -> V_190 ) ; V_19 ++ ) {
struct V_149 * V_858 = & V_4 -> V_190 [ V_19 ] ;
F_465 ( V_13 , & V_858 -> V_151 , 5 , 1 , V_853 , 64 ) ;
V_858 -> V_151 . V_146 = V_489 ;
}
F_465 ( V_13 , & V_4 -> V_184 , 0 , 1 , 1024 , 64 ) ;
F_465 ( V_13 , & V_4 -> V_218 , 0 , 1 , 2 * V_691 , 64 ) ;
}
static void F_473 ( struct V_12 * V_13 , int V_173 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_173 < V_13 -> V_16 . V_855 )
F_82 (adap, i) {
V_11 = F_97 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_855 -- ;
if ( V_13 -> V_16 . V_855 <= V_173 )
break;
}
}
V_173 = 0 ;
F_82 (adap, i) {
V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_173 ;
V_173 += V_11 -> V_20 ;
}
}
static int F_474 ( struct V_12 * V_13 )
{
int V_860 = 0 ;
int V_19 , V_861 , V_862 , V_863 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_520 = V_13 -> V_223 . V_224 ;
struct V_864 * V_865 ;
V_865 = F_93 ( sizeof( * V_865 ) * ( V_691 + 1 ) ,
V_195 ) ;
if ( ! V_865 )
return - V_61 ;
for ( V_19 = 0 ; V_19 < V_691 + 1 ; ++ V_19 )
V_865 [ V_19 ] . V_49 = V_19 ;
V_861 = V_4 -> V_856 + V_866 ;
if ( F_390 ( V_13 ) ) {
V_861 += V_4 -> V_228 + V_4 -> V_230 + V_4 -> V_222 +
V_4 -> V_226 ;
if ( F_122 ( V_13 -> V_223 . V_233 ) )
V_860 = 3 * V_520 ;
else
V_860 = 4 * V_520 ;
}
#ifdef F_13
V_862 = 8 * V_13 -> V_223 . V_224 + V_866 + V_860 ;
#else
V_862 = V_13 -> V_223 . V_224 + V_866 + V_860 ;
#endif
V_863 = F_475 ( V_13 -> V_162 , V_865 , V_862 , V_861 ) ;
if ( V_863 < 0 ) {
F_409 ( V_13 -> V_30 , L_84
L_85 ) ;
F_34 ( V_865 ) ;
return V_863 ;
}
V_19 = V_863 - V_866 - V_860 ;
if ( V_19 < V_4 -> V_856 ) {
V_4 -> V_856 = V_19 ;
if ( V_19 < V_4 -> V_855 )
F_473 ( V_13 , V_19 ) ;
}
if ( F_390 ( V_13 ) ) {
if ( V_863 < V_861 ) {
V_4 -> V_228 = V_520 ;
V_4 -> V_230 = V_520 ;
if ( ! F_122 ( V_13 -> V_223 . V_233 ) )
V_4 -> V_226 = V_520 ;
}
V_19 = V_863 - V_866 - V_4 -> V_856 -
V_4 -> V_228 - V_4 -> V_230 - V_4 -> V_226 ;
V_4 -> V_222 = ( V_19 / V_520 ) * V_520 ;
}
for ( V_19 = 0 ; V_19 < V_863 ; ++ V_19 )
V_13 -> V_174 [ V_19 ] . V_46 = V_865 [ V_19 ] . V_867 ;
F_409 ( V_13 -> V_30 , L_86
L_87 ,
V_863 , V_4 -> V_856 , V_4 -> V_222 , V_4 -> V_228 ,
V_4 -> V_230 ) ;
F_34 ( V_865 ) ;
return 0 ;
}
static int F_476 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_477 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_82 (adap, i) {
struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_192 = F_438 ( V_11 -> V_194 , sizeof( T_6 ) , V_195 ) ;
if ( ! V_11 -> V_192 )
return - V_61 ;
}
return 0 ;
}
static int F_478 ( struct V_12 * V_13 ,
enum V_868 * V_8 ,
enum V_869 * V_870 )
{
T_1 V_871 , V_872 ;
int V_873 , V_874 ;
#define F_479 4
* V_8 = V_875 ;
* V_870 = V_876 ;
V_873 = F_480 ( V_13 -> V_162 , V_877 ,
& V_871 ) ;
V_874 = F_480 ( V_13 -> V_162 , V_878 ,
& V_872 ) ;
if ( ! V_874 && V_872 ) {
if ( V_872 & V_879 )
* V_8 = V_880 ;
else if ( V_872 & V_881 )
* V_8 = V_882 ;
else if ( V_872 & V_883 )
* V_8 = V_884 ;
}
if ( ! V_873 ) {
* V_870 = ( V_871 & V_885 ) >> F_479 ;
if ( ! V_872 ) {
if ( V_871 & V_886 )
* V_8 = V_882 ;
else if ( V_871 & V_887 )
* V_8 = V_884 ;
}
}
if ( * V_8 == V_875 || * V_870 == V_876 )
return V_873 ? V_873 : V_874 ? V_874 : - V_65 ;
return 0 ;
}
static void F_481 ( struct V_12 * V_13 )
{
enum V_869 V_870 , V_888 ;
enum V_868 V_8 , V_889 ;
#define F_482 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_478 ( V_13 , & V_889 , & V_888 ) ) {
F_310 ( V_13 -> V_30 ,
L_88 ) ;
return;
}
if ( F_483 ( V_13 -> V_162 , & V_8 , & V_870 ) ||
V_8 == V_875 || V_870 == V_876 ) {
F_310 ( V_13 -> V_30 ,
L_89 ) ;
return;
}
F_409 ( V_13 -> V_30 , L_90 ,
F_482 ( V_8 ) , F_482 ( V_889 ) ) ;
F_409 ( V_13 -> V_30 , L_91 ,
V_870 , V_888 ) ;
if ( V_8 < V_889 || V_870 < V_888 )
F_409 ( V_13 -> V_30 ,
L_92
L_93 ) ;
}
static void F_484 ( struct V_12 * V_12 )
{
F_409 ( V_12 -> V_30 , L_94 ,
V_12 -> V_223 . V_532 . V_890 ,
F_485 ( V_12 -> V_223 . V_233 ) ) ;
F_409 ( V_12 -> V_30 , L_95 ,
V_12 -> V_223 . V_532 . V_891 , V_12 -> V_223 . V_532 . V_892 ) ;
if ( ! V_12 -> V_223 . V_546 )
F_310 ( V_12 -> V_30 , L_96 ) ;
else
F_409 ( V_12 -> V_30 , L_97 ,
F_486 ( V_12 -> V_223 . V_546 ) ,
F_487 ( V_12 -> V_223 . V_546 ) ,
F_488 ( V_12 -> V_223 . V_546 ) ,
F_489 ( V_12 -> V_223 . V_546 ) ) ;
if ( ! V_12 -> V_223 . V_762 )
F_409 ( V_12 -> V_30 , L_98 ) ;
else
F_409 ( V_12 -> V_30 , L_99 ,
F_486 ( V_12 -> V_223 . V_762 ) ,
F_487 ( V_12 -> V_223 . V_762 ) ,
F_488 ( V_12 -> V_223 . V_762 ) ,
F_489 ( V_12 -> V_223 . V_762 ) ) ;
if ( ! V_12 -> V_223 . V_763 )
F_310 ( V_12 -> V_30 , L_100 ) ;
else
F_409 ( V_12 -> V_30 ,
L_101 ,
F_486 ( V_12 -> V_223 . V_763 ) ,
F_487 ( V_12 -> V_223 . V_763 ) ,
F_488 ( V_12 -> V_223 . V_763 ) ,
F_489 ( V_12 -> V_223 . V_763 ) ) ;
if ( ! V_12 -> V_223 . V_764 )
F_409 ( V_12 -> V_30 , L_102 ) ;
else
F_409 ( V_12 -> V_30 ,
L_103 ,
F_486 ( V_12 -> V_223 . V_764 ) ,
F_487 ( V_12 -> V_223 . V_764 ) ,
F_488 ( V_12 -> V_223 . V_764 ) ,
F_489 ( V_12 -> V_223 . V_764 ) ) ;
F_409 ( V_12 -> V_30 , L_104 ,
F_390 ( V_12 ) ? L_105 : L_106 ,
( ( V_12 -> V_68 & V_161 ) ? L_107 :
( V_12 -> V_68 & V_163 ) ? L_108 : L_106 ) ,
F_390 ( V_12 ) ? L_109 : L_110 ) ;
}
static void F_490 ( const struct V_1 * V_2 )
{
char V_752 [ 80 ] ;
char * V_893 = V_752 ;
const char * V_894 = L_106 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_223 . V_895 . V_8 == V_896 )
V_894 = L_111 ;
else if ( V_13 -> V_223 . V_895 . V_8 == V_897 )
V_894 = L_112 ;
else if ( V_13 -> V_223 . V_895 . V_8 == V_898 )
V_894 = L_113 ;
if ( V_11 -> V_7 . V_845 & V_846 )
V_893 += sprintf ( V_893 , L_114 ) ;
if ( V_11 -> V_7 . V_845 & V_847 )
V_893 += sprintf ( V_893 , L_115 ) ;
if ( V_11 -> V_7 . V_845 & V_899 )
V_893 += sprintf ( V_893 , L_116 ) ;
if ( V_11 -> V_7 . V_845 & V_900 )
V_893 += sprintf ( V_893 , L_117 ) ;
if ( V_11 -> V_7 . V_845 & V_901 )
V_893 += sprintf ( V_893 , L_118 ) ;
if ( V_11 -> V_7 . V_845 & V_902 )
V_893 += sprintf ( V_893 , L_119 ) ;
if ( V_893 != V_752 )
-- V_893 ;
sprintf ( V_893 , L_120 , F_491 ( V_11 -> V_903 ) ) ;
F_3 ( V_2 , L_121 ,
V_2 -> V_9 , V_13 -> V_223 . V_532 . V_890 , V_13 -> V_9 , V_752 ) ;
}
static void F_492 ( struct V_417 * V_2 )
{
F_493 ( V_2 , V_904 , V_905 ) ;
}
static void F_494 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_127 ( V_12 -> V_86 ) ;
F_127 ( V_12 -> V_91 . V_356 ) ;
F_34 ( V_12 -> V_16 . V_118 ) ;
F_34 ( V_12 -> V_16 . V_203 ) ;
F_34 ( V_12 -> V_16 . V_215 ) ;
F_34 ( V_12 -> V_16 . V_217 ) ;
#ifdef F_194
F_34 ( V_12 -> V_16 . V_786 ) ;
#endif
F_73 ( V_12 ) ;
F_82 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] ) {
struct V_5 * V_11 = F_97 ( V_12 , V_19 ) ;
if ( V_11 -> V_51 != 0 )
F_495 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_51 ) ;
F_34 ( F_97 ( V_12 , V_19 ) -> V_192 ) ;
F_496 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_12 -> V_68 & V_832 )
F_446 ( V_12 , V_12 -> V_28 ) ;
}
static int F_497 ( struct V_417 * V_162 , T_1 V_906 )
{
T_6 V_907 ;
F_498 ( V_162 , V_908 , & V_907 ) ;
switch ( V_907 >> 12 ) {
case V_740 :
return F_499 ( V_740 , V_906 ) ;
case V_372 :
return F_499 ( V_372 , V_906 ) ;
case V_743 :
return F_499 ( V_743 , V_906 ) ;
default:
F_11 ( & V_162 -> V_2 , L_55 ,
V_907 ) ;
}
return - V_65 ;
}
static int F_500 ( struct V_417 * V_162 , int V_909 )
{
int V_22 = 0 ;
int V_910 = F_501 ( V_162 ) ;
T_1 V_911 ;
void T_17 * V_544 ;
V_544 = F_502 ( V_162 , 0 ) ;
if ( ! V_544 ) {
F_11 ( & V_162 -> V_2 , L_122 ) ;
return - V_61 ;
}
V_911 = F_503 ( V_544 + V_912 ) ;
F_504 ( V_544 ) ;
if ( ! ( V_911 & V_913 ) ||
! ( V_911 & V_914 ) ||
F_505 ( V_911 ) != 4 ) {
F_310 ( & V_162 -> V_2 ,
L_123 ) ;
return - V_647 ;
}
if ( V_910 && F_506 ( V_162 ) ) {
F_11 ( & V_162 -> V_2 ,
L_124 ) ;
V_909 = V_910 ;
return V_909 ;
}
if ( ! V_909 ) {
F_507 ( V_162 ) ;
return V_909 ;
}
if ( V_909 != V_910 ) {
V_22 = F_508 ( V_162 , V_909 ) ;
if ( V_22 )
return V_22 ;
}
return V_909 ;
}
static int F_509 ( struct V_417 * V_162 , const struct V_915 * V_916 )
{
int V_917 , V_19 , V_22 , V_918 , V_919 , V_920 ;
struct V_5 * V_11 ;
bool V_921 = false ;
struct V_12 * V_12 = NULL ;
void T_17 * V_544 ;
T_1 V_922 , V_906 ;
enum V_409 V_233 ;
F_510 ( V_923 L_125 , V_924 , V_925 ) ;
V_22 = F_511 ( V_162 , V_926 ) ;
if ( V_22 ) {
F_409 ( & V_162 -> V_2 , L_126 ) ;
return V_22 ;
}
V_22 = F_455 ( V_162 ) ;
if ( V_22 ) {
F_11 ( & V_162 -> V_2 , L_127 ) ;
goto V_927;
}
V_544 = F_502 ( V_162 , 0 ) ;
if ( ! V_544 ) {
F_11 ( & V_162 -> V_2 , L_122 ) ;
V_22 = - V_61 ;
goto V_928;
}
V_22 = F_458 ( V_544 ) ;
if ( V_22 < 0 )
goto V_929;
V_922 = F_503 ( V_544 + V_930 ) ;
V_906 = F_512 ( F_503 ( V_544 + V_931 ) ) ;
V_233 = F_497 ( V_162 , V_906 ) ;
V_917 = F_224 ( V_233 ) <= V_372 ?
F_513 ( V_922 ) : F_514 ( V_922 ) ;
if ( V_917 != V_916 -> V_932 ) {
F_504 ( V_544 ) ;
F_451 ( V_162 ) ;
F_454 ( V_162 ) ;
goto V_933;
}
if ( ! F_515 ( V_162 , F_516 ( 64 ) ) ) {
V_921 = true ;
V_22 = F_517 ( V_162 , F_516 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_162 -> V_2 , L_128
L_129 ) ;
goto V_929;
}
} else {
V_22 = F_515 ( V_162 , F_516 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_162 -> V_2 , L_130 ) ;
goto V_929;
}
}
F_518 ( V_162 ) ;
F_492 ( V_162 ) ;
F_456 ( V_162 ) ;
F_454 ( V_162 ) ;
V_12 = F_27 ( sizeof( * V_12 ) , V_195 ) ;
if ( ! V_12 ) {
V_22 = - V_61 ;
goto V_929;
}
V_12 -> V_361 = F_519 ( L_131 ) ;
if ( ! V_12 -> V_361 ) {
V_22 = - V_61 ;
goto V_934;
}
V_12 -> V_935 = F_27 ( sizeof( * V_12 -> V_935 ) +
( sizeof( struct V_936 ) *
V_937 ) ,
V_195 ) ;
if ( ! V_12 -> V_935 ) {
V_22 = - V_61 ;
goto V_934;
}
V_12 -> V_935 -> V_214 = V_937 ;
V_12 -> V_68 |= V_836 ;
V_12 -> V_544 = V_544 ;
V_12 -> V_162 = V_162 ;
V_12 -> V_30 = & V_162 -> V_2 ;
V_12 -> V_9 = F_520 ( V_162 ) ;
V_12 -> V_27 = V_917 ;
V_12 -> V_28 = V_917 ;
V_12 -> V_938 = V_939 ;
memset ( V_12 -> V_81 , 0xff , sizeof( V_12 -> V_81 ) ) ;
F_222 ( & V_12 -> V_421 ) ;
F_222 ( & V_12 -> V_357 ) ;
F_222 ( & V_12 -> V_430 ) ;
F_521 ( & V_12 -> V_362 , F_215 ) ;
F_521 ( & V_12 -> V_490 , F_296 ) ;
F_521 ( & V_12 -> V_497 , F_301 ) ;
V_22 = F_522 ( V_12 ) ;
if ( V_22 )
goto V_934;
if ( ! F_122 ( V_12 -> V_223 . V_233 ) ) {
V_918 = ( V_940 +
( V_941 - V_940 ) *
V_12 -> V_28 ) ;
V_919 = 1 << F_523 ( F_77 ( V_12 ,
V_942 ) >> V_918 ) ;
V_920 = V_707 / V_943 ;
if ( V_919 > V_920 ) {
F_11 ( & V_162 -> V_2 ,
L_132 ) ;
V_22 = - V_65 ;
goto V_934;
}
V_12 -> V_503 = F_524 ( F_525 ( V_162 , 2 ) ,
F_526 ( V_162 , 2 ) ) ;
if ( ! V_12 -> V_503 ) {
F_11 ( & V_162 -> V_2 , L_133 ) ;
V_22 = - V_61 ;
goto V_934;
}
}
F_369 ( V_12 ) ;
V_22 = F_423 ( V_12 ) ;
#ifdef F_194
F_114 ( V_12 -> V_16 . V_786 , V_12 -> V_16 . V_216 ) ;
#endif
F_372 ( V_12 ) ;
if ( V_22 )
goto V_944;
if ( ! F_122 ( V_12 -> V_223 . V_233 ) )
F_79 ( V_12 , V_945 , F_527 ( 7 ) |
( F_271 ( V_12 -> V_223 . V_233 ) ? F_528 ( 0 ) :
F_529 ( 0 ) ) ) ;
F_82 (adapter, i) {
struct V_1 * V_52 ;
V_52 = F_530 ( sizeof( struct V_5 ) ,
V_854 ) ;
if ( ! V_52 ) {
V_22 = - V_61 ;
goto V_946;
}
F_531 ( V_52 , & V_162 -> V_2 ) ;
V_12 -> V_39 [ V_19 ] = V_52 ;
V_11 = F_4 ( V_52 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_74 = - 1 ;
V_11 -> V_31 = V_19 ;
V_52 -> V_164 = V_162 -> V_164 ;
V_52 -> V_947 = V_948 | V_949 |
V_950 | V_951 |
V_952 | V_953 |
V_954 | V_73 ;
if ( V_921 )
V_52 -> V_947 |= V_955 ;
V_52 -> V_72 |= V_52 -> V_947 ;
V_52 -> V_956 = V_52 -> V_72 & V_957 ;
V_52 -> V_474 |= V_958 ;
V_52 -> V_959 = & V_960 ;
#ifdef F_13
V_52 -> V_961 = & V_962 ;
F_17 ( V_52 ) ;
#endif
F_532 ( V_52 ) ;
}
F_533 ( V_162 , V_12 ) ;
if ( V_12 -> V_68 & V_832 ) {
V_22 = F_534 ( V_12 , V_917 , V_917 , 0 ) ;
if ( V_22 )
goto V_946;
} else if ( V_12 -> V_223 . V_224 == 1 ) {
T_3 V_963 [ V_964 ] ;
T_3 * V_965 = V_12 -> V_223 . V_532 . V_965 ;
V_22 = F_535 ( V_12 , & V_12 -> V_223 . V_532 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_964 ; V_19 ++ )
V_963 [ V_19 ] = ( F_536 ( V_965 [ 2 * V_19 + 0 ] ) * 16 +
F_536 ( V_965 [ 2 * V_19 + 1 ] ) ) ;
F_537 ( V_12 , 0 , V_963 ) ;
}
}
F_466 ( V_12 ) ;
V_12 -> V_86 = F_538 ( V_12 -> V_782 , V_12 -> V_783 ) ;
if ( ! V_12 -> V_86 ) {
F_310 ( & V_162 -> V_2 , L_134 ) ;
V_12 -> V_223 . V_806 = 0 ;
}
#if F_326 ( V_591 )
if ( ( F_224 ( V_12 -> V_223 . V_233 ) <= V_372 ) &&
( ! ( F_77 ( V_12 , V_966 ) & V_967 ) ) ) {
F_310 ( & V_162 -> V_2 ,
L_135 ) ;
V_12 -> V_223 . V_806 = 0 ;
} else {
V_12 -> V_968 = F_539 ( V_12 -> V_789 ,
V_12 -> V_790 ) ;
if ( ! V_12 -> V_968 ) {
F_310 ( & V_162 -> V_2 ,
L_136 ) ;
V_12 -> V_223 . V_806 = 0 ;
}
}
#endif
if ( F_390 ( V_12 ) && F_220 ( & V_12 -> V_91 ) < 0 ) {
F_310 ( & V_162 -> V_2 , L_137
L_138 ) ;
V_12 -> V_223 . V_806 = 0 ;
}
if ( F_390 ( V_12 ) ) {
if ( F_77 ( V_12 , V_966 ) & V_969 ) {
T_1 V_366 , V_970 ;
if ( V_233 <= V_372 ) {
V_970 = V_971 ;
V_366 = F_77 ( V_12 , V_970 ) ;
V_12 -> V_91 . V_366 = V_366 / 4 ;
} else {
V_970 = V_972 ;
V_366 = F_77 ( V_12 , V_970 ) ;
V_12 -> V_91 . V_366 = V_366 ;
}
}
}
if ( V_973 > 1 && F_474 ( V_12 ) == 0 )
V_12 -> V_68 |= V_161 ;
else if ( V_973 > 0 && F_540 ( V_162 ) == 0 )
V_12 -> V_68 |= V_163 ;
F_481 ( V_12 ) ;
V_22 = F_476 ( V_12 ) ;
if ( V_22 )
goto V_946;
F_82 (adapter, i) {
V_11 = F_97 ( V_12 , V_19 ) ;
F_541 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
F_542 ( V_12 -> V_39 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_543 ( V_12 -> V_39 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_81 [ V_11 -> V_76 ] = V_19 ;
F_490 ( V_12 -> V_39 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_162 -> V_2 , L_139 ) ;
goto V_946;
}
if ( V_22 ) {
F_310 ( & V_162 -> V_2 , L_140 , V_19 ) ;
V_22 = 0 ;
}
if ( V_974 ) {
V_12 -> V_329 = F_544 ( F_520 ( V_162 ) ,
V_974 ) ;
F_192 ( V_12 ) ;
}
V_162 -> V_975 = 1 ;
if ( F_390 ( V_12 ) )
F_314 ( V_12 ) ;
F_484 ( V_12 ) ;
V_933:
#ifdef F_545
if ( V_917 < F_20 ( V_976 ) && V_976 [ V_917 ] > 0 ) {
F_310 ( & V_162 -> V_2 ,
L_141
L_142
L_143 ) ;
if ( F_508 ( V_162 , V_976 [ V_917 ] ) == 0 )
F_409 ( & V_162 -> V_2 ,
L_144 ,
V_976 [ V_917 ] ) ;
}
#endif
return 0 ;
V_946:
F_494 ( V_12 ) ;
V_944:
if ( ! F_122 ( V_12 -> V_223 . V_233 ) )
F_504 ( V_12 -> V_503 ) ;
V_934:
if ( V_12 -> V_361 )
F_546 ( V_12 -> V_361 ) ;
F_34 ( V_12 -> V_935 ) ;
F_34 ( V_12 ) ;
V_929:
F_504 ( V_544 ) ;
V_928:
F_547 ( V_162 ) ;
F_451 ( V_162 ) ;
V_927:
F_548 ( V_162 ) ;
return V_22 ;
}
static void F_549 ( struct V_417 * V_162 )
{
struct V_12 * V_12 = F_249 ( V_162 ) ;
#ifdef F_545
F_507 ( V_162 ) ;
#endif
if ( V_12 ) {
int V_19 ;
F_546 ( V_12 -> V_361 ) ;
if ( F_390 ( V_12 ) )
F_318 ( V_12 ) ;
F_104 ( V_12 ) ;
F_82 (adapter, i)
if ( V_12 -> V_39 [ V_19 ] -> V_977 == V_978 )
F_550 ( V_12 -> V_39 [ V_19 ] ) ;
F_551 ( V_12 -> V_329 ) ;
if ( V_12 -> V_91 . V_96 ) {
struct V_84 * V_85 = & V_12 -> V_91 . V_96 [ 0 ] ;
for ( V_19 = 0 ; V_19 < ( V_12 -> V_91 . V_93 +
V_12 -> V_91 . V_94 ) ; V_19 ++ , V_85 ++ )
if ( V_85 -> V_103 )
F_50 ( V_12 , V_85 ) ;
}
if ( V_12 -> V_68 & V_206 )
F_338 ( V_12 ) ;
F_494 ( V_12 ) ;
#if F_326 ( V_591 )
F_552 ( V_12 ) ;
#endif
F_504 ( V_12 -> V_544 ) ;
if ( ! F_122 ( V_12 -> V_223 . V_233 ) )
F_504 ( V_12 -> V_503 ) ;
F_547 ( V_162 ) ;
if ( ( V_12 -> V_68 & V_836 ) ) {
F_451 ( V_162 ) ;
V_12 -> V_68 &= ~ V_836 ;
}
F_548 ( V_162 ) ;
F_34 ( V_12 -> V_935 ) ;
F_553 () ;
F_34 ( V_12 ) ;
} else
F_548 ( V_162 ) ;
}
static int T_18 F_554 ( void )
{
int V_54 ;
V_974 = F_544 ( V_926 , NULL ) ;
if ( ! V_974 )
F_555 ( L_145 ) ;
V_54 = F_556 ( & V_477 ) ;
if ( V_54 < 0 )
F_557 ( V_974 ) ;
#if F_326 ( V_591 )
if ( ! V_979 ) {
F_558 ( & V_980 ) ;
V_979 = true ;
}
#endif
return V_54 ;
}
static void T_19 F_559 ( void )
{
#if F_326 ( V_591 )
if ( V_979 ) {
F_560 ( & V_980 ) ;
V_979 = false ;
}
#endif
F_561 ( & V_477 ) ;
F_557 ( V_974 ) ;
}
