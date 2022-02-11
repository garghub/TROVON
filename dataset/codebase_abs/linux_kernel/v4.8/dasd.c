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
int V_40 = 0 ;
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
F_36 ( V_2 -> V_50 , V_2 ) ;
V_2 -> V_58 = F_37 ( F_35 ( & V_2 -> V_56 -> V_57 ) , 4 , 1 ,
8 * sizeof( long ) ) ;
F_38 ( V_2 -> V_58 , & V_59 ) ;
F_39 ( V_2 -> V_58 , V_60 ) ;
F_40 ( V_61 , V_2 , L_1 , L_2 ) ;
V_2 -> V_26 = V_62 ;
return V_40 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_42 -> V_63 ) {
V_40 = V_2 -> V_42 -> V_63 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_2 -> V_34 ) {
F_42 ( & V_2 -> V_34 -> V_30 ) ;
F_43 ( V_2 -> V_34 -> V_50 ) ;
F_44 ( V_2 -> V_34 ) ;
F_45 ( V_2 -> V_34 ) ;
}
V_40 = F_46 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_47 ( V_2 ) ;
F_42 ( & V_2 -> V_30 ) ;
F_48 ( V_2 ) ;
F_43 ( V_2 -> V_50 ) ;
F_40 ( V_61 , V_2 , L_3 , V_2 ) ;
if ( V_2 -> V_58 != NULL ) {
F_49 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
}
V_2 -> V_26 = V_41 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_33 * V_34 ;
V_40 = 0 ;
V_34 = V_2 -> V_34 ;
if ( V_34 ) {
if ( V_34 -> V_64 -> V_42 -> V_65 != NULL )
V_40 = V_34 -> V_64 -> V_42 -> V_65 ( V_34 ) ;
if ( V_40 ) {
if ( V_40 != - V_66 ) {
V_2 -> V_26 = V_67 ;
goto V_68;
}
return V_40 ;
}
F_51 ( V_34 ) ;
F_52 ( V_34 -> V_51 ,
V_34 -> V_69 << V_34 -> V_70 ) ;
V_2 -> V_26 = V_71 ;
V_40 = F_53 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_62 ;
return V_40 ;
}
} else {
V_2 -> V_26 = V_71 ;
}
V_68:
if ( V_2 -> V_42 -> V_72 )
V_40 = V_2 -> V_42 -> V_72 ( V_2 ) ;
return V_40 ;
}
static inline
int F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 )
return F_55 ( & V_2 -> V_15 ) &&
F_55 ( & V_2 -> V_34 -> V_15 ) ;
else
return F_55 ( & V_2 -> V_15 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_40 ;
V_2 -> V_26 = V_62 ;
if ( V_2 -> V_34 ) {
struct V_33 * V_34 = V_2 -> V_34 ;
V_40 = F_57 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_71 ;
return V_40 ;
}
F_58 ( V_34 ) ;
F_59 ( V_34 ) ;
V_34 -> V_69 = 0 ;
V_34 -> V_73 = 0 ;
V_34 -> V_70 = 0 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
V_2 -> V_26 = V_62 ;
return 0 ;
}
static int
F_61 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
V_2 -> V_26 = V_80 ;
if ( V_2 -> V_34 ) {
F_62 ( V_2 -> V_34 ) ;
if ( ( V_2 -> V_81 & V_82 ) ) {
V_75 = V_2 -> V_34 -> V_51 ;
F_63 ( & F_64 ( V_75 ) -> V_83 , V_84 ) ;
return 0 ;
}
V_75 = V_2 -> V_34 -> V_85 -> V_86 ;
F_65 ( & V_77 , V_75 , V_87 ) ;
while ( ( V_79 = F_66 ( & V_77 ) ) )
F_63 ( & F_67 ( V_79 ) -> V_83 , V_84 ) ;
F_68 ( & V_77 ) ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_74 * V_75 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
if ( V_2 -> V_42 -> V_88 ) {
V_40 = V_2 -> V_42 -> V_88 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
V_2 -> V_26 = V_71 ;
if ( V_2 -> V_34 && ! ( V_2 -> V_81 & V_82 ) ) {
V_75 = V_2 -> V_34 -> V_85 -> V_86 ;
F_65 ( & V_77 , V_75 , V_87 ) ;
while ( ( V_79 = F_66 ( & V_77 ) ) )
F_63 ( & F_67 ( V_79 ) -> V_83 , V_84 ) ;
F_68 ( & V_77 ) ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
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
V_2 -> V_28 >= V_71 )
V_40 = F_50 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_67 &&
V_2 -> V_28 > V_67 )
V_40 = - V_89 ;
if ( ! V_40 &&
V_2 -> V_26 == V_71 &&
V_2 -> V_28 >= V_80 )
V_40 = F_61 ( V_2 ) ;
return V_40 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_80 &&
V_2 -> V_28 <= V_71 )
V_40 = F_69 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_71 &&
V_2 -> V_28 <= V_62 )
V_40 = F_56 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_67 &&
V_2 -> V_28 <= V_62 )
V_40 = F_60 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_62 &&
V_2 -> V_28 <= V_41 )
V_40 = F_41 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_41 &&
V_2 -> V_28 <= V_27 )
V_40 = F_24 ( V_2 ) ;
return V_40 ;
}
static void F_72 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_26 == V_2 -> V_28 )
return;
if ( V_2 -> V_26 < V_2 -> V_28 )
V_40 = F_70 ( V_2 ) ;
else
V_40 = F_71 ( V_2 ) ;
if ( V_40 == - V_66 )
return;
if ( V_40 )
V_2 -> V_28 = V_2 -> V_26 ;
F_63 ( & V_2 -> V_56 -> V_57 . V_83 , V_84 ) ;
if ( V_2 -> V_26 == V_2 -> V_28 )
F_73 ( & V_90 ) ;
}
static void V_21 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_74 ( V_92 , struct V_1 , V_20 ) ;
F_75 ( & V_2 -> V_29 ) ;
F_72 ( V_2 ) ;
F_76 ( & V_2 -> V_29 ) ;
F_77 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_79 ( & V_2 -> V_20 ) )
F_23 ( V_2 ) ;
}
static void V_25 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_74 ( V_92 , struct V_1 ,
V_24 ) ;
V_2 -> V_42 -> V_93 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_79 ( & V_2 -> V_24 ) )
F_23 ( V_2 ) ;
}
static void V_23 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_74 ( V_92 , struct V_1 ,
V_22 ) ;
V_2 -> V_56 -> V_94 -> V_95 ( V_2 -> V_56 ) ;
F_23 ( V_2 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_79 ( & V_2 -> V_22 ) )
F_23 ( V_2 ) ;
}
void F_82 ( struct V_1 * V_2 , int V_28 )
{
F_21 ( V_2 ) ;
F_75 ( & V_2 -> V_29 ) ;
if ( V_96 && V_28 > V_71 )
V_28 = V_71 ;
if ( V_2 -> V_28 != V_28 ) {
if ( V_2 -> V_26 == V_28 )
F_73 ( & V_90 ) ;
V_2 -> V_28 = V_28 ;
}
if ( V_2 -> V_26 != V_2 -> V_28 )
F_72 ( V_2 ) ;
F_76 ( & V_2 -> V_29 ) ;
F_23 ( V_2 ) ;
}
static inline int F_83 ( struct V_1 * V_2 )
{
return ( V_2 -> V_26 == V_2 -> V_28 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_80 ) ;
if ( V_2 -> V_26 <= V_41 )
F_82 ( V_2 , V_27 ) ;
F_85 ( V_90 , F_83 ( V_2 ) ) ;
F_80 ( V_2 ) ;
if ( V_2 -> V_42 -> V_97 )
V_2 -> V_42 -> V_97 ( V_2 ) ;
}
static void F_86 ( struct V_33 * V_34 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ;
unsigned int V_104 ;
struct V_1 * V_2 ;
V_104 = 0 ;
if ( V_54 || V_34 -> V_30 . V_19 )
F_87 (l, &block->ccw_queue)
if ( ++ V_104 >= 31 )
break;
F_88 ( & V_105 . V_31 ) ;
if ( V_105 . V_19 ) {
V_105 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_89 ( V_101 ) == V_107 )
V_105 . V_19 -> V_108 [ V_104 ] ++ ;
}
F_90 ( & V_105 . V_31 ) ;
F_88 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 ) {
V_34 -> V_30 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_89 ( V_101 ) == V_107 )
V_34 -> V_30 . V_19 -> V_108 [ V_104 ] ++ ;
}
F_90 ( & V_34 -> V_30 . V_31 ) ;
V_2 = V_99 -> V_109 ;
if ( V_2 -> V_30 . V_19 ) {
V_104 = 1 ;
F_87 (l, &device->ccw_queue)
if ( ++ V_104 >= 31 )
break;
}
F_88 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 ) {
V_2 -> V_30 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_89 ( V_101 ) == V_107 )
V_2 -> V_30 . V_19 -> V_108 [ V_104 ] ++ ;
}
F_90 ( & V_2 -> V_30 . V_31 ) ;
}
static void F_91 ( struct V_110 * V_19 ,
int V_111 ,
int V_112 ,
int V_113 ,
long V_114 ,
int V_115 ,
int V_116 ,
int V_117 ,
int V_118 ,
int V_119 ,
int V_120 ,
int V_121 )
{
if ( V_19 -> V_122 == V_123 ) {
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_92 ( & V_19 -> V_124 ) ;
}
V_19 -> V_122 ++ ;
V_19 -> V_125 += V_114 ;
if ( V_111 )
V_19 -> V_126 ++ ;
if ( V_112 )
V_19 -> V_127 ++ ;
V_19 -> V_128 [ V_115 ] ++ ;
V_19 -> V_129 [ V_116 ] ++ ;
V_19 -> V_130 [ V_117 ] ++ ;
V_19 -> V_131 [ V_118 ] ++ ;
V_19 -> V_132 [ V_119 ] ++ ;
V_19 -> V_133 [ V_120 ] ++ ;
V_19 -> V_134 [ V_121 ] ++ ;
if ( V_113 ) {
V_19 -> V_135 ++ ;
V_19 -> V_136 += V_114 ;
if ( V_111 )
V_19 -> V_137 ++ ;
if ( V_112 )
V_19 -> V_138 ++ ;
V_19 -> V_139 [ V_115 ] ++ ;
V_19 -> V_140 [ V_116 ] ++ ;
V_19 -> V_141 [ V_118 ] ++ ;
V_19 -> V_142 [ V_119 ] ++ ;
V_19 -> V_143 [ V_121 ] ++ ;
}
}
static void F_93 ( struct V_33 * V_34 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
long V_144 , V_145 , V_146 , V_147 ;
long V_148 , V_114 ;
struct V_1 * V_2 ;
int V_115 , V_116 , V_117 , V_118 ;
int V_119 , V_120 , V_121 ;
V_2 = V_99 -> V_109 ;
if ( ! ( V_54 ||
V_34 -> V_30 . V_19 ||
V_2 -> V_30 . V_19 ) )
return;
V_114 = F_94 ( V_101 ) ;
if ( ! V_99 -> V_149 || ! V_99 -> V_150 ||
! V_99 -> V_151 || ! V_99 -> V_152 ||
! V_114 )
return;
V_144 = ( ( V_99 -> V_150 - V_99 -> V_149 ) >> 12 ) ;
V_145 = ( ( V_99 -> V_151 - V_99 -> V_150 ) >> 12 ) ;
V_146 = ( ( V_99 -> V_152 - V_99 -> V_151 ) >> 12 ) ;
V_147 = ( ( V_99 -> V_152 - V_99 -> V_149 ) >> 12 ) ;
V_148 = V_147 / V_114 ;
F_95 ( V_114 , V_115 ) ;
F_95 ( V_147 , V_116 ) ;
F_95 ( V_148 , V_117 ) ;
F_95 ( V_144 , V_118 ) ;
F_95 ( V_145 , V_119 ) ;
F_95 ( V_145 / V_114 , V_120 ) ;
F_95 ( V_146 , V_121 ) ;
F_88 ( & V_105 . V_31 ) ;
if ( V_105 . V_19 ) {
F_91 ( V_105 . V_19 ,
V_99 -> V_109 != V_34 -> V_64 ,
V_99 -> V_153 == 1 ,
F_89 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
}
F_90 ( & V_105 . V_31 ) ;
F_88 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
F_91 ( V_34 -> V_30 . V_19 ,
V_99 -> V_109 != V_34 -> V_64 ,
V_99 -> V_153 == 1 ,
F_89 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
F_90 ( & V_34 -> V_30 . V_31 ) ;
F_88 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 )
F_91 ( V_2 -> V_30 . V_19 ,
V_99 -> V_109 != V_34 -> V_64 ,
V_99 -> V_153 == 1 ,
F_89 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
F_90 ( & V_2 -> V_30 . V_31 ) ;
}
void F_96 ( struct V_154 * V_30 )
{
struct V_110 * V_19 ;
F_97 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_98 ( & V_30 -> V_31 ) ;
return;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_92 ( & V_19 -> V_124 ) ;
F_98 ( & V_30 -> V_31 ) ;
}
int F_34 ( struct V_154 * V_30 )
{
struct V_110 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_155 ) ;
if ( ! V_19 )
return - V_4 ;
F_97 ( & V_30 -> V_31 ) ;
if ( V_30 -> V_19 ) {
F_98 ( & V_30 -> V_31 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_92 ( & V_19 -> V_124 ) ;
V_30 -> V_19 = V_19 ;
F_98 ( & V_30 -> V_31 ) ;
return 0 ;
}
void F_99 ( struct V_154 * V_30 )
{
F_97 ( & V_30 -> V_31 ) ;
F_5 ( V_30 -> V_19 ) ;
V_30 -> V_19 = NULL ;
F_98 ( & V_30 -> V_31 ) ;
}
char * F_100 ( const char T_1 * V_156 , T_2 V_157 )
{
char * V_158 ;
V_158 = F_101 ( V_157 + 1 ) ;
if ( V_158 == NULL )
return F_3 ( - V_4 ) ;
if ( F_102 ( V_158 , V_156 , V_157 ) != 0 ) {
F_103 ( V_158 ) ;
return F_3 ( - V_159 ) ;
}
if ( V_158 [ V_157 - 1 ] == '\n' )
V_158 [ V_157 - 1 ] = 0 ;
else
V_158 [ V_157 ] = 0 ;
return V_158 ;
}
static T_3 F_104 ( struct V_160 * V_160 ,
const char T_1 * V_156 ,
T_2 V_157 , T_4 * V_161 )
{
char * V_158 , * V_162 ;
int V_40 ;
struct V_163 * V_164 = (struct V_163 * ) V_160 -> V_165 ;
struct V_154 * V_166 = V_164 -> V_32 ;
if ( V_157 > 65536 )
V_157 = 65536 ;
V_158 = F_100 ( V_156 , V_157 ) ;
if ( F_30 ( V_158 ) )
return F_105 ( V_158 ) ;
V_162 = F_106 ( V_158 ) ;
V_40 = V_157 ;
if ( strncmp ( V_162 , L_4 , 5 ) == 0 ) {
F_96 ( V_166 ) ;
} else if ( strncmp ( V_162 , L_5 , 2 ) == 0 ) {
V_40 = F_34 ( V_166 ) ;
if ( V_40 )
goto V_68;
V_40 = V_157 ;
if ( V_166 == & V_105 ) {
F_96 ( V_166 ) ;
V_54 = V_167 ;
}
} else if ( strncmp ( V_162 , L_6 , 3 ) == 0 ) {
if ( V_166 == & V_105 )
V_54 = V_168 ;
F_99 ( V_166 ) ;
} else
V_40 = - V_169 ;
V_68:
F_103 ( V_158 ) ;
return V_40 ;
}
static void F_107 ( struct V_163 * V_164 , unsigned int * V_170 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < 32 ; V_171 ++ )
F_108 ( V_164 , L_7 , V_170 [ V_171 ] ) ;
F_109 ( V_164 , '\n' ) ;
}
static void F_110 ( struct V_163 * V_164 ,
struct V_110 * V_19 )
{
F_108 ( V_164 , L_8 ,
V_19 -> V_124 . V_172 , V_19 -> V_124 . V_173 ) ;
F_108 ( V_164 , L_9 , V_19 -> V_122 ) ;
F_108 ( V_164 , L_10 , V_19 -> V_125 ) ;
F_108 ( V_164 , L_11 , V_19 -> V_126 ) ;
F_108 ( V_164 , L_12 , V_19 -> V_127 ) ;
F_111 ( V_164 , L_13 ) ;
F_107 ( V_164 , V_19 -> V_128 ) ;
F_111 ( V_164 , L_14 ) ;
F_107 ( V_164 , V_19 -> V_129 ) ;
F_111 ( V_164 , L_15 ) ;
F_107 ( V_164 , V_19 -> V_130 ) ;
F_111 ( V_164 , L_16 ) ;
F_107 ( V_164 , V_19 -> V_131 ) ;
F_111 ( V_164 , L_17 ) ;
F_107 ( V_164 , V_19 -> V_132 ) ;
F_111 ( V_164 , L_18 ) ;
F_107 ( V_164 , V_19 -> V_133 ) ;
F_111 ( V_164 , L_19 ) ;
F_107 ( V_164 , V_19 -> V_134 ) ;
F_111 ( V_164 , L_20 ) ;
F_107 ( V_164 , V_19 -> V_106 ) ;
F_108 ( V_164 , L_21 , V_19 -> V_135 ) ;
F_108 ( V_164 , L_22 , V_19 -> V_136 ) ;
F_108 ( V_164 , L_23 , V_19 -> V_137 ) ;
F_108 ( V_164 , L_24 , V_19 -> V_138 ) ;
F_111 ( V_164 , L_25 ) ;
F_107 ( V_164 , V_19 -> V_139 ) ;
F_111 ( V_164 , L_26 ) ;
F_107 ( V_164 , V_19 -> V_140 ) ;
F_111 ( V_164 , L_27 ) ;
F_107 ( V_164 , V_19 -> V_141 ) ;
F_111 ( V_164 , L_28 ) ;
F_107 ( V_164 , V_19 -> V_142 ) ;
F_111 ( V_164 , L_29 ) ;
F_107 ( V_164 , V_19 -> V_143 ) ;
F_111 ( V_164 , L_30 ) ;
F_107 ( V_164 , V_19 -> V_108 ) ;
}
static int F_112 ( struct V_163 * V_164 , void * V_174 )
{
struct V_154 * V_30 ;
struct V_110 * V_19 ;
V_30 = V_164 -> V_32 ;
F_97 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_98 ( & V_30 -> V_31 ) ;
F_111 ( V_164 , L_31 ) ;
return 0 ;
}
F_110 ( V_164 , V_19 ) ;
F_98 ( & V_30 -> V_31 ) ;
return 0 ;
}
static int F_113 ( struct V_175 * V_175 , struct V_160 * V_160 )
{
struct V_154 * V_30 = V_175 -> V_176 ;
return F_114 ( V_160 , F_112 , V_30 ) ;
}
static void F_33 ( struct V_154 * V_30 ,
struct V_46 * V_48 )
{
T_5 V_177 ;
struct V_46 * V_49 ;
if ( ! V_48 )
return;
V_30 -> V_46 = NULL ;
V_30 -> V_19 = NULL ;
V_177 = ( V_178 | V_179 | V_180 ) ;
V_49 = F_115 ( L_32 , V_177 , V_48 ,
V_30 , & V_181 ) ;
if ( V_49 && ! F_30 ( V_49 ) )
V_30 -> V_46 = V_49 ;
return;
}
static void F_42 ( struct V_154 * V_30 )
{
F_99 ( V_30 ) ;
F_43 ( V_30 -> V_46 ) ;
V_30 -> V_46 = NULL ;
}
static void F_116 ( void )
{
V_54 = V_168 ;
F_42 ( & V_105 ) ;
F_43 ( V_182 ) ;
F_43 ( V_53 ) ;
}
static void F_117 ( void )
{
struct V_46 * V_49 ;
V_53 = NULL ;
V_49 = F_29 ( L_33 , NULL ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_53 = V_49 ;
V_49 = F_29 ( L_34 , V_53 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_182 = V_49 ;
F_33 ( & V_105 , V_182 ) ;
return;
error:
F_118 ( V_183 , L_1 ,
L_35 ) ;
F_116 () ;
return;
}
static void F_117 ( void )
{
return;
}
static void F_116 ( void )
{
return;
}
int F_119 ( struct V_163 * V_164 , void * V_174 )
{
F_111 ( V_164 , L_36 ) ;
return 0 ;
}
static void F_33 ( struct V_154 * V_30 ,
struct V_46 * V_48 )
{
return;
}
static void F_42 ( struct V_154 * V_30 )
{
return;
}
int F_34 ( struct V_154 * V_30 )
{
return 0 ;
}
static int F_120 ( struct V_163 * V_164 , void * V_174 )
{
struct V_1 * V_2 ;
int V_40 = - V_184 ;
V_2 = V_164 -> V_32 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_42 -> V_185 )
V_40 = V_2 -> V_42 -> V_185 ( V_2 , V_164 ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
static int F_121 ( struct V_175 * V_175 , struct V_160 * V_160 )
{
struct V_1 * V_2 = V_175 -> V_176 ;
return F_114 ( V_160 , F_120 , V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_186 ) ;
V_2 -> V_186 = NULL ;
}
static void F_36 ( struct V_46 * V_48 ,
struct V_1 * V_2 )
{
struct V_46 * V_49 ;
T_5 V_177 ;
if ( ! V_48 )
return;
V_177 = V_178 | V_180 ;
V_49 = F_115 ( L_37 , V_177 , V_48 ,
V_2 , & V_187 ) ;
if ( V_49 && ! F_30 ( V_49 ) )
V_2 -> V_186 = V_49 ;
}
struct V_98 * F_122 ( int V_188 , int V_189 ,
int V_190 ,
struct V_1 * V_2 )
{
struct V_98 * V_99 ;
F_123 ( V_190 > V_9 ||
( V_189 * sizeof( struct V_191 ) ) > V_9 ) ;
V_99 = F_2 ( sizeof( struct V_98 ) , V_3 ) ;
if ( V_99 == NULL )
return F_3 ( - V_4 ) ;
V_99 -> V_192 = NULL ;
if ( V_189 > 0 ) {
V_99 -> V_192 = F_124 ( V_189 , sizeof( struct V_191 ) ,
V_3 | V_6 ) ;
if ( V_99 -> V_192 == NULL ) {
F_5 ( V_99 ) ;
return F_3 ( - V_4 ) ;
}
}
V_99 -> V_19 = NULL ;
if ( V_190 > 0 ) {
V_99 -> V_19 = F_2 ( V_190 , V_3 | V_6 ) ;
if ( V_99 -> V_19 == NULL ) {
F_5 ( V_99 -> V_192 ) ;
F_5 ( V_99 ) ;
return F_3 ( - V_4 ) ;
}
}
V_99 -> V_188 = V_188 ;
F_125 ( V_193 , & V_99 -> V_194 ) ;
F_21 ( V_2 ) ;
return V_99 ;
}
struct V_98 * F_126 ( int V_188 , int V_189 ,
int V_190 ,
struct V_1 * V_2 )
{
unsigned long V_194 ;
struct V_98 * V_99 ;
char * V_19 ;
int V_195 ;
V_195 = ( sizeof( struct V_98 ) + 7L ) & - 8L ;
if ( V_189 > 0 )
V_195 += V_189 * sizeof( struct V_191 ) ;
if ( V_190 > 0 )
V_195 += V_190 ;
F_127 ( & V_2 -> V_11 , V_194 ) ;
V_99 = (struct V_98 * )
F_128 ( & V_2 -> V_8 , V_195 ) ;
F_129 ( & V_2 -> V_11 , V_194 ) ;
if ( V_99 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_99 , 0 , sizeof( struct V_98 ) ) ;
V_19 = ( char * ) V_99 + ( ( sizeof( struct V_98 ) + 7L ) & - 8L ) ;
V_99 -> V_192 = NULL ;
if ( V_189 > 0 ) {
V_99 -> V_192 = (struct V_191 * ) V_19 ;
V_19 += V_189 * sizeof( struct V_191 ) ;
memset ( V_99 -> V_192 , 0 , V_189 * sizeof( struct V_191 ) ) ;
}
V_99 -> V_19 = NULL ;
if ( V_190 > 0 ) {
V_99 -> V_19 = V_19 ;
memset ( V_99 -> V_19 , 0 , V_190 ) ;
}
V_99 -> V_188 = V_188 ;
F_125 ( V_193 , & V_99 -> V_194 ) ;
F_21 ( V_2 ) ;
return V_99 ;
}
void F_130 ( struct V_98 * V_99 , struct V_1 * V_2 )
{
struct V_191 * V_196 ;
V_196 = V_99 -> V_192 ;
do {
F_131 ( V_196 ) ;
} while ( V_196 ++ -> V_194 & ( V_197 | V_198 ) );
F_5 ( V_99 -> V_192 ) ;
F_5 ( V_99 -> V_19 ) ;
F_5 ( V_99 ) ;
F_23 ( V_2 ) ;
}
void F_132 ( struct V_98 * V_99 , struct V_1 * V_2 )
{
unsigned long V_194 ;
F_127 ( & V_2 -> V_11 , V_194 ) ;
F_133 ( & V_2 -> V_8 , V_99 ) ;
F_129 ( & V_2 -> V_11 , V_194 ) ;
F_23 ( V_2 ) ;
}
static inline int F_134 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
if ( V_99 == NULL )
return - V_169 ;
V_2 = V_99 -> V_109 ;
if ( strncmp ( ( char * ) & V_99 -> V_188 , V_2 -> V_42 -> V_199 , 4 ) ) {
F_40 ( V_60 , V_2 ,
L_38
L_39 ,
V_99 -> V_188 ,
* ( unsigned int * ) V_2 -> V_42 -> V_47 ) ;
return - V_169 ;
}
return 0 ;
}
int F_135 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_200 , V_40 ;
char V_201 [ V_202 ] ;
V_40 = F_134 ( V_99 ) ;
if ( V_40 )
return V_40 ;
V_200 = 0 ;
V_2 = (struct V_1 * ) V_99 -> V_109 ;
while ( ( V_200 < 5 ) && ( V_99 -> V_203 == V_204 ) ) {
V_40 = F_136 ( V_2 -> V_56 , ( long ) V_99 ) ;
switch ( V_40 ) {
case 0 :
V_99 -> V_203 = V_205 ;
V_99 -> V_151 = F_137 () ;
V_99 -> V_206 = 0 ;
F_40 ( V_207 , V_2 ,
L_40 ,
V_99 ) ;
break;
case - V_208 :
F_40 ( V_183 , V_2 , L_1 ,
L_41 ) ;
break;
case - V_209 :
F_40 ( V_183 , V_2 , L_1 ,
L_42 ) ;
break;
case - V_169 :
V_99 -> V_203 = V_210 ;
V_99 -> V_151 = F_137 () ;
V_99 -> V_206 = 0 ;
V_99 -> V_200 = - 1 ;
F_40 ( V_183 , V_2 , L_1 ,
L_43 ) ;
V_40 = 0 ;
break;
case - V_211 :
F_40 ( V_183 , V_2 , L_1 ,
L_44 ) ;
break;
default:
snprintf ( V_201 , V_202 , L_45 , V_40 ) ;
F_138 ( & V_2 -> V_56 -> V_57 , L_46
L_47 , V_201 ) ;
F_139 () ;
break;
}
V_200 ++ ;
}
F_77 ( V_2 ) ;
return V_40 ;
}
int F_140 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
char V_201 [ V_202 ] ;
V_40 = F_134 ( V_99 ) ;
if ( V_40 ) {
V_99 -> V_212 = V_40 ;
return V_40 ;
}
V_2 = (struct V_1 * ) V_99 -> V_109 ;
if ( ( ( V_99 -> V_34 &&
F_141 ( V_213 , & V_99 -> V_34 -> V_64 -> V_194 ) ) ||
F_141 ( V_213 , & V_2 -> V_194 ) ) &&
! F_141 ( V_214 , & V_99 -> V_194 ) ) {
F_40 ( V_207 , V_2 , L_48
L_49 , V_99 ) ;
V_99 -> V_203 = V_215 ;
V_99 -> V_212 = - V_89 ;
return - V_89 ;
}
if ( V_99 -> V_200 < 0 ) {
sprintf ( V_201 , L_50 , V_99 ) ;
F_138 ( & V_2 -> V_56 -> V_57 , L_51
L_52 , V_201 ) ;
V_99 -> V_203 = V_215 ;
return - V_209 ;
}
V_99 -> V_150 = F_137 () ;
V_99 -> V_206 = V_216 ;
V_99 -> V_200 -- ;
if ( ! F_141 ( V_217 , & V_99 -> V_194 ) ) {
V_99 -> V_218 &= V_2 -> V_219 . V_220 ;
if ( ! V_99 -> V_218 )
V_99 -> V_218 = V_2 -> V_219 . V_220 ;
}
if ( V_99 -> V_153 == 1 ) {
V_40 = F_142 ( V_2 -> V_56 , V_99 -> V_192 ,
( long ) V_99 , V_99 -> V_218 ) ;
} else {
V_40 = F_143 ( V_2 -> V_56 , V_99 -> V_192 ,
( long ) V_99 , V_99 -> V_218 , 0 ) ;
}
switch ( V_40 ) {
case 0 :
V_99 -> V_203 = V_204 ;
break;
case - V_211 :
F_40 ( V_60 , V_2 , L_1 ,
L_53 ) ;
break;
case - V_221 :
F_40 ( V_60 , V_2 , L_1 ,
L_54 ) ;
break;
case - V_222 :
if ( F_141 ( V_217 , & V_99 -> V_194 ) ) {
F_40 ( V_60 , V_2 ,
L_55 ,
V_99 -> V_218 ) ;
} else if ( V_99 -> V_218 != V_2 -> V_219 . V_220 ) {
V_99 -> V_218 = V_2 -> V_219 . V_220 ;
F_40 ( V_207 , V_2 , L_1 ,
L_56
L_57 ) ;
} else {
F_40 ( V_60 , V_2 , L_1 ,
L_58
L_59 ) ;
F_144 ( V_2 ) ;
V_2 -> V_219 . V_220 = 0 ;
V_2 -> V_219 . V_223 = 0 ;
V_2 -> V_219 . V_224 = 0 ;
V_2 -> V_219 . V_225 =
F_145 ( V_2 -> V_56 ) ;
}
break;
case - V_208 :
F_40 ( V_60 , V_2 , L_1 ,
L_60 ) ;
break;
case - V_209 :
F_40 ( V_60 , V_2 , L_1 ,
L_61 ) ;
break;
case - V_169 :
F_40 ( V_60 , V_2 , L_1 ,
L_62
L_63 ) ;
break;
default:
snprintf ( V_201 , V_202 , L_64 , V_40 ) ;
F_138 ( & V_2 -> V_56 -> V_57 ,
L_65
L_66 , V_201 ) ;
F_139 () ;
break;
}
V_99 -> V_212 = V_40 ;
return V_40 ;
}
static void V_18 ( unsigned long V_226 )
{
unsigned long V_194 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_226 ;
F_127 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
F_147 ( V_2 , V_227 ) ;
F_129 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
F_77 ( V_2 ) ;
}
void F_148 ( struct V_1 * V_2 , int V_228 )
{
if ( V_228 == 0 )
F_149 ( & V_2 -> V_16 ) ;
else
F_150 ( & V_2 -> V_16 , V_216 + V_228 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
F_149 ( & V_2 -> V_16 ) ;
}
static void F_151 ( struct V_229 * V_56 ,
unsigned long V_230 )
{
struct V_98 * V_99 ;
struct V_1 * V_2 ;
if ( ! V_230 )
return;
V_99 = (struct V_98 * ) V_230 ;
if ( V_99 -> V_203 != V_204 ) {
F_152 ( V_207 , V_56 ,
L_67
L_68 , V_99 -> V_203 ) ;
return;
}
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_152 ( V_207 , V_56 , L_1 ,
L_69 ) ;
return;
}
if ( ! V_99 -> V_109 ||
V_2 != V_99 -> V_109 ||
strncmp ( V_99 -> V_109 -> V_42 -> V_199 ,
( char * ) & V_99 -> V_188 , 4 ) ) {
F_152 ( V_207 , V_56 , L_1 ,
L_70 ) ;
F_23 ( V_2 ) ;
return;
}
V_99 -> V_203 = V_231 ;
F_47 ( V_2 ) ;
F_77 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_154 ( struct V_1 * V_2 )
{
F_155 ( V_2 ) ;
F_147 ( V_2 , V_227 ) ;
F_77 ( V_2 ) ;
if ( V_2 -> V_34 )
F_62 ( V_2 -> V_34 ) ;
}
void F_156 ( struct V_229 * V_56 , unsigned long V_230 ,
struct V_232 * V_232 )
{
struct V_98 * V_99 , * V_233 ;
struct V_1 * V_2 ;
unsigned long long V_234 ;
int V_235 = 0 ;
int V_236 = 0 ;
T_6 * V_237 = NULL ;
int V_228 ;
V_99 = (struct V_98 * ) V_230 ;
if ( F_30 ( V_232 ) ) {
switch ( F_105 ( V_232 ) ) {
case - V_209 :
if ( V_99 && V_99 -> V_203 == V_205 ) {
V_2 = (struct V_1 * ) V_99 -> V_109 ;
V_99 -> V_203 = V_210 ;
F_47 ( V_2 ) ;
F_73 ( & V_238 ) ;
F_77 ( V_2 ) ;
return;
}
break;
case - V_221 :
F_152 ( V_60 , V_56 , L_71
L_72 , V_239 ) ;
break;
default:
F_152 ( V_60 , V_56 , L_71
L_73 , V_239 ,
F_105 ( V_232 ) ) ;
}
F_151 ( V_56 , V_230 ) ;
return;
}
V_234 = F_137 () ;
if ( ! V_99 ||
! ( F_157 ( & V_232 -> V_240 ) == ( V_241 | V_242 ) &&
F_158 ( & V_232 -> V_240 ) == 0 ) ) {
if ( V_99 )
memcpy ( & V_99 -> V_232 , V_232 , sizeof( * V_232 ) ) ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_42 == V_243 ) {
F_23 ( V_2 ) ;
return;
}
V_237 = F_159 ( V_232 ) ;
if ( V_237 ) {
V_236 = ( V_237 [ 1 ] & V_244 ) &&
F_141 ( V_245 , & V_99 -> V_194 ) ;
V_235 = ( V_237 [ 1 ] & V_246 ) &&
F_141 ( V_247 , & V_99 -> V_194 ) ;
}
if ( ! ( V_236 || V_235 ) )
V_2 -> V_42 -> V_248 ( V_2 , V_232 , L_74 ) ;
if ( V_2 -> V_81 & V_249 )
V_2 -> V_42 -> V_250 ( V_2 , V_99 , V_232 ) ;
V_2 -> V_42 -> V_251 ( V_2 , V_99 , V_232 ) ;
F_23 ( V_2 ) ;
}
if ( F_157 ( & V_232 -> V_240 ) & V_252 ) {
V_2 = F_153 ( V_56 ) ;
V_2 -> V_42 -> V_253 ( V_2 , V_232 -> V_254 . V_255 . V_256 ) ;
F_23 ( V_2 ) ;
}
if ( ! V_99 )
return;
V_2 = (struct V_1 * ) V_99 -> V_109 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_42 -> V_199 , ( char * ) & V_99 -> V_188 , 4 ) ) {
F_152 ( V_207 , V_56 , L_1 ,
L_70 ) ;
return;
}
if ( V_99 -> V_203 == V_205 &&
F_160 ( & V_232 -> V_240 ) & V_257 ) {
V_99 -> V_203 = V_210 ;
F_47 ( V_2 ) ;
F_73 ( & V_238 ) ;
F_77 ( V_2 ) ;
return;
}
if ( V_99 -> V_203 != V_204 ) {
F_40 ( V_207 , V_2 , L_75
L_76 , F_35 ( & V_56 -> V_57 ) , V_99 -> V_203 ) ;
return;
}
V_233 = NULL ;
V_228 = 0 ;
if ( F_157 ( & V_232 -> V_240 ) == ( V_241 | V_242 ) &&
F_158 ( & V_232 -> V_240 ) == 0 ) {
V_99 -> V_203 = V_258 ;
V_99 -> V_151 = V_234 ;
if ( V_99 -> V_259 . V_233 != & V_2 -> V_15 ) {
V_233 = F_161 ( V_99 -> V_259 . V_233 ,
struct V_98 , V_259 ) ;
}
} else {
if ( ! F_141 ( V_193 , & V_99 -> V_194 ) &&
V_99 -> V_200 > 0 ) {
if ( V_99 -> V_218 == V_2 -> V_219 . V_220 )
F_40 ( V_207 , V_2 ,
L_77
L_78 ,
V_99 -> V_200 ) ;
if ( ! F_141 ( V_217 , & V_99 -> V_194 ) )
V_99 -> V_218 = V_2 -> V_219 . V_220 ;
V_99 -> V_203 = V_231 ;
V_233 = V_99 ;
} else
V_99 -> V_203 = V_215 ;
}
if ( V_233 && ( V_233 -> V_203 == V_231 ) &&
( ! V_2 -> V_260 ) ) {
if ( V_2 -> V_42 -> V_261 ( V_233 ) == 0 )
V_228 = V_233 -> V_228 ;
}
if ( V_228 != 0 )
F_148 ( V_2 , V_228 ) ;
else
F_47 ( V_2 ) ;
F_77 ( V_2 ) ;
}
enum V_262 F_162 ( struct V_229 * V_56 , struct V_232 * V_232 )
{
struct V_1 * V_2 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
goto V_68;
if ( F_141 ( V_263 , & V_2 -> V_194 ) ||
V_2 -> V_26 != V_2 -> V_28 ||
! V_2 -> V_42 -> V_251 ) {
F_23 ( V_2 ) ;
goto V_68;
}
if ( V_2 -> V_42 -> V_248 )
V_2 -> V_42 -> V_248 ( V_2 , V_232 , L_79 ) ;
V_2 -> V_42 -> V_251 ( V_2 , NULL , V_232 ) ;
F_23 ( V_2 ) ;
V_68:
return V_264 ;
}
static void F_163 ( struct V_1 * V_2 ,
struct V_98 * V_265 )
{
struct V_102 * V_103 , * V_266 ;
struct V_98 * V_99 ;
if ( ! V_265 -> V_34 )
return;
F_164 (l, n, &device->ccw_queue) {
V_99 = F_161 ( V_103 , struct V_98 , V_259 ) ;
if ( V_99 -> V_203 == V_231 &&
V_265 -> V_34 == V_99 -> V_34 ) {
V_99 -> V_203 = V_210 ;
}
}
}
static void F_165 ( struct V_1 * V_2 ,
struct V_102 * V_267 )
{
struct V_102 * V_103 , * V_266 ;
struct V_98 * V_99 ;
F_164 (l, n, &device->ccw_queue) {
V_99 = F_161 ( V_103 , struct V_98 , V_259 ) ;
if ( V_99 -> V_203 == V_231 ||
V_99 -> V_203 == V_204 ||
V_99 -> V_203 == V_205 )
continue;
if ( V_99 -> V_203 == V_215 ) {
F_163 ( V_2 , V_99 ) ;
}
F_166 ( & V_99 -> V_259 , V_267 ) ;
}
}
static void F_167 ( struct V_1 * V_2 ,
struct V_102 * V_267 )
{
struct V_102 * V_103 , * V_266 ;
struct V_98 * V_99 ;
struct V_33 * V_34 ;
void (* F_168)( struct V_98 * , void * V_19 );
void * V_268 ;
char V_201 [ V_202 ] ;
F_164 (l, n, final_queue) {
V_99 = F_161 ( V_103 , struct V_98 , V_259 ) ;
F_169 ( & V_99 -> V_259 ) ;
V_34 = V_99 -> V_34 ;
F_168 = V_99 -> F_168 ;
V_268 = V_99 -> V_268 ;
if ( V_34 )
F_97 ( & V_34 -> V_38 ) ;
switch ( V_99 -> V_203 ) {
case V_258 :
V_99 -> V_203 = V_269 ;
break;
case V_215 :
V_99 -> V_203 = V_270 ;
break;
case V_210 :
V_99 -> V_203 = V_271 ;
break;
default:
snprintf ( V_201 , V_202 , L_80 , V_99 , V_99 -> V_203 ) ;
F_138 ( & V_2 -> V_56 -> V_57 ,
L_65
L_66 , V_201 ) ;
F_139 () ;
}
if ( V_99 -> F_168 != NULL )
( F_168 ) ( V_99 , V_268 ) ;
if ( V_34 )
F_98 ( & V_34 -> V_38 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
if ( F_55 ( & V_2 -> V_15 ) )
return;
V_99 = F_161 ( V_2 -> V_15 . V_233 , struct V_98 , V_259 ) ;
if ( ( V_99 -> V_203 == V_204 && V_99 -> V_228 != 0 ) &&
( F_171 ( V_216 , V_99 -> V_228 + V_99 -> V_206 ) ) ) {
if ( F_141 ( V_272 , & V_2 -> V_194 ) ) {
V_99 -> V_200 ++ ;
}
if ( V_2 -> V_42 -> V_273 ( V_99 ) != 0 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_81
L_82 ,
V_99 , ( V_99 -> V_228 / V_274 ) ) ;
V_99 -> V_228 += 5 * V_274 ;
F_148 ( V_2 , 5 * V_274 ) ;
} else {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_83
L_84 , V_99 , ( V_99 -> V_228 / V_274 ) ,
V_99 -> V_200 ) ;
}
}
}
static int F_172 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
int V_275 = ~ ( V_276 | V_277 ) ;
if ( F_141 ( V_263 , & V_2 -> V_194 ) ) {
return 1 ;
}
if ( V_2 -> V_260 ) {
if ( V_2 -> V_260 & V_275 ) {
return 1 ;
}
if ( ! F_141 ( V_217 , & V_99 -> V_194 ) ) {
return 1 ;
}
}
return 0 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
int V_40 ;
if ( F_55 ( & V_2 -> V_15 ) )
return;
V_99 = F_161 ( V_2 -> V_15 . V_233 , struct V_98 , V_259 ) ;
if ( V_99 -> V_203 != V_231 )
return;
if ( F_172 ( V_2 , V_99 ) ) {
V_99 -> V_212 = - V_66 ;
V_99 -> V_203 = V_210 ;
F_77 ( V_2 ) ;
return;
}
V_40 = V_2 -> V_42 -> V_261 ( V_99 ) ;
if ( V_40 == 0 )
F_148 ( V_2 , V_99 -> V_228 ) ;
else if ( V_40 == - V_222 ) {
F_77 ( V_2 ) ;
} else
F_148 ( V_2 , 50 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_219 . V_225 ) {
if ( V_2 -> V_260 & ~ ( V_276 |
V_277 ) )
return;
V_40 = V_2 -> V_42 -> V_278 (
V_2 , V_2 -> V_219 . V_225 ) ;
if ( V_40 )
F_148 ( V_2 , 50 ) ;
else
V_2 -> V_219 . V_225 = 0 ;
}
}
int F_46 ( struct V_1 * V_2 )
{
struct V_98 * V_99 , * V_266 ;
int V_40 ;
struct V_102 V_279 ;
F_12 ( & V_279 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = 0 ;
F_176 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_99 -> V_203 ) {
case V_204 :
V_40 = V_2 -> V_42 -> V_273 ( V_99 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_85
L_86 , V_99 ) ;
goto V_280;
}
break;
case V_231 :
V_99 -> V_151 = F_137 () ;
V_99 -> V_203 = V_210 ;
break;
default:
break;
}
F_166 ( & V_99 -> V_259 , & V_279 ) ;
}
V_280:
F_177 ( F_146 ( V_2 -> V_56 ) ) ;
F_176 (cqr, n, &flush_queue, devlist)
F_85 ( V_238 ,
( V_99 -> V_203 != V_205 ) ) ;
F_167 ( V_2 , & V_279 ) ;
return V_40 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_102 V_267 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_267 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_170 ( V_2 ) ;
F_165 ( V_2 , & V_267 ) ;
F_174 ( V_2 ) ;
F_177 ( F_146 ( V_2 -> V_56 ) ) ;
F_167 ( V_2 , & V_267 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_173 ( V_2 ) ;
F_177 ( F_146 ( V_2 -> V_56 ) ) ;
if ( F_178 ( & V_281 ) )
F_73 ( & V_281 ) ;
F_23 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
if ( F_179 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_180 ( & V_2 -> V_13 ) ;
}
void F_181 ( struct V_1 * V_2 , int V_282 )
{
V_2 -> V_260 |= V_282 ;
}
void F_147 ( struct V_1 * V_2 , int V_282 )
{
V_2 -> V_260 &= ~ V_282 ;
if ( ! V_2 -> V_260 )
F_73 ( & V_283 ) ;
}
void F_182 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
unsigned long V_194 ;
V_2 = V_99 -> V_109 ;
F_127 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
V_99 -> V_203 = V_231 ;
F_183 ( & V_99 -> V_259 , & V_2 -> V_15 ) ;
F_77 ( V_2 ) ;
F_129 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
}
void F_184 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
unsigned long V_194 ;
V_2 = V_99 -> V_109 ;
F_127 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
V_99 -> V_203 = V_231 ;
F_185 ( & V_99 -> V_259 , & V_2 -> V_15 ) ;
F_77 ( V_2 ) ;
F_129 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
}
void F_186 ( struct V_98 * V_99 , void * V_19 )
{
F_175 ( F_146 ( V_99 -> V_109 -> V_56 ) ) ;
V_99 -> V_268 = V_284 ;
F_177 ( F_146 ( V_99 -> V_109 -> V_56 ) ) ;
F_73 ( & V_283 ) ;
}
static inline int F_187 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_99 -> V_109 ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = ( V_99 -> V_268 == V_284 ) ;
F_177 ( F_146 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
static int F_188 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
T_7 V_285 ;
if ( V_99 -> V_203 == V_286 )
return 0 ;
V_2 = V_99 -> V_109 ;
if ( F_141 ( V_193 , & V_99 -> V_194 ) ) {
if ( V_99 -> V_203 == V_271 ) {
V_2 -> V_42 -> V_287 ( V_99 ) ;
return 1 ;
}
if ( V_99 -> V_203 == V_270 ) {
V_285 = V_2 -> V_42 -> V_288 ( V_99 ) ;
V_285 ( V_99 ) ;
return 1 ;
}
if ( V_99 -> V_203 == V_289 )
F_189 ( V_99 , & V_99 -> V_232 ) ;
if ( V_99 -> V_290 ) {
F_190 ( V_2 , V_99 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_191 ( struct V_98 * V_99 )
{
if ( F_141 ( V_193 , & V_99 -> V_194 ) ) {
if ( V_99 -> V_290 )
return 1 ;
return ( ( V_99 -> V_203 != V_269 ) &&
( V_99 -> V_203 != V_289 ) ) ;
} else
return ( V_99 -> V_203 == V_286 ) ;
}
static int F_192 ( struct V_98 * V_291 , int V_292 )
{
struct V_1 * V_2 ;
int V_40 ;
struct V_102 V_15 ;
struct V_98 * V_99 ;
F_12 ( & V_15 ) ;
V_291 -> V_203 = V_286 ;
V_2 = V_291 -> V_109 ;
F_183 ( & V_291 -> V_293 , & V_15 ) ;
for ( V_99 = V_291 ; F_191 ( V_99 ) ;
V_99 = F_193 ( & V_15 ,
struct V_98 , V_293 ) ) {
if ( F_188 ( V_99 ) )
continue;
if ( V_99 -> V_203 != V_286 )
continue;
if ( F_141 ( V_213 , & V_2 -> V_194 ) &&
! F_141 ( V_214 , & V_99 -> V_194 ) ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = - V_89 ;
continue;
}
if ( V_2 -> V_260 & ~ V_227 &&
F_141 ( V_294 , & V_99 -> V_194 ) &&
( ! F_194 ( V_2 ) ) ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = - V_295 ;
continue;
}
if ( ! F_141 ( V_217 , & V_99 -> V_194 ) ) {
if ( V_292 ) {
V_40 = F_195 (
V_283 , ! ( V_2 -> V_260 ) ) ;
if ( V_40 == - V_296 ) {
V_99 -> V_203 = V_289 ;
V_291 -> V_212 = V_40 ;
continue;
}
} else
F_85 ( V_283 , ! ( V_2 -> V_260 ) ) ;
}
if ( ! V_99 -> F_168 )
V_99 -> F_168 = F_186 ;
V_99 -> V_268 = V_297 ;
F_184 ( V_99 ) ;
if ( V_292 ) {
V_40 = F_195 (
V_283 , F_187 ( V_99 ) ) ;
if ( V_40 == - V_296 ) {
F_196 ( V_99 ) ;
F_85 ( V_283 ,
F_187 ( V_99 ) ) ;
V_99 -> V_203 = V_289 ;
V_291 -> V_212 = V_40 ;
continue;
}
} else
F_85 ( V_283 , F_187 ( V_99 ) ) ;
}
V_291 -> V_152 = F_137 () ;
if ( ( V_291 -> V_203 != V_269 ) &&
( V_291 -> V_212 != - V_296 ) )
F_189 ( V_291 , & V_291 -> V_232 ) ;
if ( V_291 -> V_203 == V_269 )
V_40 = 0 ;
else if ( V_291 -> V_212 )
V_40 = V_291 -> V_212 ;
else
V_40 = - V_209 ;
return V_40 ;
}
static inline int F_197 ( struct V_102 * V_15 )
{
struct V_98 * V_99 ;
F_198 (cqr, ccw_queue, blocklist) {
if ( V_99 -> V_268 != V_284 )
return 0 ;
}
return 1 ;
}
static int F_199 ( struct V_102 * V_15 , int V_292 )
{
struct V_1 * V_2 ;
struct V_98 * V_99 , * V_266 ;
T_6 * V_237 = NULL ;
int V_40 ;
V_298:
F_176 (cqr, n, ccw_queue, blocklist) {
V_2 = V_99 -> V_109 ;
if ( V_99 -> V_203 != V_286 )
continue;
if ( F_141 ( V_213 , & V_2 -> V_194 ) &&
! F_141 ( V_214 , & V_99 -> V_194 ) ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = - V_89 ;
continue;
}
if ( V_2 -> V_260 & ~ V_227 &&
F_141 ( V_294 , & V_99 -> V_194 ) &&
! F_194 ( V_2 ) ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = - V_66 ;
continue;
}
if ( V_292 ) {
V_40 = F_195 (
V_283 , ! V_2 -> V_260 ) ;
if ( V_40 == - V_296 ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = V_40 ;
continue;
}
} else
F_85 ( V_283 , ! ( V_2 -> V_260 ) ) ;
if ( ! V_99 -> F_168 )
V_99 -> F_168 = F_186 ;
V_99 -> V_268 = V_297 ;
F_184 ( V_99 ) ;
}
F_85 ( V_283 , F_197 ( V_15 ) ) ;
V_40 = 0 ;
F_176 (cqr, n, ccw_queue, blocklist) {
V_237 = F_159 ( & V_99 -> V_232 ) ;
if ( V_237 && V_237 [ 1 ] & V_244 &&
F_141 ( V_245 , & V_99 -> V_194 ) )
continue;
if ( F_158 ( & V_99 -> V_232 . V_240 ) == 0x40 &&
F_141 ( V_299 , & V_99 -> V_194 ) )
continue;
if ( V_99 -> V_109 != V_99 -> V_300 && ! V_99 -> V_290 &&
( V_99 -> V_203 == V_271 ||
V_99 -> V_203 == V_270 ) )
return - V_66 ;
if ( F_188 ( V_99 ) )
goto V_298;
}
return 0 ;
}
int F_200 ( struct V_98 * V_99 )
{
return F_192 ( V_99 , 0 ) ;
}
int F_201 ( struct V_102 * V_15 )
{
return F_199 ( V_15 , 0 ) ;
}
int F_202 ( struct V_98 * V_99 )
{
return F_192 ( V_99 , 1 ) ;
}
static inline int F_203 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
int V_40 ;
if ( F_55 ( & V_2 -> V_15 ) )
return 0 ;
V_99 = F_161 ( V_2 -> V_15 . V_233 , struct V_98 , V_259 ) ;
V_40 = V_2 -> V_42 -> V_273 ( V_99 ) ;
if ( ! V_40 )
V_99 -> V_200 ++ ;
return V_40 ;
}
int F_204 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_99 -> V_109 ;
if ( F_141 ( V_213 , & V_2 -> V_194 ) &&
! F_141 ( V_214 , & V_99 -> V_194 ) ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = - V_89 ;
return - V_209 ;
}
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = F_203 ( V_2 ) ;
if ( V_40 ) {
F_177 ( F_146 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
V_99 -> F_168 = F_186 ;
V_99 -> V_268 = V_297 ;
V_99 -> V_203 = V_231 ;
F_183 ( & V_99 -> V_259 , V_2 -> V_15 . V_233 ) ;
F_77 ( V_2 ) ;
F_177 ( F_146 ( V_2 -> V_56 ) ) ;
F_85 ( V_283 , F_187 ( V_99 ) ) ;
if ( V_99 -> V_203 == V_269 )
V_40 = 0 ;
else if ( V_99 -> V_212 )
V_40 = V_99 -> V_212 ;
else
V_40 = - V_209 ;
F_77 ( V_2 ) ;
if ( V_2 -> V_34 )
F_62 ( V_2 -> V_34 ) ;
return V_40 ;
}
int F_196 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_109 ;
unsigned long V_194 ;
int V_40 ;
V_40 = 0 ;
F_127 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
switch ( V_99 -> V_203 ) {
case V_231 :
V_99 -> V_203 = V_210 ;
if ( V_99 -> V_268 == V_297 )
V_99 -> V_268 = V_284 ;
break;
case V_204 :
V_40 = V_2 -> V_42 -> V_273 ( V_99 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_87 ,
V_99 , V_40 ) ;
} else {
V_99 -> V_151 = F_137 () ;
}
break;
default:
break;
}
F_129 ( F_146 ( V_2 -> V_56 ) , V_194 ) ;
F_77 ( V_2 ) ;
return V_40 ;
}
static void V_39 ( unsigned long V_226 )
{
unsigned long V_194 ;
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_226 ;
F_127 ( F_146 ( V_34 -> V_64 -> V_56 ) , V_194 ) ;
F_147 ( V_34 -> V_64 , V_227 ) ;
F_129 ( F_146 ( V_34 -> V_64 -> V_56 ) , V_194 ) ;
F_62 ( V_34 ) ;
}
void F_205 ( struct V_33 * V_34 , int V_228 )
{
if ( V_228 == 0 )
F_149 ( & V_34 -> V_16 ) ;
else
F_150 ( & V_34 -> V_16 , V_216 + V_228 ) ;
}
void F_45 ( struct V_33 * V_34 )
{
F_149 ( & V_34 -> V_16 ) ;
}
static void F_190 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
T_7 V_285 ;
if ( V_99 -> V_203 == V_269 )
F_40 ( V_301 , V_2 , L_1 , L_88 ) ;
else
F_138 ( & V_2 -> V_56 -> V_57 , L_89 ) ;
V_285 = V_2 -> V_42 -> V_302 ( V_99 ) ;
V_285 ( V_99 ) ;
}
static void F_206 ( struct V_33 * V_34 )
{
struct V_303 * V_304 ;
struct V_100 * V_101 ;
struct V_98 * V_99 ;
struct V_1 * V_300 ;
unsigned long V_194 ;
V_304 = V_34 -> V_303 ;
V_300 = V_34 -> V_64 ;
if ( V_304 == NULL )
return;
if ( V_300 -> V_26 < V_71 ) {
while ( ( V_101 = F_207 ( V_34 -> V_303 ) ) )
F_208 ( V_101 , - V_209 ) ;
return;
}
if ( V_300 -> V_260 && ! ( V_300 -> V_81 & V_305 ) )
return;
while ( ( V_101 = F_209 ( V_304 ) ) ) {
if ( V_300 -> V_81 & V_306 &&
F_89 ( V_101 ) == V_307 ) {
F_40 ( V_183 , V_300 ,
L_90 ,
V_101 ) ;
F_210 ( V_101 ) ;
F_208 ( V_101 , - V_209 ) ;
continue;
}
if ( F_141 ( V_308 , & V_300 -> V_194 ) &&
( V_300 -> V_81 & V_305 ||
F_211 ( V_101 ) ) ) {
F_40 ( V_183 , V_300 ,
L_91 ,
V_101 ) ;
F_210 ( V_101 ) ;
F_208 ( V_101 , - V_221 ) ;
continue;
}
V_99 = V_300 -> V_42 -> V_309 ( V_300 , V_34 , V_101 ) ;
if ( F_30 ( V_99 ) ) {
if ( F_105 ( V_99 ) == - V_211 )
break;
if ( F_105 ( V_99 ) == - V_4 )
break;
if ( F_105 ( V_99 ) == - V_66 ) {
if ( ! F_55 ( & V_34 -> V_15 ) )
break;
F_127 (
F_146 ( V_300 -> V_56 ) , V_194 ) ;
F_181 ( V_300 ,
V_227 ) ;
F_129 (
F_146 ( V_300 -> V_56 ) , V_194 ) ;
F_205 ( V_34 , V_274 / 2 ) ;
break;
}
F_40 ( V_183 , V_300 ,
L_92
L_93 ,
F_105 ( V_99 ) , V_101 ) ;
F_210 ( V_101 ) ;
F_208 ( V_101 , - V_209 ) ;
continue;
}
V_99 -> V_268 = ( void * ) V_101 ;
V_99 -> V_203 = V_286 ;
V_101 -> V_310 = V_99 ;
F_210 ( V_101 ) ;
F_185 ( & V_99 -> V_293 , & V_34 -> V_15 ) ;
F_12 ( & V_99 -> V_259 ) ;
F_86 ( V_34 , V_99 , V_101 ) ;
}
}
static void F_212 ( struct V_98 * V_99 )
{
struct V_100 * V_101 ;
int V_203 ;
int error = 0 ;
V_101 = (struct V_100 * ) V_99 -> V_268 ;
F_93 ( V_99 -> V_34 , V_99 , V_101 ) ;
V_203 = V_99 -> V_34 -> V_64 -> V_42 -> V_311 ( V_99 , V_101 ) ;
if ( V_203 < 0 )
error = V_203 ;
else if ( V_203 == 0 ) {
if ( V_99 -> V_212 == - V_89 )
error = - V_312 ;
else if ( V_99 -> V_212 == - V_295 ||
V_99 -> V_212 == - V_221 )
error = V_99 -> V_212 ;
else
error = - V_209 ;
}
F_208 ( V_101 , error ) ;
}
static void F_213 ( struct V_33 * V_34 ,
struct V_102 * V_267 )
{
struct V_102 * V_103 , * V_266 ;
struct V_98 * V_99 ;
T_7 V_285 ;
unsigned long V_194 ;
struct V_1 * V_64 = V_34 -> V_64 ;
V_313:
F_164 (l, n, &block->ccw_queue) {
V_99 = F_161 ( V_103 , struct V_98 , V_293 ) ;
if ( V_99 -> V_203 != V_269 &&
V_99 -> V_203 != V_289 &&
V_99 -> V_203 != V_270 &&
V_99 -> V_203 != V_271 )
continue;
if ( V_99 -> V_203 == V_271 ) {
V_64 -> V_42 -> V_287 ( V_99 ) ;
goto V_313;
}
if ( V_99 -> V_203 == V_270 ) {
V_285 = V_64 -> V_42 -> V_288 ( V_99 ) ;
if ( F_30 ( V_285 ( V_99 ) ) )
continue;
goto V_313;
}
if ( V_99 -> V_203 == V_289 ) {
F_189 ( V_99 , & V_99 -> V_232 ) ;
}
if ( F_194 ( V_64 ) &&
V_99 -> V_203 == V_289 ) {
F_214 ( V_64 , V_99 , V_314 ) ;
V_99 -> V_203 = V_286 ;
V_99 -> V_200 = 255 ;
F_127 ( F_146 ( V_64 -> V_56 ) , V_194 ) ;
F_181 ( V_64 , V_315 ) ;
F_129 ( F_146 ( V_64 -> V_56 ) ,
V_194 ) ;
goto V_313;
}
if ( V_99 -> V_290 ) {
F_190 ( V_64 , V_99 ) ;
goto V_313;
}
V_99 -> V_152 = F_137 () ;
F_166 ( & V_99 -> V_293 , V_267 ) ;
}
}
static void F_215 ( struct V_98 * V_99 , void * V_19 )
{
F_62 ( V_99 -> V_34 ) ;
}
static void F_216 ( struct V_33 * V_34 )
{
struct V_98 * V_99 ;
if ( F_55 ( & V_34 -> V_15 ) )
return;
F_198 (cqr, &block->ccw_queue, blocklist) {
if ( V_99 -> V_203 != V_286 )
continue;
if ( F_141 ( V_213 , & V_34 -> V_64 -> V_194 ) &&
! F_141 ( V_214 , & V_99 -> V_194 ) ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = - V_89 ;
F_62 ( V_34 ) ;
continue;
}
if ( V_34 -> V_64 -> V_260 & ~ V_227 &&
F_141 ( V_294 , & V_99 -> V_194 ) &&
( ! F_194 ( V_34 -> V_64 ) ) ) {
V_99 -> V_203 = V_289 ;
V_99 -> V_212 = - V_295 ;
F_62 ( V_34 ) ;
continue;
}
if ( V_34 -> V_64 -> V_260 )
return;
if ( ! V_99 -> V_109 )
V_99 -> V_109 = V_34 -> V_64 ;
V_99 -> F_168 = F_215 ;
F_184 ( V_99 ) ;
}
}
static void V_37 ( struct V_33 * V_34 )
{
struct V_102 V_267 ;
struct V_102 * V_103 , * V_266 ;
struct V_98 * V_99 ;
F_10 ( & V_34 -> V_12 , 0 ) ;
F_12 ( & V_267 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_213 ( V_34 , & V_267 ) ;
F_90 ( & V_34 -> V_38 ) ;
F_175 ( & V_34 -> V_36 ) ;
F_164 (l, n, &final_queue) {
V_99 = F_161 ( V_103 , struct V_98 , V_293 ) ;
F_169 ( & V_99 -> V_293 ) ;
F_212 ( V_99 ) ;
}
F_88 ( & V_34 -> V_38 ) ;
F_206 ( V_34 ) ;
F_216 ( V_34 ) ;
F_90 ( & V_34 -> V_38 ) ;
F_177 ( & V_34 -> V_36 ) ;
if ( F_178 ( & V_281 ) )
F_73 ( & V_281 ) ;
F_23 ( V_34 -> V_64 ) ;
}
static void F_217 ( struct V_98 * V_99 , void * V_19 )
{
F_73 ( & V_238 ) ;
}
static int F_218 ( struct V_98 * V_99 )
{
struct V_33 * V_34 = V_99 -> V_34 ;
struct V_100 * V_101 ;
unsigned long V_194 ;
if ( ! V_34 )
return - V_169 ;
F_127 ( & V_34 -> V_38 , V_194 ) ;
V_101 = (struct V_100 * ) V_99 -> V_268 ;
F_219 ( V_34 -> V_303 , V_101 ) ;
F_129 ( & V_34 -> V_38 , V_194 ) ;
return 0 ;
}
static int F_57 ( struct V_33 * V_34 )
{
struct V_98 * V_99 , * V_266 ;
int V_40 , V_171 ;
struct V_102 V_279 ;
F_12 ( & V_279 ) ;
F_97 ( & V_34 -> V_38 ) ;
V_40 = 0 ;
V_313:
F_176 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_99 -> V_203 >= V_231 )
V_40 = F_196 ( V_99 ) ;
if ( V_40 < 0 )
break;
V_99 -> F_168 = F_217 ;
for ( V_171 = 0 ; V_99 != NULL ; V_99 = V_99 -> V_290 , V_171 ++ )
F_166 ( & V_99 -> V_293 , & V_279 ) ;
if ( V_171 > 1 )
goto V_313;
}
F_98 ( & V_34 -> V_38 ) ;
V_316:
F_176 (cqr, n, &flush_queue, blocklist) {
F_85 ( V_238 , ( V_99 -> V_203 < V_231 ) ) ;
if ( V_99 -> V_290 ) {
F_97 ( & V_34 -> V_38 ) ;
F_190 ( V_34 -> V_64 , V_99 ) ;
F_98 ( & V_34 -> V_38 ) ;
goto V_316;
}
F_175 ( & V_34 -> V_36 ) ;
V_99 -> V_152 = F_137 () ;
F_169 ( & V_99 -> V_293 ) ;
F_212 ( V_99 ) ;
F_177 ( & V_34 -> V_36 ) ;
}
return V_40 ;
}
void F_62 ( struct V_33 * V_34 )
{
if ( F_179 ( & V_34 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_34 -> V_64 ) ;
F_180 ( & V_34 -> V_13 ) ;
}
static void F_220 ( struct V_303 * V_304 )
{
struct V_33 * V_34 ;
V_34 = V_304 -> V_317 ;
F_88 ( & V_34 -> V_38 ) ;
F_206 ( V_34 ) ;
F_216 ( V_34 ) ;
F_90 ( & V_34 -> V_38 ) ;
}
enum V_318 F_221 ( struct V_100 * V_101 )
{
struct V_98 * V_99 = V_101 -> V_310 ;
struct V_33 * V_34 = V_101 -> V_319 -> V_317 ;
struct V_1 * V_2 ;
int V_40 = 0 ;
if ( ! V_99 )
return V_320 ;
V_2 = V_99 -> V_109 ? V_99 -> V_109 : V_34 -> V_64 ;
if ( ! V_2 -> V_321 )
return V_322 ;
F_40 ( V_60 , V_2 ,
L_94 ,
V_99 , V_99 -> V_203 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_88 ( F_146 ( V_2 -> V_56 ) ) ;
V_99 -> V_200 = - 1 ;
V_99 -> V_212 = - V_221 ;
if ( V_99 -> V_203 >= V_231 ) {
F_90 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = F_196 ( V_99 ) ;
} else if ( V_99 -> V_203 == V_286 ||
V_99 -> V_203 == V_270 ) {
V_99 -> V_203 = V_271 ;
F_90 ( F_146 ( V_2 -> V_56 ) ) ;
} else if ( V_99 -> V_203 == V_323 ) {
struct V_98 * V_324 , * V_325 , * V_326 ;
F_176 (searchcqr, nextcqr,
&block->ccw_queue, blocklist) {
V_326 = V_324 ;
while ( V_326 -> V_290 )
V_326 = V_326 -> V_290 ;
if ( V_326 != V_99 )
continue;
V_324 -> V_200 = - 1 ;
V_324 -> V_212 = - V_221 ;
if ( V_324 -> V_203 >= V_231 ) {
F_90 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = F_196 ( V_324 ) ;
F_88 ( F_146 ( V_2 -> V_56 ) ) ;
} else if ( ( V_324 -> V_203 == V_286 ) ||
( V_324 -> V_203 == V_270 ) ) {
V_324 -> V_203 = V_271 ;
V_40 = 0 ;
} else if ( V_324 -> V_203 == V_323 ) {
continue;
}
break;
}
F_90 ( F_146 ( V_2 -> V_56 ) ) ;
}
F_62 ( V_34 ) ;
F_90 ( & V_34 -> V_38 ) ;
return V_40 ? V_322 : V_320 ;
}
static int F_22 ( struct V_33 * V_34 )
{
V_34 -> V_303 = F_222 ( F_220 ,
& V_34 -> V_36 ) ;
if ( V_34 -> V_303 == NULL )
return - V_4 ;
V_34 -> V_303 -> V_317 = V_34 ;
return 0 ;
}
static void F_51 ( struct V_33 * V_34 )
{
int V_327 ;
if ( V_34 -> V_64 -> V_81 & V_82 ) {
V_327 = 2048 ;
} else {
V_327 = V_34 -> V_64 -> V_42 -> V_328 << V_34 -> V_70 ;
}
F_223 ( V_329 , V_34 -> V_303 ) ;
V_34 -> V_303 -> V_330 . V_331 = V_327 ;
F_224 ( V_34 -> V_303 ,
V_34 -> V_73 ) ;
F_225 ( V_34 -> V_303 , V_327 ) ;
F_226 ( V_34 -> V_303 , - 1L ) ;
F_227 ( V_34 -> V_303 , V_9 ) ;
F_228 ( V_34 -> V_303 , V_9 - 1 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
if ( V_34 -> V_303 ) {
F_229 ( V_34 -> V_303 ) ;
V_34 -> V_303 = NULL ;
}
}
static void F_58 ( struct V_33 * V_34 )
{
struct V_100 * V_101 ;
if ( ! V_34 -> V_303 )
return;
F_175 ( & V_34 -> V_36 ) ;
while ( ( V_101 = F_207 ( V_34 -> V_303 ) ) )
F_208 ( V_101 , - V_209 ) ;
F_177 ( & V_34 -> V_36 ) ;
}
static int F_230 ( struct V_332 * V_85 , T_8 V_177 )
{
struct V_1 * V_64 ;
int V_40 ;
V_64 = F_231 ( V_85 -> V_86 ) ;
if ( ! V_64 )
return - V_208 ;
F_232 ( & V_64 -> V_34 -> V_35 ) ;
if ( F_141 ( V_263 , & V_64 -> V_194 ) ) {
V_40 = - V_208 ;
goto V_333;
}
if ( ! F_233 ( V_64 -> V_42 -> V_44 ) ) {
V_40 = - V_169 ;
goto V_333;
}
if ( V_96 ) {
F_234 ( & V_64 -> V_56 -> V_57 ,
L_95
L_96 ) ;
V_40 = - V_89 ;
goto V_68;
}
if ( V_64 -> V_26 <= V_62 ) {
F_40 ( V_183 , V_64 , L_97 ,
L_98 ) ;
V_40 = - V_208 ;
goto V_68;
}
if ( ( V_177 & V_334 ) &&
( F_141 ( V_335 , & V_64 -> V_194 ) ||
( V_64 -> V_81 & V_306 ) ) ) {
V_40 = - V_336 ;
goto V_68;
}
F_23 ( V_64 ) ;
return 0 ;
V_68:
F_26 ( V_64 -> V_42 -> V_44 ) ;
V_333:
F_235 ( & V_64 -> V_34 -> V_35 ) ;
F_23 ( V_64 ) ;
return V_40 ;
}
static void F_236 ( struct V_74 * V_75 , T_8 V_177 )
{
struct V_1 * V_64 = F_231 ( V_75 ) ;
if ( V_64 ) {
F_235 ( & V_64 -> V_34 -> V_35 ) ;
F_26 ( V_64 -> V_42 -> V_44 ) ;
F_23 ( V_64 ) ;
}
}
static int F_237 ( struct V_332 * V_85 , struct V_337 * V_338 )
{
struct V_1 * V_64 ;
V_64 = F_231 ( V_85 -> V_86 ) ;
if ( ! V_64 )
return - V_208 ;
if ( ! V_64 -> V_42 ||
! V_64 -> V_42 -> V_339 ) {
F_23 ( V_64 ) ;
return - V_169 ;
}
V_64 -> V_42 -> V_339 ( V_64 -> V_34 , V_338 ) ;
V_338 -> V_340 = F_238 ( V_85 ) >> V_64 -> V_34 -> V_70 ;
F_23 ( V_64 ) ;
return 0 ;
}
static void
F_239 ( void )
{
#ifdef F_240
F_241 () ;
#endif
F_242 () ;
if ( V_341 != NULL ) {
F_243 ( V_341 ) ;
V_341 = NULL ;
}
F_244 () ;
F_245 () ;
if ( V_342 != NULL ) {
F_49 ( V_342 ) ;
V_342 = NULL ;
}
F_116 () ;
}
int F_246 ( struct V_1 * V_2 )
{
struct V_343 V_344 ;
struct V_345 V_346 ;
int V_40 ;
if ( ! V_347 )
return 0 ;
F_247 ( V_2 -> V_56 , & V_344 ) ;
memset ( & V_346 , 0 , sizeof( V_346 ) ) ;
V_346 . V_348 = V_344 . V_349 ;
V_346 . V_350 = sizeof( V_346 ) ;
V_40 = V_345 ( & V_346 ) ;
if ( V_40 == 0 || V_40 == 2 ) {
return V_346 . V_351 & 0x80 ;
} else {
F_118 ( V_60 , L_99 ,
V_344 . V_349 , V_40 ) ;
return 0 ;
}
}
static void F_248 ( void * V_19 , T_9 V_352 )
{
struct V_229 * V_56 = V_19 ;
int V_353 ;
V_353 = F_249 ( V_56 ) ;
if ( V_353 )
F_250 ( L_100 ,
F_35 ( & V_56 -> V_57 ) , V_353 ) ;
}
int F_251 ( struct V_229 * V_56 ,
struct V_354 * V_42 )
{
int V_353 ;
V_353 = F_252 ( V_56 ) ;
if ( V_353 ) {
F_152 ( V_60 , V_56 , L_1 ,
L_101
L_102 ) ;
return V_353 ;
}
V_56 -> V_355 = & F_156 ;
if ( ( F_253 ( V_56 , V_356 ) > 0 ) ||
( V_357 && F_254 ( F_35 ( & V_56 -> V_57 ) ) != 0 ) )
F_255 ( F_248 , V_56 ) ;
return 0 ;
}
void F_256 ( struct V_229 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_56 -> V_355 = NULL ;
V_2 = F_257 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_258 ( V_56 ) ;
return;
}
if ( F_259 ( V_263 , & V_2 -> V_194 ) &&
! F_141 ( V_272 , & V_2 -> V_194 ) ) {
F_23 ( V_2 ) ;
F_258 ( V_56 ) ;
return;
}
F_82 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_260 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
F_258 ( V_56 ) ;
}
int F_261 ( struct V_229 * V_56 ,
struct V_354 * V_45 )
{
struct V_354 * V_42 ;
struct V_1 * V_2 ;
int V_40 ;
F_262 ( V_56 , V_356 , 0 ) ;
V_2 = F_263 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_105 ( V_2 ) ;
V_42 = V_45 ;
if ( V_2 -> V_81 & V_358 ) {
if ( ! V_243 ) {
V_40 = F_264 ( V_359 ) ;
if ( V_40 ) {
F_250 ( L_103
L_104
L_105 ,
F_35 ( & V_56 -> V_57 ) , V_359 ,
V_40 ) ;
F_260 ( V_2 ) ;
return - V_208 ;
}
}
if ( ! V_243 ) {
F_250 ( L_106 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_260 ( V_2 ) ;
return - V_208 ;
}
V_42 = V_243 ;
}
if ( ! F_233 ( V_45 -> V_44 ) ) {
F_260 ( V_2 ) ;
return - V_169 ;
}
if ( ! F_233 ( V_42 -> V_44 ) ) {
F_26 ( V_45 -> V_44 ) ;
F_260 ( V_2 ) ;
return - V_169 ;
}
V_2 -> V_45 = V_45 ;
V_2 -> V_42 = V_42 ;
V_40 = V_42 -> V_360 ( V_2 ) ;
if ( V_40 ) {
F_250 ( L_107 ,
F_35 ( & V_56 -> V_57 ) , V_42 -> V_47 , V_40 ) ;
F_26 ( V_42 -> V_44 ) ;
F_26 ( V_45 -> V_44 ) ;
F_260 ( V_2 ) ;
return V_40 ;
}
F_82 ( V_2 , V_80 ) ;
if ( V_2 -> V_26 <= V_41 ) {
F_250 ( L_108 ,
F_35 ( & V_56 -> V_57 ) ) ;
V_40 = - V_208 ;
F_82 ( V_2 , V_27 ) ;
if ( V_2 -> V_34 )
F_19 ( V_2 -> V_34 ) ;
F_260 ( V_2 ) ;
} else
F_265 ( L_109 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_85 ( V_90 , F_83 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_266 ( struct V_229 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_361 , V_35 , V_40 ;
V_40 = 0 ;
V_2 = F_257 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_105 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_361 = V_2 -> V_34 -> V_85 ? 0 : - 1 ;
V_35 = F_267 ( & V_2 -> V_34 -> V_35 ) ;
if ( V_35 > V_361 ) {
if ( V_35 > 0 )
F_250 ( L_110 ,
F_35 ( & V_56 -> V_57 ) , V_35 ) ;
else
F_250 ( L_111 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_268 ( V_263 , & V_2 -> V_194 ) ;
F_23 ( V_2 ) ;
return - V_211 ;
}
}
if ( F_141 ( V_272 , & V_2 -> V_194 ) ) {
if ( F_259 ( V_263 , & V_2 -> V_194 ) ) {
F_23 ( V_2 ) ;
return - V_211 ;
} else
F_268 ( V_362 , & V_2 -> V_194 ) ;
} else
if ( F_141 ( V_263 , & V_2 -> V_194 ) ) {
F_23 ( V_2 ) ;
return - V_211 ;
}
if ( F_269 ( V_362 , & V_2 -> V_194 ) &&
! F_259 ( V_272 , & V_2 -> V_194 ) ) {
V_40 = F_270 ( V_2 -> V_34 -> V_85 ) ;
if ( V_40 != 0 )
goto V_363;
F_77 ( V_2 ) ;
V_40 = F_195 ( V_281 ,
F_54 ( V_2 ) ) ;
if ( V_40 != 0 )
goto V_363;
}
F_125 ( V_263 , & V_2 -> V_194 ) ;
F_82 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_260 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
return 0 ;
V_363:
F_268 ( V_362 , & V_2 -> V_194 ) ;
F_268 ( V_272 , & V_2 -> V_194 ) ;
F_268 ( V_263 , & V_2 -> V_194 ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
F_271 ( & V_2 -> V_56 -> V_57 , L_112
L_113 ) ;
F_40 ( V_60 , V_2 , L_1 , L_114 ) ;
F_214 ( V_2 , NULL , V_364 ) ;
if ( V_2 -> V_26 < V_62 )
return 0 ;
F_198 (cqr, &device->ccw_queue, devlist)
if ( ( V_99 -> V_203 == V_204 ) ||
( V_99 -> V_203 == V_205 ) ) {
V_99 -> V_203 = V_231 ;
V_99 -> V_200 ++ ;
}
F_181 ( V_2 , V_276 ) ;
F_47 ( V_2 ) ;
F_77 ( V_2 ) ;
return 1 ;
}
int F_272 ( struct V_1 * V_2 )
{
F_234 ( & V_2 -> V_56 -> V_57 , L_115
L_116 ) ;
F_40 ( V_60 , V_2 , L_1 , L_117 ) ;
F_147 ( V_2 , V_276 ) ;
if ( V_2 -> V_260 & V_277 ) {
F_147 ( V_2 , V_277 ) ;
F_81 ( V_2 ) ;
return 1 ;
}
F_77 ( V_2 ) ;
if ( V_2 -> V_34 )
F_62 ( V_2 -> V_34 ) ;
if ( ! V_2 -> V_260 )
F_73 ( & V_283 ) ;
return 1 ;
}
int F_273 ( struct V_229 * V_56 , int V_365 )
{
struct V_1 * V_2 ;
int V_353 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return 0 ;
V_353 = 0 ;
switch ( V_365 ) {
case V_366 :
case V_367 :
case V_368 :
V_2 -> V_219 . V_220 = 0 ;
V_2 -> V_219 . V_223 = 0 ;
V_2 -> V_219 . V_224 = 0 ;
V_353 = F_144 ( V_2 ) ;
break;
case V_369 :
V_353 = 1 ;
if ( V_2 -> V_219 . V_220 )
V_353 = F_272 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_353 ;
}
void F_274 ( struct V_229 * V_56 , int * V_370 )
{
int V_371 ;
T_10 V_372 , V_373 ;
struct V_1 * V_2 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
for ( V_371 = 0 ; V_371 < 8 ; V_371 ++ ) {
V_373 = 0x80 >> V_371 ;
if ( V_370 [ V_371 ] & V_374 ) {
V_372 = V_2 -> V_219 . V_220 ;
V_2 -> V_219 . V_220 &= ~ V_373 ;
V_2 -> V_219 . V_223 &= ~ V_373 ;
V_2 -> V_219 . V_224 &= ~ V_373 ;
if ( V_372 && ! V_2 -> V_219 . V_220 ) {
F_271 ( & V_2 -> V_56 -> V_57 ,
L_118
L_113 ) ;
F_40 ( V_60 , V_2 ,
L_1 , L_119 ) ;
F_214 ( V_2 , NULL , V_364 ) ;
F_181 ( V_2 ,
V_276 ) ;
}
}
if ( V_370 [ V_371 ] & V_375 ) {
V_2 -> V_219 . V_220 &= ~ V_373 ;
V_2 -> V_219 . V_223 &= ~ V_373 ;
V_2 -> V_219 . V_224 &= ~ V_373 ;
V_2 -> V_219 . V_225 |= V_373 ;
F_77 ( V_2 ) ;
}
if ( V_370 [ V_371 ] & V_376 ) {
if ( ! ( V_2 -> V_219 . V_220 & V_373 ) &&
! ( V_2 -> V_219 . V_225 & V_373 ) ) {
V_2 -> V_219 . V_225 |= V_373 ;
F_77 ( V_2 ) ;
}
F_40 ( V_60 , V_2 , L_1 ,
L_120 ) ;
if ( V_2 -> V_42 -> V_97 )
V_2 -> V_42 -> V_97 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
int F_275 ( struct V_1 * V_2 , T_10 V_218 )
{
if ( ! V_2 -> V_219 . V_220 && V_218 ) {
V_2 -> V_219 . V_220 = V_218 ;
F_272 ( V_2 ) ;
} else
V_2 -> V_219 . V_220 |= V_218 ;
return 0 ;
}
int F_276 ( struct V_229 * V_56 )
{
struct V_1 * V_2 = F_257 ( V_56 ) ;
struct V_102 V_377 ;
struct V_98 * V_99 , * V_266 ;
struct V_98 * V_290 ;
int V_40 ;
if ( F_30 ( V_2 ) )
return F_105 ( V_2 ) ;
F_125 ( V_378 , & V_2 -> V_194 ) ;
if ( V_2 -> V_42 -> V_379 )
V_40 = V_2 -> V_42 -> V_379 ( V_2 ) ;
F_181 ( V_2 , V_380 ) ;
F_12 ( & V_377 ) ;
F_175 ( F_146 ( V_56 ) ) ;
V_40 = 0 ;
F_176 (cqr, n, &device->ccw_queue, devlist) {
if ( V_99 -> V_203 == V_204 ) {
V_40 = V_2 -> V_42 -> V_273 ( V_99 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_121
L_122 , V_99 ) ;
F_177 ( F_146 ( V_56 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
}
F_166 ( & V_99 -> V_259 , & V_377 ) ;
}
F_177 ( F_146 ( V_56 ) ) ;
F_176 (cqr, n, &freeze_queue, devlist) {
F_85 ( V_238 ,
( V_99 -> V_203 != V_205 ) ) ;
if ( V_99 -> V_203 == V_210 )
V_99 -> V_203 = V_231 ;
if ( F_218 ( V_99 ) )
continue;
F_169 ( & V_99 -> V_259 ) ;
while ( V_99 -> V_290 != NULL ) {
V_290 = V_99 -> V_290 ;
F_277 ( & V_99 -> V_293 ) ;
F_278 ( V_99 , V_99 -> V_381 ) ;
V_99 = V_290 ;
}
if ( V_99 -> V_34 )
F_169 ( & V_99 -> V_293 ) ;
V_99 -> V_34 -> V_64 -> V_42 -> V_311 (
V_99 , (struct V_100 * ) V_99 -> V_268 ) ;
}
if ( ! F_55 ( & V_377 ) ) {
F_175 ( F_146 ( V_56 ) ) ;
F_279 ( & V_377 , & V_2 -> V_15 ) ;
F_177 ( F_146 ( V_56 ) ) ;
}
F_23 ( V_2 ) ;
return V_40 ;
}
int F_280 ( struct V_229 * V_56 )
{
struct V_1 * V_2 = F_257 ( V_56 ) ;
int V_40 = 0 ;
if ( F_30 ( V_2 ) )
return F_105 ( V_2 ) ;
F_147 ( V_2 ,
( V_380 | V_277 ) ) ;
F_77 ( V_2 ) ;
if ( V_2 -> V_42 -> V_95 && ! ( V_2 -> V_260 ) )
V_40 = V_2 -> V_42 -> V_95 ( V_2 ) ;
if ( V_40 || V_2 -> V_260 )
V_2 -> V_260 |= V_277 ;
if ( V_2 -> V_34 )
F_62 ( V_2 -> V_34 ) ;
F_268 ( V_378 , & V_2 -> V_194 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_98 * F_281 ( struct V_1 * V_2 ,
void * V_382 ,
int V_383 ,
int V_188 )
{
struct V_98 * V_99 ;
struct V_191 * V_196 ;
unsigned long * V_384 ;
V_99 = F_126 ( V_188 , 1 , V_383 , V_2 ) ;
if ( F_30 ( V_99 ) ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_65
L_66 , L_123 ) ;
return V_99 ;
}
V_196 = V_99 -> V_192 ;
V_196 -> V_385 = V_386 ;
if ( F_282 ( V_382 , V_383 ) ) {
V_384 = ( unsigned long * ) ( V_99 -> V_19 ) ;
V_196 -> V_387 = ( V_388 ) ( V_389 ) V_384 ;
V_196 -> V_194 = V_390 ;
V_384 = F_283 ( V_384 , V_382 , V_383 ) ;
} else {
V_196 -> V_387 = ( V_388 ) ( V_389 ) V_382 ;
V_196 -> V_194 = 0 ;
}
V_196 -> V_391 = V_383 ;
V_99 -> V_109 = V_2 ;
V_99 -> V_381 = V_2 ;
V_99 -> V_228 = 10 * V_274 ;
V_99 -> V_200 = 256 ;
V_99 -> V_149 = F_137 () ;
V_99 -> V_203 = V_286 ;
return V_99 ;
}
int F_284 ( struct V_1 * V_2 , int V_188 ,
void * V_382 , int V_383 )
{
int V_353 ;
struct V_98 * V_99 ;
V_99 = F_281 ( V_2 , V_382 , V_383 ,
V_188 ) ;
if ( F_30 ( V_99 ) )
return F_105 ( V_99 ) ;
V_353 = F_200 ( V_99 ) ;
F_132 ( V_99 , V_99 -> V_381 ) ;
return V_353 ;
}
char * F_159 ( struct V_232 * V_232 )
{
struct V_392 * V_392 = NULL ;
char * V_237 = NULL ;
if ( F_285 ( & V_232 -> V_240 ) && ( V_232 -> V_240 . V_393 . V_394 == 0x01 ) ) {
if ( V_232 -> V_240 . V_393 . V_395 )
V_392 = F_286 ( (struct V_395 * ) ( unsigned long )
V_232 -> V_240 . V_393 . V_395 ) ;
if ( V_392 && V_392 -> V_396 == 64 && V_392 -> V_194 )
switch ( V_392 -> V_194 & 0x07 ) {
case 1 :
V_237 = V_392 -> V_397 . V_398 . V_237 ;
break;
case 2 :
V_237 = V_392 -> V_397 . V_399 . V_237 ;
break;
default:
break;
}
} else if ( V_232 -> V_254 . V_400 . V_401 . V_402 ) {
V_237 = V_232 -> V_403 ;
}
return V_237 ;
}
void F_287 ( struct V_229 * V_56 )
{
struct V_1 * V_2 ;
V_2 = F_257 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_34 )
F_62 ( V_2 -> V_34 ) ;
F_77 ( V_2 ) ;
F_85 ( V_281 , F_54 ( V_2 ) ) ;
}
static int T_11 F_288 ( void )
{
int V_40 ;
F_289 ( & V_90 ) ;
F_289 ( & V_238 ) ;
F_289 ( & V_283 ) ;
F_289 ( & V_281 ) ;
V_342 = F_37 ( L_33 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_342 == NULL ) {
V_40 = - V_4 ;
goto V_404;
}
F_38 ( V_342 , & V_59 ) ;
F_39 ( V_342 , V_60 ) ;
F_118 ( V_61 , L_1 , L_2 ) ;
V_243 = NULL ;
F_117 () ;
V_40 = F_290 () ;
if ( V_40 )
goto V_404;
V_40 = F_291 () ;
if ( V_40 )
goto V_404;
V_40 = F_292 () ;
if ( V_40 )
goto V_404;
V_40 = F_293 () ;
if ( V_40 )
goto V_404;
#ifdef F_240
V_40 = F_294 () ;
if ( V_40 )
goto V_404;
#endif
return 0 ;
V_404:
F_295 ( L_124 ) ;
F_239 () ;
return V_40 ;
}
