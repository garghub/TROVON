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
F_5 ( & V_8 -> V_9 , V_10 +
( V_8 -> V_11 + V_8 -> V_12 - 1 ) / V_8 -> V_12 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
unsigned long V_13 ;
V_13 = V_10 - V_8 -> V_14 ;
if ( ! V_13 )
return;
V_8 -> V_14 += V_13 ;
V_13 *= V_8 -> V_12 ;
V_8 -> V_15 += V_13 ;
while ( V_8 -> V_15 >= V_8 -> V_16 )
V_8 -> V_15 -= V_8 -> V_16 ;
while ( V_8 -> V_11 <= V_13 ) {
V_8 -> V_17 ++ ;
V_8 -> V_11 += V_8 -> V_18 ;
}
V_8 -> V_11 -= V_13 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_2 -> V_21 ;
F_8 ( & V_8 -> V_22 ) ;
V_8 -> V_14 = V_10 ;
F_4 ( V_8 ) ;
F_9 ( & V_8 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_2 -> V_21 ;
F_8 ( & V_8 -> V_22 ) ;
F_11 ( & V_8 -> V_9 ) ;
F_9 ( & V_8 -> V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_21 ;
V_8 -> V_15 = 0 ;
V_8 -> V_12 = V_2 -> V_12 ;
V_8 -> V_16 = V_2 -> V_23 * V_24 ;
V_8 -> V_18 = V_2 -> V_25 * V_24 ;
V_8 -> V_11 = V_8 -> V_18 ;
V_8 -> V_17 = 0 ;
return 0 ;
}
static void F_13 ( unsigned long V_26 )
{
struct V_7 * V_8 = (struct V_7 * ) V_26 ;
unsigned long V_27 ;
int V_17 = 0 ;
F_14 ( & V_8 -> V_22 , V_27 ) ;
F_6 ( V_8 ) ;
F_4 ( V_8 ) ;
V_17 = V_8 -> V_17 ;
V_8 -> V_17 = 0 ;
F_15 ( & V_8 -> V_22 , V_27 ) ;
if ( V_17 )
F_16 ( V_8 -> V_20 ) ;
}
static T_1
F_17 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_2 -> V_21 ;
T_1 V_28 ;
F_8 ( & V_8 -> V_22 ) ;
F_6 ( V_8 ) ;
V_28 = V_8 -> V_15 / V_24 ;
F_9 ( & V_8 -> V_22 ) ;
return V_28 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_7 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_20 -> V_2 -> V_21 = V_8 ;
F_20 ( & V_8 -> V_9 , F_13 ,
( unsigned long ) V_8 ) ;
F_21 ( & V_8 -> V_22 ) ;
V_8 -> V_20 = V_20 ;
return 0 ;
}
static void F_22 ( struct V_19 * V_20 )
{
F_23 ( V_20 -> V_2 -> V_21 ) ;
}
static void F_24 ( unsigned long V_31 )
{
struct V_32 * V_8 = (struct V_32 * ) V_31 ;
if ( F_25 ( & V_8 -> V_33 ) )
F_16 ( V_8 -> V_20 ) ;
}
static enum V_34 F_26 ( struct V_35 * V_9 )
{
struct V_32 * V_8 ;
V_8 = F_27 ( V_9 , struct V_32 , V_9 ) ;
if ( ! F_25 ( & V_8 -> V_33 ) )
return V_36 ;
F_28 ( & V_8 -> V_37 ) ;
F_29 ( V_9 , V_8 -> V_38 ) ;
return V_39 ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_32 * V_8 = V_20 -> V_2 -> V_21 ;
V_8 -> V_14 = F_31 ( & V_8 -> V_9 ) ;
F_32 ( & V_8 -> V_9 , V_8 -> V_38 , V_40 ) ;
F_33 ( & V_8 -> V_33 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_19 * V_20 )
{
struct V_32 * V_8 = V_20 -> V_2 -> V_21 ;
F_33 ( & V_8 -> V_33 , 0 ) ;
F_35 ( & V_8 -> V_9 ) ;
return 0 ;
}
static inline void F_36 ( struct V_32 * V_8 )
{
F_37 ( & V_8 -> V_37 ) ;
}
static T_1
F_38 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_32 * V_8 = V_2 -> V_21 ;
T_2 V_13 ;
T_3 V_28 ;
V_13 = F_39 ( F_31 ( & V_8 -> V_9 ) ,
V_8 -> V_14 ) ;
V_13 = F_40 ( V_13 * V_2 -> V_12 + 999999 , 1000000 ) ;
F_41 ( V_13 , V_2 -> V_23 , & V_28 ) ;
return V_28 ;
}
static int F_42 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_32 * V_8 = V_2 -> V_21 ;
unsigned int V_41 , V_12 ;
long V_42 ;
unsigned long V_43 ;
F_36 ( V_8 ) ;
V_41 = V_2 -> V_25 ;
V_12 = V_2 -> V_12 ;
V_42 = V_41 / V_12 ;
V_41 %= V_12 ;
V_43 = F_40 ( ( T_2 ) V_41 * 1000000000UL + V_12 - 1 , V_12 ) ;
V_8 -> V_38 = F_43 ( V_42 , V_43 ) ;
return 0 ;
}
static int F_44 ( struct V_19 * V_20 )
{
struct V_32 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_20 -> V_2 -> V_21 = V_8 ;
F_45 ( & V_8 -> V_9 , V_44 , V_40 ) ;
V_8 -> V_9 . V_45 = F_26 ;
V_8 -> V_20 = V_20 ;
F_33 ( & V_8 -> V_33 , 0 ) ;
F_46 ( & V_8 -> V_37 , F_24 ,
( unsigned long ) V_8 ) ;
return 0 ;
}
static void F_47 ( struct V_19 * V_20 )
{
struct V_32 * V_8 = V_20 -> V_2 -> V_21 ;
F_36 ( V_8 ) ;
F_23 ( V_8 ) ;
}
static int F_48 ( struct V_19 * V_20 , int V_46 )
{
struct V_47 * V_48 = F_49 ( V_20 ) ;
switch ( V_46 ) {
case V_49 :
case V_50 :
return V_48 -> V_51 -> V_52 ( V_20 ) ;
case V_53 :
case V_54 :
return V_48 -> V_51 -> V_55 ( V_20 ) ;
}
return - V_56 ;
}
static int F_50 ( struct V_19 * V_20 )
{
struct V_47 * V_48 = F_49 ( V_20 ) ;
return V_48 -> V_51 -> V_57 ( V_20 ) ;
}
static T_1 F_51 ( struct V_19 * V_20 )
{
struct V_47 * V_48 = F_49 ( V_20 ) ;
return V_48 -> V_51 -> V_58 ( V_20 ) ;
}
static int F_52 ( struct V_19 * V_20 ,
struct V_59 * V_60 )
{
if ( V_61 ) {
V_20 -> V_2 -> V_62 = F_53 ( V_60 ) ;
return 0 ;
}
return F_54 ( V_20 ,
F_53 ( V_60 ) ) ;
}
static int F_55 ( struct V_19 * V_20 )
{
if ( V_61 )
return 0 ;
return F_56 ( V_20 ) ;
}
static int F_57 ( struct V_19 * V_20 )
{
struct V_47 * V_48 = F_49 ( V_20 ) ;
struct V_63 * V_64 = V_48 -> V_64 ;
struct V_1 * V_2 = V_20 -> V_2 ;
int V_3 ;
V_48 -> V_51 = & V_65 ;
#ifdef F_58
if ( V_35 )
V_48 -> V_51 = & V_66 ;
#endif
V_3 = V_48 -> V_51 -> V_67 ( V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_68 = V_48 -> V_69 ;
if ( V_20 -> V_70 -> V_71 & 1 ) {
V_2 -> V_68 . V_72 &= ~ V_73 ;
V_2 -> V_68 . V_72 |= V_74 ;
}
if ( V_20 -> V_70 -> V_71 & 2 )
V_2 -> V_68 . V_72 &= ~ ( V_75 |
V_76 ) ;
if ( V_64 == NULL )
return 0 ;
if ( V_20 -> V_77 == V_78 ) {
if ( V_64 -> V_79 )
V_3 = V_64 -> V_79 ( V_20 -> V_2 ) ;
} else {
if ( V_64 -> V_80 )
V_3 = V_64 -> V_80 ( V_20 -> V_2 ) ;
}
if ( V_3 < 0 ) {
V_48 -> V_51 -> free ( V_20 ) ;
return V_3 ;
}
return 0 ;
}
static int F_59 ( struct V_19 * V_20 )
{
struct V_47 * V_48 = F_49 ( V_20 ) ;
V_48 -> V_51 -> free ( V_20 ) ;
return 0 ;
}
static void F_60 ( void )
{
if ( V_61 ) {
int V_81 ;
for ( V_81 = 0 ; V_81 < 2 ; V_81 ++ )
if ( V_82 [ V_81 ] ) {
F_61 ( ( unsigned long ) V_82 [ V_81 ] ) ;
V_82 [ V_81 ] = NULL ;
}
}
}
static int F_62 ( void )
{
int V_81 ;
if ( ! V_61 )
return 0 ;
for ( V_81 = 0 ; V_81 < 2 ; V_81 ++ ) {
V_82 [ V_81 ] = ( void * ) F_63 ( V_29 ) ;
if ( ! V_82 [ V_81 ] ) {
F_60 () ;
return - V_30 ;
}
}
return 0 ;
}
static int F_64 ( struct V_19 * V_20 ,
int V_83 , T_1 V_28 ,
void T_4 * V_84 , T_1 V_85 )
{
return 0 ;
}
static int F_65 ( struct V_19 * V_20 ,
int V_83 , T_1 V_28 ,
T_1 V_85 )
{
return 0 ;
}
static struct V_86 * F_66 ( struct V_19 * V_20 ,
unsigned long V_87 )
{
return F_67 ( V_82 [ V_20 -> V_77 ] ) ;
}
static int F_68 ( struct V_47 * V_48 , int V_71 ,
int V_88 )
{
struct V_89 * V_70 ;
struct V_90 * V_91 ;
int V_3 ;
V_3 = F_69 ( V_48 -> V_92 , L_1 , V_71 ,
V_88 , V_88 , & V_70 ) ;
if ( V_3 < 0 )
return V_3 ;
V_48 -> V_70 = V_70 ;
if ( V_61 )
V_91 = & V_93 ;
else
V_91 = & V_94 ;
F_70 ( V_70 , V_78 , V_91 ) ;
F_70 ( V_70 , V_95 , V_91 ) ;
V_70 -> V_21 = V_48 ;
V_70 -> V_96 = 0 ;
strcpy ( V_70 -> V_97 , L_1 ) ;
if ( ! V_61 ) {
F_71 ( V_70 ,
V_98 ,
F_72 ( V_29 ) ,
0 , 64 * 1024 ) ;
}
return 0 ;
}
static int F_73 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
V_102 -> type = V_103 ;
V_102 -> V_85 = 2 ;
V_102 -> V_104 . integer . V_105 = - 50 ;
V_102 -> V_104 . integer . V_106 = 100 ;
return 0 ;
}
static int F_74 ( struct V_99 * V_100 ,
struct V_107 * V_108 )
{
struct V_47 * V_48 = F_75 ( V_100 ) ;
int V_109 = V_100 -> V_110 ;
F_76 ( & V_48 -> V_111 ) ;
V_108 -> V_104 . integer . V_104 [ 0 ] = V_48 -> V_112 [ V_109 ] [ 0 ] ;
V_108 -> V_104 . integer . V_104 [ 1 ] = V_48 -> V_112 [ V_109 ] [ 1 ] ;
F_77 ( & V_48 -> V_111 ) ;
return 0 ;
}
static int F_78 ( struct V_99 * V_100 ,
struct V_107 * V_108 )
{
struct V_47 * V_48 = F_75 ( V_100 ) ;
int V_113 , V_109 = V_100 -> V_110 ;
int V_114 , V_115 ;
V_114 = V_108 -> V_104 . integer . V_104 [ 0 ] ;
if ( V_114 < - 50 )
V_114 = - 50 ;
if ( V_114 > 100 )
V_114 = 100 ;
V_115 = V_108 -> V_104 . integer . V_104 [ 1 ] ;
if ( V_115 < - 50 )
V_115 = - 50 ;
if ( V_115 > 100 )
V_115 = 100 ;
F_76 ( & V_48 -> V_111 ) ;
V_113 = V_48 -> V_112 [ V_109 ] [ 0 ] != V_114 ||
V_48 -> V_112 [ V_109 ] [ 1 ] != V_115 ;
V_48 -> V_112 [ V_109 ] [ 0 ] = V_114 ;
V_48 -> V_112 [ V_109 ] [ 1 ] = V_115 ;
F_77 ( & V_48 -> V_111 ) ;
return V_113 ;
}
static int F_79 ( struct V_99 * V_100 ,
struct V_107 * V_108 )
{
struct V_47 * V_48 = F_75 ( V_100 ) ;
int V_109 = V_100 -> V_110 ;
F_76 ( & V_48 -> V_111 ) ;
V_108 -> V_104 . integer . V_104 [ 0 ] = V_48 -> V_116 [ V_109 ] [ 0 ] ;
V_108 -> V_104 . integer . V_104 [ 1 ] = V_48 -> V_116 [ V_109 ] [ 1 ] ;
F_77 ( & V_48 -> V_111 ) ;
return 0 ;
}
static int F_80 ( struct V_99 * V_100 , struct V_107 * V_108 )
{
struct V_47 * V_48 = F_75 ( V_100 ) ;
int V_113 , V_109 = V_100 -> V_110 ;
int V_114 , V_115 ;
V_114 = V_108 -> V_104 . integer . V_104 [ 0 ] & 1 ;
V_115 = V_108 -> V_104 . integer . V_104 [ 1 ] & 1 ;
F_76 ( & V_48 -> V_111 ) ;
V_113 = V_48 -> V_116 [ V_109 ] [ 0 ] != V_114 &&
V_48 -> V_116 [ V_109 ] [ 1 ] != V_115 ;
V_48 -> V_116 [ V_109 ] [ 0 ] = V_114 ;
V_48 -> V_116 [ V_109 ] [ 1 ] = V_115 ;
F_77 ( & V_48 -> V_111 ) ;
return V_113 ;
}
static int F_81 ( struct V_99 * V_100 ,
struct V_101 * V_72 )
{
const char * const V_117 [] = { L_2 , L_3 } ;
return F_82 ( V_72 , 1 , 2 , V_117 ) ;
}
static int F_83 ( struct V_99 * V_100 ,
struct V_107 * V_104 )
{
struct V_47 * V_48 = F_75 ( V_100 ) ;
V_104 -> V_104 . V_118 . V_119 [ 0 ] = V_48 -> V_120 ;
return 0 ;
}
static int F_84 ( struct V_99 * V_100 ,
struct V_107 * V_104 )
{
struct V_47 * V_48 = F_75 ( V_100 ) ;
int V_121 ;
if ( V_104 -> V_104 . V_118 . V_119 [ 0 ] > 1 )
return - V_56 ;
V_121 = V_104 -> V_104 . V_118 . V_119 [ 0 ] != V_48 -> V_120 ;
if ( V_121 ) {
V_48 -> V_120 = V_104 -> V_104 . V_118 . V_119 [ 0 ] ;
if ( V_48 -> V_120 ) {
V_48 -> V_122 -> V_123 [ 0 ] . V_124 &=
~ V_125 ;
V_48 -> V_126 -> V_123 [ 0 ] . V_124 &=
~ V_125 ;
} else {
V_48 -> V_122 -> V_123 [ 0 ] . V_124 |=
V_125 ;
V_48 -> V_126 -> V_123 [ 0 ] . V_124 |=
V_125 ;
}
F_85 ( V_48 -> V_92 , V_127 ,
& V_48 -> V_122 -> V_128 ) ;
F_85 ( V_48 -> V_92 , V_127 ,
& V_48 -> V_126 -> V_128 ) ;
}
return V_121 ;
}
static int F_86 ( struct V_47 * V_48 )
{
struct V_129 * V_92 = V_48 -> V_92 ;
struct V_99 * V_100 ;
unsigned int V_130 ;
int V_3 ;
F_21 ( & V_48 -> V_111 ) ;
strcpy ( V_92 -> V_131 , L_4 ) ;
V_48 -> V_120 = 1 ;
for ( V_130 = 0 ; V_130 < F_87 ( V_132 ) ; V_130 ++ ) {
V_100 = F_88 ( & V_132 [ V_130 ] , V_48 ) ;
V_3 = F_89 ( V_92 , V_100 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! strcmp ( V_100 -> V_128 . V_97 , L_5 ) )
V_48 -> V_122 = V_100 ;
else if ( ! strcmp ( V_100 -> V_128 . V_97 , L_6 ) )
V_48 -> V_126 = V_100 ;
}
return 0 ;
}
static void F_90 ( struct V_47 * V_48 ,
struct V_133 * V_134 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_135 ; V_81 ++ ) {
if ( V_48 -> V_69 . V_136 & ( 1ULL << V_81 ) )
F_91 ( V_134 , L_7 , F_92 ( V_81 ) ) ;
}
}
static void F_93 ( struct V_47 * V_48 ,
struct V_133 * V_134 )
{
static int V_137 [] = {
5512 , 8000 , 11025 , 16000 , 22050 , 32000 , 44100 , 48000 ,
64000 , 88200 , 96000 , 176400 , 192000 ,
} ;
int V_81 ;
if ( V_48 -> V_69 . V_137 & V_138 )
F_91 ( V_134 , L_8 ) ;
if ( V_48 -> V_69 . V_137 & V_139 )
F_91 ( V_134 , L_9 ) ;
for ( V_81 = 0 ; V_81 < F_87 ( V_137 ) ; V_81 ++ )
if ( V_48 -> V_69 . V_137 & ( 1 << V_81 ) )
F_91 ( V_134 , L_10 , V_137 [ V_81 ] ) ;
}
static void F_94 ( struct V_140 * V_141 ,
struct V_133 * V_134 )
{
struct V_47 * V_48 = V_141 -> V_21 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < F_87 ( V_142 ) ; V_81 ++ ) {
F_91 ( V_134 , L_11 , V_142 [ V_81 ] . V_97 ) ;
if ( V_142 [ V_81 ] . V_143 == sizeof( int ) )
F_91 ( V_134 , V_142 [ V_81 ] . V_144 ,
* F_95 ( V_48 , V_142 [ V_81 ] . V_87 ) ) ;
else
F_91 ( V_134 , V_142 [ V_81 ] . V_144 ,
* F_96 ( V_48 , V_142 [ V_81 ] . V_87 ) ) ;
if ( ! strcmp ( V_142 [ V_81 ] . V_97 , L_12 ) )
F_90 ( V_48 , V_134 ) ;
else if ( ! strcmp ( V_142 [ V_81 ] . V_97 , L_13 ) )
F_93 ( V_48 , V_134 ) ;
F_91 ( V_134 , L_14 ) ;
}
}
static void F_97 ( struct V_140 * V_141 ,
struct V_133 * V_134 )
{
struct V_47 * V_48 = V_141 -> V_21 ;
char line [ 64 ] ;
while ( ! F_98 ( V_134 , line , sizeof( line ) ) ) {
char V_119 [ 20 ] ;
const char * V_145 ;
unsigned long long V_146 ;
int V_81 ;
V_145 = F_99 ( V_119 , line , sizeof( V_119 ) ) ;
for ( V_81 = 0 ; V_81 < F_87 ( V_142 ) ; V_81 ++ ) {
if ( ! strcmp ( V_119 , V_142 [ V_81 ] . V_97 ) )
break;
}
if ( V_81 >= F_87 ( V_142 ) )
continue;
F_99 ( V_119 , V_145 , sizeof( V_119 ) ) ;
if ( F_100 ( V_119 , 0 , & V_146 ) )
continue;
if ( V_142 [ V_81 ] . V_143 == sizeof( int ) )
* F_95 ( V_48 , V_142 [ V_81 ] . V_87 ) = V_146 ;
else
* F_96 ( V_48 , V_142 [ V_81 ] . V_87 ) = V_146 ;
}
}
static void F_101 ( struct V_47 * V_147 )
{
struct V_140 * V_141 ;
if ( ! F_102 ( V_147 -> V_92 , L_15 , & V_141 ) ) {
F_103 ( V_141 , V_147 , F_94 ) ;
V_141 -> V_148 . V_149 . V_150 = F_97 ;
V_141 -> V_151 |= V_152 ;
V_141 -> V_21 = V_147 ;
}
}
static int F_104 ( struct V_153 * V_154 )
{
struct V_129 * V_92 ;
struct V_47 * V_48 ;
struct V_63 * V_155 = NULL , * * V_156 ;
int V_130 , V_3 ;
int V_157 = V_154 -> V_128 ;
V_3 = F_105 ( & V_154 -> V_157 , V_158 [ V_157 ] , V_128 [ V_157 ] , V_159 ,
sizeof( struct V_47 ) , & V_92 ) ;
if ( V_3 < 0 )
return V_3 ;
V_48 = V_92 -> V_21 ;
V_48 -> V_92 = V_92 ;
for ( V_156 = V_160 ; * V_156 && V_64 [ V_157 ] ; V_156 ++ ) {
if ( strcmp ( V_64 [ V_157 ] , ( * V_156 ) -> V_97 ) == 0 ) {
F_106 ( V_161
L_16 ,
( * V_156 ) -> V_97 , V_92 -> V_162 ) ;
V_155 = V_48 -> V_64 = * V_156 ;
break;
}
}
for ( V_130 = 0 ; V_130 < V_163 && V_130 < V_164 [ V_157 ] ; V_130 ++ ) {
if ( V_165 [ V_157 ] < 1 )
V_165 [ V_157 ] = 1 ;
if ( V_165 [ V_157 ] > V_166 )
V_165 [ V_157 ] = V_166 ;
V_3 = F_68 ( V_48 , V_130 , V_165 [ V_157 ] ) ;
if ( V_3 < 0 )
goto V_167;
}
V_48 -> V_69 = V_168 ;
if ( V_155 ) {
if ( V_155 -> V_136 )
V_48 -> V_69 . V_136 = V_155 -> V_136 ;
if ( V_155 -> V_169 )
V_48 -> V_69 . V_169 = V_155 -> V_169 ;
if ( V_155 -> V_170 )
V_48 -> V_69 . V_170 = V_155 -> V_170 ;
if ( V_155 -> V_171 )
V_48 -> V_69 . V_171 = V_155 -> V_171 ;
if ( V_155 -> V_172 )
V_48 -> V_69 . V_172 = V_155 -> V_172 ;
if ( V_155 -> V_173 )
V_48 -> V_69 . V_173 = V_155 -> V_173 ;
if ( V_155 -> V_137 )
V_48 -> V_69 . V_137 = V_155 -> V_137 ;
if ( V_155 -> V_174 )
V_48 -> V_69 . V_174 = V_155 -> V_174 ;
if ( V_155 -> V_175 )
V_48 -> V_69 . V_175 = V_155 -> V_175 ;
if ( V_155 -> V_176 )
V_48 -> V_69 . V_176 = V_155 -> V_176 ;
if ( V_155 -> V_177 )
V_48 -> V_69 . V_177 = V_155 -> V_177 ;
}
V_3 = F_86 ( V_48 ) ;
if ( V_3 < 0 )
goto V_167;
strcpy ( V_92 -> V_178 , L_17 ) ;
strcpy ( V_92 -> V_179 , L_17 ) ;
sprintf ( V_92 -> V_180 , L_18 , V_157 + 1 ) ;
F_101 ( V_48 ) ;
V_3 = F_107 ( V_92 ) ;
if ( V_3 == 0 ) {
F_108 ( V_154 , V_92 ) ;
return 0 ;
}
V_167:
F_109 ( V_92 ) ;
return V_3 ;
}
static int F_110 ( struct V_153 * V_154 )
{
F_109 ( F_111 ( V_154 ) ) ;
return 0 ;
}
static int F_112 ( struct V_71 * V_181 )
{
struct V_129 * V_92 = F_113 ( V_181 ) ;
struct V_47 * V_48 = V_92 -> V_21 ;
F_114 ( V_92 , V_182 ) ;
F_115 ( V_48 -> V_70 ) ;
return 0 ;
}
static int F_116 ( struct V_71 * V_181 )
{
struct V_129 * V_92 = F_113 ( V_181 ) ;
F_114 ( V_92 , V_183 ) ;
return 0 ;
}
static void F_117 ( void )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < F_87 ( V_184 ) ; ++ V_81 )
F_118 ( V_184 [ V_81 ] ) ;
F_119 ( & V_185 ) ;
F_60 () ;
}
static int T_5 F_120 ( void )
{
int V_81 , V_186 , V_3 ;
V_3 = F_121 ( & V_185 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_62 () ;
if ( V_3 < 0 ) {
F_119 ( & V_185 ) ;
return V_3 ;
}
V_186 = 0 ;
for ( V_81 = 0 ; V_81 < V_187 ; V_81 ++ ) {
struct V_153 * V_71 ;
if ( ! V_188 [ V_81 ] )
continue;
V_71 = F_122 ( V_189 ,
V_81 , NULL , 0 ) ;
if ( F_123 ( V_71 ) )
continue;
if ( ! F_111 ( V_71 ) ) {
F_118 ( V_71 ) ;
continue;
}
V_184 [ V_81 ] = V_71 ;
V_186 ++ ;
}
if ( ! V_186 ) {
#ifdef F_124
F_106 ( V_190 L_19 ) ;
#endif
F_117 () ;
return - V_191 ;
}
return 0 ;
}
static void T_6 F_125 ( void )
{
F_117 () ;
}
