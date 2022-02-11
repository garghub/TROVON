static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( F_2 ( V_2 , V_4 ) -> V_3 == V_3 )
return V_4 ;
F_3 ( V_6 L_1 , V_3 ) ;
return - V_7 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( F_5 ( V_2 , V_4 ) -> V_10 == V_9 )
return V_4 ;
F_3 ( V_6 L_2 , V_9 ) ;
return - V_7 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ )
if ( F_7 ( V_2 , V_12 ) -> V_11 == V_11 )
return V_12 ;
F_3 ( V_6 L_3 , V_11 ) ;
return - V_7 ;
}
static int F_8 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 ;
int V_4 ;
V_17 -> type = V_22 ;
V_4 = V_15 -> V_23 ;
V_21 = & F_2 ( V_2 , V_4 ) -> V_24 ;
F_10 ( & V_21 -> V_25 ) ;
V_17 -> V_26 = V_21 -> V_27 ? V_21 -> V_28 : 0 ;
F_11 ( & V_21 -> V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_18 * V_19 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 ;
int V_4 ;
V_4 = V_15 -> V_23 ;
V_21 = & F_2 ( V_2 , V_4 ) -> V_24 ;
F_10 ( & V_21 -> V_25 ) ;
if ( V_21 -> V_28 > F_13 ( V_30 -> V_31 . V_32 . V_33 ) ) {
F_11 ( & V_21 -> V_25 ) ;
F_14 () ;
return - V_7 ;
}
memset ( V_30 -> V_31 . V_32 . V_33 , 0 ,
F_13 ( V_30 -> V_31 . V_32 . V_33 ) ) ;
if ( V_21 -> V_27 )
memcpy ( V_30 -> V_31 . V_32 . V_33 , V_21 -> V_34 ,
V_21 -> V_28 ) ;
F_11 ( & V_21 -> V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 , int V_4 ,
int V_35 )
{
struct V_14 * V_36 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_37 ;
V_36 = F_16 ( & V_38 , V_19 ) ;
if ( ! V_36 )
return - V_39 ;
V_36 -> V_23 = V_4 ;
V_36 -> V_40 . V_35 = V_35 ;
V_37 = F_17 ( V_19 , F_2 ( V_2 , V_4 ) -> V_3 , V_36 ) ;
if ( V_37 < 0 )
return V_37 ;
F_2 ( V_2 , V_4 ) -> V_41 = V_36 ;
return 0 ;
}
static void F_18 ( struct V_18 * V_19 , T_1 V_3 ,
int * V_42 , int * V_43 )
{
int V_44 ;
V_44 = F_19 ( V_19 , V_3 , 0 ,
V_45 , 0 ) ;
* V_42 = V_44 >> 5 ;
* V_43 = V_44 & 0x1f ;
}
static void F_20 ( struct V_18 * V_19 , T_1 V_3 ,
int V_42 , int V_43 )
{
int V_44 ;
V_44 = ( V_42 << 5 ) | ( V_43 & 0x1f ) ;
F_21 ( V_19 , V_3 , 0 , V_46 , V_44 ) ;
}
static void F_22 ( struct V_18 * V_19 , T_1 V_3 ,
unsigned char V_44 )
{
F_21 ( V_19 , V_3 , 0 , V_47 , V_44 ) ;
}
static void F_23 ( struct V_18 * V_19 , T_1 V_3 )
{
if ( F_24 ( V_19 , V_3 ) & V_48 )
F_21 ( V_19 , V_3 , 0 ,
V_49 , V_50 ) ;
F_21 ( V_19 , V_3 , 0 ,
V_51 , V_52 ) ;
}
static int F_25 ( struct V_18 * V_19 , T_1 V_11 )
{
return 1 + F_19 ( V_19 , V_11 , 0 ,
V_53 , 0 ) ;
}
static void F_26 ( struct V_18 * V_19 ,
T_1 V_11 , int V_54 )
{
if ( V_54 != F_25 ( V_19 , V_11 ) )
F_21 ( V_19 , V_11 , 0 ,
V_55 , V_54 - 1 ) ;
}
static void F_27 ( void )
{
int V_56 , V_57 ;
struct V_58 * V_59 ;
for ( V_56 = 0 ; V_56 < F_13 ( V_60 ) ; V_56 ++ ) {
V_59 = V_60 + V_56 ;
V_59 -> V_61 = 0 ;
V_59 -> V_62 = 0 ;
for ( V_57 = 0 ; V_57 < F_13 ( V_59 -> V_63 ) ; V_57 ++ )
if ( V_59 -> V_63 [ V_57 ] ) {
V_59 -> V_61 ++ ;
V_59 -> V_62 |= V_59 -> V_63 [ V_57 ] ;
}
}
}
static int F_28 ( int V_64 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_13 ( V_60 ) ; V_56 ++ ) {
if ( V_60 [ V_56 ] . V_65 == V_64 )
break;
}
return V_56 ;
}
static int F_29 ( struct V_20 * V_21 , int V_61 )
{
int V_56 ;
int V_64 = 0 ;
int V_62 = 0 ;
char V_66 [ V_67 ] ;
if ( V_61 <= 2 )
return 0 ;
for ( V_56 = 0 ; V_56 < F_13 ( V_68 ) ; V_56 ++ ) {
if ( V_21 -> V_69 . V_70 & ( 1 << V_56 ) )
V_62 |= V_68 [ V_56 ] ;
}
for ( V_56 = 0 ; V_56 < F_13 ( V_60 ) ; V_56 ++ ) {
if ( V_61 == V_60 [ V_56 ] . V_61 &&
( V_62 & V_60 [ V_56 ] . V_62 ) ==
V_60 [ V_56 ] . V_62 ) {
V_64 = V_60 [ V_56 ] . V_65 ;
break;
}
}
if ( ! V_64 ) {
for ( V_56 = 0 ; V_56 < F_13 ( V_60 ) ; V_56 ++ ) {
if ( V_61 == V_60 [ V_56 ] . V_61 ) {
V_64 = V_60 [ V_56 ] . V_65 ;
break;
}
}
}
F_30 ( V_21 -> V_69 . V_70 , V_66 , sizeof( V_66 ) ) ;
F_31 ( L_4 ,
V_64 , V_61 , V_66 ) ;
return V_64 ;
}
static void F_32 ( struct V_18 * V_19 ,
T_1 V_3 )
{
#ifdef F_33
int V_56 ;
int V_71 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
V_71 = F_19 ( V_19 , V_3 , 0 ,
V_72 , V_56 ) ;
F_34 ( V_73 L_5 ,
V_71 >> 4 , V_71 & 0xf ) ;
}
#endif
}
static void F_35 ( struct V_18 * V_19 ,
T_1 V_3 ,
bool V_74 ,
int V_64 )
{
int V_56 ;
int V_37 ;
int V_75 ;
int V_76 [ 8 ] ;
V_75 = F_28 ( V_64 ) ;
if ( V_77 [ V_64 ] [ 1 ] == 0 ) {
for ( V_56 = 0 ; V_56 < V_60 [ V_75 ] . V_61 ; V_56 ++ )
V_77 [ V_64 ] [ V_56 ] = V_56 | ( V_56 << 4 ) ;
for (; V_56 < 8 ; V_56 ++ )
V_77 [ V_64 ] [ V_56 ] = 0xf | ( V_56 << 4 ) ;
}
if ( V_74 ) {
for ( V_56 = 0 ; V_56 < V_60 [ V_75 ] . V_61 ; V_56 ++ )
V_76 [ V_56 ] = V_56 | ( V_56 << 4 ) ;
for (; V_56 < 8 ; V_56 ++ )
V_76 [ V_56 ] = 0xf | ( V_56 << 4 ) ;
}
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
V_37 = F_21 ( V_19 , V_3 , 0 ,
V_78 ,
V_74 ? V_76 [ V_56 ] : V_77 [ V_64 ] [ V_56 ] ) ;
if ( V_37 ) {
F_31 ( V_79
L_6 ) ;
break;
}
}
F_32 ( V_19 , V_3 ) ;
}
static int F_36 ( unsigned char V_80 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_84 == V_80 )
return V_82 -> V_62 ;
}
return 0 ;
}
static int F_37 ( unsigned char V_80 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_84 == V_80 )
return V_82 -> V_85 ;
}
return 0x0f ;
}
static int F_38 ( unsigned char V_80 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_85 == V_80 )
return V_82 -> V_84 ;
}
return 0 ;
}
static int F_39 ( int V_86 )
{
struct V_81 * V_82 = V_83 ;
for (; V_82 -> V_84 ; V_82 ++ ) {
if ( V_82 -> V_62 == V_86 )
return V_82 -> V_84 ;
}
return 0 ;
}
static int F_40 ( int V_54 , unsigned char * V_84 )
{
int V_56 , V_87 = 0 , V_62 = 0 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
int V_88 = F_36 ( V_84 [ V_56 ] ) ;
if ( V_88 ) {
V_62 |= V_88 ;
V_87 ++ ;
}
}
for ( V_56 = 0 ; V_56 < F_13 ( V_60 ) ; V_56 ++ ) {
if ( ( V_54 == V_60 [ V_56 ] . V_61 ||
V_87 == V_60 [ V_56 ] . V_61 ) &&
( V_62 & V_60 [ V_56 ] . V_62 ) ==
V_60 [ V_56 ] . V_62 )
return V_60 [ V_56 ] . V_65 ;
}
return - 1 ;
}
static int F_41 ( struct V_18 * V_19 ,
T_1 V_3 ,
int V_54 , unsigned char * V_84 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
int V_44 , V_37 ;
if ( V_56 < V_54 )
V_44 = F_37 ( V_84 [ V_56 ] ) ;
else
V_44 = 0xf ;
V_44 |= ( V_56 << 4 ) ;
V_37 = F_21 ( V_19 , V_3 , 0 ,
V_78 , V_44 ) ;
if ( V_37 )
return - V_7 ;
}
return 0 ;
}
static void F_42 ( unsigned char * V_84 , int V_64 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
if ( V_56 < V_60 [ V_64 ] . V_61 )
V_84 [ V_56 ] = F_38 ( ( V_77 [ V_64 ] [ V_56 ] >> 4 ) & 0x0f ) ;
else
V_84 [ V_56 ] = 0 ;
}
}
static void F_43 ( struct V_18 * V_19 ,
T_1 V_3 , bool V_74 , int V_64 ,
int V_61 , unsigned char * V_84 ,
bool V_89 )
{
if ( ! V_74 && V_89 ) {
F_41 ( V_19 , V_3 ,
V_61 , V_84 ) ;
} else {
F_35 ( V_19 , V_3 , V_74 , V_64 ) ;
F_42 ( V_84 , V_64 ) ;
}
}
static void F_44 ( struct V_18 * V_19 ,
T_1 V_3 )
{
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_19 , V_3 , 0 , V_90 ,
V_91 ) ;
}
static void F_45 ( struct V_18 * V_19 ,
T_1 V_3 )
{
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_19 , V_3 , 0 , V_90 ,
V_92 ) ;
}
static void F_46 ( struct V_18 * V_19 , T_1 V_3 )
{
#ifdef F_33
int V_56 ;
int V_93 ;
V_93 = F_47 ( V_19 , V_3 ) ;
F_34 ( V_73 L_7 , V_93 ) ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
V_93 = F_19 ( V_19 , V_3 , 0 ,
V_94 , V_56 ) ;
F_34 ( V_73 L_8 , V_56 , V_93 ) ;
}
#endif
}
static void F_48 ( struct V_18 * V_19 , T_1 V_3 )
{
#ifdef F_49
int V_56 , V_57 ;
int V_93 ;
int V_95 , V_96 ;
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
V_93 = F_19 ( V_19 , V_3 , 0 ,
V_94 , V_56 ) ;
if ( V_93 == 0 )
continue;
F_20 ( V_19 , V_3 , V_56 , 0x0 ) ;
for ( V_57 = 1 ; V_57 < 1000 ; V_57 ++ ) {
F_22 ( V_19 , V_3 , 0x0 ) ;
F_18 ( V_19 , V_3 , & V_95 , & V_96 ) ;
if ( V_95 != V_56 )
F_50 ( V_97 L_9 ,
V_96 , V_95 , V_56 ) ;
if ( V_96 == 0 )
break;
}
F_50 ( V_97
L_10 ,
V_56 , V_93 , V_57 ) ;
}
#endif
}
static void F_51 ( struct V_98 * V_99 )
{
T_2 * V_32 = ( T_2 * ) V_99 ;
T_2 V_100 = 0 ;
int V_56 ;
V_99 -> V_101 = 0 ;
for ( V_56 = 0 ; V_56 < sizeof( * V_99 ) ; V_56 ++ )
V_100 += V_32 [ V_56 ] ;
V_99 -> V_101 = - V_100 ;
}
static void F_52 ( struct V_18 * V_19 ,
T_1 V_3 ,
T_2 * V_102 , int V_93 )
{
int V_56 ;
F_46 ( V_19 , V_3 ) ;
F_48 ( V_19 , V_3 ) ;
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
for ( V_56 = 0 ; V_56 < V_93 ; V_56 ++ )
F_22 ( V_19 , V_3 , V_102 [ V_56 ] ) ;
}
static bool F_53 ( struct V_18 * V_19 , T_1 V_3 ,
T_2 * V_102 , int V_93 )
{
T_2 V_44 ;
int V_56 ;
if ( F_19 ( V_19 , V_3 , 0 , V_103 , 0 )
!= V_91 )
return false ;
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
for ( V_56 = 0 ; V_56 < V_93 ; V_56 ++ ) {
V_44 = F_19 ( V_19 , V_3 , 0 ,
V_104 , 0 ) ;
if ( V_44 != V_102 [ V_56 ] )
return false ;
}
return true ;
}
static void F_54 ( struct V_18 * V_19 ,
struct V_105 * V_106 ,
bool V_74 )
{
T_1 V_3 = V_106 -> V_3 ;
int V_61 = V_106 -> V_61 ;
struct V_20 * V_21 ;
int V_64 ;
union V_107 V_108 ;
if ( ! V_61 )
return;
if ( F_55 ( V_19 ) )
F_21 ( V_19 , V_3 , 0 ,
V_49 ,
V_50 ) ;
V_21 = & V_106 -> V_24 ;
if ( ! V_21 -> V_109 )
return;
if ( ! V_74 && V_106 -> V_89 )
V_64 = F_40 ( V_61 , V_106 -> V_110 ) ;
else
V_64 = F_29 ( V_21 , V_61 ) ;
if ( V_64 < 0 )
V_64 = 0 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
if ( V_21 -> V_69 . V_111 == 0 ) {
struct V_98 * V_99 = & V_108 . V_112 ;
V_99 -> type = 0x84 ;
V_99 -> V_113 = 0x01 ;
V_99 -> V_114 = 0x0a ;
V_99 -> V_115 = V_61 - 1 ;
V_99 -> V_116 = V_64 ;
F_51 ( V_99 ) ;
} else if ( V_21 -> V_69 . V_111 == 1 ) {
struct V_117 * V_118 = & V_108 . V_119 ;
V_118 -> type = 0x84 ;
V_118 -> V_114 = 0x1b ;
V_118 -> V_113 = 0x11 << 2 ;
V_118 -> V_115 = V_61 - 1 ;
V_118 -> V_116 = V_64 ;
} else {
F_50 ( L_11 ,
V_3 ) ;
return;
}
F_43 ( V_19 , V_3 , V_74 , V_64 ,
V_61 , V_106 -> V_110 ,
V_106 -> V_89 ) ;
if ( ! F_53 ( V_19 , V_3 , V_108 . V_32 ,
sizeof( V_108 ) ) ) {
F_31 ( L_12
L_13 ,
V_3 ,
V_61 ) ;
F_45 ( V_19 , V_3 ) ;
F_52 ( V_19 , V_3 ,
V_108 . V_32 , sizeof( V_108 ) ) ;
F_44 ( V_19 , V_3 ) ;
}
V_106 -> V_74 = V_74 ;
}
static void F_56 ( struct V_18 * V_19 , unsigned int V_120 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_121 = V_120 >> V_122 ;
int V_3 ;
int V_4 ;
struct V_123 * V_124 ;
int V_125 = ( V_120 & V_126 ) >> V_127 ;
V_124 = F_57 ( V_19 , V_121 ) ;
if ( ! V_124 )
return;
V_3 = V_124 -> V_128 ;
V_124 -> V_129 = 1 ;
F_58 ( V_130 ,
L_14 ,
V_19 -> V_131 , V_3 , V_125 , ! ! ( V_120 & V_132 ) ,
! ! ( V_120 & V_133 ) , ! ! ( V_120 & V_134 ) ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
F_59 ( F_2 ( V_2 , V_4 ) , 1 ) ;
F_60 ( V_19 ) ;
}
static void F_61 ( struct V_18 * V_19 , unsigned int V_120 )
{
int V_121 = V_120 >> V_122 ;
int V_135 = ( V_120 & V_136 ) >> V_137 ;
int V_138 = ! ! ( V_120 & V_139 ) ;
int V_140 = ! ! ( V_120 & V_141 ) ;
F_34 ( V_97
L_15 ,
V_19 -> V_131 ,
V_121 ,
V_135 ,
V_138 ,
V_140 ) ;
if ( V_138 )
;
if ( V_140 )
;
}
static void F_62 ( struct V_18 * V_19 , unsigned int V_120 )
{
int V_121 = V_120 >> V_122 ;
int V_135 = ( V_120 & V_136 ) >> V_137 ;
if ( ! F_57 ( V_19 , V_121 ) ) {
F_50 ( V_97 L_16 , V_121 ) ;
return;
}
if ( V_135 == 0 )
F_56 ( V_19 , V_120 ) ;
else
F_61 ( V_19 , V_120 ) ;
}
static void F_63 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_128 )
{
int V_142 ;
if ( ! F_64 ( V_19 , V_11 , V_143 ) )
F_21 ( V_19 , V_11 , 0 , V_144 , V_143 ) ;
if ( ! F_64 ( V_19 , V_128 , V_143 ) ) {
F_21 ( V_19 , V_128 , 0 , V_144 ,
V_143 ) ;
F_65 ( 40 ) ;
V_142 = F_19 ( V_19 , V_128 , 0 , V_145 , 0 ) ;
V_142 = ( V_142 & V_146 ) >> V_147 ;
F_50 ( L_17 , V_128 , V_142 ) ;
}
}
static int F_66 ( struct V_18 * V_19 , T_1 V_11 ,
T_1 V_3 , T_3 V_148 , int V_149 )
{
int V_150 ;
int V_151 = 0 ;
if ( F_55 ( V_19 ) )
F_63 ( V_19 , V_11 , V_3 ) ;
if ( F_67 ( V_19 , V_3 ) & V_152 ) {
V_150 = F_19 ( V_19 , V_3 , 0 ,
V_153 , 0 ) ;
V_151 = V_150 & ~ V_154 ;
if ( F_68 ( V_149 ) )
V_151 |= V_155 ;
else
V_151 |= V_156 ;
F_31 ( L_18
L_19 ,
V_3 ,
V_150 == V_151 ? L_20 : L_21 ,
V_151 ) ;
if ( V_150 != V_151 )
F_21 ( V_19 , V_3 , 0 ,
V_51 ,
V_151 ) ;
}
if ( F_68 ( V_149 ) && ! V_151 ) {
F_31 ( L_22 ) ;
return - V_7 ;
}
F_69 ( V_19 , V_11 , V_148 , 0 , V_149 ) ;
return 0 ;
}
static int F_70 ( struct V_18 * V_19 ,
int V_4 , int * V_157 , int * V_158 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_105 * V_106 ;
struct V_159 * V_160 = NULL ;
int V_12 , V_161 = 0 ;
V_106 = F_2 ( V_2 , V_4 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_160 = F_7 ( V_2 , V_12 ) ;
if ( V_160 -> V_162 )
continue;
for ( V_161 = 0 ; V_161 < V_106 -> V_163 ; V_161 ++ )
if ( V_106 -> V_164 [ V_161 ] == V_160 -> V_11 )
break;
if ( V_161 == V_106 -> V_163 )
continue;
break;
}
if ( V_12 == V_2 -> V_13 )
return - V_165 ;
if ( V_157 )
* V_157 = V_12 ;
if ( V_158 )
* V_158 = V_161 ;
return 0 ;
}
static void F_71 ( struct V_18 * V_19 ,
T_1 V_3 , int V_161 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_128 , V_166 ;
int V_12 , V_167 ;
struct V_159 * V_160 ;
V_166 = V_19 -> V_168 + V_19 -> V_169 ;
for ( V_128 = V_19 -> V_168 ; V_128 < V_166 ; V_128 ++ ) {
unsigned int V_170 = F_24 ( V_19 , V_128 ) ;
unsigned int V_171 = F_72 ( V_170 ) ;
if ( V_171 != V_172 )
continue;
if ( V_128 == V_3 )
continue;
V_167 = F_19 ( V_19 , V_128 , 0 ,
V_173 , 0 ) ;
if ( V_167 != V_161 )
continue;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_160 = F_7 ( V_2 , V_12 ) ;
if ( ! V_160 -> V_162 ) {
F_31 ( L_23 ,
V_12 , V_128 ) ;
F_73 ( V_19 , V_128 , 0 ,
V_174 ,
V_12 ) ;
break;
}
}
}
}
static int F_74 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_177 * V_178 = V_176 -> V_178 ;
int V_4 , V_12 , V_161 = 0 ;
struct V_105 * V_106 ;
struct V_20 * V_21 ;
struct V_159 * V_160 = NULL ;
int V_37 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_75 ( V_4 < 0 ) )
return - V_7 ;
V_106 = F_2 ( V_2 , V_4 ) ;
V_21 = & V_106 -> V_24 ;
V_37 = F_70 ( V_19 , V_4 , & V_12 , & V_161 ) ;
if ( V_37 < 0 )
return V_37 ;
V_160 = F_7 ( V_2 , V_12 ) ;
V_160 -> V_162 = 1 ;
V_9 -> V_128 = V_160 -> V_11 ;
F_73 ( V_19 , V_106 -> V_3 , 0 ,
V_174 ,
V_161 ) ;
if ( F_55 ( V_19 ) )
F_71 ( V_19 , V_106 -> V_3 , V_161 ) ;
F_76 ( V_19 , V_4 , V_160 -> V_11 ) ;
V_9 -> V_179 = V_160 -> V_179 ;
V_9 -> V_180 = V_160 -> V_180 ;
V_9 -> V_181 = V_160 -> V_181 ;
V_9 -> V_182 = V_160 -> V_182 ;
V_9 -> V_183 = V_160 -> V_183 ;
if ( ! V_184 && V_21 -> V_27 ) {
F_77 ( & V_21 -> V_69 , V_9 ) ;
if ( V_9 -> V_179 > V_9 -> V_180 ||
! V_9 -> V_181 || ! V_9 -> V_182 ) {
V_160 -> V_162 = 0 ;
V_9 -> V_128 = 0 ;
F_78 ( V_19 , V_4 ) ;
return - V_165 ;
}
}
V_178 -> V_185 . V_179 = V_9 -> V_179 ;
V_178 -> V_185 . V_180 = V_9 -> V_180 ;
V_178 -> V_185 . V_182 = V_9 -> V_182 ;
V_178 -> V_185 . V_181 = V_9 -> V_181 ;
F_79 ( V_176 -> V_178 , 0 ,
V_186 , 2 ) ;
return 0 ;
}
static int F_80 ( struct V_18 * V_19 , int V_4 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_106 -> V_3 ;
if ( ! ( F_24 ( V_19 , V_3 ) & V_187 ) ) {
F_3 ( V_6
L_24
L_25 ,
V_3 , F_24 ( V_19 , V_3 ) ) ;
return - V_7 ;
}
V_106 -> V_163 = F_81 ( V_19 , V_3 ,
V_106 -> V_164 ,
V_188 ) ;
return 0 ;
}
static void F_59 ( struct V_105 * V_106 , int V_189 )
{
struct V_18 * V_19 = V_106 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = & V_2 -> V_190 ;
struct V_20 * V_191 = & V_106 -> V_24 ;
T_1 V_3 = V_106 -> V_3 ;
int V_192 = F_82 ( V_19 , V_3 ) ;
bool V_193 = false ;
bool V_194 = false ;
V_191 -> V_109 = ! ! ( V_192 & V_195 ) ;
if ( V_191 -> V_109 )
V_21 -> V_27 = ! ! ( V_192 & V_196 ) ;
else
V_21 -> V_27 = false ;
F_58 ( V_130 ,
L_26 ,
V_19 -> V_131 , V_3 , V_191 -> V_109 , V_21 -> V_27 ) ;
if ( V_21 -> V_27 ) {
if ( F_83 ( V_19 , V_3 , V_21 -> V_34 ,
& V_21 -> V_28 ) < 0 )
V_21 -> V_27 = false ;
else {
memset ( & V_21 -> V_69 , 0 , sizeof( struct V_197 ) ) ;
if ( F_84 ( & V_21 -> V_69 , V_21 -> V_34 ,
V_21 -> V_28 ) < 0 )
V_21 -> V_27 = false ;
}
if ( V_21 -> V_27 ) {
F_85 ( & V_21 -> V_69 ) ;
V_193 = true ;
}
else if ( V_189 ) {
F_86 ( V_19 -> V_198 -> V_199 ,
& V_106 -> V_200 ,
F_87 ( 300 ) ) ;
return;
}
}
F_10 ( & V_191 -> V_25 ) ;
if ( V_191 -> V_27 && ! V_21 -> V_27 ) {
V_193 = true ;
V_194 = true ;
}
if ( V_193 ) {
bool V_201 = V_191 -> V_27 ;
V_191 -> V_27 = V_21 -> V_27 ;
V_194 = V_191 -> V_28 != V_21 -> V_28 ||
memcmp ( V_191 -> V_34 , V_21 -> V_34 ,
V_21 -> V_28 ) != 0 ;
if ( V_194 )
memcpy ( V_191 -> V_34 , V_21 -> V_34 ,
V_21 -> V_28 ) ;
V_191 -> V_28 = V_21 -> V_28 ;
V_191 -> V_69 = V_21 -> V_69 ;
if ( F_55 ( V_19 ) &&
V_21 -> V_27 && ! V_201 && V_106 -> V_202 )
F_54 ( V_19 , V_106 ,
V_106 -> V_74 ) ;
}
F_11 ( & V_191 -> V_25 ) ;
if ( V_194 )
F_88 ( V_19 -> V_198 -> V_203 ,
V_204 | V_205 ,
& V_106 -> V_41 -> V_40 ) ;
}
static void F_89 ( struct V_206 * V_200 )
{
struct V_105 * V_106 =
F_90 ( F_91 ( V_200 ) , struct V_105 , V_200 ) ;
if ( V_106 -> V_207 ++ > 6 )
V_106 -> V_207 = 0 ;
F_59 ( V_106 , V_106 -> V_207 ) ;
}
static int F_92 ( struct V_18 * V_19 , T_1 V_3 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_208 , V_209 ;
int V_4 ;
struct V_105 * V_106 ;
int V_37 ;
V_208 = F_67 ( V_19 , V_3 ) ;
if ( ! ( V_208 & ( V_210 | V_211 ) ) )
return 0 ;
V_209 = F_93 ( V_19 , V_3 ) ;
if ( F_94 ( V_209 ) == V_212 )
return 0 ;
if ( F_55 ( V_19 ) )
F_95 ( V_19 , V_3 ) ;
V_4 = V_2 -> V_5 ;
V_106 = F_96 ( & V_2 -> V_213 ) ;
if ( ! V_106 )
return - V_39 ;
V_106 -> V_3 = V_3 ;
V_106 -> V_74 = false ;
V_37 = F_80 ( V_19 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_97 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_159 * V_160 ;
unsigned int V_214 ;
int V_37 ;
V_214 = F_24 ( V_19 , V_11 ) ;
V_214 = F_98 ( V_214 ) ;
V_160 = F_96 ( & V_2 -> V_215 ) ;
if ( ! V_160 )
return - V_39 ;
V_160 -> V_11 = V_11 ;
V_160 -> V_179 = 2 ;
if ( V_214 <= 16 ) {
V_160 -> V_180 = V_214 ;
if ( V_214 > V_2 -> V_180 )
V_2 -> V_180 = V_214 ;
}
V_37 = F_99 ( V_19 , V_11 ,
& V_160 -> V_181 ,
& V_160 -> V_182 ,
& V_160 -> V_183 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 -> V_13 < F_13 ( V_2 -> V_216 ) )
V_2 -> V_216 [ V_2 -> V_13 ] = V_11 ;
V_2 -> V_13 ++ ;
return 0 ;
}
static int F_100 ( struct V_18 * V_19 )
{
T_1 V_128 ;
int V_56 , V_217 ;
V_217 = F_101 ( V_19 , V_19 -> V_218 , & V_128 ) ;
if ( ! V_128 || V_217 < 0 ) {
F_3 ( V_6 L_27 ) ;
return - V_7 ;
}
for ( V_56 = 0 ; V_56 < V_217 ; V_56 ++ , V_128 ++ ) {
unsigned int V_208 ;
unsigned int type ;
V_208 = F_24 ( V_19 , V_128 ) ;
type = F_72 ( V_208 ) ;
if ( ! ( V_208 & V_219 ) )
continue;
switch ( type ) {
case V_220 :
F_97 ( V_19 , V_128 ) ;
break;
case V_172 :
F_92 ( V_19 , V_128 ) ;
break;
}
}
#ifdef F_102
if ( V_19 -> V_221 == 0x80862806 )
V_19 -> V_198 -> V_222 = 1 ;
else if ( ! ( F_103 ( V_19 , V_19 -> V_218 , V_223 ) &
V_224 ) )
V_19 -> V_198 -> V_222 = 1 ;
#endif
return 0 ;
}
static bool F_104 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_225 * V_226 ;
bool V_74 ;
F_10 ( & V_19 -> V_227 ) ;
V_226 = F_105 ( V_19 , V_11 ) ;
V_74 = ! ! ( V_226 -> V_228 & V_229 ) ;
F_11 ( & V_19 -> V_227 ) ;
return V_74 ;
}
static int F_106 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_148 ,
unsigned int V_149 ,
struct V_175 * V_176 )
{
T_1 V_11 = V_9 -> V_128 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = F_4 ( V_2 , V_9 ) ;
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_106 -> V_3 ;
bool V_74 ;
V_74 = F_104 ( V_19 , V_11 ) ;
V_106 -> V_61 = V_176 -> V_178 -> V_61 ;
V_106 -> V_202 = true ;
F_26 ( V_19 , V_11 , V_176 -> V_178 -> V_61 ) ;
F_54 ( V_19 , V_106 , V_74 ) ;
return F_66 ( V_19 , V_11 , V_3 , V_148 , V_149 ) ;
}
static int F_107 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_175 * V_176 )
{
F_108 ( V_19 , V_9 -> V_128 ) ;
return 0 ;
}
static int F_109 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_12 , V_4 ;
struct V_159 * V_160 ;
struct V_105 * V_106 ;
if ( V_9 -> V_128 ) {
V_12 = F_6 ( V_2 , V_9 -> V_128 ) ;
if ( F_75 ( V_12 < 0 ) )
return - V_7 ;
V_160 = F_7 ( V_2 , V_12 ) ;
F_75 ( ! V_160 -> V_162 ) ;
V_160 -> V_162 = 0 ;
V_9 -> V_128 = 0 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_75 ( V_4 < 0 ) )
return - V_7 ;
V_106 = F_2 ( V_2 , V_4 ) ;
F_78 ( V_19 , V_4 ) ;
V_106 -> V_89 = false ;
memset ( V_106 -> V_110 , 0 , sizeof( V_106 -> V_110 ) ) ;
V_106 -> V_202 = false ;
V_106 -> V_61 = 0 ;
}
return 0 ;
}
static int F_110 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_230 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_231 ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_17 -> type = V_232 ;
V_17 -> V_26 = V_2 -> V_180 ;
V_17 -> V_31 . integer . V_233 = 0 ;
V_17 -> V_31 . integer . V_234 = V_235 ;
return 0 ;
}
static int F_111 ( struct V_14 * V_15 , int V_236 ,
unsigned int V_93 , unsigned int T_4 * V_237 )
{
struct V_230 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_231 ;
struct V_1 * V_2 = V_19 -> V_2 ;
const unsigned int V_238 =
V_239 | V_240 | V_241 | V_242 | V_243 | V_244 | V_245 | V_246 ;
unsigned int T_4 * V_247 ;
int V_54 , V_26 = 0 ;
if ( V_93 < 8 )
return - V_39 ;
if ( F_112 ( V_248 , V_237 ) )
return - V_249 ;
V_93 -= 8 ;
V_247 = V_237 + 2 ;
for ( V_54 = 2 ; V_54 <= V_2 -> V_180 ; V_54 ++ ) {
int V_56 , V_80 ;
struct V_58 * V_250 ;
V_250 = V_60 ;
for ( V_56 = 0 ; V_56 < F_13 ( V_60 ) ; V_56 ++ , V_250 ++ ) {
int V_251 = V_54 * 4 ;
if ( V_250 -> V_61 != V_54 )
continue;
if ( V_250 -> V_62 & ~ V_238 )
continue;
if ( V_93 < 8 )
return - V_39 ;
if ( F_112 ( V_252 , V_247 ) ||
F_112 ( V_251 , V_247 + 1 ) )
return - V_249 ;
V_247 += 2 ;
V_93 -= 8 ;
V_26 += 8 ;
if ( V_93 < V_251 )
return - V_39 ;
V_93 -= V_251 ;
V_26 += V_251 ;
for ( V_80 = 7 ; V_80 >= 0 ; V_80 -- ) {
int V_86 = V_250 -> V_63 [ V_80 ] ;
if ( ! V_86 )
continue;
if ( F_112 ( F_39 ( V_86 ) , V_247 ) )
return - V_249 ;
V_247 ++ ;
}
}
}
if ( F_112 ( V_26 , V_237 + 1 ) )
return - V_249 ;
return 0 ;
}
static int F_113 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_230 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_231 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_23 ;
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < F_13 ( V_106 -> V_110 ) ; V_56 ++ )
V_30 -> V_31 . integer . V_31 [ V_56 ] = V_106 -> V_110 [ V_56 ] ;
return 0 ;
}
static int F_114 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_230 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_231 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_23 ;
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
unsigned int V_253 ;
struct V_175 * V_176 ;
unsigned char V_110 [ 8 ] ;
int V_56 , V_64 , V_254 = 0 ;
V_253 = F_115 ( V_15 , & V_30 -> V_40 ) ;
V_176 = F_116 ( V_69 , V_253 ) ;
if ( ! V_176 || ! V_176 -> V_178 )
return 0 ;
switch ( V_176 -> V_178 -> V_228 -> V_255 ) {
case V_256 :
case V_257 :
break;
case V_258 :
V_254 = 1 ;
break;
default:
return - V_259 ;
}
memset ( V_110 , 0 , sizeof( V_110 ) ) ;
for ( V_56 = 0 ; V_56 < F_13 ( V_110 ) ; V_56 ++ )
V_110 [ V_56 ] = V_30 -> V_31 . integer . V_31 [ V_56 ] ;
if ( ! memcmp ( V_110 , V_106 -> V_110 , sizeof( V_110 ) ) )
return 0 ;
V_64 = F_40 ( F_13 ( V_110 ) , V_110 ) ;
if ( V_64 < 0 )
return - V_7 ;
V_106 -> V_89 = true ;
memcpy ( V_106 -> V_110 , V_110 , sizeof( V_110 ) ) ;
if ( V_254 )
F_54 ( V_19 , V_106 , V_106 -> V_74 ) ;
return 0 ;
}
static int F_117 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_260 * V_69 ;
struct V_8 * V_261 ;
struct V_105 * V_106 ;
V_106 = F_2 ( V_2 , V_4 ) ;
sprintf ( V_106 -> V_262 , L_28 , V_4 ) ;
V_69 = F_96 ( & V_2 -> V_263 ) ;
if ( ! V_69 )
return - V_39 ;
V_69 -> V_264 = V_106 -> V_262 ;
V_69 -> V_265 = V_266 ;
V_69 -> V_267 = true ;
V_261 = & V_69 -> V_10 [ V_268 ] ;
V_261 -> V_269 = 1 ;
V_261 -> V_270 = V_271 ;
}
V_19 -> V_272 = V_2 -> V_5 ;
V_19 -> V_273 = V_2 -> V_263 . V_274 ;
return 0 ;
}
static int F_118 ( struct V_18 * V_19 , int V_4 )
{
char V_275 [ 32 ] = L_29 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
int V_276 = F_5 ( V_2 , V_4 ) -> V_35 ;
if ( V_276 > 0 )
sprintf ( V_275 + strlen ( V_275 ) , L_30 , V_276 ) ;
if ( ! F_119 ( V_19 , V_106 -> V_3 ) )
strncat ( V_275 , L_31 ,
sizeof( V_275 ) - strlen ( V_275 ) - 1 ) ;
return F_120 ( V_19 , V_106 -> V_3 , V_275 , 0 ) ;
}
static int F_121 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_37 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
V_37 = F_118 ( V_19 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_122 ( V_19 ,
V_106 -> V_3 ,
V_106 -> V_164 [ 0 ] ,
V_266 ) ;
if ( V_37 < 0 )
return V_37 ;
F_78 ( V_19 , V_4 ) ;
V_37 = F_15 ( V_19 , V_4 ,
F_5 ( V_2 , V_4 ) -> V_35 ) ;
if ( V_37 < 0 )
return V_37 ;
F_59 ( V_106 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_230 * V_110 ;
struct V_14 * V_36 ;
int V_56 ;
if ( ! V_19 -> V_273 [ V_4 ] . V_277 )
break;
V_37 = F_123 ( V_19 -> V_273 [ V_4 ] . V_277 ,
V_268 ,
NULL , 0 , V_4 , & V_110 ) ;
if ( V_37 < 0 )
return V_37 ;
V_110 -> V_231 = V_19 ;
V_36 = V_110 -> V_36 ;
for ( V_56 = 0 ; V_56 < V_36 -> V_26 ; V_56 ++ )
V_36 -> V_278 [ V_56 ] . V_279 |= V_280 ;
V_36 -> V_69 = F_110 ;
V_36 -> V_281 = F_113 ;
V_36 -> V_282 = F_114 ;
V_36 -> V_237 . V_80 = F_111 ;
}
return 0 ;
}
static int F_124 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
struct V_20 * V_21 = & V_106 -> V_24 ;
V_106 -> V_19 = V_19 ;
F_125 ( & V_21 -> V_25 ) ;
F_126 ( & V_106 -> V_200 , F_89 ) ;
F_127 ( V_19 , V_21 , V_4 ) ;
}
return 0 ;
}
static int F_128 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_106 -> V_3 ;
F_23 ( V_19 , V_3 ) ;
F_129 ( V_19 , V_3 , V_3 ) ;
}
return 0 ;
}
static void F_130 ( struct V_1 * V_2 , int V_283 )
{
F_131 ( & V_2 -> V_213 , sizeof( struct V_105 ) , V_283 ) ;
F_131 ( & V_2 -> V_215 , sizeof( struct V_159 ) , V_283 ) ;
F_131 ( & V_2 -> V_263 , sizeof( struct V_260 ) , V_283 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 ( & V_2 -> V_213 ) ;
F_133 ( & V_2 -> V_215 ) ;
F_133 ( & V_2 -> V_263 ) ;
}
static void F_134 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
struct V_20 * V_21 = & V_106 -> V_24 ;
F_135 ( & V_106 -> V_200 ) ;
F_136 ( V_19 , V_21 ) ;
}
F_137 ( V_19 -> V_198 -> V_199 ) ;
F_132 ( V_2 ) ;
F_138 ( V_2 ) ;
}
static int F_139 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
F_128 ( V_19 ) ;
F_140 ( V_19 ) ;
F_141 ( V_19 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_105 * V_106 = F_2 ( V_2 , V_4 ) ;
F_59 ( V_106 , 1 ) ;
}
return 0 ;
}
static void F_95 ( struct V_18 * V_19 ,
T_1 V_128 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_284 [ 4 ] ;
int V_285 ;
V_285 = F_81 ( V_19 , V_128 , V_284 , F_13 ( V_284 ) ) ;
if ( V_285 == V_2 -> V_13 &&
! memcmp ( V_284 , V_2 -> V_216 , V_2 -> V_13 * sizeof( T_1 ) ) )
return;
F_31 ( L_32 , V_128 ) ;
F_142 ( V_19 , V_128 , V_2 -> V_13 , V_2 -> V_216 ) ;
}
static void F_143 ( struct V_18 * V_19 ,
bool V_286 )
{
unsigned int V_287 ;
V_287 = F_19 ( V_19 , V_288 , 0 ,
V_289 , 0 ) ;
if ( V_287 == - 1 || V_287 & V_290 )
return;
V_287 |= V_290 ;
V_287 = F_19 ( V_19 , V_288 , 0 ,
V_291 , V_287 ) ;
if ( V_287 == - 1 )
return;
if ( V_286 )
F_144 ( V_19 ) ;
}
static void F_145 ( struct V_18 * V_19 )
{
unsigned int V_287 ;
V_287 = F_19 ( V_19 , V_288 , 0 ,
V_289 , 0 ) ;
if ( V_287 == - 1 || V_287 & V_292 )
return;
V_287 |= V_292 ;
F_73 ( V_19 , V_288 , 0 ,
V_291 , V_287 ) ;
}
static void F_146 ( struct V_18 * V_19 , T_1 V_293 ,
unsigned int V_294 )
{
if ( V_294 == V_143 ) {
F_143 ( V_19 , false ) ;
F_145 ( V_19 ) ;
}
F_19 ( V_19 , V_293 , 0 , V_144 , V_294 ) ;
F_147 ( V_19 , V_293 , V_294 ) ;
}
static int F_148 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_149 ( sizeof( * V_2 ) , V_295 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_19 -> V_2 = V_2 ;
F_130 ( V_2 , 4 ) ;
if ( F_55 ( V_19 ) ) {
F_143 ( V_19 , true ) ;
F_145 ( V_19 ) ;
}
if ( F_100 ( V_19 ) < 0 ) {
V_19 -> V_2 = NULL ;
F_138 ( V_2 ) ;
return - V_7 ;
}
V_19 -> V_296 = V_297 ;
if ( F_55 ( V_19 ) ) {
V_19 -> V_296 . V_298 = F_146 ;
V_19 -> V_299 = true ;
}
F_124 ( V_19 ) ;
F_27 () ;
return 0 ;
}
static int F_150 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_260 * V_69 ;
unsigned int V_214 ;
struct V_8 * V_261 ;
struct V_159 * V_160 ;
V_160 = F_7 ( V_2 , 0 ) ;
V_214 = F_24 ( V_19 , V_160 -> V_11 ) ;
V_214 = F_98 ( V_214 ) ;
V_69 = F_96 ( & V_2 -> V_263 ) ;
if ( ! V_69 )
return - V_39 ;
V_69 -> V_264 = F_2 ( V_2 , 0 ) -> V_262 ;
sprintf ( V_69 -> V_264 , L_33 ) ;
V_69 -> V_265 = V_266 ;
V_261 = & V_69 -> V_10 [ V_268 ] ;
* V_261 = V_2 -> V_300 ;
V_261 -> V_128 = V_160 -> V_11 ;
if ( V_261 -> V_180 <= 2 && V_214 && V_214 <= 16 )
V_261 -> V_180 = V_214 ;
V_19 -> V_272 = 1 ;
V_19 -> V_273 = V_69 ;
return 0 ;
}
static void F_151 ( struct V_18 * V_19 ,
unsigned int V_120 )
{
F_152 ( V_19 ) ;
F_60 ( V_19 ) ;
}
static int F_153 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_159 * V_160 ;
int V_37 ;
V_160 = F_7 ( V_2 , 0 ) ;
V_37 = F_154 ( V_19 , V_160 -> V_11 ,
V_160 -> V_11 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_155 ( V_19 , 0 ) ;
}
static int F_156 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_105 * V_106 = F_2 ( V_2 , 0 ) ;
T_1 V_301 = V_106 -> V_3 ;
F_21 ( V_19 , V_301 , 0 ,
V_51 , V_52 ) ;
if ( F_24 ( V_19 , V_301 ) & V_48 )
F_21 ( V_19 , V_301 , 0 , V_49 ,
V_50 ) ;
F_129 ( V_19 , V_301 , V_301 ) ;
return 0 ;
}
static void F_157 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_132 ( V_2 ) ;
F_138 ( V_2 ) ;
}
static int F_158 ( struct V_18 * V_19 )
{
F_159 ( V_19 , V_302 ) ;
return 0 ;
}
static int F_160 ( struct V_18 * V_19 )
{
F_159 ( V_19 , V_303 ) ;
return 0 ;
}
static int F_161 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_304 * V_305 = NULL ;
switch ( V_19 -> V_306 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_305 = & V_307 ;
break;
case 0x10de0007 :
V_305 = & V_308 ;
break;
default:
break;
}
if ( V_305 != NULL ) {
V_304 ( V_176 -> V_178 , 0 ,
V_186 ,
V_305 ) ;
} else {
F_79 ( V_176 -> V_178 , 0 ,
V_186 , 2 ) ;
}
return F_162 ( V_19 , & V_2 -> V_309 ) ;
}
static int F_163 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_164 ( V_19 , & V_2 -> V_309 ) ;
}
static int F_165 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_148 ,
unsigned int V_149 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_166 ( V_19 , & V_2 -> V_309 ,
V_148 , V_149 , V_176 ) ;
}
static int F_167 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_3 )
{
struct V_1 * V_2 ;
struct V_159 * V_160 ;
struct V_105 * V_106 ;
V_2 = F_149 ( sizeof( * V_2 ) , V_295 ) ;
if ( ! V_2 )
return - V_39 ;
V_19 -> V_2 = V_2 ;
F_130 ( V_2 , 1 ) ;
V_2 -> V_309 . V_310 = 0 ;
V_2 -> V_309 . V_311 = 2 ;
V_2 -> V_309 . V_312 = V_11 ;
V_2 -> V_13 = 1 ;
V_2 -> V_5 = 1 ;
V_106 = F_96 ( & V_2 -> V_213 ) ;
V_160 = F_96 ( & V_2 -> V_215 ) ;
if ( ! V_106 || ! V_160 ) {
F_157 ( V_19 ) ;
return - V_39 ;
}
V_160 -> V_11 = V_11 ;
V_106 -> V_3 = V_3 ;
V_2 -> V_300 = V_313 ;
V_19 -> V_296 = V_314 ;
return 0 ;
}
static void F_168 ( struct V_18 * V_19 ,
int V_61 )
{
unsigned int V_315 ;
int V_316 = V_61 ? ( V_61 - 1 ) : 1 ;
switch ( V_61 ) {
default:
case 0 :
case 2 :
V_315 = 0x00 ;
break;
case 4 :
V_315 = 0x08 ;
break;
case 6 :
V_315 = 0x0b ;
break;
case 8 :
V_315 = 0x13 ;
break;
}
F_21 ( V_19 , 0x1 , 0 ,
V_317 , V_315 ) ;
F_21 ( V_19 , 0x1 , 0 ,
V_318 ,
( 0x71 - V_316 - V_315 ) ) ;
}
static int F_169 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_56 ;
F_21 ( V_19 , V_319 ,
0 , V_320 , 0 ) ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
F_21 ( V_19 , V_321 [ V_56 ] , 0 ,
V_320 , 0 ) ;
F_21 ( V_19 , V_321 [ V_56 ] , 0 ,
V_322 , 0 ) ;
}
F_168 ( V_19 , 8 ) ;
return F_164 ( V_19 , & V_2 -> V_309 ) ;
}
static int F_170 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_148 ,
unsigned int V_149 ,
struct V_175 * V_176 )
{
int V_54 ;
unsigned int V_323 , V_324 ;
int V_56 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_225 * V_226 ;
struct V_159 * V_160 ;
F_10 ( & V_19 -> V_227 ) ;
V_160 = F_7 ( V_2 , 0 ) ;
V_226 = F_105 ( V_19 , V_160 -> V_11 ) ;
V_54 = V_176 -> V_178 -> V_61 ;
V_323 = 0x2 ;
if ( V_19 -> V_325 && ( V_226 -> V_326 & V_327 ) )
F_21 ( V_19 ,
V_319 ,
0 ,
V_328 ,
V_226 -> V_326 & ~ V_327 & 0xff ) ;
F_21 ( V_19 , V_319 , 0 ,
V_320 , ( V_148 << 4 ) | 0x0 ) ;
F_21 ( V_19 , V_319 , 0 ,
V_322 , V_149 ) ;
if ( V_19 -> V_325 && ( V_226 -> V_326 & V_327 ) ) {
F_21 ( V_19 ,
V_319 ,
0 ,
V_328 ,
V_226 -> V_326 & 0xff ) ;
F_21 ( V_19 ,
V_319 ,
0 ,
V_329 , V_323 ) ;
}
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
if ( V_54 == 2 )
V_324 = 0 ;
else
V_324 = V_56 * 2 ;
if ( V_19 -> V_325 &&
( V_226 -> V_326 & V_327 ) )
F_21 ( V_19 ,
V_321 [ V_56 ] ,
0 ,
V_328 ,
V_226 -> V_326 & ~ V_327 & 0xff ) ;
F_21 ( V_19 ,
V_321 [ V_56 ] ,
0 ,
V_320 ,
( V_148 << 4 ) | V_324 ) ;
F_21 ( V_19 ,
V_321 [ V_56 ] ,
0 ,
V_322 ,
V_149 ) ;
if ( V_19 -> V_325 &&
( V_226 -> V_326 & V_327 ) ) {
F_21 ( V_19 ,
V_321 [ V_56 ] ,
0 ,
V_328 ,
V_226 -> V_326 & 0xff ) ;
F_21 ( V_19 ,
V_321 [ V_56 ] ,
0 ,
V_329 , V_323 ) ;
}
}
F_168 ( V_19 , V_54 ) ;
F_11 ( & V_19 -> V_227 ) ;
return 0 ;
}
static int F_171 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_37 = F_167 ( V_19 , V_319 ,
V_330 ) ;
if ( V_37 < 0 )
return V_37 ;
V_19 -> V_296 . V_331 = F_158 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_300 . V_181 = V_332 ;
V_2 -> V_300 . V_183 = V_333 ;
V_2 -> V_300 . V_182 = V_334 ;
return 0 ;
}
static int F_172 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_37 = F_150 ( V_19 ) ;
if ( ! V_37 ) {
struct V_260 * V_69 = F_5 ( V_2 , 0 ) ;
V_69 -> V_267 = true ;
}
return V_37 ;
}
static int F_173 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_260 * V_69 ;
struct V_230 * V_110 ;
int V_37 ;
V_37 = F_153 ( V_19 ) ;
if ( V_37 < 0 )
return V_37 ;
V_69 = F_5 ( V_2 , 0 ) ;
V_37 = F_123 ( V_69 -> V_277 ,
V_268 ,
V_335 , 8 , 0 , & V_110 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_19 -> V_306 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_110 -> V_336 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_110 -> V_336 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_174 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_37 = F_171 ( V_19 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_309 . V_311 = 8 ;
V_2 -> V_300 = V_337 ;
V_19 -> V_296 . V_331 = F_160 ;
V_19 -> V_296 . V_338 = F_172 ;
V_19 -> V_296 . V_339 = F_173 ;
F_168 ( V_19 , 8 ) ;
return 0 ;
}
static int F_175 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_148 ,
unsigned int V_149 ,
struct V_175 * V_176 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_159 * V_160 = F_7 ( V_2 , 0 ) ;
int V_214 = V_176 -> V_178 -> V_61 ;
int V_56 , V_37 ;
V_37 = F_165 ( V_9 , V_19 , V_148 , V_149 ,
V_176 ) ;
if ( V_37 < 0 )
return V_37 ;
F_21 ( V_19 , V_160 -> V_11 , 0 ,
V_55 , V_214 - 1 ) ;
for ( V_56 = 0 ; V_56 < V_214 ; V_56 ++ ) {
F_21 ( V_19 , V_160 -> V_11 , 0 ,
V_78 ,
( V_56 << 4 ) | V_56 ) ;
}
return 0 ;
}
static int F_176 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_37 = F_167 ( V_19 , V_340 , V_341 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_300 . V_270 . V_342 = F_175 ;
return 0 ;
}
static int F_177 ( struct V_18 * V_19 )
{
return F_167 ( V_19 , V_343 , V_344 ) ;
}
static int T_5 F_178 ( void )
{
return F_179 ( & V_345 ) ;
}
static void T_6 F_180 ( void )
{
F_181 ( & V_345 ) ;
}
