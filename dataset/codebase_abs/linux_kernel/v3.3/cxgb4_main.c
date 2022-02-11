static unsigned int F_1 ( struct V_1 * V_1 ,
unsigned int V_2 , unsigned int V_3 )
{
unsigned int V_4 , V_5 ;
if ( V_3 == 0 )
return V_6 ;
if ( V_1 -> V_7 . V_8 == 0 )
return 0 ;
V_4 = V_2 % V_1 -> V_7 . V_8 ;
V_5 = V_1 -> V_7 . V_5 ;
for (; ; ) {
unsigned int V_9 = V_5 ^ ( V_5 & ( V_5 - 1 ) ) ;
if ( V_4 == 0 )
return V_9 ;
V_4 -- ;
V_5 &= ~ V_9 ;
}
}
static void F_2 ( struct V_10 * V_11 )
{
if ( ! F_3 ( V_11 ) )
F_4 ( V_11 , L_1 ) ;
else {
static const char * V_12 [] = { L_2 , L_3 , L_4 , L_5 } ;
const char * V_13 = L_6 ;
const struct V_14 * V_15 = F_5 ( V_11 ) ;
switch ( V_15 -> V_16 . V_17 ) {
case V_18 :
V_13 = L_7 ;
break;
case V_19 :
V_13 = L_8 ;
break;
case V_20 :
V_13 = L_9 ;
break;
}
F_4 ( V_11 , L_10 , V_13 ,
V_12 [ V_15 -> V_16 . V_12 ] ) ;
}
}
void F_6 ( struct V_1 * V_1 , int V_21 , int V_22 )
{
struct V_10 * V_11 = V_1 -> V_23 [ V_21 ] ;
if ( F_7 ( V_11 ) && V_22 != F_3 ( V_11 ) ) {
if ( V_22 )
F_8 ( V_11 ) ;
else
F_9 ( V_11 ) ;
F_2 ( V_11 ) ;
}
}
void F_10 ( const struct V_1 * V_24 , int V_21 )
{
static const char * V_25 [] = {
NULL , L_11 , L_12 , L_13 , L_14 , L_15 , L_16
} ;
const struct V_10 * V_11 = V_24 -> V_23 [ V_21 ] ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_26 -> V_27 == V_28 )
F_4 ( V_11 , L_17 ) ;
else if ( V_26 -> V_27 < F_11 ( V_25 ) )
F_4 ( V_11 , L_18 , V_25 [ V_26 -> V_27 ] ) ;
}
static int F_12 ( const struct V_10 * V_11 , bool V_29 )
{
T_1 V_30 = 0 ;
T_1 V_31 = 0 ;
bool free = true ;
T_2 V_32 [ 7 ] ;
const T_3 * V_33 [ 7 ] ;
int V_34 , V_35 = 0 ;
const struct V_36 * V_37 ;
int V_38 = F_13 ( V_11 ) ;
int V_39 = F_14 ( V_11 ) ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
unsigned int V_40 = V_26 -> V_1 -> V_41 ;
F_15 (ha, dev) {
V_33 [ V_35 ++ ] = V_37 -> V_33 ;
if ( -- V_38 == 0 || V_35 >= F_11 ( V_33 ) ) {
V_34 = F_16 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , free ,
V_35 , V_33 , V_32 , & V_31 , V_29 ) ;
if ( V_34 < 0 )
return V_34 ;
free = false ;
V_35 = 0 ;
}
}
F_17 (ha, dev) {
V_33 [ V_35 ++ ] = V_37 -> V_33 ;
if ( -- V_39 == 0 || V_35 >= F_11 ( V_33 ) ) {
V_34 = F_16 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , free ,
V_35 , V_33 , V_32 , & V_30 , V_29 ) ;
if ( V_34 < 0 )
return V_34 ;
free = false ;
V_35 = 0 ;
}
}
return F_18 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , V_31 != 0 ,
V_31 | V_30 , V_29 ) ;
}
static int F_19 ( struct V_10 * V_11 , int V_43 , bool V_44 )
{
int V_34 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
V_34 = F_12 ( V_11 , V_44 ) ;
if ( V_34 == 0 )
V_34 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , V_43 ,
( V_11 -> V_45 & V_46 ) ? 1 : 0 ,
( V_11 -> V_45 & V_47 ) ? 1 : 0 , 1 , - 1 ,
V_44 ) ;
return V_34 ;
}
static int F_21 ( struct V_10 * V_11 )
{
int V_34 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
unsigned int V_40 = V_26 -> V_1 -> V_41 ;
V_34 = F_20 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , V_11 -> V_43 , - 1 , - 1 , - 1 ,
! ! ( V_11 -> V_48 & V_49 ) , true ) ;
if ( V_34 == 0 ) {
V_34 = F_22 ( V_26 -> V_1 , V_40 , V_26 -> V_42 ,
V_26 -> V_50 , V_11 -> V_51 , true ,
true ) ;
if ( V_34 >= 0 ) {
V_26 -> V_50 = V_34 ;
V_34 = 0 ;
}
}
if ( V_34 == 0 )
V_34 = F_23 ( V_26 -> V_1 , V_40 , V_26 -> V_52 ,
& V_26 -> V_16 ) ;
if ( V_34 == 0 )
V_34 = F_24 ( V_26 -> V_1 , V_40 , V_26 -> V_42 , true , true ) ;
return V_34 ;
}
static int F_25 ( struct V_53 * V_54 , const T_4 * V_55 ,
const struct V_56 * V_57 )
{
T_3 V_58 = ( ( const struct V_59 * ) V_55 ) -> V_58 ;
V_55 ++ ;
if ( F_26 ( V_58 == V_60 ) ) {
const struct V_61 * V_15 = ( void * ) V_55 ;
unsigned int V_62 = F_27 ( F_28 ( V_15 -> V_63 ) ) ;
struct V_64 * V_65 ;
V_65 = V_54 -> V_24 -> V_66 . V_67 [ V_62 - V_54 -> V_24 -> V_66 . V_68 ] ;
V_65 -> V_69 ++ ;
if ( ( T_3 * ) V_65 < ( T_3 * ) V_54 -> V_24 -> V_66 . V_70 ) {
struct V_71 * V_72 ;
V_72 = F_29 ( V_65 , struct V_71 , V_54 ) ;
F_30 ( V_72 -> V_65 ) ;
} else {
struct V_73 * V_74 ;
V_74 = F_29 ( V_65 , struct V_73 , V_54 ) ;
F_31 ( & V_74 -> V_75 ) ;
}
} else if ( V_58 == V_76 || V_58 == V_77 ) {
const struct V_78 * V_15 = ( void * ) V_55 ;
if ( V_15 -> type == 0 )
F_32 ( V_54 -> V_24 , V_15 -> V_79 ) ;
} else if ( V_58 == V_80 ) {
const struct V_81 * V_15 = ( void * ) V_55 ;
F_33 ( V_54 -> V_24 , V_15 ) ;
} else
F_34 ( V_54 -> V_24 -> V_82 ,
L_19 , V_58 ) ;
return 0 ;
}
static int F_35 ( struct V_53 * V_54 , const T_4 * V_55 ,
const struct V_56 * V_57 )
{
struct V_83 * V_84 = F_29 ( V_54 , struct V_83 , V_85 ) ;
if ( V_86 [ V_54 -> V_87 ] . F_36 ( V_54 -> V_24 -> V_88 [ V_54 -> V_87 ] , V_55 , V_57 ) ) {
V_84 -> V_89 . V_90 ++ ;
return - 1 ;
}
if ( V_57 == NULL )
V_84 -> V_89 . V_91 ++ ;
else if ( V_57 == V_92 )
V_84 -> V_89 . V_93 ++ ;
else
V_84 -> V_89 . V_94 ++ ;
return 0 ;
}
static void F_37 ( struct V_1 * V_1 )
{
if ( V_1 -> V_45 & V_95 ) {
F_38 ( V_1 -> V_96 ) ;
V_1 -> V_45 &= ~ V_95 ;
} else if ( V_1 -> V_45 & V_97 ) {
F_39 ( V_1 -> V_96 ) ;
V_1 -> V_45 &= ~ V_97 ;
}
}
static T_5 F_40 ( int V_98 , void * V_99 )
{
struct V_1 * V_24 = V_99 ;
T_6 V_100 = F_41 ( V_24 , F_42 ( V_101 ) ) ;
if ( V_100 & V_102 ) {
V_24 -> V_103 = 1 ;
F_43 ( V_24 , F_42 ( V_101 ) , V_100 ) ;
}
F_44 ( V_24 ) ;
return V_104 ;
}
static void F_45 ( struct V_1 * V_24 )
{
int V_105 , V_106 , V_107 = 2 , V_108 = sizeof( V_24 -> V_109 [ 0 ] . V_110 ) ;
snprintf ( V_24 -> V_109 [ 0 ] . V_110 , V_108 , L_20 , V_24 -> V_23 [ 0 ] -> V_111 ) ;
snprintf ( V_24 -> V_109 [ 1 ] . V_110 , V_108 , L_21 ,
V_24 -> V_23 [ 0 ] -> V_111 ) ;
F_46 (adap, j) {
struct V_10 * V_112 = V_24 -> V_23 [ V_106 ] ;
const struct V_14 * V_26 = F_5 ( V_112 ) ;
for ( V_105 = 0 ; V_105 < V_26 -> V_113 ; V_105 ++ , V_107 ++ )
snprintf ( V_24 -> V_109 [ V_107 ] . V_110 , V_108 , L_22 ,
V_112 -> V_111 , V_105 ) ;
}
F_47 (&adap->sge, i)
snprintf ( V_24 -> V_109 [ V_107 ++ ] . V_110 , V_108 , L_23 ,
V_24 -> V_23 [ 0 ] -> V_111 , V_105 ) ;
F_48 (&adap->sge, i)
snprintf ( V_24 -> V_109 [ V_107 ++ ] . V_110 , V_108 , L_24 ,
V_24 -> V_23 [ 0 ] -> V_111 , V_105 ) ;
}
static int F_49 ( struct V_1 * V_24 )
{
struct V_66 * V_13 = & V_24 -> V_66 ;
int V_114 , V_115 , V_116 = 0 , V_117 = 0 , V_118 = 2 ;
V_114 = F_50 ( V_24 -> V_109 [ 1 ] . V_119 , V_120 , 0 ,
V_24 -> V_109 [ 1 ] . V_110 , & V_13 -> V_121 ) ;
if ( V_114 )
return V_114 ;
F_51 (s, ethqidx) {
V_114 = F_50 ( V_24 -> V_109 [ V_118 ] . V_119 , V_120 , 0 ,
V_24 -> V_109 [ V_118 ] . V_110 ,
& V_13 -> V_122 [ V_115 ] . V_85 ) ;
if ( V_114 )
goto V_123;
V_118 ++ ;
}
F_47 (s, ofldqidx) {
V_114 = F_50 ( V_24 -> V_109 [ V_118 ] . V_119 , V_120 , 0 ,
V_24 -> V_109 [ V_118 ] . V_110 ,
& V_13 -> V_124 [ V_116 ] . V_85 ) ;
if ( V_114 )
goto V_123;
V_118 ++ ;
}
F_48 (s, rdmaqidx) {
V_114 = F_50 ( V_24 -> V_109 [ V_118 ] . V_119 , V_120 , 0 ,
V_24 -> V_109 [ V_118 ] . V_110 ,
& V_13 -> V_125 [ V_117 ] . V_85 ) ;
if ( V_114 )
goto V_123;
V_118 ++ ;
}
return 0 ;
V_123:
while ( -- V_117 >= 0 )
F_52 ( V_24 -> V_109 [ -- V_118 ] . V_119 ,
& V_13 -> V_125 [ V_117 ] . V_85 ) ;
while ( -- V_116 >= 0 )
F_52 ( V_24 -> V_109 [ -- V_118 ] . V_119 ,
& V_13 -> V_124 [ V_116 ] . V_85 ) ;
while ( -- V_115 >= 0 )
F_52 ( V_24 -> V_109 [ -- V_118 ] . V_119 , & V_13 -> V_122 [ V_115 ] . V_85 ) ;
F_52 ( V_24 -> V_109 [ 1 ] . V_119 , & V_13 -> V_121 ) ;
return V_114 ;
}
static void F_53 ( struct V_1 * V_24 )
{
int V_105 , V_118 = 2 ;
struct V_66 * V_13 = & V_24 -> V_66 ;
F_52 ( V_24 -> V_109 [ 1 ] . V_119 , & V_13 -> V_121 ) ;
F_51 (s, i)
F_52 ( V_24 -> V_109 [ V_118 ++ ] . V_119 , & V_13 -> V_122 [ V_105 ] . V_85 ) ;
F_47 (s, i)
F_52 ( V_24 -> V_109 [ V_118 ++ ] . V_119 , & V_13 -> V_124 [ V_105 ] . V_85 ) ;
F_48 (s, i)
F_52 ( V_24 -> V_109 [ V_118 ++ ] . V_119 , & V_13 -> V_125 [ V_105 ] . V_85 ) ;
}
static int F_54 ( const struct V_14 * V_26 , const T_2 * V_126 )
{
T_2 * V_127 ;
int V_105 , V_114 ;
const struct V_128 * V_54 = & V_26 -> V_1 -> V_66 . V_122 [ V_26 -> V_129 ] ;
V_127 = F_55 ( V_26 -> V_130 * sizeof( T_2 ) , V_131 ) ;
if ( ! V_127 )
return - V_132 ;
for ( V_105 = 0 ; V_105 < V_26 -> V_130 ; V_105 ++ , V_126 ++ )
V_127 [ V_105 ] = V_54 [ * V_126 ] . V_85 . V_133 ;
V_114 = F_56 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , 0 ,
V_26 -> V_130 , V_127 , V_26 -> V_130 ) ;
F_57 ( V_127 ) ;
return V_114 ;
}
static int F_58 ( struct V_1 * V_24 )
{
int V_105 , V_114 ;
F_46 (adap, i) {
const struct V_14 * V_26 = F_59 ( V_24 , V_105 ) ;
V_114 = F_54 ( V_26 , V_26 -> V_127 ) ;
if ( V_114 )
return V_114 ;
}
return 0 ;
}
static unsigned int F_60 ( const struct V_66 * V_15 , unsigned int V_62 )
{
V_62 -= V_15 -> V_134 ;
return F_61 ( V_15 -> V_135 [ V_62 ] -> V_136 ) -> V_52 ;
}
static void F_62 ( struct V_1 * V_24 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_24 -> V_66 . V_135 ) ; V_105 ++ ) {
struct V_53 * V_54 = V_24 -> V_66 . V_135 [ V_105 ] ;
if ( V_54 && V_54 -> V_137 )
F_63 ( & V_54 -> V_138 ) ;
}
}
static void F_64 ( struct V_1 * V_24 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_24 -> V_66 . V_135 ) ; V_105 ++ ) {
struct V_53 * V_54 = V_24 -> V_66 . V_135 [ V_105 ] ;
if ( ! V_54 )
continue;
if ( V_54 -> V_137 )
F_65 ( & V_54 -> V_138 ) ;
F_43 ( V_24 , F_42 ( V_139 ) ,
F_66 ( V_54 -> V_140 ) |
F_67 ( V_54 -> V_141 ) ) ;
}
}
static int F_68 ( struct V_1 * V_24 )
{
int V_114 , V_107 , V_105 , V_106 ;
struct V_66 * V_13 = & V_24 -> V_66 ;
F_69 ( V_13 -> V_142 , V_143 ) ;
F_69 ( V_13 -> V_144 , V_143 ) ;
if ( V_24 -> V_45 & V_95 )
V_107 = 1 ;
else {
V_114 = F_70 ( V_24 , & V_13 -> V_145 , false , V_24 -> V_23 [ 0 ] , 0 ,
NULL , NULL ) ;
if ( V_114 )
return V_114 ;
V_107 = - ( ( int ) V_13 -> V_145 . V_133 + 1 ) ;
}
V_114 = F_70 ( V_24 , & V_13 -> V_121 , true , V_24 -> V_23 [ 0 ] ,
V_107 , NULL , F_25 ) ;
if ( V_114 ) {
V_146: F_71 ( V_24 ) ;
return V_114 ;
}
F_46 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_105 ] ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_128 * V_54 = & V_13 -> V_122 [ V_26 -> V_129 ] ;
struct V_71 * V_147 = & V_13 -> V_148 [ V_26 -> V_129 ] ;
for ( V_106 = 0 ; V_106 < V_26 -> V_113 ; V_106 ++ , V_54 ++ ) {
if ( V_107 > 0 )
V_107 ++ ;
V_114 = F_70 ( V_24 , & V_54 -> V_85 , false , V_11 ,
V_107 , & V_54 -> V_149 ,
V_150 ) ;
if ( V_114 )
goto V_146;
V_54 -> V_85 . V_151 = V_106 ;
memset ( & V_54 -> V_89 , 0 , sizeof( V_54 -> V_89 ) ) ;
}
for ( V_106 = 0 ; V_106 < V_26 -> V_113 ; V_106 ++ , V_147 ++ ) {
V_114 = F_72 ( V_24 , V_147 , V_11 ,
F_73 ( V_11 , V_106 ) ,
V_13 -> V_121 . V_141 ) ;
if ( V_114 )
goto V_146;
}
}
V_106 = V_13 -> V_152 / V_24 -> V_7 . V_8 ;
F_47 (s, i) {
struct V_83 * V_54 = & V_13 -> V_124 [ V_105 ] ;
struct V_10 * V_11 = V_24 -> V_23 [ V_105 / V_106 ] ;
if ( V_107 > 0 )
V_107 ++ ;
V_114 = F_70 ( V_24 , & V_54 -> V_85 , false , V_11 , V_107 ,
& V_54 -> V_149 , F_35 ) ;
if ( V_114 )
goto V_146;
memset ( & V_54 -> V_89 , 0 , sizeof( V_54 -> V_89 ) ) ;
V_13 -> V_153 [ V_105 ] = V_54 -> V_85 . V_133 ;
V_114 = F_74 ( V_24 , & V_13 -> V_70 [ V_105 ] , V_11 ,
V_13 -> V_121 . V_141 ) ;
if ( V_114 )
goto V_146;
}
F_48 (s, i) {
struct V_83 * V_54 = & V_13 -> V_125 [ V_105 ] ;
if ( V_107 > 0 )
V_107 ++ ;
V_114 = F_70 ( V_24 , & V_54 -> V_85 , false , V_24 -> V_23 [ V_105 ] ,
V_107 , & V_54 -> V_149 , F_35 ) ;
if ( V_114 )
goto V_146;
memset ( & V_54 -> V_89 , 0 , sizeof( V_54 -> V_89 ) ) ;
V_13 -> V_154 [ V_105 ] = V_54 -> V_85 . V_133 ;
}
F_46 (adap, i) {
V_114 = F_75 ( V_24 , & V_13 -> V_155 [ V_105 ] , V_24 -> V_23 [ V_105 ] ,
V_13 -> V_121 . V_141 ,
V_13 -> V_125 [ V_105 ] . V_85 . V_141 ) ;
if ( V_114 )
goto V_146;
}
F_43 ( V_24 , V_156 ,
F_76 ( F_61 ( V_24 -> V_23 [ 0 ] ) -> V_52 ) |
F_77 ( V_13 -> V_122 [ 0 ] . V_85 . V_133 ) ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_24 )
{
int V_34 ;
T_6 V_157 ;
const struct V_158 * V_159 ;
const struct V_160 * V_161 ;
struct V_162 * V_11 = V_24 -> V_82 ;
V_34 = F_79 ( & V_161 , V_163 , V_11 ) ;
if ( V_34 < 0 ) {
F_34 ( V_11 , L_25 V_163
L_26 , V_34 ) ;
return V_34 ;
}
V_159 = ( const struct V_158 * ) V_161 -> V_79 ;
V_157 = F_28 ( V_159 -> V_164 ) ;
if ( F_80 ( V_157 ) != V_165 ) {
V_34 = - V_166 ;
goto V_167;
}
if ( F_80 ( V_24 -> V_7 . V_168 ) != V_165 ||
V_157 > V_24 -> V_7 . V_168 ) {
V_34 = - F_81 ( V_24 , V_161 -> V_79 , V_161 -> V_169 ) ;
if ( ! V_34 )
F_82 ( V_11 , L_27
V_163 L_28 , & V_159 -> V_164 ) ;
}
V_167: F_83 ( V_161 ) ;
return V_34 ;
}
void * F_84 ( T_7 V_169 )
{
void * V_15 = F_85 ( V_169 , V_131 ) ;
if ( ! V_15 )
V_15 = F_86 ( V_169 ) ;
return V_15 ;
}
static void F_87 ( void * V_33 )
{
if ( F_88 ( V_33 ) )
F_89 ( V_33 ) ;
else
F_57 ( V_33 ) ;
}
static inline int F_90 ( const struct V_1 * V_24 )
{
return V_24 -> V_7 . V_170 ;
}
static T_6 F_91 ( struct V_10 * V_11 )
{
return F_92 ( V_11 ) -> V_171 ;
}
static void F_93 ( struct V_10 * V_11 , T_6 V_172 )
{
F_92 ( V_11 ) -> V_171 = V_172 ;
}
static int F_94 ( struct V_10 * V_11 , int V_173 )
{
switch ( V_173 ) {
case V_174 :
return F_11 ( V_175 ) ;
default:
return - V_176 ;
}
}
static int F_95 ( struct V_10 * V_11 )
{
return V_177 ;
}
static int F_96 ( struct V_10 * V_11 )
{
return V_178 ;
}
static void F_97 ( struct V_10 * V_11 , struct V_179 * V_180 )
{
struct V_1 * V_1 = F_92 ( V_11 ) ;
F_98 ( V_180 -> V_181 , V_182 , sizeof( V_180 -> V_181 ) ) ;
F_98 ( V_180 -> V_183 , V_184 , sizeof( V_180 -> V_183 ) ) ;
F_98 ( V_180 -> V_185 , F_99 ( V_1 -> V_96 ) ,
sizeof( V_180 -> V_185 ) ) ;
if ( V_1 -> V_7 . V_168 )
snprintf ( V_180 -> V_186 , sizeof( V_180 -> V_186 ) ,
L_29 ,
F_80 ( V_1 -> V_7 . V_168 ) ,
F_100 ( V_1 -> V_7 . V_168 ) ,
F_101 ( V_1 -> V_7 . V_168 ) ,
F_102 ( V_1 -> V_7 . V_168 ) ,
F_80 ( V_1 -> V_7 . V_187 ) ,
F_100 ( V_1 -> V_7 . V_187 ) ,
F_101 ( V_1 -> V_7 . V_187 ) ,
F_102 ( V_1 -> V_7 . V_187 ) ) ;
}
static void F_103 ( struct V_10 * V_11 , T_6 V_188 , T_3 * V_79 )
{
if ( V_188 == V_174 )
memcpy ( V_79 , V_175 , sizeof( V_175 ) ) ;
}
static void F_104 ( const struct V_1 * V_24 ,
const struct V_14 * V_15 , struct V_189 * V_13 )
{
int V_105 ;
const struct V_71 * V_190 = & V_24 -> V_66 . V_148 [ V_15 -> V_129 ] ;
const struct V_128 * V_191 = & V_24 -> V_66 . V_122 [ V_15 -> V_129 ] ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
for ( V_105 = 0 ; V_105 < V_15 -> V_113 ; V_105 ++ , V_191 ++ , V_190 ++ ) {
V_13 -> V_192 += V_190 -> V_192 ;
V_13 -> V_193 += V_190 -> V_194 ;
V_13 -> V_195 += V_191 -> V_89 . V_196 ;
V_13 -> V_197 += V_191 -> V_89 . V_197 ;
V_13 -> V_198 += V_190 -> V_198 ;
V_13 -> V_199 += V_191 -> V_89 . V_200 ;
V_13 -> V_201 += V_191 -> V_89 . V_202 ;
}
}
static void F_105 ( struct V_10 * V_11 , struct V_203 * V_89 ,
T_1 * V_79 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_106 ( V_1 , V_26 -> V_52 , (struct V_204 * ) V_79 ) ;
V_79 += sizeof( struct V_204 ) / sizeof( T_1 ) ;
F_104 ( V_1 , V_26 , (struct V_189 * ) V_79 ) ;
}
static inline unsigned int F_107 ( const struct V_1 * V_205 )
{
return 4 | ( V_205 -> V_7 . V_206 << 10 ) | ( 1 << 16 ) ;
}
static void F_108 ( struct V_1 * V_205 , void * V_207 , unsigned int V_208 ,
unsigned int V_209 )
{
T_6 * V_15 = V_207 + V_208 ;
for ( ; V_208 <= V_209 ; V_208 += sizeof( T_6 ) )
* V_15 ++ = F_41 ( V_205 , V_208 ) ;
}
static void F_109 ( struct V_10 * V_11 , struct V_210 * V_211 ,
void * V_207 )
{
static const unsigned int V_212 [] = {
0x1008 , 0x1108 ,
0x1180 , 0x11b4 ,
0x11fc , 0x123c ,
0x1300 , 0x173c ,
0x1800 , 0x18fc ,
0x3000 , 0x30d8 ,
0x30e0 , 0x5924 ,
0x5960 , 0x59d4 ,
0x5a00 , 0x5af8 ,
0x6000 , 0x6098 ,
0x6100 , 0x6150 ,
0x6200 , 0x6208 ,
0x6240 , 0x6248 ,
0x6280 , 0x6338 ,
0x6370 , 0x638c ,
0x6400 , 0x643c ,
0x6500 , 0x6524 ,
0x6a00 , 0x6a38 ,
0x6a60 , 0x6a78 ,
0x6b00 , 0x6b84 ,
0x6bf0 , 0x6c84 ,
0x6cf0 , 0x6d84 ,
0x6df0 , 0x6e84 ,
0x6ef0 , 0x6f84 ,
0x6ff0 , 0x7084 ,
0x70f0 , 0x7184 ,
0x71f0 , 0x7284 ,
0x72f0 , 0x7384 ,
0x73f0 , 0x7450 ,
0x7500 , 0x7530 ,
0x7600 , 0x761c ,
0x7680 , 0x76cc ,
0x7700 , 0x7798 ,
0x77c0 , 0x77fc ,
0x7900 , 0x79fc ,
0x7b00 , 0x7c38 ,
0x7d00 , 0x7efc ,
0x8dc0 , 0x8e1c ,
0x8e30 , 0x8e78 ,
0x8ea0 , 0x8f6c ,
0x8fc0 , 0x9074 ,
0x90fc , 0x90fc ,
0x9400 , 0x9458 ,
0x9600 , 0x96bc ,
0x9800 , 0x9808 ,
0x9820 , 0x983c ,
0x9850 , 0x9864 ,
0x9c00 , 0x9c6c ,
0x9c80 , 0x9cec ,
0x9d00 , 0x9d6c ,
0x9d80 , 0x9dec ,
0x9e00 , 0x9e6c ,
0x9e80 , 0x9eec ,
0x9f00 , 0x9f6c ,
0x9f80 , 0x9fec ,
0xd004 , 0xd03c ,
0xdfc0 , 0xdfe0 ,
0xe000 , 0xea7c ,
0xf000 , 0x11190 ,
0x19040 , 0x1906c ,
0x19078 , 0x19080 ,
0x1908c , 0x19124 ,
0x19150 , 0x191b0 ,
0x191d0 , 0x191e8 ,
0x19238 , 0x1924c ,
0x193f8 , 0x19474 ,
0x19490 , 0x194f8 ,
0x19800 , 0x19f30 ,
0x1a000 , 0x1a06c ,
0x1a0b0 , 0x1a120 ,
0x1a128 , 0x1a138 ,
0x1a190 , 0x1a1c4 ,
0x1a1fc , 0x1a1fc ,
0x1e040 , 0x1e04c ,
0x1e284 , 0x1e28c ,
0x1e2c0 , 0x1e2c0 ,
0x1e2e0 , 0x1e2e0 ,
0x1e300 , 0x1e384 ,
0x1e3c0 , 0x1e3c8 ,
0x1e440 , 0x1e44c ,
0x1e684 , 0x1e68c ,
0x1e6c0 , 0x1e6c0 ,
0x1e6e0 , 0x1e6e0 ,
0x1e700 , 0x1e784 ,
0x1e7c0 , 0x1e7c8 ,
0x1e840 , 0x1e84c ,
0x1ea84 , 0x1ea8c ,
0x1eac0 , 0x1eac0 ,
0x1eae0 , 0x1eae0 ,
0x1eb00 , 0x1eb84 ,
0x1ebc0 , 0x1ebc8 ,
0x1ec40 , 0x1ec4c ,
0x1ee84 , 0x1ee8c ,
0x1eec0 , 0x1eec0 ,
0x1eee0 , 0x1eee0 ,
0x1ef00 , 0x1ef84 ,
0x1efc0 , 0x1efc8 ,
0x1f040 , 0x1f04c ,
0x1f284 , 0x1f28c ,
0x1f2c0 , 0x1f2c0 ,
0x1f2e0 , 0x1f2e0 ,
0x1f300 , 0x1f384 ,
0x1f3c0 , 0x1f3c8 ,
0x1f440 , 0x1f44c ,
0x1f684 , 0x1f68c ,
0x1f6c0 , 0x1f6c0 ,
0x1f6e0 , 0x1f6e0 ,
0x1f700 , 0x1f784 ,
0x1f7c0 , 0x1f7c8 ,
0x1f840 , 0x1f84c ,
0x1fa84 , 0x1fa8c ,
0x1fac0 , 0x1fac0 ,
0x1fae0 , 0x1fae0 ,
0x1fb00 , 0x1fb84 ,
0x1fbc0 , 0x1fbc8 ,
0x1fc40 , 0x1fc4c ,
0x1fe84 , 0x1fe8c ,
0x1fec0 , 0x1fec0 ,
0x1fee0 , 0x1fee0 ,
0x1ff00 , 0x1ff84 ,
0x1ffc0 , 0x1ffc8 ,
0x20000 , 0x2002c ,
0x20100 , 0x2013c ,
0x20190 , 0x201c8 ,
0x20200 , 0x20318 ,
0x20400 , 0x20528 ,
0x20540 , 0x20614 ,
0x21000 , 0x21040 ,
0x2104c , 0x21060 ,
0x210c0 , 0x210ec ,
0x21200 , 0x21268 ,
0x21270 , 0x21284 ,
0x212fc , 0x21388 ,
0x21400 , 0x21404 ,
0x21500 , 0x21518 ,
0x2152c , 0x2153c ,
0x21550 , 0x21554 ,
0x21600 , 0x21600 ,
0x21608 , 0x21628 ,
0x21630 , 0x2163c ,
0x21700 , 0x2171c ,
0x21780 , 0x2178c ,
0x21800 , 0x21c38 ,
0x21c80 , 0x21d7c ,
0x21e00 , 0x21e04 ,
0x22000 , 0x2202c ,
0x22100 , 0x2213c ,
0x22190 , 0x221c8 ,
0x22200 , 0x22318 ,
0x22400 , 0x22528 ,
0x22540 , 0x22614 ,
0x23000 , 0x23040 ,
0x2304c , 0x23060 ,
0x230c0 , 0x230ec ,
0x23200 , 0x23268 ,
0x23270 , 0x23284 ,
0x232fc , 0x23388 ,
0x23400 , 0x23404 ,
0x23500 , 0x23518 ,
0x2352c , 0x2353c ,
0x23550 , 0x23554 ,
0x23600 , 0x23600 ,
0x23608 , 0x23628 ,
0x23630 , 0x2363c ,
0x23700 , 0x2371c ,
0x23780 , 0x2378c ,
0x23800 , 0x23c38 ,
0x23c80 , 0x23d7c ,
0x23e00 , 0x23e04 ,
0x24000 , 0x2402c ,
0x24100 , 0x2413c ,
0x24190 , 0x241c8 ,
0x24200 , 0x24318 ,
0x24400 , 0x24528 ,
0x24540 , 0x24614 ,
0x25000 , 0x25040 ,
0x2504c , 0x25060 ,
0x250c0 , 0x250ec ,
0x25200 , 0x25268 ,
0x25270 , 0x25284 ,
0x252fc , 0x25388 ,
0x25400 , 0x25404 ,
0x25500 , 0x25518 ,
0x2552c , 0x2553c ,
0x25550 , 0x25554 ,
0x25600 , 0x25600 ,
0x25608 , 0x25628 ,
0x25630 , 0x2563c ,
0x25700 , 0x2571c ,
0x25780 , 0x2578c ,
0x25800 , 0x25c38 ,
0x25c80 , 0x25d7c ,
0x25e00 , 0x25e04 ,
0x26000 , 0x2602c ,
0x26100 , 0x2613c ,
0x26190 , 0x261c8 ,
0x26200 , 0x26318 ,
0x26400 , 0x26528 ,
0x26540 , 0x26614 ,
0x27000 , 0x27040 ,
0x2704c , 0x27060 ,
0x270c0 , 0x270ec ,
0x27200 , 0x27268 ,
0x27270 , 0x27284 ,
0x272fc , 0x27388 ,
0x27400 , 0x27404 ,
0x27500 , 0x27518 ,
0x2752c , 0x2753c ,
0x27550 , 0x27554 ,
0x27600 , 0x27600 ,
0x27608 , 0x27628 ,
0x27630 , 0x2763c ,
0x27700 , 0x2771c ,
0x27780 , 0x2778c ,
0x27800 , 0x27c38 ,
0x27c80 , 0x27d7c ,
0x27e00 , 0x27e04
} ;
int V_105 ;
struct V_1 * V_205 = F_92 ( V_11 ) ;
V_211 -> V_183 = F_107 ( V_205 ) ;
memset ( V_207 , 0 , V_177 ) ;
for ( V_105 = 0 ; V_105 < F_11 ( V_212 ) ; V_105 += 2 )
F_108 ( V_205 , V_207 , V_212 [ V_105 ] , V_212 [ V_105 + 1 ] ) ;
}
static int F_110 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
if ( ! F_7 ( V_11 ) )
return - V_213 ;
if ( V_15 -> V_16 . V_214 != V_215 )
return - V_166 ;
F_111 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ) ;
return 0 ;
}
static int F_112 ( struct V_10 * V_11 ,
enum V_216 V_217 )
{
unsigned int V_172 ;
struct V_1 * V_24 = F_92 ( V_11 ) ;
if ( V_217 == V_218 )
V_172 = 0xffff ;
else if ( V_217 == V_219 )
V_172 = 0 ;
else
return - V_166 ;
return F_113 ( V_24 , V_24 -> V_41 , F_61 ( V_11 ) -> V_42 , V_172 ) ;
}
static unsigned int F_114 ( unsigned int type , unsigned int V_220 )
{
unsigned int V_100 = 0 ;
if ( type == V_221 || type == V_222 ||
type == V_223 ) {
V_100 |= V_224 ;
if ( V_220 & V_225 )
V_100 |= V_226 ;
if ( V_220 & V_227 )
V_100 |= V_228 ;
if ( V_220 & V_229 )
V_100 |= V_230 ;
} else if ( type == V_231 || type == V_232 ) {
V_100 |= V_233 ;
if ( V_220 & V_227 )
V_100 |= V_234 ;
if ( V_220 & V_229 )
V_100 |= V_235 ;
} else if ( type == V_236 )
V_100 |= V_233 | V_237 ;
else if ( type == V_238 )
V_100 |= V_233 | V_239 |
V_237 | V_234 ;
else if ( type == V_240 )
V_100 |= V_233 | V_239 |
V_237 | V_234 |
V_235 ;
else if ( type == V_241 ||
type == V_242 || type == V_243 )
V_100 |= V_244 ;
if ( V_220 & V_245 )
V_100 |= V_246 ;
return V_100 ;
}
static unsigned int F_115 ( unsigned int V_220 )
{
unsigned int V_100 = 0 ;
if ( V_220 & V_247 )
V_100 |= V_225 ;
if ( V_220 & V_248 )
V_100 |= V_227 ;
if ( V_220 & V_249 )
V_100 |= V_229 ;
return V_100 ;
}
static int F_116 ( struct V_10 * V_11 , struct V_250 * V_251 )
{
const struct V_14 * V_15 = F_5 ( V_11 ) ;
if ( V_15 -> V_252 == V_221 ||
V_15 -> V_252 == V_222 ||
V_15 -> V_252 == V_223 )
V_251 -> V_23 = V_253 ;
else if ( V_15 -> V_252 == V_241 ||
V_15 -> V_252 == V_242 )
V_251 -> V_23 = V_254 ;
else if ( V_15 -> V_252 == V_243 ) {
if ( V_15 -> V_27 == V_255 ||
V_15 -> V_27 == V_256 )
V_251 -> V_23 = V_257 ;
else
V_251 -> V_23 = V_254 ;
} else
V_251 -> V_23 = V_258 ;
if ( V_15 -> V_259 >= 0 ) {
V_251 -> V_260 = V_15 -> V_259 ;
V_251 -> V_261 = V_262 ;
V_251 -> V_263 = V_15 -> V_252 == V_221 ?
V_264 : V_265 ;
} else {
V_251 -> V_260 = 0 ;
V_251 -> V_261 = V_266 ;
V_251 -> V_263 = 0 ;
}
V_251 -> V_267 = F_114 ( V_15 -> V_252 , V_15 -> V_16 . V_267 ) ;
V_251 -> V_268 = F_114 ( V_15 -> V_252 ,
V_15 -> V_16 . V_268 ) ;
F_117 ( V_251 ,
F_3 ( V_11 ) ? V_15 -> V_16 . V_17 : 0 ) ;
V_251 -> V_269 = V_270 ;
V_251 -> V_214 = V_15 -> V_16 . V_214 ;
V_251 -> V_271 = 0 ;
V_251 -> V_272 = 0 ;
return 0 ;
}
static unsigned int F_118 ( int V_17 )
{
if ( V_17 == V_20 )
return V_225 ;
if ( V_17 == V_19 )
return V_227 ;
if ( V_17 == V_18 )
return V_229 ;
return 0 ;
}
static int F_119 ( struct V_10 * V_11 , struct V_250 * V_251 )
{
unsigned int V_273 ;
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_274 * V_275 = & V_15 -> V_16 ;
T_6 V_17 = F_120 ( V_251 ) ;
if ( V_251 -> V_269 != V_270 )
return - V_166 ;
if ( ! ( V_275 -> V_267 & V_245 ) ) {
if ( V_251 -> V_214 == V_276 &&
( V_275 -> V_267 & F_118 ( V_17 ) ) )
return 0 ;
return - V_166 ;
}
if ( V_251 -> V_214 == V_276 ) {
V_273 = F_118 ( V_17 ) ;
if ( ! ( V_275 -> V_267 & V_273 ) || ( V_17 == V_19 ) ||
( V_17 == V_18 ) )
return - V_166 ;
V_275 -> V_277 = V_273 ;
V_275 -> V_268 = 0 ;
} else {
V_273 = F_115 ( V_251 -> V_268 ) ;
if ( ! ( V_275 -> V_267 & V_273 ) )
return - V_166 ;
V_275 -> V_277 = 0 ;
V_275 -> V_268 = V_273 | V_245 ;
}
V_275 -> V_214 = V_251 -> V_214 ;
if ( F_7 ( V_11 ) )
return F_23 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ,
V_275 ) ;
return 0 ;
}
static void F_121 ( struct V_10 * V_11 ,
struct V_278 * V_279 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
V_279 -> V_214 = ( V_15 -> V_16 . V_280 & V_281 ) != 0 ;
V_279 -> V_282 = ( V_15 -> V_16 . V_12 & V_283 ) != 0 ;
V_279 -> V_284 = ( V_15 -> V_16 . V_12 & V_285 ) != 0 ;
}
static int F_122 ( struct V_10 * V_11 ,
struct V_278 * V_279 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_274 * V_275 = & V_15 -> V_16 ;
if ( V_279 -> V_214 == V_276 )
V_275 -> V_280 = 0 ;
else if ( V_275 -> V_267 & V_245 )
V_275 -> V_280 = V_281 ;
else
return - V_166 ;
if ( V_279 -> V_282 )
V_275 -> V_280 |= V_283 ;
if ( V_279 -> V_284 )
V_275 -> V_280 |= V_285 ;
if ( F_7 ( V_11 ) )
return F_23 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ,
V_275 ) ;
return 0 ;
}
static void F_123 ( struct V_10 * V_11 , struct V_286 * V_287 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_66 * V_13 = & V_26 -> V_1 -> V_66 ;
V_287 -> V_288 = V_289 ;
V_287 -> V_290 = V_291 ;
V_287 -> V_292 = 0 ;
V_287 -> V_293 = V_294 ;
V_287 -> V_295 = V_13 -> V_122 [ V_26 -> V_129 ] . V_149 . V_169 - 8 ;
V_287 -> V_296 = V_13 -> V_122 [ V_26 -> V_129 ] . V_85 . V_169 ;
V_287 -> V_297 = 0 ;
V_287 -> V_298 = V_13 -> V_148 [ V_26 -> V_129 ] . V_54 . V_169 ;
}
static int F_124 ( struct V_10 * V_11 , struct V_286 * V_287 )
{
int V_105 ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
struct V_66 * V_13 = & V_1 -> V_66 ;
if ( V_287 -> V_295 > V_289 || V_287 -> V_297 ||
V_287 -> V_298 > V_294 ||
V_287 -> V_296 > V_291 ||
V_287 -> V_296 < V_299 ||
V_287 -> V_295 < V_300 || V_287 -> V_298 < V_301 )
return - V_166 ;
if ( V_1 -> V_45 & V_302 )
return - V_303 ;
for ( V_105 = 0 ; V_105 < V_26 -> V_113 ; ++ V_105 ) {
V_13 -> V_148 [ V_26 -> V_129 + V_105 ] . V_54 . V_169 = V_287 -> V_298 ;
V_13 -> V_122 [ V_26 -> V_129 + V_105 ] . V_149 . V_169 = V_287 -> V_295 + 8 ;
V_13 -> V_122 [ V_26 -> V_129 + V_105 ] . V_85 . V_169 = V_287 -> V_296 ;
}
return 0 ;
}
static int F_125 ( const struct V_66 * V_13 , int time )
{
int V_105 , V_304 , V_305 = 0 , V_306 = V_307 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_308 ) ; V_105 ++ ) {
V_304 = time - V_13 -> V_308 [ V_105 ] ;
if ( V_304 < 0 )
V_304 = - V_304 ;
if ( V_304 < V_306 ) {
V_306 = V_304 ;
V_305 = V_105 ;
}
}
return V_305 ;
}
static int F_126 ( const struct V_66 * V_13 , int V_309 )
{
int V_105 , V_304 , V_305 = 0 , V_306 = V_307 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_310 ) ; V_105 ++ ) {
V_304 = V_309 - V_13 -> V_310 [ V_105 ] ;
if ( V_304 < 0 )
V_304 = - V_304 ;
if ( V_304 < V_306 ) {
V_306 = V_304 ;
V_305 = V_105 ;
}
}
return V_305 ;
}
static unsigned int F_127 ( const struct V_1 * V_24 ,
const struct V_53 * V_54 )
{
unsigned int V_151 = V_54 -> V_140 >> 1 ;
return V_151 < V_311 ? V_24 -> V_66 . V_308 [ V_151 ] : 0 ;
}
static int F_128 ( struct V_1 * V_24 , struct V_53 * V_54 ,
unsigned int V_312 , unsigned int V_313 )
{
if ( ( V_312 | V_313 ) == 0 )
V_313 = 1 ;
if ( V_313 ) {
int V_114 ;
T_6 V_100 , V_314 ;
V_314 = F_126 ( & V_24 -> V_66 , V_313 ) ;
if ( V_54 -> V_110 && V_54 -> V_315 != V_314 ) {
V_100 = F_129 ( V_316 ) |
F_130 ( V_317 ) |
F_131 ( V_54 -> V_141 ) ;
V_114 = F_132 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 1 , & V_100 ,
& V_314 ) ;
if ( V_114 )
return V_114 ;
}
V_54 -> V_315 = V_314 ;
}
V_312 = V_312 == 0 ? 6 : F_125 ( & V_24 -> V_66 , V_312 ) ;
V_54 -> V_140 = F_133 ( V_312 ) | ( V_313 > 0 ? V_318 : 0 ) ;
return 0 ;
}
static int F_134 ( struct V_10 * V_11 , struct V_319 * V_320 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_24 = V_26 -> V_1 ;
return F_128 ( V_24 , & V_24 -> V_66 . V_122 [ V_26 -> V_129 ] . V_85 ,
V_320 -> V_321 , V_320 -> V_322 ) ;
}
static int F_135 ( struct V_10 * V_11 , struct V_319 * V_320 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_1 * V_24 = V_26 -> V_1 ;
const struct V_53 * V_323 = & V_24 -> V_66 . V_122 [ V_26 -> V_129 ] . V_85 ;
V_320 -> V_321 = F_127 ( V_24 , V_323 ) ;
V_320 -> V_322 = ( V_323 -> V_140 & V_318 ) ?
V_24 -> V_66 . V_310 [ V_323 -> V_315 ] : 0 ;
return 0 ;
}
static int F_136 ( unsigned int V_324 , unsigned int V_41 , unsigned int V_325 )
{
V_41 *= V_325 ;
if ( V_324 < 1024 )
return V_324 + ( 31 << 10 ) ;
if ( V_324 < 1024 + V_41 )
return 31744 - V_41 + V_324 - 1024 ;
if ( V_324 < V_178 )
return V_324 - 1024 - V_41 ;
return - V_166 ;
}
static int F_137 ( struct V_1 * V_24 , unsigned int V_324 , T_6 * V_100 )
{
int V_326 = F_136 ( V_324 , V_24 -> V_41 , V_327 ) ;
if ( V_326 >= 0 )
V_326 = F_138 ( V_24 -> V_96 , V_326 , sizeof( T_6 ) , V_100 ) ;
return V_326 < 0 ? V_326 : 0 ;
}
static int F_139 ( struct V_1 * V_24 , unsigned int V_324 , T_6 V_100 )
{
int V_326 = F_136 ( V_324 , V_24 -> V_41 , V_327 ) ;
if ( V_326 >= 0 )
V_326 = F_140 ( V_24 -> V_96 , V_326 , sizeof( T_6 ) , & V_100 ) ;
return V_326 < 0 ? V_326 : 0 ;
}
static int F_141 ( struct V_10 * V_11 , struct V_328 * V_287 ,
T_3 * V_79 )
{
int V_105 , V_114 = 0 ;
struct V_1 * V_1 = F_92 ( V_11 ) ;
T_3 * V_207 = F_55 ( V_178 , V_131 ) ;
if ( ! V_207 )
return - V_132 ;
V_287 -> V_329 = V_330 ;
for ( V_105 = V_287 -> V_331 & ~ 3 ; ! V_114 && V_105 < V_287 -> V_331 + V_287 -> V_332 ; V_105 += 4 )
V_114 = F_137 ( V_1 , V_105 , ( T_6 * ) & V_207 [ V_105 ] ) ;
if ( ! V_114 )
memcpy ( V_79 , V_207 + V_287 -> V_331 , V_287 -> V_332 ) ;
F_57 ( V_207 ) ;
return V_114 ;
}
static int F_142 ( struct V_10 * V_11 , struct V_328 * V_333 ,
T_3 * V_79 )
{
T_3 * V_207 ;
int V_114 = 0 ;
T_6 V_334 , V_335 , * V_15 ;
struct V_1 * V_1 = F_92 ( V_11 ) ;
if ( V_333 -> V_329 != V_330 )
return - V_166 ;
V_334 = V_333 -> V_331 & ~ 3 ;
V_335 = ( V_333 -> V_332 + ( V_333 -> V_331 & 3 ) + 3 ) & ~ 3 ;
if ( V_1 -> V_41 > 0 ) {
T_6 V_208 = 1024 + V_1 -> V_41 * V_327 ;
if ( V_334 < V_208 ||
V_334 + V_335 > V_208 + V_327 )
return - V_336 ;
}
if ( V_334 != V_333 -> V_331 || V_335 != V_333 -> V_332 ) {
V_207 = F_55 ( V_335 , V_131 ) ;
if ( ! V_207 )
return - V_132 ;
V_114 = F_137 ( V_1 , V_334 , ( T_6 * ) V_207 ) ;
if ( ! V_114 && V_335 > 4 )
V_114 = F_137 ( V_1 ,
V_334 + V_335 - 4 ,
( T_6 * ) & V_207 [ V_335 - 4 ] ) ;
if ( V_114 )
goto V_167;
memcpy ( V_207 + ( V_333 -> V_331 & 3 ) , V_79 , V_333 -> V_332 ) ;
} else
V_207 = V_79 ;
V_114 = F_143 ( V_1 , false ) ;
if ( V_114 )
goto V_167;
for ( V_15 = ( T_6 * ) V_207 ; ! V_114 && V_335 ; V_335 -= 4 , V_15 ++ ) {
V_114 = F_139 ( V_1 , V_334 , * V_15 ) ;
V_334 += 4 ;
}
if ( ! V_114 )
V_114 = F_143 ( V_1 , true ) ;
V_167:
if ( V_207 != V_79 )
F_57 ( V_207 ) ;
return V_114 ;
}
static int F_144 ( struct V_10 * V_136 , struct V_337 * V_338 )
{
int V_34 ;
const struct V_160 * V_161 ;
struct V_1 * V_24 = F_92 ( V_136 ) ;
V_338 -> V_79 [ sizeof( V_338 -> V_79 ) - 1 ] = '\0' ;
V_34 = F_79 ( & V_161 , V_338 -> V_79 , V_24 -> V_82 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_81 ( V_24 , V_161 -> V_79 , V_161 -> V_169 ) ;
F_83 ( V_161 ) ;
if ( ! V_34 )
F_82 ( V_24 -> V_82 , L_30 , V_338 -> V_79 ) ;
return V_34 ;
}
static void F_145 ( struct V_10 * V_11 , struct V_339 * V_340 )
{
V_340 -> V_267 = V_341 | V_342 ;
V_340 -> V_343 = F_92 ( V_11 ) -> V_340 ;
memset ( & V_340 -> V_344 , 0 , sizeof( V_340 -> V_344 ) ) ;
}
static int F_146 ( struct V_10 * V_11 , struct V_339 * V_340 )
{
int V_114 = 0 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_340 -> V_343 & ~ V_345 )
return - V_166 ;
F_147 ( V_26 -> V_1 , V_26 -> V_52 ,
( V_340 -> V_343 & V_342 ) ? V_11 -> V_51 : NULL ) ;
if ( V_340 -> V_343 & V_341 ) {
V_114 = F_148 ( V_26 -> V_1 , V_26 -> V_52 , 0xfe , ~ 0ULL ,
~ 0ULL , 0 , false ) ;
if ( ! V_114 )
V_114 = F_148 ( V_26 -> V_1 , V_26 -> V_52 , 1 ,
~ 6ULL , ~ 0ULL , V_346 , true ) ;
} else
F_148 ( V_26 -> V_1 , V_26 -> V_52 , 0 , 0 , 0 , 0 , false ) ;
return V_114 ;
}
static int F_149 ( struct V_10 * V_11 , T_8 V_48 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
T_8 V_347 = V_11 -> V_48 ^ V_48 ;
int V_114 ;
if ( ! ( V_347 & V_49 ) )
return 0 ;
V_114 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_48 & V_49 ) , true ) ;
if ( F_150 ( V_114 ) )
V_11 -> V_48 = V_48 ^ V_49 ;
return V_114 ;
}
static T_6 F_151 ( struct V_10 * V_11 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
return V_26 -> V_130 ;
}
static int F_152 ( struct V_10 * V_11 , T_6 * V_15 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
unsigned int V_108 = V_26 -> V_130 ;
while ( V_108 -- )
V_15 [ V_108 ] = V_26 -> V_127 [ V_108 ] ;
return 0 ;
}
static int F_153 ( struct V_10 * V_11 , const T_6 * V_15 )
{
unsigned int V_105 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
for ( V_105 = 0 ; V_105 < V_26 -> V_130 ; V_105 ++ )
V_26 -> V_127 [ V_105 ] = V_15 [ V_105 ] ;
if ( V_26 -> V_1 -> V_45 & V_302 )
return F_54 ( V_26 , V_26 -> V_127 ) ;
return 0 ;
}
static int F_154 ( struct V_10 * V_11 , struct V_348 * V_180 ,
T_6 * V_349 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
switch ( V_180 -> V_251 ) {
case V_350 : {
unsigned int V_100 = V_26 -> V_351 ;
V_180 -> V_79 = 0 ;
switch ( V_180 -> V_352 ) {
case V_353 :
if ( V_100 & V_354 )
V_180 -> V_79 = V_355 | V_356 |
V_357 | V_358 ;
else if ( V_100 & V_359 )
V_180 -> V_79 = V_355 | V_356 ;
break;
case V_360 :
if ( ( V_100 & V_354 ) &&
( V_100 & V_361 ) )
V_180 -> V_79 = V_355 | V_356 |
V_357 | V_358 ;
else if ( V_100 & V_359 )
V_180 -> V_79 = V_355 | V_356 ;
break;
case V_362 :
case V_363 :
case V_364 :
if ( V_100 & V_359 )
V_180 -> V_79 = V_355 | V_356 ;
break;
case V_365 :
if ( V_100 & V_366 )
V_180 -> V_79 = V_355 | V_356 |
V_357 | V_358 ;
else if ( V_100 & V_367 )
V_180 -> V_79 = V_355 | V_356 ;
break;
case V_368 :
if ( ( V_100 & V_366 ) &&
( V_100 & V_361 ) )
V_180 -> V_79 = V_355 | V_356 |
V_357 | V_358 ;
else if ( V_100 & V_367 )
V_180 -> V_79 = V_355 | V_356 ;
break;
case V_369 :
case V_370 :
case V_371 :
if ( V_100 & V_367 )
V_180 -> V_79 = V_355 | V_356 ;
break;
}
return 0 ;
}
case V_372 :
V_180 -> V_79 = V_26 -> V_113 ;
return 0 ;
}
return - V_176 ;
}
static int F_155 ( struct V_373 * V_373 , struct V_374 * V_374 )
{
V_374 -> V_375 = V_373 -> V_376 ;
return 0 ;
}
static T_9 F_156 ( struct V_374 * V_374 , char T_10 * V_207 , T_7 V_377 ,
T_11 * V_378 )
{
T_11 V_379 = * V_378 ;
T_11 V_380 = V_374 -> V_381 . V_382 -> V_383 -> V_384 ;
unsigned int V_385 = ( V_386 ) V_374 -> V_375 & 3 ;
struct V_1 * V_24 = V_374 -> V_375 - V_385 ;
if ( V_379 < 0 )
return - V_166 ;
if ( V_379 >= V_380 )
return 0 ;
if ( V_377 > V_380 - V_379 )
V_377 = V_380 - V_379 ;
while ( V_377 ) {
T_7 V_332 ;
int V_34 , V_387 ;
T_12 V_79 [ 16 ] ;
if ( V_385 == V_388 )
V_34 = F_157 ( V_24 , V_379 , V_79 , NULL ) ;
else
V_34 = F_158 ( V_24 , V_385 , V_379 , V_79 , NULL ) ;
if ( V_34 )
return V_34 ;
V_387 = V_379 % sizeof( V_79 ) ;
V_332 = F_159 ( V_377 , sizeof( V_79 ) - V_387 ) ;
if ( F_160 ( V_207 , ( T_3 * ) V_79 + V_387 , V_332 ) )
return - V_389 ;
V_207 += V_332 ;
V_379 += V_332 ;
V_377 -= V_332 ;
}
V_377 = V_379 - * V_378 ;
* V_378 = V_379 ;
return V_377 ;
}
static void T_13 F_161 ( struct V_1 * V_24 , const char * V_111 ,
unsigned int V_151 , unsigned int V_390 )
{
struct V_382 * V_391 ;
V_391 = F_162 ( V_111 , V_392 , V_24 -> V_393 ,
( void * ) V_24 + V_151 , & V_394 ) ;
if ( V_391 && V_391 -> V_383 )
V_391 -> V_383 -> V_384 = V_390 << 20 ;
}
static int T_13 F_163 ( struct V_1 * V_24 )
{
int V_105 ;
if ( F_164 ( V_24 -> V_393 ) )
return - 1 ;
V_105 = F_41 ( V_24 , V_395 ) ;
if ( V_105 & V_396 )
F_161 ( V_24 , L_31 , V_397 , 5 ) ;
if ( V_105 & V_398 )
F_161 ( V_24 , L_32 , V_399 , 5 ) ;
if ( V_105 & V_400 )
F_161 ( V_24 , L_33 , V_388 ,
F_165 ( F_41 ( V_24 , V_401 ) ) ) ;
if ( V_24 -> V_402 )
F_162 ( L_34 , V_392 , V_24 -> V_393 , V_24 ,
& V_403 ) ;
return 0 ;
}
int F_166 ( struct V_404 * V_147 , void * V_79 )
{
int V_405 = - 1 ;
F_167 ( & V_147 -> V_406 ) ;
if ( V_147 -> V_407 ) {
union V_408 * V_15 = V_147 -> V_407 ;
V_405 = V_15 - V_147 -> V_409 ;
V_147 -> V_407 = V_15 -> V_410 ;
V_15 -> V_79 = V_79 ;
V_147 -> V_411 ++ ;
}
F_168 ( & V_147 -> V_406 ) ;
return V_405 ;
}
void F_169 ( struct V_404 * V_147 , unsigned int V_405 )
{
union V_408 * V_15 = & V_147 -> V_409 [ V_405 ] ;
F_167 ( & V_147 -> V_406 ) ;
V_15 -> V_410 = V_147 -> V_407 ;
V_147 -> V_407 = V_15 ;
V_147 -> V_411 -- ;
F_168 ( & V_147 -> V_406 ) ;
}
int F_170 ( struct V_404 * V_147 , int V_412 , void * V_79 )
{
int V_413 ;
F_167 ( & V_147 -> V_414 ) ;
if ( V_412 == V_415 ) {
V_413 = F_171 ( V_147 -> V_416 , V_147 -> V_417 ) ;
if ( V_413 < V_147 -> V_417 )
F_172 ( V_413 , V_147 -> V_416 ) ;
else
V_413 = - 1 ;
} else {
V_413 = F_173 ( V_147 -> V_416 , V_147 -> V_417 , 2 ) ;
if ( V_413 < 0 )
V_413 = - 1 ;
}
if ( V_413 >= 0 ) {
V_147 -> V_418 [ V_413 ] . V_79 = V_79 ;
V_413 += V_147 -> V_419 ;
V_147 -> V_420 ++ ;
}
F_168 ( & V_147 -> V_414 ) ;
return V_413 ;
}
void F_174 ( struct V_404 * V_147 , unsigned int V_413 , int V_412 )
{
V_413 -= V_147 -> V_419 ;
F_167 ( & V_147 -> V_414 ) ;
if ( V_412 == V_415 )
F_175 ( V_413 , V_147 -> V_416 ) ;
else
F_176 ( V_147 -> V_416 , V_413 , 2 ) ;
V_147 -> V_418 [ V_413 ] . V_79 = NULL ;
V_147 -> V_420 -- ;
F_168 ( & V_147 -> V_414 ) ;
}
static void F_177 ( struct V_421 * V_422 , unsigned int V_423 ,
unsigned int V_424 )
{
struct V_425 * V_426 ;
F_178 ( V_422 , V_427 , V_423 ) ;
V_426 = (struct V_425 * ) F_179 ( V_422 , sizeof( * V_426 ) ) ;
F_180 ( V_426 , V_424 ) ;
F_181 ( V_426 ) = F_182 ( F_183 ( V_428 , V_424 ) ) ;
}
static void F_184 ( struct V_404 * V_147 , unsigned int V_423 ,
unsigned int V_424 )
{
void * * V_15 = & V_147 -> V_429 [ V_424 ] ;
struct V_1 * V_24 = F_29 ( V_147 , struct V_1 , V_430 ) ;
F_167 ( & V_24 -> V_431 ) ;
* V_15 = V_24 -> V_432 ;
V_24 -> V_432 = ( void * * ) ( ( V_386 ) V_15 | V_423 ) ;
if ( ! V_24 -> V_433 ) {
V_24 -> V_433 = true ;
F_185 ( & V_24 -> V_434 ) ;
}
F_168 ( & V_24 -> V_431 ) ;
}
static void F_186 ( struct V_435 * V_436 )
{
struct V_421 * V_422 ;
struct V_1 * V_24 ;
V_24 = F_29 ( V_436 , struct V_1 , V_434 ) ;
F_167 ( & V_24 -> V_431 ) ;
while ( V_24 -> V_432 ) {
void * * V_15 = V_24 -> V_432 ;
unsigned int V_423 = ( V_386 ) V_15 & 3 ;
V_15 = ( void * ) V_15 - V_423 ;
V_24 -> V_432 = * V_15 ;
* V_15 = NULL ;
F_168 ( & V_24 -> V_431 ) ;
while ( ! ( V_422 = F_187 ( sizeof( struct V_425 ) ,
V_131 ) ) )
F_188 ( 1 ) ;
F_177 ( V_422 , V_423 , V_15 - V_24 -> V_430 . V_429 ) ;
F_189 ( V_24 , V_422 ) ;
F_167 ( & V_24 -> V_431 ) ;
}
V_24 -> V_433 = false ;
F_168 ( & V_24 -> V_431 ) ;
}
void F_190 ( struct V_404 * V_147 , unsigned int V_423 , unsigned int V_424 )
{
void * V_437 ;
struct V_421 * V_422 ;
struct V_1 * V_24 = F_29 ( V_147 , struct V_1 , V_430 ) ;
V_437 = V_147 -> V_429 [ V_424 ] ;
V_422 = F_187 ( sizeof( struct V_425 ) , V_438 ) ;
if ( F_26 ( V_422 ) ) {
V_147 -> V_429 [ V_424 ] = NULL ;
F_177 ( V_422 , V_423 , V_424 ) ;
F_189 ( V_24 , V_422 ) ;
} else
F_184 ( V_147 , V_423 , V_424 ) ;
if ( V_437 )
F_191 ( & V_147 -> V_439 ) ;
}
static int F_192 ( struct V_404 * V_147 )
{
T_7 V_169 ;
unsigned int V_440 = V_147 -> V_440 ;
V_169 = V_147 -> V_441 * sizeof( * V_147 -> V_429 ) + V_440 * sizeof( * V_147 -> V_409 ) +
V_147 -> V_417 * sizeof( * V_147 -> V_418 ) +
F_193 ( V_147 -> V_417 ) * sizeof( long ) ;
V_147 -> V_429 = F_84 ( V_169 ) ;
if ( ! V_147 -> V_429 )
return - V_132 ;
V_147 -> V_409 = (union V_408 * ) & V_147 -> V_429 [ V_147 -> V_441 ] ;
V_147 -> V_418 = (struct V_442 * ) & V_147 -> V_409 [ V_440 ] ;
V_147 -> V_416 = ( unsigned long * ) & V_147 -> V_418 [ V_147 -> V_417 ] ;
F_194 ( & V_147 -> V_414 ) ;
F_194 ( & V_147 -> V_406 ) ;
V_147 -> V_420 = 0 ;
V_147 -> V_407 = NULL ;
V_147 -> V_411 = 0 ;
F_195 ( & V_147 -> V_439 , 0 ) ;
if ( V_440 ) {
while ( -- V_440 )
V_147 -> V_409 [ V_440 - 1 ] . V_410 = & V_147 -> V_409 [ V_440 ] ;
V_147 -> V_407 = V_147 -> V_409 ;
}
F_69 ( V_147 -> V_416 , V_147 -> V_417 ) ;
return 0 ;
}
int F_196 ( const struct V_10 * V_11 , unsigned int V_413 ,
T_12 V_443 , T_14 V_444 , unsigned int V_445 )
{
unsigned int V_423 ;
struct V_421 * V_422 ;
struct V_1 * V_24 ;
struct V_446 * V_426 ;
V_422 = F_187 ( sizeof( * V_426 ) , V_131 ) ;
if ( ! V_422 )
return - V_132 ;
V_24 = F_92 ( V_11 ) ;
V_426 = (struct V_446 * ) F_179 ( V_422 , sizeof( * V_426 ) ) ;
F_180 ( V_426 , 0 ) ;
F_181 ( V_426 ) = F_182 ( F_183 ( V_447 , V_413 ) ) ;
V_426 -> V_448 = V_444 ;
V_426 -> V_449 = F_197 ( 0 ) ;
V_426 -> V_450 = V_443 ;
V_426 -> V_451 = F_182 ( 0 ) ;
V_423 = F_60 ( & V_24 -> V_66 , V_445 ) ;
V_426 -> V_452 = F_198 ( F_199 ( V_423 ) ) ;
V_426 -> V_453 = F_198 ( V_454 |
V_455 | F_200 ( V_445 ) ) ;
return F_201 ( V_24 , V_422 ) ;
}
unsigned int F_202 ( const unsigned short * V_456 , unsigned short V_43 ,
unsigned int * V_151 )
{
unsigned int V_105 = 0 ;
while ( V_105 < V_457 - 1 && V_456 [ V_105 + 1 ] <= V_43 )
++ V_105 ;
if ( V_151 )
* V_151 = V_105 ;
return V_456 [ V_105 ] ;
}
unsigned int F_203 ( const struct V_10 * V_11 )
{
return F_61 ( V_11 ) -> V_52 ;
}
unsigned int F_204 ( const struct V_10 * V_11 )
{
return F_61 ( V_11 ) -> V_42 ;
}
unsigned int F_205 ( const struct V_10 * V_11 )
{
return F_61 ( V_11 ) -> V_21 ;
}
void F_206 ( struct V_458 * V_96 , struct V_459 * V_460 ,
struct V_459 * V_461 )
{
struct V_1 * V_24 = F_207 ( V_96 ) ;
F_208 ( & V_24 -> V_462 ) ;
F_209 ( V_24 , V_460 , V_461 ) ;
F_210 ( & V_24 -> V_462 ) ;
}
void F_211 ( struct V_10 * V_11 , unsigned int V_463 ,
const unsigned int * V_464 )
{
struct V_1 * V_24 = F_92 ( V_11 ) ;
F_43 ( V_24 , V_465 , V_463 ) ;
F_43 ( V_24 , V_466 , F_212 ( V_464 [ 0 ] ) |
F_213 ( V_464 [ 1 ] ) | F_214 ( V_464 [ 2 ] ) |
F_215 ( V_464 [ 3 ] ) ) ;
}
static void F_216 ( struct V_467 * V_468 )
{
const struct V_162 * V_469 ;
const struct V_10 * V_136 = V_468 -> V_11 ;
if ( V_136 -> V_470 & V_471 )
V_136 = F_217 ( V_136 ) ;
V_469 = V_136 -> V_11 . V_469 ;
if ( V_469 && V_469 -> V_181 == & V_472 . V_181 )
F_218 ( F_219 ( V_469 ) , V_468 ) ;
}
static int F_220 ( struct V_473 * V_474 , unsigned long V_475 ,
void * V_79 )
{
switch ( V_475 ) {
case V_476 :
F_216 ( V_79 ) ;
break;
case V_477 :
default:
break;
}
return 0 ;
}
static void F_221 ( struct V_1 * V_24 , unsigned int V_87 )
{
void * V_478 ;
struct V_479 V_480 ;
V_480 . V_96 = V_24 -> V_96 ;
V_480 . V_402 = V_24 -> V_402 ;
V_480 . V_430 = & V_24 -> V_430 ;
V_480 . V_481 = V_24 -> V_23 ;
V_480 . V_482 = & V_24 -> V_483 ;
V_480 . V_456 = V_24 -> V_7 . V_456 ;
if ( V_87 == V_484 ) {
V_480 . V_485 = V_24 -> V_66 . V_154 ;
V_480 . V_486 = V_24 -> V_66 . V_487 ;
} else if ( V_87 == V_488 ) {
V_480 . V_485 = V_24 -> V_66 . V_153 ;
V_480 . V_486 = V_24 -> V_66 . V_152 ;
}
V_480 . V_489 = V_24 -> V_66 . V_152 ;
V_480 . V_490 = V_24 -> V_7 . V_8 ;
V_480 . V_8 = V_24 -> V_7 . V_8 ;
V_480 . V_491 = V_24 -> V_7 . V_492 ;
V_480 . V_493 = V_24 -> V_7 . V_206 ;
V_480 . V_494 = F_222 ( F_41 ( V_24 , V_495 ) ) ;
V_480 . V_496 = 1 << F_223 (
F_41 ( V_24 , V_497 ) >>
( V_24 -> V_41 * 4 ) ) ;
V_480 . V_498 = 1 << F_223 (
F_41 ( V_24 , V_499 ) >>
( V_24 -> V_41 * 4 ) ) ;
V_480 . V_500 = V_24 -> V_211 + F_42 ( V_139 ) ;
V_480 . V_501 = V_24 -> V_211 + F_42 ( V_502 ) ;
V_480 . V_168 = V_24 -> V_7 . V_168 ;
V_478 = V_86 [ V_87 ] . F_224 ( & V_480 ) ;
if ( F_225 ( V_478 ) ) {
F_226 ( V_24 -> V_82 ,
L_35 ,
V_503 [ V_87 ] , F_227 ( V_478 ) ) ;
return;
}
V_24 -> V_88 [ V_87 ] = V_478 ;
if ( ! V_504 ) {
F_228 ( & V_505 ) ;
V_504 = true ;
}
if ( V_24 -> V_45 & V_302 )
V_86 [ V_87 ] . F_229 ( V_478 , V_506 ) ;
}
static void F_230 ( struct V_1 * V_24 )
{
unsigned int V_105 ;
F_231 ( & V_507 ) ;
F_232 ( & V_24 -> V_508 , & V_509 ) ;
for ( V_105 = 0 ; V_105 < V_510 ; V_105 ++ )
if ( V_86 [ V_105 ] . F_224 )
F_221 ( V_24 , V_105 ) ;
F_233 ( & V_507 ) ;
}
static void F_234 ( struct V_1 * V_24 )
{
unsigned int V_105 ;
F_231 ( & V_507 ) ;
F_235 ( & V_24 -> V_508 ) ;
for ( V_105 = 0 ; V_105 < V_510 ; V_105 ++ )
if ( V_24 -> V_88 [ V_105 ] ) {
V_86 [ V_105 ] . F_229 ( V_24 -> V_88 [ V_105 ] ,
V_511 ) ;
V_24 -> V_88 [ V_105 ] = NULL ;
}
if ( V_504 && F_236 ( & V_509 ) ) {
F_237 ( & V_505 ) ;
V_504 = false ;
}
F_233 ( & V_507 ) ;
}
static void F_238 ( struct V_1 * V_24 , enum V_512 V_513 )
{
unsigned int V_105 ;
F_231 ( & V_507 ) ;
for ( V_105 = 0 ; V_105 < V_510 ; V_105 ++ )
if ( V_24 -> V_88 [ V_105 ] )
V_86 [ V_105 ] . F_229 ( V_24 -> V_88 [ V_105 ] , V_513 ) ;
F_233 ( & V_507 ) ;
}
int F_239 ( enum V_514 type , const struct V_515 * V_15 )
{
int V_34 = 0 ;
struct V_1 * V_24 ;
if ( type >= V_510 )
return - V_166 ;
F_231 ( & V_507 ) ;
if ( V_86 [ type ] . F_224 ) {
V_34 = - V_303 ;
goto V_167;
}
V_86 [ type ] = * V_15 ;
F_240 (adap, &adapter_list, list_node)
F_221 ( V_24 , type ) ;
V_167: F_233 ( & V_507 ) ;
return V_34 ;
}
int F_241 ( enum V_514 type )
{
struct V_1 * V_24 ;
if ( type >= V_510 )
return - V_166 ;
F_231 ( & V_507 ) ;
F_240 (adap, &adapter_list, list_node)
V_24 -> V_88 [ type ] = NULL ;
V_86 [ type ] . F_224 = NULL ;
F_233 ( & V_507 ) ;
return 0 ;
}
static int F_242 ( struct V_1 * V_24 )
{
int V_114 ;
V_114 = F_68 ( V_24 ) ;
if ( V_114 )
goto V_167;
V_114 = F_58 ( V_24 ) ;
if ( V_114 )
goto V_516;
if ( V_24 -> V_45 & V_95 ) {
F_45 ( V_24 ) ;
V_114 = F_50 ( V_24 -> V_109 [ 0 ] . V_119 , F_40 , 0 ,
V_24 -> V_109 [ 0 ] . V_110 , V_24 ) ;
if ( V_114 )
goto V_517;
V_114 = F_49 ( V_24 ) ;
if ( V_114 ) {
F_52 ( V_24 -> V_109 [ 0 ] . V_119 , V_24 ) ;
goto V_517;
}
} else {
V_114 = F_50 ( V_24 -> V_96 -> V_98 , F_243 ( V_24 ) ,
( V_24 -> V_45 & V_97 ) ? 0 : V_518 ,
V_24 -> V_23 [ 0 ] -> V_111 , V_24 ) ;
if ( V_114 )
goto V_517;
}
F_64 ( V_24 ) ;
F_244 ( V_24 ) ;
F_245 ( V_24 ) ;
V_24 -> V_45 |= V_302 ;
F_238 ( V_24 , V_506 ) ;
V_167:
return V_114 ;
V_517:
F_34 ( V_24 -> V_82 , L_36 , V_114 ) ;
V_516:
F_71 ( V_24 ) ;
goto V_167;
}
static void F_246 ( struct V_1 * V_1 )
{
F_247 ( V_1 ) ;
F_248 ( & V_1 -> V_434 ) ;
V_1 -> V_433 = false ;
V_1 -> V_432 = NULL ;
if ( V_1 -> V_45 & V_95 ) {
F_53 ( V_1 ) ;
F_52 ( V_1 -> V_109 [ 0 ] . V_119 , V_1 ) ;
} else
F_52 ( V_1 -> V_96 -> V_98 , V_1 ) ;
F_62 ( V_1 ) ;
F_249 ( V_1 ) ;
F_71 ( V_1 ) ;
V_1 -> V_45 &= ~ V_302 ;
}
static int F_250 ( struct V_10 * V_11 )
{
int V_114 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_9 ( V_11 ) ;
if ( ! ( V_1 -> V_45 & V_302 ) ) {
V_114 = F_242 ( V_1 ) ;
if ( V_114 < 0 )
return V_114 ;
}
V_114 = F_21 ( V_11 ) ;
if ( ! V_114 )
F_251 ( V_11 ) ;
return V_114 ;
}
static int F_252 ( struct V_10 * V_11 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_253 ( V_11 ) ;
F_9 ( V_11 ) ;
return F_24 ( V_1 , V_1 -> V_41 , V_26 -> V_42 , false , false ) ;
}
static struct V_519 * F_254 ( struct V_10 * V_11 ,
struct V_519 * V_520 )
{
struct V_204 V_89 ;
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_15 -> V_1 ;
F_208 ( & V_1 -> V_462 ) ;
F_106 ( V_1 , V_15 -> V_52 , & V_89 ) ;
F_210 ( & V_1 -> V_462 ) ;
V_520 -> V_521 = V_89 . V_522 ;
V_520 -> V_523 = V_89 . V_524 ;
V_520 -> V_525 = V_89 . V_526 ;
V_520 -> V_527 = V_89 . V_528 ;
V_520 -> V_529 = V_89 . V_530 ;
V_520 -> V_531 = V_89 . V_532 + V_89 . V_533 +
V_89 . V_534 ;
V_520 -> V_535 = 0 ;
V_520 -> V_536 = V_89 . V_537 ;
V_520 -> V_538 = V_89 . V_539 ;
V_520 -> V_540 = V_89 . V_541 + V_89 . V_542 +
V_89 . V_543 + V_89 . V_544 +
V_89 . V_545 + V_89 . V_546 +
V_89 . V_547 + V_89 . V_548 ;
V_520 -> V_549 = 0 ;
V_520 -> V_550 = 0 ;
V_520 -> V_551 = 0 ;
V_520 -> V_552 = 0 ;
V_520 -> V_553 = 0 ;
V_520 -> V_554 = 0 ;
V_520 -> V_555 = V_89 . V_556 ;
V_520 -> V_557 = V_89 . V_539 + V_89 . V_537 +
V_520 -> V_531 + V_89 . V_558 + V_520 -> V_540 ;
return V_520 ;
}
static int F_255 ( struct V_10 * V_11 , struct V_559 * V_426 , int V_251 )
{
unsigned int V_560 ;
int V_34 = 0 , V_561 , V_562 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_563 * V_79 = (struct V_563 * ) & V_426 -> V_564 ;
switch ( V_251 ) {
case V_565 :
if ( V_26 -> V_259 < 0 )
return - V_176 ;
V_79 -> V_566 = V_26 -> V_259 ;
break;
case V_567 :
case V_568 :
if ( F_256 ( V_79 -> V_566 ) ) {
V_561 = F_257 ( V_79 -> V_566 ) ;
V_562 = F_258 ( V_79 -> V_566 ) ;
} else if ( V_79 -> V_566 < 32 ) {
V_561 = V_79 -> V_566 ;
V_562 = 0 ;
V_79 -> V_569 &= 0x1f ;
} else
return - V_166 ;
V_560 = V_26 -> V_1 -> V_41 ;
if ( V_251 == V_567 )
V_34 = F_259 ( V_26 -> V_1 , V_560 , V_561 , V_562 ,
V_79 -> V_569 , & V_79 -> V_570 ) ;
else
V_34 = F_260 ( V_26 -> V_1 , V_560 , V_561 , V_562 ,
V_79 -> V_569 , V_79 -> V_571 ) ;
break;
default:
return - V_176 ;
}
return V_34 ;
}
static void F_261 ( struct V_10 * V_11 )
{
F_19 ( V_11 , - 1 , false ) ;
}
static int F_262 ( struct V_10 * V_11 , int V_572 )
{
int V_34 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_572 < 81 || V_572 > V_573 )
return - V_166 ;
V_34 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , V_572 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_34 )
V_11 -> V_43 = V_572 ;
return V_34 ;
}
static int F_263 ( struct V_10 * V_11 , void * V_15 )
{
int V_34 ;
struct V_574 * V_33 = V_15 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( ! F_264 ( V_33 -> V_575 ) )
return - V_166 ;
V_34 = F_22 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 ,
V_26 -> V_50 , V_33 -> V_575 , true , true ) ;
if ( V_34 < 0 )
return V_34 ;
memcpy ( V_11 -> V_51 , V_33 -> V_575 , V_11 -> V_576 ) ;
V_26 -> V_50 = V_34 ;
return 0 ;
}
static void F_265 ( struct V_10 * V_11 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_24 = V_26 -> V_1 ;
if ( V_24 -> V_45 & V_95 ) {
int V_105 ;
struct V_128 * V_191 = & V_24 -> V_66 . V_122 [ V_26 -> V_129 ] ;
for ( V_105 = V_26 -> V_113 ; V_105 ; V_105 -- , V_191 ++ )
V_120 ( 0 , & V_191 -> V_85 ) ;
} else
F_243 ( V_24 ) ( 0 , V_24 ) ;
}
void F_266 ( struct V_1 * V_24 )
{
F_267 ( V_24 , V_577 , V_578 , 0 ) ;
F_247 ( V_24 ) ;
F_268 ( V_24 -> V_82 , L_37 ) ;
}
static void F_269 ( struct V_1 * V_24 )
{
T_6 V_579 ;
V_579 = F_270 ( V_24 -> V_96 , 0 ) ;
F_43 ( V_24 , F_271 ( V_580 , 0 ) ,
( V_579 + V_581 ) | F_272 ( 0 ) |
F_273 ( F_274 ( V_582 ) - 10 ) ) ;
F_43 ( V_24 , F_271 ( V_580 , 1 ) ,
( V_579 + V_583 ) | F_272 ( 0 ) |
F_273 ( F_274 ( V_584 ) - 10 ) ) ;
F_43 ( V_24 , F_271 ( V_580 , 2 ) ,
( V_579 + V_585 ) | F_272 ( 0 ) |
F_273 ( F_274 ( V_586 ) - 10 ) ) ;
if ( V_24 -> V_483 . V_587 . V_169 ) {
unsigned int V_208 , V_588 ;
V_208 = F_270 ( V_24 -> V_96 , 2 ) +
F_275 ( V_24 -> V_96 , & V_24 -> V_483 ) ;
V_588 = F_276 ( V_24 -> V_483 . V_587 . V_169 ) >> 10 ;
F_43 ( V_24 ,
F_271 ( V_580 , 3 ) ,
V_208 | F_272 ( 1 ) | F_273 ( F_274 ( V_588 ) ) ) ;
F_43 ( V_24 ,
F_271 ( V_589 , 3 ) ,
V_24 -> V_483 . V_587 . V_208 ) ;
F_41 ( V_24 ,
F_271 ( V_589 , 3 ) ) ;
}
}
static int F_277 ( struct V_1 * V_24 , struct V_590 * V_320 )
{
T_6 V_100 ;
int V_34 ;
memset ( V_320 , 0 , sizeof( * V_320 ) ) ;
V_320 -> V_591 = F_182 ( F_278 ( V_592 ) |
V_593 | V_594 ) ;
V_320 -> V_595 = F_182 ( F_279 ( * V_320 ) ) ;
V_34 = F_280 ( V_24 , V_24 -> V_41 , V_320 , sizeof( * V_320 ) , V_320 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_320 -> V_596 & F_197 ( V_597 ) ) {
if ( ! V_598 )
V_320 -> V_596 ^= F_197 ( V_597 ) ;
else
V_320 -> V_596 = F_197 ( V_597 ) ;
} else if ( V_598 ) {
F_34 ( V_24 -> V_82 , L_38 ) ;
return V_34 ;
}
V_320 -> V_591 = F_182 ( F_278 ( V_592 ) |
V_593 | V_599 ) ;
V_34 = F_280 ( V_24 , V_24 -> V_41 , V_320 , sizeof( * V_320 ) , NULL ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_281 ( V_24 , V_24 -> V_41 ,
V_600 ,
V_601 |
V_602 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_282 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , V_143 , 64 , V_603 ,
0 , 0 , 4 , 0xf , 0xf , 16 , V_604 , V_604 ) ;
if ( V_34 < 0 )
return V_34 ;
F_283 ( V_24 ) ;
F_43 ( V_24 , V_605 , 0x64f8849 ) ;
F_43 ( V_24 , V_606 , F_212 ( V_607 - 12 ) ) ;
F_43 ( V_24 , V_608 , V_609 ) ;
V_100 = F_41 ( V_24 , V_610 ) ;
F_43 ( V_24 , V_610 , V_100 & ~ V_611 ) ;
return F_284 ( V_24 , V_24 -> V_41 ) ;
}
static int F_285 ( struct V_1 * V_24 )
{
int V_34 ;
T_6 V_100 , V_612 ;
enum V_613 V_217 ;
T_6 V_7 [ 7 ] , V_172 [ 7 ] ;
struct V_590 V_320 ;
V_34 = F_286 ( V_24 ) ;
if ( V_34 == - V_166 || V_34 > 0 ) {
if ( F_78 ( V_24 ) >= 0 )
V_34 = F_286 ( V_24 ) ;
}
if ( V_34 < 0 )
return V_34 ;
V_34 = F_287 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , V_614 , & V_217 ) ;
if ( V_34 < 0 ) {
F_34 ( V_24 -> V_82 , L_39 ,
V_34 ) ;
return V_34 ;
}
V_34 = F_288 ( V_24 , V_24 -> V_41 , V_615 | V_616 ) ;
if ( V_34 < 0 )
goto V_617;
for ( V_100 = 0 ; V_100 < V_311 - 1 ; V_100 ++ )
V_24 -> V_66 . V_308 [ V_100 ] = F_159 ( V_618 [ V_100 ] , V_619 ) ;
V_24 -> V_66 . V_308 [ V_311 - 1 ] = V_619 ;
V_24 -> V_66 . V_310 [ 0 ] = 1 ;
for ( V_100 = 1 ; V_100 < V_620 ; V_100 ++ )
V_24 -> V_66 . V_310 [ V_100 ] = F_159 ( V_621 [ V_100 - 1 ] ,
V_622 ) ;
#define F_289 ( T_15 ) \
(FW_PARAMS_MNEM(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X(FW_PARAMS_PARAM_DEV_##param))
V_7 [ 0 ] = F_289 ( V_623 ) ;
V_34 = F_290 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 1 , V_7 , V_172 ) ;
if ( V_34 < 0 )
goto V_617;
V_24 -> V_7 . V_624 . V_625 = V_172 [ 0 ] ;
V_34 = F_277 ( V_24 , & V_320 ) ;
if ( V_34 < 0 )
goto V_617;
#define F_291 ( T_15 ) \
(FW_PARAMS_MNEM(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X(FW_PARAMS_PARAM_PFVF_##param) | \
FW_PARAMS_PARAM_Y(adap->fn))
V_7 [ 0 ] = F_289 ( V_626 ) ;
V_7 [ 1 ] = F_291 ( V_627 ) ;
V_7 [ 2 ] = F_291 ( V_628 ) ;
V_7 [ 3 ] = F_291 ( V_629 ) ;
V_7 [ 4 ] = F_291 ( V_630 ) ;
V_7 [ 5 ] = F_291 ( V_631 ) ;
V_7 [ 6 ] = F_291 ( V_632 ) ;
V_34 = F_290 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 7 , V_7 , V_172 ) ;
if ( V_34 < 0 )
goto V_617;
V_612 = V_172 [ 0 ] ;
V_24 -> V_430 . V_633 = V_172 [ 3 ] ;
V_24 -> V_430 . V_634 = V_172 [ 4 ] - V_172 [ 3 ] + 1 ;
V_24 -> V_66 . V_134 = V_172 [ 5 ] ;
V_24 -> V_66 . V_68 = V_172 [ 6 ] ;
if ( V_320 . V_635 ) {
V_7 [ 0 ] = F_289 ( V_636 ) ;
V_7 [ 1 ] = F_291 ( V_637 ) ;
V_7 [ 2 ] = F_291 ( V_638 ) ;
V_7 [ 3 ] = F_291 ( V_639 ) ;
V_7 [ 4 ] = F_291 ( V_640 ) ;
V_7 [ 5 ] = F_289 ( V_641 ) ;
V_34 = F_290 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 6 , V_7 ,
V_172 ) ;
if ( V_34 < 0 )
goto V_617;
V_24 -> V_430 . V_441 = V_172 [ 0 ] ;
V_24 -> V_430 . V_440 = F_159 ( V_24 -> V_430 . V_441 / 2 , V_642 ) ;
V_24 -> V_430 . V_419 = V_172 [ 1 ] ;
V_24 -> V_430 . V_417 = V_172 [ 2 ] - V_172 [ 1 ] + 1 ;
V_24 -> V_483 . V_643 . V_208 = V_172 [ 3 ] ;
V_24 -> V_483 . V_643 . V_169 = V_172 [ 4 ] - V_172 [ 3 ] + 1 ;
V_24 -> V_7 . V_492 = V_172 [ 5 ] ;
V_24 -> V_7 . V_170 = 1 ;
}
if ( V_320 . V_644 ) {
V_7 [ 0 ] = F_291 ( V_645 ) ;
V_7 [ 1 ] = F_291 ( V_646 ) ;
V_7 [ 2 ] = F_291 ( V_647 ) ;
V_7 [ 3 ] = F_291 ( V_648 ) ;
V_7 [ 4 ] = F_291 ( V_649 ) ;
V_7 [ 5 ] = F_291 ( V_650 ) ;
V_34 = F_290 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 6 , V_7 ,
V_172 ) ;
if ( V_34 < 0 )
goto V_617;
V_24 -> V_483 . V_651 . V_208 = V_172 [ 0 ] ;
V_24 -> V_483 . V_651 . V_169 = V_172 [ 1 ] - V_172 [ 0 ] + 1 ;
V_24 -> V_483 . V_323 . V_208 = V_172 [ 2 ] ;
V_24 -> V_483 . V_323 . V_169 = V_172 [ 3 ] - V_172 [ 2 ] + 1 ;
V_24 -> V_483 . V_652 . V_208 = V_172 [ 4 ] ;
V_24 -> V_483 . V_652 . V_169 = V_172 [ 5 ] - V_172 [ 4 ] + 1 ;
V_7 [ 0 ] = F_291 ( V_653 ) ;
V_7 [ 1 ] = F_291 ( V_654 ) ;
V_7 [ 2 ] = F_291 ( V_655 ) ;
V_7 [ 3 ] = F_291 ( V_656 ) ;
V_7 [ 4 ] = F_291 ( V_657 ) ;
V_7 [ 5 ] = F_291 ( V_658 ) ;
V_34 = F_290 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 6 , V_7 ,
V_172 ) ;
if ( V_34 < 0 )
goto V_617;
V_24 -> V_483 . V_659 . V_208 = V_172 [ 0 ] ;
V_24 -> V_483 . V_659 . V_169 = V_172 [ 1 ] - V_172 [ 0 ] + 1 ;
V_24 -> V_483 . V_660 . V_208 = V_172 [ 2 ] ;
V_24 -> V_483 . V_660 . V_169 = V_172 [ 3 ] - V_172 [ 2 ] + 1 ;
V_24 -> V_483 . V_587 . V_208 = V_172 [ 4 ] ;
V_24 -> V_483 . V_587 . V_169 = V_172 [ 5 ] - V_172 [ 4 ] + 1 ;
}
if ( V_320 . V_661 ) {
V_7 [ 0 ] = F_291 ( V_662 ) ;
V_7 [ 1 ] = F_291 ( V_663 ) ;
V_34 = F_290 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 2 , V_7 ,
V_172 ) ;
if ( V_34 < 0 )
goto V_617;
V_24 -> V_483 . V_664 . V_208 = V_172 [ 0 ] ;
V_24 -> V_483 . V_664 . V_169 = V_172 [ 1 ] - V_172 [ 0 ] + 1 ;
}
#undef F_291
#undef F_289
V_24 -> V_7 . V_8 = F_292 ( V_612 ) ;
V_24 -> V_7 . V_5 = V_612 ;
V_24 -> V_45 |= V_665 ;
V_100 = F_41 ( V_24 , V_666 ) ;
V_24 -> V_7 . V_667 . V_668 = F_293 ( V_100 ) ;
F_294 ( V_24 , V_24 -> V_7 . V_456 , NULL ) ;
F_295 ( V_24 , V_24 -> V_7 . V_456 , V_24 -> V_7 . V_669 ,
V_24 -> V_7 . V_670 ) ;
#ifdef F_296
{
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < F_11 ( V_671 ) ; V_2 ++ ) {
if ( V_671 [ V_2 ] <= 0 )
continue;
for ( V_3 = 1 ; V_3 <= V_671 [ V_2 ] ; V_3 ++ ) {
V_34 = F_282 ( V_24 , V_24 -> V_41 , V_2 , V_3 ,
V_672 , V_673 ,
V_674 , V_675 ,
V_676 , V_677 ,
V_678 ,
F_1 ( V_24 , V_2 , V_3 ) ,
V_679 ,
V_680 , V_681 ) ;
if ( V_34 < 0 )
F_226 ( V_24 -> V_82 , L_40
L_41
L_42 , V_2 , V_3 , V_34 ) ;
}
}
}
#endif
F_269 ( V_24 ) ;
return 0 ;
V_617: if ( V_34 != - V_682 && V_34 != - V_683 )
F_297 ( V_24 , V_24 -> V_41 ) ;
return V_34 ;
}
static T_16 F_298 ( struct V_458 * V_96 ,
T_17 V_217 )
{
int V_105 ;
struct V_1 * V_24 = F_207 ( V_96 ) ;
if ( ! V_24 )
goto V_167;
F_299 () ;
V_24 -> V_45 &= ~ V_665 ;
F_238 ( V_24 , V_684 ) ;
F_46 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_105 ] ;
F_300 ( V_11 ) ;
F_9 ( V_11 ) ;
}
if ( V_24 -> V_45 & V_302 )
F_246 ( V_24 ) ;
F_301 () ;
F_302 ( V_96 ) ;
V_167: return V_217 == V_685 ?
V_686 : V_687 ;
}
static T_16 F_303 ( struct V_458 * V_96 )
{
int V_105 , V_34 ;
struct V_590 V_320 ;
struct V_1 * V_24 = F_207 ( V_96 ) ;
if ( ! V_24 ) {
F_304 ( V_96 ) ;
F_305 ( V_96 ) ;
return V_688 ;
}
if ( F_306 ( V_96 ) ) {
F_34 ( & V_96 -> V_11 , L_43 ) ;
return V_686 ;
}
F_307 ( V_96 ) ;
F_304 ( V_96 ) ;
F_305 ( V_96 ) ;
F_308 ( V_96 ) ;
if ( F_309 ( V_24 ) < 0 )
return V_686 ;
if ( F_287 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , V_614 , NULL ) )
return V_686 ;
V_24 -> V_45 |= V_665 ;
if ( F_277 ( V_24 , & V_320 ) )
return V_686 ;
F_46 (adap, i) {
struct V_14 * V_15 = F_59 ( V_24 , V_105 ) ;
V_34 = F_310 ( V_24 , V_24 -> V_41 , V_15 -> V_52 , V_24 -> V_41 , 0 , 1 ,
NULL , NULL ) ;
if ( V_34 < 0 )
return V_686 ;
V_15 -> V_42 = V_34 ;
V_15 -> V_50 = - 1 ;
}
F_295 ( V_24 , V_24 -> V_7 . V_456 , V_24 -> V_7 . V_669 ,
V_24 -> V_7 . V_670 ) ;
F_269 ( V_24 ) ;
if ( F_242 ( V_24 ) )
return V_686 ;
return V_688 ;
}
static void F_311 ( struct V_458 * V_96 )
{
int V_105 ;
struct V_1 * V_24 = F_207 ( V_96 ) ;
if ( ! V_24 )
return;
F_299 () ;
F_46 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_105 ] ;
if ( F_7 ( V_11 ) ) {
F_21 ( V_11 ) ;
F_261 ( V_11 ) ;
}
F_312 ( V_11 ) ;
}
F_301 () ;
}
static inline bool F_313 ( const struct V_274 * V_275 )
{
return ( V_275 -> V_267 & V_229 ) != 0 ;
}
static inline void F_314 ( struct V_53 * V_54 , T_3 V_689 , T_3 V_690 ,
unsigned int V_169 , unsigned int V_691 )
{
V_54 -> V_140 = F_133 ( V_689 ) |
( V_690 < V_620 ? V_318 : 0 ) ;
V_54 -> V_315 = V_690 < V_620 ? V_690 : 0 ;
V_54 -> V_692 = V_691 ;
V_54 -> V_169 = V_169 ;
}
static void T_13 F_315 ( struct V_1 * V_24 )
{
struct V_66 * V_13 = & V_24 -> V_66 ;
int V_105 , V_693 = 0 , V_694 = 0 , V_695 = 0 ;
F_46 (adap, i)
V_694 += F_313 ( & F_59 ( V_24 , V_105 ) -> V_16 ) ;
if ( V_694 )
V_693 = ( V_696 - ( V_24 -> V_7 . V_8 - V_694 ) ) / V_694 ;
if ( V_693 > F_316 () )
V_693 = F_316 () ;
F_46 (adap, i) {
struct V_14 * V_26 = F_59 ( V_24 , V_105 ) ;
V_26 -> V_129 = V_695 ;
V_26 -> V_113 = F_313 ( & V_26 -> V_16 ) ? V_693 : 1 ;
V_695 += V_26 -> V_113 ;
}
V_13 -> V_697 = V_695 ;
V_13 -> V_698 = V_695 ;
if ( F_90 ( V_24 ) ) {
if ( V_694 ) {
V_105 = F_317 ( int , F_11 ( V_13 -> V_124 ) ,
F_316 () ) ;
V_13 -> V_152 = F_318 ( V_105 , V_24 -> V_7 . V_8 ) ;
} else
V_13 -> V_152 = V_24 -> V_7 . V_8 ;
V_13 -> V_487 = V_24 -> V_7 . V_8 ;
}
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_122 ) ; V_105 ++ ) {
struct V_128 * V_699 = & V_13 -> V_122 [ V_105 ] ;
F_314 ( & V_699 -> V_85 , 0 , 0 , 1024 , 64 ) ;
V_699 -> V_149 . V_169 = 72 ;
}
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_148 ) ; V_105 ++ )
V_13 -> V_148 [ V_105 ] . V_54 . V_169 = 1024 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_155 ) ; V_105 ++ )
V_13 -> V_155 [ V_105 ] . V_54 . V_169 = 512 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_70 ) ; V_105 ++ )
V_13 -> V_70 [ V_105 ] . V_54 . V_169 = 1024 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_124 ) ; V_105 ++ ) {
struct V_83 * V_699 = & V_13 -> V_124 [ V_105 ] ;
F_314 ( & V_699 -> V_85 , 0 , 0 , 1024 , 64 ) ;
V_699 -> V_85 . V_87 = V_488 ;
V_699 -> V_149 . V_169 = 72 ;
}
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_125 ) ; V_105 ++ ) {
struct V_83 * V_699 = & V_13 -> V_125 [ V_105 ] ;
F_314 ( & V_699 -> V_85 , 0 , 0 , 511 , 64 ) ;
V_699 -> V_85 . V_87 = V_484 ;
V_699 -> V_149 . V_169 = 72 ;
}
F_314 ( & V_13 -> V_121 , 6 , 0 , 512 , 64 ) ;
F_314 ( & V_13 -> V_145 , 6 , 0 , 2 * V_603 , 64 ) ;
}
static void T_13 F_319 ( struct V_1 * V_24 , int V_108 )
{
int V_105 ;
struct V_14 * V_26 ;
while ( V_108 < V_24 -> V_66 . V_697 )
F_46 (adap, i) {
V_26 = F_59 ( V_24 , V_105 ) ;
if ( V_26 -> V_113 > 1 ) {
V_26 -> V_113 -- ;
V_24 -> V_66 . V_697 -- ;
if ( V_24 -> V_66 . V_697 <= V_108 )
break;
}
}
V_108 = 0 ;
F_46 (adap, i) {
V_26 = F_59 ( V_24 , V_105 ) ;
V_26 -> V_129 = V_108 ;
V_108 += V_26 -> V_113 ;
}
}
static int T_13 F_320 ( struct V_1 * V_24 )
{
int V_700 = 0 ;
int V_105 , V_114 , V_701 , V_702 ;
struct V_66 * V_13 = & V_24 -> V_66 ;
unsigned int V_490 = V_24 -> V_7 . V_8 ;
struct V_703 V_704 [ V_603 + 1 ] ;
for ( V_105 = 0 ; V_105 < F_11 ( V_704 ) ; ++ V_105 )
V_704 [ V_105 ] . V_705 = V_105 ;
V_701 = V_13 -> V_698 + V_706 ;
if ( F_90 ( V_24 ) ) {
V_701 += V_13 -> V_487 + V_13 -> V_152 ;
V_700 = 2 * V_490 ;
}
V_702 = V_24 -> V_7 . V_8 + V_706 + V_700 ;
while ( ( V_114 = F_321 ( V_24 -> V_96 , V_704 , V_701 ) ) >= V_702 )
V_701 = V_114 ;
if ( ! V_114 ) {
V_105 = V_701 - V_706 - V_700 ;
if ( V_105 < V_13 -> V_698 ) {
V_13 -> V_698 = V_105 ;
if ( V_105 < V_13 -> V_697 )
F_319 ( V_24 , V_105 ) ;
}
if ( F_90 ( V_24 ) ) {
V_105 = V_701 - V_706 - V_13 -> V_698 ;
V_105 -= V_700 - V_490 ;
V_13 -> V_152 = ( V_105 / V_490 ) * V_490 ;
}
for ( V_105 = 0 ; V_105 < V_701 ; ++ V_105 )
V_24 -> V_109 [ V_105 ] . V_119 = V_704 [ V_105 ] . V_707 ;
} else if ( V_114 > 0 )
F_82 ( V_24 -> V_82 ,
L_44 , V_114 ) ;
return V_114 ;
}
static int T_13 F_322 ( struct V_1 * V_24 )
{
unsigned int V_105 , V_106 ;
F_46 (adap, i) {
struct V_14 * V_26 = F_59 ( V_24 , V_105 ) ;
V_26 -> V_127 = F_323 ( V_26 -> V_130 , sizeof( T_2 ) , V_131 ) ;
if ( ! V_26 -> V_127 )
return - V_132 ;
for ( V_106 = 0 ; V_106 < V_26 -> V_130 ; V_106 ++ )
V_26 -> V_127 [ V_106 ] = F_324 ( V_106 , V_26 -> V_113 ) ;
}
return 0 ;
}
static void T_13 F_325 ( const struct V_10 * V_11 )
{
static const char * V_708 [] = {
L_45 , L_46 , L_47 , L_48 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 , L_55 , L_56
} ;
char V_207 [ 80 ] ;
char * V_709 = V_207 ;
const char * V_710 = L_57 ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_1 * V_24 = V_26 -> V_1 ;
if ( V_24 -> V_7 . V_711 . V_17 == V_712 )
V_710 = L_58 ;
else if ( V_24 -> V_7 . V_711 . V_17 == V_713 )
V_710 = L_59 ;
if ( V_26 -> V_16 . V_267 & V_225 )
V_709 += sprintf ( V_709 , L_60 ) ;
if ( V_26 -> V_16 . V_267 & V_227 )
V_709 += sprintf ( V_709 , L_61 ) ;
if ( V_26 -> V_16 . V_267 & V_229 )
V_709 += sprintf ( V_709 , L_62 ) ;
if ( V_709 != V_207 )
-- V_709 ;
sprintf ( V_709 , L_63 , V_708 [ V_26 -> V_252 ] ) ;
F_4 ( V_11 , L_64 ,
V_24 -> V_7 . V_624 . V_714 , V_24 -> V_7 . V_206 , V_207 ,
F_90 ( V_24 ) ? L_65 : L_57 , V_24 -> V_7 . V_711 . V_715 , V_710 ,
( V_24 -> V_45 & V_95 ) ? L_66 :
( V_24 -> V_45 & V_97 ) ? L_67 : L_57 ) ;
F_4 ( V_11 , L_68 ,
V_24 -> V_7 . V_624 . V_716 , V_24 -> V_7 . V_624 . V_717 ) ;
}
static void T_13 F_326 ( struct V_458 * V_11 )
{
T_2 V_100 ;
int V_379 ;
V_379 = F_327 ( V_11 ) ;
if ( V_379 > 0 ) {
F_328 ( V_11 , V_379 + V_718 , & V_100 ) ;
V_100 |= V_719 ;
F_329 ( V_11 , V_379 + V_718 , V_100 ) ;
}
}
static void F_330 ( struct V_1 * V_1 )
{
unsigned int V_105 ;
F_87 ( V_1 -> V_402 ) ;
F_87 ( V_1 -> V_430 . V_429 ) ;
F_37 ( V_1 ) ;
F_46 (adapter, i)
if ( V_1 -> V_23 [ V_105 ] ) {
F_57 ( F_59 ( V_1 , V_105 ) -> V_127 ) ;
F_331 ( V_1 -> V_23 [ V_105 ] ) ;
}
if ( V_1 -> V_45 & V_665 )
F_297 ( V_1 , V_1 -> V_41 ) ;
}
static int T_13 F_332 ( struct V_458 * V_96 ,
const struct V_720 * V_721 )
{
int V_722 , V_105 , V_114 ;
struct V_14 * V_26 ;
bool V_723 = false ;
struct V_1 * V_1 = NULL ;
F_333 ( V_724 L_69 , V_725 , V_184 ) ;
V_114 = F_334 ( V_96 , V_182 ) ;
if ( V_114 ) {
F_82 ( & V_96 -> V_11 , L_70 ) ;
return V_114 ;
}
V_722 = F_335 ( V_96 -> V_726 ) ;
if ( V_722 != V_721 -> V_727 ) {
F_305 ( V_96 ) ;
goto V_728;
}
V_114 = F_306 ( V_96 ) ;
if ( V_114 ) {
F_34 ( & V_96 -> V_11 , L_71 ) ;
goto V_729;
}
if ( ! F_336 ( V_96 , F_337 ( 64 ) ) ) {
V_723 = true ;
V_114 = F_338 ( V_96 , F_337 ( 64 ) ) ;
if ( V_114 ) {
F_34 ( & V_96 -> V_11 , L_72
L_73 ) ;
goto V_730;
}
} else {
V_114 = F_336 ( V_96 , F_337 ( 32 ) ) ;
if ( V_114 ) {
F_34 ( & V_96 -> V_11 , L_74 ) ;
goto V_730;
}
}
F_339 ( V_96 ) ;
F_326 ( V_96 ) ;
F_307 ( V_96 ) ;
F_305 ( V_96 ) ;
V_1 = F_85 ( sizeof( * V_1 ) , V_131 ) ;
if ( ! V_1 ) {
V_114 = - V_132 ;
goto V_730;
}
V_1 -> V_211 = F_340 ( V_96 , 0 ) ;
if ( ! V_1 -> V_211 ) {
F_34 ( & V_96 -> V_11 , L_75 ) ;
V_114 = - V_132 ;
goto V_731;
}
V_1 -> V_96 = V_96 ;
V_1 -> V_82 = & V_96 -> V_11 ;
V_1 -> V_41 = V_722 ;
V_1 -> V_171 = V_732 ;
memset ( V_1 -> V_733 , 0xff , sizeof( V_1 -> V_733 ) ) ;
F_194 ( & V_1 -> V_462 ) ;
F_194 ( & V_1 -> V_431 ) ;
F_341 ( & V_1 -> V_434 , F_186 ) ;
V_114 = F_342 ( V_1 ) ;
if ( V_114 )
goto V_734;
V_114 = F_285 ( V_1 ) ;
if ( V_114 )
goto V_734;
F_46 (adapter, i) {
struct V_10 * V_136 ;
V_136 = F_343 ( sizeof( struct V_14 ) ,
V_696 ) ;
if ( ! V_136 ) {
V_114 = - V_132 ;
goto V_735;
}
F_344 ( V_136 , & V_96 -> V_11 ) ;
V_1 -> V_23 [ V_105 ] = V_136 ;
V_26 = F_5 ( V_136 ) ;
V_26 -> V_1 = V_1 ;
V_26 -> V_50 = - 1 ;
V_26 -> V_21 = V_105 ;
V_136 -> V_98 = V_96 -> V_98 ;
V_136 -> V_736 = V_737 | V_738 |
V_739 | V_740 |
V_741 | V_742 |
V_743 | V_49 ;
if ( V_723 )
V_136 -> V_736 |= V_744 ;
V_136 -> V_48 |= V_136 -> V_736 ;
V_136 -> V_745 = V_136 -> V_48 & V_746 ;
V_136 -> V_470 |= V_747 ;
V_136 -> V_748 = & V_749 ;
F_345 ( V_136 , & V_750 ) ;
}
F_346 ( V_96 , V_1 ) ;
if ( V_1 -> V_45 & V_665 ) {
V_114 = F_347 ( V_1 , V_722 , V_722 , 0 ) ;
if ( V_114 )
goto V_735;
}
F_315 ( V_1 ) ;
V_1 -> V_402 = F_348 () ;
if ( ! V_1 -> V_402 ) {
F_226 ( & V_96 -> V_11 , L_76 ) ;
V_1 -> V_7 . V_170 = 0 ;
}
if ( F_90 ( V_1 ) && F_192 ( & V_1 -> V_430 ) < 0 ) {
F_226 ( & V_96 -> V_11 , L_77
L_78 ) ;
V_1 -> V_7 . V_170 = 0 ;
}
if ( V_118 > 1 && F_320 ( V_1 ) == 0 )
V_1 -> V_45 |= V_95 ;
else if ( V_118 > 0 && F_349 ( V_96 ) == 0 )
V_1 -> V_45 |= V_97 ;
V_114 = F_322 ( V_1 ) ;
if ( V_114 )
goto V_735;
F_46 (adapter, i) {
V_26 = F_59 ( V_1 , V_105 ) ;
F_350 ( V_1 -> V_23 [ V_105 ] , V_26 -> V_113 ) ;
F_351 ( V_1 -> V_23 [ V_105 ] , V_26 -> V_113 ) ;
V_114 = F_352 ( V_1 -> V_23 [ V_105 ] ) ;
if ( V_114 )
break;
V_1 -> V_733 [ V_26 -> V_52 ] = V_105 ;
F_325 ( V_1 -> V_23 [ V_105 ] ) ;
}
if ( V_105 == 0 ) {
F_34 ( & V_96 -> V_11 , L_79 ) ;
goto V_735;
}
if ( V_114 ) {
F_226 ( & V_96 -> V_11 , L_80 , V_105 ) ;
V_114 = 0 ;
}
if ( V_751 ) {
V_1 -> V_393 = F_353 ( F_99 ( V_96 ) ,
V_751 ) ;
F_163 ( V_1 ) ;
}
V_96 -> V_752 = 1 ;
if ( F_90 ( V_1 ) )
F_230 ( V_1 ) ;
V_728:
#ifdef F_296
if ( V_722 < F_11 ( V_671 ) && V_671 [ V_722 ] > 0 )
if ( F_354 ( V_96 , V_671 [ V_722 ] ) == 0 )
F_82 ( & V_96 -> V_11 ,
L_81 ,
V_671 [ V_722 ] ) ;
#endif
return 0 ;
V_735:
F_330 ( V_1 ) ;
V_734:
F_355 ( V_1 -> V_211 ) ;
V_731:
F_57 ( V_1 ) ;
V_730:
F_356 ( V_96 ) ;
F_302 ( V_96 ) ;
V_729:
F_357 ( V_96 ) ;
F_346 ( V_96 , NULL ) ;
return V_114 ;
}
static void T_18 F_358 ( struct V_458 * V_96 )
{
struct V_1 * V_1 = F_207 ( V_96 ) ;
F_359 ( V_96 ) ;
if ( V_1 ) {
int V_105 ;
if ( F_90 ( V_1 ) )
F_234 ( V_1 ) ;
F_46 (adapter, i)
if ( V_1 -> V_23 [ V_105 ] -> V_753 == V_754 )
F_360 ( V_1 -> V_23 [ V_105 ] ) ;
if ( V_1 -> V_393 )
F_361 ( V_1 -> V_393 ) ;
if ( V_1 -> V_45 & V_302 )
F_246 ( V_1 ) ;
F_330 ( V_1 ) ;
F_355 ( V_1 -> V_211 ) ;
F_57 ( V_1 ) ;
F_356 ( V_96 ) ;
F_302 ( V_96 ) ;
F_357 ( V_96 ) ;
F_346 ( V_96 , NULL ) ;
} else
F_357 ( V_96 ) ;
}
static int T_19 F_362 ( void )
{
int V_34 ;
V_751 = F_353 ( V_182 , NULL ) ;
if ( ! V_751 )
F_363 ( L_82 ) ;
V_34 = F_364 ( & V_472 ) ;
if ( V_34 < 0 )
F_365 ( V_751 ) ;
return V_34 ;
}
static void T_20 F_366 ( void )
{
F_367 ( & V_472 ) ;
F_365 ( V_751 ) ;
}
