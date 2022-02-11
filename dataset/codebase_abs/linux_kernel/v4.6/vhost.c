static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = ! F_2 () ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 = true ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_4 )
{
struct V_5 V_6 ;
if ( V_2 -> V_7 )
return - V_8 ;
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) )
return - V_9 ;
if ( V_6 . V_10 != V_11 &&
V_6 . V_10 != V_12 )
return - V_13 ;
if ( V_6 . V_10 == V_12 )
F_3 ( V_2 ) ;
else
F_4 ( V_2 ) ;
return 0 ;
}
static long F_7 ( struct V_1 * V_2 , T_2 V_14 ,
int T_1 * V_4 )
{
struct V_5 V_6 = {
. V_15 = V_14 ,
. V_10 = V_2 -> V_3
} ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
return - V_9 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_10 ( V_2 , V_17 ) || ! V_2 -> V_3 ;
}
static void F_1 ( struct V_1 * V_2 )
{
}
static long F_5 ( struct V_1 * V_2 , int T_1 * V_4 )
{
return - V_18 ;
}
static long F_7 ( struct V_1 * V_2 , T_2 V_14 ,
int T_1 * V_4 )
{
return - V_18 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 , V_17 ) )
V_2 -> V_16 = true ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_2 () ;
}
static void F_12 ( struct V_19 * V_19 , T_3 * V_20 ,
T_4 * V_21 )
{
struct V_22 * V_23 ;
V_23 = F_13 ( V_21 , struct V_22 , V_24 ) ;
V_23 -> V_20 = V_20 ;
F_14 ( V_20 , & V_23 -> V_25 ) ;
}
static int F_15 ( T_5 * V_25 , unsigned V_26 , int V_27 ,
void * V_28 )
{
struct V_22 * V_23 = F_13 ( V_25 , struct V_22 , V_25 ) ;
if ( ! ( ( unsigned long ) V_28 & V_23 -> V_29 ) )
return 0 ;
F_16 ( V_23 ) ;
return 0 ;
}
void F_17 ( struct V_30 * V_31 , T_6 V_32 )
{
F_18 ( & V_31 -> V_33 ) ;
V_31 -> V_32 = V_32 ;
F_19 ( & V_31 -> V_34 ) ;
V_31 -> V_35 = 0 ;
V_31 -> V_36 = V_31 -> V_37 = 0 ;
}
void F_20 ( struct V_22 * V_23 , T_6 V_32 ,
unsigned long V_29 , struct V_38 * V_39 )
{
F_21 ( & V_23 -> V_25 , F_15 ) ;
F_22 ( & V_23 -> V_24 , F_12 ) ;
V_23 -> V_29 = V_29 ;
V_23 -> V_39 = V_39 ;
V_23 -> V_20 = NULL ;
F_17 ( & V_23 -> V_31 , V_32 ) ;
}
int F_23 ( struct V_22 * V_23 , struct V_19 * V_19 )
{
unsigned long V_29 ;
int V_40 = 0 ;
if ( V_23 -> V_20 )
return 0 ;
V_29 = V_19 -> V_41 -> V_23 ( V_19 , & V_23 -> V_24 ) ;
if ( V_29 )
F_15 ( & V_23 -> V_25 , 0 , 0 , ( void * ) V_29 ) ;
if ( V_29 & V_42 ) {
if ( V_23 -> V_20 )
F_24 ( V_23 -> V_20 , & V_23 -> V_25 ) ;
V_40 = - V_13 ;
}
return V_40 ;
}
void F_25 ( struct V_22 * V_23 )
{
if ( V_23 -> V_20 ) {
F_24 ( V_23 -> V_20 , & V_23 -> V_25 ) ;
V_23 -> V_20 = NULL ;
}
}
static bool F_26 ( struct V_38 * V_39 , struct V_30 * V_31 ,
unsigned V_43 )
{
int V_44 ;
F_27 ( & V_39 -> V_45 ) ;
V_44 = V_43 - V_31 -> V_37 ;
F_28 ( & V_39 -> V_45 ) ;
return V_44 <= 0 ;
}
void F_29 ( struct V_38 * V_39 , struct V_30 * V_31 )
{
unsigned V_43 ;
int V_35 ;
F_27 ( & V_39 -> V_45 ) ;
V_43 = V_31 -> V_36 ;
V_31 -> V_35 ++ ;
F_28 ( & V_39 -> V_45 ) ;
F_30 ( V_31 -> V_34 , F_26 ( V_39 , V_31 , V_43 ) ) ;
F_27 ( & V_39 -> V_45 ) ;
V_35 = -- V_31 -> V_35 ;
F_28 ( & V_39 -> V_45 ) ;
F_31 ( V_35 < 0 ) ;
}
void F_32 ( struct V_22 * V_23 )
{
F_29 ( V_23 -> V_39 , & V_23 -> V_31 ) ;
}
void F_33 ( struct V_38 * V_39 , struct V_30 * V_31 )
{
unsigned long V_46 ;
F_34 ( & V_39 -> V_45 , V_46 ) ;
if ( F_35 ( & V_31 -> V_33 ) ) {
F_36 ( & V_31 -> V_33 , & V_39 -> V_47 ) ;
V_31 -> V_36 ++ ;
F_37 ( & V_39 -> V_45 , V_46 ) ;
F_38 ( V_39 -> V_48 ) ;
} else {
F_37 ( & V_39 -> V_45 , V_46 ) ;
}
}
bool F_39 ( struct V_38 * V_39 )
{
return ! F_35 ( & V_39 -> V_47 ) ;
}
void F_16 ( struct V_22 * V_23 )
{
F_33 ( V_23 -> V_39 , & V_23 -> V_31 ) ;
}
static void F_40 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
V_2 -> V_10 = 1 ;
V_2 -> V_49 = NULL ;
V_2 -> V_50 = NULL ;
V_2 -> V_51 = NULL ;
V_2 -> V_52 = 0 ;
V_2 -> V_53 = 0 ;
V_2 -> V_54 = 0 ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = false ;
V_2 -> V_57 = 0 ;
V_2 -> V_58 = false ;
V_2 -> V_59 = - 1ull ;
V_2 -> V_7 = NULL ;
V_2 -> V_60 = 0 ;
V_2 -> V_61 = NULL ;
V_2 -> V_62 = NULL ;
V_2 -> error = NULL ;
V_2 -> V_63 = NULL ;
V_2 -> V_64 = NULL ;
V_2 -> V_65 = NULL ;
V_2 -> V_66 = NULL ;
V_2 -> V_67 = NULL ;
F_11 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_68 = 0 ;
}
static int F_41 ( void * V_69 )
{
struct V_38 * V_39 = V_69 ;
struct V_30 * V_31 = NULL ;
unsigned V_70 ( V_43 ) ;
T_7 V_71 = F_42 () ;
F_43 ( V_72 ) ;
F_44 ( V_39 -> V_73 ) ;
for (; ; ) {
F_45 ( V_74 ) ;
F_27 ( & V_39 -> V_45 ) ;
if ( V_31 ) {
V_31 -> V_37 = V_43 ;
if ( V_31 -> V_35 )
F_46 ( & V_31 -> V_34 ) ;
}
if ( F_47 () ) {
F_28 ( & V_39 -> V_45 ) ;
F_48 ( V_75 ) ;
break;
}
if ( ! F_35 ( & V_39 -> V_47 ) ) {
V_31 = F_49 ( & V_39 -> V_47 ,
struct V_30 , V_33 ) ;
F_50 ( & V_31 -> V_33 ) ;
V_43 = V_31 -> V_36 ;
} else
V_31 = NULL ;
F_28 ( & V_39 -> V_45 ) ;
if ( V_31 ) {
F_48 ( V_75 ) ;
V_31 -> V_32 ( V_31 ) ;
if ( F_51 () )
F_52 () ;
} else
F_52 () ;
}
F_53 ( V_39 -> V_73 ) ;
F_43 ( V_71 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
F_55 ( V_2 -> log ) ;
V_2 -> log = NULL ;
F_55 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
}
static long F_56 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
V_2 = V_39 -> V_80 [ V_78 ] ;
V_2 -> V_76 = F_57 ( sizeof * V_2 -> V_76 * V_81 ,
V_82 ) ;
V_2 -> log = F_57 ( sizeof * V_2 -> log * V_81 , V_82 ) ;
V_2 -> V_77 = F_57 ( sizeof * V_2 -> V_77 * V_81 , V_82 ) ;
if ( ! V_2 -> V_76 || ! V_2 -> log || ! V_2 -> V_77 )
goto V_83;
}
return 0 ;
V_83:
for (; V_78 >= 0 ; -- V_78 )
F_54 ( V_39 -> V_80 [ V_78 ] ) ;
return - V_84 ;
}
static void F_58 ( struct V_38 * V_39 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 )
F_54 ( V_39 -> V_80 [ V_78 ] ) ;
}
void F_59 ( struct V_38 * V_39 ,
struct V_1 * * V_80 , int V_79 )
{
struct V_1 * V_2 ;
int V_78 ;
V_39 -> V_80 = V_80 ;
V_39 -> V_79 = V_79 ;
F_60 ( & V_39 -> V_85 ) ;
V_39 -> V_66 = NULL ;
V_39 -> V_86 = NULL ;
V_39 -> V_67 = NULL ;
V_39 -> V_73 = NULL ;
F_61 ( & V_39 -> V_45 ) ;
F_18 ( & V_39 -> V_47 ) ;
V_39 -> V_48 = NULL ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
V_2 = V_39 -> V_80 [ V_78 ] ;
V_2 -> log = NULL ;
V_2 -> V_76 = NULL ;
V_2 -> V_77 = NULL ;
V_2 -> V_39 = V_39 ;
F_60 ( & V_2 -> V_85 ) ;
F_40 ( V_39 , V_2 ) ;
if ( V_2 -> V_87 )
F_20 ( & V_2 -> V_23 , V_2 -> V_87 ,
V_88 , V_39 ) ;
}
}
long F_62 ( struct V_38 * V_39 )
{
return V_39 -> V_73 == V_89 -> V_73 ? 0 : - V_90 ;
}
static void F_63 ( struct V_30 * V_31 )
{
struct V_91 * V_6 ;
V_6 = F_13 ( V_31 , struct V_91 , V_31 ) ;
V_6 -> V_40 = F_64 ( V_6 -> V_92 , V_89 ) ;
}
static int F_65 ( struct V_38 * V_39 )
{
struct V_91 V_93 ;
V_93 . V_92 = V_89 ;
F_17 ( & V_93 . V_31 , F_63 ) ;
F_33 ( V_39 , & V_93 . V_31 ) ;
F_29 ( V_39 , & V_93 . V_31 ) ;
return V_93 . V_40 ;
}
bool F_66 ( struct V_38 * V_39 )
{
return V_39 -> V_73 ;
}
long F_67 ( struct V_38 * V_39 )
{
struct V_94 * V_48 ;
int V_95 ;
if ( F_66 ( V_39 ) ) {
V_95 = - V_8 ;
goto V_96;
}
V_39 -> V_73 = F_68 ( V_89 ) ;
V_48 = F_69 ( F_41 , V_39 , L_1 , V_89 -> V_97 ) ;
if ( F_70 ( V_48 ) ) {
V_95 = F_71 ( V_48 ) ;
goto V_98;
}
V_39 -> V_48 = V_48 ;
F_38 ( V_48 ) ;
V_95 = F_65 ( V_39 ) ;
if ( V_95 )
goto V_99;
V_95 = F_56 ( V_39 ) ;
if ( V_95 )
goto V_99;
return 0 ;
V_99:
F_72 ( V_48 ) ;
V_39 -> V_48 = NULL ;
V_98:
if ( V_39 -> V_73 )
F_73 ( V_39 -> V_73 ) ;
V_39 -> V_73 = NULL ;
V_96:
return V_95 ;
}
struct V_100 * F_74 ( void )
{
return F_57 ( F_75 ( struct V_100 , V_101 ) , V_82 ) ;
}
void F_76 ( struct V_38 * V_39 , struct V_100 * V_67 )
{
int V_78 ;
F_77 ( V_39 , true ) ;
V_67 -> V_102 = 0 ;
V_39 -> V_67 = V_67 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 )
V_39 -> V_80 [ V_78 ] -> V_67 = V_67 ;
}
void F_78 ( struct V_38 * V_39 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
if ( V_39 -> V_80 [ V_78 ] -> V_63 && V_39 -> V_80 [ V_78 ] -> V_87 ) {
F_25 ( & V_39 -> V_80 [ V_78 ] -> V_23 ) ;
F_32 ( & V_39 -> V_80 [ V_78 ] -> V_23 ) ;
}
}
}
void F_77 ( struct V_38 * V_39 , bool V_103 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_39 -> V_79 ; ++ V_78 ) {
if ( V_39 -> V_80 [ V_78 ] -> V_62 )
F_79 ( V_39 -> V_80 [ V_78 ] -> V_62 ) ;
if ( V_39 -> V_80 [ V_78 ] -> error )
F_80 ( V_39 -> V_80 [ V_78 ] -> error ) ;
if ( V_39 -> V_80 [ V_78 ] -> V_63 )
F_80 ( V_39 -> V_80 [ V_78 ] -> V_63 ) ;
if ( V_39 -> V_80 [ V_78 ] -> V_64 )
F_79 ( V_39 -> V_80 [ V_78 ] -> V_64 ) ;
if ( V_39 -> V_80 [ V_78 ] -> V_65 )
F_80 ( V_39 -> V_80 [ V_78 ] -> V_65 ) ;
F_40 ( V_39 , V_39 -> V_80 [ V_78 ] ) ;
}
F_58 ( V_39 ) ;
if ( V_39 -> V_66 )
F_79 ( V_39 -> V_66 ) ;
V_39 -> V_66 = NULL ;
if ( V_39 -> V_86 )
F_80 ( V_39 -> V_86 ) ;
V_39 -> V_86 = NULL ;
F_81 ( V_39 -> V_67 ) ;
V_39 -> V_67 = NULL ;
F_82 ( ! F_35 ( & V_39 -> V_47 ) ) ;
if ( V_39 -> V_48 ) {
F_72 ( V_39 -> V_48 ) ;
V_39 -> V_48 = NULL ;
}
if ( V_39 -> V_73 )
F_73 ( V_39 -> V_73 ) ;
V_39 -> V_73 = NULL ;
}
static int F_83 ( void T_1 * V_61 , T_8 V_104 , unsigned long V_105 )
{
T_8 V_106 = V_104 / V_107 / 8 ;
if ( V_106 > V_108 - ( unsigned long ) V_61 ||
V_106 + ( unsigned long ) V_61 > V_108 )
return 0 ;
return F_84 ( V_109 , V_61 + V_106 ,
( V_105 + V_107 * 8 - 1 ) / V_107 / 8 ) ;
}
static int F_85 ( void T_1 * V_61 , struct V_100 * V_110 ,
int V_111 )
{
int V_78 ;
if ( ! V_110 )
return 0 ;
for ( V_78 = 0 ; V_78 < V_110 -> V_102 ; ++ V_78 ) {
struct V_112 * V_113 = V_110 -> V_101 + V_78 ;
unsigned long V_106 = V_113 -> V_114 ;
if ( V_113 -> V_115 > V_108 )
return 0 ;
else if ( ! F_84 ( V_109 , ( void T_1 * ) V_106 ,
V_113 -> V_115 ) )
return 0 ;
else if ( V_111 && ! F_83 ( V_61 ,
V_113 -> V_116 ,
V_113 -> V_115 ) )
return 0 ;
}
return 1 ;
}
static int F_86 ( struct V_38 * V_117 , struct V_100 * V_110 ,
int V_111 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_117 -> V_79 ; ++ V_78 ) {
int V_118 ;
bool log ;
F_87 ( & V_117 -> V_80 [ V_78 ] -> V_85 ) ;
log = V_111 || F_10 ( V_117 -> V_80 [ V_78 ] , V_119 ) ;
if ( V_117 -> V_80 [ V_78 ] -> V_7 )
V_118 = F_85 ( V_117 -> V_80 [ V_78 ] -> V_61 , V_110 , log ) ;
else
V_118 = 1 ;
F_88 ( & V_117 -> V_80 [ V_78 ] -> V_85 ) ;
if ( ! V_118 )
return 0 ;
}
return 1 ;
}
static int F_89 ( struct V_1 * V_2 , unsigned int V_10 ,
struct V_120 T_1 * V_49 ,
struct V_121 T_1 * V_50 ,
struct V_122 T_1 * V_51 )
{
T_9 V_6 = F_10 ( V_2 , V_123 ) ? 2 : 0 ;
return F_84 ( V_124 , V_49 , V_10 * sizeof *V_49 ) &&
F_84 ( V_124 , V_50 ,
sizeof *V_50 + V_10 * sizeof * V_50 -> V_125 + V_6 ) &&
F_84 ( V_109 , V_51 ,
sizeof *V_51 + V_10 * sizeof * V_51 -> V_125 + V_6 ) ;
}
int F_90 ( struct V_38 * V_39 )
{
return F_86 ( V_39 , V_39 -> V_67 , 1 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
void T_1 * V_61 )
{
T_9 V_6 = F_10 ( V_2 , V_123 ) ? 2 : 0 ;
return F_85 ( V_61 , V_2 -> V_67 ,
F_10 ( V_2 , V_119 ) ) &&
( ! V_2 -> V_58 || F_83 ( V_61 , V_2 -> V_59 ,
sizeof * V_2 -> V_51 +
V_2 -> V_10 * sizeof * V_2 -> V_51 -> V_125 + V_6 ) ) ;
}
int F_92 ( struct V_1 * V_2 )
{
return F_89 ( V_2 , V_2 -> V_10 , V_2 -> V_49 , V_2 -> V_50 , V_2 -> V_51 ) &&
F_91 ( V_2 , V_2 -> V_61 ) ;
}
static int F_93 ( const void * V_126 , const void * V_127 )
{
const struct V_112 * V_128 = V_126 , * V_129 = V_127 ;
if ( V_128 -> V_116 < V_129 -> V_116 )
return 1 ;
if ( V_128 -> V_116 > V_129 -> V_116 )
return - 1 ;
return 0 ;
}
static void * F_94 ( unsigned long V_130 )
{
void * V_131 = F_95 ( V_130 , V_82 | V_132 | V_133 ) ;
if ( ! V_131 )
V_131 = F_96 ( V_130 ) ;
return V_131 ;
}
static long F_97 ( struct V_38 * V_117 , struct V_100 T_1 * V_113 )
{
struct V_100 V_110 , * V_134 , * V_135 ;
unsigned long V_130 = F_75 ( struct V_100 , V_101 ) ;
int V_78 ;
if ( F_6 ( & V_110 , V_113 , V_130 ) )
return - V_9 ;
if ( V_110 . V_136 )
return - V_137 ;
if ( V_110 . V_102 > V_138 )
return - V_139 ;
V_134 = F_94 ( V_130 + V_110 . V_102 * sizeof( * V_113 -> V_101 ) ) ;
if ( ! V_134 )
return - V_84 ;
memcpy ( V_134 , & V_110 , V_130 ) ;
if ( F_6 ( V_134 -> V_101 , V_113 -> V_101 ,
V_110 . V_102 * sizeof * V_113 -> V_101 ) ) {
F_81 ( V_134 ) ;
return - V_9 ;
}
F_98 ( V_134 -> V_101 , V_134 -> V_102 , sizeof( * V_134 -> V_101 ) ,
F_93 , NULL ) ;
if ( ! F_86 ( V_117 , V_134 , 0 ) ) {
F_81 ( V_134 ) ;
return - V_9 ;
}
V_135 = V_117 -> V_67 ;
V_117 -> V_67 = V_134 ;
for ( V_78 = 0 ; V_78 < V_117 -> V_79 ; ++ V_78 ) {
F_87 ( & V_117 -> V_80 [ V_78 ] -> V_85 ) ;
V_117 -> V_80 [ V_78 ] -> V_67 = V_134 ;
F_88 ( & V_117 -> V_80 [ V_78 ] -> V_85 ) ;
}
F_81 ( V_135 ) ;
return 0 ;
}
long F_99 ( struct V_38 * V_117 , int V_140 , void T_1 * V_4 )
{
struct V_19 * V_141 , * V_142 = NULL ;
bool V_143 = false , V_144 = false ;
struct V_145 * V_146 = NULL ;
T_2 T_1 * V_147 = V_4 ;
struct V_1 * V_2 ;
struct V_5 V_6 ;
struct V_148 V_149 ;
struct V_150 V_106 ;
T_2 V_14 ;
long V_151 ;
V_151 = F_100 ( V_14 , V_147 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_14 >= V_117 -> V_79 )
return - V_152 ;
V_2 = V_117 -> V_80 [ V_14 ] ;
F_87 ( & V_2 -> V_85 ) ;
switch ( V_140 ) {
case V_153 :
if ( V_2 -> V_7 ) {
V_151 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_151 = - V_9 ;
break;
}
if ( ! V_6 . V_10 || V_6 . V_10 > 0xffff || ( V_6 . V_10 & ( V_6 . V_10 - 1 ) ) ) {
V_151 = - V_13 ;
break;
}
V_2 -> V_10 = V_6 . V_10 ;
break;
case V_154 :
if ( V_2 -> V_7 ) {
V_151 = - V_8 ;
break;
}
if ( F_6 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_151 = - V_9 ;
break;
}
if ( V_6 . V_10 > 0xffff ) {
V_151 = - V_13 ;
break;
}
V_2 -> V_52 = V_6 . V_10 ;
V_2 -> V_53 = V_2 -> V_52 ;
break;
case V_155 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_52 ;
if ( F_8 ( V_4 , & V_6 , sizeof V_6 ) )
V_151 = - V_9 ;
break;
case V_156 :
if ( F_6 ( & V_106 , V_4 , sizeof V_106 ) ) {
V_151 = - V_9 ;
break;
}
if ( V_106 . V_46 & ~ ( 0x1 << V_157 ) ) {
V_151 = - V_137 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_106 . V_158 != V_106 . V_158 ||
( T_8 ) ( unsigned long ) V_106 . V_159 != V_106 . V_159 ||
( T_8 ) ( unsigned long ) V_106 . V_160 != V_106 . V_160 ) {
V_151 = - V_9 ;
break;
}
F_101 ( V_161 * V_2 -> V_50 > V_162 ) ;
F_101 ( V_161 * V_2 -> V_51 > V_163 ) ;
if ( ( V_106 . V_160 & ( V_162 - 1 ) ) ||
( V_106 . V_159 & ( V_163 - 1 ) ) ||
( V_106 . V_164 & ( V_163 - 1 ) ) ) {
V_151 = - V_13 ;
break;
}
if ( V_2 -> V_7 ) {
if ( ! F_89 ( V_2 , V_2 -> V_10 ,
( void T_1 * ) ( unsigned long ) V_106 . V_158 ,
( void T_1 * ) ( unsigned long ) V_106 . V_160 ,
( void T_1 * ) ( unsigned long ) V_106 . V_159 ) ) {
V_151 = - V_13 ;
break;
}
if ( ( V_106 . V_46 & ( 0x1 << V_157 ) ) &&
! F_83 ( V_2 -> V_61 , V_106 . V_164 ,
sizeof * V_2 -> V_51 +
V_2 -> V_10 * sizeof * V_2 -> V_51 -> V_125 ) ) {
V_151 = - V_13 ;
break;
}
}
V_2 -> V_58 = ! ! ( V_106 . V_46 & ( 0x1 << V_157 ) ) ;
V_2 -> V_49 = ( void T_1 * ) ( unsigned long ) V_106 . V_158 ;
V_2 -> V_50 = ( void T_1 * ) ( unsigned long ) V_106 . V_160 ;
V_2 -> V_59 = V_106 . V_164 ;
V_2 -> V_51 = ( void T_1 * ) ( unsigned long ) V_106 . V_159 ;
break;
case V_165 :
if ( F_6 ( & V_149 , V_4 , sizeof V_149 ) ) {
V_151 = - V_9 ;
break;
}
V_141 = V_149 . V_166 == - 1 ? NULL : F_102 ( V_149 . V_166 ) ;
if ( F_70 ( V_141 ) ) {
V_151 = F_71 ( V_141 ) ;
break;
}
if ( V_141 != V_2 -> V_63 ) {
V_144 = ( V_142 = V_2 -> V_63 ) != NULL ;
V_143 = ( V_2 -> V_63 = V_141 ) != NULL ;
} else
V_142 = V_141 ;
break;
case V_167 :
if ( F_6 ( & V_149 , V_4 , sizeof V_149 ) ) {
V_151 = - V_9 ;
break;
}
V_141 = V_149 . V_166 == - 1 ? NULL : F_102 ( V_149 . V_166 ) ;
if ( F_70 ( V_141 ) ) {
V_151 = F_71 ( V_141 ) ;
break;
}
if ( V_141 != V_2 -> V_65 ) {
V_142 = V_2 -> V_65 ;
V_146 = V_2 -> V_64 ;
V_2 -> V_65 = V_141 ;
V_2 -> V_64 = V_141 ?
F_103 ( V_141 ) : NULL ;
} else
V_142 = V_141 ;
break;
case V_168 :
if ( F_6 ( & V_149 , V_4 , sizeof V_149 ) ) {
V_151 = - V_9 ;
break;
}
V_141 = V_149 . V_166 == - 1 ? NULL : F_102 ( V_149 . V_166 ) ;
if ( F_70 ( V_141 ) ) {
V_151 = F_71 ( V_141 ) ;
break;
}
if ( V_141 != V_2 -> error ) {
V_142 = V_2 -> error ;
V_2 -> error = V_141 ;
V_146 = V_2 -> V_62 ;
V_2 -> V_62 = V_141 ?
F_103 ( V_141 ) : NULL ;
} else
V_142 = V_141 ;
break;
case V_169 :
V_151 = F_5 ( V_2 , V_4 ) ;
break;
case V_170 :
V_151 = F_7 ( V_2 , V_14 , V_4 ) ;
break;
case V_171 :
if ( F_6 ( & V_6 , V_4 , sizeof( V_6 ) ) ) {
V_151 = - V_9 ;
break;
}
V_2 -> V_68 = V_6 . V_10 ;
break;
case V_172 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_68 ;
if ( F_8 ( V_4 , & V_6 , sizeof( V_6 ) ) )
V_151 = - V_9 ;
break;
default:
V_151 = - V_18 ;
}
if ( V_144 && V_2 -> V_87 )
F_25 ( & V_2 -> V_23 ) ;
if ( V_146 )
F_79 ( V_146 ) ;
if ( V_142 )
F_80 ( V_142 ) ;
if ( V_143 && V_2 -> V_87 )
V_151 = F_23 ( & V_2 -> V_23 , V_2 -> V_63 ) ;
F_88 ( & V_2 -> V_85 ) ;
if ( V_144 && V_2 -> V_87 )
F_32 ( & V_2 -> V_23 ) ;
return V_151 ;
}
long F_104 ( struct V_38 * V_117 , unsigned int V_140 , void T_1 * V_4 )
{
struct V_19 * V_141 , * V_142 = NULL ;
struct V_145 * V_146 = NULL ;
T_8 V_173 ;
long V_151 ;
int V_78 , V_166 ;
if ( V_140 == V_174 ) {
V_151 = F_67 ( V_117 ) ;
goto V_34;
}
V_151 = F_62 ( V_117 ) ;
if ( V_151 )
goto V_34;
switch ( V_140 ) {
case V_175 :
V_151 = F_97 ( V_117 , V_4 ) ;
break;
case V_176 :
if ( F_6 ( & V_173 , V_4 , sizeof V_173 ) ) {
V_151 = - V_9 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_173 != V_173 ) {
V_151 = - V_9 ;
break;
}
for ( V_78 = 0 ; V_78 < V_117 -> V_79 ; ++ V_78 ) {
struct V_1 * V_2 ;
void T_1 * V_177 = ( void T_1 * ) ( unsigned long ) V_173 ;
V_2 = V_117 -> V_80 [ V_78 ] ;
F_87 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_7 && ! F_91 ( V_2 , V_177 ) )
V_151 = - V_9 ;
else
V_2 -> V_61 = V_177 ;
F_88 ( & V_2 -> V_85 ) ;
}
break;
case V_178 :
V_151 = F_100 ( V_166 , ( int T_1 * ) V_4 ) ;
if ( V_151 < 0 )
break;
V_141 = V_166 == - 1 ? NULL : F_102 ( V_166 ) ;
if ( F_70 ( V_141 ) ) {
V_151 = F_71 ( V_141 ) ;
break;
}
if ( V_141 != V_117 -> V_86 ) {
V_142 = V_117 -> V_86 ;
V_117 -> V_86 = V_141 ;
V_146 = V_117 -> V_66 ;
V_117 -> V_66 = V_141 ?
F_103 ( V_141 ) : NULL ;
} else
V_142 = V_141 ;
for ( V_78 = 0 ; V_78 < V_117 -> V_79 ; ++ V_78 ) {
F_87 ( & V_117 -> V_80 [ V_78 ] -> V_85 ) ;
V_117 -> V_80 [ V_78 ] -> V_66 = V_117 -> V_66 ;
F_88 ( & V_117 -> V_80 [ V_78 ] -> V_85 ) ;
}
if ( V_146 )
F_79 ( V_146 ) ;
if ( V_142 )
F_80 ( V_142 ) ;
break;
default:
V_151 = - V_18 ;
break;
}
V_34:
return V_151 ;
}
static const struct V_112 * F_105 ( struct V_100 * V_110 ,
T_10 V_104 , T_11 V_179 )
{
const struct V_112 * V_180 ;
int V_181 = 0 , V_182 = V_110 -> V_102 ;
while ( V_181 < V_182 ) {
int V_183 = V_181 + ( V_182 - V_181 ) / 2 ;
V_180 = V_110 -> V_101 + V_183 ;
if ( V_104 >= V_180 -> V_116 )
V_182 = V_183 ;
else
V_181 = V_183 + 1 ;
}
V_180 = V_110 -> V_101 + V_181 ;
if ( V_104 >= V_180 -> V_116 &&
V_180 -> V_116 + V_180 -> V_115 > V_104 )
return V_180 ;
return NULL ;
}
static int F_106 ( int V_184 , void T_1 * V_104 )
{
unsigned long log = ( unsigned long ) V_104 ;
struct V_185 * V_185 ;
void * V_177 ;
int V_186 = V_184 + ( log % V_187 ) * 8 ;
int V_151 ;
V_151 = F_107 ( log , 1 , 1 , & V_185 ) ;
if ( V_151 < 0 )
return V_151 ;
F_31 ( V_151 != 1 ) ;
V_177 = F_108 ( V_185 ) ;
F_109 ( V_186 , V_177 ) ;
F_110 ( V_177 ) ;
F_111 ( V_185 ) ;
F_112 ( V_185 ) ;
return 0 ;
}
static int F_113 ( void T_1 * V_61 ,
T_8 V_188 , T_8 V_189 )
{
T_8 V_190 = V_188 / V_107 ;
int V_151 ;
if ( ! V_189 )
return 0 ;
V_189 += V_188 % V_107 ;
for (; ; ) {
T_8 V_177 = ( T_8 ) ( unsigned long ) V_61 ;
T_8 log = V_177 + V_190 / 8 ;
int V_186 = V_190 % 8 ;
if ( ( T_8 ) ( unsigned long ) log != log )
return - V_9 ;
V_151 = F_106 ( V_186 , ( void T_1 * ) ( unsigned long ) log ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_189 <= V_107 )
break;
V_189 -= V_107 ;
V_190 += 1 ;
}
return V_151 ;
}
int F_114 ( struct V_1 * V_2 , struct V_191 * log ,
unsigned int V_192 , T_8 V_179 )
{
int V_78 , V_151 ;
F_115 () ;
for ( V_78 = 0 ; V_78 < V_192 ; ++ V_78 ) {
T_8 V_193 = F_116 ( log [ V_78 ] . V_179 , V_179 ) ;
V_151 = F_113 ( V_2 -> V_61 , log [ V_78 ] . V_104 , V_193 ) ;
if ( V_151 < 0 )
return V_151 ;
V_179 -= V_193 ;
if ( ! V_179 ) {
if ( V_2 -> V_66 )
F_117 ( V_2 -> V_66 , 1 ) ;
return 0 ;
}
}
F_118 () ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
void T_1 * V_51 ;
if ( F_120 ( F_121 ( V_2 , V_2 -> V_57 ) , & V_2 -> V_51 -> V_46 ) < 0 )
return - V_9 ;
if ( F_122 ( V_2 -> V_58 ) ) {
F_115 () ;
V_51 = & V_2 -> V_51 -> V_46 ;
F_113 ( V_2 -> V_61 , V_2 -> V_59 +
( V_51 - ( void T_1 * ) V_2 -> V_51 ) ,
sizeof V_2 -> V_51 -> V_46 ) ;
if ( V_2 -> V_66 )
F_117 ( V_2 -> V_66 , 1 ) ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , T_12 V_194 )
{
if ( F_120 ( F_121 ( V_2 , V_2 -> V_53 ) , F_124 ( V_2 ) ) )
return - V_9 ;
if ( F_122 ( V_2 -> V_58 ) ) {
void T_1 * V_51 ;
F_115 () ;
V_51 = F_124 ( V_2 ) ;
F_113 ( V_2 -> V_61 , V_2 -> V_59 +
( V_51 - ( void T_1 * ) V_2 -> V_51 ) ,
sizeof * F_124 ( V_2 ) ) ;
if ( V_2 -> V_66 )
F_117 ( V_2 -> V_66 , 1 ) ;
}
return 0 ;
}
int F_125 ( struct V_1 * V_2 )
{
T_13 V_54 ;
int V_151 ;
bool V_16 = V_2 -> V_16 ;
if ( ! V_2 -> V_7 ) {
F_11 ( V_2 ) ;
return 0 ;
}
F_9 ( V_2 ) ;
V_151 = F_119 ( V_2 ) ;
if ( V_151 )
goto V_95;
V_2 -> V_56 = false ;
if ( ! F_84 ( V_124 , & V_2 -> V_51 -> V_14 , sizeof V_2 -> V_51 -> V_14 ) ) {
V_151 = - V_9 ;
goto V_95;
}
V_151 = F_126 ( V_54 , & V_2 -> V_51 -> V_14 ) ;
if ( V_151 )
goto V_95;
V_2 -> V_54 = F_127 ( V_2 , V_54 ) ;
return 0 ;
V_95:
V_2 -> V_16 = V_16 ;
return V_151 ;
}
static int F_128 ( struct V_1 * V_2 , T_8 V_104 , T_2 V_179 ,
struct V_195 V_196 [] , int V_197 )
{
const struct V_112 * V_180 ;
struct V_100 * V_110 ;
struct V_195 * V_198 ;
T_8 V_6 = 0 ;
int V_40 = 0 ;
V_110 = V_2 -> V_67 ;
while ( ( T_8 ) V_179 > V_6 ) {
T_8 V_130 ;
if ( F_122 ( V_40 >= V_197 ) ) {
V_40 = - V_152 ;
break;
}
V_180 = F_105 ( V_110 , V_104 , V_179 ) ;
if ( F_122 ( ! V_180 ) ) {
V_40 = - V_9 ;
break;
}
V_198 = V_196 + V_40 ;
V_130 = V_180 -> V_115 - V_104 + V_180 -> V_116 ;
V_198 -> V_199 = F_116 ( ( T_8 ) V_179 - V_6 , V_130 ) ;
V_198 -> V_200 = ( void T_1 * ) ( unsigned long )
( V_180 -> V_114 + V_104 - V_180 -> V_116 ) ;
V_6 += V_130 ;
V_104 += V_130 ;
++ V_40 ;
}
return V_40 ;
}
static unsigned F_129 ( struct V_1 * V_2 , struct V_120 * V_49 )
{
unsigned int V_201 ;
if ( ! ( V_49 -> V_46 & F_121 ( V_2 , V_202 ) ) )
return - 1U ;
V_201 = F_127 ( V_2 , V_49 -> V_201 ) ;
F_130 () ;
return V_201 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_195 V_196 [] , unsigned int V_197 ,
unsigned int * V_203 , unsigned int * V_204 ,
struct V_191 * log , unsigned int * V_192 ,
struct V_120 * V_76 )
{
struct V_120 V_49 ;
unsigned int V_78 = 0 , V_205 , V_206 = 0 ;
T_2 V_179 = F_132 ( V_2 , V_76 -> V_179 ) ;
struct V_207 V_208 ;
int V_40 ;
if ( F_122 ( V_179 % sizeof V_49 ) ) {
F_133 ( V_2 , L_2
L_3 ,
( unsigned long long ) V_179 ,
sizeof V_49 ) ;
return - V_13 ;
}
V_40 = F_128 ( V_2 , F_134 ( V_2 , V_76 -> V_104 ) , V_179 , V_2 -> V_76 ,
V_81 ) ;
if ( F_122 ( V_40 < 0 ) ) {
F_133 ( V_2 , L_4 , V_40 ) ;
return V_40 ;
}
F_135 ( & V_208 , V_209 , V_2 -> V_76 , V_40 , V_179 ) ;
F_130 () ;
V_205 = V_179 / sizeof V_49 ;
if ( F_122 ( V_205 > V_210 + 1 ) ) {
F_133 ( V_2 , L_5 ,
V_76 -> V_179 ) ;
return - V_139 ;
}
do {
unsigned V_211 = * V_204 + * V_203 ;
if ( F_122 ( ++ V_206 > V_205 ) ) {
F_133 ( V_2 , L_6
L_7 ,
V_78 , V_205 ) ;
return - V_13 ;
}
if ( F_122 ( F_136 ( & V_49 , sizeof( V_49 ) , & V_208 ) !=
sizeof( V_49 ) ) ) {
F_133 ( V_2 , L_8 ,
V_78 , ( T_9 ) F_134 ( V_2 , V_76 -> V_104 ) + V_78 * sizeof V_49 ) ;
return - V_13 ;
}
if ( F_122 ( V_49 . V_46 & F_121 ( V_2 , V_212 ) ) ) {
F_133 ( V_2 , L_9 ,
V_78 , ( T_9 ) F_134 ( V_2 , V_76 -> V_104 ) + V_78 * sizeof V_49 ) ;
return - V_13 ;
}
V_40 = F_128 ( V_2 , F_134 ( V_2 , V_49 . V_104 ) ,
F_132 ( V_2 , V_49 . V_179 ) , V_196 + V_211 ,
V_197 - V_211 ) ;
if ( F_122 ( V_40 < 0 ) ) {
F_133 ( V_2 , L_10 ,
V_40 , V_78 ) ;
return V_40 ;
}
if ( V_49 . V_46 & F_121 ( V_2 , V_213 ) ) {
* V_204 += V_40 ;
if ( F_122 ( log ) ) {
log [ * V_192 ] . V_104 = F_134 ( V_2 , V_49 . V_104 ) ;
log [ * V_192 ] . V_179 = F_132 ( V_2 , V_49 . V_179 ) ;
++ * V_192 ;
}
} else {
if ( F_122 ( * V_204 ) ) {
F_133 ( V_2 , L_11
L_12 , V_78 ) ;
return - V_13 ;
}
* V_203 += V_40 ;
}
} while ( ( V_78 = F_129 ( V_2 , & V_49 ) ) != - 1 );
return 0 ;
}
int F_137 ( struct V_1 * V_2 ,
struct V_195 V_196 [] , unsigned int V_197 ,
unsigned int * V_203 , unsigned int * V_204 ,
struct V_191 * log , unsigned int * V_192 )
{
struct V_120 V_49 ;
unsigned int V_78 , V_214 , V_206 = 0 ;
T_12 V_52 ;
T_13 V_53 ;
T_13 V_215 ;
int V_40 ;
V_52 = V_2 -> V_52 ;
if ( F_122 ( F_126 ( V_53 , & V_2 -> V_50 -> V_14 ) ) ) {
F_133 ( V_2 , L_13 ,
& V_2 -> V_50 -> V_14 ) ;
return - V_9 ;
}
V_2 -> V_53 = F_127 ( V_2 , V_53 ) ;
if ( F_122 ( ( T_12 ) ( V_2 -> V_53 - V_52 ) > V_2 -> V_10 ) ) {
F_133 ( V_2 , L_14 ,
V_52 , V_2 -> V_53 ) ;
return - V_9 ;
}
if ( V_2 -> V_53 == V_52 )
return V_2 -> V_10 ;
F_138 () ;
if ( F_122 ( F_126 ( V_215 ,
& V_2 -> V_50 -> V_125 [ V_52 & ( V_2 -> V_10 - 1 ) ] ) ) ) {
F_133 ( V_2 , L_15 ,
V_52 ,
& V_2 -> V_50 -> V_125 [ V_52 % V_2 -> V_10 ] ) ;
return - V_9 ;
}
V_214 = F_127 ( V_2 , V_215 ) ;
if ( F_122 ( V_214 >= V_2 -> V_10 ) ) {
F_133 ( V_2 , L_16 ,
V_214 , V_2 -> V_10 ) ;
return - V_13 ;
}
* V_203 = * V_204 = 0 ;
if ( F_122 ( log ) )
* V_192 = 0 ;
V_78 = V_214 ;
do {
unsigned V_211 = * V_204 + * V_203 ;
if ( F_122 ( V_78 >= V_2 -> V_10 ) ) {
F_133 ( V_2 , L_17 ,
V_78 , V_2 -> V_10 , V_214 ) ;
return - V_13 ;
}
if ( F_122 ( ++ V_206 > V_2 -> V_10 ) ) {
F_133 ( V_2 , L_6
L_18 ,
V_78 , V_2 -> V_10 , V_214 ) ;
return - V_13 ;
}
V_40 = F_139 ( & V_49 , V_2 -> V_49 + V_78 , sizeof V_49 ) ;
if ( F_122 ( V_40 ) ) {
F_133 ( V_2 , L_19 ,
V_78 , V_2 -> V_49 + V_78 ) ;
return - V_9 ;
}
if ( V_49 . V_46 & F_121 ( V_2 , V_212 ) ) {
V_40 = F_131 ( V_2 , V_196 , V_197 ,
V_203 , V_204 ,
log , V_192 , & V_49 ) ;
if ( F_122 ( V_40 < 0 ) ) {
F_133 ( V_2 , L_20
L_21 , V_78 ) ;
return V_40 ;
}
continue;
}
V_40 = F_128 ( V_2 , F_134 ( V_2 , V_49 . V_104 ) ,
F_132 ( V_2 , V_49 . V_179 ) , V_196 + V_211 ,
V_197 - V_211 ) ;
if ( F_122 ( V_40 < 0 ) ) {
F_133 ( V_2 , L_22 ,
V_40 , V_78 ) ;
return V_40 ;
}
if ( V_49 . V_46 & F_121 ( V_2 , V_213 ) ) {
* V_204 += V_40 ;
if ( F_122 ( log ) ) {
log [ * V_192 ] . V_104 = F_134 ( V_2 , V_49 . V_104 ) ;
log [ * V_192 ] . V_179 = F_132 ( V_2 , V_49 . V_179 ) ;
++ * V_192 ;
}
} else {
if ( F_122 ( * V_204 ) ) {
F_133 ( V_2 , L_23
L_24 , V_78 ) ;
return - V_13 ;
}
* V_203 += V_40 ;
}
} while ( ( V_78 = F_129 ( V_2 , & V_49 ) ) != - 1 );
V_2 -> V_52 ++ ;
F_31 ( ! ( V_2 -> V_57 & V_216 ) ) ;
return V_214 ;
}
void F_140 ( struct V_1 * V_2 , int V_131 )
{
V_2 -> V_52 -= V_131 ;
}
int F_141 ( struct V_1 * V_2 , unsigned int V_214 , int V_179 )
{
struct V_217 V_77 = {
F_142 ( V_2 , V_214 ) ,
F_142 (vq, len)
} ;
return F_143 ( V_2 , & V_77 , 1 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_217 * V_77 ,
unsigned V_205 )
{
struct V_217 T_1 * V_51 ;
T_12 V_218 , V_219 ;
int V_181 ;
V_181 = V_2 -> V_54 & ( V_2 -> V_10 - 1 ) ;
V_51 = V_2 -> V_51 -> V_125 + V_181 ;
if ( V_205 == 1 ) {
if ( F_120 ( V_77 [ 0 ] . V_220 , & V_51 -> V_220 ) ) {
F_133 ( V_2 , L_25 ) ;
return - V_9 ;
}
if ( F_120 ( V_77 [ 0 ] . V_179 , & V_51 -> V_179 ) ) {
F_133 ( V_2 , L_26 ) ;
return - V_9 ;
}
} else if ( F_145 ( V_51 , V_77 , V_205 * sizeof *V_51 ) ) {
F_133 ( V_2 , L_27 ) ;
return - V_9 ;
}
if ( F_122 ( V_2 -> V_58 ) ) {
F_115 () ;
F_113 ( V_2 -> V_61 ,
V_2 -> V_59 +
( ( void T_1 * ) V_51 - ( void T_1 * ) V_2 -> V_51 ) ,
V_205 * sizeof *V_51 ) ;
}
V_218 = V_2 -> V_54 ;
V_219 = ( V_2 -> V_54 += V_205 ) ;
if ( F_122 ( ( T_12 ) ( V_219 - V_2 -> V_55 ) < ( T_12 ) ( V_219 - V_218 ) ) )
V_2 -> V_56 = false ;
return 0 ;
}
int F_143 ( struct V_1 * V_2 , struct V_217 * V_77 ,
unsigned V_205 )
{
int V_181 , V_131 , V_151 ;
V_181 = V_2 -> V_54 & ( V_2 -> V_10 - 1 ) ;
V_131 = V_2 -> V_10 - V_181 ;
if ( V_131 < V_205 ) {
V_151 = F_144 ( V_2 , V_77 , V_131 ) ;
if ( V_151 < 0 )
return V_151 ;
V_77 += V_131 ;
V_205 -= V_131 ;
}
V_151 = F_144 ( V_2 , V_77 , V_205 ) ;
F_115 () ;
if ( F_120 ( F_121 ( V_2 , V_2 -> V_54 ) , & V_2 -> V_51 -> V_14 ) ) {
F_133 ( V_2 , L_28 ) ;
return - V_9 ;
}
if ( F_122 ( V_2 -> V_58 ) ) {
F_113 ( V_2 -> V_61 ,
V_2 -> V_59 + F_75 ( struct V_122 , V_14 ) ,
sizeof V_2 -> V_51 -> V_14 ) ;
if ( V_2 -> V_66 )
F_117 ( V_2 -> V_66 , 1 ) ;
}
return V_151 ;
}
static bool F_146 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_14 V_218 , V_219 ;
T_13 V_221 ;
bool V_222 ;
F_147 () ;
if ( F_10 ( V_2 , V_223 ) &&
F_122 ( V_2 -> V_53 == V_2 -> V_52 ) )
return true ;
if ( ! F_10 ( V_2 , V_123 ) ) {
T_13 V_46 ;
if ( F_126 ( V_46 , & V_2 -> V_50 -> V_46 ) ) {
F_133 ( V_2 , L_29 ) ;
return true ;
}
return ! ( V_46 & F_121 ( V_2 , V_224 ) ) ;
}
V_218 = V_2 -> V_55 ;
V_222 = V_2 -> V_56 ;
V_219 = V_2 -> V_55 = V_2 -> V_54 ;
V_2 -> V_56 = true ;
if ( F_122 ( ! V_222 ) )
return true ;
if ( F_126 ( V_221 , F_148 ( V_2 ) ) ) {
F_133 ( V_2 , L_30 ) ;
return true ;
}
return F_149 ( F_127 ( V_2 , V_221 ) , V_219 , V_218 ) ;
}
void F_150 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
if ( V_2 -> V_64 && F_146 ( V_39 , V_2 ) )
F_117 ( V_2 -> V_64 , 1 ) ;
}
void F_151 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_214 , int V_179 )
{
F_141 ( V_2 , V_214 , V_179 ) ;
F_150 ( V_39 , V_2 ) ;
}
void F_152 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_217 * V_77 , unsigned V_205 )
{
F_143 ( V_2 , V_77 , V_205 ) ;
F_150 ( V_39 , V_2 ) ;
}
bool F_153 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_53 ;
int V_151 ;
V_151 = F_126 ( V_53 , & V_2 -> V_50 -> V_14 ) ;
if ( V_151 )
return false ;
return F_127 ( V_2 , V_53 ) == V_2 -> V_53 ;
}
bool F_154 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_53 ;
int V_151 ;
if ( ! ( V_2 -> V_57 & V_216 ) )
return false ;
V_2 -> V_57 &= ~ V_216 ;
if ( ! F_10 ( V_2 , V_123 ) ) {
V_151 = F_119 ( V_2 ) ;
if ( V_151 ) {
F_133 ( V_2 , L_31 ,
& V_2 -> V_51 -> V_46 , V_151 ) ;
return false ;
}
} else {
V_151 = F_123 ( V_2 , V_2 -> V_53 ) ;
if ( V_151 ) {
F_133 ( V_2 , L_32 ,
F_124 ( V_2 ) , V_151 ) ;
return false ;
}
}
F_147 () ;
V_151 = F_126 ( V_53 , & V_2 -> V_50 -> V_14 ) ;
if ( V_151 ) {
F_133 ( V_2 , L_33 ,
& V_2 -> V_50 -> V_14 , V_151 ) ;
return false ;
}
return F_127 ( V_2 , V_53 ) != V_2 -> V_53 ;
}
void F_155 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_151 ;
if ( V_2 -> V_57 & V_216 )
return;
V_2 -> V_57 |= V_216 ;
if ( ! F_10 ( V_2 , V_123 ) ) {
V_151 = F_119 ( V_2 ) ;
if ( V_151 )
F_133 ( V_2 , L_31 ,
& V_2 -> V_51 -> V_46 , V_151 ) ;
}
}
static int T_15 F_156 ( void )
{
return 0 ;
}
static void T_16 F_157 ( void )
{
}
