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
V_79 . V_98 = 2 ;
V_79 . V_99 = 1 ;
V_79 . V_100 = 1 ;
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
static int F_27 ( struct V_3 * V_4 , enum V_101 type )
{
struct V_102 * V_103 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 ;
int V_54 = 0 ;
V_11 = F_28 ( V_2 , type , V_2 -> V_11 [ V_2 -> V_104 ] -> V_105 , V_4 -> V_8 ) ;
if ( ! V_11 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_5 ,
V_4 -> V_8 , V_2 -> V_6 . V_106 . V_107 ) ;
V_54 = - V_68 ;
goto V_108;
}
if ( type == V_109 ) {
T_2 V_110 [ V_111 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_112 = V_11 -> V_113 ;
V_4 -> V_114 = V_11 -> V_115 ;
F_29 ( & V_2 -> V_66 -> V_67 ,
L_6 ,
V_4 -> V_8 , V_11 -> V_113 , V_11 -> V_115 ) ;
if ( V_4 -> V_116 )
F_30 ( V_11 , V_4 -> V_116 ) ;
V_103 = F_31 ( V_11 , V_4 -> V_117 . V_118 ,
V_4 -> V_116 , true , false ) ;
if ( ! V_103 )
F_29 ( & V_2 -> V_66 -> V_67 ,
L_7 ) ;
V_103 = F_31 ( V_11 , V_110 , V_4 -> V_116 ,
true , false ) ;
if ( ! V_103 )
F_29 ( & V_2 -> V_66 -> V_67 ,
L_8 ) ;
}
V_54 = F_32 ( V_11 ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 , L_9 ) ;
if ( V_4 -> V_119 ) {
V_54 = F_33 ( & V_2 -> V_6 , V_11 -> V_105 ,
V_4 -> V_119 / 50 , 0 , NULL ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 , L_10 ,
V_4 -> V_8 , V_54 ) ;
}
V_108:
return V_54 ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_120 = 0 ;
int V_121 ;
F_4 ( V_6 , F_35 ( V_4 -> V_114 ) ,
V_122 ) ;
V_7 = V_123 ;
F_4 ( V_6 , F_36 ( V_4 -> V_8 ) , V_7 ) ;
for ( V_121 = 0 ; V_121 < V_2 -> V_11 [ V_4 -> V_112 ] -> V_13 ; V_121 ++ ) {
T_3 V_12 = F_9 ( V_4 , V_4 -> V_112 , V_121 ) ;
V_7 = ( V_12 & V_124 ) ;
F_4 ( V_6 , F_37 ( V_120 , V_4 -> V_8 ) , V_7 ) ;
V_120 ++ ;
}
for ( V_121 = 0 ; V_121 < 7 ; V_121 ++ ) {
if ( V_121 * 2 >= V_2 -> V_11 [ V_4 -> V_112 ] -> V_13 ) {
V_7 = 0x07FF07FF ;
} else {
T_3 V_12 = F_9 ( V_4 , V_4 -> V_112 ,
V_121 * 2 ) ;
V_7 = V_12 ;
V_12 = F_9 ( V_4 , V_4 -> V_112 ,
( V_121 * 2 ) + 1 ) ;
V_7 |= V_12 << 16 ;
}
F_4 ( V_6 , F_38 ( V_121 , V_4 -> V_114 ) , V_7 ) ;
}
F_5 ( V_6 ) ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_125 ;
F_4 ( V_6 , F_36 ( V_4 -> V_8 ) , 0 ) ;
for ( V_125 = 0 ; V_125 < V_40 ; V_125 ++ )
F_4 ( V_6 , F_37 ( V_125 , V_4 -> V_8 ) ,
V_21 ) ;
F_5 ( V_6 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_33 , V_7 ;
int V_125 , V_126 ;
if ( V_4 -> V_112 ) {
F_41 ( V_2 -> V_11 [ V_4 -> V_112 ] ) ;
V_4 -> V_112 = 0 ;
V_4 -> V_114 = 0 ;
}
V_126 = V_2 -> V_6 . V_15 . V_16 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
if ( 0 == V_125 )
V_33 = F_42 ( V_4 -> V_8 ) ;
else
V_33 = F_43 ( ( ( V_126 - 1 ) *
( V_4 -> V_8 ) )
+ ( V_125 - 1 ) ) ;
F_4 ( V_6 , V_33 , V_127 ) ;
F_5 ( V_6 ) ;
}
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
if ( 0 == V_125 )
V_33 = F_12 ( V_4 -> V_8 ) ;
else
V_33 = F_13 ( ( ( V_126 - 1 ) *
( V_4 -> V_8 ) )
+ ( V_125 - 1 ) ) ;
V_7 = ( V_128 |
V_129 ) ;
F_4 ( V_6 , V_33 , V_7 ) ;
F_5 ( V_6 ) ;
}
V_4 -> V_13 = 0 ;
V_4 -> V_130 = 0 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_120 = 0 ;
int V_54 ;
V_54 = F_27 ( V_4 , V_109 ) ;
if ( V_54 )
goto V_131;
V_120 += V_2 -> V_11 [ V_4 -> V_112 ] -> V_13 ;
F_45 ( V_132 , & V_4 -> V_133 ) ;
V_4 -> V_13 = V_120 ;
F_45 ( V_134 , & V_4 -> V_130 ) ;
V_131:
if ( V_54 )
F_40 ( V_4 ) ;
return V_54 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_135 , V_125 ;
T_1 V_7 ;
V_135 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
F_4 ( V_6 , V_136 ,
V_137 | ( V_135 << V_138 ) ) ;
for ( V_125 = 0 ; V_125 < 100 ; V_125 ++ ) {
V_7 = F_2 ( V_6 , V_139 ) ;
if ( ( V_7 & V_140 ) == 0 )
return 0 ;
F_47 ( 1 ) ;
}
return - V_141 ;
}
void F_48 ( struct V_3 * V_4 , bool V_142 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_143 = false ;
int V_125 ;
T_1 V_7 ;
F_49 ( V_144 , & V_4 -> V_130 ) ;
if ( ! V_142 ) {
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 |= V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
F_5 ( V_6 ) ;
}
if ( F_46 ( V_4 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_11 ,
V_4 -> V_8 ) ;
for ( V_125 = 0 ; V_125 < 100 ; V_125 ++ ) {
F_47 ( 10 ) ;
V_7 = F_2 ( V_6 , F_50 ( V_4 -> V_8 ) ) ;
if ( V_7 & V_145 ) {
V_143 = true ;
break;
}
}
if ( ! V_143 )
F_21 ( & V_2 -> V_66 -> V_67 , L_12 ,
V_4 -> V_8 ) ;
F_4 ( V_6 , F_51 ( V_4 -> V_8 ) , V_146 ) ;
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 &= ~ V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
if ( V_4 -> V_112 == 0 )
goto V_147;
F_52 ( V_2 -> V_11 [ V_4 -> V_112 ] , false ) ;
V_147:
F_40 ( V_4 ) ;
F_44 ( V_4 ) ;
F_34 ( V_4 ) ;
F_45 ( V_144 , & V_4 -> V_130 ) ;
F_4 ( V_6 , F_51 ( V_4 -> V_8 ) , V_148 ) ;
F_5 ( V_6 ) ;
}
static bool F_53 ( struct V_1 * V_2 )
{
struct V_149 * V_66 = V_2 -> V_66 ;
struct V_149 * V_150 ;
V_150 = F_54 ( V_151 , V_152 , NULL ) ;
while ( V_150 ) {
if ( V_150 -> V_153 && F_55 ( V_150 ) == V_66 ) {
if ( V_150 -> V_154 & V_155 )
return true ;
}
V_150 = F_54 ( V_151 ,
V_152 ,
V_150 ) ;
}
return false ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_104 ] ;
struct V_156 V_157 ;
int V_158 ;
V_157 . V_105 = V_2 -> V_159 ;
V_157 . V_160 = V_2 -> V_6 . V_71 ;
V_157 . V_161 = 0 ;
V_158 = F_57 ( & V_2 -> V_6 , & V_157 , NULL ) ;
if ( V_158 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_162 , V_158 , V_2 -> V_6 . V_106 . V_107 ) ;
return;
}
V_157 . V_163 = V_164 ;
V_157 . V_22 . V_165 = F_58 ( V_166 ) ;
V_157 . V_22 . V_167 |= F_58 ( V_168 ) ;
V_158 = F_59 ( & V_11 -> V_169 -> V_6 , & V_157 , NULL ) ;
if ( V_158 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_162 , V_11 -> V_169 -> V_6 . V_106 . V_107 ) ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_104 ] ;
struct V_156 V_157 ;
int V_158 ;
V_157 . V_105 = V_2 -> V_159 ;
V_157 . V_160 = V_2 -> V_6 . V_71 ;
V_157 . V_161 = 0 ;
V_158 = F_57 ( & V_2 -> V_6 , & V_157 , NULL ) ;
if ( V_158 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_162 , V_158 , V_2 -> V_6 . V_106 . V_107 ) ;
return;
}
V_157 . V_163 = V_164 ;
V_157 . V_22 . V_165 = F_58 ( V_166 ) ;
V_157 . V_22 . V_167 &= ~ F_58 ( V_168 ) ;
V_158 = F_59 ( & V_11 -> V_169 -> V_6 , & V_157 , NULL ) ;
if ( V_158 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_162 , V_11 -> V_169 -> V_6 . V_106 . V_107 ) ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_33 , V_170 ;
int V_125 , V_171 , V_8 ;
if ( ! V_2 -> V_4 )
return;
F_62 ( V_2 ) ;
F_63 ( 10 ) ;
V_171 = V_2 -> V_172 ;
V_2 -> V_172 = 0 ;
for ( V_125 = 0 ; V_125 < V_171 ; V_125 ++ ) {
if ( F_64 ( V_134 , & V_2 -> V_4 [ V_125 ] . V_130 ) )
F_40 ( & V_2 -> V_4 [ V_125 ] ) ;
F_39 ( & V_2 -> V_4 [ V_125 ] ) ;
}
F_65 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
if ( ! F_53 ( V_2 ) ) {
F_66 ( V_2 -> V_66 ) ;
for ( V_8 = 0 ; V_8 < V_171 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_170 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
F_4 ( V_6 , F_67 ( V_33 ) , ( 1 << V_170 ) ) ;
}
F_60 ( V_2 ) ;
} else {
F_68 ( & V_2 -> V_66 -> V_67 ,
L_15 ) ;
}
F_69 ( V_2 ) ;
}
int F_70 ( struct V_1 * V_2 , T_3 V_172 )
{
struct V_3 * V_173 ;
int V_125 , V_54 = 0 ;
F_62 ( V_2 ) ;
if ( F_71 ( V_2 -> V_66 ) != V_172 ) {
V_54 = F_72 ( V_2 -> V_66 , V_172 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_16 , V_54 ) ;
V_2 -> V_172 = 0 ;
goto V_174;
}
}
V_173 = F_73 ( V_172 , sizeof( struct V_3 ) , V_175 ) ;
if ( ! V_173 ) {
V_54 = - V_176 ;
goto V_177;
}
V_2 -> V_4 = V_173 ;
for ( V_125 = 0 ; V_125 < V_172 ; V_125 ++ ) {
V_173 [ V_125 ] . V_2 = V_2 ;
V_173 [ V_125 ] . V_178 = V_179 ;
V_173 [ V_125 ] . V_8 = V_125 ;
F_45 ( V_180 , & V_173 [ V_125 ] . V_133 ) ;
V_173 [ V_125 ] . V_181 = true ;
F_48 ( & V_173 [ V_125 ] , false ) ;
F_34 ( & V_173 [ V_125 ] ) ;
}
V_2 -> V_172 = V_172 ;
F_56 ( V_2 ) ;
V_177:
if ( V_54 )
F_61 ( V_2 ) ;
V_174:
F_69 ( V_2 ) ;
return V_54 ;
}
static int F_74 ( struct V_149 * V_66 , int V_182 )
{
#ifdef F_75
struct V_1 * V_2 = F_76 ( V_66 ) ;
int V_183 = F_71 ( V_66 ) ;
int V_184 = 0 ;
F_29 ( & V_66 -> V_67 , L_17 , V_182 ) ;
if ( V_183 && V_183 != V_182 )
F_61 ( V_2 ) ;
else if ( V_183 && V_183 == V_182 )
goto V_185;
if ( V_182 > V_2 -> V_186 ) {
V_184 = - V_187 ;
goto V_188;
}
V_184 = F_70 ( V_2 , V_182 ) ;
if ( V_184 ) {
F_68 ( & V_66 -> V_67 , L_18 , V_184 ) ;
goto V_188;
}
V_185:
return V_182 ;
V_188:
return V_184 ;
#endif
return 0 ;
}
int F_77 ( struct V_149 * V_66 , int V_182 )
{
struct V_1 * V_2 = F_76 ( V_66 ) ;
if ( V_182 )
return F_74 ( V_66 , V_182 ) ;
if ( ! F_53 ( V_2 ) ) {
F_61 ( V_2 ) ;
} else {
F_68 ( & V_66 -> V_67 , L_19 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_78 ( struct V_3 * V_4 , T_1 V_189 ,
T_1 V_190 , T_2 * V_191 , T_3 V_192 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_193 ;
T_4 V_158 ;
if ( ! V_4 || V_4 -> V_8 >= V_4 -> V_2 -> V_172 )
return - V_87 ;
V_2 = V_4 -> V_2 ;
V_6 = & V_2 -> V_6 ;
V_193 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( V_190 ) {
V_4 -> V_194 ++ ;
F_21 ( & V_2 -> V_66 -> V_67 , L_20 ,
V_189 , V_190 ) ;
if ( V_4 -> V_194 >
V_195 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_21 ,
V_4 -> V_8 ) ;
F_21 ( & V_2 -> V_66 -> V_67 , L_22 ) ;
F_45 ( V_196 , & V_4 -> V_130 ) ;
}
} else {
V_4 -> V_197 ++ ;
}
V_158 = F_79 ( V_6 , V_193 , V_189 , V_190 ,
V_191 , V_192 , NULL ) ;
if ( V_158 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_23 ,
V_4 -> V_8 , V_2 -> V_6 . V_106 . V_107 ) ;
return - V_141 ;
}
return 0 ;
}
static int F_80 ( struct V_3 * V_4 ,
enum V_198 V_199 ,
T_4 V_200 )
{
return F_78 ( V_4 , V_199 , V_200 , NULL , 0 ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_201 V_22 = {
V_202 , V_203
} ;
return F_78 ( V_4 , V_204 ,
V_205 , ( T_2 * ) & V_22 ,
sizeof( struct
V_201 ) ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_206 * V_207 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_158 = 0 ;
struct V_19 * V_11 ;
int V_125 = 0 , V_208 = 0 ;
int V_209 = 1 ;
int V_54 ;
if ( ! F_64 ( V_134 , & V_4 -> V_130 ) ) {
V_158 = V_210 ;
goto V_184;
}
V_208 = ( sizeof( struct V_206 ) +
sizeof( struct V_211 ) * V_209 ) ;
V_207 = F_83 ( V_208 , V_175 ) ;
if ( ! V_207 ) {
V_158 = V_212 ;
V_208 = 0 ;
goto V_184;
}
V_207 -> V_213 = V_214 ;
V_11 = V_2 -> V_11 [ V_4 -> V_112 ] ;
if ( ! V_11 -> V_22 . V_215 )
V_207 -> V_213 |= V_216 ;
V_207 -> V_209 = V_209 ;
V_207 -> V_13 = V_4 -> V_13 ;
V_207 -> V_217 = V_2 -> V_6 . V_15 . V_16 ;
if ( V_4 -> V_112 ) {
V_207 -> V_218 [ V_125 ] . V_10 = V_4 -> V_112 ;
V_207 -> V_218 [ V_125 ] . V_219 = V_109 ;
V_207 -> V_218 [ V_125 ] . V_13 =
V_2 -> V_11 [ V_4 -> V_112 ] -> V_13 ;
memcpy ( V_207 -> V_218 [ V_125 ] . V_220 ,
V_4 -> V_117 . V_118 , V_111 ) ;
V_125 ++ ;
}
F_45 ( V_144 , & V_4 -> V_130 ) ;
V_184:
V_54 = F_78 ( V_4 , V_221 ,
V_158 , ( T_2 * ) V_207 , V_208 ) ;
F_65 ( V_207 ) ;
return V_54 ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( F_64 ( V_144 , & V_4 -> V_130 ) )
F_48 ( V_4 , false ) ;
}
static int F_85 ( struct V_3 * V_4 ,
T_2 * V_191 , T_3 V_192 )
{
struct V_222 * V_22 =
(struct V_222 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_19 * V_11 ;
bool V_223 = false ;
T_4 V_158 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ||
! F_64 ( V_132 , & V_4 -> V_133 ) ||
! F_6 ( V_4 , V_22 -> V_10 ) ||
( V_2 -> V_11 [ V_22 -> V_10 ] -> type != V_224 ) ) {
V_158 = V_210 ;
goto V_88;
}
V_11 = V_2 -> V_11 [ V_22 -> V_10 ] ;
if ( V_22 -> V_163 & V_225 )
V_223 = true ;
V_158 = F_86 ( V_6 , V_11 -> V_105 ,
V_223 , NULL ) ;
V_88:
return F_80 ( V_4 ,
V_226 ,
V_158 ) ;
}
static int F_87 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_227 * V_228 =
(struct V_227 * ) V_191 ;
struct V_229 * V_230 ;
T_3 V_10 , V_18 ;
T_4 V_158 = 0 ;
int V_125 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ) {
V_158 = V_210 ;
goto V_88;
}
V_10 = V_228 -> V_10 ;
if ( ! F_6 ( V_4 , V_10 ) ) {
V_158 = V_210 ;
goto V_88;
}
for ( V_125 = 0 ; V_125 < V_228 -> V_13 ; V_125 ++ ) {
V_230 = & V_228 -> V_231 [ V_125 ] ;
V_18 = V_230 -> V_232 . V_233 ;
if ( ( V_230 -> V_232 . V_10 != V_10 ) ||
( V_230 -> V_234 . V_10 != V_10 ) ||
( V_230 -> V_234 . V_233 != V_18 ) ||
! F_7 ( V_4 , V_10 , V_18 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( F_24 ( V_4 , V_10 , V_18 ,
& V_230 -> V_234 ) ||
F_19 ( V_4 , V_10 , V_18 ,
& V_230 -> V_232 ) ) {
V_158 = V_210 ;
goto V_88;
}
}
V_88:
return F_80 ( V_4 , V_235 ,
V_158 ) ;
}
static int F_88 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_236 * V_237 =
(struct V_236 * ) V_191 ;
struct V_26 * V_238 ;
T_3 V_10 , V_18 , V_14 ;
T_4 V_158 = 0 ;
unsigned long V_29 ;
int V_125 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ) {
V_158 = V_210 ;
goto V_88;
}
for ( V_125 = 0 ; V_125 < V_237 -> V_239 ; V_125 ++ ) {
V_238 = & V_237 -> V_27 [ V_125 ] ;
V_14 = V_238 -> V_14 ;
V_10 = V_238 -> V_10 ;
if ( ! F_8 ( V_4 , V_14 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_158 = V_210 ;
goto V_88;
}
V_29 = V_238 -> V_35 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_158 = V_210 ;
goto V_88;
}
}
V_29 = V_238 -> V_36 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_158 = V_210 ;
goto V_88;
}
}
F_11 ( V_4 , V_10 , V_238 ) ;
}
V_88:
return F_80 ( V_4 , V_240 ,
V_158 ) ;
}
static int F_89 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_241 * V_242 =
(struct V_241 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_242 -> V_10 ;
T_4 V_158 = 0 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_10 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( ( 0 == V_242 -> V_243 ) && ( 0 == V_242 -> V_244 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( F_52 ( V_2 -> V_11 [ V_10 ] , true ) )
V_158 = V_245 ;
V_88:
return F_80 ( V_4 , V_246 ,
V_158 ) ;
}
static int F_90 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_241 * V_242 =
(struct V_241 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_242 -> V_10 ;
T_4 V_158 = 0 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_242 -> V_10 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( ( 0 == V_242 -> V_243 ) && ( 0 == V_242 -> V_244 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( F_52 ( V_2 -> V_11 [ V_10 ] , false ) )
V_158 = V_245 ;
V_88:
return F_80 ( V_4 , V_247 ,
V_158 ) ;
}
static int F_91 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_241 * V_242 =
(struct V_241 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_248 V_249 ;
T_4 V_158 = 0 ;
struct V_19 * V_11 ;
memset ( & V_249 , 0 , sizeof( struct V_248 ) ) ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ) {
V_158 = V_210 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_242 -> V_10 ) ) {
V_158 = V_210 ;
goto V_88;
}
V_11 = V_2 -> V_11 [ V_242 -> V_10 ] ;
if ( ! V_11 ) {
V_158 = V_210 ;
goto V_88;
}
F_92 ( V_11 ) ;
V_249 = V_11 -> V_250 ;
V_88:
return F_78 ( V_4 , V_251 , V_158 ,
( T_2 * ) & V_249 , sizeof( V_249 ) ) ;
}
static inline int F_93 ( struct V_3 * V_4 , T_2 * V_252 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_54 = 0 ;
if ( F_94 ( V_252 ) ||
F_95 ( V_252 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 , V_252 ) ;
V_54 = V_253 ;
} else if ( V_4 -> V_254 && ! F_96 ( V_252 ) &&
! F_97 ( V_252 , V_4 -> V_117 . V_118 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_25 ) ;
V_54 = - V_187 ;
}
return V_54 ;
}
static int F_98 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_255 * V_256 =
(struct V_255 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_256 -> V_10 ;
T_4 V_54 = 0 ;
int V_125 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ||
! F_64 ( V_132 , & V_4 -> V_133 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_210 ;
goto V_88;
}
for ( V_125 = 0 ; V_125 < V_256 -> V_257 ; V_125 ++ ) {
V_54 = F_93 ( V_4 , V_256 -> V_258 [ V_125 ] . V_118 ) ;
if ( V_54 )
goto V_88;
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_125 = 0 ; V_125 < V_256 -> V_257 ; V_125 ++ ) {
struct V_102 * V_103 ;
V_103 = F_99 ( V_11 , V_256 -> V_258 [ V_125 ] . V_118 , true , false ) ;
if ( ! V_103 ) {
if ( F_100 ( V_11 ) )
V_103 = F_101 ( V_11 , V_256 -> V_258 [ V_125 ] . V_118 ,
true , false ) ;
else
V_103 = F_31 ( V_11 , V_256 -> V_258 [ V_125 ] . V_118 , - 1 ,
true , false ) ;
}
if ( ! V_103 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_26 ) ;
V_54 = V_210 ;
goto V_88;
}
}
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_80 ( V_4 , V_259 ,
V_54 ) ;
}
static int F_102 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_255 * V_256 =
(struct V_255 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_256 -> V_10 ;
T_4 V_54 = 0 ;
int V_125 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ||
! F_64 ( V_132 , & V_4 -> V_133 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_210 ;
goto V_88;
}
for ( V_125 = 0 ; V_125 < V_256 -> V_257 ; V_125 ++ ) {
if ( F_94 ( V_256 -> V_258 [ V_125 ] . V_118 ) ||
F_95 ( V_256 -> V_258 [ V_125 ] . V_118 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 ,
V_256 -> V_258 [ V_125 ] . V_118 ) ;
V_54 = V_253 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_125 = 0 ; V_125 < V_256 -> V_257 ; V_125 ++ )
F_103 ( V_11 , V_256 -> V_258 [ V_125 ] . V_118 ,
V_260 , true , false ) ;
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_80 ( V_4 , V_261 ,
V_54 ) ;
}
static int F_104 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_263 -> V_10 ;
T_4 V_158 = 0 ;
int V_125 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ||
! F_64 ( V_132 , & V_4 -> V_133 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_158 = V_210 ;
goto V_88;
}
for ( V_125 = 0 ; V_125 < V_263 -> V_257 ; V_125 ++ ) {
if ( V_263 -> V_264 [ V_125 ] > V_265 ) {
V_158 = V_210 ;
F_21 ( & V_2 -> V_66 -> V_67 ,
L_28 , V_263 -> V_264 [ V_125 ] ) ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_215 ) {
V_158 = V_210 ;
goto V_88;
}
F_105 ( V_11 ) ;
for ( V_125 = 0 ; V_125 < V_263 -> V_257 ; V_125 ++ ) {
int V_54 = F_106 ( V_11 , V_263 -> V_264 [ V_125 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_29 ,
V_263 -> V_264 [ V_125 ] , V_54 ) ;
}
V_88:
return F_80 ( V_4 , V_266 , V_158 ) ;
}
static int F_107 ( struct V_3 * V_4 , T_2 * V_191 , T_3 V_192 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_191 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_263 -> V_10 ;
T_4 V_158 = 0 ;
int V_125 ;
if ( ! F_64 ( V_144 , & V_4 -> V_130 ) ||
! F_64 ( V_132 , & V_4 -> V_133 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_158 = V_210 ;
goto V_88;
}
for ( V_125 = 0 ; V_125 < V_263 -> V_257 ; V_125 ++ ) {
if ( V_263 -> V_264 [ V_125 ] > V_265 ) {
V_158 = V_210 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_215 ) {
V_158 = V_210 ;
goto V_88;
}
for ( V_125 = 0 ; V_125 < V_263 -> V_257 ; V_125 ++ ) {
int V_54 = F_108 ( V_11 , V_263 -> V_264 [ V_125 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_30 ,
V_263 -> V_264 [ V_125 ] , V_54 ) ;
}
V_88:
return F_80 ( V_4 , V_267 , V_158 ) ;
}
static int F_109 ( struct V_3 * V_4 , T_1 V_189 ,
T_1 V_190 , T_2 * V_191 , T_3 V_192 )
{
bool V_268 = false ;
int V_269 ;
if ( F_64 ( V_196 , & V_4 -> V_130 ) )
return V_210 ;
switch ( V_189 ) {
case V_204 :
V_269 = sizeof( struct V_201 ) ;
break;
case V_270 :
case V_221 :
V_269 = 0 ;
break;
case V_271 :
V_269 = sizeof( struct V_50 ) ;
break;
case V_272 :
V_269 = sizeof( struct V_77 ) ;
break;
case V_235 :
V_269 = sizeof( struct V_227 ) ;
if ( V_192 >= V_269 ) {
struct V_227 * V_273 =
(struct V_227 * ) V_191 ;
V_269 += ( V_273 -> V_13 *
sizeof( struct
V_229 ) ) ;
if ( V_273 -> V_13 == 0 )
V_268 = true ;
}
break;
case V_240 :
V_269 = sizeof( struct V_236 ) ;
if ( V_192 >= V_269 ) {
struct V_236 * V_274 =
(struct V_236 * ) V_191 ;
V_269 += ( V_274 -> V_239 *
sizeof( struct V_26 ) ) ;
if ( V_274 -> V_239 == 0 )
V_268 = true ;
}
break;
case V_246 :
case V_247 :
V_269 = sizeof( struct V_241 ) ;
break;
case V_259 :
case V_261 :
V_269 = sizeof( struct V_255 ) ;
if ( V_192 >= V_269 ) {
struct V_255 * V_275 =
(struct V_255 * ) V_191 ;
V_269 += V_275 -> V_257 *
sizeof( struct V_276 ) ;
if ( V_275 -> V_257 == 0 )
V_268 = true ;
}
break;
case V_266 :
case V_267 :
V_269 = sizeof( struct V_262 ) ;
if ( V_192 >= V_269 ) {
struct V_262 * V_263 =
(struct V_262 * ) V_191 ;
V_269 += V_263 -> V_257 * sizeof( T_3 ) ;
if ( V_263 -> V_257 == 0 )
V_268 = true ;
}
break;
case V_226 :
V_269 = sizeof( struct V_222 ) ;
break;
case V_251 :
V_269 = sizeof( struct V_241 ) ;
break;
case V_277 :
case V_278 :
default:
return - V_187 ;
break;
}
if ( ( V_269 != V_192 ) || ( V_268 ) ) {
F_80 ( V_4 , V_189 , V_210 ) ;
return - V_87 ;
} else {
return 0 ;
}
}
int F_110 ( struct V_1 * V_2 , T_3 V_8 , T_1 V_189 ,
T_1 V_190 , T_2 * V_191 , T_3 V_192 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned int V_279 = V_8 - V_6 -> V_15 . V_74 ;
struct V_3 * V_4 ;
int V_54 ;
V_2 -> V_280 ++ ;
if ( V_279 >= V_2 -> V_172 )
return - V_87 ;
V_4 = & ( V_2 -> V_4 [ V_279 ] ) ;
V_54 = F_109 ( V_4 , V_189 , V_190 , V_191 , V_192 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_31 ,
V_279 , V_189 , V_192 ) ;
return V_54 ;
}
switch ( V_189 ) {
case V_204 :
V_54 = F_81 ( V_4 ) ;
break;
case V_221 :
V_54 = F_82 ( V_4 ) ;
break;
case V_270 :
F_84 ( V_4 ) ;
V_54 = 0 ;
break;
case V_226 :
V_54 = F_85 ( V_4 , V_191 , V_192 ) ;
break;
case V_235 :
V_54 = F_87 ( V_4 , V_191 , V_192 ) ;
break;
case V_240 :
V_54 = F_88 ( V_4 , V_191 , V_192 ) ;
break;
case V_246 :
V_54 = F_89 ( V_4 , V_191 , V_192 ) ;
break;
case V_247 :
V_54 = F_90 ( V_4 , V_191 , V_192 ) ;
break;
case V_259 :
V_54 = F_98 ( V_4 , V_191 , V_192 ) ;
break;
case V_261 :
V_54 = F_102 ( V_4 , V_191 , V_192 ) ;
break;
case V_266 :
V_54 = F_104 ( V_4 , V_191 , V_192 ) ;
break;
case V_267 :
V_54 = F_107 ( V_4 , V_191 , V_192 ) ;
break;
case V_251 :
V_54 = F_91 ( V_4 , V_191 , V_192 ) ;
break;
case V_278 :
default:
F_21 ( & V_2 -> V_66 -> V_67 , L_32 ,
V_189 , V_279 ) ;
V_54 = F_80 ( V_4 , V_189 ,
V_281 ) ;
break;
}
return V_54 ;
}
int F_111 ( struct V_1 * V_2 )
{
T_1 V_7 , V_33 , V_170 , V_8 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
if ( ! F_64 ( V_282 , & V_2 -> V_283 ) )
return 0 ;
F_49 ( V_282 , & V_2 -> V_283 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_172 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_170 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_7 = F_2 ( V_6 , F_67 ( V_33 ) ) ;
if ( V_7 & ( 1 << V_170 ) ) {
F_4 ( V_6 , F_67 ( V_33 ) , ( 1 << V_170 ) ) ;
if ( ! F_64 ( V_284 , & V_2 -> V_283 ) )
F_48 ( V_4 , true ) ;
}
}
V_7 = F_2 ( V_6 , V_285 ) ;
V_7 |= V_286 ;
F_4 ( V_6 , V_285 , V_7 ) ;
F_5 ( V_6 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 ,
enum V_198 V_189 ,
T_4 V_190 , T_2 * V_191 ,
T_3 V_192 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_2 -> V_172 ; V_125 ++ , V_4 ++ ) {
int V_193 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( ! F_64 ( V_134 , & V_4 -> V_130 ) &&
! F_64 ( V_144 , & V_4 -> V_130 ) )
continue;
F_79 ( V_6 , V_193 , V_189 , V_190 ,
V_191 , V_192 , NULL ) ;
}
}
void F_113 ( struct V_1 * V_2 )
{
struct V_287 V_288 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_289 * V_290 = & V_2 -> V_6 . V_291 . V_292 ;
int V_125 ;
V_288 . V_293 = V_294 ;
V_288 . V_295 = V_296 ;
for ( V_125 = 0 ; V_125 < V_2 -> V_172 ; V_125 ++ , V_4 ++ ) {
int V_193 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( V_4 -> V_297 ) {
V_288 . V_298 . V_299 . V_300 = V_4 -> V_301 ;
V_288 . V_298 . V_299 . V_302 =
( V_4 -> V_301 ? V_303 : 0 ) ;
} else {
V_288 . V_298 . V_299 . V_300 =
V_290 -> V_292 & V_304 ;
V_288 . V_298 . V_299 . V_302 = V_290 -> V_302 ;
}
F_79 ( V_6 , V_193 , V_277 ,
0 , ( T_2 * ) & V_288 , sizeof( V_288 ) ,
NULL ) ;
}
}
void F_114 ( struct V_1 * V_2 )
{
struct V_287 V_288 ;
V_288 . V_293 = V_305 ;
V_288 . V_295 = V_306 ;
F_112 ( V_2 , V_277 , V_205 ,
( T_2 * ) & V_288 , sizeof( struct V_287 ) ) ;
}
void F_115 ( struct V_3 * V_4 )
{
struct V_287 V_288 ;
int V_193 ;
if ( ! V_4 || V_4 -> V_8 >= V_4 -> V_2 -> V_172 )
return;
if ( ! F_64 ( V_134 , & V_4 -> V_130 ) &&
! F_64 ( V_144 , & V_4 -> V_130 ) )
return;
V_193 = V_4 -> V_8 + V_4 -> V_2 -> V_6 . V_15 . V_74 ;
V_288 . V_293 = V_305 ;
V_288 . V_295 = V_306 ;
F_79 ( & V_4 -> V_2 -> V_6 , V_193 , V_277 ,
V_205 , ( T_2 * ) & V_288 ,
sizeof( struct V_287 ) , NULL ) ;
}
int F_116 ( struct V_307 * V_308 , int V_8 , T_2 * V_309 )
{
struct V_310 * V_311 = F_117 ( V_308 ) ;
struct V_19 * V_11 = V_311 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_169 ;
struct V_102 * V_103 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_172 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_112 ] ;
if ( ! F_64 ( V_134 , & V_4 -> V_130 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
if ( ! F_118 ( V_309 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_35 ) ;
V_54 = - V_87 ;
goto V_88;
}
F_103 ( V_11 , V_4 -> V_117 . V_118 , V_4 -> V_116 ,
true , false ) ;
F_119 (f, &vsi->mac_filter_list, list)
F_103 ( V_11 , V_103 -> V_252 , V_103 -> V_312 , true , false ) ;
F_29 ( & V_2 -> V_66 -> V_67 , L_36 , V_309 , V_8 ) ;
if ( F_32 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_9 ) ;
V_54 = - V_141 ;
goto V_88;
}
F_120 ( V_4 -> V_117 . V_118 , V_309 ) ;
V_4 -> V_254 = true ;
F_1 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_66 -> V_67 , L_37 ) ;
V_54 = 0 ;
V_88:
return V_54 ;
}
int F_121 ( struct V_307 * V_308 ,
int V_8 , T_3 V_264 , T_2 V_313 )
{
struct V_310 * V_311 = F_117 ( V_308 ) ;
struct V_1 * V_2 = V_311 -> V_11 -> V_169 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_172 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_314;
}
if ( ( V_264 > V_265 ) || ( V_313 > 7 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_38 ) ;
V_54 = - V_87 ;
goto V_314;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_112 ] ;
if ( ! F_64 ( V_134 , & V_4 -> V_130 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_314;
}
if ( V_11 -> V_22 . V_215 == 0 && F_100 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_39 ,
V_8 ) ;
F_1 ( V_2 , V_4 ) ;
}
if ( ( ! ( V_264 || V_313 ) ||
( V_264 | V_313 ) != F_10 ( V_11 -> V_22 . V_215 ) ) &&
V_11 -> V_22 . V_215 )
V_54 = F_106 ( V_11 , V_260 ) ;
if ( V_11 -> V_22 . V_215 ) {
V_54 = F_108 ( V_11 , ( F_10 ( V_11 -> V_22 . V_215 ) &
V_315 ) ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_169 -> V_66 -> V_67 ,
L_40 ,
V_54 , V_2 -> V_6 . V_106 . V_107 ) ;
}
}
if ( V_264 || V_313 )
V_54 = F_30 ( V_11 ,
V_264 | ( V_313 << V_316 ) ) ;
else
F_122 ( V_11 ) ;
if ( V_264 ) {
F_29 ( & V_2 -> V_66 -> V_67 , L_41 ,
V_264 , V_313 , V_8 ) ;
V_54 = F_106 ( V_11 , V_264 ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_169 -> V_66 -> V_67 ,
L_42 , V_54 ,
V_11 -> V_169 -> V_6 . V_106 . V_107 ) ;
goto V_314;
}
F_108 ( V_11 , V_260 ) ;
}
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_43 ) ;
goto V_314;
}
V_4 -> V_116 = F_10 ( V_11 -> V_22 . V_215 ) ;
V_54 = 0 ;
V_314:
return V_54 ;
}
int F_123 ( struct V_307 * V_308 , int V_8 , int V_317 ,
int V_318 )
{
struct V_310 * V_311 = F_117 ( V_308 ) ;
struct V_1 * V_2 = V_311 -> V_11 -> V_169 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_319 = 0 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_172 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_44 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( V_317 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_45 ,
V_317 , V_8 ) ;
return - V_87 ;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_112 ] ;
if ( ! F_64 ( V_134 , & V_4 -> V_130 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_46 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
switch ( V_2 -> V_6 . V_291 . V_292 . V_302 ) {
case V_303 :
V_319 = 40000 ;
break;
case V_320 :
V_319 = 10000 ;
break;
case V_321 :
V_319 = 1000 ;
break;
default:
break;
}
if ( V_318 > V_319 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_47 ,
V_318 , V_4 -> V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( ( V_318 < 50 ) && ( V_318 > 0 ) ) {
F_68 ( & V_2 -> V_66 -> V_67 , L_48 ) ;
V_318 = 50 ;
}
V_54 = F_33 ( & V_2 -> V_6 , V_11 -> V_105 ,
V_318 / V_322 ,
V_323 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_49 ,
V_54 ) ;
V_54 = - V_141 ;
goto error;
}
V_4 -> V_119 = V_318 ;
error:
return V_54 ;
}
int F_124 ( struct V_307 * V_308 ,
int V_8 , struct V_324 * V_325 )
{
struct V_310 * V_311 = F_117 ( V_308 ) ;
struct V_19 * V_11 = V_311 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_169 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_172 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_112 ] ;
if ( ! F_64 ( V_134 , & V_4 -> V_130 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_325 -> V_4 = V_8 ;
memcpy ( & V_325 -> V_309 , V_4 -> V_117 . V_118 , V_111 ) ;
V_325 -> V_318 = V_4 -> V_119 ;
V_325 -> V_317 = 0 ;
V_325 -> V_312 = F_10 ( V_11 -> V_22 . V_215 ) & V_326 ;
V_325 -> V_313 = ( F_10 ( V_11 -> V_22 . V_215 ) & V_327 ) >>
V_316 ;
if ( V_4 -> V_297 == false )
V_325 -> V_328 = V_329 ;
else if ( V_4 -> V_301 == true )
V_325 -> V_328 = V_330 ;
else
V_325 -> V_328 = V_331 ;
V_325 -> V_181 = V_4 -> V_181 ;
V_54 = 0 ;
V_88:
return V_54 ;
}
int F_125 ( struct V_307 * V_308 , int V_8 , int V_332 )
{
struct V_310 * V_311 = F_117 ( V_308 ) ;
struct V_1 * V_2 = V_311 -> V_11 -> V_169 ;
struct V_287 V_288 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_193 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_172 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_333;
}
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_193 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
V_288 . V_293 = V_294 ;
V_288 . V_295 = V_296 ;
switch ( V_332 ) {
case V_329 :
V_4 -> V_297 = false ;
V_288 . V_298 . V_299 . V_300 =
V_2 -> V_6 . V_291 . V_292 . V_292 & V_304 ;
V_288 . V_298 . V_299 . V_302 =
V_2 -> V_6 . V_291 . V_292 . V_302 ;
break;
case V_330 :
V_4 -> V_297 = true ;
V_4 -> V_301 = true ;
V_288 . V_298 . V_299 . V_300 = true ;
V_288 . V_298 . V_299 . V_302 = V_303 ;
break;
case V_331 :
V_4 -> V_297 = true ;
V_4 -> V_301 = false ;
V_288 . V_298 . V_299 . V_300 = false ;
V_288 . V_298 . V_299 . V_302 = 0 ;
break;
default:
V_54 = - V_87 ;
goto V_333;
}
F_79 ( V_6 , V_193 , V_277 ,
0 , ( T_2 * ) & V_288 , sizeof( V_288 ) , NULL ) ;
V_333:
return V_54 ;
}
int F_126 ( struct V_307 * V_308 , int V_8 , bool V_334 )
{
struct V_310 * V_311 = F_117 ( V_308 ) ;
struct V_19 * V_11 = V_311 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_169 ;
struct V_156 V_157 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_172 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_185;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
if ( V_334 == V_4 -> V_181 )
goto V_185;
V_4 -> V_181 = V_334 ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_157 . V_105 = V_2 -> V_11 [ V_4 -> V_112 ] -> V_105 ;
V_157 . V_160 = V_2 -> V_6 . V_71 ;
V_157 . V_22 . V_165 = F_58 ( V_335 ) ;
if ( V_334 )
V_157 . V_22 . V_336 |= V_337 ;
V_54 = F_59 ( V_6 , & V_157 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_50 ,
V_54 ) ;
V_54 = - V_141 ;
}
V_185:
return V_54 ;
}
