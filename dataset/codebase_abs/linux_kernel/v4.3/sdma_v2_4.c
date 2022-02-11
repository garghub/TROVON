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
if ( V_2 -> V_19 [ V_11 ] . V_26 >= 20 )
V_2 -> V_19 [ V_11 ] . V_28 = true ;
if ( V_2 -> V_29 . V_30 ) {
V_13 = & V_2 -> V_29 . V_31 [ V_32 + V_11 ] ;
V_13 -> V_33 = V_32 + V_11 ;
V_13 -> V_20 = V_2 -> V_19 [ V_11 ] . V_20 ;
V_15 = ( const struct V_14 * ) V_13 -> V_20 -> V_23 ;
V_2 -> V_29 . V_34 +=
F_10 ( F_9 ( V_15 -> V_35 ) , V_36 ) ;
}
}
V_22:
if ( V_10 ) {
F_11 ( V_37
L_5 ,
V_9 ) ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
F_12 ( V_2 -> V_19 [ V_11 ] . V_20 ) ;
V_2 -> V_19 [ V_11 ] . V_20 = NULL ;
}
}
return V_10 ;
}
static T_1 F_13 ( struct V_38 * V_39 )
{
V_6 V_40 ;
V_40 = V_39 -> V_2 -> V_41 . V_41 [ V_39 -> V_42 ] >> 2 ;
return V_40 ;
}
static T_1 F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
int V_43 = ( V_39 == & V_39 -> V_2 -> V_19 [ 0 ] . V_39 ) ? 0 : 1 ;
V_6 V_44 = F_15 ( V_45 + V_46 [ V_43 ] ) >> 2 ;
return V_44 ;
}
static void F_16 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
int V_43 = ( V_39 == & V_39 -> V_2 -> V_19 [ 0 ] . V_39 ) ? 0 : 1 ;
F_17 ( V_45 + V_46 [ V_43 ] , V_39 -> V_44 << 2 ) ;
}
static void F_18 ( struct V_38 * V_39 , T_1 V_47 )
{
struct V_48 * V_19 = F_19 ( V_39 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_47 ; V_11 ++ )
if ( V_19 && V_19 -> V_28 && ( V_11 == 0 ) )
F_20 ( V_39 , V_39 -> V_49 |
F_21 ( V_47 - 1 ) ) ;
else
F_20 ( V_39 , V_39 -> V_49 ) ;
}
static void F_22 ( struct V_38 * V_39 ,
struct V_50 * V_51 )
{
V_6 V_52 = ( V_51 -> V_53 ? V_51 -> V_53 -> V_54 [ V_39 -> V_55 ] . V_56 : 0 ) & 0xf ;
V_6 V_57 = V_39 -> V_44 + 5 ;
while ( ( V_57 & 7 ) != 2 )
V_57 ++ ;
V_57 += 6 ;
F_20 ( V_39 , F_23 ( V_58 ) |
F_24 ( V_59 ) ) ;
F_20 ( V_39 , F_25 ( V_39 -> V_60 ) & 0xfffffffc ) ;
F_20 ( V_39 , F_26 ( V_39 -> V_60 ) ) ;
F_20 ( V_39 , F_27 ( 1 ) ) ;
F_20 ( V_39 , V_57 ) ;
F_18 ( V_39 , ( 10 - ( V_39 -> V_44 & 7 ) ) % 8 ) ;
F_20 ( V_39 , F_23 ( V_61 ) |
F_28 ( V_52 ) ) ;
F_20 ( V_39 , F_25 ( V_51 -> V_62 ) & 0xffffffe0 ) ;
F_20 ( V_39 , F_26 ( V_51 -> V_62 ) ) ;
F_20 ( V_39 , V_51 -> V_63 ) ;
F_20 ( V_39 , 0 ) ;
F_20 ( V_39 , 0 ) ;
}
static void F_29 ( struct V_38 * V_39 )
{
V_6 V_64 = 0 ;
if ( V_39 == & V_39 -> V_2 -> V_19 [ 0 ] . V_39 )
V_64 = F_30 ( V_64 , V_65 , V_66 , 1 ) ;
else
V_64 = F_30 ( V_64 , V_65 , V_67 , 1 ) ;
F_20 ( V_39 , F_23 ( V_68 ) |
F_31 ( 1 ) |
F_32 ( 3 ) ) ;
F_20 ( V_39 , V_69 << 2 ) ;
F_20 ( V_39 , V_70 << 2 ) ;
F_20 ( V_39 , V_64 ) ;
F_20 ( V_39 , V_64 ) ;
F_20 ( V_39 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static void F_35 ( struct V_38 * V_39 , T_2 V_71 , T_2 V_72 ,
unsigned V_73 )
{
bool V_74 = V_73 & V_75 ;
F_20 ( V_39 , F_23 ( V_76 ) ) ;
F_20 ( V_39 , F_25 ( V_71 ) ) ;
F_20 ( V_39 , F_26 ( V_71 ) ) ;
F_20 ( V_39 , F_25 ( V_72 ) ) ;
if ( V_74 ) {
V_71 += 4 ;
F_20 ( V_39 , F_23 ( V_76 ) ) ;
F_20 ( V_39 , F_25 ( V_71 ) ) ;
F_20 ( V_39 , F_26 ( V_71 ) ) ;
F_20 ( V_39 , F_26 ( V_72 ) ) ;
}
F_20 ( V_39 , F_23 ( V_77 ) ) ;
F_20 ( V_39 , F_36 ( 0 ) ) ;
}
static bool F_37 ( struct V_38 * V_39 ,
struct V_78 * V_79 ,
bool V_80 )
{
T_2 V_71 = V_79 -> V_62 ;
V_6 V_81 = V_80 ? 0 : 1 ;
F_20 ( V_39 , F_23 ( V_82 ) |
F_38 ( V_81 ) ) ;
F_20 ( V_39 , F_25 ( V_71 ) & 0xfffffff8 ) ;
F_20 ( V_39 , F_26 ( V_71 ) ) ;
return true ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_38 * V_83 = & V_2 -> V_19 [ 0 ] . V_39 ;
struct V_38 * V_84 = & V_2 -> V_19 [ 1 ] . V_39 ;
V_6 V_85 , V_86 ;
int V_11 ;
if ( ( V_2 -> V_87 . V_88 == V_83 ) ||
( V_2 -> V_87 . V_88 == V_84 ) )
F_40 ( V_2 , V_2 -> V_89 . V_90 ) ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_85 = F_15 ( V_91 + V_46 [ V_11 ] ) ;
V_85 = F_30 ( V_85 , V_92 , V_93 , 0 ) ;
F_17 ( V_91 + V_46 [ V_11 ] , V_85 ) ;
V_86 = F_15 ( V_94 + V_46 [ V_11 ] ) ;
V_86 = F_30 ( V_86 , V_95 , V_96 , 0 ) ;
F_17 ( V_94 + V_46 [ V_11 ] , V_86 ) ;
}
V_83 -> V_97 = false ;
V_84 -> V_97 = false ;
}
static void F_41 ( struct V_1 * V_2 )
{
}
static void F_42 ( struct V_1 * V_2 , bool V_98 )
{
V_6 V_99 ;
int V_11 ;
if ( V_98 == false ) {
F_39 ( V_2 ) ;
F_41 ( V_2 ) ;
}
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_99 = F_15 ( V_100 + V_46 [ V_11 ] ) ;
if ( V_98 )
V_99 = F_30 ( V_99 , V_101 , V_102 , 0 ) ;
else
V_99 = F_30 ( V_99 , V_101 , V_102 , 1 ) ;
F_17 ( V_100 + V_46 [ V_11 ] , V_99 ) ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
V_6 V_85 , V_86 ;
V_6 V_103 ;
V_6 V_104 ;
int V_11 , V_105 , V_106 ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_39 = & V_2 -> V_19 [ V_11 ] . V_39 ;
V_104 = ( V_39 -> V_42 * 4 ) ;
F_44 ( & V_2 -> V_107 ) ;
for ( V_105 = 0 ; V_105 < 16 ; V_105 ++ ) {
F_45 ( V_2 , 0 , 0 , 0 , V_105 ) ;
F_17 ( V_108 + V_46 [ V_11 ] , 0 ) ;
F_17 ( V_109 + V_46 [ V_11 ] , 0 ) ;
}
F_45 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_46 ( & V_2 -> V_107 ) ;
F_17 ( V_110 + V_46 [ V_11 ] , 0 ) ;
V_103 = F_47 ( V_39 -> V_111 / 4 ) ;
V_85 = F_15 ( V_91 + V_46 [ V_11 ] ) ;
V_85 = F_30 ( V_85 , V_92 , V_112 , V_103 ) ;
#ifdef F_48
V_85 = F_30 ( V_85 , V_92 , V_113 , 1 ) ;
V_85 = F_30 ( V_85 , V_92 ,
V_114 , 1 ) ;
#endif
F_17 ( V_91 + V_46 [ V_11 ] , V_85 ) ;
F_17 ( V_115 + V_46 [ V_11 ] , 0 ) ;
F_17 ( V_45 + V_46 [ V_11 ] , 0 ) ;
F_17 ( V_116 + V_46 [ V_11 ] ,
F_26 ( V_2 -> V_41 . V_62 + V_104 ) & 0xFFFFFFFF ) ;
F_17 ( V_117 + V_46 [ V_11 ] ,
F_25 ( V_2 -> V_41 . V_62 + V_104 ) & 0xFFFFFFFC ) ;
V_85 = F_30 ( V_85 , V_92 , V_118 , 1 ) ;
F_17 ( V_119 + V_46 [ V_11 ] , V_39 -> V_62 >> 8 ) ;
F_17 ( V_120 + V_46 [ V_11 ] , V_39 -> V_62 >> 40 ) ;
V_39 -> V_44 = 0 ;
F_17 ( V_45 + V_46 [ V_11 ] , V_39 -> V_44 << 2 ) ;
V_85 = F_30 ( V_85 , V_92 , V_93 , 1 ) ;
F_17 ( V_91 + V_46 [ V_11 ] , V_85 ) ;
V_86 = F_15 ( V_94 + V_46 [ V_11 ] ) ;
V_86 = F_30 ( V_86 , V_95 , V_96 , 1 ) ;
#ifdef F_48
V_86 = F_30 ( V_86 , V_95 , V_121 , 1 ) ;
#endif
F_17 ( V_94 + V_46 [ V_11 ] , V_86 ) ;
V_39 -> V_97 = true ;
V_106 = F_49 ( V_39 ) ;
if ( V_106 ) {
V_39 -> V_97 = false ;
return V_106 ;
}
if ( V_2 -> V_87 . V_88 == V_39 )
F_40 ( V_2 , V_2 -> V_89 . V_122 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
const struct V_16 * V_17 ;
const T_3 * V_123 ;
V_6 V_34 ;
int V_11 , V_105 ;
bool V_124 = false ;
if ( ! V_2 -> V_19 [ 0 ] . V_20 || ! V_2 -> V_19 [ 1 ] . V_20 )
return - V_125 ;
F_42 ( V_2 , false ) ;
if ( V_124 ) {
} else {
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_17 = ( const struct V_16 * ) V_2 -> V_19 [ V_11 ] . V_20 -> V_23 ;
F_52 ( & V_17 -> V_15 ) ;
V_34 = F_9 ( V_17 -> V_15 . V_35 ) / 4 ;
V_123 = ( const T_3 * )
( V_2 -> V_19 [ V_11 ] . V_20 -> V_23 +
F_9 ( V_17 -> V_15 . V_126 ) ) ;
F_17 ( V_127 + V_46 [ V_11 ] , 0 ) ;
for ( V_105 = 0 ; V_105 < V_34 ; V_105 ++ )
F_17 ( V_128 + V_46 [ V_11 ] , F_53 ( V_123 ++ ) ) ;
F_17 ( V_127 + V_46 [ V_11 ] , V_2 -> V_19 [ V_11 ] . V_24 ) ;
}
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_106 ;
if ( ! V_2 -> V_29 . V_30 ) {
V_106 = F_51 ( V_2 ) ;
if ( V_106 )
return V_106 ;
} else {
V_106 = V_2 -> V_129 . V_130 -> V_131 ( V_2 ,
V_32 ) ;
if ( V_106 )
return - V_125 ;
V_106 = V_2 -> V_129 . V_130 -> V_131 ( V_2 ,
V_132 ) ;
if ( V_106 )
return - V_125 ;
}
F_42 ( V_2 , true ) ;
V_106 = F_43 ( V_2 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_50 ( V_2 ) ;
if ( V_106 )
return V_106 ;
return 0 ;
}
static int F_55 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
unsigned V_11 ;
unsigned V_133 ;
int V_106 ;
V_6 V_134 ;
T_2 V_62 ;
V_106 = F_56 ( V_2 , & V_133 ) ;
if ( V_106 ) {
F_57 ( V_2 -> V_21 , L_6 , V_106 ) ;
return V_106 ;
}
V_62 = V_2 -> V_41 . V_62 + ( V_133 * 4 ) ;
V_134 = 0xCAFEDEAD ;
V_2 -> V_41 . V_41 [ V_133 ] = F_58 ( V_134 ) ;
V_106 = F_59 ( V_39 , 5 ) ;
if ( V_106 ) {
F_60 ( L_7 , V_39 -> V_55 , V_106 ) ;
F_61 ( V_2 , V_133 ) ;
return V_106 ;
}
F_20 ( V_39 , F_23 ( V_58 ) |
F_24 ( V_59 ) ) ;
F_20 ( V_39 , F_25 ( V_62 ) ) ;
F_20 ( V_39 , F_26 ( V_62 ) ) ;
F_20 ( V_39 , F_27 ( 1 ) ) ;
F_20 ( V_39 , 0xDEADBEEF ) ;
F_62 ( V_39 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_135 ; V_11 ++ ) {
V_134 = F_9 ( V_2 -> V_41 . V_41 [ V_133 ] ) ;
if ( V_134 == 0xDEADBEEF )
break;
F_63 ( 1 ) ;
}
if ( V_11 < V_2 -> V_135 ) {
F_64 ( L_8 , V_39 -> V_55 , V_11 ) ;
} else {
F_60 ( L_9 ,
V_39 -> V_55 , V_134 ) ;
V_106 = - V_125 ;
}
F_61 ( V_2 , V_133 ) ;
return V_106 ;
}
static int F_65 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_50 V_51 ;
struct V_136 * V_137 = NULL ;
unsigned V_11 ;
unsigned V_133 ;
int V_106 ;
V_6 V_134 = 0 ;
T_2 V_62 ;
V_106 = F_56 ( V_2 , & V_133 ) ;
if ( V_106 ) {
F_57 ( V_2 -> V_21 , L_6 , V_106 ) ;
return V_106 ;
}
V_62 = V_2 -> V_41 . V_62 + ( V_133 * 4 ) ;
V_134 = 0xCAFEDEAD ;
V_2 -> V_41 . V_41 [ V_133 ] = F_58 ( V_134 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_106 = F_66 ( V_39 , NULL , 256 , & V_51 ) ;
if ( V_106 ) {
F_60 ( L_10 , V_106 ) ;
goto V_138;
}
V_51 . V_139 [ 0 ] = F_23 ( V_58 ) |
F_24 ( V_59 ) ;
V_51 . V_139 [ 1 ] = F_25 ( V_62 ) ;
V_51 . V_139 [ 2 ] = F_26 ( V_62 ) ;
V_51 . V_139 [ 3 ] = F_27 ( 1 ) ;
V_51 . V_139 [ 4 ] = 0xDEADBEEF ;
V_51 . V_139 [ 5 ] = F_23 ( V_140 ) ;
V_51 . V_139 [ 6 ] = F_23 ( V_140 ) ;
V_51 . V_139 [ 7 ] = F_23 ( V_140 ) ;
V_51 . V_63 = 8 ;
V_106 = F_67 ( V_2 , V_39 , & V_51 , 1 , NULL ,
V_141 ,
& V_137 ) ;
if ( V_106 )
goto V_142;
V_106 = F_68 ( V_137 , false ) ;
if ( V_106 ) {
F_60 ( L_11 , V_106 ) ;
goto V_142;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_135 ; V_11 ++ ) {
V_134 = F_9 ( V_2 -> V_41 . V_41 [ V_133 ] ) ;
if ( V_134 == 0xDEADBEEF )
break;
F_63 ( 1 ) ;
}
if ( V_11 < V_2 -> V_135 ) {
F_64 ( L_12 ,
V_39 -> V_55 , V_11 ) ;
goto V_142;
} else {
F_60 ( L_13 , V_134 ) ;
V_106 = - V_125 ;
}
V_142:
F_69 ( V_137 ) ;
F_70 ( V_2 , & V_51 ) ;
V_138:
F_61 ( V_2 , V_133 ) ;
return V_106 ;
}
static void F_71 ( struct V_50 * V_51 ,
T_4 V_143 , T_4 V_144 ,
unsigned V_47 )
{
while ( V_47 ) {
unsigned V_145 = V_47 * 8 ;
if ( V_145 > 0x1FFFF8 )
V_145 = 0x1FFFF8 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_23 ( V_146 ) |
F_24 ( V_147 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_145 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = 0 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_25 ( V_144 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_144 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_25 ( V_143 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_143 ) ;
V_143 += V_145 ;
V_144 += V_145 ;
V_47 -= V_145 / 8 ;
}
}
static void F_72 ( struct V_50 * V_51 ,
T_4 V_143 ,
T_4 V_71 , unsigned V_47 ,
T_1 V_148 , T_1 V_73 )
{
T_4 V_149 ;
unsigned V_150 ;
while ( V_47 ) {
V_150 = V_47 * 2 ;
if ( V_150 > 0xFFFFE )
V_150 = 0xFFFFE ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_23 ( V_58 ) |
F_24 ( V_147 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_143 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_143 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_150 ;
for (; V_150 > 0 ; V_150 -= 2 , -- V_47 , V_143 += 8 ) {
if ( V_73 & V_151 ) {
V_149 = F_73 ( V_51 -> V_39 -> V_2 , V_71 ) ;
V_149 &= 0xFFFFFFFFFFFFF000ULL ;
} else if ( V_73 & V_152 ) {
V_149 = V_71 ;
} else {
V_149 = 0 ;
}
V_71 += V_148 ;
V_149 |= V_73 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_149 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_149 ) ;
}
}
}
static void F_74 ( struct V_50 * V_51 ,
T_4 V_143 ,
T_4 V_71 , unsigned V_47 ,
T_1 V_148 , T_1 V_73 )
{
T_4 V_149 ;
unsigned V_150 ;
while ( V_47 ) {
V_150 = V_47 ;
if ( V_150 > 0x7FFFF )
V_150 = 0x7FFFF ;
if ( V_73 & V_152 )
V_149 = V_71 ;
else
V_149 = 0 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_23 ( V_153 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_143 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_143 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_73 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = 0 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_149 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_149 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_148 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = 0 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_150 ;
V_143 += V_150 * 8 ;
V_71 += V_150 * V_148 ;
V_47 -= V_150 ;
}
}
static void F_75 ( struct V_50 * V_51 )
{
struct V_48 * V_19 = F_19 ( V_51 -> V_39 ) ;
V_6 V_154 ;
int V_11 ;
V_154 = ( 8 - ( V_51 -> V_63 & 0x7 ) ) % 8 ;
for ( V_11 = 0 ; V_11 < V_154 ; V_11 ++ )
if ( V_19 && V_19 -> V_28 && ( V_11 == 0 ) )
V_51 -> V_139 [ V_51 -> V_63 ++ ] =
F_23 ( V_140 ) |
F_21 ( V_154 - 1 ) ;
else
V_51 -> V_139 [ V_51 -> V_63 ++ ] =
F_23 ( V_140 ) ;
}
static void F_76 ( struct V_38 * V_39 ,
unsigned V_155 , T_4 V_156 )
{
F_20 ( V_39 , F_23 ( V_157 ) |
F_77 ( 0xf ) ) ;
if ( V_155 < 8 ) {
F_20 ( V_39 , ( V_158 + V_155 ) ) ;
} else {
F_20 ( V_39 , ( V_159 + V_155 - 8 ) ) ;
}
F_20 ( V_39 , V_156 >> 12 ) ;
F_20 ( V_39 , F_23 ( V_157 ) |
F_77 ( 0xf ) ) ;
F_20 ( V_39 , V_160 ) ;
F_20 ( V_39 , 1 << V_155 ) ;
F_20 ( V_39 , F_23 ( V_68 ) |
F_31 ( 0 ) |
F_32 ( 0 ) ) ;
F_20 ( V_39 , V_160 << 2 ) ;
F_20 ( V_39 , 0 ) ;
F_20 ( V_39 , 0 ) ;
F_20 ( V_39 , 0 ) ;
F_20 ( V_39 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static int F_78 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int F_83 ( void * V_161 )
{
struct V_38 * V_39 ;
int V_106 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
V_106 = F_84 ( V_2 , 224 , & V_2 -> V_162 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_84 ( V_2 , 241 , & V_2 -> V_163 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_84 ( V_2 , 247 , & V_2 -> V_163 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_4 ( V_2 ) ;
if ( V_106 ) {
F_60 ( L_14 ) ;
return V_106 ;
}
V_39 = & V_2 -> V_19 [ 0 ] . V_39 ;
V_39 -> V_164 = NULL ;
V_39 -> V_165 = false ;
V_39 = & V_2 -> V_19 [ 1 ] . V_39 ;
V_39 -> V_164 = NULL ;
V_39 -> V_165 = false ;
V_39 = & V_2 -> V_19 [ 0 ] . V_39 ;
sprintf ( V_39 -> V_166 , L_15 ) ;
V_106 = F_85 ( V_2 , V_39 , 256 * 1024 ,
F_86 ( V_140 ) , 0xf ,
& V_2 -> V_162 , V_167 ,
V_168 ) ;
if ( V_106 )
return V_106 ;
V_39 = & V_2 -> V_19 [ 1 ] . V_39 ;
sprintf ( V_39 -> V_166 , L_16 ) ;
V_106 = F_85 ( V_2 , V_39 , 256 * 1024 ,
F_86 ( V_140 ) , 0xf ,
& V_2 -> V_162 , V_169 ,
V_168 ) ;
if ( V_106 )
return V_106 ;
return V_106 ;
}
static int F_87 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
F_88 ( & V_2 -> V_19 [ 0 ] . V_39 ) ;
F_88 ( & V_2 -> V_19 [ 1 ] . V_39 ) ;
return 0 ;
}
static int F_89 ( void * V_161 )
{
int V_106 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
F_1 ( V_2 ) ;
V_106 = F_54 ( V_2 ) ;
if ( V_106 )
return V_106 ;
return V_106 ;
}
static int F_90 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
F_42 ( V_2 , false ) ;
return 0 ;
}
static int F_91 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
return F_90 ( V_2 ) ;
}
static int F_92 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
return F_89 ( V_2 ) ;
}
static bool F_93 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
V_6 V_134 = F_15 ( V_170 ) ;
if ( V_134 & ( V_171 |
V_172 ) )
return false ;
return true ;
}
static int F_94 ( void * V_161 )
{
unsigned V_11 ;
V_6 V_134 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_135 ; V_11 ++ ) {
V_134 = F_15 ( V_170 ) & ( V_171 |
V_172 ) ;
if ( ! V_134 )
return 0 ;
F_95 ( 1 ) ;
}
return - V_173 ;
}
static void F_96 ( void * V_161 )
{
int V_11 , V_105 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
F_97 ( V_2 -> V_21 , L_17 ) ;
F_97 ( V_2 -> V_21 , L_18 ,
F_15 ( V_170 ) ) ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
F_97 ( V_2 -> V_21 , L_19 ,
V_11 , F_15 ( V_174 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_20 ,
V_11 , F_15 ( V_100 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_21 ,
V_11 , F_15 ( V_175 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_22 ,
V_11 , F_15 ( V_110 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_23 ,
V_11 , F_15 ( V_94 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_24 ,
V_11 , F_15 ( V_91 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_25 ,
V_11 , F_15 ( V_115 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_26 ,
V_11 , F_15 ( V_45 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_27 ,
V_11 , F_15 ( V_116 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_28 ,
V_11 , F_15 ( V_117 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_29 ,
V_11 , F_15 ( V_119 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_30 ,
V_11 , F_15 ( V_120 + V_46 [ V_11 ] ) ) ;
F_44 ( & V_2 -> V_107 ) ;
for ( V_105 = 0 ; V_105 < 16 ; V_105 ++ ) {
F_45 ( V_2 , 0 , 0 , 0 , V_105 ) ;
F_97 ( V_2 -> V_21 , L_31 , V_105 ) ;
F_97 ( V_2 -> V_21 , L_32 ,
V_11 , F_15 ( V_108 + V_46 [ V_11 ] ) ) ;
F_97 ( V_2 -> V_21 , L_33 ,
V_11 , F_15 ( V_109 + V_46 [ V_11 ] ) ) ;
}
F_45 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_46 ( & V_2 -> V_107 ) ;
}
}
static int F_98 ( void * V_161 )
{
V_6 V_176 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
V_6 V_134 = F_15 ( V_170 ) ;
if ( V_134 & V_171 ) {
V_134 = F_15 ( V_100 + V_177 ) ;
V_134 = F_30 ( V_134 , V_101 , V_102 , 0 ) ;
F_17 ( V_100 + V_177 , V_134 ) ;
V_176 |= V_178 ;
}
if ( V_134 & V_172 ) {
V_134 = F_15 ( V_100 + V_179 ) ;
V_134 = F_30 ( V_134 , V_101 , V_102 , 0 ) ;
F_17 ( V_100 + V_179 , V_134 ) ;
V_176 |= V_180 ;
}
if ( V_176 ) {
F_96 ( ( void * ) V_2 ) ;
V_134 = F_15 ( V_181 ) ;
V_134 |= V_176 ;
F_97 ( V_2 -> V_21 , L_34 , V_134 ) ;
F_17 ( V_181 , V_134 ) ;
V_134 = F_15 ( V_181 ) ;
F_95 ( 50 ) ;
V_134 &= ~ V_176 ;
F_17 ( V_181 , V_134 ) ;
V_134 = F_15 ( V_181 ) ;
F_95 ( 50 ) ;
F_96 ( ( void * ) V_2 ) ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_182 * V_144 ,
unsigned type ,
enum V_183 V_184 )
{
V_6 V_185 ;
switch ( type ) {
case V_167 :
switch ( V_184 ) {
case V_186 :
V_185 = F_15 ( V_175 + V_177 ) ;
V_185 = F_30 ( V_185 , V_187 , V_188 , 0 ) ;
F_17 ( V_175 + V_177 , V_185 ) ;
break;
case V_189 :
V_185 = F_15 ( V_175 + V_177 ) ;
V_185 = F_30 ( V_185 , V_187 , V_188 , 1 ) ;
F_17 ( V_175 + V_177 , V_185 ) ;
break;
default:
break;
}
break;
case V_169 :
switch ( V_184 ) {
case V_186 :
V_185 = F_15 ( V_175 + V_179 ) ;
V_185 = F_30 ( V_185 , V_187 , V_188 , 0 ) ;
F_17 ( V_175 + V_179 , V_185 ) ;
break;
case V_189 :
V_185 = F_15 ( V_175 + V_179 ) ;
V_185 = F_30 ( V_185 , V_187 , V_188 , 1 ) ;
F_17 ( V_175 + V_179 , V_185 ) ;
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
static int F_100 ( struct V_1 * V_2 ,
struct V_182 * V_190 ,
struct V_191 * V_192 )
{
T_5 V_193 , V_194 ;
V_193 = ( V_192 -> V_195 & 0x3 ) >> 0 ;
V_194 = ( V_192 -> V_195 & 0xc ) >> 2 ;
F_5 ( L_35 ) ;
switch ( V_193 ) {
case 0 :
switch ( V_194 ) {
case 0 :
F_101 ( & V_2 -> V_19 [ 0 ] . V_39 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_194 ) {
case 0 :
F_101 ( & V_2 -> V_19 [ 1 ] . V_39 ) ;
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
static int F_102 ( struct V_1 * V_2 ,
struct V_182 * V_190 ,
struct V_191 * V_192 )
{
F_60 ( L_36 ) ;
F_103 ( & V_2 -> V_196 ) ;
return 0 ;
}
static int F_104 ( void * V_161 ,
enum V_197 V_184 )
{
return 0 ;
}
static int F_105 ( void * V_161 ,
enum V_198 V_184 )
{
return 0 ;
}
static bool F_106 ( struct V_38 * V_39 )
{
if ( F_93 ( V_39 -> V_2 ) ) {
F_107 ( V_39 ) ;
return false ;
}
return F_108 ( V_39 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
V_2 -> V_19 [ 0 ] . V_39 . V_199 = & V_200 ;
V_2 -> V_19 [ 1 ] . V_39 . V_199 = & V_200 ;
}
static void F_82 ( struct V_1 * V_2 )
{
V_2 -> V_162 . V_201 = V_202 ;
V_2 -> V_162 . V_199 = & V_203 ;
V_2 -> V_163 . V_199 = & V_204 ;
}
static void F_109 ( struct V_50 * V_51 ,
T_4 V_205 ,
T_4 V_206 ,
T_1 V_207 )
{
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_23 ( V_146 ) |
F_24 ( V_147 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_207 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = 0 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_25 ( V_205 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_205 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_25 ( V_206 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_206 ) ;
}
static void F_110 ( struct V_50 * V_51 ,
T_1 V_208 ,
T_4 V_206 ,
T_1 V_207 )
{
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_23 ( V_209 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_25 ( V_206 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = F_26 ( V_206 ) ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_208 ;
V_51 -> V_139 [ V_51 -> V_63 ++ ] = V_207 ;
}
static void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 . V_210 == NULL ) {
V_2 -> V_87 . V_210 = & V_211 ;
V_2 -> V_87 . V_88 = & V_2 -> V_19 [ 0 ] . V_39 ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_212 . V_213 == NULL ) {
V_2 -> V_212 . V_213 = & V_214 ;
V_2 -> V_212 . V_215 = & V_2 -> V_19 [ 0 ] . V_39 ;
V_2 -> V_212 . V_215 -> V_216 = true ;
}
}
