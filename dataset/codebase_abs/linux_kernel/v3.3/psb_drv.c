static void F_1 ( struct V_1 * V_2 )
{
return;
}
static void F_2 ( struct V_1 * V_2 )
{
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 ;
T_1 V_9 ;
int V_10 = - V_11 ;
if ( V_7 -> V_12 & 0x0FFFFFFF ) {
F_4 ( V_2 -> V_2 , L_1 ) ;
V_10 = - V_13 ;
goto V_14;
}
V_9 = ( V_7 -> V_15 >> V_16 ) * 4 ;
V_9 = ( V_9 + V_17 - 1 ) >> V_16 ;
V_9 =
( V_9 < V_7 -> V_18 ) ? V_9 : V_7 -> V_18 ;
V_4 -> V_19 = V_7 -> V_12 +
( V_9 << V_16 ) * 1024 ;
if ( 1 || V_20 ) {
T_1 V_21 = F_5 ( V_22 ) ;
T_1 V_23 = F_5 ( V_24 ) ;
F_6 ( L_2 , V_21 ) ;
F_6 ( L_3 ,
( V_23 & V_25 ) >>
V_26 ,
( V_23 & V_27 ) >>
V_28 ) ;
F_6
( L_4 ,
( V_23 & V_29 ) >>
V_30 ,
( V_23 & V_31 ) >>
V_32 ) ;
}
F_7 ( & V_4 -> V_33 ) ;
F_7 ( & V_4 -> V_34 ) ;
F_8 ( 0x00000000 , V_35 ) ;
F_8 ( 0x00000000 , V_36 ) ;
F_5 ( V_36 ) ;
F_8 ( F_5 ( V_37 ) | V_38 ,
V_37 ) ;
F_9 ( V_4 ) ;
F_8 ( V_7 -> V_39 , V_40 ) ;
return 0 ;
V_14:
F_2 ( V_2 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_4 ) {
F_13 ( V_4 ) ;
F_14 ( V_2 ) ;
if ( V_4 -> V_41 -> V_42 )
V_4 -> V_41 -> V_42 ( V_2 ) ;
F_2 ( V_2 ) ;
if ( V_4 -> V_43 ) {
F_15 ( V_4 -> V_43 ) ;
V_4 -> V_43 = NULL ;
}
if ( V_4 -> V_44 ) {
struct V_6 * V_7 = & V_4 -> V_8 ;
F_16 ( & V_7 -> V_45 ) ;
F_17 (
F_18
( V_4 -> V_44 ) ,
V_7 -> V_12 ,
V_4 -> V_46 >> V_16 ) ;
F_19 ( & V_7 -> V_45 ) ;
F_20 ( V_4 -> V_44 ) ;
V_4 -> V_44 = NULL ;
}
F_21 ( V_2 ) ;
if ( V_4 -> V_47 ) {
F_22 ( V_4 -> V_47 ) ;
V_4 -> V_47 = NULL ;
}
if ( V_4 -> V_48 ) {
F_23 ( V_4 -> V_48 ) ;
V_4 -> V_48 = NULL ;
}
if ( V_4 -> V_49 ) {
F_23 ( V_4 -> V_49 ) ;
V_4 -> V_49 = NULL ;
}
F_24 ( V_4 ) ;
V_2 -> V_5 = NULL ;
F_25 ( V_2 ) ;
}
F_26 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_50 )
{
struct V_3 * V_4 ;
unsigned long V_51 ;
struct V_6 * V_7 ;
unsigned long V_52 ;
int V_10 = - V_11 ;
T_1 V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_56 ;
V_4 = F_28 ( sizeof( * V_4 ) , V_57 ) ;
if ( V_4 == NULL )
return - V_11 ;
V_4 -> V_41 = (struct V_58 * ) V_50 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = ( void * ) V_4 ;
if ( ! F_29 ( V_2 ) ) {
if ( F_30 ( V_2 -> V_59 ) )
F_31 ( V_2 -> V_2 , L_5 ) ;
}
V_4 -> V_60 = V_4 -> V_41 -> V_61 ;
V_51 = F_32 ( V_2 -> V_59 , V_62 ) ;
V_4 -> V_48 =
F_33 ( V_51 + V_63 , V_64 ) ;
if ( ! V_4 -> V_48 )
goto V_14;
V_4 -> V_49 = F_33 ( V_51 + V_4 -> V_41 -> V_65 ,
V_66 ) ;
if ( ! V_4 -> V_49 )
goto V_14;
V_10 = V_4 -> V_41 -> V_67 ( V_2 ) ;
if ( V_10 )
goto V_14;
F_34 ( V_2 ) ;
V_10 = - V_11 ;
V_4 -> V_47 = F_35 ( V_68 | V_69 ) ;
if ( ! V_4 -> V_47 )
goto V_14;
F_36 ( V_4 -> V_47 , 1 ) ;
V_10 = F_37 ( V_2 , 0 ) ;
if ( V_10 )
goto V_14;
V_4 -> V_44 = F_38 ( ( void * ) 0 ,
V_70 , 0 ,
V_4 ) ;
if ( ! V_4 -> V_44 )
goto V_14;
V_7 = & V_4 -> V_8 ;
V_53 = ( V_7 -> V_71 < V_72 ) ?
( V_7 -> V_71 ) : V_72 ;
V_4 -> V_43 = F_39 ( V_4 -> V_44 , 1 , 0 ) ;
if ( ! V_4 -> V_43 )
goto V_14;
F_40 ( F_18 ( V_4 -> V_44 ) , 0 ) ;
F_40 ( V_4 -> V_43 , 1 ) ;
V_10 = F_3 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_8 ( 0x20000000 , V_73 ) ;
F_8 ( 0x30000000 , V_74 ) ;
F_41 () ;
if ( V_4 -> V_75 )
F_42 ( V_4 ) ;
V_10 = F_43 ( V_2 , V_4 -> V_60 ) ;
if ( V_10 )
goto V_14;
V_4 -> V_76 = 0 ;
V_4 -> V_77 [ 0 ] = 0 ;
V_4 -> V_77 [ 1 ] = 0 ;
V_4 -> V_77 [ 2 ] = 0 ;
F_44 ( & V_4 -> V_33 , V_52 ) ;
F_45 ( 0xFFFFFFFF , V_78 ) ;
F_45 ( 0x00000000 , V_79 ) ;
F_45 ( 0xFFFFFFFF , V_80 ) ;
F_46 ( & V_4 -> V_33 , V_52 ) ;
if ( F_29 ( V_2 ) && F_47 ( V_2 , V_81 ) )
F_48 ( V_2 ) ;
V_2 -> V_82 = 1 ;
V_2 -> V_83 = 0xffffff ;
V_2 -> V_84 -> V_85 = V_86 ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 (connector, &dev->mode_config.connector_list,
head) {
V_56 = F_53 ( V_55 ) ;
switch ( V_56 -> type ) {
case V_87 :
case V_88 :
V_10 = F_54 ( V_2 ) ;
break;
}
}
if ( V_10 )
return V_10 ;
#if 0
pm_runtime_enable(&dev->pdev->dev);
pm_runtime_set_active(&dev->pdev->dev);
#endif
return 0 ;
V_14:
F_10 ( V_2 ) ;
return V_10 ;
}
int F_55 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_56 ( struct V_89 * V_90 )
{
#ifdef F_57
if ( V_90 ) {
V_90 -> V_91 . V_92 = V_90 -> V_41 -> F_56 ( V_90 ) ;
F_58 ( V_90 ) ;
}
#endif
}
static int F_59 ( struct V_1 * V_2 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
T_1 * V_96 = V_93 ;
V_4 -> V_97 = * V_96 ;
F_56 ( V_4 -> V_89 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
T_1 * V_96 = V_93 ;
V_4 -> V_98 = * V_96 ;
F_56 ( V_4 -> V_89 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_99 * V_100 = V_93 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_54 * V_55 ;
struct V_105 * V_105 ;
int V_106 = 0 ;
T_2 V_107 ;
V_107 = V_100 -> V_108 ;
V_102 = F_63 ( V_2 , V_107 , V_109 ) ;
if ( ! V_102 ) {
F_64 ( V_2 -> V_2 , L_6 ) ;
return - V_13 ;
}
V_55 = F_65 ( V_102 ) ;
V_104 = V_55 -> V_110 -> V_104 ;
V_105 = F_66 ( V_104 ) ;
for ( V_106 = 0 ; V_106 < 256 ; V_106 ++ )
V_105 -> V_111 [ V_106 ] = V_100 -> V_112 [ V_106 ] ;
F_67 ( V_104 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , void * V_93 ,
struct V_94 * V_95 )
{
T_1 V_107 ;
T_3 V_113 ;
struct V_114 * V_115 ;
struct V_116 * V_117 = NULL ;
struct V_118 * V_96 ;
struct V_101 * V_102 ;
struct V_54 * V_55 ;
struct V_119 * V_120 ;
int V_10 = 0 ;
int V_121 = V_122 ;
V_96 = (struct V_118 * ) V_93 ;
V_107 = V_96 -> V_107 ;
V_113 = V_96 -> V_123 ;
switch ( V_113 ) {
case V_124 :
V_115 = & V_96 -> V_117 ;
F_69 ( & V_2 -> V_125 . V_126 ) ;
V_102 = F_63 ( V_2 , V_107 ,
V_109 ) ;
if ( ! V_102 ) {
V_10 = - V_13 ;
goto V_127;
}
V_55 = F_65 ( V_102 ) ;
V_117 = F_70 ( V_2 ) ;
if ( ! V_117 ) {
V_10 = - V_11 ;
goto V_127;
}
{
V_117 -> clock = V_115 -> clock ;
V_117 -> V_128 = V_115 -> V_128 ;
V_117 -> V_129 = V_115 -> V_129 ;
V_117 -> V_130 = V_115 -> V_130 ;
V_117 -> V_131 = V_115 -> V_131 ;
V_117 -> V_132 = V_115 -> V_132 ;
V_117 -> V_133 = V_115 -> V_133 ;
V_117 -> V_134 = V_115 -> V_134 ;
V_117 -> V_135 = V_115 -> V_135 ;
V_117 -> V_136 = V_115 -> V_136 ;
V_117 -> V_137 = V_115 -> V_137 ;
V_117 -> V_138 = V_115 -> V_138 ;
V_117 -> V_139 = V_115 -> V_139 ;
V_117 -> type = V_115 -> type ;
strncpy ( V_117 -> V_140 , V_115 -> V_140 , V_141 ) ;
V_117 -> V_140 [ V_141 - 1 ] = 0 ;
}
V_120 = (struct V_119 * )
V_55 -> V_142 ;
if ( V_120 -> V_143 ) {
V_121 = V_120 -> V_143 ( V_55 , V_117 ) ;
V_96 -> V_93 = V_121 ;
}
if ( V_117 )
F_71 ( V_2 , V_117 ) ;
V_127:
F_72 ( & V_2 -> V_125 . V_126 ) ;
return V_10 ;
default:
F_64 ( V_2 -> V_2 , L_7 ) ;
return - V_144 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
struct V_145 * V_96 = V_93 ;
V_96 -> V_146 = V_4 -> V_147 ;
V_96 -> V_148 = V_4 -> V_46 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_94 * V_149 )
{
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , struct V_94 * V_149 )
{
}
static long F_76 ( struct V_150 * V_151 , unsigned int V_152 ,
unsigned long V_96 )
{
struct V_94 * V_95 = V_151 -> V_153 ;
struct V_1 * V_2 = V_95 -> V_154 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
static unsigned int V_155 ;
if ( V_155 == 1 && V_4 -> V_156 ) {
V_155 ++ ;
F_77 ( & V_2 -> V_59 -> V_2 ) ;
V_4 -> V_157 = 1 ;
}
return F_78 ( V_151 , V_152 , V_96 ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_94 * V_149 )
{
}
static void F_80 ( struct V_158 * V_59 )
{
struct V_1 * V_2 = F_81 ( V_59 ) ;
F_82 ( V_2 ) ;
}
static int F_83 ( struct V_158 * V_59 , const struct V_159 * V_160 )
{
return F_84 ( V_59 , V_160 , & V_84 ) ;
}
static int T_4 F_85 ( void )
{
return F_86 ( & V_84 , & V_161 ) ;
}
static void T_5 F_87 ( void )
{
F_88 ( & V_84 , & V_161 ) ;
}
