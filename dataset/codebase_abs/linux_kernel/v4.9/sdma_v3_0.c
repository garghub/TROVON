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
return V_53 -> V_2 -> V_54 . V_54 [ V_53 -> V_55 ] >> 2 ;
}
static T_1 F_15 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
V_6 V_56 ;
if ( V_53 -> V_57 ) {
V_56 = V_53 -> V_2 -> V_54 . V_54 [ V_53 -> V_58 ] >> 2 ;
} else {
int V_59 = ( V_53 == & V_53 -> V_2 -> V_22 . V_24 [ 0 ] . V_53 ) ? 0 : 1 ;
V_56 = F_16 ( V_60 + V_61 [ V_59 ] ) >> 2 ;
}
return V_56 ;
}
static void F_17 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
if ( V_53 -> V_57 ) {
V_2 -> V_54 . V_54 [ V_53 -> V_58 ] = V_53 -> V_56 << 2 ;
F_18 ( V_53 -> V_62 , V_53 -> V_56 << 2 ) ;
} else {
int V_59 = ( V_53 == & V_53 -> V_2 -> V_22 . V_24 [ 0 ] . V_53 ) ? 0 : 1 ;
F_19 ( V_60 + V_61 [ V_59 ] , V_53 -> V_56 << 2 ) ;
}
}
static void F_20 ( struct V_52 * V_53 , T_1 V_63 )
{
struct V_64 * V_22 = F_21 ( V_53 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_63 ; V_21 ++ )
if ( V_22 && V_22 -> V_42 && ( V_21 == 0 ) )
F_22 ( V_53 , V_53 -> V_65 |
F_23 ( V_63 - 1 ) ) ;
else
F_22 ( V_53 , V_53 -> V_65 ) ;
}
static void F_24 ( struct V_52 * V_53 ,
struct V_66 * V_67 ,
unsigned V_68 , bool V_69 )
{
V_6 V_70 = V_68 & 0xf ;
F_20 ( V_53 , ( 10 - ( V_53 -> V_56 & 7 ) ) % 8 ) ;
F_22 ( V_53 , F_25 ( V_71 ) |
F_26 ( V_70 ) ) ;
F_22 ( V_53 , F_27 ( V_67 -> V_72 ) & 0xffffffe0 ) ;
F_22 ( V_53 , F_28 ( V_67 -> V_72 ) ) ;
F_22 ( V_53 , V_67 -> V_73 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , 0 ) ;
}
static void F_29 ( struct V_52 * V_53 )
{
V_6 V_74 = 0 ;
if ( V_53 == & V_53 -> V_2 -> V_22 . V_24 [ 0 ] . V_53 )
V_74 = F_30 ( V_74 , V_75 , V_76 , 1 ) ;
else
V_74 = F_30 ( V_74 , V_75 , V_77 , 1 ) ;
F_22 ( V_53 , F_25 ( V_78 ) |
F_31 ( 1 ) |
F_32 ( 3 ) ) ;
F_22 ( V_53 , V_79 << 2 ) ;
F_22 ( V_53 , V_80 << 2 ) ;
F_22 ( V_53 , V_74 ) ;
F_22 ( V_53 , V_74 ) ;
F_22 ( V_53 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static void F_35 ( struct V_52 * V_53 )
{
F_22 ( V_53 , F_25 ( V_81 ) |
F_36 ( 0xf ) ) ;
F_22 ( V_53 , V_82 ) ;
F_22 ( V_53 , 1 ) ;
}
static void F_37 ( struct V_52 * V_53 , T_2 V_83 , T_2 V_84 ,
unsigned V_85 )
{
bool V_86 = V_85 & V_87 ;
F_22 ( V_53 , F_25 ( V_88 ) ) ;
F_22 ( V_53 , F_27 ( V_83 ) ) ;
F_22 ( V_53 , F_28 ( V_83 ) ) ;
F_22 ( V_53 , F_27 ( V_84 ) ) ;
if ( V_86 ) {
V_83 += 4 ;
F_22 ( V_53 , F_25 ( V_88 ) ) ;
F_22 ( V_53 , F_27 ( V_83 ) ) ;
F_22 ( V_53 , F_28 ( V_83 ) ) ;
F_22 ( V_53 , F_28 ( V_84 ) ) ;
}
F_22 ( V_53 , F_25 ( V_89 ) ) ;
F_22 ( V_53 , F_38 ( 0 ) ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_52 * V_90 = & V_2 -> V_22 . V_24 [ 0 ] . V_53 ;
struct V_52 * V_91 = & V_2 -> V_22 . V_24 [ 1 ] . V_53 ;
V_6 V_92 , V_93 ;
int V_21 ;
if ( ( V_2 -> V_94 . V_95 == V_90 ) ||
( V_2 -> V_94 . V_95 == V_91 ) )
F_40 ( V_2 , V_2 -> V_96 . V_97 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_92 = F_16 ( V_98 + V_61 [ V_21 ] ) ;
V_92 = F_30 ( V_92 , V_99 , V_100 , 0 ) ;
F_19 ( V_98 + V_61 [ V_21 ] , V_92 ) ;
V_93 = F_16 ( V_101 + V_61 [ V_21 ] ) ;
V_93 = F_30 ( V_93 , V_102 , V_103 , 0 ) ;
F_19 ( V_101 + V_61 [ V_21 ] , V_93 ) ;
}
V_90 -> V_104 = false ;
V_91 -> V_104 = false ;
}
static void F_41 ( struct V_1 * V_2 )
{
}
static void F_42 ( struct V_1 * V_2 , bool V_105 )
{
V_6 V_106 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_106 = F_16 ( V_107 + V_61 [ V_21 ] ) ;
if ( V_105 )
V_106 = F_30 ( V_106 , V_108 ,
V_109 , 1 ) ;
else
V_106 = F_30 ( V_106 , V_108 ,
V_109 , 0 ) ;
F_19 ( V_107 + V_61 [ V_21 ] , V_106 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , bool V_105 )
{
V_6 V_106 ;
int V_21 ;
if ( ! V_105 ) {
F_39 ( V_2 ) ;
F_41 ( V_2 ) ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_106 = F_16 ( V_110 + V_61 [ V_21 ] ) ;
if ( V_105 )
V_106 = F_30 ( V_106 , V_111 , V_112 , 0 ) ;
else
V_106 = F_30 ( V_106 , V_111 , V_112 , 1 ) ;
F_19 ( V_110 + V_61 [ V_21 ] , V_106 ) ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
V_6 V_92 , V_93 ;
V_6 V_113 ;
V_6 V_114 ;
V_6 V_115 ;
int V_21 , V_116 , V_117 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_53 = & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_114 = ( V_53 -> V_55 * 4 ) ;
F_45 ( & V_2 -> V_118 ) ;
for ( V_116 = 0 ; V_116 < 16 ; V_116 ++ ) {
F_46 ( V_2 , 0 , 0 , 0 , V_116 ) ;
F_19 ( V_119 + V_61 [ V_21 ] , 0 ) ;
F_19 ( V_120 + V_61 [ V_21 ] , 0 ) ;
}
F_46 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_47 ( & V_2 -> V_118 ) ;
F_19 ( V_121 + V_61 [ V_21 ] ,
V_2 -> V_122 . V_123 . V_124 & 0x70 ) ;
F_19 ( V_125 + V_61 [ V_21 ] , 0 ) ;
V_113 = F_48 ( V_53 -> V_126 / 4 ) ;
V_92 = F_16 ( V_98 + V_61 [ V_21 ] ) ;
V_92 = F_30 ( V_92 , V_99 , V_127 , V_113 ) ;
#ifdef F_49
V_92 = F_30 ( V_92 , V_99 , V_128 , 1 ) ;
V_92 = F_30 ( V_92 , V_99 ,
V_129 , 1 ) ;
#endif
F_19 ( V_98 + V_61 [ V_21 ] , V_92 ) ;
F_19 ( V_130 + V_61 [ V_21 ] , 0 ) ;
F_19 ( V_60 + V_61 [ V_21 ] , 0 ) ;
F_19 ( V_131 + V_61 [ V_21 ] , 0 ) ;
F_19 ( V_132 + V_61 [ V_21 ] , 0 ) ;
F_19 ( V_133 + V_61 [ V_21 ] ,
F_28 ( V_2 -> V_54 . V_72 + V_114 ) & 0xFFFFFFFF ) ;
F_19 ( V_134 + V_61 [ V_21 ] ,
F_27 ( V_2 -> V_54 . V_72 + V_114 ) & 0xFFFFFFFC ) ;
V_92 = F_30 ( V_92 , V_99 , V_135 , 1 ) ;
F_19 ( V_136 + V_61 [ V_21 ] , V_53 -> V_72 >> 8 ) ;
F_19 ( V_137 + V_61 [ V_21 ] , V_53 -> V_72 >> 40 ) ;
V_53 -> V_56 = 0 ;
F_19 ( V_60 + V_61 [ V_21 ] , V_53 -> V_56 << 2 ) ;
V_115 = F_16 ( V_138 + V_61 [ V_21 ] ) ;
if ( V_53 -> V_57 ) {
V_115 = F_30 ( V_115 , V_139 ,
V_140 , V_53 -> V_62 ) ;
V_115 = F_30 ( V_115 , V_139 , V_141 , 1 ) ;
} else {
V_115 = F_30 ( V_115 , V_139 , V_141 , 0 ) ;
}
F_19 ( V_138 + V_61 [ V_21 ] , V_115 ) ;
V_92 = F_30 ( V_92 , V_99 , V_100 , 1 ) ;
F_19 ( V_98 + V_61 [ V_21 ] , V_92 ) ;
V_93 = F_16 ( V_101 + V_61 [ V_21 ] ) ;
V_93 = F_30 ( V_93 , V_102 , V_103 , 1 ) ;
#ifdef F_49
V_93 = F_30 ( V_93 , V_102 , V_142 , 1 ) ;
#endif
F_19 ( V_101 + V_61 [ V_21 ] , V_93 ) ;
V_53 -> V_104 = true ;
}
F_43 ( V_2 , true ) ;
F_42 ( V_2 , true ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_53 = & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_117 = F_50 ( V_53 ) ;
if ( V_117 ) {
V_53 -> V_104 = false ;
return V_117 ;
}
if ( V_2 -> V_94 . V_95 == V_53 )
F_40 ( V_2 , V_2 -> V_96 . V_143 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 ;
const T_3 * V_144 ;
V_6 V_48 ;
int V_21 , V_116 ;
F_43 ( V_2 , false ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
if ( ! V_2 -> V_22 . V_24 [ V_21 ] . V_25 )
return - V_145 ;
V_34 = ( const struct V_33 * ) V_2 -> V_22 . V_24 [ V_21 ] . V_25 -> V_37 ;
F_53 ( & V_34 -> V_32 ) ;
V_48 = F_11 ( V_34 -> V_32 . V_49 ) / 4 ;
V_144 = ( const T_3 * )
( V_2 -> V_22 . V_24 [ V_21 ] . V_25 -> V_37 +
F_11 ( V_34 -> V_32 . V_146 ) ) ;
F_19 ( V_147 + V_61 [ V_21 ] , 0 ) ;
for ( V_116 = 0 ; V_116 < V_48 ; V_116 ++ )
F_19 ( V_148 + V_61 [ V_21 ] , F_54 ( V_144 ++ ) ) ;
F_19 ( V_147 + V_61 [ V_21 ] , V_2 -> V_22 . V_24 [ V_21 ] . V_38 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_117 , V_21 ;
if ( ! V_2 -> V_149 ) {
if ( ! V_2 -> V_43 . V_44 ) {
V_117 = F_52 ( V_2 ) ;
if ( V_117 )
return V_117 ;
} else {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_117 = V_2 -> V_150 . V_151 -> V_152 ( V_2 ,
( V_21 == 0 ) ?
V_46 :
V_153 ) ;
if ( V_117 )
return - V_145 ;
}
}
}
F_42 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
V_117 = F_44 ( V_2 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_51 ( V_2 ) ;
if ( V_117 )
return V_117 ;
return 0 ;
}
static int F_56 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
unsigned V_21 ;
unsigned V_154 ;
int V_117 ;
V_6 V_155 ;
T_2 V_72 ;
V_117 = F_57 ( V_2 , & V_154 ) ;
if ( V_117 ) {
F_58 ( V_2 -> V_35 , L_11 , V_117 ) ;
return V_117 ;
}
V_72 = V_2 -> V_54 . V_72 + ( V_154 * 4 ) ;
V_155 = 0xCAFEDEAD ;
V_2 -> V_54 . V_54 [ V_154 ] = F_59 ( V_155 ) ;
V_117 = F_60 ( V_53 , 5 ) ;
if ( V_117 ) {
F_61 ( L_12 , V_53 -> V_156 , V_117 ) ;
F_62 ( V_2 , V_154 ) ;
return V_117 ;
}
F_22 ( V_53 , F_25 ( V_157 ) |
F_63 ( V_158 ) ) ;
F_22 ( V_53 , F_27 ( V_72 ) ) ;
F_22 ( V_53 , F_28 ( V_72 ) ) ;
F_22 ( V_53 , F_64 ( 1 ) ) ;
F_22 ( V_53 , 0xDEADBEEF ) ;
F_65 ( V_53 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_159 ; V_21 ++ ) {
V_155 = F_11 ( V_2 -> V_54 . V_54 [ V_154 ] ) ;
if ( V_155 == 0xDEADBEEF )
break;
F_66 ( 1 ) ;
}
if ( V_21 < V_2 -> V_159 ) {
F_67 ( L_13 , V_53 -> V_156 , V_21 ) ;
} else {
F_61 ( L_14 ,
V_53 -> V_156 , V_155 ) ;
V_117 = - V_145 ;
}
F_62 ( V_2 , V_154 ) ;
return V_117 ;
}
static int F_68 ( struct V_52 * V_53 , long V_160 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_66 V_67 ;
struct V_161 * V_162 = NULL ;
unsigned V_154 ;
V_6 V_155 = 0 ;
T_2 V_72 ;
long V_117 ;
V_117 = F_57 ( V_2 , & V_154 ) ;
if ( V_117 ) {
F_58 ( V_2 -> V_35 , L_15 , V_117 ) ;
return V_117 ;
}
V_72 = V_2 -> V_54 . V_72 + ( V_154 * 4 ) ;
V_155 = 0xCAFEDEAD ;
V_2 -> V_54 . V_54 [ V_154 ] = F_59 ( V_155 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_117 = F_69 ( V_2 , NULL , 256 , & V_67 ) ;
if ( V_117 ) {
F_61 ( L_16 , V_117 ) ;
goto V_163;
}
V_67 . V_164 [ 0 ] = F_25 ( V_157 ) |
F_63 ( V_158 ) ;
V_67 . V_164 [ 1 ] = F_27 ( V_72 ) ;
V_67 . V_164 [ 2 ] = F_28 ( V_72 ) ;
V_67 . V_164 [ 3 ] = F_64 ( 1 ) ;
V_67 . V_164 [ 4 ] = 0xDEADBEEF ;
V_67 . V_164 [ 5 ] = F_70 ( V_165 ) ;
V_67 . V_164 [ 6 ] = F_70 ( V_165 ) ;
V_67 . V_164 [ 7 ] = F_70 ( V_165 ) ;
V_67 . V_73 = 8 ;
V_117 = F_71 ( V_53 , 1 , & V_67 , NULL , NULL , & V_162 ) ;
if ( V_117 )
goto V_166;
V_117 = F_72 ( V_162 , false , V_160 ) ;
if ( V_117 == 0 ) {
F_61 ( L_17 ) ;
V_117 = - V_167 ;
goto V_166;
} else if ( V_117 < 0 ) {
F_61 ( L_18 , V_117 ) ;
goto V_166;
}
V_155 = F_11 ( V_2 -> V_54 . V_54 [ V_154 ] ) ;
if ( V_155 == 0xDEADBEEF ) {
F_67 ( L_19 , V_53 -> V_156 ) ;
V_117 = 0 ;
} else {
F_61 ( L_20 , V_155 ) ;
V_117 = - V_145 ;
}
V_166:
F_73 ( V_2 , & V_67 , NULL ) ;
F_74 ( V_162 ) ;
V_163:
F_62 ( V_2 , V_154 ) ;
return V_117 ;
}
static void F_75 ( struct V_66 * V_67 ,
T_4 V_168 , T_4 V_169 ,
unsigned V_63 )
{
unsigned V_170 = V_63 * 8 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_25 ( V_171 ) |
F_63 ( V_172 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_170 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = 0 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_169 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_169 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_168 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_168 ) ;
}
static void F_76 ( struct V_66 * V_67 , T_4 V_168 ,
T_4 V_173 , unsigned V_63 ,
T_1 V_174 )
{
unsigned V_175 = V_63 * 2 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_25 ( V_157 ) |
F_63 ( V_172 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_168 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_168 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_175 ;
for (; V_175 > 0 ; V_175 -= 2 , -- V_63 , V_168 += 8 ) {
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_173 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_173 ) ;
V_173 += V_174 ;
}
}
static void F_77 ( struct V_66 * V_67 , T_4 V_168 ,
T_4 V_83 , unsigned V_63 ,
T_1 V_174 , T_1 V_85 )
{
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_25 ( V_176 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_168 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_168 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_85 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = 0 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_83 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_83 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_174 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = 0 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_63 ;
}
static void F_78 ( struct V_52 * V_53 , struct V_66 * V_67 )
{
struct V_64 * V_22 = F_21 ( V_53 ) ;
V_6 V_177 ;
int V_21 ;
V_177 = ( 8 - ( V_67 -> V_73 & 0x7 ) ) % 8 ;
for ( V_21 = 0 ; V_21 < V_177 ; V_21 ++ )
if ( V_22 && V_22 -> V_42 && ( V_21 == 0 ) )
V_67 -> V_164 [ V_67 -> V_73 ++ ] =
F_25 ( V_165 ) |
F_23 ( V_177 - 1 ) ;
else
V_67 -> V_164 [ V_67 -> V_73 ++ ] =
F_25 ( V_165 ) ;
}
static void F_79 ( struct V_52 * V_53 )
{
T_1 V_84 = V_53 -> V_178 . V_179 ;
T_4 V_83 = V_53 -> V_178 . V_72 ;
F_22 ( V_53 , F_25 ( V_78 ) |
F_31 ( 0 ) |
F_32 ( 3 ) |
F_80 ( 1 ) ) ;
F_22 ( V_53 , V_83 & 0xfffffffc ) ;
F_22 ( V_53 , F_28 ( V_83 ) & 0xffffffff ) ;
F_22 ( V_53 , V_84 ) ;
F_22 ( V_53 , 0xfffffff ) ;
F_22 ( V_53 , F_33 ( 0xfff ) |
F_34 ( 4 ) ) ;
}
static void F_81 ( struct V_52 * V_53 ,
unsigned V_68 , T_4 V_180 )
{
F_22 ( V_53 , F_25 ( V_81 ) |
F_36 ( 0xf ) ) ;
if ( V_68 < 8 ) {
F_22 ( V_53 , ( V_181 + V_68 ) ) ;
} else {
F_22 ( V_53 , ( V_182 + V_68 - 8 ) ) ;
}
F_22 ( V_53 , V_180 >> 12 ) ;
F_22 ( V_53 , F_25 ( V_81 ) |
F_36 ( 0xf ) ) ;
F_22 ( V_53 , V_183 ) ;
F_22 ( V_53 , 1 << V_68 ) ;
F_22 ( V_53 , F_25 ( V_78 ) |
F_31 ( 0 ) |
F_32 ( 0 ) ) ;
F_22 ( V_53 , V_183 << 2 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , 0 ) ;
F_22 ( V_53 , F_33 ( 0xfff ) |
F_34 ( 10 ) ) ;
}
static unsigned F_82 ( struct V_52 * V_53 )
{
return
7 + 6 ;
}
static unsigned F_83 ( struct V_52 * V_53 )
{
return
6 +
3 +
6 +
12 +
10 + 10 + 10 ;
}
static int F_84 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
switch ( V_2 -> V_3 ) {
case V_18 :
V_2 -> V_22 . V_23 = 1 ;
break;
default:
V_2 -> V_22 . V_23 = V_185 ;
break;
}
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static int F_89 ( void * V_184 )
{
struct V_52 * V_53 ;
int V_117 , V_21 ;
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
V_117 = F_90 ( V_2 , 224 , & V_2 -> V_22 . V_186 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_90 ( V_2 , 241 , & V_2 -> V_22 . V_187 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_90 ( V_2 , 247 , & V_2 -> V_22 . V_187 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_6 ( V_2 ) ;
if ( V_117 ) {
F_61 ( L_21 ) ;
return V_117 ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_53 = & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_53 -> V_188 = NULL ;
V_53 -> V_57 = true ;
V_53 -> V_62 = ( V_21 == 0 ) ?
V_189 : V_190 ;
sprintf ( V_53 -> V_191 , L_22 , V_21 ) ;
V_117 = F_91 ( V_2 , V_53 , 1024 ,
F_70 ( V_165 ) , 0xf ,
& V_2 -> V_22 . V_186 ,
( V_21 == 0 ) ?
V_192 : V_193 ,
V_194 ) ;
if ( V_117 )
return V_117 ;
}
return V_117 ;
}
static int F_92 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ )
F_93 ( & V_2 -> V_22 . V_24 [ V_21 ] . V_53 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_94 ( void * V_184 )
{
int V_117 ;
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
F_1 ( V_2 ) ;
V_117 = F_55 ( V_2 ) ;
if ( V_117 )
return V_117 ;
return V_117 ;
}
static int F_95 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
F_42 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
return 0 ;
}
static int F_96 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
return F_95 ( V_2 ) ;
}
static int F_97 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
return F_94 ( V_2 ) ;
}
static bool F_98 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
V_6 V_155 = F_16 ( V_195 ) ;
if ( V_155 & ( V_196 |
V_197 ) )
return false ;
return true ;
}
static int F_99 ( void * V_184 )
{
unsigned V_21 ;
V_6 V_155 ;
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_159 ; V_21 ++ ) {
V_155 = F_16 ( V_195 ) & ( V_196 |
V_197 ) ;
if ( ! V_155 )
return 0 ;
F_100 ( 1 ) ;
}
return - V_167 ;
}
static bool F_101 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
V_6 V_198 = 0 ;
V_6 V_155 = F_16 ( V_195 ) ;
if ( ( V_155 & V_196 ) ||
( V_155 & V_197 ) ) {
V_198 |= V_199 ;
V_198 |= V_200 ;
}
if ( V_198 ) {
V_2 -> V_22 . V_198 = V_198 ;
return true ;
} else {
V_2 -> V_22 . V_198 = 0 ;
return false ;
}
}
static int F_102 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
V_6 V_198 = 0 ;
if ( ! V_2 -> V_22 . V_198 )
return 0 ;
V_198 = V_2 -> V_22 . V_198 ;
if ( F_103 ( V_198 , V_201 , V_202 ) ||
F_103 ( V_198 , V_201 , V_203 ) ) {
F_42 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
}
return 0 ;
}
static int F_104 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
V_6 V_198 = 0 ;
if ( ! V_2 -> V_22 . V_198 )
return 0 ;
V_198 = V_2 -> V_22 . V_198 ;
if ( F_103 ( V_198 , V_201 , V_202 ) ||
F_103 ( V_198 , V_201 , V_203 ) ) {
F_44 ( V_2 ) ;
F_51 ( V_2 ) ;
}
return 0 ;
}
static int F_105 ( void * V_184 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
V_6 V_198 = 0 ;
V_6 V_155 ;
if ( ! V_2 -> V_22 . V_198 )
return 0 ;
V_198 = V_2 -> V_22 . V_198 ;
if ( V_198 ) {
V_155 = F_16 ( V_204 ) ;
V_155 |= V_198 ;
F_106 ( V_2 -> V_35 , L_23 , V_155 ) ;
F_19 ( V_204 , V_155 ) ;
V_155 = F_16 ( V_204 ) ;
F_100 ( 50 ) ;
V_155 &= ~ V_198 ;
F_19 ( V_204 , V_155 ) ;
V_155 = F_16 ( V_204 ) ;
F_100 ( 50 ) ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_205 * V_206 ,
unsigned type ,
enum V_207 V_208 )
{
V_6 V_209 ;
switch ( type ) {
case V_192 :
switch ( V_208 ) {
case V_210 :
V_209 = F_16 ( V_107 + V_211 ) ;
V_209 = F_30 ( V_209 , V_108 , V_212 , 0 ) ;
F_19 ( V_107 + V_211 , V_209 ) ;
break;
case V_213 :
V_209 = F_16 ( V_107 + V_211 ) ;
V_209 = F_30 ( V_209 , V_108 , V_212 , 1 ) ;
F_19 ( V_107 + V_211 , V_209 ) ;
break;
default:
break;
}
break;
case V_193 :
switch ( V_208 ) {
case V_210 :
V_209 = F_16 ( V_107 + V_214 ) ;
V_209 = F_30 ( V_209 , V_108 , V_212 , 0 ) ;
F_19 ( V_107 + V_214 , V_209 ) ;
break;
case V_213 :
V_209 = F_16 ( V_107 + V_214 ) ;
V_209 = F_30 ( V_209 , V_108 , V_212 , 1 ) ;
F_19 ( V_107 + V_214 , V_209 ) ;
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
struct V_205 * V_206 ,
struct V_215 * V_216 )
{
T_5 V_217 , V_218 ;
V_217 = ( V_216 -> V_219 & 0x3 ) >> 0 ;
V_218 = ( V_216 -> V_219 & 0xc ) >> 2 ;
F_7 ( L_24 ) ;
switch ( V_217 ) {
case 0 :
switch ( V_218 ) {
case 0 :
F_109 ( & V_2 -> V_22 . V_24 [ 0 ] . V_53 ) ;
break;
case 1 :
break;
case 2 :
break;
}
break;
case 1 :
switch ( V_218 ) {
case 0 :
F_109 ( & V_2 -> V_22 . V_24 [ 1 ] . V_53 ) ;
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
struct V_205 * V_206 ,
struct V_215 * V_216 )
{
F_61 ( L_25 ) ;
F_111 ( & V_2 -> V_220 ) ;
return 0 ;
}
static void F_112 (
struct V_1 * V_2 ,
bool V_105 )
{
T_1 V_221 , V_37 ;
int V_21 ;
if ( V_105 && ( V_2 -> V_222 & V_223 ) ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_221 = V_37 = F_16 ( V_224 + V_61 [ V_21 ] ) ;
V_37 &= ~ ( V_225 |
V_226 |
V_227 |
V_228 |
V_229 |
V_230 |
V_231 |
V_232 ) ;
if ( V_37 != V_221 )
F_19 ( V_224 + V_61 [ V_21 ] , V_37 ) ;
}
} else {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_221 = V_37 = F_16 ( V_224 + V_61 [ V_21 ] ) ;
V_37 |= V_225 |
V_226 |
V_227 |
V_228 |
V_229 |
V_230 |
V_231 |
V_232 ;
if ( V_37 != V_221 )
F_19 ( V_224 + V_61 [ V_21 ] , V_37 ) ;
}
}
}
static void F_113 (
struct V_1 * V_2 ,
bool V_105 )
{
T_1 V_221 , V_37 ;
int V_21 ;
if ( V_105 && ( V_2 -> V_222 & V_233 ) ) {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_221 = V_37 = F_16 ( V_234 + V_61 [ V_21 ] ) ;
V_37 |= V_235 ;
if ( V_221 != V_37 )
F_19 ( V_234 + V_61 [ V_21 ] , V_37 ) ;
}
} else {
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ ) {
V_221 = V_37 = F_16 ( V_234 + V_61 [ V_21 ] ) ;
V_37 &= ~ V_235 ;
if ( V_221 != V_37 )
F_19 ( V_234 + V_61 [ V_21 ] , V_37 ) ;
}
}
}
static int F_114 ( void * V_184 ,
enum V_236 V_208 )
{
struct V_1 * V_2 = (struct V_1 * ) V_184 ;
switch ( V_2 -> V_3 ) {
case V_4 :
case V_15 :
case V_18 :
F_112 ( V_2 ,
V_208 == V_237 ? true : false ) ;
F_113 ( V_2 ,
V_208 == V_237 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_115 ( void * V_184 ,
enum V_238 V_208 )
{
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ )
V_2 -> V_22 . V_24 [ V_21 ] . V_53 . V_239 = & V_240 ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_186 . V_241 = V_242 ;
V_2 -> V_22 . V_186 . V_239 = & V_243 ;
V_2 -> V_22 . V_187 . V_239 = & V_244 ;
}
static void F_116 ( struct V_66 * V_67 ,
T_4 V_245 ,
T_4 V_246 ,
T_1 V_247 )
{
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_25 ( V_171 ) |
F_63 ( V_172 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_247 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = 0 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_245 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_245 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_246 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_246 ) ;
}
static void F_117 ( struct V_66 * V_67 ,
T_1 V_248 ,
T_4 V_246 ,
T_1 V_247 )
{
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_25 ( V_249 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_27 ( V_246 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = F_28 ( V_246 ) ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_248 ;
V_67 -> V_164 [ V_67 -> V_73 ++ ] = V_247 ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 . V_250 == NULL ) {
V_2 -> V_94 . V_250 = & V_251 ;
V_2 -> V_94 . V_95 = & V_2 -> V_22 . V_24 [ 0 ] . V_53 ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned V_21 ;
if ( V_2 -> V_252 . V_253 == NULL ) {
V_2 -> V_252 . V_253 = & V_254 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 . V_23 ; V_21 ++ )
V_2 -> V_252 . V_255 [ V_21 ] =
& V_2 -> V_22 . V_24 [ V_21 ] . V_53 ;
V_2 -> V_252 . V_256 = V_2 -> V_22 . V_23 ;
}
}
