static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
T_1 V_5 , T_2 * V_6 ,
T_3 V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ , V_11 ++ ) {
int V_14 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) &&
! F_2 ( V_20 , & V_11 -> V_19 ) )
continue;
F_3 ( V_9 , V_14 , V_4 , V_5 ,
V_6 , V_7 , NULL ) ;
}
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_21 V_22 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_23 * V_24 = & V_2 -> V_9 . V_25 . V_26 ;
int V_14 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
V_22 . V_27 = V_28 ;
V_22 . V_29 = V_30 ;
if ( V_11 -> V_31 ) {
V_22 . V_32 . V_33 . V_34 = V_11 -> V_35 ;
V_22 . V_32 . V_33 . V_36 =
( V_11 -> V_35 ? V_37 : 0 ) ;
} else {
V_22 . V_32 . V_33 . V_34 =
V_24 -> V_26 & V_38 ;
V_22 . V_32 . V_33 . V_36 = V_24 -> V_36 ;
}
F_3 ( V_9 , V_14 , V_39 ,
0 , ( T_2 * ) & V_22 , sizeof( V_22 ) , NULL ) ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ )
F_4 ( & V_2 -> V_11 [ V_12 ] ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_21 V_22 ;
V_22 . V_27 = V_40 ;
V_22 . V_29 = V_41 ;
F_1 ( V_2 , V_39 , 0 ,
( T_2 * ) & V_22 , sizeof( struct V_21 ) ) ;
}
void F_7 ( struct V_10 * V_11 )
{
struct V_21 V_22 ;
int V_14 ;
if ( ! V_11 || V_11 -> V_15 >= V_11 -> V_2 -> V_13 )
return;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) &&
! F_2 ( V_20 , & V_11 -> V_19 ) )
return;
V_14 = V_11 -> V_15 + V_11 -> V_2 -> V_9 . V_16 . V_17 ;
V_22 . V_27 = V_40 ;
V_22 . V_29 = V_41 ;
F_3 ( & V_11 -> V_2 -> V_9 , V_14 , V_39 ,
0 , ( T_2 * ) & V_22 ,
sizeof( struct V_21 ) , NULL ) ;
}
static inline void F_8 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_7 ( V_11 ) ;
F_9 ( V_11 , false ) ;
}
static inline bool F_10 ( struct V_10 * V_11 , T_3 V_42 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 , V_42 ) ;
return ( V_44 && ( V_44 -> V_15 == V_11 -> V_15 ) ) ;
}
static inline bool F_12 ( struct V_10 * V_11 , T_3 V_42 ,
T_2 V_45 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 , V_42 ) ;
return ( V_44 && ( V_45 < V_44 -> V_46 ) ) ;
}
static inline bool F_13 ( struct V_10 * V_11 , T_2 V_47 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
return V_47 < V_2 -> V_9 . V_16 . V_48 ;
}
static T_3 F_14 ( struct V_10 * V_11 , T_3 V_42 ,
T_2 V_49 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 = F_11 ( V_2 , V_42 ) ;
T_3 V_50 = V_51 ;
if ( ! V_44 )
return V_50 ;
if ( F_15 ( V_44 -> V_52 . V_53 ) &
V_54 )
V_50 =
F_15 ( V_44 -> V_52 . V_55 [ V_49 ] ) ;
else
V_50 = F_15 ( V_44 -> V_52 . V_55 [ 0 ] ) +
V_49 ;
return V_50 ;
}
static void F_16 ( struct V_10 * V_11 , T_3 V_42 ,
struct V_56 * V_57 )
{
unsigned long V_58 = 0 , V_59 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_3 V_49 , V_50 ;
enum V_60 V_61 ;
T_3 V_62 , V_47 ;
T_4 V_63 , V_64 ;
T_3 V_65 = 0 ;
V_47 = V_57 -> V_47 ;
if ( 0 == V_47 )
V_64 = F_17 ( V_11 -> V_15 ) ;
else
V_64 = F_18 (
( ( V_2 -> V_9 . V_16 . V_48 - 1 ) * V_11 -> V_15 ) +
( V_47 - 1 ) ) ;
if ( V_57 -> V_66 == 0 && V_57 -> V_67 == 0 ) {
F_19 ( V_9 , V_64 , V_68 ) ;
goto V_69;
}
V_59 = V_57 -> V_66 ;
F_20 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_58 |= ( F_21 ( V_70 *
V_49 ) ) ;
}
V_59 = V_57 -> V_67 ;
F_20 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_58 |= ( F_21 ( V_70 *
V_49 + 1 ) ) ;
}
V_62 = F_22 ( & V_58 ,
( V_71 *
V_70 ) ) ;
V_49 = V_62 / V_70 ;
V_61 = V_62 % V_70 ;
V_50 = F_14 ( V_11 , V_42 , V_49 ) ;
V_63 = ( ( V_61 << V_72 ) | V_50 ) ;
F_19 ( V_9 , V_64 , V_63 ) ;
while ( V_62 < ( V_71 * V_70 ) ) {
switch ( V_61 ) {
case V_73 :
V_64 = F_23 ( V_50 ) ;
V_65 = V_57 -> V_74 ;
break;
case V_75 :
V_64 = F_24 ( V_50 ) ;
V_65 = V_57 -> V_76 ;
break;
default:
break;
}
V_62 = F_25 ( & V_58 ,
( V_71 *
V_70 ) ,
V_62 + 1 ) ;
if ( V_62 <
( V_71 * V_70 ) ) {
V_49 = V_62 / V_70 ;
V_61 = V_62 % V_70 ;
V_50 = F_14 ( V_11 , V_42 ,
V_49 ) ;
} else {
V_50 = V_51 ;
V_61 = 0 ;
}
V_63 = ( V_47 ) |
( V_61 << V_77 ) |
( V_50 << V_78 ) |
F_21 ( V_79 ) |
( V_65 << V_80 ) ;
F_19 ( V_9 , V_64 , V_63 ) ;
}
if ( ( V_11 -> V_81 & V_82 ) &&
( V_47 == 0 ) ) {
V_63 = F_26 ( V_9 , V_83 ) ;
if ( ! ( V_63 & V_84 ) ) {
V_63 |= V_84 ;
F_19 ( V_9 , V_83 , V_63 ) ;
}
}
V_69:
F_27 ( V_9 ) ;
}
static int F_28 ( struct V_10 * V_11 , T_3 V_42 ,
T_3 V_49 ,
struct V_85 * V_52 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_86 V_87 ;
struct V_43 * V_44 ;
T_3 V_50 ;
T_4 V_88 ;
int V_89 = 0 ;
V_50 = F_14 ( V_11 , V_42 , V_49 ) ;
V_44 = F_11 ( V_2 , V_42 ) ;
memset ( & V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 . V_90 = V_52 -> V_91 / 128 ;
V_87 . V_92 = V_52 -> V_93 ;
V_87 . V_94 = F_15 ( V_44 -> V_52 . V_95 [ 0 ] ) ;
V_87 . V_96 = 0 ;
V_87 . V_97 = V_52 -> V_98 ;
V_87 . V_99 = V_52 -> V_100 ;
V_89 = F_29 ( V_9 , V_50 ) ;
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_1 ,
V_50 , V_89 ) ;
V_89 = - V_103 ;
goto V_104;
}
V_89 = F_31 ( V_9 , V_50 , & V_87 ) ;
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_2 ,
V_50 , V_89 ) ;
V_89 = - V_103 ;
goto V_104;
}
V_88 = V_105 ;
V_88 |= ( ( V_9 -> V_106 << V_107 )
& V_108 ) ;
V_88 |= ( ( ( V_11 -> V_15 + V_9 -> V_16 . V_17 )
<< V_109 )
& V_110 ) ;
F_19 ( V_9 , F_32 ( V_50 ) , V_88 ) ;
F_27 ( V_9 ) ;
V_104:
return V_89 ;
}
static int F_33 ( struct V_10 * V_11 , T_3 V_42 ,
T_3 V_49 ,
struct V_111 * V_52 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_112 V_113 ;
T_3 V_50 ;
int V_89 = 0 ;
V_50 = F_14 ( V_11 , V_42 , V_49 ) ;
memset ( & V_113 , 0 , sizeof( struct V_112 ) ) ;
V_113 . V_90 = V_52 -> V_91 / 128 ;
V_113 . V_92 = V_52 -> V_93 ;
if ( V_52 -> V_114 ) {
V_113 . V_115 = V_116 |
V_117 |
V_118 |
V_119 ;
if ( V_52 -> V_120 > ( ( 2 * 1024 ) - 64 ) ) {
V_89 = - V_121 ;
goto V_122;
}
V_113 . V_123 = V_52 -> V_120 >> V_124 ;
V_113 . V_125 = 0x2 ;
}
if ( V_52 -> V_126 > ( ( 16 * 1024 ) - 128 ) ) {
V_89 = - V_121 ;
goto V_122;
}
V_113 . V_127 = V_52 -> V_126 >> V_128 ;
if ( V_52 -> V_129 >= ( 16 * 1024 ) || V_52 -> V_129 < 64 ) {
V_89 = - V_121 ;
goto V_122;
}
V_113 . V_130 = V_52 -> V_129 ;
V_113 . V_131 = 1 ;
V_113 . V_132 = 2 ;
V_113 . V_133 = 1 ;
V_113 . V_134 = 1 ;
V_113 . V_135 = 1 ;
V_89 = F_34 ( V_9 , V_50 ) ;
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_3 ,
V_50 , V_89 ) ;
V_89 = - V_103 ;
goto V_122;
}
V_89 = F_35 ( V_9 , V_50 , & V_113 ) ;
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_4 ,
V_50 , V_89 ) ;
V_89 = - V_103 ;
goto V_122;
}
V_122:
return V_89 ;
}
static int F_36 ( struct V_10 * V_11 , enum V_136 type )
{
struct V_137 * V_138 = NULL ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 ;
int V_89 = 0 ;
V_44 = F_37 ( V_2 , type , V_2 -> V_44 [ V_2 -> V_139 ] -> V_140 , V_11 -> V_15 ) ;
if ( ! V_44 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_5 ,
V_11 -> V_15 , V_2 -> V_9 . V_141 . V_142 ) ;
V_89 = - V_103 ;
goto V_143;
}
if ( type == V_144 ) {
T_2 V_145 [ V_146 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_11 -> V_147 = V_44 -> V_148 ;
V_11 -> V_149 = V_44 -> V_150 ;
if ( V_11 -> V_151 )
F_38 ( V_44 , V_11 -> V_151 ) ;
V_138 = F_39 ( V_44 , V_11 -> V_152 . V_153 ,
V_11 -> V_151 ? V_11 -> V_151 : - 1 ,
true , false ) ;
if ( ! V_138 )
F_40 ( & V_2 -> V_101 -> V_102 ,
L_6 ) ;
V_138 = F_39 ( V_44 , V_145 ,
V_11 -> V_151 ? V_11 -> V_151 : - 1 ,
true , false ) ;
if ( ! V_138 )
F_40 ( & V_2 -> V_101 -> V_102 ,
L_7 ) ;
}
V_89 = F_41 ( V_44 ) ;
if ( V_89 )
F_30 ( & V_2 -> V_101 -> V_102 , L_8 ) ;
if ( V_11 -> V_154 ) {
V_89 = F_42 ( & V_2 -> V_9 , V_44 -> V_140 ,
V_11 -> V_154 / 50 , 0 , NULL ) ;
if ( V_89 )
F_30 ( & V_2 -> V_101 -> V_102 , L_9 ,
V_11 -> V_15 , V_89 ) ;
}
V_143:
return V_89 ;
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_4 V_63 , V_155 = 0 ;
int V_156 ;
F_19 ( V_9 , F_44 ( V_11 -> V_149 ) ,
V_157 ) ;
V_63 = V_158 ;
F_19 ( V_9 , F_45 ( V_11 -> V_15 ) , V_63 ) ;
for ( V_156 = 0 ; V_156 < V_2 -> V_44 [ V_11 -> V_147 ] -> V_46 ; V_156 ++ ) {
T_3 V_45 = F_14 ( V_11 , V_11 -> V_149 , V_156 ) ;
V_63 = ( V_45 & V_159 ) ;
F_19 ( V_9 , F_46 ( V_155 , V_11 -> V_15 ) , V_63 ) ;
V_155 ++ ;
}
for ( V_156 = 0 ; V_156 < 7 ; V_156 ++ ) {
if ( V_156 * 2 >= V_2 -> V_44 [ V_11 -> V_147 ] -> V_46 ) {
V_63 = 0x07FF07FF ;
} else {
T_3 V_45 = F_14 ( V_11 , V_11 -> V_149 ,
V_156 * 2 ) ;
V_63 = V_45 ;
V_45 = F_14 ( V_11 , V_11 -> V_149 ,
( V_156 * 2 ) + 1 ) ;
V_63 |= V_45 << 16 ;
}
F_19 ( V_9 , F_47 ( V_156 , V_11 -> V_149 ) , V_63 ) ;
}
F_27 ( V_9 ) ;
}
static void F_48 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_12 ;
F_19 ( V_9 , F_45 ( V_11 -> V_15 ) , 0 ) ;
for ( V_12 = 0 ; V_12 < V_71 ; V_12 ++ )
F_19 ( V_9 , F_46 ( V_12 , V_11 -> V_15 ) ,
V_51 ) ;
F_27 ( V_9 ) ;
}
static void F_49 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_4 V_64 , V_63 ;
int V_12 , V_160 ;
if ( V_11 -> V_147 ) {
F_50 ( V_2 -> V_44 [ V_11 -> V_147 ] ) ;
V_11 -> V_147 = 0 ;
V_11 -> V_149 = 0 ;
}
V_160 = V_2 -> V_9 . V_16 . V_48 ;
for ( V_12 = 0 ; V_12 < V_160 ; V_12 ++ ) {
if ( 0 == V_12 )
V_64 = F_51 ( V_11 -> V_15 ) ;
else
V_64 = F_52 ( ( ( V_160 - 1 ) *
( V_11 -> V_15 ) )
+ ( V_12 - 1 ) ) ;
F_19 ( V_9 , V_64 , V_161 ) ;
F_27 ( V_9 ) ;
}
for ( V_12 = 0 ; V_12 < V_160 ; V_12 ++ ) {
if ( 0 == V_12 )
V_64 = F_17 ( V_11 -> V_15 ) ;
else
V_64 = F_18 ( ( ( V_160 - 1 ) *
( V_11 -> V_15 ) )
+ ( V_12 - 1 ) ) ;
V_63 = ( V_162 |
V_163 ) ;
F_19 ( V_9 , V_64 , V_63 ) ;
F_27 ( V_9 ) ;
}
V_11 -> V_164 = 0 ;
V_11 -> V_19 = 0 ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_155 = 0 ;
int V_89 ;
V_89 = F_36 ( V_11 , V_144 ) ;
if ( V_89 )
goto V_165;
V_155 += V_2 -> V_44 [ V_11 -> V_147 ] -> V_46 ;
F_54 ( V_166 , & V_11 -> V_167 ) ;
V_11 -> V_164 = V_155 ;
F_54 ( V_18 , & V_11 -> V_19 ) ;
V_165:
if ( V_89 )
F_49 ( V_11 ) ;
return V_89 ;
}
static int F_55 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_168 , V_12 ;
T_4 V_63 ;
V_168 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
F_19 ( V_9 , V_169 ,
V_170 | ( V_168 << V_171 ) ) ;
for ( V_12 = 0 ; V_12 < 100 ; V_12 ++ ) {
V_63 = F_26 ( V_9 , V_172 ) ;
if ( ( V_63 & V_173 ) == 0 )
return 0 ;
F_56 ( 1 ) ;
}
return - V_174 ;
}
void F_9 ( struct V_10 * V_11 , bool V_175 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
bool V_176 = false ;
int V_12 ;
T_4 V_63 ;
if ( F_57 ( V_177 , & V_2 -> V_178 ) )
return;
F_58 ( V_20 , & V_11 -> V_19 ) ;
if ( ! V_175 ) {
V_63 = F_26 ( V_9 , F_59 ( V_11 -> V_15 ) ) ;
V_63 |= V_179 ;
F_19 ( V_9 , F_59 ( V_11 -> V_15 ) , V_63 ) ;
F_27 ( V_9 ) ;
}
if ( F_55 ( V_11 ) )
F_30 ( & V_2 -> V_101 -> V_102 , L_10 ,
V_11 -> V_15 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
F_60 ( 10000 , 20000 ) ;
V_63 = F_26 ( V_9 , F_61 ( V_11 -> V_15 ) ) ;
if ( V_63 & V_180 ) {
V_176 = true ;
break;
}
}
if ( V_175 )
F_60 ( 10000 , 20000 ) ;
if ( ! V_176 )
F_30 ( & V_2 -> V_101 -> V_102 , L_11 ,
V_11 -> V_15 ) ;
F_19 ( V_9 , F_62 ( V_11 -> V_15 ) , V_181 ) ;
V_63 = F_26 ( V_9 , F_59 ( V_11 -> V_15 ) ) ;
V_63 &= ~ V_179 ;
F_19 ( V_9 , F_59 ( V_11 -> V_15 ) , V_63 ) ;
if ( V_11 -> V_147 == 0 )
goto V_182;
F_63 ( V_2 -> V_44 [ V_11 -> V_147 ] , false ) ;
V_182:
F_49 ( V_11 ) ;
F_53 ( V_11 ) ;
F_43 ( V_11 ) ;
F_54 ( V_20 , & V_11 -> V_19 ) ;
F_58 ( V_183 , & V_11 -> V_19 ) ;
F_19 ( V_9 , F_62 ( V_11 -> V_15 ) , V_184 ) ;
F_27 ( V_9 ) ;
F_58 ( V_177 , & V_2 -> V_178 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_4 V_64 , V_185 ;
int V_12 , V_186 , V_15 ;
if ( ! V_2 -> V_11 )
return;
while ( F_57 ( V_177 , & V_2 -> V_178 ) )
F_60 ( 1000 , 2000 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ )
if ( F_2 ( V_18 , & V_2 -> V_11 [ V_12 ] . V_19 ) )
F_63 ( V_2 -> V_44 [ V_2 -> V_11 [ V_12 ] . V_147 ] ,
false ) ;
if ( ! F_65 ( V_2 -> V_101 ) )
F_66 ( V_2 -> V_101 ) ;
else
F_67 ( & V_2 -> V_101 -> V_102 , L_12 ) ;
F_68 ( 20 ) ;
V_186 = V_2 -> V_13 ;
V_2 -> V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_186 ; V_12 ++ ) {
if ( F_2 ( V_18 , & V_2 -> V_11 [ V_12 ] . V_19 ) )
F_49 ( & V_2 -> V_11 [ V_12 ] ) ;
F_48 ( & V_2 -> V_11 [ V_12 ] ) ;
}
F_69 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( ! F_65 ( V_2 -> V_101 ) ) {
for ( V_15 = 0 ; V_15 < V_186 ; V_15 ++ ) {
V_64 = ( V_9 -> V_16 . V_17 + V_15 ) / 32 ;
V_185 = ( V_9 -> V_16 . V_17 + V_15 ) % 32 ;
F_19 ( V_9 , F_70 ( V_64 ) , F_21 ( V_185 ) ) ;
}
}
F_58 ( V_177 , & V_2 -> V_178 ) ;
}
int F_71 ( struct V_1 * V_2 , T_3 V_13 )
{
struct V_10 * V_187 ;
int V_12 , V_89 = 0 ;
F_72 ( V_2 ) ;
if ( F_73 ( V_2 -> V_101 ) != V_13 ) {
V_89 = F_74 ( V_2 -> V_101 , V_13 ) ;
if ( V_89 ) {
V_2 -> V_13 = 0 ;
goto V_188;
}
}
V_187 = F_75 ( V_13 , sizeof( struct V_10 ) , V_189 ) ;
if ( ! V_187 ) {
V_89 = - V_190 ;
goto V_191;
}
V_2 -> V_11 = V_187 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_187 [ V_12 ] . V_2 = V_2 ;
V_187 [ V_12 ] . V_192 = V_193 ;
V_187 [ V_12 ] . V_15 = V_12 ;
F_54 ( V_194 , & V_187 [ V_12 ] . V_167 ) ;
V_187 [ V_12 ] . V_195 = true ;
F_9 ( & V_187 [ V_12 ] , false ) ;
F_43 ( & V_187 [ V_12 ] ) ;
}
V_2 -> V_13 = V_13 ;
V_191:
if ( V_89 )
F_64 ( V_2 ) ;
V_188:
F_76 ( V_2 ) ;
return V_89 ;
}
static int F_77 ( struct V_196 * V_101 , int V_197 )
{
#ifdef F_78
struct V_1 * V_2 = F_79 ( V_101 ) ;
int V_198 = F_73 ( V_101 ) ;
int V_199 = 0 ;
if ( V_2 -> V_178 & V_200 ) {
F_67 ( & V_101 -> V_102 ,
L_13 ) ;
V_199 = - V_201 ;
goto V_202;
}
F_40 ( & V_101 -> V_102 , L_14 , V_197 ) ;
if ( V_198 && V_198 != V_197 )
F_64 ( V_2 ) ;
else if ( V_198 && V_198 == V_197 )
goto V_203;
if ( V_197 > V_2 -> V_204 ) {
V_199 = - V_201 ;
goto V_202;
}
V_199 = F_71 ( V_2 , V_197 ) ;
if ( V_199 ) {
F_67 ( & V_101 -> V_102 , L_15 , V_199 ) ;
goto V_202;
}
V_203:
return V_197 ;
V_202:
return V_199 ;
#endif
return 0 ;
}
int F_80 ( struct V_196 * V_101 , int V_197 )
{
struct V_1 * V_2 = F_79 ( V_101 ) ;
if ( V_197 ) {
if ( ! ( V_2 -> V_205 & V_206 ) ) {
V_2 -> V_205 |= V_206 ;
F_81 ( V_2 ,
F_82 ( V_207 ) ) ;
}
return F_77 ( V_101 , V_197 ) ;
}
if ( ! F_65 ( V_2 -> V_101 ) ) {
F_64 ( V_2 ) ;
V_2 -> V_205 &= ~ V_206 ;
F_81 ( V_2 , F_82 ( V_207 ) ) ;
} else {
F_67 ( & V_101 -> V_102 , L_16 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_83 ( struct V_10 * V_11 , T_4 V_4 ,
T_4 V_5 , T_2 * V_6 , T_3 V_7 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_14 ;
T_1 V_208 ;
if ( ! V_11 || V_11 -> V_15 >= V_11 -> V_2 -> V_13 )
return - V_121 ;
V_2 = V_11 -> V_2 ;
V_9 = & V_2 -> V_9 ;
V_14 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
if ( V_5 ) {
V_11 -> V_209 ++ ;
F_30 ( & V_2 -> V_101 -> V_102 , L_17 ,
V_4 , V_5 ) ;
if ( V_11 -> V_209 >
V_210 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_18 ,
V_11 -> V_15 ) ;
F_30 ( & V_2 -> V_101 -> V_102 , L_19 ) ;
F_54 ( V_183 , & V_11 -> V_19 ) ;
}
} else {
V_11 -> V_211 ++ ;
}
V_208 = F_3 ( V_9 , V_14 , V_4 , V_5 ,
V_6 , V_7 , NULL ) ;
if ( V_208 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_20 ,
V_11 -> V_15 , V_2 -> V_9 . V_141 . V_142 ) ;
return - V_174 ;
}
return 0 ;
}
static int F_84 ( struct V_10 * V_11 ,
enum V_3 V_212 ,
T_1 V_213 )
{
return F_83 ( V_11 , V_212 , V_213 , NULL , 0 ) ;
}
static int F_85 ( struct V_10 * V_11 , T_2 * V_6 )
{
struct V_214 V_52 = {
V_215 , V_216
} ;
V_11 -> V_217 = * (struct V_214 * ) V_6 ;
if ( F_86 ( V_11 ) )
V_52 . V_218 = V_219 ;
return F_83 ( V_11 , V_220 ,
V_221 , ( T_2 * ) & V_52 ,
sizeof( struct
V_214 ) ) ;
}
static int F_87 ( struct V_10 * V_11 , T_2 * V_6 )
{
struct V_222 * V_223 = NULL ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_208 = 0 ;
struct V_43 * V_44 ;
int V_12 = 0 , V_224 = 0 ;
int V_225 = 1 ;
int V_89 ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
V_208 = V_226 ;
goto V_199;
}
V_224 = ( sizeof( struct V_222 ) +
sizeof( struct V_227 ) * V_225 ) ;
V_223 = F_88 ( V_224 , V_189 ) ;
if ( ! V_223 ) {
V_208 = V_228 ;
V_224 = 0 ;
goto V_199;
}
if ( F_89 ( V_11 ) )
V_11 -> V_81 = * ( T_4 * ) V_6 ;
else
V_11 -> V_81 = V_229 |
V_230 |
V_231 ;
V_223 -> V_232 = V_229 ;
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( ! V_44 -> V_52 . V_233 )
V_223 -> V_232 |= V_231 ;
if ( V_2 -> V_205 & V_234 ) {
if ( V_11 -> V_81 & V_235 )
V_223 -> V_232 |=
V_235 ;
} else {
V_223 -> V_232 |= V_230 ;
}
V_223 -> V_225 = V_225 ;
V_223 -> V_164 = V_11 -> V_164 ;
V_223 -> V_236 = V_2 -> V_9 . V_16 . V_48 ;
if ( V_11 -> V_147 ) {
V_223 -> V_237 [ V_12 ] . V_42 = V_11 -> V_149 ;
V_223 -> V_237 [ V_12 ] . V_238 = V_144 ;
V_223 -> V_237 [ V_12 ] . V_164 =
V_2 -> V_44 [ V_11 -> V_147 ] -> V_46 ;
memcpy ( V_223 -> V_237 [ V_12 ] . V_239 ,
V_11 -> V_152 . V_153 , V_146 ) ;
V_12 ++ ;
}
F_54 ( V_20 , & V_11 -> V_19 ) ;
V_199:
V_89 = F_83 ( V_11 , V_240 ,
V_208 , ( T_2 * ) V_223 , V_224 ) ;
F_69 ( V_223 ) ;
return V_89 ;
}
static void F_90 ( struct V_10 * V_11 )
{
if ( F_2 ( V_20 , & V_11 -> V_19 ) )
F_9 ( V_11 , false ) ;
}
static int F_91 ( struct V_10 * V_11 ,
T_2 * V_6 , T_3 V_7 )
{
struct V_241 * V_52 =
(struct V_241 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_43 * V_44 ;
bool V_242 = false ;
T_1 V_208 ;
V_44 = F_11 ( V_2 , V_52 -> V_42 ) ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_166 , & V_11 -> V_167 ) ||
! F_10 ( V_11 , V_52 -> V_42 ) ||
( V_44 -> type != V_243 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( V_52 -> V_205 & V_244 )
V_242 = true ;
V_208 = F_92 ( V_9 , V_44 -> V_140 ,
V_242 , NULL ) ;
V_122:
return F_84 ( V_11 ,
V_245 ,
V_208 ) ;
}
static int F_93 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_6 ;
struct V_248 * V_249 ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_42 , V_49 ;
T_1 V_208 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_208 = V_226 ;
goto V_122;
}
V_42 = V_247 -> V_42 ;
if ( ! F_10 ( V_11 , V_42 ) ) {
V_208 = V_226 ;
goto V_122;
}
for ( V_12 = 0 ; V_12 < V_247 -> V_164 ; V_12 ++ ) {
V_249 = & V_247 -> V_250 [ V_12 ] ;
V_49 = V_249 -> V_251 . V_252 ;
if ( ( V_249 -> V_251 . V_42 != V_42 ) ||
( V_249 -> V_253 . V_42 != V_42 ) ||
( V_249 -> V_253 . V_252 != V_49 ) ||
! F_12 ( V_11 , V_42 , V_49 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( F_33 ( V_11 , V_42 , V_49 ,
& V_249 -> V_253 ) ||
F_28 ( V_11 , V_42 , V_49 ,
& V_249 -> V_251 ) ) {
V_208 = V_226 ;
goto V_122;
}
}
V_2 -> V_44 [ V_11 -> V_147 ] -> V_164 = V_247 -> V_164 ;
V_122:
return F_84 ( V_11 , V_254 ,
V_208 ) ;
}
static int F_94 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_255 * V_256 =
(struct V_255 * ) V_6 ;
struct V_56 * V_257 ;
T_3 V_42 , V_49 , V_47 ;
T_1 V_208 = 0 ;
unsigned long V_59 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_208 = V_226 ;
goto V_122;
}
for ( V_12 = 0 ; V_12 < V_256 -> V_258 ; V_12 ++ ) {
V_257 = & V_256 -> V_57 [ V_12 ] ;
V_47 = V_257 -> V_47 ;
V_42 = V_257 -> V_42 ;
if ( ! F_13 ( V_11 , V_47 ) ||
! F_10 ( V_11 , V_42 ) ) {
V_208 = V_226 ;
goto V_122;
}
V_59 = V_257 -> V_66 ;
F_20 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_12 ( V_11 , V_42 ,
V_49 ) ) {
V_208 = V_226 ;
goto V_122;
}
}
V_59 = V_257 -> V_67 ;
F_20 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_12 ( V_11 , V_42 ,
V_49 ) ) {
V_208 = V_226 ;
goto V_122;
}
}
F_16 ( V_11 , V_42 , V_257 ) ;
}
V_122:
return F_84 ( V_11 , V_259 ,
V_208 ) ;
}
static int F_95 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_260 * V_261 =
(struct V_260 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_42 = V_261 -> V_42 ;
T_1 V_208 = 0 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( ! F_10 ( V_11 , V_42 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( ( 0 == V_261 -> V_262 ) && ( 0 == V_261 -> V_263 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( F_63 ( V_2 -> V_44 [ V_11 -> V_147 ] , true ) )
V_208 = V_264 ;
V_122:
return F_84 ( V_11 , V_265 ,
V_208 ) ;
}
static int F_96 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_260 * V_261 =
(struct V_260 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_208 = 0 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( ! F_10 ( V_11 , V_261 -> V_42 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( ( 0 == V_261 -> V_262 ) && ( 0 == V_261 -> V_263 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( F_63 ( V_2 -> V_44 [ V_11 -> V_147 ] , false ) )
V_208 = V_264 ;
V_122:
return F_84 ( V_11 , V_266 ,
V_208 ) ;
}
static int F_97 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_260 * V_261 =
(struct V_260 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_267 V_268 ;
T_1 V_208 = 0 ;
struct V_43 * V_44 ;
memset ( & V_268 , 0 , sizeof( struct V_267 ) ) ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_208 = V_226 ;
goto V_122;
}
if ( ! F_10 ( V_11 , V_261 -> V_42 ) ) {
V_208 = V_226 ;
goto V_122;
}
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( ! V_44 ) {
V_208 = V_226 ;
goto V_122;
}
F_98 ( V_44 ) ;
V_268 = V_44 -> V_269 ;
V_122:
return F_83 ( V_11 , V_270 , V_208 ,
( T_2 * ) & V_268 , sizeof( V_268 ) ) ;
}
static inline int F_99 ( struct V_10 * V_11 , T_2 * V_271 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_89 = 0 ;
if ( F_100 ( V_271 ) ||
F_101 ( V_271 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_21 , V_271 ) ;
V_89 = V_272 ;
} else if ( V_11 -> V_273 && ! F_102 ( V_271 ) &&
! F_103 ( V_271 , V_11 -> V_152 . V_153 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_22 ) ;
V_89 = - V_201 ;
}
return V_89 ;
}
static int F_104 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 = NULL ;
T_3 V_42 = V_275 -> V_42 ;
T_1 V_89 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_166 , & V_11 -> V_167 ) ||
! F_10 ( V_11 , V_42 ) ) {
V_89 = V_226 ;
goto V_122;
}
for ( V_12 = 0 ; V_12 < V_275 -> V_276 ; V_12 ++ ) {
V_89 = F_99 ( V_11 , V_275 -> V_277 [ V_12 ] . V_153 ) ;
if ( V_89 )
goto V_122;
}
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
for ( V_12 = 0 ; V_12 < V_275 -> V_276 ; V_12 ++ ) {
struct V_137 * V_138 ;
V_138 = F_105 ( V_44 , V_275 -> V_277 [ V_12 ] . V_153 , true , false ) ;
if ( ! V_138 ) {
if ( F_106 ( V_44 ) )
V_138 = F_107 ( V_44 , V_275 -> V_277 [ V_12 ] . V_153 ,
true , false ) ;
else
V_138 = F_39 ( V_44 , V_275 -> V_277 [ V_12 ] . V_153 , - 1 ,
true , false ) ;
}
if ( ! V_138 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_23 ) ;
V_89 = V_226 ;
goto V_122;
}
}
if ( F_41 ( V_44 ) )
F_30 ( & V_2 -> V_101 -> V_102 , L_24 ) ;
V_122:
return F_84 ( V_11 , V_278 ,
V_89 ) ;
}
static int F_108 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 = NULL ;
T_3 V_42 = V_275 -> V_42 ;
T_1 V_89 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_166 , & V_11 -> V_167 ) ||
! F_10 ( V_11 , V_42 ) ) {
V_89 = V_226 ;
goto V_122;
}
for ( V_12 = 0 ; V_12 < V_275 -> V_276 ; V_12 ++ ) {
if ( F_100 ( V_275 -> V_277 [ V_12 ] . V_153 ) ||
F_101 ( V_275 -> V_277 [ V_12 ] . V_153 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_21 ,
V_275 -> V_277 [ V_12 ] . V_153 ) ;
V_89 = V_272 ;
goto V_122;
}
}
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
for ( V_12 = 0 ; V_12 < V_275 -> V_276 ; V_12 ++ )
F_109 ( V_44 , V_275 -> V_277 [ V_12 ] . V_153 ,
V_279 , true , false ) ;
if ( F_41 ( V_44 ) )
F_30 ( & V_2 -> V_101 -> V_102 , L_24 ) ;
V_122:
return F_84 ( V_11 , V_280 ,
V_89 ) ;
}
static int F_110 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_281 * V_282 =
(struct V_281 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 = NULL ;
T_3 V_42 = V_282 -> V_42 ;
T_1 V_208 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_166 , & V_11 -> V_167 ) ||
! F_10 ( V_11 , V_42 ) ) {
V_208 = V_226 ;
goto V_122;
}
for ( V_12 = 0 ; V_12 < V_282 -> V_276 ; V_12 ++ ) {
if ( V_282 -> V_283 [ V_12 ] > V_284 ) {
V_208 = V_226 ;
F_30 ( & V_2 -> V_101 -> V_102 ,
L_25 , V_282 -> V_283 [ V_12 ] ) ;
goto V_122;
}
}
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( V_44 -> V_52 . V_233 ) {
V_208 = V_226 ;
goto V_122;
}
F_111 ( V_44 ) ;
for ( V_12 = 0 ; V_12 < V_282 -> V_276 ; V_12 ++ ) {
int V_89 = F_112 ( V_44 , V_282 -> V_283 [ V_12 ] ) ;
if ( V_89 )
F_30 ( & V_2 -> V_101 -> V_102 ,
L_26 ,
V_282 -> V_283 [ V_12 ] , V_89 ) ;
}
V_122:
return F_84 ( V_11 , V_285 , V_208 ) ;
}
static int F_113 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_281 * V_282 =
(struct V_281 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_43 * V_44 = NULL ;
T_3 V_42 = V_282 -> V_42 ;
T_1 V_208 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_166 , & V_11 -> V_167 ) ||
! F_10 ( V_11 , V_42 ) ) {
V_208 = V_226 ;
goto V_122;
}
for ( V_12 = 0 ; V_12 < V_282 -> V_276 ; V_12 ++ ) {
if ( V_282 -> V_283 [ V_12 ] > V_284 ) {
V_208 = V_226 ;
goto V_122;
}
}
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( V_44 -> V_52 . V_233 ) {
V_208 = V_226 ;
goto V_122;
}
for ( V_12 = 0 ; V_12 < V_282 -> V_276 ; V_12 ++ ) {
int V_89 = F_114 ( V_44 , V_282 -> V_283 [ V_12 ] ) ;
if ( V_89 )
F_30 ( & V_2 -> V_101 -> V_102 ,
L_27 ,
V_282 -> V_283 [ V_12 ] , V_89 ) ;
}
V_122:
return F_84 ( V_11 , V_286 , V_208 ) ;
}
static int F_115 ( struct V_10 * V_11 , T_4 V_4 ,
T_4 V_5 , T_2 * V_6 , T_3 V_7 )
{
bool V_287 = false ;
int V_288 ;
if ( F_2 ( V_183 , & V_11 -> V_19 ) )
return V_226 ;
switch ( V_4 ) {
case V_220 :
V_288 = sizeof( struct V_214 ) ;
break;
case V_289 :
V_288 = 0 ;
break;
case V_240 :
if ( F_89 ( V_11 ) )
V_288 = sizeof( T_4 ) ;
else
V_288 = 0 ;
break;
case V_290 :
V_288 = sizeof( struct V_85 ) ;
break;
case V_291 :
V_288 = sizeof( struct V_111 ) ;
break;
case V_254 :
V_288 = sizeof( struct V_246 ) ;
if ( V_7 >= V_288 ) {
struct V_246 * V_292 =
(struct V_246 * ) V_6 ;
V_288 += ( V_292 -> V_164 *
sizeof( struct
V_248 ) ) ;
if ( V_292 -> V_164 == 0 )
V_287 = true ;
}
break;
case V_259 :
V_288 = sizeof( struct V_255 ) ;
if ( V_7 >= V_288 ) {
struct V_255 * V_293 =
(struct V_255 * ) V_6 ;
V_288 += ( V_293 -> V_258 *
sizeof( struct V_56 ) ) ;
if ( V_293 -> V_258 == 0 )
V_287 = true ;
}
break;
case V_265 :
case V_266 :
V_288 = sizeof( struct V_260 ) ;
break;
case V_278 :
case V_280 :
V_288 = sizeof( struct V_274 ) ;
if ( V_7 >= V_288 ) {
struct V_274 * V_294 =
(struct V_274 * ) V_6 ;
V_288 += V_294 -> V_276 *
sizeof( struct V_295 ) ;
if ( V_294 -> V_276 == 0 )
V_287 = true ;
}
break;
case V_285 :
case V_286 :
V_288 = sizeof( struct V_281 ) ;
if ( V_7 >= V_288 ) {
struct V_281 * V_282 =
(struct V_281 * ) V_6 ;
V_288 += V_282 -> V_276 * sizeof( T_3 ) ;
if ( V_282 -> V_276 == 0 )
V_287 = true ;
}
break;
case V_245 :
V_288 = sizeof( struct V_241 ) ;
break;
case V_270 :
V_288 = sizeof( struct V_260 ) ;
break;
case V_39 :
case V_296 :
default:
return - V_201 ;
break;
}
if ( ( V_288 != V_7 ) || ( V_287 ) ) {
F_84 ( V_11 , V_4 , V_226 ) ;
return - V_121 ;
} else {
return 0 ;
}
}
int F_116 ( struct V_1 * V_2 , T_3 V_15 , T_4 V_4 ,
T_4 V_5 , T_2 * V_6 , T_3 V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_297 = V_15 - V_9 -> V_16 . V_17 ;
struct V_10 * V_11 ;
int V_89 ;
V_2 -> V_298 ++ ;
if ( V_297 >= V_2 -> V_13 )
return - V_121 ;
V_11 = & ( V_2 -> V_11 [ V_297 ] ) ;
V_89 = F_115 ( V_11 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_28 ,
V_297 , V_4 , V_7 ) ;
return V_89 ;
}
switch ( V_4 ) {
case V_220 :
V_89 = F_85 ( V_11 , V_6 ) ;
break;
case V_240 :
V_89 = F_87 ( V_11 , V_6 ) ;
break;
case V_289 :
F_90 ( V_11 ) ;
V_89 = 0 ;
break;
case V_245 :
V_89 = F_91 ( V_11 , V_6 , V_7 ) ;
break;
case V_254 :
V_89 = F_93 ( V_11 , V_6 , V_7 ) ;
break;
case V_259 :
V_89 = F_94 ( V_11 , V_6 , V_7 ) ;
break;
case V_265 :
V_89 = F_95 ( V_11 , V_6 , V_7 ) ;
F_4 ( V_11 ) ;
break;
case V_266 :
V_89 = F_96 ( V_11 , V_6 , V_7 ) ;
break;
case V_278 :
V_89 = F_104 ( V_11 , V_6 , V_7 ) ;
break;
case V_280 :
V_89 = F_108 ( V_11 , V_6 , V_7 ) ;
break;
case V_285 :
V_89 = F_110 ( V_11 , V_6 , V_7 ) ;
break;
case V_286 :
V_89 = F_113 ( V_11 , V_6 , V_7 ) ;
break;
case V_270 :
V_89 = F_97 ( V_11 , V_6 , V_7 ) ;
break;
case V_296 :
default:
F_30 ( & V_2 -> V_101 -> V_102 , L_29 ,
V_4 , V_297 ) ;
V_89 = F_84 ( V_11 , V_4 ,
V_299 ) ;
break;
}
return V_89 ;
}
int F_117 ( struct V_1 * V_2 )
{
T_4 V_63 , V_64 , V_185 , V_15 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_11 ;
if ( ! F_2 ( V_300 , & V_2 -> V_178 ) )
return 0 ;
V_63 = F_26 ( V_9 , V_301 ) ;
V_63 |= V_302 ;
F_19 ( V_9 , V_301 , V_63 ) ;
F_27 ( V_9 ) ;
F_58 ( V_300 , & V_2 -> V_178 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_13 ; V_15 ++ ) {
V_64 = ( V_9 -> V_16 . V_17 + V_15 ) / 32 ;
V_185 = ( V_9 -> V_16 . V_17 + V_15 ) % 32 ;
V_11 = & V_2 -> V_11 [ V_15 ] ;
V_63 = F_26 ( V_9 , F_70 ( V_64 ) ) ;
if ( V_63 & F_21 ( V_185 ) ) {
F_19 ( V_9 , F_70 ( V_64 ) , F_21 ( V_185 ) ) ;
if ( ! F_2 ( V_303 , & V_2 -> V_178 ) )
F_9 ( V_11 , true ) ;
}
}
return 0 ;
}
int F_118 ( struct V_304 * V_305 , int V_15 , T_2 * V_306 )
{
struct V_307 * V_308 = F_119 ( V_305 ) ;
struct V_43 * V_44 = V_308 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_309 ;
struct V_137 * V_138 ;
struct V_10 * V_11 ;
int V_89 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_30 , V_15 ) ;
V_89 = - V_121 ;
goto V_122;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_31 , V_15 ) ;
V_89 = - V_121 ;
goto V_122;
}
if ( ! F_120 ( V_306 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_32 ) ;
V_89 = - V_121 ;
goto V_122;
}
F_109 ( V_44 , V_11 -> V_152 . V_153 ,
V_11 -> V_151 ? V_11 -> V_151 : - 1 ,
true , false ) ;
F_121 (f, &vsi->mac_filter_list, list)
F_109 ( V_44 , V_138 -> V_271 , V_138 -> V_310 , true , false ) ;
F_40 ( & V_2 -> V_101 -> V_102 , L_33 , V_306 , V_15 ) ;
if ( F_41 ( V_44 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_8 ) ;
V_89 = - V_174 ;
goto V_122;
}
F_122 ( V_11 -> V_152 . V_153 , V_306 ) ;
V_11 -> V_273 = true ;
F_8 ( V_2 , V_11 ) ;
F_40 ( & V_2 -> V_101 -> V_102 , L_34 ) ;
V_122:
return V_89 ;
}
int F_123 ( struct V_304 * V_305 ,
int V_15 , T_3 V_283 , T_2 V_311 )
{
struct V_307 * V_308 = F_119 ( V_305 ) ;
struct V_1 * V_2 = V_308 -> V_44 -> V_309 ;
struct V_43 * V_44 ;
struct V_10 * V_11 ;
int V_89 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_30 , V_15 ) ;
V_89 = - V_121 ;
goto V_312;
}
if ( ( V_283 > V_284 ) || ( V_311 > 7 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_35 ) ;
V_89 = - V_121 ;
goto V_312;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_31 , V_15 ) ;
V_89 = - V_121 ;
goto V_312;
}
if ( F_15 ( V_44 -> V_52 . V_233 ) ==
( V_283 | ( V_311 << V_313 ) ) )
goto V_312;
if ( F_15 ( V_44 -> V_52 . V_233 ) == 0 && F_106 ( V_44 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 ,
L_36 ,
V_15 ) ;
F_8 ( V_2 , V_11 ) ;
}
if ( ( ! ( V_283 || V_311 ) ||
( V_283 | V_311 ) != F_15 ( V_44 -> V_52 . V_233 ) ) &&
V_44 -> V_52 . V_233 )
V_89 = F_112 ( V_44 , V_279 ) ;
if ( V_44 -> V_52 . V_233 ) {
V_89 = F_114 ( V_44 , ( F_15 ( V_44 -> V_52 . V_233 ) &
V_314 ) ) ;
if ( V_89 ) {
F_40 ( & V_44 -> V_309 -> V_101 -> V_102 ,
L_37 ,
V_89 , V_2 -> V_9 . V_141 . V_142 ) ;
}
}
if ( V_283 || V_311 )
V_89 = F_38 ( V_44 ,
V_283 | ( V_311 << V_313 ) ) ;
else
F_124 ( V_44 ) ;
if ( V_283 ) {
F_40 ( & V_2 -> V_101 -> V_102 , L_38 ,
V_283 , V_311 , V_15 ) ;
V_89 = F_112 ( V_44 , V_283 ) ;
if ( V_89 ) {
F_40 ( & V_44 -> V_309 -> V_101 -> V_102 ,
L_39 , V_89 ,
V_44 -> V_309 -> V_9 . V_141 . V_142 ) ;
goto V_312;
}
F_114 ( V_44 , V_279 ) ;
}
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_40 ) ;
goto V_312;
}
V_11 -> V_151 = F_15 ( V_44 -> V_52 . V_233 ) ;
V_89 = 0 ;
V_312:
return V_89 ;
}
int F_125 ( struct V_304 * V_305 , int V_15 , int V_315 ,
int V_316 )
{
struct V_307 * V_308 = F_119 ( V_305 ) ;
struct V_1 * V_2 = V_308 -> V_44 -> V_309 ;
struct V_43 * V_44 ;
struct V_10 * V_11 ;
int V_317 = 0 ;
int V_89 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_41 , V_15 ) ;
V_89 = - V_121 ;
goto error;
}
if ( V_315 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_42 ,
V_315 , V_15 ) ;
return - V_121 ;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_43 , V_15 ) ;
V_89 = - V_121 ;
goto error;
}
switch ( V_2 -> V_9 . V_25 . V_26 . V_36 ) {
case V_37 :
V_317 = 40000 ;
break;
case V_318 :
V_317 = 10000 ;
break;
case V_319 :
V_317 = 1000 ;
break;
default:
break;
}
if ( V_316 > V_317 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_44 ,
V_316 , V_11 -> V_15 ) ;
V_89 = - V_121 ;
goto error;
}
if ( ( V_316 < 50 ) && ( V_316 > 0 ) ) {
F_67 ( & V_2 -> V_101 -> V_102 , L_45 ) ;
V_316 = 50 ;
}
V_89 = F_42 ( & V_2 -> V_9 , V_44 -> V_140 ,
V_316 / V_320 ,
V_321 , NULL ) ;
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_46 ,
V_89 ) ;
V_89 = - V_174 ;
goto error;
}
V_11 -> V_154 = V_316 ;
error:
return V_89 ;
}
int F_126 ( struct V_304 * V_305 ,
int V_15 , struct V_322 * V_323 )
{
struct V_307 * V_308 = F_119 ( V_305 ) ;
struct V_43 * V_44 = V_308 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_309 ;
struct V_10 * V_11 ;
int V_89 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_30 , V_15 ) ;
V_89 = - V_121 ;
goto V_122;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_44 = V_2 -> V_44 [ V_11 -> V_147 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_31 , V_15 ) ;
V_89 = - V_121 ;
goto V_122;
}
V_323 -> V_11 = V_15 ;
memcpy ( & V_323 -> V_306 , V_11 -> V_152 . V_153 , V_146 ) ;
V_323 -> V_316 = V_11 -> V_154 ;
V_323 -> V_315 = 0 ;
V_323 -> V_310 = F_15 ( V_44 -> V_52 . V_233 ) & V_324 ;
V_323 -> V_311 = ( F_15 ( V_44 -> V_52 . V_233 ) & V_325 ) >>
V_313 ;
if ( V_11 -> V_31 == false )
V_323 -> V_326 = V_327 ;
else if ( V_11 -> V_35 == true )
V_323 -> V_326 = V_328 ;
else
V_323 -> V_326 = V_329 ;
V_323 -> V_195 = V_11 -> V_195 ;
V_89 = 0 ;
V_122:
return V_89 ;
}
int F_127 ( struct V_304 * V_305 , int V_15 , int V_330 )
{
struct V_307 * V_308 = F_119 ( V_305 ) ;
struct V_1 * V_2 = V_308 -> V_44 -> V_309 ;
struct V_21 V_22 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_11 ;
int V_14 ;
int V_89 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_30 , V_15 ) ;
V_89 = - V_121 ;
goto V_331;
}
V_11 = & V_2 -> V_11 [ V_15 ] ;
V_14 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
V_22 . V_27 = V_28 ;
V_22 . V_29 = V_30 ;
switch ( V_330 ) {
case V_327 :
V_11 -> V_31 = false ;
V_22 . V_32 . V_33 . V_34 =
V_2 -> V_9 . V_25 . V_26 . V_26 & V_38 ;
V_22 . V_32 . V_33 . V_36 =
V_2 -> V_9 . V_25 . V_26 . V_36 ;
break;
case V_328 :
V_11 -> V_31 = true ;
V_11 -> V_35 = true ;
V_22 . V_32 . V_33 . V_34 = true ;
V_22 . V_32 . V_33 . V_36 = V_37 ;
break;
case V_329 :
V_11 -> V_31 = true ;
V_11 -> V_35 = false ;
V_22 . V_32 . V_33 . V_34 = false ;
V_22 . V_32 . V_33 . V_36 = 0 ;
break;
default:
V_89 = - V_121 ;
goto V_331;
}
F_3 ( V_9 , V_14 , V_39 ,
0 , ( T_2 * ) & V_22 , sizeof( V_22 ) , NULL ) ;
V_331:
return V_89 ;
}
int F_128 ( struct V_304 * V_305 , int V_15 , bool V_332 )
{
struct V_307 * V_308 = F_119 ( V_305 ) ;
struct V_43 * V_44 = V_308 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_309 ;
struct V_333 V_334 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_11 ;
int V_89 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_30 , V_15 ) ;
V_89 = - V_121 ;
goto V_203;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
if ( V_332 == V_11 -> V_195 )
goto V_203;
V_11 -> V_195 = V_332 ;
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
V_334 . V_140 = V_2 -> V_44 [ V_11 -> V_147 ] -> V_140 ;
V_334 . V_335 = V_2 -> V_9 . V_106 ;
V_334 . V_52 . V_336 = F_129 ( V_337 ) ;
if ( V_332 )
V_334 . V_52 . V_338 |= ( V_339 |
V_340 ) ;
V_89 = F_130 ( V_9 , & V_334 , NULL ) ;
if ( V_89 ) {
F_30 ( & V_2 -> V_101 -> V_102 , L_47 ,
V_89 ) ;
V_89 = - V_174 ;
}
V_203:
return V_89 ;
}
