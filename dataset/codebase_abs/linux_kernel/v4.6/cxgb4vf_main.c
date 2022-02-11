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
F_59 ( & V_1 -> V_109 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_1 )
{
if ( V_1 -> V_51 & V_106 )
F_21 ( V_1 ) ;
else
F_20 ( V_1 -> V_107 -> V_108 , V_1 ) ;
F_29 ( V_1 ) ;
}
static int F_61 ( struct V_4 * V_5 )
{
int V_38 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
if ( V_1 -> V_110 == 0 ) {
V_38 = F_55 ( V_1 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_11 ( V_5 ) ;
if ( V_38 )
goto V_111;
F_62 ( V_5 ) ;
F_63 ( V_10 -> V_112 , & V_1 -> V_110 ) ;
return 0 ;
V_111:
if ( V_1 -> V_110 == 0 )
F_60 ( V_1 ) ;
return V_38 ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
F_65 ( V_5 ) ;
F_7 ( V_5 ) ;
F_14 ( V_1 , V_10 -> V_24 , false , false ) ;
V_10 -> V_11 . V_3 = 0 ;
F_66 ( V_10 -> V_112 , & V_1 -> V_110 ) ;
if ( V_1 -> V_110 == 0 )
F_60 ( V_1 ) ;
return 0 ;
}
static struct V_113 * F_67 ( struct V_4 * V_5 )
{
struct V_114 V_90 ;
struct V_9 * V_10 = F_68 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_113 * V_115 = & V_5 -> V_90 ;
int V_38 ;
F_69 ( & V_1 -> V_116 ) ;
V_38 = F_70 ( V_1 , V_10 -> V_2 , & V_90 ) ;
F_71 ( & V_1 -> V_116 ) ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
if ( V_38 )
return V_115 ;
V_115 -> V_117 = ( V_90 . V_118 + V_90 . V_119 +
V_90 . V_120 + V_90 . V_121 ) ;
V_115 -> V_122 = ( V_90 . V_123 + V_90 . V_124 +
V_90 . V_125 + V_90 . V_126 ) ;
V_115 -> V_127 = ( V_90 . V_128 + V_90 . V_129 +
V_90 . V_130 ) ;
V_115 -> V_131 = ( V_90 . V_132 + V_90 . V_133 +
V_90 . V_134 ) ;
V_115 -> V_135 = V_90 . V_133 ;
V_115 -> V_136 = V_90 . V_137 ;
V_115 -> V_138 = V_90 . V_139 ;
return V_115 ;
}
static inline int F_72 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = V_10 -> V_1 ;
T_4 V_39 = 0 ;
bool V_140 = false ;
struct V_141 * V_142 ;
F_73 (entry, &adapter->mac_hlist, list) {
V_140 |= F_74 ( V_142 -> V_143 ) ;
V_39 |= ( 1ULL << V_141 ( V_142 -> V_143 ) ) ;
}
return F_75 ( V_1 , V_10 -> V_24 , V_140 , V_39 , false ) ;
}
static int F_76 ( struct V_4 * V_144 , const T_2 * V_145 )
{
struct V_9 * V_10 = F_4 ( V_144 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_23 ;
T_4 V_146 = 0 ;
T_4 V_147 = 0 ;
bool free = false ;
bool V_140 = F_74 ( V_145 ) ;
const T_2 * V_148 [ 1 ] = { V_145 } ;
struct V_141 * V_149 ;
V_23 = F_77 ( V_1 , V_10 -> V_24 , free , 1 , V_148 ,
NULL , V_140 ? & V_147 : & V_146 , false ) ;
if ( V_23 < 0 )
goto V_150;
if ( V_147 || V_146 ) {
V_149 = F_78 ( sizeof( * V_149 ) , V_151 ) ;
if ( ! V_149 )
return - V_152 ;
F_79 ( V_149 -> V_143 , V_145 ) ;
F_80 ( & V_149 -> V_153 , & V_1 -> V_109 ) ;
V_23 = F_72 ( V_10 ) ;
}
V_150:
return V_23 < 0 ? V_23 : 0 ;
}
static int F_81 ( struct V_4 * V_144 , const T_2 * V_145 )
{
struct V_9 * V_10 = F_4 ( V_144 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_23 ;
const T_2 * V_148 [ 1 ] = { V_145 } ;
struct V_141 * V_142 , * V_154 ;
F_82 (entry, tmp, &adapter->mac_hlist, list) {
if ( F_83 ( V_142 -> V_143 , V_145 ) ) {
F_84 ( & V_142 -> V_153 ) ;
F_85 ( V_142 ) ;
return F_72 ( V_10 ) ;
}
}
V_23 = F_86 ( V_1 , V_10 -> V_24 , 1 , V_148 , false ) ;
return V_23 < 0 ? - V_155 : 0 ;
}
static int F_87 ( struct V_4 * V_5 , int V_25 , bool V_156 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! ( V_5 -> V_51 & V_157 ) ) {
F_88 ( V_5 , F_76 , F_81 ) ;
if ( ! ( V_5 -> V_51 & V_158 ) )
F_89 ( V_5 , F_76 ,
F_81 ) ;
}
return F_12 ( V_10 -> V_1 , V_10 -> V_24 , - 1 ,
( V_5 -> V_51 & V_157 ) != 0 ,
( V_5 -> V_51 & V_158 ) != 0 ,
1 , - 1 , V_156 ) ;
}
static void F_90 ( struct V_4 * V_5 )
{
F_87 ( V_5 , - 1 , false ) ;
}
static int F_91 ( const struct V_36 * V_7 , int V_159 )
{
int V_160 , V_161 = 0 , V_162 = V_163 ;
for ( V_160 = 0 ; V_160 < F_10 ( V_7 -> V_164 ) ; V_160 ++ ) {
int V_165 = V_159 - V_7 -> V_164 [ V_160 ] ;
if ( V_165 < 0 )
V_165 = - V_165 ;
if ( V_165 < V_162 ) {
V_162 = V_165 ;
V_161 = V_160 ;
}
}
return V_161 ;
}
static int F_92 ( const struct V_36 * V_7 , int V_166 )
{
int V_160 , V_165 , V_167 = 0 , V_162 = V_163 ;
for ( V_160 = 0 ; V_160 < F_10 ( V_7 -> V_168 ) ; V_160 ++ ) {
V_165 = V_166 - V_7 -> V_168 [ V_160 ] ;
if ( V_165 < 0 )
V_165 = - V_165 ;
if ( V_165 < V_162 ) {
V_162 = V_165 ;
V_167 = V_160 ;
}
}
return V_167 ;
}
static unsigned int F_93 ( const struct V_1 * V_1 ,
const struct V_45 * V_43 )
{
unsigned int V_161 = F_94 ( V_43 -> V_49 ) ;
return V_161 < V_169
? V_1 -> V_36 . V_164 [ V_161 ]
: 0 ;
}
static int F_95 ( struct V_1 * V_1 , struct V_45 * V_43 ,
unsigned int V_159 , unsigned int V_170 )
{
unsigned int V_161 ;
if ( ( V_159 | V_170 ) == 0 )
V_170 = 1 ;
if ( V_170 ) {
int V_38 ;
T_5 V_171 , V_167 ;
V_167 = F_92 ( & V_1 -> V_36 , V_170 ) ;
if ( V_43 -> V_30 && V_43 -> V_167 != V_167 ) {
V_171 = F_96 ( V_172 ) |
F_97 (
V_173 ) |
F_98 ( V_43 -> V_50 ) ;
V_38 = F_99 ( V_1 , 1 , & V_171 , & V_167 ) ;
if ( V_38 )
return V_38 ;
}
V_43 -> V_167 = V_167 ;
}
V_161 = ( V_159 == 0
? V_174
: F_91 ( & V_1 -> V_36 , V_159 ) ) ;
V_43 -> V_49 = ( F_100 ( V_161 ) |
F_101 ( V_170 > 0 ) ) ;
return 0 ;
}
static inline unsigned int F_102 ( const struct V_1 * V_1 )
{
return F_103 ( V_1 -> V_96 . V_175 ) | ( 0x3f << 10 ) ;
}
static int F_104 ( struct V_4 * V_5 , struct V_176 * V_177 , int V_178 )
{
int V_23 = 0 ;
switch ( V_178 ) {
default:
V_23 = - V_179 ;
break;
}
return V_23 ;
}
static int F_105 ( struct V_4 * V_5 , int V_180 )
{
int V_23 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_180 < 81 )
return - V_155 ;
V_23 = F_12 ( V_10 -> V_1 , V_10 -> V_24 , V_180 ,
- 1 , - 1 , - 1 , - 1 , true ) ;
if ( ! V_23 )
V_5 -> V_25 = V_180 ;
return V_23 ;
}
static T_6 F_106 ( struct V_4 * V_5 ,
T_6 V_181 )
{
if ( V_181 & V_182 )
V_181 |= V_183 ;
else
V_181 &= ~ V_183 ;
return V_181 ;
}
static int F_107 ( struct V_4 * V_5 ,
T_6 V_181 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
T_6 V_184 = V_5 -> V_181 ^ V_181 ;
if ( V_184 & V_182 )
F_12 ( V_10 -> V_1 , V_10 -> V_24 , - 1 , - 1 , - 1 , - 1 ,
V_181 & V_183 , 0 ) ;
return 0 ;
}
static int F_108 ( struct V_4 * V_5 , void * V_185 )
{
int V_23 ;
struct V_186 * V_143 = V_185 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( ! F_109 ( V_143 -> V_187 ) )
return - V_188 ;
V_23 = F_13 ( V_10 -> V_1 , V_10 -> V_24 , V_10 -> V_26 ,
V_143 -> V_187 , true ) ;
if ( V_23 < 0 )
return V_23 ;
memcpy ( V_5 -> V_27 , V_143 -> V_187 , V_5 -> V_189 ) ;
V_10 -> V_26 = V_23 ;
return 0 ;
}
static void F_110 ( struct V_4 * V_5 )
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
static unsigned int F_111 ( enum V_190 type ,
unsigned int V_191 )
{
unsigned int V_171 = 0 ;
if ( type == V_192 || type == V_193 ||
type == V_194 ) {
V_171 |= V_195 ;
if ( V_191 & V_196 )
V_171 |= V_197 ;
if ( V_191 & V_198 )
V_171 |= V_199 ;
if ( V_191 & V_200 )
V_171 |= V_201 ;
} else if ( type == V_202 || type == V_203 ) {
V_171 |= V_204 ;
if ( V_191 & V_198 )
V_171 |= V_205 ;
if ( V_191 & V_200 )
V_171 |= V_206 ;
} else if ( type == V_207 )
V_171 |= V_204 | V_208 ;
else if ( type == V_209 )
V_171 |= V_204 | V_210 |
V_208 | V_205 ;
else if ( type == V_211 )
V_171 |= V_204 | V_210 |
V_208 | V_205 |
V_206 ;
else if ( type == V_212 ||
type == V_213 ||
type == V_214 ||
type == V_215 ||
type == V_216 ) {
V_171 |= V_217 ;
if ( V_191 & V_198 )
V_171 |= V_199 ;
if ( V_191 & V_200 )
V_171 |= V_201 ;
} else if ( type == V_218 ||
type == V_219 ) {
V_171 |= V_220 ;
V_171 |= V_217 ;
}
if ( V_191 & V_221 )
V_171 |= V_222 ;
return V_171 ;
}
static int F_112 ( struct V_4 * V_5 , struct V_223 * V_178 )
{
const struct V_9 * V_67 = F_4 ( V_5 ) ;
if ( V_67 -> V_224 == V_192 ||
V_67 -> V_224 == V_193 ||
V_67 -> V_224 == V_194 )
V_178 -> V_6 = V_225 ;
else if ( V_67 -> V_224 == V_212 ||
V_67 -> V_224 == V_213 )
V_178 -> V_6 = V_226 ;
else if ( V_67 -> V_224 == V_214 ||
V_67 -> V_224 == V_215 ||
V_67 -> V_224 == V_216 ||
V_67 -> V_224 == V_219 ) {
if ( V_67 -> V_16 == V_227 ||
V_67 -> V_16 == V_228 ||
V_67 -> V_16 == V_229 ||
V_67 -> V_16 == V_230 )
V_178 -> V_6 = V_226 ;
else if ( V_67 -> V_16 == V_231 ||
V_67 -> V_16 == V_232 )
V_178 -> V_6 = V_233 ;
else
V_178 -> V_6 = V_234 ;
} else
V_178 -> V_6 = V_234 ;
if ( V_67 -> V_235 >= 0 ) {
V_178 -> V_236 = V_67 -> V_235 ;
V_178 -> V_237 = V_238 ;
V_178 -> V_239 = V_67 -> V_224 == V_192 ?
V_240 : V_241 ;
} else {
V_178 -> V_236 = 0 ;
V_178 -> V_237 = V_242 ;
V_178 -> V_239 = 0 ;
}
V_178 -> V_243 = F_111 ( V_67 -> V_224 ,
V_67 -> V_11 . V_243 ) ;
V_178 -> V_244 = F_111 ( V_67 -> V_224 ,
V_67 -> V_11 . V_244 ) ;
F_113 ( V_178 ,
F_3 ( V_5 ) ? V_67 -> V_11 . V_12 : 0 ) ;
V_178 -> V_245 = V_246 ;
V_178 -> V_247 = V_67 -> V_11 . V_247 ;
V_178 -> V_248 = 0 ;
V_178 -> V_249 = 0 ;
return 0 ;
}
static void F_114 ( struct V_4 * V_5 ,
struct V_250 * V_251 )
{
struct V_1 * V_1 = F_115 ( V_5 ) ;
F_116 ( V_251 -> V_252 , V_253 , sizeof( V_251 -> V_252 ) ) ;
F_116 ( V_251 -> V_254 , V_255 , sizeof( V_251 -> V_254 ) ) ;
F_116 ( V_251 -> V_256 , F_117 ( F_118 ( V_5 -> V_5 . V_257 ) ) ,
sizeof( V_251 -> V_256 ) ) ;
snprintf ( V_251 -> V_258 , sizeof( V_251 -> V_258 ) ,
L_35 ,
F_119 ( V_1 -> V_96 . V_5 . V_259 ) ,
F_120 ( V_1 -> V_96 . V_5 . V_259 ) ,
F_121 ( V_1 -> V_96 . V_5 . V_259 ) ,
F_122 ( V_1 -> V_96 . V_5 . V_259 ) ,
F_119 ( V_1 -> V_96 . V_5 . V_260 ) ,
F_120 ( V_1 -> V_96 . V_5 . V_260 ) ,
F_121 ( V_1 -> V_96 . V_5 . V_260 ) ,
F_122 ( V_1 -> V_96 . V_5 . V_260 ) ) ;
}
static T_5 F_123 ( struct V_4 * V_5 )
{
return F_115 ( V_5 ) -> V_261 ;
}
static void F_124 ( struct V_4 * V_5 , T_5 V_262 )
{
F_115 ( V_5 ) -> V_261 = V_262 ;
}
static void F_125 ( struct V_4 * V_5 ,
struct V_263 * V_264 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_36 * V_7 = & V_10 -> V_1 -> V_36 ;
V_264 -> V_265 = V_266 ;
V_264 -> V_267 = V_268 ;
V_264 -> V_269 = 0 ;
V_264 -> V_270 = V_271 ;
V_264 -> V_272 = V_7 -> V_42 [ V_10 -> V_85 ] . V_87 . V_273 - V_274 ;
V_264 -> V_275 = V_7 -> V_42 [ V_10 -> V_85 ] . V_43 . V_273 ;
V_264 -> V_276 = 0 ;
V_264 -> V_277 = V_7 -> V_86 [ V_10 -> V_85 ] . V_78 . V_273 ;
}
static int F_126 ( struct V_4 * V_5 ,
struct V_263 * V_264 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_32 ;
if ( V_264 -> V_272 > V_266 ||
V_264 -> V_276 ||
V_264 -> V_277 > V_271 ||
V_264 -> V_275 > V_268 ||
V_264 -> V_275 < V_278 ||
V_264 -> V_272 < V_279 ||
V_264 -> V_277 < V_280 )
return - V_155 ;
if ( V_1 -> V_51 & V_105 )
return - V_281 ;
for ( V_32 = V_10 -> V_85 ; V_32 < V_10 -> V_85 + V_10 -> V_35 ; V_32 ++ ) {
V_7 -> V_42 [ V_32 ] . V_87 . V_273 = V_264 -> V_272 + V_274 ;
V_7 -> V_42 [ V_32 ] . V_43 . V_273 = V_264 -> V_275 ;
V_7 -> V_86 [ V_32 ] . V_78 . V_273 = V_264 -> V_277 ;
}
return 0 ;
}
static int F_127 ( struct V_4 * V_5 ,
struct V_282 * V_283 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_45 * V_43 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ;
V_283 -> V_284 = F_93 ( V_1 , V_43 ) ;
V_283 -> V_285 =
( ( V_43 -> V_49 & V_286 )
? V_1 -> V_36 . V_168 [ V_43 -> V_167 ]
: 0 ) ;
return 0 ;
}
static int F_128 ( struct V_4 * V_5 ,
struct V_282 * V_283 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_95 ( V_1 ,
& V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ,
V_283 -> V_284 ,
V_283 -> V_285 ) ;
}
static void F_129 ( struct V_4 * V_5 ,
struct V_287 * V_288 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_288 -> V_247 = ( V_10 -> V_11 . V_289 & V_290 ) != 0 ;
V_288 -> V_291 = ( V_10 -> V_11 . V_8 & V_13 ) != 0 ;
V_288 -> V_292 = ( V_10 -> V_11 . V_8 & V_14 ) != 0 ;
}
static int F_130 ( struct V_4 * V_5 ,
enum V_293 V_294 )
{
unsigned int V_295 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_294 == V_296 )
V_295 = 0xffff ;
else if ( V_294 == V_297 )
V_295 = 0 ;
else
return - V_155 ;
return F_131 ( V_10 -> V_1 , V_10 -> V_24 , V_295 ) ;
}
static int F_132 ( struct V_4 * V_5 , int V_298 )
{
switch ( V_298 ) {
case V_299 :
return F_10 ( V_300 ) ;
default:
return - V_179 ;
}
}
static void F_133 ( struct V_4 * V_5 ,
T_5 V_298 ,
T_2 * V_64 )
{
switch ( V_298 ) {
case V_299 :
memcpy ( V_64 , V_300 , sizeof( V_300 ) ) ;
break;
}
}
static void F_134 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_301 * V_90 )
{
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_10 -> V_85 ] ;
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] ;
int V_32 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_74 ++ ) {
V_90 -> V_302 += V_74 -> V_302 ;
V_90 -> V_303 += V_74 -> V_304 ;
V_90 -> V_305 += V_37 -> V_90 . V_306 ;
V_90 -> V_307 += V_37 -> V_90 . V_307 ;
V_90 -> V_308 += V_74 -> V_308 ;
V_90 -> V_309 += V_37 -> V_90 . V_309 ;
V_90 -> V_310 += V_37 -> V_90 . V_310 ;
}
}
static void F_135 ( struct V_4 * V_5 ,
struct V_311 * V_90 ,
T_4 * V_64 )
{
struct V_9 * V_10 = F_68 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_38 = F_70 ( V_1 , V_10 -> V_2 ,
(struct V_114 * ) V_64 ) ;
if ( V_38 )
memset ( V_64 , 0 , sizeof( struct V_114 ) ) ;
V_64 += sizeof( struct V_114 ) / sizeof( T_4 ) ;
F_134 ( V_1 , V_10 , (struct V_301 * ) V_64 ) ;
}
static int F_136 ( struct V_4 * V_5 )
{
return V_312 ;
}
static void F_137 ( struct V_1 * V_1 , void * V_313 ,
unsigned int V_314 , unsigned int V_315 )
{
T_5 * V_316 = V_313 + V_314 - V_317 ;
for ( ; V_314 <= V_315 ; V_314 += sizeof( T_5 ) ) {
if ( V_314 == V_318 + V_319 )
* V_316 ++ = 0xffff ;
else
* V_316 ++ = F_138 ( V_1 , V_314 ) ;
}
}
static void F_139 ( struct V_4 * V_5 ,
struct V_320 * V_321 ,
void * V_313 )
{
struct V_1 * V_1 = F_115 ( V_5 ) ;
V_321 -> V_254 = F_102 ( V_1 ) ;
memset ( V_313 , 0 , V_312 ) ;
F_137 ( V_1 , V_313 ,
V_47 + V_322 ,
V_47 + V_323 ) ;
F_137 ( V_1 , V_313 ,
V_324 + V_325 ,
V_324 + V_326 ) ;
F_137 ( V_1 , V_313 ,
V_327 + V_328 ,
V_327 + ( F_140 ( V_1 -> V_96 . V_175 )
? V_329 : V_330 ) ) ;
F_137 ( V_1 , V_313 ,
V_318 + V_331 ,
V_318 + V_332 ) ;
F_137 ( V_1 , V_313 ,
V_333 + V_334 ,
V_333 + V_335 ) ;
}
static void F_141 ( struct V_4 * V_5 ,
struct V_336 * V_337 )
{
V_337 -> V_243 = 0 ;
V_337 -> V_338 = 0 ;
memset ( & V_337 -> V_339 , 0 , sizeof( V_337 -> V_339 ) ) ;
}
static int F_142 ( struct V_340 * V_341 , void * V_171 )
{
struct V_1 * V_1 = V_341 -> V_342 ;
int V_343 = F_143 ( V_1 -> V_36 . V_344 , V_345 ) ;
int V_32 , V_346 = ( V_347 ) V_171 - 1 ;
if ( V_346 )
F_144 ( V_341 , '\n' ) ;
#define F_145 ( T_7 , V_7 , V_171 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_146 ( V_7 , V_171 ) S3("s", s, v)
#define F_147 ( V_7 , V_171 ) S3("u", s, txq[qs].v)
#define F_148 ( V_7 , V_171 ) S3("u", s, rxq[qs].v)
if ( V_346 < V_343 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_346 * V_345 ] ;
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_346 * V_345 ] ;
int V_348 = F_149 ( V_345 , V_1 -> V_36 . V_344 - V_345 * V_346 ) ;
F_146 ( L_36 , L_37 ) ;
F_146 ( L_38 ,
( V_37 [ V_32 ] . V_43 . V_144
? V_37 [ V_32 ] . V_43 . V_144 -> V_19
: L_39 ) ) ;
F_145 ( L_40 , L_41 ,
( V_37 [ V_32 ] . V_43 . V_144
? ( (struct V_9 * )
F_4 ( V_37 [ V_32 ] . V_43 . V_144 ) ) -> V_112
: - 1 ) ) ;
F_147 ( L_42 , V_78 . V_79 ) ;
F_147 ( L_43 , V_78 . V_273 ) ;
F_147 ( L_44 , V_78 . V_349 ) ;
F_147 ( L_45 , V_78 . V_2 ) ;
F_147 ( L_46 , V_78 . V_350 ) ;
F_148 ( L_47 , V_43 . V_79 ) ;
F_148 ( L_48 , V_43 . V_273 ) ;
F_148 ( L_49 , V_43 . V_351 ) ;
F_145 ( L_50 , L_51 , F_93 ( V_1 , & V_37 [ V_32 ] . V_43 ) ) ;
F_145 ( L_50 , L_52 ,
V_1 -> V_36 . V_168 [ V_37 [ V_32 ] . V_43 . V_167 ] ) ;
F_148 ( L_53 , V_43 . V_350 ) ;
F_148 ( L_54 , V_43 . V_352 ) ;
F_148 ( L_55 , V_87 . V_79 ) ;
F_148 ( L_56 , V_87 . V_273 - V_274 ) ;
F_148 ( L_57 , V_87 . V_353 ) ;
F_148 ( L_58 , V_87 . V_2 ) ;
F_148 ( L_59 , V_87 . V_350 ) ;
return 0 ;
}
V_346 -= V_343 ;
if ( V_346 == 0 ) {
const struct V_45 * V_354 = & V_1 -> V_36 . V_41 ;
F_150 ( V_341 , L_60 , L_36 , L_61 ) ;
F_150 ( V_341 , L_62 , L_47 , V_354 -> V_79 ) ;
F_150 ( V_341 , L_62 , L_51 ,
F_93 ( V_1 , V_354 ) ) ;
F_150 ( V_341 , L_62 , L_52 ,
V_1 -> V_36 . V_168 [ V_354 -> V_167 ] ) ;
F_150 ( V_341 , L_62 , L_63 , V_354 -> V_350 ) ;
F_150 ( V_341 , L_62 , L_54 , V_354 -> V_352 ) ;
} else if ( V_346 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_150 ( V_341 , L_60 , L_36 , L_64 ) ;
F_150 ( V_341 , L_62 , L_47 , V_53 -> V_79 ) ;
F_150 ( V_341 , L_62 , L_51 ,
F_93 ( V_1 , V_53 ) ) ;
F_150 ( V_341 , L_62 , L_52 ,
V_1 -> V_36 . V_168 [ V_53 -> V_167 ] ) ;
F_150 ( V_341 , L_62 , L_63 , V_53 -> V_350 ) ;
F_150 ( V_341 , L_62 , L_54 , V_53 -> V_352 ) ;
}
#undef F_148
#undef F_147
#undef F_146
#undef F_145
return 0 ;
}
static int F_151 ( const struct V_1 * V_1 )
{
return F_143 ( V_1 -> V_36 . V_344 , V_345 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_152 ( struct V_340 * V_341 , T_8 * V_355 )
{
int V_356 = F_151 ( V_341 -> V_342 ) ;
return * V_355 < V_356 ? ( void * ) ( ( V_347 ) * V_355 + 1 ) : NULL ;
}
static void F_153 ( struct V_340 * V_341 , void * V_171 )
{
}
static void * F_154 ( struct V_340 * V_341 , void * V_171 , T_8 * V_355 )
{
int V_356 = F_151 ( V_341 -> V_342 ) ;
++ * V_355 ;
return * V_355 < V_356 ? ( void * ) ( ( V_347 ) * V_355 + 1 ) : NULL ;
}
static int F_155 ( struct V_357 * V_357 , struct V_358 * V_358 )
{
int V_359 = F_156 ( V_358 , & V_360 ) ;
if ( ! V_359 ) {
struct V_340 * V_341 = V_358 -> V_361 ;
V_341 -> V_342 = V_357 -> V_362 ;
}
return V_359 ;
}
static int F_157 ( struct V_340 * V_341 , void * V_171 )
{
struct V_1 * V_1 = V_341 -> V_342 ;
int V_343 = F_143 ( V_1 -> V_36 . V_344 , V_345 ) ;
int V_32 , V_346 = ( V_347 ) V_171 - 1 ;
if ( V_346 )
F_144 ( V_341 , '\n' ) ;
#define F_145 ( T_9 , V_7 , V_171 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_146 ( V_7 , V_171 ) S3("s", s, v)
#define F_158 ( T_9 , V_7 , V_171 ) S3(fmt, s, txq[qs].v)
#define F_147 ( V_7 , V_171 ) T3("lu", s, v)
#define F_159 ( T_9 , V_7 , V_171 ) S3(fmt, s, rxq[qs].v)
#define F_148 ( V_7 , V_171 ) R3("lu", s, v)
if ( V_346 < V_343 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_346 * V_345 ] ;
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_346 * V_345 ] ;
int V_348 = F_149 ( V_345 , V_1 -> V_36 . V_344 - V_345 * V_346 ) ;
F_146 ( L_36 , L_37 ) ;
F_146 ( L_38 ,
( V_37 [ V_32 ] . V_43 . V_144
? V_37 [ V_32 ] . V_43 . V_144 -> V_19
: L_39 ) ) ;
F_159 ( L_50 , L_65 , V_43 . V_363 ) ;
F_148 ( L_66 , V_90 . V_364 ) ;
F_148 ( L_67 , V_90 . V_306 ) ;
F_148 ( L_68 , V_90 . V_307 ) ;
F_148 ( L_69 , V_90 . V_310 ) ;
F_148 ( L_70 , V_90 . V_309 ) ;
F_148 ( L_71 , V_90 . V_365 ) ;
F_147 ( L_72 , V_302 ) ;
F_147 ( L_73 , V_304 ) ;
F_147 ( L_74 , V_308 ) ;
F_147 ( L_75 , V_78 . V_366 ) ;
F_147 ( L_76 , V_78 . V_80 ) ;
F_147 ( L_77 , V_367 ) ;
F_148 ( L_78 , V_87 . V_368 ) ;
F_148 ( L_79 , V_87 . V_369 ) ;
F_148 ( L_80 , V_87 . V_370 ) ;
return 0 ;
}
V_346 -= V_343 ;
if ( V_346 == 0 ) {
const struct V_45 * V_354 = & V_1 -> V_36 . V_41 ;
F_150 ( V_341 , L_81 , L_36 , L_61 ) ;
F_150 ( V_341 , L_82 , L_65 ,
V_354 -> V_363 ) ;
F_150 ( V_341 , L_82 , L_53 , V_354 -> V_350 ) ;
F_150 ( V_341 , L_82 , L_54 , V_354 -> V_352 ) ;
} else if ( V_346 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_150 ( V_341 , L_81 , L_36 , L_64 ) ;
F_150 ( V_341 , L_82 , L_65 ,
V_53 -> V_363 ) ;
F_150 ( V_341 , L_82 , L_53 , V_53 -> V_350 ) ;
F_150 ( V_341 , L_82 , L_54 , V_53 -> V_352 ) ;
}
#undef F_148
#undef F_147
#undef F_146
#undef F_159
#undef F_158
#undef F_145
return 0 ;
}
static int F_160 ( const struct V_1 * V_1 )
{
return F_143 ( V_1 -> V_36 . V_344 , V_345 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_161 ( struct V_340 * V_341 , T_8 * V_355 )
{
int V_356 = F_160 ( V_341 -> V_342 ) ;
return * V_355 < V_356 ? ( void * ) ( ( V_347 ) * V_355 + 1 ) : NULL ;
}
static void F_162 ( struct V_340 * V_341 , void * V_171 )
{
}
static void * F_163 ( struct V_340 * V_341 , void * V_171 , T_8 * V_355 )
{
int V_356 = F_160 ( V_341 -> V_342 ) ;
( * V_355 ) ++ ;
return * V_355 < V_356 ? ( void * ) ( ( V_347 ) * V_355 + 1 ) : NULL ;
}
static int F_164 ( struct V_357 * V_357 , struct V_358 * V_358 )
{
int V_359 = F_156 ( V_358 , & V_371 ) ;
if ( V_359 == 0 ) {
struct V_340 * V_341 = V_358 -> V_361 ;
V_341 -> V_342 = V_357 -> V_362 ;
}
return V_359 ;
}
static int F_165 ( struct V_340 * V_341 , void * V_171 )
{
struct V_1 * V_1 = V_341 -> V_342 ;
struct V_372 * V_373 = & V_1 -> V_96 . V_373 ;
#define F_146 ( V_30 , T_9 , T_10 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_146 ( L_83 , L_84 , V_374 ) ;
F_146 ( L_85 , L_84 , V_375 ) ;
F_146 ( L_86 , L_84 , V_376 ) ;
F_146 ( L_87 , L_84 , V_377 ) ;
F_146 ( L_88 , L_84 , V_378 ) ;
F_146 ( L_89 , L_84 , V_379 ) ;
F_146 ( L_90 , L_91 , V_380 ) ;
F_146 ( L_92 , L_84 , V_381 ) ;
F_146 ( L_93 , L_91 , V_382 ) ;
F_146 ( L_94 , L_91 , V_383 ) ;
#undef F_146
return 0 ;
}
static int F_166 ( struct V_357 * V_357 , struct V_358 * V_358 )
{
return F_167 ( V_358 , F_165 , V_357 -> V_362 ) ;
}
static int F_168 ( struct V_340 * V_341 , void * V_171 )
{
if ( V_171 == V_384 ) {
F_169 ( V_341 , L_95 ) ;
} else {
struct V_1 * V_1 = V_341 -> V_342 ;
int V_2 = ( V_347 ) V_171 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_150 ( V_341 , L_96 ,
V_5 -> V_19 , V_10 -> V_112 , V_10 -> V_24 ) ;
}
return 0 ;
}
static inline void * F_170 ( struct V_1 * V_1 , T_8 V_355 )
{
return V_355 <= V_1 -> V_96 . V_385
? ( void * ) ( V_347 ) ( V_355 + 1 )
: NULL ;
}
static void * F_171 ( struct V_340 * V_341 , T_8 * V_355 )
{
return * V_355
? F_170 ( V_341 -> V_342 , * V_355 )
: V_384 ;
}
static void * F_172 ( struct V_340 * V_341 , void * V_171 , T_8 * V_355 )
{
( * V_355 ) ++ ;
return F_170 ( V_341 -> V_342 , * V_355 ) ;
}
static void F_173 ( struct V_340 * V_341 , void * V_171 )
{
}
static int F_174 ( struct V_357 * V_357 , struct V_358 * V_358 )
{
int V_359 = F_156 ( V_358 , & V_386 ) ;
if ( V_359 == 0 ) {
struct V_340 * V_341 = V_358 -> V_361 ;
V_341 -> V_342 = V_357 -> V_362 ;
}
return V_359 ;
}
static int F_175 ( struct V_1 * V_1 )
{
int V_160 ;
F_56 ( F_176 ( V_1 -> V_387 ) ) ;
for ( V_160 = 0 ; V_160 < F_10 ( V_388 ) ; V_160 ++ )
( void ) F_177 ( V_388 [ V_160 ] . V_19 ,
V_388 [ V_160 ] . V_97 ,
V_1 -> V_387 ,
( void * ) V_1 ,
V_388 [ V_160 ] . V_389 ) ;
return 0 ;
}
static void F_178 ( struct V_1 * V_1 )
{
F_56 ( F_176 ( V_1 -> V_387 ) ) ;
}
static void F_179 ( struct V_1 * V_1 )
{
struct V_372 * V_373 = & V_1 -> V_96 . V_373 ;
unsigned int V_344 , V_390 ;
V_1 -> V_96 . V_385 = V_373 -> V_374 ;
if ( V_1 -> V_96 . V_385 > V_391 ) {
F_180 ( V_1 -> V_18 , L_97
L_98 , V_391 ,
V_1 -> V_96 . V_385 ) ;
V_1 -> V_96 . V_385 = V_391 ;
}
V_390 = F_181 ( V_1 -> V_96 . V_373 . V_380 ) ;
if ( V_390 < V_1 -> V_96 . V_385 ) {
F_180 ( V_1 -> V_18 , L_99
L_100
L_101 , V_390 , V_1 -> V_96 . V_385 ,
V_1 -> V_96 . V_373 . V_380 ) ;
V_1 -> V_96 . V_385 = V_390 ;
}
V_344 = V_373 -> V_377 - 1 - ( V_33 == V_392 ) ;
if ( V_373 -> V_376 != V_344 )
V_344 = F_149 ( V_373 -> V_376 , V_344 ) ;
if ( V_373 -> V_375 < V_344 * 2 )
V_344 = V_373 -> V_375 / 2 ;
if ( V_344 > V_393 )
V_344 = V_393 ;
V_1 -> V_36 . V_394 = V_344 ;
if ( V_1 -> V_36 . V_394 < V_1 -> V_96 . V_385 ) {
F_180 ( V_1 -> V_18 , L_102
L_103 ,
V_1 -> V_36 . V_394 , V_1 -> V_96 . V_385 ) ;
V_1 -> V_96 . V_385 = V_1 -> V_36 . V_394 ;
}
}
static int F_182 ( struct V_1 * V_1 )
{
struct V_395 * V_395 = & V_1 -> V_96 . V_36 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_38 ;
T_5 V_396 , V_295 = 0 ;
V_38 = F_183 ( V_1 ) ;
if ( V_38 < 0 ) {
F_35 ( V_1 -> V_18 , L_104 , V_38 ) ;
return V_38 ;
}
V_38 = F_184 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_105
L_106 , V_38 ) ;
return V_38 ;
}
V_38 = F_185 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_105
L_107 , V_38 ) ;
return V_38 ;
}
V_38 = F_186 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_105
L_108 , V_38 ) ;
return V_38 ;
}
V_38 = F_187 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_105
L_109 , V_38 ) ;
return V_38 ;
}
if ( V_1 -> V_96 . V_93 . V_97 !=
V_98 ) {
F_35 ( V_1 -> V_18 , L_110
L_111 , V_1 -> V_96 . V_93 . V_97 ) ;
return - V_155 ;
}
V_38 = F_188 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_112
L_113 , V_38 ) ;
return V_38 ;
}
V_396 = F_96 ( V_397 ) |
F_97 ( V_398 ) ;
V_295 = 1 ;
( void ) F_99 ( V_1 , 1 , & V_396 , & V_295 ) ;
V_7 -> V_164 [ 0 ] = F_189 ( V_1 ,
F_190 ( V_395 -> V_399 ) ) ;
V_7 -> V_164 [ 1 ] = F_189 ( V_1 ,
F_191 ( V_395 -> V_399 ) ) ;
V_7 -> V_164 [ 2 ] = F_189 ( V_1 ,
F_190 ( V_395 -> V_400 ) ) ;
V_7 -> V_164 [ 3 ] = F_189 ( V_1 ,
F_191 ( V_395 -> V_400 ) ) ;
V_7 -> V_164 [ 4 ] = F_189 ( V_1 ,
F_190 ( V_395 -> V_401 ) ) ;
V_7 -> V_164 [ 5 ] = F_189 ( V_1 ,
F_191 ( V_395 -> V_401 ) ) ;
V_7 -> V_168 [ 0 ] = F_192 ( V_395 -> V_402 ) ;
V_7 -> V_168 [ 1 ] = F_193 ( V_395 -> V_402 ) ;
V_7 -> V_168 [ 2 ] = F_194 ( V_395 -> V_402 ) ;
V_7 -> V_168 [ 3 ] = F_195 ( V_395 -> V_402 ) ;
V_38 = F_196 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_114
L_115 , V_38 ) ;
return V_38 ;
}
if ( V_1 -> V_96 . V_373 . V_380 == 0 ) {
F_35 ( V_1 -> V_18 , L_116
L_117 ) ;
return - V_155 ;
}
if ( V_1 -> V_96 . V_373 . V_374 == 0 ) {
F_35 ( V_1 -> V_18 , L_118
L_117 ) ;
return - V_155 ;
}
F_179 ( V_1 ) ;
return 0 ;
}
static inline void F_197 ( struct V_45 * V_43 , T_2 V_161 ,
T_2 V_403 , unsigned int V_273 ,
unsigned int V_404 )
{
V_43 -> V_49 = ( F_100 ( V_161 ) |
( V_403 < V_405 ?
V_286 : 0 ) ) ;
V_43 -> V_167 = ( V_403 < V_405
? V_403
: 0 ) ;
V_43 -> V_351 = V_404 ;
V_43 -> V_273 = V_273 ;
}
static void F_198 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_406 , V_407 , V_408 , V_2 , V_32 ;
T_11 V_404 ;
F_56 ( ( V_1 -> V_51 & ( V_106 | V_52 ) ) == 0 ) ;
V_407 = 0 ;
F_16 (adapter, pidx)
V_407 += F_199 ( & F_51 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_407 == 0 )
V_406 = 0 ;
else {
int V_409 = ( V_1 -> V_96 . V_385 - V_407 ) ;
V_406 = ( V_1 -> V_36 . V_394 - V_409 ) / V_407 ;
if ( V_406 > F_200 () )
V_406 = F_200 () ;
}
V_408 = 0 ;
F_16 (adapter, pidx) {
struct V_9 * V_10 = F_51 ( V_1 , V_2 ) ;
V_10 -> V_85 = V_408 ;
V_10 -> V_35 = F_199 ( & V_10 -> V_11 ) ? V_406 : 1 ;
V_408 += V_10 -> V_35 ;
}
V_7 -> V_344 = V_408 ;
V_404 = 64 ;
for ( V_32 = 0 ; V_32 < V_7 -> V_394 ; V_32 ++ ) {
struct V_84 * V_37 = & V_7 -> V_42 [ V_32 ] ;
struct V_73 * V_74 = & V_7 -> V_86 [ V_32 ] ;
F_197 ( & V_37 -> V_43 , 0 , 0 , 1024 , V_404 ) ;
V_37 -> V_87 . V_273 = 72 ;
V_74 -> V_78 . V_273 = 1024 ;
}
F_197 ( & V_7 -> V_41 , V_174 , 0 , 512 , V_404 ) ;
F_197 ( & V_7 -> V_53 , V_174 , 0 , V_410 + 1 ,
V_404 ) ;
}
static void F_201 ( struct V_1 * V_1 , int V_348 )
{
int V_160 ;
struct V_9 * V_10 ;
F_56 ( V_348 < V_1 -> V_96 . V_385 ) ;
while ( V_348 < V_1 -> V_36 . V_344 )
F_16 (adapter, i) {
V_10 = F_51 ( V_1 , V_160 ) ;
if ( V_10 -> V_35 > 1 ) {
V_10 -> V_35 -- ;
V_1 -> V_36 . V_344 -- ;
if ( V_1 -> V_36 . V_344 <= V_348 )
break;
}
}
V_348 = 0 ;
F_16 (adapter, i) {
V_10 = F_51 ( V_1 , V_160 ) ;
V_10 -> V_85 = V_348 ;
V_348 += V_10 -> V_35 ;
}
}
static int F_202 ( struct V_1 * V_1 )
{
int V_160 , V_411 , V_412 , V_35 ;
struct V_413 V_356 [ V_410 ] ;
struct V_36 * V_7 = & V_1 -> V_36 ;
for ( V_160 = 0 ; V_160 < V_410 ; ++ V_160 )
V_356 [ V_160 ] . V_142 = V_160 ;
V_411 = V_7 -> V_394 + V_414 ;
V_412 = V_1 -> V_96 . V_385 + V_414 ;
V_411 = F_203 ( V_1 -> V_107 , V_356 , V_412 , V_411 ) ;
if ( V_411 < 0 )
return V_411 ;
V_35 = V_411 - V_414 ;
if ( V_35 < V_7 -> V_394 ) {
F_180 ( V_1 -> V_18 , L_119
L_120 , V_35 ) ;
V_7 -> V_394 = V_35 ;
if ( V_35 < V_7 -> V_344 )
F_201 ( V_1 , V_35 ) ;
}
for ( V_160 = 0 ; V_160 < V_411 ; ++ V_160 )
V_1 -> V_29 [ V_160 ] . V_39 = V_356 [ V_160 ] . V_415 ;
return 0 ;
}
static int F_204 ( struct V_416 * V_107 ,
const struct V_417 * V_418 )
{
int V_419 ;
int V_38 , V_2 ;
unsigned int V_380 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_144 ;
F_205 ( L_121 , V_420 , V_255 ) ;
V_38 = F_206 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_122 ) ;
return V_38 ;
}
V_38 = F_207 ( V_107 , V_253 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_123 ) ;
goto V_421;
}
V_38 = F_208 ( V_107 , F_209 ( 64 ) ) ;
if ( V_38 == 0 ) {
V_38 = F_210 ( V_107 , F_209 ( 64 ) ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_124
L_125 ) ;
goto V_422;
}
V_419 = 1 ;
} else {
V_38 = F_208 ( V_107 , F_209 ( 32 ) ) ;
if ( V_38 != 0 ) {
F_35 ( & V_107 -> V_5 , L_126 ) ;
goto V_422;
}
V_419 = 0 ;
}
F_211 ( V_107 ) ;
V_1 = F_78 ( sizeof( * V_1 ) , V_423 ) ;
if ( ! V_1 ) {
V_38 = - V_152 ;
goto V_422;
}
F_212 ( V_107 , V_1 ) ;
V_1 -> V_107 = V_107 ;
V_1 -> V_18 = & V_107 -> V_5 ;
F_213 ( & V_1 -> V_116 ) ;
V_1 -> V_321 = F_214 ( V_107 , 0 ) ;
if ( ! V_1 -> V_321 ) {
F_35 ( & V_107 -> V_5 , L_127 ) ;
V_38 = - V_152 ;
goto V_424;
}
V_38 = F_215 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_128
L_113 , V_38 ) ;
goto V_425;
}
if ( ! F_140 ( V_1 -> V_96 . V_175 ) ) {
V_1 -> V_426 = F_216 ( F_217 ( V_107 , 2 ) ,
F_218 ( V_107 , 2 ) ) ;
if ( ! V_1 -> V_426 ) {
F_35 ( V_1 -> V_18 , L_129 ) ;
V_38 = - V_152 ;
goto V_425;
}
}
V_1 -> V_19 = F_117 ( V_107 ) ;
V_1 -> V_261 = V_427 ;
V_38 = F_182 ( V_1 ) ;
if ( V_38 )
goto V_428;
V_380 = V_1 -> V_96 . V_373 . V_380 ;
F_16 (adapter, pidx) {
int V_112 , V_24 ;
if ( V_380 == 0 )
break;
V_112 = F_219 ( V_380 ) - 1 ;
V_380 &= ~ ( 1 << V_112 ) ;
V_24 = F_220 ( V_1 , V_112 ) ;
if ( V_24 < 0 ) {
F_35 ( & V_107 -> V_5 , L_130
L_113 , V_112 , V_24 ) ;
V_38 = V_24 ;
goto V_429;
}
V_144 = F_221 ( sizeof( struct V_9 ) ,
V_94 ) ;
if ( V_144 == NULL ) {
F_222 ( V_1 , V_24 ) ;
V_38 = - V_152 ;
goto V_429;
}
V_1 -> V_6 [ V_2 ] = V_144 ;
F_223 ( V_144 , & V_107 -> V_5 ) ;
V_10 = F_4 ( V_144 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_112 = V_112 ;
V_10 -> V_24 = V_24 ;
V_10 -> V_26 = - 1 ;
F_7 ( V_144 ) ;
V_144 -> V_108 = V_107 -> V_108 ;
V_144 -> V_430 = V_431 | V_432 |
V_433 | V_434 |
V_182 | V_435 ;
V_144 -> V_436 = V_431 | V_432 |
V_433 | V_434 |
V_437 ;
V_144 -> V_181 = V_144 -> V_430 |
V_183 ;
if ( V_419 )
V_144 -> V_181 |= V_437 ;
V_144 -> V_438 |= V_439 ;
V_144 -> V_440 = & V_441 ;
V_144 -> V_442 = & V_443 ;
V_38 = F_224 ( V_1 , V_2 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_131 ,
V_2 ) ;
goto V_429;
}
}
if ( V_33 == V_444 && F_202 ( V_1 ) == 0 )
V_1 -> V_51 |= V_106 ;
else {
if ( V_33 == V_444 ) {
F_9 ( V_1 -> V_18 ,
L_132
L_133 ) ;
V_33 = V_392 ;
F_179 ( V_1 ) ;
}
V_38 = F_225 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_134
L_113 , V_38 ) ;
goto V_429;
}
V_1 -> V_51 |= V_52 ;
}
F_198 ( V_1 ) ;
F_16 (adapter, pidx) {
struct V_9 * V_10 = F_4 ( V_1 -> V_6 [ V_2 ] ) ;
V_144 = V_1 -> V_6 [ V_2 ] ;
if ( V_144 == NULL )
continue;
F_226 ( V_144 , V_10 -> V_35 ) ;
F_227 ( V_144 , V_10 -> V_35 ) ;
V_38 = F_228 ( V_144 ) ;
if ( V_38 ) {
F_180 ( & V_107 -> V_5 , L_135
L_136 , V_144 -> V_19 ) ;
continue;
}
F_63 ( V_2 , & V_1 -> V_445 ) ;
}
if ( V_1 -> V_445 == 0 ) {
F_35 ( & V_107 -> V_5 , L_137 ) ;
goto V_446;
}
if ( ! F_176 ( V_447 ) ) {
V_1 -> V_387 =
F_229 ( F_117 ( V_107 ) ,
V_447 ) ;
if ( F_176 ( V_1 -> V_387 ) )
F_180 ( & V_107 -> V_5 , L_138
L_139 ) ;
else
F_175 ( V_1 ) ;
}
F_16 (adapter, pidx) {
F_9 ( V_1 -> V_18 , L_140 ,
V_1 -> V_6 [ V_2 ] -> V_19 ,
( V_1 -> V_51 & V_106 ) ? L_141 :
( V_1 -> V_51 & V_52 ) ? L_142 : L_143 ) ;
}
return 0 ;
V_446:
if ( V_1 -> V_51 & V_106 ) {
F_230 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_231 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
V_429:
F_16 (adapter, pidx) {
V_144 = V_1 -> V_6 [ V_2 ] ;
if ( V_144 == NULL )
continue;
V_10 = F_4 ( V_144 ) ;
F_222 ( V_1 , V_10 -> V_24 ) ;
if ( F_232 ( V_2 , & V_1 -> V_445 ) )
F_233 ( V_144 ) ;
F_234 ( V_144 ) ;
}
V_428:
if ( ! F_140 ( V_1 -> V_96 . V_175 ) )
F_235 ( V_1 -> V_426 ) ;
V_425:
F_235 ( V_1 -> V_321 ) ;
V_424:
F_85 ( V_1 ) ;
V_422:
F_236 ( V_107 ) ;
F_237 ( V_107 ) ;
V_421:
F_238 ( V_107 ) ;
return V_38 ;
}
static void F_239 ( struct V_416 * V_107 )
{
struct V_1 * V_1 = F_240 ( V_107 ) ;
if ( V_1 ) {
int V_2 ;
F_16 (adapter, pidx)
if ( F_232 ( V_2 , & V_1 -> V_445 ) )
F_233 ( V_1 -> V_6 [ V_2 ] ) ;
F_241 ( V_1 ) ;
if ( V_1 -> V_51 & V_106 ) {
F_230 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_231 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
if ( ! F_176 ( V_1 -> V_387 ) ) {
F_178 ( V_1 ) ;
F_242 ( V_1 -> V_387 ) ;
}
F_49 ( V_1 ) ;
F_16 (adapter, pidx) {
struct V_4 * V_144 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_144 == NULL )
continue;
V_10 = F_4 ( V_144 ) ;
F_222 ( V_1 , V_10 -> V_24 ) ;
F_234 ( V_144 ) ;
}
F_235 ( V_1 -> V_321 ) ;
if ( ! F_140 ( V_1 -> V_96 . V_175 ) )
F_235 ( V_1 -> V_426 ) ;
F_85 ( V_1 ) ;
}
F_238 ( V_107 ) ;
F_237 ( V_107 ) ;
F_236 ( V_107 ) ;
}
static void F_243 ( struct V_416 * V_107 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_240 ( V_107 ) ;
if ( ! V_1 )
return;
F_16 (adapter, pidx)
if ( F_232 ( V_2 , & V_1 -> V_445 ) )
F_233 ( V_1 -> V_6 [ V_2 ] ) ;
F_241 ( V_1 ) ;
if ( V_1 -> V_51 & V_106 ) {
F_230 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_231 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
F_49 ( V_1 ) ;
F_212 ( V_107 , NULL ) ;
}
static int T_12 F_244 ( void )
{
int V_23 ;
if ( V_33 != V_444 && V_33 != V_392 ) {
F_245 ( L_144 ,
V_33 , V_444 , V_392 ) ;
return - V_155 ;
}
V_447 = F_229 ( V_253 , NULL ) ;
if ( F_176 ( V_447 ) )
F_245 ( L_145 ) ;
V_23 = F_246 ( & V_448 ) ;
if ( V_23 < 0 && ! F_176 ( V_447 ) )
F_247 ( V_447 ) ;
return V_23 ;
}
static void T_13 F_248 ( void )
{
F_249 ( & V_448 ) ;
F_247 ( V_447 ) ;
}
