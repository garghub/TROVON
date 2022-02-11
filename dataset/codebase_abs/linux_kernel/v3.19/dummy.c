static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 , V_5 , 256 , V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static void F_4 ( struct V_7 * V_8 )
{
V_8 -> V_9 . V_10 = V_11 +
( V_8 -> V_12 + V_8 -> V_13 - 1 ) / V_8 -> V_13 ;
F_5 ( & V_8 -> V_9 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
unsigned long V_14 ;
V_14 = V_11 - V_8 -> V_15 ;
if ( ! V_14 )
return;
V_8 -> V_15 += V_14 ;
V_14 *= V_8 -> V_13 ;
V_8 -> V_16 += V_14 ;
while ( V_8 -> V_16 >= V_8 -> V_17 )
V_8 -> V_16 -= V_8 -> V_17 ;
while ( V_8 -> V_12 <= V_14 ) {
V_8 -> V_18 ++ ;
V_8 -> V_12 += V_8 -> V_19 ;
}
V_8 -> V_12 -= V_14 ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_2 -> V_22 ;
F_8 ( & V_8 -> V_23 ) ;
V_8 -> V_15 = V_11 ;
F_4 ( V_8 ) ;
F_9 ( & V_8 -> V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_2 -> V_22 ;
F_8 ( & V_8 -> V_23 ) ;
F_11 ( & V_8 -> V_9 ) ;
F_9 ( & V_8 -> V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_22 ;
V_8 -> V_16 = 0 ;
V_8 -> V_13 = V_2 -> V_13 ;
V_8 -> V_17 = V_2 -> V_24 * V_25 ;
V_8 -> V_19 = V_2 -> V_26 * V_25 ;
V_8 -> V_12 = V_8 -> V_19 ;
V_8 -> V_18 = 0 ;
return 0 ;
}
static void F_13 ( unsigned long V_27 )
{
struct V_7 * V_8 = (struct V_7 * ) V_27 ;
unsigned long V_28 ;
int V_18 = 0 ;
F_14 ( & V_8 -> V_23 , V_28 ) ;
F_6 ( V_8 ) ;
F_4 ( V_8 ) ;
V_18 = V_8 -> V_18 ;
V_8 -> V_18 = 0 ;
F_15 ( & V_8 -> V_23 , V_28 ) ;
if ( V_18 )
F_16 ( V_8 -> V_21 ) ;
}
static T_1
F_17 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_2 -> V_22 ;
T_1 V_29 ;
F_8 ( & V_8 -> V_23 ) ;
F_6 ( V_8 ) ;
V_29 = V_8 -> V_16 / V_25 ;
F_9 ( & V_8 -> V_23 ) ;
return V_29 ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_7 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_30 ) ;
if ( ! V_8 )
return - V_31 ;
V_21 -> V_2 -> V_22 = V_8 ;
F_20 ( & V_8 -> V_9 ) ;
V_8 -> V_9 . V_27 = ( unsigned long ) V_8 ;
V_8 -> V_9 . V_32 = F_13 ;
F_21 ( & V_8 -> V_23 ) ;
V_8 -> V_21 = V_21 ;
return 0 ;
}
static void F_22 ( struct V_20 * V_21 )
{
F_23 ( V_21 -> V_2 -> V_22 ) ;
}
static void F_24 ( unsigned long V_33 )
{
struct V_34 * V_8 = (struct V_34 * ) V_33 ;
if ( F_25 ( & V_8 -> V_35 ) )
F_16 ( V_8 -> V_21 ) ;
}
static enum V_36 F_26 ( struct V_37 * V_9 )
{
struct V_34 * V_8 ;
V_8 = F_27 ( V_9 , struct V_34 , V_9 ) ;
if ( ! F_25 ( & V_8 -> V_35 ) )
return V_38 ;
F_28 ( & V_8 -> V_39 ) ;
F_29 ( V_9 , V_8 -> V_40 ) ;
return V_41 ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_34 * V_8 = V_21 -> V_2 -> V_22 ;
V_8 -> V_15 = F_31 ( & V_8 -> V_9 ) ;
F_32 ( & V_8 -> V_9 , V_8 -> V_40 , V_42 ) ;
F_33 ( & V_8 -> V_35 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_20 * V_21 )
{
struct V_34 * V_8 = V_21 -> V_2 -> V_22 ;
F_33 ( & V_8 -> V_35 , 0 ) ;
F_35 ( & V_8 -> V_9 ) ;
return 0 ;
}
static inline void F_36 ( struct V_34 * V_8 )
{
F_37 ( & V_8 -> V_39 ) ;
}
static T_1
F_38 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_34 * V_8 = V_2 -> V_22 ;
T_2 V_14 ;
T_3 V_29 ;
V_14 = F_39 ( F_31 ( & V_8 -> V_9 ) ,
V_8 -> V_15 ) ;
V_14 = F_40 ( V_14 * V_2 -> V_13 + 999999 , 1000000 ) ;
F_41 ( V_14 , V_2 -> V_24 , & V_29 ) ;
return V_29 ;
}
static int F_42 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_34 * V_8 = V_2 -> V_22 ;
unsigned int V_43 , V_13 ;
long V_44 ;
unsigned long V_45 ;
F_36 ( V_8 ) ;
V_43 = V_2 -> V_26 ;
V_13 = V_2 -> V_13 ;
V_44 = V_43 / V_13 ;
V_43 %= V_13 ;
V_45 = F_40 ( ( T_2 ) V_43 * 1000000000UL + V_13 - 1 , V_13 ) ;
V_8 -> V_40 = F_43 ( V_44 , V_45 ) ;
return 0 ;
}
static int F_44 ( struct V_20 * V_21 )
{
struct V_34 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_30 ) ;
if ( ! V_8 )
return - V_31 ;
V_21 -> V_2 -> V_22 = V_8 ;
F_45 ( & V_8 -> V_9 , V_46 , V_42 ) ;
V_8 -> V_9 . V_32 = F_26 ;
V_8 -> V_21 = V_21 ;
F_33 ( & V_8 -> V_35 , 0 ) ;
F_46 ( & V_8 -> V_39 , F_24 ,
( unsigned long ) V_8 ) ;
return 0 ;
}
static void F_47 ( struct V_20 * V_21 )
{
struct V_34 * V_8 = V_21 -> V_2 -> V_22 ;
F_36 ( V_8 ) ;
F_23 ( V_8 ) ;
}
static int F_48 ( struct V_20 * V_21 , int V_47 )
{
struct V_48 * V_49 = F_49 ( V_21 ) ;
switch ( V_47 ) {
case V_50 :
case V_51 :
return V_49 -> V_52 -> V_53 ( V_21 ) ;
case V_54 :
case V_55 :
return V_49 -> V_52 -> V_56 ( V_21 ) ;
}
return - V_57 ;
}
static int F_50 ( struct V_20 * V_21 )
{
struct V_48 * V_49 = F_49 ( V_21 ) ;
return V_49 -> V_52 -> V_58 ( V_21 ) ;
}
static T_1 F_51 ( struct V_20 * V_21 )
{
struct V_48 * V_49 = F_49 ( V_21 ) ;
return V_49 -> V_52 -> V_59 ( V_21 ) ;
}
static int F_52 ( struct V_20 * V_21 ,
struct V_60 * V_61 )
{
if ( V_62 ) {
V_21 -> V_2 -> V_63 = F_53 ( V_61 ) ;
return 0 ;
}
return F_54 ( V_21 ,
F_53 ( V_61 ) ) ;
}
static int F_55 ( struct V_20 * V_21 )
{
if ( V_62 )
return 0 ;
return F_56 ( V_21 ) ;
}
static int F_57 ( struct V_20 * V_21 )
{
struct V_48 * V_49 = F_49 ( V_21 ) ;
struct V_64 * V_65 = V_49 -> V_65 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_3 ;
V_49 -> V_52 = & V_66 ;
#ifdef F_58
if ( V_37 )
V_49 -> V_52 = & V_67 ;
#endif
V_3 = V_49 -> V_52 -> V_68 ( V_21 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_69 = V_49 -> V_70 ;
if ( V_21 -> V_71 -> V_72 & 1 ) {
V_2 -> V_69 . V_73 &= ~ V_74 ;
V_2 -> V_69 . V_73 |= V_75 ;
}
if ( V_21 -> V_71 -> V_72 & 2 )
V_2 -> V_69 . V_73 &= ~ ( V_76 |
V_77 ) ;
if ( V_65 == NULL )
return 0 ;
if ( V_21 -> V_78 == V_79 ) {
if ( V_65 -> V_80 )
V_3 = V_65 -> V_80 ( V_21 -> V_2 ) ;
} else {
if ( V_65 -> V_81 )
V_3 = V_65 -> V_81 ( V_21 -> V_2 ) ;
}
if ( V_3 < 0 ) {
V_49 -> V_52 -> free ( V_21 ) ;
return V_3 ;
}
return 0 ;
}
static int F_59 ( struct V_20 * V_21 )
{
struct V_48 * V_49 = F_49 ( V_21 ) ;
V_49 -> V_52 -> free ( V_21 ) ;
return 0 ;
}
static void F_60 ( void )
{
if ( V_62 ) {
int V_82 ;
for ( V_82 = 0 ; V_82 < 2 ; V_82 ++ )
if ( V_83 [ V_82 ] ) {
F_61 ( ( unsigned long ) V_83 [ V_82 ] ) ;
V_83 [ V_82 ] = NULL ;
}
}
}
static int F_62 ( void )
{
int V_82 ;
if ( ! V_62 )
return 0 ;
for ( V_82 = 0 ; V_82 < 2 ; V_82 ++ ) {
V_83 [ V_82 ] = ( void * ) F_63 ( V_30 ) ;
if ( ! V_83 [ V_82 ] ) {
F_60 () ;
return - V_31 ;
}
}
return 0 ;
}
static int F_64 ( struct V_20 * V_21 ,
int V_84 , T_1 V_29 ,
void T_4 * V_85 , T_1 V_86 )
{
return 0 ;
}
static int F_65 ( struct V_20 * V_21 ,
int V_84 , T_1 V_29 ,
T_1 V_86 )
{
return 0 ;
}
static struct V_87 * F_66 ( struct V_20 * V_21 ,
unsigned long V_88 )
{
return F_67 ( V_83 [ V_21 -> V_78 ] ) ;
}
static int F_68 ( struct V_48 * V_49 , int V_72 ,
int V_89 )
{
struct V_90 * V_71 ;
struct V_91 * V_92 ;
int V_3 ;
V_3 = F_69 ( V_49 -> V_93 , L_1 , V_72 ,
V_89 , V_89 , & V_71 ) ;
if ( V_3 < 0 )
return V_3 ;
V_49 -> V_71 = V_71 ;
if ( V_62 )
V_92 = & V_94 ;
else
V_92 = & V_95 ;
F_70 ( V_71 , V_79 , V_92 ) ;
F_70 ( V_71 , V_96 , V_92 ) ;
V_71 -> V_22 = V_49 ;
V_71 -> V_97 = 0 ;
strcpy ( V_71 -> V_98 , L_1 ) ;
if ( ! V_62 ) {
F_71 ( V_71 ,
V_99 ,
F_72 ( V_30 ) ,
0 , 64 * 1024 ) ;
}
return 0 ;
}
static int F_73 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
V_103 -> type = V_104 ;
V_103 -> V_86 = 2 ;
V_103 -> V_105 . integer . V_106 = - 50 ;
V_103 -> V_105 . integer . V_107 = 100 ;
return 0 ;
}
static int F_74 ( struct V_100 * V_101 ,
struct V_108 * V_109 )
{
struct V_48 * V_49 = F_75 ( V_101 ) ;
int V_110 = V_101 -> V_111 ;
F_76 ( & V_49 -> V_112 ) ;
V_109 -> V_105 . integer . V_105 [ 0 ] = V_49 -> V_113 [ V_110 ] [ 0 ] ;
V_109 -> V_105 . integer . V_105 [ 1 ] = V_49 -> V_113 [ V_110 ] [ 1 ] ;
F_77 ( & V_49 -> V_112 ) ;
return 0 ;
}
static int F_78 ( struct V_100 * V_101 ,
struct V_108 * V_109 )
{
struct V_48 * V_49 = F_75 ( V_101 ) ;
int V_114 , V_110 = V_101 -> V_111 ;
int V_115 , V_116 ;
V_115 = V_109 -> V_105 . integer . V_105 [ 0 ] ;
if ( V_115 < - 50 )
V_115 = - 50 ;
if ( V_115 > 100 )
V_115 = 100 ;
V_116 = V_109 -> V_105 . integer . V_105 [ 1 ] ;
if ( V_116 < - 50 )
V_116 = - 50 ;
if ( V_116 > 100 )
V_116 = 100 ;
F_76 ( & V_49 -> V_112 ) ;
V_114 = V_49 -> V_113 [ V_110 ] [ 0 ] != V_115 ||
V_49 -> V_113 [ V_110 ] [ 1 ] != V_116 ;
V_49 -> V_113 [ V_110 ] [ 0 ] = V_115 ;
V_49 -> V_113 [ V_110 ] [ 1 ] = V_116 ;
F_77 ( & V_49 -> V_112 ) ;
return V_114 ;
}
static int F_79 ( struct V_100 * V_101 ,
struct V_108 * V_109 )
{
struct V_48 * V_49 = F_75 ( V_101 ) ;
int V_110 = V_101 -> V_111 ;
F_76 ( & V_49 -> V_112 ) ;
V_109 -> V_105 . integer . V_105 [ 0 ] = V_49 -> V_117 [ V_110 ] [ 0 ] ;
V_109 -> V_105 . integer . V_105 [ 1 ] = V_49 -> V_117 [ V_110 ] [ 1 ] ;
F_77 ( & V_49 -> V_112 ) ;
return 0 ;
}
static int F_80 ( struct V_100 * V_101 , struct V_108 * V_109 )
{
struct V_48 * V_49 = F_75 ( V_101 ) ;
int V_114 , V_110 = V_101 -> V_111 ;
int V_115 , V_116 ;
V_115 = V_109 -> V_105 . integer . V_105 [ 0 ] & 1 ;
V_116 = V_109 -> V_105 . integer . V_105 [ 1 ] & 1 ;
F_76 ( & V_49 -> V_112 ) ;
V_114 = V_49 -> V_117 [ V_110 ] [ 0 ] != V_115 &&
V_49 -> V_117 [ V_110 ] [ 1 ] != V_116 ;
V_49 -> V_117 [ V_110 ] [ 0 ] = V_115 ;
V_49 -> V_117 [ V_110 ] [ 1 ] = V_116 ;
F_77 ( & V_49 -> V_112 ) ;
return V_114 ;
}
static int F_81 ( struct V_100 * V_101 ,
struct V_102 * V_73 )
{
const char * const V_118 [] = { L_2 , L_3 } ;
return F_82 ( V_73 , 1 , 2 , V_118 ) ;
}
static int F_83 ( struct V_100 * V_101 ,
struct V_108 * V_105 )
{
struct V_48 * V_49 = F_75 ( V_101 ) ;
V_105 -> V_105 . V_119 . V_120 [ 0 ] = V_49 -> V_121 ;
return 0 ;
}
static int F_84 ( struct V_100 * V_101 ,
struct V_108 * V_105 )
{
struct V_48 * V_49 = F_75 ( V_101 ) ;
int V_122 ;
if ( V_105 -> V_105 . V_119 . V_120 [ 0 ] > 1 )
return - V_57 ;
V_122 = V_105 -> V_105 . V_119 . V_120 [ 0 ] != V_49 -> V_121 ;
if ( V_122 ) {
V_49 -> V_121 = V_105 -> V_105 . V_119 . V_120 [ 0 ] ;
if ( V_49 -> V_121 ) {
V_49 -> V_123 -> V_124 [ 0 ] . V_125 &=
~ V_126 ;
V_49 -> V_127 -> V_124 [ 0 ] . V_125 &=
~ V_126 ;
} else {
V_49 -> V_123 -> V_124 [ 0 ] . V_125 |=
V_126 ;
V_49 -> V_127 -> V_124 [ 0 ] . V_125 |=
V_126 ;
}
F_85 ( V_49 -> V_93 , V_128 ,
& V_49 -> V_123 -> V_129 ) ;
F_85 ( V_49 -> V_93 , V_128 ,
& V_49 -> V_127 -> V_129 ) ;
}
return V_122 ;
}
static int F_86 ( struct V_48 * V_49 )
{
struct V_130 * V_93 = V_49 -> V_93 ;
struct V_100 * V_101 ;
unsigned int V_131 ;
int V_3 ;
F_21 ( & V_49 -> V_112 ) ;
strcpy ( V_93 -> V_132 , L_4 ) ;
V_49 -> V_121 = 1 ;
for ( V_131 = 0 ; V_131 < F_87 ( V_133 ) ; V_131 ++ ) {
V_101 = F_88 ( & V_133 [ V_131 ] , V_49 ) ;
V_3 = F_89 ( V_93 , V_101 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! strcmp ( V_101 -> V_129 . V_98 , L_5 ) )
V_49 -> V_123 = V_101 ;
else if ( ! strcmp ( V_101 -> V_129 . V_98 , L_6 ) )
V_49 -> V_127 = V_101 ;
}
return 0 ;
}
static void F_90 ( struct V_48 * V_49 ,
struct V_134 * V_135 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_136 ; V_82 ++ ) {
if ( V_49 -> V_70 . V_137 & ( 1ULL << V_82 ) )
F_91 ( V_135 , L_7 , F_92 ( V_82 ) ) ;
}
}
static void F_93 ( struct V_48 * V_49 ,
struct V_134 * V_135 )
{
static int V_138 [] = {
5512 , 8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 ,
64000 , 88200 , 96000 , 176400 , 192000 ,
} ;
int V_82 ;
if ( V_49 -> V_70 . V_138 & V_139 )
F_91 ( V_135 , L_8 ) ;
if ( V_49 -> V_70 . V_138 & V_140 )
F_91 ( V_135 , L_9 ) ;
for ( V_82 = 0 ; V_82 < F_87 ( V_138 ) ; V_82 ++ )
if ( V_49 -> V_70 . V_138 & ( 1 << V_82 ) )
F_91 ( V_135 , L_10 , V_138 [ V_82 ] ) ;
}
static void F_94 ( struct V_141 * V_142 ,
struct V_134 * V_135 )
{
struct V_48 * V_49 = V_142 -> V_22 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < F_87 ( V_143 ) ; V_82 ++ ) {
F_91 ( V_135 , L_11 , V_143 [ V_82 ] . V_98 ) ;
if ( V_143 [ V_82 ] . V_144 == sizeof( int ) )
F_91 ( V_135 , V_143 [ V_82 ] . V_145 ,
* F_95 ( V_49 , V_143 [ V_82 ] . V_88 ) ) ;
else
F_91 ( V_135 , V_143 [ V_82 ] . V_145 ,
* F_96 ( V_49 , V_143 [ V_82 ] . V_88 ) ) ;
if ( ! strcmp ( V_143 [ V_82 ] . V_98 , L_12 ) )
F_90 ( V_49 , V_135 ) ;
else if ( ! strcmp ( V_143 [ V_82 ] . V_98 , L_13 ) )
F_93 ( V_49 , V_135 ) ;
F_91 ( V_135 , L_14 ) ;
}
}
static void F_97 ( struct V_141 * V_142 ,
struct V_134 * V_135 )
{
struct V_48 * V_49 = V_142 -> V_22 ;
char line [ 64 ] ;
while ( ! F_98 ( V_135 , line , sizeof( line ) ) ) {
char V_120 [ 20 ] ;
const char * V_146 ;
unsigned long long V_147 ;
int V_82 ;
V_146 = F_99 ( V_120 , line , sizeof( V_120 ) ) ;
for ( V_82 = 0 ; V_82 < F_87 ( V_143 ) ; V_82 ++ ) {
if ( ! strcmp ( V_120 , V_143 [ V_82 ] . V_98 ) )
break;
}
if ( V_82 >= F_87 ( V_143 ) )
continue;
F_99 ( V_120 , V_146 , sizeof( V_120 ) ) ;
if ( F_100 ( V_120 , 0 , & V_147 ) )
continue;
if ( V_143 [ V_82 ] . V_144 == sizeof( int ) )
* F_95 ( V_49 , V_143 [ V_82 ] . V_88 ) = V_147 ;
else
* F_96 ( V_49 , V_143 [ V_82 ] . V_88 ) = V_147 ;
}
}
static void F_101 ( struct V_48 * V_148 )
{
struct V_141 * V_142 ;
if ( ! F_102 ( V_148 -> V_93 , L_15 , & V_142 ) ) {
F_103 ( V_142 , V_148 , F_94 ) ;
V_142 -> V_149 . V_150 . V_151 = F_97 ;
V_142 -> V_152 |= V_153 ;
V_142 -> V_22 = V_148 ;
}
}
static int F_104 ( struct V_154 * V_155 )
{
struct V_130 * V_93 ;
struct V_48 * V_49 ;
struct V_64 * V_156 = NULL , * * V_157 ;
int V_131 , V_3 ;
int V_158 = V_155 -> V_129 ;
V_3 = F_105 ( & V_155 -> V_158 , V_159 [ V_158 ] , V_129 [ V_158 ] , V_160 ,
sizeof( struct V_48 ) , & V_93 ) ;
if ( V_3 < 0 )
return V_3 ;
V_49 = V_93 -> V_22 ;
V_49 -> V_93 = V_93 ;
for ( V_157 = V_161 ; * V_157 && V_65 [ V_158 ] ; V_157 ++ ) {
if ( strcmp ( V_65 [ V_158 ] , ( * V_157 ) -> V_98 ) == 0 ) {
F_106 ( V_162
L_16 ,
( * V_157 ) -> V_98 , V_93 -> V_163 ) ;
V_156 = V_49 -> V_65 = * V_157 ;
break;
}
}
for ( V_131 = 0 ; V_131 < V_164 && V_131 < V_165 [ V_158 ] ; V_131 ++ ) {
if ( V_166 [ V_158 ] < 1 )
V_166 [ V_158 ] = 1 ;
if ( V_166 [ V_158 ] > V_167 )
V_166 [ V_158 ] = V_167 ;
V_3 = F_68 ( V_49 , V_131 , V_166 [ V_158 ] ) ;
if ( V_3 < 0 )
goto V_168;
}
V_49 -> V_70 = V_169 ;
if ( V_156 ) {
if ( V_156 -> V_137 )
V_49 -> V_70 . V_137 = V_156 -> V_137 ;
if ( V_156 -> V_170 )
V_49 -> V_70 . V_170 = V_156 -> V_170 ;
if ( V_156 -> V_171 )
V_49 -> V_70 . V_171 = V_156 -> V_171 ;
if ( V_156 -> V_172 )
V_49 -> V_70 . V_172 = V_156 -> V_172 ;
if ( V_156 -> V_173 )
V_49 -> V_70 . V_173 = V_156 -> V_173 ;
if ( V_156 -> V_174 )
V_49 -> V_70 . V_174 = V_156 -> V_174 ;
if ( V_156 -> V_138 )
V_49 -> V_70 . V_138 = V_156 -> V_138 ;
if ( V_156 -> V_175 )
V_49 -> V_70 . V_175 = V_156 -> V_175 ;
if ( V_156 -> V_176 )
V_49 -> V_70 . V_176 = V_156 -> V_176 ;
if ( V_156 -> V_177 )
V_49 -> V_70 . V_177 = V_156 -> V_177 ;
if ( V_156 -> V_178 )
V_49 -> V_70 . V_178 = V_156 -> V_178 ;
}
V_3 = F_86 ( V_49 ) ;
if ( V_3 < 0 )
goto V_168;
strcpy ( V_93 -> V_179 , L_17 ) ;
strcpy ( V_93 -> V_180 , L_17 ) ;
sprintf ( V_93 -> V_181 , L_18 , V_158 + 1 ) ;
F_101 ( V_49 ) ;
V_3 = F_107 ( V_93 ) ;
if ( V_3 == 0 ) {
F_108 ( V_155 , V_93 ) ;
return 0 ;
}
V_168:
F_109 ( V_93 ) ;
return V_3 ;
}
static int F_110 ( struct V_154 * V_155 )
{
F_109 ( F_111 ( V_155 ) ) ;
return 0 ;
}
static int F_112 ( struct V_72 * V_182 )
{
struct V_130 * V_93 = F_113 ( V_182 ) ;
struct V_48 * V_49 = V_93 -> V_22 ;
F_114 ( V_93 , V_183 ) ;
F_115 ( V_49 -> V_71 ) ;
return 0 ;
}
static int F_116 ( struct V_72 * V_182 )
{
struct V_130 * V_93 = F_113 ( V_182 ) ;
F_114 ( V_93 , V_184 ) ;
return 0 ;
}
static void F_117 ( void )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < F_87 ( V_185 ) ; ++ V_82 )
F_118 ( V_185 [ V_82 ] ) ;
F_119 ( & V_186 ) ;
F_60 () ;
}
static int T_5 F_120 ( void )
{
int V_82 , V_187 , V_3 ;
V_3 = F_121 ( & V_186 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_62 () ;
if ( V_3 < 0 ) {
F_119 ( & V_186 ) ;
return V_3 ;
}
V_187 = 0 ;
for ( V_82 = 0 ; V_82 < V_188 ; V_82 ++ ) {
struct V_154 * V_72 ;
if ( ! V_189 [ V_82 ] )
continue;
V_72 = F_122 ( V_190 ,
V_82 , NULL , 0 ) ;
if ( F_123 ( V_72 ) )
continue;
if ( ! F_111 ( V_72 ) ) {
F_118 ( V_72 ) ;
continue;
}
V_185 [ V_82 ] = V_72 ;
V_187 ++ ;
}
if ( ! V_187 ) {
#ifdef F_124
F_106 ( V_191 L_19 ) ;
#endif
F_117 () ;
return - V_192 ;
}
return 0 ;
}
static void T_6 F_125 ( void )
{
F_117 () ;
}
