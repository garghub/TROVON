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
case 40000 :
V_7 = L_1 ;
break;
case 10000 :
V_7 = L_2 ;
break;
case 1000 :
V_7 = L_3 ;
break;
case 100 :
V_7 = L_4 ;
break;
default:
V_7 = L_5 ;
break;
}
switch ( V_10 -> V_11 . V_8 ) {
case V_13 :
V_8 = L_6 ;
break;
case V_14 :
V_8 = L_7 ;
break;
case V_13 | V_14 :
V_8 = L_8 ;
break;
default:
V_8 = L_9 ;
break;
}
F_6 ( V_5 , L_10 , V_7 , V_8 ) ;
} else {
F_7 ( V_5 ) ;
F_6 ( V_5 , L_11 ) ;
}
}
static int F_8 ( struct V_4 * V_5 )
{
int V_15 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_15 = F_9 ( V_10 -> V_1 , V_10 -> V_16 , V_5 -> V_17 , - 1 , - 1 , - 1 , 1 ,
true ) ;
if ( V_15 == 0 ) {
V_15 = F_10 ( V_10 -> V_1 , V_10 -> V_16 ,
V_10 -> V_18 , V_5 -> V_19 , true ) ;
if ( V_15 >= 0 ) {
V_10 -> V_18 = V_15 ;
V_15 = 0 ;
}
}
if ( V_15 == 0 )
V_15 = F_11 ( V_10 -> V_1 , V_10 -> V_16 , true , true ) ;
return V_15 ;
}
static void F_12 ( struct V_1 * V_1 )
{
int V_20 = sizeof( V_1 -> V_21 [ 0 ] . V_22 ) - 1 ;
int V_2 ;
snprintf ( V_1 -> V_21 [ V_23 ] . V_22 , V_20 ,
L_12 , V_1 -> V_24 ) ;
V_1 -> V_21 [ V_23 ] . V_22 [ V_20 ] = 0 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
int V_25 , V_26 ;
for ( V_25 = 0 , V_26 = V_27 ; V_25 < V_10 -> V_28 ; V_25 ++ , V_26 ++ ) {
snprintf ( V_1 -> V_21 [ V_26 ] . V_22 , V_20 ,
L_13 , V_5 -> V_24 , V_25 ) ;
V_1 -> V_21 [ V_26 ] . V_22 [ V_20 ] = 0 ;
}
}
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_29 * V_7 = & V_1 -> V_29 ;
int V_30 , V_26 , V_31 ;
V_31 = F_15 ( V_1 -> V_21 [ V_23 ] . V_32 , V_33 ,
0 , V_1 -> V_21 [ V_23 ] . V_22 , & V_7 -> V_34 ) ;
if ( V_31 )
return V_31 ;
V_26 = V_27 ;
F_16 (s, rxq) {
V_31 = F_15 ( V_1 -> V_21 [ V_26 ] . V_32 ,
V_33 , 0 ,
V_1 -> V_21 [ V_26 ] . V_22 ,
& V_7 -> V_35 [ V_30 ] . V_36 ) ;
if ( V_31 )
goto V_37;
V_26 ++ ;
}
return 0 ;
V_37:
while ( -- V_30 >= 0 )
F_17 ( V_1 -> V_21 [ -- V_26 ] . V_32 , & V_7 -> V_35 [ V_30 ] . V_36 ) ;
F_17 ( V_1 -> V_21 [ V_23 ] . V_32 , & V_7 -> V_34 ) ;
return V_31 ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_29 * V_7 = & V_1 -> V_29 ;
int V_30 , V_26 ;
F_17 ( V_1 -> V_21 [ V_23 ] . V_32 , & V_7 -> V_34 ) ;
V_26 = V_27 ;
F_16 (s, rxq)
F_17 ( V_1 -> V_21 [ V_26 ++ ] . V_32 ,
& V_7 -> V_35 [ V_30 ] . V_36 ) ;
}
static void F_19 ( struct V_38 * V_36 )
{
F_20 ( & V_36 -> V_39 ) ;
F_21 ( V_36 -> V_1 , V_40 + V_41 ,
F_22 ( 0 ) |
F_23 ( V_36 -> V_42 ) |
F_24 ( V_36 -> V_43 ) ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
int V_30 ;
struct V_29 * V_7 = & V_1 -> V_29 ;
F_16 (s, rxq)
F_19 ( & V_7 -> V_35 [ V_30 ] . V_36 ) ;
F_19 ( & V_7 -> V_34 ) ;
if ( V_1 -> V_44 & V_45 )
F_21 ( V_1 , V_40 + V_41 ,
F_22 ( 0 ) |
F_23 ( V_7 -> V_46 . V_42 ) |
F_24 ( V_7 -> V_46 . V_43 ) ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_29 * V_7 = & V_1 -> V_29 ;
int V_30 ;
F_16 (s, rxq)
F_27 ( & V_7 -> V_35 [ V_30 ] . V_36 . V_39 ) ;
F_27 ( & V_7 -> V_34 . V_39 ) ;
}
static int F_28 ( struct V_38 * V_36 , const T_1 * V_47 ,
const struct V_48 * V_49 )
{
struct V_1 * V_1 = V_36 -> V_1 ;
T_2 V_50 = ( ( const struct V_51 * ) V_47 ) -> V_50 ;
void * V_52 = ( void * ) ( V_47 + 1 ) ;
switch ( V_50 ) {
case V_53 : {
const struct V_54 * V_55 = V_52 ;
if ( V_55 -> type == V_56 )
F_29 ( V_1 , V_55 -> V_57 ) ;
break;
}
case V_58 : {
const struct V_59 * V_60 = ( void * ) ( V_47 + 3 ) ;
V_50 = F_30 ( F_31 ( V_60 -> V_61 ) ) ;
if ( V_50 != V_62 ) {
F_32 ( V_1 -> V_63 , L_14
, V_50 ) ;
break;
}
V_52 = ( void * ) V_60 ;
}
case V_62 : {
const struct V_59 * V_60 = V_52 ;
unsigned int V_64 = F_33 ( F_34 ( V_60 -> V_61 ) ) ;
struct V_29 * V_7 = & V_1 -> V_29 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
unsigned int V_69 ;
V_69 = F_35 ( V_7 , V_64 ) ;
if ( F_36 ( V_69 >= V_70 ) ) {
F_32 ( V_1 -> V_63 ,
L_15 , V_64 ) ;
break;
}
V_66 = V_7 -> V_71 [ V_69 ] ;
if ( F_36 ( V_66 == NULL ) ) {
F_32 ( V_1 -> V_63 ,
L_16 , V_64 ) ;
break;
}
V_68 = F_37 ( V_66 , struct V_67 , V_72 ) ;
if ( F_36 ( V_66 -> V_73 != V_64 ) ) {
F_32 ( V_1 -> V_63 ,
L_17 ,
V_64 , V_66 -> V_73 ) ;
break;
}
V_68 -> V_72 . V_74 ++ ;
F_38 ( V_68 -> V_68 ) ;
break;
}
default:
F_32 ( V_1 -> V_63 ,
L_18 , V_50 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_29 * V_7 = & V_1 -> V_29 ;
int V_31 , V_2 , V_75 ;
F_40 ( V_7 -> V_76 , V_70 ) ;
if ( V_1 -> V_44 & V_45 ) {
V_31 = F_41 ( V_1 , & V_7 -> V_46 , false ,
V_1 -> V_6 [ 0 ] , 0 , NULL , NULL ) ;
if ( V_31 )
goto V_77;
}
V_31 = F_41 ( V_1 , & V_7 -> V_34 , true , V_1 -> V_6 [ 0 ] ,
V_23 , NULL , F_28 ) ;
if ( V_31 )
goto V_77;
V_75 = V_27 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_78 * V_30 = & V_7 -> V_35 [ V_10 -> V_79 ] ;
struct V_67 * V_68 = & V_7 -> V_80 [ V_10 -> V_79 ] ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_28 ; V_25 ++ , V_30 ++ , V_68 ++ ) {
V_31 = F_41 ( V_1 , & V_30 -> V_36 , false ,
V_5 , V_75 ++ ,
& V_30 -> V_81 , V_82 ) ;
if ( V_31 )
goto V_77;
V_31 = F_42 ( V_1 , V_68 , V_5 ,
F_43 ( V_5 , V_25 ) ,
V_7 -> V_34 . V_43 ) ;
if ( V_31 )
goto V_77;
V_30 -> V_36 . V_83 = V_25 ;
memset ( & V_30 -> V_84 , 0 , sizeof( V_30 -> V_84 ) ) ;
}
}
V_7 -> V_85 = V_7 -> V_80 [ 0 ] . V_72 . V_73 - V_7 -> V_80 [ 0 ] . V_72 . V_43 ;
V_7 -> V_86 = V_7 -> V_35 [ 0 ] . V_36 . V_73 - V_7 -> V_35 [ 0 ] . V_36 . V_43 ;
F_44 ( V_7 , V_7 -> V_34 . V_73 ) = & V_7 -> V_34 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_78 * V_30 = & V_7 -> V_35 [ V_10 -> V_79 ] ;
struct V_67 * V_68 = & V_7 -> V_80 [ V_10 -> V_79 ] ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_28 ; V_25 ++ , V_30 ++ , V_68 ++ ) {
F_44 ( V_7 , V_30 -> V_36 . V_73 ) = & V_30 -> V_36 ;
F_45 ( V_7 , V_68 -> V_72 . V_73 ) = & V_68 -> V_72 ;
V_30 -> V_81 . V_73 = V_30 -> V_81 . V_43 + V_7 -> V_85 ;
F_45 ( V_7 , V_30 -> V_81 . V_73 ) = & V_30 -> V_81 ;
}
}
return 0 ;
V_77:
F_46 ( V_1 ) ;
return V_31 ;
}
static int F_47 ( struct V_1 * V_1 )
{
int V_2 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_48 ( V_1 , V_2 ) ;
struct V_78 * V_30 = & V_1 -> V_29 . V_35 [ V_10 -> V_79 ] ;
T_3 V_87 [ V_88 ] ;
int V_25 , V_31 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_28 ; V_25 ++ )
V_87 [ V_25 ] = V_30 [ V_25 ] . V_36 . V_73 ;
V_31 = F_49 ( V_1 , V_10 -> V_16 ,
0 , V_10 -> V_89 , V_87 , V_10 -> V_28 ) ;
if ( V_31 )
return V_31 ;
switch ( V_1 -> V_90 . V_87 . V_91 ) {
case V_92 :
if ( ! V_1 -> V_90 . V_87 . V_93 . V_94 . V_95 ) {
union V_96 V_97 ;
V_31 = F_50 ( V_1 ,
V_10 -> V_16 ,
& V_97 ) ;
if ( V_31 )
return V_31 ;
V_97 . V_94 . V_98 =
V_30 [ 0 ] . V_36 . V_73 ;
V_31 = F_51 ( V_1 ,
V_10 -> V_16 ,
& V_97 ) ;
if ( V_31 )
return V_31 ;
}
break;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_1 )
{
int V_31 ;
if ( ( V_1 -> V_44 & V_99 ) == 0 ) {
V_31 = F_39 ( V_1 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_47 ( V_1 ) ;
if ( V_31 ) {
F_46 ( V_1 ) ;
return V_31 ;
}
if ( V_1 -> V_44 & V_100 )
F_12 ( V_1 ) ;
V_1 -> V_44 |= V_99 ;
}
F_53 ( ( V_1 -> V_44 & ( V_100 | V_45 ) ) == 0 ) ;
if ( V_1 -> V_44 & V_100 )
V_31 = F_14 ( V_1 ) ;
else
V_31 = F_15 ( V_1 -> V_101 -> V_102 ,
F_54 ( V_1 ) , 0 ,
V_1 -> V_24 , V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_19 ,
V_31 ) ;
return V_31 ;
}
F_25 ( V_1 ) ;
F_55 ( V_1 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_1 )
{
if ( V_1 -> V_44 & V_100 )
F_18 ( V_1 ) ;
else
F_17 ( V_1 -> V_101 -> V_102 , V_1 ) ;
F_26 ( V_1 ) ;
}
static int F_57 ( struct V_4 * V_5 )
{
int V_31 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_103 == 0 ) {
V_31 = F_52 ( V_1 ) ;
if ( V_31 )
return V_31 ;
}
F_58 ( V_5 , V_10 -> V_28 ) ;
V_31 = F_59 ( V_5 , V_10 -> V_28 ) ;
if ( V_31 )
goto V_104;
V_31 = F_8 ( V_5 ) ;
if ( V_31 )
goto V_104;
F_60 ( V_5 ) ;
F_61 ( V_10 -> V_105 , & V_1 -> V_103 ) ;
return 0 ;
V_104:
if ( V_1 -> V_103 == 0 )
F_56 ( V_1 ) ;
return V_31 ;
}
static int F_62 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
F_63 ( V_5 ) ;
F_7 ( V_5 ) ;
F_11 ( V_1 , V_10 -> V_16 , false , false ) ;
V_10 -> V_11 . V_3 = 0 ;
F_64 ( V_10 -> V_105 , & V_1 -> V_103 ) ;
if ( V_1 -> V_103 == 0 )
F_56 ( V_1 ) ;
return 0 ;
}
static struct V_106 * F_65 ( struct V_4 * V_5 )
{
struct V_107 V_84 ;
struct V_9 * V_10 = F_66 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_106 * V_108 = & V_5 -> V_84 ;
int V_31 ;
F_67 ( & V_1 -> V_109 ) ;
V_31 = F_68 ( V_1 , V_10 -> V_2 , & V_84 ) ;
F_69 ( & V_1 -> V_109 ) ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
if ( V_31 )
return V_108 ;
V_108 -> V_110 = ( V_84 . V_111 + V_84 . V_112 +
V_84 . V_113 + V_84 . V_114 ) ;
V_108 -> V_115 = ( V_84 . V_116 + V_84 . V_117 +
V_84 . V_118 + V_84 . V_119 ) ;
V_108 -> V_120 = ( V_84 . V_121 + V_84 . V_122 +
V_84 . V_123 ) ;
V_108 -> V_124 = ( V_84 . V_125 + V_84 . V_126 +
V_84 . V_127 ) ;
V_108 -> V_128 = V_84 . V_126 ;
V_108 -> V_129 = V_84 . V_130 ;
V_108 -> V_131 = V_84 . V_132 ;
return V_108 ;
}
static inline unsigned int F_70 ( const struct V_4 * V_5 ,
const T_2 * * V_133 ,
unsigned int V_134 ,
unsigned int V_135 )
{
unsigned int V_136 = 0 ;
unsigned int V_137 = 0 ;
const struct V_138 * V_139 ;
F_71 (dev, ha)
if ( V_136 ++ >= V_134 ) {
V_133 [ V_137 ++ ] = V_139 -> V_133 ;
if ( V_137 >= V_135 )
break;
}
return V_137 ;
}
static inline unsigned int F_72 ( const struct V_4 * V_5 ,
const T_2 * * V_133 ,
unsigned int V_134 ,
unsigned int V_135 )
{
unsigned int V_136 = 0 ;
unsigned int V_137 = 0 ;
const struct V_138 * V_139 ;
F_73 (ha, dev)
if ( V_136 ++ >= V_134 ) {
V_133 [ V_137 ++ ] = V_139 -> V_133 ;
if ( V_137 >= V_135 )
break;
}
return V_137 ;
}
static int F_74 ( const struct V_4 * V_5 , bool V_140 )
{
T_4 V_141 = 0 ;
T_4 V_142 = 0 ;
bool free = true ;
unsigned int V_134 , V_137 ;
const T_2 * V_133 [ 7 ] ;
int V_15 ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
for ( V_134 = 0 ; ; V_134 += V_137 ) {
V_137 = F_70 ( V_5 , V_133 , V_134 ,
F_75 ( V_133 ) ) ;
if ( V_137 == 0 )
break;
V_15 = F_76 ( V_10 -> V_1 , V_10 -> V_16 , free ,
V_137 , V_133 , NULL , & V_142 , V_140 ) ;
if ( V_15 < 0 )
return V_15 ;
free = false ;
}
for ( V_134 = 0 ; ; V_134 += V_137 ) {
V_137 = F_72 ( V_5 , V_133 , V_134 ,
F_75 ( V_133 ) ) ;
if ( V_137 == 0 )
break;
V_15 = F_76 ( V_10 -> V_1 , V_10 -> V_16 , free ,
V_137 , V_133 , NULL , & V_141 , V_140 ) ;
if ( V_15 < 0 )
return V_15 ;
free = false ;
}
return F_77 ( V_10 -> V_1 , V_10 -> V_16 , V_142 != 0 ,
V_142 | V_141 , V_140 ) ;
}
static int F_78 ( struct V_4 * V_5 , int V_17 , bool V_143 )
{
int V_15 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_15 = F_74 ( V_5 , V_143 ) ;
if ( V_15 == 0 )
V_15 = F_9 ( V_10 -> V_1 , V_10 -> V_16 , - 1 ,
( V_5 -> V_44 & V_144 ) != 0 ,
( V_5 -> V_44 & V_145 ) != 0 ,
1 , - 1 , V_143 ) ;
return V_15 ;
}
static void F_79 ( struct V_4 * V_5 )
{
F_78 ( V_5 , - 1 , false ) ;
}
static int F_80 ( const struct V_29 * V_7 , int V_146 )
{
int V_147 , V_148 = 0 , V_149 = V_150 ;
for ( V_147 = 0 ; V_147 < F_75 ( V_7 -> V_151 ) ; V_147 ++ ) {
int V_152 = V_146 - V_7 -> V_151 [ V_147 ] ;
if ( V_152 < 0 )
V_152 = - V_152 ;
if ( V_152 < V_149 ) {
V_149 = V_152 ;
V_148 = V_147 ;
}
}
return V_148 ;
}
static int F_81 ( const struct V_29 * V_7 , int V_153 )
{
int V_147 , V_152 , V_154 = 0 , V_149 = V_150 ;
for ( V_147 = 0 ; V_147 < F_75 ( V_7 -> V_155 ) ; V_147 ++ ) {
V_152 = V_153 - V_7 -> V_155 [ V_147 ] ;
if ( V_152 < 0 )
V_152 = - V_152 ;
if ( V_152 < V_149 ) {
V_149 = V_152 ;
V_154 = V_147 ;
}
}
return V_154 ;
}
static unsigned int F_82 ( const struct V_1 * V_1 ,
const struct V_38 * V_36 )
{
unsigned int V_148 = F_83 ( V_36 -> V_42 ) ;
return V_148 < V_156
? V_1 -> V_29 . V_151 [ V_148 ]
: 0 ;
}
static int F_84 ( struct V_1 * V_1 , struct V_38 * V_36 ,
unsigned int V_146 , unsigned int V_157 )
{
unsigned int V_148 ;
if ( ( V_146 | V_157 ) == 0 )
V_157 = 1 ;
if ( V_157 ) {
int V_31 ;
T_5 V_158 , V_154 ;
V_154 = F_81 ( & V_1 -> V_29 , V_157 ) ;
if ( V_36 -> V_22 && V_36 -> V_154 != V_154 ) {
V_158 = F_85 ( V_159 ) |
F_86 (
V_160 ) |
F_87 ( V_36 -> V_43 ) ;
V_31 = F_88 ( V_1 , 1 , & V_158 , & V_154 ) ;
if ( V_31 )
return V_31 ;
}
V_36 -> V_154 = V_154 ;
}
V_148 = ( V_146 == 0
? V_161
: F_80 ( & V_1 -> V_29 , V_146 ) ) ;
V_36 -> V_42 = ( F_89 ( V_148 ) |
( V_157 > 0 ? V_162 : 0 ) ) ;
return 0 ;
}
static inline unsigned int F_90 ( const struct V_1 * V_1 )
{
return F_91 ( V_1 -> V_90 . V_163 ) | ( 0x3f << 10 ) ;
}
static int F_92 ( struct V_4 * V_5 , struct V_164 * V_165 , int V_166 )
{
int V_15 = 0 ;
switch ( V_166 ) {
default:
V_15 = - V_167 ;
break;
}
return V_15 ;
}
static int F_93 ( struct V_4 * V_5 , int V_168 )
{
int V_15 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_168 < 81 )
return - V_169 ;
V_15 = F_9 ( V_10 -> V_1 , V_10 -> V_16 , V_168 ,
- 1 , - 1 , - 1 , - 1 , true ) ;
if ( ! V_15 )
V_5 -> V_17 = V_168 ;
return V_15 ;
}
static T_6 F_94 ( struct V_4 * V_5 ,
T_6 V_170 )
{
if ( V_170 & V_171 )
V_170 |= V_172 ;
else
V_170 &= ~ V_172 ;
return V_170 ;
}
static int F_95 ( struct V_4 * V_5 ,
T_6 V_170 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
T_6 V_173 = V_5 -> V_170 ^ V_170 ;
if ( V_173 & V_171 )
F_9 ( V_10 -> V_1 , V_10 -> V_16 , - 1 , - 1 , - 1 , - 1 ,
V_170 & V_172 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_4 * V_5 , void * V_174 )
{
int V_15 ;
struct V_175 * V_133 = V_174 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! F_97 ( V_133 -> V_176 ) )
return - V_177 ;
V_15 = F_10 ( V_10 -> V_1 , V_10 -> V_16 , V_10 -> V_18 ,
V_133 -> V_176 , true ) ;
if ( V_15 < 0 )
return V_15 ;
memcpy ( V_5 -> V_19 , V_133 -> V_176 , V_5 -> V_178 ) ;
V_10 -> V_18 = V_15 ;
return 0 ;
}
static void F_98 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_44 & V_100 ) {
struct V_78 * V_30 ;
int V_28 ;
V_30 = & V_1 -> V_29 . V_35 [ V_10 -> V_79 ] ;
for ( V_28 = V_10 -> V_28 ; V_28 ; V_28 -- ) {
V_33 ( 0 , & V_30 -> V_36 ) ;
V_30 ++ ;
}
} else
F_54 ( V_1 ) ( 0 , V_1 ) ;
}
static int F_99 ( struct V_4 * V_5 ,
struct V_179 * V_166 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
V_166 -> V_180 = V_10 -> V_11 . V_180 ;
V_166 -> V_181 = V_10 -> V_11 . V_181 ;
F_100 ( V_166 ,
F_3 ( V_5 ) ? V_10 -> V_11 . V_12 : - 1 ) ;
V_166 -> V_182 = V_183 ;
V_166 -> V_6 = ( V_166 -> V_180 & V_184 ) ? V_185 : V_186 ;
V_166 -> V_187 = V_10 -> V_105 ;
V_166 -> V_188 = V_189 ;
V_166 -> V_190 = V_10 -> V_11 . V_190 ;
V_166 -> V_191 = 0 ;
V_166 -> V_192 = 0 ;
return 0 ;
}
static void F_101 ( struct V_4 * V_5 ,
struct V_193 * V_194 )
{
struct V_1 * V_1 = F_102 ( V_5 ) ;
F_103 ( V_194 -> V_195 , V_196 , sizeof( V_194 -> V_195 ) ) ;
F_103 ( V_194 -> V_197 , V_198 , sizeof( V_194 -> V_197 ) ) ;
F_103 ( V_194 -> V_199 , F_104 ( F_105 ( V_5 -> V_5 . V_200 ) ) ,
sizeof( V_194 -> V_199 ) ) ;
snprintf ( V_194 -> V_201 , sizeof( V_194 -> V_201 ) ,
L_20 ,
F_106 ( V_1 -> V_90 . V_5 . V_202 ) ,
F_107 ( V_1 -> V_90 . V_5 . V_202 ) ,
F_108 ( V_1 -> V_90 . V_5 . V_202 ) ,
F_109 ( V_1 -> V_90 . V_5 . V_202 ) ,
F_106 ( V_1 -> V_90 . V_5 . V_203 ) ,
F_107 ( V_1 -> V_90 . V_5 . V_203 ) ,
F_108 ( V_1 -> V_90 . V_5 . V_203 ) ,
F_109 ( V_1 -> V_90 . V_5 . V_203 ) ) ;
}
static T_5 F_110 ( struct V_4 * V_5 )
{
return F_102 ( V_5 ) -> V_204 ;
}
static void F_111 ( struct V_4 * V_5 , T_5 V_205 )
{
F_102 ( V_5 ) -> V_204 = V_205 ;
}
static void F_112 ( struct V_4 * V_5 ,
struct V_206 * V_207 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_29 * V_7 = & V_10 -> V_1 -> V_29 ;
V_207 -> V_208 = V_209 ;
V_207 -> V_210 = V_211 ;
V_207 -> V_212 = 0 ;
V_207 -> V_213 = V_214 ;
V_207 -> V_215 = V_7 -> V_35 [ V_10 -> V_79 ] . V_81 . V_216 - V_217 ;
V_207 -> V_218 = V_7 -> V_35 [ V_10 -> V_79 ] . V_36 . V_216 ;
V_207 -> V_219 = 0 ;
V_207 -> V_220 = V_7 -> V_80 [ V_10 -> V_79 ] . V_72 . V_216 ;
}
static int F_113 ( struct V_4 * V_5 ,
struct V_206 * V_207 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_29 * V_7 = & V_1 -> V_29 ;
int V_25 ;
if ( V_207 -> V_215 > V_209 ||
V_207 -> V_219 ||
V_207 -> V_220 > V_214 ||
V_207 -> V_218 > V_211 ||
V_207 -> V_218 < V_221 ||
V_207 -> V_215 < V_222 ||
V_207 -> V_220 < V_223 )
return - V_169 ;
if ( V_1 -> V_44 & V_99 )
return - V_224 ;
for ( V_25 = V_10 -> V_79 ; V_25 < V_10 -> V_79 + V_10 -> V_28 ; V_25 ++ ) {
V_7 -> V_35 [ V_25 ] . V_81 . V_216 = V_207 -> V_215 + V_217 ;
V_7 -> V_35 [ V_25 ] . V_36 . V_216 = V_207 -> V_218 ;
V_7 -> V_80 [ V_25 ] . V_72 . V_216 = V_207 -> V_220 ;
}
return 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
struct V_225 * V_226 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_38 * V_36 = & V_1 -> V_29 . V_35 [ V_10 -> V_79 ] . V_36 ;
V_226 -> V_227 = F_82 ( V_1 , V_36 ) ;
V_226 -> V_228 =
( ( V_36 -> V_42 & V_162 )
? V_1 -> V_29 . V_155 [ V_36 -> V_154 ]
: 0 ) ;
return 0 ;
}
static int F_115 ( struct V_4 * V_5 ,
struct V_225 * V_226 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_84 ( V_1 ,
& V_1 -> V_29 . V_35 [ V_10 -> V_79 ] . V_36 ,
V_226 -> V_227 ,
V_226 -> V_228 ) ;
}
static void F_116 ( struct V_4 * V_5 ,
struct V_229 * V_230 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_230 -> V_190 = ( V_10 -> V_11 . V_231 & V_232 ) != 0 ;
V_230 -> V_233 = ( V_10 -> V_11 . V_8 & V_13 ) != 0 ;
V_230 -> V_234 = ( V_10 -> V_11 . V_8 & V_14 ) != 0 ;
}
static int F_117 ( struct V_4 * V_5 ,
enum V_235 V_236 )
{
unsigned int V_237 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_236 == V_238 )
V_237 = 0xffff ;
else if ( V_236 == V_239 )
V_237 = 0 ;
else
return - V_169 ;
return F_118 ( V_10 -> V_1 , V_10 -> V_16 , V_237 ) ;
}
static int F_119 ( struct V_4 * V_5 , int V_240 )
{
switch ( V_240 ) {
case V_241 :
return F_75 ( V_242 ) ;
default:
return - V_167 ;
}
}
static void F_120 ( struct V_4 * V_5 ,
T_5 V_240 ,
T_2 * V_57 )
{
switch ( V_240 ) {
case V_241 :
memcpy ( V_57 , V_242 , sizeof( V_242 ) ) ;
break;
}
}
static void F_121 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_243 * V_84 )
{
const struct V_67 * V_68 = & V_1 -> V_29 . V_80 [ V_10 -> V_79 ] ;
const struct V_78 * V_30 = & V_1 -> V_29 . V_35 [ V_10 -> V_79 ] ;
int V_25 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
for ( V_25 = 0 ; V_25 < V_10 -> V_28 ; V_25 ++ , V_30 ++ , V_68 ++ ) {
V_84 -> V_244 += V_68 -> V_244 ;
V_84 -> V_245 += V_68 -> V_246 ;
V_84 -> V_247 += V_30 -> V_84 . V_248 ;
V_84 -> V_249 += V_30 -> V_84 . V_249 ;
V_84 -> V_250 += V_68 -> V_250 ;
V_84 -> V_251 += V_30 -> V_84 . V_251 ;
V_84 -> V_252 += V_30 -> V_84 . V_252 ;
}
}
static void F_122 ( struct V_4 * V_5 ,
struct V_253 * V_84 ,
T_4 * V_57 )
{
struct V_9 * V_10 = F_66 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_31 = F_68 ( V_1 , V_10 -> V_2 ,
(struct V_107 * ) V_57 ) ;
if ( V_31 )
memset ( V_57 , 0 , sizeof( struct V_107 ) ) ;
V_57 += sizeof( struct V_107 ) / sizeof( T_4 ) ;
F_121 ( V_1 , V_10 , (struct V_243 * ) V_57 ) ;
}
static int F_123 ( struct V_4 * V_5 )
{
return V_254 ;
}
static void F_124 ( struct V_1 * V_1 , void * V_255 ,
unsigned int V_256 , unsigned int V_257 )
{
T_5 * V_258 = V_255 + V_256 - V_259 ;
for ( ; V_256 <= V_257 ; V_256 += sizeof( T_5 ) ) {
if ( V_256 == V_260 + V_261 )
* V_258 ++ = 0xffff ;
else
* V_258 ++ = F_125 ( V_1 , V_256 ) ;
}
}
static void F_126 ( struct V_4 * V_5 ,
struct V_262 * V_263 ,
void * V_255 )
{
struct V_1 * V_1 = F_102 ( V_5 ) ;
V_263 -> V_197 = F_90 ( V_1 ) ;
memset ( V_255 , 0 , V_254 ) ;
F_124 ( V_1 , V_255 ,
V_40 + V_264 ,
V_40 + V_265 ) ;
F_124 ( V_1 , V_255 ,
V_266 + V_267 ,
V_266 + V_268 ) ;
F_124 ( V_1 , V_255 ,
V_269 + V_270 ,
V_269 + ( F_127 ( V_1 -> V_90 . V_163 )
? V_271 : V_272 ) ) ;
F_124 ( V_1 , V_255 ,
V_260 + V_273 ,
V_260 + V_274 ) ;
F_124 ( V_1 , V_255 ,
V_275 + V_276 ,
V_275 + V_277 ) ;
}
static void F_128 ( struct V_4 * V_5 ,
struct V_278 * V_279 )
{
V_279 -> V_180 = 0 ;
V_279 -> V_280 = 0 ;
memset ( & V_279 -> V_281 , 0 , sizeof( V_279 -> V_281 ) ) ;
}
static int F_129 ( struct V_282 * V_283 , void * V_158 )
{
struct V_1 * V_1 = V_283 -> V_284 ;
int V_285 = F_130 ( V_1 -> V_29 . V_286 , V_287 ) ;
int V_25 , V_288 = ( V_289 ) V_158 - 1 ;
if ( V_288 )
F_131 ( V_283 , '\n' ) ;
#define F_132 ( T_7 , V_7 , V_158 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_133 ( V_7 , V_158 ) S3("s", s, v)
#define F_134 ( V_7 , V_158 ) S3("u", s, txq[qs].v)
#define F_135 ( V_7 , V_158 ) S3("u", s, rxq[qs].v)
if ( V_288 < V_285 ) {
const struct V_78 * V_30 = & V_1 -> V_29 . V_35 [ V_288 * V_287 ] ;
const struct V_67 * V_68 = & V_1 -> V_29 . V_80 [ V_288 * V_287 ] ;
int V_290 = F_136 ( V_287 , V_1 -> V_29 . V_286 - V_287 * V_288 ) ;
F_133 ( L_21 , L_22 ) ;
F_133 ( L_23 ,
( V_30 [ V_25 ] . V_36 . V_291
? V_30 [ V_25 ] . V_36 . V_291 -> V_24
: L_24 ) ) ;
F_132 ( L_25 , L_26 ,
( V_30 [ V_25 ] . V_36 . V_291
? ( (struct V_9 * )
F_4 ( V_30 [ V_25 ] . V_36 . V_291 ) ) -> V_105
: - 1 ) ) ;
F_134 ( L_27 , V_72 . V_73 ) ;
F_134 ( L_28 , V_72 . V_216 ) ;
F_134 ( L_29 , V_72 . V_292 ) ;
F_134 ( L_30 , V_72 . V_2 ) ;
F_134 ( L_31 , V_72 . V_293 ) ;
F_135 ( L_32 , V_36 . V_73 ) ;
F_135 ( L_33 , V_36 . V_216 ) ;
F_135 ( L_34 , V_36 . V_294 ) ;
F_132 ( L_35 , L_36 , F_82 ( V_1 , & V_30 [ V_25 ] . V_36 ) ) ;
F_132 ( L_35 , L_37 ,
V_1 -> V_29 . V_155 [ V_30 [ V_25 ] . V_36 . V_154 ] ) ;
F_135 ( L_38 , V_36 . V_293 ) ;
F_135 ( L_39 , V_36 . V_295 ) ;
F_135 ( L_40 , V_81 . V_73 ) ;
F_135 ( L_41 , V_81 . V_216 - V_217 ) ;
F_135 ( L_42 , V_81 . V_296 ) ;
F_135 ( L_43 , V_81 . V_2 ) ;
F_135 ( L_44 , V_81 . V_293 ) ;
return 0 ;
}
V_288 -= V_285 ;
if ( V_288 == 0 ) {
const struct V_38 * V_297 = & V_1 -> V_29 . V_34 ;
F_137 ( V_283 , L_45 , L_21 , L_46 ) ;
F_137 ( V_283 , L_47 , L_32 , V_297 -> V_73 ) ;
F_137 ( V_283 , L_47 , L_36 ,
F_82 ( V_1 , V_297 ) ) ;
F_137 ( V_283 , L_47 , L_37 ,
V_1 -> V_29 . V_155 [ V_297 -> V_154 ] ) ;
F_137 ( V_283 , L_47 , L_48 , V_297 -> V_293 ) ;
F_137 ( V_283 , L_47 , L_39 , V_297 -> V_295 ) ;
} else if ( V_288 == 1 ) {
const struct V_38 * V_46 = & V_1 -> V_29 . V_46 ;
F_137 ( V_283 , L_45 , L_21 , L_49 ) ;
F_137 ( V_283 , L_47 , L_32 , V_46 -> V_73 ) ;
F_137 ( V_283 , L_47 , L_36 ,
F_82 ( V_1 , V_46 ) ) ;
F_137 ( V_283 , L_47 , L_37 ,
V_1 -> V_29 . V_155 [ V_46 -> V_154 ] ) ;
F_137 ( V_283 , L_47 , L_48 , V_46 -> V_293 ) ;
F_137 ( V_283 , L_47 , L_39 , V_46 -> V_295 ) ;
}
#undef F_135
#undef F_134
#undef F_133
#undef F_132
return 0 ;
}
static int F_138 ( const struct V_1 * V_1 )
{
return F_130 ( V_1 -> V_29 . V_286 , V_287 ) + 1 +
( ( V_1 -> V_44 & V_45 ) != 0 ) ;
}
static void * F_139 ( struct V_282 * V_283 , T_8 * V_298 )
{
int V_299 = F_138 ( V_283 -> V_284 ) ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static void F_140 ( struct V_282 * V_283 , void * V_158 )
{
}
static void * F_141 ( struct V_282 * V_283 , void * V_158 , T_8 * V_298 )
{
int V_299 = F_138 ( V_283 -> V_284 ) ;
++ * V_298 ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static int F_142 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
int V_302 = F_143 ( V_301 , & V_303 ) ;
if ( ! V_302 ) {
struct V_282 * V_283 = V_301 -> V_304 ;
V_283 -> V_284 = V_300 -> V_305 ;
}
return V_302 ;
}
static int F_144 ( struct V_282 * V_283 , void * V_158 )
{
struct V_1 * V_1 = V_283 -> V_284 ;
int V_285 = F_130 ( V_1 -> V_29 . V_286 , V_287 ) ;
int V_25 , V_288 = ( V_289 ) V_158 - 1 ;
if ( V_288 )
F_131 ( V_283 , '\n' ) ;
#define F_132 ( T_9 , V_7 , V_158 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_133 ( V_7 , V_158 ) S3("s", s, v)
#define F_145 ( T_9 , V_7 , V_158 ) S3(fmt, s, txq[qs].v)
#define F_134 ( V_7 , V_158 ) T3("lu", s, v)
#define F_146 ( T_9 , V_7 , V_158 ) S3(fmt, s, rxq[qs].v)
#define F_135 ( V_7 , V_158 ) R3("lu", s, v)
if ( V_288 < V_285 ) {
const struct V_78 * V_30 = & V_1 -> V_29 . V_35 [ V_288 * V_287 ] ;
const struct V_67 * V_68 = & V_1 -> V_29 . V_80 [ V_288 * V_287 ] ;
int V_290 = F_136 ( V_287 , V_1 -> V_29 . V_286 - V_287 * V_288 ) ;
F_133 ( L_21 , L_22 ) ;
F_133 ( L_23 ,
( V_30 [ V_25 ] . V_36 . V_291
? V_30 [ V_25 ] . V_36 . V_291 -> V_24
: L_24 ) ) ;
F_146 ( L_35 , L_50 , V_36 . V_306 ) ;
F_135 ( L_51 , V_84 . V_307 ) ;
F_135 ( L_52 , V_84 . V_248 ) ;
F_135 ( L_53 , V_84 . V_249 ) ;
F_135 ( L_54 , V_84 . V_252 ) ;
F_135 ( L_55 , V_84 . V_251 ) ;
F_135 ( L_56 , V_84 . V_308 ) ;
F_134 ( L_57 , V_244 ) ;
F_134 ( L_58 , V_246 ) ;
F_134 ( L_59 , V_250 ) ;
F_134 ( L_60 , V_72 . V_309 ) ;
F_134 ( L_61 , V_72 . V_74 ) ;
F_134 ( L_62 , V_310 ) ;
F_135 ( L_63 , V_81 . V_311 ) ;
F_135 ( L_64 , V_81 . V_312 ) ;
F_135 ( L_65 , V_81 . V_313 ) ;
return 0 ;
}
V_288 -= V_285 ;
if ( V_288 == 0 ) {
const struct V_38 * V_297 = & V_1 -> V_29 . V_34 ;
F_137 ( V_283 , L_66 , L_21 , L_46 ) ;
F_137 ( V_283 , L_67 , L_50 ,
V_297 -> V_306 ) ;
F_137 ( V_283 , L_67 , L_38 , V_297 -> V_293 ) ;
F_137 ( V_283 , L_67 , L_39 , V_297 -> V_295 ) ;
} else if ( V_288 == 1 ) {
const struct V_38 * V_46 = & V_1 -> V_29 . V_46 ;
F_137 ( V_283 , L_66 , L_21 , L_49 ) ;
F_137 ( V_283 , L_67 , L_50 ,
V_46 -> V_306 ) ;
F_137 ( V_283 , L_67 , L_38 , V_46 -> V_293 ) ;
F_137 ( V_283 , L_67 , L_39 , V_46 -> V_295 ) ;
}
#undef F_135
#undef F_134
#undef F_133
#undef F_146
#undef F_145
#undef F_132
return 0 ;
}
static int F_147 ( const struct V_1 * V_1 )
{
return F_130 ( V_1 -> V_29 . V_286 , V_287 ) + 1 +
( ( V_1 -> V_44 & V_45 ) != 0 ) ;
}
static void * F_148 ( struct V_282 * V_283 , T_8 * V_298 )
{
int V_299 = F_147 ( V_283 -> V_284 ) ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static void F_149 ( struct V_282 * V_283 , void * V_158 )
{
}
static void * F_150 ( struct V_282 * V_283 , void * V_158 , T_8 * V_298 )
{
int V_299 = F_147 ( V_283 -> V_284 ) ;
( * V_298 ) ++ ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static int F_151 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
int V_302 = F_143 ( V_301 , & V_314 ) ;
if ( V_302 == 0 ) {
struct V_282 * V_283 = V_301 -> V_304 ;
V_283 -> V_284 = V_300 -> V_305 ;
}
return V_302 ;
}
static int F_152 ( struct V_282 * V_283 , void * V_158 )
{
struct V_1 * V_1 = V_283 -> V_284 ;
struct V_315 * V_316 = & V_1 -> V_90 . V_316 ;
#define F_133 ( V_22 , T_9 , T_10 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_133 ( L_68 , L_69 , V_317 ) ;
F_133 ( L_70 , L_69 , V_318 ) ;
F_133 ( L_71 , L_69 , V_319 ) ;
F_133 ( L_72 , L_69 , V_320 ) ;
F_133 ( L_73 , L_69 , V_321 ) ;
F_133 ( L_74 , L_69 , V_322 ) ;
F_133 ( L_75 , L_76 , V_323 ) ;
F_133 ( L_77 , L_69 , V_324 ) ;
F_133 ( L_78 , L_76 , V_325 ) ;
F_133 ( L_79 , L_76 , V_326 ) ;
#undef F_133
return 0 ;
}
static int F_153 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
return F_154 ( V_301 , F_152 , V_300 -> V_305 ) ;
}
static int F_155 ( struct V_282 * V_283 , void * V_158 )
{
if ( V_158 == V_327 ) {
F_156 ( V_283 , L_80 ) ;
} else {
struct V_1 * V_1 = V_283 -> V_284 ;
int V_2 = ( V_289 ) V_158 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_137 ( V_283 , L_81 ,
V_5 -> V_24 , V_10 -> V_105 , V_10 -> V_16 ) ;
}
return 0 ;
}
static inline void * F_157 ( struct V_1 * V_1 , T_8 V_298 )
{
return V_298 <= V_1 -> V_90 . V_328
? ( void * ) ( V_289 ) ( V_298 + 1 )
: NULL ;
}
static void * F_158 ( struct V_282 * V_283 , T_8 * V_298 )
{
return * V_298
? F_157 ( V_283 -> V_284 , * V_298 )
: V_327 ;
}
static void * F_159 ( struct V_282 * V_283 , void * V_158 , T_8 * V_298 )
{
( * V_298 ) ++ ;
return F_157 ( V_283 -> V_284 , * V_298 ) ;
}
static void F_160 ( struct V_282 * V_283 , void * V_158 )
{
}
static int F_161 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
int V_302 = F_143 ( V_301 , & V_329 ) ;
if ( V_302 == 0 ) {
struct V_282 * V_283 = V_301 -> V_304 ;
V_283 -> V_284 = V_300 -> V_305 ;
}
return V_302 ;
}
static int F_162 ( struct V_1 * V_1 )
{
int V_147 ;
F_53 ( F_163 ( V_1 -> V_330 ) ) ;
for ( V_147 = 0 ; V_147 < F_75 ( V_331 ) ; V_147 ++ )
( void ) F_164 ( V_331 [ V_147 ] . V_24 ,
V_331 [ V_147 ] . V_91 ,
V_1 -> V_330 ,
( void * ) V_1 ,
V_331 [ V_147 ] . V_332 ) ;
return 0 ;
}
static void F_165 ( struct V_1 * V_1 )
{
F_53 ( F_163 ( V_1 -> V_330 ) ) ;
}
static int F_166 ( struct V_1 * V_1 )
{
struct V_315 * V_316 = & V_1 -> V_90 . V_316 ;
struct V_333 * V_333 = & V_1 -> V_90 . V_29 ;
struct V_29 * V_7 = & V_1 -> V_29 ;
unsigned int V_286 ;
int V_31 ;
T_5 V_334 , V_237 = 0 ;
unsigned int V_335 ;
V_31 = F_167 ( V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_82
L_83 , V_31 ) ;
return V_31 ;
}
V_31 = F_168 ( V_1 ) ;
if ( V_31 < 0 ) {
F_32 ( V_1 -> V_63 , L_84 , V_31 ) ;
return V_31 ;
}
V_1 -> V_90 . V_163 = 0 ;
switch ( V_1 -> V_101 -> V_336 >> 12 ) {
case V_337 :
V_1 -> V_90 . V_163 = F_169 ( V_337 , 0 ) ;
break;
case V_338 :
V_335 = F_170 ( F_125 ( V_1 , V_339 ) ) ;
V_1 -> V_90 . V_163 |= F_169 ( V_338 , V_335 ) ;
break;
}
V_31 = F_171 ( V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_85
L_86 , V_31 ) ;
return V_31 ;
}
V_31 = F_172 ( V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_85
L_87 , V_31 ) ;
return V_31 ;
}
V_31 = F_173 ( V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_85
L_88 , V_31 ) ;
return V_31 ;
}
V_31 = F_174 ( V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_85
L_89 , V_31 ) ;
return V_31 ;
}
if ( V_1 -> V_90 . V_87 . V_91 !=
V_92 ) {
F_32 ( V_1 -> V_63 , L_90
L_91 , V_1 -> V_90 . V_87 . V_91 ) ;
return - V_169 ;
}
V_31 = F_175 ( V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_92
L_83 , V_31 ) ;
return V_31 ;
}
V_334 = F_85 ( V_340 ) |
F_86 ( V_341 ) ;
V_237 = 1 ;
( void ) F_88 ( V_1 , 1 , & V_334 , & V_237 ) ;
V_7 -> V_151 [ 0 ] = F_176 ( V_1 ,
F_177 ( V_333 -> V_342 ) ) ;
V_7 -> V_151 [ 1 ] = F_176 ( V_1 ,
F_178 ( V_333 -> V_342 ) ) ;
V_7 -> V_151 [ 2 ] = F_176 ( V_1 ,
F_177 ( V_333 -> V_343 ) ) ;
V_7 -> V_151 [ 3 ] = F_176 ( V_1 ,
F_178 ( V_333 -> V_343 ) ) ;
V_7 -> V_151 [ 4 ] = F_176 ( V_1 ,
F_177 ( V_333 -> V_344 ) ) ;
V_7 -> V_151 [ 5 ] = F_176 ( V_1 ,
F_178 ( V_333 -> V_344 ) ) ;
V_7 -> V_155 [ 0 ] =
F_179 ( V_333 -> V_345 ) ;
V_7 -> V_155 [ 1 ] =
F_180 ( V_333 -> V_345 ) ;
V_7 -> V_155 [ 2 ] =
F_181 ( V_333 -> V_345 ) ;
V_7 -> V_155 [ 3 ] =
F_182 ( V_333 -> V_345 ) ;
V_31 = F_183 ( V_1 ) ;
if ( V_31 ) {
F_32 ( V_1 -> V_63 , L_93
L_94 , V_31 ) ;
return V_31 ;
}
V_1 -> V_90 . V_328 = V_316 -> V_317 ;
if ( V_1 -> V_90 . V_328 > V_346 ) {
F_184 ( V_1 -> V_63 , L_95
L_96 , V_346 ,
V_1 -> V_90 . V_328 ) ;
V_1 -> V_90 . V_328 = V_346 ;
}
V_286 = V_316 -> V_320 - V_347 ;
if ( V_316 -> V_319 != V_286 ) {
F_184 ( V_1 -> V_63 , L_97
L_98
L_99 , V_286 , V_316 -> V_319 ) ;
V_286 = F_136 ( V_316 -> V_319 , V_286 ) ;
}
if ( V_316 -> V_318 < V_286 * 2 ) {
F_184 ( V_1 -> V_63 , L_100
L_101
L_102 , V_316 -> V_318 , V_286 ) ;
V_286 = V_316 -> V_318 / 2 ;
}
if ( V_286 > V_348 ) {
F_184 ( V_1 -> V_63 , L_103
L_102 , V_348 , V_1 -> V_29 . V_349 ) ;
V_286 = V_348 ;
}
if ( V_316 -> V_321 != 0 || V_316 -> V_318 > V_286 * 2 ) {
F_184 ( V_1 -> V_63 , L_104
L_105 , V_316 -> V_321 , V_316 -> V_318 - V_286 * 2 ) ;
}
V_1 -> V_29 . V_349 = V_286 ;
if ( V_1 -> V_29 . V_349 < V_1 -> V_90 . V_328 ) {
F_184 ( V_1 -> V_63 , L_106
L_107 ,
V_1 -> V_29 . V_349 , V_1 -> V_90 . V_328 ) ;
V_1 -> V_90 . V_328 = V_1 -> V_29 . V_349 ;
}
if ( V_1 -> V_90 . V_328 == 0 ) {
F_32 ( V_1 -> V_63 , L_108
L_109 ) ;
return - V_169 ;
}
return 0 ;
}
static inline void F_185 ( struct V_38 * V_36 , T_2 V_148 ,
T_2 V_350 , unsigned int V_216 ,
unsigned int V_351 )
{
V_36 -> V_42 = ( F_89 ( V_148 ) |
( V_350 < V_352 ? V_162 : 0 ) ) ;
V_36 -> V_154 = ( V_350 < V_352
? V_350
: 0 ) ;
V_36 -> V_294 = V_351 ;
V_36 -> V_216 = V_216 ;
}
static void F_186 ( struct V_1 * V_1 )
{
struct V_29 * V_7 = & V_1 -> V_29 ;
int V_353 , V_354 , V_355 , V_2 , V_25 ;
T_11 V_351 ;
F_53 ( ( V_1 -> V_44 & ( V_100 | V_45 ) ) == 0 ) ;
V_354 = 0 ;
F_13 (adapter, pidx)
V_354 += F_187 ( & F_48 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_354 == 0 )
V_353 = 0 ;
else {
int V_356 = ( V_1 -> V_90 . V_328 - V_354 ) ;
V_353 = ( V_1 -> V_29 . V_349 - V_356 ) / V_354 ;
if ( V_353 > F_188 () )
V_353 = F_188 () ;
}
V_355 = 0 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_48 ( V_1 , V_2 ) ;
V_10 -> V_79 = V_355 ;
V_10 -> V_28 = F_189 ( & V_10 -> V_11 ) ? V_353 : 1 ;
V_355 += V_10 -> V_28 ;
}
V_7 -> V_286 = V_355 ;
V_351 = 64 ;
for ( V_25 = 0 ; V_25 < V_7 -> V_349 ; V_25 ++ ) {
struct V_78 * V_30 = & V_7 -> V_35 [ V_25 ] ;
struct V_67 * V_68 = & V_7 -> V_80 [ V_25 ] ;
F_185 ( & V_30 -> V_36 , 0 , 0 , 1024 , V_351 ) ;
V_30 -> V_81 . V_216 = 72 ;
V_68 -> V_72 . V_216 = 1024 ;
}
F_185 ( & V_7 -> V_34 , V_161 , 0 , 512 , V_351 ) ;
F_185 ( & V_7 -> V_46 , V_161 , 0 , V_357 + 1 ,
V_351 ) ;
}
static void F_190 ( struct V_1 * V_1 , int V_290 )
{
int V_147 ;
struct V_9 * V_10 ;
F_53 ( V_290 < V_1 -> V_90 . V_328 ) ;
while ( V_290 < V_1 -> V_29 . V_286 )
F_13 (adapter, i) {
V_10 = F_48 ( V_1 , V_147 ) ;
if ( V_10 -> V_28 > 1 ) {
V_10 -> V_28 -- ;
V_1 -> V_29 . V_286 -- ;
if ( V_1 -> V_29 . V_286 <= V_290 )
break;
}
}
V_290 = 0 ;
F_13 (adapter, i) {
V_10 = F_48 ( V_1 , V_147 ) ;
V_10 -> V_79 = V_290 ;
V_290 += V_10 -> V_28 ;
}
}
static int F_191 ( struct V_1 * V_1 )
{
int V_147 , V_358 , V_359 , V_28 ;
struct V_360 V_299 [ V_357 ] ;
struct V_29 * V_7 = & V_1 -> V_29 ;
for ( V_147 = 0 ; V_147 < V_357 ; ++ V_147 )
V_299 [ V_147 ] . V_361 = V_147 ;
V_358 = V_7 -> V_349 + V_362 ;
V_359 = V_1 -> V_90 . V_328 + V_362 ;
V_358 = F_192 ( V_1 -> V_101 , V_299 , V_359 , V_358 ) ;
if ( V_358 < 0 )
return V_358 ;
V_28 = V_358 - V_362 ;
if ( V_28 < V_7 -> V_349 ) {
F_184 ( V_1 -> V_63 , L_110
L_111 , V_28 ) ;
V_7 -> V_349 = V_28 ;
if ( V_28 < V_7 -> V_286 )
F_190 ( V_1 , V_28 ) ;
}
for ( V_147 = 0 ; V_147 < V_358 ; ++ V_147 )
V_1 -> V_21 [ V_147 ] . V_32 = V_299 [ V_147 ] . V_363 ;
return 0 ;
}
static int F_193 ( struct V_364 * V_101 ,
const struct V_365 * V_366 )
{
int V_367 ;
int V_31 , V_2 ;
unsigned int V_323 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_291 ;
F_194 ( L_112 , V_368 , V_198 ) ;
V_31 = F_195 ( V_101 ) ;
if ( V_31 ) {
F_32 ( & V_101 -> V_5 , L_113 ) ;
return V_31 ;
}
V_31 = F_196 ( V_101 , V_196 ) ;
if ( V_31 ) {
F_32 ( & V_101 -> V_5 , L_114 ) ;
goto V_369;
}
V_31 = F_197 ( V_101 , F_198 ( 64 ) ) ;
if ( V_31 == 0 ) {
V_31 = F_199 ( V_101 , F_198 ( 64 ) ) ;
if ( V_31 ) {
F_32 ( & V_101 -> V_5 , L_115
L_116 ) ;
goto V_370;
}
V_367 = 1 ;
} else {
V_31 = F_197 ( V_101 , F_198 ( 32 ) ) ;
if ( V_31 != 0 ) {
F_32 ( & V_101 -> V_5 , L_117 ) ;
goto V_370;
}
V_367 = 0 ;
}
F_200 ( V_101 ) ;
V_1 = F_201 ( sizeof( * V_1 ) , V_371 ) ;
if ( ! V_1 ) {
V_31 = - V_372 ;
goto V_370;
}
F_202 ( V_101 , V_1 ) ;
V_1 -> V_101 = V_101 ;
V_1 -> V_63 = & V_101 -> V_5 ;
F_203 ( & V_1 -> V_109 ) ;
V_1 -> V_263 = F_204 ( V_101 , 0 ) ;
if ( ! V_1 -> V_263 ) {
F_32 ( & V_101 -> V_5 , L_118 ) ;
V_31 = - V_372 ;
goto V_373;
}
V_1 -> V_24 = F_104 ( V_101 ) ;
V_1 -> V_204 = V_374 ;
V_31 = F_166 ( V_1 ) ;
if ( V_31 )
goto V_375;
V_323 = V_1 -> V_90 . V_316 . V_323 ;
F_13 (adapter, pidx) {
int V_105 , V_16 ;
if ( V_323 == 0 )
break;
V_105 = F_205 ( V_323 ) - 1 ;
V_323 &= ~ ( 1 << V_105 ) ;
V_16 = F_206 ( V_1 , V_105 ) ;
if ( V_16 < 0 ) {
F_32 ( & V_101 -> V_5 , L_119
L_83 , V_105 , V_16 ) ;
V_31 = V_16 ;
goto V_376;
}
V_291 = F_207 ( sizeof( struct V_9 ) ,
V_88 ) ;
if ( V_291 == NULL ) {
F_208 ( V_1 , V_16 ) ;
V_31 = - V_372 ;
goto V_376;
}
V_1 -> V_6 [ V_2 ] = V_291 ;
F_209 ( V_291 , & V_101 -> V_5 ) ;
V_10 = F_4 ( V_291 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_105 = V_105 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_18 = - 1 ;
F_7 ( V_291 ) ;
V_291 -> V_102 = V_101 -> V_102 ;
V_291 -> V_377 = V_378 | V_379 |
V_380 | V_381 |
V_171 | V_382 ;
V_291 -> V_383 = V_378 | V_379 |
V_380 | V_381 |
V_384 ;
V_291 -> V_170 = V_291 -> V_377 |
V_172 ;
if ( V_367 )
V_291 -> V_170 |= V_384 ;
V_291 -> V_385 |= V_386 ;
V_291 -> V_387 = & V_388 ;
V_291 -> V_389 = & V_390 ;
V_31 = F_210 ( V_1 , V_2 ) ;
if ( V_31 ) {
F_32 ( & V_101 -> V_5 , L_120 ,
V_2 ) ;
goto V_376;
}
}
F_13 (adapter, pidx) {
V_291 = V_1 -> V_6 [ V_2 ] ;
if ( V_291 == NULL )
continue;
V_31 = F_211 ( V_291 ) ;
if ( V_31 ) {
F_184 ( & V_101 -> V_5 , L_121
L_122 , V_291 -> V_24 ) ;
continue;
}
F_61 ( V_2 , & V_1 -> V_391 ) ;
}
if ( V_1 -> V_391 == 0 ) {
F_32 ( & V_101 -> V_5 , L_123 ) ;
goto V_376;
}
if ( ! F_163 ( V_392 ) ) {
V_1 -> V_330 =
F_212 ( F_104 ( V_101 ) ,
V_392 ) ;
if ( F_163 ( V_1 -> V_330 ) )
F_184 ( & V_101 -> V_5 , L_124
L_125 ) ;
else
F_162 ( V_1 ) ;
}
if ( V_26 == V_393 && F_191 ( V_1 ) == 0 )
V_1 -> V_44 |= V_100 ;
else {
V_31 = F_213 ( V_101 ) ;
if ( V_31 ) {
F_32 ( & V_101 -> V_5 , L_126
L_83 ,
V_26 == V_393 ? L_127 : L_128 , V_31 ) ;
goto V_394;
}
V_1 -> V_44 |= V_45 ;
}
F_186 ( V_1 ) ;
F_13 (adapter, pidx) {
F_214 ( V_1 -> V_63 , L_129 ,
V_1 -> V_6 [ V_2 ] -> V_24 ,
( V_1 -> V_44 & V_100 ) ? L_130 :
( V_1 -> V_44 & V_45 ) ? L_128 : L_131 ) ;
}
return 0 ;
V_394:
if ( ! F_163 ( V_1 -> V_330 ) ) {
F_165 ( V_1 ) ;
F_215 ( V_1 -> V_330 ) ;
}
V_376:
F_13 (adapter, pidx) {
V_291 = V_1 -> V_6 [ V_2 ] ;
if ( V_291 == NULL )
continue;
V_10 = F_4 ( V_291 ) ;
F_208 ( V_1 , V_10 -> V_16 ) ;
if ( F_216 ( V_2 , & V_1 -> V_391 ) )
F_217 ( V_291 ) ;
F_218 ( V_291 ) ;
}
V_375:
F_219 ( V_1 -> V_263 ) ;
V_373:
F_220 ( V_1 ) ;
V_370:
F_221 ( V_101 ) ;
F_222 ( V_101 ) ;
V_369:
F_223 ( V_101 ) ;
return V_31 ;
}
static void F_224 ( struct V_364 * V_101 )
{
struct V_1 * V_1 = F_225 ( V_101 ) ;
if ( V_1 ) {
int V_2 ;
F_13 (adapter, pidx)
if ( F_216 ( V_2 , & V_1 -> V_391 ) )
F_217 ( V_1 -> V_6 [ V_2 ] ) ;
F_226 ( V_1 ) ;
if ( V_1 -> V_44 & V_100 ) {
F_227 ( V_1 -> V_101 ) ;
V_1 -> V_44 &= ~ V_100 ;
} else if ( V_1 -> V_44 & V_45 ) {
F_228 ( V_1 -> V_101 ) ;
V_1 -> V_44 &= ~ V_45 ;
}
if ( ! F_163 ( V_1 -> V_330 ) ) {
F_165 ( V_1 ) ;
F_215 ( V_1 -> V_330 ) ;
}
F_46 ( V_1 ) ;
F_13 (adapter, pidx) {
struct V_4 * V_291 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_291 == NULL )
continue;
V_10 = F_4 ( V_291 ) ;
F_208 ( V_1 , V_10 -> V_16 ) ;
F_218 ( V_291 ) ;
}
F_219 ( V_1 -> V_263 ) ;
F_220 ( V_1 ) ;
}
F_223 ( V_101 ) ;
F_222 ( V_101 ) ;
F_221 ( V_101 ) ;
}
static void F_229 ( struct V_364 * V_101 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_225 ( V_101 ) ;
if ( ! V_1 )
return;
F_13 (adapter, pidx)
if ( F_216 ( V_2 , & V_1 -> V_391 ) )
F_217 ( V_1 -> V_6 [ V_2 ] ) ;
F_226 ( V_1 ) ;
if ( V_1 -> V_44 & V_100 ) {
F_227 ( V_1 -> V_101 ) ;
V_1 -> V_44 &= ~ V_100 ;
} else if ( V_1 -> V_44 & V_45 ) {
F_228 ( V_1 -> V_101 ) ;
V_1 -> V_44 &= ~ V_45 ;
}
F_46 ( V_1 ) ;
F_202 ( V_101 , NULL ) ;
}
static int T_12 F_230 ( void )
{
int V_15 ;
if ( V_26 != V_393 && V_26 != V_395 ) {
F_231 ( L_132 ,
V_26 , V_393 , V_395 ) ;
return - V_169 ;
}
V_392 = F_212 ( V_196 , NULL ) ;
if ( F_163 ( V_392 ) )
F_231 ( L_133 ) ;
V_15 = F_232 ( & V_396 ) ;
if ( V_15 < 0 && ! F_163 ( V_392 ) )
F_233 ( V_392 ) ;
return V_15 ;
}
static void T_13 F_234 ( void )
{
F_235 ( & V_396 ) ;
F_233 ( V_392 ) ;
}
