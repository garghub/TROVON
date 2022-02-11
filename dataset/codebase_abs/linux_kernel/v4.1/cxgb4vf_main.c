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
void F_8 ( struct V_1 * V_1 , int V_2 )
{
static const char * const V_15 [] = {
NULL , L_12 , L_13 , L_14 , L_15 , L_16 , L_17
} ;
const struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_10 -> V_16 == V_17 )
F_9 ( V_1 -> V_18 , L_18 ,
V_5 -> V_19 ) ;
else if ( V_10 -> V_16 < F_10 ( V_15 ) )
F_9 ( V_1 -> V_18 , L_19 ,
V_5 -> V_19 , V_15 [ V_10 -> V_16 ] ) ;
else if ( V_10 -> V_16 == V_20 )
F_9 ( V_1 -> V_18 , L_20
L_21 , V_5 -> V_19 ) ;
else if ( V_10 -> V_16 == V_21 )
F_9 ( V_1 -> V_18 , L_22
L_23 , V_5 -> V_19 ) ;
else if ( V_10 -> V_16 == V_22 )
F_9 ( V_1 -> V_18 , L_24 ,
V_5 -> V_19 ) ;
else
F_9 ( V_1 -> V_18 , L_25
L_26 , V_5 -> V_19 , V_10 -> V_16 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
int V_23 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_23 = F_12 ( V_10 -> V_1 , V_10 -> V_24 , V_5 -> V_25 , - 1 , - 1 , - 1 , 1 ,
true ) ;
if ( V_23 == 0 ) {
V_23 = F_13 ( V_10 -> V_1 , V_10 -> V_24 ,
V_10 -> V_26 , V_5 -> V_27 , true ) ;
if ( V_23 >= 0 ) {
V_10 -> V_26 = V_23 ;
V_23 = 0 ;
}
}
if ( V_23 == 0 )
V_23 = F_14 ( V_10 -> V_1 , V_10 -> V_24 , true , true ) ;
return V_23 ;
}
static void F_15 ( struct V_1 * V_1 )
{
int V_28 = sizeof( V_1 -> V_29 [ 0 ] . V_30 ) - 1 ;
int V_2 ;
snprintf ( V_1 -> V_29 [ V_31 ] . V_30 , V_28 ,
L_27 , V_1 -> V_19 ) ;
V_1 -> V_29 [ V_31 ] . V_30 [ V_28 ] = 0 ;
F_16 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
int V_32 , V_33 ;
for ( V_32 = 0 , V_33 = V_34 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_33 ++ ) {
snprintf ( V_1 -> V_29 [ V_33 ] . V_30 , V_28 ,
L_28 , V_5 -> V_19 , V_32 ) ;
V_1 -> V_29 [ V_33 ] . V_30 [ V_28 ] = 0 ;
}
}
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_37 , V_33 , V_38 ;
V_38 = F_18 ( V_1 -> V_29 [ V_31 ] . V_39 , V_40 ,
0 , V_1 -> V_29 [ V_31 ] . V_30 , & V_7 -> V_41 ) ;
if ( V_38 )
return V_38 ;
V_33 = V_34 ;
F_19 (s, rxq) {
V_38 = F_18 ( V_1 -> V_29 [ V_33 ] . V_39 ,
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
F_20 ( V_1 -> V_29 [ -- V_33 ] . V_39 , & V_7 -> V_42 [ V_37 ] . V_43 ) ;
F_20 ( V_1 -> V_29 [ V_31 ] . V_39 , & V_7 -> V_41 ) ;
return V_38 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_37 , V_33 ;
F_20 ( V_1 -> V_29 [ V_31 ] . V_39 , & V_7 -> V_41 ) ;
V_33 = V_34 ;
F_19 (s, rxq)
F_20 ( V_1 -> V_29 [ V_33 ++ ] . V_39 ,
& V_7 -> V_42 [ V_37 ] . V_43 ) ;
}
static void F_22 ( struct V_45 * V_43 )
{
F_23 ( & V_43 -> V_46 ) ;
F_24 ( V_43 -> V_1 , V_47 + V_48 ,
F_25 ( 0 ) |
F_26 ( V_43 -> V_49 ) |
F_27 ( V_43 -> V_50 ) ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
int V_37 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
F_19 (s, rxq)
F_22 ( & V_7 -> V_42 [ V_37 ] . V_43 ) ;
F_22 ( & V_7 -> V_41 ) ;
if ( V_1 -> V_51 & V_52 )
F_24 ( V_1 , V_47 + V_48 ,
F_25 ( 0 ) |
F_26 ( V_7 -> V_53 . V_49 ) |
F_27 ( V_7 -> V_53 . V_50 ) ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_37 ;
F_19 (s, rxq)
F_30 ( & V_7 -> V_42 [ V_37 ] . V_43 . V_46 ) ;
F_30 ( & V_7 -> V_41 . V_46 ) ;
}
static int F_31 ( struct V_45 * V_43 , const T_1 * V_54 ,
const struct V_55 * V_56 )
{
struct V_1 * V_1 = V_43 -> V_1 ;
T_2 V_57 = ( ( const struct V_58 * ) V_54 ) -> V_57 ;
void * V_59 = ( void * ) ( V_54 + 1 ) ;
switch ( V_57 ) {
case V_60 : {
const struct V_61 * V_62 = V_59 ;
if ( V_62 -> type == V_63 )
F_32 ( V_1 , V_62 -> V_64 ) ;
break;
}
case V_65 : {
const struct V_66 * V_67 = ( void * ) ( V_54 + 3 ) ;
V_57 = F_33 ( F_34 ( V_67 -> V_68 ) ) ;
if ( V_57 != V_69 ) {
F_35 ( V_1 -> V_18 , L_29
, V_57 ) ;
break;
}
V_59 = ( void * ) V_67 ;
}
case V_69 : {
const struct V_66 * V_67 = V_59 ;
unsigned int V_70 = F_36 ( F_37 ( V_67 -> V_68 ) ) ;
struct V_36 * V_7 = & V_1 -> V_36 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
unsigned int V_75 ;
V_75 = F_38 ( V_7 , V_70 ) ;
if ( F_39 ( V_75 >= V_76 ) ) {
F_35 ( V_1 -> V_18 ,
L_30 , V_70 ) ;
break;
}
V_72 = V_7 -> V_77 [ V_75 ] ;
if ( F_39 ( V_72 == NULL ) ) {
F_35 ( V_1 -> V_18 ,
L_31 , V_70 ) ;
break;
}
V_74 = F_40 ( V_72 , struct V_73 , V_78 ) ;
if ( F_39 ( V_72 -> V_79 != V_70 ) ) {
F_35 ( V_1 -> V_18 ,
L_32 ,
V_70 , V_72 -> V_79 ) ;
break;
}
V_74 -> V_78 . V_80 ++ ;
F_41 ( V_74 -> V_74 ) ;
break;
}
default:
F_35 ( V_1 -> V_18 ,
L_33 , V_57 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_38 , V_2 , V_81 ;
F_43 ( V_7 -> V_82 , V_76 ) ;
if ( V_1 -> V_51 & V_52 ) {
V_38 = F_44 ( V_1 , & V_7 -> V_53 , false ,
V_1 -> V_6 [ 0 ] , 0 , NULL , NULL ) ;
if ( V_38 )
goto V_83;
}
V_38 = F_44 ( V_1 , & V_7 -> V_41 , true , V_1 -> V_6 [ 0 ] ,
V_31 , NULL , F_31 ) ;
if ( V_38 )
goto V_83;
V_81 = V_34 ;
F_16 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_84 * V_37 = & V_7 -> V_42 [ V_10 -> V_85 ] ;
struct V_73 * V_74 = & V_7 -> V_86 [ V_10 -> V_85 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_74 ++ ) {
V_38 = F_44 ( V_1 , & V_37 -> V_43 , false ,
V_5 , V_81 ++ ,
& V_37 -> V_87 , V_88 ) ;
if ( V_38 )
goto V_83;
V_38 = F_45 ( V_1 , V_74 , V_5 ,
F_46 ( V_5 , V_32 ) ,
V_7 -> V_41 . V_50 ) ;
if ( V_38 )
goto V_83;
V_37 -> V_43 . V_89 = V_32 ;
memset ( & V_37 -> V_90 , 0 , sizeof( V_37 -> V_90 ) ) ;
}
}
V_7 -> V_91 = V_7 -> V_86 [ 0 ] . V_78 . V_79 - V_7 -> V_86 [ 0 ] . V_78 . V_50 ;
V_7 -> V_92 = V_7 -> V_42 [ 0 ] . V_43 . V_79 - V_7 -> V_42 [ 0 ] . V_43 . V_50 ;
F_47 ( V_7 , V_7 -> V_41 . V_79 ) = & V_7 -> V_41 ;
F_16 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_84 * V_37 = & V_7 -> V_42 [ V_10 -> V_85 ] ;
struct V_73 * V_74 = & V_7 -> V_86 [ V_10 -> V_85 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_74 ++ ) {
F_47 ( V_7 , V_37 -> V_43 . V_79 ) = & V_37 -> V_43 ;
F_48 ( V_7 , V_74 -> V_78 . V_79 ) = & V_74 -> V_78 ;
V_37 -> V_87 . V_79 = V_37 -> V_87 . V_50 + V_7 -> V_91 ;
F_48 ( V_7 , V_37 -> V_87 . V_79 ) = & V_37 -> V_87 ;
}
}
return 0 ;
V_83:
F_49 ( V_1 ) ;
return V_38 ;
}
static int F_50 ( struct V_1 * V_1 )
{
int V_2 ;
F_16 (adapter, pidx) {
struct V_9 * V_10 = F_51 ( V_1 , V_2 ) ;
struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] ;
T_3 V_93 [ V_94 ] ;
int V_32 , V_38 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ )
V_93 [ V_32 ] = V_37 [ V_32 ] . V_43 . V_79 ;
V_38 = F_52 ( V_1 , V_10 -> V_24 ,
0 , V_10 -> V_95 , V_93 , V_10 -> V_35 ) ;
if ( V_38 )
return V_38 ;
switch ( V_1 -> V_96 . V_93 . V_97 ) {
case V_98 :
if ( ! V_1 -> V_96 . V_93 . V_99 . V_100 . V_101 ) {
union V_102 V_103 ;
V_38 = F_53 ( V_1 ,
V_10 -> V_24 ,
& V_103 ) ;
if ( V_38 )
return V_38 ;
V_103 . V_100 . V_104 =
V_37 [ 0 ] . V_43 . V_79 ;
V_38 = F_54 ( V_1 ,
V_10 -> V_24 ,
& V_103 ) ;
if ( V_38 )
return V_38 ;
}
break;
}
}
return 0 ;
}
static int F_55 ( struct V_1 * V_1 )
{
int V_38 ;
if ( ( V_1 -> V_51 & V_105 ) == 0 ) {
V_38 = F_42 ( V_1 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_50 ( V_1 ) ;
if ( V_38 ) {
F_49 ( V_1 ) ;
return V_38 ;
}
if ( V_1 -> V_51 & V_106 )
F_15 ( V_1 ) ;
V_1 -> V_51 |= V_105 ;
}
F_56 ( ( V_1 -> V_51 & ( V_106 | V_52 ) ) == 0 ) ;
if ( V_1 -> V_51 & V_106 )
V_38 = F_17 ( V_1 ) ;
else
V_38 = F_18 ( V_1 -> V_107 -> V_108 ,
F_57 ( V_1 ) , 0 ,
V_1 -> V_19 , V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_34 ,
V_38 ) ;
return V_38 ;
}
F_28 ( V_1 ) ;
F_58 ( V_1 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_1 )
{
if ( V_1 -> V_51 & V_106 )
F_21 ( V_1 ) ;
else
F_20 ( V_1 -> V_107 -> V_108 , V_1 ) ;
F_29 ( V_1 ) ;
}
static int F_60 ( struct V_4 * V_5 )
{
int V_38 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_109 == 0 ) {
V_38 = F_55 ( V_1 ) ;
if ( V_38 )
return V_38 ;
}
F_61 ( V_5 , V_10 -> V_35 ) ;
V_38 = F_62 ( V_5 , V_10 -> V_35 ) ;
if ( V_38 )
goto V_110;
V_38 = F_11 ( V_5 ) ;
if ( V_38 )
goto V_110;
F_63 ( V_5 ) ;
F_64 ( V_10 -> V_111 , & V_1 -> V_109 ) ;
return 0 ;
V_110:
if ( V_1 -> V_109 == 0 )
F_59 ( V_1 ) ;
return V_38 ;
}
static int F_65 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
F_66 ( V_5 ) ;
F_7 ( V_5 ) ;
F_14 ( V_1 , V_10 -> V_24 , false , false ) ;
V_10 -> V_11 . V_3 = 0 ;
F_67 ( V_10 -> V_111 , & V_1 -> V_109 ) ;
if ( V_1 -> V_109 == 0 )
F_59 ( V_1 ) ;
return 0 ;
}
static struct V_112 * F_68 ( struct V_4 * V_5 )
{
struct V_113 V_90 ;
struct V_9 * V_10 = F_69 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_112 * V_114 = & V_5 -> V_90 ;
int V_38 ;
F_70 ( & V_1 -> V_115 ) ;
V_38 = F_71 ( V_1 , V_10 -> V_2 , & V_90 ) ;
F_72 ( & V_1 -> V_115 ) ;
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
static inline unsigned int F_73 ( const struct V_4 * V_5 ,
const T_2 * * V_139 ,
unsigned int V_140 ,
unsigned int V_141 )
{
unsigned int V_142 = 0 ;
unsigned int V_143 = 0 ;
const struct V_144 * V_145 ;
F_74 (dev, ha)
if ( V_142 ++ >= V_140 ) {
V_139 [ V_143 ++ ] = V_145 -> V_139 ;
if ( V_143 >= V_141 )
break;
}
return V_143 ;
}
static inline unsigned int F_75 ( const struct V_4 * V_5 ,
const T_2 * * V_139 ,
unsigned int V_140 ,
unsigned int V_141 )
{
unsigned int V_142 = 0 ;
unsigned int V_143 = 0 ;
const struct V_144 * V_145 ;
F_76 (ha, dev)
if ( V_142 ++ >= V_140 ) {
V_139 [ V_143 ++ ] = V_145 -> V_139 ;
if ( V_143 >= V_141 )
break;
}
return V_143 ;
}
static int F_77 ( const struct V_4 * V_5 , bool V_146 )
{
T_4 V_147 = 0 ;
T_4 V_148 = 0 ;
bool free = true ;
unsigned int V_140 , V_143 ;
const T_2 * V_139 [ 7 ] ;
int V_23 ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
for ( V_140 = 0 ; ; V_140 += V_143 ) {
V_143 = F_73 ( V_5 , V_139 , V_140 ,
F_10 ( V_139 ) ) ;
if ( V_143 == 0 )
break;
V_23 = F_78 ( V_10 -> V_1 , V_10 -> V_24 , free ,
V_143 , V_139 , NULL , & V_148 , V_146 ) ;
if ( V_23 < 0 )
return V_23 ;
free = false ;
}
for ( V_140 = 0 ; ; V_140 += V_143 ) {
V_143 = F_75 ( V_5 , V_139 , V_140 ,
F_10 ( V_139 ) ) ;
if ( V_143 == 0 )
break;
V_23 = F_78 ( V_10 -> V_1 , V_10 -> V_24 , free ,
V_143 , V_139 , NULL , & V_147 , V_146 ) ;
if ( V_23 < 0 )
return V_23 ;
free = false ;
}
return F_79 ( V_10 -> V_1 , V_10 -> V_24 , V_148 != 0 ,
V_148 | V_147 , V_146 ) ;
}
static int F_80 ( struct V_4 * V_5 , int V_25 , bool V_149 )
{
int V_23 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_23 = F_77 ( V_5 , V_149 ) ;
if ( V_23 == 0 )
V_23 = F_12 ( V_10 -> V_1 , V_10 -> V_24 , - 1 ,
( V_5 -> V_51 & V_150 ) != 0 ,
( V_5 -> V_51 & V_151 ) != 0 ,
1 , - 1 , V_149 ) ;
return V_23 ;
}
static void F_81 ( struct V_4 * V_5 )
{
F_80 ( V_5 , - 1 , false ) ;
}
static int F_82 ( const struct V_36 * V_7 , int V_152 )
{
int V_153 , V_154 = 0 , V_155 = V_156 ;
for ( V_153 = 0 ; V_153 < F_10 ( V_7 -> V_157 ) ; V_153 ++ ) {
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
static int F_83 ( const struct V_36 * V_7 , int V_159 )
{
int V_153 , V_158 , V_160 = 0 , V_155 = V_156 ;
for ( V_153 = 0 ; V_153 < F_10 ( V_7 -> V_161 ) ; V_153 ++ ) {
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
static unsigned int F_84 ( const struct V_1 * V_1 ,
const struct V_45 * V_43 )
{
unsigned int V_154 = F_85 ( V_43 -> V_49 ) ;
return V_154 < V_162
? V_1 -> V_36 . V_157 [ V_154 ]
: 0 ;
}
static int F_86 ( struct V_1 * V_1 , struct V_45 * V_43 ,
unsigned int V_152 , unsigned int V_163 )
{
unsigned int V_154 ;
if ( ( V_152 | V_163 ) == 0 )
V_163 = 1 ;
if ( V_163 ) {
int V_38 ;
T_5 V_164 , V_160 ;
V_160 = F_83 ( & V_1 -> V_36 , V_163 ) ;
if ( V_43 -> V_30 && V_43 -> V_160 != V_160 ) {
V_164 = F_87 ( V_165 ) |
F_88 (
V_166 ) |
F_89 ( V_43 -> V_50 ) ;
V_38 = F_90 ( V_1 , 1 , & V_164 , & V_160 ) ;
if ( V_38 )
return V_38 ;
}
V_43 -> V_160 = V_160 ;
}
V_154 = ( V_152 == 0
? V_167
: F_82 ( & V_1 -> V_36 , V_152 ) ) ;
V_43 -> V_49 = ( F_91 ( V_154 ) |
( V_163 > 0 ? V_168 : 0 ) ) ;
return 0 ;
}
static inline unsigned int F_92 ( const struct V_1 * V_1 )
{
return F_93 ( V_1 -> V_96 . V_169 ) | ( 0x3f << 10 ) ;
}
static int F_94 ( struct V_4 * V_5 , struct V_170 * V_171 , int V_172 )
{
int V_23 = 0 ;
switch ( V_172 ) {
default:
V_23 = - V_173 ;
break;
}
return V_23 ;
}
static int F_95 ( struct V_4 * V_5 , int V_174 )
{
int V_23 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_174 < 81 )
return - V_175 ;
V_23 = F_12 ( V_10 -> V_1 , V_10 -> V_24 , V_174 ,
- 1 , - 1 , - 1 , - 1 , true ) ;
if ( ! V_23 )
V_5 -> V_25 = V_174 ;
return V_23 ;
}
static T_6 F_96 ( struct V_4 * V_5 ,
T_6 V_176 )
{
if ( V_176 & V_177 )
V_176 |= V_178 ;
else
V_176 &= ~ V_178 ;
return V_176 ;
}
static int F_97 ( struct V_4 * V_5 ,
T_6 V_176 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
T_6 V_179 = V_5 -> V_176 ^ V_176 ;
if ( V_179 & V_177 )
F_12 ( V_10 -> V_1 , V_10 -> V_24 , - 1 , - 1 , - 1 , - 1 ,
V_176 & V_178 , 0 ) ;
return 0 ;
}
static int F_98 ( struct V_4 * V_5 , void * V_180 )
{
int V_23 ;
struct V_181 * V_139 = V_180 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! F_99 ( V_139 -> V_182 ) )
return - V_183 ;
V_23 = F_13 ( V_10 -> V_1 , V_10 -> V_24 , V_10 -> V_26 ,
V_139 -> V_182 , true ) ;
if ( V_23 < 0 )
return V_23 ;
memcpy ( V_5 -> V_27 , V_139 -> V_182 , V_5 -> V_184 ) ;
V_10 -> V_26 = V_23 ;
return 0 ;
}
static void F_100 ( struct V_4 * V_5 )
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
F_57 ( V_1 ) ( 0 , V_1 ) ;
}
static unsigned int F_101 ( enum V_185 type ,
unsigned int V_186 )
{
unsigned int V_164 = 0 ;
if ( type == V_187 || type == V_188 ||
type == V_189 ) {
V_164 |= V_190 ;
if ( V_186 & V_191 )
V_164 |= V_192 ;
if ( V_186 & V_193 )
V_164 |= V_194 ;
if ( V_186 & V_195 )
V_164 |= V_196 ;
} else if ( type == V_197 || type == V_198 ) {
V_164 |= V_199 ;
if ( V_186 & V_193 )
V_164 |= V_200 ;
if ( V_186 & V_195 )
V_164 |= V_201 ;
} else if ( type == V_202 )
V_164 |= V_199 | V_203 ;
else if ( type == V_204 )
V_164 |= V_199 | V_205 |
V_203 | V_200 ;
else if ( type == V_206 )
V_164 |= V_199 | V_205 |
V_203 | V_200 |
V_201 ;
else if ( type == V_207 ||
type == V_208 ||
type == V_209 ||
type == V_210 ||
type == V_211 ) {
V_164 |= V_212 ;
if ( V_186 & V_193 )
V_164 |= V_194 ;
if ( V_186 & V_195 )
V_164 |= V_196 ;
} else if ( type == V_213 ||
type == V_214 ) {
V_164 |= V_215 ;
V_164 |= V_212 ;
}
if ( V_186 & V_216 )
V_164 |= V_217 ;
return V_164 ;
}
static int F_102 ( struct V_4 * V_5 , struct V_218 * V_172 )
{
const struct V_9 * V_67 = F_4 ( V_5 ) ;
if ( V_67 -> V_219 == V_187 ||
V_67 -> V_219 == V_188 ||
V_67 -> V_219 == V_189 )
V_172 -> V_6 = V_220 ;
else if ( V_67 -> V_219 == V_207 ||
V_67 -> V_219 == V_208 )
V_172 -> V_6 = V_221 ;
else if ( V_67 -> V_219 == V_209 ||
V_67 -> V_219 == V_210 ||
V_67 -> V_219 == V_211 ||
V_67 -> V_219 == V_214 ) {
if ( V_67 -> V_16 == V_222 ||
V_67 -> V_16 == V_223 ||
V_67 -> V_16 == V_224 ||
V_67 -> V_16 == V_225 )
V_172 -> V_6 = V_221 ;
else if ( V_67 -> V_16 == V_226 ||
V_67 -> V_16 == V_227 )
V_172 -> V_6 = V_228 ;
else
V_172 -> V_6 = V_229 ;
} else
V_172 -> V_6 = V_229 ;
if ( V_67 -> V_230 >= 0 ) {
V_172 -> V_231 = V_67 -> V_230 ;
V_172 -> V_232 = V_233 ;
V_172 -> V_234 = V_67 -> V_219 == V_187 ?
V_235 : V_236 ;
} else {
V_172 -> V_231 = 0 ;
V_172 -> V_232 = V_237 ;
V_172 -> V_234 = 0 ;
}
V_172 -> V_238 = F_101 ( V_67 -> V_219 ,
V_67 -> V_11 . V_238 ) ;
V_172 -> V_239 = F_101 ( V_67 -> V_219 ,
V_67 -> V_11 . V_239 ) ;
F_103 ( V_172 ,
F_3 ( V_5 ) ? V_67 -> V_11 . V_12 : 0 ) ;
V_172 -> V_240 = V_241 ;
V_172 -> V_242 = V_67 -> V_11 . V_242 ;
V_172 -> V_243 = 0 ;
V_172 -> V_244 = 0 ;
return 0 ;
}
static void F_104 ( struct V_4 * V_5 ,
struct V_245 * V_246 )
{
struct V_1 * V_1 = F_105 ( V_5 ) ;
F_106 ( V_246 -> V_247 , V_248 , sizeof( V_246 -> V_247 ) ) ;
F_106 ( V_246 -> V_249 , V_250 , sizeof( V_246 -> V_249 ) ) ;
F_106 ( V_246 -> V_251 , F_107 ( F_108 ( V_5 -> V_5 . V_252 ) ) ,
sizeof( V_246 -> V_251 ) ) ;
snprintf ( V_246 -> V_253 , sizeof( V_246 -> V_253 ) ,
L_35 ,
F_109 ( V_1 -> V_96 . V_5 . V_254 ) ,
F_110 ( V_1 -> V_96 . V_5 . V_254 ) ,
F_111 ( V_1 -> V_96 . V_5 . V_254 ) ,
F_112 ( V_1 -> V_96 . V_5 . V_254 ) ,
F_109 ( V_1 -> V_96 . V_5 . V_255 ) ,
F_110 ( V_1 -> V_96 . V_5 . V_255 ) ,
F_111 ( V_1 -> V_96 . V_5 . V_255 ) ,
F_112 ( V_1 -> V_96 . V_5 . V_255 ) ) ;
}
static T_5 F_113 ( struct V_4 * V_5 )
{
return F_105 ( V_5 ) -> V_256 ;
}
static void F_114 ( struct V_4 * V_5 , T_5 V_257 )
{
F_105 ( V_5 ) -> V_256 = V_257 ;
}
static void F_115 ( struct V_4 * V_5 ,
struct V_258 * V_259 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_36 * V_7 = & V_10 -> V_1 -> V_36 ;
V_259 -> V_260 = V_261 ;
V_259 -> V_262 = V_263 ;
V_259 -> V_264 = 0 ;
V_259 -> V_265 = V_266 ;
V_259 -> V_267 = V_7 -> V_42 [ V_10 -> V_85 ] . V_87 . V_268 - V_269 ;
V_259 -> V_270 = V_7 -> V_42 [ V_10 -> V_85 ] . V_43 . V_268 ;
V_259 -> V_271 = 0 ;
V_259 -> V_272 = V_7 -> V_86 [ V_10 -> V_85 ] . V_78 . V_268 ;
}
static int F_116 ( struct V_4 * V_5 ,
struct V_258 * V_259 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_32 ;
if ( V_259 -> V_267 > V_261 ||
V_259 -> V_271 ||
V_259 -> V_272 > V_266 ||
V_259 -> V_270 > V_263 ||
V_259 -> V_270 < V_273 ||
V_259 -> V_267 < V_274 ||
V_259 -> V_272 < V_275 )
return - V_175 ;
if ( V_1 -> V_51 & V_105 )
return - V_276 ;
for ( V_32 = V_10 -> V_85 ; V_32 < V_10 -> V_85 + V_10 -> V_35 ; V_32 ++ ) {
V_7 -> V_42 [ V_32 ] . V_87 . V_268 = V_259 -> V_267 + V_269 ;
V_7 -> V_42 [ V_32 ] . V_43 . V_268 = V_259 -> V_270 ;
V_7 -> V_86 [ V_32 ] . V_78 . V_268 = V_259 -> V_272 ;
}
return 0 ;
}
static int F_117 ( struct V_4 * V_5 ,
struct V_277 * V_278 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_45 * V_43 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ;
V_278 -> V_279 = F_84 ( V_1 , V_43 ) ;
V_278 -> V_280 =
( ( V_43 -> V_49 & V_168 )
? V_1 -> V_36 . V_161 [ V_43 -> V_160 ]
: 0 ) ;
return 0 ;
}
static int F_118 ( struct V_4 * V_5 ,
struct V_277 * V_278 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_86 ( V_1 ,
& V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ,
V_278 -> V_279 ,
V_278 -> V_280 ) ;
}
static void F_119 ( struct V_4 * V_5 ,
struct V_281 * V_282 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_282 -> V_242 = ( V_10 -> V_11 . V_283 & V_284 ) != 0 ;
V_282 -> V_285 = ( V_10 -> V_11 . V_8 & V_13 ) != 0 ;
V_282 -> V_286 = ( V_10 -> V_11 . V_8 & V_14 ) != 0 ;
}
static int F_120 ( struct V_4 * V_5 ,
enum V_287 V_288 )
{
unsigned int V_289 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_288 == V_290 )
V_289 = 0xffff ;
else if ( V_288 == V_291 )
V_289 = 0 ;
else
return - V_175 ;
return F_121 ( V_10 -> V_1 , V_10 -> V_24 , V_289 ) ;
}
static int F_122 ( struct V_4 * V_5 , int V_292 )
{
switch ( V_292 ) {
case V_293 :
return F_10 ( V_294 ) ;
default:
return - V_173 ;
}
}
static void F_123 ( struct V_4 * V_5 ,
T_5 V_292 ,
T_2 * V_64 )
{
switch ( V_292 ) {
case V_293 :
memcpy ( V_64 , V_294 , sizeof( V_294 ) ) ;
break;
}
}
static void F_124 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_295 * V_90 )
{
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_10 -> V_85 ] ;
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] ;
int V_32 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_74 ++ ) {
V_90 -> V_296 += V_74 -> V_296 ;
V_90 -> V_297 += V_74 -> V_298 ;
V_90 -> V_299 += V_37 -> V_90 . V_300 ;
V_90 -> V_301 += V_37 -> V_90 . V_301 ;
V_90 -> V_302 += V_74 -> V_302 ;
V_90 -> V_303 += V_37 -> V_90 . V_303 ;
V_90 -> V_304 += V_37 -> V_90 . V_304 ;
}
}
static void F_125 ( struct V_4 * V_5 ,
struct V_305 * V_90 ,
T_4 * V_64 )
{
struct V_9 * V_10 = F_69 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_38 = F_71 ( V_1 , V_10 -> V_2 ,
(struct V_113 * ) V_64 ) ;
if ( V_38 )
memset ( V_64 , 0 , sizeof( struct V_113 ) ) ;
V_64 += sizeof( struct V_113 ) / sizeof( T_4 ) ;
F_124 ( V_1 , V_10 , (struct V_295 * ) V_64 ) ;
}
static int F_126 ( struct V_4 * V_5 )
{
return V_306 ;
}
static void F_127 ( struct V_1 * V_1 , void * V_307 ,
unsigned int V_308 , unsigned int V_309 )
{
T_5 * V_310 = V_307 + V_308 - V_311 ;
for ( ; V_308 <= V_309 ; V_308 += sizeof( T_5 ) ) {
if ( V_308 == V_312 + V_313 )
* V_310 ++ = 0xffff ;
else
* V_310 ++ = F_128 ( V_1 , V_308 ) ;
}
}
static void F_129 ( struct V_4 * V_5 ,
struct V_314 * V_315 ,
void * V_307 )
{
struct V_1 * V_1 = F_105 ( V_5 ) ;
V_315 -> V_249 = F_92 ( V_1 ) ;
memset ( V_307 , 0 , V_306 ) ;
F_127 ( V_1 , V_307 ,
V_47 + V_316 ,
V_47 + V_317 ) ;
F_127 ( V_1 , V_307 ,
V_318 + V_319 ,
V_318 + V_320 ) ;
F_127 ( V_1 , V_307 ,
V_321 + V_322 ,
V_321 + ( F_130 ( V_1 -> V_96 . V_169 )
? V_323 : V_324 ) ) ;
F_127 ( V_1 , V_307 ,
V_312 + V_325 ,
V_312 + V_326 ) ;
F_127 ( V_1 , V_307 ,
V_327 + V_328 ,
V_327 + V_329 ) ;
}
static void F_131 ( struct V_4 * V_5 ,
struct V_330 * V_331 )
{
V_331 -> V_238 = 0 ;
V_331 -> V_332 = 0 ;
memset ( & V_331 -> V_333 , 0 , sizeof( V_331 -> V_333 ) ) ;
}
static int F_132 ( struct V_334 * V_335 , void * V_164 )
{
struct V_1 * V_1 = V_335 -> V_336 ;
int V_337 = F_133 ( V_1 -> V_36 . V_338 , V_339 ) ;
int V_32 , V_340 = ( V_341 ) V_164 - 1 ;
if ( V_340 )
F_134 ( V_335 , '\n' ) ;
#define F_135 ( T_7 , V_7 , V_164 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_136 ( V_7 , V_164 ) S3("s", s, v)
#define F_137 ( V_7 , V_164 ) S3("u", s, txq[qs].v)
#define F_138 ( V_7 , V_164 ) S3("u", s, rxq[qs].v)
if ( V_340 < V_337 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_340 * V_339 ] ;
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_340 * V_339 ] ;
int V_342 = F_139 ( V_339 , V_1 -> V_36 . V_338 - V_339 * V_340 ) ;
F_136 ( L_36 , L_37 ) ;
F_136 ( L_38 ,
( V_37 [ V_32 ] . V_43 . V_343
? V_37 [ V_32 ] . V_43 . V_343 -> V_19
: L_39 ) ) ;
F_135 ( L_40 , L_41 ,
( V_37 [ V_32 ] . V_43 . V_343
? ( (struct V_9 * )
F_4 ( V_37 [ V_32 ] . V_43 . V_343 ) ) -> V_111
: - 1 ) ) ;
F_137 ( L_42 , V_78 . V_79 ) ;
F_137 ( L_43 , V_78 . V_268 ) ;
F_137 ( L_44 , V_78 . V_344 ) ;
F_137 ( L_45 , V_78 . V_2 ) ;
F_137 ( L_46 , V_78 . V_345 ) ;
F_138 ( L_47 , V_43 . V_79 ) ;
F_138 ( L_48 , V_43 . V_268 ) ;
F_138 ( L_49 , V_43 . V_346 ) ;
F_135 ( L_50 , L_51 , F_84 ( V_1 , & V_37 [ V_32 ] . V_43 ) ) ;
F_135 ( L_50 , L_52 ,
V_1 -> V_36 . V_161 [ V_37 [ V_32 ] . V_43 . V_160 ] ) ;
F_138 ( L_53 , V_43 . V_345 ) ;
F_138 ( L_54 , V_43 . V_347 ) ;
F_138 ( L_55 , V_87 . V_79 ) ;
F_138 ( L_56 , V_87 . V_268 - V_269 ) ;
F_138 ( L_57 , V_87 . V_348 ) ;
F_138 ( L_58 , V_87 . V_2 ) ;
F_138 ( L_59 , V_87 . V_345 ) ;
return 0 ;
}
V_340 -= V_337 ;
if ( V_340 == 0 ) {
const struct V_45 * V_349 = & V_1 -> V_36 . V_41 ;
F_140 ( V_335 , L_60 , L_36 , L_61 ) ;
F_140 ( V_335 , L_62 , L_47 , V_349 -> V_79 ) ;
F_140 ( V_335 , L_62 , L_51 ,
F_84 ( V_1 , V_349 ) ) ;
F_140 ( V_335 , L_62 , L_52 ,
V_1 -> V_36 . V_161 [ V_349 -> V_160 ] ) ;
F_140 ( V_335 , L_62 , L_63 , V_349 -> V_345 ) ;
F_140 ( V_335 , L_62 , L_54 , V_349 -> V_347 ) ;
} else if ( V_340 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_140 ( V_335 , L_60 , L_36 , L_64 ) ;
F_140 ( V_335 , L_62 , L_47 , V_53 -> V_79 ) ;
F_140 ( V_335 , L_62 , L_51 ,
F_84 ( V_1 , V_53 ) ) ;
F_140 ( V_335 , L_62 , L_52 ,
V_1 -> V_36 . V_161 [ V_53 -> V_160 ] ) ;
F_140 ( V_335 , L_62 , L_63 , V_53 -> V_345 ) ;
F_140 ( V_335 , L_62 , L_54 , V_53 -> V_347 ) ;
}
#undef F_138
#undef F_137
#undef F_136
#undef F_135
return 0 ;
}
static int F_141 ( const struct V_1 * V_1 )
{
return F_133 ( V_1 -> V_36 . V_338 , V_339 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_142 ( struct V_334 * V_335 , T_8 * V_350 )
{
int V_351 = F_141 ( V_335 -> V_336 ) ;
return * V_350 < V_351 ? ( void * ) ( ( V_341 ) * V_350 + 1 ) : NULL ;
}
static void F_143 ( struct V_334 * V_335 , void * V_164 )
{
}
static void * F_144 ( struct V_334 * V_335 , void * V_164 , T_8 * V_350 )
{
int V_351 = F_141 ( V_335 -> V_336 ) ;
++ * V_350 ;
return * V_350 < V_351 ? ( void * ) ( ( V_341 ) * V_350 + 1 ) : NULL ;
}
static int F_145 ( struct V_352 * V_352 , struct V_353 * V_353 )
{
int V_354 = F_146 ( V_353 , & V_355 ) ;
if ( ! V_354 ) {
struct V_334 * V_335 = V_353 -> V_356 ;
V_335 -> V_336 = V_352 -> V_357 ;
}
return V_354 ;
}
static int F_147 ( struct V_334 * V_335 , void * V_164 )
{
struct V_1 * V_1 = V_335 -> V_336 ;
int V_337 = F_133 ( V_1 -> V_36 . V_338 , V_339 ) ;
int V_32 , V_340 = ( V_341 ) V_164 - 1 ;
if ( V_340 )
F_134 ( V_335 , '\n' ) ;
#define F_135 ( T_9 , V_7 , V_164 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_136 ( V_7 , V_164 ) S3("s", s, v)
#define F_148 ( T_9 , V_7 , V_164 ) S3(fmt, s, txq[qs].v)
#define F_137 ( V_7 , V_164 ) T3("lu", s, v)
#define F_149 ( T_9 , V_7 , V_164 ) S3(fmt, s, rxq[qs].v)
#define F_138 ( V_7 , V_164 ) R3("lu", s, v)
if ( V_340 < V_337 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_340 * V_339 ] ;
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_340 * V_339 ] ;
int V_342 = F_139 ( V_339 , V_1 -> V_36 . V_338 - V_339 * V_340 ) ;
F_136 ( L_36 , L_37 ) ;
F_136 ( L_38 ,
( V_37 [ V_32 ] . V_43 . V_343
? V_37 [ V_32 ] . V_43 . V_343 -> V_19
: L_39 ) ) ;
F_149 ( L_50 , L_65 , V_43 . V_358 ) ;
F_138 ( L_66 , V_90 . V_359 ) ;
F_138 ( L_67 , V_90 . V_300 ) ;
F_138 ( L_68 , V_90 . V_301 ) ;
F_138 ( L_69 , V_90 . V_304 ) ;
F_138 ( L_70 , V_90 . V_303 ) ;
F_138 ( L_71 , V_90 . V_360 ) ;
F_137 ( L_72 , V_296 ) ;
F_137 ( L_73 , V_298 ) ;
F_137 ( L_74 , V_302 ) ;
F_137 ( L_75 , V_78 . V_361 ) ;
F_137 ( L_76 , V_78 . V_80 ) ;
F_137 ( L_77 , V_362 ) ;
F_138 ( L_78 , V_87 . V_363 ) ;
F_138 ( L_79 , V_87 . V_364 ) ;
F_138 ( L_80 , V_87 . V_365 ) ;
return 0 ;
}
V_340 -= V_337 ;
if ( V_340 == 0 ) {
const struct V_45 * V_349 = & V_1 -> V_36 . V_41 ;
F_140 ( V_335 , L_81 , L_36 , L_61 ) ;
F_140 ( V_335 , L_82 , L_65 ,
V_349 -> V_358 ) ;
F_140 ( V_335 , L_82 , L_53 , V_349 -> V_345 ) ;
F_140 ( V_335 , L_82 , L_54 , V_349 -> V_347 ) ;
} else if ( V_340 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_140 ( V_335 , L_81 , L_36 , L_64 ) ;
F_140 ( V_335 , L_82 , L_65 ,
V_53 -> V_358 ) ;
F_140 ( V_335 , L_82 , L_53 , V_53 -> V_345 ) ;
F_140 ( V_335 , L_82 , L_54 , V_53 -> V_347 ) ;
}
#undef F_138
#undef F_137
#undef F_136
#undef F_149
#undef F_148
#undef F_135
return 0 ;
}
static int F_150 ( const struct V_1 * V_1 )
{
return F_133 ( V_1 -> V_36 . V_338 , V_339 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_151 ( struct V_334 * V_335 , T_8 * V_350 )
{
int V_351 = F_150 ( V_335 -> V_336 ) ;
return * V_350 < V_351 ? ( void * ) ( ( V_341 ) * V_350 + 1 ) : NULL ;
}
static void F_152 ( struct V_334 * V_335 , void * V_164 )
{
}
static void * F_153 ( struct V_334 * V_335 , void * V_164 , T_8 * V_350 )
{
int V_351 = F_150 ( V_335 -> V_336 ) ;
( * V_350 ) ++ ;
return * V_350 < V_351 ? ( void * ) ( ( V_341 ) * V_350 + 1 ) : NULL ;
}
static int F_154 ( struct V_352 * V_352 , struct V_353 * V_353 )
{
int V_354 = F_146 ( V_353 , & V_366 ) ;
if ( V_354 == 0 ) {
struct V_334 * V_335 = V_353 -> V_356 ;
V_335 -> V_336 = V_352 -> V_357 ;
}
return V_354 ;
}
static int F_155 ( struct V_334 * V_335 , void * V_164 )
{
struct V_1 * V_1 = V_335 -> V_336 ;
struct V_367 * V_368 = & V_1 -> V_96 . V_368 ;
#define F_136 ( V_30 , T_9 , T_10 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_136 ( L_83 , L_84 , V_369 ) ;
F_136 ( L_85 , L_84 , V_370 ) ;
F_136 ( L_86 , L_84 , V_371 ) ;
F_136 ( L_87 , L_84 , V_372 ) ;
F_136 ( L_88 , L_84 , V_373 ) ;
F_136 ( L_89 , L_84 , V_374 ) ;
F_136 ( L_90 , L_91 , V_375 ) ;
F_136 ( L_92 , L_84 , V_376 ) ;
F_136 ( L_93 , L_91 , V_377 ) ;
F_136 ( L_94 , L_91 , V_378 ) ;
#undef F_136
return 0 ;
}
static int F_156 ( struct V_352 * V_352 , struct V_353 * V_353 )
{
return F_157 ( V_353 , F_155 , V_352 -> V_357 ) ;
}
static int F_158 ( struct V_334 * V_335 , void * V_164 )
{
if ( V_164 == V_379 ) {
F_159 ( V_335 , L_95 ) ;
} else {
struct V_1 * V_1 = V_335 -> V_336 ;
int V_2 = ( V_341 ) V_164 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_140 ( V_335 , L_96 ,
V_5 -> V_19 , V_10 -> V_111 , V_10 -> V_24 ) ;
}
return 0 ;
}
static inline void * F_160 ( struct V_1 * V_1 , T_8 V_350 )
{
return V_350 <= V_1 -> V_96 . V_380
? ( void * ) ( V_341 ) ( V_350 + 1 )
: NULL ;
}
static void * F_161 ( struct V_334 * V_335 , T_8 * V_350 )
{
return * V_350
? F_160 ( V_335 -> V_336 , * V_350 )
: V_379 ;
}
static void * F_162 ( struct V_334 * V_335 , void * V_164 , T_8 * V_350 )
{
( * V_350 ) ++ ;
return F_160 ( V_335 -> V_336 , * V_350 ) ;
}
static void F_163 ( struct V_334 * V_335 , void * V_164 )
{
}
static int F_164 ( struct V_352 * V_352 , struct V_353 * V_353 )
{
int V_354 = F_146 ( V_353 , & V_381 ) ;
if ( V_354 == 0 ) {
struct V_334 * V_335 = V_353 -> V_356 ;
V_335 -> V_336 = V_352 -> V_357 ;
}
return V_354 ;
}
static int F_165 ( struct V_1 * V_1 )
{
int V_153 ;
F_56 ( F_166 ( V_1 -> V_382 ) ) ;
for ( V_153 = 0 ; V_153 < F_10 ( V_383 ) ; V_153 ++ )
( void ) F_167 ( V_383 [ V_153 ] . V_19 ,
V_383 [ V_153 ] . V_97 ,
V_1 -> V_382 ,
( void * ) V_1 ,
V_383 [ V_153 ] . V_384 ) ;
return 0 ;
}
static void F_168 ( struct V_1 * V_1 )
{
F_56 ( F_166 ( V_1 -> V_382 ) ) ;
}
static int F_169 ( struct V_1 * V_1 )
{
struct V_367 * V_368 = & V_1 -> V_96 . V_368 ;
struct V_385 * V_385 = & V_1 -> V_96 . V_36 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
unsigned int V_338 ;
int V_38 ;
T_5 V_386 , V_289 = 0 ;
V_38 = F_170 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_97
L_98 , V_38 ) ;
return V_38 ;
}
V_38 = F_171 ( V_1 ) ;
if ( V_38 < 0 ) {
F_35 ( V_1 -> V_18 , L_99 , V_38 ) ;
return V_38 ;
}
V_38 = F_172 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_100
L_101 , V_38 ) ;
return V_38 ;
}
V_38 = F_173 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_100
L_102 , V_38 ) ;
return V_38 ;
}
V_38 = F_174 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_100
L_103 , V_38 ) ;
return V_38 ;
}
V_38 = F_175 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_100
L_104 , V_38 ) ;
return V_38 ;
}
if ( V_1 -> V_96 . V_93 . V_97 !=
V_98 ) {
F_35 ( V_1 -> V_18 , L_105
L_106 , V_1 -> V_96 . V_93 . V_97 ) ;
return - V_175 ;
}
V_38 = F_176 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_107
L_98 , V_38 ) ;
return V_38 ;
}
V_386 = F_87 ( V_387 ) |
F_88 ( V_388 ) ;
V_289 = 1 ;
( void ) F_90 ( V_1 , 1 , & V_386 , & V_289 ) ;
V_7 -> V_157 [ 0 ] = F_177 ( V_1 ,
F_178 ( V_385 -> V_389 ) ) ;
V_7 -> V_157 [ 1 ] = F_177 ( V_1 ,
F_179 ( V_385 -> V_389 ) ) ;
V_7 -> V_157 [ 2 ] = F_177 ( V_1 ,
F_178 ( V_385 -> V_390 ) ) ;
V_7 -> V_157 [ 3 ] = F_177 ( V_1 ,
F_179 ( V_385 -> V_390 ) ) ;
V_7 -> V_157 [ 4 ] = F_177 ( V_1 ,
F_178 ( V_385 -> V_391 ) ) ;
V_7 -> V_157 [ 5 ] = F_177 ( V_1 ,
F_179 ( V_385 -> V_391 ) ) ;
V_7 -> V_161 [ 0 ] = F_180 ( V_385 -> V_392 ) ;
V_7 -> V_161 [ 1 ] = F_181 ( V_385 -> V_392 ) ;
V_7 -> V_161 [ 2 ] = F_182 ( V_385 -> V_392 ) ;
V_7 -> V_161 [ 3 ] = F_183 ( V_385 -> V_392 ) ;
V_38 = F_184 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_108
L_109 , V_38 ) ;
return V_38 ;
}
V_1 -> V_96 . V_380 = V_368 -> V_369 ;
if ( V_1 -> V_96 . V_380 > V_393 ) {
F_185 ( V_1 -> V_18 , L_110
L_111 , V_393 ,
V_1 -> V_96 . V_380 ) ;
V_1 -> V_96 . V_380 = V_393 ;
}
V_338 = V_368 -> V_372 - V_394 ;
if ( V_368 -> V_371 != V_338 ) {
F_185 ( V_1 -> V_18 , L_112
L_113
L_114 , V_338 , V_368 -> V_371 ) ;
V_338 = F_139 ( V_368 -> V_371 , V_338 ) ;
}
if ( V_368 -> V_370 < V_338 * 2 ) {
F_185 ( V_1 -> V_18 , L_115
L_116
L_117 , V_368 -> V_370 , V_338 ) ;
V_338 = V_368 -> V_370 / 2 ;
}
if ( V_338 > V_395 ) {
F_185 ( V_1 -> V_18 , L_118
L_117 , V_395 , V_1 -> V_36 . V_396 ) ;
V_338 = V_395 ;
}
if ( V_368 -> V_373 != 0 || V_368 -> V_370 > V_338 * 2 ) {
F_185 ( V_1 -> V_18 , L_119
L_120 , V_368 -> V_373 , V_368 -> V_370 - V_338 * 2 ) ;
}
V_1 -> V_36 . V_396 = V_338 ;
if ( V_1 -> V_36 . V_396 < V_1 -> V_96 . V_380 ) {
F_185 ( V_1 -> V_18 , L_121
L_122 ,
V_1 -> V_36 . V_396 , V_1 -> V_96 . V_380 ) ;
V_1 -> V_96 . V_380 = V_1 -> V_36 . V_396 ;
}
if ( V_1 -> V_96 . V_380 == 0 ) {
F_35 ( V_1 -> V_18 , L_123
L_124 ) ;
return - V_175 ;
}
return 0 ;
}
static inline void F_186 ( struct V_45 * V_43 , T_2 V_154 ,
T_2 V_397 , unsigned int V_268 ,
unsigned int V_398 )
{
V_43 -> V_49 = ( F_91 ( V_154 ) |
( V_397 < V_399 ? V_168 : 0 ) ) ;
V_43 -> V_160 = ( V_397 < V_399
? V_397
: 0 ) ;
V_43 -> V_346 = V_398 ;
V_43 -> V_268 = V_268 ;
}
static void F_187 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_400 , V_401 , V_402 , V_2 , V_32 ;
T_11 V_398 ;
F_56 ( ( V_1 -> V_51 & ( V_106 | V_52 ) ) == 0 ) ;
V_401 = 0 ;
F_16 (adapter, pidx)
V_401 += F_188 ( & F_51 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_401 == 0 )
V_400 = 0 ;
else {
int V_403 = ( V_1 -> V_96 . V_380 - V_401 ) ;
V_400 = ( V_1 -> V_36 . V_396 - V_403 ) / V_401 ;
if ( V_400 > F_189 () )
V_400 = F_189 () ;
}
V_402 = 0 ;
F_16 (adapter, pidx) {
struct V_9 * V_10 = F_51 ( V_1 , V_2 ) ;
V_10 -> V_85 = V_402 ;
V_10 -> V_35 = F_188 ( & V_10 -> V_11 ) ? V_400 : 1 ;
V_402 += V_10 -> V_35 ;
}
V_7 -> V_338 = V_402 ;
V_398 = 64 ;
for ( V_32 = 0 ; V_32 < V_7 -> V_396 ; V_32 ++ ) {
struct V_84 * V_37 = & V_7 -> V_42 [ V_32 ] ;
struct V_73 * V_74 = & V_7 -> V_86 [ V_32 ] ;
F_186 ( & V_37 -> V_43 , 0 , 0 , 1024 , V_398 ) ;
V_37 -> V_87 . V_268 = 72 ;
V_74 -> V_78 . V_268 = 1024 ;
}
F_186 ( & V_7 -> V_41 , V_167 , 0 , 512 , V_398 ) ;
F_186 ( & V_7 -> V_53 , V_167 , 0 , V_404 + 1 ,
V_398 ) ;
}
static void F_190 ( struct V_1 * V_1 , int V_342 )
{
int V_153 ;
struct V_9 * V_10 ;
F_56 ( V_342 < V_1 -> V_96 . V_380 ) ;
while ( V_342 < V_1 -> V_36 . V_338 )
F_16 (adapter, i) {
V_10 = F_51 ( V_1 , V_153 ) ;
if ( V_10 -> V_35 > 1 ) {
V_10 -> V_35 -- ;
V_1 -> V_36 . V_338 -- ;
if ( V_1 -> V_36 . V_338 <= V_342 )
break;
}
}
V_342 = 0 ;
F_16 (adapter, i) {
V_10 = F_51 ( V_1 , V_153 ) ;
V_10 -> V_85 = V_342 ;
V_342 += V_10 -> V_35 ;
}
}
static int F_191 ( struct V_1 * V_1 )
{
int V_153 , V_405 , V_406 , V_35 ;
struct V_407 V_351 [ V_404 ] ;
struct V_36 * V_7 = & V_1 -> V_36 ;
for ( V_153 = 0 ; V_153 < V_404 ; ++ V_153 )
V_351 [ V_153 ] . V_408 = V_153 ;
V_405 = V_7 -> V_396 + V_409 ;
V_406 = V_1 -> V_96 . V_380 + V_409 ;
V_405 = F_192 ( V_1 -> V_107 , V_351 , V_406 , V_405 ) ;
if ( V_405 < 0 )
return V_405 ;
V_35 = V_405 - V_409 ;
if ( V_35 < V_7 -> V_396 ) {
F_185 ( V_1 -> V_18 , L_125
L_126 , V_35 ) ;
V_7 -> V_396 = V_35 ;
if ( V_35 < V_7 -> V_338 )
F_190 ( V_1 , V_35 ) ;
}
for ( V_153 = 0 ; V_153 < V_405 ; ++ V_153 )
V_1 -> V_29 [ V_153 ] . V_39 = V_351 [ V_153 ] . V_410 ;
return 0 ;
}
static int F_193 ( struct V_411 * V_107 ,
const struct V_412 * V_413 )
{
int V_414 ;
int V_38 , V_2 ;
unsigned int V_375 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_343 ;
F_194 ( L_127 , V_415 , V_250 ) ;
V_38 = F_195 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_128 ) ;
return V_38 ;
}
V_38 = F_196 ( V_107 , V_248 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_129 ) ;
goto V_416;
}
V_38 = F_197 ( V_107 , F_198 ( 64 ) ) ;
if ( V_38 == 0 ) {
V_38 = F_199 ( V_107 , F_198 ( 64 ) ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_130
L_131 ) ;
goto V_417;
}
V_414 = 1 ;
} else {
V_38 = F_197 ( V_107 , F_198 ( 32 ) ) ;
if ( V_38 != 0 ) {
F_35 ( & V_107 -> V_5 , L_132 ) ;
goto V_417;
}
V_414 = 0 ;
}
F_200 ( V_107 ) ;
V_1 = F_201 ( sizeof( * V_1 ) , V_418 ) ;
if ( ! V_1 ) {
V_38 = - V_419 ;
goto V_417;
}
F_202 ( V_107 , V_1 ) ;
V_1 -> V_107 = V_107 ;
V_1 -> V_18 = & V_107 -> V_5 ;
F_203 ( & V_1 -> V_115 ) ;
V_1 -> V_315 = F_204 ( V_107 , 0 ) ;
if ( ! V_1 -> V_315 ) {
F_35 ( & V_107 -> V_5 , L_133 ) ;
V_38 = - V_419 ;
goto V_420;
}
V_38 = F_205 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_97
L_98 , V_38 ) ;
goto V_421;
}
if ( ! F_130 ( V_1 -> V_96 . V_169 ) ) {
V_1 -> V_422 = F_206 ( F_207 ( V_107 , 2 ) ,
F_208 ( V_107 , 2 ) ) ;
if ( ! V_1 -> V_422 ) {
F_35 ( V_1 -> V_18 , L_134 ) ;
V_38 = - V_419 ;
goto V_421;
}
}
V_1 -> V_19 = F_107 ( V_107 ) ;
V_1 -> V_256 = V_423 ;
V_38 = F_169 ( V_1 ) ;
if ( V_38 )
goto V_424;
V_375 = V_1 -> V_96 . V_368 . V_375 ;
F_16 (adapter, pidx) {
int V_111 , V_24 ;
if ( V_375 == 0 )
break;
V_111 = F_209 ( V_375 ) - 1 ;
V_375 &= ~ ( 1 << V_111 ) ;
V_24 = F_210 ( V_1 , V_111 ) ;
if ( V_24 < 0 ) {
F_35 ( & V_107 -> V_5 , L_135
L_98 , V_111 , V_24 ) ;
V_38 = V_24 ;
goto V_425;
}
V_343 = F_211 ( sizeof( struct V_9 ) ,
V_94 ) ;
if ( V_343 == NULL ) {
F_212 ( V_1 , V_24 ) ;
V_38 = - V_419 ;
goto V_425;
}
V_1 -> V_6 [ V_2 ] = V_343 ;
F_213 ( V_343 , & V_107 -> V_5 ) ;
V_10 = F_4 ( V_343 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_111 = V_111 ;
V_10 -> V_24 = V_24 ;
V_10 -> V_26 = - 1 ;
F_7 ( V_343 ) ;
V_343 -> V_108 = V_107 -> V_108 ;
V_343 -> V_426 = V_427 | V_428 |
V_429 | V_430 |
V_177 | V_431 ;
V_343 -> V_432 = V_427 | V_428 |
V_429 | V_430 |
V_433 ;
V_343 -> V_176 = V_343 -> V_426 |
V_178 ;
if ( V_414 )
V_343 -> V_176 |= V_433 ;
V_343 -> V_434 |= V_435 ;
V_343 -> V_436 = & V_437 ;
V_343 -> V_438 = & V_439 ;
V_38 = F_214 ( V_1 , V_2 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_136 ,
V_2 ) ;
goto V_425;
}
}
F_16 (adapter, pidx) {
V_343 = V_1 -> V_6 [ V_2 ] ;
if ( V_343 == NULL )
continue;
V_38 = F_215 ( V_343 ) ;
if ( V_38 ) {
F_185 ( & V_107 -> V_5 , L_137
L_138 , V_343 -> V_19 ) ;
continue;
}
F_64 ( V_2 , & V_1 -> V_440 ) ;
}
if ( V_1 -> V_440 == 0 ) {
F_35 ( & V_107 -> V_5 , L_139 ) ;
goto V_425;
}
if ( ! F_166 ( V_441 ) ) {
V_1 -> V_382 =
F_216 ( F_107 ( V_107 ) ,
V_441 ) ;
if ( F_166 ( V_1 -> V_382 ) )
F_185 ( & V_107 -> V_5 , L_140
L_141 ) ;
else
F_165 ( V_1 ) ;
}
if ( V_33 == V_442 && F_191 ( V_1 ) == 0 )
V_1 -> V_51 |= V_106 ;
else {
V_38 = F_217 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_142
L_98 ,
V_33 == V_442 ? L_143 : L_144 , V_38 ) ;
goto V_443;
}
V_1 -> V_51 |= V_52 ;
}
F_187 ( V_1 ) ;
F_16 (adapter, pidx) {
F_9 ( V_1 -> V_18 , L_145 ,
V_1 -> V_6 [ V_2 ] -> V_19 ,
( V_1 -> V_51 & V_106 ) ? L_146 :
( V_1 -> V_51 & V_52 ) ? L_144 : L_147 ) ;
}
return 0 ;
V_443:
if ( ! F_166 ( V_1 -> V_382 ) ) {
F_168 ( V_1 ) ;
F_218 ( V_1 -> V_382 ) ;
}
V_425:
F_16 (adapter, pidx) {
V_343 = V_1 -> V_6 [ V_2 ] ;
if ( V_343 == NULL )
continue;
V_10 = F_4 ( V_343 ) ;
F_212 ( V_1 , V_10 -> V_24 ) ;
if ( F_219 ( V_2 , & V_1 -> V_440 ) )
F_220 ( V_343 ) ;
F_221 ( V_343 ) ;
}
V_424:
if ( ! F_130 ( V_1 -> V_96 . V_169 ) )
F_222 ( V_1 -> V_422 ) ;
V_421:
F_222 ( V_1 -> V_315 ) ;
V_420:
F_223 ( V_1 ) ;
V_417:
F_224 ( V_107 ) ;
F_225 ( V_107 ) ;
V_416:
F_226 ( V_107 ) ;
return V_38 ;
}
static void F_227 ( struct V_411 * V_107 )
{
struct V_1 * V_1 = F_228 ( V_107 ) ;
if ( V_1 ) {
int V_2 ;
F_16 (adapter, pidx)
if ( F_219 ( V_2 , & V_1 -> V_440 ) )
F_220 ( V_1 -> V_6 [ V_2 ] ) ;
F_229 ( V_1 ) ;
if ( V_1 -> V_51 & V_106 ) {
F_230 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_231 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
if ( ! F_166 ( V_1 -> V_382 ) ) {
F_168 ( V_1 ) ;
F_218 ( V_1 -> V_382 ) ;
}
F_49 ( V_1 ) ;
F_16 (adapter, pidx) {
struct V_4 * V_343 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_343 == NULL )
continue;
V_10 = F_4 ( V_343 ) ;
F_212 ( V_1 , V_10 -> V_24 ) ;
F_221 ( V_343 ) ;
}
F_222 ( V_1 -> V_315 ) ;
if ( ! F_130 ( V_1 -> V_96 . V_169 ) )
F_222 ( V_1 -> V_422 ) ;
F_223 ( V_1 ) ;
}
F_226 ( V_107 ) ;
F_225 ( V_107 ) ;
F_224 ( V_107 ) ;
}
static void F_232 ( struct V_411 * V_107 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_228 ( V_107 ) ;
if ( ! V_1 )
return;
F_16 (adapter, pidx)
if ( F_219 ( V_2 , & V_1 -> V_440 ) )
F_220 ( V_1 -> V_6 [ V_2 ] ) ;
F_229 ( V_1 ) ;
if ( V_1 -> V_51 & V_106 ) {
F_230 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_231 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
F_49 ( V_1 ) ;
F_202 ( V_107 , NULL ) ;
}
static int T_12 F_233 ( void )
{
int V_23 ;
if ( V_33 != V_442 && V_33 != V_444 ) {
F_234 ( L_148 ,
V_33 , V_442 , V_444 ) ;
return - V_175 ;
}
V_441 = F_216 ( V_248 , NULL ) ;
if ( F_166 ( V_441 ) )
F_234 ( L_149 ) ;
V_23 = F_235 ( & V_445 ) ;
if ( V_23 < 0 && ! F_166 ( V_441 ) )
F_236 ( V_441 ) ;
return V_23 ;
}
static void T_13 F_237 ( void )
{
F_238 ( & V_445 ) ;
F_236 ( V_441 ) ;
}
