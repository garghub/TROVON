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
unsigned long V_52 ;
int V_10 = - V_11 ;
struct V_53 * V_54 ;
struct V_55 * V_55 ;
V_4 = F_28 ( sizeof( * V_4 ) , V_56 ) ;
if ( V_4 == NULL )
return - V_11 ;
V_4 -> V_41 = (struct V_57 * ) V_50 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = ( void * ) V_4 ;
F_29 ( V_2 -> V_58 ) ;
if ( ! F_30 ( V_2 ) ) {
if ( F_31 ( V_2 -> V_58 ) )
F_32 ( V_2 -> V_2 , L_5 ) ;
}
V_4 -> V_59 = V_4 -> V_41 -> V_60 ;
V_51 = F_33 ( V_2 -> V_58 , V_61 ) ;
V_4 -> V_48 =
F_34 ( V_51 + V_62 , V_63 ) ;
if ( ! V_4 -> V_48 )
goto V_14;
V_4 -> V_49 = F_34 ( V_51 + V_4 -> V_41 -> V_64 ,
V_65 ) ;
if ( ! V_4 -> V_49 )
goto V_14;
V_10 = V_4 -> V_41 -> V_66 ( V_2 ) ;
if ( V_10 )
goto V_14;
F_35 ( V_2 ) ;
V_10 = - V_11 ;
V_4 -> V_47 = F_36 ( V_67 | V_68 ) ;
if ( ! V_4 -> V_47 )
goto V_14;
F_37 ( V_4 -> V_47 , 1 ) ;
V_10 = F_38 ( V_2 , 0 ) ;
if ( V_10 )
goto V_14;
V_4 -> V_44 = F_39 ( ( void * ) 0 ,
V_69 , 0 ,
V_4 ) ;
if ( ! V_4 -> V_44 )
goto V_14;
V_4 -> V_43 = F_40 ( V_4 -> V_44 , 1 , 0 ) ;
if ( ! V_4 -> V_43 )
goto V_14;
F_41 ( F_18 ( V_4 -> V_44 ) , 0 ) ;
F_41 ( V_4 -> V_43 , 1 ) ;
V_10 = F_3 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_8 ( 0x20000000 , V_70 ) ;
F_8 ( 0x30000000 , V_71 ) ;
F_42 () ;
if ( V_4 -> V_72 )
F_43 ( V_4 ) ;
V_10 = F_44 ( V_2 , V_4 -> V_59 ) ;
if ( V_10 )
goto V_14;
V_4 -> V_73 = 0 ;
V_4 -> V_74 [ 0 ] = 0 ;
V_4 -> V_74 [ 1 ] = 0 ;
V_4 -> V_74 [ 2 ] = 0 ;
F_45 ( & V_4 -> V_33 , V_52 ) ;
F_46 ( 0xFFFFFFFF , V_75 ) ;
F_46 ( 0x00000000 , V_76 ) ;
F_46 ( 0xFFFFFFFF , V_77 ) ;
F_47 ( & V_4 -> V_33 , V_52 ) ;
if ( F_30 ( V_2 ) && F_48 ( V_2 , V_78 ) )
F_49 ( V_2 ) ;
V_2 -> V_79 = 1 ;
V_2 -> V_80 = 0xffffff ;
V_2 -> V_81 -> V_82 = V_83 ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 (connector, &dev->mode_config.connector_list,
head) {
V_55 = F_54 ( V_54 ) ;
switch ( V_55 -> type ) {
case V_84 :
case V_85 :
V_10 = F_55 ( V_2 ) ;
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
static int F_56 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_57 ( struct V_86 * V_87 )
{
#ifdef F_58
if ( V_87 ) {
V_87 -> V_88 . V_89 = V_87 -> V_41 -> F_57 ( V_87 ) ;
F_59 ( V_87 ) ;
}
#endif
}
static int F_60 ( struct V_1 * V_2 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_3 * V_4 = F_61 ( V_2 ) ;
T_1 * V_93 = V_90 ;
V_4 -> V_94 = * V_93 ;
F_57 ( V_4 -> V_86 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_3 * V_4 = F_61 ( V_2 ) ;
T_1 * V_93 = V_90 ;
V_4 -> V_95 = * V_93 ;
F_57 ( V_4 -> V_86 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_96 * V_97 = V_90 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_53 * V_54 ;
struct V_102 * V_102 ;
int V_103 = 0 ;
T_2 V_104 ;
V_104 = V_97 -> V_105 ;
V_99 = F_64 ( V_2 , V_104 , V_106 ) ;
if ( ! V_99 ) {
F_65 ( V_2 -> V_2 , L_6 ) ;
return - V_13 ;
}
V_54 = F_66 ( V_99 ) ;
V_101 = V_54 -> V_107 -> V_101 ;
V_102 = F_67 ( V_101 ) ;
for ( V_103 = 0 ; V_103 < 256 ; V_103 ++ )
V_102 -> V_108 [ V_103 ] = V_97 -> V_109 [ V_103 ] ;
F_68 ( V_101 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , void * V_90 ,
struct V_91 * V_92 )
{
T_1 V_104 ;
T_3 V_110 ;
struct V_111 * V_112 ;
struct V_113 * V_114 = NULL ;
struct V_115 * V_93 ;
struct V_98 * V_99 ;
struct V_53 * V_54 ;
struct V_116 * V_117 ;
int V_10 = 0 ;
int V_118 = V_119 ;
V_93 = (struct V_115 * ) V_90 ;
V_104 = V_93 -> V_104 ;
V_110 = V_93 -> V_120 ;
switch ( V_110 ) {
case V_121 :
V_112 = & V_93 -> V_114 ;
F_70 ( & V_2 -> V_122 . V_123 ) ;
V_99 = F_64 ( V_2 , V_104 ,
V_106 ) ;
if ( ! V_99 ) {
V_10 = - V_13 ;
goto V_124;
}
V_54 = F_66 ( V_99 ) ;
V_114 = F_71 ( V_2 ) ;
if ( ! V_114 ) {
V_10 = - V_11 ;
goto V_124;
}
{
V_114 -> clock = V_112 -> clock ;
V_114 -> V_125 = V_112 -> V_125 ;
V_114 -> V_126 = V_112 -> V_126 ;
V_114 -> V_127 = V_112 -> V_127 ;
V_114 -> V_128 = V_112 -> V_128 ;
V_114 -> V_129 = V_112 -> V_129 ;
V_114 -> V_130 = V_112 -> V_130 ;
V_114 -> V_131 = V_112 -> V_131 ;
V_114 -> V_132 = V_112 -> V_132 ;
V_114 -> V_133 = V_112 -> V_133 ;
V_114 -> V_134 = V_112 -> V_134 ;
V_114 -> V_135 = V_112 -> V_135 ;
V_114 -> V_136 = V_112 -> V_136 ;
V_114 -> type = V_112 -> type ;
strncpy ( V_114 -> V_137 , V_112 -> V_137 , V_138 ) ;
V_114 -> V_137 [ V_138 - 1 ] = 0 ;
}
V_117 = (struct V_116 * )
V_54 -> V_139 ;
if ( V_117 -> V_140 ) {
V_118 = V_117 -> V_140 ( V_54 , V_114 ) ;
V_93 -> V_90 = V_118 ;
}
if ( V_114 )
F_72 ( V_2 , V_114 ) ;
V_124:
F_73 ( & V_2 -> V_122 . V_123 ) ;
return V_10 ;
default:
F_65 ( V_2 -> V_2 , L_7 ) ;
return - V_141 ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_3 * V_4 = F_61 ( V_2 ) ;
struct V_142 * V_93 = V_90 ;
V_93 -> V_143 = V_4 -> V_144 ;
V_93 -> V_145 = V_4 -> V_46 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_91 * V_146 )
{
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_91 * V_146 )
{
}
static long F_77 ( struct V_147 * V_148 , unsigned int V_149 ,
unsigned long V_93 )
{
struct V_91 * V_92 = V_148 -> V_150 ;
struct V_1 * V_2 = V_92 -> V_151 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
static unsigned int V_152 ;
if ( V_152 == 1 && V_4 -> V_153 ) {
V_152 ++ ;
F_78 ( & V_2 -> V_58 -> V_2 ) ;
V_4 -> V_154 = 1 ;
}
return F_79 ( V_148 , V_149 , V_93 ) ;
}
static void F_80 ( struct V_1 * V_2 , struct V_91 * V_146 )
{
}
static void F_81 ( struct V_155 * V_58 )
{
struct V_1 * V_2 = F_82 ( V_58 ) ;
F_83 ( V_2 ) ;
}
static int F_84 ( struct V_155 * V_58 , const struct V_156 * V_157 )
{
return F_85 ( V_58 , V_157 , & V_81 ) ;
}
static int T_4 F_86 ( void )
{
return F_87 ( & V_81 , & V_158 ) ;
}
static void T_5 F_88 ( void )
{
F_89 ( & V_81 , & V_158 ) ;
}
