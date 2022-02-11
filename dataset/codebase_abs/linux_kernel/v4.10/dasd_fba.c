static int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , & V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_3 ) ;
}
static void
F_5 ( struct V_4 * V_5 , struct V_6 * V_7 , int V_8 ,
int V_9 , int V_10 , int V_11 )
{
V_5 -> V_12 = V_13 ;
V_5 -> V_14 = 0 ;
V_5 -> V_15 = 16 ;
V_5 -> V_16 = ( V_17 ) F_6 ( V_7 ) ;
memset ( V_7 , 0 , sizeof ( struct V_6 ) ) ;
if ( V_8 == V_18 )
( V_7 -> V_19 ) . V_20 = 0x0 ;
else if ( V_8 == V_21 )
( V_7 -> V_19 ) . V_20 = 0x1 ;
else
V_7 -> V_19 . V_20 = 0x2 ;
V_7 -> V_22 = V_9 ;
V_7 -> V_23 = V_10 ;
V_7 -> V_24 = V_11 - 1 ;
}
static void
F_7 ( struct V_4 * V_5 , struct V_25 * V_7 , int V_8 ,
int V_26 , int V_27 )
{
V_5 -> V_12 = V_28 ;
V_5 -> V_14 = 0 ;
V_5 -> V_15 = 8 ;
V_5 -> V_16 = ( V_17 ) F_6 ( V_7 ) ;
memset ( V_7 , 0 , sizeof ( struct V_25 ) ) ;
if ( V_8 == V_18 )
V_7 -> V_29 . V_30 = 0x5 ;
else if ( V_8 == V_21 )
V_7 -> V_29 . V_30 = 0x6 ;
else
V_7 -> V_29 . V_30 = 0x8 ;
V_7 -> V_31 = V_26 ;
V_7 -> V_32 = V_27 ;
}
static int
F_8 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_37 * V_38 ;
int V_39 , V_40 ;
if ( ! V_36 ) {
V_36 = F_9 ( sizeof( * V_36 ) , V_41 | V_42 ) ;
if ( ! V_36 ) {
F_10 ( & V_34 -> V_2 -> V_43 ,
L_1
L_2 ) ;
return - V_44 ;
}
V_34 -> V_36 = V_36 ;
} else {
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
}
V_38 = F_11 () ;
if ( F_12 ( V_38 ) ) {
F_13 ( V_45 , V_2 , L_3 , L_4
L_5 ) ;
V_34 -> V_36 = NULL ;
F_14 ( V_36 ) ;
return F_15 ( V_38 ) ;
}
V_34 -> V_38 = V_38 ;
V_38 -> V_46 = V_34 ;
V_40 = F_16 ( V_34 , V_47 ,
& V_36 -> V_48 , 32 ) ;
if ( V_40 ) {
F_13 ( V_45 , V_2 , L_6
L_7 , V_40 ) ;
V_34 -> V_38 = NULL ;
F_17 ( V_38 ) ;
V_34 -> V_36 = NULL ;
F_14 ( V_36 ) ;
return V_40 ;
}
V_34 -> V_49 = V_50 ;
V_34 -> V_51 = V_52 ;
F_18 ( V_34 , V_53 ) ;
V_39 = F_19 ( V_34 ) ;
if ( V_39 )
F_20 ( V_54 , & V_34 -> V_14 ) ;
F_21 ( & V_34 -> V_2 -> V_43 ,
L_8
L_9 ,
V_2 -> V_55 . V_56 ,
V_2 -> V_55 . V_57 ,
V_2 -> V_55 . V_58 ,
V_2 -> V_55 . V_59 ,
( ( V_36 -> V_48 . V_60 *
( V_36 -> V_48 . V_22 >> 9 ) ) >> 11 ) ,
V_36 -> V_48 . V_22 ,
V_39 ? L_10 : L_11 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_38 )
{
struct V_35 * V_36 = V_38 -> V_46 -> V_36 ;
int V_61 , V_40 ;
V_40 = F_23 ( V_36 -> V_48 . V_22 ) ;
if ( V_40 ) {
F_24 ( V_45 , V_38 -> V_46 , L_12 ,
V_36 -> V_48 . V_22 ) ;
return V_40 ;
}
V_38 -> V_62 = V_36 -> V_48 . V_60 ;
V_38 -> V_63 = V_36 -> V_48 . V_22 ;
V_38 -> V_64 = 0 ;
for ( V_61 = 512 ; V_61 < V_36 -> V_48 . V_22 ; V_61 = V_61 << 1 )
V_38 -> V_64 ++ ;
return 0 ;
}
static int F_25 ( struct V_37 * V_38 ,
struct V_65 * V_66 )
{
if ( F_23 ( V_38 -> V_63 ) != 0 )
return - V_67 ;
V_66 -> V_68 = ( V_38 -> V_62 << V_38 -> V_64 ) >> 10 ;
V_66 -> V_69 = 16 ;
V_66 -> V_70 = 128 >> V_38 -> V_64 ;
return 0 ;
}
static T_1
F_26 ( struct V_71 * V_72 )
{
return V_73 ;
}
static T_1
F_27 ( struct V_71 * V_72 )
{
if ( V_72 -> V_74 == V_73 )
return V_75 ;
F_24 ( V_45 , V_72 -> V_76 , L_13 ,
V_72 -> V_74 ) ;
return NULL ;
}
static void F_28 ( struct V_33 * V_34 ,
struct V_71 * V_72 ,
struct V_77 * V_77 )
{
char V_19 ;
V_19 = V_78 | V_79 | V_80 ;
if ( ( V_77 -> V_81 . V_30 . V_82 & V_19 ) == V_19 )
F_29 ( V_34 ) ;
}
static struct V_71 * F_30 ( struct V_33 * V_83 ,
struct V_37 * V_38 ,
struct V_84 * V_85 )
{
struct V_35 * V_36 = V_38 -> V_46 -> V_36 ;
unsigned long * V_86 ;
struct V_25 * V_87 ;
struct V_71 * V_72 ;
struct V_4 * V_5 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
char * V_92 ;
int V_15 , V_93 , V_94 , V_95 ;
T_2 V_96 , V_97 , V_98 ;
unsigned int V_9 , V_99 ;
unsigned char V_30 ;
if ( F_31 ( V_85 ) == V_21 ) {
V_30 = V_100 ;
} else if ( F_31 ( V_85 ) == V_18 ) {
V_30 = V_101 ;
} else
return F_32 ( - V_67 ) ;
V_9 = V_38 -> V_63 ;
V_97 = F_33 ( V_85 ) >> V_38 -> V_64 ;
V_98 =
( F_33 ( V_85 ) + F_34 ( V_85 ) - 1 ) >> V_38 -> V_64 ;
V_15 = 0 ;
V_93 = 0 ;
F_35 (bv, req, iter) {
if ( V_91 . V_102 & ( V_9 - 1 ) )
return F_32 ( - V_67 ) ;
V_15 += V_91 . V_102 >> ( V_38 -> V_64 + 9 ) ;
if ( F_36 ( F_37 ( V_91 . V_103 ) , V_91 . V_102 ) )
V_93 += V_91 . V_102 / V_9 ;
}
if ( V_15 != V_98 - V_97 + 1 )
return F_32 ( - V_67 ) ;
V_94 = 2 + V_15 ;
V_95 = sizeof( struct V_6 ) + sizeof( struct V_25 ) +
V_93 * sizeof( unsigned long ) ;
if ( V_36 -> V_48 . V_104 . V_105 . V_106 == 0 ) {
V_94 += V_15 - 1 ;
V_95 += ( V_15 - 1 ) * sizeof( struct V_25 ) ;
}
V_72 = F_38 ( V_47 , V_94 , V_95 , V_83 ) ;
if ( F_12 ( V_72 ) )
return V_72 ;
V_5 = V_72 -> V_107 ;
F_5 ( V_5 ++ , V_72 -> V_7 , F_31 ( V_85 ) ,
V_38 -> V_63 , F_33 ( V_85 ) , F_34 ( V_85 ) ) ;
V_86 = ( unsigned long * ) ( V_72 -> V_7 + sizeof( struct V_6 ) ) ;
V_87 = (struct V_25 * ) ( V_86 + V_93 ) ;
if ( V_36 -> V_48 . V_104 . V_105 . V_106 != 0 ) {
V_5 [ - 1 ] . V_14 |= V_108 ;
F_7 ( V_5 ++ , V_87 ++ , F_31 ( V_85 ) , 0 , V_15 ) ;
}
V_96 = V_97 ;
F_35 (bv, req, iter) {
V_92 = F_37 ( V_91 . V_103 ) + V_91 . V_109 ;
if ( V_110 ) {
char * V_111 = F_39 ( V_110 ,
V_42 | V_112 ) ;
if ( V_111 && F_31 ( V_85 ) == V_18 )
memcpy ( V_111 + V_91 . V_109 , V_92 , V_91 . V_102 ) ;
if ( V_111 )
V_92 = V_111 + V_91 . V_109 ;
}
for ( V_99 = 0 ; V_99 < V_91 . V_102 ; V_99 += V_9 ) {
if ( V_36 -> V_48 . V_104 . V_105 . V_106 == 0 ) {
V_5 [ - 1 ] . V_14 |= V_108 ;
F_7 ( V_5 , V_87 ++ ,
F_31 ( V_85 ) ,
V_96 - V_97 , 1 ) ;
V_5 -> V_14 = V_108 ;
V_5 ++ ;
} else {
if ( V_96 > V_97 )
V_5 [ - 1 ] . V_14 |= V_113 ;
else
V_5 [ - 1 ] . V_14 |= V_108 ;
}
V_5 -> V_12 = V_30 ;
V_5 -> V_15 = V_38 -> V_63 ;
if ( F_36 ( V_92 , V_9 ) ) {
V_5 -> V_16 = ( V_17 ) ( V_114 ) V_86 ;
V_5 -> V_14 = V_115 ;
V_86 = F_40 ( V_86 , V_92 , V_9 ) ;
} else {
V_5 -> V_16 = ( V_17 ) ( V_114 ) V_92 ;
V_5 -> V_14 = 0 ;
}
V_5 ++ ;
V_92 += V_9 ;
V_96 ++ ;
}
}
if ( F_41 ( V_85 ) ||
V_38 -> V_46 -> V_116 & V_117 )
F_20 ( V_118 , & V_72 -> V_14 ) ;
V_72 -> V_76 = V_83 ;
V_72 -> V_83 = V_83 ;
V_72 -> V_38 = V_38 ;
V_72 -> V_119 = V_83 -> V_49 * V_120 ;
V_72 -> V_121 = V_83 -> V_51 ;
V_72 -> V_122 = F_42 () ;
V_72 -> V_123 = V_124 ;
return V_72 ;
}
static int
F_43 ( struct V_71 * V_72 , struct V_84 * V_85 )
{
struct V_35 * V_36 = V_72 -> V_38 -> V_46 -> V_36 ;
struct V_4 * V_5 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
char * V_92 , * V_16 ;
unsigned int V_9 , V_99 ;
int V_123 ;
if ( ! V_110 )
goto V_125;
V_9 = V_72 -> V_38 -> V_63 ;
V_5 = V_72 -> V_107 ;
V_5 ++ ;
if ( V_36 -> V_48 . V_104 . V_105 . V_106 != 0 )
V_5 ++ ;
F_35 (bv, req, iter) {
V_92 = F_37 ( V_91 . V_103 ) + V_91 . V_109 ;
for ( V_99 = 0 ; V_99 < V_91 . V_102 ; V_99 += V_9 ) {
if ( V_36 -> V_48 . V_104 . V_105 . V_106 == 0 )
V_5 ++ ;
if ( V_92 ) {
if ( V_5 -> V_14 & V_115 )
V_16 = * ( ( char * * ) ( ( V_114 ) V_5 -> V_16 ) ) ;
else
V_16 = ( char * ) ( ( V_114 ) V_5 -> V_16 ) ;
if ( V_92 != V_16 ) {
if ( F_31 ( V_85 ) == V_21 )
memcpy ( V_92 , V_16 , V_91 . V_102 ) ;
F_44 ( V_110 ,
( void * ) ( ( V_114 ) V_16 & V_126 ) ) ;
}
V_92 = NULL ;
}
V_5 ++ ;
}
}
V_125:
V_123 = V_72 -> V_123 == V_127 ;
F_45 ( V_72 , V_72 -> V_83 ) ;
return V_123 ;
}
static void F_46 ( struct V_71 * V_72 )
{
if ( V_72 -> V_121 < 0 )
V_72 -> V_123 = V_128 ;
else
V_72 -> V_123 = V_124 ;
}
static int
F_47 ( struct V_33 * V_34 ,
struct V_129 * V_130 )
{
struct V_35 * V_36 = V_34 -> V_36 ;
V_130 -> V_131 = 1 ;
V_130 -> V_132 = 1 ;
V_130 -> V_133 = V_134 ;
V_130 -> V_135 = sizeof( V_36 -> V_48 ) ;
memcpy ( V_130 -> V_136 , & V_36 -> V_48 ,
sizeof( V_36 -> V_48 ) ) ;
V_130 -> V_137 = 0 ;
return 0 ;
}
static void
F_48 ( struct V_33 * V_34 , struct V_77 * V_77 ,
char * V_138 )
{
T_3 * V_139 ;
V_139 = ( T_3 * ) F_49 ( V_77 ) ;
if ( V_139 ) {
F_24 ( V_140 , V_34 ,
L_14
L_15 , V_138 ,
F_50 ( & V_77 -> V_81 ) ? L_16 : L_17 ,
F_51 ( & V_77 -> V_81 ) , F_52 ( & V_77 -> V_81 ) ,
F_53 ( & V_77 -> V_81 ) , V_139 [ 0 ] , V_139 [ 1 ] ,
V_139 [ 2 ] , V_139 [ 3 ] ) ;
} else {
F_24 ( V_140 , V_34 , L_3 ,
L_18 ) ;
}
}
static void
F_54 ( struct V_33 * V_34 , struct V_71 * V_85 ,
struct V_77 * V_77 )
{
char * V_141 ;
struct V_4 * V_142 , * V_143 , * V_144 ;
int V_145 , V_146 , V_147 , V_15 ;
V_141 = ( char * ) F_55 ( V_148 ) ;
if ( V_141 == NULL ) {
F_24 ( V_45 , V_34 , L_3 ,
L_19 ) ;
return;
}
V_145 = sprintf ( V_141 , V_149
L_20 ,
F_56 ( & V_34 -> V_2 -> V_43 ) ) ;
V_145 += sprintf ( V_141 + V_145 , V_149
L_21 , V_85 ,
V_77 -> V_81 . V_30 . V_150 , V_77 -> V_81 . V_30 . V_82 ) ;
V_145 += sprintf ( V_141 + V_145 , V_149
L_22 ,
F_56 ( & V_34 -> V_2 -> V_43 ) ,
( void * ) ( V_114 ) V_77 -> V_81 . V_30 . V_151 ) ;
if ( V_77 -> V_152 . V_153 . V_154 . V_155 ) {
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
V_145 += sprintf ( V_141 + V_145 , V_149
L_23 ,
( 8 * V_146 ) , ( ( 8 * V_146 ) + 7 ) ) ;
for ( V_147 = 0 ; V_147 < 8 ; V_147 ++ ) {
V_145 += sprintf ( V_141 + V_145 , L_24 ,
V_77 -> V_156 [ 8 * V_146 + V_147 ] ) ;
}
V_145 += sprintf ( V_141 + V_145 , L_25 ) ;
}
} else {
V_145 += sprintf ( V_141 + V_145 , V_149
L_26 ) ;
}
F_57 ( V_157 L_3 , V_141 ) ;
V_142 = V_85 -> V_107 ;
for ( V_144 = V_142 ; V_144 -> V_14 & ( V_108 | V_113 ) ; V_144 ++ ) ;
V_143 = F_58 ( V_142 + 8 , V_144 ) ;
V_145 = sprintf ( V_141 , V_149 L_27 , V_85 ) ;
while ( V_142 <= V_143 ) {
V_145 += sprintf ( V_141 + V_145 , V_149
L_28 ,
V_142 , ( ( int * ) V_142 ) [ 0 ] , ( ( int * ) V_142 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_142 -> V_15 ;
V_15 += sizeof( int ) )
V_145 += sprintf ( V_141 + V_145 , L_29 ,
( ( int * ) ( V_114 ) V_142 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_145 += sprintf ( V_141 + V_145 , L_25 ) ;
V_142 ++ ;
}
F_57 ( V_157 L_3 , V_141 ) ;
V_145 = 0 ;
if ( V_142 < ( (struct V_4 * ) ( V_114 ) V_77 -> V_81 . V_30 . V_151 ) - 2 ) {
V_142 = ( (struct V_4 * ) ( V_114 ) V_77 -> V_81 . V_30 . V_151 ) - 2 ;
V_145 += sprintf ( V_141 + V_145 , V_149 L_30 ) ;
}
V_143 = F_58 ( (struct V_4 * ) ( V_114 ) V_77 -> V_81 . V_30 . V_151 + 2 , V_144 ) ;
while ( V_142 <= V_143 ) {
V_145 += sprintf ( V_141 + V_145 , V_149
L_28 ,
V_142 , ( ( int * ) V_142 ) [ 0 ] , ( ( int * ) V_142 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_142 -> V_15 ;
V_15 += sizeof( int ) )
V_145 += sprintf ( V_141 + V_145 , L_29 ,
( ( int * ) ( V_114 ) V_142 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_145 += sprintf ( V_141 + V_145 , L_25 ) ;
V_142 ++ ;
}
if ( V_142 < V_144 - 2 ) {
V_142 = V_144 - 2 ;
V_145 += sprintf ( V_141 + V_145 , V_149 L_30 ) ;
}
while ( V_142 <= V_144 ) {
V_145 += sprintf ( V_141 + V_145 , V_149
L_28 ,
V_142 , ( ( int * ) V_142 ) [ 0 ] , ( ( int * ) V_142 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_142 -> V_15 ;
V_15 += sizeof( int ) )
V_145 += sprintf ( V_141 + V_145 , L_29 ,
( ( int * ) ( V_114 ) V_142 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_145 += sprintf ( V_141 + V_145 , L_25 ) ;
V_142 ++ ;
}
if ( V_145 > 0 )
F_57 ( V_157 L_3 , V_141 ) ;
F_59 ( ( unsigned long ) V_141 ) ;
}
static int T_4
F_60 ( void )
{
int V_158 ;
F_61 ( V_3 . V_159 , 4 ) ;
V_158 = F_62 ( & V_160 ) ;
if ( ! V_158 )
F_63 () ;
return V_158 ;
}
static void T_5
F_64 ( void )
{
F_65 ( & V_160 ) ;
}
