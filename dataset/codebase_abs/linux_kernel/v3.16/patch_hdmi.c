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
static int F_38 ( struct V_21 * V_22 , int V_81 )
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
F_40 ( L_5 ,
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
F_43 ( V_2 , L_6 ,
V_91 , V_76 ) ;
}
#endif
}
static void F_44 ( struct V_1 * V_2 ,
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
while ( ! V_95 -> V_83 [ 7 - V_99 ] && ! F_45 ( V_99 >= 8 ) )
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
F_43 ( V_2 , L_7 ) ;
break;
}
}
}
static int F_46 ( unsigned char V_69 )
{
struct V_102 * V_103 = V_104 ;
for (; V_103 -> V_105 ; V_103 ++ ) {
if ( V_103 -> V_105 == V_69 )
return V_103 -> V_82 ;
}
return 0 ;
}
static int F_47 ( int V_106 , unsigned char V_107 )
{
int V_108 = F_46 ( V_107 ) ;
int V_76 ;
if ( V_108 ) {
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
if ( V_80 [ V_106 ] . V_83 [ 7 - V_76 ] == V_108 )
return V_76 ;
}
}
return - 1 ;
}
static int F_48 ( int V_109 )
{
struct V_102 * V_103 = V_104 ;
for (; V_103 -> V_105 ; V_103 ++ ) {
if ( V_103 -> V_82 == V_109 )
return V_103 -> V_105 ;
}
return 0 ;
}
static int F_49 ( int V_106 , unsigned char V_110 )
{
int V_108 = V_80 [ V_106 ] . V_83 [ 7 - V_110 ] ;
return F_48 ( V_108 ) ;
}
static int F_50 ( int V_57 , unsigned char * V_105 )
{
int V_76 , V_111 = 0 , V_82 = 0 ;
for ( V_76 = 0 ; V_76 < V_57 ; V_76 ++ ) {
int V_108 = F_46 ( V_105 [ V_76 ] ) ;
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
static int F_51 ( struct V_1 * V_2 ,
T_1 V_3 ,
int V_57 , unsigned char * V_105 ,
int V_84 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_106 = F_37 ( V_84 ) ;
int V_112 , V_99 ;
int V_113 [ 8 ] = { [ 0 ... 7 ] = 0xf } ;
for ( V_112 = 0 ; V_112 < V_57 ; V_112 ++ ) {
V_99 = F_47 ( V_106 , V_105 [ V_112 ] ) ;
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
static void F_52 ( unsigned char * V_105 , int V_84 )
{
int V_76 ;
int V_106 = F_37 ( V_84 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
if ( V_76 < V_80 [ V_106 ] . V_81 )
V_105 [ V_76 ] = F_49 ( V_106 , V_98 [ V_84 ] [ V_76 ] & 0x0f ) ;
else
V_105 [ V_76 ] = 0 ;
}
}
static void F_53 ( struct V_1 * V_2 ,
T_1 V_3 , bool V_94 , int V_84 ,
int V_81 , unsigned char * V_105 ,
bool V_114 )
{
if ( ! V_94 && V_114 ) {
F_51 ( V_2 , V_3 ,
V_81 , V_105 , V_84 ) ;
} else {
F_44 ( V_2 , V_3 , V_94 , V_84 ) ;
F_52 ( V_105 , V_84 ) ;
}
F_41 ( V_2 , V_3 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_3 ,
int V_115 , int V_91 )
{
return F_21 ( V_2 , V_3 , 0 ,
V_116 ,
( V_91 << 4 ) | V_115 ) ;
}
static int F_55 ( struct V_1 * V_2 , T_1 V_3 ,
int V_115 )
{
return ( F_19 ( V_2 , V_3 , 0 ,
V_117 ,
V_115 ) & 0xf0 ) >> 4 ;
}
static void F_56 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_2 , V_3 , 0 , V_118 ,
V_119 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
F_21 ( V_2 , V_3 , 0 , V_118 ,
V_120 ) ;
}
static void F_58 ( struct V_1 * V_2 , T_1 V_3 )
{
#ifdef F_42
int V_76 ;
int V_121 ;
V_121 = F_59 ( V_2 , V_3 ) ;
F_43 ( V_2 , L_8 , V_121 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
V_121 = F_19 ( V_2 , V_3 , 0 ,
V_122 , V_76 ) ;
F_43 ( V_2 , L_9 , V_76 , V_121 ) ;
}
#endif
}
static void F_60 ( struct V_1 * V_2 , T_1 V_3 )
{
#ifdef F_61
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
F_43 ( V_2 , L_10 ,
V_124 , V_123 , V_76 ) ;
if ( V_124 == 0 )
break;
}
F_43 ( V_2 ,
L_11 ,
V_76 , V_121 , V_77 ) ;
}
#endif
}
static void F_62 ( struct V_125 * V_126 )
{
T_2 * V_33 = ( T_2 * ) V_126 ;
T_2 V_127 = 0 ;
int V_76 ;
V_126 -> V_128 = 0 ;
for ( V_76 = 0 ; V_76 < sizeof( * V_126 ) ; V_76 ++ )
V_127 += V_33 [ V_76 ] ;
V_126 -> V_128 = - V_127 ;
}
static void F_63 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_129 , int V_121 )
{
int V_76 ;
F_58 ( V_2 , V_3 ) ;
F_60 ( V_2 , V_3 ) ;
F_20 ( V_2 , V_3 , 0x0 , 0x0 ) ;
for ( V_76 = 0 ; V_76 < V_121 ; V_76 ++ )
F_22 ( V_2 , V_3 , V_129 [ V_76 ] ) ;
}
static bool F_64 ( struct V_1 * V_2 , T_1 V_3 ,
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
static void F_65 ( struct V_1 * V_2 ,
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
F_62 ( V_126 ) ;
} else if ( V_133 == 1 ) {
struct V_141 * V_142 = & V_135 . V_143 ;
V_142 -> type = 0x84 ;
V_142 -> V_138 = 0x1b ;
V_142 -> V_137 = 0x11 << 2 ;
V_142 -> V_139 = V_132 - 1 ;
V_142 -> V_140 = V_84 ;
} else {
F_43 ( V_2 , L_12 ,
V_3 ) ;
return;
}
if ( ! F_64 ( V_2 , V_3 , V_135 . V_33 ,
sizeof( V_135 ) ) ) {
F_43 ( V_2 ,
L_13 ,
V_3 ,
V_132 , V_84 ) ;
F_57 ( V_2 , V_3 ) ;
F_63 ( V_2 , V_3 ,
V_135 . V_33 , sizeof( V_135 ) ) ;
F_56 ( V_2 , V_3 ) ;
}
}
static void F_66 ( struct V_1 * V_2 ,
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
if ( F_67 ( V_2 ) )
F_21 ( V_2 , V_3 , 0 ,
V_51 ,
V_52 ) ;
V_22 = & V_20 -> V_25 ;
if ( ! V_94 && V_20 -> V_114 )
V_84 = F_50 ( V_81 , V_20 -> V_144 ) ;
else
V_84 = F_38 ( V_22 , V_81 ) ;
if ( V_84 < 0 )
V_84 = 0 ;
V_106 = F_37 ( V_84 ) ;
V_132 = V_80 [ V_106 ] . V_81 ;
F_26 ( V_2 , V_20 -> V_12 , V_132 ) ;
F_53 ( V_2 , V_3 , V_94 , V_84 ,
V_81 , V_20 -> V_144 ,
V_20 -> V_114 ) ;
V_5 -> V_92 . V_145 ( V_2 , V_3 , V_84 , V_132 ,
V_22 -> V_89 . V_133 ) ;
V_20 -> V_94 = V_94 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = F_1 ( V_2 , V_147 -> V_148 ) ;
if ( V_6 < 0 )
return;
if ( F_69 ( F_2 ( V_5 , V_6 ) , 1 ) )
F_70 ( V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_149 )
{
int V_150 = V_149 >> V_151 ;
struct V_146 * V_147 ;
int V_152 = ( V_149 & V_153 ) >> V_154 ;
V_147 = F_72 ( V_2 , V_150 ) ;
if ( ! V_147 )
return;
V_147 -> V_155 = 1 ;
F_43 ( V_2 ,
L_14 ,
V_2 -> V_66 , V_147 -> V_148 , V_152 , ! ! ( V_149 & V_156 ) ,
! ! ( V_149 & V_157 ) , ! ! ( V_149 & V_158 ) ) ;
F_68 ( V_2 , V_147 ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned int V_149 )
{
int V_150 = V_149 >> V_151 ;
int V_159 = ( V_149 & V_160 ) >> V_161 ;
int V_162 = ! ! ( V_149 & V_163 ) ;
int V_164 = ! ! ( V_149 & V_165 ) ;
F_74 ( V_2 ,
L_15 ,
V_2 -> V_66 ,
V_150 ,
V_159 ,
V_162 ,
V_164 ) ;
if ( V_162 )
;
if ( V_164 )
;
}
static void F_75 ( struct V_1 * V_2 , unsigned int V_149 )
{
int V_150 = V_149 >> V_151 ;
int V_159 = ( V_149 & V_160 ) >> V_161 ;
if ( ! F_72 ( V_2 , V_150 ) ) {
F_43 ( V_2 , L_16 , V_150 ) ;
return;
}
if ( V_159 == 0 )
F_71 ( V_2 , V_149 ) ;
else
F_73 ( V_2 , V_149 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_148 )
{
int V_166 ;
if ( ! F_77 ( V_2 , V_12 , V_167 ) )
F_21 ( V_2 , V_12 , 0 , V_168 , V_167 ) ;
if ( ! F_77 ( V_2 , V_148 , V_167 ) ) {
F_21 ( V_2 , V_148 , 0 , V_168 ,
V_167 ) ;
F_78 ( 40 ) ;
V_166 = F_19 ( V_2 , V_148 , 0 , V_169 , 0 ) ;
V_166 = ( V_166 & V_170 ) >> V_171 ;
F_43 ( V_2 , L_17 , V_148 , V_166 ) ;
}
}
static int F_79 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_172 )
{
int V_173 , V_174 ;
if ( F_80 ( V_2 , V_3 ) & V_175 ) {
V_173 = F_19 ( V_2 , V_3 , 0 ,
V_176 , 0 ) ;
if ( V_173 < 0 )
return V_172 ? - V_8 : 0 ;
V_174 = V_173 & ~ V_177 ;
if ( V_172 )
V_174 |= V_178 ;
else
V_174 |= V_179 ;
F_43 ( V_2 ,
L_18 ,
V_3 ,
V_173 == V_174 ? L_19 : L_20 ,
V_174 ) ;
if ( V_173 != V_174 )
F_21 ( V_2 , V_3 , 0 ,
V_55 ,
V_174 ) ;
} else if ( V_172 )
return - V_8 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_3 , T_3 V_180 , int V_181 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 ;
if ( F_67 ( V_2 ) )
F_76 ( V_2 , V_12 , V_3 ) ;
V_38 = V_5 -> V_92 . V_182 ( V_2 , V_3 , F_82 ( V_181 ) ) ;
if ( V_38 ) {
F_43 ( V_2 , L_21 ) ;
return V_38 ;
}
F_83 ( V_2 , V_12 , V_180 , 0 , V_181 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
int V_6 , int * V_183 , int * V_184 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 ;
struct V_185 * V_186 = NULL ;
int V_13 , V_187 = 0 ;
V_20 = F_2 ( V_5 , V_6 ) ;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_186 = F_7 ( V_5 , V_13 ) ;
if ( V_186 -> V_188 )
continue;
for ( V_187 = 0 ; V_187 < V_20 -> V_189 ; V_187 ++ )
if ( V_20 -> V_190 [ V_187 ] == V_186 -> V_12 )
break;
if ( V_187 == V_20 -> V_189 )
continue;
break;
}
if ( V_13 == V_5 -> V_14 )
return - V_191 ;
V_20 -> V_187 = V_187 ;
if ( V_183 )
* V_183 = V_13 ;
if ( V_184 )
* V_184 = V_187 ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_1 V_3 = V_20 -> V_3 ;
int V_187 , V_192 ;
V_187 = V_20 -> V_187 ;
V_192 = F_19 ( V_2 , V_3 , 0 ,
V_193 , 0 ) ;
if ( V_192 != V_187 )
F_86 ( V_2 , V_3 , 0 ,
V_194 ,
V_187 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
T_1 V_3 , int V_187 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_148 , V_195 ;
int V_13 , V_192 ;
struct V_185 * V_186 ;
V_195 = V_2 -> V_196 + V_2 -> V_197 ;
for ( V_148 = V_2 -> V_196 ; V_148 < V_195 ; V_148 ++ ) {
unsigned int V_198 = F_24 ( V_2 , V_148 ) ;
unsigned int V_199 = F_88 ( V_198 ) ;
if ( V_199 != V_200 )
continue;
if ( V_148 == V_3 )
continue;
V_192 = F_19 ( V_2 , V_148 , 0 ,
V_193 , 0 ) ;
if ( V_192 != V_187 )
continue;
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_186 = F_7 ( V_5 , V_13 ) ;
if ( ! V_186 -> V_188 ) {
F_43 ( V_2 ,
L_22 ,
V_13 , V_148 ) ;
F_86 ( V_2 , V_148 , 0 ,
V_194 ,
V_13 ) ;
break;
}
}
}
}
static int F_89 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_203 * V_204 = V_202 -> V_204 ;
int V_6 , V_13 , V_187 = 0 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_185 * V_186 = NULL ;
int V_38 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_90 ( V_6 < 0 ) )
return - V_8 ;
V_20 = F_2 ( V_5 , V_6 ) ;
V_22 = & V_20 -> V_25 ;
V_38 = F_84 ( V_2 , V_6 , & V_13 , & V_187 ) ;
if ( V_38 < 0 )
return V_38 ;
V_186 = F_7 ( V_5 , V_13 ) ;
V_186 -> V_188 = 1 ;
V_20 -> V_12 = V_186 -> V_12 ;
V_10 -> V_148 = V_186 -> V_12 ;
F_86 ( V_2 , V_20 -> V_3 , 0 ,
V_194 ,
V_187 ) ;
if ( F_67 ( V_2 ) || F_91 ( V_2 ) )
F_87 ( V_2 , V_20 -> V_3 , V_187 ) ;
F_92 ( V_2 , V_6 , V_186 -> V_12 ) ;
V_10 -> V_205 = V_186 -> V_205 ;
V_10 -> V_206 = V_186 -> V_206 ;
V_10 -> V_207 = V_186 -> V_207 ;
V_10 -> V_208 = V_186 -> V_208 ;
V_10 -> V_209 = V_186 -> V_209 ;
if ( ! V_210 && V_22 -> V_28 ) {
F_93 ( & V_22 -> V_89 , V_10 ) ;
if ( V_10 -> V_205 > V_10 -> V_206 ||
! V_10 -> V_207 || ! V_10 -> V_208 ) {
V_186 -> V_188 = 0 ;
V_10 -> V_148 = 0 ;
F_94 ( V_2 , V_6 ) ;
return - V_191 ;
}
}
V_204 -> V_211 . V_205 = V_10 -> V_205 ;
V_204 -> V_211 . V_206 = V_10 -> V_206 ;
V_204 -> V_211 . V_208 = V_10 -> V_208 ;
V_204 -> V_211 . V_207 = V_10 -> V_207 ;
F_95 ( V_202 -> V_204 , 0 ,
V_212 , 2 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
if ( ! ( F_24 ( V_2 , V_3 ) & V_213 ) ) {
F_3 ( V_2 ,
L_23 ,
V_3 , F_24 ( V_2 , V_3 ) ) ;
return - V_8 ;
}
V_20 -> V_189 = F_97 ( V_2 , V_3 ,
V_20 -> V_190 ,
V_214 ) ;
return 0 ;
}
static bool F_69 ( struct V_19 * V_20 , int V_215 )
{
struct V_146 * V_147 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_22 = & V_5 -> V_216 ;
struct V_21 * V_217 = & V_20 -> V_25 ;
T_1 V_3 = V_20 -> V_3 ;
int V_218 ;
bool V_219 = false ;
bool V_220 = false ;
bool V_221 ;
F_98 ( V_2 ) ;
V_218 = F_99 ( V_2 , V_3 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_217 -> V_222 = ! ! ( V_218 & V_223 ) ;
if ( V_217 -> V_222 )
V_22 -> V_28 = ! ! ( V_218 & V_224 ) ;
else
V_22 -> V_28 = false ;
F_43 ( V_2 ,
L_24 ,
V_2 -> V_66 , V_3 , V_217 -> V_222 , V_22 -> V_28 ) ;
if ( V_22 -> V_28 ) {
if ( V_5 -> V_92 . V_225 ( V_2 , V_3 , V_22 -> V_35 ,
& V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
else {
memset ( & V_22 -> V_89 , 0 , sizeof( struct V_226 ) ) ;
if ( F_100 ( & V_22 -> V_89 , V_22 -> V_35 ,
V_22 -> V_29 ) < 0 )
V_22 -> V_28 = false ;
}
if ( V_22 -> V_28 ) {
F_101 ( & V_22 -> V_89 ) ;
V_219 = true ;
}
else if ( V_215 ) {
F_102 ( V_2 -> V_67 -> V_227 ,
& V_20 -> V_228 ,
F_103 ( 300 ) ) ;
goto V_229;
}
}
if ( V_217 -> V_28 && ! V_22 -> V_28 ) {
V_219 = true ;
V_220 = true ;
}
if ( V_219 ) {
bool V_230 = V_217 -> V_28 ;
V_217 -> V_28 = V_22 -> V_28 ;
V_220 = V_217 -> V_29 != V_22 -> V_29 ||
memcmp ( V_217 -> V_35 , V_22 -> V_35 ,
V_22 -> V_29 ) != 0 ;
if ( V_220 )
memcpy ( V_217 -> V_35 , V_22 -> V_35 ,
V_22 -> V_29 ) ;
V_217 -> V_29 = V_22 -> V_29 ;
V_217 -> V_89 = V_22 -> V_89 ;
if ( V_22 -> V_28 && ! V_230 && V_20 -> V_231 ) {
if ( F_67 ( V_2 ) || F_91 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_3 ,
V_20 -> V_187 ) ;
}
F_66 ( V_2 , V_20 ,
V_20 -> V_94 ) ;
}
}
if ( V_220 )
F_104 ( V_2 -> V_67 -> V_68 ,
V_232 | V_233 ,
& V_20 -> V_42 -> V_41 ) ;
V_229:
V_221 = ! V_215 || ! V_217 -> V_222 || V_217 -> V_28 ;
V_147 = F_105 ( V_2 , V_3 ) ;
if ( V_147 )
V_147 -> V_234 = ! V_221 ;
F_11 ( & V_20 -> V_26 ) ;
F_106 ( V_2 ) ;
return V_221 ;
}
static void F_107 ( struct V_235 * V_228 )
{
struct V_19 * V_20 =
F_108 ( F_109 ( V_228 ) , struct V_19 , V_228 ) ;
if ( V_20 -> V_236 ++ > 6 )
V_20 -> V_236 = 0 ;
if ( F_69 ( V_20 , V_20 -> V_236 ) )
F_70 ( V_20 -> V_2 ) ;
}
static int F_110 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_237 , V_238 ;
int V_6 ;
struct V_19 * V_20 ;
int V_38 ;
V_237 = F_80 ( V_2 , V_3 ) ;
if ( ! ( V_237 & ( V_239 | V_240 ) ) )
return 0 ;
V_238 = F_111 ( V_2 , V_3 ) ;
if ( F_112 ( V_238 ) == V_241 )
return 0 ;
if ( F_67 ( V_2 ) )
F_113 ( V_2 , V_3 ) ;
V_6 = V_5 -> V_7 ;
V_20 = F_114 ( & V_5 -> V_242 ) ;
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
struct V_185 * V_186 ;
unsigned int V_243 ;
int V_38 ;
V_243 = F_24 ( V_2 , V_12 ) ;
V_243 = F_116 ( V_243 ) ;
V_186 = F_114 ( & V_5 -> V_244 ) ;
if ( ! V_186 )
return - V_40 ;
V_186 -> V_12 = V_12 ;
V_186 -> V_205 = 2 ;
if ( V_243 <= 16 ) {
V_186 -> V_206 = V_243 ;
if ( V_243 > V_5 -> V_206 )
V_5 -> V_206 = V_243 ;
}
V_38 = F_117 ( V_2 , V_12 ,
& V_186 -> V_207 ,
& V_186 -> V_208 ,
& V_186 -> V_209 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_5 -> V_14 < F_13 ( V_5 -> V_245 ) )
V_5 -> V_245 [ V_5 -> V_14 ] = V_12 ;
V_5 -> V_14 ++ ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
T_1 V_148 ;
int V_76 , V_246 ;
V_246 = F_119 ( V_2 , V_2 -> V_247 , & V_148 ) ;
if ( ! V_148 || V_246 < 0 ) {
F_3 ( V_2 , L_25 ) ;
return - V_8 ;
}
for ( V_76 = 0 ; V_76 < V_246 ; V_76 ++ , V_148 ++ ) {
unsigned int V_237 ;
unsigned int type ;
V_237 = F_24 ( V_2 , V_148 ) ;
type = F_88 ( V_237 ) ;
if ( ! ( V_237 & V_248 ) )
continue;
switch ( type ) {
case V_249 :
F_115 ( V_2 , V_148 ) ;
break;
case V_200 :
F_110 ( V_2 , V_148 ) ;
break;
}
}
return 0 ;
}
static bool F_120 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_250 * V_251 ;
bool V_94 ;
F_10 ( & V_2 -> V_252 ) ;
V_251 = F_121 ( V_2 , V_12 ) ;
V_94 = ! ! ( V_251 -> V_253 & V_254 ) ;
F_11 ( & V_2 -> V_252 ) ;
return V_94 ;
}
static int F_122 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_180 ,
unsigned int V_181 ,
struct V_201 * V_202 )
{
T_1 V_12 = V_10 -> V_148 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = F_4 ( V_2 , V_10 ) ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
T_1 V_3 = V_20 -> V_3 ;
bool V_94 ;
int V_173 ;
if ( F_67 ( V_2 ) || F_91 ( V_2 ) ) {
F_85 ( V_2 , V_20 ) ;
F_87 ( V_2 , V_3 , V_20 -> V_187 ) ;
}
V_94 = F_120 ( V_2 , V_12 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_81 = V_202 -> V_204 -> V_81 ;
V_20 -> V_231 = true ;
F_66 ( V_2 , V_20 , V_94 ) ;
F_11 ( & V_20 -> V_26 ) ;
if ( V_5 -> V_53 ) {
V_173 = F_19 ( V_2 , V_3 , 0 ,
V_176 , 0 ) ;
F_21 ( V_2 , V_3 , 0 ,
V_55 ,
V_173 | V_54 ) ;
}
return V_5 -> V_92 . V_255 ( V_2 , V_12 , V_3 , V_180 , V_181 ) ;
}
static int F_123 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_201 * V_202 )
{
F_124 ( V_2 , V_10 -> V_148 ) ;
return 0 ;
}
static int F_125 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_13 , V_6 ;
struct V_185 * V_186 ;
struct V_19 * V_20 ;
int V_173 ;
if ( V_10 -> V_148 ) {
V_13 = F_6 ( V_2 , V_10 -> V_148 ) ;
if ( F_90 ( V_13 < 0 ) )
return - V_8 ;
V_186 = F_7 ( V_5 , V_13 ) ;
F_90 ( ! V_186 -> V_188 ) ;
V_186 -> V_188 = 0 ;
V_10 -> V_148 = 0 ;
V_6 = F_4 ( V_2 , V_10 ) ;
if ( F_90 ( V_6 < 0 ) )
return - V_8 ;
V_20 = F_2 ( V_5 , V_6 ) ;
if ( V_5 -> V_53 ) {
V_173 = F_19 ( V_2 , V_20 -> V_3 , 0 ,
V_176 , 0 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_55 ,
V_173 & ~ V_54 ) ;
}
F_94 ( V_2 , V_6 ) ;
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_114 = false ;
memset ( V_20 -> V_144 , 0 , sizeof( V_20 -> V_144 ) ) ;
V_20 -> V_231 = false ;
V_20 -> V_81 = 0 ;
F_11 ( & V_20 -> V_26 ) ;
}
return 0 ;
}
static int F_126 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_256 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_18 -> type = V_257 ;
V_18 -> V_27 = V_5 -> V_206 ;
V_18 -> V_32 . integer . V_258 = 0 ;
V_18 -> V_32 . integer . V_259 = V_260 ;
return 0 ;
}
static int F_127 ( struct V_78 * V_261 ,
int V_81 )
{
if ( V_261 -> V_81 != V_81 )
return - 1 ;
return V_262 ;
}
static void F_128 ( struct V_78 * V_261 ,
unsigned int * V_144 , int V_81 )
{
int V_27 = 0 ;
int V_69 ;
for ( V_69 = 7 ; V_69 >= 0 ; V_69 -- ) {
int V_109 = V_261 -> V_83 [ V_69 ] ;
if ( ! V_109 )
continue;
V_144 [ V_27 ++ ] = F_48 ( V_109 ) ;
}
F_45 ( V_27 != V_81 ) ;
}
static int F_129 ( struct V_15 * V_16 , int V_263 ,
unsigned int V_121 , unsigned int T_4 * V_264 )
{
struct V_256 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int T_4 * V_265 ;
int V_57 , V_27 = 0 ;
if ( V_121 < 8 )
return - V_40 ;
if ( F_130 ( V_266 , V_264 ) )
return - V_267 ;
V_121 -= 8 ;
V_265 = V_264 + 2 ;
for ( V_57 = 2 ; V_57 <= V_5 -> V_206 ; V_57 ++ ) {
int V_76 ;
struct V_78 * V_261 ;
V_261 = V_80 ;
for ( V_76 = 0 ; V_76 < F_13 ( V_80 ) ; V_76 ++ , V_261 ++ ) {
int V_268 = V_57 * 4 ;
int type = V_5 -> V_92 . V_269 ( V_261 , V_57 ) ;
unsigned int V_270 [ 8 ] ;
if ( type < 0 )
continue;
if ( V_121 < 8 )
return - V_40 ;
if ( F_130 ( type , V_265 ) ||
F_130 ( V_268 , V_265 + 1 ) )
return - V_267 ;
V_265 += 2 ;
V_121 -= 8 ;
V_27 += 8 ;
if ( V_121 < V_268 )
return - V_40 ;
V_121 -= V_268 ;
V_27 += V_268 ;
V_5 -> V_92 . V_271 ( V_261 , V_270 , V_57 ) ;
if ( F_131 ( V_265 , V_270 , V_268 ) )
return - V_267 ;
V_265 += V_57 ;
}
}
if ( F_130 ( V_27 , V_264 + 1 ) )
return - V_267 ;
return 0 ;
}
static int F_132 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
struct V_256 * V_89 = F_9 ( V_16 ) ;
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
struct V_256 * V_89 = F_9 ( V_16 ) ;
struct V_1 * V_2 = V_89 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_16 -> V_24 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
unsigned int V_272 ;
struct V_201 * V_202 ;
unsigned char V_144 [ 8 ] ;
int V_76 , V_38 , V_84 , V_273 = 0 ;
V_272 = F_134 ( V_16 , & V_31 -> V_41 ) ;
V_202 = F_135 ( V_89 , V_272 ) ;
if ( ! V_202 || ! V_202 -> V_204 )
return 0 ;
switch ( V_202 -> V_204 -> V_253 -> V_274 ) {
case V_275 :
case V_276 :
break;
case V_277 :
V_273 = 1 ;
break;
default:
return - V_278 ;
}
memset ( V_144 , 0 , sizeof( V_144 ) ) ;
for ( V_76 = 0 ; V_76 < F_13 ( V_144 ) ; V_76 ++ )
V_144 [ V_76 ] = V_31 -> V_32 . integer . V_32 [ V_76 ] ;
if ( ! memcmp ( V_144 , V_20 -> V_144 , sizeof( V_144 ) ) )
return 0 ;
V_84 = F_50 ( F_13 ( V_144 ) , V_144 ) ;
if ( V_84 < 0 )
return - V_8 ;
if ( V_5 -> V_92 . V_279 ) {
V_38 = V_5 -> V_92 . V_279 ( V_84 , F_13 ( V_144 ) , V_144 ) ;
if ( V_38 )
return V_38 ;
}
F_10 ( & V_20 -> V_26 ) ;
V_20 -> V_114 = true ;
memcpy ( V_20 -> V_144 , V_144 , sizeof( V_144 ) ) ;
if ( V_273 )
F_66 ( V_2 , V_20 , V_20 -> V_94 ) ;
F_11 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_280 * V_89 ;
struct V_9 * V_281 ;
struct V_19 * V_20 ;
V_20 = F_2 ( V_5 , V_6 ) ;
sprintf ( V_20 -> V_282 , L_26 , V_6 ) ;
V_89 = F_114 ( & V_5 -> V_283 ) ;
if ( ! V_89 )
return - V_40 ;
V_89 -> V_65 = V_20 -> V_282 ;
V_89 -> V_284 = V_285 ;
V_89 -> V_286 = true ;
V_281 = & V_89 -> V_11 [ V_287 ] ;
V_281 -> V_288 = 1 ;
V_281 -> V_92 = V_289 ;
}
V_2 -> V_290 = V_5 -> V_7 ;
V_2 -> V_291 = V_5 -> V_283 . V_292 ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , int V_6 )
{
char V_293 [ 32 ] = L_27 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
int V_294 = F_5 ( V_5 , V_6 ) -> V_36 ;
if ( V_294 > 0 )
sprintf ( V_293 + strlen ( V_293 ) , L_28 , V_294 ) ;
if ( ! F_138 ( V_2 , V_20 -> V_3 ) )
strncat ( V_293 , L_29 ,
sizeof( V_293 ) - strlen ( V_293 ) - 1 ) ;
return F_139 ( V_2 , V_20 -> V_3 , V_293 , 0 ) ;
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
V_20 -> V_190 [ 0 ] ,
V_285 ) ;
if ( V_38 < 0 )
return V_38 ;
F_94 ( V_2 , V_6 ) ;
V_38 = F_15 ( V_2 , V_6 ,
F_5 ( V_5 , V_6 ) -> V_36 ) ;
if ( V_38 < 0 )
return V_38 ;
F_69 ( V_20 , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_256 * V_144 ;
struct V_15 * V_37 ;
int V_76 ;
if ( ! V_2 -> V_291 [ V_6 ] . V_295 )
break;
V_38 = F_142 ( V_2 -> V_291 [ V_6 ] . V_295 ,
V_287 ,
NULL , 0 , V_6 , & V_144 ) ;
if ( V_38 < 0 )
return V_38 ;
V_144 -> V_63 = V_2 ;
V_37 = V_144 -> V_37 ;
for ( V_76 = 0 ; V_76 < V_37 -> V_27 ; V_76 ++ )
V_37 -> V_296 [ V_76 ] . V_297 |= V_298 ;
V_37 -> V_89 = F_126 ;
V_37 -> V_299 = F_132 ;
V_37 -> V_300 = F_133 ;
V_37 -> V_264 . V_69 = F_129 ;
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
F_145 ( & V_20 -> V_228 , F_107 ) ;
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
F_147 ( V_2 , V_3 , V_3 ,
V_2 -> V_301 > 0 ? F_68 : NULL ) ;
}
return 0 ;
}
static void F_148 ( struct V_4 * V_5 , int V_302 )
{
F_149 ( & V_5 -> V_242 , sizeof( struct V_19 ) , V_302 ) ;
F_149 ( & V_5 -> V_244 , sizeof( struct V_185 ) , V_302 ) ;
F_149 ( & V_5 -> V_283 , sizeof( struct V_280 ) , V_302 ) ;
}
static void F_150 ( struct V_4 * V_5 )
{
F_151 ( & V_5 -> V_242 ) ;
F_151 ( & V_5 -> V_244 ) ;
F_151 ( & V_5 -> V_283 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_153 ( & V_20 -> V_228 ) ;
F_34 ( V_20 ) ;
}
F_154 ( V_2 -> V_67 -> V_227 ) ;
F_150 ( V_5 ) ;
F_155 ( V_5 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_2 -> V_303 . V_304 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_69 ( V_20 , 1 ) ;
}
return 0 ;
}
static void F_113 ( struct V_1 * V_2 ,
T_1 V_148 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_305 [ 4 ] ;
int V_306 ;
V_306 = F_97 ( V_2 , V_148 , V_305 , F_13 ( V_305 ) ) ;
if ( V_306 == V_5 -> V_14 &&
! memcmp ( V_305 , V_5 -> V_245 , V_5 -> V_14 * sizeof( T_1 ) ) )
return;
F_43 ( V_2 , L_30 , V_148 ) ;
F_159 ( V_2 , V_148 , V_5 -> V_14 , V_5 -> V_245 ) ;
}
static void F_160 ( struct V_1 * V_2 ,
bool V_307 )
{
unsigned int V_308 ;
V_308 = F_19 ( V_2 , V_309 , 0 ,
V_310 , 0 ) ;
if ( V_308 == - 1 || V_308 & V_311 )
return;
V_308 |= V_311 ;
V_308 = F_19 ( V_2 , V_309 , 0 ,
V_312 , V_308 ) ;
if ( V_308 == - 1 )
return;
if ( V_307 )
F_161 ( V_2 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
unsigned int V_308 ;
V_308 = F_19 ( V_2 , V_309 , 0 ,
V_310 , 0 ) ;
if ( V_308 == - 1 || V_308 & V_313 )
return;
V_308 |= V_313 ;
F_86 ( V_2 , V_309 , 0 ,
V_312 , V_308 ) ;
}
static void F_163 ( struct V_1 * V_2 , T_1 V_314 ,
unsigned int V_315 )
{
if ( V_315 == V_167 ) {
F_160 ( V_2 , false ) ;
F_162 ( V_2 ) ;
}
F_19 ( V_2 , V_314 , 0 , V_168 , V_315 ) ;
F_164 ( V_2 , V_314 , V_315 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_166 ( sizeof( * V_5 ) , V_316 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_5 -> V_92 = V_317 ;
V_2 -> V_5 = V_5 ;
F_148 ( V_5 , 4 ) ;
if ( F_67 ( V_2 ) ) {
F_160 ( V_2 , true ) ;
F_162 ( V_2 ) ;
}
if ( F_167 ( V_2 ) || F_91 ( V_2 ) ) {
V_2 -> V_318 = 0 ;
}
if ( F_118 ( V_2 ) < 0 ) {
V_2 -> V_5 = NULL ;
F_155 ( V_5 ) ;
return - V_8 ;
}
V_2 -> V_303 = V_319 ;
if ( F_67 ( V_2 ) ) {
V_2 -> V_303 . V_320 = F_163 ;
V_2 -> V_321 = true ;
}
F_143 ( V_2 ) ;
F_36 () ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_280 * V_89 ;
unsigned int V_243 ;
struct V_9 * V_281 ;
struct V_185 * V_186 ;
V_186 = F_7 ( V_5 , 0 ) ;
V_243 = F_24 ( V_2 , V_186 -> V_12 ) ;
V_243 = F_116 ( V_243 ) ;
V_89 = F_114 ( & V_5 -> V_283 ) ;
if ( ! V_89 )
return - V_40 ;
V_89 -> V_65 = F_2 ( V_5 , 0 ) -> V_282 ;
sprintf ( V_89 -> V_65 , L_31 ) ;
V_89 -> V_284 = V_285 ;
V_281 = & V_89 -> V_11 [ V_287 ] ;
* V_281 = V_5 -> V_322 ;
V_281 -> V_148 = V_186 -> V_12 ;
if ( V_281 -> V_206 <= 2 && V_243 && V_243 <= 16 )
V_281 -> V_206 = V_243 ;
V_2 -> V_290 = 1 ;
V_2 -> V_291 = V_89 ;
return 0 ;
}
static void F_169 ( struct V_1 * V_2 ,
unsigned int V_149 )
{
F_170 ( V_2 ) ;
F_70 ( V_2 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_185 * V_186 ;
int V_38 ;
V_186 = F_7 ( V_5 , 0 ) ;
V_38 = F_141 ( V_2 , V_186 -> V_12 ,
V_186 -> V_12 ,
V_285 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_172 ( V_2 , 0 ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_19 * V_20 = F_2 ( V_5 , 0 ) ;
T_1 V_323 = V_20 -> V_3 ;
F_21 ( V_2 , V_323 , 0 ,
V_55 , V_54 ) ;
if ( F_24 ( V_2 , V_323 ) & V_50 )
F_21 ( V_2 , V_323 , 0 , V_51 ,
V_52 ) ;
F_174 ( V_2 , V_323 , V_323 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_150 ( V_5 ) ;
F_155 ( V_5 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
F_177 ( V_2 , V_324 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 )
{
F_177 ( V_2 , V_325 ) ;
return 0 ;
}
static int F_179 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_326 * V_327 = NULL ;
switch ( V_2 -> V_328 -> V_41 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_327 = & V_329 ;
break;
case 0x10de0007 :
V_327 = & V_330 ;
break;
default:
break;
}
if ( V_327 != NULL ) {
V_326 ( V_202 -> V_204 , 0 ,
V_212 ,
V_327 ) ;
} else {
F_95 ( V_202 -> V_204 , 0 ,
V_212 , 2 ) ;
}
return F_180 ( V_2 , & V_5 -> V_331 ) ;
}
static int F_181 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_182 ( V_2 , & V_5 -> V_331 ) ;
}
static int F_183 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_180 ,
unsigned int V_181 ,
struct V_201 * V_202 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_184 ( V_2 , & V_5 -> V_331 ,
V_180 , V_181 , V_202 ) ;
}
static int F_185 ( struct V_1 * V_2 ,
T_1 V_12 , T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_185 * V_186 ;
struct V_19 * V_20 ;
V_5 = F_166 ( sizeof( * V_5 ) , V_316 ) ;
if ( ! V_5 )
return - V_40 ;
V_2 -> V_5 = V_5 ;
F_148 ( V_5 , 1 ) ;
V_5 -> V_331 . V_332 = 0 ;
V_5 -> V_331 . V_333 = 2 ;
V_5 -> V_331 . V_334 = V_12 ;
V_5 -> V_14 = 1 ;
V_5 -> V_7 = 1 ;
V_20 = F_114 ( & V_5 -> V_242 ) ;
V_186 = F_114 ( & V_5 -> V_244 ) ;
if ( ! V_20 || ! V_186 ) {
F_175 ( V_2 ) ;
return - V_40 ;
}
V_186 -> V_12 = V_12 ;
V_20 -> V_3 = V_3 ;
V_5 -> V_322 = V_335 ;
V_2 -> V_303 = V_336 ;
return 0 ;
}
static void F_186 ( struct V_1 * V_2 ,
int V_81 )
{
unsigned int V_337 ;
int V_338 = V_81 ? ( V_81 - 1 ) : 1 ;
switch ( V_81 ) {
default:
case 0 :
case 2 :
V_337 = 0x00 ;
break;
case 4 :
V_337 = 0x08 ;
break;
case 6 :
V_337 = 0x0b ;
break;
case 8 :
V_337 = 0x13 ;
break;
}
F_21 ( V_2 , 0x1 , 0 ,
V_339 , V_337 ) ;
F_21 ( V_2 , 0x1 , 0 ,
V_340 ,
( 0x71 - V_338 - V_337 ) ) ;
}
static int F_187 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_76 ;
F_21 ( V_2 , V_341 ,
0 , V_342 , 0 ) ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
F_21 ( V_2 , V_343 [ V_76 ] , 0 ,
V_342 , 0 ) ;
F_21 ( V_2 , V_343 [ V_76 ] , 0 ,
V_344 , 0 ) ;
}
F_186 ( V_2 , 8 ) ;
return F_182 ( V_2 , & V_5 -> V_331 ) ;
}
static int F_188 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_180 ,
unsigned int V_181 ,
struct V_201 * V_202 )
{
int V_57 ;
unsigned int V_345 , V_346 ;
int V_76 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_250 * V_251 ;
struct V_185 * V_186 ;
F_10 ( & V_2 -> V_252 ) ;
V_186 = F_7 ( V_5 , 0 ) ;
V_251 = F_121 ( V_2 , V_186 -> V_12 ) ;
V_57 = V_202 -> V_204 -> V_81 ;
V_345 = 0x2 ;
if ( V_2 -> V_347 && ( V_251 -> V_348 & V_349 ) )
F_21 ( V_2 ,
V_341 ,
0 ,
V_350 ,
V_251 -> V_348 & ~ V_349 & 0xff ) ;
F_21 ( V_2 , V_341 , 0 ,
V_342 , ( V_180 << 4 ) | 0x0 ) ;
F_21 ( V_2 , V_341 , 0 ,
V_344 , V_181 ) ;
if ( V_2 -> V_347 && ( V_251 -> V_348 & V_349 ) ) {
F_21 ( V_2 ,
V_341 ,
0 ,
V_350 ,
V_251 -> V_348 & 0xff ) ;
F_21 ( V_2 ,
V_341 ,
0 ,
V_351 , V_345 ) ;
}
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
if ( V_57 == 2 )
V_346 = 0 ;
else
V_346 = V_76 * 2 ;
if ( V_2 -> V_347 &&
( V_251 -> V_348 & V_349 ) )
F_21 ( V_2 ,
V_343 [ V_76 ] ,
0 ,
V_350 ,
V_251 -> V_348 & ~ V_349 & 0xff ) ;
F_21 ( V_2 ,
V_343 [ V_76 ] ,
0 ,
V_342 ,
( V_180 << 4 ) | V_346 ) ;
F_21 ( V_2 ,
V_343 [ V_76 ] ,
0 ,
V_344 ,
V_181 ) ;
if ( V_2 -> V_347 &&
( V_251 -> V_348 & V_349 ) ) {
F_21 ( V_2 ,
V_343 [ V_76 ] ,
0 ,
V_350 ,
V_251 -> V_348 & 0xff ) ;
F_21 ( V_2 ,
V_343 [ V_76 ] ,
0 ,
V_351 , V_345 ) ;
}
}
F_186 ( V_2 , V_57 ) ;
F_11 ( & V_2 -> V_252 ) ;
return 0 ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 = F_185 ( V_2 , V_341 ,
V_352 ) ;
if ( V_38 < 0 )
return V_38 ;
V_2 -> V_303 . V_304 = F_176 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_322 . V_207 = V_353 ;
V_5 -> V_322 . V_209 = V_354 ;
V_5 -> V_322 . V_208 = V_355 ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 = F_168 ( V_2 ) ;
if ( ! V_38 ) {
struct V_280 * V_89 = F_5 ( V_5 , 0 ) ;
V_89 -> V_286 = true ;
}
return V_38 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_280 * V_89 ;
struct V_256 * V_144 ;
int V_38 ;
V_38 = F_171 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_89 = F_5 ( V_5 , 0 ) ;
V_38 = F_142 ( V_89 -> V_295 ,
V_287 ,
V_356 , 8 , 0 , & V_144 ) ;
if ( V_38 < 0 )
return V_38 ;
switch ( V_2 -> V_328 -> V_41 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_144 -> V_357 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_144 -> V_357 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
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
V_5 -> V_331 . V_333 = 8 ;
V_5 -> V_322 = V_358 ;
V_2 -> V_303 . V_304 = F_178 ;
V_2 -> V_303 . V_359 = F_190 ;
V_2 -> V_303 . V_360 = F_191 ;
F_186 ( V_2 , 8 ) ;
return 0 ;
}
static int F_193 ( struct V_78 * V_261 ,
int V_81 )
{
if ( V_261 -> V_85 == 0x00 && V_81 == 2 )
return V_361 ;
return F_127 ( V_261 , V_81 ) ;
}
static int F_194 ( int V_84 , int V_57 , unsigned char * V_105 )
{
if ( V_84 == 0x00 && ( V_105 [ 0 ] != V_362 || V_105 [ 1 ] != V_363 ) )
return - V_8 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 ;
V_38 = F_165 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_53 = true ;
V_5 -> V_92 . V_269 =
F_193 ;
V_5 -> V_92 . V_279 = F_194 ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , T_1 V_148 ,
unsigned char * V_86 , int * V_29 )
{
return F_197 ( V_2 , V_148 , V_86 , V_29 ,
F_198 ( V_2 ) ) ;
}
static void F_199 ( struct V_1 * V_2 , T_1 V_3 , int V_84 ,
int V_132 , int V_133 )
{
F_21 ( V_2 , V_3 , 0 , V_364 , V_84 ) ;
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
struct V_78 * V_261 ;
int V_76 , V_77 ;
V_261 = & V_80 [ F_37 ( V_84 ) ] ;
for ( V_76 = 0 ; V_76 < V_57 ; ++ V_76 ) {
int V_108 = F_46 ( V_105 [ V_76 ] ) ;
bool V_365 = false ;
bool V_366 = false ;
if ( ! V_108 )
continue;
for ( V_77 = 0 + V_76 % 2 ; V_77 < 8 ; V_77 += 2 ) {
int V_367 = 7 - F_200 ( V_77 ) ;
if ( V_261 -> V_83 [ V_367 ] == V_108 ) {
V_365 = true ;
if ( V_76 % 2 == 0 && V_76 + 1 < V_57 ) {
int V_368 = 7 - F_200 ( V_77 + 1 ) ;
int V_369 = F_46 ( V_105 [ V_76 + 1 ] ) ;
int V_370 = V_261 -> V_83 [ V_368 ] ;
if ( V_369 == V_370 )
V_366 = true ;
else
return - V_8 ;
}
break;
}
}
if ( ! V_365 )
return - V_8 ;
if ( V_366 )
V_76 ++ ;
}
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , T_1 V_3 ,
int V_99 , int V_371 )
{
int V_372 ;
int V_373 = 0 ;
if ( V_99 > 7 )
return - V_8 ;
if ( ! F_203 ( V_2 ) ) {
V_99 = F_200 ( V_99 ) ;
if ( V_99 % 2 != 0 && V_371 == 0xf )
return 0 ;
V_99 -= V_99 % 2 ;
if ( V_371 != 0xf )
V_371 -= V_371 % 2 ;
}
V_372 = V_374 + V_99 / 2 + ( V_99 % 2 ) * 0x00e ;
if ( V_371 != 0xf )
V_373 = ( V_371 << 4 ) | V_375 ;
return F_21 ( V_2 , V_3 , 0 , V_372 , V_373 ) ;
}
static int F_204 ( struct V_1 * V_2 , T_1 V_3 ,
int V_115 )
{
bool V_376 = false ;
int V_377 = V_115 ;
int V_372 ;
int V_373 ;
if ( V_115 > 7 )
return - V_8 ;
if ( ! F_203 ( V_2 ) ) {
V_377 = F_200 ( V_115 ) ;
if ( V_377 % 2 != 0 ) {
V_377 -= 1 ;
V_376 = true ;
}
}
V_372 = V_378 + V_377 / 2 + ( V_377 % 2 ) * 0x00e ;
V_373 = F_19 ( V_2 , V_3 , 0 , V_372 , 0 ) ;
if ( ! ( V_373 & V_375 ) )
return 0xf ;
return ( ( V_373 & 0xf0 ) >> 4 ) + ! ! V_376 ;
}
static int F_205 ( struct V_78 * V_261 ,
int V_81 )
{
int V_69 ;
int V_379 = 0 ;
if ( ( V_81 % 2 ) != 0 )
return - 1 ;
for ( V_69 = 0 ; V_69 < 7 ; V_69 += 2 ) {
if ( V_261 -> V_83 [ V_69 ] || V_261 -> V_83 [ V_69 + 1 ] )
V_379 ++ ;
}
if ( V_379 * 2 != V_81 )
return - 1 ;
return V_380 ;
}
static void F_206 ( struct V_78 * V_261 ,
unsigned int * V_144 , int V_81 )
{
int V_27 = 0 ;
int V_69 ;
for ( V_69 = 7 ; V_69 >= 0 ; V_69 -- ) {
int V_338 = 7 - F_200 ( 7 - V_69 ) ;
int V_109 = V_261 -> V_83 [ V_338 ] ;
if ( ! V_109 ) {
if ( V_261 -> V_83 [ V_338 + ( V_338 % 2 ? - 1 : 1 ) ] )
V_144 [ V_27 ++ ] = V_381 ;
continue;
}
V_144 [ V_27 ++ ] = F_48 ( V_109 ) ;
}
F_45 ( V_27 != V_81 ) ;
}
static int F_207 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_172 )
{
int V_382 , V_383 ;
V_382 = F_19 ( V_2 , V_3 , 0 , V_384 , 0 ) ;
if ( V_382 >= 0 && ( V_382 & V_385 ) ) {
if ( V_172 )
V_383 = V_382 | V_386 ;
else
V_383 = V_382 & ~ V_386 ;
F_43 ( V_2 ,
L_32 ,
V_3 ,
V_382 == V_383 ? L_19 : L_20 ,
V_383 ) ;
if ( V_382 != V_383 )
F_21 ( V_2 , V_3 , 0 ,
V_387 ,
V_383 ) ;
} else if ( V_172 )
return - V_8 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_3 , T_3 V_180 , int V_181 )
{
if ( F_198 ( V_2 ) ) {
int V_388 = 180 ;
if ( V_181 & V_389 )
V_388 = 0 ;
F_21 ( V_2 , V_12 , 0 , V_390 , V_388 ) ;
}
return F_81 ( V_2 , V_12 , V_3 , V_180 , V_181 ) ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 , V_38 ;
V_38 = F_146 ( V_2 ) ;
if ( V_38 )
return V_38 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ ) {
struct V_19 * V_20 = F_2 ( V_5 , V_6 ) ;
F_21 ( V_2 , V_20 -> V_3 , 0 , V_391 , 0 ) ;
if ( F_203 ( V_2 ) )
F_21 ( V_2 , V_20 -> V_3 , 0 ,
V_392 ,
V_393 ) ;
}
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_185 * V_186 ;
int V_38 , V_13 ;
V_38 = F_165 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_303 . V_304 = F_209 ;
V_5 = V_2 -> V_5 ;
V_5 -> V_92 . V_225 = F_196 ;
V_5 -> V_92 . V_93 = F_204 ;
V_5 -> V_92 . V_101 = F_202 ;
V_5 -> V_92 . V_145 = F_199 ;
V_5 -> V_92 . V_182 = F_207 ;
V_5 -> V_92 . V_255 = F_208 ;
if ( ! F_203 ( V_2 ) ) {
V_5 -> V_92 . V_269 =
F_205 ;
V_5 -> V_92 . V_271 = F_206 ;
V_5 -> V_92 . V_279 = F_201 ;
}
for ( V_13 = 0 ; V_13 < V_5 -> V_14 ; V_13 ++ ) {
V_186 = F_7 ( V_5 , V_13 ) ;
V_186 -> V_206 = V_259 ( V_186 -> V_206 , 8u ) ;
V_186 -> V_207 |= V_353 ;
V_186 -> V_208 |= V_355 ;
V_186 -> V_209 = V_259 ( V_186 -> V_209 , 24u ) ;
}
V_5 -> V_206 = V_259 ( V_5 -> V_206 , 8u ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 )
{
return F_185 ( V_2 , V_394 , V_395 ) ;
}
int F_212 ( struct V_1 * V_2 )
{
return F_165 ( V_2 ) ;
}
static int T_5 F_213 ( void )
{
return F_214 ( & V_396 ) ;
}
static void T_6 F_215 ( void )
{
F_216 ( & V_396 ) ;
}
