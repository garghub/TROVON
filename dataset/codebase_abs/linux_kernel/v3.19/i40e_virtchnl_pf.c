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
V_79 . V_101 = 1 ;
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
static int F_27 ( struct V_3 * V_4 , enum V_102 type )
{
struct V_103 * V_104 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 ;
int V_54 = 0 ;
V_11 = F_28 ( V_2 , type , V_2 -> V_11 [ V_2 -> V_105 ] -> V_106 , V_4 -> V_8 ) ;
if ( ! V_11 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_5 ,
V_4 -> V_8 , V_2 -> V_6 . V_107 . V_108 ) ;
V_54 = - V_68 ;
goto V_109;
}
if ( type == V_110 ) {
T_2 V_111 [ V_112 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_113 = V_11 -> V_114 ;
V_4 -> V_115 = V_11 -> V_116 ;
F_29 ( & V_2 -> V_66 -> V_67 ,
L_6 ,
V_4 -> V_8 , V_11 -> V_114 , V_11 -> V_116 ) ;
if ( V_4 -> V_117 )
F_30 ( V_11 , V_4 -> V_117 ) ;
V_104 = F_31 ( V_11 , V_4 -> V_118 . V_119 ,
V_4 -> V_117 , true , false ) ;
if ( ! V_104 )
F_29 ( & V_2 -> V_66 -> V_67 ,
L_7 ) ;
V_104 = F_31 ( V_11 , V_111 , V_4 -> V_117 ,
true , false ) ;
if ( ! V_104 )
F_29 ( & V_2 -> V_66 -> V_67 ,
L_8 ) ;
}
V_54 = F_32 ( V_11 ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 , L_9 ) ;
if ( V_4 -> V_120 ) {
V_54 = F_33 ( & V_2 -> V_6 , V_11 -> V_106 ,
V_4 -> V_120 / 50 , 0 , NULL ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 , L_10 ,
V_4 -> V_8 , V_54 ) ;
}
V_109:
return V_54 ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_121 = 0 ;
int V_122 ;
F_4 ( V_6 , F_35 ( V_4 -> V_115 ) ,
V_123 ) ;
V_7 = V_124 ;
F_4 ( V_6 , F_36 ( V_4 -> V_8 ) , V_7 ) ;
for ( V_122 = 0 ; V_122 < V_2 -> V_11 [ V_4 -> V_113 ] -> V_13 ; V_122 ++ ) {
T_3 V_12 = F_9 ( V_4 , V_4 -> V_113 , V_122 ) ;
V_7 = ( V_12 & V_125 ) ;
F_4 ( V_6 , F_37 ( V_121 , V_4 -> V_8 ) , V_7 ) ;
V_121 ++ ;
}
for ( V_122 = 0 ; V_122 < 7 ; V_122 ++ ) {
if ( V_122 * 2 >= V_2 -> V_11 [ V_4 -> V_113 ] -> V_13 ) {
V_7 = 0x07FF07FF ;
} else {
T_3 V_12 = F_9 ( V_4 , V_4 -> V_113 ,
V_122 * 2 ) ;
V_7 = V_12 ;
V_12 = F_9 ( V_4 , V_4 -> V_113 ,
( V_122 * 2 ) + 1 ) ;
V_7 |= V_12 << 16 ;
}
F_4 ( V_6 , F_38 ( V_122 , V_4 -> V_115 ) , V_7 ) ;
}
F_5 ( V_6 ) ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_126 ;
F_4 ( V_6 , F_36 ( V_4 -> V_8 ) , 0 ) ;
for ( V_126 = 0 ; V_126 < V_40 ; V_126 ++ )
F_4 ( V_6 , F_37 ( V_126 , V_4 -> V_8 ) ,
V_21 ) ;
F_5 ( V_6 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_33 , V_7 ;
int V_126 , V_127 ;
if ( V_4 -> V_113 ) {
F_41 ( V_2 -> V_11 [ V_4 -> V_113 ] ) ;
V_4 -> V_113 = 0 ;
V_4 -> V_115 = 0 ;
}
V_127 = V_2 -> V_6 . V_15 . V_16 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
if ( 0 == V_126 )
V_33 = F_42 ( V_4 -> V_8 ) ;
else
V_33 = F_43 ( ( ( V_127 - 1 ) *
( V_4 -> V_8 ) )
+ ( V_126 - 1 ) ) ;
F_4 ( V_6 , V_33 , V_128 ) ;
F_5 ( V_6 ) ;
}
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
if ( 0 == V_126 )
V_33 = F_12 ( V_4 -> V_8 ) ;
else
V_33 = F_13 ( ( ( V_127 - 1 ) *
( V_4 -> V_8 ) )
+ ( V_126 - 1 ) ) ;
V_7 = ( V_129 |
V_130 ) ;
F_4 ( V_6 , V_33 , V_7 ) ;
F_5 ( V_6 ) ;
}
V_4 -> V_131 = 0 ;
V_4 -> V_132 = 0 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_121 = 0 ;
int V_54 ;
V_54 = F_27 ( V_4 , V_110 ) ;
if ( V_54 )
goto V_133;
V_121 += V_2 -> V_11 [ V_4 -> V_113 ] -> V_13 ;
F_45 ( V_134 , & V_4 -> V_135 ) ;
V_4 -> V_131 = V_121 ;
F_45 ( V_136 , & V_4 -> V_132 ) ;
V_133:
if ( V_54 )
F_40 ( V_4 ) ;
return V_54 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_137 , V_126 ;
T_1 V_7 ;
V_137 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
F_4 ( V_6 , V_138 ,
V_139 | ( V_137 << V_140 ) ) ;
for ( V_126 = 0 ; V_126 < 100 ; V_126 ++ ) {
V_7 = F_2 ( V_6 , V_141 ) ;
if ( ( V_7 & V_142 ) == 0 )
return 0 ;
F_47 ( 1 ) ;
}
return - V_143 ;
}
void F_48 ( struct V_3 * V_4 , bool V_144 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_145 = false ;
int V_126 ;
T_1 V_7 ;
F_49 ( V_146 , & V_4 -> V_132 ) ;
if ( ! V_144 ) {
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 |= V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
F_5 ( V_6 ) ;
}
if ( F_46 ( V_4 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_11 ,
V_4 -> V_8 ) ;
for ( V_126 = 0 ; V_126 < 100 ; V_126 ++ ) {
F_50 ( 10 , 20 ) ;
V_7 = F_2 ( V_6 , F_51 ( V_4 -> V_8 ) ) ;
if ( V_7 & V_147 ) {
V_145 = true ;
break;
}
}
if ( ! V_145 )
F_21 ( & V_2 -> V_66 -> V_67 , L_12 ,
V_4 -> V_8 ) ;
F_4 ( V_6 , F_52 ( V_4 -> V_8 ) , V_148 ) ;
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 &= ~ V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
if ( V_4 -> V_113 == 0 )
goto V_149;
F_53 ( V_2 -> V_11 [ V_4 -> V_113 ] , false ) ;
V_149:
F_40 ( V_4 ) ;
F_44 ( V_4 ) ;
F_34 ( V_4 ) ;
F_45 ( V_146 , & V_4 -> V_132 ) ;
F_4 ( V_6 , F_52 ( V_4 -> V_8 ) , V_150 ) ;
F_5 ( V_6 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_105 ] ;
struct V_151 V_152 ;
int V_153 ;
V_152 . V_106 = V_2 -> V_154 ;
V_152 . V_155 = V_2 -> V_6 . V_71 ;
V_152 . V_156 = 0 ;
V_153 = F_55 ( & V_2 -> V_6 , & V_152 , NULL ) ;
if ( V_153 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_157 , V_153 , V_2 -> V_6 . V_107 . V_108 ) ;
return;
}
V_152 . V_158 = V_159 ;
V_152 . V_22 . V_160 = F_56 ( V_161 ) ;
V_152 . V_22 . V_162 |= F_56 ( V_163 ) ;
V_153 = F_57 ( & V_11 -> V_164 -> V_6 , & V_152 , NULL ) ;
if ( V_153 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_157 , V_11 -> V_164 -> V_6 . V_107 . V_108 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_105 ] ;
struct V_151 V_152 ;
int V_153 ;
V_152 . V_106 = V_2 -> V_154 ;
V_152 . V_155 = V_2 -> V_6 . V_71 ;
V_152 . V_156 = 0 ;
V_153 = F_55 ( & V_2 -> V_6 , & V_152 , NULL ) ;
if ( V_153 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_157 , V_153 , V_2 -> V_6 . V_107 . V_108 ) ;
return;
}
V_152 . V_158 = V_159 ;
V_152 . V_22 . V_160 = F_56 ( V_161 ) ;
V_152 . V_22 . V_162 &= ~ F_56 ( V_163 ) ;
V_153 = F_57 ( & V_11 -> V_164 -> V_6 , & V_152 , NULL ) ;
if ( V_153 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_157 , V_11 -> V_164 -> V_6 . V_107 . V_108 ) ;
}
}
void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_33 , V_165 ;
int V_126 , V_166 , V_8 ;
if ( ! V_2 -> V_4 )
return;
F_60 ( V_2 ) ;
F_61 ( 10 ) ;
V_166 = V_2 -> V_167 ;
V_2 -> V_167 = 0 ;
for ( V_126 = 0 ; V_126 < V_166 ; V_126 ++ ) {
if ( F_62 ( V_136 , & V_2 -> V_4 [ V_126 ] . V_132 ) )
F_40 ( & V_2 -> V_4 [ V_126 ] ) ;
F_39 ( & V_2 -> V_4 [ V_126 ] ) ;
}
F_63 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
if ( ! F_64 ( V_2 -> V_66 ) ) {
F_65 ( V_2 -> V_66 ) ;
for ( V_8 = 0 ; V_8 < V_166 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_165 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
F_4 ( V_6 , F_66 ( V_33 ) , ( 1 << V_165 ) ) ;
}
F_58 ( V_2 ) ;
} else {
F_67 ( & V_2 -> V_66 -> V_67 ,
L_15 ) ;
}
F_68 ( V_2 ) ;
}
int F_69 ( struct V_1 * V_2 , T_3 V_167 )
{
struct V_3 * V_168 ;
int V_126 , V_54 = 0 ;
F_60 ( V_2 ) ;
if ( F_70 ( V_2 -> V_66 ) != V_167 ) {
V_54 = F_71 ( V_2 -> V_66 , V_167 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_16 , V_54 ) ;
V_2 -> V_167 = 0 ;
goto V_169;
}
}
V_168 = F_72 ( V_167 , sizeof( struct V_3 ) , V_170 ) ;
if ( ! V_168 ) {
V_54 = - V_171 ;
goto V_172;
}
V_2 -> V_4 = V_168 ;
for ( V_126 = 0 ; V_126 < V_167 ; V_126 ++ ) {
V_168 [ V_126 ] . V_2 = V_2 ;
V_168 [ V_126 ] . V_173 = V_174 ;
V_168 [ V_126 ] . V_8 = V_126 ;
F_45 ( V_175 , & V_168 [ V_126 ] . V_135 ) ;
V_168 [ V_126 ] . V_176 = true ;
F_48 ( & V_168 [ V_126 ] , false ) ;
F_34 ( & V_168 [ V_126 ] ) ;
}
V_2 -> V_167 = V_167 ;
F_54 ( V_2 ) ;
V_172:
if ( V_54 )
F_59 ( V_2 ) ;
V_169:
F_68 ( V_2 ) ;
return V_54 ;
}
static int F_73 ( struct V_177 * V_66 , int V_178 )
{
#ifdef F_74
struct V_1 * V_2 = F_75 ( V_66 ) ;
int V_179 = F_70 ( V_66 ) ;
int V_180 = 0 ;
F_29 ( & V_66 -> V_67 , L_17 , V_178 ) ;
if ( V_179 && V_179 != V_178 )
F_59 ( V_2 ) ;
else if ( V_179 && V_179 == V_178 )
goto V_181;
if ( V_178 > V_2 -> V_182 ) {
V_180 = - V_183 ;
goto V_184;
}
V_180 = F_69 ( V_2 , V_178 ) ;
if ( V_180 ) {
F_67 ( & V_66 -> V_67 , L_18 , V_180 ) ;
goto V_184;
}
V_181:
return V_178 ;
V_184:
return V_180 ;
#endif
return 0 ;
}
int F_76 ( struct V_177 * V_66 , int V_178 )
{
struct V_1 * V_2 = F_75 ( V_66 ) ;
if ( V_178 )
return F_73 ( V_66 , V_178 ) ;
if ( ! F_64 ( V_2 -> V_66 ) ) {
F_59 ( V_2 ) ;
} else {
F_67 ( & V_66 -> V_67 , L_19 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_77 ( struct V_3 * V_4 , T_1 V_185 ,
T_1 V_186 , T_2 * V_187 , T_3 V_188 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_189 ;
T_4 V_153 ;
if ( ! V_4 || V_4 -> V_8 >= V_4 -> V_2 -> V_167 )
return - V_87 ;
V_2 = V_4 -> V_2 ;
V_6 = & V_2 -> V_6 ;
V_189 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( V_186 ) {
V_4 -> V_190 ++ ;
F_21 ( & V_2 -> V_66 -> V_67 , L_20 ,
V_185 , V_186 ) ;
if ( V_4 -> V_190 >
V_191 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_21 ,
V_4 -> V_8 ) ;
F_21 ( & V_2 -> V_66 -> V_67 , L_22 ) ;
F_45 ( V_192 , & V_4 -> V_132 ) ;
}
} else {
V_4 -> V_193 ++ ;
}
V_153 = F_78 ( V_6 , V_189 , V_185 , V_186 ,
V_187 , V_188 , NULL ) ;
if ( V_153 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_23 ,
V_4 -> V_8 , V_2 -> V_6 . V_107 . V_108 ) ;
return - V_143 ;
}
return 0 ;
}
static int F_79 ( struct V_3 * V_4 ,
enum V_194 V_195 ,
T_4 V_196 )
{
return F_77 ( V_4 , V_195 , V_196 , NULL , 0 ) ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_197 V_22 = {
V_198 , V_199
} ;
return F_77 ( V_4 , V_200 ,
V_201 , ( T_2 * ) & V_22 ,
sizeof( struct
V_197 ) ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_202 * V_203 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_153 = 0 ;
struct V_19 * V_11 ;
int V_126 = 0 , V_204 = 0 ;
int V_205 = 1 ;
int V_54 ;
if ( ! F_62 ( V_136 , & V_4 -> V_132 ) ) {
V_153 = V_206 ;
goto V_180;
}
V_204 = ( sizeof( struct V_202 ) +
sizeof( struct V_207 ) * V_205 ) ;
V_203 = F_82 ( V_204 , V_170 ) ;
if ( ! V_203 ) {
V_153 = V_208 ;
V_204 = 0 ;
goto V_180;
}
V_203 -> V_209 = V_210 ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! V_11 -> V_22 . V_211 )
V_203 -> V_209 |= V_212 ;
V_203 -> V_205 = V_205 ;
V_203 -> V_131 = V_4 -> V_131 ;
V_203 -> V_213 = V_2 -> V_6 . V_15 . V_16 ;
if ( V_4 -> V_113 ) {
V_203 -> V_214 [ V_126 ] . V_10 = V_4 -> V_113 ;
V_203 -> V_214 [ V_126 ] . V_215 = V_110 ;
V_203 -> V_214 [ V_126 ] . V_131 =
V_2 -> V_11 [ V_4 -> V_113 ] -> V_13 ;
memcpy ( V_203 -> V_214 [ V_126 ] . V_216 ,
V_4 -> V_118 . V_119 , V_112 ) ;
V_126 ++ ;
}
F_45 ( V_146 , & V_4 -> V_132 ) ;
V_180:
V_54 = F_77 ( V_4 , V_217 ,
V_153 , ( T_2 * ) V_203 , V_204 ) ;
F_63 ( V_203 ) ;
return V_54 ;
}
static void F_83 ( struct V_3 * V_4 )
{
if ( F_62 ( V_146 , & V_4 -> V_132 ) )
F_48 ( V_4 , false ) ;
}
static int F_84 ( struct V_3 * V_4 ,
T_2 * V_187 , T_3 V_188 )
{
struct V_218 * V_22 =
(struct V_218 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_19 * V_11 ;
bool V_219 = false ;
T_4 V_153 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ||
! F_62 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_22 -> V_10 ) ||
( V_2 -> V_11 [ V_22 -> V_10 ] -> type != V_220 ) ) {
V_153 = V_206 ;
goto V_88;
}
V_11 = V_2 -> V_11 [ V_22 -> V_10 ] ;
if ( V_22 -> V_158 & V_221 )
V_219 = true ;
V_153 = F_85 ( V_6 , V_11 -> V_106 ,
V_219 , NULL ) ;
V_88:
return F_79 ( V_4 ,
V_222 ,
V_153 ) ;
}
static int F_86 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_223 * V_224 =
(struct V_223 * ) V_187 ;
struct V_225 * V_226 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 , V_18 ;
T_4 V_153 = 0 ;
int V_126 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ) {
V_153 = V_206 ;
goto V_88;
}
V_10 = V_224 -> V_10 ;
if ( ! F_6 ( V_4 , V_10 ) ) {
V_153 = V_206 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_224 -> V_131 ; V_126 ++ ) {
V_226 = & V_224 -> V_227 [ V_126 ] ;
V_18 = V_226 -> V_228 . V_229 ;
if ( ( V_226 -> V_228 . V_10 != V_10 ) ||
( V_226 -> V_230 . V_10 != V_10 ) ||
( V_226 -> V_230 . V_229 != V_18 ) ||
! F_7 ( V_4 , V_10 , V_18 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( F_24 ( V_4 , V_10 , V_18 ,
& V_226 -> V_230 ) ||
F_19 ( V_4 , V_10 , V_18 ,
& V_226 -> V_228 ) ) {
V_153 = V_206 ;
goto V_88;
}
}
V_2 -> V_11 [ V_4 -> V_113 ] -> V_131 = V_224 -> V_131 ;
V_88:
return F_79 ( V_4 , V_231 ,
V_153 ) ;
}
static int F_87 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_232 * V_233 =
(struct V_232 * ) V_187 ;
struct V_26 * V_234 ;
T_3 V_10 , V_18 , V_14 ;
T_4 V_153 = 0 ;
unsigned long V_29 ;
int V_126 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ) {
V_153 = V_206 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_233 -> V_235 ; V_126 ++ ) {
V_234 = & V_233 -> V_27 [ V_126 ] ;
V_14 = V_234 -> V_14 ;
V_10 = V_234 -> V_10 ;
if ( ! F_8 ( V_4 , V_14 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_153 = V_206 ;
goto V_88;
}
V_29 = V_234 -> V_35 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_153 = V_206 ;
goto V_88;
}
}
V_29 = V_234 -> V_36 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_153 = V_206 ;
goto V_88;
}
}
F_11 ( V_4 , V_10 , V_234 ) ;
}
V_88:
return F_79 ( V_4 , V_236 ,
V_153 ) ;
}
static int F_88 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_237 * V_238 =
(struct V_237 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_238 -> V_10 ;
T_4 V_153 = 0 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_10 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( ( 0 == V_238 -> V_239 ) && ( 0 == V_238 -> V_240 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( F_53 ( V_2 -> V_11 [ V_10 ] , true ) )
V_153 = V_241 ;
V_88:
return F_79 ( V_4 , V_242 ,
V_153 ) ;
}
static int F_89 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_237 * V_238 =
(struct V_237 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_238 -> V_10 ;
T_4 V_153 = 0 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_238 -> V_10 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( ( 0 == V_238 -> V_239 ) && ( 0 == V_238 -> V_240 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( F_53 ( V_2 -> V_11 [ V_10 ] , false ) )
V_153 = V_241 ;
V_88:
return F_79 ( V_4 , V_243 ,
V_153 ) ;
}
static int F_90 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_237 * V_238 =
(struct V_237 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_244 V_245 ;
T_4 V_153 = 0 ;
struct V_19 * V_11 ;
memset ( & V_245 , 0 , sizeof( struct V_244 ) ) ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ) {
V_153 = V_206 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_238 -> V_10 ) ) {
V_153 = V_206 ;
goto V_88;
}
V_11 = V_2 -> V_11 [ V_238 -> V_10 ] ;
if ( ! V_11 ) {
V_153 = V_206 ;
goto V_88;
}
F_91 ( V_11 ) ;
V_245 = V_11 -> V_246 ;
V_88:
return F_77 ( V_4 , V_247 , V_153 ,
( T_2 * ) & V_245 , sizeof( V_245 ) ) ;
}
static inline int F_92 ( struct V_3 * V_4 , T_2 * V_248 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_54 = 0 ;
if ( F_93 ( V_248 ) ||
F_94 ( V_248 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 , V_248 ) ;
V_54 = V_249 ;
} else if ( V_4 -> V_250 && ! F_95 ( V_248 ) &&
! F_96 ( V_248 , V_4 -> V_118 . V_119 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_25 ) ;
V_54 = - V_183 ;
}
return V_54 ;
}
static int F_97 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_251 * V_252 =
(struct V_251 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_252 -> V_10 ;
T_4 V_54 = 0 ;
int V_126 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ||
! F_62 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_206 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_252 -> V_253 ; V_126 ++ ) {
V_54 = F_92 ( V_4 , V_252 -> V_254 [ V_126 ] . V_119 ) ;
if ( V_54 )
goto V_88;
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_126 = 0 ; V_126 < V_252 -> V_253 ; V_126 ++ ) {
struct V_103 * V_104 ;
V_104 = F_98 ( V_11 , V_252 -> V_254 [ V_126 ] . V_119 , true , false ) ;
if ( ! V_104 ) {
if ( F_99 ( V_11 ) )
V_104 = F_100 ( V_11 , V_252 -> V_254 [ V_126 ] . V_119 ,
true , false ) ;
else
V_104 = F_31 ( V_11 , V_252 -> V_254 [ V_126 ] . V_119 , - 1 ,
true , false ) ;
}
if ( ! V_104 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_26 ) ;
V_54 = V_206 ;
goto V_88;
}
}
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_79 ( V_4 , V_255 ,
V_54 ) ;
}
static int F_101 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_251 * V_252 =
(struct V_251 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_252 -> V_10 ;
T_4 V_54 = 0 ;
int V_126 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ||
! F_62 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_206 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_252 -> V_253 ; V_126 ++ ) {
if ( F_93 ( V_252 -> V_254 [ V_126 ] . V_119 ) ||
F_94 ( V_252 -> V_254 [ V_126 ] . V_119 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 ,
V_252 -> V_254 [ V_126 ] . V_119 ) ;
V_54 = V_249 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_126 = 0 ; V_126 < V_252 -> V_253 ; V_126 ++ )
F_102 ( V_11 , V_252 -> V_254 [ V_126 ] . V_119 ,
V_256 , true , false ) ;
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_79 ( V_4 , V_257 ,
V_54 ) ;
}
static int F_103 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_258 * V_259 =
(struct V_258 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_259 -> V_10 ;
T_4 V_153 = 0 ;
int V_126 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ||
! F_62 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_153 = V_206 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_259 -> V_253 ; V_126 ++ ) {
if ( V_259 -> V_260 [ V_126 ] > V_261 ) {
V_153 = V_206 ;
F_21 ( & V_2 -> V_66 -> V_67 ,
L_28 , V_259 -> V_260 [ V_126 ] ) ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_211 ) {
V_153 = V_206 ;
goto V_88;
}
F_104 ( V_11 ) ;
for ( V_126 = 0 ; V_126 < V_259 -> V_253 ; V_126 ++ ) {
int V_54 = F_105 ( V_11 , V_259 -> V_260 [ V_126 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_29 ,
V_259 -> V_260 [ V_126 ] , V_54 ) ;
}
V_88:
return F_79 ( V_4 , V_262 , V_153 ) ;
}
static int F_106 ( struct V_3 * V_4 , T_2 * V_187 , T_3 V_188 )
{
struct V_258 * V_259 =
(struct V_258 * ) V_187 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_259 -> V_10 ;
T_4 V_153 = 0 ;
int V_126 ;
if ( ! F_62 ( V_146 , & V_4 -> V_132 ) ||
! F_62 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_153 = V_206 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_259 -> V_253 ; V_126 ++ ) {
if ( V_259 -> V_260 [ V_126 ] > V_261 ) {
V_153 = V_206 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_211 ) {
V_153 = V_206 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_259 -> V_253 ; V_126 ++ ) {
int V_54 = F_107 ( V_11 , V_259 -> V_260 [ V_126 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_30 ,
V_259 -> V_260 [ V_126 ] , V_54 ) ;
}
V_88:
return F_79 ( V_4 , V_263 , V_153 ) ;
}
static int F_108 ( struct V_3 * V_4 , T_1 V_185 ,
T_1 V_186 , T_2 * V_187 , T_3 V_188 )
{
bool V_264 = false ;
int V_265 ;
if ( F_62 ( V_192 , & V_4 -> V_132 ) )
return V_206 ;
switch ( V_185 ) {
case V_200 :
V_265 = sizeof( struct V_197 ) ;
break;
case V_266 :
case V_217 :
V_265 = 0 ;
break;
case V_267 :
V_265 = sizeof( struct V_50 ) ;
break;
case V_268 :
V_265 = sizeof( struct V_77 ) ;
break;
case V_231 :
V_265 = sizeof( struct V_223 ) ;
if ( V_188 >= V_265 ) {
struct V_223 * V_269 =
(struct V_223 * ) V_187 ;
V_265 += ( V_269 -> V_131 *
sizeof( struct
V_225 ) ) ;
if ( V_269 -> V_131 == 0 )
V_264 = true ;
}
break;
case V_236 :
V_265 = sizeof( struct V_232 ) ;
if ( V_188 >= V_265 ) {
struct V_232 * V_270 =
(struct V_232 * ) V_187 ;
V_265 += ( V_270 -> V_235 *
sizeof( struct V_26 ) ) ;
if ( V_270 -> V_235 == 0 )
V_264 = true ;
}
break;
case V_242 :
case V_243 :
V_265 = sizeof( struct V_237 ) ;
break;
case V_255 :
case V_257 :
V_265 = sizeof( struct V_251 ) ;
if ( V_188 >= V_265 ) {
struct V_251 * V_271 =
(struct V_251 * ) V_187 ;
V_265 += V_271 -> V_253 *
sizeof( struct V_272 ) ;
if ( V_271 -> V_253 == 0 )
V_264 = true ;
}
break;
case V_262 :
case V_263 :
V_265 = sizeof( struct V_258 ) ;
if ( V_188 >= V_265 ) {
struct V_258 * V_259 =
(struct V_258 * ) V_187 ;
V_265 += V_259 -> V_253 * sizeof( T_3 ) ;
if ( V_259 -> V_253 == 0 )
V_264 = true ;
}
break;
case V_222 :
V_265 = sizeof( struct V_218 ) ;
break;
case V_247 :
V_265 = sizeof( struct V_237 ) ;
break;
case V_273 :
case V_274 :
default:
return - V_183 ;
break;
}
if ( ( V_265 != V_188 ) || ( V_264 ) ) {
F_79 ( V_4 , V_185 , V_206 ) ;
return - V_87 ;
} else {
return 0 ;
}
}
int F_109 ( struct V_1 * V_2 , T_3 V_8 , T_1 V_185 ,
T_1 V_186 , T_2 * V_187 , T_3 V_188 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned int V_275 = V_8 - V_6 -> V_15 . V_74 ;
struct V_3 * V_4 ;
int V_54 ;
V_2 -> V_276 ++ ;
if ( V_275 >= V_2 -> V_167 )
return - V_87 ;
V_4 = & ( V_2 -> V_4 [ V_275 ] ) ;
V_54 = F_108 ( V_4 , V_185 , V_186 , V_187 , V_188 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_31 ,
V_275 , V_185 , V_188 ) ;
return V_54 ;
}
switch ( V_185 ) {
case V_200 :
V_54 = F_80 ( V_4 ) ;
break;
case V_217 :
V_54 = F_81 ( V_4 ) ;
break;
case V_266 :
F_83 ( V_4 ) ;
V_54 = 0 ;
break;
case V_222 :
V_54 = F_84 ( V_4 , V_187 , V_188 ) ;
break;
case V_231 :
V_54 = F_86 ( V_4 , V_187 , V_188 ) ;
break;
case V_236 :
V_54 = F_87 ( V_4 , V_187 , V_188 ) ;
break;
case V_242 :
V_54 = F_88 ( V_4 , V_187 , V_188 ) ;
break;
case V_243 :
V_54 = F_89 ( V_4 , V_187 , V_188 ) ;
break;
case V_255 :
V_54 = F_97 ( V_4 , V_187 , V_188 ) ;
break;
case V_257 :
V_54 = F_101 ( V_4 , V_187 , V_188 ) ;
break;
case V_262 :
V_54 = F_103 ( V_4 , V_187 , V_188 ) ;
break;
case V_263 :
V_54 = F_106 ( V_4 , V_187 , V_188 ) ;
break;
case V_247 :
V_54 = F_90 ( V_4 , V_187 , V_188 ) ;
break;
case V_274 :
default:
F_21 ( & V_2 -> V_66 -> V_67 , L_32 ,
V_185 , V_275 ) ;
V_54 = F_79 ( V_4 , V_185 ,
V_277 ) ;
break;
}
return V_54 ;
}
int F_110 ( struct V_1 * V_2 )
{
T_1 V_7 , V_33 , V_165 , V_8 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
if ( ! F_62 ( V_278 , & V_2 -> V_279 ) )
return 0 ;
V_7 = F_2 ( V_6 , V_280 ) ;
V_7 |= V_281 ;
F_4 ( V_6 , V_280 , V_7 ) ;
F_5 ( V_6 ) ;
F_49 ( V_278 , & V_2 -> V_279 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_167 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_165 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_7 = F_2 ( V_6 , F_66 ( V_33 ) ) ;
if ( V_7 & ( 1 << V_165 ) ) {
F_4 ( V_6 , F_66 ( V_33 ) , ( 1 << V_165 ) ) ;
if ( ! F_62 ( V_282 , & V_2 -> V_279 ) )
F_48 ( V_4 , true ) ;
}
}
return 0 ;
}
static void F_111 ( struct V_1 * V_2 ,
enum V_194 V_185 ,
T_4 V_186 , T_2 * V_187 ,
T_3 V_188 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < V_2 -> V_167 ; V_126 ++ , V_4 ++ ) {
int V_189 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( ! F_62 ( V_136 , & V_4 -> V_132 ) &&
! F_62 ( V_146 , & V_4 -> V_132 ) )
continue;
F_78 ( V_6 , V_189 , V_185 , V_186 ,
V_187 , V_188 , NULL ) ;
}
}
void F_112 ( struct V_1 * V_2 )
{
struct V_283 V_284 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_285 * V_286 = & V_2 -> V_6 . V_287 . V_288 ;
int V_126 ;
V_284 . V_289 = V_290 ;
V_284 . V_291 = V_292 ;
for ( V_126 = 0 ; V_126 < V_2 -> V_167 ; V_126 ++ , V_4 ++ ) {
int V_189 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( V_4 -> V_293 ) {
V_284 . V_294 . V_295 . V_296 = V_4 -> V_297 ;
V_284 . V_294 . V_295 . V_298 =
( V_4 -> V_297 ? V_299 : 0 ) ;
} else {
V_284 . V_294 . V_295 . V_296 =
V_286 -> V_288 & V_300 ;
V_284 . V_294 . V_295 . V_298 = V_286 -> V_298 ;
}
F_78 ( V_6 , V_189 , V_273 ,
0 , ( T_2 * ) & V_284 , sizeof( V_284 ) ,
NULL ) ;
}
}
void F_113 ( struct V_1 * V_2 )
{
struct V_283 V_284 ;
V_284 . V_289 = V_301 ;
V_284 . V_291 = V_302 ;
F_111 ( V_2 , V_273 , V_201 ,
( T_2 * ) & V_284 , sizeof( struct V_283 ) ) ;
}
void F_114 ( struct V_3 * V_4 )
{
struct V_283 V_284 ;
int V_189 ;
if ( ! V_4 || V_4 -> V_8 >= V_4 -> V_2 -> V_167 )
return;
if ( ! F_62 ( V_136 , & V_4 -> V_132 ) &&
! F_62 ( V_146 , & V_4 -> V_132 ) )
return;
V_189 = V_4 -> V_8 + V_4 -> V_2 -> V_6 . V_15 . V_74 ;
V_284 . V_289 = V_301 ;
V_284 . V_291 = V_302 ;
F_78 ( & V_4 -> V_2 -> V_6 , V_189 , V_273 ,
V_201 , ( T_2 * ) & V_284 ,
sizeof( struct V_283 ) , NULL ) ;
}
int F_115 ( struct V_303 * V_304 , int V_8 , T_2 * V_305 )
{
struct V_306 * V_307 = F_116 ( V_304 ) ;
struct V_19 * V_11 = V_307 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_164 ;
struct V_103 * V_104 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_167 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_62 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
if ( ! F_117 ( V_305 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_35 ) ;
V_54 = - V_87 ;
goto V_88;
}
F_102 ( V_11 , V_4 -> V_118 . V_119 , V_4 -> V_117 ,
true , false ) ;
F_118 (f, &vsi->mac_filter_list, list)
F_102 ( V_11 , V_104 -> V_248 , V_104 -> V_308 , true , false ) ;
F_29 ( & V_2 -> V_66 -> V_67 , L_36 , V_305 , V_8 ) ;
if ( F_32 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_9 ) ;
V_54 = - V_143 ;
goto V_88;
}
F_119 ( V_4 -> V_118 . V_119 , V_305 ) ;
V_4 -> V_250 = true ;
F_1 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_66 -> V_67 , L_37 ) ;
V_88:
return V_54 ;
}
int F_120 ( struct V_303 * V_304 ,
int V_8 , T_3 V_260 , T_2 V_309 )
{
struct V_306 * V_307 = F_116 ( V_304 ) ;
struct V_1 * V_2 = V_307 -> V_11 -> V_164 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_167 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_310;
}
if ( ( V_260 > V_261 ) || ( V_309 > 7 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_38 ) ;
V_54 = - V_87 ;
goto V_310;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_62 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_310;
}
if ( V_11 -> V_22 . V_211 == 0 && F_99 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_39 ,
V_8 ) ;
F_1 ( V_2 , V_4 ) ;
}
if ( ( ! ( V_260 || V_309 ) ||
( V_260 | V_309 ) != F_10 ( V_11 -> V_22 . V_211 ) ) &&
V_11 -> V_22 . V_211 )
V_54 = F_105 ( V_11 , V_256 ) ;
if ( V_11 -> V_22 . V_211 ) {
V_54 = F_107 ( V_11 , ( F_10 ( V_11 -> V_22 . V_211 ) &
V_311 ) ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_164 -> V_66 -> V_67 ,
L_40 ,
V_54 , V_2 -> V_6 . V_107 . V_108 ) ;
}
}
if ( V_260 || V_309 )
V_54 = F_30 ( V_11 ,
V_260 | ( V_309 << V_312 ) ) ;
else
F_121 ( V_11 ) ;
if ( V_260 ) {
F_29 ( & V_2 -> V_66 -> V_67 , L_41 ,
V_260 , V_309 , V_8 ) ;
V_54 = F_105 ( V_11 , V_260 ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_164 -> V_66 -> V_67 ,
L_42 , V_54 ,
V_11 -> V_164 -> V_6 . V_107 . V_108 ) ;
goto V_310;
}
F_107 ( V_11 , V_256 ) ;
}
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_43 ) ;
goto V_310;
}
V_4 -> V_117 = F_10 ( V_11 -> V_22 . V_211 ) ;
V_54 = 0 ;
V_310:
return V_54 ;
}
int F_122 ( struct V_303 * V_304 , int V_8 , int V_313 ,
int V_314 )
{
struct V_306 * V_307 = F_116 ( V_304 ) ;
struct V_1 * V_2 = V_307 -> V_11 -> V_164 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_315 = 0 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_167 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_44 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( V_313 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_45 ,
V_313 , V_8 ) ;
return - V_87 ;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_62 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_46 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
switch ( V_2 -> V_6 . V_287 . V_288 . V_298 ) {
case V_299 :
V_315 = 40000 ;
break;
case V_316 :
V_315 = 10000 ;
break;
case V_317 :
V_315 = 1000 ;
break;
default:
break;
}
if ( V_314 > V_315 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_47 ,
V_314 , V_4 -> V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( ( V_314 < 50 ) && ( V_314 > 0 ) ) {
F_67 ( & V_2 -> V_66 -> V_67 , L_48 ) ;
V_314 = 50 ;
}
V_54 = F_33 ( & V_2 -> V_6 , V_11 -> V_106 ,
V_314 / V_318 ,
V_319 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_49 ,
V_54 ) ;
V_54 = - V_143 ;
goto error;
}
V_4 -> V_120 = V_314 ;
error:
return V_54 ;
}
int F_123 ( struct V_303 * V_304 ,
int V_8 , struct V_320 * V_321 )
{
struct V_306 * V_307 = F_116 ( V_304 ) ;
struct V_19 * V_11 = V_307 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_164 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_167 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_62 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_321 -> V_4 = V_8 ;
memcpy ( & V_321 -> V_305 , V_4 -> V_118 . V_119 , V_112 ) ;
V_321 -> V_314 = V_4 -> V_120 ;
V_321 -> V_313 = 0 ;
V_321 -> V_308 = F_10 ( V_11 -> V_22 . V_211 ) & V_322 ;
V_321 -> V_309 = ( F_10 ( V_11 -> V_22 . V_211 ) & V_323 ) >>
V_312 ;
if ( V_4 -> V_293 == false )
V_321 -> V_324 = V_325 ;
else if ( V_4 -> V_297 == true )
V_321 -> V_324 = V_326 ;
else
V_321 -> V_324 = V_327 ;
V_321 -> V_176 = V_4 -> V_176 ;
V_54 = 0 ;
V_88:
return V_54 ;
}
int F_124 ( struct V_303 * V_304 , int V_8 , int V_328 )
{
struct V_306 * V_307 = F_116 ( V_304 ) ;
struct V_1 * V_2 = V_307 -> V_11 -> V_164 ;
struct V_283 V_284 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_189 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_167 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_329;
}
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_189 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
V_284 . V_289 = V_290 ;
V_284 . V_291 = V_292 ;
switch ( V_328 ) {
case V_325 :
V_4 -> V_293 = false ;
V_284 . V_294 . V_295 . V_296 =
V_2 -> V_6 . V_287 . V_288 . V_288 & V_300 ;
V_284 . V_294 . V_295 . V_298 =
V_2 -> V_6 . V_287 . V_288 . V_298 ;
break;
case V_326 :
V_4 -> V_293 = true ;
V_4 -> V_297 = true ;
V_284 . V_294 . V_295 . V_296 = true ;
V_284 . V_294 . V_295 . V_298 = V_299 ;
break;
case V_327 :
V_4 -> V_293 = true ;
V_4 -> V_297 = false ;
V_284 . V_294 . V_295 . V_296 = false ;
V_284 . V_294 . V_295 . V_298 = 0 ;
break;
default:
V_54 = - V_87 ;
goto V_329;
}
F_78 ( V_6 , V_189 , V_273 ,
0 , ( T_2 * ) & V_284 , sizeof( V_284 ) , NULL ) ;
V_329:
return V_54 ;
}
int F_125 ( struct V_303 * V_304 , int V_8 , bool V_330 )
{
struct V_306 * V_307 = F_116 ( V_304 ) ;
struct V_19 * V_11 = V_307 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_164 ;
struct V_151 V_152 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_167 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_181;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
if ( V_330 == V_4 -> V_176 )
goto V_181;
V_4 -> V_176 = V_330 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_106 = V_2 -> V_11 [ V_4 -> V_113 ] -> V_106 ;
V_152 . V_155 = V_2 -> V_6 . V_71 ;
V_152 . V_22 . V_160 = F_56 ( V_331 ) ;
if ( V_330 )
V_152 . V_22 . V_332 |= V_333 ;
V_54 = F_57 ( V_6 , & V_152 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_50 ,
V_54 ) ;
V_54 = - V_143 ;
}
V_181:
return V_54 ;
}
