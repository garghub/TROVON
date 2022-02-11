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
if ( V_2 -> V_44 . V_45 ) {
V_31 = & V_2 -> V_44 . V_46 [ V_47 + V_22 ] ;
V_31 -> V_48 = V_47 + V_22 ;
V_31 -> V_26 = V_2 -> V_23 . V_25 [ V_22 ] . V_26 ;
V_33 = ( const struct V_32 * ) V_31 -> V_26 -> V_38 ;
V_2 -> V_44 . V_49 +=
F_12 ( F_11 ( V_33 -> V_50 ) , V_51 ) ;
}
}
V_37:
if ( V_29 ) {
F_13 ( V_52
L_11 ,
V_28 ) ;
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
V_2 -> V_55 . V_55 [ V_54 -> V_59 ] = V_54 -> V_57 << 2 ;
F_18 ( V_54 -> V_63 , V_54 -> V_57 << 2 ) ;
} else {
int V_60 = ( V_54 == & V_54 -> V_2 -> V_23 . V_25 [ 0 ] . V_54 ) ? 0 : 1 ;
F_19 ( V_61 + V_62 [ V_60 ] , V_54 -> V_57 << 2 ) ;
}
}
static void F_20 ( struct V_53 * V_54 , T_1 V_64 )
{
struct V_65 * V_23 = F_21 ( V_54 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_64 ; V_22 ++ )
if ( V_23 && V_23 -> V_43 && ( V_22 == 0 ) )
F_22 ( V_54 , V_54 -> V_66 -> V_67 |
F_23 ( V_64 - 1 ) ) ;
else
F_22 ( V_54 , V_54 -> V_66 -> V_67 ) ;
}
static void F_24 ( struct V_53 * V_54 ,
struct V_68 * V_69 ,
unsigned V_70 , bool V_71 )
{
V_6 V_72 = V_70 & 0xf ;
F_20 ( V_54 , ( 10 - ( V_54 -> V_57 & 7 ) ) % 8 ) ;
F_22 ( V_54 , F_25 ( V_73 ) |
F_26 ( V_72 ) ) ;
F_22 ( V_54 , F_27 ( V_69 -> V_74 ) & 0xffffffe0 ) ;
F_22 ( V_54 , F_28 ( V_69 -> V_74 ) ) ;
F_22 ( V_54 , V_69 -> V_75 ) ;
F_22 ( V_54 , 0 ) ;
F_22 ( V_54 , 0 ) ;
}
static void F_29 ( struct V_53 * V_54 )
{
V_6 V_76 = 0 ;
if ( V_54 == & V_54 -> V_2 -> V_23 . V_25 [ 0 ] . V_54 )
V_76 = F_30 ( V_76 , V_77 , V_78 , 1 ) ;
else
V_76 = F_30 ( V_76 , V_77 , V_79 , 1 ) ;
F_22 ( V_54 , F_25 ( V_80 ) |
F_31 ( 1 ) |
F_32 ( 3 ) ) ;
F_22 ( V_54 , V_81 << 2 ) ;
F_22 ( V_54 , V_82 << 2 ) ;
F_22 ( V_54 , V_76 ) ;
F_22 ( V_54 , V_76 ) ;
F_22 ( V_54 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static void F_35 ( struct V_53 * V_54 )
{
F_22 ( V_54 , F_25 ( V_83 ) |
F_36 ( 0xf ) ) ;
F_22 ( V_54 , V_84 ) ;
F_22 ( V_54 , 1 ) ;
}
static void F_37 ( struct V_53 * V_54 , T_2 V_85 , T_2 V_86 ,
unsigned V_87 )
{
bool V_88 = V_87 & V_89 ;
F_22 ( V_54 , F_25 ( V_90 ) ) ;
F_22 ( V_54 , F_27 ( V_85 ) ) ;
F_22 ( V_54 , F_28 ( V_85 ) ) ;
F_22 ( V_54 , F_27 ( V_86 ) ) ;
if ( V_88 ) {
V_85 += 4 ;
F_22 ( V_54 , F_25 ( V_90 ) ) ;
F_22 ( V_54 , F_27 ( V_85 ) ) ;
F_22 ( V_54 , F_28 ( V_85 ) ) ;
F_22 ( V_54 , F_28 ( V_86 ) ) ;
}
F_22 ( V_54 , F_25 ( V_91 ) ) ;
F_22 ( V_54 , F_38 ( 0 ) ) ;
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
F_19 ( V_100 + V_62 [ V_22 ] , V_94 ) ;
V_95 = F_16 ( V_103 + V_62 [ V_22 ] ) ;
V_95 = F_30 ( V_95 , V_104 , V_105 , 0 ) ;
F_19 ( V_103 + V_62 [ V_22 ] , V_95 ) ;
}
V_92 -> V_106 = false ;
V_93 -> V_106 = false ;
}
static void F_41 ( struct V_1 * V_2 )
{
}
static void F_42 ( struct V_1 * V_2 , bool V_107 )
{
V_6 V_108 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_108 = F_16 ( V_109 + V_62 [ V_22 ] ) ;
if ( V_107 )
V_108 = F_30 ( V_108 , V_110 ,
V_111 , 1 ) ;
else
V_108 = F_30 ( V_108 , V_110 ,
V_111 , 0 ) ;
F_19 ( V_109 + V_62 [ V_22 ] , V_108 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , bool V_107 )
{
V_6 V_108 ;
int V_22 ;
if ( ! V_107 ) {
F_39 ( V_2 ) ;
F_41 ( V_2 ) ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_108 = F_16 ( V_112 + V_62 [ V_22 ] ) ;
if ( V_107 )
V_108 = F_30 ( V_108 , V_113 , V_114 , 0 ) ;
else
V_108 = F_30 ( V_108 , V_113 , V_114 , 1 ) ;
F_19 ( V_112 + V_62 [ V_22 ] , V_108 ) ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
V_6 V_94 , V_95 ;
V_6 V_115 ;
V_6 V_116 ;
V_6 V_117 ;
int V_22 , V_118 , V_119 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_54 = & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
V_116 = ( V_54 -> V_56 * 4 ) ;
F_45 ( & V_2 -> V_120 ) ;
for ( V_118 = 0 ; V_118 < 16 ; V_118 ++ ) {
F_46 ( V_2 , 0 , 0 , 0 , V_118 ) ;
F_19 ( V_121 + V_62 [ V_22 ] , 0 ) ;
F_19 ( V_122 + V_62 [ V_22 ] , 0 ) ;
}
F_46 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_47 ( & V_2 -> V_120 ) ;
F_19 ( V_123 + V_62 [ V_22 ] ,
V_2 -> V_124 . V_125 . V_126 & 0x70 ) ;
F_19 ( V_127 + V_62 [ V_22 ] , 0 ) ;
V_115 = F_48 ( V_54 -> V_128 / 4 ) ;
V_94 = F_16 ( V_100 + V_62 [ V_22 ] ) ;
V_94 = F_30 ( V_94 , V_101 , V_129 , V_115 ) ;
#ifdef F_49
V_94 = F_30 ( V_94 , V_101 , V_130 , 1 ) ;
V_94 = F_30 ( V_94 , V_101 ,
V_131 , 1 ) ;
#endif
F_19 ( V_100 + V_62 [ V_22 ] , V_94 ) ;
F_19 ( V_132 + V_62 [ V_22 ] , 0 ) ;
F_19 ( V_61 + V_62 [ V_22 ] , 0 ) ;
F_19 ( V_133 + V_62 [ V_22 ] , 0 ) ;
F_19 ( V_134 + V_62 [ V_22 ] , 0 ) ;
F_19 ( V_135 + V_62 [ V_22 ] ,
F_28 ( V_2 -> V_55 . V_74 + V_116 ) & 0xFFFFFFFF ) ;
F_19 ( V_136 + V_62 [ V_22 ] ,
F_27 ( V_2 -> V_55 . V_74 + V_116 ) & 0xFFFFFFFC ) ;
V_94 = F_30 ( V_94 , V_101 , V_137 , 1 ) ;
F_19 ( V_138 + V_62 [ V_22 ] , V_54 -> V_74 >> 8 ) ;
F_19 ( V_139 + V_62 [ V_22 ] , V_54 -> V_74 >> 40 ) ;
V_54 -> V_57 = 0 ;
F_19 ( V_61 + V_62 [ V_22 ] , V_54 -> V_57 << 2 ) ;
V_117 = F_16 ( V_140 + V_62 [ V_22 ] ) ;
if ( V_54 -> V_58 ) {
V_117 = F_30 ( V_117 , V_141 ,
V_142 , V_54 -> V_63 ) ;
V_117 = F_30 ( V_117 , V_141 , V_143 , 1 ) ;
} else {
V_117 = F_30 ( V_117 , V_141 , V_143 , 0 ) ;
}
F_19 ( V_140 + V_62 [ V_22 ] , V_117 ) ;
V_94 = F_30 ( V_94 , V_101 , V_102 , 1 ) ;
F_19 ( V_100 + V_62 [ V_22 ] , V_94 ) ;
V_95 = F_16 ( V_103 + V_62 [ V_22 ] ) ;
V_95 = F_30 ( V_95 , V_104 , V_105 , 1 ) ;
#ifdef F_49
V_95 = F_30 ( V_95 , V_104 , V_144 , 1 ) ;
#endif
F_19 ( V_103 + V_62 [ V_22 ] , V_95 ) ;
V_54 -> V_106 = true ;
}
F_43 ( V_2 , true ) ;
F_42 ( V_2 , true ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_54 = & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
V_119 = F_50 ( V_54 ) ;
if ( V_119 ) {
V_54 -> V_106 = false ;
return V_119 ;
}
if ( V_2 -> V_96 . V_97 == V_54 )
F_40 ( V_2 , V_2 -> V_98 . V_145 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
const struct V_34 * V_35 ;
const T_3 * V_146 ;
V_6 V_49 ;
int V_22 , V_118 ;
F_43 ( V_2 , false ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
if ( ! V_2 -> V_23 . V_25 [ V_22 ] . V_26 )
return - V_147 ;
V_35 = ( const struct V_34 * ) V_2 -> V_23 . V_25 [ V_22 ] . V_26 -> V_38 ;
F_53 ( & V_35 -> V_33 ) ;
V_49 = F_11 ( V_35 -> V_33 . V_50 ) / 4 ;
V_146 = ( const T_3 * )
( V_2 -> V_23 . V_25 [ V_22 ] . V_26 -> V_38 +
F_11 ( V_35 -> V_33 . V_148 ) ) ;
F_19 ( V_149 + V_62 [ V_22 ] , 0 ) ;
for ( V_118 = 0 ; V_118 < V_49 ; V_118 ++ )
F_19 ( V_150 + V_62 [ V_22 ] , F_54 ( V_146 ++ ) ) ;
F_19 ( V_149 + V_62 [ V_22 ] , V_2 -> V_23 . V_25 [ V_22 ] . V_39 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_119 , V_22 ;
if ( ! V_2 -> V_151 ) {
if ( ! V_2 -> V_44 . V_45 ) {
V_119 = F_52 ( V_2 ) ;
if ( V_119 )
return V_119 ;
} else {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_119 = V_2 -> V_152 . V_153 -> V_154 ( V_2 ,
( V_22 == 0 ) ?
V_47 :
V_155 ) ;
if ( V_119 )
return - V_147 ;
}
}
}
F_42 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
V_119 = F_44 ( V_2 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 )
return V_119 ;
return 0 ;
}
static int F_56 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
unsigned V_22 ;
unsigned V_156 ;
int V_119 ;
V_6 V_157 ;
T_2 V_74 ;
V_119 = F_57 ( V_2 , & V_156 ) ;
if ( V_119 ) {
F_58 ( V_2 -> V_36 , L_12 , V_119 ) ;
return V_119 ;
}
V_74 = V_2 -> V_55 . V_74 + ( V_156 * 4 ) ;
V_157 = 0xCAFEDEAD ;
V_2 -> V_55 . V_55 [ V_156 ] = F_59 ( V_157 ) ;
V_119 = F_60 ( V_54 , 5 ) ;
if ( V_119 ) {
F_61 ( L_13 , V_54 -> V_158 , V_119 ) ;
F_62 ( V_2 , V_156 ) ;
return V_119 ;
}
F_22 ( V_54 , F_25 ( V_159 ) |
F_63 ( V_160 ) ) ;
F_22 ( V_54 , F_27 ( V_74 ) ) ;
F_22 ( V_54 , F_28 ( V_74 ) ) ;
F_22 ( V_54 , F_64 ( 1 ) ) ;
F_22 ( V_54 , 0xDEADBEEF ) ;
F_65 ( V_54 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_161 ; V_22 ++ ) {
V_157 = F_11 ( V_2 -> V_55 . V_55 [ V_156 ] ) ;
if ( V_157 == 0xDEADBEEF )
break;
F_66 ( 1 ) ;
}
if ( V_22 < V_2 -> V_161 ) {
F_67 ( L_14 , V_54 -> V_158 , V_22 ) ;
} else {
F_61 ( L_15 ,
V_54 -> V_158 , V_157 ) ;
V_119 = - V_147 ;
}
F_62 ( V_2 , V_156 ) ;
return V_119 ;
}
static int F_68 ( struct V_53 * V_54 , long V_162 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_68 V_69 ;
struct V_163 * V_164 = NULL ;
unsigned V_156 ;
V_6 V_157 = 0 ;
T_2 V_74 ;
long V_119 ;
V_119 = F_57 ( V_2 , & V_156 ) ;
if ( V_119 ) {
F_58 ( V_2 -> V_36 , L_16 , V_119 ) ;
return V_119 ;
}
V_74 = V_2 -> V_55 . V_74 + ( V_156 * 4 ) ;
V_157 = 0xCAFEDEAD ;
V_2 -> V_55 . V_55 [ V_156 ] = F_59 ( V_157 ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_119 = F_69 ( V_2 , NULL , 256 , & V_69 ) ;
if ( V_119 ) {
F_61 ( L_17 , V_119 ) ;
goto V_165;
}
V_69 . V_166 [ 0 ] = F_25 ( V_159 ) |
F_63 ( V_160 ) ;
V_69 . V_166 [ 1 ] = F_27 ( V_74 ) ;
V_69 . V_166 [ 2 ] = F_28 ( V_74 ) ;
V_69 . V_166 [ 3 ] = F_64 ( 1 ) ;
V_69 . V_166 [ 4 ] = 0xDEADBEEF ;
V_69 . V_166 [ 5 ] = F_70 ( V_167 ) ;
V_69 . V_166 [ 6 ] = F_70 ( V_167 ) ;
V_69 . V_166 [ 7 ] = F_70 ( V_167 ) ;
V_69 . V_75 = 8 ;
V_119 = F_71 ( V_54 , 1 , & V_69 , NULL , & V_164 ) ;
if ( V_119 )
goto V_168;
V_119 = F_72 ( V_164 , false , V_162 ) ;
if ( V_119 == 0 ) {
F_61 ( L_18 ) ;
V_119 = - V_169 ;
goto V_168;
} else if ( V_119 < 0 ) {
F_61 ( L_19 , V_119 ) ;
goto V_168;
}
V_157 = F_11 ( V_2 -> V_55 . V_55 [ V_156 ] ) ;
if ( V_157 == 0xDEADBEEF ) {
F_67 ( L_20 , V_54 -> V_158 ) ;
V_119 = 0 ;
} else {
F_61 ( L_21 , V_157 ) ;
V_119 = - V_147 ;
}
V_168:
F_73 ( V_2 , & V_69 , NULL ) ;
F_74 ( V_164 ) ;
V_165:
F_62 ( V_2 , V_156 ) ;
return V_119 ;
}
static void F_75 ( struct V_68 * V_69 ,
T_4 V_170 , T_4 V_171 ,
unsigned V_64 )
{
unsigned V_172 = V_64 * 8 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_25 ( V_173 ) |
F_63 ( V_174 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_172 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = 0 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_171 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_171 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_170 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_170 ) ;
}
static void F_76 ( struct V_68 * V_69 , T_4 V_170 ,
T_4 V_175 , unsigned V_64 ,
T_1 V_176 )
{
unsigned V_177 = V_64 * 2 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_25 ( V_159 ) |
F_63 ( V_160 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_170 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_170 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_177 ;
for (; V_177 > 0 ; V_177 -= 2 ) {
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_175 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_175 ) ;
V_175 += V_176 ;
}
}
static void F_77 ( struct V_68 * V_69 , T_4 V_170 ,
T_4 V_85 , unsigned V_64 ,
T_1 V_176 , T_1 V_87 )
{
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_25 ( V_178 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_170 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_170 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_87 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = 0 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_85 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_85 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_176 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = 0 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_64 ;
}
static void F_78 ( struct V_53 * V_54 , struct V_68 * V_69 )
{
struct V_65 * V_23 = F_21 ( V_54 ) ;
V_6 V_179 ;
int V_22 ;
V_179 = ( 8 - ( V_69 -> V_75 & 0x7 ) ) % 8 ;
for ( V_22 = 0 ; V_22 < V_179 ; V_22 ++ )
if ( V_23 && V_23 -> V_43 && ( V_22 == 0 ) )
V_69 -> V_166 [ V_69 -> V_75 ++ ] =
F_25 ( V_167 ) |
F_23 ( V_179 - 1 ) ;
else
V_69 -> V_166 [ V_69 -> V_75 ++ ] =
F_25 ( V_167 ) ;
}
static void F_79 ( struct V_53 * V_54 )
{
T_1 V_86 = V_54 -> V_180 . V_181 ;
T_4 V_85 = V_54 -> V_180 . V_74 ;
F_22 ( V_54 , F_25 ( V_80 ) |
F_31 ( 0 ) |
F_32 ( 3 ) |
F_80 ( 1 ) ) ;
F_22 ( V_54 , V_85 & 0xfffffffc ) ;
F_22 ( V_54 , F_28 ( V_85 ) & 0xffffffff ) ;
F_22 ( V_54 , V_86 ) ;
F_22 ( V_54 , 0xfffffff ) ;
F_22 ( V_54 , F_33 ( 0xfff ) |
F_34 ( 4 ) ) ;
}
static void F_81 ( struct V_53 * V_54 ,
unsigned V_70 , T_4 V_182 )
{
F_22 ( V_54 , F_25 ( V_83 ) |
F_36 ( 0xf ) ) ;
if ( V_70 < 8 ) {
F_22 ( V_54 , ( V_183 + V_70 ) ) ;
} else {
F_22 ( V_54 , ( V_184 + V_70 - 8 ) ) ;
}
F_22 ( V_54 , V_182 >> 12 ) ;
F_22 ( V_54 , F_25 ( V_83 ) |
F_36 ( 0xf ) ) ;
F_22 ( V_54 , V_185 ) ;
F_22 ( V_54 , 1 << V_70 ) ;
F_22 ( V_54 , F_25 ( V_80 ) |
F_31 ( 0 ) |
F_32 ( 0 ) ) ;
F_22 ( V_54 , V_185 << 2 ) ;
F_22 ( V_54 , 0 ) ;
F_22 ( V_54 , 0 ) ;
F_22 ( V_54 , 0 ) ;
F_22 ( V_54 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static int F_82 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
switch ( V_2 -> V_3 ) {
case V_19 :
V_2 -> V_23 . V_24 = 1 ;
break;
default:
V_2 -> V_23 . V_24 = V_187 ;
break;
}
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static int F_87 ( void * V_186 )
{
struct V_53 * V_54 ;
int V_119 , V_22 ;
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
V_119 = F_88 ( V_2 , 224 , & V_2 -> V_23 . V_188 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_88 ( V_2 , 241 , & V_2 -> V_23 . V_189 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_88 ( V_2 , 247 , & V_2 -> V_23 . V_189 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_6 ( V_2 ) ;
if ( V_119 ) {
F_61 ( L_22 ) ;
return V_119 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_54 = & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
V_54 -> V_190 = NULL ;
V_54 -> V_58 = true ;
V_54 -> V_63 = ( V_22 == 0 ) ?
V_191 : V_192 ;
sprintf ( V_54 -> V_193 , L_23 , V_22 ) ;
V_119 = F_89 ( V_2 , V_54 , 1024 ,
& V_2 -> V_23 . V_188 ,
( V_22 == 0 ) ?
V_194 :
V_195 ) ;
if ( V_119 )
return V_119 ;
}
return V_119 ;
}
static int F_90 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ )
F_91 ( & V_2 -> V_23 . V_25 [ V_22 ] . V_54 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_92 ( void * V_186 )
{
int V_119 ;
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
F_1 ( V_2 ) ;
V_119 = F_55 ( V_2 ) ;
if ( V_119 )
return V_119 ;
return V_119 ;
}
static int F_93 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
F_42 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
return 0 ;
}
static int F_94 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
return F_93 ( V_2 ) ;
}
static int F_95 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
return F_92 ( V_2 ) ;
}
static bool F_96 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
V_6 V_157 = F_16 ( V_196 ) ;
if ( V_157 & ( V_197 |
V_198 ) )
return false ;
return true ;
}
static int F_97 ( void * V_186 )
{
unsigned V_22 ;
V_6 V_157 ;
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_161 ; V_22 ++ ) {
V_157 = F_16 ( V_196 ) & ( V_197 |
V_198 ) ;
if ( ! V_157 )
return 0 ;
F_98 ( 1 ) ;
}
return - V_169 ;
}
static bool F_99 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
V_6 V_199 = 0 ;
V_6 V_157 = F_16 ( V_196 ) ;
if ( ( V_157 & V_197 ) ||
( V_157 & V_198 ) ) {
V_199 |= V_200 ;
V_199 |= V_201 ;
}
if ( V_199 ) {
V_2 -> V_23 . V_199 = V_199 ;
return true ;
} else {
V_2 -> V_23 . V_199 = 0 ;
return false ;
}
}
static int F_100 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
V_6 V_199 = 0 ;
if ( ! V_2 -> V_23 . V_199 )
return 0 ;
V_199 = V_2 -> V_23 . V_199 ;
if ( F_101 ( V_199 , V_202 , V_203 ) ||
F_101 ( V_199 , V_202 , V_204 ) ) {
F_42 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
}
return 0 ;
}
static int F_102 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
V_6 V_199 = 0 ;
if ( ! V_2 -> V_23 . V_199 )
return 0 ;
V_199 = V_2 -> V_23 . V_199 ;
if ( F_101 ( V_199 , V_202 , V_203 ) ||
F_101 ( V_199 , V_202 , V_204 ) ) {
F_44 ( V_2 ) ;
F_51 ( V_2 ) ;
}
return 0 ;
}
static int F_103 ( void * V_186 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
V_6 V_199 = 0 ;
V_6 V_157 ;
if ( ! V_2 -> V_23 . V_199 )
return 0 ;
V_199 = V_2 -> V_23 . V_199 ;
if ( V_199 ) {
V_157 = F_16 ( V_205 ) ;
V_157 |= V_199 ;
F_104 ( V_2 -> V_36 , L_24 , V_157 ) ;
F_19 ( V_205 , V_157 ) ;
V_157 = F_16 ( V_205 ) ;
F_98 ( 50 ) ;
V_157 &= ~ V_199 ;
F_19 ( V_205 , V_157 ) ;
V_157 = F_16 ( V_205 ) ;
F_98 ( 50 ) ;
}
return 0 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_206 * V_207 ,
unsigned type ,
enum V_208 V_209 )
{
V_6 V_210 ;
switch ( type ) {
case V_194 :
switch ( V_209 ) {
case V_211 :
V_210 = F_16 ( V_109 + V_212 ) ;
V_210 = F_30 ( V_210 , V_110 , V_213 , 0 ) ;
F_19 ( V_109 + V_212 , V_210 ) ;
break;
case V_214 :
V_210 = F_16 ( V_109 + V_212 ) ;
V_210 = F_30 ( V_210 , V_110 , V_213 , 1 ) ;
F_19 ( V_109 + V_212 , V_210 ) ;
break;
default:
break;
}
break;
case V_195 :
switch ( V_209 ) {
case V_211 :
V_210 = F_16 ( V_109 + V_215 ) ;
V_210 = F_30 ( V_210 , V_110 , V_213 , 0 ) ;
F_19 ( V_109 + V_215 , V_210 ) ;
break;
case V_214 :
V_210 = F_16 ( V_109 + V_215 ) ;
V_210 = F_30 ( V_210 , V_110 , V_213 , 1 ) ;
F_19 ( V_109 + V_215 , V_210 ) ;
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
static int F_106 ( struct V_1 * V_2 ,
struct V_206 * V_207 ,
struct V_216 * V_217 )
{
T_5 V_218 , V_219 ;
V_218 = ( V_217 -> V_220 & 0x3 ) >> 0 ;
V_219 = ( V_217 -> V_220 & 0xc ) >> 2 ;
F_7 ( L_25 ) ;
switch ( V_218 ) {
case 0 :
switch ( V_219 ) {
case 0 :
F_107 ( & V_2 -> V_23 . V_25 [ 0 ] . V_54 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_219 ) {
case 0 :
F_107 ( & V_2 -> V_23 . V_25 [ 1 ] . V_54 ) ;
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
static int F_108 ( struct V_1 * V_2 ,
struct V_206 * V_207 ,
struct V_216 * V_217 )
{
F_61 ( L_26 ) ;
F_109 ( & V_2 -> V_221 ) ;
return 0 ;
}
static void F_110 (
struct V_1 * V_2 ,
bool V_107 )
{
T_1 V_222 , V_38 ;
int V_22 ;
if ( V_107 && ( V_2 -> V_223 & V_224 ) ) {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_222 = V_38 = F_16 ( V_225 + V_62 [ V_22 ] ) ;
V_38 &= ~ ( V_226 |
V_227 |
V_228 |
V_229 |
V_230 |
V_231 |
V_232 |
V_233 ) ;
if ( V_38 != V_222 )
F_19 ( V_225 + V_62 [ V_22 ] , V_38 ) ;
}
} else {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_222 = V_38 = F_16 ( V_225 + V_62 [ V_22 ] ) ;
V_38 |= V_226 |
V_227 |
V_228 |
V_229 |
V_230 |
V_231 |
V_232 |
V_233 ;
if ( V_38 != V_222 )
F_19 ( V_225 + V_62 [ V_22 ] , V_38 ) ;
}
}
}
static void F_111 (
struct V_1 * V_2 ,
bool V_107 )
{
T_1 V_222 , V_38 ;
int V_22 ;
if ( V_107 && ( V_2 -> V_223 & V_234 ) ) {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_222 = V_38 = F_16 ( V_235 + V_62 [ V_22 ] ) ;
V_38 |= V_236 ;
if ( V_222 != V_38 )
F_19 ( V_235 + V_62 [ V_22 ] , V_38 ) ;
}
} else {
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
V_222 = V_38 = F_16 ( V_235 + V_62 [ V_22 ] ) ;
V_38 &= ~ V_236 ;
if ( V_222 != V_38 )
F_19 ( V_235 + V_62 [ V_22 ] , V_38 ) ;
}
}
}
static int F_112 ( void * V_186 ,
enum V_237 V_209 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
switch ( V_2 -> V_3 ) {
case V_4 :
case V_16 :
case V_19 :
F_110 ( V_2 ,
V_209 == V_238 ? true : false ) ;
F_111 ( V_2 ,
V_209 == V_238 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_113 ( void * V_186 ,
enum V_239 V_209 )
{
return 0 ;
}
static void F_114 ( void * V_186 , V_6 * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_186 ;
int V_38 ;
V_38 = F_16 ( V_225 + V_62 [ 0 ] ) ;
if ( ! ( V_38 & V_233 ) )
* V_87 |= V_224 ;
V_38 = F_16 ( V_235 + V_62 [ 0 ] ) ;
if ( V_38 & V_236 )
* V_87 |= V_234 ;
}
static void F_83 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ )
V_2 -> V_23 . V_25 [ V_22 ] . V_54 . V_66 = & V_240 ;
}
static void F_86 ( struct V_1 * V_2 )
{
V_2 -> V_23 . V_188 . V_241 = V_242 ;
V_2 -> V_23 . V_188 . V_66 = & V_243 ;
V_2 -> V_23 . V_189 . V_66 = & V_244 ;
}
static void F_115 ( struct V_68 * V_69 ,
T_4 V_245 ,
T_4 V_246 ,
T_1 V_247 )
{
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_25 ( V_173 ) |
F_63 ( V_174 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_247 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = 0 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_245 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_245 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_246 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_246 ) ;
}
static void F_116 ( struct V_68 * V_69 ,
T_1 V_248 ,
T_4 V_246 ,
T_1 V_247 )
{
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_25 ( V_249 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_27 ( V_246 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = F_28 ( V_246 ) ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_248 ;
V_69 -> V_166 [ V_69 -> V_75 ++ ] = V_247 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 . V_250 == NULL ) {
V_2 -> V_96 . V_250 = & V_251 ;
V_2 -> V_96 . V_97 = & V_2 -> V_23 . V_25 [ 0 ] . V_54 ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned V_22 ;
if ( V_2 -> V_252 . V_253 == NULL ) {
V_2 -> V_252 . V_253 = & V_254 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ )
V_2 -> V_252 . V_255 [ V_22 ] =
& V_2 -> V_23 . V_25 [ V_22 ] . V_54 ;
V_2 -> V_252 . V_256 = V_2 -> V_23 . V_24 ;
}
}
