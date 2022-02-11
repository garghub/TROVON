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
static inline
int F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 )
return F_53 ( & V_2 -> V_15 ) &&
F_53 ( & V_2 -> V_34 -> V_15 ) ;
else
return F_53 ( & V_2 -> V_15 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_40 ;
V_2 -> V_26 = V_62 ;
if ( V_2 -> V_34 ) {
struct V_33 * V_34 = V_2 -> V_34 ;
V_40 = F_55 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_69 ;
return V_40 ;
}
F_56 ( V_34 ) ;
F_57 ( V_34 ) ;
V_34 -> V_67 = 0 ;
V_34 -> V_70 = 0 ;
V_34 -> V_68 = 0 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
V_2 -> V_26 = V_62 ;
return 0 ;
}
static int
F_59 ( struct V_1 * V_2 )
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
F_60 ( V_2 -> V_34 ) ;
if ( ( V_2 -> V_79 & V_80 ) ) {
V_72 = V_2 -> V_34 -> V_51 ;
F_61 ( & F_62 ( V_72 ) -> V_81 , V_82 ) ;
return 0 ;
}
V_72 = V_2 -> V_34 -> V_83 -> V_84 ;
F_63 ( & V_74 , V_72 , V_85 ) ;
while ( ( V_76 = F_64 ( & V_74 ) ) )
F_61 ( & F_65 ( V_76 ) -> V_81 , V_82 ) ;
F_66 ( & V_74 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
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
F_63 ( & V_74 , V_72 , V_85 ) ;
while ( ( V_76 = F_64 ( & V_74 ) ) )
F_61 ( & F_65 ( V_76 ) -> V_81 , V_82 ) ;
F_66 ( & V_74 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
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
V_40 = F_59 ( V_2 ) ;
return V_40 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_78 &&
V_2 -> V_28 <= V_69 )
V_40 = F_67 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_69 &&
V_2 -> V_28 <= V_62 )
V_40 = F_54 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_66 &&
V_2 -> V_28 <= V_62 )
V_40 = F_58 ( V_2 ) ;
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
static void F_70 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_26 == V_2 -> V_28 )
return;
if ( V_2 -> V_26 < V_2 -> V_28 )
V_40 = F_68 ( V_2 ) ;
else
V_40 = F_69 ( V_2 ) ;
if ( V_40 == - V_65 )
return;
if ( V_40 )
V_2 -> V_28 = V_2 -> V_26 ;
F_61 ( & V_2 -> V_56 -> V_57 . V_81 , V_82 ) ;
if ( V_2 -> V_26 == V_2 -> V_28 )
F_71 ( & V_88 ) ;
}
static void V_21 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_90 , struct V_1 , V_20 ) ;
F_73 ( & V_2 -> V_29 ) ;
F_70 ( V_2 ) ;
F_74 ( & V_2 -> V_29 ) ;
F_75 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_77 ( & V_2 -> V_20 ) ;
}
static void V_25 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_90 , struct V_1 ,
V_24 ) ;
V_2 -> V_42 -> V_91 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_77 ( & V_2 -> V_24 ) ;
}
static void V_23 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_90 , struct V_1 ,
V_22 ) ;
V_2 -> V_56 -> V_92 -> V_93 ( V_2 -> V_56 ) ;
F_23 ( V_2 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_77 ( & V_2 -> V_22 ) ;
}
void F_80 ( struct V_1 * V_2 , int V_28 )
{
F_21 ( V_2 ) ;
F_73 ( & V_2 -> V_29 ) ;
if ( V_94 && V_28 > V_69 )
V_28 = V_69 ;
if ( V_2 -> V_28 != V_28 ) {
if ( V_2 -> V_26 == V_28 )
F_71 ( & V_88 ) ;
V_2 -> V_28 = V_28 ;
}
if ( V_2 -> V_26 != V_2 -> V_28 )
F_70 ( V_2 ) ;
F_74 ( & V_2 -> V_29 ) ;
F_23 ( V_2 ) ;
}
static inline int F_81 ( struct V_1 * V_2 )
{
return ( V_2 -> V_26 == V_2 -> V_28 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_80 ( V_2 , V_78 ) ;
if ( V_2 -> V_26 <= V_41 )
F_80 ( V_2 , V_27 ) ;
F_83 ( V_88 , F_81 ( V_2 ) ) ;
F_78 ( V_2 ) ;
if ( V_2 -> V_42 -> V_95 )
V_2 -> V_42 -> V_95 ( V_2 ) ;
}
static void F_84 ( struct V_33 * V_34 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 ;
unsigned int V_102 ;
struct V_1 * V_2 ;
V_102 = 0 ;
if ( V_54 || V_34 -> V_30 . V_19 )
F_85 (l, &block->ccw_queue)
if ( ++ V_102 >= 31 )
break;
if ( V_54 ) {
V_103 . V_104 [ V_102 ] ++ ;
if ( F_86 ( V_99 ) == V_105 )
V_103 . V_106 [ V_102 ] ++ ;
}
F_87 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
V_34 -> V_30 . V_19 -> V_104 [ V_102 ] ++ ;
if ( F_86 ( V_99 ) == V_105 )
V_34 -> V_30 . V_19 -> V_106 [ V_102 ] ++ ;
F_88 ( & V_34 -> V_30 . V_31 ) ;
V_2 = V_97 -> V_107 ;
if ( V_2 -> V_30 . V_19 ) {
V_102 = 1 ;
F_85 (l, &device->ccw_queue)
if ( ++ V_102 >= 31 )
break;
}
F_87 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 ) {
V_2 -> V_30 . V_19 -> V_104 [ V_102 ] ++ ;
if ( F_86 ( V_99 ) == V_105 )
V_2 -> V_30 . V_19 -> V_106 [ V_102 ] ++ ;
}
F_88 ( & V_2 -> V_30 . V_31 ) ;
}
static void F_89 ( struct V_108 * V_19 ,
int V_109 ,
int V_110 ,
int V_111 ,
long V_112 ,
int V_113 ,
int V_114 ,
int V_115 ,
int V_116 ,
int V_117 ,
int V_118 ,
int V_119 )
{
if ( V_19 -> V_120 == V_121 ) {
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_90 ( & V_19 -> V_122 ) ;
}
V_19 -> V_120 ++ ;
V_19 -> V_123 += V_112 ;
if ( V_109 )
V_19 -> V_124 ++ ;
if ( V_110 )
V_19 -> V_125 ++ ;
V_19 -> V_126 [ V_113 ] ++ ;
V_19 -> V_127 [ V_114 ] ++ ;
V_19 -> V_128 [ V_115 ] ++ ;
V_19 -> V_129 [ V_116 ] ++ ;
V_19 -> V_130 [ V_117 ] ++ ;
V_19 -> V_131 [ V_118 ] ++ ;
V_19 -> V_132 [ V_119 ] ++ ;
if ( V_111 ) {
V_19 -> V_133 ++ ;
V_19 -> V_134 += V_112 ;
if ( V_109 )
V_19 -> V_135 ++ ;
if ( V_110 )
V_19 -> V_136 ++ ;
V_19 -> V_137 [ V_113 ] ++ ;
V_19 -> V_138 [ V_114 ] ++ ;
V_19 -> V_139 [ V_116 ] ++ ;
V_19 -> V_140 [ V_117 ] ++ ;
V_19 -> V_141 [ V_119 ] ++ ;
}
}
static void F_91 ( struct V_33 * V_34 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
long V_142 , V_143 , V_144 , V_145 ;
long V_146 , V_112 ;
struct V_1 * V_2 ;
int V_113 , V_114 , V_115 , V_116 ;
int V_117 , V_118 , V_119 ;
V_2 = V_97 -> V_107 ;
if ( ! ( V_54 ||
V_34 -> V_30 . V_19 ||
V_2 -> V_30 . V_19 ) )
return;
V_112 = F_92 ( V_99 ) ;
if ( ! V_97 -> V_147 || ! V_97 -> V_148 ||
! V_97 -> V_149 || ! V_97 -> V_150 ||
! V_112 )
return;
V_142 = ( ( V_97 -> V_148 - V_97 -> V_147 ) >> 12 ) ;
V_143 = ( ( V_97 -> V_149 - V_97 -> V_148 ) >> 12 ) ;
V_144 = ( ( V_97 -> V_150 - V_97 -> V_149 ) >> 12 ) ;
V_145 = ( ( V_97 -> V_150 - V_97 -> V_147 ) >> 12 ) ;
V_146 = V_145 / V_112 ;
F_93 ( V_112 , V_113 ) ;
F_93 ( V_145 , V_114 ) ;
F_93 ( V_146 , V_115 ) ;
F_93 ( V_142 , V_116 ) ;
F_93 ( V_143 , V_117 ) ;
F_93 ( V_143 / V_112 , V_118 ) ;
F_93 ( V_144 , V_119 ) ;
if ( V_54 ) {
F_89 ( & V_103 ,
V_97 -> V_107 != V_34 -> V_63 ,
V_97 -> V_151 == 1 ,
F_86 ( V_99 ) == V_105 ,
V_112 , V_113 , V_114 ,
V_115 , V_116 ,
V_117 , V_118 ,
V_119 ) ;
}
F_87 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
F_89 ( V_34 -> V_30 . V_19 ,
V_97 -> V_107 != V_34 -> V_63 ,
V_97 -> V_151 == 1 ,
F_86 ( V_99 ) == V_105 ,
V_112 , V_113 , V_114 ,
V_115 , V_116 ,
V_117 , V_118 ,
V_119 ) ;
F_88 ( & V_34 -> V_30 . V_31 ) ;
F_87 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 )
F_89 ( V_2 -> V_30 . V_19 ,
V_97 -> V_107 != V_34 -> V_63 ,
V_97 -> V_151 == 1 ,
F_86 ( V_99 ) == V_105 ,
V_112 , V_113 , V_114 ,
V_115 , V_116 ,
V_117 , V_118 ,
V_119 ) ;
F_88 ( & V_2 -> V_30 . V_31 ) ;
}
void F_94 ( struct V_152 * V_30 )
{
struct V_108 * V_19 ;
F_95 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_96 ( & V_30 -> V_31 ) ;
return;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_90 ( & V_19 -> V_122 ) ;
F_96 ( & V_30 -> V_31 ) ;
}
void F_97 ( void )
{
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
F_90 ( & V_103 . V_122 ) ;
}
int F_34 ( struct V_152 * V_30 )
{
struct V_108 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_153 ) ;
if ( ! V_19 )
return - V_4 ;
F_95 ( & V_30 -> V_31 ) ;
if ( V_30 -> V_19 ) {
F_96 ( & V_30 -> V_31 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_90 ( & V_19 -> V_122 ) ;
V_30 -> V_19 = V_19 ;
F_96 ( & V_30 -> V_31 ) ;
return 0 ;
}
void F_98 ( struct V_152 * V_30 )
{
F_95 ( & V_30 -> V_31 ) ;
F_5 ( V_30 -> V_19 ) ;
V_30 -> V_19 = NULL ;
F_96 ( & V_30 -> V_31 ) ;
}
char * F_99 ( const char T_1 * V_154 , T_2 V_155 )
{
char * V_156 ;
V_156 = F_100 ( V_155 + 1 ) ;
if ( V_156 == NULL )
return F_3 ( - V_4 ) ;
if ( F_101 ( V_156 , V_154 , V_155 ) != 0 ) {
F_102 ( V_156 ) ;
return F_3 ( - V_157 ) ;
}
if ( V_156 [ V_155 - 1 ] == '\n' )
V_156 [ V_155 - 1 ] = 0 ;
else
V_156 [ V_155 ] = 0 ;
return V_156 ;
}
static T_3 F_103 ( struct V_158 * V_158 ,
const char T_1 * V_154 ,
T_2 V_155 , T_4 * V_159 )
{
char * V_156 , * V_160 ;
int V_40 ;
struct V_161 * V_162 = (struct V_161 * ) V_158 -> V_163 ;
struct V_152 * V_164 = V_162 -> V_32 ;
if ( V_155 > 65536 )
V_155 = 65536 ;
V_156 = F_99 ( V_154 , V_155 ) ;
if ( F_30 ( V_156 ) )
return F_104 ( V_156 ) ;
V_160 = F_105 ( V_156 ) ;
V_40 = V_155 ;
if ( strncmp ( V_160 , L_4 , 5 ) == 0 ) {
F_94 ( V_164 ) ;
} else if ( strncmp ( V_160 , L_5 , 2 ) == 0 ) {
V_40 = F_34 ( V_164 ) ;
if ( ! V_40 )
V_40 = V_155 ;
} else if ( strncmp ( V_160 , L_6 , 3 ) == 0 ) {
F_98 ( V_164 ) ;
} else
V_40 = - V_165 ;
F_102 ( V_156 ) ;
return V_40 ;
}
static void F_106 ( struct V_161 * V_162 , unsigned int * V_166 )
{
int V_167 ;
for ( V_167 = 0 ; V_167 < 32 ; V_167 ++ )
F_107 ( V_162 , L_7 , V_166 [ V_167 ] ) ;
F_108 ( V_162 , '\n' ) ;
}
static void F_109 ( struct V_161 * V_162 ,
struct V_108 * V_19 )
{
F_107 ( V_162 , L_8 ,
V_19 -> V_122 . V_168 , V_19 -> V_122 . V_169 ) ;
F_107 ( V_162 , L_9 , V_19 -> V_120 ) ;
F_107 ( V_162 , L_10 , V_19 -> V_123 ) ;
F_107 ( V_162 , L_11 , V_19 -> V_124 ) ;
F_107 ( V_162 , L_12 , V_19 -> V_125 ) ;
F_107 ( V_162 , L_13 ) ;
F_106 ( V_162 , V_19 -> V_126 ) ;
F_107 ( V_162 , L_14 ) ;
F_106 ( V_162 , V_19 -> V_127 ) ;
F_107 ( V_162 , L_15 ) ;
F_106 ( V_162 , V_19 -> V_128 ) ;
F_107 ( V_162 , L_16 ) ;
F_106 ( V_162 , V_19 -> V_129 ) ;
F_107 ( V_162 , L_17 ) ;
F_106 ( V_162 , V_19 -> V_130 ) ;
F_107 ( V_162 , L_18 ) ;
F_106 ( V_162 , V_19 -> V_131 ) ;
F_107 ( V_162 , L_19 ) ;
F_106 ( V_162 , V_19 -> V_132 ) ;
F_107 ( V_162 , L_20 ) ;
F_106 ( V_162 , V_19 -> V_104 ) ;
F_107 ( V_162 , L_21 , V_19 -> V_133 ) ;
F_107 ( V_162 , L_22 , V_19 -> V_134 ) ;
F_107 ( V_162 , L_23 , V_19 -> V_135 ) ;
F_107 ( V_162 , L_24 , V_19 -> V_136 ) ;
F_107 ( V_162 , L_25 ) ;
F_106 ( V_162 , V_19 -> V_137 ) ;
F_107 ( V_162 , L_26 ) ;
F_106 ( V_162 , V_19 -> V_138 ) ;
F_107 ( V_162 , L_27 ) ;
F_106 ( V_162 , V_19 -> V_139 ) ;
F_107 ( V_162 , L_28 ) ;
F_106 ( V_162 , V_19 -> V_140 ) ;
F_107 ( V_162 , L_29 ) ;
F_106 ( V_162 , V_19 -> V_141 ) ;
F_107 ( V_162 , L_30 ) ;
F_106 ( V_162 , V_19 -> V_106 ) ;
}
static int F_110 ( struct V_161 * V_162 , void * V_170 )
{
struct V_152 * V_30 ;
struct V_108 * V_19 ;
V_30 = V_162 -> V_32 ;
F_95 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_96 ( & V_30 -> V_31 ) ;
F_107 ( V_162 , L_31 ) ;
return 0 ;
}
F_109 ( V_162 , V_19 ) ;
F_96 ( & V_30 -> V_31 ) ;
return 0 ;
}
static int F_111 ( struct V_171 * V_171 , struct V_158 * V_158 )
{
struct V_152 * V_30 = V_171 -> V_172 ;
return F_112 ( V_158 , F_110 , V_30 ) ;
}
static T_3 F_113 ( struct V_158 * V_158 ,
const char T_1 * V_154 ,
T_2 V_155 , T_4 * V_159 )
{
char * V_156 , * V_160 ;
T_3 V_40 ;
if ( V_155 > 65536 )
V_155 = 65536 ;
V_156 = F_99 ( V_154 , V_155 ) ;
if ( F_30 ( V_156 ) )
return F_104 ( V_156 ) ;
V_160 = F_105 ( V_156 ) ;
V_40 = V_155 ;
if ( strncmp ( V_160 , L_4 , 5 ) == 0 ) {
F_97 () ;
} else if ( strncmp ( V_160 , L_5 , 2 ) == 0 ) {
F_97 () ;
V_54 = V_173 ;
} else if ( strncmp ( V_160 , L_6 , 3 ) == 0 ) {
V_54 = V_174 ;
} else
V_40 = - V_165 ;
F_102 ( V_156 ) ;
return V_40 ;
}
static int F_114 ( struct V_161 * V_162 , void * V_170 )
{
if ( ! V_54 ) {
F_107 ( V_162 , L_31 ) ;
return 0 ;
}
F_109 ( V_162 , & V_103 ) ;
return 0 ;
}
static int F_115 ( struct V_171 * V_171 , struct V_158 * V_158 )
{
return F_112 ( V_158 , F_114 , NULL ) ;
}
static void F_33 ( struct V_152 * V_30 ,
struct V_46 * V_48 )
{
T_5 V_175 ;
struct V_46 * V_49 ;
if ( ! V_48 )
return;
V_30 -> V_46 = NULL ;
V_30 -> V_19 = NULL ;
V_175 = ( V_176 | V_177 | V_178 ) ;
V_49 = F_116 ( L_32 , V_175 , V_48 ,
V_30 , & V_179 ) ;
if ( V_49 && ! F_30 ( V_49 ) )
V_30 -> V_46 = V_49 ;
return;
}
static void F_41 ( struct V_152 * V_30 )
{
F_98 ( V_30 ) ;
if ( V_30 -> V_46 ) {
F_42 ( V_30 -> V_46 ) ;
V_30 -> V_46 = NULL ;
}
}
static void F_117 ( void )
{
V_54 = V_174 ;
if ( V_180 ) {
F_42 ( V_180 ) ;
V_180 = NULL ;
}
if ( V_181 )
F_42 ( V_181 ) ;
if ( V_53 )
F_42 ( V_53 ) ;
}
static void F_118 ( void )
{
T_5 V_175 ;
struct V_46 * V_49 ;
V_53 = NULL ;
V_181 = NULL ;
V_180 = NULL ;
V_49 = F_29 ( L_33 , NULL ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_53 = V_49 ;
V_49 = F_29 ( L_34 , V_53 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_181 = V_49 ;
V_175 = ( V_176 | V_177 | V_178 ) ;
V_49 = F_116 ( L_32 , V_175 , V_181 ,
NULL , & V_182 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_180 = V_49 ;
return;
error:
F_119 ( V_183 , L_1 ,
L_35 ) ;
F_117 () ;
return;
}
static void F_118 ( void )
{
return;
}
static void F_117 ( void )
{
return;
}
int F_120 ( struct V_161 * V_162 , void * V_170 )
{
F_107 ( V_162 , L_36 ) ;
return 0 ;
}
static void F_33 ( struct V_152 * V_30 ,
struct V_46 * V_48 )
{
return;
}
static void F_41 ( struct V_152 * V_30 )
{
return;
}
int F_34 ( struct V_152 * V_30 )
{
return 0 ;
}
struct V_96 * F_121 ( int V_184 , int V_185 ,
int V_186 ,
struct V_1 * V_2 )
{
struct V_96 * V_97 ;
F_122 ( V_186 > V_9 ||
( V_185 * sizeof( struct V_187 ) ) > V_9 ) ;
V_97 = F_2 ( sizeof( struct V_96 ) , V_3 ) ;
if ( V_97 == NULL )
return F_3 ( - V_4 ) ;
V_97 -> V_188 = NULL ;
if ( V_185 > 0 ) {
V_97 -> V_188 = F_123 ( V_185 , sizeof( struct V_187 ) ,
V_3 | V_6 ) ;
if ( V_97 -> V_188 == NULL ) {
F_5 ( V_97 ) ;
return F_3 ( - V_4 ) ;
}
}
V_97 -> V_19 = NULL ;
if ( V_186 > 0 ) {
V_97 -> V_19 = F_2 ( V_186 , V_3 | V_6 ) ;
if ( V_97 -> V_19 == NULL ) {
F_5 ( V_97 -> V_188 ) ;
F_5 ( V_97 ) ;
return F_3 ( - V_4 ) ;
}
}
V_97 -> V_184 = V_184 ;
F_124 ( V_189 , & V_97 -> V_190 ) ;
F_21 ( V_2 ) ;
return V_97 ;
}
struct V_96 * F_125 ( int V_184 , int V_185 ,
int V_186 ,
struct V_1 * V_2 )
{
unsigned long V_190 ;
struct V_96 * V_97 ;
char * V_19 ;
int V_191 ;
V_191 = ( sizeof( struct V_96 ) + 7L ) & - 8L ;
if ( V_185 > 0 )
V_191 += V_185 * sizeof( struct V_187 ) ;
if ( V_186 > 0 )
V_191 += V_186 ;
F_126 ( & V_2 -> V_11 , V_190 ) ;
V_97 = (struct V_96 * )
F_127 ( & V_2 -> V_8 , V_191 ) ;
F_128 ( & V_2 -> V_11 , V_190 ) ;
if ( V_97 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_97 , 0 , sizeof( struct V_96 ) ) ;
V_19 = ( char * ) V_97 + ( ( sizeof( struct V_96 ) + 7L ) & - 8L ) ;
V_97 -> V_188 = NULL ;
if ( V_185 > 0 ) {
V_97 -> V_188 = (struct V_187 * ) V_19 ;
V_19 += V_185 * sizeof( struct V_187 ) ;
memset ( V_97 -> V_188 , 0 , V_185 * sizeof( struct V_187 ) ) ;
}
V_97 -> V_19 = NULL ;
if ( V_186 > 0 ) {
V_97 -> V_19 = V_19 ;
memset ( V_97 -> V_19 , 0 , V_186 ) ;
}
V_97 -> V_184 = V_184 ;
F_124 ( V_189 , & V_97 -> V_190 ) ;
F_21 ( V_2 ) ;
return V_97 ;
}
void F_129 ( struct V_96 * V_97 , struct V_1 * V_2 )
{
#ifdef F_130
struct V_187 * V_192 ;
V_192 = V_97 -> V_188 ;
do {
F_131 ( V_192 ) ;
} while ( V_192 ++ -> V_190 & ( V_193 | V_194 ) );
#endif
F_5 ( V_97 -> V_188 ) ;
F_5 ( V_97 -> V_19 ) ;
F_5 ( V_97 ) ;
F_23 ( V_2 ) ;
}
void F_132 ( struct V_96 * V_97 , struct V_1 * V_2 )
{
unsigned long V_190 ;
F_126 ( & V_2 -> V_11 , V_190 ) ;
F_133 ( & V_2 -> V_8 , V_97 ) ;
F_128 ( & V_2 -> V_11 , V_190 ) ;
F_23 ( V_2 ) ;
}
static inline int F_134 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
if ( V_97 == NULL )
return - V_165 ;
V_2 = V_97 -> V_107 ;
if ( strncmp ( ( char * ) & V_97 -> V_184 , V_2 -> V_42 -> V_195 , 4 ) ) {
F_39 ( V_60 , V_2 ,
L_37
L_38 ,
V_97 -> V_184 ,
* ( unsigned int * ) V_2 -> V_42 -> V_47 ) ;
return - V_165 ;
}
return 0 ;
}
int F_135 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_196 , V_40 ;
char V_197 [ V_198 ] ;
V_40 = F_134 ( V_97 ) ;
if ( V_40 )
return V_40 ;
V_196 = 0 ;
V_2 = (struct V_1 * ) V_97 -> V_107 ;
while ( ( V_196 < 5 ) && ( V_97 -> V_199 == V_200 ) ) {
V_40 = F_136 ( V_2 -> V_56 , ( long ) V_97 ) ;
switch ( V_40 ) {
case 0 :
V_97 -> V_199 = V_201 ;
V_97 -> V_149 = F_137 () ;
V_97 -> V_202 = 0 ;
F_39 ( V_203 , V_2 ,
L_39 ,
V_97 ) ;
break;
case - V_204 :
F_39 ( V_183 , V_2 , L_1 ,
L_40 ) ;
break;
case - V_205 :
F_39 ( V_183 , V_2 , L_1 ,
L_41 ) ;
break;
case - V_165 :
case - V_206 :
F_39 ( V_183 , V_2 , L_1 ,
L_42 ) ;
break;
default:
snprintf ( V_197 , V_198 , L_43 , V_40 ) ;
F_138 ( & V_2 -> V_56 -> V_57 , L_44
L_45 , V_197 ) ;
F_139 () ;
break;
}
V_196 ++ ;
}
F_75 ( V_2 ) ;
return V_40 ;
}
int F_140 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_40 ;
char V_197 [ V_198 ] ;
V_40 = F_134 ( V_97 ) ;
if ( V_40 ) {
V_97 -> V_207 = V_40 ;
return V_40 ;
}
V_2 = (struct V_1 * ) V_97 -> V_107 ;
if ( ( ( V_97 -> V_34 &&
F_141 ( V_208 , & V_97 -> V_34 -> V_63 -> V_190 ) ) ||
F_141 ( V_208 , & V_2 -> V_190 ) ) &&
! F_141 ( V_209 , & V_97 -> V_190 ) ) {
F_39 ( V_203 , V_2 , L_46
L_47 , V_97 ) ;
V_97 -> V_199 = V_210 ;
V_97 -> V_207 = - V_87 ;
return - V_87 ;
}
if ( V_97 -> V_196 < 0 ) {
sprintf ( V_197 , L_48 , V_97 ) ;
F_138 ( & V_2 -> V_56 -> V_57 , L_49
L_50 , V_197 ) ;
V_97 -> V_199 = V_210 ;
return - V_205 ;
}
V_97 -> V_148 = F_137 () ;
V_97 -> V_202 = V_211 ;
V_97 -> V_196 -- ;
if ( ! F_141 ( V_212 , & V_97 -> V_190 ) ) {
V_97 -> V_213 &= V_2 -> V_214 . V_215 ;
if ( ! V_97 -> V_213 )
V_97 -> V_213 = V_2 -> V_214 . V_215 ;
}
if ( V_97 -> V_151 == 1 ) {
V_40 = F_142 ( V_2 -> V_56 , V_97 -> V_188 ,
( long ) V_97 , V_97 -> V_213 ) ;
} else {
V_40 = F_143 ( V_2 -> V_56 , V_97 -> V_188 ,
( long ) V_97 , V_97 -> V_213 , 0 ) ;
}
switch ( V_40 ) {
case 0 :
V_97 -> V_199 = V_200 ;
break;
case - V_206 :
F_39 ( V_60 , V_2 , L_1 ,
L_51 ) ;
break;
case - V_216 :
F_39 ( V_60 , V_2 , L_1 ,
L_52 ) ;
break;
case - V_217 :
if ( F_141 ( V_212 , & V_97 -> V_190 ) ) {
F_39 ( V_60 , V_2 ,
L_53 ,
V_97 -> V_213 ) ;
} else if ( V_97 -> V_213 != V_2 -> V_214 . V_215 ) {
V_97 -> V_213 = V_2 -> V_214 . V_215 ;
F_39 ( V_203 , V_2 , L_1 ,
L_54
L_55 ) ;
} else {
F_39 ( V_60 , V_2 , L_1 ,
L_56
L_57 ) ;
F_144 ( V_2 ) ;
V_2 -> V_214 . V_215 = 0 ;
V_2 -> V_214 . V_218 = 0 ;
V_2 -> V_214 . V_219 = 0 ;
V_2 -> V_214 . V_220 =
F_145 ( V_2 -> V_56 ) ;
}
break;
case - V_204 :
F_39 ( V_60 , V_2 , L_1 ,
L_58 ) ;
break;
case - V_205 :
F_39 ( V_60 , V_2 , L_1 ,
L_59 ) ;
break;
case - V_165 :
F_39 ( V_60 , V_2 , L_1 ,
L_60
L_61 ) ;
break;
default:
snprintf ( V_197 , V_198 , L_62 , V_40 ) ;
F_138 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , V_197 ) ;
F_139 () ;
break;
}
V_97 -> V_207 = V_40 ;
return V_40 ;
}
static void V_18 ( unsigned long V_221 )
{
unsigned long V_190 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_221 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
F_147 ( V_2 , V_222 ) ;
F_128 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
F_75 ( V_2 ) ;
}
void F_148 ( struct V_1 * V_2 , int V_223 )
{
if ( V_223 == 0 )
F_149 ( & V_2 -> V_16 ) ;
else
F_150 ( & V_2 -> V_16 , V_211 + V_223 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_149 ( & V_2 -> V_16 ) ;
}
static void F_151 ( struct V_224 * V_56 ,
unsigned long V_225 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 ;
if ( ! V_225 )
return;
V_97 = (struct V_96 * ) V_225 ;
if ( V_97 -> V_199 != V_200 ) {
F_152 ( V_203 , V_56 ,
L_65
L_66 , V_97 -> V_199 ) ;
return;
}
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_152 ( V_203 , V_56 , L_1 ,
L_67 ) ;
return;
}
if ( ! V_97 -> V_107 ||
V_2 != V_97 -> V_107 ||
strncmp ( V_97 -> V_107 -> V_42 -> V_195 ,
( char * ) & V_97 -> V_184 , 4 ) ) {
F_152 ( V_203 , V_56 , L_1 ,
L_68 ) ;
F_23 ( V_2 ) ;
return;
}
V_97 -> V_199 = V_226 ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_154 ( struct V_1 * V_2 )
{
F_155 ( V_2 ) ;
F_147 ( V_2 , V_222 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
}
void F_156 ( struct V_224 * V_56 , unsigned long V_225 ,
struct V_227 * V_227 )
{
struct V_96 * V_97 , * V_228 ;
struct V_1 * V_2 ;
unsigned long long V_229 ;
int V_223 ;
if ( F_30 ( V_227 ) ) {
switch ( F_104 ( V_227 ) ) {
case - V_205 :
break;
case - V_216 :
F_152 ( V_60 , V_56 , L_69
L_70 , V_230 ) ;
break;
default:
F_152 ( V_60 , V_56 , L_69
L_71 , V_230 ,
F_104 ( V_227 ) ) ;
}
F_151 ( V_56 , V_225 ) ;
return;
}
V_229 = F_137 () ;
V_97 = (struct V_96 * ) V_225 ;
if ( ! V_97 ||
! ( F_157 ( & V_227 -> V_231 ) == ( V_232 | V_233 ) &&
F_158 ( & V_227 -> V_231 ) == 0 ) ) {
if ( V_97 )
memcpy ( & V_97 -> V_227 , V_227 , sizeof( * V_227 ) ) ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_42 == V_234 ) {
F_23 ( V_2 ) ;
return;
}
V_2 -> V_42 -> V_235 ( V_2 , V_227 , L_72 ) ;
if ( V_2 -> V_79 & V_236 )
V_2 -> V_42 -> V_237 ( V_2 , V_97 , V_227 ) ;
V_2 -> V_42 -> V_238 ( V_2 , V_97 , V_227 ) ;
F_23 ( V_2 ) ;
}
if ( ! V_97 )
return;
V_2 = (struct V_1 * ) V_97 -> V_107 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_42 -> V_195 , ( char * ) & V_97 -> V_184 , 4 ) ) {
F_152 ( V_203 , V_56 , L_1 ,
L_68 ) ;
return;
}
if ( V_97 -> V_199 == V_201 &&
F_159 ( & V_227 -> V_231 ) & V_239 ) {
V_97 -> V_199 = V_240 ;
F_46 ( V_2 ) ;
F_71 ( & V_241 ) ;
F_75 ( V_2 ) ;
return;
}
if ( V_97 -> V_199 != V_200 ) {
F_39 ( V_203 , V_2 , L_73
L_74 , F_35 ( & V_56 -> V_57 ) , V_97 -> V_199 ) ;
return;
}
V_228 = NULL ;
V_223 = 0 ;
if ( F_157 ( & V_227 -> V_231 ) == ( V_232 | V_233 ) &&
F_158 ( & V_227 -> V_231 ) == 0 ) {
V_97 -> V_199 = V_242 ;
V_97 -> V_149 = V_229 ;
if ( V_97 -> V_243 . V_228 != & V_2 -> V_15 ) {
V_228 = F_160 ( V_97 -> V_243 . V_228 ,
struct V_96 , V_243 ) ;
}
} else {
if ( ! F_141 ( V_189 , & V_97 -> V_190 ) &&
V_97 -> V_196 > 0 ) {
if ( V_97 -> V_213 == V_2 -> V_214 . V_215 )
F_39 ( V_203 , V_2 ,
L_75
L_76 ,
V_97 -> V_196 ) ;
if ( ! F_141 ( V_212 , & V_97 -> V_190 ) )
V_97 -> V_213 = V_2 -> V_214 . V_215 ;
V_97 -> V_199 = V_226 ;
V_228 = V_97 ;
} else
V_97 -> V_199 = V_210 ;
}
if ( V_228 && ( V_228 -> V_199 == V_226 ) &&
( ! V_2 -> V_244 ) ) {
if ( V_2 -> V_42 -> V_245 ( V_228 ) == 0 )
V_223 = V_228 -> V_223 ;
}
if ( V_223 != 0 )
F_148 ( V_2 , V_223 ) ;
else
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
}
enum V_246 F_161 ( struct V_224 * V_56 , struct V_227 * V_227 )
{
struct V_1 * V_2 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
goto V_247;
if ( F_141 ( V_248 , & V_2 -> V_190 ) ||
V_2 -> V_26 != V_2 -> V_28 ||
! V_2 -> V_42 -> V_238 ) {
F_23 ( V_2 ) ;
goto V_247;
}
if ( V_2 -> V_42 -> V_235 )
V_2 -> V_42 -> V_235 ( V_2 , V_227 , L_77 ) ;
V_2 -> V_42 -> V_238 ( V_2 , NULL , V_227 ) ;
F_23 ( V_2 ) ;
V_247:
return V_249 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_96 * V_250 )
{
struct V_100 * V_101 , * V_251 ;
struct V_96 * V_97 ;
if ( ! V_250 -> V_34 )
return;
F_163 (l, n, &device->ccw_queue) {
V_97 = F_160 ( V_101 , struct V_96 , V_243 ) ;
if ( V_97 -> V_199 == V_226 &&
V_250 -> V_34 == V_97 -> V_34 ) {
V_97 -> V_199 = V_240 ;
}
}
}
static void F_164 ( struct V_1 * V_2 ,
struct V_100 * V_252 )
{
struct V_100 * V_101 , * V_251 ;
struct V_96 * V_97 ;
F_163 (l, n, &device->ccw_queue) {
V_97 = F_160 ( V_101 , struct V_96 , V_243 ) ;
if ( V_97 -> V_199 == V_226 ||
V_97 -> V_199 == V_200 ||
V_97 -> V_199 == V_201 )
break;
if ( V_97 -> V_199 == V_210 ) {
F_162 ( V_2 , V_97 ) ;
}
F_165 ( & V_97 -> V_243 , V_252 ) ;
}
}
static void F_166 ( struct V_1 * V_2 ,
struct V_100 * V_252 )
{
struct V_100 * V_101 , * V_251 ;
struct V_96 * V_97 ;
struct V_33 * V_34 ;
void (* F_167)( struct V_96 * , void * V_19 );
void * V_253 ;
char V_197 [ V_198 ] ;
F_163 (l, n, final_queue) {
V_97 = F_160 ( V_101 , struct V_96 , V_243 ) ;
F_168 ( & V_97 -> V_243 ) ;
V_34 = V_97 -> V_34 ;
F_167 = V_97 -> F_167 ;
V_253 = V_97 -> V_253 ;
if ( V_34 )
F_95 ( & V_34 -> V_38 ) ;
switch ( V_97 -> V_199 ) {
case V_242 :
V_97 -> V_199 = V_254 ;
break;
case V_210 :
V_97 -> V_199 = V_255 ;
break;
case V_240 :
V_97 -> V_199 = V_256 ;
break;
default:
snprintf ( V_197 , V_198 , L_78 , V_97 , V_97 -> V_199 ) ;
F_138 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , V_197 ) ;
F_139 () ;
}
if ( V_97 -> F_167 != NULL )
( F_167 ) ( V_97 , V_253 ) ;
if ( V_34 )
F_96 ( & V_34 -> V_38 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
if ( F_53 ( & V_2 -> V_15 ) )
return;
V_97 = F_160 ( V_2 -> V_15 . V_228 , struct V_96 , V_243 ) ;
if ( ( V_97 -> V_199 == V_200 && V_97 -> V_223 != 0 ) &&
( F_170 ( V_211 , V_97 -> V_223 + V_97 -> V_202 ) ) ) {
if ( F_141 ( V_257 , & V_2 -> V_190 ) ) {
V_97 -> V_196 ++ ;
}
if ( V_2 -> V_42 -> V_258 ( V_97 ) != 0 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_79
L_80 ,
V_97 , ( V_97 -> V_223 / V_259 ) ) ;
V_97 -> V_223 += 5 * V_259 ;
F_148 ( V_2 , 5 * V_259 ) ;
} else {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_81
L_82 , V_97 , ( V_97 -> V_223 / V_259 ) ,
V_97 -> V_196 ) ;
}
}
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
int V_40 ;
if ( F_53 ( & V_2 -> V_15 ) )
return;
V_97 = F_160 ( V_2 -> V_15 . V_228 , struct V_96 , V_243 ) ;
if ( V_97 -> V_199 != V_226 )
return;
if ( V_2 -> V_244 &&
! ( ! ( V_2 -> V_244 & ~ ( V_260 | V_261 ) )
&& F_141 ( V_212 , & V_97 -> V_190 ) ) ) {
V_97 -> V_207 = - V_65 ;
V_97 -> V_199 = V_240 ;
F_75 ( V_2 ) ;
return;
}
V_40 = V_2 -> V_42 -> V_245 ( V_97 ) ;
if ( V_40 == 0 )
F_148 ( V_2 , V_97 -> V_223 ) ;
else if ( V_40 == - V_217 ) {
F_75 ( V_2 ) ;
} else
F_148 ( V_2 , 50 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_214 . V_220 ) {
if ( V_2 -> V_244 & ~ ( V_260 |
V_261 ) )
return;
V_40 = V_2 -> V_42 -> V_262 (
V_2 , V_2 -> V_214 . V_220 ) ;
if ( V_40 )
F_148 ( V_2 , 50 ) ;
else
V_2 -> V_214 . V_220 = 0 ;
}
}
int F_45 ( struct V_1 * V_2 )
{
struct V_96 * V_97 , * V_251 ;
int V_40 ;
struct V_100 V_263 ;
F_12 ( & V_263 ) ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = 0 ;
F_174 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_97 -> V_199 ) {
case V_200 :
V_40 = V_2 -> V_42 -> V_258 ( V_97 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_83
L_84 , V_97 ) ;
goto V_264;
}
break;
case V_226 :
V_97 -> V_149 = F_137 () ;
V_97 -> V_199 = V_240 ;
break;
default:
break;
}
F_165 ( & V_97 -> V_243 , & V_263 ) ;
}
V_264:
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_174 (cqr, n, &flush_queue, devlist)
F_83 ( V_241 ,
( V_97 -> V_199 != V_201 ) ) ;
F_166 ( V_2 , & V_263 ) ;
return V_40 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_100 V_252 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_252 ) ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
F_169 ( V_2 ) ;
F_164 ( V_2 , & V_252 ) ;
F_172 ( V_2 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_166 ( V_2 , & V_252 ) ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
F_171 ( V_2 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
if ( F_176 ( & V_265 ) )
F_71 ( & V_265 ) ;
F_23 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( F_177 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_178 ( & V_2 -> V_13 ) ;
}
void F_179 ( struct V_1 * V_2 , int V_266 )
{
V_2 -> V_244 |= V_266 ;
}
void F_147 ( struct V_1 * V_2 , int V_266 )
{
V_2 -> V_244 &= ~ V_266 ;
if ( ! V_2 -> V_244 )
F_71 ( & V_267 ) ;
}
void F_180 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
unsigned long V_190 ;
V_2 = V_97 -> V_107 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
V_97 -> V_199 = V_226 ;
F_181 ( & V_97 -> V_243 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_128 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
}
void F_182 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
unsigned long V_190 ;
V_2 = V_97 -> V_107 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
V_97 -> V_199 = V_226 ;
F_183 ( & V_97 -> V_243 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_128 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
}
void F_184 ( struct V_96 * V_97 , void * V_19 )
{
F_173 ( F_146 ( V_97 -> V_107 -> V_56 ) ) ;
V_97 -> V_253 = V_268 ;
F_175 ( F_146 ( V_97 -> V_107 -> V_56 ) ) ;
F_71 ( & V_267 ) ;
}
static inline int F_185 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_97 -> V_107 ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = ( V_97 -> V_253 == V_268 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
static int F_186 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
T_6 V_269 ;
if ( V_97 -> V_199 == V_270 )
return 0 ;
V_2 = V_97 -> V_107 ;
if ( F_141 ( V_189 , & V_97 -> V_190 ) ) {
if ( V_97 -> V_199 == V_256 ) {
V_2 -> V_42 -> V_271 ( V_97 ) ;
return 1 ;
}
if ( V_97 -> V_199 == V_255 ) {
V_269 = V_2 -> V_42 -> V_272 ( V_97 ) ;
V_269 ( V_97 ) ;
return 1 ;
}
if ( V_97 -> V_199 == V_273 )
F_187 ( V_97 , & V_97 -> V_227 ) ;
if ( V_97 -> V_274 ) {
F_188 ( V_2 , V_97 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_189 ( struct V_96 * V_97 )
{
if ( F_141 ( V_189 , & V_97 -> V_190 ) ) {
if ( V_97 -> V_274 )
return 1 ;
return ( ( V_97 -> V_199 != V_254 ) &&
( V_97 -> V_199 != V_273 ) ) ;
} else
return ( V_97 -> V_199 == V_270 ) ;
}
static int F_190 ( struct V_96 * V_275 , int V_276 )
{
struct V_1 * V_2 ;
int V_40 ;
struct V_100 V_15 ;
struct V_96 * V_97 ;
F_12 ( & V_15 ) ;
V_275 -> V_199 = V_270 ;
V_2 = V_275 -> V_107 ;
F_181 ( & V_275 -> V_277 , & V_15 ) ;
for ( V_97 = V_275 ; F_189 ( V_97 ) ;
V_97 = F_191 ( & V_15 ,
struct V_96 , V_277 ) ) {
if ( F_186 ( V_97 ) )
continue;
if ( V_97 -> V_199 != V_270 )
continue;
if ( F_141 ( V_208 , & V_2 -> V_190 ) &&
! F_141 ( V_209 , & V_97 -> V_190 ) ) {
V_97 -> V_199 = V_273 ;
V_97 -> V_207 = - V_87 ;
continue;
}
if ( V_2 -> V_244 & ~ V_222 &&
F_141 ( V_278 , & V_97 -> V_190 ) &&
( ! F_192 ( V_2 ) ) ) {
V_97 -> V_199 = V_273 ;
V_97 -> V_207 = - V_65 ;
continue;
}
if ( V_276 ) {
V_40 = F_193 (
V_267 , ! ( V_2 -> V_244 ) ) ;
if ( V_40 == - V_279 ) {
V_97 -> V_199 = V_273 ;
V_275 -> V_207 = V_40 ;
continue;
}
} else
F_83 ( V_267 , ! ( V_2 -> V_244 ) ) ;
if ( ! V_97 -> F_167 )
V_97 -> F_167 = F_184 ;
V_97 -> V_253 = V_280 ;
F_182 ( V_97 ) ;
if ( V_276 ) {
V_40 = F_193 (
V_267 , F_185 ( V_97 ) ) ;
if ( V_40 == - V_279 ) {
F_194 ( V_97 ) ;
F_83 ( V_267 ,
F_185 ( V_97 ) ) ;
V_97 -> V_199 = V_273 ;
V_275 -> V_207 = V_40 ;
continue;
}
} else
F_83 ( V_267 , F_185 ( V_97 ) ) ;
}
V_275 -> V_150 = F_137 () ;
if ( ( V_275 -> V_199 != V_254 ) &&
( V_275 -> V_207 != - V_279 ) )
F_187 ( V_275 , & V_275 -> V_227 ) ;
if ( V_275 -> V_199 == V_254 )
V_40 = 0 ;
else if ( V_275 -> V_207 )
V_40 = V_275 -> V_207 ;
else
V_40 = - V_205 ;
return V_40 ;
}
int F_195 ( struct V_96 * V_97 )
{
return F_190 ( V_97 , 0 ) ;
}
int F_196 ( struct V_96 * V_97 )
{
return F_190 ( V_97 , 1 ) ;
}
static inline int F_197 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
int V_40 ;
if ( F_53 ( & V_2 -> V_15 ) )
return 0 ;
V_97 = F_160 ( V_2 -> V_15 . V_228 , struct V_96 , V_243 ) ;
V_40 = V_2 -> V_42 -> V_258 ( V_97 ) ;
if ( ! V_40 )
V_97 -> V_196 ++ ;
return V_40 ;
}
int F_198 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_97 -> V_107 ;
if ( F_141 ( V_208 , & V_2 -> V_190 ) &&
! F_141 ( V_209 , & V_97 -> V_190 ) ) {
V_97 -> V_199 = V_273 ;
V_97 -> V_207 = - V_87 ;
return - V_205 ;
}
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = F_197 ( V_2 ) ;
if ( V_40 ) {
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
V_97 -> F_167 = F_184 ;
V_97 -> V_253 = V_280 ;
V_97 -> V_199 = V_226 ;
F_181 ( & V_97 -> V_243 , V_2 -> V_15 . V_228 ) ;
F_75 ( V_2 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_83 ( V_267 , F_185 ( V_97 ) ) ;
if ( V_97 -> V_199 == V_254 )
V_40 = 0 ;
else if ( V_97 -> V_207 )
V_40 = V_97 -> V_207 ;
else
V_40 = - V_205 ;
return V_40 ;
}
int F_194 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_107 ;
unsigned long V_190 ;
int V_40 ;
V_40 = 0 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
switch ( V_97 -> V_199 ) {
case V_226 :
V_97 -> V_199 = V_240 ;
break;
case V_200 :
V_40 = V_2 -> V_42 -> V_258 ( V_97 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_85 ,
V_97 , V_40 ) ;
} else {
V_97 -> V_149 = F_137 () ;
}
break;
default:
break;
}
F_128 ( F_146 ( V_2 -> V_56 ) , V_190 ) ;
F_75 ( V_2 ) ;
return V_40 ;
}
static void V_39 ( unsigned long V_221 )
{
unsigned long V_190 ;
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_221 ;
F_126 ( F_146 ( V_34 -> V_63 -> V_56 ) , V_190 ) ;
F_147 ( V_34 -> V_63 , V_222 ) ;
F_128 ( F_146 ( V_34 -> V_63 -> V_56 ) , V_190 ) ;
F_60 ( V_34 ) ;
}
void F_199 ( struct V_33 * V_34 , int V_223 )
{
if ( V_223 == 0 )
F_149 ( & V_34 -> V_16 ) ;
else
F_150 ( & V_34 -> V_16 , V_211 + V_223 ) ;
}
void F_44 ( struct V_33 * V_34 )
{
F_149 ( & V_34 -> V_16 ) ;
}
static void F_188 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
T_6 V_269 ;
if ( V_97 -> V_199 == V_254 )
F_39 ( V_281 , V_2 , L_1 , L_86 ) ;
else
F_138 ( & V_2 -> V_56 -> V_57 , L_87 ) ;
V_269 = V_2 -> V_42 -> V_282 ( V_97 ) ;
V_269 ( V_97 ) ;
}
static void F_200 ( struct V_33 * V_34 )
{
struct V_283 * V_284 ;
struct V_98 * V_99 ;
struct V_96 * V_97 ;
struct V_1 * V_285 ;
unsigned long V_190 ;
V_284 = V_34 -> V_283 ;
V_285 = V_34 -> V_63 ;
if ( V_284 == NULL )
return;
if ( V_285 -> V_26 < V_69 ) {
while ( ( V_99 = F_201 ( V_34 -> V_283 ) ) )
F_202 ( V_99 , - V_205 ) ;
return;
}
while ( ( V_99 = F_203 ( V_284 ) ) ) {
if ( V_285 -> V_79 & V_286 &&
F_86 ( V_99 ) == V_287 ) {
F_39 ( V_183 , V_285 ,
L_88 ,
V_99 ) ;
F_204 ( V_99 ) ;
F_202 ( V_99 , - V_205 ) ;
continue;
}
V_97 = V_285 -> V_42 -> V_288 ( V_285 , V_34 , V_99 ) ;
if ( F_30 ( V_97 ) ) {
if ( F_104 ( V_97 ) == - V_206 )
break;
if ( F_104 ( V_97 ) == - V_4 )
break;
if ( F_104 ( V_97 ) == - V_65 ) {
if ( ! F_53 ( & V_34 -> V_15 ) )
break;
F_126 (
F_146 ( V_285 -> V_56 ) , V_190 ) ;
F_179 ( V_285 ,
V_222 ) ;
F_128 (
F_146 ( V_285 -> V_56 ) , V_190 ) ;
F_199 ( V_34 , V_259 / 2 ) ;
break;
}
F_39 ( V_183 , V_285 ,
L_89
L_90 ,
F_104 ( V_97 ) , V_99 ) ;
F_204 ( V_99 ) ;
F_202 ( V_99 , - V_205 ) ;
continue;
}
V_97 -> V_253 = ( void * ) V_99 ;
V_97 -> V_199 = V_270 ;
F_204 ( V_99 ) ;
F_183 ( & V_97 -> V_277 , & V_34 -> V_15 ) ;
F_84 ( V_34 , V_97 , V_99 ) ;
}
}
static void F_205 ( struct V_96 * V_97 )
{
struct V_98 * V_99 ;
int V_199 ;
int error = 0 ;
V_99 = (struct V_98 * ) V_97 -> V_253 ;
F_91 ( V_97 -> V_34 , V_97 , V_99 ) ;
V_199 = V_97 -> V_34 -> V_63 -> V_42 -> V_289 ( V_97 , V_99 ) ;
if ( V_199 <= 0 )
error = V_199 ? V_199 : - V_205 ;
F_202 ( V_99 , error ) ;
}
static void F_206 ( struct V_33 * V_34 ,
struct V_100 * V_252 )
{
struct V_100 * V_101 , * V_251 ;
struct V_96 * V_97 ;
T_6 V_269 ;
unsigned long V_190 ;
struct V_1 * V_63 = V_34 -> V_63 ;
V_290:
F_163 (l, n, &block->ccw_queue) {
V_97 = F_160 ( V_101 , struct V_96 , V_277 ) ;
if ( V_97 -> V_199 != V_254 &&
V_97 -> V_199 != V_273 &&
V_97 -> V_199 != V_255 &&
V_97 -> V_199 != V_256 )
continue;
if ( V_97 -> V_199 == V_256 ) {
V_63 -> V_42 -> V_271 ( V_97 ) ;
goto V_290;
}
if ( V_97 -> V_199 == V_255 ) {
V_269 = V_63 -> V_42 -> V_272 ( V_97 ) ;
if ( F_30 ( V_269 ( V_97 ) ) )
continue;
goto V_290;
}
if ( V_97 -> V_199 == V_273 ) {
F_187 ( V_97 , & V_97 -> V_227 ) ;
}
if ( F_192 ( V_63 ) &&
V_97 -> V_199 == V_273 ) {
F_207 ( V_63 , V_97 , V_291 ) ;
V_97 -> V_199 = V_270 ;
V_97 -> V_196 = 255 ;
F_126 ( F_146 ( V_63 -> V_56 ) , V_190 ) ;
F_179 ( V_63 , V_292 ) ;
F_128 ( F_146 ( V_63 -> V_56 ) ,
V_190 ) ;
goto V_290;
}
if ( V_97 -> V_274 ) {
F_188 ( V_63 , V_97 ) ;
goto V_290;
}
V_97 -> V_150 = F_137 () ;
F_165 ( & V_97 -> V_277 , V_252 ) ;
}
}
static void F_208 ( struct V_96 * V_97 , void * V_19 )
{
F_60 ( V_97 -> V_34 ) ;
}
static void F_209 ( struct V_33 * V_34 )
{
struct V_96 * V_97 ;
if ( F_53 ( & V_34 -> V_15 ) )
return;
F_210 (cqr, &block->ccw_queue, blocklist) {
if ( V_97 -> V_199 != V_270 )
continue;
if ( F_141 ( V_208 , & V_34 -> V_63 -> V_190 ) &&
! F_141 ( V_209 , & V_97 -> V_190 ) ) {
V_97 -> V_199 = V_273 ;
V_97 -> V_207 = - V_87 ;
F_60 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_244 & ~ V_222 &&
F_141 ( V_278 , & V_97 -> V_190 ) &&
( ! F_192 ( V_34 -> V_63 ) ) ) {
V_97 -> V_199 = V_273 ;
F_60 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_244 )
return;
if ( ! V_97 -> V_107 )
V_97 -> V_107 = V_34 -> V_63 ;
V_97 -> F_167 = F_208 ;
F_182 ( V_97 ) ;
}
}
static void V_37 ( struct V_33 * V_34 )
{
struct V_100 V_252 ;
struct V_100 * V_101 , * V_251 ;
struct V_96 * V_97 ;
F_10 ( & V_34 -> V_12 , 0 ) ;
F_12 ( & V_252 ) ;
F_87 ( & V_34 -> V_38 ) ;
F_206 ( V_34 , & V_252 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_173 ( & V_34 -> V_36 ) ;
F_163 (l, n, &final_queue) {
V_97 = F_160 ( V_101 , struct V_96 , V_277 ) ;
F_168 ( & V_97 -> V_277 ) ;
F_205 ( V_97 ) ;
}
F_87 ( & V_34 -> V_38 ) ;
F_200 ( V_34 ) ;
F_209 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_175 ( & V_34 -> V_36 ) ;
if ( F_176 ( & V_265 ) )
F_71 ( & V_265 ) ;
F_23 ( V_34 -> V_63 ) ;
}
static void F_211 ( struct V_96 * V_97 , void * V_19 )
{
F_71 ( & V_241 ) ;
}
static int F_55 ( struct V_33 * V_34 )
{
struct V_96 * V_97 , * V_251 ;
int V_40 , V_167 ;
struct V_100 V_263 ;
F_12 ( & V_263 ) ;
F_95 ( & V_34 -> V_38 ) ;
V_40 = 0 ;
V_290:
F_174 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_97 -> V_199 >= V_226 )
V_40 = F_194 ( V_97 ) ;
if ( V_40 < 0 )
break;
V_97 -> F_167 = F_211 ;
for ( V_167 = 0 ; V_97 != NULL ; V_97 = V_97 -> V_274 , V_167 ++ )
F_165 ( & V_97 -> V_277 , & V_263 ) ;
if ( V_167 > 1 )
goto V_290;
}
F_96 ( & V_34 -> V_38 ) ;
V_293:
F_174 (cqr, n, &flush_queue, blocklist) {
F_83 ( V_241 , ( V_97 -> V_199 < V_226 ) ) ;
if ( V_97 -> V_274 ) {
F_95 ( & V_34 -> V_38 ) ;
F_188 ( V_34 -> V_63 , V_97 ) ;
F_96 ( & V_34 -> V_38 ) ;
goto V_293;
}
F_173 ( & V_34 -> V_36 ) ;
V_97 -> V_150 = F_137 () ;
F_168 ( & V_97 -> V_277 ) ;
F_205 ( V_97 ) ;
F_175 ( & V_34 -> V_36 ) ;
}
return V_40 ;
}
void F_60 ( struct V_33 * V_34 )
{
if ( F_177 ( & V_34 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_34 -> V_63 ) ;
F_178 ( & V_34 -> V_13 ) ;
}
static void F_212 ( struct V_283 * V_284 )
{
struct V_33 * V_34 ;
V_34 = V_284 -> V_294 ;
F_87 ( & V_34 -> V_38 ) ;
F_200 ( V_34 ) ;
F_209 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
}
static int F_22 ( struct V_33 * V_34 )
{
int V_40 ;
V_34 -> V_283 = F_213 ( F_212 ,
& V_34 -> V_36 ) ;
if ( V_34 -> V_283 == NULL )
return - V_4 ;
V_34 -> V_283 -> V_294 = V_34 ;
F_214 ( V_34 -> V_283 -> V_295 ) ;
V_34 -> V_283 -> V_295 = NULL ;
V_40 = F_215 ( V_34 -> V_283 , L_91 ) ;
if ( V_40 ) {
F_216 ( V_34 -> V_283 ) ;
return V_40 ;
}
return 0 ;
}
static void F_49 ( struct V_33 * V_34 )
{
int V_296 ;
if ( V_34 -> V_63 -> V_79 & V_80 ) {
V_296 = 2048 ;
} else {
V_296 = V_34 -> V_63 -> V_42 -> V_297 << V_34 -> V_68 ;
}
F_217 ( V_34 -> V_283 ,
V_34 -> V_70 ) ;
F_218 ( V_34 -> V_283 , V_296 ) ;
F_219 ( V_34 -> V_283 , - 1L ) ;
F_220 ( V_34 -> V_283 , V_9 ) ;
F_221 ( V_34 -> V_283 , V_9 - 1 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
if ( V_34 -> V_283 ) {
F_216 ( V_34 -> V_283 ) ;
V_34 -> V_283 = NULL ;
}
}
static void F_56 ( struct V_33 * V_34 )
{
struct V_98 * V_99 ;
if ( ! V_34 -> V_283 )
return;
F_173 ( & V_34 -> V_36 ) ;
while ( ( V_99 = F_201 ( V_34 -> V_283 ) ) )
F_202 ( V_99 , - V_205 ) ;
F_175 ( & V_34 -> V_36 ) ;
}
static int F_222 ( struct V_298 * V_83 , T_7 V_175 )
{
struct V_1 * V_63 ;
int V_40 ;
V_63 = F_223 ( V_83 -> V_84 ) ;
if ( ! V_63 )
return - V_204 ;
F_224 ( & V_63 -> V_34 -> V_35 ) ;
if ( F_141 ( V_248 , & V_63 -> V_190 ) ) {
V_40 = - V_204 ;
goto V_299;
}
if ( ! F_225 ( V_63 -> V_42 -> V_44 ) ) {
V_40 = - V_165 ;
goto V_299;
}
if ( V_94 ) {
F_226 ( & V_63 -> V_56 -> V_57 ,
L_92
L_93 ) ;
V_40 = - V_87 ;
goto V_247;
}
if ( V_63 -> V_26 <= V_62 ) {
F_39 ( V_183 , V_63 , L_94 ,
L_95 ) ;
V_40 = - V_204 ;
goto V_247;
}
if ( ( V_175 & V_300 ) &&
( F_141 ( V_301 , & V_63 -> V_190 ) ||
( V_63 -> V_79 & V_286 ) ) ) {
V_40 = - V_302 ;
goto V_247;
}
F_23 ( V_63 ) ;
return 0 ;
V_247:
F_26 ( V_63 -> V_42 -> V_44 ) ;
V_299:
F_227 ( & V_63 -> V_34 -> V_35 ) ;
F_23 ( V_63 ) ;
return V_40 ;
}
static int F_228 ( struct V_71 * V_72 , T_7 V_175 )
{
struct V_1 * V_63 ;
V_63 = F_223 ( V_72 ) ;
if ( ! V_63 )
return - V_204 ;
F_227 ( & V_63 -> V_34 -> V_35 ) ;
F_26 ( V_63 -> V_42 -> V_44 ) ;
F_23 ( V_63 ) ;
return 0 ;
}
static int F_229 ( struct V_298 * V_83 , struct V_303 * V_304 )
{
struct V_1 * V_63 ;
V_63 = F_223 ( V_83 -> V_84 ) ;
if ( ! V_63 )
return - V_204 ;
if ( ! V_63 -> V_42 ||
! V_63 -> V_42 -> V_305 ) {
F_23 ( V_63 ) ;
return - V_165 ;
}
V_63 -> V_42 -> V_305 ( V_63 -> V_34 , V_304 ) ;
V_304 -> V_306 = F_230 ( V_83 ) >> V_63 -> V_34 -> V_68 ;
F_23 ( V_63 ) ;
return 0 ;
}
static void
F_231 ( void )
{
#ifdef F_232
F_233 () ;
#endif
F_234 () ;
if ( V_307 != NULL ) {
F_235 ( V_307 ) ;
V_307 = NULL ;
}
F_236 () ;
F_237 () ;
if ( V_308 != NULL ) {
F_47 ( V_308 ) ;
V_308 = NULL ;
}
F_117 () ;
}
int F_238 ( struct V_1 * V_2 )
{
struct V_309 V_310 ;
struct V_311 V_312 ;
int V_40 ;
if ( ! V_313 )
return 0 ;
F_239 ( V_2 -> V_56 , & V_310 ) ;
memset ( & V_312 , 0 , sizeof( V_312 ) ) ;
V_312 . V_314 = V_310 . V_315 ;
V_312 . V_316 = sizeof( V_312 ) ;
V_40 = V_311 ( & V_312 ) ;
if ( V_40 == 0 || V_40 == 2 ) {
return V_312 . V_317 & 0x80 ;
} else {
F_119 ( V_60 , L_96 ,
V_310 . V_315 , V_40 ) ;
return 0 ;
}
}
static void F_240 ( void * V_19 , T_8 V_318 )
{
struct V_224 * V_56 = V_19 ;
int V_319 ;
V_319 = F_241 ( V_56 ) ;
if ( V_319 )
F_242 ( L_97 ,
F_35 ( & V_56 -> V_57 ) , V_319 ) ;
}
int F_243 ( struct V_224 * V_56 ,
struct V_320 * V_42 )
{
int V_319 ;
V_319 = F_244 ( V_56 ) ;
if ( V_319 ) {
F_152 ( V_60 , V_56 , L_1 ,
L_98
L_99 ) ;
return V_319 ;
}
V_56 -> V_321 = & F_156 ;
if ( ( F_245 ( V_56 , V_322 ) > 0 ) ||
( V_323 && F_246 ( F_35 ( & V_56 -> V_57 ) ) != 0 ) )
F_247 ( F_240 , V_56 ) ;
return 0 ;
}
void F_248 ( struct V_224 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_56 -> V_321 = NULL ;
V_2 = F_249 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_250 ( V_56 ) ;
return;
}
if ( F_251 ( V_248 , & V_2 -> V_190 ) &&
! F_141 ( V_257 , & V_2 -> V_190 ) ) {
F_23 ( V_2 ) ;
F_250 ( V_56 ) ;
return;
}
F_80 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_252 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
F_250 ( V_56 ) ;
}
int F_253 ( struct V_224 * V_56 ,
struct V_320 * V_45 )
{
struct V_320 * V_42 ;
struct V_1 * V_2 ;
int V_40 ;
F_254 ( V_56 , V_322 , 0 ) ;
V_2 = F_255 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
V_42 = V_45 ;
if ( V_2 -> V_79 & V_324 ) {
if ( ! V_234 ) {
F_242 ( L_100
L_101 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_252 ( V_2 ) ;
return - V_204 ;
}
V_42 = V_234 ;
}
if ( ! F_225 ( V_45 -> V_44 ) ) {
F_252 ( V_2 ) ;
return - V_165 ;
}
if ( ! F_225 ( V_42 -> V_44 ) ) {
F_26 ( V_45 -> V_44 ) ;
F_252 ( V_2 ) ;
return - V_165 ;
}
V_2 -> V_45 = V_45 ;
V_2 -> V_42 = V_42 ;
V_40 = V_42 -> V_325 ( V_2 ) ;
if ( V_40 ) {
F_242 ( L_102
L_103 ,
F_35 ( & V_56 -> V_57 ) , V_42 -> V_47 , V_40 ) ;
F_26 ( V_42 -> V_44 ) ;
F_26 ( V_45 -> V_44 ) ;
F_252 ( V_2 ) ;
return V_40 ;
}
F_80 ( V_2 , V_78 ) ;
if ( V_2 -> V_26 <= V_41 ) {
F_242 ( L_104
L_105 , F_35 ( & V_56 -> V_57 ) ) ;
V_40 = - V_204 ;
F_80 ( V_2 , V_27 ) ;
if ( V_2 -> V_34 )
F_19 ( V_2 -> V_34 ) ;
F_252 ( V_2 ) ;
} else
F_256 ( L_106 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_83 ( V_88 , F_81 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_257 ( struct V_224 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_326 , V_35 , V_40 ;
V_40 = 0 ;
V_2 = F_249 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_326 = V_2 -> V_34 -> V_83 ? 0 : - 1 ;
V_35 = F_258 ( & V_2 -> V_34 -> V_35 ) ;
if ( V_35 > V_326 ) {
if ( V_35 > 0 )
F_242 ( L_107
L_108 ,
F_35 ( & V_56 -> V_57 ) , V_35 ) ;
else
F_242 ( L_107
L_109 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_259 ( V_248 , & V_2 -> V_190 ) ;
F_23 ( V_2 ) ;
return - V_206 ;
}
}
if ( F_141 ( V_257 , & V_2 -> V_190 ) ) {
if ( F_251 ( V_248 , & V_2 -> V_190 ) ) {
F_23 ( V_2 ) ;
return - V_206 ;
} else
F_259 ( V_327 , & V_2 -> V_190 ) ;
} else
if ( F_141 ( V_248 , & V_2 -> V_190 ) ) {
F_23 ( V_2 ) ;
return - V_206 ;
}
if ( F_260 ( V_327 , & V_2 -> V_190 ) &&
! F_251 ( V_257 , & V_2 -> V_190 ) ) {
V_40 = F_261 ( V_2 -> V_34 -> V_83 ) ;
if ( V_40 != 0 )
goto V_328;
F_75 ( V_2 ) ;
V_40 = F_193 ( V_265 ,
F_52 ( V_2 ) ) ;
if ( V_40 != 0 )
goto V_328;
}
F_124 ( V_248 , & V_2 -> V_190 ) ;
F_80 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_252 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
return 0 ;
V_328:
F_259 ( V_327 , & V_2 -> V_190 ) ;
F_259 ( V_257 , & V_2 -> V_190 ) ;
F_259 ( V_248 , & V_2 -> V_190 ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
F_262 ( & V_2 -> V_56 -> V_57 , L_110
L_111 ) ;
F_39 ( V_60 , V_2 , L_1 , L_112 ) ;
F_207 ( V_2 , NULL , V_329 ) ;
if ( V_2 -> V_26 < V_62 )
return 0 ;
F_210 (cqr, &device->ccw_queue, devlist)
if ( ( V_97 -> V_199 == V_200 ) ||
( V_97 -> V_199 == V_201 ) ) {
V_97 -> V_199 = V_226 ;
V_97 -> V_196 ++ ;
}
F_179 ( V_2 , V_260 ) ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
return 1 ;
}
int F_263 ( struct V_1 * V_2 )
{
F_226 ( & V_2 -> V_56 -> V_57 , L_113
L_114 ) ;
F_39 ( V_60 , V_2 , L_1 , L_115 ) ;
F_147 ( V_2 , V_260 ) ;
if ( V_2 -> V_244 & V_261 ) {
F_147 ( V_2 , V_261 ) ;
F_79 ( V_2 ) ;
return 1 ;
}
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
return 1 ;
}
int F_264 ( struct V_224 * V_56 , int V_330 )
{
struct V_1 * V_2 ;
int V_319 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return 0 ;
V_319 = 0 ;
switch ( V_330 ) {
case V_331 :
case V_332 :
case V_333 :
V_2 -> V_214 . V_215 = 0 ;
V_2 -> V_214 . V_218 = 0 ;
V_2 -> V_214 . V_219 = 0 ;
V_319 = F_144 ( V_2 ) ;
break;
case V_334 :
V_319 = 1 ;
if ( V_2 -> V_214 . V_215 )
V_319 = F_263 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_319 ;
}
void F_265 ( struct V_224 * V_56 , int * V_335 )
{
int V_336 ;
T_9 V_337 , V_338 ;
struct V_1 * V_2 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
for ( V_336 = 0 ; V_336 < 8 ; V_336 ++ ) {
V_338 = 0x80 >> V_336 ;
if ( V_335 [ V_336 ] & V_339 ) {
V_337 = V_2 -> V_214 . V_215 ;
V_2 -> V_214 . V_215 &= ~ V_338 ;
V_2 -> V_214 . V_218 &= ~ V_338 ;
V_2 -> V_214 . V_219 &= ~ V_338 ;
if ( V_337 && ! V_2 -> V_214 . V_215 )
F_144 ( V_2 ) ;
}
if ( V_335 [ V_336 ] & V_340 ) {
V_2 -> V_214 . V_215 &= ~ V_338 ;
V_2 -> V_214 . V_218 &= ~ V_338 ;
V_2 -> V_214 . V_219 &= ~ V_338 ;
V_2 -> V_214 . V_220 |= V_338 ;
F_75 ( V_2 ) ;
}
if ( V_335 [ V_336 ] & V_341 ) {
if ( ! ( V_2 -> V_214 . V_215 & V_338 ) &&
! ( V_2 -> V_214 . V_220 & V_338 ) ) {
V_2 -> V_214 . V_220 |= V_338 ;
F_75 ( V_2 ) ;
}
F_39 ( V_60 , V_2 , L_1 ,
L_116 ) ;
if ( V_2 -> V_42 -> V_95 )
V_2 -> V_42 -> V_95 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
int F_266 ( struct V_1 * V_2 , T_9 V_213 )
{
if ( ! V_2 -> V_214 . V_215 && V_213 ) {
V_2 -> V_214 . V_215 = V_213 ;
F_263 ( V_2 ) ;
} else
V_2 -> V_214 . V_215 |= V_213 ;
return 0 ;
}
int F_267 ( struct V_224 * V_56 )
{
struct V_96 * V_97 , * V_251 ;
int V_40 ;
struct V_100 V_342 ;
struct V_1 * V_2 = F_249 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
F_124 ( V_343 , & V_2 -> V_190 ) ;
if ( V_2 -> V_42 -> V_344 )
V_40 = V_2 -> V_42 -> V_344 ( V_2 ) ;
F_179 ( V_2 , V_345 ) ;
F_12 ( & V_342 ) ;
F_173 ( F_146 ( V_56 ) ) ;
V_40 = 0 ;
F_174 (cqr, n, &device->ccw_queue, devlist) {
if ( V_97 -> V_199 == V_200 ) {
V_40 = V_2 -> V_42 -> V_258 ( V_97 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_117
L_118 , V_97 ) ;
F_175 ( F_146 ( V_56 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
}
F_165 ( & V_97 -> V_243 , & V_342 ) ;
}
F_175 ( F_146 ( V_56 ) ) ;
F_174 (cqr, n, &freeze_queue, devlist) {
F_83 ( V_241 ,
( V_97 -> V_199 != V_201 ) ) ;
if ( V_97 -> V_199 == V_240 )
V_97 -> V_199 = V_226 ;
}
F_173 ( F_146 ( V_56 ) ) ;
F_268 ( & V_342 , & V_2 -> V_15 ) ;
F_175 ( F_146 ( V_56 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_269 ( struct V_224 * V_56 )
{
struct V_1 * V_2 = F_249 ( V_56 ) ;
int V_40 = 0 ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
F_147 ( V_2 ,
( V_345 | V_261 ) ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_42 -> V_93 && ! ( V_2 -> V_244 ) )
V_40 = V_2 -> V_42 -> V_93 ( V_2 ) ;
if ( V_40 || V_2 -> V_244 )
V_2 -> V_244 |= V_261 ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
F_259 ( V_343 , & V_2 -> V_190 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_96 * F_270 ( struct V_1 * V_2 ,
void * V_346 ,
int V_347 ,
int V_184 )
{
struct V_96 * V_97 ;
struct V_187 * V_192 ;
unsigned long * V_348 ;
V_97 = F_125 ( V_184 , 1 , V_347 , V_2 ) ;
if ( F_30 ( V_97 ) ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , L_119 ) ;
return V_97 ;
}
V_192 = V_97 -> V_188 ;
V_192 -> V_349 = V_350 ;
if ( F_271 ( V_346 , V_347 ) ) {
V_348 = ( unsigned long * ) ( V_97 -> V_19 ) ;
V_192 -> V_351 = ( V_352 ) ( V_353 ) V_348 ;
V_192 -> V_190 = V_354 ;
V_348 = F_272 ( V_348 , V_346 , V_347 ) ;
} else {
V_192 -> V_351 = ( V_352 ) ( V_353 ) V_346 ;
V_192 -> V_190 = 0 ;
}
V_192 -> V_355 = V_347 ;
V_97 -> V_107 = V_2 ;
V_97 -> V_356 = V_2 ;
V_97 -> V_223 = 10 * V_259 ;
V_97 -> V_196 = 256 ;
V_97 -> V_147 = F_137 () ;
V_97 -> V_199 = V_270 ;
return V_97 ;
}
int F_273 ( struct V_1 * V_2 , int V_184 ,
void * V_346 , int V_347 )
{
int V_319 ;
struct V_96 * V_97 ;
V_97 = F_270 ( V_2 , V_346 , V_347 ,
V_184 ) ;
if ( F_30 ( V_97 ) )
return F_104 ( V_97 ) ;
V_319 = F_195 ( V_97 ) ;
F_132 ( V_97 , V_97 -> V_356 ) ;
return V_319 ;
}
char * F_274 ( struct V_227 * V_227 )
{
struct V_357 * V_357 = NULL ;
char * V_358 = NULL ;
if ( F_275 ( & V_227 -> V_231 ) && ( V_227 -> V_231 . V_359 . V_360 == 0x01 ) ) {
if ( V_227 -> V_231 . V_359 . V_361 )
V_357 = F_276 ( (struct V_361 * ) ( unsigned long )
V_227 -> V_231 . V_359 . V_361 ) ;
if ( V_357 && V_357 -> V_362 == 64 && V_357 -> V_190 )
switch ( V_357 -> V_190 & 0x07 ) {
case 1 :
V_358 = V_357 -> V_363 . V_364 . V_358 ;
break;
case 2 :
V_358 = V_357 -> V_363 . V_365 . V_358 ;
break;
default:
break;
}
} else if ( V_227 -> V_366 . V_367 . V_368 . V_369 ) {
V_358 = V_227 -> V_370 ;
}
return V_358 ;
}
void F_277 ( struct V_224 * V_56 )
{
struct V_1 * V_2 ;
V_2 = F_249 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
F_75 ( V_2 ) ;
F_83 ( V_265 , F_52 ( V_2 ) ) ;
}
static int T_10 F_278 ( void )
{
int V_40 ;
F_279 ( & V_88 ) ;
F_279 ( & V_241 ) ;
F_279 ( & V_267 ) ;
F_279 ( & V_265 ) ;
V_308 = F_36 ( L_33 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_308 == NULL ) {
V_40 = - V_4 ;
goto V_371;
}
F_37 ( V_308 , & V_59 ) ;
F_38 ( V_308 , V_60 ) ;
F_119 ( V_61 , L_1 , L_2 ) ;
V_234 = NULL ;
F_118 () ;
V_40 = F_280 () ;
if ( V_40 )
goto V_371;
V_40 = F_281 () ;
if ( V_40 )
goto V_371;
V_40 = F_282 () ;
if ( V_40 )
goto V_371;
V_40 = F_283 () ;
if ( V_40 )
goto V_371;
#ifdef F_232
V_40 = F_284 () ;
if ( V_40 )
goto V_371;
#endif
return 0 ;
V_371:
F_285 ( L_120 ) ;
F_231 () ;
return V_40 ;
}
