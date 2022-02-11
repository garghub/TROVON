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
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_39 ;
int V_40 ;
V_38 = (struct V_37 * ) V_34 -> V_38 ;
if ( ! V_38 ) {
V_38 = F_9 ( sizeof( * V_38 ) , V_41 | V_42 ) ;
if ( ! V_38 ) {
F_10 ( & V_34 -> V_2 -> V_43 ,
L_1
L_2 ) ;
return - V_44 ;
}
V_34 -> V_38 = ( void * ) V_38 ;
} else {
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
}
V_36 = F_11 () ;
if ( F_12 ( V_36 ) ) {
F_13 ( V_45 , V_2 , L_3 , L_4
L_5 ) ;
V_34 -> V_38 = NULL ;
F_14 ( V_38 ) ;
return F_15 ( V_36 ) ;
}
V_34 -> V_36 = V_36 ;
V_36 -> V_46 = V_34 ;
V_39 = F_16 ( V_34 , V_47 ,
& V_38 -> V_48 , 32 ) ;
if ( V_39 ) {
F_13 ( V_45 , V_2 , L_6
L_7 , V_39 ) ;
V_34 -> V_36 = NULL ;
F_17 ( V_36 ) ;
V_34 -> V_38 = NULL ;
F_14 ( V_38 ) ;
return V_39 ;
}
V_34 -> V_49 = V_50 ;
V_34 -> V_51 = V_52 ;
V_34 -> V_53 . V_54 = V_55 ;
V_40 = F_18 ( V_34 ) ;
if ( V_40 )
F_19 ( V_56 , & V_34 -> V_14 ) ;
F_20 ( & V_34 -> V_2 -> V_43 ,
L_8
L_9 ,
V_2 -> V_57 . V_58 ,
V_2 -> V_57 . V_59 ,
V_2 -> V_57 . V_60 ,
V_2 -> V_57 . V_61 ,
( ( V_38 -> V_48 . V_62 *
( V_38 -> V_48 . V_22 >> 9 ) ) >> 11 ) ,
V_38 -> V_48 . V_22 ,
V_40 ? L_10 : L_11 ) ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
struct V_37 * V_38 ;
int V_63 , V_39 ;
V_38 = (struct V_37 * ) V_36 -> V_46 -> V_38 ;
V_39 = F_22 ( V_38 -> V_48 . V_22 ) ;
if ( V_39 ) {
F_23 ( V_45 , V_36 -> V_46 , L_12 ,
V_38 -> V_48 . V_22 ) ;
return V_39 ;
}
V_36 -> V_64 = V_38 -> V_48 . V_62 ;
V_36 -> V_65 = V_38 -> V_48 . V_22 ;
V_36 -> V_66 = 0 ;
for ( V_63 = 512 ; V_63 < V_38 -> V_48 . V_22 ; V_63 = V_63 << 1 )
V_36 -> V_66 ++ ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 ,
struct V_67 * V_68 )
{
if ( F_22 ( V_36 -> V_65 ) != 0 )
return - V_69 ;
V_68 -> V_70 = ( V_36 -> V_64 << V_36 -> V_66 ) >> 10 ;
V_68 -> V_71 = 16 ;
V_68 -> V_72 = 128 >> V_36 -> V_66 ;
return 0 ;
}
static T_1
F_25 ( struct V_73 * V_74 )
{
return V_75 ;
}
static T_1
F_26 ( struct V_73 * V_74 )
{
if ( V_74 -> V_76 == V_75 )
return V_77 ;
F_23 ( V_45 , V_74 -> V_78 , L_13 ,
V_74 -> V_76 ) ;
return NULL ;
}
static void F_27 ( struct V_33 * V_34 ,
struct V_73 * V_74 ,
struct V_79 * V_79 )
{
char V_19 ;
V_19 = V_80 | V_81 | V_82 ;
if ( ( V_79 -> V_83 . V_30 . V_84 & V_19 ) == V_19 )
F_28 ( V_34 ) ;
}
static struct V_73 * F_29 ( struct V_33 * V_85 ,
struct V_35 * V_36 ,
struct V_86 * V_87 )
{
struct V_37 * V_38 ;
unsigned long * V_88 ;
struct V_25 * V_89 ;
struct V_73 * V_74 ;
struct V_4 * V_5 ;
struct V_90 V_91 ;
struct V_92 V_93 ;
char * V_94 ;
int V_15 , V_95 , V_96 , V_97 ;
T_2 V_98 , V_99 , V_100 ;
unsigned int V_9 , V_101 ;
unsigned char V_30 ;
V_38 = (struct V_37 * ) V_36 -> V_46 -> V_38 ;
if ( F_30 ( V_87 ) == V_21 ) {
V_30 = V_102 ;
} else if ( F_30 ( V_87 ) == V_18 ) {
V_30 = V_103 ;
} else
return F_31 ( - V_69 ) ;
V_9 = V_36 -> V_65 ;
V_99 = F_32 ( V_87 ) >> V_36 -> V_66 ;
V_100 =
( F_32 ( V_87 ) + F_33 ( V_87 ) - 1 ) >> V_36 -> V_66 ;
V_15 = 0 ;
V_95 = 0 ;
F_34 (bv, req, iter) {
if ( V_93 . V_104 & ( V_9 - 1 ) )
return F_31 ( - V_69 ) ;
V_15 += V_93 . V_104 >> ( V_36 -> V_66 + 9 ) ;
if ( F_35 ( F_36 ( V_93 . V_105 ) , V_93 . V_104 ) )
V_95 += V_93 . V_104 / V_9 ;
}
if ( V_15 != V_100 - V_99 + 1 )
return F_31 ( - V_69 ) ;
V_96 = 2 + V_15 ;
V_97 = sizeof( struct V_6 ) + sizeof( struct V_25 ) +
V_95 * sizeof( unsigned long ) ;
if ( V_38 -> V_48 . V_106 . V_107 . V_108 == 0 ) {
V_96 += V_15 - 1 ;
V_97 += ( V_15 - 1 ) * sizeof( struct V_25 ) ;
}
V_74 = F_37 ( V_47 , V_96 , V_97 , V_85 ) ;
if ( F_12 ( V_74 ) )
return V_74 ;
V_5 = V_74 -> V_109 ;
F_5 ( V_5 ++ , V_74 -> V_7 , F_30 ( V_87 ) ,
V_36 -> V_65 , F_32 ( V_87 ) , F_33 ( V_87 ) ) ;
V_88 = ( unsigned long * ) ( V_74 -> V_7 + sizeof( struct V_6 ) ) ;
V_89 = (struct V_25 * ) ( V_88 + V_95 ) ;
if ( V_38 -> V_48 . V_106 . V_107 . V_108 != 0 ) {
V_5 [ - 1 ] . V_14 |= V_110 ;
F_7 ( V_5 ++ , V_89 ++ , F_30 ( V_87 ) , 0 , V_15 ) ;
}
V_98 = V_99 ;
F_34 (bv, req, iter) {
V_94 = F_36 ( V_93 . V_105 ) + V_93 . V_111 ;
if ( V_112 ) {
char * V_113 = F_38 ( V_112 ,
V_42 | V_114 ) ;
if ( V_113 && F_30 ( V_87 ) == V_18 )
memcpy ( V_113 + V_93 . V_111 , V_94 , V_93 . V_104 ) ;
if ( V_113 )
V_94 = V_113 + V_93 . V_111 ;
}
for ( V_101 = 0 ; V_101 < V_93 . V_104 ; V_101 += V_9 ) {
if ( V_38 -> V_48 . V_106 . V_107 . V_108 == 0 ) {
V_5 [ - 1 ] . V_14 |= V_110 ;
F_7 ( V_5 , V_89 ++ ,
F_30 ( V_87 ) ,
V_98 - V_99 , 1 ) ;
V_5 -> V_14 = V_110 ;
V_5 ++ ;
} else {
if ( V_98 > V_99 )
V_5 [ - 1 ] . V_14 |= V_115 ;
else
V_5 [ - 1 ] . V_14 |= V_110 ;
}
V_5 -> V_12 = V_30 ;
V_5 -> V_15 = V_36 -> V_65 ;
if ( F_35 ( V_94 , V_9 ) ) {
V_5 -> V_16 = ( V_17 ) ( V_116 ) V_88 ;
V_5 -> V_14 = V_117 ;
V_88 = F_39 ( V_88 , V_94 , V_9 ) ;
} else {
V_5 -> V_16 = ( V_17 ) ( V_116 ) V_94 ;
V_5 -> V_14 = 0 ;
}
V_5 ++ ;
V_94 += V_9 ;
V_98 ++ ;
}
}
if ( F_40 ( V_87 ) ||
V_36 -> V_46 -> V_118 & V_119 )
F_19 ( V_120 , & V_74 -> V_14 ) ;
V_74 -> V_78 = V_85 ;
V_74 -> V_85 = V_85 ;
V_74 -> V_36 = V_36 ;
V_74 -> V_121 = V_85 -> V_49 * V_122 ;
V_74 -> V_123 = V_85 -> V_51 ;
V_74 -> V_124 = F_41 () ;
V_74 -> V_125 = V_126 ;
return V_74 ;
}
static int
F_42 ( struct V_73 * V_74 , struct V_86 * V_87 )
{
struct V_37 * V_38 ;
struct V_4 * V_5 ;
struct V_90 V_91 ;
struct V_92 V_93 ;
char * V_94 , * V_16 ;
unsigned int V_9 , V_101 ;
int V_125 ;
if ( ! V_112 )
goto V_127;
V_38 = (struct V_37 * ) V_74 -> V_36 -> V_46 -> V_38 ;
V_9 = V_74 -> V_36 -> V_65 ;
V_5 = V_74 -> V_109 ;
V_5 ++ ;
if ( V_38 -> V_48 . V_106 . V_107 . V_108 != 0 )
V_5 ++ ;
F_34 (bv, req, iter) {
V_94 = F_36 ( V_93 . V_105 ) + V_93 . V_111 ;
for ( V_101 = 0 ; V_101 < V_93 . V_104 ; V_101 += V_9 ) {
if ( V_38 -> V_48 . V_106 . V_107 . V_108 == 0 )
V_5 ++ ;
if ( V_94 ) {
if ( V_5 -> V_14 & V_117 )
V_16 = * ( ( char * * ) ( ( V_116 ) V_5 -> V_16 ) ) ;
else
V_16 = ( char * ) ( ( V_116 ) V_5 -> V_16 ) ;
if ( V_94 != V_16 ) {
if ( F_30 ( V_87 ) == V_21 )
memcpy ( V_94 , V_16 , V_93 . V_104 ) ;
F_43 ( V_112 ,
( void * ) ( ( V_116 ) V_16 & V_128 ) ) ;
}
V_94 = NULL ;
}
V_5 ++ ;
}
}
V_127:
V_125 = V_74 -> V_125 == V_129 ;
F_44 ( V_74 , V_74 -> V_85 ) ;
return V_125 ;
}
static void F_45 ( struct V_73 * V_74 )
{
if ( V_74 -> V_123 < 0 )
V_74 -> V_125 = V_130 ;
else
V_74 -> V_125 = V_126 ;
}
static int
F_46 ( struct V_33 * V_34 ,
struct V_131 * V_132 )
{
V_132 -> V_133 = 1 ;
V_132 -> V_134 = 1 ;
V_132 -> V_135 = V_136 ;
V_132 -> V_137 = sizeof( struct V_138 ) ;
memcpy ( V_132 -> V_139 ,
& ( (struct V_37 * ) V_34 -> V_38 ) -> V_48 ,
sizeof ( struct V_138 ) ) ;
V_132 -> V_140 = 0 ;
return 0 ;
}
static void
F_47 ( struct V_33 * V_34 , struct V_79 * V_79 ,
char * V_141 )
{
T_3 * V_142 ;
V_142 = ( T_3 * ) F_48 ( V_79 ) ;
if ( V_142 ) {
F_23 ( V_143 , V_34 ,
L_14
L_15 , V_141 ,
F_49 ( & V_79 -> V_83 ) ? L_16 : L_17 ,
F_50 ( & V_79 -> V_83 ) , F_51 ( & V_79 -> V_83 ) ,
F_52 ( & V_79 -> V_83 ) , V_142 [ 0 ] , V_142 [ 1 ] ,
V_142 [ 2 ] , V_142 [ 3 ] ) ;
} else {
F_23 ( V_143 , V_34 , L_3 ,
L_18 ) ;
}
}
static void
F_53 ( struct V_33 * V_34 , struct V_73 * V_87 ,
struct V_79 * V_79 )
{
char * V_144 ;
struct V_4 * V_145 , * V_146 , * V_147 ;
int V_148 , V_149 , V_150 , V_15 ;
V_144 = ( char * ) F_54 ( V_151 ) ;
if ( V_144 == NULL ) {
F_23 ( V_45 , V_34 , L_3 ,
L_19 ) ;
return;
}
V_148 = sprintf ( V_144 , V_152
L_20 ,
F_55 ( & V_34 -> V_2 -> V_43 ) ) ;
V_148 += sprintf ( V_144 + V_148 , V_152
L_21 , V_87 ,
V_79 -> V_83 . V_30 . V_153 , V_79 -> V_83 . V_30 . V_84 ) ;
V_148 += sprintf ( V_144 + V_148 , V_152
L_22 ,
F_55 ( & V_34 -> V_2 -> V_43 ) ,
( void * ) ( V_116 ) V_79 -> V_83 . V_30 . V_154 ) ;
if ( V_79 -> V_155 . V_156 . V_157 . V_158 ) {
for ( V_149 = 0 ; V_149 < 4 ; V_149 ++ ) {
V_148 += sprintf ( V_144 + V_148 , V_152
L_23 ,
( 8 * V_149 ) , ( ( 8 * V_149 ) + 7 ) ) ;
for ( V_150 = 0 ; V_150 < 8 ; V_150 ++ ) {
V_148 += sprintf ( V_144 + V_148 , L_24 ,
V_79 -> V_159 [ 8 * V_149 + V_150 ] ) ;
}
V_148 += sprintf ( V_144 + V_148 , L_25 ) ;
}
} else {
V_148 += sprintf ( V_144 + V_148 , V_152
L_26 ) ;
}
F_56 ( V_160 L_3 , V_144 ) ;
V_145 = V_87 -> V_109 ;
for ( V_147 = V_145 ; V_147 -> V_14 & ( V_110 | V_115 ) ; V_147 ++ ) ;
V_146 = F_57 ( V_145 + 8 , V_147 ) ;
V_148 = sprintf ( V_144 , V_152 L_27 , V_87 ) ;
while ( V_145 <= V_146 ) {
V_148 += sprintf ( V_144 + V_148 , V_152
L_28 ,
V_145 , ( ( int * ) V_145 ) [ 0 ] , ( ( int * ) V_145 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_145 -> V_15 ;
V_15 += sizeof( int ) )
V_148 += sprintf ( V_144 + V_148 , L_29 ,
( ( int * ) ( V_116 ) V_145 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_148 += sprintf ( V_144 + V_148 , L_25 ) ;
V_145 ++ ;
}
F_56 ( V_160 L_3 , V_144 ) ;
V_148 = 0 ;
if ( V_145 < ( (struct V_4 * ) ( V_116 ) V_79 -> V_83 . V_30 . V_154 ) - 2 ) {
V_145 = ( (struct V_4 * ) ( V_116 ) V_79 -> V_83 . V_30 . V_154 ) - 2 ;
V_148 += sprintf ( V_144 + V_148 , V_152 L_30 ) ;
}
V_146 = F_57 ( (struct V_4 * ) ( V_116 ) V_79 -> V_83 . V_30 . V_154 + 2 , V_147 ) ;
while ( V_145 <= V_146 ) {
V_148 += sprintf ( V_144 + V_148 , V_152
L_28 ,
V_145 , ( ( int * ) V_145 ) [ 0 ] , ( ( int * ) V_145 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_145 -> V_15 ;
V_15 += sizeof( int ) )
V_148 += sprintf ( V_144 + V_148 , L_29 ,
( ( int * ) ( V_116 ) V_145 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_148 += sprintf ( V_144 + V_148 , L_25 ) ;
V_145 ++ ;
}
if ( V_145 < V_147 - 2 ) {
V_145 = V_147 - 2 ;
V_148 += sprintf ( V_144 + V_148 , V_152 L_30 ) ;
}
while ( V_145 <= V_147 ) {
V_148 += sprintf ( V_144 + V_148 , V_152
L_28 ,
V_145 , ( ( int * ) V_145 ) [ 0 ] , ( ( int * ) V_145 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_145 -> V_15 ;
V_15 += sizeof( int ) )
V_148 += sprintf ( V_144 + V_148 , L_29 ,
( ( int * ) ( V_116 ) V_145 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_148 += sprintf ( V_144 + V_148 , L_25 ) ;
V_145 ++ ;
}
if ( V_148 > 0 )
F_56 ( V_160 L_3 , V_144 ) ;
F_58 ( ( unsigned long ) V_144 ) ;
}
static int T_4
F_59 ( void )
{
int V_161 ;
F_60 ( V_3 . V_162 , 4 ) ;
V_161 = F_61 ( & V_163 ) ;
if ( ! V_161 )
F_62 () ;
return V_161 ;
}
static void T_5
F_63 ( void )
{
F_64 ( & V_163 ) ;
}
