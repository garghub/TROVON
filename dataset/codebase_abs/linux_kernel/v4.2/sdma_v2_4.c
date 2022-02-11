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
static int F_4 ( struct V_1 * V_2 )
{
const char * V_8 ;
char V_9 [ 30 ] ;
int V_10 , V_11 ;
struct V_12 * V_13 = NULL ;
const struct V_14 * V_15 = NULL ;
const struct V_16 * V_17 ;
F_5 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_4 :
V_8 = L_2 ;
break;
default: F_6 () ;
}
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
if ( V_11 == 0 )
snprintf ( V_9 , sizeof( V_9 ) , L_3 , V_8 ) ;
else
snprintf ( V_9 , sizeof( V_9 ) , L_4 , V_8 ) ;
V_10 = F_7 ( & V_2 -> V_19 [ V_11 ] . V_20 , V_9 , V_2 -> V_21 ) ;
if ( V_10 )
goto V_22;
V_10 = F_8 ( V_2 -> V_19 [ V_11 ] . V_20 ) ;
if ( V_10 )
goto V_22;
V_17 = ( const struct V_16 * ) V_2 -> V_19 [ V_11 ] . V_20 -> V_23 ;
V_2 -> V_19 [ V_11 ] . V_24 = F_9 ( V_17 -> V_15 . V_25 ) ;
V_2 -> V_19 [ V_11 ] . V_26 = F_9 ( V_17 -> V_27 ) ;
if ( V_2 -> V_28 . V_29 ) {
V_13 = & V_2 -> V_28 . V_30 [ V_31 + V_11 ] ;
V_13 -> V_32 = V_31 + V_11 ;
V_13 -> V_20 = V_2 -> V_19 [ V_11 ] . V_20 ;
V_15 = ( const struct V_14 * ) V_13 -> V_20 -> V_23 ;
V_2 -> V_28 . V_33 +=
F_10 ( F_9 ( V_15 -> V_34 ) , V_35 ) ;
}
}
V_22:
if ( V_10 ) {
F_11 ( V_36
L_5 ,
V_9 ) ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
F_12 ( V_2 -> V_19 [ V_11 ] . V_20 ) ;
V_2 -> V_19 [ V_11 ] . V_20 = NULL ;
}
}
return V_10 ;
}
static T_1 F_13 ( struct V_37 * V_38 )
{
V_6 V_39 ;
V_39 = V_38 -> V_2 -> V_40 . V_40 [ V_38 -> V_41 ] >> 2 ;
return V_39 ;
}
static T_1 F_14 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
int V_42 = ( V_38 == & V_38 -> V_2 -> V_19 [ 0 ] . V_38 ) ? 0 : 1 ;
V_6 V_43 = F_15 ( V_44 + V_45 [ V_42 ] ) >> 2 ;
return V_43 ;
}
static void F_16 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
int V_42 = ( V_38 == & V_38 -> V_2 -> V_19 [ 0 ] . V_38 ) ? 0 : 1 ;
F_17 ( V_44 + V_45 [ V_42 ] , V_38 -> V_43 << 2 ) ;
}
static void F_18 ( struct V_37 * V_38 ,
struct V_46 * V_47 )
{
V_6 V_48 = ( V_47 -> V_49 ? V_47 -> V_49 -> V_50 [ V_38 -> V_51 ] . V_52 : 0 ) & 0xf ;
V_6 V_53 = V_38 -> V_43 + 5 ;
while ( ( V_53 & 7 ) != 2 )
V_53 ++ ;
V_53 += 6 ;
F_19 ( V_38 , F_20 ( V_54 ) |
F_21 ( V_55 ) ) ;
F_19 ( V_38 , F_22 ( V_38 -> V_56 ) & 0xfffffffc ) ;
F_19 ( V_38 , F_23 ( V_38 -> V_56 ) ) ;
F_19 ( V_38 , F_24 ( 1 ) ) ;
F_19 ( V_38 , V_53 ) ;
while ( ( V_38 -> V_43 & 7 ) != 2 )
F_19 ( V_38 , F_20 ( V_57 ) ) ;
F_19 ( V_38 , F_20 ( V_58 ) |
F_25 ( V_48 ) ) ;
F_19 ( V_38 , F_22 ( V_47 -> V_59 ) & 0xffffffe0 ) ;
F_19 ( V_38 , F_23 ( V_47 -> V_59 ) ) ;
F_19 ( V_38 , V_47 -> V_60 ) ;
F_19 ( V_38 , 0 ) ;
F_19 ( V_38 , 0 ) ;
}
static void F_26 ( struct V_37 * V_38 )
{
V_6 V_61 = 0 ;
if ( V_38 == & V_38 -> V_2 -> V_19 [ 0 ] . V_38 )
V_61 = F_27 ( V_61 , V_62 , V_63 , 1 ) ;
else
V_61 = F_27 ( V_61 , V_62 , V_64 , 1 ) ;
F_19 ( V_38 , F_20 ( V_65 ) |
F_28 ( 1 ) |
F_29 ( 3 ) ) ;
F_19 ( V_38 , V_66 << 2 ) ;
F_19 ( V_38 , V_67 << 2 ) ;
F_19 ( V_38 , V_61 ) ;
F_19 ( V_38 , V_61 ) ;
F_19 ( V_38 , F_30 ( 0xfff ) |
F_31 ( 10 ) ) ;
}
static void F_32 ( struct V_37 * V_38 , T_2 V_68 , T_2 V_69 ,
unsigned V_70 )
{
bool V_71 = V_70 & V_72 ;
F_19 ( V_38 , F_20 ( V_73 ) ) ;
F_19 ( V_38 , F_22 ( V_68 ) ) ;
F_19 ( V_38 , F_23 ( V_68 ) ) ;
F_19 ( V_38 , F_22 ( V_69 ) ) ;
if ( V_71 ) {
V_68 += 4 ;
F_19 ( V_38 , F_20 ( V_73 ) ) ;
F_19 ( V_38 , F_22 ( V_68 ) ) ;
F_19 ( V_38 , F_23 ( V_68 ) ) ;
F_19 ( V_38 , F_23 ( V_69 ) ) ;
}
F_19 ( V_38 , F_20 ( V_74 ) ) ;
F_19 ( V_38 , F_33 ( 0 ) ) ;
}
static bool F_34 ( struct V_37 * V_38 ,
struct V_75 * V_76 ,
bool V_77 )
{
T_2 V_68 = V_76 -> V_59 ;
V_6 V_78 = V_77 ? 0 : 1 ;
F_19 ( V_38 , F_20 ( V_79 ) |
F_35 ( V_78 ) ) ;
F_19 ( V_38 , F_22 ( V_68 ) & 0xfffffff8 ) ;
F_19 ( V_38 , F_23 ( V_68 ) ) ;
return true ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_37 * V_80 = & V_2 -> V_19 [ 0 ] . V_38 ;
struct V_37 * V_81 = & V_2 -> V_19 [ 1 ] . V_38 ;
V_6 V_82 , V_83 ;
int V_11 ;
if ( ( V_2 -> V_84 . V_85 == V_80 ) ||
( V_2 -> V_84 . V_85 == V_81 ) )
F_37 ( V_2 , V_2 -> V_86 . V_87 ) ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_82 = F_15 ( V_88 + V_45 [ V_11 ] ) ;
V_82 = F_27 ( V_82 , V_89 , V_90 , 0 ) ;
F_17 ( V_88 + V_45 [ V_11 ] , V_82 ) ;
V_83 = F_15 ( V_91 + V_45 [ V_11 ] ) ;
V_83 = F_27 ( V_83 , V_92 , V_93 , 0 ) ;
F_17 ( V_91 + V_45 [ V_11 ] , V_83 ) ;
}
V_80 -> V_94 = false ;
V_81 -> V_94 = false ;
}
static void F_38 ( struct V_1 * V_2 )
{
}
static void F_39 ( struct V_1 * V_2 , bool V_95 )
{
V_6 V_96 ;
int V_11 ;
if ( V_95 == false ) {
F_36 ( V_2 ) ;
F_38 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_96 = F_15 ( V_97 + V_45 [ V_11 ] ) ;
if ( V_95 )
V_96 = F_27 ( V_96 , V_98 , V_99 , 0 ) ;
else
V_96 = F_27 ( V_96 , V_98 , V_99 , 1 ) ;
F_17 ( V_97 + V_45 [ V_11 ] , V_96 ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
V_6 V_82 , V_83 ;
V_6 V_100 ;
V_6 V_101 ;
int V_11 , V_102 , V_103 ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_38 = & V_2 -> V_19 [ V_11 ] . V_38 ;
V_101 = ( V_38 -> V_41 * 4 ) ;
F_41 ( & V_2 -> V_104 ) ;
for ( V_102 = 0 ; V_102 < 16 ; V_102 ++ ) {
F_42 ( V_2 , 0 , 0 , 0 , V_102 ) ;
F_17 ( V_105 + V_45 [ V_11 ] , 0 ) ;
F_17 ( V_106 + V_45 [ V_11 ] , 0 ) ;
}
F_42 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_43 ( & V_2 -> V_104 ) ;
F_17 ( V_107 + V_45 [ V_11 ] , 0 ) ;
V_100 = F_44 ( V_38 -> V_108 / 4 ) ;
V_82 = F_15 ( V_88 + V_45 [ V_11 ] ) ;
V_82 = F_27 ( V_82 , V_89 , V_109 , V_100 ) ;
#ifdef F_45
V_82 = F_27 ( V_82 , V_89 , V_110 , 1 ) ;
V_82 = F_27 ( V_82 , V_89 ,
V_111 , 1 ) ;
#endif
F_17 ( V_88 + V_45 [ V_11 ] , V_82 ) ;
F_17 ( V_112 + V_45 [ V_11 ] , 0 ) ;
F_17 ( V_44 + V_45 [ V_11 ] , 0 ) ;
F_17 ( V_113 + V_45 [ V_11 ] ,
F_23 ( V_2 -> V_40 . V_59 + V_101 ) & 0xFFFFFFFF ) ;
F_17 ( V_114 + V_45 [ V_11 ] ,
F_22 ( V_2 -> V_40 . V_59 + V_101 ) & 0xFFFFFFFC ) ;
V_82 = F_27 ( V_82 , V_89 , V_115 , 1 ) ;
F_17 ( V_116 + V_45 [ V_11 ] , V_38 -> V_59 >> 8 ) ;
F_17 ( V_117 + V_45 [ V_11 ] , V_38 -> V_59 >> 40 ) ;
V_38 -> V_43 = 0 ;
F_17 ( V_44 + V_45 [ V_11 ] , V_38 -> V_43 << 2 ) ;
V_82 = F_27 ( V_82 , V_89 , V_90 , 1 ) ;
F_17 ( V_88 + V_45 [ V_11 ] , V_82 ) ;
V_83 = F_15 ( V_91 + V_45 [ V_11 ] ) ;
V_83 = F_27 ( V_83 , V_92 , V_93 , 1 ) ;
#ifdef F_45
V_83 = F_27 ( V_83 , V_92 , V_118 , 1 ) ;
#endif
F_17 ( V_91 + V_45 [ V_11 ] , V_83 ) ;
V_38 -> V_94 = true ;
V_103 = F_46 ( V_38 ) ;
if ( V_103 ) {
V_38 -> V_94 = false ;
return V_103 ;
}
if ( V_2 -> V_84 . V_85 == V_38 )
F_37 ( V_2 , V_2 -> V_86 . V_119 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
const struct V_16 * V_17 ;
const T_3 * V_120 ;
V_6 V_33 ;
int V_11 , V_102 ;
bool V_121 = false ;
if ( ! V_2 -> V_19 [ 0 ] . V_20 || ! V_2 -> V_19 [ 1 ] . V_20 )
return - V_122 ;
F_39 ( V_2 , false ) ;
if ( V_121 ) {
} else {
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_17 = ( const struct V_16 * ) V_2 -> V_19 [ V_11 ] . V_20 -> V_23 ;
F_49 ( & V_17 -> V_15 ) ;
V_33 = F_9 ( V_17 -> V_15 . V_34 ) / 4 ;
V_120 = ( const T_3 * )
( V_2 -> V_19 [ V_11 ] . V_20 -> V_23 +
F_9 ( V_17 -> V_15 . V_123 ) ) ;
F_17 ( V_124 + V_45 [ V_11 ] , 0 ) ;
for ( V_102 = 0 ; V_102 < V_33 ; V_102 ++ )
F_17 ( V_125 + V_45 [ V_11 ] , F_50 ( V_120 ++ ) ) ;
F_17 ( V_124 + V_45 [ V_11 ] , V_2 -> V_19 [ V_11 ] . V_24 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_103 ;
if ( ! V_2 -> V_28 . V_29 ) {
V_103 = F_48 ( V_2 ) ;
if ( V_103 )
return V_103 ;
} else {
V_103 = V_2 -> V_126 . V_127 -> V_128 ( V_2 ,
V_31 ) ;
if ( V_103 )
return - V_122 ;
V_103 = V_2 -> V_126 . V_127 -> V_128 ( V_2 ,
V_129 ) ;
if ( V_103 )
return - V_122 ;
}
F_39 ( V_2 , true ) ;
V_103 = F_40 ( V_2 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_47 ( V_2 ) ;
if ( V_103 )
return V_103 ;
return 0 ;
}
static int F_52 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
unsigned V_11 ;
unsigned V_130 ;
int V_103 ;
V_6 V_131 ;
T_2 V_59 ;
V_103 = F_53 ( V_2 , & V_130 ) ;
if ( V_103 ) {
F_54 ( V_2 -> V_21 , L_6 , V_103 ) ;
return V_103 ;
}
V_59 = V_2 -> V_40 . V_59 + ( V_130 * 4 ) ;
V_131 = 0xCAFEDEAD ;
V_2 -> V_40 . V_40 [ V_130 ] = F_55 ( V_131 ) ;
V_103 = F_56 ( V_38 , 5 ) ;
if ( V_103 ) {
F_57 ( L_7 , V_38 -> V_51 , V_103 ) ;
F_58 ( V_2 , V_130 ) ;
return V_103 ;
}
F_19 ( V_38 , F_20 ( V_54 ) |
F_21 ( V_55 ) ) ;
F_19 ( V_38 , F_22 ( V_59 ) ) ;
F_19 ( V_38 , F_23 ( V_59 ) ) ;
F_19 ( V_38 , F_24 ( 1 ) ) ;
F_19 ( V_38 , 0xDEADBEEF ) ;
F_59 ( V_38 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_132 ; V_11 ++ ) {
V_131 = F_9 ( V_2 -> V_40 . V_40 [ V_130 ] ) ;
if ( V_131 == 0xDEADBEEF )
break;
F_60 ( 1 ) ;
}
if ( V_11 < V_2 -> V_132 ) {
F_61 ( L_8 , V_38 -> V_51 , V_11 ) ;
} else {
F_57 ( L_9 ,
V_38 -> V_51 , V_131 ) ;
V_103 = - V_122 ;
}
F_58 ( V_2 , V_130 ) ;
return V_103 ;
}
static int F_62 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_46 V_47 ;
unsigned V_11 ;
unsigned V_130 ;
int V_103 ;
V_6 V_131 = 0 ;
T_2 V_59 ;
V_103 = F_53 ( V_2 , & V_130 ) ;
if ( V_103 ) {
F_54 ( V_2 -> V_21 , L_6 , V_103 ) ;
return V_103 ;
}
V_59 = V_2 -> V_40 . V_59 + ( V_130 * 4 ) ;
V_131 = 0xCAFEDEAD ;
V_2 -> V_40 . V_40 [ V_130 ] = F_55 ( V_131 ) ;
V_103 = F_63 ( V_38 , NULL , 256 , & V_47 ) ;
if ( V_103 ) {
F_58 ( V_2 , V_130 ) ;
F_57 ( L_10 , V_103 ) ;
return V_103 ;
}
V_47 . V_133 [ 0 ] = F_20 ( V_54 ) |
F_21 ( V_55 ) ;
V_47 . V_133 [ 1 ] = F_22 ( V_59 ) ;
V_47 . V_133 [ 2 ] = F_23 ( V_59 ) ;
V_47 . V_133 [ 3 ] = F_24 ( 1 ) ;
V_47 . V_133 [ 4 ] = 0xDEADBEEF ;
V_47 . V_133 [ 5 ] = F_20 ( V_57 ) ;
V_47 . V_133 [ 6 ] = F_20 ( V_57 ) ;
V_47 . V_133 [ 7 ] = F_20 ( V_57 ) ;
V_47 . V_60 = 8 ;
V_103 = F_64 ( V_2 , 1 , & V_47 , V_134 ) ;
if ( V_103 ) {
F_65 ( V_2 , & V_47 ) ;
F_58 ( V_2 , V_130 ) ;
F_57 ( L_11 , V_103 ) ;
return V_103 ;
}
V_103 = F_66 ( V_47 . V_135 , false ) ;
if ( V_103 ) {
F_65 ( V_2 , & V_47 ) ;
F_58 ( V_2 , V_130 ) ;
F_57 ( L_12 , V_103 ) ;
return V_103 ;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_132 ; V_11 ++ ) {
V_131 = F_9 ( V_2 -> V_40 . V_40 [ V_130 ] ) ;
if ( V_131 == 0xDEADBEEF )
break;
F_60 ( 1 ) ;
}
if ( V_11 < V_2 -> V_132 ) {
F_61 ( L_13 ,
V_47 . V_135 -> V_38 -> V_51 , V_11 ) ;
} else {
F_57 ( L_14 , V_131 ) ;
V_103 = - V_122 ;
}
F_65 ( V_2 , & V_47 ) ;
F_58 ( V_2 , V_130 ) ;
return V_103 ;
}
static void F_67 ( struct V_46 * V_47 ,
T_4 V_136 , T_4 V_137 ,
unsigned V_138 )
{
while ( V_138 ) {
unsigned V_139 = V_138 * 8 ;
if ( V_139 > 0x1FFFF8 )
V_139 = 0x1FFFF8 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_20 ( V_140 ) |
F_21 ( V_141 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_139 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = 0 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_22 ( V_137 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_23 ( V_137 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_22 ( V_136 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_23 ( V_136 ) ;
V_136 += V_139 ;
V_137 += V_139 ;
V_138 -= V_139 / 8 ;
}
}
static void F_68 ( struct V_46 * V_47 ,
T_4 V_136 ,
T_4 V_68 , unsigned V_138 ,
T_1 V_142 , T_1 V_70 )
{
T_4 V_143 ;
unsigned V_144 ;
while ( V_138 ) {
V_144 = V_138 * 2 ;
if ( V_144 > 0xFFFFE )
V_144 = 0xFFFFE ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_20 ( V_54 ) |
F_21 ( V_141 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_136 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_23 ( V_136 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_144 ;
for (; V_144 > 0 ; V_144 -= 2 , -- V_138 , V_136 += 8 ) {
if ( V_70 & V_145 ) {
V_143 = F_69 ( V_47 -> V_38 -> V_2 , V_68 ) ;
V_143 &= 0xFFFFFFFFFFFFF000ULL ;
} else if ( V_70 & V_146 ) {
V_143 = V_68 ;
} else {
V_143 = 0 ;
}
V_68 += V_142 ;
V_143 |= V_70 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_143 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_23 ( V_143 ) ;
}
}
}
static void F_70 ( struct V_46 * V_47 ,
T_4 V_136 ,
T_4 V_68 , unsigned V_138 ,
T_1 V_142 , T_1 V_70 )
{
T_4 V_143 ;
unsigned V_144 ;
while ( V_138 ) {
V_144 = V_138 ;
if ( V_144 > 0x7FFFF )
V_144 = 0x7FFFF ;
if ( V_70 & V_146 )
V_143 = V_68 ;
else
V_143 = 0 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_20 ( V_147 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_136 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_23 ( V_136 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_70 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = 0 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_143 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_23 ( V_143 ) ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_142 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = 0 ;
V_47 -> V_133 [ V_47 -> V_60 ++ ] = V_144 ;
V_136 += V_144 * 8 ;
V_68 += V_144 * V_142 ;
V_138 -= V_144 ;
}
}
static void F_71 ( struct V_46 * V_47 )
{
while ( V_47 -> V_60 & 0x7 )
V_47 -> V_133 [ V_47 -> V_60 ++ ] = F_20 ( V_57 ) ;
}
static void F_72 ( struct V_37 * V_38 ,
unsigned V_148 , T_4 V_149 )
{
F_19 ( V_38 , F_20 ( V_150 ) |
F_73 ( 0xf ) ) ;
if ( V_148 < 8 ) {
F_19 ( V_38 , ( V_151 + V_148 ) ) ;
} else {
F_19 ( V_38 , ( V_152 + V_148 - 8 ) ) ;
}
F_19 ( V_38 , V_149 >> 12 ) ;
F_19 ( V_38 , F_20 ( V_150 ) |
F_73 ( 0xf ) ) ;
F_19 ( V_38 , V_153 ) ;
F_19 ( V_38 , 1 << V_148 ) ;
F_19 ( V_38 , F_20 ( V_65 ) |
F_28 ( 0 ) |
F_29 ( 0 ) ) ;
F_19 ( V_38 , V_153 << 2 ) ;
F_19 ( V_38 , 0 ) ;
F_19 ( V_38 , 0 ) ;
F_19 ( V_38 , 0 ) ;
F_19 ( V_38 , F_30 ( 0xfff ) |
F_31 ( 10 ) ) ;
}
static int F_74 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static int F_79 ( void * V_154 )
{
struct V_37 * V_38 ;
int V_103 ;
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
V_103 = F_80 ( V_2 , 224 , & V_2 -> V_155 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_80 ( V_2 , 241 , & V_2 -> V_156 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_80 ( V_2 , 247 , & V_2 -> V_156 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_4 ( V_2 ) ;
if ( V_103 ) {
F_57 ( L_15 ) ;
return V_103 ;
}
V_38 = & V_2 -> V_19 [ 0 ] . V_38 ;
V_38 -> V_157 = NULL ;
V_38 -> V_158 = false ;
V_38 = & V_2 -> V_19 [ 1 ] . V_38 ;
V_38 -> V_157 = NULL ;
V_38 -> V_158 = false ;
V_38 = & V_2 -> V_19 [ 0 ] . V_38 ;
sprintf ( V_38 -> V_159 , L_16 ) ;
V_103 = F_81 ( V_2 , V_38 , 256 * 1024 ,
F_82 ( V_57 ) , 0xf ,
& V_2 -> V_155 , V_160 ,
V_161 ) ;
if ( V_103 )
return V_103 ;
V_38 = & V_2 -> V_19 [ 1 ] . V_38 ;
sprintf ( V_38 -> V_159 , L_17 ) ;
V_103 = F_81 ( V_2 , V_38 , 256 * 1024 ,
F_82 ( V_57 ) , 0xf ,
& V_2 -> V_155 , V_162 ,
V_161 ) ;
if ( V_103 )
return V_103 ;
return V_103 ;
}
static int F_83 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
F_84 ( & V_2 -> V_19 [ 0 ] . V_38 ) ;
F_84 ( & V_2 -> V_19 [ 1 ] . V_38 ) ;
return 0 ;
}
static int F_85 ( void * V_154 )
{
int V_103 ;
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
F_1 ( V_2 ) ;
V_103 = F_51 ( V_2 ) ;
if ( V_103 )
return V_103 ;
return V_103 ;
}
static int F_86 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
F_39 ( V_2 , false ) ;
return 0 ;
}
static int F_87 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
return F_86 ( V_2 ) ;
}
static int F_88 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
return F_85 ( V_2 ) ;
}
static bool F_89 ( void * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
V_6 V_131 = F_15 ( V_163 ) ;
if ( V_131 & ( V_164 |
V_165 ) )
return false ;
return true ;
}
static int F_90 ( void * V_154 )
{
unsigned V_11 ;
V_6 V_131 ;
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_132 ; V_11 ++ ) {
V_131 = F_15 ( V_163 ) & ( V_164 |
V_165 ) ;
if ( ! V_131 )
return 0 ;
F_91 ( 1 ) ;
}
return - V_166 ;
}
static void F_92 ( void * V_154 )
{
int V_11 , V_102 ;
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
F_93 ( V_2 -> V_21 , L_18 ) ;
F_93 ( V_2 -> V_21 , L_19 ,
F_15 ( V_163 ) ) ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
F_93 ( V_2 -> V_21 , L_20 ,
V_11 , F_15 ( V_167 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_21 ,
V_11 , F_15 ( V_97 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_22 ,
V_11 , F_15 ( V_168 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_23 ,
V_11 , F_15 ( V_107 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_24 ,
V_11 , F_15 ( V_91 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_25 ,
V_11 , F_15 ( V_88 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_26 ,
V_11 , F_15 ( V_112 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_27 ,
V_11 , F_15 ( V_44 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_28 ,
V_11 , F_15 ( V_113 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_29 ,
V_11 , F_15 ( V_114 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_30 ,
V_11 , F_15 ( V_116 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_31 ,
V_11 , F_15 ( V_117 + V_45 [ V_11 ] ) ) ;
F_41 ( & V_2 -> V_104 ) ;
for ( V_102 = 0 ; V_102 < 16 ; V_102 ++ ) {
F_42 ( V_2 , 0 , 0 , 0 , V_102 ) ;
F_93 ( V_2 -> V_21 , L_32 , V_102 ) ;
F_93 ( V_2 -> V_21 , L_33 ,
V_11 , F_15 ( V_105 + V_45 [ V_11 ] ) ) ;
F_93 ( V_2 -> V_21 , L_34 ,
V_11 , F_15 ( V_106 + V_45 [ V_11 ] ) ) ;
}
F_42 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_43 ( & V_2 -> V_104 ) ;
}
}
static int F_94 ( void * V_154 )
{
V_6 V_169 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
V_6 V_131 = F_15 ( V_163 ) ;
if ( V_131 & V_164 ) {
V_131 = F_15 ( V_97 + V_170 ) ;
V_131 = F_27 ( V_131 , V_98 , V_99 , 0 ) ;
F_17 ( V_97 + V_170 , V_131 ) ;
V_169 |= V_171 ;
}
if ( V_131 & V_165 ) {
V_131 = F_15 ( V_97 + V_172 ) ;
V_131 = F_27 ( V_131 , V_98 , V_99 , 0 ) ;
F_17 ( V_97 + V_172 , V_131 ) ;
V_169 |= V_173 ;
}
if ( V_169 ) {
F_92 ( ( void * ) V_2 ) ;
V_131 = F_15 ( V_174 ) ;
V_131 |= V_169 ;
F_93 ( V_2 -> V_21 , L_35 , V_131 ) ;
F_17 ( V_174 , V_131 ) ;
V_131 = F_15 ( V_174 ) ;
F_91 ( 50 ) ;
V_131 &= ~ V_169 ;
F_17 ( V_174 , V_131 ) ;
V_131 = F_15 ( V_174 ) ;
F_91 ( 50 ) ;
F_92 ( ( void * ) V_2 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_175 * V_137 ,
unsigned type ,
enum V_176 V_177 )
{
V_6 V_178 ;
switch ( type ) {
case V_160 :
switch ( V_177 ) {
case V_179 :
V_178 = F_15 ( V_168 + V_170 ) ;
V_178 = F_27 ( V_178 , V_180 , V_181 , 0 ) ;
F_17 ( V_168 + V_170 , V_178 ) ;
break;
case V_182 :
V_178 = F_15 ( V_168 + V_170 ) ;
V_178 = F_27 ( V_178 , V_180 , V_181 , 1 ) ;
F_17 ( V_168 + V_170 , V_178 ) ;
break;
default:
break;
}
break;
case V_162 :
switch ( V_177 ) {
case V_179 :
V_178 = F_15 ( V_168 + V_172 ) ;
V_178 = F_27 ( V_178 , V_180 , V_181 , 0 ) ;
F_17 ( V_168 + V_172 , V_178 ) ;
break;
case V_182 :
V_178 = F_15 ( V_168 + V_172 ) ;
V_178 = F_27 ( V_178 , V_180 , V_181 , 1 ) ;
F_17 ( V_168 + V_172 , V_178 ) ;
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
static int F_96 ( struct V_1 * V_2 ,
struct V_175 * V_183 ,
struct V_184 * V_185 )
{
T_5 V_186 , V_187 ;
V_186 = ( V_185 -> V_188 & 0x3 ) >> 0 ;
V_187 = ( V_185 -> V_188 & 0xc ) >> 2 ;
F_5 ( L_36 ) ;
switch ( V_186 ) {
case 0 :
switch ( V_187 ) {
case 0 :
F_97 ( & V_2 -> V_19 [ 0 ] . V_38 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_187 ) {
case 0 :
F_97 ( & V_2 -> V_19 [ 1 ] . V_38 ) ;
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
static int F_98 ( struct V_1 * V_2 ,
struct V_175 * V_183 ,
struct V_184 * V_185 )
{
F_57 ( L_37 ) ;
F_99 ( & V_2 -> V_189 ) ;
return 0 ;
}
static int F_100 ( void * V_154 ,
enum V_190 V_177 )
{
return 0 ;
}
static int F_101 ( void * V_154 ,
enum V_191 V_177 )
{
return 0 ;
}
static bool F_102 ( struct V_37 * V_38 )
{
if ( F_89 ( V_38 -> V_2 ) ) {
F_103 ( V_38 ) ;
return false ;
}
return F_104 ( V_38 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
V_2 -> V_19 [ 0 ] . V_38 . V_192 = & V_193 ;
V_2 -> V_19 [ 1 ] . V_38 . V_192 = & V_193 ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_155 . V_194 = V_195 ;
V_2 -> V_155 . V_192 = & V_196 ;
V_2 -> V_156 . V_192 = & V_197 ;
}
static void F_105 ( struct V_37 * V_38 ,
T_4 V_198 ,
T_4 V_199 ,
T_1 V_200 )
{
F_19 ( V_38 , F_20 ( V_140 ) |
F_21 ( V_141 ) ) ;
F_19 ( V_38 , V_200 ) ;
F_19 ( V_38 , 0 ) ;
F_19 ( V_38 , F_22 ( V_198 ) ) ;
F_19 ( V_38 , F_23 ( V_198 ) ) ;
F_19 ( V_38 , F_22 ( V_199 ) ) ;
F_19 ( V_38 , F_23 ( V_199 ) ) ;
}
static void F_106 ( struct V_37 * V_38 ,
T_1 V_201 ,
T_4 V_199 ,
T_1 V_200 )
{
F_19 ( V_38 , F_20 ( V_202 ) ) ;
F_19 ( V_38 , F_22 ( V_199 ) ) ;
F_19 ( V_38 , F_23 ( V_199 ) ) ;
F_19 ( V_38 , V_201 ) ;
F_19 ( V_38 , V_200 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( V_2 -> V_84 . V_203 == NULL ) {
V_2 -> V_84 . V_203 = & V_204 ;
V_2 -> V_84 . V_85 = & V_2 -> V_19 [ 0 ] . V_38 ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 . V_206 == NULL ) {
V_2 -> V_205 . V_206 = & V_207 ;
V_2 -> V_205 . V_208 = & V_2 -> V_19 [ 0 ] . V_38 ;
}
}
