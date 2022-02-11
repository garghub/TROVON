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
struct V_22 * V_23 ;
int V_4 ;
V_17 -> type = V_24 ;
V_4 = V_15 -> V_25 ;
V_21 = F_2 ( V_2 , V_4 ) ;
V_23 = & V_21 -> V_26 ;
F_10 ( & V_21 -> V_27 ) ;
V_17 -> V_28 = V_23 -> V_29 ? V_23 -> V_30 : 0 ;
F_11 ( & V_21 -> V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_18 * V_19 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_4 ;
V_4 = V_15 -> V_25 ;
V_21 = F_2 ( V_2 , V_4 ) ;
V_23 = & V_21 -> V_26 ;
F_10 ( & V_21 -> V_27 ) ;
if ( V_23 -> V_30 > F_13 ( V_32 -> V_33 . V_34 . V_35 ) ) {
F_11 ( & V_21 -> V_27 ) ;
F_14 () ;
return - V_7 ;
}
memset ( V_32 -> V_33 . V_34 . V_35 , 0 ,
F_13 ( V_32 -> V_33 . V_34 . V_35 ) ) ;
if ( V_23 -> V_29 )
memcpy ( V_32 -> V_33 . V_34 . V_35 , V_23 -> V_36 ,
V_23 -> V_30 ) ;
F_11 ( & V_21 -> V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 , int V_4 ,
int V_37 )
{
struct V_14 * V_38 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_39 ;
V_38 = F_16 ( & V_40 , V_19 ) ;
if ( ! V_38 )
return - V_41 ;
V_38 -> V_25 = V_4 ;
V_38 -> V_42 . V_37 = V_37 ;
V_39 = F_17 ( V_19 , F_2 ( V_2 , V_4 ) -> V_3 , V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
F_2 ( V_2 , V_4 ) -> V_43 = V_38 ;
return 0 ;
}
static void F_18 ( struct V_18 * V_19 , T_1 V_3 ,
int * V_44 , int * V_45 )
{
int V_46 ;
V_46 = F_19 ( V_19 , V_3 , 0 ,
V_47 , 0 ) ;
* V_44 = V_46 >> 5 ;
* V_45 = V_46 & 0x1f ;
}
static void F_20 ( struct V_18 * V_19 , T_1 V_3 ,
int V_44 , int V_45 )
{
int V_46 ;
V_46 = ( V_44 << 5 ) | ( V_45 & 0x1f ) ;
F_21 ( V_19 , V_3 , 0 , V_48 , V_46 ) ;
}
static void F_22 ( struct V_18 * V_19 , T_1 V_3 ,
unsigned char V_46 )
{
F_21 ( V_19 , V_3 , 0 , V_49 , V_46 ) ;
}
static void F_23 ( struct V_18 * V_19 , T_1 V_3 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_50 ;
if ( F_24 ( V_19 , V_3 ) & V_51 )
F_21 ( V_19 , V_3 , 0 ,
V_52 , V_53 ) ;
if ( V_2 -> V_54 )
V_50 = 0 ;
else
V_50 = V_55 ;
F_21 ( V_19 , V_3 , 0 ,
V_56 , V_50 ) ;
}
static int F_25 ( struct V_18 * V_19 , T_1 V_11 )
{
return 1 + F_19 ( V_19 , V_11 , 0 ,
V_57 , 0 ) ;
}
static void F_26 ( struct V_18 * V_19 ,
T_1 V_11 , int V_58 )
{
if ( V_58 != F_25 ( V_19 , V_11 ) )
F_21 ( V_19 , V_11 , 0 ,
V_59 , V_58 - 1 ) ;
}
static void F_27 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_20 * V_21 = V_61 -> V_64 ;
F_10 ( & V_21 -> V_27 ) ;
F_28 ( & V_21 -> V_26 , V_63 ) ;
F_11 ( & V_21 -> V_27 ) ;
}
static void F_29 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_20 * V_21 = V_61 -> V_64 ;
F_10 ( & V_21 -> V_27 ) ;
F_30 ( & V_21 -> V_26 , V_63 ) ;
F_11 ( & V_21 -> V_27 ) ;
}
static int F_31 ( struct V_20 * V_21 , int V_65 )
{
char V_66 [ 32 ] ;
struct V_18 * V_19 = V_21 -> V_19 ;
struct V_60 * V_61 ;
int V_39 ;
snprintf ( V_66 , sizeof( V_66 ) , L_4 , V_19 -> V_67 , V_65 ) ;
V_39 = F_32 ( V_19 -> V_68 -> V_69 , V_66 , & V_61 ) ;
if ( V_39 < 0 )
return V_39 ;
F_33 ( V_61 , V_21 , F_27 ) ;
V_61 -> V_70 . V_71 . V_72 = F_29 ;
V_61 -> V_73 |= V_74 ;
V_21 -> V_75 = V_61 ;
return 0 ;
}
static void F_34 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_19 -> V_68 -> V_76 && V_21 -> V_75 ) {
F_35 ( V_21 -> V_19 -> V_68 -> V_69 , V_21 -> V_75 ) ;
V_21 -> V_75 = NULL ;
}
}
static inline int F_31 ( struct V_20 * V_21 ,
int V_65 )
{
return 0 ;
}
static inline void F_34 ( struct V_20 * V_21 )
{
}
static void F_36 ( void )
{
int V_77 , V_78 ;
struct V_79 * V_80 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ ) {
V_80 = V_81 + V_77 ;
V_80 -> V_82 = 0 ;
V_80 -> V_83 = 0 ;
for ( V_78 = 0 ; V_78 < F_13 ( V_80 -> V_84 ) ; V_78 ++ )
if ( V_80 -> V_84 [ V_78 ] ) {
V_80 -> V_82 ++ ;
V_80 -> V_83 |= V_80 -> V_84 [ V_78 ] ;
}
}
}
static int F_37 ( int V_85 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ ) {
if ( V_81 [ V_77 ] . V_86 == V_85 )
break;
}
return V_77 ;
}
static int F_38 ( struct V_22 * V_23 , int V_82 )
{
int V_77 ;
int V_85 = 0 ;
int V_83 = 0 ;
char V_87 [ V_88 ] ;
if ( V_82 <= 2 )
return 0 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_89 ) ; V_77 ++ ) {
if ( V_23 -> V_90 . V_91 & ( 1 << V_77 ) )
V_83 |= V_89 [ V_77 ] ;
}
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ ) {
if ( V_82 == V_81 [ V_77 ] . V_82 &&
( V_83 & V_81 [ V_77 ] . V_83 ) ==
V_81 [ V_77 ] . V_83 ) {
V_85 = V_81 [ V_77 ] . V_86 ;
break;
}
}
if ( ! V_85 ) {
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ ) {
if ( V_82 == V_81 [ V_77 ] . V_82 ) {
V_85 = V_81 [ V_77 ] . V_86 ;
break;
}
}
}
F_39 ( V_23 -> V_90 . V_91 , V_87 , sizeof( V_87 ) ) ;
F_40 ( L_5 ,
V_85 , V_82 , V_87 ) ;
return V_85 ;
}
static void F_41 ( struct V_18 * V_19 ,
T_1 V_3 )
{
#ifdef F_42
struct V_1 * V_2 = V_19 -> V_2 ;
int V_77 ;
int V_92 ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_92 = V_2 -> V_93 . V_94 ( V_19 , V_3 , V_77 ) ;
F_43 ( V_95 L_6 ,
V_92 , V_77 ) ;
}
#endif
}
static void F_44 ( struct V_18 * V_19 ,
T_1 V_3 ,
bool V_96 ,
int V_85 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_79 * V_97 ;
int V_77 ;
int V_39 ;
int V_98 ;
int V_99 [ 8 ] ;
V_98 = F_37 ( V_85 ) ;
V_97 = & V_81 [ V_98 ] ;
if ( V_100 [ V_85 ] [ 1 ] == 0 ) {
int V_101 = 0 ;
for ( V_77 = 0 ; V_77 < V_97 -> V_82 ; V_77 ++ ) {
while ( ! V_97 -> V_84 [ 7 - V_101 ] && ! F_45 ( V_101 >= 8 ) )
V_101 ++ ;
V_100 [ V_85 ] [ V_77 ] = ( V_77 << 4 ) | V_101 ++ ;
}
for ( V_101 = 0 ; V_101 < 8 ; V_101 ++ )
if ( ! V_97 -> V_84 [ 7 - V_101 ] )
V_100 [ V_85 ] [ V_77 ++ ] = ( 0xf << 4 ) | V_101 ;
}
if ( V_96 ) {
for ( V_77 = 0 ; V_77 < V_97 -> V_82 ; V_77 ++ )
V_99 [ V_77 ] = ( V_77 << 4 ) | V_77 ;
for (; V_77 < 8 ; V_77 ++ )
V_99 [ V_77 ] = ( 0xf << 4 ) | V_77 ;
}
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
int V_102 = V_96 ? V_99 [ V_77 ] : V_100 [ V_85 ] [ V_77 ] ;
int V_101 = V_102 & 0x0f ;
int V_92 = ( V_102 & 0xf0 ) >> 4 ;
V_39 = V_2 -> V_93 . V_103 ( V_19 , V_3 , V_101 , V_92 ) ;
if ( V_39 ) {
F_40 ( V_104
L_7 ) ;
break;
}
}
}
static int F_46 ( unsigned char V_70 )
{
struct V_105 * V_106 = V_107 ;
for (; V_106 -> V_108 ; V_106 ++ ) {
if ( V_106 -> V_108 == V_70 )
return V_106 -> V_83 ;
}
return 0 ;
}
static int F_47 ( int V_109 , unsigned char V_110 )
{
int V_111 = F_46 ( V_110 ) ;
int V_77 ;
if ( V_111 ) {
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
if ( V_81 [ V_109 ] . V_84 [ 7 - V_77 ] == V_111 )
return V_77 ;
}
}
return - 1 ;
}
static int F_48 ( int V_112 )
{
struct V_105 * V_106 = V_107 ;
for (; V_106 -> V_108 ; V_106 ++ ) {
if ( V_106 -> V_83 == V_112 )
return V_106 -> V_108 ;
}
return 0 ;
}
static int F_49 ( int V_109 , unsigned char V_113 )
{
int V_111 = V_81 [ V_109 ] . V_84 [ 7 - V_113 ] ;
return F_48 ( V_111 ) ;
}
static int F_50 ( int V_58 , unsigned char * V_108 )
{
int V_77 , V_114 = 0 , V_83 = 0 ;
for ( V_77 = 0 ; V_77 < V_58 ; V_77 ++ ) {
int V_111 = F_46 ( V_108 [ V_77 ] ) ;
if ( V_111 ) {
V_83 |= V_111 ;
V_114 ++ ;
}
}
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ ) {
if ( ( V_58 == V_81 [ V_77 ] . V_82 ||
V_114 == V_81 [ V_77 ] . V_82 ) &&
( V_83 & V_81 [ V_77 ] . V_83 ) ==
V_81 [ V_77 ] . V_83 )
return V_81 [ V_77 ] . V_86 ;
}
return - 1 ;
}
static int F_51 ( struct V_18 * V_19 ,
T_1 V_3 ,
int V_58 , unsigned char * V_108 ,
int V_85 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_109 = F_37 ( V_85 ) ;
int V_115 , V_101 ;
int V_116 [ 8 ] = { [ 0 ... 7 ] = 0xf } ;
for ( V_115 = 0 ; V_115 < V_58 ; V_115 ++ ) {
V_101 = F_47 ( V_109 , V_108 [ V_115 ] ) ;
if ( V_101 < 0 )
continue;
V_116 [ V_101 ] = V_115 ;
}
for ( V_101 = 0 ; V_101 < 8 ; V_101 ++ ) {
int V_39 ;
V_39 = V_2 -> V_93 . V_103 ( V_19 , V_3 , V_101 ,
V_116 [ V_101 ] ) ;
if ( V_39 )
return - V_7 ;
}
return 0 ;
}
static void F_52 ( unsigned char * V_108 , int V_85 )
{
int V_77 ;
int V_109 = F_37 ( V_85 ) ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
if ( V_77 < V_81 [ V_109 ] . V_82 )
V_108 [ V_77 ] = F_49 ( V_109 , V_100 [ V_85 ] [ V_77 ] & 0x0f ) ;
else
V_108 [ V_77 ] = 0 ;
}
}
static void F_53 ( struct V_18 * V_19 ,
T_1 V_3 , bool V_96 , int V_85 ,
int V_82 , unsigned char * V_108 ,
bool V_117 )
{
if ( ! V_96 && V_117 ) {
F_51 ( V_19 , V_3 ,
V_82 , V_108 , V_85 ) ;
} else {
F_44 ( V_19 , V_3 , V_96 , V_85 ) ;
F_52 ( V_108 , V_85 ) ;
}
F_41 ( V_19 , V_3 ) ;
}
static int F_54 ( struct V_18 * V_19 , T_1 V_3 ,
int V_118 , int V_92 )
{
return F_21 ( V_19 , V_3 , 0 ,
V_119 ,
( V_92 << 4 ) | V_118 ) ;
}
static int F_55 ( struct V_18 * V_19 , T_1 V_3 ,
int V_118 )
{
return ( F_19 ( V_19 , V_3 , 0 ,
V_120 ,
V_118 ) & 0xf0 ) >> 4 ;
}
static void F_56 ( struct V_18 * V_19 ,
T_1 V_3 )
{
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_19 , V_3 , 0 , V_121 ,
V_122 ) ;
}
static void F_57 ( struct V_18 * V_19 ,
T_1 V_3 )
{
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_19 , V_3 , 0 , V_121 ,
V_123 ) ;
}
static void F_58 ( struct V_18 * V_19 , T_1 V_3 )
{
#ifdef F_42
int V_77 ;
int V_124 ;
V_124 = F_59 ( V_19 , V_3 ) ;
F_43 ( V_95 L_8 , V_124 ) ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_124 = F_19 ( V_19 , V_3 , 0 ,
V_125 , V_77 ) ;
F_43 ( V_95 L_9 , V_77 , V_124 ) ;
}
#endif
}
static void F_60 ( struct V_18 * V_19 , T_1 V_3 )
{
#ifdef F_61
int V_77 , V_78 ;
int V_124 ;
int V_126 , V_127 ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_124 = F_19 ( V_19 , V_3 , 0 ,
V_125 , V_77 ) ;
if ( V_124 == 0 )
continue;
F_20 ( V_19 , V_3 , V_77 , 0x0 ) ;
for ( V_78 = 1 ; V_78 < 1000 ; V_78 ++ ) {
F_22 ( V_19 , V_3 , 0x0 ) ;
F_18 ( V_19 , V_3 , & V_126 , & V_127 ) ;
if ( V_126 != V_77 )
F_62 ( V_128 L_10 ,
V_127 , V_126 , V_77 ) ;
if ( V_127 == 0 )
break;
}
F_62 ( V_128
L_11 ,
V_77 , V_124 , V_78 ) ;
}
#endif
}
static void F_63 ( struct V_129 * V_130 )
{
T_2 * V_34 = ( T_2 * ) V_130 ;
T_2 V_131 = 0 ;
int V_77 ;
V_130 -> V_132 = 0 ;
for ( V_77 = 0 ; V_77 < sizeof( * V_130 ) ; V_77 ++ )
V_131 += V_34 [ V_77 ] ;
V_130 -> V_132 = - V_131 ;
}
static void F_64 ( struct V_18 * V_19 ,
T_1 V_3 ,
T_2 * V_133 , int V_124 )
{
int V_77 ;
F_58 ( V_19 , V_3 ) ;
F_60 ( V_19 , V_3 ) ;
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
for ( V_77 = 0 ; V_77 < V_124 ; V_77 ++ )
F_22 ( V_19 , V_3 , V_133 [ V_77 ] ) ;
}
static bool F_65 ( struct V_18 * V_19 , T_1 V_3 ,
T_2 * V_133 , int V_124 )
{
T_2 V_46 ;
int V_77 ;
if ( F_19 ( V_19 , V_3 , 0 , V_134 , 0 )
!= V_122 )
return false ;
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
for ( V_77 = 0 ; V_77 < V_124 ; V_77 ++ ) {
V_46 = F_19 ( V_19 , V_3 , 0 ,
V_135 , 0 ) ;
if ( V_46 != V_133 [ V_77 ] )
return false ;
}
return true ;
}
static void F_66 ( struct V_18 * V_19 ,
T_1 V_3 ,
int V_85 , int V_136 ,
int V_137 )
{
union V_138 V_139 ;
if ( V_137 == 0 ) {
struct V_129 * V_130 = & V_139 . V_140 ;
V_130 -> type = 0x84 ;
V_130 -> V_141 = 0x01 ;
V_130 -> V_142 = 0x0a ;
V_130 -> V_143 = V_136 - 1 ;
V_130 -> V_144 = V_85 ;
F_63 ( V_130 ) ;
} else if ( V_137 == 1 ) {
struct V_145 * V_146 = & V_139 . V_147 ;
V_146 -> type = 0x84 ;
V_146 -> V_142 = 0x1b ;
V_146 -> V_141 = 0x11 << 2 ;
V_146 -> V_143 = V_136 - 1 ;
V_146 -> V_144 = V_85 ;
} else {
F_62 ( L_12 ,
V_3 ) ;
return;
}
if ( ! F_65 ( V_19 , V_3 , V_139 . V_34 ,
sizeof( V_139 ) ) ) {
F_40 ( L_13
L_14 ,
V_3 ,
V_136 , V_85 ) ;
F_57 ( V_19 , V_3 ) ;
F_64 ( V_19 , V_3 ,
V_139 . V_34 , sizeof( V_139 ) ) ;
F_56 ( V_19 , V_3 ) ;
}
}
static void F_67 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
bool V_96 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_3 = V_21 -> V_3 ;
int V_82 = V_21 -> V_82 ;
int V_136 ;
struct V_22 * V_23 ;
int V_85 , V_109 ;
if ( ! V_82 )
return;
if ( F_68 ( V_19 ) )
F_21 ( V_19 , V_3 , 0 ,
V_52 ,
V_53 ) ;
V_23 = & V_21 -> V_26 ;
if ( ! V_23 -> V_148 )
return;
if ( ! V_96 && V_21 -> V_117 )
V_85 = F_50 ( V_82 , V_21 -> V_149 ) ;
else
V_85 = F_38 ( V_23 , V_82 ) ;
if ( V_85 < 0 )
V_85 = 0 ;
V_109 = F_37 ( V_85 ) ;
V_136 = V_81 [ V_109 ] . V_82 ;
F_26 ( V_19 , V_21 -> V_11 , V_136 ) ;
F_53 ( V_19 , V_3 , V_96 , V_85 ,
V_82 , V_21 -> V_149 ,
V_21 -> V_117 ) ;
V_2 -> V_93 . V_150 ( V_19 , V_3 , V_85 , V_136 ,
V_23 -> V_90 . V_137 ) ;
V_21 -> V_96 = V_96 ;
}
static void F_69 ( struct V_18 * V_19 , struct V_151 * V_152 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = F_1 ( V_2 , V_152 -> V_153 ) ;
if ( V_4 < 0 )
return;
if ( F_70 ( F_2 ( V_2 , V_4 ) , 1 ) )
F_71 ( V_19 ) ;
}
static void F_72 ( struct V_18 * V_19 , unsigned int V_154 )
{
int V_155 = V_154 >> V_156 ;
struct V_151 * V_152 ;
int V_157 = ( V_154 & V_158 ) >> V_159 ;
V_152 = F_73 ( V_19 , V_155 ) ;
if ( ! V_152 )
return;
V_152 -> V_160 = 1 ;
F_74 ( V_161 ,
L_15 ,
V_19 -> V_67 , V_152 -> V_153 , V_157 , ! ! ( V_154 & V_162 ) ,
! ! ( V_154 & V_163 ) , ! ! ( V_154 & V_164 ) ) ;
F_69 ( V_19 , V_152 ) ;
}
static void F_75 ( struct V_18 * V_19 , unsigned int V_154 )
{
int V_155 = V_154 >> V_156 ;
int V_165 = ( V_154 & V_166 ) >> V_167 ;
int V_168 = ! ! ( V_154 & V_169 ) ;
int V_170 = ! ! ( V_154 & V_171 ) ;
F_43 ( V_128
L_16 ,
V_19 -> V_67 ,
V_155 ,
V_165 ,
V_168 ,
V_170 ) ;
if ( V_168 )
;
if ( V_170 )
;
}
static void F_76 ( struct V_18 * V_19 , unsigned int V_154 )
{
int V_155 = V_154 >> V_156 ;
int V_165 = ( V_154 & V_166 ) >> V_167 ;
if ( ! F_73 ( V_19 , V_155 ) ) {
F_62 ( V_128 L_17 , V_155 ) ;
return;
}
if ( V_165 == 0 )
F_72 ( V_19 , V_154 ) ;
else
F_75 ( V_19 , V_154 ) ;
}
static void F_77 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_153 )
{
int V_172 ;
if ( ! F_78 ( V_19 , V_11 , V_173 ) )
F_21 ( V_19 , V_11 , 0 , V_174 , V_173 ) ;
if ( ! F_78 ( V_19 , V_153 , V_173 ) ) {
F_21 ( V_19 , V_153 , 0 , V_174 ,
V_173 ) ;
F_79 ( 40 ) ;
V_172 = F_19 ( V_19 , V_153 , 0 , V_175 , 0 ) ;
V_172 = ( V_172 & V_176 ) >> V_177 ;
F_62 ( L_18 , V_153 , V_172 ) ;
}
}
static int F_80 ( struct V_18 * V_19 , T_1 V_3 ,
bool V_178 )
{
int V_179 , V_180 ;
if ( F_81 ( V_19 , V_3 ) & V_181 ) {
V_179 = F_19 ( V_19 , V_3 , 0 ,
V_182 , 0 ) ;
if ( V_179 < 0 )
return V_178 ? - V_7 : 0 ;
V_180 = V_179 & ~ V_183 ;
if ( V_178 )
V_180 |= V_184 ;
else
V_180 |= V_185 ;
F_40 ( L_19
L_20 ,
V_3 ,
V_179 == V_180 ? L_21 : L_22 ,
V_180 ) ;
if ( V_179 != V_180 )
F_21 ( V_19 , V_3 , 0 ,
V_56 ,
V_180 ) ;
} else if ( V_178 )
return - V_7 ;
return 0 ;
}
static int F_82 ( struct V_18 * V_19 , T_1 V_11 ,
T_1 V_3 , T_3 V_186 , int V_187 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_39 ;
if ( F_68 ( V_19 ) )
F_77 ( V_19 , V_11 , V_3 ) ;
V_39 = V_2 -> V_93 . V_188 ( V_19 , V_3 , F_83 ( V_187 ) ) ;
if ( V_39 ) {
F_40 ( L_23 ) ;
return V_39 ;
}
F_84 ( V_19 , V_11 , V_186 , 0 , V_187 ) ;
return 0 ;
}
static int F_85 ( struct V_18 * V_19 ,
int V_4 , int * V_189 , int * V_190 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 ;
struct V_191 * V_192 = NULL ;
int V_12 , V_193 = 0 ;
V_21 = F_2 ( V_2 , V_4 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_192 = F_7 ( V_2 , V_12 ) ;
if ( V_192 -> V_194 )
continue;
for ( V_193 = 0 ; V_193 < V_21 -> V_195 ; V_193 ++ )
if ( V_21 -> V_196 [ V_193 ] == V_192 -> V_11 )
break;
if ( V_193 == V_21 -> V_195 )
continue;
break;
}
if ( V_12 == V_2 -> V_13 )
return - V_197 ;
if ( V_189 )
* V_189 = V_12 ;
if ( V_190 )
* V_190 = V_193 ;
return 0 ;
}
static void F_86 ( struct V_18 * V_19 ,
T_1 V_3 , int V_193 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_153 , V_198 ;
int V_12 , V_199 ;
struct V_191 * V_192 ;
V_198 = V_19 -> V_200 + V_19 -> V_201 ;
for ( V_153 = V_19 -> V_200 ; V_153 < V_198 ; V_153 ++ ) {
unsigned int V_202 = F_24 ( V_19 , V_153 ) ;
unsigned int V_203 = F_87 ( V_202 ) ;
if ( V_203 != V_204 )
continue;
if ( V_153 == V_3 )
continue;
V_199 = F_19 ( V_19 , V_153 , 0 ,
V_205 , 0 ) ;
if ( V_199 != V_193 )
continue;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_192 = F_7 ( V_2 , V_12 ) ;
if ( ! V_192 -> V_194 ) {
F_40 ( L_24 ,
V_12 , V_153 ) ;
F_88 ( V_19 , V_153 , 0 ,
V_206 ,
V_12 ) ;
break;
}
}
}
}
static int F_89 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_209 * V_210 = V_208 -> V_210 ;
int V_4 , V_12 , V_193 = 0 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_191 * V_192 = NULL ;
int V_39 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_90 ( V_4 < 0 ) )
return - V_7 ;
V_21 = F_2 ( V_2 , V_4 ) ;
V_23 = & V_21 -> V_26 ;
V_39 = F_85 ( V_19 , V_4 , & V_12 , & V_193 ) ;
if ( V_39 < 0 )
return V_39 ;
V_192 = F_7 ( V_2 , V_12 ) ;
V_192 -> V_194 = 1 ;
V_21 -> V_11 = V_192 -> V_11 ;
V_9 -> V_153 = V_192 -> V_11 ;
F_88 ( V_19 , V_21 -> V_3 , 0 ,
V_206 ,
V_193 ) ;
if ( F_68 ( V_19 ) || F_91 ( V_19 ) )
F_86 ( V_19 , V_21 -> V_3 , V_193 ) ;
F_92 ( V_19 , V_4 , V_192 -> V_11 ) ;
V_9 -> V_211 = V_192 -> V_211 ;
V_9 -> V_212 = V_192 -> V_212 ;
V_9 -> V_213 = V_192 -> V_213 ;
V_9 -> V_214 = V_192 -> V_214 ;
V_9 -> V_215 = V_192 -> V_215 ;
if ( ! V_216 && V_23 -> V_29 ) {
F_93 ( & V_23 -> V_90 , V_9 ) ;
if ( V_9 -> V_211 > V_9 -> V_212 ||
! V_9 -> V_213 || ! V_9 -> V_214 ) {
V_192 -> V_194 = 0 ;
V_9 -> V_153 = 0 ;
F_94 ( V_19 , V_4 ) ;
return - V_197 ;
}
}
V_210 -> V_217 . V_211 = V_9 -> V_211 ;
V_210 -> V_217 . V_212 = V_9 -> V_212 ;
V_210 -> V_217 . V_214 = V_9 -> V_214 ;
V_210 -> V_217 . V_213 = V_9 -> V_213 ;
F_95 ( V_208 -> V_210 , 0 ,
V_218 , 2 ) ;
return 0 ;
}
static int F_96 ( struct V_18 * V_19 , int V_4 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_21 -> V_3 ;
if ( ! ( F_24 ( V_19 , V_3 ) & V_219 ) ) {
F_3 ( V_6
L_25
L_26 ,
V_3 , F_24 ( V_19 , V_3 ) ) ;
return - V_7 ;
}
V_21 -> V_195 = F_97 ( V_19 , V_3 ,
V_21 -> V_196 ,
V_220 ) ;
return 0 ;
}
static bool F_70 ( struct V_20 * V_21 , int V_221 )
{
struct V_151 * V_152 ;
struct V_18 * V_19 = V_21 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_22 * V_23 = & V_2 -> V_222 ;
struct V_22 * V_223 = & V_21 -> V_26 ;
T_1 V_3 = V_21 -> V_3 ;
int V_224 ;
bool V_225 = false ;
bool V_226 = false ;
bool V_227 ;
F_98 ( V_19 ) ;
V_224 = F_99 ( V_19 , V_3 ) ;
F_10 ( & V_21 -> V_27 ) ;
V_223 -> V_148 = ! ! ( V_224 & V_228 ) ;
if ( V_223 -> V_148 )
V_23 -> V_29 = ! ! ( V_224 & V_229 ) ;
else
V_23 -> V_29 = false ;
F_74 ( V_161 ,
L_27 ,
V_19 -> V_67 , V_3 , V_223 -> V_148 , V_23 -> V_29 ) ;
if ( V_23 -> V_29 ) {
if ( V_2 -> V_93 . V_230 ( V_19 , V_3 , V_23 -> V_36 ,
& V_23 -> V_30 ) < 0 )
V_23 -> V_29 = false ;
else {
memset ( & V_23 -> V_90 , 0 , sizeof( struct V_231 ) ) ;
if ( F_100 ( & V_23 -> V_90 , V_23 -> V_36 ,
V_23 -> V_30 ) < 0 )
V_23 -> V_29 = false ;
}
if ( V_23 -> V_29 ) {
F_101 ( & V_23 -> V_90 ) ;
V_225 = true ;
}
else if ( V_221 ) {
F_102 ( V_19 -> V_68 -> V_232 ,
& V_21 -> V_233 ,
F_103 ( 300 ) ) ;
goto V_234;
}
}
if ( V_223 -> V_29 && ! V_23 -> V_29 ) {
V_225 = true ;
V_226 = true ;
}
if ( V_225 ) {
bool V_235 = V_223 -> V_29 ;
V_223 -> V_29 = V_23 -> V_29 ;
V_226 = V_223 -> V_30 != V_23 -> V_30 ||
memcmp ( V_223 -> V_36 , V_23 -> V_36 ,
V_23 -> V_30 ) != 0 ;
if ( V_226 )
memcpy ( V_223 -> V_36 , V_23 -> V_36 ,
V_23 -> V_30 ) ;
V_223 -> V_30 = V_23 -> V_30 ;
V_223 -> V_90 = V_23 -> V_90 ;
if ( V_23 -> V_29 && ! V_235 && V_21 -> V_236 )
F_67 ( V_19 , V_21 ,
V_21 -> V_96 ) ;
}
if ( V_226 )
F_104 ( V_19 -> V_68 -> V_69 ,
V_237 | V_238 ,
& V_21 -> V_43 -> V_42 ) ;
V_234:
V_227 = ! V_221 || ! V_223 -> V_148 || V_223 -> V_29 ;
V_152 = F_105 ( V_19 , V_3 ) ;
if ( V_152 )
V_152 -> V_239 = ! V_227 ;
F_11 ( & V_21 -> V_27 ) ;
F_106 ( V_19 ) ;
return V_227 ;
}
static void F_107 ( struct V_240 * V_233 )
{
struct V_20 * V_21 =
F_108 ( F_109 ( V_233 ) , struct V_20 , V_233 ) ;
if ( V_21 -> V_241 ++ > 6 )
V_21 -> V_241 = 0 ;
if ( F_70 ( V_21 , V_21 -> V_241 ) )
F_71 ( V_21 -> V_19 ) ;
}
static int F_110 ( struct V_18 * V_19 , T_1 V_3 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_242 , V_243 ;
int V_4 ;
struct V_20 * V_21 ;
int V_39 ;
V_242 = F_81 ( V_19 , V_3 ) ;
if ( ! ( V_242 & ( V_244 | V_245 ) ) )
return 0 ;
V_243 = F_111 ( V_19 , V_3 ) ;
if ( F_112 ( V_243 ) == V_246 )
return 0 ;
if ( F_68 ( V_19 ) )
F_113 ( V_19 , V_3 ) ;
V_4 = V_2 -> V_5 ;
V_21 = F_114 ( & V_2 -> V_247 ) ;
if ( ! V_21 )
return - V_41 ;
V_21 -> V_3 = V_3 ;
V_21 -> V_96 = false ;
V_39 = F_96 ( V_19 , V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_115 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_191 * V_192 ;
unsigned int V_248 ;
int V_39 ;
V_248 = F_24 ( V_19 , V_11 ) ;
V_248 = F_116 ( V_248 ) ;
V_192 = F_114 ( & V_2 -> V_249 ) ;
if ( ! V_192 )
return - V_41 ;
V_192 -> V_11 = V_11 ;
V_192 -> V_211 = 2 ;
if ( V_248 <= 16 ) {
V_192 -> V_212 = V_248 ;
if ( V_248 > V_2 -> V_212 )
V_2 -> V_212 = V_248 ;
}
V_39 = F_117 ( V_19 , V_11 ,
& V_192 -> V_213 ,
& V_192 -> V_214 ,
& V_192 -> V_215 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_2 -> V_13 < F_13 ( V_2 -> V_250 ) )
V_2 -> V_250 [ V_2 -> V_13 ] = V_11 ;
V_2 -> V_13 ++ ;
return 0 ;
}
static int F_118 ( struct V_18 * V_19 )
{
T_1 V_153 ;
int V_77 , V_251 ;
V_251 = F_119 ( V_19 , V_19 -> V_252 , & V_153 ) ;
if ( ! V_153 || V_251 < 0 ) {
F_3 ( V_6 L_28 ) ;
return - V_7 ;
}
for ( V_77 = 0 ; V_77 < V_251 ; V_77 ++ , V_153 ++ ) {
unsigned int V_242 ;
unsigned int type ;
V_242 = F_24 ( V_19 , V_153 ) ;
type = F_87 ( V_242 ) ;
if ( ! ( V_242 & V_253 ) )
continue;
switch ( type ) {
case V_254 :
F_115 ( V_19 , V_153 ) ;
break;
case V_204 :
F_110 ( V_19 , V_153 ) ;
break;
}
}
return 0 ;
}
static bool F_120 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_255 * V_256 ;
bool V_96 ;
F_10 ( & V_19 -> V_257 ) ;
V_256 = F_121 ( V_19 , V_11 ) ;
V_96 = ! ! ( V_256 -> V_258 & V_259 ) ;
F_11 ( & V_19 -> V_257 ) ;
return V_96 ;
}
static int F_122 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_186 ,
unsigned int V_187 ,
struct V_207 * V_208 )
{
T_1 V_11 = V_9 -> V_153 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = F_4 ( V_2 , V_9 ) ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_21 -> V_3 ;
bool V_96 ;
int V_179 ;
V_96 = F_120 ( V_19 , V_11 ) ;
F_10 ( & V_21 -> V_27 ) ;
V_21 -> V_82 = V_208 -> V_210 -> V_82 ;
V_21 -> V_236 = true ;
F_67 ( V_19 , V_21 , V_96 ) ;
F_11 ( & V_21 -> V_27 ) ;
if ( V_2 -> V_54 ) {
V_179 = F_19 ( V_19 , V_3 , 0 ,
V_182 , 0 ) ;
F_21 ( V_19 , V_3 , 0 ,
V_56 ,
V_179 | V_55 ) ;
}
return V_2 -> V_93 . V_260 ( V_19 , V_11 , V_3 , V_186 , V_187 ) ;
}
static int F_123 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_207 * V_208 )
{
F_124 ( V_19 , V_9 -> V_153 ) ;
return 0 ;
}
static int F_125 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_12 , V_4 ;
struct V_191 * V_192 ;
struct V_20 * V_21 ;
int V_179 ;
if ( V_9 -> V_153 ) {
V_12 = F_6 ( V_2 , V_9 -> V_153 ) ;
if ( F_90 ( V_12 < 0 ) )
return - V_7 ;
V_192 = F_7 ( V_2 , V_12 ) ;
F_90 ( ! V_192 -> V_194 ) ;
V_192 -> V_194 = 0 ;
V_9 -> V_153 = 0 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_90 ( V_4 < 0 ) )
return - V_7 ;
V_21 = F_2 ( V_2 , V_4 ) ;
if ( V_2 -> V_54 ) {
V_179 = F_19 ( V_19 , V_21 -> V_3 , 0 ,
V_182 , 0 ) ;
F_21 ( V_19 , V_21 -> V_3 , 0 ,
V_56 ,
V_179 & ~ V_55 ) ;
}
F_94 ( V_19 , V_4 ) ;
F_10 ( & V_21 -> V_27 ) ;
V_21 -> V_117 = false ;
memset ( V_21 -> V_149 , 0 , sizeof( V_21 -> V_149 ) ) ;
V_21 -> V_236 = false ;
V_21 -> V_82 = 0 ;
F_11 ( & V_21 -> V_27 ) ;
}
return 0 ;
}
static int F_126 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_261 * V_90 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_90 -> V_64 ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_17 -> type = V_262 ;
V_17 -> V_28 = V_2 -> V_212 ;
V_17 -> V_33 . integer . V_263 = 0 ;
V_17 -> V_33 . integer . V_264 = V_265 ;
return 0 ;
}
static int F_127 ( struct V_79 * V_266 ,
int V_82 )
{
if ( V_266 -> V_82 != V_82 )
return - 1 ;
return V_267 ;
}
static void F_128 ( struct V_79 * V_266 ,
unsigned int * V_149 , int V_82 )
{
int V_28 = 0 ;
int V_70 ;
for ( V_70 = 7 ; V_70 >= 0 ; V_70 -- ) {
int V_112 = V_266 -> V_84 [ V_70 ] ;
if ( ! V_112 )
continue;
V_149 [ V_28 ++ ] = F_48 ( V_112 ) ;
}
F_45 ( V_28 != V_82 ) ;
}
static int F_129 ( struct V_14 * V_15 , int V_268 ,
unsigned int V_124 , unsigned int T_4 * V_269 )
{
struct V_261 * V_90 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_90 -> V_64 ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int T_4 * V_270 ;
int V_58 , V_28 = 0 ;
if ( V_124 < 8 )
return - V_41 ;
if ( F_130 ( V_271 , V_269 ) )
return - V_272 ;
V_124 -= 8 ;
V_270 = V_269 + 2 ;
for ( V_58 = 2 ; V_58 <= V_2 -> V_212 ; V_58 ++ ) {
int V_77 ;
struct V_79 * V_266 ;
V_266 = V_81 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ , V_266 ++ ) {
int V_273 = V_58 * 4 ;
int type = V_2 -> V_93 . V_274 ( V_266 , V_58 ) ;
unsigned int V_275 [ 8 ] ;
if ( type < 0 )
continue;
if ( V_124 < 8 )
return - V_41 ;
if ( F_130 ( type , V_270 ) ||
F_130 ( V_273 , V_270 + 1 ) )
return - V_272 ;
V_270 += 2 ;
V_124 -= 8 ;
V_28 += 8 ;
if ( V_124 < V_273 )
return - V_41 ;
V_124 -= V_273 ;
V_28 += V_273 ;
V_2 -> V_93 . V_276 ( V_266 , V_275 , V_58 ) ;
if ( F_131 ( V_270 , V_275 , V_273 ) )
return - V_272 ;
V_270 += V_58 ;
}
}
if ( F_130 ( V_28 , V_269 + 1 ) )
return - V_272 ;
return 0 ;
}
static int F_132 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_261 * V_90 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_90 -> V_64 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_25 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
int V_77 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_21 -> V_149 ) ; V_77 ++ )
V_32 -> V_33 . integer . V_33 [ V_77 ] = V_21 -> V_149 [ V_77 ] ;
return 0 ;
}
static int F_133 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_261 * V_90 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_90 -> V_64 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_25 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
unsigned int V_277 ;
struct V_207 * V_208 ;
unsigned char V_149 [ 8 ] ;
int V_77 , V_39 , V_85 , V_278 = 0 ;
V_277 = F_134 ( V_15 , & V_32 -> V_42 ) ;
V_208 = F_135 ( V_90 , V_277 ) ;
if ( ! V_208 || ! V_208 -> V_210 )
return 0 ;
switch ( V_208 -> V_210 -> V_258 -> V_279 ) {
case V_280 :
case V_281 :
break;
case V_282 :
V_278 = 1 ;
break;
default:
return - V_283 ;
}
memset ( V_149 , 0 , sizeof( V_149 ) ) ;
for ( V_77 = 0 ; V_77 < F_13 ( V_149 ) ; V_77 ++ )
V_149 [ V_77 ] = V_32 -> V_33 . integer . V_33 [ V_77 ] ;
if ( ! memcmp ( V_149 , V_21 -> V_149 , sizeof( V_149 ) ) )
return 0 ;
V_85 = F_50 ( F_13 ( V_149 ) , V_149 ) ;
if ( V_85 < 0 )
return - V_7 ;
if ( V_2 -> V_93 . V_284 ) {
V_39 = V_2 -> V_93 . V_284 ( V_85 , F_13 ( V_149 ) , V_149 ) ;
if ( V_39 )
return V_39 ;
}
F_10 ( & V_21 -> V_27 ) ;
V_21 -> V_117 = true ;
memcpy ( V_21 -> V_149 , V_149 , sizeof( V_149 ) ) ;
if ( V_278 )
F_67 ( V_19 , V_21 , V_21 -> V_96 ) ;
F_11 ( & V_21 -> V_27 ) ;
return 0 ;
}
static int F_136 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_285 * V_90 ;
struct V_8 * V_286 ;
struct V_20 * V_21 ;
V_21 = F_2 ( V_2 , V_4 ) ;
sprintf ( V_21 -> V_287 , L_29 , V_4 ) ;
V_90 = F_114 ( & V_2 -> V_288 ) ;
if ( ! V_90 )
return - V_41 ;
V_90 -> V_66 = V_21 -> V_287 ;
V_90 -> V_289 = V_290 ;
V_90 -> V_291 = true ;
V_286 = & V_90 -> V_10 [ V_292 ] ;
V_286 -> V_293 = 1 ;
V_286 -> V_93 = V_294 ;
}
V_19 -> V_295 = V_2 -> V_5 ;
V_19 -> V_296 = V_2 -> V_288 . V_297 ;
return 0 ;
}
static int F_137 ( struct V_18 * V_19 , int V_4 )
{
char V_298 [ 32 ] = L_30 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
int V_299 = F_5 ( V_2 , V_4 ) -> V_37 ;
if ( V_299 > 0 )
sprintf ( V_298 + strlen ( V_298 ) , L_31 , V_299 ) ;
if ( ! F_138 ( V_19 , V_21 -> V_3 ) )
strncat ( V_298 , L_32 ,
sizeof( V_298 ) - strlen ( V_298 ) - 1 ) ;
return F_139 ( V_19 , V_21 -> V_3 , V_298 , 0 ) ;
}
static int F_140 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_39 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
V_39 = F_137 ( V_19 , V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_141 ( V_19 ,
V_21 -> V_3 ,
V_21 -> V_196 [ 0 ] ,
V_290 ) ;
if ( V_39 < 0 )
return V_39 ;
F_94 ( V_19 , V_4 ) ;
V_39 = F_15 ( V_19 , V_4 ,
F_5 ( V_2 , V_4 ) -> V_37 ) ;
if ( V_39 < 0 )
return V_39 ;
F_70 ( V_21 , 0 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_261 * V_149 ;
struct V_14 * V_38 ;
int V_77 ;
if ( ! V_19 -> V_296 [ V_4 ] . V_300 )
break;
V_39 = F_142 ( V_19 -> V_296 [ V_4 ] . V_300 ,
V_292 ,
NULL , 0 , V_4 , & V_149 ) ;
if ( V_39 < 0 )
return V_39 ;
V_149 -> V_64 = V_19 ;
V_38 = V_149 -> V_38 ;
for ( V_77 = 0 ; V_77 < V_38 -> V_28 ; V_77 ++ )
V_38 -> V_301 [ V_77 ] . V_302 |= V_303 ;
V_38 -> V_90 = F_126 ;
V_38 -> V_304 = F_132 ;
V_38 -> V_305 = F_133 ;
V_38 -> V_269 . V_70 = F_129 ;
}
return 0 ;
}
static int F_143 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
V_21 -> V_19 = V_19 ;
F_144 ( & V_21 -> V_27 ) ;
F_145 ( & V_21 -> V_233 , F_107 ) ;
F_31 ( V_21 , V_4 ) ;
}
return 0 ;
}
static int F_146 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_21 -> V_3 ;
F_23 ( V_19 , V_3 ) ;
F_147 ( V_19 , V_3 , V_3 ,
V_19 -> V_306 > 0 ? F_69 : NULL ) ;
}
return 0 ;
}
static void F_148 ( struct V_1 * V_2 , int V_307 )
{
F_149 ( & V_2 -> V_247 , sizeof( struct V_20 ) , V_307 ) ;
F_149 ( & V_2 -> V_249 , sizeof( struct V_191 ) , V_307 ) ;
F_149 ( & V_2 -> V_288 , sizeof( struct V_285 ) , V_307 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
F_151 ( & V_2 -> V_247 ) ;
F_151 ( & V_2 -> V_249 ) ;
F_151 ( & V_2 -> V_288 ) ;
}
static void F_152 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
F_153 ( & V_21 -> V_233 ) ;
F_34 ( V_21 ) ;
}
F_154 ( V_19 -> V_68 -> V_232 ) ;
F_150 ( V_2 ) ;
F_155 ( V_2 ) ;
}
static int F_156 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
F_146 ( V_19 ) ;
F_157 ( V_19 ) ;
F_158 ( V_19 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
F_70 ( V_21 , 1 ) ;
}
return 0 ;
}
static void F_113 ( struct V_18 * V_19 ,
T_1 V_153 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_308 [ 4 ] ;
int V_309 ;
V_309 = F_97 ( V_19 , V_153 , V_308 , F_13 ( V_308 ) ) ;
if ( V_309 == V_2 -> V_13 &&
! memcmp ( V_308 , V_2 -> V_250 , V_2 -> V_13 * sizeof( T_1 ) ) )
return;
F_40 ( L_33 , V_153 ) ;
F_159 ( V_19 , V_153 , V_2 -> V_13 , V_2 -> V_250 ) ;
}
static void F_160 ( struct V_18 * V_19 ,
bool V_310 )
{
unsigned int V_311 ;
V_311 = F_19 ( V_19 , V_312 , 0 ,
V_313 , 0 ) ;
if ( V_311 == - 1 || V_311 & V_314 )
return;
V_311 |= V_314 ;
V_311 = F_19 ( V_19 , V_312 , 0 ,
V_315 , V_311 ) ;
if ( V_311 == - 1 )
return;
if ( V_310 )
F_161 ( V_19 ) ;
}
static void F_162 ( struct V_18 * V_19 )
{
unsigned int V_311 ;
V_311 = F_19 ( V_19 , V_312 , 0 ,
V_313 , 0 ) ;
if ( V_311 == - 1 || V_311 & V_316 )
return;
V_311 |= V_316 ;
F_88 ( V_19 , V_312 , 0 ,
V_315 , V_311 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_1 V_317 ,
unsigned int V_318 )
{
if ( V_318 == V_173 ) {
F_160 ( V_19 , false ) ;
F_162 ( V_19 ) ;
}
F_19 ( V_19 , V_317 , 0 , V_174 , V_318 ) ;
F_164 ( V_19 , V_317 , V_318 ) ;
}
static int F_165 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_166 ( sizeof( * V_2 ) , V_319 ) ;
if ( V_2 == NULL )
return - V_41 ;
V_2 -> V_93 = V_320 ;
V_19 -> V_2 = V_2 ;
F_148 ( V_2 , 4 ) ;
if ( F_68 ( V_19 ) ) {
F_160 ( V_19 , true ) ;
F_162 ( V_19 ) ;
}
if ( F_167 ( V_19 ) || F_91 ( V_19 ) ) {
V_19 -> V_321 = 0 ;
}
if ( F_118 ( V_19 ) < 0 ) {
V_19 -> V_2 = NULL ;
F_155 ( V_2 ) ;
return - V_7 ;
}
V_19 -> V_322 = V_323 ;
if ( F_68 ( V_19 ) ) {
V_19 -> V_322 . V_324 = F_163 ;
V_19 -> V_325 = true ;
}
F_143 ( V_19 ) ;
F_36 () ;
return 0 ;
}
static int F_168 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_285 * V_90 ;
unsigned int V_248 ;
struct V_8 * V_286 ;
struct V_191 * V_192 ;
V_192 = F_7 ( V_2 , 0 ) ;
V_248 = F_24 ( V_19 , V_192 -> V_11 ) ;
V_248 = F_116 ( V_248 ) ;
V_90 = F_114 ( & V_2 -> V_288 ) ;
if ( ! V_90 )
return - V_41 ;
V_90 -> V_66 = F_2 ( V_2 , 0 ) -> V_287 ;
sprintf ( V_90 -> V_66 , L_34 ) ;
V_90 -> V_289 = V_290 ;
V_286 = & V_90 -> V_10 [ V_292 ] ;
* V_286 = V_2 -> V_326 ;
V_286 -> V_153 = V_192 -> V_11 ;
if ( V_286 -> V_212 <= 2 && V_248 && V_248 <= 16 )
V_286 -> V_212 = V_248 ;
V_19 -> V_295 = 1 ;
V_19 -> V_296 = V_90 ;
return 0 ;
}
static void F_169 ( struct V_18 * V_19 ,
unsigned int V_154 )
{
F_170 ( V_19 ) ;
F_71 ( V_19 ) ;
}
static int F_171 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_191 * V_192 ;
int V_39 ;
V_192 = F_7 ( V_2 , 0 ) ;
V_39 = F_141 ( V_19 , V_192 -> V_11 ,
V_192 -> V_11 ,
V_290 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_172 ( V_19 , 0 ) ;
}
static int F_173 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = F_2 ( V_2 , 0 ) ;
T_1 V_327 = V_21 -> V_3 ;
F_21 ( V_19 , V_327 , 0 ,
V_56 , V_55 ) ;
if ( F_24 ( V_19 , V_327 ) & V_51 )
F_21 ( V_19 , V_327 , 0 , V_52 ,
V_53 ) ;
F_174 ( V_19 , V_327 , V_327 ) ;
return 0 ;
}
static void F_175 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_150 ( V_2 ) ;
F_155 ( V_2 ) ;
}
static int F_176 ( struct V_18 * V_19 )
{
F_177 ( V_19 , V_328 ) ;
return 0 ;
}
static int F_178 ( struct V_18 * V_19 )
{
F_177 ( V_19 , V_329 ) ;
return 0 ;
}
static int F_179 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_330 * V_331 = NULL ;
switch ( V_19 -> V_332 -> V_42 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_331 = & V_333 ;
break;
case 0x10de0007 :
V_331 = & V_334 ;
break;
default:
break;
}
if ( V_331 != NULL ) {
V_330 ( V_208 -> V_210 , 0 ,
V_218 ,
V_331 ) ;
} else {
F_95 ( V_208 -> V_210 , 0 ,
V_218 , 2 ) ;
}
return F_180 ( V_19 , & V_2 -> V_335 ) ;
}
static int F_181 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_182 ( V_19 , & V_2 -> V_335 ) ;
}
static int F_183 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_186 ,
unsigned int V_187 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_184 ( V_19 , & V_2 -> V_335 ,
V_186 , V_187 , V_208 ) ;
}
static int F_185 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_3 )
{
struct V_1 * V_2 ;
struct V_191 * V_192 ;
struct V_20 * V_21 ;
V_2 = F_166 ( sizeof( * V_2 ) , V_319 ) ;
if ( ! V_2 )
return - V_41 ;
V_19 -> V_2 = V_2 ;
F_148 ( V_2 , 1 ) ;
V_2 -> V_335 . V_336 = 0 ;
V_2 -> V_335 . V_337 = 2 ;
V_2 -> V_335 . V_338 = V_11 ;
V_2 -> V_13 = 1 ;
V_2 -> V_5 = 1 ;
V_21 = F_114 ( & V_2 -> V_247 ) ;
V_192 = F_114 ( & V_2 -> V_249 ) ;
if ( ! V_21 || ! V_192 ) {
F_175 ( V_19 ) ;
return - V_41 ;
}
V_192 -> V_11 = V_11 ;
V_21 -> V_3 = V_3 ;
V_2 -> V_326 = V_339 ;
V_19 -> V_322 = V_340 ;
return 0 ;
}
static void F_186 ( struct V_18 * V_19 ,
int V_82 )
{
unsigned int V_341 ;
int V_342 = V_82 ? ( V_82 - 1 ) : 1 ;
switch ( V_82 ) {
default:
case 0 :
case 2 :
V_341 = 0x00 ;
break;
case 4 :
V_341 = 0x08 ;
break;
case 6 :
V_341 = 0x0b ;
break;
case 8 :
V_341 = 0x13 ;
break;
}
F_21 ( V_19 , 0x1 , 0 ,
V_343 , V_341 ) ;
F_21 ( V_19 , 0x1 , 0 ,
V_344 ,
( 0x71 - V_342 - V_341 ) ) ;
}
static int F_187 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_77 ;
F_21 ( V_19 , V_345 ,
0 , V_346 , 0 ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
F_21 ( V_19 , V_347 [ V_77 ] , 0 ,
V_346 , 0 ) ;
F_21 ( V_19 , V_347 [ V_77 ] , 0 ,
V_348 , 0 ) ;
}
F_186 ( V_19 , 8 ) ;
return F_182 ( V_19 , & V_2 -> V_335 ) ;
}
static int F_188 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_186 ,
unsigned int V_187 ,
struct V_207 * V_208 )
{
int V_58 ;
unsigned int V_349 , V_350 ;
int V_77 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_255 * V_256 ;
struct V_191 * V_192 ;
F_10 ( & V_19 -> V_257 ) ;
V_192 = F_7 ( V_2 , 0 ) ;
V_256 = F_121 ( V_19 , V_192 -> V_11 ) ;
V_58 = V_208 -> V_210 -> V_82 ;
V_349 = 0x2 ;
if ( V_19 -> V_351 && ( V_256 -> V_352 & V_353 ) )
F_21 ( V_19 ,
V_345 ,
0 ,
V_354 ,
V_256 -> V_352 & ~ V_353 & 0xff ) ;
F_21 ( V_19 , V_345 , 0 ,
V_346 , ( V_186 << 4 ) | 0x0 ) ;
F_21 ( V_19 , V_345 , 0 ,
V_348 , V_187 ) ;
if ( V_19 -> V_351 && ( V_256 -> V_352 & V_353 ) ) {
F_21 ( V_19 ,
V_345 ,
0 ,
V_354 ,
V_256 -> V_352 & 0xff ) ;
F_21 ( V_19 ,
V_345 ,
0 ,
V_355 , V_349 ) ;
}
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
if ( V_58 == 2 )
V_350 = 0 ;
else
V_350 = V_77 * 2 ;
if ( V_19 -> V_351 &&
( V_256 -> V_352 & V_353 ) )
F_21 ( V_19 ,
V_347 [ V_77 ] ,
0 ,
V_354 ,
V_256 -> V_352 & ~ V_353 & 0xff ) ;
F_21 ( V_19 ,
V_347 [ V_77 ] ,
0 ,
V_346 ,
( V_186 << 4 ) | V_350 ) ;
F_21 ( V_19 ,
V_347 [ V_77 ] ,
0 ,
V_348 ,
V_187 ) ;
if ( V_19 -> V_351 &&
( V_256 -> V_352 & V_353 ) ) {
F_21 ( V_19 ,
V_347 [ V_77 ] ,
0 ,
V_354 ,
V_256 -> V_352 & 0xff ) ;
F_21 ( V_19 ,
V_347 [ V_77 ] ,
0 ,
V_355 , V_349 ) ;
}
}
F_186 ( V_19 , V_58 ) ;
F_11 ( & V_19 -> V_257 ) ;
return 0 ;
}
static int F_189 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_39 = F_185 ( V_19 , V_345 ,
V_356 ) ;
if ( V_39 < 0 )
return V_39 ;
V_19 -> V_322 . V_357 = F_176 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_326 . V_213 = V_358 ;
V_2 -> V_326 . V_215 = V_359 ;
V_2 -> V_326 . V_214 = V_360 ;
return 0 ;
}
static int F_190 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_39 = F_168 ( V_19 ) ;
if ( ! V_39 ) {
struct V_285 * V_90 = F_5 ( V_2 , 0 ) ;
V_90 -> V_291 = true ;
}
return V_39 ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_285 * V_90 ;
struct V_261 * V_149 ;
int V_39 ;
V_39 = F_171 ( V_19 ) ;
if ( V_39 < 0 )
return V_39 ;
V_90 = F_5 ( V_2 , 0 ) ;
V_39 = F_142 ( V_90 -> V_300 ,
V_292 ,
V_361 , 8 , 0 , & V_149 ) ;
if ( V_39 < 0 )
return V_39 ;
switch ( V_19 -> V_332 -> V_42 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_149 -> V_362 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_149 -> V_362 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_192 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_39 = F_189 ( V_19 ) ;
if ( V_39 < 0 )
return V_39 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_335 . V_337 = 8 ;
V_2 -> V_326 = V_363 ;
V_19 -> V_322 . V_357 = F_178 ;
V_19 -> V_322 . V_364 = F_190 ;
V_19 -> V_322 . V_365 = F_191 ;
F_186 ( V_19 , 8 ) ;
return 0 ;
}
static int F_193 ( struct V_79 * V_266 ,
int V_82 )
{
if ( V_266 -> V_86 == 0x00 && V_82 == 2 )
return V_366 ;
return F_127 ( V_266 , V_82 ) ;
}
static int F_194 ( int V_85 , int V_58 , unsigned char * V_108 )
{
if ( V_85 == 0x00 && ( V_108 [ 0 ] != V_367 || V_108 [ 1 ] != V_368 ) )
return - V_7 ;
return 0 ;
}
static int F_195 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_39 ;
V_39 = F_165 ( V_19 ) ;
if ( V_39 )
return V_39 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_54 = true ;
V_2 -> V_93 . V_274 =
F_193 ;
V_2 -> V_93 . V_284 = F_194 ;
return 0 ;
}
static int F_196 ( struct V_18 * V_19 , T_1 V_153 ,
unsigned char * V_87 , int * V_30 )
{
return F_197 ( V_19 , V_153 , V_87 , V_30 ,
F_198 ( V_19 ) ) ;
}
static void F_199 ( struct V_18 * V_19 , T_1 V_3 , int V_85 ,
int V_136 , int V_137 )
{
F_21 ( V_19 , V_3 , 0 , V_369 , V_85 ) ;
}
static int F_200 ( int V_110 )
{
switch ( V_110 ) {
case 2 : return 3 ;
case 3 : return 2 ;
default: break;
}
return V_110 ;
}
static int F_201 ( int V_85 , int V_58 , unsigned char * V_108 )
{
struct V_79 * V_266 ;
int V_77 , V_78 ;
V_266 = & V_81 [ F_37 ( V_85 ) ] ;
for ( V_77 = 0 ; V_77 < V_58 ; ++ V_77 ) {
int V_111 = F_46 ( V_108 [ V_77 ] ) ;
bool V_370 = false ;
bool V_371 = false ;
if ( ! V_111 )
continue;
for ( V_78 = 0 + V_77 % 2 ; V_78 < 8 ; V_78 += 2 ) {
int V_372 = 7 - F_200 ( V_78 ) ;
if ( V_266 -> V_84 [ V_372 ] == V_111 ) {
V_370 = true ;
if ( V_77 % 2 == 0 && V_77 + 1 < V_58 ) {
int V_373 = 7 - F_200 ( V_78 + 1 ) ;
int V_374 = F_46 ( V_108 [ V_77 + 1 ] ) ;
int V_375 = V_266 -> V_84 [ V_373 ] ;
if ( V_374 == V_375 )
V_371 = true ;
else
return - V_7 ;
}
break;
}
}
if ( ! V_370 )
return - V_7 ;
if ( V_371 )
V_77 ++ ;
}
return 0 ;
}
static int F_202 ( struct V_18 * V_19 , T_1 V_3 ,
int V_101 , int V_376 )
{
int V_377 ;
int V_378 = 0 ;
if ( V_101 > 7 )
return - V_7 ;
if ( ! F_203 ( V_19 ) ) {
V_101 = F_200 ( V_101 ) ;
if ( V_101 % 2 != 0 && V_376 == 0xf )
return 0 ;
V_101 -= V_101 % 2 ;
if ( V_376 != 0xf )
V_376 -= V_376 % 2 ;
}
V_377 = V_379 + V_101 / 2 + ( V_101 % 2 ) * 0x00e ;
if ( V_376 != 0xf )
V_378 = ( V_376 << 4 ) | V_380 ;
return F_21 ( V_19 , V_3 , 0 , V_377 , V_378 ) ;
}
static int F_204 ( struct V_18 * V_19 , T_1 V_3 ,
int V_118 )
{
bool V_381 = false ;
int V_382 = V_118 ;
int V_377 ;
int V_378 ;
if ( V_118 > 7 )
return - V_7 ;
if ( ! F_203 ( V_19 ) ) {
V_382 = F_200 ( V_118 ) ;
if ( V_382 % 2 != 0 ) {
V_382 -= 1 ;
V_381 = true ;
}
}
V_377 = V_383 + V_382 / 2 + ( V_382 % 2 ) * 0x00e ;
V_378 = F_19 ( V_19 , V_3 , 0 , V_377 , 0 ) ;
if ( ! ( V_378 & V_380 ) )
return 0xf ;
return ( ( V_378 & 0xf0 ) >> 4 ) + ! ! V_381 ;
}
static int F_205 ( struct V_79 * V_266 ,
int V_82 )
{
int V_70 ;
int V_384 = 0 ;
if ( ( V_82 % 2 ) != 0 )
return - 1 ;
for ( V_70 = 0 ; V_70 < 7 ; V_70 += 2 ) {
if ( V_266 -> V_84 [ V_70 ] || V_266 -> V_84 [ V_70 + 1 ] )
V_384 ++ ;
}
if ( V_384 * 2 != V_82 )
return - 1 ;
return V_385 ;
}
static void F_206 ( struct V_79 * V_266 ,
unsigned int * V_149 , int V_82 )
{
int V_28 = 0 ;
int V_70 ;
for ( V_70 = 7 ; V_70 >= 0 ; V_70 -- ) {
int V_342 = 7 - F_200 ( 7 - V_70 ) ;
int V_112 = V_266 -> V_84 [ V_342 ] ;
if ( ! V_112 ) {
if ( V_266 -> V_84 [ V_342 + ( V_342 % 2 ? - 1 : 1 ) ] )
V_149 [ V_28 ++ ] = V_386 ;
continue;
}
V_149 [ V_28 ++ ] = F_48 ( V_112 ) ;
}
F_45 ( V_28 != V_82 ) ;
}
static int F_207 ( struct V_18 * V_19 , T_1 V_3 ,
bool V_178 )
{
int V_387 , V_388 ;
V_387 = F_19 ( V_19 , V_3 , 0 , V_389 , 0 ) ;
if ( V_387 >= 0 && ( V_387 & V_390 ) ) {
if ( V_178 )
V_388 = V_387 | V_391 ;
else
V_388 = V_387 & ~ V_391 ;
F_40 ( L_35
L_36 ,
V_3 ,
V_387 == V_388 ? L_21 : L_22 ,
V_388 ) ;
if ( V_387 != V_388 )
F_21 ( V_19 , V_3 , 0 ,
V_392 ,
V_388 ) ;
} else if ( V_178 )
return - V_7 ;
return 0 ;
}
static int F_208 ( struct V_18 * V_19 , T_1 V_11 ,
T_1 V_3 , T_3 V_186 , int V_187 )
{
if ( F_198 ( V_19 ) ) {
int V_393 = 180 ;
if ( V_187 & V_394 )
V_393 = 0 ;
F_21 ( V_19 , V_11 , 0 , V_395 , V_393 ) ;
}
return F_82 ( V_19 , V_11 , V_3 , V_186 , V_187 ) ;
}
static int F_209 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 , V_39 ;
V_39 = F_146 ( V_19 ) ;
if ( V_39 )
return V_39 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
F_21 ( V_19 , V_21 -> V_3 , 0 , V_396 , 0 ) ;
if ( F_203 ( V_19 ) )
F_21 ( V_19 , V_21 -> V_3 , 0 ,
V_397 ,
V_398 ) ;
}
return 0 ;
}
static int F_210 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_191 * V_192 ;
int V_39 , V_12 ;
V_39 = F_165 ( V_19 ) ;
if ( V_39 )
return V_39 ;
V_19 -> V_322 . V_357 = F_209 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_93 . V_230 = F_196 ;
V_2 -> V_93 . V_94 = F_204 ;
V_2 -> V_93 . V_103 = F_202 ;
V_2 -> V_93 . V_150 = F_199 ;
V_2 -> V_93 . V_188 = F_207 ;
V_2 -> V_93 . V_260 = F_208 ;
if ( ! F_203 ( V_19 ) ) {
V_2 -> V_93 . V_274 =
F_205 ;
V_2 -> V_93 . V_276 = F_206 ;
V_2 -> V_93 . V_284 = F_201 ;
}
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_192 = F_7 ( V_2 , V_12 ) ;
V_192 -> V_212 = V_264 ( V_192 -> V_212 , 8u ) ;
V_192 -> V_213 |= V_358 ;
V_192 -> V_214 |= V_360 ;
V_192 -> V_215 = V_264 ( V_192 -> V_215 , 24u ) ;
}
V_2 -> V_212 = V_264 ( V_2 -> V_212 , 8u ) ;
return 0 ;
}
static int F_211 ( struct V_18 * V_19 )
{
return F_185 ( V_19 , V_399 , V_400 ) ;
}
int F_212 ( struct V_18 * V_19 )
{
return F_165 ( V_19 ) ;
}
static int T_5 F_213 ( void )
{
return F_214 ( & V_401 ) ;
}
static void T_6 F_215 ( void )
{
F_216 ( & V_401 ) ;
}
