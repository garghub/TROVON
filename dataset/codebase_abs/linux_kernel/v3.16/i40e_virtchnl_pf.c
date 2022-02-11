static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 |= V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
F_5 ( V_6 ) ;
}
static inline bool F_6 ( struct V_3 * V_4 , T_2 V_10 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_2 -> V_11 [ V_10 ] -> V_8 == V_4 -> V_8 ;
}
static inline bool F_7 ( struct V_3 * V_4 , T_2 V_10 ,
T_2 V_12 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_12 < V_2 -> V_11 [ V_10 ] -> V_13 ;
}
static inline bool F_8 ( struct V_3 * V_4 , T_2 V_14 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return V_14 < V_2 -> V_6 . V_15 . V_16 ;
}
static T_3 F_9 ( struct V_3 * V_4 , T_2 V_17 ,
T_2 V_18 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = V_2 -> V_11 [ V_17 ] ;
T_3 V_20 = V_21 ;
if ( F_10 ( V_11 -> V_22 . V_23 ) &
V_24 )
V_20 =
F_10 ( V_11 -> V_22 . V_25 [ V_18 ] ) ;
else
V_20 = F_10 ( V_11 -> V_22 . V_25 [ 0 ] ) +
V_18 ;
return V_20 ;
}
static void F_11 ( struct V_3 * V_4 , T_3 V_17 ,
struct V_26 * V_27 )
{
unsigned long V_28 = 0 , V_29 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_3 V_18 , V_20 ;
enum V_30 V_31 ;
T_3 V_32 , V_14 ;
T_1 V_7 , V_33 ;
T_3 V_34 = 0 ;
V_14 = V_27 -> V_14 ;
if ( 0 == V_14 )
V_33 = F_12 ( V_4 -> V_8 ) ;
else
V_33 = F_13 (
( ( V_2 -> V_6 . V_15 . V_16 - 1 ) * V_4 -> V_8 ) +
( V_14 - 1 ) ) ;
if ( V_27 -> V_35 == 0 && V_27 -> V_36 == 0 ) {
F_4 ( V_6 , V_33 , V_37 ) ;
goto V_38;
}
V_29 = V_27 -> V_35 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_28 |= ( 1 <<
( V_39 *
V_18 ) ) ;
}
V_29 = V_27 -> V_36 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_28 |= ( 1 <<
( V_39 * V_18
+ 1 ) ) ;
}
V_32 = F_15 ( & V_28 ,
( V_40 *
V_39 ) ) ;
V_18 = V_32 / V_39 ;
V_31 = V_32 % V_39 ;
V_20 = F_9 ( V_4 , V_17 , V_18 ) ;
V_7 = ( ( V_31 << V_41 ) | V_20 ) ;
F_4 ( V_6 , V_33 , V_7 ) ;
while ( V_32 < ( V_40 * V_39 ) ) {
switch ( V_31 ) {
case V_42 :
V_33 = F_16 ( V_20 ) ;
V_34 = V_27 -> V_43 ;
break;
case V_44 :
V_33 = F_17 ( V_20 ) ;
V_34 = V_27 -> V_45 ;
break;
default:
break;
}
V_32 = F_18 ( & V_28 ,
( V_40 *
V_39 ) ,
V_32 + 1 ) ;
if ( V_32 <
( V_40 * V_39 ) ) {
V_18 = V_32 / V_39 ;
V_31 = V_32 % V_39 ;
V_20 = F_9 ( V_4 , V_17 ,
V_18 ) ;
} else {
V_20 = V_21 ;
V_31 = 0 ;
}
V_7 = ( V_14 ) |
( V_31 << V_46 ) |
( V_20 << V_47 ) |
( 1 << V_48 ) |
( V_34 << V_49 ) ;
F_4 ( V_6 , V_33 , V_7 ) ;
}
V_38:
F_5 ( V_6 ) ;
}
static int F_19 ( struct V_3 * V_4 , T_3 V_17 ,
T_3 V_18 ,
struct V_50 * V_22 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_51 V_52 ;
T_3 V_20 ;
T_1 V_53 ;
int V_54 = 0 ;
V_20 = F_9 ( V_4 , V_17 , V_18 ) ;
memset ( & V_52 , 0 , sizeof( struct V_51 ) ) ;
V_52 . V_55 = V_22 -> V_56 / 128 ;
V_52 . V_57 = V_22 -> V_58 ;
V_52 . V_59 = F_10 ( V_2 -> V_11 [ V_17 ] -> V_22 . V_60 [ 0 ] ) ;
V_52 . V_61 = 0 ;
V_52 . V_62 = V_22 -> V_63 ;
V_52 . V_64 = V_22 -> V_65 ;
V_54 = F_20 ( V_6 , V_20 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_1 ,
V_20 , V_54 ) ;
V_54 = - V_68 ;
goto V_69;
}
V_54 = F_22 ( V_6 , V_20 , & V_52 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_2 ,
V_20 , V_54 ) ;
V_54 = - V_68 ;
goto V_69;
}
V_53 = V_70 ;
V_53 |= ( ( V_6 -> V_71 << V_72 )
& V_73 ) ;
V_53 |= ( ( ( V_4 -> V_8 + V_6 -> V_15 . V_74 )
<< V_75 )
& V_76 ) ;
F_4 ( V_6 , F_23 ( V_20 ) , V_53 ) ;
F_5 ( V_6 ) ;
V_69:
return V_54 ;
}
static int F_24 ( struct V_3 * V_4 , T_3 V_17 ,
T_3 V_18 ,
struct V_77 * V_22 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_78 V_79 ;
T_3 V_20 ;
int V_54 = 0 ;
V_20 = F_9 ( V_4 , V_17 , V_18 ) ;
memset ( & V_79 , 0 , sizeof( struct V_78 ) ) ;
V_79 . V_55 = V_22 -> V_56 / 128 ;
V_79 . V_57 = V_22 -> V_58 ;
if ( V_22 -> V_80 ) {
V_79 . V_81 = V_82 |
V_83 |
V_84 |
V_85 ;
if ( V_22 -> V_86 > ( ( 2 * 1024 ) - 64 ) ) {
V_54 = - V_87 ;
goto V_88;
}
V_79 . V_89 = V_22 -> V_86 >> V_90 ;
V_79 . V_91 = 0x2 ;
}
if ( V_22 -> V_92 > ( ( 16 * 1024 ) - 128 ) ) {
V_54 = - V_87 ;
goto V_88;
}
V_79 . V_93 = V_22 -> V_92 >> V_94 ;
if ( V_22 -> V_95 >= ( 16 * 1024 ) || V_22 -> V_95 < 64 ) {
V_54 = - V_87 ;
goto V_88;
}
V_79 . V_96 = V_22 -> V_95 ;
V_79 . V_97 = 1 ;
V_79 . V_98 = 1 ;
V_79 . V_99 = 1 ;
V_79 . V_100 = 1 ;
V_79 . V_101 = 1 ;
V_79 . V_102 = 2 ;
V_79 . V_103 = 1 ;
V_79 . V_104 = 1 ;
V_54 = F_25 ( V_6 , V_20 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_3 ,
V_20 , V_54 ) ;
V_54 = - V_68 ;
goto V_88;
}
V_54 = F_26 ( V_6 , V_20 , & V_79 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_4 ,
V_20 , V_54 ) ;
V_54 = - V_68 ;
goto V_88;
}
V_88:
return V_54 ;
}
static int F_27 ( struct V_3 * V_4 , enum V_105 type )
{
struct V_106 * V_107 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 ;
int V_54 = 0 ;
V_11 = F_28 ( V_2 , type , V_2 -> V_11 [ V_2 -> V_108 ] -> V_109 , V_4 -> V_8 ) ;
if ( ! V_11 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_5 ,
V_4 -> V_8 , V_2 -> V_6 . V_110 . V_111 ) ;
V_54 = - V_68 ;
goto V_112;
}
if ( type == V_113 ) {
T_2 V_114 [ V_115 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_116 = V_11 -> V_117 ;
V_4 -> V_118 = V_11 -> V_119 ;
F_29 ( & V_2 -> V_66 -> V_67 ,
L_6 ,
V_4 -> V_8 , V_11 -> V_117 , V_11 -> V_119 ) ;
if ( V_4 -> V_120 )
F_30 ( V_11 , V_4 -> V_120 ) ;
V_107 = F_31 ( V_11 , V_4 -> V_121 . V_122 ,
V_4 -> V_120 , true , false ) ;
if ( ! V_107 )
F_29 ( & V_2 -> V_66 -> V_67 ,
L_7 ) ;
V_107 = F_31 ( V_11 , V_114 , V_4 -> V_120 ,
true , false ) ;
if ( ! V_107 )
F_29 ( & V_2 -> V_66 -> V_67 ,
L_8 ) ;
}
V_54 = F_32 ( V_11 ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 , L_9 ) ;
if ( V_4 -> V_123 ) {
V_54 = F_33 ( & V_2 -> V_6 , V_11 -> V_109 ,
V_4 -> V_123 / 50 , 0 , NULL ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 , L_10 ,
V_4 -> V_8 , V_54 ) ;
}
V_112:
return V_54 ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_124 = 0 ;
int V_125 ;
F_4 ( V_6 , F_35 ( V_4 -> V_118 ) ,
V_126 ) ;
V_7 = V_127 ;
F_4 ( V_6 , F_36 ( V_4 -> V_8 ) , V_7 ) ;
for ( V_125 = 0 ; V_125 < V_2 -> V_11 [ V_4 -> V_116 ] -> V_13 ; V_125 ++ ) {
T_3 V_12 = F_9 ( V_4 , V_4 -> V_116 , V_125 ) ;
V_7 = ( V_12 & V_128 ) ;
F_4 ( V_6 , F_37 ( V_124 , V_4 -> V_8 ) , V_7 ) ;
V_124 ++ ;
}
for ( V_125 = 0 ; V_125 < 7 ; V_125 ++ ) {
if ( V_125 * 2 >= V_2 -> V_11 [ V_4 -> V_116 ] -> V_13 ) {
V_7 = 0x07FF07FF ;
} else {
T_3 V_12 = F_9 ( V_4 , V_4 -> V_116 ,
V_125 * 2 ) ;
V_7 = V_12 ;
V_12 = F_9 ( V_4 , V_4 -> V_116 ,
( V_125 * 2 ) + 1 ) ;
V_7 |= V_12 << 16 ;
}
F_4 ( V_6 , F_38 ( V_125 , V_4 -> V_118 ) , V_7 ) ;
}
F_5 ( V_6 ) ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_129 ;
F_4 ( V_6 , F_36 ( V_4 -> V_8 ) , 0 ) ;
for ( V_129 = 0 ; V_129 < V_40 ; V_129 ++ )
F_4 ( V_6 , F_37 ( V_129 , V_4 -> V_8 ) ,
V_21 ) ;
F_5 ( V_6 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_33 , V_7 ;
int V_129 , V_130 ;
if ( V_4 -> V_116 ) {
F_41 ( V_2 -> V_11 [ V_4 -> V_116 ] ) ;
V_4 -> V_116 = 0 ;
V_4 -> V_118 = 0 ;
}
V_130 = V_2 -> V_6 . V_15 . V_16 ;
for ( V_129 = 0 ; V_129 < V_130 ; V_129 ++ ) {
if ( 0 == V_129 )
V_33 = F_42 ( V_4 -> V_8 ) ;
else
V_33 = F_43 ( ( ( V_130 - 1 ) *
( V_4 -> V_8 ) )
+ ( V_129 - 1 ) ) ;
F_4 ( V_6 , V_33 , V_131 ) ;
F_5 ( V_6 ) ;
}
for ( V_129 = 0 ; V_129 < V_130 ; V_129 ++ ) {
if ( 0 == V_129 )
V_33 = F_12 ( V_4 -> V_8 ) ;
else
V_33 = F_13 ( ( ( V_130 - 1 ) *
( V_4 -> V_8 ) )
+ ( V_129 - 1 ) ) ;
V_7 = ( V_132 |
V_133 ) ;
F_4 ( V_6 , V_33 , V_7 ) ;
F_5 ( V_6 ) ;
}
V_4 -> V_13 = 0 ;
V_4 -> V_134 = 0 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_124 = 0 ;
int V_54 ;
V_54 = F_27 ( V_4 , V_113 ) ;
if ( V_54 )
goto V_135;
V_124 += V_2 -> V_11 [ V_4 -> V_116 ] -> V_13 ;
F_45 ( V_136 , & V_4 -> V_137 ) ;
V_4 -> V_13 = V_124 ;
F_45 ( V_138 , & V_4 -> V_134 ) ;
V_135:
if ( V_54 )
F_40 ( V_4 ) ;
return V_54 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_139 , V_129 ;
T_1 V_7 ;
V_139 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
F_4 ( V_6 , V_140 ,
V_141 | ( V_139 << V_142 ) ) ;
for ( V_129 = 0 ; V_129 < 100 ; V_129 ++ ) {
V_7 = F_2 ( V_6 , V_143 ) ;
if ( ( V_7 & V_144 ) == 0 )
return 0 ;
F_47 ( 1 ) ;
}
return - V_145 ;
}
void F_48 ( struct V_3 * V_4 , bool V_146 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_147 = false ;
int V_129 ;
T_1 V_7 ;
F_49 ( V_148 , & V_4 -> V_134 ) ;
if ( ! V_146 ) {
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 |= V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
F_5 ( V_6 ) ;
}
if ( F_46 ( V_4 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_11 ,
V_4 -> V_8 ) ;
for ( V_129 = 0 ; V_129 < 100 ; V_129 ++ ) {
F_47 ( 10 ) ;
V_7 = F_2 ( V_6 , F_50 ( V_4 -> V_8 ) ) ;
if ( V_7 & V_149 ) {
V_147 = true ;
break;
}
}
if ( ! V_147 )
F_21 ( & V_2 -> V_66 -> V_67 , L_12 ,
V_4 -> V_8 ) ;
F_4 ( V_6 , F_51 ( V_4 -> V_8 ) , V_150 ) ;
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 &= ~ V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
if ( V_4 -> V_116 == 0 )
goto V_151;
F_52 ( V_2 -> V_11 [ V_4 -> V_116 ] , false ) ;
V_151:
F_40 ( V_4 ) ;
F_44 ( V_4 ) ;
F_34 ( V_4 ) ;
F_45 ( V_148 , & V_4 -> V_134 ) ;
F_4 ( V_6 , F_51 ( V_4 -> V_8 ) , V_152 ) ;
F_5 ( V_6 ) ;
}
static bool F_53 ( struct V_1 * V_2 )
{
struct V_153 * V_66 = V_2 -> V_66 ;
struct V_153 * V_154 ;
V_154 = F_54 ( V_155 , V_156 , NULL ) ;
while ( V_154 ) {
if ( V_154 -> V_157 && F_55 ( V_154 ) == V_66 ) {
if ( V_154 -> V_158 & V_159 )
return true ;
}
V_154 = F_54 ( V_155 ,
V_156 ,
V_154 ) ;
}
return false ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_108 ] ;
struct V_160 V_161 ;
int V_162 ;
V_161 . V_109 = V_2 -> V_163 ;
V_161 . V_164 = V_2 -> V_6 . V_71 ;
V_161 . V_165 = 0 ;
V_162 = F_57 ( & V_2 -> V_6 , & V_161 , NULL ) ;
if ( V_162 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_166 , V_162 , V_2 -> V_6 . V_110 . V_111 ) ;
return;
}
V_161 . V_167 = V_168 ;
V_161 . V_22 . V_169 = F_58 ( V_170 ) ;
V_161 . V_22 . V_171 |= F_58 ( V_172 ) ;
V_162 = F_59 ( & V_11 -> V_173 -> V_6 , & V_161 , NULL ) ;
if ( V_162 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_166 , V_11 -> V_173 -> V_6 . V_110 . V_111 ) ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_108 ] ;
struct V_160 V_161 ;
int V_162 ;
V_161 . V_109 = V_2 -> V_163 ;
V_161 . V_164 = V_2 -> V_6 . V_71 ;
V_161 . V_165 = 0 ;
V_162 = F_57 ( & V_2 -> V_6 , & V_161 , NULL ) ;
if ( V_162 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_166 , V_162 , V_2 -> V_6 . V_110 . V_111 ) ;
return;
}
V_161 . V_167 = V_168 ;
V_161 . V_22 . V_169 = F_58 ( V_170 ) ;
V_161 . V_22 . V_171 &= ~ F_58 ( V_172 ) ;
V_162 = F_59 ( & V_11 -> V_173 -> V_6 , & V_161 , NULL ) ;
if ( V_162 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_166 , V_11 -> V_173 -> V_6 . V_110 . V_111 ) ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_33 , V_174 ;
int V_129 , V_175 , V_8 ;
if ( ! V_2 -> V_4 )
return;
F_62 ( V_2 ) ;
F_63 ( 10 ) ;
V_175 = V_2 -> V_176 ;
V_2 -> V_176 = 0 ;
for ( V_129 = 0 ; V_129 < V_175 ; V_129 ++ ) {
if ( F_64 ( V_138 , & V_2 -> V_4 [ V_129 ] . V_134 ) )
F_40 ( & V_2 -> V_4 [ V_129 ] ) ;
F_39 ( & V_2 -> V_4 [ V_129 ] ) ;
}
F_65 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
if ( ! F_53 ( V_2 ) ) {
F_66 ( V_2 -> V_66 ) ;
for ( V_8 = 0 ; V_8 < V_175 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_174 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
F_4 ( V_6 , F_67 ( V_33 ) , ( 1 << V_174 ) ) ;
}
F_60 ( V_2 ) ;
} else {
F_68 ( & V_2 -> V_66 -> V_67 ,
L_15 ) ;
}
F_69 ( V_2 ) ;
}
int F_70 ( struct V_1 * V_2 , T_3 V_176 )
{
struct V_3 * V_177 ;
int V_129 , V_54 = 0 ;
F_62 ( V_2 ) ;
if ( F_71 ( V_2 -> V_66 ) != V_176 ) {
V_54 = F_72 ( V_2 -> V_66 , V_176 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_16 , V_54 ) ;
V_2 -> V_176 = 0 ;
goto V_178;
}
}
V_177 = F_73 ( V_176 , sizeof( struct V_3 ) , V_179 ) ;
if ( ! V_177 ) {
V_54 = - V_180 ;
goto V_181;
}
V_2 -> V_4 = V_177 ;
for ( V_129 = 0 ; V_129 < V_176 ; V_129 ++ ) {
V_177 [ V_129 ] . V_2 = V_2 ;
V_177 [ V_129 ] . V_182 = V_183 ;
V_177 [ V_129 ] . V_8 = V_129 ;
F_45 ( V_184 , & V_177 [ V_129 ] . V_137 ) ;
V_177 [ V_129 ] . V_185 = true ;
F_48 ( & V_177 [ V_129 ] , false ) ;
F_34 ( & V_177 [ V_129 ] ) ;
}
V_2 -> V_176 = V_176 ;
F_56 ( V_2 ) ;
V_181:
if ( V_54 )
F_61 ( V_2 ) ;
V_178:
F_69 ( V_2 ) ;
return V_54 ;
}
static int F_74 ( struct V_153 * V_66 , int V_186 )
{
#ifdef F_75
struct V_1 * V_2 = F_76 ( V_66 ) ;
int V_187 = F_71 ( V_66 ) ;
int V_188 = 0 ;
F_29 ( & V_66 -> V_67 , L_17 , V_186 ) ;
if ( V_187 && V_187 != V_186 )
F_61 ( V_2 ) ;
else if ( V_187 && V_187 == V_186 )
goto V_189;
if ( V_186 > V_2 -> V_190 ) {
V_188 = - V_191 ;
goto V_192;
}
V_188 = F_70 ( V_2 , V_186 ) ;
if ( V_188 ) {
F_68 ( & V_66 -> V_67 , L_18 , V_188 ) ;
goto V_192;
}
V_189:
return V_186 ;
V_192:
return V_188 ;
#endif
return 0 ;
}
int F_77 ( struct V_153 * V_66 , int V_186 )
{
struct V_1 * V_2 = F_76 ( V_66 ) ;
if ( V_186 )
return F_74 ( V_66 , V_186 ) ;
if ( ! F_53 ( V_2 ) ) {
F_61 ( V_2 ) ;
} else {
F_68 ( & V_66 -> V_67 , L_19 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_78 ( struct V_3 * V_4 , T_1 V_193 ,
T_1 V_194 , T_2 * V_195 , T_3 V_196 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_197 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
T_4 V_162 ;
if ( V_194 ) {
V_4 -> V_198 ++ ;
F_21 ( & V_2 -> V_66 -> V_67 , L_20 ,
V_193 , V_194 ) ;
if ( V_4 -> V_198 >
V_199 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_21 ,
V_4 -> V_8 ) ;
F_21 ( & V_2 -> V_66 -> V_67 , L_22 ) ;
F_45 ( V_200 , & V_4 -> V_134 ) ;
}
} else {
V_4 -> V_201 ++ ;
}
V_162 = F_79 ( V_6 , V_197 , V_193 , V_194 ,
V_195 , V_196 , NULL ) ;
if ( V_162 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_23 ,
V_4 -> V_8 , V_2 -> V_6 . V_110 . V_111 ) ;
return - V_145 ;
}
return 0 ;
}
static int F_80 ( struct V_3 * V_4 ,
enum V_202 V_203 ,
T_4 V_204 )
{
return F_78 ( V_4 , V_203 , V_204 , NULL , 0 ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_205 V_22 = {
V_206 , V_207
} ;
return F_78 ( V_4 , V_208 ,
V_209 , ( T_2 * ) & V_22 ,
sizeof( struct
V_205 ) ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_210 * V_211 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_162 = 0 ;
struct V_19 * V_11 ;
int V_129 = 0 , V_212 = 0 ;
int V_213 = 1 ;
int V_54 ;
if ( ! F_64 ( V_138 , & V_4 -> V_134 ) ) {
V_162 = V_214 ;
goto V_188;
}
V_212 = ( sizeof( struct V_210 ) +
sizeof( struct V_215 ) * V_213 ) ;
V_211 = F_83 ( V_212 , V_179 ) ;
if ( ! V_211 ) {
V_162 = V_216 ;
V_212 = 0 ;
goto V_188;
}
V_211 -> V_217 = V_218 ;
V_11 = V_2 -> V_11 [ V_4 -> V_116 ] ;
if ( ! V_11 -> V_22 . V_219 )
V_211 -> V_217 |= V_220 ;
V_211 -> V_213 = V_213 ;
V_211 -> V_13 = V_4 -> V_13 ;
V_211 -> V_221 = V_2 -> V_6 . V_15 . V_16 ;
if ( V_4 -> V_116 ) {
V_211 -> V_222 [ V_129 ] . V_10 = V_4 -> V_116 ;
V_211 -> V_222 [ V_129 ] . V_223 = V_113 ;
V_211 -> V_222 [ V_129 ] . V_13 =
V_2 -> V_11 [ V_4 -> V_116 ] -> V_13 ;
memcpy ( V_211 -> V_222 [ V_129 ] . V_224 ,
V_4 -> V_121 . V_122 , V_115 ) ;
V_129 ++ ;
}
F_45 ( V_148 , & V_4 -> V_134 ) ;
V_188:
V_54 = F_78 ( V_4 , V_225 ,
V_162 , ( T_2 * ) V_211 , V_212 ) ;
F_65 ( V_211 ) ;
return V_54 ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( F_64 ( V_148 , & V_4 -> V_134 ) )
F_48 ( V_4 , false ) ;
}
static int F_85 ( struct V_3 * V_4 ,
T_2 * V_195 , T_3 V_196 )
{
struct V_226 * V_22 =
(struct V_226 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_227 = false ;
bool V_228 = false ;
T_4 V_162 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ||
! F_64 ( V_136 , & V_4 -> V_137 ) ||
! F_6 ( V_4 , V_22 -> V_10 ) ||
( V_2 -> V_11 [ V_22 -> V_10 ] -> type != V_229 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( V_22 -> V_167 & V_230 )
V_228 = true ;
V_162 = F_86 ( V_6 , V_22 -> V_10 ,
V_228 , NULL ) ;
if ( V_162 )
goto V_88;
if ( V_22 -> V_167 & V_231 )
V_227 = true ;
V_162 = F_87 ( V_6 , V_22 -> V_10 ,
V_227 , NULL ) ;
V_88:
return F_80 ( V_4 ,
V_232 ,
V_162 ) ;
}
static int F_88 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_233 * V_234 =
(struct V_233 * ) V_195 ;
struct V_235 * V_236 ;
T_3 V_10 , V_18 ;
T_4 V_162 = 0 ;
int V_129 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ) {
V_162 = V_214 ;
goto V_88;
}
V_10 = V_234 -> V_10 ;
if ( ! F_6 ( V_4 , V_10 ) ) {
V_162 = V_214 ;
goto V_88;
}
for ( V_129 = 0 ; V_129 < V_234 -> V_13 ; V_129 ++ ) {
V_236 = & V_234 -> V_237 [ V_129 ] ;
V_18 = V_236 -> V_238 . V_239 ;
if ( ( V_236 -> V_238 . V_10 != V_10 ) ||
( V_236 -> V_240 . V_10 != V_10 ) ||
( V_236 -> V_240 . V_239 != V_18 ) ||
! F_7 ( V_4 , V_10 , V_18 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( F_24 ( V_4 , V_10 , V_18 ,
& V_236 -> V_240 ) ||
F_19 ( V_4 , V_10 , V_18 ,
& V_236 -> V_238 ) ) {
V_162 = V_214 ;
goto V_88;
}
}
V_88:
return F_80 ( V_4 , V_241 ,
V_162 ) ;
}
static int F_89 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_242 * V_243 =
(struct V_242 * ) V_195 ;
struct V_26 * V_244 ;
T_3 V_10 , V_18 , V_14 ;
T_4 V_162 = 0 ;
unsigned long V_29 ;
int V_129 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ) {
V_162 = V_214 ;
goto V_88;
}
for ( V_129 = 0 ; V_129 < V_243 -> V_245 ; V_129 ++ ) {
V_244 = & V_243 -> V_27 [ V_129 ] ;
V_14 = V_244 -> V_14 ;
V_10 = V_244 -> V_10 ;
if ( ! F_8 ( V_4 , V_14 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_162 = V_214 ;
goto V_88;
}
V_29 = V_244 -> V_35 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_162 = V_214 ;
goto V_88;
}
}
V_29 = V_244 -> V_36 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_162 = V_214 ;
goto V_88;
}
}
F_11 ( V_4 , V_10 , V_244 ) ;
}
V_88:
return F_80 ( V_4 , V_246 ,
V_162 ) ;
}
static int F_90 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_247 * V_248 =
(struct V_247 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_248 -> V_10 ;
T_4 V_162 = 0 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_10 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( ( 0 == V_248 -> V_249 ) && ( 0 == V_248 -> V_250 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( F_52 ( V_2 -> V_11 [ V_10 ] , true ) )
V_162 = V_251 ;
V_88:
return F_80 ( V_4 , V_252 ,
V_162 ) ;
}
static int F_91 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_247 * V_248 =
(struct V_247 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_248 -> V_10 ;
T_4 V_162 = 0 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_248 -> V_10 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( ( 0 == V_248 -> V_249 ) && ( 0 == V_248 -> V_250 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( F_52 ( V_2 -> V_11 [ V_10 ] , false ) )
V_162 = V_251 ;
V_88:
return F_80 ( V_4 , V_253 ,
V_162 ) ;
}
static int F_92 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_247 * V_248 =
(struct V_247 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_254 V_255 ;
T_4 V_162 = 0 ;
struct V_19 * V_11 ;
memset ( & V_255 , 0 , sizeof( struct V_254 ) ) ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ) {
V_162 = V_214 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_248 -> V_10 ) ) {
V_162 = V_214 ;
goto V_88;
}
V_11 = V_2 -> V_11 [ V_248 -> V_10 ] ;
if ( ! V_11 ) {
V_162 = V_214 ;
goto V_88;
}
F_93 ( V_11 ) ;
V_255 = V_11 -> V_256 ;
V_88:
return F_78 ( V_4 , V_257 , V_162 ,
( T_2 * ) & V_255 , sizeof( V_255 ) ) ;
}
static inline int F_94 ( struct V_3 * V_4 , T_2 * V_258 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_54 = 0 ;
if ( F_95 ( V_258 ) ||
F_96 ( V_258 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 , V_258 ) ;
V_54 = V_259 ;
} else if ( V_4 -> V_260 && ! F_97 ( V_258 ) &&
! F_98 ( V_258 , V_4 -> V_121 . V_122 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_25 ) ;
V_54 = - V_191 ;
}
return V_54 ;
}
static int F_99 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_261 * V_262 =
(struct V_261 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_262 -> V_10 ;
T_4 V_54 = 0 ;
int V_129 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ||
! F_64 ( V_136 , & V_4 -> V_137 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_214 ;
goto V_88;
}
for ( V_129 = 0 ; V_129 < V_262 -> V_263 ; V_129 ++ ) {
V_54 = F_94 ( V_4 , V_262 -> V_264 [ V_129 ] . V_122 ) ;
if ( V_54 )
goto V_88;
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_129 = 0 ; V_129 < V_262 -> V_263 ; V_129 ++ ) {
struct V_106 * V_107 ;
V_107 = F_100 ( V_11 , V_262 -> V_264 [ V_129 ] . V_122 , true , false ) ;
if ( ! V_107 ) {
if ( F_101 ( V_11 ) )
V_107 = F_102 ( V_11 , V_262 -> V_264 [ V_129 ] . V_122 ,
true , false ) ;
else
V_107 = F_31 ( V_11 , V_262 -> V_264 [ V_129 ] . V_122 , - 1 ,
true , false ) ;
}
if ( ! V_107 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_26 ) ;
V_54 = V_214 ;
goto V_88;
}
}
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_80 ( V_4 , V_265 ,
V_54 ) ;
}
static int F_103 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_261 * V_262 =
(struct V_261 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_262 -> V_10 ;
T_4 V_54 = 0 ;
int V_129 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ||
! F_64 ( V_136 , & V_4 -> V_137 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_214 ;
goto V_88;
}
for ( V_129 = 0 ; V_129 < V_262 -> V_263 ; V_129 ++ ) {
if ( F_95 ( V_262 -> V_264 [ V_129 ] . V_122 ) ||
F_96 ( V_262 -> V_264 [ V_129 ] . V_122 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 ,
V_262 -> V_264 [ V_129 ] . V_122 ) ;
V_54 = V_259 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_129 = 0 ; V_129 < V_262 -> V_263 ; V_129 ++ )
F_104 ( V_11 , V_262 -> V_264 [ V_129 ] . V_122 ,
V_266 , true , false ) ;
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_80 ( V_4 , V_267 ,
V_54 ) ;
}
static int F_105 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_269 -> V_10 ;
T_4 V_162 = 0 ;
int V_129 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ||
! F_64 ( V_136 , & V_4 -> V_137 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_162 = V_214 ;
goto V_88;
}
for ( V_129 = 0 ; V_129 < V_269 -> V_263 ; V_129 ++ ) {
if ( V_269 -> V_270 [ V_129 ] > V_271 ) {
V_162 = V_214 ;
F_21 ( & V_2 -> V_66 -> V_67 ,
L_28 , V_269 -> V_270 [ V_129 ] ) ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_219 ) {
V_162 = V_214 ;
goto V_88;
}
F_106 ( V_11 ) ;
for ( V_129 = 0 ; V_129 < V_269 -> V_263 ; V_129 ++ ) {
int V_54 = F_107 ( V_11 , V_269 -> V_270 [ V_129 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_29 ,
V_269 -> V_270 [ V_129 ] , V_54 ) ;
}
V_88:
return F_80 ( V_4 , V_272 , V_162 ) ;
}
static int F_108 ( struct V_3 * V_4 , T_2 * V_195 , T_3 V_196 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_195 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_269 -> V_10 ;
T_4 V_162 = 0 ;
int V_129 ;
if ( ! F_64 ( V_148 , & V_4 -> V_134 ) ||
! F_64 ( V_136 , & V_4 -> V_137 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_162 = V_214 ;
goto V_88;
}
for ( V_129 = 0 ; V_129 < V_269 -> V_263 ; V_129 ++ ) {
if ( V_269 -> V_270 [ V_129 ] > V_271 ) {
V_162 = V_214 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_219 ) {
V_162 = V_214 ;
goto V_88;
}
for ( V_129 = 0 ; V_129 < V_269 -> V_263 ; V_129 ++ ) {
int V_54 = F_109 ( V_11 , V_269 -> V_270 [ V_129 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_30 ,
V_269 -> V_270 [ V_129 ] , V_54 ) ;
}
V_88:
return F_80 ( V_4 , V_273 , V_162 ) ;
}
static int F_110 ( struct V_3 * V_4 , T_1 V_193 ,
T_1 V_194 , T_2 * V_195 , T_3 V_196 )
{
bool V_274 = false ;
int V_275 ;
if ( F_64 ( V_200 , & V_4 -> V_134 ) )
return V_214 ;
switch ( V_193 ) {
case V_208 :
V_275 = sizeof( struct V_205 ) ;
break;
case V_276 :
case V_225 :
V_275 = 0 ;
break;
case V_277 :
V_275 = sizeof( struct V_50 ) ;
break;
case V_278 :
V_275 = sizeof( struct V_77 ) ;
break;
case V_241 :
V_275 = sizeof( struct V_233 ) ;
if ( V_196 >= V_275 ) {
struct V_233 * V_279 =
(struct V_233 * ) V_195 ;
V_275 += ( V_279 -> V_13 *
sizeof( struct
V_235 ) ) ;
if ( V_279 -> V_13 == 0 )
V_274 = true ;
}
break;
case V_246 :
V_275 = sizeof( struct V_242 ) ;
if ( V_196 >= V_275 ) {
struct V_242 * V_280 =
(struct V_242 * ) V_195 ;
V_275 += ( V_280 -> V_245 *
sizeof( struct V_26 ) ) ;
if ( V_280 -> V_245 == 0 )
V_274 = true ;
}
break;
case V_252 :
case V_253 :
V_275 = sizeof( struct V_247 ) ;
break;
case V_265 :
case V_267 :
V_275 = sizeof( struct V_261 ) ;
if ( V_196 >= V_275 ) {
struct V_261 * V_281 =
(struct V_261 * ) V_195 ;
V_275 += V_281 -> V_263 *
sizeof( struct V_282 ) ;
if ( V_281 -> V_263 == 0 )
V_274 = true ;
}
break;
case V_272 :
case V_273 :
V_275 = sizeof( struct V_268 ) ;
if ( V_196 >= V_275 ) {
struct V_268 * V_269 =
(struct V_268 * ) V_195 ;
V_275 += V_269 -> V_263 * sizeof( T_3 ) ;
if ( V_269 -> V_263 == 0 )
V_274 = true ;
}
break;
case V_232 :
V_275 = sizeof( struct V_226 ) ;
break;
case V_257 :
V_275 = sizeof( struct V_247 ) ;
break;
case V_283 :
case V_284 :
default:
return - V_191 ;
break;
}
if ( ( V_275 != V_196 ) || ( V_274 ) ) {
F_80 ( V_4 , V_193 , V_214 ) ;
return - V_87 ;
} else {
return 0 ;
}
}
int F_111 ( struct V_1 * V_2 , T_3 V_8 , T_1 V_193 ,
T_1 V_194 , T_2 * V_195 , T_3 V_196 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned int V_285 = V_8 - V_6 -> V_15 . V_74 ;
struct V_3 * V_4 ;
int V_54 ;
V_2 -> V_286 ++ ;
if ( V_285 >= V_2 -> V_176 )
return - V_87 ;
V_4 = & ( V_2 -> V_4 [ V_285 ] ) ;
V_54 = F_110 ( V_4 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_31 ,
V_285 , V_193 , V_196 ) ;
return V_54 ;
}
switch ( V_193 ) {
case V_208 :
V_54 = F_81 ( V_4 ) ;
break;
case V_225 :
V_54 = F_82 ( V_4 ) ;
break;
case V_276 :
F_84 ( V_4 ) ;
V_54 = 0 ;
break;
case V_232 :
V_54 = F_85 ( V_4 , V_195 , V_196 ) ;
break;
case V_241 :
V_54 = F_88 ( V_4 , V_195 , V_196 ) ;
break;
case V_246 :
V_54 = F_89 ( V_4 , V_195 , V_196 ) ;
break;
case V_252 :
V_54 = F_90 ( V_4 , V_195 , V_196 ) ;
break;
case V_253 :
V_54 = F_91 ( V_4 , V_195 , V_196 ) ;
break;
case V_265 :
V_54 = F_99 ( V_4 , V_195 , V_196 ) ;
break;
case V_267 :
V_54 = F_103 ( V_4 , V_195 , V_196 ) ;
break;
case V_272 :
V_54 = F_105 ( V_4 , V_195 , V_196 ) ;
break;
case V_273 :
V_54 = F_108 ( V_4 , V_195 , V_196 ) ;
break;
case V_257 :
V_54 = F_92 ( V_4 , V_195 , V_196 ) ;
break;
case V_284 :
default:
F_21 ( & V_2 -> V_66 -> V_67 , L_32 ,
V_193 , V_285 ) ;
V_54 = F_80 ( V_4 , V_193 ,
V_287 ) ;
break;
}
return V_54 ;
}
int F_112 ( struct V_1 * V_2 )
{
T_1 V_7 , V_33 , V_174 , V_8 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
if ( ! F_64 ( V_288 , & V_2 -> V_289 ) )
return 0 ;
F_49 ( V_288 , & V_2 -> V_289 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_176 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_174 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_7 = F_2 ( V_6 , F_67 ( V_33 ) ) ;
if ( V_7 & ( 1 << V_174 ) ) {
F_4 ( V_6 , F_67 ( V_33 ) , ( 1 << V_174 ) ) ;
if ( ! F_64 ( V_290 , & V_2 -> V_289 ) )
F_48 ( V_4 , true ) ;
}
}
V_7 = F_2 ( V_6 , V_291 ) ;
V_7 |= V_292 ;
F_4 ( V_6 , V_291 , V_7 ) ;
F_5 ( V_6 ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 ,
enum V_202 V_193 ,
T_4 V_194 , T_2 * V_195 ,
T_3 V_196 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_176 ; V_129 ++ ) {
F_79 ( V_6 , V_4 -> V_8 , V_193 , V_194 ,
V_195 , V_196 , NULL ) ;
V_4 ++ ;
}
}
void F_114 ( struct V_1 * V_2 )
{
struct V_293 V_294 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_295 * V_296 = & V_2 -> V_6 . V_297 . V_298 ;
int V_129 ;
V_294 . V_299 = V_300 ;
V_294 . V_301 = V_302 ;
for ( V_129 = 0 ; V_129 < V_2 -> V_176 ; V_129 ++ ) {
if ( V_4 -> V_303 ) {
V_294 . V_304 . V_305 . V_306 = V_4 -> V_307 ;
V_294 . V_304 . V_305 . V_308 =
( V_4 -> V_307 ? V_309 : 0 ) ;
} else {
V_294 . V_304 . V_305 . V_306 =
V_296 -> V_298 & V_310 ;
V_294 . V_304 . V_305 . V_308 = V_296 -> V_308 ;
}
F_79 ( V_6 , V_4 -> V_8 , V_283 ,
0 , ( T_2 * ) & V_294 , sizeof( V_294 ) ,
NULL ) ;
V_4 ++ ;
}
}
void F_115 ( struct V_1 * V_2 )
{
struct V_293 V_294 ;
V_294 . V_299 = V_311 ;
V_294 . V_301 = V_312 ;
F_113 ( V_2 , V_283 , V_209 ,
( T_2 * ) & V_294 , sizeof( struct V_293 ) ) ;
}
void F_116 ( struct V_3 * V_4 )
{
struct V_293 V_294 ;
V_294 . V_299 = V_311 ;
V_294 . V_301 = V_312 ;
F_79 ( & V_4 -> V_2 -> V_6 , V_4 -> V_8 , V_283 ,
V_209 , ( T_2 * ) & V_294 ,
sizeof( struct V_293 ) , NULL ) ;
}
int F_117 ( struct V_313 * V_314 , int V_8 , T_2 * V_315 )
{
struct V_316 * V_317 = F_118 ( V_314 ) ;
struct V_19 * V_11 = V_317 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_173 ;
struct V_106 * V_107 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_176 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_116 ] ;
if ( ! F_64 ( V_138 , & V_4 -> V_134 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
if ( ! F_119 ( V_315 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_35 ) ;
V_54 = - V_87 ;
goto V_88;
}
F_104 ( V_11 , V_4 -> V_121 . V_122 , V_4 -> V_120 ,
true , false ) ;
F_120 (f, &vsi->mac_filter_list, list)
F_104 ( V_11 , V_107 -> V_258 , V_107 -> V_318 , true , false ) ;
F_29 ( & V_2 -> V_66 -> V_67 , L_36 , V_315 , V_8 ) ;
if ( F_32 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_9 ) ;
V_54 = - V_145 ;
goto V_88;
}
F_121 ( V_4 -> V_121 . V_122 , V_315 ) ;
V_4 -> V_260 = true ;
F_29 ( & V_2 -> V_66 -> V_67 , L_37 ) ;
V_54 = 0 ;
V_88:
return V_54 ;
}
int F_122 ( struct V_313 * V_314 ,
int V_8 , T_3 V_270 , T_2 V_319 )
{
struct V_316 * V_317 = F_118 ( V_314 ) ;
struct V_1 * V_2 = V_317 -> V_11 -> V_173 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_176 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_320;
}
if ( ( V_270 > V_271 ) || ( V_319 > 7 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_38 ) ;
V_54 = - V_87 ;
goto V_320;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_116 ] ;
if ( ! F_64 ( V_138 , & V_4 -> V_134 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_320;
}
if ( V_11 -> V_22 . V_219 == 0 && F_101 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_39 ,
V_8 ) ;
F_1 ( V_2 , V_4 ) ;
}
if ( ( ! ( V_270 || V_319 ) ||
( V_270 | V_319 ) != F_10 ( V_11 -> V_22 . V_219 ) ) &&
V_11 -> V_22 . V_219 )
V_54 = F_107 ( V_11 , V_266 ) ;
if ( V_11 -> V_22 . V_219 ) {
V_54 = F_109 ( V_11 , ( F_10 ( V_11 -> V_22 . V_219 ) &
V_321 ) ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_173 -> V_66 -> V_67 ,
L_40 ,
V_54 , V_2 -> V_6 . V_110 . V_111 ) ;
}
}
if ( V_270 || V_319 )
V_54 = F_30 ( V_11 ,
V_270 | ( V_319 << V_322 ) ) ;
else
F_123 ( V_11 ) ;
if ( V_270 ) {
F_29 ( & V_2 -> V_66 -> V_67 , L_41 ,
V_270 , V_319 , V_8 ) ;
V_54 = F_107 ( V_11 , V_270 ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_173 -> V_66 -> V_67 ,
L_42 , V_54 ,
V_11 -> V_173 -> V_6 . V_110 . V_111 ) ;
goto V_320;
}
F_109 ( V_11 , V_266 ) ;
}
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_43 ) ;
goto V_320;
}
V_4 -> V_120 = F_10 ( V_11 -> V_22 . V_219 ) ;
V_54 = 0 ;
V_320:
return V_54 ;
}
int F_124 ( struct V_313 * V_314 , int V_8 , int V_323 ,
int V_324 )
{
struct V_316 * V_317 = F_118 ( V_314 ) ;
struct V_1 * V_2 = V_317 -> V_11 -> V_173 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_325 = 0 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_176 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_44 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( V_323 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_45 ,
V_323 , V_8 ) ;
return - V_87 ;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_116 ] ;
if ( ! F_64 ( V_138 , & V_4 -> V_134 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_46 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
switch ( V_2 -> V_6 . V_297 . V_298 . V_308 ) {
case V_309 :
V_325 = 40000 ;
break;
case V_326 :
V_325 = 10000 ;
break;
case V_327 :
V_325 = 1000 ;
break;
default:
break;
}
if ( V_324 > V_325 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_47 ,
V_324 , V_4 -> V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( ( V_324 < 50 ) && ( V_324 > 0 ) ) {
F_68 ( & V_2 -> V_66 -> V_67 , L_48 ) ;
V_324 = 50 ;
}
V_54 = F_33 ( & V_2 -> V_6 , V_11 -> V_109 ,
V_324 / V_328 ,
V_329 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_49 ,
V_54 ) ;
V_54 = - V_145 ;
goto error;
}
V_4 -> V_123 = V_324 ;
error:
return V_54 ;
}
int F_125 ( struct V_313 * V_314 ,
int V_8 , struct V_330 * V_331 )
{
struct V_316 * V_317 = F_118 ( V_314 ) ;
struct V_19 * V_11 = V_317 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_173 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_176 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_116 ] ;
if ( ! F_64 ( V_138 , & V_4 -> V_134 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_331 -> V_4 = V_8 ;
memcpy ( & V_331 -> V_315 , V_4 -> V_121 . V_122 , V_115 ) ;
V_331 -> V_324 = V_4 -> V_123 ;
V_331 -> V_323 = 0 ;
V_331 -> V_318 = F_10 ( V_11 -> V_22 . V_219 ) & V_332 ;
V_331 -> V_319 = ( F_10 ( V_11 -> V_22 . V_219 ) & V_333 ) >>
V_322 ;
if ( V_4 -> V_303 == false )
V_331 -> V_334 = V_335 ;
else if ( V_4 -> V_307 == true )
V_331 -> V_334 = V_336 ;
else
V_331 -> V_334 = V_337 ;
V_331 -> V_185 = V_4 -> V_185 ;
V_54 = 0 ;
V_88:
return V_54 ;
}
int F_126 ( struct V_313 * V_314 , int V_8 , int V_338 )
{
struct V_316 * V_317 = F_118 ( V_314 ) ;
struct V_1 * V_2 = V_317 -> V_11 -> V_173 ;
struct V_293 V_294 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_176 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_339;
}
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_294 . V_299 = V_300 ;
V_294 . V_301 = V_302 ;
switch ( V_338 ) {
case V_335 :
V_4 -> V_303 = false ;
V_294 . V_304 . V_305 . V_306 =
V_2 -> V_6 . V_297 . V_298 . V_298 & V_310 ;
V_294 . V_304 . V_305 . V_308 =
V_2 -> V_6 . V_297 . V_298 . V_308 ;
break;
case V_336 :
V_4 -> V_303 = true ;
V_4 -> V_307 = true ;
V_294 . V_304 . V_305 . V_306 = true ;
V_294 . V_304 . V_305 . V_308 = V_309 ;
break;
case V_337 :
V_4 -> V_303 = true ;
V_4 -> V_307 = false ;
V_294 . V_304 . V_305 . V_306 = false ;
V_294 . V_304 . V_305 . V_308 = 0 ;
break;
default:
V_54 = - V_87 ;
goto V_339;
}
F_79 ( V_6 , V_4 -> V_8 , V_283 ,
0 , ( T_2 * ) & V_294 , sizeof( V_294 ) , NULL ) ;
V_339:
return V_54 ;
}
int F_127 ( struct V_313 * V_314 , int V_8 , bool V_340 )
{
struct V_316 * V_317 = F_118 ( V_314 ) ;
struct V_19 * V_11 = V_317 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_173 ;
struct V_160 V_161 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_176 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_189;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
if ( V_340 == V_4 -> V_185 )
goto V_189;
V_4 -> V_185 = V_340 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_109 = V_2 -> V_11 [ V_4 -> V_116 ] -> V_109 ;
V_161 . V_164 = V_2 -> V_6 . V_71 ;
V_161 . V_22 . V_169 = F_58 ( V_341 ) ;
if ( V_340 )
V_161 . V_22 . V_342 |= V_343 ;
V_54 = F_59 ( V_6 , & V_161 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_50 ,
V_54 ) ;
V_54 = - V_145 ;
}
V_189:
return V_54 ;
}
