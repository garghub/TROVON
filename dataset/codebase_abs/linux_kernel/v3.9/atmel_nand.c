static int F_1 ( void )
{
return F_2 () || F_3 () ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 -> V_3 . V_4 ) )
F_6 ( V_2 -> V_3 . V_4 , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 -> V_3 . V_4 ) )
F_6 ( V_2 -> V_3 . V_4 , 1 ) ;
}
static void F_8 ( struct V_5 * V_6 , int V_7 , unsigned int V_8 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
if ( V_8 & V_11 ) {
if ( V_8 & V_12 )
F_4 ( V_2 ) ;
else
F_7 ( V_2 ) ;
}
if ( V_7 == V_13 )
return;
if ( V_8 & V_14 )
F_9 ( V_7 , V_2 -> V_15 + ( 1 << V_2 -> V_3 . V_16 ) ) ;
else
F_9 ( V_7 , V_2 -> V_15 + ( 1 << V_2 -> V_3 . V_17 ) ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
return F_11 ( V_2 -> V_3 . V_18 ) ^
! ! V_2 -> V_3 . V_19 ;
}
static void F_12 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_13 ( V_9 -> V_22 , V_20 , V_21 ) ;
}
static void F_14 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_15 ( V_9 -> V_22 , V_20 , V_21 / 2 ) ;
}
static void F_16 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_17 ( V_9 -> V_23 , V_20 , V_21 ) ;
}
static void F_18 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
F_19 ( V_9 -> V_23 , V_20 , V_21 / 2 ) ;
}
static void F_20 ( void * V_24 )
{
F_21 ( V_24 ) ;
}
static int F_22 ( struct V_5 * V_6 , void * V_20 , int V_21 ,
int V_25 )
{
struct V_26 * V_27 ;
enum V_28 V_29 ;
T_2 V_30 , V_31 , V_32 ;
struct V_33 * V_34 = NULL ;
T_3 V_35 ;
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
void * V_37 = V_20 ;
int V_38 = - V_39 ;
enum V_40 V_41 = V_25 ? V_42 : V_43 ;
if ( V_20 >= V_44 )
goto V_45;
V_27 = V_2 -> V_46 -> V_47 ;
V_29 = V_48 | V_49 | V_50 |
V_51 ;
V_32 = F_23 ( V_27 -> V_52 , V_37 , V_21 , V_41 ) ;
if ( F_24 ( V_27 -> V_52 , V_32 ) ) {
F_25 ( V_2 -> V_52 , L_1 ) ;
goto V_45;
}
if ( V_25 ) {
V_30 = V_2 -> V_53 ;
V_31 = V_32 ;
} else {
V_30 = V_32 ;
V_31 = V_2 -> V_53 ;
}
V_34 = V_27 -> V_54 ( V_2 -> V_46 , V_31 ,
V_30 , V_21 , V_29 ) ;
if ( ! V_34 ) {
F_25 ( V_2 -> V_52 , L_2 ) ;
goto V_55;
}
F_26 ( & V_2 -> V_56 ) ;
V_34 -> V_57 = F_20 ;
V_34 -> V_58 = & V_2 -> V_56 ;
V_35 = V_34 -> V_59 ( V_34 ) ;
if ( F_27 ( V_35 ) ) {
F_25 ( V_2 -> V_52 , L_3 ) ;
goto V_55;
}
F_28 ( V_2 -> V_46 ) ;
F_29 ( & V_2 -> V_56 ) ;
V_38 = 0 ;
V_55:
F_30 ( V_27 -> V_52 , V_32 , V_21 , V_41 ) ;
V_45:
if ( V_38 != 0 )
F_31 ( V_2 -> V_52 , L_4 ) ;
return V_38 ;
}
static void F_32 ( struct V_5 * V_6 , T_1 * V_20 , int V_21 )
{
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
if ( V_60 && V_21 > V_6 -> V_61 )
if ( F_22 ( V_6 , V_20 , V_21 , 1 ) == 0 )
return;
if ( V_2 -> V_3 . V_62 )
F_14 ( V_6 , V_20 , V_21 ) ;
else
F_12 ( V_6 , V_20 , V_21 ) ;
}
static void F_33 ( struct V_5 * V_6 , const T_1 * V_20 , int V_21 )
{
struct V_9 * V_36 = V_6 -> V_10 ;
struct V_1 * V_2 = V_36 -> V_10 ;
if ( V_60 && V_21 > V_6 -> V_61 )
if ( F_22 ( V_6 , ( void * ) V_20 , V_21 , 0 ) == 0 )
return;
if ( V_2 -> V_3 . V_62 )
F_18 ( V_6 , V_20 , V_21 ) ;
else
F_16 ( V_6 , V_20 , V_21 ) ;
}
static int F_34 ( int V_63 , int V_64 )
{
int V_65 = 12 + V_64 / 512 ;
return ( V_65 * V_63 + 7 ) / 8 ;
}
static void F_35 ( struct V_66 * V_67 ,
int V_61 , int V_68 )
{
int V_69 ;
V_67 -> V_70 = V_68 ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ )
V_67 -> V_71 [ V_69 ] = V_61 - V_68 + V_69 ;
V_67 -> V_72 [ 0 ] . V_73 = 2 ;
V_67 -> V_72 [ 0 ] . V_74 =
V_61 - V_68 - V_67 -> V_72 [ 0 ] . V_73 ;
}
static void T_4 * F_36 ( struct V_1 * V_2 )
{
int V_75 ;
V_75 = V_2 -> V_76 == 512 ?
V_77 : V_78 ;
return V_2 -> V_79 + V_2 -> V_80 +
V_75 * sizeof( V_81 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_82 ) ;
F_38 ( V_2 -> V_83 ) ;
F_38 ( V_2 -> V_84 ) ;
F_38 ( V_2 -> V_85 ) ;
F_38 ( V_2 -> V_86 ) ;
F_38 ( V_2 -> V_87 ) ;
F_38 ( V_2 -> V_88 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
const int V_63 = V_2 -> V_89 ;
V_2 -> V_82 = F_40 ( ( 2 * V_63 + 1 ) * sizeof( V_81 ) ,
V_90 ) ;
V_2 -> V_83 = F_40 ( ( 2 * V_63 + 1 ) * sizeof( V_81 ) , V_90 ) ;
V_2 -> V_84 = F_40 ( ( V_63 + 1 ) * sizeof( V_81 ) , V_90 ) ;
V_2 -> V_85 = F_40 ( ( V_63 + 2 ) * ( 2 * V_63 + 1 ) * sizeof( V_81 ) ,
V_90 ) ;
V_2 -> V_86 = F_40 ( ( V_63 + 1 ) * sizeof( int ) , V_90 ) ;
V_2 -> V_87 = F_40 ( ( V_63 + 1 ) * sizeof( int ) , V_90 ) ;
V_2 -> V_88 = F_40 ( ( V_63 + 1 ) * sizeof( int ) , V_90 ) ;
if ( V_2 -> V_82 &&
V_2 -> V_83 &&
V_2 -> V_84 &&
V_2 -> V_85 &&
V_2 -> V_86 &&
V_2 -> V_87 &&
V_2 -> V_88 )
return 0 ;
F_37 ( V_2 ) ;
return - V_91 ;
}
static void F_41 ( struct V_5 * V_6 , int V_92 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
int V_69 ;
T_5 V_93 ;
for ( V_69 = 0 ; V_69 < V_2 -> V_89 ; V_69 ++ ) {
V_93 = F_42 ( V_2 -> V_94 , V_92 , V_69 / 2 ) ;
if ( V_69 & 1 )
V_93 >>= 16 ;
V_93 &= 0xffff ;
V_2 -> V_82 [ ( 2 * V_69 ) + 1 ] = ( V_81 ) V_93 ;
}
}
static void F_43 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
V_81 T_4 * V_95 = V_2 -> V_96 ;
V_81 T_4 * V_97 = V_2 -> V_98 ;
V_81 * V_99 = V_2 -> V_82 ;
const int V_63 = V_2 -> V_89 ;
V_81 * V_100 ;
int V_69 , V_101 ;
V_100 = V_2 -> V_83 ;
memset ( & V_100 [ 1 ] , 0 , sizeof( V_81 ) * ( 2 * V_63 - 1 ) ) ;
for ( V_69 = 1 ; V_69 < 2 * V_63 ; V_69 += 2 ) {
for ( V_101 = 0 ; V_101 < V_2 -> V_102 ; V_101 ++ ) {
if ( V_99 [ V_69 ] & ( ( unsigned short ) 0x1 << V_101 ) )
V_100 [ V_69 ] = F_44 ( V_95 + V_69 * V_101 ) ^ V_100 [ V_69 ] ;
}
}
for ( V_69 = 2 , V_101 = 1 ; V_101 <= V_63 ; V_69 = ++ V_101 << 1 ) {
if ( V_100 [ V_101 ] == 0 ) {
V_100 [ V_69 ] = 0 ;
} else {
V_81 V_103 ;
V_103 = F_44 ( V_97 + V_100 [ V_101 ] ) ;
V_103 = ( V_103 * 2 ) % V_2 -> V_104 ;
V_100 [ V_69 ] = F_44 ( V_95 + V_103 ) ;
}
}
return;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
V_81 * V_105 = V_2 -> V_84 ;
V_81 * V_100 = V_2 -> V_83 ;
int * V_106 = V_2 -> V_86 ;
int * V_107 = V_2 -> V_87 ;
int * V_108 = V_2 -> V_88 ;
int V_109 = V_2 -> V_104 ;
const V_81 V_63 = V_2 -> V_89 ;
const int V_110 = 2 * V_63 + 1 ;
V_81 T_4 * V_97 = V_2 -> V_98 ;
V_81 T_4 * V_95 = V_2 -> V_96 ;
int V_69 , V_101 , V_111 ;
T_5 V_112 , V_103 ;
V_81 * V_113 = V_2 -> V_85 ;
int V_114 ;
int V_115 ;
int V_116 ;
V_112 = 0 ;
V_106 [ 0 ] = - 1 ;
memset ( V_113 , 0 , sizeof( V_81 ) * V_110 ) ;
V_113 [ 0 ] = 1 ;
V_107 [ 0 ] = 1 ;
V_105 [ 0 ] = 0 ;
V_108 [ 0 ] = ( V_106 [ 0 ] * 2 - V_105 [ 0 ] ) >> 1 ;
V_106 [ 1 ] = 0 ;
memset ( & V_113 [ V_110 ] , 0 , sizeof( V_81 ) * V_110 ) ;
V_113 [ V_110 ] = 1 ;
V_107 [ 1 ] = V_100 [ 1 ] ;
V_105 [ 1 ] = 0 ;
V_108 [ 1 ] = ( V_106 [ 1 ] * 2 - V_105 [ 1 ] ) >> 1 ;
memset ( & V_113 [ ( V_63 + 1 ) * V_110 ] , 0 , sizeof( V_81 ) * V_110 ) ;
for ( V_69 = 1 ; V_69 <= V_63 ; V_69 ++ ) {
V_106 [ V_69 + 1 ] = V_69 << 1 ;
if ( V_107 [ V_69 ] == 0 ) {
V_112 ++ ;
V_103 = ( ( V_63 - ( V_105 [ V_69 ] >> 1 ) - 1 ) / 2 ) ;
if ( ( V_63 - ( V_105 [ V_69 ] >> 1 ) - 1 ) & 0x1 )
V_103 += 2 ;
else
V_103 += 1 ;
if ( V_112 == V_103 ) {
for ( V_101 = 0 ; V_101 <= ( V_105 [ V_69 ] >> 1 ) + 1 ; V_101 ++ )
V_113 [ ( V_63 + 1 ) * V_110 + V_101 ] =
V_113 [ V_69 * V_110 + V_101 ] ;
V_105 [ V_63 + 1 ] = V_105 [ V_69 ] ;
return;
}
for ( V_101 = 0 ; V_101 <= V_105 [ V_69 ] >> 1 ; V_101 ++ )
V_113 [ ( V_69 + 1 ) * V_110 + V_101 ] = V_113 [ V_69 * V_110 + V_101 ] ;
V_105 [ V_69 + 1 ] = V_105 [ V_69 ] ;
} else {
V_114 = 0 ;
V_115 = - 1 ;
for ( V_101 = 0 ; V_101 < V_69 ; V_101 ++ ) {
if ( ( V_107 [ V_101 ] ) && ( V_108 [ V_101 ] > V_115 ) ) {
V_115 = V_108 [ V_101 ] ;
V_114 = V_101 ;
}
}
V_116 = ( V_106 [ V_69 ] - V_106 [ V_114 ] ) ;
if ( ( V_105 [ V_69 ] >> 1 ) > ( ( V_105 [ V_114 ] >> 1 ) + V_116 ) )
V_105 [ V_69 + 1 ] = V_105 [ V_69 ] ;
else
V_105 [ V_69 + 1 ] = ( ( V_105 [ V_114 ] >> 1 ) + V_116 ) * 2 ;
for ( V_111 = 0 ; V_111 < V_110 ; V_111 ++ )
V_113 [ ( V_69 + 1 ) * V_110 + V_111 ] = 0 ;
for ( V_111 = 0 ; V_111 <= V_105 [ V_114 ] >> 1 ; V_111 ++ ) {
V_81 V_117 , V_118 , V_119 ;
if ( ! ( V_113 [ V_114 * V_110 + V_111 ] && V_107 [ V_69 ] ) )
continue;
V_117 = F_44 ( V_97 + V_107 [ V_69 ] ) ;
V_118 = F_44 ( V_97 + V_107 [ V_114 ] ) ;
V_119 = F_44 ( V_97 + V_113 [ V_114 * V_110 + V_111 ] ) ;
V_103 = V_117 + ( V_109 - V_118 ) + V_119 ;
V_117 = F_44 ( V_95 + V_103 % V_109 ) ;
V_113 [ ( V_69 + 1 ) * V_110 + ( V_111 + V_116 ) ] = V_117 ;
}
for ( V_111 = 0 ; V_111 <= V_105 [ V_69 ] >> 1 ; V_111 ++ )
V_113 [ ( V_69 + 1 ) * V_110 + V_111 ] ^= V_113 [ V_69 * V_110 + V_111 ] ;
}
V_108 [ V_69 + 1 ] = ( V_106 [ V_69 + 1 ] * 2 - V_105 [ V_69 + 1 ] ) >> 1 ;
if ( V_69 >= V_63 )
continue;
for ( V_111 = 0 ; V_111 <= ( V_105 [ V_69 + 1 ] >> 1 ) ; V_111 ++ ) {
V_103 = 2 * ( V_69 - 1 ) ;
if ( V_111 == 0 ) {
V_107 [ V_69 + 1 ] = V_100 [ V_103 + 3 ] ;
} else if ( V_113 [ ( V_69 + 1 ) * V_110 + V_111 ] && V_100 [ V_103 + 3 - V_111 ] ) {
V_81 V_117 , V_118 , V_119 ;
V_117 = F_44 ( V_97 +
V_113 [ ( V_69 + 1 ) * V_110 + V_111 ] ) ;
V_118 = V_100 [ 2 * ( V_69 - 1 ) + 3 - V_111 ] ;
V_119 = F_44 ( V_97 + V_118 ) ;
V_103 = V_117 + V_119 ;
V_103 %= V_109 ;
V_107 [ V_69 + 1 ] = F_44 ( V_95 + V_103 ) ^
V_107 [ V_69 + 1 ] ;
}
}
}
return;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned long V_120 ;
const int V_63 = V_2 -> V_89 ;
const int V_110 = 2 * V_63 + 1 ;
int V_64 = V_2 -> V_76 ;
int V_121 = 0 ;
int V_122 ;
int V_69 ;
T_5 V_123 ;
V_81 * V_113 = V_2 -> V_85 ;
F_47 ( V_2 -> V_124 , V_125 , V_126 ) ;
for ( V_69 = 0 ; V_69 <= V_2 -> V_84 [ V_63 + 1 ] >> 1 ; V_69 ++ ) {
F_48 ( V_2 -> V_124 , V_69 ,
V_113 [ ( V_63 + 1 ) * V_110 + V_69 ] ) ;
V_121 ++ ;
}
V_123 = ( V_121 - 1 ) << 16 ;
if ( V_64 == 1024 )
V_123 |= 1 ;
F_47 ( V_2 -> V_124 , V_127 , V_123 ) ;
F_47 ( V_2 -> V_124 , V_128 ,
V_64 * 8 + V_2 -> V_102 * V_63 ) ;
V_120 = V_129 + F_49 ( V_130 ) ;
while ( ! ( F_50 ( V_2 -> V_124 , V_131 )
& V_132 ) ) {
if ( F_51 ( F_52 ( V_129 , V_120 ) ) ) {
F_25 ( V_2 -> V_52 , L_5 ) ;
return - 1 ;
}
F_53 () ;
}
V_122 = ( F_50 ( V_2 -> V_124 , V_131 )
& V_133 ) >> 8 ;
if ( V_122 == V_2 -> V_84 [ V_63 + 1 ] >> 1 )
return V_121 - 1 ;
return - 1 ;
}
static void F_54 ( struct V_5 * V_6 , T_6 * V_20 , T_6 * V_94 ,
int V_134 , int V_135 , int V_121 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
int V_69 = 0 ;
int V_136 , V_137 , V_64 , V_138 ;
T_5 V_103 ;
T_6 V_139 ;
V_64 = V_2 -> V_76 ;
while ( V_121 ) {
V_103 = F_55 ( V_2 -> V_124 , V_69 ) - 1 ;
V_136 = V_103 / 8 ;
V_137 = V_103 % 8 ;
if ( V_136 >= ( V_64 + V_135 ) )
F_56 () ;
if ( V_136 < V_64 ) {
V_139 = * ( V_20 + V_136 ) ;
* ( V_20 + V_136 ) ^= ( 1 << V_137 ) ;
V_138 = V_134 * V_2 -> V_76 + V_136 ;
F_57 ( V_2 -> V_52 , L_6 ,
V_138 , V_137 , V_139 , * ( V_20 + V_136 ) ) ;
} else {
V_103 = V_134 * V_2 -> V_140
+ ( V_136 - V_64 ) ;
V_139 = V_94 [ V_103 ] ;
V_94 [ V_103 ] ^= ( 1 << V_137 ) ;
V_138 = V_103 + V_9 -> V_94 . V_67 -> V_71 [ 0 ] ;
F_57 ( V_2 -> V_52 , L_7 ,
V_138 , V_137 , V_139 , V_94 [ V_103 ] ) ;
}
V_69 ++ ;
V_121 -- ;
}
return;
}
static int F_58 ( struct V_5 * V_6 , T_7 V_141 , T_6 * V_20 ,
T_1 * V_94 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
int V_69 , V_121 , V_70 ;
T_6 * V_142 ;
int V_143 = 0 ;
V_70 = V_9 -> V_94 . V_144 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ )
if ( V_94 [ V_69 ] != 0xff )
goto V_145;
return 0 ;
V_145:
for ( V_69 = 0 ; V_69 < V_2 -> V_146 ; V_69 ++ ) {
V_121 = 0 ;
if ( V_141 & 0x1 ) {
V_142 = V_20 + V_69 * V_2 -> V_76 ;
F_41 ( V_6 , V_69 ) ;
F_43 ( V_6 ) ;
F_45 ( V_6 ) ;
V_121 = F_46 ( V_6 ) ;
if ( V_121 == - 1 ) {
F_25 ( V_2 -> V_52 , L_8 ) ;
V_6 -> V_147 . V_148 ++ ;
return - V_39 ;
} else {
F_54 ( V_6 , V_142 , V_94 , V_69 ,
V_2 -> V_140 , V_121 ) ;
V_6 -> V_147 . V_149 += V_121 ;
V_143 += V_121 ;
}
}
V_141 >>= 1 ;
}
return V_143 ;
}
static int F_59 ( struct V_5 * V_6 ,
struct V_9 * V_36 , T_6 * V_20 , int V_150 , int V_151 )
{
struct V_1 * V_2 = V_36 -> V_10 ;
int V_152 = V_36 -> V_94 . V_153 ;
T_6 * V_154 = V_36 -> V_155 ;
T_5 * V_71 = V_36 -> V_94 . V_67 -> V_71 ;
T_5 V_156 ;
unsigned long V_120 ;
int V_157 = 0 ;
F_60 ( V_2 -> V_94 , V_158 , V_159 ) ;
F_60 ( V_2 -> V_94 , V_158 , V_160 ) ;
F_60 ( V_2 -> V_94 , V_161 , ( F_61 ( V_2 -> V_94 , V_161 )
& ~ V_162 ) | V_163 ) ;
F_60 ( V_2 -> V_94 , V_158 , V_164 ) ;
F_60 ( V_2 -> V_94 , V_158 , V_165 ) ;
V_36 -> V_166 ( V_6 , V_20 , V_152 ) ;
V_36 -> V_166 ( V_6 , V_154 , V_6 -> V_61 ) ;
V_120 = V_129 + F_49 ( V_130 ) ;
while ( ( F_61 ( V_2 -> V_94 , V_167 ) & V_168 ) ) {
if ( F_51 ( F_52 ( V_129 , V_120 ) ) ) {
F_25 ( V_2 -> V_52 , L_9 ) ;
return - V_39 ;
}
F_53 () ;
}
V_156 = F_61 ( V_2 -> V_94 , V_169 ) ;
if ( V_156 != 0 ) {
V_157 = F_58 ( V_6 , V_156 , V_20 , & V_154 [ V_71 [ 0 ] ] ) ;
if ( V_157 < 0 )
return 0 ;
}
return V_157 ;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_9 * V_36 , const T_6 * V_20 , int V_150 )
{
struct V_1 * V_2 = V_36 -> V_10 ;
T_5 * V_71 = V_36 -> V_94 . V_67 -> V_71 ;
int V_69 , V_101 ;
unsigned long V_120 ;
F_60 ( V_2 -> V_94 , V_158 , V_159 ) ;
F_60 ( V_2 -> V_94 , V_158 , V_160 ) ;
F_60 ( V_2 -> V_94 , V_161 , ( F_61 ( V_2 -> V_94 , V_161 ) |
V_162 ) & ~ V_163 ) ;
F_60 ( V_2 -> V_94 , V_158 , V_164 ) ;
F_60 ( V_2 -> V_94 , V_158 , V_165 ) ;
V_36 -> V_170 ( V_6 , ( T_1 * ) V_20 , V_6 -> V_171 ) ;
V_120 = V_129 + F_49 ( V_130 ) ;
while ( ( F_61 ( V_2 -> V_94 , V_167 ) & V_168 ) ) {
if ( F_51 ( F_52 ( V_129 , V_120 ) ) ) {
F_25 ( V_2 -> V_52 , L_10 ) ;
return - V_39 ;
}
F_53 () ;
}
for ( V_69 = 0 ; V_69 < V_2 -> V_146 ; V_69 ++ ) {
for ( V_101 = 0 ; V_101 < V_2 -> V_140 ; V_101 ++ ) {
int V_138 ;
V_138 = V_69 * V_2 -> V_140 + V_101 ;
V_36 -> V_155 [ V_71 [ V_138 ] ] =
F_63 ( V_2 -> V_94 , V_69 , V_101 ) ;
}
}
V_36 -> V_170 ( V_6 , V_36 -> V_155 , V_6 -> V_61 ) ;
return 0 ;
}
static void F_64 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
T_5 V_123 = 0 ;
struct V_66 * V_172 ;
F_60 ( V_2 -> V_94 , V_158 , V_159 ) ;
F_60 ( V_2 -> V_94 , V_158 , V_160 ) ;
switch ( V_2 -> V_89 ) {
case 2 :
V_123 = V_173 ;
break;
case 4 :
V_123 = V_174 ;
break;
case 8 :
V_123 = V_175 ;
break;
case 12 :
V_123 = V_176 ;
break;
case 24 :
V_123 = V_177 ;
break;
}
if ( V_2 -> V_76 == 512 )
V_123 |= V_178 ;
else if ( V_2 -> V_76 == 1024 )
V_123 |= V_179 ;
switch ( V_2 -> V_146 ) {
case 1 :
V_123 |= V_180 ;
break;
case 2 :
V_123 |= V_181 ;
break;
case 4 :
V_123 |= V_182 ;
break;
case 8 :
V_123 |= V_183 ;
break;
}
V_123 |= ( V_184 | V_185
| V_186 ) ;
F_60 ( V_2 -> V_94 , V_161 , V_123 ) ;
V_172 = V_9 -> V_94 . V_67 ;
F_60 ( V_2 -> V_94 , V_187 , V_6 -> V_61 - 1 ) ;
F_60 ( V_2 -> V_94 , V_188 , V_172 -> V_71 [ 0 ] ) ;
F_60 ( V_2 -> V_94 , V_189 ,
V_172 -> V_71 [ V_172 -> V_70 - 1 ] ) ;
F_60 ( V_2 -> V_94 , V_190 , 2 ) ;
F_60 ( V_2 -> V_94 , V_191 , 0xff ) ;
F_60 ( V_2 -> V_94 , V_158 , V_164 ) ;
}
static int F_65 ( struct V_9 * V_36 ,
int * V_192 , int * V_64 )
{
* V_192 = * V_64 = 0 ;
if ( V_36 -> V_193 . V_192 == 0xff )
return - 1 ;
* V_192 = V_36 -> V_193 . V_192 ;
* V_64 = 512 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
int * V_63 , int * V_64 )
{
* V_63 = * V_64 = 0 ;
if ( V_2 -> V_9 . V_194 ) {
if ( ! F_65 ( & V_2 -> V_9 , V_63 , V_64 ) )
F_57 ( V_2 -> V_52 , L_11 ,
* V_63 , * V_64 ) ;
else
F_57 ( V_2 -> V_52 , L_12 ) ;
} else {
F_57 ( V_2 -> V_52 , L_13 ) ;
}
if ( * V_63 == 0 && * V_64 == 0 ) {
* V_63 = 2 ;
* V_64 = 512 ;
}
if ( V_2 -> V_89 == 0 ) {
if ( * V_63 <= 2 )
V_2 -> V_89 = 2 ;
else if ( * V_63 <= 4 )
V_2 -> V_89 = 4 ;
else if ( * V_63 < 8 )
V_2 -> V_89 = 8 ;
else if ( * V_63 < 12 )
V_2 -> V_89 = 12 ;
else if ( * V_63 < 24 )
V_2 -> V_89 = 24 ;
else
return - V_195 ;
}
if ( V_2 -> V_76 == 0 ) {
if ( * V_64 >= 1024 )
V_2 -> V_76 = 1024 ;
else if ( * V_64 >= 512 )
V_2 -> V_76 = 512 ;
else
return - V_195 ;
}
return 0 ;
}
static int T_8 F_67 ( struct V_196 * V_197 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_9 * V_9 = & V_2 -> V_9 ;
struct V_198 * V_199 , * V_200 , * V_201 ;
int V_63 , V_64 , V_202 ;
V_202 = F_66 ( V_2 , & V_63 , & V_64 ) ;
if ( V_202 ) {
F_25 ( V_2 -> V_52 , L_14 ) ;
return V_202 ;
}
if ( V_63 != V_2 -> V_89 ||
V_64 != V_2 -> V_76 )
F_57 ( V_2 -> V_52 , L_15 ) ;
V_63 = V_2 -> V_89 ;
V_64 = V_2 -> V_76 ;
V_2 -> V_80 = ( V_64 == 512 ) ?
V_2 -> V_203 :
V_2 -> V_204 ;
F_57 ( V_2 -> V_52 , L_16 ,
V_63 , V_64 ) ;
V_199 = F_68 ( V_197 , V_205 , 1 ) ;
if ( ! V_199 ) {
F_31 ( V_2 -> V_52 ,
L_17 ) ;
V_9 -> V_94 . V_206 = V_207 ;
return 0 ;
}
V_2 -> V_94 = F_69 ( V_199 -> V_208 , F_70 ( V_199 ) ) ;
if ( V_2 -> V_94 == NULL ) {
F_25 ( V_2 -> V_52 , L_18 ) ;
V_202 = - V_39 ;
goto V_209;
}
V_200 = F_68 ( V_197 , V_205 , 2 ) ;
V_201 = F_68 ( V_197 , V_205 , 3 ) ;
if ( V_200 && V_201 ) {
V_2 -> V_124 = F_69 ( V_200 -> V_208 ,
F_70 ( V_200 ) ) ;
V_2 -> V_79 = F_69 ( V_201 -> V_208 ,
F_70 ( V_201 ) ) ;
}
if ( ! V_2 -> V_124 || ! V_2 -> V_79 ) {
F_25 ( V_2 -> V_52 ,
L_19 ) ;
V_202 = - V_39 ;
goto V_210;
}
V_9 -> V_94 . V_153 = V_6 -> V_171 ;
switch ( V_6 -> V_171 ) {
case 2048 :
V_2 -> V_102 = V_211 ;
V_2 -> V_104 = ( 1 << V_2 -> V_102 ) - 1 ;
V_2 -> V_146 = V_6 -> V_171 / V_64 ;
V_2 -> V_140 = F_34 (
V_63 , V_64 ) ;
V_2 -> V_96 = F_36 ( V_2 ) ;
V_2 -> V_98 = V_2 -> V_79 +
V_2 -> V_80 ;
V_9 -> V_94 . V_212 = 1 ;
V_9 -> V_94 . V_213 = V_63 ;
V_9 -> V_94 . V_144 = V_2 -> V_140 *
V_2 -> V_146 ;
if ( V_9 -> V_94 . V_144 > V_6 -> V_61 - 2 ) {
F_25 ( V_2 -> V_52 , L_20 ) ;
V_202 = - V_195 ;
goto V_214;
}
F_35 ( & V_215 ,
V_6 -> V_61 ,
V_9 -> V_94 . V_144 ) ;
V_9 -> V_94 . V_67 = & V_215 ;
break;
case 512 :
case 1024 :
case 4096 :
F_31 ( V_2 -> V_52 ,
L_21 ) ;
default:
V_9 -> V_94 . V_206 = V_207 ;
return 0 ;
}
V_202 = F_39 ( V_2 ) ;
if ( V_202 ) {
F_25 ( V_2 -> V_52 ,
L_22 ) ;
goto V_216;
}
V_9 -> V_94 . V_217 = F_59 ;
V_9 -> V_94 . V_218 = F_62 ;
F_64 ( V_6 ) ;
return 0 ;
V_216:
V_214:
V_210:
F_71 ( V_2 -> V_94 ) ;
if ( V_2 -> V_124 )
F_71 ( V_2 -> V_124 ) ;
if ( V_2 -> V_79 )
F_71 ( V_2 -> V_79 ) ;
V_209:
return V_202 ;
}
static int F_72 ( struct V_5 * V_6 ,
const T_9 * V_219 , unsigned char * V_220 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_221 ;
V_221 = F_73 ( V_2 -> V_94 , V_222 ) ;
V_220 [ 0 ] = V_221 & 0xFF ;
V_220 [ 1 ] = ( V_221 >> 8 ) & 0xFF ;
V_221 = F_73 ( V_2 -> V_94 , V_223 ) & V_224 ;
V_220 [ 2 ] = V_221 & 0xFF ;
V_220 [ 3 ] = ( V_221 >> 8 ) & 0xFF ;
return 0 ;
}
static int F_74 ( struct V_5 * V_6 , struct V_9 * V_36 ,
T_6 * V_20 , int V_150 , int V_151 )
{
int V_152 = V_36 -> V_94 . V_153 ;
int V_70 = V_36 -> V_94 . V_144 ;
T_5 * V_71 = V_36 -> V_94 . V_67 -> V_71 ;
T_6 * V_37 = V_20 ;
T_6 * V_154 = V_36 -> V_155 ;
T_6 * V_225 ;
int V_156 ;
unsigned int V_226 = 0 ;
if ( F_75 () ) {
struct V_1 * V_2 = V_36 -> V_10 ;
F_76 ( V_2 -> V_94 , V_227 , V_228 ) ;
}
V_36 -> V_166 ( V_6 , V_37 , V_152 ) ;
if ( V_71 [ 0 ] != 0 ) {
V_36 -> V_229 ( V_6 , V_230 ,
V_6 -> V_171 + V_71 [ 0 ] , - 1 ) ;
}
V_225 = V_154 + V_71 [ 0 ] ;
V_36 -> V_166 ( V_6 , V_225 , V_70 ) ;
V_156 = V_36 -> V_94 . V_231 ( V_6 , V_37 , V_154 , NULL ) ;
if ( V_156 < 0 ) {
V_6 -> V_147 . V_148 ++ ;
} else {
V_6 -> V_147 . V_149 += V_156 ;
V_226 = F_77 (unsigned int, max_bitflips, stat) ;
}
V_36 -> V_229 ( V_6 , V_230 , V_6 -> V_171 , - 1 ) ;
V_36 -> V_166 ( V_6 , V_154 , V_6 -> V_61 ) ;
return V_226 ;
}
static int F_78 ( struct V_5 * V_6 , T_9 * V_219 ,
T_9 * V_232 , T_9 * V_233 )
{
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_234 ;
unsigned int V_235 , V_236 ;
V_234 = F_73 ( V_2 -> V_94 , V_167 ) ;
if ( F_79 ( ! ( V_234 & V_237 ) ) )
return 0 ;
V_236 = F_73 ( V_2 -> V_94 , V_222 ) & V_238 ;
V_235 = F_73 ( V_2 -> V_94 , V_222 ) & V_239 ;
V_235 >>= 4 ;
if ( V_234 & V_240 ) {
if ( ( V_236 == V_238 )
&& ( V_235 == ( V_239 >> 4 ) ) ) {
return 0 ;
}
F_80 ( V_2 -> V_52 , L_23
L_24 ) ;
return - V_39 ;
}
if ( V_234 & V_241 ) {
F_80 ( V_2 -> V_52 , L_25
L_26 ) ;
return 0 ;
}
F_80 ( V_2 -> V_52 , L_27
L_28
L_29 ,
V_235 , V_236 ) ;
if ( V_9 -> V_242 & V_243 ) {
( ( unsigned short * ) V_219 ) [ V_235 ] ^= ( 1 << V_236 ) ;
} else {
V_219 [ V_235 ] ^= ( 1 << V_236 ) ;
}
F_80 ( V_2 -> V_52 , L_30 ) ;
return 1 ;
}
static void F_81 ( struct V_5 * V_6 , int V_206 )
{
if ( F_75 () ) {
struct V_9 * V_9 = V_6 -> V_10 ;
struct V_1 * V_2 = V_9 -> V_10 ;
F_76 ( V_2 -> V_94 , V_227 , V_228 ) ;
}
}
static int F_82 ( struct V_1 * V_2 ,
struct V_244 * V_245 )
{
T_7 V_123 ;
T_7 V_73 [ 2 ] ;
int V_246 ;
struct V_247 * V_3 = & V_2 -> V_3 ;
enum V_248 V_29 ;
if ( F_83 ( V_245 , L_31 , & V_123 ) == 0 ) {
if ( V_123 >= 32 ) {
F_25 ( V_2 -> V_52 , L_32 , V_123 ) ;
return - V_195 ;
}
V_3 -> V_17 = V_123 ;
}
if ( F_83 ( V_245 , L_33 , & V_123 ) == 0 ) {
if ( V_123 >= 32 ) {
F_25 ( V_2 -> V_52 , L_34 , V_123 ) ;
return - V_195 ;
}
V_3 -> V_16 = V_123 ;
}
V_246 = F_84 ( V_245 ) ;
V_3 -> V_246 = V_246 < 0 ? V_207 : V_246 ;
V_3 -> V_249 = F_85 ( V_245 ) ;
if ( F_86 ( V_245 ) == 16 )
V_3 -> V_62 = 1 ;
V_3 -> V_18 = F_87 ( V_245 , 0 , & V_29 ) ;
V_3 -> V_19 = ( V_29 == V_250 ) ;
V_3 -> V_4 = F_88 ( V_245 , 1 ) ;
V_3 -> V_251 = F_88 ( V_245 , 2 ) ;
V_2 -> V_252 = F_89 ( V_245 , L_35 ) ;
if ( ! ( V_3 -> V_246 == V_253 ) || ! V_2 -> V_252 )
return 0 ;
if ( F_83 ( V_245 , L_36 , & V_123 ) == 0 ) {
if ( ( V_123 != 2 ) && ( V_123 != 4 ) && ( V_123 != 8 ) && ( V_123 != 12 ) &&
( V_123 != 24 ) ) {
F_25 ( V_2 -> V_52 ,
L_37 ,
V_123 ) ;
return - V_195 ;
}
V_2 -> V_89 = ( T_1 ) V_123 ;
}
if ( F_83 ( V_245 , L_38 , & V_123 ) == 0 ) {
if ( ( V_123 != 512 ) && ( V_123 != 1024 ) ) {
F_25 ( V_2 -> V_52 ,
L_39 ,
V_123 ) ;
return - V_195 ;
}
V_2 -> V_76 = ( V_254 ) V_123 ;
}
if ( F_90 ( V_245 , L_40 ,
V_73 , 2 ) != 0 ) {
F_25 ( V_2 -> V_52 , L_41 ) ;
return - V_195 ;
}
if ( ! V_73 [ 0 ] && ! V_73 [ 1 ] ) {
F_25 ( V_2 -> V_52 , L_42 ) ;
return - V_195 ;
}
V_2 -> V_203 = V_73 [ 0 ] ;
V_2 -> V_204 = V_73 [ 1 ] ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_244 * V_245 )
{
return - V_195 ;
}
static int T_8 F_91 ( struct V_196 * V_197 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_9 * V_9 = & V_2 -> V_9 ;
struct V_198 * V_199 ;
V_199 = F_68 ( V_197 , V_205 , 1 ) ;
if ( ! V_199 ) {
F_25 ( V_2 -> V_52 ,
L_43 ) ;
V_9 -> V_94 . V_206 = V_207 ;
return 0 ;
}
V_2 -> V_94 = F_69 ( V_199 -> V_208 , F_70 ( V_199 ) ) ;
if ( V_2 -> V_94 == NULL ) {
F_25 ( V_2 -> V_52 , L_18 ) ;
return - V_39 ;
}
V_9 -> V_94 . V_153 = V_6 -> V_171 ;
switch ( V_6 -> V_171 ) {
case 512 :
V_9 -> V_94 . V_67 = & V_255 ;
F_76 ( V_2 -> V_94 , V_256 , V_257 ) ;
break;
case 1024 :
V_9 -> V_94 . V_67 = & V_258 ;
F_76 ( V_2 -> V_94 , V_256 , V_259 ) ;
break;
case 2048 :
V_9 -> V_94 . V_67 = & V_258 ;
F_76 ( V_2 -> V_94 , V_256 , V_260 ) ;
break;
case 4096 :
V_9 -> V_94 . V_67 = & V_258 ;
F_76 ( V_2 -> V_94 , V_256 , V_261 ) ;
break;
default:
V_9 -> V_94 . V_206 = V_207 ;
return 0 ;
}
V_9 -> V_94 . V_262 = F_72 ;
V_9 -> V_94 . V_231 = F_78 ;
V_9 -> V_94 . V_263 = F_81 ;
V_9 -> V_94 . V_217 = F_74 ;
V_9 -> V_94 . V_144 = 4 ;
V_9 -> V_94 . V_213 = 1 ;
return 0 ;
}
static int T_8 F_92 ( struct V_196 * V_197 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_9 * V_9 ;
struct V_198 * V_264 ;
struct V_265 V_266 = {} ;
int V_267 ;
struct V_268 * V_268 ;
V_264 = F_68 ( V_197 , V_205 , 0 ) ;
if ( ! V_264 ) {
F_93 ( V_269 L_44 ) ;
return - V_270 ;
}
V_2 = F_40 ( sizeof( struct V_1 ) , V_90 ) ;
if ( ! V_2 ) {
F_93 ( V_269 L_45 ) ;
return - V_91 ;
}
V_2 -> V_53 = ( T_2 ) V_264 -> V_208 ;
V_2 -> V_15 = F_69 ( V_264 -> V_208 , F_70 ( V_264 ) ) ;
if ( V_2 -> V_15 == NULL ) {
F_93 ( V_269 L_46 ) ;
V_267 = - V_39 ;
goto V_271;
}
V_6 = & V_2 -> V_6 ;
V_9 = & V_2 -> V_9 ;
V_2 -> V_52 = & V_197 -> V_52 ;
if ( V_197 -> V_52 . V_272 ) {
V_267 = F_82 ( V_2 , V_197 -> V_52 . V_272 ) ;
if ( V_267 )
goto V_273;
} else {
memcpy ( & V_2 -> V_3 , V_197 -> V_52 . V_274 ,
sizeof( struct V_247 ) ) ;
}
V_9 -> V_10 = V_2 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_275 = V_276 ;
V_9 -> V_22 = V_2 -> V_15 ;
V_9 -> V_23 = V_2 -> V_15 ;
V_9 -> V_277 = F_8 ;
V_268 = F_94 ( & V_197 -> V_52 ) ;
if ( F_95 ( V_268 ) ) {
F_25 ( V_2 -> V_52 , L_47 ) ;
V_267 = F_96 ( V_268 ) ;
goto V_273;
}
if ( F_5 ( V_2 -> V_3 . V_18 ) ) {
V_267 = F_97 ( V_2 -> V_3 . V_18 , L_48 ) ;
if ( V_267 < 0 ) {
F_25 ( & V_197 -> V_52 ,
L_49 ,
V_2 -> V_3 . V_18 ) ;
goto V_273;
}
V_267 = F_98 ( V_2 -> V_3 . V_18 ) ;
if ( V_267 < 0 ) {
F_25 ( & V_197 -> V_52 ,
L_50 ,
V_2 -> V_3 . V_18 ) ;
goto V_273;
}
V_9 -> V_278 = F_10 ;
}
if ( F_5 ( V_2 -> V_3 . V_4 ) ) {
V_267 = F_97 ( V_2 -> V_3 . V_4 , L_51 ) ;
if ( V_267 < 0 ) {
F_25 ( & V_197 -> V_52 ,
L_52 ,
V_2 -> V_3 . V_4 ) ;
goto V_273;
}
V_267 = F_99 ( V_2 -> V_3 . V_4 , 1 ) ;
if ( V_267 < 0 ) {
F_25 ( & V_197 -> V_52 ,
L_53 ,
V_2 -> V_3 . V_4 ) ;
goto V_273;
}
}
V_9 -> V_94 . V_206 = V_2 -> V_3 . V_246 ;
V_9 -> V_279 = 20 ;
if ( V_2 -> V_3 . V_62 )
V_9 -> V_242 |= V_243 ;
V_9 -> V_166 = F_32 ;
V_9 -> V_170 = F_33 ;
F_100 ( V_197 , V_2 ) ;
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_3 . V_251 ) ) {
V_267 = F_97 ( V_2 -> V_3 . V_251 , L_54 ) ;
if ( V_267 < 0 ) {
F_25 ( & V_197 -> V_52 ,
L_55 ,
V_2 -> V_3 . V_251 ) ;
goto V_280;
}
V_267 = F_98 ( V_2 -> V_3 . V_251 ) ;
if ( V_267 < 0 ) {
F_25 ( & V_197 -> V_52 ,
L_56 ,
V_2 -> V_3 . V_251 ) ;
goto V_280;
}
if ( F_11 ( V_2 -> V_3 . V_251 ) ) {
F_93 ( V_281 L_57 ) ;
V_267 = - V_270 ;
goto V_280;
}
}
if ( V_2 -> V_3 . V_249 || V_249 ) {
F_93 ( V_281 L_58 ) ;
V_9 -> V_282 |= V_283 ;
}
if ( ! F_1 () )
V_60 = 0 ;
if ( V_60 ) {
T_10 V_284 ;
F_101 ( V_284 ) ;
F_102 ( V_285 , V_284 ) ;
V_2 -> V_46 = F_103 ( V_284 , NULL , NULL ) ;
if ( ! V_2 -> V_46 ) {
F_25 ( V_2 -> V_52 , L_59 ) ;
V_60 = 0 ;
}
}
if ( V_60 )
F_57 ( V_2 -> V_52 , L_60 ,
F_104 ( V_2 -> V_46 ) ) ;
else
F_57 ( V_2 -> V_52 , L_61 ) ;
if ( F_105 ( V_6 , 1 , NULL ) ) {
V_267 = - V_270 ;
goto V_286;
}
if ( V_9 -> V_94 . V_206 == V_253 ) {
if ( V_2 -> V_252 )
V_267 = F_67 ( V_197 , V_2 ) ;
else
V_267 = F_91 ( V_197 , V_2 ) ;
if ( V_267 != 0 )
goto V_287;
}
if ( F_106 ( V_6 ) ) {
V_267 = - V_270 ;
goto V_288;
}
V_6 -> V_289 = L_62 ;
V_266 . V_272 = V_197 -> V_52 . V_272 ;
V_267 = F_107 ( V_6 , NULL , & V_266 ,
V_2 -> V_3 . V_290 , V_2 -> V_3 . V_291 ) ;
if ( ! V_267 )
return V_267 ;
V_288:
if ( V_2 -> V_252 && V_2 -> V_9 . V_94 . V_206 == V_253 ) {
F_60 ( V_2 -> V_94 , V_158 , V_160 ) ;
F_37 ( V_2 ) ;
}
if ( V_2 -> V_94 )
F_71 ( V_2 -> V_94 ) ;
if ( V_2 -> V_124 )
F_71 ( V_2 -> V_124 ) ;
if ( V_2 -> V_79 )
F_71 ( V_2 -> V_79 ) ;
V_287:
V_286:
V_280:
F_7 ( V_2 ) ;
F_100 ( V_197 , NULL ) ;
if ( V_2 -> V_46 )
F_108 ( V_2 -> V_46 ) ;
V_273:
F_71 ( V_2 -> V_15 ) ;
V_271:
F_38 ( V_2 ) ;
return V_267 ;
}
static int T_11 F_109 ( struct V_196 * V_197 )
{
struct V_1 * V_2 = F_110 ( V_197 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_111 ( V_6 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_252 && V_2 -> V_9 . V_94 . V_206 == V_253 ) {
F_60 ( V_2 -> V_94 , V_158 , V_160 ) ;
F_47 ( V_2 -> V_124 , V_125 ,
V_126 ) ;
F_37 ( V_2 ) ;
}
if ( F_5 ( V_2 -> V_3 . V_251 ) )
F_112 ( V_2 -> V_3 . V_251 ) ;
if ( F_5 ( V_2 -> V_3 . V_4 ) )
F_112 ( V_2 -> V_3 . V_4 ) ;
if ( F_5 ( V_2 -> V_3 . V_18 ) )
F_112 ( V_2 -> V_3 . V_18 ) ;
if ( V_2 -> V_94 )
F_71 ( V_2 -> V_94 ) ;
if ( V_2 -> V_79 )
F_71 ( V_2 -> V_79 ) ;
if ( V_2 -> V_124 )
F_71 ( V_2 -> V_124 ) ;
if ( V_2 -> V_46 )
F_108 ( V_2 -> V_46 ) ;
F_71 ( V_2 -> V_15 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
static int T_8 F_113 ( void )
{
return F_114 ( & V_292 , F_92 ) ;
}
static void T_11 F_115 ( void )
{
F_116 ( & V_292 ) ;
}
