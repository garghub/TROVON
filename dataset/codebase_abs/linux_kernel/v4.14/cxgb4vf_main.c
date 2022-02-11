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
case 100 :
V_7 = L_1 ;
break;
case 1000 :
V_7 = L_2 ;
break;
case 10000 :
V_7 = L_3 ;
break;
case 25000 :
V_7 = L_4 ;
break;
case 40000 :
V_7 = L_5 ;
break;
case 100000 :
V_7 = L_6 ;
break;
default:
V_7 = L_7 ;
break;
}
switch ( ( int ) V_10 -> V_11 . V_8 ) {
case V_13 :
V_8 = L_8 ;
break;
case V_14 :
V_8 = L_9 ;
break;
case V_13 | V_14 :
V_8 = L_10 ;
break;
default:
V_8 = L_11 ;
break;
}
F_6 ( V_5 , L_12 , V_7 , V_8 ) ;
} else {
F_7 ( V_5 ) ;
F_6 ( V_5 , L_13 ) ;
}
}
void F_8 ( struct V_1 * V_1 , int V_2 )
{
static const char * const V_15 [] = {
NULL , L_14 , L_15 , L_16 , L_17 , L_18 , L_19
} ;
const struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_10 -> V_16 == V_17 )
F_9 ( V_1 -> V_18 , L_20 ,
V_5 -> V_19 ) ;
else if ( V_10 -> V_16 < F_10 ( V_15 ) )
F_9 ( V_1 -> V_18 , L_21 ,
V_5 -> V_19 , V_15 [ V_10 -> V_16 ] ) ;
else if ( V_10 -> V_16 == V_20 )
F_9 ( V_1 -> V_18 , L_22
L_23 , V_5 -> V_19 ) ;
else if ( V_10 -> V_16 == V_21 )
F_9 ( V_1 -> V_18 , L_24
L_25 , V_5 -> V_19 ) ;
else if ( V_10 -> V_16 == V_22 )
F_9 ( V_1 -> V_18 , L_26 ,
V_5 -> V_19 ) ;
else
F_9 ( V_1 -> V_18 , L_27
L_28 , V_5 -> V_19 , V_10 -> V_16 ) ;
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
L_29 , V_1 -> V_19 ) ;
V_1 -> V_29 [ V_31 ] . V_30 [ V_28 ] = 0 ;
F_16 (adapter, pidx) {
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
const struct V_9 * V_10 = F_4 ( V_5 ) ;
int V_32 , V_33 ;
for ( V_32 = 0 , V_33 = V_34 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_33 ++ ) {
snprintf ( V_1 -> V_29 [ V_33 ] . V_30 , V_28 ,
L_30 , V_5 -> V_19 , V_32 ) ;
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
F_35 ( V_1 -> V_18 , L_31
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
L_32 , V_70 ) ;
break;
}
V_72 = V_7 -> V_77 [ V_75 ] ;
if ( F_39 ( V_72 == NULL ) ) {
F_35 ( V_1 -> V_18 ,
L_33 , V_70 ) ;
break;
}
V_74 = F_40 ( V_72 , struct V_73 , V_78 ) ;
if ( F_39 ( V_72 -> V_79 != V_70 ) ) {
F_35 ( V_1 -> V_18 ,
L_34 ,
V_70 , V_72 -> V_79 ) ;
break;
}
V_74 -> V_78 . V_80 ++ ;
F_41 ( V_74 -> V_74 ) ;
break;
}
default:
F_35 ( V_1 -> V_18 ,
L_35 , V_57 ) ;
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
F_35 ( V_1 -> V_18 , L_36 ,
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
F_88 ( V_5 , F_76 , F_81 ) ;
F_89 ( V_5 , F_76 , F_81 ) ;
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
static int F_111 ( enum V_190 V_191 ,
enum V_192 V_16 )
{
if ( V_191 == V_193 ||
V_191 == V_194 ||
V_191 == V_195 ) {
return V_196 ;
} else if ( V_191 == V_197 ||
V_191 == V_198 ) {
return V_199 ;
} else if ( V_191 == V_200 ||
V_191 == V_201 ||
V_191 == V_202 ||
V_191 == V_203 ||
V_191 == V_204 ||
V_191 == V_205 ||
V_191 == V_206 ||
V_191 == V_207 ) {
if ( V_16 == V_208 ||
V_16 == V_209 ||
V_16 == V_210 ||
V_16 == V_211 )
return V_199 ;
else if ( V_16 == V_212 ||
V_16 == V_213 )
return V_214 ;
else
return V_215 ;
} else if ( V_191 == V_216 ||
V_191 == V_217 ) {
return V_218 ;
}
return V_215 ;
}
static void F_112 ( enum V_190 V_191 ,
unsigned int V_219 ,
unsigned long * V_220 )
{
#define F_113 ( T_7 ) \
__set_bit(ETHTOOL_LINK_MODE_ ## __lmm_name ## _BIT, \
link_mode_mask)
#define F_114 ( T_8 , T_7 ) \
do { \
if (fw_caps & FW_PORT_CAP32_ ## __fw_name) \
SET_LMM(__lmm_name); \
} while (0)
switch ( V_191 ) {
case V_193 :
case V_194 :
case V_195 :
F_113 ( V_221 ) ;
F_114 ( V_222 , 100baseT_Full ) ;
F_114 ( V_223 , 1000baseT_Full ) ;
F_114 ( V_224 , 10000baseT_Full ) ;
break;
case V_225 :
case V_226 :
F_113 ( V_227 ) ;
F_114 ( V_223 , 1000baseKX_Full ) ;
F_114 ( V_224 , 10000baseKX4_Full ) ;
break;
case V_228 :
F_113 ( V_227 ) ;
F_113 ( 10000baseKR_Full ) ;
break;
case V_229 :
F_113 ( V_227 ) ;
F_113 ( 10000baseR_FEC ) ;
F_113 ( 10000baseKR_Full ) ;
F_113 ( 1000baseKX_Full ) ;
break;
case V_230 :
F_113 ( V_227 ) ;
F_113 ( 10000baseR_FEC ) ;
F_113 ( 10000baseKR_Full ) ;
F_113 ( 1000baseKX_Full ) ;
F_113 ( 10000baseKX4_Full ) ;
break;
case V_197 :
case V_198 :
case V_200 :
case V_201 :
case V_202 :
F_113 ( V_231 ) ;
F_114 ( V_223 , 1000baseT_Full ) ;
F_114 ( V_224 , 10000baseT_Full ) ;
break;
case V_232 :
case V_203 :
F_113 ( V_231 ) ;
F_113 ( 40000baseSR4_Full ) ;
break;
case V_205 :
case V_207 :
F_113 ( V_231 ) ;
F_113 ( 25000baseCR_Full ) ;
break;
case V_217 :
F_113 ( V_227 ) ;
F_113 ( 25000baseKR_Full ) ;
break;
case V_206 :
F_113 ( V_231 ) ;
F_113 ( 50000baseSR2_Full ) ;
break;
case V_216 :
case V_204 :
F_113 ( V_231 ) ;
F_113 ( 100000baseCR4_Full ) ;
break;
default:
break;
}
F_114 ( V_233 , V_234 ) ;
F_114 ( 802_3_PAUSE , V_235 ) ;
F_114 ( 802_3_ASM_DIR , V_236 ) ;
#undef F_114
#undef F_113
}
static int F_115 ( struct V_4 * V_5 ,
struct V_237 * V_238 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_239 * V_240 = & V_238 -> V_240 ;
if ( ! F_2 ( V_5 ) )
( void ) F_116 ( V_10 ) ;
F_117 ( V_238 , V_241 ) ;
F_117 ( V_238 , V_242 ) ;
F_117 ( V_238 , V_243 ) ;
V_240 -> V_6 = F_111 ( V_10 -> V_191 , V_10 -> V_16 ) ;
if ( V_10 -> V_244 >= 0 ) {
V_240 -> V_245 = V_10 -> V_244 ;
V_240 -> V_246 = ( V_10 -> V_191 == V_193
? V_247
: V_248 ) ;
} else {
V_240 -> V_245 = 255 ;
V_240 -> V_246 = 0 ;
}
F_112 ( V_10 -> V_191 , V_10 -> V_11 . V_249 ,
V_238 -> V_250 . V_241 ) ;
F_112 ( V_10 -> V_191 , V_10 -> V_11 . V_251 ,
V_238 -> V_250 . V_242 ) ;
F_112 ( V_10 -> V_191 , V_10 -> V_11 . V_252 ,
V_238 -> V_250 . V_243 ) ;
if ( F_3 ( V_5 ) ) {
V_240 -> V_12 = V_10 -> V_11 . V_12 ;
V_240 -> V_253 = V_254 ;
} else {
V_240 -> V_12 = V_255 ;
V_240 -> V_253 = V_256 ;
}
V_240 -> V_257 = V_10 -> V_11 . V_257 ;
if ( V_10 -> V_11 . V_249 & V_258 )
F_118 ( V_238 ,
V_241 , V_234 ) ;
if ( V_10 -> V_11 . V_257 )
F_118 ( V_238 ,
V_242 , V_234 ) ;
return 0 ;
}
static void F_119 ( struct V_4 * V_5 ,
struct V_259 * V_260 )
{
struct V_1 * V_1 = F_120 ( V_5 ) ;
F_121 ( V_260 -> V_261 , V_262 , sizeof( V_260 -> V_261 ) ) ;
F_121 ( V_260 -> V_263 , V_264 , sizeof( V_260 -> V_263 ) ) ;
F_121 ( V_260 -> V_265 , F_122 ( F_123 ( V_5 -> V_5 . V_266 ) ) ,
sizeof( V_260 -> V_265 ) ) ;
snprintf ( V_260 -> V_267 , sizeof( V_260 -> V_267 ) ,
L_37 ,
F_124 ( V_1 -> V_96 . V_5 . V_268 ) ,
F_125 ( V_1 -> V_96 . V_5 . V_268 ) ,
F_126 ( V_1 -> V_96 . V_5 . V_268 ) ,
F_127 ( V_1 -> V_96 . V_5 . V_268 ) ,
F_124 ( V_1 -> V_96 . V_5 . V_269 ) ,
F_125 ( V_1 -> V_96 . V_5 . V_269 ) ,
F_126 ( V_1 -> V_96 . V_5 . V_269 ) ,
F_127 ( V_1 -> V_96 . V_5 . V_269 ) ) ;
}
static T_5 F_128 ( struct V_4 * V_5 )
{
return F_120 ( V_5 ) -> V_270 ;
}
static void F_129 ( struct V_4 * V_5 , T_5 V_271 )
{
F_120 ( V_5 ) -> V_270 = V_271 ;
}
static void F_130 ( struct V_4 * V_5 ,
struct V_272 * V_273 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_36 * V_7 = & V_10 -> V_1 -> V_36 ;
V_273 -> V_274 = V_275 ;
V_273 -> V_276 = V_277 ;
V_273 -> V_278 = 0 ;
V_273 -> V_279 = V_280 ;
V_273 -> V_281 = V_7 -> V_42 [ V_10 -> V_85 ] . V_87 . V_282 - V_283 ;
V_273 -> V_284 = V_7 -> V_42 [ V_10 -> V_85 ] . V_43 . V_282 ;
V_273 -> V_285 = 0 ;
V_273 -> V_286 = V_7 -> V_86 [ V_10 -> V_85 ] . V_78 . V_282 ;
}
static int F_131 ( struct V_4 * V_5 ,
struct V_272 * V_273 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_32 ;
if ( V_273 -> V_281 > V_275 ||
V_273 -> V_285 ||
V_273 -> V_286 > V_280 ||
V_273 -> V_284 > V_277 ||
V_273 -> V_284 < V_287 ||
V_273 -> V_281 < V_288 ||
V_273 -> V_286 < V_289 )
return - V_155 ;
if ( V_1 -> V_51 & V_105 )
return - V_290 ;
for ( V_32 = V_10 -> V_85 ; V_32 < V_10 -> V_85 + V_10 -> V_35 ; V_32 ++ ) {
V_7 -> V_42 [ V_32 ] . V_87 . V_282 = V_273 -> V_281 + V_283 ;
V_7 -> V_42 [ V_32 ] . V_43 . V_282 = V_273 -> V_284 ;
V_7 -> V_86 [ V_32 ] . V_78 . V_282 = V_273 -> V_286 ;
}
return 0 ;
}
static int F_132 ( struct V_4 * V_5 ,
struct V_291 * V_292 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
const struct V_1 * V_1 = V_10 -> V_1 ;
const struct V_45 * V_43 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ;
V_292 -> V_293 = F_93 ( V_1 , V_43 ) ;
V_292 -> V_294 =
( ( V_43 -> V_49 & V_295 )
? V_1 -> V_36 . V_168 [ V_43 -> V_167 ]
: 0 ) ;
return 0 ;
}
static int F_133 ( struct V_4 * V_5 ,
struct V_291 * V_292 )
{
const struct V_9 * V_10 = F_4 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
return F_95 ( V_1 ,
& V_1 -> V_36 . V_42 [ V_10 -> V_85 ] . V_43 ,
V_292 -> V_293 ,
V_292 -> V_294 ) ;
}
static void F_134 ( struct V_4 * V_5 ,
struct V_296 * V_297 )
{
struct V_9 * V_10 = F_4 ( V_5 ) ;
V_297 -> V_257 = ( V_10 -> V_11 . V_298 & V_299 ) != 0 ;
V_297 -> V_300 = ( V_10 -> V_11 . V_8 & V_13 ) != 0 ;
V_297 -> V_301 = ( V_10 -> V_11 . V_8 & V_14 ) != 0 ;
}
static int F_135 ( struct V_4 * V_5 ,
enum V_302 V_303 )
{
unsigned int V_304 ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
if ( V_303 == V_305 )
V_304 = 0xffff ;
else if ( V_303 == V_306 )
V_304 = 0 ;
else
return - V_155 ;
return F_136 ( V_10 -> V_1 , V_10 -> V_24 , V_304 ) ;
}
static int F_137 ( struct V_4 * V_5 , int V_307 )
{
switch ( V_307 ) {
case V_308 :
return F_10 ( V_309 ) ;
default:
return - V_179 ;
}
}
static void F_138 ( struct V_4 * V_5 ,
T_5 V_307 ,
T_2 * V_64 )
{
switch ( V_307 ) {
case V_308 :
memcpy ( V_64 , V_309 , sizeof( V_309 ) ) ;
break;
}
}
static void F_139 ( const struct V_1 * V_1 ,
const struct V_9 * V_10 ,
struct V_310 * V_90 )
{
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_10 -> V_85 ] ;
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_10 -> V_85 ] ;
int V_32 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
for ( V_32 = 0 ; V_32 < V_10 -> V_35 ; V_32 ++ , V_37 ++ , V_74 ++ ) {
V_90 -> V_311 += V_74 -> V_311 ;
V_90 -> V_312 += V_74 -> V_313 ;
V_90 -> V_314 += V_37 -> V_90 . V_315 ;
V_90 -> V_316 += V_37 -> V_90 . V_316 ;
V_90 -> V_317 += V_74 -> V_317 ;
V_90 -> V_318 += V_37 -> V_90 . V_318 ;
V_90 -> V_319 += V_37 -> V_90 . V_319 ;
}
}
static void F_140 ( struct V_4 * V_5 ,
struct V_320 * V_90 ,
T_4 * V_64 )
{
struct V_9 * V_10 = F_68 ( V_5 ) ;
struct V_1 * V_1 = V_10 -> V_1 ;
int V_38 = F_70 ( V_1 , V_10 -> V_2 ,
(struct V_114 * ) V_64 ) ;
if ( V_38 )
memset ( V_64 , 0 , sizeof( struct V_114 ) ) ;
V_64 += sizeof( struct V_114 ) / sizeof( T_4 ) ;
F_139 ( V_1 , V_10 , (struct V_310 * ) V_64 ) ;
}
static int F_141 ( struct V_4 * V_5 )
{
return V_321 ;
}
static void F_142 ( struct V_1 * V_1 , void * V_322 ,
unsigned int V_323 , unsigned int V_324 )
{
T_5 * V_325 = V_322 + V_323 - V_326 ;
for ( ; V_323 <= V_324 ; V_323 += sizeof( T_5 ) ) {
if ( V_323 == V_327 + V_328 )
* V_325 ++ = 0xffff ;
else
* V_325 ++ = F_143 ( V_1 , V_323 ) ;
}
}
static void F_144 ( struct V_4 * V_5 ,
struct V_329 * V_330 ,
void * V_322 )
{
struct V_1 * V_1 = F_120 ( V_5 ) ;
V_330 -> V_263 = F_102 ( V_1 ) ;
memset ( V_322 , 0 , V_321 ) ;
F_142 ( V_1 , V_322 ,
V_47 + V_331 ,
V_47 + V_332 ) ;
F_142 ( V_1 , V_322 ,
V_333 + V_334 ,
V_333 + V_335 ) ;
F_142 ( V_1 , V_322 ,
V_336 + V_337 ,
V_336 + ( F_145 ( V_1 -> V_96 . V_175 )
? V_338 : V_339 ) ) ;
F_142 ( V_1 , V_322 ,
V_327 + V_340 ,
V_327 + V_341 ) ;
F_142 ( V_1 , V_322 ,
V_342 + V_343 ,
V_342 + V_344 ) ;
}
static void F_146 ( struct V_4 * V_5 ,
struct V_345 * V_346 )
{
V_346 -> V_241 = 0 ;
V_346 -> V_347 = 0 ;
memset ( & V_346 -> V_348 , 0 , sizeof( V_346 -> V_348 ) ) ;
}
static int F_147 ( struct V_349 * V_350 , void * V_171 )
{
struct V_1 * V_1 = V_350 -> V_351 ;
struct V_352 * log = V_1 -> V_353 ;
struct V_354 * V_142 ;
int V_355 , V_160 ;
if ( V_171 == V_356 ) {
F_148 ( V_350 ,
L_38 ,
L_39 , L_40 , L_41 , L_42 ,
L_43 ) ;
return 0 ;
}
V_355 = log -> V_357 + ( ( V_358 ) V_171 - 2 ) ;
if ( V_355 >= log -> V_282 )
V_355 -= log -> V_282 ;
V_142 = F_149 ( log , V_355 ) ;
if ( V_142 -> V_359 == 0 )
return 0 ;
F_148 ( V_350 , L_44 ,
V_142 -> V_360 , V_142 -> V_359 ,
V_142 -> V_361 , V_142 -> V_362 ) ;
for ( V_160 = 0 ; V_160 < V_363 / 8 ; V_160 ++ ) {
T_4 V_364 = V_142 -> V_178 [ V_160 ] ;
T_5 V_365 = ( T_5 ) ( V_364 >> 32 ) ;
T_5 V_366 = ( T_5 ) V_364 ;
F_148 ( V_350 , L_45 , V_365 , V_366 ) ;
}
F_150 ( V_350 , L_46 ) ;
return 0 ;
}
static inline void * F_151 ( struct V_349 * V_350 , T_9 V_367 )
{
struct V_1 * V_1 = V_350 -> V_351 ;
struct V_352 * log = V_1 -> V_353 ;
return ( ( V_367 <= log -> V_282 ) ? ( void * ) ( V_358 ) ( V_367 + 1 ) : NULL ) ;
}
static void * F_152 ( struct V_349 * V_350 , T_9 * V_367 )
{
return * V_367 ? F_151 ( V_350 , * V_367 ) : V_356 ;
}
static void * F_153 ( struct V_349 * V_350 , void * V_171 , T_9 * V_367 )
{
++ * V_367 ;
return F_151 ( V_350 , * V_367 ) ;
}
static void F_154 ( struct V_349 * V_350 , void * V_171 )
{
}
static int F_155 ( struct V_368 * V_368 , struct V_369 * V_369 )
{
int V_370 = F_156 ( V_369 , & V_371 ) ;
if ( ! V_370 ) {
struct V_349 * V_350 = V_369 -> V_372 ;
V_350 -> V_351 = V_368 -> V_373 ;
}
return V_370 ;
}
static int F_157 ( struct V_349 * V_350 , void * V_171 )
{
struct V_1 * V_1 = V_350 -> V_351 ;
int V_374 = F_158 ( V_1 -> V_36 . V_375 , V_376 ) ;
int V_32 , V_377 = ( V_358 ) V_171 - 1 ;
if ( V_377 )
F_159 ( V_350 , '\n' ) ;
#define F_160 ( T_10 , V_7 , V_171 ) \
do {\
seq_printf(seq, "%-12s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %16" fmt_spec, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_161 ( V_7 , V_171 ) S3("s", s, v)
#define F_162 ( V_7 , V_171 ) S3("u", s, txq[qs].v)
#define F_163 ( V_7 , V_171 ) S3("u", s, rxq[qs].v)
if ( V_377 < V_374 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_377 * V_376 ] ;
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_377 * V_376 ] ;
int V_378 = F_164 ( V_376 , V_1 -> V_36 . V_375 - V_376 * V_377 ) ;
F_161 ( L_47 , L_48 ) ;
F_161 ( L_49 ,
( V_37 [ V_32 ] . V_43 . V_144
? V_37 [ V_32 ] . V_43 . V_144 -> V_19
: L_50 ) ) ;
F_160 ( L_51 , L_52 ,
( V_37 [ V_32 ] . V_43 . V_144
? ( (struct V_9 * )
F_4 ( V_37 [ V_32 ] . V_43 . V_144 ) ) -> V_112
: - 1 ) ) ;
F_162 ( L_53 , V_78 . V_79 ) ;
F_162 ( L_54 , V_78 . V_282 ) ;
F_162 ( L_55 , V_78 . V_379 ) ;
F_162 ( L_56 , V_78 . V_2 ) ;
F_162 ( L_57 , V_78 . V_380 ) ;
F_163 ( L_58 , V_43 . V_79 ) ;
F_163 ( L_59 , V_43 . V_282 ) ;
F_163 ( L_60 , V_43 . V_381 ) ;
F_160 ( L_61 , L_62 , F_93 ( V_1 , & V_37 [ V_32 ] . V_43 ) ) ;
F_160 ( L_61 , L_63 ,
V_1 -> V_36 . V_168 [ V_37 [ V_32 ] . V_43 . V_167 ] ) ;
F_163 ( L_64 , V_43 . V_380 ) ;
F_163 ( L_65 , V_43 . V_382 ) ;
F_163 ( L_66 , V_87 . V_79 ) ;
F_163 ( L_67 , V_87 . V_282 - V_283 ) ;
F_163 ( L_68 , V_87 . V_383 ) ;
F_163 ( L_69 , V_87 . V_2 ) ;
F_163 ( L_70 , V_87 . V_380 ) ;
return 0 ;
}
V_377 -= V_374 ;
if ( V_377 == 0 ) {
const struct V_45 * V_384 = & V_1 -> V_36 . V_41 ;
F_148 ( V_350 , L_71 , L_47 , L_72 ) ;
F_148 ( V_350 , L_73 , L_58 , V_384 -> V_79 ) ;
F_148 ( V_350 , L_73 , L_62 ,
F_93 ( V_1 , V_384 ) ) ;
F_148 ( V_350 , L_73 , L_63 ,
V_1 -> V_36 . V_168 [ V_384 -> V_167 ] ) ;
F_148 ( V_350 , L_73 , L_74 , V_384 -> V_380 ) ;
F_148 ( V_350 , L_73 , L_65 , V_384 -> V_382 ) ;
} else if ( V_377 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_148 ( V_350 , L_71 , L_47 , L_75 ) ;
F_148 ( V_350 , L_73 , L_58 , V_53 -> V_79 ) ;
F_148 ( V_350 , L_73 , L_62 ,
F_93 ( V_1 , V_53 ) ) ;
F_148 ( V_350 , L_73 , L_63 ,
V_1 -> V_36 . V_168 [ V_53 -> V_167 ] ) ;
F_148 ( V_350 , L_73 , L_74 , V_53 -> V_380 ) ;
F_148 ( V_350 , L_73 , L_65 , V_53 -> V_382 ) ;
}
#undef F_163
#undef F_162
#undef F_161
#undef F_160
return 0 ;
}
static int F_165 ( const struct V_1 * V_1 )
{
return F_158 ( V_1 -> V_36 . V_375 , V_376 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_166 ( struct V_349 * V_350 , T_9 * V_367 )
{
int V_385 = F_165 ( V_350 -> V_351 ) ;
return * V_367 < V_385 ? ( void * ) ( ( V_358 ) * V_367 + 1 ) : NULL ;
}
static void F_167 ( struct V_349 * V_350 , void * V_171 )
{
}
static void * F_168 ( struct V_349 * V_350 , void * V_171 , T_9 * V_367 )
{
int V_385 = F_165 ( V_350 -> V_351 ) ;
++ * V_367 ;
return * V_367 < V_385 ? ( void * ) ( ( V_358 ) * V_367 + 1 ) : NULL ;
}
static int F_169 ( struct V_368 * V_368 , struct V_369 * V_369 )
{
int V_370 = F_156 ( V_369 , & V_386 ) ;
if ( ! V_370 ) {
struct V_349 * V_350 = V_369 -> V_372 ;
V_350 -> V_351 = V_368 -> V_373 ;
}
return V_370 ;
}
static int F_170 ( struct V_349 * V_350 , void * V_171 )
{
struct V_1 * V_1 = V_350 -> V_351 ;
int V_374 = F_158 ( V_1 -> V_36 . V_375 , V_376 ) ;
int V_32 , V_377 = ( V_358 ) V_171 - 1 ;
if ( V_377 )
F_159 ( V_350 , '\n' ) ;
#define F_160 ( T_11 , V_7 , V_171 ) \
do { \
seq_printf(seq, "%-16s", s); \
for (qs = 0; qs < n; ++qs) \
seq_printf(seq, " %8" fmt, v); \
seq_putc(seq, '\n'); \
} while (0)
#define F_161 ( V_7 , V_171 ) S3("s", s, v)
#define F_171 ( T_11 , V_7 , V_171 ) S3(fmt, s, txq[qs].v)
#define F_162 ( V_7 , V_171 ) T3("lu", s, v)
#define F_172 ( T_11 , V_7 , V_171 ) S3(fmt, s, rxq[qs].v)
#define F_163 ( V_7 , V_171 ) R3("lu", s, v)
if ( V_377 < V_374 ) {
const struct V_84 * V_37 = & V_1 -> V_36 . V_42 [ V_377 * V_376 ] ;
const struct V_73 * V_74 = & V_1 -> V_36 . V_86 [ V_377 * V_376 ] ;
int V_378 = F_164 ( V_376 , V_1 -> V_36 . V_375 - V_376 * V_377 ) ;
F_161 ( L_47 , L_48 ) ;
F_161 ( L_49 ,
( V_37 [ V_32 ] . V_43 . V_144
? V_37 [ V_32 ] . V_43 . V_144 -> V_19
: L_50 ) ) ;
F_172 ( L_61 , L_76 , V_43 . V_387 ) ;
F_163 ( L_77 , V_90 . V_388 ) ;
F_163 ( L_78 , V_90 . V_315 ) ;
F_163 ( L_79 , V_90 . V_316 ) ;
F_163 ( L_80 , V_90 . V_319 ) ;
F_163 ( L_81 , V_90 . V_318 ) ;
F_163 ( L_82 , V_90 . V_389 ) ;
F_162 ( L_83 , V_311 ) ;
F_162 ( L_84 , V_313 ) ;
F_162 ( L_85 , V_317 ) ;
F_162 ( L_86 , V_78 . V_390 ) ;
F_162 ( L_87 , V_78 . V_80 ) ;
F_162 ( L_88 , V_391 ) ;
F_163 ( L_89 , V_87 . V_392 ) ;
F_163 ( L_90 , V_87 . V_393 ) ;
F_163 ( L_91 , V_87 . V_394 ) ;
return 0 ;
}
V_377 -= V_374 ;
if ( V_377 == 0 ) {
const struct V_45 * V_384 = & V_1 -> V_36 . V_41 ;
F_148 ( V_350 , L_92 , L_47 , L_72 ) ;
F_148 ( V_350 , L_93 , L_76 ,
V_384 -> V_387 ) ;
F_148 ( V_350 , L_93 , L_64 , V_384 -> V_380 ) ;
F_148 ( V_350 , L_93 , L_65 , V_384 -> V_382 ) ;
} else if ( V_377 == 1 ) {
const struct V_45 * V_53 = & V_1 -> V_36 . V_53 ;
F_148 ( V_350 , L_92 , L_47 , L_75 ) ;
F_148 ( V_350 , L_93 , L_76 ,
V_53 -> V_387 ) ;
F_148 ( V_350 , L_93 , L_64 , V_53 -> V_380 ) ;
F_148 ( V_350 , L_93 , L_65 , V_53 -> V_382 ) ;
}
#undef F_163
#undef F_162
#undef F_161
#undef F_172
#undef F_171
#undef F_160
return 0 ;
}
static int F_173 ( const struct V_1 * V_1 )
{
return F_158 ( V_1 -> V_36 . V_375 , V_376 ) + 1 +
( ( V_1 -> V_51 & V_52 ) != 0 ) ;
}
static void * F_174 ( struct V_349 * V_350 , T_9 * V_367 )
{
int V_385 = F_173 ( V_350 -> V_351 ) ;
return * V_367 < V_385 ? ( void * ) ( ( V_358 ) * V_367 + 1 ) : NULL ;
}
static void F_175 ( struct V_349 * V_350 , void * V_171 )
{
}
static void * F_176 ( struct V_349 * V_350 , void * V_171 , T_9 * V_367 )
{
int V_385 = F_173 ( V_350 -> V_351 ) ;
( * V_367 ) ++ ;
return * V_367 < V_385 ? ( void * ) ( ( V_358 ) * V_367 + 1 ) : NULL ;
}
static int F_177 ( struct V_368 * V_368 , struct V_369 * V_369 )
{
int V_370 = F_156 ( V_369 , & V_395 ) ;
if ( V_370 == 0 ) {
struct V_349 * V_350 = V_369 -> V_372 ;
V_350 -> V_351 = V_368 -> V_373 ;
}
return V_370 ;
}
static int F_178 ( struct V_349 * V_350 , void * V_171 )
{
struct V_1 * V_1 = V_350 -> V_351 ;
struct V_396 * V_397 = & V_1 -> V_96 . V_397 ;
#define F_161 ( V_30 , T_11 , T_12 ) \
seq_printf(seq, "%-60s " fmt "\n", \
desc " (" #var "):", vfres->var)
F_161 ( L_94 , L_95 , V_398 ) ;
F_161 ( L_96 , L_95 , V_399 ) ;
F_161 ( L_97 , L_95 , V_400 ) ;
F_161 ( L_98 , L_95 , V_401 ) ;
F_161 ( L_99 , L_95 , V_402 ) ;
F_161 ( L_100 , L_95 , V_403 ) ;
F_161 ( L_101 , L_102 , V_404 ) ;
F_161 ( L_103 , L_95 , V_405 ) ;
F_161 ( L_104 , L_102 , V_406 ) ;
F_161 ( L_105 , L_102 , V_407 ) ;
#undef F_161
return 0 ;
}
static int F_179 ( struct V_368 * V_368 , struct V_369 * V_369 )
{
return F_180 ( V_369 , F_178 , V_368 -> V_373 ) ;
}
static int F_181 ( struct V_349 * V_350 , void * V_171 )
{
if ( V_171 == V_356 ) {
F_150 ( V_350 , L_106 ) ;
} else {
struct V_1 * V_1 = V_350 -> V_351 ;
int V_2 = ( V_358 ) V_171 - 2 ;
struct V_4 * V_5 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 = F_4 ( V_5 ) ;
F_148 ( V_350 , L_107 ,
V_5 -> V_19 , V_10 -> V_112 , V_10 -> V_24 ) ;
}
return 0 ;
}
static inline void * F_182 ( struct V_1 * V_1 , T_9 V_367 )
{
return V_367 <= V_1 -> V_96 . V_408
? ( void * ) ( V_358 ) ( V_367 + 1 )
: NULL ;
}
static void * F_183 ( struct V_349 * V_350 , T_9 * V_367 )
{
return * V_367
? F_182 ( V_350 -> V_351 , * V_367 )
: V_356 ;
}
static void * F_184 ( struct V_349 * V_350 , void * V_171 , T_9 * V_367 )
{
( * V_367 ) ++ ;
return F_182 ( V_350 -> V_351 , * V_367 ) ;
}
static void F_185 ( struct V_349 * V_350 , void * V_171 )
{
}
static int F_186 ( struct V_368 * V_368 , struct V_369 * V_369 )
{
int V_370 = F_156 ( V_369 , & V_409 ) ;
if ( V_370 == 0 ) {
struct V_349 * V_350 = V_369 -> V_372 ;
V_350 -> V_351 = V_368 -> V_373 ;
}
return V_370 ;
}
static int F_187 ( struct V_1 * V_1 )
{
int V_160 ;
F_56 ( F_188 ( V_1 -> V_410 ) ) ;
for ( V_160 = 0 ; V_160 < F_10 ( V_411 ) ; V_160 ++ )
( void ) F_189 ( V_411 [ V_160 ] . V_19 ,
V_411 [ V_160 ] . V_97 ,
V_1 -> V_410 ,
( void * ) V_1 ,
V_411 [ V_160 ] . V_412 ) ;
return 0 ;
}
static void F_190 ( struct V_1 * V_1 )
{
F_56 ( F_188 ( V_1 -> V_410 ) ) ;
}
static void F_191 ( struct V_1 * V_1 )
{
struct V_396 * V_397 = & V_1 -> V_96 . V_397 ;
unsigned int V_375 , V_413 ;
V_1 -> V_96 . V_408 = V_397 -> V_398 ;
if ( V_1 -> V_96 . V_408 > V_414 ) {
F_192 ( V_1 -> V_18 , L_108
L_109 , V_414 ,
V_1 -> V_96 . V_408 ) ;
V_1 -> V_96 . V_408 = V_414 ;
}
V_413 = F_193 ( V_1 -> V_96 . V_397 . V_404 ) ;
if ( V_413 < V_1 -> V_96 . V_408 ) {
F_192 ( V_1 -> V_18 , L_110
L_111
L_112 , V_413 , V_1 -> V_96 . V_408 ,
V_1 -> V_96 . V_397 . V_404 ) ;
V_1 -> V_96 . V_408 = V_413 ;
}
V_375 = V_397 -> V_401 - 1 - ( V_33 == V_415 ) ;
if ( V_397 -> V_400 != V_375 )
V_375 = F_164 ( V_397 -> V_400 , V_375 ) ;
if ( V_397 -> V_399 < V_375 * 2 )
V_375 = V_397 -> V_399 / 2 ;
if ( V_375 > V_416 )
V_375 = V_416 ;
V_1 -> V_36 . V_417 = V_375 ;
if ( V_1 -> V_36 . V_417 < V_1 -> V_96 . V_408 ) {
F_192 ( V_1 -> V_18 , L_113
L_114 ,
V_1 -> V_36 . V_417 , V_1 -> V_96 . V_408 ) ;
V_1 -> V_96 . V_408 = V_1 -> V_36 . V_417 ;
}
}
static int F_194 ( struct V_1 * V_1 )
{
struct V_418 * V_418 = & V_1 -> V_96 . V_36 ;
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_38 ;
T_5 V_419 , V_304 = 0 ;
V_38 = F_195 ( V_1 ) ;
if ( V_38 < 0 ) {
F_35 ( V_1 -> V_18 , L_115 , V_38 ) ;
return V_38 ;
}
V_38 = F_196 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_116
L_117 , V_38 ) ;
return V_38 ;
}
V_38 = F_197 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_116
L_118 , V_38 ) ;
return V_38 ;
}
V_38 = F_198 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_116
L_119 , V_38 ) ;
return V_38 ;
}
V_38 = F_199 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_116
L_120 , V_38 ) ;
return V_38 ;
}
if ( V_1 -> V_96 . V_93 . V_97 !=
V_98 ) {
F_35 ( V_1 -> V_18 , L_121
L_122 , V_1 -> V_96 . V_93 . V_97 ) ;
return - V_155 ;
}
V_38 = F_200 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_123
L_124 , V_38 ) ;
return V_38 ;
}
V_419 = F_96 ( V_420 ) |
F_97 ( V_421 ) ;
V_304 = 1 ;
( void ) F_99 ( V_1 , 1 , & V_419 , & V_304 ) ;
V_7 -> V_164 [ 0 ] = F_201 ( V_1 ,
F_202 ( V_418 -> V_422 ) ) ;
V_7 -> V_164 [ 1 ] = F_201 ( V_1 ,
F_203 ( V_418 -> V_422 ) ) ;
V_7 -> V_164 [ 2 ] = F_201 ( V_1 ,
F_202 ( V_418 -> V_423 ) ) ;
V_7 -> V_164 [ 3 ] = F_201 ( V_1 ,
F_203 ( V_418 -> V_423 ) ) ;
V_7 -> V_164 [ 4 ] = F_201 ( V_1 ,
F_202 ( V_418 -> V_424 ) ) ;
V_7 -> V_164 [ 5 ] = F_201 ( V_1 ,
F_203 ( V_418 -> V_424 ) ) ;
V_7 -> V_168 [ 0 ] = F_204 ( V_418 -> V_425 ) ;
V_7 -> V_168 [ 1 ] = F_205 ( V_418 -> V_425 ) ;
V_7 -> V_168 [ 2 ] = F_206 ( V_418 -> V_425 ) ;
V_7 -> V_168 [ 3 ] = F_207 ( V_418 -> V_425 ) ;
V_38 = F_208 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_125
L_126 , V_38 ) ;
return V_38 ;
}
if ( V_1 -> V_96 . V_397 . V_404 == 0 ) {
F_35 ( V_1 -> V_18 , L_127
L_128 ) ;
return - V_155 ;
}
if ( V_1 -> V_96 . V_397 . V_398 == 0 ) {
F_35 ( V_1 -> V_18 , L_129
L_128 ) ;
return - V_155 ;
}
F_191 ( V_1 ) ;
return 0 ;
}
static inline void F_209 ( struct V_45 * V_43 , T_2 V_161 ,
T_2 V_426 , unsigned int V_282 ,
unsigned int V_427 )
{
V_43 -> V_49 = ( F_100 ( V_161 ) |
( V_426 < V_428 ?
V_295 : 0 ) ) ;
V_43 -> V_167 = ( V_426 < V_428
? V_426
: 0 ) ;
V_43 -> V_381 = V_427 ;
V_43 -> V_282 = V_282 ;
}
static void F_210 ( struct V_1 * V_1 )
{
struct V_36 * V_7 = & V_1 -> V_36 ;
int V_429 , V_430 , V_431 , V_2 , V_32 ;
T_13 V_427 ;
F_56 ( ( V_1 -> V_51 & ( V_106 | V_52 ) ) == 0 ) ;
V_430 = 0 ;
F_16 (adapter, pidx)
V_430 += F_211 ( & F_51 ( V_1 , V_2 ) -> V_11 ) ;
if ( V_430 == 0 )
V_429 = 0 ;
else {
int V_432 = ( V_1 -> V_96 . V_408 - V_430 ) ;
V_429 = ( V_1 -> V_36 . V_417 - V_432 ) / V_430 ;
if ( V_429 > F_212 () )
V_429 = F_212 () ;
}
V_431 = 0 ;
F_16 (adapter, pidx) {
struct V_9 * V_10 = F_51 ( V_1 , V_2 ) ;
V_10 -> V_85 = V_431 ;
V_10 -> V_35 = F_211 ( & V_10 -> V_11 ) ? V_429 : 1 ;
V_431 += V_10 -> V_35 ;
}
V_7 -> V_375 = V_431 ;
V_427 = 64 ;
for ( V_32 = 0 ; V_32 < V_7 -> V_417 ; V_32 ++ ) {
struct V_84 * V_37 = & V_7 -> V_42 [ V_32 ] ;
struct V_73 * V_74 = & V_7 -> V_86 [ V_32 ] ;
F_209 ( & V_37 -> V_43 , 0 , 0 , 1024 , V_427 ) ;
V_37 -> V_87 . V_282 = 72 ;
V_74 -> V_78 . V_282 = 1024 ;
}
F_209 ( & V_7 -> V_41 , V_174 , 0 , 512 , V_427 ) ;
F_209 ( & V_7 -> V_53 , V_174 , 0 , V_433 + 1 ,
V_427 ) ;
}
static void F_213 ( struct V_1 * V_1 , int V_378 )
{
int V_160 ;
struct V_9 * V_10 ;
F_56 ( V_378 < V_1 -> V_96 . V_408 ) ;
while ( V_378 < V_1 -> V_36 . V_375 )
F_16 (adapter, i) {
V_10 = F_51 ( V_1 , V_160 ) ;
if ( V_10 -> V_35 > 1 ) {
V_10 -> V_35 -- ;
V_1 -> V_36 . V_375 -- ;
if ( V_1 -> V_36 . V_375 <= V_378 )
break;
}
}
V_378 = 0 ;
F_16 (adapter, i) {
V_10 = F_51 ( V_1 , V_160 ) ;
V_10 -> V_85 = V_378 ;
V_378 += V_10 -> V_35 ;
}
}
static int F_214 ( struct V_1 * V_1 )
{
int V_160 , V_434 , V_435 , V_35 ;
struct V_436 V_385 [ V_433 ] ;
struct V_36 * V_7 = & V_1 -> V_36 ;
for ( V_160 = 0 ; V_160 < V_433 ; ++ V_160 )
V_385 [ V_160 ] . V_142 = V_160 ;
V_434 = V_7 -> V_417 + V_437 ;
V_435 = V_1 -> V_96 . V_408 + V_437 ;
V_434 = F_215 ( V_1 -> V_107 , V_385 , V_435 , V_434 ) ;
if ( V_434 < 0 )
return V_434 ;
V_35 = V_434 - V_437 ;
if ( V_35 < V_7 -> V_417 ) {
F_192 ( V_1 -> V_18 , L_130
L_131 , V_35 ) ;
V_7 -> V_417 = V_35 ;
if ( V_35 < V_7 -> V_375 )
F_213 ( V_1 , V_35 ) ;
}
for ( V_160 = 0 ; V_160 < V_434 ; ++ V_160 )
V_1 -> V_29 [ V_160 ] . V_39 = V_385 [ V_160 ] . V_438 ;
return 0 ;
}
static int F_216 ( struct V_439 * V_107 ,
const struct V_440 * V_441 )
{
int V_442 ;
int V_38 , V_2 ;
unsigned int V_404 ;
struct V_1 * V_1 ;
struct V_9 * V_10 ;
struct V_4 * V_144 ;
unsigned int V_443 ;
F_217 ( L_132 , V_444 , V_264 ) ;
V_38 = F_218 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_133 ) ;
return V_38 ;
}
V_38 = F_219 ( V_107 , V_262 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_134 ) ;
goto V_445;
}
V_38 = F_220 ( V_107 , F_221 ( 64 ) ) ;
if ( V_38 == 0 ) {
V_38 = F_222 ( V_107 , F_221 ( 64 ) ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_135
L_136 ) ;
goto V_446;
}
V_442 = 1 ;
} else {
V_38 = F_220 ( V_107 , F_221 ( 32 ) ) ;
if ( V_38 != 0 ) {
F_35 ( & V_107 -> V_5 , L_137 ) ;
goto V_446;
}
V_442 = 0 ;
}
F_223 ( V_107 ) ;
V_1 = F_78 ( sizeof( * V_1 ) , V_447 ) ;
if ( ! V_1 ) {
V_38 = - V_152 ;
goto V_446;
}
F_224 ( V_107 , V_1 ) ;
V_1 -> V_107 = V_107 ;
V_1 -> V_18 = & V_107 -> V_5 ;
V_1 -> V_353 = F_78 ( sizeof( * V_1 -> V_353 ) +
( sizeof( struct V_354 ) *
V_448 ) ,
V_447 ) ;
if ( ! V_1 -> V_353 ) {
V_38 = - V_152 ;
goto V_449;
}
V_1 -> V_353 -> V_282 = V_448 ;
F_225 ( & V_1 -> V_116 ) ;
F_225 ( & V_1 -> V_450 ) ;
F_59 ( & V_1 -> V_451 . V_153 ) ;
V_1 -> V_330 = F_226 ( V_107 , 0 ) ;
if ( ! V_1 -> V_330 ) {
F_35 ( & V_107 -> V_5 , L_138 ) ;
V_38 = - V_152 ;
goto V_449;
}
V_38 = F_227 ( V_1 ) ;
if ( V_38 ) {
F_35 ( V_1 -> V_18 , L_139
L_124 , V_38 ) ;
goto V_452;
}
if ( ! F_145 ( V_1 -> V_96 . V_175 ) ) {
V_1 -> V_453 = F_228 ( F_229 ( V_107 , 2 ) ,
F_230 ( V_107 , 2 ) ) ;
if ( ! V_1 -> V_453 ) {
F_35 ( V_1 -> V_18 , L_140 ) ;
V_38 = - V_152 ;
goto V_452;
}
}
V_1 -> V_19 = F_122 ( V_107 ) ;
V_1 -> V_270 = V_454 ;
if ( ! F_231 ( V_107 ) )
V_1 -> V_51 |= V_455 ;
V_38 = F_194 ( V_1 ) ;
if ( V_38 )
goto V_456;
V_404 = V_1 -> V_96 . V_397 . V_404 ;
V_443 = F_232 ( V_1 ) ;
F_16 (adapter, pidx) {
int V_112 , V_24 ;
T_2 V_457 [ V_458 ] ;
unsigned int V_459 = 1 ;
if ( V_404 == 0 )
break;
V_112 = F_233 ( V_404 ) - 1 ;
V_404 &= ~ ( 1 << V_112 ) ;
V_24 = F_234 ( V_1 , V_112 ) ;
if ( V_24 < 0 ) {
F_35 ( & V_107 -> V_5 , L_141
L_124 , V_112 , V_24 ) ;
V_38 = V_24 ;
goto V_460;
}
V_144 = F_235 ( sizeof( struct V_9 ) ,
V_94 ) ;
if ( V_144 == NULL ) {
F_236 ( V_1 , V_24 ) ;
V_38 = - V_152 ;
goto V_460;
}
V_1 -> V_6 [ V_2 ] = V_144 ;
F_237 ( V_144 , & V_107 -> V_5 ) ;
V_10 = F_4 ( V_144 ) ;
V_10 -> V_1 = V_1 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_112 = V_112 ;
V_10 -> V_24 = V_24 ;
V_10 -> V_26 = - 1 ;
F_7 ( V_144 ) ;
V_144 -> V_108 = V_107 -> V_108 ;
V_144 -> V_461 = V_462 | V_463 |
V_464 | V_465 |
V_182 | V_466 ;
V_144 -> V_467 = V_462 | V_463 |
V_464 | V_465 |
V_468 ;
V_144 -> V_181 = V_144 -> V_461 |
V_183 ;
if ( V_442 )
V_144 -> V_181 |= V_468 ;
V_144 -> V_469 |= V_470 ;
V_144 -> V_471 = 81 ;
V_144 -> V_472 = V_473 ;
V_144 -> V_474 = & V_475 ;
V_144 -> V_476 = & V_477 ;
V_144 -> V_478 = V_10 -> V_112 ;
V_38 = F_238 ( V_1 , V_2 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_142 ,
V_2 ) ;
goto V_460;
}
V_38 = F_239 ( V_1 , V_443 , & V_459 , V_457 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 ,
L_143
L_144 , V_38 ) ;
} else if ( V_459 && V_1 -> V_96 . V_397 . V_398 == 1 ) {
struct V_186 V_143 ;
F_79 ( V_143 . V_187 , V_457 ) ;
V_38 = F_108 ( V_144 , & V_143 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 ,
L_145 ,
V_457 ) ;
goto V_460;
}
F_9 ( & V_107 -> V_5 ,
L_146 , V_457 ) ;
}
}
if ( V_33 == V_479 && F_214 ( V_1 ) == 0 )
V_1 -> V_51 |= V_106 ;
else {
if ( V_33 == V_479 ) {
F_9 ( V_1 -> V_18 ,
L_147
L_148 ) ;
V_33 = V_415 ;
F_191 ( V_1 ) ;
}
V_38 = F_240 ( V_107 ) ;
if ( V_38 ) {
F_35 ( & V_107 -> V_5 , L_149
L_124 , V_38 ) ;
goto V_460;
}
V_1 -> V_51 |= V_52 ;
}
F_210 ( V_1 ) ;
F_16 (adapter, pidx) {
struct V_9 * V_10 = F_4 ( V_1 -> V_6 [ V_2 ] ) ;
V_144 = V_1 -> V_6 [ V_2 ] ;
if ( V_144 == NULL )
continue;
F_241 ( V_144 , V_10 -> V_35 ) ;
F_242 ( V_144 , V_10 -> V_35 ) ;
V_38 = F_243 ( V_144 ) ;
if ( V_38 ) {
F_192 ( & V_107 -> V_5 , L_150
L_151 , V_144 -> V_19 ) ;
continue;
}
F_63 ( V_2 , & V_1 -> V_480 ) ;
}
if ( V_1 -> V_480 == 0 ) {
F_35 ( & V_107 -> V_5 , L_152 ) ;
goto V_481;
}
if ( ! F_188 ( V_482 ) ) {
V_1 -> V_410 =
F_244 ( F_122 ( V_107 ) ,
V_482 ) ;
if ( F_188 ( V_1 -> V_410 ) )
F_192 ( & V_107 -> V_5 , L_153
L_154 ) ;
else
F_187 ( V_1 ) ;
}
F_16 (adapter, pidx) {
F_9 ( V_1 -> V_18 , L_155 ,
V_1 -> V_6 [ V_2 ] -> V_19 ,
( V_1 -> V_51 & V_106 ) ? L_156 :
( V_1 -> V_51 & V_52 ) ? L_157 : L_158 ) ;
}
return 0 ;
V_481:
if ( V_1 -> V_51 & V_106 ) {
F_245 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_246 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
V_460:
F_16 (adapter, pidx) {
V_144 = V_1 -> V_6 [ V_2 ] ;
if ( V_144 == NULL )
continue;
V_10 = F_4 ( V_144 ) ;
F_236 ( V_1 , V_10 -> V_24 ) ;
if ( F_247 ( V_2 , & V_1 -> V_480 ) )
F_248 ( V_144 ) ;
F_249 ( V_144 ) ;
}
V_456:
if ( ! F_145 ( V_1 -> V_96 . V_175 ) )
F_250 ( V_1 -> V_453 ) ;
V_452:
F_250 ( V_1 -> V_330 ) ;
V_449:
F_85 ( V_1 -> V_353 ) ;
F_85 ( V_1 ) ;
V_446:
F_251 ( V_107 ) ;
F_252 ( V_107 ) ;
V_445:
F_253 ( V_107 ) ;
return V_38 ;
}
static void F_254 ( struct V_439 * V_107 )
{
struct V_1 * V_1 = F_255 ( V_107 ) ;
if ( V_1 ) {
int V_2 ;
F_16 (adapter, pidx)
if ( F_247 ( V_2 , & V_1 -> V_480 ) )
F_248 ( V_1 -> V_6 [ V_2 ] ) ;
F_256 ( V_1 ) ;
if ( V_1 -> V_51 & V_106 ) {
F_245 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_246 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
if ( ! F_188 ( V_1 -> V_410 ) ) {
F_190 ( V_1 ) ;
F_257 ( V_1 -> V_410 ) ;
}
F_49 ( V_1 ) ;
F_16 (adapter, pidx) {
struct V_4 * V_144 = V_1 -> V_6 [ V_2 ] ;
struct V_9 * V_10 ;
if ( V_144 == NULL )
continue;
V_10 = F_4 ( V_144 ) ;
F_236 ( V_1 , V_10 -> V_24 ) ;
F_249 ( V_144 ) ;
}
F_250 ( V_1 -> V_330 ) ;
if ( ! F_145 ( V_1 -> V_96 . V_175 ) )
F_250 ( V_1 -> V_453 ) ;
F_85 ( V_1 -> V_353 ) ;
F_85 ( V_1 ) ;
}
F_253 ( V_107 ) ;
F_252 ( V_107 ) ;
F_251 ( V_107 ) ;
}
static void F_258 ( struct V_439 * V_107 )
{
struct V_1 * V_1 ;
int V_2 ;
V_1 = F_255 ( V_107 ) ;
if ( ! V_1 )
return;
F_16 (adapter, pidx)
if ( F_247 ( V_2 , & V_1 -> V_480 ) )
F_248 ( V_1 -> V_6 [ V_2 ] ) ;
F_256 ( V_1 ) ;
if ( V_1 -> V_51 & V_106 ) {
F_245 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_106 ;
} else if ( V_1 -> V_51 & V_52 ) {
F_246 ( V_1 -> V_107 ) ;
V_1 -> V_51 &= ~ V_52 ;
}
F_49 ( V_1 ) ;
F_224 ( V_107 , NULL ) ;
}
static int T_14 F_259 ( void )
{
int V_23 ;
if ( V_33 != V_479 && V_33 != V_415 ) {
F_260 ( L_159 ,
V_33 , V_479 , V_415 ) ;
return - V_155 ;
}
V_482 = F_244 ( V_262 , NULL ) ;
if ( F_188 ( V_482 ) )
F_260 ( L_160 ) ;
V_23 = F_261 ( & V_483 ) ;
if ( V_23 < 0 && ! F_188 ( V_482 ) )
F_262 ( V_482 ) ;
return V_23 ;
}
static void T_15 F_263 ( void )
{
F_264 ( & V_483 ) ;
F_262 ( V_482 ) ;
}
