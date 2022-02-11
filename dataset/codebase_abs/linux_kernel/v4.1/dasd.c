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
if ( V_2 -> V_42 -> V_63 ) {
V_40 = V_2 -> V_42 -> V_63 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_2 -> V_34 ) {
F_41 ( & V_2 -> V_34 -> V_30 ) ;
F_42 ( V_2 -> V_34 -> V_50 ) ;
F_43 ( V_2 -> V_34 ) ;
F_44 ( V_2 -> V_34 ) ;
}
V_40 = F_45 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_46 ( V_2 ) ;
F_41 ( & V_2 -> V_30 ) ;
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
if ( V_34 -> V_64 -> V_42 -> V_65 != NULL )
V_40 = V_34 -> V_64 -> V_42 -> V_65 ( V_34 ) ;
if ( V_40 ) {
if ( V_40 != - V_66 ) {
V_2 -> V_26 = V_67 ;
goto V_68;
}
return V_40 ;
}
F_49 ( V_34 ) ;
F_50 ( V_34 -> V_51 ,
V_34 -> V_69 << V_34 -> V_70 ) ;
V_2 -> V_26 = V_71 ;
V_40 = F_51 ( V_34 ) ;
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
V_2 -> V_26 = V_71 ;
return V_40 ;
}
F_56 ( V_34 ) ;
F_57 ( V_34 ) ;
V_34 -> V_69 = 0 ;
V_34 -> V_73 = 0 ;
V_34 -> V_70 = 0 ;
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
V_2 -> V_26 = V_71 ;
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
V_2 -> V_28 >= V_71 )
V_40 = F_48 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_67 &&
V_2 -> V_28 > V_67 )
V_40 = - V_89 ;
if ( ! V_40 &&
V_2 -> V_26 == V_71 &&
V_2 -> V_28 >= V_80 )
V_40 = F_59 ( V_2 ) ;
return V_40 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_80 &&
V_2 -> V_28 <= V_71 )
V_40 = F_67 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_71 &&
V_2 -> V_28 <= V_62 )
V_40 = F_54 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_67 &&
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
if ( V_40 == - V_66 )
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
if ( ! F_77 ( & V_2 -> V_20 ) )
F_23 ( V_2 ) ;
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
if ( ! F_77 ( & V_2 -> V_24 ) )
F_23 ( V_2 ) ;
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
if ( ! F_77 ( & V_2 -> V_22 ) )
F_23 ( V_2 ) ;
}
void F_80 ( struct V_1 * V_2 , int V_28 )
{
F_21 ( V_2 ) ;
F_73 ( & V_2 -> V_29 ) ;
if ( V_96 && V_28 > V_71 )
V_28 = V_71 ;
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
F_86 ( & V_105 . V_31 ) ;
if ( V_105 . V_19 ) {
V_105 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_87 ( V_101 ) == V_107 )
V_105 . V_19 -> V_108 [ V_104 ] ++ ;
}
F_88 ( & V_105 . V_31 ) ;
F_86 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 ) {
V_34 -> V_30 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_87 ( V_101 ) == V_107 )
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
F_86 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 ) {
V_2 -> V_30 . V_19 -> V_106 [ V_104 ] ++ ;
if ( F_87 ( V_101 ) == V_107 )
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
F_86 ( & V_105 . V_31 ) ;
if ( V_105 . V_19 ) {
F_89 ( V_105 . V_19 ,
V_99 -> V_109 != V_34 -> V_64 ,
V_99 -> V_153 == 1 ,
F_87 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
}
F_88 ( & V_105 . V_31 ) ;
F_86 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
F_89 ( V_34 -> V_30 . V_19 ,
V_99 -> V_109 != V_34 -> V_64 ,
V_99 -> V_153 == 1 ,
F_87 ( V_101 ) == V_107 ,
V_114 , V_115 , V_116 ,
V_117 , V_118 ,
V_119 , V_120 ,
V_121 ) ;
F_88 ( & V_34 -> V_30 . V_31 ) ;
F_86 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 )
F_89 ( V_2 -> V_30 . V_19 ,
V_99 -> V_109 != V_34 -> V_64 ,
V_99 -> V_153 == 1 ,
F_87 ( V_101 ) == V_107 ,
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
void F_97 ( struct V_154 * V_30 )
{
F_95 ( & V_30 -> V_31 ) ;
F_5 ( V_30 -> V_19 ) ;
V_30 -> V_19 = NULL ;
F_96 ( & V_30 -> V_31 ) ;
}
char * F_98 ( const char T_1 * V_156 , T_2 V_157 )
{
char * V_158 ;
V_158 = F_99 ( V_157 + 1 ) ;
if ( V_158 == NULL )
return F_3 ( - V_4 ) ;
if ( F_100 ( V_158 , V_156 , V_157 ) != 0 ) {
F_101 ( V_158 ) ;
return F_3 ( - V_159 ) ;
}
if ( V_158 [ V_157 - 1 ] == '\n' )
V_158 [ V_157 - 1 ] = 0 ;
else
V_158 [ V_157 ] = 0 ;
return V_158 ;
}
static T_3 F_102 ( struct V_160 * V_160 ,
const char T_1 * V_156 ,
T_2 V_157 , T_4 * V_161 )
{
char * V_158 , * V_162 ;
int V_40 ;
struct V_163 * V_164 = (struct V_163 * ) V_160 -> V_165 ;
struct V_154 * V_166 = V_164 -> V_32 ;
if ( V_157 > 65536 )
V_157 = 65536 ;
V_158 = F_98 ( V_156 , V_157 ) ;
if ( F_30 ( V_158 ) )
return F_103 ( V_158 ) ;
V_162 = F_104 ( V_158 ) ;
V_40 = V_157 ;
if ( strncmp ( V_162 , L_4 , 5 ) == 0 ) {
F_94 ( V_166 ) ;
} else if ( strncmp ( V_162 , L_5 , 2 ) == 0 ) {
V_40 = F_34 ( V_166 ) ;
if ( V_40 )
goto V_68;
V_40 = V_157 ;
if ( V_166 == & V_105 ) {
F_94 ( V_166 ) ;
V_54 = V_167 ;
}
} else if ( strncmp ( V_162 , L_6 , 3 ) == 0 ) {
if ( V_166 == & V_105 )
V_54 = V_168 ;
F_97 ( V_166 ) ;
} else
V_40 = - V_169 ;
V_68:
F_101 ( V_158 ) ;
return V_40 ;
}
static void F_105 ( struct V_163 * V_164 , unsigned int * V_170 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < 32 ; V_171 ++ )
F_106 ( V_164 , L_7 , V_170 [ V_171 ] ) ;
F_107 ( V_164 , '\n' ) ;
}
static void F_108 ( struct V_163 * V_164 ,
struct V_110 * V_19 )
{
F_106 ( V_164 , L_8 ,
V_19 -> V_124 . V_172 , V_19 -> V_124 . V_173 ) ;
F_106 ( V_164 , L_9 , V_19 -> V_122 ) ;
F_106 ( V_164 , L_10 , V_19 -> V_125 ) ;
F_106 ( V_164 , L_11 , V_19 -> V_126 ) ;
F_106 ( V_164 , L_12 , V_19 -> V_127 ) ;
F_109 ( V_164 , L_13 ) ;
F_105 ( V_164 , V_19 -> V_128 ) ;
F_109 ( V_164 , L_14 ) ;
F_105 ( V_164 , V_19 -> V_129 ) ;
F_109 ( V_164 , L_15 ) ;
F_105 ( V_164 , V_19 -> V_130 ) ;
F_109 ( V_164 , L_16 ) ;
F_105 ( V_164 , V_19 -> V_131 ) ;
F_109 ( V_164 , L_17 ) ;
F_105 ( V_164 , V_19 -> V_132 ) ;
F_109 ( V_164 , L_18 ) ;
F_105 ( V_164 , V_19 -> V_133 ) ;
F_109 ( V_164 , L_19 ) ;
F_105 ( V_164 , V_19 -> V_134 ) ;
F_109 ( V_164 , L_20 ) ;
F_105 ( V_164 , V_19 -> V_106 ) ;
F_106 ( V_164 , L_21 , V_19 -> V_135 ) ;
F_106 ( V_164 , L_22 , V_19 -> V_136 ) ;
F_106 ( V_164 , L_23 , V_19 -> V_137 ) ;
F_106 ( V_164 , L_24 , V_19 -> V_138 ) ;
F_109 ( V_164 , L_25 ) ;
F_105 ( V_164 , V_19 -> V_139 ) ;
F_109 ( V_164 , L_26 ) ;
F_105 ( V_164 , V_19 -> V_140 ) ;
F_109 ( V_164 , L_27 ) ;
F_105 ( V_164 , V_19 -> V_141 ) ;
F_109 ( V_164 , L_28 ) ;
F_105 ( V_164 , V_19 -> V_142 ) ;
F_109 ( V_164 , L_29 ) ;
F_105 ( V_164 , V_19 -> V_143 ) ;
F_109 ( V_164 , L_30 ) ;
F_105 ( V_164 , V_19 -> V_108 ) ;
}
static int F_110 ( struct V_163 * V_164 , void * V_174 )
{
struct V_154 * V_30 ;
struct V_110 * V_19 ;
V_30 = V_164 -> V_32 ;
F_95 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_96 ( & V_30 -> V_31 ) ;
F_109 ( V_164 , L_31 ) ;
return 0 ;
}
F_108 ( V_164 , V_19 ) ;
F_96 ( & V_30 -> V_31 ) ;
return 0 ;
}
static int F_111 ( struct V_175 * V_175 , struct V_160 * V_160 )
{
struct V_154 * V_30 = V_175 -> V_176 ;
return F_112 ( V_160 , F_110 , V_30 ) ;
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
V_49 = F_113 ( L_32 , V_177 , V_48 ,
V_30 , & V_181 ) ;
if ( V_49 && ! F_30 ( V_49 ) )
V_30 -> V_46 = V_49 ;
return;
}
static void F_41 ( struct V_154 * V_30 )
{
F_97 ( V_30 ) ;
F_42 ( V_30 -> V_46 ) ;
V_30 -> V_46 = NULL ;
}
static void F_114 ( void )
{
V_54 = V_168 ;
F_41 ( & V_105 ) ;
F_42 ( V_182 ) ;
F_42 ( V_53 ) ;
}
static void F_115 ( void )
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
F_116 ( V_183 , L_1 ,
L_35 ) ;
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
int F_117 ( struct V_163 * V_164 , void * V_174 )
{
F_109 ( V_164 , L_36 ) ;
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
struct V_98 * F_118 ( int V_184 , int V_185 ,
int V_186 ,
struct V_1 * V_2 )
{
struct V_98 * V_99 ;
F_119 ( V_186 > V_9 ||
( V_185 * sizeof( struct V_187 ) ) > V_9 ) ;
V_99 = F_2 ( sizeof( struct V_98 ) , V_3 ) ;
if ( V_99 == NULL )
return F_3 ( - V_4 ) ;
V_99 -> V_188 = NULL ;
if ( V_185 > 0 ) {
V_99 -> V_188 = F_120 ( V_185 , sizeof( struct V_187 ) ,
V_3 | V_6 ) ;
if ( V_99 -> V_188 == NULL ) {
F_5 ( V_99 ) ;
return F_3 ( - V_4 ) ;
}
}
V_99 -> V_19 = NULL ;
if ( V_186 > 0 ) {
V_99 -> V_19 = F_2 ( V_186 , V_3 | V_6 ) ;
if ( V_99 -> V_19 == NULL ) {
F_5 ( V_99 -> V_188 ) ;
F_5 ( V_99 ) ;
return F_3 ( - V_4 ) ;
}
}
V_99 -> V_184 = V_184 ;
F_121 ( V_189 , & V_99 -> V_190 ) ;
F_21 ( V_2 ) ;
return V_99 ;
}
struct V_98 * F_122 ( int V_184 , int V_185 ,
int V_186 ,
struct V_1 * V_2 )
{
unsigned long V_190 ;
struct V_98 * V_99 ;
char * V_19 ;
int V_191 ;
V_191 = ( sizeof( struct V_98 ) + 7L ) & - 8L ;
if ( V_185 > 0 )
V_191 += V_185 * sizeof( struct V_187 ) ;
if ( V_186 > 0 )
V_191 += V_186 ;
F_123 ( & V_2 -> V_11 , V_190 ) ;
V_99 = (struct V_98 * )
F_124 ( & V_2 -> V_8 , V_191 ) ;
F_125 ( & V_2 -> V_11 , V_190 ) ;
if ( V_99 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_99 , 0 , sizeof( struct V_98 ) ) ;
V_19 = ( char * ) V_99 + ( ( sizeof( struct V_98 ) + 7L ) & - 8L ) ;
V_99 -> V_188 = NULL ;
if ( V_185 > 0 ) {
V_99 -> V_188 = (struct V_187 * ) V_19 ;
V_19 += V_185 * sizeof( struct V_187 ) ;
memset ( V_99 -> V_188 , 0 , V_185 * sizeof( struct V_187 ) ) ;
}
V_99 -> V_19 = NULL ;
if ( V_186 > 0 ) {
V_99 -> V_19 = V_19 ;
memset ( V_99 -> V_19 , 0 , V_186 ) ;
}
V_99 -> V_184 = V_184 ;
F_121 ( V_189 , & V_99 -> V_190 ) ;
F_21 ( V_2 ) ;
return V_99 ;
}
void F_126 ( struct V_98 * V_99 , struct V_1 * V_2 )
{
struct V_187 * V_192 ;
V_192 = V_99 -> V_188 ;
do {
F_127 ( V_192 ) ;
} while ( V_192 ++ -> V_190 & ( V_193 | V_194 ) );
F_5 ( V_99 -> V_188 ) ;
F_5 ( V_99 -> V_19 ) ;
F_5 ( V_99 ) ;
F_23 ( V_2 ) ;
}
void F_128 ( struct V_98 * V_99 , struct V_1 * V_2 )
{
unsigned long V_190 ;
F_123 ( & V_2 -> V_11 , V_190 ) ;
F_129 ( & V_2 -> V_8 , V_99 ) ;
F_125 ( & V_2 -> V_11 , V_190 ) ;
F_23 ( V_2 ) ;
}
static inline int F_130 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
if ( V_99 == NULL )
return - V_169 ;
V_2 = V_99 -> V_109 ;
if ( strncmp ( ( char * ) & V_99 -> V_184 , V_2 -> V_42 -> V_195 , 4 ) ) {
F_39 ( V_60 , V_2 ,
L_37
L_38 ,
V_99 -> V_184 ,
* ( unsigned int * ) V_2 -> V_42 -> V_47 ) ;
return - V_169 ;
}
return 0 ;
}
int F_131 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_196 , V_40 ;
char V_197 [ V_198 ] ;
V_40 = F_130 ( V_99 ) ;
if ( V_40 )
return V_40 ;
V_196 = 0 ;
V_2 = (struct V_1 * ) V_99 -> V_109 ;
while ( ( V_196 < 5 ) && ( V_99 -> V_199 == V_200 ) ) {
V_40 = F_132 ( V_2 -> V_56 , ( long ) V_99 ) ;
switch ( V_40 ) {
case 0 :
V_99 -> V_199 = V_201 ;
V_99 -> V_151 = F_133 () ;
V_99 -> V_202 = 0 ;
F_39 ( V_203 , V_2 ,
L_39 ,
V_99 ) ;
break;
case - V_204 :
F_39 ( V_183 , V_2 , L_1 ,
L_40 ) ;
break;
case - V_205 :
F_39 ( V_183 , V_2 , L_1 ,
L_41 ) ;
break;
case - V_169 :
V_99 -> V_199 = V_206 ;
V_99 -> V_151 = F_133 () ;
V_99 -> V_202 = 0 ;
V_99 -> V_196 = - 1 ;
F_39 ( V_183 , V_2 , L_1 ,
L_42 ) ;
V_40 = 0 ;
break;
case - V_207 :
F_39 ( V_183 , V_2 , L_1 ,
L_43 ) ;
break;
default:
snprintf ( V_197 , V_198 , L_44 , V_40 ) ;
F_134 ( & V_2 -> V_56 -> V_57 , L_45
L_46 , V_197 ) ;
F_135 () ;
break;
}
V_196 ++ ;
}
F_75 ( V_2 ) ;
return V_40 ;
}
int F_136 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
char V_197 [ V_198 ] ;
V_40 = F_130 ( V_99 ) ;
if ( V_40 ) {
V_99 -> V_208 = V_40 ;
return V_40 ;
}
V_2 = (struct V_1 * ) V_99 -> V_109 ;
if ( ( ( V_99 -> V_34 &&
F_137 ( V_209 , & V_99 -> V_34 -> V_64 -> V_190 ) ) ||
F_137 ( V_209 , & V_2 -> V_190 ) ) &&
! F_137 ( V_210 , & V_99 -> V_190 ) ) {
F_39 ( V_203 , V_2 , L_47
L_48 , V_99 ) ;
V_99 -> V_199 = V_211 ;
V_99 -> V_208 = - V_89 ;
return - V_89 ;
}
if ( V_99 -> V_196 < 0 ) {
sprintf ( V_197 , L_49 , V_99 ) ;
F_134 ( & V_2 -> V_56 -> V_57 , L_50
L_51 , V_197 ) ;
V_99 -> V_199 = V_211 ;
return - V_205 ;
}
V_99 -> V_150 = F_133 () ;
V_99 -> V_202 = V_212 ;
V_99 -> V_196 -- ;
if ( ! F_137 ( V_213 , & V_99 -> V_190 ) ) {
V_99 -> V_214 &= V_2 -> V_215 . V_216 ;
if ( ! V_99 -> V_214 )
V_99 -> V_214 = V_2 -> V_215 . V_216 ;
}
if ( V_99 -> V_153 == 1 ) {
V_40 = F_138 ( V_2 -> V_56 , V_99 -> V_188 ,
( long ) V_99 , V_99 -> V_214 ) ;
} else {
V_40 = F_139 ( V_2 -> V_56 , V_99 -> V_188 ,
( long ) V_99 , V_99 -> V_214 , 0 ) ;
}
switch ( V_40 ) {
case 0 :
V_99 -> V_199 = V_200 ;
break;
case - V_207 :
F_39 ( V_60 , V_2 , L_1 ,
L_52 ) ;
break;
case - V_217 :
F_39 ( V_60 , V_2 , L_1 ,
L_53 ) ;
break;
case - V_218 :
if ( F_137 ( V_213 , & V_99 -> V_190 ) ) {
F_39 ( V_60 , V_2 ,
L_54 ,
V_99 -> V_214 ) ;
} else if ( V_99 -> V_214 != V_2 -> V_215 . V_216 ) {
V_99 -> V_214 = V_2 -> V_215 . V_216 ;
F_39 ( V_203 , V_2 , L_1 ,
L_55
L_56 ) ;
} else {
F_39 ( V_60 , V_2 , L_1 ,
L_57
L_58 ) ;
F_140 ( V_2 ) ;
V_2 -> V_215 . V_216 = 0 ;
V_2 -> V_215 . V_219 = 0 ;
V_2 -> V_215 . V_220 = 0 ;
V_2 -> V_215 . V_221 =
F_141 ( V_2 -> V_56 ) ;
}
break;
case - V_204 :
F_39 ( V_60 , V_2 , L_1 ,
L_59 ) ;
break;
case - V_205 :
F_39 ( V_60 , V_2 , L_1 ,
L_60 ) ;
break;
case - V_169 :
F_39 ( V_60 , V_2 , L_1 ,
L_61
L_62 ) ;
break;
default:
snprintf ( V_197 , V_198 , L_63 , V_40 ) ;
F_134 ( & V_2 -> V_56 -> V_57 ,
L_64
L_65 , V_197 ) ;
F_135 () ;
break;
}
V_99 -> V_208 = V_40 ;
return V_40 ;
}
static void V_18 ( unsigned long V_222 )
{
unsigned long V_190 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_222 ;
F_123 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
F_143 ( V_2 , V_223 ) ;
F_125 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
F_75 ( V_2 ) ;
}
void F_144 ( struct V_1 * V_2 , int V_224 )
{
if ( V_224 == 0 )
F_145 ( & V_2 -> V_16 ) ;
else
F_146 ( & V_2 -> V_16 , V_212 + V_224 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_16 ) ;
}
static void F_147 ( struct V_225 * V_56 ,
unsigned long V_226 )
{
struct V_98 * V_99 ;
struct V_1 * V_2 ;
if ( ! V_226 )
return;
V_99 = (struct V_98 * ) V_226 ;
if ( V_99 -> V_199 != V_200 ) {
F_148 ( V_203 , V_56 ,
L_66
L_67 , V_99 -> V_199 ) ;
return;
}
V_2 = F_149 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_148 ( V_203 , V_56 , L_1 ,
L_68 ) ;
return;
}
if ( ! V_99 -> V_109 ||
V_2 != V_99 -> V_109 ||
strncmp ( V_99 -> V_109 -> V_42 -> V_195 ,
( char * ) & V_99 -> V_184 , 4 ) ) {
F_148 ( V_203 , V_56 , L_1 ,
L_69 ) ;
F_23 ( V_2 ) ;
return;
}
V_99 -> V_199 = V_227 ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_150 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_143 ( V_2 , V_223 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
}
void F_152 ( struct V_225 * V_56 , unsigned long V_226 ,
struct V_228 * V_228 )
{
struct V_98 * V_99 , * V_229 ;
struct V_1 * V_2 ;
unsigned long long V_230 ;
int V_224 ;
if ( F_30 ( V_228 ) ) {
switch ( F_103 ( V_228 ) ) {
case - V_205 :
break;
case - V_217 :
F_148 ( V_60 , V_56 , L_70
L_71 , V_231 ) ;
break;
default:
F_148 ( V_60 , V_56 , L_70
L_72 , V_231 ,
F_103 ( V_228 ) ) ;
}
F_147 ( V_56 , V_226 ) ;
return;
}
V_230 = F_133 () ;
V_99 = (struct V_98 * ) V_226 ;
if ( ! V_99 ||
! ( F_153 ( & V_228 -> V_232 ) == ( V_233 | V_234 ) &&
F_154 ( & V_228 -> V_232 ) == 0 ) ) {
if ( V_99 )
memcpy ( & V_99 -> V_228 , V_228 , sizeof( * V_228 ) ) ;
V_2 = F_149 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_42 == V_235 ) {
F_23 ( V_2 ) ;
return;
}
V_2 -> V_42 -> V_236 ( V_2 , V_228 , L_73 ) ;
if ( V_2 -> V_81 & V_237 )
V_2 -> V_42 -> V_238 ( V_2 , V_99 , V_228 ) ;
V_2 -> V_42 -> V_239 ( V_2 , V_99 , V_228 ) ;
F_23 ( V_2 ) ;
}
if ( F_153 ( & V_228 -> V_232 ) & V_240 ) {
V_2 = F_149 ( V_56 ) ;
V_2 -> V_42 -> V_241 ( V_2 , V_228 -> V_242 . V_243 . V_244 ) ;
F_23 ( V_2 ) ;
}
if ( ! V_99 )
return;
V_2 = (struct V_1 * ) V_99 -> V_109 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_42 -> V_195 , ( char * ) & V_99 -> V_184 , 4 ) ) {
F_148 ( V_203 , V_56 , L_1 ,
L_69 ) ;
return;
}
if ( V_99 -> V_199 == V_201 &&
F_155 ( & V_228 -> V_232 ) & V_245 ) {
V_99 -> V_199 = V_206 ;
F_46 ( V_2 ) ;
F_71 ( & V_246 ) ;
F_75 ( V_2 ) ;
return;
}
if ( V_99 -> V_199 != V_200 ) {
F_39 ( V_203 , V_2 , L_74
L_75 , F_35 ( & V_56 -> V_57 ) , V_99 -> V_199 ) ;
return;
}
V_229 = NULL ;
V_224 = 0 ;
if ( F_153 ( & V_228 -> V_232 ) == ( V_233 | V_234 ) &&
F_154 ( & V_228 -> V_232 ) == 0 ) {
V_99 -> V_199 = V_247 ;
V_99 -> V_151 = V_230 ;
if ( V_99 -> V_248 . V_229 != & V_2 -> V_15 ) {
V_229 = F_156 ( V_99 -> V_248 . V_229 ,
struct V_98 , V_248 ) ;
}
} else {
if ( ! F_137 ( V_189 , & V_99 -> V_190 ) &&
V_99 -> V_196 > 0 ) {
if ( V_99 -> V_214 == V_2 -> V_215 . V_216 )
F_39 ( V_203 , V_2 ,
L_76
L_77 ,
V_99 -> V_196 ) ;
if ( ! F_137 ( V_213 , & V_99 -> V_190 ) )
V_99 -> V_214 = V_2 -> V_215 . V_216 ;
V_99 -> V_199 = V_227 ;
V_229 = V_99 ;
} else
V_99 -> V_199 = V_211 ;
}
if ( V_229 && ( V_229 -> V_199 == V_227 ) &&
( ! V_2 -> V_249 ) ) {
if ( V_2 -> V_42 -> V_250 ( V_229 ) == 0 )
V_224 = V_229 -> V_224 ;
}
if ( V_224 != 0 )
F_144 ( V_2 , V_224 ) ;
else
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
}
enum V_251 F_157 ( struct V_225 * V_56 , struct V_228 * V_228 )
{
struct V_1 * V_2 ;
V_2 = F_149 ( V_56 ) ;
if ( F_30 ( V_2 ) )
goto V_68;
if ( F_137 ( V_252 , & V_2 -> V_190 ) ||
V_2 -> V_26 != V_2 -> V_28 ||
! V_2 -> V_42 -> V_239 ) {
F_23 ( V_2 ) ;
goto V_68;
}
if ( V_2 -> V_42 -> V_236 )
V_2 -> V_42 -> V_236 ( V_2 , V_228 , L_78 ) ;
V_2 -> V_42 -> V_239 ( V_2 , NULL , V_228 ) ;
F_23 ( V_2 ) ;
V_68:
return V_253 ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_98 * V_254 )
{
struct V_102 * V_103 , * V_255 ;
struct V_98 * V_99 ;
if ( ! V_254 -> V_34 )
return;
F_159 (l, n, &device->ccw_queue) {
V_99 = F_156 ( V_103 , struct V_98 , V_248 ) ;
if ( V_99 -> V_199 == V_227 &&
V_254 -> V_34 == V_99 -> V_34 ) {
V_99 -> V_199 = V_206 ;
}
}
}
static void F_160 ( struct V_1 * V_2 ,
struct V_102 * V_256 )
{
struct V_102 * V_103 , * V_255 ;
struct V_98 * V_99 ;
F_159 (l, n, &device->ccw_queue) {
V_99 = F_156 ( V_103 , struct V_98 , V_248 ) ;
if ( V_99 -> V_199 == V_227 ||
V_99 -> V_199 == V_200 ||
V_99 -> V_199 == V_201 )
continue;
if ( V_99 -> V_199 == V_211 ) {
F_158 ( V_2 , V_99 ) ;
}
F_161 ( & V_99 -> V_248 , V_256 ) ;
}
}
static void F_162 ( struct V_1 * V_2 ,
struct V_102 * V_256 )
{
struct V_102 * V_103 , * V_255 ;
struct V_98 * V_99 ;
struct V_33 * V_34 ;
void (* F_163)( struct V_98 * , void * V_19 );
void * V_257 ;
char V_197 [ V_198 ] ;
F_159 (l, n, final_queue) {
V_99 = F_156 ( V_103 , struct V_98 , V_248 ) ;
F_164 ( & V_99 -> V_248 ) ;
V_34 = V_99 -> V_34 ;
F_163 = V_99 -> F_163 ;
V_257 = V_99 -> V_257 ;
if ( V_34 )
F_95 ( & V_34 -> V_38 ) ;
switch ( V_99 -> V_199 ) {
case V_247 :
V_99 -> V_199 = V_258 ;
break;
case V_211 :
V_99 -> V_199 = V_259 ;
break;
case V_206 :
V_99 -> V_199 = V_260 ;
break;
default:
snprintf ( V_197 , V_198 , L_79 , V_99 , V_99 -> V_199 ) ;
F_134 ( & V_2 -> V_56 -> V_57 ,
L_64
L_65 , V_197 ) ;
F_135 () ;
}
if ( V_99 -> F_163 != NULL )
( F_163 ) ( V_99 , V_257 ) ;
if ( V_34 )
F_96 ( & V_34 -> V_38 ) ;
}
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
if ( F_53 ( & V_2 -> V_15 ) )
return;
V_99 = F_156 ( V_2 -> V_15 . V_229 , struct V_98 , V_248 ) ;
if ( ( V_99 -> V_199 == V_200 && V_99 -> V_224 != 0 ) &&
( F_166 ( V_212 , V_99 -> V_224 + V_99 -> V_202 ) ) ) {
if ( F_137 ( V_261 , & V_2 -> V_190 ) ) {
V_99 -> V_196 ++ ;
}
if ( V_2 -> V_42 -> V_262 ( V_99 ) != 0 ) {
F_134 ( & V_2 -> V_56 -> V_57 ,
L_80
L_81 ,
V_99 , ( V_99 -> V_224 / V_263 ) ) ;
V_99 -> V_224 += 5 * V_263 ;
F_144 ( V_2 , 5 * V_263 ) ;
} else {
F_134 ( & V_2 -> V_56 -> V_57 ,
L_82
L_83 , V_99 , ( V_99 -> V_224 / V_263 ) ,
V_99 -> V_196 ) ;
}
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
int V_40 ;
if ( F_53 ( & V_2 -> V_15 ) )
return;
V_99 = F_156 ( V_2 -> V_15 . V_229 , struct V_98 , V_248 ) ;
if ( V_99 -> V_199 != V_227 )
return;
if ( V_2 -> V_249 &&
! ( ! ( V_2 -> V_249 & ~ ( V_264 | V_265 ) )
&& F_137 ( V_213 , & V_99 -> V_190 ) ) ) {
V_99 -> V_208 = - V_66 ;
V_99 -> V_199 = V_206 ;
F_75 ( V_2 ) ;
return;
}
V_40 = V_2 -> V_42 -> V_250 ( V_99 ) ;
if ( V_40 == 0 )
F_144 ( V_2 , V_99 -> V_224 ) ;
else if ( V_40 == - V_218 ) {
F_75 ( V_2 ) ;
} else
F_144 ( V_2 , 50 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_215 . V_221 ) {
if ( V_2 -> V_249 & ~ ( V_264 |
V_265 ) )
return;
V_40 = V_2 -> V_42 -> V_266 (
V_2 , V_2 -> V_215 . V_221 ) ;
if ( V_40 )
F_144 ( V_2 , 50 ) ;
else
V_2 -> V_215 . V_221 = 0 ;
}
}
int F_45 ( struct V_1 * V_2 )
{
struct V_98 * V_99 , * V_255 ;
int V_40 ;
struct V_102 V_267 ;
F_12 ( & V_267 ) ;
F_169 ( F_142 ( V_2 -> V_56 ) ) ;
V_40 = 0 ;
F_170 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_99 -> V_199 ) {
case V_200 :
V_40 = V_2 -> V_42 -> V_262 ( V_99 ) ;
if ( V_40 ) {
F_134 ( & V_2 -> V_56 -> V_57 ,
L_84
L_85 , V_99 ) ;
goto V_268;
}
break;
case V_227 :
V_99 -> V_151 = F_133 () ;
V_99 -> V_199 = V_206 ;
break;
default:
break;
}
F_161 ( & V_99 -> V_248 , & V_267 ) ;
}
V_268:
F_171 ( F_142 ( V_2 -> V_56 ) ) ;
F_170 (cqr, n, &flush_queue, devlist)
F_83 ( V_246 ,
( V_99 -> V_199 != V_201 ) ) ;
F_162 ( V_2 , & V_267 ) ;
return V_40 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_102 V_256 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_256 ) ;
F_169 ( F_142 ( V_2 -> V_56 ) ) ;
F_165 ( V_2 ) ;
F_160 ( V_2 , & V_256 ) ;
F_168 ( V_2 ) ;
F_171 ( F_142 ( V_2 -> V_56 ) ) ;
F_162 ( V_2 , & V_256 ) ;
F_169 ( F_142 ( V_2 -> V_56 ) ) ;
F_167 ( V_2 ) ;
F_171 ( F_142 ( V_2 -> V_56 ) ) ;
if ( F_172 ( & V_269 ) )
F_71 ( & V_269 ) ;
F_23 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( F_173 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_174 ( & V_2 -> V_13 ) ;
}
void F_175 ( struct V_1 * V_2 , int V_270 )
{
V_2 -> V_249 |= V_270 ;
}
void F_143 ( struct V_1 * V_2 , int V_270 )
{
V_2 -> V_249 &= ~ V_270 ;
if ( ! V_2 -> V_249 )
F_71 ( & V_271 ) ;
}
void F_176 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
unsigned long V_190 ;
V_2 = V_99 -> V_109 ;
F_123 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
V_99 -> V_199 = V_227 ;
F_177 ( & V_99 -> V_248 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_125 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
}
void F_178 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
unsigned long V_190 ;
V_2 = V_99 -> V_109 ;
F_123 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
V_99 -> V_199 = V_227 ;
F_179 ( & V_99 -> V_248 , & V_2 -> V_15 ) ;
F_75 ( V_2 ) ;
F_125 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
}
void F_180 ( struct V_98 * V_99 , void * V_19 )
{
F_169 ( F_142 ( V_99 -> V_109 -> V_56 ) ) ;
V_99 -> V_257 = V_272 ;
F_171 ( F_142 ( V_99 -> V_109 -> V_56 ) ) ;
F_71 ( & V_271 ) ;
}
static inline int F_181 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_99 -> V_109 ;
F_169 ( F_142 ( V_2 -> V_56 ) ) ;
V_40 = ( V_99 -> V_257 == V_272 ) ;
F_171 ( F_142 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
static int F_182 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
T_6 V_273 ;
if ( V_99 -> V_199 == V_274 )
return 0 ;
V_2 = V_99 -> V_109 ;
if ( F_137 ( V_189 , & V_99 -> V_190 ) ) {
if ( V_99 -> V_199 == V_260 ) {
V_2 -> V_42 -> V_275 ( V_99 ) ;
return 1 ;
}
if ( V_99 -> V_199 == V_259 ) {
V_273 = V_2 -> V_42 -> V_276 ( V_99 ) ;
V_273 ( V_99 ) ;
return 1 ;
}
if ( V_99 -> V_199 == V_277 )
F_183 ( V_99 , & V_99 -> V_228 ) ;
if ( V_99 -> V_278 ) {
F_184 ( V_2 , V_99 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_185 ( struct V_98 * V_99 )
{
if ( F_137 ( V_189 , & V_99 -> V_190 ) ) {
if ( V_99 -> V_278 )
return 1 ;
return ( ( V_99 -> V_199 != V_258 ) &&
( V_99 -> V_199 != V_277 ) ) ;
} else
return ( V_99 -> V_199 == V_274 ) ;
}
static int F_186 ( struct V_98 * V_279 , int V_280 )
{
struct V_1 * V_2 ;
int V_40 ;
struct V_102 V_15 ;
struct V_98 * V_99 ;
F_12 ( & V_15 ) ;
V_279 -> V_199 = V_274 ;
V_2 = V_279 -> V_109 ;
F_177 ( & V_279 -> V_281 , & V_15 ) ;
for ( V_99 = V_279 ; F_185 ( V_99 ) ;
V_99 = F_187 ( & V_15 ,
struct V_98 , V_281 ) ) {
if ( F_182 ( V_99 ) )
continue;
if ( V_99 -> V_199 != V_274 )
continue;
if ( F_137 ( V_209 , & V_2 -> V_190 ) &&
! F_137 ( V_210 , & V_99 -> V_190 ) ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = - V_89 ;
continue;
}
if ( V_2 -> V_249 & ~ V_223 &&
F_137 ( V_282 , & V_99 -> V_190 ) &&
( ! F_188 ( V_2 ) ) ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = - V_283 ;
continue;
}
if ( ! F_137 ( V_213 , & V_99 -> V_190 ) ) {
if ( V_280 ) {
V_40 = F_189 (
V_271 , ! ( V_2 -> V_249 ) ) ;
if ( V_40 == - V_284 ) {
V_99 -> V_199 = V_277 ;
V_279 -> V_208 = V_40 ;
continue;
}
} else
F_83 ( V_271 , ! ( V_2 -> V_249 ) ) ;
}
if ( ! V_99 -> F_163 )
V_99 -> F_163 = F_180 ;
V_99 -> V_257 = V_285 ;
F_178 ( V_99 ) ;
if ( V_280 ) {
V_40 = F_189 (
V_271 , F_181 ( V_99 ) ) ;
if ( V_40 == - V_284 ) {
F_190 ( V_99 ) ;
F_83 ( V_271 ,
F_181 ( V_99 ) ) ;
V_99 -> V_199 = V_277 ;
V_279 -> V_208 = V_40 ;
continue;
}
} else
F_83 ( V_271 , F_181 ( V_99 ) ) ;
}
V_279 -> V_152 = F_133 () ;
if ( ( V_279 -> V_199 != V_258 ) &&
( V_279 -> V_208 != - V_284 ) )
F_183 ( V_279 , & V_279 -> V_228 ) ;
if ( V_279 -> V_199 == V_258 )
V_40 = 0 ;
else if ( V_279 -> V_208 )
V_40 = V_279 -> V_208 ;
else
V_40 = - V_205 ;
return V_40 ;
}
static inline int F_191 ( struct V_102 * V_15 )
{
struct V_98 * V_99 ;
F_192 (cqr, ccw_queue, blocklist) {
if ( V_99 -> V_257 != V_272 )
return 0 ;
}
return 1 ;
}
static int F_193 ( struct V_102 * V_15 , int V_280 )
{
struct V_1 * V_2 ;
struct V_98 * V_99 , * V_255 ;
int V_40 ;
V_286:
F_170 (cqr, n, ccw_queue, blocklist) {
V_2 = V_99 -> V_109 ;
if ( V_99 -> V_199 != V_274 )
continue;
if ( F_137 ( V_209 , & V_2 -> V_190 ) &&
! F_137 ( V_210 , & V_99 -> V_190 ) ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = - V_89 ;
continue;
}
if ( V_2 -> V_249 & ~ V_223 &&
F_137 ( V_282 , & V_99 -> V_190 ) &&
! F_188 ( V_2 ) ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = - V_66 ;
continue;
}
if ( V_280 ) {
V_40 = F_189 (
V_271 , ! V_2 -> V_249 ) ;
if ( V_40 == - V_284 ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = V_40 ;
continue;
}
} else
F_83 ( V_271 , ! ( V_2 -> V_249 ) ) ;
if ( ! V_99 -> F_163 )
V_99 -> F_163 = F_180 ;
V_99 -> V_257 = V_285 ;
F_178 ( V_99 ) ;
}
F_83 ( V_271 , F_191 ( V_15 ) ) ;
V_40 = 0 ;
F_170 (cqr, n, ccw_queue, blocklist) {
if ( V_99 -> V_109 != V_99 -> V_287 && ! V_99 -> V_278 &&
( V_99 -> V_199 == V_260 ||
V_99 -> V_199 == V_259 ) )
return - V_66 ;
if ( F_182 ( V_99 ) )
goto V_286;
}
return 0 ;
}
int F_194 ( struct V_98 * V_99 )
{
return F_186 ( V_99 , 0 ) ;
}
int F_195 ( struct V_102 * V_15 )
{
return F_193 ( V_15 , 0 ) ;
}
int F_196 ( struct V_98 * V_99 )
{
return F_186 ( V_99 , 1 ) ;
}
static inline int F_197 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
int V_40 ;
if ( F_53 ( & V_2 -> V_15 ) )
return 0 ;
V_99 = F_156 ( V_2 -> V_15 . V_229 , struct V_98 , V_248 ) ;
V_40 = V_2 -> V_42 -> V_262 ( V_99 ) ;
if ( ! V_40 )
V_99 -> V_196 ++ ;
return V_40 ;
}
int F_198 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_99 -> V_109 ;
if ( F_137 ( V_209 , & V_2 -> V_190 ) &&
! F_137 ( V_210 , & V_99 -> V_190 ) ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = - V_89 ;
return - V_205 ;
}
F_169 ( F_142 ( V_2 -> V_56 ) ) ;
V_40 = F_197 ( V_2 ) ;
if ( V_40 ) {
F_171 ( F_142 ( V_2 -> V_56 ) ) ;
return V_40 ;
}
V_99 -> F_163 = F_180 ;
V_99 -> V_257 = V_285 ;
V_99 -> V_199 = V_227 ;
F_177 ( & V_99 -> V_248 , V_2 -> V_15 . V_229 ) ;
F_75 ( V_2 ) ;
F_171 ( F_142 ( V_2 -> V_56 ) ) ;
F_83 ( V_271 , F_181 ( V_99 ) ) ;
if ( V_99 -> V_199 == V_258 )
V_40 = 0 ;
else if ( V_99 -> V_208 )
V_40 = V_99 -> V_208 ;
else
V_40 = - V_205 ;
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
return V_40 ;
}
int F_190 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_109 ;
unsigned long V_190 ;
int V_40 ;
V_40 = 0 ;
F_123 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
switch ( V_99 -> V_199 ) {
case V_227 :
V_99 -> V_199 = V_206 ;
if ( V_99 -> V_257 == V_285 )
V_99 -> V_257 = V_272 ;
break;
case V_200 :
V_40 = V_2 -> V_42 -> V_262 ( V_99 ) ;
if ( V_40 ) {
F_134 ( & V_2 -> V_56 -> V_57 ,
L_86 ,
V_99 , V_40 ) ;
} else {
V_99 -> V_151 = F_133 () ;
}
break;
default:
break;
}
F_125 ( F_142 ( V_2 -> V_56 ) , V_190 ) ;
F_75 ( V_2 ) ;
return V_40 ;
}
static void V_39 ( unsigned long V_222 )
{
unsigned long V_190 ;
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_222 ;
F_123 ( F_142 ( V_34 -> V_64 -> V_56 ) , V_190 ) ;
F_143 ( V_34 -> V_64 , V_223 ) ;
F_125 ( F_142 ( V_34 -> V_64 -> V_56 ) , V_190 ) ;
F_60 ( V_34 ) ;
}
void F_199 ( struct V_33 * V_34 , int V_224 )
{
if ( V_224 == 0 )
F_145 ( & V_34 -> V_16 ) ;
else
F_146 ( & V_34 -> V_16 , V_212 + V_224 ) ;
}
void F_44 ( struct V_33 * V_34 )
{
F_145 ( & V_34 -> V_16 ) ;
}
static void F_184 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
T_6 V_273 ;
if ( V_99 -> V_199 == V_258 )
F_39 ( V_288 , V_2 , L_1 , L_87 ) ;
else
F_134 ( & V_2 -> V_56 -> V_57 , L_88 ) ;
V_273 = V_2 -> V_42 -> V_289 ( V_99 ) ;
V_273 ( V_99 ) ;
}
static void F_200 ( struct V_33 * V_34 )
{
struct V_290 * V_291 ;
struct V_100 * V_101 ;
struct V_98 * V_99 ;
struct V_1 * V_287 ;
unsigned long V_190 ;
V_291 = V_34 -> V_290 ;
V_287 = V_34 -> V_64 ;
if ( V_291 == NULL )
return;
if ( V_287 -> V_26 < V_71 ) {
while ( ( V_101 = F_201 ( V_34 -> V_290 ) ) )
F_202 ( V_101 , - V_205 ) ;
return;
}
if ( V_287 -> V_249 )
return;
while ( ( V_101 = F_203 ( V_291 ) ) ) {
if ( V_287 -> V_81 & V_292 &&
F_87 ( V_101 ) == V_293 ) {
F_39 ( V_183 , V_287 ,
L_89 ,
V_101 ) ;
F_204 ( V_101 ) ;
F_202 ( V_101 , - V_205 ) ;
continue;
}
if ( F_137 ( V_294 , & V_287 -> V_190 ) &&
( V_287 -> V_81 & V_295 ||
F_205 ( V_101 ) ) ) {
F_39 ( V_183 , V_287 ,
L_90 ,
V_101 ) ;
F_204 ( V_101 ) ;
F_202 ( V_101 , - V_217 ) ;
continue;
}
V_99 = V_287 -> V_42 -> V_296 ( V_287 , V_34 , V_101 ) ;
if ( F_30 ( V_99 ) ) {
if ( F_103 ( V_99 ) == - V_207 )
break;
if ( F_103 ( V_99 ) == - V_4 )
break;
if ( F_103 ( V_99 ) == - V_66 ) {
if ( ! F_53 ( & V_34 -> V_15 ) )
break;
F_123 (
F_142 ( V_287 -> V_56 ) , V_190 ) ;
F_175 ( V_287 ,
V_223 ) ;
F_125 (
F_142 ( V_287 -> V_56 ) , V_190 ) ;
F_199 ( V_34 , V_263 / 2 ) ;
break;
}
F_39 ( V_183 , V_287 ,
L_91
L_92 ,
F_103 ( V_99 ) , V_101 ) ;
F_204 ( V_101 ) ;
F_202 ( V_101 , - V_205 ) ;
continue;
}
V_99 -> V_257 = ( void * ) V_101 ;
V_99 -> V_199 = V_274 ;
V_101 -> V_297 = V_99 ;
F_204 ( V_101 ) ;
F_179 ( & V_99 -> V_281 , & V_34 -> V_15 ) ;
F_12 ( & V_99 -> V_248 ) ;
F_84 ( V_34 , V_99 , V_101 ) ;
}
}
static void F_206 ( struct V_98 * V_99 )
{
struct V_100 * V_101 ;
int V_199 ;
int error = 0 ;
V_101 = (struct V_100 * ) V_99 -> V_257 ;
F_91 ( V_99 -> V_34 , V_99 , V_101 ) ;
V_199 = V_99 -> V_34 -> V_64 -> V_42 -> V_298 ( V_99 , V_101 ) ;
if ( V_199 < 0 )
error = V_199 ;
else if ( V_199 == 0 ) {
if ( V_99 -> V_208 == - V_89 )
error = - V_299 ;
else if ( V_99 -> V_208 == - V_283 ||
V_99 -> V_208 == - V_217 )
error = V_99 -> V_208 ;
else
error = - V_205 ;
}
F_202 ( V_101 , error ) ;
}
static void F_207 ( struct V_33 * V_34 ,
struct V_102 * V_256 )
{
struct V_102 * V_103 , * V_255 ;
struct V_98 * V_99 ;
T_6 V_273 ;
unsigned long V_190 ;
struct V_1 * V_64 = V_34 -> V_64 ;
V_300:
F_159 (l, n, &block->ccw_queue) {
V_99 = F_156 ( V_103 , struct V_98 , V_281 ) ;
if ( V_99 -> V_199 != V_258 &&
V_99 -> V_199 != V_277 &&
V_99 -> V_199 != V_259 &&
V_99 -> V_199 != V_260 )
continue;
if ( V_99 -> V_199 == V_260 ) {
V_64 -> V_42 -> V_275 ( V_99 ) ;
goto V_300;
}
if ( V_99 -> V_199 == V_259 ) {
V_273 = V_64 -> V_42 -> V_276 ( V_99 ) ;
if ( F_30 ( V_273 ( V_99 ) ) )
continue;
goto V_300;
}
if ( V_99 -> V_199 == V_277 ) {
F_183 ( V_99 , & V_99 -> V_228 ) ;
}
if ( F_188 ( V_64 ) &&
V_99 -> V_199 == V_277 ) {
F_208 ( V_64 , V_99 , V_301 ) ;
V_99 -> V_199 = V_274 ;
V_99 -> V_196 = 255 ;
F_123 ( F_142 ( V_64 -> V_56 ) , V_190 ) ;
F_175 ( V_64 , V_302 ) ;
F_125 ( F_142 ( V_64 -> V_56 ) ,
V_190 ) ;
goto V_300;
}
if ( V_99 -> V_278 ) {
F_184 ( V_64 , V_99 ) ;
goto V_300;
}
V_99 -> V_152 = F_133 () ;
F_161 ( & V_99 -> V_281 , V_256 ) ;
}
}
static void F_209 ( struct V_98 * V_99 , void * V_19 )
{
F_60 ( V_99 -> V_34 ) ;
}
static void F_210 ( struct V_33 * V_34 )
{
struct V_98 * V_99 ;
if ( F_53 ( & V_34 -> V_15 ) )
return;
F_192 (cqr, &block->ccw_queue, blocklist) {
if ( V_99 -> V_199 != V_274 )
continue;
if ( F_137 ( V_209 , & V_34 -> V_64 -> V_190 ) &&
! F_137 ( V_210 , & V_99 -> V_190 ) ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = - V_89 ;
F_60 ( V_34 ) ;
continue;
}
if ( V_34 -> V_64 -> V_249 & ~ V_223 &&
F_137 ( V_282 , & V_99 -> V_190 ) &&
( ! F_188 ( V_34 -> V_64 ) ) ) {
V_99 -> V_199 = V_277 ;
V_99 -> V_208 = - V_283 ;
F_60 ( V_34 ) ;
continue;
}
if ( V_34 -> V_64 -> V_249 )
return;
if ( ! V_99 -> V_109 )
V_99 -> V_109 = V_34 -> V_64 ;
V_99 -> F_163 = F_209 ;
F_178 ( V_99 ) ;
}
}
static void V_37 ( struct V_33 * V_34 )
{
struct V_102 V_256 ;
struct V_102 * V_103 , * V_255 ;
struct V_98 * V_99 ;
F_10 ( & V_34 -> V_12 , 0 ) ;
F_12 ( & V_256 ) ;
F_86 ( & V_34 -> V_38 ) ;
F_207 ( V_34 , & V_256 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_169 ( & V_34 -> V_36 ) ;
F_159 (l, n, &final_queue) {
V_99 = F_156 ( V_103 , struct V_98 , V_281 ) ;
F_164 ( & V_99 -> V_281 ) ;
F_206 ( V_99 ) ;
}
F_86 ( & V_34 -> V_38 ) ;
F_200 ( V_34 ) ;
F_210 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
F_171 ( & V_34 -> V_36 ) ;
if ( F_172 ( & V_269 ) )
F_71 ( & V_269 ) ;
F_23 ( V_34 -> V_64 ) ;
}
static void F_211 ( struct V_98 * V_99 , void * V_19 )
{
F_71 ( & V_246 ) ;
}
static int F_212 ( struct V_98 * V_99 )
{
struct V_33 * V_34 = V_99 -> V_34 ;
struct V_100 * V_101 ;
unsigned long V_190 ;
if ( ! V_34 )
return - V_169 ;
F_123 ( & V_34 -> V_38 , V_190 ) ;
V_101 = (struct V_100 * ) V_99 -> V_257 ;
F_213 ( V_34 -> V_290 , V_101 ) ;
F_125 ( & V_34 -> V_38 , V_190 ) ;
return 0 ;
}
static int F_55 ( struct V_33 * V_34 )
{
struct V_98 * V_99 , * V_255 ;
int V_40 , V_171 ;
struct V_102 V_267 ;
F_12 ( & V_267 ) ;
F_95 ( & V_34 -> V_38 ) ;
V_40 = 0 ;
V_300:
F_170 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_99 -> V_199 >= V_227 )
V_40 = F_190 ( V_99 ) ;
if ( V_40 < 0 )
break;
V_99 -> F_163 = F_211 ;
for ( V_171 = 0 ; V_99 != NULL ; V_99 = V_99 -> V_278 , V_171 ++ )
F_161 ( & V_99 -> V_281 , & V_267 ) ;
if ( V_171 > 1 )
goto V_300;
}
F_96 ( & V_34 -> V_38 ) ;
V_303:
F_170 (cqr, n, &flush_queue, blocklist) {
F_83 ( V_246 , ( V_99 -> V_199 < V_227 ) ) ;
if ( V_99 -> V_278 ) {
F_95 ( & V_34 -> V_38 ) ;
F_184 ( V_34 -> V_64 , V_99 ) ;
F_96 ( & V_34 -> V_38 ) ;
goto V_303;
}
F_169 ( & V_34 -> V_36 ) ;
V_99 -> V_152 = F_133 () ;
F_164 ( & V_99 -> V_281 ) ;
F_206 ( V_99 ) ;
F_171 ( & V_34 -> V_36 ) ;
}
return V_40 ;
}
void F_60 ( struct V_33 * V_34 )
{
if ( F_173 ( & V_34 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_34 -> V_64 ) ;
F_174 ( & V_34 -> V_13 ) ;
}
static void F_214 ( struct V_290 * V_291 )
{
struct V_33 * V_34 ;
V_34 = V_291 -> V_304 ;
F_86 ( & V_34 -> V_38 ) ;
F_200 ( V_34 ) ;
F_210 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
}
enum V_305 F_215 ( struct V_100 * V_101 )
{
struct V_98 * V_99 = V_101 -> V_297 ;
struct V_33 * V_34 = V_101 -> V_306 -> V_304 ;
struct V_1 * V_2 ;
int V_40 = 0 ;
if ( ! V_99 )
return V_307 ;
V_2 = V_99 -> V_109 ? V_99 -> V_109 : V_34 -> V_64 ;
if ( ! V_2 -> V_308 )
return V_309 ;
F_39 ( V_60 , V_2 ,
L_93 ,
V_99 , V_99 -> V_199 ) ;
F_86 ( & V_34 -> V_38 ) ;
F_86 ( F_142 ( V_2 -> V_56 ) ) ;
V_99 -> V_196 = - 1 ;
V_99 -> V_208 = - V_217 ;
if ( V_99 -> V_199 >= V_227 ) {
F_88 ( F_142 ( V_2 -> V_56 ) ) ;
V_40 = F_190 ( V_99 ) ;
} else if ( V_99 -> V_199 == V_274 ||
V_99 -> V_199 == V_259 ) {
V_99 -> V_199 = V_260 ;
F_88 ( F_142 ( V_2 -> V_56 ) ) ;
} else if ( V_99 -> V_199 == V_310 ) {
struct V_98 * V_311 , * V_312 , * V_313 ;
F_170 (searchcqr, nextcqr,
&block->ccw_queue, blocklist) {
V_313 = V_311 ;
while ( V_313 -> V_278 )
V_313 = V_313 -> V_278 ;
if ( V_313 != V_99 )
continue;
V_311 -> V_196 = - 1 ;
V_311 -> V_208 = - V_217 ;
if ( V_311 -> V_199 >= V_227 ) {
F_88 ( F_142 ( V_2 -> V_56 ) ) ;
V_40 = F_190 ( V_311 ) ;
F_86 ( F_142 ( V_2 -> V_56 ) ) ;
} else if ( ( V_311 -> V_199 == V_274 ) ||
( V_311 -> V_199 == V_259 ) ) {
V_311 -> V_199 = V_260 ;
V_40 = 0 ;
} else if ( V_311 -> V_199 == V_310 ) {
continue;
}
break;
}
F_88 ( F_142 ( V_2 -> V_56 ) ) ;
}
F_60 ( V_34 ) ;
F_88 ( & V_34 -> V_38 ) ;
return V_40 ? V_309 : V_307 ;
}
static int F_22 ( struct V_33 * V_34 )
{
V_34 -> V_290 = F_216 ( F_214 ,
& V_34 -> V_36 ) ;
if ( V_34 -> V_290 == NULL )
return - V_4 ;
V_34 -> V_290 -> V_304 = V_34 ;
return 0 ;
}
static void F_49 ( struct V_33 * V_34 )
{
int V_314 ;
if ( V_34 -> V_64 -> V_81 & V_82 ) {
V_314 = 2048 ;
} else {
V_314 = V_34 -> V_64 -> V_42 -> V_315 << V_34 -> V_70 ;
}
F_217 ( V_34 -> V_290 ,
V_34 -> V_73 ) ;
F_218 ( V_34 -> V_290 , V_314 ) ;
F_219 ( V_34 -> V_290 , - 1L ) ;
F_220 ( V_34 -> V_290 , V_9 ) ;
F_221 ( V_34 -> V_290 , V_9 - 1 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
if ( V_34 -> V_290 ) {
F_222 ( V_34 -> V_290 ) ;
V_34 -> V_290 = NULL ;
}
}
static void F_56 ( struct V_33 * V_34 )
{
struct V_100 * V_101 ;
if ( ! V_34 -> V_290 )
return;
F_169 ( & V_34 -> V_36 ) ;
while ( ( V_101 = F_201 ( V_34 -> V_290 ) ) )
F_202 ( V_101 , - V_205 ) ;
F_171 ( & V_34 -> V_36 ) ;
}
static int F_223 ( struct V_316 * V_85 , T_7 V_177 )
{
struct V_1 * V_64 ;
int V_40 ;
V_64 = F_224 ( V_85 -> V_86 ) ;
if ( ! V_64 )
return - V_204 ;
F_225 ( & V_64 -> V_34 -> V_35 ) ;
if ( F_137 ( V_252 , & V_64 -> V_190 ) ) {
V_40 = - V_204 ;
goto V_317;
}
if ( ! F_226 ( V_64 -> V_42 -> V_44 ) ) {
V_40 = - V_169 ;
goto V_317;
}
if ( V_96 ) {
F_227 ( & V_64 -> V_56 -> V_57 ,
L_94
L_95 ) ;
V_40 = - V_89 ;
goto V_68;
}
if ( V_64 -> V_26 <= V_62 ) {
F_39 ( V_183 , V_64 , L_96 ,
L_97 ) ;
V_40 = - V_204 ;
goto V_68;
}
if ( ( V_177 & V_318 ) &&
( F_137 ( V_319 , & V_64 -> V_190 ) ||
( V_64 -> V_81 & V_292 ) ) ) {
V_40 = - V_320 ;
goto V_68;
}
F_23 ( V_64 ) ;
return 0 ;
V_68:
F_26 ( V_64 -> V_42 -> V_44 ) ;
V_317:
F_228 ( & V_64 -> V_34 -> V_35 ) ;
F_23 ( V_64 ) ;
return V_40 ;
}
static void F_229 ( struct V_74 * V_75 , T_7 V_177 )
{
struct V_1 * V_64 = F_224 ( V_75 ) ;
if ( V_64 ) {
F_228 ( & V_64 -> V_34 -> V_35 ) ;
F_26 ( V_64 -> V_42 -> V_44 ) ;
F_23 ( V_64 ) ;
}
}
static int F_230 ( struct V_316 * V_85 , struct V_321 * V_322 )
{
struct V_1 * V_64 ;
V_64 = F_224 ( V_85 -> V_86 ) ;
if ( ! V_64 )
return - V_204 ;
if ( ! V_64 -> V_42 ||
! V_64 -> V_42 -> V_323 ) {
F_23 ( V_64 ) ;
return - V_169 ;
}
V_64 -> V_42 -> V_323 ( V_64 -> V_34 , V_322 ) ;
V_322 -> V_324 = F_231 ( V_85 ) >> V_64 -> V_34 -> V_70 ;
F_23 ( V_64 ) ;
return 0 ;
}
static void
F_232 ( void )
{
#ifdef F_233
F_234 () ;
#endif
F_235 () ;
if ( V_325 != NULL ) {
F_236 ( V_325 ) ;
V_325 = NULL ;
}
F_237 () ;
F_238 () ;
if ( V_326 != NULL ) {
F_47 ( V_326 ) ;
V_326 = NULL ;
}
F_114 () ;
}
int F_239 ( struct V_1 * V_2 )
{
struct V_327 V_328 ;
struct V_329 V_330 ;
int V_40 ;
if ( ! V_331 )
return 0 ;
F_240 ( V_2 -> V_56 , & V_328 ) ;
memset ( & V_330 , 0 , sizeof( V_330 ) ) ;
V_330 . V_332 = V_328 . V_333 ;
V_330 . V_334 = sizeof( V_330 ) ;
V_40 = V_329 ( & V_330 ) ;
if ( V_40 == 0 || V_40 == 2 ) {
return V_330 . V_335 & 0x80 ;
} else {
F_116 ( V_60 , L_98 ,
V_328 . V_333 , V_40 ) ;
return 0 ;
}
}
static void F_241 ( void * V_19 , T_8 V_336 )
{
struct V_225 * V_56 = V_19 ;
int V_337 ;
V_337 = F_242 ( V_56 ) ;
if ( V_337 )
F_243 ( L_99 ,
F_35 ( & V_56 -> V_57 ) , V_337 ) ;
}
int F_244 ( struct V_225 * V_56 ,
struct V_338 * V_42 )
{
int V_337 ;
V_337 = F_245 ( V_56 ) ;
if ( V_337 ) {
F_148 ( V_60 , V_56 , L_1 ,
L_100
L_101 ) ;
return V_337 ;
}
V_56 -> V_339 = & F_152 ;
if ( ( F_246 ( V_56 , V_340 ) > 0 ) ||
( V_341 && F_247 ( F_35 ( & V_56 -> V_57 ) ) != 0 ) )
F_248 ( F_241 , V_56 ) ;
return 0 ;
}
void F_249 ( struct V_225 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_56 -> V_339 = NULL ;
V_2 = F_250 ( V_56 ) ;
if ( F_30 ( V_2 ) ) {
F_251 ( V_56 ) ;
return;
}
if ( F_252 ( V_252 , & V_2 -> V_190 ) &&
! F_137 ( V_261 , & V_2 -> V_190 ) ) {
F_23 ( V_2 ) ;
F_251 ( V_56 ) ;
return;
}
F_80 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_253 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
F_251 ( V_56 ) ;
}
int F_254 ( struct V_225 * V_56 ,
struct V_338 * V_45 )
{
struct V_338 * V_42 ;
struct V_1 * V_2 ;
int V_40 ;
F_255 ( V_56 , V_340 , 0 ) ;
V_2 = F_256 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_103 ( V_2 ) ;
V_42 = V_45 ;
if ( V_2 -> V_81 & V_342 ) {
if ( ! V_235 ) {
F_243 ( L_102 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_253 ( V_2 ) ;
return - V_204 ;
}
V_42 = V_235 ;
}
if ( ! F_226 ( V_45 -> V_44 ) ) {
F_253 ( V_2 ) ;
return - V_169 ;
}
if ( ! F_226 ( V_42 -> V_44 ) ) {
F_26 ( V_45 -> V_44 ) ;
F_253 ( V_2 ) ;
return - V_169 ;
}
V_2 -> V_45 = V_45 ;
V_2 -> V_42 = V_42 ;
V_40 = V_42 -> V_343 ( V_2 ) ;
if ( V_40 ) {
F_243 ( L_103 ,
F_35 ( & V_56 -> V_57 ) , V_42 -> V_47 , V_40 ) ;
F_26 ( V_42 -> V_44 ) ;
F_26 ( V_45 -> V_44 ) ;
F_253 ( V_2 ) ;
return V_40 ;
}
F_80 ( V_2 , V_80 ) ;
if ( V_2 -> V_26 <= V_41 ) {
F_243 ( L_104 ,
F_35 ( & V_56 -> V_57 ) ) ;
V_40 = - V_204 ;
F_80 ( V_2 , V_27 ) ;
if ( V_2 -> V_34 )
F_19 ( V_2 -> V_34 ) ;
F_253 ( V_2 ) ;
} else
F_257 ( L_105 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_83 ( V_90 , F_81 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_258 ( struct V_225 * V_56 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_344 , V_35 , V_40 ;
V_40 = 0 ;
V_2 = F_250 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return F_103 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_344 = V_2 -> V_34 -> V_85 ? 0 : - 1 ;
V_35 = F_259 ( & V_2 -> V_34 -> V_35 ) ;
if ( V_35 > V_344 ) {
if ( V_35 > 0 )
F_243 ( L_106 ,
F_35 ( & V_56 -> V_57 ) , V_35 ) ;
else
F_243 ( L_107 ,
F_35 ( & V_56 -> V_57 ) ) ;
F_260 ( V_252 , & V_2 -> V_190 ) ;
F_23 ( V_2 ) ;
return - V_207 ;
}
}
if ( F_137 ( V_261 , & V_2 -> V_190 ) ) {
if ( F_252 ( V_252 , & V_2 -> V_190 ) ) {
F_23 ( V_2 ) ;
return - V_207 ;
} else
F_260 ( V_345 , & V_2 -> V_190 ) ;
} else
if ( F_137 ( V_252 , & V_2 -> V_190 ) ) {
F_23 ( V_2 ) ;
return - V_207 ;
}
if ( F_261 ( V_345 , & V_2 -> V_190 ) &&
! F_252 ( V_261 , & V_2 -> V_190 ) ) {
V_40 = F_262 ( V_2 -> V_34 -> V_85 ) ;
if ( V_40 != 0 )
goto V_346;
F_75 ( V_2 ) ;
V_40 = F_189 ( V_269 ,
F_52 ( V_2 ) ) ;
if ( V_40 != 0 )
goto V_346;
}
F_121 ( V_252 , & V_2 -> V_190 ) ;
F_80 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_253 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
return 0 ;
V_346:
F_260 ( V_345 , & V_2 -> V_190 ) ;
F_260 ( V_261 , & V_2 -> V_190 ) ;
F_260 ( V_252 , & V_2 -> V_190 ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_98 * V_99 ;
F_263 ( & V_2 -> V_56 -> V_57 , L_108
L_109 ) ;
F_39 ( V_60 , V_2 , L_1 , L_110 ) ;
F_208 ( V_2 , NULL , V_347 ) ;
if ( V_2 -> V_26 < V_62 )
return 0 ;
F_192 (cqr, &device->ccw_queue, devlist)
if ( ( V_99 -> V_199 == V_200 ) ||
( V_99 -> V_199 == V_201 ) ) {
V_99 -> V_199 = V_227 ;
V_99 -> V_196 ++ ;
}
F_175 ( V_2 , V_264 ) ;
F_46 ( V_2 ) ;
F_75 ( V_2 ) ;
return 1 ;
}
int F_264 ( struct V_1 * V_2 )
{
F_227 ( & V_2 -> V_56 -> V_57 , L_111
L_112 ) ;
F_39 ( V_60 , V_2 , L_1 , L_113 ) ;
F_143 ( V_2 , V_264 ) ;
if ( V_2 -> V_249 & V_265 ) {
F_143 ( V_2 , V_265 ) ;
F_79 ( V_2 ) ;
return 1 ;
}
F_75 ( V_2 ) ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
if ( ! V_2 -> V_249 )
F_71 ( & V_271 ) ;
return 1 ;
}
int F_265 ( struct V_225 * V_56 , int V_348 )
{
struct V_1 * V_2 ;
int V_337 ;
V_2 = F_149 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return 0 ;
V_337 = 0 ;
switch ( V_348 ) {
case V_349 :
case V_350 :
case V_351 :
V_2 -> V_215 . V_216 = 0 ;
V_2 -> V_215 . V_219 = 0 ;
V_2 -> V_215 . V_220 = 0 ;
V_337 = F_140 ( V_2 ) ;
break;
case V_352 :
V_337 = 1 ;
if ( V_2 -> V_215 . V_216 )
V_337 = F_264 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_337 ;
}
void F_266 ( struct V_225 * V_56 , int * V_353 )
{
int V_354 ;
T_9 V_355 , V_356 ;
struct V_1 * V_2 ;
V_2 = F_149 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
for ( V_354 = 0 ; V_354 < 8 ; V_354 ++ ) {
V_356 = 0x80 >> V_354 ;
if ( V_353 [ V_354 ] & V_357 ) {
V_355 = V_2 -> V_215 . V_216 ;
V_2 -> V_215 . V_216 &= ~ V_356 ;
V_2 -> V_215 . V_219 &= ~ V_356 ;
V_2 -> V_215 . V_220 &= ~ V_356 ;
if ( V_355 && ! V_2 -> V_215 . V_216 ) {
F_263 ( & V_2 -> V_56 -> V_57 ,
L_114
L_109 ) ;
F_39 ( V_60 , V_2 ,
L_1 , L_115 ) ;
F_208 ( V_2 , NULL , V_347 ) ;
F_175 ( V_2 ,
V_264 ) ;
}
}
if ( V_353 [ V_354 ] & V_358 ) {
V_2 -> V_215 . V_216 &= ~ V_356 ;
V_2 -> V_215 . V_219 &= ~ V_356 ;
V_2 -> V_215 . V_220 &= ~ V_356 ;
V_2 -> V_215 . V_221 |= V_356 ;
F_75 ( V_2 ) ;
}
if ( V_353 [ V_354 ] & V_359 ) {
if ( ! ( V_2 -> V_215 . V_216 & V_356 ) &&
! ( V_2 -> V_215 . V_221 & V_356 ) ) {
V_2 -> V_215 . V_221 |= V_356 ;
F_75 ( V_2 ) ;
}
F_39 ( V_60 , V_2 , L_1 ,
L_116 ) ;
if ( V_2 -> V_42 -> V_97 )
V_2 -> V_42 -> V_97 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
int F_267 ( struct V_1 * V_2 , T_9 V_214 )
{
if ( ! V_2 -> V_215 . V_216 && V_214 ) {
V_2 -> V_215 . V_216 = V_214 ;
F_264 ( V_2 ) ;
} else
V_2 -> V_215 . V_216 |= V_214 ;
return 0 ;
}
int F_268 ( struct V_225 * V_56 )
{
struct V_1 * V_2 = F_250 ( V_56 ) ;
struct V_102 V_360 ;
struct V_98 * V_99 , * V_255 ;
struct V_98 * V_278 ;
int V_40 ;
if ( F_30 ( V_2 ) )
return F_103 ( V_2 ) ;
F_121 ( V_361 , & V_2 -> V_190 ) ;
if ( V_2 -> V_42 -> V_362 )
V_40 = V_2 -> V_42 -> V_362 ( V_2 ) ;
F_175 ( V_2 , V_363 ) ;
F_12 ( & V_360 ) ;
F_169 ( F_142 ( V_56 ) ) ;
V_40 = 0 ;
F_170 (cqr, n, &device->ccw_queue, devlist) {
if ( V_99 -> V_199 == V_200 ) {
V_40 = V_2 -> V_42 -> V_262 ( V_99 ) ;
if ( V_40 ) {
F_134 ( & V_2 -> V_56 -> V_57 ,
L_117
L_118 , V_99 ) ;
F_171 ( F_142 ( V_56 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
}
F_161 ( & V_99 -> V_248 , & V_360 ) ;
}
F_171 ( F_142 ( V_56 ) ) ;
F_170 (cqr, n, &freeze_queue, devlist) {
F_83 ( V_246 ,
( V_99 -> V_199 != V_201 ) ) ;
if ( V_99 -> V_199 == V_206 )
V_99 -> V_199 = V_227 ;
if ( F_212 ( V_99 ) )
continue;
F_164 ( & V_99 -> V_248 ) ;
while ( V_99 -> V_278 != NULL ) {
V_278 = V_99 -> V_278 ;
F_269 ( & V_99 -> V_281 ) ;
F_270 ( V_99 , V_99 -> V_364 ) ;
V_99 = V_278 ;
}
if ( V_99 -> V_34 )
F_164 ( & V_99 -> V_281 ) ;
V_99 -> V_34 -> V_64 -> V_42 -> V_298 (
V_99 , (struct V_100 * ) V_99 -> V_257 ) ;
}
if ( ! F_53 ( & V_360 ) ) {
F_169 ( F_142 ( V_56 ) ) ;
F_271 ( & V_360 , & V_2 -> V_15 ) ;
F_171 ( F_142 ( V_56 ) ) ;
}
F_23 ( V_2 ) ;
return V_40 ;
}
int F_272 ( struct V_225 * V_56 )
{
struct V_1 * V_2 = F_250 ( V_56 ) ;
int V_40 = 0 ;
if ( F_30 ( V_2 ) )
return F_103 ( V_2 ) ;
F_143 ( V_2 ,
( V_363 | V_265 ) ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_42 -> V_95 && ! ( V_2 -> V_249 ) )
V_40 = V_2 -> V_42 -> V_95 ( V_2 ) ;
if ( V_40 || V_2 -> V_249 )
V_2 -> V_249 |= V_265 ;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
F_260 ( V_361 , & V_2 -> V_190 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_98 * F_273 ( struct V_1 * V_2 ,
void * V_365 ,
int V_366 ,
int V_184 )
{
struct V_98 * V_99 ;
struct V_187 * V_192 ;
unsigned long * V_367 ;
V_99 = F_122 ( V_184 , 1 , V_366 , V_2 ) ;
if ( F_30 ( V_99 ) ) {
F_134 ( & V_2 -> V_56 -> V_57 ,
L_64
L_65 , L_119 ) ;
return V_99 ;
}
V_192 = V_99 -> V_188 ;
V_192 -> V_368 = V_369 ;
if ( F_274 ( V_365 , V_366 ) ) {
V_367 = ( unsigned long * ) ( V_99 -> V_19 ) ;
V_192 -> V_370 = ( V_371 ) ( V_372 ) V_367 ;
V_192 -> V_190 = V_373 ;
V_367 = F_275 ( V_367 , V_365 , V_366 ) ;
} else {
V_192 -> V_370 = ( V_371 ) ( V_372 ) V_365 ;
V_192 -> V_190 = 0 ;
}
V_192 -> V_374 = V_366 ;
V_99 -> V_109 = V_2 ;
V_99 -> V_364 = V_2 ;
V_99 -> V_224 = 10 * V_263 ;
V_99 -> V_196 = 256 ;
V_99 -> V_149 = F_133 () ;
V_99 -> V_199 = V_274 ;
return V_99 ;
}
int F_276 ( struct V_1 * V_2 , int V_184 ,
void * V_365 , int V_366 )
{
int V_337 ;
struct V_98 * V_99 ;
V_99 = F_273 ( V_2 , V_365 , V_366 ,
V_184 ) ;
if ( F_30 ( V_99 ) )
return F_103 ( V_99 ) ;
V_337 = F_194 ( V_99 ) ;
F_128 ( V_99 , V_99 -> V_364 ) ;
return V_337 ;
}
char * F_277 ( struct V_228 * V_228 )
{
struct V_375 * V_375 = NULL ;
char * V_376 = NULL ;
if ( F_278 ( & V_228 -> V_232 ) && ( V_228 -> V_232 . V_377 . V_378 == 0x01 ) ) {
if ( V_228 -> V_232 . V_377 . V_379 )
V_375 = F_279 ( (struct V_379 * ) ( unsigned long )
V_228 -> V_232 . V_377 . V_379 ) ;
if ( V_375 && V_375 -> V_380 == 64 && V_375 -> V_190 )
switch ( V_375 -> V_190 & 0x07 ) {
case 1 :
V_376 = V_375 -> V_381 . V_382 . V_376 ;
break;
case 2 :
V_376 = V_375 -> V_381 . V_383 . V_376 ;
break;
default:
break;
}
} else if ( V_228 -> V_242 . V_384 . V_385 . V_386 ) {
V_376 = V_228 -> V_387 ;
}
return V_376 ;
}
void F_280 ( struct V_225 * V_56 )
{
struct V_1 * V_2 ;
V_2 = F_250 ( V_56 ) ;
if ( F_30 ( V_2 ) )
return;
if ( V_2 -> V_34 )
F_60 ( V_2 -> V_34 ) ;
F_75 ( V_2 ) ;
F_83 ( V_269 , F_52 ( V_2 ) ) ;
}
static int T_10 F_281 ( void )
{
int V_40 ;
F_282 ( & V_90 ) ;
F_282 ( & V_246 ) ;
F_282 ( & V_271 ) ;
F_282 ( & V_269 ) ;
V_326 = F_36 ( L_33 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_326 == NULL ) {
V_40 = - V_4 ;
goto V_388;
}
F_37 ( V_326 , & V_59 ) ;
F_38 ( V_326 , V_60 ) ;
F_116 ( V_61 , L_1 , L_2 ) ;
V_235 = NULL ;
F_115 () ;
V_40 = F_283 () ;
if ( V_40 )
goto V_388;
V_40 = F_284 () ;
if ( V_40 )
goto V_388;
V_40 = F_285 () ;
if ( V_40 )
goto V_388;
V_40 = F_286 () ;
if ( V_40 )
goto V_388;
#ifdef F_233
V_40 = F_287 () ;
if ( V_40 )
goto V_388;
#endif
return 0 ;
V_388:
F_288 ( L_120 ) ;
F_232 () ;
return V_40 ;
}
