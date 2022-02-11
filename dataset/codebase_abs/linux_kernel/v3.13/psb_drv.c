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
if ( V_5 -> V_41 ) {
F_25 ( V_5 -> V_41 ) ;
V_5 -> V_41 = NULL ;
}
if ( V_5 -> V_42 )
F_26 ( V_5 -> V_42 ) ;
F_27 ( V_2 ) ;
F_28 ( V_5 ) ;
V_2 -> V_6 = NULL ;
}
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned long V_43 )
{
struct V_4 * V_5 ;
unsigned long V_44 , V_45 ;
unsigned long V_46 ;
int V_3 = - V_14 ;
struct V_47 * V_48 ;
struct V_49 * V_49 ;
V_5 = F_31 ( sizeof( * V_5 ) , V_50 ) ;
if ( V_5 == NULL )
return - V_14 ;
V_5 -> V_32 = (struct V_51 * ) V_43 ;
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = ( void * ) V_5 ;
F_32 ( V_2 -> V_52 ) ;
V_5 -> V_53 = V_5 -> V_32 -> V_54 ;
V_44 = F_33 ( V_2 -> V_52 , V_55 ) ;
V_5 -> V_39 =
F_34 ( V_44 + V_56 , V_57 ) ;
if ( ! V_5 -> V_39 )
goto V_17;
V_5 -> V_40 = F_34 ( V_44 + V_5 -> V_32 -> V_58 ,
V_59 ) ;
if ( ! V_5 -> V_40 )
goto V_17;
if ( F_35 ( V_2 ) ) {
V_5 -> V_42 = F_36 ( 0 , F_37 ( 3 , 0 ) ) ;
if ( V_5 -> V_42 ) {
V_44 = F_33 ( V_5 -> V_42 ,
V_60 ) ;
V_45 = F_38 ( V_5 -> V_42 ,
V_60 ) ;
V_5 -> V_41 = F_39 ( V_44 ,
V_45 ) ;
if ( ! V_5 -> V_41 )
goto V_17;
F_40 ( L_3 ) ;
} else {
V_5 -> V_41 = V_5 -> V_39 ;
F_40 ( L_4 ) ;
}
V_5 -> V_61 = V_5 -> V_41 ;
} else {
V_5 -> V_61 = V_5 -> V_39 ;
}
F_41 ( V_2 ) ;
V_3 = V_5 -> V_32 -> V_62 ( V_2 ) ;
if ( V_3 )
goto V_17;
F_42 ( V_2 ) ;
V_3 = - V_14 ;
V_5 -> V_38 = F_43 ( V_63 | V_64 ) ;
if ( ! V_5 -> V_38 )
goto V_17;
F_44 ( V_5 -> V_38 , 1 ) ;
V_3 = F_45 ( V_2 , 0 ) ;
if ( V_3 )
goto V_17;
V_5 -> V_35 = F_46 ( ( void * ) 0 ,
V_65 , 0 ,
V_5 ) ;
if ( ! V_5 -> V_35 )
goto V_17;
V_5 -> V_34 = F_47 ( V_5 -> V_35 , 1 , 0 ) ;
if ( ! V_5 -> V_34 )
goto V_17;
F_48 ( F_19 ( V_5 -> V_35 ) , 0 ) ;
F_48 ( V_5 -> V_34 , 1 ) ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_9 ( 0x20000000 , V_66 ) ;
F_9 ( 0x30000000 , V_67 ) ;
F_49 () ;
V_3 = F_50 ( V_2 , V_5 -> V_53 ) ;
if ( V_3 )
goto V_17;
V_5 -> V_68 = 0 ;
V_5 -> V_69 [ 0 ] = 0 ;
V_5 -> V_69 [ 1 ] = 0 ;
V_5 -> V_69 [ 2 ] = 0 ;
F_51 ( & V_5 -> V_23 , V_46 ) ;
F_52 ( 0xFFFFFFFF , V_70 ) ;
F_52 ( 0x00000000 , V_71 ) ;
F_52 ( 0xFFFFFFFF , V_72 ) ;
F_53 ( & V_5 -> V_23 , V_46 ) ;
F_54 ( V_2 ) ;
V_2 -> V_73 = true ;
V_2 -> V_74 = 0xffffff ;
V_2 -> V_75 -> V_76 = V_77 ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 (connector, &dev->mode_config.connector_list,
head) {
V_49 = F_59 ( V_48 ) ;
switch ( V_49 -> type ) {
case V_78 :
case V_79 :
V_3 = F_60 ( V_2 ) ;
break;
}
}
if ( V_3 )
return V_3 ;
F_61 ( V_2 ) ;
#if 0
pm_runtime_enable(&dev->pdev->dev);
pm_runtime_set_active(&dev->pdev->dev);
#endif
return 0 ;
V_17:
F_12 ( V_2 ) ;
return V_3 ;
}
static int F_62 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_63 ( struct V_31 * V_80 )
{
#ifdef F_64
if ( V_80 ) {
V_80 -> V_81 . V_82 = V_80 -> V_32 -> F_63 ( V_80 ) ;
F_65 ( V_80 ) ;
}
#endif
}
static int F_66 ( struct V_1 * V_2 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_4 * V_5 = F_67 ( V_2 ) ;
T_1 * V_86 = V_83 ;
V_5 -> V_87 = * V_86 ;
F_63 ( V_5 -> V_31 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_4 * V_5 = F_67 ( V_2 ) ;
T_1 * V_86 = V_83 ;
V_5 -> V_88 = * V_86 ;
F_63 ( V_5 -> V_31 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_89 * V_90 = V_83 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_47 * V_48 ;
struct V_95 * V_95 ;
int V_96 = 0 ;
T_2 V_97 ;
V_97 = V_90 -> V_98 ;
V_92 = F_70 ( V_2 , V_97 , V_99 ) ;
if ( ! V_92 ) {
F_71 ( V_2 -> V_2 , L_5 ) ;
return - V_100 ;
}
V_48 = F_72 ( V_92 ) ;
V_94 = V_48 -> V_101 -> V_94 ;
V_95 = F_73 ( V_94 ) ;
for ( V_96 = 0 ; V_96 < 256 ; V_96 ++ )
V_95 -> V_102 [ V_96 ] = V_90 -> V_103 [ V_96 ] ;
F_74 ( V_94 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , void * V_83 ,
struct V_84 * V_85 )
{
T_1 V_97 ;
T_3 V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 = NULL ;
struct V_109 * V_86 ;
struct V_91 * V_92 ;
struct V_47 * V_48 ;
struct V_110 * V_111 ;
int V_3 = 0 ;
int V_112 = V_113 ;
V_86 = (struct V_109 * ) V_83 ;
V_97 = V_86 -> V_97 ;
V_104 = V_86 -> V_114 ;
switch ( V_104 ) {
case V_115 :
V_106 = & V_86 -> V_108 ;
F_2 ( V_2 ) ;
V_92 = F_70 ( V_2 , V_97 ,
V_99 ) ;
if ( ! V_92 ) {
V_3 = - V_100 ;
goto V_116;
}
V_48 = F_72 ( V_92 ) ;
V_108 = F_76 ( V_2 ) ;
if ( ! V_108 ) {
V_3 = - V_14 ;
goto V_116;
}
{
V_108 -> clock = V_106 -> clock ;
V_108 -> V_117 = V_106 -> V_117 ;
V_108 -> V_118 = V_106 -> V_118 ;
V_108 -> V_119 = V_106 -> V_119 ;
V_108 -> V_120 = V_106 -> V_120 ;
V_108 -> V_121 = V_106 -> V_121 ;
V_108 -> V_122 = V_106 -> V_122 ;
V_108 -> V_123 = V_106 -> V_123 ;
V_108 -> V_124 = V_106 -> V_124 ;
V_108 -> V_125 = V_106 -> V_125 ;
V_108 -> V_126 = V_106 -> V_126 ;
V_108 -> V_127 = V_106 -> V_127 ;
V_108 -> V_128 = V_106 -> V_128 ;
V_108 -> type = V_106 -> type ;
strncpy ( V_108 -> V_129 , V_106 -> V_129 , V_130 ) ;
V_108 -> V_129 [ V_130 - 1 ] = 0 ;
}
V_111 = (struct V_110 * )
V_48 -> V_131 ;
if ( V_111 -> V_132 ) {
V_112 = V_111 -> V_132 ( V_48 , V_108 ) ;
V_86 -> V_83 = V_112 ;
}
if ( V_108 )
F_77 ( V_2 , V_108 ) ;
V_116:
F_5 ( V_2 ) ;
return V_3 ;
default:
F_71 ( V_2 -> V_2 , L_6 ) ;
return - V_133 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , void * V_83 ,
struct V_84 * V_85 )
{
struct V_4 * V_5 = F_67 ( V_2 ) ;
struct V_134 * V_86 = V_83 ;
V_86 -> V_135 = V_5 -> V_136 ;
V_86 -> V_137 = V_5 -> V_37 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_84 * V_138 )
{
return 0 ;
}
static void F_80 ( struct V_1 * V_2 , struct V_84 * V_138 )
{
}
static long F_81 ( struct V_139 * V_140 , unsigned int V_141 ,
unsigned long V_86 )
{
struct V_84 * V_85 = V_140 -> V_142 ;
struct V_1 * V_2 = V_85 -> V_143 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
static unsigned int V_144 ;
if ( V_144 == 1 && V_5 -> V_145 ) {
V_144 ++ ;
F_82 ( & V_2 -> V_52 -> V_2 ) ;
V_5 -> V_146 = 1 ;
}
return F_83 ( V_140 , V_141 , V_86 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_84 * V_138 )
{
}
static void F_85 ( struct V_147 * V_52 )
{
struct V_1 * V_2 = F_86 ( V_52 ) ;
F_87 ( V_2 ) ;
}
static int F_88 ( struct V_147 * V_52 , const struct V_148 * V_149 )
{
return F_89 ( V_52 , V_149 , & V_75 ) ;
}
static int T_4 F_90 ( void )
{
return F_91 ( & V_75 , & V_150 ) ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_75 , & V_150 ) ;
}
