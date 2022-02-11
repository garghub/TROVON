static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_2 ( V_2 ) ;
V_3 = F_3 ( & V_8 -> V_9 ) ;
if ( V_3 )
F_4 ( L_1 ) ;
F_5 ( V_2 ) ;
return;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_10 * V_11 = & V_5 -> V_12 ;
T_1 V_13 ;
int V_3 = - V_14 ;
if ( V_11 -> V_15 & 0x0FFFFFFF ) {
F_7 ( V_2 -> V_2 , L_2 ) ;
V_3 = - V_16 ;
goto V_17;
}
V_13 = ( V_11 -> V_18 >> V_19 ) * 4 ;
V_13 = ( V_13 + V_20 - 1 ) >> V_19 ;
V_13 =
( V_13 < V_11 -> V_21 ) ? V_13 : V_11 -> V_21 ;
V_5 -> V_22 = V_11 -> V_15 +
( V_13 << V_19 ) * 1024 ;
F_8 ( & V_5 -> V_23 ) ;
F_8 ( & V_5 -> V_24 ) ;
F_9 ( 0x00000000 , V_25 ) ;
F_9 ( 0x00000000 , V_26 ) ;
F_10 ( V_26 ) ;
F_9 ( F_10 ( V_27 ) | V_28 ,
V_27 ) ;
F_11 ( V_5 ) ;
F_9 ( V_11 -> V_29 , V_30 ) ;
return 0 ;
V_17:
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
if ( V_5 -> V_31 )
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_5 -> V_32 -> V_33 )
V_5 -> V_32 -> V_33 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_5 -> V_34 ) {
F_16 ( V_5 -> V_34 ) ;
V_5 -> V_34 = NULL ;
}
if ( V_5 -> V_35 ) {
struct V_10 * V_11 = & V_5 -> V_12 ;
F_17 ( & V_11 -> V_36 ) ;
F_18 (
F_19
( V_5 -> V_35 ) ,
V_11 -> V_15 ,
V_5 -> V_37 >> V_19 ) ;
F_20 ( & V_11 -> V_36 ) ;
F_21 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
}
F_22 ( V_2 ) ;
if ( V_5 -> V_38 ) {
F_23 ( V_5 -> V_38 , 1 ) ;
F_24 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
}
if ( V_5 -> V_39 ) {
F_25 ( V_5 -> V_39 ) ;
V_5 -> V_39 = NULL ;
}
if ( V_5 -> V_40 ) {
F_25 ( V_5 -> V_40 ) ;
V_5 -> V_40 = NULL ;
}
F_26 ( V_2 ) ;
F_27 ( V_5 ) ;
V_2 -> V_6 = NULL ;
}
F_28 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_4 * V_5 ;
unsigned long V_42 ;
unsigned long V_43 ;
int V_3 = - V_14 ;
struct V_44 * V_45 ;
struct V_46 * V_46 ;
V_5 = F_30 ( sizeof( * V_5 ) , V_47 ) ;
if ( V_5 == NULL )
return - V_14 ;
V_5 -> V_32 = (struct V_48 * ) V_41 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = ( void * ) V_5 ;
F_31 ( V_2 -> V_49 ) ;
V_5 -> V_50 = V_5 -> V_32 -> V_51 ;
V_42 = F_32 ( V_2 -> V_49 , V_52 ) ;
V_5 -> V_39 =
F_33 ( V_42 + V_53 , V_54 ) ;
if ( ! V_5 -> V_39 )
goto V_17;
V_5 -> V_40 = F_33 ( V_42 + V_5 -> V_32 -> V_55 ,
V_56 ) ;
if ( ! V_5 -> V_40 )
goto V_17;
F_34 ( V_2 ) ;
V_3 = V_5 -> V_32 -> V_57 ( V_2 ) ;
if ( V_3 )
goto V_17;
F_35 ( V_2 ) ;
V_3 = - V_14 ;
V_5 -> V_38 = F_36 ( V_58 | V_59 ) ;
if ( ! V_5 -> V_38 )
goto V_17;
F_37 ( V_5 -> V_38 , 1 ) ;
V_3 = F_38 ( V_2 , 0 ) ;
if ( V_3 )
goto V_17;
V_5 -> V_35 = F_39 ( ( void * ) 0 ,
V_60 , 0 ,
V_5 ) ;
if ( ! V_5 -> V_35 )
goto V_17;
V_5 -> V_34 = F_40 ( V_5 -> V_35 , 1 , 0 ) ;
if ( ! V_5 -> V_34 )
goto V_17;
F_41 ( F_19 ( V_5 -> V_35 ) , 0 ) ;
F_41 ( V_5 -> V_34 , 1 ) ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_9 ( 0x20000000 , V_61 ) ;
F_9 ( 0x30000000 , V_62 ) ;
F_42 () ;
V_3 = F_43 ( V_2 , V_5 -> V_50 ) ;
if ( V_3 )
goto V_17;
V_5 -> V_63 = 0 ;
V_5 -> V_64 [ 0 ] = 0 ;
V_5 -> V_64 [ 1 ] = 0 ;
V_5 -> V_64 [ 2 ] = 0 ;
F_44 ( & V_5 -> V_23 , V_43 ) ;
F_45 ( 0xFFFFFFFF , V_65 ) ;
F_45 ( 0x00000000 , V_66 ) ;
F_45 ( 0xFFFFFFFF , V_67 ) ;
F_46 ( & V_5 -> V_23 , V_43 ) ;
F_47 ( V_2 ) ;
V_2 -> V_68 = 1 ;
V_2 -> V_69 = 0xffffff ;
V_2 -> V_70 -> V_71 = V_72 ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 (connector, &dev->mode_config.connector_list,
head) {
V_46 = F_52 ( V_45 ) ;
switch ( V_46 -> type ) {
case V_73 :
case V_74 :
V_3 = F_53 ( V_2 ) ;
break;
}
}
if ( V_3 )
return V_3 ;
F_54 ( V_2 ) ;
#if 0
pm_runtime_enable(&dev->pdev->dev);
pm_runtime_set_active(&dev->pdev->dev);
#endif
return 0 ;
V_17:
F_12 ( V_2 ) ;
return V_3 ;
}
static int F_55 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_56 ( struct V_31 * V_75 )
{
#ifdef F_57
if ( V_75 ) {
V_75 -> V_76 . V_77 = V_75 -> V_32 -> F_56 ( V_75 ) ;
F_58 ( V_75 ) ;
}
#endif
}
static int F_59 ( struct V_1 * V_2 , void * V_78 ,
struct V_79 * V_80 )
{
struct V_4 * V_5 = F_60 ( V_2 ) ;
T_1 * V_81 = V_78 ;
V_5 -> V_82 = * V_81 ;
F_56 ( V_5 -> V_31 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_78 ,
struct V_79 * V_80 )
{
struct V_4 * V_5 = F_60 ( V_2 ) ;
T_1 * V_81 = V_78 ;
V_5 -> V_83 = * V_81 ;
F_56 ( V_5 -> V_31 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_78 ,
struct V_79 * V_80 )
{
struct V_84 * V_85 = V_78 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_44 * V_45 ;
struct V_90 * V_90 ;
int V_91 = 0 ;
T_2 V_92 ;
V_92 = V_85 -> V_93 ;
V_87 = F_63 ( V_2 , V_92 , V_94 ) ;
if ( ! V_87 ) {
F_64 ( V_2 -> V_2 , L_3 ) ;
return - V_16 ;
}
V_45 = F_65 ( V_87 ) ;
V_89 = V_45 -> V_95 -> V_89 ;
V_90 = F_66 ( V_89 ) ;
for ( V_91 = 0 ; V_91 < 256 ; V_91 ++ )
V_90 -> V_96 [ V_91 ] = V_85 -> V_97 [ V_91 ] ;
F_67 ( V_89 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , void * V_78 ,
struct V_79 * V_80 )
{
T_1 V_92 ;
T_3 V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 = NULL ;
struct V_103 * V_81 ;
struct V_86 * V_87 ;
struct V_44 * V_45 ;
struct V_104 * V_105 ;
int V_3 = 0 ;
int V_106 = V_107 ;
V_81 = (struct V_103 * ) V_78 ;
V_92 = V_81 -> V_92 ;
V_98 = V_81 -> V_108 ;
switch ( V_98 ) {
case V_109 :
V_100 = & V_81 -> V_102 ;
F_2 ( V_2 ) ;
V_87 = F_63 ( V_2 , V_92 ,
V_94 ) ;
if ( ! V_87 ) {
V_3 = - V_16 ;
goto V_110;
}
V_45 = F_65 ( V_87 ) ;
V_102 = F_69 ( V_2 ) ;
if ( ! V_102 ) {
V_3 = - V_14 ;
goto V_110;
}
{
V_102 -> clock = V_100 -> clock ;
V_102 -> V_111 = V_100 -> V_111 ;
V_102 -> V_112 = V_100 -> V_112 ;
V_102 -> V_113 = V_100 -> V_113 ;
V_102 -> V_114 = V_100 -> V_114 ;
V_102 -> V_115 = V_100 -> V_115 ;
V_102 -> V_116 = V_100 -> V_116 ;
V_102 -> V_117 = V_100 -> V_117 ;
V_102 -> V_118 = V_100 -> V_118 ;
V_102 -> V_119 = V_100 -> V_119 ;
V_102 -> V_120 = V_100 -> V_120 ;
V_102 -> V_121 = V_100 -> V_121 ;
V_102 -> V_122 = V_100 -> V_122 ;
V_102 -> type = V_100 -> type ;
strncpy ( V_102 -> V_123 , V_100 -> V_123 , V_124 ) ;
V_102 -> V_123 [ V_124 - 1 ] = 0 ;
}
V_105 = (struct V_104 * )
V_45 -> V_125 ;
if ( V_105 -> V_126 ) {
V_106 = V_105 -> V_126 ( V_45 , V_102 ) ;
V_81 -> V_78 = V_106 ;
}
if ( V_102 )
F_70 ( V_2 , V_102 ) ;
V_110:
F_5 ( V_2 ) ;
return V_3 ;
default:
F_64 ( V_2 -> V_2 , L_4 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , void * V_78 ,
struct V_79 * V_80 )
{
struct V_4 * V_5 = F_60 ( V_2 ) ;
struct V_128 * V_81 = V_78 ;
V_81 -> V_129 = V_5 -> V_130 ;
V_81 -> V_131 = V_5 -> V_37 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_79 * V_132 )
{
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , struct V_79 * V_132 )
{
}
static long F_74 ( struct V_133 * V_134 , unsigned int V_135 ,
unsigned long V_81 )
{
struct V_79 * V_80 = V_134 -> V_136 ;
struct V_1 * V_2 = V_80 -> V_137 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
static unsigned int V_138 ;
if ( V_138 == 1 && V_5 -> V_139 ) {
V_138 ++ ;
F_75 ( & V_2 -> V_49 -> V_2 ) ;
V_5 -> V_140 = 1 ;
}
return F_76 ( V_134 , V_135 , V_81 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_79 * V_132 )
{
}
static void F_78 ( struct V_141 * V_49 )
{
struct V_1 * V_2 = F_79 ( V_49 ) ;
F_80 ( V_2 ) ;
}
static int F_81 ( struct V_141 * V_49 , const struct V_142 * V_143 )
{
return F_82 ( V_49 , V_143 , & V_70 ) ;
}
static int T_4 F_83 ( void )
{
return F_84 ( & V_70 , & V_144 ) ;
}
static void T_5 F_85 ( void )
{
F_86 ( & V_70 , & V_144 ) ;
}
