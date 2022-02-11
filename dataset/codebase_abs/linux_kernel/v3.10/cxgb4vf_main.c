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
F_6 ( V_5 , L_9 , V_7 , V_8 ) ;
} else {
F_7 ( V_5 ) ;
F_6 ( V_5 , L_10 ) ;
}
}
static int F_8 ( struct V_4 * V_5 )
{
int V_18 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_18 = F_9 ( V_10 -> V_1 , V_10 -> V_19 , V_5 -> V_20 , - 1 , - 1 , - 1 , 1 ,
true ) ;
if ( V_18 == 0 ) {
V_18 = F_10 ( V_10 -> V_1 , V_10 -> V_19 ,
V_10 -> V_21 , V_5 -> V_22 , true ) ;
if ( V_18 >= 0 ) {
V_10 -> V_21 = V_18 ;
V_18 = 0 ;
}
}
if ( V_18 == 0 )
V_18 = F_11 ( V_10 -> V_1 , V_10 -> V_19 , true , true ) ;
return V_18 ;
}
static void F_12 ( struct V_1 * V_1 )
{
int V_23 = sizeof( V_1 -> V_24 [ 0 ] . V_25 ) - 1 ;
int V_2 ;
snprintf ( V_1 -> V_24 [ V_26 ] . V_25 , V_23 ,
L_11 , V_1 -> V_27 ) ;
V_1 -> V_24 [ V_26 ] . V_25 [ V_23 ] = 0 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
int V_28 , V_29 ;
for ( V_28 = 0 , V_29 = V_30 ; V_28 < V_10 -> V_31 ; V_28 ++ , V_29 ++ ) {
snprintf ( V_1 -> V_24 [ V_29 ] . V_25 , V_23 ,
L_12 , V_5 -> V_27 , V_28 ) ;
V_1 -> V_24 [ V_29 ] . V_25 [ V_23 ] = 0 ;
}
}
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_33 , V_29 , V_34 ;
V_34 = F_15 ( V_1 -> V_24 [ V_26 ] . V_35 , V_36 ,
0 , V_1 -> V_24 [ V_26 ] . V_25 , & V_7 -> V_37 ) ;
if ( V_34 )
return V_34 ;
V_29 = V_30 ;
F_16 (s, rxq) {
V_34 = F_15 ( V_1 -> V_24 [ V_29 ] . V_35 ,
V_36 , 0 ,
V_1 -> V_24 [ V_29 ] . V_25 ,
& V_7 -> V_38 [ V_33 ] . V_39 ) ;
if ( V_34 )
goto V_40;
V_29 ++ ;
}
return 0 ;
V_40:
while ( -- V_33 >= 0 )
F_17 ( V_1 -> V_24 [ -- V_29 ] . V_35 , & V_7 -> V_38 [ V_33 ] . V_39 ) ;
F_17 ( V_1 -> V_24 [ V_26 ] . V_35 , & V_7 -> V_37 ) ;
return V_34 ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_33 , V_29 ;
F_17 ( V_1 -> V_24 [ V_26 ] . V_35 , & V_7 -> V_37 ) ;
V_29 = V_30 ;
F_16 (s, rxq)
F_17 ( V_1 -> V_24 [ V_29 ++ ] . V_35 ,
& V_7 -> V_38 [ V_33 ] . V_39 ) ;
}
static void F_19 ( struct V_41 * V_39 )
{
F_20 ( & V_39 -> V_42 ) ;
F_21 ( V_39 -> V_1 , V_43 + V_44 ,
F_22 ( 0 ) |
F_23 ( V_39 -> V_45 ) |
F_24 ( V_39 -> V_46 ) ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
int V_33 ;
struct V_32 * V_7 = & V_1 -> V_32 ;
F_16 (s, rxq)
F_19 ( & V_7 -> V_38 [ V_33 ] . V_39 ) ;
F_19 ( & V_7 -> V_37 ) ;
if ( V_1 -> V_47 & V_48 )
F_21 ( V_1 , V_43 + V_44 ,
F_22 ( 0 ) |
F_23 ( V_7 -> V_49 . V_45 ) |
F_24 ( V_7 -> V_49 . V_46 ) ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_33 ;
F_16 (s, rxq)
F_27 ( & V_7 -> V_38 [ V_33 ] . V_39 . V_42 ) ;
F_27 ( & V_7 -> V_37 . V_42 ) ;
}
static int F_28 ( struct V_41 * V_39 , const T_1 * V_50 ,
const struct V_51 * V_52 )
{
struct V_1 * V_1 = V_39 -> V_1 ;
T_2 V_53 = ( ( const struct V_54 * ) V_50 ) -> V_53 ;
void * V_55 = ( void * ) ( V_50 + 1 ) ;
switch ( V_53 ) {
case V_56 : {
const struct V_57 * V_58 = V_55 ;
if ( V_58 -> type == V_59 )
F_29 ( V_1 , V_58 -> V_60 ) ;
break;
}
case V_61 : {
const struct V_62 * V_63 = ( void * ) ( V_50 + 3 ) ;
V_53 = F_30 ( F_31 ( V_63 -> V_64 ) ) ;
if ( V_53 != V_65 ) {
F_32 ( V_1 -> V_66 , L_13
, V_53 ) ;
break;
}
V_55 = ( void * ) V_63 ;
}
case V_65 : {
const struct V_62 * V_63 = V_55 ;
unsigned int V_67 = F_33 ( F_34 ( V_63 -> V_64 ) ) ;
struct V_32 * V_7 = & V_1 -> V_32 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
unsigned int V_72 ;
V_72 = F_35 ( V_7 , V_67 ) ;
if ( F_36 ( V_72 >= V_73 ) ) {
F_32 ( V_1 -> V_66 ,
L_14 , V_67 ) ;
break;
}
V_69 = V_7 -> V_74 [ V_72 ] ;
if ( F_36 ( V_69 == NULL ) ) {
F_32 ( V_1 -> V_66 ,
L_15 , V_67 ) ;
break;
}
V_71 = F_37 ( V_69 , struct V_70 , V_75 ) ;
if ( F_36 ( V_69 -> V_76 != V_67 ) ) {
F_32 ( V_1 -> V_66 ,
L_16 ,
V_67 , V_69 -> V_76 ) ;
break;
}
V_71 -> V_75 . V_77 ++ ;
F_38 ( V_71 -> V_71 ) ;
break;
}
default:
F_32 ( V_1 -> V_66 ,
L_17 , V_53 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_34 , V_2 , V_78 ;
F_40 ( V_7 -> V_79 , V_73 ) ;
if ( V_1 -> V_47 & V_48 ) {
V_34 = F_41 ( V_1 , & V_7 -> V_49 , false ,
V_1 -> V_6 [ 0 ] , 0 , NULL , NULL ) ;
if ( V_34 )
goto V_80;
}
V_34 = F_41 ( V_1 , & V_7 -> V_37 , true , V_1 -> V_6 [ 0 ] ,
V_26 , NULL , F_28 ) ;
if ( V_34 )
goto V_80;
V_78 = V_30 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_81 * V_33 = & V_7 -> V_38 [ V_10 -> V_82 ] ;
struct V_70 * V_71 = & V_7 -> V_83 [ V_10 -> V_82 ] ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ , V_33 ++ , V_71 ++ ) {
V_34 = F_41 ( V_1 , & V_33 -> V_39 , false ,
V_5 , V_78 ++ ,
& V_33 -> V_84 , V_85 ) ;
if ( V_34 )
goto V_80;
V_34 = F_42 ( V_1 , V_71 , V_5 ,
F_43 ( V_5 , V_28 ) ,
V_7 -> V_37 . V_46 ) ;
if ( V_34 )
goto V_80;
V_33 -> V_39 . V_86 = V_28 ;
memset ( & V_33 -> V_87 , 0 , sizeof( V_33 -> V_87 ) ) ;
}
}
V_7 -> V_88 = V_7 -> V_83 [ 0 ] . V_75 . V_76 - V_7 -> V_83 [ 0 ] . V_75 . V_46 ;
V_7 -> V_89 = V_7 -> V_38 [ 0 ] . V_39 . V_76 - V_7 -> V_38 [ 0 ] . V_39 . V_46 ;
F_44 ( V_7 , V_7 -> V_37 . V_76 ) = & V_7 -> V_37 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_81 * V_33 = & V_7 -> V_38 [ V_10 -> V_82 ] ;
struct V_70 * V_71 = & V_7 -> V_83 [ V_10 -> V_82 ] ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ , V_33 ++ , V_71 ++ ) {
F_44 ( V_7 , V_33 -> V_39 . V_76 ) = & V_33 -> V_39 ;
F_45 ( V_7 , V_71 -> V_75 . V_76 ) = & V_71 -> V_75 ;
V_33 -> V_84 . V_76 = V_33 -> V_84 . V_46 + V_7 -> V_88 ;
F_45 ( V_7 , V_33 -> V_84 . V_76 ) = & V_33 -> V_84 ;
}
}
return 0 ;
V_80:
F_46 ( V_1 ) ;
return V_34 ;
}
static int F_47 ( struct V_1 * V_1 )
{
int V_2 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_48 ( V_1 , V_2 ) ;
struct V_81 * V_33 = & V_1 -> V_32 . V_38 [ V_10 -> V_82 ] ;
T_3 V_90 [ V_91 ] ;
int V_28 , V_34 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ )
V_90 [ V_28 ] = V_33 [ V_28 ] . V_39 . V_76 ;
V_34 = F_49 ( V_1 , V_10 -> V_19 ,
0 , V_10 -> V_92 , V_90 , V_10 -> V_31 ) ;
if ( V_34 )
return V_34 ;
switch ( V_1 -> V_93 . V_90 . V_94 ) {
case V_95 :
if ( ! V_1 -> V_93 . V_90 . V_96 . V_97 . V_98 ) {
union V_99 V_100 ;
V_34 = F_50 ( V_1 ,
V_10 -> V_19 ,
& V_100 ) ;
if ( V_34 )
return V_34 ;
V_100 . V_97 . V_101 =
V_33 [ 0 ] . V_39 . V_76 ;
V_34 = F_51 ( V_1 ,
V_10 -> V_19 ,
& V_100 ) ;
if ( V_34 )
return V_34 ;
}
break;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_1 )
{
int V_34 ;
if ( ( V_1 -> V_47 & V_102 ) == 0 ) {
V_34 = F_39 ( V_1 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_47 ( V_1 ) ;
if ( V_34 ) {
F_46 ( V_1 ) ;
return V_34 ;
}
if ( V_1 -> V_47 & V_103 )
F_12 ( V_1 ) ;
V_1 -> V_47 |= V_102 ;
}
F_53 ( ( V_1 -> V_47 & ( V_103 | V_48 ) ) == 0 ) ;
if ( V_1 -> V_47 & V_103 )
V_34 = F_14 ( V_1 ) ;
else
V_34 = F_15 ( V_1 -> V_104 -> V_105 ,
F_54 ( V_1 ) , 0 ,
V_1 -> V_27 , V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_18 ,
V_34 ) ;
return V_34 ;
}
F_25 ( V_1 ) ;
F_55 ( V_1 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_1 )
{
if ( V_1 -> V_47 & V_103 )
F_18 ( V_1 ) ;
else
F_17 ( V_1 -> V_104 -> V_105 , V_1 ) ;
F_26 ( V_1 ) ;
}
static int F_57 ( struct V_4 * V_5 )
{
int V_34 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_106 == 0 ) {
V_34 = F_52 ( V_1 ) ;
if ( V_34 )
return V_34 ;
}
F_58 ( V_5 , V_10 -> V_31 ) ;
V_34 = F_59 ( V_5 , V_10 -> V_31 ) ;
if ( V_34 )
goto V_107;
V_34 = F_8 ( V_5 ) ;
if ( V_34 )
goto V_107;
F_60 ( V_5 ) ;
F_61 ( V_10 -> V_108 , & V_1 -> V_106 ) ;
return 0 ;
V_107:
if ( V_1 -> V_106 == 0 )
F_56 ( V_1 ) ;
return V_34 ;
}
static int F_62 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
F_63 ( V_5 ) ;
F_7 ( V_5 ) ;
F_11 ( V_1 , V_10 -> V_19 , false , false ) ;
V_10 -> V_11 . V_3 = 0 ;
F_64 ( V_10 -> V_108 , & V_1 -> V_106 ) ;
if ( V_1 -> V_106 == 0 )
F_56 ( V_1 ) ;
return 0 ;
}
static struct V_109 * F_65 ( struct V_4 * V_5 )
{
struct V_110 V_87 ;
struct V_9 * V_10 = F_66 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_109 * V_111 = & V_5 -> V_87 ;
int V_34 ;
F_67 ( & V_1 -> V_112 ) ;
V_34 = F_68 ( V_1 , V_10 -> V_2 , & V_87 ) ;
F_69 ( & V_1 -> V_112 ) ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
if ( V_34 )
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
static inline unsigned int F_70 ( const struct V_4 * V_5 ,
const T_2 * * V_136 ,
unsigned int V_137 ,
unsigned int V_138 )
{
unsigned int V_139 = 0 ;
unsigned int V_140 = 0 ;
const struct V_141 * V_142 ;
F_71 (dev, ha)
if ( V_139 ++ >= V_137 ) {
V_136 [ V_140 ++ ] = V_142 -> V_136 ;
if ( V_140 >= V_138 )
break;
}
return V_140 ;
}
static inline unsigned int F_72 ( const struct V_4 * V_5 ,
const T_2 * * V_136 ,
unsigned int V_137 ,
unsigned int V_138 )
{
unsigned int V_139 = 0 ;
unsigned int V_140 = 0 ;
const struct V_141 * V_142 ;
F_73 (ha, dev)
if ( V_139 ++ >= V_137 ) {
V_136 [ V_140 ++ ] = V_142 -> V_136 ;
if ( V_140 >= V_138 )
break;
}
return V_140 ;
}
static int F_74 ( const struct V_4 * V_5 , bool V_143 )
{
T_4 V_144 = 0 ;
T_4 V_145 = 0 ;
bool free = true ;
unsigned int V_137 , V_140 ;
const T_2 * V_136 [ 7 ] ;
int V_18 ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
for ( V_137 = 0 ; ; V_137 += V_140 ) {
V_140 = F_70 ( V_5 , V_136 , V_137 ,
F_75 ( V_136 ) ) ;
if ( V_140 == 0 )
break;
V_18 = F_76 ( V_10 -> V_1 , V_10 -> V_19 , free ,
V_140 , V_136 , NULL , & V_145 , V_143 ) ;
if ( V_18 < 0 )
return V_18 ;
free = false ;
}
for ( V_137 = 0 ; ; V_137 += V_140 ) {
V_140 = F_72 ( V_5 , V_136 , V_137 ,
F_75 ( V_136 ) ) ;
if ( V_140 == 0 )
break;
V_18 = F_76 ( V_10 -> V_1 , V_10 -> V_19 , free ,
V_140 , V_136 , NULL , & V_144 , V_143 ) ;
if ( V_18 < 0 )
return V_18 ;
free = false ;
}
return F_77 ( V_10 -> V_1 , V_10 -> V_19 , V_145 != 0 ,
V_145 | V_144 , V_143 ) ;
}
static int F_78 ( struct V_4 * V_5 , int V_20 , bool V_146 )
{
int V_18 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_18 = F_74 ( V_5 , V_146 ) ;
if ( V_18 == 0 )
V_18 = F_9 ( V_10 -> V_1 , V_10 -> V_19 , - 1 ,
( V_5 -> V_47 & V_147 ) != 0 ,
( V_5 -> V_47 & V_148 ) != 0 ,
1 , - 1 , V_146 ) ;
return V_18 ;
}
static void F_79 ( struct V_4 * V_5 )
{
F_78 ( V_5 , - 1 , false ) ;
}
static int F_80 ( const struct V_32 * V_7 , int V_149 )
{
int V_150 , V_151 = 0 , V_152 = V_153 ;
for ( V_150 = 0 ; V_150 < F_75 ( V_7 -> V_154 ) ; V_150 ++ ) {
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
static int F_81 ( const struct V_32 * V_7 , int V_156 )
{
int V_150 , V_155 , V_157 = 0 , V_152 = V_153 ;
for ( V_150 = 0 ; V_150 < F_75 ( V_7 -> V_158 ) ; V_150 ++ ) {
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
static unsigned int F_82 ( const struct V_1 * V_1 ,
const struct V_41 * V_39 )
{
unsigned int V_151 = F_83 ( V_39 -> V_45 ) ;
return V_151 < V_159
? V_1 -> V_32 . V_154 [ V_151 ]
: 0 ;
}
static int F_84 ( struct V_1 * V_1 , struct V_41 * V_39 ,
unsigned int V_149 , unsigned int V_160 )
{
unsigned int V_151 ;
if ( ( V_149 | V_160 ) == 0 )
V_160 = 1 ;
if ( V_160 ) {
int V_34 ;
T_5 V_161 , V_157 ;
V_157 = F_81 ( & V_1 -> V_32 , V_160 ) ;
if ( V_39 -> V_25 && V_39 -> V_157 != V_157 ) {
V_161 = F_85 ( V_162 ) |
F_86 (
V_163 ) |
F_87 ( V_39 -> V_46 ) ;
V_34 = F_88 ( V_1 , 1 , & V_161 , & V_157 ) ;
if ( V_34 )
return V_34 ;
}
V_39 -> V_157 = V_157 ;
}
V_151 = ( V_149 == 0
? V_164
: F_80 ( & V_1 -> V_32 , V_149 ) ) ;
V_39 -> V_45 = ( F_89 ( V_151 ) |
( V_160 > 0 ? V_165 : 0 ) ) ;
return 0 ;
}
static inline unsigned int F_90 ( const struct V_1 * V_1 )
{
return F_91 ( V_1 -> V_166 ) | ( 0x3f << 10 ) ;
}
static int F_92 ( struct V_4 * V_5 , struct V_167 * V_168 , int V_169 )
{
int V_18 = 0 ;
switch ( V_169 ) {
default:
V_18 = - V_170 ;
break;
}
return V_18 ;
}
static int F_93 ( struct V_4 * V_5 , int V_171 )
{
int V_18 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_171 < 81 )
return - V_172 ;
V_18 = F_9 ( V_10 -> V_1 , V_10 -> V_19 , V_171 ,
- 1 , - 1 , - 1 , - 1 , true ) ;
if ( ! V_18 )
V_5 -> V_20 = V_171 ;
return V_18 ;
}
static T_6 F_94 ( struct V_4 * V_5 ,
T_6 V_173 )
{
if ( V_173 & V_174 )
V_173 |= V_175 ;
else
V_173 &= ~ V_175 ;
return V_173 ;
}
static int F_95 ( struct V_4 * V_5 ,
T_6 V_173 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
T_6 V_176 = V_5 -> V_173 ^ V_173 ;
if ( V_176 & V_174 )
F_9 ( V_10 -> V_1 , V_10 -> V_19 , - 1 , - 1 , - 1 , - 1 ,
V_173 & V_175 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_4 * V_5 , void * V_177 )
{
int V_18 ;
struct V_178 * V_136 = V_177 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! F_97 ( V_136 -> V_179 ) )
return - V_180 ;
V_18 = F_10 ( V_10 -> V_1 , V_10 -> V_19 , V_10 -> V_21 ,
V_136 -> V_179 , true ) ;
if ( V_18 < 0 )
return V_18 ;
memcpy ( V_5 -> V_22 , V_136 -> V_179 , V_5 -> V_181 ) ;
V_10 -> V_21 = V_18 ;
return 0 ;
}
static void F_98 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_47 & V_103 ) {
struct V_81 * V_33 ;
int V_31 ;
V_33 = & V_1 -> V_32 . V_38 [ V_10 -> V_82 ] ;
for ( V_31 = V_10 -> V_31 ; V_31 ; V_31 -- ) {
V_36 ( 0 , & V_33 -> V_39 ) ;
V_33 ++ ;
}
} else
F_54 ( V_1 ) ( 0 , V_1 ) ;
}
static int F_99 ( struct V_4 * V_5 ,
struct V_182 * V_169 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
V_169 -> V_183 = V_10 -> V_11 . V_183 ;
V_169 -> V_184 = V_10 -> V_11 . V_184 ;
F_100 ( V_169 ,
F_3 ( V_5 ) ? V_10 -> V_11 . V_12 : - 1 ) ;
V_169 -> V_185 = V_186 ;
V_169 -> V_6 = ( V_169 -> V_183 & V_187 ) ? V_188 : V_189 ;
V_169 -> V_190 = V_10 -> V_108 ;
V_169 -> V_191 = V_192 ;
V_169 -> V_193 = V_10 -> V_11 . V_193 ;
V_169 -> V_194 = 0 ;
V_169 -> V_195 = 0 ;
return 0 ;
}
static void F_101 ( struct V_4 * V_5 ,
struct V_196 * V_197 )
{
struct V_1 * V_1 = F_102 ( V_5 ) ;
F_103 ( V_197 -> V_198 , V_199 , sizeof( V_197 -> V_198 ) ) ;
F_103 ( V_197 -> V_200 , V_201 , sizeof( V_197 -> V_200 ) ) ;
F_103 ( V_197 -> V_202 , F_104 ( F_105 ( V_5 -> V_5 . V_203 ) ) ,
sizeof( V_197 -> V_202 ) ) ;
snprintf ( V_197 -> V_204 , sizeof( V_197 -> V_204 ) ,
L_19 ,
F_106 ( V_1 -> V_93 . V_5 . V_205 ) ,
F_107 ( V_1 -> V_93 . V_5 . V_205 ) ,
F_108 ( V_1 -> V_93 . V_5 . V_205 ) ,
F_109 ( V_1 -> V_93 . V_5 . V_205 ) ,
F_106 ( V_1 -> V_93 . V_5 . V_206 ) ,
F_107 ( V_1 -> V_93 . V_5 . V_206 ) ,
F_108 ( V_1 -> V_93 . V_5 . V_206 ) ,
F_109 ( V_1 -> V_93 . V_5 . V_206 ) ) ;
}
static T_5 F_110 ( struct V_4 * V_5 )
{
return F_102 ( V_5 ) -> V_207 ;
}
static void F_111 ( struct V_4 * V_5 , T_5 V_208 )
{
F_102 ( V_5 ) -> V_207 = V_208 ;
}
static void F_112 ( struct V_4 * V_5 ,
struct V_209 * V_210 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_32 * V_7 = & V_10 -> V_1 -> V_32 ;
V_210 -> V_211 = V_212 ;
V_210 -> V_213 = V_214 ;
V_210 -> V_215 = 0 ;
V_210 -> V_216 = V_217 ;
V_210 -> V_218 = V_7 -> V_38 [ V_10 -> V_82 ] . V_84 . V_219 - V_220 ;
V_210 -> V_221 = V_7 -> V_38 [ V_10 -> V_82 ] . V_39 . V_219 ;
V_210 -> V_222 = 0 ;
V_210 -> V_223 = V_7 -> V_83 [ V_10 -> V_82 ] . V_75 . V_219 ;
}
static int F_113 ( struct V_4 * V_5 ,
struct V_209 * V_210 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_28 ;
if ( V_210 -> V_218 > V_212 ||
V_210 -> V_222 ||
V_210 -> V_223 > V_217 ||
V_210 -> V_221 > V_214 ||
V_210 -> V_221 < V_224 ||
V_210 -> V_218 < V_225 ||
V_210 -> V_223 < V_226 )
return - V_172 ;
if ( V_1 -> V_47 & V_102 )
return - V_227 ;
for ( V_28 = V_10 -> V_82 ; V_28 < V_10 -> V_82 + V_10 -> V_31 ; V_28 ++ ) {
V_7 -> V_38 [ V_28 ] . V_84 . V_219 = V_210 -> V_218 + V_220 ;
V_7 -> V_38 [ V_28 ] . V_39 . V_219 = V_210 -> V_221 ;
V_7 -> V_83 [ V_28 ] . V_75 . V_219 = V_210 -> V_223 ;
}
return 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_228 * V_229 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_41 * V_39 = & V_1 -> V_32 . V_38 [ V_10 -> V_82 ] . V_39 ;
V_229 -> V_230 = F_82 ( V_1 , V_39 ) ;
V_229 -> V_231 =
( ( V_39 -> V_45 & V_165 )
? V_1 -> V_32 . V_158 [ V_39 -> V_157 ]
: 0 ) ;
return 0 ;
}
static int F_115 ( struct V_4 * V_5 ,
struct V_228 * V_229 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_84 ( V_1 ,
& V_1 -> V_32 . V_38 [ V_10 -> V_82 ] . V_39 ,
V_229 -> V_230 ,
V_229 -> V_231 ) ;
}
static void F_116 ( struct V_4 * V_5 ,
struct V_232 * V_233 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_233 -> V_193 = ( V_10 -> V_11 . V_234 & V_235 ) != 0 ;
V_233 -> V_236 = ( V_10 -> V_11 . V_8 & V_16 ) != 0 ;
V_233 -> V_237 = ( V_10 -> V_11 . V_8 & V_17 ) != 0 ;
}
static int F_117 ( struct V_4 * V_5 ,
enum V_238 V_239 )
{
unsigned int V_240 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_239 == V_241 )
V_240 = 0xffff ;
else if ( V_239 == V_242 )
V_240 = 0 ;
else
return - V_172 ;
return F_118 ( V_10 -> V_1 , V_10 -> V_19 , V_240 ) ;
}
static int F_119 ( struct V_4 * V_5 , int V_243 )
{
switch ( V_243 ) {
case V_244 :
return F_75 ( V_245 ) ;
default:
return - V_170 ;
}
}
static void F_120 ( struct V_4 * V_5 ,
T_5 V_243 ,
T_2 * V_60 )
{
switch ( V_243 ) {
case V_244 :
memcpy ( V_60 , V_245 , sizeof( V_245 ) ) ;
break;
}
}
static void F_121 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_246 * V_87 )
{
const struct V_70 * V_71 = & V_1 -> V_32 . V_83 [ V_10 -> V_82 ] ;
const struct V_81 * V_33 = & V_1 -> V_32 . V_38 [ V_10 -> V_82 ] ;
int V_28 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ , V_33 ++ , V_71 ++ ) {
V_87 -> V_247 += V_71 -> V_247 ;
V_87 -> V_248 += V_71 -> V_249 ;
V_87 -> V_250 += V_33 -> V_87 . V_251 ;
V_87 -> V_252 += V_33 -> V_87 . V_252 ;
V_87 -> V_253 += V_71 -> V_253 ;
V_87 -> V_254 += V_33 -> V_87 . V_254 ;
V_87 -> V_255 += V_33 -> V_87 . V_255 ;
}
}
static void F_122 ( struct V_4 * V_5 ,
struct V_256 * V_87 ,
T_4 * V_60 )
{
struct V_9 * V_10 = F_66 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_34 = F_68 ( V_1 , V_10 -> V_2 ,
(struct V_110 * ) V_60 ) ;
if ( V_34 )
memset ( V_60 , 0 , sizeof( struct V_110 ) ) ;
V_60 += sizeof( struct V_110 ) / sizeof( T_4 ) ;
F_121 ( V_1 , V_10 , (struct V_246 * ) V_60 ) ;
}
static int F_123 ( struct V_4 * V_5 )
{
return V_257 ;
}
static void F_124 ( struct V_1 * V_1 , void * V_258 ,
unsigned int V_259 , unsigned int V_260 )
{
T_5 * V_261 = V_258 + V_259 - V_262 ;
for ( ; V_259 <= V_260 ; V_259 += sizeof( T_5 ) ) {
if ( V_259 == V_263 + V_264 )
* V_261 ++ = 0xffff ;
else
* V_261 ++ = F_125 ( V_1 , V_259 ) ;
}
}
static void F_126 ( struct V_4 * V_5 ,
struct V_265 * V_266 ,
void * V_258 )
{
struct V_1 * V_1 = F_102 ( V_5 ) ;
V_266 -> V_200 = F_90 ( V_1 ) ;
memset ( V_258 , 0 , V_257 ) ;
F_124 ( V_1 , V_258 ,
V_43 + V_267 ,
V_43 + V_268 ) ;
F_124 ( V_1 , V_258 ,
V_269 + V_270 ,
V_269 + V_271 ) ;
F_124 ( V_1 , V_258 ,
V_272 + V_273 ,
V_272 + V_274 ) ;
F_124 ( V_1 , V_258 ,
V_263 + V_275 ,
V_263 + V_276 ) ;
F_124 ( V_1 , V_258 ,
V_277 + V_278 ,
V_277 + V_279 ) ;
}
static void F_127 ( struct V_4 * V_5 ,
struct V_280 * V_281 )
{
V_281 -> V_183 = 0 ;
V_281 -> V_282 = 0 ;
memset ( & V_281 -> V_283 , 0 , sizeof( V_281 -> V_283 ) ) ;
}
static int F_128 ( struct V_284 * V_285 , void * V_161 )
{
struct V_1 * V_1 = V_285 -> V_286 ;
int V_287 = F_129 ( V_1 -> V_32 . V_288 , V_289 ) ;
int V_28 , V_290 = ( V_291 ) V_161 - 1 ;
if ( V_290 )
F_130 ( V_285 , '\n' ) ;
#define F_131 ( T_7 , V_7 , V_161 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_132 ( V_7 , V_161 ) S3("s", s, v)
#define F_133 ( V_7 , V_161 ) S3("u", s, txq[qs].v)
#define F_134 ( V_7 , V_161 ) S3("u", s, rxq[qs].v)
if ( V_290 < V_287 ) {
const struct V_81 * V_33 = & V_1 -> V_32 . V_38 [ V_290 * V_289 ] ;
const struct V_70 * V_71 = & V_1 -> V_32 . V_83 [ V_290 * V_289 ] ;
int V_292 = F_135 ( V_289 , V_1 -> V_32 . V_288 - V_289 * V_290 ) ;
F_132 ( L_20 , L_21 ) ;
F_132 ( L_22 ,
( V_33 [ V_28 ] . V_39 . V_293
? V_33 [ V_28 ] . V_39 . V_293 -> V_27
: L_23 ) ) ;
F_131 ( L_24 , L_25 ,
( V_33 [ V_28 ] . V_39 . V_293
? ( (struct V_9 * )
F_4 ( V_33 [ V_28 ] . V_39 . V_293 ) ) -> V_108
: - 1 ) ) ;
F_133 ( L_26 , V_75 . V_76 ) ;
F_133 ( L_27 , V_75 . V_219 ) ;
F_133 ( L_28 , V_75 . V_294 ) ;
F_133 ( L_29 , V_75 . V_2 ) ;
F_133 ( L_30 , V_75 . V_295 ) ;
F_134 ( L_31 , V_39 . V_76 ) ;
F_134 ( L_32 , V_39 . V_219 ) ;
F_134 ( L_33 , V_39 . V_296 ) ;
F_131 ( L_34 , L_35 , F_82 ( V_1 , & V_33 [ V_28 ] . V_39 ) ) ;
F_131 ( L_34 , L_36 ,
V_1 -> V_32 . V_158 [ V_33 [ V_28 ] . V_39 . V_157 ] ) ;
F_134 ( L_37 , V_39 . V_295 ) ;
F_134 ( L_38 , V_39 . V_297 ) ;
F_134 ( L_39 , V_84 . V_76 ) ;
F_134 ( L_40 , V_84 . V_219 - V_220 ) ;
F_134 ( L_41 , V_84 . V_298 ) ;
F_134 ( L_42 , V_84 . V_2 ) ;
F_134 ( L_43 , V_84 . V_295 ) ;
return 0 ;
}
V_290 -= V_287 ;
if ( V_290 == 0 ) {
const struct V_41 * V_299 = & V_1 -> V_32 . V_37 ;
F_136 ( V_285 , L_44 , L_20 , L_45 ) ;
F_136 ( V_285 , L_46 , L_31 , V_299 -> V_76 ) ;
F_136 ( V_285 , L_46 , L_35 ,
F_82 ( V_1 , V_299 ) ) ;
F_136 ( V_285 , L_46 , L_36 ,
V_1 -> V_32 . V_158 [ V_299 -> V_157 ] ) ;
F_136 ( V_285 , L_46 , L_47 , V_299 -> V_295 ) ;
F_136 ( V_285 , L_46 , L_38 , V_299 -> V_297 ) ;
} else if ( V_290 == 1 ) {
const struct V_41 * V_49 = & V_1 -> V_32 . V_49 ;
F_136 ( V_285 , L_44 , L_20 , L_48 ) ;
F_136 ( V_285 , L_46 , L_31 , V_49 -> V_76 ) ;
F_136 ( V_285 , L_46 , L_35 ,
F_82 ( V_1 , V_49 ) ) ;
F_136 ( V_285 , L_46 , L_36 ,
V_1 -> V_32 . V_158 [ V_49 -> V_157 ] ) ;
F_136 ( V_285 , L_46 , L_47 , V_49 -> V_295 ) ;
F_136 ( V_285 , L_46 , L_38 , V_49 -> V_297 ) ;
}
#undef F_134
#undef F_133
#undef F_132
#undef F_131
return 0 ;
}
static int F_137 ( const struct V_1 * V_1 )
{
return F_129 ( V_1 -> V_32 . V_288 , V_289 ) + 1 +
( ( V_1 -> V_47 & V_48 ) != 0 ) ;
}
static void * F_138 ( struct V_284 * V_285 , T_8 * V_300 )
{
int V_301 = F_137 ( V_285 -> V_286 ) ;
return * V_300 < V_301 ? ( void * ) ( ( V_291 ) * V_300 + 1 ) : NULL ;
}
static void F_139 ( struct V_284 * V_285 , void * V_161 )
{
}
static void * F_140 ( struct V_284 * V_285 , void * V_161 , T_8 * V_300 )
{
int V_301 = F_137 ( V_285 -> V_286 ) ;
++ * V_300 ;
return * V_300 < V_301 ? ( void * ) ( ( V_291 ) * V_300 + 1 ) : NULL ;
}
static int F_141 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
int V_304 = F_142 ( V_303 , & V_305 ) ;
if ( ! V_304 ) {
struct V_284 * V_285 = V_303 -> V_306 ;
V_285 -> V_286 = V_302 -> V_307 ;
}
return V_304 ;
}
static int F_143 ( struct V_284 * V_285 , void * V_161 )
{
struct V_1 * V_1 = V_285 -> V_286 ;
int V_287 = F_129 ( V_1 -> V_32 . V_288 , V_289 ) ;
int V_28 , V_290 = ( V_291 ) V_161 - 1 ;
if ( V_290 )
F_130 ( V_285 , '\n' ) ;
#define F_131 ( T_9 , V_7 , V_161 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_132 ( V_7 , V_161 ) S3("s", s, v)
#define F_144 ( T_9 , V_7 , V_161 ) S3(fmt, s, txq[qs].v)
#define F_133 ( V_7 , V_161 ) T3("lu", s, v)
#define F_145 ( T_9 , V_7 , V_161 ) S3(fmt, s, rxq[qs].v)
#define F_134 ( V_7 , V_161 ) R3("lu", s, v)
if ( V_290 < V_287 ) {
const struct V_81 * V_33 = & V_1 -> V_32 . V_38 [ V_290 * V_289 ] ;
const struct V_70 * V_71 = & V_1 -> V_32 . V_83 [ V_290 * V_289 ] ;
int V_292 = F_135 ( V_289 , V_1 -> V_32 . V_288 - V_289 * V_290 ) ;
F_132 ( L_20 , L_21 ) ;
F_132 ( L_22 ,
( V_33 [ V_28 ] . V_39 . V_293
? V_33 [ V_28 ] . V_39 . V_293 -> V_27
: L_23 ) ) ;
F_145 ( L_34 , L_49 , V_39 . V_308 ) ;
F_134 ( L_50 , V_87 . V_309 ) ;
F_134 ( L_51 , V_87 . V_251 ) ;
F_134 ( L_52 , V_87 . V_252 ) ;
F_134 ( L_53 , V_87 . V_255 ) ;
F_134 ( L_54 , V_87 . V_254 ) ;
F_134 ( L_55 , V_87 . V_310 ) ;
F_133 ( L_56 , V_247 ) ;
F_133 ( L_57 , V_249 ) ;
F_133 ( L_58 , V_253 ) ;
F_133 ( L_59 , V_75 . V_311 ) ;
F_133 ( L_60 , V_75 . V_77 ) ;
F_133 ( L_61 , V_312 ) ;
F_134 ( L_62 , V_84 . V_313 ) ;
F_134 ( L_63 , V_84 . V_314 ) ;
F_134 ( L_64 , V_84 . V_315 ) ;
return 0 ;
}
V_290 -= V_287 ;
if ( V_290 == 0 ) {
const struct V_41 * V_299 = & V_1 -> V_32 . V_37 ;
F_136 ( V_285 , L_65 , L_20 , L_45 ) ;
F_136 ( V_285 , L_66 , L_49 ,
V_299 -> V_308 ) ;
F_136 ( V_285 , L_66 , L_37 , V_299 -> V_295 ) ;
F_136 ( V_285 , L_66 , L_38 , V_299 -> V_297 ) ;
} else if ( V_290 == 1 ) {
const struct V_41 * V_49 = & V_1 -> V_32 . V_49 ;
F_136 ( V_285 , L_65 , L_20 , L_48 ) ;
F_136 ( V_285 , L_66 , L_49 ,
V_49 -> V_308 ) ;
F_136 ( V_285 , L_66 , L_37 , V_49 -> V_295 ) ;
F_136 ( V_285 , L_66 , L_38 , V_49 -> V_297 ) ;
}
#undef F_134
#undef F_133
#undef F_132
#undef F_145
#undef F_144
#undef F_131
return 0 ;
}
static int F_146 ( const struct V_1 * V_1 )
{
return F_129 ( V_1 -> V_32 . V_288 , V_289 ) + 1 +
( ( V_1 -> V_47 & V_48 ) != 0 ) ;
}
static void * F_147 ( struct V_284 * V_285 , T_8 * V_300 )
{
int V_301 = F_146 ( V_285 -> V_286 ) ;
return * V_300 < V_301 ? ( void * ) ( ( V_291 ) * V_300 + 1 ) : NULL ;
}
static void F_148 ( struct V_284 * V_285 , void * V_161 )
{
}
static void * F_149 ( struct V_284 * V_285 , void * V_161 , T_8 * V_300 )
{
int V_301 = F_146 ( V_285 -> V_286 ) ;
( * V_300 ) ++ ;
return * V_300 < V_301 ? ( void * ) ( ( V_291 ) * V_300 + 1 ) : NULL ;
}
static int F_150 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
int V_304 = F_142 ( V_303 , & V_316 ) ;
if ( V_304 == 0 ) {
struct V_284 * V_285 = V_303 -> V_306 ;
V_285 -> V_286 = V_302 -> V_307 ;
}
return V_304 ;
}
static int F_151 ( struct V_284 * V_285 , void * V_161 )
{
struct V_1 * V_1 = V_285 -> V_286 ;
struct V_317 * V_318 = & V_1 -> V_93 . V_318 ;
#define F_132 ( V_25 , T_9 , T_10 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_132 ( L_67 , L_68 , V_319 ) ;
F_132 ( L_69 , L_68 , V_320 ) ;
F_132 ( L_70 , L_68 , V_321 ) ;
F_132 ( L_71 , L_68 , V_322 ) ;
F_132 ( L_72 , L_68 , V_323 ) ;
F_132 ( L_73 , L_68 , V_324 ) ;
F_132 ( L_74 , L_75 , V_325 ) ;
F_132 ( L_76 , L_68 , V_326 ) ;
F_132 ( L_77 , L_75 , V_327 ) ;
F_132 ( L_78 , L_75 , V_328 ) ;
#undef F_132
return 0 ;
}
static int F_152 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
return F_153 ( V_303 , F_151 , V_302 -> V_307 ) ;
}
static int F_154 ( struct V_284 * V_285 , void * V_161 )
{
if ( V_161 == V_329 ) {
F_155 ( V_285 , L_79 ) ;
} else {
struct V_1 * V_1 = V_285 -> V_286 ;
int V_2 = ( V_291 ) V_161 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_136 ( V_285 , L_80 ,
V_5 -> V_27 , V_10 -> V_108 , V_10 -> V_19 ) ;
}
return 0 ;
}
static inline void * F_156 ( struct V_1 * V_1 , T_8 V_300 )
{
return V_300 <= V_1 -> V_93 . V_330
? ( void * ) ( V_291 ) ( V_300 + 1 )
: NULL ;
}
static void * F_157 ( struct V_284 * V_285 , T_8 * V_300 )
{
return * V_300
? F_156 ( V_285 -> V_286 , * V_300 )
: V_329 ;
}
static void * F_158 ( struct V_284 * V_285 , void * V_161 , T_8 * V_300 )
{
( * V_300 ) ++ ;
return F_156 ( V_285 -> V_286 , * V_300 ) ;
}
static void F_159 ( struct V_284 * V_285 , void * V_161 )
{
}
static int F_160 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
int V_304 = F_142 ( V_303 , & V_331 ) ;
if ( V_304 == 0 ) {
struct V_284 * V_285 = V_303 -> V_306 ;
V_285 -> V_286 = V_302 -> V_307 ;
}
return V_304 ;
}
static int F_161 ( struct V_1 * V_1 )
{
int V_150 ;
F_53 ( F_162 ( V_1 -> V_332 ) ) ;
for ( V_150 = 0 ; V_150 < F_75 ( V_333 ) ; V_150 ++ )
( void ) F_163 ( V_333 [ V_150 ] . V_27 ,
V_333 [ V_150 ] . V_94 ,
V_1 -> V_332 ,
( void * ) V_1 ,
V_333 [ V_150 ] . V_334 ) ;
return 0 ;
}
static void F_164 ( struct V_1 * V_1 )
{
F_53 ( F_162 ( V_1 -> V_332 ) ) ;
}
static int F_165 ( struct V_1 * V_1 )
{
struct V_317 * V_318 = & V_1 -> V_93 . V_318 ;
struct V_335 * V_335 = & V_1 -> V_93 . V_32 ;
struct V_32 * V_7 = & V_1 -> V_32 ;
unsigned int V_288 ;
int V_34 ;
T_5 V_336 , V_240 = 0 ;
V_34 = F_166 ( V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_81
L_82 , V_34 ) ;
return V_34 ;
}
V_34 = F_167 ( V_1 ) ;
if ( V_34 < 0 ) {
F_32 ( V_1 -> V_66 , L_83 , V_34 ) ;
return V_34 ;
}
switch ( V_1 -> V_104 -> V_337 >> 12 ) {
case V_338 :
V_1 -> V_166 = F_168 ( V_338 , 0 ) ;
break;
case V_339 :
V_1 -> V_166 = F_168 ( V_339 , 0 ) ;
break;
}
V_34 = F_169 ( V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_84
L_85 , V_34 ) ;
return V_34 ;
}
V_34 = F_170 ( V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_84
L_86 , V_34 ) ;
return V_34 ;
}
V_34 = F_171 ( V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_84
L_87 , V_34 ) ;
return V_34 ;
}
V_34 = F_172 ( V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_84
L_88 , V_34 ) ;
return V_34 ;
}
if ( V_1 -> V_93 . V_90 . V_94 !=
V_95 ) {
F_32 ( V_1 -> V_66 , L_89
L_90 , V_1 -> V_93 . V_90 . V_94 ) ;
return - V_172 ;
}
V_34 = F_173 ( V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_91
L_82 , V_34 ) ;
return V_34 ;
}
V_336 = F_85 ( V_340 ) |
F_86 ( V_341 ) ;
V_240 = 1 ;
( void ) F_88 ( V_1 , 1 , & V_336 , & V_240 ) ;
V_7 -> V_154 [ 0 ] = F_174 ( V_1 ,
F_175 ( V_335 -> V_342 ) ) ;
V_7 -> V_154 [ 1 ] = F_174 ( V_1 ,
F_176 ( V_335 -> V_342 ) ) ;
V_7 -> V_154 [ 2 ] = F_174 ( V_1 ,
F_175 ( V_335 -> V_343 ) ) ;
V_7 -> V_154 [ 3 ] = F_174 ( V_1 ,
F_176 ( V_335 -> V_343 ) ) ;
V_7 -> V_154 [ 4 ] = F_174 ( V_1 ,
F_175 ( V_335 -> V_344 ) ) ;
V_7 -> V_154 [ 5 ] = F_174 ( V_1 ,
F_176 ( V_335 -> V_344 ) ) ;
V_7 -> V_158 [ 0 ] =
F_177 ( V_335 -> V_345 ) ;
V_7 -> V_158 [ 1 ] =
F_178 ( V_335 -> V_345 ) ;
V_7 -> V_158 [ 2 ] =
F_179 ( V_335 -> V_345 ) ;
V_7 -> V_158 [ 3 ] =
F_180 ( V_335 -> V_345 ) ;
V_34 = F_181 ( V_1 ) ;
if ( V_34 ) {
F_32 ( V_1 -> V_66 , L_92
L_93 , V_34 ) ;
return V_34 ;
}
V_1 -> V_93 . V_330 = V_318 -> V_319 ;
if ( V_1 -> V_93 . V_330 > V_346 ) {
F_182 ( V_1 -> V_66 , L_94
L_95 , V_346 ,
V_1 -> V_93 . V_330 ) ;
V_1 -> V_93 . V_330 = V_346 ;
}
V_288 = V_318 -> V_322 - V_347 ;
if ( V_318 -> V_321 != V_288 ) {
F_182 ( V_1 -> V_66 , L_96
L_97
L_98 , V_288 , V_318 -> V_321 ) ;
V_288 = F_135 ( V_318 -> V_321 , V_288 ) ;
}
if ( V_318 -> V_320 < V_288 * 2 ) {
F_182 ( V_1 -> V_66 , L_99
L_100
L_101 , V_318 -> V_320 , V_288 ) ;
V_288 = V_318 -> V_320 / 2 ;
}
if ( V_288 > V_348 ) {
F_182 ( V_1 -> V_66 , L_102
L_101 , V_348 , V_1 -> V_32 . V_349 ) ;
V_288 = V_348 ;
}
if ( V_318 -> V_323 != 0 || V_318 -> V_320 > V_288 * 2 ) {
F_182 ( V_1 -> V_66 , L_103
L_104 , V_318 -> V_323 , V_318 -> V_320 - V_288 * 2 ) ;
}
V_1 -> V_32 . V_349 = V_288 ;
if ( V_1 -> V_32 . V_349 < V_1 -> V_93 . V_330 ) {
F_182 ( V_1 -> V_66 , L_105
L_106 ,
V_1 -> V_32 . V_349 , V_1 -> V_93 . V_330 ) ;
V_1 -> V_93 . V_330 = V_1 -> V_32 . V_349 ;
}
if ( V_1 -> V_93 . V_330 == 0 ) {
F_32 ( V_1 -> V_66 , L_107
L_108 ) ;
return - V_172 ;
}
return 0 ;
}
static inline void F_183 ( struct V_41 * V_39 , T_2 V_151 ,
T_2 V_350 , unsigned int V_219 ,
unsigned int V_351 )
{
V_39 -> V_45 = ( F_89 ( V_151 ) |
( V_350 < V_352 ? V_165 : 0 ) ) ;
V_39 -> V_157 = ( V_350 < V_352
? V_350
: 0 ) ;
V_39 -> V_296 = V_351 ;
V_39 -> V_219 = V_219 ;
}
static void F_184 ( struct V_1 * V_1 )
{
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_353 , V_354 , V_355 , V_2 , V_28 ;
T_11 V_351 ;
F_53 ( ( V_1 -> V_47 & ( V_103 | V_48 ) ) == 0 ) ;
V_354 = 0 ;
F_13 (adapter, pidx)
V_354 += F_185 ( & F_48 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_354 == 0 )
V_353 = 0 ;
else {
int V_356 = ( V_1 -> V_93 . V_330 - V_354 ) ;
V_353 = ( V_1 -> V_32 . V_349 - V_356 ) / V_354 ;
if ( V_353 > F_186 () )
V_353 = F_186 () ;
}
V_355 = 0 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_48 ( V_1 , V_2 ) ;
V_10 -> V_82 = V_355 ;
V_10 -> V_31 = F_185 ( & V_10 -> V_11 ) ? V_353 : 1 ;
V_355 += V_10 -> V_31 ;
}
V_7 -> V_288 = V_355 ;
V_351 = 64 ;
for ( V_28 = 0 ; V_28 < V_7 -> V_349 ; V_28 ++ ) {
struct V_81 * V_33 = & V_7 -> V_38 [ V_28 ] ;
struct V_70 * V_71 = & V_7 -> V_83 [ V_28 ] ;
F_183 ( & V_33 -> V_39 , 0 , 0 , 1024 , V_351 ) ;
V_33 -> V_84 . V_219 = 72 ;
V_71 -> V_75 . V_219 = 1024 ;
}
F_183 ( & V_7 -> V_37 , V_164 , 0 , 512 , V_351 ) ;
F_183 ( & V_7 -> V_49 , V_164 , 0 , V_357 + 1 ,
V_351 ) ;
}
static void F_187 ( struct V_1 * V_1 , int V_292 )
{
int V_150 ;
struct V_9 * V_10 ;
F_53 ( V_292 < V_1 -> V_93 . V_330 ) ;
while ( V_292 < V_1 -> V_32 . V_288 )
F_13 (adapter, i) {
V_10 = F_48 ( V_1 , V_150 ) ;
if ( V_10 -> V_31 > 1 ) {
V_10 -> V_31 -- ;
V_1 -> V_32 . V_288 -- ;
if ( V_1 -> V_32 . V_288 <= V_292 )
break;
}
}
V_292 = 0 ;
F_13 (adapter, i) {
V_10 = F_48 ( V_1 , V_150 ) ;
V_10 -> V_82 = V_292 ;
V_292 += V_10 -> V_31 ;
}
}
static int F_188 ( struct V_1 * V_1 )
{
int V_150 , V_34 , V_358 , V_359 ;
struct V_360 V_301 [ V_357 ] ;
struct V_32 * V_7 = & V_1 -> V_32 ;
for ( V_150 = 0 ; V_150 < V_357 ; ++ V_150 )
V_301 [ V_150 ] . V_361 = V_150 ;
V_358 = V_7 -> V_349 + V_362 ;
V_359 = V_1 -> V_93 . V_330 + V_362 ;
while ( ( V_34 = F_189 ( V_1 -> V_104 , V_301 , V_358 ) ) >= V_359 )
V_358 = V_34 ;
if ( V_34 == 0 ) {
int V_31 = V_358 - V_362 ;
if ( V_31 < V_7 -> V_349 ) {
F_182 ( V_1 -> V_66 , L_109
L_110 , V_31 ) ;
V_7 -> V_349 = V_31 ;
if ( V_31 < V_7 -> V_288 )
F_187 ( V_1 , V_31 ) ;
}
for ( V_150 = 0 ; V_150 < V_358 ; ++ V_150 )
V_1 -> V_24 [ V_150 ] . V_35 = V_301 [ V_150 ] . V_363 ;
} else if ( V_34 > 0 ) {
F_190 ( V_1 -> V_104 ) ;
F_191 ( V_1 -> V_66 , L_111
L_112 , V_34 ) ;
}
return V_34 ;
}
static int F_192 ( struct V_364 * V_104 ,
const struct V_365 * V_366 )
{
int V_367 ;
int V_34 , V_2 ;
unsigned int V_325 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_293 ;
F_193 ( L_113 , V_368 , V_201 ) ;
V_34 = F_194 ( V_104 ) ;
if ( V_34 ) {
F_32 ( & V_104 -> V_5 , L_114 ) ;
return V_34 ;
}
V_34 = F_195 ( V_104 , V_199 ) ;
if ( V_34 ) {
F_32 ( & V_104 -> V_5 , L_115 ) ;
goto V_369;
}
V_34 = F_196 ( V_104 , F_197 ( 64 ) ) ;
if ( V_34 == 0 ) {
V_34 = F_198 ( V_104 , F_197 ( 64 ) ) ;
if ( V_34 ) {
F_32 ( & V_104 -> V_5 , L_116
L_117 ) ;
goto V_370;
}
V_367 = 1 ;
} else {
V_34 = F_196 ( V_104 , F_197 ( 32 ) ) ;
if ( V_34 != 0 ) {
F_32 ( & V_104 -> V_5 , L_118 ) ;
goto V_370;
}
V_367 = 0 ;
}
F_199 ( V_104 ) ;
V_1 = F_200 ( sizeof( * V_1 ) , V_371 ) ;
if ( ! V_1 ) {
V_34 = - V_372 ;
goto V_370;
}
F_201 ( V_104 , V_1 ) ;
V_1 -> V_104 = V_104 ;
V_1 -> V_66 = & V_104 -> V_5 ;
F_202 ( & V_1 -> V_112 ) ;
V_1 -> V_266 = F_203 ( V_104 , 0 ) ;
if ( ! V_1 -> V_266 ) {
F_32 ( & V_104 -> V_5 , L_119 ) ;
V_34 = - V_372 ;
goto V_373;
}
V_1 -> V_27 = F_104 ( V_104 ) ;
V_1 -> V_207 = V_374 ;
V_34 = F_165 ( V_1 ) ;
if ( V_34 )
goto V_375;
V_325 = V_1 -> V_93 . V_318 . V_325 ;
F_13 (adapter, pidx) {
int V_108 , V_19 ;
if ( V_325 == 0 )
break;
V_108 = F_204 ( V_325 ) - 1 ;
V_325 &= ~ ( 1 << V_108 ) ;
V_19 = F_205 ( V_1 , V_108 ) ;
if ( V_19 < 0 ) {
F_32 ( & V_104 -> V_5 , L_120
L_82 , V_108 , V_19 ) ;
V_34 = V_19 ;
goto V_376;
}
V_293 = F_206 ( sizeof( struct V_9 ) ,
V_91 ) ;
if ( V_293 == NULL ) {
F_207 ( V_1 , V_19 ) ;
V_34 = - V_372 ;
goto V_376;
}
V_1 -> V_6 [ V_2 ] = V_293 ;
F_208 ( V_293 , & V_104 -> V_5 ) ;
V_10 = F_4 ( V_293 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_108 = V_108 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_21 = - 1 ;
F_7 ( V_293 ) ;
V_293 -> V_105 = V_104 -> V_105 ;
V_293 -> V_377 = V_378 | V_379 |
V_380 | V_381 |
V_174 | V_382 ;
V_293 -> V_383 = V_378 | V_379 |
V_380 | V_381 |
V_384 ;
V_293 -> V_173 = V_293 -> V_377 |
V_175 ;
if ( V_367 )
V_293 -> V_173 |= V_384 ;
V_293 -> V_385 |= V_386 ;
V_293 -> V_387 = & V_388 ;
F_209 ( V_293 , & V_389 ) ;
V_34 = F_210 ( V_1 , V_2 ) ;
if ( V_34 ) {
F_32 ( & V_104 -> V_5 , L_121 ,
V_2 ) ;
goto V_376;
}
}
F_13 (adapter, pidx) {
V_293 = V_1 -> V_6 [ V_2 ] ;
if ( V_293 == NULL )
continue;
V_34 = F_211 ( V_293 ) ;
if ( V_34 ) {
F_182 ( & V_104 -> V_5 , L_122
L_123 , V_293 -> V_27 ) ;
continue;
}
F_61 ( V_2 , & V_1 -> V_390 ) ;
}
if ( V_1 -> V_390 == 0 ) {
F_32 ( & V_104 -> V_5 , L_124 ) ;
goto V_376;
}
if ( ! F_162 ( V_391 ) ) {
V_1 -> V_332 =
F_212 ( F_104 ( V_104 ) ,
V_391 ) ;
if ( F_162 ( V_1 -> V_332 ) )
F_182 ( & V_104 -> V_5 , L_125
L_126 ) ;
else
F_161 ( V_1 ) ;
}
if ( V_29 == V_392 && F_188 ( V_1 ) == 0 )
V_1 -> V_47 |= V_103 ;
else {
V_34 = F_213 ( V_104 ) ;
if ( V_34 ) {
F_32 ( & V_104 -> V_5 , L_127
L_82 ,
V_29 == V_392 ? L_128 : L_129 , V_34 ) ;
goto V_393;
}
V_1 -> V_47 |= V_48 ;
}
F_184 ( V_1 ) ;
F_13 (adapter, pidx) {
F_191 ( V_1 -> V_66 , L_130 ,
V_1 -> V_6 [ V_2 ] -> V_27 ,
( V_1 -> V_47 & V_103 ) ? L_131 :
( V_1 -> V_47 & V_48 ) ? L_129 : L_132 ) ;
}
return 0 ;
V_393:
if ( ! F_162 ( V_1 -> V_332 ) ) {
F_164 ( V_1 ) ;
F_214 ( V_1 -> V_332 ) ;
}
V_376:
F_13 (adapter, pidx) {
V_293 = V_1 -> V_6 [ V_2 ] ;
if ( V_293 == NULL )
continue;
V_10 = F_4 ( V_293 ) ;
F_207 ( V_1 , V_10 -> V_19 ) ;
if ( F_215 ( V_2 , & V_1 -> V_390 ) )
F_216 ( V_293 ) ;
F_217 ( V_293 ) ;
}
V_375:
F_218 ( V_1 -> V_266 ) ;
V_373:
F_219 ( V_1 ) ;
F_201 ( V_104 , NULL ) ;
V_370:
F_220 ( V_104 ) ;
F_201 ( V_104 , NULL ) ;
F_221 ( V_104 ) ;
V_369:
F_222 ( V_104 ) ;
return V_34 ;
}
static void F_223 ( struct V_364 * V_104 )
{
struct V_1 * V_1 = F_224 ( V_104 ) ;
if ( V_1 ) {
int V_2 ;
F_13 (adapter, pidx)
if ( F_215 ( V_2 , & V_1 -> V_390 ) )
F_216 ( V_1 -> V_6 [ V_2 ] ) ;
F_225 ( V_1 ) ;
if ( V_1 -> V_47 & V_103 ) {
F_190 ( V_1 -> V_104 ) ;
V_1 -> V_47 &= ~ V_103 ;
} else if ( V_1 -> V_47 & V_48 ) {
F_226 ( V_1 -> V_104 ) ;
V_1 -> V_47 &= ~ V_48 ;
}
if ( ! F_162 ( V_1 -> V_332 ) ) {
F_164 ( V_1 ) ;
F_214 ( V_1 -> V_332 ) ;
}
F_46 ( V_1 ) ;
F_13 (adapter, pidx) {
struct V_4 * V_293 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_293 == NULL )
continue;
V_10 = F_4 ( V_293 ) ;
F_207 ( V_1 , V_10 -> V_19 ) ;
F_217 ( V_293 ) ;
}
F_218 ( V_1 -> V_266 ) ;
F_219 ( V_1 ) ;
F_201 ( V_104 , NULL ) ;
}
F_222 ( V_104 ) ;
F_221 ( V_104 ) ;
F_220 ( V_104 ) ;
}
static void F_227 ( struct V_364 * V_104 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_224 ( V_104 ) ;
if ( ! V_1 )
return;
F_13 (adapter, pidx) {
struct V_4 * V_293 ;
struct V_9 * V_10 ;
if ( ! F_215 ( V_2 , & V_1 -> V_390 ) )
continue;
V_293 = V_1 -> V_6 [ V_2 ] ;
if ( ! V_293 )
continue;
V_10 = F_4 ( V_293 ) ;
F_11 ( V_1 , V_10 -> V_19 , false , false ) ;
}
F_46 ( V_1 ) ;
}
static int T_12 F_228 ( void )
{
int V_18 ;
if ( V_29 != V_392 && V_29 != V_394 ) {
F_229 ( L_133 ,
V_29 , V_392 , V_394 ) ;
return - V_172 ;
}
V_391 = F_212 ( V_199 , NULL ) ;
if ( F_162 ( V_391 ) )
F_229 ( L_134 ) ;
V_18 = F_230 ( & V_395 ) ;
if ( V_18 < 0 && ! F_162 ( V_391 ) )
F_231 ( V_391 ) ;
return V_18 ;
}
static void T_13 F_232 ( void )
{
F_233 ( & V_395 ) ;
F_231 ( V_391 ) ;
}
