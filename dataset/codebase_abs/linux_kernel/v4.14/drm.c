static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 . V_4 = V_4 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
F_4 ( V_8 , V_4 ) ;
F_5 ( V_8 , V_4 ) ;
F_6 ( V_8 , V_4 ,
V_9 ) ;
F_7 ( V_8 , V_4 ) ;
F_8 ( V_8 , V_4 ) ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_10 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 , struct V_1 ,
V_5 . V_6 ) ;
F_3 ( V_2 , V_2 -> V_5 . V_4 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_3 * V_4 , bool V_11 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_13 ;
V_13 = F_13 ( V_8 , V_4 ) ;
if ( V_13 )
return V_13 ;
F_14 ( & V_2 -> V_5 . V_14 ) ;
F_15 ( & V_2 -> V_5 . V_6 ) ;
V_13 = F_16 ( V_4 , true ) ;
if ( V_13 ) {
F_17 ( & V_2 -> V_5 . V_14 ) ;
F_8 ( V_8 , V_4 ) ;
return V_13 ;
}
F_18 ( V_4 ) ;
if ( V_11 )
F_1 ( V_2 , V_4 ) ;
else
F_3 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_5 . V_14 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 , unsigned long V_15 )
{
struct V_16 * V_17 = F_20 ( V_8 -> V_18 ) ;
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
if ( F_22 ( & V_21 ) ) {
T_1 V_22 , V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
unsigned long V_28 ;
V_2 -> V_29 = F_23 ( & V_21 ) ;
if ( ! V_2 -> V_29 ) {
V_13 = - V_20 ;
goto free;
}
V_27 = & V_2 -> V_29 -> V_27 ;
V_24 = V_27 -> V_30 ;
V_25 = V_27 -> V_31 - V_32 ;
V_22 = V_25 + 1 ;
V_23 = V_27 -> V_31 ;
V_28 = F_24 ( V_2 -> V_29 -> V_33 ) ;
F_25 ( & V_2 -> V_34 . V_29 , 1UL << V_28 ,
V_22 >> V_28 ,
V_23 >> V_28 ) ;
V_2 -> V_34 . V_35 = F_26 ( & V_2 -> V_34 . V_29 ) ;
V_2 -> V_34 . V_36 = V_23 >> V_2 -> V_34 . V_35 ;
F_27 ( & V_2 -> V_37 , V_24 , V_25 - V_24 + 1 ) ;
F_28 ( & V_2 -> V_38 ) ;
F_29 ( L_1 ) ;
F_29 ( L_2 , V_24 , V_25 ) ;
F_29 ( L_3 , V_22 ,
V_23 ) ;
}
F_28 ( & V_2 -> V_39 ) ;
F_30 ( & V_2 -> V_40 ) ;
F_28 ( & V_2 -> V_5 . V_14 ) ;
F_31 ( & V_2 -> V_5 . V_6 , F_10 ) ;
V_8 -> V_12 = V_2 ;
V_2 -> V_8 = V_8 ;
F_32 ( V_8 ) ;
V_8 -> V_41 . V_42 = 0 ;
V_8 -> V_41 . V_43 = 0 ;
V_8 -> V_41 . V_44 = 4096 ;
V_8 -> V_41 . V_45 = 4096 ;
V_8 -> V_41 . V_46 = true ;
V_8 -> V_41 . V_47 = & V_48 ;
V_13 = F_33 ( V_8 ) ;
if ( V_13 < 0 )
goto V_49;
F_34 ( V_8 ) ;
V_13 = F_35 ( V_17 ) ;
if ( V_13 < 0 )
goto V_50;
V_8 -> V_51 = true ;
V_8 -> V_52 = 0xffffffff ;
V_13 = F_36 ( V_8 , V_8 -> V_41 . V_53 ) ;
if ( V_13 < 0 )
goto V_17;
F_37 ( V_8 ) ;
V_13 = F_38 ( V_8 ) ;
if ( V_13 < 0 )
goto V_17;
return 0 ;
V_17:
F_39 ( V_17 ) ;
V_50:
F_40 ( V_8 ) ;
F_41 ( V_8 ) ;
V_49:
F_42 ( V_8 ) ;
if ( V_2 -> V_29 ) {
F_43 ( V_2 -> V_29 ) ;
F_44 ( & V_2 -> V_37 ) ;
F_45 ( & V_2 -> V_38 ) ;
F_46 ( & V_2 -> V_34 . V_29 ) ;
}
free:
F_47 ( V_2 ) ;
return V_13 ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = F_20 ( V_8 -> V_18 ) ;
struct V_1 * V_2 = V_8 -> V_12 ;
int V_13 ;
F_40 ( V_8 ) ;
F_49 ( V_8 ) ;
F_42 ( V_8 ) ;
V_13 = F_39 ( V_17 ) ;
if ( V_13 < 0 )
return;
if ( V_2 -> V_29 ) {
F_43 ( V_2 -> V_29 ) ;
F_44 ( & V_2 -> V_37 ) ;
F_45 ( & V_2 -> V_38 ) ;
F_46 ( & V_2 -> V_34 . V_29 ) ;
}
F_47 ( V_2 ) ;
}
static int F_50 ( struct V_7 * V_8 , struct V_54 * V_55 )
{
struct V_56 * V_57 ;
V_57 = F_21 ( sizeof( * V_57 ) , V_19 ) ;
if ( ! V_57 )
return - V_20 ;
F_51 ( & V_57 -> V_58 ) ;
F_28 ( & V_57 -> V_14 ) ;
V_55 -> V_59 = V_57 ;
return 0 ;
}
static void F_52 ( struct V_60 * V_61 )
{
V_61 -> V_62 -> V_63 -> V_64 ( V_61 ) ;
F_47 ( V_61 ) ;
}
static void F_53 ( struct V_7 * V_8 )
{
#ifdef F_54
struct V_1 * V_2 = V_8 -> V_12 ;
F_55 ( V_2 -> V_50 ) ;
#endif
}
static struct V_65 *
F_56 ( struct V_54 * V_66 , T_2 V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
V_69 = F_57 ( V_66 , V_67 ) ;
if ( ! V_69 )
return NULL ;
V_71 = F_58 ( V_69 ) ;
return & V_71 -> V_72 ;
}
static int F_59 ( struct V_73 * V_74 ,
struct V_75 T_3 * V_76 ,
struct V_7 * V_8 ,
struct V_54 * V_66 )
{
T_2 V_77 , V_78 ;
int V_13 ;
V_13 = F_60 ( V_77 , & V_76 -> V_77 . V_67 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_74 -> V_77 . V_79 , & V_76 -> V_77 . V_79 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_78 , & V_76 -> V_78 . V_67 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_74 -> V_78 . V_79 , & V_76 -> V_78 . V_79 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_74 -> V_35 , & V_76 -> V_35 ) ;
if ( V_13 < 0 )
return V_13 ;
V_74 -> V_77 . V_71 = F_56 ( V_66 , V_77 ) ;
if ( ! V_74 -> V_77 . V_71 )
return - V_80 ;
V_74 -> V_78 . V_71 = F_56 ( V_66 , V_78 ) ;
if ( ! V_74 -> V_78 . V_71 )
return - V_80 ;
return 0 ;
}
static int F_61 ( struct V_81 * V_74 ,
struct V_82 T_3 * V_76 ,
struct V_54 * V_66 )
{
T_2 V_77 ;
int V_13 ;
V_13 = F_60 ( V_77 , & V_76 -> V_67 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_74 -> V_79 , & V_76 -> V_79 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_74 -> V_83 , & V_76 -> V_84 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_60 ( V_74 -> V_85 , & V_76 -> V_85 ) ;
if ( V_13 < 0 )
return V_13 ;
V_74 -> V_71 = F_56 ( V_66 , V_77 ) ;
if ( ! V_74 -> V_71 )
return - V_80 ;
return 0 ;
}
int F_62 ( struct V_60 * V_61 ,
struct V_86 * args , struct V_7 * V_8 ,
struct V_54 * V_66 )
{
unsigned int V_87 = args -> V_87 ;
unsigned int V_88 = args -> V_88 ;
unsigned int V_89 = args -> V_89 ;
struct V_90 T_3 * V_91 =
( void T_3 * ) ( V_92 ) args -> V_91 ;
struct V_75 T_3 * V_93 =
( void T_3 * ) ( V_92 ) args -> V_93 ;
struct V_82 T_3 * V_94 =
( void T_3 * ) ( V_92 ) args -> V_94 ;
struct V_95 V_84 ;
struct V_96 * V_96 = F_63 ( V_8 -> V_18 -> V_97 ) ;
struct V_68 * * V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
unsigned int V_103 ;
int V_13 ;
if ( args -> V_104 != 1 )
return - V_105 ;
if ( args -> V_89 != 0 )
return - V_105 ;
V_102 = F_64 ( V_61 -> V_106 , args -> V_87 ,
args -> V_88 , args -> V_89 ) ;
if ( ! V_102 )
return - V_20 ;
V_102 -> V_88 = args -> V_88 ;
V_102 -> V_107 = args -> V_89 ;
V_102 -> V_62 = ( T_2 ) args -> V_61 ;
V_102 -> V_108 = V_61 -> V_62 -> V_72 . V_108 ;
V_102 -> V_109 = true ;
V_103 = V_87 + V_88 * 2 + V_89 ;
V_98 = F_65 ( V_103 , sizeof( * V_98 ) , V_19 ) ;
if ( ! V_98 ) {
V_13 = - V_20 ;
goto V_110;
}
V_103 = 0 ;
while ( V_87 ) {
struct V_90 V_77 ;
struct V_65 * V_71 ;
struct V_70 * V_111 ;
T_1 V_79 ;
if ( F_66 ( & V_77 , V_91 , sizeof( V_77 ) ) ) {
V_13 = - V_112 ;
goto V_113;
}
if ( V_77 . V_114 > V_115 ) {
V_13 = - V_105 ;
goto V_113;
}
V_71 = F_56 ( V_66 , V_77 . V_67 ) ;
if ( ! V_71 ) {
V_13 = - V_80 ;
goto V_113;
}
V_79 = ( T_1 ) V_77 . V_79 + ( T_1 ) V_77 . V_114 * sizeof( T_2 ) ;
V_111 = F_67 ( V_71 ) ;
V_98 [ V_103 ++ ] = & V_111 -> V_69 ;
if ( V_79 & 3 || V_79 >= V_111 -> V_69 . V_116 ) {
V_13 = - V_105 ;
goto V_113;
}
F_68 ( V_102 , V_71 , V_77 . V_114 , V_77 . V_79 ) ;
V_87 -- ;
V_91 ++ ;
}
while ( V_88 -- ) {
struct V_73 * V_117 ;
struct V_70 * V_111 ;
V_13 = F_59 ( & V_102 -> V_118 [ V_88 ] ,
& V_93 [ V_88 ] , V_8 ,
V_66 ) ;
if ( V_13 < 0 )
goto V_113;
V_117 = & V_102 -> V_118 [ V_88 ] ;
V_111 = F_67 ( V_117 -> V_77 . V_71 ) ;
V_98 [ V_103 ++ ] = & V_111 -> V_69 ;
if ( V_117 -> V_77 . V_79 & 3 ||
V_117 -> V_77 . V_79 >= V_111 -> V_69 . V_116 ) {
V_13 = - V_105 ;
goto V_113;
}
V_111 = F_67 ( V_117 -> V_78 . V_71 ) ;
V_98 [ V_103 ++ ] = & V_111 -> V_69 ;
if ( V_117 -> V_78 . V_79 >= V_111 -> V_69 . V_116 ) {
V_13 = - V_105 ;
goto V_113;
}
}
while ( V_89 -- ) {
struct V_81 * V_119 = & V_102 -> V_120 [ V_89 ] ;
struct V_70 * V_111 ;
V_13 = F_61 ( V_119 ,
& V_94 [ V_89 ] ,
V_66 ) ;
if ( V_13 < 0 )
goto V_113;
V_111 = F_67 ( V_119 -> V_71 ) ;
V_98 [ V_103 ++ ] = & V_111 -> V_69 ;
if ( V_119 -> V_79 & 3 ||
V_119 -> V_79 >= V_111 -> V_69 . V_116 ) {
V_13 = - V_105 ;
goto V_113;
}
}
if ( F_66 ( & V_84 , ( void T_3 * ) ( V_92 ) args -> V_121 ,
sizeof( V_84 ) ) ) {
V_13 = - V_112 ;
goto V_113;
}
V_100 = F_69 ( V_96 , V_84 . V_122 ) ;
if ( ! V_100 ) {
V_13 = - V_80 ;
goto V_113;
}
V_102 -> V_123 = V_61 -> V_62 -> V_63 -> V_123 ;
V_102 -> V_124 = V_61 -> V_62 -> V_63 -> V_124 ;
V_102 -> V_125 = V_84 . V_126 ;
V_102 -> V_83 = V_84 . V_122 ;
V_102 -> V_127 = 10000 ;
if ( args -> V_127 && args -> V_127 < 10000 )
V_102 -> V_127 = args -> V_127 ;
V_13 = F_70 ( V_102 , V_61 -> V_62 -> V_72 . V_18 ) ;
if ( V_13 )
goto V_113;
V_13 = F_71 ( V_102 ) ;
if ( V_13 ) {
F_72 ( V_102 ) ;
goto V_113;
}
args -> V_128 = V_102 -> V_129 ;
V_113:
while ( V_103 -- )
F_73 ( V_98 [ V_103 ] ) ;
F_47 ( V_98 ) ;
V_110:
F_74 ( V_102 ) ;
return V_13 ;
}
static int F_75 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_131 * args = V_130 ;
struct V_70 * V_71 ;
V_71 = F_76 ( V_66 , V_8 , args -> V_116 , args -> V_15 ,
& args -> V_67 ) ;
if ( F_77 ( V_71 ) )
return F_78 ( V_71 ) ;
return 0 ;
}
static int F_79 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_132 * args = V_130 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
V_69 = F_57 ( V_66 , args -> V_67 ) ;
if ( ! V_69 )
return - V_105 ;
V_71 = F_58 ( V_69 ) ;
args -> V_79 = F_80 ( & V_71 -> V_69 . V_133 ) ;
F_73 ( V_69 ) ;
return 0 ;
}
static int F_81 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_96 * V_134 = F_63 ( V_8 -> V_18 -> V_97 ) ;
struct V_135 * args = V_130 ;
struct V_99 * V_100 ;
V_100 = F_69 ( V_134 , args -> V_122 ) ;
if ( ! V_100 )
return - V_105 ;
args -> V_136 = F_82 ( V_100 ) ;
return 0 ;
}
static int F_83 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_96 * V_96 = F_63 ( V_8 -> V_18 -> V_97 ) ;
struct V_137 * args = V_130 ;
struct V_99 * V_100 ;
V_100 = F_69 ( V_96 , args -> V_122 ) ;
if ( ! V_100 )
return - V_105 ;
return F_84 ( V_100 ) ;
}
static int F_85 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_96 * V_96 = F_63 ( V_8 -> V_18 -> V_97 ) ;
struct V_138 * args = V_130 ;
struct V_99 * V_100 ;
V_100 = F_69 ( V_96 , args -> V_122 ) ;
if ( ! V_100 )
return - V_105 ;
return F_86 ( V_100 , args -> V_85 , args -> V_127 ,
& args -> V_136 ) ;
}
static int F_87 ( struct V_56 * V_57 ,
struct V_139 * V_62 ,
struct V_60 * V_61 )
{
int V_13 ;
V_13 = V_62 -> V_63 -> V_140 ( V_62 , V_61 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_88 ( & V_57 -> V_58 , V_61 , 1 , 0 , V_19 ) ;
if ( V_13 < 0 ) {
V_62 -> V_63 -> V_64 ( V_61 ) ;
return V_13 ;
}
V_61 -> V_62 = V_62 ;
V_61 -> V_122 = V_13 ;
return 0 ;
}
static int F_89 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_56 * V_57 = V_66 -> V_59 ;
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_141 * args = V_130 ;
struct V_60 * V_61 ;
struct V_139 * V_62 ;
int V_13 = - V_142 ;
V_61 = F_21 ( sizeof( * V_61 ) , V_19 ) ;
if ( ! V_61 )
return - V_20 ;
F_14 ( & V_57 -> V_14 ) ;
F_90 (client, &tegra->clients, list)
if ( V_62 -> V_72 . V_108 == args -> V_62 ) {
V_13 = F_87 ( V_57 , V_62 , V_61 ) ;
if ( V_13 < 0 )
break;
args -> V_61 = V_61 -> V_122 ;
break;
}
if ( V_13 < 0 )
F_47 ( V_61 ) ;
F_17 ( & V_57 -> V_14 ) ;
return V_13 ;
}
static int F_91 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_56 * V_57 = V_66 -> V_59 ;
struct V_143 * args = V_130 ;
struct V_60 * V_61 ;
int V_13 = 0 ;
F_14 ( & V_57 -> V_14 ) ;
V_61 = F_92 ( & V_57 -> V_58 , args -> V_61 ) ;
if ( ! V_61 ) {
V_13 = - V_105 ;
goto V_144;
}
F_93 ( & V_57 -> V_58 , V_61 -> V_122 ) ;
F_52 ( V_61 ) ;
V_144:
F_17 ( & V_57 -> V_14 ) ;
return V_13 ;
}
static int F_94 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_56 * V_57 = V_66 -> V_59 ;
struct V_145 * args = V_130 ;
struct V_60 * V_61 ;
struct V_99 * V_84 ;
int V_13 = 0 ;
F_14 ( & V_57 -> V_14 ) ;
V_61 = F_92 ( & V_57 -> V_58 , args -> V_61 ) ;
if ( ! V_61 ) {
V_13 = - V_142 ;
goto V_144;
}
if ( args -> V_146 >= V_61 -> V_62 -> V_72 . V_104 ) {
V_13 = - V_105 ;
goto V_144;
}
V_84 = V_61 -> V_62 -> V_72 . V_121 [ args -> V_146 ] ;
args -> V_122 = F_95 ( V_84 ) ;
V_144:
F_17 ( & V_57 -> V_14 ) ;
return V_13 ;
}
static int F_96 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_56 * V_57 = V_66 -> V_59 ;
struct V_86 * args = V_130 ;
struct V_60 * V_61 ;
int V_13 ;
F_14 ( & V_57 -> V_14 ) ;
V_61 = F_92 ( & V_57 -> V_58 , args -> V_61 ) ;
if ( ! V_61 ) {
V_13 = - V_142 ;
goto V_144;
}
V_13 = V_61 -> V_62 -> V_63 -> V_147 ( V_61 , args , V_8 , V_66 ) ;
V_144:
F_17 ( & V_57 -> V_14 ) ;
return V_13 ;
}
static int F_97 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_56 * V_57 = V_66 -> V_59 ;
struct V_148 * args = V_130 ;
struct V_60 * V_61 ;
struct V_149 * V_72 ;
struct V_99 * V_84 ;
int V_13 = 0 ;
F_14 ( & V_57 -> V_14 ) ;
V_61 = F_92 ( & V_57 -> V_58 , args -> V_61 ) ;
if ( ! V_61 ) {
V_13 = - V_142 ;
goto V_144;
}
if ( args -> V_84 >= V_61 -> V_62 -> V_72 . V_104 ) {
V_13 = - V_105 ;
goto V_144;
}
V_84 = V_61 -> V_62 -> V_72 . V_121 [ args -> V_84 ] ;
V_72 = F_98 ( V_84 ) ;
if ( ! V_72 ) {
V_13 = - V_150 ;
goto V_144;
}
args -> V_122 = F_99 ( V_72 ) ;
V_144:
F_17 ( & V_57 -> V_14 ) ;
return V_13 ;
}
static int F_100 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_151 * args = V_130 ;
enum V_152 V_153 ;
struct V_68 * V_69 ;
unsigned long V_136 = 0 ;
struct V_70 * V_71 ;
switch ( args -> V_153 ) {
case V_154 :
V_153 = V_155 ;
if ( args -> V_136 != 0 )
return - V_105 ;
break;
case V_156 :
V_153 = V_157 ;
if ( args -> V_136 != 0 )
return - V_105 ;
break;
case V_158 :
V_153 = V_159 ;
if ( args -> V_136 > 5 )
return - V_105 ;
V_136 = args -> V_136 ;
break;
default:
return - V_105 ;
}
V_69 = F_57 ( V_66 , args -> V_67 ) ;
if ( ! V_69 )
return - V_80 ;
V_71 = F_58 ( V_69 ) ;
V_71 -> V_160 . V_153 = V_153 ;
V_71 -> V_160 . V_136 = V_136 ;
F_73 ( V_69 ) ;
return 0 ;
}
static int F_101 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_161 * args = V_130 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_13 = 0 ;
V_69 = F_57 ( V_66 , args -> V_67 ) ;
if ( ! V_69 )
return - V_80 ;
V_71 = F_58 ( V_69 ) ;
switch ( V_71 -> V_160 . V_153 ) {
case V_155 :
args -> V_153 = V_154 ;
args -> V_136 = 0 ;
break;
case V_157 :
args -> V_153 = V_156 ;
args -> V_136 = 0 ;
break;
case V_159 :
args -> V_153 = V_158 ;
args -> V_136 = V_71 -> V_160 . V_136 ;
break;
default:
V_13 = - V_105 ;
break;
}
F_73 ( V_69 ) ;
return V_13 ;
}
static int F_102 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_162 * args = V_130 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
if ( args -> V_15 & ~ V_163 )
return - V_105 ;
V_69 = F_57 ( V_66 , args -> V_67 ) ;
if ( ! V_69 )
return - V_80 ;
V_71 = F_58 ( V_69 ) ;
V_71 -> V_15 = 0 ;
if ( args -> V_15 & V_164 )
V_71 -> V_15 |= V_165 ;
F_73 ( V_69 ) ;
return 0 ;
}
static int F_103 ( struct V_7 * V_8 , void * V_130 ,
struct V_54 * V_66 )
{
struct V_166 * args = V_130 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
V_69 = F_57 ( V_66 , args -> V_67 ) ;
if ( ! V_69 )
return - V_80 ;
V_71 = F_58 ( V_69 ) ;
args -> V_15 = 0 ;
if ( V_71 -> V_15 & V_165 )
args -> V_15 |= V_164 ;
F_73 ( V_69 ) ;
return 0 ;
}
static int F_104 ( int V_122 , void * V_167 , void * V_130 )
{
struct V_60 * V_61 = V_167 ;
F_52 ( V_61 ) ;
return 0 ;
}
static void F_105 ( struct V_7 * V_8 , struct V_54 * V_66 )
{
struct V_56 * V_57 = V_66 -> V_59 ;
F_14 ( & V_57 -> V_14 ) ;
F_106 ( & V_57 -> V_58 , F_104 , NULL ) ;
F_17 ( & V_57 -> V_14 ) ;
F_107 ( & V_57 -> V_58 ) ;
F_45 ( & V_57 -> V_14 ) ;
F_47 ( V_57 ) ;
}
static int F_108 ( struct V_168 * V_169 , void * V_130 )
{
struct V_170 * V_171 = (struct V_170 * ) V_169 -> V_172 ;
struct V_7 * V_8 = V_171 -> V_173 -> V_18 ;
struct V_174 * V_175 ;
F_14 ( & V_8 -> V_41 . V_176 ) ;
F_90 (fb, &drm->mode_config.fb_list, head) {
F_109 ( V_169 , L_4 ,
V_175 -> V_72 . V_122 , V_175 -> V_177 , V_175 -> V_178 ,
V_175 -> V_179 -> V_180 ,
V_175 -> V_179 -> V_181 [ 0 ] * 8 ,
F_110 ( V_175 ) ) ;
}
F_17 ( & V_8 -> V_41 . V_176 ) ;
return 0 ;
}
static int F_111 ( struct V_168 * V_169 , void * V_130 )
{
struct V_170 * V_171 = (struct V_170 * ) V_169 -> V_172 ;
struct V_7 * V_8 = V_171 -> V_173 -> V_18 ;
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_182 V_167 = F_112 ( V_169 ) ;
if ( V_2 -> V_29 ) {
F_14 ( & V_2 -> V_38 ) ;
F_113 ( & V_2 -> V_37 , & V_167 ) ;
F_17 ( & V_2 -> V_38 ) ;
}
return 0 ;
}
static int F_114 ( struct V_183 * V_173 )
{
return F_115 ( V_184 ,
F_116 ( V_184 ) ,
V_173 -> V_185 , V_173 ) ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_139 * V_62 )
{
F_14 ( & V_2 -> V_39 ) ;
F_118 ( & V_62 -> V_186 , & V_2 -> V_40 ) ;
F_17 ( & V_2 -> V_39 ) ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 ,
struct V_139 * V_62 )
{
F_14 ( & V_2 -> V_39 ) ;
F_120 ( & V_62 -> V_186 ) ;
F_17 ( & V_2 -> V_39 ) ;
return 0 ;
}
void * F_121 ( struct V_1 * V_2 , T_4 V_116 ,
T_5 * V_187 )
{
struct V_188 * V_189 ;
void * V_190 ;
T_6 V_191 ;
int V_13 ;
if ( V_2 -> V_29 )
V_116 = F_122 ( & V_2 -> V_34 . V_29 , V_116 ) ;
else
V_116 = F_123 ( V_116 ) ;
V_191 = V_19 | V_192 ;
if ( ! V_2 -> V_29 ) {
V_191 |= V_193 ;
}
V_190 = ( void * ) F_124 ( V_191 , F_125 ( V_116 ) ) ;
if ( ! V_190 )
return F_126 ( - V_20 ) ;
if ( ! V_2 -> V_29 ) {
* V_187 = F_127 ( V_190 ) ;
return V_190 ;
}
V_189 = F_128 ( & V_2 -> V_34 . V_29 ,
V_116 >> V_2 -> V_34 . V_35 ,
V_2 -> V_34 . V_36 , true ) ;
if ( ! V_189 ) {
V_13 = - V_194 ;
goto V_195;
}
* V_187 = F_129 ( & V_2 -> V_34 . V_29 , V_189 ) ;
V_13 = F_130 ( V_2 -> V_29 , * V_187 , F_127 ( V_190 ) ,
V_116 , V_196 | V_197 ) ;
if ( V_13 < 0 )
goto V_198;
return V_190 ;
V_198:
F_131 ( & V_2 -> V_34 . V_29 , V_189 ) ;
V_195:
V_195 ( ( unsigned long ) V_190 , F_125 ( V_116 ) ) ;
return F_126 ( V_13 ) ;
}
void F_132 ( struct V_1 * V_2 , T_4 V_116 , void * V_190 ,
T_5 V_187 )
{
if ( V_2 -> V_29 )
V_116 = F_122 ( & V_2 -> V_34 . V_29 , V_116 ) ;
else
V_116 = F_123 ( V_116 ) ;
if ( V_2 -> V_29 ) {
F_133 ( V_2 -> V_29 , V_187 , V_116 ) ;
V_198 ( & V_2 -> V_34 . V_29 ,
F_134 ( & V_2 -> V_34 . V_29 , V_187 ) ) ;
}
V_195 ( ( unsigned long ) V_190 , F_125 ( V_116 ) ) ;
}
static int F_135 ( struct V_16 * V_18 )
{
struct V_199 * V_200 = & V_201 ;
struct V_7 * V_8 ;
int V_13 ;
V_8 = F_136 ( V_200 , & V_18 -> V_18 ) ;
if ( F_77 ( V_8 ) )
return F_78 ( V_8 ) ;
F_137 ( & V_18 -> V_18 , V_8 ) ;
V_13 = F_138 ( V_8 , 0 ) ;
if ( V_13 < 0 )
goto V_202;
return 0 ;
V_202:
F_139 ( V_8 ) ;
return V_13 ;
}
static int F_140 ( struct V_16 * V_18 )
{
struct V_7 * V_8 = F_63 ( & V_18 -> V_18 ) ;
F_141 ( V_8 ) ;
F_139 ( V_8 ) ;
return 0 ;
}
static int F_142 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = F_63 ( V_18 ) ;
struct V_1 * V_2 = V_8 -> V_12 ;
F_143 ( V_8 ) ;
F_144 ( V_8 ) ;
V_2 -> V_4 = F_145 ( V_8 ) ;
if ( F_77 ( V_2 -> V_4 ) ) {
F_146 ( V_8 ) ;
F_147 ( V_8 ) ;
return F_78 ( V_2 -> V_4 ) ;
}
return 0 ;
}
static int F_148 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = F_63 ( V_18 ) ;
struct V_1 * V_2 = V_8 -> V_12 ;
F_149 ( V_8 , V_2 -> V_4 ) ;
F_146 ( V_8 ) ;
F_147 ( V_8 ) ;
return 0 ;
}
static int T_7 F_150 ( void )
{
int V_13 ;
V_13 = F_151 ( & V_203 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_152 ( V_204 , F_116 ( V_204 ) ) ;
if ( V_13 < 0 )
goto V_205;
return 0 ;
V_205:
F_153 ( & V_203 ) ;
return V_13 ;
}
static void T_8 F_154 ( void )
{
F_155 ( V_204 , F_116 ( V_204 ) ) ;
F_153 ( & V_203 ) ;
}
