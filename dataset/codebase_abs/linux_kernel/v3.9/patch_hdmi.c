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
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 * V_24 ;
int V_4 ;
V_20 -> type = V_25 ;
V_4 = V_18 -> V_26 ;
V_24 = & V_2 -> V_6 [ V_4 ] . V_27 ;
F_7 ( & V_24 -> V_28 ) ;
V_20 -> V_29 = V_24 -> V_30 ? V_24 -> V_31 : 0 ;
F_8 ( & V_24 -> V_28 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
struct V_32 * V_33 )
{
struct V_21 * V_22 = F_6 ( V_18 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 * V_24 ;
int V_4 ;
V_4 = V_18 -> V_26 ;
V_24 = & V_2 -> V_6 [ V_4 ] . V_27 ;
F_7 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_31 > F_10 ( V_33 -> V_34 . V_35 . V_36 ) ) {
F_8 ( & V_24 -> V_28 ) ;
F_11 () ;
return - V_8 ;
}
memset ( V_33 -> V_34 . V_35 . V_36 , 0 ,
F_10 ( V_33 -> V_34 . V_35 . V_36 ) ) ;
if ( V_24 -> V_30 )
memcpy ( V_33 -> V_34 . V_35 . V_36 , V_24 -> V_37 ,
V_24 -> V_31 ) ;
F_8 ( & V_24 -> V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 , int V_4 ,
int V_38 )
{
struct V_17 * V_39 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_40 ;
V_39 = F_13 ( & V_41 , V_22 ) ;
if ( ! V_39 )
return - V_42 ;
V_39 -> V_26 = V_4 ;
V_39 -> V_43 . V_38 = V_38 ;
V_40 = F_14 ( V_22 , V_2 -> V_6 [ V_4 ] . V_3 , V_39 ) ;
if ( V_40 < 0 )
return V_40 ;
V_2 -> V_6 [ V_4 ] . V_44 = V_39 ;
return 0 ;
}
static void F_15 ( struct V_21 * V_22 , T_1 V_3 ,
int * V_45 , int * V_46 )
{
int V_47 ;
V_47 = F_16 ( V_22 , V_3 , 0 ,
V_48 , 0 ) ;
* V_45 = V_47 >> 5 ;
* V_46 = V_47 & 0x1f ;
}
static void F_17 ( struct V_21 * V_22 , T_1 V_3 ,
int V_45 , int V_46 )
{
int V_47 ;
V_47 = ( V_45 << 5 ) | ( V_46 & 0x1f ) ;
F_18 ( V_22 , V_3 , 0 , V_49 , V_47 ) ;
}
static void F_19 ( struct V_21 * V_22 , T_1 V_3 ,
unsigned char V_47 )
{
F_18 ( V_22 , V_3 , 0 , V_50 , V_47 ) ;
}
static void F_20 ( struct V_21 * V_22 , T_1 V_3 )
{
if ( F_21 ( V_22 , V_3 ) & V_51 )
F_18 ( V_22 , V_3 , 0 ,
V_52 , V_53 ) ;
F_18 ( V_22 , V_3 , 0 ,
V_54 , V_55 ) ;
}
static int F_22 ( struct V_21 * V_22 , T_1 V_13 )
{
return 1 + F_16 ( V_22 , V_13 , 0 ,
V_56 , 0 ) ;
}
static void F_23 ( struct V_21 * V_22 ,
T_1 V_13 , int V_57 )
{
if ( V_57 != F_22 ( V_22 , V_13 ) )
F_18 ( V_22 , V_13 , 0 ,
V_58 , V_57 - 1 ) ;
}
static void F_24 ( void )
{
int V_59 , V_60 ;
struct V_61 * V_62 ;
for ( V_59 = 0 ; V_59 < F_10 ( V_63 ) ; V_59 ++ ) {
V_62 = V_63 + V_59 ;
V_62 -> V_64 = 0 ;
V_62 -> V_65 = 0 ;
for ( V_60 = 0 ; V_60 < F_10 ( V_62 -> V_66 ) ; V_60 ++ )
if ( V_62 -> V_66 [ V_60 ] ) {
V_62 -> V_64 ++ ;
V_62 -> V_65 |= V_62 -> V_66 [ V_60 ] ;
}
}
}
static int F_25 ( int V_67 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < F_10 ( V_63 ) ; V_59 ++ ) {
if ( V_63 [ V_59 ] . V_68 == V_67 )
break;
}
return V_59 ;
}
static int F_26 ( struct V_23 * V_24 , int V_64 )
{
int V_59 ;
int V_67 = 0 ;
int V_65 = 0 ;
char V_69 [ V_70 ] ;
if ( V_64 <= 2 )
return 0 ;
for ( V_59 = 0 ; V_59 < F_10 ( V_71 ) ; V_59 ++ ) {
if ( V_24 -> V_72 . V_73 & ( 1 << V_59 ) )
V_65 |= V_71 [ V_59 ] ;
}
for ( V_59 = 0 ; V_59 < F_10 ( V_63 ) ; V_59 ++ ) {
if ( V_64 == V_63 [ V_59 ] . V_64 &&
( V_65 & V_63 [ V_59 ] . V_65 ) ==
V_63 [ V_59 ] . V_65 ) {
V_67 = V_63 [ V_59 ] . V_68 ;
break;
}
}
F_27 ( V_24 -> V_72 . V_73 , V_69 , sizeof( V_69 ) ) ;
F_28 ( L_4 ,
V_67 , V_64 , V_69 ) ;
return V_67 ;
}
static void F_29 ( struct V_21 * V_22 ,
T_1 V_3 )
{
#ifdef F_30
int V_59 ;
int V_74 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
V_74 = F_16 ( V_22 , V_3 , 0 ,
V_75 , V_59 ) ;
F_31 ( V_76 L_5 ,
V_74 >> 4 , V_74 & 0xf ) ;
}
#endif
}
static void F_32 ( struct V_21 * V_22 ,
T_1 V_3 ,
bool V_77 ,
int V_67 )
{
int V_59 ;
int V_40 ;
int V_78 ;
int V_79 [ 8 ] ;
V_78 = F_25 ( V_67 ) ;
if ( V_80 [ V_67 ] [ 1 ] == 0 ) {
for ( V_59 = 0 ; V_59 < V_63 [ V_78 ] . V_64 ; V_59 ++ )
V_80 [ V_67 ] [ V_59 ] = V_59 | ( V_59 << 4 ) ;
for (; V_59 < 8 ; V_59 ++ )
V_80 [ V_67 ] [ V_59 ] = 0xf | ( V_59 << 4 ) ;
}
if ( V_77 ) {
for ( V_59 = 0 ; V_59 < V_63 [ V_78 ] . V_64 ; V_59 ++ )
V_79 [ V_59 ] = V_59 | ( V_59 << 4 ) ;
for (; V_59 < 8 ; V_59 ++ )
V_79 [ V_59 ] = 0xf | ( V_59 << 4 ) ;
}
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
V_40 = F_18 ( V_22 , V_3 , 0 ,
V_81 ,
V_77 ? V_79 [ V_59 ] : V_80 [ V_67 ] [ V_59 ] ) ;
if ( V_40 ) {
F_28 ( V_82
L_6 ) ;
break;
}
}
F_29 ( V_22 , V_3 ) ;
}
static int F_33 ( unsigned char V_83 )
{
struct V_84 * V_85 = V_86 ;
for (; V_85 -> V_87 ; V_85 ++ ) {
if ( V_85 -> V_87 == V_83 )
return V_85 -> V_65 ;
}
return 0 ;
}
static int F_34 ( unsigned char V_83 )
{
struct V_84 * V_85 = V_86 ;
for (; V_85 -> V_87 ; V_85 ++ ) {
if ( V_85 -> V_87 == V_83 )
return V_85 -> V_88 ;
}
return 0x0f ;
}
static int F_35 ( unsigned char V_83 )
{
struct V_84 * V_85 = V_86 ;
for (; V_85 -> V_87 ; V_85 ++ ) {
if ( V_85 -> V_88 == V_83 )
return V_85 -> V_87 ;
}
return 0 ;
}
static int F_36 ( int V_89 )
{
struct V_84 * V_85 = V_86 ;
for (; V_85 -> V_87 ; V_85 ++ ) {
if ( V_85 -> V_65 == V_89 )
return V_85 -> V_87 ;
}
return 0 ;
}
static int F_37 ( int V_57 , unsigned char * V_87 )
{
int V_59 , V_90 = 0 , V_65 = 0 ;
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
int V_91 = F_33 ( V_87 [ V_59 ] ) ;
if ( V_91 ) {
V_65 |= V_91 ;
V_90 ++ ;
}
}
for ( V_59 = 0 ; V_59 < F_10 ( V_63 ) ; V_59 ++ ) {
if ( ( V_57 == V_63 [ V_59 ] . V_64 ||
V_90 == V_63 [ V_59 ] . V_64 ) &&
( V_65 & V_63 [ V_59 ] . V_65 ) ==
V_63 [ V_59 ] . V_65 )
return V_63 [ V_59 ] . V_68 ;
}
return - 1 ;
}
static int F_38 ( struct V_21 * V_22 ,
T_1 V_3 ,
int V_57 , unsigned char * V_87 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
int V_47 , V_40 ;
if ( V_59 < V_57 )
V_47 = F_34 ( V_87 [ V_59 ] ) ;
else
V_47 = 0xf ;
V_47 |= ( V_59 << 4 ) ;
V_40 = F_18 ( V_22 , V_3 , 0 ,
V_81 , V_47 ) ;
if ( V_40 )
return - V_8 ;
}
return 0 ;
}
static void F_39 ( unsigned char * V_87 , int V_67 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_59 < V_63 [ V_67 ] . V_64 )
V_87 [ V_59 ] = F_35 ( ( V_80 [ V_67 ] [ V_59 ] >> 4 ) & 0x0f ) ;
else
V_87 [ V_59 ] = 0 ;
}
}
static void F_40 ( struct V_21 * V_22 ,
T_1 V_3 , bool V_77 , int V_67 ,
int V_64 , unsigned char * V_87 ,
bool V_92 )
{
if ( ! V_77 && V_92 ) {
F_38 ( V_22 , V_3 ,
V_64 , V_87 ) ;
} else {
F_32 ( V_22 , V_3 , V_77 , V_67 ) ;
F_39 ( V_87 , V_67 ) ;
}
}
static void F_41 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_17 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_18 ( V_22 , V_3 , 0 , V_93 ,
V_94 ) ;
}
static void F_42 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_17 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_18 ( V_22 , V_3 , 0 , V_93 ,
V_95 ) ;
}
static void F_43 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_30
int V_59 ;
int V_96 ;
V_96 = F_44 ( V_22 , V_3 ) ;
F_31 ( V_76 L_7 , V_96 ) ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
V_96 = F_16 ( V_22 , V_3 , 0 ,
V_97 , V_59 ) ;
F_31 ( V_76 L_8 , V_59 , V_96 ) ;
}
#endif
}
static void F_45 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_46
int V_59 , V_60 ;
int V_96 ;
int V_98 , V_99 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
V_96 = F_16 ( V_22 , V_3 , 0 ,
V_97 , V_59 ) ;
if ( V_96 == 0 )
continue;
F_17 ( V_22 , V_3 , V_59 , 0x0 ) ;
for ( V_60 = 1 ; V_60 < 1000 ; V_60 ++ ) {
F_19 ( V_22 , V_3 , 0x0 ) ;
F_15 ( V_22 , V_3 , & V_98 , & V_99 ) ;
if ( V_98 != V_59 )
F_47 ( V_100 L_9 ,
V_99 , V_98 , V_59 ) ;
if ( V_99 == 0 )
break;
}
F_47 ( V_100
L_10 ,
V_59 , V_96 , V_60 ) ;
}
#endif
}
static void F_48 ( struct V_101 * V_102 )
{
T_2 * V_35 = ( T_2 * ) V_102 ;
T_2 V_103 = 0 ;
int V_59 ;
V_102 -> V_104 = 0 ;
for ( V_59 = 0 ; V_59 < sizeof( * V_102 ) ; V_59 ++ )
V_103 += V_35 [ V_59 ] ;
V_102 -> V_104 = - V_103 ;
}
static void F_49 ( struct V_21 * V_22 ,
T_1 V_3 ,
T_2 * V_105 , int V_96 )
{
int V_59 ;
F_43 ( V_22 , V_3 ) ;
F_45 ( V_22 , V_3 ) ;
F_17 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_59 = 0 ; V_59 < V_96 ; V_59 ++ )
F_19 ( V_22 , V_3 , V_105 [ V_59 ] ) ;
}
static bool F_50 ( struct V_21 * V_22 , T_1 V_3 ,
T_2 * V_105 , int V_96 )
{
T_2 V_47 ;
int V_59 ;
if ( F_16 ( V_22 , V_3 , 0 , V_106 , 0 )
!= V_94 )
return false ;
F_17 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_59 = 0 ; V_59 < V_96 ; V_59 ++ ) {
V_47 = F_16 ( V_22 , V_3 , 0 ,
V_107 , 0 ) ;
if ( V_47 != V_105 [ V_59 ] )
return false ;
}
return true ;
}
static void F_51 ( struct V_21 * V_22 , int V_4 ,
bool V_77 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_111 -> V_3 ;
int V_64 = V_109 -> V_112 -> V_64 ;
struct V_23 * V_24 ;
int V_67 ;
union V_113 V_114 ;
V_24 = & V_2 -> V_6 [ V_4 ] . V_27 ;
if ( ! V_24 -> V_115 )
return;
if ( ! V_77 && V_111 -> V_92 )
V_67 = F_37 ( V_64 , V_111 -> V_116 ) ;
else
V_67 = F_26 ( V_24 , V_64 ) ;
if ( V_67 < 0 )
V_67 = 0 ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
if ( V_24 -> V_72 . V_117 == 0 ) {
struct V_101 * V_102 = & V_114 . V_118 ;
V_102 -> type = 0x84 ;
V_102 -> V_119 = 0x01 ;
V_102 -> V_120 = 0x0a ;
V_102 -> V_121 = V_64 - 1 ;
V_102 -> V_122 = V_67 ;
F_48 ( V_102 ) ;
} else if ( V_24 -> V_72 . V_117 == 1 ) {
struct V_123 * V_124 = & V_114 . V_125 ;
V_124 -> type = 0x84 ;
V_124 -> V_120 = 0x1b ;
V_124 -> V_119 = 0x11 << 2 ;
V_124 -> V_121 = V_64 - 1 ;
V_124 -> V_122 = V_67 ;
} else {
F_47 ( L_11 ,
V_3 ) ;
return;
}
if ( ! F_50 ( V_22 , V_3 , V_114 . V_35 ,
sizeof( V_114 ) ) ) {
F_28 ( L_12
L_13 ,
V_3 ,
V_64 ) ;
F_40 ( V_22 , V_3 , V_77 , V_67 ,
V_64 , V_111 -> V_116 ,
V_111 -> V_92 ) ;
F_42 ( V_22 , V_3 ) ;
F_49 ( V_22 , V_3 ,
V_114 . V_35 , sizeof( V_114 ) ) ;
F_41 ( V_22 , V_3 ) ;
} else {
if ( V_111 -> V_77 != V_77 )
F_40 ( V_22 , V_3 , V_77 , V_67 ,
V_64 , V_111 -> V_116 ,
V_111 -> V_92 ) ;
}
V_111 -> V_77 = V_77 ;
}
static void F_52 ( struct V_21 * V_22 , unsigned int V_126 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_127 = V_126 >> V_128 ;
int V_3 ;
int V_4 ;
struct V_129 * V_130 ;
V_130 = F_53 ( V_22 , V_127 ) ;
if ( ! V_130 )
return;
V_3 = V_130 -> V_131 ;
V_130 -> V_132 = 1 ;
F_54 ( V_133 ,
L_14 ,
V_22 -> V_134 , V_3 ,
! ! ( V_126 & V_135 ) , ! ! ( V_126 & V_136 ) ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
F_55 ( & V_2 -> V_6 [ V_4 ] , 1 ) ;
F_56 ( V_22 ) ;
}
static void F_57 ( struct V_21 * V_22 , unsigned int V_126 )
{
int V_127 = V_126 >> V_128 ;
int V_137 = ( V_126 & V_138 ) >> V_139 ;
int V_140 = ! ! ( V_126 & V_141 ) ;
int V_142 = ! ! ( V_126 & V_143 ) ;
F_31 ( V_100
L_15 ,
V_22 -> V_134 ,
V_127 ,
V_137 ,
V_140 ,
V_142 ) ;
if ( V_140 )
;
if ( V_142 )
;
}
static void F_58 ( struct V_21 * V_22 , unsigned int V_126 )
{
int V_127 = V_126 >> V_128 ;
int V_137 = ( V_126 & V_138 ) >> V_139 ;
if ( ! F_53 ( V_22 , V_127 ) ) {
F_47 ( V_100 L_16 , V_127 ) ;
return;
}
if ( V_137 == 0 )
F_52 ( V_22 , V_126 ) ;
else
F_57 ( V_22 , V_126 ) ;
}
static int F_59 ( struct V_21 * V_22 , T_1 V_13 ,
T_1 V_3 , T_3 V_144 , int V_145 )
{
int V_146 ;
int V_147 = 0 ;
if ( F_60 ( V_22 , V_3 ) & V_148 ) {
V_146 = F_16 ( V_22 , V_3 , 0 ,
V_149 , 0 ) ;
V_147 = V_146 & ~ V_150 ;
if ( F_61 ( V_145 ) )
V_147 |= V_151 ;
else
V_147 |= V_152 ;
F_28 ( L_17
L_18 ,
V_3 ,
V_146 == V_147 ? L_19 : L_20 ,
V_147 ) ;
if ( V_146 != V_147 )
F_18 ( V_22 , V_3 , 0 ,
V_54 ,
V_147 ) ;
}
if ( F_61 ( V_145 ) && ! V_147 ) {
F_28 ( L_21 ) ;
return - V_8 ;
}
F_62 ( V_22 , V_13 , V_144 , 0 , V_145 ) ;
return 0 ;
}
static int F_63 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_153 * V_112 = V_109 -> V_112 ;
int V_4 , V_14 , V_154 = 0 ;
struct V_110 * V_111 ;
struct V_23 * V_24 ;
struct V_155 * V_156 = NULL ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_64 ( V_4 < 0 ) )
return - V_8 ;
V_111 = & V_2 -> V_6 [ V_4 ] ;
V_24 = & V_111 -> V_27 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_156 = & V_2 -> V_16 [ V_14 ] ;
if ( V_156 -> V_157 )
continue;
for ( V_154 = 0 ; V_154 < V_111 -> V_158 ; V_154 ++ )
if ( V_111 -> V_159 [ V_154 ] == V_156 -> V_13 )
break;
if ( V_154 == V_111 -> V_158 )
continue;
break;
}
if ( V_14 == V_2 -> V_15 )
return - V_160 ;
V_156 -> V_157 = 1 ;
V_10 -> V_131 = V_156 -> V_13 ;
F_18 ( V_22 , V_111 -> V_3 , 0 ,
V_161 ,
V_154 ) ;
F_65 ( V_22 , V_4 , V_156 -> V_13 ) ;
V_10 -> V_162 = V_156 -> V_162 ;
V_10 -> V_163 = V_156 -> V_163 ;
V_10 -> V_164 = V_156 -> V_164 ;
V_10 -> V_165 = V_156 -> V_165 ;
V_10 -> V_166 = V_156 -> V_166 ;
if ( ! V_167 && V_24 -> V_30 ) {
F_66 ( & V_24 -> V_72 , V_10 ) ;
if ( V_10 -> V_162 > V_10 -> V_163 ||
! V_10 -> V_164 || ! V_10 -> V_165 ) {
V_156 -> V_157 = 0 ;
V_10 -> V_131 = 0 ;
F_67 ( V_22 , V_4 ) ;
return - V_160 ;
}
}
V_112 -> V_168 . V_162 = V_10 -> V_162 ;
V_112 -> V_168 . V_163 = V_10 -> V_163 ;
V_112 -> V_168 . V_165 = V_10 -> V_165 ;
V_112 -> V_168 . V_164 = V_10 -> V_164 ;
F_68 ( V_109 -> V_112 , 0 ,
V_169 , 2 ) ;
return 0 ;
}
static int F_69 ( struct V_21 * V_22 , int V_4 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_111 -> V_3 ;
if ( ! ( F_21 ( V_22 , V_3 ) & V_170 ) ) {
F_2 ( V_7
L_22
L_23 ,
V_3 , F_21 ( V_22 , V_3 ) ) ;
return - V_8 ;
}
V_111 -> V_158 = F_70 ( V_22 , V_3 ,
V_111 -> V_159 ,
V_171 ) ;
return 0 ;
}
static void F_55 ( struct V_110 * V_111 , int V_172 )
{
struct V_21 * V_22 = V_111 -> V_22 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 * V_24 = & V_2 -> V_173 ;
struct V_23 * V_174 = & V_111 -> V_27 ;
T_1 V_3 = V_111 -> V_3 ;
int V_175 = F_71 ( V_22 , V_3 ) ;
bool V_176 = false ;
bool V_177 = false ;
V_174 -> V_115 = ! ! ( V_175 & V_178 ) ;
if ( V_174 -> V_115 )
V_24 -> V_30 = ! ! ( V_175 & V_179 ) ;
else
V_24 -> V_30 = false ;
F_54 ( V_133 ,
L_24 ,
V_22 -> V_134 , V_3 , V_174 -> V_115 , V_24 -> V_30 ) ;
if ( V_24 -> V_30 ) {
if ( F_72 ( V_22 , V_3 , V_24 -> V_37 ,
& V_24 -> V_31 ) < 0 )
V_24 -> V_30 = false ;
else {
memset ( & V_24 -> V_72 , 0 , sizeof( struct V_180 ) ) ;
if ( F_73 ( & V_24 -> V_72 , V_24 -> V_37 ,
V_24 -> V_31 ) < 0 )
V_24 -> V_30 = false ;
}
if ( V_24 -> V_30 ) {
F_74 ( & V_24 -> V_72 ) ;
V_176 = true ;
}
else if ( V_172 ) {
F_75 ( V_22 -> V_181 -> V_182 ,
& V_111 -> V_183 ,
F_76 ( 300 ) ) ;
return;
}
}
F_7 ( & V_174 -> V_28 ) ;
if ( V_174 -> V_30 && ! V_24 -> V_30 ) {
V_176 = true ;
V_177 = true ;
}
if ( V_176 ) {
V_174 -> V_30 = V_24 -> V_30 ;
V_177 = V_174 -> V_31 != V_24 -> V_31 ||
memcmp ( V_174 -> V_37 , V_24 -> V_37 ,
V_24 -> V_31 ) != 0 ;
if ( V_177 )
memcpy ( V_174 -> V_37 , V_24 -> V_37 ,
V_24 -> V_31 ) ;
V_174 -> V_31 = V_24 -> V_31 ;
V_174 -> V_72 = V_24 -> V_72 ;
}
F_8 ( & V_174 -> V_28 ) ;
if ( V_177 )
F_77 ( V_22 -> V_181 -> V_184 ,
V_185 | V_186 ,
& V_111 -> V_44 -> V_43 ) ;
}
static void F_78 ( struct V_187 * V_183 )
{
struct V_110 * V_111 =
F_79 ( F_80 ( V_183 ) , struct V_110 , V_183 ) ;
if ( V_111 -> V_188 ++ > 6 )
V_111 -> V_188 = 0 ;
F_55 ( V_111 , V_111 -> V_188 ) ;
}
static int F_81 ( struct V_21 * V_22 , T_1 V_3 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned int V_189 , V_190 ;
int V_4 ;
struct V_110 * V_111 ;
int V_40 ;
V_189 = F_60 ( V_22 , V_3 ) ;
if ( ! ( V_189 & ( V_191 | V_192 ) ) )
return 0 ;
V_190 = F_82 ( V_22 , V_3 ) ;
if ( F_83 ( V_190 ) == V_193 )
return 0 ;
if ( F_64 ( V_2 -> V_5 >= V_194 ) )
return - V_195 ;
if ( V_22 -> V_196 == 0x80862807 )
F_84 ( V_22 , V_3 ) ;
V_4 = V_2 -> V_5 ;
V_111 = & V_2 -> V_6 [ V_4 ] ;
V_111 -> V_3 = V_3 ;
V_111 -> V_77 = false ;
V_40 = F_69 ( V_22 , V_4 ) ;
if ( V_40 < 0 )
return V_40 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_85 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 ;
struct V_155 * V_156 ;
unsigned int V_197 ;
int V_40 ;
if ( F_64 ( V_2 -> V_15 >= V_198 ) )
return - V_195 ;
V_197 = F_21 ( V_22 , V_13 ) ;
V_197 = F_86 ( V_197 ) ;
V_14 = V_2 -> V_15 ;
V_156 = & V_2 -> V_16 [ V_14 ] ;
V_156 -> V_13 = V_13 ;
V_156 -> V_162 = 2 ;
if ( V_197 <= 16 ) {
V_156 -> V_163 = V_197 ;
if ( V_197 > V_2 -> V_163 )
V_2 -> V_163 = V_197 ;
}
V_40 = F_87 ( V_22 , V_13 ,
& V_156 -> V_164 ,
& V_156 -> V_165 ,
& V_156 -> V_166 ) ;
if ( V_40 < 0 )
return V_40 ;
V_2 -> V_199 [ V_2 -> V_15 ++ ] = V_13 ;
return 0 ;
}
static int F_88 ( struct V_21 * V_22 )
{
T_1 V_131 ;
int V_59 , V_200 ;
V_200 = F_89 ( V_22 , V_22 -> V_201 , & V_131 ) ;
if ( ! V_131 || V_200 < 0 ) {
F_2 ( V_7 L_25 ) ;
return - V_8 ;
}
for ( V_59 = 0 ; V_59 < V_200 ; V_59 ++ , V_131 ++ ) {
unsigned int V_189 ;
unsigned int type ;
V_189 = F_21 ( V_22 , V_131 ) ;
type = F_90 ( V_189 ) ;
if ( ! ( V_189 & V_202 ) )
continue;
switch ( type ) {
case V_203 :
F_85 ( V_22 , V_131 ) ;
break;
case V_204 :
F_81 ( V_22 , V_131 ) ;
break;
}
}
#ifdef F_91
if ( V_22 -> V_196 == 0x80862806 )
V_22 -> V_181 -> V_205 = 1 ;
else if ( ! ( F_92 ( V_22 , V_22 -> V_201 , V_206 ) &
V_207 ) )
V_22 -> V_181 -> V_205 = 1 ;
#endif
return 0 ;
}
static char * F_93 ( int V_208 )
{
static char V_209 [ V_194 ] [ 8 ] ;
sprintf ( & V_209 [ V_208 ] [ 0 ] , L_26 , V_208 ) ;
return & V_209 [ V_208 ] [ 0 ] ;
}
static bool F_94 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_210 * V_211 ;
bool V_77 ;
F_7 ( & V_22 -> V_212 ) ;
V_211 = F_95 ( V_22 , V_13 ) ;
V_77 = ! ! ( V_211 -> V_213 & V_214 ) ;
F_8 ( & V_22 -> V_212 ) ;
return V_77 ;
}
static int F_96 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_144 ,
unsigned int V_145 ,
struct V_108 * V_109 )
{
T_1 V_13 = V_10 -> V_131 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = F_3 ( V_2 , V_10 ) ;
T_1 V_3 = V_2 -> V_6 [ V_4 ] . V_3 ;
bool V_77 ;
V_77 = F_94 ( V_22 , V_13 ) ;
F_23 ( V_22 , V_13 , V_109 -> V_112 -> V_64 ) ;
F_51 ( V_22 , V_4 , V_77 , V_109 ) ;
return F_59 ( V_22 , V_13 , V_3 , V_144 , V_145 ) ;
}
static int F_97 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_108 * V_109 )
{
F_98 ( V_22 , V_10 -> V_131 ) ;
return 0 ;
}
static int F_99 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 , V_4 ;
struct V_155 * V_156 ;
struct V_110 * V_111 ;
if ( V_10 -> V_131 ) {
V_14 = F_4 ( V_2 , V_10 -> V_131 ) ;
if ( F_64 ( V_14 < 0 ) )
return - V_8 ;
V_156 = & V_2 -> V_16 [ V_14 ] ;
F_64 ( ! V_156 -> V_157 ) ;
V_156 -> V_157 = 0 ;
V_10 -> V_131 = 0 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_64 ( V_4 < 0 ) )
return - V_8 ;
V_111 = & V_2 -> V_6 [ V_4 ] ;
F_67 ( V_22 , V_4 ) ;
V_111 -> V_92 = false ;
memset ( V_111 -> V_116 , 0 , sizeof( V_111 -> V_116 ) ) ;
}
return 0 ;
}
static int F_100 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_215 * V_72 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_72 -> V_216 ;
struct V_1 * V_2 = V_22 -> V_2 ;
V_20 -> type = V_217 ;
V_20 -> V_29 = V_2 -> V_163 ;
V_20 -> V_34 . integer . V_218 = 0 ;
V_20 -> V_34 . integer . V_219 = V_220 ;
return 0 ;
}
static int F_101 ( struct V_17 * V_18 , int V_221 ,
unsigned int V_96 , unsigned int T_4 * V_222 )
{
struct V_215 * V_72 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_72 -> V_216 ;
struct V_1 * V_2 = V_22 -> V_2 ;
const unsigned int V_223 =
V_224 | V_225 | V_226 | V_227 | V_228 | V_229 | V_230 | V_231 ;
unsigned int T_4 * V_232 ;
int V_57 , V_29 = 0 ;
if ( V_96 < 8 )
return - V_42 ;
if ( F_102 ( V_233 , V_222 ) )
return - V_234 ;
V_96 -= 8 ;
V_232 = V_222 + 2 ;
for ( V_57 = 2 ; V_57 <= V_2 -> V_163 ; V_57 ++ ) {
int V_59 , V_83 ;
struct V_61 * V_235 ;
V_235 = V_63 ;
for ( V_59 = 0 ; V_59 < F_10 ( V_63 ) ; V_59 ++ , V_235 ++ ) {
int V_236 = V_57 * 4 ;
if ( V_235 -> V_64 != V_57 )
continue;
if ( V_235 -> V_65 & ~ V_223 )
continue;
if ( V_96 < 8 )
return - V_42 ;
if ( F_102 ( V_237 , V_232 ) ||
F_102 ( V_236 , V_232 + 1 ) )
return - V_234 ;
V_232 += 2 ;
V_96 -= 8 ;
V_29 += 8 ;
if ( V_96 < V_236 )
return - V_42 ;
V_96 -= V_236 ;
V_29 += V_236 ;
for ( V_83 = 7 ; V_83 >= 0 ; V_83 -- ) {
int V_89 = V_235 -> V_66 [ V_83 ] ;
if ( ! V_89 )
continue;
if ( F_102 ( F_36 ( V_89 ) , V_232 ) )
return - V_234 ;
V_232 ++ ;
}
}
}
if ( F_102 ( V_29 , V_222 + 1 ) )
return - V_234 ;
return 0 ;
}
static int F_103 ( struct V_17 * V_18 ,
struct V_32 * V_33 )
{
struct V_215 * V_72 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_72 -> V_216 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = V_18 -> V_26 ;
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
int V_59 ;
for ( V_59 = 0 ; V_59 < F_10 ( V_111 -> V_116 ) ; V_59 ++ )
V_33 -> V_34 . integer . V_34 [ V_59 ] = V_111 -> V_116 [ V_59 ] ;
return 0 ;
}
static int F_104 ( struct V_17 * V_18 ,
struct V_32 * V_33 )
{
struct V_215 * V_72 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_72 -> V_216 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = V_18 -> V_26 ;
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
unsigned int V_238 ;
struct V_108 * V_109 ;
unsigned char V_116 [ 8 ] ;
int V_59 , V_67 , V_239 = 0 ;
V_238 = F_105 ( V_18 , & V_33 -> V_43 ) ;
V_109 = F_106 ( V_72 , V_238 ) ;
if ( ! V_109 || ! V_109 -> V_112 )
return 0 ;
switch ( V_109 -> V_112 -> V_213 -> V_240 ) {
case V_241 :
case V_242 :
break;
case V_243 :
V_239 = 1 ;
break;
default:
return - V_244 ;
}
memset ( V_116 , 0 , sizeof( V_116 ) ) ;
for ( V_59 = 0 ; V_59 < F_10 ( V_116 ) ; V_59 ++ )
V_116 [ V_59 ] = V_33 -> V_34 . integer . V_34 [ V_59 ] ;
if ( ! memcmp ( V_116 , V_111 -> V_116 , sizeof( V_116 ) ) )
return 0 ;
V_67 = F_37 ( F_10 ( V_116 ) , V_116 ) ;
if ( V_67 < 0 )
return - V_8 ;
V_111 -> V_92 = true ;
memcpy ( V_111 -> V_116 , V_116 , sizeof( V_116 ) ) ;
if ( V_239 )
F_51 ( V_22 , V_4 , V_111 -> V_77 ,
V_109 ) ;
return 0 ;
}
static int F_107 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_245 * V_72 ;
struct V_9 * V_246 ;
V_72 = & V_2 -> V_11 [ V_4 ] ;
V_72 -> V_247 = F_93 ( V_4 ) ;
V_72 -> V_248 = V_249 ;
V_72 -> V_250 = true ;
V_246 = & V_72 -> V_12 [ V_251 ] ;
V_246 -> V_252 = 1 ;
V_246 -> V_253 = V_254 ;
}
V_22 -> V_255 = V_2 -> V_5 ;
V_22 -> V_256 = V_2 -> V_11 ;
return 0 ;
}
static int F_108 ( struct V_21 * V_22 , int V_4 )
{
char V_257 [ 32 ] = L_27 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
int V_258 = V_2 -> V_11 [ V_4 ] . V_38 ;
if ( V_258 > 0 )
sprintf ( V_257 + strlen ( V_257 ) , L_28 , V_258 ) ;
if ( ! F_109 ( V_22 , V_111 -> V_3 ) )
strncat ( V_257 , L_29 ,
sizeof( V_257 ) - strlen ( V_257 ) - 1 ) ;
return F_110 ( V_22 , V_111 -> V_3 , V_257 , 0 ) ;
}
static int F_111 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_40 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
V_40 = F_108 ( V_22 , V_4 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_112 ( V_22 ,
V_111 -> V_3 ,
V_111 -> V_159 [ 0 ] ,
V_249 ) ;
if ( V_40 < 0 )
return V_40 ;
F_67 ( V_22 , V_4 ) ;
V_40 = F_12 ( V_22 ,
V_4 ,
V_2 -> V_11 [ V_4 ] . V_38 ) ;
if ( V_40 < 0 )
return V_40 ;
F_55 ( V_111 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_215 * V_116 ;
struct V_17 * V_39 ;
int V_59 ;
V_40 = F_113 ( V_22 -> V_256 [ V_4 ] . V_259 ,
V_251 ,
NULL , 0 , V_4 , & V_116 ) ;
if ( V_40 < 0 )
return V_40 ;
V_116 -> V_216 = V_22 ;
V_39 = V_116 -> V_39 ;
for ( V_59 = 0 ; V_59 < V_39 -> V_29 ; V_59 ++ )
V_39 -> V_260 [ V_59 ] . V_261 |= V_262 ;
V_39 -> V_72 = F_100 ;
V_39 -> V_263 = F_103 ;
V_39 -> V_264 = F_104 ;
V_39 -> V_222 . V_83 = F_101 ;
}
return 0 ;
}
static int F_114 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
struct V_23 * V_24 = & V_111 -> V_27 ;
V_111 -> V_22 = V_22 ;
F_115 ( & V_24 -> V_28 ) ;
F_116 ( & V_111 -> V_183 , F_78 ) ;
F_117 ( V_22 , V_24 , V_4 ) ;
}
return 0 ;
}
static int F_118 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_111 -> V_3 ;
F_20 ( V_22 , V_3 ) ;
F_119 ( V_22 , V_3 , V_3 ) ;
}
return 0 ;
}
static void F_120 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_110 * V_111 = & V_2 -> V_6 [ V_4 ] ;
struct V_23 * V_24 = & V_111 -> V_27 ;
F_121 ( & V_111 -> V_183 ) ;
F_122 ( V_22 , V_24 ) ;
}
F_123 ( V_22 -> V_181 -> V_182 ) ;
F_124 ( V_2 ) ;
}
static void F_84 ( struct V_21 * V_22 ,
T_1 V_131 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
T_1 V_265 [ 4 ] ;
int V_266 ;
V_266 = F_70 ( V_22 , V_131 , V_265 , F_10 ( V_265 ) ) ;
if ( V_266 == V_2 -> V_15 &&
! memcmp ( V_265 , V_2 -> V_199 , V_2 -> V_15 * sizeof( T_1 ) ) )
return;
F_28 ( L_30 , V_131 ) ;
F_125 ( V_22 , V_131 , V_2 -> V_15 , V_2 -> V_199 ) ;
}
static void F_126 ( struct V_21 * V_22 ,
const struct V_267 * V_268 , int V_269 )
{
unsigned int V_270 ;
if ( V_269 != V_271 )
return;
V_270 = F_16 ( V_22 , V_272 , 0 ,
V_273 , 0 ) ;
if ( V_270 == - 1 || V_270 & V_274 )
return;
V_270 |= V_274 ;
V_270 = F_16 ( V_22 , V_272 , 0 ,
V_275 , V_270 ) ;
if ( V_270 == - 1 )
return;
F_127 ( V_22 ) ;
return;
}
static void F_128 ( struct V_21 * V_22 )
{
unsigned int V_270 ;
V_270 = F_16 ( V_22 , V_272 , 0 ,
V_273 , 0 ) ;
if ( V_270 == - 1 || V_270 & V_276 )
return;
V_270 |= V_276 ;
F_129 ( V_22 , V_272 , 0 ,
V_275 , V_270 ) ;
}
static int F_130 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_131 ( sizeof( * V_2 ) , V_277 ) ;
if ( V_2 == NULL )
return - V_42 ;
V_22 -> V_2 = V_2 ;
F_132 ( V_22 , V_278 , V_279 , V_280 ) ;
F_133 ( V_22 , V_271 ) ;
if ( V_22 -> V_196 == 0x80862807 )
F_128 ( V_22 ) ;
if ( F_88 ( V_22 ) < 0 ) {
V_22 -> V_2 = NULL ;
F_124 ( V_2 ) ;
return - V_8 ;
}
V_22 -> V_281 = V_282 ;
F_114 ( V_22 ) ;
F_24 () ;
return 0 ;
}
static int F_134 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_245 * V_72 = V_2 -> V_11 ;
unsigned int V_197 ;
struct V_9 * V_246 ;
V_22 -> V_255 = 1 ;
V_22 -> V_256 = V_72 ;
V_197 = F_21 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
V_197 = F_86 ( V_197 ) ;
V_72 -> V_247 = F_93 ( 0 ) ;
V_72 -> V_248 = V_249 ;
V_246 = & V_72 -> V_12 [ V_251 ] ;
* V_246 = V_2 -> V_283 ;
V_246 -> V_131 = V_2 -> V_16 [ 0 ] . V_13 ;
if ( V_246 -> V_163 <= 2 && V_197 && V_197 <= 16 )
V_246 -> V_163 = V_197 ;
return 0 ;
}
static void F_135 ( struct V_21 * V_22 ,
unsigned int V_126 )
{
F_136 ( V_22 ) ;
F_56 ( V_22 ) ;
}
static int F_137 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_40 ;
V_40 = F_138 ( V_22 ,
V_2 -> V_16 [ 0 ] . V_13 ,
V_2 -> V_16 [ 0 ] . V_13 ) ;
if ( V_40 < 0 )
return V_40 ;
return F_139 ( V_22 , 0 ) ;
}
static int F_140 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
T_1 V_284 = V_2 -> V_6 [ 0 ] . V_3 ;
F_18 ( V_22 , V_284 , 0 ,
V_54 , V_55 ) ;
if ( F_21 ( V_22 , V_284 ) & V_51 )
F_18 ( V_22 , V_284 , 0 , V_52 ,
V_53 ) ;
F_119 ( V_22 , V_284 , V_284 ) ;
return 0 ;
}
static void F_141 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_124 ( V_2 ) ;
}
static int F_142 ( struct V_21 * V_22 )
{
F_143 ( V_22 , V_285 ) ;
return 0 ;
}
static int F_144 ( struct V_21 * V_22 )
{
F_143 ( V_22 , V_286 ) ;
return 0 ;
}
static int F_145 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_287 * V_288 = NULL ;
switch ( V_22 -> V_289 -> V_43 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_288 = & V_290 ;
break;
case 0x10de0007 :
V_288 = & V_291 ;
break;
default:
break;
}
if ( V_288 != NULL ) {
V_287 ( V_109 -> V_112 , 0 ,
V_169 ,
V_288 ) ;
} else {
F_68 ( V_109 -> V_112 , 0 ,
V_169 , 2 ) ;
}
return F_146 ( V_22 , & V_2 -> V_292 ) ;
}
static int F_147 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_148 ( V_22 , & V_2 -> V_292 ) ;
}
static int F_149 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_144 ,
unsigned int V_145 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_150 ( V_22 , & V_2 -> V_292 ,
V_144 , V_145 , V_109 ) ;
}
static int F_151 ( struct V_21 * V_22 ,
T_1 V_13 , T_1 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_131 ( sizeof( * V_2 ) , V_277 ) ;
if ( ! V_2 )
return - V_42 ;
V_22 -> V_2 = V_2 ;
V_2 -> V_292 . V_293 = 0 ;
V_2 -> V_292 . V_294 = 2 ;
V_2 -> V_292 . V_295 = V_13 ;
V_2 -> V_15 = 1 ;
V_2 -> V_5 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_13 ;
V_2 -> V_6 [ 0 ] . V_3 = V_3 ;
V_2 -> V_283 = V_296 ;
V_22 -> V_281 = V_297 ;
return 0 ;
}
static void F_152 ( struct V_21 * V_22 ,
int V_64 )
{
unsigned int V_298 ;
int V_299 = V_64 ? ( V_64 - 1 ) : 1 ;
switch ( V_64 ) {
default:
case 0 :
case 2 :
V_298 = 0x00 ;
break;
case 4 :
V_298 = 0x08 ;
break;
case 6 :
V_298 = 0x0b ;
break;
case 8 :
V_298 = 0x13 ;
break;
}
F_18 ( V_22 , 0x1 , 0 ,
V_300 , V_298 ) ;
F_18 ( V_22 , 0x1 , 0 ,
V_301 ,
( 0x71 - V_299 - V_298 ) ) ;
}
static int F_153 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_59 ;
F_18 ( V_22 , V_302 ,
0 , V_303 , 0 ) ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
F_18 ( V_22 , V_304 [ V_59 ] , 0 ,
V_303 , 0 ) ;
F_18 ( V_22 , V_304 [ V_59 ] , 0 ,
V_305 , 0 ) ;
}
F_152 ( V_22 , 8 ) ;
return F_148 ( V_22 , & V_2 -> V_292 ) ;
}
static int F_154 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_144 ,
unsigned int V_145 ,
struct V_108 * V_109 )
{
int V_57 ;
unsigned int V_306 , V_307 ;
int V_59 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_210 * V_211 ;
F_7 ( & V_22 -> V_212 ) ;
V_211 = F_95 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
V_57 = V_109 -> V_112 -> V_64 ;
V_306 = 0x2 ;
if ( V_22 -> V_308 && ( V_211 -> V_309 & V_310 ) )
F_18 ( V_22 ,
V_302 ,
0 ,
V_311 ,
V_211 -> V_309 & ~ V_310 & 0xff ) ;
F_18 ( V_22 , V_302 , 0 ,
V_303 , ( V_144 << 4 ) | 0x0 ) ;
F_18 ( V_22 , V_302 , 0 ,
V_305 , V_145 ) ;
if ( V_22 -> V_308 && ( V_211 -> V_309 & V_310 ) ) {
F_18 ( V_22 ,
V_302 ,
0 ,
V_311 ,
V_211 -> V_309 & 0xff ) ;
F_18 ( V_22 ,
V_302 ,
0 ,
V_312 , V_306 ) ;
}
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
if ( V_57 == 2 )
V_307 = 0 ;
else
V_307 = V_59 * 2 ;
if ( V_22 -> V_308 &&
( V_211 -> V_309 & V_310 ) )
F_18 ( V_22 ,
V_304 [ V_59 ] ,
0 ,
V_311 ,
V_211 -> V_309 & ~ V_310 & 0xff ) ;
F_18 ( V_22 ,
V_304 [ V_59 ] ,
0 ,
V_303 ,
( V_144 << 4 ) | V_307 ) ;
F_18 ( V_22 ,
V_304 [ V_59 ] ,
0 ,
V_305 ,
V_145 ) ;
if ( V_22 -> V_308 &&
( V_211 -> V_309 & V_310 ) ) {
F_18 ( V_22 ,
V_304 [ V_59 ] ,
0 ,
V_311 ,
V_211 -> V_309 & 0xff ) ;
F_18 ( V_22 ,
V_304 [ V_59 ] ,
0 ,
V_312 , V_306 ) ;
}
}
F_152 ( V_22 , V_57 ) ;
F_8 ( & V_22 -> V_212 ) ;
return 0 ;
}
static int F_155 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_40 = F_151 ( V_22 , V_302 ,
V_313 ) ;
if ( V_40 < 0 )
return V_40 ;
V_22 -> V_281 . V_314 = F_142 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_283 . V_164 = V_315 ;
V_2 -> V_283 . V_166 = V_316 ;
V_2 -> V_283 . V_165 = V_317 ;
return 0 ;
}
static int F_156 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_40 = F_134 ( V_22 ) ;
V_2 -> V_11 [ 0 ] . V_250 = true ;
return V_40 ;
}
static int F_157 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_215 * V_116 ;
int V_40 ;
V_40 = F_137 ( V_22 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_113 ( V_2 -> V_11 [ 0 ] . V_259 ,
V_251 ,
V_318 , 8 , 0 , & V_116 ) ;
if ( V_40 < 0 )
return V_40 ;
switch ( V_22 -> V_289 -> V_43 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_116 -> V_319 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_116 -> V_319 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_158 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_40 = F_155 ( V_22 ) ;
if ( V_40 < 0 )
return V_40 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_292 . V_294 = 8 ;
V_2 -> V_283 = V_320 ;
V_22 -> V_281 . V_314 = F_144 ;
V_22 -> V_281 . V_321 = F_156 ;
V_22 -> V_281 . V_322 = F_157 ;
F_152 ( V_22 , 8 ) ;
return 0 ;
}
static int F_159 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_144 ,
unsigned int V_145 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_197 = V_109 -> V_112 -> V_64 ;
int V_59 , V_40 ;
V_40 = F_149 ( V_10 , V_22 , V_144 , V_145 ,
V_109 ) ;
if ( V_40 < 0 )
return V_40 ;
F_18 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_58 , V_197 - 1 ) ;
for ( V_59 = 0 ; V_59 < V_197 ; V_59 ++ ) {
F_18 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_81 ,
( V_59 << 4 ) | V_59 ) ;
}
return 0 ;
}
static int F_160 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_40 = F_151 ( V_22 , V_323 , V_324 ) ;
if ( V_40 < 0 )
return V_40 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_283 . V_253 . V_325 = F_159 ;
return 0 ;
}
static int F_161 ( struct V_21 * V_22 )
{
return F_151 ( V_22 , V_326 , V_327 ) ;
}
static int T_5 F_162 ( void )
{
return F_163 ( & V_328 ) ;
}
static void T_6 F_164 ( void )
{
F_165 ( & V_328 ) ;
}
