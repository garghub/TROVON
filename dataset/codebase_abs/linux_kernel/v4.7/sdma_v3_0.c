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
break;
case V_13 :
F_2 ( V_2 ,
V_14 ,
( const V_6 ) F_3 ( V_14 ) ) ;
break;
case V_15 :
F_2 ( V_2 ,
V_16 ,
( const V_6 ) F_3 ( V_16 ) ) ;
F_2 ( V_2 ,
V_17 ,
( const V_6 ) F_3 ( V_17 ) ) ;
break;
case V_18 :
F_2 ( V_2 ,
V_19 ,
( const V_6 ) F_3 ( V_19 ) ) ;
F_2 ( V_2 ,
V_20 ,
( const V_6 ) F_3 ( V_20 ) ) ;
break;
default:
break;
}
}
static void F_4 ( struct V_1 * V_2 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
F_5 ( V_2 -> V_22 . V_24 [ V_21 ] . V_25 ) ;
V_2 -> V_22 . V_24 [ V_21 ] . V_25 = NULL ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
const char * V_26 ;
char V_27 [ 30 ] ;
int V_28 = 0 , V_21 ;
struct V_29 * V_30 = NULL ;
const struct V_31 * V_32 = NULL ;
const struct V_33 * V_34 ;
F_7 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_8 :
V_26 = L_2 ;
break;
case V_4 :
V_26 = L_3 ;
break;
case V_11 :
V_26 = L_4 ;
break;
case V_13 :
V_26 = L_5 ;
break;
case V_15 :
V_26 = L_6 ;
break;
case V_18 :
V_26 = L_7 ;
break;
default: F_8 () ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
if ( V_21 == 0 )
snprintf ( V_27 , sizeof( V_27 ) , L_8 , V_26 ) ;
else
snprintf ( V_27 , sizeof( V_27 ) , L_9 , V_26 ) ;
V_28 = F_9 ( & V_2 -> V_22 . V_24 [ V_21 ] . V_25 , V_27 , V_2 -> V_35 ) ;
if ( V_28 )
goto V_36;
V_28 = F_10 ( V_2 -> V_22 . V_24 [ V_21 ] . V_25 ) ;
if ( V_28 )
goto V_36;
V_34 = ( const struct V_33 * ) V_2 -> V_22 . V_24 [ V_21 ] . V_25 -> V_37 ;
V_2 -> V_22 . V_24 [ V_21 ] . V_38 = F_11 ( V_34 -> V_32 . V_39 ) ;
V_2 -> V_22 . V_24 [ V_21 ] . V_40 = F_11 ( V_34 -> V_41 ) ;
if ( V_2 -> V_22 . V_24 [ V_21 ] . V_40 >= 20 )
V_2 -> V_22 . V_24 [ V_21 ] . V_42 = true ;
if ( V_2 -> V_43 . V_44 ) {
V_30 = & V_2 -> V_43 . V_45 [ V_46 + V_21 ] ;
V_30 -> V_47 = V_46 + V_21 ;
V_30 -> V_25 = V_2 -> V_22 . V_24 [ V_21 ] . V_25 ;
V_32 = ( const struct V_31 * ) V_30 -> V_25 -> V_37 ;
V_2 -> V_43 . V_48 +=
F_12 ( F_11 ( V_32 -> V_49 ) , V_50 ) ;
}
}
V_36:
if ( V_28 ) {
F_13 ( V_51
L_10 ,
V_27 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
F_5 ( V_2 -> V_22 . V_24 [ V_21 ] . V_25 ) ;
V_2 -> V_22 . V_24 [ V_21 ] . V_25 = NULL ;
}
}
return V_28 ;
}
static T_1 F_14 ( struct V_52 * V_53 )
{
V_6 V_54 ;
V_54 = V_53 -> V_2 -> V_55 . V_55 [ V_53 -> V_56 ] >> 2 ;
return V_54 ;
}
static T_1 F_15 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
V_6 V_57 ;
if ( V_53 -> V_58 ) {
V_57 = V_53 -> V_2 -> V_55 . V_55 [ V_53 -> V_59 ] >> 2 ;
} else {
int V_60 = ( V_53 == & V_53 -> V_2 -> V_22 . V_24 [ 0 ] . V_53 ) ? 0 : 1 ;
V_57 = F_16 ( V_61 + V_62 [ V_60 ] ) >> 2 ;
}
return V_57 ;
}
static void F_17 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
if ( V_53 -> V_58 ) {
V_2 -> V_55 . V_55 [ V_53 -> V_59 ] = V_53 -> V_57 << 2 ;
F_18 ( V_53 -> V_63 , V_53 -> V_57 << 2 ) ;
} else {
int V_60 = ( V_53 == & V_53 -> V_2 -> V_22 . V_24 [ 0 ] . V_53 ) ? 0 : 1 ;
F_19 ( V_61 + V_62 [ V_60 ] , V_53 -> V_57 << 2 ) ;
}
}
static void F_20 ( struct V_52 * V_53 , T_1 V_64 )
{
struct V_65 * V_22 = F_21 ( V_53 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_64 ; V_21 ++ )
if ( V_22 && V_22 -> V_42 && ( V_21 == 0 ) )
F_22 ( V_53 , V_53 -> V_66 |
F_23 ( V_64 - 1 ) ) ;
else
F_22 ( V_53 , V_53 -> V_66 ) ;
}
static void F_24 ( struct V_52 * V_53 ,
struct V_67 * V_68 ,
unsigned V_69 , bool V_70 )
{
V_6 V_71 = V_69 & 0xf ;
V_6 V_72 = V_53 -> V_57 + 5 ;
while ( ( V_72 & 7 ) != 2 )
V_72 ++ ;
V_72 += 6 ;
F_22 ( V_53 , F_25 ( V_73 ) |
F_26 ( V_74 ) ) ;
F_22 ( V_53 , F_27 ( V_53 -> V_75 ) & 0xfffffffc ) ;
F_22 ( V_53 , F_28 ( V_53 -> V_75 ) ) ;
F_22 ( V_53 , F_29 ( 1 ) ) ;
F_22 ( V_53 , V_72 ) ;
F_20 ( V_53 , ( 10 - ( V_53 -> V_57 & 7 ) ) % 8 ) ;
F_22 ( V_53 , F_25 ( V_76 ) |
F_30 ( V_71 ) ) ;
F_22 ( V_53 , F_27 ( V_68 -> V_77 ) & 0xffffffe0 ) ;
F_22 ( V_53 , F_28 ( V_68 -> V_77 ) ) ;
F_22 ( V_53 , V_68 -> V_78 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , 0 ) ;
}
static void F_31 ( struct V_52 * V_53 )
{
V_6 V_79 = 0 ;
if ( V_53 == & V_53 -> V_2 -> V_22 . V_24 [ 0 ] . V_53 )
V_79 = F_32 ( V_79 , V_80 , V_81 , 1 ) ;
else
V_79 = F_32 ( V_79 , V_80 , V_82 , 1 ) ;
F_22 ( V_53 , F_25 ( V_83 ) |
F_33 ( 1 ) |
F_34 ( 3 ) ) ;
F_22 ( V_53 , V_84 << 2 ) ;
F_22 ( V_53 , V_85 << 2 ) ;
F_22 ( V_53 , V_79 ) ;
F_22 ( V_53 , V_79 ) ;
F_22 ( V_53 , F_35 ( 0xfff ) |
F_36 ( 10 ) ) ;
}
static void F_37 ( struct V_52 * V_53 )
{
F_22 ( V_53 , F_25 ( V_86 ) |
F_38 ( 0xf ) ) ;
F_22 ( V_53 , V_87 ) ;
F_22 ( V_53 , 1 ) ;
}
static void F_39 ( struct V_52 * V_53 , T_2 V_88 , T_2 V_89 ,
unsigned V_90 )
{
bool V_91 = V_90 & V_92 ;
F_22 ( V_53 , F_25 ( V_93 ) ) ;
F_22 ( V_53 , F_27 ( V_88 ) ) ;
F_22 ( V_53 , F_28 ( V_88 ) ) ;
F_22 ( V_53 , F_27 ( V_89 ) ) ;
if ( V_91 ) {
V_88 += 4 ;
F_22 ( V_53 , F_25 ( V_93 ) ) ;
F_22 ( V_53 , F_27 ( V_88 ) ) ;
F_22 ( V_53 , F_28 ( V_88 ) ) ;
F_22 ( V_53 , F_28 ( V_89 ) ) ;
}
F_22 ( V_53 , F_25 ( V_94 ) ) ;
F_22 ( V_53 , F_40 ( 0 ) ) ;
}
unsigned F_41 ( struct V_52 * V_53 )
{
unsigned V_95 ;
F_22 ( V_53 , F_25 ( V_96 ) ) ;
F_22 ( V_53 , F_27 ( V_53 -> V_97 ) ) ;
F_22 ( V_53 , F_28 ( V_53 -> V_97 ) ) ;
F_22 ( V_53 , 1 ) ;
V_95 = V_53 -> V_57 ;
F_22 ( V_53 , 0x55aa55aa ) ;
return V_95 ;
}
void F_42 ( struct V_52 * V_53 , unsigned V_98 )
{
unsigned V_99 ;
F_43 ( V_53 -> V_53 [ V_98 ] != 0x55aa55aa ) ;
V_99 = V_53 -> V_57 - 1 ;
if ( F_44 ( V_99 > V_98 ) )
V_53 -> V_53 [ V_98 ] = V_99 - V_98 ;
else
V_53 -> V_53 [ V_98 ] = ( V_53 -> V_100 >> 2 ) - V_98 + V_99 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_52 * V_101 = & V_2 -> V_22 . V_24 [ 0 ] . V_53 ;
struct V_52 * V_102 = & V_2 -> V_22 . V_24 [ 1 ] . V_53 ;
V_6 V_103 , V_104 ;
int V_21 ;
if ( ( V_2 -> V_105 . V_106 == V_101 ) ||
( V_2 -> V_105 . V_106 == V_102 ) )
F_46 ( V_2 , V_2 -> V_107 . V_108 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_103 = F_16 ( V_109 + V_62 [ V_21 ] ) ;
V_103 = F_32 ( V_103 , V_110 , V_111 , 0 ) ;
F_19 ( V_109 + V_62 [ V_21 ] , V_103 ) ;
V_104 = F_16 ( V_112 + V_62 [ V_21 ] ) ;
V_104 = F_32 ( V_104 , V_113 , V_114 , 0 ) ;
F_19 ( V_112 + V_62 [ V_21 ] , V_104 ) ;
}
V_101 -> V_115 = false ;
V_102 -> V_115 = false ;
}
static void F_47 ( struct V_1 * V_2 )
{
}
static void F_48 ( struct V_1 * V_2 , bool V_116 )
{
V_6 V_117 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_117 = F_16 ( V_118 + V_62 [ V_21 ] ) ;
if ( V_116 )
V_117 = F_32 ( V_117 , V_119 ,
V_120 , 1 ) ;
else
V_117 = F_32 ( V_117 , V_119 ,
V_120 , 0 ) ;
F_19 ( V_118 + V_62 [ V_21 ] , V_117 ) ;
}
}
static void F_49 ( struct V_1 * V_2 , bool V_116 )
{
V_6 V_117 ;
int V_21 ;
if ( V_116 == false ) {
F_45 ( V_2 ) ;
F_47 ( V_2 ) ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_117 = F_16 ( V_121 + V_62 [ V_21 ] ) ;
if ( V_116 )
V_117 = F_32 ( V_117 , V_122 , V_123 , 0 ) ;
else
V_117 = F_32 ( V_117 , V_122 , V_123 , 1 ) ;
F_19 ( V_121 + V_62 [ V_21 ] , V_117 ) ;
}
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
V_6 V_103 , V_104 ;
V_6 V_124 ;
V_6 V_125 ;
V_6 V_126 ;
int V_21 , V_127 , V_128 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_53 = & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_125 = ( V_53 -> V_56 * 4 ) ;
F_51 ( & V_2 -> V_129 ) ;
for ( V_127 = 0 ; V_127 < 16 ; V_127 ++ ) {
F_52 ( V_2 , 0 , 0 , 0 , V_127 ) ;
F_19 ( V_130 + V_62 [ V_21 ] , 0 ) ;
F_19 ( V_131 + V_62 [ V_21 ] , 0 ) ;
}
F_52 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_53 ( & V_2 -> V_129 ) ;
F_19 ( V_132 + V_62 [ V_21 ] ,
V_2 -> V_133 . V_134 . V_135 & 0x70 ) ;
F_19 ( V_136 + V_62 [ V_21 ] , 0 ) ;
V_124 = F_54 ( V_53 -> V_100 / 4 ) ;
V_103 = F_16 ( V_109 + V_62 [ V_21 ] ) ;
V_103 = F_32 ( V_103 , V_110 , V_137 , V_124 ) ;
#ifdef F_55
V_103 = F_32 ( V_103 , V_110 , V_138 , 1 ) ;
V_103 = F_32 ( V_103 , V_110 ,
V_139 , 1 ) ;
#endif
F_19 ( V_109 + V_62 [ V_21 ] , V_103 ) ;
F_19 ( V_140 + V_62 [ V_21 ] , 0 ) ;
F_19 ( V_61 + V_62 [ V_21 ] , 0 ) ;
F_19 ( V_141 + V_62 [ V_21 ] , 0 ) ;
F_19 ( V_142 + V_62 [ V_21 ] , 0 ) ;
F_19 ( V_143 + V_62 [ V_21 ] ,
F_28 ( V_2 -> V_55 . V_77 + V_125 ) & 0xFFFFFFFF ) ;
F_19 ( V_144 + V_62 [ V_21 ] ,
F_27 ( V_2 -> V_55 . V_77 + V_125 ) & 0xFFFFFFFC ) ;
V_103 = F_32 ( V_103 , V_110 , V_145 , 1 ) ;
F_19 ( V_146 + V_62 [ V_21 ] , V_53 -> V_77 >> 8 ) ;
F_19 ( V_147 + V_62 [ V_21 ] , V_53 -> V_77 >> 40 ) ;
V_53 -> V_57 = 0 ;
F_19 ( V_61 + V_62 [ V_21 ] , V_53 -> V_57 << 2 ) ;
V_126 = F_16 ( V_148 + V_62 [ V_21 ] ) ;
if ( V_53 -> V_58 ) {
V_126 = F_32 ( V_126 , V_149 ,
V_150 , V_53 -> V_63 ) ;
V_126 = F_32 ( V_126 , V_149 , V_151 , 1 ) ;
} else {
V_126 = F_32 ( V_126 , V_149 , V_151 , 0 ) ;
}
F_19 ( V_148 + V_62 [ V_21 ] , V_126 ) ;
V_103 = F_32 ( V_103 , V_110 , V_111 , 1 ) ;
F_19 ( V_109 + V_62 [ V_21 ] , V_103 ) ;
V_104 = F_16 ( V_112 + V_62 [ V_21 ] ) ;
V_104 = F_32 ( V_104 , V_113 , V_114 , 1 ) ;
#ifdef F_55
V_104 = F_32 ( V_104 , V_113 , V_152 , 1 ) ;
#endif
F_19 ( V_112 + V_62 [ V_21 ] , V_104 ) ;
V_53 -> V_115 = true ;
}
F_49 ( V_2 , true ) ;
F_48 ( V_2 , true ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_53 = & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_128 = F_56 ( V_53 ) ;
if ( V_128 ) {
V_53 -> V_115 = false ;
return V_128 ;
}
if ( V_2 -> V_105 . V_106 == V_53 )
F_46 ( V_2 , V_2 -> V_107 . V_153 ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 ;
const T_3 * V_154 ;
V_6 V_48 ;
int V_21 , V_127 ;
F_49 ( V_2 , false ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
if ( ! V_2 -> V_22 . V_24 [ V_21 ] . V_25 )
return - V_155 ;
V_34 = ( const struct V_33 * ) V_2 -> V_22 . V_24 [ V_21 ] . V_25 -> V_37 ;
F_59 ( & V_34 -> V_32 ) ;
V_48 = F_11 ( V_34 -> V_32 . V_49 ) / 4 ;
V_154 = ( const T_3 * )
( V_2 -> V_22 . V_24 [ V_21 ] . V_25 -> V_37 +
F_11 ( V_34 -> V_32 . V_156 ) ) ;
F_19 ( V_157 + V_62 [ V_21 ] , 0 ) ;
for ( V_127 = 0 ; V_127 < V_48 ; V_127 ++ )
F_19 ( V_158 + V_62 [ V_21 ] , F_60 ( V_154 ++ ) ) ;
F_19 ( V_157 + V_62 [ V_21 ] , V_2 -> V_22 . V_24 [ V_21 ] . V_38 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_128 , V_21 ;
if ( ! V_2 -> V_159 ) {
if ( ! V_2 -> V_43 . V_44 ) {
V_128 = F_58 ( V_2 ) ;
if ( V_128 )
return V_128 ;
} else {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_128 = V_2 -> V_160 . V_161 -> V_162 ( V_2 ,
( V_21 == 0 ) ?
V_46 :
V_163 ) ;
if ( V_128 )
return - V_155 ;
}
}
}
F_48 ( V_2 , false ) ;
F_49 ( V_2 , false ) ;
V_128 = F_50 ( V_2 ) ;
if ( V_128 )
return V_128 ;
V_128 = F_57 ( V_2 ) ;
if ( V_128 )
return V_128 ;
return 0 ;
}
static int F_62 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
unsigned V_21 ;
unsigned V_164 ;
int V_128 ;
V_6 V_165 ;
T_2 V_77 ;
V_128 = F_63 ( V_2 , & V_164 ) ;
if ( V_128 ) {
F_64 ( V_2 -> V_35 , L_11 , V_128 ) ;
return V_128 ;
}
V_77 = V_2 -> V_55 . V_77 + ( V_164 * 4 ) ;
V_165 = 0xCAFEDEAD ;
V_2 -> V_55 . V_55 [ V_164 ] = F_65 ( V_165 ) ;
V_128 = F_66 ( V_53 , 5 ) ;
if ( V_128 ) {
F_67 ( L_12 , V_53 -> V_166 , V_128 ) ;
F_68 ( V_2 , V_164 ) ;
return V_128 ;
}
F_22 ( V_53 , F_25 ( V_73 ) |
F_26 ( V_74 ) ) ;
F_22 ( V_53 , F_27 ( V_77 ) ) ;
F_22 ( V_53 , F_28 ( V_77 ) ) ;
F_22 ( V_53 , F_29 ( 1 ) ) ;
F_22 ( V_53 , 0xDEADBEEF ) ;
F_69 ( V_53 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_167 ; V_21 ++ ) {
V_165 = F_11 ( V_2 -> V_55 . V_55 [ V_164 ] ) ;
if ( V_165 == 0xDEADBEEF )
break;
F_70 ( 1 ) ;
}
if ( V_21 < V_2 -> V_167 ) {
F_71 ( L_13 , V_53 -> V_166 , V_21 ) ;
} else {
F_67 ( L_14 ,
V_53 -> V_166 , V_165 ) ;
V_128 = - V_155 ;
}
F_68 ( V_2 , V_164 ) ;
return V_128 ;
}
static int F_72 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_67 V_68 ;
struct V_168 * V_169 = NULL ;
unsigned V_21 ;
unsigned V_164 ;
int V_128 ;
V_6 V_165 = 0 ;
T_2 V_77 ;
V_128 = F_63 ( V_2 , & V_164 ) ;
if ( V_128 ) {
F_64 ( V_2 -> V_35 , L_11 , V_128 ) ;
return V_128 ;
}
V_77 = V_2 -> V_55 . V_77 + ( V_164 * 4 ) ;
V_165 = 0xCAFEDEAD ;
V_2 -> V_55 . V_55 [ V_164 ] = F_65 ( V_165 ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_128 = F_73 ( V_2 , NULL , 256 , & V_68 ) ;
if ( V_128 ) {
F_67 ( L_15 , V_128 ) ;
goto V_170;
}
V_68 . V_171 [ 0 ] = F_25 ( V_73 ) |
F_26 ( V_74 ) ;
V_68 . V_171 [ 1 ] = F_27 ( V_77 ) ;
V_68 . V_171 [ 2 ] = F_28 ( V_77 ) ;
V_68 . V_171 [ 3 ] = F_29 ( 1 ) ;
V_68 . V_171 [ 4 ] = 0xDEADBEEF ;
V_68 . V_171 [ 5 ] = F_74 ( V_172 ) ;
V_68 . V_171 [ 6 ] = F_74 ( V_172 ) ;
V_68 . V_171 [ 7 ] = F_74 ( V_172 ) ;
V_68 . V_78 = 8 ;
V_128 = F_75 ( V_53 , 1 , & V_68 , NULL , NULL , & V_169 ) ;
if ( V_128 )
goto V_173;
V_128 = F_76 ( V_169 , false ) ;
if ( V_128 ) {
F_67 ( L_16 , V_128 ) ;
goto V_173;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_167 ; V_21 ++ ) {
V_165 = F_11 ( V_2 -> V_55 . V_55 [ V_164 ] ) ;
if ( V_165 == 0xDEADBEEF )
break;
F_70 ( 1 ) ;
}
if ( V_21 < V_2 -> V_167 ) {
F_71 ( L_17 ,
V_53 -> V_166 , V_21 ) ;
goto V_173;
} else {
F_67 ( L_18 , V_165 ) ;
V_128 = - V_155 ;
}
V_173:
F_77 ( V_169 ) ;
F_78 ( V_2 , & V_68 , NULL ) ;
F_77 ( V_169 ) ;
V_170:
F_68 ( V_2 , V_164 ) ;
return V_128 ;
}
static void F_79 ( struct V_67 * V_68 ,
T_4 V_174 , T_4 V_175 ,
unsigned V_64 )
{
while ( V_64 ) {
unsigned V_176 = V_64 * 8 ;
if ( V_176 > 0x1FFFF8 )
V_176 = 0x1FFFF8 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_25 ( V_177 ) |
F_26 ( V_178 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_176 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = 0 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_27 ( V_175 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_175 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_27 ( V_174 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_174 ) ;
V_174 += V_176 ;
V_175 += V_176 ;
V_64 -= V_176 / 8 ;
}
}
static void F_80 ( struct V_67 * V_68 ,
const T_5 * V_179 , T_4 V_174 ,
T_4 V_88 , unsigned V_64 ,
T_1 V_180 , T_1 V_90 )
{
T_4 V_181 ;
unsigned V_182 ;
while ( V_64 ) {
V_182 = V_64 * 2 ;
if ( V_182 > 0xFFFFE )
V_182 = 0xFFFFE ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_25 ( V_73 ) |
F_26 ( V_178 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_174 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_174 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_182 ;
for (; V_182 > 0 ; V_182 -= 2 , -- V_64 , V_174 += 8 ) {
V_181 = F_81 ( V_179 , V_88 ) ;
V_88 += V_180 ;
V_181 |= V_90 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_181 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_181 ) ;
}
}
}
static void F_82 ( struct V_67 * V_68 ,
T_4 V_174 ,
T_4 V_88 , unsigned V_64 ,
T_1 V_180 , T_1 V_90 )
{
T_4 V_181 ;
unsigned V_182 ;
while ( V_64 ) {
V_182 = V_64 ;
if ( V_182 > 0x7FFFF )
V_182 = 0x7FFFF ;
if ( V_90 & V_183 )
V_181 = V_88 ;
else
V_181 = 0 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_25 ( V_184 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_174 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_174 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_90 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = 0 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_181 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_181 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_180 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = 0 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_182 ;
V_174 += V_182 * 8 ;
V_88 += V_182 * V_180 ;
V_64 -= V_182 ;
}
}
static void F_83 ( struct V_52 * V_53 , struct V_67 * V_68 )
{
struct V_65 * V_22 = F_21 ( V_53 ) ;
V_6 V_185 ;
int V_21 ;
V_185 = ( 8 - ( V_68 -> V_78 & 0x7 ) ) % 8 ;
for ( V_21 = 0 ; V_21 < V_185 ; V_21 ++ )
if ( V_22 && V_22 -> V_42 && ( V_21 == 0 ) )
V_68 -> V_171 [ V_68 -> V_78 ++ ] =
F_25 ( V_172 ) |
F_23 ( V_185 - 1 ) ;
else
V_68 -> V_171 [ V_68 -> V_78 ++ ] =
F_25 ( V_172 ) ;
}
static void F_84 ( struct V_52 * V_53 )
{
T_1 V_89 = V_53 -> V_186 . V_187 ;
T_4 V_88 = V_53 -> V_186 . V_77 ;
F_22 ( V_53 , F_25 ( V_83 ) |
F_33 ( 0 ) |
F_34 ( 3 ) |
F_85 ( 1 ) ) ;
F_22 ( V_53 , V_88 & 0xfffffffc ) ;
F_22 ( V_53 , F_28 ( V_88 ) & 0xffffffff ) ;
F_22 ( V_53 , V_89 ) ;
F_22 ( V_53 , 0xfffffff ) ;
F_22 ( V_53 , F_35 ( 0xfff ) |
F_36 ( 4 ) ) ;
}
static void F_86 ( struct V_52 * V_53 ,
unsigned V_69 , T_4 V_188 )
{
F_22 ( V_53 , F_25 ( V_86 ) |
F_38 ( 0xf ) ) ;
if ( V_69 < 8 ) {
F_22 ( V_53 , ( V_189 + V_69 ) ) ;
} else {
F_22 ( V_53 , ( V_190 + V_69 - 8 ) ) ;
}
F_22 ( V_53 , V_188 >> 12 ) ;
F_22 ( V_53 , F_25 ( V_86 ) |
F_38 ( 0xf ) ) ;
F_22 ( V_53 , V_191 ) ;
F_22 ( V_53 , 1 << V_69 ) ;
F_22 ( V_53 , F_25 ( V_83 ) |
F_33 ( 0 ) |
F_34 ( 0 ) ) ;
F_22 ( V_53 , V_191 << 2 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , F_35 ( 0xfff ) |
F_36 ( 10 ) ) ;
}
static int F_87 ( void * V_192 )
{
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
switch ( V_2 -> V_3 ) {
case V_18 :
V_2 -> V_22 . V_23 = 1 ;
break;
default:
V_2 -> V_22 . V_23 = V_193 ;
break;
}
F_88 ( V_2 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
F_91 ( V_2 ) ;
return 0 ;
}
static int F_92 ( void * V_192 )
{
struct V_52 * V_53 ;
int V_128 , V_21 ;
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
V_128 = F_93 ( V_2 , 224 , & V_2 -> V_22 . V_194 ) ;
if ( V_128 )
return V_128 ;
V_128 = F_93 ( V_2 , 241 , & V_2 -> V_22 . V_195 ) ;
if ( V_128 )
return V_128 ;
V_128 = F_93 ( V_2 , 247 , & V_2 -> V_22 . V_195 ) ;
if ( V_128 )
return V_128 ;
V_128 = F_6 ( V_2 ) ;
if ( V_128 ) {
F_67 ( L_19 ) ;
return V_128 ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_53 = & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_53 -> V_196 = NULL ;
V_53 -> V_58 = true ;
V_53 -> V_63 = ( V_21 == 0 ) ?
V_197 : V_198 ;
sprintf ( V_53 -> V_199 , L_20 , V_21 ) ;
V_128 = F_94 ( V_2 , V_53 , 1024 ,
F_74 ( V_172 ) , 0xf ,
& V_2 -> V_22 . V_194 ,
( V_21 == 0 ) ?
V_200 : V_201 ,
V_202 ) ;
if ( V_128 )
return V_128 ;
}
return V_128 ;
}
static int F_95 ( void * V_192 )
{
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ )
F_96 ( & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_97 ( void * V_192 )
{
int V_128 ;
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
F_1 ( V_2 ) ;
V_128 = F_61 ( V_2 ) ;
if ( V_128 )
return V_128 ;
return V_128 ;
}
static int F_98 ( void * V_192 )
{
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
F_48 ( V_2 , false ) ;
F_49 ( V_2 , false ) ;
return 0 ;
}
static int F_99 ( void * V_192 )
{
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
return F_98 ( V_2 ) ;
}
static int F_100 ( void * V_192 )
{
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
return F_97 ( V_2 ) ;
}
static bool F_101 ( void * V_192 )
{
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
V_6 V_165 = F_16 ( V_203 ) ;
if ( V_165 & ( V_204 |
V_205 ) )
return false ;
return true ;
}
static int F_102 ( void * V_192 )
{
unsigned V_21 ;
V_6 V_165 ;
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_167 ; V_21 ++ ) {
V_165 = F_16 ( V_203 ) & ( V_204 |
V_205 ) ;
if ( ! V_165 )
return 0 ;
F_103 ( 1 ) ;
}
return - V_206 ;
}
static int F_104 ( void * V_192 )
{
V_6 V_207 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
V_6 V_165 = F_16 ( V_203 ) ;
if ( V_165 & V_204 ) {
V_165 = F_16 ( V_121 + V_208 ) ;
V_165 = F_32 ( V_165 , V_122 , V_123 , 0 ) ;
F_19 ( V_121 + V_208 , V_165 ) ;
V_207 |= V_209 ;
}
if ( V_165 & V_205 ) {
V_165 = F_16 ( V_121 + V_210 ) ;
V_165 = F_32 ( V_165 , V_122 , V_123 , 0 ) ;
F_19 ( V_121 + V_210 , V_165 ) ;
V_207 |= V_211 ;
}
if ( V_207 ) {
V_165 = F_16 ( V_212 ) ;
V_165 |= V_207 ;
F_105 ( V_2 -> V_35 , L_21 , V_165 ) ;
F_19 ( V_212 , V_165 ) ;
V_165 = F_16 ( V_212 ) ;
F_103 ( 50 ) ;
V_165 &= ~ V_207 ;
F_19 ( V_212 , V_165 ) ;
V_165 = F_16 ( V_212 ) ;
F_103 ( 50 ) ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
unsigned type ,
enum V_215 V_216 )
{
V_6 V_217 ;
switch ( type ) {
case V_200 :
switch ( V_216 ) {
case V_218 :
V_217 = F_16 ( V_118 + V_208 ) ;
V_217 = F_32 ( V_217 , V_119 , V_219 , 0 ) ;
F_19 ( V_118 + V_208 , V_217 ) ;
break;
case V_220 :
V_217 = F_16 ( V_118 + V_208 ) ;
V_217 = F_32 ( V_217 , V_119 , V_219 , 1 ) ;
F_19 ( V_118 + V_208 , V_217 ) ;
break;
default:
break;
}
break;
case V_201 :
switch ( V_216 ) {
case V_218 :
V_217 = F_16 ( V_118 + V_210 ) ;
V_217 = F_32 ( V_217 , V_119 , V_219 , 0 ) ;
F_19 ( V_118 + V_210 , V_217 ) ;
break;
case V_220 :
V_217 = F_16 ( V_118 + V_210 ) ;
V_217 = F_32 ( V_217 , V_119 , V_219 , 1 ) ;
F_19 ( V_118 + V_210 , V_217 ) ;
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
static int F_107 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
struct V_221 * V_222 )
{
T_6 V_223 , V_224 ;
V_223 = ( V_222 -> V_225 & 0x3 ) >> 0 ;
V_224 = ( V_222 -> V_225 & 0xc ) >> 2 ;
F_7 ( L_22 ) ;
switch ( V_223 ) {
case 0 :
switch ( V_224 ) {
case 0 :
F_108 ( & V_2 -> V_22 . V_24 [ 0 ] . V_53 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_224 ) {
case 0 :
F_108 ( & V_2 -> V_22 . V_24 [ 1 ] . V_53 ) ;
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
static int F_109 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
struct V_221 * V_222 )
{
F_67 ( L_23 ) ;
F_110 ( & V_2 -> V_226 ) ;
return 0 ;
}
static void F_111 (
struct V_1 * V_2 ,
bool V_116 )
{
T_1 V_227 , V_37 ;
int V_21 ;
if ( V_116 && ( V_2 -> V_228 & V_229 ) ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_227 = V_37 = F_16 ( V_230 + V_62 [ V_21 ] ) ;
V_37 &= ~ ( V_231 |
V_232 |
V_233 |
V_234 |
V_235 |
V_236 |
V_237 |
V_238 ) ;
if ( V_37 != V_227 )
F_19 ( V_230 + V_62 [ V_21 ] , V_37 ) ;
}
} else {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_227 = V_37 = F_16 ( V_230 + V_62 [ V_21 ] ) ;
V_37 |= V_231 |
V_232 |
V_233 |
V_234 |
V_235 |
V_236 |
V_237 |
V_238 ;
if ( V_37 != V_227 )
F_19 ( V_230 + V_62 [ V_21 ] , V_37 ) ;
}
}
}
static void F_112 (
struct V_1 * V_2 ,
bool V_116 )
{
T_1 V_227 , V_37 ;
int V_21 ;
if ( V_116 && ( V_2 -> V_228 & V_239 ) ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_227 = V_37 = F_16 ( V_240 + V_62 [ V_21 ] ) ;
V_37 |= V_241 ;
if ( V_227 != V_37 )
F_19 ( V_240 + V_62 [ V_21 ] , V_37 ) ;
}
} else {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_227 = V_37 = F_16 ( V_240 + V_62 [ V_21 ] ) ;
V_37 &= ~ V_241 ;
if ( V_227 != V_37 )
F_19 ( V_240 + V_62 [ V_21 ] , V_37 ) ;
}
}
}
static int F_113 ( void * V_192 ,
enum V_242 V_216 )
{
struct V_1 * V_2 = (struct V_1 * ) V_192 ;
switch ( V_2 -> V_3 ) {
case V_4 :
case V_15 :
case V_18 :
F_111 ( V_2 ,
V_216 == V_243 ? true : false ) ;
F_112 ( V_2 ,
V_216 == V_243 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_114 ( void * V_192 ,
enum V_244 V_216 )
{
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ )
V_2 -> V_22 . V_24 [ V_21 ] . V_53 . V_245 = & V_246 ;
}
static void F_91 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_194 . V_247 = V_248 ;
V_2 -> V_22 . V_194 . V_245 = & V_249 ;
V_2 -> V_22 . V_195 . V_245 = & V_250 ;
}
static void F_115 ( struct V_67 * V_68 ,
T_4 V_251 ,
T_4 V_252 ,
T_1 V_253 )
{
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_25 ( V_177 ) |
F_26 ( V_178 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_253 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = 0 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_27 ( V_251 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_251 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_27 ( V_252 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_252 ) ;
}
static void F_116 ( struct V_67 * V_68 ,
T_1 V_254 ,
T_4 V_252 ,
T_1 V_253 )
{
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_25 ( V_255 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_27 ( V_252 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = F_28 ( V_252 ) ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_254 ;
V_68 -> V_171 [ V_68 -> V_78 ++ ] = V_253 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_105 . V_256 == NULL ) {
V_2 -> V_105 . V_256 = & V_257 ;
V_2 -> V_105 . V_106 = & V_2 -> V_22 . V_24 [ 0 ] . V_53 ;
}
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned V_21 ;
if ( V_2 -> V_258 . V_259 == NULL ) {
V_2 -> V_258 . V_259 = & V_260 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ )
V_2 -> V_258 . V_261 [ V_21 ] =
& V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_2 -> V_258 . V_262 = V_2 -> V_22 . V_23 ;
}
}
