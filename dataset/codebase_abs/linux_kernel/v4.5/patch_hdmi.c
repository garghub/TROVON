static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ )
if ( F_2 ( V_5 , V_6 ) -> V_3 == V_3 )
return V_6 ;
F_3 ( V_2 , L_1 , V_3 ) ;
return - V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ )
if ( F_5 ( V_5 , V_6 ) -> V_11 == V_10 )
return V_6 ;
F_3 ( V_2 , L_2 , V_10 ) ;
return - V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ )
if ( F_7 ( V_5 , V_13 ) -> V_12 == V_12 )
return V_13 ;
F_3 ( V_2 , L_3 , V_12 ) ;
return - V_8 ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_6 ;
V_18 -> type = V_23 ;
V_6 = V_16 -> V_24 ;
V_20 = F_2 ( V_5 , V_6 ) ;
V_22 = & V_20 -> V_25 ;
F_10 ( & V_20 -> V_26 ) ;
V_18 -> V_27 = V_22 -> V_28 ? V_22 -> V_29 : 0 ;
F_11 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_6 ;
V_6 = V_16 -> V_24 ;
V_20 = F_2 ( V_5 , V_6 ) ;
V_22 = & V_20 -> V_25 ;
F_10 ( & V_20 -> V_26 ) ;
if ( V_22 -> V_29 > F_13 ( V_31 -> V_32 . V_33 . V_34 ) ||
V_22 -> V_29 > V_35 ) {
F_11 ( & V_20 -> V_26 ) ;
F_14 () ;
return - V_8 ;
}
memset ( V_31 -> V_32 . V_33 . V_34 , 0 ,
F_13 ( V_31 -> V_32 . V_33 . V_34 ) ) ;
if ( V_22 -> V_28 )
memcpy ( V_31 -> V_32 . V_33 . V_34 , V_22 -> V_36 ,
V_22 -> V_29 ) ;
F_11 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_6 ,
int V_37 )
{
struct V_15 * V_38 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_39 ;
V_38 = F_16 ( & V_40 , V_2 ) ;
if ( ! V_38 )
return - V_41 ;
V_38 -> V_24 = V_6 ;
V_38 -> V_42 . V_37 = V_37 ;
V_39 = F_17 ( V_2 , F_2 ( V_5 , V_6 ) -> V_3 , V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
F_2 ( V_5 , V_6 ) -> V_43 = V_38 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_3 ,
int * V_44 , int * V_45 )
{
int V_46 ;
V_46 = F_19 ( V_2 , V_3 , 0 ,
V_47 , 0 ) ;
* V_44 = V_46 >> 5 ;
* V_45 = V_46 & 0x1f ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_3 ,
int V_44 , int V_45 )
{
int V_46 ;
V_46 = ( V_44 << 5 ) | ( V_45 & 0x1f ) ;
F_21 ( V_2 , V_3 , 0 , V_48 , V_46 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_46 )
{
F_21 ( V_2 , V_3 , 0 , V_49 , V_46 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_50 ;
if ( F_24 ( V_2 , V_3 ) & V_51 )
F_21 ( V_2 , V_3 , 0 ,
V_52 , V_53 ) ;
if ( V_5 -> V_54 )
V_50 = 0 ;
else
V_50 = V_55 ;
F_21 ( V_2 , V_3 , 0 ,
V_56 , V_50 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_12 )
{
return 1 + F_19 ( V_2 , V_12 , 0 ,
V_57 , 0 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_1 V_12 , int V_58 )
{
if ( V_58 != F_25 ( V_2 , V_12 ) )
F_21 ( V_2 , V_12 , 0 ,
V_59 , V_58 - 1 ) ;
}
static void F_27 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_19 * V_20 = V_61 -> V_64 ;
F_10 ( & V_20 -> V_26 ) ;
F_28 ( & V_20 -> V_25 , V_63 ) ;
F_11 ( & V_20 -> V_26 ) ;
}
static void F_29 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_19 * V_20 = V_61 -> V_64 ;
F_10 ( & V_20 -> V_26 ) ;
F_30 ( & V_20 -> V_25 , V_63 ) ;
F_11 ( & V_20 -> V_26 ) ;
}
static int F_31 ( struct V_19 * V_20 , int V_65 )
{
char V_66 [ 32 ] ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_60 * V_61 ;
int V_39 ;
snprintf ( V_66 , sizeof( V_66 ) , L_4 , V_2 -> V_67 , V_65 ) ;
V_39 = F_32 ( V_2 -> V_68 , V_66 , & V_61 ) ;
if ( V_39 < 0 )
return V_39 ;
F_33 ( V_61 , V_20 , F_27 ) ;
V_61 -> V_69 . V_70 . V_71 = F_29 ;
V_61 -> V_72 |= V_73 ;
V_20 -> V_74 = V_61 ;
return 0 ;
}
static void F_34 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_2 -> V_75 -> V_76 ) {
F_35 ( V_20 -> V_74 ) ;
V_20 -> V_74 = NULL ;
}
}
static inline int F_31 ( struct V_19 * V_20 ,
int V_65 )
{
return 0 ;
}
static inline void F_34 ( struct V_19 * V_20 )
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
static int F_38 ( struct V_1 * V_2 ,
struct V_21 * V_22 , int V_82 )
{
int V_77 ;
int V_85 = 0 ;
int V_83 = 0 ;
char V_87 [ V_88 ] ;
if ( V_82 <= 2 )
return 0 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_89 ) ; V_77 ++ ) {
if ( V_22 -> V_90 . V_91 & ( 1 << V_77 ) )
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
F_39 ( V_22 -> V_90 . V_91 , V_87 , sizeof( V_87 ) ) ;
F_40 ( V_2 , L_5 ,
V_85 , V_82 , V_87 ) ;
return V_85 ;
}
static void F_41 ( struct V_1 * V_2 ,
T_1 V_3 )
{
#ifdef F_42
struct V_4 * V_5 = V_2 -> V_5 ;
int V_77 ;
int V_92 ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_92 = V_5 -> V_93 . V_94 ( V_2 , V_3 , V_77 ) ;
F_40 ( V_2 , L_6 ,
V_92 , V_77 ) ;
}
#endif
}
static void F_43 ( struct V_1 * V_2 ,
T_1 V_3 ,
bool V_95 ,
int V_85 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_79 * V_96 ;
int V_77 ;
int V_39 ;
int V_97 ;
int V_98 [ 8 ] ;
V_97 = F_37 ( V_85 ) ;
V_96 = & V_81 [ V_97 ] ;
if ( V_99 [ V_85 ] [ 1 ] == 0 ) {
int V_100 = 0 ;
for ( V_77 = 0 ; V_77 < V_96 -> V_82 ; V_77 ++ ) {
while ( ! V_96 -> V_84 [ 7 - V_100 ] && ! F_44 ( V_100 >= 8 ) )
V_100 ++ ;
V_99 [ V_85 ] [ V_77 ] = ( V_77 << 4 ) | V_100 ++ ;
}
for ( V_100 = 0 ; V_100 < 8 ; V_100 ++ )
if ( ! V_96 -> V_84 [ 7 - V_100 ] )
V_99 [ V_85 ] [ V_77 ++ ] = ( 0xf << 4 ) | V_100 ;
}
if ( V_95 ) {
for ( V_77 = 0 ; V_77 < V_96 -> V_82 ; V_77 ++ )
V_98 [ V_77 ] = ( V_77 << 4 ) | V_77 ;
for (; V_77 < 8 ; V_77 ++ )
V_98 [ V_77 ] = ( 0xf << 4 ) | V_77 ;
}
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
int V_101 = V_95 ? V_98 [ V_77 ] : V_99 [ V_85 ] [ V_77 ] ;
int V_100 = V_101 & 0x0f ;
int V_92 = ( V_101 & 0xf0 ) >> 4 ;
V_39 = V_5 -> V_93 . V_102 ( V_2 , V_3 , V_100 , V_92 ) ;
if ( V_39 ) {
F_40 ( V_2 , L_7 ) ;
break;
}
}
}
static int F_45 ( unsigned char V_69 )
{
struct V_103 * V_104 = V_105 ;
for (; V_104 -> V_106 ; V_104 ++ ) {
if ( V_104 -> V_106 == V_69 )
return V_104 -> V_83 ;
}
return 0 ;
}
static int F_46 ( int V_107 , unsigned char V_108 )
{
int V_109 = F_45 ( V_108 ) ;
int V_77 ;
if ( V_109 ) {
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
if ( V_81 [ V_107 ] . V_84 [ 7 - V_77 ] == V_109 )
return V_77 ;
}
}
return - 1 ;
}
static int F_47 ( int V_110 )
{
struct V_103 * V_104 = V_105 ;
for (; V_104 -> V_106 ; V_104 ++ ) {
if ( V_104 -> V_83 == V_110 )
return V_104 -> V_106 ;
}
return 0 ;
}
static int F_48 ( int V_107 , unsigned char V_111 )
{
int V_109 = V_81 [ V_107 ] . V_84 [ 7 - V_111 ] ;
return F_47 ( V_109 ) ;
}
static int F_49 ( int V_58 , unsigned char * V_106 )
{
int V_77 , V_112 = 0 , V_83 = 0 ;
for ( V_77 = 0 ; V_77 < V_58 ; V_77 ++ ) {
int V_109 = F_45 ( V_106 [ V_77 ] ) ;
if ( V_109 ) {
V_83 |= V_109 ;
V_112 ++ ;
}
}
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ ) {
if ( ( V_58 == V_81 [ V_77 ] . V_82 ||
V_112 == V_81 [ V_77 ] . V_82 ) &&
( V_83 & V_81 [ V_77 ] . V_83 ) ==
V_81 [ V_77 ] . V_83 )
return V_81 [ V_77 ] . V_86 ;
}
return - 1 ;
}
static int F_50 ( struct V_1 * V_2 ,
T_1 V_3 ,
int V_58 , unsigned char * V_106 ,
int V_85 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_107 = F_37 ( V_85 ) ;
int V_113 , V_100 ;
int V_114 [ 8 ] = { [ 0 ... 7 ] = 0xf } ;
for ( V_113 = 0 ; V_113 < V_58 ; V_113 ++ ) {
V_100 = F_46 ( V_107 , V_106 [ V_113 ] ) ;
if ( V_100 < 0 )
continue;
V_114 [ V_100 ] = V_113 ;
}
for ( V_100 = 0 ; V_100 < 8 ; V_100 ++ ) {
int V_39 ;
V_39 = V_5 -> V_93 . V_102 ( V_2 , V_3 , V_100 ,
V_114 [ V_100 ] ) ;
if ( V_39 )
return - V_8 ;
}
return 0 ;
}
static void F_51 ( unsigned char * V_106 , int V_85 )
{
int V_77 ;
int V_107 = F_37 ( V_85 ) ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
if ( V_77 < V_81 [ V_107 ] . V_82 )
V_106 [ V_77 ] = F_48 ( V_107 , V_99 [ V_85 ] [ V_77 ] & 0x0f ) ;
else
V_106 [ V_77 ] = 0 ;
}
}
static void F_52 ( struct V_1 * V_2 ,
T_1 V_3 , bool V_95 , int V_85 ,
int V_82 , unsigned char * V_106 ,
bool V_115 )
{
if ( ! V_95 && V_115 ) {
F_50 ( V_2 , V_3 ,
V_82 , V_106 , V_85 ) ;
} else {
F_43 ( V_2 , V_3 , V_95 , V_85 ) ;
F_51 ( V_106 , V_85 ) ;
}
F_41 ( V_2 , V_3 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_3 ,
int V_116 , int V_92 )
{
return F_21 ( V_2 , V_3 , 0 ,
V_117 ,
( V_92 << 4 ) | V_116 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_3 ,
int V_116 )
{
return ( F_19 ( V_2 , V_3 , 0 ,
V_118 ,
V_116 ) & 0xf0 ) >> 4 ;
}
static void F_55 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_2 , V_3 , 0 , V_119 ,
V_120 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_2 , V_3 , 0 , V_119 ,
V_121 ) ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_3 )
{
#ifdef F_42
int V_77 ;
int V_122 ;
V_122 = F_58 ( V_2 , V_3 ) ;
F_40 ( V_2 , L_8 , V_122 ) ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_122 = F_19 ( V_2 , V_3 , 0 ,
V_123 , V_77 ) ;
F_40 ( V_2 , L_9 , V_77 , V_122 ) ;
}
#endif
}
static void F_59 ( struct V_1 * V_2 , T_1 V_3 )
{
#ifdef F_60
int V_77 , V_78 ;
int V_122 ;
int V_124 , V_125 ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_122 = F_19 ( V_2 , V_3 , 0 ,
V_123 , V_77 ) ;
if ( V_122 == 0 )
continue;
F_20 ( V_2 , V_3 , V_77 , 0x0 ) ;
for ( V_78 = 1 ; V_78 < 1000 ; V_78 ++ ) {
F_22 ( V_2 , V_3 , 0x0 ) ;
F_18 ( V_2 , V_3 , & V_124 , & V_125 ) ;
if ( V_124 != V_77 )
F_40 ( V_2 , L_10 ,
V_125 , V_124 , V_77 ) ;
if ( V_125 == 0 )
break;
}
F_40 ( V_2 ,
L_11 ,
V_77 , V_122 , V_78 ) ;
}
#endif
}
static void F_61 ( struct V_126 * V_127 )
{
T_2 * V_33 = ( T_2 * ) V_127 ;
T_2 V_128 = 0 ;
int V_77 ;
V_127 -> V_129 = 0 ;
for ( V_77 = 0 ; V_77 < sizeof( * V_127 ) ; V_77 ++ )
V_128 += V_33 [ V_77 ] ;
V_127 -> V_129 = - V_128 ;
}
static void F_62 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_130 , int V_122 )
{
int V_77 ;
F_57 ( V_2 , V_3 ) ;
F_59 ( V_2 , V_3 ) ;
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
for ( V_77 = 0 ; V_77 < V_122 ; V_77 ++ )
F_22 ( V_2 , V_3 , V_130 [ V_77 ] ) ;
}
static bool F_63 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_130 , int V_122 )
{
T_2 V_46 ;
int V_77 ;
if ( F_19 ( V_2 , V_3 , 0 , V_131 , 0 )
!= V_120 )
return false ;
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
for ( V_77 = 0 ; V_77 < V_122 ; V_77 ++ ) {
V_46 = F_19 ( V_2 , V_3 , 0 ,
V_132 , 0 ) ;
if ( V_46 != V_130 [ V_77 ] )
return false ;
}
return true ;
}
static void F_64 ( struct V_1 * V_2 ,
T_1 V_3 ,
int V_85 , int V_133 ,
int V_134 )
{
union V_135 V_136 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
if ( V_134 == 0 ) {
struct V_126 * V_127 = & V_136 . V_137 ;
V_127 -> type = 0x84 ;
V_127 -> V_138 = 0x01 ;
V_127 -> V_139 = 0x0a ;
V_127 -> V_140 = V_133 - 1 ;
V_127 -> V_141 = V_85 ;
F_61 ( V_127 ) ;
} else if ( V_134 == 1 ) {
struct V_142 * V_143 = & V_136 . V_144 ;
V_143 -> type = 0x84 ;
V_143 -> V_139 = 0x1b ;
V_143 -> V_138 = 0x11 << 2 ;
V_143 -> V_140 = V_133 - 1 ;
V_143 -> V_141 = V_85 ;
} else {
F_40 ( V_2 , L_12 ,
V_3 ) ;
return;
}
if ( ! F_63 ( V_2 , V_3 , V_136 . V_33 ,
sizeof( V_136 ) ) ) {
F_40 ( V_2 ,
L_13 ,
V_3 ,
V_133 , V_85 ) ;
F_56 ( V_2 , V_3 ) ;
F_62 ( V_2 , V_3 ,
V_136 . V_33 , sizeof( V_136 ) ) ;
F_55 ( V_2 , V_3 ) ;
}
}
static void F_65 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
bool V_95 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_3 = V_20 -> V_3 ;
int V_82 = V_20 -> V_82 ;
int V_133 ;
struct V_21 * V_22 ;
int V_85 , V_107 ;
if ( ! V_82 )
return;
if ( F_66 ( V_2 ) )
F_21 ( V_2 , V_3 , 0 ,
V_52 ,
V_53 ) ;
V_22 = & V_20 -> V_25 ;
if ( ! V_95 && V_20 -> V_115 )
V_85 = F_49 ( V_82 , V_20 -> V_145 ) ;
else
V_85 = F_38 ( V_2 , V_22 , V_82 ) ;
if ( V_85 < 0 )
V_85 = 0 ;
V_107 = F_37 ( V_85 ) ;
V_133 = V_81 [ V_107 ] . V_82 ;
F_26 ( V_2 , V_20 -> V_12 , V_133 ) ;
F_52 ( V_2 , V_3 , V_95 , V_85 ,
V_82 , V_20 -> V_145 ,
V_20 -> V_115 ) ;
V_5 -> V_93 . V_146 ( V_2 , V_3 , V_85 , V_133 ,
V_22 -> V_90 . V_134 ) ;
V_20 -> V_95 = V_95 ;
}
static void F_67 ( struct V_1 * V_2 , T_1 V_147 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = F_1 ( V_2 , V_147 ) ;
if ( V_6 < 0 )
return;
if ( F_68 ( F_2 ( V_5 , V_6 ) , 1 ) )
F_69 ( V_2 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
F_67 ( V_2 , V_149 -> V_147 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_150 )
{
int V_151 = V_150 >> V_152 ;
struct V_153 * V_149 ;
int V_154 = ( V_150 & V_155 ) >> V_156 ;
V_149 = F_72 ( V_2 , V_151 ) ;
if ( ! V_149 )
return;
V_149 -> V_157 = 1 ;
F_40 ( V_2 ,
L_14 ,
V_2 -> V_67 , V_149 -> V_147 , V_154 , ! ! ( V_150 & V_158 ) ,
! ! ( V_150 & V_159 ) , ! ! ( V_150 & V_160 ) ) ;
F_67 ( V_2 , V_149 -> V_147 ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned int V_150 )
{
int V_151 = V_150 >> V_152 ;
int V_161 = ( V_150 & V_162 ) >> V_163 ;
int V_164 = ! ! ( V_150 & V_165 ) ;
int V_166 = ! ! ( V_150 & V_167 ) ;
F_74 ( V_2 ,
L_15 ,
V_2 -> V_67 ,
V_151 ,
V_161 ,
V_164 ,
V_166 ) ;
if ( V_164 )
;
if ( V_166 )
;
}
static void F_75 ( struct V_1 * V_2 , unsigned int V_150 )
{
int V_151 = V_150 >> V_152 ;
int V_161 = ( V_150 & V_162 ) >> V_163 ;
if ( ! F_72 ( V_2 , V_151 ) ) {
F_40 ( V_2 , L_16 , V_151 ) ;
return;
}
if ( V_161 == 0 )
F_71 ( V_2 , V_150 ) ;
else
F_73 ( V_2 , V_150 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_147 )
{
int V_168 ;
if ( ! F_77 ( V_2 , V_12 , V_169 ) )
F_21 ( V_2 , V_12 , 0 , V_170 , V_169 ) ;
if ( ! F_77 ( V_2 , V_147 , V_169 ) ) {
F_21 ( V_2 , V_147 , 0 , V_170 ,
V_169 ) ;
F_78 ( 40 ) ;
V_168 = F_19 ( V_2 , V_147 , 0 , V_171 , 0 ) ;
V_168 = ( V_168 & V_172 ) >> V_173 ;
F_40 ( V_2 , L_17 , V_147 , V_168 ) ;
}
}
static int F_79 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_174 )
{
int V_175 , V_176 ;
if ( F_80 ( V_2 , V_3 ) & V_177 ) {
V_175 = F_19 ( V_2 , V_3 , 0 ,
V_178 , 0 ) ;
if ( V_175 < 0 )
return V_174 ? - V_8 : 0 ;
V_176 = V_175 & ~ V_179 ;
if ( V_174 )
V_176 |= V_180 ;
else
V_176 |= V_181 ;
F_40 ( V_2 ,
L_18 ,
V_3 ,
V_175 == V_176 ? L_19 : L_20 ,
V_176 ) ;
if ( V_175 != V_176 )
F_21 ( V_2 , V_3 , 0 ,
V_56 ,
V_176 ) ;
} else if ( V_174 )
return - V_8 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_3 , T_3 V_182 , int V_183 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_39 ;
if ( F_66 ( V_2 ) )
F_76 ( V_2 , V_12 , V_3 ) ;
V_39 = V_5 -> V_93 . V_184 ( V_2 , V_3 , F_82 ( V_183 ) ) ;
if ( V_39 ) {
F_40 ( V_2 , L_21 ) ;
return V_39 ;
}
F_83 ( V_2 , V_12 , V_182 , 0 , V_183 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
int V_6 , int * V_185 , int * V_186 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 ;
struct V_187 * V_188 = NULL ;
int V_13 , V_189 = 0 ;
V_20 = F_2 ( V_5 , V_6 ) ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_188 = F_7 ( V_5 , V_13 ) ;
if ( V_188 -> V_190 )
continue;
for ( V_189 = 0 ; V_189 < V_20 -> V_191 ; V_189 ++ )
if ( V_20 -> V_192 [ V_189 ] == V_188 -> V_12 )
break;
if ( V_189 == V_20 -> V_191 )
continue;
break;
}
if ( V_13 == V_5 -> V_14 )
return - V_193 ;
V_20 -> V_189 = V_189 ;
if ( V_185 )
* V_185 = V_13 ;
if ( V_186 )
* V_186 = V_189 ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_1 V_3 = V_20 -> V_3 ;
int V_189 , V_194 ;
V_189 = V_20 -> V_189 ;
V_194 = F_19 ( V_2 , V_3 , 0 ,
V_195 , 0 ) ;
if ( V_194 != V_189 )
F_86 ( V_2 , V_3 , 0 ,
V_196 ,
V_189 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
T_1 V_3 , int V_189 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_147 ;
int V_13 , V_194 ;
struct V_187 * V_188 ;
F_88 (nid, codec) {
unsigned int V_197 = F_24 ( V_2 , V_147 ) ;
unsigned int V_198 = F_89 ( V_197 ) ;
if ( V_198 != V_199 )
continue;
if ( V_147 == V_3 )
continue;
V_194 = F_19 ( V_2 , V_147 , 0 ,
V_195 , 0 ) ;
if ( V_194 != V_189 )
continue;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_188 = F_7 ( V_5 , V_13 ) ;
if ( ! V_188 -> V_190 ) {
F_40 ( V_2 ,
L_22 ,
V_13 , V_147 ) ;
F_86 ( V_2 , V_147 , 0 ,
V_196 ,
V_13 ) ;
break;
}
}
}
}
static int F_90 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_202 * V_203 = V_201 -> V_203 ;
int V_6 , V_13 , V_189 = 0 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_187 * V_188 = NULL ;
int V_39 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_91 ( V_6 < 0 ) )
return - V_8 ;
V_20 = F_2 ( V_5 , V_6 ) ;
V_22 = & V_20 -> V_25 ;
V_39 = F_84 ( V_2 , V_6 , & V_13 , & V_189 ) ;
if ( V_39 < 0 )
return V_39 ;
V_188 = F_7 ( V_5 , V_13 ) ;
V_188 -> V_190 = 1 ;
V_20 -> V_12 = V_188 -> V_12 ;
V_10 -> V_147 = V_188 -> V_12 ;
F_86 ( V_2 , V_20 -> V_3 , 0 ,
V_196 ,
V_189 ) ;
if ( F_66 ( V_2 ) || F_92 ( V_2 ) )
F_87 ( V_2 , V_20 -> V_3 , V_189 ) ;
F_93 ( V_2 , V_6 , V_188 -> V_12 ) ;
V_10 -> V_204 = V_188 -> V_204 ;
V_10 -> V_205 = V_188 -> V_205 ;
V_10 -> V_206 = V_188 -> V_206 ;
V_10 -> V_207 = V_188 -> V_207 ;
V_10 -> V_208 = V_188 -> V_208 ;
if ( ! V_209 && V_22 -> V_28 ) {
F_94 ( & V_22 -> V_90 , V_10 ) ;
if ( V_10 -> V_204 > V_10 -> V_205 ||
! V_10 -> V_206 || ! V_10 -> V_207 ) {
V_188 -> V_190 = 0 ;
V_10 -> V_147 = 0 ;
F_95 ( V_2 , V_6 ) ;
return - V_193 ;
}
}
V_203 -> V_210 . V_204 = V_10 -> V_204 ;
V_203 -> V_210 . V_205 = V_10 -> V_205 ;
V_203 -> V_210 . V_207 = V_10 -> V_207 ;
V_203 -> V_210 . V_206 = V_10 -> V_206 ;
F_96 ( V_201 -> V_203 , 0 ,
V_211 , 2 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
if ( ! ( F_24 ( V_2 , V_3 ) & V_212 ) ) {
F_3 ( V_2 ,
L_23 ,
V_3 , F_24 ( V_2 , V_3 ) ) ;
return - V_8 ;
}
V_20 -> V_191 = F_98 ( V_2 , V_3 ,
V_20 -> V_192 ,
V_213 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_21 * V_214 = & V_20 -> V_25 ;
bool V_215 = V_214 -> V_28 ;
bool V_216 ;
if ( V_22 -> V_28 )
F_100 ( V_2 , & V_22 -> V_90 ) ;
V_216 = ( V_214 -> V_28 != V_22 -> V_28 ) ;
if ( V_22 -> V_28 && V_214 -> V_28 )
if ( V_214 -> V_29 != V_22 -> V_29 ||
memcmp ( V_214 -> V_36 , V_22 -> V_36 ,
V_22 -> V_29 ) != 0 )
V_216 = true ;
V_214 -> V_28 = V_22 -> V_28 ;
V_214 -> V_29 = V_22 -> V_29 ;
if ( V_22 -> V_28 )
memcpy ( V_214 -> V_36 , V_22 -> V_36 , V_22 -> V_29 ) ;
V_214 -> V_90 = V_22 -> V_90 ;
if ( V_22 -> V_28 && ! V_215 && V_20 -> V_217 ) {
if ( F_66 ( V_2 ) || F_92 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_20 -> V_3 ,
V_20 -> V_189 ) ;
}
F_65 ( V_2 , V_20 , V_20 -> V_95 ) ;
}
if ( V_216 )
F_101 ( V_2 -> V_68 ,
V_218 |
V_219 ,
& V_20 -> V_43 -> V_42 ) ;
}
static bool F_102 ( struct V_19 * V_20 ,
int V_220 )
{
struct V_153 * V_149 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_22 = & V_5 -> V_221 ;
struct V_21 * V_214 = & V_20 -> V_25 ;
T_1 V_3 = V_20 -> V_3 ;
int V_222 ;
bool V_223 ;
bool V_224 = false ;
F_103 ( V_2 ) ;
V_222 = F_104 ( V_2 , V_3 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_214 -> V_225 = ! ! ( V_222 & V_226 ) ;
if ( V_214 -> V_225 )
V_22 -> V_28 = ! ! ( V_222 & V_227 ) ;
else
V_22 -> V_28 = false ;
F_40 ( V_2 ,
L_24 ,
V_2 -> V_67 , V_3 , V_214 -> V_225 , V_22 -> V_28 ) ;
if ( V_22 -> V_28 ) {
if ( V_5 -> V_93 . V_228 ( V_2 , V_3 , V_22 -> V_36 ,
& V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
else {
if ( F_105 ( V_2 , & V_22 -> V_90 , V_22 -> V_36 ,
V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
}
if ( ! V_22 -> V_28 && V_220 )
V_224 = true ;
}
if ( V_224 )
F_106 ( & V_20 -> V_229 , F_107 ( 300 ) ) ;
else
F_99 ( V_2 , V_20 , V_22 ) ;
V_223 = ! V_220 || ! V_214 -> V_225 || V_214 -> V_28 ;
V_149 = F_108 ( V_2 , V_3 ) ;
if ( V_149 )
V_149 -> V_230 = ! V_223 ;
F_11 ( & V_20 -> V_26 ) ;
F_109 ( V_2 ) ;
return V_223 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_22 = & V_5 -> V_221 ;
int V_122 ;
F_10 ( & V_20 -> V_26 ) ;
V_122 = F_111 ( & V_2 -> V_75 -> V_231 , V_20 -> V_3 ,
& V_22 -> V_225 , V_22 -> V_36 ,
V_35 ) ;
if ( V_122 < 0 )
goto V_232;
if ( V_122 > 0 ) {
V_122 = F_112 ( V_122 , V_35 ) ;
if ( F_105 ( V_2 , & V_22 -> V_90 ,
V_22 -> V_36 , V_122 ) < 0 )
V_122 = - V_8 ;
}
if ( V_122 > 0 ) {
V_22 -> V_28 = true ;
V_22 -> V_29 = V_122 ;
} else {
V_22 -> V_28 = false ;
V_22 -> V_29 = 0 ;
}
F_99 ( V_2 , V_20 , V_22 ) ;
F_113 ( V_20 -> V_233 ,
V_22 -> V_225 ? V_234 : 0 ) ;
V_232:
F_11 ( & V_20 -> V_26 ) ;
}
static bool F_68 ( struct V_19 * V_20 , int V_220 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
if ( F_114 ( V_2 ) ) {
F_110 ( V_2 , V_20 ) ;
return false ;
} else {
return F_102 ( V_20 , V_220 ) ;
}
}
static void F_115 ( struct V_235 * V_229 )
{
struct V_19 * V_20 =
F_116 ( F_117 ( V_229 ) , struct V_19 , V_229 ) ;
if ( V_20 -> V_236 ++ > 6 )
V_20 -> V_236 = 0 ;
if ( F_68 ( V_20 , V_20 -> V_236 ) )
F_69 ( V_20 -> V_2 ) ;
}
static int F_118 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_237 , V_238 ;
int V_6 ;
struct V_19 * V_20 ;
int V_39 ;
V_237 = F_80 ( V_2 , V_3 ) ;
if ( ! ( V_237 & ( V_239 | V_240 ) ) )
return 0 ;
V_238 = F_119 ( V_2 , V_3 ) ;
if ( F_120 ( V_238 ) == V_241 )
return 0 ;
if ( F_66 ( V_2 ) )
F_121 ( V_2 , V_3 ) ;
V_6 = V_5 -> V_7 ;
V_20 = F_122 ( & V_5 -> V_242 ) ;
if ( ! V_20 )
return - V_41 ;
V_20 -> V_3 = V_3 ;
V_20 -> V_95 = false ;
V_39 = F_97 ( V_2 , V_6 ) ;
if ( V_39 < 0 )
return V_39 ;
V_5 -> V_7 ++ ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_187 * V_188 ;
unsigned int V_243 ;
int V_39 ;
V_243 = F_24 ( V_2 , V_12 ) ;
V_243 = F_124 ( V_243 ) ;
V_188 = F_122 ( & V_5 -> V_244 ) ;
if ( ! V_188 )
return - V_41 ;
V_188 -> V_12 = V_12 ;
V_188 -> V_204 = 2 ;
if ( V_243 <= 16 ) {
V_188 -> V_205 = V_243 ;
if ( V_243 > V_5 -> V_205 )
V_5 -> V_205 = V_243 ;
}
V_39 = F_125 ( V_2 , V_12 ,
& V_188 -> V_206 ,
& V_188 -> V_207 ,
& V_188 -> V_208 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_5 -> V_14 < F_13 ( V_5 -> V_245 ) )
V_5 -> V_245 [ V_5 -> V_14 ] = V_12 ;
V_5 -> V_14 ++ ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
T_1 V_147 ;
int V_77 , V_246 ;
V_246 = F_127 ( V_2 , V_2 -> V_231 . V_247 , & V_147 ) ;
if ( ! V_147 || V_246 < 0 ) {
F_3 ( V_2 , L_25 ) ;
return - V_8 ;
}
for ( V_77 = 0 ; V_77 < V_246 ; V_77 ++ , V_147 ++ ) {
unsigned int V_237 ;
unsigned int type ;
V_237 = F_24 ( V_2 , V_147 ) ;
type = F_89 ( V_237 ) ;
if ( ! ( V_237 & V_248 ) )
continue;
switch ( type ) {
case V_249 :
F_123 ( V_2 , V_147 ) ;
break;
case V_199 :
F_118 ( V_2 , V_147 ) ;
break;
}
}
return 0 ;
}
static bool F_128 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_250 * V_251 ;
bool V_95 ;
F_10 ( & V_2 -> V_252 ) ;
V_251 = F_129 ( V_2 , V_12 ) ;
V_95 = ! ! ( V_251 -> V_253 & V_254 ) ;
F_11 ( & V_2 -> V_252 ) ;
return V_95 ;
}
static int F_130 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_200 * V_201 )
{
T_1 V_12 = V_10 -> V_147 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = F_4 ( V_2 , V_10 ) ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
struct V_202 * V_203 = V_201 -> V_203 ;
bool V_95 ;
int V_175 ;
if ( F_66 ( V_2 ) || F_92 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_3 , V_20 -> V_189 ) ;
}
F_131 ( & V_2 -> V_75 -> V_231 , V_3 , V_203 -> V_255 ) ;
V_95 = F_128 ( V_2 , V_12 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_82 = V_201 -> V_203 -> V_82 ;
V_20 -> V_217 = true ;
F_65 ( V_2 , V_20 , V_95 ) ;
F_11 ( & V_20 -> V_26 ) ;
if ( V_5 -> V_54 ) {
V_175 = F_19 ( V_2 , V_3 , 0 ,
V_178 , 0 ) ;
F_21 ( V_2 , V_3 , 0 ,
V_56 ,
V_175 | V_55 ) ;
}
return V_5 -> V_93 . V_256 ( V_2 , V_12 , V_3 , V_182 , V_183 ) ;
}
static int F_132 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
F_133 ( V_2 , V_10 -> V_147 ) ;
return 0 ;
}
static int F_134 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_13 , V_6 ;
struct V_187 * V_188 ;
struct V_19 * V_20 ;
int V_175 ;
if ( V_10 -> V_147 ) {
V_13 = F_6 ( V_2 , V_10 -> V_147 ) ;
if ( F_91 ( V_13 < 0 ) )
return - V_8 ;
V_188 = F_7 ( V_5 , V_13 ) ;
F_91 ( ! V_188 -> V_190 ) ;
V_188 -> V_190 = 0 ;
V_10 -> V_147 = 0 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_91 ( V_6 < 0 ) )
return - V_8 ;
V_20 = F_2 ( V_5 , V_6 ) ;
if ( V_5 -> V_54 ) {
V_175 = F_19 ( V_2 , V_20 -> V_3 , 0 ,
V_178 , 0 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_56 ,
V_175 & ~ V_55 ) ;
}
F_95 ( V_2 , V_6 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_115 = false ;
memset ( V_20 -> V_145 , 0 , sizeof( V_20 -> V_145 ) ) ;
V_20 -> V_217 = false ;
V_20 -> V_82 = 0 ;
F_11 ( & V_20 -> V_26 ) ;
}
return 0 ;
}
static int F_135 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_257 * V_90 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_90 -> V_64 ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_18 -> type = V_258 ;
V_18 -> V_27 = V_5 -> V_205 ;
V_18 -> V_32 . integer . F_112 = 0 ;
V_18 -> V_32 . integer . V_259 = V_260 ;
return 0 ;
}
static int F_136 ( struct V_79 * V_261 ,
int V_82 )
{
if ( V_261 -> V_82 != V_82 )
return - 1 ;
return V_262 ;
}
static void F_137 ( struct V_79 * V_261 ,
unsigned int * V_145 , int V_82 )
{
int V_27 = 0 ;
int V_69 ;
for ( V_69 = 7 ; V_69 >= 0 ; V_69 -- ) {
int V_110 = V_261 -> V_84 [ V_69 ] ;
if ( ! V_110 )
continue;
V_145 [ V_27 ++ ] = F_47 ( V_110 ) ;
}
F_44 ( V_27 != V_82 ) ;
}
static int F_138 ( struct V_15 * V_16 , int V_263 ,
unsigned int V_122 , unsigned int T_4 * V_264 )
{
struct V_257 * V_90 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_90 -> V_64 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int T_4 * V_265 ;
int V_58 , V_27 = 0 ;
if ( V_122 < 8 )
return - V_41 ;
if ( F_139 ( V_266 , V_264 ) )
return - V_267 ;
V_122 -= 8 ;
V_265 = V_264 + 2 ;
for ( V_58 = 2 ; V_58 <= V_5 -> V_205 ; V_58 ++ ) {
int V_77 ;
struct V_79 * V_261 ;
V_261 = V_81 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_81 ) ; V_77 ++ , V_261 ++ ) {
int V_268 = V_58 * 4 ;
int type = V_5 -> V_93 . V_269 ( V_261 , V_58 ) ;
unsigned int V_270 [ 8 ] ;
if ( type < 0 )
continue;
if ( V_122 < 8 )
return - V_41 ;
if ( F_139 ( type , V_265 ) ||
F_139 ( V_268 , V_265 + 1 ) )
return - V_267 ;
V_265 += 2 ;
V_122 -= 8 ;
V_27 += 8 ;
if ( V_122 < V_268 )
return - V_41 ;
V_122 -= V_268 ;
V_27 += V_268 ;
V_5 -> V_93 . V_271 ( V_261 , V_270 , V_58 ) ;
if ( F_140 ( V_265 , V_270 , V_268 ) )
return - V_267 ;
V_265 += V_58 ;
}
}
if ( F_139 ( V_27 , V_264 + 1 ) )
return - V_267 ;
return 0 ;
}
static int F_141 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_257 * V_90 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_90 -> V_64 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_16 -> V_24 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
int V_77 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_20 -> V_145 ) ; V_77 ++ )
V_31 -> V_32 . integer . V_32 [ V_77 ] = V_20 -> V_145 [ V_77 ] ;
return 0 ;
}
static int F_142 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_257 * V_90 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_90 -> V_64 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_16 -> V_24 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
unsigned int V_272 ;
struct V_200 * V_201 ;
unsigned char V_145 [ 8 ] ;
int V_77 , V_39 , V_85 , V_273 = 0 ;
V_272 = F_143 ( V_16 , & V_31 -> V_42 ) ;
V_201 = F_144 ( V_90 , V_272 ) ;
if ( ! V_201 || ! V_201 -> V_203 )
return 0 ;
switch ( V_201 -> V_203 -> V_253 -> V_274 ) {
case V_275 :
case V_276 :
break;
case V_277 :
V_273 = 1 ;
break;
default:
return - V_278 ;
}
memset ( V_145 , 0 , sizeof( V_145 ) ) ;
for ( V_77 = 0 ; V_77 < F_13 ( V_145 ) ; V_77 ++ )
V_145 [ V_77 ] = V_31 -> V_32 . integer . V_32 [ V_77 ] ;
if ( ! memcmp ( V_145 , V_20 -> V_145 , sizeof( V_145 ) ) )
return 0 ;
V_85 = F_49 ( F_13 ( V_145 ) , V_145 ) ;
if ( V_85 < 0 )
return - V_8 ;
if ( V_5 -> V_93 . V_279 ) {
V_39 = V_5 -> V_93 . V_279 ( V_85 , F_13 ( V_145 ) , V_145 ) ;
if ( V_39 )
return V_39 ;
}
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_115 = true ;
memcpy ( V_20 -> V_145 , V_145 , sizeof( V_145 ) ) ;
if ( V_273 )
F_65 ( V_2 , V_20 , V_20 -> V_95 ) ;
F_11 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_280 * V_90 ;
struct V_9 * V_281 ;
V_90 = F_146 ( V_2 , L_26 , V_6 ) ;
if ( ! V_90 )
return - V_41 ;
V_5 -> V_282 [ V_6 ] = V_90 ;
V_90 -> V_283 = V_284 ;
V_90 -> V_285 = true ;
V_281 = & V_90 -> V_11 [ V_286 ] ;
V_281 -> V_287 = 1 ;
V_281 -> V_93 = V_288 ;
}
return 0 ;
}
static void F_147 ( struct V_289 * V_149 )
{
struct V_19 * V_20 = V_149 -> V_64 ;
V_20 -> V_233 = NULL ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_66 )
{
struct V_289 * V_149 ;
int V_39 ;
V_39 = F_149 ( V_2 -> V_68 , V_66 , V_234 , & V_149 ,
true , false ) ;
if ( V_39 < 0 )
return V_39 ;
V_20 -> V_233 = V_149 ;
V_149 -> V_64 = V_20 ;
V_149 -> V_290 = F_147 ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 , int V_6 )
{
char V_291 [ 32 ] = L_27 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
int V_292 = F_5 ( V_5 , V_6 ) -> V_37 ;
bool V_293 ;
if ( V_292 > 0 )
sprintf ( V_291 + strlen ( V_291 ) , L_28 , V_292 ) ;
if ( F_114 ( V_2 ) )
return F_148 ( V_2 , V_20 , V_291 ) ;
V_293 = ! F_151 ( V_2 , V_20 -> V_3 ) ;
if ( V_293 )
strncat ( V_291 , L_29 ,
sizeof( V_291 ) - strlen ( V_291 ) - 1 ) ;
return F_152 ( V_2 , V_20 -> V_3 , V_291 ,
V_293 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_39 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
V_39 = F_150 ( V_2 , V_6 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_154 ( V_2 ,
V_20 -> V_3 ,
V_20 -> V_192 [ 0 ] ,
V_284 ) ;
if ( V_39 < 0 )
return V_39 ;
F_95 ( V_2 , V_6 ) ;
V_39 = F_15 ( V_2 , V_6 ,
F_5 ( V_5 , V_6 ) -> V_37 ) ;
if ( V_39 < 0 )
return V_39 ;
F_68 ( V_20 , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_280 * V_294 ;
struct V_257 * V_145 ;
struct V_15 * V_38 ;
int V_77 ;
V_294 = V_5 -> V_282 [ V_6 ] ;
if ( ! V_294 || ! V_294 -> V_294 )
break;
V_39 = F_155 ( V_294 -> V_294 ,
V_286 ,
NULL , 0 , V_6 , & V_145 ) ;
if ( V_39 < 0 )
return V_39 ;
V_145 -> V_64 = V_2 ;
V_38 = V_145 -> V_38 ;
for ( V_77 = 0 ; V_77 < V_38 -> V_27 ; V_77 ++ )
V_38 -> V_295 [ V_77 ] . V_296 |= V_297 ;
V_38 -> V_90 = F_135 ;
V_38 -> V_298 = F_141 ;
V_38 -> V_299 = F_142 ;
V_38 -> V_264 . V_69 = F_138 ;
}
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
V_20 -> V_2 = V_2 ;
F_157 ( & V_20 -> V_26 ) ;
F_158 ( & V_20 -> V_229 , F_115 ) ;
F_31 ( V_20 , V_6 ) ;
}
return 0 ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
F_23 ( V_2 , V_3 ) ;
if ( ! F_114 ( V_2 ) )
F_160 ( V_2 , V_3 ,
V_2 -> V_300 > 0 ?
F_70 : NULL ) ;
}
return 0 ;
}
static void F_161 ( struct V_4 * V_5 , int V_301 )
{
F_162 ( & V_5 -> V_242 , sizeof( struct V_19 ) , V_301 ) ;
F_162 ( & V_5 -> V_244 , sizeof( struct V_187 ) , V_301 ) ;
}
static void F_163 ( struct V_4 * V_5 )
{
F_164 ( & V_5 -> V_242 ) ;
F_164 ( & V_5 -> V_244 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( F_114 ( V_2 ) )
F_166 ( NULL ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_167 ( & V_20 -> V_229 ) ;
F_34 ( V_20 ) ;
if ( V_20 -> V_233 )
F_168 ( V_2 -> V_68 , V_20 -> V_233 ) ;
}
if ( V_5 -> V_302 )
F_169 ( & V_2 -> V_75 -> V_231 ) ;
F_163 ( V_5 ) ;
F_170 ( V_5 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_2 -> V_303 . V_304 ( V_2 ) ;
F_172 ( V_2 -> V_231 . V_305 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_68 ( V_20 , 1 ) ;
}
return 0 ;
}
static void F_121 ( struct V_1 * V_2 ,
T_1 V_147 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_306 [ 4 ] ;
int V_307 ;
V_307 = F_98 ( V_2 , V_147 , V_306 , F_13 ( V_306 ) ) ;
if ( V_307 == V_5 -> V_14 &&
! memcmp ( V_306 , V_5 -> V_245 , V_5 -> V_14 * sizeof( T_1 ) ) )
return;
F_40 ( V_2 , L_30 , V_147 ) ;
F_173 ( V_2 , V_147 , V_5 -> V_14 , V_5 -> V_245 ) ;
}
static void F_174 ( struct V_1 * V_2 ,
bool V_308 )
{
unsigned int V_309 ;
V_309 = F_19 ( V_2 , V_310 , 0 ,
V_311 , 0 ) ;
if ( V_309 == - 1 || V_309 & V_312 )
return;
V_309 |= V_312 ;
V_309 = F_19 ( V_2 , V_310 , 0 ,
V_313 , V_309 ) ;
if ( V_309 == - 1 )
return;
if ( V_308 )
F_175 ( V_2 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
unsigned int V_309 ;
V_309 = F_19 ( V_2 , V_310 , 0 ,
V_311 , 0 ) ;
if ( V_309 == - 1 || V_309 & V_314 )
return;
V_309 |= V_314 ;
F_177 ( & V_2 -> V_231 , V_313 ) ;
F_86 ( V_2 , V_310 , 0 ,
V_313 , V_309 ) ;
}
static void F_178 ( struct V_1 * V_2 , T_1 V_315 ,
unsigned int V_316 )
{
if ( V_316 == V_169 ) {
F_174 ( V_2 , false ) ;
F_176 ( V_2 ) ;
}
F_19 ( V_2 , V_315 , 0 , V_170 , V_316 ) ;
F_179 ( V_2 , V_315 , V_316 ) ;
}
static void F_180 ( void * V_317 , int V_318 )
{
struct V_1 * V_2 = V_317 ;
int V_3 = V_318 + 0x04 ;
if ( F_181 ( V_2 -> V_68 ) != V_319 )
return;
if ( F_182 ( & ( V_2 ) -> V_231 . V_320 ) )
return;
F_67 ( V_2 , V_3 ) ;
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_184 ( sizeof( * V_5 ) , V_321 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_93 = V_322 ;
V_2 -> V_5 = V_5 ;
F_161 ( V_5 , 4 ) ;
if ( ! F_114 ( V_2 ) &&
( V_2 -> V_231 . V_323 >> 16 ) == 0x8086 )
if ( ! F_185 ( & V_2 -> V_75 -> V_231 ) )
V_5 -> V_302 = true ;
if ( F_66 ( V_2 ) ) {
F_174 ( V_2 , true ) ;
F_176 ( V_2 ) ;
}
if ( F_92 ( V_2 ) || F_186 ( V_2 ) ||
F_187 ( V_2 ) )
V_2 -> V_231 . V_324 = 1 ;
if ( F_126 ( V_2 ) < 0 ) {
if ( V_5 -> V_302 )
F_169 ( & V_2 -> V_75 -> V_231 ) ;
V_2 -> V_5 = NULL ;
F_170 ( V_5 ) ;
return - V_8 ;
}
V_2 -> V_303 = V_325 ;
if ( F_66 ( V_2 ) ) {
V_2 -> V_303 . V_326 = F_178 ;
V_2 -> V_327 = true ;
}
if ( F_66 ( V_2 ) || F_92 ( V_2 ) )
V_2 -> V_328 = 1 ;
F_156 ( V_2 ) ;
F_36 () ;
if ( F_114 ( V_2 ) ) {
V_2 -> V_329 = 0 ;
V_5 -> V_330 . V_317 = V_2 ;
F_188 () ;
V_5 -> V_330 . V_331 = F_180 ;
F_166 ( & V_5 -> V_330 ) ;
}
return 0 ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_280 * V_90 ;
unsigned int V_243 ;
struct V_9 * V_281 ;
struct V_187 * V_188 ;
V_188 = F_7 ( V_5 , 0 ) ;
V_243 = F_24 ( V_2 , V_188 -> V_12 ) ;
V_243 = F_124 ( V_243 ) ;
V_90 = F_146 ( V_2 , L_31 ) ;
if ( ! V_90 )
return - V_41 ;
V_5 -> V_282 [ 0 ] = V_90 ;
V_90 -> V_283 = V_284 ;
V_281 = & V_90 -> V_11 [ V_286 ] ;
* V_281 = V_5 -> V_332 ;
V_281 -> V_147 = V_188 -> V_12 ;
if ( V_281 -> V_205 <= 2 && V_243 && V_243 <= 16 )
V_281 -> V_205 = V_243 ;
return 0 ;
}
static void F_190 ( struct V_1 * V_2 ,
unsigned int V_150 )
{
F_191 ( V_2 ) ;
F_69 ( V_2 ) ;
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_187 * V_188 ;
int V_39 ;
V_188 = F_7 ( V_5 , 0 ) ;
V_39 = F_154 ( V_2 , V_188 -> V_12 ,
V_188 -> V_12 ,
V_284 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_193 ( V_2 , 0 ) ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , 0 ) ;
T_1 V_333 = V_20 -> V_3 ;
F_21 ( V_2 , V_333 , 0 ,
V_56 , V_55 ) ;
if ( F_24 ( V_2 , V_333 ) & V_51 )
F_21 ( V_2 , V_333 , 0 , V_52 ,
V_53 ) ;
F_195 ( V_2 , V_333 ) ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_163 ( V_5 ) ;
F_170 ( V_5 ) ;
}
static int F_197 ( struct V_1 * V_2 )
{
F_198 ( V_2 , V_334 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
F_198 ( V_2 , V_335 ) ;
return 0 ;
}
static int F_200 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_336 * V_337 = NULL ;
switch ( V_2 -> V_338 -> V_323 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_337 = & V_339 ;
break;
case 0x10de0007 :
V_337 = & V_340 ;
break;
default:
break;
}
if ( V_337 != NULL ) {
V_336 ( V_201 -> V_203 , 0 ,
V_211 ,
V_337 ) ;
} else {
F_96 ( V_201 -> V_203 , 0 ,
V_211 , 2 ) ;
}
return F_201 ( V_2 , & V_5 -> V_341 ) ;
}
static int F_202 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_203 ( V_2 , & V_5 -> V_341 ) ;
}
static int F_204 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_205 ( V_2 , & V_5 -> V_341 ,
V_182 , V_183 , V_201 ) ;
}
static int F_206 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_187 * V_188 ;
struct V_19 * V_20 ;
V_5 = F_184 ( sizeof( * V_5 ) , V_321 ) ;
if ( ! V_5 )
return - V_41 ;
V_2 -> V_5 = V_5 ;
F_161 ( V_5 , 1 ) ;
V_5 -> V_341 . V_342 = 0 ;
V_5 -> V_341 . V_343 = 2 ;
V_5 -> V_341 . V_344 = V_12 ;
V_5 -> V_14 = 1 ;
V_5 -> V_7 = 1 ;
V_20 = F_122 ( & V_5 -> V_242 ) ;
V_188 = F_122 ( & V_5 -> V_244 ) ;
if ( ! V_20 || ! V_188 ) {
F_196 ( V_2 ) ;
return - V_41 ;
}
V_188 -> V_12 = V_12 ;
V_20 -> V_3 = V_3 ;
V_5 -> V_332 = V_345 ;
V_2 -> V_303 = V_346 ;
return 0 ;
}
static void F_207 ( struct V_1 * V_2 ,
int V_82 )
{
unsigned int V_347 ;
int V_348 = V_82 ? ( V_82 - 1 ) : 1 ;
switch ( V_82 ) {
default:
case 0 :
case 2 :
V_347 = 0x00 ;
break;
case 4 :
V_347 = 0x08 ;
break;
case 6 :
V_347 = 0x0b ;
break;
case 8 :
V_347 = 0x13 ;
break;
}
F_21 ( V_2 , 0x1 , 0 ,
V_349 , V_347 ) ;
F_21 ( V_2 , 0x1 , 0 ,
V_350 ,
( 0x71 - V_348 - V_347 ) ) ;
}
static int F_208 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_77 ;
F_21 ( V_2 , V_351 ,
0 , V_352 , 0 ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
F_21 ( V_2 , V_353 [ V_77 ] , 0 ,
V_352 , 0 ) ;
F_21 ( V_2 , V_353 [ V_77 ] , 0 ,
V_354 , 0 ) ;
}
F_207 ( V_2 , 8 ) ;
return F_203 ( V_2 , & V_5 -> V_341 ) ;
}
static int F_209 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_200 * V_201 )
{
int V_58 ;
unsigned int V_355 , V_356 ;
int V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_250 * V_251 ;
struct V_187 * V_188 ;
F_10 ( & V_2 -> V_252 ) ;
V_188 = F_7 ( V_5 , 0 ) ;
V_251 = F_129 ( V_2 , V_188 -> V_12 ) ;
V_58 = V_201 -> V_203 -> V_82 ;
V_355 = 0x2 ;
if ( V_2 -> V_357 && ( V_251 -> V_358 & V_359 ) )
F_21 ( V_2 ,
V_351 ,
0 ,
V_360 ,
V_251 -> V_358 & ~ V_359 & 0xff ) ;
F_21 ( V_2 , V_351 , 0 ,
V_352 , ( V_182 << 4 ) | 0x0 ) ;
F_21 ( V_2 , V_351 , 0 ,
V_354 , V_183 ) ;
if ( V_2 -> V_357 && ( V_251 -> V_358 & V_359 ) ) {
F_21 ( V_2 ,
V_351 ,
0 ,
V_360 ,
V_251 -> V_358 & 0xff ) ;
F_21 ( V_2 ,
V_351 ,
0 ,
V_361 , V_355 ) ;
}
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
if ( V_58 == 2 )
V_356 = 0 ;
else
V_356 = V_77 * 2 ;
if ( V_2 -> V_357 &&
( V_251 -> V_358 & V_359 ) )
F_21 ( V_2 ,
V_353 [ V_77 ] ,
0 ,
V_360 ,
V_251 -> V_358 & ~ V_359 & 0xff ) ;
F_21 ( V_2 ,
V_353 [ V_77 ] ,
0 ,
V_352 ,
( V_182 << 4 ) | V_356 ) ;
F_21 ( V_2 ,
V_353 [ V_77 ] ,
0 ,
V_354 ,
V_183 ) ;
if ( V_2 -> V_357 &&
( V_251 -> V_358 & V_359 ) ) {
F_21 ( V_2 ,
V_353 [ V_77 ] ,
0 ,
V_360 ,
V_251 -> V_358 & 0xff ) ;
F_21 ( V_2 ,
V_353 [ V_77 ] ,
0 ,
V_361 , V_355 ) ;
}
}
F_207 ( V_2 , V_58 ) ;
F_11 ( & V_2 -> V_252 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_39 = F_206 ( V_2 , V_351 ,
V_362 ) ;
if ( V_39 < 0 )
return V_39 ;
V_2 -> V_303 . V_304 = F_197 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_332 . V_206 = V_363 ;
V_5 -> V_332 . V_208 = V_364 ;
V_5 -> V_332 . V_207 = V_365 ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_39 = F_189 ( V_2 ) ;
if ( ! V_39 ) {
struct V_280 * V_90 = F_5 ( V_5 , 0 ) ;
V_90 -> V_285 = true ;
}
return V_39 ;
}
static int F_212 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_280 * V_90 ;
struct V_257 * V_145 ;
int V_39 ;
V_39 = F_192 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_90 = F_5 ( V_5 , 0 ) ;
V_39 = F_155 ( V_90 -> V_294 ,
V_286 ,
V_366 , 8 , 0 , & V_145 ) ;
if ( V_39 < 0 )
return V_39 ;
switch ( V_2 -> V_338 -> V_323 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_145 -> V_367 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_145 -> V_367 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_213 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_39 = F_210 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_341 . V_343 = 8 ;
V_5 -> V_332 = V_368 ;
V_2 -> V_303 . V_304 = F_199 ;
V_2 -> V_303 . V_369 = F_211 ;
V_2 -> V_303 . V_370 = F_212 ;
F_207 ( V_2 , 8 ) ;
return 0 ;
}
static int F_214 ( struct V_79 * V_261 ,
int V_82 )
{
if ( V_261 -> V_86 == 0x00 && V_82 == 2 )
return V_371 ;
return F_136 ( V_261 , V_82 ) ;
}
static int F_215 ( int V_85 , int V_58 , unsigned char * V_106 )
{
if ( V_85 == 0x00 && ( V_106 [ 0 ] != V_372 || V_106 [ 1 ] != V_373 ) )
return - V_8 ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_39 ;
V_39 = F_183 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_54 = true ;
V_5 -> V_93 . V_269 =
F_214 ;
V_5 -> V_93 . V_279 = F_215 ;
return 0 ;
}
static void F_217 ( struct V_1 * V_2 , unsigned int V_183 )
{
unsigned int V_32 ;
V_32 = F_19 ( V_2 , V_374 , 0 ,
V_375 , 0 ) ;
V_32 = ( V_32 >> 24 ) & 0xff ;
F_21 ( V_2 , V_374 , 0 ,
V_376 ,
( V_183 >> 0 ) & 0xff ) ;
F_21 ( V_2 , V_374 , 0 ,
V_377 ,
( V_183 >> 8 ) & 0xff ) ;
F_21 ( V_2 , V_374 , 0 ,
V_378 , 0 ) ;
if ( V_183 == 0 )
V_32 &= ~ V_379 ;
else
V_32 |= V_379 ;
V_32 ^= V_380 ;
F_21 ( V_2 , V_374 , 0 ,
V_381 , V_32 ) ;
}
static int F_218 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_200 * V_201 )
{
int V_39 ;
V_39 = F_130 ( V_10 , V_2 , V_182 ,
V_183 , V_201 ) ;
if ( V_39 < 0 )
return V_39 ;
F_217 ( V_2 , V_183 ) ;
return 0 ;
}
static int F_219 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
F_217 ( V_2 , 0 ) ;
return F_132 ( V_10 , V_2 , V_201 ) ;
}
static struct V_280 * F_220 ( struct V_1 * V_2 , int type )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_77 ;
for ( V_77 = 0 ; V_77 < V_5 -> V_7 ; V_77 ++ ) {
struct V_280 * V_294 = F_5 ( V_5 , V_77 ) ;
if ( V_294 -> V_283 == type )
return V_294 ;
}
return NULL ;
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_9 * V_11 ;
struct V_280 * V_294 ;
int V_39 ;
V_39 = F_145 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_294 = F_220 ( V_2 , V_284 ) ;
if ( ! V_294 )
return - V_193 ;
V_11 = & V_294 -> V_11 [ V_286 ] ;
V_11 -> V_93 . V_382 = F_218 ;
V_11 -> V_93 . V_383 = F_219 ;
return 0 ;
}
static int F_222 ( struct V_1 * V_2 )
{
int V_39 ;
V_39 = F_183 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_2 -> V_303 . V_369 = F_221 ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 , T_1 V_147 ,
unsigned char * V_87 , int * V_29 )
{
return F_224 ( V_2 , V_147 , V_87 , V_29 ,
F_225 ( V_2 ) ) ;
}
static void F_226 ( struct V_1 * V_2 , T_1 V_3 , int V_85 ,
int V_133 , int V_134 )
{
F_21 ( V_2 , V_3 , 0 , V_384 , V_85 ) ;
}
static int F_227 ( int V_108 )
{
switch ( V_108 ) {
case 2 : return 3 ;
case 3 : return 2 ;
default: break;
}
return V_108 ;
}
static int F_228 ( int V_85 , int V_58 , unsigned char * V_106 )
{
struct V_79 * V_261 ;
int V_77 , V_78 ;
V_261 = & V_81 [ F_37 ( V_85 ) ] ;
for ( V_77 = 0 ; V_77 < V_58 ; ++ V_77 ) {
int V_109 = F_45 ( V_106 [ V_77 ] ) ;
bool V_385 = false ;
bool V_386 = false ;
if ( ! V_109 )
continue;
for ( V_78 = 0 + V_77 % 2 ; V_78 < 8 ; V_78 += 2 ) {
int V_387 = 7 - F_227 ( V_78 ) ;
if ( V_261 -> V_84 [ V_387 ] == V_109 ) {
V_385 = true ;
if ( V_77 % 2 == 0 && V_77 + 1 < V_58 ) {
int V_388 = 7 - F_227 ( V_78 + 1 ) ;
int V_389 = F_45 ( V_106 [ V_77 + 1 ] ) ;
int V_390 = V_261 -> V_84 [ V_388 ] ;
if ( V_389 == V_390 )
V_386 = true ;
else
return - V_8 ;
}
break;
}
}
if ( ! V_385 )
return - V_8 ;
if ( V_386 )
V_77 ++ ;
}
return 0 ;
}
static int F_229 ( struct V_1 * V_2 , T_1 V_3 ,
int V_100 , int V_391 )
{
int V_392 ;
int V_393 = 0 ;
if ( V_100 > 7 )
return - V_8 ;
if ( ! F_230 ( V_2 ) ) {
V_100 = F_227 ( V_100 ) ;
if ( V_100 % 2 != 0 && V_391 == 0xf )
return 0 ;
V_100 -= V_100 % 2 ;
if ( V_391 != 0xf )
V_391 -= V_391 % 2 ;
}
V_392 = V_394 + V_100 / 2 + ( V_100 % 2 ) * 0x00e ;
if ( V_391 != 0xf )
V_393 = ( V_391 << 4 ) | V_395 ;
return F_21 ( V_2 , V_3 , 0 , V_392 , V_393 ) ;
}
static int F_231 ( struct V_1 * V_2 , T_1 V_3 ,
int V_116 )
{
bool V_396 = false ;
int V_397 = V_116 ;
int V_392 ;
int V_393 ;
if ( V_116 > 7 )
return - V_8 ;
if ( ! F_230 ( V_2 ) ) {
V_397 = F_227 ( V_116 ) ;
if ( V_397 % 2 != 0 ) {
V_397 -= 1 ;
V_396 = true ;
}
}
V_392 = V_398 + V_397 / 2 + ( V_397 % 2 ) * 0x00e ;
V_393 = F_19 ( V_2 , V_3 , 0 , V_392 , 0 ) ;
if ( ! ( V_393 & V_395 ) )
return 0xf ;
return ( ( V_393 & 0xf0 ) >> 4 ) + ! ! V_396 ;
}
static int F_232 ( struct V_79 * V_261 ,
int V_82 )
{
int V_69 ;
int V_399 = 0 ;
if ( ( V_82 % 2 ) != 0 )
return - 1 ;
for ( V_69 = 0 ; V_69 < 7 ; V_69 += 2 ) {
if ( V_261 -> V_84 [ V_69 ] || V_261 -> V_84 [ V_69 + 1 ] )
V_399 ++ ;
}
if ( V_399 * 2 != V_82 )
return - 1 ;
return V_400 ;
}
static void F_233 ( struct V_79 * V_261 ,
unsigned int * V_145 , int V_82 )
{
int V_27 = 0 ;
int V_69 ;
for ( V_69 = 7 ; V_69 >= 0 ; V_69 -- ) {
int V_348 = 7 - F_227 ( 7 - V_69 ) ;
int V_110 = V_261 -> V_84 [ V_348 ] ;
if ( ! V_110 ) {
if ( V_261 -> V_84 [ V_348 + ( V_348 % 2 ? - 1 : 1 ) ] )
V_145 [ V_27 ++ ] = V_401 ;
continue;
}
V_145 [ V_27 ++ ] = F_47 ( V_110 ) ;
}
F_44 ( V_27 != V_82 ) ;
}
static int F_234 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_174 )
{
int V_402 , V_403 ;
V_402 = F_19 ( V_2 , V_3 , 0 , V_404 , 0 ) ;
if ( V_402 >= 0 && ( V_402 & V_405 ) ) {
if ( V_174 )
V_403 = V_402 | V_406 ;
else
V_403 = V_402 & ~ V_406 ;
F_40 ( V_2 ,
L_32 ,
V_3 ,
V_402 == V_403 ? L_19 : L_20 ,
V_403 ) ;
if ( V_402 != V_403 )
F_21 ( V_2 , V_3 , 0 ,
V_407 ,
V_403 ) ;
} else if ( V_174 )
return - V_8 ;
return 0 ;
}
static int F_235 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_3 , T_3 V_182 , int V_183 )
{
if ( F_225 ( V_2 ) ) {
int V_408 = 180 ;
if ( V_183 & V_409 )
V_408 = 0 ;
F_21 ( V_2 , V_12 , 0 , V_410 , V_408 ) ;
}
return F_81 ( V_2 , V_12 , V_3 , V_182 , V_183 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 , V_39 ;
V_39 = F_159 ( V_2 ) ;
if ( V_39 )
return V_39 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 , V_411 , 0 ) ;
if ( F_230 ( V_2 ) )
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_412 ,
V_413 ) ;
}
return 0 ;
}
static int F_237 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_187 * V_188 ;
int V_39 , V_13 ;
V_39 = F_183 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_2 -> V_303 . V_304 = F_236 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_93 . V_228 = F_223 ;
V_5 -> V_93 . V_94 = F_231 ;
V_5 -> V_93 . V_102 = F_229 ;
V_5 -> V_93 . V_146 = F_226 ;
V_5 -> V_93 . V_184 = F_234 ;
V_5 -> V_93 . V_256 = F_235 ;
if ( ! F_230 ( V_2 ) ) {
V_5 -> V_93 . V_269 =
F_232 ;
V_5 -> V_93 . V_271 = F_233 ;
V_5 -> V_93 . V_279 = F_228 ;
}
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_188 = F_7 ( V_5 , V_13 ) ;
V_188 -> V_205 = V_259 ( V_188 -> V_205 , 8u ) ;
V_188 -> V_206 |= V_363 ;
V_188 -> V_207 |= V_365 ;
V_188 -> V_208 = V_259 ( V_188 -> V_208 , 24u ) ;
}
V_5 -> V_205 = V_259 ( V_5 -> V_205 , 8u ) ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 )
{
return F_206 ( V_2 , V_414 , V_415 ) ;
}
