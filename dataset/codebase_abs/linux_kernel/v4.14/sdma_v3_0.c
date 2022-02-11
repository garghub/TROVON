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
case V_12 :
F_2 ( V_2 ,
V_13 ,
( const V_6 ) F_3 ( V_13 ) ) ;
break;
case V_14 :
F_2 ( V_2 ,
V_15 ,
( const V_6 ) F_3 ( V_15 ) ) ;
break;
case V_16 :
F_2 ( V_2 ,
V_17 ,
( const V_6 ) F_3 ( V_17 ) ) ;
F_2 ( V_2 ,
V_18 ,
( const V_6 ) F_3 ( V_18 ) ) ;
break;
case V_19 :
F_2 ( V_2 ,
V_20 ,
( const V_6 ) F_3 ( V_20 ) ) ;
F_2 ( V_2 ,
V_21 ,
( const V_6 ) F_3 ( V_21 ) ) ;
break;
default:
break;
}
}
static void F_4 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
F_5 ( V_2 -> V_23 . V_25 [ V_22 ] . V_26 ) ;
V_2 -> V_23 . V_25 [ V_22 ] . V_26 = NULL ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
const char * V_27 ;
char V_28 [ 30 ] ;
int V_29 = 0 , V_22 ;
struct V_30 * V_31 = NULL ;
const struct V_32 * V_33 = NULL ;
const struct V_34 * V_35 ;
F_7 ( L_1 ) ;
switch ( V_2 -> V_3 ) {
case V_8 :
V_27 = L_2 ;
break;
case V_4 :
V_27 = L_3 ;
break;
case V_11 :
V_27 = L_4 ;
break;
case V_14 :
V_27 = L_5 ;
break;
case V_12 :
V_27 = L_6 ;
break;
case V_16 :
V_27 = L_7 ;
break;
case V_19 :
V_27 = L_8 ;
break;
default: F_8 () ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
if ( V_22 == 0 )
snprintf ( V_28 , sizeof( V_28 ) , L_9 , V_27 ) ;
else
snprintf ( V_28 , sizeof( V_28 ) , L_10 , V_27 ) ;
V_29 = F_9 ( & V_2 -> V_23 . V_25 [ V_22 ] . V_26 , V_28 , V_2 -> V_36 ) ;
if ( V_29 )
goto V_37;
V_29 = F_10 ( V_2 -> V_23 . V_25 [ V_22 ] . V_26 ) ;
if ( V_29 )
goto V_37;
V_35 = ( const struct V_34 * ) V_2 -> V_23 . V_25 [ V_22 ] . V_26 -> V_38 ;
V_2 -> V_23 . V_25 [ V_22 ] . V_39 = F_11 ( V_35 -> V_33 . V_40 ) ;
V_2 -> V_23 . V_25 [ V_22 ] . V_41 = F_11 ( V_35 -> V_42 ) ;
if ( V_2 -> V_23 . V_25 [ V_22 ] . V_41 >= 20 )
V_2 -> V_23 . V_25 [ V_22 ] . V_43 = true ;
if ( V_2 -> V_44 . V_45 == V_46 ) {
V_31 = & V_2 -> V_44 . V_47 [ V_48 + V_22 ] ;
V_31 -> V_49 = V_48 + V_22 ;
V_31 -> V_26 = V_2 -> V_23 . V_25 [ V_22 ] . V_26 ;
V_33 = ( const struct V_32 * ) V_31 -> V_26 -> V_38 ;
V_2 -> V_44 . V_50 +=
F_12 ( F_11 ( V_33 -> V_51 ) , V_52 ) ;
}
}
V_37:
if ( V_29 ) {
F_13 ( L_11 , V_28 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
F_5 ( V_2 -> V_23 . V_25 [ V_22 ] . V_26 ) ;
V_2 -> V_23 . V_25 [ V_22 ] . V_26 = NULL ;
}
}
return V_29 ;
}
static T_1 F_14 ( struct V_53 * V_54 )
{
return V_54 -> V_2 -> V_55 . V_55 [ V_54 -> V_56 ] >> 2 ;
}
static T_1 F_15 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
V_6 V_57 ;
if ( V_54 -> V_58 ) {
V_57 = V_54 -> V_2 -> V_55 . V_55 [ V_54 -> V_59 ] >> 2 ;
} else {
int V_60 = ( V_54 == & V_54 -> V_2 -> V_23 . V_25 [ 0 ] . V_54 ) ? 0 : 1 ;
V_57 = F_16 ( V_61 + V_62 [ V_60 ] ) >> 2 ;
}
return V_57 ;
}
static void F_17 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
if ( V_54 -> V_58 ) {
V_2 -> V_55 . V_55 [ V_54 -> V_59 ] = F_18 ( V_54 -> V_57 ) << 2 ;
F_19 ( V_54 -> V_63 , F_18 ( V_54 -> V_57 ) << 2 ) ;
} else {
int V_60 = ( V_54 == & V_54 -> V_2 -> V_23 . V_25 [ 0 ] . V_54 ) ? 0 : 1 ;
F_20 ( V_61 + V_62 [ V_60 ] , F_18 ( V_54 -> V_57 ) << 2 ) ;
}
}
static void F_21 ( struct V_53 * V_54 , T_2 V_64 )
{
struct V_65 * V_23 = F_22 ( V_54 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_64 ; V_22 ++ )
if ( V_23 && V_23 -> V_43 && ( V_22 == 0 ) )
F_23 ( V_54 , V_54 -> V_66 -> V_67 |
F_24 ( V_64 - 1 ) ) ;
else
F_23 ( V_54 , V_54 -> V_66 -> V_67 ) ;
}
static void F_25 ( struct V_53 * V_54 ,
struct V_68 * V_69 ,
unsigned V_70 , bool V_71 )
{
V_6 V_72 = V_70 & 0xf ;
F_21 ( V_54 , ( 10 - ( F_18 ( V_54 -> V_57 ) & 7 ) ) % 8 ) ;
F_23 ( V_54 , F_26 ( V_73 ) |
F_27 ( V_72 ) ) ;
F_23 ( V_54 , F_18 ( V_69 -> V_74 ) & 0xffffffe0 ) ;
F_23 ( V_54 , F_28 ( V_69 -> V_74 ) ) ;
F_23 ( V_54 , V_69 -> V_75 ) ;
F_23 ( V_54 , 0 ) ;
F_23 ( V_54 , 0 ) ;
}
static void F_29 ( struct V_53 * V_54 )
{
V_6 V_76 = 0 ;
if ( V_54 == & V_54 -> V_2 -> V_23 . V_25 [ 0 ] . V_54 )
V_76 = F_30 ( V_76 , V_77 , V_78 , 1 ) ;
else
V_76 = F_30 ( V_76 , V_77 , V_79 , 1 ) ;
F_23 ( V_54 , F_26 ( V_80 ) |
F_31 ( 1 ) |
F_32 ( 3 ) ) ;
F_23 ( V_54 , V_81 << 2 ) ;
F_23 ( V_54 , V_82 << 2 ) ;
F_23 ( V_54 , V_76 ) ;
F_23 ( V_54 , V_76 ) ;
F_23 ( V_54 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static void F_35 ( struct V_53 * V_54 )
{
F_23 ( V_54 , F_26 ( V_83 ) |
F_36 ( 0xf ) ) ;
F_23 ( V_54 , V_84 ) ;
F_23 ( V_54 , 1 ) ;
}
static void F_37 ( struct V_53 * V_54 , T_3 V_85 , T_3 V_86 ,
unsigned V_87 )
{
bool V_88 = V_87 & V_89 ;
F_23 ( V_54 , F_26 ( V_90 ) ) ;
F_23 ( V_54 , F_18 ( V_85 ) ) ;
F_23 ( V_54 , F_28 ( V_85 ) ) ;
F_23 ( V_54 , F_18 ( V_86 ) ) ;
if ( V_88 ) {
V_85 += 4 ;
F_23 ( V_54 , F_26 ( V_90 ) ) ;
F_23 ( V_54 , F_18 ( V_85 ) ) ;
F_23 ( V_54 , F_28 ( V_85 ) ) ;
F_23 ( V_54 , F_28 ( V_86 ) ) ;
}
F_23 ( V_54 , F_26 ( V_91 ) ) ;
F_23 ( V_54 , F_38 ( 0 ) ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_53 * V_92 = & V_2 -> V_23 . V_25 [ 0 ] . V_54 ;
struct V_53 * V_93 = & V_2 -> V_23 . V_25 [ 1 ] . V_54 ;
V_6 V_94 , V_95 ;
int V_22 ;
if ( ( V_2 -> V_96 . V_97 == V_92 ) ||
( V_2 -> V_96 . V_97 == V_93 ) )
F_40 ( V_2 , V_2 -> V_98 . V_99 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_94 = F_16 ( V_100 + V_62 [ V_22 ] ) ;
V_94 = F_30 ( V_94 , V_101 , V_102 , 0 ) ;
F_20 ( V_100 + V_62 [ V_22 ] , V_94 ) ;
V_95 = F_16 ( V_103 + V_62 [ V_22 ] ) ;
V_95 = F_30 ( V_95 , V_104 , V_105 , 0 ) ;
F_20 ( V_103 + V_62 [ V_22 ] , V_95 ) ;
}
V_92 -> V_106 = false ;
V_93 -> V_106 = false ;
}
static void F_41 ( struct V_1 * V_2 )
{
}
static void F_42 ( struct V_1 * V_2 , bool V_107 )
{
V_6 V_108 , V_109 = 0 ;
int V_22 ;
if ( V_110 ) {
unsigned V_111 = V_110 ;
unsigned V_112 = 0 ;
while ( V_111 > ( V_113 >>
V_114 ) ) {
V_111 = ( V_111 + 1 ) >> 1 ;
V_112 ++ ;
}
if ( V_112 > ( V_115 >>
V_116 ) ) {
V_111 = ( V_113 >>
V_114 ) ;
V_112 = ( V_115 >>
V_116 ) ;
F_43 ( 1 ,
L_12 ,
V_111 << V_112 ) ;
}
V_109 =
V_111 << V_114 |
V_112 << V_116 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_108 = F_16 ( V_117 + V_62 [ V_22 ] ) ;
if ( V_107 ) {
V_108 = F_30 ( V_108 , V_118 ,
V_119 , 1 ) ;
V_108 = F_30 ( V_108 , V_118 ,
V_120 , 1 ) ;
if ( V_110 ) {
F_20 ( V_121 + V_62 [ V_22 ] ,
V_109 ) ;
F_20 ( V_122 + V_62 [ V_22 ] ,
V_109 ) ;
}
} else {
V_108 = F_30 ( V_108 , V_118 ,
V_119 , 0 ) ;
V_108 = F_30 ( V_108 , V_118 ,
V_120 , 1 ) ;
}
F_20 ( V_117 + V_62 [ V_22 ] , V_108 ) ;
}
}
static void F_44 ( struct V_1 * V_2 , bool V_107 )
{
V_6 V_108 ;
int V_22 ;
if ( ! V_107 ) {
F_39 ( V_2 ) ;
F_41 ( V_2 ) ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_108 = F_16 ( V_123 + V_62 [ V_22 ] ) ;
if ( V_107 )
V_108 = F_30 ( V_108 , V_124 , V_125 , 0 ) ;
else
V_108 = F_30 ( V_108 , V_124 , V_125 , 1 ) ;
F_20 ( V_123 + V_62 [ V_22 ] , V_108 ) ;
}
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
V_6 V_94 , V_95 ;
V_6 V_126 ;
V_6 V_127 ;
V_6 V_128 ;
int V_22 , V_129 , V_130 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_54 = & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
F_46 ( V_54 ) ;
V_127 = ( V_54 -> V_56 * 4 ) ;
F_47 ( & V_2 -> V_131 ) ;
for ( V_129 = 0 ; V_129 < 16 ; V_129 ++ ) {
F_48 ( V_2 , 0 , 0 , 0 , V_129 ) ;
F_20 ( V_132 + V_62 [ V_22 ] , 0 ) ;
F_20 ( V_133 + V_62 [ V_22 ] , 0 ) ;
}
F_48 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_49 ( & V_2 -> V_131 ) ;
F_20 ( V_134 + V_62 [ V_22 ] ,
V_2 -> V_135 . V_136 . V_137 & 0x70 ) ;
F_20 ( V_138 + V_62 [ V_22 ] , 0 ) ;
V_126 = F_50 ( V_54 -> V_139 / 4 ) ;
V_94 = F_16 ( V_100 + V_62 [ V_22 ] ) ;
V_94 = F_30 ( V_94 , V_101 , V_140 , V_126 ) ;
#ifdef F_51
V_94 = F_30 ( V_94 , V_101 , V_141 , 1 ) ;
V_94 = F_30 ( V_94 , V_101 ,
V_142 , 1 ) ;
#endif
F_20 ( V_100 + V_62 [ V_22 ] , V_94 ) ;
V_54 -> V_57 = 0 ;
F_20 ( V_143 + V_62 [ V_22 ] , 0 ) ;
F_17 ( V_54 ) ;
F_20 ( V_144 + V_62 [ V_22 ] , 0 ) ;
F_20 ( V_145 + V_62 [ V_22 ] , 0 ) ;
F_20 ( V_146 + V_62 [ V_22 ] ,
F_28 ( V_2 -> V_55 . V_74 + V_127 ) & 0xFFFFFFFF ) ;
F_20 ( V_147 + V_62 [ V_22 ] ,
F_18 ( V_2 -> V_55 . V_74 + V_127 ) & 0xFFFFFFFC ) ;
V_94 = F_30 ( V_94 , V_101 , V_148 , 1 ) ;
F_20 ( V_149 + V_62 [ V_22 ] , V_54 -> V_74 >> 8 ) ;
F_20 ( V_150 + V_62 [ V_22 ] , V_54 -> V_74 >> 40 ) ;
V_128 = F_16 ( V_151 + V_62 [ V_22 ] ) ;
if ( V_54 -> V_58 ) {
V_128 = F_30 ( V_128 , V_152 ,
V_153 , V_54 -> V_63 ) ;
V_128 = F_30 ( V_128 , V_152 , V_154 , 1 ) ;
} else {
V_128 = F_30 ( V_128 , V_152 , V_154 , 0 ) ;
}
F_20 ( V_151 + V_62 [ V_22 ] , V_128 ) ;
V_94 = F_30 ( V_94 , V_101 , V_102 , 1 ) ;
F_20 ( V_100 + V_62 [ V_22 ] , V_94 ) ;
V_95 = F_16 ( V_103 + V_62 [ V_22 ] ) ;
V_95 = F_30 ( V_95 , V_104 , V_105 , 1 ) ;
#ifdef F_51
V_95 = F_30 ( V_95 , V_104 , V_155 , 1 ) ;
#endif
F_20 ( V_103 + V_62 [ V_22 ] , V_95 ) ;
V_54 -> V_106 = true ;
}
F_44 ( V_2 , true ) ;
F_42 ( V_2 , true ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_54 = & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
V_130 = F_52 ( V_54 ) ;
if ( V_130 ) {
V_54 -> V_106 = false ;
return V_130 ;
}
if ( V_2 -> V_96 . V_97 == V_54 )
F_40 ( V_2 , V_2 -> V_98 . V_156 ) ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
const struct V_34 * V_35 ;
const T_4 * V_157 ;
V_6 V_50 ;
int V_22 , V_129 ;
F_44 ( V_2 , false ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
if ( ! V_2 -> V_23 . V_25 [ V_22 ] . V_26 )
return - V_158 ;
V_35 = ( const struct V_34 * ) V_2 -> V_23 . V_25 [ V_22 ] . V_26 -> V_38 ;
F_55 ( & V_35 -> V_33 ) ;
V_50 = F_11 ( V_35 -> V_33 . V_51 ) / 4 ;
V_157 = ( const T_4 * )
( V_2 -> V_23 . V_25 [ V_22 ] . V_26 -> V_38 +
F_11 ( V_35 -> V_33 . V_159 ) ) ;
F_20 ( V_160 + V_62 [ V_22 ] , 0 ) ;
for ( V_129 = 0 ; V_129 < V_50 ; V_129 ++ )
F_20 ( V_161 + V_62 [ V_22 ] , F_56 ( V_157 ++ ) ) ;
F_20 ( V_160 + V_62 [ V_22 ] , V_2 -> V_23 . V_25 [ V_22 ] . V_39 ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_130 , V_22 ;
if ( ! V_2 -> V_162 ) {
if ( V_2 -> V_44 . V_45 != V_46 ) {
V_130 = F_54 ( V_2 ) ;
if ( V_130 )
return V_130 ;
} else {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_130 = V_2 -> V_163 . V_164 -> V_165 ( V_2 ,
( V_22 == 0 ) ?
V_48 :
V_166 ) ;
if ( V_130 )
return - V_158 ;
}
}
}
F_42 ( V_2 , false ) ;
F_44 ( V_2 , false ) ;
V_130 = F_45 ( V_2 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_53 ( V_2 ) ;
if ( V_130 )
return V_130 ;
return 0 ;
}
static int F_58 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
unsigned V_22 ;
unsigned V_167 ;
int V_130 ;
V_6 V_168 ;
T_3 V_74 ;
V_130 = F_59 ( V_2 , & V_167 ) ;
if ( V_130 ) {
F_60 ( V_2 -> V_36 , L_13 , V_130 ) ;
return V_130 ;
}
V_74 = V_2 -> V_55 . V_74 + ( V_167 * 4 ) ;
V_168 = 0xCAFEDEAD ;
V_2 -> V_55 . V_55 [ V_167 ] = F_61 ( V_168 ) ;
V_130 = F_62 ( V_54 , 5 ) ;
if ( V_130 ) {
F_63 ( L_14 , V_54 -> V_169 , V_130 ) ;
F_64 ( V_2 , V_167 ) ;
return V_130 ;
}
F_23 ( V_54 , F_26 ( V_170 ) |
F_65 ( V_171 ) ) ;
F_23 ( V_54 , F_18 ( V_74 ) ) ;
F_23 ( V_54 , F_28 ( V_74 ) ) ;
F_23 ( V_54 , F_66 ( 1 ) ) ;
F_23 ( V_54 , 0xDEADBEEF ) ;
F_67 ( V_54 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_172 ; V_22 ++ ) {
V_168 = F_11 ( V_2 -> V_55 . V_55 [ V_167 ] ) ;
if ( V_168 == 0xDEADBEEF )
break;
F_68 ( 1 ) ;
}
if ( V_22 < V_2 -> V_172 ) {
F_69 ( L_15 , V_54 -> V_169 , V_22 ) ;
} else {
F_63 ( L_16 ,
V_54 -> V_169 , V_168 ) ;
V_130 = - V_158 ;
}
F_64 ( V_2 , V_167 ) ;
return V_130 ;
}
static int F_70 ( struct V_53 * V_54 , long V_173 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_68 V_69 ;
struct V_174 * V_175 = NULL ;
unsigned V_167 ;
V_6 V_168 = 0 ;
T_3 V_74 ;
long V_130 ;
V_130 = F_59 ( V_2 , & V_167 ) ;
if ( V_130 ) {
F_60 ( V_2 -> V_36 , L_17 , V_130 ) ;
return V_130 ;
}
V_74 = V_2 -> V_55 . V_74 + ( V_167 * 4 ) ;
V_168 = 0xCAFEDEAD ;
V_2 -> V_55 . V_55 [ V_167 ] = F_61 ( V_168 ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_130 = F_71 ( V_2 , NULL , 256 , & V_69 ) ;
if ( V_130 ) {
F_63 ( L_18 , V_130 ) ;
goto V_176;
}
V_69 . V_177 [ 0 ] = F_26 ( V_170 ) |
F_65 ( V_171 ) ;
V_69 . V_177 [ 1 ] = F_18 ( V_74 ) ;
V_69 . V_177 [ 2 ] = F_28 ( V_74 ) ;
V_69 . V_177 [ 3 ] = F_66 ( 1 ) ;
V_69 . V_177 [ 4 ] = 0xDEADBEEF ;
V_69 . V_177 [ 5 ] = F_72 ( V_178 ) ;
V_69 . V_177 [ 6 ] = F_72 ( V_178 ) ;
V_69 . V_177 [ 7 ] = F_72 ( V_178 ) ;
V_69 . V_75 = 8 ;
V_130 = F_73 ( V_54 , 1 , & V_69 , NULL , & V_175 ) ;
if ( V_130 )
goto V_179;
V_130 = F_74 ( V_175 , false , V_173 ) ;
if ( V_130 == 0 ) {
F_63 ( L_19 ) ;
V_130 = - V_180 ;
goto V_179;
} else if ( V_130 < 0 ) {
F_63 ( L_20 , V_130 ) ;
goto V_179;
}
V_168 = F_11 ( V_2 -> V_55 . V_55 [ V_167 ] ) ;
if ( V_168 == 0xDEADBEEF ) {
F_69 ( L_21 , V_54 -> V_169 ) ;
V_130 = 0 ;
} else {
F_63 ( L_22 , V_168 ) ;
V_130 = - V_158 ;
}
V_179:
F_75 ( V_2 , & V_69 , NULL ) ;
F_76 ( V_175 ) ;
V_176:
F_64 ( V_2 , V_167 ) ;
return V_130 ;
}
static void F_77 ( struct V_68 * V_69 ,
T_1 V_181 , T_1 V_182 ,
unsigned V_64 )
{
unsigned V_183 = V_64 * 8 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_26 ( V_184 ) |
F_65 ( V_185 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = V_183 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = 0 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_182 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_182 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_181 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_181 ) ;
}
static void F_78 ( struct V_68 * V_69 , T_1 V_181 ,
T_1 V_111 , unsigned V_64 ,
T_2 V_186 )
{
unsigned V_187 = V_64 * 2 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_26 ( V_170 ) |
F_65 ( V_171 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_181 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_181 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = V_187 ;
for (; V_187 > 0 ; V_187 -= 2 ) {
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_111 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_111 ) ;
V_111 += V_186 ;
}
}
static void F_79 ( struct V_68 * V_69 , T_1 V_181 ,
T_1 V_85 , unsigned V_64 ,
T_2 V_186 , T_1 V_87 )
{
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_26 ( V_188 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_181 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_181 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_87 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_87 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_85 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_85 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = V_186 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = 0 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = V_64 ;
}
static void F_80 ( struct V_53 * V_54 , struct V_68 * V_69 )
{
struct V_65 * V_23 = F_22 ( V_54 ) ;
V_6 V_189 ;
int V_22 ;
V_189 = ( 8 - ( V_69 -> V_75 & 0x7 ) ) % 8 ;
for ( V_22 = 0 ; V_22 < V_189 ; V_22 ++ )
if ( V_23 && V_23 -> V_43 && ( V_22 == 0 ) )
V_69 -> V_177 [ V_69 -> V_75 ++ ] =
F_26 ( V_178 ) |
F_24 ( V_189 - 1 ) ;
else
V_69 -> V_177 [ V_69 -> V_75 ++ ] =
F_26 ( V_178 ) ;
}
static void F_81 ( struct V_53 * V_54 )
{
T_2 V_86 = V_54 -> V_190 . V_191 ;
T_1 V_85 = V_54 -> V_190 . V_74 ;
F_23 ( V_54 , F_26 ( V_80 ) |
F_31 ( 0 ) |
F_32 ( 3 ) |
F_82 ( 1 ) ) ;
F_23 ( V_54 , V_85 & 0xfffffffc ) ;
F_23 ( V_54 , F_28 ( V_85 ) & 0xffffffff ) ;
F_23 ( V_54 , V_86 ) ;
F_23 ( V_54 , 0xfffffff ) ;
F_23 ( V_54 , F_33 ( 0xfff ) |
F_34 ( 4 ) ) ;
}
static void F_83 ( struct V_53 * V_54 ,
unsigned V_70 , T_1 V_192 )
{
F_23 ( V_54 , F_26 ( V_83 ) |
F_36 ( 0xf ) ) ;
if ( V_70 < 8 ) {
F_23 ( V_54 , ( V_193 + V_70 ) ) ;
} else {
F_23 ( V_54 , ( V_194 + V_70 - 8 ) ) ;
}
F_23 ( V_54 , V_192 >> 12 ) ;
F_23 ( V_54 , F_26 ( V_83 ) |
F_36 ( 0xf ) ) ;
F_23 ( V_54 , V_195 ) ;
F_23 ( V_54 , 1 << V_70 ) ;
F_23 ( V_54 , F_26 ( V_80 ) |
F_31 ( 0 ) |
F_32 ( 0 ) ) ;
F_23 ( V_54 , V_195 << 2 ) ;
F_23 ( V_54 , 0 ) ;
F_23 ( V_54 , 0 ) ;
F_23 ( V_54 , 0 ) ;
F_23 ( V_54 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static int F_84 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
switch ( V_2 -> V_3 ) {
case V_19 :
V_2 -> V_23 . V_24 = 1 ;
break;
default:
V_2 -> V_23 . V_24 = V_197 ;
break;
}
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static int F_89 ( void * V_196 )
{
struct V_53 * V_54 ;
int V_130 , V_22 ;
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
V_130 = F_90 ( V_2 , V_198 , 224 ,
& V_2 -> V_23 . V_199 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_90 ( V_2 , V_198 , 241 ,
& V_2 -> V_23 . V_200 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_90 ( V_2 , V_198 , 247 ,
& V_2 -> V_23 . V_200 ) ;
if ( V_130 )
return V_130 ;
V_130 = F_6 ( V_2 ) ;
if ( V_130 ) {
F_63 ( L_23 ) ;
return V_130 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_54 = & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
V_54 -> V_201 = NULL ;
V_54 -> V_58 = true ;
V_54 -> V_63 = ( V_22 == 0 ) ?
V_202 : V_203 ;
sprintf ( V_54 -> V_204 , L_24 , V_22 ) ;
V_130 = F_91 ( V_2 , V_54 , 1024 ,
& V_2 -> V_23 . V_199 ,
( V_22 == 0 ) ?
V_205 :
V_206 ) ;
if ( V_130 )
return V_130 ;
}
return V_130 ;
}
static int F_92 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ )
F_93 ( & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_94 ( void * V_196 )
{
int V_130 ;
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
F_1 ( V_2 ) ;
V_130 = F_57 ( V_2 ) ;
if ( V_130 )
return V_130 ;
return V_130 ;
}
static int F_95 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
F_42 ( V_2 , false ) ;
F_44 ( V_2 , false ) ;
return 0 ;
}
static int F_96 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
return F_95 ( V_2 ) ;
}
static int F_97 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
return F_94 ( V_2 ) ;
}
static bool F_98 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
V_6 V_168 = F_16 ( V_207 ) ;
if ( V_168 & ( V_208 |
V_209 ) )
return false ;
return true ;
}
static int F_99 ( void * V_196 )
{
unsigned V_22 ;
V_6 V_168 ;
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_172 ; V_22 ++ ) {
V_168 = F_16 ( V_207 ) & ( V_208 |
V_209 ) ;
if ( ! V_168 )
return 0 ;
F_100 ( 1 ) ;
}
return - V_180 ;
}
static bool F_101 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
V_6 V_210 = 0 ;
V_6 V_168 = F_16 ( V_207 ) ;
if ( ( V_168 & V_208 ) ||
( V_168 & V_209 ) ) {
V_210 |= V_211 ;
V_210 |= V_212 ;
}
if ( V_210 ) {
V_2 -> V_23 . V_210 = V_210 ;
return true ;
} else {
V_2 -> V_23 . V_210 = 0 ;
return false ;
}
}
static int F_102 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
V_6 V_210 = 0 ;
if ( ! V_2 -> V_23 . V_210 )
return 0 ;
V_210 = V_2 -> V_23 . V_210 ;
if ( F_103 ( V_210 , V_213 , V_214 ) ||
F_103 ( V_210 , V_213 , V_215 ) ) {
F_42 ( V_2 , false ) ;
F_44 ( V_2 , false ) ;
}
return 0 ;
}
static int F_104 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
V_6 V_210 = 0 ;
if ( ! V_2 -> V_23 . V_210 )
return 0 ;
V_210 = V_2 -> V_23 . V_210 ;
if ( F_103 ( V_210 , V_213 , V_214 ) ||
F_103 ( V_210 , V_213 , V_215 ) ) {
F_45 ( V_2 ) ;
F_53 ( V_2 ) ;
}
return 0 ;
}
static int F_105 ( void * V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
V_6 V_210 = 0 ;
V_6 V_168 ;
if ( ! V_2 -> V_23 . V_210 )
return 0 ;
V_210 = V_2 -> V_23 . V_210 ;
if ( V_210 ) {
V_168 = F_16 ( V_216 ) ;
V_168 |= V_210 ;
F_106 ( V_2 -> V_36 , L_25 , V_168 ) ;
F_20 ( V_216 , V_168 ) ;
V_168 = F_16 ( V_216 ) ;
F_100 ( 50 ) ;
V_168 &= ~ V_210 ;
F_20 ( V_216 , V_168 ) ;
V_168 = F_16 ( V_216 ) ;
F_100 ( 50 ) ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_217 * V_218 ,
unsigned type ,
enum V_219 V_220 )
{
V_6 V_221 ;
switch ( type ) {
case V_205 :
switch ( V_220 ) {
case V_222 :
V_221 = F_16 ( V_117 + V_223 ) ;
V_221 = F_30 ( V_221 , V_118 , V_224 , 0 ) ;
F_20 ( V_117 + V_223 , V_221 ) ;
break;
case V_225 :
V_221 = F_16 ( V_117 + V_223 ) ;
V_221 = F_30 ( V_221 , V_118 , V_224 , 1 ) ;
F_20 ( V_117 + V_223 , V_221 ) ;
break;
default:
break;
}
break;
case V_206 :
switch ( V_220 ) {
case V_222 :
V_221 = F_16 ( V_117 + V_226 ) ;
V_221 = F_30 ( V_221 , V_118 , V_224 , 0 ) ;
F_20 ( V_117 + V_226 , V_221 ) ;
break;
case V_225 :
V_221 = F_16 ( V_117 + V_226 ) ;
V_221 = F_30 ( V_221 , V_118 , V_224 , 1 ) ;
F_20 ( V_117 + V_226 , V_221 ) ;
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
static int F_108 ( struct V_1 * V_2 ,
struct V_217 * V_218 ,
struct V_227 * V_228 )
{
T_5 V_229 , V_230 ;
V_229 = ( V_228 -> V_231 & 0x3 ) >> 0 ;
V_230 = ( V_228 -> V_231 & 0xc ) >> 2 ;
F_7 ( L_26 ) ;
switch ( V_229 ) {
case 0 :
switch ( V_230 ) {
case 0 :
F_109 ( & V_2 -> V_23 . V_25 [ 0 ] . V_54 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_230 ) {
case 0 :
F_109 ( & V_2 -> V_23 . V_25 [ 1 ] . V_54 ) ;
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
static int F_110 ( struct V_1 * V_2 ,
struct V_217 * V_218 ,
struct V_227 * V_228 )
{
F_63 ( L_27 ) ;
F_111 ( & V_2 -> V_232 ) ;
return 0 ;
}
static void F_112 (
struct V_1 * V_2 ,
bool V_107 )
{
T_2 V_233 , V_38 ;
int V_22 ;
if ( V_107 && ( V_2 -> V_234 & V_235 ) ) {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_233 = V_38 = F_16 ( V_236 + V_62 [ V_22 ] ) ;
V_38 &= ~ ( V_237 |
V_238 |
V_239 |
V_240 |
V_241 |
V_242 |
V_243 |
V_244 ) ;
if ( V_38 != V_233 )
F_20 ( V_236 + V_62 [ V_22 ] , V_38 ) ;
}
} else {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_233 = V_38 = F_16 ( V_236 + V_62 [ V_22 ] ) ;
V_38 |= V_237 |
V_238 |
V_239 |
V_240 |
V_241 |
V_242 |
V_243 |
V_244 ;
if ( V_38 != V_233 )
F_20 ( V_236 + V_62 [ V_22 ] , V_38 ) ;
}
}
}
static void F_113 (
struct V_1 * V_2 ,
bool V_107 )
{
T_2 V_233 , V_38 ;
int V_22 ;
if ( V_107 && ( V_2 -> V_234 & V_245 ) ) {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_233 = V_38 = F_16 ( V_246 + V_62 [ V_22 ] ) ;
V_38 |= V_247 ;
if ( V_233 != V_38 )
F_20 ( V_246 + V_62 [ V_22 ] , V_38 ) ;
}
} else {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_233 = V_38 = F_16 ( V_246 + V_62 [ V_22 ] ) ;
V_38 &= ~ V_247 ;
if ( V_233 != V_38 )
F_20 ( V_246 + V_62 [ V_22 ] , V_38 ) ;
}
}
}
static int F_114 ( void * V_196 ,
enum V_248 V_220 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
if ( F_115 ( V_2 ) )
return 0 ;
switch ( V_2 -> V_3 ) {
case V_4 :
case V_16 :
case V_19 :
F_112 ( V_2 ,
V_220 == V_249 ) ;
F_113 ( V_2 ,
V_220 == V_249 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_116 ( void * V_196 ,
enum V_250 V_220 )
{
return 0 ;
}
static void F_117 ( void * V_196 , V_6 * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
int V_38 ;
if ( F_115 ( V_2 ) )
* V_87 = 0 ;
V_38 = F_16 ( V_236 + V_62 [ 0 ] ) ;
if ( ! ( V_38 & V_244 ) )
* V_87 |= V_235 ;
V_38 = F_16 ( V_246 + V_62 [ 0 ] ) ;
if ( V_38 & V_247 )
* V_87 |= V_245 ;
}
static void F_85 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ )
V_2 -> V_23 . V_25 [ V_22 ] . V_54 . V_66 = & V_251 ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_2 -> V_23 . V_199 . V_252 = V_253 ;
V_2 -> V_23 . V_199 . V_66 = & V_254 ;
V_2 -> V_23 . V_200 . V_66 = & V_255 ;
}
static void F_118 ( struct V_68 * V_69 ,
T_1 V_256 ,
T_1 V_257 ,
T_2 V_258 )
{
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_26 ( V_184 ) |
F_65 ( V_185 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = V_258 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = 0 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_256 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_256 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_257 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_257 ) ;
}
static void F_119 ( struct V_68 * V_69 ,
T_2 V_259 ,
T_1 V_257 ,
T_2 V_258 )
{
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_26 ( V_260 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_18 ( V_257 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = F_28 ( V_257 ) ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = V_259 ;
V_69 -> V_177 [ V_69 -> V_75 ++ ] = V_258 ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 . V_261 == NULL ) {
V_2 -> V_96 . V_261 = & V_262 ;
V_2 -> V_96 . V_97 = & V_2 -> V_23 . V_25 [ 0 ] . V_54 ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned V_22 ;
if ( V_2 -> V_263 . V_264 == NULL ) {
V_2 -> V_263 . V_264 = & V_265 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ )
V_2 -> V_263 . V_266 [ V_22 ] =
& V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
V_2 -> V_263 . V_267 = V_2 -> V_23 . V_24 ;
}
}
