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
if ( F_49 ( V_146 , & V_2 -> V_147 ) )
return;
F_50 ( V_148 , & V_4 -> V_132 ) ;
if ( ! V_144 ) {
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 |= V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
F_5 ( V_6 ) ;
}
if ( F_46 ( V_4 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_11 ,
V_4 -> V_8 ) ;
for ( V_126 = 0 ; V_126 < 10 ; V_126 ++ ) {
F_51 ( 10000 , 20000 ) ;
V_7 = F_2 ( V_6 , F_52 ( V_4 -> V_8 ) ) ;
if ( V_7 & V_149 ) {
V_145 = true ;
break;
}
}
if ( ! V_145 )
F_21 ( & V_2 -> V_66 -> V_67 , L_12 ,
V_4 -> V_8 ) ;
F_4 ( V_6 , F_53 ( V_4 -> V_8 ) , V_150 ) ;
V_7 = F_2 ( V_6 , F_3 ( V_4 -> V_8 ) ) ;
V_7 &= ~ V_9 ;
F_4 ( V_6 , F_3 ( V_4 -> V_8 ) , V_7 ) ;
if ( V_4 -> V_113 == 0 )
goto V_151;
F_54 ( V_2 -> V_11 [ V_4 -> V_113 ] , false ) ;
V_151:
F_40 ( V_4 ) ;
F_44 ( V_4 ) ;
F_34 ( V_4 ) ;
F_45 ( V_148 , & V_4 -> V_132 ) ;
F_4 ( V_6 , F_53 ( V_4 -> V_8 ) , V_152 ) ;
F_5 ( V_6 ) ;
F_50 ( V_146 , & V_2 -> V_147 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_105 ] ;
struct V_153 V_154 ;
int V_155 ;
V_154 . V_106 = V_2 -> V_156 ;
V_154 . V_157 = V_2 -> V_6 . V_71 ;
V_154 . V_158 = 0 ;
V_155 = F_56 ( & V_2 -> V_6 , & V_154 , NULL ) ;
if ( V_155 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_159 , V_155 , V_2 -> V_6 . V_107 . V_108 ) ;
return;
}
V_154 . V_160 = V_161 ;
V_154 . V_22 . V_162 = F_57 ( V_163 ) ;
V_154 . V_22 . V_164 |= F_57 ( V_165 ) ;
V_155 = F_58 ( & V_11 -> V_166 -> V_6 , & V_154 , NULL ) ;
if ( V_155 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_159 , V_11 -> V_166 -> V_6 . V_107 . V_108 ) ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = V_2 -> V_11 [ V_2 -> V_105 ] ;
struct V_153 V_154 ;
int V_155 ;
V_154 . V_106 = V_2 -> V_156 ;
V_154 . V_157 = V_2 -> V_6 . V_71 ;
V_154 . V_158 = 0 ;
V_155 = F_56 ( & V_2 -> V_6 , & V_154 , NULL ) ;
if ( V_155 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_13 ,
V_159 , V_155 , V_2 -> V_6 . V_107 . V_108 ) ;
return;
}
V_154 . V_160 = V_161 ;
V_154 . V_22 . V_162 = F_57 ( V_163 ) ;
V_154 . V_22 . V_164 &= ~ F_57 ( V_165 ) ;
V_155 = F_58 ( & V_11 -> V_166 -> V_6 , & V_154 , NULL ) ;
if ( V_155 ) {
F_29 ( & V_2 -> V_66 -> V_67 ,
L_14 ,
V_159 , V_11 -> V_166 -> V_6 . V_107 . V_108 ) ;
}
}
void F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_33 , V_167 ;
int V_126 , V_168 , V_8 ;
if ( ! V_2 -> V_4 )
return;
while ( F_49 ( V_146 , & V_2 -> V_147 ) )
F_51 ( 1000 , 2000 ) ;
if ( ! F_61 ( V_2 -> V_66 ) )
F_62 ( V_2 -> V_66 ) ;
F_63 ( 20 ) ;
V_168 = V_2 -> V_169 ;
V_2 -> V_169 = 0 ;
for ( V_126 = 0 ; V_126 < V_168 ; V_126 ++ ) {
if ( F_64 ( V_136 , & V_2 -> V_4 [ V_126 ] . V_132 ) )
F_40 ( & V_2 -> V_4 [ V_126 ] ) ;
F_39 ( & V_2 -> V_4 [ V_126 ] ) ;
}
F_65 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
if ( ! F_61 ( V_2 -> V_66 ) ) {
for ( V_8 = 0 ; V_8 < V_168 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_167 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
F_4 ( V_6 , F_66 ( V_33 ) , ( 1 << V_167 ) ) ;
}
F_59 ( V_2 ) ;
} else {
F_67 ( & V_2 -> V_66 -> V_67 ,
L_15 ) ;
}
F_50 ( V_146 , & V_2 -> V_147 ) ;
}
int F_68 ( struct V_1 * V_2 , T_3 V_169 )
{
struct V_3 * V_170 ;
int V_126 , V_54 = 0 ;
F_69 ( V_2 ) ;
if ( F_70 ( V_2 -> V_66 ) != V_169 ) {
V_54 = F_71 ( V_2 -> V_66 , V_169 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_16 , V_54 ) ;
V_2 -> V_169 = 0 ;
goto V_171;
}
}
V_170 = F_72 ( V_169 , sizeof( struct V_3 ) , V_172 ) ;
if ( ! V_170 ) {
V_54 = - V_173 ;
goto V_174;
}
V_2 -> V_4 = V_170 ;
for ( V_126 = 0 ; V_126 < V_169 ; V_126 ++ ) {
V_170 [ V_126 ] . V_2 = V_2 ;
V_170 [ V_126 ] . V_175 = V_176 ;
V_170 [ V_126 ] . V_8 = V_126 ;
F_45 ( V_177 , & V_170 [ V_126 ] . V_135 ) ;
V_170 [ V_126 ] . V_178 = true ;
F_48 ( & V_170 [ V_126 ] , false ) ;
F_34 ( & V_170 [ V_126 ] ) ;
}
V_2 -> V_169 = V_169 ;
F_55 ( V_2 ) ;
V_174:
if ( V_54 )
F_60 ( V_2 ) ;
V_171:
F_73 ( V_2 ) ;
return V_54 ;
}
static int F_74 ( struct V_179 * V_66 , int V_180 )
{
#ifdef F_75
struct V_1 * V_2 = F_76 ( V_66 ) ;
int V_181 = F_70 ( V_66 ) ;
int V_182 = 0 ;
F_29 ( & V_66 -> V_67 , L_17 , V_180 ) ;
if ( V_181 && V_181 != V_180 )
F_60 ( V_2 ) ;
else if ( V_181 && V_181 == V_180 )
goto V_183;
if ( V_180 > V_2 -> V_184 ) {
V_182 = - V_185 ;
goto V_186;
}
V_182 = F_68 ( V_2 , V_180 ) ;
if ( V_182 ) {
F_67 ( & V_66 -> V_67 , L_18 , V_182 ) ;
goto V_186;
}
V_183:
return V_180 ;
V_186:
return V_182 ;
#endif
return 0 ;
}
int F_77 ( struct V_179 * V_66 , int V_180 )
{
struct V_1 * V_2 = F_76 ( V_66 ) ;
if ( V_180 )
return F_74 ( V_66 , V_180 ) ;
if ( ! F_61 ( V_2 -> V_66 ) ) {
F_60 ( V_2 ) ;
} else {
F_67 ( & V_66 -> V_67 , L_19 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_78 ( struct V_3 * V_4 , T_1 V_187 ,
T_1 V_188 , T_2 * V_189 , T_3 V_190 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_191 ;
T_4 V_155 ;
if ( ! V_4 || V_4 -> V_8 >= V_4 -> V_2 -> V_169 )
return - V_87 ;
V_2 = V_4 -> V_2 ;
V_6 = & V_2 -> V_6 ;
V_191 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( V_188 ) {
V_4 -> V_192 ++ ;
F_21 ( & V_2 -> V_66 -> V_67 , L_20 ,
V_187 , V_188 ) ;
if ( V_4 -> V_192 >
V_193 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_21 ,
V_4 -> V_8 ) ;
F_21 ( & V_2 -> V_66 -> V_67 , L_22 ) ;
F_45 ( V_194 , & V_4 -> V_132 ) ;
}
} else {
V_4 -> V_195 ++ ;
}
V_155 = F_79 ( V_6 , V_191 , V_187 , V_188 ,
V_189 , V_190 , NULL ) ;
if ( V_155 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_23 ,
V_4 -> V_8 , V_2 -> V_6 . V_107 . V_108 ) ;
return - V_143 ;
}
return 0 ;
}
static int F_80 ( struct V_3 * V_4 ,
enum V_196 V_197 ,
T_4 V_198 )
{
return F_78 ( V_4 , V_197 , V_198 , NULL , 0 ) ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_199 V_22 = {
V_200 , V_201
} ;
return F_78 ( V_4 , V_202 ,
V_203 , ( T_2 * ) & V_22 ,
sizeof( struct
V_199 ) ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_204 * V_205 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_4 V_155 = 0 ;
struct V_19 * V_11 ;
int V_126 = 0 , V_206 = 0 ;
int V_207 = 1 ;
int V_54 ;
if ( ! F_64 ( V_136 , & V_4 -> V_132 ) ) {
V_155 = V_208 ;
goto V_182;
}
V_206 = ( sizeof( struct V_204 ) +
sizeof( struct V_209 ) * V_207 ) ;
V_205 = F_83 ( V_206 , V_172 ) ;
if ( ! V_205 ) {
V_155 = V_210 ;
V_206 = 0 ;
goto V_182;
}
V_205 -> V_211 = V_212 ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! V_11 -> V_22 . V_213 )
V_205 -> V_211 |= V_214 ;
V_205 -> V_207 = V_207 ;
V_205 -> V_131 = V_4 -> V_131 ;
V_205 -> V_215 = V_2 -> V_6 . V_15 . V_16 ;
if ( V_4 -> V_113 ) {
V_205 -> V_216 [ V_126 ] . V_10 = V_4 -> V_113 ;
V_205 -> V_216 [ V_126 ] . V_217 = V_110 ;
V_205 -> V_216 [ V_126 ] . V_131 =
V_2 -> V_11 [ V_4 -> V_113 ] -> V_13 ;
memcpy ( V_205 -> V_216 [ V_126 ] . V_218 ,
V_4 -> V_118 . V_119 , V_112 ) ;
V_126 ++ ;
}
F_45 ( V_148 , & V_4 -> V_132 ) ;
V_182:
V_54 = F_78 ( V_4 , V_219 ,
V_155 , ( T_2 * ) V_205 , V_206 ) ;
F_65 ( V_205 ) ;
return V_54 ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( F_64 ( V_148 , & V_4 -> V_132 ) )
F_48 ( V_4 , false ) ;
}
static int F_85 ( struct V_3 * V_4 ,
T_2 * V_189 , T_3 V_190 )
{
struct V_220 * V_22 =
(struct V_220 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_19 * V_11 ;
bool V_221 = false ;
T_4 V_155 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ||
! F_64 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_22 -> V_10 ) ||
( V_2 -> V_11 [ V_22 -> V_10 ] -> type != V_222 ) ) {
V_155 = V_208 ;
goto V_88;
}
V_11 = V_2 -> V_11 [ V_22 -> V_10 ] ;
if ( V_22 -> V_160 & V_223 )
V_221 = true ;
V_155 = F_86 ( V_6 , V_11 -> V_106 ,
V_221 , NULL ) ;
V_88:
return F_80 ( V_4 ,
V_224 ,
V_155 ) ;
}
static int F_87 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_225 * V_226 =
(struct V_225 * ) V_189 ;
struct V_227 * V_228 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 , V_18 ;
T_4 V_155 = 0 ;
int V_126 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ) {
V_155 = V_208 ;
goto V_88;
}
V_10 = V_226 -> V_10 ;
if ( ! F_6 ( V_4 , V_10 ) ) {
V_155 = V_208 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_226 -> V_131 ; V_126 ++ ) {
V_228 = & V_226 -> V_229 [ V_126 ] ;
V_18 = V_228 -> V_230 . V_231 ;
if ( ( V_228 -> V_230 . V_10 != V_10 ) ||
( V_228 -> V_232 . V_10 != V_10 ) ||
( V_228 -> V_232 . V_231 != V_18 ) ||
! F_7 ( V_4 , V_10 , V_18 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( F_24 ( V_4 , V_10 , V_18 ,
& V_228 -> V_232 ) ||
F_19 ( V_4 , V_10 , V_18 ,
& V_228 -> V_230 ) ) {
V_155 = V_208 ;
goto V_88;
}
}
V_2 -> V_11 [ V_4 -> V_113 ] -> V_131 = V_226 -> V_131 ;
V_88:
return F_80 ( V_4 , V_233 ,
V_155 ) ;
}
static int F_88 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_234 * V_235 =
(struct V_234 * ) V_189 ;
struct V_26 * V_236 ;
T_3 V_10 , V_18 , V_14 ;
T_4 V_155 = 0 ;
unsigned long V_29 ;
int V_126 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ) {
V_155 = V_208 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_235 -> V_237 ; V_126 ++ ) {
V_236 = & V_235 -> V_27 [ V_126 ] ;
V_14 = V_236 -> V_14 ;
V_10 = V_236 -> V_10 ;
if ( ! F_8 ( V_4 , V_14 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_155 = V_208 ;
goto V_88;
}
V_29 = V_236 -> V_35 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_155 = V_208 ;
goto V_88;
}
}
V_29 = V_236 -> V_36 ;
F_14 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_7 ( V_4 , V_10 ,
V_18 ) ) {
V_155 = V_208 ;
goto V_88;
}
}
F_11 ( V_4 , V_10 , V_236 ) ;
}
V_88:
return F_80 ( V_4 , V_238 ,
V_155 ) ;
}
static int F_89 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_239 * V_240 =
(struct V_239 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_240 -> V_10 ;
T_4 V_155 = 0 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_10 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( ( 0 == V_240 -> V_241 ) && ( 0 == V_240 -> V_242 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( F_54 ( V_2 -> V_11 [ V_10 ] , true ) )
V_155 = V_243 ;
V_88:
return F_80 ( V_4 , V_244 ,
V_155 ) ;
}
static int F_90 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_239 * V_240 =
(struct V_239 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_10 = V_240 -> V_10 ;
T_4 V_155 = 0 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_240 -> V_10 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( ( 0 == V_240 -> V_241 ) && ( 0 == V_240 -> V_242 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( F_54 ( V_2 -> V_11 [ V_10 ] , false ) )
V_155 = V_243 ;
V_88:
return F_80 ( V_4 , V_245 ,
V_155 ) ;
}
static int F_91 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_239 * V_240 =
(struct V_239 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_246 V_247 ;
T_4 V_155 = 0 ;
struct V_19 * V_11 ;
memset ( & V_247 , 0 , sizeof( struct V_246 ) ) ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ) {
V_155 = V_208 ;
goto V_88;
}
if ( ! F_6 ( V_4 , V_240 -> V_10 ) ) {
V_155 = V_208 ;
goto V_88;
}
V_11 = V_2 -> V_11 [ V_240 -> V_10 ] ;
if ( ! V_11 ) {
V_155 = V_208 ;
goto V_88;
}
F_92 ( V_11 ) ;
V_247 = V_11 -> V_248 ;
V_88:
return F_78 ( V_4 , V_249 , V_155 ,
( T_2 * ) & V_247 , sizeof( V_247 ) ) ;
}
static inline int F_93 ( struct V_3 * V_4 , T_2 * V_250 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_54 = 0 ;
if ( F_94 ( V_250 ) ||
F_95 ( V_250 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 , V_250 ) ;
V_54 = V_251 ;
} else if ( V_4 -> V_252 && ! F_96 ( V_250 ) &&
! F_97 ( V_250 , V_4 -> V_118 . V_119 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_25 ) ;
V_54 = - V_185 ;
}
return V_54 ;
}
static int F_98 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_253 * V_254 =
(struct V_253 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_254 -> V_10 ;
T_4 V_54 = 0 ;
int V_126 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ||
! F_64 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_208 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_254 -> V_255 ; V_126 ++ ) {
V_54 = F_93 ( V_4 , V_254 -> V_256 [ V_126 ] . V_119 ) ;
if ( V_54 )
goto V_88;
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_126 = 0 ; V_126 < V_254 -> V_255 ; V_126 ++ ) {
struct V_103 * V_104 ;
V_104 = F_99 ( V_11 , V_254 -> V_256 [ V_126 ] . V_119 , true , false ) ;
if ( ! V_104 ) {
if ( F_100 ( V_11 ) )
V_104 = F_101 ( V_11 , V_254 -> V_256 [ V_126 ] . V_119 ,
true , false ) ;
else
V_104 = F_31 ( V_11 , V_254 -> V_256 [ V_126 ] . V_119 , - 1 ,
true , false ) ;
}
if ( ! V_104 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_26 ) ;
V_54 = V_208 ;
goto V_88;
}
}
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_80 ( V_4 , V_257 ,
V_54 ) ;
}
static int F_102 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_253 * V_254 =
(struct V_253 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_254 -> V_10 ;
T_4 V_54 = 0 ;
int V_126 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ||
! F_64 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_54 = V_208 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_254 -> V_255 ; V_126 ++ ) {
if ( F_94 ( V_254 -> V_256 [ V_126 ] . V_119 ) ||
F_95 ( V_254 -> V_256 [ V_126 ] . V_119 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_24 ,
V_254 -> V_256 [ V_126 ] . V_119 ) ;
V_54 = V_251 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
for ( V_126 = 0 ; V_126 < V_254 -> V_255 ; V_126 ++ )
F_103 ( V_11 , V_254 -> V_256 [ V_126 ] . V_119 ,
V_258 , true , false ) ;
if ( F_32 ( V_11 ) )
F_21 ( & V_2 -> V_66 -> V_67 , L_27 ) ;
V_88:
return F_80 ( V_4 , V_259 ,
V_54 ) ;
}
static int F_104 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_260 * V_261 =
(struct V_260 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_261 -> V_10 ;
T_4 V_155 = 0 ;
int V_126 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ||
! F_64 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_155 = V_208 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_261 -> V_255 ; V_126 ++ ) {
if ( V_261 -> V_262 [ V_126 ] > V_263 ) {
V_155 = V_208 ;
F_21 ( & V_2 -> V_66 -> V_67 ,
L_28 , V_261 -> V_262 [ V_126 ] ) ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_213 ) {
V_155 = V_208 ;
goto V_88;
}
F_105 ( V_11 ) ;
for ( V_126 = 0 ; V_126 < V_261 -> V_255 ; V_126 ++ ) {
int V_54 = F_106 ( V_11 , V_261 -> V_262 [ V_126 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_29 ,
V_261 -> V_262 [ V_126 ] , V_54 ) ;
}
V_88:
return F_80 ( V_4 , V_264 , V_155 ) ;
}
static int F_107 ( struct V_3 * V_4 , T_2 * V_189 , T_3 V_190 )
{
struct V_260 * V_261 =
(struct V_260 * ) V_189 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_11 = NULL ;
T_3 V_10 = V_261 -> V_10 ;
T_4 V_155 = 0 ;
int V_126 ;
if ( ! F_64 ( V_148 , & V_4 -> V_132 ) ||
! F_64 ( V_134 , & V_4 -> V_135 ) ||
! F_6 ( V_4 , V_10 ) ) {
V_155 = V_208 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_261 -> V_255 ; V_126 ++ ) {
if ( V_261 -> V_262 [ V_126 ] > V_263 ) {
V_155 = V_208 ;
goto V_88;
}
}
V_11 = V_2 -> V_11 [ V_10 ] ;
if ( V_11 -> V_22 . V_213 ) {
V_155 = V_208 ;
goto V_88;
}
for ( V_126 = 0 ; V_126 < V_261 -> V_255 ; V_126 ++ ) {
int V_54 = F_108 ( V_11 , V_261 -> V_262 [ V_126 ] ) ;
if ( V_54 )
F_21 ( & V_2 -> V_66 -> V_67 ,
L_30 ,
V_261 -> V_262 [ V_126 ] , V_54 ) ;
}
V_88:
return F_80 ( V_4 , V_265 , V_155 ) ;
}
static int F_109 ( struct V_3 * V_4 , T_1 V_187 ,
T_1 V_188 , T_2 * V_189 , T_3 V_190 )
{
bool V_266 = false ;
int V_267 ;
if ( F_64 ( V_194 , & V_4 -> V_132 ) )
return V_208 ;
switch ( V_187 ) {
case V_202 :
V_267 = sizeof( struct V_199 ) ;
break;
case V_268 :
case V_219 :
V_267 = 0 ;
break;
case V_269 :
V_267 = sizeof( struct V_50 ) ;
break;
case V_270 :
V_267 = sizeof( struct V_77 ) ;
break;
case V_233 :
V_267 = sizeof( struct V_225 ) ;
if ( V_190 >= V_267 ) {
struct V_225 * V_271 =
(struct V_225 * ) V_189 ;
V_267 += ( V_271 -> V_131 *
sizeof( struct
V_227 ) ) ;
if ( V_271 -> V_131 == 0 )
V_266 = true ;
}
break;
case V_238 :
V_267 = sizeof( struct V_234 ) ;
if ( V_190 >= V_267 ) {
struct V_234 * V_272 =
(struct V_234 * ) V_189 ;
V_267 += ( V_272 -> V_237 *
sizeof( struct V_26 ) ) ;
if ( V_272 -> V_237 == 0 )
V_266 = true ;
}
break;
case V_244 :
case V_245 :
V_267 = sizeof( struct V_239 ) ;
break;
case V_257 :
case V_259 :
V_267 = sizeof( struct V_253 ) ;
if ( V_190 >= V_267 ) {
struct V_253 * V_273 =
(struct V_253 * ) V_189 ;
V_267 += V_273 -> V_255 *
sizeof( struct V_274 ) ;
if ( V_273 -> V_255 == 0 )
V_266 = true ;
}
break;
case V_264 :
case V_265 :
V_267 = sizeof( struct V_260 ) ;
if ( V_190 >= V_267 ) {
struct V_260 * V_261 =
(struct V_260 * ) V_189 ;
V_267 += V_261 -> V_255 * sizeof( T_3 ) ;
if ( V_261 -> V_255 == 0 )
V_266 = true ;
}
break;
case V_224 :
V_267 = sizeof( struct V_220 ) ;
break;
case V_249 :
V_267 = sizeof( struct V_239 ) ;
break;
case V_275 :
case V_276 :
default:
return - V_185 ;
break;
}
if ( ( V_267 != V_190 ) || ( V_266 ) ) {
F_80 ( V_4 , V_187 , V_208 ) ;
return - V_87 ;
} else {
return 0 ;
}
}
int F_110 ( struct V_1 * V_2 , T_3 V_8 , T_1 V_187 ,
T_1 V_188 , T_2 * V_189 , T_3 V_190 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned int V_277 = V_8 - V_6 -> V_15 . V_74 ;
struct V_3 * V_4 ;
int V_54 ;
V_2 -> V_278 ++ ;
if ( V_277 >= V_2 -> V_169 )
return - V_87 ;
V_4 = & ( V_2 -> V_4 [ V_277 ] ) ;
V_54 = F_109 ( V_4 , V_187 , V_188 , V_189 , V_190 ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_31 ,
V_277 , V_187 , V_190 ) ;
return V_54 ;
}
switch ( V_187 ) {
case V_202 :
V_54 = F_81 ( V_4 ) ;
break;
case V_219 :
V_54 = F_82 ( V_4 ) ;
break;
case V_268 :
F_84 ( V_4 ) ;
V_54 = 0 ;
break;
case V_224 :
V_54 = F_85 ( V_4 , V_189 , V_190 ) ;
break;
case V_233 :
V_54 = F_87 ( V_4 , V_189 , V_190 ) ;
break;
case V_238 :
V_54 = F_88 ( V_4 , V_189 , V_190 ) ;
break;
case V_244 :
V_54 = F_89 ( V_4 , V_189 , V_190 ) ;
break;
case V_245 :
V_54 = F_90 ( V_4 , V_189 , V_190 ) ;
break;
case V_257 :
V_54 = F_98 ( V_4 , V_189 , V_190 ) ;
break;
case V_259 :
V_54 = F_102 ( V_4 , V_189 , V_190 ) ;
break;
case V_264 :
V_54 = F_104 ( V_4 , V_189 , V_190 ) ;
break;
case V_265 :
V_54 = F_107 ( V_4 , V_189 , V_190 ) ;
break;
case V_249 :
V_54 = F_91 ( V_4 , V_189 , V_190 ) ;
break;
case V_276 :
default:
F_21 ( & V_2 -> V_66 -> V_67 , L_32 ,
V_187 , V_277 ) ;
V_54 = F_80 ( V_4 , V_187 ,
V_279 ) ;
break;
}
return V_54 ;
}
int F_111 ( struct V_1 * V_2 )
{
T_1 V_7 , V_33 , V_167 , V_8 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
if ( ! F_64 ( V_280 , & V_2 -> V_147 ) )
return 0 ;
V_7 = F_2 ( V_6 , V_281 ) ;
V_7 |= V_282 ;
F_4 ( V_6 , V_281 , V_7 ) ;
F_5 ( V_6 ) ;
F_50 ( V_280 , & V_2 -> V_147 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_169 ; V_8 ++ ) {
V_33 = ( V_6 -> V_15 . V_74 + V_8 ) / 32 ;
V_167 = ( V_6 -> V_15 . V_74 + V_8 ) % 32 ;
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_7 = F_2 ( V_6 , F_66 ( V_33 ) ) ;
if ( V_7 & ( 1 << V_167 ) ) {
F_4 ( V_6 , F_66 ( V_33 ) , ( 1 << V_167 ) ) ;
if ( ! F_64 ( V_283 , & V_2 -> V_147 ) )
F_48 ( V_4 , true ) ;
}
}
return 0 ;
}
static void F_112 ( struct V_1 * V_2 ,
enum V_196 V_187 ,
T_4 V_188 , T_2 * V_189 ,
T_3 V_190 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < V_2 -> V_169 ; V_126 ++ , V_4 ++ ) {
int V_191 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( ! F_64 ( V_136 , & V_4 -> V_132 ) &&
! F_64 ( V_148 , & V_4 -> V_132 ) )
continue;
F_79 ( V_6 , V_191 , V_187 , V_188 ,
V_189 , V_190 , NULL ) ;
}
}
void F_113 ( struct V_1 * V_2 )
{
struct V_284 V_285 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_286 * V_287 = & V_2 -> V_6 . V_288 . V_289 ;
int V_126 ;
V_285 . V_290 = V_291 ;
V_285 . V_292 = V_293 ;
for ( V_126 = 0 ; V_126 < V_2 -> V_169 ; V_126 ++ , V_4 ++ ) {
int V_191 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
if ( V_4 -> V_294 ) {
V_285 . V_295 . V_296 . V_297 = V_4 -> V_298 ;
V_285 . V_295 . V_296 . V_299 =
( V_4 -> V_298 ? V_300 : 0 ) ;
} else {
V_285 . V_295 . V_296 . V_297 =
V_287 -> V_289 & V_301 ;
V_285 . V_295 . V_296 . V_299 = V_287 -> V_299 ;
}
F_79 ( V_6 , V_191 , V_275 ,
0 , ( T_2 * ) & V_285 , sizeof( V_285 ) ,
NULL ) ;
}
}
void F_114 ( struct V_1 * V_2 )
{
struct V_284 V_285 ;
V_285 . V_290 = V_302 ;
V_285 . V_292 = V_303 ;
F_112 ( V_2 , V_275 , V_203 ,
( T_2 * ) & V_285 , sizeof( struct V_284 ) ) ;
}
void F_115 ( struct V_3 * V_4 )
{
struct V_284 V_285 ;
int V_191 ;
if ( ! V_4 || V_4 -> V_8 >= V_4 -> V_2 -> V_169 )
return;
if ( ! F_64 ( V_136 , & V_4 -> V_132 ) &&
! F_64 ( V_148 , & V_4 -> V_132 ) )
return;
V_191 = V_4 -> V_8 + V_4 -> V_2 -> V_6 . V_15 . V_74 ;
V_285 . V_290 = V_302 ;
V_285 . V_292 = V_303 ;
F_79 ( & V_4 -> V_2 -> V_6 , V_191 , V_275 ,
V_203 , ( T_2 * ) & V_285 ,
sizeof( struct V_284 ) , NULL ) ;
}
int F_116 ( struct V_304 * V_305 , int V_8 , T_2 * V_306 )
{
struct V_307 * V_308 = F_117 ( V_305 ) ;
struct V_19 * V_11 = V_308 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_166 ;
struct V_103 * V_104 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_169 ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_64 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
if ( ! F_118 ( V_306 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_35 ) ;
V_54 = - V_87 ;
goto V_88;
}
F_103 ( V_11 , V_4 -> V_118 . V_119 , V_4 -> V_117 ,
true , false ) ;
F_119 (f, &vsi->mac_filter_list, list)
F_103 ( V_11 , V_104 -> V_250 , V_104 -> V_309 , true , false ) ;
F_29 ( & V_2 -> V_66 -> V_67 , L_36 , V_306 , V_8 ) ;
if ( F_32 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_9 ) ;
V_54 = - V_143 ;
goto V_88;
}
F_120 ( V_4 -> V_118 . V_119 , V_306 ) ;
V_4 -> V_252 = true ;
F_1 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_66 -> V_67 , L_37 ) ;
V_88:
return V_54 ;
}
int F_121 ( struct V_304 * V_305 ,
int V_8 , T_3 V_262 , T_2 V_310 )
{
struct V_307 * V_308 = F_117 ( V_305 ) ;
struct V_1 * V_2 = V_308 -> V_11 -> V_166 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_169 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_311;
}
if ( ( V_262 > V_263 ) || ( V_310 > 7 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_38 ) ;
V_54 = - V_87 ;
goto V_311;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_64 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_311;
}
if ( V_11 -> V_22 . V_213 == 0 && F_100 ( V_11 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 ,
L_39 ,
V_8 ) ;
F_1 ( V_2 , V_4 ) ;
}
if ( ( ! ( V_262 || V_310 ) ||
( V_262 | V_310 ) != F_10 ( V_11 -> V_22 . V_213 ) ) &&
V_11 -> V_22 . V_213 )
V_54 = F_106 ( V_11 , V_258 ) ;
if ( V_11 -> V_22 . V_213 ) {
V_54 = F_108 ( V_11 , ( F_10 ( V_11 -> V_22 . V_213 ) &
V_312 ) ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_166 -> V_66 -> V_67 ,
L_40 ,
V_54 , V_2 -> V_6 . V_107 . V_108 ) ;
}
}
if ( V_262 || V_310 )
V_54 = F_30 ( V_11 ,
V_262 | ( V_310 << V_313 ) ) ;
else
F_122 ( V_11 ) ;
if ( V_262 ) {
F_29 ( & V_2 -> V_66 -> V_67 , L_41 ,
V_262 , V_310 , V_8 ) ;
V_54 = F_106 ( V_11 , V_262 ) ;
if ( V_54 ) {
F_29 ( & V_11 -> V_166 -> V_66 -> V_67 ,
L_42 , V_54 ,
V_11 -> V_166 -> V_6 . V_107 . V_108 ) ;
goto V_311;
}
F_108 ( V_11 , V_258 ) ;
}
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_43 ) ;
goto V_311;
}
V_4 -> V_117 = F_10 ( V_11 -> V_22 . V_213 ) ;
V_54 = 0 ;
V_311:
return V_54 ;
}
int F_123 ( struct V_304 * V_305 , int V_8 , int V_314 ,
int V_315 )
{
struct V_307 * V_308 = F_117 ( V_305 ) ;
struct V_1 * V_2 = V_308 -> V_11 -> V_166 ;
struct V_19 * V_11 ;
struct V_3 * V_4 ;
int V_316 = 0 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_169 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_44 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( V_314 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_45 ,
V_314 , V_8 ) ;
return - V_87 ;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_64 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_46 , V_8 ) ;
V_54 = - V_87 ;
goto error;
}
switch ( V_2 -> V_6 . V_288 . V_289 . V_299 ) {
case V_300 :
V_316 = 40000 ;
break;
case V_317 :
V_316 = 10000 ;
break;
case V_318 :
V_316 = 1000 ;
break;
default:
break;
}
if ( V_315 > V_316 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_47 ,
V_315 , V_4 -> V_8 ) ;
V_54 = - V_87 ;
goto error;
}
if ( ( V_315 < 50 ) && ( V_315 > 0 ) ) {
F_67 ( & V_2 -> V_66 -> V_67 , L_48 ) ;
V_315 = 50 ;
}
V_54 = F_33 ( & V_2 -> V_6 , V_11 -> V_106 ,
V_315 / V_319 ,
V_320 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_49 ,
V_54 ) ;
V_54 = - V_143 ;
goto error;
}
V_4 -> V_120 = V_315 ;
error:
return V_54 ;
}
int F_124 ( struct V_304 * V_305 ,
int V_8 , struct V_321 * V_322 )
{
struct V_307 * V_308 = F_117 ( V_305 ) ;
struct V_19 * V_11 = V_308 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_166 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_169 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
V_11 = V_2 -> V_11 [ V_4 -> V_113 ] ;
if ( ! F_64 ( V_136 , & V_4 -> V_132 ) ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_34 , V_8 ) ;
V_54 = - V_87 ;
goto V_88;
}
V_322 -> V_4 = V_8 ;
memcpy ( & V_322 -> V_306 , V_4 -> V_118 . V_119 , V_112 ) ;
V_322 -> V_315 = V_4 -> V_120 ;
V_322 -> V_314 = 0 ;
V_322 -> V_309 = F_10 ( V_11 -> V_22 . V_213 ) & V_323 ;
V_322 -> V_310 = ( F_10 ( V_11 -> V_22 . V_213 ) & V_324 ) >>
V_313 ;
if ( V_4 -> V_294 == false )
V_322 -> V_325 = V_326 ;
else if ( V_4 -> V_298 == true )
V_322 -> V_325 = V_327 ;
else
V_322 -> V_325 = V_328 ;
V_322 -> V_178 = V_4 -> V_178 ;
V_54 = 0 ;
V_88:
return V_54 ;
}
int F_125 ( struct V_304 * V_305 , int V_8 , int V_329 )
{
struct V_307 * V_308 = F_117 ( V_305 ) ;
struct V_1 * V_2 = V_308 -> V_11 -> V_166 ;
struct V_284 V_285 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_191 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_169 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_330;
}
V_4 = & V_2 -> V_4 [ V_8 ] ;
V_191 = V_4 -> V_8 + V_6 -> V_15 . V_74 ;
V_285 . V_290 = V_291 ;
V_285 . V_292 = V_293 ;
switch ( V_329 ) {
case V_326 :
V_4 -> V_294 = false ;
V_285 . V_295 . V_296 . V_297 =
V_2 -> V_6 . V_288 . V_289 . V_289 & V_301 ;
V_285 . V_295 . V_296 . V_299 =
V_2 -> V_6 . V_288 . V_289 . V_299 ;
break;
case V_327 :
V_4 -> V_294 = true ;
V_4 -> V_298 = true ;
V_285 . V_295 . V_296 . V_297 = true ;
V_285 . V_295 . V_296 . V_299 = V_300 ;
break;
case V_328 :
V_4 -> V_294 = true ;
V_4 -> V_298 = false ;
V_285 . V_295 . V_296 . V_297 = false ;
V_285 . V_295 . V_296 . V_299 = 0 ;
break;
default:
V_54 = - V_87 ;
goto V_330;
}
F_79 ( V_6 , V_191 , V_275 ,
0 , ( T_2 * ) & V_285 , sizeof( V_285 ) , NULL ) ;
V_330:
return V_54 ;
}
int F_126 ( struct V_304 * V_305 , int V_8 , bool V_331 )
{
struct V_307 * V_308 = F_117 ( V_305 ) ;
struct V_19 * V_11 = V_308 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_166 ;
struct V_153 V_154 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_54 = 0 ;
if ( V_8 >= V_2 -> V_169 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_33 , V_8 ) ;
V_54 = - V_87 ;
goto V_183;
}
V_4 = & ( V_2 -> V_4 [ V_8 ] ) ;
if ( V_331 == V_4 -> V_178 )
goto V_183;
V_4 -> V_178 = V_331 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_106 = V_2 -> V_11 [ V_4 -> V_113 ] -> V_106 ;
V_154 . V_157 = V_2 -> V_6 . V_71 ;
V_154 . V_22 . V_162 = F_57 ( V_332 ) ;
if ( V_331 )
V_154 . V_22 . V_333 |= V_334 ;
V_54 = F_58 ( V_6 , & V_154 , NULL ) ;
if ( V_54 ) {
F_21 ( & V_2 -> V_66 -> V_67 , L_50 ,
V_54 ) ;
V_54 = - V_143 ;
}
V_183:
return V_54 ;
}
