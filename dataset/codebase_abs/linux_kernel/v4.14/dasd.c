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
F_14 ( & V_2 -> V_26 , V_27 ) ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_29 ;
F_15 ( & V_2 -> V_31 ) ;
F_9 ( & V_2 -> V_32 . V_33 ) ;
return V_2 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_34 ) ;
F_17 ( ( unsigned long ) V_2 -> V_7 ) ;
F_7 ( ( unsigned long ) V_2 -> V_5 , 1 ) ;
F_5 ( V_2 ) ;
}
struct V_35 * F_18 ( void )
{
struct V_35 * V_36 ;
V_36 = F_2 ( sizeof( * V_36 ) , V_3 ) ;
if ( ! V_36 )
return F_3 ( - V_4 ) ;
F_10 ( & V_36 -> V_37 , - 1 ) ;
F_10 ( & V_36 -> V_12 , 0 ) ;
F_11 ( & V_36 -> V_13 ,
( void (*) ( unsigned long ) ) V_38 ,
( unsigned long ) V_36 ) ;
F_12 ( & V_36 -> V_15 ) ;
F_9 ( & V_36 -> V_39 ) ;
F_13 ( & V_36 -> V_16 ) ;
V_36 -> V_16 . V_17 = V_40 ;
V_36 -> V_16 . V_19 = ( unsigned long ) V_36 ;
F_9 ( & V_36 -> V_32 . V_33 ) ;
return V_36 ;
}
void F_19 ( struct V_35 * V_36 )
{
F_5 ( V_36 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_41 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_36 ) {
V_41 = F_22 ( V_2 -> V_36 ) ;
if ( V_41 ) {
F_23 ( V_2 ) ;
return V_41 ;
}
}
V_2 -> V_28 = V_42 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
V_2 -> V_28 = V_29 ;
if ( V_2 -> V_36 )
F_26 ( V_2 -> V_36 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_43 * F_27 ( const char * V_44 ,
struct V_43 * V_45 )
{
struct V_43 * V_46 ;
if ( ! V_45 )
return NULL ;
V_46 = F_28 ( V_44 , V_45 ) ;
if ( ! V_46 || F_29 ( V_46 ) )
return NULL ;
return V_46 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_41 = 0 ;
if ( V_36 ) {
V_41 = F_31 ( V_36 ) ;
if ( V_41 )
return V_41 ;
V_36 -> V_47 =
F_27 ( V_36 -> V_48 -> V_49 ,
V_50 ) ;
F_32 ( & V_36 -> V_32 , V_36 -> V_47 ) ;
if ( V_51 == V_52 )
F_33 ( & V_2 -> V_36 -> V_32 ) ;
}
V_2 -> V_47 =
F_27 ( F_34 ( & V_2 -> V_53 -> V_54 ) ,
V_50 ) ;
F_32 ( & V_2 -> V_32 , V_2 -> V_47 ) ;
F_35 ( V_2 -> V_47 , V_2 ) ;
V_2 -> V_55 = F_36 ( F_34 ( & V_2 -> V_53 -> V_54 ) , 4 , 1 ,
8 * sizeof( long ) ) ;
F_37 ( V_2 -> V_55 , & V_56 ) ;
F_38 ( V_2 -> V_55 , V_57 ) ;
F_39 ( V_58 , V_2 , L_1 , L_2 ) ;
V_2 -> V_28 = V_59 ;
return V_41 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_41 ;
if ( V_2 -> V_60 -> V_61 ) {
V_41 = V_2 -> V_60 -> V_61 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_2 -> V_36 ) {
F_41 ( & V_2 -> V_36 -> V_32 ) ;
F_42 ( V_2 -> V_36 -> V_47 ) ;
F_43 ( V_2 -> V_36 ) ;
F_44 ( V_2 -> V_36 ) ;
}
V_41 = F_45 ( V_2 ) ;
if ( V_41 )
return V_41 ;
F_46 ( V_2 ) ;
F_41 ( & V_2 -> V_32 ) ;
F_47 ( V_2 ) ;
F_42 ( V_2 -> V_47 ) ;
F_39 ( V_58 , V_2 , L_3 , V_2 ) ;
if ( V_2 -> V_55 != NULL ) {
F_48 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
}
V_2 -> V_28 = V_42 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_41 ;
struct V_35 * V_36 ;
struct V_62 * V_63 ;
V_41 = 0 ;
V_36 = V_2 -> V_36 ;
if ( V_36 ) {
if ( V_36 -> V_64 -> V_60 -> V_65 != NULL )
V_41 = V_36 -> V_64 -> V_60 -> V_65 ( V_36 ) ;
if ( V_41 ) {
if ( V_41 != - V_66 ) {
V_2 -> V_28 = V_67 ;
V_63 = V_2 -> V_36 -> V_48 ;
F_50 ( & F_51 ( V_63 ) -> V_68 ,
V_69 ) ;
goto V_70;
}
return V_41 ;
}
F_52 ( V_36 ) ;
F_53 ( V_36 -> V_48 ,
V_36 -> V_71 << V_36 -> V_72 ) ;
V_2 -> V_28 = V_73 ;
V_41 = F_54 ( V_36 ) ;
if ( V_41 ) {
V_2 -> V_28 = V_59 ;
return V_41 ;
}
} else {
V_2 -> V_28 = V_73 ;
}
V_70:
if ( V_2 -> V_60 -> V_74 )
V_41 = V_2 -> V_60 -> V_74 ( V_2 ) ;
return V_41 ;
}
static inline
int F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 )
return F_56 ( & V_2 -> V_15 ) &&
F_56 ( & V_2 -> V_36 -> V_15 ) ;
else
return F_56 ( & V_2 -> V_15 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_41 ;
V_2 -> V_28 = V_59 ;
if ( V_2 -> V_36 ) {
struct V_35 * V_36 = V_2 -> V_36 ;
V_41 = F_58 ( V_36 ) ;
if ( V_41 ) {
V_2 -> V_28 = V_73 ;
return V_41 ;
}
F_59 ( V_36 ) ;
V_36 -> V_71 = 0 ;
V_36 -> V_75 = 0 ;
V_36 -> V_72 = 0 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
V_2 -> V_28 = V_59 ;
return 0 ;
}
static int
F_61 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
V_2 -> V_28 = V_80 ;
if ( V_2 -> V_36 ) {
F_62 ( V_2 -> V_36 ) ;
if ( ( V_2 -> V_81 & V_82 ) ) {
V_63 = V_2 -> V_36 -> V_48 ;
F_50 ( & F_51 ( V_63 ) -> V_68 , V_69 ) ;
return 0 ;
}
V_63 = V_2 -> V_36 -> V_83 -> V_84 ;
F_63 ( & V_77 , V_63 , V_85 ) ;
while ( ( V_79 = F_64 ( & V_77 ) ) )
F_50 ( & F_65 ( V_79 ) -> V_68 , V_69 ) ;
F_66 ( & V_77 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_41 ;
struct V_62 * V_63 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
if ( V_2 -> V_60 -> V_86 ) {
V_41 = V_2 -> V_60 -> V_86 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
V_2 -> V_28 = V_73 ;
if ( V_2 -> V_36 && ! ( V_2 -> V_81 & V_82 ) ) {
V_63 = V_2 -> V_36 -> V_83 -> V_84 ;
F_63 ( & V_77 , V_63 , V_85 ) ;
while ( ( V_79 = F_64 ( & V_77 ) ) )
F_50 ( & F_65 ( V_79 ) -> V_68 , V_69 ) ;
F_66 ( & V_77 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_41 ;
V_41 = 0 ;
if ( V_2 -> V_28 == V_29 &&
V_2 -> V_30 >= V_42 )
V_41 = F_20 ( V_2 ) ;
if ( ! V_41 &&
V_2 -> V_28 == V_42 &&
V_2 -> V_30 >= V_59 )
V_41 = F_30 ( V_2 ) ;
if ( ! V_41 &&
V_2 -> V_28 == V_59 &&
V_2 -> V_30 >= V_73 )
V_41 = F_49 ( V_2 ) ;
if ( ! V_41 &&
V_2 -> V_28 == V_67 &&
V_2 -> V_30 > V_67 )
V_41 = - V_87 ;
if ( ! V_41 &&
V_2 -> V_28 == V_73 &&
V_2 -> V_30 >= V_80 )
V_41 = F_61 ( V_2 ) ;
return V_41 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_41 ;
V_41 = 0 ;
if ( V_2 -> V_28 == V_80 &&
V_2 -> V_30 <= V_73 )
V_41 = F_67 ( V_2 ) ;
if ( ! V_41 &&
V_2 -> V_28 == V_73 &&
V_2 -> V_30 <= V_59 )
V_41 = F_57 ( V_2 ) ;
if ( ! V_41 &&
V_2 -> V_28 == V_67 &&
V_2 -> V_30 <= V_59 )
V_41 = F_60 ( V_2 ) ;
if ( ! V_41 &&
V_2 -> V_28 == V_59 &&
V_2 -> V_30 <= V_42 )
V_41 = F_40 ( V_2 ) ;
if ( ! V_41 &&
V_2 -> V_28 == V_42 &&
V_2 -> V_30 <= V_29 )
V_41 = F_24 ( V_2 ) ;
return V_41 ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_41 ;
if ( V_2 -> V_28 == V_2 -> V_30 )
return;
if ( V_2 -> V_28 < V_2 -> V_30 )
V_41 = F_68 ( V_2 ) ;
else
V_41 = F_69 ( V_2 ) ;
if ( V_41 == - V_66 )
return;
if ( V_41 )
V_2 -> V_30 = V_2 -> V_28 ;
F_50 ( & V_2 -> V_53 -> V_54 . V_68 , V_69 ) ;
if ( V_2 -> V_28 == V_2 -> V_30 )
F_71 ( & V_88 ) ;
}
static void V_21 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_90 , struct V_1 , V_20 ) ;
F_73 ( & V_2 -> V_31 ) ;
F_70 ( V_2 ) ;
F_74 ( & V_2 -> V_31 ) ;
F_75 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_77 ( & V_2 -> V_20 ) )
F_23 ( V_2 ) ;
}
static void V_25 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_90 , struct V_1 ,
V_24 ) ;
V_2 -> V_60 -> V_91 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_77 ( & V_2 -> V_24 ) )
F_23 ( V_2 ) ;
}
static void V_23 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_90 , struct V_1 ,
V_22 ) ;
V_2 -> V_53 -> V_92 -> V_93 ( V_2 -> V_53 ) ;
F_23 ( V_2 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_77 ( & V_2 -> V_22 ) )
F_23 ( V_2 ) ;
}
void F_80 ( struct V_1 * V_2 , int V_30 )
{
F_21 ( V_2 ) ;
F_73 ( & V_2 -> V_31 ) ;
if ( V_94 && V_30 > V_73 )
V_30 = V_73 ;
if ( V_2 -> V_30 != V_30 ) {
if ( V_2 -> V_28 == V_30 )
F_71 ( & V_88 ) ;
V_2 -> V_30 = V_30 ;
}
if ( V_2 -> V_28 != V_2 -> V_30 )
F_70 ( V_2 ) ;
F_74 ( & V_2 -> V_31 ) ;
F_23 ( V_2 ) ;
}
static inline int F_81 ( struct V_1 * V_2 )
{
return ( V_2 -> V_28 == V_2 -> V_30 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_80 ( V_2 , V_80 ) ;
if ( V_2 -> V_28 <= V_42 )
F_80 ( V_2 , V_29 ) ;
F_83 ( V_88 , F_81 ( V_2 ) ) ;
F_78 ( V_2 ) ;
if ( V_2 -> V_60 -> V_95 )
V_2 -> V_60 -> V_95 ( V_2 ) ;
}
static void F_84 ( struct V_35 * V_36 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 ;
unsigned int V_102 ;
struct V_1 * V_2 ;
V_102 = 0 ;
if ( V_51 || V_36 -> V_32 . V_19 )
F_85 (l, &block->ccw_queue)
if ( ++ V_102 >= 31 )
break;
F_86 ( & V_103 . V_33 ) ;
if ( V_103 . V_19 ) {
V_103 . V_19 -> V_104 [ V_102 ] ++ ;
if ( F_87 ( V_99 ) == V_105 )
V_103 . V_19 -> V_106 [ V_102 ] ++ ;
}
F_88 ( & V_103 . V_33 ) ;
F_86 ( & V_36 -> V_32 . V_33 ) ;
if ( V_36 -> V_32 . V_19 ) {
V_36 -> V_32 . V_19 -> V_104 [ V_102 ] ++ ;
if ( F_87 ( V_99 ) == V_105 )
V_36 -> V_32 . V_19 -> V_106 [ V_102 ] ++ ;
}
F_88 ( & V_36 -> V_32 . V_33 ) ;
V_2 = V_97 -> V_107 ;
if ( V_2 -> V_32 . V_19 ) {
V_102 = 1 ;
F_85 (l, &device->ccw_queue)
if ( ++ V_102 >= 31 )
break;
}
F_86 ( & V_2 -> V_32 . V_33 ) ;
if ( V_2 -> V_32 . V_19 ) {
V_2 -> V_32 . V_19 -> V_104 [ V_102 ] ++ ;
if ( F_87 ( V_99 ) == V_105 )
V_2 -> V_32 . V_19 -> V_106 [ V_102 ] ++ ;
}
F_88 ( & V_2 -> V_32 . V_33 ) ;
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
static void F_91 ( struct V_35 * V_36 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
unsigned long V_142 , V_143 , V_144 , V_145 ;
unsigned long V_146 , V_112 ;
struct V_1 * V_2 ;
int V_113 , V_114 , V_115 , V_116 ;
int V_117 , V_118 , V_119 ;
struct V_108 * V_19 ;
V_2 = V_97 -> V_107 ;
if ( ! ( V_51 ||
V_36 -> V_32 . V_19 ||
V_2 -> V_32 . V_19 ) )
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
F_86 ( & V_103 . V_33 ) ;
if ( V_103 . V_19 ) {
V_19 = V_103 . V_19 ;
V_19 -> V_151 += V_145 ;
V_19 -> V_152 += V_142 ;
V_19 -> V_153 += V_143 ;
V_19 -> V_154 += V_144 ;
F_89 ( V_103 . V_19 ,
V_97 -> V_107 != V_36 -> V_64 ,
V_97 -> V_155 == 1 ,
F_87 ( V_99 ) == V_105 ,
V_112 , V_113 , V_114 ,
V_115 , V_116 ,
V_117 , V_118 ,
V_119 ) ;
}
F_88 ( & V_103 . V_33 ) ;
F_86 ( & V_36 -> V_32 . V_33 ) ;
if ( V_36 -> V_32 . V_19 ) {
V_19 = V_36 -> V_32 . V_19 ;
V_19 -> V_151 += V_145 ;
V_19 -> V_152 += V_142 ;
V_19 -> V_153 += V_143 ;
V_19 -> V_154 += V_144 ;
F_89 ( V_36 -> V_32 . V_19 ,
V_97 -> V_107 != V_36 -> V_64 ,
V_97 -> V_155 == 1 ,
F_87 ( V_99 ) == V_105 ,
V_112 , V_113 , V_114 ,
V_115 , V_116 ,
V_117 , V_118 ,
V_119 ) ;
}
F_88 ( & V_36 -> V_32 . V_33 ) ;
F_86 ( & V_2 -> V_32 . V_33 ) ;
if ( V_2 -> V_32 . V_19 ) {
V_19 = V_2 -> V_32 . V_19 ;
V_19 -> V_151 += V_145 ;
V_19 -> V_152 += V_142 ;
V_19 -> V_153 += V_143 ;
V_19 -> V_154 += V_144 ;
F_89 ( V_2 -> V_32 . V_19 ,
V_97 -> V_107 != V_36 -> V_64 ,
V_97 -> V_155 == 1 ,
F_87 ( V_99 ) == V_105 ,
V_112 , V_113 , V_114 ,
V_115 , V_116 ,
V_117 , V_118 ,
V_119 ) ;
}
F_88 ( & V_2 -> V_32 . V_33 ) ;
}
void F_94 ( struct V_156 * V_32 )
{
struct V_108 * V_19 ;
F_95 ( & V_32 -> V_33 ) ;
V_19 = V_32 -> V_19 ;
if ( ! V_19 ) {
F_96 ( & V_32 -> V_33 ) ;
return;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_90 ( & V_19 -> V_122 ) ;
F_96 ( & V_32 -> V_33 ) ;
}
int F_33 ( struct V_156 * V_32 )
{
struct V_108 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_157 ) ;
if ( ! V_19 )
return - V_4 ;
F_95 ( & V_32 -> V_33 ) ;
if ( V_32 -> V_19 ) {
F_96 ( & V_32 -> V_33 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_90 ( & V_19 -> V_122 ) ;
V_32 -> V_19 = V_19 ;
F_96 ( & V_32 -> V_33 ) ;
return 0 ;
}
void F_97 ( struct V_156 * V_32 )
{
F_95 ( & V_32 -> V_33 ) ;
F_5 ( V_32 -> V_19 ) ;
V_32 -> V_19 = NULL ;
F_96 ( & V_32 -> V_33 ) ;
}
char * F_98 ( const char T_1 * V_158 , T_2 V_159 )
{
char * V_160 ;
V_160 = F_99 ( V_159 + 1 ) ;
if ( V_160 == NULL )
return F_3 ( - V_4 ) ;
if ( F_100 ( V_160 , V_158 , V_159 ) != 0 ) {
F_101 ( V_160 ) ;
return F_3 ( - V_161 ) ;
}
if ( V_160 [ V_159 - 1 ] == '\n' )
V_160 [ V_159 - 1 ] = 0 ;
else
V_160 [ V_159 ] = 0 ;
return V_160 ;
}
static T_3 F_102 ( struct V_162 * V_162 ,
const char T_1 * V_158 ,
T_2 V_159 , T_4 * V_163 )
{
char * V_160 , * V_164 ;
int V_41 ;
struct V_165 * V_166 = (struct V_165 * ) V_162 -> V_167 ;
struct V_156 * V_168 = V_166 -> V_34 ;
if ( V_159 > 65536 )
V_159 = 65536 ;
V_160 = F_98 ( V_158 , V_159 ) ;
if ( F_29 ( V_160 ) )
return F_103 ( V_160 ) ;
V_164 = F_104 ( V_160 ) ;
V_41 = V_159 ;
if ( strncmp ( V_164 , L_4 , 5 ) == 0 ) {
F_94 ( V_168 ) ;
} else if ( strncmp ( V_164 , L_5 , 2 ) == 0 ) {
V_41 = F_33 ( V_168 ) ;
if ( V_41 )
goto V_70;
V_41 = V_159 ;
if ( V_168 == & V_103 ) {
F_94 ( V_168 ) ;
V_51 = V_169 ;
}
} else if ( strncmp ( V_164 , L_6 , 3 ) == 0 ) {
if ( V_168 == & V_103 )
V_51 = V_170 ;
F_97 ( V_168 ) ;
} else
V_41 = - V_171 ;
V_70:
F_101 ( V_160 ) ;
return V_41 ;
}
static void F_105 ( struct V_165 * V_166 , unsigned int * V_172 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < 32 ; V_173 ++ )
F_106 ( V_166 , L_7 , V_172 [ V_173 ] ) ;
F_107 ( V_166 , '\n' ) ;
}
static void F_108 ( struct V_165 * V_166 ,
struct V_108 * V_19 )
{
F_106 ( V_166 , L_8 ,
V_19 -> V_122 . V_174 , V_19 -> V_122 . V_175 ) ;
F_106 ( V_166 , L_9 , V_19 -> V_120 ) ;
F_106 ( V_166 , L_10 , V_19 -> V_123 ) ;
F_106 ( V_166 , L_11 , V_19 -> V_124 ) ;
F_106 ( V_166 , L_12 , V_19 -> V_125 ) ;
F_106 ( V_166 , L_13 , V_19 -> V_120 ?
V_19 -> V_151 / V_19 -> V_120 : 0UL ) ;
F_106 ( V_166 , L_14 , V_19 -> V_120 ?
V_19 -> V_152 / V_19 -> V_120 : 0UL ) ;
F_106 ( V_166 , L_15 , V_19 -> V_120 ?
V_19 -> V_153 / V_19 -> V_120 : 0UL ) ;
F_106 ( V_166 , L_16 , V_19 -> V_120 ?
V_19 -> V_154 / V_19 -> V_120 : 0UL ) ;
F_109 ( V_166 , L_17 ) ;
F_105 ( V_166 , V_19 -> V_126 ) ;
F_109 ( V_166 , L_18 ) ;
F_105 ( V_166 , V_19 -> V_127 ) ;
F_109 ( V_166 , L_19 ) ;
F_105 ( V_166 , V_19 -> V_128 ) ;
F_109 ( V_166 , L_20 ) ;
F_105 ( V_166 , V_19 -> V_129 ) ;
F_109 ( V_166 , L_21 ) ;
F_105 ( V_166 , V_19 -> V_130 ) ;
F_109 ( V_166 , L_22 ) ;
F_105 ( V_166 , V_19 -> V_131 ) ;
F_109 ( V_166 , L_23 ) ;
F_105 ( V_166 , V_19 -> V_132 ) ;
F_109 ( V_166 , L_24 ) ;
F_105 ( V_166 , V_19 -> V_104 ) ;
F_106 ( V_166 , L_25 , V_19 -> V_133 ) ;
F_106 ( V_166 , L_26 , V_19 -> V_134 ) ;
F_106 ( V_166 , L_27 , V_19 -> V_135 ) ;
F_106 ( V_166 , L_28 , V_19 -> V_136 ) ;
F_109 ( V_166 , L_29 ) ;
F_105 ( V_166 , V_19 -> V_137 ) ;
F_109 ( V_166 , L_30 ) ;
F_105 ( V_166 , V_19 -> V_138 ) ;
F_109 ( V_166 , L_31 ) ;
F_105 ( V_166 , V_19 -> V_139 ) ;
F_109 ( V_166 , L_32 ) ;
F_105 ( V_166 , V_19 -> V_140 ) ;
F_109 ( V_166 , L_33 ) ;
F_105 ( V_166 , V_19 -> V_141 ) ;
F_109 ( V_166 , L_34 ) ;
F_105 ( V_166 , V_19 -> V_106 ) ;
}
static int F_110 ( struct V_165 * V_166 , void * V_176 )
{
struct V_156 * V_32 ;
struct V_108 * V_19 ;
V_32 = V_166 -> V_34 ;
F_95 ( & V_32 -> V_33 ) ;
V_19 = V_32 -> V_19 ;
if ( ! V_19 ) {
F_96 ( & V_32 -> V_33 ) ;
F_109 ( V_166 , L_35 ) ;
return 0 ;
}
F_108 ( V_166 , V_19 ) ;
F_96 ( & V_32 -> V_33 ) ;
return 0 ;
}
static int F_111 ( struct V_177 * V_177 , struct V_162 * V_162 )
{
struct V_156 * V_32 = V_177 -> V_178 ;
return F_112 ( V_162 , F_110 , V_32 ) ;
}
static void F_32 ( struct V_156 * V_32 ,
struct V_43 * V_45 )
{
T_5 V_179 ;
struct V_43 * V_46 ;
if ( ! V_45 )
return;
V_32 -> V_43 = NULL ;
V_32 -> V_19 = NULL ;
V_179 = ( V_180 | V_181 | V_182 ) ;
V_46 = F_113 ( L_36 , V_179 , V_45 ,
V_32 , & V_183 ) ;
if ( V_46 && ! F_29 ( V_46 ) )
V_32 -> V_43 = V_46 ;
return;
}
static void F_41 ( struct V_156 * V_32 )
{
F_97 ( V_32 ) ;
F_42 ( V_32 -> V_43 ) ;
V_32 -> V_43 = NULL ;
}
static void F_114 ( void )
{
V_51 = V_170 ;
F_41 ( & V_103 ) ;
F_42 ( V_184 ) ;
F_42 ( V_50 ) ;
}
static void F_115 ( void )
{
struct V_43 * V_46 ;
V_50 = NULL ;
V_46 = F_28 ( L_37 , NULL ) ;
if ( ! V_46 || F_29 ( V_46 ) )
goto error;
V_50 = V_46 ;
V_46 = F_28 ( L_38 , V_50 ) ;
if ( ! V_46 || F_29 ( V_46 ) )
goto error;
V_184 = V_46 ;
F_32 ( & V_103 , V_184 ) ;
return;
error:
F_116 ( V_185 , L_1 ,
L_39 ) ;
F_114 () ;
return;
}
static void F_115 ( void )
{
return;
}
static void F_114 ( void )
{
return;
}
int F_117 ( struct V_165 * V_166 , void * V_176 )
{
F_109 ( V_166 , L_40 ) ;
return 0 ;
}
static void F_32 ( struct V_156 * V_32 ,
struct V_43 * V_45 )
{
return;
}
static void F_41 ( struct V_156 * V_32 )
{
return;
}
int F_33 ( struct V_156 * V_32 )
{
return 0 ;
}
static int F_118 ( struct V_165 * V_166 , void * V_176 )
{
struct V_1 * V_2 ;
int V_41 = - V_186 ;
V_2 = V_166 -> V_34 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_60 -> V_187 )
V_41 = V_2 -> V_60 -> V_187 ( V_2 , V_166 ) ;
F_23 ( V_2 ) ;
return V_41 ;
}
static int F_119 ( struct V_177 * V_177 , struct V_162 * V_162 )
{
struct V_1 * V_2 = V_177 -> V_178 ;
return F_112 ( V_162 , F_118 , V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_42 ( V_2 -> V_188 ) ;
V_2 -> V_188 = NULL ;
}
static void F_35 ( struct V_43 * V_45 ,
struct V_1 * V_2 )
{
struct V_43 * V_46 ;
T_5 V_179 ;
if ( ! V_45 )
return;
V_179 = V_180 | V_182 ;
V_46 = F_113 ( L_41 , V_179 , V_45 ,
V_2 , & V_189 ) ;
if ( V_46 && ! F_29 ( V_46 ) )
V_2 -> V_188 = V_46 ;
}
struct V_96 * F_120 ( int V_190 , int V_191 ,
int V_192 ,
struct V_1 * V_2 )
{
struct V_96 * V_97 ;
F_121 ( V_192 > V_9 ||
( V_191 * sizeof( struct V_193 ) ) > V_9 ) ;
V_97 = F_2 ( sizeof( struct V_96 ) , V_3 ) ;
if ( V_97 == NULL )
return F_3 ( - V_4 ) ;
V_97 -> V_194 = NULL ;
if ( V_191 > 0 ) {
V_97 -> V_194 = F_122 ( V_191 , sizeof( struct V_193 ) ,
V_3 | V_6 ) ;
if ( V_97 -> V_194 == NULL ) {
F_5 ( V_97 ) ;
return F_3 ( - V_4 ) ;
}
}
V_97 -> V_19 = NULL ;
if ( V_192 > 0 ) {
V_97 -> V_19 = F_2 ( V_192 , V_3 | V_6 ) ;
if ( V_97 -> V_19 == NULL ) {
F_5 ( V_97 -> V_194 ) ;
F_5 ( V_97 ) ;
return F_3 ( - V_4 ) ;
}
}
V_97 -> V_190 = V_190 ;
F_123 ( V_195 , & V_97 -> V_196 ) ;
F_21 ( V_2 ) ;
return V_97 ;
}
struct V_96 * F_124 ( int V_190 , int V_191 ,
int V_192 ,
struct V_1 * V_2 )
{
unsigned long V_196 ;
struct V_96 * V_97 ;
char * V_19 ;
int V_197 ;
V_197 = ( sizeof( struct V_96 ) + 7L ) & - 8L ;
if ( V_191 > 0 )
V_197 += V_191 * sizeof( struct V_193 ) ;
if ( V_192 > 0 )
V_197 += V_192 ;
F_125 ( & V_2 -> V_11 , V_196 ) ;
V_97 = (struct V_96 * )
F_126 ( & V_2 -> V_8 , V_197 ) ;
F_127 ( & V_2 -> V_11 , V_196 ) ;
if ( V_97 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_97 , 0 , sizeof( struct V_96 ) ) ;
V_19 = ( char * ) V_97 + ( ( sizeof( struct V_96 ) + 7L ) & - 8L ) ;
V_97 -> V_194 = NULL ;
if ( V_191 > 0 ) {
V_97 -> V_194 = (struct V_193 * ) V_19 ;
V_19 += V_191 * sizeof( struct V_193 ) ;
memset ( V_97 -> V_194 , 0 , V_191 * sizeof( struct V_193 ) ) ;
}
V_97 -> V_19 = NULL ;
if ( V_192 > 0 ) {
V_97 -> V_19 = V_19 ;
memset ( V_97 -> V_19 , 0 , V_192 ) ;
}
V_97 -> V_190 = V_190 ;
F_123 ( V_195 , & V_97 -> V_196 ) ;
F_21 ( V_2 ) ;
return V_97 ;
}
void F_128 ( struct V_96 * V_97 , struct V_1 * V_2 )
{
struct V_193 * V_198 ;
V_198 = V_97 -> V_194 ;
do {
F_129 ( V_198 ) ;
} while ( V_198 ++ -> V_196 & ( V_199 | V_200 ) );
F_5 ( V_97 -> V_194 ) ;
F_5 ( V_97 -> V_19 ) ;
F_5 ( V_97 ) ;
F_23 ( V_2 ) ;
}
void F_130 ( struct V_96 * V_97 , struct V_1 * V_2 )
{
unsigned long V_196 ;
F_125 ( & V_2 -> V_11 , V_196 ) ;
F_131 ( & V_2 -> V_8 , V_97 ) ;
F_127 ( & V_2 -> V_11 , V_196 ) ;
F_23 ( V_2 ) ;
}
static inline int F_132 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
if ( V_97 == NULL )
return - V_171 ;
V_2 = V_97 -> V_107 ;
if ( strncmp ( ( char * ) & V_97 -> V_190 , V_2 -> V_60 -> V_201 , 4 ) ) {
F_39 ( V_57 , V_2 ,
L_42
L_43 ,
V_97 -> V_190 ,
* ( unsigned int * ) V_2 -> V_60 -> V_44 ) ;
return - V_171 ;
}
return 0 ;
}
int F_133 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_202 , V_41 ;
char V_203 [ V_204 ] ;
V_41 = F_132 ( V_97 ) ;
if ( V_41 )
return V_41 ;
V_202 = 0 ;
V_2 = (struct V_1 * ) V_97 -> V_107 ;
while ( ( V_202 < 5 ) && ( V_97 -> V_205 == V_206 ) ) {
V_41 = F_134 ( V_2 -> V_53 , ( long ) V_97 ) ;
switch ( V_41 ) {
case 0 :
V_97 -> V_205 = V_207 ;
V_97 -> V_149 = F_135 () ;
V_97 -> V_208 = 0 ;
F_39 ( V_209 , V_2 ,
L_44 ,
V_97 ) ;
break;
case - V_210 :
F_39 ( V_185 , V_2 , L_1 ,
L_45 ) ;
break;
case - V_211 :
F_39 ( V_185 , V_2 , L_1 ,
L_46 ) ;
break;
case - V_171 :
V_97 -> V_205 = V_212 ;
V_97 -> V_149 = F_135 () ;
V_97 -> V_208 = 0 ;
V_97 -> V_202 = - 1 ;
F_39 ( V_185 , V_2 , L_1 ,
L_47 ) ;
V_41 = 0 ;
break;
case - V_213 :
F_39 ( V_185 , V_2 , L_1 ,
L_48 ) ;
break;
default:
snprintf ( V_203 , V_204 , L_49 , V_41 ) ;
F_136 ( & V_2 -> V_53 -> V_54 , L_50
L_51 , V_203 ) ;
F_137 () ;
break;
}
V_202 ++ ;
}
F_75 ( V_2 ) ;
return V_41 ;
}
int F_138 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_41 ;
char V_203 [ V_204 ] ;
V_41 = F_132 ( V_97 ) ;
if ( V_41 ) {
V_97 -> V_214 = V_41 ;
return V_41 ;
}
V_2 = (struct V_1 * ) V_97 -> V_107 ;
if ( ( ( V_97 -> V_36 &&
F_139 ( V_215 , & V_97 -> V_36 -> V_64 -> V_196 ) ) ||
F_139 ( V_215 , & V_2 -> V_196 ) ) &&
! F_139 ( V_216 , & V_97 -> V_196 ) ) {
F_39 ( V_209 , V_2 , L_52
L_53 , V_97 ) ;
V_97 -> V_205 = V_217 ;
V_97 -> V_214 = - V_87 ;
return - V_87 ;
}
if ( V_97 -> V_202 < 0 ) {
sprintf ( V_203 , L_54 , V_97 ) ;
F_136 ( & V_2 -> V_53 -> V_54 , L_55
L_56 , V_203 ) ;
V_97 -> V_205 = V_217 ;
return - V_211 ;
}
V_97 -> V_148 = F_135 () ;
V_97 -> V_208 = V_218 ;
V_97 -> V_202 -- ;
if ( ! F_139 ( V_219 , & V_97 -> V_196 ) ) {
V_97 -> V_220 &= F_140 ( V_2 ) ;
if ( ! V_97 -> V_220 )
V_97 -> V_220 = F_140 ( V_2 ) ;
}
if ( V_97 -> V_155 == 1 ) {
V_41 = F_141 ( V_2 -> V_53 , V_97 -> V_194 ,
( long ) V_97 , V_97 -> V_220 ) ;
} else {
V_41 = F_142 ( V_2 -> V_53 , V_97 -> V_194 ,
( long ) V_97 , V_97 -> V_220 , 0 ) ;
}
switch ( V_41 ) {
case 0 :
V_97 -> V_205 = V_206 ;
break;
case - V_213 :
F_39 ( V_57 , V_2 , L_1 ,
L_57 ) ;
break;
case - V_221 :
F_39 ( V_57 , V_2 , L_1 ,
L_58 ) ;
break;
case - V_222 :
if ( F_139 ( V_219 , & V_97 -> V_196 ) ) {
F_39 ( V_57 , V_2 ,
L_59 ,
V_97 -> V_220 ) ;
} else if ( V_97 -> V_220 != F_140 ( V_2 ) ) {
V_97 -> V_220 = F_140 ( V_2 ) ;
F_39 ( V_209 , V_2 , L_1 ,
L_60
L_61 ) ;
} else {
F_39 ( V_57 , V_2 , L_1 ,
L_62
L_63 ) ;
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ,
F_146 (
V_2 -> V_53 ) ) ;
}
break;
case - V_210 :
F_39 ( V_57 , V_2 , L_1 ,
L_64 ) ;
break;
case - V_211 :
F_39 ( V_57 , V_2 , L_1 ,
L_65 ) ;
break;
case - V_171 :
F_39 ( V_57 , V_2 , L_1 ,
L_66
L_67 ) ;
break;
default:
snprintf ( V_203 , V_204 , L_68 , V_41 ) ;
F_136 ( & V_2 -> V_53 -> V_54 ,
L_69
L_70 , V_203 ) ;
F_137 () ;
break;
}
V_97 -> V_214 = V_41 ;
return V_41 ;
}
static void V_18 ( unsigned long V_223 )
{
unsigned long V_196 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_223 ;
F_125 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
F_148 ( V_2 , V_224 ) ;
F_127 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
F_75 ( V_2 ) ;
}
void F_149 ( struct V_1 * V_2 , int V_225 )
{
if ( V_225 == 0 )
F_150 ( & V_2 -> V_16 ) ;
else
F_151 ( & V_2 -> V_16 , V_218 + V_225 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_150 ( & V_2 -> V_16 ) ;
}
static void F_152 ( struct V_226 * V_53 ,
unsigned long V_227 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 ;
if ( ! V_227 )
return;
V_97 = (struct V_96 * ) V_227 ;
if ( V_97 -> V_205 != V_206 ) {
F_153 ( V_209 , V_53 ,
L_71
L_72 , V_97 -> V_205 ) ;
return;
}
V_2 = F_154 ( V_53 ) ;
if ( F_29 ( V_2 ) ) {
F_153 ( V_209 , V_53 , L_1 ,
L_73 ) ;
return;
}
if ( ! V_97 -> V_107 ||
V_2 != V_97 -> V_107 ||
strncmp ( V_97 -> V_107 -> V_60 -> V_201 ,
( char * ) & V_97 -> V_190 , 4 ) ) {
F_153 ( V_209 , V_53 , L_1 ,
L_74 ) ;
F_23 ( V_2 ) ;
return;
}
V_97 -> V_205 = V_228 ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_155 ( struct V_1 * V_2 )
{
F_156 ( V_2 ) ;
F_148 ( V_2 , V_224 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_36 ) {
F_62 ( V_2 -> V_36 ) ;
if ( V_2 -> V_36 -> V_229 )
F_157 ( V_2 -> V_36 -> V_229 ,
true ) ;
}
}
static int F_158 ( struct V_230 * V_230 )
{
return ( F_159 ( & V_230 -> V_231 ) &&
( V_230 -> V_231 . V_232 . V_233 == V_234 ||
V_230 -> V_231 . V_232 . V_233 == V_235 ) ) ;
}
void F_160 ( struct V_226 * V_53 , unsigned long V_227 ,
struct V_230 * V_230 )
{
struct V_96 * V_97 , * V_236 ;
struct V_1 * V_2 ;
unsigned long V_237 ;
int V_238 = 0 ;
int V_239 = 0 ;
T_6 * V_240 = NULL ;
int V_225 ;
V_97 = (struct V_96 * ) V_227 ;
if ( F_29 ( V_230 ) ) {
switch ( F_103 ( V_230 ) ) {
case - V_211 :
if ( V_97 && V_97 -> V_205 == V_207 ) {
V_2 = V_97 -> V_107 ;
V_97 -> V_205 = V_212 ;
F_46 ( V_2 ) ;
F_71 ( & V_241 ) ;
F_75 ( V_2 ) ;
return;
}
break;
case - V_221 :
F_153 ( V_57 , V_53 , L_75
L_76 , V_242 ) ;
break;
default:
F_153 ( V_57 , V_53 , L_75
L_77 , V_242 ,
F_103 ( V_230 ) ) ;
}
F_152 ( V_53 , V_227 ) ;
return;
}
V_237 = F_135 () ;
if ( ! V_97 ||
! ( F_161 ( & V_230 -> V_231 ) == ( V_243 | V_244 ) &&
F_162 ( & V_230 -> V_231 ) == 0 ) ) {
if ( V_97 )
memcpy ( & V_97 -> V_230 , V_230 , sizeof( * V_230 ) ) ;
V_2 = F_154 ( V_53 ) ;
if ( F_29 ( V_2 ) )
return;
if ( V_2 -> V_60 == V_245 ) {
F_23 ( V_2 ) ;
return;
}
V_240 = F_163 ( V_230 ) ;
if ( V_240 ) {
V_239 = ( V_240 [ 1 ] & V_246 ) &&
F_139 ( V_247 , & V_97 -> V_196 ) ;
V_238 = ( V_240 [ 1 ] & V_248 ) &&
F_139 ( V_249 , & V_97 -> V_196 ) ;
}
if ( ! ( V_239 || V_238 ) )
V_2 -> V_60 -> V_250 ( V_2 , V_230 , L_78 ) ;
if ( V_2 -> V_81 & V_251 )
V_2 -> V_60 -> V_252 ( V_2 , V_97 , V_230 ) ;
V_2 -> V_60 -> V_253 ( V_2 , V_97 , V_230 ) ;
F_23 ( V_2 ) ;
}
if ( F_161 ( & V_230 -> V_231 ) & V_254 ) {
V_2 = F_154 ( V_53 ) ;
if ( ! F_29 ( V_2 ) ) {
V_2 -> V_60 -> V_255 ( V_2 ,
V_230 -> V_256 . V_257 . V_258 ) ;
F_23 ( V_2 ) ;
}
}
if ( ! V_97 )
return;
V_2 = (struct V_1 * ) V_97 -> V_107 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_60 -> V_201 , ( char * ) & V_97 -> V_190 , 4 ) ) {
F_153 ( V_209 , V_53 , L_1 ,
L_74 ) ;
return;
}
if ( V_97 -> V_205 == V_207 &&
F_164 ( & V_230 -> V_231 ) & V_259 ) {
V_97 -> V_205 = V_212 ;
F_46 ( V_2 ) ;
F_71 ( & V_241 ) ;
F_75 ( V_2 ) ;
return;
}
if ( V_97 -> V_205 != V_206 ) {
F_39 ( V_209 , V_2 , L_79
L_80 , F_34 ( & V_53 -> V_54 ) , V_97 -> V_205 ) ;
return;
}
V_236 = NULL ;
V_225 = 0 ;
if ( F_161 ( & V_230 -> V_231 ) == ( V_243 | V_244 ) &&
F_162 ( & V_230 -> V_231 ) == 0 ) {
V_97 -> V_205 = V_260 ;
V_97 -> V_149 = V_237 ;
if ( V_97 -> V_261 . V_236 != & V_2 -> V_15 ) {
V_236 = F_165 ( V_97 -> V_261 . V_236 ,
struct V_96 , V_261 ) ;
}
} else {
if ( V_97 -> V_155 && F_158 ( V_230 ) &&
V_2 -> V_60 -> V_262 )
V_2 -> V_60 -> V_262 ( V_2 , V_230 ) ;
if ( ! F_139 ( V_195 , & V_97 -> V_196 ) &&
V_97 -> V_202 > 0 ) {
if ( V_97 -> V_220 == F_140 ( V_2 ) )
F_39 ( V_209 , V_2 ,
L_81
L_82 ,
V_97 -> V_202 ) ;
if ( ! F_139 ( V_219 , & V_97 -> V_196 ) )
V_97 -> V_220 = F_140 ( V_2 ) ;
V_97 -> V_205 = V_228 ;
V_236 = V_97 ;
} else
V_97 -> V_205 = V_217 ;
}
if ( V_236 && ( V_236 -> V_205 == V_228 ) &&
( ! V_2 -> V_263 ) ) {
if ( V_2 -> V_60 -> V_264 ( V_236 ) == 0 )
V_225 = V_236 -> V_225 ;
}
if ( V_225 != 0 )
F_149 ( V_2 , V_225 ) ;
else
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
}
enum V_265 F_166 ( struct V_226 * V_53 , struct V_230 * V_230 )
{
struct V_1 * V_2 ;
V_2 = F_154 ( V_53 ) ;
if ( F_29 ( V_2 ) )
goto V_70;
if ( F_139 ( V_266 , & V_2 -> V_196 ) ||
V_2 -> V_28 != V_2 -> V_30 ||
! V_2 -> V_60 -> V_253 ) {
F_23 ( V_2 ) ;
goto V_70;
}
if ( V_2 -> V_60 -> V_250 )
V_2 -> V_60 -> V_250 ( V_2 , V_230 , L_83 ) ;
V_2 -> V_60 -> V_253 ( V_2 , NULL , V_230 ) ;
F_23 ( V_2 ) ;
V_70:
return V_267 ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_96 * V_268 )
{
struct V_100 * V_101 , * V_269 ;
struct V_96 * V_97 ;
if ( ! V_268 -> V_36 )
return;
F_168 (l, n, &device->ccw_queue) {
V_97 = F_165 ( V_101 , struct V_96 , V_261 ) ;
if ( V_97 -> V_205 == V_228 &&
V_268 -> V_36 == V_97 -> V_36 ) {
V_97 -> V_205 = V_212 ;
}
}
}
static void F_169 ( struct V_1 * V_2 ,
struct V_100 * V_270 )
{
struct V_100 * V_101 , * V_269 ;
struct V_96 * V_97 ;
F_168 (l, n, &device->ccw_queue) {
V_97 = F_165 ( V_101 , struct V_96 , V_261 ) ;
if ( V_97 -> V_205 == V_228 ||
V_97 -> V_205 == V_206 ||
V_97 -> V_205 == V_207 )
continue;
if ( V_97 -> V_205 == V_217 ) {
F_167 ( V_2 , V_97 ) ;
}
F_170 ( & V_97 -> V_261 , V_270 ) ;
}
}
static void F_171 ( struct V_1 * V_2 ,
struct V_100 * V_270 )
{
struct V_100 * V_101 , * V_269 ;
struct V_96 * V_97 ;
struct V_35 * V_36 ;
void (* F_172)( struct V_96 * , void * V_19 );
void * V_271 ;
char V_203 [ V_204 ] ;
F_168 (l, n, final_queue) {
V_97 = F_165 ( V_101 , struct V_96 , V_261 ) ;
F_173 ( & V_97 -> V_261 ) ;
V_36 = V_97 -> V_36 ;
F_172 = V_97 -> F_172 ;
V_271 = V_97 -> V_271 ;
if ( V_36 )
F_95 ( & V_36 -> V_39 ) ;
switch ( V_97 -> V_205 ) {
case V_260 :
V_97 -> V_205 = V_272 ;
break;
case V_217 :
V_97 -> V_205 = V_273 ;
break;
case V_212 :
V_97 -> V_205 = V_274 ;
break;
default:
snprintf ( V_203 , V_204 , L_84 , V_97 , V_97 -> V_205 ) ;
F_136 ( & V_2 -> V_53 -> V_54 ,
L_69
L_70 , V_203 ) ;
F_137 () ;
}
if ( V_97 -> F_172 != NULL )
( F_172 ) ( V_97 , V_271 ) ;
if ( V_36 )
F_96 ( & V_36 -> V_39 ) ;
}
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
if ( F_56 ( & V_2 -> V_15 ) )
return;
V_97 = F_165 ( V_2 -> V_15 . V_236 , struct V_96 , V_261 ) ;
if ( ( V_97 -> V_205 == V_206 && V_97 -> V_225 != 0 ) &&
( F_175 ( V_218 , V_97 -> V_225 + V_97 -> V_208 ) ) ) {
if ( F_139 ( V_275 , & V_2 -> V_196 ) ) {
V_97 -> V_202 ++ ;
}
if ( V_2 -> V_60 -> V_276 ( V_97 ) != 0 ) {
F_136 ( & V_2 -> V_53 -> V_54 ,
L_85
L_86 ,
V_97 , ( V_97 -> V_225 / V_277 ) ) ;
V_97 -> V_225 += 5 * V_277 ;
F_149 ( V_2 , 5 * V_277 ) ;
} else {
F_136 ( & V_2 -> V_53 -> V_54 ,
L_87
L_88 , V_97 , ( V_97 -> V_225 / V_277 ) ,
V_97 -> V_202 ) ;
}
}
}
static int F_176 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
int V_278 = ~ ( V_279 | V_280 ) ;
if ( F_139 ( V_266 , & V_2 -> V_196 ) &&
! F_139 ( V_275 , & V_2 -> V_196 ) ) {
return 1 ;
}
if ( V_2 -> V_263 ) {
if ( V_2 -> V_263 & V_278 ) {
return 1 ;
}
if ( ! F_139 ( V_219 , & V_97 -> V_196 ) ) {
return 1 ;
}
}
return 0 ;
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
int V_41 ;
if ( F_56 ( & V_2 -> V_15 ) )
return;
V_97 = F_165 ( V_2 -> V_15 . V_236 , struct V_96 , V_261 ) ;
if ( V_97 -> V_205 != V_228 )
return;
if ( F_176 ( V_2 , V_97 ) ) {
V_97 -> V_214 = - V_66 ;
V_97 -> V_205 = V_212 ;
F_75 ( V_2 ) ;
return;
}
V_41 = V_2 -> V_60 -> V_264 ( V_97 ) ;
if ( V_41 == 0 )
F_149 ( V_2 , V_97 -> V_225 ) ;
else if ( V_41 == - V_222 ) {
F_75 ( V_2 ) ;
} else
F_149 ( V_2 , 50 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
int V_41 ;
if ( ! F_179 ( V_2 ) )
return;
if ( V_2 -> V_263 &
~ ( V_279 | V_280 ) )
return;
V_41 = V_2 -> V_60 -> V_281 ( V_2 ,
F_179 ( V_2 ) ) ;
if ( V_41 )
F_149 ( V_2 , 50 ) ;
else
F_180 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_96 * V_97 , * V_269 ;
int V_41 ;
struct V_100 V_282 ;
F_12 ( & V_282 ) ;
F_181 ( F_147 ( V_2 -> V_53 ) ) ;
V_41 = 0 ;
F_182 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_97 -> V_205 ) {
case V_206 :
V_41 = V_2 -> V_60 -> V_276 ( V_97 ) ;
if ( V_41 ) {
F_136 ( & V_2 -> V_53 -> V_54 ,
L_89
L_90 , V_97 ) ;
goto V_283;
}
break;
case V_228 :
V_97 -> V_149 = F_135 () ;
V_97 -> V_205 = V_212 ;
break;
default:
break;
}
F_170 ( & V_97 -> V_261 , & V_282 ) ;
}
V_283:
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
F_182 (cqr, n, &flush_queue, devlist)
F_83 ( V_241 ,
( V_97 -> V_205 != V_207 ) ) ;
F_171 ( V_2 , & V_282 ) ;
return V_41 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_100 V_270 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_270 ) ;
F_181 ( F_147 ( V_2 -> V_53 ) ) ;
F_174 ( V_2 ) ;
F_169 ( V_2 , & V_270 ) ;
F_178 ( V_2 ) ;
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
F_171 ( V_2 , & V_270 ) ;
F_181 ( F_147 ( V_2 -> V_53 ) ) ;
F_177 ( V_2 ) ;
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
if ( F_184 ( & V_284 ) )
F_71 ( & V_284 ) ;
F_23 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( F_185 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_186 ( & V_2 -> V_13 ) ;
}
void F_187 ( struct V_1 * V_2 , int V_285 )
{
V_2 -> V_263 |= V_285 ;
}
void F_148 ( struct V_1 * V_2 , int V_285 )
{
V_2 -> V_263 &= ~ V_285 ;
if ( ! V_2 -> V_263 )
F_71 ( & V_286 ) ;
}
void F_188 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
unsigned long V_196 ;
V_2 = V_97 -> V_107 ;
F_125 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
V_97 -> V_205 = V_228 ;
F_189 ( & V_97 -> V_261 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_127 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
}
void F_190 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
unsigned long V_196 ;
V_2 = V_97 -> V_107 ;
F_125 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
V_97 -> V_205 = V_228 ;
F_191 ( & V_97 -> V_261 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_127 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
}
void F_192 ( struct V_96 * V_97 , void * V_19 )
{
F_181 ( F_147 ( V_97 -> V_107 -> V_53 ) ) ;
V_97 -> V_271 = V_287 ;
F_183 ( F_147 ( V_97 -> V_107 -> V_53 ) ) ;
F_71 ( & V_286 ) ;
}
static inline int F_193 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_41 ;
V_2 = V_97 -> V_107 ;
F_181 ( F_147 ( V_2 -> V_53 ) ) ;
V_41 = ( V_97 -> V_271 == V_287 ) ;
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
return V_41 ;
}
static int F_194 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
T_7 V_288 ;
if ( V_97 -> V_205 == V_289 )
return 0 ;
V_2 = V_97 -> V_107 ;
if ( F_139 ( V_195 , & V_97 -> V_196 ) ) {
if ( V_97 -> V_205 == V_274 ) {
V_2 -> V_60 -> V_290 ( V_97 ) ;
return 1 ;
}
if ( V_97 -> V_205 == V_273 ) {
V_288 = V_2 -> V_60 -> V_291 ( V_97 ) ;
V_288 ( V_97 ) ;
return 1 ;
}
if ( V_97 -> V_205 == V_292 )
F_195 ( V_97 , & V_97 -> V_230 ) ;
if ( V_97 -> V_293 ) {
F_196 ( V_2 , V_97 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_197 ( struct V_96 * V_97 )
{
if ( F_139 ( V_195 , & V_97 -> V_196 ) ) {
if ( V_97 -> V_293 )
return 1 ;
return ( ( V_97 -> V_205 != V_272 ) &&
( V_97 -> V_205 != V_292 ) ) ;
} else
return ( V_97 -> V_205 == V_289 ) ;
}
static int F_198 ( struct V_96 * V_294 , int V_295 )
{
struct V_1 * V_2 ;
int V_41 ;
struct V_100 V_15 ;
struct V_96 * V_97 ;
F_12 ( & V_15 ) ;
V_294 -> V_205 = V_289 ;
V_2 = V_294 -> V_107 ;
F_189 ( & V_294 -> V_296 , & V_15 ) ;
for ( V_97 = V_294 ; F_197 ( V_97 ) ;
V_97 = F_199 ( & V_15 ,
struct V_96 , V_296 ) ) {
if ( F_194 ( V_97 ) )
continue;
if ( V_97 -> V_205 != V_289 )
continue;
if ( F_139 ( V_215 , & V_2 -> V_196 ) &&
! F_139 ( V_216 , & V_97 -> V_196 ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_87 ;
continue;
}
if ( V_2 -> V_263 & ~ V_224 &&
F_139 ( V_297 , & V_97 -> V_196 ) &&
( ! F_200 ( V_2 ) ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_298 ;
continue;
}
if ( F_139 ( V_266 , & V_2 -> V_196 ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_210 ;
continue;
}
if ( ! F_139 ( V_219 , & V_97 -> V_196 ) ) {
if ( V_295 ) {
V_41 = F_201 (
V_286 , ! ( V_2 -> V_263 ) ) ;
if ( V_41 == - V_299 ) {
V_97 -> V_205 = V_292 ;
V_294 -> V_214 = V_41 ;
continue;
}
} else
F_83 ( V_286 , ! ( V_2 -> V_263 ) ) ;
}
if ( ! V_97 -> F_172 )
V_97 -> F_172 = F_192 ;
V_97 -> V_271 = V_300 ;
F_190 ( V_97 ) ;
if ( V_295 ) {
V_41 = F_201 (
V_286 , F_193 ( V_97 ) ) ;
if ( V_41 == - V_299 ) {
F_202 ( V_97 ) ;
F_83 ( V_286 ,
F_193 ( V_97 ) ) ;
V_97 -> V_205 = V_292 ;
V_294 -> V_214 = V_41 ;
continue;
}
} else
F_83 ( V_286 , F_193 ( V_97 ) ) ;
}
V_294 -> V_150 = F_135 () ;
if ( ( V_294 -> V_205 != V_272 ) &&
( V_294 -> V_214 != - V_299 ) )
F_195 ( V_294 , & V_294 -> V_230 ) ;
if ( V_294 -> V_205 == V_272 )
V_41 = 0 ;
else if ( V_294 -> V_214 )
V_41 = V_294 -> V_214 ;
else
V_41 = - V_211 ;
return V_41 ;
}
static inline int F_203 ( struct V_100 * V_15 )
{
struct V_96 * V_97 ;
F_204 (cqr, ccw_queue, blocklist) {
if ( V_97 -> V_271 != V_287 )
return 0 ;
}
return 1 ;
}
static int F_205 ( struct V_100 * V_15 , int V_295 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 , * V_269 ;
T_6 * V_240 = NULL ;
int V_41 ;
V_301:
F_182 (cqr, n, ccw_queue, blocklist) {
V_2 = V_97 -> V_107 ;
if ( V_97 -> V_205 != V_289 )
continue;
if ( F_139 ( V_215 , & V_2 -> V_196 ) &&
! F_139 ( V_216 , & V_97 -> V_196 ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_87 ;
continue;
}
if ( V_2 -> V_263 & ~ V_224 &&
F_139 ( V_297 , & V_97 -> V_196 ) &&
! F_200 ( V_2 ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_66 ;
continue;
}
if ( V_295 ) {
V_41 = F_201 (
V_286 , ! V_2 -> V_263 ) ;
if ( V_41 == - V_299 ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = V_41 ;
continue;
}
} else
F_83 ( V_286 , ! ( V_2 -> V_263 ) ) ;
if ( ! V_97 -> F_172 )
V_97 -> F_172 = F_192 ;
V_97 -> V_271 = V_300 ;
F_190 ( V_97 ) ;
}
F_83 ( V_286 , F_203 ( V_15 ) ) ;
V_41 = 0 ;
F_182 (cqr, n, ccw_queue, blocklist) {
V_240 = F_163 ( & V_97 -> V_230 ) ;
if ( V_240 && V_240 [ 1 ] & V_246 &&
F_139 ( V_247 , & V_97 -> V_196 ) )
continue;
if ( F_162 ( & V_97 -> V_230 . V_231 ) == 0x40 &&
F_139 ( V_302 , & V_97 -> V_196 ) )
continue;
if ( V_97 -> V_107 != V_97 -> V_303 && ! V_97 -> V_293 &&
( V_97 -> V_205 == V_274 ||
V_97 -> V_205 == V_273 ) )
return - V_66 ;
if ( F_194 ( V_97 ) )
goto V_301;
}
return 0 ;
}
int F_206 ( struct V_96 * V_97 )
{
return F_198 ( V_97 , 0 ) ;
}
int F_207 ( struct V_100 * V_15 )
{
return F_205 ( V_15 , 0 ) ;
}
int F_208 ( struct V_96 * V_97 )
{
return F_198 ( V_97 , 1 ) ;
}
static inline int F_209 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
int V_41 ;
if ( F_56 ( & V_2 -> V_15 ) )
return 0 ;
V_97 = F_165 ( V_2 -> V_15 . V_236 , struct V_96 , V_261 ) ;
V_41 = V_2 -> V_60 -> V_276 ( V_97 ) ;
if ( ! V_41 )
V_97 -> V_202 ++ ;
return V_41 ;
}
int F_210 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
int V_41 ;
V_2 = V_97 -> V_107 ;
if ( F_139 ( V_215 , & V_2 -> V_196 ) &&
! F_139 ( V_216 , & V_97 -> V_196 ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_87 ;
return - V_211 ;
}
F_181 ( F_147 ( V_2 -> V_53 ) ) ;
V_41 = F_209 ( V_2 ) ;
if ( V_41 ) {
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
return V_41 ;
}
V_97 -> F_172 = F_192 ;
V_97 -> V_271 = V_300 ;
V_97 -> V_205 = V_228 ;
F_189 ( & V_97 -> V_261 , V_2 -> V_15 . V_236 ) ;
F_75 ( V_2 ) ;
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
F_83 ( V_286 , F_193 ( V_97 ) ) ;
if ( V_97 -> V_205 == V_272 )
V_41 = 0 ;
else if ( V_97 -> V_214 )
V_41 = V_97 -> V_214 ;
else
V_41 = - V_211 ;
F_75 ( V_2 ) ;
if ( V_2 -> V_36 )
F_62 ( V_2 -> V_36 ) ;
return V_41 ;
}
int F_202 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_107 ;
unsigned long V_196 ;
int V_41 ;
V_41 = 0 ;
F_125 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
switch ( V_97 -> V_205 ) {
case V_228 :
V_97 -> V_205 = V_212 ;
if ( V_97 -> V_271 == V_300 )
V_97 -> V_271 = V_287 ;
break;
case V_206 :
V_41 = V_2 -> V_60 -> V_276 ( V_97 ) ;
if ( V_41 ) {
F_136 ( & V_2 -> V_53 -> V_54 ,
L_91 ,
V_97 , V_41 ) ;
} else {
V_97 -> V_149 = F_135 () ;
}
break;
default:
break;
}
F_127 ( F_147 ( V_2 -> V_53 ) , V_196 ) ;
F_75 ( V_2 ) ;
return V_41 ;
}
static void V_40 ( unsigned long V_223 )
{
unsigned long V_196 ;
struct V_35 * V_36 ;
V_36 = (struct V_35 * ) V_223 ;
F_125 ( F_147 ( V_36 -> V_64 -> V_53 ) , V_196 ) ;
F_148 ( V_36 -> V_64 , V_224 ) ;
F_127 ( F_147 ( V_36 -> V_64 -> V_53 ) , V_196 ) ;
F_62 ( V_36 ) ;
F_157 ( V_36 -> V_229 , true ) ;
}
void F_211 ( struct V_35 * V_36 , int V_225 )
{
if ( V_225 == 0 )
F_150 ( & V_36 -> V_16 ) ;
else
F_151 ( & V_36 -> V_16 , V_218 + V_225 ) ;
}
void F_44 ( struct V_35 * V_36 )
{
F_150 ( & V_36 -> V_16 ) ;
}
static void F_196 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
T_7 V_288 ;
if ( V_97 -> V_205 == V_272 )
F_39 ( V_304 , V_2 , L_1 , L_92 ) ;
else
F_136 ( & V_2 -> V_53 -> V_54 , L_93 ) ;
V_288 = V_2 -> V_60 -> V_305 ( V_97 ) ;
V_288 ( V_97 ) ;
}
static void F_212 ( struct V_96 * V_97 )
{
struct V_98 * V_99 ;
T_8 error = V_306 ;
int V_205 ;
V_99 = (struct V_98 * ) V_97 -> V_271 ;
F_91 ( V_97 -> V_36 , V_97 , V_99 ) ;
V_205 = V_97 -> V_36 -> V_64 -> V_60 -> V_307 ( V_97 , V_99 ) ;
if ( V_205 < 0 )
error = F_213 ( V_205 ) ;
else if ( V_205 == 0 ) {
switch ( V_97 -> V_214 ) {
case - V_87 :
error = V_308 ;
break;
case - V_298 :
error = V_309 ;
break;
case - V_221 :
error = V_310 ;
break;
default:
error = V_311 ;
break;
}
}
if ( error ) {
F_214 ( V_99 , error ) ;
F_157 ( V_99 -> V_312 , true ) ;
} else {
F_215 ( V_99 ) ;
}
}
static void F_216 ( struct V_35 * V_36 ,
struct V_100 * V_270 )
{
struct V_100 * V_101 , * V_269 ;
struct V_96 * V_97 ;
T_7 V_288 ;
unsigned long V_196 ;
struct V_1 * V_64 = V_36 -> V_64 ;
V_313:
F_168 (l, n, &block->ccw_queue) {
V_97 = F_165 ( V_101 , struct V_96 , V_296 ) ;
if ( V_97 -> V_205 != V_272 &&
V_97 -> V_205 != V_292 &&
V_97 -> V_205 != V_273 &&
V_97 -> V_205 != V_274 )
continue;
if ( V_97 -> V_205 == V_274 ) {
V_64 -> V_60 -> V_290 ( V_97 ) ;
goto V_313;
}
if ( V_97 -> V_205 == V_273 ) {
V_288 = V_64 -> V_60 -> V_291 ( V_97 ) ;
if ( F_29 ( V_288 ( V_97 ) ) )
continue;
goto V_313;
}
if ( V_97 -> V_205 == V_292 ) {
F_195 ( V_97 , & V_97 -> V_230 ) ;
}
if ( F_200 ( V_64 ) &&
V_97 -> V_205 == V_292 ) {
F_217 ( V_64 , V_97 , V_314 ) ;
V_97 -> V_205 = V_289 ;
V_97 -> V_202 = 255 ;
F_125 ( F_147 ( V_64 -> V_53 ) , V_196 ) ;
F_187 ( V_64 , V_315 ) ;
F_127 ( F_147 ( V_64 -> V_53 ) ,
V_196 ) ;
goto V_313;
}
if ( V_97 -> V_293 ) {
F_196 ( V_64 , V_97 ) ;
goto V_313;
}
V_97 -> V_150 = F_135 () ;
F_170 ( & V_97 -> V_296 , V_270 ) ;
}
}
static void F_218 ( struct V_96 * V_97 , void * V_19 )
{
F_62 ( V_97 -> V_36 ) ;
}
static void F_219 ( struct V_35 * V_36 )
{
struct V_96 * V_97 ;
if ( F_56 ( & V_36 -> V_15 ) )
return;
F_204 (cqr, &block->ccw_queue, blocklist) {
if ( V_97 -> V_205 != V_289 )
continue;
if ( F_139 ( V_215 , & V_36 -> V_64 -> V_196 ) &&
! F_139 ( V_216 , & V_97 -> V_196 ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_87 ;
F_62 ( V_36 ) ;
continue;
}
if ( V_36 -> V_64 -> V_263 & ~ V_224 &&
F_139 ( V_297 , & V_97 -> V_196 ) &&
( ! F_200 ( V_36 -> V_64 ) ) ) {
V_97 -> V_205 = V_292 ;
V_97 -> V_214 = - V_298 ;
F_62 ( V_36 ) ;
continue;
}
if ( V_36 -> V_64 -> V_263 )
return;
if ( ! V_97 -> V_107 )
V_97 -> V_107 = V_36 -> V_64 ;
V_97 -> F_172 = F_218 ;
F_190 ( V_97 ) ;
}
}
static void V_38 ( struct V_35 * V_36 )
{
struct V_100 V_270 ;
struct V_100 * V_101 , * V_269 ;
struct V_96 * V_97 ;
struct V_316 * V_317 ;
F_10 ( & V_36 -> V_12 , 0 ) ;
F_12 ( & V_270 ) ;
F_181 ( & V_36 -> V_39 ) ;
F_216 ( V_36 , & V_270 ) ;
F_183 ( & V_36 -> V_39 ) ;
F_168 (l, n, &final_queue) {
V_97 = F_165 ( V_101 , struct V_96 , V_296 ) ;
V_317 = V_97 -> V_317 ;
F_181 ( & V_317 -> V_33 ) ;
F_173 ( & V_97 -> V_296 ) ;
F_212 ( V_97 ) ;
F_183 ( & V_317 -> V_33 ) ;
}
F_181 ( & V_36 -> V_39 ) ;
F_219 ( V_36 ) ;
F_183 ( & V_36 -> V_39 ) ;
if ( F_184 ( & V_284 ) )
F_71 ( & V_284 ) ;
F_23 ( V_36 -> V_64 ) ;
}
static void F_220 ( struct V_96 * V_97 , void * V_19 )
{
F_71 ( & V_241 ) ;
}
static int F_221 ( struct V_96 * V_97 )
{
struct V_35 * V_36 = V_97 -> V_36 ;
struct V_98 * V_99 ;
if ( ! V_36 )
return - V_171 ;
F_181 ( & V_97 -> V_317 -> V_33 ) ;
V_99 = (struct V_98 * ) V_97 -> V_271 ;
F_222 ( V_99 , false ) ;
F_183 ( & V_97 -> V_317 -> V_33 ) ;
return 0 ;
}
static int F_58 ( struct V_35 * V_36 )
{
struct V_96 * V_97 , * V_269 ;
int V_41 , V_173 ;
struct V_100 V_282 ;
unsigned long V_196 ;
F_12 ( & V_282 ) ;
F_95 ( & V_36 -> V_39 ) ;
V_41 = 0 ;
V_313:
F_182 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_97 -> V_205 >= V_228 )
V_41 = F_202 ( V_97 ) ;
if ( V_41 < 0 )
break;
V_97 -> F_172 = F_220 ;
for ( V_173 = 0 ; V_97 != NULL ; V_97 = V_97 -> V_293 , V_173 ++ )
F_170 ( & V_97 -> V_296 , & V_282 ) ;
if ( V_173 > 1 )
goto V_313;
}
F_96 ( & V_36 -> V_39 ) ;
V_318:
F_182 (cqr, n, &flush_queue, blocklist) {
F_83 ( V_241 , ( V_97 -> V_205 < V_228 ) ) ;
if ( V_97 -> V_293 ) {
F_95 ( & V_36 -> V_39 ) ;
F_196 ( V_36 -> V_64 , V_97 ) ;
F_96 ( & V_36 -> V_39 ) ;
goto V_318;
}
F_125 ( & V_97 -> V_317 -> V_33 , V_196 ) ;
V_97 -> V_150 = F_135 () ;
F_173 ( & V_97 -> V_296 ) ;
F_212 ( V_97 ) ;
F_127 ( & V_97 -> V_317 -> V_33 , V_196 ) ;
}
return V_41 ;
}
void F_62 ( struct V_35 * V_36 )
{
if ( F_185 ( & V_36 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_36 -> V_64 ) ;
F_186 ( & V_36 -> V_13 ) ;
}
static T_8 F_223 ( struct V_319 * V_320 ,
const struct V_321 * V_322 )
{
struct V_35 * V_36 = V_320 -> V_323 -> V_324 ;
struct V_316 * V_317 = V_320 -> V_325 ;
struct V_98 * V_99 = V_322 -> V_326 ;
struct V_1 * V_303 ;
struct V_96 * V_97 ;
T_8 V_41 = V_306 ;
V_303 = V_36 -> V_64 ;
F_181 ( & V_317 -> V_33 ) ;
if ( V_303 -> V_28 < V_73 ) {
F_39 ( V_185 , V_303 ,
L_94 , V_99 ) ;
V_41 = V_311 ;
goto V_70;
}
if ( V_303 -> V_263 && ! ( V_303 -> V_81 & V_327 ) ) {
F_39 ( V_185 , V_303 ,
L_95 , V_99 ) ;
V_41 = V_328 ;
goto V_70;
}
if ( V_303 -> V_81 & V_329 &&
F_87 ( V_99 ) == V_330 ) {
F_39 ( V_185 , V_303 ,
L_96 , V_99 ) ;
V_41 = V_311 ;
goto V_70;
}
if ( F_139 ( V_331 , & V_303 -> V_196 ) &&
( V_303 -> V_81 & V_327 ||
F_224 ( V_99 ) ) ) {
F_39 ( V_185 , V_303 ,
L_97 , V_99 ) ;
V_41 = V_311 ;
goto V_70;
}
V_97 = V_303 -> V_60 -> V_332 ( V_303 , V_36 , V_99 ) ;
if ( F_29 ( V_97 ) ) {
if ( F_103 ( V_97 ) == - V_213 ||
F_103 ( V_97 ) == - V_4 ||
F_103 ( V_97 ) == - V_66 ) {
V_41 = V_328 ;
goto V_70;
}
F_39 ( V_185 , V_303 ,
L_98 ,
F_103 ( V_97 ) , V_99 ) ;
V_41 = V_311 ;
goto V_70;
}
V_97 -> V_271 = V_99 ;
V_97 -> V_205 = V_289 ;
V_97 -> V_317 = V_317 ;
V_99 -> V_333 = V_97 ;
F_225 ( V_99 ) ;
F_86 ( & V_36 -> V_39 ) ;
F_191 ( & V_97 -> V_296 , & V_36 -> V_15 ) ;
F_12 ( & V_97 -> V_261 ) ;
F_84 ( V_36 , V_97 , V_99 ) ;
F_62 ( V_36 ) ;
F_88 ( & V_36 -> V_39 ) ;
V_70:
F_183 ( & V_317 -> V_33 ) ;
return V_41 ;
}
enum V_334 F_226 ( struct V_98 * V_99 , bool V_335 )
{
struct V_96 * V_97 = V_99 -> V_333 ;
struct V_35 * V_36 = V_99 -> V_312 -> V_324 ;
struct V_1 * V_2 ;
unsigned long V_196 ;
int V_41 = 0 ;
if ( ! V_97 )
return V_336 ;
F_125 ( & V_97 -> V_317 -> V_33 , V_196 ) ;
V_2 = V_97 -> V_107 ? V_97 -> V_107 : V_36 -> V_64 ;
if ( ! V_2 -> V_337 ) {
F_127 ( & V_97 -> V_317 -> V_33 , V_196 ) ;
return V_338 ;
}
F_39 ( V_57 , V_2 ,
L_99 ,
V_97 , V_97 -> V_205 ) ;
F_86 ( & V_36 -> V_39 ) ;
F_86 ( F_147 ( V_2 -> V_53 ) ) ;
V_97 -> V_202 = - 1 ;
V_97 -> V_214 = - V_221 ;
if ( V_97 -> V_205 >= V_228 ) {
F_88 ( F_147 ( V_2 -> V_53 ) ) ;
V_41 = F_202 ( V_97 ) ;
} else if ( V_97 -> V_205 == V_289 ||
V_97 -> V_205 == V_273 ) {
V_97 -> V_205 = V_274 ;
F_88 ( F_147 ( V_2 -> V_53 ) ) ;
} else if ( V_97 -> V_205 == V_339 ) {
struct V_96 * V_340 , * V_341 , * V_342 ;
F_182 (searchcqr, nextcqr,
&block->ccw_queue, blocklist) {
V_342 = V_340 ;
while ( V_342 -> V_293 )
V_342 = V_342 -> V_293 ;
if ( V_342 != V_97 )
continue;
V_340 -> V_202 = - 1 ;
V_340 -> V_214 = - V_221 ;
if ( V_340 -> V_205 >= V_228 ) {
F_88 ( F_147 ( V_2 -> V_53 ) ) ;
V_41 = F_202 ( V_340 ) ;
F_86 ( F_147 ( V_2 -> V_53 ) ) ;
} else if ( ( V_340 -> V_205 == V_289 ) ||
( V_340 -> V_205 == V_273 ) ) {
V_340 -> V_205 = V_274 ;
V_41 = 0 ;
} else if ( V_340 -> V_205 == V_339 ) {
continue;
}
break;
}
F_88 ( F_147 ( V_2 -> V_53 ) ) ;
}
F_62 ( V_36 ) ;
F_88 ( & V_36 -> V_39 ) ;
F_127 ( & V_97 -> V_317 -> V_33 , V_196 ) ;
return V_41 ? V_338 : V_336 ;
}
static int F_227 ( struct V_319 * V_320 , void * V_19 ,
unsigned int V_343 )
{
struct V_316 * V_317 = F_2 ( sizeof( * V_317 ) , V_157 ) ;
if ( ! V_317 )
return - V_4 ;
F_9 ( & V_317 -> V_33 ) ;
V_320 -> V_325 = V_317 ;
return 0 ;
}
static void F_228 ( struct V_319 * V_320 , unsigned int V_343 )
{
F_5 ( V_320 -> V_325 ) ;
V_320 -> V_325 = NULL ;
}
static void F_229 ( struct V_98 * V_99 )
{
F_214 ( V_99 , 0 ) ;
F_157 ( V_99 -> V_312 , true ) ;
}
static int F_22 ( struct V_35 * V_36 )
{
int V_41 ;
V_36 -> V_344 . V_345 = & V_346 ;
V_36 -> V_344 . V_347 = V_348 ;
V_36 -> V_344 . V_349 = V_350 * V_351 ;
V_36 -> V_344 . V_196 = V_352 ;
V_41 = F_230 ( & V_36 -> V_344 ) ;
if ( V_41 )
return V_41 ;
V_36 -> V_229 = F_231 ( & V_36 -> V_344 ) ;
if ( F_29 ( V_36 -> V_229 ) )
return F_103 ( V_36 -> V_229 ) ;
V_36 -> V_229 -> V_324 = V_36 ;
return 0 ;
}
static void F_52 ( struct V_35 * V_36 )
{
unsigned int V_353 = V_36 -> V_75 ;
struct V_229 * V_312 = V_36 -> V_229 ;
unsigned int V_354 , V_355 ;
int V_356 ;
if ( V_36 -> V_64 -> V_81 & V_82 ) {
V_356 = 2048 ;
} else {
V_356 = V_36 -> V_64 -> V_60 -> V_357 << V_36 -> V_72 ;
}
F_232 ( V_358 , V_312 ) ;
V_312 -> V_359 . V_360 = V_356 ;
F_233 ( V_312 , V_353 ) ;
F_234 ( V_312 , V_356 ) ;
F_235 ( V_312 , V_361 ) ;
F_236 ( V_312 , V_9 ) ;
F_237 ( V_312 , V_9 - 1 ) ;
if ( V_36 -> V_64 -> V_81 & V_362 ) {
V_312 -> V_359 . V_363 = V_353 ;
V_312 -> V_359 . V_364 = V_9 ;
V_354 = V_361 * V_353 ;
V_354 = F_238 ( V_354 , V_9 ) - V_9 ;
V_355 = V_354 / V_353 ;
F_239 ( V_312 , V_355 ) ;
F_240 ( V_312 , V_355 ) ;
F_232 ( V_365 , V_312 ) ;
}
}
static void F_26 ( struct V_35 * V_36 )
{
if ( V_36 -> V_229 ) {
F_241 ( V_36 -> V_229 ) ;
F_242 ( & V_36 -> V_344 ) ;
V_36 -> V_229 = NULL ;
}
}
static int F_243 ( struct V_366 * V_83 , T_9 V_179 )
{
struct V_1 * V_64 ;
int V_41 ;
V_64 = F_244 ( V_83 -> V_84 ) ;
if ( ! V_64 )
return - V_210 ;
F_245 ( & V_64 -> V_36 -> V_37 ) ;
if ( F_139 ( V_266 , & V_64 -> V_196 ) ) {
V_41 = - V_210 ;
goto V_367;
}
if ( ! F_246 ( V_64 -> V_60 -> V_368 ) ) {
V_41 = - V_171 ;
goto V_367;
}
if ( V_94 ) {
F_247 ( & V_64 -> V_53 -> V_54 ,
L_100
L_101 ) ;
V_41 = - V_87 ;
goto V_70;
}
if ( V_64 -> V_28 <= V_59 ) {
F_39 ( V_185 , V_64 , L_102 ,
L_103 ) ;
V_41 = - V_210 ;
goto V_70;
}
if ( ( V_179 & V_369 ) &&
( F_139 ( V_370 , & V_64 -> V_196 ) ||
( V_64 -> V_81 & V_329 ) ) ) {
V_41 = - V_371 ;
goto V_70;
}
F_23 ( V_64 ) ;
return 0 ;
V_70:
F_248 ( V_64 -> V_60 -> V_368 ) ;
V_367:
F_249 ( & V_64 -> V_36 -> V_37 ) ;
F_23 ( V_64 ) ;
return V_41 ;
}
static void F_250 ( struct V_62 * V_63 , T_9 V_179 )
{
struct V_1 * V_64 = F_244 ( V_63 ) ;
if ( V_64 ) {
F_249 ( & V_64 -> V_36 -> V_37 ) ;
F_248 ( V_64 -> V_60 -> V_368 ) ;
F_23 ( V_64 ) ;
}
}
static int F_251 ( struct V_366 * V_83 , struct V_372 * V_373 )
{
struct V_1 * V_64 ;
V_64 = F_244 ( V_83 -> V_84 ) ;
if ( ! V_64 )
return - V_210 ;
if ( ! V_64 -> V_60 ||
! V_64 -> V_60 -> V_374 ) {
F_23 ( V_64 ) ;
return - V_171 ;
}
V_64 -> V_60 -> V_374 ( V_64 -> V_36 , V_373 ) ;
V_373 -> V_375 = F_252 ( V_83 ) >> V_64 -> V_36 -> V_72 ;
F_23 ( V_64 ) ;
return 0 ;
}
static void
F_253 ( void )
{
#ifdef F_254
F_255 () ;
#endif
F_256 () ;
if ( V_376 != NULL ) {
F_257 ( V_376 ) ;
V_376 = NULL ;
}
F_258 () ;
F_259 () ;
if ( V_377 != NULL ) {
F_48 ( V_377 ) ;
V_377 = NULL ;
}
F_114 () ;
}
int F_260 ( struct V_1 * V_2 )
{
struct V_378 V_379 ;
struct V_380 V_381 ;
int V_41 ;
if ( ! V_382 )
return 0 ;
F_261 ( V_2 -> V_53 , & V_379 ) ;
memset ( & V_381 , 0 , sizeof( V_381 ) ) ;
V_381 . V_383 = V_379 . V_384 ;
V_381 . V_385 = sizeof( V_381 ) ;
V_41 = V_380 ( & V_381 ) ;
if ( V_41 == 0 || V_41 == 2 ) {
return V_381 . V_386 & 0x80 ;
} else {
F_116 ( V_57 , L_104 ,
V_379 . V_384 , V_41 ) ;
return 0 ;
}
}
static void F_262 ( void * V_19 , T_10 V_387 )
{
struct V_226 * V_53 = V_19 ;
int V_388 ;
V_388 = F_263 ( V_53 ) ;
if ( V_388 )
F_264 ( L_105 ,
F_34 ( & V_53 -> V_54 ) , V_388 ) ;
}
int F_265 ( struct V_226 * V_53 ,
struct V_389 * V_60 )
{
int V_388 ;
V_388 = F_266 ( V_53 ) ;
if ( V_388 ) {
F_153 ( V_57 , V_53 , L_1 ,
L_106
L_107 ) ;
return V_388 ;
}
V_53 -> V_390 = & F_160 ;
if ( ( F_267 ( V_53 , V_391 ) > 0 ) ||
( V_392 && F_268 ( F_34 ( & V_53 -> V_54 ) ) != 0 ) )
F_269 ( F_262 , V_53 ) ;
return 0 ;
}
void F_270 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 ) {
if ( V_2 -> V_60 -> V_393 )
V_2 -> V_60 -> V_393 ( V_2 ) ;
F_248 ( V_2 -> V_60 -> V_368 ) ;
V_2 -> V_60 = NULL ;
}
if ( V_2 -> V_394 ) {
F_248 ( V_2 -> V_394 -> V_368 ) ;
V_2 -> V_394 = NULL ;
}
}
void F_271 ( struct V_226 * V_53 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
V_53 -> V_390 = NULL ;
V_2 = F_272 ( V_53 ) ;
if ( F_29 ( V_2 ) ) {
F_273 ( V_53 ) ;
return;
}
if ( F_274 ( V_266 , & V_2 -> V_196 ) &&
! F_139 ( V_275 , & V_2 -> V_196 ) ) {
F_23 ( V_2 ) ;
F_273 ( V_53 ) ;
return;
}
F_80 ( V_2 , V_29 ) ;
V_36 = V_2 -> V_36 ;
F_275 ( V_2 ) ;
if ( V_36 )
F_19 ( V_36 ) ;
F_273 ( V_53 ) ;
}
int F_276 ( struct V_226 * V_53 ,
struct V_389 * V_394 )
{
struct V_389 * V_60 ;
struct V_1 * V_2 ;
int V_41 ;
F_277 ( V_53 , V_391 , 0 ) ;
V_2 = F_278 ( V_53 ) ;
if ( F_29 ( V_2 ) )
return F_103 ( V_2 ) ;
V_60 = V_394 ;
if ( V_2 -> V_81 & V_395 ) {
if ( ! V_245 ) {
V_41 = F_279 ( V_396 ) ;
if ( V_41 ) {
F_264 ( L_108
L_109
L_110 ,
F_34 ( & V_53 -> V_54 ) , V_396 ,
V_41 ) ;
F_275 ( V_2 ) ;
return - V_210 ;
}
}
if ( ! V_245 ) {
F_264 ( L_111 ,
F_34 ( & V_53 -> V_54 ) ) ;
F_275 ( V_2 ) ;
return - V_210 ;
}
V_60 = V_245 ;
}
if ( ! F_246 ( V_394 -> V_368 ) ) {
F_275 ( V_2 ) ;
return - V_171 ;
}
if ( ! F_246 ( V_60 -> V_368 ) ) {
F_248 ( V_394 -> V_368 ) ;
F_275 ( V_2 ) ;
return - V_171 ;
}
V_2 -> V_394 = V_394 ;
V_2 -> V_60 = V_60 ;
V_41 = V_60 -> V_397 ( V_2 ) ;
if ( V_41 ) {
F_264 ( L_112 ,
F_34 ( & V_53 -> V_54 ) , V_60 -> V_44 , V_41 ) ;
F_248 ( V_60 -> V_368 ) ;
F_248 ( V_394 -> V_368 ) ;
F_275 ( V_2 ) ;
return V_41 ;
}
F_80 ( V_2 , V_80 ) ;
if ( V_2 -> V_28 <= V_42 ) {
F_264 ( L_113 ,
F_34 ( & V_53 -> V_54 ) ) ;
V_41 = - V_210 ;
F_80 ( V_2 , V_29 ) ;
if ( V_2 -> V_36 )
F_19 ( V_2 -> V_36 ) ;
F_275 ( V_2 ) ;
} else
F_280 ( L_114 ,
F_34 ( & V_53 -> V_54 ) ) ;
F_83 ( V_88 , F_81 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_41 ;
}
int F_281 ( struct V_226 * V_53 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_398 , V_37 , V_41 ;
unsigned long V_196 ;
V_41 = 0 ;
F_125 ( F_147 ( V_53 ) , V_196 ) ;
V_2 = F_154 ( V_53 ) ;
if ( F_29 ( V_2 ) ) {
F_127 ( F_147 ( V_53 ) , V_196 ) ;
return F_103 ( V_2 ) ;
}
if ( V_2 -> V_36 ) {
V_398 = V_2 -> V_36 -> V_83 ? 0 : - 1 ;
V_37 = F_282 ( & V_2 -> V_36 -> V_37 ) ;
if ( V_37 > V_398 ) {
if ( V_37 > 0 )
F_264 ( L_115 ,
F_34 ( & V_53 -> V_54 ) , V_37 ) ;
else
F_264 ( L_116 ,
F_34 ( & V_53 -> V_54 ) ) ;
V_41 = - V_213 ;
goto V_399;
}
}
if ( F_139 ( V_266 , & V_2 -> V_196 ) ) {
if ( F_139 ( V_275 , & V_2 -> V_196 ) ) {
F_283 ( V_275 ,
& V_2 -> V_196 ) ;
} else {
V_41 = - V_213 ;
goto V_399;
}
}
F_123 ( V_266 , & V_2 -> V_196 ) ;
if ( F_284 ( V_400 , & V_2 -> V_196 ) &&
! F_274 ( V_275 , & V_2 -> V_196 ) ) {
F_127 ( F_147 ( V_53 ) , V_196 ) ;
if ( V_2 -> V_36 ) {
V_41 = F_285 ( V_2 -> V_36 -> V_83 ) ;
if ( V_41 != 0 )
goto V_401;
}
F_75 ( V_2 ) ;
V_41 = F_201 ( V_284 ,
F_55 ( V_2 ) ) ;
if ( V_41 != 0 )
goto V_401;
F_125 ( F_147 ( V_53 ) , V_196 ) ;
if ( ! F_139 ( V_275 , & V_2 -> V_196 ) ) {
V_41 = - V_299 ;
goto V_399;
}
F_283 ( V_275 , & V_2 -> V_196 ) ;
}
F_127 ( F_147 ( V_53 ) , V_196 ) ;
F_80 ( V_2 , V_29 ) ;
V_36 = V_2 -> V_36 ;
F_275 ( V_2 ) ;
if ( V_36 )
F_19 ( V_36 ) ;
return 0 ;
V_401:
F_125 ( F_147 ( V_53 ) , V_196 ) ;
F_283 ( V_275 , & V_2 -> V_196 ) ;
F_283 ( V_266 , & V_2 -> V_196 ) ;
V_399:
F_23 ( V_2 ) ;
F_127 ( F_147 ( V_53 ) , V_196 ) ;
return V_41 ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
F_286 ( & V_2 -> V_53 -> V_54 , L_117
L_118 ) ;
F_39 ( V_57 , V_2 , L_1 , L_119 ) ;
F_217 ( V_2 , NULL , V_402 ) ;
if ( V_2 -> V_28 < V_59 )
return 0 ;
F_204 (cqr, &device->ccw_queue, devlist)
if ( ( V_97 -> V_205 == V_206 ) ||
( V_97 -> V_205 == V_207 ) ) {
V_97 -> V_205 = V_228 ;
V_97 -> V_202 ++ ;
}
F_187 ( V_2 , V_279 ) ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
return 1 ;
}
int F_287 ( struct V_1 * V_2 )
{
F_247 ( & V_2 -> V_53 -> V_54 , L_120
L_121 ) ;
F_39 ( V_57 , V_2 , L_1 , L_122 ) ;
F_148 ( V_2 , V_279 ) ;
if ( V_2 -> V_263 & V_280 ) {
F_148 ( V_2 , V_280 ) ;
F_79 ( V_2 ) ;
return 1 ;
}
F_75 ( V_2 ) ;
if ( V_2 -> V_36 ) {
F_62 ( V_2 -> V_36 ) ;
if ( V_2 -> V_36 -> V_229 )
F_157 ( V_2 -> V_36 -> V_229 ,
true ) ;
}
if ( ! V_2 -> V_263 )
F_71 ( & V_286 ) ;
return 1 ;
}
int F_288 ( struct V_226 * V_53 , int V_403 )
{
struct V_1 * V_2 ;
int V_388 ;
V_2 = F_154 ( V_53 ) ;
if ( F_29 ( V_2 ) )
return 0 ;
V_388 = 0 ;
switch ( V_403 ) {
case V_404 :
case V_405 :
case V_406 :
F_144 ( V_2 ) ;
V_388 = F_143 ( V_2 ) ;
break;
case V_407 :
V_388 = 1 ;
if ( F_140 ( V_2 ) )
V_388 = F_287 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_388 ;
}
void F_289 ( struct V_226 * V_53 , int * V_408 )
{
struct V_1 * V_2 ;
int V_409 , V_410 , V_411 , V_412 ;
V_2 = F_154 ( V_53 ) ;
if ( F_29 ( V_2 ) )
return;
V_410 = F_140 ( V_2 ) ;
for ( V_409 = 0 ; V_409 < 8 ; V_409 ++ ) {
if ( V_408 [ V_409 ] & V_413 ) {
F_290 ( V_2 , V_409 ) ;
}
if ( V_408 [ V_409 ] & V_414 ) {
F_291 ( V_2 , V_409 ) ;
F_75 ( V_2 ) ;
}
if ( V_408 [ V_409 ] & V_415 ) {
if ( ! F_292 ( V_2 , V_409 ) &&
! F_293 ( V_2 , V_409 ) ) {
F_291 ( V_2 , V_409 ) ;
F_75 ( V_2 ) ;
}
F_39 ( V_57 , V_2 , L_1 ,
L_123 ) ;
if ( V_2 -> V_60 -> V_95 )
V_2 -> V_60 -> V_95 ( V_2 ) ;
}
}
V_411 = F_294 ( V_2 ) ;
V_412 = F_295 ( V_2 ) ;
if ( ! F_140 ( V_2 ) && V_411 ) {
if ( V_2 -> V_60 -> V_416 )
V_2 -> V_60 -> V_416 ( V_2 ) ;
F_187 ( V_2 , V_417 ) ;
F_145 ( V_2 , V_411 ) ;
F_75 ( V_2 ) ;
F_296 ( V_2 ) ;
} else if ( ! F_140 ( V_2 ) && V_412 ) {
F_145 ( V_2 , V_412 ) ;
F_75 ( V_2 ) ;
}
if ( V_410 && ! F_140 ( V_2 ) && ! V_411 && ! V_412 ) {
F_286 ( & V_2 -> V_53 -> V_54 ,
L_124 ) ;
F_39 ( V_57 , V_2 ,
L_1 , L_125 ) ;
F_217 ( V_2 , NULL , V_402 ) ;
F_187 ( V_2 ,
V_279 ) ;
}
F_23 ( V_2 ) ;
}
int F_297 ( struct V_1 * V_2 , T_11 V_220 )
{
if ( ! F_140 ( V_2 ) && V_220 ) {
F_298 ( V_2 , V_220 ) ;
F_287 ( V_2 ) ;
} else
F_299 ( V_2 , V_220 ) ;
return 0 ;
}
static int F_300 ( struct V_1 * V_2 )
{
struct V_100 V_418 ;
struct V_96 * V_97 , * V_269 ;
struct V_96 * V_293 ;
int V_41 ;
F_12 ( & V_418 ) ;
F_181 ( F_147 ( V_2 -> V_53 ) ) ;
V_41 = 0 ;
F_182 (cqr, n, &device->ccw_queue, devlist) {
if ( V_97 -> V_205 == V_206 ) {
V_41 = V_2 -> V_60 -> V_276 ( V_97 ) ;
if ( V_41 ) {
F_136 ( & V_2 -> V_53 -> V_54 ,
L_126
L_127 , V_97 ) ;
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
F_23 ( V_2 ) ;
return V_41 ;
}
}
F_170 ( & V_97 -> V_261 , & V_418 ) ;
}
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
F_182 (cqr, n, &requeue_queue, devlist) {
F_83 ( V_241 ,
( V_97 -> V_205 != V_207 ) ) ;
if ( V_97 -> V_271 == V_300 )
V_97 -> V_271 = V_287 ;
F_173 ( & V_97 -> V_261 ) ;
while ( V_97 -> V_293 != NULL ) {
V_293 = V_97 -> V_293 ;
F_301 ( & V_97 -> V_296 ) ;
F_302 ( V_97 , V_97 -> V_419 ) ;
V_97 = V_293 ;
}
if ( F_221 ( V_97 ) )
continue;
if ( V_97 -> V_36 )
F_173 ( & V_97 -> V_296 ) ;
V_97 -> V_36 -> V_64 -> V_60 -> V_307 (
V_97 , (struct V_98 * ) V_97 -> V_271 ) ;
}
if ( ! F_56 ( & V_418 ) ) {
F_181 ( F_147 ( V_2 -> V_53 ) ) ;
F_303 ( & V_418 , & V_2 -> V_15 ) ;
F_183 ( F_147 ( V_2 -> V_53 ) ) ;
}
F_71 ( & V_286 ) ;
return V_41 ;
}
static void V_27 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_72 ( V_90 , struct V_1 ,
V_26 ) ;
F_300 ( V_2 ) ;
F_148 ( V_2 , V_417 ) ;
if ( V_2 -> V_36 )
F_62 ( V_2 -> V_36 ) ;
F_23 ( V_2 ) ;
}
void F_296 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_77 ( & V_2 -> V_26 ) )
F_23 ( V_2 ) ;
}
int F_304 ( struct V_226 * V_53 )
{
struct V_1 * V_2 = F_272 ( V_53 ) ;
if ( F_29 ( V_2 ) )
return F_103 ( V_2 ) ;
F_123 ( V_420 , & V_2 -> V_196 ) ;
if ( V_2 -> V_60 -> V_421 )
V_2 -> V_60 -> V_421 ( V_2 ) ;
F_187 ( V_2 , V_422 ) ;
return F_300 ( V_2 ) ;
}
int F_305 ( struct V_226 * V_53 )
{
struct V_1 * V_2 = F_272 ( V_53 ) ;
int V_41 = 0 ;
if ( F_29 ( V_2 ) )
return F_103 ( V_2 ) ;
F_148 ( V_2 ,
( V_422 | V_280 ) ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_60 -> V_93 && ! ( V_2 -> V_263 ) )
V_41 = V_2 -> V_60 -> V_93 ( V_2 ) ;
if ( V_41 || V_2 -> V_263 )
V_2 -> V_263 |= V_280 ;
if ( V_2 -> V_36 ) {
F_62 ( V_2 -> V_36 ) ;
if ( V_2 -> V_36 -> V_229 )
F_157 ( V_2 -> V_36 -> V_229 ,
true ) ;
}
F_283 ( V_420 , & V_2 -> V_196 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_96 * F_306 ( struct V_1 * V_2 ,
void * V_423 ,
int V_424 ,
int V_190 )
{
struct V_96 * V_97 ;
struct V_193 * V_198 ;
unsigned long * V_425 ;
V_97 = F_124 ( V_190 , 1 , V_424 , V_2 ) ;
if ( F_29 ( V_97 ) ) {
F_136 ( & V_2 -> V_53 -> V_54 ,
L_69
L_70 , L_128 ) ;
return V_97 ;
}
V_198 = V_97 -> V_194 ;
V_198 -> V_426 = V_427 ;
if ( F_307 ( V_423 , V_424 ) ) {
V_425 = ( unsigned long * ) ( V_97 -> V_19 ) ;
V_198 -> V_428 = ( V_429 ) ( V_430 ) V_425 ;
V_198 -> V_196 = V_431 ;
V_425 = F_308 ( V_425 , V_423 , V_424 ) ;
} else {
V_198 -> V_428 = ( V_429 ) ( V_430 ) V_423 ;
V_198 -> V_196 = 0 ;
}
V_198 -> V_432 = V_424 ;
V_97 -> V_107 = V_2 ;
V_97 -> V_419 = V_2 ;
V_97 -> V_225 = 10 * V_277 ;
V_97 -> V_202 = 256 ;
V_97 -> V_147 = F_135 () ;
V_97 -> V_205 = V_289 ;
return V_97 ;
}
int F_309 ( struct V_1 * V_2 , int V_190 ,
void * V_423 , int V_424 )
{
int V_388 ;
struct V_96 * V_97 ;
V_97 = F_306 ( V_2 , V_423 , V_424 ,
V_190 ) ;
if ( F_29 ( V_97 ) )
return F_103 ( V_97 ) ;
V_388 = F_206 ( V_97 ) ;
F_130 ( V_97 , V_97 -> V_419 ) ;
return V_388 ;
}
char * F_163 ( struct V_230 * V_230 )
{
struct V_433 * V_433 = NULL ;
char * V_240 = NULL ;
if ( F_310 ( & V_230 -> V_231 ) && ( V_230 -> V_231 . V_232 . V_434 == 0x01 ) ) {
if ( V_230 -> V_231 . V_232 . V_435 )
V_433 = F_311 ( (struct V_435 * ) ( unsigned long )
V_230 -> V_231 . V_232 . V_435 ) ;
if ( V_433 && V_433 -> V_436 == 64 && V_433 -> V_196 )
switch ( V_433 -> V_196 & 0x07 ) {
case 1 :
V_240 = V_433 -> V_437 . V_438 . V_240 ;
break;
case 2 :
V_240 = V_433 -> V_437 . V_439 . V_240 ;
break;
default:
break;
}
} else if ( V_230 -> V_256 . V_440 . V_441 . V_442 ) {
V_240 = V_230 -> V_443 ;
}
return V_240 ;
}
void F_312 ( struct V_226 * V_53 )
{
struct V_1 * V_2 ;
V_2 = F_272 ( V_53 ) ;
if ( F_29 ( V_2 ) )
return;
if ( V_2 -> V_36 )
F_62 ( V_2 -> V_36 ) ;
F_75 ( V_2 ) ;
F_83 ( V_284 , F_55 ( V_2 ) ) ;
}
static int T_12 F_313 ( void )
{
int V_41 ;
F_314 ( & V_88 ) ;
F_314 ( & V_241 ) ;
F_314 ( & V_286 ) ;
F_314 ( & V_284 ) ;
V_377 = F_36 ( L_37 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_377 == NULL ) {
V_41 = - V_4 ;
goto V_444;
}
F_37 ( V_377 , & V_56 ) ;
F_38 ( V_377 , V_57 ) ;
F_116 ( V_58 , L_1 , L_2 ) ;
V_245 = NULL ;
F_115 () ;
V_41 = F_315 () ;
if ( V_41 )
goto V_444;
V_41 = F_316 () ;
if ( V_41 )
goto V_444;
V_41 = F_317 () ;
if ( V_41 )
goto V_444;
V_41 = F_318 () ;
if ( V_41 )
goto V_444;
#ifdef F_254
V_41 = F_319 () ;
if ( V_41 )
goto V_444;
#endif
return 0 ;
V_444:
F_320 ( L_129 ) ;
F_253 () ;
return V_41 ;
}
