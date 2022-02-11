static void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
F_2 ( V_2 ,
V_5 ,
( const V_6 ) F_3 ( V_5 ) ) ;
F_2 ( V_2 ,
V_7 ,
( const V_6 ) F_3 ( V_7 ) ) ;
break;
default:
break;
}
}
static void F_4 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
F_5 ( V_2 -> V_9 . V_11 [ V_8 ] . V_12 ) ;
V_2 -> V_9 . V_11 [ V_8 ] . V_12 = NULL ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
const char * V_13 ;
char V_14 [ 30 ] ;
int V_15 = 0 , V_8 ;
struct V_16 * V_17 = NULL ;
const struct V_18 * V_19 = NULL ;
const struct V_20 * V_21 ;
F_7 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_4 :
V_13 = L_2 ;
break;
default: F_8 () ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
if ( V_8 == 0 )
snprintf ( V_14 , sizeof( V_14 ) , L_3 , V_13 ) ;
else
snprintf ( V_14 , sizeof( V_14 ) , L_4 , V_13 ) ;
V_15 = F_9 ( & V_2 -> V_9 . V_11 [ V_8 ] . V_12 , V_14 , V_2 -> V_22 ) ;
if ( V_15 )
goto V_23;
V_15 = F_10 ( V_2 -> V_9 . V_11 [ V_8 ] . V_12 ) ;
if ( V_15 )
goto V_23;
V_21 = ( const struct V_20 * ) V_2 -> V_9 . V_11 [ V_8 ] . V_12 -> V_24 ;
V_2 -> V_9 . V_11 [ V_8 ] . V_25 = F_11 ( V_21 -> V_19 . V_26 ) ;
V_2 -> V_9 . V_11 [ V_8 ] . V_27 = F_11 ( V_21 -> V_28 ) ;
if ( V_2 -> V_9 . V_11 [ V_8 ] . V_27 >= 20 )
V_2 -> V_9 . V_11 [ V_8 ] . V_29 = true ;
if ( V_2 -> V_30 . V_31 ) {
V_17 = & V_2 -> V_30 . V_32 [ V_33 + V_8 ] ;
V_17 -> V_34 = V_33 + V_8 ;
V_17 -> V_12 = V_2 -> V_9 . V_11 [ V_8 ] . V_12 ;
V_19 = ( const struct V_18 * ) V_17 -> V_12 -> V_24 ;
V_2 -> V_30 . V_35 +=
F_12 ( F_11 ( V_19 -> V_36 ) , V_37 ) ;
}
}
V_23:
if ( V_15 ) {
F_13 ( V_38
L_5 ,
V_14 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
F_5 ( V_2 -> V_9 . V_11 [ V_8 ] . V_12 ) ;
V_2 -> V_9 . V_11 [ V_8 ] . V_12 = NULL ;
}
}
return V_15 ;
}
static T_1 F_14 ( struct V_39 * V_40 )
{
V_6 V_41 ;
V_41 = V_40 -> V_2 -> V_42 . V_42 [ V_40 -> V_43 ] >> 2 ;
return V_41 ;
}
static T_1 F_15 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
int V_44 = ( V_40 == & V_40 -> V_2 -> V_9 . V_11 [ 0 ] . V_40 ) ? 0 : 1 ;
V_6 V_45 = F_16 ( V_46 + V_47 [ V_44 ] ) >> 2 ;
return V_45 ;
}
static void F_17 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
int V_44 = ( V_40 == & V_40 -> V_2 -> V_9 . V_11 [ 0 ] . V_40 ) ? 0 : 1 ;
F_18 ( V_46 + V_47 [ V_44 ] , V_40 -> V_45 << 2 ) ;
}
static void F_19 ( struct V_39 * V_40 , T_1 V_48 )
{
struct V_49 * V_9 = F_20 ( V_40 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_48 ; V_8 ++ )
if ( V_9 && V_9 -> V_29 && ( V_8 == 0 ) )
F_21 ( V_40 , V_40 -> V_50 |
F_22 ( V_48 - 1 ) ) ;
else
F_21 ( V_40 , V_40 -> V_50 ) ;
}
static void F_23 ( struct V_39 * V_40 ,
struct V_51 * V_52 ,
unsigned V_53 , bool V_54 )
{
V_6 V_55 = V_53 & 0xf ;
V_6 V_56 = V_40 -> V_45 + 5 ;
while ( ( V_56 & 7 ) != 2 )
V_56 ++ ;
V_56 += 6 ;
F_21 ( V_40 , F_24 ( V_57 ) |
F_25 ( V_58 ) ) ;
F_21 ( V_40 , F_26 ( V_40 -> V_59 ) & 0xfffffffc ) ;
F_21 ( V_40 , F_27 ( V_40 -> V_59 ) ) ;
F_21 ( V_40 , F_28 ( 1 ) ) ;
F_21 ( V_40 , V_56 ) ;
F_19 ( V_40 , ( 10 - ( V_40 -> V_45 & 7 ) ) % 8 ) ;
F_21 ( V_40 , F_24 ( V_60 ) |
F_29 ( V_55 ) ) ;
F_21 ( V_40 , F_26 ( V_52 -> V_61 ) & 0xffffffe0 ) ;
F_21 ( V_40 , F_27 ( V_52 -> V_61 ) ) ;
F_21 ( V_40 , V_52 -> V_62 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
}
static void F_30 ( struct V_39 * V_40 )
{
V_6 V_63 = 0 ;
if ( V_40 == & V_40 -> V_2 -> V_9 . V_11 [ 0 ] . V_40 )
V_63 = F_31 ( V_63 , V_64 , V_65 , 1 ) ;
else
V_63 = F_31 ( V_63 , V_64 , V_66 , 1 ) ;
F_21 ( V_40 , F_24 ( V_67 ) |
F_32 ( 1 ) |
F_33 ( 3 ) ) ;
F_21 ( V_40 , V_68 << 2 ) ;
F_21 ( V_40 , V_69 << 2 ) ;
F_21 ( V_40 , V_63 ) ;
F_21 ( V_40 , V_63 ) ;
F_21 ( V_40 , F_34 ( 0xfff ) |
F_35 ( 10 ) ) ;
}
static void F_36 ( struct V_39 * V_40 )
{
F_21 ( V_40 , F_24 ( V_70 ) |
F_37 ( 0xf ) ) ;
F_21 ( V_40 , V_71 ) ;
F_21 ( V_40 , 1 ) ;
}
static void F_38 ( struct V_39 * V_40 , T_2 V_72 , T_2 V_73 ,
unsigned V_74 )
{
bool V_75 = V_74 & V_76 ;
F_21 ( V_40 , F_24 ( V_77 ) ) ;
F_21 ( V_40 , F_26 ( V_72 ) ) ;
F_21 ( V_40 , F_27 ( V_72 ) ) ;
F_21 ( V_40 , F_26 ( V_73 ) ) ;
if ( V_75 ) {
V_72 += 4 ;
F_21 ( V_40 , F_24 ( V_77 ) ) ;
F_21 ( V_40 , F_26 ( V_72 ) ) ;
F_21 ( V_40 , F_27 ( V_72 ) ) ;
F_21 ( V_40 , F_27 ( V_73 ) ) ;
}
F_21 ( V_40 , F_24 ( V_78 ) ) ;
F_21 ( V_40 , F_39 ( 0 ) ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_39 * V_79 = & V_2 -> V_9 . V_11 [ 0 ] . V_40 ;
struct V_39 * V_80 = & V_2 -> V_9 . V_11 [ 1 ] . V_40 ;
V_6 V_81 , V_82 ;
int V_8 ;
if ( ( V_2 -> V_83 . V_84 == V_79 ) ||
( V_2 -> V_83 . V_84 == V_80 ) )
F_41 ( V_2 , V_2 -> V_85 . V_86 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_81 = F_16 ( V_87 + V_47 [ V_8 ] ) ;
V_81 = F_31 ( V_81 , V_88 , V_89 , 0 ) ;
F_18 ( V_87 + V_47 [ V_8 ] , V_81 ) ;
V_82 = F_16 ( V_90 + V_47 [ V_8 ] ) ;
V_82 = F_31 ( V_82 , V_91 , V_92 , 0 ) ;
F_18 ( V_90 + V_47 [ V_8 ] , V_82 ) ;
}
V_79 -> V_93 = false ;
V_80 -> V_93 = false ;
}
static void F_42 ( struct V_1 * V_2 )
{
}
static void F_43 ( struct V_1 * V_2 , bool V_94 )
{
V_6 V_95 ;
int V_8 ;
if ( V_94 == false ) {
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_95 = F_16 ( V_96 + V_47 [ V_8 ] ) ;
if ( V_94 )
V_95 = F_31 ( V_95 , V_97 , V_98 , 0 ) ;
else
V_95 = F_31 ( V_95 , V_97 , V_98 , 1 ) ;
F_18 ( V_96 + V_47 [ V_8 ] , V_95 ) ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
V_6 V_81 , V_82 ;
V_6 V_99 ;
V_6 V_100 ;
int V_8 , V_101 , V_102 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_100 = ( V_40 -> V_43 * 4 ) ;
F_45 ( & V_2 -> V_103 ) ;
for ( V_101 = 0 ; V_101 < 16 ; V_101 ++ ) {
F_46 ( V_2 , 0 , 0 , 0 , V_101 ) ;
F_18 ( V_104 + V_47 [ V_8 ] , 0 ) ;
F_18 ( V_105 + V_47 [ V_8 ] , 0 ) ;
}
F_46 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_47 ( & V_2 -> V_103 ) ;
F_18 ( V_106 + V_47 [ V_8 ] ,
V_2 -> V_107 . V_108 . V_109 & 0x70 ) ;
F_18 ( V_110 + V_47 [ V_8 ] , 0 ) ;
V_99 = F_48 ( V_40 -> V_111 / 4 ) ;
V_81 = F_16 ( V_87 + V_47 [ V_8 ] ) ;
V_81 = F_31 ( V_81 , V_88 , V_112 , V_99 ) ;
#ifdef F_49
V_81 = F_31 ( V_81 , V_88 , V_113 , 1 ) ;
V_81 = F_31 ( V_81 , V_88 ,
V_114 , 1 ) ;
#endif
F_18 ( V_87 + V_47 [ V_8 ] , V_81 ) ;
F_18 ( V_115 + V_47 [ V_8 ] , 0 ) ;
F_18 ( V_46 + V_47 [ V_8 ] , 0 ) ;
F_18 ( V_116 + V_47 [ V_8 ] , 0 ) ;
F_18 ( V_117 + V_47 [ V_8 ] , 0 ) ;
F_18 ( V_118 + V_47 [ V_8 ] ,
F_27 ( V_2 -> V_42 . V_61 + V_100 ) & 0xFFFFFFFF ) ;
F_18 ( V_119 + V_47 [ V_8 ] ,
F_26 ( V_2 -> V_42 . V_61 + V_100 ) & 0xFFFFFFFC ) ;
V_81 = F_31 ( V_81 , V_88 , V_120 , 1 ) ;
F_18 ( V_121 + V_47 [ V_8 ] , V_40 -> V_61 >> 8 ) ;
F_18 ( V_122 + V_47 [ V_8 ] , V_40 -> V_61 >> 40 ) ;
V_40 -> V_45 = 0 ;
F_18 ( V_46 + V_47 [ V_8 ] , V_40 -> V_45 << 2 ) ;
V_81 = F_31 ( V_81 , V_88 , V_89 , 1 ) ;
F_18 ( V_87 + V_47 [ V_8 ] , V_81 ) ;
V_82 = F_16 ( V_90 + V_47 [ V_8 ] ) ;
V_82 = F_31 ( V_82 , V_91 , V_92 , 1 ) ;
#ifdef F_49
V_82 = F_31 ( V_82 , V_91 , V_123 , 1 ) ;
#endif
F_18 ( V_90 + V_47 [ V_8 ] , V_82 ) ;
V_40 -> V_93 = true ;
}
F_43 ( V_2 , true ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_102 = F_50 ( V_40 ) ;
if ( V_102 ) {
V_40 -> V_93 = false ;
return V_102 ;
}
if ( V_2 -> V_83 . V_84 == V_40 )
F_41 ( V_2 , V_2 -> V_85 . V_124 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
const struct V_20 * V_21 ;
const T_3 * V_125 ;
V_6 V_35 ;
int V_8 , V_101 ;
F_43 ( V_2 , false ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
if ( ! V_2 -> V_9 . V_11 [ V_8 ] . V_12 )
return - V_126 ;
V_21 = ( const struct V_20 * ) V_2 -> V_9 . V_11 [ V_8 ] . V_12 -> V_24 ;
F_53 ( & V_21 -> V_19 ) ;
V_35 = F_11 ( V_21 -> V_19 . V_36 ) / 4 ;
V_125 = ( const T_3 * )
( V_2 -> V_9 . V_11 [ V_8 ] . V_12 -> V_24 +
F_11 ( V_21 -> V_19 . V_127 ) ) ;
F_18 ( V_128 + V_47 [ V_8 ] , 0 ) ;
for ( V_101 = 0 ; V_101 < V_35 ; V_101 ++ )
F_18 ( V_129 + V_47 [ V_8 ] , F_54 ( V_125 ++ ) ) ;
F_18 ( V_128 + V_47 [ V_8 ] , V_2 -> V_9 . V_11 [ V_8 ] . V_25 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_102 ;
if ( ! V_2 -> V_30 . V_31 ) {
V_102 = F_52 ( V_2 ) ;
if ( V_102 )
return V_102 ;
} else {
V_102 = V_2 -> V_130 . V_131 -> V_132 ( V_2 ,
V_33 ) ;
if ( V_102 )
return - V_126 ;
V_102 = V_2 -> V_130 . V_131 -> V_132 ( V_2 ,
V_133 ) ;
if ( V_102 )
return - V_126 ;
}
F_43 ( V_2 , false ) ;
V_102 = F_44 ( V_2 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_51 ( V_2 ) ;
if ( V_102 )
return V_102 ;
return 0 ;
}
static int F_56 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
unsigned V_8 ;
unsigned V_134 ;
int V_102 ;
V_6 V_135 ;
T_2 V_61 ;
V_102 = F_57 ( V_2 , & V_134 ) ;
if ( V_102 ) {
F_58 ( V_2 -> V_22 , L_6 , V_102 ) ;
return V_102 ;
}
V_61 = V_2 -> V_42 . V_61 + ( V_134 * 4 ) ;
V_135 = 0xCAFEDEAD ;
V_2 -> V_42 . V_42 [ V_134 ] = F_59 ( V_135 ) ;
V_102 = F_60 ( V_40 , 5 ) ;
if ( V_102 ) {
F_61 ( L_7 , V_40 -> V_136 , V_102 ) ;
F_62 ( V_2 , V_134 ) ;
return V_102 ;
}
F_21 ( V_40 , F_24 ( V_57 ) |
F_25 ( V_58 ) ) ;
F_21 ( V_40 , F_26 ( V_61 ) ) ;
F_21 ( V_40 , F_27 ( V_61 ) ) ;
F_21 ( V_40 , F_28 ( 1 ) ) ;
F_21 ( V_40 , 0xDEADBEEF ) ;
F_63 ( V_40 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_137 ; V_8 ++ ) {
V_135 = F_11 ( V_2 -> V_42 . V_42 [ V_134 ] ) ;
if ( V_135 == 0xDEADBEEF )
break;
F_64 ( 1 ) ;
}
if ( V_8 < V_2 -> V_137 ) {
F_65 ( L_8 , V_40 -> V_136 , V_8 ) ;
} else {
F_61 ( L_9 ,
V_40 -> V_136 , V_135 ) ;
V_102 = - V_126 ;
}
F_62 ( V_2 , V_134 ) ;
return V_102 ;
}
static int F_66 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_51 V_52 ;
struct V_138 * V_139 = NULL ;
unsigned V_8 ;
unsigned V_134 ;
int V_102 ;
V_6 V_135 = 0 ;
T_2 V_61 ;
V_102 = F_57 ( V_2 , & V_134 ) ;
if ( V_102 ) {
F_58 ( V_2 -> V_22 , L_6 , V_102 ) ;
return V_102 ;
}
V_61 = V_2 -> V_42 . V_61 + ( V_134 * 4 ) ;
V_135 = 0xCAFEDEAD ;
V_2 -> V_42 . V_42 [ V_134 ] = F_59 ( V_135 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_102 = F_67 ( V_2 , NULL , 256 , & V_52 ) ;
if ( V_102 ) {
F_61 ( L_10 , V_102 ) ;
goto V_140;
}
V_52 . V_141 [ 0 ] = F_24 ( V_57 ) |
F_25 ( V_58 ) ;
V_52 . V_141 [ 1 ] = F_26 ( V_61 ) ;
V_52 . V_141 [ 2 ] = F_27 ( V_61 ) ;
V_52 . V_141 [ 3 ] = F_28 ( 1 ) ;
V_52 . V_141 [ 4 ] = 0xDEADBEEF ;
V_52 . V_141 [ 5 ] = F_24 ( V_142 ) ;
V_52 . V_141 [ 6 ] = F_24 ( V_142 ) ;
V_52 . V_141 [ 7 ] = F_24 ( V_142 ) ;
V_52 . V_62 = 8 ;
V_102 = F_68 ( V_40 , 1 , & V_52 , NULL , NULL , & V_139 ) ;
if ( V_102 )
goto V_143;
V_102 = F_69 ( V_139 , false ) ;
if ( V_102 ) {
F_61 ( L_11 , V_102 ) ;
goto V_143;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_137 ; V_8 ++ ) {
V_135 = F_11 ( V_2 -> V_42 . V_42 [ V_134 ] ) ;
if ( V_135 == 0xDEADBEEF )
break;
F_64 ( 1 ) ;
}
if ( V_8 < V_2 -> V_137 ) {
F_65 ( L_12 ,
V_40 -> V_136 , V_8 ) ;
goto V_143;
} else {
F_61 ( L_13 , V_135 ) ;
V_102 = - V_126 ;
}
V_143:
F_70 ( V_139 ) ;
F_71 ( V_2 , & V_52 , NULL ) ;
F_70 ( V_139 ) ;
V_140:
F_62 ( V_2 , V_134 ) ;
return V_102 ;
}
static void F_72 ( struct V_51 * V_52 ,
T_4 V_144 , T_4 V_145 ,
unsigned V_48 )
{
while ( V_48 ) {
unsigned V_146 = V_48 * 8 ;
if ( V_146 > 0x1FFFF8 )
V_146 = 0x1FFFF8 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_24 ( V_147 ) |
F_25 ( V_148 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_146 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_26 ( V_145 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_145 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_26 ( V_144 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_144 ) ;
V_144 += V_146 ;
V_145 += V_146 ;
V_48 -= V_146 / 8 ;
}
}
static void F_73 ( struct V_51 * V_52 ,
const T_5 * V_149 , T_4 V_144 ,
T_4 V_72 , unsigned V_48 ,
T_1 V_150 , T_1 V_74 )
{
T_4 V_151 ;
unsigned V_152 ;
while ( V_48 ) {
V_152 = V_48 * 2 ;
if ( V_152 > 0xFFFFE )
V_152 = 0xFFFFE ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_24 ( V_57 ) |
F_25 ( V_148 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_144 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_144 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_152 ;
for (; V_152 > 0 ; V_152 -= 2 , -- V_48 , V_144 += 8 ) {
V_151 = F_74 ( V_149 , V_72 ) ;
V_72 += V_150 ;
V_151 |= V_74 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_151 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_151 ) ;
}
}
}
static void F_75 ( struct V_51 * V_52 ,
T_4 V_144 ,
T_4 V_72 , unsigned V_48 ,
T_1 V_150 , T_1 V_74 )
{
T_4 V_151 ;
unsigned V_152 ;
while ( V_48 ) {
V_152 = V_48 ;
if ( V_152 > 0x7FFFF )
V_152 = 0x7FFFF ;
if ( V_74 & V_153 )
V_151 = V_72 ;
else
V_151 = 0 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_24 ( V_154 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_144 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_144 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_74 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_151 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_151 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_150 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_152 ;
V_144 += V_152 * 8 ;
V_72 += V_152 * V_150 ;
V_48 -= V_152 ;
}
}
static void F_76 ( struct V_39 * V_40 , struct V_51 * V_52 )
{
struct V_49 * V_9 = F_20 ( V_40 ) ;
V_6 V_155 ;
int V_8 ;
V_155 = ( 8 - ( V_52 -> V_62 & 0x7 ) ) % 8 ;
for ( V_8 = 0 ; V_8 < V_155 ; V_8 ++ )
if ( V_9 && V_9 -> V_29 && ( V_8 == 0 ) )
V_52 -> V_141 [ V_52 -> V_62 ++ ] =
F_24 ( V_142 ) |
F_22 ( V_155 - 1 ) ;
else
V_52 -> V_141 [ V_52 -> V_62 ++ ] =
F_24 ( V_142 ) ;
}
static void F_77 ( struct V_39 * V_40 )
{
T_1 V_73 = V_40 -> V_156 . V_157 ;
T_4 V_72 = V_40 -> V_156 . V_61 ;
F_21 ( V_40 , F_24 ( V_67 ) |
F_32 ( 0 ) |
F_33 ( 3 ) |
F_78 ( 1 ) ) ;
F_21 ( V_40 , V_72 & 0xfffffffc ) ;
F_21 ( V_40 , F_27 ( V_72 ) & 0xffffffff ) ;
F_21 ( V_40 , V_73 ) ;
F_21 ( V_40 , 0xfffffff ) ;
F_21 ( V_40 , F_34 ( 0xfff ) |
F_35 ( 4 ) ) ;
}
static void F_79 ( struct V_39 * V_40 ,
unsigned V_53 , T_4 V_158 )
{
F_21 ( V_40 , F_24 ( V_70 ) |
F_37 ( 0xf ) ) ;
if ( V_53 < 8 ) {
F_21 ( V_40 , ( V_159 + V_53 ) ) ;
} else {
F_21 ( V_40 , ( V_160 + V_53 - 8 ) ) ;
}
F_21 ( V_40 , V_158 >> 12 ) ;
F_21 ( V_40 , F_24 ( V_70 ) |
F_37 ( 0xf ) ) ;
F_21 ( V_40 , V_161 ) ;
F_21 ( V_40 , 1 << V_53 ) ;
F_21 ( V_40 , F_24 ( V_67 ) |
F_32 ( 0 ) |
F_33 ( 0 ) ) ;
F_21 ( V_40 , V_161 << 2 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , F_34 ( 0xfff ) |
F_35 ( 10 ) ) ;
}
static int F_80 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
V_2 -> V_9 . V_10 = V_163 ;
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_85 ( void * V_162 )
{
struct V_39 * V_40 ;
int V_102 , V_8 ;
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
V_102 = F_86 ( V_2 , 224 , & V_2 -> V_9 . V_164 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_86 ( V_2 , 241 , & V_2 -> V_9 . V_165 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_86 ( V_2 , 247 , & V_2 -> V_9 . V_165 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_6 ( V_2 ) ;
if ( V_102 ) {
F_61 ( L_14 ) ;
return V_102 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_40 -> V_166 = NULL ;
V_40 -> V_167 = false ;
sprintf ( V_40 -> V_168 , L_15 , V_8 ) ;
V_102 = F_87 ( V_2 , V_40 , 1024 ,
F_88 ( V_142 ) , 0xf ,
& V_2 -> V_9 . V_164 ,
( V_8 == 0 ) ?
V_169 : V_170 ,
V_171 ) ;
if ( V_102 )
return V_102 ;
}
return V_102 ;
}
static int F_89 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
F_90 ( & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_91 ( void * V_162 )
{
int V_102 ;
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
F_1 ( V_2 ) ;
V_102 = F_55 ( V_2 ) ;
if ( V_102 )
return V_102 ;
return V_102 ;
}
static int F_92 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
F_43 ( V_2 , false ) ;
return 0 ;
}
static int F_93 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
return F_92 ( V_2 ) ;
}
static int F_94 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
return F_91 ( V_2 ) ;
}
static bool F_95 ( void * V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
V_6 V_135 = F_16 ( V_172 ) ;
if ( V_135 & ( V_173 |
V_174 ) )
return false ;
return true ;
}
static int F_96 ( void * V_162 )
{
unsigned V_8 ;
V_6 V_135 ;
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_137 ; V_8 ++ ) {
V_135 = F_16 ( V_172 ) & ( V_173 |
V_174 ) ;
if ( ! V_135 )
return 0 ;
F_97 ( 1 ) ;
}
return - V_175 ;
}
static int F_98 ( void * V_162 )
{
V_6 V_176 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
V_6 V_135 = F_16 ( V_172 ) ;
if ( V_135 & V_173 ) {
V_135 = F_16 ( V_96 + V_177 ) ;
V_135 = F_31 ( V_135 , V_97 , V_98 , 0 ) ;
F_18 ( V_96 + V_177 , V_135 ) ;
V_176 |= V_178 ;
}
if ( V_135 & V_174 ) {
V_135 = F_16 ( V_96 + V_179 ) ;
V_135 = F_31 ( V_135 , V_97 , V_98 , 0 ) ;
F_18 ( V_96 + V_179 , V_135 ) ;
V_176 |= V_180 ;
}
if ( V_176 ) {
V_135 = F_16 ( V_181 ) ;
V_135 |= V_176 ;
F_99 ( V_2 -> V_22 , L_16 , V_135 ) ;
F_18 ( V_181 , V_135 ) ;
V_135 = F_16 ( V_181 ) ;
F_97 ( 50 ) ;
V_135 &= ~ V_176 ;
F_18 ( V_181 , V_135 ) ;
V_135 = F_16 ( V_181 ) ;
F_97 ( 50 ) ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_182 * V_145 ,
unsigned type ,
enum V_183 V_184 )
{
V_6 V_185 ;
switch ( type ) {
case V_169 :
switch ( V_184 ) {
case V_186 :
V_185 = F_16 ( V_187 + V_177 ) ;
V_185 = F_31 ( V_185 , V_188 , V_189 , 0 ) ;
F_18 ( V_187 + V_177 , V_185 ) ;
break;
case V_190 :
V_185 = F_16 ( V_187 + V_177 ) ;
V_185 = F_31 ( V_185 , V_188 , V_189 , 1 ) ;
F_18 ( V_187 + V_177 , V_185 ) ;
break;
default:
break;
}
break;
case V_170 :
switch ( V_184 ) {
case V_186 :
V_185 = F_16 ( V_187 + V_179 ) ;
V_185 = F_31 ( V_185 , V_188 , V_189 , 0 ) ;
F_18 ( V_187 + V_179 , V_185 ) ;
break;
case V_190 :
V_185 = F_16 ( V_187 + V_179 ) ;
V_185 = F_31 ( V_185 , V_188 , V_189 , 1 ) ;
F_18 ( V_187 + V_179 , V_185 ) ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_182 * V_191 ,
struct V_192 * V_193 )
{
T_6 V_194 , V_195 ;
V_194 = ( V_193 -> V_196 & 0x3 ) >> 0 ;
V_195 = ( V_193 -> V_196 & 0xc ) >> 2 ;
F_7 ( L_17 ) ;
switch ( V_194 ) {
case 0 :
switch ( V_195 ) {
case 0 :
F_102 ( & V_2 -> V_9 . V_11 [ 0 ] . V_40 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_195 ) {
case 0 :
F_102 ( & V_2 -> V_9 . V_11 [ 1 ] . V_40 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_182 * V_191 ,
struct V_192 * V_193 )
{
F_61 ( L_18 ) ;
F_104 ( & V_2 -> V_197 ) ;
return 0 ;
}
static int F_105 ( void * V_162 ,
enum V_198 V_184 )
{
return 0 ;
}
static int F_106 ( void * V_162 ,
enum V_199 V_184 )
{
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
V_2 -> V_9 . V_11 [ V_8 ] . V_40 . V_200 = & V_201 ;
}
static void F_84 ( struct V_1 * V_2 )
{
V_2 -> V_9 . V_164 . V_202 = V_203 ;
V_2 -> V_9 . V_164 . V_200 = & V_204 ;
V_2 -> V_9 . V_165 . V_200 = & V_205 ;
}
static void F_107 ( struct V_51 * V_52 ,
T_4 V_206 ,
T_4 V_207 ,
T_1 V_208 )
{
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_24 ( V_147 ) |
F_25 ( V_148 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_208 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_26 ( V_206 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_206 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_26 ( V_207 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_207 ) ;
}
static void F_108 ( struct V_51 * V_52 ,
T_1 V_209 ,
T_4 V_207 ,
T_1 V_208 )
{
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_24 ( V_210 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_26 ( V_207 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = F_27 ( V_207 ) ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_209 ;
V_52 -> V_141 [ V_52 -> V_62 ++ ] = V_208 ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 . V_211 == NULL ) {
V_2 -> V_83 . V_211 = & V_212 ;
V_2 -> V_83 . V_84 = & V_2 -> V_9 . V_11 [ 0 ] . V_40 ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned V_8 ;
if ( V_2 -> V_213 . V_214 == NULL ) {
V_2 -> V_213 . V_214 = & V_215 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
V_2 -> V_213 . V_216 [ V_8 ] =
& V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_2 -> V_213 . V_217 = V_2 -> V_9 . V_10 ;
}
}
