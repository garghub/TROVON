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
const struct V_62 * V_63 = V_55 ;
unsigned int V_64 = F_30 ( F_31 ( V_63 -> V_65 ) ) ;
struct V_32 * V_7 = & V_1 -> V_32 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
unsigned int V_70 ;
V_70 = F_32 ( V_7 , V_64 ) ;
if ( F_33 ( V_70 >= V_71 ) ) {
F_34 ( V_1 -> V_72 ,
L_13 , V_64 ) ;
break;
}
V_67 = V_7 -> V_73 [ V_70 ] ;
if ( F_33 ( V_67 == NULL ) ) {
F_34 ( V_1 -> V_72 ,
L_14 , V_64 ) ;
break;
}
V_69 = F_35 ( V_67 , struct V_68 , V_74 ) ;
if ( F_33 ( V_67 -> V_75 != V_64 ) ) {
F_34 ( V_1 -> V_72 ,
L_15 ,
V_64 , V_67 -> V_75 ) ;
break;
}
V_69 -> V_74 . V_76 ++ ;
F_36 ( V_69 -> V_69 ) ;
break;
}
default:
F_34 ( V_1 -> V_72 ,
L_16 , V_53 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_34 , V_2 , V_77 ;
F_38 ( V_7 -> V_78 , V_71 ) ;
if ( V_1 -> V_47 & V_48 ) {
V_34 = F_39 ( V_1 , & V_7 -> V_49 , false ,
V_1 -> V_6 [ 0 ] , 0 , NULL , NULL ) ;
if ( V_34 )
goto V_79;
}
V_34 = F_39 ( V_1 , & V_7 -> V_37 , true , V_1 -> V_6 [ 0 ] ,
V_26 , NULL , F_28 ) ;
if ( V_34 )
goto V_79;
V_77 = V_30 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_80 * V_33 = & V_7 -> V_38 [ V_10 -> V_81 ] ;
struct V_68 * V_69 = & V_7 -> V_82 [ V_10 -> V_81 ] ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ , V_33 ++ , V_69 ++ ) {
V_34 = F_39 ( V_1 , & V_33 -> V_39 , false ,
V_5 , V_77 ++ ,
& V_33 -> V_83 , V_84 ) ;
if ( V_34 )
goto V_79;
V_34 = F_40 ( V_1 , V_69 , V_5 ,
F_41 ( V_5 , V_28 ) ,
V_7 -> V_37 . V_46 ) ;
if ( V_34 )
goto V_79;
V_33 -> V_39 . V_85 = V_28 ;
memset ( & V_33 -> V_86 , 0 , sizeof( V_33 -> V_86 ) ) ;
}
}
V_7 -> V_87 = V_7 -> V_82 [ 0 ] . V_74 . V_75 - V_7 -> V_82 [ 0 ] . V_74 . V_46 ;
V_7 -> V_88 = V_7 -> V_38 [ 0 ] . V_39 . V_75 - V_7 -> V_38 [ 0 ] . V_39 . V_46 ;
F_42 ( V_7 , V_7 -> V_37 . V_75 ) = & V_7 -> V_37 ;
F_13 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_80 * V_33 = & V_7 -> V_38 [ V_10 -> V_81 ] ;
struct V_68 * V_69 = & V_7 -> V_82 [ V_10 -> V_81 ] ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ , V_33 ++ , V_69 ++ ) {
F_42 ( V_7 , V_33 -> V_39 . V_75 ) = & V_33 -> V_39 ;
F_43 ( V_7 , V_69 -> V_74 . V_75 ) = & V_69 -> V_74 ;
V_33 -> V_83 . V_75 = V_33 -> V_83 . V_46 + V_7 -> V_87 ;
F_43 ( V_7 , V_33 -> V_83 . V_75 ) = & V_33 -> V_83 ;
}
}
return 0 ;
V_79:
F_44 ( V_1 ) ;
return V_34 ;
}
static int F_45 ( struct V_1 * V_1 )
{
int V_2 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_46 ( V_1 , V_2 ) ;
struct V_80 * V_33 = & V_1 -> V_32 . V_38 [ V_10 -> V_81 ] ;
T_3 V_89 [ V_90 ] ;
int V_28 , V_34 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ )
V_89 [ V_28 ] = V_33 [ V_28 ] . V_39 . V_75 ;
V_34 = F_47 ( V_1 , V_10 -> V_19 ,
0 , V_10 -> V_91 , V_89 , V_10 -> V_31 ) ;
if ( V_34 )
return V_34 ;
switch ( V_1 -> V_92 . V_89 . V_93 ) {
case V_94 :
if ( ! V_1 -> V_92 . V_89 . V_95 . V_96 . V_97 ) {
union V_98 V_99 ;
V_34 = F_48 ( V_1 ,
V_10 -> V_19 ,
& V_99 ) ;
if ( V_34 )
return V_34 ;
V_99 . V_96 . V_100 =
V_33 [ 0 ] . V_39 . V_75 ;
V_34 = F_49 ( V_1 ,
V_10 -> V_19 ,
& V_99 ) ;
if ( V_34 )
return V_34 ;
}
break;
}
}
return 0 ;
}
static int F_50 ( struct V_1 * V_1 )
{
int V_34 ;
if ( ( V_1 -> V_47 & V_101 ) == 0 ) {
V_34 = F_37 ( V_1 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_45 ( V_1 ) ;
if ( V_34 ) {
F_44 ( V_1 ) ;
return V_34 ;
}
if ( V_1 -> V_47 & V_102 )
F_12 ( V_1 ) ;
V_1 -> V_47 |= V_101 ;
}
F_51 ( ( V_1 -> V_47 & ( V_102 | V_48 ) ) == 0 ) ;
if ( V_1 -> V_47 & V_102 )
V_34 = F_14 ( V_1 ) ;
else
V_34 = F_15 ( V_1 -> V_103 -> V_104 ,
F_52 ( V_1 ) , 0 ,
V_1 -> V_27 , V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_17 ,
V_34 ) ;
return V_34 ;
}
F_25 ( V_1 ) ;
F_53 ( V_1 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_1 )
{
if ( V_1 -> V_47 & V_102 )
F_18 ( V_1 ) ;
else
F_17 ( V_1 -> V_103 -> V_104 , V_1 ) ;
F_26 ( V_1 ) ;
}
static int F_55 ( struct V_4 * V_5 )
{
int V_34 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_105 == 0 ) {
V_34 = F_50 ( V_1 ) ;
if ( V_34 )
return V_34 ;
}
F_56 ( V_5 , V_10 -> V_31 ) ;
V_34 = F_57 ( V_5 , V_10 -> V_31 ) ;
if ( V_34 )
goto V_106;
V_34 = F_8 ( V_5 ) ;
if ( V_34 )
goto V_106;
F_58 ( V_5 ) ;
F_59 ( V_10 -> V_107 , & V_1 -> V_105 ) ;
return 0 ;
V_106:
if ( V_1 -> V_105 == 0 )
F_54 ( V_1 ) ;
return V_34 ;
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
F_61 ( V_5 ) ;
F_7 ( V_5 ) ;
F_11 ( V_1 , V_10 -> V_19 , false , false ) ;
V_10 -> V_11 . V_3 = 0 ;
F_62 ( V_10 -> V_107 , & V_1 -> V_105 ) ;
if ( V_1 -> V_105 == 0 )
F_54 ( V_1 ) ;
return 0 ;
}
static struct V_108 * F_63 ( struct V_4 * V_5 )
{
struct V_109 V_86 ;
struct V_9 * V_10 = F_64 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_108 * V_110 = & V_5 -> V_86 ;
int V_34 ;
F_65 ( & V_1 -> V_111 ) ;
V_34 = F_66 ( V_1 , V_10 -> V_2 , & V_86 ) ;
F_67 ( & V_1 -> V_111 ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
if ( V_34 )
return V_110 ;
V_110 -> V_112 = ( V_86 . V_113 + V_86 . V_114 +
V_86 . V_115 + V_86 . V_116 ) ;
V_110 -> V_117 = ( V_86 . V_118 + V_86 . V_119 +
V_86 . V_120 + V_86 . V_121 ) ;
V_110 -> V_122 = ( V_86 . V_123 + V_86 . V_124 +
V_86 . V_125 ) ;
V_110 -> V_126 = ( V_86 . V_127 + V_86 . V_128 +
V_86 . V_129 ) ;
V_110 -> V_130 = V_86 . V_128 ;
V_110 -> V_131 = V_86 . V_132 ;
V_110 -> V_133 = V_86 . V_134 ;
return V_110 ;
}
static inline unsigned int F_68 ( const struct V_4 * V_5 ,
const T_2 * * V_135 ,
unsigned int V_136 ,
unsigned int V_137 )
{
unsigned int V_138 = 0 ;
unsigned int V_139 = 0 ;
const struct V_140 * V_141 ;
F_69 (dev, ha)
if ( V_138 ++ >= V_136 ) {
V_135 [ V_139 ++ ] = V_141 -> V_135 ;
if ( V_139 >= V_137 )
break;
}
return V_139 ;
}
static inline unsigned int F_70 ( const struct V_4 * V_5 ,
const T_2 * * V_135 ,
unsigned int V_136 ,
unsigned int V_137 )
{
unsigned int V_138 = 0 ;
unsigned int V_139 = 0 ;
const struct V_140 * V_141 ;
F_71 (ha, dev)
if ( V_138 ++ >= V_136 ) {
V_135 [ V_139 ++ ] = V_141 -> V_135 ;
if ( V_139 >= V_137 )
break;
}
return V_139 ;
}
static int F_72 ( const struct V_4 * V_5 , bool V_142 )
{
T_4 V_143 = 0 ;
T_4 V_144 = 0 ;
bool free = true ;
unsigned int V_136 , V_139 ;
const T_2 * V_135 [ 7 ] ;
int V_18 ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
for ( V_136 = 0 ; ; V_136 += V_139 ) {
V_139 = F_68 ( V_5 , V_135 , V_136 ,
F_73 ( V_135 ) ) ;
if ( V_139 == 0 )
break;
V_18 = F_74 ( V_10 -> V_1 , V_10 -> V_19 , free ,
V_139 , V_135 , NULL , & V_144 , V_142 ) ;
if ( V_18 < 0 )
return V_18 ;
free = false ;
}
for ( V_136 = 0 ; ; V_136 += V_139 ) {
V_139 = F_70 ( V_5 , V_135 , V_136 ,
F_73 ( V_135 ) ) ;
if ( V_139 == 0 )
break;
V_18 = F_74 ( V_10 -> V_1 , V_10 -> V_19 , free ,
V_139 , V_135 , NULL , & V_143 , V_142 ) ;
if ( V_18 < 0 )
return V_18 ;
free = false ;
}
return F_75 ( V_10 -> V_1 , V_10 -> V_19 , V_144 != 0 ,
V_144 | V_143 , V_142 ) ;
}
static int F_76 ( struct V_4 * V_5 , int V_20 , bool V_145 )
{
int V_18 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_18 = F_72 ( V_5 , V_145 ) ;
if ( V_18 == 0 )
V_18 = F_9 ( V_10 -> V_1 , V_10 -> V_19 , - 1 ,
( V_5 -> V_47 & V_146 ) != 0 ,
( V_5 -> V_47 & V_147 ) != 0 ,
1 , - 1 , V_145 ) ;
return V_18 ;
}
static void F_77 ( struct V_4 * V_5 )
{
F_76 ( V_5 , - 1 , false ) ;
}
static int F_78 ( const struct V_32 * V_7 , int V_148 )
{
int V_149 , V_150 = 0 , V_151 = V_152 ;
for ( V_149 = 0 ; V_149 < F_73 ( V_7 -> V_153 ) ; V_149 ++ ) {
int V_154 = V_148 - V_7 -> V_153 [ V_149 ] ;
if ( V_154 < 0 )
V_154 = - V_154 ;
if ( V_154 < V_151 ) {
V_151 = V_154 ;
V_150 = V_149 ;
}
}
return V_150 ;
}
static int F_79 ( const struct V_32 * V_7 , int V_155 )
{
int V_149 , V_154 , V_156 = 0 , V_151 = V_152 ;
for ( V_149 = 0 ; V_149 < F_73 ( V_7 -> V_157 ) ; V_149 ++ ) {
V_154 = V_155 - V_7 -> V_157 [ V_149 ] ;
if ( V_154 < 0 )
V_154 = - V_154 ;
if ( V_154 < V_151 ) {
V_151 = V_154 ;
V_156 = V_149 ;
}
}
return V_156 ;
}
static unsigned int F_80 ( const struct V_1 * V_1 ,
const struct V_41 * V_39 )
{
unsigned int V_150 = F_81 ( V_39 -> V_45 ) ;
return V_150 < V_158
? V_1 -> V_32 . V_153 [ V_150 ]
: 0 ;
}
static int F_82 ( struct V_1 * V_1 , struct V_41 * V_39 ,
unsigned int V_148 , unsigned int V_159 )
{
unsigned int V_150 ;
if ( ( V_148 | V_159 ) == 0 )
V_159 = 1 ;
if ( V_159 ) {
int V_34 ;
T_5 V_160 , V_156 ;
V_156 = F_79 ( & V_1 -> V_32 , V_159 ) ;
if ( V_39 -> V_25 && V_39 -> V_156 != V_156 ) {
V_160 = F_83 ( V_161 ) |
F_84 (
V_162 ) |
F_85 ( V_39 -> V_46 ) ;
V_34 = F_86 ( V_1 , 1 , & V_160 , & V_156 ) ;
if ( V_34 )
return V_34 ;
}
V_39 -> V_156 = V_156 ;
}
V_150 = ( V_148 == 0
? V_163
: F_78 ( & V_1 -> V_32 , V_148 ) ) ;
V_39 -> V_45 = ( F_87 ( V_150 ) |
( V_159 > 0 ? V_164 : 0 ) ) ;
return 0 ;
}
static inline unsigned int F_88 ( const struct V_1 * V_1 )
{
return 4 | ( 0x3f << 10 ) ;
}
static int F_89 ( struct V_4 * V_5 , struct V_165 * V_166 , int V_167 )
{
int V_18 = 0 ;
switch ( V_167 ) {
default:
V_18 = - V_168 ;
break;
}
return V_18 ;
}
static int F_90 ( struct V_4 * V_5 , int V_169 )
{
int V_18 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_169 < 81 )
return - V_170 ;
V_18 = F_9 ( V_10 -> V_1 , V_10 -> V_19 , V_169 ,
- 1 , - 1 , - 1 , - 1 , true ) ;
if ( ! V_18 )
V_5 -> V_20 = V_169 ;
return V_18 ;
}
static T_6 F_91 ( struct V_4 * V_5 ,
T_6 V_171 )
{
if ( V_171 & V_172 )
V_171 |= V_173 ;
else
V_171 &= ~ V_173 ;
return V_171 ;
}
static int F_92 ( struct V_4 * V_5 ,
T_6 V_171 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
T_6 V_174 = V_5 -> V_171 ^ V_171 ;
if ( V_174 & V_172 )
F_9 ( V_10 -> V_1 , V_10 -> V_19 , - 1 , - 1 , - 1 , - 1 ,
V_171 & V_173 , 0 ) ;
return 0 ;
}
static int F_93 ( struct V_4 * V_5 , void * V_175 )
{
int V_18 ;
struct V_176 * V_135 = V_175 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! F_94 ( V_135 -> V_177 ) )
return - V_178 ;
V_18 = F_10 ( V_10 -> V_1 , V_10 -> V_19 , V_10 -> V_21 ,
V_135 -> V_177 , true ) ;
if ( V_18 < 0 )
return V_18 ;
memcpy ( V_5 -> V_22 , V_135 -> V_177 , V_5 -> V_179 ) ;
V_10 -> V_21 = V_18 ;
return 0 ;
}
static void F_95 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_47 & V_102 ) {
struct V_80 * V_33 ;
int V_31 ;
V_33 = & V_1 -> V_32 . V_38 [ V_10 -> V_81 ] ;
for ( V_31 = V_10 -> V_31 ; V_31 ; V_31 -- ) {
V_36 ( 0 , & V_33 -> V_39 ) ;
V_33 ++ ;
}
} else
F_52 ( V_1 ) ( 0 , V_1 ) ;
}
static int F_96 ( struct V_4 * V_5 ,
struct V_180 * V_167 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
V_167 -> V_181 = V_10 -> V_11 . V_181 ;
V_167 -> V_182 = V_10 -> V_11 . V_182 ;
F_97 ( V_167 ,
F_3 ( V_5 ) ? V_10 -> V_11 . V_12 : - 1 ) ;
V_167 -> V_183 = V_184 ;
V_167 -> V_6 = ( V_167 -> V_181 & V_185 ) ? V_186 : V_187 ;
V_167 -> V_188 = V_10 -> V_107 ;
V_167 -> V_189 = V_190 ;
V_167 -> V_191 = V_10 -> V_11 . V_191 ;
V_167 -> V_192 = 0 ;
V_167 -> V_193 = 0 ;
return 0 ;
}
static void F_98 ( struct V_4 * V_5 ,
struct V_194 * V_195 )
{
struct V_1 * V_1 = F_99 ( V_5 ) ;
F_100 ( V_195 -> V_196 , V_197 , sizeof( V_195 -> V_196 ) ) ;
F_100 ( V_195 -> V_198 , V_199 , sizeof( V_195 -> V_198 ) ) ;
F_100 ( V_195 -> V_200 , F_101 ( F_102 ( V_5 -> V_5 . V_201 ) ) ,
sizeof( V_195 -> V_200 ) ) ;
snprintf ( V_195 -> V_202 , sizeof( V_195 -> V_202 ) ,
L_18 ,
F_103 ( V_1 -> V_92 . V_5 . V_203 ) ,
F_104 ( V_1 -> V_92 . V_5 . V_203 ) ,
F_105 ( V_1 -> V_92 . V_5 . V_203 ) ,
F_106 ( V_1 -> V_92 . V_5 . V_203 ) ,
F_103 ( V_1 -> V_92 . V_5 . V_204 ) ,
F_104 ( V_1 -> V_92 . V_5 . V_204 ) ,
F_105 ( V_1 -> V_92 . V_5 . V_204 ) ,
F_106 ( V_1 -> V_92 . V_5 . V_204 ) ) ;
}
static T_5 F_107 ( struct V_4 * V_5 )
{
return F_99 ( V_5 ) -> V_205 ;
}
static void F_108 ( struct V_4 * V_5 , T_5 V_206 )
{
F_99 ( V_5 ) -> V_205 = V_206 ;
}
static void F_109 ( struct V_4 * V_5 ,
struct V_207 * V_208 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_32 * V_7 = & V_10 -> V_1 -> V_32 ;
V_208 -> V_209 = V_210 ;
V_208 -> V_211 = V_212 ;
V_208 -> V_213 = 0 ;
V_208 -> V_214 = V_215 ;
V_208 -> V_216 = V_7 -> V_38 [ V_10 -> V_81 ] . V_83 . V_217 - V_218 ;
V_208 -> V_219 = V_7 -> V_38 [ V_10 -> V_81 ] . V_39 . V_217 ;
V_208 -> V_220 = 0 ;
V_208 -> V_221 = V_7 -> V_82 [ V_10 -> V_81 ] . V_74 . V_217 ;
}
static int F_110 ( struct V_4 * V_5 ,
struct V_207 * V_208 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_28 ;
if ( V_208 -> V_216 > V_210 ||
V_208 -> V_220 ||
V_208 -> V_221 > V_215 ||
V_208 -> V_219 > V_212 ||
V_208 -> V_219 < V_222 ||
V_208 -> V_216 < V_223 ||
V_208 -> V_221 < V_224 )
return - V_170 ;
if ( V_1 -> V_47 & V_101 )
return - V_225 ;
for ( V_28 = V_10 -> V_81 ; V_28 < V_10 -> V_81 + V_10 -> V_31 ; V_28 ++ ) {
V_7 -> V_38 [ V_28 ] . V_83 . V_217 = V_208 -> V_216 + V_218 ;
V_7 -> V_38 [ V_28 ] . V_39 . V_217 = V_208 -> V_219 ;
V_7 -> V_82 [ V_28 ] . V_74 . V_217 = V_208 -> V_221 ;
}
return 0 ;
}
static int F_111 ( struct V_4 * V_5 ,
struct V_226 * V_227 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_41 * V_39 = & V_1 -> V_32 . V_38 [ V_10 -> V_81 ] . V_39 ;
V_227 -> V_228 = F_80 ( V_1 , V_39 ) ;
V_227 -> V_229 =
( ( V_39 -> V_45 & V_164 )
? V_1 -> V_32 . V_157 [ V_39 -> V_156 ]
: 0 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 ,
struct V_226 * V_227 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_82 ( V_1 ,
& V_1 -> V_32 . V_38 [ V_10 -> V_81 ] . V_39 ,
V_227 -> V_228 ,
V_227 -> V_229 ) ;
}
static void F_113 ( struct V_4 * V_5 ,
struct V_230 * V_231 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_231 -> V_191 = ( V_10 -> V_11 . V_232 & V_233 ) != 0 ;
V_231 -> V_234 = ( V_10 -> V_11 . V_8 & V_16 ) != 0 ;
V_231 -> V_235 = ( V_10 -> V_11 . V_8 & V_17 ) != 0 ;
}
static int F_114 ( struct V_4 * V_5 ,
enum V_236 V_237 )
{
unsigned int V_238 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_237 == V_239 )
V_238 = 0xffff ;
else if ( V_237 == V_240 )
V_238 = 0 ;
else
return - V_170 ;
return F_115 ( V_10 -> V_1 , V_10 -> V_19 , V_238 ) ;
}
static int F_116 ( struct V_4 * V_5 , int V_241 )
{
switch ( V_241 ) {
case V_242 :
return F_73 ( V_243 ) ;
default:
return - V_168 ;
}
}
static void F_117 ( struct V_4 * V_5 ,
T_5 V_241 ,
T_2 * V_60 )
{
switch ( V_241 ) {
case V_242 :
memcpy ( V_60 , V_243 , sizeof( V_243 ) ) ;
break;
}
}
static void F_118 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_244 * V_86 )
{
const struct V_68 * V_69 = & V_1 -> V_32 . V_82 [ V_10 -> V_81 ] ;
const struct V_80 * V_33 = & V_1 -> V_32 . V_38 [ V_10 -> V_81 ] ;
int V_28 ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
for ( V_28 = 0 ; V_28 < V_10 -> V_31 ; V_28 ++ , V_33 ++ , V_69 ++ ) {
V_86 -> V_245 += V_69 -> V_245 ;
V_86 -> V_246 += V_69 -> V_247 ;
V_86 -> V_248 += V_33 -> V_86 . V_249 ;
V_86 -> V_250 += V_33 -> V_86 . V_250 ;
V_86 -> V_251 += V_69 -> V_251 ;
V_86 -> V_252 += V_33 -> V_86 . V_252 ;
V_86 -> V_253 += V_33 -> V_86 . V_253 ;
}
}
static void F_119 ( struct V_4 * V_5 ,
struct V_254 * V_86 ,
T_4 * V_60 )
{
struct V_9 * V_10 = F_64 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_34 = F_66 ( V_1 , V_10 -> V_2 ,
(struct V_109 * ) V_60 ) ;
if ( V_34 )
memset ( V_60 , 0 , sizeof( struct V_109 ) ) ;
V_60 += sizeof( struct V_109 ) / sizeof( T_4 ) ;
F_118 ( V_1 , V_10 , (struct V_244 * ) V_60 ) ;
}
static int F_120 ( struct V_4 * V_5 )
{
return V_255 ;
}
static void F_121 ( struct V_1 * V_1 , void * V_256 ,
unsigned int V_257 , unsigned int V_258 )
{
T_5 * V_259 = V_256 + V_257 - V_260 ;
for ( ; V_257 <= V_258 ; V_257 += sizeof( T_5 ) ) {
if ( V_257 == V_261 + V_262 )
* V_259 ++ = 0xffff ;
else
* V_259 ++ = F_122 ( V_1 , V_257 ) ;
}
}
static void F_123 ( struct V_4 * V_5 ,
struct V_263 * V_264 ,
void * V_256 )
{
struct V_1 * V_1 = F_99 ( V_5 ) ;
V_264 -> V_198 = F_88 ( V_1 ) ;
memset ( V_256 , 0 , V_255 ) ;
F_121 ( V_1 , V_256 ,
V_43 + V_265 ,
V_43 + V_266 ) ;
F_121 ( V_1 , V_256 ,
V_267 + V_268 ,
V_267 + V_269 ) ;
F_121 ( V_1 , V_256 ,
V_270 + V_271 ,
V_270 + V_272 ) ;
F_121 ( V_1 , V_256 ,
V_261 + V_273 ,
V_261 + V_274 ) ;
F_121 ( V_1 , V_256 ,
V_275 + V_276 ,
V_275 + V_277 ) ;
}
static void F_124 ( struct V_4 * V_5 ,
struct V_278 * V_279 )
{
V_279 -> V_181 = 0 ;
V_279 -> V_280 = 0 ;
memset ( & V_279 -> V_281 , 0 , sizeof( V_279 -> V_281 ) ) ;
}
static int F_125 ( struct V_282 * V_283 , void * V_160 )
{
struct V_1 * V_1 = V_283 -> V_284 ;
int V_285 = F_126 ( V_1 -> V_32 . V_286 , V_287 ) ;
int V_28 , V_288 = ( V_289 ) V_160 - 1 ;
if ( V_288 )
F_127 ( V_283 , '\n' ) ;
#define F_128 ( T_7 , V_7 , V_160 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_129 ( V_7 , V_160 ) S3("s", s, v)
#define F_130 ( V_7 , V_160 ) S3("u", s, txq[qs].v)
#define F_131 ( V_7 , V_160 ) S3("u", s, rxq[qs].v)
if ( V_288 < V_285 ) {
const struct V_80 * V_33 = & V_1 -> V_32 . V_38 [ V_288 * V_287 ] ;
const struct V_68 * V_69 = & V_1 -> V_32 . V_82 [ V_288 * V_287 ] ;
int V_290 = F_132 ( V_287 , V_1 -> V_32 . V_286 - V_287 * V_288 ) ;
F_129 ( L_19 , L_20 ) ;
F_129 ( L_21 ,
( V_33 [ V_28 ] . V_39 . V_291
? V_33 [ V_28 ] . V_39 . V_291 -> V_27
: L_22 ) ) ;
F_128 ( L_23 , L_24 ,
( V_33 [ V_28 ] . V_39 . V_291
? ( (struct V_9 * )
F_4 ( V_33 [ V_28 ] . V_39 . V_291 ) ) -> V_107
: - 1 ) ) ;
F_130 ( L_25 , V_74 . V_75 ) ;
F_130 ( L_26 , V_74 . V_217 ) ;
F_130 ( L_27 , V_74 . V_292 ) ;
F_130 ( L_28 , V_74 . V_2 ) ;
F_130 ( L_29 , V_74 . V_293 ) ;
F_131 ( L_30 , V_39 . V_75 ) ;
F_131 ( L_31 , V_39 . V_217 ) ;
F_131 ( L_32 , V_39 . V_294 ) ;
F_128 ( L_33 , L_34 , F_80 ( V_1 , & V_33 [ V_28 ] . V_39 ) ) ;
F_128 ( L_33 , L_35 ,
V_1 -> V_32 . V_157 [ V_33 [ V_28 ] . V_39 . V_156 ] ) ;
F_131 ( L_36 , V_39 . V_293 ) ;
F_131 ( L_37 , V_39 . V_295 ) ;
F_131 ( L_38 , V_83 . V_75 ) ;
F_131 ( L_39 , V_83 . V_217 - V_218 ) ;
F_131 ( L_40 , V_83 . V_296 ) ;
F_131 ( L_41 , V_83 . V_2 ) ;
F_131 ( L_42 , V_83 . V_293 ) ;
return 0 ;
}
V_288 -= V_285 ;
if ( V_288 == 0 ) {
const struct V_41 * V_297 = & V_1 -> V_32 . V_37 ;
F_133 ( V_283 , L_43 , L_19 , L_44 ) ;
F_133 ( V_283 , L_45 , L_30 , V_297 -> V_75 ) ;
F_133 ( V_283 , L_45 , L_34 ,
F_80 ( V_1 , V_297 ) ) ;
F_133 ( V_283 , L_45 , L_35 ,
V_1 -> V_32 . V_157 [ V_297 -> V_156 ] ) ;
F_133 ( V_283 , L_45 , L_46 , V_297 -> V_293 ) ;
F_133 ( V_283 , L_45 , L_37 , V_297 -> V_295 ) ;
} else if ( V_288 == 1 ) {
const struct V_41 * V_49 = & V_1 -> V_32 . V_49 ;
F_133 ( V_283 , L_43 , L_19 , L_47 ) ;
F_133 ( V_283 , L_45 , L_30 , V_49 -> V_75 ) ;
F_133 ( V_283 , L_45 , L_34 ,
F_80 ( V_1 , V_49 ) ) ;
F_133 ( V_283 , L_45 , L_35 ,
V_1 -> V_32 . V_157 [ V_49 -> V_156 ] ) ;
F_133 ( V_283 , L_45 , L_46 , V_49 -> V_293 ) ;
F_133 ( V_283 , L_45 , L_37 , V_49 -> V_295 ) ;
}
#undef F_131
#undef F_130
#undef F_129
#undef F_128
return 0 ;
}
static int F_134 ( const struct V_1 * V_1 )
{
return F_126 ( V_1 -> V_32 . V_286 , V_287 ) + 1 +
( ( V_1 -> V_47 & V_48 ) != 0 ) ;
}
static void * F_135 ( struct V_282 * V_283 , T_8 * V_298 )
{
int V_299 = F_134 ( V_283 -> V_284 ) ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static void F_136 ( struct V_282 * V_283 , void * V_160 )
{
}
static void * F_137 ( struct V_282 * V_283 , void * V_160 , T_8 * V_298 )
{
int V_299 = F_134 ( V_283 -> V_284 ) ;
++ * V_298 ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static int F_138 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
int V_302 = F_139 ( V_301 , & V_303 ) ;
if ( ! V_302 ) {
struct V_282 * V_283 = V_301 -> V_304 ;
V_283 -> V_284 = V_300 -> V_305 ;
}
return V_302 ;
}
static int F_140 ( struct V_282 * V_283 , void * V_160 )
{
struct V_1 * V_1 = V_283 -> V_284 ;
int V_285 = F_126 ( V_1 -> V_32 . V_286 , V_287 ) ;
int V_28 , V_288 = ( V_289 ) V_160 - 1 ;
if ( V_288 )
F_127 ( V_283 , '\n' ) ;
#define F_128 ( T_9 , V_7 , V_160 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_129 ( V_7 , V_160 ) S3("s", s, v)
#define F_141 ( T_9 , V_7 , V_160 ) S3(fmt, s, txq[qs].v)
#define F_130 ( V_7 , V_160 ) T3("lu", s, v)
#define F_142 ( T_9 , V_7 , V_160 ) S3(fmt, s, rxq[qs].v)
#define F_131 ( V_7 , V_160 ) R3("lu", s, v)
if ( V_288 < V_285 ) {
const struct V_80 * V_33 = & V_1 -> V_32 . V_38 [ V_288 * V_287 ] ;
const struct V_68 * V_69 = & V_1 -> V_32 . V_82 [ V_288 * V_287 ] ;
int V_290 = F_132 ( V_287 , V_1 -> V_32 . V_286 - V_287 * V_288 ) ;
F_129 ( L_19 , L_20 ) ;
F_129 ( L_21 ,
( V_33 [ V_28 ] . V_39 . V_291
? V_33 [ V_28 ] . V_39 . V_291 -> V_27
: L_22 ) ) ;
F_142 ( L_33 , L_48 , V_39 . V_306 ) ;
F_131 ( L_49 , V_86 . V_307 ) ;
F_131 ( L_50 , V_86 . V_249 ) ;
F_131 ( L_51 , V_86 . V_250 ) ;
F_131 ( L_52 , V_86 . V_253 ) ;
F_131 ( L_53 , V_86 . V_252 ) ;
F_131 ( L_54 , V_86 . V_308 ) ;
F_130 ( L_55 , V_245 ) ;
F_130 ( L_56 , V_247 ) ;
F_130 ( L_57 , V_251 ) ;
F_130 ( L_58 , V_74 . V_309 ) ;
F_130 ( L_59 , V_74 . V_76 ) ;
F_130 ( L_60 , V_310 ) ;
F_131 ( L_61 , V_83 . V_311 ) ;
F_131 ( L_62 , V_83 . V_312 ) ;
F_131 ( L_63 , V_83 . V_313 ) ;
return 0 ;
}
V_288 -= V_285 ;
if ( V_288 == 0 ) {
const struct V_41 * V_297 = & V_1 -> V_32 . V_37 ;
F_133 ( V_283 , L_64 , L_19 , L_44 ) ;
F_133 ( V_283 , L_65 , L_48 ,
V_297 -> V_306 ) ;
F_133 ( V_283 , L_65 , L_36 , V_297 -> V_293 ) ;
F_133 ( V_283 , L_65 , L_37 , V_297 -> V_295 ) ;
} else if ( V_288 == 1 ) {
const struct V_41 * V_49 = & V_1 -> V_32 . V_49 ;
F_133 ( V_283 , L_64 , L_19 , L_47 ) ;
F_133 ( V_283 , L_65 , L_48 ,
V_49 -> V_306 ) ;
F_133 ( V_283 , L_65 , L_36 , V_49 -> V_293 ) ;
F_133 ( V_283 , L_65 , L_37 , V_49 -> V_295 ) ;
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
return F_126 ( V_1 -> V_32 . V_286 , V_287 ) + 1 +
( ( V_1 -> V_47 & V_48 ) != 0 ) ;
}
static void * F_144 ( struct V_282 * V_283 , T_8 * V_298 )
{
int V_299 = F_143 ( V_283 -> V_284 ) ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static void F_145 ( struct V_282 * V_283 , void * V_160 )
{
}
static void * F_146 ( struct V_282 * V_283 , void * V_160 , T_8 * V_298 )
{
int V_299 = F_143 ( V_283 -> V_284 ) ;
( * V_298 ) ++ ;
return * V_298 < V_299 ? ( void * ) ( ( V_289 ) * V_298 + 1 ) : NULL ;
}
static int F_147 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
int V_302 = F_139 ( V_301 , & V_314 ) ;
if ( V_302 == 0 ) {
struct V_282 * V_283 = V_301 -> V_304 ;
V_283 -> V_284 = V_300 -> V_305 ;
}
return V_302 ;
}
static int F_148 ( struct V_282 * V_283 , void * V_160 )
{
struct V_1 * V_1 = V_283 -> V_284 ;
struct V_315 * V_316 = & V_1 -> V_92 . V_316 ;
#define F_129 ( V_25 , T_9 , T_10 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_129 ( L_66 , L_67 , V_317 ) ;
F_129 ( L_68 , L_67 , V_318 ) ;
F_129 ( L_69 , L_67 , V_319 ) ;
F_129 ( L_70 , L_67 , V_320 ) ;
F_129 ( L_71 , L_67 , V_321 ) ;
F_129 ( L_72 , L_67 , V_322 ) ;
F_129 ( L_73 , L_74 , V_323 ) ;
F_129 ( L_75 , L_67 , V_324 ) ;
F_129 ( L_76 , L_74 , V_325 ) ;
F_129 ( L_77 , L_74 , V_326 ) ;
#undef F_129
return 0 ;
}
static int F_149 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
return F_150 ( V_301 , F_148 , V_300 -> V_305 ) ;
}
static int F_151 ( struct V_282 * V_283 , void * V_160 )
{
if ( V_160 == V_327 ) {
F_152 ( V_283 , L_78 ) ;
} else {
struct V_1 * V_1 = V_283 -> V_284 ;
int V_2 = ( V_289 ) V_160 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_133 ( V_283 , L_79 ,
V_5 -> V_27 , V_10 -> V_107 , V_10 -> V_19 ) ;
}
return 0 ;
}
static inline void * F_153 ( struct V_1 * V_1 , T_8 V_298 )
{
return V_298 <= V_1 -> V_92 . V_328
? ( void * ) ( V_289 ) ( V_298 + 1 )
: NULL ;
}
static void * F_154 ( struct V_282 * V_283 , T_8 * V_298 )
{
return * V_298
? F_153 ( V_283 -> V_284 , * V_298 )
: V_327 ;
}
static void * F_155 ( struct V_282 * V_283 , void * V_160 , T_8 * V_298 )
{
( * V_298 ) ++ ;
return F_153 ( V_283 -> V_284 , * V_298 ) ;
}
static void F_156 ( struct V_282 * V_283 , void * V_160 )
{
}
static int F_157 ( struct V_300 * V_300 , struct V_301 * V_301 )
{
int V_302 = F_139 ( V_301 , & V_329 ) ;
if ( V_302 == 0 ) {
struct V_282 * V_283 = V_301 -> V_304 ;
V_283 -> V_284 = V_300 -> V_305 ;
}
return V_302 ;
}
static int F_158 ( struct V_1 * V_1 )
{
int V_149 ;
F_51 ( F_159 ( V_1 -> V_330 ) ) ;
for ( V_149 = 0 ; V_149 < F_73 ( V_331 ) ; V_149 ++ )
( void ) F_160 ( V_331 [ V_149 ] . V_27 ,
V_331 [ V_149 ] . V_93 ,
V_1 -> V_330 ,
( void * ) V_1 ,
V_331 [ V_149 ] . V_332 ) ;
return 0 ;
}
static void F_161 ( struct V_1 * V_1 )
{
F_51 ( F_159 ( V_1 -> V_330 ) ) ;
}
static int F_162 ( struct V_1 * V_1 )
{
struct V_315 * V_316 = & V_1 -> V_92 . V_316 ;
struct V_333 * V_333 = & V_1 -> V_92 . V_32 ;
struct V_32 * V_7 = & V_1 -> V_32 ;
unsigned int V_286 ;
int V_34 ;
V_34 = F_163 ( V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_80
L_81 , V_34 ) ;
return V_34 ;
}
V_34 = F_164 ( V_1 ) ;
if ( V_34 < 0 ) {
F_34 ( V_1 -> V_72 , L_82 , V_34 ) ;
return V_34 ;
}
V_34 = F_165 ( V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_83
L_84 , V_34 ) ;
return V_34 ;
}
V_34 = F_166 ( V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_83
L_85 , V_34 ) ;
return V_34 ;
}
V_34 = F_167 ( V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_83
L_86 , V_34 ) ;
return V_34 ;
}
V_34 = F_168 ( V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_83
L_87 , V_34 ) ;
return V_34 ;
}
if ( V_1 -> V_92 . V_89 . V_93 !=
V_94 ) {
F_34 ( V_1 -> V_72 , L_88
L_89 , V_1 -> V_92 . V_89 . V_93 ) ;
return - V_170 ;
}
V_34 = F_169 ( V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_90
L_81 , V_34 ) ;
return V_34 ;
}
V_7 -> V_153 [ 0 ] = F_170 ( V_1 ,
F_171 ( V_333 -> V_334 ) ) ;
V_7 -> V_153 [ 1 ] = F_170 ( V_1 ,
F_172 ( V_333 -> V_334 ) ) ;
V_7 -> V_153 [ 2 ] = F_170 ( V_1 ,
F_171 ( V_333 -> V_335 ) ) ;
V_7 -> V_153 [ 3 ] = F_170 ( V_1 ,
F_172 ( V_333 -> V_335 ) ) ;
V_7 -> V_153 [ 4 ] = F_170 ( V_1 ,
F_171 ( V_333 -> V_336 ) ) ;
V_7 -> V_153 [ 5 ] = F_170 ( V_1 ,
F_172 ( V_333 -> V_336 ) ) ;
V_7 -> V_157 [ 0 ] =
F_173 ( V_333 -> V_337 ) ;
V_7 -> V_157 [ 1 ] =
F_174 ( V_333 -> V_337 ) ;
V_7 -> V_157 [ 2 ] =
F_175 ( V_333 -> V_337 ) ;
V_7 -> V_157 [ 3 ] =
F_176 ( V_333 -> V_337 ) ;
V_34 = F_177 ( V_1 ) ;
if ( V_34 ) {
F_34 ( V_1 -> V_72 , L_91
L_92 , V_34 ) ;
return V_34 ;
}
V_1 -> V_92 . V_328 = V_316 -> V_317 ;
if ( V_1 -> V_92 . V_328 > V_338 ) {
F_178 ( V_1 -> V_72 , L_93
L_94 , V_338 ,
V_1 -> V_92 . V_328 ) ;
V_1 -> V_92 . V_328 = V_338 ;
}
V_286 = V_316 -> V_320 - V_339 ;
if ( V_316 -> V_319 != V_286 ) {
F_178 ( V_1 -> V_72 , L_95
L_96
L_97 , V_286 , V_316 -> V_319 ) ;
V_286 = F_132 ( V_316 -> V_319 , V_286 ) ;
}
if ( V_316 -> V_318 < V_286 * 2 ) {
F_178 ( V_1 -> V_72 , L_98
L_99
L_100 , V_316 -> V_318 , V_286 ) ;
V_286 = V_316 -> V_318 / 2 ;
}
if ( V_286 > V_340 ) {
F_178 ( V_1 -> V_72 , L_101
L_100 , V_340 , V_1 -> V_32 . V_341 ) ;
V_286 = V_340 ;
}
if ( V_316 -> V_321 != 0 || V_316 -> V_318 > V_286 * 2 ) {
F_178 ( V_1 -> V_72 , L_102
L_103 , V_316 -> V_321 , V_316 -> V_318 - V_286 * 2 ) ;
}
V_1 -> V_32 . V_341 = V_286 ;
if ( V_1 -> V_32 . V_341 < V_1 -> V_92 . V_328 ) {
F_178 ( V_1 -> V_72 , L_104
L_105 ,
V_1 -> V_32 . V_341 , V_1 -> V_92 . V_328 ) ;
V_1 -> V_92 . V_328 = V_1 -> V_32 . V_341 ;
}
if ( V_1 -> V_92 . V_328 == 0 ) {
F_34 ( V_1 -> V_72 , L_106
L_107 ) ;
return - V_170 ;
}
return 0 ;
}
static inline void F_179 ( struct V_41 * V_39 , T_2 V_150 ,
T_2 V_342 , unsigned int V_217 ,
unsigned int V_343 )
{
V_39 -> V_45 = ( F_87 ( V_150 ) |
( V_342 < V_344 ? V_164 : 0 ) ) ;
V_39 -> V_156 = ( V_342 < V_344
? V_342
: 0 ) ;
V_39 -> V_294 = V_343 ;
V_39 -> V_217 = V_217 ;
}
static void F_180 ( struct V_1 * V_1 )
{
struct V_32 * V_7 = & V_1 -> V_32 ;
int V_345 , V_346 , V_347 , V_2 , V_28 ;
T_11 V_343 ;
F_51 ( ( V_1 -> V_47 & ( V_102 | V_48 ) ) == 0 ) ;
V_346 = 0 ;
F_13 (adapter, pidx)
V_346 += F_181 ( & F_46 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_346 == 0 )
V_345 = 0 ;
else {
int V_348 = ( V_1 -> V_92 . V_328 - V_346 ) ;
V_345 = ( V_1 -> V_32 . V_341 - V_348 ) / V_346 ;
if ( V_345 > F_182 () )
V_345 = F_182 () ;
}
V_347 = 0 ;
F_13 (adapter, pidx) {
struct V_9 * V_10 = F_46 ( V_1 , V_2 ) ;
V_10 -> V_81 = V_347 ;
V_10 -> V_31 = F_181 ( & V_10 -> V_11 ) ? V_345 : 1 ;
V_347 += V_10 -> V_31 ;
}
V_7 -> V_286 = V_347 ;
V_343 = 64 ;
for ( V_28 = 0 ; V_28 < V_7 -> V_341 ; V_28 ++ ) {
struct V_80 * V_33 = & V_7 -> V_38 [ V_28 ] ;
struct V_68 * V_69 = & V_7 -> V_82 [ V_28 ] ;
F_179 ( & V_33 -> V_39 , 0 , 0 , 1024 , V_343 ) ;
V_33 -> V_83 . V_217 = 72 ;
V_69 -> V_74 . V_217 = 1024 ;
}
F_179 ( & V_7 -> V_37 , V_163 , 0 , 512 , V_343 ) ;
F_179 ( & V_7 -> V_49 , V_163 , 0 , V_349 + 1 ,
V_343 ) ;
}
static void F_183 ( struct V_1 * V_1 , int V_290 )
{
int V_149 ;
struct V_9 * V_10 ;
F_51 ( V_290 < V_1 -> V_92 . V_328 ) ;
while ( V_290 < V_1 -> V_32 . V_286 )
F_13 (adapter, i) {
V_10 = F_46 ( V_1 , V_149 ) ;
if ( V_10 -> V_31 > 1 ) {
V_10 -> V_31 -- ;
V_1 -> V_32 . V_286 -- ;
if ( V_1 -> V_32 . V_286 <= V_290 )
break;
}
}
V_290 = 0 ;
F_13 (adapter, i) {
V_10 = F_46 ( V_1 , V_149 ) ;
V_10 -> V_81 = V_290 ;
V_290 += V_10 -> V_31 ;
}
}
static int F_184 ( struct V_1 * V_1 )
{
int V_149 , V_34 , V_350 , V_351 ;
struct V_352 V_299 [ V_349 ] ;
struct V_32 * V_7 = & V_1 -> V_32 ;
for ( V_149 = 0 ; V_149 < V_349 ; ++ V_149 )
V_299 [ V_149 ] . V_353 = V_149 ;
V_350 = V_7 -> V_341 + V_354 ;
V_351 = V_1 -> V_92 . V_328 + V_354 ;
while ( ( V_34 = F_185 ( V_1 -> V_103 , V_299 , V_350 ) ) >= V_351 )
V_350 = V_34 ;
if ( V_34 == 0 ) {
int V_31 = V_350 - V_354 ;
if ( V_31 < V_7 -> V_341 ) {
F_178 ( V_1 -> V_72 , L_108
L_109 , V_31 ) ;
V_7 -> V_341 = V_31 ;
if ( V_31 < V_7 -> V_286 )
F_183 ( V_1 , V_31 ) ;
}
for ( V_149 = 0 ; V_149 < V_350 ; ++ V_149 )
V_1 -> V_24 [ V_149 ] . V_35 = V_299 [ V_149 ] . V_355 ;
} else if ( V_34 > 0 ) {
F_186 ( V_1 -> V_103 ) ;
F_187 ( V_1 -> V_72 , L_110
L_111 , V_34 ) ;
}
return V_34 ;
}
static int F_188 ( struct V_356 * V_103 ,
const struct V_357 * V_358 )
{
int V_359 ;
int V_34 , V_2 ;
unsigned int V_323 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_291 ;
F_189 ( L_112 , V_360 , V_199 ) ;
V_34 = F_190 ( V_103 ) ;
if ( V_34 ) {
F_34 ( & V_103 -> V_5 , L_113 ) ;
return V_34 ;
}
V_34 = F_191 ( V_103 , V_197 ) ;
if ( V_34 ) {
F_34 ( & V_103 -> V_5 , L_114 ) ;
goto V_361;
}
V_34 = F_192 ( V_103 , F_193 ( 64 ) ) ;
if ( V_34 == 0 ) {
V_34 = F_194 ( V_103 , F_193 ( 64 ) ) ;
if ( V_34 ) {
F_34 ( & V_103 -> V_5 , L_115
L_116 ) ;
goto V_362;
}
V_359 = 1 ;
} else {
V_34 = F_192 ( V_103 , F_193 ( 32 ) ) ;
if ( V_34 != 0 ) {
F_34 ( & V_103 -> V_5 , L_117 ) ;
goto V_362;
}
V_359 = 0 ;
}
F_195 ( V_103 ) ;
V_1 = F_196 ( sizeof( * V_1 ) , V_363 ) ;
if ( ! V_1 ) {
V_34 = - V_364 ;
goto V_362;
}
F_197 ( V_103 , V_1 ) ;
V_1 -> V_103 = V_103 ;
V_1 -> V_72 = & V_103 -> V_5 ;
F_198 ( & V_1 -> V_111 ) ;
V_1 -> V_264 = F_199 ( V_103 , 0 ) ;
if ( ! V_1 -> V_264 ) {
F_34 ( & V_103 -> V_5 , L_118 ) ;
V_34 = - V_364 ;
goto V_365;
}
V_1 -> V_27 = F_101 ( V_103 ) ;
V_1 -> V_205 = V_366 ;
V_34 = F_162 ( V_1 ) ;
if ( V_34 )
goto V_367;
V_323 = V_1 -> V_92 . V_316 . V_323 ;
F_13 (adapter, pidx) {
int V_107 , V_19 ;
if ( V_323 == 0 )
break;
V_107 = F_200 ( V_323 ) - 1 ;
V_323 &= ~ ( 1 << V_107 ) ;
V_19 = F_201 ( V_1 , V_107 ) ;
if ( V_19 < 0 ) {
F_34 ( & V_103 -> V_5 , L_119
L_81 , V_107 , V_19 ) ;
V_34 = V_19 ;
goto V_368;
}
V_291 = F_202 ( sizeof( struct V_9 ) ,
V_90 ) ;
if ( V_291 == NULL ) {
F_203 ( V_1 , V_19 ) ;
V_34 = - V_364 ;
goto V_368;
}
V_1 -> V_6 [ V_2 ] = V_291 ;
F_204 ( V_291 , & V_103 -> V_5 ) ;
V_10 = F_4 ( V_291 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_107 = V_107 ;
V_10 -> V_19 = V_19 ;
V_10 -> V_21 = - 1 ;
F_7 ( V_291 ) ;
V_291 -> V_104 = V_103 -> V_104 ;
V_291 -> V_369 = V_370 | V_371 |
V_372 | V_373 |
V_172 | V_374 ;
V_291 -> V_375 = V_370 | V_371 |
V_372 | V_373 |
V_376 ;
V_291 -> V_171 = V_291 -> V_369 | V_173 ;
if ( V_359 )
V_291 -> V_171 |= V_376 ;
V_291 -> V_377 |= V_378 ;
V_291 -> V_379 = & V_380 ;
F_205 ( V_291 , & V_381 ) ;
V_34 = F_206 ( V_1 , V_2 ) ;
if ( V_34 ) {
F_34 ( & V_103 -> V_5 , L_120 ,
V_2 ) ;
goto V_368;
}
}
F_13 (adapter, pidx) {
V_291 = V_1 -> V_6 [ V_2 ] ;
if ( V_291 == NULL )
continue;
V_34 = F_207 ( V_291 ) ;
if ( V_34 ) {
F_178 ( & V_103 -> V_5 , L_121
L_122 , V_291 -> V_27 ) ;
continue;
}
F_59 ( V_2 , & V_1 -> V_382 ) ;
}
if ( V_1 -> V_382 == 0 ) {
F_34 ( & V_103 -> V_5 , L_123 ) ;
goto V_368;
}
if ( ! F_159 ( V_383 ) ) {
V_1 -> V_330 =
F_208 ( F_101 ( V_103 ) ,
V_383 ) ;
if ( F_159 ( V_1 -> V_330 ) )
F_178 ( & V_103 -> V_5 , L_124
L_125 ) ;
else
F_158 ( V_1 ) ;
}
if ( V_29 == V_384 && F_184 ( V_1 ) == 0 )
V_1 -> V_47 |= V_102 ;
else {
V_34 = F_209 ( V_103 ) ;
if ( V_34 ) {
F_34 ( & V_103 -> V_5 , L_126
L_81 ,
V_29 == V_384 ? L_127 : L_128 , V_34 ) ;
goto V_385;
}
V_1 -> V_47 |= V_48 ;
}
F_180 ( V_1 ) ;
F_13 (adapter, pidx) {
F_187 ( V_1 -> V_72 , L_129 ,
V_1 -> V_6 [ V_2 ] -> V_27 ,
( V_1 -> V_47 & V_102 ) ? L_130 :
( V_1 -> V_47 & V_48 ) ? L_128 : L_131 ) ;
}
return 0 ;
V_385:
if ( ! F_159 ( V_1 -> V_330 ) ) {
F_161 ( V_1 ) ;
F_210 ( V_1 -> V_330 ) ;
}
V_368:
F_13 (adapter, pidx) {
V_291 = V_1 -> V_6 [ V_2 ] ;
if ( V_291 == NULL )
continue;
V_10 = F_4 ( V_291 ) ;
F_203 ( V_1 , V_10 -> V_19 ) ;
if ( F_211 ( V_2 , & V_1 -> V_382 ) )
F_212 ( V_291 ) ;
F_213 ( V_291 ) ;
}
V_367:
F_214 ( V_1 -> V_264 ) ;
V_365:
F_215 ( V_1 ) ;
F_197 ( V_103 , NULL ) ;
V_362:
F_216 ( V_103 ) ;
F_197 ( V_103 , NULL ) ;
F_217 ( V_103 ) ;
V_361:
F_218 ( V_103 ) ;
return V_34 ;
}
static void F_219 ( struct V_356 * V_103 )
{
struct V_1 * V_1 = F_220 ( V_103 ) ;
if ( V_1 ) {
int V_2 ;
F_13 (adapter, pidx)
if ( F_211 ( V_2 , & V_1 -> V_382 ) )
F_212 ( V_1 -> V_6 [ V_2 ] ) ;
F_221 ( V_1 ) ;
if ( V_1 -> V_47 & V_102 ) {
F_186 ( V_1 -> V_103 ) ;
V_1 -> V_47 &= ~ V_102 ;
} else if ( V_1 -> V_47 & V_48 ) {
F_222 ( V_1 -> V_103 ) ;
V_1 -> V_47 &= ~ V_48 ;
}
if ( ! F_159 ( V_1 -> V_330 ) ) {
F_161 ( V_1 ) ;
F_210 ( V_1 -> V_330 ) ;
}
F_44 ( V_1 ) ;
F_13 (adapter, pidx) {
struct V_4 * V_291 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_291 == NULL )
continue;
V_10 = F_4 ( V_291 ) ;
F_203 ( V_1 , V_10 -> V_19 ) ;
F_213 ( V_291 ) ;
}
F_214 ( V_1 -> V_264 ) ;
F_215 ( V_1 ) ;
F_197 ( V_103 , NULL ) ;
}
F_218 ( V_103 ) ;
F_217 ( V_103 ) ;
F_216 ( V_103 ) ;
}
static void F_223 ( struct V_356 * V_103 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_220 ( V_103 ) ;
if ( ! V_1 )
return;
F_13 (adapter, pidx) {
struct V_4 * V_291 ;
struct V_9 * V_10 ;
if ( ! F_211 ( V_2 , & V_1 -> V_382 ) )
continue;
V_291 = V_1 -> V_6 [ V_2 ] ;
if ( ! V_291 )
continue;
V_10 = F_4 ( V_291 ) ;
F_11 ( V_1 , V_10 -> V_19 , false , false ) ;
}
F_44 ( V_1 ) ;
}
static int T_12 F_224 ( void )
{
int V_18 ;
if ( V_29 != V_384 && V_29 != V_386 ) {
F_225 ( L_132 ,
V_29 , V_384 , V_386 ) ;
return - V_170 ;
}
V_383 = F_208 ( V_197 , NULL ) ;
if ( F_159 ( V_383 ) )
F_225 ( L_133 ) ;
V_18 = F_226 ( & V_387 ) ;
if ( V_18 < 0 && ! F_159 ( V_383 ) )
F_227 ( V_383 ) ;
return V_18 ;
}
static void T_13 F_228 ( void )
{
F_229 ( & V_387 ) ;
F_227 ( V_383 ) ;
}
