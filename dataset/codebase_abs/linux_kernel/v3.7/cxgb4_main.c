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
V_114 = F_50 ( V_24 -> V_109 [ V_118 ] . V_119 ,
V_120 , 0 ,
V_24 -> V_109 [ V_118 ] . V_110 ,
& V_13 -> V_122 [ V_115 ] . V_85 ) ;
if ( V_114 )
goto V_123;
V_118 ++ ;
}
F_47 (s, ofldqidx) {
V_114 = F_50 ( V_24 -> V_109 [ V_118 ] . V_119 ,
V_120 , 0 ,
V_24 -> V_109 [ V_118 ] . V_110 ,
& V_13 -> V_124 [ V_116 ] . V_85 ) ;
if ( V_114 )
goto V_123;
V_118 ++ ;
}
F_48 (s, rdmaqidx) {
V_114 = F_50 ( V_24 -> V_109 [ V_118 ] . V_119 ,
V_120 , 0 ,
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
F_52 ( V_24 -> V_109 [ -- V_118 ] . V_119 ,
& V_13 -> V_122 [ V_115 ] . V_85 ) ;
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
F_81 ( V_11 , L_27 ) ;
V_34 = F_82 ( V_24 , V_24 -> V_169 , V_161 -> V_79 , V_161 -> V_170 ,
false ) ;
if ( ! V_34 )
F_81 ( V_11 , L_28
V_163 L_29 ,
F_80 ( V_157 ) ,
F_83 ( V_157 ) ,
F_84 ( V_157 ) ,
F_85 ( V_157 ) ) ;
else
F_34 ( V_11 , L_30 , - V_34 ) ;
} else {
V_34 = - V_166 ;
}
V_167: F_86 ( V_161 ) ;
return V_34 ;
}
void * F_87 ( T_7 V_170 )
{
void * V_15 = F_88 ( V_170 , V_131 ) ;
if ( ! V_15 )
V_15 = F_89 ( V_170 ) ;
return V_15 ;
}
static void F_90 ( void * V_33 )
{
if ( F_91 ( V_33 ) )
F_92 ( V_33 ) ;
else
F_57 ( V_33 ) ;
}
static inline int F_93 ( const struct V_1 * V_24 )
{
return V_24 -> V_7 . V_171 ;
}
static T_6 F_94 ( struct V_10 * V_11 )
{
return F_95 ( V_11 ) -> V_172 ;
}
static void F_96 ( struct V_10 * V_11 , T_6 V_173 )
{
F_95 ( V_11 ) -> V_172 = V_173 ;
}
static int F_97 ( struct V_10 * V_11 , int V_174 )
{
switch ( V_174 ) {
case V_175 :
return F_11 ( V_176 ) ;
default:
return - V_177 ;
}
}
static int F_98 ( struct V_10 * V_11 )
{
return V_178 ;
}
static int F_99 ( struct V_10 * V_11 )
{
return V_179 ;
}
static void F_100 ( struct V_10 * V_11 , struct V_180 * V_181 )
{
struct V_1 * V_1 = F_95 ( V_11 ) ;
F_101 ( V_181 -> V_182 , V_183 , sizeof( V_181 -> V_182 ) ) ;
F_101 ( V_181 -> V_184 , V_185 , sizeof( V_181 -> V_184 ) ) ;
F_101 ( V_181 -> V_186 , F_102 ( V_1 -> V_96 ) ,
sizeof( V_181 -> V_186 ) ) ;
if ( V_1 -> V_7 . V_168 )
snprintf ( V_181 -> V_187 , sizeof( V_181 -> V_187 ) ,
L_31 ,
F_80 ( V_1 -> V_7 . V_168 ) ,
F_83 ( V_1 -> V_7 . V_168 ) ,
F_84 ( V_1 -> V_7 . V_168 ) ,
F_85 ( V_1 -> V_7 . V_168 ) ,
F_80 ( V_1 -> V_7 . V_188 ) ,
F_83 ( V_1 -> V_7 . V_188 ) ,
F_84 ( V_1 -> V_7 . V_188 ) ,
F_85 ( V_1 -> V_7 . V_188 ) ) ;
}
static void F_103 ( struct V_10 * V_11 , T_6 V_189 , T_3 * V_79 )
{
if ( V_189 == V_175 )
memcpy ( V_79 , V_176 , sizeof( V_176 ) ) ;
}
static void F_104 ( const struct V_1 * V_24 ,
const struct V_14 * V_15 , struct V_190 * V_13 )
{
int V_105 ;
const struct V_71 * V_191 = & V_24 -> V_66 . V_148 [ V_15 -> V_129 ] ;
const struct V_128 * V_192 = & V_24 -> V_66 . V_122 [ V_15 -> V_129 ] ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
for ( V_105 = 0 ; V_105 < V_15 -> V_113 ; V_105 ++ , V_192 ++ , V_191 ++ ) {
V_13 -> V_193 += V_191 -> V_193 ;
V_13 -> V_194 += V_191 -> V_195 ;
V_13 -> V_196 += V_192 -> V_89 . V_197 ;
V_13 -> V_198 += V_192 -> V_89 . V_198 ;
V_13 -> V_199 += V_191 -> V_199 ;
V_13 -> V_200 += V_192 -> V_89 . V_201 ;
V_13 -> V_202 += V_192 -> V_89 . V_203 ;
}
}
static void F_105 ( struct V_10 * V_11 , struct V_204 * V_89 ,
T_1 * V_79 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_106 ( V_1 , V_26 -> V_52 , (struct V_205 * ) V_79 ) ;
V_79 += sizeof( struct V_205 ) / sizeof( T_1 ) ;
F_104 ( V_1 , V_26 , (struct V_190 * ) V_79 ) ;
}
static inline unsigned int F_107 ( const struct V_1 * V_206 )
{
return 4 | ( V_206 -> V_7 . V_207 << 10 ) | ( 1 << 16 ) ;
}
static void F_108 ( struct V_1 * V_206 , void * V_208 , unsigned int V_209 ,
unsigned int V_210 )
{
T_6 * V_15 = V_208 + V_209 ;
for ( ; V_209 <= V_210 ; V_209 += sizeof( T_6 ) )
* V_15 ++ = F_41 ( V_206 , V_209 ) ;
}
static void F_109 ( struct V_10 * V_11 , struct V_211 * V_212 ,
void * V_208 )
{
static const unsigned int V_213 [] = {
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
struct V_1 * V_206 = F_95 ( V_11 ) ;
V_212 -> V_184 = F_107 ( V_206 ) ;
memset ( V_208 , 0 , V_178 ) ;
for ( V_105 = 0 ; V_105 < F_11 ( V_213 ) ; V_105 += 2 )
F_108 ( V_206 , V_208 , V_213 [ V_105 ] , V_213 [ V_105 + 1 ] ) ;
}
static int F_110 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
if ( ! F_7 ( V_11 ) )
return - V_214 ;
if ( V_15 -> V_16 . V_215 != V_216 )
return - V_166 ;
F_111 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ) ;
return 0 ;
}
static int F_112 ( struct V_10 * V_11 ,
enum V_217 V_218 )
{
unsigned int V_173 ;
struct V_1 * V_24 = F_95 ( V_11 ) ;
if ( V_218 == V_219 )
V_173 = 0xffff ;
else if ( V_218 == V_220 )
V_173 = 0 ;
else
return - V_166 ;
return F_113 ( V_24 , V_24 -> V_41 , F_61 ( V_11 ) -> V_42 , V_173 ) ;
}
static unsigned int F_114 ( unsigned int type , unsigned int V_221 )
{
unsigned int V_100 = 0 ;
if ( type == V_222 || type == V_223 ||
type == V_224 ) {
V_100 |= V_225 ;
if ( V_221 & V_226 )
V_100 |= V_227 ;
if ( V_221 & V_228 )
V_100 |= V_229 ;
if ( V_221 & V_230 )
V_100 |= V_231 ;
} else if ( type == V_232 || type == V_233 ) {
V_100 |= V_234 ;
if ( V_221 & V_228 )
V_100 |= V_235 ;
if ( V_221 & V_230 )
V_100 |= V_236 ;
} else if ( type == V_237 )
V_100 |= V_234 | V_238 ;
else if ( type == V_239 )
V_100 |= V_234 | V_240 |
V_238 | V_235 ;
else if ( type == V_241 )
V_100 |= V_234 | V_240 |
V_238 | V_235 |
V_236 ;
else if ( type == V_242 ||
type == V_243 || type == V_244 )
V_100 |= V_245 ;
if ( V_221 & V_246 )
V_100 |= V_247 ;
return V_100 ;
}
static unsigned int F_115 ( unsigned int V_221 )
{
unsigned int V_100 = 0 ;
if ( V_221 & V_248 )
V_100 |= V_226 ;
if ( V_221 & V_249 )
V_100 |= V_228 ;
if ( V_221 & V_250 )
V_100 |= V_230 ;
return V_100 ;
}
static int F_116 ( struct V_10 * V_11 , struct V_251 * V_252 )
{
const struct V_14 * V_15 = F_5 ( V_11 ) ;
if ( V_15 -> V_253 == V_222 ||
V_15 -> V_253 == V_223 ||
V_15 -> V_253 == V_224 )
V_252 -> V_23 = V_254 ;
else if ( V_15 -> V_253 == V_242 ||
V_15 -> V_253 == V_243 )
V_252 -> V_23 = V_255 ;
else if ( V_15 -> V_253 == V_244 ) {
if ( V_15 -> V_27 == V_256 ||
V_15 -> V_27 == V_257 )
V_252 -> V_23 = V_258 ;
else
V_252 -> V_23 = V_255 ;
} else
V_252 -> V_23 = V_259 ;
if ( V_15 -> V_260 >= 0 ) {
V_252 -> V_261 = V_15 -> V_260 ;
V_252 -> V_262 = V_263 ;
V_252 -> V_264 = V_15 -> V_253 == V_222 ?
V_265 : V_266 ;
} else {
V_252 -> V_261 = 0 ;
V_252 -> V_262 = V_267 ;
V_252 -> V_264 = 0 ;
}
V_252 -> V_268 = F_114 ( V_15 -> V_253 , V_15 -> V_16 . V_268 ) ;
V_252 -> V_269 = F_114 ( V_15 -> V_253 ,
V_15 -> V_16 . V_269 ) ;
F_117 ( V_252 ,
F_3 ( V_11 ) ? V_15 -> V_16 . V_17 : 0 ) ;
V_252 -> V_270 = V_271 ;
V_252 -> V_215 = V_15 -> V_16 . V_215 ;
V_252 -> V_272 = 0 ;
V_252 -> V_273 = 0 ;
return 0 ;
}
static unsigned int F_118 ( int V_17 )
{
if ( V_17 == V_20 )
return V_226 ;
if ( V_17 == V_19 )
return V_228 ;
if ( V_17 == V_18 )
return V_230 ;
return 0 ;
}
static int F_119 ( struct V_10 * V_11 , struct V_251 * V_252 )
{
unsigned int V_274 ;
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_275 * V_276 = & V_15 -> V_16 ;
T_6 V_17 = F_120 ( V_252 ) ;
if ( V_252 -> V_270 != V_271 )
return - V_166 ;
if ( ! ( V_276 -> V_268 & V_246 ) ) {
if ( V_252 -> V_215 == V_277 &&
( V_276 -> V_268 & F_118 ( V_17 ) ) )
return 0 ;
return - V_166 ;
}
if ( V_252 -> V_215 == V_277 ) {
V_274 = F_118 ( V_17 ) ;
if ( ! ( V_276 -> V_268 & V_274 ) || ( V_17 == V_19 ) ||
( V_17 == V_18 ) )
return - V_166 ;
V_276 -> V_278 = V_274 ;
V_276 -> V_269 = 0 ;
} else {
V_274 = F_115 ( V_252 -> V_269 ) ;
if ( ! ( V_276 -> V_268 & V_274 ) )
return - V_166 ;
V_276 -> V_278 = 0 ;
V_276 -> V_269 = V_274 | V_246 ;
}
V_276 -> V_215 = V_252 -> V_215 ;
if ( F_7 ( V_11 ) )
return F_23 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ,
V_276 ) ;
return 0 ;
}
static void F_121 ( struct V_10 * V_11 ,
struct V_279 * V_280 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
V_280 -> V_215 = ( V_15 -> V_16 . V_281 & V_282 ) != 0 ;
V_280 -> V_283 = ( V_15 -> V_16 . V_12 & V_284 ) != 0 ;
V_280 -> V_285 = ( V_15 -> V_16 . V_12 & V_286 ) != 0 ;
}
static int F_122 ( struct V_10 * V_11 ,
struct V_279 * V_280 )
{
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_275 * V_276 = & V_15 -> V_16 ;
if ( V_280 -> V_215 == V_277 )
V_276 -> V_281 = 0 ;
else if ( V_276 -> V_268 & V_246 )
V_276 -> V_281 = V_282 ;
else
return - V_166 ;
if ( V_280 -> V_283 )
V_276 -> V_281 |= V_284 ;
if ( V_280 -> V_285 )
V_276 -> V_281 |= V_286 ;
if ( F_7 ( V_11 ) )
return F_23 ( V_15 -> V_1 , V_15 -> V_1 -> V_41 , V_15 -> V_52 ,
V_276 ) ;
return 0 ;
}
static void F_123 ( struct V_10 * V_11 , struct V_287 * V_288 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_66 * V_13 = & V_26 -> V_1 -> V_66 ;
V_288 -> V_289 = V_290 ;
V_288 -> V_291 = V_292 ;
V_288 -> V_293 = 0 ;
V_288 -> V_294 = V_295 ;
V_288 -> V_296 = V_13 -> V_122 [ V_26 -> V_129 ] . V_149 . V_170 - 8 ;
V_288 -> V_297 = V_13 -> V_122 [ V_26 -> V_129 ] . V_85 . V_170 ;
V_288 -> V_298 = 0 ;
V_288 -> V_299 = V_13 -> V_148 [ V_26 -> V_129 ] . V_54 . V_170 ;
}
static int F_124 ( struct V_10 * V_11 , struct V_287 * V_288 )
{
int V_105 ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
struct V_66 * V_13 = & V_1 -> V_66 ;
if ( V_288 -> V_296 > V_290 || V_288 -> V_298 ||
V_288 -> V_299 > V_295 ||
V_288 -> V_297 > V_292 ||
V_288 -> V_297 < V_300 ||
V_288 -> V_296 < V_301 || V_288 -> V_299 < V_302 )
return - V_166 ;
if ( V_1 -> V_45 & V_303 )
return - V_304 ;
for ( V_105 = 0 ; V_105 < V_26 -> V_113 ; ++ V_105 ) {
V_13 -> V_148 [ V_26 -> V_129 + V_105 ] . V_54 . V_170 = V_288 -> V_299 ;
V_13 -> V_122 [ V_26 -> V_129 + V_105 ] . V_149 . V_170 = V_288 -> V_296 + 8 ;
V_13 -> V_122 [ V_26 -> V_129 + V_105 ] . V_85 . V_170 = V_288 -> V_297 ;
}
return 0 ;
}
static int F_125 ( const struct V_66 * V_13 , int time )
{
int V_105 , V_305 , V_306 = 0 , V_307 = V_308 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_309 ) ; V_105 ++ ) {
V_305 = time - V_13 -> V_309 [ V_105 ] ;
if ( V_305 < 0 )
V_305 = - V_305 ;
if ( V_305 < V_307 ) {
V_307 = V_305 ;
V_306 = V_105 ;
}
}
return V_306 ;
}
static int F_126 ( const struct V_66 * V_13 , int V_310 )
{
int V_105 , V_305 , V_306 = 0 , V_307 = V_308 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_311 ) ; V_105 ++ ) {
V_305 = V_310 - V_13 -> V_311 [ V_105 ] ;
if ( V_305 < 0 )
V_305 = - V_305 ;
if ( V_305 < V_307 ) {
V_307 = V_305 ;
V_306 = V_105 ;
}
}
return V_306 ;
}
static unsigned int F_127 ( const struct V_1 * V_24 ,
const struct V_53 * V_54 )
{
unsigned int V_151 = V_54 -> V_140 >> 1 ;
return V_151 < V_312 ? V_24 -> V_66 . V_309 [ V_151 ] : 0 ;
}
static int F_128 ( struct V_1 * V_24 , struct V_53 * V_54 ,
unsigned int V_313 , unsigned int V_314 )
{
if ( ( V_313 | V_314 ) == 0 )
V_314 = 1 ;
if ( V_314 ) {
int V_114 ;
T_6 V_100 , V_315 ;
V_315 = F_126 ( & V_24 -> V_66 , V_314 ) ;
if ( V_54 -> V_110 && V_54 -> V_316 != V_315 ) {
V_100 = F_129 ( V_317 ) |
F_130 ( V_318 ) |
F_131 ( V_54 -> V_141 ) ;
V_114 = F_132 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , 1 , & V_100 ,
& V_315 ) ;
if ( V_114 )
return V_114 ;
}
V_54 -> V_316 = V_315 ;
}
V_313 = V_313 == 0 ? 6 : F_125 ( & V_24 -> V_66 , V_313 ) ;
V_54 -> V_140 = F_133 ( V_313 ) | ( V_314 > 0 ? V_319 : 0 ) ;
return 0 ;
}
static int F_134 ( struct V_10 * V_11 , struct V_320 * V_321 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_24 = V_26 -> V_1 ;
return F_128 ( V_24 , & V_24 -> V_66 . V_122 [ V_26 -> V_129 ] . V_85 ,
V_321 -> V_322 , V_321 -> V_323 ) ;
}
static int F_135 ( struct V_10 * V_11 , struct V_320 * V_321 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_1 * V_24 = V_26 -> V_1 ;
const struct V_53 * V_324 = & V_24 -> V_66 . V_122 [ V_26 -> V_129 ] . V_85 ;
V_321 -> V_322 = F_127 ( V_24 , V_324 ) ;
V_321 -> V_323 = ( V_324 -> V_140 & V_319 ) ?
V_24 -> V_66 . V_311 [ V_324 -> V_316 ] : 0 ;
return 0 ;
}
static int F_136 ( unsigned int V_325 , unsigned int V_41 , unsigned int V_326 )
{
V_41 *= V_326 ;
if ( V_325 < 1024 )
return V_325 + ( 31 << 10 ) ;
if ( V_325 < 1024 + V_41 )
return 31744 - V_41 + V_325 - 1024 ;
if ( V_325 < V_179 )
return V_325 - 1024 - V_41 ;
return - V_166 ;
}
static int F_137 ( struct V_1 * V_24 , unsigned int V_325 , T_6 * V_100 )
{
int V_327 = F_136 ( V_325 , V_24 -> V_41 , V_328 ) ;
if ( V_327 >= 0 )
V_327 = F_138 ( V_24 -> V_96 , V_327 , sizeof( T_6 ) , V_100 ) ;
return V_327 < 0 ? V_327 : 0 ;
}
static int F_139 ( struct V_1 * V_24 , unsigned int V_325 , T_6 V_100 )
{
int V_327 = F_136 ( V_325 , V_24 -> V_41 , V_328 ) ;
if ( V_327 >= 0 )
V_327 = F_140 ( V_24 -> V_96 , V_327 , sizeof( T_6 ) , & V_100 ) ;
return V_327 < 0 ? V_327 : 0 ;
}
static int F_141 ( struct V_10 * V_11 , struct V_329 * V_288 ,
T_3 * V_79 )
{
int V_105 , V_114 = 0 ;
struct V_1 * V_1 = F_95 ( V_11 ) ;
T_3 * V_208 = F_55 ( V_179 , V_131 ) ;
if ( ! V_208 )
return - V_132 ;
V_288 -> V_330 = V_331 ;
for ( V_105 = V_288 -> V_332 & ~ 3 ; ! V_114 && V_105 < V_288 -> V_332 + V_288 -> V_333 ; V_105 += 4 )
V_114 = F_137 ( V_1 , V_105 , ( T_6 * ) & V_208 [ V_105 ] ) ;
if ( ! V_114 )
memcpy ( V_79 , V_208 + V_288 -> V_332 , V_288 -> V_333 ) ;
F_57 ( V_208 ) ;
return V_114 ;
}
static int F_142 ( struct V_10 * V_11 , struct V_329 * V_334 ,
T_3 * V_79 )
{
T_3 * V_208 ;
int V_114 = 0 ;
T_6 V_335 , V_336 , * V_15 ;
struct V_1 * V_1 = F_95 ( V_11 ) ;
if ( V_334 -> V_330 != V_331 )
return - V_166 ;
V_335 = V_334 -> V_332 & ~ 3 ;
V_336 = ( V_334 -> V_333 + ( V_334 -> V_332 & 3 ) + 3 ) & ~ 3 ;
if ( V_1 -> V_41 > 0 ) {
T_6 V_209 = 1024 + V_1 -> V_41 * V_328 ;
if ( V_335 < V_209 ||
V_335 + V_336 > V_209 + V_328 )
return - V_337 ;
}
if ( V_335 != V_334 -> V_332 || V_336 != V_334 -> V_333 ) {
V_208 = F_55 ( V_336 , V_131 ) ;
if ( ! V_208 )
return - V_132 ;
V_114 = F_137 ( V_1 , V_335 , ( T_6 * ) V_208 ) ;
if ( ! V_114 && V_336 > 4 )
V_114 = F_137 ( V_1 ,
V_335 + V_336 - 4 ,
( T_6 * ) & V_208 [ V_336 - 4 ] ) ;
if ( V_114 )
goto V_167;
memcpy ( V_208 + ( V_334 -> V_332 & 3 ) , V_79 , V_334 -> V_333 ) ;
} else
V_208 = V_79 ;
V_114 = F_143 ( V_1 , false ) ;
if ( V_114 )
goto V_167;
for ( V_15 = ( T_6 * ) V_208 ; ! V_114 && V_336 ; V_336 -= 4 , V_15 ++ ) {
V_114 = F_139 ( V_1 , V_335 , * V_15 ) ;
V_335 += 4 ;
}
if ( ! V_114 )
V_114 = F_143 ( V_1 , true ) ;
V_167:
if ( V_208 != V_79 )
F_57 ( V_208 ) ;
return V_114 ;
}
static int F_144 ( struct V_10 * V_136 , struct V_338 * V_339 )
{
int V_34 ;
const struct V_160 * V_161 ;
struct V_1 * V_24 = F_95 ( V_136 ) ;
V_339 -> V_79 [ sizeof( V_339 -> V_79 ) - 1 ] = '\0' ;
V_34 = F_79 ( & V_161 , V_339 -> V_79 , V_24 -> V_82 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_145 ( V_24 , V_161 -> V_79 , V_161 -> V_170 ) ;
F_86 ( V_161 ) ;
if ( ! V_34 )
F_81 ( V_24 -> V_82 , L_32 , V_339 -> V_79 ) ;
return V_34 ;
}
static void F_146 ( struct V_10 * V_11 , struct V_340 * V_341 )
{
V_341 -> V_268 = V_342 | V_343 ;
V_341 -> V_344 = F_95 ( V_11 ) -> V_341 ;
memset ( & V_341 -> V_345 , 0 , sizeof( V_341 -> V_345 ) ) ;
}
static int F_147 ( struct V_10 * V_11 , struct V_340 * V_341 )
{
int V_114 = 0 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_341 -> V_344 & ~ V_346 )
return - V_166 ;
F_148 ( V_26 -> V_1 , V_26 -> V_52 ,
( V_341 -> V_344 & V_343 ) ? V_11 -> V_51 : NULL ) ;
if ( V_341 -> V_344 & V_342 ) {
V_114 = F_149 ( V_26 -> V_1 , V_26 -> V_52 , 0xfe , ~ 0ULL ,
~ 0ULL , 0 , false ) ;
if ( ! V_114 )
V_114 = F_149 ( V_26 -> V_1 , V_26 -> V_52 , 1 ,
~ 6ULL , ~ 0ULL , V_347 , true ) ;
} else
F_149 ( V_26 -> V_1 , V_26 -> V_52 , 0 , 0 , 0 , 0 , false ) ;
return V_114 ;
}
static int F_150 ( struct V_10 * V_11 , T_8 V_48 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
T_8 V_348 = V_11 -> V_48 ^ V_48 ;
int V_114 ;
if ( ! ( V_348 & V_49 ) )
return 0 ;
V_114 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , - 1 ,
- 1 , - 1 , - 1 ,
! ! ( V_48 & V_49 ) , true ) ;
if ( F_151 ( V_114 ) )
V_11 -> V_48 = V_48 ^ V_49 ;
return V_114 ;
}
static T_6 F_152 ( struct V_10 * V_11 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
return V_26 -> V_130 ;
}
static int F_153 ( struct V_10 * V_11 , T_6 * V_15 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
unsigned int V_108 = V_26 -> V_130 ;
while ( V_108 -- )
V_15 [ V_108 ] = V_26 -> V_127 [ V_108 ] ;
return 0 ;
}
static int F_154 ( struct V_10 * V_11 , const T_6 * V_15 )
{
unsigned int V_105 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
for ( V_105 = 0 ; V_105 < V_26 -> V_130 ; V_105 ++ )
V_26 -> V_127 [ V_105 ] = V_15 [ V_105 ] ;
if ( V_26 -> V_1 -> V_45 & V_303 )
return F_54 ( V_26 , V_26 -> V_127 ) ;
return 0 ;
}
static int F_155 ( struct V_10 * V_11 , struct V_349 * V_181 ,
T_6 * V_350 )
{
const struct V_14 * V_26 = F_5 ( V_11 ) ;
switch ( V_181 -> V_252 ) {
case V_351 : {
unsigned int V_100 = V_26 -> V_352 ;
V_181 -> V_79 = 0 ;
switch ( V_181 -> V_353 ) {
case V_354 :
if ( V_100 & V_355 )
V_181 -> V_79 = V_356 | V_357 |
V_358 | V_359 ;
else if ( V_100 & V_360 )
V_181 -> V_79 = V_356 | V_357 ;
break;
case V_361 :
if ( ( V_100 & V_355 ) &&
( V_100 & V_362 ) )
V_181 -> V_79 = V_356 | V_357 |
V_358 | V_359 ;
else if ( V_100 & V_360 )
V_181 -> V_79 = V_356 | V_357 ;
break;
case V_363 :
case V_364 :
case V_365 :
if ( V_100 & V_360 )
V_181 -> V_79 = V_356 | V_357 ;
break;
case V_366 :
if ( V_100 & V_367 )
V_181 -> V_79 = V_356 | V_357 |
V_358 | V_359 ;
else if ( V_100 & V_368 )
V_181 -> V_79 = V_356 | V_357 ;
break;
case V_369 :
if ( ( V_100 & V_367 ) &&
( V_100 & V_362 ) )
V_181 -> V_79 = V_356 | V_357 |
V_358 | V_359 ;
else if ( V_100 & V_368 )
V_181 -> V_79 = V_356 | V_357 ;
break;
case V_370 :
case V_371 :
case V_372 :
if ( V_100 & V_368 )
V_181 -> V_79 = V_356 | V_357 ;
break;
}
return 0 ;
}
case V_373 :
V_181 -> V_79 = V_26 -> V_113 ;
return 0 ;
}
return - V_177 ;
}
static T_9 F_156 ( struct V_374 * V_374 , char T_10 * V_208 , T_7 V_375 ,
T_11 * V_376 )
{
T_11 V_377 = * V_376 ;
T_11 V_378 = V_374 -> V_379 . V_380 -> V_381 -> V_382 ;
unsigned int V_383 = ( V_384 ) V_374 -> V_385 & 3 ;
struct V_1 * V_24 = V_374 -> V_385 - V_383 ;
if ( V_377 < 0 )
return - V_166 ;
if ( V_377 >= V_378 )
return 0 ;
if ( V_375 > V_378 - V_377 )
V_375 = V_378 - V_377 ;
while ( V_375 ) {
T_7 V_333 ;
int V_34 , V_386 ;
T_12 V_79 [ 16 ] ;
if ( V_383 == V_387 )
V_34 = F_157 ( V_24 , V_377 , V_79 , NULL ) ;
else
V_34 = F_158 ( V_24 , V_383 , V_377 , V_79 , NULL ) ;
if ( V_34 )
return V_34 ;
V_386 = V_377 % sizeof( V_79 ) ;
V_333 = F_159 ( V_375 , sizeof( V_79 ) - V_386 ) ;
if ( F_160 ( V_208 , ( T_3 * ) V_79 + V_386 , V_333 ) )
return - V_388 ;
V_208 += V_333 ;
V_377 += V_333 ;
V_375 -= V_333 ;
}
V_375 = V_377 - * V_376 ;
* V_376 = V_377 ;
return V_375 ;
}
static void T_13 F_161 ( struct V_1 * V_24 , const char * V_111 ,
unsigned int V_151 , unsigned int V_389 )
{
struct V_380 * V_390 ;
V_390 = F_162 ( V_111 , V_391 , V_24 -> V_392 ,
( void * ) V_24 + V_151 , & V_393 ) ;
if ( V_390 && V_390 -> V_381 )
V_390 -> V_381 -> V_382 = V_389 << 20 ;
}
static int T_13 F_163 ( struct V_1 * V_24 )
{
int V_105 ;
if ( F_164 ( V_24 -> V_392 ) )
return - 1 ;
V_105 = F_41 ( V_24 , V_394 ) ;
if ( V_105 & V_395 )
F_161 ( V_24 , L_33 , V_396 , 5 ) ;
if ( V_105 & V_397 )
F_161 ( V_24 , L_34 , V_398 , 5 ) ;
if ( V_105 & V_399 )
F_161 ( V_24 , L_35 , V_387 ,
F_165 ( F_41 ( V_24 , V_400 ) ) ) ;
if ( V_24 -> V_401 )
F_162 ( L_36 , V_391 , V_24 -> V_392 , V_24 ,
& V_402 ) ;
return 0 ;
}
int F_166 ( struct V_403 * V_147 , void * V_79 )
{
int V_404 = - 1 ;
F_167 ( & V_147 -> V_405 ) ;
if ( V_147 -> V_406 ) {
union V_407 * V_15 = V_147 -> V_406 ;
V_404 = V_15 - V_147 -> V_408 ;
V_147 -> V_406 = V_15 -> V_409 ;
V_15 -> V_79 = V_79 ;
V_147 -> V_410 ++ ;
}
F_168 ( & V_147 -> V_405 ) ;
return V_404 ;
}
void F_169 ( struct V_403 * V_147 , unsigned int V_404 )
{
union V_407 * V_15 = & V_147 -> V_408 [ V_404 ] ;
F_167 ( & V_147 -> V_405 ) ;
V_15 -> V_409 = V_147 -> V_406 ;
V_147 -> V_406 = V_15 ;
V_147 -> V_410 -- ;
F_168 ( & V_147 -> V_405 ) ;
}
int F_170 ( struct V_403 * V_147 , int V_411 , void * V_79 )
{
int V_412 ;
F_167 ( & V_147 -> V_413 ) ;
if ( V_411 == V_414 ) {
V_412 = F_171 ( V_147 -> V_415 , V_147 -> V_416 ) ;
if ( V_412 < V_147 -> V_416 )
F_172 ( V_412 , V_147 -> V_415 ) ;
else
V_412 = - 1 ;
} else {
V_412 = F_173 ( V_147 -> V_415 , V_147 -> V_416 , 2 ) ;
if ( V_412 < 0 )
V_412 = - 1 ;
}
if ( V_412 >= 0 ) {
V_147 -> V_417 [ V_412 ] . V_79 = V_79 ;
V_412 += V_147 -> V_418 ;
V_147 -> V_419 ++ ;
}
F_168 ( & V_147 -> V_413 ) ;
return V_412 ;
}
void F_174 ( struct V_403 * V_147 , unsigned int V_412 , int V_411 )
{
V_412 -= V_147 -> V_418 ;
F_167 ( & V_147 -> V_413 ) ;
if ( V_411 == V_414 )
F_175 ( V_412 , V_147 -> V_415 ) ;
else
F_176 ( V_147 -> V_415 , V_412 , 2 ) ;
V_147 -> V_417 [ V_412 ] . V_79 = NULL ;
V_147 -> V_419 -- ;
F_168 ( & V_147 -> V_413 ) ;
}
static void F_177 ( struct V_420 * V_421 , unsigned int V_422 ,
unsigned int V_423 )
{
struct V_424 * V_425 ;
F_178 ( V_421 , V_426 , V_422 ) ;
V_425 = (struct V_424 * ) F_179 ( V_421 , sizeof( * V_425 ) ) ;
F_180 ( V_425 , V_423 ) ;
F_181 ( V_425 ) = F_182 ( F_183 ( V_427 , V_423 ) ) ;
}
static void F_184 ( struct V_403 * V_147 , unsigned int V_422 ,
unsigned int V_423 )
{
void * * V_15 = & V_147 -> V_428 [ V_423 ] ;
struct V_1 * V_24 = F_29 ( V_147 , struct V_1 , V_429 ) ;
F_167 ( & V_24 -> V_430 ) ;
* V_15 = V_24 -> V_431 ;
V_24 -> V_431 = ( void * * ) ( ( V_384 ) V_15 | V_422 ) ;
if ( ! V_24 -> V_432 ) {
V_24 -> V_432 = true ;
F_185 ( V_433 , & V_24 -> V_434 ) ;
}
F_168 ( & V_24 -> V_430 ) ;
}
static void F_186 ( struct V_435 * V_436 )
{
struct V_420 * V_421 ;
struct V_1 * V_24 ;
V_24 = F_29 ( V_436 , struct V_1 , V_434 ) ;
F_167 ( & V_24 -> V_430 ) ;
while ( V_24 -> V_431 ) {
void * * V_15 = V_24 -> V_431 ;
unsigned int V_422 = ( V_384 ) V_15 & 3 ;
V_15 = ( void * ) V_15 - V_422 ;
V_24 -> V_431 = * V_15 ;
* V_15 = NULL ;
F_168 ( & V_24 -> V_430 ) ;
while ( ! ( V_421 = F_187 ( sizeof( struct V_424 ) ,
V_131 ) ) )
F_188 ( 1 ) ;
F_177 ( V_421 , V_422 , V_15 - V_24 -> V_429 . V_428 ) ;
F_189 ( V_24 , V_421 ) ;
F_167 ( & V_24 -> V_430 ) ;
}
V_24 -> V_432 = false ;
F_168 ( & V_24 -> V_430 ) ;
}
void F_190 ( struct V_403 * V_147 , unsigned int V_422 , unsigned int V_423 )
{
void * V_437 ;
struct V_420 * V_421 ;
struct V_1 * V_24 = F_29 ( V_147 , struct V_1 , V_429 ) ;
V_437 = V_147 -> V_428 [ V_423 ] ;
V_421 = F_187 ( sizeof( struct V_424 ) , V_438 ) ;
if ( F_26 ( V_421 ) ) {
V_147 -> V_428 [ V_423 ] = NULL ;
F_177 ( V_421 , V_422 , V_423 ) ;
F_189 ( V_24 , V_421 ) ;
} else
F_184 ( V_147 , V_422 , V_423 ) ;
if ( V_437 )
F_191 ( & V_147 -> V_439 ) ;
}
static int F_192 ( struct V_403 * V_147 )
{
T_7 V_170 ;
unsigned int V_440 = V_147 -> V_440 ;
V_170 = V_147 -> V_441 * sizeof( * V_147 -> V_428 ) + V_440 * sizeof( * V_147 -> V_408 ) +
V_147 -> V_416 * sizeof( * V_147 -> V_417 ) +
F_193 ( V_147 -> V_416 ) * sizeof( long ) ;
V_147 -> V_428 = F_87 ( V_170 ) ;
if ( ! V_147 -> V_428 )
return - V_132 ;
V_147 -> V_408 = (union V_407 * ) & V_147 -> V_428 [ V_147 -> V_441 ] ;
V_147 -> V_417 = (struct V_442 * ) & V_147 -> V_408 [ V_440 ] ;
V_147 -> V_415 = ( unsigned long * ) & V_147 -> V_417 [ V_147 -> V_416 ] ;
F_194 ( & V_147 -> V_413 ) ;
F_194 ( & V_147 -> V_405 ) ;
V_147 -> V_419 = 0 ;
V_147 -> V_406 = NULL ;
V_147 -> V_410 = 0 ;
F_195 ( & V_147 -> V_439 , 0 ) ;
if ( V_440 ) {
while ( -- V_440 )
V_147 -> V_408 [ V_440 - 1 ] . V_409 = & V_147 -> V_408 [ V_440 ] ;
V_147 -> V_406 = V_147 -> V_408 ;
}
F_69 ( V_147 -> V_415 , V_147 -> V_416 ) ;
return 0 ;
}
int F_196 ( const struct V_10 * V_11 , unsigned int V_412 ,
T_12 V_443 , T_14 V_444 , unsigned int V_445 )
{
unsigned int V_422 ;
struct V_420 * V_421 ;
struct V_1 * V_24 ;
struct V_446 * V_425 ;
V_421 = F_187 ( sizeof( * V_425 ) , V_131 ) ;
if ( ! V_421 )
return - V_132 ;
V_24 = F_95 ( V_11 ) ;
V_425 = (struct V_446 * ) F_179 ( V_421 , sizeof( * V_425 ) ) ;
F_180 ( V_425 , 0 ) ;
F_181 ( V_425 ) = F_182 ( F_183 ( V_447 , V_412 ) ) ;
V_425 -> V_448 = V_444 ;
V_425 -> V_449 = F_197 ( 0 ) ;
V_425 -> V_450 = V_443 ;
V_425 -> V_451 = F_182 ( 0 ) ;
V_422 = F_60 ( & V_24 -> V_66 , V_445 ) ;
V_425 -> V_452 = F_198 ( F_199 ( V_422 ) ) ;
V_425 -> V_453 = F_198 ( V_454 |
V_455 | F_200 ( V_445 ) ) ;
return F_201 ( V_24 , V_421 ) ;
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
unsigned int F_204 ( const struct V_10 * V_11 , int V_458 )
{
struct V_1 * V_24 = F_95 ( V_11 ) ;
T_6 V_100 ;
V_100 = F_41 ( V_24 , V_459 ) ;
return V_458 ? F_205 ( V_100 ) : F_206 ( V_100 ) ;
}
unsigned int F_207 ( const struct V_10 * V_11 )
{
return F_61 ( V_11 ) -> V_42 ;
}
unsigned int F_208 ( const struct V_10 * V_11 )
{
return F_61 ( V_11 ) -> V_21 ;
}
void F_209 ( struct V_460 * V_96 , struct V_461 * V_462 ,
struct V_461 * V_463 )
{
struct V_1 * V_24 = F_210 ( V_96 ) ;
F_211 ( & V_24 -> V_464 ) ;
F_212 ( V_24 , V_462 , V_463 ) ;
F_213 ( & V_24 -> V_464 ) ;
}
void F_214 ( struct V_10 * V_11 , unsigned int V_465 ,
const unsigned int * V_466 )
{
struct V_1 * V_24 = F_95 ( V_11 ) ;
F_43 ( V_24 , V_467 , V_465 ) ;
F_43 ( V_24 , V_468 , F_215 ( V_466 [ 0 ] ) |
F_216 ( V_466 [ 1 ] ) | F_217 ( V_466 [ 2 ] ) |
F_218 ( V_466 [ 3 ] ) ) ;
}
int F_219 ( struct V_10 * V_11 )
{
struct V_1 * V_24 = F_95 ( V_11 ) ;
int V_34 ;
V_34 = F_220 ( V_24 , V_24 -> V_169 ,
0xe1000000 + V_469 , 0x20000000 ) ;
return V_34 ;
}
static int F_221 ( struct V_1 * V_24 , T_2 V_62 , T_2 * V_470 , T_2 * V_471 )
{
T_6 V_33 = F_41 ( V_24 , V_472 ) + 24 * V_62 + 8 ;
T_4 V_473 ;
int V_34 ;
V_34 = F_222 ( V_24 , V_33 , ( T_12 * ) & V_473 , 8 ) ;
if ( ! V_34 ) {
* V_471 = ( F_223 ( V_473 ) >> 25 ) & 0xffff ;
* V_470 = ( F_223 ( V_473 ) >> 9 ) & 0xffff ;
}
return V_34 ;
}
int F_224 ( struct V_10 * V_11 , T_2 V_62 , T_2 V_470 ,
T_2 V_170 )
{
struct V_1 * V_24 = F_95 ( V_11 ) ;
T_2 V_474 , V_475 ;
int V_34 ;
V_34 = F_221 ( V_24 , V_62 , & V_474 , & V_475 ) ;
if ( V_34 )
goto V_167;
if ( V_470 != V_474 ) {
T_2 V_305 ;
if ( V_470 >= V_474 )
V_305 = V_470 - V_474 ;
else
V_305 = V_170 - V_474 + V_470 ;
F_225 () ;
F_43 ( V_24 , F_42 ( V_476 ) ,
F_226 ( V_62 ) | F_227 ( V_305 ) ) ;
}
V_167:
return V_34 ;
}
static void F_228 ( struct V_477 * V_478 )
{
const struct V_162 * V_479 ;
const struct V_10 * V_136 = V_478 -> V_11 ;
if ( V_136 -> V_480 & V_481 )
V_136 = F_229 ( V_136 ) ;
V_479 = V_136 -> V_11 . V_479 ;
if ( V_479 && V_479 -> V_182 == & V_482 . V_182 )
F_230 ( F_231 ( V_479 ) , V_478 ) ;
}
static int F_232 ( struct V_483 * V_484 , unsigned long V_485 ,
void * V_79 )
{
switch ( V_485 ) {
case V_486 :
F_228 ( V_79 ) ;
break;
case V_487 :
default:
break;
}
return 0 ;
}
static void F_233 ( struct V_1 * V_24 , int V_488 )
{
T_6 V_100 ;
do {
F_234 ( V_489 ) ;
F_235 ( F_236 ( V_488 ) ) ;
V_100 = F_41 ( V_24 , V_459 ) ;
if ( F_205 ( V_100 ) == 0 && F_206 ( V_100 ) == 0 )
break;
} while ( 1 );
}
static void F_237 ( struct V_64 * V_54 )
{
F_238 ( & V_54 -> V_490 ) ;
V_54 -> V_491 = 1 ;
F_239 ( & V_54 -> V_490 ) ;
}
static void F_240 ( struct V_64 * V_54 )
{
F_238 ( & V_54 -> V_490 ) ;
V_54 -> V_491 = 0 ;
F_239 ( & V_54 -> V_490 ) ;
}
static void F_241 ( struct V_1 * V_24 )
{
int V_105 ;
F_51 (&adap->sge, i)
F_237 ( & V_24 -> V_66 . V_148 [ V_105 ] . V_54 ) ;
F_47 (&adap->sge, i)
F_237 ( & V_24 -> V_66 . V_70 [ V_105 ] . V_54 ) ;
F_46 (adap, i)
F_237 ( & V_24 -> V_66 . V_155 [ V_105 ] . V_54 ) ;
}
static void F_242 ( struct V_1 * V_24 )
{
int V_105 ;
F_51 (&adap->sge, i)
F_240 ( & V_24 -> V_66 . V_148 [ V_105 ] . V_54 ) ;
F_47 (&adap->sge, i)
F_240 ( & V_24 -> V_66 . V_70 [ V_105 ] . V_54 ) ;
F_46 (adap, i)
F_240 ( & V_24 -> V_66 . V_155 [ V_105 ] . V_54 ) ;
}
static void F_243 ( struct V_1 * V_24 , struct V_64 * V_54 )
{
T_2 V_474 , V_475 ;
int V_34 ;
F_167 ( & V_54 -> V_490 ) ;
V_34 = F_221 ( V_24 , ( T_2 ) V_54 -> V_141 , & V_474 , & V_475 ) ;
if ( V_34 )
goto V_167;
if ( V_54 -> V_492 != V_474 ) {
T_2 V_305 ;
if ( V_54 -> V_492 >= V_474 )
V_305 = V_54 -> V_492 - V_474 ;
else
V_305 = V_54 -> V_170 - V_474 + V_54 -> V_492 ;
F_225 () ;
F_43 ( V_24 , F_42 ( V_476 ) ,
F_226 ( V_54 -> V_141 ) | F_227 ( V_305 ) ) ;
}
V_167:
V_54 -> V_491 = 0 ;
F_168 ( & V_54 -> V_490 ) ;
if ( V_34 )
F_244 ( V_24 , L_37 ) ;
}
static void F_245 ( struct V_1 * V_24 )
{
int V_105 ;
F_51 (&adap->sge, i)
F_243 ( V_24 , & V_24 -> V_66 . V_148 [ V_105 ] . V_54 ) ;
F_47 (&adap->sge, i)
F_243 ( V_24 , & V_24 -> V_66 . V_70 [ V_105 ] . V_54 ) ;
F_46 (adap, i)
F_243 ( V_24 , & V_24 -> V_66 . V_155 [ V_105 ] . V_54 ) ;
}
static void F_246 ( struct V_1 * V_24 , enum V_493 V_252 )
{
F_247 ( & V_494 ) ;
if ( V_24 -> V_88 [ V_495 ] )
V_86 [ V_495 ] . F_248 ( V_24 -> V_88 [ V_495 ] ,
V_252 ) ;
F_249 ( & V_494 ) ;
}
static void F_250 ( struct V_435 * V_436 )
{
struct V_1 * V_24 ;
V_24 = F_29 ( V_436 , struct V_1 , V_496 ) ;
F_246 ( V_24 , V_497 ) ;
F_233 ( V_24 , V_498 ) ;
F_251 ( V_24 , V_499 ,
V_500 | V_501 ,
V_500 | V_501 ) ;
F_246 ( V_24 , V_502 ) ;
}
static void F_252 ( struct V_435 * V_436 )
{
struct V_1 * V_24 ;
V_24 = F_29 ( V_436 , struct V_1 , V_503 ) ;
F_251 ( V_24 , V_504 , V_505 , 0 ) ;
F_241 ( V_24 ) ;
F_246 ( V_24 , V_506 ) ;
F_233 ( V_24 , 1 ) ;
F_245 ( V_24 ) ;
F_242 ( V_24 ) ;
}
void F_253 ( struct V_1 * V_24 )
{
F_251 ( V_24 , V_499 ,
V_500 | V_501 , 0 ) ;
F_185 ( V_433 , & V_24 -> V_496 ) ;
}
void F_254 ( struct V_1 * V_24 )
{
F_185 ( V_433 , & V_24 -> V_503 ) ;
}
static void F_255 ( struct V_1 * V_24 , unsigned int V_87 )
{
void * V_507 ;
struct V_508 V_509 ;
V_509 . V_96 = V_24 -> V_96 ;
V_509 . V_401 = V_24 -> V_401 ;
V_509 . V_429 = & V_24 -> V_429 ;
V_509 . V_510 = V_24 -> V_23 ;
V_509 . V_511 = & V_24 -> V_512 ;
V_509 . V_456 = V_24 -> V_7 . V_456 ;
if ( V_87 == V_495 ) {
V_509 . V_513 = V_24 -> V_66 . V_154 ;
V_509 . V_514 = V_24 -> V_66 . V_515 ;
} else if ( V_87 == V_516 ) {
V_509 . V_513 = V_24 -> V_66 . V_153 ;
V_509 . V_514 = V_24 -> V_66 . V_152 ;
}
V_509 . V_517 = V_24 -> V_66 . V_152 ;
V_509 . V_518 = V_24 -> V_7 . V_8 ;
V_509 . V_8 = V_24 -> V_7 . V_8 ;
V_509 . V_519 = V_24 -> V_7 . V_520 ;
V_509 . V_521 = V_24 -> V_7 . V_207 ;
V_509 . V_522 = F_256 ( F_41 ( V_24 , V_523 ) ) ;
V_509 . V_524 = 1 << F_257 (
F_41 ( V_24 , V_525 ) >>
( V_24 -> V_41 * 4 ) ) ;
V_509 . V_526 = 1 << F_257 (
F_41 ( V_24 , V_527 ) >>
( V_24 -> V_41 * 4 ) ) ;
V_509 . V_528 = V_24 -> V_212 + F_42 ( V_139 ) ;
V_509 . V_529 = V_24 -> V_212 + F_42 ( V_476 ) ;
V_509 . V_168 = V_24 -> V_7 . V_168 ;
V_509 . V_530 = V_530 ;
V_507 = V_86 [ V_87 ] . F_258 ( & V_509 ) ;
if ( F_259 ( V_507 ) ) {
F_260 ( V_24 -> V_82 ,
L_38 ,
V_531 [ V_87 ] , F_261 ( V_507 ) ) ;
return;
}
V_24 -> V_88 [ V_87 ] = V_507 ;
if ( ! V_532 ) {
F_262 ( & V_533 ) ;
V_532 = true ;
}
if ( V_24 -> V_45 & V_303 )
V_86 [ V_87 ] . F_263 ( V_507 , V_534 ) ;
}
static void F_264 ( struct V_1 * V_24 )
{
unsigned int V_105 ;
F_247 ( & V_494 ) ;
F_265 ( & V_24 -> V_535 , & V_536 ) ;
for ( V_105 = 0 ; V_105 < V_537 ; V_105 ++ )
if ( V_86 [ V_105 ] . F_258 )
F_255 ( V_24 , V_105 ) ;
F_249 ( & V_494 ) ;
}
static void F_266 ( struct V_1 * V_24 )
{
unsigned int V_105 ;
F_247 ( & V_494 ) ;
F_267 ( & V_24 -> V_535 ) ;
for ( V_105 = 0 ; V_105 < V_537 ; V_105 ++ )
if ( V_24 -> V_88 [ V_105 ] ) {
V_86 [ V_105 ] . F_263 ( V_24 -> V_88 [ V_105 ] ,
V_538 ) ;
V_24 -> V_88 [ V_105 ] = NULL ;
}
if ( V_532 && F_268 ( & V_536 ) ) {
F_269 ( & V_533 ) ;
V_532 = false ;
}
F_249 ( & V_494 ) ;
}
static void F_270 ( struct V_1 * V_24 , enum V_539 V_540 )
{
unsigned int V_105 ;
F_247 ( & V_494 ) ;
for ( V_105 = 0 ; V_105 < V_537 ; V_105 ++ )
if ( V_24 -> V_88 [ V_105 ] )
V_86 [ V_105 ] . F_263 ( V_24 -> V_88 [ V_105 ] , V_540 ) ;
F_249 ( & V_494 ) ;
}
int F_271 ( enum V_541 type , const struct V_542 * V_15 )
{
int V_34 = 0 ;
struct V_1 * V_24 ;
if ( type >= V_537 )
return - V_166 ;
F_247 ( & V_494 ) ;
if ( V_86 [ type ] . F_258 ) {
V_34 = - V_304 ;
goto V_167;
}
V_86 [ type ] = * V_15 ;
F_272 (adap, &adapter_list, list_node)
F_255 ( V_24 , type ) ;
V_167: F_249 ( & V_494 ) ;
return V_34 ;
}
int F_273 ( enum V_541 type )
{
struct V_1 * V_24 ;
if ( type >= V_537 )
return - V_166 ;
F_247 ( & V_494 ) ;
F_272 (adap, &adapter_list, list_node)
V_24 -> V_88 [ type ] = NULL ;
V_86 [ type ] . F_258 = NULL ;
F_249 ( & V_494 ) ;
return 0 ;
}
static int F_274 ( struct V_1 * V_24 )
{
int V_114 ;
V_114 = F_68 ( V_24 ) ;
if ( V_114 )
goto V_167;
V_114 = F_58 ( V_24 ) ;
if ( V_114 )
goto V_543;
if ( V_24 -> V_45 & V_95 ) {
F_45 ( V_24 ) ;
V_114 = F_50 ( V_24 -> V_109 [ 0 ] . V_119 , F_40 , 0 ,
V_24 -> V_109 [ 0 ] . V_110 , V_24 ) ;
if ( V_114 )
goto V_544;
V_114 = F_49 ( V_24 ) ;
if ( V_114 ) {
F_52 ( V_24 -> V_109 [ 0 ] . V_119 , V_24 ) ;
goto V_544;
}
} else {
V_114 = F_50 ( V_24 -> V_96 -> V_98 , F_275 ( V_24 ) ,
( V_24 -> V_45 & V_97 ) ? 0 : V_545 ,
V_24 -> V_23 [ 0 ] -> V_111 , V_24 ) ;
if ( V_114 )
goto V_544;
}
F_64 ( V_24 ) ;
F_276 ( V_24 ) ;
F_277 ( V_24 ) ;
V_24 -> V_45 |= V_303 ;
F_270 ( V_24 , V_534 ) ;
V_167:
return V_114 ;
V_544:
F_34 ( V_24 -> V_82 , L_39 , V_114 ) ;
V_543:
F_71 ( V_24 ) ;
goto V_167;
}
static void F_278 ( struct V_1 * V_1 )
{
F_279 ( V_1 ) ;
F_280 ( & V_1 -> V_434 ) ;
F_280 ( & V_1 -> V_496 ) ;
F_280 ( & V_1 -> V_503 ) ;
V_1 -> V_432 = false ;
V_1 -> V_431 = NULL ;
if ( V_1 -> V_45 & V_95 ) {
F_53 ( V_1 ) ;
F_52 ( V_1 -> V_109 [ 0 ] . V_119 , V_1 ) ;
} else
F_52 ( V_1 -> V_96 -> V_98 , V_1 ) ;
F_62 ( V_1 ) ;
F_281 ( V_1 ) ;
F_71 ( V_1 ) ;
V_1 -> V_45 &= ~ V_303 ;
}
static int F_282 ( struct V_10 * V_11 )
{
int V_114 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_9 ( V_11 ) ;
if ( ! ( V_1 -> V_45 & V_303 ) ) {
V_114 = F_274 ( V_1 ) ;
if ( V_114 < 0 )
return V_114 ;
}
V_114 = F_21 ( V_11 ) ;
if ( ! V_114 )
F_283 ( V_11 ) ;
return V_114 ;
}
static int F_284 ( struct V_10 * V_11 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_285 ( V_11 ) ;
F_9 ( V_11 ) ;
return F_24 ( V_1 , V_1 -> V_41 , V_26 -> V_42 , false , false ) ;
}
static struct V_546 * F_286 ( struct V_10 * V_11 ,
struct V_546 * V_547 )
{
struct V_205 V_89 ;
struct V_14 * V_15 = F_5 ( V_11 ) ;
struct V_1 * V_1 = V_15 -> V_1 ;
F_211 ( & V_1 -> V_464 ) ;
F_106 ( V_1 , V_15 -> V_52 , & V_89 ) ;
F_213 ( & V_1 -> V_464 ) ;
V_547 -> V_548 = V_89 . V_549 ;
V_547 -> V_550 = V_89 . V_551 ;
V_547 -> V_552 = V_89 . V_553 ;
V_547 -> V_554 = V_89 . V_555 ;
V_547 -> V_556 = V_89 . V_557 ;
V_547 -> V_558 = V_89 . V_559 + V_89 . V_560 +
V_89 . V_561 ;
V_547 -> V_562 = 0 ;
V_547 -> V_563 = V_89 . V_564 ;
V_547 -> V_565 = V_89 . V_566 ;
V_547 -> V_567 = V_89 . V_568 + V_89 . V_569 +
V_89 . V_570 + V_89 . V_571 +
V_89 . V_572 + V_89 . V_573 +
V_89 . V_574 + V_89 . V_575 ;
V_547 -> V_576 = 0 ;
V_547 -> V_577 = 0 ;
V_547 -> V_578 = 0 ;
V_547 -> V_579 = 0 ;
V_547 -> V_580 = 0 ;
V_547 -> V_581 = 0 ;
V_547 -> V_582 = V_89 . V_583 ;
V_547 -> V_584 = V_89 . V_566 + V_89 . V_564 +
V_547 -> V_558 + V_89 . V_585 + V_547 -> V_567 ;
return V_547 ;
}
static int F_287 ( struct V_10 * V_11 , struct V_586 * V_425 , int V_252 )
{
unsigned int V_169 ;
int V_34 = 0 , V_587 , V_588 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_589 * V_79 = (struct V_589 * ) & V_425 -> V_590 ;
switch ( V_252 ) {
case V_591 :
if ( V_26 -> V_260 < 0 )
return - V_177 ;
V_79 -> V_592 = V_26 -> V_260 ;
break;
case V_593 :
case V_594 :
if ( F_288 ( V_79 -> V_592 ) ) {
V_587 = F_289 ( V_79 -> V_592 ) ;
V_588 = F_290 ( V_79 -> V_592 ) ;
} else if ( V_79 -> V_592 < 32 ) {
V_587 = V_79 -> V_592 ;
V_588 = 0 ;
V_79 -> V_595 &= 0x1f ;
} else
return - V_166 ;
V_169 = V_26 -> V_1 -> V_41 ;
if ( V_252 == V_593 )
V_34 = F_291 ( V_26 -> V_1 , V_169 , V_587 , V_588 ,
V_79 -> V_595 , & V_79 -> V_596 ) ;
else
V_34 = F_292 ( V_26 -> V_1 , V_169 , V_587 , V_588 ,
V_79 -> V_595 , V_79 -> V_597 ) ;
break;
default:
return - V_177 ;
}
return V_34 ;
}
static void F_293 ( struct V_10 * V_11 )
{
F_19 ( V_11 , - 1 , false ) ;
}
static int F_294 ( struct V_10 * V_11 , int V_598 )
{
int V_34 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( V_598 < 81 || V_598 > V_599 )
return - V_166 ;
V_34 = F_20 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 , V_598 , - 1 ,
- 1 , - 1 , - 1 , true ) ;
if ( ! V_34 )
V_11 -> V_43 = V_598 ;
return V_34 ;
}
static int F_295 ( struct V_10 * V_11 , void * V_15 )
{
int V_34 ;
struct V_600 * V_33 = V_15 ;
struct V_14 * V_26 = F_5 ( V_11 ) ;
if ( ! F_296 ( V_33 -> V_601 ) )
return - V_602 ;
V_34 = F_22 ( V_26 -> V_1 , V_26 -> V_1 -> V_41 , V_26 -> V_42 ,
V_26 -> V_50 , V_33 -> V_601 , true , true ) ;
if ( V_34 < 0 )
return V_34 ;
memcpy ( V_11 -> V_51 , V_33 -> V_601 , V_11 -> V_603 ) ;
V_26 -> V_50 = V_34 ;
return 0 ;
}
static void F_297 ( struct V_10 * V_11 )
{
struct V_14 * V_26 = F_5 ( V_11 ) ;
struct V_1 * V_24 = V_26 -> V_1 ;
if ( V_24 -> V_45 & V_95 ) {
int V_105 ;
struct V_128 * V_192 = & V_24 -> V_66 . V_122 [ V_26 -> V_129 ] ;
for ( V_105 = V_26 -> V_113 ; V_105 ; V_105 -- , V_192 ++ )
V_120 ( 0 , & V_192 -> V_85 ) ;
} else
F_275 ( V_24 ) ( 0 , V_24 ) ;
}
void F_298 ( struct V_1 * V_24 )
{
F_251 ( V_24 , V_604 , V_605 , 0 ) ;
F_279 ( V_24 ) ;
F_299 ( V_24 -> V_82 , L_40 ) ;
}
static void F_300 ( struct V_1 * V_24 )
{
T_6 V_606 ;
V_606 = F_301 ( V_24 -> V_96 , 0 ) ;
F_43 ( V_24 , F_302 ( V_607 , 0 ) ,
( V_606 + V_608 ) | F_303 ( 0 ) |
F_304 ( F_305 ( V_609 ) - 10 ) ) ;
F_43 ( V_24 , F_302 ( V_607 , 1 ) ,
( V_606 + V_610 ) | F_303 ( 0 ) |
F_304 ( F_305 ( V_611 ) - 10 ) ) ;
F_43 ( V_24 , F_302 ( V_607 , 2 ) ,
( V_606 + V_612 ) | F_303 ( 0 ) |
F_304 ( F_305 ( V_613 ) - 10 ) ) ;
}
static void F_306 ( struct V_1 * V_24 )
{
if ( V_24 -> V_512 . V_614 . V_170 ) {
unsigned int V_209 , V_615 ;
V_209 = F_301 ( V_24 -> V_96 , 2 ) +
F_307 ( V_24 -> V_96 , & V_24 -> V_512 ) ;
V_615 = F_308 ( V_24 -> V_512 . V_614 . V_170 ) >> 10 ;
F_43 ( V_24 ,
F_302 ( V_607 , 3 ) ,
V_209 | F_303 ( 1 ) | F_304 ( F_305 ( V_615 ) ) ) ;
F_43 ( V_24 ,
F_302 ( V_616 , 3 ) ,
V_24 -> V_512 . V_614 . V_209 ) ;
F_41 ( V_24 ,
F_302 ( V_616 , 3 ) ) ;
}
}
static int F_309 ( struct V_1 * V_24 , struct V_617 * V_321 )
{
T_6 V_100 ;
int V_34 ;
memset ( V_321 , 0 , sizeof( * V_321 ) ) ;
V_321 -> V_618 = F_182 ( F_310 ( V_619 ) |
V_620 | V_621 ) ;
V_321 -> V_622 = F_182 ( F_311 ( * V_321 ) ) ;
V_34 = F_312 ( V_24 , V_24 -> V_41 , V_321 , sizeof( * V_321 ) , V_321 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_321 -> V_623 & F_197 ( V_624 ) ) {
if ( ! V_625 )
V_321 -> V_623 ^= F_197 ( V_624 ) ;
else
V_321 -> V_623 = F_197 ( V_624 ) ;
} else if ( V_625 ) {
F_34 ( V_24 -> V_82 , L_41 ) ;
return V_34 ;
}
V_321 -> V_618 = F_182 ( F_310 ( V_619 ) |
V_620 | V_626 ) ;
V_34 = F_312 ( V_24 , V_24 -> V_41 , V_321 , sizeof( * V_321 ) , NULL ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_313 ( V_24 , V_24 -> V_41 ,
V_627 ,
V_628 |
V_629 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_314 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , 0 , V_143 , 64 , V_630 ,
0 , 0 , 4 , 0xf , 0xf , 16 , V_631 , V_631 ) ;
if ( V_34 < 0 )
return V_34 ;
F_315 ( V_24 ) ;
F_43 ( V_24 , V_632 , 0x64f8849 ) ;
F_43 ( V_24 , V_633 , F_215 ( V_634 - 12 ) ) ;
F_43 ( V_24 , V_635 , V_636 ) ;
V_100 = F_41 ( V_24 , V_637 ) ;
F_43 ( V_24 , V_637 , V_100 & ~ V_638 ) ;
return F_316 ( V_24 , V_24 -> V_41 ) ;
}
static int F_317 ( struct V_1 * V_1 )
{
F_318 ( V_1 , V_639 , V_640 ) ;
if ( V_641 != 2 && V_641 != 0 ) {
F_34 ( & V_1 -> V_96 -> V_11 ,
L_42 ,
V_641 ) ;
V_641 = 2 ;
}
F_251 ( V_1 , V_604 ,
V_642 ,
F_319 ( V_641 ) ) ;
F_320 ( V_1 , V_636 ,
V_638 , 0 ) ;
return 0 ;
}
static int F_321 ( struct V_1 * V_1 , int V_643 )
{
struct V_617 V_644 ;
const struct V_160 * V_645 ;
unsigned long V_646 = 0 , V_647 = 0 ;
T_6 V_648 , V_649 , V_650 ;
int V_34 , V_651 ;
if ( V_643 ) {
V_34 = F_322 ( V_1 , V_1 -> V_169 ,
V_652 | V_653 ) ;
if ( V_34 < 0 )
goto V_654;
}
V_34 = F_79 ( & V_645 , V_655 , V_1 -> V_82 ) ;
if ( V_34 < 0 ) {
V_651 = 1 ;
V_646 = V_656 ;
V_647 = F_323 ( V_1 ) ;
} else {
T_6 V_7 [ 7 ] , V_173 [ 7 ] ;
V_651 = 0 ;
if ( V_645 -> V_170 >= V_657 )
V_34 = - V_132 ;
else {
V_7 [ 0 ] = ( F_129 ( V_658 ) |
F_130 ( V_659 ) ) ;
V_34 = F_324 ( V_1 , V_1 -> V_169 ,
V_1 -> V_41 , 0 , 1 , V_7 , V_173 ) ;
if ( V_34 == 0 ) {
T_7 V_660 = V_645 -> V_170 & 0x3 ;
T_7 V_170 = V_645 -> V_170 & ~ 0x3 ;
T_12 * V_79 = ( T_12 * ) V_645 -> V_79 ;
V_646 = F_325 ( V_173 [ 0 ] ) ;
V_647 = F_326 ( V_173 [ 0 ] ) << 16 ;
V_34 = F_327 ( V_1 , V_646 , V_647 ,
V_170 , V_79 ) ;
if ( V_34 == 0 && V_660 != 0 ) {
union {
T_12 V_661 ;
char V_208 [ 4 ] ;
} V_662 ;
int V_105 ;
V_662 . V_661 = V_79 [ V_170 >> 2 ] ;
for ( V_105 = V_660 ; V_105 < 4 ; V_105 ++ )
V_662 . V_208 [ V_105 ] = 0 ;
V_34 = F_327 ( V_1 , V_646 ,
V_647 + V_170 ,
4 , & V_662 . V_661 ) ;
}
}
}
F_86 ( V_645 ) ;
if ( V_34 )
goto V_654;
}
memset ( & V_644 , 0 , sizeof( V_644 ) ) ;
V_644 . V_618 =
F_182 ( F_310 ( V_619 ) |
V_620 |
V_621 ) ;
V_644 . V_622 =
F_182 ( V_663 |
F_328 ( V_646 ) |
F_329 ( V_647 >> 16 ) |
F_311 ( V_644 ) ) ;
V_34 = F_312 ( V_1 , V_1 -> V_169 , & V_644 , sizeof( V_644 ) ,
& V_644 ) ;
if ( V_34 < 0 )
goto V_654;
V_648 = F_28 ( V_644 . V_648 ) ;
V_649 = F_28 ( V_644 . V_649 ) ;
V_650 = F_28 ( V_644 . V_650 ) ;
if ( V_649 != V_650 )
F_260 ( V_1 -> V_82 , L_43\
L_44 ,
V_649 , V_650 ) ;
V_644 . V_618 =
F_182 ( F_310 ( V_619 ) |
V_620 |
V_626 ) ;
V_644 . V_622 = F_182 ( F_311 ( V_644 ) ) ;
V_34 = F_312 ( V_1 , V_1 -> V_169 , & V_644 , sizeof( V_644 ) ,
NULL ) ;
if ( V_34 < 0 )
goto V_654;
V_34 = F_317 ( V_1 ) ;
if ( V_34 < 0 )
goto V_654;
V_34 = F_330 ( V_1 , V_1 -> V_169 ) ;
if ( V_34 < 0 )
goto V_654;
V_1 -> V_45 |= V_664 ;
F_81 ( V_1 -> V_82 , L_45\
L_46 ,
( V_651
? L_47
: L_48 V_655 ) ,
V_648 , V_650 ) ;
return 0 ;
V_654:
if ( V_34 != - V_665 )
F_260 ( V_1 -> V_82 , L_49 ,
- V_34 ) ;
return V_34 ;
}
static int F_331 ( struct V_1 * V_1 , int V_643 )
{
struct V_66 * V_13 = & V_1 -> V_66 ;
struct V_617 V_644 ;
T_6 V_100 ;
int V_105 , V_34 ;
if ( V_643 ) {
V_34 = F_322 ( V_1 , V_1 -> V_169 ,
V_652 | V_653 ) ;
if ( V_34 < 0 )
goto V_654;
}
memset ( & V_644 , 0 , sizeof( V_644 ) ) ;
V_644 . V_618 = F_182 ( F_310 ( V_619 ) |
V_620 | V_621 ) ;
V_644 . V_622 = F_182 ( F_311 ( V_644 ) ) ;
V_34 = F_312 ( V_1 , V_1 -> V_169 , & V_644 , sizeof( V_644 ) ,
& V_644 ) ;
if ( V_34 < 0 )
goto V_654;
if ( V_644 . V_623 & F_197 ( V_624 ) ) {
if ( ! V_625 )
V_644 . V_623 ^= F_197 ( V_624 ) ;
else
V_644 . V_623 = F_197 ( V_624 ) ;
} else if ( V_625 ) {
F_34 ( V_1 -> V_82 , L_41 ) ;
goto V_654;
}
V_644 . V_618 = F_182 ( F_310 ( V_619 ) |
V_620 | V_626 ) ;
V_34 = F_312 ( V_1 , V_1 -> V_169 , & V_644 , sizeof( V_644 ) ,
NULL ) ;
if ( V_34 < 0 )
goto V_654;
V_34 = F_317 ( V_1 ) ;
if ( V_34 < 0 )
goto V_654;
V_1 -> V_45 |= V_666 ;
V_34 = F_313 ( V_1 , V_1 -> V_169 ,
V_627 ,
V_628 |
V_667 |
( ( V_1 -> V_45 & V_666 ) ?
V_629 : 0 ) ) ;
if ( V_34 < 0 )
goto V_654;
V_34 = F_314 ( V_1 , V_1 -> V_169 , V_1 -> V_41 , 0 ,
V_668 , V_669 ,
V_670 , V_671 ,
V_672 , V_673 ,
V_674 ,
F_1 ( V_1 , V_1 -> V_41 , 0 ) ,
V_675 ,
V_676 , V_677 ) ;
if ( V_34 < 0 )
goto V_654;
for ( V_105 = 0 ; V_105 < V_312 - 1 ; V_105 ++ )
V_13 -> V_309 [ V_105 ] = F_159 ( V_678 [ V_105 ] , V_679 ) ;
V_13 -> V_309 [ V_312 - 1 ] = V_679 ;
V_13 -> V_311 [ 0 ] = 1 ;
for ( V_105 = 1 ; V_105 < V_680 ; V_105 ++ )
V_13 -> V_311 [ V_105 ] = F_159 ( V_681 [ V_105 - 1 ] ,
F_332 ( V_682 ) ) ;
F_315 ( V_1 ) ;
#ifdef F_333
{
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < F_11 ( V_683 ) ; V_2 ++ ) {
if ( V_683 [ V_2 ] <= 0 )
continue;
for ( V_3 = 1 ; V_3 <= V_683 [ V_2 ] ; V_3 ++ ) {
V_34 = F_314 ( V_1 , V_1 -> V_169 ,
V_2 , V_3 ,
V_684 , V_685 ,
V_686 , V_687 ,
V_688 , V_689 ,
F_334 (
V_674 ) ,
F_1 (
V_1 , V_2 , V_3 ) ,
V_690 ,
V_691 , V_692 ) ;
if ( V_34 < 0 )
F_260 ( V_1 -> V_82 ,
L_50\
L_51
L_52 , V_2 , V_3 , V_34 ) ;
}
}
}
#endif
if ( V_693 != V_694 ) {
int V_106 , V_695 = 0 ;
for ( V_106 = V_696 ; V_106 <= V_697 ; V_106 ++ )
switch ( V_693 & ( 1 << V_106 ) ) {
case 0 :
break;
case V_698 :
V_695 += 1 ;
break;
case V_699 :
V_695 += 3 ;
break;
case V_700 :
V_695 += 17 ;
break;
case V_701 :
V_695 += 17 ;
break;
case V_702 :
V_695 += 8 ;
break;
case V_703 :
V_695 += 8 ;
break;
case V_704 :
V_695 += 16 ;
break;
case V_705 :
V_695 += 9 ;
break;
case V_706 :
V_695 += 3 ;
break;
case V_707 :
V_695 += 1 ;
break;
}
if ( V_695 > 36 ) {
F_34 ( V_1 -> V_82 ,
L_53\
L_54 , V_693 , V_695 ,
V_694 ) ;
V_693 = V_694 ;
}
}
V_100 = V_693 ;
F_335 ( V_1 , V_635 , V_637 ,
& V_100 , 1 , V_708 ) ;
if ( V_693 )
F_251 ( V_1 , V_709 ,
V_710 ,
V_710 ) ;
F_43 ( V_1 , V_632 , F_336 ( 6 ) |
F_337 ( 4 ) | F_338 ( 15 ) |
F_339 ( 8 ) | F_340 ( 8 ) |
F_341 ( 4 ) | F_342 ( 9 ) ) ;
V_34 = F_330 ( V_1 , V_1 -> V_169 ) ;
if ( V_34 < 0 )
goto V_654;
F_81 ( V_1 -> V_82 , L_55\
L_56 ) ;
return 0 ;
V_654:
return V_34 ;
}
static int F_343 ( struct V_1 * V_24 )
{
int V_34 ;
T_6 V_100 , V_711 ;
enum V_712 V_218 ;
T_6 V_7 [ 7 ] , V_173 [ 7 ] ;
struct V_617 V_644 ;
int V_643 = 1 , V_106 ;
V_34 = F_344 ( V_24 , V_24 -> V_169 , V_24 -> V_41 ,
V_713 ? V_714 : V_715 ,
& V_218 ) ;
if ( V_34 < 0 ) {
F_34 ( V_24 -> V_82 , L_57 ,
V_34 ) ;
return V_34 ;
}
if ( V_34 == V_24 -> V_169 )
V_24 -> V_45 |= V_716 ;
if ( V_713 && V_218 == V_717 )
V_218 = V_718 ;
V_34 = F_345 ( V_24 ) ;
if ( ( V_24 -> V_45 & V_716 ) && V_218 != V_717 ) {
if ( V_34 == - V_166 || V_34 > 0 ) {
if ( F_78 ( V_24 ) >= 0 ) {
V_643 = 0 ;
V_34 = F_345 ( V_24 ) ;
}
}
if ( V_34 < 0 )
return V_34 ;
}
V_34 = F_346 ( V_24 , & V_24 -> V_7 . V_719 ) ;
if ( V_34 < 0 )
goto V_654;
V_100 =
F_129 ( V_658 ) |
F_130 ( V_720 ) ;
V_34 = F_324 ( V_24 , V_24 -> V_169 , V_24 -> V_41 , 0 , 1 , & V_100 , & V_711 ) ;
if ( V_34 < 0 )
goto V_654;
V_24 -> V_7 . V_8 = F_347 ( V_711 ) ;
V_24 -> V_7 . V_5 = V_711 ;
if ( V_218 == V_717 ) {
F_81 ( V_24 -> V_82 , L_58\
L_59 ,
V_24 -> V_45 & V_716 ? L_60 : L_61 ) ;
V_24 -> V_45 |= V_664 ;
} else {
F_81 ( V_24 -> V_82 , L_62\
L_63 ) ;
if ( V_34 < 0 )
F_260 ( V_24 -> V_82 , L_64
L_65 ) ;
if ( V_721 )
V_34 = F_331 ( V_24 , V_643 ) ;
else {
V_7 [ 0 ] = ( F_129 ( V_658 ) |
F_130 ( V_659 ) ) ;
V_34 = F_324 ( V_24 , V_24 -> V_169 , V_24 -> V_41 , 0 , 1 ,
V_7 , V_173 ) ;
if ( V_34 < 0 )
V_34 = F_331 ( V_24 , V_643 ) ;
else {
V_34 = F_321 ( V_24 , V_643 ) ;
if ( V_34 == - V_665 ) {
F_81 ( V_24 -> V_82 ,
L_66
L_67
L_68 ) ;
V_34 = F_331 ( V_24 , V_643 ) ;
}
}
}
if ( V_34 < 0 ) {
F_34 ( V_24 -> V_82 ,
L_69 ,
- V_34 ) ;
goto V_654;
}
}
if ( V_24 -> V_45 & V_664 ) {
V_34 = F_315 ( V_24 ) ;
if ( V_34 < 0 )
goto V_654;
}
if ( F_348 ( V_24 -> V_96 -> V_162 ) )
V_24 -> V_7 . V_722 = 1 ;
#define F_349 ( T_15 ) \
(FW_PARAMS_MNEM(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X(FW_PARAMS_PARAM_DEV_##param))
#define F_350 ( T_15 ) \
FW_PARAMS_MNEM(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y(0) | \
FW_PARAMS_PARAM_Z(0)
V_7 [ 0 ] = F_350 ( V_723 ) ;
V_7 [ 1 ] = F_350 ( V_724 ) ;
V_7 [ 2 ] = F_350 ( V_725 ) ;
V_7 [ 3 ] = F_350 ( V_726 ) ;
V_7 [ 4 ] = F_350 ( V_727 ) ;
V_7 [ 5 ] = F_350 ( V_728 ) ;
V_34 = F_324 ( V_24 , V_24 -> V_169 , V_24 -> V_41 , 0 , 6 , V_7 , V_173 ) ;
if ( V_34 < 0 )
goto V_654;
V_24 -> V_66 . V_68 = V_173 [ 0 ] ;
V_24 -> V_729 = V_173 [ 1 ] ;
V_24 -> V_730 = V_173 [ 2 ] ;
V_24 -> V_429 . V_731 = V_173 [ 3 ] ;
V_24 -> V_429 . V_732 = V_173 [ 4 ] - V_173 [ 3 ] + 1 ;
V_24 -> V_66 . V_134 = V_173 [ 5 ] ;
V_7 [ 0 ] = F_350 ( V_733 ) ;
V_7 [ 1 ] = F_350 ( V_734 ) ;
V_34 = F_324 ( V_24 , V_24 -> V_169 , V_24 -> V_41 , 0 , 2 , V_7 , V_173 ) ;
if ( ( V_173 [ 0 ] != V_173 [ 1 ] ) && ( V_34 >= 0 ) ) {
V_24 -> V_45 |= V_735 ;
V_24 -> V_429 . V_736 = V_173 [ 0 ] ;
V_24 -> V_429 . V_737 = V_173 [ 1 ] ;
}
memset ( & V_644 , 0 , sizeof( V_644 ) ) ;
V_644 . V_618 = F_182 ( F_310 ( V_619 ) |
V_620 | V_621 ) ;
V_644 . V_622 = F_182 ( F_311 ( V_644 ) ) ;
V_34 = F_312 ( V_24 , V_24 -> V_169 , & V_644 , sizeof( V_644 ) ,
& V_644 ) ;
if ( V_34 < 0 )
goto V_654;
if ( V_644 . V_738 ) {
V_7 [ 0 ] = F_349 ( V_739 ) ;
V_7 [ 1 ] = F_350 ( V_740 ) ;
V_7 [ 2 ] = F_350 ( V_741 ) ;
V_7 [ 3 ] = F_350 ( V_742 ) ;
V_7 [ 4 ] = F_350 ( V_743 ) ;
V_7 [ 5 ] = F_349 ( V_744 ) ;
V_34 = F_324 ( V_24 , V_24 -> V_169 , V_24 -> V_41 , 0 , 6 ,
V_7 , V_173 ) ;
if ( V_34 < 0 )
goto V_654;
V_24 -> V_429 . V_441 = V_173 [ 0 ] ;
V_24 -> V_429 . V_440 = F_159 ( V_24 -> V_429 . V_441 / 2 , V_745 ) ;
V_24 -> V_429 . V_418 = V_173 [ 1 ] ;
V_24 -> V_429 . V_416 = V_173 [ 2 ] - V_173 [ 1 ] + 1 ;
if ( V_24 -> V_45 & V_735 && ! F_351 ( V_24 ) ) {
V_24 -> V_429 . V_746 = V_24 -> V_429 . V_731 +
F_352 ( V_24 -> V_429 . V_732 , 3 ) ;
V_24 -> V_429 . V_747 = V_24 -> V_429 . V_732 -
F_352 ( V_24 -> V_429 . V_732 , 3 ) ;
V_24 -> V_429 . V_732 = V_24 -> V_429 . V_746 -
V_24 -> V_429 . V_731 ;
}
V_24 -> V_512 . V_748 . V_209 = V_173 [ 3 ] ;
V_24 -> V_512 . V_748 . V_170 = V_173 [ 4 ] - V_173 [ 3 ] + 1 ;
V_24 -> V_7 . V_520 = V_173 [ 5 ] ;
V_24 -> V_7 . V_171 = 1 ;
}
if ( V_644 . V_749 ) {
V_7 [ 0 ] = F_350 ( V_750 ) ;
V_7 [ 1 ] = F_350 ( V_751 ) ;
V_7 [ 2 ] = F_350 ( V_752 ) ;
V_7 [ 3 ] = F_350 ( V_753 ) ;
V_7 [ 4 ] = F_350 ( V_754 ) ;
V_7 [ 5 ] = F_350 ( V_755 ) ;
V_34 = F_324 ( V_24 , V_24 -> V_169 , V_24 -> V_41 , 0 , 6 ,
V_7 , V_173 ) ;
if ( V_34 < 0 )
goto V_654;
V_24 -> V_512 . V_756 . V_209 = V_173 [ 0 ] ;
V_24 -> V_512 . V_756 . V_170 = V_173 [ 1 ] - V_173 [ 0 ] + 1 ;
V_24 -> V_512 . V_324 . V_209 = V_173 [ 2 ] ;
V_24 -> V_512 . V_324 . V_170 = V_173 [ 3 ] - V_173 [ 2 ] + 1 ;
V_24 -> V_512 . V_757 . V_209 = V_173 [ 4 ] ;
V_24 -> V_512 . V_757 . V_170 = V_173 [ 5 ] - V_173 [ 4 ] + 1 ;
V_7 [ 0 ] = F_350 ( V_758 ) ;
V_7 [ 1 ] = F_350 ( V_759 ) ;
V_7 [ 2 ] = F_350 ( V_760 ) ;
V_7 [ 3 ] = F_350 ( V_761 ) ;
V_7 [ 4 ] = F_350 ( V_762 ) ;
V_7 [ 5 ] = F_350 ( V_763 ) ;
V_34 = F_324 ( V_24 , 0 , 0 , 0 , 6 , V_7 , V_173 ) ;
if ( V_34 < 0 )
goto V_654;
V_24 -> V_512 . V_764 . V_209 = V_173 [ 0 ] ;
V_24 -> V_512 . V_764 . V_170 = V_173 [ 1 ] - V_173 [ 0 ] + 1 ;
V_24 -> V_512 . V_765 . V_209 = V_173 [ 2 ] ;
V_24 -> V_512 . V_765 . V_170 = V_173 [ 3 ] - V_173 [ 2 ] + 1 ;
V_24 -> V_512 . V_614 . V_209 = V_173 [ 4 ] ;
V_24 -> V_512 . V_614 . V_170 = V_173 [ 5 ] - V_173 [ 4 ] + 1 ;
}
if ( V_644 . V_766 ) {
V_7 [ 0 ] = F_350 ( V_767 ) ;
V_7 [ 1 ] = F_350 ( V_768 ) ;
V_34 = F_324 ( V_24 , V_24 -> V_169 , V_24 -> V_41 , 0 , 2 ,
V_7 , V_173 ) ;
if ( V_34 < 0 )
goto V_654;
V_24 -> V_512 . V_769 . V_209 = V_173 [ 0 ] ;
V_24 -> V_512 . V_769 . V_170 = V_173 [ 1 ] - V_173 [ 0 ] + 1 ;
}
#undef F_350
#undef F_349
V_100 = F_41 ( V_24 , V_770 ) ;
V_24 -> V_7 . V_771 . V_772 = F_353 ( V_100 ) ;
V_24 -> V_7 . V_771 . V_773 = F_354 ( V_100 ) ;
F_355 ( V_24 , V_24 -> V_7 . V_456 , NULL ) ;
F_356 ( V_24 , V_24 -> V_7 . V_456 , V_24 -> V_7 . V_774 ,
V_24 -> V_7 . V_775 ) ;
for ( V_106 = 0 ; V_106 < V_776 ; V_106 ++ )
V_24 -> V_7 . V_771 . V_777 [ V_106 ] = V_106 ;
V_24 -> V_45 |= V_778 ;
return 0 ;
V_654:
if ( V_34 != - V_779 && V_34 != - V_780 )
F_357 ( V_24 , V_24 -> V_169 ) ;
return V_34 ;
}
static T_16 F_358 ( struct V_460 * V_96 ,
T_17 V_218 )
{
int V_105 ;
struct V_1 * V_24 = F_210 ( V_96 ) ;
if ( ! V_24 )
goto V_167;
F_359 () ;
V_24 -> V_45 &= ~ V_778 ;
F_270 ( V_24 , V_781 ) ;
F_46 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_105 ] ;
F_360 ( V_11 ) ;
F_9 ( V_11 ) ;
}
if ( V_24 -> V_45 & V_303 )
F_278 ( V_24 ) ;
F_361 () ;
F_362 ( V_96 ) ;
V_167: return V_218 == V_782 ?
V_783 : V_784 ;
}
static T_16 F_363 ( struct V_460 * V_96 )
{
int V_105 , V_34 ;
struct V_617 V_321 ;
struct V_1 * V_24 = F_210 ( V_96 ) ;
if ( ! V_24 ) {
F_364 ( V_96 ) ;
F_365 ( V_96 ) ;
return V_785 ;
}
if ( F_366 ( V_96 ) ) {
F_34 ( & V_96 -> V_11 , L_70 ) ;
return V_783 ;
}
F_367 ( V_96 ) ;
F_364 ( V_96 ) ;
F_365 ( V_96 ) ;
F_368 ( V_96 ) ;
if ( F_369 ( V_24 ) < 0 )
return V_783 ;
if ( F_344 ( V_24 , V_24 -> V_41 , V_24 -> V_41 , V_714 , NULL ) )
return V_783 ;
V_24 -> V_45 |= V_778 ;
if ( F_309 ( V_24 , & V_321 ) )
return V_783 ;
F_46 (adap, i) {
struct V_14 * V_15 = F_59 ( V_24 , V_105 ) ;
V_34 = F_370 ( V_24 , V_24 -> V_41 , V_15 -> V_52 , V_24 -> V_41 , 0 , 1 ,
NULL , NULL ) ;
if ( V_34 < 0 )
return V_783 ;
V_15 -> V_42 = V_34 ;
V_15 -> V_50 = - 1 ;
}
F_356 ( V_24 , V_24 -> V_7 . V_456 , V_24 -> V_7 . V_774 ,
V_24 -> V_7 . V_775 ) ;
F_300 ( V_24 ) ;
if ( F_274 ( V_24 ) )
return V_783 ;
return V_785 ;
}
static void F_371 ( struct V_460 * V_96 )
{
int V_105 ;
struct V_1 * V_24 = F_210 ( V_96 ) ;
if ( ! V_24 )
return;
F_359 () ;
F_46 (adap, i) {
struct V_10 * V_11 = V_24 -> V_23 [ V_105 ] ;
if ( F_7 ( V_11 ) ) {
F_21 ( V_11 ) ;
F_293 ( V_11 ) ;
}
F_372 ( V_11 ) ;
}
F_361 () ;
}
static inline bool F_373 ( const struct V_275 * V_276 )
{
return ( V_276 -> V_268 & V_230 ) != 0 ;
}
static inline void F_374 ( struct V_53 * V_54 , T_3 V_786 , T_3 V_787 ,
unsigned int V_170 , unsigned int V_788 )
{
V_54 -> V_140 = F_133 ( V_786 ) |
( V_787 < V_680 ? V_319 : 0 ) ;
V_54 -> V_316 = V_787 < V_680 ? V_787 : 0 ;
V_54 -> V_789 = V_788 ;
V_54 -> V_170 = V_170 ;
}
static void T_13 F_375 ( struct V_1 * V_24 )
{
struct V_66 * V_13 = & V_24 -> V_66 ;
int V_105 , V_790 = 0 , V_791 = 0 , V_792 = 0 ;
F_46 (adap, i)
V_791 += F_373 ( & F_59 ( V_24 , V_105 ) -> V_16 ) ;
if ( V_791 )
V_790 = ( V_793 - ( V_24 -> V_7 . V_8 - V_791 ) ) / V_791 ;
if ( V_790 > F_376 () )
V_790 = F_376 () ;
F_46 (adap, i) {
struct V_14 * V_26 = F_59 ( V_24 , V_105 ) ;
V_26 -> V_129 = V_792 ;
V_26 -> V_113 = F_373 ( & V_26 -> V_16 ) ? V_790 : 1 ;
V_792 += V_26 -> V_113 ;
}
V_13 -> V_794 = V_792 ;
V_13 -> V_795 = V_792 ;
if ( F_93 ( V_24 ) ) {
if ( V_791 ) {
V_105 = F_377 ( int , F_11 ( V_13 -> V_124 ) ,
F_378 () ) ;
V_13 -> V_152 = F_379 ( V_105 , V_24 -> V_7 . V_8 ) ;
} else
V_13 -> V_152 = V_24 -> V_7 . V_8 ;
V_13 -> V_515 = V_24 -> V_7 . V_8 ;
}
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_122 ) ; V_105 ++ ) {
struct V_128 * V_796 = & V_13 -> V_122 [ V_105 ] ;
F_374 ( & V_796 -> V_85 , 0 , 0 , 1024 , 64 ) ;
V_796 -> V_149 . V_170 = 72 ;
}
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_148 ) ; V_105 ++ )
V_13 -> V_148 [ V_105 ] . V_54 . V_170 = 1024 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_155 ) ; V_105 ++ )
V_13 -> V_155 [ V_105 ] . V_54 . V_170 = 512 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_70 ) ; V_105 ++ )
V_13 -> V_70 [ V_105 ] . V_54 . V_170 = 1024 ;
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_124 ) ; V_105 ++ ) {
struct V_83 * V_796 = & V_13 -> V_124 [ V_105 ] ;
F_374 ( & V_796 -> V_85 , 0 , 0 , 1024 , 64 ) ;
V_796 -> V_85 . V_87 = V_516 ;
V_796 -> V_149 . V_170 = 72 ;
}
for ( V_105 = 0 ; V_105 < F_11 ( V_13 -> V_125 ) ; V_105 ++ ) {
struct V_83 * V_796 = & V_13 -> V_125 [ V_105 ] ;
F_374 ( & V_796 -> V_85 , 0 , 0 , 511 , 64 ) ;
V_796 -> V_85 . V_87 = V_495 ;
V_796 -> V_149 . V_170 = 72 ;
}
F_374 ( & V_13 -> V_121 , 6 , 0 , 512 , 64 ) ;
F_374 ( & V_13 -> V_145 , 6 , 0 , 2 * V_630 , 64 ) ;
}
static void T_13 F_380 ( struct V_1 * V_24 , int V_108 )
{
int V_105 ;
struct V_14 * V_26 ;
while ( V_108 < V_24 -> V_66 . V_794 )
F_46 (adap, i) {
V_26 = F_59 ( V_24 , V_105 ) ;
if ( V_26 -> V_113 > 1 ) {
V_26 -> V_113 -- ;
V_24 -> V_66 . V_794 -- ;
if ( V_24 -> V_66 . V_794 <= V_108 )
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
static int T_13 F_381 ( struct V_1 * V_24 )
{
int V_797 = 0 ;
int V_105 , V_114 , V_798 , V_799 ;
struct V_66 * V_13 = & V_24 -> V_66 ;
unsigned int V_518 = V_24 -> V_7 . V_8 ;
struct V_800 V_801 [ V_630 + 1 ] ;
for ( V_105 = 0 ; V_105 < F_11 ( V_801 ) ; ++ V_105 )
V_801 [ V_105 ] . V_802 = V_105 ;
V_798 = V_13 -> V_795 + V_803 ;
if ( F_93 ( V_24 ) ) {
V_798 += V_13 -> V_515 + V_13 -> V_152 ;
V_797 = 2 * V_518 ;
}
V_799 = V_24 -> V_7 . V_8 + V_803 + V_797 ;
while ( ( V_114 = F_382 ( V_24 -> V_96 , V_801 , V_798 ) ) >= V_799 )
V_798 = V_114 ;
if ( ! V_114 ) {
V_105 = V_798 - V_803 - V_797 ;
if ( V_105 < V_13 -> V_795 ) {
V_13 -> V_795 = V_105 ;
if ( V_105 < V_13 -> V_794 )
F_380 ( V_24 , V_105 ) ;
}
if ( F_93 ( V_24 ) ) {
V_105 = V_798 - V_803 - V_13 -> V_795 ;
V_105 -= V_797 - V_518 ;
V_13 -> V_152 = ( V_105 / V_518 ) * V_518 ;
}
for ( V_105 = 0 ; V_105 < V_798 ; ++ V_105 )
V_24 -> V_109 [ V_105 ] . V_119 = V_801 [ V_105 ] . V_804 ;
} else if ( V_114 > 0 )
F_81 ( V_24 -> V_82 ,
L_71 , V_114 ) ;
return V_114 ;
}
static int T_13 F_383 ( struct V_1 * V_24 )
{
unsigned int V_105 , V_106 ;
F_46 (adap, i) {
struct V_14 * V_26 = F_59 ( V_24 , V_105 ) ;
V_26 -> V_127 = F_384 ( V_26 -> V_130 , sizeof( T_2 ) , V_131 ) ;
if ( ! V_26 -> V_127 )
return - V_132 ;
for ( V_106 = 0 ; V_106 < V_26 -> V_130 ; V_106 ++ )
V_26 -> V_127 [ V_106 ] = F_385 ( V_106 , V_26 -> V_113 ) ;
}
return 0 ;
}
static void T_13 F_386 ( const struct V_10 * V_11 )
{
static const char * V_805 [] = {
L_72 , L_73 , L_74 , L_75 , L_76 , L_77 , L_78 ,
L_79 , L_80 , L_81 , L_82 , L_83
} ;
char V_208 [ 80 ] ;
char * V_806 = V_208 ;
const char * V_807 = L_84 ;
const struct V_14 * V_26 = F_5 ( V_11 ) ;
const struct V_1 * V_24 = V_26 -> V_1 ;
if ( V_24 -> V_7 . V_808 . V_17 == V_809 )
V_807 = L_85 ;
else if ( V_24 -> V_7 . V_808 . V_17 == V_810 )
V_807 = L_86 ;
if ( V_26 -> V_16 . V_268 & V_226 )
V_806 += sprintf ( V_806 , L_87 ) ;
if ( V_26 -> V_16 . V_268 & V_228 )
V_806 += sprintf ( V_806 , L_88 ) ;
if ( V_26 -> V_16 . V_268 & V_230 )
V_806 += sprintf ( V_806 , L_89 ) ;
if ( V_806 != V_208 )
-- V_806 ;
sprintf ( V_806 , L_90 , V_805 [ V_26 -> V_253 ] ) ;
F_4 ( V_11 , L_91 ,
V_24 -> V_7 . V_719 . V_811 , V_24 -> V_7 . V_207 , V_208 ,
F_93 ( V_24 ) ? L_92 : L_84 , V_24 -> V_7 . V_808 . V_812 , V_807 ,
( V_24 -> V_45 & V_95 ) ? L_93 :
( V_24 -> V_45 & V_97 ) ? L_94 : L_84 ) ;
F_4 ( V_11 , L_95 ,
V_24 -> V_7 . V_719 . V_813 , V_24 -> V_7 . V_719 . V_814 ) ;
}
static void T_13 F_387 ( struct V_460 * V_11 )
{
F_388 ( V_11 , V_815 , V_816 ) ;
}
static void F_389 ( struct V_1 * V_1 )
{
unsigned int V_105 ;
F_90 ( V_1 -> V_401 ) ;
F_90 ( V_1 -> V_429 . V_428 ) ;
F_37 ( V_1 ) ;
F_46 (adapter, i)
if ( V_1 -> V_23 [ V_105 ] ) {
F_57 ( F_59 ( V_1 , V_105 ) -> V_127 ) ;
F_390 ( V_1 -> V_23 [ V_105 ] ) ;
}
if ( V_1 -> V_45 & V_778 )
F_357 ( V_1 , V_1 -> V_41 ) ;
}
static int T_13 F_391 ( struct V_460 * V_96 ,
const struct V_817 * V_818 )
{
int V_819 , V_105 , V_114 ;
struct V_14 * V_26 ;
bool V_820 = false ;
struct V_1 * V_1 = NULL ;
F_392 ( V_821 L_96 , V_822 , V_185 ) ;
V_114 = F_393 ( V_96 , V_183 ) ;
if ( V_114 ) {
F_81 ( & V_96 -> V_11 , L_97 ) ;
return V_114 ;
}
V_819 = F_394 ( V_96 -> V_823 ) ;
if ( V_819 != V_818 -> V_824 ) {
F_365 ( V_96 ) ;
goto V_825;
}
V_114 = F_366 ( V_96 ) ;
if ( V_114 ) {
F_34 ( & V_96 -> V_11 , L_98 ) ;
goto V_826;
}
if ( ! F_395 ( V_96 , F_396 ( 64 ) ) ) {
V_820 = true ;
V_114 = F_397 ( V_96 , F_396 ( 64 ) ) ;
if ( V_114 ) {
F_34 ( & V_96 -> V_11 , L_99
L_100 ) ;
goto V_827;
}
} else {
V_114 = F_395 ( V_96 , F_396 ( 32 ) ) ;
if ( V_114 ) {
F_34 ( & V_96 -> V_11 , L_101 ) ;
goto V_827;
}
}
F_398 ( V_96 ) ;
F_387 ( V_96 ) ;
F_367 ( V_96 ) ;
F_365 ( V_96 ) ;
V_1 = F_88 ( sizeof( * V_1 ) , V_131 ) ;
if ( ! V_1 ) {
V_114 = - V_132 ;
goto V_827;
}
V_1 -> V_212 = F_399 ( V_96 , 0 ) ;
if ( ! V_1 -> V_212 ) {
F_34 ( & V_96 -> V_11 , L_102 ) ;
V_114 = - V_132 ;
goto V_828;
}
V_1 -> V_96 = V_96 ;
V_1 -> V_82 = & V_96 -> V_11 ;
V_1 -> V_169 = V_819 ;
V_1 -> V_41 = V_819 ;
V_1 -> V_172 = V_829 ;
memset ( V_1 -> V_830 , 0xff , sizeof( V_1 -> V_830 ) ) ;
F_194 ( & V_1 -> V_464 ) ;
F_194 ( & V_1 -> V_430 ) ;
F_400 ( & V_1 -> V_434 , F_186 ) ;
F_400 ( & V_1 -> V_496 , F_250 ) ;
F_400 ( & V_1 -> V_503 , F_252 ) ;
V_114 = F_401 ( V_1 ) ;
if ( V_114 )
goto V_831;
F_300 ( V_1 ) ;
V_114 = F_343 ( V_1 ) ;
F_306 ( V_1 ) ;
if ( V_114 )
goto V_831;
F_46 (adapter, i) {
struct V_10 * V_136 ;
V_136 = F_402 ( sizeof( struct V_14 ) ,
V_793 ) ;
if ( ! V_136 ) {
V_114 = - V_132 ;
goto V_832;
}
F_403 ( V_136 , & V_96 -> V_11 ) ;
V_1 -> V_23 [ V_105 ] = V_136 ;
V_26 = F_5 ( V_136 ) ;
V_26 -> V_1 = V_1 ;
V_26 -> V_50 = - 1 ;
V_26 -> V_21 = V_105 ;
V_136 -> V_98 = V_96 -> V_98 ;
V_136 -> V_833 = V_834 | V_835 |
V_836 | V_837 |
V_838 | V_839 |
V_840 | V_49 ;
if ( V_820 )
V_136 -> V_833 |= V_841 ;
V_136 -> V_48 |= V_136 -> V_833 ;
V_136 -> V_842 = V_136 -> V_48 & V_843 ;
V_136 -> V_480 |= V_844 ;
V_136 -> V_845 = & V_846 ;
F_404 ( V_136 , & V_847 ) ;
}
F_405 ( V_96 , V_1 ) ;
if ( V_1 -> V_45 & V_778 ) {
V_114 = F_406 ( V_1 , V_819 , V_819 , 0 ) ;
if ( V_114 )
goto V_832;
}
F_375 ( V_1 ) ;
V_1 -> V_401 = F_407 () ;
if ( ! V_1 -> V_401 ) {
F_260 ( & V_96 -> V_11 , L_103 ) ;
V_1 -> V_7 . V_171 = 0 ;
}
if ( F_93 ( V_1 ) && F_192 ( & V_1 -> V_429 ) < 0 ) {
F_260 ( & V_96 -> V_11 , L_104
L_105 ) ;
V_1 -> V_7 . V_171 = 0 ;
}
if ( V_848 > 1 && F_381 ( V_1 ) == 0 )
V_1 -> V_45 |= V_95 ;
else if ( V_848 > 0 && F_408 ( V_96 ) == 0 )
V_1 -> V_45 |= V_97 ;
V_114 = F_383 ( V_1 ) ;
if ( V_114 )
goto V_832;
F_46 (adapter, i) {
V_26 = F_59 ( V_1 , V_105 ) ;
F_409 ( V_1 -> V_23 [ V_105 ] , V_26 -> V_113 ) ;
F_410 ( V_1 -> V_23 [ V_105 ] , V_26 -> V_113 ) ;
V_114 = F_411 ( V_1 -> V_23 [ V_105 ] ) ;
if ( V_114 )
break;
V_1 -> V_830 [ V_26 -> V_52 ] = V_105 ;
F_386 ( V_1 -> V_23 [ V_105 ] ) ;
}
if ( V_105 == 0 ) {
F_34 ( & V_96 -> V_11 , L_106 ) ;
goto V_832;
}
if ( V_114 ) {
F_260 ( & V_96 -> V_11 , L_107 , V_105 ) ;
V_114 = 0 ;
}
if ( V_849 ) {
V_1 -> V_392 = F_412 ( F_102 ( V_96 ) ,
V_849 ) ;
F_163 ( V_1 ) ;
}
V_96 -> V_850 = 1 ;
if ( F_93 ( V_1 ) )
F_264 ( V_1 ) ;
V_825:
#ifdef F_333
if ( V_819 < F_11 ( V_683 ) && V_683 [ V_819 ] > 0 )
if ( F_413 ( V_96 , V_683 [ V_819 ] ) == 0 )
F_81 ( & V_96 -> V_11 ,
L_108 ,
V_683 [ V_819 ] ) ;
#endif
return 0 ;
V_832:
F_389 ( V_1 ) ;
V_831:
F_414 ( V_1 -> V_212 ) ;
V_828:
F_57 ( V_1 ) ;
V_827:
F_415 ( V_96 ) ;
F_362 ( V_96 ) ;
V_826:
F_416 ( V_96 ) ;
F_405 ( V_96 , NULL ) ;
return V_114 ;
}
static void T_18 F_417 ( struct V_460 * V_96 )
{
struct V_1 * V_1 = F_210 ( V_96 ) ;
#ifdef F_333
F_418 ( V_96 ) ;
#endif
if ( V_1 ) {
int V_105 ;
if ( F_93 ( V_1 ) )
F_266 ( V_1 ) ;
F_46 (adapter, i)
if ( V_1 -> V_23 [ V_105 ] -> V_851 == V_852 )
F_419 ( V_1 -> V_23 [ V_105 ] ) ;
if ( V_1 -> V_392 )
F_420 ( V_1 -> V_392 ) ;
if ( V_1 -> V_45 & V_303 )
F_278 ( V_1 ) ;
F_389 ( V_1 ) ;
F_414 ( V_1 -> V_212 ) ;
F_57 ( V_1 ) ;
F_415 ( V_96 ) ;
F_362 ( V_96 ) ;
F_416 ( V_96 ) ;
F_405 ( V_96 , NULL ) ;
} else
F_416 ( V_96 ) ;
}
static int T_19 F_421 ( void )
{
int V_34 ;
V_433 = F_422 ( L_109 ) ;
if ( ! V_433 )
return - V_132 ;
V_849 = F_412 ( V_183 , NULL ) ;
if ( ! V_849 )
F_423 ( L_110 ) ;
V_34 = F_424 ( & V_482 ) ;
if ( V_34 < 0 )
F_425 ( V_849 ) ;
return V_34 ;
}
static void T_20 F_426 ( void )
{
F_427 ( & V_482 ) ;
F_425 ( V_849 ) ;
F_428 ( V_433 ) ;
F_429 ( V_433 ) ;
}
