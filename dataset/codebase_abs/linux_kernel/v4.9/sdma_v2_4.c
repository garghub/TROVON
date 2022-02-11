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
return V_40 -> V_2 -> V_41 . V_41 [ V_40 -> V_42 ] >> 2 ;
}
static T_1 F_15 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
int V_43 = ( V_40 == & V_40 -> V_2 -> V_9 . V_11 [ 0 ] . V_40 ) ? 0 : 1 ;
V_6 V_44 = F_16 ( V_45 + V_46 [ V_43 ] ) >> 2 ;
return V_44 ;
}
static void F_17 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
int V_43 = ( V_40 == & V_40 -> V_2 -> V_9 . V_11 [ 0 ] . V_40 ) ? 0 : 1 ;
F_18 ( V_45 + V_46 [ V_43 ] , V_40 -> V_44 << 2 ) ;
}
static void F_19 ( struct V_39 * V_40 , T_1 V_47 )
{
struct V_48 * V_9 = F_20 ( V_40 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_47 ; V_8 ++ )
if ( V_9 && V_9 -> V_29 && ( V_8 == 0 ) )
F_21 ( V_40 , V_40 -> V_49 |
F_22 ( V_47 - 1 ) ) ;
else
F_21 ( V_40 , V_40 -> V_49 ) ;
}
static void F_23 ( struct V_39 * V_40 ,
struct V_50 * V_51 ,
unsigned V_52 , bool V_53 )
{
V_6 V_54 = V_52 & 0xf ;
F_19 ( V_40 , ( 10 - ( V_40 -> V_44 & 7 ) ) % 8 ) ;
F_21 ( V_40 , F_24 ( V_55 ) |
F_25 ( V_54 ) ) ;
F_21 ( V_40 , F_26 ( V_51 -> V_56 ) & 0xffffffe0 ) ;
F_21 ( V_40 , F_27 ( V_51 -> V_56 ) ) ;
F_21 ( V_40 , V_51 -> V_57 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
}
static void F_28 ( struct V_39 * V_40 )
{
V_6 V_58 = 0 ;
if ( V_40 == & V_40 -> V_2 -> V_9 . V_11 [ 0 ] . V_40 )
V_58 = F_29 ( V_58 , V_59 , V_60 , 1 ) ;
else
V_58 = F_29 ( V_58 , V_59 , V_61 , 1 ) ;
F_21 ( V_40 , F_24 ( V_62 ) |
F_30 ( 1 ) |
F_31 ( 3 ) ) ;
F_21 ( V_40 , V_63 << 2 ) ;
F_21 ( V_40 , V_64 << 2 ) ;
F_21 ( V_40 , V_58 ) ;
F_21 ( V_40 , V_58 ) ;
F_21 ( V_40 , F_32 ( 0xfff ) |
F_33 ( 10 ) ) ;
}
static void F_34 ( struct V_39 * V_40 )
{
F_21 ( V_40 , F_24 ( V_65 ) |
F_35 ( 0xf ) ) ;
F_21 ( V_40 , V_66 ) ;
F_21 ( V_40 , 1 ) ;
}
static void F_36 ( struct V_39 * V_40 , T_2 V_67 , T_2 V_68 ,
unsigned V_69 )
{
bool V_70 = V_69 & V_71 ;
F_21 ( V_40 , F_24 ( V_72 ) ) ;
F_21 ( V_40 , F_26 ( V_67 ) ) ;
F_21 ( V_40 , F_27 ( V_67 ) ) ;
F_21 ( V_40 , F_26 ( V_68 ) ) ;
if ( V_70 ) {
V_67 += 4 ;
F_21 ( V_40 , F_24 ( V_72 ) ) ;
F_21 ( V_40 , F_26 ( V_67 ) ) ;
F_21 ( V_40 , F_27 ( V_67 ) ) ;
F_21 ( V_40 , F_27 ( V_68 ) ) ;
}
F_21 ( V_40 , F_24 ( V_73 ) ) ;
F_21 ( V_40 , F_37 ( 0 ) ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_39 * V_74 = & V_2 -> V_9 . V_11 [ 0 ] . V_40 ;
struct V_39 * V_75 = & V_2 -> V_9 . V_11 [ 1 ] . V_40 ;
V_6 V_76 , V_77 ;
int V_8 ;
if ( ( V_2 -> V_78 . V_79 == V_74 ) ||
( V_2 -> V_78 . V_79 == V_75 ) )
F_39 ( V_2 , V_2 -> V_80 . V_81 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_76 = F_16 ( V_82 + V_46 [ V_8 ] ) ;
V_76 = F_29 ( V_76 , V_83 , V_84 , 0 ) ;
F_18 ( V_82 + V_46 [ V_8 ] , V_76 ) ;
V_77 = F_16 ( V_85 + V_46 [ V_8 ] ) ;
V_77 = F_29 ( V_77 , V_86 , V_87 , 0 ) ;
F_18 ( V_85 + V_46 [ V_8 ] , V_77 ) ;
}
V_74 -> V_88 = false ;
V_75 -> V_88 = false ;
}
static void F_40 ( struct V_1 * V_2 )
{
}
static void F_41 ( struct V_1 * V_2 , bool V_89 )
{
V_6 V_90 ;
int V_8 ;
if ( ! V_89 ) {
F_38 ( V_2 ) ;
F_40 ( V_2 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_90 = F_16 ( V_91 + V_46 [ V_8 ] ) ;
if ( V_89 )
V_90 = F_29 ( V_90 , V_92 , V_93 , 0 ) ;
else
V_90 = F_29 ( V_90 , V_92 , V_93 , 1 ) ;
F_18 ( V_91 + V_46 [ V_8 ] , V_90 ) ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
V_6 V_76 , V_77 ;
V_6 V_94 ;
V_6 V_95 ;
int V_8 , V_96 , V_97 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_95 = ( V_40 -> V_42 * 4 ) ;
F_43 ( & V_2 -> V_98 ) ;
for ( V_96 = 0 ; V_96 < 16 ; V_96 ++ ) {
F_44 ( V_2 , 0 , 0 , 0 , V_96 ) ;
F_18 ( V_99 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_100 + V_46 [ V_8 ] , 0 ) ;
}
F_44 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_45 ( & V_2 -> V_98 ) ;
F_18 ( V_101 + V_46 [ V_8 ] ,
V_2 -> V_102 . V_103 . V_104 & 0x70 ) ;
F_18 ( V_105 + V_46 [ V_8 ] , 0 ) ;
V_94 = F_46 ( V_40 -> V_106 / 4 ) ;
V_76 = F_16 ( V_82 + V_46 [ V_8 ] ) ;
V_76 = F_29 ( V_76 , V_83 , V_107 , V_94 ) ;
#ifdef F_47
V_76 = F_29 ( V_76 , V_83 , V_108 , 1 ) ;
V_76 = F_29 ( V_76 , V_83 ,
V_109 , 1 ) ;
#endif
F_18 ( V_82 + V_46 [ V_8 ] , V_76 ) ;
F_18 ( V_110 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_45 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_111 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_112 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_113 + V_46 [ V_8 ] ,
F_27 ( V_2 -> V_41 . V_56 + V_95 ) & 0xFFFFFFFF ) ;
F_18 ( V_114 + V_46 [ V_8 ] ,
F_26 ( V_2 -> V_41 . V_56 + V_95 ) & 0xFFFFFFFC ) ;
V_76 = F_29 ( V_76 , V_83 , V_115 , 1 ) ;
F_18 ( V_116 + V_46 [ V_8 ] , V_40 -> V_56 >> 8 ) ;
F_18 ( V_117 + V_46 [ V_8 ] , V_40 -> V_56 >> 40 ) ;
V_40 -> V_44 = 0 ;
F_18 ( V_45 + V_46 [ V_8 ] , V_40 -> V_44 << 2 ) ;
V_76 = F_29 ( V_76 , V_83 , V_84 , 1 ) ;
F_18 ( V_82 + V_46 [ V_8 ] , V_76 ) ;
V_77 = F_16 ( V_85 + V_46 [ V_8 ] ) ;
V_77 = F_29 ( V_77 , V_86 , V_87 , 1 ) ;
#ifdef F_47
V_77 = F_29 ( V_77 , V_86 , V_118 , 1 ) ;
#endif
F_18 ( V_85 + V_46 [ V_8 ] , V_77 ) ;
V_40 -> V_88 = true ;
}
F_41 ( V_2 , true ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_97 = F_48 ( V_40 ) ;
if ( V_97 ) {
V_40 -> V_88 = false ;
return V_97 ;
}
if ( V_2 -> V_78 . V_79 == V_40 )
F_39 ( V_2 , V_2 -> V_80 . V_119 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
const struct V_20 * V_21 ;
const T_3 * V_120 ;
V_6 V_35 ;
int V_8 , V_96 ;
F_41 ( V_2 , false ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
if ( ! V_2 -> V_9 . V_11 [ V_8 ] . V_12 )
return - V_121 ;
V_21 = ( const struct V_20 * ) V_2 -> V_9 . V_11 [ V_8 ] . V_12 -> V_24 ;
F_51 ( & V_21 -> V_19 ) ;
V_35 = F_11 ( V_21 -> V_19 . V_36 ) / 4 ;
V_120 = ( const T_3 * )
( V_2 -> V_9 . V_11 [ V_8 ] . V_12 -> V_24 +
F_11 ( V_21 -> V_19 . V_122 ) ) ;
F_18 ( V_123 + V_46 [ V_8 ] , 0 ) ;
for ( V_96 = 0 ; V_96 < V_35 ; V_96 ++ )
F_18 ( V_124 + V_46 [ V_8 ] , F_52 ( V_120 ++ ) ) ;
F_18 ( V_123 + V_46 [ V_8 ] , V_2 -> V_9 . V_11 [ V_8 ] . V_25 ) ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_97 ;
if ( ! V_2 -> V_125 ) {
if ( ! V_2 -> V_30 . V_31 ) {
V_97 = F_50 ( V_2 ) ;
if ( V_97 )
return V_97 ;
} else {
V_97 = V_2 -> V_126 . V_127 -> V_128 ( V_2 ,
V_33 ) ;
if ( V_97 )
return - V_121 ;
V_97 = V_2 -> V_126 . V_127 -> V_128 ( V_2 ,
V_129 ) ;
if ( V_97 )
return - V_121 ;
}
}
F_41 ( V_2 , false ) ;
V_97 = F_42 ( V_2 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_49 ( V_2 ) ;
if ( V_97 )
return V_97 ;
return 0 ;
}
static int F_54 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
unsigned V_8 ;
unsigned V_130 ;
int V_97 ;
V_6 V_131 ;
T_2 V_56 ;
V_97 = F_55 ( V_2 , & V_130 ) ;
if ( V_97 ) {
F_56 ( V_2 -> V_22 , L_6 , V_97 ) ;
return V_97 ;
}
V_56 = V_2 -> V_41 . V_56 + ( V_130 * 4 ) ;
V_131 = 0xCAFEDEAD ;
V_2 -> V_41 . V_41 [ V_130 ] = F_57 ( V_131 ) ;
V_97 = F_58 ( V_40 , 5 ) ;
if ( V_97 ) {
F_59 ( L_7 , V_40 -> V_132 , V_97 ) ;
F_60 ( V_2 , V_130 ) ;
return V_97 ;
}
F_21 ( V_40 , F_24 ( V_133 ) |
F_61 ( V_134 ) ) ;
F_21 ( V_40 , F_26 ( V_56 ) ) ;
F_21 ( V_40 , F_27 ( V_56 ) ) ;
F_21 ( V_40 , F_62 ( 1 ) ) ;
F_21 ( V_40 , 0xDEADBEEF ) ;
F_63 ( V_40 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_135 ; V_8 ++ ) {
V_131 = F_11 ( V_2 -> V_41 . V_41 [ V_130 ] ) ;
if ( V_131 == 0xDEADBEEF )
break;
F_64 ( 1 ) ;
}
if ( V_8 < V_2 -> V_135 ) {
F_65 ( L_8 , V_40 -> V_132 , V_8 ) ;
} else {
F_59 ( L_9 ,
V_40 -> V_132 , V_131 ) ;
V_97 = - V_121 ;
}
F_60 ( V_2 , V_130 ) ;
return V_97 ;
}
static int F_66 ( struct V_39 * V_40 , long V_136 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_50 V_51 ;
struct V_137 * V_138 = NULL ;
unsigned V_130 ;
V_6 V_131 = 0 ;
T_2 V_56 ;
long V_97 ;
V_97 = F_55 ( V_2 , & V_130 ) ;
if ( V_97 ) {
F_56 ( V_2 -> V_22 , L_10 , V_97 ) ;
return V_97 ;
}
V_56 = V_2 -> V_41 . V_56 + ( V_130 * 4 ) ;
V_131 = 0xCAFEDEAD ;
V_2 -> V_41 . V_41 [ V_130 ] = F_57 ( V_131 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_97 = F_67 ( V_2 , NULL , 256 , & V_51 ) ;
if ( V_97 ) {
F_59 ( L_11 , V_97 ) ;
goto V_139;
}
V_51 . V_140 [ 0 ] = F_24 ( V_133 ) |
F_61 ( V_134 ) ;
V_51 . V_140 [ 1 ] = F_26 ( V_56 ) ;
V_51 . V_140 [ 2 ] = F_27 ( V_56 ) ;
V_51 . V_140 [ 3 ] = F_62 ( 1 ) ;
V_51 . V_140 [ 4 ] = 0xDEADBEEF ;
V_51 . V_140 [ 5 ] = F_24 ( V_141 ) ;
V_51 . V_140 [ 6 ] = F_24 ( V_141 ) ;
V_51 . V_140 [ 7 ] = F_24 ( V_141 ) ;
V_51 . V_57 = 8 ;
V_97 = F_68 ( V_40 , 1 , & V_51 , NULL , NULL , & V_138 ) ;
if ( V_97 )
goto V_142;
V_97 = F_69 ( V_138 , false , V_136 ) ;
if ( V_97 == 0 ) {
F_59 ( L_12 ) ;
V_97 = - V_143 ;
goto V_142;
} else if ( V_97 < 0 ) {
F_59 ( L_13 , V_97 ) ;
goto V_142;
}
V_131 = F_11 ( V_2 -> V_41 . V_41 [ V_130 ] ) ;
if ( V_131 == 0xDEADBEEF ) {
F_65 ( L_14 , V_40 -> V_132 ) ;
V_97 = 0 ;
} else {
F_59 ( L_15 , V_131 ) ;
V_97 = - V_121 ;
}
V_142:
F_70 ( V_2 , & V_51 , NULL ) ;
F_71 ( V_138 ) ;
V_139:
F_60 ( V_2 , V_130 ) ;
return V_97 ;
}
static void F_72 ( struct V_50 * V_51 ,
T_4 V_144 , T_4 V_145 ,
unsigned V_47 )
{
unsigned V_146 = V_47 * 8 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_24 ( V_147 ) |
F_61 ( V_148 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_146 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = 0 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_145 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_145 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_144 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_144 ) ;
}
static void F_73 ( struct V_50 * V_51 , T_4 V_144 ,
T_4 V_149 , unsigned V_47 ,
T_1 V_150 )
{
unsigned V_151 = V_47 * 2 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_24 ( V_133 ) |
F_61 ( V_148 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_144 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_144 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_151 ;
for (; V_151 > 0 ; V_151 -= 2 , -- V_47 , V_144 += 8 ) {
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_149 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_149 ) ;
V_149 += V_150 ;
}
}
static void F_74 ( struct V_50 * V_51 , T_4 V_144 ,
T_4 V_67 , unsigned V_47 ,
T_1 V_150 , T_1 V_69 )
{
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_24 ( V_152 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_144 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_144 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_69 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = 0 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_67 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_67 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_150 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = 0 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_47 ;
}
static void F_75 ( struct V_39 * V_40 , struct V_50 * V_51 )
{
struct V_48 * V_9 = F_20 ( V_40 ) ;
V_6 V_153 ;
int V_8 ;
V_153 = ( 8 - ( V_51 -> V_57 & 0x7 ) ) % 8 ;
for ( V_8 = 0 ; V_8 < V_153 ; V_8 ++ )
if ( V_9 && V_9 -> V_29 && ( V_8 == 0 ) )
V_51 -> V_140 [ V_51 -> V_57 ++ ] =
F_24 ( V_141 ) |
F_22 ( V_153 - 1 ) ;
else
V_51 -> V_140 [ V_51 -> V_57 ++ ] =
F_24 ( V_141 ) ;
}
static void F_76 ( struct V_39 * V_40 )
{
T_1 V_68 = V_40 -> V_154 . V_155 ;
T_4 V_67 = V_40 -> V_154 . V_56 ;
F_21 ( V_40 , F_24 ( V_62 ) |
F_30 ( 0 ) |
F_31 ( 3 ) |
F_77 ( 1 ) ) ;
F_21 ( V_40 , V_67 & 0xfffffffc ) ;
F_21 ( V_40 , F_27 ( V_67 ) & 0xffffffff ) ;
F_21 ( V_40 , V_68 ) ;
F_21 ( V_40 , 0xfffffff ) ;
F_21 ( V_40 , F_32 ( 0xfff ) |
F_33 ( 4 ) ) ;
}
static void F_78 ( struct V_39 * V_40 ,
unsigned V_52 , T_4 V_156 )
{
F_21 ( V_40 , F_24 ( V_65 ) |
F_35 ( 0xf ) ) ;
if ( V_52 < 8 ) {
F_21 ( V_40 , ( V_157 + V_52 ) ) ;
} else {
F_21 ( V_40 , ( V_158 + V_52 - 8 ) ) ;
}
F_21 ( V_40 , V_156 >> 12 ) ;
F_21 ( V_40 , F_24 ( V_65 ) |
F_35 ( 0xf ) ) ;
F_21 ( V_40 , V_159 ) ;
F_21 ( V_40 , 1 << V_52 ) ;
F_21 ( V_40 , F_24 ( V_62 ) |
F_30 ( 0 ) |
F_31 ( 0 ) ) ;
F_21 ( V_40 , V_159 << 2 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , F_32 ( 0xfff ) |
F_33 ( 10 ) ) ;
}
static unsigned F_79 ( struct V_39 * V_40 )
{
return
7 + 6 ;
}
static unsigned F_80 ( struct V_39 * V_40 )
{
return
6 +
3 +
6 +
12 +
10 + 10 + 10 ;
}
static int F_81 ( void * V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
V_2 -> V_9 . V_10 = V_161 ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_86 ( void * V_160 )
{
struct V_39 * V_40 ;
int V_97 , V_8 ;
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
V_97 = F_87 ( V_2 , 224 , & V_2 -> V_9 . V_162 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_87 ( V_2 , 241 , & V_2 -> V_9 . V_163 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_87 ( V_2 , 247 , & V_2 -> V_9 . V_163 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_6 ( V_2 ) ;
if ( V_97 ) {
F_59 ( L_16 ) ;
return V_97 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_40 -> V_164 = NULL ;
V_40 -> V_165 = false ;
sprintf ( V_40 -> V_166 , L_17 , V_8 ) ;
V_97 = F_88 ( V_2 , V_40 , 1024 ,
F_89 ( V_141 ) , 0xf ,
& V_2 -> V_9 . V_162 ,
( V_8 == 0 ) ?
V_167 : V_168 ,
V_169 ) ;
if ( V_97 )
return V_97 ;
}
return V_97 ;
}
static int F_90 ( void * V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
F_91 ( & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_92 ( void * V_160 )
{
int V_97 ;
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
F_1 ( V_2 ) ;
V_97 = F_53 ( V_2 ) ;
if ( V_97 )
return V_97 ;
return V_97 ;
}
static int F_93 ( void * V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
F_41 ( V_2 , false ) ;
return 0 ;
}
static int F_94 ( void * V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
return F_93 ( V_2 ) ;
}
static int F_95 ( void * V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
return F_92 ( V_2 ) ;
}
static bool F_96 ( void * V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
V_6 V_131 = F_16 ( V_170 ) ;
if ( V_131 & ( V_171 |
V_172 ) )
return false ;
return true ;
}
static int F_97 ( void * V_160 )
{
unsigned V_8 ;
V_6 V_131 ;
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_135 ; V_8 ++ ) {
V_131 = F_16 ( V_170 ) & ( V_171 |
V_172 ) ;
if ( ! V_131 )
return 0 ;
F_98 ( 1 ) ;
}
return - V_143 ;
}
static int F_99 ( void * V_160 )
{
V_6 V_173 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
V_6 V_131 = F_16 ( V_170 ) ;
if ( V_131 & V_171 ) {
V_131 = F_16 ( V_91 + V_174 ) ;
V_131 = F_29 ( V_131 , V_92 , V_93 , 0 ) ;
F_18 ( V_91 + V_174 , V_131 ) ;
V_173 |= V_175 ;
}
if ( V_131 & V_172 ) {
V_131 = F_16 ( V_91 + V_176 ) ;
V_131 = F_29 ( V_131 , V_92 , V_93 , 0 ) ;
F_18 ( V_91 + V_176 , V_131 ) ;
V_173 |= V_177 ;
}
if ( V_173 ) {
V_131 = F_16 ( V_178 ) ;
V_131 |= V_173 ;
F_100 ( V_2 -> V_22 , L_18 , V_131 ) ;
F_18 ( V_178 , V_131 ) ;
V_131 = F_16 ( V_178 ) ;
F_98 ( 50 ) ;
V_131 &= ~ V_173 ;
F_18 ( V_178 , V_131 ) ;
V_131 = F_16 ( V_178 ) ;
F_98 ( 50 ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_179 * V_145 ,
unsigned type ,
enum V_180 V_181 )
{
V_6 V_182 ;
switch ( type ) {
case V_167 :
switch ( V_181 ) {
case V_183 :
V_182 = F_16 ( V_184 + V_174 ) ;
V_182 = F_29 ( V_182 , V_185 , V_186 , 0 ) ;
F_18 ( V_184 + V_174 , V_182 ) ;
break;
case V_187 :
V_182 = F_16 ( V_184 + V_174 ) ;
V_182 = F_29 ( V_182 , V_185 , V_186 , 1 ) ;
F_18 ( V_184 + V_174 , V_182 ) ;
break;
default:
break;
}
break;
case V_168 :
switch ( V_181 ) {
case V_183 :
V_182 = F_16 ( V_184 + V_176 ) ;
V_182 = F_29 ( V_182 , V_185 , V_186 , 0 ) ;
F_18 ( V_184 + V_176 , V_182 ) ;
break;
case V_187 :
V_182 = F_16 ( V_184 + V_176 ) ;
V_182 = F_29 ( V_182 , V_185 , V_186 , 1 ) ;
F_18 ( V_184 + V_176 , V_182 ) ;
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
struct V_179 * V_188 ,
struct V_189 * V_190 )
{
T_5 V_191 , V_192 ;
V_191 = ( V_190 -> V_193 & 0x3 ) >> 0 ;
V_192 = ( V_190 -> V_193 & 0xc ) >> 2 ;
F_7 ( L_19 ) ;
switch ( V_191 ) {
case 0 :
switch ( V_192 ) {
case 0 :
F_103 ( & V_2 -> V_9 . V_11 [ 0 ] . V_40 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_192 ) {
case 0 :
F_103 ( & V_2 -> V_9 . V_11 [ 1 ] . V_40 ) ;
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
struct V_179 * V_188 ,
struct V_189 * V_190 )
{
F_59 ( L_20 ) ;
F_105 ( & V_2 -> V_194 ) ;
return 0 ;
}
static int F_106 ( void * V_160 ,
enum V_195 V_181 )
{
return 0 ;
}
static int F_107 ( void * V_160 ,
enum V_196 V_181 )
{
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
V_2 -> V_9 . V_11 [ V_8 ] . V_40 . V_197 = & V_198 ;
}
static void F_85 ( struct V_1 * V_2 )
{
V_2 -> V_9 . V_162 . V_199 = V_200 ;
V_2 -> V_9 . V_162 . V_197 = & V_201 ;
V_2 -> V_9 . V_163 . V_197 = & V_202 ;
}
static void F_108 ( struct V_50 * V_51 ,
T_4 V_203 ,
T_4 V_204 ,
T_1 V_205 )
{
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_24 ( V_147 ) |
F_61 ( V_148 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_205 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = 0 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_203 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_203 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_204 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_204 ) ;
}
static void F_109 ( struct V_50 * V_51 ,
T_1 V_206 ,
T_4 V_204 ,
T_1 V_205 )
{
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_24 ( V_207 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_26 ( V_204 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = F_27 ( V_204 ) ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_206 ;
V_51 -> V_140 [ V_51 -> V_57 ++ ] = V_205 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 . V_208 == NULL ) {
V_2 -> V_78 . V_208 = & V_209 ;
V_2 -> V_78 . V_79 = & V_2 -> V_9 . V_11 [ 0 ] . V_40 ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned V_8 ;
if ( V_2 -> V_210 . V_211 == NULL ) {
V_2 -> V_210 . V_211 = & V_212 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
V_2 -> V_210 . V_213 [ V_8 ] =
& V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_2 -> V_210 . V_214 = V_2 -> V_9 . V_10 ;
}
}
