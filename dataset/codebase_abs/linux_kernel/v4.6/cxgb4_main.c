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
static inline int F_20 ( struct V_5 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_12 ;
T_2 V_38 = 0 ;
bool V_39 = false ;
struct V_40 * V_41 ;
F_21 (entry, &adap->mac_hlist, list) {
V_39 |= F_22 ( V_41 -> V_42 ) ;
V_38 |= ( 1ULL << V_40 ( V_41 -> V_42 ) ) ;
}
return F_23 ( V_13 , V_13 -> V_27 , V_11 -> V_43 , V_39 ,
V_38 , false ) ;
}
static int F_24 ( struct V_1 * V_44 , const T_3 * V_45 )
{
struct V_5 * V_11 = F_4 ( V_44 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_46 ;
T_2 V_47 = 0 ;
T_2 V_48 = 0 ;
bool free = false ;
bool V_39 = F_22 ( V_45 ) ;
const T_3 * V_49 [ 1 ] = { V_45 } ;
struct V_40 * V_50 ;
V_46 = F_25 ( V_13 , V_13 -> V_27 , V_11 -> V_43 , free , 1 , V_49 ,
NULL , V_39 ? & V_48 : & V_47 , false ) ;
if ( V_46 < 0 )
goto V_51;
if ( V_48 || V_47 ) {
V_50 = F_26 ( sizeof( * V_50 ) , V_52 ) ;
if ( ! V_50 )
return - V_53 ;
F_27 ( V_50 -> V_42 , V_45 ) ;
F_28 ( & V_50 -> V_54 , & V_13 -> V_55 ) ;
V_46 = F_20 ( V_11 ) ;
}
V_51:
return V_46 < 0 ? V_46 : 0 ;
}
static int F_29 ( struct V_1 * V_44 , const T_3 * V_45 )
{
struct V_5 * V_11 = F_4 ( V_44 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
int V_46 ;
const T_3 * V_49 [ 1 ] = { V_45 } ;
struct V_40 * V_41 , * V_56 ;
F_30 (entry, tmp, &adap->mac_hlist, list) {
if ( F_31 ( V_41 -> V_42 , V_45 ) ) {
F_32 ( & V_41 -> V_54 ) ;
F_33 ( V_41 ) ;
return F_20 ( V_11 ) ;
}
}
V_46 = F_34 ( V_13 , V_13 -> V_27 , V_11 -> V_43 , 1 , V_49 , false ) ;
return V_46 < 0 ? - V_57 : 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_58 , bool V_59 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
if ( ! ( V_2 -> V_60 & V_61 ) ) {
F_36 ( V_2 , F_24 , F_29 ) ;
if ( ! ( V_2 -> V_60 & V_62 ) )
F_37 ( V_2 , F_24 , F_29 ) ;
}
return F_38 ( V_12 , V_12 -> V_27 , V_11 -> V_43 , V_58 ,
( V_2 -> V_60 & V_61 ) ? 1 : 0 ,
( V_2 -> V_60 & V_62 ) ? 1 : 0 , 1 , - 1 ,
V_59 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_46 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
unsigned int V_63 = V_11 -> V_12 -> V_28 ;
V_46 = F_38 ( V_11 -> V_12 , V_63 , V_11 -> V_43 , V_2 -> V_58 , - 1 , - 1 , - 1 ,
! ! ( V_2 -> V_64 & V_65 ) , true ) ;
if ( V_46 == 0 ) {
V_46 = F_40 ( V_11 -> V_12 , V_63 , V_11 -> V_43 ,
V_11 -> V_66 , V_2 -> V_67 , true ,
true ) ;
if ( V_46 >= 0 ) {
V_11 -> V_66 = V_46 ;
V_46 = 0 ;
}
}
if ( V_46 == 0 )
V_46 = F_41 ( V_11 -> V_12 , V_63 , V_11 -> V_68 ,
& V_11 -> V_7 ) ;
if ( V_46 == 0 ) {
F_42 () ;
V_46 = F_43 ( V_11 -> V_12 , V_63 , V_11 -> V_43 , true ,
true , V_69 ) ;
F_44 () ;
}
return V_46 ;
}
int F_45 ( const struct V_1 * V_2 )
{
#ifdef F_15
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! V_11 -> V_70 . V_71 )
return 0 ;
return ( ( V_11 -> V_70 . V_72 == V_73 ) ||
( V_11 -> V_70 . V_72 == V_74 ) ) ;
#else
return 0 ;
#endif
}
static void F_46 ( struct V_12 * V_13 , const struct V_75 * V_76 )
{
int V_34 = F_47 ( F_48 ( V_76 -> V_77 ) ) ;
struct V_1 * V_2 = V_13 -> V_34 [ V_34 ] ;
int V_78 = F_45 ( V_2 ) ;
int V_79 ;
F_49 ( V_13 , V_76 ) ;
V_79 = F_45 ( V_2 ) ;
if ( V_79 != V_78 )
F_6 ( V_2 , V_79 ) ;
}
static void F_50 ( struct V_12 * V_13 , struct V_80 * V_81 )
{
if ( V_81 -> V_82 )
F_51 ( V_81 -> V_82 ) ;
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
}
static void F_52 ( struct V_12 * V_13 , const struct V_83 * V_84 )
{
unsigned int V_85 = F_53 ( V_84 ) ;
unsigned int V_86 = V_85 - V_13 -> V_87 . V_88 ;
unsigned int V_46 ;
struct V_80 * V_81 ;
if ( V_85 >= V_13 -> V_87 . V_88 && V_86 <
( V_13 -> V_87 . V_89 + V_13 -> V_87 . V_90 ) ) {
V_85 = V_86 ;
V_46 = F_54 ( V_84 -> V_91 ) ;
V_81 = & V_13 -> V_87 . V_92 [ V_85 ] ;
if ( V_46 == V_93 ) {
F_50 ( V_13 , V_81 ) ;
} else if ( V_46 == V_94 ) {
F_11 ( V_13 -> V_30 , L_23 ,
V_85 ) ;
F_50 ( V_13 , V_81 ) ;
} else if ( V_46 == V_95 ) {
V_81 -> V_96 = ( F_55 ( V_84 -> V_97 ) >> 24 ) & 0xff ;
V_81 -> V_98 = 0 ;
V_81 -> V_99 = 1 ;
} else {
F_11 ( V_13 -> V_30 , L_24 ,
V_85 , V_46 ) ;
F_50 ( V_13 , V_81 ) ;
}
}
}
static int F_56 ( struct V_100 * V_25 , const T_4 * V_101 ,
const struct V_102 * V_103 )
{
T_3 V_104 = ( ( const struct V_105 * ) V_101 ) -> V_104 ;
V_101 ++ ;
if ( F_57 ( V_104 == V_106 &&
( ( const struct V_107 * ) V_101 ) -> type == V_108 ) ) {
V_101 ++ ;
V_104 = ( ( const struct V_105 * ) V_101 ) -> V_104 ;
V_101 ++ ;
if ( V_104 != V_109 ) {
F_11 ( V_25 -> V_13 -> V_30 , L_25
, V_104 ) ;
goto V_51;
}
}
if ( F_58 ( V_104 == V_109 ) ) {
const struct V_110 * V_6 = ( void * ) V_101 ;
unsigned int V_111 = F_59 ( F_48 ( V_6 -> V_112 ) ) ;
struct V_113 * V_15 ;
V_15 = V_25 -> V_13 -> V_16 . V_114 [ V_111 - V_25 -> V_13 -> V_16 . V_115 ] ;
V_15 -> V_116 ++ ;
if ( ( T_3 * ) V_15 < ( T_3 * ) V_25 -> V_13 -> V_16 . V_117 ) {
struct V_14 * V_118 ;
V_118 = F_60 ( V_15 , struct V_14 , V_25 ) ;
F_61 ( V_118 -> V_15 ) ;
} else {
struct V_119 * V_120 ;
V_120 = F_60 ( V_15 , struct V_119 , V_25 ) ;
F_62 ( & V_120 -> V_121 ) ;
}
} else if ( V_104 == V_122 || V_104 == V_106 ) {
const struct V_123 * V_6 = ( void * ) V_101 ;
#ifdef F_15
const struct V_75 * V_76 = ( const void * ) V_6 -> V_124 ;
unsigned int V_125 = F_63 ( F_48 ( V_76 -> V_77 ) ) ;
unsigned int V_126 =
F_64 ( F_48 ( V_76 -> V_127 ) ) ;
if ( V_125 == V_128 &&
V_126 == V_129 ) {
int V_34 = F_47 (
F_65 ( V_76 -> V_77 ) ) ;
struct V_1 * V_2 = V_25 -> V_13 -> V_34 [ V_34 ] ;
int V_130 = ( ( V_76 -> V_131 . V_132 . V_133 &
V_134 )
? V_135
: V_136 ) ;
F_66 ( V_2 , V_130 ) ;
}
if ( V_125 == V_128 &&
V_126 == V_137 )
F_46 ( V_25 -> V_13 , V_76 ) ;
else
#endif
if ( V_6 -> type == 0 )
F_67 ( V_25 -> V_13 , V_6 -> V_124 ) ;
} else if ( V_104 == V_138 ) {
const struct V_139 * V_6 = ( void * ) V_101 ;
F_68 ( V_25 -> V_13 , V_6 ) ;
} else if ( V_104 == V_140 ) {
const struct V_83 * V_6 = ( void * ) V_101 ;
F_52 ( V_25 -> V_13 , V_6 ) ;
} else
F_11 ( V_25 -> V_13 -> V_30 ,
L_26 , V_104 ) ;
V_51:
return 0 ;
}
static void F_69 ( struct V_100 * V_25 )
{
if ( V_141 [ V_25 -> V_142 ] . V_143 )
V_141 [ V_25 -> V_142 ] . V_143 ( & V_25 -> V_144 ) ;
}
static int F_70 ( struct V_100 * V_25 , const T_4 * V_101 ,
const struct V_102 * V_103 )
{
struct V_145 * V_146 = F_60 ( V_25 , struct V_145 , V_147 ) ;
int V_46 ;
if ( ( ( const struct V_105 * ) V_101 ) -> V_104 == V_106 &&
( ( const struct V_107 * ) ( V_101 + 1 ) ) -> type == V_108 )
V_101 += 2 ;
if ( V_25 -> V_148 )
V_46 = V_141 [ V_25 -> V_142 ] . F_71 ( V_25 -> V_13 -> V_149 [ V_25 -> V_142 ] ,
V_101 , V_103 , & V_25 -> V_144 ,
& V_25 -> V_150 ) ;
else
V_46 = V_141 [ V_25 -> V_142 ] . F_72 ( V_25 -> V_13 -> V_149 [ V_25 -> V_142 ] ,
V_101 , V_103 ) ;
if ( V_46 ) {
V_146 -> V_151 . V_152 ++ ;
return - 1 ;
}
if ( V_103 == NULL )
V_146 -> V_151 . V_153 ++ ;
else if ( V_103 == V_154 )
V_146 -> V_151 . V_155 ++ ;
else
V_146 -> V_151 . V_156 ++ ;
return 0 ;
}
static void F_73 ( struct V_12 * V_12 )
{
if ( V_12 -> V_60 & V_157 ) {
F_74 ( V_12 -> V_158 ) ;
V_12 -> V_60 &= ~ V_157 ;
} else if ( V_12 -> V_60 & V_159 ) {
F_75 ( V_12 -> V_158 ) ;
V_12 -> V_60 &= ~ V_159 ;
}
}
static T_5 F_76 ( int V_160 , void * V_91 )
{
struct V_12 * V_13 = V_91 ;
T_1 V_161 = F_77 ( V_13 , F_78 ( V_162 ) ) ;
if ( V_161 & V_163 ) {
V_13 -> V_164 = 1 ;
F_79 ( V_13 , F_78 ( V_162 ) , V_161 ) ;
}
if ( V_13 -> V_60 & V_165 )
F_80 ( V_13 ) ;
return V_166 ;
}
static void F_81 ( struct V_12 * V_13 )
{
int V_19 , V_167 , V_168 = 2 , V_169 = sizeof( V_13 -> V_170 [ 0 ] . V_171 ) ;
snprintf ( V_13 -> V_170 [ 0 ] . V_171 , V_169 , L_27 , V_13 -> V_34 [ 0 ] -> V_9 ) ;
snprintf ( V_13 -> V_170 [ 1 ] . V_171 , V_169 , L_28 ,
V_13 -> V_34 [ 0 ] -> V_9 ) ;
F_82 (adap, j) {
struct V_1 * V_172 = V_13 -> V_34 [ V_167 ] ;
const struct V_5 * V_11 = F_4 ( V_172 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_20 ; V_19 ++ , V_168 ++ )
snprintf ( V_13 -> V_170 [ V_168 ] . V_171 , V_169 , L_29 ,
V_172 -> V_9 , V_19 ) ;
}
F_83 (&adap->sge, i)
snprintf ( V_13 -> V_170 [ V_168 ++ ] . V_171 , V_169 , L_30 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_19 ) ;
F_84 (&adap->sge, i)
snprintf ( V_13 -> V_170 [ V_168 ++ ] . V_171 , V_169 , L_31 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_19 ) ;
F_85 (&adap->sge, i)
snprintf ( V_13 -> V_170 [ V_168 ++ ] . V_171 , V_169 , L_32 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_19 ) ;
F_86 (&adap->sge, i)
snprintf ( V_13 -> V_170 [ V_168 ++ ] . V_171 , V_169 , L_33 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_19 ) ;
}
static int F_87 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_22 , V_173 , V_174 = 0 , V_175 = 0 , V_176 = 0 ;
int V_177 = 0 ;
int V_178 = 2 ;
V_22 = F_88 ( V_13 -> V_170 [ 1 ] . V_38 , V_179 , 0 ,
V_13 -> V_170 [ 1 ] . V_171 , & V_4 -> V_180 ) ;
if ( V_22 )
return V_22 ;
F_89 (s, ethqidx) {
V_22 = F_88 ( V_13 -> V_170 [ V_178 ] . V_38 ,
V_179 , 0 ,
V_13 -> V_170 [ V_178 ] . V_171 ,
& V_4 -> V_181 [ V_173 ] . V_147 ) ;
if ( V_22 )
goto V_182;
V_178 ++ ;
}
F_83 (s, iscsiqidx) {
V_22 = F_88 ( V_13 -> V_170 [ V_178 ] . V_38 ,
V_179 , 0 ,
V_13 -> V_170 [ V_178 ] . V_171 ,
& V_4 -> V_183 [ V_174 ] . V_147 ) ;
if ( V_22 )
goto V_182;
V_178 ++ ;
}
F_84 (s, iscsitqidx) {
V_22 = F_88 ( V_13 -> V_170 [ V_178 ] . V_38 ,
V_179 , 0 ,
V_13 -> V_170 [ V_178 ] . V_171 ,
& V_4 -> V_184 [ V_177 ] . V_147 ) ;
if ( V_22 )
goto V_182;
V_178 ++ ;
}
F_85 (s, rdmaqidx) {
V_22 = F_88 ( V_13 -> V_170 [ V_178 ] . V_38 ,
V_179 , 0 ,
V_13 -> V_170 [ V_178 ] . V_171 ,
& V_4 -> V_185 [ V_175 ] . V_147 ) ;
if ( V_22 )
goto V_182;
V_178 ++ ;
}
F_86 (s, rdmaciqqidx) {
V_22 = F_88 ( V_13 -> V_170 [ V_178 ] . V_38 ,
V_179 , 0 ,
V_13 -> V_170 [ V_178 ] . V_171 ,
& V_4 -> V_186 [ V_176 ] . V_147 ) ;
if ( V_22 )
goto V_182;
V_178 ++ ;
}
return 0 ;
V_182:
while ( -- V_176 >= 0 )
F_90 ( V_13 -> V_170 [ -- V_178 ] . V_38 ,
& V_4 -> V_186 [ V_176 ] . V_147 ) ;
while ( -- V_175 >= 0 )
F_90 ( V_13 -> V_170 [ -- V_178 ] . V_38 ,
& V_4 -> V_185 [ V_175 ] . V_147 ) ;
while ( -- V_177 >= 0 )
F_90 ( V_13 -> V_170 [ -- V_178 ] . V_38 ,
& V_4 -> V_184 [ V_177 ] . V_147 ) ;
while ( -- V_174 >= 0 )
F_90 ( V_13 -> V_170 [ -- V_178 ] . V_38 ,
& V_4 -> V_183 [ V_174 ] . V_147 ) ;
while ( -- V_173 >= 0 )
F_90 ( V_13 -> V_170 [ -- V_178 ] . V_38 ,
& V_4 -> V_181 [ V_173 ] . V_147 ) ;
F_90 ( V_13 -> V_170 [ 1 ] . V_38 , & V_4 -> V_180 ) ;
return V_22 ;
}
static void F_91 ( struct V_12 * V_13 )
{
int V_19 , V_178 = 2 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_90 ( V_13 -> V_170 [ 1 ] . V_38 , & V_4 -> V_180 ) ;
F_89 (s, i)
F_90 ( V_13 -> V_170 [ V_178 ++ ] . V_38 , & V_4 -> V_181 [ V_19 ] . V_147 ) ;
F_83 (s, i)
F_90 ( V_13 -> V_170 [ V_178 ++ ] . V_38 ,
& V_4 -> V_183 [ V_19 ] . V_147 ) ;
F_84 (s, i)
F_90 ( V_13 -> V_170 [ V_178 ++ ] . V_38 ,
& V_4 -> V_184 [ V_19 ] . V_147 ) ;
F_85 (s, i)
F_90 ( V_13 -> V_170 [ V_178 ++ ] . V_38 , & V_4 -> V_185 [ V_19 ] . V_147 ) ;
F_86 (s, i)
F_90 ( V_13 -> V_170 [ V_178 ++ ] . V_38 , & V_4 -> V_186 [ V_19 ] . V_147 ) ;
}
int F_92 ( const struct V_5 * V_11 , const T_6 * V_187 )
{
T_6 * V_188 ;
int V_19 , V_22 ;
struct V_12 * V_12 = V_11 -> V_12 ;
const struct V_189 * V_146 ;
V_146 = & V_12 -> V_16 . V_181 [ V_11 -> V_18 ] ;
V_188 = F_93 ( V_11 -> V_190 * sizeof( T_6 ) , V_191 ) ;
if ( ! V_188 )
return - V_53 ;
for ( V_19 = 0 ; V_19 < V_11 -> V_190 ; V_19 ++ , V_187 ++ )
V_188 [ V_19 ] = V_146 [ * V_187 ] . V_147 . V_192 ;
V_22 = F_94 ( V_12 , V_12 -> V_28 , V_11 -> V_43 , 0 ,
V_11 -> V_190 , V_188 , V_11 -> V_190 ) ;
if ( ! V_22 )
V_22 = F_95 ( V_12 , V_12 -> V_27 , V_11 -> V_43 ,
V_193 |
V_194 |
V_195 |
V_196 |
V_197 ,
V_188 [ 0 ] ) ;
F_33 ( V_188 ) ;
return V_22 ;
}
static int F_96 ( struct V_12 * V_13 )
{
int V_19 , V_167 , V_22 ;
F_82 (adap, i) {
const struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
for ( V_167 = 0 ; V_167 < V_11 -> V_190 ; V_167 ++ )
V_11 -> V_188 [ V_167 ] = V_167 % V_11 -> V_20 ;
V_22 = F_92 ( V_11 , V_11 -> V_188 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static unsigned int F_98 ( const struct V_16 * V_6 , unsigned int V_111 )
{
V_111 -= V_6 -> V_198 ;
return F_99 ( V_6 -> V_199 [ V_111 ] -> V_44 ) -> V_68 ;
}
static void F_100 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_200 ; V_19 ++ ) {
struct V_100 * V_25 = V_13 -> V_16 . V_199 [ V_19 ] ;
if ( V_25 && V_25 -> V_201 ) {
F_101 ( & V_25 -> V_150 ) ;
F_42 () ;
while ( ! F_102 ( V_25 ) )
F_103 ( 1 ) ;
F_44 () ;
}
}
}
static void F_104 ( struct V_12 * V_13 )
{
if ( V_13 -> V_60 & V_202 ) {
F_105 ( V_13 ) ;
if ( V_13 -> V_60 & V_157 ) {
F_91 ( V_13 ) ;
F_90 ( V_13 -> V_170 [ 0 ] . V_38 , V_13 ) ;
} else {
F_90 ( V_13 -> V_158 -> V_160 , V_13 ) ;
}
F_100 ( V_13 ) ;
}
}
static void F_106 ( struct V_12 * V_13 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_16 . V_200 ; V_19 ++ ) {
struct V_100 * V_25 = V_13 -> V_16 . V_199 [ V_19 ] ;
if ( ! V_25 )
continue;
if ( V_25 -> V_201 ) {
F_107 ( V_25 ) ;
F_108 ( & V_25 -> V_150 ) ;
}
F_79 ( V_13 , F_78 ( V_203 ) ,
F_109 ( V_25 -> V_204 ) |
F_110 ( V_25 -> V_26 ) ) ;
}
}
static int F_111 ( struct V_12 * V_13 , struct V_145 * V_25 ,
unsigned int V_205 , unsigned int V_206 , int V_168 ,
T_6 * V_207 , bool V_208 )
{
int V_19 , V_22 ;
for ( V_19 = 0 ; V_19 < V_205 ; V_19 ++ , V_25 ++ ) {
if ( V_168 > 0 )
V_168 ++ ;
V_22 = F_112 ( V_13 , & V_25 -> V_147 , false ,
V_13 -> V_34 [ V_19 / V_206 ] ,
V_168 , V_25 -> V_209 . V_210 ? & V_25 -> V_209 : NULL ,
F_70 ,
V_208 ? F_69 : NULL ,
0 ) ;
if ( V_22 )
return V_22 ;
memset ( & V_25 -> V_151 , 0 , sizeof( V_25 -> V_151 ) ) ;
if ( V_207 )
V_207 [ V_19 ] = V_25 -> V_147 . V_192 ;
}
return 0 ;
}
static int F_113 ( struct V_12 * V_13 )
{
int V_22 , V_168 , V_19 , V_167 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
F_114 ( V_4 -> V_211 , V_4 -> V_212 ) ;
F_114 ( V_4 -> V_213 , V_4 -> V_212 ) ;
if ( V_13 -> V_60 & V_157 )
V_168 = 1 ;
else {
V_22 = F_112 ( V_13 , & V_4 -> V_214 , false , V_13 -> V_34 [ 0 ] , 0 ,
NULL , NULL , NULL , - 1 ) ;
if ( V_22 )
return V_22 ;
V_168 = - ( ( int ) V_4 -> V_214 . V_192 + 1 ) ;
}
V_22 = F_112 ( V_13 , & V_4 -> V_180 , true , V_13 -> V_34 [ 0 ] ,
V_168 , NULL , F_56 , NULL , - 1 ) ;
if ( V_22 ) {
V_215: F_115 ( V_13 ) ;
return V_22 ;
}
F_82 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_189 * V_25 = & V_4 -> V_181 [ V_11 -> V_18 ] ;
struct V_14 * V_216 = & V_4 -> V_17 [ V_11 -> V_18 ] ;
for ( V_167 = 0 ; V_167 < V_11 -> V_20 ; V_167 ++ , V_25 ++ ) {
if ( V_168 > 0 )
V_168 ++ ;
V_22 = F_112 ( V_13 , & V_25 -> V_147 , false , V_2 ,
V_168 , & V_25 -> V_209 ,
V_217 ,
NULL ,
F_116 ( V_13 ,
V_11 -> V_68 ) ) ;
if ( V_22 )
goto V_215;
V_25 -> V_147 . V_85 = V_167 ;
memset ( & V_25 -> V_151 , 0 , sizeof( V_25 -> V_151 ) ) ;
}
for ( V_167 = 0 ; V_167 < V_11 -> V_20 ; V_167 ++ , V_216 ++ ) {
V_22 = F_117 ( V_13 , V_216 , V_2 ,
F_118 ( V_2 , V_167 ) ,
V_4 -> V_180 . V_26 ) ;
if ( V_22 )
goto V_215;
}
}
V_167 = V_4 -> V_218 / V_13 -> V_219 . V_220 ;
F_83 (s, i) {
V_22 = F_119 ( V_13 , & V_4 -> V_117 [ V_19 ] ,
V_13 -> V_34 [ V_19 / V_167 ] ,
V_4 -> V_180 . V_26 ) ;
if ( V_22 )
goto V_215;
}
#define F_120 ( T_7 , V_205 , V_206 , V_207 , V_208 ) do { \
err = alloc_ofld_rxqs(adap, firstq, nq, per_chan, msi_idx, ids, lro); \
if (err) \
goto freeout; \
if (msi_idx > 0) \
msi_idx += nq; \
} while (0)
F_120 ( V_4 -> V_183 , V_4 -> V_218 , V_167 , V_4 -> V_221 , false ) ;
F_120 ( V_4 -> V_184 , V_4 -> V_222 , V_167 , V_4 -> V_223 , true ) ;
F_120 ( V_4 -> V_185 , V_4 -> V_224 , 1 , V_4 -> V_225 , false ) ;
V_167 = V_4 -> V_226 / V_13 -> V_219 . V_220 ;
F_120 ( V_4 -> V_186 , V_4 -> V_226 , V_167 , V_4 -> V_227 , false ) ;
#undef F_120
F_82 (adap, i) {
V_22 = F_121 ( V_13 , & V_4 -> V_228 [ V_19 ] , V_13 -> V_34 [ V_19 ] ,
V_4 -> V_180 . V_26 ,
V_4 -> V_185 [ V_19 ] . V_147 . V_26 ) ;
if ( V_22 )
goto V_215;
}
F_79 ( V_13 , F_122 ( V_13 -> V_219 . V_229 ) ?
V_230 :
V_231 ,
F_123 ( F_99 ( V_13 -> V_34 [ 0 ] ) -> V_68 ) |
F_124 ( V_4 -> V_181 [ 0 ] . V_147 . V_192 ) ) ;
return 0 ;
}
void * F_125 ( T_8 V_210 )
{
void * V_6 = F_26 ( V_210 , V_191 | V_232 ) ;
if ( ! V_6 )
V_6 = F_126 ( V_210 ) ;
return V_6 ;
}
void F_127 ( void * V_42 )
{
F_128 ( V_42 ) ;
}
static int F_129 ( struct V_12 * V_12 , int V_233 )
{
struct V_80 * V_81 = & V_12 -> V_87 . V_92 [ V_233 ] ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
unsigned int V_238 ;
V_235 = F_130 ( sizeof( * V_237 ) , V_191 ) ;
if ( ! V_235 )
return - V_53 ;
if ( V_81 -> V_239 . V_240 || V_81 -> V_239 . V_241 ) {
V_81 -> V_82 = F_131 ( V_12 , V_81 -> V_239 . V_242 ,
V_81 -> V_239 . V_243 , V_81 -> V_239 . V_244 ) ;
if ( V_81 -> V_82 == NULL ) {
F_132 ( V_235 ) ;
return - V_53 ;
}
}
V_238 = V_12 -> V_87 . V_88 + V_233 ;
V_237 = (struct V_236 * ) F_133 ( V_235 , sizeof( * V_237 ) ) ;
memset ( V_237 , 0 , sizeof( * V_237 ) ) ;
V_237 -> V_245 = F_134 ( F_135 ( V_246 ) ) ;
V_237 -> V_247 = F_134 ( F_136 ( sizeof( * V_237 ) / 16 ) ) ;
V_237 -> V_248 =
F_134 ( F_137 ( V_238 ) |
F_138 ( V_81 -> V_239 . type ) |
F_139 ( 0 ) |
F_140 ( V_81 -> V_239 . V_249 ) ) ;
V_237 -> V_250 =
F_134 ( F_141 ( V_81 -> V_239 . V_251 ) |
F_142 ( V_81 -> V_239 . V_126 == V_252 ) |
F_143 ( V_81 -> V_239 . V_253 ) |
F_144 ( V_81 -> V_239 . V_254 ) |
F_145 ( V_81 -> V_239 . V_255 ) |
F_146 ( V_81 -> V_239 . V_126 == V_256 ) |
F_147 ( V_81 -> V_239 . V_240 ) |
F_148 ( V_81 -> V_239 . V_257 ) |
F_149 ( V_81 -> V_239 . V_241 == V_258 ||
V_81 -> V_239 . V_241 == V_259 ) |
F_150 ( V_81 -> V_239 . V_241 == V_260 ||
V_81 -> V_239 . V_241 == V_259 ) |
F_151 ( V_81 -> V_239 . V_261 ) |
F_152 ( V_81 -> V_239 . V_243 ) |
F_153 ( V_81 -> V_239 . V_262 ) |
F_154 ( V_81 -> V_82 ? V_81 -> V_82 -> V_85 : 0 ) ) ;
V_237 -> V_263 = F_155 ( V_81 -> V_239 . V_264 . V_263 ) ;
V_237 -> V_265 = F_155 ( V_81 -> V_239 . V_266 . V_263 ) ;
V_237 -> V_267 =
( F_156 ( V_81 -> V_239 . V_264 . V_268 ) |
F_157 ( V_81 -> V_239 . V_266 . V_268 ) |
F_158 ( V_81 -> V_239 . V_264 . V_269 ) |
F_159 ( V_81 -> V_239 . V_264 . V_270 ) |
F_160 ( V_81 -> V_239 . V_266 . V_269 ) |
F_161 ( V_81 -> V_239 . V_266 . V_270 ) ) ;
V_237 -> V_271 = 0 ;
V_237 -> V_272 =
F_155 ( F_162 ( 0 ) |
F_163 ( V_12 -> V_16 . V_180 . V_192 ) ) ;
V_237 -> V_273 =
F_134 ( F_164 ( V_81 -> V_239 . V_264 . V_274 ) |
F_165 ( V_81 -> V_239 . V_266 . V_274 ) |
F_166 ( V_81 -> V_239 . V_264 . V_275 ) |
F_167 ( V_81 -> V_239 . V_266 . V_275 ) |
F_168 ( V_81 -> V_239 . V_264 . V_276 ) |
F_169 ( V_81 -> V_239 . V_266 . V_276 ) |
F_170 ( V_81 -> V_239 . V_264 . V_277 ) |
F_171 ( V_81 -> V_239 . V_266 . V_277 ) ) ;
V_237 -> V_278 = V_81 -> V_239 . V_264 . V_279 ;
V_237 -> V_280 = V_81 -> V_239 . V_266 . V_279 ;
V_237 -> V_281 = V_81 -> V_239 . V_264 . V_282 ;
V_237 -> V_283 = V_81 -> V_239 . V_266 . V_282 ;
V_237 -> V_284 = F_155 ( V_81 -> V_239 . V_264 . V_284 ) ;
V_237 -> V_285 = F_155 ( V_81 -> V_239 . V_266 . V_284 ) ;
V_237 -> V_286 = F_155 ( V_81 -> V_239 . V_264 . V_286 ) ;
V_237 -> V_287 = F_155 ( V_81 -> V_239 . V_266 . V_286 ) ;
memcpy ( V_237 -> V_288 , V_81 -> V_239 . V_264 . V_288 , sizeof( V_237 -> V_288 ) ) ;
memcpy ( V_237 -> V_289 , V_81 -> V_239 . V_266 . V_288 , sizeof( V_237 -> V_289 ) ) ;
memcpy ( V_237 -> V_290 , V_81 -> V_239 . V_264 . V_290 , sizeof( V_237 -> V_290 ) ) ;
memcpy ( V_237 -> V_291 , V_81 -> V_239 . V_266 . V_290 , sizeof( V_237 -> V_291 ) ) ;
V_237 -> V_292 = F_155 ( V_81 -> V_239 . V_264 . V_293 ) ;
V_237 -> V_294 = F_155 ( V_81 -> V_239 . V_266 . V_293 ) ;
V_237 -> V_295 = F_155 ( V_81 -> V_239 . V_264 . V_296 ) ;
V_237 -> V_297 = F_155 ( V_81 -> V_239 . V_266 . V_296 ) ;
if ( V_81 -> V_239 . V_257 )
memcpy ( V_237 -> V_298 , V_81 -> V_239 . V_299 , sizeof( V_237 -> V_298 ) ) ;
V_81 -> V_98 = 1 ;
F_172 ( V_235 , V_300 , V_81 -> V_239 . V_264 . V_276 & 0x3 ) ;
F_173 ( V_12 , V_235 ) ;
return 0 ;
}
static int F_174 ( struct V_12 * V_12 , int V_233 )
{
struct V_80 * V_81 = & V_12 -> V_87 . V_92 [ V_233 ] ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
unsigned int V_301 , V_238 ;
V_301 = sizeof( * V_237 ) ;
V_238 = V_12 -> V_87 . V_88 + V_233 ;
V_235 = F_130 ( V_301 , V_191 ) ;
if ( ! V_235 )
return - V_53 ;
V_237 = (struct V_236 * ) F_133 ( V_235 , V_301 ) ;
F_175 ( V_238 , V_237 , V_12 -> V_16 . V_180 . V_192 ) ;
V_81 -> V_98 = 1 ;
F_176 ( V_12 , V_235 ) ;
return 0 ;
}
static T_6 F_177 ( struct V_1 * V_2 , struct V_234 * V_235 ,
void * V_302 , T_9 V_303 )
{
int V_15 ;
#ifdef F_15
if ( F_45 ( V_2 ) ) {
T_6 V_304 ;
int V_22 ;
V_22 = F_178 ( V_235 , & V_304 ) ;
if ( F_57 ( V_22 ) ) {
if ( F_179 () )
F_180 ( V_2 ,
L_34 ) ;
V_15 = 0 ;
} else {
V_15 = ( V_304 & V_305 ) >> V_306 ;
#ifdef F_181
if ( V_235 -> V_307 == F_155 ( V_308 ) )
V_15 = V_235 -> V_309 & 0x7 ;
#endif
}
return V_15 ;
}
#endif
if ( V_310 ) {
V_15 = ( F_182 ( V_235 )
? F_183 ( V_235 )
: F_184 () ) ;
while ( F_57 ( V_15 >= V_2 -> V_311 ) )
V_15 -= V_2 -> V_311 ;
return V_15 ;
}
return V_303 ( V_2 , V_235 ) % V_2 -> V_311 ;
}
static int F_185 ( const struct V_16 * V_4 , int time )
{
int V_19 , V_312 , V_313 = 0 , V_314 = V_315 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_316 ) ; V_19 ++ ) {
V_312 = time - V_4 -> V_316 [ V_19 ] ;
if ( V_312 < 0 )
V_312 = - V_312 ;
if ( V_312 < V_314 ) {
V_314 = V_312 ;
V_313 = V_19 ;
}
}
return V_313 ;
}
static int F_186 ( const struct V_16 * V_4 , int V_317 )
{
int V_19 , V_312 , V_313 = 0 , V_314 = V_315 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_318 ) ; V_19 ++ ) {
V_312 = V_317 - V_4 -> V_318 [ V_19 ] ;
if ( V_312 < 0 )
V_312 = - V_312 ;
if ( V_312 < V_314 ) {
V_314 = V_312 ;
V_313 = V_19 ;
}
}
return V_313 ;
}
int F_187 ( struct V_100 * V_25 ,
unsigned int V_319 , unsigned int V_320 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
if ( ( V_319 | V_320 ) == 0 )
V_320 = 1 ;
if ( V_320 ) {
int V_22 ;
T_1 V_161 , V_321 ;
V_321 = F_186 ( & V_13 -> V_16 , V_320 ) ;
if ( V_25 -> V_171 && V_25 -> V_322 != V_321 ) {
V_161 = F_7 ( V_23 ) |
F_8 (
V_323 ) |
F_9 ( V_25 -> V_26 ) ;
V_22 = F_188 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
& V_161 , & V_321 ) ;
if ( V_22 )
return V_22 ;
}
V_25 -> V_322 = V_321 ;
}
V_319 = V_319 == 0 ? 6 : F_185 ( & V_13 -> V_16 , V_319 ) ;
V_25 -> V_204 = F_189 ( V_319 ) | F_190 ( V_320 > 0 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , T_10 V_64 )
{
const struct V_5 * V_11 = F_4 ( V_2 ) ;
T_10 V_324 = V_2 -> V_64 ^ V_64 ;
int V_22 ;
if ( ! ( V_324 & V_65 ) )
return 0 ;
V_22 = F_38 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_43 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_64 & V_65 ) , true ) ;
if ( F_57 ( V_22 ) )
V_2 -> V_64 = V_64 ^ V_65 ;
return V_22 ;
}
static int F_192 ( struct V_12 * V_13 )
{
if ( F_193 ( V_13 -> V_325 ) )
return - 1 ;
#ifdef F_194
F_195 ( V_13 ) ;
#endif
return 0 ;
}
int F_196 ( struct V_326 * V_216 , void * V_124 )
{
int V_327 = - 1 ;
F_197 ( & V_216 -> V_328 ) ;
if ( V_216 -> V_329 ) {
union V_330 * V_6 = V_216 -> V_329 ;
V_327 = ( V_6 - V_216 -> V_331 ) + V_216 -> V_332 ;
V_216 -> V_329 = V_6 -> V_333 ;
V_6 -> V_124 = V_124 ;
V_216 -> V_334 ++ ;
}
F_198 ( & V_216 -> V_328 ) ;
return V_327 ;
}
void F_199 ( struct V_326 * V_216 , unsigned int V_327 )
{
union V_330 * V_6 = & V_216 -> V_331 [ V_327 - V_216 -> V_332 ] ;
F_197 ( & V_216 -> V_328 ) ;
V_6 -> V_333 = V_216 -> V_329 ;
V_216 -> V_329 = V_6 ;
V_216 -> V_334 -- ;
F_198 ( & V_216 -> V_328 ) ;
}
int F_200 ( struct V_326 * V_216 , int V_335 , void * V_124 )
{
int V_336 ;
F_197 ( & V_216 -> V_337 ) ;
if ( V_335 == V_338 ) {
V_336 = F_201 ( V_216 -> V_339 , V_216 -> V_340 ) ;
if ( V_336 < V_216 -> V_340 )
F_202 ( V_336 , V_216 -> V_339 ) ;
else
V_336 = - 1 ;
} else {
V_336 = F_203 ( V_216 -> V_339 , V_216 -> V_340 , 1 ) ;
if ( V_336 < 0 )
V_336 = - 1 ;
}
if ( V_336 >= 0 ) {
V_216 -> V_341 [ V_336 ] . V_124 = V_124 ;
V_336 += V_216 -> V_342 ;
if ( V_335 == V_338 )
V_216 -> V_343 ++ ;
else
V_216 -> V_343 += 2 ;
}
F_198 ( & V_216 -> V_337 ) ;
return V_336 ;
}
int F_204 ( struct V_326 * V_216 , int V_335 , void * V_124 )
{
int V_336 ;
F_197 ( & V_216 -> V_337 ) ;
if ( V_335 == V_338 ) {
V_336 = F_205 ( V_216 -> V_339 ,
V_216 -> V_340 + V_216 -> V_90 , V_216 -> V_340 ) ;
if ( V_336 < ( V_216 -> V_340 + V_216 -> V_90 ) )
F_202 ( V_336 , V_216 -> V_339 ) ;
else
V_336 = - 1 ;
} else {
V_336 = - 1 ;
}
if ( V_336 >= 0 ) {
V_216 -> V_341 [ V_336 ] . V_124 = V_124 ;
V_336 -= V_216 -> V_340 ;
V_336 += V_216 -> V_344 ;
V_216 -> V_345 ++ ;
}
F_198 ( & V_216 -> V_337 ) ;
return V_336 ;
}
void F_206 ( struct V_326 * V_216 , unsigned int V_336 , int V_335 )
{
if ( V_216 -> V_90 && ( V_336 >= V_216 -> V_344 ) ) {
V_336 -= V_216 -> V_344 ;
V_336 += V_216 -> V_340 ;
} else {
V_336 -= V_216 -> V_342 ;
}
F_197 ( & V_216 -> V_337 ) ;
if ( V_335 == V_338 )
F_207 ( V_336 , V_216 -> V_339 ) ;
else
F_208 ( V_216 -> V_339 , V_336 , 1 ) ;
V_216 -> V_341 [ V_336 ] . V_124 = NULL ;
if ( V_336 < V_216 -> V_340 ) {
if ( V_335 == V_338 )
V_216 -> V_343 -- ;
else
V_216 -> V_343 -= 2 ;
} else {
V_216 -> V_345 -- ;
}
F_198 ( & V_216 -> V_337 ) ;
}
static void F_209 ( struct V_234 * V_235 , unsigned int V_346 ,
unsigned int V_347 )
{
struct V_348 * V_349 ;
F_172 ( V_235 , V_350 , V_346 ) ;
V_349 = (struct V_348 * ) F_133 ( V_235 , sizeof( * V_349 ) ) ;
F_210 ( V_349 , V_347 ) ;
F_211 ( V_349 ) = F_134 ( F_212 ( V_351 , V_347 ) ) ;
}
static void F_213 ( struct V_326 * V_216 , unsigned int V_346 ,
unsigned int V_347 )
{
void * * V_6 = & V_216 -> V_352 [ V_347 ] ;
struct V_12 * V_13 = F_60 ( V_216 , struct V_12 , V_87 ) ;
F_197 ( & V_13 -> V_353 ) ;
* V_6 = V_13 -> V_354 ;
V_13 -> V_354 = ( void * * ) ( ( V_355 ) V_6 | V_346 ) ;
if ( ! V_13 -> V_356 ) {
V_13 -> V_356 = true ;
F_214 ( V_13 -> V_357 , & V_13 -> V_358 ) ;
}
F_198 ( & V_13 -> V_353 ) ;
}
static void F_215 ( struct V_359 * V_360 )
{
struct V_234 * V_235 ;
struct V_12 * V_13 ;
V_13 = F_60 ( V_360 , struct V_12 , V_358 ) ;
F_197 ( & V_13 -> V_353 ) ;
while ( V_13 -> V_354 ) {
void * * V_6 = V_13 -> V_354 ;
unsigned int V_346 = ( V_355 ) V_6 & 3 ;
V_6 = ( void * ) V_6 - V_346 ;
V_13 -> V_354 = * V_6 ;
* V_6 = NULL ;
F_198 ( & V_13 -> V_353 ) ;
while ( ! ( V_235 = F_130 ( sizeof( struct V_348 ) ,
V_191 ) ) )
F_216 ( 1 ) ;
F_209 ( V_235 , V_346 , V_6 - V_13 -> V_87 . V_352 ) ;
F_173 ( V_13 , V_235 ) ;
F_197 ( & V_13 -> V_353 ) ;
}
V_13 -> V_356 = false ;
F_198 ( & V_13 -> V_353 ) ;
}
void F_217 ( struct V_326 * V_216 , unsigned int V_346 , unsigned int V_347 )
{
struct V_234 * V_235 ;
struct V_12 * V_13 = F_60 ( V_216 , struct V_12 , V_87 ) ;
F_218 ( V_347 >= V_216 -> V_361 ) ;
if ( V_216 -> V_352 [ V_347 ] ) {
V_216 -> V_352 [ V_347 ] = NULL ;
if ( V_216 -> V_362 && ( V_347 >= V_216 -> V_362 ) )
F_219 ( & V_216 -> V_363 ) ;
else
F_219 ( & V_216 -> V_364 ) ;
}
V_235 = F_130 ( sizeof( struct V_348 ) , V_52 ) ;
if ( F_58 ( V_235 ) ) {
F_209 ( V_235 , V_346 , V_347 ) ;
F_173 ( V_13 , V_235 ) ;
} else
F_213 ( V_216 , V_346 , V_347 ) ;
}
static int F_220 ( struct V_326 * V_216 )
{
T_8 V_210 ;
unsigned int V_365 ;
unsigned int V_366 = V_216 -> V_366 ;
struct V_12 * V_13 = F_60 ( V_216 , struct V_12 , V_87 ) ;
V_365 = F_221 ( V_216 -> V_340 + V_216 -> V_90 ) ;
V_210 = V_216 -> V_361 * sizeof( * V_216 -> V_352 ) +
V_366 * sizeof( * V_216 -> V_331 ) +
V_216 -> V_340 * sizeof( * V_216 -> V_341 ) +
V_216 -> V_90 * sizeof( * V_216 -> V_341 ) +
V_365 * sizeof( long ) +
V_216 -> V_89 * sizeof( * V_216 -> V_92 ) +
V_216 -> V_90 * sizeof( * V_216 -> V_92 ) ;
V_216 -> V_352 = F_125 ( V_210 ) ;
if ( ! V_216 -> V_352 )
return - V_53 ;
V_216 -> V_331 = (union V_330 * ) & V_216 -> V_352 [ V_216 -> V_361 ] ;
V_216 -> V_341 = (struct V_367 * ) & V_216 -> V_331 [ V_366 ] ;
V_216 -> V_339 = ( unsigned long * ) & V_216 -> V_341 [ V_216 -> V_340 + V_216 -> V_90 ] ;
V_216 -> V_92 = (struct V_80 * ) & V_216 -> V_339 [ V_365 ] ;
F_222 ( & V_216 -> V_337 ) ;
F_222 ( & V_216 -> V_328 ) ;
V_216 -> V_343 = 0 ;
V_216 -> V_345 = 0 ;
V_216 -> V_329 = NULL ;
V_216 -> V_334 = 0 ;
F_223 ( & V_216 -> V_364 , 0 ) ;
F_223 ( & V_216 -> V_363 , 0 ) ;
if ( V_366 ) {
while ( -- V_366 )
V_216 -> V_331 [ V_366 - 1 ] . V_333 = & V_216 -> V_331 [ V_366 ] ;
V_216 -> V_329 = V_216 -> V_331 ;
}
F_114 ( V_216 -> V_339 , V_216 -> V_340 + V_216 -> V_90 ) ;
if ( ! V_216 -> V_342 &&
( F_224 ( V_13 -> V_219 . V_229 ) <= V_368 ) )
F_202 ( 0 , V_216 -> V_339 ) ;
return 0 ;
}
int F_225 ( const struct V_1 * V_2 , unsigned int V_336 ,
T_11 V_369 , T_12 V_370 , T_12 V_242 ,
unsigned int V_371 )
{
unsigned int V_346 ;
struct V_234 * V_235 ;
struct V_12 * V_13 ;
struct V_372 * V_349 ;
int V_46 ;
V_235 = F_130 ( sizeof( * V_349 ) , V_191 ) ;
if ( ! V_235 )
return - V_53 ;
V_13 = F_226 ( V_2 ) ;
V_349 = (struct V_372 * ) F_133 ( V_235 , sizeof( * V_349 ) ) ;
F_210 ( V_349 , 0 ) ;
F_211 ( V_349 ) = F_134 ( F_212 ( V_373 , V_336 ) ) ;
V_349 -> V_374 = V_370 ;
V_349 -> V_375 = F_155 ( 0 ) ;
V_349 -> V_376 = V_369 ;
V_349 -> V_377 = F_134 ( 0 ) ;
V_346 = F_98 ( & V_13 -> V_16 , V_371 ) ;
V_349 -> V_378 = F_227 ( F_228 ( V_346 ) ) ;
V_349 -> V_379 = F_227 ( F_229 ( V_380 ) |
V_381 | F_230 ( V_371 ) ) ;
V_46 = F_176 ( V_13 , V_235 ) ;
return F_231 ( V_46 ) ;
}
int F_232 ( const struct V_1 * V_2 , unsigned int V_336 ,
const struct V_382 * V_369 , T_12 V_370 ,
unsigned int V_371 )
{
unsigned int V_346 ;
struct V_234 * V_235 ;
struct V_12 * V_13 ;
struct V_383 * V_349 ;
int V_46 ;
V_235 = F_130 ( sizeof( * V_349 ) , V_191 ) ;
if ( ! V_235 )
return - V_53 ;
V_13 = F_226 ( V_2 ) ;
V_349 = (struct V_383 * ) F_133 ( V_235 , sizeof( * V_349 ) ) ;
F_210 ( V_349 , 0 ) ;
F_211 ( V_349 ) = F_134 ( F_212 ( V_384 , V_336 ) ) ;
V_349 -> V_374 = V_370 ;
V_349 -> V_375 = F_155 ( 0 ) ;
V_349 -> V_385 = * ( T_4 * ) ( V_369 -> V_386 ) ;
V_349 -> V_387 = * ( T_4 * ) ( V_369 -> V_386 + 8 ) ;
V_349 -> V_388 = F_227 ( 0 ) ;
V_349 -> V_389 = F_227 ( 0 ) ;
V_346 = F_98 ( & V_13 -> V_16 , V_371 ) ;
V_349 -> V_378 = F_227 ( F_228 ( V_346 ) ) ;
V_349 -> V_379 = F_227 ( F_229 ( V_380 ) |
V_381 | F_230 ( V_371 ) ) ;
V_46 = F_176 ( V_13 , V_235 ) ;
return F_231 ( V_46 ) ;
}
int F_233 ( const struct V_1 * V_2 , unsigned int V_336 ,
unsigned int V_371 , bool V_390 )
{
struct V_234 * V_235 ;
struct V_12 * V_13 ;
struct V_391 * V_349 ;
int V_46 ;
V_13 = F_226 ( V_2 ) ;
V_235 = F_130 ( sizeof( * V_349 ) , V_191 ) ;
if ( ! V_235 )
return - V_53 ;
V_349 = (struct V_391 * ) F_133 ( V_235 , sizeof( * V_349 ) ) ;
F_210 ( V_349 , 0 ) ;
F_211 ( V_349 ) = F_134 ( F_212 ( V_392 , V_336 ) ) ;
V_349 -> V_393 = F_155 ( F_234 ( 0 ) | ( V_390 ? F_235 ( 1 ) :
F_235 ( 0 ) ) | F_236 ( V_371 ) ) ;
V_46 = F_176 ( V_13 , V_235 ) ;
return F_231 ( V_46 ) ;
}
unsigned int F_237 ( const unsigned short * V_394 , unsigned short V_58 ,
unsigned int * V_85 )
{
unsigned int V_19 = 0 ;
while ( V_19 < V_395 - 1 && V_394 [ V_19 + 1 ] <= V_58 )
++ V_19 ;
if ( V_85 )
* V_85 = V_19 ;
return V_394 [ V_19 ] ;
}
unsigned int F_238 ( const unsigned short * V_394 ,
unsigned short V_396 ,
unsigned short V_397 ,
unsigned short V_398 ,
unsigned int * V_399 )
{
unsigned short V_400 = V_396 + V_397 ;
unsigned short V_401 = V_398 - 1 ;
int V_402 , V_403 ;
for ( V_402 = 0 , V_403 = - 1 ; V_402 < V_395 ; V_402 ++ ) {
unsigned short V_404 = V_394 [ V_402 ] - V_396 ;
if ( ( V_404 & V_401 ) == 0 )
V_403 = V_402 ;
if ( V_402 + 1 < V_395 && V_394 [ V_402 + 1 ] > V_400 )
break;
}
if ( V_402 == V_395 )
V_402 -- ;
if ( V_403 >= 0 &&
V_402 - V_403 <= 1 )
V_402 = V_403 ;
if ( V_399 )
* V_399 = V_402 ;
return V_394 [ V_402 ] ;
}
unsigned int F_239 ( enum V_405 V_229 , unsigned int V_43 )
{
if ( F_224 ( V_229 ) <= V_368 )
return ( ( V_43 & 0x7f ) << 1 ) ;
else
return ( V_43 & 0x7f ) ;
}
unsigned int F_240 ( const struct V_1 * V_2 )
{
return F_99 ( V_2 ) -> V_68 ;
}
unsigned int F_241 ( const struct V_1 * V_2 , int V_406 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
T_1 V_407 , V_408 , V_409 , V_410 ;
V_407 = F_77 ( V_13 , V_411 ) ;
V_408 = F_77 ( V_13 , V_412 ) ;
if ( F_122 ( V_13 -> V_219 . V_229 ) ) {
V_409 = F_242 ( V_407 ) ;
V_410 = F_243 ( V_407 ) ;
} else {
V_409 = F_244 ( V_407 ) ;
V_410 = F_245 ( V_408 ) ;
}
return V_406 ? V_409 : V_410 ;
}
unsigned int F_246 ( const struct V_1 * V_2 )
{
return F_99 ( V_2 ) -> V_43 ;
}
unsigned int F_247 ( const struct V_1 * V_2 )
{
return F_99 ( V_2 ) -> V_31 ;
}
void F_248 ( struct V_413 * V_158 , struct V_414 * V_415 ,
struct V_414 * V_416 )
{
struct V_12 * V_13 = F_249 ( V_158 ) ;
F_250 ( & V_13 -> V_417 ) ;
F_251 ( V_13 , V_415 , V_416 ) ;
F_252 ( & V_13 -> V_417 ) ;
}
void F_253 ( struct V_1 * V_2 , unsigned int V_418 ,
const unsigned int * V_419 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
F_79 ( V_13 , V_420 , V_418 ) ;
F_79 ( V_13 , V_421 , F_254 ( V_419 [ 0 ] ) |
F_255 ( V_419 [ 1 ] ) | F_256 ( V_419 [ 2 ] ) |
F_257 ( V_419 [ 3 ] ) ) ;
}
int F_258 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
return F_259 ( V_13 , V_13 -> V_27 ) ;
}
static int F_260 ( struct V_12 * V_13 , T_6 V_111 , T_6 * V_422 , T_6 * V_423 )
{
T_1 V_42 = F_77 ( V_13 , V_424 ) + 24 * V_111 + 8 ;
T_4 V_425 ;
int V_46 ;
F_250 ( & V_13 -> V_426 ) ;
V_46 = F_261 ( V_13 , 0 , V_427 , V_42 ,
sizeof( V_425 ) , ( T_11 * ) & V_425 ,
V_428 ) ;
F_252 ( & V_13 -> V_426 ) ;
if ( ! V_46 ) {
* V_423 = ( F_55 ( V_425 ) >> 25 ) & 0xffff ;
* V_422 = ( F_55 ( V_425 ) >> 9 ) & 0xffff ;
}
return V_46 ;
}
int F_262 ( struct V_1 * V_2 , T_6 V_111 , T_6 V_422 ,
T_6 V_210 )
{
struct V_12 * V_13 = F_226 ( V_2 ) ;
T_6 V_429 , V_430 ;
int V_46 ;
V_46 = F_260 ( V_13 , V_111 , & V_429 , & V_430 ) ;
if ( V_46 )
goto V_51;
if ( V_422 != V_429 ) {
T_6 V_312 ;
T_1 V_264 ;
if ( V_422 >= V_429 )
V_312 = V_422 - V_429 ;
else
V_312 = V_210 - V_429 + V_422 ;
if ( F_122 ( V_13 -> V_219 . V_229 ) )
V_264 = F_263 ( V_312 ) ;
else
V_264 = F_264 ( V_312 ) ;
F_265 () ;
F_79 ( V_13 , F_78 ( V_431 ) ,
F_266 ( V_111 ) | V_264 ) ;
}
V_51:
return V_46 ;
}
int F_267 ( struct V_1 * V_2 , T_1 V_432 , T_11 * V_433 )
{
struct V_12 * V_13 ;
T_1 V_434 , V_435 , V_436 ;
T_1 V_437 , V_438 , V_439 , V_440 , V_210 ;
T_1 V_441 , V_442 , V_443 , V_444 ;
int V_46 ;
V_13 = F_226 ( V_2 ) ;
V_434 = ( ( V_432 >> 8 ) * 32 ) + V_13 -> V_445 . V_432 . V_446 ;
V_210 = F_77 ( V_13 , V_447 ) ;
V_437 = F_268 ( V_210 ) << 20 ;
V_210 = F_77 ( V_13 , V_448 ) ;
V_438 = F_269 ( V_210 ) << 20 ;
V_210 = F_77 ( V_13 , V_449 ) ;
V_439 = F_270 ( V_210 ) << 20 ;
V_441 = V_437 ;
V_442 = V_441 + V_438 ;
V_443 = V_442 + V_439 ;
if ( V_434 < V_441 ) {
V_435 = V_427 ;
V_436 = V_434 ;
} else if ( V_434 < V_442 ) {
V_435 = V_450 ;
V_436 = V_434 - V_441 ;
} else {
if ( V_434 < V_443 ) {
V_435 = V_451 ;
V_436 = V_434 - V_442 ;
} else if ( F_271 ( V_13 -> V_219 . V_229 ) ) {
V_210 = F_77 ( V_13 , V_452 ) ;
V_440 = F_272 ( V_210 ) << 20 ;
V_444 = V_443 + V_440 ;
if ( V_434 < V_444 ) {
V_435 = V_453 ;
V_436 = V_434 - V_443 ;
} else {
goto V_22;
}
} else {
goto V_22;
}
}
F_250 ( & V_13 -> V_426 ) ;
V_46 = F_261 ( V_13 , 0 , V_435 , V_436 , 32 , V_433 , V_428 ) ;
F_252 ( & V_13 -> V_426 ) ;
return V_46 ;
V_22:
F_11 ( V_13 -> V_30 , L_35 ,
V_432 , V_434 ) ;
return - V_57 ;
}
T_2 F_273 ( struct V_1 * V_2 )
{
T_1 V_454 , V_455 ;
struct V_12 * V_13 ;
V_13 = F_226 ( V_2 ) ;
V_455 = F_77 ( V_13 , V_456 ) ;
V_454 = F_274 ( F_77 ( V_13 , V_457 ) ) ;
return ( ( T_2 ) V_454 << 32 ) | ( T_2 ) V_455 ;
}
int F_275 ( struct V_1 * V_2 ,
unsigned int V_111 ,
enum V_458 V_459 ,
int V_460 ,
T_2 * V_461 ,
unsigned int * V_462 )
{
return F_276 ( F_226 ( V_2 ) ,
V_111 ,
( V_459 == V_463
? V_464
: V_465 ) ,
V_460 ,
V_461 ,
V_462 ) ;
}
static void F_277 ( struct V_466 * V_467 )
{
const struct V_468 * V_469 ;
const struct V_1 * V_44 = V_467 -> V_2 ;
if ( V_44 -> V_470 & V_471 )
V_44 = F_278 ( V_44 ) ;
V_469 = V_44 -> V_2 . V_469 ;
if ( V_469 && V_469 -> V_472 == & V_473 . V_472 )
F_279 ( F_280 ( V_469 ) , V_467 ) ;
}
static int F_281 ( struct V_474 * V_475 , unsigned long V_476 ,
void * V_124 )
{
switch ( V_476 ) {
case V_477 :
F_277 ( V_124 ) ;
break;
case V_478 :
default:
break;
}
return 0 ;
}
static void F_282 ( struct V_12 * V_13 , int V_479 )
{
T_1 V_407 , V_408 , V_409 , V_410 ;
do {
V_407 = F_77 ( V_13 , V_411 ) ;
V_408 = F_77 ( V_13 , V_412 ) ;
if ( F_122 ( V_13 -> V_219 . V_229 ) ) {
V_409 = F_242 ( V_407 ) ;
V_410 = F_243 ( V_407 ) ;
} else {
V_409 = F_244 ( V_407 ) ;
V_410 = F_245 ( V_408 ) ;
}
if ( V_409 == 0 && V_410 == 0 )
break;
F_283 ( V_480 ) ;
F_284 ( F_285 ( V_479 ) ) ;
} while ( 1 );
}
static void F_286 ( struct V_113 * V_25 )
{
unsigned long V_60 ;
F_287 ( & V_25 -> V_481 , V_60 ) ;
V_25 -> V_482 = 1 ;
F_288 ( & V_25 -> V_481 , V_60 ) ;
}
static void F_289 ( struct V_12 * V_13 , struct V_113 * V_25 )
{
F_290 ( & V_25 -> V_481 ) ;
if ( V_25 -> V_483 ) {
F_265 () ;
F_79 ( V_13 , F_78 ( V_431 ) ,
F_266 ( V_25 -> V_26 ) | F_263 ( V_25 -> V_483 ) ) ;
V_25 -> V_483 = 0 ;
}
V_25 -> V_482 = 0 ;
F_291 ( & V_25 -> V_481 ) ;
}
static void F_292 ( struct V_12 * V_13 )
{
int V_19 ;
F_89 (&adap->sge, i)
F_286 ( & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_83 (&adap->sge, i)
F_286 ( & V_13 -> V_16 . V_117 [ V_19 ] . V_25 ) ;
F_82 (adap, i)
F_286 ( & V_13 -> V_16 . V_228 [ V_19 ] . V_25 ) ;
}
static void F_293 ( struct V_12 * V_13 )
{
int V_19 ;
F_89 (&adap->sge, i)
F_289 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_83 (&adap->sge, i)
F_289 ( V_13 , & V_13 -> V_16 . V_117 [ V_19 ] . V_25 ) ;
F_82 (adap, i)
F_289 ( V_13 , & V_13 -> V_16 . V_228 [ V_19 ] . V_25 ) ;
}
static void F_294 ( struct V_12 * V_13 , enum V_484 V_125 )
{
if ( V_13 -> V_149 [ V_485 ] )
V_141 [ V_485 ] . F_295 ( V_13 -> V_149 [ V_485 ] ,
V_125 ) ;
}
static void F_296 ( struct V_359 * V_360 )
{
struct V_12 * V_13 ;
V_13 = F_60 ( V_360 , struct V_12 , V_486 ) ;
F_282 ( V_13 , V_487 ) ;
F_293 ( V_13 ) ;
F_294 ( V_13 , V_488 ) ;
if ( F_224 ( V_13 -> V_219 . V_229 ) <= V_368 )
F_297 ( V_13 , V_489 ,
V_490 | V_491 ,
V_490 | V_491 ) ;
else
F_297 ( V_13 , V_489 ,
V_491 , V_491 ) ;
}
static void F_298 ( struct V_12 * V_13 , struct V_113 * V_25 )
{
T_6 V_429 , V_430 ;
int V_46 ;
F_290 ( & V_25 -> V_481 ) ;
V_46 = F_260 ( V_13 , ( T_6 ) V_25 -> V_26 , & V_429 , & V_430 ) ;
if ( V_46 )
goto V_51;
if ( V_25 -> V_492 != V_429 ) {
T_6 V_312 ;
T_1 V_264 ;
if ( V_25 -> V_492 >= V_429 )
V_312 = V_25 -> V_492 - V_429 ;
else
V_312 = V_25 -> V_210 - V_429 + V_25 -> V_492 ;
if ( F_122 ( V_13 -> V_219 . V_229 ) )
V_264 = F_263 ( V_312 ) ;
else
V_264 = F_264 ( V_312 ) ;
F_265 () ;
F_79 ( V_13 , F_78 ( V_431 ) ,
F_266 ( V_25 -> V_26 ) | V_264 ) ;
}
V_51:
V_25 -> V_482 = 0 ;
V_25 -> V_483 = 0 ;
F_291 ( & V_25 -> V_481 ) ;
if ( V_46 )
F_299 ( V_13 , L_36 ) ;
}
static void F_300 ( struct V_12 * V_13 )
{
int V_19 ;
F_89 (&adap->sge, i)
F_298 ( V_13 , & V_13 -> V_16 . V_17 [ V_19 ] . V_25 ) ;
F_83 (&adap->sge, i)
F_298 ( V_13 , & V_13 -> V_16 . V_117 [ V_19 ] . V_25 ) ;
F_82 (adap, i)
F_298 ( V_13 , & V_13 -> V_16 . V_228 [ V_19 ] . V_25 ) ;
}
static void F_301 ( struct V_359 * V_360 )
{
struct V_12 * V_13 ;
V_13 = F_60 ( V_360 , struct V_12 , V_493 ) ;
if ( F_122 ( V_13 -> V_219 . V_229 ) ) {
F_282 ( V_13 , V_487 ) ;
F_294 ( V_13 , V_494 ) ;
F_282 ( V_13 , V_487 ) ;
F_300 ( V_13 ) ;
F_282 ( V_13 , V_487 ) ;
F_293 ( V_13 ) ;
F_294 ( V_13 , V_488 ) ;
} else if ( F_271 ( V_13 -> V_219 . V_229 ) ) {
T_1 V_495 = F_77 ( V_13 , 0x010ac ) ;
T_6 V_111 = ( V_495 >> 15 ) & 0x1ffff ;
T_6 V_496 = V_495 & 0x1fff ;
T_2 V_497 ;
unsigned int V_498 ;
int V_46 ;
V_46 = F_276 ( V_13 , V_111 , V_464 ,
0 , & V_497 , & V_498 ) ;
if ( V_46 )
F_11 ( V_13 -> V_30 , L_37
L_38 , V_111 , V_496 ) ;
else
F_302 ( F_264 ( V_496 ) | F_266 ( V_498 ) ,
V_13 -> V_499 + V_497 + V_500 ) ;
F_297 ( V_13 , 0x10b0 , 1 << 15 , 1 << 15 ) ;
}
if ( F_224 ( V_13 -> V_219 . V_229 ) <= V_368 )
F_297 ( V_13 , V_501 , V_502 , 0 ) ;
}
void F_303 ( struct V_12 * V_13 )
{
if ( F_122 ( V_13 -> V_219 . V_229 ) ) {
F_292 ( V_13 ) ;
F_294 ( V_13 , V_503 ) ;
F_297 ( V_13 , V_489 ,
V_490 | V_491 , 0 ) ;
F_214 ( V_13 -> V_357 , & V_13 -> V_486 ) ;
}
}
void F_304 ( struct V_12 * V_13 )
{
if ( F_122 ( V_13 -> V_219 . V_229 ) ) {
F_292 ( V_13 ) ;
F_294 ( V_13 , V_503 ) ;
}
F_214 ( V_13 -> V_357 , & V_13 -> V_493 ) ;
}
static void F_305 ( struct V_12 * V_13 , unsigned int V_142 )
{
void * V_504 ;
struct V_505 V_506 ;
unsigned short V_19 ;
V_506 . V_158 = V_13 -> V_158 ;
V_506 . V_28 = V_13 -> V_28 ;
V_506 . V_82 = V_13 -> V_82 ;
V_506 . V_87 = & V_13 -> V_87 ;
V_506 . V_507 = V_13 -> V_34 ;
V_506 . V_508 = & V_13 -> V_445 ;
V_506 . V_394 = V_13 -> V_219 . V_394 ;
if ( V_142 == V_485 ) {
V_506 . V_509 = V_13 -> V_16 . V_225 ;
V_506 . V_510 = V_13 -> V_16 . V_227 ;
V_506 . V_511 = V_13 -> V_16 . V_224 ;
V_506 . V_512 = V_13 -> V_16 . V_226 ;
} else if ( V_142 == V_513 ) {
V_506 . V_509 = V_13 -> V_16 . V_221 ;
V_506 . V_511 = V_13 -> V_16 . V_218 ;
} else if ( V_142 == V_514 ) {
V_506 . V_509 = V_13 -> V_16 . V_223 ;
V_506 . V_511 = V_13 -> V_16 . V_222 ;
}
V_506 . V_515 = V_13 -> V_16 . V_218 ;
V_506 . V_516 = V_13 -> V_219 . V_220 ;
V_506 . V_220 = V_13 -> V_219 . V_220 ;
V_506 . V_517 = V_13 -> V_219 . V_518 ;
V_506 . V_519 = V_13 -> V_219 . V_229 ;
V_506 . V_520 = F_306 ( F_77 ( V_13 , V_521 ) ) ;
V_506 . V_522 = F_77 ( V_13 , V_420 ) ;
V_506 . V_523 = F_77 ( V_13 , V_421 ) ;
V_506 . V_524 = F_77 ( V_13 , V_525 ) ;
V_506 . V_526 = & V_13 -> V_526 ;
V_506 . V_527 = 1000000000 / V_13 -> V_219 . V_528 . V_529 ;
V_506 . V_530 = 1 << V_13 -> V_219 . V_16 . V_531 ;
V_506 . V_532 = 1 << V_13 -> V_219 . V_16 . V_533 ;
V_506 . V_534 = V_13 -> V_219 . V_535 . V_536 ;
for ( V_19 = 0 ; V_19 < V_537 ; V_19 ++ )
V_506 . V_538 [ V_19 ] = V_19 ;
V_506 . V_539 = V_13 -> V_540 + F_78 ( V_203 ) ;
V_506 . V_541 = V_13 -> V_540 + F_78 ( V_431 ) ;
V_506 . V_542 = V_13 -> V_219 . V_542 ;
V_506 . V_543 = V_543 ;
V_506 . V_544 = V_13 -> V_16 . V_545 ;
V_506 . V_546 = V_13 -> V_16 . V_547 ;
V_506 . V_548 = V_13 -> V_16 . V_549 ;
V_506 . V_550 = V_13 -> V_60 & V_551 ;
V_506 . V_552 = V_13 -> V_219 . V_552 ;
V_506 . V_553 = V_13 -> V_219 . V_553 ;
V_506 . V_554 = V_13 -> V_219 . V_554 ;
V_506 . V_555 = F_307 ( V_13 -> V_30 ) ;
V_504 = V_141 [ V_142 ] . F_308 ( & V_506 ) ;
if ( F_309 ( V_504 ) ) {
F_310 ( V_13 -> V_30 ,
L_39 ,
V_556 [ V_142 ] , F_311 ( V_504 ) ) ;
return;
}
V_13 -> V_149 [ V_142 ] = V_504 ;
if ( ! V_557 ) {
F_312 ( & V_558 ) ;
V_557 = true ;
}
if ( V_13 -> V_60 & V_202 )
V_141 [ V_142 ] . F_313 ( V_504 , V_559 ) ;
}
static void F_314 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_250 ( & V_560 ) ;
F_315 ( & V_13 -> V_561 , & V_562 ) ;
F_252 ( & V_560 ) ;
F_316 ( & V_563 ) ;
F_28 ( & V_13 -> V_564 , & V_565 ) ;
for ( V_19 = 0 ; V_19 < V_566 ; V_19 ++ )
if ( V_141 [ V_19 ] . F_308 )
F_305 ( V_13 , V_19 ) ;
F_317 ( & V_563 ) ;
}
static void F_318 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
F_316 ( & V_563 ) ;
F_32 ( & V_13 -> V_564 ) ;
for ( V_19 = 0 ; V_19 < V_566 ; V_19 ++ )
if ( V_13 -> V_149 [ V_19 ] ) {
V_141 [ V_19 ] . F_313 ( V_13 -> V_149 [ V_19 ] ,
V_567 ) ;
V_13 -> V_149 [ V_19 ] = NULL ;
}
if ( V_557 && F_319 ( & V_565 ) ) {
F_320 ( & V_558 ) ;
V_557 = false ;
}
F_317 ( & V_563 ) ;
F_250 ( & V_560 ) ;
F_321 ( & V_13 -> V_561 ) ;
F_252 ( & V_560 ) ;
}
static void F_322 ( struct V_12 * V_13 , enum V_568 V_569 )
{
unsigned int V_19 ;
F_316 ( & V_563 ) ;
for ( V_19 = 0 ; V_19 < V_566 ; V_19 ++ )
if ( V_13 -> V_149 [ V_19 ] )
V_141 [ V_19 ] . F_313 ( V_13 -> V_149 [ V_19 ] , V_569 ) ;
F_317 ( & V_563 ) ;
}
int F_323 ( enum V_570 type , const struct V_571 * V_6 )
{
int V_46 = 0 ;
struct V_12 * V_13 ;
if ( type >= V_566 )
return - V_57 ;
F_316 ( & V_563 ) ;
if ( V_141 [ type ] . F_308 ) {
V_46 = - V_572 ;
goto V_51;
}
V_141 [ type ] = * V_6 ;
F_21 (adap, &adapter_list, list_node)
F_305 ( V_13 , type ) ;
V_51: F_317 ( & V_563 ) ;
return V_46 ;
}
int F_324 ( enum V_570 type )
{
struct V_12 * V_13 ;
if ( type >= V_566 )
return - V_57 ;
F_316 ( & V_563 ) ;
F_21 (adap, &adapter_list, list_node)
V_13 -> V_149 [ type ] = NULL ;
V_141 [ type ] . F_308 = NULL ;
F_317 ( & V_563 ) ;
return 0 ;
}
static int F_325 ( struct V_474 * V_573 ,
unsigned long V_476 , void * V_124 )
{
struct V_574 * V_575 = V_124 ;
struct V_1 * V_576 = V_575 -> V_577 -> V_2 ;
const struct V_468 * V_469 = NULL ;
#if F_326 ( V_578 )
struct V_12 * V_13 ;
#endif
if ( V_576 -> V_470 & V_471 )
V_576 = F_278 ( V_576 ) ;
#if F_326 ( V_578 )
if ( V_576 -> V_60 & V_579 ) {
F_21 (adap, &adapter_list, list_node) {
switch ( V_476 ) {
case V_580 :
F_327 ( V_13 -> V_34 [ 0 ] ,
( const T_1 * ) V_575 , 1 ) ;
break;
case V_581 :
F_328 ( V_13 -> V_34 [ 0 ] ,
( const T_1 * ) V_575 , 1 ) ;
break;
default:
break;
}
}
return V_582 ;
}
#endif
if ( V_576 )
V_469 = V_576 -> V_2 . V_469 ;
if ( V_469 && V_469 -> V_472 == & V_473 . V_472 ) {
switch ( V_476 ) {
case V_580 :
F_327 ( V_576 , ( const T_1 * ) V_575 , 1 ) ;
break;
case V_581 :
F_328 ( V_576 , ( const T_1 * ) V_575 , 1 ) ;
break;
default:
break;
}
}
return V_582 ;
}
static void F_329 ( const struct V_12 * V_13 )
{
int V_19 ;
struct V_1 * V_2 ;
int V_46 ;
F_330 () ;
for ( V_19 = 0 ; V_19 < V_583 ; V_19 ++ ) {
V_2 = V_13 -> V_34 [ V_19 ] ;
V_46 = 0 ;
if ( V_2 )
V_46 = F_331 ( V_2 ) ;
if ( V_46 < 0 )
break;
}
F_332 () ;
}
static int F_333 ( struct V_12 * V_13 )
{
int V_22 ;
V_22 = F_113 ( V_13 ) ;
if ( V_22 )
goto V_51;
V_22 = F_96 ( V_13 ) ;
if ( V_22 )
goto V_584;
if ( V_13 -> V_60 & V_157 ) {
F_81 ( V_13 ) ;
V_22 = F_88 ( V_13 -> V_170 [ 0 ] . V_38 , F_76 , 0 ,
V_13 -> V_170 [ 0 ] . V_171 , V_13 ) ;
if ( V_22 )
goto V_585;
V_22 = F_87 ( V_13 ) ;
if ( V_22 ) {
F_90 ( V_13 -> V_170 [ 0 ] . V_38 , V_13 ) ;
goto V_585;
}
} else {
V_22 = F_88 ( V_13 -> V_158 -> V_160 , F_334 ( V_13 ) ,
( V_13 -> V_60 & V_159 ) ? 0 : V_586 ,
V_13 -> V_34 [ 0 ] -> V_9 , V_13 ) ;
if ( V_22 )
goto V_585;
}
F_106 ( V_13 ) ;
F_335 ( V_13 ) ;
F_336 ( V_13 ) ;
V_13 -> V_60 |= V_202 ;
F_322 ( V_13 , V_559 ) ;
#if F_326 ( V_587 )
F_329 ( V_13 ) ;
#endif
F_337 ( & V_13 -> V_55 ) ;
V_51:
return V_22 ;
V_585:
F_11 ( V_13 -> V_30 , L_40 , V_22 ) ;
V_584:
F_115 ( V_13 ) ;
goto V_51;
}
static void F_338 ( struct V_12 * V_12 )
{
F_339 ( & V_12 -> V_358 ) ;
F_339 ( & V_12 -> V_486 ) ;
F_339 ( & V_12 -> V_493 ) ;
V_12 -> V_356 = false ;
V_12 -> V_354 = NULL ;
F_340 ( V_12 ) ;
F_115 ( V_12 ) ;
V_12 -> V_60 &= ~ V_202 ;
}
static int F_341 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_17 ( V_2 ) ;
if ( ! ( V_12 -> V_60 & V_202 ) ) {
V_22 = F_333 ( V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_39 ( V_2 ) ;
if ( ! V_22 )
F_342 ( V_2 ) ;
return V_22 ;
}
static int F_343 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_11 -> V_12 ;
F_344 ( V_2 ) ;
F_17 ( V_2 ) ;
return F_345 ( V_12 , V_12 -> V_28 , V_11 -> V_43 , false , false ) ;
}
static int F_346 ( struct V_80 * V_81 )
{
if ( V_81 -> V_588 )
return - V_589 ;
if ( V_81 -> V_98 )
return - V_572 ;
return 0 ;
}
static int F_347 ( struct V_12 * V_12 , unsigned int V_233 )
{
struct V_80 * V_81 ;
int V_46 ;
if ( V_233 >= V_12 -> V_87 . V_89 + V_12 -> V_87 . V_90 )
return - V_57 ;
V_81 = & V_12 -> V_87 . V_92 [ V_233 ] ;
V_46 = F_346 ( V_81 ) ;
if ( V_46 )
return V_46 ;
if ( V_81 -> V_99 )
return F_174 ( V_12 , V_233 ) ;
return 0 ;
}
int F_348 ( const struct V_1 * V_2 , unsigned int V_336 ,
T_11 V_369 , T_12 V_370 , T_12 V_242 ,
unsigned int V_371 , unsigned char V_34 , unsigned char V_266 )
{
int V_46 ;
struct V_80 * V_81 ;
struct V_12 * V_13 ;
int V_19 ;
T_3 * V_264 ;
V_13 = F_226 ( V_2 ) ;
V_336 -= V_13 -> V_87 . V_344 ;
V_336 += V_13 -> V_87 . V_89 ;
V_81 = & V_13 -> V_87 . V_92 [ V_336 ] ;
V_46 = F_346 ( V_81 ) ;
if ( V_46 )
return V_46 ;
if ( V_81 -> V_99 )
F_50 ( V_13 , V_81 ) ;
memset ( & V_81 -> V_239 , 0 , sizeof( struct V_590 ) ) ;
V_81 -> V_239 . V_264 . V_293 = F_349 ( V_370 ) ;
V_81 -> V_239 . V_266 . V_293 = ~ 0 ;
V_264 = ( T_3 * ) & V_369 ;
if ( ( V_264 [ 0 ] | V_264 [ 1 ] | V_264 [ 2 ] | V_264 [ 3 ] ) != 0 ) {
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_81 -> V_239 . V_264 . V_288 [ V_19 ] = V_264 [ V_19 ] ;
V_81 -> V_239 . V_266 . V_288 [ V_19 ] = ~ 0 ;
}
if ( V_13 -> V_219 . V_535 . V_536 & V_591 ) {
V_81 -> V_239 . V_264 . V_276 = V_34 ;
V_81 -> V_239 . V_266 . V_276 = V_266 ;
}
}
if ( V_13 -> V_219 . V_535 . V_536 & V_592 ) {
V_81 -> V_239 . V_264 . V_279 = V_593 ;
V_81 -> V_239 . V_266 . V_279 = ~ 0 ;
}
V_81 -> V_239 . V_253 = 1 ;
V_81 -> V_239 . V_249 = V_371 ;
V_81 -> V_588 = 1 ;
V_81 -> V_239 . V_251 = 1 ;
V_46 = F_129 ( V_13 , V_336 ) ;
if ( V_46 ) {
F_50 ( V_13 , V_81 ) ;
return V_46 ;
}
return 0 ;
}
int F_350 ( const struct V_1 * V_2 , unsigned int V_336 ,
unsigned int V_371 , bool V_390 )
{
int V_46 ;
struct V_80 * V_81 ;
struct V_12 * V_13 ;
V_13 = F_226 ( V_2 ) ;
V_336 -= V_13 -> V_87 . V_344 ;
V_336 += V_13 -> V_87 . V_89 ;
V_81 = & V_13 -> V_87 . V_92 [ V_336 ] ;
V_81 -> V_588 = 0 ;
V_46 = F_347 ( V_13 , V_336 ) ;
if ( V_46 )
return V_46 ;
return 0 ;
}
static struct V_594 * F_351 ( struct V_1 * V_2 ,
struct V_594 * V_595 )
{
struct V_596 V_151 ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
struct V_12 * V_12 = V_6 -> V_12 ;
F_250 ( & V_12 -> V_417 ) ;
if ( ! F_352 ( V_2 ) ) {
F_252 ( & V_12 -> V_417 ) ;
return V_595 ;
}
F_353 ( V_12 , V_6 -> V_68 , & V_151 ,
& V_6 -> V_597 ) ;
F_252 ( & V_12 -> V_417 ) ;
V_595 -> V_598 = V_151 . V_599 ;
V_595 -> V_600 = V_151 . V_601 ;
V_595 -> V_602 = V_151 . V_603 ;
V_595 -> V_604 = V_151 . V_605 ;
V_595 -> V_606 = V_151 . V_607 ;
V_595 -> V_608 = V_151 . V_609 + V_151 . V_610 +
V_151 . V_611 ;
V_595 -> V_612 = 0 ;
V_595 -> V_613 = V_151 . V_614 ;
V_595 -> V_615 = V_151 . V_616 ;
V_595 -> V_617 = V_151 . V_618 + V_151 . V_619 +
V_151 . V_620 + V_151 . V_621 +
V_151 . V_622 + V_151 . V_623 +
V_151 . V_624 + V_151 . V_625 ;
V_595 -> V_626 = 0 ;
V_595 -> V_627 = 0 ;
V_595 -> V_628 = 0 ;
V_595 -> V_629 = 0 ;
V_595 -> V_630 = 0 ;
V_595 -> V_631 = 0 ;
V_595 -> V_632 = V_151 . V_633 ;
V_595 -> V_634 = V_151 . V_616 + V_151 . V_614 +
V_595 -> V_608 + V_151 . V_635 + V_595 -> V_617 ;
return V_595 ;
}
static int F_354 ( struct V_1 * V_2 , struct V_636 * V_349 , int V_125 )
{
unsigned int V_27 ;
int V_46 = 0 , V_637 , V_638 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_639 * V_124 = (struct V_639 * ) & V_349 -> V_640 ;
switch ( V_125 ) {
case V_641 :
if ( V_11 -> V_642 < 0 )
return - V_643 ;
V_124 -> V_644 = V_11 -> V_642 ;
break;
case V_645 :
case V_646 :
if ( F_355 ( V_124 -> V_644 ) ) {
V_637 = F_356 ( V_124 -> V_644 ) ;
V_638 = F_357 ( V_124 -> V_644 ) ;
} else if ( V_124 -> V_644 < 32 ) {
V_637 = V_124 -> V_644 ;
V_638 = 0 ;
V_124 -> V_647 &= 0x1f ;
} else
return - V_57 ;
V_27 = V_11 -> V_12 -> V_28 ;
if ( V_125 == V_645 )
V_46 = F_358 ( V_11 -> V_12 , V_27 , V_637 , V_638 ,
V_124 -> V_647 , & V_124 -> V_648 ) ;
else
V_46 = F_359 ( V_11 -> V_12 , V_27 , V_637 , V_638 ,
V_124 -> V_647 , V_124 -> V_649 ) ;
break;
case V_650 :
return F_360 ( V_349 -> V_640 , & V_11 -> V_651 ,
sizeof( V_11 -> V_651 ) ) ?
- V_652 : 0 ;
case V_653 :
if ( F_361 ( & V_11 -> V_651 , V_349 -> V_640 ,
sizeof( V_11 -> V_651 ) ) )
return - V_652 ;
switch ( V_11 -> V_651 . V_654 ) {
case V_655 :
V_11 -> V_656 = false ;
break;
case V_657 :
V_11 -> V_656 = true ;
break;
default:
V_11 -> V_651 . V_654 = V_655 ;
return - V_658 ;
}
return F_360 ( V_349 -> V_640 , & V_11 -> V_651 ,
sizeof( V_11 -> V_651 ) ) ?
- V_652 : 0 ;
default:
return - V_643 ;
}
return V_46 ;
}
static void F_362 ( struct V_1 * V_2 )
{
F_35 ( V_2 , - 1 , false ) ;
}
static int F_363 ( struct V_1 * V_2 , int V_659 )
{
int V_46 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( V_659 < 81 || V_659 > V_660 )
return - V_57 ;
V_46 = F_38 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_43 , V_659 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_46 )
V_2 -> V_58 = V_659 ;
return V_46 ;
}
static int F_364 ( struct V_1 * V_2 , void * V_6 )
{
int V_46 ;
struct V_661 * V_42 = V_6 ;
struct V_5 * V_11 = F_4 ( V_2 ) ;
if ( ! F_365 ( V_42 -> V_662 ) )
return - V_663 ;
V_46 = F_40 ( V_11 -> V_12 , V_11 -> V_12 -> V_28 , V_11 -> V_43 ,
V_11 -> V_66 , V_42 -> V_662 , true , true ) ;
if ( V_46 < 0 )
return V_46 ;
memcpy ( V_2 -> V_67 , V_42 -> V_662 , V_2 -> V_664 ) ;
V_11 -> V_66 = V_46 ;
return 0 ;
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = F_4 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_60 & V_157 ) {
int V_19 ;
struct V_189 * V_665 = & V_13 -> V_16 . V_181 [ V_11 -> V_18 ] ;
for ( V_19 = V_11 -> V_20 ; V_19 ; V_19 -- , V_665 ++ )
V_179 ( 0 , & V_665 -> V_147 ) ;
} else
F_334 ( V_13 ) ( 0 , V_13 ) ;
}
void F_367 ( struct V_12 * V_13 )
{
F_297 ( V_13 , V_666 , V_667 , 0 ) ;
F_105 ( V_13 ) ;
F_368 ( V_13 -> V_30 , L_41 ) ;
}
static void F_369 ( struct V_12 * V_13 )
{
T_1 V_668 = F_370 ( V_13 ) ;
F_371 ( V_13 , V_668 , V_669 ) ;
}
static void F_372 ( struct V_12 * V_13 )
{
if ( V_13 -> V_445 . V_670 . V_210 ) {
T_1 V_446 ;
unsigned int V_671 ;
V_446 = F_373 ( V_13 , V_672 ) ;
V_446 &= V_673 ;
V_446 += F_374 ( V_13 -> V_158 , & V_13 -> V_445 ) ;
V_671 = F_375 ( V_13 -> V_445 . V_670 . V_210 ) >> 10 ;
F_79 ( V_13 ,
F_376 ( V_674 , 3 ) ,
V_446 | F_377 ( 1 ) | F_378 ( F_379 ( V_671 ) ) ) ;
F_79 ( V_13 ,
F_376 ( V_675 , 3 ) ,
V_13 -> V_445 . V_670 . V_446 ) ;
F_77 ( V_13 ,
F_376 ( V_675 , 3 ) ) ;
}
}
static int F_380 ( struct V_12 * V_13 , struct V_676 * V_677 )
{
T_1 V_161 ;
int V_46 ;
memset ( V_677 , 0 , sizeof( * V_677 ) ) ;
V_677 -> V_678 = F_134 ( F_381 ( V_679 ) |
V_680 | V_681 ) ;
V_677 -> V_682 = F_134 ( F_382 ( * V_677 ) ) ;
V_46 = F_383 ( V_13 , V_13 -> V_27 , V_677 , sizeof( * V_677 ) , V_677 ) ;
if ( V_46 < 0 )
return V_46 ;
V_677 -> V_678 = F_134 ( F_381 ( V_679 ) |
V_680 | V_683 ) ;
V_46 = F_383 ( V_13 , V_13 -> V_27 , V_677 , sizeof( * V_677 ) , NULL ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_384 ( V_13 , V_13 -> V_28 ,
V_684 ,
V_685 |
V_686 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_385 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , V_13 -> V_16 . V_212 , 64 ,
V_687 , 0 , 0 , 4 , 0xf , 0xf , 16 , V_688 ,
V_688 ) ;
if ( V_46 < 0 )
return V_46 ;
F_386 ( V_13 ) ;
F_79 ( V_13 , V_689 , 0x64f8849 ) ;
F_79 ( V_13 , V_690 , F_254 ( V_691 - 12 ) ) ;
F_79 ( V_13 , V_692 , V_693 ) ;
V_161 = F_77 ( V_13 , V_694 ) ;
F_79 ( V_13 , V_694 , V_161 & ~ V_695 ) ;
V_13 -> V_219 . V_535 . V_696 = 0xE4 ;
F_79 ( V_13 , V_697 ,
F_387 ( V_13 -> V_219 . V_535 . V_696 ) ) ;
V_161 = 0x84218421 ;
F_388 ( V_13 , V_692 , V_694 ,
& V_161 , 1 , V_698 ) ;
F_388 ( V_13 , V_692 , V_694 ,
& V_161 , 1 , V_699 ) ;
F_388 ( V_13 , V_692 , V_694 ,
& V_161 , 1 , V_700 ) ;
#define F_389 16
if ( F_390 ( V_13 ) ) {
F_79 ( V_13 , V_701 ,
F_391 ( F_389 ) |
F_392 ( F_389 ) |
F_393 ( F_389 ) |
F_394 ( F_389 ) ) ;
F_79 ( V_13 , V_702 ,
F_391 ( F_389 ) |
F_392 ( F_389 ) |
F_393 ( F_389 ) |
F_394 ( F_389 ) ) ;
}
return F_395 ( V_13 , V_13 -> V_28 ) ;
}
static int F_396 ( struct V_12 * V_12 )
{
F_397 ( V_12 , V_703 , V_704 ) ;
if ( V_705 != 2 && V_705 != 0 ) {
F_11 ( & V_12 -> V_158 -> V_2 ,
L_42 ,
V_705 ) ;
V_705 = 2 ;
}
F_297 ( V_12 , V_666 ,
F_398 ( V_706 ) ,
F_398 ( V_705 ) ) ;
F_399 ( V_12 , V_693 ,
V_695 , 0 ) ;
return 0 ;
}
static int F_400 ( const T_3 * V_707 ,
T_8 V_708 )
{
int V_434 ;
#define F_401 ( T_13 ) (((__p)[0] << 8) | (__p)[1])
#define F_402 ( T_13 ) ((__p)[0] | ((__p)[1] << 8))
#define F_403 ( T_13 ) (le16(__p) | ((__p)[2] << 16))
V_434 = F_403 ( V_707 + 0x8 ) << 12 ;
V_434 = F_403 ( V_707 + V_434 + 0xa ) ;
return F_401 ( V_707 + V_434 + 0x27e ) ;
#undef F_401
#undef F_402
#undef F_403
}
static struct V_709 * F_404 ( int V_710 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_711 ) ; V_19 ++ ) {
if ( V_711 [ V_19 ] . V_712 == V_710 )
return & V_711 [ V_19 ] ;
}
return NULL ;
}
static int F_405 ( struct V_12 * V_13 )
{
const struct V_713 * V_714 ;
int V_46 ;
struct V_709 * V_715 ;
V_715 = F_404 ( V_13 -> V_158 -> V_468 ) ;
if ( ! V_715 ) {
F_310 ( V_13 -> V_30 ,
L_43 ) ;
return - V_643 ;
}
V_46 = F_406 ( & V_714 , V_715 -> V_716 ,
V_13 -> V_30 ) ;
if ( V_46 < 0 ) {
F_11 ( V_13 -> V_30 , L_44
L_45 ,
V_715 -> V_716 , - V_46 ) ;
if ( V_715 -> V_717 ) {
int V_718 = 0 ;
F_407 ( V_13 , & V_718 ) ;
F_310 ( V_13 -> V_30 , L_46
L_47 , V_718 ) ;
V_46 = 0 ;
}
return V_46 ;
}
V_46 = F_408 ( V_13 , V_669 , & V_13 -> V_426 ,
V_715 -> V_719 ,
( T_3 * ) V_714 -> V_124 , V_714 -> V_210 ) ;
if ( V_46 < 0 )
F_11 ( V_13 -> V_30 , L_48 ,
- V_46 ) ;
else if ( V_46 > 0 ) {
int V_720 = 0 ;
if ( V_715 -> V_719 )
V_720 = V_715 -> V_719 ( V_714 -> V_124 ,
V_714 -> V_210 ) ;
F_409 ( V_13 -> V_30 , L_49
L_50 ,
V_715 -> V_716 , V_720 ) ;
}
F_410 ( V_714 ) ;
return V_46 ;
}
static int F_411 ( struct V_12 * V_12 , int V_721 )
{
struct V_676 V_722 ;
const struct V_713 * V_723 ;
unsigned long V_724 = 0 , V_725 = 0 ;
T_1 V_726 , V_727 , V_728 ;
int V_46 ;
int V_729 = 0 ;
char * V_730 , V_731 [ 256 ] ;
char * V_732 = NULL ;
if ( V_721 ) {
V_46 = F_412 ( V_12 , V_12 -> V_27 ,
V_733 | V_734 ) ;
if ( V_46 < 0 )
goto V_735;
}
if ( F_413 ( V_12 -> V_158 -> V_468 ) ) {
V_46 = F_405 ( V_12 ) ;
if ( V_46 < 0 )
goto V_735;
}
switch ( F_224 ( V_12 -> V_219 . V_229 ) ) {
case V_736 :
V_730 = V_737 ;
break;
case V_368 :
V_730 = V_738 ;
break;
case V_739 :
V_730 = V_740 ;
break;
default:
F_11 ( V_12 -> V_30 , L_51 ,
V_12 -> V_158 -> V_468 ) ;
V_46 = - V_57 ;
goto V_735;
}
V_46 = F_414 ( & V_723 , V_730 , V_12 -> V_30 ) ;
if ( V_46 < 0 ) {
V_732 = L_52 ;
V_724 = V_741 ;
V_725 = F_415 ( V_12 ) ;
} else {
T_1 V_219 [ 7 ] , V_264 [ 7 ] ;
sprintf ( V_731 ,
L_53 , V_730 ) ;
V_732 = V_731 ;
if ( V_723 -> V_210 >= V_742 )
V_46 = - V_53 ;
else {
V_219 [ 0 ] = ( F_7 ( V_743 ) |
F_8 ( V_744 ) ) ;
V_46 = F_416 ( V_12 , V_12 -> V_27 ,
V_12 -> V_28 , 0 , 1 , V_219 , V_264 ) ;
if ( V_46 == 0 ) {
T_8 V_745 = V_723 -> V_210 & 0x3 ;
T_8 V_210 = V_723 -> V_210 & ~ 0x3 ;
T_11 * V_124 = ( T_11 * ) V_723 -> V_124 ;
V_724 = F_417 ( V_264 [ 0 ] ) ;
V_725 = F_418 ( V_264 [ 0 ] ) << 16 ;
F_250 ( & V_12 -> V_426 ) ;
V_46 = F_261 ( V_12 , 0 , V_724 , V_725 ,
V_210 , V_124 , V_746 ) ;
if ( V_46 == 0 && V_745 != 0 ) {
union {
T_11 V_747 ;
char V_748 [ 4 ] ;
} V_749 ;
int V_19 ;
V_749 . V_747 = V_124 [ V_210 >> 2 ] ;
for ( V_19 = V_745 ; V_19 < 4 ; V_19 ++ )
V_749 . V_748 [ V_19 ] = 0 ;
V_46 = F_261 ( V_12 , 0 , V_724 ,
V_725 + V_210 ,
4 , & V_749 . V_747 ,
V_746 ) ;
}
F_252 ( & V_12 -> V_426 ) ;
}
}
F_410 ( V_723 ) ;
if ( V_46 )
goto V_735;
}
memset ( & V_722 , 0 , sizeof( V_722 ) ) ;
V_722 . V_678 =
F_134 ( F_381 ( V_679 ) |
V_680 |
V_681 ) ;
V_722 . V_682 =
F_134 ( V_750 |
F_419 ( V_724 ) |
F_420 ( V_725 >> 16 ) |
F_382 ( V_722 ) ) ;
V_46 = F_383 ( V_12 , V_12 -> V_27 , & V_722 , sizeof( V_722 ) ,
& V_722 ) ;
if ( V_46 == - V_751 ) {
memset ( & V_722 , 0 , sizeof( V_722 ) ) ;
V_722 . V_678 =
F_134 ( F_381 ( V_679 ) |
V_680 |
V_681 ) ;
V_722 . V_682 = F_134 ( F_382 ( V_722 ) ) ;
V_46 = F_383 ( V_12 , V_12 -> V_27 , & V_722 ,
sizeof( V_722 ) , & V_722 ) ;
V_732 = L_54 ;
}
V_729 = 1 ;
if ( V_46 < 0 )
goto V_735;
V_726 = F_48 ( V_722 . V_726 ) ;
V_727 = F_48 ( V_722 . V_727 ) ;
V_728 = F_48 ( V_722 . V_728 ) ;
if ( V_727 != V_728 )
F_310 ( V_12 -> V_30 , L_55\
L_56 ,
V_727 , V_728 ) ;
V_722 . V_678 =
F_134 ( F_381 ( V_679 ) |
V_680 |
V_683 ) ;
V_722 . V_682 = F_134 ( F_382 ( V_722 ) ) ;
V_46 = F_383 ( V_12 , V_12 -> V_27 , & V_722 , sizeof( V_722 ) ,
NULL ) ;
if ( V_46 < 0 )
goto V_735;
V_46 = F_396 ( V_12 ) ;
if ( V_46 < 0 )
goto V_735;
V_46 = F_421 ( V_12 , V_12 -> V_27 ) ;
if ( V_46 < 0 )
goto V_735;
F_409 ( V_12 -> V_30 , L_57\
L_58 ,
V_732 , V_726 , V_728 ) ;
return 0 ;
V_735:
if ( V_729 && V_46 != - V_751 )
F_310 ( V_12 -> V_30 , L_59 ,
V_732 , - V_46 ) ;
return V_46 ;
}
static struct V_752 * F_422 ( int V_229 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_753 ) ; V_19 ++ ) {
if ( V_753 [ V_19 ] . V_229 == V_229 )
return & V_753 [ V_19 ] ;
}
return NULL ;
}
static int F_423 ( struct V_12 * V_13 )
{
int V_46 ;
T_1 V_161 , V_754 ;
enum V_755 V_72 ;
T_1 V_219 [ 7 ] , V_264 [ 7 ] ;
struct V_676 V_722 ;
int V_721 = 1 ;
V_46 = F_424 ( V_13 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_425 ( V_13 , V_13 -> V_27 , V_13 -> V_27 , V_756 , & V_72 ) ;
if ( V_46 < 0 ) {
F_11 ( V_13 -> V_30 , L_60 ,
V_46 ) ;
return V_46 ;
}
if ( V_46 == V_13 -> V_27 )
V_13 -> V_60 |= V_165 ;
F_426 ( V_13 , & V_13 -> V_219 . V_542 ) ;
F_427 ( V_13 , & V_13 -> V_219 . V_757 ) ;
V_46 = F_428 ( V_13 ) ;
if ( V_46 )
V_72 = V_758 ;
if ( ( V_13 -> V_60 & V_165 ) && V_72 != V_759 ) {
struct V_752 * V_752 ;
struct V_760 * V_761 ;
const struct V_713 * V_762 ;
const T_3 * V_763 = NULL ;
unsigned int V_764 = 0 ;
V_752 = F_422 ( F_224 ( V_13 -> V_219 . V_229 ) ) ;
if ( V_752 == NULL ) {
F_11 ( V_13 -> V_30 ,
L_61 ,
F_224 ( V_13 -> V_219 . V_229 ) ) ;
return - V_57 ;
}
V_761 = F_125 ( sizeof( * V_761 ) ) ;
V_46 = F_414 ( & V_762 , V_752 -> V_765 ,
V_13 -> V_30 ) ;
if ( V_46 < 0 ) {
F_11 ( V_13 -> V_30 ,
L_62 ,
V_752 -> V_765 , V_46 ) ;
} else {
V_763 = V_762 -> V_124 ;
V_764 = V_762 -> V_210 ;
}
V_46 = F_429 ( V_13 , V_752 , V_763 , V_764 , V_761 ,
V_72 , & V_721 ) ;
F_410 ( V_762 ) ;
F_127 ( V_761 ) ;
if ( V_46 < 0 )
goto V_735;
}
V_46 = F_430 ( V_13 , & V_13 -> V_219 . V_528 ) ;
if ( V_46 < 0 )
goto V_735;
V_161 =
F_7 ( V_743 ) |
F_8 ( V_766 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , & V_161 , & V_754 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_219 . V_220 = F_431 ( V_754 ) ;
V_13 -> V_219 . V_767 = V_754 ;
if ( V_72 == V_759 ) {
F_409 ( V_13 -> V_30 , L_63\
L_64 ,
V_13 -> V_60 & V_165 ? L_65 : L_66 ) ;
} else {
F_409 ( V_13 -> V_30 , L_67\
L_68 ) ;
V_219 [ 0 ] = ( F_7 ( V_743 ) |
F_8 ( V_744 ) ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 ,
V_219 , V_264 ) ;
if ( V_46 < 0 ) {
F_11 ( V_13 -> V_30 , L_69
L_70 ) ;
goto V_735;
}
V_46 = F_411 ( V_13 , V_721 ) ;
if ( V_46 == - V_751 ) {
F_11 ( V_13 -> V_30 , L_71
L_72 ) ;
goto V_735;
}
if ( V_46 < 0 ) {
F_11 ( V_13 -> V_30 , L_73
L_74 , - V_46 ) ;
goto V_735;
}
}
V_46 = F_386 ( V_13 ) ;
if ( V_46 < 0 )
goto V_735;
if ( F_432 ( V_13 -> V_158 -> V_468 ) )
V_13 -> V_219 . V_768 = 1 ;
#define F_433 ( T_14 ) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define F_434 ( T_14 ) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
V_219 [ 0 ] = F_434 ( V_769 ) ;
V_219 [ 1 ] = F_434 ( V_770 ) ;
V_219 [ 2 ] = F_434 ( V_771 ) ;
V_219 [ 3 ] = F_434 ( V_772 ) ;
V_219 [ 4 ] = F_434 ( V_773 ) ;
V_219 [ 5 ] = F_434 ( V_774 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_219 , V_264 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_16 . V_115 = V_264 [ 0 ] ;
V_13 -> V_775 = V_264 [ 1 ] ;
V_13 -> V_776 = V_264 [ 2 ] ;
V_13 -> V_87 . V_88 = V_264 [ 3 ] ;
V_13 -> V_87 . V_89 = V_264 [ 4 ] - V_264 [ 3 ] + 1 ;
V_13 -> V_16 . V_198 = V_264 [ 5 ] ;
V_219 [ 0 ] = F_434 ( V_777 ) ;
V_219 [ 1 ] = F_434 ( V_778 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_219 , V_264 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_16 . V_212 = V_264 [ 0 ] - V_13 -> V_16 . V_115 + 1 ;
V_13 -> V_16 . V_200 = V_264 [ 1 ] - V_13 -> V_16 . V_198 + 1 ;
V_13 -> V_16 . V_114 = F_435 ( V_13 -> V_16 . V_212 ,
sizeof( * V_13 -> V_16 . V_114 ) , V_191 ) ;
if ( ! V_13 -> V_16 . V_114 ) {
V_46 = - V_53 ;
goto V_735;
}
V_13 -> V_16 . V_199 = F_435 ( V_13 -> V_16 . V_200 ,
sizeof( * V_13 -> V_16 . V_199 ) , V_191 ) ;
if ( ! V_13 -> V_16 . V_199 ) {
V_46 = - V_53 ;
goto V_735;
}
V_13 -> V_16 . V_211 = F_435 ( F_221 ( V_13 -> V_16 . V_212 ) ,
sizeof( long ) , V_191 ) ;
if ( ! V_13 -> V_16 . V_211 ) {
V_46 = - V_53 ;
goto V_735;
}
V_13 -> V_16 . V_213 = F_435 ( F_221 ( V_13 -> V_16 . V_212 ) ,
sizeof( long ) , V_191 ) ;
if ( ! V_13 -> V_16 . V_213 ) {
V_46 = - V_53 ;
goto V_735;
}
#ifdef F_194
V_13 -> V_16 . V_779 = F_435 ( F_221 ( V_13 -> V_16 . V_212 ) ,
sizeof( long ) , V_191 ) ;
if ( ! V_13 -> V_16 . V_779 ) {
V_46 = - V_53 ;
goto V_735;
}
#endif
V_219 [ 0 ] = F_434 ( V_780 ) ;
V_219 [ 1 ] = F_434 ( V_781 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_219 , V_264 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_782 = V_264 [ 0 ] ;
V_13 -> V_783 = V_264 [ 1 ] ;
V_219 [ 0 ] = F_434 ( V_784 ) ;
V_219 [ 1 ] = F_434 ( V_785 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_219 , V_264 ) ;
if ( ( V_264 [ 0 ] != V_264 [ 1 ] ) && ( V_46 >= 0 ) ) {
V_13 -> V_60 |= V_551 ;
V_13 -> V_87 . V_786 = V_264 [ 0 ] ;
V_13 -> V_87 . V_787 = V_264 [ 1 ] ;
}
V_219 [ 0 ] = F_434 ( V_788 ) ;
V_264 [ 0 ] = 1 ;
( void ) F_188 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 1 , V_219 , V_264 ) ;
if ( F_122 ( V_13 -> V_219 . V_229 ) ) {
V_13 -> V_219 . V_554 = false ;
} else {
V_219 [ 0 ] = F_433 ( V_789 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 ,
1 , V_219 , V_264 ) ;
V_13 -> V_219 . V_554 = ( V_46 == 0 && V_264 [ 0 ] != 0 ) ;
}
memset ( & V_722 , 0 , sizeof( V_722 ) ) ;
V_722 . V_678 = F_134 ( F_381 ( V_679 ) |
V_680 | V_681 ) ;
V_722 . V_682 = F_134 ( F_382 ( V_722 ) ) ;
V_46 = F_383 ( V_13 , V_13 -> V_27 , & V_722 , sizeof( V_722 ) ,
& V_722 ) ;
if ( V_46 < 0 )
goto V_735;
if ( V_722 . V_790 ) {
V_219 [ 0 ] = F_433 ( V_791 ) ;
V_219 [ 1 ] = F_434 ( V_792 ) ;
V_219 [ 2 ] = F_434 ( V_793 ) ;
V_219 [ 3 ] = F_434 ( V_794 ) ;
V_219 [ 4 ] = F_434 ( V_795 ) ;
V_219 [ 5 ] = F_433 ( V_796 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_219 , V_264 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_87 . V_361 = V_264 [ 0 ] ;
V_13 -> V_87 . V_366 = F_436 ( V_13 -> V_87 . V_361 / 2 , V_797 ) ;
V_13 -> V_87 . V_342 = V_264 [ 1 ] ;
V_13 -> V_87 . V_340 = V_264 [ 2 ] - V_264 [ 1 ] + 1 ;
if ( V_13 -> V_60 & V_551 && ! F_437 ( V_13 ) ) {
V_13 -> V_87 . V_344 = V_13 -> V_87 . V_88 +
F_438 ( V_13 -> V_87 . V_89 , 3 ) ;
V_13 -> V_87 . V_90 = V_13 -> V_87 . V_89 -
F_438 ( V_13 -> V_87 . V_89 , 3 ) ;
V_13 -> V_87 . V_89 = V_13 -> V_87 . V_344 -
V_13 -> V_87 . V_88 ;
}
V_13 -> V_445 . V_798 . V_446 = V_264 [ 3 ] ;
V_13 -> V_445 . V_798 . V_210 = V_264 [ 4 ] - V_264 [ 3 ] + 1 ;
V_13 -> V_219 . V_518 = V_264 [ 5 ] ;
V_13 -> V_219 . V_799 = 1 ;
}
if ( V_722 . V_800 ) {
V_219 [ 0 ] = F_434 ( V_801 ) ;
V_219 [ 1 ] = F_434 ( V_802 ) ;
V_219 [ 2 ] = F_434 ( V_803 ) ;
V_219 [ 3 ] = F_434 ( V_804 ) ;
V_219 [ 4 ] = F_434 ( V_805 ) ;
V_219 [ 5 ] = F_434 ( V_806 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 ,
V_219 , V_264 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_445 . V_432 . V_446 = V_264 [ 0 ] ;
V_13 -> V_445 . V_432 . V_210 = V_264 [ 1 ] - V_264 [ 0 ] + 1 ;
V_13 -> V_445 . V_807 . V_446 = V_264 [ 2 ] ;
V_13 -> V_445 . V_807 . V_210 = V_264 [ 3 ] - V_264 [ 2 ] + 1 ;
V_13 -> V_445 . V_808 . V_446 = V_264 [ 4 ] ;
V_13 -> V_445 . V_808 . V_210 = V_264 [ 5 ] - V_264 [ 4 ] + 1 ;
V_219 [ 0 ] = F_434 ( V_809 ) ;
V_219 [ 1 ] = F_434 ( V_810 ) ;
V_219 [ 2 ] = F_434 ( V_811 ) ;
V_219 [ 3 ] = F_434 ( V_812 ) ;
V_219 [ 4 ] = F_434 ( V_813 ) ;
V_219 [ 5 ] = F_434 ( V_814 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 6 , V_219 ,
V_264 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_445 . V_815 . V_446 = V_264 [ 0 ] ;
V_13 -> V_445 . V_815 . V_210 = V_264 [ 1 ] - V_264 [ 0 ] + 1 ;
V_13 -> V_445 . V_816 . V_446 = V_264 [ 2 ] ;
V_13 -> V_445 . V_816 . V_210 = V_264 [ 3 ] - V_264 [ 2 ] + 1 ;
V_13 -> V_445 . V_670 . V_446 = V_264 [ 4 ] ;
V_13 -> V_445 . V_670 . V_210 = V_264 [ 5 ] - V_264 [ 4 ] + 1 ;
V_219 [ 0 ] = F_433 ( V_817 ) ;
V_219 [ 1 ] = F_433 ( V_818 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 , V_219 ,
V_264 ) ;
if ( V_46 < 0 ) {
V_13 -> V_219 . V_552 = 8 ;
V_13 -> V_219 . V_553 = 32 * V_13 -> V_87 . V_361 ;
V_46 = 0 ;
} else {
V_13 -> V_219 . V_552 = V_264 [ 0 ] ;
V_13 -> V_219 . V_553 = V_264 [ 1 ] ;
}
F_409 ( V_13 -> V_30 ,
L_75 ,
V_13 -> V_219 . V_552 ,
V_13 -> V_219 . V_553 ) ;
}
if ( V_722 . V_819 ) {
V_219 [ 0 ] = F_434 ( V_820 ) ;
V_219 [ 1 ] = F_434 ( V_821 ) ;
V_46 = F_416 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , 0 , 2 ,
V_219 , V_264 ) ;
if ( V_46 < 0 )
goto V_735;
V_13 -> V_445 . V_822 . V_446 = V_264 [ 0 ] ;
V_13 -> V_445 . V_822 . V_210 = V_264 [ 1 ] - V_264 [ 0 ] + 1 ;
}
#undef F_434
#undef F_433
F_439 ( V_13 , V_13 -> V_219 . V_394 , NULL ) ;
if ( V_72 != V_759 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_395 ; V_19 ++ )
if ( V_13 -> V_219 . V_394 [ V_19 ] == 1492 ) {
V_13 -> V_219 . V_394 [ V_19 ] = 1488 ;
break;
}
F_440 ( V_13 , V_13 -> V_219 . V_394 , V_13 -> V_219 . V_823 ,
V_13 -> V_219 . V_824 ) ;
}
F_441 ( V_13 ) ;
V_13 -> V_60 |= V_825 ;
F_442 ( V_13 ) ;
return 0 ;
V_735:
F_33 ( V_13 -> V_16 . V_114 ) ;
F_33 ( V_13 -> V_16 . V_199 ) ;
F_33 ( V_13 -> V_16 . V_211 ) ;
F_33 ( V_13 -> V_16 . V_213 ) ;
#ifdef F_194
F_33 ( V_13 -> V_16 . V_779 ) ;
#endif
if ( V_46 != - V_826 && V_46 != - V_827 )
F_443 ( V_13 , V_13 -> V_27 ) ;
return V_46 ;
}
static T_15 F_444 ( struct V_413 * V_158 ,
T_16 V_72 )
{
int V_19 ;
struct V_12 * V_13 = F_249 ( V_158 ) ;
if ( ! V_13 )
goto V_51;
F_445 () ;
V_13 -> V_60 &= ~ V_825 ;
F_322 ( V_13 , V_828 ) ;
F_250 ( & V_13 -> V_417 ) ;
F_82 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
F_446 ( V_2 ) ;
F_17 ( V_2 ) ;
}
F_252 ( & V_13 -> V_417 ) ;
F_104 ( V_13 ) ;
if ( V_13 -> V_60 & V_202 )
F_338 ( V_13 ) ;
F_447 () ;
if ( ( V_13 -> V_60 & V_829 ) ) {
F_448 ( V_158 ) ;
V_13 -> V_60 &= ~ V_829 ;
}
V_51: return V_72 == V_830 ?
V_831 : V_832 ;
}
static T_15 F_449 ( struct V_413 * V_158 )
{
int V_19 , V_46 ;
struct V_676 V_677 ;
struct V_12 * V_13 = F_249 ( V_158 ) ;
if ( ! V_13 ) {
F_450 ( V_158 ) ;
F_451 ( V_158 ) ;
return V_833 ;
}
if ( ! ( V_13 -> V_60 & V_829 ) ) {
if ( F_452 ( V_158 ) ) {
F_11 ( & V_158 -> V_2 , L_76
L_77 ) ;
return V_831 ;
}
V_13 -> V_60 |= V_829 ;
}
F_453 ( V_158 ) ;
F_450 ( V_158 ) ;
F_451 ( V_158 ) ;
F_454 ( V_158 ) ;
if ( F_455 ( V_13 -> V_540 ) < 0 )
return V_831 ;
if ( F_425 ( V_13 , V_13 -> V_27 , V_13 -> V_28 , V_834 , NULL ) < 0 )
return V_831 ;
V_13 -> V_60 |= V_825 ;
if ( F_380 ( V_13 , & V_677 ) )
return V_831 ;
F_82 (adap, i) {
struct V_5 * V_6 = F_97 ( V_13 , V_19 ) ;
V_46 = F_456 ( V_13 , V_13 -> V_27 , V_6 -> V_68 , V_13 -> V_28 , 0 , 1 ,
NULL , NULL ) ;
if ( V_46 < 0 )
return V_831 ;
V_6 -> V_43 = V_46 ;
V_6 -> V_66 = - 1 ;
}
F_440 ( V_13 , V_13 -> V_219 . V_394 , V_13 -> V_219 . V_823 ,
V_13 -> V_219 . V_824 ) ;
F_369 ( V_13 ) ;
if ( F_333 ( V_13 ) )
return V_831 ;
return V_833 ;
}
static void F_457 ( struct V_413 * V_158 )
{
int V_19 ;
struct V_12 * V_13 = F_249 ( V_158 ) ;
if ( ! V_13 )
return;
F_445 () ;
F_82 (adap, i) {
struct V_1 * V_2 = V_13 -> V_34 [ V_19 ] ;
if ( F_13 ( V_2 ) ) {
F_39 ( V_2 ) ;
F_362 ( V_2 ) ;
}
F_458 ( V_2 ) ;
}
F_447 () ;
}
static inline bool F_459 ( const struct V_835 * V_836 )
{
return ( V_836 -> V_837 & V_838 ) != 0 ||
( V_836 -> V_837 & V_839 ) != 0 ;
}
static inline void F_460 ( struct V_12 * V_13 , struct V_100 * V_25 ,
unsigned int V_319 , unsigned int V_320 ,
unsigned int V_210 , unsigned int V_840 )
{
V_25 -> V_13 = V_13 ;
F_187 ( V_25 , V_319 , V_320 ) ;
V_25 -> V_841 = V_840 ;
V_25 -> V_210 = V_210 ;
}
static void F_461 ( struct V_12 * V_13 )
{
struct V_16 * V_4 = & V_13 -> V_16 ;
int V_19 , V_842 = 0 , V_843 = 0 ;
#ifndef F_15
int V_844 = 0 ;
#endif
int V_845 ;
F_82 (adap, i)
V_842 += F_459 ( & F_97 ( V_13 , V_19 ) -> V_7 ) ;
#ifdef F_15
if ( V_13 -> V_219 . V_220 * 8 > V_846 ) {
F_11 ( V_13 -> V_30 , L_78 ,
V_846 , V_13 -> V_219 . V_220 * 8 ) ;
F_462 ( 1 ) ;
}
F_82 (adap, i) {
struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_843 ;
V_11 -> V_20 = 8 ;
V_843 += V_11 -> V_20 ;
}
#else
if ( V_842 )
V_844 = ( V_846 - ( V_13 -> V_219 . V_220 - V_842 ) ) / V_842 ;
if ( V_844 > F_463 () )
V_844 = F_463 () ;
F_82 (adap, i) {
struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_843 ;
V_11 -> V_20 = F_459 ( & V_11 -> V_7 ) ? V_844 : 1 ;
V_843 += V_11 -> V_20 ;
}
#endif
V_4 -> V_847 = V_843 ;
V_4 -> V_848 = V_843 ;
if ( F_390 ( V_13 ) ) {
if ( V_842 ) {
V_19 = F_464 ( int , F_19 ( V_4 -> V_183 ) ,
F_465 () ) ;
V_4 -> V_218 = F_466 ( V_19 , V_13 -> V_219 . V_220 ) ;
} else
V_4 -> V_218 = V_13 -> V_219 . V_220 ;
V_4 -> V_224 = V_13 -> V_219 . V_220 ;
V_4 -> V_226 = F_464 ( int , V_849 , F_465 () ) ;
V_4 -> V_226 = ( V_4 -> V_226 / V_13 -> V_219 . V_220 ) *
V_13 -> V_219 . V_220 ;
V_4 -> V_226 = F_467 ( int , V_4 -> V_226 , V_13 -> V_219 . V_220 ) ;
if ( ! F_122 ( V_13 -> V_219 . V_229 ) )
V_4 -> V_222 = V_4 -> V_218 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_181 ) ; V_19 ++ ) {
struct V_189 * V_850 = & V_4 -> V_181 [ V_19 ] ;
F_460 ( V_13 , & V_850 -> V_147 , 5 , 10 , 1024 , 64 ) ;
V_850 -> V_209 . V_210 = 72 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_17 ) ; V_19 ++ )
V_4 -> V_17 [ V_19 ] . V_25 . V_210 = 1024 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_228 ) ; V_19 ++ )
V_4 -> V_228 [ V_19 ] . V_25 . V_210 = 512 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_117 ) ; V_19 ++ )
V_4 -> V_117 [ V_19 ] . V_25 . V_210 = 1024 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_183 ) ; V_19 ++ ) {
struct V_145 * V_850 = & V_4 -> V_183 [ V_19 ] ;
F_460 ( V_13 , & V_850 -> V_147 , 5 , 1 , 1024 , 64 ) ;
V_850 -> V_147 . V_142 = V_513 ;
V_850 -> V_209 . V_210 = 72 ;
}
if ( ! F_122 ( V_13 -> V_219 . V_229 ) ) {
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_184 ) ; V_19 ++ ) {
struct V_145 * V_850 = & V_4 -> V_184 [ V_19 ] ;
F_460 ( V_13 , & V_850 -> V_147 , 5 , 1 , 1024 , 64 ) ;
V_850 -> V_147 . V_142 = V_514 ;
V_850 -> V_209 . V_210 = 72 ;
}
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_185 ) ; V_19 ++ ) {
struct V_145 * V_850 = & V_4 -> V_185 [ V_19 ] ;
F_460 ( V_13 , & V_850 -> V_147 , 5 , 1 , 511 , 64 ) ;
V_850 -> V_147 . V_142 = V_485 ;
V_850 -> V_209 . V_210 = 72 ;
}
V_845 = 64 + V_13 -> V_445 . V_816 . V_210 + V_13 -> V_87 . V_89 ;
if ( V_845 > V_851 ) {
F_299 ( V_13 , L_79 ) ;
V_845 = V_851 ;
}
for ( V_19 = 0 ; V_19 < F_19 ( V_4 -> V_186 ) ; V_19 ++ ) {
struct V_145 * V_850 = & V_4 -> V_186 [ V_19 ] ;
F_460 ( V_13 , & V_850 -> V_147 , 5 , 1 , V_845 , 64 ) ;
V_850 -> V_147 . V_142 = V_485 ;
}
F_460 ( V_13 , & V_4 -> V_180 , 0 , 1 , 1024 , 64 ) ;
F_460 ( V_13 , & V_4 -> V_214 , 0 , 1 , 2 * V_687 , 64 ) ;
}
static void F_468 ( struct V_12 * V_13 , int V_169 )
{
int V_19 ;
struct V_5 * V_11 ;
while ( V_169 < V_13 -> V_16 . V_847 )
F_82 (adap, i) {
V_11 = F_97 ( V_13 , V_19 ) ;
if ( V_11 -> V_20 > 1 ) {
V_11 -> V_20 -- ;
V_13 -> V_16 . V_847 -- ;
if ( V_13 -> V_16 . V_847 <= V_169 )
break;
}
}
V_169 = 0 ;
F_82 (adap, i) {
V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_18 = V_169 ;
V_169 += V_11 -> V_20 ;
}
}
static int F_469 ( struct V_12 * V_13 )
{
int V_852 = 0 ;
int V_19 , V_853 , V_854 , V_855 ;
struct V_16 * V_4 = & V_13 -> V_16 ;
unsigned int V_516 = V_13 -> V_219 . V_220 ;
struct V_856 * V_857 ;
V_857 = F_93 ( sizeof( * V_857 ) * ( V_687 + 1 ) ,
V_191 ) ;
if ( ! V_857 )
return - V_53 ;
for ( V_19 = 0 ; V_19 < V_687 + 1 ; ++ V_19 )
V_857 [ V_19 ] . V_41 = V_19 ;
V_853 = V_4 -> V_848 + V_858 ;
if ( F_390 ( V_13 ) ) {
V_853 += V_4 -> V_224 + V_4 -> V_226 + V_4 -> V_218 +
V_4 -> V_222 ;
if ( F_122 ( V_13 -> V_219 . V_229 ) )
V_852 = 3 * V_516 ;
else
V_852 = 4 * V_516 ;
}
#ifdef F_15
V_854 = 8 * V_13 -> V_219 . V_220 + V_858 + V_852 ;
#else
V_854 = V_13 -> V_219 . V_220 + V_858 + V_852 ;
#endif
V_855 = F_470 ( V_13 -> V_158 , V_857 , V_854 , V_853 ) ;
if ( V_855 < 0 ) {
F_409 ( V_13 -> V_30 , L_80
L_81 ) ;
F_33 ( V_857 ) ;
return V_855 ;
}
V_19 = V_855 - V_858 - V_852 ;
if ( V_19 < V_4 -> V_848 ) {
V_4 -> V_848 = V_19 ;
if ( V_19 < V_4 -> V_847 )
F_468 ( V_13 , V_19 ) ;
}
if ( F_390 ( V_13 ) ) {
if ( V_855 < V_853 ) {
V_4 -> V_224 = V_516 ;
V_4 -> V_226 = V_516 ;
if ( ! F_122 ( V_13 -> V_219 . V_229 ) )
V_4 -> V_222 = V_516 ;
}
V_19 = V_855 - V_858 - V_4 -> V_848 -
V_4 -> V_224 - V_4 -> V_226 - V_4 -> V_222 ;
V_4 -> V_218 = ( V_19 / V_516 ) * V_516 ;
}
for ( V_19 = 0 ; V_19 < V_855 ; ++ V_19 )
V_13 -> V_170 [ V_19 ] . V_38 = V_857 [ V_19 ] . V_859 ;
F_409 ( V_13 -> V_30 , L_82
L_83 ,
V_855 , V_4 -> V_848 , V_4 -> V_218 , V_4 -> V_224 ,
V_4 -> V_226 ) ;
F_33 ( V_857 ) ;
return 0 ;
}
static int F_471 ( struct V_12 * V_13 )
{
unsigned int V_19 ;
int V_22 ;
V_22 = F_472 ( V_13 , V_13 -> V_27 ) ;
if ( V_22 )
return V_22 ;
F_82 (adap, i) {
struct V_5 * V_11 = F_97 ( V_13 , V_19 ) ;
V_11 -> V_188 = F_435 ( V_11 -> V_190 , sizeof( T_6 ) , V_191 ) ;
if ( ! V_11 -> V_188 )
return - V_53 ;
}
return 0 ;
}
static int F_473 ( struct V_12 * V_13 ,
enum V_860 * V_8 ,
enum V_861 * V_862 )
{
T_1 V_863 , V_864 ;
int V_865 , V_866 ;
#define F_474 4
* V_8 = V_867 ;
* V_862 = V_868 ;
V_865 = F_475 ( V_13 -> V_158 , V_869 ,
& V_863 ) ;
V_866 = F_475 ( V_13 -> V_158 , V_870 ,
& V_864 ) ;
if ( ! V_866 && V_864 ) {
if ( V_864 & V_871 )
* V_8 = V_872 ;
else if ( V_864 & V_873 )
* V_8 = V_874 ;
else if ( V_864 & V_875 )
* V_8 = V_876 ;
}
if ( ! V_865 ) {
* V_862 = ( V_863 & V_877 ) >> F_474 ;
if ( ! V_864 ) {
if ( V_863 & V_878 )
* V_8 = V_874 ;
else if ( V_863 & V_879 )
* V_8 = V_876 ;
}
}
if ( * V_8 == V_867 || * V_862 == V_868 )
return V_865 ? V_865 : V_866 ? V_866 : - V_57 ;
return 0 ;
}
static void F_476 ( struct V_12 * V_13 )
{
enum V_861 V_862 , V_880 ;
enum V_860 V_8 , V_881 ;
#define F_477 ( V_8 ) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if ( F_473 ( V_13 , & V_881 , & V_880 ) ) {
F_310 ( V_13 -> V_30 ,
L_84 ) ;
return;
}
if ( F_478 ( V_13 -> V_158 , & V_8 , & V_862 ) ||
V_8 == V_867 || V_862 == V_868 ) {
F_310 ( V_13 -> V_30 ,
L_85 ) ;
return;
}
F_409 ( V_13 -> V_30 , L_86 ,
F_477 ( V_8 ) , F_477 ( V_881 ) ) ;
F_409 ( V_13 -> V_30 , L_87 ,
V_862 , V_880 ) ;
if ( V_8 < V_881 || V_862 < V_880 )
F_409 ( V_13 -> V_30 ,
L_88
L_89 ) ;
}
static void F_479 ( const struct V_1 * V_2 )
{
char V_748 [ 80 ] ;
char * V_882 = V_748 ;
const char * V_883 = L_90 ;
const struct V_5 * V_11 = F_4 ( V_2 ) ;
const struct V_12 * V_13 = V_11 -> V_12 ;
if ( V_13 -> V_219 . V_884 . V_8 == V_885 )
V_883 = L_91 ;
else if ( V_13 -> V_219 . V_884 . V_8 == V_886 )
V_883 = L_92 ;
else if ( V_13 -> V_219 . V_884 . V_8 == V_887 )
V_883 = L_93 ;
if ( V_11 -> V_7 . V_837 & V_888 )
V_882 += sprintf ( V_882 , L_94 ) ;
if ( V_11 -> V_7 . V_837 & V_889 )
V_882 += sprintf ( V_882 , L_95 ) ;
if ( V_11 -> V_7 . V_837 & V_838 )
V_882 += sprintf ( V_882 , L_96 ) ;
if ( V_11 -> V_7 . V_837 & V_839 )
V_882 += sprintf ( V_882 , L_97 ) ;
if ( V_882 != V_748 )
-- V_882 ;
sprintf ( V_882 , L_98 , F_480 ( V_11 -> V_890 ) ) ;
F_3 ( V_2 , L_99 ,
V_13 -> V_219 . V_528 . V_891 ,
F_481 ( V_13 -> V_219 . V_229 ) , V_748 ,
F_390 ( V_13 ) ? L_100 : L_90 ,
( V_13 -> V_60 & V_157 ) ? L_101 :
( V_13 -> V_60 & V_159 ) ? L_102 : L_90 ) ;
F_3 ( V_2 , L_103 ,
V_13 -> V_219 . V_528 . V_892 , V_13 -> V_219 . V_528 . V_893 ) ;
}
static void F_482 ( struct V_413 * V_2 )
{
F_483 ( V_2 , V_894 , V_895 ) ;
}
static void F_484 ( struct V_12 * V_12 )
{
unsigned int V_19 ;
F_127 ( V_12 -> V_82 ) ;
F_127 ( V_12 -> V_87 . V_352 ) ;
F_33 ( V_12 -> V_16 . V_114 ) ;
F_33 ( V_12 -> V_16 . V_199 ) ;
F_33 ( V_12 -> V_16 . V_211 ) ;
F_33 ( V_12 -> V_16 . V_213 ) ;
#ifdef F_194
F_33 ( V_12 -> V_16 . V_779 ) ;
#endif
F_73 ( V_12 ) ;
F_82 (adapter, i)
if ( V_12 -> V_34 [ V_19 ] ) {
struct V_5 * V_11 = F_97 ( V_12 , V_19 ) ;
if ( V_11 -> V_43 != 0 )
F_485 ( V_12 , V_12 -> V_27 , V_12 -> V_28 ,
0 , V_11 -> V_43 ) ;
F_33 ( F_97 ( V_12 , V_19 ) -> V_188 ) ;
F_486 ( V_12 -> V_34 [ V_19 ] ) ;
}
if ( V_12 -> V_60 & V_825 )
F_443 ( V_12 , V_12 -> V_28 ) ;
}
static int F_487 ( struct V_413 * V_158 , T_1 V_896 )
{
T_6 V_897 ;
F_488 ( V_158 , V_898 , & V_897 ) ;
switch ( V_897 >> 12 ) {
case V_736 :
return F_489 ( V_736 , V_896 ) ;
case V_368 :
return F_489 ( V_368 , V_896 ) ;
case V_739 :
return F_489 ( V_739 , V_896 ) ;
default:
F_11 ( & V_158 -> V_2 , L_51 ,
V_897 ) ;
}
return - V_57 ;
}
static int F_490 ( struct V_413 * V_158 , const struct V_899 * V_900 )
{
int V_901 , V_19 , V_22 , V_902 , V_903 , V_904 ;
struct V_5 * V_11 ;
bool V_905 = false ;
struct V_12 * V_12 = NULL ;
void T_17 * V_540 ;
T_1 V_906 , V_896 ;
enum V_405 V_229 ;
F_491 ( V_907 L_104 , V_908 , V_909 ) ;
V_22 = F_492 ( V_158 , V_910 ) ;
if ( V_22 ) {
F_409 ( & V_158 -> V_2 , L_105 ) ;
return V_22 ;
}
V_22 = F_452 ( V_158 ) ;
if ( V_22 ) {
F_11 ( & V_158 -> V_2 , L_106 ) ;
goto V_911;
}
V_540 = F_493 ( V_158 , 0 ) ;
if ( ! V_540 ) {
F_11 ( & V_158 -> V_2 , L_107 ) ;
V_22 = - V_53 ;
goto V_912;
}
V_22 = F_455 ( V_540 ) ;
if ( V_22 < 0 )
goto V_913;
V_906 = F_494 ( V_540 + V_914 ) ;
V_896 = F_495 ( F_494 ( V_540 + V_915 ) ) ;
V_229 = F_487 ( V_158 , V_896 ) ;
V_901 = F_224 ( V_229 ) <= V_368 ?
F_496 ( V_906 ) : F_497 ( V_906 ) ;
if ( V_901 != V_900 -> V_916 ) {
F_498 ( V_540 ) ;
F_448 ( V_158 ) ;
F_451 ( V_158 ) ;
goto V_917;
}
if ( ! F_499 ( V_158 , F_500 ( 64 ) ) ) {
V_905 = true ;
V_22 = F_501 ( V_158 , F_500 ( 64 ) ) ;
if ( V_22 ) {
F_11 ( & V_158 -> V_2 , L_108
L_109 ) ;
goto V_913;
}
} else {
V_22 = F_499 ( V_158 , F_500 ( 32 ) ) ;
if ( V_22 ) {
F_11 ( & V_158 -> V_2 , L_110 ) ;
goto V_913;
}
}
F_502 ( V_158 ) ;
F_482 ( V_158 ) ;
F_453 ( V_158 ) ;
F_451 ( V_158 ) ;
V_12 = F_26 ( sizeof( * V_12 ) , V_191 ) ;
if ( ! V_12 ) {
V_22 = - V_53 ;
goto V_913;
}
V_12 -> V_357 = F_503 ( L_111 ) ;
if ( ! V_12 -> V_357 ) {
V_22 = - V_53 ;
goto V_918;
}
V_12 -> V_60 |= V_829 ;
V_12 -> V_540 = V_540 ;
V_12 -> V_158 = V_158 ;
V_12 -> V_30 = & V_158 -> V_2 ;
V_12 -> V_27 = V_901 ;
V_12 -> V_28 = V_901 ;
V_12 -> V_919 = V_920 ;
memset ( V_12 -> V_921 , 0xff , sizeof( V_12 -> V_921 ) ) ;
F_222 ( & V_12 -> V_417 ) ;
F_222 ( & V_12 -> V_353 ) ;
F_222 ( & V_12 -> V_426 ) ;
F_504 ( & V_12 -> V_358 , F_215 ) ;
F_504 ( & V_12 -> V_486 , F_296 ) ;
F_504 ( & V_12 -> V_493 , F_301 ) ;
V_22 = F_505 ( V_12 ) ;
if ( V_22 )
goto V_918;
if ( ! F_122 ( V_12 -> V_219 . V_229 ) ) {
V_902 = ( V_922 +
( V_923 - V_922 ) *
V_12 -> V_28 ) ;
V_903 = 1 << F_506 ( F_77 ( V_12 ,
V_924 ) >> V_902 ) ;
V_904 = V_703 / V_925 ;
if ( V_903 > V_904 ) {
F_11 ( & V_158 -> V_2 ,
L_112 ) ;
V_22 = - V_57 ;
goto V_918;
}
V_12 -> V_499 = F_507 ( F_508 ( V_158 , 2 ) ,
F_509 ( V_158 , 2 ) ) ;
if ( ! V_12 -> V_499 ) {
F_11 ( & V_158 -> V_2 , L_113 ) ;
V_22 = - V_53 ;
goto V_918;
}
}
F_369 ( V_12 ) ;
V_22 = F_423 ( V_12 ) ;
#ifdef F_194
F_114 ( V_12 -> V_16 . V_779 , V_12 -> V_16 . V_212 ) ;
#endif
F_372 ( V_12 ) ;
if ( V_22 )
goto V_926;
if ( ! F_122 ( V_12 -> V_219 . V_229 ) )
F_79 ( V_12 , V_927 , F_510 ( 7 ) |
( F_271 ( V_12 -> V_219 . V_229 ) ? F_511 ( 0 ) :
F_512 ( 0 ) ) ) ;
F_82 (adapter, i) {
struct V_1 * V_44 ;
V_44 = F_513 ( sizeof( struct V_5 ) ,
V_846 ) ;
if ( ! V_44 ) {
V_22 = - V_53 ;
goto V_928;
}
F_514 ( V_44 , & V_158 -> V_2 ) ;
V_12 -> V_34 [ V_19 ] = V_44 ;
V_11 = F_4 ( V_44 ) ;
V_11 -> V_12 = V_12 ;
V_11 -> V_66 = - 1 ;
V_11 -> V_31 = V_19 ;
V_44 -> V_160 = V_158 -> V_160 ;
V_44 -> V_929 = V_930 | V_931 |
V_932 | V_933 |
V_934 | V_935 |
V_936 | V_65 ;
if ( V_905 )
V_44 -> V_929 |= V_937 ;
V_44 -> V_64 |= V_44 -> V_929 ;
V_44 -> V_938 = V_44 -> V_64 & V_939 ;
V_44 -> V_470 |= V_940 ;
V_44 -> V_941 = & V_942 ;
#ifdef F_15
V_44 -> V_943 = & V_944 ;
F_16 ( V_44 ) ;
#endif
F_515 ( V_44 ) ;
}
F_516 ( V_158 , V_12 ) ;
if ( V_12 -> V_60 & V_825 ) {
V_22 = F_517 ( V_12 , V_901 , V_901 , 0 ) ;
if ( V_22 )
goto V_928;
} else if ( V_12 -> V_219 . V_220 == 1 ) {
T_3 V_945 [ V_946 ] ;
T_3 * V_947 = V_12 -> V_219 . V_528 . V_947 ;
V_22 = F_518 ( V_12 , & V_12 -> V_219 . V_528 ) ;
if ( ! V_22 ) {
for ( V_19 = 0 ; V_19 < V_946 ; V_19 ++ )
V_945 [ V_19 ] = ( F_519 ( V_947 [ 2 * V_19 + 0 ] ) * 16 +
F_519 ( V_947 [ 2 * V_19 + 1 ] ) ) ;
F_520 ( V_12 , 0 , V_945 ) ;
}
}
F_461 ( V_12 ) ;
V_12 -> V_82 = F_521 ( V_12 -> V_775 , V_12 -> V_776 ) ;
if ( ! V_12 -> V_82 ) {
F_310 ( & V_158 -> V_2 , L_114 ) ;
V_12 -> V_219 . V_799 = 0 ;
}
#if F_326 ( V_587 )
if ( ( F_224 ( V_12 -> V_219 . V_229 ) <= V_368 ) &&
( ! ( F_77 ( V_12 , V_948 ) & V_949 ) ) ) {
F_310 ( & V_158 -> V_2 ,
L_115 ) ;
V_12 -> V_219 . V_799 = 0 ;
} else {
V_12 -> V_950 = F_522 ( V_12 -> V_782 ,
V_12 -> V_783 ) ;
if ( ! V_12 -> V_950 ) {
F_310 ( & V_158 -> V_2 ,
L_116 ) ;
V_12 -> V_219 . V_799 = 0 ;
}
}
#endif
if ( F_390 ( V_12 ) && F_220 ( & V_12 -> V_87 ) < 0 ) {
F_310 ( & V_158 -> V_2 , L_117
L_118 ) ;
V_12 -> V_219 . V_799 = 0 ;
}
if ( F_390 ( V_12 ) ) {
if ( F_77 ( V_12 , V_948 ) & V_951 ) {
T_1 V_362 , V_952 ;
if ( V_229 <= V_368 ) {
V_952 = V_953 ;
V_362 = F_77 ( V_12 , V_952 ) ;
V_12 -> V_87 . V_362 = V_362 / 4 ;
} else {
V_952 = V_954 ;
V_362 = F_77 ( V_12 , V_952 ) ;
V_12 -> V_87 . V_362 = V_362 ;
}
}
}
if ( V_955 > 1 && F_469 ( V_12 ) == 0 )
V_12 -> V_60 |= V_157 ;
else if ( V_955 > 0 && F_523 ( V_158 ) == 0 )
V_12 -> V_60 |= V_159 ;
F_476 ( V_12 ) ;
V_22 = F_471 ( V_12 ) ;
if ( V_22 )
goto V_928;
F_82 (adapter, i) {
V_11 = F_97 ( V_12 , V_19 ) ;
F_524 ( V_12 -> V_34 [ V_19 ] , V_11 -> V_20 ) ;
F_525 ( V_12 -> V_34 [ V_19 ] , V_11 -> V_20 ) ;
V_22 = F_526 ( V_12 -> V_34 [ V_19 ] ) ;
if ( V_22 )
break;
V_12 -> V_921 [ V_11 -> V_68 ] = V_19 ;
F_479 ( V_12 -> V_34 [ V_19 ] ) ;
}
if ( V_19 == 0 ) {
F_11 ( & V_158 -> V_2 , L_119 ) ;
goto V_928;
}
if ( V_22 ) {
F_310 ( & V_158 -> V_2 , L_120 , V_19 ) ;
V_22 = 0 ;
}
if ( V_956 ) {
V_12 -> V_325 = F_527 ( F_528 ( V_158 ) ,
V_956 ) ;
F_192 ( V_12 ) ;
}
V_158 -> V_957 = 1 ;
if ( F_390 ( V_12 ) )
F_314 ( V_12 ) ;
V_917:
#ifdef F_529
if ( V_901 < F_19 ( V_958 ) && V_958 [ V_901 ] > 0 )
if ( F_530 ( V_158 , V_958 [ V_901 ] ) == 0 )
F_409 ( & V_158 -> V_2 ,
L_121 ,
V_958 [ V_901 ] ) ;
#endif
return 0 ;
V_928:
F_484 ( V_12 ) ;
V_926:
if ( ! F_122 ( V_12 -> V_219 . V_229 ) )
F_498 ( V_12 -> V_499 ) ;
V_918:
if ( V_12 -> V_357 )
F_531 ( V_12 -> V_357 ) ;
F_33 ( V_12 ) ;
V_913:
F_498 ( V_540 ) ;
V_912:
F_532 ( V_158 ) ;
F_448 ( V_158 ) ;
V_911:
F_533 ( V_158 ) ;
return V_22 ;
}
static void F_534 ( struct V_413 * V_158 )
{
struct V_12 * V_12 = F_249 ( V_158 ) ;
#ifdef F_529
F_535 ( V_158 ) ;
#endif
if ( V_12 ) {
int V_19 ;
F_531 ( V_12 -> V_357 ) ;
if ( F_390 ( V_12 ) )
F_318 ( V_12 ) ;
F_104 ( V_12 ) ;
F_82 (adapter, i)
if ( V_12 -> V_34 [ V_19 ] -> V_959 == V_960 )
F_536 ( V_12 -> V_34 [ V_19 ] ) ;
F_537 ( V_12 -> V_325 ) ;
if ( V_12 -> V_87 . V_92 ) {
struct V_80 * V_81 = & V_12 -> V_87 . V_92 [ 0 ] ;
for ( V_19 = 0 ; V_19 < ( V_12 -> V_87 . V_89 +
V_12 -> V_87 . V_90 ) ; V_19 ++ , V_81 ++ )
if ( V_81 -> V_99 )
F_50 ( V_12 , V_81 ) ;
}
if ( V_12 -> V_60 & V_202 )
F_338 ( V_12 ) ;
F_484 ( V_12 ) ;
#if F_326 ( V_587 )
F_538 ( V_12 ) ;
#endif
F_498 ( V_12 -> V_540 ) ;
if ( ! F_122 ( V_12 -> V_219 . V_229 ) )
F_498 ( V_12 -> V_499 ) ;
F_532 ( V_158 ) ;
if ( ( V_12 -> V_60 & V_829 ) ) {
F_448 ( V_158 ) ;
V_12 -> V_60 &= ~ V_829 ;
}
F_533 ( V_158 ) ;
F_539 () ;
F_33 ( V_12 ) ;
} else
F_533 ( V_158 ) ;
}
static int T_18 F_540 ( void )
{
int V_46 ;
V_956 = F_527 ( V_910 , NULL ) ;
if ( ! V_956 )
F_541 ( L_122 ) ;
V_46 = F_542 ( & V_473 ) ;
if ( V_46 < 0 )
F_543 ( V_956 ) ;
#if F_326 ( V_587 )
if ( ! V_961 ) {
F_544 ( & V_962 ) ;
V_961 = true ;
}
#endif
return V_46 ;
}
static void T_19 F_545 ( void )
{
#if F_326 ( V_587 )
if ( V_961 ) {
F_546 ( & V_962 ) ;
V_961 = false ;
}
#endif
F_547 ( & V_473 ) ;
F_543 ( V_956 ) ;
}
