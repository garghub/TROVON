static inline bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_5 -> V_6 [ V_3 ] -> V_7 == V_2 -> V_7 ;
}
static inline bool F_2 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_8 < V_5 -> V_6 [ V_3 ] -> V_9 ;
}
static inline bool F_3 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return V_10 <= V_5 -> V_11 . V_12 . V_13 ;
}
static T_2 F_4 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_15 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = V_5 -> V_6 [ V_14 ] ;
T_2 V_17 = V_18 ;
if ( F_5 ( V_6 -> V_19 . V_20 ) &
V_21 )
V_17 =
F_5 ( V_6 -> V_19 . V_22 [ V_15 ] ) ;
else
V_17 = F_5 ( V_6 -> V_19 . V_22 [ 0 ] ) +
V_15 ;
return V_17 ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_14 ,
struct V_23 * V_24 )
{
unsigned long V_25 = 0 , V_26 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
T_2 V_15 , V_17 ;
enum V_28 V_29 ;
T_2 V_30 , V_10 ;
T_3 V_31 , V_32 ;
T_2 V_33 = 0 ;
V_10 = V_24 -> V_10 ;
if ( 0 == V_10 )
V_32 = F_7 ( V_2 -> V_7 ) ;
else
V_32 = F_8 (
( V_5 -> V_11 . V_12 . V_13
* V_2 -> V_7 ) + ( V_10 - 1 ) ) ;
if ( V_24 -> V_34 == 0 && V_24 -> V_35 == 0 ) {
F_9 ( V_11 , V_32 , V_36 ) ;
goto V_37;
}
V_26 = V_24 -> V_34 ;
F_10 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_25 |= ( 1 <<
( V_38 *
V_15 ) ) ;
}
V_26 = V_24 -> V_35 ;
F_10 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_25 |= ( 1 <<
( V_38 * V_15
+ 1 ) ) ;
}
V_30 = F_11 ( & V_25 ,
( V_39 *
V_38 ) ) ;
V_15 = V_30 / V_38 ;
V_29 = V_30 % V_38 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
V_31 = ( ( V_29 << V_40 ) | V_17 ) ;
F_9 ( V_11 , V_32 , V_31 ) ;
while ( V_30 < ( V_39 * V_38 ) ) {
switch ( V_29 ) {
case V_41 :
V_32 = F_12 ( V_17 ) ;
V_33 = V_24 -> V_42 ;
break;
case V_43 :
V_32 = F_13 ( V_17 ) ;
V_33 = V_24 -> V_44 ;
break;
default:
break;
}
V_30 = F_14 ( & V_25 ,
( V_39 *
V_38 ) ,
V_30 + 1 ) ;
if ( V_30 <
( V_39 * V_38 ) ) {
V_15 = V_30 / V_38 ;
V_29 = V_30 % V_38 ;
V_17 = F_4 ( V_2 , V_14 ,
V_15 ) ;
} else {
V_17 = V_18 ;
V_29 = 0 ;
}
V_31 = ( V_10 ) |
( V_29 << V_45 ) |
( V_17 << V_46 ) |
( 1 << V_47 ) |
( V_33 << V_48 ) ;
F_9 ( V_11 , V_32 , V_31 ) ;
}
V_37:
F_15 ( V_11 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
struct V_49 * V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_50 V_51 ;
T_2 V_17 ;
T_3 V_52 ;
int V_53 = 0 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
memset ( & V_51 , 0 , sizeof( struct V_50 ) ) ;
V_51 . V_54 = V_19 -> V_55 / 128 ;
V_51 . V_56 = V_19 -> V_57 ;
V_51 . V_58 = F_5 ( V_5 -> V_6 [ V_14 ] -> V_19 . V_59 [ 0 ] ) ;
V_51 . V_60 = 0 ;
V_53 = F_17 ( V_11 , V_17 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_1 ,
V_17 , V_53 ) ;
V_53 = - V_63 ;
goto V_64;
}
V_53 = F_19 ( V_11 , V_17 , & V_51 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_2 ,
V_17 , V_53 ) ;
V_53 = - V_63 ;
goto V_64;
}
V_52 = V_65 ;
V_52 |= ( ( V_11 -> V_66 << V_67 )
& V_68 ) ;
V_52 |= ( ( ( V_2 -> V_7 + V_11 -> V_12 . V_69 )
<< V_70 )
& V_71 ) ;
F_9 ( V_11 , F_20 ( V_17 ) , V_52 ) ;
F_15 ( V_11 ) ;
V_64:
return V_53 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
struct V_72 * V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_73 V_74 ;
T_2 V_17 ;
int V_53 = 0 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
memset ( & V_74 , 0 , sizeof( struct V_73 ) ) ;
V_74 . V_54 = V_19 -> V_55 / 128 ;
V_74 . V_56 = V_19 -> V_57 ;
if ( V_19 -> V_75 ) {
V_74 . V_76 = V_77 |
V_78 |
V_79 |
V_80 ;
if ( V_19 -> V_81 > ( ( 2 * 1024 ) - 64 ) ) {
V_53 = - V_82 ;
goto V_83;
}
V_74 . V_84 = V_19 -> V_81 >> V_85 ;
V_74 . V_86 = 0x2 ;
}
if ( V_19 -> V_87 > ( ( 16 * 1024 ) - 128 ) ) {
V_53 = - V_82 ;
goto V_83;
}
V_74 . V_88 = V_19 -> V_87 >> V_89 ;
if ( V_19 -> V_90 >= ( 16 * 1024 ) || V_19 -> V_90 < 64 ) {
V_53 = - V_82 ;
goto V_83;
}
V_74 . V_91 = V_19 -> V_90 ;
V_74 . V_92 = 1 ;
V_74 . V_93 = 1 ;
V_74 . V_94 = 1 ;
V_74 . V_95 = 1 ;
V_74 . V_96 = 1 ;
V_74 . V_97 = 2 ;
V_74 . V_98 = 1 ;
V_53 = F_22 ( V_11 , V_17 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_3 ,
V_17 , V_53 ) ;
V_53 = - V_63 ;
goto V_83;
}
V_53 = F_23 ( V_11 , V_17 , & V_74 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_4 ,
V_17 , V_53 ) ;
V_53 = - V_63 ;
goto V_83;
}
V_83:
return V_53 ;
}
static int F_24 ( struct V_1 * V_2 , enum V_99 type )
{
struct V_100 * V_101 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 ;
int V_53 = 0 ;
V_6 = F_25 ( V_5 , type , V_5 -> V_6 [ V_5 -> V_102 ] -> V_103 , V_2 -> V_7 ) ;
if ( ! V_6 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_5 ,
V_2 -> V_7 , V_5 -> V_11 . V_104 . V_105 ) ;
V_53 = - V_63 ;
goto V_106;
}
if ( type == V_107 ) {
T_1 V_108 [ V_109 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_2 -> V_110 = V_6 -> V_111 ;
V_2 -> V_112 = V_6 -> V_113 ;
F_26 ( & V_5 -> V_61 -> V_62 ,
L_6 ,
V_2 -> V_7 , V_6 -> V_111 , V_6 -> V_113 ) ;
if ( V_2 -> V_114 )
F_27 ( V_6 , V_2 -> V_114 ) ;
V_101 = F_28 ( V_6 , V_2 -> V_115 . V_116 ,
V_2 -> V_114 , true , false ) ;
if ( ! V_101 )
F_26 ( & V_5 -> V_61 -> V_62 ,
L_7 ) ;
V_101 = F_28 ( V_6 , V_108 , V_2 -> V_114 ,
true , false ) ;
if ( ! V_101 )
F_26 ( & V_5 -> V_61 -> V_62 ,
L_8 ) ;
}
if ( ! V_101 ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_9 ) ;
V_53 = - V_117 ;
goto V_106;
}
V_53 = F_29 ( V_6 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_10 ) ;
goto V_106;
}
V_106:
return V_53 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
T_3 V_31 , V_118 = 0 ;
int V_119 ;
F_9 ( V_11 , F_31 ( V_2 -> V_112 ) ,
V_120 ) ;
V_31 = V_121 ;
F_9 ( V_11 , F_32 ( V_2 -> V_7 ) , V_31 ) ;
for ( V_119 = 0 ; V_119 < V_5 -> V_6 [ V_2 -> V_110 ] -> V_9 ; V_119 ++ ) {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_110 , V_119 ) ;
V_31 = ( V_8 & V_122 ) ;
F_9 ( V_11 , F_33 ( V_118 , V_2 -> V_7 ) , V_31 ) ;
V_118 ++ ;
}
for ( V_119 = 0 ; V_119 < 7 ; V_119 ++ ) {
if ( V_119 * 2 >= V_5 -> V_6 [ V_2 -> V_110 ] -> V_9 ) {
V_31 = 0x07FF07FF ;
} else {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_110 ,
V_119 * 2 ) ;
V_31 = V_8 ;
V_8 = F_4 ( V_2 , V_2 -> V_110 ,
( V_119 * 2 ) + 1 ) ;
V_31 |= V_8 << 16 ;
}
F_9 ( V_11 , F_34 ( V_119 , V_2 -> V_112 ) , V_31 ) ;
}
F_15 ( V_11 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
int V_123 ;
F_9 ( V_11 , F_32 ( V_2 -> V_7 ) , 0 ) ;
for ( V_123 = 0 ; V_123 < V_39 ; V_123 ++ )
F_9 ( V_11 , F_33 ( V_123 , V_2 -> V_7 ) ,
V_18 ) ;
F_15 ( V_11 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
T_3 V_32 , V_31 ;
int V_123 , V_124 ;
if ( V_2 -> V_110 ) {
F_37 ( V_5 -> V_6 [ V_2 -> V_110 ] ) ;
V_2 -> V_110 = 0 ;
V_2 -> V_112 = 0 ;
}
V_124 = V_5 -> V_11 . V_12 . V_13 + 1 ;
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ ) {
if ( 0 == V_123 )
V_32 = F_38 ( V_2 -> V_7 ) ;
else
V_32 = F_39 ( ( ( V_124 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_123 - 1 ) ) ;
F_9 ( V_11 , V_32 , V_125 ) ;
F_15 ( V_11 ) ;
}
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ ) {
if ( 0 == V_123 )
V_32 = F_7 ( V_2 -> V_7 ) ;
else
V_32 = F_8 ( ( ( V_124 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_123 - 1 ) ) ;
V_31 = ( V_126 |
V_127 ) ;
F_9 ( V_11 , V_32 , V_31 ) ;
F_15 ( V_11 ) ;
}
V_2 -> V_9 = 0 ;
V_2 -> V_128 = 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_118 = 0 ;
int V_53 ;
V_53 = F_24 ( V_2 , V_107 ) ;
if ( V_53 )
goto V_129;
V_118 += V_5 -> V_6 [ V_2 -> V_110 ] -> V_9 ;
F_41 ( V_130 , & V_2 -> V_131 ) ;
V_2 -> V_9 = V_118 ;
F_41 ( V_132 , & V_2 -> V_128 ) ;
V_129:
if ( V_53 )
F_36 ( V_2 ) ;
return V_53 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
int V_133 , V_123 ;
T_3 V_31 ;
V_133 = V_2 -> V_7 + V_11 -> V_12 . V_69 ;
F_9 ( V_11 , V_134 ,
V_135 | ( V_133 << V_136 ) ) ;
for ( V_123 = 0 ; V_123 < 100 ; V_123 ++ ) {
V_31 = F_43 ( V_11 , V_137 ) ;
if ( ( V_31 & V_138 ) == 0 )
return 0 ;
F_44 ( 1 ) ;
}
return - V_139 ;
}
void F_45 ( struct V_1 * V_2 , bool V_140 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
bool V_141 = false ;
int V_123 ;
T_3 V_31 ;
F_46 ( V_142 , & V_2 -> V_128 ) ;
if ( ! V_140 ) {
V_31 = F_43 ( V_11 , F_47 ( V_2 -> V_7 ) ) ;
V_31 |= V_143 ;
F_9 ( V_11 , F_47 ( V_2 -> V_7 ) , V_31 ) ;
F_15 ( V_11 ) ;
}
if ( F_42 ( V_2 ) )
F_18 ( & V_5 -> V_61 -> V_62 , L_11 ,
V_2 -> V_7 ) ;
for ( V_123 = 0 ; V_123 < 100 ; V_123 ++ ) {
F_44 ( 10 ) ;
V_31 = F_43 ( V_11 , F_48 ( V_2 -> V_7 ) ) ;
if ( V_31 & V_144 ) {
V_141 = true ;
break;
}
}
if ( ! V_141 )
F_18 ( & V_5 -> V_61 -> V_62 , L_12 ,
V_2 -> V_7 ) ;
F_9 ( V_11 , F_49 ( V_2 -> V_7 ) , V_145 ) ;
V_31 = F_43 ( V_11 , F_47 ( V_2 -> V_7 ) ) ;
V_31 &= ~ V_143 ;
F_9 ( V_11 , F_47 ( V_2 -> V_7 ) , V_31 ) ;
if ( V_2 -> V_110 == 0 )
goto V_146;
F_50 ( V_5 -> V_6 [ V_2 -> V_110 ] , false ) ;
V_146:
F_36 ( V_2 ) ;
F_51 ( 10 ) ;
F_40 ( V_2 ) ;
F_30 ( V_2 ) ;
F_9 ( V_11 , F_49 ( V_2 -> V_7 ) , V_147 ) ;
F_15 ( V_11 ) ;
}
static bool F_52 ( struct V_4 * V_5 )
{
struct V_148 * V_61 = V_5 -> V_61 ;
struct V_148 * V_149 ;
V_149 = F_53 ( V_150 , V_151 , NULL ) ;
while ( V_149 ) {
if ( V_149 -> V_152 && F_54 ( V_149 ) == V_61 ) {
if ( V_149 -> V_153 & V_154 )
return true ;
}
V_149 = F_53 ( V_150 ,
V_151 ,
V_149 ) ;
}
return false ;
}
static void F_55 ( struct V_4 * V_5 )
{
struct V_16 * V_6 = V_5 -> V_6 [ V_5 -> V_102 ] ;
struct V_155 V_156 ;
int V_157 ;
V_156 . V_103 = V_5 -> V_158 ;
V_156 . V_159 = V_5 -> V_11 . V_66 ;
V_156 . V_160 = 0 ;
V_157 = F_56 ( & V_5 -> V_11 , & V_156 , NULL ) ;
if ( V_157 ) {
F_26 ( & V_5 -> V_61 -> V_62 ,
L_13 ,
V_161 , V_157 , V_5 -> V_11 . V_104 . V_105 ) ;
return;
}
V_156 . V_162 = V_163 ;
V_156 . V_19 . V_164 = F_57 ( V_165 ) ;
V_156 . V_19 . V_166 |= F_57 ( V_167 ) ;
V_157 = F_58 ( & V_6 -> V_168 -> V_11 , & V_156 , NULL ) ;
if ( V_157 ) {
F_26 ( & V_5 -> V_61 -> V_62 ,
L_14 ,
V_161 , V_6 -> V_168 -> V_11 . V_104 . V_105 ) ;
}
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_16 * V_6 = V_5 -> V_6 [ V_5 -> V_102 ] ;
struct V_155 V_156 ;
int V_157 ;
V_156 . V_103 = V_5 -> V_158 ;
V_156 . V_159 = V_5 -> V_11 . V_66 ;
V_156 . V_160 = 0 ;
V_157 = F_56 ( & V_5 -> V_11 , & V_156 , NULL ) ;
if ( V_157 ) {
F_26 ( & V_5 -> V_61 -> V_62 ,
L_13 ,
V_161 , V_157 , V_5 -> V_11 . V_104 . V_105 ) ;
return;
}
V_156 . V_162 = V_163 ;
V_156 . V_19 . V_164 = F_57 ( V_165 ) ;
V_156 . V_19 . V_166 &= ~ F_57 ( V_167 ) ;
V_157 = F_58 ( & V_6 -> V_168 -> V_11 , & V_156 , NULL ) ;
if ( V_157 ) {
F_26 ( & V_5 -> V_61 -> V_62 ,
L_14 ,
V_161 , V_6 -> V_168 -> V_11 . V_104 . V_105 ) ;
}
}
void F_60 ( struct V_4 * V_5 )
{
struct V_27 * V_11 = & V_5 -> V_11 ;
T_3 V_32 , V_169 ;
int V_123 , V_170 , V_7 ;
if ( ! V_5 -> V_2 )
return;
F_61 ( V_5 ) ;
F_51 ( 10 ) ;
V_170 = V_5 -> V_171 ;
V_5 -> V_171 = 0 ;
for ( V_123 = 0 ; V_123 < V_170 ; V_123 ++ ) {
if ( F_62 ( V_132 , & V_5 -> V_2 [ V_123 ] . V_128 ) )
F_36 ( & V_5 -> V_2 [ V_123 ] ) ;
F_35 ( & V_5 -> V_2 [ V_123 ] ) ;
}
F_63 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
if ( ! F_52 ( V_5 ) ) {
F_64 ( V_5 -> V_61 ) ;
for ( V_7 = 0 ; V_7 < V_170 ; V_7 ++ ) {
V_32 = ( V_11 -> V_12 . V_69 + V_7 ) / 32 ;
V_169 = ( V_11 -> V_12 . V_69 + V_7 ) % 32 ;
F_9 ( V_11 , F_65 ( V_32 ) , ( 1 << V_169 ) ) ;
}
F_59 ( V_5 ) ;
} else {
F_66 ( & V_5 -> V_61 -> V_62 ,
L_15 ) ;
}
F_67 ( V_5 ) ;
}
static int F_68 ( struct V_4 * V_5 , T_2 V_171 )
{
struct V_1 * V_172 ;
int V_123 , V_53 = 0 ;
F_61 ( V_5 ) ;
V_53 = F_69 ( V_5 -> V_61 , V_171 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_16 , V_53 ) ;
V_5 -> V_171 = 0 ;
goto V_173;
}
V_172 = F_70 ( V_171 * sizeof( struct V_1 ) , V_174 ) ;
if ( ! V_172 ) {
V_53 = - V_117 ;
goto V_175;
}
for ( V_123 = 0 ; V_123 < V_171 ; V_123 ++ ) {
V_172 [ V_123 ] . V_5 = V_5 ;
V_172 [ V_123 ] . V_176 = V_177 ;
V_172 [ V_123 ] . V_7 = V_123 ;
F_41 ( V_178 , & V_172 [ V_123 ] . V_131 ) ;
F_45 ( & V_172 [ V_123 ] , false ) ;
F_30 ( & V_172 [ V_123 ] ) ;
}
V_5 -> V_2 = V_172 ;
V_5 -> V_171 = V_171 ;
F_55 ( V_5 ) ;
V_175:
if ( V_53 )
F_60 ( V_5 ) ;
V_173:
F_67 ( V_5 ) ;
return V_53 ;
}
static int F_71 ( struct V_148 * V_61 , int V_179 )
{
#ifdef F_72
struct V_4 * V_5 = F_73 ( V_61 ) ;
int V_180 = F_74 ( V_61 ) ;
int V_181 = 0 ;
F_26 ( & V_61 -> V_62 , L_17 , V_179 ) ;
if ( V_180 && V_180 != V_179 )
F_60 ( V_5 ) ;
else if ( V_180 && V_180 == V_179 )
goto V_182;
if ( V_179 > V_5 -> V_183 ) {
V_181 = - V_184 ;
goto V_185;
}
V_181 = F_68 ( V_5 , V_179 ) ;
if ( V_181 ) {
F_66 ( & V_61 -> V_62 , L_18 , V_181 ) ;
goto V_185;
}
V_182:
return V_179 ;
V_185:
return V_181 ;
#endif
return 0 ;
}
int F_75 ( struct V_148 * V_61 , int V_179 )
{
struct V_4 * V_5 = F_73 ( V_61 ) ;
if ( V_179 )
return F_71 ( V_61 , V_179 ) ;
F_60 ( V_5 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , T_3 V_186 ,
T_3 V_187 , T_1 * V_188 , T_2 V_189 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
int V_190 = V_2 -> V_7 + V_11 -> V_12 . V_69 ;
T_4 V_157 ;
if ( V_187 ) {
V_2 -> V_191 ++ ;
F_18 ( & V_5 -> V_61 -> V_62 , L_19 ,
V_186 , V_187 ) ;
if ( V_2 -> V_191 >
V_192 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_20 ,
V_2 -> V_7 ) ;
F_18 ( & V_5 -> V_61 -> V_62 , L_21 ) ;
F_41 ( V_193 , & V_2 -> V_128 ) ;
}
} else {
V_2 -> V_194 ++ ;
}
V_157 = F_77 ( V_11 , V_190 , V_186 , V_187 ,
V_188 , V_189 , NULL ) ;
if ( V_157 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_22 ,
V_2 -> V_7 , V_5 -> V_11 . V_104 . V_105 ) ;
return - V_139 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
enum V_195 V_196 ,
T_4 V_197 )
{
return F_76 ( V_2 , V_196 , V_197 , NULL , 0 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_198 V_19 = {
V_199 , V_200
} ;
return F_76 ( V_2 , V_201 ,
V_202 , ( T_1 * ) & V_19 ,
sizeof( struct
V_198 ) ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_203 * V_204 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_157 = 0 ;
struct V_16 * V_6 ;
int V_123 = 0 , V_205 = 0 ;
int V_206 = 1 ;
int V_53 ;
if ( ! F_62 ( V_132 , & V_2 -> V_128 ) ) {
V_157 = V_207 ;
goto V_181;
}
V_205 = ( sizeof( struct V_203 ) +
sizeof( struct V_208 ) * V_206 ) ;
V_204 = F_70 ( V_205 , V_174 ) ;
if ( ! V_204 ) {
V_157 = V_209 ;
V_205 = 0 ;
goto V_181;
}
V_204 -> V_210 = V_211 ;
V_6 = V_5 -> V_6 [ V_2 -> V_110 ] ;
if ( ! V_6 -> V_19 . V_212 )
V_204 -> V_210 |= V_213 ;
V_204 -> V_206 = V_206 ;
V_204 -> V_9 = V_2 -> V_9 ;
V_204 -> V_214 = V_5 -> V_11 . V_12 . V_13 ;
if ( V_2 -> V_110 ) {
V_204 -> V_215 [ V_123 ] . V_3 = V_2 -> V_110 ;
V_204 -> V_215 [ V_123 ] . V_216 = V_107 ;
V_204 -> V_215 [ V_123 ] . V_9 =
V_5 -> V_6 [ V_2 -> V_110 ] -> V_9 ;
memcpy ( V_204 -> V_215 [ V_123 ] . V_217 ,
V_2 -> V_115 . V_116 , V_109 ) ;
V_123 ++ ;
}
F_41 ( V_142 , & V_2 -> V_128 ) ;
V_181:
V_53 = F_76 ( V_2 , V_218 ,
V_157 , ( T_1 * ) V_204 , V_205 ) ;
F_63 ( V_204 ) ;
return V_53 ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( F_62 ( V_142 , & V_2 -> V_128 ) )
F_45 ( V_2 , false ) ;
}
static int F_82 ( struct V_1 * V_2 ,
T_1 * V_188 , T_2 V_189 )
{
struct V_219 * V_19 =
(struct V_219 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
bool V_220 = false ;
bool V_221 = false ;
T_4 V_157 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ||
! F_62 ( V_130 , & V_2 -> V_131 ) ||
! F_1 ( V_2 , V_19 -> V_3 ) ||
( V_5 -> V_6 [ V_19 -> V_3 ] -> type != V_222 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( V_19 -> V_162 & V_223 )
V_221 = true ;
V_157 = F_83 ( V_11 , V_19 -> V_3 ,
V_221 , NULL ) ;
if ( V_157 )
goto V_83;
if ( V_19 -> V_162 & V_224 )
V_220 = true ;
V_157 = F_84 ( V_11 , V_19 -> V_3 ,
V_220 , NULL ) ;
V_83:
return F_78 ( V_2 ,
V_225 ,
V_157 ) ;
}
static int F_85 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_226 * V_227 =
(struct V_226 * ) V_188 ;
struct V_228 * V_229 ;
T_2 V_3 , V_15 ;
T_4 V_157 = 0 ;
int V_123 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ) {
V_157 = V_207 ;
goto V_83;
}
V_3 = V_227 -> V_3 ;
if ( ! F_1 ( V_2 , V_3 ) ) {
V_157 = V_207 ;
goto V_83;
}
for ( V_123 = 0 ; V_123 < V_227 -> V_9 ; V_123 ++ ) {
V_229 = & V_227 -> V_230 [ V_123 ] ;
V_15 = V_229 -> V_231 . V_232 ;
if ( ( V_229 -> V_231 . V_3 != V_3 ) ||
( V_229 -> V_233 . V_3 != V_3 ) ||
( V_229 -> V_233 . V_232 != V_15 ) ||
! F_2 ( V_2 , V_3 , V_15 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( F_21 ( V_2 , V_3 , V_15 ,
& V_229 -> V_233 ) ||
F_16 ( V_2 , V_3 , V_15 ,
& V_229 -> V_231 ) ) {
V_157 = V_207 ;
goto V_83;
}
}
V_83:
return F_78 ( V_2 , V_234 ,
V_157 ) ;
}
static int F_86 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_235 * V_236 =
(struct V_235 * ) V_188 ;
struct V_23 * V_237 ;
T_2 V_3 , V_15 , V_10 ;
T_4 V_157 = 0 ;
unsigned long V_26 ;
int V_123 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ) {
V_157 = V_207 ;
goto V_83;
}
for ( V_123 = 0 ; V_123 < V_236 -> V_238 ; V_123 ++ ) {
V_237 = & V_236 -> V_24 [ V_123 ] ;
V_10 = V_237 -> V_10 ;
V_3 = V_237 -> V_3 ;
if ( ! F_3 ( V_2 , V_10 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_157 = V_207 ;
goto V_83;
}
V_26 = V_237 -> V_34 ;
F_10 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_157 = V_207 ;
goto V_83;
}
}
V_26 = V_237 -> V_35 ;
F_10 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_157 = V_207 ;
goto V_83;
}
}
F_6 ( V_2 , V_3 , V_237 ) ;
}
V_83:
return F_78 ( V_2 , V_239 ,
V_157 ) ;
}
static int F_87 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_240 * V_241 =
(struct V_240 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_241 -> V_3 ;
T_4 V_157 = 0 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( ! F_1 ( V_2 , V_3 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( ( 0 == V_241 -> V_242 ) && ( 0 == V_241 -> V_243 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( F_50 ( V_5 -> V_6 [ V_3 ] , true ) )
V_157 = V_244 ;
V_83:
return F_78 ( V_2 , V_245 ,
V_157 ) ;
}
static int F_88 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_240 * V_241 =
(struct V_240 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_241 -> V_3 ;
T_4 V_157 = 0 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( ! F_1 ( V_2 , V_241 -> V_3 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( ( 0 == V_241 -> V_242 ) && ( 0 == V_241 -> V_243 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( F_50 ( V_5 -> V_6 [ V_3 ] , false ) )
V_157 = V_244 ;
V_83:
return F_78 ( V_2 , V_246 ,
V_157 ) ;
}
static int F_89 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_240 * V_241 =
(struct V_240 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_247 V_248 ;
T_4 V_157 = 0 ;
struct V_16 * V_6 ;
memset ( & V_248 , 0 , sizeof( struct V_247 ) ) ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ) {
V_157 = V_207 ;
goto V_83;
}
if ( ! F_1 ( V_2 , V_241 -> V_3 ) ) {
V_157 = V_207 ;
goto V_83;
}
V_6 = V_5 -> V_6 [ V_241 -> V_3 ] ;
if ( ! V_6 ) {
V_157 = V_207 ;
goto V_83;
}
F_90 ( V_6 ) ;
V_248 = V_6 -> V_249 ;
V_83:
return F_76 ( V_2 , V_250 , V_157 ,
( T_1 * ) & V_248 , sizeof( V_248 ) ) ;
}
static inline int F_91 ( struct V_1 * V_2 , T_1 * V_251 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_53 = 0 ;
if ( F_92 ( V_251 ) ||
F_93 ( V_251 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_23 , V_251 ) ;
V_53 = V_252 ;
} else if ( V_2 -> V_253 && ! F_94 ( V_251 ) &&
! F_95 ( V_251 , V_2 -> V_115 . V_116 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_24 ) ;
V_53 = - V_184 ;
}
return V_53 ;
}
static int F_96 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_254 * V_255 =
(struct V_254 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_255 -> V_3 ;
T_4 V_53 = 0 ;
int V_123 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ||
! F_62 ( V_130 , & V_2 -> V_131 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_53 = V_207 ;
goto V_83;
}
for ( V_123 = 0 ; V_123 < V_255 -> V_256 ; V_123 ++ ) {
V_53 = F_91 ( V_2 , V_255 -> V_257 [ V_123 ] . V_116 ) ;
if ( V_53 )
goto V_83;
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_123 = 0 ; V_123 < V_255 -> V_256 ; V_123 ++ ) {
struct V_100 * V_101 ;
V_101 = F_97 ( V_6 , V_255 -> V_257 [ V_123 ] . V_116 , true , false ) ;
if ( ! V_101 ) {
if ( F_98 ( V_6 ) )
V_101 = F_99 ( V_6 , V_255 -> V_257 [ V_123 ] . V_116 ,
true , false ) ;
else
V_101 = F_28 ( V_6 , V_255 -> V_257 [ V_123 ] . V_116 , - 1 ,
true , false ) ;
}
if ( ! V_101 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_25 ) ;
V_53 = V_207 ;
goto V_83;
}
}
if ( F_29 ( V_6 ) )
F_18 ( & V_5 -> V_61 -> V_62 , L_26 ) ;
V_83:
return F_78 ( V_2 , V_258 ,
V_53 ) ;
}
static int F_100 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_254 * V_255 =
(struct V_254 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_255 -> V_3 ;
T_4 V_53 = 0 ;
int V_123 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ||
! F_62 ( V_130 , & V_2 -> V_131 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_53 = V_207 ;
goto V_83;
}
for ( V_123 = 0 ; V_123 < V_255 -> V_256 ; V_123 ++ ) {
if ( F_92 ( V_255 -> V_257 [ V_123 ] . V_116 ) ||
F_93 ( V_255 -> V_257 [ V_123 ] . V_116 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_23 ,
V_255 -> V_257 [ V_123 ] . V_116 ) ;
V_53 = V_252 ;
goto V_83;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_123 = 0 ; V_123 < V_255 -> V_256 ; V_123 ++ )
F_101 ( V_6 , V_255 -> V_257 [ V_123 ] . V_116 ,
V_259 , true , false ) ;
if ( F_29 ( V_6 ) )
F_18 ( & V_5 -> V_61 -> V_62 , L_26 ) ;
V_83:
return F_78 ( V_2 , V_260 ,
V_53 ) ;
}
static int F_102 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_261 * V_262 =
(struct V_261 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_262 -> V_3 ;
T_4 V_157 = 0 ;
int V_123 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ||
! F_62 ( V_130 , & V_2 -> V_131 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_157 = V_207 ;
goto V_83;
}
for ( V_123 = 0 ; V_123 < V_262 -> V_256 ; V_123 ++ ) {
if ( V_262 -> V_263 [ V_123 ] > V_264 ) {
V_157 = V_207 ;
F_18 ( & V_5 -> V_61 -> V_62 ,
L_27 , V_262 -> V_263 [ V_123 ] ) ;
goto V_83;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_212 ) {
V_157 = V_207 ;
goto V_83;
}
F_103 ( V_6 ) ;
for ( V_123 = 0 ; V_123 < V_262 -> V_256 ; V_123 ++ ) {
int V_53 = F_104 ( V_6 , V_262 -> V_263 [ V_123 ] ) ;
if ( V_53 )
F_18 ( & V_5 -> V_61 -> V_62 ,
L_28 ,
V_262 -> V_263 [ V_123 ] , V_53 ) ;
}
V_83:
return F_78 ( V_2 , V_265 , V_157 ) ;
}
static int F_105 ( struct V_1 * V_2 , T_1 * V_188 , T_2 V_189 )
{
struct V_261 * V_262 =
(struct V_261 * ) V_188 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_262 -> V_3 ;
T_4 V_157 = 0 ;
int V_123 ;
if ( ! F_62 ( V_142 , & V_2 -> V_128 ) ||
! F_62 ( V_130 , & V_2 -> V_131 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_157 = V_207 ;
goto V_83;
}
for ( V_123 = 0 ; V_123 < V_262 -> V_256 ; V_123 ++ ) {
if ( V_262 -> V_263 [ V_123 ] > V_264 ) {
V_157 = V_207 ;
goto V_83;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_212 ) {
V_157 = V_207 ;
goto V_83;
}
for ( V_123 = 0 ; V_123 < V_262 -> V_256 ; V_123 ++ ) {
int V_53 = F_106 ( V_6 , V_262 -> V_263 [ V_123 ] ) ;
if ( V_53 )
F_18 ( & V_5 -> V_61 -> V_62 ,
L_29 ,
V_262 -> V_263 [ V_123 ] , V_53 ) ;
}
V_83:
return F_78 ( V_2 , V_266 , V_157 ) ;
}
static int F_107 ( struct V_1 * V_2 , T_3 V_186 ,
T_3 V_187 , T_1 * V_188 , T_2 V_189 )
{
bool V_267 = false ;
int V_268 ;
if ( F_62 ( V_193 , & V_2 -> V_128 ) )
return V_207 ;
switch ( V_186 ) {
case V_201 :
V_268 = sizeof( struct V_198 ) ;
break;
case V_269 :
case V_218 :
V_268 = 0 ;
break;
case V_270 :
V_268 = sizeof( struct V_49 ) ;
break;
case V_271 :
V_268 = sizeof( struct V_72 ) ;
break;
case V_234 :
V_268 = sizeof( struct V_226 ) ;
if ( V_189 >= V_268 ) {
struct V_226 * V_272 =
(struct V_226 * ) V_188 ;
V_268 += ( V_272 -> V_9 *
sizeof( struct
V_228 ) ) ;
if ( V_272 -> V_9 == 0 )
V_267 = true ;
}
break;
case V_239 :
V_268 = sizeof( struct V_235 ) ;
if ( V_189 >= V_268 ) {
struct V_235 * V_273 =
(struct V_235 * ) V_188 ;
V_268 += ( V_273 -> V_238 *
sizeof( struct V_23 ) ) ;
if ( V_273 -> V_238 == 0 )
V_267 = true ;
}
break;
case V_245 :
case V_246 :
V_268 = sizeof( struct V_240 ) ;
break;
case V_258 :
case V_260 :
V_268 = sizeof( struct V_254 ) ;
if ( V_189 >= V_268 ) {
struct V_254 * V_274 =
(struct V_254 * ) V_188 ;
V_268 += V_274 -> V_256 *
sizeof( struct V_275 ) ;
if ( V_274 -> V_256 == 0 )
V_267 = true ;
}
break;
case V_265 :
case V_266 :
V_268 = sizeof( struct V_261 ) ;
if ( V_189 >= V_268 ) {
struct V_261 * V_262 =
(struct V_261 * ) V_188 ;
V_268 += V_262 -> V_256 * sizeof( T_2 ) ;
if ( V_262 -> V_256 == 0 )
V_267 = true ;
}
break;
case V_225 :
V_268 = sizeof( struct V_219 ) ;
break;
case V_250 :
V_268 = sizeof( struct V_240 ) ;
break;
case V_276 :
case V_277 :
default:
return - V_184 ;
break;
}
if ( ( V_268 != V_189 ) || ( V_267 ) ) {
F_78 ( V_2 , V_186 , V_207 ) ;
return - V_82 ;
} else {
return 0 ;
}
}
int F_108 ( struct V_4 * V_5 , T_2 V_7 , T_3 V_186 ,
T_3 V_187 , T_1 * V_188 , T_2 V_189 )
{
struct V_27 * V_11 = & V_5 -> V_11 ;
int V_278 = V_7 - V_11 -> V_12 . V_69 ;
struct V_1 * V_2 ;
int V_53 ;
V_5 -> V_279 ++ ;
if ( V_278 >= V_5 -> V_171 )
return - V_82 ;
V_2 = & ( V_5 -> V_2 [ V_278 ] ) ;
V_53 = F_107 ( V_2 , V_186 , V_187 , V_188 , V_189 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_30 ,
V_278 , V_186 , V_189 ) ;
return V_53 ;
}
switch ( V_186 ) {
case V_201 :
V_53 = F_79 ( V_2 ) ;
break;
case V_218 :
V_53 = F_80 ( V_2 ) ;
break;
case V_269 :
F_81 ( V_2 ) ;
V_53 = 0 ;
break;
case V_225 :
V_53 = F_82 ( V_2 , V_188 , V_189 ) ;
break;
case V_234 :
V_53 = F_85 ( V_2 , V_188 , V_189 ) ;
break;
case V_239 :
V_53 = F_86 ( V_2 , V_188 , V_189 ) ;
break;
case V_245 :
V_53 = F_87 ( V_2 , V_188 , V_189 ) ;
break;
case V_246 :
V_53 = F_88 ( V_2 , V_188 , V_189 ) ;
break;
case V_258 :
V_53 = F_96 ( V_2 , V_188 , V_189 ) ;
break;
case V_260 :
V_53 = F_100 ( V_2 , V_188 , V_189 ) ;
break;
case V_265 :
V_53 = F_102 ( V_2 , V_188 , V_189 ) ;
break;
case V_266 :
V_53 = F_105 ( V_2 , V_188 , V_189 ) ;
break;
case V_250 :
V_53 = F_89 ( V_2 , V_188 , V_189 ) ;
break;
case V_277 :
default:
F_18 ( & V_5 -> V_61 -> V_62 , L_31 ,
V_186 , V_278 ) ;
V_53 = F_78 ( V_2 , V_186 ,
V_280 ) ;
break;
}
return V_53 ;
}
int F_109 ( struct V_4 * V_5 )
{
T_3 V_31 , V_32 , V_169 , V_7 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 ;
if ( ! F_62 ( V_281 , & V_5 -> V_282 ) )
return 0 ;
F_46 ( V_281 , & V_5 -> V_282 ) ;
for ( V_7 = 0 ; V_7 < V_5 -> V_171 ; V_7 ++ ) {
V_32 = ( V_11 -> V_12 . V_69 + V_7 ) / 32 ;
V_169 = ( V_11 -> V_12 . V_69 + V_7 ) % 32 ;
V_2 = & V_5 -> V_2 [ V_7 ] ;
V_31 = F_43 ( V_11 , F_65 ( V_32 ) ) ;
if ( V_31 & ( 1 << V_169 ) ) {
F_9 ( V_11 , F_65 ( V_32 ) , ( 1 << V_169 ) ) ;
F_45 ( V_2 , true ) ;
}
}
V_31 = F_43 ( V_11 , V_283 ) ;
V_31 |= V_284 ;
F_9 ( V_11 , V_283 , V_31 ) ;
F_15 ( V_11 ) ;
return 0 ;
}
static void F_110 ( struct V_4 * V_5 ,
enum V_195 V_186 ,
T_4 V_187 , T_1 * V_188 ,
T_2 V_189 )
{
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_5 -> V_171 ; V_123 ++ ) {
F_77 ( V_11 , V_2 -> V_7 , V_186 , V_187 ,
V_188 , V_189 , NULL ) ;
V_2 ++ ;
}
}
void F_111 ( struct V_4 * V_5 )
{
struct V_285 V_286 ;
V_286 . V_287 = V_288 ;
V_286 . V_289 = V_290 ;
V_286 . V_291 . V_292 . V_293 =
V_5 -> V_11 . V_294 . V_295 . V_295 & V_296 ;
V_286 . V_291 . V_292 . V_297 = V_5 -> V_11 . V_294 . V_295 . V_297 ;
F_110 ( V_5 , V_276 , V_202 ,
( T_1 * ) & V_286 , sizeof( struct V_285 ) ) ;
}
void F_112 ( struct V_4 * V_5 )
{
struct V_285 V_286 ;
V_286 . V_287 = V_298 ;
V_286 . V_289 = V_299 ;
F_110 ( V_5 , V_276 , V_202 ,
( T_1 * ) & V_286 , sizeof( struct V_285 ) ) ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_285 V_286 ;
V_286 . V_287 = V_298 ;
V_286 . V_289 = V_299 ;
F_77 ( & V_2 -> V_5 -> V_11 , V_2 -> V_7 , V_276 ,
V_202 , ( T_1 * ) & V_286 ,
sizeof( struct V_285 ) , NULL ) ;
}
int F_114 ( struct V_300 * V_301 , int V_7 , T_1 * V_302 )
{
struct V_303 * V_304 = F_115 ( V_301 ) ;
struct V_16 * V_6 = V_304 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_168 ;
struct V_100 * V_101 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
if ( V_7 >= V_5 -> V_171 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_32 , V_7 ) ;
V_53 = - V_82 ;
goto V_83;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_110 ] ;
if ( ! F_62 ( V_132 , & V_2 -> V_128 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_33 , V_7 ) ;
V_53 = - V_82 ;
goto V_83;
}
if ( ! F_116 ( V_302 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_34 ) ;
V_53 = - V_82 ;
goto V_83;
}
F_101 ( V_6 , V_2 -> V_115 . V_116 , 0 , true , false ) ;
V_101 = F_28 ( V_6 , V_302 , 0 , true , false ) ;
if ( ! V_101 ) {
F_18 ( & V_5 -> V_61 -> V_62 ,
L_35 ) ;
V_53 = - V_117 ;
goto V_83;
}
F_26 ( & V_5 -> V_61 -> V_62 , L_36 , V_302 , V_7 ) ;
if ( F_29 ( V_6 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_10 ) ;
V_53 = - V_139 ;
goto V_83;
}
memcpy ( V_2 -> V_115 . V_116 , V_302 , V_109 ) ;
V_2 -> V_253 = true ;
F_26 ( & V_5 -> V_61 -> V_62 , L_37 ) ;
V_53 = 0 ;
V_83:
return V_53 ;
}
int F_117 ( struct V_300 * V_301 ,
int V_7 , T_2 V_263 , T_1 V_305 )
{
struct V_303 * V_304 = F_115 ( V_301 ) ;
struct V_4 * V_5 = V_304 -> V_6 -> V_168 ;
struct V_16 * V_6 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
if ( V_7 >= V_5 -> V_171 ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_32 , V_7 ) ;
V_53 = - V_82 ;
goto V_306;
}
if ( ( V_263 > V_264 ) || ( V_305 > 7 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_38 ) ;
V_53 = - V_82 ;
goto V_306;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_110 ] ;
if ( ! F_62 ( V_132 , & V_2 -> V_128 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_33 , V_7 ) ;
V_53 = - V_82 ;
goto V_306;
}
if ( V_6 -> V_19 . V_212 == 0 && F_98 ( V_6 ) )
F_18 ( & V_5 -> V_61 -> V_62 ,
L_39 ,
V_7 ) ;
if ( ! ( V_263 || V_305 ) && V_6 -> V_19 . V_212 )
V_53 = F_104 ( V_6 , V_259 ) ;
if ( V_6 -> V_19 . V_212 ) {
V_53 = F_106 ( V_6 , ( F_5 ( V_6 -> V_19 . V_212 ) &
V_307 ) ) ;
if ( V_53 ) {
F_26 ( & V_6 -> V_168 -> V_61 -> V_62 ,
L_40 ,
V_53 , V_5 -> V_11 . V_104 . V_105 ) ;
}
}
if ( V_263 || V_305 )
V_53 = F_27 ( V_6 ,
V_263 | ( V_305 << V_308 ) ) ;
else
F_118 ( V_6 ) ;
if ( V_263 ) {
F_26 ( & V_5 -> V_61 -> V_62 , L_41 ,
V_263 , V_305 , V_7 ) ;
V_53 = F_104 ( V_6 , V_263 ) ;
if ( V_53 ) {
F_26 ( & V_6 -> V_168 -> V_61 -> V_62 ,
L_42 , V_53 ,
V_6 -> V_168 -> V_11 . V_104 . V_105 ) ;
goto V_306;
}
F_106 ( V_6 , V_259 ) ;
}
if ( V_53 ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_43 ) ;
goto V_306;
}
V_2 -> V_114 = F_5 ( V_6 -> V_19 . V_212 ) ;
V_53 = 0 ;
V_306:
return V_53 ;
}
int F_119 ( struct V_300 * V_301 , int V_7 , int V_309 )
{
return - V_310 ;
}
int F_120 ( struct V_300 * V_301 ,
int V_7 , struct V_311 * V_312 )
{
struct V_303 * V_304 = F_115 ( V_301 ) ;
struct V_16 * V_6 = V_304 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_168 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
if ( V_7 >= V_5 -> V_171 ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_32 , V_7 ) ;
V_53 = - V_82 ;
goto V_83;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_110 ] ;
if ( ! F_62 ( V_132 , & V_2 -> V_128 ) ) {
F_18 ( & V_5 -> V_61 -> V_62 , L_33 , V_7 ) ;
V_53 = - V_82 ;
goto V_83;
}
V_312 -> V_2 = V_7 ;
memcpy ( & V_312 -> V_302 , V_2 -> V_115 . V_116 , V_109 ) ;
V_312 -> V_309 = 0 ;
V_312 -> V_313 = F_5 ( V_6 -> V_19 . V_212 ) & V_314 ;
V_312 -> V_305 = ( F_5 ( V_6 -> V_19 . V_212 ) & V_315 ) >>
V_308 ;
V_53 = 0 ;
V_83:
return V_53 ;
}
