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
V_5 -> V_2 = NULL ;
F_6 ( & V_5 -> V_13 , V_14 ) ;
}
int F_12 ( struct V_4 * V_5 , struct V_1 * V_1 )
{
unsigned long V_11 ;
int V_22 = 0 ;
V_11 = V_1 -> V_23 -> V_5 ( V_1 , & V_5 -> V_6 ) ;
if ( V_11 )
F_4 ( & V_5 -> V_7 , 0 , 0 , ( void * ) V_11 ) ;
if ( V_11 & V_24 ) {
if ( V_5 -> V_2 )
F_13 ( V_5 -> V_2 , & V_5 -> V_7 ) ;
V_22 = - V_25 ;
}
return V_22 ;
}
void F_14 ( struct V_4 * V_5 )
{
if ( V_5 -> V_2 ) {
F_13 ( V_5 -> V_2 , & V_5 -> V_7 ) ;
V_5 -> V_2 = NULL ;
}
}
static bool F_15 ( struct V_20 * V_21 , struct V_12 * V_13 ,
unsigned V_26 )
{
int V_27 ;
F_16 ( & V_21 -> V_28 ) ;
V_27 = V_26 - V_13 -> V_19 ;
F_17 ( & V_21 -> V_28 ) ;
return V_27 <= 0 ;
}
static void F_18 ( struct V_20 * V_21 , struct V_12 * V_13 )
{
unsigned V_26 ;
int V_17 ;
F_16 ( & V_21 -> V_28 ) ;
V_26 = V_13 -> V_18 ;
V_13 -> V_17 ++ ;
F_17 ( & V_21 -> V_28 ) ;
F_19 ( V_13 -> V_16 , F_15 ( V_21 , V_13 , V_26 ) ) ;
F_16 ( & V_21 -> V_28 ) ;
V_17 = -- V_13 -> V_17 ;
F_17 ( & V_21 -> V_28 ) ;
F_20 ( V_17 < 0 ) ;
}
void F_21 ( struct V_4 * V_5 )
{
F_18 ( V_5 -> V_21 , & V_5 -> V_13 ) ;
}
void F_22 ( struct V_20 * V_21 , struct V_12 * V_13 )
{
unsigned long V_29 ;
F_23 ( & V_21 -> V_28 , V_29 ) ;
if ( F_24 ( & V_13 -> V_15 ) ) {
F_25 ( & V_13 -> V_15 , & V_21 -> V_30 ) ;
V_13 -> V_18 ++ ;
F_26 ( V_21 -> V_31 ) ;
}
F_27 ( & V_21 -> V_28 , V_29 ) ;
}
void F_5 ( struct V_4 * V_5 )
{
F_22 ( V_5 -> V_21 , & V_5 -> V_13 ) ;
}
static void F_28 ( struct V_20 * V_21 ,
struct V_32 * V_33 )
{
V_33 -> V_34 = 1 ;
V_33 -> V_35 = NULL ;
V_33 -> V_36 = NULL ;
V_33 -> V_37 = NULL ;
V_33 -> V_38 = 0 ;
V_33 -> V_39 = 0 ;
V_33 -> V_40 = 0 ;
V_33 -> V_41 = 0 ;
V_33 -> V_42 = false ;
V_33 -> V_43 = 0 ;
V_33 -> V_44 = false ;
V_33 -> V_45 = - 1ull ;
V_33 -> V_46 = 0 ;
V_33 -> V_47 = 0 ;
V_33 -> V_48 = NULL ;
V_33 -> V_49 = NULL ;
V_33 -> V_50 = NULL ;
V_33 -> error = NULL ;
V_33 -> V_51 = NULL ;
V_33 -> V_52 = NULL ;
V_33 -> V_53 = NULL ;
V_33 -> V_54 = NULL ;
V_33 -> V_55 = 0 ;
V_33 -> V_56 = 0 ;
V_33 -> V_57 = NULL ;
}
static int F_29 ( void * V_58 )
{
struct V_20 * V_21 = V_58 ;
struct V_12 * V_13 = NULL ;
unsigned V_59 ( V_26 ) ;
T_5 V_60 = F_30 () ;
F_31 ( V_61 ) ;
F_32 ( V_21 -> V_62 ) ;
for (; ; ) {
F_33 ( V_63 ) ;
F_16 ( & V_21 -> V_28 ) ;
if ( V_13 ) {
V_13 -> V_19 = V_26 ;
if ( V_13 -> V_17 )
F_34 ( & V_13 -> V_16 ) ;
}
if ( F_35 () ) {
F_17 ( & V_21 -> V_28 ) ;
F_36 ( V_64 ) ;
break;
}
if ( ! F_24 ( & V_21 -> V_30 ) ) {
V_13 = F_37 ( & V_21 -> V_30 ,
struct V_12 , V_15 ) ;
F_38 ( & V_13 -> V_15 ) ;
V_26 = V_13 -> V_18 ;
} else
V_13 = NULL ;
F_17 ( & V_21 -> V_28 ) ;
if ( V_13 ) {
F_36 ( V_64 ) ;
V_13 -> V_14 ( V_13 ) ;
if ( F_39 () )
F_40 () ;
} else
F_40 () ;
}
F_41 ( V_21 -> V_62 ) ;
F_31 ( V_60 ) ;
return 0 ;
}
static void F_42 ( struct V_32 * V_33 )
{
F_43 ( V_33 -> V_65 ) ;
V_33 -> V_65 = NULL ;
F_43 ( V_33 -> log ) ;
V_33 -> log = NULL ;
F_43 ( V_33 -> V_66 ) ;
V_33 -> V_66 = NULL ;
F_43 ( V_33 -> V_67 ) ;
V_33 -> V_67 = NULL ;
}
void F_44 ( int V_33 )
{
V_68 |= 0x1 << V_33 ;
}
static long F_45 ( struct V_20 * V_21 )
{
int V_69 ;
bool V_70 ;
for ( V_69 = 0 ; V_69 < V_21 -> V_71 ; ++ V_69 ) {
V_21 -> V_72 [ V_69 ] . V_65 = F_46 ( sizeof * V_21 -> V_72 [ V_69 ] . V_65 *
V_73 , V_74 ) ;
V_21 -> V_72 [ V_69 ] . log = F_46 ( sizeof * V_21 -> V_72 [ V_69 ] . log * V_73 ,
V_74 ) ;
V_21 -> V_72 [ V_69 ] . V_66 = F_46 ( sizeof * V_21 -> V_72 [ V_69 ] . V_66 *
V_73 , V_74 ) ;
V_70 = V_68 & ( 0x1 << V_69 ) ;
if ( V_70 )
V_21 -> V_72 [ V_69 ] . V_67 =
F_46 ( sizeof * V_21 -> V_72 [ V_69 ] . V_67 *
V_73 , V_74 ) ;
if ( ! V_21 -> V_72 [ V_69 ] . V_65 || ! V_21 -> V_72 [ V_69 ] . log ||
! V_21 -> V_72 [ V_69 ] . V_66 ||
( V_70 && ! V_21 -> V_72 [ V_69 ] . V_67 ) )
goto V_75;
}
return 0 ;
V_75:
for (; V_69 >= 0 ; -- V_69 )
F_42 ( & V_21 -> V_72 [ V_69 ] ) ;
return - V_76 ;
}
static void F_47 ( struct V_20 * V_21 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_21 -> V_71 ; ++ V_69 )
F_42 ( & V_21 -> V_72 [ V_69 ] ) ;
}
long F_48 ( struct V_20 * V_21 ,
struct V_32 * V_72 , int V_71 )
{
int V_69 ;
V_21 -> V_72 = V_72 ;
V_21 -> V_71 = V_71 ;
F_49 ( & V_21 -> V_77 ) ;
V_21 -> V_54 = NULL ;
V_21 -> V_78 = NULL ;
V_21 -> V_79 = NULL ;
V_21 -> V_62 = NULL ;
F_50 ( & V_21 -> V_28 ) ;
F_7 ( & V_21 -> V_30 ) ;
V_21 -> V_31 = NULL ;
for ( V_69 = 0 ; V_69 < V_21 -> V_71 ; ++ V_69 ) {
V_21 -> V_72 [ V_69 ] . log = NULL ;
V_21 -> V_72 [ V_69 ] . V_65 = NULL ;
V_21 -> V_72 [ V_69 ] . V_66 = NULL ;
V_21 -> V_72 [ V_69 ] . V_67 = NULL ;
V_21 -> V_72 [ V_69 ] . V_21 = V_21 ;
F_49 ( & V_21 -> V_72 [ V_69 ] . V_77 ) ;
F_28 ( V_21 , V_21 -> V_72 + V_69 ) ;
if ( V_21 -> V_72 [ V_69 ] . V_80 )
F_9 ( & V_21 -> V_72 [ V_69 ] . V_5 ,
V_21 -> V_72 [ V_69 ] . V_80 , V_81 , V_21 ) ;
}
return 0 ;
}
long F_51 ( struct V_20 * V_21 )
{
return V_21 -> V_62 == V_82 -> V_62 ? 0 : - V_83 ;
}
static void F_52 ( struct V_12 * V_13 )
{
struct V_84 * V_85 ;
V_85 = F_2 ( V_13 , struct V_84 , V_13 ) ;
V_85 -> V_22 = F_53 ( V_85 -> V_86 , V_82 ) ;
}
static int F_54 ( struct V_20 * V_21 )
{
struct V_84 V_87 ;
V_87 . V_86 = V_82 ;
F_6 ( & V_87 . V_13 , F_52 ) ;
F_22 ( V_21 , & V_87 . V_13 ) ;
F_18 ( V_21 , & V_87 . V_13 ) ;
return V_87 . V_22 ;
}
static long F_55 ( struct V_20 * V_21 )
{
struct V_88 * V_31 ;
int V_89 ;
if ( V_21 -> V_62 ) {
V_89 = - V_90 ;
goto V_91;
}
V_21 -> V_62 = F_56 ( V_82 ) ;
V_31 = F_57 ( F_29 , V_21 , L_1 , V_82 -> V_92 ) ;
if ( F_58 ( V_31 ) ) {
V_89 = F_59 ( V_31 ) ;
goto V_93;
}
V_21 -> V_31 = V_31 ;
F_26 ( V_31 ) ;
V_89 = F_54 ( V_21 ) ;
if ( V_89 )
goto V_94;
V_89 = F_45 ( V_21 ) ;
if ( V_89 )
goto V_94;
return 0 ;
V_94:
F_60 ( V_31 ) ;
V_21 -> V_31 = NULL ;
V_93:
if ( V_21 -> V_62 )
F_61 ( V_21 -> V_62 ) ;
V_21 -> V_62 = NULL ;
V_91:
return V_89 ;
}
long F_62 ( struct V_20 * V_21 )
{
struct V_95 * V_79 ;
V_79 = F_46 ( F_63 ( struct V_95 , V_96 ) , V_74 ) ;
if ( ! V_79 )
return - V_76 ;
F_64 ( V_21 , true ) ;
V_79 -> V_97 = 0 ;
F_65 ( V_21 -> V_79 , V_79 ) ;
return 0 ;
}
void F_66 ( struct V_20 * V_21 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_21 -> V_71 ; ++ V_69 ) {
if ( V_21 -> V_72 [ V_69 ] . V_51 && V_21 -> V_72 [ V_69 ] . V_80 ) {
F_14 ( & V_21 -> V_72 [ V_69 ] . V_5 ) ;
F_21 ( & V_21 -> V_72 [ V_69 ] . V_5 ) ;
}
}
}
void F_64 ( struct V_20 * V_21 , bool V_98 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_21 -> V_71 ; ++ V_69 ) {
if ( V_21 -> V_72 [ V_69 ] . V_50 )
F_67 ( V_21 -> V_72 [ V_69 ] . V_50 ) ;
if ( V_21 -> V_72 [ V_69 ] . error )
F_68 ( V_21 -> V_72 [ V_69 ] . error ) ;
if ( V_21 -> V_72 [ V_69 ] . V_51 )
F_68 ( V_21 -> V_72 [ V_69 ] . V_51 ) ;
if ( V_21 -> V_72 [ V_69 ] . V_52 )
F_67 ( V_21 -> V_72 [ V_69 ] . V_52 ) ;
if ( V_21 -> V_72 [ V_69 ] . V_53 )
F_68 ( V_21 -> V_72 [ V_69 ] . V_53 ) ;
F_28 ( V_21 , V_21 -> V_72 + V_69 ) ;
}
F_47 ( V_21 ) ;
if ( V_21 -> V_54 )
F_67 ( V_21 -> V_54 ) ;
V_21 -> V_54 = NULL ;
if ( V_21 -> V_78 )
F_68 ( V_21 -> V_78 ) ;
V_21 -> V_78 = NULL ;
F_43 ( F_69 ( V_21 -> V_79 ,
V_98 ==
F_70 ( & V_21 -> V_77 ) ) ) ;
F_65 ( V_21 -> V_79 , NULL ) ;
F_71 ( ! F_24 ( & V_21 -> V_30 ) ) ;
if ( V_21 -> V_31 ) {
F_60 ( V_21 -> V_31 ) ;
V_21 -> V_31 = NULL ;
}
if ( V_21 -> V_62 )
F_61 ( V_21 -> V_62 ) ;
V_21 -> V_62 = NULL ;
}
static int F_72 ( void T_6 * V_49 , T_7 V_99 , unsigned long V_100 )
{
T_7 V_101 = V_99 / V_102 / 8 ;
if ( V_101 > V_103 - ( unsigned long ) V_49 ||
V_101 + ( unsigned long ) V_49 > V_103 )
return 0 ;
return F_73 ( V_104 , V_49 + V_101 ,
( V_100 + V_102 * 8 - 1 ) / V_102 / 8 ) ;
}
static int F_74 ( void T_6 * V_49 , struct V_95 * V_105 ,
int V_106 )
{
int V_69 ;
if ( ! V_105 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_105 -> V_97 ; ++ V_69 ) {
struct V_107 * V_108 = V_105 -> V_96 + V_69 ;
unsigned long V_101 = V_108 -> V_109 ;
if ( V_108 -> V_110 > V_103 )
return 0 ;
else if ( ! F_73 ( V_104 , ( void T_6 * ) V_101 ,
V_108 -> V_110 ) )
return 0 ;
else if ( V_106 && ! F_72 ( V_49 ,
V_108 -> V_111 ,
V_108 -> V_110 ) )
return 0 ;
}
return 1 ;
}
static int F_75 ( struct V_20 * V_112 , struct V_95 * V_105 ,
int V_106 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_112 -> V_71 ; ++ V_69 ) {
int V_113 ;
F_76 ( & V_112 -> V_72 [ V_69 ] . V_77 ) ;
if ( V_112 -> V_72 [ V_69 ] . V_48 )
V_113 = F_74 ( V_112 -> V_72 [ V_69 ] . V_49 , V_105 ,
V_106 ) ;
else
V_113 = 1 ;
F_77 ( & V_112 -> V_72 [ V_69 ] . V_77 ) ;
if ( ! V_113 )
return 0 ;
}
return 1 ;
}
static int F_78 ( struct V_20 * V_112 , unsigned int V_34 ,
struct V_114 T_6 * V_35 ,
struct V_115 T_6 * V_36 ,
struct V_116 T_6 * V_37 )
{
T_8 V_85 = F_79 ( V_112 , V_117 ) ? 2 : 0 ;
return F_73 ( V_118 , V_35 , V_34 * sizeof *V_35 ) &&
F_73 ( V_118 , V_36 ,
sizeof *V_36 + V_34 * sizeof * V_36 -> V_119 + V_85 ) &&
F_73 ( V_104 , V_37 ,
sizeof *V_37 + V_34 * sizeof * V_37 -> V_119 + V_85 ) ;
}
int F_80 ( struct V_20 * V_21 )
{
struct V_95 * V_120 ;
V_120 = F_69 ( V_21 -> V_79 ,
F_70 ( & V_21 -> V_77 ) ) ;
return F_75 ( V_21 , V_120 , 1 ) ;
}
static int F_81 ( struct V_20 * V_112 , struct V_32 * V_33 ,
void T_6 * V_49 )
{
struct V_95 * V_120 ;
T_8 V_85 = F_79 ( V_112 , V_117 ) ? 2 : 0 ;
V_120 = F_69 ( V_33 -> V_21 -> V_79 ,
F_70 ( & V_33 -> V_77 ) ) ;
return F_74 ( V_49 , V_120 ,
F_79 ( V_33 -> V_21 , V_121 ) ) &&
( ! V_33 -> V_44 || F_72 ( V_49 , V_33 -> V_45 ,
sizeof * V_33 -> V_37 +
V_33 -> V_34 * sizeof * V_33 -> V_37 -> V_119 + V_85 ) ) ;
}
int F_82 ( struct V_32 * V_33 )
{
return F_78 ( V_33 -> V_21 , V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) &&
F_81 ( V_33 -> V_21 , V_33 , V_33 -> V_49 ) ;
}
static long F_83 ( struct V_20 * V_112 , struct V_95 T_6 * V_108 )
{
struct V_95 V_105 , * V_122 , * V_123 ;
unsigned long V_124 = F_63 ( struct V_95 , V_96 ) ;
if ( F_84 ( & V_105 , V_108 , V_124 ) )
return - V_125 ;
if ( V_105 . V_126 )
return - V_127 ;
if ( V_105 . V_97 > V_128 )
return - V_129 ;
V_122 = F_46 ( V_124 + V_105 . V_97 * sizeof * V_108 -> V_96 , V_74 ) ;
if ( ! V_122 )
return - V_76 ;
memcpy ( V_122 , & V_105 , V_124 ) ;
if ( F_84 ( V_122 -> V_96 , V_108 -> V_96 ,
V_105 . V_97 * sizeof * V_108 -> V_96 ) ) {
F_43 ( V_122 ) ;
return - V_125 ;
}
if ( ! F_75 ( V_112 , V_122 ,
F_79 ( V_112 , V_121 ) ) ) {
F_43 ( V_122 ) ;
return - V_125 ;
}
V_123 = F_69 ( V_112 -> V_79 ,
F_70 ( & V_112 -> V_77 ) ) ;
F_85 ( V_112 -> V_79 , V_122 ) ;
F_86 () ;
F_43 ( V_123 ) ;
return 0 ;
}
long F_87 ( struct V_20 * V_112 , int V_130 , void T_6 * V_131 )
{
struct V_1 * V_132 , * V_133 = NULL ;
bool V_134 = false , V_135 = false ;
struct V_136 * V_137 = NULL ;
T_9 T_6 * V_138 = V_131 ;
struct V_32 * V_33 ;
struct V_139 V_85 ;
struct V_140 V_141 ;
struct V_142 V_101 ;
T_9 V_143 ;
long V_144 ;
V_144 = F_88 ( V_143 , V_138 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_143 >= V_112 -> V_71 )
return - V_145 ;
V_33 = V_112 -> V_72 + V_143 ;
F_76 ( & V_33 -> V_77 ) ;
switch ( V_130 ) {
case V_146 :
if ( V_33 -> V_48 ) {
V_144 = - V_90 ;
break;
}
if ( F_84 ( & V_85 , V_131 , sizeof V_85 ) ) {
V_144 = - V_125 ;
break;
}
if ( ! V_85 . V_34 || V_85 . V_34 > 0xffff || ( V_85 . V_34 & ( V_85 . V_34 - 1 ) ) ) {
V_144 = - V_25 ;
break;
}
V_33 -> V_34 = V_85 . V_34 ;
break;
case V_147 :
if ( V_33 -> V_48 ) {
V_144 = - V_90 ;
break;
}
if ( F_84 ( & V_85 , V_131 , sizeof V_85 ) ) {
V_144 = - V_125 ;
break;
}
if ( V_85 . V_34 > 0xffff ) {
V_144 = - V_25 ;
break;
}
V_33 -> V_38 = V_85 . V_34 ;
V_33 -> V_39 = V_33 -> V_38 ;
break;
case V_148 :
V_85 . V_149 = V_143 ;
V_85 . V_34 = V_33 -> V_38 ;
if ( F_89 ( V_131 , & V_85 , sizeof V_85 ) )
V_144 = - V_125 ;
break;
case V_150 :
if ( F_84 ( & V_101 , V_131 , sizeof V_101 ) ) {
V_144 = - V_125 ;
break;
}
if ( V_101 . V_29 & ~ ( 0x1 << V_151 ) ) {
V_144 = - V_127 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_101 . V_152 != V_101 . V_152 ||
( T_7 ) ( unsigned long ) V_101 . V_153 != V_101 . V_153 ||
( T_7 ) ( unsigned long ) V_101 . V_154 != V_101 . V_154 ) {
V_144 = - V_125 ;
break;
}
if ( ( V_101 . V_154 & ( sizeof * V_33 -> V_36 -> V_119 - 1 ) ) ||
( V_101 . V_153 & ( sizeof * V_33 -> V_37 -> V_119 - 1 ) ) ||
( V_101 . V_155 & ( sizeof * V_33 -> V_37 -> V_119 - 1 ) ) ) {
V_144 = - V_25 ;
break;
}
if ( V_33 -> V_48 ) {
if ( ! F_78 ( V_112 , V_33 -> V_34 ,
( void T_6 * ) ( unsigned long ) V_101 . V_152 ,
( void T_6 * ) ( unsigned long ) V_101 . V_154 ,
( void T_6 * ) ( unsigned long ) V_101 . V_153 ) ) {
V_144 = - V_25 ;
break;
}
if ( ( V_101 . V_29 & ( 0x1 << V_151 ) ) &&
! F_72 ( V_33 -> V_49 , V_101 . V_155 ,
sizeof * V_33 -> V_37 +
V_33 -> V_34 * sizeof * V_33 -> V_37 -> V_119 ) ) {
V_144 = - V_25 ;
break;
}
}
V_33 -> V_44 = ! ! ( V_101 . V_29 & ( 0x1 << V_151 ) ) ;
V_33 -> V_35 = ( void T_6 * ) ( unsigned long ) V_101 . V_152 ;
V_33 -> V_36 = ( void T_6 * ) ( unsigned long ) V_101 . V_154 ;
V_33 -> V_45 = V_101 . V_155 ;
V_33 -> V_37 = ( void T_6 * ) ( unsigned long ) V_101 . V_153 ;
break;
case V_156 :
if ( F_84 ( & V_141 , V_131 , sizeof V_141 ) ) {
V_144 = - V_125 ;
break;
}
V_132 = V_141 . V_157 == - 1 ? NULL : F_90 ( V_141 . V_157 ) ;
if ( F_58 ( V_132 ) ) {
V_144 = F_59 ( V_132 ) ;
break;
}
if ( V_132 != V_33 -> V_51 ) {
V_135 = ( V_133 = V_33 -> V_51 ) != NULL ;
V_134 = ( V_33 -> V_51 = V_132 ) != NULL ;
} else
V_133 = V_132 ;
break;
case V_158 :
if ( F_84 ( & V_141 , V_131 , sizeof V_141 ) ) {
V_144 = - V_125 ;
break;
}
V_132 = V_141 . V_157 == - 1 ? NULL : F_90 ( V_141 . V_157 ) ;
if ( F_58 ( V_132 ) ) {
V_144 = F_59 ( V_132 ) ;
break;
}
if ( V_132 != V_33 -> V_53 ) {
V_133 = V_33 -> V_53 ;
V_137 = V_33 -> V_52 ;
V_33 -> V_53 = V_132 ;
V_33 -> V_52 = V_132 ?
F_91 ( V_132 ) : NULL ;
} else
V_133 = V_132 ;
break;
case V_159 :
if ( F_84 ( & V_141 , V_131 , sizeof V_141 ) ) {
V_144 = - V_125 ;
break;
}
V_132 = V_141 . V_157 == - 1 ? NULL : F_90 ( V_141 . V_157 ) ;
if ( F_58 ( V_132 ) ) {
V_144 = F_59 ( V_132 ) ;
break;
}
if ( V_132 != V_33 -> error ) {
V_133 = V_33 -> error ;
V_33 -> error = V_132 ;
V_137 = V_33 -> V_50 ;
V_33 -> V_50 = V_132 ?
F_91 ( V_132 ) : NULL ;
} else
V_133 = V_132 ;
break;
default:
V_144 = - V_160 ;
}
if ( V_135 && V_33 -> V_80 )
F_14 ( & V_33 -> V_5 ) ;
if ( V_137 )
F_67 ( V_137 ) ;
if ( V_133 )
F_68 ( V_133 ) ;
if ( V_134 && V_33 -> V_80 )
V_144 = F_12 ( & V_33 -> V_5 , V_33 -> V_51 ) ;
F_77 ( & V_33 -> V_77 ) ;
if ( V_135 && V_33 -> V_80 )
F_21 ( & V_33 -> V_5 ) ;
return V_144 ;
}
long F_92 ( struct V_20 * V_112 , unsigned int V_130 , void T_6 * V_131 )
{
struct V_1 * V_132 , * V_133 = NULL ;
struct V_136 * V_137 = NULL ;
T_7 V_161 ;
long V_144 ;
int V_69 , V_157 ;
if ( V_130 == V_162 ) {
V_144 = F_55 ( V_112 ) ;
goto V_16;
}
V_144 = F_51 ( V_112 ) ;
if ( V_144 )
goto V_16;
switch ( V_130 ) {
case V_163 :
V_144 = F_83 ( V_112 , V_131 ) ;
break;
case V_164 :
if ( F_84 ( & V_161 , V_131 , sizeof V_161 ) ) {
V_144 = - V_125 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_161 != V_161 ) {
V_144 = - V_125 ;
break;
}
for ( V_69 = 0 ; V_69 < V_112 -> V_71 ; ++ V_69 ) {
struct V_32 * V_33 ;
void T_6 * V_165 = ( void T_6 * ) ( unsigned long ) V_161 ;
V_33 = V_112 -> V_72 + V_69 ;
F_76 ( & V_33 -> V_77 ) ;
if ( V_33 -> V_48 && ! F_81 ( V_112 , V_33 , V_165 ) )
V_144 = - V_125 ;
else
V_33 -> V_49 = V_165 ;
F_77 ( & V_33 -> V_77 ) ;
}
break;
case V_166 :
V_144 = F_88 ( V_157 , ( int T_6 * ) V_131 ) ;
if ( V_144 < 0 )
break;
V_132 = V_157 == - 1 ? NULL : F_90 ( V_157 ) ;
if ( F_58 ( V_132 ) ) {
V_144 = F_59 ( V_132 ) ;
break;
}
if ( V_132 != V_112 -> V_78 ) {
V_133 = V_112 -> V_78 ;
V_137 = V_112 -> V_54 ;
V_112 -> V_54 = V_132 ?
F_91 ( V_132 ) : NULL ;
} else
V_133 = V_132 ;
for ( V_69 = 0 ; V_69 < V_112 -> V_71 ; ++ V_69 ) {
F_76 ( & V_112 -> V_72 [ V_69 ] . V_77 ) ;
V_112 -> V_72 [ V_69 ] . V_54 = V_112 -> V_54 ;
F_77 ( & V_112 -> V_72 [ V_69 ] . V_77 ) ;
}
if ( V_137 )
F_67 ( V_137 ) ;
if ( V_133 )
F_68 ( V_133 ) ;
break;
default:
V_144 = - V_160 ;
break;
}
V_16:
return V_144 ;
}
static const struct V_107 * F_93 ( struct V_95 * V_105 ,
T_10 V_99 , T_11 V_167 )
{
struct V_107 * V_168 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_105 -> V_97 ; ++ V_69 ) {
V_168 = V_105 -> V_96 + V_69 ;
if ( V_168 -> V_111 <= V_99 &&
V_168 -> V_111 + V_168 -> V_110 - 1 >= V_99 )
return V_168 ;
}
return NULL ;
}
static int F_94 ( int V_169 , void T_6 * V_99 )
{
unsigned long log = ( unsigned long ) V_99 ;
struct V_170 * V_170 ;
void * V_165 ;
int V_171 = V_169 + ( log % V_172 ) * 8 ;
int V_144 ;
V_144 = F_95 ( log , 1 , 1 , & V_170 ) ;
if ( V_144 < 0 )
return V_144 ;
F_20 ( V_144 != 1 ) ;
V_165 = F_96 ( V_170 ) ;
F_97 ( V_171 , V_165 ) ;
F_98 ( V_165 ) ;
F_99 ( V_170 ) ;
F_100 ( V_170 ) ;
return 0 ;
}
static int F_101 ( void T_6 * V_49 ,
T_7 V_173 , T_7 V_174 )
{
T_7 V_175 = V_173 / V_102 ;
int V_144 ;
if ( ! V_174 )
return 0 ;
V_174 += V_173 % V_102 ;
for (; ; ) {
T_7 V_165 = ( T_7 ) ( unsigned long ) V_49 ;
T_7 log = V_165 + V_175 / 8 ;
int V_171 = V_175 % 8 ;
if ( ( T_7 ) ( unsigned long ) log != log )
return - V_125 ;
V_144 = F_94 ( V_171 , ( void T_6 * ) ( unsigned long ) log ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_174 <= V_102 )
break;
V_174 -= V_102 ;
V_175 += 1 ;
}
return V_144 ;
}
int F_102 ( struct V_32 * V_33 , struct V_176 * log ,
unsigned int V_177 , T_7 V_167 )
{
int V_69 , V_144 ;
F_103 () ;
for ( V_69 = 0 ; V_69 < V_177 ; ++ V_69 ) {
T_7 V_178 = F_104 ( log [ V_69 ] . V_167 , V_167 ) ;
V_144 = F_101 ( V_33 -> V_49 , log [ V_69 ] . V_99 , V_178 ) ;
if ( V_144 < 0 )
return V_144 ;
V_167 -= V_178 ;
if ( ! V_167 ) {
if ( V_33 -> V_54 )
F_105 ( V_33 -> V_54 , 1 ) ;
return 0 ;
}
}
F_106 () ;
return 0 ;
}
static int F_107 ( struct V_32 * V_33 )
{
void T_6 * V_37 ;
if ( F_108 ( V_33 -> V_43 , & V_33 -> V_37 -> V_29 ) < 0 )
return - V_125 ;
if ( F_109 ( V_33 -> V_44 ) ) {
F_103 () ;
V_37 = & V_33 -> V_37 -> V_29 ;
F_101 ( V_33 -> V_49 , V_33 -> V_45 +
( V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof V_33 -> V_37 -> V_29 ) ;
if ( V_33 -> V_54 )
F_105 ( V_33 -> V_54 , 1 ) ;
}
return 0 ;
}
static int F_110 ( struct V_32 * V_33 , T_12 V_179 )
{
if ( F_108 ( V_33 -> V_39 , F_111 ( V_33 ) ) )
return - V_125 ;
if ( F_109 ( V_33 -> V_44 ) ) {
void T_6 * V_37 ;
F_103 () ;
V_37 = F_111 ( V_33 ) ;
F_101 ( V_33 -> V_49 , V_33 -> V_45 +
( V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof * F_111 ( V_33 ) ) ;
if ( V_33 -> V_54 )
F_105 ( V_33 -> V_54 , 1 ) ;
}
return 0 ;
}
int F_112 ( struct V_32 * V_33 )
{
int V_144 ;
if ( ! V_33 -> V_48 )
return 0 ;
V_144 = F_107 ( V_33 ) ;
if ( V_144 )
return V_144 ;
V_33 -> V_42 = false ;
return F_88 ( V_33 -> V_40 , & V_33 -> V_37 -> V_143 ) ;
}
static int F_113 ( struct V_20 * V_21 , T_7 V_99 , T_9 V_167 ,
struct V_180 V_181 [] , int V_182 )
{
const struct V_107 * V_168 ;
struct V_95 * V_105 ;
struct V_180 * V_183 ;
T_7 V_85 = 0 ;
int V_22 = 0 ;
F_114 () ;
V_105 = F_115 ( V_21 -> V_79 ) ;
while ( ( T_7 ) V_167 > V_85 ) {
T_7 V_124 ;
if ( F_109 ( V_22 >= V_182 ) ) {
V_22 = - V_145 ;
break;
}
V_168 = F_93 ( V_105 , V_99 , V_167 ) ;
if ( F_109 ( ! V_168 ) ) {
V_22 = - V_125 ;
break;
}
V_183 = V_181 + V_22 ;
V_124 = V_168 -> V_110 - V_99 + V_168 -> V_111 ;
V_183 -> V_184 = F_104 ( ( T_7 ) V_167 - V_85 , V_124 ) ;
V_183 -> V_185 = ( void T_6 * ) ( unsigned long )
( V_168 -> V_109 + V_99 - V_168 -> V_111 ) ;
V_85 += V_124 ;
V_99 += V_124 ;
++ V_22 ;
}
F_116 () ;
return V_22 ;
}
static unsigned F_117 ( struct V_114 * V_35 )
{
unsigned int V_186 ;
if ( ! ( V_35 -> V_29 & V_187 ) )
return - 1U ;
V_186 = V_35 -> V_186 ;
F_118 () ;
return V_186 ;
}
static int F_119 ( struct V_20 * V_21 , struct V_32 * V_33 ,
struct V_180 V_181 [] , unsigned int V_182 ,
unsigned int * V_188 , unsigned int * V_189 ,
struct V_176 * log , unsigned int * V_177 ,
struct V_114 * V_65 )
{
struct V_114 V_35 ;
unsigned int V_69 = 0 , V_190 , V_191 = 0 ;
int V_22 ;
if ( F_109 ( V_65 -> V_167 % sizeof V_35 ) ) {
F_120 ( V_33 , L_2
L_3 ,
( unsigned long long ) V_65 -> V_167 ,
sizeof V_35 ) ;
return - V_25 ;
}
V_22 = F_113 ( V_21 , V_65 -> V_99 , V_65 -> V_167 , V_33 -> V_65 ,
V_73 ) ;
if ( F_109 ( V_22 < 0 ) ) {
F_120 ( V_33 , L_4 , V_22 ) ;
return V_22 ;
}
F_118 () ;
V_190 = V_65 -> V_167 / sizeof V_35 ;
if ( F_109 ( V_190 > V_192 + 1 ) ) {
F_120 ( V_33 , L_5 ,
V_65 -> V_167 ) ;
return - V_129 ;
}
do {
unsigned V_193 = * V_189 + * V_188 ;
if ( F_109 ( ++ V_191 > V_190 ) ) {
F_120 ( V_33 , L_6
L_7 ,
V_69 , V_190 ) ;
return - V_25 ;
}
if ( F_109 ( F_121 ( ( unsigned char * ) & V_35 ,
V_33 -> V_65 , sizeof V_35 ) ) ) {
F_120 ( V_33 , L_8 ,
V_69 , ( T_8 ) V_65 -> V_99 + V_69 * sizeof V_35 ) ;
return - V_25 ;
}
if ( F_109 ( V_35 . V_29 & V_194 ) ) {
F_120 ( V_33 , L_9 ,
V_69 , ( T_8 ) V_65 -> V_99 + V_69 * sizeof V_35 ) ;
return - V_25 ;
}
V_22 = F_113 ( V_21 , V_35 . V_99 , V_35 . V_167 , V_181 + V_193 ,
V_182 - V_193 ) ;
if ( F_109 ( V_22 < 0 ) ) {
F_120 ( V_33 , L_10 ,
V_22 , V_69 ) ;
return V_22 ;
}
if ( V_35 . V_29 & V_195 ) {
* V_189 += V_22 ;
if ( F_109 ( log ) ) {
log [ * V_177 ] . V_99 = V_35 . V_99 ;
log [ * V_177 ] . V_167 = V_35 . V_167 ;
++ * V_177 ;
}
} else {
if ( F_109 ( * V_189 ) ) {
F_120 ( V_33 , L_11
L_12 , V_69 ) ;
return - V_25 ;
}
* V_188 += V_22 ;
}
} while ( ( V_69 = F_117 ( & V_35 ) ) != - 1 );
return 0 ;
}
int F_122 ( struct V_20 * V_21 , struct V_32 * V_33 ,
struct V_180 V_181 [] , unsigned int V_182 ,
unsigned int * V_188 , unsigned int * V_189 ,
struct V_176 * log , unsigned int * V_177 )
{
struct V_114 V_35 ;
unsigned int V_69 , V_196 , V_191 = 0 ;
T_12 V_38 ;
int V_22 ;
V_38 = V_33 -> V_38 ;
if ( F_109 ( F_123 ( V_33 -> V_39 , & V_33 -> V_36 -> V_143 ) ) ) {
F_120 ( V_33 , L_13 ,
& V_33 -> V_36 -> V_143 ) ;
return - V_125 ;
}
if ( F_109 ( ( T_12 ) ( V_33 -> V_39 - V_38 ) > V_33 -> V_34 ) ) {
F_120 ( V_33 , L_14 ,
V_38 , V_33 -> V_39 ) ;
return - V_125 ;
}
if ( V_33 -> V_39 == V_38 )
return V_33 -> V_34 ;
F_124 () ;
if ( F_109 ( F_123 ( V_196 ,
& V_33 -> V_36 -> V_119 [ V_38 % V_33 -> V_34 ] ) ) ) {
F_120 ( V_33 , L_15 ,
V_38 ,
& V_33 -> V_36 -> V_119 [ V_38 % V_33 -> V_34 ] ) ;
return - V_125 ;
}
if ( F_109 ( V_196 >= V_33 -> V_34 ) ) {
F_120 ( V_33 , L_16 ,
V_196 , V_33 -> V_34 ) ;
return - V_25 ;
}
* V_188 = * V_189 = 0 ;
if ( F_109 ( log ) )
* V_177 = 0 ;
V_69 = V_196 ;
do {
unsigned V_193 = * V_189 + * V_188 ;
if ( F_109 ( V_69 >= V_33 -> V_34 ) ) {
F_120 ( V_33 , L_17 ,
V_69 , V_33 -> V_34 , V_196 ) ;
return - V_25 ;
}
if ( F_109 ( ++ V_191 > V_33 -> V_34 ) ) {
F_120 ( V_33 , L_6
L_18 ,
V_69 , V_33 -> V_34 , V_196 ) ;
return - V_25 ;
}
V_22 = F_125 ( & V_35 , V_33 -> V_35 + V_69 , sizeof V_35 ) ;
if ( F_109 ( V_22 ) ) {
F_120 ( V_33 , L_19 ,
V_69 , V_33 -> V_35 + V_69 ) ;
return - V_125 ;
}
if ( V_35 . V_29 & V_194 ) {
V_22 = F_119 ( V_21 , V_33 , V_181 , V_182 ,
V_188 , V_189 ,
log , V_177 , & V_35 ) ;
if ( F_109 ( V_22 < 0 ) ) {
F_120 ( V_33 , L_20
L_21 , V_69 ) ;
return V_22 ;
}
continue;
}
V_22 = F_113 ( V_21 , V_35 . V_99 , V_35 . V_167 , V_181 + V_193 ,
V_182 - V_193 ) ;
if ( F_109 ( V_22 < 0 ) ) {
F_120 ( V_33 , L_22 ,
V_22 , V_69 ) ;
return V_22 ;
}
if ( V_35 . V_29 & V_195 ) {
* V_189 += V_22 ;
if ( F_109 ( log ) ) {
log [ * V_177 ] . V_99 = V_35 . V_99 ;
log [ * V_177 ] . V_167 = V_35 . V_167 ;
++ * V_177 ;
}
} else {
if ( F_109 ( * V_189 ) ) {
F_120 ( V_33 , L_23
L_24 , V_69 ) ;
return - V_25 ;
}
* V_188 += V_22 ;
}
} while ( ( V_69 = F_117 ( & V_35 ) ) != - 1 );
V_33 -> V_38 ++ ;
F_20 ( ! ( V_33 -> V_43 & V_197 ) ) ;
return V_196 ;
}
void F_126 ( struct V_32 * V_33 , int V_198 )
{
V_33 -> V_38 -= V_198 ;
}
int F_127 ( struct V_32 * V_33 , unsigned int V_196 , int V_167 )
{
struct V_199 T_6 * V_37 ;
V_37 = & V_33 -> V_37 -> V_119 [ V_33 -> V_40 % V_33 -> V_34 ] ;
if ( F_108 ( V_196 , & V_37 -> V_200 ) ) {
F_120 ( V_33 , L_25 ) ;
return - V_125 ;
}
if ( F_108 ( V_167 , & V_37 -> V_167 ) ) {
F_120 ( V_33 , L_26 ) ;
return - V_125 ;
}
F_103 () ;
if ( F_108 ( V_33 -> V_40 + 1 , & V_33 -> V_37 -> V_143 ) ) {
F_120 ( V_33 , L_27 ) ;
return - V_125 ;
}
if ( F_109 ( V_33 -> V_44 ) ) {
F_103 () ;
F_101 ( V_33 -> V_49 ,
V_33 -> V_45 +
( ( void T_6 * ) V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof *V_37 ) ;
F_101 ( V_33 -> V_49 ,
V_33 -> V_45 + F_63 ( struct V_116 , V_143 ) ,
sizeof V_33 -> V_37 -> V_143 ) ;
if ( V_33 -> V_54 )
F_105 ( V_33 -> V_54 , 1 ) ;
}
V_33 -> V_40 ++ ;
if ( F_109 ( V_33 -> V_40 == V_33 -> V_41 ) )
V_33 -> V_42 = false ;
return 0 ;
}
static int F_128 ( struct V_32 * V_33 ,
struct V_199 * V_66 ,
unsigned V_190 )
{
struct V_199 T_6 * V_37 ;
T_12 V_201 , V_202 ;
int V_203 ;
V_203 = V_33 -> V_40 % V_33 -> V_34 ;
V_37 = V_33 -> V_37 -> V_119 + V_203 ;
if ( F_129 ( V_37 , V_66 , V_190 * sizeof *V_37 ) ) {
F_120 ( V_33 , L_28 ) ;
return - V_125 ;
}
if ( F_109 ( V_33 -> V_44 ) ) {
F_103 () ;
F_101 ( V_33 -> V_49 ,
V_33 -> V_45 +
( ( void T_6 * ) V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
V_190 * sizeof *V_37 ) ;
}
V_201 = V_33 -> V_40 ;
V_202 = ( V_33 -> V_40 += V_190 ) ;
if ( F_109 ( ( T_12 ) ( V_202 - V_33 -> V_41 ) < ( T_12 ) ( V_202 - V_201 ) ) )
V_33 -> V_42 = false ;
return 0 ;
}
int F_130 ( struct V_32 * V_33 , struct V_199 * V_66 ,
unsigned V_190 )
{
int V_203 , V_198 , V_144 ;
V_203 = V_33 -> V_40 % V_33 -> V_34 ;
V_198 = V_33 -> V_34 - V_203 ;
if ( V_198 < V_190 ) {
V_144 = F_128 ( V_33 , V_66 , V_198 ) ;
if ( V_144 < 0 )
return V_144 ;
V_66 += V_198 ;
V_190 -= V_198 ;
}
V_144 = F_128 ( V_33 , V_66 , V_190 ) ;
F_103 () ;
if ( F_131 ( V_33 -> V_40 , & V_33 -> V_37 -> V_143 ) ) {
F_120 ( V_33 , L_27 ) ;
return - V_125 ;
}
if ( F_109 ( V_33 -> V_44 ) ) {
F_101 ( V_33 -> V_49 ,
V_33 -> V_45 + F_63 ( struct V_116 , V_143 ) ,
sizeof V_33 -> V_37 -> V_143 ) ;
if ( V_33 -> V_54 )
F_105 ( V_33 -> V_54 , 1 ) ;
}
return V_144 ;
}
static bool F_132 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
T_13 V_201 , V_202 , V_204 ;
bool V_205 ;
F_133 () ;
if ( F_79 ( V_21 , V_206 ) &&
F_109 ( V_33 -> V_39 == V_33 -> V_38 ) )
return true ;
if ( ! F_79 ( V_21 , V_117 ) ) {
T_13 V_29 ;
if ( F_123 ( V_29 , & V_33 -> V_36 -> V_29 ) ) {
F_120 ( V_33 , L_29 ) ;
return true ;
}
return ! ( V_29 & V_207 ) ;
}
V_201 = V_33 -> V_41 ;
V_205 = V_33 -> V_42 ;
V_202 = V_33 -> V_41 = V_33 -> V_40 ;
V_33 -> V_42 = true ;
if ( F_109 ( ! V_205 ) )
return true ;
if ( F_88 ( V_204 , F_134 ( V_33 ) ) ) {
F_120 ( V_33 , L_30 ) ;
return true ;
}
return F_135 ( V_204 , V_202 , V_201 ) ;
}
void F_136 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
if ( V_33 -> V_52 && F_132 ( V_21 , V_33 ) )
F_105 ( V_33 -> V_52 , 1 ) ;
}
void F_137 ( struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int V_196 , int V_167 )
{
F_127 ( V_33 , V_196 , V_167 ) ;
F_136 ( V_21 , V_33 ) ;
}
void F_138 ( struct V_20 * V_21 ,
struct V_32 * V_33 ,
struct V_199 * V_66 , unsigned V_190 )
{
F_130 ( V_33 , V_66 , V_190 ) ;
F_136 ( V_21 , V_33 ) ;
}
bool F_139 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
T_12 V_39 ;
int V_144 ;
if ( ! ( V_33 -> V_43 & V_197 ) )
return false ;
V_33 -> V_43 &= ~ V_197 ;
if ( ! F_79 ( V_21 , V_117 ) ) {
V_144 = F_107 ( V_33 ) ;
if ( V_144 ) {
F_120 ( V_33 , L_31 ,
& V_33 -> V_37 -> V_29 , V_144 ) ;
return false ;
}
} else {
V_144 = F_110 ( V_33 , V_33 -> V_39 ) ;
if ( V_144 ) {
F_120 ( V_33 , L_32 ,
F_111 ( V_33 ) , V_144 ) ;
return false ;
}
}
F_133 () ;
V_144 = F_123 ( V_39 , & V_33 -> V_36 -> V_143 ) ;
if ( V_144 ) {
F_120 ( V_33 , L_33 ,
& V_33 -> V_36 -> V_143 , V_144 ) ;
return false ;
}
return V_39 != V_33 -> V_39 ;
}
void F_140 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
int V_144 ;
if ( V_33 -> V_43 & V_197 )
return;
V_33 -> V_43 |= V_197 ;
if ( ! F_79 ( V_21 , V_117 ) ) {
V_144 = F_107 ( V_33 ) ;
if ( V_144 )
F_120 ( V_33 , L_31 ,
& V_33 -> V_37 -> V_29 , V_144 ) ;
}
}
static void F_141 ( struct V_208 * V_208 )
{
struct V_209 * V_57 = F_2 ( V_208 , struct V_209 ,
V_208 ) ;
F_142 ( & V_57 -> V_7 ) ;
}
struct V_209 * F_143 ( struct V_32 * V_33 ,
bool V_70 )
{
struct V_209 * V_57 ;
if ( ! V_70 )
return NULL ;
V_57 = F_46 ( sizeof *V_57 , V_74 ) ;
if ( ! V_57 )
return F_144 ( - V_76 ) ;
F_145 ( & V_57 -> V_208 ) ;
F_8 ( & V_57 -> V_7 ) ;
V_57 -> V_33 = V_33 ;
return V_57 ;
}
void F_146 ( struct V_209 * V_57 )
{
F_147 ( & V_57 -> V_208 , F_141 ) ;
}
void F_148 ( struct V_209 * V_57 )
{
F_147 ( & V_57 -> V_208 , F_141 ) ;
F_19 ( V_57 -> V_7 , ! F_149 ( & V_57 -> V_208 . V_210 ) ) ;
F_43 ( V_57 ) ;
}
