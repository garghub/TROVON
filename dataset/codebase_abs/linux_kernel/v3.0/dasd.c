struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
return F_3 ( - V_4 ) ;
V_2 -> V_5 = ( void * ) F_4 ( V_3 | V_6 , 1 ) ;
if ( ! V_2 -> V_5 ) {
F_5 ( V_2 ) ;
return F_3 ( - V_4 ) ;
}
V_2 -> V_7 = ( void * ) F_6 ( V_3 | V_6 ) ;
if ( ! V_2 -> V_7 ) {
F_7 ( ( unsigned long ) V_2 -> V_5 , 1 ) ;
F_5 ( V_2 ) ;
return F_3 ( - V_4 ) ;
}
F_8 ( & V_2 -> V_8 , V_2 -> V_5 , V_9 * 2 ) ;
F_8 ( & V_2 -> V_10 , V_2 -> V_7 , V_9 ) ;
F_9 ( & V_2 -> V_11 ) ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_11 ( & V_2 -> V_13 ,
( void (*) ( unsigned long ) ) V_14 ,
( unsigned long ) V_2 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_13 ( & V_2 -> V_16 ) ;
V_2 -> V_16 . V_17 = V_18 ;
V_2 -> V_16 . V_19 = ( unsigned long ) V_2 ;
F_14 ( & V_2 -> V_20 , V_21 ) ;
F_14 ( & V_2 -> V_22 , V_23 ) ;
F_14 ( & V_2 -> V_24 , V_25 ) ;
V_2 -> V_26 = V_27 ;
V_2 -> V_28 = V_27 ;
F_15 ( & V_2 -> V_29 ) ;
return V_2 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_30 ) ;
F_17 ( ( unsigned long ) V_2 -> V_7 ) ;
F_7 ( ( unsigned long ) V_2 -> V_5 , 1 ) ;
F_5 ( V_2 ) ;
}
struct V_31 * F_18 ( void )
{
struct V_31 * V_32 ;
V_32 = F_2 ( sizeof( * V_32 ) , V_3 ) ;
if ( ! V_32 )
return F_3 ( - V_4 ) ;
F_10 ( & V_32 -> V_33 , - 1 ) ;
F_9 ( & V_32 -> V_34 ) ;
F_10 ( & V_32 -> V_12 , 0 ) ;
F_11 ( & V_32 -> V_13 ,
( void (*) ( unsigned long ) ) V_35 ,
( unsigned long ) V_32 ) ;
F_12 ( & V_32 -> V_15 ) ;
F_9 ( & V_32 -> V_36 ) ;
F_13 ( & V_32 -> V_16 ) ;
V_32 -> V_16 . V_17 = V_37 ;
V_32 -> V_16 . V_19 = ( unsigned long ) V_32 ;
return V_32 ;
}
void F_19 ( struct V_31 * V_32 )
{
F_5 ( V_32 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_38 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_32 ) {
V_38 = F_22 ( V_2 -> V_32 ) ;
if ( V_38 ) {
F_23 ( V_2 ) ;
return V_38 ;
}
}
V_2 -> V_26 = V_39 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
if ( V_2 -> V_40 ) {
if ( V_2 -> V_40 -> V_41 )
V_2 -> V_40 -> V_41 ( V_2 ) ;
F_26 ( V_2 -> V_40 -> V_42 ) ;
}
V_2 -> V_40 = NULL ;
if ( V_2 -> V_43 )
F_26 ( V_2 -> V_43 -> V_42 ) ;
V_2 -> V_43 = NULL ;
V_2 -> V_26 = V_27 ;
if ( V_2 -> V_32 )
F_27 ( V_2 -> V_32 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_38 ;
if ( V_2 -> V_32 ) {
V_38 = F_29 ( V_2 -> V_32 ) ;
if ( V_38 )
return V_38 ;
}
V_2 -> V_44 = F_30 ( F_31 ( & V_2 -> V_45 -> V_46 ) , 4 , 1 ,
8 * sizeof( long ) ) ;
F_32 ( V_2 -> V_44 , & V_47 ) ;
F_33 ( V_2 -> V_44 , V_48 ) ;
F_34 ( V_49 , V_2 , L_1 , L_2 ) ;
V_2 -> V_26 = V_50 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_38 ;
if ( V_2 -> V_32 ) {
F_36 ( V_2 -> V_32 ) ;
F_37 ( V_2 -> V_32 ) ;
}
V_38 = F_38 ( V_2 ) ;
if ( V_38 )
return V_38 ;
F_39 ( V_2 ) ;
F_34 ( V_49 , V_2 , L_3 , V_2 ) ;
if ( V_2 -> V_44 != NULL ) {
F_40 ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
}
V_2 -> V_26 = V_39 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_31 * V_32 ;
V_38 = 0 ;
V_32 = V_2 -> V_32 ;
if ( V_32 ) {
if ( V_32 -> V_51 -> V_40 -> V_52 != NULL )
V_38 = V_32 -> V_51 -> V_40 -> V_52 ( V_32 ) ;
if ( V_38 ) {
if ( V_38 != - V_53 )
V_2 -> V_26 = V_54 ;
return V_38 ;
}
F_42 ( V_32 ) ;
F_43 ( V_32 -> V_55 ,
V_32 -> V_56 << V_32 -> V_57 ) ;
V_2 -> V_26 = V_58 ;
V_38 = F_44 ( V_32 ) ;
if ( V_38 )
V_2 -> V_26 = V_50 ;
} else {
V_2 -> V_26 = V_58 ;
}
return V_38 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_38 ;
V_2 -> V_26 = V_50 ;
if ( V_2 -> V_32 ) {
struct V_31 * V_32 = V_2 -> V_32 ;
V_38 = F_46 ( V_32 ) ;
if ( V_38 ) {
V_2 -> V_26 = V_58 ;
return V_38 ;
}
F_47 ( V_32 ) ;
F_48 ( V_32 ) ;
V_32 -> V_56 = 0 ;
V_32 -> V_59 = 0 ;
V_32 -> V_57 = 0 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
V_2 -> V_26 = V_50 ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_60 * V_61 ;
struct V_62 V_63 ;
struct V_64 * V_65 ;
if ( V_2 -> V_40 -> V_66 ) {
V_38 = V_2 -> V_40 -> V_66 ( V_2 ) ;
if ( V_38 )
return V_38 ;
}
V_2 -> V_26 = V_67 ;
if ( V_2 -> V_32 ) {
F_51 ( V_2 -> V_32 ) ;
if ( ( V_2 -> V_68 & V_69 ) ) {
V_61 = V_2 -> V_32 -> V_55 ;
F_52 ( & F_53 ( V_61 ) -> V_70 , V_71 ) ;
return 0 ;
}
V_61 = V_2 -> V_32 -> V_72 -> V_73 ;
F_54 ( & V_63 , V_61 , V_74 ) ;
while ( ( V_65 = F_55 ( & V_63 ) ) )
F_52 ( & F_56 ( V_65 ) -> V_70 , V_71 ) ;
F_57 ( & V_63 ) ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_60 * V_61 ;
struct V_62 V_63 ;
struct V_64 * V_65 ;
if ( V_2 -> V_40 -> V_75 ) {
V_38 = V_2 -> V_40 -> V_75 ( V_2 ) ;
if ( V_38 )
return V_38 ;
}
V_2 -> V_26 = V_58 ;
if ( V_2 -> V_32 && ! ( V_2 -> V_68 & V_69 ) ) {
V_61 = V_2 -> V_32 -> V_72 -> V_73 ;
F_54 ( & V_63 , V_61 , V_74 ) ;
while ( ( V_65 = F_55 ( & V_63 ) ) )
F_52 ( & F_56 ( V_65 ) -> V_70 , V_71 ) ;
F_57 ( & V_63 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = 0 ;
if ( V_2 -> V_26 == V_27 &&
V_2 -> V_28 >= V_39 )
V_38 = F_20 ( V_2 ) ;
if ( ! V_38 &&
V_2 -> V_26 == V_39 &&
V_2 -> V_28 >= V_50 )
V_38 = F_28 ( V_2 ) ;
if ( ! V_38 &&
V_2 -> V_26 == V_50 &&
V_2 -> V_28 >= V_58 )
V_38 = F_41 ( V_2 ) ;
if ( ! V_38 &&
V_2 -> V_26 == V_54 &&
V_2 -> V_28 > V_54 )
V_38 = - V_76 ;
if ( ! V_38 &&
V_2 -> V_26 == V_58 &&
V_2 -> V_28 >= V_67 )
V_38 = F_50 ( V_2 ) ;
return V_38 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = 0 ;
if ( V_2 -> V_26 == V_67 &&
V_2 -> V_28 <= V_58 )
V_38 = F_58 ( V_2 ) ;
if ( ! V_38 &&
V_2 -> V_26 == V_58 &&
V_2 -> V_28 <= V_50 )
V_38 = F_45 ( V_2 ) ;
if ( ! V_38 &&
V_2 -> V_26 == V_54 &&
V_2 -> V_28 <= V_50 )
V_38 = F_49 ( V_2 ) ;
if ( ! V_38 &&
V_2 -> V_26 == V_50 &&
V_2 -> V_28 <= V_39 )
V_38 = F_35 ( V_2 ) ;
if ( ! V_38 &&
V_2 -> V_26 == V_39 &&
V_2 -> V_28 <= V_27 )
V_38 = F_24 ( V_2 ) ;
return V_38 ;
}
static void F_61 ( struct V_1 * V_2 )
{
int V_38 ;
if ( V_2 -> V_26 == V_2 -> V_28 )
return;
if ( V_2 -> V_26 < V_2 -> V_28 )
V_38 = F_59 ( V_2 ) ;
else
V_38 = F_60 ( V_2 ) ;
if ( V_38 == - V_53 )
return;
if ( V_38 )
V_2 -> V_28 = V_2 -> V_26 ;
if ( V_2 -> V_26 == V_2 -> V_28 )
F_62 ( & V_77 ) ;
F_52 ( & V_2 -> V_45 -> V_46 . V_70 , V_71 ) ;
}
static void V_21 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_63 ( V_79 , struct V_1 , V_20 ) ;
F_64 ( & V_2 -> V_29 ) ;
F_61 ( V_2 ) ;
F_65 ( & V_2 -> V_29 ) ;
F_66 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_68 ( & V_2 -> V_20 ) ;
}
static void V_25 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_63 ( V_79 , struct V_1 ,
V_24 ) ;
V_2 -> V_40 -> V_80 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_68 ( & V_2 -> V_24 ) ;
}
static void V_23 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_63 ( V_79 , struct V_1 ,
V_22 ) ;
V_2 -> V_45 -> V_81 -> V_82 ( V_2 -> V_45 ) ;
F_23 ( V_2 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_68 ( & V_2 -> V_22 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_28 )
{
F_21 ( V_2 ) ;
F_64 ( & V_2 -> V_29 ) ;
if ( V_83 && V_28 > V_58 )
V_28 = V_58 ;
if ( V_2 -> V_28 != V_28 ) {
if ( V_2 -> V_26 == V_28 )
F_62 ( & V_77 ) ;
V_2 -> V_28 = V_28 ;
}
if ( V_2 -> V_26 != V_2 -> V_28 )
F_61 ( V_2 ) ;
F_65 ( & V_2 -> V_29 ) ;
F_23 ( V_2 ) ;
}
static inline int F_72 ( struct V_1 * V_2 )
{
return ( V_2 -> V_26 == V_2 -> V_28 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
F_71 ( V_2 , V_67 ) ;
if ( V_2 -> V_26 <= V_39 )
F_71 ( V_2 , V_27 ) ;
F_74 ( V_77 , F_72 ( V_2 ) ) ;
}
static void F_75 ( struct V_31 * V_32 ,
struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * V_89 ;
unsigned int V_90 ;
if ( V_91 != V_92 )
return;
V_90 = 0 ;
F_76 (l, &block->ccw_queue)
if ( ++ V_90 >= 31 )
break;
V_93 . V_94 [ V_90 ] ++ ;
V_32 -> V_95 . V_94 [ V_90 ] ++ ;
}
static void F_77 ( struct V_31 * V_32 ,
struct V_84 * V_85 ,
struct V_86 * V_87 )
{
long V_96 , V_97 , V_98 , V_99 ;
long V_100 , V_101 ;
if ( V_91 != V_92 )
return;
V_101 = F_78 ( V_87 ) ;
if ( ! V_85 -> V_102 || ! V_85 -> V_103 ||
! V_85 -> V_104 || ! V_85 -> V_105 ||
! V_101 )
return;
V_96 = ( ( V_85 -> V_103 - V_85 -> V_102 ) >> 12 ) ;
V_97 = ( ( V_85 -> V_104 - V_85 -> V_103 ) >> 12 ) ;
V_98 = ( ( V_85 -> V_105 - V_85 -> V_104 ) >> 12 ) ;
V_99 = ( ( V_85 -> V_105 - V_85 -> V_102 ) >> 12 ) ;
V_100 = V_99 / V_101 ;
if ( ! V_93 . V_106 )
memset ( & V_93 , 0 ,
sizeof( struct V_107 ) ) ;
V_93 . V_106 ++ ;
V_93 . V_108 += V_101 ;
if ( ! V_32 -> V_95 . V_106 )
memset ( & V_32 -> V_95 , 0 ,
sizeof( struct V_107 ) ) ;
V_32 -> V_95 . V_106 ++ ;
V_32 -> V_95 . V_108 += V_101 ;
F_79 ( V_101 , V_109 , V_32 ) ;
F_79 ( V_99 , V_110 , V_32 ) ;
F_79 ( V_100 , V_111 , V_32 ) ;
F_79 ( V_96 , V_112 , V_32 ) ;
F_79 ( V_97 , V_113 , V_32 ) ;
F_79 ( V_97 / V_101 , V_114 , V_32 ) ;
F_79 ( V_98 , V_115 , V_32 ) ;
}
struct V_84 * F_80 ( int V_116 , int V_117 ,
int V_118 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 ;
F_81 ( V_118 > V_9 ||
( V_117 * sizeof( struct V_119 ) ) > V_9 ) ;
V_85 = F_2 ( sizeof( struct V_84 ) , V_3 ) ;
if ( V_85 == NULL )
return F_3 ( - V_4 ) ;
V_85 -> V_120 = NULL ;
if ( V_117 > 0 ) {
V_85 -> V_120 = F_82 ( V_117 , sizeof( struct V_119 ) ,
V_3 | V_6 ) ;
if ( V_85 -> V_120 == NULL ) {
F_5 ( V_85 ) ;
return F_3 ( - V_4 ) ;
}
}
V_85 -> V_19 = NULL ;
if ( V_118 > 0 ) {
V_85 -> V_19 = F_2 ( V_118 , V_3 | V_6 ) ;
if ( V_85 -> V_19 == NULL ) {
F_5 ( V_85 -> V_120 ) ;
F_5 ( V_85 ) ;
return F_3 ( - V_4 ) ;
}
}
V_85 -> V_116 = V_116 ;
F_83 ( V_121 , & V_85 -> V_122 ) ;
F_21 ( V_2 ) ;
return V_85 ;
}
struct V_84 * F_84 ( int V_116 , int V_117 ,
int V_118 ,
struct V_1 * V_2 )
{
unsigned long V_122 ;
struct V_84 * V_85 ;
char * V_19 ;
int V_123 ;
V_123 = ( sizeof( struct V_84 ) + 7L ) & - 8L ;
if ( V_117 > 0 )
V_123 += V_117 * sizeof( struct V_119 ) ;
if ( V_118 > 0 )
V_123 += V_118 ;
F_85 ( & V_2 -> V_11 , V_122 ) ;
V_85 = (struct V_84 * )
F_86 ( & V_2 -> V_8 , V_123 ) ;
F_87 ( & V_2 -> V_11 , V_122 ) ;
if ( V_85 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
V_19 = ( char * ) V_85 + ( ( sizeof( struct V_84 ) + 7L ) & - 8L ) ;
V_85 -> V_120 = NULL ;
if ( V_117 > 0 ) {
V_85 -> V_120 = (struct V_119 * ) V_19 ;
V_19 += V_117 * sizeof( struct V_119 ) ;
memset ( V_85 -> V_120 , 0 , V_117 * sizeof( struct V_119 ) ) ;
}
V_85 -> V_19 = NULL ;
if ( V_118 > 0 ) {
V_85 -> V_19 = V_19 ;
memset ( V_85 -> V_19 , 0 , V_118 ) ;
}
V_85 -> V_116 = V_116 ;
F_83 ( V_121 , & V_85 -> V_122 ) ;
F_21 ( V_2 ) ;
return V_85 ;
}
void F_88 ( struct V_84 * V_85 , struct V_1 * V_2 )
{
#ifdef F_89
struct V_119 * V_124 ;
V_124 = V_85 -> V_120 ;
do {
F_90 ( V_124 ) ;
} while ( V_124 ++ -> V_122 & ( V_125 | V_126 ) );
#endif
F_5 ( V_85 -> V_120 ) ;
F_5 ( V_85 -> V_19 ) ;
F_5 ( V_85 ) ;
F_23 ( V_2 ) ;
}
void F_91 ( struct V_84 * V_85 , struct V_1 * V_2 )
{
unsigned long V_122 ;
F_85 ( & V_2 -> V_11 , V_122 ) ;
F_92 ( & V_2 -> V_8 , V_85 ) ;
F_87 ( & V_2 -> V_11 , V_122 ) ;
F_23 ( V_2 ) ;
}
static inline int F_93 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
if ( V_85 == NULL )
return - V_127 ;
V_2 = V_85 -> V_128 ;
if ( strncmp ( ( char * ) & V_85 -> V_116 , V_2 -> V_40 -> V_129 , 4 ) ) {
F_34 ( V_48 , V_2 ,
L_4
L_5 ,
V_85 -> V_116 ,
* ( unsigned int * ) V_2 -> V_40 -> V_130 ) ;
return - V_127 ;
}
return 0 ;
}
int F_94 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_131 , V_38 ;
char V_132 [ V_133 ] ;
V_38 = F_93 ( V_85 ) ;
if ( V_38 )
return V_38 ;
V_131 = 0 ;
V_2 = (struct V_1 * ) V_85 -> V_128 ;
while ( ( V_131 < 5 ) && ( V_85 -> V_134 == V_135 ) ) {
V_38 = F_95 ( V_2 -> V_45 , ( long ) V_85 ) ;
switch ( V_38 ) {
case 0 :
V_85 -> V_134 = V_136 ;
V_85 -> V_104 = F_96 () ;
V_85 -> V_137 = 0 ;
F_34 ( V_138 , V_2 ,
L_6 ,
V_85 ) ;
break;
case - V_139 :
F_34 ( V_140 , V_2 , L_1 ,
L_7 ) ;
break;
case - V_141 :
F_34 ( V_140 , V_2 , L_1 ,
L_8 ) ;
break;
case - V_127 :
case - V_142 :
F_34 ( V_140 , V_2 , L_1 ,
L_9 ) ;
break;
default:
snprintf ( V_132 , V_133 , L_10 , V_38 ) ;
F_97 ( & V_2 -> V_45 -> V_46 , L_11
L_12 , V_132 ) ;
F_98 () ;
break;
}
V_131 ++ ;
}
F_66 ( V_2 ) ;
return V_38 ;
}
int F_99 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_38 ;
char V_132 [ V_133 ] ;
V_38 = F_93 ( V_85 ) ;
if ( V_38 ) {
V_85 -> V_143 = V_38 ;
return V_38 ;
}
V_2 = (struct V_1 * ) V_85 -> V_128 ;
if ( ( ( V_85 -> V_32 &&
F_100 ( V_144 , & V_85 -> V_32 -> V_51 -> V_122 ) ) ||
F_100 ( V_144 , & V_2 -> V_122 ) ) &&
! F_100 ( V_145 , & V_85 -> V_122 ) ) {
F_34 ( V_138 , V_2 , L_13
L_14 , V_85 ) ;
V_85 -> V_134 = V_146 ;
V_85 -> V_143 = - V_76 ;
return - V_76 ;
}
if ( V_85 -> V_131 < 0 ) {
sprintf ( V_132 , L_15 , V_85 ) ;
F_97 ( & V_2 -> V_45 -> V_46 , L_16
L_17 , V_132 ) ;
V_85 -> V_134 = V_146 ;
return - V_141 ;
}
V_85 -> V_103 = F_96 () ;
V_85 -> V_137 = V_147 ;
V_85 -> V_131 -- ;
if ( ! F_100 ( V_148 , & V_85 -> V_122 ) ) {
V_85 -> V_149 &= V_2 -> V_150 . V_151 ;
if ( ! V_85 -> V_149 )
V_85 -> V_149 = V_2 -> V_150 . V_151 ;
}
if ( V_85 -> V_152 == 1 ) {
V_38 = F_101 ( V_2 -> V_45 , V_85 -> V_120 ,
( long ) V_85 , V_85 -> V_149 ) ;
} else {
V_38 = F_102 ( V_2 -> V_45 , V_85 -> V_120 ,
( long ) V_85 , V_85 -> V_149 , 0 ) ;
}
switch ( V_38 ) {
case 0 :
V_85 -> V_134 = V_135 ;
break;
case - V_142 :
F_34 ( V_48 , V_2 , L_1 ,
L_18 ) ;
break;
case - V_153 :
F_34 ( V_48 , V_2 , L_1 ,
L_19 ) ;
break;
case - V_154 :
if ( F_100 ( V_148 , & V_85 -> V_122 ) ) {
F_34 ( V_48 , V_2 ,
L_20 ,
V_85 -> V_149 ) ;
} else if ( V_85 -> V_149 != V_2 -> V_150 . V_151 ) {
V_85 -> V_149 = V_2 -> V_150 . V_151 ;
F_34 ( V_138 , V_2 , L_1 ,
L_21
L_22 ) ;
} else {
F_34 ( V_48 , V_2 , L_1 ,
L_23
L_24 ) ;
F_103 ( V_2 ) ;
V_2 -> V_150 . V_151 = 0 ;
V_2 -> V_150 . V_155 = 0 ;
V_2 -> V_150 . V_156 = 0 ;
V_2 -> V_150 . V_157 =
F_104 ( V_2 -> V_45 ) ;
}
break;
case - V_139 :
F_34 ( V_48 , V_2 , L_1 ,
L_25 ) ;
break;
case - V_141 :
F_34 ( V_48 , V_2 , L_1 ,
L_26 ) ;
break;
case - V_127 :
F_34 ( V_48 , V_2 , L_1 ,
L_27
L_28 ) ;
break;
default:
snprintf ( V_132 , V_133 , L_29 , V_38 ) ;
F_97 ( & V_2 -> V_45 -> V_46 ,
L_30
L_31 , V_132 ) ;
F_98 () ;
break;
}
V_85 -> V_143 = V_38 ;
return V_38 ;
}
static void V_18 ( unsigned long V_158 )
{
unsigned long V_122 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_158 ;
F_85 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
F_106 ( V_2 , V_159 ) ;
F_87 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
F_66 ( V_2 ) ;
}
void F_107 ( struct V_1 * V_2 , int V_160 )
{
if ( V_160 == 0 )
F_108 ( & V_2 -> V_16 ) ;
else
F_109 ( & V_2 -> V_16 , V_147 + V_160 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_108 ( & V_2 -> V_16 ) ;
}
static void F_110 ( struct V_161 * V_45 ,
unsigned long V_162 )
{
struct V_84 * V_85 ;
struct V_1 * V_2 ;
if ( ! V_162 )
return;
V_85 = (struct V_84 * ) V_162 ;
if ( V_85 -> V_134 != V_135 ) {
F_111 ( V_138 , V_45 ,
L_32
L_33 , V_85 -> V_134 ) ;
return;
}
V_2 = F_112 ( V_45 ) ;
if ( F_113 ( V_2 ) ) {
F_111 ( V_138 , V_45 , L_1 ,
L_34 ) ;
return;
}
if ( ! V_85 -> V_128 ||
V_2 != V_85 -> V_128 ||
strncmp ( V_85 -> V_128 -> V_40 -> V_129 ,
( char * ) & V_85 -> V_116 , 4 ) ) {
F_111 ( V_138 , V_45 , L_1 ,
L_35 ) ;
F_23 ( V_2 ) ;
return;
}
V_85 -> V_134 = V_163 ;
F_39 ( V_2 ) ;
F_66 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
F_115 ( V_2 ) ;
F_106 ( V_2 , V_159 ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_32 )
F_51 ( V_2 -> V_32 ) ;
}
void F_116 ( struct V_161 * V_45 , unsigned long V_162 ,
struct V_164 * V_164 )
{
struct V_84 * V_85 , * V_165 ;
struct V_1 * V_2 ;
unsigned long long V_166 ;
int V_160 ;
F_117 ( F_118 () ) . V_167 [ V_168 ] ++ ;
if ( F_113 ( V_164 ) ) {
switch ( F_119 ( V_164 ) ) {
case - V_141 :
break;
case - V_153 :
F_111 ( V_48 , V_45 , L_36
L_37 , V_169 ) ;
break;
default:
F_111 ( V_48 , V_45 , L_36
L_38 , V_169 ,
F_119 ( V_164 ) ) ;
}
F_110 ( V_45 , V_162 ) ;
return;
}
V_166 = F_96 () ;
V_85 = (struct V_84 * ) V_162 ;
if ( ! V_85 ||
! ( F_120 ( & V_164 -> V_170 ) == ( V_171 | V_172 ) &&
F_121 ( & V_164 -> V_170 ) == 0 ) ) {
if ( V_85 )
memcpy ( & V_85 -> V_164 , V_164 , sizeof( * V_164 ) ) ;
V_2 = F_112 ( V_45 ) ;
if ( F_113 ( V_2 ) )
return;
if ( V_2 -> V_40 == V_173 ) {
F_23 ( V_2 ) ;
return;
}
V_2 -> V_40 -> V_174 ( V_2 , V_164 , L_39 ) ;
if ( V_2 -> V_68 & V_175 )
V_2 -> V_40 -> V_176 ( V_2 , V_85 , V_164 ) ;
V_2 -> V_40 -> V_177 ( V_2 , V_85 , V_164 ) ;
F_23 ( V_2 ) ;
}
if ( ! V_85 )
return;
V_2 = (struct V_1 * ) V_85 -> V_128 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_40 -> V_129 , ( char * ) & V_85 -> V_116 , 4 ) ) {
F_111 ( V_138 , V_45 , L_1 ,
L_35 ) ;
return;
}
if ( V_85 -> V_134 == V_136 &&
F_122 ( & V_164 -> V_170 ) & V_178 ) {
V_85 -> V_134 = V_179 ;
F_39 ( V_2 ) ;
F_62 ( & V_180 ) ;
F_66 ( V_2 ) ;
return;
}
if ( V_85 -> V_134 != V_135 ) {
F_34 ( V_138 , V_2 , L_40
L_41 , F_31 ( & V_45 -> V_46 ) , V_85 -> V_134 ) ;
return;
}
V_165 = NULL ;
V_160 = 0 ;
if ( F_120 ( & V_164 -> V_170 ) == ( V_171 | V_172 ) &&
F_121 ( & V_164 -> V_170 ) == 0 ) {
V_85 -> V_134 = V_181 ;
V_85 -> V_104 = V_166 ;
if ( V_85 -> V_182 . V_165 != & V_2 -> V_15 ) {
V_165 = F_123 ( V_85 -> V_182 . V_165 ,
struct V_84 , V_182 ) ;
}
} else {
if ( ! F_100 ( V_121 , & V_85 -> V_122 ) &&
V_85 -> V_131 > 0 ) {
if ( V_85 -> V_149 == V_2 -> V_150 . V_151 )
F_34 ( V_138 , V_2 ,
L_42
L_43 ,
V_85 -> V_131 ) ;
if ( ! F_100 ( V_148 , & V_85 -> V_122 ) )
V_85 -> V_149 = V_2 -> V_150 . V_151 ;
V_85 -> V_134 = V_163 ;
V_165 = V_85 ;
} else
V_85 -> V_134 = V_146 ;
}
if ( V_165 && ( V_165 -> V_134 == V_163 ) &&
( ! V_2 -> V_183 ) ) {
if ( V_2 -> V_40 -> V_184 ( V_165 ) == 0 )
V_160 = V_165 -> V_160 ;
}
if ( V_160 != 0 )
F_107 ( V_2 , V_160 ) ;
else
F_39 ( V_2 ) ;
F_66 ( V_2 ) ;
}
enum V_185 F_124 ( struct V_161 * V_45 , struct V_164 * V_164 )
{
struct V_1 * V_2 ;
V_2 = F_112 ( V_45 ) ;
if ( F_113 ( V_2 ) )
goto V_186;
if ( F_100 ( V_187 , & V_2 -> V_122 ) ||
V_2 -> V_26 != V_2 -> V_28 ||
! V_2 -> V_40 -> V_177 ) {
F_23 ( V_2 ) ;
goto V_186;
}
if ( V_2 -> V_40 -> V_174 )
V_2 -> V_40 -> V_174 ( V_2 , V_164 , L_44 ) ;
V_2 -> V_40 -> V_177 ( V_2 , NULL , V_164 ) ;
F_23 ( V_2 ) ;
V_186:
return V_188 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_84 * V_189 )
{
struct V_88 * V_89 , * V_190 ;
struct V_84 * V_85 ;
if ( ! V_189 -> V_32 )
return;
F_126 (l, n, &device->ccw_queue) {
V_85 = F_123 ( V_89 , struct V_84 , V_182 ) ;
if ( V_85 -> V_134 == V_163 &&
V_189 -> V_32 == V_85 -> V_32 ) {
V_85 -> V_134 = V_179 ;
}
}
}
static void F_127 ( struct V_1 * V_2 ,
struct V_88 * V_191 )
{
struct V_88 * V_89 , * V_190 ;
struct V_84 * V_85 ;
F_126 (l, n, &device->ccw_queue) {
V_85 = F_123 ( V_89 , struct V_84 , V_182 ) ;
if ( V_85 -> V_134 == V_163 ||
V_85 -> V_134 == V_135 ||
V_85 -> V_134 == V_136 )
break;
if ( V_85 -> V_134 == V_146 ) {
F_125 ( V_2 , V_85 ) ;
}
F_128 ( & V_85 -> V_182 , V_191 ) ;
}
}
static void F_129 ( struct V_1 * V_2 ,
struct V_88 * V_191 )
{
struct V_88 * V_89 , * V_190 ;
struct V_84 * V_85 ;
struct V_31 * V_32 ;
void (* F_130)( struct V_84 * , void * V_19 );
void * V_192 ;
char V_132 [ V_133 ] ;
F_126 (l, n, final_queue) {
V_85 = F_123 ( V_89 , struct V_84 , V_182 ) ;
F_131 ( & V_85 -> V_182 ) ;
V_32 = V_85 -> V_32 ;
F_130 = V_85 -> F_130 ;
V_192 = V_85 -> V_192 ;
if ( V_32 )
F_132 ( & V_32 -> V_36 ) ;
switch ( V_85 -> V_134 ) {
case V_181 :
V_85 -> V_134 = V_193 ;
break;
case V_146 :
V_85 -> V_134 = V_194 ;
break;
case V_179 :
V_85 -> V_134 = V_195 ;
break;
default:
snprintf ( V_132 , V_133 , L_45 , V_85 , V_85 -> V_134 ) ;
F_97 ( & V_2 -> V_45 -> V_46 ,
L_30
L_31 , V_132 ) ;
F_98 () ;
}
if ( V_85 -> F_130 != NULL )
( F_130 ) ( V_85 , V_192 ) ;
if ( V_32 )
F_133 ( & V_32 -> V_36 ) ;
}
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
if ( F_135 ( & V_2 -> V_15 ) )
return;
V_85 = F_123 ( V_2 -> V_15 . V_165 , struct V_84 , V_182 ) ;
if ( ( V_85 -> V_134 == V_135 && V_85 -> V_160 != 0 ) &&
( F_136 ( V_147 , V_85 -> V_160 + V_85 -> V_137 ) ) ) {
if ( V_2 -> V_40 -> V_196 ( V_85 ) != 0 ) {
F_97 ( & V_2 -> V_45 -> V_46 ,
L_46
L_47 ,
V_85 , ( V_85 -> V_160 / V_197 ) ) ;
V_85 -> V_160 += 5 * V_197 ;
F_107 ( V_2 , 5 * V_197 ) ;
} else {
F_97 ( & V_2 -> V_45 -> V_46 ,
L_48
L_49 , V_85 , ( V_85 -> V_160 / V_197 ) ,
V_85 -> V_131 ) ;
}
}
}
static void F_137 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
int V_38 ;
if ( F_135 ( & V_2 -> V_15 ) )
return;
V_85 = F_123 ( V_2 -> V_15 . V_165 , struct V_84 , V_182 ) ;
if ( V_85 -> V_134 != V_163 )
return;
if ( V_2 -> V_183 &&
! ( ! ( V_2 -> V_183 & ~ ( V_198 | V_199 ) )
&& F_100 ( V_148 , & V_85 -> V_122 ) ) ) {
V_85 -> V_143 = - V_53 ;
V_85 -> V_134 = V_179 ;
F_66 ( V_2 ) ;
return;
}
V_38 = V_2 -> V_40 -> V_184 ( V_85 ) ;
if ( V_38 == 0 )
F_107 ( V_2 , V_85 -> V_160 ) ;
else if ( V_38 == - V_154 ) {
F_66 ( V_2 ) ;
} else
F_107 ( V_2 , 50 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
int V_38 ;
if ( V_2 -> V_150 . V_157 ) {
if ( V_2 -> V_183 & ~ ( V_198 |
V_199 ) )
return;
V_38 = V_2 -> V_40 -> V_200 (
V_2 , V_2 -> V_150 . V_157 ) ;
if ( V_38 )
F_107 ( V_2 , 50 ) ;
else
V_2 -> V_150 . V_157 = 0 ;
}
}
int F_38 ( struct V_1 * V_2 )
{
struct V_84 * V_85 , * V_190 ;
int V_38 ;
struct V_88 V_201 ;
F_12 ( & V_201 ) ;
F_139 ( F_105 ( V_2 -> V_45 ) ) ;
V_38 = 0 ;
F_140 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_85 -> V_134 ) {
case V_135 :
V_38 = V_2 -> V_40 -> V_196 ( V_85 ) ;
if ( V_38 ) {
F_97 ( & V_2 -> V_45 -> V_46 ,
L_50
L_51 , V_85 ) ;
goto V_202;
}
break;
case V_163 :
V_85 -> V_104 = F_96 () ;
V_85 -> V_134 = V_179 ;
break;
default:
break;
}
F_128 ( & V_85 -> V_182 , & V_201 ) ;
}
V_202:
F_141 ( F_105 ( V_2 -> V_45 ) ) ;
F_140 (cqr, n, &flush_queue, devlist)
F_74 ( V_180 ,
( V_85 -> V_134 != V_136 ) ) ;
F_129 ( V_2 , & V_201 ) ;
return V_38 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_88 V_191 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_191 ) ;
F_139 ( F_105 ( V_2 -> V_45 ) ) ;
F_134 ( V_2 ) ;
F_127 ( V_2 , & V_191 ) ;
F_138 ( V_2 ) ;
F_141 ( F_105 ( V_2 -> V_45 ) ) ;
F_129 ( V_2 , & V_191 ) ;
F_139 ( F_105 ( V_2 -> V_45 ) ) ;
F_137 ( V_2 ) ;
F_141 ( F_105 ( V_2 -> V_45 ) ) ;
F_23 ( V_2 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( F_142 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_143 ( & V_2 -> V_13 ) ;
}
void F_144 ( struct V_1 * V_2 , int V_203 )
{
V_2 -> V_183 |= V_203 ;
}
void F_106 ( struct V_1 * V_2 , int V_203 )
{
V_2 -> V_183 &= ~ V_203 ;
if ( ! V_2 -> V_183 )
F_62 ( & V_204 ) ;
}
void F_145 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
unsigned long V_122 ;
V_2 = V_85 -> V_128 ;
F_85 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
V_85 -> V_134 = V_163 ;
F_146 ( & V_85 -> V_182 , & V_2 -> V_15 ) ;
F_66 ( V_2 ) ;
F_87 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
}
void F_147 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
unsigned long V_122 ;
V_2 = V_85 -> V_128 ;
F_85 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
V_85 -> V_134 = V_163 ;
F_148 ( & V_85 -> V_182 , & V_2 -> V_15 ) ;
F_66 ( V_2 ) ;
F_87 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
}
static void F_149 ( struct V_84 * V_85 , void * V_19 )
{
F_139 ( F_105 ( V_85 -> V_128 -> V_45 ) ) ;
V_85 -> V_192 = V_205 ;
F_141 ( F_105 ( V_85 -> V_128 -> V_45 ) ) ;
F_62 ( & V_204 ) ;
}
static inline int F_150 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_38 ;
V_2 = V_85 -> V_128 ;
F_139 ( F_105 ( V_2 -> V_45 ) ) ;
V_38 = ( V_85 -> V_192 == V_205 ) ;
F_141 ( F_105 ( V_2 -> V_45 ) ) ;
return V_38 ;
}
static int F_151 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
T_1 V_206 ;
if ( V_85 -> V_134 == V_207 )
return 0 ;
V_2 = V_85 -> V_128 ;
if ( F_100 ( V_121 , & V_85 -> V_122 ) ) {
if ( V_85 -> V_134 == V_195 ) {
V_2 -> V_40 -> V_208 ( V_85 ) ;
return 1 ;
}
if ( V_85 -> V_134 == V_194 ) {
V_206 = V_2 -> V_40 -> V_209 ( V_85 ) ;
V_206 ( V_85 ) ;
return 1 ;
}
if ( V_85 -> V_134 == V_210 )
F_152 ( V_85 , & V_85 -> V_164 ) ;
if ( V_85 -> V_211 ) {
F_153 ( V_2 , V_85 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_154 ( struct V_84 * V_85 )
{
if ( F_100 ( V_121 , & V_85 -> V_122 ) ) {
if ( V_85 -> V_211 )
return 1 ;
return ( ( V_85 -> V_134 != V_193 ) &&
( V_85 -> V_134 != V_210 ) ) ;
} else
return ( V_85 -> V_134 == V_207 ) ;
}
static int F_155 ( struct V_84 * V_212 , int V_213 )
{
struct V_1 * V_2 ;
int V_38 ;
struct V_88 V_15 ;
struct V_84 * V_85 ;
F_12 ( & V_15 ) ;
V_212 -> V_134 = V_207 ;
V_2 = V_212 -> V_128 ;
F_146 ( & V_212 -> V_214 , & V_15 ) ;
for ( V_85 = V_212 ; F_154 ( V_85 ) ;
V_85 = F_156 ( & V_15 ,
struct V_84 , V_214 ) ) {
if ( F_151 ( V_85 ) )
continue;
if ( V_85 -> V_134 != V_207 )
continue;
if ( F_100 ( V_144 , & V_2 -> V_122 ) &&
! F_100 ( V_145 , & V_85 -> V_122 ) ) {
V_85 -> V_134 = V_210 ;
V_85 -> V_143 = - V_76 ;
continue;
}
if ( V_2 -> V_183 & ~ V_159 &&
F_100 ( V_215 , & V_85 -> V_122 ) &&
( ! F_157 ( V_2 ) ) ) {
V_85 -> V_134 = V_210 ;
continue;
}
if ( V_213 ) {
V_38 = F_158 (
V_204 , ! ( V_2 -> V_183 ) ) ;
if ( V_38 == - V_216 ) {
V_85 -> V_134 = V_210 ;
V_212 -> V_143 = V_38 ;
continue;
}
} else
F_74 ( V_204 , ! ( V_2 -> V_183 ) ) ;
V_85 -> F_130 = F_149 ;
V_85 -> V_192 = V_217 ;
F_147 ( V_85 ) ;
if ( V_213 ) {
V_38 = F_158 (
V_204 , F_150 ( V_85 ) ) ;
if ( V_38 == - V_216 ) {
F_159 ( V_85 ) ;
F_74 ( V_204 ,
F_150 ( V_85 ) ) ;
V_85 -> V_134 = V_210 ;
V_212 -> V_143 = V_38 ;
continue;
}
} else
F_74 ( V_204 , F_150 ( V_85 ) ) ;
}
V_212 -> V_105 = F_96 () ;
if ( ( V_212 -> V_134 != V_193 ) &&
( V_212 -> V_143 != - V_216 ) )
F_152 ( V_212 , & V_212 -> V_164 ) ;
if ( V_212 -> V_134 == V_193 )
V_38 = 0 ;
else if ( V_212 -> V_143 )
V_38 = V_212 -> V_143 ;
else
V_38 = - V_141 ;
return V_38 ;
}
int F_160 ( struct V_84 * V_85 )
{
return F_155 ( V_85 , 0 ) ;
}
int F_161 ( struct V_84 * V_85 )
{
return F_155 ( V_85 , 1 ) ;
}
static inline int F_162 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
int V_38 ;
if ( F_135 ( & V_2 -> V_15 ) )
return 0 ;
V_85 = F_123 ( V_2 -> V_15 . V_165 , struct V_84 , V_182 ) ;
V_38 = V_2 -> V_40 -> V_196 ( V_85 ) ;
if ( ! V_38 )
V_85 -> V_131 ++ ;
return V_38 ;
}
int F_163 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_38 ;
V_2 = V_85 -> V_128 ;
if ( F_100 ( V_144 , & V_2 -> V_122 ) &&
! F_100 ( V_145 , & V_85 -> V_122 ) ) {
V_85 -> V_134 = V_210 ;
V_85 -> V_143 = - V_76 ;
return - V_141 ;
}
F_139 ( F_105 ( V_2 -> V_45 ) ) ;
V_38 = F_162 ( V_2 ) ;
if ( V_38 ) {
F_141 ( F_105 ( V_2 -> V_45 ) ) ;
return V_38 ;
}
V_85 -> F_130 = F_149 ;
V_85 -> V_192 = V_217 ;
V_85 -> V_134 = V_163 ;
F_146 ( & V_85 -> V_182 , & V_2 -> V_15 ) ;
F_66 ( V_2 ) ;
F_141 ( F_105 ( V_2 -> V_45 ) ) ;
F_74 ( V_204 , F_150 ( V_85 ) ) ;
if ( V_85 -> V_134 == V_193 )
V_38 = 0 ;
else if ( V_85 -> V_143 )
V_38 = V_85 -> V_143 ;
else
V_38 = - V_141 ;
return V_38 ;
}
int F_159 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_128 ;
unsigned long V_122 ;
int V_38 ;
V_38 = 0 ;
F_85 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
switch ( V_85 -> V_134 ) {
case V_163 :
V_85 -> V_134 = V_179 ;
break;
case V_135 :
V_38 = V_2 -> V_40 -> V_196 ( V_85 ) ;
if ( V_38 ) {
F_97 ( & V_2 -> V_45 -> V_46 ,
L_52 ,
V_85 , V_38 ) ;
} else {
V_85 -> V_104 = F_96 () ;
}
break;
default:
break;
}
F_87 ( F_105 ( V_2 -> V_45 ) , V_122 ) ;
F_66 ( V_2 ) ;
return V_38 ;
}
static void V_37 ( unsigned long V_158 )
{
unsigned long V_122 ;
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) V_158 ;
F_85 ( F_105 ( V_32 -> V_51 -> V_45 ) , V_122 ) ;
F_106 ( V_32 -> V_51 , V_159 ) ;
F_87 ( F_105 ( V_32 -> V_51 -> V_45 ) , V_122 ) ;
F_51 ( V_32 ) ;
}
void F_164 ( struct V_31 * V_32 , int V_160 )
{
if ( V_160 == 0 )
F_108 ( & V_32 -> V_16 ) ;
else
F_109 ( & V_32 -> V_16 , V_147 + V_160 ) ;
}
void F_37 ( struct V_31 * V_32 )
{
F_108 ( & V_32 -> V_16 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
T_1 V_206 ;
if ( V_85 -> V_134 == V_193 )
F_34 ( V_218 , V_2 , L_1 , L_53 ) ;
else
F_97 ( & V_2 -> V_45 -> V_46 , L_54 ) ;
V_206 = V_2 -> V_40 -> V_219 ( V_85 ) ;
V_206 ( V_85 ) ;
}
static void F_165 ( struct V_31 * V_32 )
{
struct V_220 * V_221 ;
struct V_86 * V_87 ;
struct V_84 * V_85 ;
struct V_1 * V_222 ;
unsigned long V_122 ;
V_221 = V_32 -> V_220 ;
V_222 = V_32 -> V_51 ;
if ( V_221 == NULL )
return;
if ( V_222 -> V_26 < V_58 ) {
while ( ( V_87 = F_166 ( V_32 -> V_220 ) ) )
F_167 ( V_87 , - V_141 ) ;
return;
}
while ( ( V_87 = F_168 ( V_221 ) ) ) {
if ( V_222 -> V_68 & V_223 &&
F_169 ( V_87 ) == V_224 ) {
F_34 ( V_140 , V_222 ,
L_55 ,
V_87 ) ;
F_170 ( V_87 ) ;
F_167 ( V_87 , - V_141 ) ;
continue;
}
V_85 = V_222 -> V_40 -> V_225 ( V_222 , V_32 , V_87 ) ;
if ( F_113 ( V_85 ) ) {
if ( F_119 ( V_85 ) == - V_142 )
break;
if ( F_119 ( V_85 ) == - V_4 )
break;
if ( F_119 ( V_85 ) == - V_53 ) {
if ( ! F_135 ( & V_32 -> V_15 ) )
break;
F_85 (
F_105 ( V_222 -> V_45 ) , V_122 ) ;
F_144 ( V_222 ,
V_159 ) ;
F_87 (
F_105 ( V_222 -> V_45 ) , V_122 ) ;
F_164 ( V_32 , V_197 / 2 ) ;
break;
}
F_34 ( V_140 , V_222 ,
L_56
L_57 ,
F_119 ( V_85 ) , V_87 ) ;
F_170 ( V_87 ) ;
F_167 ( V_87 , - V_141 ) ;
continue;
}
V_85 -> V_192 = ( void * ) V_87 ;
V_85 -> V_134 = V_207 ;
F_170 ( V_87 ) ;
F_148 ( & V_85 -> V_214 , & V_32 -> V_15 ) ;
F_75 ( V_32 , V_85 , V_87 ) ;
}
}
static void F_171 ( struct V_84 * V_85 )
{
struct V_86 * V_87 ;
int V_134 ;
int error = 0 ;
V_87 = (struct V_86 * ) V_85 -> V_192 ;
F_77 ( V_85 -> V_32 , V_85 , V_87 ) ;
V_134 = V_85 -> V_32 -> V_51 -> V_40 -> V_226 ( V_85 , V_87 ) ;
if ( V_134 <= 0 )
error = V_134 ? V_134 : - V_141 ;
F_167 ( V_87 , error ) ;
}
static void F_172 ( struct V_31 * V_32 ,
struct V_88 * V_191 )
{
struct V_88 * V_89 , * V_190 ;
struct V_84 * V_85 ;
T_1 V_206 ;
unsigned long V_122 ;
struct V_1 * V_51 = V_32 -> V_51 ;
V_227:
F_126 (l, n, &block->ccw_queue) {
V_85 = F_123 ( V_89 , struct V_84 , V_214 ) ;
if ( V_85 -> V_134 != V_193 &&
V_85 -> V_134 != V_210 &&
V_85 -> V_134 != V_194 &&
V_85 -> V_134 != V_195 )
continue;
if ( V_85 -> V_134 == V_195 ) {
V_51 -> V_40 -> V_208 ( V_85 ) ;
goto V_227;
}
if ( V_85 -> V_134 == V_194 ) {
V_206 = V_51 -> V_40 -> V_209 ( V_85 ) ;
if ( F_113 ( V_206 ( V_85 ) ) )
continue;
goto V_227;
}
if ( V_85 -> V_134 == V_210 ) {
F_152 ( V_85 , & V_85 -> V_164 ) ;
}
if ( F_157 ( V_51 ) &&
V_85 -> V_134 == V_210 ) {
F_173 ( V_51 , V_85 , V_228 ) ;
V_85 -> V_134 = V_207 ;
V_85 -> V_131 = 255 ;
F_85 ( F_105 ( V_51 -> V_45 ) , V_122 ) ;
F_144 ( V_51 , V_229 ) ;
F_87 ( F_105 ( V_51 -> V_45 ) ,
V_122 ) ;
goto V_227;
}
if ( V_85 -> V_211 ) {
F_153 ( V_51 , V_85 ) ;
goto V_227;
}
V_85 -> V_105 = F_96 () ;
F_128 ( & V_85 -> V_214 , V_191 ) ;
}
}
static void F_174 ( struct V_84 * V_85 , void * V_19 )
{
F_51 ( V_85 -> V_32 ) ;
}
static void F_175 ( struct V_31 * V_32 )
{
struct V_84 * V_85 ;
if ( F_135 ( & V_32 -> V_15 ) )
return;
F_176 (cqr, &block->ccw_queue, blocklist) {
if ( V_85 -> V_134 != V_207 )
continue;
if ( F_100 ( V_144 , & V_32 -> V_51 -> V_122 ) &&
! F_100 ( V_145 , & V_85 -> V_122 ) ) {
V_85 -> V_134 = V_210 ;
V_85 -> V_143 = - V_76 ;
F_51 ( V_32 ) ;
continue;
}
if ( V_32 -> V_51 -> V_183 & ~ V_159 &&
F_100 ( V_215 , & V_85 -> V_122 ) &&
( ! F_157 ( V_32 -> V_51 ) ) ) {
V_85 -> V_134 = V_210 ;
F_51 ( V_32 ) ;
continue;
}
if ( V_32 -> V_51 -> V_183 )
return;
if ( ! V_85 -> V_128 )
V_85 -> V_128 = V_32 -> V_51 ;
V_85 -> F_130 = F_174 ;
F_147 ( V_85 ) ;
}
}
static void V_35 ( struct V_31 * V_32 )
{
struct V_88 V_191 ;
struct V_88 * V_89 , * V_190 ;
struct V_84 * V_85 ;
F_10 ( & V_32 -> V_12 , 0 ) ;
F_12 ( & V_191 ) ;
F_177 ( & V_32 -> V_36 ) ;
F_172 ( V_32 , & V_191 ) ;
F_178 ( & V_32 -> V_36 ) ;
F_139 ( & V_32 -> V_34 ) ;
F_126 (l, n, &final_queue) {
V_85 = F_123 ( V_89 , struct V_84 , V_214 ) ;
F_131 ( & V_85 -> V_214 ) ;
F_171 ( V_85 ) ;
}
F_177 ( & V_32 -> V_36 ) ;
F_165 ( V_32 ) ;
F_175 ( V_32 ) ;
F_178 ( & V_32 -> V_36 ) ;
F_141 ( & V_32 -> V_34 ) ;
F_23 ( V_32 -> V_51 ) ;
}
static void F_179 ( struct V_84 * V_85 , void * V_19 )
{
F_62 ( & V_180 ) ;
}
static int F_46 ( struct V_31 * V_32 )
{
struct V_84 * V_85 , * V_190 ;
int V_38 , V_230 ;
struct V_88 V_201 ;
F_12 ( & V_201 ) ;
F_132 ( & V_32 -> V_36 ) ;
V_38 = 0 ;
V_227:
F_140 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_85 -> V_134 >= V_163 )
V_38 = F_159 ( V_85 ) ;
if ( V_38 < 0 )
break;
V_85 -> F_130 = F_179 ;
for ( V_230 = 0 ; V_85 != NULL ; V_85 = V_85 -> V_211 , V_230 ++ )
F_128 ( & V_85 -> V_214 , & V_201 ) ;
if ( V_230 > 1 )
goto V_227;
}
F_133 ( & V_32 -> V_36 ) ;
V_231:
F_140 (cqr, n, &flush_queue, blocklist) {
F_74 ( V_180 , ( V_85 -> V_134 < V_163 ) ) ;
if ( V_85 -> V_211 ) {
F_132 ( & V_32 -> V_36 ) ;
F_153 ( V_32 -> V_51 , V_85 ) ;
F_133 ( & V_32 -> V_36 ) ;
goto V_231;
}
F_139 ( & V_32 -> V_34 ) ;
V_85 -> V_105 = F_96 () ;
F_131 ( & V_85 -> V_214 ) ;
F_171 ( V_85 ) ;
F_141 ( & V_32 -> V_34 ) ;
}
return V_38 ;
}
void F_51 ( struct V_31 * V_32 )
{
if ( F_142 ( & V_32 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_32 -> V_51 ) ;
F_143 ( & V_32 -> V_13 ) ;
}
static void F_180 ( struct V_220 * V_221 )
{
struct V_31 * V_32 ;
V_32 = V_221 -> V_232 ;
F_177 ( & V_32 -> V_36 ) ;
F_165 ( V_32 ) ;
F_175 ( V_32 ) ;
F_178 ( & V_32 -> V_36 ) ;
}
static int F_22 ( struct V_31 * V_32 )
{
int V_38 ;
V_32 -> V_220 = F_181 ( F_180 ,
& V_32 -> V_34 ) ;
if ( V_32 -> V_220 == NULL )
return - V_4 ;
V_32 -> V_220 -> V_232 = V_32 ;
F_182 ( V_32 -> V_220 -> V_233 ) ;
V_32 -> V_220 -> V_233 = NULL ;
V_38 = F_183 ( V_32 -> V_220 , L_58 ) ;
if ( V_38 ) {
F_184 ( V_32 -> V_220 ) ;
return V_38 ;
}
return 0 ;
}
static void F_42 ( struct V_31 * V_32 )
{
int V_234 ;
if ( V_32 -> V_51 -> V_68 & V_69 ) {
V_234 = 2048 ;
} else {
V_234 = V_32 -> V_51 -> V_40 -> V_235 << V_32 -> V_57 ;
}
F_185 ( V_32 -> V_220 ,
V_32 -> V_59 ) ;
F_186 ( V_32 -> V_220 , V_234 ) ;
F_187 ( V_32 -> V_220 , - 1L ) ;
F_188 ( V_32 -> V_220 , V_9 ) ;
F_189 ( V_32 -> V_220 , V_9 - 1 ) ;
}
static void F_27 ( struct V_31 * V_32 )
{
if ( V_32 -> V_220 ) {
F_184 ( V_32 -> V_220 ) ;
V_32 -> V_220 = NULL ;
}
}
static void F_47 ( struct V_31 * V_32 )
{
struct V_86 * V_87 ;
if ( ! V_32 -> V_220 )
return;
F_139 ( & V_32 -> V_34 ) ;
while ( ( V_87 = F_166 ( V_32 -> V_220 ) ) )
F_167 ( V_87 , - V_141 ) ;
F_141 ( & V_32 -> V_34 ) ;
}
static int F_190 ( struct V_236 * V_72 , T_2 V_237 )
{
struct V_1 * V_51 ;
int V_38 ;
V_51 = F_191 ( V_72 -> V_73 ) ;
if ( ! V_51 )
return - V_139 ;
F_192 ( & V_51 -> V_32 -> V_33 ) ;
if ( F_100 ( V_187 , & V_51 -> V_122 ) ) {
V_38 = - V_139 ;
goto V_238;
}
if ( ! F_193 ( V_51 -> V_40 -> V_42 ) ) {
V_38 = - V_127 ;
goto V_238;
}
if ( V_83 ) {
F_194 ( & V_51 -> V_45 -> V_46 ,
L_59
L_60 ) ;
V_38 = - V_76 ;
goto V_186;
}
if ( V_51 -> V_26 <= V_50 ) {
F_34 ( V_140 , V_51 , L_61 ,
L_62 ) ;
V_38 = - V_139 ;
goto V_186;
}
if ( ( V_237 & V_239 ) &&
( F_100 ( V_240 , & V_51 -> V_122 ) ||
( V_51 -> V_68 & V_223 ) ) ) {
V_38 = - V_241 ;
goto V_186;
}
F_23 ( V_51 ) ;
return 0 ;
V_186:
F_26 ( V_51 -> V_40 -> V_42 ) ;
V_238:
F_195 ( & V_51 -> V_32 -> V_33 ) ;
F_23 ( V_51 ) ;
return V_38 ;
}
static int F_196 ( struct V_60 * V_61 , T_2 V_237 )
{
struct V_1 * V_51 ;
V_51 = F_191 ( V_61 ) ;
if ( ! V_51 )
return - V_139 ;
F_195 ( & V_51 -> V_32 -> V_33 ) ;
F_26 ( V_51 -> V_40 -> V_42 ) ;
F_23 ( V_51 ) ;
return 0 ;
}
static int F_197 ( struct V_236 * V_72 , struct V_242 * V_243 )
{
struct V_1 * V_51 ;
V_51 = F_191 ( V_72 -> V_73 ) ;
if ( ! V_51 )
return - V_139 ;
if ( ! V_51 -> V_40 ||
! V_51 -> V_40 -> V_244 ) {
F_23 ( V_51 ) ;
return - V_127 ;
}
V_51 -> V_40 -> V_244 ( V_51 -> V_32 , V_243 ) ;
V_243 -> V_245 = F_198 ( V_72 ) >> V_51 -> V_32 -> V_57 ;
F_23 ( V_51 ) ;
return 0 ;
}
static void
F_199 ( void )
{
#ifdef F_200
F_201 () ;
#endif
F_202 () ;
if ( V_246 != NULL ) {
F_203 ( V_246 ) ;
V_246 = NULL ;
}
F_204 () ;
F_205 () ;
if ( V_247 != NULL ) {
F_40 ( V_247 ) ;
V_247 = NULL ;
}
}
int F_206 ( struct V_1 * V_2 )
{
struct V_248 V_249 ;
struct V_250 V_251 ;
int V_38 ;
if ( ! V_252 )
return 0 ;
F_207 ( V_2 -> V_45 , & V_249 ) ;
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
V_251 . V_253 = V_249 . V_254 ;
V_251 . V_255 = sizeof( V_251 ) ;
V_38 = V_250 ( & V_251 ) ;
if ( V_38 == 0 || V_38 == 2 ) {
return V_251 . V_256 & 0x80 ;
} else {
F_208 ( V_48 , L_63 ,
V_249 . V_254 , V_38 ) ;
return 0 ;
}
}
static void F_209 ( void * V_19 , T_3 V_257 )
{
struct V_161 * V_45 = V_19 ;
int V_258 ;
V_258 = F_210 ( V_45 ) ;
if ( V_258 )
F_211 ( L_64 ,
F_31 ( & V_45 -> V_46 ) , V_258 ) ;
}
int F_212 ( struct V_161 * V_45 ,
struct V_259 * V_40 )
{
int V_258 ;
V_258 = F_213 ( V_45 ) ;
if ( V_258 ) {
F_111 ( V_48 , V_45 , L_1 ,
L_65
L_66 ) ;
return V_258 ;
}
V_45 -> V_260 = & F_116 ;
if ( ( F_214 ( V_45 , V_261 ) > 0 ) ||
( V_262 && F_215 ( F_31 ( & V_45 -> V_46 ) ) != 0 ) )
F_216 ( F_209 , V_45 ) ;
return 0 ;
}
void F_217 ( struct V_161 * V_45 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
V_45 -> V_260 = NULL ;
F_218 ( V_45 ) ;
V_2 = F_219 ( V_45 ) ;
if ( F_113 ( V_2 ) )
return;
if ( F_220 ( V_187 , & V_2 -> V_122 ) ) {
F_23 ( V_2 ) ;
return;
}
F_71 ( V_2 , V_27 ) ;
V_32 = V_2 -> V_32 ;
F_221 ( V_2 ) ;
if ( V_32 )
F_19 ( V_32 ) ;
}
int F_222 ( struct V_161 * V_45 ,
struct V_259 * V_43 )
{
struct V_259 * V_40 ;
struct V_1 * V_2 ;
int V_38 ;
F_223 ( V_45 , V_261 , 0 ) ;
V_2 = F_224 ( V_45 ) ;
if ( F_113 ( V_2 ) )
return F_119 ( V_2 ) ;
V_40 = V_43 ;
if ( V_2 -> V_68 & V_263 ) {
if ( ! V_173 ) {
F_211 ( L_67
L_68 ,
F_31 ( & V_45 -> V_46 ) ) ;
F_221 ( V_2 ) ;
return - V_139 ;
}
V_40 = V_173 ;
}
if ( ! F_193 ( V_43 -> V_42 ) ) {
F_221 ( V_2 ) ;
return - V_127 ;
}
if ( ! F_193 ( V_40 -> V_42 ) ) {
F_26 ( V_43 -> V_42 ) ;
F_221 ( V_2 ) ;
return - V_127 ;
}
V_2 -> V_43 = V_43 ;
V_2 -> V_40 = V_40 ;
V_38 = V_40 -> V_264 ( V_2 ) ;
if ( V_38 ) {
F_211 ( L_69
L_70 ,
F_31 ( & V_45 -> V_46 ) , V_40 -> V_130 , V_38 ) ;
F_26 ( V_40 -> V_42 ) ;
F_26 ( V_43 -> V_42 ) ;
F_221 ( V_2 ) ;
return V_38 ;
}
F_71 ( V_2 , V_67 ) ;
if ( V_2 -> V_26 <= V_39 ) {
F_211 ( L_71
L_72 , F_31 ( & V_45 -> V_46 ) ) ;
V_38 = - V_139 ;
F_71 ( V_2 , V_27 ) ;
if ( V_2 -> V_32 )
F_19 ( V_2 -> V_32 ) ;
F_221 ( V_2 ) ;
} else
F_225 ( L_73 ,
F_31 ( & V_45 -> V_46 ) ) ;
F_74 ( V_77 , F_72 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_38 ;
}
int F_226 ( struct V_161 * V_45 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_265 , V_33 ;
V_2 = F_219 ( V_45 ) ;
if ( F_113 ( V_2 ) )
return F_119 ( V_2 ) ;
if ( F_220 ( V_187 , & V_2 -> V_122 ) ) {
F_23 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_32 ) {
V_265 = V_2 -> V_32 -> V_72 ? 0 : - 1 ;
V_33 = F_227 ( & V_2 -> V_32 -> V_33 ) ;
if ( V_33 > V_265 ) {
if ( V_33 > 0 )
F_211 ( L_74
L_75 ,
F_31 ( & V_45 -> V_46 ) , V_33 ) ;
else
F_211 ( L_74
L_76 ,
F_31 ( & V_45 -> V_46 ) ) ;
F_228 ( V_187 , & V_2 -> V_122 ) ;
F_23 ( V_2 ) ;
return - V_142 ;
}
}
F_71 ( V_2 , V_27 ) ;
V_32 = V_2 -> V_32 ;
F_221 ( V_2 ) ;
if ( V_32 )
F_19 ( V_32 ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
F_229 ( & V_2 -> V_45 -> V_46 , L_77
L_78 ) ;
F_34 ( V_48 , V_2 , L_1 , L_79 ) ;
F_173 ( V_2 , NULL , V_266 ) ;
if ( V_2 -> V_26 < V_50 )
return 0 ;
F_176 (cqr, &device->ccw_queue, devlist)
if ( ( V_85 -> V_134 == V_135 ) ||
( V_85 -> V_134 == V_136 ) ) {
V_85 -> V_134 = V_163 ;
V_85 -> V_131 ++ ;
}
F_144 ( V_2 , V_198 ) ;
F_39 ( V_2 ) ;
F_66 ( V_2 ) ;
return 1 ;
}
int F_230 ( struct V_1 * V_2 )
{
F_194 ( & V_2 -> V_45 -> V_46 , L_80
L_81 ) ;
F_34 ( V_48 , V_2 , L_1 , L_82 ) ;
F_106 ( V_2 , V_198 ) ;
if ( V_2 -> V_183 & V_199 ) {
F_106 ( V_2 , V_199 ) ;
F_70 ( V_2 ) ;
return 1 ;
}
F_66 ( V_2 ) ;
if ( V_2 -> V_32 )
F_51 ( V_2 -> V_32 ) ;
return 1 ;
}
int F_231 ( struct V_161 * V_45 , int V_267 )
{
struct V_1 * V_2 ;
int V_258 ;
V_2 = F_112 ( V_45 ) ;
if ( F_113 ( V_2 ) )
return 0 ;
V_258 = 0 ;
switch ( V_267 ) {
case V_268 :
case V_269 :
case V_270 :
V_2 -> V_150 . V_151 = 0 ;
V_2 -> V_150 . V_155 = 0 ;
V_2 -> V_150 . V_156 = 0 ;
V_258 = F_103 ( V_2 ) ;
break;
case V_271 :
V_258 = 1 ;
if ( V_2 -> V_150 . V_151 )
V_258 = F_230 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_258 ;
}
void F_232 ( struct V_161 * V_45 , int * V_272 )
{
int V_273 ;
T_4 V_274 , V_275 ;
struct V_1 * V_2 ;
V_2 = F_112 ( V_45 ) ;
if ( F_113 ( V_2 ) )
return;
for ( V_273 = 0 ; V_273 < 8 ; V_273 ++ ) {
V_275 = 0x80 >> V_273 ;
if ( V_272 [ V_273 ] & V_276 ) {
V_274 = V_2 -> V_150 . V_151 ;
V_2 -> V_150 . V_151 &= ~ V_275 ;
V_2 -> V_150 . V_155 &= ~ V_275 ;
V_2 -> V_150 . V_156 &= ~ V_275 ;
if ( V_274 && ! V_2 -> V_150 . V_151 )
F_103 ( V_2 ) ;
}
if ( V_272 [ V_273 ] & V_277 ) {
V_2 -> V_150 . V_151 &= ~ V_275 ;
V_2 -> V_150 . V_155 &= ~ V_275 ;
V_2 -> V_150 . V_156 &= ~ V_275 ;
V_2 -> V_150 . V_157 |= V_275 ;
F_66 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
int F_233 ( struct V_1 * V_2 , T_4 V_149 )
{
if ( ! V_2 -> V_150 . V_151 && V_149 ) {
V_2 -> V_150 . V_151 = V_149 ;
F_230 ( V_2 ) ;
} else
V_2 -> V_150 . V_151 |= V_149 ;
return 0 ;
}
int F_234 ( struct V_161 * V_45 )
{
struct V_84 * V_85 , * V_190 ;
int V_38 ;
struct V_88 V_278 ;
struct V_1 * V_2 = F_219 ( V_45 ) ;
if ( F_113 ( V_2 ) )
return F_119 ( V_2 ) ;
if ( V_2 -> V_40 -> V_279 )
V_38 = V_2 -> V_40 -> V_279 ( V_2 ) ;
F_144 ( V_2 , V_280 ) ;
F_12 ( & V_278 ) ;
F_139 ( F_105 ( V_45 ) ) ;
V_38 = 0 ;
F_140 (cqr, n, &device->ccw_queue, devlist) {
if ( V_85 -> V_134 == V_135 ) {
V_38 = V_2 -> V_40 -> V_196 ( V_85 ) ;
if ( V_38 ) {
F_97 ( & V_2 -> V_45 -> V_46 ,
L_83
L_84 , V_85 ) ;
F_141 ( F_105 ( V_45 ) ) ;
F_23 ( V_2 ) ;
return V_38 ;
}
}
F_128 ( & V_85 -> V_182 , & V_278 ) ;
}
F_141 ( F_105 ( V_45 ) ) ;
F_140 (cqr, n, &freeze_queue, devlist) {
F_74 ( V_180 ,
( V_85 -> V_134 != V_136 ) ) ;
if ( V_85 -> V_134 == V_179 )
V_85 -> V_134 = V_163 ;
}
F_139 ( F_105 ( V_45 ) ) ;
F_235 ( & V_278 , & V_2 -> V_15 ) ;
F_141 ( F_105 ( V_45 ) ) ;
F_23 ( V_2 ) ;
return V_38 ;
}
int F_236 ( struct V_161 * V_45 )
{
struct V_1 * V_2 = F_219 ( V_45 ) ;
int V_38 = 0 ;
if ( F_113 ( V_2 ) )
return F_119 ( V_2 ) ;
F_106 ( V_2 ,
( V_280 | V_199 ) ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_40 -> V_82 && ! ( V_2 -> V_183 ) )
V_38 = V_2 -> V_40 -> V_82 ( V_2 ) ;
if ( V_38 || V_2 -> V_183 )
V_2 -> V_183 |= V_199 ;
if ( V_2 -> V_32 )
F_51 ( V_2 -> V_32 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_84 * F_237 ( struct V_1 * V_2 ,
void * V_281 ,
int V_282 ,
int V_116 )
{
struct V_84 * V_85 ;
struct V_119 * V_124 ;
unsigned long * V_283 ;
V_85 = F_84 ( V_116 , 1 , V_282 , V_2 ) ;
if ( F_113 ( V_85 ) ) {
F_97 ( & V_2 -> V_45 -> V_46 ,
L_30
L_31 , L_85 ) ;
return V_85 ;
}
V_124 = V_85 -> V_120 ;
V_124 -> V_284 = V_285 ;
if ( F_238 ( V_281 , V_282 ) ) {
V_283 = ( unsigned long * ) ( V_85 -> V_19 ) ;
V_124 -> V_286 = ( V_287 ) ( V_288 ) V_283 ;
V_124 -> V_122 = V_289 ;
V_283 = F_239 ( V_283 , V_281 , V_282 ) ;
} else {
V_124 -> V_286 = ( V_287 ) ( V_288 ) V_281 ;
V_124 -> V_122 = 0 ;
}
V_124 -> V_290 = V_282 ;
V_85 -> V_128 = V_2 ;
V_85 -> V_291 = V_2 ;
V_85 -> V_160 = 10 * V_197 ;
V_85 -> V_131 = 256 ;
V_85 -> V_102 = F_96 () ;
V_85 -> V_134 = V_207 ;
return V_85 ;
}
int F_240 ( struct V_1 * V_2 , int V_116 ,
void * V_281 , int V_282 )
{
int V_258 ;
struct V_84 * V_85 ;
V_85 = F_237 ( V_2 , V_281 , V_282 ,
V_116 ) ;
if ( F_113 ( V_85 ) )
return F_119 ( V_85 ) ;
V_258 = F_160 ( V_85 ) ;
F_91 ( V_85 , V_85 -> V_291 ) ;
return V_258 ;
}
char * F_241 ( struct V_164 * V_164 )
{
struct V_292 * V_292 = NULL ;
char * V_293 = NULL ;
if ( F_242 ( & V_164 -> V_170 ) && ( V_164 -> V_170 . V_294 . V_295 == 0x01 ) ) {
if ( V_164 -> V_170 . V_294 . V_296 )
V_292 = F_243 ( (struct V_296 * ) ( unsigned long )
V_164 -> V_170 . V_294 . V_296 ) ;
if ( V_292 && V_292 -> V_297 == 64 && V_292 -> V_122 )
switch ( V_292 -> V_122 & 0x07 ) {
case 1 :
V_293 = V_292 -> V_298 . V_299 . V_293 ;
break;
case 2 :
V_293 = V_292 -> V_298 . V_300 . V_293 ;
break;
default:
break;
}
} else if ( V_164 -> V_301 . V_302 . V_303 . V_304 ) {
V_293 = V_164 -> V_305 ;
}
return V_293 ;
}
static int T_5 F_244 ( void )
{
int V_38 ;
F_245 ( & V_77 ) ;
F_245 ( & V_180 ) ;
F_245 ( & V_204 ) ;
V_247 = F_30 ( L_86 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_247 == NULL ) {
V_38 = - V_4 ;
goto V_306;
}
F_32 ( V_247 , & V_47 ) ;
F_33 ( V_247 , V_48 ) ;
F_208 ( V_49 , L_1 , L_2 ) ;
V_173 = NULL ;
V_38 = F_246 () ;
if ( V_38 )
goto V_306;
V_38 = F_247 () ;
if ( V_38 )
goto V_306;
V_38 = F_248 () ;
if ( V_38 )
goto V_306;
V_38 = F_249 () ;
if ( V_38 )
goto V_306;
#ifdef F_200
V_38 = F_250 () ;
if ( V_38 )
goto V_306;
#endif
return 0 ;
V_306:
F_251 ( L_87 ) ;
F_199 () ;
return V_38 ;
}
