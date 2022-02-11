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
return V_10 < V_5 -> V_11 . V_12 . V_13 ;
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
( ( V_5 -> V_11 . V_12 . V_13 - 1 ) * V_2 -> V_7 ) +
( V_10 - 1 ) ) ;
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
V_51 . V_61 = 1 ;
V_51 . V_62 = V_19 -> V_55 +
( V_19 -> V_57 * sizeof( struct V_63 ) ) ;
V_53 = F_17 ( V_11 , V_17 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_1 ,
V_17 , V_53 ) ;
V_53 = - V_66 ;
goto V_67;
}
V_53 = F_19 ( V_11 , V_17 , & V_51 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_2 ,
V_17 , V_53 ) ;
V_53 = - V_66 ;
goto V_67;
}
V_52 = V_68 ;
V_52 |= ( ( V_11 -> V_69 << V_70 )
& V_71 ) ;
V_52 |= ( ( ( V_2 -> V_7 + V_11 -> V_12 . V_72 )
<< V_73 )
& V_74 ) ;
F_9 ( V_11 , F_20 ( V_17 ) , V_52 ) ;
F_15 ( V_11 ) ;
V_67:
return V_53 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_14 ,
T_2 V_15 ,
struct V_75 * V_19 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_76 V_77 ;
T_2 V_17 ;
int V_53 = 0 ;
V_17 = F_4 ( V_2 , V_14 , V_15 ) ;
memset ( & V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 . V_54 = V_19 -> V_55 / 128 ;
V_77 . V_56 = V_19 -> V_57 ;
if ( V_19 -> V_78 ) {
V_77 . V_79 = V_80 |
V_81 |
V_82 |
V_83 ;
if ( V_19 -> V_84 > ( ( 2 * 1024 ) - 64 ) ) {
V_53 = - V_85 ;
goto V_86;
}
V_77 . V_87 = V_19 -> V_84 >> V_88 ;
V_77 . V_89 = 0x2 ;
}
if ( V_19 -> V_90 > ( ( 16 * 1024 ) - 128 ) ) {
V_53 = - V_85 ;
goto V_86;
}
V_77 . V_91 = V_19 -> V_90 >> V_92 ;
if ( V_19 -> V_93 >= ( 16 * 1024 ) || V_19 -> V_93 < 64 ) {
V_53 = - V_85 ;
goto V_86;
}
V_77 . V_94 = V_19 -> V_93 ;
V_77 . V_95 = 1 ;
V_77 . V_96 = 1 ;
V_77 . V_97 = 1 ;
V_77 . V_98 = 1 ;
V_77 . V_99 = 1 ;
V_77 . V_100 = 2 ;
V_77 . V_101 = 1 ;
V_53 = F_22 ( V_11 , V_17 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_3 ,
V_17 , V_53 ) ;
V_53 = - V_66 ;
goto V_86;
}
V_53 = F_23 ( V_11 , V_17 , & V_77 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_4 ,
V_17 , V_53 ) ;
V_53 = - V_66 ;
goto V_86;
}
V_86:
return V_53 ;
}
static int F_24 ( struct V_1 * V_2 , enum V_102 type )
{
struct V_103 * V_104 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 ;
int V_53 = 0 ;
V_6 = F_25 ( V_5 , type , V_5 -> V_6 [ V_5 -> V_105 ] -> V_106 , V_2 -> V_7 ) ;
if ( ! V_6 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_5 ,
V_2 -> V_7 , V_5 -> V_11 . V_107 . V_108 ) ;
V_53 = - V_66 ;
goto V_109;
}
if ( type == V_110 ) {
T_1 V_111 [ V_112 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_2 -> V_113 = V_6 -> V_114 ;
V_2 -> V_115 = V_6 -> V_116 ;
F_26 ( & V_5 -> V_64 -> V_65 ,
L_6 ,
V_2 -> V_7 , V_6 -> V_114 , V_6 -> V_116 ) ;
if ( V_2 -> V_117 )
F_27 ( V_6 , V_2 -> V_117 ) ;
V_104 = F_28 ( V_6 , V_2 -> V_118 . V_119 ,
V_2 -> V_117 , true , false ) ;
if ( ! V_104 )
F_26 ( & V_5 -> V_64 -> V_65 ,
L_7 ) ;
V_104 = F_28 ( V_6 , V_111 , V_2 -> V_117 ,
true , false ) ;
if ( ! V_104 )
F_26 ( & V_5 -> V_64 -> V_65 ,
L_8 ) ;
}
V_53 = F_29 ( V_6 ) ;
if ( V_53 )
F_18 ( & V_5 -> V_64 -> V_65 , L_9 ) ;
V_109:
return V_53 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
T_3 V_31 , V_120 = 0 ;
int V_121 ;
F_9 ( V_11 , F_31 ( V_2 -> V_115 ) ,
V_122 ) ;
V_31 = V_123 ;
F_9 ( V_11 , F_32 ( V_2 -> V_7 ) , V_31 ) ;
for ( V_121 = 0 ; V_121 < V_5 -> V_6 [ V_2 -> V_113 ] -> V_9 ; V_121 ++ ) {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_113 , V_121 ) ;
V_31 = ( V_8 & V_124 ) ;
F_9 ( V_11 , F_33 ( V_120 , V_2 -> V_7 ) , V_31 ) ;
V_120 ++ ;
}
for ( V_121 = 0 ; V_121 < 7 ; V_121 ++ ) {
if ( V_121 * 2 >= V_5 -> V_6 [ V_2 -> V_113 ] -> V_9 ) {
V_31 = 0x07FF07FF ;
} else {
T_2 V_8 = F_4 ( V_2 , V_2 -> V_113 ,
V_121 * 2 ) ;
V_31 = V_8 ;
V_8 = F_4 ( V_2 , V_2 -> V_113 ,
( V_121 * 2 ) + 1 ) ;
V_31 |= V_8 << 16 ;
}
F_9 ( V_11 , F_34 ( V_121 , V_2 -> V_115 ) , V_31 ) ;
}
F_15 ( V_11 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
int V_125 ;
F_9 ( V_11 , F_32 ( V_2 -> V_7 ) , 0 ) ;
for ( V_125 = 0 ; V_125 < V_39 ; V_125 ++ )
F_9 ( V_11 , F_33 ( V_125 , V_2 -> V_7 ) ,
V_18 ) ;
F_15 ( V_11 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
T_3 V_32 , V_31 ;
int V_125 , V_126 ;
if ( V_2 -> V_113 ) {
F_37 ( V_5 -> V_6 [ V_2 -> V_113 ] ) ;
V_2 -> V_113 = 0 ;
V_2 -> V_115 = 0 ;
}
V_126 = V_5 -> V_11 . V_12 . V_13 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
if ( 0 == V_125 )
V_32 = F_38 ( V_2 -> V_7 ) ;
else
V_32 = F_39 ( ( ( V_126 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_125 - 1 ) ) ;
F_9 ( V_11 , V_32 , V_127 ) ;
F_15 ( V_11 ) ;
}
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
if ( 0 == V_125 )
V_32 = F_7 ( V_2 -> V_7 ) ;
else
V_32 = F_8 ( ( ( V_126 - 1 ) *
( V_2 -> V_7 ) )
+ ( V_125 - 1 ) ) ;
V_31 = ( V_128 |
V_129 ) ;
F_9 ( V_11 , V_32 , V_31 ) ;
F_15 ( V_11 ) ;
}
V_2 -> V_9 = 0 ;
V_2 -> V_130 = 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_120 = 0 ;
int V_53 ;
V_53 = F_24 ( V_2 , V_110 ) ;
if ( V_53 )
goto V_131;
V_120 += V_5 -> V_6 [ V_2 -> V_113 ] -> V_9 ;
F_41 ( V_132 , & V_2 -> V_133 ) ;
V_2 -> V_9 = V_120 ;
F_41 ( V_134 , & V_2 -> V_130 ) ;
V_131:
if ( V_53 )
F_36 ( V_2 ) ;
return V_53 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
int V_135 , V_125 ;
T_3 V_31 ;
V_135 = V_2 -> V_7 + V_11 -> V_12 . V_72 ;
F_9 ( V_11 , V_136 ,
V_137 | ( V_135 << V_138 ) ) ;
for ( V_125 = 0 ; V_125 < 100 ; V_125 ++ ) {
V_31 = F_43 ( V_11 , V_139 ) ;
if ( ( V_31 & V_140 ) == 0 )
return 0 ;
F_44 ( 1 ) ;
}
return - V_141 ;
}
void F_45 ( struct V_1 * V_2 , bool V_142 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
bool V_143 = false ;
int V_125 ;
T_3 V_31 ;
F_46 ( V_144 , & V_2 -> V_130 ) ;
if ( ! V_142 ) {
V_31 = F_43 ( V_11 , F_47 ( V_2 -> V_7 ) ) ;
V_31 |= V_145 ;
F_9 ( V_11 , F_47 ( V_2 -> V_7 ) , V_31 ) ;
F_15 ( V_11 ) ;
}
if ( F_42 ( V_2 ) )
F_18 ( & V_5 -> V_64 -> V_65 , L_10 ,
V_2 -> V_7 ) ;
for ( V_125 = 0 ; V_125 < 100 ; V_125 ++ ) {
F_44 ( 10 ) ;
V_31 = F_43 ( V_11 , F_48 ( V_2 -> V_7 ) ) ;
if ( V_31 & V_146 ) {
V_143 = true ;
break;
}
}
if ( ! V_143 )
F_18 ( & V_5 -> V_64 -> V_65 , L_11 ,
V_2 -> V_7 ) ;
F_9 ( V_11 , F_49 ( V_2 -> V_7 ) , V_147 ) ;
V_31 = F_43 ( V_11 , F_47 ( V_2 -> V_7 ) ) ;
V_31 &= ~ V_145 ;
F_9 ( V_11 , F_47 ( V_2 -> V_7 ) , V_31 ) ;
if ( V_2 -> V_113 == 0 )
goto V_148;
F_50 ( V_5 -> V_6 [ V_2 -> V_113 ] , false ) ;
V_148:
F_36 ( V_2 ) ;
F_40 ( V_2 ) ;
F_30 ( V_2 ) ;
F_41 ( V_144 , & V_2 -> V_130 ) ;
F_9 ( V_11 , F_49 ( V_2 -> V_7 ) , V_149 ) ;
F_15 ( V_11 ) ;
}
static bool F_51 ( struct V_4 * V_5 )
{
struct V_150 * V_64 = V_5 -> V_64 ;
struct V_150 * V_151 ;
V_151 = F_52 ( V_152 , V_153 , NULL ) ;
while ( V_151 ) {
if ( V_151 -> V_154 && F_53 ( V_151 ) == V_64 ) {
if ( V_151 -> V_155 & V_156 )
return true ;
}
V_151 = F_52 ( V_152 ,
V_153 ,
V_151 ) ;
}
return false ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_16 * V_6 = V_5 -> V_6 [ V_5 -> V_105 ] ;
struct V_157 V_158 ;
int V_159 ;
V_158 . V_106 = V_5 -> V_160 ;
V_158 . V_161 = V_5 -> V_11 . V_69 ;
V_158 . V_162 = 0 ;
V_159 = F_55 ( & V_5 -> V_11 , & V_158 , NULL ) ;
if ( V_159 ) {
F_26 ( & V_5 -> V_64 -> V_65 ,
L_12 ,
V_163 , V_159 , V_5 -> V_11 . V_107 . V_108 ) ;
return;
}
V_158 . V_164 = V_165 ;
V_158 . V_19 . V_166 = F_56 ( V_167 ) ;
V_158 . V_19 . V_168 |= F_56 ( V_169 ) ;
V_159 = F_57 ( & V_6 -> V_170 -> V_11 , & V_158 , NULL ) ;
if ( V_159 ) {
F_26 ( & V_5 -> V_64 -> V_65 ,
L_13 ,
V_163 , V_6 -> V_170 -> V_11 . V_107 . V_108 ) ;
}
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_16 * V_6 = V_5 -> V_6 [ V_5 -> V_105 ] ;
struct V_157 V_158 ;
int V_159 ;
V_158 . V_106 = V_5 -> V_160 ;
V_158 . V_161 = V_5 -> V_11 . V_69 ;
V_158 . V_162 = 0 ;
V_159 = F_55 ( & V_5 -> V_11 , & V_158 , NULL ) ;
if ( V_159 ) {
F_26 ( & V_5 -> V_64 -> V_65 ,
L_12 ,
V_163 , V_159 , V_5 -> V_11 . V_107 . V_108 ) ;
return;
}
V_158 . V_164 = V_165 ;
V_158 . V_19 . V_166 = F_56 ( V_167 ) ;
V_158 . V_19 . V_168 &= ~ F_56 ( V_169 ) ;
V_159 = F_57 ( & V_6 -> V_170 -> V_11 , & V_158 , NULL ) ;
if ( V_159 ) {
F_26 ( & V_5 -> V_64 -> V_65 ,
L_13 ,
V_163 , V_6 -> V_170 -> V_11 . V_107 . V_108 ) ;
}
}
void F_59 ( struct V_4 * V_5 )
{
struct V_27 * V_11 = & V_5 -> V_11 ;
T_3 V_32 , V_171 ;
int V_125 , V_172 , V_7 ;
if ( ! V_5 -> V_2 )
return;
F_60 ( V_5 ) ;
F_61 ( 10 ) ;
V_172 = V_5 -> V_173 ;
V_5 -> V_173 = 0 ;
for ( V_125 = 0 ; V_125 < V_172 ; V_125 ++ ) {
if ( F_62 ( V_134 , & V_5 -> V_2 [ V_125 ] . V_130 ) )
F_36 ( & V_5 -> V_2 [ V_125 ] ) ;
F_35 ( & V_5 -> V_2 [ V_125 ] ) ;
}
F_63 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
if ( ! F_51 ( V_5 ) ) {
F_64 ( V_5 -> V_64 ) ;
for ( V_7 = 0 ; V_7 < V_172 ; V_7 ++ ) {
V_32 = ( V_11 -> V_12 . V_72 + V_7 ) / 32 ;
V_171 = ( V_11 -> V_12 . V_72 + V_7 ) % 32 ;
F_9 ( V_11 , F_65 ( V_32 ) , ( 1 << V_171 ) ) ;
}
F_58 ( V_5 ) ;
} else {
F_66 ( & V_5 -> V_64 -> V_65 ,
L_14 ) ;
}
F_67 ( V_5 ) ;
}
int F_68 ( struct V_4 * V_5 , T_2 V_173 )
{
struct V_1 * V_174 ;
int V_125 , V_53 = 0 ;
F_60 ( V_5 ) ;
if ( F_69 ( V_5 -> V_64 ) != V_173 ) {
V_53 = F_70 ( V_5 -> V_64 , V_173 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_15 , V_53 ) ;
V_5 -> V_173 = 0 ;
goto V_175;
}
}
V_174 = F_71 ( V_173 , sizeof( struct V_1 ) , V_176 ) ;
if ( ! V_174 ) {
V_53 = - V_177 ;
goto V_178;
}
for ( V_125 = 0 ; V_125 < V_173 ; V_125 ++ ) {
V_174 [ V_125 ] . V_5 = V_5 ;
V_174 [ V_125 ] . V_179 = V_180 ;
V_174 [ V_125 ] . V_7 = V_125 ;
F_41 ( V_181 , & V_174 [ V_125 ] . V_133 ) ;
F_45 ( & V_174 [ V_125 ] , false ) ;
F_30 ( & V_174 [ V_125 ] ) ;
}
V_5 -> V_2 = V_174 ;
V_5 -> V_173 = V_173 ;
F_54 ( V_5 ) ;
V_178:
if ( V_53 )
F_59 ( V_5 ) ;
V_175:
F_67 ( V_5 ) ;
return V_53 ;
}
static int F_72 ( struct V_150 * V_64 , int V_182 )
{
#ifdef F_73
struct V_4 * V_5 = F_74 ( V_64 ) ;
int V_183 = F_69 ( V_64 ) ;
int V_184 = 0 ;
F_26 ( & V_64 -> V_65 , L_16 , V_182 ) ;
if ( V_183 && V_183 != V_182 )
F_59 ( V_5 ) ;
else if ( V_183 && V_183 == V_182 )
goto V_185;
if ( V_182 > V_5 -> V_186 ) {
V_184 = - V_187 ;
goto V_188;
}
V_184 = F_68 ( V_5 , V_182 ) ;
if ( V_184 ) {
F_66 ( & V_64 -> V_65 , L_17 , V_184 ) ;
goto V_188;
}
V_185:
return V_182 ;
V_188:
return V_184 ;
#endif
return 0 ;
}
int F_75 ( struct V_150 * V_64 , int V_182 )
{
struct V_4 * V_5 = F_74 ( V_64 ) ;
if ( V_182 )
return F_72 ( V_64 , V_182 ) ;
F_59 ( V_5 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , T_3 V_189 ,
T_3 V_190 , T_1 * V_191 , T_2 V_192 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
int V_193 = V_2 -> V_7 + V_11 -> V_12 . V_72 ;
T_4 V_159 ;
if ( V_190 ) {
V_2 -> V_194 ++ ;
F_18 ( & V_5 -> V_64 -> V_65 , L_18 ,
V_189 , V_190 ) ;
if ( V_2 -> V_194 >
V_195 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_19 ,
V_2 -> V_7 ) ;
F_18 ( & V_5 -> V_64 -> V_65 , L_20 ) ;
F_41 ( V_196 , & V_2 -> V_130 ) ;
}
} else {
V_2 -> V_197 ++ ;
}
V_159 = F_77 ( V_11 , V_193 , V_189 , V_190 ,
V_191 , V_192 , NULL ) ;
if ( V_159 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_21 ,
V_2 -> V_7 , V_5 -> V_11 . V_107 . V_108 ) ;
return - V_141 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
enum V_198 V_199 ,
T_4 V_200 )
{
return F_76 ( V_2 , V_199 , V_200 , NULL , 0 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_201 V_19 = {
V_202 , V_203
} ;
return F_76 ( V_2 , V_204 ,
V_205 , ( T_1 * ) & V_19 ,
sizeof( struct
V_201 ) ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_206 * V_207 = NULL ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_159 = 0 ;
struct V_16 * V_6 ;
int V_125 = 0 , V_208 = 0 ;
int V_209 = 1 ;
int V_53 ;
if ( ! F_62 ( V_134 , & V_2 -> V_130 ) ) {
V_159 = V_210 ;
goto V_184;
}
V_208 = ( sizeof( struct V_206 ) +
sizeof( struct V_211 ) * V_209 ) ;
V_207 = F_81 ( V_208 , V_176 ) ;
if ( ! V_207 ) {
V_159 = V_212 ;
V_208 = 0 ;
goto V_184;
}
V_207 -> V_213 = V_214 ;
V_6 = V_5 -> V_6 [ V_2 -> V_113 ] ;
if ( ! V_6 -> V_19 . V_215 )
V_207 -> V_213 |= V_216 ;
V_207 -> V_209 = V_209 ;
V_207 -> V_9 = V_2 -> V_9 ;
V_207 -> V_217 = V_5 -> V_11 . V_12 . V_13 ;
if ( V_2 -> V_113 ) {
V_207 -> V_218 [ V_125 ] . V_3 = V_2 -> V_113 ;
V_207 -> V_218 [ V_125 ] . V_219 = V_110 ;
V_207 -> V_218 [ V_125 ] . V_9 =
V_5 -> V_6 [ V_2 -> V_113 ] -> V_9 ;
memcpy ( V_207 -> V_218 [ V_125 ] . V_220 ,
V_2 -> V_118 . V_119 , V_112 ) ;
V_125 ++ ;
}
F_41 ( V_144 , & V_2 -> V_130 ) ;
V_184:
V_53 = F_76 ( V_2 , V_221 ,
V_159 , ( T_1 * ) V_207 , V_208 ) ;
F_63 ( V_207 ) ;
return V_53 ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( F_62 ( V_144 , & V_2 -> V_130 ) )
F_45 ( V_2 , false ) ;
}
static int F_83 ( struct V_1 * V_2 ,
T_1 * V_191 , T_2 V_192 )
{
struct V_222 * V_19 =
(struct V_222 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
bool V_223 = false ;
bool V_224 = false ;
T_4 V_159 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ||
! F_62 ( V_132 , & V_2 -> V_133 ) ||
! F_1 ( V_2 , V_19 -> V_3 ) ||
( V_5 -> V_6 [ V_19 -> V_3 ] -> type != V_225 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( V_19 -> V_164 & V_226 )
V_224 = true ;
V_159 = F_84 ( V_11 , V_19 -> V_3 ,
V_224 , NULL ) ;
if ( V_159 )
goto V_86;
if ( V_19 -> V_164 & V_227 )
V_223 = true ;
V_159 = F_85 ( V_11 , V_19 -> V_3 ,
V_223 , NULL ) ;
V_86:
return F_78 ( V_2 ,
V_228 ,
V_159 ) ;
}
static int F_86 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_229 * V_230 =
(struct V_229 * ) V_191 ;
struct V_231 * V_232 ;
T_2 V_3 , V_15 ;
T_4 V_159 = 0 ;
int V_125 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ) {
V_159 = V_210 ;
goto V_86;
}
V_3 = V_230 -> V_3 ;
if ( ! F_1 ( V_2 , V_3 ) ) {
V_159 = V_210 ;
goto V_86;
}
for ( V_125 = 0 ; V_125 < V_230 -> V_9 ; V_125 ++ ) {
V_232 = & V_230 -> V_233 [ V_125 ] ;
V_15 = V_232 -> V_234 . V_235 ;
if ( ( V_232 -> V_234 . V_3 != V_3 ) ||
( V_232 -> V_236 . V_3 != V_3 ) ||
( V_232 -> V_236 . V_235 != V_15 ) ||
! F_2 ( V_2 , V_3 , V_15 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( F_21 ( V_2 , V_3 , V_15 ,
& V_232 -> V_236 ) ||
F_16 ( V_2 , V_3 , V_15 ,
& V_232 -> V_234 ) ) {
V_159 = V_210 ;
goto V_86;
}
}
V_86:
return F_78 ( V_2 , V_237 ,
V_159 ) ;
}
static int F_87 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_238 * V_239 =
(struct V_238 * ) V_191 ;
struct V_23 * V_240 ;
T_2 V_3 , V_15 , V_10 ;
T_4 V_159 = 0 ;
unsigned long V_26 ;
int V_125 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ) {
V_159 = V_210 ;
goto V_86;
}
for ( V_125 = 0 ; V_125 < V_239 -> V_241 ; V_125 ++ ) {
V_240 = & V_239 -> V_24 [ V_125 ] ;
V_10 = V_240 -> V_10 ;
V_3 = V_240 -> V_3 ;
if ( ! F_3 ( V_2 , V_10 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_159 = V_210 ;
goto V_86;
}
V_26 = V_240 -> V_34 ;
F_10 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_159 = V_210 ;
goto V_86;
}
}
V_26 = V_240 -> V_35 ;
F_10 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_2 ( V_2 , V_3 ,
V_15 ) ) {
V_159 = V_210 ;
goto V_86;
}
}
F_6 ( V_2 , V_3 , V_240 ) ;
}
V_86:
return F_78 ( V_2 , V_242 ,
V_159 ) ;
}
static int F_88 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_243 * V_244 =
(struct V_243 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_244 -> V_3 ;
T_4 V_159 = 0 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( ! F_1 ( V_2 , V_3 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( ( 0 == V_244 -> V_245 ) && ( 0 == V_244 -> V_246 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( F_50 ( V_5 -> V_6 [ V_3 ] , true ) )
V_159 = V_247 ;
V_86:
return F_78 ( V_2 , V_248 ,
V_159 ) ;
}
static int F_89 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_243 * V_244 =
(struct V_243 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_3 = V_244 -> V_3 ;
T_4 V_159 = 0 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( ! F_1 ( V_2 , V_244 -> V_3 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( ( 0 == V_244 -> V_245 ) && ( 0 == V_244 -> V_246 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( F_50 ( V_5 -> V_6 [ V_3 ] , false ) )
V_159 = V_247 ;
V_86:
return F_78 ( V_2 , V_249 ,
V_159 ) ;
}
static int F_90 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_243 * V_244 =
(struct V_243 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_250 V_251 ;
T_4 V_159 = 0 ;
struct V_16 * V_6 ;
memset ( & V_251 , 0 , sizeof( struct V_250 ) ) ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ) {
V_159 = V_210 ;
goto V_86;
}
if ( ! F_1 ( V_2 , V_244 -> V_3 ) ) {
V_159 = V_210 ;
goto V_86;
}
V_6 = V_5 -> V_6 [ V_244 -> V_3 ] ;
if ( ! V_6 ) {
V_159 = V_210 ;
goto V_86;
}
F_91 ( V_6 ) ;
V_251 = V_6 -> V_252 ;
V_86:
return F_76 ( V_2 , V_253 , V_159 ,
( T_1 * ) & V_251 , sizeof( V_251 ) ) ;
}
static inline int F_92 ( struct V_1 * V_2 , T_1 * V_254 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_53 = 0 ;
if ( F_93 ( V_254 ) ||
F_94 ( V_254 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_22 , V_254 ) ;
V_53 = V_255 ;
} else if ( V_2 -> V_256 && ! F_95 ( V_254 ) &&
! F_96 ( V_254 , V_2 -> V_118 . V_119 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_23 ) ;
V_53 = - V_187 ;
}
return V_53 ;
}
static int F_97 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_257 * V_258 =
(struct V_257 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_258 -> V_3 ;
T_4 V_53 = 0 ;
int V_125 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ||
! F_62 ( V_132 , & V_2 -> V_133 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_53 = V_210 ;
goto V_86;
}
for ( V_125 = 0 ; V_125 < V_258 -> V_259 ; V_125 ++ ) {
V_53 = F_92 ( V_2 , V_258 -> V_260 [ V_125 ] . V_119 ) ;
if ( V_53 )
goto V_86;
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_125 = 0 ; V_125 < V_258 -> V_259 ; V_125 ++ ) {
struct V_103 * V_104 ;
V_104 = F_98 ( V_6 , V_258 -> V_260 [ V_125 ] . V_119 , true , false ) ;
if ( ! V_104 ) {
if ( F_99 ( V_6 ) )
V_104 = F_100 ( V_6 , V_258 -> V_260 [ V_125 ] . V_119 ,
true , false ) ;
else
V_104 = F_28 ( V_6 , V_258 -> V_260 [ V_125 ] . V_119 , - 1 ,
true , false ) ;
}
if ( ! V_104 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_24 ) ;
V_53 = V_210 ;
goto V_86;
}
}
if ( F_29 ( V_6 ) )
F_18 ( & V_5 -> V_64 -> V_65 , L_25 ) ;
V_86:
return F_78 ( V_2 , V_261 ,
V_53 ) ;
}
static int F_101 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_257 * V_258 =
(struct V_257 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_258 -> V_3 ;
T_4 V_53 = 0 ;
int V_125 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ||
! F_62 ( V_132 , & V_2 -> V_133 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_53 = V_210 ;
goto V_86;
}
for ( V_125 = 0 ; V_125 < V_258 -> V_259 ; V_125 ++ ) {
if ( F_93 ( V_258 -> V_260 [ V_125 ] . V_119 ) ||
F_94 ( V_258 -> V_260 [ V_125 ] . V_119 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_22 ,
V_258 -> V_260 [ V_125 ] . V_119 ) ;
V_53 = V_255 ;
goto V_86;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
for ( V_125 = 0 ; V_125 < V_258 -> V_259 ; V_125 ++ )
F_102 ( V_6 , V_258 -> V_260 [ V_125 ] . V_119 ,
V_262 , true , false ) ;
if ( F_29 ( V_6 ) )
F_18 ( & V_5 -> V_64 -> V_65 , L_25 ) ;
V_86:
return F_78 ( V_2 , V_263 ,
V_53 ) ;
}
static int F_103 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_264 * V_265 =
(struct V_264 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_265 -> V_3 ;
T_4 V_159 = 0 ;
int V_125 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ||
! F_62 ( V_132 , & V_2 -> V_133 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_159 = V_210 ;
goto V_86;
}
for ( V_125 = 0 ; V_125 < V_265 -> V_259 ; V_125 ++ ) {
if ( V_265 -> V_266 [ V_125 ] > V_267 ) {
V_159 = V_210 ;
F_18 ( & V_5 -> V_64 -> V_65 ,
L_26 , V_265 -> V_266 [ V_125 ] ) ;
goto V_86;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_215 ) {
V_159 = V_210 ;
goto V_86;
}
F_104 ( V_6 ) ;
for ( V_125 = 0 ; V_125 < V_265 -> V_259 ; V_125 ++ ) {
int V_53 = F_105 ( V_6 , V_265 -> V_266 [ V_125 ] ) ;
if ( V_53 )
F_18 ( & V_5 -> V_64 -> V_65 ,
L_27 ,
V_265 -> V_266 [ V_125 ] , V_53 ) ;
}
V_86:
return F_78 ( V_2 , V_268 , V_159 ) ;
}
static int F_106 ( struct V_1 * V_2 , T_1 * V_191 , T_2 V_192 )
{
struct V_264 * V_265 =
(struct V_264 * ) V_191 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_16 * V_6 = NULL ;
T_2 V_3 = V_265 -> V_3 ;
T_4 V_159 = 0 ;
int V_125 ;
if ( ! F_62 ( V_144 , & V_2 -> V_130 ) ||
! F_62 ( V_132 , & V_2 -> V_133 ) ||
! F_1 ( V_2 , V_3 ) ) {
V_159 = V_210 ;
goto V_86;
}
for ( V_125 = 0 ; V_125 < V_265 -> V_259 ; V_125 ++ ) {
if ( V_265 -> V_266 [ V_125 ] > V_267 ) {
V_159 = V_210 ;
goto V_86;
}
}
V_6 = V_5 -> V_6 [ V_3 ] ;
if ( V_6 -> V_19 . V_215 ) {
V_159 = V_210 ;
goto V_86;
}
for ( V_125 = 0 ; V_125 < V_265 -> V_259 ; V_125 ++ ) {
int V_53 = F_107 ( V_6 , V_265 -> V_266 [ V_125 ] ) ;
if ( V_53 )
F_18 ( & V_5 -> V_64 -> V_65 ,
L_28 ,
V_265 -> V_266 [ V_125 ] , V_53 ) ;
}
V_86:
return F_78 ( V_2 , V_269 , V_159 ) ;
}
static int F_108 ( struct V_1 * V_2 , T_3 V_189 ,
T_3 V_190 , T_1 * V_191 , T_2 V_192 )
{
bool V_270 = false ;
int V_271 ;
if ( F_62 ( V_196 , & V_2 -> V_130 ) )
return V_210 ;
switch ( V_189 ) {
case V_204 :
V_271 = sizeof( struct V_201 ) ;
break;
case V_272 :
case V_221 :
V_271 = 0 ;
break;
case V_273 :
V_271 = sizeof( struct V_49 ) ;
break;
case V_274 :
V_271 = sizeof( struct V_75 ) ;
break;
case V_237 :
V_271 = sizeof( struct V_229 ) ;
if ( V_192 >= V_271 ) {
struct V_229 * V_275 =
(struct V_229 * ) V_191 ;
V_271 += ( V_275 -> V_9 *
sizeof( struct
V_231 ) ) ;
if ( V_275 -> V_9 == 0 )
V_270 = true ;
}
break;
case V_242 :
V_271 = sizeof( struct V_238 ) ;
if ( V_192 >= V_271 ) {
struct V_238 * V_276 =
(struct V_238 * ) V_191 ;
V_271 += ( V_276 -> V_241 *
sizeof( struct V_23 ) ) ;
if ( V_276 -> V_241 == 0 )
V_270 = true ;
}
break;
case V_248 :
case V_249 :
V_271 = sizeof( struct V_243 ) ;
break;
case V_261 :
case V_263 :
V_271 = sizeof( struct V_257 ) ;
if ( V_192 >= V_271 ) {
struct V_257 * V_277 =
(struct V_257 * ) V_191 ;
V_271 += V_277 -> V_259 *
sizeof( struct V_278 ) ;
if ( V_277 -> V_259 == 0 )
V_270 = true ;
}
break;
case V_268 :
case V_269 :
V_271 = sizeof( struct V_264 ) ;
if ( V_192 >= V_271 ) {
struct V_264 * V_265 =
(struct V_264 * ) V_191 ;
V_271 += V_265 -> V_259 * sizeof( T_2 ) ;
if ( V_265 -> V_259 == 0 )
V_270 = true ;
}
break;
case V_228 :
V_271 = sizeof( struct V_222 ) ;
break;
case V_253 :
V_271 = sizeof( struct V_243 ) ;
break;
case V_279 :
case V_280 :
default:
return - V_187 ;
break;
}
if ( ( V_271 != V_192 ) || ( V_270 ) ) {
F_78 ( V_2 , V_189 , V_210 ) ;
return - V_85 ;
} else {
return 0 ;
}
}
int F_109 ( struct V_4 * V_5 , T_2 V_7 , T_3 V_189 ,
T_3 V_190 , T_1 * V_191 , T_2 V_192 )
{
struct V_27 * V_11 = & V_5 -> V_11 ;
unsigned int V_281 = V_7 - V_11 -> V_12 . V_72 ;
struct V_1 * V_2 ;
int V_53 ;
V_5 -> V_282 ++ ;
if ( V_281 >= V_5 -> V_173 )
return - V_85 ;
V_2 = & ( V_5 -> V_2 [ V_281 ] ) ;
V_53 = F_108 ( V_2 , V_189 , V_190 , V_191 , V_192 ) ;
if ( V_53 ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_29 ,
V_281 , V_189 , V_192 ) ;
return V_53 ;
}
switch ( V_189 ) {
case V_204 :
V_53 = F_79 ( V_2 ) ;
break;
case V_221 :
V_53 = F_80 ( V_2 ) ;
break;
case V_272 :
F_82 ( V_2 ) ;
V_53 = 0 ;
break;
case V_228 :
V_53 = F_83 ( V_2 , V_191 , V_192 ) ;
break;
case V_237 :
V_53 = F_86 ( V_2 , V_191 , V_192 ) ;
break;
case V_242 :
V_53 = F_87 ( V_2 , V_191 , V_192 ) ;
break;
case V_248 :
V_53 = F_88 ( V_2 , V_191 , V_192 ) ;
break;
case V_249 :
V_53 = F_89 ( V_2 , V_191 , V_192 ) ;
break;
case V_261 :
V_53 = F_97 ( V_2 , V_191 , V_192 ) ;
break;
case V_263 :
V_53 = F_101 ( V_2 , V_191 , V_192 ) ;
break;
case V_268 :
V_53 = F_103 ( V_2 , V_191 , V_192 ) ;
break;
case V_269 :
V_53 = F_106 ( V_2 , V_191 , V_192 ) ;
break;
case V_253 :
V_53 = F_90 ( V_2 , V_191 , V_192 ) ;
break;
case V_280 :
default:
F_18 ( & V_5 -> V_64 -> V_65 , L_30 ,
V_189 , V_281 ) ;
V_53 = F_78 ( V_2 , V_189 ,
V_283 ) ;
break;
}
return V_53 ;
}
int F_110 ( struct V_4 * V_5 )
{
T_3 V_31 , V_32 , V_171 , V_7 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 ;
if ( ! F_62 ( V_284 , & V_5 -> V_285 ) )
return 0 ;
F_46 ( V_284 , & V_5 -> V_285 ) ;
for ( V_7 = 0 ; V_7 < V_5 -> V_173 ; V_7 ++ ) {
V_32 = ( V_11 -> V_12 . V_72 + V_7 ) / 32 ;
V_171 = ( V_11 -> V_12 . V_72 + V_7 ) % 32 ;
V_2 = & V_5 -> V_2 [ V_7 ] ;
V_31 = F_43 ( V_11 , F_65 ( V_32 ) ) ;
if ( V_31 & ( 1 << V_171 ) ) {
F_9 ( V_11 , F_65 ( V_32 ) , ( 1 << V_171 ) ) ;
if ( ! F_62 ( V_286 , & V_5 -> V_285 ) )
F_45 ( V_2 , true ) ;
}
}
V_31 = F_43 ( V_11 , V_287 ) ;
V_31 |= V_288 ;
F_9 ( V_11 , V_287 , V_31 ) ;
F_15 ( V_11 ) ;
return 0 ;
}
static void F_111 ( struct V_4 * V_5 ,
enum V_198 V_189 ,
T_4 V_190 , T_1 * V_191 ,
T_2 V_192 )
{
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_5 -> V_173 ; V_125 ++ ) {
F_77 ( V_11 , V_2 -> V_7 , V_189 , V_190 ,
V_191 , V_192 , NULL ) ;
V_2 ++ ;
}
}
void F_112 ( struct V_4 * V_5 )
{
struct V_289 V_290 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_291 * V_292 = & V_5 -> V_11 . V_293 . V_294 ;
int V_125 ;
V_290 . V_295 = V_296 ;
V_290 . V_297 = V_298 ;
for ( V_125 = 0 ; V_125 < V_5 -> V_173 ; V_125 ++ ) {
if ( V_2 -> V_299 ) {
V_290 . V_300 . V_301 . V_302 = V_2 -> V_303 ;
V_290 . V_300 . V_301 . V_304 =
( V_2 -> V_303 ? V_305 : 0 ) ;
} else {
V_290 . V_300 . V_301 . V_302 =
V_292 -> V_294 & V_306 ;
V_290 . V_300 . V_301 . V_304 = V_292 -> V_304 ;
}
F_77 ( V_11 , V_2 -> V_7 , V_279 ,
0 , ( T_1 * ) & V_290 , sizeof( V_290 ) ,
NULL ) ;
V_2 ++ ;
}
}
void F_113 ( struct V_4 * V_5 )
{
struct V_289 V_290 ;
V_290 . V_295 = V_307 ;
V_290 . V_297 = V_308 ;
F_111 ( V_5 , V_279 , V_205 ,
( T_1 * ) & V_290 , sizeof( struct V_289 ) ) ;
}
void F_114 ( struct V_1 * V_2 )
{
struct V_289 V_290 ;
V_290 . V_295 = V_307 ;
V_290 . V_297 = V_308 ;
F_77 ( & V_2 -> V_5 -> V_11 , V_2 -> V_7 , V_279 ,
V_205 , ( T_1 * ) & V_290 ,
sizeof( struct V_289 ) , NULL ) ;
}
int F_115 ( struct V_309 * V_310 , int V_7 , T_1 * V_311 )
{
struct V_312 * V_313 = F_116 ( V_310 ) ;
struct V_16 * V_6 = V_313 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_170 ;
struct V_103 * V_104 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
if ( V_7 >= V_5 -> V_173 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_31 , V_7 ) ;
V_53 = - V_85 ;
goto V_86;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_113 ] ;
if ( ! F_62 ( V_134 , & V_2 -> V_130 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_32 , V_7 ) ;
V_53 = - V_85 ;
goto V_86;
}
if ( ! F_117 ( V_311 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_33 ) ;
V_53 = - V_85 ;
goto V_86;
}
F_102 ( V_6 , V_2 -> V_118 . V_119 , 0 , true , false ) ;
V_104 = F_28 ( V_6 , V_311 , 0 , true , false ) ;
if ( ! V_104 ) {
F_18 ( & V_5 -> V_64 -> V_65 ,
L_34 ) ;
V_53 = - V_177 ;
goto V_86;
}
F_26 ( & V_5 -> V_64 -> V_65 , L_35 , V_311 , V_7 ) ;
if ( F_29 ( V_6 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_9 ) ;
V_53 = - V_141 ;
goto V_86;
}
memcpy ( V_2 -> V_118 . V_119 , V_311 , V_112 ) ;
V_2 -> V_256 = true ;
F_26 ( & V_5 -> V_64 -> V_65 , L_36 ) ;
V_53 = 0 ;
V_86:
return V_53 ;
}
int F_118 ( struct V_309 * V_310 ,
int V_7 , T_2 V_266 , T_1 V_314 )
{
struct V_312 * V_313 = F_116 ( V_310 ) ;
struct V_4 * V_5 = V_313 -> V_6 -> V_170 ;
struct V_16 * V_6 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
if ( V_7 >= V_5 -> V_173 ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_31 , V_7 ) ;
V_53 = - V_85 ;
goto V_315;
}
if ( ( V_266 > V_267 ) || ( V_314 > 7 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_37 ) ;
V_53 = - V_85 ;
goto V_315;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_113 ] ;
if ( ! F_62 ( V_134 , & V_2 -> V_130 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_32 , V_7 ) ;
V_53 = - V_85 ;
goto V_315;
}
if ( V_6 -> V_19 . V_215 == 0 && F_99 ( V_6 ) )
F_18 ( & V_5 -> V_64 -> V_65 ,
L_38 ,
V_7 ) ;
if ( ! ( V_266 || V_314 ) && V_6 -> V_19 . V_215 )
V_53 = F_105 ( V_6 , V_262 ) ;
if ( V_6 -> V_19 . V_215 ) {
V_53 = F_107 ( V_6 , ( F_5 ( V_6 -> V_19 . V_215 ) &
V_316 ) ) ;
if ( V_53 ) {
F_26 ( & V_6 -> V_170 -> V_64 -> V_65 ,
L_39 ,
V_53 , V_5 -> V_11 . V_107 . V_108 ) ;
}
}
if ( V_266 || V_314 )
V_53 = F_27 ( V_6 ,
V_266 | ( V_314 << V_317 ) ) ;
else
F_119 ( V_6 ) ;
if ( V_266 ) {
F_26 ( & V_5 -> V_64 -> V_65 , L_40 ,
V_266 , V_314 , V_7 ) ;
V_53 = F_105 ( V_6 , V_266 ) ;
if ( V_53 ) {
F_26 ( & V_6 -> V_170 -> V_64 -> V_65 ,
L_41 , V_53 ,
V_6 -> V_170 -> V_11 . V_107 . V_108 ) ;
goto V_315;
}
F_107 ( V_6 , V_262 ) ;
}
if ( V_53 ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_42 ) ;
goto V_315;
}
V_2 -> V_117 = F_5 ( V_6 -> V_19 . V_215 ) ;
V_53 = 0 ;
V_315:
return V_53 ;
}
int F_120 ( struct V_309 * V_310 , int V_7 , int V_318 )
{
return - V_319 ;
}
int F_121 ( struct V_309 * V_310 ,
int V_7 , struct V_320 * V_321 )
{
struct V_312 * V_313 = F_116 ( V_310 ) ;
struct V_16 * V_6 = V_313 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_170 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
if ( V_7 >= V_5 -> V_173 ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_31 , V_7 ) ;
V_53 = - V_85 ;
goto V_86;
}
V_2 = & ( V_5 -> V_2 [ V_7 ] ) ;
V_6 = V_5 -> V_6 [ V_2 -> V_113 ] ;
if ( ! F_62 ( V_134 , & V_2 -> V_130 ) ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_32 , V_7 ) ;
V_53 = - V_85 ;
goto V_86;
}
V_321 -> V_2 = V_7 ;
memcpy ( & V_321 -> V_311 , V_2 -> V_118 . V_119 , V_112 ) ;
V_321 -> V_318 = 0 ;
V_321 -> V_322 = F_5 ( V_6 -> V_19 . V_215 ) & V_323 ;
V_321 -> V_314 = ( F_5 ( V_6 -> V_19 . V_215 ) & V_324 ) >>
V_317 ;
V_53 = 0 ;
V_86:
return V_53 ;
}
int F_122 ( struct V_309 * V_310 , int V_7 , int V_325 )
{
struct V_312 * V_313 = F_116 ( V_310 ) ;
struct V_4 * V_5 = V_313 -> V_6 -> V_170 ;
struct V_289 V_290 ;
struct V_27 * V_11 = & V_5 -> V_11 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
if ( V_7 >= V_5 -> V_173 ) {
F_18 ( & V_5 -> V_64 -> V_65 , L_31 , V_7 ) ;
V_53 = - V_85 ;
goto V_326;
}
V_2 = & V_5 -> V_2 [ V_7 ] ;
V_290 . V_295 = V_296 ;
V_290 . V_297 = V_298 ;
switch ( V_325 ) {
case V_327 :
V_2 -> V_299 = false ;
V_290 . V_300 . V_301 . V_302 =
V_5 -> V_11 . V_293 . V_294 . V_294 & V_306 ;
V_290 . V_300 . V_301 . V_304 =
V_5 -> V_11 . V_293 . V_294 . V_304 ;
break;
case V_328 :
V_2 -> V_299 = true ;
V_2 -> V_303 = true ;
V_290 . V_300 . V_301 . V_302 = true ;
V_290 . V_300 . V_301 . V_304 = V_305 ;
break;
case V_329 :
V_2 -> V_299 = true ;
V_2 -> V_303 = false ;
V_290 . V_300 . V_301 . V_302 = false ;
V_290 . V_300 . V_301 . V_304 = 0 ;
break;
default:
V_53 = - V_85 ;
goto V_326;
}
F_77 ( V_11 , V_2 -> V_7 , V_279 ,
0 , ( T_1 * ) & V_290 , sizeof( V_290 ) , NULL ) ;
V_326:
return V_53 ;
}
