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
V_50 , V_51 ) ;
}
static int F_18 ( struct V_21 * V_22 , T_1 V_13 )
{
return 1 + F_12 ( V_22 , V_13 , 0 ,
V_52 , 0 ) ;
}
static void F_19 ( struct V_21 * V_22 ,
T_1 V_13 , int V_53 )
{
if ( V_53 != F_18 ( V_22 , V_13 ) )
F_14 ( V_22 , V_13 , 0 ,
V_54 , V_53 - 1 ) ;
}
static void F_20 ( void )
{
int V_55 , V_56 ;
struct V_57 * V_58 ;
for ( V_55 = 0 ; V_55 < F_21 ( V_59 ) ; V_55 ++ ) {
V_58 = V_59 + V_55 ;
V_58 -> V_60 = 0 ;
V_58 -> V_61 = 0 ;
for ( V_56 = 0 ; V_56 < F_21 ( V_58 -> V_62 ) ; V_56 ++ )
if ( V_58 -> V_62 [ V_56 ] ) {
V_58 -> V_60 ++ ;
V_58 -> V_61 |= V_58 -> V_62 [ V_56 ] ;
}
}
}
static int F_22 ( int V_63 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < F_21 ( V_59 ) ; V_55 ++ ) {
if ( V_59 [ V_55 ] . V_64 == V_63 )
break;
}
return V_55 ;
}
static int F_23 ( struct V_65 * V_66 , int V_60 )
{
int V_55 ;
int V_63 = 0 ;
int V_61 = 0 ;
char V_67 [ V_68 ] ;
if ( V_60 <= 2 )
return 0 ;
for ( V_55 = 0 ; V_55 < F_21 ( V_69 ) ; V_55 ++ ) {
if ( V_66 -> V_70 & ( 1 << V_55 ) )
V_61 |= V_69 [ V_55 ] ;
}
for ( V_55 = 0 ; V_55 < F_21 ( V_59 ) ; V_55 ++ ) {
if ( V_60 == V_59 [ V_55 ] . V_60 &&
( V_61 & V_59 [ V_55 ] . V_61 ) ==
V_59 [ V_55 ] . V_61 ) {
V_63 = V_59 [ V_55 ] . V_64 ;
break;
}
}
F_24 ( V_66 -> V_70 , V_67 , sizeof( V_67 ) ) ;
F_25 ( L_4 ,
V_63 , V_60 , V_67 ) ;
return V_63 ;
}
static void F_26 ( struct V_21 * V_22 ,
T_1 V_3 )
{
#ifdef F_27
int V_55 ;
int V_71 ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
V_71 = F_12 ( V_22 , V_3 , 0 ,
V_72 , V_55 ) ;
F_28 ( V_73 L_5 ,
V_71 >> 4 , V_71 & 0xf ) ;
}
#endif
}
static void F_29 ( struct V_21 * V_22 ,
T_1 V_3 ,
bool V_74 ,
int V_63 )
{
int V_55 ;
int V_37 ;
int V_75 ;
int V_76 [ 8 ] ;
V_75 = F_22 ( V_63 ) ;
if ( V_77 [ V_63 ] [ 1 ] == 0 ) {
for ( V_55 = 0 ; V_55 < V_59 [ V_75 ] . V_60 ; V_55 ++ )
V_77 [ V_63 ] [ V_55 ] = V_55 | ( V_55 << 4 ) ;
for (; V_55 < 8 ; V_55 ++ )
V_77 [ V_63 ] [ V_55 ] = 0xf | ( V_55 << 4 ) ;
}
if ( V_74 ) {
for ( V_55 = 0 ; V_55 < V_59 [ V_75 ] . V_60 ; V_55 ++ )
V_76 [ V_55 ] = V_55 | ( V_55 << 4 ) ;
for (; V_55 < 8 ; V_55 ++ )
V_76 [ V_55 ] = 0xf | ( V_55 << 4 ) ;
}
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
V_37 = F_14 ( V_22 , V_3 , 0 ,
V_78 ,
V_74 ? V_76 [ V_55 ] : V_77 [ V_63 ] [ V_55 ] ) ;
if ( V_37 ) {
F_25 ( V_79
L_6 ) ;
break;
}
}
F_26 ( V_22 , V_3 ) ;
}
static int F_30 ( unsigned char V_80 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_84 == V_80 )
return V_82 -> V_61 ;
}
return 0 ;
}
static int F_31 ( unsigned char V_80 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_84 == V_80 )
return V_82 -> V_85 ;
}
return 0x0f ;
}
static int F_32 ( unsigned char V_80 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_85 == V_80 )
return V_82 -> V_84 ;
}
return 0 ;
}
static int F_33 ( int V_86 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_61 == V_86 )
return V_82 -> V_84 ;
}
return 0 ;
}
static int F_34 ( int V_53 , unsigned char * V_84 )
{
int V_55 , V_87 = 0 , V_61 = 0 ;
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ ) {
int V_88 = F_30 ( V_84 [ V_55 ] ) ;
if ( V_88 ) {
V_61 |= V_88 ;
V_87 ++ ;
}
}
for ( V_55 = 0 ; V_55 < F_21 ( V_59 ) ; V_55 ++ ) {
if ( ( V_53 == V_59 [ V_55 ] . V_60 ||
V_87 == V_59 [ V_55 ] . V_60 ) &&
( V_61 & V_59 [ V_55 ] . V_61 ) ==
V_59 [ V_55 ] . V_61 )
return V_59 [ V_55 ] . V_64 ;
}
return - 1 ;
}
static int F_35 ( struct V_21 * V_22 ,
T_1 V_3 ,
int V_53 , unsigned char * V_84 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
int V_43 , V_37 ;
if ( V_55 < V_53 )
V_43 = F_31 ( V_84 [ V_55 ] ) ;
else
V_43 = 0xf ;
V_43 |= ( V_55 << 4 ) ;
V_37 = F_14 ( V_22 , V_3 , 0 ,
V_78 , V_43 ) ;
if ( V_37 )
return - V_8 ;
}
return 0 ;
}
static void F_36 ( unsigned char * V_84 , int V_63 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
if ( V_55 < V_59 [ V_63 ] . V_60 )
V_84 [ V_55 ] = F_32 ( ( V_77 [ V_63 ] [ V_55 ] >> 4 ) & 0x0f ) ;
else
V_84 [ V_55 ] = 0 ;
}
}
static void F_37 ( struct V_21 * V_22 ,
T_1 V_3 , bool V_74 , int V_63 ,
int V_60 , unsigned char * V_84 )
{
if ( ! V_74 && V_84 ) {
F_35 ( V_22 , V_3 ,
V_60 , V_84 ) ;
} else {
F_29 ( V_22 , V_3 , V_74 , V_63 ) ;
F_36 ( V_84 , V_63 ) ;
}
}
static void F_38 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_14 ( V_22 , V_3 , 0 , V_89 ,
V_90 ) ;
}
static void F_39 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_14 ( V_22 , V_3 , 0 , V_89 ,
V_91 ) ;
}
static void F_40 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_27
int V_55 ;
int V_92 ;
V_92 = F_41 ( V_22 , V_3 ) ;
F_28 ( V_73 L_7 , V_92 ) ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
V_92 = F_12 ( V_22 , V_3 , 0 ,
V_93 , V_55 ) ;
F_28 ( V_73 L_8 , V_55 , V_92 ) ;
}
#endif
}
static void F_42 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_43
int V_55 , V_56 ;
int V_92 ;
int V_94 , V_95 ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
V_92 = F_12 ( V_22 , V_3 , 0 ,
V_93 , V_55 ) ;
if ( V_92 == 0 )
continue;
F_13 ( V_22 , V_3 , V_55 , 0x0 ) ;
for ( V_56 = 1 ; V_56 < 1000 ; V_56 ++ ) {
F_15 ( V_22 , V_3 , 0x0 ) ;
F_11 ( V_22 , V_3 , & V_94 , & V_95 ) ;
if ( V_94 != V_55 )
F_44 ( V_96 L_9 ,
V_95 , V_94 , V_55 ) ;
if ( V_95 == 0 )
break;
}
F_44 ( V_96
L_10 ,
V_55 , V_92 , V_56 ) ;
}
#endif
}
static void F_45 ( struct V_97 * V_98 )
{
T_2 * V_31 = ( T_2 * ) V_98 ;
T_2 V_99 = 0 ;
int V_55 ;
V_98 -> V_100 = 0 ;
for ( V_55 = 0 ; V_55 < sizeof( * V_98 ) ; V_55 ++ )
V_99 += V_31 [ V_55 ] ;
V_98 -> V_100 = - V_99 ;
}
static void F_46 ( struct V_21 * V_22 ,
T_1 V_3 ,
T_2 * V_101 , int V_92 )
{
int V_55 ;
F_40 ( V_22 , V_3 ) ;
F_42 ( V_22 , V_3 ) ;
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ )
F_15 ( V_22 , V_3 , V_101 [ V_55 ] ) ;
}
static bool F_47 ( struct V_21 * V_22 , T_1 V_3 ,
T_2 * V_101 , int V_92 )
{
T_2 V_43 ;
int V_55 ;
if ( F_12 ( V_22 , V_3 , 0 , V_102 , 0 )
!= V_90 )
return false ;
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ ) {
V_43 = F_12 ( V_22 , V_3 , 0 ,
V_103 , 0 ) ;
if ( V_43 != V_101 [ V_55 ] )
return false ;
}
return true ;
}
static void F_48 ( struct V_21 * V_22 , int V_4 ,
bool V_74 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_107 -> V_3 ;
int V_60 = V_105 -> V_108 -> V_60 ;
struct V_65 * V_66 ;
int V_63 ;
union V_109 V_110 ;
V_66 = & V_2 -> V_6 [ V_4 ] . V_26 ;
if ( ! V_66 -> V_111 )
return;
if ( ! V_74 && V_107 -> V_112 )
V_63 = F_34 ( V_60 , V_107 -> V_113 ) ;
else
V_63 = F_23 ( V_66 , V_60 ) ;
if ( V_63 < 0 )
V_63 = 0 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
if ( V_66 -> V_114 == 0 ) {
struct V_97 * V_98 = & V_110 . V_115 ;
V_98 -> type = 0x84 ;
V_98 -> V_116 = 0x01 ;
V_98 -> V_117 = 0x0a ;
V_98 -> V_118 = V_60 - 1 ;
V_98 -> V_119 = V_63 ;
F_45 ( V_98 ) ;
} else if ( V_66 -> V_114 == 1 ) {
struct V_120 * V_121 = & V_110 . V_122 ;
V_121 -> type = 0x84 ;
V_121 -> V_117 = 0x1b ;
V_121 -> V_116 = 0x11 << 2 ;
V_121 -> V_118 = V_60 - 1 ;
V_121 -> V_119 = V_63 ;
} else {
F_44 ( L_11 ,
V_3 ) ;
return;
}
if ( ! F_47 ( V_22 , V_3 , V_110 . V_31 ,
sizeof( V_110 ) ) ) {
F_25 ( L_12
L_13 ,
V_3 ,
V_60 ) ;
F_37 ( V_22 , V_3 , V_74 , V_63 ,
V_60 , V_107 -> V_113 ) ;
F_39 ( V_22 , V_3 ) ;
F_46 ( V_22 , V_3 ,
V_110 . V_31 , sizeof( V_110 ) ) ;
F_38 ( V_22 , V_3 ) ;
} else {
if ( V_107 -> V_74 != V_74 )
F_37 ( V_22 , V_3 , V_74 , V_63 ,
V_60 , V_107 -> V_113 ) ;
}
V_107 -> V_74 = V_74 ;
}
static void F_49 ( struct V_21 * V_22 , unsigned int V_123 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_124 = V_123 >> V_125 ;
int V_3 ;
int V_4 ;
struct V_126 * V_127 ;
V_127 = F_50 ( V_22 , V_124 ) ;
if ( ! V_127 )
return;
V_3 = V_127 -> V_128 ;
V_127 -> V_129 = 1 ;
F_51 ( V_130 ,
L_14 ,
V_22 -> V_131 , V_3 ,
! ! ( V_123 & V_132 ) , ! ! ( V_123 & V_133 ) ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
F_52 ( & V_2 -> V_6 [ V_4 ] , 1 ) ;
F_53 ( V_22 ) ;
}
static void F_54 ( struct V_21 * V_22 , unsigned int V_123 )
{
int V_124 = V_123 >> V_125 ;
int V_134 = ( V_123 & V_135 ) >> V_136 ;
int V_137 = ! ! ( V_123 & V_138 ) ;
int V_139 = ! ! ( V_123 & V_140 ) ;
F_28 ( V_96
L_15 ,
V_22 -> V_131 ,
V_124 ,
V_134 ,
V_137 ,
V_139 ) ;
if ( V_137 )
;
if ( V_139 )
;
}
static void F_55 ( struct V_21 * V_22 , unsigned int V_123 )
{
int V_124 = V_123 >> V_125 ;
int V_134 = ( V_123 & V_135 ) >> V_136 ;
if ( ! F_50 ( V_22 , V_124 ) ) {
F_44 ( V_96 L_16 , V_124 ) ;
return;
}
if ( V_134 == 0 )
F_49 ( V_22 , V_123 ) ;
else
F_54 ( V_22 , V_123 ) ;
}
static int F_56 ( struct V_21 * V_22 , T_1 V_13 ,
T_1 V_3 , T_3 V_141 , int V_142 )
{
int V_143 ;
int V_144 = 0 ;
if ( F_57 ( V_22 , V_3 ) & V_145 ) {
V_143 = F_12 ( V_22 , V_3 , 0 ,
V_146 , 0 ) ;
V_144 = V_143 & ~ V_147 ;
if ( F_58 ( V_142 ) )
V_144 |= V_148 ;
else
V_144 |= V_149 ;
F_25 ( L_17
L_18 ,
V_3 ,
V_143 == V_144 ? L_19 : L_20 ,
V_144 ) ;
if ( V_143 != V_144 )
F_14 ( V_22 , V_3 , 0 ,
V_50 ,
V_144 ) ;
}
if ( F_58 ( V_142 ) && ! V_144 ) {
F_25 ( L_21 ) ;
return - V_8 ;
}
F_59 ( V_22 , V_13 , V_141 , 0 , V_142 ) ;
return 0 ;
}
static int F_60 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_150 * V_108 = V_105 -> V_108 ;
int V_4 , V_14 , V_151 = 0 ;
struct V_106 * V_107 ;
struct V_65 * V_66 ;
struct V_152 * V_153 = NULL ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_61 ( V_4 < 0 ) )
return - V_8 ;
V_107 = & V_2 -> V_6 [ V_4 ] ;
V_66 = & V_107 -> V_26 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_153 = & V_2 -> V_16 [ V_14 ] ;
if ( V_153 -> V_154 )
continue;
for ( V_151 = 0 ; V_151 < V_107 -> V_155 ; V_151 ++ )
if ( V_107 -> V_156 [ V_151 ] == V_153 -> V_13 )
break;
if ( V_151 == V_107 -> V_155 )
continue;
break;
}
if ( V_14 == V_2 -> V_15 )
return - V_157 ;
V_153 -> V_154 = 1 ;
V_10 -> V_128 = V_153 -> V_13 ;
F_14 ( V_22 , V_107 -> V_3 , 0 ,
V_158 ,
V_151 ) ;
F_62 ( V_22 , V_4 , V_153 -> V_13 ) ;
V_10 -> V_159 = V_153 -> V_159 ;
V_10 -> V_160 = V_153 -> V_160 ;
V_10 -> V_161 = V_153 -> V_161 ;
V_10 -> V_162 = V_153 -> V_162 ;
V_10 -> V_163 = V_153 -> V_163 ;
if ( ! V_164 && V_66 -> V_165 ) {
F_63 ( V_66 , V_10 ) ;
if ( V_10 -> V_159 > V_10 -> V_160 ||
! V_10 -> V_161 || ! V_10 -> V_162 )
return - V_157 ;
}
V_108 -> V_166 . V_159 = V_10 -> V_159 ;
V_108 -> V_166 . V_160 = V_10 -> V_160 ;
V_108 -> V_166 . V_162 = V_10 -> V_162 ;
V_108 -> V_166 . V_161 = V_10 -> V_161 ;
F_64 ( V_105 -> V_108 , 0 ,
V_167 , 2 ) ;
return 0 ;
}
static int F_65 ( struct V_21 * V_22 , int V_4 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_107 -> V_3 ;
if ( ! ( F_17 ( V_22 , V_3 ) & V_168 ) ) {
F_2 ( V_7
L_22
L_23 ,
V_3 , F_17 ( V_22 , V_3 ) ) ;
return - V_8 ;
}
V_107 -> V_155 = F_66 ( V_22 , V_3 ,
V_107 -> V_156 ,
V_169 ) ;
return 0 ;
}
static void F_52 ( struct V_106 * V_107 , int V_170 )
{
struct V_21 * V_22 = V_107 -> V_22 ;
struct V_65 * V_66 = & V_107 -> V_26 ;
T_1 V_3 = V_107 -> V_3 ;
int V_171 = F_67 ( V_22 , V_3 ) ;
bool V_165 = false ;
memset ( V_66 , 0 , F_68 ( struct V_65 , V_33 ) ) ;
V_66 -> V_111 = ! ! ( V_171 & V_172 ) ;
if ( V_66 -> V_111 )
V_165 = ! ! ( V_171 & V_173 ) ;
F_51 ( V_130 ,
L_24 ,
V_22 -> V_131 , V_3 , V_66 -> V_111 , V_165 ) ;
if ( V_165 ) {
if ( ! F_69 ( V_66 , V_22 , V_3 ) )
F_70 ( V_66 ) ;
else if ( V_170 ) {
F_71 ( V_22 -> V_174 -> V_175 ,
& V_107 -> V_176 ,
F_72 ( 300 ) ) ;
}
}
}
static void F_73 ( struct V_177 * V_176 )
{
struct V_106 * V_107 =
F_74 ( F_75 ( V_176 ) , struct V_106 , V_176 ) ;
if ( V_107 -> V_178 ++ > 6 )
V_107 -> V_178 = 0 ;
F_52 ( V_107 , V_107 -> V_178 ) ;
}
static int F_76 ( struct V_21 * V_22 , T_1 V_3 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned int V_179 , V_180 ;
int V_4 ;
struct V_106 * V_107 ;
int V_37 ;
V_179 = F_57 ( V_22 , V_3 ) ;
if ( ! ( V_179 & ( V_181 | V_182 ) ) )
return 0 ;
V_180 = F_77 ( V_22 , V_3 ) ;
if ( F_78 ( V_180 ) == V_183 )
return 0 ;
if ( F_61 ( V_2 -> V_5 >= V_184 ) )
return - V_185 ;
V_4 = V_2 -> V_5 ;
V_107 = & V_2 -> V_6 [ V_4 ] ;
V_107 -> V_3 = V_3 ;
V_107 -> V_74 = false ;
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
struct V_152 * V_153 ;
unsigned int V_186 ;
int V_37 ;
if ( F_61 ( V_2 -> V_15 >= V_187 ) )
return - V_185 ;
V_186 = F_17 ( V_22 , V_13 ) ;
V_186 = F_80 ( V_186 ) ;
V_14 = V_2 -> V_15 ;
V_153 = & V_2 -> V_16 [ V_14 ] ;
V_153 -> V_13 = V_13 ;
V_153 -> V_159 = 2 ;
if ( V_186 <= 16 ) {
V_153 -> V_160 = V_186 ;
if ( V_186 > V_2 -> V_160 )
V_2 -> V_160 = V_186 ;
}
V_37 = F_81 ( V_22 , V_13 ,
& V_153 -> V_161 ,
& V_153 -> V_162 ,
& V_153 -> V_163 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_15 ++ ;
return 0 ;
}
static int F_82 ( struct V_21 * V_22 )
{
T_1 V_128 ;
int V_55 , V_188 ;
V_188 = F_83 ( V_22 , V_22 -> V_189 , & V_128 ) ;
if ( ! V_128 || V_188 < 0 ) {
F_2 ( V_7 L_25 ) ;
return - V_8 ;
}
for ( V_55 = 0 ; V_55 < V_188 ; V_55 ++ , V_128 ++ ) {
unsigned int V_179 ;
unsigned int type ;
V_179 = F_17 ( V_22 , V_128 ) ;
type = F_84 ( V_179 ) ;
if ( ! ( V_179 & V_190 ) )
continue;
switch ( type ) {
case V_191 :
F_79 ( V_22 , V_128 ) ;
break;
case V_192 :
F_76 ( V_22 , V_128 ) ;
break;
}
}
#ifdef F_85
if ( V_22 -> V_193 == 0x80862806 )
V_22 -> V_174 -> V_194 = 1 ;
else if ( ! ( F_86 ( V_22 , V_22 -> V_189 , V_195 ) &
V_196 ) )
V_22 -> V_174 -> V_194 = 1 ;
#endif
return 0 ;
}
static char * F_87 ( int V_197 )
{
static char V_198 [ V_184 ] [ 8 ] ;
sprintf ( & V_198 [ V_197 ] [ 0 ] , L_26 , V_197 ) ;
return & V_198 [ V_197 ] [ 0 ] ;
}
static bool F_88 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_199 * V_200 ;
bool V_74 ;
F_89 ( & V_22 -> V_201 ) ;
V_200 = F_90 ( V_22 , V_13 ) ;
V_74 = ! ! ( V_200 -> V_202 & V_203 ) ;
F_91 ( & V_22 -> V_201 ) ;
return V_74 ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_141 ,
unsigned int V_142 ,
struct V_104 * V_105 )
{
T_1 V_13 = V_10 -> V_128 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = F_3 ( V_2 , V_10 ) ;
T_1 V_3 = V_2 -> V_6 [ V_4 ] . V_3 ;
bool V_74 ;
V_74 = F_88 ( V_22 , V_13 ) ;
F_19 ( V_22 , V_13 , V_105 -> V_108 -> V_60 ) ;
F_48 ( V_22 , V_4 , V_74 , V_105 ) ;
return F_56 ( V_22 , V_13 , V_3 , V_141 , V_142 ) ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_104 * V_105 )
{
F_94 ( V_22 , V_10 -> V_128 ) ;
return 0 ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 , V_4 ;
struct V_152 * V_153 ;
struct V_106 * V_107 ;
if ( V_10 -> V_128 ) {
V_14 = F_4 ( V_2 , V_10 -> V_128 ) ;
if ( F_61 ( V_14 < 0 ) )
return - V_8 ;
V_153 = & V_2 -> V_16 [ V_14 ] ;
F_61 ( ! V_153 -> V_154 ) ;
V_153 -> V_154 = 0 ;
V_10 -> V_128 = 0 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_61 ( V_4 < 0 ) )
return - V_8 ;
V_107 = & V_2 -> V_6 [ V_4 ] ;
F_96 ( V_22 , V_4 ) ;
V_107 -> V_112 = false ;
memset ( V_107 -> V_113 , 0 , sizeof( V_107 -> V_113 ) ) ;
}
return 0 ;
}
static int F_97 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_204 * V_205 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_205 -> V_206 ;
struct V_1 * V_2 = V_22 -> V_2 ;
V_20 -> type = V_207 ;
V_20 -> V_25 = V_2 -> V_160 ;
V_20 -> V_30 . integer . V_208 = 0 ;
V_20 -> V_30 . integer . V_209 = V_210 ;
return 0 ;
}
static int F_98 ( struct V_17 * V_18 , int V_211 ,
unsigned int V_92 , unsigned int T_4 * V_212 )
{
struct V_204 * V_205 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_205 -> V_206 ;
struct V_1 * V_2 = V_22 -> V_2 ;
const unsigned int V_213 =
V_214 | V_215 | V_216 | V_217 | V_218 | V_219 | V_220 | V_221 ;
unsigned int T_4 * V_222 ;
int V_53 , V_25 = 0 ;
if ( V_92 < 8 )
return - V_39 ;
if ( F_99 ( V_223 , V_212 ) )
return - V_224 ;
V_92 -= 8 ;
V_222 = V_212 + 2 ;
for ( V_53 = 2 ; V_53 <= V_2 -> V_160 ; V_53 ++ ) {
int V_55 , V_80 ;
struct V_57 * V_225 ;
V_225 = V_59 ;
for ( V_55 = 0 ; V_55 < F_21 ( V_59 ) ; V_55 ++ , V_225 ++ ) {
int V_226 = V_53 * 4 ;
if ( V_225 -> V_60 != V_53 )
continue;
if ( V_225 -> V_61 & ~ V_213 )
continue;
if ( V_92 < 8 )
return - V_39 ;
if ( F_99 ( V_227 , V_222 ) ||
F_99 ( V_226 , V_222 + 1 ) )
return - V_224 ;
V_222 += 2 ;
V_92 -= 8 ;
V_25 += 8 ;
if ( V_92 < V_226 )
return - V_39 ;
V_92 -= V_226 ;
V_25 += V_226 ;
for ( V_80 = 7 ; V_80 >= 0 ; V_80 -- ) {
int V_86 = V_225 -> V_62 [ V_80 ] ;
if ( ! V_86 )
continue;
if ( F_99 ( F_33 ( V_86 ) , V_222 ) )
return - V_224 ;
V_222 ++ ;
}
}
}
if ( F_99 ( V_25 , V_212 + 1 ) )
return - V_224 ;
return 0 ;
}
static int F_100 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_204 * V_205 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_205 -> V_206 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = V_18 -> V_24 ;
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
int V_55 ;
for ( V_55 = 0 ; V_55 < F_21 ( V_107 -> V_113 ) ; V_55 ++ )
V_29 -> V_30 . integer . V_30 [ V_55 ] = V_107 -> V_113 [ V_55 ] ;
return 0 ;
}
static int F_101 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_204 * V_205 = F_6 ( V_18 ) ;
struct V_21 * V_22 = V_205 -> V_206 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = V_18 -> V_24 ;
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
unsigned int V_228 ;
struct V_104 * V_105 ;
unsigned char V_113 [ 8 ] ;
int V_55 , V_63 , V_229 = 0 ;
V_228 = F_102 ( V_18 , & V_29 -> V_40 ) ;
V_105 = F_103 ( V_205 , V_228 ) ;
if ( ! V_105 || ! V_105 -> V_108 )
return 0 ;
switch ( V_105 -> V_108 -> V_202 -> V_230 ) {
case V_231 :
case V_232 :
break;
case V_233 :
V_229 = 1 ;
break;
default:
return - V_234 ;
}
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
for ( V_55 = 0 ; V_55 < F_21 ( V_113 ) ; V_55 ++ )
V_113 [ V_55 ] = V_29 -> V_30 . integer . V_30 [ V_55 ] ;
if ( ! memcmp ( V_113 , V_107 -> V_113 , sizeof( V_113 ) ) )
return 0 ;
V_63 = F_34 ( F_21 ( V_113 ) , V_113 ) ;
if ( V_63 < 0 )
return - V_8 ;
V_107 -> V_112 = true ;
memcpy ( V_107 -> V_113 , V_113 , sizeof( V_113 ) ) ;
if ( V_229 )
F_48 ( V_22 , V_4 , V_107 -> V_74 ,
V_105 ) ;
return 0 ;
}
static int F_104 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_235 * V_205 ;
struct V_9 * V_236 ;
V_205 = & V_2 -> V_11 [ V_4 ] ;
V_205 -> V_237 = F_87 ( V_4 ) ;
V_205 -> V_238 = V_239 ;
V_205 -> V_240 = true ;
V_236 = & V_205 -> V_12 [ V_241 ] ;
V_236 -> V_242 = 1 ;
V_236 -> V_243 = V_244 ;
}
V_22 -> V_245 = V_2 -> V_5 ;
V_22 -> V_246 = V_2 -> V_11 ;
return 0 ;
}
static int F_105 ( struct V_21 * V_22 , int V_4 )
{
char V_247 [ 32 ] = L_27 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
int V_248 = V_2 -> V_11 [ V_4 ] . V_35 ;
if ( V_248 > 0 )
sprintf ( V_247 + strlen ( V_247 ) , L_28 , V_248 ) ;
return F_106 ( V_22 , V_107 -> V_3 , V_247 , 0 ) ;
}
static int F_107 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
V_37 = F_105 ( V_22 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_108 ( V_22 ,
V_107 -> V_3 ,
V_107 -> V_156 [ 0 ] ,
V_239 ) ;
if ( V_37 < 0 )
return V_37 ;
F_96 ( V_22 , V_4 ) ;
V_37 = F_8 ( V_22 ,
V_4 ,
V_2 -> V_11 [ V_4 ] . V_35 ) ;
if ( V_37 < 0 )
return V_37 ;
F_52 ( V_107 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_204 * V_113 ;
struct V_17 * V_36 ;
int V_55 ;
V_37 = F_109 ( V_22 -> V_246 [ V_4 ] . V_249 ,
V_241 ,
NULL , 0 , V_4 , & V_113 ) ;
if ( V_37 < 0 )
return V_37 ;
V_113 -> V_206 = V_22 ;
V_36 = V_113 -> V_36 ;
for ( V_55 = 0 ; V_55 < V_36 -> V_25 ; V_55 ++ )
V_36 -> V_250 [ V_55 ] . V_251 |= V_252 ;
V_36 -> V_205 = F_97 ;
V_36 -> V_253 = F_100 ;
V_36 -> V_254 = F_101 ;
V_36 -> V_212 . V_80 = F_98 ;
}
return 0 ;
}
static int F_110 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
struct V_65 * V_66 = & V_107 -> V_26 ;
V_107 -> V_22 = V_22 ;
F_111 ( & V_107 -> V_176 , F_73 ) ;
F_112 ( V_22 , V_66 , V_4 ) ;
}
return 0 ;
}
static int F_113 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_107 -> V_3 ;
F_16 ( V_22 , V_3 ) ;
F_114 ( V_22 , V_3 , V_3 ) ;
}
return 0 ;
}
static void F_115 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_106 * V_107 = & V_2 -> V_6 [ V_4 ] ;
struct V_65 * V_66 = & V_107 -> V_26 ;
F_116 ( & V_107 -> V_176 ) ;
F_117 ( V_22 , V_66 ) ;
}
F_118 ( V_22 -> V_174 -> V_175 ) ;
F_119 ( V_2 ) ;
}
static void F_120 ( struct V_21 * V_22 )
{
unsigned int V_255 ;
T_1 V_256 [ 3 ] = { 0x2 , 0x3 , 0x4 } ;
V_255 = F_12 ( V_22 , 0x08 , 0 , 0xf81 , 0 ) ;
if ( V_255 == - 1 || V_255 & 0x02 )
return;
V_255 |= 0x02 ;
F_12 ( V_22 , 0x08 , 0 , 0x781 , V_255 ) ;
V_255 = F_12 ( V_22 , 0x08 , 0 , 0xf81 , 0 ) ;
if ( V_255 == - 1 || ! ( V_255 & 0x02 ) )
return;
F_121 ( V_22 , 0x05 , 3 , V_256 ) ;
F_121 ( V_22 , 0x06 , 3 , V_256 ) ;
F_121 ( V_22 , 0x07 , 3 , V_256 ) ;
}
static int F_122 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_123 ( sizeof( * V_2 ) , V_257 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
if ( V_22 -> V_193 == 0x80862807 )
F_120 ( V_22 ) ;
if ( F_82 ( V_22 ) < 0 ) {
V_22 -> V_2 = NULL ;
F_119 ( V_2 ) ;
return - V_8 ;
}
V_22 -> V_258 = V_259 ;
F_110 ( V_22 ) ;
F_20 () ;
return 0 ;
}
static int F_124 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_235 * V_205 = V_2 -> V_11 ;
unsigned int V_186 ;
struct V_9 * V_236 ;
V_22 -> V_245 = 1 ;
V_22 -> V_246 = V_205 ;
V_186 = F_17 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
V_186 = F_80 ( V_186 ) ;
V_205 -> V_237 = F_87 ( 0 ) ;
V_205 -> V_238 = V_239 ;
V_236 = & V_205 -> V_12 [ V_241 ] ;
* V_236 = V_2 -> V_260 ;
V_236 -> V_128 = V_2 -> V_16 [ 0 ] . V_13 ;
if ( V_236 -> V_160 <= 2 && V_186 && V_186 <= 16 )
V_236 -> V_160 = V_186 ;
return 0 ;
}
static void F_125 ( struct V_21 * V_22 ,
unsigned int V_123 )
{
F_126 ( V_22 ) ;
F_53 ( V_22 ) ;
}
static int F_127 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
V_37 = F_128 ( V_22 ,
V_2 -> V_16 [ 0 ] . V_13 ,
V_2 -> V_16 [ 0 ] . V_13 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_129 ( V_22 , 0 ) ;
}
static int F_130 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
T_1 V_261 = V_2 -> V_6 [ 0 ] . V_3 ;
F_14 ( V_22 , V_261 , 0 ,
V_50 , V_51 ) ;
if ( F_17 ( V_22 , V_261 ) & V_47 )
F_14 ( V_22 , V_261 , 0 , V_48 ,
V_49 ) ;
F_114 ( V_22 , V_261 , V_261 ) ;
return 0 ;
}
static void F_131 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_119 ( V_2 ) ;
}
static int F_132 ( struct V_21 * V_22 )
{
F_133 ( V_22 , V_262 ) ;
return 0 ;
}
static int F_134 ( struct V_21 * V_22 )
{
F_133 ( V_22 , V_263 ) ;
return 0 ;
}
static int F_135 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_264 * V_265 = NULL ;
switch ( V_22 -> V_266 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_265 = & V_267 ;
break;
case 0x10de0007 :
V_265 = & V_268 ;
break;
default:
break;
}
if ( V_265 != NULL ) {
V_264 ( V_105 -> V_108 , 0 ,
V_167 ,
V_265 ) ;
} else {
F_64 ( V_105 -> V_108 , 0 ,
V_167 , 2 ) ;
}
return F_136 ( V_22 , & V_2 -> V_269 ) ;
}
static int F_137 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_138 ( V_22 , & V_2 -> V_269 ) ;
}
static int F_139 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_141 ,
unsigned int V_142 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_140 ( V_22 , & V_2 -> V_269 ,
V_141 , V_142 , V_105 ) ;
}
static int F_141 ( struct V_21 * V_22 ,
T_1 V_13 , T_1 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_123 ( sizeof( * V_2 ) , V_257 ) ;
if ( ! V_2 )
return - V_39 ;
V_22 -> V_2 = V_2 ;
V_2 -> V_269 . V_270 = 0 ;
V_2 -> V_269 . V_271 = 2 ;
V_2 -> V_269 . V_272 = V_13 ;
V_2 -> V_15 = 1 ;
V_2 -> V_5 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_13 ;
V_2 -> V_6 [ 0 ] . V_3 = V_3 ;
V_2 -> V_260 = V_273 ;
V_22 -> V_258 = V_274 ;
return 0 ;
}
static void F_142 ( struct V_21 * V_22 ,
int V_60 )
{
unsigned int V_275 ;
int V_276 = V_60 ? ( V_60 - 1 ) : 1 ;
switch ( V_60 ) {
default:
case 0 :
case 2 :
V_275 = 0x00 ;
break;
case 4 :
V_275 = 0x08 ;
break;
case 6 :
V_275 = 0x0b ;
break;
case 8 :
V_275 = 0x13 ;
break;
}
F_14 ( V_22 , 0x1 , 0 ,
V_277 , V_275 ) ;
F_14 ( V_22 , 0x1 , 0 ,
V_278 ,
( 0x71 - V_276 - V_275 ) ) ;
}
static int F_143 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_55 ;
F_14 ( V_22 , V_279 ,
0 , V_280 , 0 ) ;
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
F_14 ( V_22 , V_281 [ V_55 ] , 0 ,
V_280 , 0 ) ;
F_14 ( V_22 , V_281 [ V_55 ] , 0 ,
V_282 , 0 ) ;
}
F_142 ( V_22 , 8 ) ;
return F_138 ( V_22 , & V_2 -> V_269 ) ;
}
static int F_144 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_141 ,
unsigned int V_142 ,
struct V_104 * V_105 )
{
int V_53 ;
unsigned int V_283 , V_284 ;
int V_55 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_199 * V_200 ;
F_89 ( & V_22 -> V_201 ) ;
V_200 = F_90 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
V_53 = V_105 -> V_108 -> V_60 ;
V_283 = 0x2 ;
if ( V_22 -> V_285 && ( V_200 -> V_286 & V_287 ) )
F_14 ( V_22 ,
V_279 ,
0 ,
V_288 ,
V_200 -> V_286 & ~ V_287 & 0xff ) ;
F_14 ( V_22 , V_279 , 0 ,
V_280 , ( V_141 << 4 ) | 0x0 ) ;
F_14 ( V_22 , V_279 , 0 ,
V_282 , V_142 ) ;
if ( V_22 -> V_285 && ( V_200 -> V_286 & V_287 ) ) {
F_14 ( V_22 ,
V_279 ,
0 ,
V_288 ,
V_200 -> V_286 & 0xff ) ;
F_14 ( V_22 ,
V_279 ,
0 ,
V_289 , V_283 ) ;
}
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
if ( V_53 == 2 )
V_284 = 0 ;
else
V_284 = V_55 * 2 ;
if ( V_22 -> V_285 &&
( V_200 -> V_286 & V_287 ) )
F_14 ( V_22 ,
V_281 [ V_55 ] ,
0 ,
V_288 ,
V_200 -> V_286 & ~ V_287 & 0xff ) ;
F_14 ( V_22 ,
V_281 [ V_55 ] ,
0 ,
V_280 ,
( V_141 << 4 ) | V_284 ) ;
F_14 ( V_22 ,
V_281 [ V_55 ] ,
0 ,
V_282 ,
V_142 ) ;
if ( V_22 -> V_285 &&
( V_200 -> V_286 & V_287 ) ) {
F_14 ( V_22 ,
V_281 [ V_55 ] ,
0 ,
V_288 ,
V_200 -> V_286 & 0xff ) ;
F_14 ( V_22 ,
V_281 [ V_55 ] ,
0 ,
V_289 , V_283 ) ;
}
}
F_142 ( V_22 , V_53 ) ;
F_91 ( & V_22 -> V_201 ) ;
return 0 ;
}
static int F_145 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_141 ( V_22 , V_279 ,
V_290 ) ;
if ( V_37 < 0 )
return V_37 ;
V_22 -> V_258 . V_291 = F_132 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_260 . V_161 = V_292 ;
V_2 -> V_260 . V_163 = V_293 ;
V_2 -> V_260 . V_162 = V_294 ;
return 0 ;
}
static int F_146 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 = F_124 ( V_22 ) ;
V_2 -> V_11 [ 0 ] . V_240 = true ;
return V_37 ;
}
static int F_147 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_204 * V_113 ;
int V_37 ;
V_37 = F_127 ( V_22 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_109 ( V_2 -> V_11 [ 0 ] . V_249 ,
V_241 ,
V_295 , 8 , 0 , & V_113 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_22 -> V_266 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_113 -> V_296 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_113 -> V_296 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_148 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_145 ( V_22 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_269 . V_271 = 8 ;
V_2 -> V_260 = V_297 ;
V_22 -> V_258 . V_291 = F_134 ;
V_22 -> V_258 . V_298 = F_146 ;
V_22 -> V_258 . V_299 = F_147 ;
F_142 ( V_22 , 8 ) ;
return 0 ;
}
static int F_149 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_141 ,
unsigned int V_142 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_186 = V_105 -> V_108 -> V_60 ;
int V_55 , V_37 ;
V_37 = F_139 ( V_10 , V_22 , V_141 , V_142 ,
V_105 ) ;
if ( V_37 < 0 )
return V_37 ;
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_54 , V_186 - 1 ) ;
for ( V_55 = 0 ; V_55 < V_186 ; V_55 ++ ) {
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_78 ,
( V_55 << 4 ) | V_55 ) ;
}
return 0 ;
}
static int F_150 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_141 ( V_22 , V_300 , V_301 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_260 . V_243 . V_302 = F_149 ;
return 0 ;
}
static int F_151 ( struct V_21 * V_22 )
{
return F_141 ( V_22 , V_303 , V_304 ) ;
}
static int T_5 F_152 ( void )
{
return F_153 ( & V_305 ) ;
}
static void T_6 F_154 ( void )
{
F_155 ( & V_305 ) ;
}
