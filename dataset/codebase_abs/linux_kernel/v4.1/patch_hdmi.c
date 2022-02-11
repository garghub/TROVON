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
V_38 = F_32 ( V_2 -> V_67 , V_65 , & V_60 ) ;
if ( V_38 < 0 )
return V_38 ;
F_33 ( V_60 , V_20 , F_27 ) ;
V_60 -> V_68 . V_69 . V_70 = F_29 ;
V_60 -> V_71 |= V_72 ;
V_20 -> V_73 = V_60 ;
return 0 ;
}
static void F_34 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_2 -> V_74 -> V_75 && V_20 -> V_73 ) {
F_35 ( V_20 -> V_2 -> V_67 , V_20 -> V_73 ) ;
V_20 -> V_73 = NULL ;
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
static int F_45 ( unsigned char V_68 )
{
struct V_102 * V_103 = V_104 ;
for (; V_103 -> V_105 ; V_103 ++ ) {
if ( V_103 -> V_105 == V_68 )
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
T_1 V_146 ;
int V_13 , V_194 ;
struct V_187 * V_188 ;
F_88 (nid, codec) {
unsigned int V_197 = F_24 ( V_2 , V_146 ) ;
unsigned int V_198 = F_89 ( V_197 ) ;
if ( V_198 != V_199 )
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
int V_38 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_91 ( V_6 < 0 ) )
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
if ( F_66 ( V_2 ) || F_92 ( V_2 ) )
F_87 ( V_2 , V_20 -> V_3 , V_189 ) ;
F_93 ( V_2 , V_6 , V_188 -> V_12 ) ;
V_10 -> V_204 = V_188 -> V_204 ;
V_10 -> V_205 = V_188 -> V_205 ;
V_10 -> V_206 = V_188 -> V_206 ;
V_10 -> V_207 = V_188 -> V_207 ;
V_10 -> V_208 = V_188 -> V_208 ;
if ( ! V_209 && V_22 -> V_28 ) {
F_94 ( & V_22 -> V_89 , V_10 ) ;
if ( V_10 -> V_204 > V_10 -> V_205 ||
! V_10 -> V_206 || ! V_10 -> V_207 ) {
V_188 -> V_190 = 0 ;
V_10 -> V_146 = 0 ;
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
static bool F_68 ( struct V_19 * V_20 , int V_214 )
{
struct V_153 * V_148 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_22 = & V_5 -> V_215 ;
struct V_21 * V_216 = & V_20 -> V_25 ;
T_1 V_3 = V_20 -> V_3 ;
int V_217 ;
bool V_218 = false ;
bool V_219 = false ;
bool V_220 ;
F_99 ( V_2 ) ;
V_217 = F_100 ( V_2 , V_3 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_216 -> V_221 = ! ! ( V_217 & V_222 ) ;
if ( V_216 -> V_221 )
V_22 -> V_28 = ! ! ( V_217 & V_223 ) ;
else
V_22 -> V_28 = false ;
F_40 ( V_2 ,
L_24 ,
V_2 -> V_66 , V_3 , V_216 -> V_221 , V_22 -> V_28 ) ;
if ( V_22 -> V_28 ) {
if ( V_5 -> V_92 . V_224 ( V_2 , V_3 , V_22 -> V_35 ,
& V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
else {
memset ( & V_22 -> V_89 , 0 , sizeof( struct V_225 ) ) ;
if ( F_101 ( V_2 , & V_22 -> V_89 , V_22 -> V_35 ,
V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
}
if ( V_22 -> V_28 ) {
F_102 ( V_2 , & V_22 -> V_89 ) ;
V_218 = true ;
}
else if ( V_214 ) {
F_103 ( & V_20 -> V_226 ,
F_104 ( 300 ) ) ;
goto V_227;
}
}
if ( V_216 -> V_28 != V_22 -> V_28 )
V_219 = true ;
if ( V_216 -> V_28 && ! V_22 -> V_28 )
V_218 = true ;
if ( V_218 ) {
bool V_228 = V_216 -> V_28 ;
V_216 -> V_28 = V_22 -> V_28 ;
if ( V_216 -> V_29 != V_22 -> V_29 ||
memcmp ( V_216 -> V_35 , V_22 -> V_35 ,
V_22 -> V_29 ) != 0 ) {
memcpy ( V_216 -> V_35 , V_22 -> V_35 ,
V_22 -> V_29 ) ;
V_219 = true ;
}
V_216 -> V_29 = V_22 -> V_29 ;
V_216 -> V_89 = V_22 -> V_89 ;
if ( V_22 -> V_28 && ! V_228 && V_20 -> V_229 ) {
if ( F_66 ( V_2 ) ||
F_92 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_3 ,
V_20 -> V_189 ) ;
}
F_65 ( V_2 , V_20 ,
V_20 -> V_94 ) ;
}
}
if ( V_219 )
F_105 ( V_2 -> V_67 ,
V_230 | V_231 ,
& V_20 -> V_42 -> V_41 ) ;
V_227:
V_220 = ! V_214 || ! V_216 -> V_221 || V_216 -> V_28 ;
V_148 = F_106 ( V_2 , V_3 ) ;
if ( V_148 )
V_148 -> V_232 = ! V_220 ;
F_11 ( & V_20 -> V_26 ) ;
F_107 ( V_2 ) ;
return V_220 ;
}
static void F_108 ( struct V_233 * V_226 )
{
struct V_19 * V_20 =
F_109 ( F_110 ( V_226 ) , struct V_19 , V_226 ) ;
if ( V_20 -> V_234 ++ > 6 )
V_20 -> V_234 = 0 ;
if ( F_68 ( V_20 , V_20 -> V_234 ) )
F_69 ( V_20 -> V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_235 , V_236 ;
int V_6 ;
struct V_19 * V_20 ;
int V_38 ;
V_235 = F_80 ( V_2 , V_3 ) ;
if ( ! ( V_235 & ( V_237 | V_238 ) ) )
return 0 ;
V_236 = F_112 ( V_2 , V_3 ) ;
if ( F_113 ( V_236 ) == V_239 )
return 0 ;
if ( F_66 ( V_2 ) )
F_114 ( V_2 , V_3 ) ;
V_6 = V_5 -> V_7 ;
V_20 = F_115 ( & V_5 -> V_240 ) ;
if ( ! V_20 )
return - V_40 ;
V_20 -> V_3 = V_3 ;
V_20 -> V_94 = false ;
V_38 = F_97 ( V_2 , V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_5 -> V_7 ++ ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_187 * V_188 ;
unsigned int V_241 ;
int V_38 ;
V_241 = F_24 ( V_2 , V_12 ) ;
V_241 = F_117 ( V_241 ) ;
V_188 = F_115 ( & V_5 -> V_242 ) ;
if ( ! V_188 )
return - V_40 ;
V_188 -> V_12 = V_12 ;
V_188 -> V_204 = 2 ;
if ( V_241 <= 16 ) {
V_188 -> V_205 = V_241 ;
if ( V_241 > V_5 -> V_205 )
V_5 -> V_205 = V_241 ;
}
V_38 = F_118 ( V_2 , V_12 ,
& V_188 -> V_206 ,
& V_188 -> V_207 ,
& V_188 -> V_208 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_5 -> V_14 < F_13 ( V_5 -> V_243 ) )
V_5 -> V_243 [ V_5 -> V_14 ] = V_12 ;
V_5 -> V_14 ++ ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
T_1 V_146 ;
int V_76 , V_244 ;
V_244 = F_120 ( V_2 , V_2 -> V_245 . V_246 , & V_146 ) ;
if ( ! V_146 || V_244 < 0 ) {
F_3 ( V_2 , L_25 ) ;
return - V_8 ;
}
for ( V_76 = 0 ; V_76 < V_244 ; V_76 ++ , V_146 ++ ) {
unsigned int V_235 ;
unsigned int type ;
V_235 = F_24 ( V_2 , V_146 ) ;
type = F_89 ( V_235 ) ;
if ( ! ( V_235 & V_247 ) )
continue;
switch ( type ) {
case V_248 :
F_116 ( V_2 , V_146 ) ;
break;
case V_199 :
F_111 ( V_2 , V_146 ) ;
break;
}
}
return 0 ;
}
static bool F_121 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_249 * V_250 ;
bool V_94 ;
F_10 ( & V_2 -> V_251 ) ;
V_250 = F_122 ( V_2 , V_12 ) ;
V_94 = ! ! ( V_250 -> V_252 & V_253 ) ;
F_11 ( & V_2 -> V_251 ) ;
return V_94 ;
}
static int F_123 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_200 * V_201 )
{
T_1 V_12 = V_10 -> V_146 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = F_4 ( V_2 , V_10 ) ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
bool V_94 ;
int V_175 ;
if ( F_66 ( V_2 ) || F_92 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_3 , V_20 -> V_189 ) ;
}
V_94 = F_121 ( V_2 , V_12 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_81 = V_201 -> V_203 -> V_81 ;
V_20 -> V_229 = true ;
F_65 ( V_2 , V_20 , V_94 ) ;
F_11 ( & V_20 -> V_26 ) ;
if ( V_5 -> V_53 ) {
V_175 = F_19 ( V_2 , V_3 , 0 ,
V_178 , 0 ) ;
F_21 ( V_2 , V_3 , 0 ,
V_55 ,
V_175 | V_54 ) ;
}
return V_5 -> V_92 . V_254 ( V_2 , V_12 , V_3 , V_182 , V_183 ) ;
}
static int F_124 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
F_125 ( V_2 , V_10 -> V_146 ) ;
return 0 ;
}
static int F_126 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_13 , V_6 ;
struct V_187 * V_188 ;
struct V_19 * V_20 ;
int V_175 ;
if ( V_10 -> V_146 ) {
V_13 = F_6 ( V_2 , V_10 -> V_146 ) ;
if ( F_91 ( V_13 < 0 ) )
return - V_8 ;
V_188 = F_7 ( V_5 , V_13 ) ;
F_91 ( ! V_188 -> V_190 ) ;
V_188 -> V_190 = 0 ;
V_10 -> V_146 = 0 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_91 ( V_6 < 0 ) )
return - V_8 ;
V_20 = F_2 ( V_5 , V_6 ) ;
if ( V_5 -> V_53 ) {
V_175 = F_19 ( V_2 , V_20 -> V_3 , 0 ,
V_178 , 0 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_55 ,
V_175 & ~ V_54 ) ;
}
F_95 ( V_2 , V_6 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_114 = false ;
memset ( V_20 -> V_144 , 0 , sizeof( V_20 -> V_144 ) ) ;
V_20 -> V_229 = false ;
V_20 -> V_81 = 0 ;
F_11 ( & V_20 -> V_26 ) ;
}
return 0 ;
}
static int F_127 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_255 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_18 -> type = V_256 ;
V_18 -> V_27 = V_5 -> V_205 ;
V_18 -> V_32 . integer . V_257 = 0 ;
V_18 -> V_32 . integer . V_258 = V_259 ;
return 0 ;
}
static int F_128 ( struct V_78 * V_260 ,
int V_81 )
{
if ( V_260 -> V_81 != V_81 )
return - 1 ;
return V_261 ;
}
static void F_129 ( struct V_78 * V_260 ,
unsigned int * V_144 , int V_81 )
{
int V_27 = 0 ;
int V_68 ;
for ( V_68 = 7 ; V_68 >= 0 ; V_68 -- ) {
int V_109 = V_260 -> V_83 [ V_68 ] ;
if ( ! V_109 )
continue;
V_144 [ V_27 ++ ] = F_47 ( V_109 ) ;
}
F_44 ( V_27 != V_81 ) ;
}
static int F_130 ( struct V_15 * V_16 , int V_262 ,
unsigned int V_121 , unsigned int T_4 * V_263 )
{
struct V_255 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int T_4 * V_264 ;
int V_57 , V_27 = 0 ;
if ( V_121 < 8 )
return - V_40 ;
if ( F_131 ( V_265 , V_263 ) )
return - V_266 ;
V_121 -= 8 ;
V_264 = V_263 + 2 ;
for ( V_57 = 2 ; V_57 <= V_5 -> V_205 ; V_57 ++ ) {
int V_76 ;
struct V_78 * V_260 ;
V_260 = V_80 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ , V_260 ++ ) {
int V_267 = V_57 * 4 ;
int type = V_5 -> V_92 . V_268 ( V_260 , V_57 ) ;
unsigned int V_269 [ 8 ] ;
if ( type < 0 )
continue;
if ( V_121 < 8 )
return - V_40 ;
if ( F_131 ( type , V_264 ) ||
F_131 ( V_267 , V_264 + 1 ) )
return - V_266 ;
V_264 += 2 ;
V_121 -= 8 ;
V_27 += 8 ;
if ( V_121 < V_267 )
return - V_40 ;
V_121 -= V_267 ;
V_27 += V_267 ;
V_5 -> V_92 . V_270 ( V_260 , V_269 , V_57 ) ;
if ( F_132 ( V_264 , V_269 , V_267 ) )
return - V_266 ;
V_264 += V_57 ;
}
}
if ( F_131 ( V_27 , V_263 + 1 ) )
return - V_266 ;
return 0 ;
}
static int F_133 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_255 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_16 -> V_24 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_20 -> V_144 ) ; V_76 ++ )
V_31 -> V_32 . integer . V_32 [ V_76 ] = V_20 -> V_144 [ V_76 ] ;
return 0 ;
}
static int F_134 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_255 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_16 -> V_24 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
unsigned int V_271 ;
struct V_200 * V_201 ;
unsigned char V_144 [ 8 ] ;
int V_76 , V_38 , V_84 , V_272 = 0 ;
V_271 = F_135 ( V_16 , & V_31 -> V_41 ) ;
V_201 = F_136 ( V_89 , V_271 ) ;
if ( ! V_201 || ! V_201 -> V_203 )
return 0 ;
switch ( V_201 -> V_203 -> V_252 -> V_273 ) {
case V_274 :
case V_275 :
break;
case V_276 :
V_272 = 1 ;
break;
default:
return - V_277 ;
}
memset ( V_144 , 0 , sizeof( V_144 ) ) ;
for ( V_76 = 0 ; V_76 < F_13 ( V_144 ) ; V_76 ++ )
V_144 [ V_76 ] = V_31 -> V_32 . integer . V_32 [ V_76 ] ;
if ( ! memcmp ( V_144 , V_20 -> V_144 , sizeof( V_144 ) ) )
return 0 ;
V_84 = F_49 ( F_13 ( V_144 ) , V_144 ) ;
if ( V_84 < 0 )
return - V_8 ;
if ( V_5 -> V_92 . V_278 ) {
V_38 = V_5 -> V_92 . V_278 ( V_84 , F_13 ( V_144 ) , V_144 ) ;
if ( V_38 )
return V_38 ;
}
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_114 = true ;
memcpy ( V_20 -> V_144 , V_144 , sizeof( V_144 ) ) ;
if ( V_272 )
F_65 ( V_2 , V_20 , V_20 -> V_94 ) ;
F_11 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_279 * V_89 ;
struct V_9 * V_280 ;
struct V_19 * V_20 ;
V_20 = F_2 ( V_5 , V_6 ) ;
V_89 = F_138 ( V_2 , L_26 , V_6 ) ;
if ( ! V_89 )
return - V_40 ;
V_5 -> V_281 [ V_6 ] = V_89 ;
V_89 -> V_282 = V_283 ;
V_89 -> V_284 = true ;
V_280 = & V_89 -> V_11 [ V_285 ] ;
V_280 -> V_286 = 1 ;
V_280 -> V_92 = V_287 ;
}
return 0 ;
}
static int F_139 ( struct V_1 * V_2 , int V_6 )
{
char V_288 [ 32 ] = L_27 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
int V_289 = F_5 ( V_5 , V_6 ) -> V_36 ;
if ( V_289 > 0 )
sprintf ( V_288 + strlen ( V_288 ) , L_28 , V_289 ) ;
if ( ! F_140 ( V_2 , V_20 -> V_3 ) )
strncat ( V_288 , L_29 ,
sizeof( V_288 ) - strlen ( V_288 ) - 1 ) ;
return F_141 ( V_2 , V_20 -> V_3 , V_288 , 0 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
V_38 = F_139 ( V_2 , V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_143 ( V_2 ,
V_20 -> V_3 ,
V_20 -> V_192 [ 0 ] ,
V_283 ) ;
if ( V_38 < 0 )
return V_38 ;
F_95 ( V_2 , V_6 ) ;
V_38 = F_15 ( V_2 , V_6 ,
F_5 ( V_5 , V_6 ) -> V_36 ) ;
if ( V_38 < 0 )
return V_38 ;
F_68 ( V_20 , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_279 * V_290 ;
struct V_255 * V_144 ;
struct V_15 * V_37 ;
int V_76 ;
V_290 = V_5 -> V_281 [ V_6 ] ;
if ( ! V_290 || ! V_290 -> V_290 )
break;
V_38 = F_144 ( V_290 -> V_290 ,
V_285 ,
NULL , 0 , V_6 , & V_144 ) ;
if ( V_38 < 0 )
return V_38 ;
V_144 -> V_63 = V_2 ;
V_37 = V_144 -> V_37 ;
for ( V_76 = 0 ; V_76 < V_37 -> V_27 ; V_76 ++ )
V_37 -> V_291 [ V_76 ] . V_292 |= V_293 ;
V_37 -> V_89 = F_127 ;
V_37 -> V_294 = F_133 ;
V_37 -> V_295 = F_134 ;
V_37 -> V_263 . V_68 = F_130 ;
}
return 0 ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
V_20 -> V_2 = V_2 ;
F_146 ( & V_20 -> V_26 ) ;
F_147 ( & V_20 -> V_226 , F_108 ) ;
F_31 ( V_20 , V_6 ) ;
}
return 0 ;
}
static int F_148 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
F_23 ( V_2 , V_3 ) ;
F_149 ( V_2 , V_3 ,
V_2 -> V_296 > 0 ? F_70 : NULL ) ;
}
return 0 ;
}
static void F_150 ( struct V_4 * V_5 , int V_297 )
{
F_151 ( & V_5 -> V_240 , sizeof( struct V_19 ) , V_297 ) ;
F_151 ( & V_5 -> V_242 , sizeof( struct V_187 ) , V_297 ) ;
}
static void F_152 ( struct V_4 * V_5 )
{
F_153 ( & V_5 -> V_240 ) ;
F_153 ( & V_5 -> V_242 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_155 ( & V_20 -> V_226 ) ;
F_34 ( V_20 ) ;
}
F_152 ( V_5 ) ;
F_156 ( V_5 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_2 -> V_298 . V_299 ( V_2 ) ;
F_158 ( V_2 -> V_245 . V_300 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_68 ( V_20 , 1 ) ;
}
return 0 ;
}
static void F_114 ( struct V_1 * V_2 ,
T_1 V_146 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_301 [ 4 ] ;
int V_302 ;
V_302 = F_98 ( V_2 , V_146 , V_301 , F_13 ( V_301 ) ) ;
if ( V_302 == V_5 -> V_14 &&
! memcmp ( V_301 , V_5 -> V_243 , V_5 -> V_14 * sizeof( T_1 ) ) )
return;
F_40 ( V_2 , L_30 , V_146 ) ;
F_159 ( V_2 , V_146 , V_5 -> V_14 , V_5 -> V_243 ) ;
}
static void F_160 ( struct V_1 * V_2 ,
bool V_303 )
{
unsigned int V_304 ;
V_304 = F_19 ( V_2 , V_305 , 0 ,
V_306 , 0 ) ;
if ( V_304 == - 1 || V_304 & V_307 )
return;
V_304 |= V_307 ;
V_304 = F_19 ( V_2 , V_305 , 0 ,
V_308 , V_304 ) ;
if ( V_304 == - 1 )
return;
if ( V_303 )
F_161 ( V_2 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
unsigned int V_304 ;
V_304 = F_19 ( V_2 , V_305 , 0 ,
V_306 , 0 ) ;
if ( V_304 == - 1 || V_304 & V_309 )
return;
V_304 |= V_309 ;
F_163 ( & V_2 -> V_245 , V_308 ) ;
F_86 ( V_2 , V_305 , 0 ,
V_308 , V_304 ) ;
}
static void F_164 ( struct V_1 * V_2 , T_1 V_310 ,
unsigned int V_311 )
{
if ( V_311 == V_169 ) {
F_160 ( V_2 , false ) ;
F_162 ( V_2 ) ;
}
F_19 ( V_2 , V_310 , 0 , V_170 , V_311 ) ;
F_165 ( V_2 , V_310 , V_311 ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_167 ( sizeof( * V_5 ) , V_312 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_5 -> V_92 = V_313 ;
V_2 -> V_5 = V_5 ;
F_150 ( V_5 , 4 ) ;
if ( F_66 ( V_2 ) ) {
F_160 ( V_2 , true ) ;
F_162 ( V_2 ) ;
}
if ( F_66 ( V_2 ) || F_92 ( V_2 ) )
V_2 -> V_314 = 0 ;
if ( F_119 ( V_2 ) < 0 ) {
V_2 -> V_5 = NULL ;
F_156 ( V_5 ) ;
return - V_8 ;
}
V_2 -> V_298 = V_315 ;
if ( F_66 ( V_2 ) ) {
V_2 -> V_298 . V_316 = F_164 ;
V_2 -> V_317 = true ;
}
F_145 ( V_2 ) ;
F_36 () ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_279 * V_89 ;
unsigned int V_241 ;
struct V_9 * V_280 ;
struct V_187 * V_188 ;
V_188 = F_7 ( V_5 , 0 ) ;
V_241 = F_24 ( V_2 , V_188 -> V_12 ) ;
V_241 = F_117 ( V_241 ) ;
V_89 = F_138 ( V_2 , L_31 ) ;
if ( ! V_89 )
return - V_40 ;
V_5 -> V_281 [ 0 ] = V_89 ;
V_89 -> V_282 = V_283 ;
V_280 = & V_89 -> V_11 [ V_285 ] ;
* V_280 = V_5 -> V_318 ;
V_280 -> V_146 = V_188 -> V_12 ;
if ( V_280 -> V_205 <= 2 && V_241 && V_241 <= 16 )
V_280 -> V_205 = V_241 ;
return 0 ;
}
static void F_169 ( struct V_1 * V_2 ,
unsigned int V_150 )
{
F_170 ( V_2 ) ;
F_69 ( V_2 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_187 * V_188 ;
int V_38 ;
V_188 = F_7 ( V_5 , 0 ) ;
V_38 = F_143 ( V_2 , V_188 -> V_12 ,
V_188 -> V_12 ,
V_283 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_172 ( V_2 , 0 ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , 0 ) ;
T_1 V_319 = V_20 -> V_3 ;
F_21 ( V_2 , V_319 , 0 ,
V_55 , V_54 ) ;
if ( F_24 ( V_2 , V_319 ) & V_50 )
F_21 ( V_2 , V_319 , 0 , V_51 ,
V_52 ) ;
F_174 ( V_2 , V_319 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_152 ( V_5 ) ;
F_156 ( V_5 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
F_177 ( V_2 , V_320 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 )
{
F_177 ( V_2 , V_321 ) ;
return 0 ;
}
static int F_179 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_322 * V_323 = NULL ;
switch ( V_2 -> V_324 -> V_41 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_323 = & V_325 ;
break;
case 0x10de0007 :
V_323 = & V_326 ;
break;
default:
break;
}
if ( V_323 != NULL ) {
V_322 ( V_201 -> V_203 , 0 ,
V_211 ,
V_323 ) ;
} else {
F_96 ( V_201 -> V_203 , 0 ,
V_211 , 2 ) ;
}
return F_180 ( V_2 , & V_5 -> V_327 ) ;
}
static int F_181 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_182 ( V_2 , & V_5 -> V_327 ) ;
}
static int F_183 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_184 ( V_2 , & V_5 -> V_327 ,
V_182 , V_183 , V_201 ) ;
}
static int F_185 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_187 * V_188 ;
struct V_19 * V_20 ;
V_5 = F_167 ( sizeof( * V_5 ) , V_312 ) ;
if ( ! V_5 )
return - V_40 ;
V_2 -> V_5 = V_5 ;
F_150 ( V_5 , 1 ) ;
V_5 -> V_327 . V_328 = 0 ;
V_5 -> V_327 . V_329 = 2 ;
V_5 -> V_327 . V_330 = V_12 ;
V_5 -> V_14 = 1 ;
V_5 -> V_7 = 1 ;
V_20 = F_115 ( & V_5 -> V_240 ) ;
V_188 = F_115 ( & V_5 -> V_242 ) ;
if ( ! V_20 || ! V_188 ) {
F_175 ( V_2 ) ;
return - V_40 ;
}
V_188 -> V_12 = V_12 ;
V_20 -> V_3 = V_3 ;
V_5 -> V_318 = V_331 ;
V_2 -> V_298 = V_332 ;
return 0 ;
}
static void F_186 ( struct V_1 * V_2 ,
int V_81 )
{
unsigned int V_333 ;
int V_334 = V_81 ? ( V_81 - 1 ) : 1 ;
switch ( V_81 ) {
default:
case 0 :
case 2 :
V_333 = 0x00 ;
break;
case 4 :
V_333 = 0x08 ;
break;
case 6 :
V_333 = 0x0b ;
break;
case 8 :
V_333 = 0x13 ;
break;
}
F_21 ( V_2 , 0x1 , 0 ,
V_335 , V_333 ) ;
F_21 ( V_2 , 0x1 , 0 ,
V_336 ,
( 0x71 - V_334 - V_333 ) ) ;
}
static int F_187 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_200 * V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_76 ;
F_21 ( V_2 , V_337 ,
0 , V_338 , 0 ) ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
F_21 ( V_2 , V_339 [ V_76 ] , 0 ,
V_338 , 0 ) ;
F_21 ( V_2 , V_339 [ V_76 ] , 0 ,
V_340 , 0 ) ;
}
F_186 ( V_2 , 8 ) ;
return F_182 ( V_2 , & V_5 -> V_327 ) ;
}
static int F_188 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_182 ,
unsigned int V_183 ,
struct V_200 * V_201 )
{
int V_57 ;
unsigned int V_341 , V_342 ;
int V_76 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_249 * V_250 ;
struct V_187 * V_188 ;
F_10 ( & V_2 -> V_251 ) ;
V_188 = F_7 ( V_5 , 0 ) ;
V_250 = F_122 ( V_2 , V_188 -> V_12 ) ;
V_57 = V_201 -> V_203 -> V_81 ;
V_341 = 0x2 ;
if ( V_2 -> V_343 && ( V_250 -> V_344 & V_345 ) )
F_21 ( V_2 ,
V_337 ,
0 ,
V_346 ,
V_250 -> V_344 & ~ V_345 & 0xff ) ;
F_21 ( V_2 , V_337 , 0 ,
V_338 , ( V_182 << 4 ) | 0x0 ) ;
F_21 ( V_2 , V_337 , 0 ,
V_340 , V_183 ) ;
if ( V_2 -> V_343 && ( V_250 -> V_344 & V_345 ) ) {
F_21 ( V_2 ,
V_337 ,
0 ,
V_346 ,
V_250 -> V_344 & 0xff ) ;
F_21 ( V_2 ,
V_337 ,
0 ,
V_347 , V_341 ) ;
}
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
if ( V_57 == 2 )
V_342 = 0 ;
else
V_342 = V_76 * 2 ;
if ( V_2 -> V_343 &&
( V_250 -> V_344 & V_345 ) )
F_21 ( V_2 ,
V_339 [ V_76 ] ,
0 ,
V_346 ,
V_250 -> V_344 & ~ V_345 & 0xff ) ;
F_21 ( V_2 ,
V_339 [ V_76 ] ,
0 ,
V_338 ,
( V_182 << 4 ) | V_342 ) ;
F_21 ( V_2 ,
V_339 [ V_76 ] ,
0 ,
V_340 ,
V_183 ) ;
if ( V_2 -> V_343 &&
( V_250 -> V_344 & V_345 ) ) {
F_21 ( V_2 ,
V_339 [ V_76 ] ,
0 ,
V_346 ,
V_250 -> V_344 & 0xff ) ;
F_21 ( V_2 ,
V_339 [ V_76 ] ,
0 ,
V_347 , V_341 ) ;
}
}
F_186 ( V_2 , V_57 ) ;
F_11 ( & V_2 -> V_251 ) ;
return 0 ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 = F_185 ( V_2 , V_337 ,
V_348 ) ;
if ( V_38 < 0 )
return V_38 ;
V_2 -> V_298 . V_299 = F_176 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_318 . V_206 = V_349 ;
V_5 -> V_318 . V_208 = V_350 ;
V_5 -> V_318 . V_207 = V_351 ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 = F_168 ( V_2 ) ;
if ( ! V_38 ) {
struct V_279 * V_89 = F_5 ( V_5 , 0 ) ;
V_89 -> V_284 = true ;
}
return V_38 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_279 * V_89 ;
struct V_255 * V_144 ;
int V_38 ;
V_38 = F_171 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_89 = F_5 ( V_5 , 0 ) ;
V_38 = F_144 ( V_89 -> V_290 ,
V_285 ,
V_352 , 8 , 0 , & V_144 ) ;
if ( V_38 < 0 )
return V_38 ;
switch ( V_2 -> V_324 -> V_41 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_144 -> V_353 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_144 -> V_353 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_192 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 = F_189 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_327 . V_329 = 8 ;
V_5 -> V_318 = V_354 ;
V_2 -> V_298 . V_299 = F_178 ;
V_2 -> V_298 . V_355 = F_190 ;
V_2 -> V_298 . V_356 = F_191 ;
F_186 ( V_2 , 8 ) ;
return 0 ;
}
static int F_193 ( struct V_78 * V_260 ,
int V_81 )
{
if ( V_260 -> V_85 == 0x00 && V_81 == 2 )
return V_357 ;
return F_128 ( V_260 , V_81 ) ;
}
static int F_194 ( int V_84 , int V_57 , unsigned char * V_105 )
{
if ( V_84 == 0x00 && ( V_105 [ 0 ] != V_358 || V_105 [ 1 ] != V_359 ) )
return - V_8 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 ;
V_38 = F_166 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_53 = true ;
V_5 -> V_92 . V_268 =
F_193 ;
V_5 -> V_92 . V_278 = F_194 ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , T_1 V_146 ,
unsigned char * V_86 , int * V_29 )
{
return F_197 ( V_2 , V_146 , V_86 , V_29 ,
F_198 ( V_2 ) ) ;
}
static void F_199 ( struct V_1 * V_2 , T_1 V_3 , int V_84 ,
int V_132 , int V_133 )
{
F_21 ( V_2 , V_3 , 0 , V_360 , V_84 ) ;
}
static int F_200 ( int V_107 )
{
switch ( V_107 ) {
case 2 : return 3 ;
case 3 : return 2 ;
default: break;
}
return V_107 ;
}
static int F_201 ( int V_84 , int V_57 , unsigned char * V_105 )
{
struct V_78 * V_260 ;
int V_76 , V_77 ;
V_260 = & V_80 [ F_37 ( V_84 ) ] ;
for ( V_76 = 0 ; V_76 < V_57 ; ++ V_76 ) {
int V_108 = F_45 ( V_105 [ V_76 ] ) ;
bool V_361 = false ;
bool V_362 = false ;
if ( ! V_108 )
continue;
for ( V_77 = 0 + V_76 % 2 ; V_77 < 8 ; V_77 += 2 ) {
int V_363 = 7 - F_200 ( V_77 ) ;
if ( V_260 -> V_83 [ V_363 ] == V_108 ) {
V_361 = true ;
if ( V_76 % 2 == 0 && V_76 + 1 < V_57 ) {
int V_364 = 7 - F_200 ( V_77 + 1 ) ;
int V_365 = F_45 ( V_105 [ V_76 + 1 ] ) ;
int V_366 = V_260 -> V_83 [ V_364 ] ;
if ( V_365 == V_366 )
V_362 = true ;
else
return - V_8 ;
}
break;
}
}
if ( ! V_361 )
return - V_8 ;
if ( V_362 )
V_76 ++ ;
}
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , T_1 V_3 ,
int V_99 , int V_367 )
{
int V_368 ;
int V_369 = 0 ;
if ( V_99 > 7 )
return - V_8 ;
if ( ! F_203 ( V_2 ) ) {
V_99 = F_200 ( V_99 ) ;
if ( V_99 % 2 != 0 && V_367 == 0xf )
return 0 ;
V_99 -= V_99 % 2 ;
if ( V_367 != 0xf )
V_367 -= V_367 % 2 ;
}
V_368 = V_370 + V_99 / 2 + ( V_99 % 2 ) * 0x00e ;
if ( V_367 != 0xf )
V_369 = ( V_367 << 4 ) | V_371 ;
return F_21 ( V_2 , V_3 , 0 , V_368 , V_369 ) ;
}
static int F_204 ( struct V_1 * V_2 , T_1 V_3 ,
int V_115 )
{
bool V_372 = false ;
int V_373 = V_115 ;
int V_368 ;
int V_369 ;
if ( V_115 > 7 )
return - V_8 ;
if ( ! F_203 ( V_2 ) ) {
V_373 = F_200 ( V_115 ) ;
if ( V_373 % 2 != 0 ) {
V_373 -= 1 ;
V_372 = true ;
}
}
V_368 = V_374 + V_373 / 2 + ( V_373 % 2 ) * 0x00e ;
V_369 = F_19 ( V_2 , V_3 , 0 , V_368 , 0 ) ;
if ( ! ( V_369 & V_371 ) )
return 0xf ;
return ( ( V_369 & 0xf0 ) >> 4 ) + ! ! V_372 ;
}
static int F_205 ( struct V_78 * V_260 ,
int V_81 )
{
int V_68 ;
int V_375 = 0 ;
if ( ( V_81 % 2 ) != 0 )
return - 1 ;
for ( V_68 = 0 ; V_68 < 7 ; V_68 += 2 ) {
if ( V_260 -> V_83 [ V_68 ] || V_260 -> V_83 [ V_68 + 1 ] )
V_375 ++ ;
}
if ( V_375 * 2 != V_81 )
return - 1 ;
return V_376 ;
}
static void F_206 ( struct V_78 * V_260 ,
unsigned int * V_144 , int V_81 )
{
int V_27 = 0 ;
int V_68 ;
for ( V_68 = 7 ; V_68 >= 0 ; V_68 -- ) {
int V_334 = 7 - F_200 ( 7 - V_68 ) ;
int V_109 = V_260 -> V_83 [ V_334 ] ;
if ( ! V_109 ) {
if ( V_260 -> V_83 [ V_334 + ( V_334 % 2 ? - 1 : 1 ) ] )
V_144 [ V_27 ++ ] = V_377 ;
continue;
}
V_144 [ V_27 ++ ] = F_47 ( V_109 ) ;
}
F_44 ( V_27 != V_81 ) ;
}
static int F_207 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_174 )
{
int V_378 , V_379 ;
V_378 = F_19 ( V_2 , V_3 , 0 , V_380 , 0 ) ;
if ( V_378 >= 0 && ( V_378 & V_381 ) ) {
if ( V_174 )
V_379 = V_378 | V_382 ;
else
V_379 = V_378 & ~ V_382 ;
F_40 ( V_2 ,
L_32 ,
V_3 ,
V_378 == V_379 ? L_19 : L_20 ,
V_379 ) ;
if ( V_378 != V_379 )
F_21 ( V_2 , V_3 , 0 ,
V_383 ,
V_379 ) ;
} else if ( V_174 )
return - V_8 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_3 , T_3 V_182 , int V_183 )
{
if ( F_198 ( V_2 ) ) {
int V_384 = 180 ;
if ( V_183 & V_385 )
V_384 = 0 ;
F_21 ( V_2 , V_12 , 0 , V_386 , V_384 ) ;
}
return F_81 ( V_2 , V_12 , V_3 , V_182 , V_183 ) ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 , V_38 ;
V_38 = F_148 ( V_2 ) ;
if ( V_38 )
return V_38 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 , V_387 , 0 ) ;
if ( F_203 ( V_2 ) )
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_388 ,
V_389 ) ;
}
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_187 * V_188 ;
int V_38 , V_13 ;
V_38 = F_166 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_298 . V_299 = F_209 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_92 . V_224 = F_196 ;
V_5 -> V_92 . V_93 = F_204 ;
V_5 -> V_92 . V_101 = F_202 ;
V_5 -> V_92 . V_145 = F_199 ;
V_5 -> V_92 . V_184 = F_207 ;
V_5 -> V_92 . V_254 = F_208 ;
if ( ! F_203 ( V_2 ) ) {
V_5 -> V_92 . V_268 =
F_205 ;
V_5 -> V_92 . V_270 = F_206 ;
V_5 -> V_92 . V_278 = F_201 ;
}
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_188 = F_7 ( V_5 , V_13 ) ;
V_188 -> V_205 = V_258 ( V_188 -> V_205 , 8u ) ;
V_188 -> V_206 |= V_349 ;
V_188 -> V_207 |= V_351 ;
V_188 -> V_208 = V_258 ( V_188 -> V_208 , 24u ) ;
}
V_5 -> V_205 = V_258 ( V_5 -> V_205 , 8u ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
return F_185 ( V_2 , V_390 , V_391 ) ;
}
