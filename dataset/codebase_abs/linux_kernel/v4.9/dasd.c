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
V_2 -> V_26 = V_27 ;
if ( V_2 -> V_34 )
F_26 ( V_2 -> V_34 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_42 * F_27 ( const char * V_43 ,
struct V_42 * V_44 )
{
struct V_42 * V_45 ;
if ( ! V_44 )
return NULL ;
V_45 = F_28 ( V_43 , V_44 ) ;
if ( ! V_45 || F_29 ( V_45 ) )
return NULL ;
return V_45 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
int V_40 = 0 ;
if ( V_34 ) {
V_40 = F_31 ( V_34 ) ;
if ( V_40 )
return V_40 ;
V_34 -> V_46 =
F_27 ( V_34 -> V_47 -> V_48 ,
V_49 ) ;
F_32 ( & V_34 -> V_30 , V_34 -> V_46 ) ;
if ( V_50 == V_51 )
F_33 ( & V_2 -> V_34 -> V_30 ) ;
}
V_2 -> V_46 =
F_27 ( F_34 ( & V_2 -> V_52 -> V_53 ) ,
V_49 ) ;
F_32 ( & V_2 -> V_30 , V_2 -> V_46 ) ;
F_35 ( V_2 -> V_46 , V_2 ) ;
V_2 -> V_54 = F_36 ( F_34 ( & V_2 -> V_52 -> V_53 ) , 4 , 1 ,
8 * sizeof( long ) ) ;
F_37 ( V_2 -> V_54 , & V_55 ) ;
F_38 ( V_2 -> V_54 , V_56 ) ;
F_39 ( V_57 , V_2 , L_1 , L_2 ) ;
V_2 -> V_26 = V_58 ;
return V_40 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_59 -> V_60 ) {
V_40 = V_2 -> V_59 -> V_60 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_2 -> V_34 ) {
F_41 ( & V_2 -> V_34 -> V_30 ) ;
F_42 ( V_2 -> V_34 -> V_46 ) ;
F_43 ( V_2 -> V_34 ) ;
F_44 ( V_2 -> V_34 ) ;
}
V_40 = F_45 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_46 ( V_2 ) ;
F_41 ( & V_2 -> V_30 ) ;
F_47 ( V_2 ) ;
F_42 ( V_2 -> V_46 ) ;
F_39 ( V_57 , V_2 , L_3 , V_2 ) ;
if ( V_2 -> V_54 != NULL ) {
F_48 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
}
V_2 -> V_26 = V_41 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_33 * V_34 ;
struct V_61 * V_62 ;
V_40 = 0 ;
V_34 = V_2 -> V_34 ;
if ( V_34 ) {
if ( V_34 -> V_63 -> V_59 -> V_64 != NULL )
V_40 = V_34 -> V_63 -> V_59 -> V_64 ( V_34 ) ;
if ( V_40 ) {
if ( V_40 != - V_65 ) {
V_2 -> V_26 = V_66 ;
V_62 = V_2 -> V_34 -> V_47 ;
F_50 ( & F_51 ( V_62 ) -> V_67 ,
V_68 ) ;
goto V_69;
}
return V_40 ;
}
F_52 ( V_34 ) ;
F_53 ( V_34 -> V_47 ,
V_34 -> V_70 << V_34 -> V_71 ) ;
V_2 -> V_26 = V_72 ;
V_40 = F_54 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_58 ;
return V_40 ;
}
} else {
V_2 -> V_26 = V_72 ;
}
V_69:
if ( V_2 -> V_59 -> V_73 )
V_40 = V_2 -> V_59 -> V_73 ( V_2 ) ;
return V_40 ;
}
static inline
int F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 )
return F_56 ( & V_2 -> V_15 ) &&
F_56 ( & V_2 -> V_34 -> V_15 ) ;
else
return F_56 ( & V_2 -> V_15 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_40 ;
V_2 -> V_26 = V_58 ;
if ( V_2 -> V_34 ) {
struct V_33 * V_34 = V_2 -> V_34 ;
V_40 = F_58 ( V_34 ) ;
if ( V_40 ) {
V_2 -> V_26 = V_72 ;
return V_40 ;
}
F_59 ( V_34 ) ;
F_60 ( V_34 ) ;
V_34 -> V_70 = 0 ;
V_34 -> V_74 = 0 ;
V_34 -> V_71 = 0 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
V_2 -> V_26 = V_58 ;
return 0 ;
}
static int
F_62 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_75 V_76 ;
struct V_77 * V_78 ;
V_2 -> V_26 = V_79 ;
if ( V_2 -> V_34 ) {
F_63 ( V_2 -> V_34 ) ;
if ( ( V_2 -> V_80 & V_81 ) ) {
V_62 = V_2 -> V_34 -> V_47 ;
F_50 ( & F_51 ( V_62 ) -> V_67 , V_68 ) ;
return 0 ;
}
V_62 = V_2 -> V_34 -> V_82 -> V_83 ;
F_64 ( & V_76 , V_62 , V_84 ) ;
while ( ( V_78 = F_65 ( & V_76 ) ) )
F_50 ( & F_66 ( V_78 ) -> V_67 , V_68 ) ;
F_67 ( & V_76 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_61 * V_62 ;
struct V_75 V_76 ;
struct V_77 * V_78 ;
if ( V_2 -> V_59 -> V_85 ) {
V_40 = V_2 -> V_59 -> V_85 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
V_2 -> V_26 = V_72 ;
if ( V_2 -> V_34 && ! ( V_2 -> V_80 & V_81 ) ) {
V_62 = V_2 -> V_34 -> V_82 -> V_83 ;
F_64 ( & V_76 , V_62 , V_84 ) ;
while ( ( V_78 = F_65 ( & V_76 ) ) )
F_50 ( & F_66 ( V_78 ) -> V_67 , V_68 ) ;
F_67 ( & V_76 ) ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_27 &&
V_2 -> V_28 >= V_41 )
V_40 = F_20 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_41 &&
V_2 -> V_28 >= V_58 )
V_40 = F_30 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_58 &&
V_2 -> V_28 >= V_72 )
V_40 = F_49 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_66 &&
V_2 -> V_28 > V_66 )
V_40 = - V_86 ;
if ( ! V_40 &&
V_2 -> V_26 == V_72 &&
V_2 -> V_28 >= V_79 )
V_40 = F_62 ( V_2 ) ;
return V_40 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = 0 ;
if ( V_2 -> V_26 == V_79 &&
V_2 -> V_28 <= V_72 )
V_40 = F_68 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_72 &&
V_2 -> V_28 <= V_58 )
V_40 = F_57 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_66 &&
V_2 -> V_28 <= V_58 )
V_40 = F_61 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_58 &&
V_2 -> V_28 <= V_41 )
V_40 = F_40 ( V_2 ) ;
if ( ! V_40 &&
V_2 -> V_26 == V_41 &&
V_2 -> V_28 <= V_27 )
V_40 = F_24 ( V_2 ) ;
return V_40 ;
}
static void F_71 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_26 == V_2 -> V_28 )
return;
if ( V_2 -> V_26 < V_2 -> V_28 )
V_40 = F_69 ( V_2 ) ;
else
V_40 = F_70 ( V_2 ) ;
if ( V_40 == - V_65 )
return;
if ( V_40 )
V_2 -> V_28 = V_2 -> V_26 ;
F_50 ( & V_2 -> V_52 -> V_53 . V_67 , V_68 ) ;
if ( V_2 -> V_26 == V_2 -> V_28 )
F_72 ( & V_87 ) ;
}
static void V_21 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_73 ( V_89 , struct V_1 , V_20 ) ;
F_74 ( & V_2 -> V_29 ) ;
F_71 ( V_2 ) ;
F_75 ( & V_2 -> V_29 ) ;
F_76 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_78 ( & V_2 -> V_20 ) )
F_23 ( V_2 ) ;
}
static void V_25 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_73 ( V_89 , struct V_1 ,
V_24 ) ;
V_2 -> V_59 -> V_90 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_78 ( & V_2 -> V_24 ) )
F_23 ( V_2 ) ;
}
static void V_23 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_73 ( V_89 , struct V_1 ,
V_22 ) ;
V_2 -> V_52 -> V_91 -> V_92 ( V_2 -> V_52 ) ;
F_23 ( V_2 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( ! F_78 ( & V_2 -> V_22 ) )
F_23 ( V_2 ) ;
}
void F_81 ( struct V_1 * V_2 , int V_28 )
{
F_21 ( V_2 ) ;
F_74 ( & V_2 -> V_29 ) ;
if ( V_93 && V_28 > V_72 )
V_28 = V_72 ;
if ( V_2 -> V_28 != V_28 ) {
if ( V_2 -> V_26 == V_28 )
F_72 ( & V_87 ) ;
V_2 -> V_28 = V_28 ;
}
if ( V_2 -> V_26 != V_2 -> V_28 )
F_71 ( V_2 ) ;
F_75 ( & V_2 -> V_29 ) ;
F_23 ( V_2 ) ;
}
static inline int F_82 ( struct V_1 * V_2 )
{
return ( V_2 -> V_26 == V_2 -> V_28 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_81 ( V_2 , V_79 ) ;
if ( V_2 -> V_26 <= V_41 )
F_81 ( V_2 , V_27 ) ;
F_84 ( V_87 , F_82 ( V_2 ) ) ;
F_79 ( V_2 ) ;
if ( V_2 -> V_59 -> V_94 )
V_2 -> V_59 -> V_94 ( V_2 ) ;
}
static void F_85 ( struct V_33 * V_34 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 ;
unsigned int V_101 ;
struct V_1 * V_2 ;
V_101 = 0 ;
if ( V_50 || V_34 -> V_30 . V_19 )
F_86 (l, &block->ccw_queue)
if ( ++ V_101 >= 31 )
break;
F_87 ( & V_102 . V_31 ) ;
if ( V_102 . V_19 ) {
V_102 . V_19 -> V_103 [ V_101 ] ++ ;
if ( F_88 ( V_98 ) == V_104 )
V_102 . V_19 -> V_105 [ V_101 ] ++ ;
}
F_89 ( & V_102 . V_31 ) ;
F_87 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 ) {
V_34 -> V_30 . V_19 -> V_103 [ V_101 ] ++ ;
if ( F_88 ( V_98 ) == V_104 )
V_34 -> V_30 . V_19 -> V_105 [ V_101 ] ++ ;
}
F_89 ( & V_34 -> V_30 . V_31 ) ;
V_2 = V_96 -> V_106 ;
if ( V_2 -> V_30 . V_19 ) {
V_101 = 1 ;
F_86 (l, &device->ccw_queue)
if ( ++ V_101 >= 31 )
break;
}
F_87 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 ) {
V_2 -> V_30 . V_19 -> V_103 [ V_101 ] ++ ;
if ( F_88 ( V_98 ) == V_104 )
V_2 -> V_30 . V_19 -> V_105 [ V_101 ] ++ ;
}
F_89 ( & V_2 -> V_30 . V_31 ) ;
}
static void F_90 ( struct V_107 * V_19 ,
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
F_91 ( & V_19 -> V_121 ) ;
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
static void F_92 ( struct V_33 * V_34 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
long V_141 , V_142 , V_143 , V_144 ;
long V_145 , V_111 ;
struct V_1 * V_2 ;
int V_112 , V_113 , V_114 , V_115 ;
int V_116 , V_117 , V_118 ;
V_2 = V_96 -> V_106 ;
if ( ! ( V_50 ||
V_34 -> V_30 . V_19 ||
V_2 -> V_30 . V_19 ) )
return;
V_111 = F_93 ( V_98 ) ;
if ( ! V_96 -> V_146 || ! V_96 -> V_147 ||
! V_96 -> V_148 || ! V_96 -> V_149 ||
! V_111 )
return;
V_141 = ( ( V_96 -> V_147 - V_96 -> V_146 ) >> 12 ) ;
V_142 = ( ( V_96 -> V_148 - V_96 -> V_147 ) >> 12 ) ;
V_143 = ( ( V_96 -> V_149 - V_96 -> V_148 ) >> 12 ) ;
V_144 = ( ( V_96 -> V_149 - V_96 -> V_146 ) >> 12 ) ;
V_145 = V_144 / V_111 ;
F_94 ( V_111 , V_112 ) ;
F_94 ( V_144 , V_113 ) ;
F_94 ( V_145 , V_114 ) ;
F_94 ( V_141 , V_115 ) ;
F_94 ( V_142 , V_116 ) ;
F_94 ( V_142 / V_111 , V_117 ) ;
F_94 ( V_143 , V_118 ) ;
F_87 ( & V_102 . V_31 ) ;
if ( V_102 . V_19 ) {
F_90 ( V_102 . V_19 ,
V_96 -> V_106 != V_34 -> V_63 ,
V_96 -> V_150 == 1 ,
F_88 ( V_98 ) == V_104 ,
V_111 , V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 ,
V_118 ) ;
}
F_89 ( & V_102 . V_31 ) ;
F_87 ( & V_34 -> V_30 . V_31 ) ;
if ( V_34 -> V_30 . V_19 )
F_90 ( V_34 -> V_30 . V_19 ,
V_96 -> V_106 != V_34 -> V_63 ,
V_96 -> V_150 == 1 ,
F_88 ( V_98 ) == V_104 ,
V_111 , V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 ,
V_118 ) ;
F_89 ( & V_34 -> V_30 . V_31 ) ;
F_87 ( & V_2 -> V_30 . V_31 ) ;
if ( V_2 -> V_30 . V_19 )
F_90 ( V_2 -> V_30 . V_19 ,
V_96 -> V_106 != V_34 -> V_63 ,
V_96 -> V_150 == 1 ,
F_88 ( V_98 ) == V_104 ,
V_111 , V_112 , V_113 ,
V_114 , V_115 ,
V_116 , V_117 ,
V_118 ) ;
F_89 ( & V_2 -> V_30 . V_31 ) ;
}
void F_95 ( struct V_151 * V_30 )
{
struct V_107 * V_19 ;
F_96 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_97 ( & V_30 -> V_31 ) ;
return;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_91 ( & V_19 -> V_121 ) ;
F_97 ( & V_30 -> V_31 ) ;
}
int F_33 ( struct V_151 * V_30 )
{
struct V_107 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_152 ) ;
if ( ! V_19 )
return - V_4 ;
F_96 ( & V_30 -> V_31 ) ;
if ( V_30 -> V_19 ) {
F_97 ( & V_30 -> V_31 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_91 ( & V_19 -> V_121 ) ;
V_30 -> V_19 = V_19 ;
F_97 ( & V_30 -> V_31 ) ;
return 0 ;
}
void F_98 ( struct V_151 * V_30 )
{
F_96 ( & V_30 -> V_31 ) ;
F_5 ( V_30 -> V_19 ) ;
V_30 -> V_19 = NULL ;
F_97 ( & V_30 -> V_31 ) ;
}
char * F_99 ( const char T_1 * V_153 , T_2 V_154 )
{
char * V_155 ;
V_155 = F_100 ( V_154 + 1 ) ;
if ( V_155 == NULL )
return F_3 ( - V_4 ) ;
if ( F_101 ( V_155 , V_153 , V_154 ) != 0 ) {
F_102 ( V_155 ) ;
return F_3 ( - V_156 ) ;
}
if ( V_155 [ V_154 - 1 ] == '\n' )
V_155 [ V_154 - 1 ] = 0 ;
else
V_155 [ V_154 ] = 0 ;
return V_155 ;
}
static T_3 F_103 ( struct V_157 * V_157 ,
const char T_1 * V_153 ,
T_2 V_154 , T_4 * V_158 )
{
char * V_155 , * V_159 ;
int V_40 ;
struct V_160 * V_161 = (struct V_160 * ) V_157 -> V_162 ;
struct V_151 * V_163 = V_161 -> V_32 ;
if ( V_154 > 65536 )
V_154 = 65536 ;
V_155 = F_99 ( V_153 , V_154 ) ;
if ( F_29 ( V_155 ) )
return F_104 ( V_155 ) ;
V_159 = F_105 ( V_155 ) ;
V_40 = V_154 ;
if ( strncmp ( V_159 , L_4 , 5 ) == 0 ) {
F_95 ( V_163 ) ;
} else if ( strncmp ( V_159 , L_5 , 2 ) == 0 ) {
V_40 = F_33 ( V_163 ) ;
if ( V_40 )
goto V_69;
V_40 = V_154 ;
if ( V_163 == & V_102 ) {
F_95 ( V_163 ) ;
V_50 = V_164 ;
}
} else if ( strncmp ( V_159 , L_6 , 3 ) == 0 ) {
if ( V_163 == & V_102 )
V_50 = V_165 ;
F_98 ( V_163 ) ;
} else
V_40 = - V_166 ;
V_69:
F_102 ( V_155 ) ;
return V_40 ;
}
static void F_106 ( struct V_160 * V_161 , unsigned int * V_167 )
{
int V_168 ;
for ( V_168 = 0 ; V_168 < 32 ; V_168 ++ )
F_107 ( V_161 , L_7 , V_167 [ V_168 ] ) ;
F_108 ( V_161 , '\n' ) ;
}
static void F_109 ( struct V_160 * V_161 ,
struct V_107 * V_19 )
{
F_107 ( V_161 , L_8 ,
V_19 -> V_121 . V_169 , V_19 -> V_121 . V_170 ) ;
F_107 ( V_161 , L_9 , V_19 -> V_119 ) ;
F_107 ( V_161 , L_10 , V_19 -> V_122 ) ;
F_107 ( V_161 , L_11 , V_19 -> V_123 ) ;
F_107 ( V_161 , L_12 , V_19 -> V_124 ) ;
F_110 ( V_161 , L_13 ) ;
F_106 ( V_161 , V_19 -> V_125 ) ;
F_110 ( V_161 , L_14 ) ;
F_106 ( V_161 , V_19 -> V_126 ) ;
F_110 ( V_161 , L_15 ) ;
F_106 ( V_161 , V_19 -> V_127 ) ;
F_110 ( V_161 , L_16 ) ;
F_106 ( V_161 , V_19 -> V_128 ) ;
F_110 ( V_161 , L_17 ) ;
F_106 ( V_161 , V_19 -> V_129 ) ;
F_110 ( V_161 , L_18 ) ;
F_106 ( V_161 , V_19 -> V_130 ) ;
F_110 ( V_161 , L_19 ) ;
F_106 ( V_161 , V_19 -> V_131 ) ;
F_110 ( V_161 , L_20 ) ;
F_106 ( V_161 , V_19 -> V_103 ) ;
F_107 ( V_161 , L_21 , V_19 -> V_132 ) ;
F_107 ( V_161 , L_22 , V_19 -> V_133 ) ;
F_107 ( V_161 , L_23 , V_19 -> V_134 ) ;
F_107 ( V_161 , L_24 , V_19 -> V_135 ) ;
F_110 ( V_161 , L_25 ) ;
F_106 ( V_161 , V_19 -> V_136 ) ;
F_110 ( V_161 , L_26 ) ;
F_106 ( V_161 , V_19 -> V_137 ) ;
F_110 ( V_161 , L_27 ) ;
F_106 ( V_161 , V_19 -> V_138 ) ;
F_110 ( V_161 , L_28 ) ;
F_106 ( V_161 , V_19 -> V_139 ) ;
F_110 ( V_161 , L_29 ) ;
F_106 ( V_161 , V_19 -> V_140 ) ;
F_110 ( V_161 , L_30 ) ;
F_106 ( V_161 , V_19 -> V_105 ) ;
}
static int F_111 ( struct V_160 * V_161 , void * V_171 )
{
struct V_151 * V_30 ;
struct V_107 * V_19 ;
V_30 = V_161 -> V_32 ;
F_96 ( & V_30 -> V_31 ) ;
V_19 = V_30 -> V_19 ;
if ( ! V_19 ) {
F_97 ( & V_30 -> V_31 ) ;
F_110 ( V_161 , L_31 ) ;
return 0 ;
}
F_109 ( V_161 , V_19 ) ;
F_97 ( & V_30 -> V_31 ) ;
return 0 ;
}
static int F_112 ( struct V_172 * V_172 , struct V_157 * V_157 )
{
struct V_151 * V_30 = V_172 -> V_173 ;
return F_113 ( V_157 , F_111 , V_30 ) ;
}
static void F_32 ( struct V_151 * V_30 ,
struct V_42 * V_44 )
{
T_5 V_174 ;
struct V_42 * V_45 ;
if ( ! V_44 )
return;
V_30 -> V_42 = NULL ;
V_30 -> V_19 = NULL ;
V_174 = ( V_175 | V_176 | V_177 ) ;
V_45 = F_114 ( L_32 , V_174 , V_44 ,
V_30 , & V_178 ) ;
if ( V_45 && ! F_29 ( V_45 ) )
V_30 -> V_42 = V_45 ;
return;
}
static void F_41 ( struct V_151 * V_30 )
{
F_98 ( V_30 ) ;
F_42 ( V_30 -> V_42 ) ;
V_30 -> V_42 = NULL ;
}
static void F_115 ( void )
{
V_50 = V_165 ;
F_41 ( & V_102 ) ;
F_42 ( V_179 ) ;
F_42 ( V_49 ) ;
}
static void F_116 ( void )
{
struct V_42 * V_45 ;
V_49 = NULL ;
V_45 = F_28 ( L_33 , NULL ) ;
if ( ! V_45 || F_29 ( V_45 ) )
goto error;
V_49 = V_45 ;
V_45 = F_28 ( L_34 , V_49 ) ;
if ( ! V_45 || F_29 ( V_45 ) )
goto error;
V_179 = V_45 ;
F_32 ( & V_102 , V_179 ) ;
return;
error:
F_117 ( V_180 , L_1 ,
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
int F_118 ( struct V_160 * V_161 , void * V_171 )
{
F_110 ( V_161 , L_36 ) ;
return 0 ;
}
static void F_32 ( struct V_151 * V_30 ,
struct V_42 * V_44 )
{
return;
}
static void F_41 ( struct V_151 * V_30 )
{
return;
}
int F_33 ( struct V_151 * V_30 )
{
return 0 ;
}
static int F_119 ( struct V_160 * V_161 , void * V_171 )
{
struct V_1 * V_2 ;
int V_40 = - V_181 ;
V_2 = V_161 -> V_32 ;
F_21 ( V_2 ) ;
if ( V_2 -> V_59 -> V_182 )
V_40 = V_2 -> V_59 -> V_182 ( V_2 , V_161 ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
static int F_120 ( struct V_172 * V_172 , struct V_157 * V_157 )
{
struct V_1 * V_2 = V_172 -> V_173 ;
return F_113 ( V_157 , F_119 , V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_42 ( V_2 -> V_183 ) ;
V_2 -> V_183 = NULL ;
}
static void F_35 ( struct V_42 * V_44 ,
struct V_1 * V_2 )
{
struct V_42 * V_45 ;
T_5 V_174 ;
if ( ! V_44 )
return;
V_174 = V_175 | V_177 ;
V_45 = F_114 ( L_37 , V_174 , V_44 ,
V_2 , & V_184 ) ;
if ( V_45 && ! F_29 ( V_45 ) )
V_2 -> V_183 = V_45 ;
}
struct V_95 * F_121 ( int V_185 , int V_186 ,
int V_187 ,
struct V_1 * V_2 )
{
struct V_95 * V_96 ;
F_122 ( V_187 > V_9 ||
( V_186 * sizeof( struct V_188 ) ) > V_9 ) ;
V_96 = F_2 ( sizeof( struct V_95 ) , V_3 ) ;
if ( V_96 == NULL )
return F_3 ( - V_4 ) ;
V_96 -> V_189 = NULL ;
if ( V_186 > 0 ) {
V_96 -> V_189 = F_123 ( V_186 , sizeof( struct V_188 ) ,
V_3 | V_6 ) ;
if ( V_96 -> V_189 == NULL ) {
F_5 ( V_96 ) ;
return F_3 ( - V_4 ) ;
}
}
V_96 -> V_19 = NULL ;
if ( V_187 > 0 ) {
V_96 -> V_19 = F_2 ( V_187 , V_3 | V_6 ) ;
if ( V_96 -> V_19 == NULL ) {
F_5 ( V_96 -> V_189 ) ;
F_5 ( V_96 ) ;
return F_3 ( - V_4 ) ;
}
}
V_96 -> V_185 = V_185 ;
F_124 ( V_190 , & V_96 -> V_191 ) ;
F_21 ( V_2 ) ;
return V_96 ;
}
struct V_95 * F_125 ( int V_185 , int V_186 ,
int V_187 ,
struct V_1 * V_2 )
{
unsigned long V_191 ;
struct V_95 * V_96 ;
char * V_19 ;
int V_192 ;
V_192 = ( sizeof( struct V_95 ) + 7L ) & - 8L ;
if ( V_186 > 0 )
V_192 += V_186 * sizeof( struct V_188 ) ;
if ( V_187 > 0 )
V_192 += V_187 ;
F_126 ( & V_2 -> V_11 , V_191 ) ;
V_96 = (struct V_95 * )
F_127 ( & V_2 -> V_8 , V_192 ) ;
F_128 ( & V_2 -> V_11 , V_191 ) ;
if ( V_96 == NULL )
return F_3 ( - V_4 ) ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
V_19 = ( char * ) V_96 + ( ( sizeof( struct V_95 ) + 7L ) & - 8L ) ;
V_96 -> V_189 = NULL ;
if ( V_186 > 0 ) {
V_96 -> V_189 = (struct V_188 * ) V_19 ;
V_19 += V_186 * sizeof( struct V_188 ) ;
memset ( V_96 -> V_189 , 0 , V_186 * sizeof( struct V_188 ) ) ;
}
V_96 -> V_19 = NULL ;
if ( V_187 > 0 ) {
V_96 -> V_19 = V_19 ;
memset ( V_96 -> V_19 , 0 , V_187 ) ;
}
V_96 -> V_185 = V_185 ;
F_124 ( V_190 , & V_96 -> V_191 ) ;
F_21 ( V_2 ) ;
return V_96 ;
}
void F_129 ( struct V_95 * V_96 , struct V_1 * V_2 )
{
struct V_188 * V_193 ;
V_193 = V_96 -> V_189 ;
do {
F_130 ( V_193 ) ;
} while ( V_193 ++ -> V_191 & ( V_194 | V_195 ) );
F_5 ( V_96 -> V_189 ) ;
F_5 ( V_96 -> V_19 ) ;
F_5 ( V_96 ) ;
F_23 ( V_2 ) ;
}
void F_131 ( struct V_95 * V_96 , struct V_1 * V_2 )
{
unsigned long V_191 ;
F_126 ( & V_2 -> V_11 , V_191 ) ;
F_132 ( & V_2 -> V_8 , V_96 ) ;
F_128 ( & V_2 -> V_11 , V_191 ) ;
F_23 ( V_2 ) ;
}
static inline int F_133 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
if ( V_96 == NULL )
return - V_166 ;
V_2 = V_96 -> V_106 ;
if ( strncmp ( ( char * ) & V_96 -> V_185 , V_2 -> V_59 -> V_196 , 4 ) ) {
F_39 ( V_56 , V_2 ,
L_38
L_39 ,
V_96 -> V_185 ,
* ( unsigned int * ) V_2 -> V_59 -> V_43 ) ;
return - V_166 ;
}
return 0 ;
}
int F_134 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_197 , V_40 ;
char V_198 [ V_199 ] ;
V_40 = F_133 ( V_96 ) ;
if ( V_40 )
return V_40 ;
V_197 = 0 ;
V_2 = (struct V_1 * ) V_96 -> V_106 ;
while ( ( V_197 < 5 ) && ( V_96 -> V_200 == V_201 ) ) {
V_40 = F_135 ( V_2 -> V_52 , ( long ) V_96 ) ;
switch ( V_40 ) {
case 0 :
V_96 -> V_200 = V_202 ;
V_96 -> V_148 = F_136 () ;
V_96 -> V_203 = 0 ;
F_39 ( V_204 , V_2 ,
L_40 ,
V_96 ) ;
break;
case - V_205 :
F_39 ( V_180 , V_2 , L_1 ,
L_41 ) ;
break;
case - V_206 :
F_39 ( V_180 , V_2 , L_1 ,
L_42 ) ;
break;
case - V_166 :
V_96 -> V_200 = V_207 ;
V_96 -> V_148 = F_136 () ;
V_96 -> V_203 = 0 ;
V_96 -> V_197 = - 1 ;
F_39 ( V_180 , V_2 , L_1 ,
L_43 ) ;
V_40 = 0 ;
break;
case - V_208 :
F_39 ( V_180 , V_2 , L_1 ,
L_44 ) ;
break;
default:
snprintf ( V_198 , V_199 , L_45 , V_40 ) ;
F_137 ( & V_2 -> V_52 -> V_53 , L_46
L_47 , V_198 ) ;
F_138 () ;
break;
}
V_197 ++ ;
}
F_76 ( V_2 ) ;
return V_40 ;
}
int F_139 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_40 ;
char V_198 [ V_199 ] ;
V_40 = F_133 ( V_96 ) ;
if ( V_40 ) {
V_96 -> V_209 = V_40 ;
return V_40 ;
}
V_2 = (struct V_1 * ) V_96 -> V_106 ;
if ( ( ( V_96 -> V_34 &&
F_140 ( V_210 , & V_96 -> V_34 -> V_63 -> V_191 ) ) ||
F_140 ( V_210 , & V_2 -> V_191 ) ) &&
! F_140 ( V_211 , & V_96 -> V_191 ) ) {
F_39 ( V_204 , V_2 , L_48
L_49 , V_96 ) ;
V_96 -> V_200 = V_212 ;
V_96 -> V_209 = - V_86 ;
return - V_86 ;
}
if ( V_96 -> V_197 < 0 ) {
sprintf ( V_198 , L_50 , V_96 ) ;
F_137 ( & V_2 -> V_52 -> V_53 , L_51
L_52 , V_198 ) ;
V_96 -> V_200 = V_212 ;
return - V_206 ;
}
V_96 -> V_147 = F_136 () ;
V_96 -> V_203 = V_213 ;
V_96 -> V_197 -- ;
if ( ! F_140 ( V_214 , & V_96 -> V_191 ) ) {
V_96 -> V_215 &= V_2 -> V_216 . V_217 ;
if ( ! V_96 -> V_215 )
V_96 -> V_215 = V_2 -> V_216 . V_217 ;
}
if ( V_96 -> V_150 == 1 ) {
V_40 = F_141 ( V_2 -> V_52 , V_96 -> V_189 ,
( long ) V_96 , V_96 -> V_215 ) ;
} else {
V_40 = F_142 ( V_2 -> V_52 , V_96 -> V_189 ,
( long ) V_96 , V_96 -> V_215 , 0 ) ;
}
switch ( V_40 ) {
case 0 :
V_96 -> V_200 = V_201 ;
break;
case - V_208 :
F_39 ( V_56 , V_2 , L_1 ,
L_53 ) ;
break;
case - V_218 :
F_39 ( V_56 , V_2 , L_1 ,
L_54 ) ;
break;
case - V_219 :
if ( F_140 ( V_214 , & V_96 -> V_191 ) ) {
F_39 ( V_56 , V_2 ,
L_55 ,
V_96 -> V_215 ) ;
} else if ( V_96 -> V_215 != V_2 -> V_216 . V_217 ) {
V_96 -> V_215 = V_2 -> V_216 . V_217 ;
F_39 ( V_204 , V_2 , L_1 ,
L_56
L_57 ) ;
} else {
F_39 ( V_56 , V_2 , L_1 ,
L_58
L_59 ) ;
F_143 ( V_2 ) ;
V_2 -> V_216 . V_217 = 0 ;
V_2 -> V_216 . V_220 = 0 ;
V_2 -> V_216 . V_221 = 0 ;
V_2 -> V_216 . V_222 =
F_144 ( V_2 -> V_52 ) ;
}
break;
case - V_205 :
F_39 ( V_56 , V_2 , L_1 ,
L_60 ) ;
break;
case - V_206 :
F_39 ( V_56 , V_2 , L_1 ,
L_61 ) ;
break;
case - V_166 :
F_39 ( V_56 , V_2 , L_1 ,
L_62
L_63 ) ;
break;
default:
snprintf ( V_198 , V_199 , L_64 , V_40 ) ;
F_137 ( & V_2 -> V_52 -> V_53 ,
L_65
L_66 , V_198 ) ;
F_138 () ;
break;
}
V_96 -> V_209 = V_40 ;
return V_40 ;
}
static void V_18 ( unsigned long V_223 )
{
unsigned long V_191 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_223 ;
F_126 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
F_146 ( V_2 , V_224 ) ;
F_128 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
F_76 ( V_2 ) ;
}
void F_147 ( struct V_1 * V_2 , int V_225 )
{
if ( V_225 == 0 )
F_148 ( & V_2 -> V_16 ) ;
else
F_149 ( & V_2 -> V_16 , V_213 + V_225 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_148 ( & V_2 -> V_16 ) ;
}
static void F_150 ( struct V_226 * V_52 ,
unsigned long V_227 )
{
struct V_95 * V_96 ;
struct V_1 * V_2 ;
if ( ! V_227 )
return;
V_96 = (struct V_95 * ) V_227 ;
if ( V_96 -> V_200 != V_201 ) {
F_151 ( V_204 , V_52 ,
L_67
L_68 , V_96 -> V_200 ) ;
return;
}
V_2 = F_152 ( V_52 ) ;
if ( F_29 ( V_2 ) ) {
F_151 ( V_204 , V_52 , L_1 ,
L_69 ) ;
return;
}
if ( ! V_96 -> V_106 ||
V_2 != V_96 -> V_106 ||
strncmp ( V_96 -> V_106 -> V_59 -> V_196 ,
( char * ) & V_96 -> V_185 , 4 ) ) {
F_151 ( V_204 , V_52 , L_1 ,
L_70 ) ;
F_23 ( V_2 ) ;
return;
}
V_96 -> V_200 = V_228 ;
F_46 ( V_2 ) ;
F_76 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_153 ( struct V_1 * V_2 )
{
F_154 ( V_2 ) ;
F_146 ( V_2 , V_224 ) ;
F_76 ( V_2 ) ;
if ( V_2 -> V_34 )
F_63 ( V_2 -> V_34 ) ;
}
void F_155 ( struct V_226 * V_52 , unsigned long V_227 ,
struct V_229 * V_229 )
{
struct V_95 * V_96 , * V_230 ;
struct V_1 * V_2 ;
unsigned long long V_231 ;
int V_232 = 0 ;
int V_233 = 0 ;
T_6 * V_234 = NULL ;
int V_225 ;
V_96 = (struct V_95 * ) V_227 ;
if ( F_29 ( V_229 ) ) {
switch ( F_104 ( V_229 ) ) {
case - V_206 :
if ( V_96 && V_96 -> V_200 == V_202 ) {
V_2 = (struct V_1 * ) V_96 -> V_106 ;
V_96 -> V_200 = V_207 ;
F_46 ( V_2 ) ;
F_72 ( & V_235 ) ;
F_76 ( V_2 ) ;
return;
}
break;
case - V_218 :
F_151 ( V_56 , V_52 , L_71
L_72 , V_236 ) ;
break;
default:
F_151 ( V_56 , V_52 , L_71
L_73 , V_236 ,
F_104 ( V_229 ) ) ;
}
F_150 ( V_52 , V_227 ) ;
return;
}
V_231 = F_136 () ;
if ( ! V_96 ||
! ( F_156 ( & V_229 -> V_237 ) == ( V_238 | V_239 ) &&
F_157 ( & V_229 -> V_237 ) == 0 ) ) {
if ( V_96 )
memcpy ( & V_96 -> V_229 , V_229 , sizeof( * V_229 ) ) ;
V_2 = F_152 ( V_52 ) ;
if ( F_29 ( V_2 ) )
return;
if ( V_2 -> V_59 == V_240 ) {
F_23 ( V_2 ) ;
return;
}
V_234 = F_158 ( V_229 ) ;
if ( V_234 ) {
V_233 = ( V_234 [ 1 ] & V_241 ) &&
F_140 ( V_242 , & V_96 -> V_191 ) ;
V_232 = ( V_234 [ 1 ] & V_243 ) &&
F_140 ( V_244 , & V_96 -> V_191 ) ;
}
if ( ! ( V_233 || V_232 ) )
V_2 -> V_59 -> V_245 ( V_2 , V_229 , L_74 ) ;
if ( V_2 -> V_80 & V_246 )
V_2 -> V_59 -> V_247 ( V_2 , V_96 , V_229 ) ;
V_2 -> V_59 -> V_248 ( V_2 , V_96 , V_229 ) ;
F_23 ( V_2 ) ;
}
if ( F_156 ( & V_229 -> V_237 ) & V_249 ) {
V_2 = F_152 ( V_52 ) ;
V_2 -> V_59 -> V_250 ( V_2 , V_229 -> V_251 . V_252 . V_253 ) ;
F_23 ( V_2 ) ;
}
if ( ! V_96 )
return;
V_2 = (struct V_1 * ) V_96 -> V_106 ;
if ( ! V_2 ||
strncmp ( V_2 -> V_59 -> V_196 , ( char * ) & V_96 -> V_185 , 4 ) ) {
F_151 ( V_204 , V_52 , L_1 ,
L_70 ) ;
return;
}
if ( V_96 -> V_200 == V_202 &&
F_159 ( & V_229 -> V_237 ) & V_254 ) {
V_96 -> V_200 = V_207 ;
F_46 ( V_2 ) ;
F_72 ( & V_235 ) ;
F_76 ( V_2 ) ;
return;
}
if ( V_96 -> V_200 != V_201 ) {
F_39 ( V_204 , V_2 , L_75
L_76 , F_34 ( & V_52 -> V_53 ) , V_96 -> V_200 ) ;
return;
}
V_230 = NULL ;
V_225 = 0 ;
if ( F_156 ( & V_229 -> V_237 ) == ( V_238 | V_239 ) &&
F_157 ( & V_229 -> V_237 ) == 0 ) {
V_96 -> V_200 = V_255 ;
V_96 -> V_148 = V_231 ;
if ( V_96 -> V_256 . V_230 != & V_2 -> V_15 ) {
V_230 = F_160 ( V_96 -> V_256 . V_230 ,
struct V_95 , V_256 ) ;
}
} else {
if ( ! F_140 ( V_190 , & V_96 -> V_191 ) &&
V_96 -> V_197 > 0 ) {
if ( V_96 -> V_215 == V_2 -> V_216 . V_217 )
F_39 ( V_204 , V_2 ,
L_77
L_78 ,
V_96 -> V_197 ) ;
if ( ! F_140 ( V_214 , & V_96 -> V_191 ) )
V_96 -> V_215 = V_2 -> V_216 . V_217 ;
V_96 -> V_200 = V_228 ;
V_230 = V_96 ;
} else
V_96 -> V_200 = V_212 ;
}
if ( V_230 && ( V_230 -> V_200 == V_228 ) &&
( ! V_2 -> V_257 ) ) {
if ( V_2 -> V_59 -> V_258 ( V_230 ) == 0 )
V_225 = V_230 -> V_225 ;
}
if ( V_225 != 0 )
F_147 ( V_2 , V_225 ) ;
else
F_46 ( V_2 ) ;
F_76 ( V_2 ) ;
}
enum V_259 F_161 ( struct V_226 * V_52 , struct V_229 * V_229 )
{
struct V_1 * V_2 ;
V_2 = F_152 ( V_52 ) ;
if ( F_29 ( V_2 ) )
goto V_69;
if ( F_140 ( V_260 , & V_2 -> V_191 ) ||
V_2 -> V_26 != V_2 -> V_28 ||
! V_2 -> V_59 -> V_248 ) {
F_23 ( V_2 ) ;
goto V_69;
}
if ( V_2 -> V_59 -> V_245 )
V_2 -> V_59 -> V_245 ( V_2 , V_229 , L_79 ) ;
V_2 -> V_59 -> V_248 ( V_2 , NULL , V_229 ) ;
F_23 ( V_2 ) ;
V_69:
return V_261 ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_95 * V_262 )
{
struct V_99 * V_100 , * V_263 ;
struct V_95 * V_96 ;
if ( ! V_262 -> V_34 )
return;
F_163 (l, n, &device->ccw_queue) {
V_96 = F_160 ( V_100 , struct V_95 , V_256 ) ;
if ( V_96 -> V_200 == V_228 &&
V_262 -> V_34 == V_96 -> V_34 ) {
V_96 -> V_200 = V_207 ;
}
}
}
static void F_164 ( struct V_1 * V_2 ,
struct V_99 * V_264 )
{
struct V_99 * V_100 , * V_263 ;
struct V_95 * V_96 ;
F_163 (l, n, &device->ccw_queue) {
V_96 = F_160 ( V_100 , struct V_95 , V_256 ) ;
if ( V_96 -> V_200 == V_228 ||
V_96 -> V_200 == V_201 ||
V_96 -> V_200 == V_202 )
continue;
if ( V_96 -> V_200 == V_212 ) {
F_162 ( V_2 , V_96 ) ;
}
F_165 ( & V_96 -> V_256 , V_264 ) ;
}
}
static void F_166 ( struct V_1 * V_2 ,
struct V_99 * V_264 )
{
struct V_99 * V_100 , * V_263 ;
struct V_95 * V_96 ;
struct V_33 * V_34 ;
void (* F_167)( struct V_95 * , void * V_19 );
void * V_265 ;
char V_198 [ V_199 ] ;
F_163 (l, n, final_queue) {
V_96 = F_160 ( V_100 , struct V_95 , V_256 ) ;
F_168 ( & V_96 -> V_256 ) ;
V_34 = V_96 -> V_34 ;
F_167 = V_96 -> F_167 ;
V_265 = V_96 -> V_265 ;
if ( V_34 )
F_96 ( & V_34 -> V_38 ) ;
switch ( V_96 -> V_200 ) {
case V_255 :
V_96 -> V_200 = V_266 ;
break;
case V_212 :
V_96 -> V_200 = V_267 ;
break;
case V_207 :
V_96 -> V_200 = V_268 ;
break;
default:
snprintf ( V_198 , V_199 , L_80 , V_96 , V_96 -> V_200 ) ;
F_137 ( & V_2 -> V_52 -> V_53 ,
L_65
L_66 , V_198 ) ;
F_138 () ;
}
if ( V_96 -> F_167 != NULL )
( F_167 ) ( V_96 , V_265 ) ;
if ( V_34 )
F_97 ( & V_34 -> V_38 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
if ( F_56 ( & V_2 -> V_15 ) )
return;
V_96 = F_160 ( V_2 -> V_15 . V_230 , struct V_95 , V_256 ) ;
if ( ( V_96 -> V_200 == V_201 && V_96 -> V_225 != 0 ) &&
( F_170 ( V_213 , V_96 -> V_225 + V_96 -> V_203 ) ) ) {
if ( F_140 ( V_269 , & V_2 -> V_191 ) ) {
V_96 -> V_197 ++ ;
}
if ( V_2 -> V_59 -> V_270 ( V_96 ) != 0 ) {
F_137 ( & V_2 -> V_52 -> V_53 ,
L_81
L_82 ,
V_96 , ( V_96 -> V_225 / V_271 ) ) ;
V_96 -> V_225 += 5 * V_271 ;
F_147 ( V_2 , 5 * V_271 ) ;
} else {
F_137 ( & V_2 -> V_52 -> V_53 ,
L_83
L_84 , V_96 , ( V_96 -> V_225 / V_271 ) ,
V_96 -> V_197 ) ;
}
}
}
static int F_171 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
int V_272 = ~ ( V_273 | V_274 ) ;
if ( F_140 ( V_260 , & V_2 -> V_191 ) ) {
return 1 ;
}
if ( V_2 -> V_257 ) {
if ( V_2 -> V_257 & V_272 ) {
return 1 ;
}
if ( ! F_140 ( V_214 , & V_96 -> V_191 ) ) {
return 1 ;
}
}
return 0 ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
int V_40 ;
if ( F_56 ( & V_2 -> V_15 ) )
return;
V_96 = F_160 ( V_2 -> V_15 . V_230 , struct V_95 , V_256 ) ;
if ( V_96 -> V_200 != V_228 )
return;
if ( F_171 ( V_2 , V_96 ) ) {
V_96 -> V_209 = - V_65 ;
V_96 -> V_200 = V_207 ;
F_76 ( V_2 ) ;
return;
}
V_40 = V_2 -> V_59 -> V_258 ( V_96 ) ;
if ( V_40 == 0 )
F_147 ( V_2 , V_96 -> V_225 ) ;
else if ( V_40 == - V_219 ) {
F_76 ( V_2 ) ;
} else
F_147 ( V_2 , 50 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_216 . V_222 ) {
if ( V_2 -> V_257 & ~ ( V_273 |
V_274 ) )
return;
V_40 = V_2 -> V_59 -> V_275 (
V_2 , V_2 -> V_216 . V_222 ) ;
if ( V_40 )
F_147 ( V_2 , 50 ) ;
else
V_2 -> V_216 . V_222 = 0 ;
}
}
int F_45 ( struct V_1 * V_2 )
{
struct V_95 * V_96 , * V_263 ;
int V_40 ;
struct V_99 V_276 ;
F_12 ( & V_276 ) ;
F_174 ( F_145 ( V_2 -> V_52 ) ) ;
V_40 = 0 ;
F_175 (cqr, n, &device->ccw_queue, devlist) {
switch ( V_96 -> V_200 ) {
case V_201 :
V_40 = V_2 -> V_59 -> V_270 ( V_96 ) ;
if ( V_40 ) {
F_137 ( & V_2 -> V_52 -> V_53 ,
L_85
L_86 , V_96 ) ;
goto V_277;
}
break;
case V_228 :
V_96 -> V_148 = F_136 () ;
V_96 -> V_200 = V_207 ;
break;
default:
break;
}
F_165 ( & V_96 -> V_256 , & V_276 ) ;
}
V_277:
F_176 ( F_145 ( V_2 -> V_52 ) ) ;
F_175 (cqr, n, &flush_queue, devlist)
F_84 ( V_235 ,
( V_96 -> V_200 != V_202 ) ) ;
F_166 ( V_2 , & V_276 ) ;
return V_40 ;
}
static void V_14 ( struct V_1 * V_2 )
{
struct V_99 V_264 ;
F_10 ( & V_2 -> V_12 , 0 ) ;
F_12 ( & V_264 ) ;
F_174 ( F_145 ( V_2 -> V_52 ) ) ;
F_169 ( V_2 ) ;
F_164 ( V_2 , & V_264 ) ;
F_173 ( V_2 ) ;
F_176 ( F_145 ( V_2 -> V_52 ) ) ;
F_166 ( V_2 , & V_264 ) ;
F_174 ( F_145 ( V_2 -> V_52 ) ) ;
F_172 ( V_2 ) ;
F_176 ( F_145 ( V_2 -> V_52 ) ) ;
if ( F_177 ( & V_278 ) )
F_72 ( & V_278 ) ;
F_23 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( F_178 ( & V_2 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_2 ) ;
F_179 ( & V_2 -> V_13 ) ;
}
void F_180 ( struct V_1 * V_2 , int V_279 )
{
V_2 -> V_257 |= V_279 ;
}
void F_146 ( struct V_1 * V_2 , int V_279 )
{
V_2 -> V_257 &= ~ V_279 ;
if ( ! V_2 -> V_257 )
F_72 ( & V_280 ) ;
}
void F_181 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
unsigned long V_191 ;
V_2 = V_96 -> V_106 ;
F_126 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
V_96 -> V_200 = V_228 ;
F_182 ( & V_96 -> V_256 , & V_2 -> V_15 ) ;
F_76 ( V_2 ) ;
F_128 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
}
void F_183 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
unsigned long V_191 ;
V_2 = V_96 -> V_106 ;
F_126 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
V_96 -> V_200 = V_228 ;
F_184 ( & V_96 -> V_256 , & V_2 -> V_15 ) ;
F_76 ( V_2 ) ;
F_128 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
}
void F_185 ( struct V_95 * V_96 , void * V_19 )
{
F_174 ( F_145 ( V_96 -> V_106 -> V_52 ) ) ;
V_96 -> V_265 = V_281 ;
F_176 ( F_145 ( V_96 -> V_106 -> V_52 ) ) ;
F_72 ( & V_280 ) ;
}
static inline int F_186 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_96 -> V_106 ;
F_174 ( F_145 ( V_2 -> V_52 ) ) ;
V_40 = ( V_96 -> V_265 == V_281 ) ;
F_176 ( F_145 ( V_2 -> V_52 ) ) ;
return V_40 ;
}
static int F_187 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
T_7 V_282 ;
if ( V_96 -> V_200 == V_283 )
return 0 ;
V_2 = V_96 -> V_106 ;
if ( F_140 ( V_190 , & V_96 -> V_191 ) ) {
if ( V_96 -> V_200 == V_268 ) {
V_2 -> V_59 -> V_284 ( V_96 ) ;
return 1 ;
}
if ( V_96 -> V_200 == V_267 ) {
V_282 = V_2 -> V_59 -> V_285 ( V_96 ) ;
V_282 ( V_96 ) ;
return 1 ;
}
if ( V_96 -> V_200 == V_286 )
F_188 ( V_96 , & V_96 -> V_229 ) ;
if ( V_96 -> V_287 ) {
F_189 ( V_2 , V_96 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_190 ( struct V_95 * V_96 )
{
if ( F_140 ( V_190 , & V_96 -> V_191 ) ) {
if ( V_96 -> V_287 )
return 1 ;
return ( ( V_96 -> V_200 != V_266 ) &&
( V_96 -> V_200 != V_286 ) ) ;
} else
return ( V_96 -> V_200 == V_283 ) ;
}
static int F_191 ( struct V_95 * V_288 , int V_289 )
{
struct V_1 * V_2 ;
int V_40 ;
struct V_99 V_15 ;
struct V_95 * V_96 ;
F_12 ( & V_15 ) ;
V_288 -> V_200 = V_283 ;
V_2 = V_288 -> V_106 ;
F_182 ( & V_288 -> V_290 , & V_15 ) ;
for ( V_96 = V_288 ; F_190 ( V_96 ) ;
V_96 = F_192 ( & V_15 ,
struct V_95 , V_290 ) ) {
if ( F_187 ( V_96 ) )
continue;
if ( V_96 -> V_200 != V_283 )
continue;
if ( F_140 ( V_210 , & V_2 -> V_191 ) &&
! F_140 ( V_211 , & V_96 -> V_191 ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_86 ;
continue;
}
if ( V_2 -> V_257 & ~ V_224 &&
F_140 ( V_291 , & V_96 -> V_191 ) &&
( ! F_193 ( V_2 ) ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_292 ;
continue;
}
if ( F_140 ( V_260 , & V_2 -> V_191 ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_205 ;
continue;
}
if ( ! F_140 ( V_214 , & V_96 -> V_191 ) ) {
if ( V_289 ) {
V_40 = F_194 (
V_280 , ! ( V_2 -> V_257 ) ) ;
if ( V_40 == - V_293 ) {
V_96 -> V_200 = V_286 ;
V_288 -> V_209 = V_40 ;
continue;
}
} else
F_84 ( V_280 , ! ( V_2 -> V_257 ) ) ;
}
if ( ! V_96 -> F_167 )
V_96 -> F_167 = F_185 ;
V_96 -> V_265 = V_294 ;
F_183 ( V_96 ) ;
if ( V_289 ) {
V_40 = F_194 (
V_280 , F_186 ( V_96 ) ) ;
if ( V_40 == - V_293 ) {
F_195 ( V_96 ) ;
F_84 ( V_280 ,
F_186 ( V_96 ) ) ;
V_96 -> V_200 = V_286 ;
V_288 -> V_209 = V_40 ;
continue;
}
} else
F_84 ( V_280 , F_186 ( V_96 ) ) ;
}
V_288 -> V_149 = F_136 () ;
if ( ( V_288 -> V_200 != V_266 ) &&
( V_288 -> V_209 != - V_293 ) )
F_188 ( V_288 , & V_288 -> V_229 ) ;
if ( V_288 -> V_200 == V_266 )
V_40 = 0 ;
else if ( V_288 -> V_209 )
V_40 = V_288 -> V_209 ;
else
V_40 = - V_206 ;
return V_40 ;
}
static inline int F_196 ( struct V_99 * V_15 )
{
struct V_95 * V_96 ;
F_197 (cqr, ccw_queue, blocklist) {
if ( V_96 -> V_265 != V_281 )
return 0 ;
}
return 1 ;
}
static int F_198 ( struct V_99 * V_15 , int V_289 )
{
struct V_1 * V_2 ;
struct V_95 * V_96 , * V_263 ;
T_6 * V_234 = NULL ;
int V_40 ;
V_295:
F_175 (cqr, n, ccw_queue, blocklist) {
V_2 = V_96 -> V_106 ;
if ( V_96 -> V_200 != V_283 )
continue;
if ( F_140 ( V_210 , & V_2 -> V_191 ) &&
! F_140 ( V_211 , & V_96 -> V_191 ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_86 ;
continue;
}
if ( V_2 -> V_257 & ~ V_224 &&
F_140 ( V_291 , & V_96 -> V_191 ) &&
! F_193 ( V_2 ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_65 ;
continue;
}
if ( V_289 ) {
V_40 = F_194 (
V_280 , ! V_2 -> V_257 ) ;
if ( V_40 == - V_293 ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = V_40 ;
continue;
}
} else
F_84 ( V_280 , ! ( V_2 -> V_257 ) ) ;
if ( ! V_96 -> F_167 )
V_96 -> F_167 = F_185 ;
V_96 -> V_265 = V_294 ;
F_183 ( V_96 ) ;
}
F_84 ( V_280 , F_196 ( V_15 ) ) ;
V_40 = 0 ;
F_175 (cqr, n, ccw_queue, blocklist) {
V_234 = F_158 ( & V_96 -> V_229 ) ;
if ( V_234 && V_234 [ 1 ] & V_241 &&
F_140 ( V_242 , & V_96 -> V_191 ) )
continue;
if ( F_157 ( & V_96 -> V_229 . V_237 ) == 0x40 &&
F_140 ( V_296 , & V_96 -> V_191 ) )
continue;
if ( V_96 -> V_106 != V_96 -> V_297 && ! V_96 -> V_287 &&
( V_96 -> V_200 == V_268 ||
V_96 -> V_200 == V_267 ) )
return - V_65 ;
if ( F_187 ( V_96 ) )
goto V_295;
}
return 0 ;
}
int F_199 ( struct V_95 * V_96 )
{
return F_191 ( V_96 , 0 ) ;
}
int F_200 ( struct V_99 * V_15 )
{
return F_198 ( V_15 , 0 ) ;
}
int F_201 ( struct V_95 * V_96 )
{
return F_191 ( V_96 , 1 ) ;
}
static inline int F_202 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
int V_40 ;
if ( F_56 ( & V_2 -> V_15 ) )
return 0 ;
V_96 = F_160 ( V_2 -> V_15 . V_230 , struct V_95 , V_256 ) ;
V_40 = V_2 -> V_59 -> V_270 ( V_96 ) ;
if ( ! V_40 )
V_96 -> V_197 ++ ;
return V_40 ;
}
int F_203 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = V_96 -> V_106 ;
if ( F_140 ( V_210 , & V_2 -> V_191 ) &&
! F_140 ( V_211 , & V_96 -> V_191 ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_86 ;
return - V_206 ;
}
F_174 ( F_145 ( V_2 -> V_52 ) ) ;
V_40 = F_202 ( V_2 ) ;
if ( V_40 ) {
F_176 ( F_145 ( V_2 -> V_52 ) ) ;
return V_40 ;
}
V_96 -> F_167 = F_185 ;
V_96 -> V_265 = V_294 ;
V_96 -> V_200 = V_228 ;
F_182 ( & V_96 -> V_256 , V_2 -> V_15 . V_230 ) ;
F_76 ( V_2 ) ;
F_176 ( F_145 ( V_2 -> V_52 ) ) ;
F_84 ( V_280 , F_186 ( V_96 ) ) ;
if ( V_96 -> V_200 == V_266 )
V_40 = 0 ;
else if ( V_96 -> V_209 )
V_40 = V_96 -> V_209 ;
else
V_40 = - V_206 ;
F_76 ( V_2 ) ;
if ( V_2 -> V_34 )
F_63 ( V_2 -> V_34 ) ;
return V_40 ;
}
int F_195 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_106 ;
unsigned long V_191 ;
int V_40 ;
V_40 = 0 ;
F_126 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
switch ( V_96 -> V_200 ) {
case V_228 :
V_96 -> V_200 = V_207 ;
if ( V_96 -> V_265 == V_294 )
V_96 -> V_265 = V_281 ;
break;
case V_201 :
V_40 = V_2 -> V_59 -> V_270 ( V_96 ) ;
if ( V_40 ) {
F_137 ( & V_2 -> V_52 -> V_53 ,
L_87 ,
V_96 , V_40 ) ;
} else {
V_96 -> V_148 = F_136 () ;
}
break;
default:
break;
}
F_128 ( F_145 ( V_2 -> V_52 ) , V_191 ) ;
F_76 ( V_2 ) ;
return V_40 ;
}
static void V_39 ( unsigned long V_223 )
{
unsigned long V_191 ;
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_223 ;
F_126 ( F_145 ( V_34 -> V_63 -> V_52 ) , V_191 ) ;
F_146 ( V_34 -> V_63 , V_224 ) ;
F_128 ( F_145 ( V_34 -> V_63 -> V_52 ) , V_191 ) ;
F_63 ( V_34 ) ;
}
void F_204 ( struct V_33 * V_34 , int V_225 )
{
if ( V_225 == 0 )
F_148 ( & V_34 -> V_16 ) ;
else
F_149 ( & V_34 -> V_16 , V_213 + V_225 ) ;
}
void F_44 ( struct V_33 * V_34 )
{
F_148 ( & V_34 -> V_16 ) ;
}
static void F_189 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
T_7 V_282 ;
if ( V_96 -> V_200 == V_266 )
F_39 ( V_298 , V_2 , L_1 , L_88 ) ;
else
F_137 ( & V_2 -> V_52 -> V_53 , L_89 ) ;
V_282 = V_2 -> V_59 -> V_299 ( V_96 ) ;
V_282 ( V_96 ) ;
}
static void F_205 ( struct V_33 * V_34 )
{
struct V_300 * V_301 ;
struct V_97 * V_98 ;
struct V_95 * V_96 ;
struct V_1 * V_297 ;
unsigned long V_191 ;
V_301 = V_34 -> V_300 ;
V_297 = V_34 -> V_63 ;
if ( V_301 == NULL )
return;
if ( V_297 -> V_26 < V_72 ) {
while ( ( V_98 = F_206 ( V_34 -> V_300 ) ) )
F_207 ( V_98 , - V_206 ) ;
return;
}
if ( V_297 -> V_257 && ! ( V_297 -> V_80 & V_302 ) )
return;
while ( ( V_98 = F_208 ( V_301 ) ) ) {
if ( V_297 -> V_80 & V_303 &&
F_88 ( V_98 ) == V_304 ) {
F_39 ( V_180 , V_297 ,
L_90 ,
V_98 ) ;
F_209 ( V_98 ) ;
F_207 ( V_98 , - V_206 ) ;
continue;
}
if ( F_140 ( V_305 , & V_297 -> V_191 ) &&
( V_297 -> V_80 & V_302 ||
F_210 ( V_98 ) ) ) {
F_39 ( V_180 , V_297 ,
L_91 ,
V_98 ) ;
F_209 ( V_98 ) ;
F_207 ( V_98 , - V_218 ) ;
continue;
}
V_96 = V_297 -> V_59 -> V_306 ( V_297 , V_34 , V_98 ) ;
if ( F_29 ( V_96 ) ) {
if ( F_104 ( V_96 ) == - V_208 )
break;
if ( F_104 ( V_96 ) == - V_4 )
break;
if ( F_104 ( V_96 ) == - V_65 ) {
if ( ! F_56 ( & V_34 -> V_15 ) )
break;
F_126 (
F_145 ( V_297 -> V_52 ) , V_191 ) ;
F_180 ( V_297 ,
V_224 ) ;
F_128 (
F_145 ( V_297 -> V_52 ) , V_191 ) ;
F_204 ( V_34 , V_271 / 2 ) ;
break;
}
F_39 ( V_180 , V_297 ,
L_92
L_93 ,
F_104 ( V_96 ) , V_98 ) ;
F_209 ( V_98 ) ;
F_207 ( V_98 , - V_206 ) ;
continue;
}
V_96 -> V_265 = ( void * ) V_98 ;
V_96 -> V_200 = V_283 ;
V_98 -> V_307 = V_96 ;
F_209 ( V_98 ) ;
F_184 ( & V_96 -> V_290 , & V_34 -> V_15 ) ;
F_12 ( & V_96 -> V_256 ) ;
F_85 ( V_34 , V_96 , V_98 ) ;
}
}
static void F_211 ( struct V_95 * V_96 )
{
struct V_97 * V_98 ;
int V_200 ;
int error = 0 ;
V_98 = (struct V_97 * ) V_96 -> V_265 ;
F_92 ( V_96 -> V_34 , V_96 , V_98 ) ;
V_200 = V_96 -> V_34 -> V_63 -> V_59 -> V_308 ( V_96 , V_98 ) ;
if ( V_200 < 0 )
error = V_200 ;
else if ( V_200 == 0 ) {
if ( V_96 -> V_209 == - V_86 )
error = - V_309 ;
else if ( V_96 -> V_209 == - V_292 ||
V_96 -> V_209 == - V_218 )
error = V_96 -> V_209 ;
else
error = - V_206 ;
}
F_207 ( V_98 , error ) ;
}
static void F_212 ( struct V_33 * V_34 ,
struct V_99 * V_264 )
{
struct V_99 * V_100 , * V_263 ;
struct V_95 * V_96 ;
T_7 V_282 ;
unsigned long V_191 ;
struct V_1 * V_63 = V_34 -> V_63 ;
V_310:
F_163 (l, n, &block->ccw_queue) {
V_96 = F_160 ( V_100 , struct V_95 , V_290 ) ;
if ( V_96 -> V_200 != V_266 &&
V_96 -> V_200 != V_286 &&
V_96 -> V_200 != V_267 &&
V_96 -> V_200 != V_268 )
continue;
if ( V_96 -> V_200 == V_268 ) {
V_63 -> V_59 -> V_284 ( V_96 ) ;
goto V_310;
}
if ( V_96 -> V_200 == V_267 ) {
V_282 = V_63 -> V_59 -> V_285 ( V_96 ) ;
if ( F_29 ( V_282 ( V_96 ) ) )
continue;
goto V_310;
}
if ( V_96 -> V_200 == V_286 ) {
F_188 ( V_96 , & V_96 -> V_229 ) ;
}
if ( F_193 ( V_63 ) &&
V_96 -> V_200 == V_286 ) {
F_213 ( V_63 , V_96 , V_311 ) ;
V_96 -> V_200 = V_283 ;
V_96 -> V_197 = 255 ;
F_126 ( F_145 ( V_63 -> V_52 ) , V_191 ) ;
F_180 ( V_63 , V_312 ) ;
F_128 ( F_145 ( V_63 -> V_52 ) ,
V_191 ) ;
goto V_310;
}
if ( V_96 -> V_287 ) {
F_189 ( V_63 , V_96 ) ;
goto V_310;
}
V_96 -> V_149 = F_136 () ;
F_165 ( & V_96 -> V_290 , V_264 ) ;
}
}
static void F_214 ( struct V_95 * V_96 , void * V_19 )
{
F_63 ( V_96 -> V_34 ) ;
}
static void F_215 ( struct V_33 * V_34 )
{
struct V_95 * V_96 ;
if ( F_56 ( & V_34 -> V_15 ) )
return;
F_197 (cqr, &block->ccw_queue, blocklist) {
if ( V_96 -> V_200 != V_283 )
continue;
if ( F_140 ( V_210 , & V_34 -> V_63 -> V_191 ) &&
! F_140 ( V_211 , & V_96 -> V_191 ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_86 ;
F_63 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_257 & ~ V_224 &&
F_140 ( V_291 , & V_96 -> V_191 ) &&
( ! F_193 ( V_34 -> V_63 ) ) ) {
V_96 -> V_200 = V_286 ;
V_96 -> V_209 = - V_292 ;
F_63 ( V_34 ) ;
continue;
}
if ( V_34 -> V_63 -> V_257 )
return;
if ( ! V_96 -> V_106 )
V_96 -> V_106 = V_34 -> V_63 ;
V_96 -> F_167 = F_214 ;
F_183 ( V_96 ) ;
}
}
static void V_37 ( struct V_33 * V_34 )
{
struct V_99 V_264 ;
struct V_99 * V_100 , * V_263 ;
struct V_95 * V_96 ;
F_10 ( & V_34 -> V_12 , 0 ) ;
F_12 ( & V_264 ) ;
F_87 ( & V_34 -> V_38 ) ;
F_212 ( V_34 , & V_264 ) ;
F_89 ( & V_34 -> V_38 ) ;
F_174 ( & V_34 -> V_36 ) ;
F_163 (l, n, &final_queue) {
V_96 = F_160 ( V_100 , struct V_95 , V_290 ) ;
F_168 ( & V_96 -> V_290 ) ;
F_211 ( V_96 ) ;
}
F_87 ( & V_34 -> V_38 ) ;
F_205 ( V_34 ) ;
F_215 ( V_34 ) ;
F_89 ( & V_34 -> V_38 ) ;
F_176 ( & V_34 -> V_36 ) ;
if ( F_177 ( & V_278 ) )
F_72 ( & V_278 ) ;
F_23 ( V_34 -> V_63 ) ;
}
static void F_216 ( struct V_95 * V_96 , void * V_19 )
{
F_72 ( & V_235 ) ;
}
static int F_217 ( struct V_95 * V_96 )
{
struct V_33 * V_34 = V_96 -> V_34 ;
struct V_97 * V_98 ;
unsigned long V_191 ;
if ( ! V_34 )
return - V_166 ;
F_126 ( & V_34 -> V_38 , V_191 ) ;
V_98 = (struct V_97 * ) V_96 -> V_265 ;
F_218 ( V_34 -> V_300 , V_98 ) ;
F_128 ( & V_34 -> V_38 , V_191 ) ;
return 0 ;
}
static int F_58 ( struct V_33 * V_34 )
{
struct V_95 * V_96 , * V_263 ;
int V_40 , V_168 ;
struct V_99 V_276 ;
F_12 ( & V_276 ) ;
F_96 ( & V_34 -> V_38 ) ;
V_40 = 0 ;
V_310:
F_175 (cqr, n, &block->ccw_queue, blocklist) {
if ( V_96 -> V_200 >= V_228 )
V_40 = F_195 ( V_96 ) ;
if ( V_40 < 0 )
break;
V_96 -> F_167 = F_216 ;
for ( V_168 = 0 ; V_96 != NULL ; V_96 = V_96 -> V_287 , V_168 ++ )
F_165 ( & V_96 -> V_290 , & V_276 ) ;
if ( V_168 > 1 )
goto V_310;
}
F_97 ( & V_34 -> V_38 ) ;
V_313:
F_175 (cqr, n, &flush_queue, blocklist) {
F_84 ( V_235 , ( V_96 -> V_200 < V_228 ) ) ;
if ( V_96 -> V_287 ) {
F_96 ( & V_34 -> V_38 ) ;
F_189 ( V_34 -> V_63 , V_96 ) ;
F_97 ( & V_34 -> V_38 ) ;
goto V_313;
}
F_174 ( & V_34 -> V_36 ) ;
V_96 -> V_149 = F_136 () ;
F_168 ( & V_96 -> V_290 ) ;
F_211 ( V_96 ) ;
F_176 ( & V_34 -> V_36 ) ;
}
return V_40 ;
}
void F_63 ( struct V_33 * V_34 )
{
if ( F_178 ( & V_34 -> V_12 , 0 , 1 ) != 0 )
return;
F_21 ( V_34 -> V_63 ) ;
F_179 ( & V_34 -> V_13 ) ;
}
static void F_219 ( struct V_300 * V_301 )
{
struct V_33 * V_34 ;
V_34 = V_301 -> V_314 ;
F_87 ( & V_34 -> V_38 ) ;
F_205 ( V_34 ) ;
F_215 ( V_34 ) ;
F_89 ( & V_34 -> V_38 ) ;
}
enum V_315 F_220 ( struct V_97 * V_98 )
{
struct V_95 * V_96 = V_98 -> V_307 ;
struct V_33 * V_34 = V_98 -> V_316 -> V_314 ;
struct V_1 * V_2 ;
int V_40 = 0 ;
if ( ! V_96 )
return V_317 ;
V_2 = V_96 -> V_106 ? V_96 -> V_106 : V_34 -> V_63 ;
if ( ! V_2 -> V_318 )
return V_319 ;
F_39 ( V_56 , V_2 ,
L_94 ,
V_96 , V_96 -> V_200 ) ;
F_87 ( & V_34 -> V_38 ) ;
F_87 ( F_145 ( V_2 -> V_52 ) ) ;
V_96 -> V_197 = - 1 ;
V_96 -> V_209 = - V_218 ;
if ( V_96 -> V_200 >= V_228 ) {
F_89 ( F_145 ( V_2 -> V_52 ) ) ;
V_40 = F_195 ( V_96 ) ;
} else if ( V_96 -> V_200 == V_283 ||
V_96 -> V_200 == V_267 ) {
V_96 -> V_200 = V_268 ;
F_89 ( F_145 ( V_2 -> V_52 ) ) ;
} else if ( V_96 -> V_200 == V_320 ) {
struct V_95 * V_321 , * V_322 , * V_323 ;
F_175 (searchcqr, nextcqr,
&block->ccw_queue, blocklist) {
V_323 = V_321 ;
while ( V_323 -> V_287 )
V_323 = V_323 -> V_287 ;
if ( V_323 != V_96 )
continue;
V_321 -> V_197 = - 1 ;
V_321 -> V_209 = - V_218 ;
if ( V_321 -> V_200 >= V_228 ) {
F_89 ( F_145 ( V_2 -> V_52 ) ) ;
V_40 = F_195 ( V_321 ) ;
F_87 ( F_145 ( V_2 -> V_52 ) ) ;
} else if ( ( V_321 -> V_200 == V_283 ) ||
( V_321 -> V_200 == V_267 ) ) {
V_321 -> V_200 = V_268 ;
V_40 = 0 ;
} else if ( V_321 -> V_200 == V_320 ) {
continue;
}
break;
}
F_89 ( F_145 ( V_2 -> V_52 ) ) ;
}
F_63 ( V_34 ) ;
F_89 ( & V_34 -> V_38 ) ;
return V_40 ? V_319 : V_317 ;
}
static int F_22 ( struct V_33 * V_34 )
{
V_34 -> V_300 = F_221 ( F_219 ,
& V_34 -> V_36 ) ;
if ( V_34 -> V_300 == NULL )
return - V_4 ;
V_34 -> V_300 -> V_314 = V_34 ;
return 0 ;
}
static void F_52 ( struct V_33 * V_34 )
{
int V_324 ;
if ( V_34 -> V_63 -> V_80 & V_81 ) {
V_324 = 2048 ;
} else {
V_324 = V_34 -> V_63 -> V_59 -> V_325 << V_34 -> V_71 ;
}
F_222 ( V_326 , V_34 -> V_300 ) ;
V_34 -> V_300 -> V_327 . V_328 = V_324 ;
F_223 ( V_34 -> V_300 ,
V_34 -> V_74 ) ;
F_224 ( V_34 -> V_300 , V_324 ) ;
F_225 ( V_34 -> V_300 , - 1L ) ;
F_226 ( V_34 -> V_300 , V_9 ) ;
F_227 ( V_34 -> V_300 , V_9 - 1 ) ;
}
static void F_26 ( struct V_33 * V_34 )
{
if ( V_34 -> V_300 ) {
F_228 ( V_34 -> V_300 ) ;
V_34 -> V_300 = NULL ;
}
}
static void F_59 ( struct V_33 * V_34 )
{
struct V_97 * V_98 ;
if ( ! V_34 -> V_300 )
return;
F_174 ( & V_34 -> V_36 ) ;
while ( ( V_98 = F_206 ( V_34 -> V_300 ) ) )
F_207 ( V_98 , - V_206 ) ;
F_176 ( & V_34 -> V_36 ) ;
}
static int F_229 ( struct V_329 * V_82 , T_8 V_174 )
{
struct V_1 * V_63 ;
int V_40 ;
V_63 = F_230 ( V_82 -> V_83 ) ;
if ( ! V_63 )
return - V_205 ;
F_231 ( & V_63 -> V_34 -> V_35 ) ;
if ( F_140 ( V_260 , & V_63 -> V_191 ) ) {
V_40 = - V_205 ;
goto V_330;
}
if ( ! F_232 ( V_63 -> V_59 -> V_331 ) ) {
V_40 = - V_166 ;
goto V_330;
}
if ( V_93 ) {
F_233 ( & V_63 -> V_52 -> V_53 ,
L_95
L_96 ) ;
V_40 = - V_86 ;
goto V_69;
}
if ( V_63 -> V_26 <= V_58 ) {
F_39 ( V_180 , V_63 , L_97 ,
L_98 ) ;
V_40 = - V_205 ;
goto V_69;
}
if ( ( V_174 & V_332 ) &&
( F_140 ( V_333 , & V_63 -> V_191 ) ||
( V_63 -> V_80 & V_303 ) ) ) {
V_40 = - V_334 ;
goto V_69;
}
F_23 ( V_63 ) ;
return 0 ;
V_69:
F_234 ( V_63 -> V_59 -> V_331 ) ;
V_330:
F_235 ( & V_63 -> V_34 -> V_35 ) ;
F_23 ( V_63 ) ;
return V_40 ;
}
static void F_236 ( struct V_61 * V_62 , T_8 V_174 )
{
struct V_1 * V_63 = F_230 ( V_62 ) ;
if ( V_63 ) {
F_235 ( & V_63 -> V_34 -> V_35 ) ;
F_234 ( V_63 -> V_59 -> V_331 ) ;
F_23 ( V_63 ) ;
}
}
static int F_237 ( struct V_329 * V_82 , struct V_335 * V_336 )
{
struct V_1 * V_63 ;
V_63 = F_230 ( V_82 -> V_83 ) ;
if ( ! V_63 )
return - V_205 ;
if ( ! V_63 -> V_59 ||
! V_63 -> V_59 -> V_337 ) {
F_23 ( V_63 ) ;
return - V_166 ;
}
V_63 -> V_59 -> V_337 ( V_63 -> V_34 , V_336 ) ;
V_336 -> V_338 = F_238 ( V_82 ) >> V_63 -> V_34 -> V_71 ;
F_23 ( V_63 ) ;
return 0 ;
}
static void
F_239 ( void )
{
#ifdef F_240
F_241 () ;
#endif
F_242 () ;
if ( V_339 != NULL ) {
F_243 ( V_339 ) ;
V_339 = NULL ;
}
F_244 () ;
F_245 () ;
if ( V_340 != NULL ) {
F_48 ( V_340 ) ;
V_340 = NULL ;
}
F_115 () ;
}
int F_246 ( struct V_1 * V_2 )
{
struct V_341 V_342 ;
struct V_343 V_344 ;
int V_40 ;
if ( ! V_345 )
return 0 ;
F_247 ( V_2 -> V_52 , & V_342 ) ;
memset ( & V_344 , 0 , sizeof( V_344 ) ) ;
V_344 . V_346 = V_342 . V_347 ;
V_344 . V_348 = sizeof( V_344 ) ;
V_40 = V_343 ( & V_344 ) ;
if ( V_40 == 0 || V_40 == 2 ) {
return V_344 . V_349 & 0x80 ;
} else {
F_117 ( V_56 , L_99 ,
V_342 . V_347 , V_40 ) ;
return 0 ;
}
}
static void F_248 ( void * V_19 , T_9 V_350 )
{
struct V_226 * V_52 = V_19 ;
int V_351 ;
V_351 = F_249 ( V_52 ) ;
if ( V_351 )
F_250 ( L_100 ,
F_34 ( & V_52 -> V_53 ) , V_351 ) ;
}
int F_251 ( struct V_226 * V_52 ,
struct V_352 * V_59 )
{
int V_351 ;
V_351 = F_252 ( V_52 ) ;
if ( V_351 ) {
F_151 ( V_56 , V_52 , L_1 ,
L_101
L_102 ) ;
return V_351 ;
}
V_52 -> V_353 = & F_155 ;
if ( ( F_253 ( V_52 , V_354 ) > 0 ) ||
( V_355 && F_254 ( F_34 ( & V_52 -> V_53 ) ) != 0 ) )
F_255 ( F_248 , V_52 ) ;
return 0 ;
}
void F_256 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 ) {
if ( V_2 -> V_59 -> V_356 )
V_2 -> V_59 -> V_356 ( V_2 ) ;
F_234 ( V_2 -> V_59 -> V_331 ) ;
V_2 -> V_59 = NULL ;
}
if ( V_2 -> V_357 ) {
F_234 ( V_2 -> V_357 -> V_331 ) ;
V_2 -> V_357 = NULL ;
}
}
void F_257 ( struct V_226 * V_52 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_52 -> V_353 = NULL ;
V_2 = F_258 ( V_52 ) ;
if ( F_29 ( V_2 ) ) {
F_259 ( V_52 ) ;
return;
}
if ( F_260 ( V_260 , & V_2 -> V_191 ) &&
! F_140 ( V_269 , & V_2 -> V_191 ) ) {
F_23 ( V_2 ) ;
F_259 ( V_52 ) ;
return;
}
F_81 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_261 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
F_259 ( V_52 ) ;
}
int F_262 ( struct V_226 * V_52 ,
struct V_352 * V_357 )
{
struct V_352 * V_59 ;
struct V_1 * V_2 ;
int V_40 ;
F_263 ( V_52 , V_354 , 0 ) ;
V_2 = F_264 ( V_52 ) ;
if ( F_29 ( V_2 ) )
return F_104 ( V_2 ) ;
V_59 = V_357 ;
if ( V_2 -> V_80 & V_358 ) {
if ( ! V_240 ) {
V_40 = F_265 ( V_359 ) ;
if ( V_40 ) {
F_250 ( L_103
L_104
L_105 ,
F_34 ( & V_52 -> V_53 ) , V_359 ,
V_40 ) ;
F_261 ( V_2 ) ;
return - V_205 ;
}
}
if ( ! V_240 ) {
F_250 ( L_106 ,
F_34 ( & V_52 -> V_53 ) ) ;
F_261 ( V_2 ) ;
return - V_205 ;
}
V_59 = V_240 ;
}
if ( ! F_232 ( V_357 -> V_331 ) ) {
F_261 ( V_2 ) ;
return - V_166 ;
}
if ( ! F_232 ( V_59 -> V_331 ) ) {
F_234 ( V_357 -> V_331 ) ;
F_261 ( V_2 ) ;
return - V_166 ;
}
V_2 -> V_357 = V_357 ;
V_2 -> V_59 = V_59 ;
V_40 = V_59 -> V_360 ( V_2 ) ;
if ( V_40 ) {
F_250 ( L_107 ,
F_34 ( & V_52 -> V_53 ) , V_59 -> V_43 , V_40 ) ;
F_234 ( V_59 -> V_331 ) ;
F_234 ( V_357 -> V_331 ) ;
F_261 ( V_2 ) ;
return V_40 ;
}
F_81 ( V_2 , V_79 ) ;
if ( V_2 -> V_26 <= V_41 ) {
F_250 ( L_108 ,
F_34 ( & V_52 -> V_53 ) ) ;
V_40 = - V_205 ;
F_81 ( V_2 , V_27 ) ;
if ( V_2 -> V_34 )
F_19 ( V_2 -> V_34 ) ;
F_261 ( V_2 ) ;
} else
F_266 ( L_109 ,
F_34 ( & V_52 -> V_53 ) ) ;
F_84 ( V_87 , F_82 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_267 ( struct V_226 * V_52 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_361 , V_35 , V_40 ;
V_40 = 0 ;
V_2 = F_258 ( V_52 ) ;
if ( F_29 ( V_2 ) )
return F_104 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_361 = V_2 -> V_34 -> V_82 ? 0 : - 1 ;
V_35 = F_268 ( & V_2 -> V_34 -> V_35 ) ;
if ( V_35 > V_361 ) {
if ( V_35 > 0 )
F_250 ( L_110 ,
F_34 ( & V_52 -> V_53 ) , V_35 ) ;
else
F_250 ( L_111 ,
F_34 ( & V_52 -> V_53 ) ) ;
F_269 ( V_260 , & V_2 -> V_191 ) ;
F_23 ( V_2 ) ;
return - V_208 ;
}
}
if ( F_140 ( V_269 , & V_2 -> V_191 ) ) {
if ( F_260 ( V_260 , & V_2 -> V_191 ) ) {
F_23 ( V_2 ) ;
return - V_208 ;
} else
F_269 ( V_362 , & V_2 -> V_191 ) ;
} else
if ( F_140 ( V_260 , & V_2 -> V_191 ) ) {
F_23 ( V_2 ) ;
return - V_208 ;
}
if ( F_270 ( V_362 , & V_2 -> V_191 ) &&
! F_260 ( V_269 , & V_2 -> V_191 ) ) {
V_40 = F_271 ( V_2 -> V_34 -> V_82 ) ;
if ( V_40 != 0 )
goto V_363;
F_76 ( V_2 ) ;
V_40 = F_194 ( V_278 ,
F_55 ( V_2 ) ) ;
if ( V_40 != 0 )
goto V_363;
}
F_124 ( V_260 , & V_2 -> V_191 ) ;
F_81 ( V_2 , V_27 ) ;
V_34 = V_2 -> V_34 ;
F_261 ( V_2 ) ;
if ( V_34 )
F_19 ( V_34 ) ;
return 0 ;
V_363:
F_269 ( V_362 , & V_2 -> V_191 ) ;
F_269 ( V_269 , & V_2 -> V_191 ) ;
F_269 ( V_260 , & V_2 -> V_191 ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
F_272 ( & V_2 -> V_52 -> V_53 , L_112
L_113 ) ;
F_39 ( V_56 , V_2 , L_1 , L_114 ) ;
F_213 ( V_2 , NULL , V_364 ) ;
if ( V_2 -> V_26 < V_58 )
return 0 ;
F_197 (cqr, &device->ccw_queue, devlist)
if ( ( V_96 -> V_200 == V_201 ) ||
( V_96 -> V_200 == V_202 ) ) {
V_96 -> V_200 = V_228 ;
V_96 -> V_197 ++ ;
}
F_180 ( V_2 , V_273 ) ;
F_46 ( V_2 ) ;
F_76 ( V_2 ) ;
return 1 ;
}
int F_273 ( struct V_1 * V_2 )
{
F_233 ( & V_2 -> V_52 -> V_53 , L_115
L_116 ) ;
F_39 ( V_56 , V_2 , L_1 , L_117 ) ;
F_146 ( V_2 , V_273 ) ;
if ( V_2 -> V_257 & V_274 ) {
F_146 ( V_2 , V_274 ) ;
F_80 ( V_2 ) ;
return 1 ;
}
F_76 ( V_2 ) ;
if ( V_2 -> V_34 )
F_63 ( V_2 -> V_34 ) ;
if ( ! V_2 -> V_257 )
F_72 ( & V_280 ) ;
return 1 ;
}
int F_274 ( struct V_226 * V_52 , int V_365 )
{
struct V_1 * V_2 ;
int V_351 ;
V_2 = F_152 ( V_52 ) ;
if ( F_29 ( V_2 ) )
return 0 ;
V_351 = 0 ;
switch ( V_365 ) {
case V_366 :
case V_367 :
case V_368 :
V_2 -> V_216 . V_217 = 0 ;
V_2 -> V_216 . V_220 = 0 ;
V_2 -> V_216 . V_221 = 0 ;
V_351 = F_143 ( V_2 ) ;
break;
case V_369 :
V_351 = 1 ;
if ( V_2 -> V_216 . V_217 )
V_351 = F_273 ( V_2 ) ;
break;
}
F_23 ( V_2 ) ;
return V_351 ;
}
void F_275 ( struct V_226 * V_52 , int * V_370 )
{
int V_371 ;
T_10 V_372 , V_373 ;
struct V_1 * V_2 ;
V_2 = F_152 ( V_52 ) ;
if ( F_29 ( V_2 ) )
return;
for ( V_371 = 0 ; V_371 < 8 ; V_371 ++ ) {
V_373 = 0x80 >> V_371 ;
if ( V_370 [ V_371 ] & V_374 ) {
V_372 = V_2 -> V_216 . V_217 ;
V_2 -> V_216 . V_217 &= ~ V_373 ;
V_2 -> V_216 . V_220 &= ~ V_373 ;
V_2 -> V_216 . V_221 &= ~ V_373 ;
if ( V_372 && ! V_2 -> V_216 . V_217 ) {
F_272 ( & V_2 -> V_52 -> V_53 ,
L_118
L_113 ) ;
F_39 ( V_56 , V_2 ,
L_1 , L_119 ) ;
F_213 ( V_2 , NULL , V_364 ) ;
F_180 ( V_2 ,
V_273 ) ;
}
}
if ( V_370 [ V_371 ] & V_375 ) {
V_2 -> V_216 . V_217 &= ~ V_373 ;
V_2 -> V_216 . V_220 &= ~ V_373 ;
V_2 -> V_216 . V_221 &= ~ V_373 ;
V_2 -> V_216 . V_222 |= V_373 ;
F_76 ( V_2 ) ;
}
if ( V_370 [ V_371 ] & V_376 ) {
if ( ! ( V_2 -> V_216 . V_217 & V_373 ) &&
! ( V_2 -> V_216 . V_222 & V_373 ) ) {
V_2 -> V_216 . V_222 |= V_373 ;
F_76 ( V_2 ) ;
}
F_39 ( V_56 , V_2 , L_1 ,
L_120 ) ;
if ( V_2 -> V_59 -> V_94 )
V_2 -> V_59 -> V_94 ( V_2 ) ;
}
}
F_23 ( V_2 ) ;
}
int F_276 ( struct V_1 * V_2 , T_10 V_215 )
{
if ( ! V_2 -> V_216 . V_217 && V_215 ) {
V_2 -> V_216 . V_217 = V_215 ;
F_273 ( V_2 ) ;
} else
V_2 -> V_216 . V_217 |= V_215 ;
return 0 ;
}
int F_277 ( struct V_226 * V_52 )
{
struct V_1 * V_2 = F_258 ( V_52 ) ;
struct V_99 V_377 ;
struct V_95 * V_96 , * V_263 ;
struct V_95 * V_287 ;
int V_40 ;
if ( F_29 ( V_2 ) )
return F_104 ( V_2 ) ;
F_124 ( V_378 , & V_2 -> V_191 ) ;
if ( V_2 -> V_59 -> V_379 )
V_40 = V_2 -> V_59 -> V_379 ( V_2 ) ;
F_180 ( V_2 , V_380 ) ;
F_12 ( & V_377 ) ;
F_174 ( F_145 ( V_52 ) ) ;
V_40 = 0 ;
F_175 (cqr, n, &device->ccw_queue, devlist) {
if ( V_96 -> V_200 == V_201 ) {
V_40 = V_2 -> V_59 -> V_270 ( V_96 ) ;
if ( V_40 ) {
F_137 ( & V_2 -> V_52 -> V_53 ,
L_121
L_122 , V_96 ) ;
F_176 ( F_145 ( V_52 ) ) ;
F_23 ( V_2 ) ;
return V_40 ;
}
}
F_165 ( & V_96 -> V_256 , & V_377 ) ;
}
F_176 ( F_145 ( V_52 ) ) ;
F_175 (cqr, n, &freeze_queue, devlist) {
F_84 ( V_235 ,
( V_96 -> V_200 != V_202 ) ) ;
if ( V_96 -> V_200 == V_207 )
V_96 -> V_200 = V_228 ;
if ( F_217 ( V_96 ) )
continue;
F_168 ( & V_96 -> V_256 ) ;
while ( V_96 -> V_287 != NULL ) {
V_287 = V_96 -> V_287 ;
F_278 ( & V_96 -> V_290 ) ;
F_279 ( V_96 , V_96 -> V_381 ) ;
V_96 = V_287 ;
}
if ( V_96 -> V_34 )
F_168 ( & V_96 -> V_290 ) ;
V_96 -> V_34 -> V_63 -> V_59 -> V_308 (
V_96 , (struct V_97 * ) V_96 -> V_265 ) ;
}
if ( ! F_56 ( & V_377 ) ) {
F_174 ( F_145 ( V_52 ) ) ;
F_280 ( & V_377 , & V_2 -> V_15 ) ;
F_176 ( F_145 ( V_52 ) ) ;
}
F_23 ( V_2 ) ;
return V_40 ;
}
int F_281 ( struct V_226 * V_52 )
{
struct V_1 * V_2 = F_258 ( V_52 ) ;
int V_40 = 0 ;
if ( F_29 ( V_2 ) )
return F_104 ( V_2 ) ;
F_146 ( V_2 ,
( V_380 | V_274 ) ) ;
F_76 ( V_2 ) ;
if ( V_2 -> V_59 -> V_92 && ! ( V_2 -> V_257 ) )
V_40 = V_2 -> V_59 -> V_92 ( V_2 ) ;
if ( V_40 || V_2 -> V_257 )
V_2 -> V_257 |= V_274 ;
if ( V_2 -> V_34 )
F_63 ( V_2 -> V_34 ) ;
F_269 ( V_378 , & V_2 -> V_191 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static struct V_95 * F_282 ( struct V_1 * V_2 ,
void * V_382 ,
int V_383 ,
int V_185 )
{
struct V_95 * V_96 ;
struct V_188 * V_193 ;
unsigned long * V_384 ;
V_96 = F_125 ( V_185 , 1 , V_383 , V_2 ) ;
if ( F_29 ( V_96 ) ) {
F_137 ( & V_2 -> V_52 -> V_53 ,
L_65
L_66 , L_123 ) ;
return V_96 ;
}
V_193 = V_96 -> V_189 ;
V_193 -> V_385 = V_386 ;
if ( F_283 ( V_382 , V_383 ) ) {
V_384 = ( unsigned long * ) ( V_96 -> V_19 ) ;
V_193 -> V_387 = ( V_388 ) ( V_389 ) V_384 ;
V_193 -> V_191 = V_390 ;
V_384 = F_284 ( V_384 , V_382 , V_383 ) ;
} else {
V_193 -> V_387 = ( V_388 ) ( V_389 ) V_382 ;
V_193 -> V_191 = 0 ;
}
V_193 -> V_391 = V_383 ;
V_96 -> V_106 = V_2 ;
V_96 -> V_381 = V_2 ;
V_96 -> V_225 = 10 * V_271 ;
V_96 -> V_197 = 256 ;
V_96 -> V_146 = F_136 () ;
V_96 -> V_200 = V_283 ;
return V_96 ;
}
int F_285 ( struct V_1 * V_2 , int V_185 ,
void * V_382 , int V_383 )
{
int V_351 ;
struct V_95 * V_96 ;
V_96 = F_282 ( V_2 , V_382 , V_383 ,
V_185 ) ;
if ( F_29 ( V_96 ) )
return F_104 ( V_96 ) ;
V_351 = F_199 ( V_96 ) ;
F_131 ( V_96 , V_96 -> V_381 ) ;
return V_351 ;
}
char * F_158 ( struct V_229 * V_229 )
{
struct V_392 * V_392 = NULL ;
char * V_234 = NULL ;
if ( F_286 ( & V_229 -> V_237 ) && ( V_229 -> V_237 . V_393 . V_394 == 0x01 ) ) {
if ( V_229 -> V_237 . V_393 . V_395 )
V_392 = F_287 ( (struct V_395 * ) ( unsigned long )
V_229 -> V_237 . V_393 . V_395 ) ;
if ( V_392 && V_392 -> V_396 == 64 && V_392 -> V_191 )
switch ( V_392 -> V_191 & 0x07 ) {
case 1 :
V_234 = V_392 -> V_397 . V_398 . V_234 ;
break;
case 2 :
V_234 = V_392 -> V_397 . V_399 . V_234 ;
break;
default:
break;
}
} else if ( V_229 -> V_251 . V_400 . V_401 . V_402 ) {
V_234 = V_229 -> V_403 ;
}
return V_234 ;
}
void F_288 ( struct V_226 * V_52 )
{
struct V_1 * V_2 ;
V_2 = F_258 ( V_52 ) ;
if ( F_29 ( V_2 ) )
return;
if ( V_2 -> V_34 )
F_63 ( V_2 -> V_34 ) ;
F_76 ( V_2 ) ;
F_84 ( V_278 , F_55 ( V_2 ) ) ;
}
static int T_11 F_289 ( void )
{
int V_40 ;
F_290 ( & V_87 ) ;
F_290 ( & V_235 ) ;
F_290 ( & V_280 ) ;
F_290 ( & V_278 ) ;
V_340 = F_36 ( L_33 , 1 , 1 , 8 * sizeof( long ) ) ;
if ( V_340 == NULL ) {
V_40 = - V_4 ;
goto V_404;
}
F_37 ( V_340 , & V_55 ) ;
F_38 ( V_340 , V_56 ) ;
F_117 ( V_57 , L_1 , L_2 ) ;
V_240 = NULL ;
F_116 () ;
V_40 = F_291 () ;
if ( V_40 )
goto V_404;
V_40 = F_292 () ;
if ( V_40 )
goto V_404;
V_40 = F_293 () ;
if ( V_40 )
goto V_404;
V_40 = F_294 () ;
if ( V_40 )
goto V_404;
#ifdef F_240
V_40 = F_295 () ;
if ( V_40 )
goto V_404;
#endif
return 0 ;
V_404:
F_296 ( L_124 ) ;
F_239 () ;
return V_40 ;
}
