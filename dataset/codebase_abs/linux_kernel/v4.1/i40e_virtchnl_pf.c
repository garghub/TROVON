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
struct V_8 * V_9 = & V_2 -> V_9 ;
T_4 V_42 ;
V_42 = F_9 ( V_9 , F_10 ( V_11 -> V_15 ) ) ;
V_42 |= V_43 ;
F_11 ( V_9 , F_10 ( V_11 -> V_15 ) , V_42 ) ;
F_12 ( V_9 ) ;
}
static inline bool F_13 ( struct V_10 * V_11 , T_3 V_44 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 = F_14 ( V_2 , V_44 ) ;
return ( V_46 && ( V_46 -> V_15 == V_11 -> V_15 ) ) ;
}
static inline bool F_15 ( struct V_10 * V_11 , T_3 V_44 ,
T_2 V_47 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 = F_14 ( V_2 , V_44 ) ;
return ( V_46 && ( V_47 < V_46 -> V_48 ) ) ;
}
static inline bool F_16 ( struct V_10 * V_11 , T_2 V_49 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
return V_49 < V_2 -> V_9 . V_16 . V_50 ;
}
static T_3 F_17 ( struct V_10 * V_11 , T_3 V_44 ,
T_2 V_51 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 = F_14 ( V_2 , V_44 ) ;
T_3 V_52 = V_53 ;
if ( ! V_46 )
return V_52 ;
if ( F_18 ( V_46 -> V_54 . V_55 ) &
V_56 )
V_52 =
F_18 ( V_46 -> V_54 . V_57 [ V_51 ] ) ;
else
V_52 = F_18 ( V_46 -> V_54 . V_57 [ 0 ] ) +
V_51 ;
return V_52 ;
}
static void F_19 ( struct V_10 * V_11 , T_3 V_44 ,
struct V_58 * V_59 )
{
unsigned long V_60 = 0 , V_61 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_3 V_51 , V_52 ;
enum V_62 V_63 ;
T_3 V_64 , V_49 ;
T_4 V_42 , V_65 ;
T_3 V_66 = 0 ;
V_49 = V_59 -> V_49 ;
if ( 0 == V_49 )
V_65 = F_20 ( V_11 -> V_15 ) ;
else
V_65 = F_21 (
( ( V_2 -> V_9 . V_16 . V_50 - 1 ) * V_11 -> V_15 ) +
( V_49 - 1 ) ) ;
if ( V_59 -> V_67 == 0 && V_59 -> V_68 == 0 ) {
F_11 ( V_9 , V_65 , V_69 ) ;
goto V_70;
}
V_61 = V_59 -> V_67 ;
F_22 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_60 |= ( 1 <<
( V_71 *
V_51 ) ) ;
}
V_61 = V_59 -> V_68 ;
F_22 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
V_60 |= ( 1 <<
( V_71 * V_51
+ 1 ) ) ;
}
V_64 = F_23 ( & V_60 ,
( V_72 *
V_71 ) ) ;
V_51 = V_64 / V_71 ;
V_63 = V_64 % V_71 ;
V_52 = F_17 ( V_11 , V_44 , V_51 ) ;
V_42 = ( ( V_63 << V_73 ) | V_52 ) ;
F_11 ( V_9 , V_65 , V_42 ) ;
while ( V_64 < ( V_72 * V_71 ) ) {
switch ( V_63 ) {
case V_74 :
V_65 = F_24 ( V_52 ) ;
V_66 = V_59 -> V_75 ;
break;
case V_76 :
V_65 = F_25 ( V_52 ) ;
V_66 = V_59 -> V_77 ;
break;
default:
break;
}
V_64 = F_26 ( & V_60 ,
( V_72 *
V_71 ) ,
V_64 + 1 ) ;
if ( V_64 <
( V_72 * V_71 ) ) {
V_51 = V_64 / V_71 ;
V_63 = V_64 % V_71 ;
V_52 = F_17 ( V_11 , V_44 ,
V_51 ) ;
} else {
V_52 = V_53 ;
V_63 = 0 ;
}
V_42 = ( V_49 ) |
( V_63 << V_78 ) |
( V_52 << V_79 ) |
( 1 << V_80 ) |
( V_66 << V_81 ) ;
F_11 ( V_9 , V_65 , V_42 ) ;
}
V_70:
F_12 ( V_9 ) ;
}
static int F_27 ( struct V_10 * V_11 , T_3 V_44 ,
T_3 V_51 ,
struct V_82 * V_54 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_83 V_84 ;
struct V_45 * V_46 ;
T_3 V_52 ;
T_4 V_85 ;
int V_86 = 0 ;
V_52 = F_17 ( V_11 , V_44 , V_51 ) ;
V_46 = F_14 ( V_2 , V_44 ) ;
memset ( & V_84 , 0 , sizeof( struct V_83 ) ) ;
V_84 . V_87 = V_54 -> V_88 / 128 ;
V_84 . V_89 = V_54 -> V_90 ;
V_84 . V_91 = F_18 ( V_46 -> V_54 . V_92 [ 0 ] ) ;
V_84 . V_93 = 0 ;
V_84 . V_94 = V_54 -> V_95 ;
V_84 . V_96 = V_54 -> V_97 ;
V_86 = F_28 ( V_9 , V_52 ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_1 ,
V_52 , V_86 ) ;
V_86 = - V_100 ;
goto V_101;
}
V_86 = F_30 ( V_9 , V_52 , & V_84 ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_2 ,
V_52 , V_86 ) ;
V_86 = - V_100 ;
goto V_101;
}
V_85 = V_102 ;
V_85 |= ( ( V_9 -> V_103 << V_104 )
& V_105 ) ;
V_85 |= ( ( ( V_11 -> V_15 + V_9 -> V_16 . V_17 )
<< V_106 )
& V_107 ) ;
F_11 ( V_9 , F_31 ( V_52 ) , V_85 ) ;
F_12 ( V_9 ) ;
V_101:
return V_86 ;
}
static int F_32 ( struct V_10 * V_11 , T_3 V_44 ,
T_3 V_51 ,
struct V_108 * V_54 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_109 V_110 ;
T_3 V_52 ;
int V_86 = 0 ;
V_52 = F_17 ( V_11 , V_44 , V_51 ) ;
memset ( & V_110 , 0 , sizeof( struct V_109 ) ) ;
V_110 . V_87 = V_54 -> V_88 / 128 ;
V_110 . V_89 = V_54 -> V_90 ;
if ( V_54 -> V_111 ) {
V_110 . V_112 = V_113 |
V_114 |
V_115 |
V_116 ;
if ( V_54 -> V_117 > ( ( 2 * 1024 ) - 64 ) ) {
V_86 = - V_118 ;
goto V_119;
}
V_110 . V_120 = V_54 -> V_117 >> V_121 ;
V_110 . V_122 = 0x2 ;
}
if ( V_54 -> V_123 > ( ( 16 * 1024 ) - 128 ) ) {
V_86 = - V_118 ;
goto V_119;
}
V_110 . V_124 = V_54 -> V_123 >> V_125 ;
if ( V_54 -> V_126 >= ( 16 * 1024 ) || V_54 -> V_126 < 64 ) {
V_86 = - V_118 ;
goto V_119;
}
V_110 . V_127 = V_54 -> V_126 ;
V_110 . V_128 = 1 ;
V_110 . V_129 = 2 ;
V_110 . V_130 = 1 ;
V_110 . V_131 = 1 ;
V_110 . V_132 = 1 ;
V_86 = F_33 ( V_9 , V_52 ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_3 ,
V_52 , V_86 ) ;
V_86 = - V_100 ;
goto V_119;
}
V_86 = F_34 ( V_9 , V_52 , & V_110 ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_4 ,
V_52 , V_86 ) ;
V_86 = - V_100 ;
goto V_119;
}
V_119:
return V_86 ;
}
static int F_35 ( struct V_10 * V_11 , enum V_133 type )
{
struct V_134 * V_135 = NULL ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 ;
int V_86 = 0 ;
V_46 = F_36 ( V_2 , type , V_2 -> V_46 [ V_2 -> V_136 ] -> V_137 , V_11 -> V_15 ) ;
if ( ! V_46 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_5 ,
V_11 -> V_15 , V_2 -> V_9 . V_138 . V_139 ) ;
V_86 = - V_100 ;
goto V_140;
}
if ( type == V_141 ) {
T_2 V_142 [ V_143 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_11 -> V_144 = V_46 -> V_145 ;
V_11 -> V_146 = V_46 -> V_147 ;
if ( V_11 -> V_148 )
F_37 ( V_46 , V_11 -> V_148 ) ;
V_135 = F_38 ( V_46 , V_11 -> V_149 . V_150 ,
V_11 -> V_148 , true , false ) ;
if ( ! V_135 )
F_39 ( & V_2 -> V_98 -> V_99 ,
L_6 ) ;
V_135 = F_38 ( V_46 , V_142 , V_11 -> V_148 ,
true , false ) ;
if ( ! V_135 )
F_39 ( & V_2 -> V_98 -> V_99 ,
L_7 ) ;
}
V_86 = F_40 ( V_46 ) ;
if ( V_86 )
F_29 ( & V_2 -> V_98 -> V_99 , L_8 ) ;
if ( V_11 -> V_151 ) {
V_86 = F_41 ( & V_2 -> V_9 , V_46 -> V_137 ,
V_11 -> V_151 / 50 , 0 , NULL ) ;
if ( V_86 )
F_29 ( & V_2 -> V_98 -> V_99 , L_9 ,
V_11 -> V_15 , V_86 ) ;
}
V_140:
return V_86 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_4 V_42 , V_152 = 0 ;
int V_153 ;
F_11 ( V_9 , F_43 ( V_11 -> V_146 ) ,
V_154 ) ;
V_42 = V_155 ;
F_11 ( V_9 , F_44 ( V_11 -> V_15 ) , V_42 ) ;
for ( V_153 = 0 ; V_153 < V_2 -> V_46 [ V_11 -> V_144 ] -> V_48 ; V_153 ++ ) {
T_3 V_47 = F_17 ( V_11 , V_11 -> V_146 , V_153 ) ;
V_42 = ( V_47 & V_156 ) ;
F_11 ( V_9 , F_45 ( V_152 , V_11 -> V_15 ) , V_42 ) ;
V_152 ++ ;
}
for ( V_153 = 0 ; V_153 < 7 ; V_153 ++ ) {
if ( V_153 * 2 >= V_2 -> V_46 [ V_11 -> V_144 ] -> V_48 ) {
V_42 = 0x07FF07FF ;
} else {
T_3 V_47 = F_17 ( V_11 , V_11 -> V_146 ,
V_153 * 2 ) ;
V_42 = V_47 ;
V_47 = F_17 ( V_11 , V_11 -> V_146 ,
( V_153 * 2 ) + 1 ) ;
V_42 |= V_47 << 16 ;
}
F_11 ( V_9 , F_46 ( V_153 , V_11 -> V_146 ) , V_42 ) ;
}
F_12 ( V_9 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_12 ;
F_11 ( V_9 , F_44 ( V_11 -> V_15 ) , 0 ) ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 ++ )
F_11 ( V_9 , F_45 ( V_12 , V_11 -> V_15 ) ,
V_53 ) ;
F_12 ( V_9 ) ;
}
static void F_48 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_4 V_65 , V_42 ;
int V_12 , V_157 ;
if ( V_11 -> V_144 ) {
F_49 ( V_2 -> V_46 [ V_11 -> V_144 ] ) ;
V_11 -> V_144 = 0 ;
V_11 -> V_146 = 0 ;
}
V_157 = V_2 -> V_9 . V_16 . V_50 ;
for ( V_12 = 0 ; V_12 < V_157 ; V_12 ++ ) {
if ( 0 == V_12 )
V_65 = F_50 ( V_11 -> V_15 ) ;
else
V_65 = F_51 ( ( ( V_157 - 1 ) *
( V_11 -> V_15 ) )
+ ( V_12 - 1 ) ) ;
F_11 ( V_9 , V_65 , V_158 ) ;
F_12 ( V_9 ) ;
}
for ( V_12 = 0 ; V_12 < V_157 ; V_12 ++ ) {
if ( 0 == V_12 )
V_65 = F_20 ( V_11 -> V_15 ) ;
else
V_65 = F_21 ( ( ( V_157 - 1 ) *
( V_11 -> V_15 ) )
+ ( V_12 - 1 ) ) ;
V_42 = ( V_159 |
V_160 ) ;
F_11 ( V_9 , V_65 , V_42 ) ;
F_12 ( V_9 ) ;
}
V_11 -> V_161 = 0 ;
V_11 -> V_19 = 0 ;
}
static int F_52 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_152 = 0 ;
int V_86 ;
V_86 = F_35 ( V_11 , V_141 ) ;
if ( V_86 )
goto V_162;
V_152 += V_2 -> V_46 [ V_11 -> V_144 ] -> V_48 ;
F_53 ( V_163 , & V_11 -> V_164 ) ;
V_11 -> V_161 = V_152 ;
F_53 ( V_18 , & V_11 -> V_19 ) ;
V_162:
if ( V_86 )
F_48 ( V_11 ) ;
return V_86 ;
}
static int F_54 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_165 , V_12 ;
T_4 V_42 ;
V_165 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
F_11 ( V_9 , V_166 ,
V_167 | ( V_165 << V_168 ) ) ;
for ( V_12 = 0 ; V_12 < 100 ; V_12 ++ ) {
V_42 = F_9 ( V_9 , V_169 ) ;
if ( ( V_42 & V_170 ) == 0 )
return 0 ;
F_55 ( 1 ) ;
}
return - V_171 ;
}
void F_56 ( struct V_10 * V_11 , bool V_172 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
bool V_173 = false ;
int V_12 ;
T_4 V_42 ;
if ( F_57 ( V_174 , & V_2 -> V_175 ) )
return;
F_58 ( V_20 , & V_11 -> V_19 ) ;
if ( ! V_172 ) {
V_42 = F_9 ( V_9 , F_10 ( V_11 -> V_15 ) ) ;
V_42 |= V_43 ;
F_11 ( V_9 , F_10 ( V_11 -> V_15 ) , V_42 ) ;
F_12 ( V_9 ) ;
}
if ( F_54 ( V_11 ) )
F_29 ( & V_2 -> V_98 -> V_99 , L_10 ,
V_11 -> V_15 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
F_59 ( 10000 , 20000 ) ;
V_42 = F_9 ( V_9 , F_60 ( V_11 -> V_15 ) ) ;
if ( V_42 & V_176 ) {
V_173 = true ;
break;
}
}
if ( V_172 )
F_59 ( 10000 , 20000 ) ;
if ( ! V_173 )
F_29 ( & V_2 -> V_98 -> V_99 , L_11 ,
V_11 -> V_15 ) ;
F_11 ( V_9 , F_61 ( V_11 -> V_15 ) , V_177 ) ;
V_42 = F_9 ( V_9 , F_10 ( V_11 -> V_15 ) ) ;
V_42 &= ~ V_43 ;
F_11 ( V_9 , F_10 ( V_11 -> V_15 ) , V_42 ) ;
if ( V_11 -> V_144 == 0 )
goto V_178;
F_62 ( V_2 -> V_46 [ V_11 -> V_144 ] , false ) ;
V_178:
F_48 ( V_11 ) ;
F_52 ( V_11 ) ;
F_42 ( V_11 ) ;
F_53 ( V_20 , & V_11 -> V_19 ) ;
F_11 ( V_9 , F_61 ( V_11 -> V_15 ) , V_179 ) ;
F_12 ( V_9 ) ;
F_58 ( V_174 , & V_2 -> V_175 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_4 V_65 , V_180 ;
int V_12 , V_181 , V_15 ;
if ( ! V_2 -> V_11 )
return;
while ( F_57 ( V_174 , & V_2 -> V_175 ) )
F_59 ( 1000 , 2000 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ )
if ( F_2 ( V_18 , & V_2 -> V_11 [ V_12 ] . V_19 ) )
F_62 ( V_2 -> V_46 [ V_2 -> V_11 [ V_12 ] . V_144 ] ,
false ) ;
if ( ! F_64 ( V_2 -> V_98 ) )
F_65 ( V_2 -> V_98 ) ;
else
F_66 ( & V_2 -> V_98 -> V_99 , L_12 ) ;
F_67 ( 20 ) ;
V_181 = V_2 -> V_13 ;
V_2 -> V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_181 ; V_12 ++ ) {
if ( F_2 ( V_18 , & V_2 -> V_11 [ V_12 ] . V_19 ) )
F_48 ( & V_2 -> V_11 [ V_12 ] ) ;
F_47 ( & V_2 -> V_11 [ V_12 ] ) ;
}
F_68 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( ! F_64 ( V_2 -> V_98 ) ) {
for ( V_15 = 0 ; V_15 < V_181 ; V_15 ++ ) {
V_65 = ( V_9 -> V_16 . V_17 + V_15 ) / 32 ;
V_180 = ( V_9 -> V_16 . V_17 + V_15 ) % 32 ;
F_11 ( V_9 , F_69 ( V_65 ) , ( 1 << V_180 ) ) ;
}
}
F_58 ( V_174 , & V_2 -> V_175 ) ;
}
int F_70 ( struct V_1 * V_2 , T_3 V_13 )
{
struct V_10 * V_182 ;
int V_12 , V_86 = 0 ;
F_71 ( V_2 ) ;
if ( F_72 ( V_2 -> V_98 ) != V_13 ) {
V_86 = F_73 ( V_2 -> V_98 , V_13 ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_13 , V_86 ) ;
V_2 -> V_13 = 0 ;
goto V_183;
}
}
V_182 = F_74 ( V_13 , sizeof( struct V_10 ) , V_184 ) ;
if ( ! V_182 ) {
V_86 = - V_185 ;
goto V_186;
}
V_2 -> V_11 = V_182 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_182 [ V_12 ] . V_2 = V_2 ;
V_182 [ V_12 ] . V_187 = V_188 ;
V_182 [ V_12 ] . V_15 = V_12 ;
F_53 ( V_189 , & V_182 [ V_12 ] . V_164 ) ;
V_182 [ V_12 ] . V_190 = true ;
F_56 ( & V_182 [ V_12 ] , false ) ;
F_42 ( & V_182 [ V_12 ] ) ;
}
V_2 -> V_13 = V_13 ;
V_186:
if ( V_86 )
F_63 ( V_2 ) ;
V_183:
F_75 ( V_2 ) ;
return V_86 ;
}
static int F_76 ( struct V_191 * V_98 , int V_192 )
{
#ifdef F_77
struct V_1 * V_2 = F_78 ( V_98 ) ;
int V_193 = F_72 ( V_98 ) ;
int V_194 = 0 ;
F_39 ( & V_98 -> V_99 , L_14 , V_192 ) ;
if ( V_193 && V_193 != V_192 )
F_63 ( V_2 ) ;
else if ( V_193 && V_193 == V_192 )
goto V_195;
if ( V_192 > V_2 -> V_196 ) {
V_194 = - V_197 ;
goto V_198;
}
V_194 = F_70 ( V_2 , V_192 ) ;
if ( V_194 ) {
F_66 ( & V_98 -> V_99 , L_15 , V_194 ) ;
goto V_198;
}
V_195:
return V_192 ;
V_198:
return V_194 ;
#endif
return 0 ;
}
int F_79 ( struct V_191 * V_98 , int V_192 )
{
struct V_1 * V_2 = F_78 ( V_98 ) ;
if ( V_192 ) {
if ( ! ( V_2 -> V_199 & V_200 ) ) {
V_2 -> V_199 |= V_200 ;
F_80 ( V_2 ,
F_81 ( V_201 ) ) ;
}
return F_76 ( V_98 , V_192 ) ;
}
if ( ! F_64 ( V_2 -> V_98 ) ) {
F_63 ( V_2 ) ;
V_2 -> V_199 &= ~ V_200 ;
F_80 ( V_2 , F_81 ( V_201 ) ) ;
} else {
F_66 ( & V_98 -> V_99 , L_16 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_82 ( struct V_10 * V_11 , T_4 V_4 ,
T_4 V_5 , T_2 * V_6 , T_3 V_7 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_14 ;
T_1 V_202 ;
if ( ! V_11 || V_11 -> V_15 >= V_11 -> V_2 -> V_13 )
return - V_118 ;
V_2 = V_11 -> V_2 ;
V_9 = & V_2 -> V_9 ;
V_14 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
if ( V_5 ) {
V_11 -> V_203 ++ ;
F_29 ( & V_2 -> V_98 -> V_99 , L_17 ,
V_4 , V_5 ) ;
if ( V_11 -> V_203 >
V_204 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_18 ,
V_11 -> V_15 ) ;
F_29 ( & V_2 -> V_98 -> V_99 , L_19 ) ;
F_53 ( V_205 , & V_11 -> V_19 ) ;
}
} else {
V_11 -> V_206 ++ ;
}
V_202 = F_3 ( V_9 , V_14 , V_4 , V_5 ,
V_6 , V_7 , NULL ) ;
if ( V_202 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_20 ,
V_11 -> V_15 , V_2 -> V_9 . V_138 . V_139 ) ;
return - V_171 ;
}
return 0 ;
}
static int F_83 ( struct V_10 * V_11 ,
enum V_3 V_207 ,
T_1 V_208 )
{
return F_82 ( V_11 , V_207 , V_208 , NULL , 0 ) ;
}
static int F_84 ( struct V_10 * V_11 )
{
struct V_209 V_54 = {
V_210 , V_211
} ;
return F_82 ( V_11 , V_212 ,
V_213 , ( T_2 * ) & V_54 ,
sizeof( struct
V_209 ) ) ;
}
static int F_85 ( struct V_10 * V_11 )
{
struct V_214 * V_215 = NULL ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_202 = 0 ;
struct V_45 * V_46 ;
int V_12 = 0 , V_216 = 0 ;
int V_217 = 1 ;
int V_86 ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
V_202 = V_218 ;
goto V_194;
}
V_216 = ( sizeof( struct V_214 ) +
sizeof( struct V_219 ) * V_217 ) ;
V_215 = F_86 ( V_216 , V_184 ) ;
if ( ! V_215 ) {
V_202 = V_220 ;
V_216 = 0 ;
goto V_194;
}
V_215 -> V_221 = V_222 ;
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( ! V_46 -> V_54 . V_223 )
V_215 -> V_221 |= V_224 ;
V_215 -> V_217 = V_217 ;
V_215 -> V_161 = V_11 -> V_161 ;
V_215 -> V_225 = V_2 -> V_9 . V_16 . V_50 ;
if ( V_11 -> V_144 ) {
V_215 -> V_226 [ V_12 ] . V_44 = V_11 -> V_146 ;
V_215 -> V_226 [ V_12 ] . V_227 = V_141 ;
V_215 -> V_226 [ V_12 ] . V_161 =
V_2 -> V_46 [ V_11 -> V_144 ] -> V_48 ;
memcpy ( V_215 -> V_226 [ V_12 ] . V_228 ,
V_11 -> V_149 . V_150 , V_143 ) ;
V_12 ++ ;
}
F_53 ( V_20 , & V_11 -> V_19 ) ;
V_194:
V_86 = F_82 ( V_11 , V_229 ,
V_202 , ( T_2 * ) V_215 , V_216 ) ;
F_68 ( V_215 ) ;
return V_86 ;
}
static void F_87 ( struct V_10 * V_11 )
{
if ( F_2 ( V_20 , & V_11 -> V_19 ) )
F_56 ( V_11 , false ) ;
}
static int F_88 ( struct V_10 * V_11 ,
T_2 * V_6 , T_3 V_7 )
{
struct V_230 * V_54 =
(struct V_230 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_45 * V_46 ;
bool V_231 = false ;
T_1 V_202 ;
V_46 = F_14 ( V_2 , V_54 -> V_44 ) ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_163 , & V_11 -> V_164 ) ||
! F_13 ( V_11 , V_54 -> V_44 ) ||
( V_46 -> type != V_232 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( V_54 -> V_199 & V_233 )
V_231 = true ;
V_202 = F_89 ( V_9 , V_46 -> V_137 ,
V_231 , NULL ) ;
V_119:
return F_83 ( V_11 ,
V_234 ,
V_202 ) ;
}
static int F_90 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_235 * V_236 =
(struct V_235 * ) V_6 ;
struct V_237 * V_238 ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_44 , V_51 ;
T_1 V_202 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_202 = V_218 ;
goto V_119;
}
V_44 = V_236 -> V_44 ;
if ( ! F_13 ( V_11 , V_44 ) ) {
V_202 = V_218 ;
goto V_119;
}
for ( V_12 = 0 ; V_12 < V_236 -> V_161 ; V_12 ++ ) {
V_238 = & V_236 -> V_239 [ V_12 ] ;
V_51 = V_238 -> V_240 . V_241 ;
if ( ( V_238 -> V_240 . V_44 != V_44 ) ||
( V_238 -> V_242 . V_44 != V_44 ) ||
( V_238 -> V_242 . V_241 != V_51 ) ||
! F_15 ( V_11 , V_44 , V_51 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( F_32 ( V_11 , V_44 , V_51 ,
& V_238 -> V_242 ) ||
F_27 ( V_11 , V_44 , V_51 ,
& V_238 -> V_240 ) ) {
V_202 = V_218 ;
goto V_119;
}
}
V_2 -> V_46 [ V_11 -> V_144 ] -> V_161 = V_236 -> V_161 ;
V_119:
return F_83 ( V_11 , V_243 ,
V_202 ) ;
}
static int F_91 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_6 ;
struct V_58 * V_246 ;
T_3 V_44 , V_51 , V_49 ;
T_1 V_202 = 0 ;
unsigned long V_61 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_202 = V_218 ;
goto V_119;
}
for ( V_12 = 0 ; V_12 < V_245 -> V_247 ; V_12 ++ ) {
V_246 = & V_245 -> V_59 [ V_12 ] ;
V_49 = V_246 -> V_49 ;
V_44 = V_246 -> V_44 ;
if ( ! F_16 ( V_11 , V_49 ) ||
! F_13 ( V_11 , V_44 ) ) {
V_202 = V_218 ;
goto V_119;
}
V_61 = V_246 -> V_67 ;
F_22 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_15 ( V_11 , V_44 ,
V_51 ) ) {
V_202 = V_218 ;
goto V_119;
}
}
V_61 = V_246 -> V_68 ;
F_22 (vsi_queue_id, &tempmap, I40E_MAX_VSI_QP) {
if ( ! F_15 ( V_11 , V_44 ,
V_51 ) ) {
V_202 = V_218 ;
goto V_119;
}
}
F_19 ( V_11 , V_44 , V_246 ) ;
}
V_119:
return F_83 ( V_11 , V_248 ,
V_202 ) ;
}
static int F_92 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_249 * V_250 =
(struct V_249 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_44 = V_250 -> V_44 ;
T_1 V_202 = 0 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( ! F_13 ( V_11 , V_44 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( ( 0 == V_250 -> V_251 ) && ( 0 == V_250 -> V_252 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( F_62 ( V_2 -> V_46 [ V_11 -> V_144 ] , true ) )
V_202 = V_253 ;
V_119:
return F_83 ( V_11 , V_254 ,
V_202 ) ;
}
static int F_93 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_249 * V_250 =
(struct V_249 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_202 = 0 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( ! F_13 ( V_11 , V_250 -> V_44 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( ( 0 == V_250 -> V_251 ) && ( 0 == V_250 -> V_252 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( F_62 ( V_2 -> V_46 [ V_11 -> V_144 ] , false ) )
V_202 = V_253 ;
V_119:
return F_83 ( V_11 , V_255 ,
V_202 ) ;
}
static int F_94 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_249 * V_250 =
(struct V_249 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_256 V_257 ;
T_1 V_202 = 0 ;
struct V_45 * V_46 ;
memset ( & V_257 , 0 , sizeof( struct V_256 ) ) ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ) {
V_202 = V_218 ;
goto V_119;
}
if ( ! F_13 ( V_11 , V_250 -> V_44 ) ) {
V_202 = V_218 ;
goto V_119;
}
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( ! V_46 ) {
V_202 = V_218 ;
goto V_119;
}
F_95 ( V_46 ) ;
V_257 = V_46 -> V_258 ;
V_119:
return F_82 ( V_11 , V_259 , V_202 ,
( T_2 * ) & V_257 , sizeof( V_257 ) ) ;
}
static inline int F_96 ( struct V_10 * V_11 , T_2 * V_260 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_86 = 0 ;
if ( F_97 ( V_260 ) ||
F_98 ( V_260 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_21 , V_260 ) ;
V_86 = V_261 ;
} else if ( V_11 -> V_262 && ! F_99 ( V_260 ) &&
! F_100 ( V_260 , V_11 -> V_149 . V_150 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_22 ) ;
V_86 = - V_197 ;
}
return V_86 ;
}
static int F_101 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 = NULL ;
T_3 V_44 = V_264 -> V_44 ;
T_1 V_86 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_163 , & V_11 -> V_164 ) ||
! F_13 ( V_11 , V_44 ) ) {
V_86 = V_218 ;
goto V_119;
}
for ( V_12 = 0 ; V_12 < V_264 -> V_265 ; V_12 ++ ) {
V_86 = F_96 ( V_11 , V_264 -> V_266 [ V_12 ] . V_150 ) ;
if ( V_86 )
goto V_119;
}
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
for ( V_12 = 0 ; V_12 < V_264 -> V_265 ; V_12 ++ ) {
struct V_134 * V_135 ;
V_135 = F_102 ( V_46 , V_264 -> V_266 [ V_12 ] . V_150 , true , false ) ;
if ( ! V_135 ) {
if ( F_103 ( V_46 ) )
V_135 = F_104 ( V_46 , V_264 -> V_266 [ V_12 ] . V_150 ,
true , false ) ;
else
V_135 = F_38 ( V_46 , V_264 -> V_266 [ V_12 ] . V_150 , - 1 ,
true , false ) ;
}
if ( ! V_135 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_23 ) ;
V_86 = V_218 ;
goto V_119;
}
}
if ( F_40 ( V_46 ) )
F_29 ( & V_2 -> V_98 -> V_99 , L_24 ) ;
V_119:
return F_83 ( V_11 , V_267 ,
V_86 ) ;
}
static int F_105 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 = NULL ;
T_3 V_44 = V_264 -> V_44 ;
T_1 V_86 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_163 , & V_11 -> V_164 ) ||
! F_13 ( V_11 , V_44 ) ) {
V_86 = V_218 ;
goto V_119;
}
for ( V_12 = 0 ; V_12 < V_264 -> V_265 ; V_12 ++ ) {
if ( F_97 ( V_264 -> V_266 [ V_12 ] . V_150 ) ||
F_98 ( V_264 -> V_266 [ V_12 ] . V_150 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_21 ,
V_264 -> V_266 [ V_12 ] . V_150 ) ;
V_86 = V_261 ;
goto V_119;
}
}
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
for ( V_12 = 0 ; V_12 < V_264 -> V_265 ; V_12 ++ )
F_106 ( V_46 , V_264 -> V_266 [ V_12 ] . V_150 ,
V_268 , true , false ) ;
if ( F_40 ( V_46 ) )
F_29 ( & V_2 -> V_98 -> V_99 , L_24 ) ;
V_119:
return F_83 ( V_11 , V_269 ,
V_86 ) ;
}
static int F_107 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 = NULL ;
T_3 V_44 = V_271 -> V_44 ;
T_1 V_202 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_163 , & V_11 -> V_164 ) ||
! F_13 ( V_11 , V_44 ) ) {
V_202 = V_218 ;
goto V_119;
}
for ( V_12 = 0 ; V_12 < V_271 -> V_265 ; V_12 ++ ) {
if ( V_271 -> V_272 [ V_12 ] > V_273 ) {
V_202 = V_218 ;
F_29 ( & V_2 -> V_98 -> V_99 ,
L_25 , V_271 -> V_272 [ V_12 ] ) ;
goto V_119;
}
}
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( V_46 -> V_54 . V_223 ) {
V_202 = V_218 ;
goto V_119;
}
F_108 ( V_46 ) ;
for ( V_12 = 0 ; V_12 < V_271 -> V_265 ; V_12 ++ ) {
int V_86 = F_109 ( V_46 , V_271 -> V_272 [ V_12 ] ) ;
if ( V_86 )
F_29 ( & V_2 -> V_98 -> V_99 ,
L_26 ,
V_271 -> V_272 [ V_12 ] , V_86 ) ;
}
V_119:
return F_83 ( V_11 , V_274 , V_202 ) ;
}
static int F_110 ( struct V_10 * V_11 , T_2 * V_6 , T_3 V_7 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_6 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_45 * V_46 = NULL ;
T_3 V_44 = V_271 -> V_44 ;
T_1 V_202 = 0 ;
int V_12 ;
if ( ! F_2 ( V_20 , & V_11 -> V_19 ) ||
! F_2 ( V_163 , & V_11 -> V_164 ) ||
! F_13 ( V_11 , V_44 ) ) {
V_202 = V_218 ;
goto V_119;
}
for ( V_12 = 0 ; V_12 < V_271 -> V_265 ; V_12 ++ ) {
if ( V_271 -> V_272 [ V_12 ] > V_273 ) {
V_202 = V_218 ;
goto V_119;
}
}
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( V_46 -> V_54 . V_223 ) {
V_202 = V_218 ;
goto V_119;
}
for ( V_12 = 0 ; V_12 < V_271 -> V_265 ; V_12 ++ ) {
int V_86 = F_111 ( V_46 , V_271 -> V_272 [ V_12 ] ) ;
if ( V_86 )
F_29 ( & V_2 -> V_98 -> V_99 ,
L_27 ,
V_271 -> V_272 [ V_12 ] , V_86 ) ;
}
V_119:
return F_83 ( V_11 , V_275 , V_202 ) ;
}
static int F_112 ( struct V_10 * V_11 , T_4 V_4 ,
T_4 V_5 , T_2 * V_6 , T_3 V_7 )
{
bool V_276 = false ;
int V_277 ;
if ( F_2 ( V_205 , & V_11 -> V_19 ) )
return V_218 ;
switch ( V_4 ) {
case V_212 :
V_277 = sizeof( struct V_209 ) ;
break;
case V_278 :
case V_229 :
V_277 = 0 ;
break;
case V_279 :
V_277 = sizeof( struct V_82 ) ;
break;
case V_280 :
V_277 = sizeof( struct V_108 ) ;
break;
case V_243 :
V_277 = sizeof( struct V_235 ) ;
if ( V_7 >= V_277 ) {
struct V_235 * V_281 =
(struct V_235 * ) V_6 ;
V_277 += ( V_281 -> V_161 *
sizeof( struct
V_237 ) ) ;
if ( V_281 -> V_161 == 0 )
V_276 = true ;
}
break;
case V_248 :
V_277 = sizeof( struct V_244 ) ;
if ( V_7 >= V_277 ) {
struct V_244 * V_282 =
(struct V_244 * ) V_6 ;
V_277 += ( V_282 -> V_247 *
sizeof( struct V_58 ) ) ;
if ( V_282 -> V_247 == 0 )
V_276 = true ;
}
break;
case V_254 :
case V_255 :
V_277 = sizeof( struct V_249 ) ;
break;
case V_267 :
case V_269 :
V_277 = sizeof( struct V_263 ) ;
if ( V_7 >= V_277 ) {
struct V_263 * V_283 =
(struct V_263 * ) V_6 ;
V_277 += V_283 -> V_265 *
sizeof( struct V_284 ) ;
if ( V_283 -> V_265 == 0 )
V_276 = true ;
}
break;
case V_274 :
case V_275 :
V_277 = sizeof( struct V_270 ) ;
if ( V_7 >= V_277 ) {
struct V_270 * V_271 =
(struct V_270 * ) V_6 ;
V_277 += V_271 -> V_265 * sizeof( T_3 ) ;
if ( V_271 -> V_265 == 0 )
V_276 = true ;
}
break;
case V_234 :
V_277 = sizeof( struct V_230 ) ;
break;
case V_259 :
V_277 = sizeof( struct V_249 ) ;
break;
case V_39 :
case V_285 :
default:
return - V_197 ;
break;
}
if ( ( V_277 != V_7 ) || ( V_276 ) ) {
F_83 ( V_11 , V_4 , V_218 ) ;
return - V_118 ;
} else {
return 0 ;
}
}
int F_113 ( struct V_1 * V_2 , T_3 V_15 , T_4 V_4 ,
T_4 V_5 , T_2 * V_6 , T_3 V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_286 = V_15 - V_9 -> V_16 . V_17 ;
struct V_10 * V_11 ;
int V_86 ;
V_2 -> V_287 ++ ;
if ( V_286 >= V_2 -> V_13 )
return - V_118 ;
V_11 = & ( V_2 -> V_11 [ V_286 ] ) ;
V_86 = F_112 ( V_11 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_28 ,
V_286 , V_4 , V_7 ) ;
return V_86 ;
}
switch ( V_4 ) {
case V_212 :
V_86 = F_84 ( V_11 ) ;
break;
case V_229 :
V_86 = F_85 ( V_11 ) ;
break;
case V_278 :
F_87 ( V_11 ) ;
V_86 = 0 ;
break;
case V_234 :
V_86 = F_88 ( V_11 , V_6 , V_7 ) ;
break;
case V_243 :
V_86 = F_90 ( V_11 , V_6 , V_7 ) ;
break;
case V_248 :
V_86 = F_91 ( V_11 , V_6 , V_7 ) ;
break;
case V_254 :
V_86 = F_92 ( V_11 , V_6 , V_7 ) ;
F_4 ( V_11 ) ;
break;
case V_255 :
V_86 = F_93 ( V_11 , V_6 , V_7 ) ;
break;
case V_267 :
V_86 = F_101 ( V_11 , V_6 , V_7 ) ;
break;
case V_269 :
V_86 = F_105 ( V_11 , V_6 , V_7 ) ;
break;
case V_274 :
V_86 = F_107 ( V_11 , V_6 , V_7 ) ;
break;
case V_275 :
V_86 = F_110 ( V_11 , V_6 , V_7 ) ;
break;
case V_259 :
V_86 = F_94 ( V_11 , V_6 , V_7 ) ;
break;
case V_285 :
default:
F_29 ( & V_2 -> V_98 -> V_99 , L_29 ,
V_4 , V_286 ) ;
V_86 = F_83 ( V_11 , V_4 ,
V_288 ) ;
break;
}
return V_86 ;
}
int F_114 ( struct V_1 * V_2 )
{
T_4 V_42 , V_65 , V_180 , V_15 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_11 ;
if ( ! F_2 ( V_289 , & V_2 -> V_175 ) )
return 0 ;
V_42 = F_9 ( V_9 , V_290 ) ;
V_42 |= V_291 ;
F_11 ( V_9 , V_290 , V_42 ) ;
F_12 ( V_9 ) ;
F_58 ( V_289 , & V_2 -> V_175 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_13 ; V_15 ++ ) {
V_65 = ( V_9 -> V_16 . V_17 + V_15 ) / 32 ;
V_180 = ( V_9 -> V_16 . V_17 + V_15 ) % 32 ;
V_11 = & V_2 -> V_11 [ V_15 ] ;
V_42 = F_9 ( V_9 , F_69 ( V_65 ) ) ;
if ( V_42 & ( 1 << V_180 ) ) {
F_11 ( V_9 , F_69 ( V_65 ) , ( 1 << V_180 ) ) ;
if ( ! F_2 ( V_292 , & V_2 -> V_175 ) )
F_56 ( V_11 , true ) ;
}
}
return 0 ;
}
int F_115 ( struct V_293 * V_294 , int V_15 , T_2 * V_295 )
{
struct V_296 * V_297 = F_116 ( V_294 ) ;
struct V_45 * V_46 = V_297 -> V_46 ;
struct V_1 * V_2 = V_46 -> V_298 ;
struct V_134 * V_135 ;
struct V_10 * V_11 ;
int V_86 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_30 , V_15 ) ;
V_86 = - V_118 ;
goto V_119;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_31 , V_15 ) ;
V_86 = - V_118 ;
goto V_119;
}
if ( ! F_117 ( V_295 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_32 ) ;
V_86 = - V_118 ;
goto V_119;
}
F_106 ( V_46 , V_11 -> V_149 . V_150 , V_11 -> V_148 ,
true , false ) ;
F_118 (f, &vsi->mac_filter_list, list)
F_106 ( V_46 , V_135 -> V_260 , V_135 -> V_299 , true , false ) ;
F_39 ( & V_2 -> V_98 -> V_99 , L_33 , V_295 , V_15 ) ;
if ( F_40 ( V_46 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_8 ) ;
V_86 = - V_171 ;
goto V_119;
}
F_119 ( V_11 -> V_149 . V_150 , V_295 ) ;
V_11 -> V_262 = true ;
F_8 ( V_2 , V_11 ) ;
F_39 ( & V_2 -> V_98 -> V_99 , L_34 ) ;
V_119:
return V_86 ;
}
int F_120 ( struct V_293 * V_294 ,
int V_15 , T_3 V_272 , T_2 V_300 )
{
struct V_296 * V_297 = F_116 ( V_294 ) ;
struct V_1 * V_2 = V_297 -> V_46 -> V_298 ;
struct V_45 * V_46 ;
struct V_10 * V_11 ;
int V_86 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_30 , V_15 ) ;
V_86 = - V_118 ;
goto V_301;
}
if ( ( V_272 > V_273 ) || ( V_300 > 7 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_35 ) ;
V_86 = - V_118 ;
goto V_301;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_31 , V_15 ) ;
V_86 = - V_118 ;
goto V_301;
}
if ( V_46 -> V_54 . V_223 == 0 && F_103 ( V_46 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 ,
L_36 ,
V_15 ) ;
F_8 ( V_2 , V_11 ) ;
}
if ( ( ! ( V_272 || V_300 ) ||
( V_272 | V_300 ) != F_18 ( V_46 -> V_54 . V_223 ) ) &&
V_46 -> V_54 . V_223 )
V_86 = F_109 ( V_46 , V_268 ) ;
if ( V_46 -> V_54 . V_223 ) {
V_86 = F_111 ( V_46 , ( F_18 ( V_46 -> V_54 . V_223 ) &
V_302 ) ) ;
if ( V_86 ) {
F_39 ( & V_46 -> V_298 -> V_98 -> V_99 ,
L_37 ,
V_86 , V_2 -> V_9 . V_138 . V_139 ) ;
}
}
if ( V_272 || V_300 )
V_86 = F_37 ( V_46 ,
V_272 | ( V_300 << V_303 ) ) ;
else
F_121 ( V_46 ) ;
if ( V_272 ) {
F_39 ( & V_2 -> V_98 -> V_99 , L_38 ,
V_272 , V_300 , V_15 ) ;
V_86 = F_109 ( V_46 , V_272 ) ;
if ( V_86 ) {
F_39 ( & V_46 -> V_298 -> V_98 -> V_99 ,
L_39 , V_86 ,
V_46 -> V_298 -> V_9 . V_138 . V_139 ) ;
goto V_301;
}
F_111 ( V_46 , V_268 ) ;
}
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_40 ) ;
goto V_301;
}
V_11 -> V_148 = F_18 ( V_46 -> V_54 . V_223 ) ;
V_86 = 0 ;
V_301:
return V_86 ;
}
int F_122 ( struct V_293 * V_294 , int V_15 , int V_304 ,
int V_305 )
{
struct V_296 * V_297 = F_116 ( V_294 ) ;
struct V_1 * V_2 = V_297 -> V_46 -> V_298 ;
struct V_45 * V_46 ;
struct V_10 * V_11 ;
int V_306 = 0 ;
int V_86 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_41 , V_15 ) ;
V_86 = - V_118 ;
goto error;
}
if ( V_304 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_42 ,
V_304 , V_15 ) ;
return - V_118 ;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_43 , V_15 ) ;
V_86 = - V_118 ;
goto error;
}
switch ( V_2 -> V_9 . V_25 . V_26 . V_36 ) {
case V_37 :
V_306 = 40000 ;
break;
case V_307 :
V_306 = 10000 ;
break;
case V_308 :
V_306 = 1000 ;
break;
default:
break;
}
if ( V_305 > V_306 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_44 ,
V_305 , V_11 -> V_15 ) ;
V_86 = - V_118 ;
goto error;
}
if ( ( V_305 < 50 ) && ( V_305 > 0 ) ) {
F_66 ( & V_2 -> V_98 -> V_99 , L_45 ) ;
V_305 = 50 ;
}
V_86 = F_41 ( & V_2 -> V_9 , V_46 -> V_137 ,
V_305 / V_309 ,
V_310 , NULL ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_46 ,
V_86 ) ;
V_86 = - V_171 ;
goto error;
}
V_11 -> V_151 = V_305 ;
error:
return V_86 ;
}
int F_123 ( struct V_293 * V_294 ,
int V_15 , struct V_311 * V_312 )
{
struct V_296 * V_297 = F_116 ( V_294 ) ;
struct V_45 * V_46 = V_297 -> V_46 ;
struct V_1 * V_2 = V_46 -> V_298 ;
struct V_10 * V_11 ;
int V_86 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_30 , V_15 ) ;
V_86 = - V_118 ;
goto V_119;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
V_46 = V_2 -> V_46 [ V_11 -> V_144 ] ;
if ( ! F_2 ( V_18 , & V_11 -> V_19 ) ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_31 , V_15 ) ;
V_86 = - V_118 ;
goto V_119;
}
V_312 -> V_11 = V_15 ;
memcpy ( & V_312 -> V_295 , V_11 -> V_149 . V_150 , V_143 ) ;
V_312 -> V_305 = V_11 -> V_151 ;
V_312 -> V_304 = 0 ;
V_312 -> V_299 = F_18 ( V_46 -> V_54 . V_223 ) & V_313 ;
V_312 -> V_300 = ( F_18 ( V_46 -> V_54 . V_223 ) & V_314 ) >>
V_303 ;
if ( V_11 -> V_31 == false )
V_312 -> V_315 = V_316 ;
else if ( V_11 -> V_35 == true )
V_312 -> V_315 = V_317 ;
else
V_312 -> V_315 = V_318 ;
V_312 -> V_190 = V_11 -> V_190 ;
V_86 = 0 ;
V_119:
return V_86 ;
}
int F_124 ( struct V_293 * V_294 , int V_15 , int V_319 )
{
struct V_296 * V_297 = F_116 ( V_294 ) ;
struct V_1 * V_2 = V_297 -> V_46 -> V_298 ;
struct V_21 V_22 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_11 ;
int V_14 ;
int V_86 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_30 , V_15 ) ;
V_86 = - V_118 ;
goto V_320;
}
V_11 = & V_2 -> V_11 [ V_15 ] ;
V_14 = V_11 -> V_15 + V_9 -> V_16 . V_17 ;
V_22 . V_27 = V_28 ;
V_22 . V_29 = V_30 ;
switch ( V_319 ) {
case V_316 :
V_11 -> V_31 = false ;
V_22 . V_32 . V_33 . V_34 =
V_2 -> V_9 . V_25 . V_26 . V_26 & V_38 ;
V_22 . V_32 . V_33 . V_36 =
V_2 -> V_9 . V_25 . V_26 . V_36 ;
break;
case V_317 :
V_11 -> V_31 = true ;
V_11 -> V_35 = true ;
V_22 . V_32 . V_33 . V_34 = true ;
V_22 . V_32 . V_33 . V_36 = V_37 ;
break;
case V_318 :
V_11 -> V_31 = true ;
V_11 -> V_35 = false ;
V_22 . V_32 . V_33 . V_34 = false ;
V_22 . V_32 . V_33 . V_36 = 0 ;
break;
default:
V_86 = - V_118 ;
goto V_320;
}
F_3 ( V_9 , V_14 , V_39 ,
0 , ( T_2 * ) & V_22 , sizeof( V_22 ) , NULL ) ;
V_320:
return V_86 ;
}
int F_125 ( struct V_293 * V_294 , int V_15 , bool V_321 )
{
struct V_296 * V_297 = F_116 ( V_294 ) ;
struct V_45 * V_46 = V_297 -> V_46 ;
struct V_1 * V_2 = V_46 -> V_298 ;
struct V_322 V_323 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_10 * V_11 ;
int V_86 = 0 ;
if ( V_15 >= V_2 -> V_13 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_30 , V_15 ) ;
V_86 = - V_118 ;
goto V_195;
}
V_11 = & ( V_2 -> V_11 [ V_15 ] ) ;
if ( V_321 == V_11 -> V_190 )
goto V_195;
V_11 -> V_190 = V_321 ;
memset ( & V_323 , 0 , sizeof( V_323 ) ) ;
V_323 . V_137 = V_2 -> V_46 [ V_11 -> V_144 ] -> V_137 ;
V_323 . V_324 = V_2 -> V_9 . V_103 ;
V_323 . V_54 . V_325 = F_126 ( V_326 ) ;
if ( V_321 )
V_323 . V_54 . V_327 |= ( V_328 |
V_329 ) ;
V_86 = F_127 ( V_9 , & V_323 , NULL ) ;
if ( V_86 ) {
F_29 ( & V_2 -> V_98 -> V_99 , L_47 ,
V_86 ) ;
V_86 = - V_171 ;
}
V_195:
return V_86 ;
}
