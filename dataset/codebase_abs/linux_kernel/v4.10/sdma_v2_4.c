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
F_21 ( V_40 , V_40 -> V_49 -> V_50 |
F_22 ( V_47 - 1 ) ) ;
else
F_21 ( V_40 , V_40 -> V_49 -> V_50 ) ;
}
static void F_23 ( struct V_39 * V_40 ,
struct V_51 * V_52 ,
unsigned V_53 , bool V_54 )
{
V_6 V_55 = V_53 & 0xf ;
F_19 ( V_40 , ( 10 - ( V_40 -> V_44 & 7 ) ) % 8 ) ;
F_21 ( V_40 , F_24 ( V_56 ) |
F_25 ( V_55 ) ) ;
F_21 ( V_40 , F_26 ( V_52 -> V_57 ) & 0xffffffe0 ) ;
F_21 ( V_40 , F_27 ( V_52 -> V_57 ) ) ;
F_21 ( V_40 , V_52 -> V_58 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
}
static void F_28 ( struct V_39 * V_40 )
{
V_6 V_59 = 0 ;
if ( V_40 == & V_40 -> V_2 -> V_9 . V_11 [ 0 ] . V_40 )
V_59 = F_29 ( V_59 , V_60 , V_61 , 1 ) ;
else
V_59 = F_29 ( V_59 , V_60 , V_62 , 1 ) ;
F_21 ( V_40 , F_24 ( V_63 ) |
F_30 ( 1 ) |
F_31 ( 3 ) ) ;
F_21 ( V_40 , V_64 << 2 ) ;
F_21 ( V_40 , V_65 << 2 ) ;
F_21 ( V_40 , V_59 ) ;
F_21 ( V_40 , V_59 ) ;
F_21 ( V_40 , F_32 ( 0xfff ) |
F_33 ( 10 ) ) ;
}
static void F_34 ( struct V_39 * V_40 )
{
F_21 ( V_40 , F_24 ( V_66 ) |
F_35 ( 0xf ) ) ;
F_21 ( V_40 , V_67 ) ;
F_21 ( V_40 , 1 ) ;
}
static void F_36 ( struct V_39 * V_40 , T_2 V_68 , T_2 V_69 ,
unsigned V_70 )
{
bool V_71 = V_70 & V_72 ;
F_21 ( V_40 , F_24 ( V_73 ) ) ;
F_21 ( V_40 , F_26 ( V_68 ) ) ;
F_21 ( V_40 , F_27 ( V_68 ) ) ;
F_21 ( V_40 , F_26 ( V_69 ) ) ;
if ( V_71 ) {
V_68 += 4 ;
F_21 ( V_40 , F_24 ( V_73 ) ) ;
F_21 ( V_40 , F_26 ( V_68 ) ) ;
F_21 ( V_40 , F_27 ( V_68 ) ) ;
F_21 ( V_40 , F_27 ( V_69 ) ) ;
}
F_21 ( V_40 , F_24 ( V_74 ) ) ;
F_21 ( V_40 , F_37 ( 0 ) ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_39 * V_75 = & V_2 -> V_9 . V_11 [ 0 ] . V_40 ;
struct V_39 * V_76 = & V_2 -> V_9 . V_11 [ 1 ] . V_40 ;
V_6 V_77 , V_78 ;
int V_8 ;
if ( ( V_2 -> V_79 . V_80 == V_75 ) ||
( V_2 -> V_79 . V_80 == V_76 ) )
F_39 ( V_2 , V_2 -> V_81 . V_82 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_77 = F_16 ( V_83 + V_46 [ V_8 ] ) ;
V_77 = F_29 ( V_77 , V_84 , V_85 , 0 ) ;
F_18 ( V_83 + V_46 [ V_8 ] , V_77 ) ;
V_78 = F_16 ( V_86 + V_46 [ V_8 ] ) ;
V_78 = F_29 ( V_78 , V_87 , V_88 , 0 ) ;
F_18 ( V_86 + V_46 [ V_8 ] , V_78 ) ;
}
V_75 -> V_89 = false ;
V_76 -> V_89 = false ;
}
static void F_40 ( struct V_1 * V_2 )
{
}
static void F_41 ( struct V_1 * V_2 , bool V_90 )
{
V_6 V_91 ;
int V_8 ;
if ( ! V_90 ) {
F_38 ( V_2 ) ;
F_40 ( V_2 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_91 = F_16 ( V_92 + V_46 [ V_8 ] ) ;
if ( V_90 )
V_91 = F_29 ( V_91 , V_93 , V_94 , 0 ) ;
else
V_91 = F_29 ( V_91 , V_93 , V_94 , 1 ) ;
F_18 ( V_92 + V_46 [ V_8 ] , V_91 ) ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
V_6 V_77 , V_78 ;
V_6 V_95 ;
V_6 V_96 ;
int V_8 , V_97 , V_98 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_96 = ( V_40 -> V_42 * 4 ) ;
F_43 ( & V_2 -> V_99 ) ;
for ( V_97 = 0 ; V_97 < 16 ; V_97 ++ ) {
F_44 ( V_2 , 0 , 0 , 0 , V_97 ) ;
F_18 ( V_100 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_101 + V_46 [ V_8 ] , 0 ) ;
}
F_44 ( V_2 , 0 , 0 , 0 , 0 ) ;
F_45 ( & V_2 -> V_99 ) ;
F_18 ( V_102 + V_46 [ V_8 ] ,
V_2 -> V_103 . V_104 . V_105 & 0x70 ) ;
F_18 ( V_106 + V_46 [ V_8 ] , 0 ) ;
V_95 = F_46 ( V_40 -> V_107 / 4 ) ;
V_77 = F_16 ( V_83 + V_46 [ V_8 ] ) ;
V_77 = F_29 ( V_77 , V_84 , V_108 , V_95 ) ;
#ifdef F_47
V_77 = F_29 ( V_77 , V_84 , V_109 , 1 ) ;
V_77 = F_29 ( V_77 , V_84 ,
V_110 , 1 ) ;
#endif
F_18 ( V_83 + V_46 [ V_8 ] , V_77 ) ;
F_18 ( V_111 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_45 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_112 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_113 + V_46 [ V_8 ] , 0 ) ;
F_18 ( V_114 + V_46 [ V_8 ] ,
F_27 ( V_2 -> V_41 . V_57 + V_96 ) & 0xFFFFFFFF ) ;
F_18 ( V_115 + V_46 [ V_8 ] ,
F_26 ( V_2 -> V_41 . V_57 + V_96 ) & 0xFFFFFFFC ) ;
V_77 = F_29 ( V_77 , V_84 , V_116 , 1 ) ;
F_18 ( V_117 + V_46 [ V_8 ] , V_40 -> V_57 >> 8 ) ;
F_18 ( V_118 + V_46 [ V_8 ] , V_40 -> V_57 >> 40 ) ;
V_40 -> V_44 = 0 ;
F_18 ( V_45 + V_46 [ V_8 ] , V_40 -> V_44 << 2 ) ;
V_77 = F_29 ( V_77 , V_84 , V_85 , 1 ) ;
F_18 ( V_83 + V_46 [ V_8 ] , V_77 ) ;
V_78 = F_16 ( V_86 + V_46 [ V_8 ] ) ;
V_78 = F_29 ( V_78 , V_87 , V_88 , 1 ) ;
#ifdef F_47
V_78 = F_29 ( V_78 , V_87 , V_119 , 1 ) ;
#endif
F_18 ( V_86 + V_46 [ V_8 ] , V_78 ) ;
V_40 -> V_89 = true ;
}
F_41 ( V_2 , true ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_98 = F_48 ( V_40 ) ;
if ( V_98 ) {
V_40 -> V_89 = false ;
return V_98 ;
}
if ( V_2 -> V_79 . V_80 == V_40 )
F_39 ( V_2 , V_2 -> V_81 . V_120 ) ;
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
const T_3 * V_121 ;
V_6 V_35 ;
int V_8 , V_97 ;
F_41 ( V_2 , false ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
if ( ! V_2 -> V_9 . V_11 [ V_8 ] . V_12 )
return - V_122 ;
V_21 = ( const struct V_20 * ) V_2 -> V_9 . V_11 [ V_8 ] . V_12 -> V_24 ;
F_51 ( & V_21 -> V_19 ) ;
V_35 = F_11 ( V_21 -> V_19 . V_36 ) / 4 ;
V_121 = ( const T_3 * )
( V_2 -> V_9 . V_11 [ V_8 ] . V_12 -> V_24 +
F_11 ( V_21 -> V_19 . V_123 ) ) ;
F_18 ( V_124 + V_46 [ V_8 ] , 0 ) ;
for ( V_97 = 0 ; V_97 < V_35 ; V_97 ++ )
F_18 ( V_125 + V_46 [ V_8 ] , F_52 ( V_121 ++ ) ) ;
F_18 ( V_124 + V_46 [ V_8 ] , V_2 -> V_9 . V_11 [ V_8 ] . V_25 ) ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_98 ;
if ( ! V_2 -> V_126 ) {
if ( ! V_2 -> V_30 . V_31 ) {
V_98 = F_50 ( V_2 ) ;
if ( V_98 )
return V_98 ;
} else {
V_98 = V_2 -> V_127 . V_128 -> V_129 ( V_2 ,
V_33 ) ;
if ( V_98 )
return - V_122 ;
V_98 = V_2 -> V_127 . V_128 -> V_129 ( V_2 ,
V_130 ) ;
if ( V_98 )
return - V_122 ;
}
}
F_41 ( V_2 , false ) ;
V_98 = F_42 ( V_2 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_49 ( V_2 ) ;
if ( V_98 )
return V_98 ;
return 0 ;
}
static int F_54 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
unsigned V_8 ;
unsigned V_131 ;
int V_98 ;
V_6 V_132 ;
T_2 V_57 ;
V_98 = F_55 ( V_2 , & V_131 ) ;
if ( V_98 ) {
F_56 ( V_2 -> V_22 , L_6 , V_98 ) ;
return V_98 ;
}
V_57 = V_2 -> V_41 . V_57 + ( V_131 * 4 ) ;
V_132 = 0xCAFEDEAD ;
V_2 -> V_41 . V_41 [ V_131 ] = F_57 ( V_132 ) ;
V_98 = F_58 ( V_40 , 5 ) ;
if ( V_98 ) {
F_59 ( L_7 , V_40 -> V_133 , V_98 ) ;
F_60 ( V_2 , V_131 ) ;
return V_98 ;
}
F_21 ( V_40 , F_24 ( V_134 ) |
F_61 ( V_135 ) ) ;
F_21 ( V_40 , F_26 ( V_57 ) ) ;
F_21 ( V_40 , F_27 ( V_57 ) ) ;
F_21 ( V_40 , F_62 ( 1 ) ) ;
F_21 ( V_40 , 0xDEADBEEF ) ;
F_63 ( V_40 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_136 ; V_8 ++ ) {
V_132 = F_11 ( V_2 -> V_41 . V_41 [ V_131 ] ) ;
if ( V_132 == 0xDEADBEEF )
break;
F_64 ( 1 ) ;
}
if ( V_8 < V_2 -> V_136 ) {
F_65 ( L_8 , V_40 -> V_133 , V_8 ) ;
} else {
F_59 ( L_9 ,
V_40 -> V_133 , V_132 ) ;
V_98 = - V_122 ;
}
F_60 ( V_2 , V_131 ) ;
return V_98 ;
}
static int F_66 ( struct V_39 * V_40 , long V_137 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_51 V_52 ;
struct V_138 * V_139 = NULL ;
unsigned V_131 ;
V_6 V_132 = 0 ;
T_2 V_57 ;
long V_98 ;
V_98 = F_55 ( V_2 , & V_131 ) ;
if ( V_98 ) {
F_56 ( V_2 -> V_22 , L_10 , V_98 ) ;
return V_98 ;
}
V_57 = V_2 -> V_41 . V_57 + ( V_131 * 4 ) ;
V_132 = 0xCAFEDEAD ;
V_2 -> V_41 . V_41 [ V_131 ] = F_57 ( V_132 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_98 = F_67 ( V_2 , NULL , 256 , & V_52 ) ;
if ( V_98 ) {
F_59 ( L_11 , V_98 ) ;
goto V_140;
}
V_52 . V_141 [ 0 ] = F_24 ( V_134 ) |
F_61 ( V_135 ) ;
V_52 . V_141 [ 1 ] = F_26 ( V_57 ) ;
V_52 . V_141 [ 2 ] = F_27 ( V_57 ) ;
V_52 . V_141 [ 3 ] = F_62 ( 1 ) ;
V_52 . V_141 [ 4 ] = 0xDEADBEEF ;
V_52 . V_141 [ 5 ] = F_24 ( V_142 ) ;
V_52 . V_141 [ 6 ] = F_24 ( V_142 ) ;
V_52 . V_141 [ 7 ] = F_24 ( V_142 ) ;
V_52 . V_58 = 8 ;
V_98 = F_68 ( V_40 , 1 , & V_52 , NULL , NULL , & V_139 ) ;
if ( V_98 )
goto V_143;
V_98 = F_69 ( V_139 , false , V_137 ) ;
if ( V_98 == 0 ) {
F_59 ( L_12 ) ;
V_98 = - V_144 ;
goto V_143;
} else if ( V_98 < 0 ) {
F_59 ( L_13 , V_98 ) ;
goto V_143;
}
V_132 = F_11 ( V_2 -> V_41 . V_41 [ V_131 ] ) ;
if ( V_132 == 0xDEADBEEF ) {
F_65 ( L_14 , V_40 -> V_133 ) ;
V_98 = 0 ;
} else {
F_59 ( L_15 , V_132 ) ;
V_98 = - V_122 ;
}
V_143:
F_70 ( V_2 , & V_52 , NULL ) ;
F_71 ( V_139 ) ;
V_140:
F_60 ( V_2 , V_131 ) ;
return V_98 ;
}
static void F_72 ( struct V_51 * V_52 ,
T_4 V_145 , T_4 V_146 ,
unsigned V_47 )
{
unsigned V_147 = V_47 * 8 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_24 ( V_148 ) |
F_61 ( V_149 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_147 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_146 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_146 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_145 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_145 ) ;
}
static void F_73 ( struct V_51 * V_52 , T_4 V_145 ,
T_4 V_150 , unsigned V_47 ,
T_1 V_151 )
{
unsigned V_152 = V_47 * 2 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_24 ( V_134 ) |
F_61 ( V_135 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_145 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_145 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_152 ;
for (; V_152 > 0 ; V_152 -= 2 ) {
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_150 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_150 ) ;
V_150 += V_151 ;
}
}
static void F_74 ( struct V_51 * V_52 , T_4 V_145 ,
T_4 V_68 , unsigned V_47 ,
T_1 V_151 , T_1 V_70 )
{
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_24 ( V_153 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_145 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_145 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_70 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_68 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_68 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_151 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_47 ;
}
static void F_75 ( struct V_39 * V_40 , struct V_51 * V_52 )
{
struct V_48 * V_9 = F_20 ( V_40 ) ;
V_6 V_154 ;
int V_8 ;
V_154 = ( 8 - ( V_52 -> V_58 & 0x7 ) ) % 8 ;
for ( V_8 = 0 ; V_8 < V_154 ; V_8 ++ )
if ( V_9 && V_9 -> V_29 && ( V_8 == 0 ) )
V_52 -> V_141 [ V_52 -> V_58 ++ ] =
F_24 ( V_142 ) |
F_22 ( V_154 - 1 ) ;
else
V_52 -> V_141 [ V_52 -> V_58 ++ ] =
F_24 ( V_142 ) ;
}
static void F_76 ( struct V_39 * V_40 )
{
T_1 V_69 = V_40 -> V_155 . V_156 ;
T_4 V_68 = V_40 -> V_155 . V_57 ;
F_21 ( V_40 , F_24 ( V_63 ) |
F_30 ( 0 ) |
F_31 ( 3 ) |
F_77 ( 1 ) ) ;
F_21 ( V_40 , V_68 & 0xfffffffc ) ;
F_21 ( V_40 , F_27 ( V_68 ) & 0xffffffff ) ;
F_21 ( V_40 , V_69 ) ;
F_21 ( V_40 , 0xfffffff ) ;
F_21 ( V_40 , F_32 ( 0xfff ) |
F_33 ( 4 ) ) ;
}
static void F_78 ( struct V_39 * V_40 ,
unsigned V_53 , T_4 V_157 )
{
F_21 ( V_40 , F_24 ( V_66 ) |
F_35 ( 0xf ) ) ;
if ( V_53 < 8 ) {
F_21 ( V_40 , ( V_158 + V_53 ) ) ;
} else {
F_21 ( V_40 , ( V_159 + V_53 - 8 ) ) ;
}
F_21 ( V_40 , V_157 >> 12 ) ;
F_21 ( V_40 , F_24 ( V_66 ) |
F_35 ( 0xf ) ) ;
F_21 ( V_40 , V_160 ) ;
F_21 ( V_40 , 1 << V_53 ) ;
F_21 ( V_40 , F_24 ( V_63 ) |
F_30 ( 0 ) |
F_31 ( 0 ) ) ;
F_21 ( V_40 , V_160 << 2 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , 0 ) ;
F_21 ( V_40 , F_32 ( 0xfff ) |
F_33 ( 10 ) ) ;
}
static int F_79 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
V_2 -> V_9 . V_10 = V_162 ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_84 ( void * V_161 )
{
struct V_39 * V_40 ;
int V_98 , V_8 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
V_98 = F_85 ( V_2 , 224 , & V_2 -> V_9 . V_163 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_85 ( V_2 , 241 , & V_2 -> V_9 . V_164 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_85 ( V_2 , 247 , & V_2 -> V_9 . V_164 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_6 ( V_2 ) ;
if ( V_98 ) {
F_59 ( L_16 ) ;
return V_98 ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ ) {
V_40 = & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_40 -> V_165 = NULL ;
V_40 -> V_166 = false ;
sprintf ( V_40 -> V_167 , L_17 , V_8 ) ;
V_98 = F_86 ( V_2 , V_40 , 1024 ,
& V_2 -> V_9 . V_163 ,
( V_8 == 0 ) ?
V_168 :
V_169 ) ;
if ( V_98 )
return V_98 ;
}
return V_98 ;
}
static int F_87 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
F_88 ( & V_2 -> V_9 . V_11 [ V_8 ] . V_40 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_89 ( void * V_161 )
{
int V_98 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
F_1 ( V_2 ) ;
V_98 = F_53 ( V_2 ) ;
if ( V_98 )
return V_98 ;
return V_98 ;
}
static int F_90 ( void * V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
F_41 ( V_2 , false ) ;
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
V_6 V_132 = F_16 ( V_170 ) ;
if ( V_132 & ( V_171 |
V_172 ) )
return false ;
return true ;
}
static int F_94 ( void * V_161 )
{
unsigned V_8 ;
V_6 V_132 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_136 ; V_8 ++ ) {
V_132 = F_16 ( V_170 ) & ( V_171 |
V_172 ) ;
if ( ! V_132 )
return 0 ;
F_95 ( 1 ) ;
}
return - V_144 ;
}
static int F_96 ( void * V_161 )
{
V_6 V_173 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
V_6 V_132 = F_16 ( V_170 ) ;
if ( V_132 & V_171 ) {
V_132 = F_16 ( V_92 + V_174 ) ;
V_132 = F_29 ( V_132 , V_93 , V_94 , 0 ) ;
F_18 ( V_92 + V_174 , V_132 ) ;
V_173 |= V_175 ;
}
if ( V_132 & V_172 ) {
V_132 = F_16 ( V_92 + V_176 ) ;
V_132 = F_29 ( V_132 , V_93 , V_94 , 0 ) ;
F_18 ( V_92 + V_176 , V_132 ) ;
V_173 |= V_177 ;
}
if ( V_173 ) {
V_132 = F_16 ( V_178 ) ;
V_132 |= V_173 ;
F_97 ( V_2 -> V_22 , L_18 , V_132 ) ;
F_18 ( V_178 , V_132 ) ;
V_132 = F_16 ( V_178 ) ;
F_95 ( 50 ) ;
V_132 &= ~ V_173 ;
F_18 ( V_178 , V_132 ) ;
V_132 = F_16 ( V_178 ) ;
F_95 ( 50 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_179 * V_146 ,
unsigned type ,
enum V_180 V_181 )
{
V_6 V_182 ;
switch ( type ) {
case V_168 :
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
case V_169 :
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
static int F_99 ( struct V_1 * V_2 ,
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
F_100 ( & V_2 -> V_9 . V_11 [ 0 ] . V_40 ) ;
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
F_100 ( & V_2 -> V_9 . V_11 [ 1 ] . V_40 ) ;
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
static int F_101 ( struct V_1 * V_2 ,
struct V_179 * V_188 ,
struct V_189 * V_190 )
{
F_59 ( L_20 ) ;
F_102 ( & V_2 -> V_194 ) ;
return 0 ;
}
static int F_103 ( void * V_161 ,
enum V_195 V_181 )
{
return 0 ;
}
static int F_104 ( void * V_161 ,
enum V_196 V_181 )
{
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
V_2 -> V_9 . V_11 [ V_8 ] . V_40 . V_49 = & V_197 ;
}
static void F_83 ( struct V_1 * V_2 )
{
V_2 -> V_9 . V_163 . V_198 = V_199 ;
V_2 -> V_9 . V_163 . V_49 = & V_200 ;
V_2 -> V_9 . V_164 . V_49 = & V_201 ;
}
static void F_105 ( struct V_51 * V_52 ,
T_4 V_202 ,
T_4 V_203 ,
T_1 V_204 )
{
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_24 ( V_148 ) |
F_61 ( V_149 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_204 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = 0 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_202 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_202 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_203 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_203 ) ;
}
static void F_106 ( struct V_51 * V_52 ,
T_1 V_205 ,
T_4 V_203 ,
T_1 V_204 )
{
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_24 ( V_206 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_26 ( V_203 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = F_27 ( V_203 ) ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_205 ;
V_52 -> V_141 [ V_52 -> V_58 ++ ] = V_204 ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 . V_207 == NULL ) {
V_2 -> V_79 . V_207 = & V_208 ;
V_2 -> V_79 . V_80 = & V_2 -> V_9 . V_11 [ 0 ] . V_40 ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned V_8 ;
if ( V_2 -> V_209 . V_210 == NULL ) {
V_2 -> V_209 . V_210 = & V_211 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 ; V_8 ++ )
V_2 -> V_209 . V_212 [ V_8 ] =
& V_2 -> V_9 . V_11 [ V_8 ] . V_40 ;
V_2 -> V_209 . V_213 = V_2 -> V_9 . V_10 ;
}
}
