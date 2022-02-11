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
if ( V_22 -> V_29 > F_13 ( V_31 -> V_32 . V_33 . V_34 ) ) {
F_11 ( & V_20 -> V_26 ) ;
F_14 () ;
return - V_8 ;
}
memset ( V_31 -> V_32 . V_33 . V_34 , 0 ,
F_13 ( V_31 -> V_32 . V_33 . V_34 ) ) ;
if ( V_22 -> V_28 )
memcpy ( V_31 -> V_32 . V_33 . V_34 , V_22 -> V_35 ,
V_22 -> V_29 ) ;
F_11 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_6 ,
int V_36 )
{
struct V_15 * V_37 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 ;
V_37 = F_16 ( & V_39 , V_2 ) ;
if ( ! V_37 )
return - V_40 ;
V_37 -> V_24 = V_6 ;
V_37 -> V_41 . V_36 = V_36 ;
V_38 = F_17 ( V_2 , F_2 ( V_5 , V_6 ) -> V_3 , V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
F_2 ( V_5 , V_6 ) -> V_42 = V_37 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_3 ,
int * V_43 , int * V_44 )
{
int V_45 ;
V_45 = F_19 ( V_2 , V_3 , 0 ,
V_46 , 0 ) ;
* V_43 = V_45 >> 5 ;
* V_44 = V_45 & 0x1f ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_3 ,
int V_43 , int V_44 )
{
int V_45 ;
V_45 = ( V_43 << 5 ) | ( V_44 & 0x1f ) ;
F_21 ( V_2 , V_3 , 0 , V_47 , V_45 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_45 )
{
F_21 ( V_2 , V_3 , 0 , V_48 , V_45 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_49 ;
if ( F_24 ( V_2 , V_3 ) & V_50 )
F_21 ( V_2 , V_3 , 0 ,
V_51 , V_52 ) ;
if ( V_5 -> V_53 )
V_49 = 0 ;
else
V_49 = V_54 ;
F_21 ( V_2 , V_3 , 0 ,
V_55 , V_49 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_12 )
{
return 1 + F_19 ( V_2 , V_12 , 0 ,
V_56 , 0 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_1 V_12 , int V_57 )
{
if ( V_57 != F_25 ( V_2 , V_12 ) )
F_21 ( V_2 , V_12 , 0 ,
V_58 , V_57 - 1 ) ;
}
static void F_27 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_19 * V_20 = V_60 -> V_63 ;
F_10 ( & V_20 -> V_26 ) ;
F_28 ( & V_20 -> V_25 , V_62 ) ;
F_11 ( & V_20 -> V_26 ) ;
}
static void F_29 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_19 * V_20 = V_60 -> V_63 ;
F_10 ( & V_20 -> V_26 ) ;
F_30 ( & V_20 -> V_25 , V_62 ) ;
F_11 ( & V_20 -> V_26 ) ;
}
static int F_31 ( struct V_19 * V_20 , int V_64 )
{
char V_65 [ 32 ] ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_59 * V_60 ;
int V_38 ;
snprintf ( V_65 , sizeof( V_65 ) , L_4 , V_2 -> V_66 , V_64 ) ;
V_38 = F_32 ( V_2 -> V_67 -> V_68 , V_65 , & V_60 ) ;
if ( V_38 < 0 )
return V_38 ;
F_33 ( V_60 , V_20 , F_27 ) ;
V_60 -> V_69 . V_70 . V_71 = F_29 ;
V_60 -> V_72 |= V_73 ;
V_20 -> V_74 = V_60 ;
return 0 ;
}
static void F_34 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_2 -> V_67 -> V_75 && V_20 -> V_74 ) {
F_35 ( V_20 -> V_2 -> V_67 -> V_68 , V_20 -> V_74 ) ;
V_20 -> V_74 = NULL ;
}
}
static inline int F_31 ( struct V_19 * V_20 ,
int V_64 )
{
return 0 ;
}
static inline void F_34 ( struct V_19 * V_20 )
{
}
static void F_36 ( void )
{
int V_76 , V_77 ;
struct V_78 * V_79 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ ) {
V_79 = V_80 + V_76 ;
V_79 -> V_81 = 0 ;
V_79 -> V_82 = 0 ;
for ( V_77 = 0 ; V_77 < F_13 ( V_79 -> V_83 ) ; V_77 ++ )
if ( V_79 -> V_83 [ V_77 ] ) {
V_79 -> V_81 ++ ;
V_79 -> V_82 |= V_79 -> V_83 [ V_77 ] ;
}
}
}
static int F_37 ( int V_84 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ ) {
if ( V_80 [ V_76 ] . V_85 == V_84 )
break;
}
return V_76 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_21 * V_22 , int V_81 )
{
int V_76 ;
int V_84 = 0 ;
int V_82 = 0 ;
char V_86 [ V_87 ] ;
if ( V_81 <= 2 )
return 0 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_88 ) ; V_76 ++ ) {
if ( V_22 -> V_89 . V_90 & ( 1 << V_76 ) )
V_82 |= V_88 [ V_76 ] ;
}
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ ) {
if ( V_81 == V_80 [ V_76 ] . V_81 &&
( V_82 & V_80 [ V_76 ] . V_82 ) ==
V_80 [ V_76 ] . V_82 ) {
V_84 = V_80 [ V_76 ] . V_85 ;
break;
}
}
if ( ! V_84 ) {
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ ) {
if ( V_81 == V_80 [ V_76 ] . V_81 ) {
V_84 = V_80 [ V_76 ] . V_85 ;
break;
}
}
}
F_39 ( V_22 -> V_89 . V_90 , V_86 , sizeof( V_86 ) ) ;
F_40 ( V_2 , L_5 ,
V_84 , V_81 , V_86 ) ;
return V_84 ;
}
static void F_41 ( struct V_1 * V_2 ,
T_1 V_3 )
{
#ifdef F_42
struct V_4 * V_5 = V_2 -> V_5 ;
int V_76 ;
int V_91 ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_91 = V_5 -> V_92 . V_93 ( V_2 , V_3 , V_76 ) ;
F_40 ( V_2 , L_6 ,
V_91 , V_76 ) ;
}
#endif
}
static void F_43 ( struct V_1 * V_2 ,
T_1 V_3 ,
bool V_94 ,
int V_84 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_78 * V_95 ;
int V_76 ;
int V_38 ;
int V_96 ;
int V_97 [ 8 ] ;
V_96 = F_37 ( V_84 ) ;
V_95 = & V_80 [ V_96 ] ;
if ( V_98 [ V_84 ] [ 1 ] == 0 ) {
int V_99 = 0 ;
for ( V_76 = 0 ; V_76 < V_95 -> V_81 ; V_76 ++ ) {
while ( ! V_95 -> V_83 [ 7 - V_99 ] && ! F_44 ( V_99 >= 8 ) )
V_99 ++ ;
V_98 [ V_84 ] [ V_76 ] = ( V_76 << 4 ) | V_99 ++ ;
}
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ )
if ( ! V_95 -> V_83 [ 7 - V_99 ] )
V_98 [ V_84 ] [ V_76 ++ ] = ( 0xf << 4 ) | V_99 ;
}
if ( V_94 ) {
for ( V_76 = 0 ; V_76 < V_95 -> V_81 ; V_76 ++ )
V_97 [ V_76 ] = ( V_76 << 4 ) | V_76 ;
for (; V_76 < 8 ; V_76 ++ )
V_97 [ V_76 ] = ( 0xf << 4 ) | V_76 ;
}
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
int V_100 = V_94 ? V_97 [ V_76 ] : V_98 [ V_84 ] [ V_76 ] ;
int V_99 = V_100 & 0x0f ;
int V_91 = ( V_100 & 0xf0 ) >> 4 ;
V_38 = V_5 -> V_92 . V_101 ( V_2 , V_3 , V_99 , V_91 ) ;
if ( V_38 ) {
F_40 ( V_2 , L_7 ) ;
break;
}
}
}
static int F_45 ( unsigned char V_69 )
{
struct V_102 * V_103 = V_104 ;
for (; V_103 -> V_105 ; V_103 ++ ) {
if ( V_103 -> V_105 == V_69 )
return V_103 -> V_82 ;
}
return 0 ;
}
static int F_46 ( int V_106 , unsigned char V_107 )
{
int V_108 = F_45 ( V_107 ) ;
int V_76 ;
if ( V_108 ) {
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
if ( V_80 [ V_106 ] . V_83 [ 7 - V_76 ] == V_108 )
return V_76 ;
}
}
return - 1 ;
}
static int F_47 ( int V_109 )
{
struct V_102 * V_103 = V_104 ;
for (; V_103 -> V_105 ; V_103 ++ ) {
if ( V_103 -> V_82 == V_109 )
return V_103 -> V_105 ;
}
return 0 ;
}
static int F_48 ( int V_106 , unsigned char V_110 )
{
int V_108 = V_80 [ V_106 ] . V_83 [ 7 - V_110 ] ;
return F_47 ( V_108 ) ;
}
static int F_49 ( int V_57 , unsigned char * V_105 )
{
int V_76 , V_111 = 0 , V_82 = 0 ;
for ( V_76 = 0 ; V_76 < V_57 ; V_76 ++ ) {
int V_108 = F_45 ( V_105 [ V_76 ] ) ;
if ( V_108 ) {
V_82 |= V_108 ;
V_111 ++ ;
}
}
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ ) {
if ( ( V_57 == V_80 [ V_76 ] . V_81 ||
V_111 == V_80 [ V_76 ] . V_81 ) &&
( V_82 & V_80 [ V_76 ] . V_82 ) ==
V_80 [ V_76 ] . V_82 )
return V_80 [ V_76 ] . V_85 ;
}
return - 1 ;
}
static int F_50 ( struct V_1 * V_2 ,
T_1 V_3 ,
int V_57 , unsigned char * V_105 ,
int V_84 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_106 = F_37 ( V_84 ) ;
int V_112 , V_99 ;
int V_113 [ 8 ] = { [ 0 ... 7 ] = 0xf } ;
for ( V_112 = 0 ; V_112 < V_57 ; V_112 ++ ) {
V_99 = F_46 ( V_106 , V_105 [ V_112 ] ) ;
if ( V_99 < 0 )
continue;
V_113 [ V_99 ] = V_112 ;
}
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ ) {
int V_38 ;
V_38 = V_5 -> V_92 . V_101 ( V_2 , V_3 , V_99 ,
V_113 [ V_99 ] ) ;
if ( V_38 )
return - V_8 ;
}
return 0 ;
}
static void F_51 ( unsigned char * V_105 , int V_84 )
{
int V_76 ;
int V_106 = F_37 ( V_84 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
if ( V_76 < V_80 [ V_106 ] . V_81 )
V_105 [ V_76 ] = F_48 ( V_106 , V_98 [ V_84 ] [ V_76 ] & 0x0f ) ;
else
V_105 [ V_76 ] = 0 ;
}
}
static void F_52 ( struct V_1 * V_2 ,
T_1 V_3 , bool V_94 , int V_84 ,
int V_81 , unsigned char * V_105 ,
bool V_114 )
{
if ( ! V_94 && V_114 ) {
F_50 ( V_2 , V_3 ,
V_81 , V_105 , V_84 ) ;
} else {
F_43 ( V_2 , V_3 , V_94 , V_84 ) ;
F_51 ( V_105 , V_84 ) ;
}
F_41 ( V_2 , V_3 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_3 ,
int V_115 , int V_91 )
{
return F_21 ( V_2 , V_3 , 0 ,
V_116 ,
( V_91 << 4 ) | V_115 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_3 ,
int V_115 )
{
return ( F_19 ( V_2 , V_3 , 0 ,
V_117 ,
V_115 ) & 0xf0 ) >> 4 ;
}
static void F_55 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_2 , V_3 , 0 , V_118 ,
V_119 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_2 , V_3 , 0 , V_118 ,
V_120 ) ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_3 )
{
#ifdef F_42
int V_76 ;
int V_121 ;
V_121 = F_58 ( V_2 , V_3 ) ;
F_40 ( V_2 , L_8 , V_121 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_121 = F_19 ( V_2 , V_3 , 0 ,
V_122 , V_76 ) ;
F_40 ( V_2 , L_9 , V_76 , V_121 ) ;
}
#endif
}
static void F_59 ( struct V_1 * V_2 , T_1 V_3 )
{
#ifdef F_60
int V_76 , V_77 ;
int V_121 ;
int V_123 , V_124 ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_121 = F_19 ( V_2 , V_3 , 0 ,
V_122 , V_76 ) ;
if ( V_121 == 0 )
continue;
F_20 ( V_2 , V_3 , V_76 , 0x0 ) ;
for ( V_77 = 1 ; V_77 < 1000 ; V_77 ++ ) {
F_22 ( V_2 , V_3 , 0x0 ) ;
F_18 ( V_2 , V_3 , & V_123 , & V_124 ) ;
if ( V_123 != V_76 )
F_40 ( V_2 , L_10 ,
V_124 , V_123 , V_76 ) ;
if ( V_124 == 0 )
break;
}
F_40 ( V_2 ,
L_11 ,
V_76 , V_121 , V_77 ) ;
}
#endif
}
static void F_61 ( struct V_125 * V_126 )
{
T_2 * V_33 = ( T_2 * ) V_126 ;
T_2 V_127 = 0 ;
int V_76 ;
V_126 -> V_128 = 0 ;
for ( V_76 = 0 ; V_76 < sizeof( * V_126 ) ; V_76 ++ )
V_127 += V_33 [ V_76 ] ;
V_126 -> V_128 = - V_127 ;
}
static void F_62 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_129 , int V_121 )
{
int V_76 ;
F_57 ( V_2 , V_3 ) ;
F_59 ( V_2 , V_3 ) ;
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
for ( V_76 = 0 ; V_76 < V_121 ; V_76 ++ )
F_22 ( V_2 , V_3 , V_129 [ V_76 ] ) ;
}
static bool F_63 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_129 , int V_121 )
{
T_2 V_45 ;
int V_76 ;
if ( F_19 ( V_2 , V_3 , 0 , V_130 , 0 )
!= V_119 )
return false ;
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
for ( V_76 = 0 ; V_76 < V_121 ; V_76 ++ ) {
V_45 = F_19 ( V_2 , V_3 , 0 ,
V_131 , 0 ) ;
if ( V_45 != V_129 [ V_76 ] )
return false ;
}
return true ;
}
static void F_64 ( struct V_1 * V_2 ,
T_1 V_3 ,
int V_84 , int V_132 ,
int V_133 )
{
union V_134 V_135 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
if ( V_133 == 0 ) {
struct V_125 * V_126 = & V_135 . V_136 ;
V_126 -> type = 0x84 ;
V_126 -> V_137 = 0x01 ;
V_126 -> V_138 = 0x0a ;
V_126 -> V_139 = V_132 - 1 ;
V_126 -> V_140 = V_84 ;
F_61 ( V_126 ) ;
} else if ( V_133 == 1 ) {
struct V_141 * V_142 = & V_135 . V_143 ;
V_142 -> type = 0x84 ;
V_142 -> V_138 = 0x1b ;
V_142 -> V_137 = 0x11 << 2 ;
V_142 -> V_139 = V_132 - 1 ;
V_142 -> V_140 = V_84 ;
} else {
F_40 ( V_2 , L_12 ,
V_3 ) ;
return;
}
if ( ! F_63 ( V_2 , V_3 , V_135 . V_33 ,
sizeof( V_135 ) ) ) {
F_40 ( V_2 ,
L_13 ,
V_3 ,
V_132 , V_84 ) ;
F_56 ( V_2 , V_3 ) ;
F_62 ( V_2 , V_3 ,
V_135 . V_33 , sizeof( V_135 ) ) ;
F_55 ( V_2 , V_3 ) ;
}
}
static void F_65 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
bool V_94 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_3 = V_20 -> V_3 ;
int V_81 = V_20 -> V_81 ;
int V_132 ;
struct V_21 * V_22 ;
int V_84 , V_106 ;
if ( ! V_81 )
return;
if ( F_66 ( V_2 ) )
F_21 ( V_2 , V_3 , 0 ,
V_51 ,
V_52 ) ;
V_22 = & V_20 -> V_25 ;
if ( ! V_94 && V_20 -> V_114 )
V_84 = F_49 ( V_81 , V_20 -> V_144 ) ;
else
V_84 = F_38 ( V_2 , V_22 , V_81 ) ;
if ( V_84 < 0 )
V_84 = 0 ;
V_106 = F_37 ( V_84 ) ;
V_132 = V_80 [ V_106 ] . V_81 ;
F_26 ( V_2 , V_20 -> V_12 , V_132 ) ;
F_52 ( V_2 , V_3 , V_94 , V_84 ,
V_81 , V_20 -> V_144 ,
V_20 -> V_114 ) ;
V_5 -> V_92 . V_145 ( V_2 , V_3 , V_84 , V_132 ,
V_22 -> V_89 . V_133 ) ;
V_20 -> V_94 = V_94 ;
}
static void F_67 ( struct V_1 * V_2 , T_1 V_146 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = F_1 ( V_2 , V_146 ) ;
if ( V_6 < 0 )
return;
if ( F_68 ( F_2 ( V_5 , V_6 ) , 1 ) )
F_69 ( V_2 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
F_67 ( V_2 , V_148 -> V_149 -> V_146 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_150 )
{
int V_151 = V_150 >> V_152 ;
struct V_153 * V_148 ;
int V_154 = ( V_150 & V_155 ) >> V_156 ;
V_148 = F_72 ( V_2 , V_151 ) ;
if ( ! V_148 )
return;
V_148 -> V_157 = 1 ;
F_40 ( V_2 ,
L_14 ,
V_2 -> V_66 , V_148 -> V_146 , V_154 , ! ! ( V_150 & V_158 ) ,
! ! ( V_150 & V_159 ) , ! ! ( V_150 & V_160 ) ) ;
F_67 ( V_2 , V_148 -> V_146 ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned int V_150 )
{
int V_151 = V_150 >> V_152 ;
int V_161 = ( V_150 & V_162 ) >> V_163 ;
int V_164 = ! ! ( V_150 & V_165 ) ;
int V_166 = ! ! ( V_150 & V_167 ) ;
F_74 ( V_2 ,
L_15 ,
V_2 -> V_66 ,
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
T_1 V_12 , T_1 V_146 )
{
int V_168 ;
if ( ! F_77 ( V_2 , V_12 , V_169 ) )
F_21 ( V_2 , V_12 , 0 , V_170 , V_169 ) ;
if ( ! F_77 ( V_2 , V_146 , V_169 ) ) {
F_21 ( V_2 , V_146 , 0 , V_170 ,
V_169 ) ;
F_78 ( 40 ) ;
V_168 = F_19 ( V_2 , V_146 , 0 , V_171 , 0 ) ;
V_168 = ( V_168 & V_172 ) >> V_173 ;
F_40 ( V_2 , L_17 , V_146 , V_168 ) ;
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
V_55 ,
V_176 ) ;
} else if ( V_174 )
return - V_8 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_3 , T_3 V_182 , int V_183 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 ;
if ( F_66 ( V_2 ) )
F_76 ( V_2 , V_12 , V_3 ) ;
V_38 = V_5 -> V_92 . V_184 ( V_2 , V_3 , F_82 ( V_183 ) ) ;
if ( V_38 ) {
F_40 ( V_2 , L_21 ) ;
return V_38 ;
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
T_1 V_146 , V_197 ;
int V_13 , V_194 ;
struct V_187 * V_188 ;
V_197 = V_2 -> V_198 + V_2 -> V_199 ;
for ( V_146 = V_2 -> V_198 ; V_146 < V_197 ; V_146 ++ ) {
unsigned int V_200 = F_24 ( V_2 , V_146 ) ;
unsigned int V_201 = F_88 ( V_200 ) ;
if ( V_201 != V_202 )
continue;
if ( V_146 == V_3 )
continue;
V_194 = F_19 ( V_2 , V_146 , 0 ,
V_195 , 0 ) ;
if ( V_194 != V_189 )
continue;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_188 = F_7 ( V_5 , V_13 ) ;
if ( ! V_188 -> V_190 ) {
F_40 ( V_2 ,
L_22 ,
V_13 , V_146 ) ;
F_86 ( V_2 , V_146 , 0 ,
V_196 ,
V_13 ) ;
break;
}
}
}
}
static int F_89 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_205 * V_206 = V_204 -> V_206 ;
int V_6 , V_13 , V_189 = 0 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_187 * V_188 = NULL ;
int V_38 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_90 ( V_6 < 0 ) )
return - V_8 ;
V_20 = F_2 ( V_5 , V_6 ) ;
V_22 = & V_20 -> V_25 ;
V_38 = F_84 ( V_2 , V_6 , & V_13 , & V_189 ) ;
if ( V_38 < 0 )
return V_38 ;
V_188 = F_7 ( V_5 , V_13 ) ;
V_188 -> V_190 = 1 ;
V_20 -> V_12 = V_188 -> V_12 ;
V_10 -> V_146 = V_188 -> V_12 ;
F_86 ( V_2 , V_20 -> V_3 , 0 ,
V_196 ,
V_189 ) ;
if ( F_66 ( V_2 ) || F_91 ( V_2 ) )
F_87 ( V_2 , V_20 -> V_3 , V_189 ) ;
F_92 ( V_2 , V_6 , V_188 -> V_12 ) ;
V_10 -> V_207 = V_188 -> V_207 ;
V_10 -> V_208 = V_188 -> V_208 ;
V_10 -> V_209 = V_188 -> V_209 ;
V_10 -> V_210 = V_188 -> V_210 ;
V_10 -> V_211 = V_188 -> V_211 ;
if ( ! V_212 && V_22 -> V_28 ) {
F_93 ( & V_22 -> V_89 , V_10 ) ;
if ( V_10 -> V_207 > V_10 -> V_208 ||
! V_10 -> V_209 || ! V_10 -> V_210 ) {
V_188 -> V_190 = 0 ;
V_10 -> V_146 = 0 ;
F_94 ( V_2 , V_6 ) ;
return - V_193 ;
}
}
V_206 -> V_213 . V_207 = V_10 -> V_207 ;
V_206 -> V_213 . V_208 = V_10 -> V_208 ;
V_206 -> V_213 . V_210 = V_10 -> V_210 ;
V_206 -> V_213 . V_209 = V_10 -> V_209 ;
F_95 ( V_204 -> V_206 , 0 ,
V_214 , 2 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
if ( ! ( F_24 ( V_2 , V_3 ) & V_215 ) ) {
F_3 ( V_2 ,
L_23 ,
V_3 , F_24 ( V_2 , V_3 ) ) ;
return - V_8 ;
}
V_20 -> V_191 = F_97 ( V_2 , V_3 ,
V_20 -> V_192 ,
V_216 ) ;
return 0 ;
}
static bool F_68 ( struct V_19 * V_20 , int V_217 )
{
struct V_153 * V_148 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_22 = & V_5 -> V_218 ;
struct V_21 * V_219 = & V_20 -> V_25 ;
T_1 V_3 = V_20 -> V_3 ;
int V_220 ;
bool V_221 = false ;
bool V_222 = false ;
bool V_223 ;
F_98 ( V_2 ) ;
V_220 = F_99 ( V_2 , V_3 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_219 -> V_224 = ! ! ( V_220 & V_225 ) ;
if ( V_219 -> V_224 )
V_22 -> V_28 = ! ! ( V_220 & V_226 ) ;
else
V_22 -> V_28 = false ;
F_40 ( V_2 ,
L_24 ,
V_2 -> V_66 , V_3 , V_219 -> V_224 , V_22 -> V_28 ) ;
if ( V_22 -> V_28 ) {
if ( V_5 -> V_92 . V_227 ( V_2 , V_3 , V_22 -> V_35 ,
& V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
else {
memset ( & V_22 -> V_89 , 0 , sizeof( struct V_228 ) ) ;
if ( F_100 ( V_2 , & V_22 -> V_89 , V_22 -> V_35 ,
V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
}
if ( V_22 -> V_28 ) {
F_101 ( V_2 , & V_22 -> V_89 ) ;
V_221 = true ;
}
else if ( V_217 ) {
F_102 ( V_2 -> V_67 -> V_229 ,
& V_20 -> V_230 ,
F_103 ( 300 ) ) ;
goto V_231;
}
}
if ( V_219 -> V_28 != V_22 -> V_28 )
V_222 = true ;
if ( V_219 -> V_28 && ! V_22 -> V_28 )
V_221 = true ;
if ( V_221 ) {
bool V_232 = V_219 -> V_28 ;
V_219 -> V_28 = V_22 -> V_28 ;
if ( V_219 -> V_29 != V_22 -> V_29 ||
memcmp ( V_219 -> V_35 , V_22 -> V_35 ,
V_22 -> V_29 ) != 0 ) {
memcpy ( V_219 -> V_35 , V_22 -> V_35 ,
V_22 -> V_29 ) ;
V_222 = true ;
}
V_219 -> V_29 = V_22 -> V_29 ;
V_219 -> V_89 = V_22 -> V_89 ;
if ( V_22 -> V_28 && ! V_232 && V_20 -> V_233 ) {
if ( F_66 ( V_2 ) ||
F_91 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_3 ,
V_20 -> V_189 ) ;
}
F_65 ( V_2 , V_20 ,
V_20 -> V_94 ) ;
}
}
if ( V_222 )
F_104 ( V_2 -> V_67 -> V_68 ,
V_234 | V_235 ,
& V_20 -> V_42 -> V_41 ) ;
V_231:
V_223 = ! V_217 || ! V_219 -> V_224 || V_219 -> V_28 ;
V_148 = F_105 ( V_2 , V_3 ) ;
if ( V_148 )
V_148 -> V_236 = ! V_223 ;
F_11 ( & V_20 -> V_26 ) ;
F_106 ( V_2 ) ;
return V_223 ;
}
static void F_107 ( struct V_237 * V_230 )
{
struct V_19 * V_20 =
F_108 ( F_109 ( V_230 ) , struct V_19 , V_230 ) ;
if ( V_20 -> V_238 ++ > 6 )
V_20 -> V_238 = 0 ;
if ( F_68 ( V_20 , V_20 -> V_238 ) )
F_69 ( V_20 -> V_2 ) ;
}
static int F_110 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_239 , V_240 ;
int V_6 ;
struct V_19 * V_20 ;
int V_38 ;
V_239 = F_80 ( V_2 , V_3 ) ;
if ( ! ( V_239 & ( V_241 | V_242 ) ) )
return 0 ;
V_240 = F_111 ( V_2 , V_3 ) ;
if ( F_112 ( V_240 ) == V_243 )
return 0 ;
if ( F_66 ( V_2 ) )
F_113 ( V_2 , V_3 ) ;
V_6 = V_5 -> V_7 ;
V_20 = F_114 ( & V_5 -> V_244 ) ;
if ( ! V_20 )
return - V_40 ;
V_20 -> V_3 = V_3 ;
V_20 -> V_94 = false ;
V_38 = F_96 ( V_2 , V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_5 -> V_7 ++ ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_187 * V_188 ;
unsigned int V_245 ;
int V_38 ;
V_245 = F_24 ( V_2 , V_12 ) ;
V_245 = F_116 ( V_245 ) ;
V_188 = F_114 ( & V_5 -> V_246 ) ;
if ( ! V_188 )
return - V_40 ;
V_188 -> V_12 = V_12 ;
V_188 -> V_207 = 2 ;
if ( V_245 <= 16 ) {
V_188 -> V_208 = V_245 ;
if ( V_245 > V_5 -> V_208 )
V_5 -> V_208 = V_245 ;
}
V_38 = F_117 ( V_2 , V_12 ,
& V_188 -> V_209 ,
& V_188 -> V_210 ,
& V_188 -> V_211 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_5 -> V_14 < F_13 ( V_5 -> V_247 ) )
V_5 -> V_247 [ V_5 -> V_14 ] = V_12 ;
V_5 -> V_14 ++ ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
T_1 V_146 ;
int V_76 , V_248 ;
V_248 = F_119 ( V_2 , V_2 -> V_249 , & V_146 ) ;
if ( ! V_146 || V_248 < 0 ) {
F_3 ( V_2 , L_25 ) ;
return - V_8 ;
}
for ( V_76 = 0 ; V_76 < V_248 ; V_76 ++ , V_146 ++ ) {
unsigned int V_239 ;
unsigned int type ;
V_239 = F_24 ( V_2 , V_146 ) ;
type = F_88 ( V_239 ) ;
if ( ! ( V_239 & V_250 ) )
continue;
switch ( type ) {
case V_251 :
F_115 ( V_2 , V_146 ) ;
break;
case V_202 :
F_110 ( V_2 , V_146 ) ;
break;
}
}
return 0 ;
}
static bool F_120 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_252 * V_253 ;
bool V_94 ;
F_10 ( & V_2 -> V_254 ) ;
V_253 = F_121 ( V_2 , V_12 ) ;
V_94 = ! ! ( V_253 -> V_255 & V_256 ) ;
F_11 ( & V_2 -> V_254 ) ;
return V_94 ;
}
static int F_122 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_203 * V_204 )
{
T_1 V_12 = V_10 -> V_146 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = F_4 ( V_2 , V_10 ) ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
bool V_94 ;
int V_175 ;
if ( F_66 ( V_2 ) || F_91 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_3 , V_20 -> V_189 ) ;
}
V_94 = F_120 ( V_2 , V_12 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_81 = V_204 -> V_206 -> V_81 ;
V_20 -> V_233 = true ;
F_65 ( V_2 , V_20 , V_94 ) ;
F_11 ( & V_20 -> V_26 ) ;
if ( V_5 -> V_53 ) {
V_175 = F_19 ( V_2 , V_3 , 0 ,
V_178 , 0 ) ;
F_21 ( V_2 , V_3 , 0 ,
V_55 ,
V_175 | V_54 ) ;
}
return V_5 -> V_92 . V_257 ( V_2 , V_12 , V_3 , V_182 , V_183 ) ;
}
static int F_123 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_203 * V_204 )
{
F_124 ( V_2 , V_10 -> V_146 ) ;
return 0 ;
}
static int F_125 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_13 , V_6 ;
struct V_187 * V_188 ;
struct V_19 * V_20 ;
int V_175 ;
if ( V_10 -> V_146 ) {
V_13 = F_6 ( V_2 , V_10 -> V_146 ) ;
if ( F_90 ( V_13 < 0 ) )
return - V_8 ;
V_188 = F_7 ( V_5 , V_13 ) ;
F_90 ( ! V_188 -> V_190 ) ;
V_188 -> V_190 = 0 ;
V_10 -> V_146 = 0 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_90 ( V_6 < 0 ) )
return - V_8 ;
V_20 = F_2 ( V_5 , V_6 ) ;
if ( V_5 -> V_53 ) {
V_175 = F_19 ( V_2 , V_20 -> V_3 , 0 ,
V_178 , 0 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_55 ,
V_175 & ~ V_54 ) ;
}
F_94 ( V_2 , V_6 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_114 = false ;
memset ( V_20 -> V_144 , 0 , sizeof( V_20 -> V_144 ) ) ;
V_20 -> V_233 = false ;
V_20 -> V_81 = 0 ;
F_11 ( & V_20 -> V_26 ) ;
}
return 0 ;
}
static int F_126 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_258 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_18 -> type = V_259 ;
V_18 -> V_27 = V_5 -> V_208 ;
V_18 -> V_32 . integer . V_260 = 0 ;
V_18 -> V_32 . integer . V_261 = V_262 ;
return 0 ;
}
static int F_127 ( struct V_78 * V_263 ,
int V_81 )
{
if ( V_263 -> V_81 != V_81 )
return - 1 ;
return V_264 ;
}
static void F_128 ( struct V_78 * V_263 ,
unsigned int * V_144 , int V_81 )
{
int V_27 = 0 ;
int V_69 ;
for ( V_69 = 7 ; V_69 >= 0 ; V_69 -- ) {
int V_109 = V_263 -> V_83 [ V_69 ] ;
if ( ! V_109 )
continue;
V_144 [ V_27 ++ ] = F_47 ( V_109 ) ;
}
F_44 ( V_27 != V_81 ) ;
}
static int F_129 ( struct V_15 * V_16 , int V_265 ,
unsigned int V_121 , unsigned int T_4 * V_266 )
{
struct V_258 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int T_4 * V_267 ;
int V_57 , V_27 = 0 ;
if ( V_121 < 8 )
return - V_40 ;
if ( F_130 ( V_268 , V_266 ) )
return - V_269 ;
V_121 -= 8 ;
V_267 = V_266 + 2 ;
for ( V_57 = 2 ; V_57 <= V_5 -> V_208 ; V_57 ++ ) {
int V_76 ;
struct V_78 * V_263 ;
V_263 = V_80 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ , V_263 ++ ) {
int V_270 = V_57 * 4 ;
int type = V_5 -> V_92 . V_271 ( V_263 , V_57 ) ;
unsigned int V_272 [ 8 ] ;
if ( type < 0 )
continue;
if ( V_121 < 8 )
return - V_40 ;
if ( F_130 ( type , V_267 ) ||
F_130 ( V_270 , V_267 + 1 ) )
return - V_269 ;
V_267 += 2 ;
V_121 -= 8 ;
V_27 += 8 ;
if ( V_121 < V_270 )
return - V_40 ;
V_121 -= V_270 ;
V_27 += V_270 ;
V_5 -> V_92 . V_273 ( V_263 , V_272 , V_57 ) ;
if ( F_131 ( V_267 , V_272 , V_270 ) )
return - V_269 ;
V_267 += V_57 ;
}
}
if ( F_130 ( V_27 , V_266 + 1 ) )
return - V_269 ;
return 0 ;
}
static int F_132 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_258 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_16 -> V_24 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_20 -> V_144 ) ; V_76 ++ )
V_31 -> V_32 . integer . V_32 [ V_76 ] = V_20 -> V_144 [ V_76 ] ;
return 0 ;
}
static int F_133 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_258 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_16 -> V_24 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
unsigned int V_274 ;
struct V_203 * V_204 ;
unsigned char V_144 [ 8 ] ;
int V_76 , V_38 , V_84 , V_275 = 0 ;
V_274 = F_134 ( V_16 , & V_31 -> V_41 ) ;
V_204 = F_135 ( V_89 , V_274 ) ;
if ( ! V_204 || ! V_204 -> V_206 )
return 0 ;
switch ( V_204 -> V_206 -> V_255 -> V_276 ) {
case V_277 :
case V_278 :
break;
case V_279 :
V_275 = 1 ;
break;
default:
return - V_280 ;
}
memset ( V_144 , 0 , sizeof( V_144 ) ) ;
for ( V_76 = 0 ; V_76 < F_13 ( V_144 ) ; V_76 ++ )
V_144 [ V_76 ] = V_31 -> V_32 . integer . V_32 [ V_76 ] ;
if ( ! memcmp ( V_144 , V_20 -> V_144 , sizeof( V_144 ) ) )
return 0 ;
V_84 = F_49 ( F_13 ( V_144 ) , V_144 ) ;
if ( V_84 < 0 )
return - V_8 ;
if ( V_5 -> V_92 . V_281 ) {
V_38 = V_5 -> V_92 . V_281 ( V_84 , F_13 ( V_144 ) , V_144 ) ;
if ( V_38 )
return V_38 ;
}
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_114 = true ;
memcpy ( V_20 -> V_144 , V_144 , sizeof( V_144 ) ) ;
if ( V_275 )
F_65 ( V_2 , V_20 , V_20 -> V_94 ) ;
F_11 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_282 * V_89 ;
struct V_9 * V_283 ;
struct V_19 * V_20 ;
V_20 = F_2 ( V_5 , V_6 ) ;
sprintf ( V_20 -> V_284 , L_26 , V_6 ) ;
V_89 = F_114 ( & V_5 -> V_285 ) ;
if ( ! V_89 )
return - V_40 ;
V_89 -> V_65 = V_20 -> V_284 ;
V_89 -> V_286 = V_287 ;
V_89 -> V_288 = true ;
V_283 = & V_89 -> V_11 [ V_289 ] ;
V_283 -> V_290 = 1 ;
V_283 -> V_92 = V_291 ;
}
V_2 -> V_292 = V_5 -> V_7 ;
V_2 -> V_293 = V_5 -> V_285 . V_294 ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , int V_6 )
{
char V_295 [ 32 ] = L_27 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
int V_296 = F_5 ( V_5 , V_6 ) -> V_36 ;
if ( V_296 > 0 )
sprintf ( V_295 + strlen ( V_295 ) , L_28 , V_296 ) ;
if ( ! F_138 ( V_2 , V_20 -> V_3 ) )
strncat ( V_295 , L_29 ,
sizeof( V_295 ) - strlen ( V_295 ) - 1 ) ;
return F_139 ( V_2 , V_20 -> V_3 , V_295 , 0 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
V_38 = F_137 ( V_2 , V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_141 ( V_2 ,
V_20 -> V_3 ,
V_20 -> V_192 [ 0 ] ,
V_287 ) ;
if ( V_38 < 0 )
return V_38 ;
F_94 ( V_2 , V_6 ) ;
V_38 = F_15 ( V_2 , V_6 ,
F_5 ( V_5 , V_6 ) -> V_36 ) ;
if ( V_38 < 0 )
return V_38 ;
F_68 ( V_20 , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_258 * V_144 ;
struct V_15 * V_37 ;
int V_76 ;
if ( ! V_2 -> V_293 [ V_6 ] . V_297 )
break;
V_38 = F_142 ( V_2 -> V_293 [ V_6 ] . V_297 ,
V_289 ,
NULL , 0 , V_6 , & V_144 ) ;
if ( V_38 < 0 )
return V_38 ;
V_144 -> V_63 = V_2 ;
V_37 = V_144 -> V_37 ;
for ( V_76 = 0 ; V_76 < V_37 -> V_27 ; V_76 ++ )
V_37 -> V_298 [ V_76 ] . V_299 |= V_300 ;
V_37 -> V_89 = F_126 ;
V_37 -> V_301 = F_132 ;
V_37 -> V_302 = F_133 ;
V_37 -> V_266 . V_69 = F_129 ;
}
return 0 ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
V_20 -> V_2 = V_2 ;
F_144 ( & V_20 -> V_26 ) ;
F_145 ( & V_20 -> V_230 , F_107 ) ;
F_31 ( V_20 , V_6 ) ;
}
return 0 ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
F_23 ( V_2 , V_3 ) ;
F_147 ( V_2 , V_3 ,
V_2 -> V_303 > 0 ? F_70 : NULL ) ;
}
return 0 ;
}
static void F_148 ( struct V_4 * V_5 , int V_304 )
{
F_149 ( & V_5 -> V_244 , sizeof( struct V_19 ) , V_304 ) ;
F_149 ( & V_5 -> V_246 , sizeof( struct V_187 ) , V_304 ) ;
F_149 ( & V_5 -> V_285 , sizeof( struct V_282 ) , V_304 ) ;
}
static void F_150 ( struct V_4 * V_5 )
{
F_151 ( & V_5 -> V_244 ) ;
F_151 ( & V_5 -> V_246 ) ;
F_151 ( & V_5 -> V_285 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_153 ( & V_20 -> V_230 ) ;
F_34 ( V_20 ) ;
}
F_154 ( V_2 -> V_67 -> V_229 ) ;
F_150 ( V_5 ) ;
F_155 ( V_5 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_2 -> V_305 . V_306 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_68 ( V_20 , 1 ) ;
}
return 0 ;
}
static void F_113 ( struct V_1 * V_2 ,
T_1 V_146 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_307 [ 4 ] ;
int V_308 ;
V_308 = F_97 ( V_2 , V_146 , V_307 , F_13 ( V_307 ) ) ;
if ( V_308 == V_5 -> V_14 &&
! memcmp ( V_307 , V_5 -> V_247 , V_5 -> V_14 * sizeof( T_1 ) ) )
return;
F_40 ( V_2 , L_30 , V_146 ) ;
F_159 ( V_2 , V_146 , V_5 -> V_14 , V_5 -> V_247 ) ;
}
static void F_160 ( struct V_1 * V_2 ,
bool V_309 )
{
unsigned int V_310 ;
V_310 = F_19 ( V_2 , V_311 , 0 ,
V_312 , 0 ) ;
if ( V_310 == - 1 || V_310 & V_313 )
return;
V_310 |= V_313 ;
V_310 = F_19 ( V_2 , V_311 , 0 ,
V_314 , V_310 ) ;
if ( V_310 == - 1 )
return;
if ( V_309 )
F_161 ( V_2 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
unsigned int V_310 ;
V_310 = F_19 ( V_2 , V_311 , 0 ,
V_312 , 0 ) ;
if ( V_310 == - 1 || V_310 & V_315 )
return;
V_310 |= V_315 ;
F_86 ( V_2 , V_311 , 0 ,
V_314 , V_310 ) ;
}
static void F_163 ( struct V_1 * V_2 , T_1 V_316 ,
unsigned int V_317 )
{
if ( V_317 == V_169 ) {
F_160 ( V_2 , false ) ;
F_162 ( V_2 ) ;
}
F_19 ( V_2 , V_316 , 0 , V_170 , V_317 ) ;
F_164 ( V_2 , V_316 , V_317 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_166 ( sizeof( * V_5 ) , V_318 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_5 -> V_92 = V_319 ;
V_2 -> V_5 = V_5 ;
F_148 ( V_5 , 4 ) ;
if ( F_66 ( V_2 ) ) {
F_160 ( V_2 , true ) ;
F_162 ( V_2 ) ;
}
if ( F_66 ( V_2 ) || F_91 ( V_2 ) )
V_2 -> V_320 = 0 ;
if ( F_118 ( V_2 ) < 0 ) {
V_2 -> V_5 = NULL ;
F_155 ( V_5 ) ;
return - V_8 ;
}
V_2 -> V_305 = V_321 ;
if ( F_66 ( V_2 ) ) {
V_2 -> V_305 . V_322 = F_163 ;
V_2 -> V_323 = true ;
}
F_143 ( V_2 ) ;
F_36 () ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_282 * V_89 ;
unsigned int V_245 ;
struct V_9 * V_283 ;
struct V_187 * V_188 ;
V_188 = F_7 ( V_5 , 0 ) ;
V_245 = F_24 ( V_2 , V_188 -> V_12 ) ;
V_245 = F_116 ( V_245 ) ;
V_89 = F_114 ( & V_5 -> V_285 ) ;
if ( ! V_89 )
return - V_40 ;
V_89 -> V_65 = F_2 ( V_5 , 0 ) -> V_284 ;
sprintf ( V_89 -> V_65 , L_31 ) ;
V_89 -> V_286 = V_287 ;
V_283 = & V_89 -> V_11 [ V_289 ] ;
* V_283 = V_5 -> V_324 ;
V_283 -> V_146 = V_188 -> V_12 ;
if ( V_283 -> V_208 <= 2 && V_245 && V_245 <= 16 )
V_283 -> V_208 = V_245 ;
V_2 -> V_292 = 1 ;
V_2 -> V_293 = V_89 ;
return 0 ;
}
static void F_168 ( struct V_1 * V_2 ,
unsigned int V_150 )
{
F_169 ( V_2 ) ;
F_69 ( V_2 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_187 * V_188 ;
int V_38 ;
V_188 = F_7 ( V_5 , 0 ) ;
V_38 = F_141 ( V_2 , V_188 -> V_12 ,
V_188 -> V_12 ,
V_287 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_171 ( V_2 , 0 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , 0 ) ;
T_1 V_325 = V_20 -> V_3 ;
F_21 ( V_2 , V_325 , 0 ,
V_55 , V_54 ) ;
if ( F_24 ( V_2 , V_325 ) & V_50 )
F_21 ( V_2 , V_325 , 0 , V_51 ,
V_52 ) ;
F_173 ( V_2 , V_325 ) ;
return 0 ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_150 ( V_5 ) ;
F_155 ( V_5 ) ;
}
static int F_175 ( struct V_1 * V_2 )
{
F_176 ( V_2 , V_326 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
F_176 ( V_2 , V_327 ) ;
return 0 ;
}
static int F_178 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_328 * V_329 = NULL ;
switch ( V_2 -> V_330 -> V_41 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_329 = & V_331 ;
break;
case 0x10de0007 :
V_329 = & V_332 ;
break;
default:
break;
}
if ( V_329 != NULL ) {
V_328 ( V_204 -> V_206 , 0 ,
V_214 ,
V_329 ) ;
} else {
F_95 ( V_204 -> V_206 , 0 ,
V_214 , 2 ) ;
}
return F_179 ( V_2 , & V_5 -> V_333 ) ;
}
static int F_180 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_181 ( V_2 , & V_5 -> V_333 ) ;
}
static int F_182 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_183 ( V_2 , & V_5 -> V_333 ,
V_182 , V_183 , V_204 ) ;
}
static int F_184 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_187 * V_188 ;
struct V_19 * V_20 ;
V_5 = F_166 ( sizeof( * V_5 ) , V_318 ) ;
if ( ! V_5 )
return - V_40 ;
V_2 -> V_5 = V_5 ;
F_148 ( V_5 , 1 ) ;
V_5 -> V_333 . V_334 = 0 ;
V_5 -> V_333 . V_335 = 2 ;
V_5 -> V_333 . V_336 = V_12 ;
V_5 -> V_14 = 1 ;
V_5 -> V_7 = 1 ;
V_20 = F_114 ( & V_5 -> V_244 ) ;
V_188 = F_114 ( & V_5 -> V_246 ) ;
if ( ! V_20 || ! V_188 ) {
F_174 ( V_2 ) ;
return - V_40 ;
}
V_188 -> V_12 = V_12 ;
V_20 -> V_3 = V_3 ;
V_5 -> V_324 = V_337 ;
V_2 -> V_305 = V_338 ;
return 0 ;
}
static void F_185 ( struct V_1 * V_2 ,
int V_81 )
{
unsigned int V_339 ;
int V_340 = V_81 ? ( V_81 - 1 ) : 1 ;
switch ( V_81 ) {
default:
case 0 :
case 2 :
V_339 = 0x00 ;
break;
case 4 :
V_339 = 0x08 ;
break;
case 6 :
V_339 = 0x0b ;
break;
case 8 :
V_339 = 0x13 ;
break;
}
F_21 ( V_2 , 0x1 , 0 ,
V_341 , V_339 ) ;
F_21 ( V_2 , 0x1 , 0 ,
V_342 ,
( 0x71 - V_340 - V_339 ) ) ;
}
static int F_186 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_203 * V_204 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_76 ;
F_21 ( V_2 , V_343 ,
0 , V_344 , 0 ) ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
F_21 ( V_2 , V_345 [ V_76 ] , 0 ,
V_344 , 0 ) ;
F_21 ( V_2 , V_345 [ V_76 ] , 0 ,
V_346 , 0 ) ;
}
F_185 ( V_2 , 8 ) ;
return F_181 ( V_2 , & V_5 -> V_333 ) ;
}
static int F_187 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_203 * V_204 )
{
int V_57 ;
unsigned int V_347 , V_348 ;
int V_76 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_252 * V_253 ;
struct V_187 * V_188 ;
F_10 ( & V_2 -> V_254 ) ;
V_188 = F_7 ( V_5 , 0 ) ;
V_253 = F_121 ( V_2 , V_188 -> V_12 ) ;
V_57 = V_204 -> V_206 -> V_81 ;
V_347 = 0x2 ;
if ( V_2 -> V_349 && ( V_253 -> V_350 & V_351 ) )
F_21 ( V_2 ,
V_343 ,
0 ,
V_352 ,
V_253 -> V_350 & ~ V_351 & 0xff ) ;
F_21 ( V_2 , V_343 , 0 ,
V_344 , ( V_182 << 4 ) | 0x0 ) ;
F_21 ( V_2 , V_343 , 0 ,
V_346 , V_183 ) ;
if ( V_2 -> V_349 && ( V_253 -> V_350 & V_351 ) ) {
F_21 ( V_2 ,
V_343 ,
0 ,
V_352 ,
V_253 -> V_350 & 0xff ) ;
F_21 ( V_2 ,
V_343 ,
0 ,
V_353 , V_347 ) ;
}
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
if ( V_57 == 2 )
V_348 = 0 ;
else
V_348 = V_76 * 2 ;
if ( V_2 -> V_349 &&
( V_253 -> V_350 & V_351 ) )
F_21 ( V_2 ,
V_345 [ V_76 ] ,
0 ,
V_352 ,
V_253 -> V_350 & ~ V_351 & 0xff ) ;
F_21 ( V_2 ,
V_345 [ V_76 ] ,
0 ,
V_344 ,
( V_182 << 4 ) | V_348 ) ;
F_21 ( V_2 ,
V_345 [ V_76 ] ,
0 ,
V_346 ,
V_183 ) ;
if ( V_2 -> V_349 &&
( V_253 -> V_350 & V_351 ) ) {
F_21 ( V_2 ,
V_345 [ V_76 ] ,
0 ,
V_352 ,
V_253 -> V_350 & 0xff ) ;
F_21 ( V_2 ,
V_345 [ V_76 ] ,
0 ,
V_353 , V_347 ) ;
}
}
F_185 ( V_2 , V_57 ) ;
F_11 ( & V_2 -> V_254 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 = F_184 ( V_2 , V_343 ,
V_354 ) ;
if ( V_38 < 0 )
return V_38 ;
V_2 -> V_305 . V_306 = F_175 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_324 . V_209 = V_355 ;
V_5 -> V_324 . V_211 = V_356 ;
V_5 -> V_324 . V_210 = V_357 ;
return 0 ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 = F_167 ( V_2 ) ;
if ( ! V_38 ) {
struct V_282 * V_89 = F_5 ( V_5 , 0 ) ;
V_89 -> V_288 = true ;
}
return V_38 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_282 * V_89 ;
struct V_258 * V_144 ;
int V_38 ;
V_38 = F_170 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_89 = F_5 ( V_5 , 0 ) ;
V_38 = F_142 ( V_89 -> V_297 ,
V_289 ,
V_358 , 8 , 0 , & V_144 ) ;
if ( V_38 < 0 )
return V_38 ;
switch ( V_2 -> V_330 -> V_41 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_144 -> V_359 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_144 -> V_359 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 = F_188 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_333 . V_335 = 8 ;
V_5 -> V_324 = V_360 ;
V_2 -> V_305 . V_306 = F_177 ;
V_2 -> V_305 . V_361 = F_189 ;
V_2 -> V_305 . V_362 = F_190 ;
F_185 ( V_2 , 8 ) ;
return 0 ;
}
static int F_192 ( struct V_78 * V_263 ,
int V_81 )
{
if ( V_263 -> V_85 == 0x00 && V_81 == 2 )
return V_363 ;
return F_127 ( V_263 , V_81 ) ;
}
static int F_193 ( int V_84 , int V_57 , unsigned char * V_105 )
{
if ( V_84 == 0x00 && ( V_105 [ 0 ] != V_364 || V_105 [ 1 ] != V_365 ) )
return - V_8 ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 ;
V_38 = F_165 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_53 = true ;
V_5 -> V_92 . V_271 =
F_192 ;
V_5 -> V_92 . V_281 = F_193 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 , T_1 V_146 ,
unsigned char * V_86 , int * V_29 )
{
return F_196 ( V_2 , V_146 , V_86 , V_29 ,
F_197 ( V_2 ) ) ;
}
static void F_198 ( struct V_1 * V_2 , T_1 V_3 , int V_84 ,
int V_132 , int V_133 )
{
F_21 ( V_2 , V_3 , 0 , V_366 , V_84 ) ;
}
static int F_199 ( int V_107 )
{
switch ( V_107 ) {
case 2 : return 3 ;
case 3 : return 2 ;
default: break;
}
return V_107 ;
}
static int F_200 ( int V_84 , int V_57 , unsigned char * V_105 )
{
struct V_78 * V_263 ;
int V_76 , V_77 ;
V_263 = & V_80 [ F_37 ( V_84 ) ] ;
for ( V_76 = 0 ; V_76 < V_57 ; ++ V_76 ) {
int V_108 = F_45 ( V_105 [ V_76 ] ) ;
bool V_367 = false ;
bool V_368 = false ;
if ( ! V_108 )
continue;
for ( V_77 = 0 + V_76 % 2 ; V_77 < 8 ; V_77 += 2 ) {
int V_369 = 7 - F_199 ( V_77 ) ;
if ( V_263 -> V_83 [ V_369 ] == V_108 ) {
V_367 = true ;
if ( V_76 % 2 == 0 && V_76 + 1 < V_57 ) {
int V_370 = 7 - F_199 ( V_77 + 1 ) ;
int V_371 = F_45 ( V_105 [ V_76 + 1 ] ) ;
int V_372 = V_263 -> V_83 [ V_370 ] ;
if ( V_371 == V_372 )
V_368 = true ;
else
return - V_8 ;
}
break;
}
}
if ( ! V_367 )
return - V_8 ;
if ( V_368 )
V_76 ++ ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , T_1 V_3 ,
int V_99 , int V_373 )
{
int V_374 ;
int V_375 = 0 ;
if ( V_99 > 7 )
return - V_8 ;
if ( ! F_202 ( V_2 ) ) {
V_99 = F_199 ( V_99 ) ;
if ( V_99 % 2 != 0 && V_373 == 0xf )
return 0 ;
V_99 -= V_99 % 2 ;
if ( V_373 != 0xf )
V_373 -= V_373 % 2 ;
}
V_374 = V_376 + V_99 / 2 + ( V_99 % 2 ) * 0x00e ;
if ( V_373 != 0xf )
V_375 = ( V_373 << 4 ) | V_377 ;
return F_21 ( V_2 , V_3 , 0 , V_374 , V_375 ) ;
}
static int F_203 ( struct V_1 * V_2 , T_1 V_3 ,
int V_115 )
{
bool V_378 = false ;
int V_379 = V_115 ;
int V_374 ;
int V_375 ;
if ( V_115 > 7 )
return - V_8 ;
if ( ! F_202 ( V_2 ) ) {
V_379 = F_199 ( V_115 ) ;
if ( V_379 % 2 != 0 ) {
V_379 -= 1 ;
V_378 = true ;
}
}
V_374 = V_380 + V_379 / 2 + ( V_379 % 2 ) * 0x00e ;
V_375 = F_19 ( V_2 , V_3 , 0 , V_374 , 0 ) ;
if ( ! ( V_375 & V_377 ) )
return 0xf ;
return ( ( V_375 & 0xf0 ) >> 4 ) + ! ! V_378 ;
}
static int F_204 ( struct V_78 * V_263 ,
int V_81 )
{
int V_69 ;
int V_381 = 0 ;
if ( ( V_81 % 2 ) != 0 )
return - 1 ;
for ( V_69 = 0 ; V_69 < 7 ; V_69 += 2 ) {
if ( V_263 -> V_83 [ V_69 ] || V_263 -> V_83 [ V_69 + 1 ] )
V_381 ++ ;
}
if ( V_381 * 2 != V_81 )
return - 1 ;
return V_382 ;
}
static void F_205 ( struct V_78 * V_263 ,
unsigned int * V_144 , int V_81 )
{
int V_27 = 0 ;
int V_69 ;
for ( V_69 = 7 ; V_69 >= 0 ; V_69 -- ) {
int V_340 = 7 - F_199 ( 7 - V_69 ) ;
int V_109 = V_263 -> V_83 [ V_340 ] ;
if ( ! V_109 ) {
if ( V_263 -> V_83 [ V_340 + ( V_340 % 2 ? - 1 : 1 ) ] )
V_144 [ V_27 ++ ] = V_383 ;
continue;
}
V_144 [ V_27 ++ ] = F_47 ( V_109 ) ;
}
F_44 ( V_27 != V_81 ) ;
}
static int F_206 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_174 )
{
int V_384 , V_385 ;
V_384 = F_19 ( V_2 , V_3 , 0 , V_386 , 0 ) ;
if ( V_384 >= 0 && ( V_384 & V_387 ) ) {
if ( V_174 )
V_385 = V_384 | V_388 ;
else
V_385 = V_384 & ~ V_388 ;
F_40 ( V_2 ,
L_32 ,
V_3 ,
V_384 == V_385 ? L_19 : L_20 ,
V_385 ) ;
if ( V_384 != V_385 )
F_21 ( V_2 , V_3 , 0 ,
V_389 ,
V_385 ) ;
} else if ( V_174 )
return - V_8 ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_3 , T_3 V_182 , int V_183 )
{
if ( F_197 ( V_2 ) ) {
int V_390 = 180 ;
if ( V_183 & V_391 )
V_390 = 0 ;
F_21 ( V_2 , V_12 , 0 , V_392 , V_390 ) ;
}
return F_81 ( V_2 , V_12 , V_3 , V_182 , V_183 ) ;
}
static int F_208 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 , V_38 ;
V_38 = F_146 ( V_2 ) ;
if ( V_38 )
return V_38 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 , V_393 , 0 ) ;
if ( F_202 ( V_2 ) )
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_394 ,
V_395 ) ;
}
return 0 ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_187 * V_188 ;
int V_38 , V_13 ;
V_38 = F_165 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_305 . V_306 = F_208 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_92 . V_227 = F_195 ;
V_5 -> V_92 . V_93 = F_203 ;
V_5 -> V_92 . V_101 = F_201 ;
V_5 -> V_92 . V_145 = F_198 ;
V_5 -> V_92 . V_184 = F_206 ;
V_5 -> V_92 . V_257 = F_207 ;
if ( ! F_202 ( V_2 ) ) {
V_5 -> V_92 . V_271 =
F_204 ;
V_5 -> V_92 . V_273 = F_205 ;
V_5 -> V_92 . V_281 = F_200 ;
}
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_188 = F_7 ( V_5 , V_13 ) ;
V_188 -> V_208 = V_261 ( V_188 -> V_208 , 8u ) ;
V_188 -> V_209 |= V_355 ;
V_188 -> V_210 |= V_357 ;
V_188 -> V_211 = V_261 ( V_188 -> V_211 , 24u ) ;
}
V_5 -> V_208 = V_261 ( V_5 -> V_208 , 8u ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
return F_184 ( V_2 , V_396 , V_397 ) ;
}
int F_211 ( struct V_1 * V_2 )
{
return F_165 ( V_2 ) ;
}
static int T_5 F_212 ( void )
{
return F_213 ( & V_398 ) ;
}
static void T_6 F_214 ( void )
{
F_215 ( & V_398 ) ;
}
