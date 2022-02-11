static void F_1 ( struct V_1 * V_2 )
{
return;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 ;
T_1 V_9 ;
int V_10 = - V_11 ;
if ( V_7 -> V_12 & 0x0FFFFFFF ) {
F_3 ( V_2 -> V_2 , L_1 ) ;
V_10 = - V_13 ;
goto V_14;
}
V_9 = ( V_7 -> V_15 >> V_16 ) * 4 ;
V_9 = ( V_9 + V_17 - 1 ) >> V_16 ;
V_9 =
( V_9 < V_7 -> V_18 ) ? V_9 : V_7 -> V_18 ;
V_4 -> V_19 = V_7 -> V_12 +
( V_9 << V_16 ) * 1024 ;
F_4 ( & V_4 -> V_20 ) ;
F_4 ( & V_4 -> V_21 ) ;
F_5 ( 0x00000000 , V_22 ) ;
F_5 ( 0x00000000 , V_23 ) ;
F_6 ( V_23 ) ;
F_5 ( F_6 ( V_24 ) | V_25 ,
V_24 ) ;
F_7 ( V_4 ) ;
F_5 ( V_7 -> V_26 , V_27 ) ;
return 0 ;
V_14:
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 ) {
if ( V_4 -> V_28 )
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
if ( V_4 -> V_29 -> V_30 )
V_4 -> V_29 -> V_30 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( V_4 -> V_31 ) {
F_12 ( V_4 -> V_31 ) ;
V_4 -> V_31 = NULL ;
}
if ( V_4 -> V_32 ) {
struct V_6 * V_7 = & V_4 -> V_8 ;
F_13 ( & V_7 -> V_33 ) ;
F_14 (
F_15
( V_4 -> V_32 ) ,
V_7 -> V_12 ,
V_4 -> V_34 >> V_16 ) ;
F_16 ( & V_7 -> V_33 ) ;
F_17 ( V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
}
F_18 ( V_2 ) ;
if ( V_4 -> V_35 ) {
F_19 ( V_4 -> V_35 , 1 ) ;
F_20 ( V_4 -> V_35 ) ;
V_4 -> V_35 = NULL ;
}
if ( V_4 -> V_36 ) {
F_21 ( V_4 -> V_36 ) ;
V_4 -> V_36 = NULL ;
}
if ( V_4 -> V_37 ) {
F_21 ( V_4 -> V_37 ) ;
V_4 -> V_37 = NULL ;
}
F_22 ( V_2 ) ;
F_23 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
F_24 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_38 )
{
struct V_3 * V_4 ;
unsigned long V_39 ;
unsigned long V_40 ;
int V_10 = - V_11 ;
struct V_41 * V_42 ;
struct V_43 * V_43 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_44 ) ;
if ( V_4 == NULL )
return - V_11 ;
V_4 -> V_29 = (struct V_45 * ) V_38 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = ( void * ) V_4 ;
F_27 ( V_2 -> V_46 ) ;
V_4 -> V_47 = V_4 -> V_29 -> V_48 ;
V_39 = F_28 ( V_2 -> V_46 , V_49 ) ;
V_4 -> V_36 =
F_29 ( V_39 + V_50 , V_51 ) ;
if ( ! V_4 -> V_36 )
goto V_14;
V_4 -> V_37 = F_29 ( V_39 + V_4 -> V_29 -> V_52 ,
V_53 ) ;
if ( ! V_4 -> V_37 )
goto V_14;
F_30 ( V_2 ) ;
V_10 = V_4 -> V_29 -> V_54 ( V_2 ) ;
if ( V_10 )
goto V_14;
F_31 ( V_2 ) ;
V_10 = - V_11 ;
V_4 -> V_35 = F_32 ( V_55 | V_56 ) ;
if ( ! V_4 -> V_35 )
goto V_14;
F_33 ( V_4 -> V_35 , 1 ) ;
V_10 = F_34 ( V_2 , 0 ) ;
if ( V_10 )
goto V_14;
V_4 -> V_32 = F_35 ( ( void * ) 0 ,
V_57 , 0 ,
V_4 ) ;
if ( ! V_4 -> V_32 )
goto V_14;
V_4 -> V_31 = F_36 ( V_4 -> V_32 , 1 , 0 ) ;
if ( ! V_4 -> V_31 )
goto V_14;
F_37 ( F_15 ( V_4 -> V_32 ) , 0 ) ;
F_37 ( V_4 -> V_31 , 1 ) ;
V_10 = F_2 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_5 ( 0x20000000 , V_58 ) ;
F_5 ( 0x30000000 , V_59 ) ;
F_38 () ;
V_10 = F_39 ( V_2 , V_4 -> V_47 ) ;
if ( V_10 )
goto V_14;
V_4 -> V_60 = 0 ;
V_4 -> V_61 [ 0 ] = 0 ;
V_4 -> V_61 [ 1 ] = 0 ;
V_4 -> V_61 [ 2 ] = 0 ;
F_40 ( & V_4 -> V_20 , V_40 ) ;
F_41 ( 0xFFFFFFFF , V_62 ) ;
F_41 ( 0x00000000 , V_63 ) ;
F_41 ( 0xFFFFFFFF , V_64 ) ;
F_42 ( & V_4 -> V_20 , V_40 ) ;
F_43 ( V_2 ) ;
V_2 -> V_65 = 1 ;
V_2 -> V_66 = 0xffffff ;
V_2 -> V_67 -> V_68 = V_69 ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 (connector, &dev->mode_config.connector_list,
head) {
V_43 = F_48 ( V_42 ) ;
switch ( V_43 -> type ) {
case V_70 :
case V_71 :
V_10 = F_49 ( V_2 ) ;
break;
}
}
if ( V_10 )
return V_10 ;
F_50 ( V_2 ) ;
#if 0
pm_runtime_enable(&dev->pdev->dev);
pm_runtime_set_active(&dev->pdev->dev);
#endif
return 0 ;
V_14:
F_8 ( V_2 ) ;
return V_10 ;
}
static int F_51 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_52 ( struct V_28 * V_72 )
{
#ifdef F_53
if ( V_72 ) {
V_72 -> V_73 . V_74 = V_72 -> V_29 -> F_52 ( V_72 ) ;
F_54 ( V_72 ) ;
}
#endif
}
static int F_55 ( struct V_1 * V_2 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_3 * V_4 = F_56 ( V_2 ) ;
T_1 * V_78 = V_75 ;
V_4 -> V_79 = * V_78 ;
F_52 ( V_4 -> V_28 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_3 * V_4 = F_56 ( V_2 ) ;
T_1 * V_78 = V_75 ;
V_4 -> V_80 = * V_78 ;
F_52 ( V_4 -> V_28 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_81 * V_82 = V_75 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_41 * V_42 ;
struct V_87 * V_87 ;
int V_88 = 0 ;
T_2 V_89 ;
V_89 = V_82 -> V_90 ;
V_84 = F_59 ( V_2 , V_89 , V_91 ) ;
if ( ! V_84 ) {
F_60 ( V_2 -> V_2 , L_2 ) ;
return - V_13 ;
}
V_42 = F_61 ( V_84 ) ;
V_86 = V_42 -> V_92 -> V_86 ;
V_87 = F_62 ( V_86 ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ )
V_87 -> V_93 [ V_88 ] = V_82 -> V_94 [ V_88 ] ;
F_63 ( V_86 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , void * V_75 ,
struct V_76 * V_77 )
{
T_1 V_89 ;
T_3 V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 = NULL ;
struct V_100 * V_78 ;
struct V_83 * V_84 ;
struct V_41 * V_42 ;
struct V_101 * V_102 ;
int V_10 = 0 ;
int V_103 = V_104 ;
V_78 = (struct V_100 * ) V_75 ;
V_89 = V_78 -> V_89 ;
V_95 = V_78 -> V_105 ;
switch ( V_95 ) {
case V_106 :
V_97 = & V_78 -> V_99 ;
F_65 ( & V_2 -> V_107 . V_108 ) ;
V_84 = F_59 ( V_2 , V_89 ,
V_91 ) ;
if ( ! V_84 ) {
V_10 = - V_13 ;
goto V_109;
}
V_42 = F_61 ( V_84 ) ;
V_99 = F_66 ( V_2 ) ;
if ( ! V_99 ) {
V_10 = - V_11 ;
goto V_109;
}
{
V_99 -> clock = V_97 -> clock ;
V_99 -> V_110 = V_97 -> V_110 ;
V_99 -> V_111 = V_97 -> V_111 ;
V_99 -> V_112 = V_97 -> V_112 ;
V_99 -> V_113 = V_97 -> V_113 ;
V_99 -> V_114 = V_97 -> V_114 ;
V_99 -> V_115 = V_97 -> V_115 ;
V_99 -> V_116 = V_97 -> V_116 ;
V_99 -> V_117 = V_97 -> V_117 ;
V_99 -> V_118 = V_97 -> V_118 ;
V_99 -> V_119 = V_97 -> V_119 ;
V_99 -> V_120 = V_97 -> V_120 ;
V_99 -> V_121 = V_97 -> V_121 ;
V_99 -> type = V_97 -> type ;
strncpy ( V_99 -> V_122 , V_97 -> V_122 , V_123 ) ;
V_99 -> V_122 [ V_123 - 1 ] = 0 ;
}
V_102 = (struct V_101 * )
V_42 -> V_124 ;
if ( V_102 -> V_125 ) {
V_103 = V_102 -> V_125 ( V_42 , V_99 ) ;
V_78 -> V_75 = V_103 ;
}
if ( V_99 )
F_67 ( V_2 , V_99 ) ;
V_109:
F_68 ( & V_2 -> V_107 . V_108 ) ;
return V_10 ;
default:
F_60 ( V_2 -> V_2 , L_3 ) ;
return - V_126 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , void * V_75 ,
struct V_76 * V_77 )
{
struct V_3 * V_4 = F_56 ( V_2 ) ;
struct V_127 * V_78 = V_75 ;
V_78 -> V_128 = V_4 -> V_129 ;
V_78 -> V_130 = V_4 -> V_34 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_76 * V_131 )
{
return 0 ;
}
static void F_71 ( struct V_1 * V_2 , struct V_76 * V_131 )
{
}
static long F_72 ( struct V_132 * V_133 , unsigned int V_134 ,
unsigned long V_78 )
{
struct V_76 * V_77 = V_133 -> V_135 ;
struct V_1 * V_2 = V_77 -> V_136 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
static unsigned int V_137 ;
if ( V_137 == 1 && V_4 -> V_138 ) {
V_137 ++ ;
F_73 ( & V_2 -> V_46 -> V_2 ) ;
V_4 -> V_139 = 1 ;
}
return F_74 ( V_133 , V_134 , V_78 ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_76 * V_131 )
{
}
static void F_76 ( struct V_140 * V_46 )
{
struct V_1 * V_2 = F_77 ( V_46 ) ;
F_78 ( V_2 ) ;
}
static int F_79 ( struct V_140 * V_46 , const struct V_141 * V_142 )
{
return F_80 ( V_46 , V_142 , & V_67 ) ;
}
static int T_4 F_81 ( void )
{
return F_82 ( & V_67 , & V_143 ) ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_67 , & V_143 ) ;
}
