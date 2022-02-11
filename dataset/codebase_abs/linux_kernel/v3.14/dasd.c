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
V_2 -> V_58 = F_36 ( F_35 ( & V_2 -> V_56 -> V_57 ) , 4 , 1 ,
8 * sizeof( long ) ) ;
F_37 ( V_2 -> V_58 , & V_59 ) ;
F_38 ( V_2 -> V_58 , V_60 ) ;
F_39 ( V_61 , V_2 , L_1 , L_2 ) ;
V_2 -> V_26 = V_62 ;
return V_40 ;
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
if ( V_40 != - V_65 ) {
V_2 -> V_26 = V_66 ;
goto V_67;
}
return V_40 ;
}
F_49 ( V_34 ) ;
F_50 ( V_34 -> V_51 ,
V_34 -> V_68 << V_34 -> V_69 ) ;
V_2 -> V_26 = V_70 ;
V_40 = F_51 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_62 ;
return V_40 ;
}
} else {
V_2 -> V_26 = V_70 ;
}
V_67:
if ( V_2 -> V_42 -> V_71 )
V_40 = V_2 -> V_42 -> V_71 ( V_2 ) ;
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
if ( V_2 -> V_42 -> V_72 ) {
V_40 = V_2 -> V_42 -> V_72 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
V_2 -> V_26 = V_62 ;
if ( V_2 -> V_34 ) {
struct V_33 * V_34 = V_2 -> V_34 ;
V_40 = F_55 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_70 ;
return V_40 ;
}
F_56 ( V_34 ) ;
F_57 ( V_34 ) ;
V_34 -> V_68 = 0 ;
V_34 -> V_73 = 0 ;
V_34 -> V_69 = 0 ;
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
struct V_74 * V_75 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
V_2 -> V_26 = V_80 ;
if ( V_2 -> V_34 ) {
F_60 ( V_2 -> V_34 ) ;
if ( ( V_2 -> V_81 & V_82 ) ) {
V_75 = V_2 -> V_34 -> V_51 ;
F_61 ( & F_62 ( V_75 ) -> V_83 , V_84 ) ;
return 0 ;
}
V_75 = V_2 -> V_34 -> V_85 -> V_86 ;
F_63 ( & V_77 , V_75 , V_87 ) ;
while ( ( V_79 = F_64 ( & V_77 ) ) )
F_61 ( & F_65 ( V_79 ) -> V_83 , V_84 ) ;
F_66 ( & V_77 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
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
V_2 -> V_26 = V_70 ;
if ( V_2 -> V_34 && ! ( V_2 -> V_81 & V_82 ) ) {
V_75 = V_2 -> V_34 -> V_85 -> V_86 ;
F_63 ( & V_77 , V_75 , V_87 ) ;
while ( ( V_79 = F_64 ( & V_77 ) ) )
F_61 ( & F_65 ( V_79 ) -> V_83 , V_84 ) ;
F_66 ( & V_77 ) ;
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
V_2 -> V_28 >= V_70 )
V_40 = F_48 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_66 &&
V_2 -> V_28 > V_66 )
V_40 = - V_89 ;
if ( ! V_40 &&
V_2 -> V_26 == V_70 &&
V_2 -> V_28 >= V_80 )
V_40 = F_59 ( V_2 ) ;
return V_40 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_80 &&
V_2 -> V_28 <= V_70 )
V_40 = F_67 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_70 &&
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
F_61 ( & V_2 -> V_56 -> V_57 . V_83 , V_84 ) ;
if ( V_2 -> V_26 == V_2 -> V_28 )
F_71 ( & V_90 ) ;
}
static void V_21 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_72 ( V_92 , struct V_1 , V_20 ) ;
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
static void V_25 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_72 ( V_92 , struct V_1 ,
V_24 ) ;
V_2 -> V_42 -> V_93 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_77 ( & V_2 -> V_24 ) ;
}
static void V_23 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_72 ( V_92 , struct V_1 ,
V_22 ) ;
V_2 -> V_56 -> V_94 -> V_95 ( V_2 -> V_56 ) ;
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
if ( V_96 && V_28 > V_70 )
V_28 = V_70 ;
if ( V_2 -> V_28 != V_28 ) {
if ( V_2 -> V_26 == V_28 )
F_71 ( & V_90 ) ;
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
F_80 ( V_2 , V_80 ) ;
if ( V_2 -> V_26 <= V_41 )
F_80 ( V_2 , V_27 ) ;
F_83 ( V_90 , F_81 ( V_2 ) ) ;
F_78 ( V_2 ) ;
if ( V_2 -> V_42 -> V_97 )
V_2 -> V_42 -> V_97 ( V_2 ) ;
}
static void F_84 ( struct V_33 * V_34 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ;
unsigned int V_104 ;
struct V_1 * V_2 ;
V_104 = 0 ;
if ( V_54 || V_34 -> V_30 . V_19 )
F_85 (l, &block->ccw_queue)
if ( ++ V_104 >= 31 )
break;
if ( V_54 ) {
V_105 . V_106 [ V_104 ] ++ ;
if ( F_86 ( V_101 ) == V_107 )
V_105 . V_108 [ V_104 ] ++ ;
}
F_87 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 ) {
V_34 -> V_30 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_86 ( V_101 ) == V_107 )
V_34 -> V_30 . V_19 -> V_108 [ V_104 ] ++ ;
}
F_88 ( & V_34 -> V_30 . V_31 ) ;
V_2 = V_99 -> V_109 ;
if ( V_2 -> V_30 . V_19 ) {
V_104 = 1 ;
F_85 (l, &device->ccw_queue)
if ( ++ V_104 >= 31 )
break;
}
F_87 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 ) {
V_2 -> V_30 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_86 ( V_101 ) == V_107 )
V_2 -> V_30 . V_19 -> V_108 [ V_104 ] ++ ;
}
F_88 ( & V_2 -> V_30 . V_31 ) ;
}
static void F_89 ( struct V_110 * V_19 ,
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
F_90 ( & V_19 -> V_124 ) ;
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
static void F_91 ( struct V_33 * V_34 ,
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
V_114 = F_92 ( V_101 ) ;
if ( ! V_99 -> V_149 || ! V_99 -> V_150 ||
! V_99 -> V_151 || ! V_99 -> V_152 ||
! V_114 )
return;
V_144 = ( ( V_99 -> V_150 - V_99 -> V_149 ) >> 12 ) ;
V_145 = ( ( V_99 -> V_151 - V_99 -> V_150 ) >> 12 ) ;
V_146 = ( ( V_99 -> V_152 - V_99 -> V_151 ) >> 12 ) ;
V_147 = ( ( V_99 -> V_152 - V_99 -> V_149 ) >> 12 ) ;
V_148 = V_147 / V_114 ;
F_93 ( V_114 , V_115 ) ;
F_93 ( V_147 , V_116 ) ;
F_93 ( V_148 , V_117 ) ;
F_93 ( V_144 , V_118 ) ;
F_93 ( V_145 , V_119 ) ;
F_93 ( V_145 / V_114 , V_120 ) ;
F_93 ( V_146 , V_121 ) ;
if ( V_54 ) {
F_89 ( & V_105 ,
V_99 -> V_109 != V_34 -> V_63 ,
V_99 -> V_153 == 1 ,
F_86 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
}
F_87 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
F_89 ( V_34 -> V_30 . V_19 ,
V_99 -> V_109 != V_34 -> V_63 ,
V_99 -> V_153 == 1 ,
F_86 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
F_88 ( & V_34 -> V_30 . V_31 ) ;
F_87 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 )
F_89 ( V_2 -> V_30 . V_19 ,
V_99 -> V_109 != V_34 -> V_63 ,
V_99 -> V_153 == 1 ,
F_86 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
F_88 ( & V_2 -> V_30 . V_31 ) ;
}
void F_94 ( struct V_154 * V_30 )
{
struct V_110 * V_19 ;
F_95 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_96 ( & V_30 -> V_31 ) ;
return;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_90 ( & V_19 -> V_124 ) ;
F_96 ( & V_30 -> V_31 ) ;
}
void F_97 ( void )
{
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
F_90 ( & V_105 . V_124 ) ;
}
int F_34 ( struct V_154 * V_30 )
{
struct V_110 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_155 ) ;
if ( ! V_19 )
return - V_4 ;
F_95 ( & V_30 -> V_31 ) ;
if ( V_30 -> V_19 ) {
F_96 ( & V_30 -> V_31 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_90 ( & V_19 -> V_124 ) ;
V_30 -> V_19 = V_19 ;
F_96 ( & V_30 -> V_31 ) ;
return 0 ;
}
void F_98 ( struct V_154 * V_30 )
{
F_95 ( & V_30 -> V_31 ) ;
F_5 ( V_30 -> V_19 ) ;
V_30 -> V_19 = NULL ;
F_96 ( & V_30 -> V_31 ) ;
}
char * F_99 ( const char T_1 * V_156 , T_2 V_157 )
{
char * V_158 ;
V_158 = F_100 ( V_157 + 1 ) ;
if ( V_158 == NULL )
return F_3 ( - V_4 ) ;
if ( F_101 ( V_158 , V_156 , V_157 ) != 0 ) {
F_102 ( V_158 ) ;
return F_3 ( - V_159 ) ;
}
if ( V_158 [ V_157 - 1 ] == '\n' )
V_158 [ V_157 - 1 ] = 0 ;
else
V_158 [ V_157 ] = 0 ;
return V_158 ;
}
static T_3 F_103 ( struct V_160 * V_160 ,
const char T_1 * V_156 ,
T_2 V_157 , T_4 * V_161 )
{
char * V_158 , * V_162 ;
int V_40 ;
struct V_163 * V_164 = (struct V_163 * ) V_160 -> V_165 ;
struct V_154 * V_166 = V_164 -> V_32 ;
if ( V_157 > 65536 )
V_157 = 65536 ;
V_158 = F_99 ( V_156 , V_157 ) ;
if ( F_30 ( V_158 ) )
return F_104 ( V_158 ) ;
V_162 = F_105 ( V_158 ) ;
V_40 = V_157 ;
if ( strncmp ( V_162 , L_4 , 5 ) == 0 ) {
F_94 ( V_166 ) ;
} else if ( strncmp ( V_162 , L_5 , 2 ) == 0 ) {
V_40 = F_34 ( V_166 ) ;
if ( ! V_40 )
V_40 = V_157 ;
} else if ( strncmp ( V_162 , L_6 , 3 ) == 0 ) {
F_98 ( V_166 ) ;
} else
V_40 = - V_167 ;
F_102 ( V_158 ) ;
return V_40 ;
}
static void F_106 ( struct V_163 * V_164 , unsigned int * V_168 )
{
int V_169 ;
for ( V_169 = 0 ; V_169 < 32 ; V_169 ++ )
F_107 ( V_164 , L_7 , V_168 [ V_169 ] ) ;
F_108 ( V_164 , '\n' ) ;
}
static void F_109 ( struct V_163 * V_164 ,
struct V_110 * V_19 )
{
F_107 ( V_164 , L_8 ,
V_19 -> V_124 . V_170 , V_19 -> V_124 . V_171 ) ;
F_107 ( V_164 , L_9 , V_19 -> V_122 ) ;
F_107 ( V_164 , L_10 , V_19 -> V_125 ) ;
F_107 ( V_164 , L_11 , V_19 -> V_126 ) ;
F_107 ( V_164 , L_12 , V_19 -> V_127 ) ;
F_107 ( V_164 , L_13 ) ;
F_106 ( V_164 , V_19 -> V_128 ) ;
F_107 ( V_164 , L_14 ) ;
F_106 ( V_164 , V_19 -> V_129 ) ;
F_107 ( V_164 , L_15 ) ;
F_106 ( V_164 , V_19 -> V_130 ) ;
F_107 ( V_164 , L_16 ) ;
F_106 ( V_164 , V_19 -> V_131 ) ;
F_107 ( V_164 , L_17 ) ;
F_106 ( V_164 , V_19 -> V_132 ) ;
F_107 ( V_164 , L_18 ) ;
F_106 ( V_164 , V_19 -> V_133 ) ;
F_107 ( V_164 , L_19 ) ;
F_106 ( V_164 , V_19 -> V_134 ) ;
F_107 ( V_164 , L_20 ) ;
F_106 ( V_164 , V_19 -> V_106 ) ;
F_107 ( V_164 , L_21 , V_19 -> V_135 ) ;
F_107 ( V_164 , L_22 , V_19 -> V_136 ) ;
F_107 ( V_164 , L_23 , V_19 -> V_137 ) ;
F_107 ( V_164 , L_24 , V_19 -> V_138 ) ;
F_107 ( V_164 , L_25 ) ;
F_106 ( V_164 , V_19 -> V_139 ) ;
F_107 ( V_164 , L_26 ) ;
F_106 ( V_164 , V_19 -> V_140 ) ;
F_107 ( V_164 , L_27 ) ;
F_106 ( V_164 , V_19 -> V_141 ) ;
F_107 ( V_164 , L_28 ) ;
F_106 ( V_164 , V_19 -> V_142 ) ;
F_107 ( V_164 , L_29 ) ;
F_106 ( V_164 , V_19 -> V_143 ) ;
F_107 ( V_164 , L_30 ) ;
F_106 ( V_164 , V_19 -> V_108 ) ;
}
static int F_110 ( struct V_163 * V_164 , void * V_172 )
{
struct V_154 * V_30 ;
struct V_110 * V_19 ;
V_30 = V_164 -> V_32 ;
F_95 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_96 ( & V_30 -> V_31 ) ;
F_107 ( V_164 , L_31 ) ;
return 0 ;
}
F_109 ( V_164 , V_19 ) ;
F_96 ( & V_30 -> V_31 ) ;
return 0 ;
}
static int F_111 ( struct V_173 * V_173 , struct V_160 * V_160 )
{
struct V_154 * V_30 = V_173 -> V_174 ;
return F_112 ( V_160 , F_110 , V_30 ) ;
}
static T_3 F_113 ( struct V_160 * V_160 ,
const char T_1 * V_156 ,
T_2 V_157 , T_4 * V_161 )
{
char * V_158 , * V_162 ;
T_3 V_40 ;
if ( V_157 > 65536 )
V_157 = 65536 ;
V_158 = F_99 ( V_156 , V_157 ) ;
if ( F_30 ( V_158 ) )
return F_104 ( V_158 ) ;
V_162 = F_105 ( V_158 ) ;
V_40 = V_157 ;
if ( strncmp ( V_162 , L_4 , 5 ) == 0 ) {
F_97 () ;
} else if ( strncmp ( V_162 , L_5 , 2 ) == 0 ) {
F_97 () ;
V_54 = V_175 ;
} else if ( strncmp ( V_162 , L_6 , 3 ) == 0 ) {
V_54 = V_176 ;
} else
V_40 = - V_167 ;
F_102 ( V_158 ) ;
return V_40 ;
}
static int F_114 ( struct V_163 * V_164 , void * V_172 )
{
if ( ! V_54 ) {
F_107 ( V_164 , L_31 ) ;
return 0 ;
}
F_109 ( V_164 , & V_105 ) ;
return 0 ;
}
static int F_115 ( struct V_173 * V_173 , struct V_160 * V_160 )
{
return F_112 ( V_160 , F_114 , NULL ) ;
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
V_49 = F_116 ( L_32 , V_177 , V_48 ,
V_30 , & V_181 ) ;
if ( V_49 && ! F_30 ( V_49 ) )
V_30 -> V_46 = V_49 ;
return;
}
static void F_41 ( struct V_154 * V_30 )
{
F_98 ( V_30 ) ;
if ( V_30 -> V_46 ) {
F_42 ( V_30 -> V_46 ) ;
V_30 -> V_46 = NULL ;
}
}
static void F_117 ( void )
{
V_54 = V_176 ;
if ( V_182 ) {
F_42 ( V_182 ) ;
V_182 = NULL ;
}
if ( V_183 )
F_42 ( V_183 ) ;
if ( V_53 )
F_42 ( V_53 ) ;
}
static void F_118 ( void )
{
T_5 V_177 ;
struct V_46 * V_49 ;
V_53 = NULL ;
V_183 = NULL ;
V_182 = NULL ;
V_49 = F_29 ( L_33 , NULL ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_53 = V_49 ;
V_49 = F_29 ( L_34 , V_53 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_183 = V_49 ;
V_177 = ( V_178 | V_179 | V_180 ) ;
V_49 = F_116 ( L_32 , V_177 , V_183 ,
NULL , & V_184 ) ;
if ( ! V_49 || F_30 ( V_49 ) )
goto error;
V_182 = V_49 ;
return;
error:
F_119 ( V_185 , L_1 ,
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
int F_120 ( struct V_163 * V_164 , void * V_172 )
{
F_107 ( V_164 , L_36 ) ;
return 0 ;
}
static void F_33 ( struct V_154 * V_30 ,
struct V_46 * V_48 )
{
return;
}
static void F_41 ( struct V_154 * V_30 )
{
return;
}
int F_34 ( struct V_154 * V_30 )
{
return 0 ;
}
struct V_98 * F_121 ( int V_186 , int V_187 ,
int V_188 ,
struct V_1 * V_2 )
{
struct V_98 * V_99 ;
F_122 ( V_188 > V_9 ||
( V_187 * sizeof( struct V_189 ) ) > V_9 ) ;
V_99 = F_2 ( sizeof( struct V_98 ) , V_3 ) ;
if ( V_99 == NULL )
return F_3 ( - V_4 ) ;
V_99 -> V_190 = NULL ;
if ( V_187 > 0 ) {
V_99 -> V_190 = F_123 ( V_187 , sizeof( struct V_189 ) ,
V_3 | V_6 ) ;
if ( V_99 -> V_190 == NULL ) {
F_5 ( V_99 ) ;
return F_3 ( - V_4 ) ;
}
}
V_99 -> V_19 = NULL ;
if ( V_188 > 0 ) {
V_99 -> V_19 = F_2 ( V_188 , V_3 | V_6 ) ;
if ( V_99 -> V_19 == NULL ) {
F_5 ( V_99 -> V_190 ) ;
F_5 ( V_99 ) ;
return F_3 ( - V_4 ) ;
}
}
V_99 -> V_186 = V_186 ;
F_124 ( V_191 , & V_99 -> V_192 ) ;
F_21 ( V_2 ) ;
return V_99 ;
}
struct V_98 * F_125 ( int V_186 , int V_187 ,
int V_188 ,
struct V_1 * V_2 )
{
unsigned long V_192 ;
struct V_98 * V_99 ;
char * V_19 ;
int V_193 ;
V_193 = ( sizeof( struct V_98 ) + 7L ) & - 8L ;
if ( V_187 > 0 )
V_193 += V_187 * sizeof( struct V_189 ) ;
if ( V_188 > 0 )
V_193 += V_188 ;
F_126 ( & V_2 -> V_11 , V_192 ) ;
V_99 = (struct V_98 * )
F_127 ( & V_2 -> V_8 , V_193 ) ;
F_128 ( & V_2 -> V_11 , V_192 ) ;
if ( V_99 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_99 , 0 , sizeof( struct V_98 ) ) ;
V_19 = ( char * ) V_99 + ( ( sizeof( struct V_98 ) + 7L ) & - 8L ) ;
V_99 -> V_190 = NULL ;
if ( V_187 > 0 ) {
V_99 -> V_190 = (struct V_189 * ) V_19 ;
V_19 += V_187 * sizeof( struct V_189 ) ;
memset ( V_99 -> V_190 , 0 , V_187 * sizeof( struct V_189 ) ) ;
}
V_99 -> V_19 = NULL ;
if ( V_188 > 0 ) {
V_99 -> V_19 = V_19 ;
memset ( V_99 -> V_19 , 0 , V_188 ) ;
}
V_99 -> V_186 = V_186 ;
F_124 ( V_191 , & V_99 -> V_192 ) ;
F_21 ( V_2 ) ;
return V_99 ;
}
void F_129 ( struct V_98 * V_99 , struct V_1 * V_2 )
{
#ifdef F_130
struct V_189 * V_194 ;
V_194 = V_99 -> V_190 ;
do {
F_131 ( V_194 ) ;
} while ( V_194 ++ -> V_192 & ( V_195 | V_196 ) );
#endif
F_5 ( V_99 -> V_190 ) ;
F_5 ( V_99 -> V_19 ) ;
F_5 ( V_99 ) ;
F_23 ( V_2 ) ;
}
void F_132 ( struct V_98 * V_99 , struct V_1 * V_2 )
{
unsigned long V_192 ;
F_126 ( & V_2 -> V_11 , V_192 ) ;
F_133 ( & V_2 -> V_8 , V_99 ) ;
F_128 ( & V_2 -> V_11 , V_192 ) ;
F_23 ( V_2 ) ;
}
static inline int F_134 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
if ( V_99 == NULL )
return - V_167 ;
V_2 = V_99 -> V_109 ;
if ( strncmp ( ( char * ) & V_99 -> V_186 , V_2 -> V_42 -> V_197 , 4 ) ) {
F_39 ( V_60 , V_2 ,
L_37
L_38 ,
V_99 -> V_186 ,
* ( unsigned int * ) V_2 -> V_42 -> V_47 ) ;
return - V_167 ;
}
return 0 ;
}
int F_135 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_198 , V_40 ;
char V_199 [ V_200 ] ;
V_40 = F_134 ( V_99 ) ;
if ( V_40 )
return V_40 ;
V_198 = 0 ;
V_2 = (struct V_1 * ) V_99 -> V_109 ;
while ( ( V_198 < 5 ) && ( V_99 -> V_201 == V_202 ) ) {
V_40 = F_136 ( V_2 -> V_56 , ( long ) V_99 ) ;
switch ( V_40 ) {
case 0 :
V_99 -> V_201 = V_203 ;
V_99 -> V_151 = F_137 () ;
V_99 -> V_204 = 0 ;
F_39 ( V_205 , V_2 ,
L_39 ,
V_99 ) ;
break;
case - V_206 :
F_39 ( V_185 , V_2 , L_1 ,
L_40 ) ;
break;
case - V_207 :
F_39 ( V_185 , V_2 , L_1 ,
L_41 ) ;
break;
case - V_167 :
case - V_208 :
F_39 ( V_185 , V_2 , L_1 ,
L_42 ) ;
break;
default:
snprintf ( V_199 , V_200 , L_43 , V_40 ) ;
F_138 ( & V_2 -> V_56 -> V_57 , L_44
L_45 , V_199 ) ;
F_139 () ;
break;
}
V_198 ++ ;
}
F_75 ( V_2 ) ;
return V_40 ;
}
int F_140 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
char V_199 [ V_200 ] ;
V_40 = F_134 ( V_99 ) ;
if ( V_40 ) {
V_99 -> V_209 = V_40 ;
return V_40 ;
}
V_2 = (struct V_1 * ) V_99 -> V_109 ;
if ( ( ( V_99 -> V_34 &&
F_141 ( V_210 , & V_99 -> V_34 -> V_63 -> V_192 ) ) ||
F_141 ( V_210 , & V_2 -> V_192 ) ) &&
! F_141 ( V_211 , & V_99 -> V_192 ) ) {
F_39 ( V_205 , V_2 , L_46
L_47 , V_99 ) ;
V_99 -> V_201 = V_212 ;
V_99 -> V_209 = - V_89 ;
return - V_89 ;
}
if ( V_99 -> V_198 < 0 ) {
sprintf ( V_199 , L_48 , V_99 ) ;
F_138 ( & V_2 -> V_56 -> V_57 , L_49
L_50 , V_199 ) ;
V_99 -> V_201 = V_212 ;
return - V_207 ;
}
V_99 -> V_150 = F_137 () ;
V_99 -> V_204 = V_213 ;
V_99 -> V_198 -- ;
if ( ! F_141 ( V_214 , & V_99 -> V_192 ) ) {
V_99 -> V_215 &= V_2 -> V_216 . V_217 ;
if ( ! V_99 -> V_215 )
V_99 -> V_215 = V_2 -> V_216 . V_217 ;
}
if ( V_99 -> V_153 == 1 ) {
V_40 = F_142 ( V_2 -> V_56 , V_99 -> V_190 ,
( long ) V_99 , V_99 -> V_215 ) ;
} else {
V_40 = F_143 ( V_2 -> V_56 , V_99 -> V_190 ,
( long ) V_99 , V_99 -> V_215 , 0 ) ;
}
switch ( V_40 ) {
case 0 :
V_99 -> V_201 = V_202 ;
break;
case - V_208 :
F_39 ( V_60 , V_2 , L_1 ,
L_51 ) ;
break;
case - V_218 :
F_39 ( V_60 , V_2 , L_1 ,
L_52 ) ;
break;
case - V_219 :
if ( F_141 ( V_214 , & V_99 -> V_192 ) ) {
F_39 ( V_60 , V_2 ,
L_53 ,
V_99 -> V_215 ) ;
} else if ( V_99 -> V_215 != V_2 -> V_216 . V_217 ) {
V_99 -> V_215 = V_2 -> V_216 . V_217 ;
F_39 ( V_205 , V_2 , L_1 ,
L_54
L_55 ) ;
} else {
F_39 ( V_60 , V_2 , L_1 ,
L_56
L_57 ) ;
F_144 ( V_2 ) ;
V_2 -> V_216 . V_217 = 0 ;
V_2 -> V_216 . V_220 = 0 ;
V_2 -> V_216 . V_221 = 0 ;
V_2 -> V_216 . V_222 =
F_145 ( V_2 -> V_56 ) ;
}
break;
case - V_206 :
F_39 ( V_60 , V_2 , L_1 ,
L_58 ) ;
break;
case - V_207 :
F_39 ( V_60 , V_2 , L_1 ,
L_59 ) ;
break;
case - V_167 :
F_39 ( V_60 , V_2 , L_1 ,
L_60
L_61 ) ;
break;
default:
snprintf ( V_199 , V_200 , L_62 , V_40 ) ;
F_138 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , V_199 ) ;
F_139 () ;
break;
}
V_99 -> V_209 = V_40 ;
return V_40 ;
}
static void V_18 ( unsigned long V_223 )
{
unsigned long V_192 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_223 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
F_147 ( V_2 , V_224 ) ;
F_128 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
F_75 ( V_2 ) ;
}
void F_148 ( struct V_1 * V_2 , int V_225 )
{
if ( V_225 == 0 )
F_149 ( & V_2 -> V_16 ) ;
else
F_150 ( & V_2 -> V_16 , V_213 + V_225 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_149 ( & V_2 -> V_16 ) ;
}
static void F_151 ( struct V_226 * V_56 ,
unsigned long V_227 )
{
struct V_98 * V_99 ;
struct V_1 * V_2 ;
if ( ! V_227 )
return;
V_99 = (struct V_98 * ) V_227 ;
if ( V_99 -> V_201 != V_202 ) {
F_152 ( V_205 , V_56 ,
L_65
L_66 , V_99 -> V_201 ) ;
return;
}
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_152 ( V_205 , V_56 , L_1 ,
L_67 ) ;
return;
}
if ( ! V_99 -> V_109 ||
V_2 != V_99 -> V_109 ||
strncmp ( V_99 -> V_109 -> V_42 -> V_197 ,
( char * ) & V_99 -> V_186 , 4 ) ) {
F_152 ( V_205 , V_56 , L_1 ,
L_68 ) ;
F_23 ( V_2 ) ;
return;
}
V_99 -> V_201 = V_228 ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_154 ( struct V_1 * V_2 )
{
F_155 ( V_2 ) ;
F_147 ( V_2 , V_224 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
}
void F_156 ( struct V_226 * V_56 , unsigned long V_227 ,
struct V_229 * V_229 )
{
struct V_98 * V_99 , * V_230 ;
struct V_1 * V_2 ;
unsigned long long V_231 ;
int V_225 ;
if ( F_30 ( V_229 ) ) {
switch ( F_104 ( V_229 ) ) {
case - V_207 :
break;
case - V_218 :
F_152 ( V_60 , V_56 , L_69
L_70 , V_232 ) ;
break;
default:
F_152 ( V_60 , V_56 , L_69
L_71 , V_232 ,
F_104 ( V_229 ) ) ;
}
F_151 ( V_56 , V_227 ) ;
return;
}
V_231 = F_137 () ;
V_99 = (struct V_98 * ) V_227 ;
if ( ! V_99 ||
! ( F_157 ( & V_229 -> V_233 ) == ( V_234 | V_235 ) &&
F_158 ( & V_229 -> V_233 ) == 0 ) ) {
if ( V_99 )
memcpy ( & V_99 -> V_229 , V_229 , sizeof( * V_229 ) ) ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_42 == V_236 ) {
F_23 ( V_2 ) ;
return;
}
V_2 -> V_42 -> V_237 ( V_2 , V_229 , L_72 ) ;
if ( V_2 -> V_81 & V_238 )
V_2 -> V_42 -> V_239 ( V_2 , V_99 , V_229 ) ;
V_2 -> V_42 -> V_240 ( V_2 , V_99 , V_229 ) ;
F_23 ( V_2 ) ;
}
if ( ! V_99 )
return;
V_2 = (struct V_1 * ) V_99 -> V_109 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_42 -> V_197 , ( char * ) & V_99 -> V_186 , 4 ) ) {
F_152 ( V_205 , V_56 , L_1 ,
L_68 ) ;
return;
}
if ( V_99 -> V_201 == V_203 &&
F_159 ( & V_229 -> V_233 ) & V_241 ) {
V_99 -> V_201 = V_242 ;
F_46 ( V_2 ) ;
F_71 ( & V_243 ) ;
F_75 ( V_2 ) ;
return;
}
if ( V_99 -> V_201 != V_202 ) {
F_39 ( V_205 , V_2 , L_73
L_74 , F_35 ( & V_56 -> V_57 ) , V_99 -> V_201 ) ;
return;
}
V_230 = NULL ;
V_225 = 0 ;
if ( F_157 ( & V_229 -> V_233 ) == ( V_234 | V_235 ) &&
F_158 ( & V_229 -> V_233 ) == 0 ) {
V_99 -> V_201 = V_244 ;
V_99 -> V_151 = V_231 ;
if ( V_99 -> V_245 . V_230 != & V_2 -> V_15 ) {
V_230 = F_160 ( V_99 -> V_245 . V_230 ,
struct V_98 , V_245 ) ;
}
} else {
if ( ! F_141 ( V_191 , & V_99 -> V_192 ) &&
V_99 -> V_198 > 0 ) {
if ( V_99 -> V_215 == V_2 -> V_216 . V_217 )
F_39 ( V_205 , V_2 ,
L_75
L_76 ,
V_99 -> V_198 ) ;
if ( ! F_141 ( V_214 , & V_99 -> V_192 ) )
V_99 -> V_215 = V_2 -> V_216 . V_217 ;
V_99 -> V_201 = V_228 ;
V_230 = V_99 ;
} else
V_99 -> V_201 = V_212 ;
}
if ( V_230 && ( V_230 -> V_201 == V_228 ) &&
( ! V_2 -> V_246 ) ) {
if ( V_2 -> V_42 -> V_247 ( V_230 ) == 0 )
V_225 = V_230 -> V_225 ;
}
if ( V_225 != 0 )
F_148 ( V_2 , V_225 ) ;
else
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
}
enum V_248 F_161 ( struct V_226 * V_56 , struct V_229 * V_229 )
{
struct V_1 * V_2 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
goto V_67;
if ( F_141 ( V_249 , & V_2 -> V_192 ) ||
V_2 -> V_26 != V_2 -> V_28 ||
! V_2 -> V_42 -> V_240 ) {
F_23 ( V_2 ) ;
goto V_67;
}
if ( V_2 -> V_42 -> V_237 )
V_2 -> V_42 -> V_237 ( V_2 , V_229 , L_77 ) ;
V_2 -> V_42 -> V_240 ( V_2 , NULL , V_229 ) ;
F_23 ( V_2 ) ;
V_67:
return V_250 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_98 * V_251 )
{
struct V_102 * V_103 , * V_252 ;
struct V_98 * V_99 ;
if ( ! V_251 -> V_34 )
return;
F_163 (l, n, &device->ccw_queue) {
V_99 = F_160 ( V_103 , struct V_98 , V_245 ) ;
if ( V_99 -> V_201 == V_228 &&
V_251 -> V_34 == V_99 -> V_34 ) {
V_99 -> V_201 = V_242 ;
}
}
}
static void F_164 ( struct V_1 * V_2 ,
struct V_102 * V_253 )
{
struct V_102 * V_103 , * V_252 ;
struct V_98 * V_99 ;
F_163 (l, n, &device->ccw_queue) {
V_99 = F_160 ( V_103 , struct V_98 , V_245 ) ;
if ( V_99 -> V_201 == V_228 ||
V_99 -> V_201 == V_202 ||
V_99 -> V_201 == V_203 )
continue;
if ( V_99 -> V_201 == V_212 ) {
F_162 ( V_2 , V_99 ) ;
}
F_165 ( & V_99 -> V_245 , V_253 ) ;
}
}
static void F_166 ( struct V_1 * V_2 ,
struct V_102 * V_253 )
{
struct V_102 * V_103 , * V_252 ;
struct V_98 * V_99 ;
struct V_33 * V_34 ;
void (* F_167)( struct V_98 * , void * V_19 );
void * V_254 ;
char V_199 [ V_200 ] ;
F_163 (l, n, final_queue) {
V_99 = F_160 ( V_103 , struct V_98 , V_245 ) ;
F_168 ( & V_99 -> V_245 ) ;
V_34 = V_99 -> V_34 ;
F_167 = V_99 -> F_167 ;
V_254 = V_99 -> V_254 ;
if ( V_34 )
F_95 ( & V_34 -> V_38 ) ;
switch ( V_99 -> V_201 ) {
case V_244 :
V_99 -> V_201 = V_255 ;
break;
case V_212 :
V_99 -> V_201 = V_256 ;
break;
case V_242 :
V_99 -> V_201 = V_257 ;
break;
default:
snprintf ( V_199 , V_200 , L_78 , V_99 , V_99 -> V_201 ) ;
F_138 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , V_199 ) ;
F_139 () ;
}
if ( V_99 -> F_167 != NULL )
( F_167 ) ( V_99 , V_254 ) ;
if ( V_34 )
F_96 ( & V_34 -> V_38 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
if ( F_53 ( & V_2 -> V_15 ) )
return;
V_99 = F_160 ( V_2 -> V_15 . V_230 , struct V_98 , V_245 ) ;
if ( ( V_99 -> V_201 == V_202 && V_99 -> V_225 != 0 ) &&
( F_170 ( V_213 , V_99 -> V_225 + V_99 -> V_204 ) ) ) {
if ( F_141 ( V_258 , & V_2 -> V_192 ) ) {
V_99 -> V_198 ++ ;
}
if ( V_2 -> V_42 -> V_259 ( V_99 ) != 0 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_79
L_80 ,
V_99 , ( V_99 -> V_225 / V_260 ) ) ;
V_99 -> V_225 += 5 * V_260 ;
F_148 ( V_2 , 5 * V_260 ) ;
} else {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_81
L_82 , V_99 , ( V_99 -> V_225 / V_260 ) ,
V_99 -> V_198 ) ;
}
}
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
int V_40 ;
if ( F_53 ( & V_2 -> V_15 ) )
return;
V_99 = F_160 ( V_2 -> V_15 . V_230 , struct V_98 , V_245 ) ;
if ( V_99 -> V_201 != V_228 )
return;
if ( V_2 -> V_246 &&
! ( ! ( V_2 -> V_246 & ~ ( V_261 | V_262 ) )
&& F_141 ( V_214 , & V_99 -> V_192 ) ) ) {
V_99 -> V_209 = - V_65 ;
V_99 -> V_201 = V_242 ;
F_75 ( V_2 ) ;
return;
}
V_40 = V_2 -> V_42 -> V_247 ( V_99 ) ;
if ( V_40 == 0 )
F_148 ( V_2 , V_99 -> V_225 ) ;
else if ( V_40 == - V_219 ) {
F_75 ( V_2 ) ;
} else
F_148 ( V_2 , 50 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_216 . V_222 ) {
if ( V_2 -> V_246 & ~ ( V_261 |
V_262 ) )
return;
V_40 = V_2 -> V_42 -> V_263 (
V_2 , V_2 -> V_216 . V_222 ) ;
if ( V_40 )
F_148 ( V_2 , 50 ) ;
else
V_2 -> V_216 . V_222 = 0 ;
}
}
int F_45 ( struct V_1 * V_2 )
{
struct V_98 * V_99 , * V_252 ;
int V_40 ;
struct V_102 V_264 ;
F_12 ( & V_264 ) ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = 0 ;
F_174 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_99 -> V_201 ) {
case V_202 :
V_40 = V_2 -> V_42 -> V_259 ( V_99 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_83
L_84 , V_99 ) ;
goto V_265;
}
break;
case V_228 :
V_99 -> V_151 = F_137 () ;
V_99 -> V_201 = V_242 ;
break;
default:
break;
}
F_165 ( & V_99 -> V_245 , & V_264 ) ;
}
V_265:
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_174 (cqr, n, &flush_queue, devlist)
F_83 ( V_243 ,
( V_99 -> V_201 != V_203 ) ) ;
F_166 ( V_2 , & V_264 ) ;
return V_40 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_102 V_253 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_253 ) ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
F_169 ( V_2 ) ;
F_164 ( V_2 , & V_253 ) ;
F_172 ( V_2 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_166 ( V_2 , & V_253 ) ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
F_171 ( V_2 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
if ( F_176 ( & V_266 ) )
F_71 ( & V_266 ) ;
F_23 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( F_177 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_178 ( & V_2 -> V_13 ) ;
}
void F_179 ( struct V_1 * V_2 , int V_267 )
{
V_2 -> V_246 |= V_267 ;
}
void F_147 ( struct V_1 * V_2 , int V_267 )
{
V_2 -> V_246 &= ~ V_267 ;
if ( ! V_2 -> V_246 )
F_71 ( & V_268 ) ;
}
void F_180 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
unsigned long V_192 ;
V_2 = V_99 -> V_109 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
V_99 -> V_201 = V_228 ;
F_181 ( & V_99 -> V_245 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_128 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
}
void F_182 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
unsigned long V_192 ;
V_2 = V_99 -> V_109 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
V_99 -> V_201 = V_228 ;
F_183 ( & V_99 -> V_245 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_128 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
}
void F_184 ( struct V_98 * V_99 , void * V_19 )
{
F_173 ( F_146 ( V_99 -> V_109 -> V_56 ) ) ;
V_99 -> V_254 = V_269 ;
F_175 ( F_146 ( V_99 -> V_109 -> V_56 ) ) ;
F_71 ( & V_268 ) ;
}
static inline int F_185 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_99 -> V_109 ;
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = ( V_99 -> V_254 == V_269 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
static int F_186 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
T_6 V_270 ;
if ( V_99 -> V_201 == V_271 )
return 0 ;
V_2 = V_99 -> V_109 ;
if ( F_141 ( V_191 , & V_99 -> V_192 ) ) {
if ( V_99 -> V_201 == V_257 ) {
V_2 -> V_42 -> V_272 ( V_99 ) ;
return 1 ;
}
if ( V_99 -> V_201 == V_256 ) {
V_270 = V_2 -> V_42 -> V_273 ( V_99 ) ;
V_270 ( V_99 ) ;
return 1 ;
}
if ( V_99 -> V_201 == V_274 )
F_187 ( V_99 , & V_99 -> V_229 ) ;
if ( V_99 -> V_275 ) {
F_188 ( V_2 , V_99 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_189 ( struct V_98 * V_99 )
{
if ( F_141 ( V_191 , & V_99 -> V_192 ) ) {
if ( V_99 -> V_275 )
return 1 ;
return ( ( V_99 -> V_201 != V_255 ) &&
( V_99 -> V_201 != V_274 ) ) ;
} else
return ( V_99 -> V_201 == V_271 ) ;
}
static int F_190 ( struct V_98 * V_276 , int V_277 )
{
struct V_1 * V_2 ;
int V_40 ;
struct V_102 V_15 ;
struct V_98 * V_99 ;
F_12 ( & V_15 ) ;
V_276 -> V_201 = V_271 ;
V_2 = V_276 -> V_109 ;
F_181 ( & V_276 -> V_278 , & V_15 ) ;
for ( V_99 = V_276 ; F_189 ( V_99 ) ;
V_99 = F_191 ( & V_15 ,
struct V_98 , V_278 ) ) {
if ( F_186 ( V_99 ) )
continue;
if ( V_99 -> V_201 != V_271 )
continue;
if ( F_141 ( V_210 , & V_2 -> V_192 ) &&
! F_141 ( V_211 , & V_99 -> V_192 ) ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = - V_89 ;
continue;
}
if ( V_2 -> V_246 & ~ V_224 &&
F_141 ( V_279 , & V_99 -> V_192 ) &&
( ! F_192 ( V_2 ) ) ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = - V_280 ;
continue;
}
if ( V_277 ) {
V_40 = F_193 (
V_268 , ! ( V_2 -> V_246 ) ) ;
if ( V_40 == - V_281 ) {
V_99 -> V_201 = V_274 ;
V_276 -> V_209 = V_40 ;
continue;
}
} else
F_83 ( V_268 , ! ( V_2 -> V_246 ) ) ;
if ( ! V_99 -> F_167 )
V_99 -> F_167 = F_184 ;
V_99 -> V_254 = V_282 ;
F_182 ( V_99 ) ;
if ( V_277 ) {
V_40 = F_193 (
V_268 , F_185 ( V_99 ) ) ;
if ( V_40 == - V_281 ) {
F_194 ( V_99 ) ;
F_83 ( V_268 ,
F_185 ( V_99 ) ) ;
V_99 -> V_201 = V_274 ;
V_276 -> V_209 = V_40 ;
continue;
}
} else
F_83 ( V_268 , F_185 ( V_99 ) ) ;
}
V_276 -> V_152 = F_137 () ;
if ( ( V_276 -> V_201 != V_255 ) &&
( V_276 -> V_209 != - V_281 ) )
F_187 ( V_276 , & V_276 -> V_229 ) ;
if ( V_276 -> V_201 == V_255 )
V_40 = 0 ;
else if ( V_276 -> V_209 )
V_40 = V_276 -> V_209 ;
else
V_40 = - V_207 ;
return V_40 ;
}
static inline int F_195 ( struct V_102 * V_15 )
{
struct V_98 * V_99 ;
F_196 (cqr, ccw_queue, blocklist) {
if ( V_99 -> V_254 != V_269 )
return 0 ;
}
return 1 ;
}
static int F_197 ( struct V_102 * V_15 , int V_277 )
{
struct V_1 * V_2 ;
int V_40 ;
struct V_98 * V_99 , * V_252 ;
V_283:
F_174 (cqr, n, ccw_queue, blocklist) {
V_2 = V_99 -> V_109 ;
if ( V_99 -> V_201 != V_271 )
continue;
if ( F_141 ( V_210 , & V_2 -> V_192 ) &&
! F_141 ( V_211 , & V_99 -> V_192 ) ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = - V_89 ;
continue;
}
if ( V_2 -> V_246 & ~ V_224 &&
F_141 ( V_279 , & V_99 -> V_192 ) &&
! F_192 ( V_2 ) ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = - V_65 ;
continue;
}
if ( V_277 ) {
V_40 = F_193 (
V_268 , ! V_2 -> V_246 ) ;
if ( V_40 == - V_281 ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = V_40 ;
continue;
}
} else
F_83 ( V_268 , ! ( V_2 -> V_246 ) ) ;
if ( ! V_99 -> F_167 )
V_99 -> F_167 = F_184 ;
V_99 -> V_254 = V_282 ;
F_182 ( V_99 ) ;
}
F_83 ( V_268 , F_195 ( V_15 ) ) ;
V_40 = 0 ;
F_174 (cqr, n, ccw_queue, blocklist) {
if ( F_186 ( V_99 ) )
V_40 = 1 ;
}
if ( V_40 )
goto V_283;
return 0 ;
}
int F_198 ( struct V_98 * V_99 )
{
return F_190 ( V_99 , 0 ) ;
}
int F_199 ( struct V_102 * V_15 )
{
return F_197 ( V_15 , 0 ) ;
}
int F_200 ( struct V_98 * V_99 )
{
return F_190 ( V_99 , 1 ) ;
}
static inline int F_201 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
int V_40 ;
if ( F_53 ( & V_2 -> V_15 ) )
return 0 ;
V_99 = F_160 ( V_2 -> V_15 . V_230 , struct V_98 , V_245 ) ;
V_40 = V_2 -> V_42 -> V_259 ( V_99 ) ;
if ( ! V_40 )
V_99 -> V_198 ++ ;
return V_40 ;
}
int F_202 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_99 -> V_109 ;
if ( F_141 ( V_210 , & V_2 -> V_192 ) &&
! F_141 ( V_211 , & V_99 -> V_192 ) ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = - V_89 ;
return - V_207 ;
}
F_173 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = F_201 ( V_2 ) ;
if ( V_40 ) {
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
V_99 -> F_167 = F_184 ;
V_99 -> V_254 = V_282 ;
V_99 -> V_201 = V_228 ;
F_181 ( & V_99 -> V_245 , V_2 -> V_15 . V_230 ) ;
F_75 ( V_2 ) ;
F_175 ( F_146 ( V_2 -> V_56 ) ) ;
F_83 ( V_268 , F_185 ( V_99 ) ) ;
if ( V_99 -> V_201 == V_255 )
V_40 = 0 ;
else if ( V_99 -> V_209 )
V_40 = V_99 -> V_209 ;
else
V_40 = - V_207 ;
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
return V_40 ;
}
int F_194 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_109 ;
unsigned long V_192 ;
int V_40 ;
V_40 = 0 ;
F_126 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
switch ( V_99 -> V_201 ) {
case V_228 :
V_99 -> V_201 = V_242 ;
break;
case V_202 :
V_40 = V_2 -> V_42 -> V_259 ( V_99 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_85 ,
V_99 , V_40 ) ;
} else {
V_99 -> V_151 = F_137 () ;
}
break;
default:
break;
}
F_128 ( F_146 ( V_2 -> V_56 ) , V_192 ) ;
F_75 ( V_2 ) ;
return V_40 ;
}
static void V_39 ( unsigned long V_223 )
{
unsigned long V_192 ;
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_223 ;
F_126 ( F_146 ( V_34 -> V_63 -> V_56 ) , V_192 ) ;
F_147 ( V_34 -> V_63 , V_224 ) ;
F_128 ( F_146 ( V_34 -> V_63 -> V_56 ) , V_192 ) ;
F_60 ( V_34 ) ;
}
void F_203 ( struct V_33 * V_34 , int V_225 )
{
if ( V_225 == 0 )
F_149 ( & V_34 -> V_16 ) ;
else
F_150 ( & V_34 -> V_16 , V_213 + V_225 ) ;
}
void F_44 ( struct V_33 * V_34 )
{
F_149 ( & V_34 -> V_16 ) ;
}
static void F_188 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
T_6 V_270 ;
if ( V_99 -> V_201 == V_255 )
F_39 ( V_284 , V_2 , L_1 , L_86 ) ;
else
F_138 ( & V_2 -> V_56 -> V_57 , L_87 ) ;
V_270 = V_2 -> V_42 -> V_285 ( V_99 ) ;
V_270 ( V_99 ) ;
}
static void F_204 ( struct V_33 * V_34 )
{
struct V_286 * V_287 ;
struct V_100 * V_101 ;
struct V_98 * V_99 ;
struct V_1 * V_288 ;
unsigned long V_192 ;
V_287 = V_34 -> V_286 ;
V_288 = V_34 -> V_63 ;
if ( V_287 == NULL )
return;
if ( V_288 -> V_26 < V_70 ) {
while ( ( V_101 = F_205 ( V_34 -> V_286 ) ) )
F_206 ( V_101 , - V_207 ) ;
return;
}
while ( ( V_101 = F_207 ( V_287 ) ) ) {
if ( V_288 -> V_81 & V_289 &&
F_86 ( V_101 ) == V_290 ) {
F_39 ( V_185 , V_288 ,
L_88 ,
V_101 ) ;
F_208 ( V_101 ) ;
F_206 ( V_101 , - V_207 ) ;
continue;
}
if ( F_141 ( V_291 , & V_288 -> V_192 ) &&
( V_288 -> V_81 & V_292 ||
F_209 ( V_101 ) ) ) {
F_39 ( V_185 , V_288 ,
L_89 ,
V_101 ) ;
F_208 ( V_101 ) ;
F_206 ( V_101 , - V_218 ) ;
continue;
}
V_99 = V_288 -> V_42 -> V_293 ( V_288 , V_34 , V_101 ) ;
if ( F_30 ( V_99 ) ) {
if ( F_104 ( V_99 ) == - V_208 )
break;
if ( F_104 ( V_99 ) == - V_4 )
break;
if ( F_104 ( V_99 ) == - V_65 ) {
if ( ! F_53 ( & V_34 -> V_15 ) )
break;
F_126 (
F_146 ( V_288 -> V_56 ) , V_192 ) ;
F_179 ( V_288 ,
V_224 ) ;
F_128 (
F_146 ( V_288 -> V_56 ) , V_192 ) ;
F_203 ( V_34 , V_260 / 2 ) ;
break;
}
F_39 ( V_185 , V_288 ,
L_90
L_91 ,
F_104 ( V_99 ) , V_101 ) ;
F_208 ( V_101 ) ;
F_206 ( V_101 , - V_207 ) ;
continue;
}
V_99 -> V_254 = ( void * ) V_101 ;
V_99 -> V_201 = V_271 ;
V_101 -> V_294 = V_99 ;
F_208 ( V_101 ) ;
F_183 ( & V_99 -> V_278 , & V_34 -> V_15 ) ;
F_12 ( & V_99 -> V_245 ) ;
F_84 ( V_34 , V_99 , V_101 ) ;
}
}
static void F_210 ( struct V_98 * V_99 )
{
struct V_100 * V_101 ;
int V_201 ;
int error = 0 ;
V_101 = (struct V_100 * ) V_99 -> V_254 ;
F_91 ( V_99 -> V_34 , V_99 , V_101 ) ;
V_201 = V_99 -> V_34 -> V_63 -> V_42 -> V_295 ( V_99 , V_101 ) ;
if ( V_201 < 0 )
error = V_201 ;
else if ( V_201 == 0 ) {
if ( V_99 -> V_209 == - V_89 )
error = - V_296 ;
else if ( V_99 -> V_209 == - V_280 ||
V_99 -> V_209 == - V_218 )
error = V_99 -> V_209 ;
else
error = - V_207 ;
}
F_206 ( V_101 , error ) ;
}
static void F_211 ( struct V_33 * V_34 ,
struct V_102 * V_253 )
{
struct V_102 * V_103 , * V_252 ;
struct V_98 * V_99 ;
T_6 V_270 ;
unsigned long V_192 ;
struct V_1 * V_63 = V_34 -> V_63 ;
V_297:
F_163 (l, n, &block->ccw_queue) {
V_99 = F_160 ( V_103 , struct V_98 , V_278 ) ;
if ( V_99 -> V_201 != V_255 &&
V_99 -> V_201 != V_274 &&
V_99 -> V_201 != V_256 &&
V_99 -> V_201 != V_257 )
continue;
if ( V_99 -> V_201 == V_257 ) {
V_63 -> V_42 -> V_272 ( V_99 ) ;
goto V_297;
}
if ( V_99 -> V_201 == V_256 ) {
V_270 = V_63 -> V_42 -> V_273 ( V_99 ) ;
if ( F_30 ( V_270 ( V_99 ) ) )
continue;
goto V_297;
}
if ( V_99 -> V_201 == V_274 ) {
F_187 ( V_99 , & V_99 -> V_229 ) ;
}
if ( F_192 ( V_63 ) &&
V_99 -> V_201 == V_274 ) {
F_212 ( V_63 , V_99 , V_298 ) ;
V_99 -> V_201 = V_271 ;
V_99 -> V_198 = 255 ;
F_126 ( F_146 ( V_63 -> V_56 ) , V_192 ) ;
F_179 ( V_63 , V_299 ) ;
F_128 ( F_146 ( V_63 -> V_56 ) ,
V_192 ) ;
goto V_297;
}
if ( V_99 -> V_275 ) {
F_188 ( V_63 , V_99 ) ;
goto V_297;
}
V_99 -> V_152 = F_137 () ;
F_165 ( & V_99 -> V_278 , V_253 ) ;
}
}
static void F_213 ( struct V_98 * V_99 , void * V_19 )
{
F_60 ( V_99 -> V_34 ) ;
}
static void F_214 ( struct V_33 * V_34 )
{
struct V_98 * V_99 ;
if ( F_53 ( & V_34 -> V_15 ) )
return;
F_196 (cqr, &block->ccw_queue, blocklist) {
if ( V_99 -> V_201 != V_271 )
continue;
if ( F_141 ( V_210 , & V_34 -> V_63 -> V_192 ) &&
! F_141 ( V_211 , & V_99 -> V_192 ) ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = - V_89 ;
F_60 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_246 & ~ V_224 &&
F_141 ( V_279 , & V_99 -> V_192 ) &&
( ! F_192 ( V_34 -> V_63 ) ) ) {
V_99 -> V_201 = V_274 ;
V_99 -> V_209 = - V_280 ;
F_60 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_246 )
return;
if ( ! V_99 -> V_109 )
V_99 -> V_109 = V_34 -> V_63 ;
V_99 -> F_167 = F_213 ;
F_182 ( V_99 ) ;
}
}
static void V_37 ( struct V_33 * V_34 )
{
struct V_102 V_253 ;
struct V_102 * V_103 , * V_252 ;
struct V_98 * V_99 ;
F_10 ( & V_34 -> V_12 , 0 ) ;
F_12 ( & V_253 ) ;
F_87 ( & V_34 -> V_38 ) ;
F_211 ( V_34 , & V_253 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_173 ( & V_34 -> V_36 ) ;
F_163 (l, n, &final_queue) {
V_99 = F_160 ( V_103 , struct V_98 , V_278 ) ;
F_168 ( & V_99 -> V_278 ) ;
F_210 ( V_99 ) ;
}
F_87 ( & V_34 -> V_38 ) ;
F_204 ( V_34 ) ;
F_214 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_175 ( & V_34 -> V_36 ) ;
if ( F_176 ( & V_266 ) )
F_71 ( & V_266 ) ;
F_23 ( V_34 -> V_63 ) ;
}
static void F_215 ( struct V_98 * V_99 , void * V_19 )
{
F_71 ( & V_243 ) ;
}
static int F_216 ( struct V_98 * V_99 )
{
struct V_33 * V_34 = V_99 -> V_34 ;
struct V_100 * V_101 ;
unsigned long V_192 ;
if ( ! V_34 )
return - V_167 ;
F_126 ( & V_34 -> V_38 , V_192 ) ;
V_101 = (struct V_100 * ) V_99 -> V_254 ;
F_217 ( V_34 -> V_286 , V_101 ) ;
F_128 ( & V_34 -> V_38 , V_192 ) ;
return 0 ;
}
static int F_55 ( struct V_33 * V_34 )
{
struct V_98 * V_99 , * V_252 ;
int V_40 , V_169 ;
struct V_102 V_264 ;
F_12 ( & V_264 ) ;
F_95 ( & V_34 -> V_38 ) ;
V_40 = 0 ;
V_297:
F_174 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_99 -> V_201 >= V_228 )
V_40 = F_194 ( V_99 ) ;
if ( V_40 < 0 )
break;
V_99 -> F_167 = F_215 ;
for ( V_169 = 0 ; V_99 != NULL ; V_99 = V_99 -> V_275 , V_169 ++ )
F_165 ( & V_99 -> V_278 , & V_264 ) ;
if ( V_169 > 1 )
goto V_297;
}
F_96 ( & V_34 -> V_38 ) ;
V_300:
F_174 (cqr, n, &flush_queue, blocklist) {
F_83 ( V_243 , ( V_99 -> V_201 < V_228 ) ) ;
if ( V_99 -> V_275 ) {
F_95 ( & V_34 -> V_38 ) ;
F_188 ( V_34 -> V_63 , V_99 ) ;
F_96 ( & V_34 -> V_38 ) ;
goto V_300;
}
F_173 ( & V_34 -> V_36 ) ;
V_99 -> V_152 = F_137 () ;
F_168 ( & V_99 -> V_278 ) ;
F_210 ( V_99 ) ;
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
static void F_218 ( struct V_286 * V_287 )
{
struct V_33 * V_34 ;
V_34 = V_287 -> V_301 ;
F_87 ( & V_34 -> V_38 ) ;
F_204 ( V_34 ) ;
F_214 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
}
enum V_302 F_219 ( struct V_100 * V_101 )
{
struct V_98 * V_99 = V_101 -> V_294 ;
struct V_33 * V_34 = V_101 -> V_303 -> V_301 ;
struct V_1 * V_2 ;
int V_40 = 0 ;
if ( ! V_99 )
return V_304 ;
V_2 = V_99 -> V_109 ? V_99 -> V_109 : V_34 -> V_63 ;
if ( ! V_2 -> V_305 )
return V_306 ;
F_39 ( V_60 , V_2 ,
L_92 ,
V_99 , V_99 -> V_201 ) ;
F_87 ( & V_34 -> V_38 ) ;
F_87 ( F_146 ( V_2 -> V_56 ) ) ;
V_99 -> V_198 = - 1 ;
V_99 -> V_209 = - V_218 ;
if ( V_99 -> V_201 >= V_228 ) {
F_88 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = F_194 ( V_99 ) ;
} else if ( V_99 -> V_201 == V_271 ||
V_99 -> V_201 == V_256 ) {
V_99 -> V_201 = V_257 ;
F_88 ( F_146 ( V_2 -> V_56 ) ) ;
} else if ( V_99 -> V_201 == V_307 ) {
struct V_98 * V_308 , * V_309 , * V_310 ;
F_174 (searchcqr, nextcqr,
&block->ccw_queue, blocklist) {
V_310 = V_308 ;
while ( V_310 -> V_275 )
V_310 = V_310 -> V_275 ;
if ( V_310 != V_99 )
continue;
V_308 -> V_198 = - 1 ;
V_308 -> V_209 = - V_218 ;
if ( V_308 -> V_201 >= V_228 ) {
F_88 ( F_146 ( V_2 -> V_56 ) ) ;
V_40 = F_194 ( V_308 ) ;
F_87 ( F_146 ( V_2 -> V_56 ) ) ;
} else if ( ( V_308 -> V_201 == V_271 ) ||
( V_308 -> V_201 == V_256 ) ) {
V_308 -> V_201 = V_257 ;
V_40 = 0 ;
} else if ( V_308 -> V_201 == V_307 ) {
continue;
}
break;
}
F_88 ( F_146 ( V_2 -> V_56 ) ) ;
}
F_60 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
return V_40 ? V_306 : V_304 ;
}
static int F_22 ( struct V_33 * V_34 )
{
int V_40 ;
V_34 -> V_286 = F_220 ( F_218 ,
& V_34 -> V_36 ) ;
if ( V_34 -> V_286 == NULL )
return - V_4 ;
V_34 -> V_286 -> V_301 = V_34 ;
F_221 ( V_34 -> V_286 -> V_311 ) ;
V_34 -> V_286 -> V_311 = NULL ;
F_73 ( & V_34 -> V_286 -> V_312 ) ;
V_40 = F_222 ( V_34 -> V_286 , L_93 ) ;
if ( V_40 )
F_223 ( V_34 -> V_286 ) ;
F_74 ( & V_34 -> V_286 -> V_312 ) ;
return V_40 ;
}
static void F_49 ( struct V_33 * V_34 )
{
int V_313 ;
if ( V_34 -> V_63 -> V_81 & V_82 ) {
V_313 = 2048 ;
} else {
V_313 = V_34 -> V_63 -> V_42 -> V_314 << V_34 -> V_69 ;
}
F_224 ( V_34 -> V_286 ,
V_34 -> V_73 ) ;
F_225 ( V_34 -> V_286 , V_313 ) ;
F_226 ( V_34 -> V_286 , - 1L ) ;
F_227 ( V_34 -> V_286 , V_9 ) ;
F_228 ( V_34 -> V_286 , V_9 - 1 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
if ( V_34 -> V_286 ) {
F_223 ( V_34 -> V_286 ) ;
V_34 -> V_286 = NULL ;
}
}
static void F_56 ( struct V_33 * V_34 )
{
struct V_100 * V_101 ;
if ( ! V_34 -> V_286 )
return;
F_173 ( & V_34 -> V_36 ) ;
while ( ( V_101 = F_205 ( V_34 -> V_286 ) ) )
F_206 ( V_101 , - V_207 ) ;
F_175 ( & V_34 -> V_36 ) ;
}
static int F_229 ( struct V_315 * V_85 , T_7 V_177 )
{
struct V_1 * V_63 ;
int V_40 ;
V_63 = F_230 ( V_85 -> V_86 ) ;
if ( ! V_63 )
return - V_206 ;
F_231 ( & V_63 -> V_34 -> V_35 ) ;
if ( F_141 ( V_249 , & V_63 -> V_192 ) ) {
V_40 = - V_206 ;
goto V_316;
}
if ( ! F_232 ( V_63 -> V_42 -> V_44 ) ) {
V_40 = - V_167 ;
goto V_316;
}
if ( V_96 ) {
F_233 ( & V_63 -> V_56 -> V_57 ,
L_94
L_95 ) ;
V_40 = - V_89 ;
goto V_67;
}
if ( V_63 -> V_26 <= V_62 ) {
F_39 ( V_185 , V_63 , L_96 ,
L_97 ) ;
V_40 = - V_206 ;
goto V_67;
}
if ( ( V_177 & V_317 ) &&
( F_141 ( V_318 , & V_63 -> V_192 ) ||
( V_63 -> V_81 & V_289 ) ) ) {
V_40 = - V_319 ;
goto V_67;
}
F_23 ( V_63 ) ;
return 0 ;
V_67:
F_26 ( V_63 -> V_42 -> V_44 ) ;
V_316:
F_234 ( & V_63 -> V_34 -> V_35 ) ;
F_23 ( V_63 ) ;
return V_40 ;
}
static void F_235 ( struct V_74 * V_75 , T_7 V_177 )
{
struct V_1 * V_63 = F_230 ( V_75 ) ;
if ( V_63 ) {
F_234 ( & V_63 -> V_34 -> V_35 ) ;
F_26 ( V_63 -> V_42 -> V_44 ) ;
F_23 ( V_63 ) ;
}
}
static int F_236 ( struct V_315 * V_85 , struct V_320 * V_321 )
{
struct V_1 * V_63 ;
V_63 = F_230 ( V_85 -> V_86 ) ;
if ( ! V_63 )
return - V_206 ;
if ( ! V_63 -> V_42 ||
! V_63 -> V_42 -> V_322 ) {
F_23 ( V_63 ) ;
return - V_167 ;
}
V_63 -> V_42 -> V_322 ( V_63 -> V_34 , V_321 ) ;
V_321 -> V_323 = F_237 ( V_85 ) >> V_63 -> V_34 -> V_69 ;
F_23 ( V_63 ) ;
return 0 ;
}
static void
F_238 ( void )
{
#ifdef F_239
F_240 () ;
#endif
F_241 () ;
if ( V_324 != NULL ) {
F_242 ( V_324 ) ;
V_324 = NULL ;
}
F_243 () ;
F_244 () ;
if ( V_325 != NULL ) {
F_47 ( V_325 ) ;
V_325 = NULL ;
}
F_117 () ;
}
int F_245 ( struct V_1 * V_2 )
{
struct V_326 V_327 ;
struct V_328 V_329 ;
int V_40 ;
if ( ! V_330 )
return 0 ;
F_246 ( V_2 -> V_56 , & V_327 ) ;
memset ( & V_329 , 0 , sizeof( V_329 ) ) ;
V_329 . V_331 = V_327 . V_332 ;
V_329 . V_333 = sizeof( V_329 ) ;
V_40 = V_328 ( & V_329 ) ;
if ( V_40 == 0 || V_40 == 2 ) {
return V_329 . V_334 & 0x80 ;
} else {
F_119 ( V_60 , L_98 ,
V_327 . V_332 , V_40 ) ;
return 0 ;
}
}
static void F_247 ( void * V_19 , T_8 V_335 )
{
struct V_226 * V_56 = V_19 ;
int V_336 ;
V_336 = F_248 ( V_56 ) ;
if ( V_336 )
F_249 ( L_99 ,
F_35 ( & V_56 -> V_57 ) , V_336 ) ;
}
int F_250 ( struct V_226 * V_56 ,
struct V_337 * V_42 )
{
int V_336 ;
V_336 = F_251 ( V_56 ) ;
if ( V_336 ) {
F_152 ( V_60 , V_56 , L_1 ,
L_100
L_101 ) ;
return V_336 ;
}
V_56 -> V_338 = & F_156 ;
if ( ( F_252 ( V_56 , V_339 ) > 0 ) ||
( V_340 && F_253 ( F_35 ( & V_56 -> V_57 ) ) != 0 ) )
F_254 ( F_247 , V_56 ) ;
return 0 ;
}
void F_255 ( struct V_226 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_56 -> V_338 = NULL ;
V_2 = F_256 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_257 ( V_56 ) ;
return;
}
if ( F_258 ( V_249 , & V_2 -> V_192 ) &&
! F_141 ( V_258 , & V_2 -> V_192 ) ) {
F_23 ( V_2 ) ;
F_257 ( V_56 ) ;
return;
}
F_80 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_259 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
F_257 ( V_56 ) ;
}
int F_260 ( struct V_226 * V_56 ,
struct V_337 * V_45 )
{
struct V_337 * V_42 ;
struct V_1 * V_2 ;
int V_40 ;
F_261 ( V_56 , V_339 , 0 ) ;
V_2 = F_262 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
V_42 = V_45 ;
if ( V_2 -> V_81 & V_341 ) {
if ( ! V_236 ) {
F_249 ( L_102
L_103 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_259 ( V_2 ) ;
return - V_206 ;
}
V_42 = V_236 ;
}
if ( ! F_232 ( V_45 -> V_44 ) ) {
F_259 ( V_2 ) ;
return - V_167 ;
}
if ( ! F_232 ( V_42 -> V_44 ) ) {
F_26 ( V_45 -> V_44 ) ;
F_259 ( V_2 ) ;
return - V_167 ;
}
V_2 -> V_45 = V_45 ;
V_2 -> V_42 = V_42 ;
V_40 = V_42 -> V_342 ( V_2 ) ;
if ( V_40 ) {
F_249 ( L_104
L_105 ,
F_35 ( & V_56 -> V_57 ) , V_42 -> V_47 , V_40 ) ;
F_26 ( V_42 -> V_44 ) ;
F_26 ( V_45 -> V_44 ) ;
F_259 ( V_2 ) ;
return V_40 ;
}
F_80 ( V_2 , V_80 ) ;
if ( V_2 -> V_26 <= V_41 ) {
F_249 ( L_106
L_107 , F_35 ( & V_56 -> V_57 ) ) ;
V_40 = - V_206 ;
F_80 ( V_2 , V_27 ) ;
if ( V_2 -> V_34 )
F_19 ( V_2 -> V_34 ) ;
F_259 ( V_2 ) ;
} else
F_263 ( L_108 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_83 ( V_90 , F_81 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_264 ( struct V_226 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_343 , V_35 , V_40 ;
V_40 = 0 ;
V_2 = F_256 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_343 = V_2 -> V_34 -> V_85 ? 0 : - 1 ;
V_35 = F_265 ( & V_2 -> V_34 -> V_35 ) ;
if ( V_35 > V_343 ) {
if ( V_35 > 0 )
F_249 ( L_109
L_110 ,
F_35 ( & V_56 -> V_57 ) , V_35 ) ;
else
F_249 ( L_109
L_111 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_266 ( V_249 , & V_2 -> V_192 ) ;
F_23 ( V_2 ) ;
return - V_208 ;
}
}
if ( F_141 ( V_258 , & V_2 -> V_192 ) ) {
if ( F_258 ( V_249 , & V_2 -> V_192 ) ) {
F_23 ( V_2 ) ;
return - V_208 ;
} else
F_266 ( V_344 , & V_2 -> V_192 ) ;
} else
if ( F_141 ( V_249 , & V_2 -> V_192 ) ) {
F_23 ( V_2 ) ;
return - V_208 ;
}
if ( F_267 ( V_344 , & V_2 -> V_192 ) &&
! F_258 ( V_258 , & V_2 -> V_192 ) ) {
V_40 = F_268 ( V_2 -> V_34 -> V_85 ) ;
if ( V_40 != 0 )
goto V_345;
F_75 ( V_2 ) ;
V_40 = F_193 ( V_266 ,
F_52 ( V_2 ) ) ;
if ( V_40 != 0 )
goto V_345;
}
F_124 ( V_249 , & V_2 -> V_192 ) ;
F_80 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_259 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
return 0 ;
V_345:
F_266 ( V_344 , & V_2 -> V_192 ) ;
F_266 ( V_258 , & V_2 -> V_192 ) ;
F_266 ( V_249 , & V_2 -> V_192 ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
F_269 ( & V_2 -> V_56 -> V_57 , L_112
L_113 ) ;
F_39 ( V_60 , V_2 , L_1 , L_114 ) ;
F_212 ( V_2 , NULL , V_346 ) ;
if ( V_2 -> V_26 < V_62 )
return 0 ;
F_196 (cqr, &device->ccw_queue, devlist)
if ( ( V_99 -> V_201 == V_202 ) ||
( V_99 -> V_201 == V_203 ) ) {
V_99 -> V_201 = V_228 ;
V_99 -> V_198 ++ ;
}
F_179 ( V_2 , V_261 ) ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
return 1 ;
}
int F_270 ( struct V_1 * V_2 )
{
F_233 ( & V_2 -> V_56 -> V_57 , L_115
L_116 ) ;
F_39 ( V_60 , V_2 , L_1 , L_117 ) ;
F_147 ( V_2 , V_261 ) ;
if ( V_2 -> V_246 & V_262 ) {
F_147 ( V_2 , V_262 ) ;
F_79 ( V_2 ) ;
return 1 ;
}
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
return 1 ;
}
int F_271 ( struct V_226 * V_56 , int V_347 )
{
struct V_1 * V_2 ;
int V_336 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return 0 ;
V_336 = 0 ;
switch ( V_347 ) {
case V_348 :
case V_349 :
case V_350 :
V_2 -> V_216 . V_217 = 0 ;
V_2 -> V_216 . V_220 = 0 ;
V_2 -> V_216 . V_221 = 0 ;
V_336 = F_144 ( V_2 ) ;
break;
case V_351 :
V_336 = 1 ;
if ( V_2 -> V_216 . V_217 )
V_336 = F_270 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_336 ;
}
void F_272 ( struct V_226 * V_56 , int * V_352 )
{
int V_353 ;
T_9 V_354 , V_355 ;
struct V_1 * V_2 ;
V_2 = F_153 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
for ( V_353 = 0 ; V_353 < 8 ; V_353 ++ ) {
V_355 = 0x80 >> V_353 ;
if ( V_352 [ V_353 ] & V_356 ) {
V_354 = V_2 -> V_216 . V_217 ;
V_2 -> V_216 . V_217 &= ~ V_355 ;
V_2 -> V_216 . V_220 &= ~ V_355 ;
V_2 -> V_216 . V_221 &= ~ V_355 ;
if ( V_354 && ! V_2 -> V_216 . V_217 ) {
F_269 ( & V_2 -> V_56 -> V_57 ,
L_118
L_113 ) ;
F_39 ( V_60 , V_2 ,
L_1 , L_119 ) ;
F_212 ( V_2 , NULL , V_346 ) ;
F_179 ( V_2 ,
V_261 ) ;
}
}
if ( V_352 [ V_353 ] & V_357 ) {
V_2 -> V_216 . V_217 &= ~ V_355 ;
V_2 -> V_216 . V_220 &= ~ V_355 ;
V_2 -> V_216 . V_221 &= ~ V_355 ;
V_2 -> V_216 . V_222 |= V_355 ;
F_75 ( V_2 ) ;
}
if ( V_352 [ V_353 ] & V_358 ) {
if ( ! ( V_2 -> V_216 . V_217 & V_355 ) &&
! ( V_2 -> V_216 . V_222 & V_355 ) ) {
V_2 -> V_216 . V_222 |= V_355 ;
F_75 ( V_2 ) ;
}
F_39 ( V_60 , V_2 , L_1 ,
L_120 ) ;
if ( V_2 -> V_42 -> V_97 )
V_2 -> V_42 -> V_97 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
int F_273 ( struct V_1 * V_2 , T_9 V_215 )
{
if ( ! V_2 -> V_216 . V_217 && V_215 ) {
V_2 -> V_216 . V_217 = V_215 ;
F_270 ( V_2 ) ;
} else
V_2 -> V_216 . V_217 |= V_215 ;
return 0 ;
}
int F_274 ( struct V_226 * V_56 )
{
struct V_1 * V_2 = F_256 ( V_56 ) ;
struct V_102 V_359 ;
struct V_98 * V_99 , * V_252 ;
struct V_98 * V_275 ;
int V_40 ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
F_124 ( V_360 , & V_2 -> V_192 ) ;
if ( V_2 -> V_42 -> V_361 )
V_40 = V_2 -> V_42 -> V_361 ( V_2 ) ;
F_179 ( V_2 , V_362 ) ;
F_12 ( & V_359 ) ;
F_173 ( F_146 ( V_56 ) ) ;
V_40 = 0 ;
F_174 (cqr, n, &device->ccw_queue, devlist) {
if ( V_99 -> V_201 == V_202 ) {
V_40 = V_2 -> V_42 -> V_259 ( V_99 ) ;
if ( V_40 ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_121
L_122 , V_99 ) ;
F_175 ( F_146 ( V_56 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
}
F_165 ( & V_99 -> V_245 , & V_359 ) ;
}
F_175 ( F_146 ( V_56 ) ) ;
F_174 (cqr, n, &freeze_queue, devlist) {
F_83 ( V_243 ,
( V_99 -> V_201 != V_203 ) ) ;
if ( V_99 -> V_201 == V_242 )
V_99 -> V_201 = V_228 ;
if ( F_216 ( V_99 ) )
continue;
F_168 ( & V_99 -> V_245 ) ;
while ( V_99 -> V_275 != NULL ) {
V_275 = V_99 -> V_275 ;
F_275 ( & V_99 -> V_278 ) ;
F_276 ( V_99 , V_99 -> V_363 ) ;
V_99 = V_275 ;
}
if ( V_99 -> V_34 )
F_168 ( & V_99 -> V_278 ) ;
V_99 -> V_34 -> V_63 -> V_42 -> V_295 (
V_99 , (struct V_100 * ) V_99 -> V_254 ) ;
}
if ( ! F_53 ( & V_359 ) ) {
F_173 ( F_146 ( V_56 ) ) ;
F_277 ( & V_359 , & V_2 -> V_15 ) ;
F_175 ( F_146 ( V_56 ) ) ;
}
F_23 ( V_2 ) ;
return V_40 ;
}
int F_278 ( struct V_226 * V_56 )
{
struct V_1 * V_2 = F_256 ( V_56 ) ;
int V_40 = 0 ;
if ( F_30 ( V_2 ) )
return F_104 ( V_2 ) ;
F_147 ( V_2 ,
( V_362 | V_262 ) ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_42 -> V_95 && ! ( V_2 -> V_246 ) )
V_40 = V_2 -> V_42 -> V_95 ( V_2 ) ;
if ( V_40 || V_2 -> V_246 )
V_2 -> V_246 |= V_262 ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
F_266 ( V_360 , & V_2 -> V_192 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_98 * F_279 ( struct V_1 * V_2 ,
void * V_364 ,
int V_365 ,
int V_186 )
{
struct V_98 * V_99 ;
struct V_189 * V_194 ;
unsigned long * V_366 ;
V_99 = F_125 ( V_186 , 1 , V_365 , V_2 ) ;
if ( F_30 ( V_99 ) ) {
F_138 ( & V_2 -> V_56 -> V_57 ,
L_63
L_64 , L_123 ) ;
return V_99 ;
}
V_194 = V_99 -> V_190 ;
V_194 -> V_367 = V_368 ;
if ( F_280 ( V_364 , V_365 ) ) {
V_366 = ( unsigned long * ) ( V_99 -> V_19 ) ;
V_194 -> V_369 = ( V_370 ) ( V_371 ) V_366 ;
V_194 -> V_192 = V_372 ;
V_366 = F_281 ( V_366 , V_364 , V_365 ) ;
} else {
V_194 -> V_369 = ( V_370 ) ( V_371 ) V_364 ;
V_194 -> V_192 = 0 ;
}
V_194 -> V_373 = V_365 ;
V_99 -> V_109 = V_2 ;
V_99 -> V_363 = V_2 ;
V_99 -> V_225 = 10 * V_260 ;
V_99 -> V_198 = 256 ;
V_99 -> V_149 = F_137 () ;
V_99 -> V_201 = V_271 ;
return V_99 ;
}
int F_282 ( struct V_1 * V_2 , int V_186 ,
void * V_364 , int V_365 )
{
int V_336 ;
struct V_98 * V_99 ;
V_99 = F_279 ( V_2 , V_364 , V_365 ,
V_186 ) ;
if ( F_30 ( V_99 ) )
return F_104 ( V_99 ) ;
V_336 = F_198 ( V_99 ) ;
F_132 ( V_99 , V_99 -> V_363 ) ;
return V_336 ;
}
char * F_283 ( struct V_229 * V_229 )
{
struct V_374 * V_374 = NULL ;
char * V_375 = NULL ;
if ( F_284 ( & V_229 -> V_233 ) && ( V_229 -> V_233 . V_376 . V_377 == 0x01 ) ) {
if ( V_229 -> V_233 . V_376 . V_378 )
V_374 = F_285 ( (struct V_378 * ) ( unsigned long )
V_229 -> V_233 . V_376 . V_378 ) ;
if ( V_374 && V_374 -> V_379 == 64 && V_374 -> V_192 )
switch ( V_374 -> V_192 & 0x07 ) {
case 1 :
V_375 = V_374 -> V_380 . V_381 . V_375 ;
break;
case 2 :
V_375 = V_374 -> V_380 . V_382 . V_375 ;
break;
default:
break;
}
} else if ( V_229 -> V_383 . V_384 . V_385 . V_386 ) {
V_375 = V_229 -> V_387 ;
}
return V_375 ;
}
void F_286 ( struct V_226 * V_56 )
{
struct V_1 * V_2 ;
V_2 = F_256 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
F_75 ( V_2 ) ;
F_83 ( V_266 , F_52 ( V_2 ) ) ;
}
static int T_10 F_287 ( void )
{
int V_40 ;
F_288 ( & V_90 ) ;
F_288 ( & V_243 ) ;
F_288 ( & V_268 ) ;
F_288 ( & V_266 ) ;
V_325 = F_36 ( L_33 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_325 == NULL ) {
V_40 = - V_4 ;
goto V_388;
}
F_37 ( V_325 , & V_59 ) ;
F_38 ( V_325 , V_60 ) ;
F_119 ( V_61 , L_1 , L_2 ) ;
V_236 = NULL ;
F_118 () ;
V_40 = F_289 () ;
if ( V_40 )
goto V_388;
V_40 = F_290 () ;
if ( V_40 )
goto V_388;
V_40 = F_291 () ;
if ( V_40 )
goto V_388;
V_40 = F_292 () ;
if ( V_40 )
goto V_388;
#ifdef F_239
V_40 = F_293 () ;
if ( V_40 )
goto V_388;
#endif
return 0 ;
V_388:
F_294 ( L_124 ) ;
F_238 () ;
return V_40 ;
}
