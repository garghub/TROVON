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
if ( F_24 ( V_19 , V_3 ) & V_50 )
F_21 ( V_19 , V_3 , 0 ,
V_51 , V_52 ) ;
F_21 ( V_19 , V_3 , 0 ,
V_53 , V_54 ) ;
}
static int F_25 ( struct V_18 * V_19 , T_1 V_11 )
{
return 1 + F_19 ( V_19 , V_11 , 0 ,
V_55 , 0 ) ;
}
static void F_26 ( struct V_18 * V_19 ,
T_1 V_11 , int V_56 )
{
if ( V_56 != F_25 ( V_19 , V_11 ) )
F_21 ( V_19 , V_11 , 0 ,
V_57 , V_56 - 1 ) ;
}
static void F_27 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_20 * V_21 = V_59 -> V_62 ;
F_10 ( & V_21 -> V_27 ) ;
F_28 ( & V_21 -> V_26 , V_61 ) ;
F_11 ( & V_21 -> V_27 ) ;
}
static void F_29 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_20 * V_21 = V_59 -> V_62 ;
F_10 ( & V_21 -> V_27 ) ;
F_30 ( & V_21 -> V_26 , V_61 ) ;
F_11 ( & V_21 -> V_27 ) ;
}
static int F_31 ( struct V_20 * V_21 , int V_63 )
{
char V_64 [ 32 ] ;
struct V_18 * V_19 = V_21 -> V_19 ;
struct V_58 * V_59 ;
int V_39 ;
snprintf ( V_64 , sizeof( V_64 ) , L_4 , V_19 -> V_65 , V_63 ) ;
V_39 = F_32 ( V_19 -> V_66 -> V_67 , V_64 , & V_59 ) ;
if ( V_39 < 0 )
return V_39 ;
F_33 ( V_59 , V_21 , F_27 ) ;
V_59 -> V_68 . V_69 . V_70 = F_29 ;
V_59 -> V_71 |= V_72 ;
V_21 -> V_73 = V_59 ;
return 0 ;
}
static void F_34 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_19 -> V_66 -> V_74 && V_21 -> V_73 ) {
F_35 ( V_21 -> V_19 -> V_66 -> V_67 , V_21 -> V_73 ) ;
V_21 -> V_73 = NULL ;
}
}
static inline int F_31 ( struct V_20 * V_21 ,
int V_63 )
{
return 0 ;
}
static inline void F_34 ( struct V_20 * V_21 )
{
}
static void F_36 ( void )
{
int V_75 , V_76 ;
struct V_77 * V_78 ;
for ( V_75 = 0 ; V_75 < F_13 ( V_79 ) ; V_75 ++ ) {
V_78 = V_79 + V_75 ;
V_78 -> V_80 = 0 ;
V_78 -> V_81 = 0 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_78 -> V_82 ) ; V_76 ++ )
if ( V_78 -> V_82 [ V_76 ] ) {
V_78 -> V_80 ++ ;
V_78 -> V_81 |= V_78 -> V_82 [ V_76 ] ;
}
}
}
static int F_37 ( int V_83 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < F_13 ( V_79 ) ; V_75 ++ ) {
if ( V_79 [ V_75 ] . V_84 == V_83 )
break;
}
return V_75 ;
}
static int F_38 ( struct V_22 * V_23 , int V_80 )
{
int V_75 ;
int V_83 = 0 ;
int V_81 = 0 ;
char V_85 [ V_86 ] ;
if ( V_80 <= 2 )
return 0 ;
for ( V_75 = 0 ; V_75 < F_13 ( V_87 ) ; V_75 ++ ) {
if ( V_23 -> V_88 . V_89 & ( 1 << V_75 ) )
V_81 |= V_87 [ V_75 ] ;
}
for ( V_75 = 0 ; V_75 < F_13 ( V_79 ) ; V_75 ++ ) {
if ( V_80 == V_79 [ V_75 ] . V_80 &&
( V_81 & V_79 [ V_75 ] . V_81 ) ==
V_79 [ V_75 ] . V_81 ) {
V_83 = V_79 [ V_75 ] . V_84 ;
break;
}
}
if ( ! V_83 ) {
for ( V_75 = 0 ; V_75 < F_13 ( V_79 ) ; V_75 ++ ) {
if ( V_80 == V_79 [ V_75 ] . V_80 ) {
V_83 = V_79 [ V_75 ] . V_84 ;
break;
}
}
}
F_39 ( V_23 -> V_88 . V_89 , V_85 , sizeof( V_85 ) ) ;
F_40 ( L_5 ,
V_83 , V_80 , V_85 ) ;
return V_83 ;
}
static void F_41 ( struct V_18 * V_19 ,
T_1 V_3 )
{
#ifdef F_42
struct V_1 * V_2 = V_19 -> V_2 ;
int V_75 ;
int V_90 ;
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
V_90 = V_2 -> V_91 . V_92 ( V_19 , V_3 , V_75 ) ;
F_43 ( V_93 L_6 ,
V_90 , V_75 ) ;
}
#endif
}
static void F_44 ( struct V_18 * V_19 ,
T_1 V_3 ,
bool V_94 ,
int V_83 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_77 * V_95 ;
int V_75 ;
int V_39 ;
int V_96 ;
int V_97 [ 8 ] ;
V_96 = F_37 ( V_83 ) ;
V_95 = & V_79 [ V_96 ] ;
if ( V_98 [ V_83 ] [ 1 ] == 0 ) {
int V_99 = 0 ;
for ( V_75 = 0 ; V_75 < V_95 -> V_80 ; V_75 ++ ) {
while ( ! V_95 -> V_82 [ 7 - V_99 ] && ! F_45 ( V_99 >= 8 ) )
V_99 ++ ;
V_98 [ V_83 ] [ V_75 ] = ( V_75 << 4 ) | V_99 ++ ;
}
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ )
if ( ! V_95 -> V_82 [ 7 - V_99 ] )
V_98 [ V_83 ] [ V_75 ++ ] = ( 0xf << 4 ) | V_99 ;
}
if ( V_94 ) {
for ( V_75 = 0 ; V_75 < V_95 -> V_80 ; V_75 ++ )
V_97 [ V_75 ] = ( V_75 << 4 ) | V_75 ;
for (; V_75 < 8 ; V_75 ++ )
V_97 [ V_75 ] = ( 0xf << 4 ) | V_75 ;
}
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
int V_100 = V_94 ? V_97 [ V_75 ] : V_98 [ V_83 ] [ V_75 ] ;
int V_99 = V_100 & 0x0f ;
int V_90 = ( V_100 & 0xf0 ) >> 4 ;
V_39 = V_2 -> V_91 . V_101 ( V_19 , V_3 , V_99 , V_90 ) ;
if ( V_39 ) {
F_40 ( V_102
L_7 ) ;
break;
}
}
}
static int F_46 ( unsigned char V_68 )
{
struct V_103 * V_104 = V_105 ;
for (; V_104 -> V_106 ; V_104 ++ ) {
if ( V_104 -> V_106 == V_68 )
return V_104 -> V_81 ;
}
return 0 ;
}
static int F_47 ( int V_107 , unsigned char V_108 )
{
int V_109 = F_46 ( V_108 ) ;
int V_75 ;
if ( V_109 ) {
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
if ( V_79 [ V_107 ] . V_82 [ 7 - V_75 ] == V_109 )
return V_75 ;
}
}
return - 1 ;
}
static int F_48 ( int V_110 )
{
struct V_103 * V_104 = V_105 ;
for (; V_104 -> V_106 ; V_104 ++ ) {
if ( V_104 -> V_81 == V_110 )
return V_104 -> V_106 ;
}
return 0 ;
}
static int F_49 ( int V_107 , unsigned char V_111 )
{
int V_109 = V_79 [ V_107 ] . V_82 [ 7 - V_111 ] ;
return F_48 ( V_109 ) ;
}
static int F_50 ( int V_56 , unsigned char * V_106 )
{
int V_75 , V_112 = 0 , V_81 = 0 ;
for ( V_75 = 0 ; V_75 < V_56 ; V_75 ++ ) {
int V_109 = F_46 ( V_106 [ V_75 ] ) ;
if ( V_109 ) {
V_81 |= V_109 ;
V_112 ++ ;
}
}
for ( V_75 = 0 ; V_75 < F_13 ( V_79 ) ; V_75 ++ ) {
if ( ( V_56 == V_79 [ V_75 ] . V_80 ||
V_112 == V_79 [ V_75 ] . V_80 ) &&
( V_81 & V_79 [ V_75 ] . V_81 ) ==
V_79 [ V_75 ] . V_81 )
return V_79 [ V_75 ] . V_84 ;
}
return - 1 ;
}
static int F_51 ( struct V_18 * V_19 ,
T_1 V_3 ,
int V_56 , unsigned char * V_106 ,
int V_83 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_107 = F_37 ( V_83 ) ;
int V_113 , V_99 ;
int V_114 [ 8 ] = { [ 0 ... 7 ] = 0xf } ;
for ( V_113 = 0 ; V_113 < V_56 ; V_113 ++ ) {
V_99 = F_47 ( V_107 , V_106 [ V_113 ] ) ;
if ( V_99 < 0 )
continue;
V_114 [ V_99 ] = V_113 ;
}
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ ) {
int V_39 ;
V_39 = V_2 -> V_91 . V_101 ( V_19 , V_3 , V_99 ,
V_114 [ V_99 ] ) ;
if ( V_39 )
return - V_7 ;
}
return 0 ;
}
static void F_52 ( unsigned char * V_106 , int V_83 )
{
int V_75 ;
int V_107 = F_37 ( V_83 ) ;
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
if ( V_75 < V_79 [ V_107 ] . V_80 )
V_106 [ V_75 ] = F_49 ( V_107 , V_98 [ V_83 ] [ V_75 ] & 0x0f ) ;
else
V_106 [ V_75 ] = 0 ;
}
}
static void F_53 ( struct V_18 * V_19 ,
T_1 V_3 , bool V_94 , int V_83 ,
int V_80 , unsigned char * V_106 ,
bool V_115 )
{
if ( ! V_94 && V_115 ) {
F_51 ( V_19 , V_3 ,
V_80 , V_106 , V_83 ) ;
} else {
F_44 ( V_19 , V_3 , V_94 , V_83 ) ;
F_52 ( V_106 , V_83 ) ;
}
F_41 ( V_19 , V_3 ) ;
}
static int F_54 ( struct V_18 * V_19 , T_1 V_3 ,
int V_116 , int V_90 )
{
return F_21 ( V_19 , V_3 , 0 ,
V_117 ,
( V_90 << 4 ) | V_116 ) ;
}
static int F_55 ( struct V_18 * V_19 , T_1 V_3 ,
int V_116 )
{
return ( F_19 ( V_19 , V_3 , 0 ,
V_118 ,
V_116 ) & 0xf0 ) >> 4 ;
}
static void F_56 ( struct V_18 * V_19 ,
T_1 V_3 )
{
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_19 , V_3 , 0 , V_119 ,
V_120 ) ;
}
static void F_57 ( struct V_18 * V_19 ,
T_1 V_3 )
{
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_19 , V_3 , 0 , V_119 ,
V_121 ) ;
}
static void F_58 ( struct V_18 * V_19 , T_1 V_3 )
{
#ifdef F_42
int V_75 ;
int V_122 ;
V_122 = F_59 ( V_19 , V_3 ) ;
F_43 ( V_93 L_8 , V_122 ) ;
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
V_122 = F_19 ( V_19 , V_3 , 0 ,
V_123 , V_75 ) ;
F_43 ( V_93 L_9 , V_75 , V_122 ) ;
}
#endif
}
static void F_60 ( struct V_18 * V_19 , T_1 V_3 )
{
#ifdef F_61
int V_75 , V_76 ;
int V_122 ;
int V_124 , V_125 ;
for ( V_75 = 0 ; V_75 < 8 ; V_75 ++ ) {
V_122 = F_19 ( V_19 , V_3 , 0 ,
V_123 , V_75 ) ;
if ( V_122 == 0 )
continue;
F_20 ( V_19 , V_3 , V_75 , 0x0 ) ;
for ( V_76 = 1 ; V_76 < 1000 ; V_76 ++ ) {
F_22 ( V_19 , V_3 , 0x0 ) ;
F_18 ( V_19 , V_3 , & V_124 , & V_125 ) ;
if ( V_124 != V_75 )
F_62 ( V_126 L_10 ,
V_125 , V_124 , V_75 ) ;
if ( V_125 == 0 )
break;
}
F_62 ( V_126
L_11 ,
V_75 , V_122 , V_76 ) ;
}
#endif
}
static void F_63 ( struct V_127 * V_128 )
{
T_2 * V_34 = ( T_2 * ) V_128 ;
T_2 V_129 = 0 ;
int V_75 ;
V_128 -> V_130 = 0 ;
for ( V_75 = 0 ; V_75 < sizeof( * V_128 ) ; V_75 ++ )
V_129 += V_34 [ V_75 ] ;
V_128 -> V_130 = - V_129 ;
}
static void F_64 ( struct V_18 * V_19 ,
T_1 V_3 ,
T_2 * V_131 , int V_122 )
{
int V_75 ;
F_58 ( V_19 , V_3 ) ;
F_60 ( V_19 , V_3 ) ;
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
for ( V_75 = 0 ; V_75 < V_122 ; V_75 ++ )
F_22 ( V_19 , V_3 , V_131 [ V_75 ] ) ;
}
static bool F_65 ( struct V_18 * V_19 , T_1 V_3 ,
T_2 * V_131 , int V_122 )
{
T_2 V_46 ;
int V_75 ;
if ( F_19 ( V_19 , V_3 , 0 , V_132 , 0 )
!= V_120 )
return false ;
F_20 ( V_19 , V_3 , 0x0 , 0x0 ) ;
for ( V_75 = 0 ; V_75 < V_122 ; V_75 ++ ) {
V_46 = F_19 ( V_19 , V_3 , 0 ,
V_133 , 0 ) ;
if ( V_46 != V_131 [ V_75 ] )
return false ;
}
return true ;
}
static void F_66 ( struct V_18 * V_19 ,
T_1 V_3 ,
int V_83 , int V_134 ,
int V_135 )
{
union V_136 V_137 ;
if ( V_135 == 0 ) {
struct V_127 * V_128 = & V_137 . V_138 ;
V_128 -> type = 0x84 ;
V_128 -> V_139 = 0x01 ;
V_128 -> V_140 = 0x0a ;
V_128 -> V_141 = V_134 - 1 ;
V_128 -> V_142 = V_83 ;
F_63 ( V_128 ) ;
} else if ( V_135 == 1 ) {
struct V_143 * V_144 = & V_137 . V_145 ;
V_144 -> type = 0x84 ;
V_144 -> V_140 = 0x1b ;
V_144 -> V_139 = 0x11 << 2 ;
V_144 -> V_141 = V_134 - 1 ;
V_144 -> V_142 = V_83 ;
} else {
F_62 ( L_12 ,
V_3 ) ;
return;
}
if ( ! F_65 ( V_19 , V_3 , V_137 . V_34 ,
sizeof( V_137 ) ) ) {
F_40 ( L_13
L_14 ,
V_3 ,
V_134 , V_83 ) ;
F_57 ( V_19 , V_3 ) ;
F_64 ( V_19 , V_3 ,
V_137 . V_34 , sizeof( V_137 ) ) ;
F_56 ( V_19 , V_3 ) ;
}
}
static void F_67 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
bool V_94 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_3 = V_21 -> V_3 ;
int V_80 = V_21 -> V_80 ;
int V_134 ;
struct V_22 * V_23 ;
int V_83 , V_107 ;
if ( ! V_80 )
return;
if ( F_68 ( V_19 ) )
F_21 ( V_19 , V_3 , 0 ,
V_51 ,
V_52 ) ;
V_23 = & V_21 -> V_26 ;
if ( ! V_23 -> V_146 )
return;
if ( ! V_94 && V_21 -> V_115 )
V_83 = F_50 ( V_80 , V_21 -> V_147 ) ;
else
V_83 = F_38 ( V_23 , V_80 ) ;
if ( V_83 < 0 )
V_83 = 0 ;
V_107 = F_37 ( V_83 ) ;
V_134 = V_79 [ V_107 ] . V_80 ;
F_26 ( V_19 , V_21 -> V_11 , V_134 ) ;
F_53 ( V_19 , V_3 , V_94 , V_83 ,
V_80 , V_21 -> V_147 ,
V_21 -> V_115 ) ;
V_2 -> V_91 . V_148 ( V_19 , V_3 , V_83 , V_134 ,
V_23 -> V_88 . V_135 ) ;
V_21 -> V_94 = V_94 ;
}
static void F_69 ( struct V_18 * V_19 , struct V_149 * V_150 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = F_1 ( V_2 , V_150 -> V_151 ) ;
if ( V_4 < 0 )
return;
if ( F_70 ( F_2 ( V_2 , V_4 ) , 1 ) )
F_71 ( V_19 ) ;
}
static void F_72 ( struct V_18 * V_19 , unsigned int V_152 )
{
int V_153 = V_152 >> V_154 ;
struct V_149 * V_150 ;
int V_155 = ( V_152 & V_156 ) >> V_157 ;
V_150 = F_73 ( V_19 , V_153 ) ;
if ( ! V_150 )
return;
V_150 -> V_158 = 1 ;
F_74 ( V_159 ,
L_15 ,
V_19 -> V_65 , V_150 -> V_151 , V_155 , ! ! ( V_152 & V_160 ) ,
! ! ( V_152 & V_161 ) , ! ! ( V_152 & V_162 ) ) ;
F_69 ( V_19 , V_150 ) ;
}
static void F_75 ( struct V_18 * V_19 , unsigned int V_152 )
{
int V_153 = V_152 >> V_154 ;
int V_163 = ( V_152 & V_164 ) >> V_165 ;
int V_166 = ! ! ( V_152 & V_167 ) ;
int V_168 = ! ! ( V_152 & V_169 ) ;
F_43 ( V_126
L_16 ,
V_19 -> V_65 ,
V_153 ,
V_163 ,
V_166 ,
V_168 ) ;
if ( V_166 )
;
if ( V_168 )
;
}
static void F_76 ( struct V_18 * V_19 , unsigned int V_152 )
{
int V_153 = V_152 >> V_154 ;
int V_163 = ( V_152 & V_164 ) >> V_165 ;
if ( ! F_73 ( V_19 , V_153 ) ) {
F_62 ( V_126 L_17 , V_153 ) ;
return;
}
if ( V_163 == 0 )
F_72 ( V_19 , V_152 ) ;
else
F_75 ( V_19 , V_152 ) ;
}
static void F_77 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_151 )
{
int V_170 ;
if ( ! F_78 ( V_19 , V_11 , V_171 ) )
F_21 ( V_19 , V_11 , 0 , V_172 , V_171 ) ;
if ( ! F_78 ( V_19 , V_151 , V_171 ) ) {
F_21 ( V_19 , V_151 , 0 , V_172 ,
V_171 ) ;
F_79 ( 40 ) ;
V_170 = F_19 ( V_19 , V_151 , 0 , V_173 , 0 ) ;
V_170 = ( V_170 & V_174 ) >> V_175 ;
F_62 ( L_18 , V_151 , V_170 ) ;
}
}
static int F_80 ( struct V_18 * V_19 , T_1 V_3 ,
bool V_176 )
{
int V_177 , V_178 ;
if ( F_81 ( V_19 , V_3 ) & V_179 ) {
V_177 = F_19 ( V_19 , V_3 , 0 ,
V_180 , 0 ) ;
if ( V_177 < 0 )
return V_176 ? - V_7 : 0 ;
V_178 = V_177 & ~ V_181 ;
if ( V_176 )
V_178 |= V_182 ;
else
V_178 |= V_183 ;
F_40 ( L_19
L_20 ,
V_3 ,
V_177 == V_178 ? L_21 : L_22 ,
V_178 ) ;
if ( V_177 != V_178 )
F_21 ( V_19 , V_3 , 0 ,
V_53 ,
V_178 ) ;
} else if ( V_176 )
return - V_7 ;
return 0 ;
}
static int F_82 ( struct V_18 * V_19 , T_1 V_11 ,
T_1 V_3 , T_3 V_184 , int V_185 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_39 ;
if ( F_68 ( V_19 ) )
F_77 ( V_19 , V_11 , V_3 ) ;
V_39 = V_2 -> V_91 . V_186 ( V_19 , V_3 , F_83 ( V_185 ) ) ;
if ( V_39 ) {
F_40 ( L_23 ) ;
return V_39 ;
}
F_84 ( V_19 , V_11 , V_184 , 0 , V_185 ) ;
return 0 ;
}
static int F_85 ( struct V_18 * V_19 ,
int V_4 , int * V_187 , int * V_188 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 ;
struct V_189 * V_190 = NULL ;
int V_12 , V_191 = 0 ;
V_21 = F_2 ( V_2 , V_4 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_190 = F_7 ( V_2 , V_12 ) ;
if ( V_190 -> V_192 )
continue;
for ( V_191 = 0 ; V_191 < V_21 -> V_193 ; V_191 ++ )
if ( V_21 -> V_194 [ V_191 ] == V_190 -> V_11 )
break;
if ( V_191 == V_21 -> V_193 )
continue;
break;
}
if ( V_12 == V_2 -> V_13 )
return - V_195 ;
if ( V_187 )
* V_187 = V_12 ;
if ( V_188 )
* V_188 = V_191 ;
return 0 ;
}
static void F_86 ( struct V_18 * V_19 ,
T_1 V_3 , int V_191 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_151 , V_196 ;
int V_12 , V_197 ;
struct V_189 * V_190 ;
V_196 = V_19 -> V_198 + V_19 -> V_199 ;
for ( V_151 = V_19 -> V_198 ; V_151 < V_196 ; V_151 ++ ) {
unsigned int V_200 = F_24 ( V_19 , V_151 ) ;
unsigned int V_201 = F_87 ( V_200 ) ;
if ( V_201 != V_202 )
continue;
if ( V_151 == V_3 )
continue;
V_197 = F_19 ( V_19 , V_151 , 0 ,
V_203 , 0 ) ;
if ( V_197 != V_191 )
continue;
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_190 = F_7 ( V_2 , V_12 ) ;
if ( ! V_190 -> V_192 ) {
F_40 ( L_24 ,
V_12 , V_151 ) ;
F_88 ( V_19 , V_151 , 0 ,
V_204 ,
V_12 ) ;
break;
}
}
}
}
static int F_89 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_207 * V_208 = V_206 -> V_208 ;
int V_4 , V_12 , V_191 = 0 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_189 * V_190 = NULL ;
int V_39 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_90 ( V_4 < 0 ) )
return - V_7 ;
V_21 = F_2 ( V_2 , V_4 ) ;
V_23 = & V_21 -> V_26 ;
V_39 = F_85 ( V_19 , V_4 , & V_12 , & V_191 ) ;
if ( V_39 < 0 )
return V_39 ;
V_190 = F_7 ( V_2 , V_12 ) ;
V_190 -> V_192 = 1 ;
V_21 -> V_11 = V_190 -> V_11 ;
V_9 -> V_151 = V_190 -> V_11 ;
F_88 ( V_19 , V_21 -> V_3 , 0 ,
V_204 ,
V_191 ) ;
if ( F_68 ( V_19 ) || F_91 ( V_19 ) )
F_86 ( V_19 , V_21 -> V_3 , V_191 ) ;
F_92 ( V_19 , V_4 , V_190 -> V_11 ) ;
V_9 -> V_209 = V_190 -> V_209 ;
V_9 -> V_210 = V_190 -> V_210 ;
V_9 -> V_211 = V_190 -> V_211 ;
V_9 -> V_212 = V_190 -> V_212 ;
V_9 -> V_213 = V_190 -> V_213 ;
if ( ! V_214 && V_23 -> V_29 ) {
F_93 ( & V_23 -> V_88 , V_9 ) ;
if ( V_9 -> V_209 > V_9 -> V_210 ||
! V_9 -> V_211 || ! V_9 -> V_212 ) {
V_190 -> V_192 = 0 ;
V_9 -> V_151 = 0 ;
F_94 ( V_19 , V_4 ) ;
return - V_195 ;
}
}
V_208 -> V_215 . V_209 = V_9 -> V_209 ;
V_208 -> V_215 . V_210 = V_9 -> V_210 ;
V_208 -> V_215 . V_212 = V_9 -> V_212 ;
V_208 -> V_215 . V_211 = V_9 -> V_211 ;
F_95 ( V_206 -> V_208 , 0 ,
V_216 , 2 ) ;
return 0 ;
}
static int F_96 ( struct V_18 * V_19 , int V_4 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_21 -> V_3 ;
if ( ! ( F_24 ( V_19 , V_3 ) & V_217 ) ) {
F_3 ( V_6
L_25
L_26 ,
V_3 , F_24 ( V_19 , V_3 ) ) ;
return - V_7 ;
}
V_21 -> V_193 = F_97 ( V_19 , V_3 ,
V_21 -> V_194 ,
V_218 ) ;
return 0 ;
}
static bool F_70 ( struct V_20 * V_21 , int V_219 )
{
struct V_149 * V_150 ;
struct V_18 * V_19 = V_21 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_22 * V_23 = & V_2 -> V_220 ;
struct V_22 * V_221 = & V_21 -> V_26 ;
T_1 V_3 = V_21 -> V_3 ;
int V_222 = F_98 ( V_19 , V_3 ) ;
bool V_223 = false ;
bool V_224 = false ;
bool V_225 ;
F_10 ( & V_21 -> V_27 ) ;
V_221 -> V_146 = ! ! ( V_222 & V_226 ) ;
if ( V_221 -> V_146 )
V_23 -> V_29 = ! ! ( V_222 & V_227 ) ;
else
V_23 -> V_29 = false ;
F_74 ( V_159 ,
L_27 ,
V_19 -> V_65 , V_3 , V_221 -> V_146 , V_23 -> V_29 ) ;
if ( V_23 -> V_29 ) {
if ( V_2 -> V_91 . V_228 ( V_19 , V_3 , V_23 -> V_36 ,
& V_23 -> V_30 ) < 0 )
V_23 -> V_29 = false ;
else {
memset ( & V_23 -> V_88 , 0 , sizeof( struct V_229 ) ) ;
if ( F_99 ( & V_23 -> V_88 , V_23 -> V_36 ,
V_23 -> V_30 ) < 0 )
V_23 -> V_29 = false ;
}
if ( V_23 -> V_29 ) {
F_100 ( & V_23 -> V_88 ) ;
V_223 = true ;
}
else if ( V_219 ) {
F_101 ( V_19 -> V_66 -> V_230 ,
& V_21 -> V_231 ,
F_102 ( 300 ) ) ;
goto V_232;
}
}
if ( V_221 -> V_29 && ! V_23 -> V_29 ) {
V_223 = true ;
V_224 = true ;
}
if ( V_223 ) {
bool V_233 = V_221 -> V_29 ;
V_221 -> V_29 = V_23 -> V_29 ;
V_224 = V_221 -> V_30 != V_23 -> V_30 ||
memcmp ( V_221 -> V_36 , V_23 -> V_36 ,
V_23 -> V_30 ) != 0 ;
if ( V_224 )
memcpy ( V_221 -> V_36 , V_23 -> V_36 ,
V_23 -> V_30 ) ;
V_221 -> V_30 = V_23 -> V_30 ;
V_221 -> V_88 = V_23 -> V_88 ;
if ( V_23 -> V_29 && ! V_233 && V_21 -> V_234 )
F_67 ( V_19 , V_21 ,
V_21 -> V_94 ) ;
}
if ( V_224 )
F_103 ( V_19 -> V_66 -> V_67 ,
V_235 | V_236 ,
& V_21 -> V_43 -> V_42 ) ;
V_232:
V_225 = ! V_219 || ! V_221 -> V_146 || V_221 -> V_29 ;
V_150 = F_104 ( V_19 , V_3 ) ;
if ( V_150 )
V_150 -> V_237 = ! V_225 ;
F_11 ( & V_21 -> V_27 ) ;
return V_225 ;
}
static void F_105 ( struct V_238 * V_231 )
{
struct V_20 * V_21 =
F_106 ( F_107 ( V_231 ) , struct V_20 , V_231 ) ;
if ( V_21 -> V_239 ++ > 6 )
V_21 -> V_239 = 0 ;
if ( F_70 ( V_21 , V_21 -> V_239 ) )
F_71 ( V_21 -> V_19 ) ;
}
static int F_108 ( struct V_18 * V_19 , T_1 V_3 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_240 , V_241 ;
int V_4 ;
struct V_20 * V_21 ;
int V_39 ;
V_240 = F_81 ( V_19 , V_3 ) ;
if ( ! ( V_240 & ( V_242 | V_243 ) ) )
return 0 ;
V_241 = F_109 ( V_19 , V_3 ) ;
if ( F_110 ( V_241 ) == V_244 )
return 0 ;
if ( F_68 ( V_19 ) )
F_111 ( V_19 , V_3 ) ;
V_4 = V_2 -> V_5 ;
V_21 = F_112 ( & V_2 -> V_245 ) ;
if ( ! V_21 )
return - V_41 ;
V_21 -> V_3 = V_3 ;
V_21 -> V_94 = false ;
V_39 = F_96 ( V_19 , V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_113 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_189 * V_190 ;
unsigned int V_246 ;
int V_39 ;
V_246 = F_24 ( V_19 , V_11 ) ;
V_246 = F_114 ( V_246 ) ;
V_190 = F_112 ( & V_2 -> V_247 ) ;
if ( ! V_190 )
return - V_41 ;
V_190 -> V_11 = V_11 ;
V_190 -> V_209 = 2 ;
if ( V_246 <= 16 ) {
V_190 -> V_210 = V_246 ;
if ( V_246 > V_2 -> V_210 )
V_2 -> V_210 = V_246 ;
}
V_39 = F_115 ( V_19 , V_11 ,
& V_190 -> V_211 ,
& V_190 -> V_212 ,
& V_190 -> V_213 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_2 -> V_13 < F_13 ( V_2 -> V_248 ) )
V_2 -> V_248 [ V_2 -> V_13 ] = V_11 ;
V_2 -> V_13 ++ ;
return 0 ;
}
static int F_116 ( struct V_18 * V_19 )
{
T_1 V_151 ;
int V_75 , V_249 ;
V_249 = F_117 ( V_19 , V_19 -> V_250 , & V_151 ) ;
if ( ! V_151 || V_249 < 0 ) {
F_3 ( V_6 L_28 ) ;
return - V_7 ;
}
for ( V_75 = 0 ; V_75 < V_249 ; V_75 ++ , V_151 ++ ) {
unsigned int V_240 ;
unsigned int type ;
V_240 = F_24 ( V_19 , V_151 ) ;
type = F_87 ( V_240 ) ;
if ( ! ( V_240 & V_251 ) )
continue;
switch ( type ) {
case V_252 :
F_113 ( V_19 , V_151 ) ;
break;
case V_202 :
F_108 ( V_19 , V_151 ) ;
break;
}
}
#ifdef F_118
if ( V_19 -> V_253 == 0x80862806 )
V_19 -> V_66 -> V_254 = 1 ;
else if ( ! ( F_119 ( V_19 , V_19 -> V_250 , V_255 ) &
V_256 ) )
V_19 -> V_66 -> V_254 = 1 ;
#endif
return 0 ;
}
static bool F_120 ( struct V_18 * V_19 , T_1 V_11 )
{
struct V_257 * V_258 ;
bool V_94 ;
F_10 ( & V_19 -> V_259 ) ;
V_258 = F_121 ( V_19 , V_11 ) ;
V_94 = ! ! ( V_258 -> V_260 & V_261 ) ;
F_11 ( & V_19 -> V_259 ) ;
return V_94 ;
}
static int F_122 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_184 ,
unsigned int V_185 ,
struct V_205 * V_206 )
{
T_1 V_11 = V_9 -> V_151 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = F_4 ( V_2 , V_9 ) ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
T_1 V_3 = V_21 -> V_3 ;
bool V_94 ;
V_94 = F_120 ( V_19 , V_11 ) ;
F_10 ( & V_21 -> V_27 ) ;
V_21 -> V_80 = V_206 -> V_208 -> V_80 ;
V_21 -> V_234 = true ;
F_67 ( V_19 , V_21 , V_94 ) ;
F_11 ( & V_21 -> V_27 ) ;
return V_2 -> V_91 . V_262 ( V_19 , V_11 , V_3 , V_184 , V_185 ) ;
}
static int F_123 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_205 * V_206 )
{
F_124 ( V_19 , V_9 -> V_151 ) ;
return 0 ;
}
static int F_125 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_12 , V_4 ;
struct V_189 * V_190 ;
struct V_20 * V_21 ;
if ( V_9 -> V_151 ) {
V_12 = F_6 ( V_2 , V_9 -> V_151 ) ;
if ( F_90 ( V_12 < 0 ) )
return - V_7 ;
V_190 = F_7 ( V_2 , V_12 ) ;
F_90 ( ! V_190 -> V_192 ) ;
V_190 -> V_192 = 0 ;
V_9 -> V_151 = 0 ;
V_4 = F_4 ( V_2 , V_9 ) ;
if ( F_90 ( V_4 < 0 ) )
return - V_7 ;
V_21 = F_2 ( V_2 , V_4 ) ;
F_94 ( V_19 , V_4 ) ;
F_10 ( & V_21 -> V_27 ) ;
V_21 -> V_115 = false ;
memset ( V_21 -> V_147 , 0 , sizeof( V_21 -> V_147 ) ) ;
V_21 -> V_234 = false ;
V_21 -> V_80 = 0 ;
F_11 ( & V_21 -> V_27 ) ;
}
return 0 ;
}
static int F_126 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_263 * V_88 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_88 -> V_62 ;
struct V_1 * V_2 = V_19 -> V_2 ;
V_17 -> type = V_264 ;
V_17 -> V_28 = V_2 -> V_210 ;
V_17 -> V_33 . integer . V_265 = 0 ;
V_17 -> V_33 . integer . V_266 = V_267 ;
return 0 ;
}
static int F_127 ( struct V_77 * V_268 ,
int V_80 )
{
if ( V_268 -> V_80 != V_80 )
return - 1 ;
return V_269 ;
}
static void F_128 ( struct V_77 * V_268 ,
unsigned int * V_147 , int V_80 )
{
int V_28 = 0 ;
int V_68 ;
for ( V_68 = 7 ; V_68 >= 0 ; V_68 -- ) {
int V_110 = V_268 -> V_82 [ V_68 ] ;
if ( ! V_110 )
continue;
V_147 [ V_28 ++ ] = F_48 ( V_110 ) ;
}
F_45 ( V_28 != V_80 ) ;
}
static int F_129 ( struct V_14 * V_15 , int V_270 ,
unsigned int V_122 , unsigned int T_4 * V_271 )
{
struct V_263 * V_88 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_88 -> V_62 ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int T_4 * V_272 ;
int V_56 , V_28 = 0 ;
if ( V_122 < 8 )
return - V_41 ;
if ( F_130 ( V_273 , V_271 ) )
return - V_274 ;
V_122 -= 8 ;
V_272 = V_271 + 2 ;
for ( V_56 = 2 ; V_56 <= V_2 -> V_210 ; V_56 ++ ) {
int V_75 ;
struct V_77 * V_268 ;
V_268 = V_79 ;
for ( V_75 = 0 ; V_75 < F_13 ( V_79 ) ; V_75 ++ , V_268 ++ ) {
int V_275 = V_56 * 4 ;
int type = V_2 -> V_91 . V_276 ( V_268 , V_56 ) ;
unsigned int V_277 [ 8 ] ;
if ( type < 0 )
continue;
if ( V_122 < 8 )
return - V_41 ;
if ( F_130 ( type , V_272 ) ||
F_130 ( V_275 , V_272 + 1 ) )
return - V_274 ;
V_272 += 2 ;
V_122 -= 8 ;
V_28 += 8 ;
if ( V_122 < V_275 )
return - V_41 ;
V_122 -= V_275 ;
V_28 += V_275 ;
V_2 -> V_91 . V_278 ( V_268 , V_277 , V_56 ) ;
if ( F_131 ( V_272 , V_277 , V_275 ) )
return - V_274 ;
V_272 += V_56 ;
}
}
if ( F_130 ( V_28 , V_271 + 1 ) )
return - V_274 ;
return 0 ;
}
static int F_132 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_263 * V_88 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_88 -> V_62 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_25 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
int V_75 ;
for ( V_75 = 0 ; V_75 < F_13 ( V_21 -> V_147 ) ; V_75 ++ )
V_32 -> V_33 . integer . V_33 [ V_75 ] = V_21 -> V_147 [ V_75 ] ;
return 0 ;
}
static int F_133 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_263 * V_88 = F_9 ( V_15 ) ;
struct V_18 * V_19 = V_88 -> V_62 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 = V_15 -> V_25 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
unsigned int V_279 ;
struct V_205 * V_206 ;
unsigned char V_147 [ 8 ] ;
int V_75 , V_39 , V_83 , V_280 = 0 ;
V_279 = F_134 ( V_15 , & V_32 -> V_42 ) ;
V_206 = F_135 ( V_88 , V_279 ) ;
if ( ! V_206 || ! V_206 -> V_208 )
return 0 ;
switch ( V_206 -> V_208 -> V_260 -> V_281 ) {
case V_282 :
case V_283 :
break;
case V_284 :
V_280 = 1 ;
break;
default:
return - V_285 ;
}
memset ( V_147 , 0 , sizeof( V_147 ) ) ;
for ( V_75 = 0 ; V_75 < F_13 ( V_147 ) ; V_75 ++ )
V_147 [ V_75 ] = V_32 -> V_33 . integer . V_33 [ V_75 ] ;
if ( ! memcmp ( V_147 , V_21 -> V_147 , sizeof( V_147 ) ) )
return 0 ;
V_83 = F_50 ( F_13 ( V_147 ) , V_147 ) ;
if ( V_83 < 0 )
return - V_7 ;
if ( V_2 -> V_91 . V_286 ) {
V_39 = V_2 -> V_91 . V_286 ( V_83 , F_13 ( V_147 ) , V_147 ) ;
if ( V_39 )
return V_39 ;
}
F_10 ( & V_21 -> V_27 ) ;
V_21 -> V_115 = true ;
memcpy ( V_21 -> V_147 , V_147 , sizeof( V_147 ) ) ;
if ( V_280 )
F_67 ( V_19 , V_21 , V_21 -> V_94 ) ;
F_11 ( & V_21 -> V_27 ) ;
return 0 ;
}
static int F_136 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_287 * V_88 ;
struct V_8 * V_288 ;
struct V_20 * V_21 ;
V_21 = F_2 ( V_2 , V_4 ) ;
sprintf ( V_21 -> V_289 , L_29 , V_4 ) ;
V_88 = F_112 ( & V_2 -> V_290 ) ;
if ( ! V_88 )
return - V_41 ;
V_88 -> V_64 = V_21 -> V_289 ;
V_88 -> V_291 = V_292 ;
V_88 -> V_293 = true ;
V_288 = & V_88 -> V_10 [ V_294 ] ;
V_288 -> V_295 = 1 ;
V_288 -> V_91 = V_296 ;
}
V_19 -> V_297 = V_2 -> V_5 ;
V_19 -> V_298 = V_2 -> V_290 . V_299 ;
return 0 ;
}
static int F_137 ( struct V_18 * V_19 , int V_4 )
{
char V_300 [ 32 ] = L_30 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
int V_301 = F_5 ( V_2 , V_4 ) -> V_37 ;
if ( V_301 > 0 )
sprintf ( V_300 + strlen ( V_300 ) , L_31 , V_301 ) ;
if ( ! F_138 ( V_19 , V_21 -> V_3 ) )
strncat ( V_300 , L_32 ,
sizeof( V_300 ) - strlen ( V_300 ) - 1 ) ;
return F_139 ( V_19 , V_21 -> V_3 , V_300 , 0 ) ;
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
V_21 -> V_194 [ 0 ] ,
V_292 ) ;
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
struct V_263 * V_147 ;
struct V_14 * V_38 ;
int V_75 ;
if ( ! V_19 -> V_298 [ V_4 ] . V_302 )
break;
V_39 = F_142 ( V_19 -> V_298 [ V_4 ] . V_302 ,
V_294 ,
NULL , 0 , V_4 , & V_147 ) ;
if ( V_39 < 0 )
return V_39 ;
V_147 -> V_62 = V_19 ;
V_38 = V_147 -> V_38 ;
for ( V_75 = 0 ; V_75 < V_38 -> V_28 ; V_75 ++ )
V_38 -> V_303 [ V_75 ] . V_304 |= V_305 ;
V_38 -> V_88 = F_126 ;
V_38 -> V_306 = F_132 ;
V_38 -> V_307 = F_133 ;
V_38 -> V_271 . V_68 = F_129 ;
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
F_145 ( & V_21 -> V_231 , F_105 ) ;
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
V_19 -> V_308 > 0 ? F_69 : NULL ) ;
}
return 0 ;
}
static void F_148 ( struct V_1 * V_2 , int V_309 )
{
F_149 ( & V_2 -> V_245 , sizeof( struct V_20 ) , V_309 ) ;
F_149 ( & V_2 -> V_247 , sizeof( struct V_189 ) , V_309 ) ;
F_149 ( & V_2 -> V_290 , sizeof( struct V_287 ) , V_309 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
F_151 ( & V_2 -> V_245 ) ;
F_151 ( & V_2 -> V_247 ) ;
F_151 ( & V_2 -> V_290 ) ;
}
static void F_152 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
F_153 ( & V_21 -> V_231 ) ;
F_34 ( V_21 ) ;
}
F_154 ( V_19 -> V_66 -> V_230 ) ;
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
static void F_111 ( struct V_18 * V_19 ,
T_1 V_151 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_310 [ 4 ] ;
int V_311 ;
V_311 = F_97 ( V_19 , V_151 , V_310 , F_13 ( V_310 ) ) ;
if ( V_311 == V_2 -> V_13 &&
! memcmp ( V_310 , V_2 -> V_248 , V_2 -> V_13 * sizeof( T_1 ) ) )
return;
F_40 ( L_33 , V_151 ) ;
F_159 ( V_19 , V_151 , V_2 -> V_13 , V_2 -> V_248 ) ;
}
static void F_160 ( struct V_18 * V_19 ,
bool V_312 )
{
unsigned int V_313 ;
V_313 = F_19 ( V_19 , V_314 , 0 ,
V_315 , 0 ) ;
if ( V_313 == - 1 || V_313 & V_316 )
return;
V_313 |= V_316 ;
V_313 = F_19 ( V_19 , V_314 , 0 ,
V_317 , V_313 ) ;
if ( V_313 == - 1 )
return;
if ( V_312 )
F_161 ( V_19 ) ;
}
static void F_162 ( struct V_18 * V_19 )
{
unsigned int V_313 ;
V_313 = F_19 ( V_19 , V_314 , 0 ,
V_315 , 0 ) ;
if ( V_313 == - 1 || V_313 & V_318 )
return;
V_313 |= V_318 ;
F_88 ( V_19 , V_314 , 0 ,
V_317 , V_313 ) ;
}
static void F_163 ( struct V_18 * V_19 , T_1 V_319 ,
unsigned int V_320 )
{
if ( V_320 == V_171 ) {
F_160 ( V_19 , false ) ;
F_162 ( V_19 ) ;
}
F_19 ( V_19 , V_319 , 0 , V_172 , V_320 ) ;
F_164 ( V_19 , V_319 , V_320 ) ;
}
static int F_165 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_166 ( sizeof( * V_2 ) , V_321 ) ;
if ( V_2 == NULL )
return - V_41 ;
V_2 -> V_91 = V_322 ;
V_19 -> V_2 = V_2 ;
F_148 ( V_2 , 4 ) ;
if ( F_68 ( V_19 ) ) {
F_160 ( V_19 , true ) ;
F_162 ( V_19 ) ;
}
if ( F_116 ( V_19 ) < 0 ) {
V_19 -> V_2 = NULL ;
F_155 ( V_2 ) ;
return - V_7 ;
}
V_19 -> V_323 = V_324 ;
if ( F_68 ( V_19 ) ) {
V_19 -> V_323 . V_325 = F_163 ;
V_19 -> V_326 = true ;
}
F_143 ( V_19 ) ;
F_36 () ;
return 0 ;
}
static int F_167 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_287 * V_88 ;
unsigned int V_246 ;
struct V_8 * V_288 ;
struct V_189 * V_190 ;
V_190 = F_7 ( V_2 , 0 ) ;
V_246 = F_24 ( V_19 , V_190 -> V_11 ) ;
V_246 = F_114 ( V_246 ) ;
V_88 = F_112 ( & V_2 -> V_290 ) ;
if ( ! V_88 )
return - V_41 ;
V_88 -> V_64 = F_2 ( V_2 , 0 ) -> V_289 ;
sprintf ( V_88 -> V_64 , L_34 ) ;
V_88 -> V_291 = V_292 ;
V_288 = & V_88 -> V_10 [ V_294 ] ;
* V_288 = V_2 -> V_327 ;
V_288 -> V_151 = V_190 -> V_11 ;
if ( V_288 -> V_210 <= 2 && V_246 && V_246 <= 16 )
V_288 -> V_210 = V_246 ;
V_19 -> V_297 = 1 ;
V_19 -> V_298 = V_88 ;
return 0 ;
}
static void F_168 ( struct V_18 * V_19 ,
unsigned int V_152 )
{
F_169 ( V_19 ) ;
F_71 ( V_19 ) ;
}
static int F_170 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_189 * V_190 ;
int V_39 ;
V_190 = F_7 ( V_2 , 0 ) ;
V_39 = F_141 ( V_19 , V_190 -> V_11 ,
V_190 -> V_11 ,
V_292 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_171 ( V_19 , 0 ) ;
}
static int F_172 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_20 * V_21 = F_2 ( V_2 , 0 ) ;
T_1 V_328 = V_21 -> V_3 ;
F_21 ( V_19 , V_328 , 0 ,
V_53 , V_54 ) ;
if ( F_24 ( V_19 , V_328 ) & V_50 )
F_21 ( V_19 , V_328 , 0 , V_51 ,
V_52 ) ;
F_173 ( V_19 , V_328 , V_328 ) ;
return 0 ;
}
static void F_174 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_150 ( V_2 ) ;
F_155 ( V_2 ) ;
}
static int F_175 ( struct V_18 * V_19 )
{
F_176 ( V_19 , V_329 ) ;
return 0 ;
}
static int F_177 ( struct V_18 * V_19 )
{
F_176 ( V_19 , V_330 ) ;
return 0 ;
}
static int F_178 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_331 * V_332 = NULL ;
switch ( V_19 -> V_333 -> V_42 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_332 = & V_334 ;
break;
case 0x10de0007 :
V_332 = & V_335 ;
break;
default:
break;
}
if ( V_332 != NULL ) {
V_331 ( V_206 -> V_208 , 0 ,
V_216 ,
V_332 ) ;
} else {
F_95 ( V_206 -> V_208 , 0 ,
V_216 , 2 ) ;
}
return F_179 ( V_19 , & V_2 -> V_336 ) ;
}
static int F_180 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_181 ( V_19 , & V_2 -> V_336 ) ;
}
static int F_182 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_184 ,
unsigned int V_185 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
return F_183 ( V_19 , & V_2 -> V_336 ,
V_184 , V_185 , V_206 ) ;
}
static int F_184 ( struct V_18 * V_19 ,
T_1 V_11 , T_1 V_3 )
{
struct V_1 * V_2 ;
struct V_189 * V_190 ;
struct V_20 * V_21 ;
V_2 = F_166 ( sizeof( * V_2 ) , V_321 ) ;
if ( ! V_2 )
return - V_41 ;
V_19 -> V_2 = V_2 ;
F_148 ( V_2 , 1 ) ;
V_2 -> V_336 . V_337 = 0 ;
V_2 -> V_336 . V_338 = 2 ;
V_2 -> V_336 . V_339 = V_11 ;
V_2 -> V_13 = 1 ;
V_2 -> V_5 = 1 ;
V_21 = F_112 ( & V_2 -> V_245 ) ;
V_190 = F_112 ( & V_2 -> V_247 ) ;
if ( ! V_21 || ! V_190 ) {
F_174 ( V_19 ) ;
return - V_41 ;
}
V_190 -> V_11 = V_11 ;
V_21 -> V_3 = V_3 ;
V_2 -> V_327 = V_340 ;
V_19 -> V_323 = V_341 ;
return 0 ;
}
static void F_185 ( struct V_18 * V_19 ,
int V_80 )
{
unsigned int V_342 ;
int V_343 = V_80 ? ( V_80 - 1 ) : 1 ;
switch ( V_80 ) {
default:
case 0 :
case 2 :
V_342 = 0x00 ;
break;
case 4 :
V_342 = 0x08 ;
break;
case 6 :
V_342 = 0x0b ;
break;
case 8 :
V_342 = 0x13 ;
break;
}
F_21 ( V_19 , 0x1 , 0 ,
V_344 , V_342 ) ;
F_21 ( V_19 , 0x1 , 0 ,
V_345 ,
( 0x71 - V_343 - V_342 ) ) ;
}
static int F_186 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_75 ;
F_21 ( V_19 , V_346 ,
0 , V_347 , 0 ) ;
for ( V_75 = 0 ; V_75 < 4 ; V_75 ++ ) {
F_21 ( V_19 , V_348 [ V_75 ] , 0 ,
V_347 , 0 ) ;
F_21 ( V_19 , V_348 [ V_75 ] , 0 ,
V_349 , 0 ) ;
}
F_185 ( V_19 , 8 ) ;
return F_181 ( V_19 , & V_2 -> V_336 ) ;
}
static int F_187 ( struct V_8 * V_9 ,
struct V_18 * V_19 ,
unsigned int V_184 ,
unsigned int V_185 ,
struct V_205 * V_206 )
{
int V_56 ;
unsigned int V_350 , V_351 ;
int V_75 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_257 * V_258 ;
struct V_189 * V_190 ;
F_10 ( & V_19 -> V_259 ) ;
V_190 = F_7 ( V_2 , 0 ) ;
V_258 = F_121 ( V_19 , V_190 -> V_11 ) ;
V_56 = V_206 -> V_208 -> V_80 ;
V_350 = 0x2 ;
if ( V_19 -> V_352 && ( V_258 -> V_353 & V_354 ) )
F_21 ( V_19 ,
V_346 ,
0 ,
V_355 ,
V_258 -> V_353 & ~ V_354 & 0xff ) ;
F_21 ( V_19 , V_346 , 0 ,
V_347 , ( V_184 << 4 ) | 0x0 ) ;
F_21 ( V_19 , V_346 , 0 ,
V_349 , V_185 ) ;
if ( V_19 -> V_352 && ( V_258 -> V_353 & V_354 ) ) {
F_21 ( V_19 ,
V_346 ,
0 ,
V_355 ,
V_258 -> V_353 & 0xff ) ;
F_21 ( V_19 ,
V_346 ,
0 ,
V_356 , V_350 ) ;
}
for ( V_75 = 0 ; V_75 < 4 ; V_75 ++ ) {
if ( V_56 == 2 )
V_351 = 0 ;
else
V_351 = V_75 * 2 ;
if ( V_19 -> V_352 &&
( V_258 -> V_353 & V_354 ) )
F_21 ( V_19 ,
V_348 [ V_75 ] ,
0 ,
V_355 ,
V_258 -> V_353 & ~ V_354 & 0xff ) ;
F_21 ( V_19 ,
V_348 [ V_75 ] ,
0 ,
V_347 ,
( V_184 << 4 ) | V_351 ) ;
F_21 ( V_19 ,
V_348 [ V_75 ] ,
0 ,
V_349 ,
V_185 ) ;
if ( V_19 -> V_352 &&
( V_258 -> V_353 & V_354 ) ) {
F_21 ( V_19 ,
V_348 [ V_75 ] ,
0 ,
V_355 ,
V_258 -> V_353 & 0xff ) ;
F_21 ( V_19 ,
V_348 [ V_75 ] ,
0 ,
V_356 , V_350 ) ;
}
}
F_185 ( V_19 , V_56 ) ;
F_11 ( & V_19 -> V_259 ) ;
return 0 ;
}
static int F_188 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_39 = F_184 ( V_19 , V_346 ,
V_357 ) ;
if ( V_39 < 0 )
return V_39 ;
V_19 -> V_323 . V_358 = F_175 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_327 . V_211 = V_359 ;
V_2 -> V_327 . V_213 = V_360 ;
V_2 -> V_327 . V_212 = V_361 ;
return 0 ;
}
static int F_189 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_39 = F_167 ( V_19 ) ;
if ( ! V_39 ) {
struct V_287 * V_88 = F_5 ( V_2 , 0 ) ;
V_88 -> V_293 = true ;
}
return V_39 ;
}
static int F_190 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_287 * V_88 ;
struct V_263 * V_147 ;
int V_39 ;
V_39 = F_170 ( V_19 ) ;
if ( V_39 < 0 )
return V_39 ;
V_88 = F_5 ( V_2 , 0 ) ;
V_39 = F_142 ( V_88 -> V_302 ,
V_294 ,
V_362 , 8 , 0 , & V_147 ) ;
if ( V_39 < 0 )
return V_39 ;
switch ( V_19 -> V_333 -> V_42 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_147 -> V_363 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_147 -> V_363 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_39 = F_188 ( V_19 ) ;
if ( V_39 < 0 )
return V_39 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_336 . V_338 = 8 ;
V_2 -> V_327 = V_364 ;
V_19 -> V_323 . V_358 = F_177 ;
V_19 -> V_323 . V_365 = F_189 ;
V_19 -> V_323 . V_366 = F_190 ;
F_185 ( V_19 , 8 ) ;
return 0 ;
}
static int F_192 ( struct V_77 * V_268 ,
int V_80 )
{
if ( V_268 -> V_84 == 0x00 && V_80 == 2 )
return V_367 ;
return F_127 ( V_268 , V_80 ) ;
}
static int F_193 ( int V_83 , int V_56 , unsigned char * V_106 )
{
if ( V_83 == 0x00 && ( V_106 [ 0 ] != V_368 || V_106 [ 1 ] != V_369 ) )
return - V_7 ;
return 0 ;
}
static int F_194 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_39 ;
V_39 = F_165 ( V_19 ) ;
if ( V_39 )
return V_39 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_91 . V_276 =
F_192 ;
V_2 -> V_91 . V_286 = F_193 ;
return 0 ;
}
static int F_195 ( struct V_18 * V_19 , T_1 V_151 ,
unsigned char * V_85 , int * V_30 )
{
return F_196 ( V_19 , V_151 , V_85 , V_30 ,
F_197 ( V_19 ) ) ;
}
static void F_198 ( struct V_18 * V_19 , T_1 V_3 , int V_83 ,
int V_134 , int V_135 )
{
F_21 ( V_19 , V_3 , 0 , V_370 , V_83 ) ;
}
static int F_199 ( int V_108 )
{
switch ( V_108 ) {
case 2 : return 3 ;
case 3 : return 2 ;
default: break;
}
return V_108 ;
}
static int F_200 ( int V_83 , int V_56 , unsigned char * V_106 )
{
struct V_77 * V_268 ;
int V_75 , V_76 ;
V_268 = & V_79 [ F_37 ( V_83 ) ] ;
for ( V_75 = 0 ; V_75 < V_56 ; ++ V_75 ) {
int V_109 = F_46 ( V_106 [ V_75 ] ) ;
bool V_371 = false ;
bool V_372 = false ;
if ( ! V_109 )
continue;
for ( V_76 = 0 + V_75 % 2 ; V_76 < 8 ; V_76 += 2 ) {
int V_373 = 7 - F_199 ( V_76 ) ;
if ( V_268 -> V_82 [ V_373 ] == V_109 ) {
V_371 = true ;
if ( V_75 % 2 == 0 && V_75 + 1 < V_56 ) {
int V_374 = 7 - F_199 ( V_76 + 1 ) ;
int V_375 = F_46 ( V_106 [ V_75 + 1 ] ) ;
int V_376 = V_268 -> V_82 [ V_374 ] ;
if ( V_375 == V_376 )
V_372 = true ;
else
return - V_7 ;
}
break;
}
}
if ( ! V_371 )
return - V_7 ;
if ( V_372 )
V_75 ++ ;
}
return 0 ;
}
static int F_201 ( struct V_18 * V_19 , T_1 V_3 ,
int V_99 , int V_377 )
{
int V_378 ;
int V_379 = 0 ;
if ( V_99 > 7 )
return - V_7 ;
if ( ! F_202 ( V_19 ) ) {
V_99 = F_199 ( V_99 ) ;
if ( V_99 % 2 != 0 && V_377 == 0xf )
return 0 ;
V_99 -= V_99 % 2 ;
if ( V_377 != 0xf )
V_377 -= V_377 % 2 ;
}
V_378 = V_380 + V_99 / 2 + ( V_99 % 2 ) * 0x00e ;
if ( V_377 != 0xf )
V_379 = ( V_377 << 4 ) | V_381 ;
return F_21 ( V_19 , V_3 , 0 , V_378 , V_379 ) ;
}
static int F_203 ( struct V_18 * V_19 , T_1 V_3 ,
int V_116 )
{
bool V_382 = false ;
int V_383 = V_116 ;
int V_378 ;
int V_379 ;
if ( V_116 > 7 )
return - V_7 ;
if ( ! F_202 ( V_19 ) ) {
V_383 = F_199 ( V_116 ) ;
if ( V_383 % 2 != 0 ) {
V_383 -= 1 ;
V_382 = true ;
}
}
V_378 = V_384 + V_383 / 2 + ( V_383 % 2 ) * 0x00e ;
V_379 = F_19 ( V_19 , V_3 , 0 , V_378 , 0 ) ;
if ( ! ( V_379 & V_381 ) )
return 0xf ;
return ( ( V_379 & 0xf0 ) >> 4 ) + ! ! V_382 ;
}
static int F_204 ( struct V_77 * V_268 ,
int V_80 )
{
int V_68 ;
int V_385 = 0 ;
if ( ( V_80 % 2 ) != 0 )
return - 1 ;
for ( V_68 = 0 ; V_68 < 7 ; V_68 += 2 ) {
if ( V_268 -> V_82 [ V_68 ] || V_268 -> V_82 [ V_68 + 1 ] )
V_385 ++ ;
}
if ( V_385 * 2 != V_80 )
return - 1 ;
return V_386 ;
}
static void F_205 ( struct V_77 * V_268 ,
unsigned int * V_147 , int V_80 )
{
int V_28 = 0 ;
int V_68 ;
for ( V_68 = 7 ; V_68 >= 0 ; V_68 -- ) {
int V_343 = 7 - F_199 ( 7 - V_68 ) ;
int V_110 = V_268 -> V_82 [ V_343 ] ;
if ( ! V_110 ) {
if ( V_268 -> V_82 [ V_343 + ( V_343 % 2 ? - 1 : 1 ) ] )
V_147 [ V_28 ++ ] = V_387 ;
continue;
}
V_147 [ V_28 ++ ] = F_48 ( V_110 ) ;
}
F_45 ( V_28 != V_80 ) ;
}
static int F_206 ( struct V_18 * V_19 , T_1 V_3 ,
bool V_176 )
{
int V_388 , V_389 ;
V_388 = F_19 ( V_19 , V_3 , 0 , V_390 , 0 ) ;
if ( V_388 >= 0 && ( V_388 & V_391 ) ) {
if ( V_176 )
V_389 = V_388 | V_392 ;
else
V_389 = V_388 & ~ V_392 ;
F_40 ( L_35
L_36 ,
V_3 ,
V_388 == V_389 ? L_21 : L_22 ,
V_389 ) ;
if ( V_388 != V_389 )
F_21 ( V_19 , V_3 , 0 ,
V_393 ,
V_389 ) ;
} else if ( V_176 )
return - V_7 ;
return 0 ;
}
static int F_207 ( struct V_18 * V_19 , T_1 V_11 ,
T_1 V_3 , T_3 V_184 , int V_185 )
{
if ( F_197 ( V_19 ) ) {
int V_394 = 180 ;
if ( V_185 & V_395 )
V_394 = 0 ;
F_21 ( V_19 , V_11 , 0 , V_396 , V_394 ) ;
}
return F_82 ( V_19 , V_11 , V_3 , V_184 , V_185 ) ;
}
static int F_208 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_4 , V_39 ;
V_39 = F_146 ( V_19 ) ;
if ( V_39 )
return V_39 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_20 * V_21 = F_2 ( V_2 , V_4 ) ;
F_21 ( V_19 , V_21 -> V_3 , 0 , V_397 , 0 ) ;
if ( F_202 ( V_19 ) )
F_21 ( V_19 , V_21 -> V_3 , 0 ,
V_398 ,
V_399 ) ;
}
return 0 ;
}
static int F_209 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_189 * V_190 ;
int V_39 , V_12 ;
V_39 = F_165 ( V_19 ) ;
if ( V_39 )
return V_39 ;
V_19 -> V_323 . V_358 = F_208 ;
V_2 = V_19 -> V_2 ;
V_2 -> V_91 . V_228 = F_195 ;
V_2 -> V_91 . V_92 = F_203 ;
V_2 -> V_91 . V_101 = F_201 ;
V_2 -> V_91 . V_148 = F_198 ;
V_2 -> V_91 . V_186 = F_206 ;
V_2 -> V_91 . V_262 = F_207 ;
if ( ! F_202 ( V_19 ) ) {
V_2 -> V_91 . V_276 =
F_204 ;
V_2 -> V_91 . V_278 = F_205 ;
V_2 -> V_91 . V_286 = F_200 ;
}
for ( V_12 = 0 ; V_12 < V_2 -> V_13 ; V_12 ++ ) {
V_190 = F_7 ( V_2 , V_12 ) ;
V_190 -> V_210 = V_266 ( V_190 -> V_210 , 8u ) ;
V_190 -> V_211 |= V_359 ;
V_190 -> V_212 |= V_361 ;
V_190 -> V_213 = V_266 ( V_190 -> V_213 , 24u ) ;
}
V_2 -> V_210 = V_266 ( V_2 -> V_210 , 8u ) ;
return 0 ;
}
static int F_210 ( struct V_18 * V_19 )
{
return F_184 ( V_19 , V_400 , V_401 ) ;
}
static int T_5 F_211 ( void )
{
return F_212 ( & V_402 ) ;
}
static void T_6 F_213 ( void )
{
F_214 ( & V_402 ) ;
}
