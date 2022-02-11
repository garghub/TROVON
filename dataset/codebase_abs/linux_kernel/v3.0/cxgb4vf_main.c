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
static void F_8 ( struct V_4 * V_5 ,
struct V_20 * V_21 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_10 -> V_22 = V_21 ;
F_9 ( V_10 -> V_1 , V_10 -> V_23 , - 1 , - 1 , - 1 , - 1 , V_21 != NULL , 0 ) ;
}
static int F_10 ( struct V_4 * V_5 )
{
int V_24 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_24 = F_9 ( V_10 -> V_1 , V_10 -> V_23 , V_5 -> V_25 , - 1 , - 1 , - 1 , - 1 ,
true ) ;
if ( V_24 == 0 ) {
V_24 = F_11 ( V_10 -> V_1 , V_10 -> V_23 ,
V_10 -> V_26 , V_5 -> V_27 , true ) ;
if ( V_24 >= 0 ) {
V_10 -> V_26 = V_24 ;
V_24 = 0 ;
}
}
if ( V_24 == 0 )
V_24 = F_12 ( V_10 -> V_1 , V_10 -> V_23 , true , true ) ;
return V_24 ;
}
static void F_13 ( struct V_1 * V_1 )
{
int V_28 = sizeof( V_1 -> V_29 [ 0 ] . V_30 ) - 1 ;
int V_2 ;
snprintf ( V_1 -> V_29 [ V_31 ] . V_30 , V_28 ,
L_11 , V_1 -> V_19 ) ;
V_1 -> V_29 [ V_31 ] . V_30 [ V_28 ] = 0 ;
F_14 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
int V_32 , V_33 ;
for ( V_32 = 0 , V_33 = V_34 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_33 ++ ) {
snprintf ( V_1 -> V_29 [ V_33 ] . V_30 , V_28 ,
L_12 , V_5 -> V_19 , V_32 ) ;
V_1 -> V_29 [ V_33 ] . V_30 [ V_28 ] = 0 ;
}
}
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_37 , V_33 , V_38 ;
V_38 = F_16 ( V_1 -> V_29 [ V_31 ] . V_39 , V_40 ,
0 , V_1 -> V_29 [ V_31 ] . V_30 , & V_7 -> V_41 ) ;
if ( V_38 )
return V_38 ;
V_33 = V_34 ;
F_17 (s, rxq) {
V_38 = F_16 ( V_1 -> V_29 [ V_33 ] . V_39 ,
V_40 , 0 ,
V_1 -> V_29 [ V_33 ] . V_30 ,
& V_7 -> V_42 [ V_37 ] . V_43 ) ;
if ( V_38 )
goto V_44;
V_33 ++ ;
}
return 0 ;
V_44:
while ( -- V_37 >= 0 )
F_18 ( V_1 -> V_29 [ -- V_33 ] . V_39 , & V_7 -> V_42 [ V_37 ] . V_43 ) ;
F_18 ( V_1 -> V_29 [ V_31 ] . V_39 , & V_7 -> V_41 ) ;
return V_38 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_37 , V_33 ;
F_18 ( V_1 -> V_29 [ V_31 ] . V_39 , & V_7 -> V_41 ) ;
V_33 = V_34 ;
F_17 (s, rxq)
F_18 ( V_1 -> V_29 [ V_33 ++ ] . V_39 ,
& V_7 -> V_42 [ V_37 ] . V_43 ) ;
}
static void F_20 ( struct V_45 * V_43 )
{
F_21 ( & V_43 -> V_46 ) ;
F_22 ( V_43 -> V_1 , V_47 + V_48 ,
F_23 ( 0 ) |
F_24 ( V_43 -> V_49 ) |
F_25 ( V_43 -> V_50 ) ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
int V_37 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
F_17 (s, rxq)
F_20 ( & V_7 -> V_42 [ V_37 ] . V_43 ) ;
F_20 ( & V_7 -> V_41 ) ;
if ( V_1 -> V_51 & V_52 )
F_22 ( V_1 , V_47 + V_48 ,
F_23 ( 0 ) |
F_24 ( V_7 -> V_53 . V_49 ) |
F_25 ( V_7 -> V_53 . V_50 ) ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_37 ;
F_17 (s, rxq)
F_28 ( & V_7 -> V_42 [ V_37 ] . V_43 . V_46 ) ;
F_28 ( & V_7 -> V_41 . V_46 ) ;
}
static int F_29 ( struct V_45 * V_43 , const T_1 * V_54 ,
const struct V_55 * V_56 )
{
struct V_1 * V_1 = V_43 -> V_1 ;
T_2 V_57 = ( ( const struct V_58 * ) V_54 ) -> V_57 ;
void * V_59 = ( void * ) ( V_54 + 1 ) ;
switch ( V_57 ) {
case V_60 : {
const struct V_61 * V_62 = V_59 ;
if ( V_62 -> type == V_63 )
F_30 ( V_1 , V_62 -> V_64 ) ;
break;
}
case V_65 : {
const struct V_66 * V_67 = ( void * ) V_59 ;
unsigned int V_68 = F_31 ( F_32 ( V_67 -> V_69 ) ) ;
struct V_36 * V_7 = & V_1 -> V_36 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
unsigned int V_74 ;
V_74 = F_33 ( V_7 , V_68 ) ;
if ( F_34 ( V_74 >= V_75 ) ) {
F_35 ( V_1 -> V_76 ,
L_13 , V_68 ) ;
break;
}
V_71 = V_7 -> V_77 [ V_74 ] ;
if ( F_34 ( V_71 == NULL ) ) {
F_35 ( V_1 -> V_76 ,
L_14 , V_68 ) ;
break;
}
V_73 = F_36 ( V_71 , struct V_72 , V_78 ) ;
if ( F_34 ( V_71 -> V_79 != V_68 ) ) {
F_35 ( V_1 -> V_76 ,
L_15 ,
V_68 , V_71 -> V_79 ) ;
break;
}
V_73 -> V_78 . V_80 ++ ;
F_37 ( V_73 -> V_73 ) ;
break;
}
default:
F_35 ( V_1 -> V_76 ,
L_16 , V_57 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_38 , V_2 , V_81 ;
F_39 ( V_7 -> V_82 , V_75 ) ;
if ( V_1 -> V_51 & V_52 ) {
V_38 = F_40 ( V_1 , & V_7 -> V_53 , false ,
V_1 -> V_6 [ 0 ] , 0 , NULL , NULL ) ;
if ( V_38 )
goto V_83;
}
V_38 = F_40 ( V_1 , & V_7 -> V_41 , true , V_1 -> V_6 [ 0 ] ,
V_31 , NULL , F_29 ) ;
if ( V_38 )
goto V_83;
V_81 = V_34 ;
F_14 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_84 * V_37 = & V_7 -> V_42 [ V_10 -> V_85 ] ;
struct V_72 * V_73 = & V_7 -> V_86 [ V_10 -> V_85 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_73 ++ ) {
V_38 = F_40 ( V_1 , & V_37 -> V_43 , false ,
V_5 , V_81 ++ ,
& V_37 -> V_87 , V_88 ) ;
if ( V_38 )
goto V_83;
V_38 = F_41 ( V_1 , V_73 , V_5 ,
F_42 ( V_5 , V_32 ) ,
V_7 -> V_41 . V_50 ) ;
if ( V_38 )
goto V_83;
V_37 -> V_43 . V_89 = V_32 ;
memset ( & V_37 -> V_90 , 0 , sizeof( V_37 -> V_90 ) ) ;
}
}
V_7 -> V_91 = V_7 -> V_86 [ 0 ] . V_78 . V_79 - V_7 -> V_86 [ 0 ] . V_78 . V_50 ;
V_7 -> V_92 = V_7 -> V_42 [ 0 ] . V_43 . V_79 - V_7 -> V_42 [ 0 ] . V_43 . V_50 ;
F_43 ( V_7 , V_7 -> V_41 . V_79 ) = & V_7 -> V_41 ;
F_14 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_84 * V_37 = & V_7 -> V_42 [ V_10 -> V_85 ] ;
struct V_72 * V_73 = & V_7 -> V_86 [ V_10 -> V_85 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_73 ++ ) {
F_43 ( V_7 , V_37 -> V_43 . V_79 ) = & V_37 -> V_43 ;
F_44 ( V_7 , V_73 -> V_78 . V_79 ) = & V_73 -> V_78 ;
V_37 -> V_87 . V_79 = V_37 -> V_87 . V_50 + V_7 -> V_91 ;
F_44 ( V_7 , V_37 -> V_87 . V_79 ) = & V_37 -> V_87 ;
}
}
return 0 ;
V_83:
F_45 ( V_1 ) ;
return V_38 ;
}
static int F_46 ( struct V_1 * V_1 )
{
int V_2 ;
F_14 (adapter, pidx) {
struct V_9 * V_10 = F_47 ( V_1 , V_2 ) ;
struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] ;
T_3 V_93 [ V_94 ] ;
int V_32 , V_38 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ )
V_93 [ V_32 ] = V_37 [ V_32 ] . V_43 . V_79 ;
V_38 = F_48 ( V_1 , V_10 -> V_23 ,
0 , V_10 -> V_95 , V_93 , V_10 -> V_35 ) ;
if ( V_38 )
return V_38 ;
switch ( V_1 -> V_96 . V_93 . V_97 ) {
case V_98 :
if ( ! V_1 -> V_96 . V_93 . V_99 . V_100 . V_101 ) {
union V_102 V_103 ;
V_38 = F_49 ( V_1 ,
V_10 -> V_23 ,
& V_103 ) ;
if ( V_38 )
return V_38 ;
V_103 . V_100 . V_104 =
V_37 [ 0 ] . V_43 . V_79 ;
V_38 = F_50 ( V_1 ,
V_10 -> V_23 ,
& V_103 ) ;
if ( V_38 )
return V_38 ;
}
break;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_1 )
{
int V_38 ;
if ( ( V_1 -> V_51 & V_105 ) == 0 ) {
V_38 = F_38 ( V_1 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_46 ( V_1 ) ;
if ( V_38 ) {
F_45 ( V_1 ) ;
return V_38 ;
}
if ( V_1 -> V_51 & V_106 )
F_13 ( V_1 ) ;
V_1 -> V_51 |= V_105 ;
}
F_52 ( ( V_1 -> V_51 & ( V_106 | V_52 ) ) == 0 ) ;
if ( V_1 -> V_51 & V_106 )
V_38 = F_15 ( V_1 ) ;
else
V_38 = F_16 ( V_1 -> V_107 -> V_108 ,
F_53 ( V_1 ) , 0 ,
V_1 -> V_19 , V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_17 ,
V_38 ) ;
return V_38 ;
}
F_26 ( V_1 ) ;
F_54 ( V_1 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_1 )
{
if ( V_1 -> V_51 & V_106 )
F_19 ( V_1 ) ;
else
F_18 ( V_1 -> V_107 -> V_108 , V_1 ) ;
F_27 ( V_1 ) ;
}
static int F_56 ( struct V_4 * V_5 )
{
int V_38 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_109 == 0 ) {
V_38 = F_51 ( V_1 ) ;
if ( V_38 )
return V_38 ;
}
F_57 ( V_5 , V_10 -> V_35 ) ;
V_38 = F_58 ( V_5 , V_10 -> V_35 ) ;
if ( V_38 )
goto V_110;
V_38 = F_10 ( V_5 ) ;
if ( V_38 )
goto V_110;
F_59 ( V_5 ) ;
F_60 ( V_10 -> V_111 , & V_1 -> V_109 ) ;
return 0 ;
V_110:
if ( V_1 -> V_109 == 0 )
F_55 ( V_1 ) ;
return V_38 ;
}
static int F_61 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
F_62 ( V_5 ) ;
F_7 ( V_5 ) ;
F_12 ( V_1 , V_10 -> V_23 , false , false ) ;
V_10 -> V_11 . V_3 = 0 ;
F_63 ( V_10 -> V_111 , & V_1 -> V_109 ) ;
if ( V_1 -> V_109 == 0 )
F_55 ( V_1 ) ;
return 0 ;
}
static struct V_112 * F_64 ( struct V_4 * V_5 )
{
struct V_113 V_90 ;
struct V_9 * V_10 = F_65 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_112 * V_114 = & V_5 -> V_90 ;
int V_38 ;
F_66 ( & V_1 -> V_115 ) ;
V_38 = F_67 ( V_1 , V_10 -> V_2 , & V_90 ) ;
F_68 ( & V_1 -> V_115 ) ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
if ( V_38 )
return V_114 ;
V_114 -> V_116 = ( V_90 . V_117 + V_90 . V_118 +
V_90 . V_119 + V_90 . V_120 ) ;
V_114 -> V_121 = ( V_90 . V_122 + V_90 . V_123 +
V_90 . V_124 + V_90 . V_125 ) ;
V_114 -> V_126 = ( V_90 . V_127 + V_90 . V_128 +
V_90 . V_129 ) ;
V_114 -> V_130 = ( V_90 . V_131 + V_90 . V_132 +
V_90 . V_133 ) ;
V_114 -> V_134 = V_90 . V_132 ;
V_114 -> V_135 = V_90 . V_136 ;
V_114 -> V_137 = V_90 . V_138 ;
return V_114 ;
}
static inline unsigned int F_69 ( const struct V_4 * V_5 ,
const T_2 * * V_139 ,
unsigned int V_140 ,
unsigned int V_141 )
{
unsigned int V_142 = 0 ;
unsigned int V_143 = 0 ;
const struct V_144 * V_145 ;
F_70 (dev, ha)
if ( V_142 ++ >= V_140 ) {
V_139 [ V_143 ++ ] = V_145 -> V_139 ;
if ( V_143 >= V_141 )
break;
}
return V_143 ;
}
static inline unsigned int F_71 ( const struct V_4 * V_5 ,
const T_2 * * V_139 ,
unsigned int V_140 ,
unsigned int V_141 )
{
unsigned int V_142 = 0 ;
unsigned int V_143 = 0 ;
const struct V_144 * V_145 ;
F_72 (ha, dev)
if ( V_142 ++ >= V_140 ) {
V_139 [ V_143 ++ ] = V_145 -> V_139 ;
if ( V_143 >= V_141 )
break;
}
return V_143 ;
}
static int F_73 ( const struct V_4 * V_5 , bool V_146 )
{
T_4 V_147 = 0 ;
T_4 V_148 = 0 ;
bool free = true ;
unsigned int V_140 , V_143 ;
const T_2 * V_139 [ 7 ] ;
int V_24 ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
for ( V_140 = 0 ; ; V_140 += V_143 ) {
V_143 = F_69 ( V_5 , V_139 , V_140 ,
F_74 ( V_139 ) ) ;
if ( V_143 == 0 )
break;
V_24 = F_75 ( V_10 -> V_1 , V_10 -> V_23 , free ,
V_143 , V_139 , NULL , & V_148 , V_146 ) ;
if ( V_24 < 0 )
return V_24 ;
free = false ;
}
for ( V_140 = 0 ; ; V_140 += V_143 ) {
V_143 = F_71 ( V_5 , V_139 , V_140 ,
F_74 ( V_139 ) ) ;
if ( V_143 == 0 )
break;
V_24 = F_75 ( V_10 -> V_1 , V_10 -> V_23 , free ,
V_143 , V_139 , NULL , & V_147 , V_146 ) ;
if ( V_24 < 0 )
return V_24 ;
free = false ;
}
return F_76 ( V_10 -> V_1 , V_10 -> V_23 , V_148 != 0 ,
V_148 | V_147 , V_146 ) ;
}
static int F_77 ( struct V_4 * V_5 , int V_25 , bool V_149 )
{
int V_24 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_24 = F_73 ( V_5 , V_149 ) ;
if ( V_24 == 0 )
V_24 = F_9 ( V_10 -> V_1 , V_10 -> V_23 , - 1 ,
( V_5 -> V_51 & V_150 ) != 0 ,
( V_5 -> V_51 & V_151 ) != 0 ,
1 , - 1 , V_149 ) ;
return V_24 ;
}
static void F_78 ( struct V_4 * V_5 )
{
F_77 ( V_5 , - 1 , false ) ;
}
static int F_79 ( const struct V_36 * V_7 , int V_152 )
{
int V_153 , V_154 = 0 , V_155 = V_156 ;
for ( V_153 = 0 ; V_153 < F_74 ( V_7 -> V_157 ) ; V_153 ++ ) {
int V_158 = V_152 - V_7 -> V_157 [ V_153 ] ;
if ( V_158 < 0 )
V_158 = - V_158 ;
if ( V_158 < V_155 ) {
V_155 = V_158 ;
V_154 = V_153 ;
}
}
return V_154 ;
}
static int F_80 ( const struct V_36 * V_7 , int V_159 )
{
int V_153 , V_158 , V_160 = 0 , V_155 = V_156 ;
for ( V_153 = 0 ; V_153 < F_74 ( V_7 -> V_161 ) ; V_153 ++ ) {
V_158 = V_159 - V_7 -> V_161 [ V_153 ] ;
if ( V_158 < 0 )
V_158 = - V_158 ;
if ( V_158 < V_155 ) {
V_155 = V_158 ;
V_160 = V_153 ;
}
}
return V_160 ;
}
static unsigned int F_81 ( const struct V_1 * V_1 ,
const struct V_45 * V_43 )
{
unsigned int V_154 = F_82 ( V_43 -> V_49 ) ;
return V_154 < V_162
? V_1 -> V_36 . V_157 [ V_154 ]
: 0 ;
}
static int F_83 ( struct V_1 * V_1 , struct V_45 * V_43 ,
unsigned int V_152 , unsigned int V_163 )
{
unsigned int V_154 ;
if ( ( V_152 | V_163 ) == 0 )
V_163 = 1 ;
if ( V_163 ) {
int V_38 ;
T_5 V_164 , V_160 ;
V_160 = F_80 ( & V_1 -> V_36 , V_163 ) ;
if ( V_43 -> V_30 && V_43 -> V_160 != V_160 ) {
V_164 = F_84 ( V_165 ) |
F_85 (
V_166 ) |
F_86 ( V_43 -> V_50 ) ;
V_38 = F_87 ( V_1 , 1 , & V_164 , & V_160 ) ;
if ( V_38 )
return V_38 ;
}
V_43 -> V_160 = V_160 ;
}
V_154 = ( V_152 == 0
? V_167
: F_79 ( & V_1 -> V_36 , V_152 ) ) ;
V_43 -> V_49 = ( F_88 ( V_154 ) |
( V_163 > 0 ? V_168 : 0 ) ) ;
return 0 ;
}
static inline unsigned int F_89 ( const struct V_1 * V_1 )
{
return 4 | ( 0x3f << 10 ) ;
}
static int F_90 ( struct V_4 * V_5 , struct V_169 * V_170 , int V_171 )
{
int V_24 = 0 ;
switch ( V_171 ) {
default:
V_24 = - V_172 ;
break;
}
return V_24 ;
}
static int F_91 ( struct V_4 * V_5 , int V_173 )
{
int V_24 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_173 < 81 )
return - V_174 ;
V_24 = F_9 ( V_10 -> V_1 , V_10 -> V_23 , V_173 ,
- 1 , - 1 , - 1 , - 1 , true ) ;
if ( ! V_24 )
V_5 -> V_25 = V_173 ;
return V_24 ;
}
static int F_92 ( struct V_4 * V_5 , void * V_175 )
{
int V_24 ;
struct V_176 * V_139 = V_175 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! F_93 ( V_139 -> V_177 ) )
return - V_174 ;
V_24 = F_11 ( V_10 -> V_1 , V_10 -> V_23 , V_10 -> V_26 ,
V_139 -> V_177 , true ) ;
if ( V_24 < 0 )
return V_24 ;
memcpy ( V_5 -> V_27 , V_139 -> V_177 , V_5 -> V_178 ) ;
V_10 -> V_26 = V_24 ;
return 0 ;
}
static void F_94 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_51 & V_106 ) {
struct V_84 * V_37 ;
int V_35 ;
V_37 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] ;
for ( V_35 = V_10 -> V_35 ; V_35 ; V_35 -- ) {
V_40 ( 0 , & V_37 -> V_43 ) ;
V_37 ++ ;
}
} else
F_53 ( V_1 ) ( 0 , V_1 ) ;
}
static int F_95 ( struct V_4 * V_5 ,
struct V_179 * V_171 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
V_171 -> V_180 = V_10 -> V_11 . V_180 ;
V_171 -> V_181 = V_10 -> V_11 . V_181 ;
F_96 ( V_171 ,
F_3 ( V_5 ) ? V_10 -> V_11 . V_12 : - 1 ) ;
V_171 -> V_182 = V_183 ;
V_171 -> V_6 = ( V_171 -> V_180 & V_184 ) ? V_185 : V_186 ;
V_171 -> V_187 = V_10 -> V_111 ;
V_171 -> V_188 = V_189 ;
V_171 -> V_190 = V_10 -> V_11 . V_190 ;
V_171 -> V_191 = 0 ;
V_171 -> V_192 = 0 ;
return 0 ;
}
static void F_97 ( struct V_4 * V_5 ,
struct V_193 * V_194 )
{
struct V_1 * V_1 = F_98 ( V_5 ) ;
strcpy ( V_194 -> V_195 , V_196 ) ;
strcpy ( V_194 -> V_197 , V_198 ) ;
strcpy ( V_194 -> V_199 , F_99 ( F_100 ( V_5 -> V_5 . V_200 ) ) ) ;
snprintf ( V_194 -> V_201 , sizeof( V_194 -> V_201 ) ,
L_18 ,
F_101 ( V_1 -> V_96 . V_5 . V_202 ) ,
F_102 ( V_1 -> V_96 . V_5 . V_202 ) ,
F_103 ( V_1 -> V_96 . V_5 . V_202 ) ,
F_104 ( V_1 -> V_96 . V_5 . V_202 ) ,
F_101 ( V_1 -> V_96 . V_5 . V_203 ) ,
F_102 ( V_1 -> V_96 . V_5 . V_203 ) ,
F_103 ( V_1 -> V_96 . V_5 . V_203 ) ,
F_104 ( V_1 -> V_96 . V_5 . V_203 ) ) ;
}
static T_5 F_105 ( struct V_4 * V_5 )
{
return F_98 ( V_5 ) -> V_204 ;
}
static void F_106 ( struct V_4 * V_5 , T_5 V_205 )
{
F_98 ( V_5 ) -> V_204 = V_205 ;
}
static void F_107 ( struct V_4 * V_5 ,
struct V_206 * V_207 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_36 * V_7 = & V_10 -> V_1 -> V_36 ;
V_207 -> V_208 = V_209 ;
V_207 -> V_210 = V_211 ;
V_207 -> V_212 = 0 ;
V_207 -> V_213 = V_214 ;
V_207 -> V_215 = V_7 -> V_42 [ V_10 -> V_85 ] . V_87 . V_216 - V_217 ;
V_207 -> V_218 = V_7 -> V_42 [ V_10 -> V_85 ] . V_43 . V_216 ;
V_207 -> V_219 = 0 ;
V_207 -> V_220 = V_7 -> V_86 [ V_10 -> V_85 ] . V_78 . V_216 ;
}
static int F_108 ( struct V_4 * V_5 ,
struct V_206 * V_207 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_32 ;
if ( V_207 -> V_215 > V_209 ||
V_207 -> V_219 ||
V_207 -> V_220 > V_214 ||
V_207 -> V_218 > V_211 ||
V_207 -> V_218 < V_221 ||
V_207 -> V_215 < V_222 ||
V_207 -> V_220 < V_223 )
return - V_174 ;
if ( V_1 -> V_51 & V_105 )
return - V_224 ;
for ( V_32 = V_10 -> V_85 ; V_32 < V_10 -> V_85 + V_10 -> V_35 ; V_32 ++ ) {
V_7 -> V_42 [ V_32 ] . V_87 . V_216 = V_207 -> V_215 + V_217 ;
V_7 -> V_42 [ V_32 ] . V_43 . V_216 = V_207 -> V_218 ;
V_7 -> V_86 [ V_32 ] . V_78 . V_216 = V_207 -> V_220 ;
}
return 0 ;
}
static int F_109 ( struct V_4 * V_5 ,
struct V_225 * V_226 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_45 * V_43 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ;
V_226 -> V_227 = F_81 ( V_1 , V_43 ) ;
V_226 -> V_228 =
( ( V_43 -> V_49 & V_168 )
? V_1 -> V_36 . V_161 [ V_43 -> V_160 ]
: 0 ) ;
return 0 ;
}
static int F_110 ( struct V_4 * V_5 ,
struct V_225 * V_226 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_83 ( V_1 ,
& V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ,
V_226 -> V_227 ,
V_226 -> V_228 ) ;
}
static void F_111 ( struct V_4 * V_5 ,
struct V_229 * V_230 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_230 -> V_190 = ( V_10 -> V_11 . V_231 & V_232 ) != 0 ;
V_230 -> V_233 = ( V_10 -> V_11 . V_8 & V_16 ) != 0 ;
V_230 -> V_234 = ( V_10 -> V_11 . V_8 & V_17 ) != 0 ;
}
static int F_112 ( struct V_4 * V_5 ,
enum V_235 V_236 )
{
unsigned int V_237 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_236 == V_238 )
V_237 = 0xffff ;
else if ( V_236 == V_239 )
V_237 = 0 ;
else
return - V_174 ;
return F_113 ( V_10 -> V_1 , V_10 -> V_23 , V_237 ) ;
}
static int F_114 ( struct V_4 * V_5 , int V_240 )
{
switch ( V_240 ) {
case V_241 :
return F_74 ( V_242 ) ;
default:
return - V_172 ;
}
}
static void F_115 ( struct V_4 * V_5 ,
T_5 V_240 ,
T_2 * V_64 )
{
switch ( V_240 ) {
case V_241 :
memcpy ( V_64 , V_242 , sizeof( V_242 ) ) ;
break;
}
}
static void F_116 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_243 * V_90 )
{
const struct V_72 * V_73 = & V_1 -> V_36 . V_86 [ V_10 -> V_85 ] ;
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] ;
int V_32 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_73 ++ ) {
V_90 -> V_244 += V_73 -> V_244 ;
V_90 -> V_245 += V_73 -> V_246 ;
V_90 -> V_247 += V_37 -> V_90 . V_248 ;
V_90 -> V_249 += V_37 -> V_90 . V_249 ;
V_90 -> V_250 += V_73 -> V_250 ;
V_90 -> V_251 += V_37 -> V_90 . V_251 ;
V_90 -> V_252 += V_37 -> V_90 . V_252 ;
}
}
static void F_117 ( struct V_4 * V_5 ,
struct V_253 * V_90 ,
T_4 * V_64 )
{
struct V_9 * V_10 = F_65 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_38 = F_67 ( V_1 , V_10 -> V_2 ,
(struct V_113 * ) V_64 ) ;
if ( V_38 )
memset ( V_64 , 0 , sizeof( struct V_113 ) ) ;
V_64 += sizeof( struct V_113 ) / sizeof( T_4 ) ;
F_116 ( V_1 , V_10 , (struct V_243 * ) V_64 ) ;
}
static int F_118 ( struct V_4 * V_5 )
{
return V_254 ;
}
static void F_119 ( struct V_1 * V_1 , void * V_255 ,
unsigned int V_256 , unsigned int V_257 )
{
T_5 * V_258 = V_255 + V_256 - V_259 ;
for ( ; V_256 <= V_257 ; V_256 += sizeof( T_5 ) ) {
if ( V_256 == V_260 + V_261 )
* V_258 ++ = 0xffff ;
else
* V_258 ++ = F_120 ( V_1 , V_256 ) ;
}
}
static void F_121 ( struct V_4 * V_5 ,
struct V_262 * V_263 ,
void * V_255 )
{
struct V_1 * V_1 = F_98 ( V_5 ) ;
V_263 -> V_197 = F_89 ( V_1 ) ;
memset ( V_255 , 0 , V_254 ) ;
F_119 ( V_1 , V_255 ,
V_47 + V_264 ,
V_47 + V_265 ) ;
F_119 ( V_1 , V_255 ,
V_266 + V_267 ,
V_266 + V_268 ) ;
F_119 ( V_1 , V_255 ,
V_269 + V_270 ,
V_269 + V_271 ) ;
F_119 ( V_1 , V_255 ,
V_260 + V_272 ,
V_260 + V_273 ) ;
F_119 ( V_1 , V_255 ,
V_274 + V_275 ,
V_274 + V_276 ) ;
}
static void F_122 ( struct V_4 * V_5 ,
struct V_277 * V_278 )
{
V_278 -> V_180 = 0 ;
V_278 -> V_279 = 0 ;
memset ( & V_278 -> V_280 , 0 , sizeof( V_278 -> V_280 ) ) ;
}
static int F_123 ( struct V_281 * V_282 , void * V_164 )
{
struct V_1 * V_1 = V_282 -> V_283 ;
int V_284 = F_124 ( V_1 -> V_36 . V_285 , V_286 ) ;
int V_32 , V_287 = ( V_288 ) V_164 - 1 ;
if ( V_287 )
F_125 ( V_282 , '\n' ) ;
#define F_126 ( T_6 , V_7 , V_164 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_127 ( V_7 , V_164 ) S3("s", s, v)
#define F_128 ( V_7 , V_164 ) S3("u", s, txq[qs].v)
#define F_129 ( V_7 , V_164 ) S3("u", s, rxq[qs].v)
if ( V_287 < V_284 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_287 * V_286 ] ;
const struct V_72 * V_73 = & V_1 -> V_36 . V_86 [ V_287 * V_286 ] ;
int V_289 = F_130 ( V_286 , V_1 -> V_36 . V_285 - V_286 * V_287 ) ;
F_127 ( L_19 , L_20 ) ;
F_127 ( L_21 ,
( V_37 [ V_32 ] . V_43 . V_290
? V_37 [ V_32 ] . V_43 . V_290 -> V_19
: L_22 ) ) ;
F_126 ( L_23 , L_24 ,
( V_37 [ V_32 ] . V_43 . V_290
? ( (struct V_9 * )
F_4 ( V_37 [ V_32 ] . V_43 . V_290 ) ) -> V_111
: - 1 ) ) ;
F_128 ( L_25 , V_78 . V_79 ) ;
F_128 ( L_26 , V_78 . V_216 ) ;
F_128 ( L_27 , V_78 . V_291 ) ;
F_128 ( L_28 , V_78 . V_2 ) ;
F_128 ( L_29 , V_78 . V_292 ) ;
F_129 ( L_30 , V_43 . V_79 ) ;
F_129 ( L_31 , V_43 . V_216 ) ;
F_129 ( L_32 , V_43 . V_293 ) ;
F_126 ( L_33 , L_34 , F_81 ( V_1 , & V_37 [ V_32 ] . V_43 ) ) ;
F_126 ( L_33 , L_35 ,
V_1 -> V_36 . V_161 [ V_37 [ V_32 ] . V_43 . V_160 ] ) ;
F_129 ( L_36 , V_43 . V_292 ) ;
F_129 ( L_37 , V_43 . V_294 ) ;
F_129 ( L_38 , V_87 . V_79 ) ;
F_129 ( L_39 , V_87 . V_216 - V_217 ) ;
F_129 ( L_40 , V_87 . V_295 ) ;
F_129 ( L_41 , V_87 . V_2 ) ;
F_129 ( L_42 , V_87 . V_292 ) ;
return 0 ;
}
V_287 -= V_284 ;
if ( V_287 == 0 ) {
const struct V_45 * V_296 = & V_1 -> V_36 . V_41 ;
F_131 ( V_282 , L_43 , L_19 , L_44 ) ;
F_131 ( V_282 , L_45 , L_30 , V_296 -> V_79 ) ;
F_131 ( V_282 , L_45 , L_34 ,
F_81 ( V_1 , V_296 ) ) ;
F_131 ( V_282 , L_45 , L_35 ,
V_1 -> V_36 . V_161 [ V_296 -> V_160 ] ) ;
F_131 ( V_282 , L_45 , L_46 , V_296 -> V_292 ) ;
F_131 ( V_282 , L_45 , L_37 , V_296 -> V_294 ) ;
} else if ( V_287 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_131 ( V_282 , L_43 , L_19 , L_47 ) ;
F_131 ( V_282 , L_45 , L_30 , V_53 -> V_79 ) ;
F_131 ( V_282 , L_45 , L_34 ,
F_81 ( V_1 , V_53 ) ) ;
F_131 ( V_282 , L_45 , L_35 ,
V_1 -> V_36 . V_161 [ V_53 -> V_160 ] ) ;
F_131 ( V_282 , L_45 , L_46 , V_53 -> V_292 ) ;
F_131 ( V_282 , L_45 , L_37 , V_53 -> V_294 ) ;
}
#undef F_129
#undef F_128
#undef F_127
#undef F_126
return 0 ;
}
static int F_132 ( const struct V_1 * V_1 )
{
return F_124 ( V_1 -> V_36 . V_285 , V_286 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_133 ( struct V_281 * V_282 , T_7 * V_297 )
{
int V_298 = F_132 ( V_282 -> V_283 ) ;
return * V_297 < V_298 ? ( void * ) ( ( V_288 ) * V_297 + 1 ) : NULL ;
}
static void F_134 ( struct V_281 * V_282 , void * V_164 )
{
}
static void * F_135 ( struct V_281 * V_282 , void * V_164 , T_7 * V_297 )
{
int V_298 = F_132 ( V_282 -> V_283 ) ;
++ * V_297 ;
return * V_297 < V_298 ? ( void * ) ( ( V_288 ) * V_297 + 1 ) : NULL ;
}
static int F_136 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
int V_301 = F_137 ( V_300 , & V_302 ) ;
if ( ! V_301 ) {
struct V_281 * V_282 = V_300 -> V_303 ;
V_282 -> V_283 = V_299 -> V_304 ;
}
return V_301 ;
}
static int F_138 ( struct V_281 * V_282 , void * V_164 )
{
struct V_1 * V_1 = V_282 -> V_283 ;
int V_284 = F_124 ( V_1 -> V_36 . V_285 , V_286 ) ;
int V_32 , V_287 = ( V_288 ) V_164 - 1 ;
if ( V_287 )
F_125 ( V_282 , '\n' ) ;
#define F_126 ( T_8 , V_7 , V_164 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_127 ( V_7 , V_164 ) S3("s", s, v)
#define F_139 ( T_8 , V_7 , V_164 ) S3(fmt, s, txq[qs].v)
#define F_128 ( V_7 , V_164 ) T3("lu", s, v)
#define F_140 ( T_8 , V_7 , V_164 ) S3(fmt, s, rxq[qs].v)
#define F_129 ( V_7 , V_164 ) R3("lu", s, v)
if ( V_287 < V_284 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_287 * V_286 ] ;
const struct V_72 * V_73 = & V_1 -> V_36 . V_86 [ V_287 * V_286 ] ;
int V_289 = F_130 ( V_286 , V_1 -> V_36 . V_285 - V_286 * V_287 ) ;
F_127 ( L_19 , L_20 ) ;
F_127 ( L_21 ,
( V_37 [ V_32 ] . V_43 . V_290
? V_37 [ V_32 ] . V_43 . V_290 -> V_19
: L_22 ) ) ;
F_140 ( L_33 , L_48 , V_43 . V_305 ) ;
F_129 ( L_49 , V_90 . V_306 ) ;
F_129 ( L_50 , V_90 . V_248 ) ;
F_129 ( L_51 , V_90 . V_249 ) ;
F_129 ( L_52 , V_90 . V_252 ) ;
F_129 ( L_53 , V_90 . V_251 ) ;
F_129 ( L_54 , V_90 . V_307 ) ;
F_128 ( L_55 , V_244 ) ;
F_128 ( L_56 , V_246 ) ;
F_128 ( L_57 , V_250 ) ;
F_128 ( L_58 , V_78 . V_308 ) ;
F_128 ( L_59 , V_78 . V_80 ) ;
F_128 ( L_60 , V_309 ) ;
F_129 ( L_61 , V_87 . V_310 ) ;
F_129 ( L_62 , V_87 . V_311 ) ;
F_129 ( L_63 , V_87 . V_312 ) ;
return 0 ;
}
V_287 -= V_284 ;
if ( V_287 == 0 ) {
const struct V_45 * V_296 = & V_1 -> V_36 . V_41 ;
F_131 ( V_282 , L_64 , L_19 , L_44 ) ;
F_131 ( V_282 , L_65 , L_48 ,
V_296 -> V_305 ) ;
F_131 ( V_282 , L_65 , L_36 , V_296 -> V_292 ) ;
F_131 ( V_282 , L_65 , L_37 , V_296 -> V_294 ) ;
} else if ( V_287 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_131 ( V_282 , L_64 , L_19 , L_47 ) ;
F_131 ( V_282 , L_65 , L_48 ,
V_53 -> V_305 ) ;
F_131 ( V_282 , L_65 , L_36 , V_53 -> V_292 ) ;
F_131 ( V_282 , L_65 , L_37 , V_53 -> V_294 ) ;
}
#undef F_129
#undef F_128
#undef F_127
#undef F_140
#undef F_139
#undef F_126
return 0 ;
}
static int F_141 ( const struct V_1 * V_1 )
{
return F_124 ( V_1 -> V_36 . V_285 , V_286 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_142 ( struct V_281 * V_282 , T_7 * V_297 )
{
int V_298 = F_141 ( V_282 -> V_283 ) ;
return * V_297 < V_298 ? ( void * ) ( ( V_288 ) * V_297 + 1 ) : NULL ;
}
static void F_143 ( struct V_281 * V_282 , void * V_164 )
{
}
static void * F_144 ( struct V_281 * V_282 , void * V_164 , T_7 * V_297 )
{
int V_298 = F_141 ( V_282 -> V_283 ) ;
( * V_297 ) ++ ;
return * V_297 < V_298 ? ( void * ) ( ( V_288 ) * V_297 + 1 ) : NULL ;
}
static int F_145 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
int V_301 = F_137 ( V_300 , & V_313 ) ;
if ( V_301 == 0 ) {
struct V_281 * V_282 = V_300 -> V_303 ;
V_282 -> V_283 = V_299 -> V_304 ;
}
return V_301 ;
}
static int F_146 ( struct V_281 * V_282 , void * V_164 )
{
struct V_1 * V_1 = V_282 -> V_283 ;
struct V_314 * V_315 = & V_1 -> V_96 . V_315 ;
#define F_127 ( V_30 , T_8 , T_9 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_127 ( L_66 , L_67 , V_316 ) ;
F_127 ( L_68 , L_67 , V_317 ) ;
F_127 ( L_69 , L_67 , V_318 ) ;
F_127 ( L_70 , L_67 , V_319 ) ;
F_127 ( L_71 , L_67 , V_320 ) ;
F_127 ( L_72 , L_67 , V_321 ) ;
F_127 ( L_73 , L_74 , V_322 ) ;
F_127 ( L_75 , L_67 , V_323 ) ;
F_127 ( L_76 , L_74 , V_324 ) ;
F_127 ( L_77 , L_74 , V_325 ) ;
#undef F_127
return 0 ;
}
static int F_147 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
return F_148 ( V_300 , F_146 , V_299 -> V_304 ) ;
}
static int F_149 ( struct V_281 * V_282 , void * V_164 )
{
if ( V_164 == V_326 ) {
F_150 ( V_282 , L_78 ) ;
} else {
struct V_1 * V_1 = V_282 -> V_283 ;
int V_2 = ( V_288 ) V_164 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_131 ( V_282 , L_79 ,
V_5 -> V_19 , V_10 -> V_111 , V_10 -> V_23 ) ;
}
return 0 ;
}
static inline void * F_151 ( struct V_1 * V_1 , T_7 V_297 )
{
return V_297 <= V_1 -> V_96 . V_327
? ( void * ) ( V_288 ) ( V_297 + 1 )
: NULL ;
}
static void * F_152 ( struct V_281 * V_282 , T_7 * V_297 )
{
return * V_297
? F_151 ( V_282 -> V_283 , * V_297 )
: V_326 ;
}
static void * F_153 ( struct V_281 * V_282 , void * V_164 , T_7 * V_297 )
{
( * V_297 ) ++ ;
return F_151 ( V_282 -> V_283 , * V_297 ) ;
}
static void F_154 ( struct V_281 * V_282 , void * V_164 )
{
}
static int F_155 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
int V_301 = F_137 ( V_300 , & V_328 ) ;
if ( V_301 == 0 ) {
struct V_281 * V_282 = V_300 -> V_303 ;
V_282 -> V_283 = V_299 -> V_304 ;
}
return V_301 ;
}
static int T_10 F_156 ( struct V_1 * V_1 )
{
int V_153 ;
F_52 ( F_157 ( V_1 -> V_329 ) ) ;
for ( V_153 = 0 ; V_153 < F_74 ( V_330 ) ; V_153 ++ )
( void ) F_158 ( V_330 [ V_153 ] . V_19 ,
V_330 [ V_153 ] . V_97 ,
V_1 -> V_329 ,
( void * ) V_1 ,
V_330 [ V_153 ] . V_331 ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_1 )
{
F_52 ( F_157 ( V_1 -> V_329 ) ) ;
}
static int T_10 F_160 ( struct V_1 * V_1 )
{
struct V_314 * V_315 = & V_1 -> V_96 . V_315 ;
struct V_332 * V_332 = & V_1 -> V_96 . V_36 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
unsigned int V_285 ;
int V_38 ;
V_38 = F_161 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_80
L_81 , V_38 ) ;
return V_38 ;
}
V_38 = F_162 ( V_1 ) ;
if ( V_38 < 0 ) {
F_35 ( V_1 -> V_76 , L_82 , V_38 ) ;
return V_38 ;
}
V_38 = F_163 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_83
L_84 , V_38 ) ;
return V_38 ;
}
V_38 = F_164 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_83
L_85 , V_38 ) ;
return V_38 ;
}
V_38 = F_165 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_83
L_86 , V_38 ) ;
return V_38 ;
}
V_38 = F_166 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_83
L_87 , V_38 ) ;
return V_38 ;
}
if ( V_1 -> V_96 . V_93 . V_97 !=
V_98 ) {
F_35 ( V_1 -> V_76 , L_88
L_89 , V_1 -> V_96 . V_93 . V_97 ) ;
return - V_174 ;
}
V_38 = F_167 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_90
L_81 , V_38 ) ;
return V_38 ;
}
V_7 -> V_157 [ 0 ] = F_168 ( V_1 ,
F_169 ( V_332 -> V_333 ) ) ;
V_7 -> V_157 [ 1 ] = F_168 ( V_1 ,
F_170 ( V_332 -> V_333 ) ) ;
V_7 -> V_157 [ 2 ] = F_168 ( V_1 ,
F_169 ( V_332 -> V_334 ) ) ;
V_7 -> V_157 [ 3 ] = F_168 ( V_1 ,
F_170 ( V_332 -> V_334 ) ) ;
V_7 -> V_157 [ 4 ] = F_168 ( V_1 ,
F_169 ( V_332 -> V_335 ) ) ;
V_7 -> V_157 [ 5 ] = F_168 ( V_1 ,
F_170 ( V_332 -> V_335 ) ) ;
V_7 -> V_161 [ 0 ] =
F_171 ( V_332 -> V_336 ) ;
V_7 -> V_161 [ 1 ] =
F_172 ( V_332 -> V_336 ) ;
V_7 -> V_161 [ 2 ] =
F_173 ( V_332 -> V_336 ) ;
V_7 -> V_161 [ 3 ] =
F_174 ( V_332 -> V_336 ) ;
V_38 = F_175 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_76 , L_91
L_92 , V_38 ) ;
return V_38 ;
}
V_1 -> V_96 . V_327 = V_315 -> V_316 ;
if ( V_1 -> V_96 . V_327 > V_337 ) {
F_176 ( V_1 -> V_76 , L_93
L_94 , V_337 ,
V_1 -> V_96 . V_327 ) ;
V_1 -> V_96 . V_327 = V_337 ;
}
V_285 = V_315 -> V_319 - V_338 ;
if ( V_315 -> V_318 != V_285 ) {
F_176 ( V_1 -> V_76 , L_95
L_96
L_97 , V_285 , V_315 -> V_318 ) ;
V_285 = F_130 ( V_315 -> V_318 , V_285 ) ;
}
if ( V_315 -> V_317 < V_285 * 2 ) {
F_176 ( V_1 -> V_76 , L_98
L_99
L_100 , V_315 -> V_317 , V_285 ) ;
V_285 = V_315 -> V_317 / 2 ;
}
if ( V_285 > V_339 ) {
F_176 ( V_1 -> V_76 , L_101
L_100 , V_339 , V_1 -> V_36 . V_340 ) ;
V_285 = V_339 ;
}
if ( V_315 -> V_320 != 0 || V_315 -> V_317 > V_285 * 2 ) {
F_176 ( V_1 -> V_76 , L_102
L_103 , V_315 -> V_320 , V_315 -> V_317 - V_285 * 2 ) ;
}
V_1 -> V_36 . V_340 = V_285 ;
if ( V_1 -> V_36 . V_340 < V_1 -> V_96 . V_327 ) {
F_176 ( V_1 -> V_76 , L_104
L_105 ,
V_1 -> V_36 . V_340 , V_1 -> V_96 . V_327 ) ;
V_1 -> V_96 . V_327 = V_1 -> V_36 . V_340 ;
}
if ( V_1 -> V_96 . V_327 == 0 ) {
F_35 ( V_1 -> V_76 , L_106
L_107 ) ;
return - V_174 ;
}
return 0 ;
}
static inline void F_177 ( struct V_45 * V_43 , T_2 V_154 ,
T_2 V_341 , unsigned int V_216 ,
unsigned int V_342 )
{
V_43 -> V_49 = ( F_88 ( V_154 ) |
( V_341 < V_343 ? V_168 : 0 ) ) ;
V_43 -> V_160 = ( V_341 < V_343
? V_341
: 0 ) ;
V_43 -> V_293 = V_342 ;
V_43 -> V_216 = V_216 ;
}
static void T_10 F_178 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_344 , V_345 , V_346 , V_2 , V_32 ;
T_11 V_342 ;
F_52 ( ( V_1 -> V_51 & ( V_106 | V_52 ) ) == 0 ) ;
V_345 = 0 ;
F_14 (adapter, pidx)
V_345 += F_179 ( & F_47 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_345 == 0 )
V_344 = 0 ;
else {
int V_347 = ( V_1 -> V_96 . V_327 - V_345 ) ;
V_344 = ( V_1 -> V_36 . V_340 - V_347 ) / V_345 ;
if ( V_344 > F_180 () )
V_344 = F_180 () ;
}
V_346 = 0 ;
F_14 (adapter, pidx) {
struct V_9 * V_10 = F_47 ( V_1 , V_2 ) ;
V_10 -> V_85 = V_346 ;
V_10 -> V_35 = F_179 ( & V_10 -> V_11 ) ? V_344 : 1 ;
V_346 += V_10 -> V_35 ;
}
V_7 -> V_285 = V_346 ;
V_342 = 64 ;
for ( V_32 = 0 ; V_32 < V_7 -> V_340 ; V_32 ++ ) {
struct V_84 * V_37 = & V_7 -> V_42 [ V_32 ] ;
struct V_72 * V_73 = & V_7 -> V_86 [ V_32 ] ;
F_177 ( & V_37 -> V_43 , 0 , 0 , 1024 , V_342 ) ;
V_37 -> V_87 . V_216 = 72 ;
V_73 -> V_78 . V_216 = 1024 ;
}
F_177 ( & V_7 -> V_41 , V_167 , 0 , 512 , V_342 ) ;
F_177 ( & V_7 -> V_53 , V_167 , 0 , V_348 + 1 ,
V_342 ) ;
}
static void T_10 F_181 ( struct V_1 * V_1 , int V_289 )
{
int V_153 ;
struct V_9 * V_10 ;
F_52 ( V_289 < V_1 -> V_96 . V_327 ) ;
while ( V_289 < V_1 -> V_36 . V_285 )
F_14 (adapter, i) {
V_10 = F_47 ( V_1 , V_153 ) ;
if ( V_10 -> V_35 > 1 ) {
V_10 -> V_35 -- ;
V_1 -> V_36 . V_285 -- ;
if ( V_1 -> V_36 . V_285 <= V_289 )
break;
}
}
V_289 = 0 ;
F_14 (adapter, i) {
V_10 = F_47 ( V_1 , V_153 ) ;
V_10 -> V_85 = V_289 ;
V_289 += V_10 -> V_35 ;
}
}
static int T_10 F_182 ( struct V_1 * V_1 )
{
int V_153 , V_38 , V_349 , V_350 ;
struct V_351 V_298 [ V_348 ] ;
struct V_36 * V_7 = & V_1 -> V_36 ;
for ( V_153 = 0 ; V_153 < V_348 ; ++ V_153 )
V_298 [ V_153 ] . V_352 = V_153 ;
V_349 = V_7 -> V_340 + V_353 ;
V_350 = V_1 -> V_96 . V_327 + V_353 ;
while ( ( V_38 = F_183 ( V_1 -> V_107 , V_298 , V_349 ) ) >= V_350 )
V_349 = V_38 ;
if ( V_38 == 0 ) {
int V_35 = V_349 - V_353 ;
if ( V_35 < V_7 -> V_340 ) {
F_176 ( V_1 -> V_76 , L_108
L_109 , V_35 ) ;
V_7 -> V_340 = V_35 ;
if ( V_35 < V_7 -> V_285 )
F_181 ( V_1 , V_35 ) ;
}
for ( V_153 = 0 ; V_153 < V_349 ; ++ V_153 )
V_1 -> V_29 [ V_153 ] . V_39 = V_298 [ V_153 ] . V_354 ;
} else if ( V_38 > 0 ) {
F_184 ( V_1 -> V_107 ) ;
F_185 ( V_1 -> V_76 , L_110
L_111 , V_38 ) ;
}
return V_38 ;
}
static int T_10 F_186 ( struct V_355 * V_107 ,
const struct V_356 * V_357 )
{
static int V_358 ;
int V_359 ;
int V_38 , V_2 ;
unsigned int V_322 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_290 ;
if ( V_358 == 0 ) {
F_6 ( V_18 L_112 , V_360 , V_198 ) ;
V_358 = 1 ;
}
V_38 = F_187 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_113 ) ;
return V_38 ;
}
V_38 = F_188 ( V_107 , V_196 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_114 ) ;
goto V_361;
}
V_38 = F_189 ( V_107 , F_190 ( 64 ) ) ;
if ( V_38 == 0 ) {
V_38 = F_191 ( V_107 , F_190 ( 64 ) ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_115
L_116 ) ;
goto V_362;
}
V_359 = 1 ;
} else {
V_38 = F_189 ( V_107 , F_190 ( 32 ) ) ;
if ( V_38 != 0 ) {
F_35 ( & V_107 -> V_5 , L_117 ) ;
goto V_362;
}
V_359 = 0 ;
}
F_192 ( V_107 ) ;
V_1 = F_193 ( sizeof( * V_1 ) , V_363 ) ;
if ( ! V_1 ) {
V_38 = - V_364 ;
goto V_362;
}
F_194 ( V_107 , V_1 ) ;
V_1 -> V_107 = V_107 ;
V_1 -> V_76 = & V_107 -> V_5 ;
F_195 ( & V_1 -> V_115 ) ;
V_1 -> V_263 = F_196 ( V_107 , 0 ) ;
if ( ! V_1 -> V_263 ) {
F_35 ( & V_107 -> V_5 , L_118 ) ;
V_38 = - V_364 ;
goto V_365;
}
V_1 -> V_19 = F_99 ( V_107 ) ;
V_1 -> V_204 = V_366 ;
V_38 = F_160 ( V_1 ) ;
if ( V_38 )
goto V_367;
V_322 = V_1 -> V_96 . V_315 . V_322 ;
F_14 (adapter, pidx) {
int V_111 , V_23 ;
if ( V_322 == 0 )
break;
V_111 = F_197 ( V_322 ) - 1 ;
V_322 &= ~ ( 1 << V_111 ) ;
V_23 = F_198 ( V_1 , V_111 ) ;
if ( V_23 < 0 ) {
F_35 ( & V_107 -> V_5 , L_119
L_81 , V_111 , V_23 ) ;
V_38 = V_23 ;
goto V_368;
}
V_290 = F_199 ( sizeof( struct V_9 ) ,
V_94 ) ;
if ( V_290 == NULL ) {
F_35 ( & V_107 -> V_5 , L_120
L_121 , V_111 ) ;
F_200 ( V_1 , V_23 ) ;
V_38 = - V_364 ;
goto V_368;
}
V_1 -> V_6 [ V_2 ] = V_290 ;
F_201 ( V_290 , & V_107 -> V_5 ) ;
V_10 = F_4 ( V_290 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_111 = V_111 ;
V_10 -> V_23 = V_23 ;
V_10 -> V_26 = - 1 ;
F_7 ( V_290 ) ;
V_290 -> V_108 = V_107 -> V_108 ;
V_290 -> V_369 = V_370 | V_371 |
V_372 | V_373 |
V_374 | V_375 ;
V_290 -> V_376 = V_370 | V_371 |
V_372 | V_373 |
V_377 ;
V_290 -> V_378 = V_290 -> V_369 |
V_379 ;
if ( V_359 )
V_290 -> V_378 |= V_377 ;
#ifdef F_202
V_290 -> V_380 = & V_381 ;
#else
V_290 -> V_382 = F_8 ;
V_290 -> V_383 = F_56 ;
V_290 -> V_384 = F_61 ;
V_290 -> V_385 = V_386 ;
V_290 -> V_387 = F_64 ;
V_290 -> V_388 = F_78 ;
V_290 -> V_389 = F_90 ;
V_290 -> V_390 = F_91 ;
V_290 -> V_391 = F_92 ;
#ifdef F_203
V_290 -> V_392 = F_94 ;
#endif
#endif
F_204 ( V_290 , & V_393 ) ;
V_38 = F_205 ( V_1 , V_2 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_122 ,
V_2 ) ;
goto V_368;
}
}
F_14 (adapter, pidx) {
V_290 = V_1 -> V_6 [ V_2 ] ;
if ( V_290 == NULL )
continue;
V_38 = F_206 ( V_290 ) ;
if ( V_38 ) {
F_176 ( & V_107 -> V_5 , L_123
L_124 , V_290 -> V_19 ) ;
continue;
}
F_60 ( V_2 , & V_1 -> V_394 ) ;
}
if ( V_1 -> V_394 == 0 ) {
F_35 ( & V_107 -> V_5 , L_125 ) ;
goto V_368;
}
if ( ! F_157 ( V_395 ) ) {
V_1 -> V_329 =
F_207 ( F_99 ( V_107 ) ,
V_395 ) ;
if ( F_157 ( V_1 -> V_329 ) )
F_176 ( & V_107 -> V_5 , L_126
L_127 ) ;
else
F_156 ( V_1 ) ;
}
if ( V_33 == V_396 && F_182 ( V_1 ) == 0 )
V_1 -> V_51 |= V_106 ;
else {
V_38 = F_208 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_128
L_81 ,
V_33 == V_396 ? L_129 : L_130 , V_38 ) ;
goto V_397;
}
V_1 -> V_51 |= V_52 ;
}
F_178 ( V_1 ) ;
F_14 (adapter, pidx) {
F_185 ( V_1 -> V_76 , L_131 ,
V_1 -> V_6 [ V_2 ] -> V_19 ,
( V_1 -> V_51 & V_106 ) ? L_132 :
( V_1 -> V_51 & V_52 ) ? L_130 : L_133 ) ;
}
return 0 ;
V_397:
if ( ! F_157 ( V_1 -> V_329 ) ) {
F_159 ( V_1 ) ;
F_209 ( V_1 -> V_329 ) ;
}
V_368:
F_14 (adapter, pidx) {
V_290 = V_1 -> V_6 [ V_2 ] ;
if ( V_290 == NULL )
continue;
V_10 = F_4 ( V_290 ) ;
F_200 ( V_1 , V_10 -> V_23 ) ;
if ( F_210 ( V_2 , & V_1 -> V_394 ) )
F_211 ( V_290 ) ;
F_212 ( V_290 ) ;
}
V_367:
F_213 ( V_1 -> V_263 ) ;
V_365:
F_214 ( V_1 ) ;
F_194 ( V_107 , NULL ) ;
V_362:
F_215 ( V_107 ) ;
F_194 ( V_107 , NULL ) ;
F_216 ( V_107 ) ;
V_361:
F_217 ( V_107 ) ;
return V_38 ;
}
static void T_12 F_218 ( struct V_355 * V_107 )
{
struct V_1 * V_1 = F_219 ( V_107 ) ;
if ( V_1 ) {
int V_2 ;
F_14 (adapter, pidx)
if ( F_210 ( V_2 , & V_1 -> V_394 ) )
F_211 ( V_1 -> V_6 [ V_2 ] ) ;
F_220 ( V_1 ) ;
if ( V_1 -> V_51 & V_106 ) {
F_184 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_221 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
if ( ! F_157 ( V_1 -> V_329 ) ) {
F_159 ( V_1 ) ;
F_209 ( V_1 -> V_329 ) ;
}
F_45 ( V_1 ) ;
F_14 (adapter, pidx) {
struct V_4 * V_290 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_290 == NULL )
continue;
V_10 = F_4 ( V_290 ) ;
F_200 ( V_1 , V_10 -> V_23 ) ;
F_212 ( V_290 ) ;
}
F_213 ( V_1 -> V_263 ) ;
F_214 ( V_1 ) ;
F_194 ( V_107 , NULL ) ;
}
F_217 ( V_107 ) ;
F_216 ( V_107 ) ;
F_215 ( V_107 ) ;
}
static void T_12 F_222 ( struct V_355 * V_107 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_219 ( V_107 ) ;
if ( ! V_1 )
return;
F_14 (adapter, pidx) {
struct V_4 * V_290 ;
struct V_9 * V_10 ;
if ( ! F_210 ( V_2 , & V_1 -> V_394 ) )
continue;
V_290 = V_1 -> V_6 [ V_2 ] ;
if ( ! V_290 )
continue;
V_10 = F_4 ( V_290 ) ;
F_12 ( V_1 , V_10 -> V_23 , false , false ) ;
}
F_45 ( V_1 ) ;
}
static int T_13 F_223 ( void )
{
int V_24 ;
if ( V_33 != V_396 && V_33 != V_398 ) {
F_6 (KERN_WARNING KBUILD_MODNAME
L_134
L_135 ,
msi, MSI_MSIX, MSI_MSI) ;
return - V_174 ;
}
V_395 = F_207 ( V_196 , NULL ) ;
if ( F_157 ( V_395 ) )
F_6 (KERN_WARNING KBUILD_MODNAME L_136
L_137 ) ;
V_24 = F_224 ( & V_399 ) ;
if ( V_24 < 0 && ! F_157 ( V_395 ) )
F_225 ( V_395 ) ;
return V_24 ;
}
static void T_14 F_226 ( void )
{
F_227 ( & V_399 ) ;
F_225 ( V_395 ) ;
}
