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
F_9 ( & V_2 -> V_30 . V_31 ) ;
return V_2 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_32 ) ;
F_17 ( ( unsigned long ) V_2 -> V_7 ) ;
F_7 ( ( unsigned long ) V_2 -> V_5 , 1 ) ;
F_5 ( V_2 ) ;
}
struct V_33 * F_18 ( void )
{
struct V_33 * V_34 ;
V_34 = F_2 ( sizeof( * V_34 ) , V_3 ) ;
if ( ! V_34 )
return F_3 ( - V_4 ) ;
F_10 ( & V_34 -> V_35 , - 1 ) ;
F_9 ( & V_34 -> V_36 ) ;
F_10 ( & V_34 -> V_12 , 0 ) ;
F_11 ( & V_34 -> V_13 ,
( void (*) ( unsigned long ) ) V_37 ,
( unsigned long ) V_34 ) ;
F_12 ( & V_34 -> V_15 ) ;
F_9 ( & V_34 -> V_38 ) ;
F_13 ( & V_34 -> V_16 ) ;
V_34 -> V_16 . V_17 = V_39 ;
V_34 -> V_16 . V_19 = ( unsigned long ) V_34 ;
F_9 ( & V_34 -> V_30 . V_31 ) ;
return V_34 ;
}
void F_19 ( struct V_33 * V_34 )
{
F_5 ( V_34 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_40 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_40 = F_22 ( V_2 -> V_34 ) ;
if ( V_40 ) {
F_23 ( V_2 ) ;
return V_40 ;
}
}
V_2 -> V_26 = V_41 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
if ( V_2 -> V_42 ) {
if ( V_2 -> V_42 -> V_43 )
V_2 -> V_42 -> V_43 ( V_2 ) ;
F_26 ( V_2 -> V_42 -> V_44 ) ;
}
V_2 -> V_42 = NULL ;
if ( V_2 -> V_45 )
F_26 ( V_2 -> V_45 -> V_44 ) ;
V_2 -> V_45 = NULL ;
V_2 -> V_26 = V_27 ;
if ( V_2 -> V_34 )
F_27 ( V_2 -> V_34 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_46 * F_28 ( const char * V_47 ,
struct V_46 * V_48 )
{
struct V_46 * V_49 ;
if ( ! V_48 )
return NULL ;
V_49 = F_29 ( V_47 , V_48 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
return NULL ;
return V_49 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
int V_40 ;
if ( V_34 ) {
V_40 = F_32 ( V_34 ) ;
if ( V_40 )
return V_40 ;
V_34 -> V_50 =
F_28 ( V_34 -> V_51 -> V_52 ,
V_53 ) ;
F_33 ( & V_34 -> V_30 , V_34 -> V_50 ) ;
if ( V_54 == V_55 )
F_34 ( & V_2 -> V_34 -> V_30 ) ;
}
V_2 -> V_50 =
F_28 ( F_35 ( & V_2 -> V_56 -> V_57 ) ,
V_53 ) ;
F_33 ( & V_2 -> V_30 , V_2 -> V_50 ) ;
V_2 -> V_58 = F_36 ( F_35 ( & V_2 -> V_56 -> V_57 ) , 4 , 1 ,
8 * sizeof( long ) ) ;
F_37 ( V_2 -> V_58 , & V_59 ) ;
F_38 ( V_2 -> V_58 , V_60 ) ;
F_39 ( V_61 , V_2 , L_1 , L_2 ) ;
V_2 -> V_26 = V_62 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_34 ) {
F_41 ( & V_2 -> V_34 -> V_30 ) ;
if ( V_2 -> V_34 -> V_50 )
F_42 ( V_2 -> V_34 -> V_50 ) ;
F_43 ( V_2 -> V_34 ) ;
F_44 ( V_2 -> V_34 ) ;
}
V_40 = F_45 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_46 ( V_2 ) ;
F_41 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_50 )
F_42 ( V_2 -> V_50 ) ;
F_39 ( V_61 , V_2 , L_3 , V_2 ) ;
if ( V_2 -> V_58 != NULL ) {
F_47 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
}
V_2 -> V_26 = V_41 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_33 * V_34 ;
V_40 = 0 ;
V_34 = V_2 -> V_34 ;
if ( V_34 ) {
if ( V_34 -> V_63 -> V_42 -> V_64 != NULL )
V_40 = V_34 -> V_63 -> V_42 -> V_64 ( V_34 ) ;
if ( V_40 ) {
if ( V_40 != - V_65 )
V_2 -> V_26 = V_66 ;
return V_40 ;
}
F_49 ( V_34 ) ;
F_50 ( V_34 -> V_51 ,
V_34 -> V_67 << V_34 -> V_68 ) ;
V_2 -> V_26 = V_69 ;
V_40 = F_51 ( V_34 ) ;
if ( V_40 )
V_2 -> V_26 = V_62 ;
} else {
V_2 -> V_26 = V_69 ;
}
return V_40 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_40 ;
V_2 -> V_26 = V_62 ;
if ( V_2 -> V_34 ) {
struct V_33 * V_34 = V_2 -> V_34 ;
V_40 = F_53 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_69 ;
return V_40 ;
}
F_54 ( V_34 ) ;
F_55 ( V_34 ) ;
V_34 -> V_67 = 0 ;
V_34 -> V_70 = 0 ;
V_34 -> V_68 = 0 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
V_2 -> V_26 = V_62 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_71 * V_72 ;
struct V_73 V_74 ;
struct V_75 * V_76 ;
if ( V_2 -> V_42 -> V_77 ) {
V_40 = V_2 -> V_42 -> V_77 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
V_2 -> V_26 = V_78 ;
if ( V_2 -> V_34 ) {
F_58 ( V_2 -> V_34 ) ;
if ( ( V_2 -> V_79 & V_80 ) ) {
V_72 = V_2 -> V_34 -> V_51 ;
F_59 ( & F_60 ( V_72 ) -> V_81 , V_82 ) ;
return 0 ;
}
V_72 = V_2 -> V_34 -> V_83 -> V_84 ;
F_61 ( & V_74 , V_72 , V_85 ) ;
while ( ( V_76 = F_62 ( & V_74 ) ) )
F_59 ( & F_63 ( V_76 ) -> V_81 , V_82 ) ;
F_64 ( & V_74 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_71 * V_72 ;
struct V_73 V_74 ;
struct V_75 * V_76 ;
if ( V_2 -> V_42 -> V_86 ) {
V_40 = V_2 -> V_42 -> V_86 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
V_2 -> V_26 = V_69 ;
if ( V_2 -> V_34 && ! ( V_2 -> V_79 & V_80 ) ) {
V_72 = V_2 -> V_34 -> V_83 -> V_84 ;
F_61 ( & V_74 , V_72 , V_85 ) ;
while ( ( V_76 = F_62 ( & V_74 ) ) )
F_59 ( & F_63 ( V_76 ) -> V_81 , V_82 ) ;
F_64 ( & V_74 ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_27 &&
V_2 -> V_28 >= V_41 )
V_40 = F_20 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_41 &&
V_2 -> V_28 >= V_62 )
V_40 = F_31 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_62 &&
V_2 -> V_28 >= V_69 )
V_40 = F_48 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_66 &&
V_2 -> V_28 > V_66 )
V_40 = - V_87 ;
if ( ! V_40 &&
V_2 -> V_26 == V_69 &&
V_2 -> V_28 >= V_78 )
V_40 = F_57 ( V_2 ) ;
return V_40 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_78 &&
V_2 -> V_28 <= V_69 )
V_40 = F_65 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_69 &&
V_2 -> V_28 <= V_62 )
V_40 = F_52 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_66 &&
V_2 -> V_28 <= V_62 )
V_40 = F_56 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_62 &&
V_2 -> V_28 <= V_41 )
V_40 = F_40 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_41 &&
V_2 -> V_28 <= V_27 )
V_40 = F_24 ( V_2 ) ;
return V_40 ;
}
static void F_68 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_26 == V_2 -> V_28 )
return;
if ( V_2 -> V_26 < V_2 -> V_28 )
V_40 = F_66 ( V_2 ) ;
else
V_40 = F_67 ( V_2 ) ;
if ( V_40 == - V_65 )
return;
if ( V_40 )
V_2 -> V_28 = V_2 -> V_26 ;
if ( V_2 -> V_26 == V_2 -> V_28 )
F_69 ( & V_88 ) ;
F_59 ( & V_2 -> V_56 -> V_57 . V_81 , V_82 ) ;
}
static void V_21 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_70 ( V_90 , struct V_1 , V_20 ) ;
F_71 ( & V_2 -> V_29 ) ;
F_68 ( V_2 ) ;
F_72 ( & V_2 -> V_29 ) ;
F_73 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_75 ( & V_2 -> V_20 ) ;
}
static void V_25 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_70 ( V_90 , struct V_1 ,
V_24 ) ;
V_2 -> V_42 -> V_91 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_75 ( & V_2 -> V_24 ) ;
}
static void V_23 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_70 ( V_90 , struct V_1 ,
V_22 ) ;
V_2 -> V_56 -> V_92 -> V_93 ( V_2 -> V_56 ) ;
F_23 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_75 ( & V_2 -> V_22 ) ;
}
void F_78 ( struct V_1 * V_2 , int V_28 )
{
F_21 ( V_2 ) ;
F_71 ( & V_2 -> V_29 ) ;
if ( V_94 && V_28 > V_69 )
V_28 = V_69 ;
if ( V_2 -> V_28 != V_28 ) {
if ( V_2 -> V_26 == V_28 )
F_69 ( & V_88 ) ;
V_2 -> V_28 = V_28 ;
}
if ( V_2 -> V_26 != V_2 -> V_28 )
F_68 ( V_2 ) ;
F_72 ( & V_2 -> V_29 ) ;
F_23 ( V_2 ) ;
}
static inline int F_79 ( struct V_1 * V_2 )
{
return ( V_2 -> V_26 == V_2 -> V_28 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
F_78 ( V_2 , V_78 ) ;
if ( V_2 -> V_26 <= V_41 )
F_78 ( V_2 , V_27 ) ;
F_81 ( V_88 , F_79 ( V_2 ) ) ;
}
static void F_82 ( struct V_33 * V_34 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 ;
unsigned int V_101 ;
struct V_1 * V_2 ;
V_101 = 0 ;
if ( V_54 || V_34 -> V_30 . V_19 )
F_83 (l, &block->ccw_queue)
if ( ++ V_101 >= 31 )
break;
if ( V_54 ) {
V_102 . V_103 [ V_101 ] ++ ;
if ( F_84 ( V_98 ) == V_104 )
V_102 . V_105 [ V_101 ] ++ ;
}
F_85 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
V_34 -> V_30 . V_19 -> V_103 [ V_101 ] ++ ;
if ( F_84 ( V_98 ) == V_104 )
V_34 -> V_30 . V_19 -> V_105 [ V_101 ] ++ ;
F_86 ( & V_34 -> V_30 . V_31 ) ;
V_2 = V_96 -> V_106 ;
if ( V_2 -> V_30 . V_19 ) {
V_101 = 1 ;
F_83 (l, &device->ccw_queue)
if ( ++ V_101 >= 31 )
break;
}
F_85 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 ) {
V_2 -> V_30 . V_19 -> V_103 [ V_101 ] ++ ;
if ( F_84 ( V_98 ) == V_104 )
V_2 -> V_30 . V_19 -> V_105 [ V_101 ] ++ ;
}
F_86 ( & V_2 -> V_30 . V_31 ) ;
}
static void F_87 ( struct V_107 * V_19 ,
int V_108 ,
int V_109 ,
int V_110 ,
long V_111 ,
int V_112 ,
int V_113 ,
int V_114 ,
int V_115 ,
int V_116 ,
int V_117 ,
int V_118 )
{
if ( V_19 -> V_119 == V_120 ) {
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_88 ( & V_19 -> V_121 ) ;
}
V_19 -> V_119 ++ ;
V_19 -> V_122 += V_111 ;
if ( V_108 )
V_19 -> V_123 ++ ;
if ( V_109 )
V_19 -> V_124 ++ ;
V_19 -> V_125 [ V_112 ] ++ ;
V_19 -> V_126 [ V_113 ] ++ ;
V_19 -> V_127 [ V_114 ] ++ ;
V_19 -> V_128 [ V_115 ] ++ ;
V_19 -> V_129 [ V_116 ] ++ ;
V_19 -> V_130 [ V_117 ] ++ ;
V_19 -> V_131 [ V_118 ] ++ ;
if ( V_110 ) {
V_19 -> V_132 ++ ;
V_19 -> V_133 += V_111 ;
if ( V_108 )
V_19 -> V_134 ++ ;
if ( V_109 )
V_19 -> V_135 ++ ;
V_19 -> V_136 [ V_112 ] ++ ;
V_19 -> V_137 [ V_113 ] ++ ;
V_19 -> V_138 [ V_115 ] ++ ;
V_19 -> V_139 [ V_116 ] ++ ;
V_19 -> V_140 [ V_118 ] ++ ;
}
}
static void F_89 ( struct V_33 * V_34 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
long V_141 , V_142 , V_143 , V_144 ;
long V_145 , V_111 ;
struct V_1 * V_2 ;
int V_112 , V_113 , V_114 , V_115 ;
int V_116 , V_117 , V_118 ;
V_2 = V_96 -> V_106 ;
if ( ! ( V_54 ||
V_34 -> V_30 . V_19 ||
V_2 -> V_30 . V_19 ) )
return;
V_111 = F_90 ( V_98 ) ;
if ( ! V_96 -> V_146 || ! V_96 -> V_147 ||
! V_96 -> V_148 || ! V_96 -> V_149 ||
! V_111 )
return;
V_141 = ( ( V_96 -> V_147 - V_96 -> V_146 ) >> 12 ) ;
V_142 = ( ( V_96 -> V_148 - V_96 -> V_147 ) >> 12 ) ;
V_143 = ( ( V_96 -> V_149 - V_96 -> V_148 ) >> 12 ) ;
V_144 = ( ( V_96 -> V_149 - V_96 -> V_146 ) >> 12 ) ;
V_145 = V_144 / V_111 ;
F_91 ( V_111 , V_112 ) ;
F_91 ( V_144 , V_113 ) ;
F_91 ( V_145 , V_114 ) ;
F_91 ( V_141 , V_115 ) ;
F_91 ( V_142 , V_116 ) ;
F_91 ( V_142 / V_111 , V_117 ) ;
F_91 ( V_143 , V_118 ) ;
if ( V_54 ) {
F_87 ( & V_102 ,
V_96 -> V_106 != V_34 -> V_63 ,
V_96 -> V_150 == 1 ,
F_84 ( V_98 ) == V_104 ,
V_111 , V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 ,
V_118 ) ;
}
F_85 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
F_87 ( V_34 -> V_30 . V_19 ,
V_96 -> V_106 != V_34 -> V_63 ,
V_96 -> V_150 == 1 ,
F_84 ( V_98 ) == V_104 ,
V_111 , V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 ,
V_118 ) ;
F_86 ( & V_34 -> V_30 . V_31 ) ;
F_85 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 )
F_87 ( V_2 -> V_30 . V_19 ,
V_96 -> V_106 != V_34 -> V_63 ,
V_96 -> V_150 == 1 ,
F_84 ( V_98 ) == V_104 ,
V_111 , V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 ,
V_118 ) ;
F_86 ( & V_2 -> V_30 . V_31 ) ;
}
void F_92 ( struct V_151 * V_30 )
{
struct V_107 * V_19 ;
F_93 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_94 ( & V_30 -> V_31 ) ;
return;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_88 ( & V_19 -> V_121 ) ;
F_94 ( & V_30 -> V_31 ) ;
}
void F_95 ( void )
{
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
F_88 ( & V_102 . V_121 ) ;
}
int F_34 ( struct V_151 * V_30 )
{
struct V_107 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_152 ) ;
if ( ! V_19 )
return - V_4 ;
F_93 ( & V_30 -> V_31 ) ;
if ( V_30 -> V_19 ) {
F_94 ( & V_30 -> V_31 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_88 ( & V_19 -> V_121 ) ;
V_30 -> V_19 = V_19 ;
F_94 ( & V_30 -> V_31 ) ;
return 0 ;
}
void F_96 ( struct V_151 * V_30 )
{
F_93 ( & V_30 -> V_31 ) ;
F_5 ( V_30 -> V_19 ) ;
V_30 -> V_19 = NULL ;
F_94 ( & V_30 -> V_31 ) ;
}
char * F_97 ( const char T_1 * V_153 , T_2 V_154 )
{
char * V_155 ;
V_155 = F_98 ( V_154 + 1 ) ;
if ( V_155 == NULL )
return F_3 ( - V_4 ) ;
if ( F_99 ( V_155 , V_153 , V_154 ) != 0 ) {
F_100 ( V_155 ) ;
return F_3 ( - V_156 ) ;
}
if ( V_155 [ V_154 - 1 ] == '\n' )
V_155 [ V_154 - 1 ] = 0 ;
else
V_155 [ V_154 ] = 0 ;
return V_155 ;
}
static T_3 F_101 ( struct V_157 * V_157 ,
const char T_1 * V_153 ,
T_2 V_154 , T_4 * V_158 )
{
char * V_155 , * V_159 ;
int V_40 ;
struct V_160 * V_161 = (struct V_160 * ) V_157 -> V_162 ;
struct V_151 * V_163 = V_161 -> V_32 ;
if ( V_154 > 65536 )
V_154 = 65536 ;
V_155 = F_97 ( V_153 , V_154 ) ;
if ( F_30 ( V_155 ) )
return F_102 ( V_155 ) ;
V_159 = F_103 ( V_155 ) ;
V_40 = V_154 ;
if ( strncmp ( V_159 , L_4 , 5 ) == 0 ) {
F_92 ( V_163 ) ;
} else if ( strncmp ( V_159 , L_5 , 2 ) == 0 ) {
V_40 = F_34 ( V_163 ) ;
if ( ! V_40 )
V_40 = V_154 ;
} else if ( strncmp ( V_159 , L_6 , 3 ) == 0 ) {
F_96 ( V_163 ) ;
} else
V_40 = - V_164 ;
F_100 ( V_155 ) ;
return V_40 ;
}
static void F_104 ( struct V_160 * V_161 , unsigned int * V_165 )
{
int V_166 ;
for ( V_166 = 0 ; V_166 < 32 ; V_166 ++ )
F_105 ( V_161 , L_7 , V_165 [ V_166 ] ) ;
F_106 ( V_161 , '\n' ) ;
}
static void F_107 ( struct V_160 * V_161 ,
struct V_107 * V_19 )
{
F_105 ( V_161 , L_8 ,
V_19 -> V_121 . V_167 , V_19 -> V_121 . V_168 ) ;
F_105 ( V_161 , L_9 , V_19 -> V_119 ) ;
F_105 ( V_161 , L_10 , V_19 -> V_122 ) ;
F_105 ( V_161 , L_11 , V_19 -> V_123 ) ;
F_105 ( V_161 , L_12 , V_19 -> V_124 ) ;
F_105 ( V_161 , L_13 ) ;
F_104 ( V_161 , V_19 -> V_125 ) ;
F_105 ( V_161 , L_14 ) ;
F_104 ( V_161 , V_19 -> V_126 ) ;
F_105 ( V_161 , L_15 ) ;
F_104 ( V_161 , V_19 -> V_127 ) ;
F_105 ( V_161 , L_16 ) ;
F_104 ( V_161 , V_19 -> V_128 ) ;
F_105 ( V_161 , L_17 ) ;
F_104 ( V_161 , V_19 -> V_129 ) ;
F_105 ( V_161 , L_18 ) ;
F_104 ( V_161 , V_19 -> V_130 ) ;
F_105 ( V_161 , L_19 ) ;
F_104 ( V_161 , V_19 -> V_131 ) ;
F_105 ( V_161 , L_20 ) ;
F_104 ( V_161 , V_19 -> V_103 ) ;
F_105 ( V_161 , L_21 , V_19 -> V_132 ) ;
F_105 ( V_161 , L_22 , V_19 -> V_133 ) ;
F_105 ( V_161 , L_23 , V_19 -> V_134 ) ;
F_105 ( V_161 , L_24 , V_19 -> V_135 ) ;
F_105 ( V_161 , L_25 ) ;
F_104 ( V_161 , V_19 -> V_136 ) ;
F_105 ( V_161 , L_26 ) ;
F_104 ( V_161 , V_19 -> V_137 ) ;
F_105 ( V_161 , L_27 ) ;
F_104 ( V_161 , V_19 -> V_138 ) ;
F_105 ( V_161 , L_28 ) ;
F_104 ( V_161 , V_19 -> V_139 ) ;
F_105 ( V_161 , L_29 ) ;
F_104 ( V_161 , V_19 -> V_140 ) ;
F_105 ( V_161 , L_30 ) ;
F_104 ( V_161 , V_19 -> V_105 ) ;
}
static int F_108 ( struct V_160 * V_161 , void * V_169 )
{
struct V_151 * V_30 ;
struct V_107 * V_19 ;
V_30 = V_161 -> V_32 ;
F_93 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_94 ( & V_30 -> V_31 ) ;
F_105 ( V_161 , L_31 ) ;
return 0 ;
}
F_107 ( V_161 , V_19 ) ;
F_94 ( & V_30 -> V_31 ) ;
return 0 ;
}
static int F_109 ( struct V_170 * V_170 , struct V_157 * V_157 )
{
struct V_151 * V_30 = V_170 -> V_171 ;
return F_110 ( V_157 , F_108 , V_30 ) ;
}
static T_3 F_111 ( struct V_157 * V_157 ,
const char T_1 * V_153 ,
T_2 V_154 , T_4 * V_158 )
{
char * V_155 , * V_159 ;
T_3 V_40 ;
if ( V_154 > 65536 )
V_154 = 65536 ;
V_155 = F_97 ( V_153 , V_154 ) ;
if ( F_30 ( V_155 ) )
return F_102 ( V_155 ) ;
V_159 = F_103 ( V_155 ) ;
V_40 = V_154 ;
if ( strncmp ( V_159 , L_4 , 5 ) == 0 ) {
F_95 () ;
} else if ( strncmp ( V_159 , L_5 , 2 ) == 0 ) {
F_95 () ;
V_54 = V_172 ;
} else if ( strncmp ( V_159 , L_6 , 3 ) == 0 ) {
V_54 = V_173 ;
} else
V_40 = - V_164 ;
F_100 ( V_155 ) ;
return V_40 ;
}
static int F_112 ( struct V_160 * V_161 , void * V_169 )
{
if ( ! V_54 ) {
F_105 ( V_161 , L_31 ) ;
return 0 ;
}
F_107 ( V_161 , & V_102 ) ;
return 0 ;
}
static int F_113 ( struct V_170 * V_170 , struct V_157 * V_157 )
{
return F_110 ( V_157 , F_112 , NULL ) ;
}
static void F_33 ( struct V_151 * V_30 ,
struct V_46 * V_48 )
{
T_5 V_174 ;
struct V_46 * V_49 ;
if ( ! V_48 )
return;
V_30 -> V_46 = NULL ;
V_30 -> V_19 = NULL ;
V_174 = ( V_175 | V_176 | V_177 ) ;
V_49 = F_114 ( L_32 , V_174 , V_48 ,
V_30 , & V_178 ) ;
if ( V_49 && ! F_30 ( V_49 ) )
V_30 -> V_46 = V_49 ;
return;
}
static void F_41 ( struct V_151 * V_30 )
{
F_96 ( V_30 ) ;
if ( V_30 -> V_46 ) {
F_42 ( V_30 -> V_46 ) ;
V_30 -> V_46 = NULL ;
}
}
static void F_115 ( void )
{
V_54 = V_173 ;
if ( V_179 ) {
F_42 ( V_179 ) ;
V_179 = NULL ;
}
if ( V_180 )
F_42 ( V_180 ) ;
if ( V_53 )
F_42 ( V_53 ) ;
}
static void F_116 ( void )
{
T_5 V_174 ;
struct V_46 * V_49 ;
V_53 = NULL ;
V_180 = NULL ;
V_179 = NULL ;
V_49 = F_29 ( L_33 , NULL ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_53 = V_49 ;
V_49 = F_29 ( L_34 , V_53 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_180 = V_49 ;
V_174 = ( V_175 | V_176 | V_177 ) ;
V_49 = F_114 ( L_32 , V_174 , V_180 ,
NULL , & V_181 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_179 = V_49 ;
return;
error:
F_117 ( V_182 , L_1 ,
L_35 ) ;
F_115 () ;
return;
}
static void F_116 ( void )
{
return;
}
static void F_115 ( void )
{
return;
}
int F_118 ( struct V_160 * V_161 , void * V_169 )
{
F_105 ( V_161 , L_36 ) ;
return 0 ;
}
static void F_33 ( struct V_151 * V_30 ,
struct V_46 * V_48 )
{
return;
}
static void F_41 ( struct V_151 * V_30 )
{
return;
}
int F_34 ( struct V_151 * V_30 )
{
return 0 ;
}
struct V_95 * F_119 ( int V_183 , int V_184 ,
int V_185 ,
struct V_1 * V_2 )
{
struct V_95 * V_96 ;
F_120 ( V_185 > V_9 ||
( V_184 * sizeof( struct V_186 ) ) > V_9 ) ;
V_96 = F_2 ( sizeof( struct V_95 ) , V_3 ) ;
if ( V_96 == NULL )
return F_3 ( - V_4 ) ;
V_96 -> V_187 = NULL ;
if ( V_184 > 0 ) {
V_96 -> V_187 = F_121 ( V_184 , sizeof( struct V_186 ) ,
V_3 | V_6 ) ;
if ( V_96 -> V_187 == NULL ) {
F_5 ( V_96 ) ;
return F_3 ( - V_4 ) ;
}
}
V_96 -> V_19 = NULL ;
if ( V_185 > 0 ) {
V_96 -> V_19 = F_2 ( V_185 , V_3 | V_6 ) ;
if ( V_96 -> V_19 == NULL ) {
F_5 ( V_96 -> V_187 ) ;
F_5 ( V_96 ) ;
return F_3 ( - V_4 ) ;
}
}
V_96 -> V_183 = V_183 ;
F_122 ( V_188 , & V_96 -> V_189 ) ;
F_21 ( V_2 ) ;
return V_96 ;
}
struct V_95 * F_123 ( int V_183 , int V_184 ,
int V_185 ,
struct V_1 * V_2 )
{
unsigned long V_189 ;
struct V_95 * V_96 ;
char * V_19 ;
int V_190 ;
V_190 = ( sizeof( struct V_95 ) + 7L ) & - 8L ;
if ( V_184 > 0 )
V_190 += V_184 * sizeof( struct V_186 ) ;
if ( V_185 > 0 )
V_190 += V_185 ;
F_124 ( & V_2 -> V_11 , V_189 ) ;
V_96 = (struct V_95 * )
F_125 ( & V_2 -> V_8 , V_190 ) ;
F_126 ( & V_2 -> V_11 , V_189 ) ;
if ( V_96 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
V_19 = ( char * ) V_96 + ( ( sizeof( struct V_95 ) + 7L ) & - 8L ) ;
V_96 -> V_187 = NULL ;
if ( V_184 > 0 ) {
V_96 -> V_187 = (struct V_186 * ) V_19 ;
V_19 += V_184 * sizeof( struct V_186 ) ;
memset ( V_96 -> V_187 , 0 , V_184 * sizeof( struct V_186 ) ) ;
}
V_96 -> V_19 = NULL ;
if ( V_185 > 0 ) {
V_96 -> V_19 = V_19 ;
memset ( V_96 -> V_19 , 0 , V_185 ) ;
}
V_96 -> V_183 = V_183 ;
F_122 ( V_188 , & V_96 -> V_189 ) ;
F_21 ( V_2 ) ;
return V_96 ;
}
void F_127 ( struct V_95 * V_96 , struct V_1 * V_2 )
{
#ifdef F_128
struct V_186 * V_191 ;
V_191 = V_96 -> V_187 ;
do {
F_129 ( V_191 ) ;
} while ( V_191 ++ -> V_189 & ( V_192 | V_193 ) );
#endif
F_5 ( V_96 -> V_187 ) ;
F_5 ( V_96 -> V_19 ) ;
F_5 ( V_96 ) ;
F_23 ( V_2 ) ;
}
void F_130 ( struct V_95 * V_96 , struct V_1 * V_2 )
{
unsigned long V_189 ;
F_124 ( & V_2 -> V_11 , V_189 ) ;
F_131 ( & V_2 -> V_8 , V_96 ) ;
F_126 ( & V_2 -> V_11 , V_189 ) ;
F_23 ( V_2 ) ;
}
static inline int F_132 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
if ( V_96 == NULL )
return - V_164 ;
V_2 = V_96 -> V_106 ;
if ( strncmp ( ( char * ) & V_96 -> V_183 , V_2 -> V_42 -> V_194 , 4 ) ) {
F_39 ( V_60 , V_2 ,
L_37
L_38 ,
V_96 -> V_183 ,
* ( unsigned int * ) V_2 -> V_42 -> V_47 ) ;
return - V_164 ;
}
return 0 ;
}
int F_133 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_195 , V_40 ;
char V_196 [ V_197 ] ;
V_40 = F_132 ( V_96 ) ;
if ( V_40 )
return V_40 ;
V_195 = 0 ;
V_2 = (struct V_1 * ) V_96 -> V_106 ;
while ( ( V_195 < 5 ) && ( V_96 -> V_198 == V_199 ) ) {
V_40 = F_134 ( V_2 -> V_56 , ( long ) V_96 ) ;
switch ( V_40 ) {
case 0 :
V_96 -> V_198 = V_200 ;
V_96 -> V_148 = F_135 () ;
V_96 -> V_201 = 0 ;
F_39 ( V_202 , V_2 ,
L_39 ,
V_96 ) ;
break;
case - V_203 :
F_39 ( V_182 , V_2 , L_1 ,
L_40 ) ;
break;
case - V_204 :
F_39 ( V_182 , V_2 , L_1 ,
L_41 ) ;
break;
case - V_164 :
case - V_205 :
F_39 ( V_182 , V_2 , L_1 ,
L_42 ) ;
break;
default:
snprintf ( V_196 , V_197 , L_43 , V_40 ) ;
F_136 ( & V_2 -> V_56 -> V_57 , L_44
L_45 , V_196 ) ;
F_137 () ;
break;
}
V_195 ++ ;
}
F_73 ( V_2 ) ;
return V_40 ;
}
int F_138 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_40 ;
char V_196 [ V_197 ] ;
V_40 = F_132 ( V_96 ) ;
if ( V_40 ) {
V_96 -> V_206 = V_40 ;
return V_40 ;
}
V_2 = (struct V_1 * ) V_96 -> V_106 ;
if ( ( ( V_96 -> V_34 &&
F_139 ( V_207 , & V_96 -> V_34 -> V_63 -> V_189 ) ) ||
F_139 ( V_207 , & V_2 -> V_189 ) ) &&
! F_139 ( V_208 , & V_96 -> V_189 ) ) {
F_39 ( V_202 , V_2 , L_46
L_47 , V_96 ) ;
V_96 -> V_198 = V_209 ;
V_96 -> V_206 = - V_87 ;
return - V_87 ;
}
if ( V_96 -> V_195 < 0 ) {
sprintf ( V_196 , L_48 , V_96 ) ;
F_136 ( & V_2 -> V_56 -> V_57 , L_49
L_50 , V_196 ) ;
V_96 -> V_198 = V_209 ;
return - V_204 ;
}
V_96 -> V_147 = F_135 () ;
V_96 -> V_201 = V_210 ;
V_96 -> V_195 -- ;
if ( ! F_139 ( V_211 , & V_96 -> V_189 ) ) {
V_96 -> V_212 &= V_2 -> V_213 . V_214 ;
if ( ! V_96 -> V_212 )
V_96 -> V_212 = V_2 -> V_213 . V_214 ;
}
if ( V_96 -> V_150 == 1 ) {
V_40 = F_140 ( V_2 -> V_56 , V_96 -> V_187 ,
( long ) V_96 , V_96 -> V_212 ) ;
} else {
V_40 = F_141 ( V_2 -> V_56 , V_96 -> V_187 ,
( long ) V_96 , V_96 -> V_212 , 0 ) ;
}
switch ( V_40 ) {
case 0 :
V_96 -> V_198 = V_199 ;
break;
case - V_205 :
F_39 ( V_60 , V_2 , L_1 ,
L_51 ) ;
break;
case - V_215 :
F_39 ( V_60 , V_2 , L_1 ,
L_52 ) ;
break;
case - V_216 :
if ( F_139 ( V_211 , & V_96 -> V_189 ) ) {
F_39 ( V_60 , V_2 ,
L_53 ,
V_96 -> V_212 ) ;
} else if ( V_96 -> V_212 != V_2 -> V_213 . V_214 ) {
V_96 -> V_212 = V_2 -> V_213 . V_214 ;
F_39 ( V_202 , V_2 , L_1 ,
L_54
L_55 ) ;
} else {
F_39 ( V_60 , V_2 , L_1 ,
L_56
L_57 ) ;
F_142 ( V_2 ) ;
V_2 -> V_213 . V_214 = 0 ;
V_2 -> V_213 . V_217 = 0 ;
V_2 -> V_213 . V_218 = 0 ;
V_2 -> V_213 . V_219 =
F_143 ( V_2 -> V_56 ) ;
}
break;
case - V_203 :
F_39 ( V_60 , V_2 , L_1 ,
L_58 ) ;
break;
case - V_204 :
F_39 ( V_60 , V_2 , L_1 ,
L_59 ) ;
break;
case - V_164 :
F_39 ( V_60 , V_2 , L_1 ,
L_60
L_61 ) ;
break;
default:
snprintf ( V_196 , V_197 , L_62 , V_40 ) ;
F_136 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , V_196 ) ;
F_137 () ;
break;
}
V_96 -> V_206 = V_40 ;
return V_40 ;
}
static void V_18 ( unsigned long V_220 )
{
unsigned long V_189 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_220 ;
F_124 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
F_145 ( V_2 , V_221 ) ;
F_126 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
F_73 ( V_2 ) ;
}
void F_146 ( struct V_1 * V_2 , int V_222 )
{
if ( V_222 == 0 )
F_147 ( & V_2 -> V_16 ) ;
else
F_148 ( & V_2 -> V_16 , V_210 + V_222 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_147 ( & V_2 -> V_16 ) ;
}
static void F_149 ( struct V_223 * V_56 ,
unsigned long V_224 )
{
struct V_95 * V_96 ;
struct V_1 * V_2 ;
if ( ! V_224 )
return;
V_96 = (struct V_95 * ) V_224 ;
if ( V_96 -> V_198 != V_199 ) {
F_150 ( V_202 , V_56 ,
L_65
L_66 , V_96 -> V_198 ) ;
return;
}
V_2 = F_151 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_150 ( V_202 , V_56 , L_1 ,
L_67 ) ;
return;
}
if ( ! V_96 -> V_106 ||
V_2 != V_96 -> V_106 ||
strncmp ( V_96 -> V_106 -> V_42 -> V_194 ,
( char * ) & V_96 -> V_183 , 4 ) ) {
F_150 ( V_202 , V_56 , L_1 ,
L_68 ) ;
F_23 ( V_2 ) ;
return;
}
V_96 -> V_198 = V_225 ;
F_46 ( V_2 ) ;
F_73 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_152 ( struct V_1 * V_2 )
{
F_153 ( V_2 ) ;
F_145 ( V_2 , V_221 ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_34 )
F_58 ( V_2 -> V_34 ) ;
}
void F_154 ( struct V_223 * V_56 , unsigned long V_224 ,
struct V_226 * V_226 )
{
struct V_95 * V_96 , * V_227 ;
struct V_1 * V_2 ;
unsigned long long V_228 ;
int V_222 ;
if ( F_30 ( V_226 ) ) {
switch ( F_102 ( V_226 ) ) {
case - V_204 :
break;
case - V_215 :
F_150 ( V_60 , V_56 , L_69
L_70 , V_229 ) ;
break;
default:
F_150 ( V_60 , V_56 , L_69
L_71 , V_229 ,
F_102 ( V_226 ) ) ;
}
F_149 ( V_56 , V_224 ) ;
return;
}
V_228 = F_135 () ;
V_96 = (struct V_95 * ) V_224 ;
if ( ! V_96 ||
! ( F_155 ( & V_226 -> V_230 ) == ( V_231 | V_232 ) &&
F_156 ( & V_226 -> V_230 ) == 0 ) ) {
if ( V_96 )
memcpy ( & V_96 -> V_226 , V_226 , sizeof( * V_226 ) ) ;
V_2 = F_151 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_42 == V_233 ) {
F_23 ( V_2 ) ;
return;
}
V_2 -> V_42 -> V_234 ( V_2 , V_226 , L_72 ) ;
if ( V_2 -> V_79 & V_235 )
V_2 -> V_42 -> V_236 ( V_2 , V_96 , V_226 ) ;
V_2 -> V_42 -> V_237 ( V_2 , V_96 , V_226 ) ;
F_23 ( V_2 ) ;
}
if ( ! V_96 )
return;
V_2 = (struct V_1 * ) V_96 -> V_106 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_42 -> V_194 , ( char * ) & V_96 -> V_183 , 4 ) ) {
F_150 ( V_202 , V_56 , L_1 ,
L_68 ) ;
return;
}
if ( V_96 -> V_198 == V_200 &&
F_157 ( & V_226 -> V_230 ) & V_238 ) {
V_96 -> V_198 = V_239 ;
F_46 ( V_2 ) ;
F_69 ( & V_240 ) ;
F_73 ( V_2 ) ;
return;
}
if ( V_96 -> V_198 != V_199 ) {
F_39 ( V_202 , V_2 , L_73
L_74 , F_35 ( & V_56 -> V_57 ) , V_96 -> V_198 ) ;
return;
}
V_227 = NULL ;
V_222 = 0 ;
if ( F_155 ( & V_226 -> V_230 ) == ( V_231 | V_232 ) &&
F_156 ( & V_226 -> V_230 ) == 0 ) {
V_96 -> V_198 = V_241 ;
V_96 -> V_148 = V_228 ;
if ( V_96 -> V_242 . V_227 != & V_2 -> V_15 ) {
V_227 = F_158 ( V_96 -> V_242 . V_227 ,
struct V_95 , V_242 ) ;
}
} else {
if ( ! F_139 ( V_188 , & V_96 -> V_189 ) &&
V_96 -> V_195 > 0 ) {
if ( V_96 -> V_212 == V_2 -> V_213 . V_214 )
F_39 ( V_202 , V_2 ,
L_75
L_76 ,
V_96 -> V_195 ) ;
if ( ! F_139 ( V_211 , & V_96 -> V_189 ) )
V_96 -> V_212 = V_2 -> V_213 . V_214 ;
V_96 -> V_198 = V_225 ;
V_227 = V_96 ;
} else
V_96 -> V_198 = V_209 ;
}
if ( V_227 && ( V_227 -> V_198 == V_225 ) &&
( ! V_2 -> V_243 ) ) {
if ( V_2 -> V_42 -> V_244 ( V_227 ) == 0 )
V_222 = V_227 -> V_222 ;
}
if ( V_222 != 0 )
F_146 ( V_2 , V_222 ) ;
else
F_46 ( V_2 ) ;
F_73 ( V_2 ) ;
}
enum V_245 F_159 ( struct V_223 * V_56 , struct V_226 * V_226 )
{
struct V_1 * V_2 ;
V_2 = F_151 ( V_56 ) ;
if ( F_30 ( V_2 ) )
goto V_246;
if ( F_139 ( V_247 , & V_2 -> V_189 ) ||
V_2 -> V_26 != V_2 -> V_28 ||
! V_2 -> V_42 -> V_237 ) {
F_23 ( V_2 ) ;
goto V_246;
}
if ( V_2 -> V_42 -> V_234 )
V_2 -> V_42 -> V_234 ( V_2 , V_226 , L_77 ) ;
V_2 -> V_42 -> V_237 ( V_2 , NULL , V_226 ) ;
F_23 ( V_2 ) ;
V_246:
return V_248 ;
}
static void F_160 ( struct V_1 * V_2 ,
struct V_95 * V_249 )
{
struct V_99 * V_100 , * V_250 ;
struct V_95 * V_96 ;
if ( ! V_249 -> V_34 )
return;
F_161 (l, n, &device->ccw_queue) {
V_96 = F_158 ( V_100 , struct V_95 , V_242 ) ;
if ( V_96 -> V_198 == V_225 &&
V_249 -> V_34 == V_96 -> V_34 ) {
V_96 -> V_198 = V_239 ;
}
}
}
static void F_162 ( struct V_1 * V_2 ,
struct V_99 * V_251 )
{
struct V_99 * V_100 , * V_250 ;
struct V_95 * V_96 ;
F_161 (l, n, &device->ccw_queue) {
V_96 = F_158 ( V_100 , struct V_95 , V_242 ) ;
if ( V_96 -> V_198 == V_225 ||
V_96 -> V_198 == V_199 ||
V_96 -> V_198 == V_200 )
break;
if ( V_96 -> V_198 == V_209 ) {
F_160 ( V_2 , V_96 ) ;
}
F_163 ( & V_96 -> V_242 , V_251 ) ;
}
}
static void F_164 ( struct V_1 * V_2 ,
struct V_99 * V_251 )
{
struct V_99 * V_100 , * V_250 ;
struct V_95 * V_96 ;
struct V_33 * V_34 ;
void (* F_165)( struct V_95 * , void * V_19 );
void * V_252 ;
char V_196 [ V_197 ] ;
F_161 (l, n, final_queue) {
V_96 = F_158 ( V_100 , struct V_95 , V_242 ) ;
F_166 ( & V_96 -> V_242 ) ;
V_34 = V_96 -> V_34 ;
F_165 = V_96 -> F_165 ;
V_252 = V_96 -> V_252 ;
if ( V_34 )
F_93 ( & V_34 -> V_38 ) ;
switch ( V_96 -> V_198 ) {
case V_241 :
V_96 -> V_198 = V_253 ;
break;
case V_209 :
V_96 -> V_198 = V_254 ;
break;
case V_239 :
V_96 -> V_198 = V_255 ;
break;
default:
snprintf ( V_196 , V_197 , L_78 , V_96 , V_96 -> V_198 ) ;
F_136 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , V_196 ) ;
F_137 () ;
}
if ( V_96 -> F_165 != NULL )
( F_165 ) ( V_96 , V_252 ) ;
if ( V_34 )
F_94 ( & V_34 -> V_38 ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
if ( F_168 ( & V_2 -> V_15 ) )
return;
V_96 = F_158 ( V_2 -> V_15 . V_227 , struct V_95 , V_242 ) ;
if ( ( V_96 -> V_198 == V_199 && V_96 -> V_222 != 0 ) &&
( F_169 ( V_210 , V_96 -> V_222 + V_96 -> V_201 ) ) ) {
if ( V_2 -> V_42 -> V_256 ( V_96 ) != 0 ) {
F_136 ( & V_2 -> V_56 -> V_57 ,
L_79
L_80 ,
V_96 , ( V_96 -> V_222 / V_257 ) ) ;
V_96 -> V_222 += 5 * V_257 ;
F_146 ( V_2 , 5 * V_257 ) ;
} else {
F_136 ( & V_2 -> V_56 -> V_57 ,
L_81
L_82 , V_96 , ( V_96 -> V_222 / V_257 ) ,
V_96 -> V_195 ) ;
}
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
int V_40 ;
if ( F_168 ( & V_2 -> V_15 ) )
return;
V_96 = F_158 ( V_2 -> V_15 . V_227 , struct V_95 , V_242 ) ;
if ( V_96 -> V_198 != V_225 )
return;
if ( V_2 -> V_243 &&
! ( ! ( V_2 -> V_243 & ~ ( V_258 | V_259 ) )
&& F_139 ( V_211 , & V_96 -> V_189 ) ) ) {
V_96 -> V_206 = - V_65 ;
V_96 -> V_198 = V_239 ;
F_73 ( V_2 ) ;
return;
}
V_40 = V_2 -> V_42 -> V_244 ( V_96 ) ;
if ( V_40 == 0 )
F_146 ( V_2 , V_96 -> V_222 ) ;
else if ( V_40 == - V_216 ) {
F_73 ( V_2 ) ;
} else
F_146 ( V_2 , 50 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_213 . V_219 ) {
if ( V_2 -> V_243 & ~ ( V_258 |
V_259 ) )
return;
V_40 = V_2 -> V_42 -> V_260 (
V_2 , V_2 -> V_213 . V_219 ) ;
if ( V_40 )
F_146 ( V_2 , 50 ) ;
else
V_2 -> V_213 . V_219 = 0 ;
}
}
int F_45 ( struct V_1 * V_2 )
{
struct V_95 * V_96 , * V_250 ;
int V_40 ;
struct V_99 V_261 ;
F_12 ( & V_261 ) ;
F_172 ( F_144 ( V_2 -> V_56 ) ) ;
V_40 = 0 ;
F_173 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_96 -> V_198 ) {
case V_199 :
V_40 = V_2 -> V_42 -> V_256 ( V_96 ) ;
if ( V_40 ) {
F_136 ( & V_2 -> V_56 -> V_57 ,
L_83
L_84 , V_96 ) ;
goto V_262;
}
break;
case V_225 :
V_96 -> V_148 = F_135 () ;
V_96 -> V_198 = V_239 ;
break;
default:
break;
}
F_163 ( & V_96 -> V_242 , & V_261 ) ;
}
V_262:
F_174 ( F_144 ( V_2 -> V_56 ) ) ;
F_173 (cqr, n, &flush_queue, devlist)
F_81 ( V_240 ,
( V_96 -> V_198 != V_200 ) ) ;
F_164 ( V_2 , & V_261 ) ;
return V_40 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_99 V_251 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_251 ) ;
F_172 ( F_144 ( V_2 -> V_56 ) ) ;
F_167 ( V_2 ) ;
F_162 ( V_2 , & V_251 ) ;
F_171 ( V_2 ) ;
F_174 ( F_144 ( V_2 -> V_56 ) ) ;
F_164 ( V_2 , & V_251 ) ;
F_172 ( F_144 ( V_2 -> V_56 ) ) ;
F_170 ( V_2 ) ;
F_174 ( F_144 ( V_2 -> V_56 ) ) ;
F_23 ( V_2 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
if ( F_175 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_176 ( & V_2 -> V_13 ) ;
}
void F_177 ( struct V_1 * V_2 , int V_263 )
{
V_2 -> V_243 |= V_263 ;
}
void F_145 ( struct V_1 * V_2 , int V_263 )
{
V_2 -> V_243 &= ~ V_263 ;
if ( ! V_2 -> V_243 )
F_69 ( & V_264 ) ;
}
void F_178 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
unsigned long V_189 ;
V_2 = V_96 -> V_106 ;
F_124 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
V_96 -> V_198 = V_225 ;
F_179 ( & V_96 -> V_242 , & V_2 -> V_15 ) ;
F_73 ( V_2 ) ;
F_126 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
}
void F_180 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
unsigned long V_189 ;
V_2 = V_96 -> V_106 ;
F_124 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
V_96 -> V_198 = V_225 ;
F_181 ( & V_96 -> V_242 , & V_2 -> V_15 ) ;
F_73 ( V_2 ) ;
F_126 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
}
void F_182 ( struct V_95 * V_96 , void * V_19 )
{
F_172 ( F_144 ( V_96 -> V_106 -> V_56 ) ) ;
V_96 -> V_252 = V_265 ;
F_174 ( F_144 ( V_96 -> V_106 -> V_56 ) ) ;
F_69 ( & V_264 ) ;
}
static inline int F_183 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_96 -> V_106 ;
F_172 ( F_144 ( V_2 -> V_56 ) ) ;
V_40 = ( V_96 -> V_252 == V_265 ) ;
F_174 ( F_144 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
static int F_184 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
T_6 V_266 ;
if ( V_96 -> V_198 == V_267 )
return 0 ;
V_2 = V_96 -> V_106 ;
if ( F_139 ( V_188 , & V_96 -> V_189 ) ) {
if ( V_96 -> V_198 == V_255 ) {
V_2 -> V_42 -> V_268 ( V_96 ) ;
return 1 ;
}
if ( V_96 -> V_198 == V_254 ) {
V_266 = V_2 -> V_42 -> V_269 ( V_96 ) ;
V_266 ( V_96 ) ;
return 1 ;
}
if ( V_96 -> V_198 == V_270 )
F_185 ( V_96 , & V_96 -> V_226 ) ;
if ( V_96 -> V_271 ) {
F_186 ( V_2 , V_96 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_187 ( struct V_95 * V_96 )
{
if ( F_139 ( V_188 , & V_96 -> V_189 ) ) {
if ( V_96 -> V_271 )
return 1 ;
return ( ( V_96 -> V_198 != V_253 ) &&
( V_96 -> V_198 != V_270 ) ) ;
} else
return ( V_96 -> V_198 == V_267 ) ;
}
static int F_188 ( struct V_95 * V_272 , int V_273 )
{
struct V_1 * V_2 ;
int V_40 ;
struct V_99 V_15 ;
struct V_95 * V_96 ;
F_12 ( & V_15 ) ;
V_272 -> V_198 = V_267 ;
V_2 = V_272 -> V_106 ;
F_179 ( & V_272 -> V_274 , & V_15 ) ;
for ( V_96 = V_272 ; F_187 ( V_96 ) ;
V_96 = F_189 ( & V_15 ,
struct V_95 , V_274 ) ) {
if ( F_184 ( V_96 ) )
continue;
if ( V_96 -> V_198 != V_267 )
continue;
if ( F_139 ( V_207 , & V_2 -> V_189 ) &&
! F_139 ( V_208 , & V_96 -> V_189 ) ) {
V_96 -> V_198 = V_270 ;
V_96 -> V_206 = - V_87 ;
continue;
}
if ( V_2 -> V_243 & ~ V_221 &&
F_139 ( V_275 , & V_96 -> V_189 ) &&
( ! F_190 ( V_2 ) ) ) {
V_96 -> V_198 = V_270 ;
continue;
}
if ( V_273 ) {
V_40 = F_191 (
V_264 , ! ( V_2 -> V_243 ) ) ;
if ( V_40 == - V_276 ) {
V_96 -> V_198 = V_270 ;
V_272 -> V_206 = V_40 ;
continue;
}
} else
F_81 ( V_264 , ! ( V_2 -> V_243 ) ) ;
if ( ! V_96 -> F_165 )
V_96 -> F_165 = F_182 ;
V_96 -> V_252 = V_277 ;
F_180 ( V_96 ) ;
if ( V_273 ) {
V_40 = F_191 (
V_264 , F_183 ( V_96 ) ) ;
if ( V_40 == - V_276 ) {
F_192 ( V_96 ) ;
F_81 ( V_264 ,
F_183 ( V_96 ) ) ;
V_96 -> V_198 = V_270 ;
V_272 -> V_206 = V_40 ;
continue;
}
} else
F_81 ( V_264 , F_183 ( V_96 ) ) ;
}
V_272 -> V_149 = F_135 () ;
if ( ( V_272 -> V_198 != V_253 ) &&
( V_272 -> V_206 != - V_276 ) )
F_185 ( V_272 , & V_272 -> V_226 ) ;
if ( V_272 -> V_198 == V_253 )
V_40 = 0 ;
else if ( V_272 -> V_206 )
V_40 = V_272 -> V_206 ;
else
V_40 = - V_204 ;
return V_40 ;
}
int F_193 ( struct V_95 * V_96 )
{
return F_188 ( V_96 , 0 ) ;
}
int F_194 ( struct V_95 * V_96 )
{
return F_188 ( V_96 , 1 ) ;
}
static inline int F_195 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
int V_40 ;
if ( F_168 ( & V_2 -> V_15 ) )
return 0 ;
V_96 = F_158 ( V_2 -> V_15 . V_227 , struct V_95 , V_242 ) ;
V_40 = V_2 -> V_42 -> V_256 ( V_96 ) ;
if ( ! V_40 )
V_96 -> V_195 ++ ;
return V_40 ;
}
int F_196 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_96 -> V_106 ;
if ( F_139 ( V_207 , & V_2 -> V_189 ) &&
! F_139 ( V_208 , & V_96 -> V_189 ) ) {
V_96 -> V_198 = V_270 ;
V_96 -> V_206 = - V_87 ;
return - V_204 ;
}
F_172 ( F_144 ( V_2 -> V_56 ) ) ;
V_40 = F_195 ( V_2 ) ;
if ( V_40 ) {
F_174 ( F_144 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
V_96 -> F_165 = F_182 ;
V_96 -> V_252 = V_277 ;
V_96 -> V_198 = V_225 ;
F_179 ( & V_96 -> V_242 , V_2 -> V_15 . V_227 ) ;
F_73 ( V_2 ) ;
F_174 ( F_144 ( V_2 -> V_56 ) ) ;
F_81 ( V_264 , F_183 ( V_96 ) ) ;
if ( V_96 -> V_198 == V_253 )
V_40 = 0 ;
else if ( V_96 -> V_206 )
V_40 = V_96 -> V_206 ;
else
V_40 = - V_204 ;
return V_40 ;
}
int F_192 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_106 ;
unsigned long V_189 ;
int V_40 ;
V_40 = 0 ;
F_124 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
switch ( V_96 -> V_198 ) {
case V_225 :
V_96 -> V_198 = V_239 ;
break;
case V_199 :
V_40 = V_2 -> V_42 -> V_256 ( V_96 ) ;
if ( V_40 ) {
F_136 ( & V_2 -> V_56 -> V_57 ,
L_85 ,
V_96 , V_40 ) ;
} else {
V_96 -> V_148 = F_135 () ;
}
break;
default:
break;
}
F_126 ( F_144 ( V_2 -> V_56 ) , V_189 ) ;
F_73 ( V_2 ) ;
return V_40 ;
}
static void V_39 ( unsigned long V_220 )
{
unsigned long V_189 ;
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_220 ;
F_124 ( F_144 ( V_34 -> V_63 -> V_56 ) , V_189 ) ;
F_145 ( V_34 -> V_63 , V_221 ) ;
F_126 ( F_144 ( V_34 -> V_63 -> V_56 ) , V_189 ) ;
F_58 ( V_34 ) ;
}
void F_197 ( struct V_33 * V_34 , int V_222 )
{
if ( V_222 == 0 )
F_147 ( & V_34 -> V_16 ) ;
else
F_148 ( & V_34 -> V_16 , V_210 + V_222 ) ;
}
void F_44 ( struct V_33 * V_34 )
{
F_147 ( & V_34 -> V_16 ) ;
}
static void F_186 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
T_6 V_266 ;
if ( V_96 -> V_198 == V_253 )
F_39 ( V_278 , V_2 , L_1 , L_86 ) ;
else
F_136 ( & V_2 -> V_56 -> V_57 , L_87 ) ;
V_266 = V_2 -> V_42 -> V_279 ( V_96 ) ;
V_266 ( V_96 ) ;
}
static void F_198 ( struct V_33 * V_34 )
{
struct V_280 * V_281 ;
struct V_97 * V_98 ;
struct V_95 * V_96 ;
struct V_1 * V_282 ;
unsigned long V_189 ;
V_281 = V_34 -> V_280 ;
V_282 = V_34 -> V_63 ;
if ( V_281 == NULL )
return;
if ( V_282 -> V_26 < V_69 ) {
while ( ( V_98 = F_199 ( V_34 -> V_280 ) ) )
F_200 ( V_98 , - V_204 ) ;
return;
}
while ( ( V_98 = F_201 ( V_281 ) ) ) {
if ( V_282 -> V_79 & V_283 &&
F_84 ( V_98 ) == V_284 ) {
F_39 ( V_182 , V_282 ,
L_88 ,
V_98 ) ;
F_202 ( V_98 ) ;
F_200 ( V_98 , - V_204 ) ;
continue;
}
V_96 = V_282 -> V_42 -> V_285 ( V_282 , V_34 , V_98 ) ;
if ( F_30 ( V_96 ) ) {
if ( F_102 ( V_96 ) == - V_205 )
break;
if ( F_102 ( V_96 ) == - V_4 )
break;
if ( F_102 ( V_96 ) == - V_65 ) {
if ( ! F_168 ( & V_34 -> V_15 ) )
break;
F_124 (
F_144 ( V_282 -> V_56 ) , V_189 ) ;
F_177 ( V_282 ,
V_221 ) ;
F_126 (
F_144 ( V_282 -> V_56 ) , V_189 ) ;
F_197 ( V_34 , V_257 / 2 ) ;
break;
}
F_39 ( V_182 , V_282 ,
L_89
L_90 ,
F_102 ( V_96 ) , V_98 ) ;
F_202 ( V_98 ) ;
F_200 ( V_98 , - V_204 ) ;
continue;
}
V_96 -> V_252 = ( void * ) V_98 ;
V_96 -> V_198 = V_267 ;
F_202 ( V_98 ) ;
F_181 ( & V_96 -> V_274 , & V_34 -> V_15 ) ;
F_82 ( V_34 , V_96 , V_98 ) ;
}
}
static void F_203 ( struct V_95 * V_96 )
{
struct V_97 * V_98 ;
int V_198 ;
int error = 0 ;
V_98 = (struct V_97 * ) V_96 -> V_252 ;
F_89 ( V_96 -> V_34 , V_96 , V_98 ) ;
V_198 = V_96 -> V_34 -> V_63 -> V_42 -> V_286 ( V_96 , V_98 ) ;
if ( V_198 <= 0 )
error = V_198 ? V_198 : - V_204 ;
F_200 ( V_98 , error ) ;
}
static void F_204 ( struct V_33 * V_34 ,
struct V_99 * V_251 )
{
struct V_99 * V_100 , * V_250 ;
struct V_95 * V_96 ;
T_6 V_266 ;
unsigned long V_189 ;
struct V_1 * V_63 = V_34 -> V_63 ;
V_287:
F_161 (l, n, &block->ccw_queue) {
V_96 = F_158 ( V_100 , struct V_95 , V_274 ) ;
if ( V_96 -> V_198 != V_253 &&
V_96 -> V_198 != V_270 &&
V_96 -> V_198 != V_254 &&
V_96 -> V_198 != V_255 )
continue;
if ( V_96 -> V_198 == V_255 ) {
V_63 -> V_42 -> V_268 ( V_96 ) ;
goto V_287;
}
if ( V_96 -> V_198 == V_254 ) {
V_266 = V_63 -> V_42 -> V_269 ( V_96 ) ;
if ( F_30 ( V_266 ( V_96 ) ) )
continue;
goto V_287;
}
if ( V_96 -> V_198 == V_270 ) {
F_185 ( V_96 , & V_96 -> V_226 ) ;
}
if ( F_190 ( V_63 ) &&
V_96 -> V_198 == V_270 ) {
F_205 ( V_63 , V_96 , V_288 ) ;
V_96 -> V_198 = V_267 ;
V_96 -> V_195 = 255 ;
F_124 ( F_144 ( V_63 -> V_56 ) , V_189 ) ;
F_177 ( V_63 , V_289 ) ;
F_126 ( F_144 ( V_63 -> V_56 ) ,
V_189 ) ;
goto V_287;
}
if ( V_96 -> V_271 ) {
F_186 ( V_63 , V_96 ) ;
goto V_287;
}
V_96 -> V_149 = F_135 () ;
F_163 ( & V_96 -> V_274 , V_251 ) ;
}
}
static void F_206 ( struct V_95 * V_96 , void * V_19 )
{
F_58 ( V_96 -> V_34 ) ;
}
static void F_207 ( struct V_33 * V_34 )
{
struct V_95 * V_96 ;
if ( F_168 ( & V_34 -> V_15 ) )
return;
F_208 (cqr, &block->ccw_queue, blocklist) {
if ( V_96 -> V_198 != V_267 )
continue;
if ( F_139 ( V_207 , & V_34 -> V_63 -> V_189 ) &&
! F_139 ( V_208 , & V_96 -> V_189 ) ) {
V_96 -> V_198 = V_270 ;
V_96 -> V_206 = - V_87 ;
F_58 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_243 & ~ V_221 &&
F_139 ( V_275 , & V_96 -> V_189 ) &&
( ! F_190 ( V_34 -> V_63 ) ) ) {
V_96 -> V_198 = V_270 ;
F_58 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_243 )
return;
if ( ! V_96 -> V_106 )
V_96 -> V_106 = V_34 -> V_63 ;
V_96 -> F_165 = F_206 ;
F_180 ( V_96 ) ;
}
}
static void V_37 ( struct V_33 * V_34 )
{
struct V_99 V_251 ;
struct V_99 * V_100 , * V_250 ;
struct V_95 * V_96 ;
F_10 ( & V_34 -> V_12 , 0 ) ;
F_12 ( & V_251 ) ;
F_85 ( & V_34 -> V_38 ) ;
F_204 ( V_34 , & V_251 ) ;
F_86 ( & V_34 -> V_38 ) ;
F_172 ( & V_34 -> V_36 ) ;
F_161 (l, n, &final_queue) {
V_96 = F_158 ( V_100 , struct V_95 , V_274 ) ;
F_166 ( & V_96 -> V_274 ) ;
F_203 ( V_96 ) ;
}
F_85 ( & V_34 -> V_38 ) ;
F_198 ( V_34 ) ;
F_207 ( V_34 ) ;
F_86 ( & V_34 -> V_38 ) ;
F_174 ( & V_34 -> V_36 ) ;
F_23 ( V_34 -> V_63 ) ;
}
static void F_209 ( struct V_95 * V_96 , void * V_19 )
{
F_69 ( & V_240 ) ;
}
static int F_53 ( struct V_33 * V_34 )
{
struct V_95 * V_96 , * V_250 ;
int V_40 , V_166 ;
struct V_99 V_261 ;
F_12 ( & V_261 ) ;
F_93 ( & V_34 -> V_38 ) ;
V_40 = 0 ;
V_287:
F_173 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_96 -> V_198 >= V_225 )
V_40 = F_192 ( V_96 ) ;
if ( V_40 < 0 )
break;
V_96 -> F_165 = F_209 ;
for ( V_166 = 0 ; V_96 != NULL ; V_96 = V_96 -> V_271 , V_166 ++ )
F_163 ( & V_96 -> V_274 , & V_261 ) ;
if ( V_166 > 1 )
goto V_287;
}
F_94 ( & V_34 -> V_38 ) ;
V_290:
F_173 (cqr, n, &flush_queue, blocklist) {
F_81 ( V_240 , ( V_96 -> V_198 < V_225 ) ) ;
if ( V_96 -> V_271 ) {
F_93 ( & V_34 -> V_38 ) ;
F_186 ( V_34 -> V_63 , V_96 ) ;
F_94 ( & V_34 -> V_38 ) ;
goto V_290;
}
F_172 ( & V_34 -> V_36 ) ;
V_96 -> V_149 = F_135 () ;
F_166 ( & V_96 -> V_274 ) ;
F_203 ( V_96 ) ;
F_174 ( & V_34 -> V_36 ) ;
}
return V_40 ;
}
void F_58 ( struct V_33 * V_34 )
{
if ( F_175 ( & V_34 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_34 -> V_63 ) ;
F_176 ( & V_34 -> V_13 ) ;
}
static void F_210 ( struct V_280 * V_281 )
{
struct V_33 * V_34 ;
V_34 = V_281 -> V_291 ;
F_85 ( & V_34 -> V_38 ) ;
F_198 ( V_34 ) ;
F_207 ( V_34 ) ;
F_86 ( & V_34 -> V_38 ) ;
}
static int F_22 ( struct V_33 * V_34 )
{
int V_40 ;
V_34 -> V_280 = F_211 ( F_210 ,
& V_34 -> V_36 ) ;
if ( V_34 -> V_280 == NULL )
return - V_4 ;
V_34 -> V_280 -> V_291 = V_34 ;
F_212 ( V_34 -> V_280 -> V_292 ) ;
V_34 -> V_280 -> V_292 = NULL ;
V_40 = F_213 ( V_34 -> V_280 , L_91 ) ;
if ( V_40 ) {
F_214 ( V_34 -> V_280 ) ;
return V_40 ;
}
return 0 ;
}
static void F_49 ( struct V_33 * V_34 )
{
int V_293 ;
if ( V_34 -> V_63 -> V_79 & V_80 ) {
V_293 = 2048 ;
} else {
V_293 = V_34 -> V_63 -> V_42 -> V_294 << V_34 -> V_68 ;
}
F_215 ( V_34 -> V_280 ,
V_34 -> V_70 ) ;
F_216 ( V_34 -> V_280 , V_293 ) ;
F_217 ( V_34 -> V_280 , - 1L ) ;
F_218 ( V_34 -> V_280 , V_9 ) ;
F_219 ( V_34 -> V_280 , V_9 - 1 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
if ( V_34 -> V_280 ) {
F_214 ( V_34 -> V_280 ) ;
V_34 -> V_280 = NULL ;
}
}
static void F_54 ( struct V_33 * V_34 )
{
struct V_97 * V_98 ;
if ( ! V_34 -> V_280 )
return;
F_172 ( & V_34 -> V_36 ) ;
while ( ( V_98 = F_199 ( V_34 -> V_280 ) ) )
F_200 ( V_98 , - V_204 ) ;
F_174 ( & V_34 -> V_36 ) ;
}
static int F_220 ( struct V_295 * V_83 , T_7 V_174 )
{
struct V_1 * V_63 ;
int V_40 ;
V_63 = F_221 ( V_83 -> V_84 ) ;
if ( ! V_63 )
return - V_203 ;
F_222 ( & V_63 -> V_34 -> V_35 ) ;
if ( F_139 ( V_247 , & V_63 -> V_189 ) ) {
V_40 = - V_203 ;
goto V_296;
}
if ( ! F_223 ( V_63 -> V_42 -> V_44 ) ) {
V_40 = - V_164 ;
goto V_296;
}
if ( V_94 ) {
F_224 ( & V_63 -> V_56 -> V_57 ,
L_92
L_93 ) ;
V_40 = - V_87 ;
goto V_246;
}
if ( V_63 -> V_26 <= V_62 ) {
F_39 ( V_182 , V_63 , L_94 ,
L_95 ) ;
V_40 = - V_203 ;
goto V_246;
}
if ( ( V_174 & V_297 ) &&
( F_139 ( V_298 , & V_63 -> V_189 ) ||
( V_63 -> V_79 & V_283 ) ) ) {
V_40 = - V_299 ;
goto V_246;
}
F_23 ( V_63 ) ;
return 0 ;
V_246:
F_26 ( V_63 -> V_42 -> V_44 ) ;
V_296:
F_225 ( & V_63 -> V_34 -> V_35 ) ;
F_23 ( V_63 ) ;
return V_40 ;
}
static int F_226 ( struct V_71 * V_72 , T_7 V_174 )
{
struct V_1 * V_63 ;
V_63 = F_221 ( V_72 ) ;
if ( ! V_63 )
return - V_203 ;
F_225 ( & V_63 -> V_34 -> V_35 ) ;
F_26 ( V_63 -> V_42 -> V_44 ) ;
F_23 ( V_63 ) ;
return 0 ;
}
static int F_227 ( struct V_295 * V_83 , struct V_300 * V_301 )
{
struct V_1 * V_63 ;
V_63 = F_221 ( V_83 -> V_84 ) ;
if ( ! V_63 )
return - V_203 ;
if ( ! V_63 -> V_42 ||
! V_63 -> V_42 -> V_302 ) {
F_23 ( V_63 ) ;
return - V_164 ;
}
V_63 -> V_42 -> V_302 ( V_63 -> V_34 , V_301 ) ;
V_301 -> V_303 = F_228 ( V_83 ) >> V_63 -> V_34 -> V_68 ;
F_23 ( V_63 ) ;
return 0 ;
}
static void
F_229 ( void )
{
#ifdef F_230
F_231 () ;
#endif
F_232 () ;
if ( V_304 != NULL ) {
F_233 ( V_304 ) ;
V_304 = NULL ;
}
F_234 () ;
F_235 () ;
if ( V_305 != NULL ) {
F_47 ( V_305 ) ;
V_305 = NULL ;
}
F_115 () ;
}
int F_236 ( struct V_1 * V_2 )
{
struct V_306 V_307 ;
struct V_308 V_309 ;
int V_40 ;
if ( ! V_310 )
return 0 ;
F_237 ( V_2 -> V_56 , & V_307 ) ;
memset ( & V_309 , 0 , sizeof( V_309 ) ) ;
V_309 . V_311 = V_307 . V_312 ;
V_309 . V_313 = sizeof( V_309 ) ;
V_40 = V_308 ( & V_309 ) ;
if ( V_40 == 0 || V_40 == 2 ) {
return V_309 . V_314 & 0x80 ;
} else {
F_117 ( V_60 , L_96 ,
V_307 . V_312 , V_40 ) ;
return 0 ;
}
}
static void F_238 ( void * V_19 , T_8 V_315 )
{
struct V_223 * V_56 = V_19 ;
int V_316 ;
V_316 = F_239 ( V_56 ) ;
if ( V_316 )
F_240 ( L_97 ,
F_35 ( & V_56 -> V_57 ) , V_316 ) ;
}
int F_241 ( struct V_223 * V_56 ,
struct V_317 * V_42 )
{
int V_316 ;
V_316 = F_242 ( V_56 ) ;
if ( V_316 ) {
F_150 ( V_60 , V_56 , L_1 ,
L_98
L_99 ) ;
return V_316 ;
}
V_56 -> V_318 = & F_154 ;
if ( ( F_243 ( V_56 , V_319 ) > 0 ) ||
( V_320 && F_244 ( F_35 ( & V_56 -> V_57 ) ) != 0 ) )
F_245 ( F_238 , V_56 ) ;
return 0 ;
}
void F_246 ( struct V_223 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_56 -> V_318 = NULL ;
F_247 ( V_56 ) ;
V_2 = F_248 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( F_249 ( V_247 , & V_2 -> V_189 ) ) {
F_23 ( V_2 ) ;
return;
}
F_78 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_250 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
}
int F_251 ( struct V_223 * V_56 ,
struct V_317 * V_45 )
{
struct V_317 * V_42 ;
struct V_1 * V_2 ;
int V_40 ;
F_252 ( V_56 , V_319 , 0 ) ;
V_2 = F_253 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_102 ( V_2 ) ;
V_42 = V_45 ;
if ( V_2 -> V_79 & V_321 ) {
if ( ! V_233 ) {
F_240 ( L_100
L_101 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_250 ( V_2 ) ;
return - V_203 ;
}
V_42 = V_233 ;
}
if ( ! F_223 ( V_45 -> V_44 ) ) {
F_250 ( V_2 ) ;
return - V_164 ;
}
if ( ! F_223 ( V_42 -> V_44 ) ) {
F_26 ( V_45 -> V_44 ) ;
F_250 ( V_2 ) ;
return - V_164 ;
}
V_2 -> V_45 = V_45 ;
V_2 -> V_42 = V_42 ;
V_40 = V_42 -> V_322 ( V_2 ) ;
if ( V_40 ) {
F_240 ( L_102
L_103 ,
F_35 ( & V_56 -> V_57 ) , V_42 -> V_47 , V_40 ) ;
F_26 ( V_42 -> V_44 ) ;
F_26 ( V_45 -> V_44 ) ;
F_250 ( V_2 ) ;
return V_40 ;
}
F_78 ( V_2 , V_78 ) ;
if ( V_2 -> V_26 <= V_41 ) {
F_240 ( L_104
L_105 , F_35 ( & V_56 -> V_57 ) ) ;
V_40 = - V_203 ;
F_78 ( V_2 , V_27 ) ;
if ( V_2 -> V_34 )
F_19 ( V_2 -> V_34 ) ;
F_250 ( V_2 ) ;
} else
F_254 ( L_106 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_81 ( V_88 , F_79 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_255 ( struct V_223 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_323 , V_35 ;
V_2 = F_248 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_102 ( V_2 ) ;
if ( F_249 ( V_247 , & V_2 -> V_189 ) ) {
F_23 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_34 ) {
V_323 = V_2 -> V_34 -> V_83 ? 0 : - 1 ;
V_35 = F_256 ( & V_2 -> V_34 -> V_35 ) ;
if ( V_35 > V_323 ) {
if ( V_35 > 0 )
F_240 ( L_107
L_108 ,
F_35 ( & V_56 -> V_57 ) , V_35 ) ;
else
F_240 ( L_107
L_109 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_257 ( V_247 , & V_2 -> V_189 ) ;
F_23 ( V_2 ) ;
return - V_205 ;
}
}
F_78 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_250 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
return 0 ;
}
int F_142 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
F_258 ( & V_2 -> V_56 -> V_57 , L_110
L_111 ) ;
F_39 ( V_60 , V_2 , L_1 , L_112 ) ;
F_205 ( V_2 , NULL , V_324 ) ;
if ( V_2 -> V_26 < V_62 )
return 0 ;
F_208 (cqr, &device->ccw_queue, devlist)
if ( ( V_96 -> V_198 == V_199 ) ||
( V_96 -> V_198 == V_200 ) ) {
V_96 -> V_198 = V_225 ;
V_96 -> V_195 ++ ;
}
F_177 ( V_2 , V_258 ) ;
F_46 ( V_2 ) ;
F_73 ( V_2 ) ;
return 1 ;
}
int F_259 ( struct V_1 * V_2 )
{
F_224 ( & V_2 -> V_56 -> V_57 , L_113
L_114 ) ;
F_39 ( V_60 , V_2 , L_1 , L_115 ) ;
F_145 ( V_2 , V_258 ) ;
if ( V_2 -> V_243 & V_259 ) {
F_145 ( V_2 , V_259 ) ;
F_77 ( V_2 ) ;
return 1 ;
}
F_73 ( V_2 ) ;
if ( V_2 -> V_34 )
F_58 ( V_2 -> V_34 ) ;
return 1 ;
}
int F_260 ( struct V_223 * V_56 , int V_325 )
{
struct V_1 * V_2 ;
int V_316 ;
V_2 = F_151 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return 0 ;
V_316 = 0 ;
switch ( V_325 ) {
case V_326 :
case V_327 :
case V_328 :
V_2 -> V_213 . V_214 = 0 ;
V_2 -> V_213 . V_217 = 0 ;
V_2 -> V_213 . V_218 = 0 ;
V_316 = F_142 ( V_2 ) ;
break;
case V_329 :
V_316 = 1 ;
if ( V_2 -> V_213 . V_214 )
V_316 = F_259 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_316 ;
}
void F_261 ( struct V_223 * V_56 , int * V_330 )
{
int V_331 ;
T_9 V_332 , V_333 ;
struct V_1 * V_2 ;
V_2 = F_151 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
for ( V_331 = 0 ; V_331 < 8 ; V_331 ++ ) {
V_333 = 0x80 >> V_331 ;
if ( V_330 [ V_331 ] & V_334 ) {
V_332 = V_2 -> V_213 . V_214 ;
V_2 -> V_213 . V_214 &= ~ V_333 ;
V_2 -> V_213 . V_217 &= ~ V_333 ;
V_2 -> V_213 . V_218 &= ~ V_333 ;
if ( V_332 && ! V_2 -> V_213 . V_214 )
F_142 ( V_2 ) ;
}
if ( V_330 [ V_331 ] & V_335 ) {
V_2 -> V_213 . V_214 &= ~ V_333 ;
V_2 -> V_213 . V_217 &= ~ V_333 ;
V_2 -> V_213 . V_218 &= ~ V_333 ;
V_2 -> V_213 . V_219 |= V_333 ;
F_73 ( V_2 ) ;
}
if ( V_330 [ V_331 ] & V_336 ) {
F_39 ( V_60 , V_2 , L_1 ,
L_116 ) ;
if ( V_2 -> V_42 -> V_337 )
V_2 -> V_42 -> V_337 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
int F_262 ( struct V_1 * V_2 , T_9 V_212 )
{
if ( ! V_2 -> V_213 . V_214 && V_212 ) {
V_2 -> V_213 . V_214 = V_212 ;
F_259 ( V_2 ) ;
} else
V_2 -> V_213 . V_214 |= V_212 ;
return 0 ;
}
int F_263 ( struct V_223 * V_56 )
{
struct V_95 * V_96 , * V_250 ;
int V_40 ;
struct V_99 V_338 ;
struct V_1 * V_2 = F_248 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_102 ( V_2 ) ;
F_122 ( V_339 , & V_2 -> V_189 ) ;
if ( V_2 -> V_42 -> V_340 )
V_40 = V_2 -> V_42 -> V_340 ( V_2 ) ;
F_177 ( V_2 , V_341 ) ;
F_12 ( & V_338 ) ;
F_172 ( F_144 ( V_56 ) ) ;
V_40 = 0 ;
F_173 (cqr, n, &device->ccw_queue, devlist) {
if ( V_96 -> V_198 == V_199 ) {
V_40 = V_2 -> V_42 -> V_256 ( V_96 ) ;
if ( V_40 ) {
F_136 ( & V_2 -> V_56 -> V_57 ,
L_117
L_118 , V_96 ) ;
F_174 ( F_144 ( V_56 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
}
F_163 ( & V_96 -> V_242 , & V_338 ) ;
}
F_174 ( F_144 ( V_56 ) ) ;
F_173 (cqr, n, &freeze_queue, devlist) {
F_81 ( V_240 ,
( V_96 -> V_198 != V_200 ) ) ;
if ( V_96 -> V_198 == V_239 )
V_96 -> V_198 = V_225 ;
}
F_172 ( F_144 ( V_56 ) ) ;
F_264 ( & V_338 , & V_2 -> V_15 ) ;
F_174 ( F_144 ( V_56 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_265 ( struct V_223 * V_56 )
{
struct V_1 * V_2 = F_248 ( V_56 ) ;
int V_40 = 0 ;
if ( F_30 ( V_2 ) )
return F_102 ( V_2 ) ;
F_145 ( V_2 ,
( V_341 | V_259 ) ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_42 -> V_93 && ! ( V_2 -> V_243 ) )
V_40 = V_2 -> V_42 -> V_93 ( V_2 ) ;
if ( V_40 || V_2 -> V_243 )
V_2 -> V_243 |= V_259 ;
if ( V_2 -> V_34 )
F_58 ( V_2 -> V_34 ) ;
F_257 ( V_339 , & V_2 -> V_189 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_95 * F_266 ( struct V_1 * V_2 ,
void * V_342 ,
int V_343 ,
int V_183 )
{
struct V_95 * V_96 ;
struct V_186 * V_191 ;
unsigned long * V_344 ;
V_96 = F_123 ( V_183 , 1 , V_343 , V_2 ) ;
if ( F_30 ( V_96 ) ) {
F_136 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , L_119 ) ;
return V_96 ;
}
V_191 = V_96 -> V_187 ;
V_191 -> V_345 = V_346 ;
if ( F_267 ( V_342 , V_343 ) ) {
V_344 = ( unsigned long * ) ( V_96 -> V_19 ) ;
V_191 -> V_347 = ( V_348 ) ( V_349 ) V_344 ;
V_191 -> V_189 = V_350 ;
V_344 = F_268 ( V_344 , V_342 , V_343 ) ;
} else {
V_191 -> V_347 = ( V_348 ) ( V_349 ) V_342 ;
V_191 -> V_189 = 0 ;
}
V_191 -> V_351 = V_343 ;
V_96 -> V_106 = V_2 ;
V_96 -> V_352 = V_2 ;
V_96 -> V_222 = 10 * V_257 ;
V_96 -> V_195 = 256 ;
V_96 -> V_146 = F_135 () ;
V_96 -> V_198 = V_267 ;
return V_96 ;
}
int F_269 ( struct V_1 * V_2 , int V_183 ,
void * V_342 , int V_343 )
{
int V_316 ;
struct V_95 * V_96 ;
V_96 = F_266 ( V_2 , V_342 , V_343 ,
V_183 ) ;
if ( F_30 ( V_96 ) )
return F_102 ( V_96 ) ;
V_316 = F_193 ( V_96 ) ;
F_130 ( V_96 , V_96 -> V_352 ) ;
return V_316 ;
}
char * F_270 ( struct V_226 * V_226 )
{
struct V_353 * V_353 = NULL ;
char * V_354 = NULL ;
if ( F_271 ( & V_226 -> V_230 ) && ( V_226 -> V_230 . V_355 . V_356 == 0x01 ) ) {
if ( V_226 -> V_230 . V_355 . V_357 )
V_353 = F_272 ( (struct V_357 * ) ( unsigned long )
V_226 -> V_230 . V_355 . V_357 ) ;
if ( V_353 && V_353 -> V_358 == 64 && V_353 -> V_189 )
switch ( V_353 -> V_189 & 0x07 ) {
case 1 :
V_354 = V_353 -> V_359 . V_360 . V_354 ;
break;
case 2 :
V_354 = V_353 -> V_359 . V_361 . V_354 ;
break;
default:
break;
}
} else if ( V_226 -> V_362 . V_363 . V_364 . V_365 ) {
V_354 = V_226 -> V_366 ;
}
return V_354 ;
}
static int T_10 F_273 ( void )
{
int V_40 ;
F_274 ( & V_88 ) ;
F_274 ( & V_240 ) ;
F_274 ( & V_264 ) ;
V_305 = F_36 ( L_33 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_305 == NULL ) {
V_40 = - V_4 ;
goto V_367;
}
F_37 ( V_305 , & V_59 ) ;
F_38 ( V_305 , V_60 ) ;
F_117 ( V_61 , L_1 , L_2 ) ;
V_233 = NULL ;
F_116 () ;
V_40 = F_275 () ;
if ( V_40 )
goto V_367;
V_40 = F_276 () ;
if ( V_40 )
goto V_367;
V_40 = F_277 () ;
if ( V_40 )
goto V_367;
V_40 = F_278 () ;
if ( V_40 )
goto V_367;
#ifdef F_230
V_40 = F_279 () ;
if ( V_40 )
goto V_367;
#endif
return 0 ;
V_367:
F_280 ( L_120 ) ;
F_229 () ;
return V_40 ;
}
