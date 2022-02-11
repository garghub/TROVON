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
V_34 -> V_51 . V_52 = V_53 ;
V_40 = F_18 ( V_34 ) ;
if ( V_40 )
F_19 ( V_54 , & V_34 -> V_14 ) ;
F_20 ( & V_34 -> V_2 -> V_43 ,
L_8
L_9 ,
V_2 -> V_55 . V_56 ,
V_2 -> V_55 . V_57 ,
V_2 -> V_55 . V_58 ,
V_2 -> V_55 . V_59 ,
( ( V_38 -> V_48 . V_60 *
( V_38 -> V_48 . V_22 >> 9 ) ) >> 11 ) ,
V_38 -> V_48 . V_22 ,
V_40 ? L_10 : L_11 ) ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
struct V_37 * V_38 ;
int V_61 , V_39 ;
V_38 = (struct V_37 * ) V_36 -> V_46 -> V_38 ;
V_39 = F_22 ( V_38 -> V_48 . V_22 ) ;
if ( V_39 ) {
F_23 ( V_45 , V_36 -> V_46 , L_12 ,
V_38 -> V_48 . V_22 ) ;
return V_39 ;
}
V_36 -> V_62 = V_38 -> V_48 . V_60 ;
V_36 -> V_63 = V_38 -> V_48 . V_22 ;
V_36 -> V_64 = 0 ;
for ( V_61 = 512 ; V_61 < V_38 -> V_48 . V_22 ; V_61 = V_61 << 1 )
V_36 -> V_64 ++ ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 ,
struct V_65 * V_66 )
{
if ( F_22 ( V_36 -> V_63 ) != 0 )
return - V_67 ;
V_66 -> V_68 = ( V_36 -> V_62 << V_36 -> V_64 ) >> 10 ;
V_66 -> V_69 = 16 ;
V_66 -> V_70 = 128 >> V_36 -> V_64 ;
return 0 ;
}
static T_1
F_25 ( struct V_71 * V_72 )
{
return V_73 ;
}
static T_1
F_26 ( struct V_71 * V_72 )
{
if ( V_72 -> V_74 == V_73 )
return V_75 ;
F_23 ( V_45 , V_72 -> V_76 , L_13 ,
V_72 -> V_74 ) ;
return NULL ;
}
static void F_27 ( struct V_33 * V_34 ,
struct V_71 * V_72 ,
struct V_77 * V_77 )
{
char V_19 ;
V_19 = V_78 | V_79 | V_80 ;
if ( ( V_77 -> V_81 . V_30 . V_82 & V_19 ) == V_19 )
F_28 ( V_34 ) ;
}
static struct V_71 * F_29 ( struct V_33 * V_83 ,
struct V_35 * V_36 ,
struct V_84 * V_85 )
{
struct V_37 * V_38 ;
unsigned long * V_86 ;
struct V_25 * V_87 ;
struct V_71 * V_72 ;
struct V_4 * V_5 ;
struct V_88 V_89 ;
struct V_90 * V_91 ;
char * V_92 ;
int V_15 , V_93 , V_94 , V_95 ;
T_2 V_96 , V_97 , V_98 ;
unsigned int V_9 , V_99 ;
unsigned char V_30 ;
V_38 = (struct V_37 * ) V_36 -> V_46 -> V_38 ;
if ( F_30 ( V_85 ) == V_21 ) {
V_30 = V_100 ;
} else if ( F_30 ( V_85 ) == V_18 ) {
V_30 = V_101 ;
} else
return F_31 ( - V_67 ) ;
V_9 = V_36 -> V_63 ;
V_97 = F_32 ( V_85 ) >> V_36 -> V_64 ;
V_98 =
( F_32 ( V_85 ) + F_33 ( V_85 ) - 1 ) >> V_36 -> V_64 ;
V_15 = 0 ;
V_93 = 0 ;
F_34 (bv, req, iter) {
if ( V_91 -> V_102 & ( V_9 - 1 ) )
return F_31 ( - V_67 ) ;
V_15 += V_91 -> V_102 >> ( V_36 -> V_64 + 9 ) ;
#if F_35 ( V_103 )
if ( F_36 ( F_37 ( V_91 -> V_104 ) , V_91 -> V_102 ) )
V_93 += V_91 -> V_102 / V_9 ;
#endif
}
if ( V_15 != V_98 - V_97 + 1 )
return F_31 ( - V_67 ) ;
V_94 = 2 + V_15 ;
V_95 = sizeof( struct V_6 ) + sizeof( struct V_25 ) +
V_93 * sizeof( unsigned long ) ;
if ( V_38 -> V_48 . V_105 . V_106 . V_107 == 0 ) {
V_94 += V_15 - 1 ;
V_95 += ( V_15 - 1 ) * sizeof( struct V_25 ) ;
}
V_72 = F_38 ( V_47 , V_94 , V_95 , V_83 ) ;
if ( F_12 ( V_72 ) )
return V_72 ;
V_5 = V_72 -> V_108 ;
F_5 ( V_5 ++ , V_72 -> V_7 , F_30 ( V_85 ) ,
V_36 -> V_63 , F_32 ( V_85 ) , F_33 ( V_85 ) ) ;
V_86 = ( unsigned long * ) ( V_72 -> V_7 + sizeof( struct V_6 ) ) ;
V_87 = (struct V_25 * ) ( V_86 + V_93 ) ;
if ( V_38 -> V_48 . V_105 . V_106 . V_107 != 0 ) {
V_5 [ - 1 ] . V_14 |= V_109 ;
F_7 ( V_5 ++ , V_87 ++ , F_30 ( V_85 ) , 0 , V_15 ) ;
}
V_96 = V_97 ;
F_34 (bv, req, iter) {
V_92 = F_37 ( V_91 -> V_104 ) + V_91 -> V_110 ;
if ( V_111 ) {
char * V_112 = F_39 ( V_111 ,
V_42 | V_113 ) ;
if ( V_112 && F_30 ( V_85 ) == V_18 )
memcpy ( V_112 + V_91 -> V_110 , V_92 , V_91 -> V_102 ) ;
if ( V_112 )
V_92 = V_112 + V_91 -> V_110 ;
}
for ( V_99 = 0 ; V_99 < V_91 -> V_102 ; V_99 += V_9 ) {
if ( V_38 -> V_48 . V_105 . V_106 . V_107 == 0 ) {
V_5 [ - 1 ] . V_14 |= V_109 ;
F_7 ( V_5 , V_87 ++ ,
F_30 ( V_85 ) ,
V_96 - V_97 , 1 ) ;
V_5 -> V_14 = V_109 ;
V_5 ++ ;
} else {
if ( V_96 > V_97 )
V_5 [ - 1 ] . V_14 |= V_114 ;
else
V_5 [ - 1 ] . V_14 |= V_109 ;
}
V_5 -> V_12 = V_30 ;
V_5 -> V_15 = V_36 -> V_63 ;
if ( F_36 ( V_92 , V_9 ) ) {
V_5 -> V_16 = ( V_17 ) ( V_115 ) V_86 ;
V_5 -> V_14 = V_116 ;
V_86 = F_40 ( V_86 , V_92 , V_9 ) ;
} else {
V_5 -> V_16 = ( V_17 ) ( V_115 ) V_92 ;
V_5 -> V_14 = 0 ;
}
V_5 ++ ;
V_92 += V_9 ;
V_96 ++ ;
}
}
if ( F_41 ( V_85 ) ||
V_36 -> V_46 -> V_117 & V_118 )
F_19 ( V_119 , & V_72 -> V_14 ) ;
V_72 -> V_76 = V_83 ;
V_72 -> V_83 = V_83 ;
V_72 -> V_36 = V_36 ;
V_72 -> V_120 = V_83 -> V_49 * V_121 ;
V_72 -> V_122 = 32 ;
V_72 -> V_123 = F_42 () ;
V_72 -> V_124 = V_125 ;
return V_72 ;
}
static int
F_43 ( struct V_71 * V_72 , struct V_84 * V_85 )
{
struct V_37 * V_38 ;
struct V_4 * V_5 ;
struct V_88 V_89 ;
struct V_90 * V_91 ;
char * V_92 , * V_16 ;
unsigned int V_9 , V_99 ;
int V_124 ;
if ( ! V_111 )
goto V_126;
V_38 = (struct V_37 * ) V_72 -> V_36 -> V_46 -> V_38 ;
V_9 = V_72 -> V_36 -> V_63 ;
V_5 = V_72 -> V_108 ;
V_5 ++ ;
if ( V_38 -> V_48 . V_105 . V_106 . V_107 != 0 )
V_5 ++ ;
F_34 (bv, req, iter) {
V_92 = F_37 ( V_91 -> V_104 ) + V_91 -> V_110 ;
for ( V_99 = 0 ; V_99 < V_91 -> V_102 ; V_99 += V_9 ) {
if ( V_38 -> V_48 . V_105 . V_106 . V_107 == 0 )
V_5 ++ ;
if ( V_92 ) {
if ( V_5 -> V_14 & V_116 )
V_16 = * ( ( char * * ) ( ( V_115 ) V_5 -> V_16 ) ) ;
else
V_16 = ( char * ) ( ( V_115 ) V_5 -> V_16 ) ;
if ( V_92 != V_16 ) {
if ( F_30 ( V_85 ) == V_21 )
memcpy ( V_92 , V_16 , V_91 -> V_102 ) ;
F_44 ( V_111 ,
( void * ) ( ( V_115 ) V_16 & V_127 ) ) ;
}
V_92 = NULL ;
}
V_5 ++ ;
}
}
V_126:
V_124 = V_72 -> V_124 == V_128 ;
F_45 ( V_72 , V_72 -> V_83 ) ;
return V_124 ;
}
static void F_46 ( struct V_71 * V_72 )
{
V_72 -> V_124 = V_125 ;
}
static int
F_47 ( struct V_33 * V_34 ,
struct V_129 * V_130 )
{
V_130 -> V_131 = 1 ;
V_130 -> V_132 = 1 ;
V_130 -> V_133 = V_134 ;
V_130 -> V_135 = sizeof( struct V_136 ) ;
memcpy ( V_130 -> V_137 ,
& ( (struct V_37 * ) V_34 -> V_38 ) -> V_48 ,
sizeof ( struct V_136 ) ) ;
V_130 -> V_138 = 0 ;
return 0 ;
}
static void
F_48 ( struct V_33 * V_34 , struct V_77 * V_77 ,
char * V_139 )
{
T_3 * V_140 ;
V_140 = ( T_3 * ) F_49 ( V_77 ) ;
if ( V_140 ) {
F_23 ( V_141 , V_34 ,
L_14
L_15 , V_139 ,
F_50 ( & V_77 -> V_81 ) ? L_16 : L_17 ,
F_51 ( & V_77 -> V_81 ) , F_52 ( & V_77 -> V_81 ) ,
F_53 ( & V_77 -> V_81 ) , V_140 [ 0 ] , V_140 [ 1 ] ,
V_140 [ 2 ] , V_140 [ 3 ] ) ;
} else {
F_23 ( V_141 , V_34 , L_3 ,
L_18 ) ;
}
}
static void
F_54 ( struct V_33 * V_34 , struct V_71 * V_85 ,
struct V_77 * V_77 )
{
char * V_142 ;
struct V_4 * V_143 , * V_144 , * V_145 ;
int V_146 , V_147 , V_148 , V_15 ;
V_142 = ( char * ) F_55 ( V_149 ) ;
if ( V_142 == NULL ) {
F_23 ( V_45 , V_34 , L_3 ,
L_19 ) ;
return;
}
V_146 = sprintf ( V_142 , V_150
L_20 ,
F_56 ( & V_34 -> V_2 -> V_43 ) ) ;
V_146 += sprintf ( V_142 + V_146 , V_150
L_21 , V_85 ,
V_77 -> V_81 . V_30 . V_151 , V_77 -> V_81 . V_30 . V_82 ) ;
V_146 += sprintf ( V_142 + V_146 , V_150
L_22 ,
F_56 ( & V_34 -> V_2 -> V_43 ) ,
( void * ) ( V_115 ) V_77 -> V_81 . V_30 . V_152 ) ;
if ( V_77 -> V_153 . V_154 . V_155 . V_156 ) {
for ( V_147 = 0 ; V_147 < 4 ; V_147 ++ ) {
V_146 += sprintf ( V_142 + V_146 , V_150
L_23 ,
( 8 * V_147 ) , ( ( 8 * V_147 ) + 7 ) ) ;
for ( V_148 = 0 ; V_148 < 8 ; V_148 ++ ) {
V_146 += sprintf ( V_142 + V_146 , L_24 ,
V_77 -> V_157 [ 8 * V_147 + V_148 ] ) ;
}
V_146 += sprintf ( V_142 + V_146 , L_25 ) ;
}
} else {
V_146 += sprintf ( V_142 + V_146 , V_150
L_26 ) ;
}
F_57 ( V_158 L_3 , V_142 ) ;
V_143 = V_85 -> V_108 ;
for ( V_145 = V_143 ; V_145 -> V_14 & ( V_109 | V_114 ) ; V_145 ++ ) ;
V_144 = F_58 ( V_143 + 8 , V_145 ) ;
V_146 = sprintf ( V_142 , V_150 L_27 , V_85 ) ;
while ( V_143 <= V_144 ) {
V_146 += sprintf ( V_142 + V_146 , V_150
L_28 ,
V_143 , ( ( int * ) V_143 ) [ 0 ] , ( ( int * ) V_143 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_143 -> V_15 ;
V_15 += sizeof( int ) )
V_146 += sprintf ( V_142 + V_146 , L_29 ,
( ( int * ) ( V_115 ) V_143 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_146 += sprintf ( V_142 + V_146 , L_25 ) ;
V_143 ++ ;
}
F_57 ( V_158 L_3 , V_142 ) ;
V_146 = 0 ;
if ( V_143 < ( (struct V_4 * ) ( V_115 ) V_77 -> V_81 . V_30 . V_152 ) - 2 ) {
V_143 = ( (struct V_4 * ) ( V_115 ) V_77 -> V_81 . V_30 . V_152 ) - 2 ;
V_146 += sprintf ( V_142 + V_146 , V_150 L_30 ) ;
}
V_144 = F_58 ( (struct V_4 * ) ( V_115 ) V_77 -> V_81 . V_30 . V_152 + 2 , V_145 ) ;
while ( V_143 <= V_144 ) {
V_146 += sprintf ( V_142 + V_146 , V_150
L_28 ,
V_143 , ( ( int * ) V_143 ) [ 0 ] , ( ( int * ) V_143 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_143 -> V_15 ;
V_15 += sizeof( int ) )
V_146 += sprintf ( V_142 + V_146 , L_29 ,
( ( int * ) ( V_115 ) V_143 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_146 += sprintf ( V_142 + V_146 , L_25 ) ;
V_143 ++ ;
}
if ( V_143 < V_145 - 2 ) {
V_143 = V_145 - 2 ;
V_146 += sprintf ( V_142 + V_146 , V_150 L_30 ) ;
}
while ( V_143 <= V_145 ) {
V_146 += sprintf ( V_142 + V_146 , V_150
L_28 ,
V_143 , ( ( int * ) V_143 ) [ 0 ] , ( ( int * ) V_143 ) [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < 32 && V_15 < V_143 -> V_15 ;
V_15 += sizeof( int ) )
V_146 += sprintf ( V_142 + V_146 , L_29 ,
( ( int * ) ( V_115 ) V_143 -> V_16 )
[ ( V_15 >> 2 ) ] ) ;
V_146 += sprintf ( V_142 + V_146 , L_25 ) ;
V_143 ++ ;
}
if ( V_146 > 0 )
F_57 ( V_158 L_3 , V_142 ) ;
F_59 ( ( unsigned long ) V_142 ) ;
}
static int T_4
F_60 ( void )
{
int V_159 ;
F_61 ( V_3 . V_160 , 4 ) ;
V_159 = F_62 ( & V_161 ) ;
if ( ! V_159 )
F_63 () ;
return V_159 ;
}
static void T_5
F_64 ( void )
{
F_65 ( & V_161 ) ;
}
