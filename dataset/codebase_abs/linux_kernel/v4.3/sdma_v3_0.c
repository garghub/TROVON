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
case V_8 :
F_2 ( V_2 ,
V_9 ,
( const V_6 ) F_3 ( V_9 ) ) ;
F_2 ( V_2 ,
V_10 ,
( const V_6 ) F_3 ( V_10 ) ) ;
break;
case V_11 :
F_2 ( V_2 ,
V_12 ,
( const V_6 ) F_3 ( V_12 ) ) ;
F_2 ( V_2 ,
V_13 ,
( const V_6 ) F_3 ( V_13 ) ) ;
break;
default:
break;
}
}
static int F_4 ( struct V_1 * V_2 )
{
const char * V_14 ;
char V_15 [ 30 ] ;
int V_16 , V_17 ;
struct V_18 * V_19 = NULL ;
const struct V_20 * V_21 = NULL ;
const struct V_22 * V_23 ;
F_5 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_8 :
V_14 = L_2 ;
break;
case V_4 :
V_14 = L_3 ;
break;
case V_11 :
V_14 = L_4 ;
break;
default: F_6 () ;
}
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
if ( V_17 == 0 )
snprintf ( V_15 , sizeof( V_15 ) , L_5 , V_14 ) ;
else
snprintf ( V_15 , sizeof( V_15 ) , L_6 , V_14 ) ;
V_16 = F_7 ( & V_2 -> V_25 [ V_17 ] . V_26 , V_15 , V_2 -> V_27 ) ;
if ( V_16 )
goto V_28;
V_16 = F_8 ( V_2 -> V_25 [ V_17 ] . V_26 ) ;
if ( V_16 )
goto V_28;
V_23 = ( const struct V_22 * ) V_2 -> V_25 [ V_17 ] . V_26 -> V_29 ;
V_2 -> V_25 [ V_17 ] . V_30 = F_9 ( V_23 -> V_21 . V_31 ) ;
V_2 -> V_25 [ V_17 ] . V_32 = F_9 ( V_23 -> V_33 ) ;
if ( V_2 -> V_25 [ V_17 ] . V_32 >= 20 )
V_2 -> V_25 [ V_17 ] . V_34 = true ;
if ( V_2 -> V_35 . V_36 ) {
V_19 = & V_2 -> V_35 . V_37 [ V_38 + V_17 ] ;
V_19 -> V_39 = V_38 + V_17 ;
V_19 -> V_26 = V_2 -> V_25 [ V_17 ] . V_26 ;
V_21 = ( const struct V_20 * ) V_19 -> V_26 -> V_29 ;
V_2 -> V_35 . V_40 +=
F_10 ( F_9 ( V_21 -> V_41 ) , V_42 ) ;
}
}
V_28:
if ( V_16 ) {
F_11 ( V_43
L_7 ,
V_15 ) ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
F_12 ( V_2 -> V_25 [ V_17 ] . V_26 ) ;
V_2 -> V_25 [ V_17 ] . V_26 = NULL ;
}
}
return V_16 ;
}
static T_1 F_13 ( struct V_44 * V_45 )
{
V_6 V_46 ;
V_46 = V_45 -> V_2 -> V_47 . V_47 [ V_45 -> V_48 ] >> 2 ;
return V_46 ;
}
static T_1 F_14 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
V_6 V_49 ;
if ( V_45 -> V_50 ) {
V_49 = V_45 -> V_2 -> V_47 . V_47 [ V_45 -> V_51 ] >> 2 ;
} else {
int V_52 = ( V_45 == & V_45 -> V_2 -> V_25 [ 0 ] . V_45 ) ? 0 : 1 ;
V_49 = F_15 ( V_53 + V_54 [ V_52 ] ) >> 2 ;
}
return V_49 ;
}
static void F_16 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
if ( V_45 -> V_50 ) {
V_2 -> V_47 . V_47 [ V_45 -> V_51 ] = V_45 -> V_49 << 2 ;
F_17 ( V_45 -> V_55 , V_45 -> V_49 << 2 ) ;
} else {
int V_52 = ( V_45 == & V_45 -> V_2 -> V_25 [ 0 ] . V_45 ) ? 0 : 1 ;
F_18 ( V_53 + V_54 [ V_52 ] , V_45 -> V_49 << 2 ) ;
}
}
static void F_19 ( struct V_44 * V_45 , T_1 V_56 )
{
struct V_57 * V_25 = F_20 ( V_45 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_56 ; V_17 ++ )
if ( V_25 && V_25 -> V_34 && ( V_17 == 0 ) )
F_21 ( V_45 , V_45 -> V_58 |
F_22 ( V_56 - 1 ) ) ;
else
F_21 ( V_45 , V_45 -> V_58 ) ;
}
static void F_23 ( struct V_44 * V_45 ,
struct V_59 * V_60 )
{
V_6 V_61 = ( V_60 -> V_62 ? V_60 -> V_62 -> V_63 [ V_45 -> V_64 ] . V_65 : 0 ) & 0xf ;
V_6 V_66 = V_45 -> V_49 + 5 ;
while ( ( V_66 & 7 ) != 2 )
V_66 ++ ;
V_66 += 6 ;
F_21 ( V_45 , F_24 ( V_67 ) |
F_25 ( V_68 ) ) ;
F_21 ( V_45 , F_26 ( V_45 -> V_69 ) & 0xfffffffc ) ;
F_21 ( V_45 , F_27 ( V_45 -> V_69 ) ) ;
F_21 ( V_45 , F_28 ( 1 ) ) ;
F_21 ( V_45 , V_66 ) ;
F_19 ( V_45 , ( 10 - ( V_45 -> V_49 & 7 ) ) % 8 ) ;
F_21 ( V_45 , F_24 ( V_70 ) |
F_29 ( V_61 ) ) ;
F_21 ( V_45 , F_26 ( V_60 -> V_71 ) & 0xffffffe0 ) ;
F_21 ( V_45 , F_27 ( V_60 -> V_71 ) ) ;
F_21 ( V_45 , V_60 -> V_72 ) ;
F_21 ( V_45 , 0 ) ;
F_21 ( V_45 , 0 ) ;
}
static void F_30 ( struct V_44 * V_45 )
{
V_6 V_73 = 0 ;
if ( V_45 == & V_45 -> V_2 -> V_25 [ 0 ] . V_45 )
V_73 = F_31 ( V_73 , V_74 , V_75 , 1 ) ;
else
V_73 = F_31 ( V_73 , V_74 , V_76 , 1 ) ;
F_21 ( V_45 , F_24 ( V_77 ) |
F_32 ( 1 ) |
F_33 ( 3 ) ) ;
F_21 ( V_45 , V_78 << 2 ) ;
F_21 ( V_45 , V_79 << 2 ) ;
F_21 ( V_45 , V_73 ) ;
F_21 ( V_45 , V_73 ) ;
F_21 ( V_45 , F_34 ( 0xfff ) |
F_35 ( 10 ) ) ;
}
static void F_36 ( struct V_44 * V_45 , T_2 V_80 , T_2 V_81 ,
unsigned V_82 )
{
bool V_83 = V_82 & V_84 ;
F_21 ( V_45 , F_24 ( V_85 ) ) ;
F_21 ( V_45 , F_26 ( V_80 ) ) ;
F_21 ( V_45 , F_27 ( V_80 ) ) ;
F_21 ( V_45 , F_26 ( V_81 ) ) ;
if ( V_83 ) {
V_80 += 4 ;
F_21 ( V_45 , F_24 ( V_85 ) ) ;
F_21 ( V_45 , F_26 ( V_80 ) ) ;
F_21 ( V_45 , F_27 ( V_80 ) ) ;
F_21 ( V_45 , F_27 ( V_81 ) ) ;
}
F_21 ( V_45 , F_24 ( V_86 ) ) ;
F_21 ( V_45 , F_37 ( 0 ) ) ;
}
static bool F_38 ( struct V_44 * V_45 ,
struct V_87 * V_88 ,
bool V_89 )
{
T_2 V_80 = V_88 -> V_71 ;
V_6 V_90 = V_89 ? 0 : 1 ;
F_21 ( V_45 , F_24 ( V_91 ) |
F_39 ( V_90 ) ) ;
F_21 ( V_45 , F_26 ( V_80 ) & 0xfffffff8 ) ;
F_21 ( V_45 , F_27 ( V_80 ) ) ;
return true ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_44 * V_92 = & V_2 -> V_25 [ 0 ] . V_45 ;
struct V_44 * V_93 = & V_2 -> V_25 [ 1 ] . V_45 ;
V_6 V_94 , V_95 ;
int V_17 ;
if ( ( V_2 -> V_96 . V_97 == V_92 ) ||
( V_2 -> V_96 . V_97 == V_93 ) )
F_41 ( V_2 , V_2 -> V_98 . V_99 ) ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_94 = F_15 ( V_100 + V_54 [ V_17 ] ) ;
V_94 = F_31 ( V_94 , V_101 , V_102 , 0 ) ;
F_18 ( V_100 + V_54 [ V_17 ] , V_94 ) ;
V_95 = F_15 ( V_103 + V_54 [ V_17 ] ) ;
V_95 = F_31 ( V_95 , V_104 , V_105 , 0 ) ;
F_18 ( V_103 + V_54 [ V_17 ] , V_95 ) ;
}
V_92 -> V_106 = false ;
V_93 -> V_106 = false ;
}
static void F_42 ( struct V_1 * V_2 )
{
}
static void F_43 ( struct V_1 * V_2 , bool V_107 )
{
V_6 V_108 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_108 = F_15 ( V_109 + V_54 [ V_17 ] ) ;
if ( V_107 )
V_108 = F_31 ( V_108 , V_110 ,
V_111 , 1 ) ;
else
V_108 = F_31 ( V_108 , V_110 ,
V_111 , 0 ) ;
F_18 ( V_109 + V_54 [ V_17 ] , V_108 ) ;
}
}
static void F_44 ( struct V_1 * V_2 , bool V_107 )
{
V_6 V_108 ;
int V_17 ;
if ( V_107 == false ) {
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
}
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_108 = F_15 ( V_112 + V_54 [ V_17 ] ) ;
if ( V_107 )
V_108 = F_31 ( V_108 , V_113 , V_114 , 0 ) ;
else
V_108 = F_31 ( V_108 , V_113 , V_114 , 1 ) ;
F_18 ( V_112 + V_54 [ V_17 ] , V_108 ) ;
}
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
V_6 V_94 , V_95 ;
V_6 V_115 ;
V_6 V_116 ;
V_6 V_117 ;
int V_17 , V_118 , V_119 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_45 = & V_2 -> V_25 [ V_17 ] . V_45 ;
V_116 = ( V_45 -> V_48 * 4 ) ;
F_46 ( & V_2 -> V_120 ) ;
for ( V_118 = 0 ; V_118 < 16 ; V_118 ++ ) {
F_47 ( V_2 , 0 , 0 , 0 , V_118 ) ;
F_18 ( V_121 + V_54 [ V_17 ] , 0 ) ;
F_18 ( V_122 + V_54 [ V_17 ] , 0 ) ;
}
F_47 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_48 ( & V_2 -> V_120 ) ;
F_18 ( V_123 + V_54 [ V_17 ] , 0 ) ;
V_115 = F_49 ( V_45 -> V_124 / 4 ) ;
V_94 = F_15 ( V_100 + V_54 [ V_17 ] ) ;
V_94 = F_31 ( V_94 , V_101 , V_125 , V_115 ) ;
#ifdef F_50
V_94 = F_31 ( V_94 , V_101 , V_126 , 1 ) ;
V_94 = F_31 ( V_94 , V_101 ,
V_127 , 1 ) ;
#endif
F_18 ( V_100 + V_54 [ V_17 ] , V_94 ) ;
F_18 ( V_128 + V_54 [ V_17 ] , 0 ) ;
F_18 ( V_53 + V_54 [ V_17 ] , 0 ) ;
F_18 ( V_129 + V_54 [ V_17 ] ,
F_27 ( V_2 -> V_47 . V_71 + V_116 ) & 0xFFFFFFFF ) ;
F_18 ( V_130 + V_54 [ V_17 ] ,
F_26 ( V_2 -> V_47 . V_71 + V_116 ) & 0xFFFFFFFC ) ;
V_94 = F_31 ( V_94 , V_101 , V_131 , 1 ) ;
F_18 ( V_132 + V_54 [ V_17 ] , V_45 -> V_71 >> 8 ) ;
F_18 ( V_133 + V_54 [ V_17 ] , V_45 -> V_71 >> 40 ) ;
V_45 -> V_49 = 0 ;
F_18 ( V_53 + V_54 [ V_17 ] , V_45 -> V_49 << 2 ) ;
V_117 = F_15 ( V_134 + V_54 [ V_17 ] ) ;
if ( V_45 -> V_50 ) {
V_117 = F_31 ( V_117 , V_135 ,
V_136 , V_45 -> V_55 ) ;
V_117 = F_31 ( V_117 , V_135 , V_137 , 1 ) ;
} else {
V_117 = F_31 ( V_117 , V_135 , V_137 , 0 ) ;
}
F_18 ( V_134 + V_54 [ V_17 ] , V_117 ) ;
V_94 = F_31 ( V_94 , V_101 , V_102 , 1 ) ;
F_18 ( V_100 + V_54 [ V_17 ] , V_94 ) ;
V_95 = F_15 ( V_103 + V_54 [ V_17 ] ) ;
V_95 = F_31 ( V_95 , V_104 , V_105 , 1 ) ;
#ifdef F_50
V_95 = F_31 ( V_95 , V_104 , V_138 , 1 ) ;
#endif
F_18 ( V_103 + V_54 [ V_17 ] , V_95 ) ;
V_45 -> V_106 = true ;
V_119 = F_51 ( V_45 ) ;
if ( V_119 ) {
V_45 -> V_106 = false ;
return V_119 ;
}
if ( V_2 -> V_96 . V_97 == V_45 )
F_41 ( V_2 , V_2 -> V_98 . V_139 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
const struct V_22 * V_23 ;
const T_3 * V_140 ;
V_6 V_40 ;
int V_17 , V_118 ;
if ( ! V_2 -> V_25 [ 0 ] . V_26 || ! V_2 -> V_25 [ 1 ] . V_26 )
return - V_141 ;
F_44 ( V_2 , false ) ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_23 = ( const struct V_22 * ) V_2 -> V_25 [ V_17 ] . V_26 -> V_29 ;
F_54 ( & V_23 -> V_21 ) ;
V_40 = F_9 ( V_23 -> V_21 . V_41 ) / 4 ;
V_140 = ( const T_3 * )
( V_2 -> V_25 [ V_17 ] . V_26 -> V_29 +
F_9 ( V_23 -> V_21 . V_142 ) ) ;
F_18 ( V_143 + V_54 [ V_17 ] , 0 ) ;
for ( V_118 = 0 ; V_118 < V_40 ; V_118 ++ )
F_18 ( V_144 + V_54 [ V_17 ] , F_55 ( V_140 ++ ) ) ;
F_18 ( V_143 + V_54 [ V_17 ] , V_2 -> V_25 [ V_17 ] . V_30 ) ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_119 ;
if ( ! V_2 -> V_35 . V_36 ) {
V_119 = F_53 ( V_2 ) ;
if ( V_119 )
return V_119 ;
} else {
V_119 = V_2 -> V_145 . V_146 -> V_147 ( V_2 ,
V_38 ) ;
if ( V_119 )
return - V_141 ;
V_119 = V_2 -> V_145 . V_146 -> V_147 ( V_2 ,
V_148 ) ;
if ( V_119 )
return - V_141 ;
}
F_44 ( V_2 , true ) ;
F_43 ( V_2 , true ) ;
V_119 = F_45 ( V_2 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_52 ( V_2 ) ;
if ( V_119 )
return V_119 ;
return 0 ;
}
static int F_57 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
unsigned V_17 ;
unsigned V_149 ;
int V_119 ;
V_6 V_150 ;
T_2 V_71 ;
V_119 = F_58 ( V_2 , & V_149 ) ;
if ( V_119 ) {
F_59 ( V_2 -> V_27 , L_8 , V_119 ) ;
return V_119 ;
}
V_71 = V_2 -> V_47 . V_71 + ( V_149 * 4 ) ;
V_150 = 0xCAFEDEAD ;
V_2 -> V_47 . V_47 [ V_149 ] = F_60 ( V_150 ) ;
V_119 = F_61 ( V_45 , 5 ) ;
if ( V_119 ) {
F_62 ( L_9 , V_45 -> V_64 , V_119 ) ;
F_63 ( V_2 , V_149 ) ;
return V_119 ;
}
F_21 ( V_45 , F_24 ( V_67 ) |
F_25 ( V_68 ) ) ;
F_21 ( V_45 , F_26 ( V_71 ) ) ;
F_21 ( V_45 , F_27 ( V_71 ) ) ;
F_21 ( V_45 , F_28 ( 1 ) ) ;
F_21 ( V_45 , 0xDEADBEEF ) ;
F_64 ( V_45 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_151 ; V_17 ++ ) {
V_150 = F_9 ( V_2 -> V_47 . V_47 [ V_149 ] ) ;
if ( V_150 == 0xDEADBEEF )
break;
F_65 ( 1 ) ;
}
if ( V_17 < V_2 -> V_151 ) {
F_66 ( L_10 , V_45 -> V_64 , V_17 ) ;
} else {
F_62 ( L_11 ,
V_45 -> V_64 , V_150 ) ;
V_119 = - V_141 ;
}
F_63 ( V_2 , V_149 ) ;
return V_119 ;
}
static int F_67 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_59 V_60 ;
struct V_152 * V_153 = NULL ;
unsigned V_17 ;
unsigned V_149 ;
int V_119 ;
V_6 V_150 = 0 ;
T_2 V_71 ;
V_119 = F_58 ( V_2 , & V_149 ) ;
if ( V_119 ) {
F_59 ( V_2 -> V_27 , L_8 , V_119 ) ;
return V_119 ;
}
V_71 = V_2 -> V_47 . V_71 + ( V_149 * 4 ) ;
V_150 = 0xCAFEDEAD ;
V_2 -> V_47 . V_47 [ V_149 ] = F_60 ( V_150 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_119 = F_68 ( V_45 , NULL , 256 , & V_60 ) ;
if ( V_119 ) {
F_62 ( L_12 , V_119 ) ;
goto V_154;
}
V_60 . V_155 [ 0 ] = F_24 ( V_67 ) |
F_25 ( V_68 ) ;
V_60 . V_155 [ 1 ] = F_26 ( V_71 ) ;
V_60 . V_155 [ 2 ] = F_27 ( V_71 ) ;
V_60 . V_155 [ 3 ] = F_28 ( 1 ) ;
V_60 . V_155 [ 4 ] = 0xDEADBEEF ;
V_60 . V_155 [ 5 ] = F_69 ( V_156 ) ;
V_60 . V_155 [ 6 ] = F_69 ( V_156 ) ;
V_60 . V_155 [ 7 ] = F_69 ( V_156 ) ;
V_60 . V_72 = 8 ;
V_119 = F_70 ( V_2 , V_45 , & V_60 , 1 , NULL ,
V_157 ,
& V_153 ) ;
if ( V_119 )
goto V_158;
V_119 = F_71 ( V_153 , false ) ;
if ( V_119 ) {
F_62 ( L_13 , V_119 ) ;
goto V_158;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_151 ; V_17 ++ ) {
V_150 = F_9 ( V_2 -> V_47 . V_47 [ V_149 ] ) ;
if ( V_150 == 0xDEADBEEF )
break;
F_65 ( 1 ) ;
}
if ( V_17 < V_2 -> V_151 ) {
F_66 ( L_14 ,
V_45 -> V_64 , V_17 ) ;
goto V_158;
} else {
F_62 ( L_15 , V_150 ) ;
V_119 = - V_141 ;
}
V_158:
F_72 ( V_153 ) ;
F_73 ( V_2 , & V_60 ) ;
V_154:
F_63 ( V_2 , V_149 ) ;
return V_119 ;
}
static void F_74 ( struct V_59 * V_60 ,
T_4 V_159 , T_4 V_160 ,
unsigned V_56 )
{
while ( V_56 ) {
unsigned V_161 = V_56 * 8 ;
if ( V_161 > 0x1FFFF8 )
V_161 = 0x1FFFF8 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_24 ( V_162 ) |
F_25 ( V_163 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_161 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = 0 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_26 ( V_160 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_160 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_26 ( V_159 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_159 ) ;
V_159 += V_161 ;
V_160 += V_161 ;
V_56 -= V_161 / 8 ;
}
}
static void F_75 ( struct V_59 * V_60 ,
T_4 V_159 ,
T_4 V_80 , unsigned V_56 ,
T_1 V_164 , T_1 V_82 )
{
T_4 V_165 ;
unsigned V_166 ;
while ( V_56 ) {
V_166 = V_56 * 2 ;
if ( V_166 > 0xFFFFE )
V_166 = 0xFFFFE ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_24 ( V_67 ) |
F_25 ( V_163 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_159 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_159 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_166 ;
for (; V_166 > 0 ; V_166 -= 2 , -- V_56 , V_159 += 8 ) {
if ( V_82 & V_167 ) {
V_165 = F_76 ( V_60 -> V_45 -> V_2 , V_80 ) ;
V_165 &= 0xFFFFFFFFFFFFF000ULL ;
} else if ( V_82 & V_168 ) {
V_165 = V_80 ;
} else {
V_165 = 0 ;
}
V_80 += V_164 ;
V_165 |= V_82 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_165 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_165 ) ;
}
}
}
static void F_77 ( struct V_59 * V_60 ,
T_4 V_159 ,
T_4 V_80 , unsigned V_56 ,
T_1 V_164 , T_1 V_82 )
{
T_4 V_165 ;
unsigned V_166 ;
while ( V_56 ) {
V_166 = V_56 ;
if ( V_166 > 0x7FFFF )
V_166 = 0x7FFFF ;
if ( V_82 & V_168 )
V_165 = V_80 ;
else
V_165 = 0 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_24 ( V_169 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_159 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_159 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_82 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = 0 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_165 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_165 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_164 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = 0 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_166 ;
V_159 += V_166 * 8 ;
V_80 += V_166 * V_164 ;
V_56 -= V_166 ;
}
}
static void F_78 ( struct V_59 * V_60 )
{
struct V_57 * V_25 = F_20 ( V_60 -> V_45 ) ;
V_6 V_170 ;
int V_17 ;
V_170 = ( 8 - ( V_60 -> V_72 & 0x7 ) ) % 8 ;
for ( V_17 = 0 ; V_17 < V_170 ; V_17 ++ )
if ( V_25 && V_25 -> V_34 && ( V_17 == 0 ) )
V_60 -> V_155 [ V_60 -> V_72 ++ ] =
F_24 ( V_156 ) |
F_22 ( V_170 - 1 ) ;
else
V_60 -> V_155 [ V_60 -> V_72 ++ ] =
F_24 ( V_156 ) ;
}
static void F_79 ( struct V_44 * V_45 ,
unsigned V_171 , T_4 V_172 )
{
F_21 ( V_45 , F_24 ( V_173 ) |
F_80 ( 0xf ) ) ;
if ( V_171 < 8 ) {
F_21 ( V_45 , ( V_174 + V_171 ) ) ;
} else {
F_21 ( V_45 , ( V_175 + V_171 - 8 ) ) ;
}
F_21 ( V_45 , V_172 >> 12 ) ;
F_21 ( V_45 , F_24 ( V_173 ) |
F_80 ( 0xf ) ) ;
F_21 ( V_45 , V_176 ) ;
F_21 ( V_45 , 1 << V_171 ) ;
F_21 ( V_45 , F_24 ( V_77 ) |
F_32 ( 0 ) |
F_33 ( 0 ) ) ;
F_21 ( V_45 , V_176 << 2 ) ;
F_21 ( V_45 , 0 ) ;
F_21 ( V_45 , 0 ) ;
F_21 ( V_45 , 0 ) ;
F_21 ( V_45 , F_34 ( 0xfff ) |
F_35 ( 10 ) ) ;
}
static int F_81 ( void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_86 ( void * V_177 )
{
struct V_44 * V_45 ;
int V_119 ;
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
V_119 = F_87 ( V_2 , 224 , & V_2 -> V_178 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_87 ( V_2 , 241 , & V_2 -> V_179 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_87 ( V_2 , 247 , & V_2 -> V_179 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_4 ( V_2 ) ;
if ( V_119 ) {
F_62 ( L_16 ) ;
return V_119 ;
}
V_45 = & V_2 -> V_25 [ 0 ] . V_45 ;
V_45 -> V_180 = NULL ;
V_45 -> V_50 = true ;
V_45 -> V_55 = V_181 ;
V_45 = & V_2 -> V_25 [ 1 ] . V_45 ;
V_45 -> V_180 = NULL ;
V_45 -> V_50 = true ;
V_45 -> V_55 = V_182 ;
V_45 = & V_2 -> V_25 [ 0 ] . V_45 ;
sprintf ( V_45 -> V_183 , L_17 ) ;
V_119 = F_88 ( V_2 , V_45 , 256 * 1024 ,
F_69 ( V_156 ) , 0xf ,
& V_2 -> V_178 , V_184 ,
V_185 ) ;
if ( V_119 )
return V_119 ;
V_45 = & V_2 -> V_25 [ 1 ] . V_45 ;
sprintf ( V_45 -> V_183 , L_18 ) ;
V_119 = F_88 ( V_2 , V_45 , 256 * 1024 ,
F_69 ( V_156 ) , 0xf ,
& V_2 -> V_178 , V_186 ,
V_185 ) ;
if ( V_119 )
return V_119 ;
return V_119 ;
}
static int F_89 ( void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
F_90 ( & V_2 -> V_25 [ 0 ] . V_45 ) ;
F_90 ( & V_2 -> V_25 [ 1 ] . V_45 ) ;
return 0 ;
}
static int F_91 ( void * V_177 )
{
int V_119 ;
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
F_1 ( V_2 ) ;
V_119 = F_56 ( V_2 ) ;
if ( V_119 )
return V_119 ;
return V_119 ;
}
static int F_92 ( void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
F_43 ( V_2 , false ) ;
F_44 ( V_2 , false ) ;
return 0 ;
}
static int F_93 ( void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
return F_92 ( V_2 ) ;
}
static int F_94 ( void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
return F_91 ( V_2 ) ;
}
static bool F_95 ( void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
V_6 V_150 = F_15 ( V_187 ) ;
if ( V_150 & ( V_188 |
V_189 ) )
return false ;
return true ;
}
static int F_96 ( void * V_177 )
{
unsigned V_17 ;
V_6 V_150 ;
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_151 ; V_17 ++ ) {
V_150 = F_15 ( V_187 ) & ( V_188 |
V_189 ) ;
if ( ! V_150 )
return 0 ;
F_97 ( 1 ) ;
}
return - V_190 ;
}
static void F_98 ( void * V_177 )
{
int V_17 , V_118 ;
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
F_99 ( V_2 -> V_27 , L_19 ) ;
F_99 ( V_2 -> V_27 , L_20 ,
F_15 ( V_187 ) ) ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
F_99 ( V_2 -> V_27 , L_21 ,
V_17 , F_15 ( V_191 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_22 ,
V_17 , F_15 ( V_112 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_23 ,
V_17 , F_15 ( V_109 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_24 ,
V_17 , F_15 ( V_123 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_25 ,
V_17 , F_15 ( V_103 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_26 ,
V_17 , F_15 ( V_100 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_27 ,
V_17 , F_15 ( V_128 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_28 ,
V_17 , F_15 ( V_53 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_29 ,
V_17 , F_15 ( V_129 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_30 ,
V_17 , F_15 ( V_130 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_31 ,
V_17 , F_15 ( V_132 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_32 ,
V_17 , F_15 ( V_133 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_33 ,
V_17 , F_15 ( V_134 + V_54 [ V_17 ] ) ) ;
F_46 ( & V_2 -> V_120 ) ;
for ( V_118 = 0 ; V_118 < 16 ; V_118 ++ ) {
F_47 ( V_2 , 0 , 0 , 0 , V_118 ) ;
F_99 ( V_2 -> V_27 , L_34 , V_118 ) ;
F_99 ( V_2 -> V_27 , L_35 ,
V_17 , F_15 ( V_121 + V_54 [ V_17 ] ) ) ;
F_99 ( V_2 -> V_27 , L_36 ,
V_17 , F_15 ( V_122 + V_54 [ V_17 ] ) ) ;
}
F_47 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_48 ( & V_2 -> V_120 ) ;
}
}
static int F_100 ( void * V_177 )
{
V_6 V_192 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
V_6 V_150 = F_15 ( V_187 ) ;
if ( V_150 & V_188 ) {
V_150 = F_15 ( V_112 + V_193 ) ;
V_150 = F_31 ( V_150 , V_113 , V_114 , 0 ) ;
F_18 ( V_112 + V_193 , V_150 ) ;
V_192 |= V_194 ;
}
if ( V_150 & V_189 ) {
V_150 = F_15 ( V_112 + V_195 ) ;
V_150 = F_31 ( V_150 , V_113 , V_114 , 0 ) ;
F_18 ( V_112 + V_195 , V_150 ) ;
V_192 |= V_196 ;
}
if ( V_192 ) {
F_98 ( ( void * ) V_2 ) ;
V_150 = F_15 ( V_197 ) ;
V_150 |= V_192 ;
F_99 ( V_2 -> V_27 , L_37 , V_150 ) ;
F_18 ( V_197 , V_150 ) ;
V_150 = F_15 ( V_197 ) ;
F_97 ( 50 ) ;
V_150 &= ~ V_192 ;
F_18 ( V_197 , V_150 ) ;
V_150 = F_15 ( V_197 ) ;
F_97 ( 50 ) ;
F_98 ( ( void * ) V_2 ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_198 * V_199 ,
unsigned type ,
enum V_200 V_201 )
{
V_6 V_202 ;
switch ( type ) {
case V_184 :
switch ( V_201 ) {
case V_203 :
V_202 = F_15 ( V_109 + V_193 ) ;
V_202 = F_31 ( V_202 , V_110 , V_204 , 0 ) ;
F_18 ( V_109 + V_193 , V_202 ) ;
break;
case V_205 :
V_202 = F_15 ( V_109 + V_193 ) ;
V_202 = F_31 ( V_202 , V_110 , V_204 , 1 ) ;
F_18 ( V_109 + V_193 , V_202 ) ;
break;
default:
break;
}
break;
case V_186 :
switch ( V_201 ) {
case V_203 :
V_202 = F_15 ( V_109 + V_195 ) ;
V_202 = F_31 ( V_202 , V_110 , V_204 , 0 ) ;
F_18 ( V_109 + V_195 , V_202 ) ;
break;
case V_205 :
V_202 = F_15 ( V_109 + V_195 ) ;
V_202 = F_31 ( V_202 , V_110 , V_204 , 1 ) ;
F_18 ( V_109 + V_195 , V_202 ) ;
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
static int F_102 ( struct V_1 * V_2 ,
struct V_198 * V_199 ,
struct V_206 * V_207 )
{
T_5 V_208 , V_209 ;
V_208 = ( V_207 -> V_210 & 0x3 ) >> 0 ;
V_209 = ( V_207 -> V_210 & 0xc ) >> 2 ;
F_5 ( L_38 ) ;
switch ( V_208 ) {
case 0 :
switch ( V_209 ) {
case 0 :
F_103 ( & V_2 -> V_25 [ 0 ] . V_45 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_209 ) {
case 0 :
F_103 ( & V_2 -> V_25 [ 1 ] . V_45 ) ;
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
static int F_104 ( struct V_1 * V_2 ,
struct V_198 * V_199 ,
struct V_206 * V_207 )
{
F_62 ( L_39 ) ;
F_105 ( & V_2 -> V_211 ) ;
return 0 ;
}
static int F_106 ( void * V_177 ,
enum V_212 V_201 )
{
return 0 ;
}
static int F_107 ( void * V_177 ,
enum V_213 V_201 )
{
return 0 ;
}
static bool F_108 ( struct V_44 * V_45 )
{
if ( F_95 ( V_45 -> V_2 ) ) {
F_109 ( V_45 ) ;
return false ;
}
return F_110 ( V_45 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
V_2 -> V_25 [ 0 ] . V_45 . V_214 = & V_215 ;
V_2 -> V_25 [ 1 ] . V_45 . V_214 = & V_215 ;
}
static void F_85 ( struct V_1 * V_2 )
{
V_2 -> V_178 . V_216 = V_217 ;
V_2 -> V_178 . V_214 = & V_218 ;
V_2 -> V_179 . V_214 = & V_219 ;
}
static void F_111 ( struct V_59 * V_60 ,
T_4 V_220 ,
T_4 V_221 ,
T_1 V_222 )
{
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_24 ( V_162 ) |
F_25 ( V_163 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_222 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = 0 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_26 ( V_220 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_220 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_26 ( V_221 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_221 ) ;
}
static void F_112 ( struct V_59 * V_60 ,
T_1 V_223 ,
T_4 V_221 ,
T_1 V_222 )
{
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_24 ( V_224 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_26 ( V_221 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = F_27 ( V_221 ) ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_223 ;
V_60 -> V_155 [ V_60 -> V_72 ++ ] = V_222 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 . V_225 == NULL ) {
V_2 -> V_96 . V_225 = & V_226 ;
V_2 -> V_96 . V_97 = & V_2 -> V_25 [ 0 ] . V_45 ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_227 . V_228 == NULL ) {
V_2 -> V_227 . V_228 = & V_229 ;
V_2 -> V_227 . V_230 = & V_2 -> V_25 [ 0 ] . V_45 ;
V_2 -> V_227 . V_230 -> V_231 = true ;
}
}
