static void F_1 ( struct V_1 * V_1 , T_1 * V_2 ,
T_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , struct V_4 , V_6 ) ;
V_5 -> V_2 = V_2 ;
F_3 ( V_2 , & V_5 -> V_7 ) ;
}
static int F_4 ( T_3 * V_7 , unsigned V_8 , int V_9 ,
void * V_10 )
{
struct V_4 * V_5 = F_2 ( V_7 , struct V_4 , V_7 ) ;
if ( ! ( ( unsigned long ) V_10 & V_5 -> V_11 ) )
return 0 ;
F_5 ( V_5 ) ;
return 0 ;
}
void F_6 ( struct V_12 * V_13 , T_4 V_14 )
{
F_7 ( & V_13 -> V_15 ) ;
V_13 -> V_14 = V_14 ;
F_8 ( & V_13 -> V_16 ) ;
V_13 -> V_17 = 0 ;
V_13 -> V_18 = V_13 -> V_19 = 0 ;
}
void F_9 ( struct V_4 * V_5 , T_4 V_14 ,
unsigned long V_11 , struct V_20 * V_21 )
{
F_10 ( & V_5 -> V_7 , F_4 ) ;
F_11 ( & V_5 -> V_6 , F_1 ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_21 = V_21 ;
F_6 ( & V_5 -> V_13 , V_14 ) ;
}
void F_12 ( struct V_4 * V_5 , struct V_1 * V_1 )
{
unsigned long V_11 ;
V_11 = V_1 -> V_22 -> V_5 ( V_1 , & V_5 -> V_6 ) ;
if ( V_11 )
F_4 ( & V_5 -> V_7 , 0 , 0 , ( void * ) V_11 ) ;
}
void F_13 ( struct V_4 * V_5 )
{
F_14 ( V_5 -> V_2 , & V_5 -> V_7 ) ;
}
static bool F_15 ( struct V_20 * V_21 , struct V_12 * V_13 ,
unsigned V_23 )
{
int V_24 ;
F_16 ( & V_21 -> V_25 ) ;
V_24 = V_23 - V_13 -> V_19 ;
F_17 ( & V_21 -> V_25 ) ;
return V_24 <= 0 ;
}
static void F_18 ( struct V_20 * V_21 , struct V_12 * V_13 )
{
unsigned V_23 ;
int V_17 ;
F_16 ( & V_21 -> V_25 ) ;
V_23 = V_13 -> V_18 ;
V_13 -> V_17 ++ ;
F_17 ( & V_21 -> V_25 ) ;
F_19 ( V_13 -> V_16 , F_15 ( V_21 , V_13 , V_23 ) ) ;
F_16 ( & V_21 -> V_25 ) ;
V_17 = -- V_13 -> V_17 ;
F_17 ( & V_21 -> V_25 ) ;
F_20 ( V_17 < 0 ) ;
}
void F_21 ( struct V_4 * V_5 )
{
F_18 ( V_5 -> V_21 , & V_5 -> V_13 ) ;
}
void F_22 ( struct V_20 * V_21 , struct V_12 * V_13 )
{
unsigned long V_26 ;
F_23 ( & V_21 -> V_25 , V_26 ) ;
if ( F_24 ( & V_13 -> V_15 ) ) {
F_25 ( & V_13 -> V_15 , & V_21 -> V_27 ) ;
V_13 -> V_18 ++ ;
F_26 ( V_21 -> V_28 ) ;
}
F_27 ( & V_21 -> V_25 , V_26 ) ;
}
void F_5 ( struct V_4 * V_5 )
{
F_22 ( V_5 -> V_21 , & V_5 -> V_13 ) ;
}
static void F_28 ( struct V_20 * V_21 ,
struct V_29 * V_30 )
{
V_30 -> V_31 = 1 ;
V_30 -> V_32 = NULL ;
V_30 -> V_33 = NULL ;
V_30 -> V_34 = NULL ;
V_30 -> V_35 = 0 ;
V_30 -> V_36 = 0 ;
V_30 -> V_37 = 0 ;
V_30 -> V_38 = 0 ;
V_30 -> V_39 = false ;
V_30 -> V_40 = 0 ;
V_30 -> V_41 = false ;
V_30 -> V_42 = - 1ull ;
V_30 -> V_43 = 0 ;
V_30 -> V_44 = 0 ;
V_30 -> V_45 = NULL ;
V_30 -> V_46 = NULL ;
V_30 -> V_47 = NULL ;
V_30 -> error = NULL ;
V_30 -> V_48 = NULL ;
V_30 -> V_49 = NULL ;
V_30 -> V_50 = NULL ;
V_30 -> V_51 = NULL ;
V_30 -> V_52 = 0 ;
V_30 -> V_53 = 0 ;
V_30 -> V_54 = NULL ;
}
static int F_29 ( void * V_55 )
{
struct V_20 * V_21 = V_55 ;
struct V_12 * V_13 = NULL ;
unsigned V_56 ( V_23 ) ;
T_5 V_57 = F_30 () ;
F_31 ( V_58 ) ;
F_32 ( V_21 -> V_59 ) ;
for (; ; ) {
F_33 ( V_60 ) ;
F_16 ( & V_21 -> V_25 ) ;
if ( V_13 ) {
V_13 -> V_19 = V_23 ;
if ( V_13 -> V_17 )
F_34 ( & V_13 -> V_16 ) ;
}
if ( F_35 () ) {
F_17 ( & V_21 -> V_25 ) ;
F_36 ( V_61 ) ;
break;
}
if ( ! F_24 ( & V_21 -> V_27 ) ) {
V_13 = F_37 ( & V_21 -> V_27 ,
struct V_12 , V_15 ) ;
F_38 ( & V_13 -> V_15 ) ;
V_23 = V_13 -> V_18 ;
} else
V_13 = NULL ;
F_17 ( & V_21 -> V_25 ) ;
if ( V_13 ) {
F_36 ( V_61 ) ;
V_13 -> V_14 ( V_13 ) ;
if ( F_39 () )
F_40 () ;
} else
F_40 () ;
}
F_41 ( V_21 -> V_59 ) ;
F_31 ( V_57 ) ;
return 0 ;
}
static void F_42 ( struct V_29 * V_30 )
{
F_43 ( V_30 -> V_62 ) ;
V_30 -> V_62 = NULL ;
F_43 ( V_30 -> log ) ;
V_30 -> log = NULL ;
F_43 ( V_30 -> V_63 ) ;
V_30 -> V_63 = NULL ;
F_43 ( V_30 -> V_64 ) ;
V_30 -> V_64 = NULL ;
}
void F_44 ( int V_30 )
{
V_65 |= 0x1 << V_30 ;
}
static long F_45 ( struct V_20 * V_21 )
{
int V_66 ;
bool V_67 ;
for ( V_66 = 0 ; V_66 < V_21 -> V_68 ; ++ V_66 ) {
V_21 -> V_69 [ V_66 ] . V_62 = F_46 ( sizeof * V_21 -> V_69 [ V_66 ] . V_62 *
V_70 , V_71 ) ;
V_21 -> V_69 [ V_66 ] . log = F_46 ( sizeof * V_21 -> V_69 [ V_66 ] . log * V_70 ,
V_71 ) ;
V_21 -> V_69 [ V_66 ] . V_63 = F_46 ( sizeof * V_21 -> V_69 [ V_66 ] . V_63 *
V_70 , V_71 ) ;
V_67 = V_65 & ( 0x1 << V_66 ) ;
if ( V_67 )
V_21 -> V_69 [ V_66 ] . V_64 =
F_46 ( sizeof * V_21 -> V_69 [ V_66 ] . V_64 *
V_70 , V_71 ) ;
if ( ! V_21 -> V_69 [ V_66 ] . V_62 || ! V_21 -> V_69 [ V_66 ] . log ||
! V_21 -> V_69 [ V_66 ] . V_63 ||
( V_67 && ! V_21 -> V_69 [ V_66 ] . V_64 ) )
goto V_72;
}
return 0 ;
V_72:
for (; V_66 >= 0 ; -- V_66 )
F_42 ( & V_21 -> V_69 [ V_66 ] ) ;
return - V_73 ;
}
static void F_47 ( struct V_20 * V_21 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_21 -> V_68 ; ++ V_66 )
F_42 ( & V_21 -> V_69 [ V_66 ] ) ;
}
long F_48 ( struct V_20 * V_21 ,
struct V_29 * V_69 , int V_68 )
{
int V_66 ;
V_21 -> V_69 = V_69 ;
V_21 -> V_68 = V_68 ;
F_49 ( & V_21 -> V_74 ) ;
V_21 -> V_51 = NULL ;
V_21 -> V_75 = NULL ;
V_21 -> V_76 = NULL ;
V_21 -> V_59 = NULL ;
F_50 ( & V_21 -> V_25 ) ;
F_7 ( & V_21 -> V_27 ) ;
V_21 -> V_28 = NULL ;
for ( V_66 = 0 ; V_66 < V_21 -> V_68 ; ++ V_66 ) {
V_21 -> V_69 [ V_66 ] . log = NULL ;
V_21 -> V_69 [ V_66 ] . V_62 = NULL ;
V_21 -> V_69 [ V_66 ] . V_63 = NULL ;
V_21 -> V_69 [ V_66 ] . V_64 = NULL ;
V_21 -> V_69 [ V_66 ] . V_21 = V_21 ;
F_49 ( & V_21 -> V_69 [ V_66 ] . V_74 ) ;
F_28 ( V_21 , V_21 -> V_69 + V_66 ) ;
if ( V_21 -> V_69 [ V_66 ] . V_77 )
F_9 ( & V_21 -> V_69 [ V_66 ] . V_5 ,
V_21 -> V_69 [ V_66 ] . V_77 , V_78 , V_21 ) ;
}
return 0 ;
}
long F_51 ( struct V_20 * V_21 )
{
return V_21 -> V_59 == V_79 -> V_59 ? 0 : - V_80 ;
}
static void F_52 ( struct V_12 * V_13 )
{
struct V_81 * V_82 ;
V_82 = F_2 ( V_13 , struct V_81 , V_13 ) ;
V_82 -> V_83 = F_53 ( V_82 -> V_84 , V_79 ) ;
}
static int F_54 ( struct V_20 * V_21 )
{
struct V_81 V_85 ;
V_85 . V_84 = V_79 ;
F_6 ( & V_85 . V_13 , F_52 ) ;
F_22 ( V_21 , & V_85 . V_13 ) ;
F_18 ( V_21 , & V_85 . V_13 ) ;
return V_85 . V_83 ;
}
static long F_55 ( struct V_20 * V_21 )
{
struct V_86 * V_28 ;
int V_87 ;
if ( V_21 -> V_59 ) {
V_87 = - V_88 ;
goto V_89;
}
V_21 -> V_59 = F_56 ( V_79 ) ;
V_28 = F_57 ( F_29 , V_21 , L_1 , V_79 -> V_90 ) ;
if ( F_58 ( V_28 ) ) {
V_87 = F_59 ( V_28 ) ;
goto V_91;
}
V_21 -> V_28 = V_28 ;
F_26 ( V_28 ) ;
V_87 = F_54 ( V_21 ) ;
if ( V_87 )
goto V_92;
V_87 = F_45 ( V_21 ) ;
if ( V_87 )
goto V_92;
return 0 ;
V_92:
F_60 ( V_28 ) ;
V_21 -> V_28 = NULL ;
V_91:
if ( V_21 -> V_59 )
F_61 ( V_21 -> V_59 ) ;
V_21 -> V_59 = NULL ;
V_89:
return V_87 ;
}
long F_62 ( struct V_20 * V_21 )
{
struct V_93 * V_76 ;
V_76 = F_46 ( F_63 ( struct V_93 , V_94 ) , V_71 ) ;
if ( ! V_76 )
return - V_73 ;
F_64 ( V_21 , true ) ;
V_76 -> V_95 = 0 ;
F_65 ( V_21 -> V_76 , V_76 ) ;
return 0 ;
}
int F_66 ( struct V_29 * V_30 )
{
int V_66 ;
int V_96 = 0 ;
for ( V_66 = V_30 -> V_53 ; V_66 != V_30 -> V_52 ; V_66 = ( V_66 + 1 ) % V_70 ) {
if ( ( V_30 -> V_63 [ V_66 ] . V_97 == V_98 ) ) {
V_30 -> V_63 [ V_66 ] . V_97 = V_99 ;
F_67 ( V_30 -> V_21 , V_30 ,
V_30 -> V_63 [ V_66 ] . V_100 , 0 ) ;
++ V_96 ;
} else
break;
}
if ( V_96 )
V_30 -> V_53 = V_66 ;
return V_96 ;
}
void F_64 ( struct V_20 * V_21 , bool V_101 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_21 -> V_68 ; ++ V_66 ) {
if ( V_21 -> V_69 [ V_66 ] . V_48 && V_21 -> V_69 [ V_66 ] . V_77 ) {
F_13 ( & V_21 -> V_69 [ V_66 ] . V_5 ) ;
F_21 ( & V_21 -> V_69 [ V_66 ] . V_5 ) ;
}
if ( V_21 -> V_69 [ V_66 ] . V_54 )
F_68 ( V_21 -> V_69 [ V_66 ] . V_54 ) ;
F_66 ( & V_21 -> V_69 [ V_66 ] ) ;
if ( V_21 -> V_69 [ V_66 ] . V_47 )
F_69 ( V_21 -> V_69 [ V_66 ] . V_47 ) ;
if ( V_21 -> V_69 [ V_66 ] . error )
F_70 ( V_21 -> V_69 [ V_66 ] . error ) ;
if ( V_21 -> V_69 [ V_66 ] . V_48 )
F_70 ( V_21 -> V_69 [ V_66 ] . V_48 ) ;
if ( V_21 -> V_69 [ V_66 ] . V_49 )
F_69 ( V_21 -> V_69 [ V_66 ] . V_49 ) ;
if ( V_21 -> V_69 [ V_66 ] . V_50 )
F_70 ( V_21 -> V_69 [ V_66 ] . V_50 ) ;
F_28 ( V_21 , V_21 -> V_69 + V_66 ) ;
}
F_47 ( V_21 ) ;
if ( V_21 -> V_51 )
F_69 ( V_21 -> V_51 ) ;
V_21 -> V_51 = NULL ;
if ( V_21 -> V_75 )
F_70 ( V_21 -> V_75 ) ;
V_21 -> V_75 = NULL ;
F_43 ( F_71 ( V_21 -> V_76 ,
V_101 ==
F_72 ( & V_21 -> V_74 ) ) ) ;
F_65 ( V_21 -> V_76 , NULL ) ;
F_73 ( ! F_24 ( & V_21 -> V_27 ) ) ;
if ( V_21 -> V_28 ) {
F_60 ( V_21 -> V_28 ) ;
V_21 -> V_28 = NULL ;
}
if ( V_21 -> V_59 )
F_61 ( V_21 -> V_59 ) ;
V_21 -> V_59 = NULL ;
}
static int F_74 ( void T_6 * V_46 , T_7 V_102 , unsigned long V_103 )
{
T_7 V_104 = V_102 / V_105 / 8 ;
if ( V_104 > V_106 - ( unsigned long ) V_46 ||
V_104 + ( unsigned long ) V_46 > V_106 )
return 0 ;
return F_75 ( V_107 , V_46 + V_104 ,
( V_103 + V_105 * 8 - 1 ) / V_105 / 8 ) ;
}
static int F_76 ( void T_6 * V_46 , struct V_93 * V_108 ,
int V_109 )
{
int V_66 ;
if ( ! V_108 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_108 -> V_95 ; ++ V_66 ) {
struct V_110 * V_111 = V_108 -> V_94 + V_66 ;
unsigned long V_104 = V_111 -> V_112 ;
if ( V_111 -> V_113 > V_106 )
return 0 ;
else if ( ! F_75 ( V_107 , ( void T_6 * ) V_104 ,
V_111 -> V_113 ) )
return 0 ;
else if ( V_109 && ! F_74 ( V_46 ,
V_111 -> V_114 ,
V_111 -> V_113 ) )
return 0 ;
}
return 1 ;
}
static int F_77 ( struct V_20 * V_115 , struct V_93 * V_108 ,
int V_109 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_115 -> V_68 ; ++ V_66 ) {
int V_116 ;
F_78 ( & V_115 -> V_69 [ V_66 ] . V_74 ) ;
if ( V_115 -> V_69 [ V_66 ] . V_45 )
V_116 = F_76 ( V_115 -> V_69 [ V_66 ] . V_46 , V_108 ,
V_109 ) ;
else
V_116 = 1 ;
F_79 ( & V_115 -> V_69 [ V_66 ] . V_74 ) ;
if ( ! V_116 )
return 0 ;
}
return 1 ;
}
static int F_80 ( struct V_20 * V_115 , unsigned int V_31 ,
struct V_117 T_6 * V_32 ,
struct V_118 T_6 * V_33 ,
struct V_119 T_6 * V_34 )
{
T_8 V_82 = F_81 ( V_115 , V_120 ) ? 2 : 0 ;
return F_75 ( V_121 , V_32 , V_31 * sizeof *V_32 ) &&
F_75 ( V_121 , V_33 ,
sizeof *V_33 + V_31 * sizeof * V_33 -> V_122 + V_82 ) &&
F_75 ( V_107 , V_34 ,
sizeof *V_34 + V_31 * sizeof * V_34 -> V_122 + V_82 ) ;
}
int F_82 ( struct V_20 * V_21 )
{
struct V_93 * V_123 ;
V_123 = F_71 ( V_21 -> V_76 ,
F_72 ( & V_21 -> V_74 ) ) ;
return F_77 ( V_21 , V_123 , 1 ) ;
}
static int F_83 ( struct V_20 * V_115 , struct V_29 * V_30 ,
void T_6 * V_46 )
{
struct V_93 * V_123 ;
T_8 V_82 = F_81 ( V_115 , V_120 ) ? 2 : 0 ;
V_123 = F_71 ( V_30 -> V_21 -> V_76 ,
F_72 ( & V_30 -> V_74 ) ) ;
return F_76 ( V_46 , V_123 ,
F_81 ( V_30 -> V_21 , V_124 ) ) &&
( ! V_30 -> V_41 || F_74 ( V_46 , V_30 -> V_42 ,
sizeof * V_30 -> V_34 +
V_30 -> V_31 * sizeof * V_30 -> V_34 -> V_122 + V_82 ) ) ;
}
int F_84 ( struct V_29 * V_30 )
{
return F_80 ( V_30 -> V_21 , V_30 -> V_31 , V_30 -> V_32 , V_30 -> V_33 , V_30 -> V_34 ) &&
F_83 ( V_30 -> V_21 , V_30 , V_30 -> V_46 ) ;
}
static long F_85 ( struct V_20 * V_115 , struct V_93 T_6 * V_111 )
{
struct V_93 V_108 , * V_125 , * V_126 ;
unsigned long V_127 = F_63 ( struct V_93 , V_94 ) ;
if ( F_86 ( & V_108 , V_111 , V_127 ) )
return - V_128 ;
if ( V_108 . V_129 )
return - V_130 ;
if ( V_108 . V_95 > V_131 )
return - V_132 ;
V_125 = F_46 ( V_127 + V_108 . V_95 * sizeof * V_111 -> V_94 , V_71 ) ;
if ( ! V_125 )
return - V_73 ;
memcpy ( V_125 , & V_108 , V_127 ) ;
if ( F_86 ( V_125 -> V_94 , V_111 -> V_94 ,
V_108 . V_95 * sizeof * V_111 -> V_94 ) ) {
F_43 ( V_125 ) ;
return - V_128 ;
}
if ( ! F_77 ( V_115 , V_125 ,
F_81 ( V_115 , V_124 ) ) ) {
F_43 ( V_125 ) ;
return - V_128 ;
}
V_126 = F_71 ( V_115 -> V_76 ,
F_72 ( & V_115 -> V_74 ) ) ;
F_87 ( V_115 -> V_76 , V_125 ) ;
F_88 () ;
F_43 ( V_126 ) ;
return 0 ;
}
static long F_89 ( struct V_20 * V_115 , int V_133 , void T_6 * V_134 )
{
struct V_1 * V_135 , * V_136 = NULL ,
* V_137 = NULL , * V_138 = NULL ;
struct V_139 * V_140 = NULL ;
T_9 T_6 * V_141 = V_134 ;
struct V_29 * V_30 ;
struct V_142 V_82 ;
struct V_143 V_144 ;
struct V_145 V_104 ;
T_9 V_146 ;
long V_147 ;
V_147 = F_90 ( V_146 , V_141 ) ;
if ( V_147 < 0 )
return V_147 ;
if ( V_146 >= V_115 -> V_68 )
return - V_148 ;
V_30 = V_115 -> V_69 + V_146 ;
F_78 ( & V_30 -> V_74 ) ;
switch ( V_133 ) {
case V_149 :
if ( V_30 -> V_45 ) {
V_147 = - V_88 ;
break;
}
if ( F_86 ( & V_82 , V_134 , sizeof V_82 ) ) {
V_147 = - V_128 ;
break;
}
if ( ! V_82 . V_31 || V_82 . V_31 > 0xffff || ( V_82 . V_31 & ( V_82 . V_31 - 1 ) ) ) {
V_147 = - V_150 ;
break;
}
V_30 -> V_31 = V_82 . V_31 ;
break;
case V_151 :
if ( V_30 -> V_45 ) {
V_147 = - V_88 ;
break;
}
if ( F_86 ( & V_82 , V_134 , sizeof V_82 ) ) {
V_147 = - V_128 ;
break;
}
if ( V_82 . V_31 > 0xffff ) {
V_147 = - V_150 ;
break;
}
V_30 -> V_35 = V_82 . V_31 ;
V_30 -> V_36 = V_30 -> V_35 ;
break;
case V_152 :
V_82 . V_153 = V_146 ;
V_82 . V_31 = V_30 -> V_35 ;
if ( F_91 ( V_134 , & V_82 , sizeof V_82 ) )
V_147 = - V_128 ;
break;
case V_154 :
if ( F_86 ( & V_104 , V_134 , sizeof V_104 ) ) {
V_147 = - V_128 ;
break;
}
if ( V_104 . V_26 & ~ ( 0x1 << V_155 ) ) {
V_147 = - V_130 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_104 . V_156 != V_104 . V_156 ||
( T_7 ) ( unsigned long ) V_104 . V_157 != V_104 . V_157 ||
( T_7 ) ( unsigned long ) V_104 . V_158 != V_104 . V_158 ) {
V_147 = - V_128 ;
break;
}
if ( ( V_104 . V_158 & ( sizeof * V_30 -> V_33 -> V_122 - 1 ) ) ||
( V_104 . V_157 & ( sizeof * V_30 -> V_34 -> V_122 - 1 ) ) ||
( V_104 . V_159 & ( sizeof * V_30 -> V_34 -> V_122 - 1 ) ) ) {
V_147 = - V_150 ;
break;
}
if ( V_30 -> V_45 ) {
if ( ! F_80 ( V_115 , V_30 -> V_31 ,
( void T_6 * ) ( unsigned long ) V_104 . V_156 ,
( void T_6 * ) ( unsigned long ) V_104 . V_158 ,
( void T_6 * ) ( unsigned long ) V_104 . V_157 ) ) {
V_147 = - V_150 ;
break;
}
if ( ( V_104 . V_26 & ( 0x1 << V_155 ) ) &&
! F_74 ( V_30 -> V_46 , V_104 . V_159 ,
sizeof * V_30 -> V_34 +
V_30 -> V_31 * sizeof * V_30 -> V_34 -> V_122 ) ) {
V_147 = - V_150 ;
break;
}
}
V_30 -> V_41 = ! ! ( V_104 . V_26 & ( 0x1 << V_155 ) ) ;
V_30 -> V_32 = ( void T_6 * ) ( unsigned long ) V_104 . V_156 ;
V_30 -> V_33 = ( void T_6 * ) ( unsigned long ) V_104 . V_158 ;
V_30 -> V_42 = V_104 . V_159 ;
V_30 -> V_34 = ( void T_6 * ) ( unsigned long ) V_104 . V_157 ;
break;
case V_160 :
if ( F_86 ( & V_144 , V_134 , sizeof V_144 ) ) {
V_147 = - V_128 ;
break;
}
V_135 = V_144 . V_161 == - 1 ? NULL : F_92 ( V_144 . V_161 ) ;
if ( F_58 ( V_135 ) ) {
V_147 = F_59 ( V_135 ) ;
break;
}
if ( V_135 != V_30 -> V_48 ) {
V_138 = V_136 = V_30 -> V_48 ;
V_137 = V_30 -> V_48 = V_135 ;
} else
V_136 = V_135 ;
break;
case V_162 :
if ( F_86 ( & V_144 , V_134 , sizeof V_144 ) ) {
V_147 = - V_128 ;
break;
}
V_135 = V_144 . V_161 == - 1 ? NULL : F_92 ( V_144 . V_161 ) ;
if ( F_58 ( V_135 ) ) {
V_147 = F_59 ( V_135 ) ;
break;
}
if ( V_135 != V_30 -> V_50 ) {
V_136 = V_30 -> V_50 ;
V_140 = V_30 -> V_49 ;
V_30 -> V_50 = V_135 ;
V_30 -> V_49 = V_135 ?
F_93 ( V_135 ) : NULL ;
} else
V_136 = V_135 ;
break;
case V_163 :
if ( F_86 ( & V_144 , V_134 , sizeof V_144 ) ) {
V_147 = - V_128 ;
break;
}
V_135 = V_144 . V_161 == - 1 ? NULL : F_92 ( V_144 . V_161 ) ;
if ( F_58 ( V_135 ) ) {
V_147 = F_59 ( V_135 ) ;
break;
}
if ( V_135 != V_30 -> error ) {
V_136 = V_30 -> error ;
V_30 -> error = V_135 ;
V_140 = V_30 -> V_47 ;
V_30 -> V_47 = V_135 ?
F_93 ( V_135 ) : NULL ;
} else
V_136 = V_135 ;
break;
default:
V_147 = - V_164 ;
}
if ( V_138 && V_30 -> V_77 )
F_13 ( & V_30 -> V_5 ) ;
if ( V_140 )
F_69 ( V_140 ) ;
if ( V_136 )
F_70 ( V_136 ) ;
if ( V_137 && V_30 -> V_77 )
F_12 ( & V_30 -> V_5 , V_30 -> V_48 ) ;
F_79 ( & V_30 -> V_74 ) ;
if ( V_138 && V_30 -> V_77 )
F_21 ( & V_30 -> V_5 ) ;
return V_147 ;
}
long F_94 ( struct V_20 * V_115 , unsigned int V_133 , unsigned long V_165 )
{
void T_6 * V_134 = ( void T_6 * ) V_165 ;
struct V_1 * V_135 , * V_136 = NULL ;
struct V_139 * V_140 = NULL ;
T_7 V_166 ;
long V_147 ;
int V_66 , V_161 ;
if ( V_133 == V_167 ) {
V_147 = F_55 ( V_115 ) ;
goto V_16;
}
V_147 = F_51 ( V_115 ) ;
if ( V_147 )
goto V_16;
switch ( V_133 ) {
case V_168 :
V_147 = F_85 ( V_115 , V_134 ) ;
break;
case V_169 :
if ( F_86 ( & V_166 , V_134 , sizeof V_166 ) ) {
V_147 = - V_128 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_166 != V_166 ) {
V_147 = - V_128 ;
break;
}
for ( V_66 = 0 ; V_66 < V_115 -> V_68 ; ++ V_66 ) {
struct V_29 * V_30 ;
void T_6 * V_170 = ( void T_6 * ) ( unsigned long ) V_166 ;
V_30 = V_115 -> V_69 + V_66 ;
F_78 ( & V_30 -> V_74 ) ;
if ( V_30 -> V_45 && ! F_83 ( V_115 , V_30 , V_170 ) )
V_147 = - V_128 ;
else
V_30 -> V_46 = V_170 ;
F_79 ( & V_30 -> V_74 ) ;
}
break;
case V_171 :
V_147 = F_90 ( V_161 , ( int T_6 * ) V_134 ) ;
if ( V_147 < 0 )
break;
V_135 = V_161 == - 1 ? NULL : F_92 ( V_161 ) ;
if ( F_58 ( V_135 ) ) {
V_147 = F_59 ( V_135 ) ;
break;
}
if ( V_135 != V_115 -> V_75 ) {
V_136 = V_115 -> V_75 ;
V_140 = V_115 -> V_51 ;
V_115 -> V_51 = V_135 ?
F_93 ( V_135 ) : NULL ;
} else
V_136 = V_135 ;
for ( V_66 = 0 ; V_66 < V_115 -> V_68 ; ++ V_66 ) {
F_78 ( & V_115 -> V_69 [ V_66 ] . V_74 ) ;
V_115 -> V_69 [ V_66 ] . V_51 = V_115 -> V_51 ;
F_79 ( & V_115 -> V_69 [ V_66 ] . V_74 ) ;
}
if ( V_140 )
F_69 ( V_140 ) ;
if ( V_136 )
F_70 ( V_136 ) ;
break;
default:
V_147 = F_89 ( V_115 , V_133 , V_134 ) ;
break;
}
V_16:
return V_147 ;
}
static const struct V_110 * F_95 ( struct V_93 * V_108 ,
T_10 V_102 , T_11 V_97 )
{
struct V_110 * V_172 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_108 -> V_95 ; ++ V_66 ) {
V_172 = V_108 -> V_94 + V_66 ;
if ( V_172 -> V_114 <= V_102 &&
V_172 -> V_114 + V_172 -> V_113 - 1 >= V_102 )
return V_172 ;
}
return NULL ;
}
static int F_96 ( int V_173 , void T_6 * V_102 )
{
unsigned long log = ( unsigned long ) V_102 ;
struct V_174 * V_174 ;
void * V_170 ;
int V_175 = V_173 + ( log % V_176 ) * 8 ;
int V_147 ;
V_147 = F_97 ( log , 1 , 1 , & V_174 ) ;
if ( V_147 < 0 )
return V_147 ;
F_20 ( V_147 != 1 ) ;
V_170 = F_98 ( V_174 ) ;
F_99 ( V_175 , V_170 ) ;
F_100 ( V_170 ) ;
F_101 ( V_174 ) ;
F_102 ( V_174 ) ;
return 0 ;
}
static int F_103 ( void T_6 * V_46 ,
T_7 V_177 , T_7 V_178 )
{
T_7 V_179 = V_177 / V_105 ;
int V_147 ;
if ( ! V_178 )
return 0 ;
V_178 += V_177 % V_105 ;
for (; ; ) {
T_7 V_170 = ( T_7 ) ( unsigned long ) V_46 ;
T_7 log = V_170 + V_179 / 8 ;
int V_175 = V_179 % 8 ;
if ( ( T_7 ) ( unsigned long ) log != log )
return - V_128 ;
V_147 = F_96 ( V_175 , ( void T_6 * ) ( unsigned long ) log ) ;
if ( V_147 < 0 )
return V_147 ;
if ( V_178 <= V_105 )
break;
V_178 -= V_105 ;
V_179 += 1 ;
}
return V_147 ;
}
int F_104 ( struct V_29 * V_30 , struct V_180 * log ,
unsigned int V_181 , T_7 V_97 )
{
int V_66 , V_147 ;
F_105 () ;
for ( V_66 = 0 ; V_66 < V_181 ; ++ V_66 ) {
T_7 V_182 = F_106 ( log [ V_66 ] . V_97 , V_97 ) ;
V_147 = F_103 ( V_30 -> V_46 , log [ V_66 ] . V_102 , V_182 ) ;
if ( V_147 < 0 )
return V_147 ;
V_97 -= V_182 ;
if ( ! V_97 ) {
if ( V_30 -> V_51 )
F_107 ( V_30 -> V_51 , 1 ) ;
return 0 ;
}
}
F_108 () ;
return 0 ;
}
static int F_109 ( struct V_29 * V_30 )
{
void T_6 * V_34 ;
if ( F_110 ( V_30 -> V_40 , & V_30 -> V_34 -> V_26 ) < 0 )
return - V_128 ;
if ( F_111 ( V_30 -> V_41 ) ) {
F_105 () ;
V_34 = & V_30 -> V_34 -> V_26 ;
F_103 ( V_30 -> V_46 , V_30 -> V_42 +
( V_34 - ( void T_6 * ) V_30 -> V_34 ) ,
sizeof V_30 -> V_34 -> V_26 ) ;
if ( V_30 -> V_51 )
F_107 ( V_30 -> V_51 , 1 ) ;
}
return 0 ;
}
static int F_112 ( struct V_29 * V_30 , T_12 V_183 )
{
if ( F_110 ( V_30 -> V_36 , F_113 ( V_30 ) ) )
return - V_128 ;
if ( F_111 ( V_30 -> V_41 ) ) {
void T_6 * V_34 ;
F_105 () ;
V_34 = F_113 ( V_30 ) ;
F_103 ( V_30 -> V_46 , V_30 -> V_42 +
( V_34 - ( void T_6 * ) V_30 -> V_34 ) ,
sizeof * F_113 ( V_30 ) ) ;
if ( V_30 -> V_51 )
F_107 ( V_30 -> V_51 , 1 ) ;
}
return 0 ;
}
int F_114 ( struct V_29 * V_30 )
{
int V_147 ;
if ( ! V_30 -> V_45 )
return 0 ;
V_147 = F_109 ( V_30 ) ;
if ( V_147 )
return V_147 ;
V_30 -> V_39 = false ;
return F_90 ( V_30 -> V_37 , & V_30 -> V_34 -> V_146 ) ;
}
static int F_115 ( struct V_20 * V_21 , T_7 V_102 , T_9 V_97 ,
struct V_184 V_185 [] , int V_186 )
{
const struct V_110 * V_172 ;
struct V_93 * V_108 ;
struct V_184 * V_187 ;
T_7 V_82 = 0 ;
int V_83 = 0 ;
F_116 () ;
V_108 = F_117 ( V_21 -> V_76 ) ;
while ( ( T_7 ) V_97 > V_82 ) {
T_7 V_127 ;
if ( F_111 ( V_83 >= V_186 ) ) {
V_83 = - V_148 ;
break;
}
V_172 = F_95 ( V_108 , V_102 , V_97 ) ;
if ( F_111 ( ! V_172 ) ) {
V_83 = - V_128 ;
break;
}
V_187 = V_185 + V_83 ;
V_127 = V_172 -> V_113 - V_102 + V_172 -> V_114 ;
V_187 -> V_188 = F_106 ( ( T_7 ) V_97 , V_127 ) ;
V_187 -> V_189 = ( void T_6 * ) ( unsigned long )
( V_172 -> V_112 + V_102 - V_172 -> V_114 ) ;
V_82 += V_127 ;
V_102 += V_127 ;
++ V_83 ;
}
F_118 () ;
return V_83 ;
}
static unsigned F_119 ( struct V_117 * V_32 )
{
unsigned int V_190 ;
if ( ! ( V_32 -> V_26 & V_191 ) )
return - 1U ;
V_190 = V_32 -> V_190 ;
F_120 () ;
return V_190 ;
}
static int F_121 ( struct V_20 * V_21 , struct V_29 * V_30 ,
struct V_184 V_185 [] , unsigned int V_186 ,
unsigned int * V_192 , unsigned int * V_193 ,
struct V_180 * log , unsigned int * V_181 ,
struct V_117 * V_62 )
{
struct V_117 V_32 ;
unsigned int V_66 = 0 , V_194 , V_195 = 0 ;
int V_83 ;
if ( F_111 ( V_62 -> V_97 % sizeof V_32 ) ) {
F_122 ( V_30 , L_2
L_3 ,
( unsigned long long ) V_62 -> V_97 ,
sizeof V_32 ) ;
return - V_150 ;
}
V_83 = F_115 ( V_21 , V_62 -> V_102 , V_62 -> V_97 , V_30 -> V_62 ,
V_70 ) ;
if ( F_111 ( V_83 < 0 ) ) {
F_122 ( V_30 , L_4 , V_83 ) ;
return V_83 ;
}
F_120 () ;
V_194 = V_62 -> V_97 / sizeof V_32 ;
if ( F_111 ( V_194 > V_196 + 1 ) ) {
F_122 ( V_30 , L_5 ,
V_62 -> V_97 ) ;
return - V_132 ;
}
do {
unsigned V_197 = * V_193 + * V_192 ;
if ( F_111 ( ++ V_195 > V_194 ) ) {
F_122 ( V_30 , L_6
L_7 ,
V_66 , V_194 ) ;
return - V_150 ;
}
if ( F_111 ( F_123 ( ( unsigned char * ) & V_32 ,
V_30 -> V_62 , sizeof V_32 ) ) ) {
F_122 ( V_30 , L_8 ,
V_66 , ( T_8 ) V_62 -> V_102 + V_66 * sizeof V_32 ) ;
return - V_150 ;
}
if ( F_111 ( V_32 . V_26 & V_198 ) ) {
F_122 ( V_30 , L_9 ,
V_66 , ( T_8 ) V_62 -> V_102 + V_66 * sizeof V_32 ) ;
return - V_150 ;
}
V_83 = F_115 ( V_21 , V_32 . V_102 , V_32 . V_97 , V_185 + V_197 ,
V_186 - V_197 ) ;
if ( F_111 ( V_83 < 0 ) ) {
F_122 ( V_30 , L_10 ,
V_83 , V_66 ) ;
return V_83 ;
}
if ( V_32 . V_26 & V_199 ) {
* V_193 += V_83 ;
if ( F_111 ( log ) ) {
log [ * V_181 ] . V_102 = V_32 . V_102 ;
log [ * V_181 ] . V_97 = V_32 . V_97 ;
++ * V_181 ;
}
} else {
if ( F_111 ( * V_193 ) ) {
F_122 ( V_30 , L_11
L_12 , V_66 ) ;
return - V_150 ;
}
* V_192 += V_83 ;
}
} while ( ( V_66 = F_119 ( & V_32 ) ) != - 1 );
return 0 ;
}
int F_124 ( struct V_20 * V_21 , struct V_29 * V_30 ,
struct V_184 V_185 [] , unsigned int V_186 ,
unsigned int * V_192 , unsigned int * V_193 ,
struct V_180 * log , unsigned int * V_181 )
{
struct V_117 V_32 ;
unsigned int V_66 , V_200 , V_195 = 0 ;
T_12 V_35 ;
int V_83 ;
V_35 = V_30 -> V_35 ;
if ( F_111 ( F_125 ( V_30 -> V_36 , & V_30 -> V_33 -> V_146 ) ) ) {
F_122 ( V_30 , L_13 ,
& V_30 -> V_33 -> V_146 ) ;
return - V_128 ;
}
if ( F_111 ( ( T_12 ) ( V_30 -> V_36 - V_35 ) > V_30 -> V_31 ) ) {
F_122 ( V_30 , L_14 ,
V_35 , V_30 -> V_36 ) ;
return - V_128 ;
}
if ( V_30 -> V_36 == V_35 )
return V_30 -> V_31 ;
F_126 () ;
if ( F_111 ( F_125 ( V_200 ,
& V_30 -> V_33 -> V_122 [ V_35 % V_30 -> V_31 ] ) ) ) {
F_122 ( V_30 , L_15 ,
V_35 ,
& V_30 -> V_33 -> V_122 [ V_35 % V_30 -> V_31 ] ) ;
return - V_128 ;
}
if ( F_111 ( V_200 >= V_30 -> V_31 ) ) {
F_122 ( V_30 , L_16 ,
V_200 , V_30 -> V_31 ) ;
return - V_150 ;
}
* V_192 = * V_193 = 0 ;
if ( F_111 ( log ) )
* V_181 = 0 ;
V_66 = V_200 ;
do {
unsigned V_197 = * V_193 + * V_192 ;
if ( F_111 ( V_66 >= V_30 -> V_31 ) ) {
F_122 ( V_30 , L_17 ,
V_66 , V_30 -> V_31 , V_200 ) ;
return - V_150 ;
}
if ( F_111 ( ++ V_195 > V_30 -> V_31 ) ) {
F_122 ( V_30 , L_6
L_18 ,
V_66 , V_30 -> V_31 , V_200 ) ;
return - V_150 ;
}
V_83 = F_127 ( & V_32 , V_30 -> V_32 + V_66 , sizeof V_32 ) ;
if ( F_111 ( V_83 ) ) {
F_122 ( V_30 , L_19 ,
V_66 , V_30 -> V_32 + V_66 ) ;
return - V_128 ;
}
if ( V_32 . V_26 & V_198 ) {
V_83 = F_121 ( V_21 , V_30 , V_185 , V_186 ,
V_192 , V_193 ,
log , V_181 , & V_32 ) ;
if ( F_111 ( V_83 < 0 ) ) {
F_122 ( V_30 , L_20
L_21 , V_66 ) ;
return V_83 ;
}
continue;
}
V_83 = F_115 ( V_21 , V_32 . V_102 , V_32 . V_97 , V_185 + V_197 ,
V_186 - V_197 ) ;
if ( F_111 ( V_83 < 0 ) ) {
F_122 ( V_30 , L_22 ,
V_83 , V_66 ) ;
return V_83 ;
}
if ( V_32 . V_26 & V_199 ) {
* V_193 += V_83 ;
if ( F_111 ( log ) ) {
log [ * V_181 ] . V_102 = V_32 . V_102 ;
log [ * V_181 ] . V_97 = V_32 . V_97 ;
++ * V_181 ;
}
} else {
if ( F_111 ( * V_193 ) ) {
F_122 ( V_30 , L_23
L_24 , V_66 ) ;
return - V_150 ;
}
* V_192 += V_83 ;
}
} while ( ( V_66 = F_119 ( & V_32 ) ) != - 1 );
V_30 -> V_35 ++ ;
F_20 ( ! ( V_30 -> V_40 & V_201 ) ) ;
return V_200 ;
}
void F_128 ( struct V_29 * V_30 , int V_202 )
{
V_30 -> V_35 -= V_202 ;
}
int F_129 ( struct V_29 * V_30 , unsigned int V_200 , int V_97 )
{
struct V_203 T_6 * V_34 ;
V_34 = & V_30 -> V_34 -> V_122 [ V_30 -> V_37 % V_30 -> V_31 ] ;
if ( F_110 ( V_200 , & V_34 -> V_100 ) ) {
F_122 ( V_30 , L_25 ) ;
return - V_128 ;
}
if ( F_110 ( V_97 , & V_34 -> V_97 ) ) {
F_122 ( V_30 , L_26 ) ;
return - V_128 ;
}
F_105 () ;
if ( F_110 ( V_30 -> V_37 + 1 , & V_30 -> V_34 -> V_146 ) ) {
F_122 ( V_30 , L_27 ) ;
return - V_128 ;
}
if ( F_111 ( V_30 -> V_41 ) ) {
F_105 () ;
F_103 ( V_30 -> V_46 ,
V_30 -> V_42 +
( ( void T_6 * ) V_34 - ( void T_6 * ) V_30 -> V_34 ) ,
sizeof *V_34 ) ;
F_103 ( V_30 -> V_46 ,
V_30 -> V_42 + F_63 ( struct V_119 , V_146 ) ,
sizeof V_30 -> V_34 -> V_146 ) ;
if ( V_30 -> V_51 )
F_107 ( V_30 -> V_51 , 1 ) ;
}
V_30 -> V_37 ++ ;
if ( F_111 ( V_30 -> V_37 == V_30 -> V_38 ) )
V_30 -> V_39 = false ;
return 0 ;
}
static int F_130 ( struct V_29 * V_30 ,
struct V_203 * V_63 ,
unsigned V_194 )
{
struct V_203 T_6 * V_34 ;
T_12 V_204 , V_205 ;
int V_206 ;
V_206 = V_30 -> V_37 % V_30 -> V_31 ;
V_34 = V_30 -> V_34 -> V_122 + V_206 ;
if ( F_131 ( V_34 , V_63 , V_194 * sizeof *V_34 ) ) {
F_122 ( V_30 , L_28 ) ;
return - V_128 ;
}
if ( F_111 ( V_30 -> V_41 ) ) {
F_105 () ;
F_103 ( V_30 -> V_46 ,
V_30 -> V_42 +
( ( void T_6 * ) V_34 - ( void T_6 * ) V_30 -> V_34 ) ,
V_194 * sizeof *V_34 ) ;
}
V_204 = V_30 -> V_37 ;
V_205 = ( V_30 -> V_37 += V_194 ) ;
if ( F_111 ( ( T_12 ) ( V_205 - V_30 -> V_38 ) < ( T_12 ) ( V_205 - V_204 ) ) )
V_30 -> V_39 = false ;
return 0 ;
}
int F_132 ( struct V_29 * V_30 , struct V_203 * V_63 ,
unsigned V_194 )
{
int V_206 , V_202 , V_147 ;
V_206 = V_30 -> V_37 % V_30 -> V_31 ;
V_202 = V_30 -> V_31 - V_206 ;
if ( V_202 < V_194 ) {
V_147 = F_130 ( V_30 , V_63 , V_202 ) ;
if ( V_147 < 0 )
return V_147 ;
V_63 += V_202 ;
V_194 -= V_202 ;
}
V_147 = F_130 ( V_30 , V_63 , V_194 ) ;
F_105 () ;
if ( F_133 ( V_30 -> V_37 , & V_30 -> V_34 -> V_146 ) ) {
F_122 ( V_30 , L_27 ) ;
return - V_128 ;
}
if ( F_111 ( V_30 -> V_41 ) ) {
F_103 ( V_30 -> V_46 ,
V_30 -> V_42 + F_63 ( struct V_119 , V_146 ) ,
sizeof V_30 -> V_34 -> V_146 ) ;
if ( V_30 -> V_51 )
F_107 ( V_30 -> V_51 , 1 ) ;
}
return V_147 ;
}
static bool F_134 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
T_13 V_204 , V_205 , V_207 ;
bool V_208 ;
F_135 () ;
if ( F_81 ( V_21 , V_209 ) &&
F_111 ( V_30 -> V_36 == V_30 -> V_35 ) )
return true ;
if ( ! F_81 ( V_21 , V_120 ) ) {
T_13 V_26 ;
if ( F_125 ( V_26 , & V_30 -> V_33 -> V_26 ) ) {
F_122 ( V_30 , L_29 ) ;
return true ;
}
return ! ( V_26 & V_210 ) ;
}
V_204 = V_30 -> V_38 ;
V_208 = V_30 -> V_39 ;
V_205 = V_30 -> V_38 = V_30 -> V_37 ;
V_30 -> V_39 = true ;
if ( F_111 ( ! V_208 ) )
return true ;
if ( F_90 ( V_207 , F_136 ( V_30 ) ) ) {
F_122 ( V_30 , L_30 ) ;
return true ;
}
return F_137 ( V_207 , V_205 , V_204 ) ;
}
void F_138 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
if ( V_30 -> V_49 && F_134 ( V_21 , V_30 ) )
F_107 ( V_30 -> V_49 , 1 ) ;
}
void F_67 ( struct V_20 * V_21 ,
struct V_29 * V_30 ,
unsigned int V_200 , int V_97 )
{
F_129 ( V_30 , V_200 , V_97 ) ;
F_138 ( V_21 , V_30 ) ;
}
void F_139 ( struct V_20 * V_21 ,
struct V_29 * V_30 ,
struct V_203 * V_63 , unsigned V_194 )
{
F_132 ( V_30 , V_63 , V_194 ) ;
F_138 ( V_21 , V_30 ) ;
}
bool F_140 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
T_12 V_36 ;
int V_147 ;
if ( ! ( V_30 -> V_40 & V_201 ) )
return false ;
V_30 -> V_40 &= ~ V_201 ;
if ( ! F_81 ( V_21 , V_120 ) ) {
V_147 = F_109 ( V_30 ) ;
if ( V_147 ) {
F_122 ( V_30 , L_31 ,
& V_30 -> V_34 -> V_26 , V_147 ) ;
return false ;
}
} else {
V_147 = F_112 ( V_30 , V_30 -> V_36 ) ;
if ( V_147 ) {
F_122 ( V_30 , L_32 ,
F_113 ( V_30 ) , V_147 ) ;
return false ;
}
}
F_135 () ;
V_147 = F_125 ( V_36 , & V_30 -> V_33 -> V_146 ) ;
if ( V_147 ) {
F_122 ( V_30 , L_33 ,
& V_30 -> V_33 -> V_146 , V_147 ) ;
return false ;
}
return V_36 != V_30 -> V_36 ;
}
void F_141 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
int V_147 ;
if ( V_30 -> V_40 & V_201 )
return;
V_30 -> V_40 |= V_201 ;
if ( ! F_81 ( V_21 , V_120 ) ) {
V_147 = F_109 ( V_30 ) ;
if ( V_147 )
F_122 ( V_30 , L_31 ,
& V_30 -> V_34 -> V_26 , V_147 ) ;
}
}
static void F_142 ( struct V_211 * V_211 )
{
struct V_212 * V_54 = F_2 ( V_211 , struct V_212 ,
V_211 ) ;
F_143 ( & V_54 -> V_7 ) ;
}
struct V_212 * F_144 ( struct V_29 * V_30 ,
bool V_67 )
{
struct V_212 * V_54 ;
if ( ! V_67 )
return NULL ;
V_54 = F_46 ( sizeof *V_54 , V_71 ) ;
if ( ! V_54 )
return F_145 ( - V_73 ) ;
F_146 ( & V_54 -> V_211 ) ;
F_8 ( & V_54 -> V_7 ) ;
V_54 -> V_30 = V_30 ;
return V_54 ;
}
void F_147 ( struct V_212 * V_54 )
{
F_148 ( & V_54 -> V_211 , F_142 ) ;
}
void F_68 ( struct V_212 * V_54 )
{
F_148 ( & V_54 -> V_211 , F_142 ) ;
F_19 ( V_54 -> V_7 , ! F_149 ( & V_54 -> V_211 . V_213 ) ) ;
F_43 ( V_54 ) ;
}
void F_150 ( struct V_64 * V_214 )
{
struct V_212 * V_54 = V_214 -> V_140 ;
struct V_29 * V_30 = V_54 -> V_30 ;
F_5 ( & V_30 -> V_5 ) ;
V_30 -> V_63 [ V_214 -> V_32 ] . V_97 = V_98 ;
F_148 ( & V_54 -> V_211 , F_142 ) ;
}
