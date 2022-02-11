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
static void F_54 ( struct V_18 * V_19 , int V_4 ,
bool V_74 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_108 -> V_3 ;
int V_61 = V_106 -> V_109 -> V_61 ;
struct V_20 * V_21 ;
int V_64 ;
union V_110 V_111 ;
V_21 = & V_108 -> V_24 ;
if ( ! V_21 -> V_112 )
return;
if ( ! V_74 && V_108 -> V_89 )
V_64 = F_40 ( V_61 , V_108 -> V_113 ) ;
else
V_64 = F_29 ( V_21 , V_61 ) ;
if ( V_64 < 0 )
V_64 = 0 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
if ( V_21 -> V_69 . V_114 == 0 ) {
struct V_98 * V_99 = & V_111 . V_115 ;
V_99 -> type = 0x84 ;
V_99 -> V_116 = 0x01 ;
V_99 -> V_117 = 0x0a ;
V_99 -> V_118 = V_61 - 1 ;
V_99 -> V_119 = V_64 ;
F_51 ( V_99 ) ;
} else if ( V_21 -> V_69 . V_114 == 1 ) {
struct V_120 * V_121 = & V_111 . V_122 ;
V_121 -> type = 0x84 ;
V_121 -> V_117 = 0x1b ;
V_121 -> V_116 = 0x11 << 2 ;
V_121 -> V_118 = V_61 - 1 ;
V_121 -> V_119 = V_64 ;
} else {
F_50 ( L_11 ,
V_3 ) ;
return;
}
if ( ! F_53 ( V_19 , V_3 , V_111 . V_32 ,
sizeof( V_111 ) ) ) {
F_31 ( L_12
L_13 ,
V_3 ,
V_61 ) ;
F_43 ( V_19 , V_3 , V_74 , V_64 ,
V_61 , V_108 -> V_113 ,
V_108 -> V_89 ) ;
F_45 ( V_19 , V_3 ) ;
F_52 ( V_19 , V_3 ,
V_111 . V_32 , sizeof( V_111 ) ) ;
F_44 ( V_19 , V_3 ) ;
} else {
if ( V_108 -> V_74 != V_74 )
F_43 ( V_19 , V_3 , V_74 , V_64 ,
V_61 , V_108 -> V_113 ,
V_108 -> V_89 ) ;
}
V_108 -> V_74 = V_74 ;
}
static void F_55 ( struct V_18 * V_19 , unsigned int V_123 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_124 = V_123 >> V_125 ;
int V_3 ;
int V_4 ;
struct V_126 * V_127 ;
V_127 = F_56 ( V_19 , V_124 ) ;
if ( ! V_127 )
return;
V_3 = V_127 -> V_128 ;
V_127 -> V_129 = 1 ;
F_57 ( V_130 ,
L_14 ,
V_19 -> V_131 , V_3 ,
! ! ( V_123 & V_132 ) , ! ! ( V_123 & V_133 ) ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
F_58 ( F_2 ( V_2 , V_4 ) , 1 ) ;
F_59 ( V_19 ) ;
}
static void F_60 ( struct V_18 * V_19 , unsigned int V_123 )
{
int V_124 = V_123 >> V_125 ;
int V_134 = ( V_123 & V_135 ) >> V_136 ;
int V_137 = ! ! ( V_123 & V_138 ) ;
int V_139 = ! ! ( V_123 & V_140 ) ;
F_34 ( V_97
L_15 ,
V_19 -> V_131 ,
V_124 ,
V_134 ,
V_137 ,
V_139 ) ;
if ( V_137 )
;
if ( V_139 )
;
}
static void F_61 ( struct V_18 * V_19 , unsigned int V_123 )
{
int V_124 = V_123 >> V_125 ;
int V_134 = ( V_123 & V_135 ) >> V_136 ;
if ( ! F_56 ( V_19 , V_124 ) ) {
F_50 ( V_97 L_16 , V_124 ) ;
return;
}
if ( V_134 == 0 )
F_55 ( V_19 , V_123 ) ;
else
F_60 ( V_19 , V_123 ) ;
}
static void F_62 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_128 )
{
int V_141 , V_142 , V_143 ;
if ( ! F_63 ( V_19 , V_11 , V_144 ) )
F_21 ( V_19 , V_11 , 0 , V_145 , V_144 ) ;
if ( ! F_63 ( V_19 , V_128 , V_144 ) ) {
F_21 ( V_19 , V_128 , 0 , V_145 ,
V_144 ) ;
F_64 ( 40 ) ;
V_141 = F_19 ( V_19 , V_128 , 0 , V_146 , 0 ) ;
V_141 = ( V_141 & V_147 ) >> V_148 ;
F_50 ( L_17 , V_128 , V_141 ) ;
}
V_142 = F_19 ( V_19 , V_128 , 0 ,
V_149 ,
V_150 | V_151 ) ;
V_143 = F_19 ( V_19 , V_128 , 0 ,
V_149 ,
V_152 | V_151 ) ;
if ( V_142 != V_143 ) {
F_21 ( V_19 , V_128 , 0 , V_49 ,
V_153 | V_154 | V_142 ) ;
V_142 = F_19 ( V_19 , V_128 , 0 ,
V_149 ,
V_150 | V_151 ) ;
V_143 = F_19 ( V_19 , V_128 , 0 ,
V_149 ,
V_152 | V_151 ) ;
F_50 ( L_18 , V_128 , V_142 , V_143 ) ;
}
}
static int F_65 ( struct V_18 * V_19 , T_1 V_11 ,
T_1 V_3 , T_3 V_155 , int V_156 )
{
int V_157 ;
int V_158 = 0 ;
if ( V_19 -> V_159 == 0x80862807 )
F_62 ( V_19 , V_11 , V_3 ) ;
if ( F_66 ( V_19 , V_3 ) & V_160 ) {
V_157 = F_19 ( V_19 , V_3 , 0 ,
V_161 , 0 ) ;
V_158 = V_157 & ~ V_162 ;
if ( F_67 ( V_156 ) )
V_158 |= V_163 ;
else
V_158 |= V_164 ;
F_31 ( L_19
L_20 ,
V_3 ,
V_157 == V_158 ? L_21 : L_22 ,
V_158 ) ;
if ( V_157 != V_158 )
F_21 ( V_19 , V_3 , 0 ,
V_51 ,
V_158 ) ;
}
if ( F_67 ( V_156 ) && ! V_158 ) {
F_31 ( L_23 ) ;
return - V_7 ;
}
F_68 ( V_19 , V_11 , V_155 , 0 , V_156 ) ;
return 0 ;
}
static int F_69 ( struct V_18 * V_19 ,
int V_4 , int * V_165 , int * V_166 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_107 * V_108 ;
struct V_167 * V_168 = NULL ;
int V_12 , V_169 = 0 ;
V_108 = F_2 ( V_2 , V_4 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_168 = F_7 ( V_2 , V_12 ) ;
if ( V_168 -> V_170 )
continue;
for ( V_169 = 0 ; V_169 < V_108 -> V_171 ; V_169 ++ )
if ( V_108 -> V_172 [ V_169 ] == V_168 -> V_11 )
break;
if ( V_169 == V_108 -> V_171 )
continue;
break;
}
if ( V_12 == V_2 -> V_13 )
return - V_173 ;
if ( V_165 )
* V_165 = V_12 ;
if ( V_166 )
* V_166 = V_169 ;
return 0 ;
}
static void F_70 ( struct V_18 * V_19 ,
int V_174 , int V_166 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_107 * V_108 ;
int V_4 , V_169 ;
int V_175 ;
int V_37 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
V_108 = F_2 ( V_2 , V_4 ) ;
if ( V_4 == V_174 )
continue;
V_175 = F_19 ( V_19 , V_108 -> V_3 , 0 ,
V_176 , 0 ) ;
if ( V_175 == V_166 ) {
V_37 = F_69 ( V_19 , V_4 , NULL , & V_169 ) ;
if ( V_37 < 0 )
return;
F_31 ( L_24 , V_169 , V_4 ) ;
F_71 ( V_19 , V_108 -> V_3 , 0 ,
V_177 ,
V_169 ) ;
}
}
}
static int F_72 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_178 * V_109 = V_106 -> V_109 ;
int V_4 , V_12 , V_169 = 0 ;
struct V_107 * V_108 ;
struct V_20 * V_21 ;
struct V_167 * V_168 = NULL ;
int V_37 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_73 ( V_4 < 0 ) )
return - V_7 ;
V_108 = F_2 ( V_2 , V_4 ) ;
V_21 = & V_108 -> V_24 ;
V_37 = F_69 ( V_19 , V_4 , & V_12 , & V_169 ) ;
if ( V_37 < 0 )
return V_37 ;
V_168 = F_7 ( V_2 , V_12 ) ;
V_168 -> V_170 = 1 ;
V_9 -> V_128 = V_168 -> V_11 ;
F_71 ( V_19 , V_108 -> V_3 , 0 ,
V_177 ,
V_169 ) ;
if ( V_19 -> V_159 == 0x80862807 )
F_70 ( V_19 , V_4 , V_169 ) ;
F_74 ( V_19 , V_4 , V_168 -> V_11 ) ;
V_9 -> V_179 = V_168 -> V_179 ;
V_9 -> V_180 = V_168 -> V_180 ;
V_9 -> V_181 = V_168 -> V_181 ;
V_9 -> V_182 = V_168 -> V_182 ;
V_9 -> V_183 = V_168 -> V_183 ;
if ( ! V_184 && V_21 -> V_27 ) {
F_75 ( & V_21 -> V_69 , V_9 ) ;
if ( V_9 -> V_179 > V_9 -> V_180 ||
! V_9 -> V_181 || ! V_9 -> V_182 ) {
V_168 -> V_170 = 0 ;
V_9 -> V_128 = 0 ;
F_76 ( V_19 , V_4 ) ;
return - V_173 ;
}
}
V_109 -> V_185 . V_179 = V_9 -> V_179 ;
V_109 -> V_185 . V_180 = V_9 -> V_180 ;
V_109 -> V_185 . V_182 = V_9 -> V_182 ;
V_109 -> V_185 . V_181 = V_9 -> V_181 ;
F_77 ( V_106 -> V_109 , 0 ,
V_186 , 2 ) ;
return 0 ;
}
static int F_78 ( struct V_18 * V_19 , int V_4 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_108 -> V_3 ;
if ( ! ( F_24 ( V_19 , V_3 ) & V_187 ) ) {
F_3 ( V_6
L_25
L_26 ,
V_3 , F_24 ( V_19 , V_3 ) ) ;
return - V_7 ;
}
V_108 -> V_171 = F_79 ( V_19 , V_3 ,
V_108 -> V_172 ,
V_188 ) ;
return 0 ;
}
static void F_58 ( struct V_107 * V_108 , int V_189 )
{
struct V_18 * V_19 = V_108 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = & V_2 -> V_190 ;
struct V_20 * V_191 = & V_108 -> V_24 ;
T_1 V_3 = V_108 -> V_3 ;
int V_192 = F_80 ( V_19 , V_3 ) ;
bool V_193 = false ;
bool V_194 = false ;
V_191 -> V_112 = ! ! ( V_192 & V_195 ) ;
if ( V_191 -> V_112 )
V_21 -> V_27 = ! ! ( V_192 & V_196 ) ;
else
V_21 -> V_27 = false ;
F_57 ( V_130 ,
L_27 ,
V_19 -> V_131 , V_3 , V_191 -> V_112 , V_21 -> V_27 ) ;
if ( V_21 -> V_27 ) {
if ( F_81 ( V_19 , V_3 , V_21 -> V_34 ,
& V_21 -> V_28 ) < 0 )
V_21 -> V_27 = false ;
else {
memset ( & V_21 -> V_69 , 0 , sizeof( struct V_197 ) ) ;
if ( F_82 ( & V_21 -> V_69 , V_21 -> V_34 ,
V_21 -> V_28 ) < 0 )
V_21 -> V_27 = false ;
}
if ( V_21 -> V_27 ) {
F_83 ( & V_21 -> V_69 ) ;
V_193 = true ;
}
else if ( V_189 ) {
F_84 ( V_19 -> V_198 -> V_199 ,
& V_108 -> V_200 ,
F_85 ( 300 ) ) ;
return;
}
}
F_10 ( & V_191 -> V_25 ) ;
if ( V_191 -> V_27 && ! V_21 -> V_27 ) {
V_193 = true ;
V_194 = true ;
}
if ( V_193 ) {
V_191 -> V_27 = V_21 -> V_27 ;
V_194 = V_191 -> V_28 != V_21 -> V_28 ||
memcmp ( V_191 -> V_34 , V_21 -> V_34 ,
V_21 -> V_28 ) != 0 ;
if ( V_194 )
memcpy ( V_191 -> V_34 , V_21 -> V_34 ,
V_21 -> V_28 ) ;
V_191 -> V_28 = V_21 -> V_28 ;
V_191 -> V_69 = V_21 -> V_69 ;
}
F_11 ( & V_191 -> V_25 ) ;
if ( V_194 )
F_86 ( V_19 -> V_198 -> V_201 ,
V_202 | V_203 ,
& V_108 -> V_41 -> V_40 ) ;
}
static void F_87 ( struct V_204 * V_200 )
{
struct V_107 * V_108 =
F_88 ( F_89 ( V_200 ) , struct V_107 , V_200 ) ;
if ( V_108 -> V_205 ++ > 6 )
V_108 -> V_205 = 0 ;
F_58 ( V_108 , V_108 -> V_205 ) ;
}
static int F_90 ( struct V_18 * V_19 , T_1 V_3 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_206 , V_207 ;
int V_4 ;
struct V_107 * V_108 ;
int V_37 ;
V_206 = F_66 ( V_19 , V_3 ) ;
if ( ! ( V_206 & ( V_208 | V_209 ) ) )
return 0 ;
V_207 = F_91 ( V_19 , V_3 ) ;
if ( F_92 ( V_207 ) == V_210 )
return 0 ;
if ( V_19 -> V_159 == 0x80862807 )
F_93 ( V_19 , V_3 ) ;
V_4 = V_2 -> V_5 ;
V_108 = F_94 ( & V_2 -> V_211 ) ;
if ( ! V_108 )
return - V_39 ;
V_108 -> V_3 = V_3 ;
V_108 -> V_74 = false ;
V_37 = F_78 ( V_19 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_95 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_167 * V_168 ;
unsigned int V_212 ;
int V_37 ;
V_212 = F_24 ( V_19 , V_11 ) ;
V_212 = F_96 ( V_212 ) ;
V_168 = F_94 ( & V_2 -> V_213 ) ;
if ( ! V_168 )
return - V_39 ;
V_168 -> V_11 = V_11 ;
V_168 -> V_179 = 2 ;
if ( V_212 <= 16 ) {
V_168 -> V_180 = V_212 ;
if ( V_212 > V_2 -> V_180 )
V_2 -> V_180 = V_212 ;
}
V_37 = F_97 ( V_19 , V_11 ,
& V_168 -> V_181 ,
& V_168 -> V_182 ,
& V_168 -> V_183 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 -> V_13 < F_13 ( V_2 -> V_214 ) )
V_2 -> V_214 [ V_2 -> V_13 ] = V_11 ;
V_2 -> V_13 ++ ;
return 0 ;
}
static int F_98 ( struct V_18 * V_19 )
{
T_1 V_128 ;
int V_56 , V_215 ;
V_215 = F_99 ( V_19 , V_19 -> V_216 , & V_128 ) ;
if ( ! V_128 || V_215 < 0 ) {
F_3 ( V_6 L_28 ) ;
return - V_7 ;
}
for ( V_56 = 0 ; V_56 < V_215 ; V_56 ++ , V_128 ++ ) {
unsigned int V_206 ;
unsigned int type ;
V_206 = F_24 ( V_19 , V_128 ) ;
type = F_100 ( V_206 ) ;
if ( ! ( V_206 & V_217 ) )
continue;
switch ( type ) {
case V_218 :
F_95 ( V_19 , V_128 ) ;
break;
case V_219 :
F_90 ( V_19 , V_128 ) ;
break;
}
}
#ifdef F_101
if ( V_19 -> V_159 == 0x80862806 )
V_19 -> V_198 -> V_220 = 1 ;
else if ( ! ( F_102 ( V_19 , V_19 -> V_216 , V_221 ) &
V_222 ) )
V_19 -> V_198 -> V_220 = 1 ;
#endif
return 0 ;
}
static bool F_103 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_223 * V_224 ;
bool V_74 ;
F_10 ( & V_19 -> V_225 ) ;
V_224 = F_104 ( V_19 , V_11 ) ;
V_74 = ! ! ( V_224 -> V_226 & V_227 ) ;
F_11 ( & V_19 -> V_225 ) ;
return V_74 ;
}
static int F_105 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_105 * V_106 )
{
T_1 V_11 = V_9 -> V_128 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = F_4 ( V_2 , V_9 ) ;
T_1 V_3 = F_2 ( V_2 , V_4 ) -> V_3 ;
bool V_74 ;
V_74 = F_103 ( V_19 , V_11 ) ;
F_26 ( V_19 , V_11 , V_106 -> V_109 -> V_61 ) ;
F_54 ( V_19 , V_4 , V_74 , V_106 ) ;
return F_65 ( V_19 , V_11 , V_3 , V_155 , V_156 ) ;
}
static int F_106 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_105 * V_106 )
{
F_107 ( V_19 , V_9 -> V_128 ) ;
return 0 ;
}
static int F_108 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_12 , V_4 ;
struct V_167 * V_168 ;
struct V_107 * V_108 ;
if ( V_9 -> V_128 ) {
V_12 = F_6 ( V_2 , V_9 -> V_128 ) ;
if ( F_73 ( V_12 < 0 ) )
return - V_7 ;
V_168 = F_7 ( V_2 , V_12 ) ;
F_73 ( ! V_168 -> V_170 ) ;
V_168 -> V_170 = 0 ;
V_9 -> V_128 = 0 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_73 ( V_4 < 0 ) )
return - V_7 ;
V_108 = F_2 ( V_2 , V_4 ) ;
F_76 ( V_19 , V_4 ) ;
V_108 -> V_89 = false ;
memset ( V_108 -> V_113 , 0 , sizeof( V_108 -> V_113 ) ) ;
}
return 0 ;
}
static int F_109 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_228 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_229 ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_17 -> type = V_230 ;
V_17 -> V_26 = V_2 -> V_180 ;
V_17 -> V_31 . integer . V_231 = 0 ;
V_17 -> V_31 . integer . V_232 = V_233 ;
return 0 ;
}
static int F_110 ( struct V_14 * V_15 , int V_234 ,
unsigned int V_93 , unsigned int T_4 * V_235 )
{
struct V_228 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_229 ;
struct V_1 * V_2 = V_19 -> V_2 ;
const unsigned int V_236 =
V_237 | V_238 | V_239 | V_240 | V_241 | V_242 | V_243 | V_244 ;
unsigned int T_4 * V_245 ;
int V_54 , V_26 = 0 ;
if ( V_93 < 8 )
return - V_39 ;
if ( F_111 ( V_246 , V_235 ) )
return - V_247 ;
V_93 -= 8 ;
V_245 = V_235 + 2 ;
for ( V_54 = 2 ; V_54 <= V_2 -> V_180 ; V_54 ++ ) {
int V_56 , V_80 ;
struct V_58 * V_248 ;
V_248 = V_60 ;
for ( V_56 = 0 ; V_56 < F_13 ( V_60 ) ; V_56 ++ , V_248 ++ ) {
int V_249 = V_54 * 4 ;
if ( V_248 -> V_61 != V_54 )
continue;
if ( V_248 -> V_62 & ~ V_236 )
continue;
if ( V_93 < 8 )
return - V_39 ;
if ( F_111 ( V_250 , V_245 ) ||
F_111 ( V_249 , V_245 + 1 ) )
return - V_247 ;
V_245 += 2 ;
V_93 -= 8 ;
V_26 += 8 ;
if ( V_93 < V_249 )
return - V_39 ;
V_93 -= V_249 ;
V_26 += V_249 ;
for ( V_80 = 7 ; V_80 >= 0 ; V_80 -- ) {
int V_86 = V_248 -> V_63 [ V_80 ] ;
if ( ! V_86 )
continue;
if ( F_111 ( F_39 ( V_86 ) , V_245 ) )
return - V_247 ;
V_245 ++ ;
}
}
}
if ( F_111 ( V_26 , V_235 + 1 ) )
return - V_247 ;
return 0 ;
}
static int F_112 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_228 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_229 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_23 ;
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < F_13 ( V_108 -> V_113 ) ; V_56 ++ )
V_30 -> V_31 . integer . V_31 [ V_56 ] = V_108 -> V_113 [ V_56 ] ;
return 0 ;
}
static int F_113 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_228 * V_69 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_69 -> V_229 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_23 ;
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
unsigned int V_251 ;
struct V_105 * V_106 ;
unsigned char V_113 [ 8 ] ;
int V_56 , V_64 , V_252 = 0 ;
V_251 = F_114 ( V_15 , & V_30 -> V_40 ) ;
V_106 = F_115 ( V_69 , V_251 ) ;
if ( ! V_106 || ! V_106 -> V_109 )
return 0 ;
switch ( V_106 -> V_109 -> V_226 -> V_253 ) {
case V_254 :
case V_255 :
break;
case V_256 :
V_252 = 1 ;
break;
default:
return - V_257 ;
}
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
for ( V_56 = 0 ; V_56 < F_13 ( V_113 ) ; V_56 ++ )
V_113 [ V_56 ] = V_30 -> V_31 . integer . V_31 [ V_56 ] ;
if ( ! memcmp ( V_113 , V_108 -> V_113 , sizeof( V_113 ) ) )
return 0 ;
V_64 = F_40 ( F_13 ( V_113 ) , V_113 ) ;
if ( V_64 < 0 )
return - V_7 ;
V_108 -> V_89 = true ;
memcpy ( V_108 -> V_113 , V_113 , sizeof( V_113 ) ) ;
if ( V_252 )
F_54 ( V_19 , V_4 , V_108 -> V_74 ,
V_106 ) ;
return 0 ;
}
static int F_116 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_258 * V_69 ;
struct V_8 * V_259 ;
struct V_107 * V_108 ;
V_108 = F_2 ( V_2 , V_4 ) ;
sprintf ( V_108 -> V_260 , L_29 , V_4 ) ;
V_69 = F_94 ( & V_2 -> V_261 ) ;
if ( ! V_69 )
return - V_39 ;
V_69 -> V_262 = V_108 -> V_260 ;
V_69 -> V_263 = V_264 ;
V_69 -> V_265 = true ;
V_259 = & V_69 -> V_10 [ V_266 ] ;
V_259 -> V_267 = 1 ;
V_259 -> V_268 = V_269 ;
}
V_19 -> V_270 = V_2 -> V_5 ;
V_19 -> V_271 = V_2 -> V_261 . V_272 ;
return 0 ;
}
static int F_117 ( struct V_18 * V_19 , int V_4 )
{
char V_273 [ 32 ] = L_30 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
int V_274 = F_5 ( V_2 , V_4 ) -> V_35 ;
if ( V_274 > 0 )
sprintf ( V_273 + strlen ( V_273 ) , L_31 , V_274 ) ;
if ( ! F_118 ( V_19 , V_108 -> V_3 ) )
strncat ( V_273 , L_32 ,
sizeof( V_273 ) - strlen ( V_273 ) - 1 ) ;
return F_119 ( V_19 , V_108 -> V_3 , V_273 , 0 ) ;
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_37 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
V_37 = F_117 ( V_19 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_121 ( V_19 ,
V_108 -> V_3 ,
V_108 -> V_172 [ 0 ] ,
V_264 ) ;
if ( V_37 < 0 )
return V_37 ;
F_76 ( V_19 , V_4 ) ;
V_37 = F_15 ( V_19 , V_4 ,
F_5 ( V_2 , V_4 ) -> V_35 ) ;
if ( V_37 < 0 )
return V_37 ;
F_58 ( V_108 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_228 * V_113 ;
struct V_14 * V_36 ;
int V_56 ;
if ( ! V_19 -> V_271 [ V_4 ] . V_275 )
break;
V_37 = F_122 ( V_19 -> V_271 [ V_4 ] . V_275 ,
V_266 ,
NULL , 0 , V_4 , & V_113 ) ;
if ( V_37 < 0 )
return V_37 ;
V_113 -> V_229 = V_19 ;
V_36 = V_113 -> V_36 ;
for ( V_56 = 0 ; V_56 < V_36 -> V_26 ; V_56 ++ )
V_36 -> V_276 [ V_56 ] . V_277 |= V_278 ;
V_36 -> V_69 = F_109 ;
V_36 -> V_279 = F_112 ;
V_36 -> V_280 = F_113 ;
V_36 -> V_235 . V_80 = F_110 ;
}
return 0 ;
}
static int F_123 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
struct V_20 * V_21 = & V_108 -> V_24 ;
V_108 -> V_19 = V_19 ;
F_124 ( & V_21 -> V_25 ) ;
F_125 ( & V_108 -> V_200 , F_87 ) ;
F_126 ( V_19 , V_21 , V_4 ) ;
}
return 0 ;
}
static int F_127 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_108 -> V_3 ;
F_23 ( V_19 , V_3 ) ;
F_128 ( V_19 , V_3 , V_3 ) ;
}
return 0 ;
}
static void F_129 ( struct V_1 * V_2 , int V_281 )
{
F_130 ( & V_2 -> V_211 , sizeof( struct V_107 ) , V_281 ) ;
F_130 ( & V_2 -> V_213 , sizeof( struct V_167 ) , V_281 ) ;
F_130 ( & V_2 -> V_261 , sizeof( struct V_258 ) , V_281 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_132 ( & V_2 -> V_211 ) ;
F_132 ( & V_2 -> V_213 ) ;
F_132 ( & V_2 -> V_261 ) ;
}
static void F_133 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
struct V_20 * V_21 = & V_108 -> V_24 ;
F_134 ( & V_108 -> V_200 ) ;
F_135 ( V_19 , V_21 ) ;
}
F_136 ( V_19 -> V_198 -> V_199 ) ;
F_131 ( V_2 ) ;
F_137 ( V_2 ) ;
}
static int F_138 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
F_127 ( V_19 ) ;
F_139 ( V_19 ) ;
F_140 ( V_19 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_107 * V_108 = F_2 ( V_2 , V_4 ) ;
F_58 ( V_108 , 1 ) ;
}
return 0 ;
}
static void F_93 ( struct V_18 * V_19 ,
T_1 V_128 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_282 [ 4 ] ;
int V_283 ;
V_283 = F_79 ( V_19 , V_128 , V_282 , F_13 ( V_282 ) ) ;
if ( V_283 == V_2 -> V_13 &&
! memcmp ( V_282 , V_2 -> V_214 , V_2 -> V_13 * sizeof( T_1 ) ) )
return;
F_31 ( L_33 , V_128 ) ;
F_141 ( V_19 , V_128 , V_2 -> V_13 , V_2 -> V_214 ) ;
}
static void F_142 ( struct V_18 * V_19 ,
bool V_284 )
{
unsigned int V_285 ;
V_285 = F_19 ( V_19 , V_286 , 0 ,
V_287 , 0 ) ;
if ( V_285 == - 1 || V_285 & V_288 )
return;
V_285 |= V_288 ;
V_285 = F_19 ( V_19 , V_286 , 0 ,
V_289 , V_285 ) ;
if ( V_285 == - 1 )
return;
if ( V_284 )
F_143 ( V_19 ) ;
}
static void F_144 ( struct V_18 * V_19 )
{
unsigned int V_285 ;
V_285 = F_19 ( V_19 , V_286 , 0 ,
V_287 , 0 ) ;
if ( V_285 == - 1 || V_285 & V_290 )
return;
V_285 |= V_290 ;
F_71 ( V_19 , V_286 , 0 ,
V_289 , V_285 ) ;
}
static void F_145 ( struct V_18 * V_19 , T_1 V_291 ,
unsigned int V_292 )
{
if ( V_292 == V_144 ) {
F_142 ( V_19 , false ) ;
F_144 ( V_19 ) ;
}
F_19 ( V_19 , V_291 , 0 , V_145 , V_292 ) ;
F_146 ( V_19 , V_291 , V_292 ) ;
}
static int F_147 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_148 ( sizeof( * V_2 ) , V_293 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_19 -> V_2 = V_2 ;
F_129 ( V_2 , 4 ) ;
if ( V_19 -> V_159 == 0x80862807 ) {
F_142 ( V_19 , true ) ;
F_144 ( V_19 ) ;
}
if ( F_98 ( V_19 ) < 0 ) {
V_19 -> V_2 = NULL ;
F_137 ( V_2 ) ;
return - V_7 ;
}
V_19 -> V_294 = V_295 ;
if ( V_19 -> V_159 == 0x80862807 )
V_19 -> V_294 . V_296 = F_145 ;
F_123 ( V_19 ) ;
F_27 () ;
return 0 ;
}
static int F_149 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_258 * V_69 ;
unsigned int V_212 ;
struct V_8 * V_259 ;
struct V_167 * V_168 ;
V_168 = F_7 ( V_2 , 0 ) ;
V_212 = F_24 ( V_19 , V_168 -> V_11 ) ;
V_212 = F_96 ( V_212 ) ;
V_69 = F_94 ( & V_2 -> V_261 ) ;
if ( ! V_69 )
return - V_39 ;
V_69 -> V_262 = F_2 ( V_2 , 0 ) -> V_260 ;
sprintf ( V_69 -> V_262 , L_34 ) ;
V_69 -> V_263 = V_264 ;
V_259 = & V_69 -> V_10 [ V_266 ] ;
* V_259 = V_2 -> V_297 ;
V_259 -> V_128 = V_168 -> V_11 ;
if ( V_259 -> V_180 <= 2 && V_212 && V_212 <= 16 )
V_259 -> V_180 = V_212 ;
V_19 -> V_270 = 1 ;
V_19 -> V_271 = V_69 ;
return 0 ;
}
static void F_150 ( struct V_18 * V_19 ,
unsigned int V_123 )
{
F_151 ( V_19 ) ;
F_59 ( V_19 ) ;
}
static int F_152 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_167 * V_168 ;
int V_37 ;
V_168 = F_7 ( V_2 , 0 ) ;
V_37 = F_153 ( V_19 , V_168 -> V_11 ,
V_168 -> V_11 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_154 ( V_19 , 0 ) ;
}
static int F_155 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_107 * V_108 = F_2 ( V_2 , 0 ) ;
T_1 V_298 = V_108 -> V_3 ;
F_21 ( V_19 , V_298 , 0 ,
V_51 , V_52 ) ;
if ( F_24 ( V_19 , V_298 ) & V_48 )
F_21 ( V_19 , V_298 , 0 , V_49 ,
V_50 ) ;
F_128 ( V_19 , V_298 , V_298 ) ;
return 0 ;
}
static void F_156 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_131 ( V_2 ) ;
F_137 ( V_2 ) ;
}
static int F_157 ( struct V_18 * V_19 )
{
F_158 ( V_19 , V_299 ) ;
return 0 ;
}
static int F_159 ( struct V_18 * V_19 )
{
F_158 ( V_19 , V_300 ) ;
return 0 ;
}
static int F_160 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_301 * V_302 = NULL ;
switch ( V_19 -> V_303 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_302 = & V_304 ;
break;
case 0x10de0007 :
V_302 = & V_305 ;
break;
default:
break;
}
if ( V_302 != NULL ) {
V_301 ( V_106 -> V_109 , 0 ,
V_186 ,
V_302 ) ;
} else {
F_77 ( V_106 -> V_109 , 0 ,
V_186 , 2 ) ;
}
return F_161 ( V_19 , & V_2 -> V_306 ) ;
}
static int F_162 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_163 ( V_19 , & V_2 -> V_306 ) ;
}
static int F_164 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_165 ( V_19 , & V_2 -> V_306 ,
V_155 , V_156 , V_106 ) ;
}
static int F_166 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_3 )
{
struct V_1 * V_2 ;
struct V_167 * V_168 ;
struct V_107 * V_108 ;
V_2 = F_148 ( sizeof( * V_2 ) , V_293 ) ;
if ( ! V_2 )
return - V_39 ;
V_19 -> V_2 = V_2 ;
F_129 ( V_2 , 1 ) ;
V_2 -> V_306 . V_307 = 0 ;
V_2 -> V_306 . V_308 = 2 ;
V_2 -> V_306 . V_309 = V_11 ;
V_2 -> V_13 = 1 ;
V_2 -> V_5 = 1 ;
V_108 = F_94 ( & V_2 -> V_211 ) ;
V_168 = F_94 ( & V_2 -> V_213 ) ;
if ( ! V_108 || ! V_168 ) {
F_156 ( V_19 ) ;
return - V_39 ;
}
V_168 -> V_11 = V_11 ;
V_108 -> V_3 = V_3 ;
V_2 -> V_297 = V_310 ;
V_19 -> V_294 = V_311 ;
return 0 ;
}
static void F_167 ( struct V_18 * V_19 ,
int V_61 )
{
unsigned int V_312 ;
int V_313 = V_61 ? ( V_61 - 1 ) : 1 ;
switch ( V_61 ) {
default:
case 0 :
case 2 :
V_312 = 0x00 ;
break;
case 4 :
V_312 = 0x08 ;
break;
case 6 :
V_312 = 0x0b ;
break;
case 8 :
V_312 = 0x13 ;
break;
}
F_21 ( V_19 , 0x1 , 0 ,
V_314 , V_312 ) ;
F_21 ( V_19 , 0x1 , 0 ,
V_315 ,
( 0x71 - V_313 - V_312 ) ) ;
}
static int F_168 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_56 ;
F_21 ( V_19 , V_316 ,
0 , V_317 , 0 ) ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
F_21 ( V_19 , V_318 [ V_56 ] , 0 ,
V_317 , 0 ) ;
F_21 ( V_19 , V_318 [ V_56 ] , 0 ,
V_319 , 0 ) ;
}
F_167 ( V_19 , 8 ) ;
return F_163 ( V_19 , & V_2 -> V_306 ) ;
}
static int F_169 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_105 * V_106 )
{
int V_54 ;
unsigned int V_320 , V_321 ;
int V_56 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_223 * V_224 ;
struct V_167 * V_168 ;
F_10 ( & V_19 -> V_225 ) ;
V_168 = F_7 ( V_2 , 0 ) ;
V_224 = F_104 ( V_19 , V_168 -> V_11 ) ;
V_54 = V_106 -> V_109 -> V_61 ;
V_320 = 0x2 ;
if ( V_19 -> V_322 && ( V_224 -> V_323 & V_324 ) )
F_21 ( V_19 ,
V_316 ,
0 ,
V_325 ,
V_224 -> V_323 & ~ V_324 & 0xff ) ;
F_21 ( V_19 , V_316 , 0 ,
V_317 , ( V_155 << 4 ) | 0x0 ) ;
F_21 ( V_19 , V_316 , 0 ,
V_319 , V_156 ) ;
if ( V_19 -> V_322 && ( V_224 -> V_323 & V_324 ) ) {
F_21 ( V_19 ,
V_316 ,
0 ,
V_325 ,
V_224 -> V_323 & 0xff ) ;
F_21 ( V_19 ,
V_316 ,
0 ,
V_326 , V_320 ) ;
}
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
if ( V_54 == 2 )
V_321 = 0 ;
else
V_321 = V_56 * 2 ;
if ( V_19 -> V_322 &&
( V_224 -> V_323 & V_324 ) )
F_21 ( V_19 ,
V_318 [ V_56 ] ,
0 ,
V_325 ,
V_224 -> V_323 & ~ V_324 & 0xff ) ;
F_21 ( V_19 ,
V_318 [ V_56 ] ,
0 ,
V_317 ,
( V_155 << 4 ) | V_321 ) ;
F_21 ( V_19 ,
V_318 [ V_56 ] ,
0 ,
V_319 ,
V_156 ) ;
if ( V_19 -> V_322 &&
( V_224 -> V_323 & V_324 ) ) {
F_21 ( V_19 ,
V_318 [ V_56 ] ,
0 ,
V_325 ,
V_224 -> V_323 & 0xff ) ;
F_21 ( V_19 ,
V_318 [ V_56 ] ,
0 ,
V_326 , V_320 ) ;
}
}
F_167 ( V_19 , V_54 ) ;
F_11 ( & V_19 -> V_225 ) ;
return 0 ;
}
static int F_170 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_37 = F_166 ( V_19 , V_316 ,
V_327 ) ;
if ( V_37 < 0 )
return V_37 ;
V_19 -> V_294 . V_328 = F_157 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_297 . V_181 = V_329 ;
V_2 -> V_297 . V_183 = V_330 ;
V_2 -> V_297 . V_182 = V_331 ;
return 0 ;
}
static int F_171 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_37 = F_149 ( V_19 ) ;
if ( ! V_37 ) {
struct V_258 * V_69 = F_5 ( V_2 , 0 ) ;
V_69 -> V_265 = true ;
}
return V_37 ;
}
static int F_172 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_258 * V_69 ;
struct V_228 * V_113 ;
int V_37 ;
V_37 = F_152 ( V_19 ) ;
if ( V_37 < 0 )
return V_37 ;
V_69 = F_5 ( V_2 , 0 ) ;
V_37 = F_122 ( V_69 -> V_275 ,
V_266 ,
V_332 , 8 , 0 , & V_113 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_19 -> V_303 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_113 -> V_333 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_113 -> V_333 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_173 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_37 = F_170 ( V_19 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_306 . V_308 = 8 ;
V_2 -> V_297 = V_334 ;
V_19 -> V_294 . V_328 = F_159 ;
V_19 -> V_294 . V_335 = F_171 ;
V_19 -> V_294 . V_336 = F_172 ;
F_167 ( V_19 , 8 ) ;
return 0 ;
}
static int F_174 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_167 * V_168 = F_7 ( V_2 , 0 ) ;
int V_212 = V_106 -> V_109 -> V_61 ;
int V_56 , V_37 ;
V_37 = F_164 ( V_9 , V_19 , V_155 , V_156 ,
V_106 ) ;
if ( V_37 < 0 )
return V_37 ;
F_21 ( V_19 , V_168 -> V_11 , 0 ,
V_55 , V_212 - 1 ) ;
for ( V_56 = 0 ; V_56 < V_212 ; V_56 ++ ) {
F_21 ( V_19 , V_168 -> V_11 , 0 ,
V_78 ,
( V_56 << 4 ) | V_56 ) ;
}
return 0 ;
}
static int F_175 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_37 = F_166 ( V_19 , V_337 , V_338 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_297 . V_268 . V_339 = F_174 ;
return 0 ;
}
static int F_176 ( struct V_18 * V_19 )
{
return F_166 ( V_19 , V_340 , V_341 ) ;
}
static int T_5 F_177 ( void )
{
return F_178 ( & V_342 ) ;
}
static void T_6 F_179 ( void )
{
F_180 ( & V_342 ) ;
}
