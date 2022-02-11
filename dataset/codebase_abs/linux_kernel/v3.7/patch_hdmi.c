static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( V_2 -> V_6 [ V_4 ] . V_3 == V_3 )
return V_4 ;
F_2 ( V_7 L_1 , V_3 ) ;
return - V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( & V_2 -> V_11 [ V_4 ] . V_12 [ 0 ] == V_10 )
return V_4 ;
F_2 ( V_7 L_2 , V_10 ) ;
return - V_8 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ )
if ( V_2 -> V_16 [ V_14 ] . V_13 == V_13 )
return V_14 ;
F_2 ( V_7 L_3 , V_13 ) ;
return - V_8 ;
}
static int F_5 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_18 ) ;
struct V_1 * V_2 ;
int V_4 ;
V_2 = V_22 -> V_2 ;
V_20 -> type = V_23 ;
V_4 = V_18 -> V_24 ;
V_20 -> V_25 = V_2 -> V_6 [ V_4 ] . V_26 . V_27 ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_21 * V_22 = F_6 ( V_18 ) ;
struct V_1 * V_2 ;
int V_4 ;
V_2 = V_22 -> V_2 ;
V_4 = V_18 -> V_24 ;
memcpy ( V_29 -> V_30 . V_31 . V_32 ,
V_2 -> V_6 [ V_4 ] . V_26 . V_33 , V_34 ) ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 , int V_4 ,
int V_35 )
{
struct V_17 * V_36 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
V_36 = F_9 ( & V_38 , V_22 ) ;
if ( ! V_36 )
return - V_39 ;
V_36 -> V_24 = V_4 ;
V_36 -> V_40 . V_35 = V_35 ;
V_37 = F_10 ( V_22 , V_2 -> V_6 [ V_4 ] . V_3 , V_36 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static void F_11 ( struct V_21 * V_22 , T_1 V_3 ,
int * V_41 , int * V_42 )
{
int V_43 ;
V_43 = F_12 ( V_22 , V_3 , 0 ,
V_44 , 0 ) ;
* V_41 = V_43 >> 5 ;
* V_42 = V_43 & 0x1f ;
}
static void F_13 ( struct V_21 * V_22 , T_1 V_3 ,
int V_41 , int V_42 )
{
int V_43 ;
V_43 = ( V_41 << 5 ) | ( V_42 & 0x1f ) ;
F_14 ( V_22 , V_3 , 0 , V_45 , V_43 ) ;
}
static void F_15 ( struct V_21 * V_22 , T_1 V_3 ,
unsigned char V_43 )
{
F_14 ( V_22 , V_3 , 0 , V_46 , V_43 ) ;
}
static void F_16 ( struct V_21 * V_22 , T_1 V_3 )
{
if ( F_17 ( V_22 , V_3 ) & V_47 )
F_14 ( V_22 , V_3 , 0 ,
V_48 , V_49 ) ;
F_14 ( V_22 , V_3 , 0 ,
V_50 , 0 ) ;
}
static int F_18 ( struct V_21 * V_22 , T_1 V_13 )
{
return 1 + F_12 ( V_22 , V_13 , 0 ,
V_51 , 0 ) ;
}
static void F_19 ( struct V_21 * V_22 ,
T_1 V_13 , int V_52 )
{
if ( V_52 != F_18 ( V_22 , V_13 ) )
F_14 ( V_22 , V_13 , 0 ,
V_53 , V_52 - 1 ) ;
}
static void F_20 ( void )
{
int V_54 , V_55 ;
struct V_56 * V_57 ;
for ( V_54 = 0 ; V_54 < F_21 ( V_58 ) ; V_54 ++ ) {
V_57 = V_58 + V_54 ;
V_57 -> V_59 = 0 ;
V_57 -> V_60 = 0 ;
for ( V_55 = 0 ; V_55 < F_21 ( V_57 -> V_61 ) ; V_55 ++ )
if ( V_57 -> V_61 [ V_55 ] ) {
V_57 -> V_59 ++ ;
V_57 -> V_60 |= V_57 -> V_61 [ V_55 ] ;
}
}
}
static int F_22 ( int V_62 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < F_21 ( V_58 ) ; V_54 ++ ) {
if ( V_58 [ V_54 ] . V_63 == V_62 )
break;
}
return V_54 ;
}
static int F_23 ( struct V_64 * V_65 , int V_59 )
{
int V_54 ;
int V_62 = 0 ;
int V_60 = 0 ;
char V_66 [ V_67 ] ;
if ( V_59 <= 2 )
return 0 ;
for ( V_54 = 0 ; V_54 < F_21 ( V_68 ) ; V_54 ++ ) {
if ( V_65 -> V_69 & ( 1 << V_54 ) )
V_60 |= V_68 [ V_54 ] ;
}
for ( V_54 = 0 ; V_54 < F_21 ( V_58 ) ; V_54 ++ ) {
if ( V_59 == V_58 [ V_54 ] . V_59 &&
( V_60 & V_58 [ V_54 ] . V_60 ) ==
V_58 [ V_54 ] . V_60 ) {
V_62 = V_58 [ V_54 ] . V_63 ;
break;
}
}
F_24 ( V_65 -> V_69 , V_66 , sizeof( V_66 ) ) ;
F_25 ( L_4 ,
V_62 , V_59 , V_66 ) ;
return V_62 ;
}
static void F_26 ( struct V_21 * V_22 ,
T_1 V_3 )
{
#ifdef F_27
int V_54 ;
int V_70 ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_70 = F_12 ( V_22 , V_3 , 0 ,
V_71 , V_54 ) ;
F_28 ( V_72 L_5 ,
V_70 >> 4 , V_70 & 0xf ) ;
}
#endif
}
static void F_29 ( struct V_21 * V_22 ,
T_1 V_3 ,
bool V_73 ,
int V_62 )
{
int V_54 ;
int V_37 ;
int V_74 ;
int V_75 [ 8 ] ;
V_74 = F_22 ( V_62 ) ;
if ( V_76 [ V_62 ] [ 1 ] == 0 ) {
for ( V_54 = 0 ; V_54 < V_58 [ V_74 ] . V_59 ; V_54 ++ )
V_76 [ V_62 ] [ V_54 ] = V_54 | ( V_54 << 4 ) ;
for (; V_54 < 8 ; V_54 ++ )
V_76 [ V_62 ] [ V_54 ] = 0xf | ( V_54 << 4 ) ;
}
if ( V_73 ) {
for ( V_54 = 0 ; V_54 < V_58 [ V_74 ] . V_59 ; V_54 ++ )
V_75 [ V_54 ] = V_54 | ( V_54 << 4 ) ;
for (; V_54 < 8 ; V_54 ++ )
V_75 [ V_54 ] = 0xf | ( V_54 << 4 ) ;
}
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_37 = F_14 ( V_22 , V_3 , 0 ,
V_77 ,
V_73 ? V_75 [ V_54 ] : V_76 [ V_62 ] [ V_54 ] ) ;
if ( V_37 ) {
F_25 ( V_78
L_6 ) ;
break;
}
}
F_26 ( V_22 , V_3 ) ;
}
static int F_30 ( unsigned char V_79 )
{
struct V_80 * V_81 = V_82 ;
for (; V_81 -> V_83 ; V_81 ++ ) {
if ( V_81 -> V_83 == V_79 )
return V_81 -> V_60 ;
}
return 0 ;
}
static int F_31 ( unsigned char V_79 )
{
struct V_80 * V_81 = V_82 ;
for (; V_81 -> V_83 ; V_81 ++ ) {
if ( V_81 -> V_83 == V_79 )
return V_81 -> V_84 ;
}
return 0x0f ;
}
static int F_32 ( unsigned char V_79 )
{
struct V_80 * V_81 = V_82 ;
for (; V_81 -> V_83 ; V_81 ++ ) {
if ( V_81 -> V_84 == V_79 )
return V_81 -> V_83 ;
}
return 0 ;
}
static int F_33 ( int V_85 )
{
struct V_80 * V_81 = V_82 ;
for (; V_81 -> V_83 ; V_81 ++ ) {
if ( V_81 -> V_60 == V_85 )
return V_81 -> V_83 ;
}
return 0 ;
}
static int F_34 ( int V_52 , unsigned char * V_83 )
{
int V_54 , V_86 = 0 , V_60 = 0 ;
for ( V_54 = 0 ; V_54 < V_52 ; V_54 ++ ) {
int V_87 = F_30 ( V_83 [ V_54 ] ) ;
if ( V_87 ) {
V_60 |= V_87 ;
V_86 ++ ;
}
}
for ( V_54 = 0 ; V_54 < F_21 ( V_58 ) ; V_54 ++ ) {
if ( ( V_52 == V_58 [ V_54 ] . V_59 ||
V_86 == V_58 [ V_54 ] . V_59 ) &&
( V_60 & V_58 [ V_54 ] . V_60 ) ==
V_58 [ V_54 ] . V_60 )
return V_58 [ V_54 ] . V_63 ;
}
return - 1 ;
}
static int F_35 ( struct V_21 * V_22 ,
T_1 V_3 ,
int V_52 , unsigned char * V_83 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
int V_43 , V_37 ;
if ( V_54 < V_52 )
V_43 = F_31 ( V_83 [ V_54 ] ) ;
else
V_43 = 0xf ;
V_43 |= ( V_54 << 4 ) ;
V_37 = F_14 ( V_22 , V_3 , 0 ,
V_77 , V_43 ) ;
if ( V_37 )
return - V_8 ;
}
return 0 ;
}
static void F_36 ( unsigned char * V_83 , int V_62 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
if ( V_54 < V_58 [ V_62 ] . V_59 )
V_83 [ V_54 ] = F_32 ( ( V_76 [ V_62 ] [ V_54 ] >> 4 ) & 0x0f ) ;
else
V_83 [ V_54 ] = 0 ;
}
}
static void F_37 ( struct V_21 * V_22 ,
T_1 V_3 , bool V_73 , int V_62 ,
int V_59 , unsigned char * V_83 )
{
if ( ! V_73 && V_83 ) {
F_35 ( V_22 , V_3 ,
V_59 , V_83 ) ;
} else {
F_29 ( V_22 , V_3 , V_73 , V_62 ) ;
F_36 ( V_83 , V_62 ) ;
}
}
static void F_38 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_14 ( V_22 , V_3 , 0 , V_88 ,
V_89 ) ;
}
static void F_39 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_14 ( V_22 , V_3 , 0 , V_88 ,
V_90 ) ;
}
static void F_40 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_27
int V_54 ;
int V_91 ;
V_91 = F_41 ( V_22 , V_3 ) ;
F_28 ( V_72 L_7 , V_91 ) ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_91 = F_12 ( V_22 , V_3 , 0 ,
V_92 , V_54 ) ;
F_28 ( V_72 L_8 , V_54 , V_91 ) ;
}
#endif
}
static void F_42 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_43
int V_54 , V_55 ;
int V_91 ;
int V_93 , V_94 ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_91 = F_12 ( V_22 , V_3 , 0 ,
V_92 , V_54 ) ;
if ( V_91 == 0 )
continue;
F_13 ( V_22 , V_3 , V_54 , 0x0 ) ;
for ( V_55 = 1 ; V_55 < 1000 ; V_55 ++ ) {
F_15 ( V_22 , V_3 , 0x0 ) ;
F_11 ( V_22 , V_3 , & V_93 , & V_94 ) ;
if ( V_93 != V_54 )
F_44 ( V_95 L_9 ,
V_94 , V_93 , V_54 ) ;
if ( V_94 == 0 )
break;
}
F_44 ( V_95
L_10 ,
V_54 , V_91 , V_55 ) ;
}
#endif
}
static void F_45 ( struct V_96 * V_97 )
{
T_2 * V_31 = ( T_2 * ) V_97 ;
T_2 V_98 = 0 ;
int V_54 ;
V_97 -> V_99 = 0 ;
for ( V_54 = 0 ; V_54 < sizeof( * V_97 ) ; V_54 ++ )
V_98 += V_31 [ V_54 ] ;
V_97 -> V_99 = - V_98 ;
}
static void F_46 ( struct V_21 * V_22 ,
T_1 V_3 ,
T_2 * V_100 , int V_91 )
{
int V_54 ;
F_40 ( V_22 , V_3 ) ;
F_42 ( V_22 , V_3 ) ;
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ )
F_15 ( V_22 , V_3 , V_100 [ V_54 ] ) ;
}
static bool F_47 ( struct V_21 * V_22 , T_1 V_3 ,
T_2 * V_100 , int V_91 )
{
T_2 V_43 ;
int V_54 ;
if ( F_12 ( V_22 , V_3 , 0 , V_101 , 0 )
!= V_89 )
return false ;
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_54 = 0 ; V_54 < V_91 ; V_54 ++ ) {
V_43 = F_12 ( V_22 , V_3 , 0 ,
V_102 , 0 ) ;
if ( V_43 != V_100 [ V_54 ] )
return false ;
}
return true ;
}
static void F_48 ( struct V_21 * V_22 , int V_4 ,
bool V_73 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_106 -> V_3 ;
int V_59 = V_104 -> V_107 -> V_59 ;
struct V_64 * V_65 ;
int V_62 ;
union V_108 V_109 ;
V_65 = & V_2 -> V_6 [ V_4 ] . V_26 ;
if ( ! V_65 -> V_110 )
return;
if ( ! V_73 && V_106 -> V_111 )
V_62 = F_34 ( V_59 , V_106 -> V_112 ) ;
else
V_62 = F_23 ( V_65 , V_59 ) ;
if ( V_62 < 0 )
V_62 = 0 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
if ( V_65 -> V_113 == 0 ) {
struct V_96 * V_97 = & V_109 . V_114 ;
V_97 -> type = 0x84 ;
V_97 -> V_115 = 0x01 ;
V_97 -> V_116 = 0x0a ;
V_97 -> V_117 = V_59 - 1 ;
V_97 -> V_118 = V_62 ;
F_45 ( V_97 ) ;
} else if ( V_65 -> V_113 == 1 ) {
struct V_119 * V_120 = & V_109 . V_121 ;
V_120 -> type = 0x84 ;
V_120 -> V_116 = 0x1b ;
V_120 -> V_115 = 0x11 << 2 ;
V_120 -> V_117 = V_59 - 1 ;
V_120 -> V_118 = V_62 ;
} else {
F_44 ( L_11 ,
V_3 ) ;
return;
}
if ( ! F_47 ( V_22 , V_3 , V_109 . V_31 ,
sizeof( V_109 ) ) ) {
F_25 ( L_12
L_13 ,
V_3 ,
V_59 ) ;
F_37 ( V_22 , V_3 , V_73 , V_62 ,
V_59 , V_106 -> V_112 ) ;
F_39 ( V_22 , V_3 ) ;
F_46 ( V_22 , V_3 ,
V_109 . V_31 , sizeof( V_109 ) ) ;
F_38 ( V_22 , V_3 ) ;
} else {
if ( V_106 -> V_73 != V_73 )
F_37 ( V_22 , V_3 , V_73 , V_62 ,
V_59 , V_106 -> V_112 ) ;
}
V_106 -> V_73 = V_73 ;
}
static void F_49 ( struct V_21 * V_22 , unsigned int V_122 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_123 = V_122 >> V_124 ;
int V_3 ;
int V_4 ;
struct V_125 * V_126 ;
V_126 = F_50 ( V_22 , V_123 ) ;
if ( ! V_126 )
return;
V_3 = V_126 -> V_127 ;
V_126 -> V_128 = 1 ;
F_51 ( V_129 ,
L_14 ,
V_22 -> V_130 , V_3 ,
! ! ( V_122 & V_131 ) , ! ! ( V_122 & V_132 ) ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
F_52 ( & V_2 -> V_6 [ V_4 ] , 1 ) ;
F_53 ( V_22 ) ;
}
static void F_54 ( struct V_21 * V_22 , unsigned int V_122 )
{
int V_123 = V_122 >> V_124 ;
int V_133 = ( V_122 & V_134 ) >> V_135 ;
int V_136 = ! ! ( V_122 & V_137 ) ;
int V_138 = ! ! ( V_122 & V_139 ) ;
F_28 ( V_95
L_15 ,
V_22 -> V_130 ,
V_123 ,
V_133 ,
V_136 ,
V_138 ) ;
if ( V_136 )
;
if ( V_138 )
;
}
static void F_55 ( struct V_21 * V_22 , unsigned int V_122 )
{
int V_123 = V_122 >> V_124 ;
int V_133 = ( V_122 & V_134 ) >> V_135 ;
if ( ! F_50 ( V_22 , V_123 ) ) {
F_44 ( V_95 L_16 , V_123 ) ;
return;
}
if ( V_133 == 0 )
F_49 ( V_22 , V_122 ) ;
else
F_54 ( V_22 , V_122 ) ;
}
static int F_56 ( struct V_21 * V_22 , T_1 V_13 ,
T_1 V_3 , T_3 V_140 , int V_141 )
{
int V_142 ;
int V_143 = 0 ;
if ( F_57 ( V_22 , V_3 ) & V_144 ) {
V_142 = F_12 ( V_22 , V_3 , 0 ,
V_145 , 0 ) ;
V_143 = V_142 & ~ V_146 ;
if ( F_58 ( V_141 ) )
V_143 |= V_147 ;
else
V_143 |= V_148 ;
F_25 ( L_17
L_18 ,
V_3 ,
V_142 == V_143 ? L_19 : L_20 ,
V_143 ) ;
if ( V_142 != V_143 )
F_14 ( V_22 , V_3 , 0 ,
V_50 ,
V_143 ) ;
}
if ( F_58 ( V_141 ) && ! V_143 ) {
F_25 ( L_21 ) ;
return - V_8 ;
}
F_59 ( V_22 , V_13 , V_140 , 0 , V_141 ) ;
return 0 ;
}
static int F_60 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_149 * V_107 = V_104 -> V_107 ;
int V_4 , V_14 , V_150 = 0 ;
struct V_105 * V_106 ;
struct V_64 * V_65 ;
struct V_151 * V_152 = NULL ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_61 ( V_4 < 0 ) )
return - V_8 ;
V_106 = & V_2 -> V_6 [ V_4 ] ;
V_65 = & V_106 -> V_26 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_152 = & V_2 -> V_16 [ V_14 ] ;
if ( V_152 -> V_153 )
continue;
for ( V_150 = 0 ; V_150 < V_106 -> V_154 ; V_150 ++ )
if ( V_106 -> V_155 [ V_150 ] == V_152 -> V_13 )
break;
if ( V_150 == V_106 -> V_154 )
continue;
break;
}
if ( V_14 == V_2 -> V_15 )
return - V_156 ;
V_152 -> V_153 = 1 ;
V_10 -> V_127 = V_152 -> V_13 ;
F_14 ( V_22 , V_106 -> V_3 , 0 ,
V_157 ,
V_150 ) ;
F_62 ( V_22 , V_4 , V_152 -> V_13 ) ;
V_10 -> V_158 = V_152 -> V_158 ;
V_10 -> V_159 = V_152 -> V_159 ;
V_10 -> V_160 = V_152 -> V_160 ;
V_10 -> V_161 = V_152 -> V_161 ;
V_10 -> V_162 = V_152 -> V_162 ;
if ( ! V_163 && V_65 -> V_164 ) {
F_63 ( V_65 , V_10 ) ;
if ( V_10 -> V_158 > V_10 -> V_159 ||
! V_10 -> V_160 || ! V_10 -> V_161 )
return - V_156 ;
}
V_107 -> V_165 . V_158 = V_10 -> V_158 ;
V_107 -> V_165 . V_159 = V_10 -> V_159 ;
V_107 -> V_165 . V_161 = V_10 -> V_161 ;
V_107 -> V_165 . V_160 = V_10 -> V_160 ;
F_64 ( V_104 -> V_107 , 0 ,
V_166 , 2 ) ;
return 0 ;
}
static int F_65 ( struct V_21 * V_22 , int V_4 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_106 -> V_3 ;
if ( ! ( F_17 ( V_22 , V_3 ) & V_167 ) ) {
F_2 ( V_7
L_22
L_23 ,
V_3 , F_17 ( V_22 , V_3 ) ) ;
return - V_8 ;
}
V_106 -> V_154 = F_66 ( V_22 , V_3 ,
V_106 -> V_155 ,
V_168 ) ;
return 0 ;
}
static void F_52 ( struct V_105 * V_106 , int V_169 )
{
struct V_21 * V_22 = V_106 -> V_22 ;
struct V_64 * V_65 = & V_106 -> V_26 ;
T_1 V_3 = V_106 -> V_3 ;
int V_170 = F_67 ( V_22 , V_3 ) ;
bool V_164 = false ;
memset ( V_65 , 0 , F_68 ( struct V_64 , V_33 ) ) ;
V_65 -> V_110 = ! ! ( V_170 & V_171 ) ;
if ( V_65 -> V_110 )
V_164 = ! ! ( V_170 & V_172 ) ;
F_51 ( V_129 ,
L_24 ,
V_22 -> V_130 , V_3 , V_65 -> V_110 , V_164 ) ;
if ( V_164 ) {
if ( ! F_69 ( V_65 , V_22 , V_3 ) )
F_70 ( V_65 ) ;
else if ( V_169 ) {
F_71 ( V_22 -> V_173 -> V_174 ,
& V_106 -> V_175 ,
F_72 ( 300 ) ) ;
}
}
}
static void F_73 ( struct V_176 * V_175 )
{
struct V_105 * V_106 =
F_74 ( F_75 ( V_175 ) , struct V_105 , V_175 ) ;
if ( V_106 -> V_177 ++ > 6 )
V_106 -> V_177 = 0 ;
F_52 ( V_106 , V_106 -> V_177 ) ;
}
static int F_76 ( struct V_21 * V_22 , T_1 V_3 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned int V_178 , V_179 ;
int V_4 ;
struct V_105 * V_106 ;
int V_37 ;
V_178 = F_77 ( V_22 , V_3 , V_180 ) ;
if ( ! ( V_178 & ( V_181 | V_182 ) ) )
return 0 ;
V_179 = F_12 ( V_22 , V_3 , 0 ,
V_183 , 0 ) ;
if ( F_78 ( V_179 ) == V_184 )
return 0 ;
if ( F_61 ( V_2 -> V_5 >= V_185 ) )
return - V_186 ;
V_4 = V_2 -> V_5 ;
V_106 = & V_2 -> V_6 [ V_4 ] ;
V_106 -> V_3 = V_3 ;
V_106 -> V_73 = false ;
V_37 = F_65 ( V_22 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_79 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 ;
struct V_151 * V_152 ;
unsigned int V_187 ;
int V_37 ;
if ( F_61 ( V_2 -> V_15 >= V_188 ) )
return - V_186 ;
V_187 = F_17 ( V_22 , V_13 ) ;
V_187 = F_80 ( V_187 ) ;
V_14 = V_2 -> V_15 ;
V_152 = & V_2 -> V_16 [ V_14 ] ;
V_152 -> V_13 = V_13 ;
V_152 -> V_158 = 2 ;
if ( V_187 <= 16 ) {
V_152 -> V_159 = V_187 ;
if ( V_187 > V_2 -> V_159 )
V_2 -> V_159 = V_187 ;
}
V_37 = F_81 ( V_22 , V_13 ,
& V_152 -> V_160 ,
& V_152 -> V_161 ,
& V_152 -> V_162 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_15 ++ ;
return 0 ;
}
static int F_82 ( struct V_21 * V_22 )
{
T_1 V_127 ;
int V_54 , V_189 ;
V_189 = F_83 ( V_22 , V_22 -> V_190 , & V_127 ) ;
if ( ! V_127 || V_189 < 0 ) {
F_2 ( V_7 L_25 ) ;
return - V_8 ;
}
for ( V_54 = 0 ; V_54 < V_189 ; V_54 ++ , V_127 ++ ) {
unsigned int V_178 ;
unsigned int type ;
V_178 = F_77 ( V_22 , V_127 , V_191 ) ;
type = F_84 ( V_178 ) ;
if ( ! ( V_178 & V_192 ) )
continue;
switch ( type ) {
case V_193 :
F_79 ( V_22 , V_127 ) ;
break;
case V_194 :
F_76 ( V_22 , V_127 ) ;
break;
}
}
#ifdef F_85
if ( ! ( F_77 ( V_22 , V_22 -> V_190 , V_195 ) &
V_196 ) )
V_22 -> V_173 -> V_197 = 1 ;
#endif
return 0 ;
}
static char * F_86 ( int V_198 )
{
static char V_199 [ V_185 ] [ 8 ] ;
sprintf ( & V_199 [ V_198 ] [ 0 ] , L_26 , V_198 ) ;
return & V_199 [ V_198 ] [ 0 ] ;
}
static bool F_87 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_200 * V_201 ;
bool V_73 ;
F_88 ( & V_22 -> V_202 ) ;
V_201 = F_89 ( V_22 , V_13 ) ;
V_73 = ! ! ( V_201 -> V_203 & V_204 ) ;
F_90 ( & V_22 -> V_202 ) ;
return V_73 ;
}
static int F_91 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_140 ,
unsigned int V_141 ,
struct V_103 * V_104 )
{
T_1 V_13 = V_10 -> V_127 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = F_3 ( V_2 , V_10 ) ;
T_1 V_3 = V_2 -> V_6 [ V_4 ] . V_3 ;
int V_142 ;
bool V_73 ;
V_73 = F_87 ( V_22 , V_13 ) ;
F_19 ( V_22 , V_13 , V_104 -> V_107 -> V_59 ) ;
F_48 ( V_22 , V_4 , V_73 , V_104 ) ;
V_142 = F_12 ( V_22 , V_3 , 0 ,
V_145 , 0 ) ;
F_14 ( V_22 , V_3 , 0 ,
V_50 , V_142 | V_205 ) ;
return F_56 ( V_22 , V_13 , V_3 , V_140 , V_141 ) ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_103 * V_104 )
{
F_93 ( V_22 , V_10 -> V_127 ) ;
return 0 ;
}
static int F_94 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 , V_4 ;
struct V_151 * V_152 ;
struct V_105 * V_106 ;
int V_142 ;
if ( V_10 -> V_127 ) {
V_14 = F_4 ( V_2 , V_10 -> V_127 ) ;
if ( F_61 ( V_14 < 0 ) )
return - V_8 ;
V_152 = & V_2 -> V_16 [ V_14 ] ;
F_61 ( ! V_152 -> V_153 ) ;
V_152 -> V_153 = 0 ;
V_10 -> V_127 = 0 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_61 ( V_4 < 0 ) )
return - V_8 ;
V_106 = & V_2 -> V_6 [ V_4 ] ;
V_142 = F_12 ( V_22 , V_106 -> V_3 , 0 ,
V_145 , 0 ) ;
F_14 ( V_22 , V_106 -> V_3 , 0 ,
V_50 ,
V_142 & ~ V_205 ) ;
F_95 ( V_22 , V_4 ) ;
V_106 -> V_111 = false ;
memset ( V_106 -> V_112 , 0 , sizeof( V_106 -> V_112 ) ) ;
}
return 0 ;
}
static int F_96 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_206 * V_207 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_207 -> V_208 ;
struct V_1 * V_2 = V_22 -> V_2 ;
V_20 -> type = V_209 ;
V_20 -> V_25 = V_2 -> V_159 ;
V_20 -> V_30 . integer . V_210 = 0 ;
V_20 -> V_30 . integer . V_211 = V_212 ;
return 0 ;
}
static int F_97 ( struct V_17 * V_18 , int V_213 ,
unsigned int V_91 , unsigned int T_4 * V_214 )
{
struct V_206 * V_207 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_207 -> V_208 ;
struct V_1 * V_2 = V_22 -> V_2 ;
const unsigned int V_215 =
V_216 | V_217 | V_218 | V_219 | V_220 | V_221 | V_222 | V_223 ;
unsigned int T_4 * V_224 ;
int V_52 , V_25 = 0 ;
if ( V_91 < 8 )
return - V_39 ;
if ( F_98 ( V_225 , V_214 ) )
return - V_226 ;
V_91 -= 8 ;
V_224 = V_214 + 2 ;
for ( V_52 = 2 ; V_52 <= V_2 -> V_159 ; V_52 ++ ) {
int V_54 , V_79 ;
struct V_56 * V_227 ;
V_227 = V_58 ;
for ( V_54 = 0 ; V_54 < F_21 ( V_58 ) ; V_54 ++ , V_227 ++ ) {
int V_228 = V_52 * 4 ;
if ( V_227 -> V_59 != V_52 )
continue;
if ( V_227 -> V_60 & ~ V_215 )
continue;
if ( V_91 < 8 )
return - V_39 ;
if ( F_98 ( V_229 , V_224 ) ||
F_98 ( V_228 , V_224 + 1 ) )
return - V_226 ;
V_224 += 2 ;
V_91 -= 8 ;
V_25 += 8 ;
if ( V_91 < V_228 )
return - V_39 ;
V_91 -= V_228 ;
V_25 += V_228 ;
for ( V_79 = 7 ; V_79 >= 0 ; V_79 -- ) {
int V_85 = V_227 -> V_61 [ V_79 ] ;
if ( ! V_85 )
continue;
if ( F_98 ( F_33 ( V_85 ) , V_224 ) )
return - V_226 ;
V_224 ++ ;
}
}
}
if ( F_98 ( V_25 , V_214 + 1 ) )
return - V_226 ;
return 0 ;
}
static int F_99 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_206 * V_207 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_207 -> V_208 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = V_18 -> V_24 ;
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
int V_54 ;
for ( V_54 = 0 ; V_54 < F_21 ( V_106 -> V_112 ) ; V_54 ++ )
V_29 -> V_30 . integer . V_30 [ V_54 ] = V_106 -> V_112 [ V_54 ] ;
return 0 ;
}
static int F_100 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_206 * V_207 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_207 -> V_208 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = V_18 -> V_24 ;
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
unsigned int V_230 ;
struct V_103 * V_104 ;
unsigned char V_112 [ 8 ] ;
int V_54 , V_62 , V_231 = 0 ;
V_230 = F_101 ( V_18 , & V_29 -> V_40 ) ;
V_104 = F_102 ( V_207 , V_230 ) ;
if ( ! V_104 || ! V_104 -> V_107 )
return - V_232 ;
switch ( V_104 -> V_107 -> V_203 -> V_233 ) {
case V_234 :
case V_235 :
break;
case V_236 :
V_231 = 1 ;
break;
default:
return - V_237 ;
}
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
for ( V_54 = 0 ; V_54 < F_21 ( V_112 ) ; V_54 ++ )
V_112 [ V_54 ] = V_29 -> V_30 . integer . V_30 [ V_54 ] ;
if ( ! memcmp ( V_112 , V_106 -> V_112 , sizeof( V_112 ) ) )
return 0 ;
V_62 = F_34 ( F_21 ( V_112 ) , V_112 ) ;
if ( V_62 < 0 )
return - V_8 ;
V_106 -> V_111 = true ;
memcpy ( V_106 -> V_112 , V_112 , sizeof( V_112 ) ) ;
if ( V_231 )
F_48 ( V_22 , V_4 , V_106 -> V_73 ,
V_104 ) ;
return 0 ;
}
static int F_103 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_238 * V_207 ;
struct V_9 * V_239 ;
V_207 = & V_2 -> V_11 [ V_4 ] ;
V_207 -> V_240 = F_86 ( V_4 ) ;
V_207 -> V_241 = V_242 ;
V_207 -> V_243 = true ;
V_239 = & V_207 -> V_12 [ V_244 ] ;
V_239 -> V_245 = 1 ;
V_239 -> V_246 = V_247 ;
}
V_22 -> V_248 = V_2 -> V_5 ;
V_22 -> V_249 = V_2 -> V_11 ;
return 0 ;
}
static int F_104 ( struct V_21 * V_22 , int V_4 )
{
char V_250 [ 32 ] = L_27 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
int V_251 = V_2 -> V_11 [ V_4 ] . V_35 ;
if ( V_251 > 0 )
sprintf ( V_250 + strlen ( V_250 ) , L_28 , V_251 ) ;
return F_105 ( V_22 , V_106 -> V_3 , V_250 , 0 ) ;
}
static int F_106 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
V_37 = F_104 ( V_22 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_107 ( V_22 ,
V_106 -> V_3 ,
V_106 -> V_155 [ 0 ] ) ;
if ( V_37 < 0 )
return V_37 ;
F_95 ( V_22 , V_4 ) ;
V_37 = F_8 ( V_22 ,
V_4 ,
V_2 -> V_11 [ V_4 ] . V_35 ) ;
if ( V_37 < 0 )
return V_37 ;
F_52 ( V_106 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_206 * V_112 ;
struct V_17 * V_36 ;
int V_54 ;
V_37 = F_108 ( V_22 -> V_249 [ V_4 ] . V_252 ,
V_244 ,
NULL , 0 , V_4 , & V_112 ) ;
if ( V_37 < 0 )
return V_37 ;
V_112 -> V_208 = V_22 ;
V_36 = V_112 -> V_36 ;
for ( V_54 = 0 ; V_54 < V_36 -> V_25 ; V_54 ++ )
V_36 -> V_253 [ V_54 ] . V_254 |= V_255 ;
V_36 -> V_207 = F_96 ;
V_36 -> V_256 = F_99 ;
V_36 -> V_257 = F_100 ;
V_36 -> V_214 . V_79 = F_97 ;
}
return 0 ;
}
static int F_109 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
struct V_64 * V_65 = & V_106 -> V_26 ;
V_106 -> V_22 = V_22 ;
F_110 ( & V_106 -> V_175 , F_73 ) ;
F_111 ( V_22 , V_65 , V_4 ) ;
}
return 0 ;
}
static int F_112 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_106 -> V_3 ;
F_16 ( V_22 , V_3 ) ;
F_113 ( V_22 , V_3 , V_3 ) ;
}
return 0 ;
}
static void F_114 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = & V_2 -> V_6 [ V_4 ] ;
struct V_64 * V_65 = & V_106 -> V_26 ;
F_115 ( & V_106 -> V_175 ) ;
F_116 ( V_22 , V_65 ) ;
}
F_117 ( V_22 -> V_173 -> V_174 ) ;
F_118 ( V_2 ) ;
}
static int F_119 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_120 ( sizeof( * V_2 ) , V_258 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
if ( F_82 ( V_22 ) < 0 ) {
V_22 -> V_2 = NULL ;
F_118 ( V_2 ) ;
return - V_8 ;
}
V_22 -> V_259 = V_260 ;
F_109 ( V_22 ) ;
F_20 () ;
return 0 ;
}
static int F_121 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_238 * V_207 = V_2 -> V_11 ;
unsigned int V_187 ;
struct V_9 * V_239 ;
V_22 -> V_248 = 1 ;
V_22 -> V_249 = V_207 ;
V_187 = F_17 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
V_187 = F_80 ( V_187 ) ;
V_207 -> V_240 = F_86 ( 0 ) ;
V_207 -> V_241 = V_242 ;
V_239 = & V_207 -> V_12 [ V_244 ] ;
* V_239 = V_2 -> V_261 ;
V_239 -> V_127 = V_2 -> V_16 [ 0 ] . V_13 ;
if ( V_239 -> V_159 <= 2 && V_187 && V_187 <= 16 )
V_239 -> V_159 = V_187 ;
return 0 ;
}
static void F_122 ( struct V_21 * V_22 ,
unsigned int V_122 )
{
F_123 ( V_22 ) ;
F_53 ( V_22 ) ;
}
static int F_124 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
V_37 = F_107 ( V_22 ,
V_2 -> V_16 [ 0 ] . V_13 ,
V_2 -> V_16 [ 0 ] . V_13 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_125 ( V_22 , 0 ) ;
}
static int F_126 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
T_1 V_262 = V_2 -> V_6 [ 0 ] . V_3 ;
F_14 ( V_22 , V_262 , 0 ,
V_50 , V_205 ) ;
if ( F_17 ( V_22 , V_262 ) & V_47 )
F_14 ( V_22 , V_262 , 0 , V_48 ,
V_49 ) ;
F_113 ( V_22 , V_262 , V_262 ) ;
return 0 ;
}
static void F_127 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_118 ( V_2 ) ;
}
static int F_128 ( struct V_21 * V_22 )
{
F_129 ( V_22 , V_263 ) ;
return 0 ;
}
static int F_130 ( struct V_21 * V_22 )
{
F_129 ( V_22 , V_264 ) ;
return 0 ;
}
static int F_131 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_265 * V_266 = NULL ;
switch ( V_22 -> V_267 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_266 = & V_268 ;
break;
case 0x10de0007 :
V_266 = & V_269 ;
break;
default:
break;
}
if ( V_266 != NULL ) {
V_265 ( V_104 -> V_107 , 0 ,
V_166 ,
V_266 ) ;
} else {
F_64 ( V_104 -> V_107 , 0 ,
V_166 , 2 ) ;
}
return F_132 ( V_22 , & V_2 -> V_270 ) ;
}
static int F_133 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_134 ( V_22 , & V_2 -> V_270 ) ;
}
static int F_135 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_140 ,
unsigned int V_141 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_136 ( V_22 , & V_2 -> V_270 ,
V_140 , V_141 , V_104 ) ;
}
static int F_137 ( struct V_21 * V_22 ,
T_1 V_13 , T_1 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_120 ( sizeof( * V_2 ) , V_258 ) ;
if ( ! V_2 )
return - V_39 ;
V_22 -> V_2 = V_2 ;
V_2 -> V_270 . V_271 = 0 ;
V_2 -> V_270 . V_272 = 2 ;
V_2 -> V_270 . V_273 = V_13 ;
V_2 -> V_15 = 1 ;
V_2 -> V_5 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_13 ;
V_2 -> V_6 [ 0 ] . V_3 = V_3 ;
V_2 -> V_261 = V_274 ;
V_22 -> V_259 = V_275 ;
return 0 ;
}
static void F_138 ( struct V_21 * V_22 ,
int V_59 )
{
unsigned int V_276 ;
int V_277 = V_59 ? ( V_59 - 1 ) : 1 ;
switch ( V_59 ) {
default:
case 0 :
case 2 :
V_276 = 0x00 ;
break;
case 4 :
V_276 = 0x08 ;
break;
case 6 :
V_276 = 0x0b ;
break;
case 8 :
V_276 = 0x13 ;
break;
}
F_14 ( V_22 , 0x1 , 0 ,
V_278 , V_276 ) ;
F_14 ( V_22 , 0x1 , 0 ,
V_279 ,
( 0x71 - V_277 - V_276 ) ) ;
}
static int F_139 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_54 ;
F_14 ( V_22 , V_280 ,
0 , V_281 , 0 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
F_14 ( V_22 , V_282 [ V_54 ] , 0 ,
V_281 , 0 ) ;
F_14 ( V_22 , V_282 [ V_54 ] , 0 ,
V_283 , 0 ) ;
}
F_138 ( V_22 , 8 ) ;
return F_134 ( V_22 , & V_2 -> V_270 ) ;
}
static int F_140 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_140 ,
unsigned int V_141 ,
struct V_103 * V_104 )
{
int V_52 ;
unsigned int V_284 , V_285 ;
int V_54 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_200 * V_201 ;
F_88 ( & V_22 -> V_202 ) ;
V_201 = F_89 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
V_52 = V_104 -> V_107 -> V_59 ;
V_284 = 0x2 ;
if ( V_22 -> V_286 && ( V_201 -> V_287 & V_288 ) )
F_14 ( V_22 ,
V_280 ,
0 ,
V_289 ,
V_201 -> V_287 & ~ V_288 & 0xff ) ;
F_14 ( V_22 , V_280 , 0 ,
V_281 , ( V_140 << 4 ) | 0x0 ) ;
F_14 ( V_22 , V_280 , 0 ,
V_283 , V_141 ) ;
if ( V_22 -> V_286 && ( V_201 -> V_287 & V_288 ) ) {
F_14 ( V_22 ,
V_280 ,
0 ,
V_289 ,
V_201 -> V_287 & 0xff ) ;
F_14 ( V_22 ,
V_280 ,
0 ,
V_290 , V_284 ) ;
}
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
if ( V_52 == 2 )
V_285 = 0 ;
else
V_285 = V_54 * 2 ;
if ( V_22 -> V_286 &&
( V_201 -> V_287 & V_288 ) )
F_14 ( V_22 ,
V_282 [ V_54 ] ,
0 ,
V_289 ,
V_201 -> V_287 & ~ V_288 & 0xff ) ;
F_14 ( V_22 ,
V_282 [ V_54 ] ,
0 ,
V_281 ,
( V_140 << 4 ) | V_285 ) ;
F_14 ( V_22 ,
V_282 [ V_54 ] ,
0 ,
V_283 ,
V_141 ) ;
if ( V_22 -> V_286 &&
( V_201 -> V_287 & V_288 ) ) {
F_14 ( V_22 ,
V_282 [ V_54 ] ,
0 ,
V_289 ,
V_201 -> V_287 & 0xff ) ;
F_14 ( V_22 ,
V_282 [ V_54 ] ,
0 ,
V_290 , V_284 ) ;
}
}
F_138 ( V_22 , V_52 ) ;
F_90 ( & V_22 -> V_202 ) ;
return 0 ;
}
static int F_141 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_137 ( V_22 , V_280 ,
V_291 ) ;
if ( V_37 < 0 )
return V_37 ;
V_22 -> V_259 . V_292 = F_128 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_261 . V_160 = V_293 ;
V_2 -> V_261 . V_162 = V_294 ;
V_2 -> V_261 . V_161 = V_295 ;
return 0 ;
}
static int F_142 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 = F_121 ( V_22 ) ;
V_2 -> V_11 [ 0 ] . V_243 = true ;
return V_37 ;
}
static int F_143 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_206 * V_112 ;
int V_37 ;
V_37 = F_124 ( V_22 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_108 ( V_2 -> V_11 [ 0 ] . V_252 ,
V_244 ,
V_296 , 8 , 0 , & V_112 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_22 -> V_267 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_112 -> V_297 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_112 -> V_297 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_144 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_141 ( V_22 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_270 . V_272 = 8 ;
V_2 -> V_261 = V_298 ;
V_22 -> V_259 . V_292 = F_130 ;
V_22 -> V_259 . V_299 = F_142 ;
V_22 -> V_259 . V_300 = F_143 ;
F_138 ( V_22 , 8 ) ;
return 0 ;
}
static int F_145 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_140 ,
unsigned int V_141 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_187 = V_104 -> V_107 -> V_59 ;
int V_54 , V_37 ;
V_37 = F_135 ( V_10 , V_22 , V_140 , V_141 ,
V_104 ) ;
if ( V_37 < 0 )
return V_37 ;
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_53 , V_187 - 1 ) ;
for ( V_54 = 0 ; V_54 < V_187 ; V_54 ++ ) {
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_77 ,
( V_54 << 4 ) | V_54 ) ;
}
return 0 ;
}
static int F_146 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_137 ( V_22 , V_301 , V_302 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_261 . V_246 . V_303 = F_145 ;
return 0 ;
}
static int F_147 ( struct V_21 * V_22 )
{
return F_137 ( V_22 , V_304 , V_305 ) ;
}
static int T_5 F_148 ( void )
{
return F_149 ( & V_306 ) ;
}
static void T_6 F_150 ( void )
{
F_151 ( & V_306 ) ;
}
