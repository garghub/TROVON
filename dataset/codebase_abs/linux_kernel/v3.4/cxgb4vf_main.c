void F_1 ( struct V_1 * V_1 , int V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
if ( ! F_2 ( V_5 ) || V_3 == F_3 ( V_5 ) )
return;
if ( V_3 ) {
const char * V_7 ;
const char * V_8 ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
switch ( V_10 -> V_11 . V_12 ) {
case V_13 :
V_7 = L_1 ;
break;
case V_14 :
V_7 = L_2 ;
break;
case V_15 :
V_7 = L_3 ;
break;
default:
V_7 = L_4 ;
break;
}
switch ( V_10 -> V_11 . V_8 ) {
case V_16 :
V_8 = L_5 ;
break;
case V_17 :
V_8 = L_6 ;
break;
case V_16 | V_17 :
V_8 = L_7 ;
break;
default:
V_8 = L_8 ;
break;
}
F_6 ( V_18 L_9 ,
V_5 -> V_19 , V_7 , V_8 ) ;
} else {
F_7 ( V_5 ) ;
F_6 ( V_18 L_10 , V_5 -> V_19 ) ;
}
}
static int F_8 ( struct V_4 * V_5 )
{
int V_20 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_20 = F_9 ( V_10 -> V_1 , V_10 -> V_21 , V_5 -> V_22 , - 1 , - 1 , - 1 , 1 ,
true ) ;
if ( V_20 == 0 ) {
V_20 = F_10 ( V_10 -> V_1 , V_10 -> V_21 ,
V_10 -> V_23 , V_5 -> V_24 , true ) ;
if ( V_20 >= 0 ) {
V_10 -> V_23 = V_20 ;
V_20 = 0 ;
}
}
if ( V_20 == 0 )
V_20 = F_11 ( V_10 -> V_1 , V_10 -> V_21 , true , true ) ;
return V_20 ;
}
static void F_12 ( struct V_1 * V_1 )
{
int V_25 = sizeof( V_1 -> V_26 [ 0 ] . V_27 ) - 1 ;
int V_2 ;
snprintf ( V_1 -> V_26 [ V_28 ] . V_27 , V_25 ,
L_11 , V_1 -> V_19 ) ;
V_1 -> V_26 [ V_28 ] . V_27 [ V_25 ] = 0 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
int V_29 , V_30 ;
for ( V_29 = 0 , V_30 = V_31 ; V_29 < V_10 -> V_32 ; V_29 ++ , V_30 ++ ) {
snprintf ( V_1 -> V_26 [ V_30 ] . V_27 , V_25 ,
L_12 , V_5 -> V_19 , V_29 ) ;
V_1 -> V_26 [ V_30 ] . V_27 [ V_25 ] = 0 ;
}
}
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_33 * V_7 = & V_1 -> V_33 ;
int V_34 , V_30 , V_35 ;
V_35 = F_15 ( V_1 -> V_26 [ V_28 ] . V_36 , V_37 ,
0 , V_1 -> V_26 [ V_28 ] . V_27 , & V_7 -> V_38 ) ;
if ( V_35 )
return V_35 ;
V_30 = V_31 ;
F_16 (s, rxq) {
V_35 = F_15 ( V_1 -> V_26 [ V_30 ] . V_36 ,
V_37 , 0 ,
V_1 -> V_26 [ V_30 ] . V_27 ,
& V_7 -> V_39 [ V_34 ] . V_40 ) ;
if ( V_35 )
goto V_41;
V_30 ++ ;
}
return 0 ;
V_41:
while ( -- V_34 >= 0 )
F_17 ( V_1 -> V_26 [ -- V_30 ] . V_36 , & V_7 -> V_39 [ V_34 ] . V_40 ) ;
F_17 ( V_1 -> V_26 [ V_28 ] . V_36 , & V_7 -> V_38 ) ;
return V_35 ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_33 * V_7 = & V_1 -> V_33 ;
int V_34 , V_30 ;
F_17 ( V_1 -> V_26 [ V_28 ] . V_36 , & V_7 -> V_38 ) ;
V_30 = V_31 ;
F_16 (s, rxq)
F_17 ( V_1 -> V_26 [ V_30 ++ ] . V_36 ,
& V_7 -> V_39 [ V_34 ] . V_40 ) ;
}
static void F_19 ( struct V_42 * V_40 )
{
F_20 ( & V_40 -> V_43 ) ;
F_21 ( V_40 -> V_1 , V_44 + V_45 ,
F_22 ( 0 ) |
F_23 ( V_40 -> V_46 ) |
F_24 ( V_40 -> V_47 ) ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
int V_34 ;
struct V_33 * V_7 = & V_1 -> V_33 ;
F_16 (s, rxq)
F_19 ( & V_7 -> V_39 [ V_34 ] . V_40 ) ;
F_19 ( & V_7 -> V_38 ) ;
if ( V_1 -> V_48 & V_49 )
F_21 ( V_1 , V_44 + V_45 ,
F_22 ( 0 ) |
F_23 ( V_7 -> V_50 . V_46 ) |
F_24 ( V_7 -> V_50 . V_47 ) ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_33 * V_7 = & V_1 -> V_33 ;
int V_34 ;
F_16 (s, rxq)
F_27 ( & V_7 -> V_39 [ V_34 ] . V_40 . V_43 ) ;
F_27 ( & V_7 -> V_38 . V_43 ) ;
}
static int F_28 ( struct V_42 * V_40 , const T_1 * V_51 ,
const struct V_52 * V_53 )
{
struct V_1 * V_1 = V_40 -> V_1 ;
T_2 V_54 = ( ( const struct V_55 * ) V_51 ) -> V_54 ;
void * V_56 = ( void * ) ( V_51 + 1 ) ;
switch ( V_54 ) {
case V_57 : {
const struct V_58 * V_59 = V_56 ;
if ( V_59 -> type == V_60 )
F_29 ( V_1 , V_59 -> V_61 ) ;
break;
}
case V_62 : {
const struct V_63 * V_64 = ( void * ) V_56 ;
unsigned int V_65 = F_30 ( F_31 ( V_64 -> V_66 ) ) ;
struct V_33 * V_7 = & V_1 -> V_33 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
unsigned int V_71 ;
V_71 = F_32 ( V_7 , V_65 ) ;
if ( F_33 ( V_71 >= V_72 ) ) {
F_34 ( V_1 -> V_73 ,
L_13 , V_65 ) ;
break;
}
V_68 = V_7 -> V_74 [ V_71 ] ;
if ( F_33 ( V_68 == NULL ) ) {
F_34 ( V_1 -> V_73 ,
L_14 , V_65 ) ;
break;
}
V_70 = F_35 ( V_68 , struct V_69 , V_75 ) ;
if ( F_33 ( V_68 -> V_76 != V_65 ) ) {
F_34 ( V_1 -> V_73 ,
L_15 ,
V_65 , V_68 -> V_76 ) ;
break;
}
V_70 -> V_75 . V_77 ++ ;
F_36 ( V_70 -> V_70 ) ;
break;
}
default:
F_34 ( V_1 -> V_73 ,
L_16 , V_54 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_33 * V_7 = & V_1 -> V_33 ;
int V_35 , V_2 , V_78 ;
F_38 ( V_7 -> V_79 , V_72 ) ;
if ( V_1 -> V_48 & V_49 ) {
V_35 = F_39 ( V_1 , & V_7 -> V_50 , false ,
V_1 -> V_6 [ 0 ] , 0 , NULL , NULL ) ;
if ( V_35 )
goto V_80;
}
V_35 = F_39 ( V_1 , & V_7 -> V_38 , true , V_1 -> V_6 [ 0 ] ,
V_28 , NULL , F_28 ) ;
if ( V_35 )
goto V_80;
V_78 = V_31 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_81 * V_34 = & V_7 -> V_39 [ V_10 -> V_82 ] ;
struct V_69 * V_70 = & V_7 -> V_83 [ V_10 -> V_82 ] ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_32 ; V_29 ++ , V_34 ++ , V_70 ++ ) {
V_35 = F_39 ( V_1 , & V_34 -> V_40 , false ,
V_5 , V_78 ++ ,
& V_34 -> V_84 , V_85 ) ;
if ( V_35 )
goto V_80;
V_35 = F_40 ( V_1 , V_70 , V_5 ,
F_41 ( V_5 , V_29 ) ,
V_7 -> V_38 . V_47 ) ;
if ( V_35 )
goto V_80;
V_34 -> V_40 . V_86 = V_29 ;
memset ( & V_34 -> V_87 , 0 , sizeof( V_34 -> V_87 ) ) ;
}
}
V_7 -> V_88 = V_7 -> V_83 [ 0 ] . V_75 . V_76 - V_7 -> V_83 [ 0 ] . V_75 . V_47 ;
V_7 -> V_89 = V_7 -> V_39 [ 0 ] . V_40 . V_76 - V_7 -> V_39 [ 0 ] . V_40 . V_47 ;
F_42 ( V_7 , V_7 -> V_38 . V_76 ) = & V_7 -> V_38 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_81 * V_34 = & V_7 -> V_39 [ V_10 -> V_82 ] ;
struct V_69 * V_70 = & V_7 -> V_83 [ V_10 -> V_82 ] ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_32 ; V_29 ++ , V_34 ++ , V_70 ++ ) {
F_42 ( V_7 , V_34 -> V_40 . V_76 ) = & V_34 -> V_40 ;
F_43 ( V_7 , V_70 -> V_75 . V_76 ) = & V_70 -> V_75 ;
V_34 -> V_84 . V_76 = V_34 -> V_84 . V_47 + V_7 -> V_88 ;
F_43 ( V_7 , V_34 -> V_84 . V_76 ) = & V_34 -> V_84 ;
}
}
return 0 ;
V_80:
F_44 ( V_1 ) ;
return V_35 ;
}
static int F_45 ( struct V_1 * V_1 )
{
int V_2 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_46 ( V_1 , V_2 ) ;
struct V_81 * V_34 = & V_1 -> V_33 . V_39 [ V_10 -> V_82 ] ;
T_3 V_90 [ V_91 ] ;
int V_29 , V_35 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_32 ; V_29 ++ )
V_90 [ V_29 ] = V_34 [ V_29 ] . V_40 . V_76 ;
V_35 = F_47 ( V_1 , V_10 -> V_21 ,
0 , V_10 -> V_92 , V_90 , V_10 -> V_32 ) ;
if ( V_35 )
return V_35 ;
switch ( V_1 -> V_93 . V_90 . V_94 ) {
case V_95 :
if ( ! V_1 -> V_93 . V_90 . V_96 . V_97 . V_98 ) {
union V_99 V_100 ;
V_35 = F_48 ( V_1 ,
V_10 -> V_21 ,
& V_100 ) ;
if ( V_35 )
return V_35 ;
V_100 . V_97 . V_101 =
V_34 [ 0 ] . V_40 . V_76 ;
V_35 = F_49 ( V_1 ,
V_10 -> V_21 ,
& V_100 ) ;
if ( V_35 )
return V_35 ;
}
break;
}
}
return 0 ;
}
static int F_50 ( struct V_1 * V_1 )
{
int V_35 ;
if ( ( V_1 -> V_48 & V_102 ) == 0 ) {
V_35 = F_37 ( V_1 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_45 ( V_1 ) ;
if ( V_35 ) {
F_44 ( V_1 ) ;
return V_35 ;
}
if ( V_1 -> V_48 & V_103 )
F_12 ( V_1 ) ;
V_1 -> V_48 |= V_102 ;
}
F_51 ( ( V_1 -> V_48 & ( V_103 | V_49 ) ) == 0 ) ;
if ( V_1 -> V_48 & V_103 )
V_35 = F_14 ( V_1 ) ;
else
V_35 = F_15 ( V_1 -> V_104 -> V_105 ,
F_52 ( V_1 ) , 0 ,
V_1 -> V_19 , V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_17 ,
V_35 ) ;
return V_35 ;
}
F_25 ( V_1 ) ;
F_53 ( V_1 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_1 )
{
if ( V_1 -> V_48 & V_103 )
F_18 ( V_1 ) ;
else
F_17 ( V_1 -> V_104 -> V_105 , V_1 ) ;
F_26 ( V_1 ) ;
}
static int F_55 ( struct V_4 * V_5 )
{
int V_35 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_106 == 0 ) {
V_35 = F_50 ( V_1 ) ;
if ( V_35 )
return V_35 ;
}
F_56 ( V_5 , V_10 -> V_32 ) ;
V_35 = F_57 ( V_5 , V_10 -> V_32 ) ;
if ( V_35 )
goto V_107;
V_35 = F_8 ( V_5 ) ;
if ( V_35 )
goto V_107;
F_58 ( V_5 ) ;
F_59 ( V_10 -> V_108 , & V_1 -> V_106 ) ;
return 0 ;
V_107:
if ( V_1 -> V_106 == 0 )
F_54 ( V_1 ) ;
return V_35 ;
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
F_61 ( V_5 ) ;
F_7 ( V_5 ) ;
F_11 ( V_1 , V_10 -> V_21 , false , false ) ;
V_10 -> V_11 . V_3 = 0 ;
F_62 ( V_10 -> V_108 , & V_1 -> V_106 ) ;
if ( V_1 -> V_106 == 0 )
F_54 ( V_1 ) ;
return 0 ;
}
static struct V_109 * F_63 ( struct V_4 * V_5 )
{
struct V_110 V_87 ;
struct V_9 * V_10 = F_64 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_109 * V_111 = & V_5 -> V_87 ;
int V_35 ;
F_65 ( & V_1 -> V_112 ) ;
V_35 = F_66 ( V_1 , V_10 -> V_2 , & V_87 ) ;
F_67 ( & V_1 -> V_112 ) ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
if ( V_35 )
return V_111 ;
V_111 -> V_113 = ( V_87 . V_114 + V_87 . V_115 +
V_87 . V_116 + V_87 . V_117 ) ;
V_111 -> V_118 = ( V_87 . V_119 + V_87 . V_120 +
V_87 . V_121 + V_87 . V_122 ) ;
V_111 -> V_123 = ( V_87 . V_124 + V_87 . V_125 +
V_87 . V_126 ) ;
V_111 -> V_127 = ( V_87 . V_128 + V_87 . V_129 +
V_87 . V_130 ) ;
V_111 -> V_131 = V_87 . V_129 ;
V_111 -> V_132 = V_87 . V_133 ;
V_111 -> V_134 = V_87 . V_135 ;
return V_111 ;
}
static inline unsigned int F_68 ( const struct V_4 * V_5 ,
const T_2 * * V_136 ,
unsigned int V_137 ,
unsigned int V_138 )
{
unsigned int V_139 = 0 ;
unsigned int V_140 = 0 ;
const struct V_141 * V_142 ;
F_69 (dev, ha)
if ( V_139 ++ >= V_137 ) {
V_136 [ V_140 ++ ] = V_142 -> V_136 ;
if ( V_140 >= V_138 )
break;
}
return V_140 ;
}
static inline unsigned int F_70 ( const struct V_4 * V_5 ,
const T_2 * * V_136 ,
unsigned int V_137 ,
unsigned int V_138 )
{
unsigned int V_139 = 0 ;
unsigned int V_140 = 0 ;
const struct V_141 * V_142 ;
F_71 (ha, dev)
if ( V_139 ++ >= V_137 ) {
V_136 [ V_140 ++ ] = V_142 -> V_136 ;
if ( V_140 >= V_138 )
break;
}
return V_140 ;
}
static int F_72 ( const struct V_4 * V_5 , bool V_143 )
{
T_4 V_144 = 0 ;
T_4 V_145 = 0 ;
bool free = true ;
unsigned int V_137 , V_140 ;
const T_2 * V_136 [ 7 ] ;
int V_20 ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
for ( V_137 = 0 ; ; V_137 += V_140 ) {
V_140 = F_68 ( V_5 , V_136 , V_137 ,
F_73 ( V_136 ) ) ;
if ( V_140 == 0 )
break;
V_20 = F_74 ( V_10 -> V_1 , V_10 -> V_21 , free ,
V_140 , V_136 , NULL , & V_145 , V_143 ) ;
if ( V_20 < 0 )
return V_20 ;
free = false ;
}
for ( V_137 = 0 ; ; V_137 += V_140 ) {
V_140 = F_70 ( V_5 , V_136 , V_137 ,
F_73 ( V_136 ) ) ;
if ( V_140 == 0 )
break;
V_20 = F_74 ( V_10 -> V_1 , V_10 -> V_21 , free ,
V_140 , V_136 , NULL , & V_144 , V_143 ) ;
if ( V_20 < 0 )
return V_20 ;
free = false ;
}
return F_75 ( V_10 -> V_1 , V_10 -> V_21 , V_145 != 0 ,
V_145 | V_144 , V_143 ) ;
}
static int F_76 ( struct V_4 * V_5 , int V_22 , bool V_146 )
{
int V_20 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_20 = F_72 ( V_5 , V_146 ) ;
if ( V_20 == 0 )
V_20 = F_9 ( V_10 -> V_1 , V_10 -> V_21 , - 1 ,
( V_5 -> V_48 & V_147 ) != 0 ,
( V_5 -> V_48 & V_148 ) != 0 ,
1 , - 1 , V_146 ) ;
return V_20 ;
}
static void F_77 ( struct V_4 * V_5 )
{
F_76 ( V_5 , - 1 , false ) ;
}
static int F_78 ( const struct V_33 * V_7 , int V_149 )
{
int V_150 , V_151 = 0 , V_152 = V_153 ;
for ( V_150 = 0 ; V_150 < F_73 ( V_7 -> V_154 ) ; V_150 ++ ) {
int V_155 = V_149 - V_7 -> V_154 [ V_150 ] ;
if ( V_155 < 0 )
V_155 = - V_155 ;
if ( V_155 < V_152 ) {
V_152 = V_155 ;
V_151 = V_150 ;
}
}
return V_151 ;
}
static int F_79 ( const struct V_33 * V_7 , int V_156 )
{
int V_150 , V_155 , V_157 = 0 , V_152 = V_153 ;
for ( V_150 = 0 ; V_150 < F_73 ( V_7 -> V_158 ) ; V_150 ++ ) {
V_155 = V_156 - V_7 -> V_158 [ V_150 ] ;
if ( V_155 < 0 )
V_155 = - V_155 ;
if ( V_155 < V_152 ) {
V_152 = V_155 ;
V_157 = V_150 ;
}
}
return V_157 ;
}
static unsigned int F_80 ( const struct V_1 * V_1 ,
const struct V_42 * V_40 )
{
unsigned int V_151 = F_81 ( V_40 -> V_46 ) ;
return V_151 < V_159
? V_1 -> V_33 . V_154 [ V_151 ]
: 0 ;
}
static int F_82 ( struct V_1 * V_1 , struct V_42 * V_40 ,
unsigned int V_149 , unsigned int V_160 )
{
unsigned int V_151 ;
if ( ( V_149 | V_160 ) == 0 )
V_160 = 1 ;
if ( V_160 ) {
int V_35 ;
T_5 V_161 , V_157 ;
V_157 = F_79 ( & V_1 -> V_33 , V_160 ) ;
if ( V_40 -> V_27 && V_40 -> V_157 != V_157 ) {
V_161 = F_83 ( V_162 ) |
F_84 (
V_163 ) |
F_85 ( V_40 -> V_47 ) ;
V_35 = F_86 ( V_1 , 1 , & V_161 , & V_157 ) ;
if ( V_35 )
return V_35 ;
}
V_40 -> V_157 = V_157 ;
}
V_151 = ( V_149 == 0
? V_164
: F_78 ( & V_1 -> V_33 , V_149 ) ) ;
V_40 -> V_46 = ( F_87 ( V_151 ) |
( V_160 > 0 ? V_165 : 0 ) ) ;
return 0 ;
}
static inline unsigned int F_88 ( const struct V_1 * V_1 )
{
return 4 | ( 0x3f << 10 ) ;
}
static int F_89 ( struct V_4 * V_5 , struct V_166 * V_167 , int V_168 )
{
int V_20 = 0 ;
switch ( V_168 ) {
default:
V_20 = - V_169 ;
break;
}
return V_20 ;
}
static int F_90 ( struct V_4 * V_5 , int V_170 )
{
int V_20 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_170 < 81 )
return - V_171 ;
V_20 = F_9 ( V_10 -> V_1 , V_10 -> V_21 , V_170 ,
- 1 , - 1 , - 1 , - 1 , true ) ;
if ( ! V_20 )
V_5 -> V_22 = V_170 ;
return V_20 ;
}
static T_6 F_91 ( struct V_4 * V_5 ,
T_6 V_172 )
{
if ( V_172 & V_173 )
V_172 |= V_174 ;
else
V_172 &= ~ V_174 ;
return V_172 ;
}
static int F_92 ( struct V_4 * V_5 ,
T_6 V_172 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
T_6 V_175 = V_5 -> V_172 ^ V_172 ;
if ( V_175 & V_173 )
F_9 ( V_10 -> V_1 , V_10 -> V_21 , - 1 , - 1 , - 1 , - 1 ,
V_172 & V_174 , 0 ) ;
return 0 ;
}
static int F_93 ( struct V_4 * V_5 , void * V_176 )
{
int V_20 ;
struct V_177 * V_136 = V_176 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! F_94 ( V_136 -> V_178 ) )
return - V_179 ;
V_20 = F_10 ( V_10 -> V_1 , V_10 -> V_21 , V_10 -> V_23 ,
V_136 -> V_178 , true ) ;
if ( V_20 < 0 )
return V_20 ;
memcpy ( V_5 -> V_24 , V_136 -> V_178 , V_5 -> V_180 ) ;
V_10 -> V_23 = V_20 ;
return 0 ;
}
static void F_95 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_48 & V_103 ) {
struct V_81 * V_34 ;
int V_32 ;
V_34 = & V_1 -> V_33 . V_39 [ V_10 -> V_82 ] ;
for ( V_32 = V_10 -> V_32 ; V_32 ; V_32 -- ) {
V_37 ( 0 , & V_34 -> V_40 ) ;
V_34 ++ ;
}
} else
F_52 ( V_1 ) ( 0 , V_1 ) ;
}
static int F_96 ( struct V_4 * V_5 ,
struct V_181 * V_168 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
V_168 -> V_182 = V_10 -> V_11 . V_182 ;
V_168 -> V_183 = V_10 -> V_11 . V_183 ;
F_97 ( V_168 ,
F_3 ( V_5 ) ? V_10 -> V_11 . V_12 : - 1 ) ;
V_168 -> V_184 = V_185 ;
V_168 -> V_6 = ( V_168 -> V_182 & V_186 ) ? V_187 : V_188 ;
V_168 -> V_189 = V_10 -> V_108 ;
V_168 -> V_190 = V_191 ;
V_168 -> V_192 = V_10 -> V_11 . V_192 ;
V_168 -> V_193 = 0 ;
V_168 -> V_194 = 0 ;
return 0 ;
}
static void F_98 ( struct V_4 * V_5 ,
struct V_195 * V_196 )
{
struct V_1 * V_1 = F_99 ( V_5 ) ;
F_100 ( V_196 -> V_197 , V_198 , sizeof( V_196 -> V_197 ) ) ;
F_100 ( V_196 -> V_199 , V_200 , sizeof( V_196 -> V_199 ) ) ;
F_100 ( V_196 -> V_201 , F_101 ( F_102 ( V_5 -> V_5 . V_202 ) ) ,
sizeof( V_196 -> V_201 ) ) ;
snprintf ( V_196 -> V_203 , sizeof( V_196 -> V_203 ) ,
L_18 ,
F_103 ( V_1 -> V_93 . V_5 . V_204 ) ,
F_104 ( V_1 -> V_93 . V_5 . V_204 ) ,
F_105 ( V_1 -> V_93 . V_5 . V_204 ) ,
F_106 ( V_1 -> V_93 . V_5 . V_204 ) ,
F_103 ( V_1 -> V_93 . V_5 . V_205 ) ,
F_104 ( V_1 -> V_93 . V_5 . V_205 ) ,
F_105 ( V_1 -> V_93 . V_5 . V_205 ) ,
F_106 ( V_1 -> V_93 . V_5 . V_205 ) ) ;
}
static T_5 F_107 ( struct V_4 * V_5 )
{
return F_99 ( V_5 ) -> V_206 ;
}
static void F_108 ( struct V_4 * V_5 , T_5 V_207 )
{
F_99 ( V_5 ) -> V_206 = V_207 ;
}
static void F_109 ( struct V_4 * V_5 ,
struct V_208 * V_209 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_33 * V_7 = & V_10 -> V_1 -> V_33 ;
V_209 -> V_210 = V_211 ;
V_209 -> V_212 = V_213 ;
V_209 -> V_214 = 0 ;
V_209 -> V_215 = V_216 ;
V_209 -> V_217 = V_7 -> V_39 [ V_10 -> V_82 ] . V_84 . V_218 - V_219 ;
V_209 -> V_220 = V_7 -> V_39 [ V_10 -> V_82 ] . V_40 . V_218 ;
V_209 -> V_221 = 0 ;
V_209 -> V_222 = V_7 -> V_83 [ V_10 -> V_82 ] . V_75 . V_218 ;
}
static int F_110 ( struct V_4 * V_5 ,
struct V_208 * V_209 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_33 * V_7 = & V_1 -> V_33 ;
int V_29 ;
if ( V_209 -> V_217 > V_211 ||
V_209 -> V_221 ||
V_209 -> V_222 > V_216 ||
V_209 -> V_220 > V_213 ||
V_209 -> V_220 < V_223 ||
V_209 -> V_217 < V_224 ||
V_209 -> V_222 < V_225 )
return - V_171 ;
if ( V_1 -> V_48 & V_102 )
return - V_226 ;
for ( V_29 = V_10 -> V_82 ; V_29 < V_10 -> V_82 + V_10 -> V_32 ; V_29 ++ ) {
V_7 -> V_39 [ V_29 ] . V_84 . V_218 = V_209 -> V_217 + V_219 ;
V_7 -> V_39 [ V_29 ] . V_40 . V_218 = V_209 -> V_220 ;
V_7 -> V_83 [ V_29 ] . V_75 . V_218 = V_209 -> V_222 ;
}
return 0 ;
}
static int F_111 ( struct V_4 * V_5 ,
struct V_227 * V_228 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_42 * V_40 = & V_1 -> V_33 . V_39 [ V_10 -> V_82 ] . V_40 ;
V_228 -> V_229 = F_80 ( V_1 , V_40 ) ;
V_228 -> V_230 =
( ( V_40 -> V_46 & V_165 )
? V_1 -> V_33 . V_158 [ V_40 -> V_157 ]
: 0 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 ,
struct V_227 * V_228 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_82 ( V_1 ,
& V_1 -> V_33 . V_39 [ V_10 -> V_82 ] . V_40 ,
V_228 -> V_229 ,
V_228 -> V_230 ) ;
}
static void F_113 ( struct V_4 * V_5 ,
struct V_231 * V_232 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_232 -> V_192 = ( V_10 -> V_11 . V_233 & V_234 ) != 0 ;
V_232 -> V_235 = ( V_10 -> V_11 . V_8 & V_16 ) != 0 ;
V_232 -> V_236 = ( V_10 -> V_11 . V_8 & V_17 ) != 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
enum V_237 V_238 )
{
unsigned int V_239 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_238 == V_240 )
V_239 = 0xffff ;
else if ( V_238 == V_241 )
V_239 = 0 ;
else
return - V_171 ;
return F_115 ( V_10 -> V_1 , V_10 -> V_21 , V_239 ) ;
}
static int F_116 ( struct V_4 * V_5 , int V_242 )
{
switch ( V_242 ) {
case V_243 :
return F_73 ( V_244 ) ;
default:
return - V_169 ;
}
}
static void F_117 ( struct V_4 * V_5 ,
T_5 V_242 ,
T_2 * V_61 )
{
switch ( V_242 ) {
case V_243 :
memcpy ( V_61 , V_244 , sizeof( V_244 ) ) ;
break;
}
}
static void F_118 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_245 * V_87 )
{
const struct V_69 * V_70 = & V_1 -> V_33 . V_83 [ V_10 -> V_82 ] ;
const struct V_81 * V_34 = & V_1 -> V_33 . V_39 [ V_10 -> V_82 ] ;
int V_29 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
for ( V_29 = 0 ; V_29 < V_10 -> V_32 ; V_29 ++ , V_34 ++ , V_70 ++ ) {
V_87 -> V_246 += V_70 -> V_246 ;
V_87 -> V_247 += V_70 -> V_248 ;
V_87 -> V_249 += V_34 -> V_87 . V_250 ;
V_87 -> V_251 += V_34 -> V_87 . V_251 ;
V_87 -> V_252 += V_70 -> V_252 ;
V_87 -> V_253 += V_34 -> V_87 . V_253 ;
V_87 -> V_254 += V_34 -> V_87 . V_254 ;
}
}
static void F_119 ( struct V_4 * V_5 ,
struct V_255 * V_87 ,
T_4 * V_61 )
{
struct V_9 * V_10 = F_64 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_35 = F_66 ( V_1 , V_10 -> V_2 ,
(struct V_110 * ) V_61 ) ;
if ( V_35 )
memset ( V_61 , 0 , sizeof( struct V_110 ) ) ;
V_61 += sizeof( struct V_110 ) / sizeof( T_4 ) ;
F_118 ( V_1 , V_10 , (struct V_245 * ) V_61 ) ;
}
static int F_120 ( struct V_4 * V_5 )
{
return V_256 ;
}
static void F_121 ( struct V_1 * V_1 , void * V_257 ,
unsigned int V_258 , unsigned int V_259 )
{
T_5 * V_260 = V_257 + V_258 - V_261 ;
for ( ; V_258 <= V_259 ; V_258 += sizeof( T_5 ) ) {
if ( V_258 == V_262 + V_263 )
* V_260 ++ = 0xffff ;
else
* V_260 ++ = F_122 ( V_1 , V_258 ) ;
}
}
static void F_123 ( struct V_4 * V_5 ,
struct V_264 * V_265 ,
void * V_257 )
{
struct V_1 * V_1 = F_99 ( V_5 ) ;
V_265 -> V_199 = F_88 ( V_1 ) ;
memset ( V_257 , 0 , V_256 ) ;
F_121 ( V_1 , V_257 ,
V_44 + V_266 ,
V_44 + V_267 ) ;
F_121 ( V_1 , V_257 ,
V_268 + V_269 ,
V_268 + V_270 ) ;
F_121 ( V_1 , V_257 ,
V_271 + V_272 ,
V_271 + V_273 ) ;
F_121 ( V_1 , V_257 ,
V_262 + V_274 ,
V_262 + V_275 ) ;
F_121 ( V_1 , V_257 ,
V_276 + V_277 ,
V_276 + V_278 ) ;
}
static void F_124 ( struct V_4 * V_5 ,
struct V_279 * V_280 )
{
V_280 -> V_182 = 0 ;
V_280 -> V_281 = 0 ;
memset ( & V_280 -> V_282 , 0 , sizeof( V_280 -> V_282 ) ) ;
}
static int F_125 ( struct V_283 * V_284 , void * V_161 )
{
struct V_1 * V_1 = V_284 -> V_285 ;
int V_286 = F_126 ( V_1 -> V_33 . V_287 , V_288 ) ;
int V_29 , V_289 = ( V_290 ) V_161 - 1 ;
if ( V_289 )
F_127 ( V_284 , '\n' ) ;
#define F_128 ( T_7 , V_7 , V_161 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_129 ( V_7 , V_161 ) S3("s", s, v)
#define F_130 ( V_7 , V_161 ) S3("u", s, txq[qs].v)
#define F_131 ( V_7 , V_161 ) S3("u", s, rxq[qs].v)
if ( V_289 < V_286 ) {
const struct V_81 * V_34 = & V_1 -> V_33 . V_39 [ V_289 * V_288 ] ;
const struct V_69 * V_70 = & V_1 -> V_33 . V_83 [ V_289 * V_288 ] ;
int V_291 = F_132 ( V_288 , V_1 -> V_33 . V_287 - V_288 * V_289 ) ;
F_129 ( L_19 , L_20 ) ;
F_129 ( L_21 ,
( V_34 [ V_29 ] . V_40 . V_292
? V_34 [ V_29 ] . V_40 . V_292 -> V_19
: L_22 ) ) ;
F_128 ( L_23 , L_24 ,
( V_34 [ V_29 ] . V_40 . V_292
? ( (struct V_9 * )
F_4 ( V_34 [ V_29 ] . V_40 . V_292 ) ) -> V_108
: - 1 ) ) ;
F_130 ( L_25 , V_75 . V_76 ) ;
F_130 ( L_26 , V_75 . V_218 ) ;
F_130 ( L_27 , V_75 . V_293 ) ;
F_130 ( L_28 , V_75 . V_2 ) ;
F_130 ( L_29 , V_75 . V_294 ) ;
F_131 ( L_30 , V_40 . V_76 ) ;
F_131 ( L_31 , V_40 . V_218 ) ;
F_131 ( L_32 , V_40 . V_295 ) ;
F_128 ( L_33 , L_34 , F_80 ( V_1 , & V_34 [ V_29 ] . V_40 ) ) ;
F_128 ( L_33 , L_35 ,
V_1 -> V_33 . V_158 [ V_34 [ V_29 ] . V_40 . V_157 ] ) ;
F_131 ( L_36 , V_40 . V_294 ) ;
F_131 ( L_37 , V_40 . V_296 ) ;
F_131 ( L_38 , V_84 . V_76 ) ;
F_131 ( L_39 , V_84 . V_218 - V_219 ) ;
F_131 ( L_40 , V_84 . V_297 ) ;
F_131 ( L_41 , V_84 . V_2 ) ;
F_131 ( L_42 , V_84 . V_294 ) ;
return 0 ;
}
V_289 -= V_286 ;
if ( V_289 == 0 ) {
const struct V_42 * V_298 = & V_1 -> V_33 . V_38 ;
F_133 ( V_284 , L_43 , L_19 , L_44 ) ;
F_133 ( V_284 , L_45 , L_30 , V_298 -> V_76 ) ;
F_133 ( V_284 , L_45 , L_34 ,
F_80 ( V_1 , V_298 ) ) ;
F_133 ( V_284 , L_45 , L_35 ,
V_1 -> V_33 . V_158 [ V_298 -> V_157 ] ) ;
F_133 ( V_284 , L_45 , L_46 , V_298 -> V_294 ) ;
F_133 ( V_284 , L_45 , L_37 , V_298 -> V_296 ) ;
} else if ( V_289 == 1 ) {
const struct V_42 * V_50 = & V_1 -> V_33 . V_50 ;
F_133 ( V_284 , L_43 , L_19 , L_47 ) ;
F_133 ( V_284 , L_45 , L_30 , V_50 -> V_76 ) ;
F_133 ( V_284 , L_45 , L_34 ,
F_80 ( V_1 , V_50 ) ) ;
F_133 ( V_284 , L_45 , L_35 ,
V_1 -> V_33 . V_158 [ V_50 -> V_157 ] ) ;
F_133 ( V_284 , L_45 , L_46 , V_50 -> V_294 ) ;
F_133 ( V_284 , L_45 , L_37 , V_50 -> V_296 ) ;
}
#undef F_131
#undef F_130
#undef F_129
#undef F_128
return 0 ;
}
static int F_134 ( const struct V_1 * V_1 )
{
return F_126 ( V_1 -> V_33 . V_287 , V_288 ) + 1 +
( ( V_1 -> V_48 & V_49 ) != 0 ) ;
}
static void * F_135 ( struct V_283 * V_284 , T_8 * V_299 )
{
int V_300 = F_134 ( V_284 -> V_285 ) ;
return * V_299 < V_300 ? ( void * ) ( ( V_290 ) * V_299 + 1 ) : NULL ;
}
static void F_136 ( struct V_283 * V_284 , void * V_161 )
{
}
static void * F_137 ( struct V_283 * V_284 , void * V_161 , T_8 * V_299 )
{
int V_300 = F_134 ( V_284 -> V_285 ) ;
++ * V_299 ;
return * V_299 < V_300 ? ( void * ) ( ( V_290 ) * V_299 + 1 ) : NULL ;
}
static int F_138 ( struct V_301 * V_301 , struct V_302 * V_302 )
{
int V_303 = F_139 ( V_302 , & V_304 ) ;
if ( ! V_303 ) {
struct V_283 * V_284 = V_302 -> V_305 ;
V_284 -> V_285 = V_301 -> V_306 ;
}
return V_303 ;
}
static int F_140 ( struct V_283 * V_284 , void * V_161 )
{
struct V_1 * V_1 = V_284 -> V_285 ;
int V_286 = F_126 ( V_1 -> V_33 . V_287 , V_288 ) ;
int V_29 , V_289 = ( V_290 ) V_161 - 1 ;
if ( V_289 )
F_127 ( V_284 , '\n' ) ;
#define F_128 ( T_9 , V_7 , V_161 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_129 ( V_7 , V_161 ) S3("s", s, v)
#define F_141 ( T_9 , V_7 , V_161 ) S3(fmt, s, txq[qs].v)
#define F_130 ( V_7 , V_161 ) T3("lu", s, v)
#define F_142 ( T_9 , V_7 , V_161 ) S3(fmt, s, rxq[qs].v)
#define F_131 ( V_7 , V_161 ) R3("lu", s, v)
if ( V_289 < V_286 ) {
const struct V_81 * V_34 = & V_1 -> V_33 . V_39 [ V_289 * V_288 ] ;
const struct V_69 * V_70 = & V_1 -> V_33 . V_83 [ V_289 * V_288 ] ;
int V_291 = F_132 ( V_288 , V_1 -> V_33 . V_287 - V_288 * V_289 ) ;
F_129 ( L_19 , L_20 ) ;
F_129 ( L_21 ,
( V_34 [ V_29 ] . V_40 . V_292
? V_34 [ V_29 ] . V_40 . V_292 -> V_19
: L_22 ) ) ;
F_142 ( L_33 , L_48 , V_40 . V_307 ) ;
F_131 ( L_49 , V_87 . V_308 ) ;
F_131 ( L_50 , V_87 . V_250 ) ;
F_131 ( L_51 , V_87 . V_251 ) ;
F_131 ( L_52 , V_87 . V_254 ) ;
F_131 ( L_53 , V_87 . V_253 ) ;
F_131 ( L_54 , V_87 . V_309 ) ;
F_130 ( L_55 , V_246 ) ;
F_130 ( L_56 , V_248 ) ;
F_130 ( L_57 , V_252 ) ;
F_130 ( L_58 , V_75 . V_310 ) ;
F_130 ( L_59 , V_75 . V_77 ) ;
F_130 ( L_60 , V_311 ) ;
F_131 ( L_61 , V_84 . V_312 ) ;
F_131 ( L_62 , V_84 . V_313 ) ;
F_131 ( L_63 , V_84 . V_314 ) ;
return 0 ;
}
V_289 -= V_286 ;
if ( V_289 == 0 ) {
const struct V_42 * V_298 = & V_1 -> V_33 . V_38 ;
F_133 ( V_284 , L_64 , L_19 , L_44 ) ;
F_133 ( V_284 , L_65 , L_48 ,
V_298 -> V_307 ) ;
F_133 ( V_284 , L_65 , L_36 , V_298 -> V_294 ) ;
F_133 ( V_284 , L_65 , L_37 , V_298 -> V_296 ) ;
} else if ( V_289 == 1 ) {
const struct V_42 * V_50 = & V_1 -> V_33 . V_50 ;
F_133 ( V_284 , L_64 , L_19 , L_47 ) ;
F_133 ( V_284 , L_65 , L_48 ,
V_50 -> V_307 ) ;
F_133 ( V_284 , L_65 , L_36 , V_50 -> V_294 ) ;
F_133 ( V_284 , L_65 , L_37 , V_50 -> V_296 ) ;
}
#undef F_131
#undef F_130
#undef F_129
#undef F_142
#undef F_141
#undef F_128
return 0 ;
}
static int F_143 ( const struct V_1 * V_1 )
{
return F_126 ( V_1 -> V_33 . V_287 , V_288 ) + 1 +
( ( V_1 -> V_48 & V_49 ) != 0 ) ;
}
static void * F_144 ( struct V_283 * V_284 , T_8 * V_299 )
{
int V_300 = F_143 ( V_284 -> V_285 ) ;
return * V_299 < V_300 ? ( void * ) ( ( V_290 ) * V_299 + 1 ) : NULL ;
}
static void F_145 ( struct V_283 * V_284 , void * V_161 )
{
}
static void * F_146 ( struct V_283 * V_284 , void * V_161 , T_8 * V_299 )
{
int V_300 = F_143 ( V_284 -> V_285 ) ;
( * V_299 ) ++ ;
return * V_299 < V_300 ? ( void * ) ( ( V_290 ) * V_299 + 1 ) : NULL ;
}
static int F_147 ( struct V_301 * V_301 , struct V_302 * V_302 )
{
int V_303 = F_139 ( V_302 , & V_315 ) ;
if ( V_303 == 0 ) {
struct V_283 * V_284 = V_302 -> V_305 ;
V_284 -> V_285 = V_301 -> V_306 ;
}
return V_303 ;
}
static int F_148 ( struct V_283 * V_284 , void * V_161 )
{
struct V_1 * V_1 = V_284 -> V_285 ;
struct V_316 * V_317 = & V_1 -> V_93 . V_317 ;
#define F_129 ( V_27 , T_9 , T_10 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_129 ( L_66 , L_67 , V_318 ) ;
F_129 ( L_68 , L_67 , V_319 ) ;
F_129 ( L_69 , L_67 , V_320 ) ;
F_129 ( L_70 , L_67 , V_321 ) ;
F_129 ( L_71 , L_67 , V_322 ) ;
F_129 ( L_72 , L_67 , V_323 ) ;
F_129 ( L_73 , L_74 , V_324 ) ;
F_129 ( L_75 , L_67 , V_325 ) ;
F_129 ( L_76 , L_74 , V_326 ) ;
F_129 ( L_77 , L_74 , V_327 ) ;
#undef F_129
return 0 ;
}
static int F_149 ( struct V_301 * V_301 , struct V_302 * V_302 )
{
return F_150 ( V_302 , F_148 , V_301 -> V_306 ) ;
}
static int F_151 ( struct V_283 * V_284 , void * V_161 )
{
if ( V_161 == V_328 ) {
F_152 ( V_284 , L_78 ) ;
} else {
struct V_1 * V_1 = V_284 -> V_285 ;
int V_2 = ( V_290 ) V_161 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_133 ( V_284 , L_79 ,
V_5 -> V_19 , V_10 -> V_108 , V_10 -> V_21 ) ;
}
return 0 ;
}
static inline void * F_153 ( struct V_1 * V_1 , T_8 V_299 )
{
return V_299 <= V_1 -> V_93 . V_329
? ( void * ) ( V_290 ) ( V_299 + 1 )
: NULL ;
}
static void * F_154 ( struct V_283 * V_284 , T_8 * V_299 )
{
return * V_299
? F_153 ( V_284 -> V_285 , * V_299 )
: V_328 ;
}
static void * F_155 ( struct V_283 * V_284 , void * V_161 , T_8 * V_299 )
{
( * V_299 ) ++ ;
return F_153 ( V_284 -> V_285 , * V_299 ) ;
}
static void F_156 ( struct V_283 * V_284 , void * V_161 )
{
}
static int F_157 ( struct V_301 * V_301 , struct V_302 * V_302 )
{
int V_303 = F_139 ( V_302 , & V_330 ) ;
if ( V_303 == 0 ) {
struct V_283 * V_284 = V_302 -> V_305 ;
V_284 -> V_285 = V_301 -> V_306 ;
}
return V_303 ;
}
static int T_11 F_158 ( struct V_1 * V_1 )
{
int V_150 ;
F_51 ( F_159 ( V_1 -> V_331 ) ) ;
for ( V_150 = 0 ; V_150 < F_73 ( V_332 ) ; V_150 ++ )
( void ) F_160 ( V_332 [ V_150 ] . V_19 ,
V_332 [ V_150 ] . V_94 ,
V_1 -> V_331 ,
( void * ) V_1 ,
V_332 [ V_150 ] . V_333 ) ;
return 0 ;
}
static void F_161 ( struct V_1 * V_1 )
{
F_51 ( F_159 ( V_1 -> V_331 ) ) ;
}
static int T_11 F_162 ( struct V_1 * V_1 )
{
struct V_316 * V_317 = & V_1 -> V_93 . V_317 ;
struct V_334 * V_334 = & V_1 -> V_93 . V_33 ;
struct V_33 * V_7 = & V_1 -> V_33 ;
unsigned int V_287 ;
int V_35 ;
V_35 = F_163 ( V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_80
L_81 , V_35 ) ;
return V_35 ;
}
V_35 = F_164 ( V_1 ) ;
if ( V_35 < 0 ) {
F_34 ( V_1 -> V_73 , L_82 , V_35 ) ;
return V_35 ;
}
V_35 = F_165 ( V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_83
L_84 , V_35 ) ;
return V_35 ;
}
V_35 = F_166 ( V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_83
L_85 , V_35 ) ;
return V_35 ;
}
V_35 = F_167 ( V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_83
L_86 , V_35 ) ;
return V_35 ;
}
V_35 = F_168 ( V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_83
L_87 , V_35 ) ;
return V_35 ;
}
if ( V_1 -> V_93 . V_90 . V_94 !=
V_95 ) {
F_34 ( V_1 -> V_73 , L_88
L_89 , V_1 -> V_93 . V_90 . V_94 ) ;
return - V_171 ;
}
V_35 = F_169 ( V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_90
L_81 , V_35 ) ;
return V_35 ;
}
V_7 -> V_154 [ 0 ] = F_170 ( V_1 ,
F_171 ( V_334 -> V_335 ) ) ;
V_7 -> V_154 [ 1 ] = F_170 ( V_1 ,
F_172 ( V_334 -> V_335 ) ) ;
V_7 -> V_154 [ 2 ] = F_170 ( V_1 ,
F_171 ( V_334 -> V_336 ) ) ;
V_7 -> V_154 [ 3 ] = F_170 ( V_1 ,
F_172 ( V_334 -> V_336 ) ) ;
V_7 -> V_154 [ 4 ] = F_170 ( V_1 ,
F_171 ( V_334 -> V_337 ) ) ;
V_7 -> V_154 [ 5 ] = F_170 ( V_1 ,
F_172 ( V_334 -> V_337 ) ) ;
V_7 -> V_158 [ 0 ] =
F_173 ( V_334 -> V_338 ) ;
V_7 -> V_158 [ 1 ] =
F_174 ( V_334 -> V_338 ) ;
V_7 -> V_158 [ 2 ] =
F_175 ( V_334 -> V_338 ) ;
V_7 -> V_158 [ 3 ] =
F_176 ( V_334 -> V_338 ) ;
V_35 = F_177 ( V_1 ) ;
if ( V_35 ) {
F_34 ( V_1 -> V_73 , L_91
L_92 , V_35 ) ;
return V_35 ;
}
V_1 -> V_93 . V_329 = V_317 -> V_318 ;
if ( V_1 -> V_93 . V_329 > V_339 ) {
F_178 ( V_1 -> V_73 , L_93
L_94 , V_339 ,
V_1 -> V_93 . V_329 ) ;
V_1 -> V_93 . V_329 = V_339 ;
}
V_287 = V_317 -> V_321 - V_340 ;
if ( V_317 -> V_320 != V_287 ) {
F_178 ( V_1 -> V_73 , L_95
L_96
L_97 , V_287 , V_317 -> V_320 ) ;
V_287 = F_132 ( V_317 -> V_320 , V_287 ) ;
}
if ( V_317 -> V_319 < V_287 * 2 ) {
F_178 ( V_1 -> V_73 , L_98
L_99
L_100 , V_317 -> V_319 , V_287 ) ;
V_287 = V_317 -> V_319 / 2 ;
}
if ( V_287 > V_341 ) {
F_178 ( V_1 -> V_73 , L_101
L_100 , V_341 , V_1 -> V_33 . V_342 ) ;
V_287 = V_341 ;
}
if ( V_317 -> V_322 != 0 || V_317 -> V_319 > V_287 * 2 ) {
F_178 ( V_1 -> V_73 , L_102
L_103 , V_317 -> V_322 , V_317 -> V_319 - V_287 * 2 ) ;
}
V_1 -> V_33 . V_342 = V_287 ;
if ( V_1 -> V_33 . V_342 < V_1 -> V_93 . V_329 ) {
F_178 ( V_1 -> V_73 , L_104
L_105 ,
V_1 -> V_33 . V_342 , V_1 -> V_93 . V_329 ) ;
V_1 -> V_93 . V_329 = V_1 -> V_33 . V_342 ;
}
if ( V_1 -> V_93 . V_329 == 0 ) {
F_34 ( V_1 -> V_73 , L_106
L_107 ) ;
return - V_171 ;
}
return 0 ;
}
static inline void F_179 ( struct V_42 * V_40 , T_2 V_151 ,
T_2 V_343 , unsigned int V_218 ,
unsigned int V_344 )
{
V_40 -> V_46 = ( F_87 ( V_151 ) |
( V_343 < V_345 ? V_165 : 0 ) ) ;
V_40 -> V_157 = ( V_343 < V_345
? V_343
: 0 ) ;
V_40 -> V_295 = V_344 ;
V_40 -> V_218 = V_218 ;
}
static void T_11 F_180 ( struct V_1 * V_1 )
{
struct V_33 * V_7 = & V_1 -> V_33 ;
int V_346 , V_347 , V_348 , V_2 , V_29 ;
T_12 V_344 ;
F_51 ( ( V_1 -> V_48 & ( V_103 | V_49 ) ) == 0 ) ;
V_347 = 0 ;
F_13 (adapter, pidx)
V_347 += F_181 ( & F_46 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_347 == 0 )
V_346 = 0 ;
else {
int V_349 = ( V_1 -> V_93 . V_329 - V_347 ) ;
V_346 = ( V_1 -> V_33 . V_342 - V_349 ) / V_347 ;
if ( V_346 > F_182 () )
V_346 = F_182 () ;
}
V_348 = 0 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_46 ( V_1 , V_2 ) ;
V_10 -> V_82 = V_348 ;
V_10 -> V_32 = F_181 ( & V_10 -> V_11 ) ? V_346 : 1 ;
V_348 += V_10 -> V_32 ;
}
V_7 -> V_287 = V_348 ;
V_344 = 64 ;
for ( V_29 = 0 ; V_29 < V_7 -> V_342 ; V_29 ++ ) {
struct V_81 * V_34 = & V_7 -> V_39 [ V_29 ] ;
struct V_69 * V_70 = & V_7 -> V_83 [ V_29 ] ;
F_179 ( & V_34 -> V_40 , 0 , 0 , 1024 , V_344 ) ;
V_34 -> V_84 . V_218 = 72 ;
V_70 -> V_75 . V_218 = 1024 ;
}
F_179 ( & V_7 -> V_38 , V_164 , 0 , 512 , V_344 ) ;
F_179 ( & V_7 -> V_50 , V_164 , 0 , V_350 + 1 ,
V_344 ) ;
}
static void T_11 F_183 ( struct V_1 * V_1 , int V_291 )
{
int V_150 ;
struct V_9 * V_10 ;
F_51 ( V_291 < V_1 -> V_93 . V_329 ) ;
while ( V_291 < V_1 -> V_33 . V_287 )
F_13 (adapter, i) {
V_10 = F_46 ( V_1 , V_150 ) ;
if ( V_10 -> V_32 > 1 ) {
V_10 -> V_32 -- ;
V_1 -> V_33 . V_287 -- ;
if ( V_1 -> V_33 . V_287 <= V_291 )
break;
}
}
V_291 = 0 ;
F_13 (adapter, i) {
V_10 = F_46 ( V_1 , V_150 ) ;
V_10 -> V_82 = V_291 ;
V_291 += V_10 -> V_32 ;
}
}
static int T_11 F_184 ( struct V_1 * V_1 )
{
int V_150 , V_35 , V_351 , V_352 ;
struct V_353 V_300 [ V_350 ] ;
struct V_33 * V_7 = & V_1 -> V_33 ;
for ( V_150 = 0 ; V_150 < V_350 ; ++ V_150 )
V_300 [ V_150 ] . V_354 = V_150 ;
V_351 = V_7 -> V_342 + V_355 ;
V_352 = V_1 -> V_93 . V_329 + V_355 ;
while ( ( V_35 = F_185 ( V_1 -> V_104 , V_300 , V_351 ) ) >= V_352 )
V_351 = V_35 ;
if ( V_35 == 0 ) {
int V_32 = V_351 - V_355 ;
if ( V_32 < V_7 -> V_342 ) {
F_178 ( V_1 -> V_73 , L_108
L_109 , V_32 ) ;
V_7 -> V_342 = V_32 ;
if ( V_32 < V_7 -> V_287 )
F_183 ( V_1 , V_32 ) ;
}
for ( V_150 = 0 ; V_150 < V_351 ; ++ V_150 )
V_1 -> V_26 [ V_150 ] . V_36 = V_300 [ V_150 ] . V_356 ;
} else if ( V_35 > 0 ) {
F_186 ( V_1 -> V_104 ) ;
F_187 ( V_1 -> V_73 , L_110
L_111 , V_35 ) ;
}
return V_35 ;
}
static int T_11 F_188 ( struct V_357 * V_104 ,
const struct V_358 * V_359 )
{
static int V_360 ;
int V_361 ;
int V_35 , V_2 ;
unsigned int V_324 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_292 ;
if ( V_360 == 0 ) {
F_6 ( V_18 L_112 , V_362 , V_200 ) ;
V_360 = 1 ;
}
V_35 = F_189 ( V_104 ) ;
if ( V_35 ) {
F_34 ( & V_104 -> V_5 , L_113 ) ;
return V_35 ;
}
V_35 = F_190 ( V_104 , V_198 ) ;
if ( V_35 ) {
F_34 ( & V_104 -> V_5 , L_114 ) ;
goto V_363;
}
V_35 = F_191 ( V_104 , F_192 ( 64 ) ) ;
if ( V_35 == 0 ) {
V_35 = F_193 ( V_104 , F_192 ( 64 ) ) ;
if ( V_35 ) {
F_34 ( & V_104 -> V_5 , L_115
L_116 ) ;
goto V_364;
}
V_361 = 1 ;
} else {
V_35 = F_191 ( V_104 , F_192 ( 32 ) ) ;
if ( V_35 != 0 ) {
F_34 ( & V_104 -> V_5 , L_117 ) ;
goto V_364;
}
V_361 = 0 ;
}
F_194 ( V_104 ) ;
V_1 = F_195 ( sizeof( * V_1 ) , V_365 ) ;
if ( ! V_1 ) {
V_35 = - V_366 ;
goto V_364;
}
F_196 ( V_104 , V_1 ) ;
V_1 -> V_104 = V_104 ;
V_1 -> V_73 = & V_104 -> V_5 ;
F_197 ( & V_1 -> V_112 ) ;
V_1 -> V_265 = F_198 ( V_104 , 0 ) ;
if ( ! V_1 -> V_265 ) {
F_34 ( & V_104 -> V_5 , L_118 ) ;
V_35 = - V_366 ;
goto V_367;
}
V_1 -> V_19 = F_101 ( V_104 ) ;
V_1 -> V_206 = V_368 ;
V_35 = F_162 ( V_1 ) ;
if ( V_35 )
goto V_369;
V_324 = V_1 -> V_93 . V_317 . V_324 ;
F_13 (adapter, pidx) {
int V_108 , V_21 ;
if ( V_324 == 0 )
break;
V_108 = F_199 ( V_324 ) - 1 ;
V_324 &= ~ ( 1 << V_108 ) ;
V_21 = F_200 ( V_1 , V_108 ) ;
if ( V_21 < 0 ) {
F_34 ( & V_104 -> V_5 , L_119
L_81 , V_108 , V_21 ) ;
V_35 = V_21 ;
goto V_370;
}
V_292 = F_201 ( sizeof( struct V_9 ) ,
V_91 ) ;
if ( V_292 == NULL ) {
F_202 ( V_1 , V_21 ) ;
V_35 = - V_366 ;
goto V_370;
}
V_1 -> V_6 [ V_2 ] = V_292 ;
F_203 ( V_292 , & V_104 -> V_5 ) ;
V_10 = F_4 ( V_292 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_108 = V_108 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_23 = - 1 ;
F_7 ( V_292 ) ;
V_292 -> V_105 = V_104 -> V_105 ;
V_292 -> V_371 = V_372 | V_373 |
V_374 | V_375 |
V_173 | V_376 ;
V_292 -> V_377 = V_372 | V_373 |
V_374 | V_375 |
V_378 ;
V_292 -> V_172 = V_292 -> V_371 | V_174 ;
if ( V_361 )
V_292 -> V_172 |= V_378 ;
V_292 -> V_379 |= V_380 ;
V_292 -> V_381 = & V_382 ;
F_204 ( V_292 , & V_383 ) ;
V_35 = F_205 ( V_1 , V_2 ) ;
if ( V_35 ) {
F_34 ( & V_104 -> V_5 , L_120 ,
V_2 ) ;
goto V_370;
}
}
F_13 (adapter, pidx) {
V_292 = V_1 -> V_6 [ V_2 ] ;
if ( V_292 == NULL )
continue;
V_35 = F_206 ( V_292 ) ;
if ( V_35 ) {
F_178 ( & V_104 -> V_5 , L_121
L_122 , V_292 -> V_19 ) ;
continue;
}
F_59 ( V_2 , & V_1 -> V_384 ) ;
}
if ( V_1 -> V_384 == 0 ) {
F_34 ( & V_104 -> V_5 , L_123 ) ;
goto V_370;
}
if ( ! F_159 ( V_385 ) ) {
V_1 -> V_331 =
F_207 ( F_101 ( V_104 ) ,
V_385 ) ;
if ( F_159 ( V_1 -> V_331 ) )
F_178 ( & V_104 -> V_5 , L_124
L_125 ) ;
else
F_158 ( V_1 ) ;
}
if ( V_30 == V_386 && F_184 ( V_1 ) == 0 )
V_1 -> V_48 |= V_103 ;
else {
V_35 = F_208 ( V_104 ) ;
if ( V_35 ) {
F_34 ( & V_104 -> V_5 , L_126
L_81 ,
V_30 == V_386 ? L_127 : L_128 , V_35 ) ;
goto V_387;
}
V_1 -> V_48 |= V_49 ;
}
F_180 ( V_1 ) ;
F_13 (adapter, pidx) {
F_187 ( V_1 -> V_73 , L_129 ,
V_1 -> V_6 [ V_2 ] -> V_19 ,
( V_1 -> V_48 & V_103 ) ? L_130 :
( V_1 -> V_48 & V_49 ) ? L_128 : L_131 ) ;
}
return 0 ;
V_387:
if ( ! F_159 ( V_1 -> V_331 ) ) {
F_161 ( V_1 ) ;
F_209 ( V_1 -> V_331 ) ;
}
V_370:
F_13 (adapter, pidx) {
V_292 = V_1 -> V_6 [ V_2 ] ;
if ( V_292 == NULL )
continue;
V_10 = F_4 ( V_292 ) ;
F_202 ( V_1 , V_10 -> V_21 ) ;
if ( F_210 ( V_2 , & V_1 -> V_384 ) )
F_211 ( V_292 ) ;
F_212 ( V_292 ) ;
}
V_369:
F_213 ( V_1 -> V_265 ) ;
V_367:
F_214 ( V_1 ) ;
F_196 ( V_104 , NULL ) ;
V_364:
F_215 ( V_104 ) ;
F_196 ( V_104 , NULL ) ;
F_216 ( V_104 ) ;
V_363:
F_217 ( V_104 ) ;
return V_35 ;
}
static void T_13 F_218 ( struct V_357 * V_104 )
{
struct V_1 * V_1 = F_219 ( V_104 ) ;
if ( V_1 ) {
int V_2 ;
F_13 (adapter, pidx)
if ( F_210 ( V_2 , & V_1 -> V_384 ) )
F_211 ( V_1 -> V_6 [ V_2 ] ) ;
F_220 ( V_1 ) ;
if ( V_1 -> V_48 & V_103 ) {
F_186 ( V_1 -> V_104 ) ;
V_1 -> V_48 &= ~ V_103 ;
} else if ( V_1 -> V_48 & V_49 ) {
F_221 ( V_1 -> V_104 ) ;
V_1 -> V_48 &= ~ V_49 ;
}
if ( ! F_159 ( V_1 -> V_331 ) ) {
F_161 ( V_1 ) ;
F_209 ( V_1 -> V_331 ) ;
}
F_44 ( V_1 ) ;
F_13 (adapter, pidx) {
struct V_4 * V_292 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_292 == NULL )
continue;
V_10 = F_4 ( V_292 ) ;
F_202 ( V_1 , V_10 -> V_21 ) ;
F_212 ( V_292 ) ;
}
F_213 ( V_1 -> V_265 ) ;
F_214 ( V_1 ) ;
F_196 ( V_104 , NULL ) ;
}
F_217 ( V_104 ) ;
F_216 ( V_104 ) ;
F_215 ( V_104 ) ;
}
static void T_13 F_222 ( struct V_357 * V_104 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_219 ( V_104 ) ;
if ( ! V_1 )
return;
F_13 (adapter, pidx) {
struct V_4 * V_292 ;
struct V_9 * V_10 ;
if ( ! F_210 ( V_2 , & V_1 -> V_384 ) )
continue;
V_292 = V_1 -> V_6 [ V_2 ] ;
if ( ! V_292 )
continue;
V_10 = F_4 ( V_292 ) ;
F_11 ( V_1 , V_10 -> V_21 , false , false ) ;
}
F_44 ( V_1 ) ;
}
static int T_14 F_223 ( void )
{
int V_20 ;
if ( V_30 != V_386 && V_30 != V_388 ) {
F_6 (KERN_WARNING KBUILD_MODNAME
L_132
L_133 ,
msi, MSI_MSIX, MSI_MSI) ;
return - V_171 ;
}
V_385 = F_207 ( V_198 , NULL ) ;
if ( F_159 ( V_385 ) )
F_6 (KERN_WARNING KBUILD_MODNAME L_134
L_135 ) ;
V_20 = F_224 ( & V_389 ) ;
if ( V_20 < 0 && ! F_159 ( V_385 ) )
F_225 ( V_385 ) ;
return V_20 ;
}
static void T_15 F_226 ( void )
{
F_227 ( & V_389 ) ;
F_225 ( V_385 ) ;
}
