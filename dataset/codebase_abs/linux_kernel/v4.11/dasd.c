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
F_9 ( & V_36 -> V_38 ) ;
F_10 ( & V_36 -> V_12 , 0 ) ;
F_11 ( & V_36 -> V_13 ,
( void (*) ( unsigned long ) ) V_39 ,
( unsigned long ) V_36 ) ;
F_12 ( & V_36 -> V_15 ) ;
F_9 ( & V_36 -> V_40 ) ;
F_13 ( & V_36 -> V_16 ) ;
V_36 -> V_16 . V_17 = V_41 ;
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
int V_42 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_36 ) {
V_42 = F_22 ( V_2 -> V_36 ) ;
if ( V_42 ) {
F_23 ( V_2 ) ;
return V_42 ;
}
}
V_2 -> V_28 = V_43 ;
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
static struct V_44 * F_27 ( const char * V_45 ,
struct V_44 * V_46 )
{
struct V_44 * V_47 ;
if ( ! V_46 )
return NULL ;
V_47 = F_28 ( V_45 , V_46 ) ;
if ( ! V_47 || F_29 ( V_47 ) )
return NULL ;
return V_47 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_42 = 0 ;
if ( V_36 ) {
V_42 = F_31 ( V_36 ) ;
if ( V_42 )
return V_42 ;
V_36 -> V_48 =
F_27 ( V_36 -> V_49 -> V_50 ,
V_51 ) ;
F_32 ( & V_36 -> V_32 , V_36 -> V_48 ) ;
if ( V_52 == V_53 )
F_33 ( & V_2 -> V_36 -> V_32 ) ;
}
V_2 -> V_48 =
F_27 ( F_34 ( & V_2 -> V_54 -> V_55 ) ,
V_51 ) ;
F_32 ( & V_2 -> V_32 , V_2 -> V_48 ) ;
F_35 ( V_2 -> V_48 , V_2 ) ;
V_2 -> V_56 = F_36 ( F_34 ( & V_2 -> V_54 -> V_55 ) , 4 , 1 ,
8 * sizeof( long ) ) ;
F_37 ( V_2 -> V_56 , & V_57 ) ;
F_38 ( V_2 -> V_56 , V_58 ) ;
F_39 ( V_59 , V_2 , L_1 , L_2 ) ;
V_2 -> V_28 = V_60 ;
return V_42 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_42 ;
if ( V_2 -> V_61 -> V_62 ) {
V_42 = V_2 -> V_61 -> V_62 ( V_2 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_2 -> V_36 ) {
F_41 ( & V_2 -> V_36 -> V_32 ) ;
F_42 ( V_2 -> V_36 -> V_48 ) ;
F_43 ( V_2 -> V_36 ) ;
F_44 ( V_2 -> V_36 ) ;
}
V_42 = F_45 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_46 ( V_2 ) ;
F_41 ( & V_2 -> V_32 ) ;
F_47 ( V_2 ) ;
F_42 ( V_2 -> V_48 ) ;
F_39 ( V_59 , V_2 , L_3 , V_2 ) ;
if ( V_2 -> V_56 != NULL ) {
F_48 ( V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
}
V_2 -> V_28 = V_43 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_35 * V_36 ;
struct V_63 * V_64 ;
V_42 = 0 ;
V_36 = V_2 -> V_36 ;
if ( V_36 ) {
if ( V_36 -> V_65 -> V_61 -> V_66 != NULL )
V_42 = V_36 -> V_65 -> V_61 -> V_66 ( V_36 ) ;
if ( V_42 ) {
if ( V_42 != - V_67 ) {
V_2 -> V_28 = V_68 ;
V_64 = V_2 -> V_36 -> V_49 ;
F_50 ( & F_51 ( V_64 ) -> V_69 ,
V_70 ) ;
goto V_71;
}
return V_42 ;
}
F_52 ( V_36 ) ;
F_53 ( V_36 -> V_49 ,
V_36 -> V_72 << V_36 -> V_73 ) ;
V_2 -> V_28 = V_74 ;
V_42 = F_54 ( V_36 ) ;
if ( V_42 ) {
V_2 -> V_28 = V_60 ;
return V_42 ;
}
} else {
V_2 -> V_28 = V_74 ;
}
V_71:
if ( V_2 -> V_61 -> V_75 )
V_42 = V_2 -> V_61 -> V_75 ( V_2 ) ;
return V_42 ;
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
int V_42 ;
V_2 -> V_28 = V_60 ;
if ( V_2 -> V_36 ) {
struct V_35 * V_36 = V_2 -> V_36 ;
V_42 = F_58 ( V_36 ) ;
if ( V_42 ) {
V_2 -> V_28 = V_74 ;
return V_42 ;
}
F_59 ( V_36 ) ;
F_60 ( V_36 ) ;
V_36 -> V_72 = 0 ;
V_36 -> V_76 = 0 ;
V_36 -> V_73 = 0 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
V_2 -> V_28 = V_60 ;
return 0 ;
}
static int
F_62 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_77 V_78 ;
struct V_79 * V_80 ;
V_2 -> V_28 = V_81 ;
if ( V_2 -> V_36 ) {
F_63 ( V_2 -> V_36 ) ;
if ( ( V_2 -> V_82 & V_83 ) ) {
V_64 = V_2 -> V_36 -> V_49 ;
F_50 ( & F_51 ( V_64 ) -> V_69 , V_70 ) ;
return 0 ;
}
V_64 = V_2 -> V_36 -> V_84 -> V_85 ;
F_64 ( & V_78 , V_64 , V_86 ) ;
while ( ( V_80 = F_65 ( & V_78 ) ) )
F_50 ( & F_66 ( V_80 ) -> V_69 , V_70 ) ;
F_67 ( & V_78 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_63 * V_64 ;
struct V_77 V_78 ;
struct V_79 * V_80 ;
if ( V_2 -> V_61 -> V_87 ) {
V_42 = V_2 -> V_61 -> V_87 ( V_2 ) ;
if ( V_42 )
return V_42 ;
}
V_2 -> V_28 = V_74 ;
if ( V_2 -> V_36 && ! ( V_2 -> V_82 & V_83 ) ) {
V_64 = V_2 -> V_36 -> V_84 -> V_85 ;
F_64 ( & V_78 , V_64 , V_86 ) ;
while ( ( V_80 = F_65 ( & V_78 ) ) )
F_50 ( & F_66 ( V_80 ) -> V_69 , V_70 ) ;
F_67 ( & V_78 ) ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = 0 ;
if ( V_2 -> V_28 == V_29 &&
V_2 -> V_30 >= V_43 )
V_42 = F_20 ( V_2 ) ;
if ( ! V_42 &&
V_2 -> V_28 == V_43 &&
V_2 -> V_30 >= V_60 )
V_42 = F_30 ( V_2 ) ;
if ( ! V_42 &&
V_2 -> V_28 == V_60 &&
V_2 -> V_30 >= V_74 )
V_42 = F_49 ( V_2 ) ;
if ( ! V_42 &&
V_2 -> V_28 == V_68 &&
V_2 -> V_30 > V_68 )
V_42 = - V_88 ;
if ( ! V_42 &&
V_2 -> V_28 == V_74 &&
V_2 -> V_30 >= V_81 )
V_42 = F_62 ( V_2 ) ;
return V_42 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = 0 ;
if ( V_2 -> V_28 == V_81 &&
V_2 -> V_30 <= V_74 )
V_42 = F_68 ( V_2 ) ;
if ( ! V_42 &&
V_2 -> V_28 == V_74 &&
V_2 -> V_30 <= V_60 )
V_42 = F_57 ( V_2 ) ;
if ( ! V_42 &&
V_2 -> V_28 == V_68 &&
V_2 -> V_30 <= V_60 )
V_42 = F_61 ( V_2 ) ;
if ( ! V_42 &&
V_2 -> V_28 == V_60 &&
V_2 -> V_30 <= V_43 )
V_42 = F_40 ( V_2 ) ;
if ( ! V_42 &&
V_2 -> V_28 == V_43 &&
V_2 -> V_30 <= V_29 )
V_42 = F_24 ( V_2 ) ;
return V_42 ;
}
static void F_71 ( struct V_1 * V_2 )
{
int V_42 ;
if ( V_2 -> V_28 == V_2 -> V_30 )
return;
if ( V_2 -> V_28 < V_2 -> V_30 )
V_42 = F_69 ( V_2 ) ;
else
V_42 = F_70 ( V_2 ) ;
if ( V_42 == - V_67 )
return;
if ( V_42 )
V_2 -> V_30 = V_2 -> V_28 ;
F_50 ( & V_2 -> V_54 -> V_55 . V_69 , V_70 ) ;
if ( V_2 -> V_28 == V_2 -> V_30 )
F_72 ( & V_89 ) ;
}
static void V_21 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_73 ( V_91 , struct V_1 , V_20 ) ;
F_74 ( & V_2 -> V_31 ) ;
F_71 ( V_2 ) ;
F_75 ( & V_2 -> V_31 ) ;
F_76 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_78 ( & V_2 -> V_20 ) )
F_23 ( V_2 ) ;
}
static void V_25 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_73 ( V_91 , struct V_1 ,
V_24 ) ;
V_2 -> V_61 -> V_92 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_78 ( & V_2 -> V_24 ) )
F_23 ( V_2 ) ;
}
static void V_23 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_73 ( V_91 , struct V_1 ,
V_22 ) ;
V_2 -> V_54 -> V_93 -> V_94 ( V_2 -> V_54 ) ;
F_23 ( V_2 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_78 ( & V_2 -> V_22 ) )
F_23 ( V_2 ) ;
}
void F_81 ( struct V_1 * V_2 , int V_30 )
{
F_21 ( V_2 ) ;
F_74 ( & V_2 -> V_31 ) ;
if ( V_95 && V_30 > V_74 )
V_30 = V_74 ;
if ( V_2 -> V_30 != V_30 ) {
if ( V_2 -> V_28 == V_30 )
F_72 ( & V_89 ) ;
V_2 -> V_30 = V_30 ;
}
if ( V_2 -> V_28 != V_2 -> V_30 )
F_71 ( V_2 ) ;
F_75 ( & V_2 -> V_31 ) ;
F_23 ( V_2 ) ;
}
static inline int F_82 ( struct V_1 * V_2 )
{
return ( V_2 -> V_28 == V_2 -> V_30 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_81 ( V_2 , V_81 ) ;
if ( V_2 -> V_28 <= V_43 )
F_81 ( V_2 , V_29 ) ;
F_84 ( V_89 , F_82 ( V_2 ) ) ;
F_79 ( V_2 ) ;
if ( V_2 -> V_61 -> V_96 )
V_2 -> V_61 -> V_96 ( V_2 ) ;
}
static void F_85 ( struct V_35 * V_36 ,
struct V_97 * V_98 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
unsigned int V_103 ;
struct V_1 * V_2 ;
V_103 = 0 ;
if ( V_52 || V_36 -> V_32 . V_19 )
F_86 (l, &block->ccw_queue)
if ( ++ V_103 >= 31 )
break;
F_87 ( & V_104 . V_33 ) ;
if ( V_104 . V_19 ) {
V_104 . V_19 -> V_105 [ V_103 ] ++ ;
if ( F_88 ( V_100 ) == V_106 )
V_104 . V_19 -> V_107 [ V_103 ] ++ ;
}
F_89 ( & V_104 . V_33 ) ;
F_87 ( & V_36 -> V_32 . V_33 ) ;
if ( V_36 -> V_32 . V_19 ) {
V_36 -> V_32 . V_19 -> V_105 [ V_103 ] ++ ;
if ( F_88 ( V_100 ) == V_106 )
V_36 -> V_32 . V_19 -> V_107 [ V_103 ] ++ ;
}
F_89 ( & V_36 -> V_32 . V_33 ) ;
V_2 = V_98 -> V_108 ;
if ( V_2 -> V_32 . V_19 ) {
V_103 = 1 ;
F_86 (l, &device->ccw_queue)
if ( ++ V_103 >= 31 )
break;
}
F_87 ( & V_2 -> V_32 . V_33 ) ;
if ( V_2 -> V_32 . V_19 ) {
V_2 -> V_32 . V_19 -> V_105 [ V_103 ] ++ ;
if ( F_88 ( V_100 ) == V_106 )
V_2 -> V_32 . V_19 -> V_107 [ V_103 ] ++ ;
}
F_89 ( & V_2 -> V_32 . V_33 ) ;
}
static void F_90 ( struct V_109 * V_19 ,
int V_110 ,
int V_111 ,
int V_112 ,
long V_113 ,
int V_114 ,
int V_115 ,
int V_116 ,
int V_117 ,
int V_118 ,
int V_119 ,
int V_120 )
{
if ( V_19 -> V_121 == V_122 ) {
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_91 ( & V_19 -> V_123 ) ;
}
V_19 -> V_121 ++ ;
V_19 -> V_124 += V_113 ;
if ( V_110 )
V_19 -> V_125 ++ ;
if ( V_111 )
V_19 -> V_126 ++ ;
V_19 -> V_127 [ V_114 ] ++ ;
V_19 -> V_128 [ V_115 ] ++ ;
V_19 -> V_129 [ V_116 ] ++ ;
V_19 -> V_130 [ V_117 ] ++ ;
V_19 -> V_131 [ V_118 ] ++ ;
V_19 -> V_132 [ V_119 ] ++ ;
V_19 -> V_133 [ V_120 ] ++ ;
if ( V_112 ) {
V_19 -> V_134 ++ ;
V_19 -> V_135 += V_113 ;
if ( V_110 )
V_19 -> V_136 ++ ;
if ( V_111 )
V_19 -> V_137 ++ ;
V_19 -> V_138 [ V_114 ] ++ ;
V_19 -> V_139 [ V_115 ] ++ ;
V_19 -> V_140 [ V_117 ] ++ ;
V_19 -> V_141 [ V_118 ] ++ ;
V_19 -> V_142 [ V_120 ] ++ ;
}
}
static void F_92 ( struct V_35 * V_36 ,
struct V_97 * V_98 ,
struct V_99 * V_100 )
{
long V_143 , V_144 , V_145 , V_146 ;
long V_147 , V_113 ;
struct V_1 * V_2 ;
int V_114 , V_115 , V_116 , V_117 ;
int V_118 , V_119 , V_120 ;
V_2 = V_98 -> V_108 ;
if ( ! ( V_52 ||
V_36 -> V_32 . V_19 ||
V_2 -> V_32 . V_19 ) )
return;
V_113 = F_93 ( V_100 ) ;
if ( ! V_98 -> V_148 || ! V_98 -> V_149 ||
! V_98 -> V_150 || ! V_98 -> V_151 ||
! V_113 )
return;
V_143 = ( ( V_98 -> V_149 - V_98 -> V_148 ) >> 12 ) ;
V_144 = ( ( V_98 -> V_150 - V_98 -> V_149 ) >> 12 ) ;
V_145 = ( ( V_98 -> V_151 - V_98 -> V_150 ) >> 12 ) ;
V_146 = ( ( V_98 -> V_151 - V_98 -> V_148 ) >> 12 ) ;
V_147 = V_146 / V_113 ;
F_94 ( V_113 , V_114 ) ;
F_94 ( V_146 , V_115 ) ;
F_94 ( V_147 , V_116 ) ;
F_94 ( V_143 , V_117 ) ;
F_94 ( V_144 , V_118 ) ;
F_94 ( V_144 / V_113 , V_119 ) ;
F_94 ( V_145 , V_120 ) ;
F_87 ( & V_104 . V_33 ) ;
if ( V_104 . V_19 ) {
F_90 ( V_104 . V_19 ,
V_98 -> V_108 != V_36 -> V_65 ,
V_98 -> V_152 == 1 ,
F_88 ( V_100 ) == V_106 ,
V_113 , V_114 , V_115 ,
V_116 , V_117 ,
V_118 , V_119 ,
V_120 ) ;
}
F_89 ( & V_104 . V_33 ) ;
F_87 ( & V_36 -> V_32 . V_33 ) ;
if ( V_36 -> V_32 . V_19 )
F_90 ( V_36 -> V_32 . V_19 ,
V_98 -> V_108 != V_36 -> V_65 ,
V_98 -> V_152 == 1 ,
F_88 ( V_100 ) == V_106 ,
V_113 , V_114 , V_115 ,
V_116 , V_117 ,
V_118 , V_119 ,
V_120 ) ;
F_89 ( & V_36 -> V_32 . V_33 ) ;
F_87 ( & V_2 -> V_32 . V_33 ) ;
if ( V_2 -> V_32 . V_19 )
F_90 ( V_2 -> V_32 . V_19 ,
V_98 -> V_108 != V_36 -> V_65 ,
V_98 -> V_152 == 1 ,
F_88 ( V_100 ) == V_106 ,
V_113 , V_114 , V_115 ,
V_116 , V_117 ,
V_118 , V_119 ,
V_120 ) ;
F_89 ( & V_2 -> V_32 . V_33 ) ;
}
void F_95 ( struct V_153 * V_32 )
{
struct V_109 * V_19 ;
F_96 ( & V_32 -> V_33 ) ;
V_19 = V_32 -> V_19 ;
if ( ! V_19 ) {
F_97 ( & V_32 -> V_33 ) ;
return;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_91 ( & V_19 -> V_123 ) ;
F_97 ( & V_32 -> V_33 ) ;
}
int F_33 ( struct V_153 * V_32 )
{
struct V_109 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_154 ) ;
if ( ! V_19 )
return - V_4 ;
F_96 ( & V_32 -> V_33 ) ;
if ( V_32 -> V_19 ) {
F_97 ( & V_32 -> V_33 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_91 ( & V_19 -> V_123 ) ;
V_32 -> V_19 = V_19 ;
F_97 ( & V_32 -> V_33 ) ;
return 0 ;
}
void F_98 ( struct V_153 * V_32 )
{
F_96 ( & V_32 -> V_33 ) ;
F_5 ( V_32 -> V_19 ) ;
V_32 -> V_19 = NULL ;
F_97 ( & V_32 -> V_33 ) ;
}
char * F_99 ( const char T_1 * V_155 , T_2 V_156 )
{
char * V_157 ;
V_157 = F_100 ( V_156 + 1 ) ;
if ( V_157 == NULL )
return F_3 ( - V_4 ) ;
if ( F_101 ( V_157 , V_155 , V_156 ) != 0 ) {
F_102 ( V_157 ) ;
return F_3 ( - V_158 ) ;
}
if ( V_157 [ V_156 - 1 ] == '\n' )
V_157 [ V_156 - 1 ] = 0 ;
else
V_157 [ V_156 ] = 0 ;
return V_157 ;
}
static T_3 F_103 ( struct V_159 * V_159 ,
const char T_1 * V_155 ,
T_2 V_156 , T_4 * V_160 )
{
char * V_157 , * V_161 ;
int V_42 ;
struct V_162 * V_163 = (struct V_162 * ) V_159 -> V_164 ;
struct V_153 * V_165 = V_163 -> V_34 ;
if ( V_156 > 65536 )
V_156 = 65536 ;
V_157 = F_99 ( V_155 , V_156 ) ;
if ( F_29 ( V_157 ) )
return F_104 ( V_157 ) ;
V_161 = F_105 ( V_157 ) ;
V_42 = V_156 ;
if ( strncmp ( V_161 , L_4 , 5 ) == 0 ) {
F_95 ( V_165 ) ;
} else if ( strncmp ( V_161 , L_5 , 2 ) == 0 ) {
V_42 = F_33 ( V_165 ) ;
if ( V_42 )
goto V_71;
V_42 = V_156 ;
if ( V_165 == & V_104 ) {
F_95 ( V_165 ) ;
V_52 = V_166 ;
}
} else if ( strncmp ( V_161 , L_6 , 3 ) == 0 ) {
if ( V_165 == & V_104 )
V_52 = V_167 ;
F_98 ( V_165 ) ;
} else
V_42 = - V_168 ;
V_71:
F_102 ( V_157 ) ;
return V_42 ;
}
static void F_106 ( struct V_162 * V_163 , unsigned int * V_169 )
{
int V_170 ;
for ( V_170 = 0 ; V_170 < 32 ; V_170 ++ )
F_107 ( V_163 , L_7 , V_169 [ V_170 ] ) ;
F_108 ( V_163 , '\n' ) ;
}
static void F_109 ( struct V_162 * V_163 ,
struct V_109 * V_19 )
{
F_107 ( V_163 , L_8 ,
V_19 -> V_123 . V_171 , V_19 -> V_123 . V_172 ) ;
F_107 ( V_163 , L_9 , V_19 -> V_121 ) ;
F_107 ( V_163 , L_10 , V_19 -> V_124 ) ;
F_107 ( V_163 , L_11 , V_19 -> V_125 ) ;
F_107 ( V_163 , L_12 , V_19 -> V_126 ) ;
F_110 ( V_163 , L_13 ) ;
F_106 ( V_163 , V_19 -> V_127 ) ;
F_110 ( V_163 , L_14 ) ;
F_106 ( V_163 , V_19 -> V_128 ) ;
F_110 ( V_163 , L_15 ) ;
F_106 ( V_163 , V_19 -> V_129 ) ;
F_110 ( V_163 , L_16 ) ;
F_106 ( V_163 , V_19 -> V_130 ) ;
F_110 ( V_163 , L_17 ) ;
F_106 ( V_163 , V_19 -> V_131 ) ;
F_110 ( V_163 , L_18 ) ;
F_106 ( V_163 , V_19 -> V_132 ) ;
F_110 ( V_163 , L_19 ) ;
F_106 ( V_163 , V_19 -> V_133 ) ;
F_110 ( V_163 , L_20 ) ;
F_106 ( V_163 , V_19 -> V_105 ) ;
F_107 ( V_163 , L_21 , V_19 -> V_134 ) ;
F_107 ( V_163 , L_22 , V_19 -> V_135 ) ;
F_107 ( V_163 , L_23 , V_19 -> V_136 ) ;
F_107 ( V_163 , L_24 , V_19 -> V_137 ) ;
F_110 ( V_163 , L_25 ) ;
F_106 ( V_163 , V_19 -> V_138 ) ;
F_110 ( V_163 , L_26 ) ;
F_106 ( V_163 , V_19 -> V_139 ) ;
F_110 ( V_163 , L_27 ) ;
F_106 ( V_163 , V_19 -> V_140 ) ;
F_110 ( V_163 , L_28 ) ;
F_106 ( V_163 , V_19 -> V_141 ) ;
F_110 ( V_163 , L_29 ) ;
F_106 ( V_163 , V_19 -> V_142 ) ;
F_110 ( V_163 , L_30 ) ;
F_106 ( V_163 , V_19 -> V_107 ) ;
}
static int F_111 ( struct V_162 * V_163 , void * V_173 )
{
struct V_153 * V_32 ;
struct V_109 * V_19 ;
V_32 = V_163 -> V_34 ;
F_96 ( & V_32 -> V_33 ) ;
V_19 = V_32 -> V_19 ;
if ( ! V_19 ) {
F_97 ( & V_32 -> V_33 ) ;
F_110 ( V_163 , L_31 ) ;
return 0 ;
}
F_109 ( V_163 , V_19 ) ;
F_97 ( & V_32 -> V_33 ) ;
return 0 ;
}
static int F_112 ( struct V_174 * V_174 , struct V_159 * V_159 )
{
struct V_153 * V_32 = V_174 -> V_175 ;
return F_113 ( V_159 , F_111 , V_32 ) ;
}
static void F_32 ( struct V_153 * V_32 ,
struct V_44 * V_46 )
{
T_5 V_176 ;
struct V_44 * V_47 ;
if ( ! V_46 )
return;
V_32 -> V_44 = NULL ;
V_32 -> V_19 = NULL ;
V_176 = ( V_177 | V_178 | V_179 ) ;
V_47 = F_114 ( L_32 , V_176 , V_46 ,
V_32 , & V_180 ) ;
if ( V_47 && ! F_29 ( V_47 ) )
V_32 -> V_44 = V_47 ;
return;
}
static void F_41 ( struct V_153 * V_32 )
{
F_98 ( V_32 ) ;
F_42 ( V_32 -> V_44 ) ;
V_32 -> V_44 = NULL ;
}
static void F_115 ( void )
{
V_52 = V_167 ;
F_41 ( & V_104 ) ;
F_42 ( V_181 ) ;
F_42 ( V_51 ) ;
}
static void F_116 ( void )
{
struct V_44 * V_47 ;
V_51 = NULL ;
V_47 = F_28 ( L_33 , NULL ) ;
if ( ! V_47 || F_29 ( V_47 ) )
goto error;
V_51 = V_47 ;
V_47 = F_28 ( L_34 , V_51 ) ;
if ( ! V_47 || F_29 ( V_47 ) )
goto error;
V_181 = V_47 ;
F_32 ( & V_104 , V_181 ) ;
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
int F_118 ( struct V_162 * V_163 , void * V_173 )
{
F_110 ( V_163 , L_36 ) ;
return 0 ;
}
static void F_32 ( struct V_153 * V_32 ,
struct V_44 * V_46 )
{
return;
}
static void F_41 ( struct V_153 * V_32 )
{
return;
}
int F_33 ( struct V_153 * V_32 )
{
return 0 ;
}
static int F_119 ( struct V_162 * V_163 , void * V_173 )
{
struct V_1 * V_2 ;
int V_42 = - V_183 ;
V_2 = V_163 -> V_34 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_61 -> V_184 )
V_42 = V_2 -> V_61 -> V_184 ( V_2 , V_163 ) ;
F_23 ( V_2 ) ;
return V_42 ;
}
static int F_120 ( struct V_174 * V_174 , struct V_159 * V_159 )
{
struct V_1 * V_2 = V_174 -> V_175 ;
return F_113 ( V_159 , F_119 , V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_42 ( V_2 -> V_185 ) ;
V_2 -> V_185 = NULL ;
}
static void F_35 ( struct V_44 * V_46 ,
struct V_1 * V_2 )
{
struct V_44 * V_47 ;
T_5 V_176 ;
if ( ! V_46 )
return;
V_176 = V_177 | V_179 ;
V_47 = F_114 ( L_37 , V_176 , V_46 ,
V_2 , & V_186 ) ;
if ( V_47 && ! F_29 ( V_47 ) )
V_2 -> V_185 = V_47 ;
}
struct V_97 * F_121 ( int V_187 , int V_188 ,
int V_189 ,
struct V_1 * V_2 )
{
struct V_97 * V_98 ;
F_122 ( V_189 > V_9 ||
( V_188 * sizeof( struct V_190 ) ) > V_9 ) ;
V_98 = F_2 ( sizeof( struct V_97 ) , V_3 ) ;
if ( V_98 == NULL )
return F_3 ( - V_4 ) ;
V_98 -> V_191 = NULL ;
if ( V_188 > 0 ) {
V_98 -> V_191 = F_123 ( V_188 , sizeof( struct V_190 ) ,
V_3 | V_6 ) ;
if ( V_98 -> V_191 == NULL ) {
F_5 ( V_98 ) ;
return F_3 ( - V_4 ) ;
}
}
V_98 -> V_19 = NULL ;
if ( V_189 > 0 ) {
V_98 -> V_19 = F_2 ( V_189 , V_3 | V_6 ) ;
if ( V_98 -> V_19 == NULL ) {
F_5 ( V_98 -> V_191 ) ;
F_5 ( V_98 ) ;
return F_3 ( - V_4 ) ;
}
}
V_98 -> V_187 = V_187 ;
F_124 ( V_192 , & V_98 -> V_193 ) ;
F_21 ( V_2 ) ;
return V_98 ;
}
struct V_97 * F_125 ( int V_187 , int V_188 ,
int V_189 ,
struct V_1 * V_2 )
{
unsigned long V_193 ;
struct V_97 * V_98 ;
char * V_19 ;
int V_194 ;
V_194 = ( sizeof( struct V_97 ) + 7L ) & - 8L ;
if ( V_188 > 0 )
V_194 += V_188 * sizeof( struct V_190 ) ;
if ( V_189 > 0 )
V_194 += V_189 ;
F_126 ( & V_2 -> V_11 , V_193 ) ;
V_98 = (struct V_97 * )
F_127 ( & V_2 -> V_8 , V_194 ) ;
F_128 ( & V_2 -> V_11 , V_193 ) ;
if ( V_98 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_98 , 0 , sizeof( struct V_97 ) ) ;
V_19 = ( char * ) V_98 + ( ( sizeof( struct V_97 ) + 7L ) & - 8L ) ;
V_98 -> V_191 = NULL ;
if ( V_188 > 0 ) {
V_98 -> V_191 = (struct V_190 * ) V_19 ;
V_19 += V_188 * sizeof( struct V_190 ) ;
memset ( V_98 -> V_191 , 0 , V_188 * sizeof( struct V_190 ) ) ;
}
V_98 -> V_19 = NULL ;
if ( V_189 > 0 ) {
V_98 -> V_19 = V_19 ;
memset ( V_98 -> V_19 , 0 , V_189 ) ;
}
V_98 -> V_187 = V_187 ;
F_124 ( V_192 , & V_98 -> V_193 ) ;
F_21 ( V_2 ) ;
return V_98 ;
}
void F_129 ( struct V_97 * V_98 , struct V_1 * V_2 )
{
struct V_190 * V_195 ;
V_195 = V_98 -> V_191 ;
do {
F_130 ( V_195 ) ;
} while ( V_195 ++ -> V_193 & ( V_196 | V_197 ) );
F_5 ( V_98 -> V_191 ) ;
F_5 ( V_98 -> V_19 ) ;
F_5 ( V_98 ) ;
F_23 ( V_2 ) ;
}
void F_131 ( struct V_97 * V_98 , struct V_1 * V_2 )
{
unsigned long V_193 ;
F_126 ( & V_2 -> V_11 , V_193 ) ;
F_132 ( & V_2 -> V_8 , V_98 ) ;
F_128 ( & V_2 -> V_11 , V_193 ) ;
F_23 ( V_2 ) ;
}
static inline int F_133 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
if ( V_98 == NULL )
return - V_168 ;
V_2 = V_98 -> V_108 ;
if ( strncmp ( ( char * ) & V_98 -> V_187 , V_2 -> V_61 -> V_198 , 4 ) ) {
F_39 ( V_58 , V_2 ,
L_38
L_39 ,
V_98 -> V_187 ,
* ( unsigned int * ) V_2 -> V_61 -> V_45 ) ;
return - V_168 ;
}
return 0 ;
}
int F_134 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
int V_199 , V_42 ;
char V_200 [ V_201 ] ;
V_42 = F_133 ( V_98 ) ;
if ( V_42 )
return V_42 ;
V_199 = 0 ;
V_2 = (struct V_1 * ) V_98 -> V_108 ;
while ( ( V_199 < 5 ) && ( V_98 -> V_202 == V_203 ) ) {
V_42 = F_135 ( V_2 -> V_54 , ( long ) V_98 ) ;
switch ( V_42 ) {
case 0 :
V_98 -> V_202 = V_204 ;
V_98 -> V_150 = F_136 () ;
V_98 -> V_205 = 0 ;
F_39 ( V_206 , V_2 ,
L_40 ,
V_98 ) ;
break;
case - V_207 :
F_39 ( V_182 , V_2 , L_1 ,
L_41 ) ;
break;
case - V_208 :
F_39 ( V_182 , V_2 , L_1 ,
L_42 ) ;
break;
case - V_168 :
V_98 -> V_202 = V_209 ;
V_98 -> V_150 = F_136 () ;
V_98 -> V_205 = 0 ;
V_98 -> V_199 = - 1 ;
F_39 ( V_182 , V_2 , L_1 ,
L_43 ) ;
V_42 = 0 ;
break;
case - V_210 :
F_39 ( V_182 , V_2 , L_1 ,
L_44 ) ;
break;
default:
snprintf ( V_200 , V_201 , L_45 , V_42 ) ;
F_137 ( & V_2 -> V_54 -> V_55 , L_46
L_47 , V_200 ) ;
F_138 () ;
break;
}
V_199 ++ ;
}
F_76 ( V_2 ) ;
return V_42 ;
}
int F_139 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
int V_42 ;
char V_200 [ V_201 ] ;
V_42 = F_133 ( V_98 ) ;
if ( V_42 ) {
V_98 -> V_211 = V_42 ;
return V_42 ;
}
V_2 = (struct V_1 * ) V_98 -> V_108 ;
if ( ( ( V_98 -> V_36 &&
F_140 ( V_212 , & V_98 -> V_36 -> V_65 -> V_193 ) ) ||
F_140 ( V_212 , & V_2 -> V_193 ) ) &&
! F_140 ( V_213 , & V_98 -> V_193 ) ) {
F_39 ( V_206 , V_2 , L_48
L_49 , V_98 ) ;
V_98 -> V_202 = V_214 ;
V_98 -> V_211 = - V_88 ;
return - V_88 ;
}
if ( V_98 -> V_199 < 0 ) {
sprintf ( V_200 , L_50 , V_98 ) ;
F_137 ( & V_2 -> V_54 -> V_55 , L_51
L_52 , V_200 ) ;
V_98 -> V_202 = V_214 ;
return - V_208 ;
}
V_98 -> V_149 = F_136 () ;
V_98 -> V_205 = V_215 ;
V_98 -> V_199 -- ;
if ( ! F_140 ( V_216 , & V_98 -> V_193 ) ) {
V_98 -> V_217 &= F_141 ( V_2 ) ;
if ( ! V_98 -> V_217 )
V_98 -> V_217 = F_141 ( V_2 ) ;
}
if ( V_98 -> V_152 == 1 ) {
V_42 = F_142 ( V_2 -> V_54 , V_98 -> V_191 ,
( long ) V_98 , V_98 -> V_217 ) ;
} else {
V_42 = F_143 ( V_2 -> V_54 , V_98 -> V_191 ,
( long ) V_98 , V_98 -> V_217 , 0 ) ;
}
switch ( V_42 ) {
case 0 :
V_98 -> V_202 = V_203 ;
break;
case - V_210 :
F_39 ( V_58 , V_2 , L_1 ,
L_53 ) ;
break;
case - V_218 :
F_39 ( V_58 , V_2 , L_1 ,
L_54 ) ;
break;
case - V_219 :
if ( F_140 ( V_216 , & V_98 -> V_193 ) ) {
F_39 ( V_58 , V_2 ,
L_55 ,
V_98 -> V_217 ) ;
} else if ( V_98 -> V_217 != F_141 ( V_2 ) ) {
V_98 -> V_217 = F_141 ( V_2 ) ;
F_39 ( V_206 , V_2 , L_1 ,
L_56
L_57 ) ;
} else {
F_39 ( V_58 , V_2 , L_1 ,
L_58
L_59 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
F_146 ( V_2 ,
F_147 (
V_2 -> V_54 ) ) ;
}
break;
case - V_207 :
F_39 ( V_58 , V_2 , L_1 ,
L_60 ) ;
break;
case - V_208 :
F_39 ( V_58 , V_2 , L_1 ,
L_61 ) ;
break;
case - V_168 :
F_39 ( V_58 , V_2 , L_1 ,
L_62
L_63 ) ;
break;
default:
snprintf ( V_200 , V_201 , L_64 , V_42 ) ;
F_137 ( & V_2 -> V_54 -> V_55 ,
L_65
L_66 , V_200 ) ;
F_138 () ;
break;
}
V_98 -> V_211 = V_42 ;
return V_42 ;
}
static void V_18 ( unsigned long V_220 )
{
unsigned long V_193 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_220 ;
F_126 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
F_149 ( V_2 , V_221 ) ;
F_128 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
F_76 ( V_2 ) ;
}
void F_150 ( struct V_1 * V_2 , int V_222 )
{
if ( V_222 == 0 )
F_151 ( & V_2 -> V_16 ) ;
else
F_152 ( & V_2 -> V_16 , V_215 + V_222 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_151 ( & V_2 -> V_16 ) ;
}
static void F_153 ( struct V_223 * V_54 ,
unsigned long V_224 )
{
struct V_97 * V_98 ;
struct V_1 * V_2 ;
if ( ! V_224 )
return;
V_98 = (struct V_97 * ) V_224 ;
if ( V_98 -> V_202 != V_203 ) {
F_154 ( V_206 , V_54 ,
L_67
L_68 , V_98 -> V_202 ) ;
return;
}
V_2 = F_155 ( V_54 ) ;
if ( F_29 ( V_2 ) ) {
F_154 ( V_206 , V_54 , L_1 ,
L_69 ) ;
return;
}
if ( ! V_98 -> V_108 ||
V_2 != V_98 -> V_108 ||
strncmp ( V_98 -> V_108 -> V_61 -> V_198 ,
( char * ) & V_98 -> V_187 , 4 ) ) {
F_154 ( V_206 , V_54 , L_1 ,
L_70 ) ;
F_23 ( V_2 ) ;
return;
}
V_98 -> V_202 = V_225 ;
F_46 ( V_2 ) ;
F_76 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_156 ( struct V_1 * V_2 )
{
F_157 ( V_2 ) ;
F_149 ( V_2 , V_221 ) ;
F_76 ( V_2 ) ;
if ( V_2 -> V_36 )
F_63 ( V_2 -> V_36 ) ;
}
static int F_158 ( struct V_226 * V_226 )
{
return ( F_159 ( & V_226 -> V_227 ) &&
( V_226 -> V_227 . V_228 . V_229 == V_230 ||
V_226 -> V_227 . V_228 . V_229 == V_231 ) ) ;
}
void F_160 ( struct V_223 * V_54 , unsigned long V_224 ,
struct V_226 * V_226 )
{
struct V_97 * V_98 , * V_232 ;
struct V_1 * V_2 ;
unsigned long long V_233 ;
int V_234 = 0 ;
int V_235 = 0 ;
T_6 * V_236 = NULL ;
int V_222 ;
V_98 = (struct V_97 * ) V_224 ;
if ( F_29 ( V_226 ) ) {
switch ( F_104 ( V_226 ) ) {
case - V_208 :
if ( V_98 && V_98 -> V_202 == V_204 ) {
V_2 = V_98 -> V_108 ;
V_98 -> V_202 = V_209 ;
F_46 ( V_2 ) ;
F_72 ( & V_237 ) ;
F_76 ( V_2 ) ;
return;
}
break;
case - V_218 :
F_154 ( V_58 , V_54 , L_71
L_72 , V_238 ) ;
break;
default:
F_154 ( V_58 , V_54 , L_71
L_73 , V_238 ,
F_104 ( V_226 ) ) ;
}
F_153 ( V_54 , V_224 ) ;
return;
}
V_233 = F_136 () ;
if ( ! V_98 ||
! ( F_161 ( & V_226 -> V_227 ) == ( V_239 | V_240 ) &&
F_162 ( & V_226 -> V_227 ) == 0 ) ) {
if ( V_98 )
memcpy ( & V_98 -> V_226 , V_226 , sizeof( * V_226 ) ) ;
V_2 = F_155 ( V_54 ) ;
if ( F_29 ( V_2 ) )
return;
if ( V_2 -> V_61 == V_241 ) {
F_23 ( V_2 ) ;
return;
}
V_236 = F_163 ( V_226 ) ;
if ( V_236 ) {
V_235 = ( V_236 [ 1 ] & V_242 ) &&
F_140 ( V_243 , & V_98 -> V_193 ) ;
V_234 = ( V_236 [ 1 ] & V_244 ) &&
F_140 ( V_245 , & V_98 -> V_193 ) ;
}
if ( ! ( V_235 || V_234 ) )
V_2 -> V_61 -> V_246 ( V_2 , V_226 , L_74 ) ;
if ( V_2 -> V_82 & V_247 )
V_2 -> V_61 -> V_248 ( V_2 , V_98 , V_226 ) ;
V_2 -> V_61 -> V_249 ( V_2 , V_98 , V_226 ) ;
F_23 ( V_2 ) ;
}
if ( F_161 ( & V_226 -> V_227 ) & V_250 ) {
V_2 = F_155 ( V_54 ) ;
if ( ! F_29 ( V_2 ) ) {
V_2 -> V_61 -> V_251 ( V_2 ,
V_226 -> V_252 . V_253 . V_254 ) ;
F_23 ( V_2 ) ;
}
}
if ( ! V_98 )
return;
V_2 = (struct V_1 * ) V_98 -> V_108 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_61 -> V_198 , ( char * ) & V_98 -> V_187 , 4 ) ) {
F_154 ( V_206 , V_54 , L_1 ,
L_70 ) ;
return;
}
if ( V_98 -> V_202 == V_204 &&
F_164 ( & V_226 -> V_227 ) & V_255 ) {
V_98 -> V_202 = V_209 ;
F_46 ( V_2 ) ;
F_72 ( & V_237 ) ;
F_76 ( V_2 ) ;
return;
}
if ( V_98 -> V_202 != V_203 ) {
F_39 ( V_206 , V_2 , L_75
L_76 , F_34 ( & V_54 -> V_55 ) , V_98 -> V_202 ) ;
return;
}
V_232 = NULL ;
V_222 = 0 ;
if ( F_161 ( & V_226 -> V_227 ) == ( V_239 | V_240 ) &&
F_162 ( & V_226 -> V_227 ) == 0 ) {
V_98 -> V_202 = V_256 ;
V_98 -> V_150 = V_233 ;
if ( V_98 -> V_257 . V_232 != & V_2 -> V_15 ) {
V_232 = F_165 ( V_98 -> V_257 . V_232 ,
struct V_97 , V_257 ) ;
}
} else {
if ( V_98 -> V_152 && F_158 ( V_226 ) &&
V_2 -> V_61 -> V_258 )
V_2 -> V_61 -> V_258 ( V_2 , V_226 ) ;
if ( ! F_140 ( V_192 , & V_98 -> V_193 ) &&
V_98 -> V_199 > 0 ) {
if ( V_98 -> V_217 == F_141 ( V_2 ) )
F_39 ( V_206 , V_2 ,
L_77
L_78 ,
V_98 -> V_199 ) ;
if ( ! F_140 ( V_216 , & V_98 -> V_193 ) )
V_98 -> V_217 = F_141 ( V_2 ) ;
V_98 -> V_202 = V_225 ;
V_232 = V_98 ;
} else
V_98 -> V_202 = V_214 ;
}
if ( V_232 && ( V_232 -> V_202 == V_225 ) &&
( ! V_2 -> V_259 ) ) {
if ( V_2 -> V_61 -> V_260 ( V_232 ) == 0 )
V_222 = V_232 -> V_222 ;
}
if ( V_222 != 0 )
F_150 ( V_2 , V_222 ) ;
else
F_46 ( V_2 ) ;
F_76 ( V_2 ) ;
}
enum V_261 F_166 ( struct V_223 * V_54 , struct V_226 * V_226 )
{
struct V_1 * V_2 ;
V_2 = F_155 ( V_54 ) ;
if ( F_29 ( V_2 ) )
goto V_71;
if ( F_140 ( V_262 , & V_2 -> V_193 ) ||
V_2 -> V_28 != V_2 -> V_30 ||
! V_2 -> V_61 -> V_249 ) {
F_23 ( V_2 ) ;
goto V_71;
}
if ( V_2 -> V_61 -> V_246 )
V_2 -> V_61 -> V_246 ( V_2 , V_226 , L_79 ) ;
V_2 -> V_61 -> V_249 ( V_2 , NULL , V_226 ) ;
F_23 ( V_2 ) ;
V_71:
return V_263 ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_97 * V_264 )
{
struct V_101 * V_102 , * V_265 ;
struct V_97 * V_98 ;
if ( ! V_264 -> V_36 )
return;
F_168 (l, n, &device->ccw_queue) {
V_98 = F_165 ( V_102 , struct V_97 , V_257 ) ;
if ( V_98 -> V_202 == V_225 &&
V_264 -> V_36 == V_98 -> V_36 ) {
V_98 -> V_202 = V_209 ;
}
}
}
static void F_169 ( struct V_1 * V_2 ,
struct V_101 * V_266 )
{
struct V_101 * V_102 , * V_265 ;
struct V_97 * V_98 ;
F_168 (l, n, &device->ccw_queue) {
V_98 = F_165 ( V_102 , struct V_97 , V_257 ) ;
if ( V_98 -> V_202 == V_225 ||
V_98 -> V_202 == V_203 ||
V_98 -> V_202 == V_204 )
continue;
if ( V_98 -> V_202 == V_214 ) {
F_167 ( V_2 , V_98 ) ;
}
F_170 ( & V_98 -> V_257 , V_266 ) ;
}
}
static void F_171 ( struct V_1 * V_2 ,
struct V_101 * V_266 )
{
struct V_101 * V_102 , * V_265 ;
struct V_97 * V_98 ;
struct V_35 * V_36 ;
void (* F_172)( struct V_97 * , void * V_19 );
void * V_267 ;
char V_200 [ V_201 ] ;
F_168 (l, n, final_queue) {
V_98 = F_165 ( V_102 , struct V_97 , V_257 ) ;
F_173 ( & V_98 -> V_257 ) ;
V_36 = V_98 -> V_36 ;
F_172 = V_98 -> F_172 ;
V_267 = V_98 -> V_267 ;
if ( V_36 )
F_96 ( & V_36 -> V_40 ) ;
switch ( V_98 -> V_202 ) {
case V_256 :
V_98 -> V_202 = V_268 ;
break;
case V_214 :
V_98 -> V_202 = V_269 ;
break;
case V_209 :
V_98 -> V_202 = V_270 ;
break;
default:
snprintf ( V_200 , V_201 , L_80 , V_98 , V_98 -> V_202 ) ;
F_137 ( & V_2 -> V_54 -> V_55 ,
L_65
L_66 , V_200 ) ;
F_138 () ;
}
if ( V_98 -> F_172 != NULL )
( F_172 ) ( V_98 , V_267 ) ;
if ( V_36 )
F_97 ( & V_36 -> V_40 ) ;
}
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
if ( F_56 ( & V_2 -> V_15 ) )
return;
V_98 = F_165 ( V_2 -> V_15 . V_232 , struct V_97 , V_257 ) ;
if ( ( V_98 -> V_202 == V_203 && V_98 -> V_222 != 0 ) &&
( F_175 ( V_215 , V_98 -> V_222 + V_98 -> V_205 ) ) ) {
if ( F_140 ( V_271 , & V_2 -> V_193 ) ) {
V_98 -> V_199 ++ ;
}
if ( V_2 -> V_61 -> V_272 ( V_98 ) != 0 ) {
F_137 ( & V_2 -> V_54 -> V_55 ,
L_81
L_82 ,
V_98 , ( V_98 -> V_222 / V_273 ) ) ;
V_98 -> V_222 += 5 * V_273 ;
F_150 ( V_2 , 5 * V_273 ) ;
} else {
F_137 ( & V_2 -> V_54 -> V_55 ,
L_83
L_84 , V_98 , ( V_98 -> V_222 / V_273 ) ,
V_98 -> V_199 ) ;
}
}
}
static int F_176 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
int V_274 = ~ ( V_275 | V_276 ) ;
if ( F_140 ( V_262 , & V_2 -> V_193 ) ) {
return 1 ;
}
if ( V_2 -> V_259 ) {
if ( V_2 -> V_259 & V_274 ) {
return 1 ;
}
if ( ! F_140 ( V_216 , & V_98 -> V_193 ) ) {
return 1 ;
}
}
return 0 ;
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
int V_42 ;
if ( F_56 ( & V_2 -> V_15 ) )
return;
V_98 = F_165 ( V_2 -> V_15 . V_232 , struct V_97 , V_257 ) ;
if ( V_98 -> V_202 != V_225 )
return;
if ( F_176 ( V_2 , V_98 ) ) {
V_98 -> V_211 = - V_67 ;
V_98 -> V_202 = V_209 ;
F_76 ( V_2 ) ;
return;
}
V_42 = V_2 -> V_61 -> V_260 ( V_98 ) ;
if ( V_42 == 0 )
F_150 ( V_2 , V_98 -> V_222 ) ;
else if ( V_42 == - V_219 ) {
F_76 ( V_2 ) ;
} else
F_150 ( V_2 , 50 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
int V_42 ;
if ( ! F_179 ( V_2 ) )
return;
if ( V_2 -> V_259 &
~ ( V_275 | V_276 ) )
return;
V_42 = V_2 -> V_61 -> V_277 ( V_2 ,
F_179 ( V_2 ) ) ;
if ( V_42 )
F_150 ( V_2 , 50 ) ;
else
F_180 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_97 * V_98 , * V_265 ;
int V_42 ;
struct V_101 V_278 ;
F_12 ( & V_278 ) ;
F_181 ( F_148 ( V_2 -> V_54 ) ) ;
V_42 = 0 ;
F_182 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_98 -> V_202 ) {
case V_203 :
V_42 = V_2 -> V_61 -> V_272 ( V_98 ) ;
if ( V_42 ) {
F_137 ( & V_2 -> V_54 -> V_55 ,
L_85
L_86 , V_98 ) ;
goto V_279;
}
break;
case V_225 :
V_98 -> V_150 = F_136 () ;
V_98 -> V_202 = V_209 ;
break;
default:
break;
}
F_170 ( & V_98 -> V_257 , & V_278 ) ;
}
V_279:
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
F_182 (cqr, n, &flush_queue, devlist)
F_84 ( V_237 ,
( V_98 -> V_202 != V_204 ) ) ;
F_171 ( V_2 , & V_278 ) ;
return V_42 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_101 V_266 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_266 ) ;
F_181 ( F_148 ( V_2 -> V_54 ) ) ;
F_174 ( V_2 ) ;
F_169 ( V_2 , & V_266 ) ;
F_178 ( V_2 ) ;
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
F_171 ( V_2 , & V_266 ) ;
F_181 ( F_148 ( V_2 -> V_54 ) ) ;
F_177 ( V_2 ) ;
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
if ( F_184 ( & V_280 ) )
F_72 ( & V_280 ) ;
F_23 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( F_185 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_186 ( & V_2 -> V_13 ) ;
}
void F_187 ( struct V_1 * V_2 , int V_281 )
{
V_2 -> V_259 |= V_281 ;
}
void F_149 ( struct V_1 * V_2 , int V_281 )
{
V_2 -> V_259 &= ~ V_281 ;
if ( ! V_2 -> V_259 )
F_72 ( & V_282 ) ;
}
void F_188 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
unsigned long V_193 ;
V_2 = V_98 -> V_108 ;
F_126 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
V_98 -> V_202 = V_225 ;
F_189 ( & V_98 -> V_257 , & V_2 -> V_15 ) ;
F_76 ( V_2 ) ;
F_128 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
}
void F_190 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
unsigned long V_193 ;
V_2 = V_98 -> V_108 ;
F_126 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
V_98 -> V_202 = V_225 ;
F_191 ( & V_98 -> V_257 , & V_2 -> V_15 ) ;
F_76 ( V_2 ) ;
F_128 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
}
void F_192 ( struct V_97 * V_98 , void * V_19 )
{
F_181 ( F_148 ( V_98 -> V_108 -> V_54 ) ) ;
V_98 -> V_267 = V_283 ;
F_183 ( F_148 ( V_98 -> V_108 -> V_54 ) ) ;
F_72 ( & V_282 ) ;
}
static inline int F_193 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
int V_42 ;
V_2 = V_98 -> V_108 ;
F_181 ( F_148 ( V_2 -> V_54 ) ) ;
V_42 = ( V_98 -> V_267 == V_283 ) ;
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
return V_42 ;
}
static int F_194 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
T_7 V_284 ;
if ( V_98 -> V_202 == V_285 )
return 0 ;
V_2 = V_98 -> V_108 ;
if ( F_140 ( V_192 , & V_98 -> V_193 ) ) {
if ( V_98 -> V_202 == V_270 ) {
V_2 -> V_61 -> V_286 ( V_98 ) ;
return 1 ;
}
if ( V_98 -> V_202 == V_269 ) {
V_284 = V_2 -> V_61 -> V_287 ( V_98 ) ;
V_284 ( V_98 ) ;
return 1 ;
}
if ( V_98 -> V_202 == V_288 )
F_195 ( V_98 , & V_98 -> V_226 ) ;
if ( V_98 -> V_289 ) {
F_196 ( V_2 , V_98 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_197 ( struct V_97 * V_98 )
{
if ( F_140 ( V_192 , & V_98 -> V_193 ) ) {
if ( V_98 -> V_289 )
return 1 ;
return ( ( V_98 -> V_202 != V_268 ) &&
( V_98 -> V_202 != V_288 ) ) ;
} else
return ( V_98 -> V_202 == V_285 ) ;
}
static int F_198 ( struct V_97 * V_290 , int V_291 )
{
struct V_1 * V_2 ;
int V_42 ;
struct V_101 V_15 ;
struct V_97 * V_98 ;
F_12 ( & V_15 ) ;
V_290 -> V_202 = V_285 ;
V_2 = V_290 -> V_108 ;
F_189 ( & V_290 -> V_292 , & V_15 ) ;
for ( V_98 = V_290 ; F_197 ( V_98 ) ;
V_98 = F_199 ( & V_15 ,
struct V_97 , V_292 ) ) {
if ( F_194 ( V_98 ) )
continue;
if ( V_98 -> V_202 != V_285 )
continue;
if ( F_140 ( V_212 , & V_2 -> V_193 ) &&
! F_140 ( V_213 , & V_98 -> V_193 ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_88 ;
continue;
}
if ( V_2 -> V_259 & ~ V_221 &&
F_140 ( V_293 , & V_98 -> V_193 ) &&
( ! F_200 ( V_2 ) ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_294 ;
continue;
}
if ( F_140 ( V_262 , & V_2 -> V_193 ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_207 ;
continue;
}
if ( ! F_140 ( V_216 , & V_98 -> V_193 ) ) {
if ( V_291 ) {
V_42 = F_201 (
V_282 , ! ( V_2 -> V_259 ) ) ;
if ( V_42 == - V_295 ) {
V_98 -> V_202 = V_288 ;
V_290 -> V_211 = V_42 ;
continue;
}
} else
F_84 ( V_282 , ! ( V_2 -> V_259 ) ) ;
}
if ( ! V_98 -> F_172 )
V_98 -> F_172 = F_192 ;
V_98 -> V_267 = V_296 ;
F_190 ( V_98 ) ;
if ( V_291 ) {
V_42 = F_201 (
V_282 , F_193 ( V_98 ) ) ;
if ( V_42 == - V_295 ) {
F_202 ( V_98 ) ;
F_84 ( V_282 ,
F_193 ( V_98 ) ) ;
V_98 -> V_202 = V_288 ;
V_290 -> V_211 = V_42 ;
continue;
}
} else
F_84 ( V_282 , F_193 ( V_98 ) ) ;
}
V_290 -> V_151 = F_136 () ;
if ( ( V_290 -> V_202 != V_268 ) &&
( V_290 -> V_211 != - V_295 ) )
F_195 ( V_290 , & V_290 -> V_226 ) ;
if ( V_290 -> V_202 == V_268 )
V_42 = 0 ;
else if ( V_290 -> V_211 )
V_42 = V_290 -> V_211 ;
else
V_42 = - V_208 ;
return V_42 ;
}
static inline int F_203 ( struct V_101 * V_15 )
{
struct V_97 * V_98 ;
F_204 (cqr, ccw_queue, blocklist) {
if ( V_98 -> V_267 != V_283 )
return 0 ;
}
return 1 ;
}
static int F_205 ( struct V_101 * V_15 , int V_291 )
{
struct V_1 * V_2 ;
struct V_97 * V_98 , * V_265 ;
T_6 * V_236 = NULL ;
int V_42 ;
V_297:
F_182 (cqr, n, ccw_queue, blocklist) {
V_2 = V_98 -> V_108 ;
if ( V_98 -> V_202 != V_285 )
continue;
if ( F_140 ( V_212 , & V_2 -> V_193 ) &&
! F_140 ( V_213 , & V_98 -> V_193 ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_88 ;
continue;
}
if ( V_2 -> V_259 & ~ V_221 &&
F_140 ( V_293 , & V_98 -> V_193 ) &&
! F_200 ( V_2 ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_67 ;
continue;
}
if ( V_291 ) {
V_42 = F_201 (
V_282 , ! V_2 -> V_259 ) ;
if ( V_42 == - V_295 ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = V_42 ;
continue;
}
} else
F_84 ( V_282 , ! ( V_2 -> V_259 ) ) ;
if ( ! V_98 -> F_172 )
V_98 -> F_172 = F_192 ;
V_98 -> V_267 = V_296 ;
F_190 ( V_98 ) ;
}
F_84 ( V_282 , F_203 ( V_15 ) ) ;
V_42 = 0 ;
F_182 (cqr, n, ccw_queue, blocklist) {
V_236 = F_163 ( & V_98 -> V_226 ) ;
if ( V_236 && V_236 [ 1 ] & V_242 &&
F_140 ( V_243 , & V_98 -> V_193 ) )
continue;
if ( F_162 ( & V_98 -> V_226 . V_227 ) == 0x40 &&
F_140 ( V_298 , & V_98 -> V_193 ) )
continue;
if ( V_98 -> V_108 != V_98 -> V_299 && ! V_98 -> V_289 &&
( V_98 -> V_202 == V_270 ||
V_98 -> V_202 == V_269 ) )
return - V_67 ;
if ( F_194 ( V_98 ) )
goto V_297;
}
return 0 ;
}
int F_206 ( struct V_97 * V_98 )
{
return F_198 ( V_98 , 0 ) ;
}
int F_207 ( struct V_101 * V_15 )
{
return F_205 ( V_15 , 0 ) ;
}
int F_208 ( struct V_97 * V_98 )
{
return F_198 ( V_98 , 1 ) ;
}
static inline int F_209 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
int V_42 ;
if ( F_56 ( & V_2 -> V_15 ) )
return 0 ;
V_98 = F_165 ( V_2 -> V_15 . V_232 , struct V_97 , V_257 ) ;
V_42 = V_2 -> V_61 -> V_272 ( V_98 ) ;
if ( ! V_42 )
V_98 -> V_199 ++ ;
return V_42 ;
}
int F_210 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
int V_42 ;
V_2 = V_98 -> V_108 ;
if ( F_140 ( V_212 , & V_2 -> V_193 ) &&
! F_140 ( V_213 , & V_98 -> V_193 ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_88 ;
return - V_208 ;
}
F_181 ( F_148 ( V_2 -> V_54 ) ) ;
V_42 = F_209 ( V_2 ) ;
if ( V_42 ) {
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
return V_42 ;
}
V_98 -> F_172 = F_192 ;
V_98 -> V_267 = V_296 ;
V_98 -> V_202 = V_225 ;
F_189 ( & V_98 -> V_257 , V_2 -> V_15 . V_232 ) ;
F_76 ( V_2 ) ;
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
F_84 ( V_282 , F_193 ( V_98 ) ) ;
if ( V_98 -> V_202 == V_268 )
V_42 = 0 ;
else if ( V_98 -> V_211 )
V_42 = V_98 -> V_211 ;
else
V_42 = - V_208 ;
F_76 ( V_2 ) ;
if ( V_2 -> V_36 )
F_63 ( V_2 -> V_36 ) ;
return V_42 ;
}
int F_202 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = V_98 -> V_108 ;
unsigned long V_193 ;
int V_42 ;
V_42 = 0 ;
F_126 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
switch ( V_98 -> V_202 ) {
case V_225 :
V_98 -> V_202 = V_209 ;
if ( V_98 -> V_267 == V_296 )
V_98 -> V_267 = V_283 ;
break;
case V_203 :
V_42 = V_2 -> V_61 -> V_272 ( V_98 ) ;
if ( V_42 ) {
F_137 ( & V_2 -> V_54 -> V_55 ,
L_87 ,
V_98 , V_42 ) ;
} else {
V_98 -> V_150 = F_136 () ;
}
break;
default:
break;
}
F_128 ( F_148 ( V_2 -> V_54 ) , V_193 ) ;
F_76 ( V_2 ) ;
return V_42 ;
}
static void V_41 ( unsigned long V_220 )
{
unsigned long V_193 ;
struct V_35 * V_36 ;
V_36 = (struct V_35 * ) V_220 ;
F_126 ( F_148 ( V_36 -> V_65 -> V_54 ) , V_193 ) ;
F_149 ( V_36 -> V_65 , V_221 ) ;
F_128 ( F_148 ( V_36 -> V_65 -> V_54 ) , V_193 ) ;
F_63 ( V_36 ) ;
}
void F_211 ( struct V_35 * V_36 , int V_222 )
{
if ( V_222 == 0 )
F_151 ( & V_36 -> V_16 ) ;
else
F_152 ( & V_36 -> V_16 , V_215 + V_222 ) ;
}
void F_44 ( struct V_35 * V_36 )
{
F_151 ( & V_36 -> V_16 ) ;
}
static void F_196 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
T_7 V_284 ;
if ( V_98 -> V_202 == V_268 )
F_39 ( V_300 , V_2 , L_1 , L_88 ) ;
else
F_137 ( & V_2 -> V_54 -> V_55 , L_89 ) ;
V_284 = V_2 -> V_61 -> V_301 ( V_98 ) ;
V_284 ( V_98 ) ;
}
static void F_212 ( struct V_35 * V_36 )
{
struct V_302 * V_303 ;
struct V_99 * V_100 ;
struct V_97 * V_98 ;
struct V_1 * V_299 ;
unsigned long V_193 ;
V_303 = V_36 -> V_302 ;
V_299 = V_36 -> V_65 ;
if ( V_303 == NULL )
return;
if ( V_299 -> V_28 < V_74 ) {
while ( ( V_100 = F_213 ( V_36 -> V_302 ) ) )
F_214 ( V_100 , - V_208 ) ;
return;
}
if ( V_299 -> V_259 && ! ( V_299 -> V_82 & V_304 ) )
return;
while ( ( V_100 = F_215 ( V_303 ) ) ) {
if ( V_299 -> V_82 & V_305 &&
F_88 ( V_100 ) == V_306 ) {
F_39 ( V_182 , V_299 ,
L_90 ,
V_100 ) ;
F_216 ( V_100 ) ;
F_214 ( V_100 , - V_208 ) ;
continue;
}
if ( F_140 ( V_307 , & V_299 -> V_193 ) &&
( V_299 -> V_82 & V_304 ||
F_217 ( V_100 ) ) ) {
F_39 ( V_182 , V_299 ,
L_91 ,
V_100 ) ;
F_216 ( V_100 ) ;
F_214 ( V_100 , - V_218 ) ;
continue;
}
V_98 = V_299 -> V_61 -> V_308 ( V_299 , V_36 , V_100 ) ;
if ( F_29 ( V_98 ) ) {
if ( F_104 ( V_98 ) == - V_210 )
break;
if ( F_104 ( V_98 ) == - V_4 )
break;
if ( F_104 ( V_98 ) == - V_67 ) {
if ( ! F_56 ( & V_36 -> V_15 ) )
break;
F_126 (
F_148 ( V_299 -> V_54 ) , V_193 ) ;
F_187 ( V_299 ,
V_221 ) ;
F_128 (
F_148 ( V_299 -> V_54 ) , V_193 ) ;
F_211 ( V_36 , V_273 / 2 ) ;
break;
}
F_39 ( V_182 , V_299 ,
L_92
L_93 ,
F_104 ( V_98 ) , V_100 ) ;
F_216 ( V_100 ) ;
F_214 ( V_100 , - V_208 ) ;
continue;
}
V_98 -> V_267 = ( void * ) V_100 ;
V_98 -> V_202 = V_285 ;
V_100 -> V_309 = V_98 ;
F_216 ( V_100 ) ;
F_191 ( & V_98 -> V_292 , & V_36 -> V_15 ) ;
F_12 ( & V_98 -> V_257 ) ;
F_85 ( V_36 , V_98 , V_100 ) ;
}
}
static void F_218 ( struct V_97 * V_98 )
{
struct V_99 * V_100 ;
int V_202 ;
int error = 0 ;
V_100 = (struct V_99 * ) V_98 -> V_267 ;
F_92 ( V_98 -> V_36 , V_98 , V_100 ) ;
V_202 = V_98 -> V_36 -> V_65 -> V_61 -> V_310 ( V_98 , V_100 ) ;
if ( V_202 < 0 )
error = V_202 ;
else if ( V_202 == 0 ) {
if ( V_98 -> V_211 == - V_88 )
error = - V_311 ;
else if ( V_98 -> V_211 == - V_294 ||
V_98 -> V_211 == - V_218 )
error = V_98 -> V_211 ;
else
error = - V_208 ;
}
F_214 ( V_100 , error ) ;
}
static void F_219 ( struct V_35 * V_36 ,
struct V_101 * V_266 )
{
struct V_101 * V_102 , * V_265 ;
struct V_97 * V_98 ;
T_7 V_284 ;
unsigned long V_193 ;
struct V_1 * V_65 = V_36 -> V_65 ;
V_312:
F_168 (l, n, &block->ccw_queue) {
V_98 = F_165 ( V_102 , struct V_97 , V_292 ) ;
if ( V_98 -> V_202 != V_268 &&
V_98 -> V_202 != V_288 &&
V_98 -> V_202 != V_269 &&
V_98 -> V_202 != V_270 )
continue;
if ( V_98 -> V_202 == V_270 ) {
V_65 -> V_61 -> V_286 ( V_98 ) ;
goto V_312;
}
if ( V_98 -> V_202 == V_269 ) {
V_284 = V_65 -> V_61 -> V_287 ( V_98 ) ;
if ( F_29 ( V_284 ( V_98 ) ) )
continue;
goto V_312;
}
if ( V_98 -> V_202 == V_288 ) {
F_195 ( V_98 , & V_98 -> V_226 ) ;
}
if ( F_200 ( V_65 ) &&
V_98 -> V_202 == V_288 ) {
F_220 ( V_65 , V_98 , V_313 ) ;
V_98 -> V_202 = V_285 ;
V_98 -> V_199 = 255 ;
F_126 ( F_148 ( V_65 -> V_54 ) , V_193 ) ;
F_187 ( V_65 , V_314 ) ;
F_128 ( F_148 ( V_65 -> V_54 ) ,
V_193 ) ;
goto V_312;
}
if ( V_98 -> V_289 ) {
F_196 ( V_65 , V_98 ) ;
goto V_312;
}
V_98 -> V_151 = F_136 () ;
F_170 ( & V_98 -> V_292 , V_266 ) ;
}
}
static void F_221 ( struct V_97 * V_98 , void * V_19 )
{
F_63 ( V_98 -> V_36 ) ;
}
static void F_222 ( struct V_35 * V_36 )
{
struct V_97 * V_98 ;
if ( F_56 ( & V_36 -> V_15 ) )
return;
F_204 (cqr, &block->ccw_queue, blocklist) {
if ( V_98 -> V_202 != V_285 )
continue;
if ( F_140 ( V_212 , & V_36 -> V_65 -> V_193 ) &&
! F_140 ( V_213 , & V_98 -> V_193 ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_88 ;
F_63 ( V_36 ) ;
continue;
}
if ( V_36 -> V_65 -> V_259 & ~ V_221 &&
F_140 ( V_293 , & V_98 -> V_193 ) &&
( ! F_200 ( V_36 -> V_65 ) ) ) {
V_98 -> V_202 = V_288 ;
V_98 -> V_211 = - V_294 ;
F_63 ( V_36 ) ;
continue;
}
if ( V_36 -> V_65 -> V_259 )
return;
if ( ! V_98 -> V_108 )
V_98 -> V_108 = V_36 -> V_65 ;
V_98 -> F_172 = F_221 ;
F_190 ( V_98 ) ;
}
}
static void V_39 ( struct V_35 * V_36 )
{
struct V_101 V_266 ;
struct V_101 * V_102 , * V_265 ;
struct V_97 * V_98 ;
F_10 ( & V_36 -> V_12 , 0 ) ;
F_12 ( & V_266 ) ;
F_87 ( & V_36 -> V_40 ) ;
F_219 ( V_36 , & V_266 ) ;
F_89 ( & V_36 -> V_40 ) ;
F_181 ( & V_36 -> V_38 ) ;
F_168 (l, n, &final_queue) {
V_98 = F_165 ( V_102 , struct V_97 , V_292 ) ;
F_173 ( & V_98 -> V_292 ) ;
F_218 ( V_98 ) ;
}
F_87 ( & V_36 -> V_40 ) ;
F_212 ( V_36 ) ;
F_222 ( V_36 ) ;
F_89 ( & V_36 -> V_40 ) ;
F_183 ( & V_36 -> V_38 ) ;
if ( F_184 ( & V_280 ) )
F_72 ( & V_280 ) ;
F_23 ( V_36 -> V_65 ) ;
}
static void F_223 ( struct V_97 * V_98 , void * V_19 )
{
F_72 ( & V_237 ) ;
}
static int F_224 ( struct V_97 * V_98 )
{
struct V_35 * V_36 = V_98 -> V_36 ;
struct V_99 * V_100 ;
unsigned long V_193 ;
if ( ! V_36 )
return - V_168 ;
F_126 ( & V_36 -> V_38 , V_193 ) ;
V_100 = (struct V_99 * ) V_98 -> V_267 ;
F_225 ( V_36 -> V_302 , V_100 ) ;
F_128 ( & V_36 -> V_38 , V_193 ) ;
return 0 ;
}
static int F_58 ( struct V_35 * V_36 )
{
struct V_97 * V_98 , * V_265 ;
int V_42 , V_170 ;
struct V_101 V_278 ;
F_12 ( & V_278 ) ;
F_96 ( & V_36 -> V_40 ) ;
V_42 = 0 ;
V_312:
F_182 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_98 -> V_202 >= V_225 )
V_42 = F_202 ( V_98 ) ;
if ( V_42 < 0 )
break;
V_98 -> F_172 = F_223 ;
for ( V_170 = 0 ; V_98 != NULL ; V_98 = V_98 -> V_289 , V_170 ++ )
F_170 ( & V_98 -> V_292 , & V_278 ) ;
if ( V_170 > 1 )
goto V_312;
}
F_97 ( & V_36 -> V_40 ) ;
V_315:
F_182 (cqr, n, &flush_queue, blocklist) {
F_84 ( V_237 , ( V_98 -> V_202 < V_225 ) ) ;
if ( V_98 -> V_289 ) {
F_96 ( & V_36 -> V_40 ) ;
F_196 ( V_36 -> V_65 , V_98 ) ;
F_97 ( & V_36 -> V_40 ) ;
goto V_315;
}
F_181 ( & V_36 -> V_38 ) ;
V_98 -> V_151 = F_136 () ;
F_173 ( & V_98 -> V_292 ) ;
F_218 ( V_98 ) ;
F_183 ( & V_36 -> V_38 ) ;
}
return V_42 ;
}
void F_63 ( struct V_35 * V_36 )
{
if ( F_185 ( & V_36 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_36 -> V_65 ) ;
F_186 ( & V_36 -> V_13 ) ;
}
static void F_226 ( struct V_302 * V_303 )
{
struct V_35 * V_36 ;
V_36 = V_303 -> V_316 ;
F_87 ( & V_36 -> V_40 ) ;
F_212 ( V_36 ) ;
F_222 ( V_36 ) ;
F_89 ( & V_36 -> V_40 ) ;
}
enum V_317 F_227 ( struct V_99 * V_100 )
{
struct V_97 * V_98 = V_100 -> V_309 ;
struct V_35 * V_36 = V_100 -> V_318 -> V_316 ;
struct V_1 * V_2 ;
int V_42 = 0 ;
if ( ! V_98 )
return V_319 ;
V_2 = V_98 -> V_108 ? V_98 -> V_108 : V_36 -> V_65 ;
if ( ! V_2 -> V_320 )
return V_321 ;
F_39 ( V_58 , V_2 ,
L_94 ,
V_98 , V_98 -> V_202 ) ;
F_87 ( & V_36 -> V_40 ) ;
F_87 ( F_148 ( V_2 -> V_54 ) ) ;
V_98 -> V_199 = - 1 ;
V_98 -> V_211 = - V_218 ;
if ( V_98 -> V_202 >= V_225 ) {
F_89 ( F_148 ( V_2 -> V_54 ) ) ;
V_42 = F_202 ( V_98 ) ;
} else if ( V_98 -> V_202 == V_285 ||
V_98 -> V_202 == V_269 ) {
V_98 -> V_202 = V_270 ;
F_89 ( F_148 ( V_2 -> V_54 ) ) ;
} else if ( V_98 -> V_202 == V_322 ) {
struct V_97 * V_323 , * V_324 , * V_325 ;
F_182 (searchcqr, nextcqr,
&block->ccw_queue, blocklist) {
V_325 = V_323 ;
while ( V_325 -> V_289 )
V_325 = V_325 -> V_289 ;
if ( V_325 != V_98 )
continue;
V_323 -> V_199 = - 1 ;
V_323 -> V_211 = - V_218 ;
if ( V_323 -> V_202 >= V_225 ) {
F_89 ( F_148 ( V_2 -> V_54 ) ) ;
V_42 = F_202 ( V_323 ) ;
F_87 ( F_148 ( V_2 -> V_54 ) ) ;
} else if ( ( V_323 -> V_202 == V_285 ) ||
( V_323 -> V_202 == V_269 ) ) {
V_323 -> V_202 = V_270 ;
V_42 = 0 ;
} else if ( V_323 -> V_202 == V_322 ) {
continue;
}
break;
}
F_89 ( F_148 ( V_2 -> V_54 ) ) ;
}
F_63 ( V_36 ) ;
F_89 ( & V_36 -> V_40 ) ;
return V_42 ? V_321 : V_319 ;
}
static int F_22 ( struct V_35 * V_36 )
{
V_36 -> V_302 = F_228 ( F_226 ,
& V_36 -> V_38 ) ;
if ( V_36 -> V_302 == NULL )
return - V_4 ;
V_36 -> V_302 -> V_316 = V_36 ;
return 0 ;
}
static void F_52 ( struct V_35 * V_36 )
{
struct V_302 * V_318 = V_36 -> V_302 ;
int V_326 ;
if ( V_36 -> V_65 -> V_82 & V_83 ) {
V_326 = 2048 ;
} else {
V_326 = V_36 -> V_65 -> V_61 -> V_327 << V_36 -> V_73 ;
}
F_229 ( V_328 , V_318 ) ;
V_318 -> V_329 . V_330 = V_326 ;
F_230 ( V_318 , V_36 -> V_76 ) ;
F_231 ( V_318 , V_326 ) ;
F_232 ( V_318 , V_331 ) ;
F_233 ( V_318 , V_9 ) ;
F_234 ( V_318 , V_9 - 1 ) ;
}
static void F_26 ( struct V_35 * V_36 )
{
if ( V_36 -> V_302 ) {
F_235 ( V_36 -> V_302 ) ;
V_36 -> V_302 = NULL ;
}
}
static void F_59 ( struct V_35 * V_36 )
{
struct V_99 * V_100 ;
if ( ! V_36 -> V_302 )
return;
F_181 ( & V_36 -> V_38 ) ;
while ( ( V_100 = F_213 ( V_36 -> V_302 ) ) )
F_214 ( V_100 , - V_208 ) ;
F_183 ( & V_36 -> V_38 ) ;
}
static int F_236 ( struct V_332 * V_84 , T_8 V_176 )
{
struct V_1 * V_65 ;
int V_42 ;
V_65 = F_237 ( V_84 -> V_85 ) ;
if ( ! V_65 )
return - V_207 ;
F_238 ( & V_65 -> V_36 -> V_37 ) ;
if ( F_140 ( V_262 , & V_65 -> V_193 ) ) {
V_42 = - V_207 ;
goto V_333;
}
if ( ! F_239 ( V_65 -> V_61 -> V_334 ) ) {
V_42 = - V_168 ;
goto V_333;
}
if ( V_95 ) {
F_240 ( & V_65 -> V_54 -> V_55 ,
L_95
L_96 ) ;
V_42 = - V_88 ;
goto V_71;
}
if ( V_65 -> V_28 <= V_60 ) {
F_39 ( V_182 , V_65 , L_97 ,
L_98 ) ;
V_42 = - V_207 ;
goto V_71;
}
if ( ( V_176 & V_335 ) &&
( F_140 ( V_336 , & V_65 -> V_193 ) ||
( V_65 -> V_82 & V_305 ) ) ) {
V_42 = - V_337 ;
goto V_71;
}
F_23 ( V_65 ) ;
return 0 ;
V_71:
F_241 ( V_65 -> V_61 -> V_334 ) ;
V_333:
F_242 ( & V_65 -> V_36 -> V_37 ) ;
F_23 ( V_65 ) ;
return V_42 ;
}
static void F_243 ( struct V_63 * V_64 , T_8 V_176 )
{
struct V_1 * V_65 = F_237 ( V_64 ) ;
if ( V_65 ) {
F_242 ( & V_65 -> V_36 -> V_37 ) ;
F_241 ( V_65 -> V_61 -> V_334 ) ;
F_23 ( V_65 ) ;
}
}
static int F_244 ( struct V_332 * V_84 , struct V_338 * V_339 )
{
struct V_1 * V_65 ;
V_65 = F_237 ( V_84 -> V_85 ) ;
if ( ! V_65 )
return - V_207 ;
if ( ! V_65 -> V_61 ||
! V_65 -> V_61 -> V_340 ) {
F_23 ( V_65 ) ;
return - V_168 ;
}
V_65 -> V_61 -> V_340 ( V_65 -> V_36 , V_339 ) ;
V_339 -> V_341 = F_245 ( V_84 ) >> V_65 -> V_36 -> V_73 ;
F_23 ( V_65 ) ;
return 0 ;
}
static void
F_246 ( void )
{
#ifdef F_247
F_248 () ;
#endif
F_249 () ;
if ( V_342 != NULL ) {
F_250 ( V_342 ) ;
V_342 = NULL ;
}
F_251 () ;
F_252 () ;
if ( V_343 != NULL ) {
F_48 ( V_343 ) ;
V_343 = NULL ;
}
F_115 () ;
}
int F_253 ( struct V_1 * V_2 )
{
struct V_344 V_345 ;
struct V_346 V_347 ;
int V_42 ;
if ( ! V_348 )
return 0 ;
F_254 ( V_2 -> V_54 , & V_345 ) ;
memset ( & V_347 , 0 , sizeof( V_347 ) ) ;
V_347 . V_349 = V_345 . V_350 ;
V_347 . V_351 = sizeof( V_347 ) ;
V_42 = V_346 ( & V_347 ) ;
if ( V_42 == 0 || V_42 == 2 ) {
return V_347 . V_352 & 0x80 ;
} else {
F_117 ( V_58 , L_99 ,
V_345 . V_350 , V_42 ) ;
return 0 ;
}
}
static void F_255 ( void * V_19 , T_9 V_353 )
{
struct V_223 * V_54 = V_19 ;
int V_354 ;
V_354 = F_256 ( V_54 ) ;
if ( V_354 )
F_257 ( L_100 ,
F_34 ( & V_54 -> V_55 ) , V_354 ) ;
}
int F_258 ( struct V_223 * V_54 ,
struct V_355 * V_61 )
{
int V_354 ;
V_354 = F_259 ( V_54 ) ;
if ( V_354 ) {
F_154 ( V_58 , V_54 , L_1 ,
L_101
L_102 ) ;
return V_354 ;
}
V_54 -> V_356 = & F_160 ;
if ( ( F_260 ( V_54 , V_357 ) > 0 ) ||
( V_358 && F_261 ( F_34 ( & V_54 -> V_55 ) ) != 0 ) )
F_262 ( F_255 , V_54 ) ;
return 0 ;
}
void F_263 ( struct V_1 * V_2 )
{
if ( V_2 -> V_61 ) {
if ( V_2 -> V_61 -> V_359 )
V_2 -> V_61 -> V_359 ( V_2 ) ;
F_241 ( V_2 -> V_61 -> V_334 ) ;
V_2 -> V_61 = NULL ;
}
if ( V_2 -> V_360 ) {
F_241 ( V_2 -> V_360 -> V_334 ) ;
V_2 -> V_360 = NULL ;
}
}
void F_264 ( struct V_223 * V_54 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
V_54 -> V_356 = NULL ;
V_2 = F_265 ( V_54 ) ;
if ( F_29 ( V_2 ) ) {
F_266 ( V_54 ) ;
return;
}
if ( F_267 ( V_262 , & V_2 -> V_193 ) &&
! F_140 ( V_271 , & V_2 -> V_193 ) ) {
F_23 ( V_2 ) ;
F_266 ( V_54 ) ;
return;
}
F_81 ( V_2 , V_29 ) ;
V_36 = V_2 -> V_36 ;
F_268 ( V_2 ) ;
if ( V_36 )
F_19 ( V_36 ) ;
F_266 ( V_54 ) ;
}
int F_269 ( struct V_223 * V_54 ,
struct V_355 * V_360 )
{
struct V_355 * V_61 ;
struct V_1 * V_2 ;
int V_42 ;
F_270 ( V_54 , V_357 , 0 ) ;
V_2 = F_271 ( V_54 ) ;
if ( F_29 ( V_2 ) )
return F_104 ( V_2 ) ;
V_61 = V_360 ;
if ( V_2 -> V_82 & V_361 ) {
if ( ! V_241 ) {
V_42 = F_272 ( V_362 ) ;
if ( V_42 ) {
F_257 ( L_103
L_104
L_105 ,
F_34 ( & V_54 -> V_55 ) , V_362 ,
V_42 ) ;
F_268 ( V_2 ) ;
return - V_207 ;
}
}
if ( ! V_241 ) {
F_257 ( L_106 ,
F_34 ( & V_54 -> V_55 ) ) ;
F_268 ( V_2 ) ;
return - V_207 ;
}
V_61 = V_241 ;
}
if ( ! F_239 ( V_360 -> V_334 ) ) {
F_268 ( V_2 ) ;
return - V_168 ;
}
if ( ! F_239 ( V_61 -> V_334 ) ) {
F_241 ( V_360 -> V_334 ) ;
F_268 ( V_2 ) ;
return - V_168 ;
}
V_2 -> V_360 = V_360 ;
V_2 -> V_61 = V_61 ;
V_42 = V_61 -> V_363 ( V_2 ) ;
if ( V_42 ) {
F_257 ( L_107 ,
F_34 ( & V_54 -> V_55 ) , V_61 -> V_45 , V_42 ) ;
F_241 ( V_61 -> V_334 ) ;
F_241 ( V_360 -> V_334 ) ;
F_268 ( V_2 ) ;
return V_42 ;
}
F_81 ( V_2 , V_81 ) ;
if ( V_2 -> V_28 <= V_43 ) {
F_257 ( L_108 ,
F_34 ( & V_54 -> V_55 ) ) ;
V_42 = - V_207 ;
F_81 ( V_2 , V_29 ) ;
if ( V_2 -> V_36 )
F_19 ( V_2 -> V_36 ) ;
F_268 ( V_2 ) ;
} else
F_273 ( L_109 ,
F_34 ( & V_54 -> V_55 ) ) ;
F_84 ( V_89 , F_82 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_42 ;
}
int F_274 ( struct V_223 * V_54 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_364 , V_37 , V_42 ;
unsigned long V_193 ;
V_42 = 0 ;
F_126 ( F_148 ( V_54 ) , V_193 ) ;
V_2 = F_155 ( V_54 ) ;
if ( F_29 ( V_2 ) ) {
F_128 ( F_148 ( V_54 ) , V_193 ) ;
return F_104 ( V_2 ) ;
}
if ( V_2 -> V_36 ) {
V_364 = V_2 -> V_36 -> V_84 ? 0 : - 1 ;
V_37 = F_275 ( & V_2 -> V_36 -> V_37 ) ;
if ( V_37 > V_364 ) {
if ( V_37 > 0 )
F_257 ( L_110 ,
F_34 ( & V_54 -> V_55 ) , V_37 ) ;
else
F_257 ( L_111 ,
F_34 ( & V_54 -> V_55 ) ) ;
F_276 ( V_262 , & V_2 -> V_193 ) ;
goto V_365;
}
}
if ( F_140 ( V_271 , & V_2 -> V_193 ) ) {
if ( F_267 ( V_262 , & V_2 -> V_193 ) )
goto V_365;
else
F_276 ( V_366 , & V_2 -> V_193 ) ;
} else {
if ( F_140 ( V_262 , & V_2 -> V_193 ) )
goto V_365;
}
F_124 ( V_262 , & V_2 -> V_193 ) ;
F_128 ( F_148 ( V_54 ) , V_193 ) ;
if ( F_277 ( V_366 , & V_2 -> V_193 ) &&
! F_267 ( V_271 , & V_2 -> V_193 ) ) {
if ( V_2 -> V_36 ) {
V_42 = F_278 ( V_2 -> V_36 -> V_84 ) ;
if ( V_42 != 0 )
goto V_367;
}
F_76 ( V_2 ) ;
V_42 = F_201 ( V_280 ,
F_55 ( V_2 ) ) ;
if ( V_42 != 0 )
goto V_367;
}
F_81 ( V_2 , V_29 ) ;
V_36 = V_2 -> V_36 ;
F_268 ( V_2 ) ;
if ( V_36 )
F_19 ( V_36 ) ;
return 0 ;
V_367:
F_276 ( V_366 , & V_2 -> V_193 ) ;
F_276 ( V_271 , & V_2 -> V_193 ) ;
F_276 ( V_262 , & V_2 -> V_193 ) ;
F_23 ( V_2 ) ;
return V_42 ;
V_365:
F_23 ( V_2 ) ;
F_128 ( F_148 ( V_54 ) , V_193 ) ;
return - V_210 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
F_279 ( & V_2 -> V_54 -> V_55 , L_112
L_113 ) ;
F_39 ( V_58 , V_2 , L_1 , L_114 ) ;
F_220 ( V_2 , NULL , V_368 ) ;
if ( V_2 -> V_28 < V_60 )
return 0 ;
F_204 (cqr, &device->ccw_queue, devlist)
if ( ( V_98 -> V_202 == V_203 ) ||
( V_98 -> V_202 == V_204 ) ) {
V_98 -> V_202 = V_225 ;
V_98 -> V_199 ++ ;
}
F_187 ( V_2 , V_275 ) ;
F_46 ( V_2 ) ;
F_76 ( V_2 ) ;
return 1 ;
}
int F_280 ( struct V_1 * V_2 )
{
F_240 ( & V_2 -> V_54 -> V_55 , L_115
L_116 ) ;
F_39 ( V_58 , V_2 , L_1 , L_117 ) ;
F_149 ( V_2 , V_275 ) ;
if ( V_2 -> V_259 & V_276 ) {
F_149 ( V_2 , V_276 ) ;
F_80 ( V_2 ) ;
return 1 ;
}
F_76 ( V_2 ) ;
if ( V_2 -> V_36 )
F_63 ( V_2 -> V_36 ) ;
if ( ! V_2 -> V_259 )
F_72 ( & V_282 ) ;
return 1 ;
}
int F_281 ( struct V_223 * V_54 , int V_369 )
{
struct V_1 * V_2 ;
int V_354 ;
V_2 = F_155 ( V_54 ) ;
if ( F_29 ( V_2 ) )
return 0 ;
V_354 = 0 ;
switch ( V_369 ) {
case V_370 :
case V_371 :
case V_372 :
F_145 ( V_2 ) ;
V_354 = F_144 ( V_2 ) ;
break;
case V_373 :
V_354 = 1 ;
if ( F_141 ( V_2 ) )
V_354 = F_280 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_354 ;
}
void F_282 ( struct V_223 * V_54 , int * V_374 )
{
struct V_1 * V_2 ;
int V_375 , V_376 , V_377 , V_378 ;
V_2 = F_155 ( V_54 ) ;
if ( F_29 ( V_2 ) )
return;
V_376 = F_141 ( V_2 ) ;
for ( V_375 = 0 ; V_375 < 8 ; V_375 ++ ) {
if ( V_374 [ V_375 ] & V_379 ) {
F_283 ( V_2 , V_375 ) ;
}
if ( V_374 [ V_375 ] & V_380 ) {
F_284 ( V_2 , V_375 ) ;
F_76 ( V_2 ) ;
}
if ( V_374 [ V_375 ] & V_381 ) {
if ( ! F_285 ( V_2 , V_375 ) &&
! F_286 ( V_2 , V_375 ) ) {
F_284 ( V_2 , V_375 ) ;
F_76 ( V_2 ) ;
}
F_39 ( V_58 , V_2 , L_1 ,
L_118 ) ;
if ( V_2 -> V_61 -> V_96 )
V_2 -> V_61 -> V_96 ( V_2 ) ;
}
}
V_377 = F_287 ( V_2 ) ;
V_378 = F_288 ( V_2 ) ;
if ( ! F_141 ( V_2 ) && V_377 ) {
if ( V_2 -> V_61 -> V_382 )
V_2 -> V_61 -> V_382 ( V_2 ) ;
F_187 ( V_2 , V_383 ) ;
F_146 ( V_2 , V_377 ) ;
F_76 ( V_2 ) ;
F_289 ( V_2 ) ;
} else if ( ! F_141 ( V_2 ) && V_378 ) {
F_146 ( V_2 , V_378 ) ;
F_76 ( V_2 ) ;
}
if ( V_376 && ! F_141 ( V_2 ) && ! V_377 && ! V_378 ) {
F_279 ( & V_2 -> V_54 -> V_55 ,
L_119 ) ;
F_39 ( V_58 , V_2 ,
L_1 , L_120 ) ;
F_220 ( V_2 , NULL , V_368 ) ;
F_187 ( V_2 ,
V_275 ) ;
}
F_23 ( V_2 ) ;
}
int F_290 ( struct V_1 * V_2 , T_10 V_217 )
{
if ( ! F_141 ( V_2 ) && V_217 ) {
F_291 ( V_2 , V_217 ) ;
F_280 ( V_2 ) ;
} else
F_292 ( V_2 , V_217 ) ;
return 0 ;
}
static int F_293 ( struct V_1 * V_2 )
{
struct V_101 V_384 ;
struct V_97 * V_98 , * V_265 ;
struct V_97 * V_289 ;
int V_42 ;
F_12 ( & V_384 ) ;
F_181 ( F_148 ( V_2 -> V_54 ) ) ;
V_42 = 0 ;
F_182 (cqr, n, &device->ccw_queue, devlist) {
if ( V_98 -> V_202 == V_203 ) {
V_42 = V_2 -> V_61 -> V_272 ( V_98 ) ;
if ( V_42 ) {
F_137 ( & V_2 -> V_54 -> V_55 ,
L_121
L_122 , V_98 ) ;
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
F_23 ( V_2 ) ;
return V_42 ;
}
}
F_170 ( & V_98 -> V_257 , & V_384 ) ;
}
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
F_182 (cqr, n, &requeue_queue, devlist) {
F_84 ( V_237 ,
( V_98 -> V_202 != V_204 ) ) ;
if ( V_98 -> V_267 == V_296 )
V_98 -> V_267 = V_283 ;
F_173 ( & V_98 -> V_257 ) ;
while ( V_98 -> V_289 != NULL ) {
V_289 = V_98 -> V_289 ;
F_294 ( & V_98 -> V_292 ) ;
F_295 ( V_98 , V_98 -> V_385 ) ;
V_98 = V_289 ;
}
if ( F_224 ( V_98 ) )
continue;
if ( V_98 -> V_36 )
F_173 ( & V_98 -> V_292 ) ;
V_98 -> V_36 -> V_65 -> V_61 -> V_310 (
V_98 , (struct V_99 * ) V_98 -> V_267 ) ;
}
if ( ! F_56 ( & V_384 ) ) {
F_181 ( F_148 ( V_2 -> V_54 ) ) ;
F_296 ( & V_384 , & V_2 -> V_15 ) ;
F_183 ( F_148 ( V_2 -> V_54 ) ) ;
}
F_72 ( & V_282 ) ;
return V_42 ;
}
static void V_27 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_73 ( V_91 , struct V_1 ,
V_26 ) ;
F_293 ( V_2 ) ;
F_149 ( V_2 , V_383 ) ;
if ( V_2 -> V_36 )
F_63 ( V_2 -> V_36 ) ;
F_23 ( V_2 ) ;
}
void F_289 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_78 ( & V_2 -> V_26 ) )
F_23 ( V_2 ) ;
}
int F_297 ( struct V_223 * V_54 )
{
struct V_1 * V_2 = F_265 ( V_54 ) ;
int V_42 ;
if ( F_29 ( V_2 ) )
return F_104 ( V_2 ) ;
F_124 ( V_386 , & V_2 -> V_193 ) ;
if ( V_2 -> V_61 -> V_387 )
V_42 = V_2 -> V_61 -> V_387 ( V_2 ) ;
F_187 ( V_2 , V_388 ) ;
return F_293 ( V_2 ) ;
}
int F_298 ( struct V_223 * V_54 )
{
struct V_1 * V_2 = F_265 ( V_54 ) ;
int V_42 = 0 ;
if ( F_29 ( V_2 ) )
return F_104 ( V_2 ) ;
F_149 ( V_2 ,
( V_388 | V_276 ) ) ;
F_76 ( V_2 ) ;
if ( V_2 -> V_61 -> V_94 && ! ( V_2 -> V_259 ) )
V_42 = V_2 -> V_61 -> V_94 ( V_2 ) ;
if ( V_42 || V_2 -> V_259 )
V_2 -> V_259 |= V_276 ;
if ( V_2 -> V_36 )
F_63 ( V_2 -> V_36 ) ;
F_276 ( V_386 , & V_2 -> V_193 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_97 * F_299 ( struct V_1 * V_2 ,
void * V_389 ,
int V_390 ,
int V_187 )
{
struct V_97 * V_98 ;
struct V_190 * V_195 ;
unsigned long * V_391 ;
V_98 = F_125 ( V_187 , 1 , V_390 , V_2 ) ;
if ( F_29 ( V_98 ) ) {
F_137 ( & V_2 -> V_54 -> V_55 ,
L_65
L_66 , L_123 ) ;
return V_98 ;
}
V_195 = V_98 -> V_191 ;
V_195 -> V_392 = V_393 ;
if ( F_300 ( V_389 , V_390 ) ) {
V_391 = ( unsigned long * ) ( V_98 -> V_19 ) ;
V_195 -> V_394 = ( V_395 ) ( V_396 ) V_391 ;
V_195 -> V_193 = V_397 ;
V_391 = F_301 ( V_391 , V_389 , V_390 ) ;
} else {
V_195 -> V_394 = ( V_395 ) ( V_396 ) V_389 ;
V_195 -> V_193 = 0 ;
}
V_195 -> V_398 = V_390 ;
V_98 -> V_108 = V_2 ;
V_98 -> V_385 = V_2 ;
V_98 -> V_222 = 10 * V_273 ;
V_98 -> V_199 = 256 ;
V_98 -> V_148 = F_136 () ;
V_98 -> V_202 = V_285 ;
return V_98 ;
}
int F_302 ( struct V_1 * V_2 , int V_187 ,
void * V_389 , int V_390 )
{
int V_354 ;
struct V_97 * V_98 ;
V_98 = F_299 ( V_2 , V_389 , V_390 ,
V_187 ) ;
if ( F_29 ( V_98 ) )
return F_104 ( V_98 ) ;
V_354 = F_206 ( V_98 ) ;
F_131 ( V_98 , V_98 -> V_385 ) ;
return V_354 ;
}
char * F_163 ( struct V_226 * V_226 )
{
struct V_399 * V_399 = NULL ;
char * V_236 = NULL ;
if ( F_303 ( & V_226 -> V_227 ) && ( V_226 -> V_227 . V_228 . V_400 == 0x01 ) ) {
if ( V_226 -> V_227 . V_228 . V_401 )
V_399 = F_304 ( (struct V_401 * ) ( unsigned long )
V_226 -> V_227 . V_228 . V_401 ) ;
if ( V_399 && V_399 -> V_402 == 64 && V_399 -> V_193 )
switch ( V_399 -> V_193 & 0x07 ) {
case 1 :
V_236 = V_399 -> V_403 . V_404 . V_236 ;
break;
case 2 :
V_236 = V_399 -> V_403 . V_405 . V_236 ;
break;
default:
break;
}
} else if ( V_226 -> V_252 . V_406 . V_407 . V_408 ) {
V_236 = V_226 -> V_409 ;
}
return V_236 ;
}
void F_305 ( struct V_223 * V_54 )
{
struct V_1 * V_2 ;
V_2 = F_265 ( V_54 ) ;
if ( F_29 ( V_2 ) )
return;
if ( V_2 -> V_36 )
F_63 ( V_2 -> V_36 ) ;
F_76 ( V_2 ) ;
F_84 ( V_280 , F_55 ( V_2 ) ) ;
}
static int T_11 F_306 ( void )
{
int V_42 ;
F_307 ( & V_89 ) ;
F_307 ( & V_237 ) ;
F_307 ( & V_282 ) ;
F_307 ( & V_280 ) ;
V_343 = F_36 ( L_33 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_343 == NULL ) {
V_42 = - V_4 ;
goto V_410;
}
F_37 ( V_343 , & V_57 ) ;
F_38 ( V_343 , V_58 ) ;
F_117 ( V_59 , L_1 , L_2 ) ;
V_241 = NULL ;
F_116 () ;
V_42 = F_308 () ;
if ( V_42 )
goto V_410;
V_42 = F_309 () ;
if ( V_42 )
goto V_410;
V_42 = F_310 () ;
if ( V_42 )
goto V_410;
V_42 = F_311 () ;
if ( V_42 )
goto V_410;
#ifdef F_247
V_42 = F_312 () ;
if ( V_42 )
goto V_410;
#endif
return 0 ;
V_410:
F_313 ( L_124 ) ;
F_246 () ;
return V_42 ;
}
