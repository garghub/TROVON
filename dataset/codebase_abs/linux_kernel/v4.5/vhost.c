static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = ! F_2 () ;
}
static long F_3 ( struct V_1 * V_2 , int T_1 * V_4 )
{
struct V_5 V_6 ;
if ( V_2 -> V_7 )
return - V_8 ;
if ( F_4 ( & V_6 , V_4 , sizeof( V_6 ) ) )
return - V_9 ;
if ( V_6 . V_10 != V_11 &&
V_6 . V_10 != V_12 )
return - V_13 ;
V_2 -> V_3 = V_6 . V_10 ;
return 0 ;
}
static long F_5 ( struct V_1 * V_2 , T_2 V_14 ,
int T_1 * V_4 )
{
struct V_5 V_6 = {
. V_15 = V_14 ,
. V_10 = V_2 -> V_3
} ;
if ( F_6 ( V_4 , & V_6 , sizeof( V_6 ) ) )
return - V_9 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_8 ( V_2 , V_17 ) || ! V_2 -> V_3 ;
}
static void F_1 ( struct V_1 * V_2 )
{
}
static long F_3 ( struct V_1 * V_2 , int T_1 * V_4 )
{
return - V_18 ;
}
static long F_5 ( struct V_1 * V_2 , T_2 V_14 ,
int T_1 * V_4 )
{
return - V_18 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 , V_17 ) )
V_2 -> V_16 = true ;
}
static void F_9 ( struct V_19 * V_19 , T_3 * V_20 ,
T_4 * V_21 )
{
struct V_22 * V_23 ;
V_23 = F_10 ( V_21 , struct V_22 , V_24 ) ;
V_23 -> V_20 = V_20 ;
F_11 ( V_20 , & V_23 -> V_25 ) ;
}
static int F_12 ( T_5 * V_25 , unsigned V_26 , int V_27 ,
void * V_28 )
{
struct V_22 * V_23 = F_10 ( V_25 , struct V_22 , V_25 ) ;
if ( ! ( ( unsigned long ) V_28 & V_23 -> V_29 ) )
return 0 ;
F_13 ( V_23 ) ;
return 0 ;
}
void F_14 ( struct V_30 * V_31 , T_6 V_32 )
{
F_15 ( & V_31 -> V_33 ) ;
V_31 -> V_32 = V_32 ;
F_16 ( & V_31 -> V_34 ) ;
V_31 -> V_35 = 0 ;
V_31 -> V_36 = V_31 -> V_37 = 0 ;
}
void F_17 ( struct V_22 * V_23 , T_6 V_32 ,
unsigned long V_29 , struct V_38 * V_39 )
{
F_18 ( & V_23 -> V_25 , F_12 ) ;
F_19 ( & V_23 -> V_24 , F_9 ) ;
V_23 -> V_29 = V_29 ;
V_23 -> V_39 = V_39 ;
V_23 -> V_20 = NULL ;
F_14 ( & V_23 -> V_31 , V_32 ) ;
}
int F_20 ( struct V_22 * V_23 , struct V_19 * V_19 )
{
unsigned long V_29 ;
int V_40 = 0 ;
if ( V_23 -> V_20 )
return 0 ;
V_29 = V_19 -> V_41 -> V_23 ( V_19 , & V_23 -> V_24 ) ;
if ( V_29 )
F_12 ( & V_23 -> V_25 , 0 , 0 , ( void * ) V_29 ) ;
if ( V_29 & V_42 ) {
if ( V_23 -> V_20 )
F_21 ( V_23 -> V_20 , & V_23 -> V_25 ) ;
V_40 = - V_13 ;
}
return V_40 ;
}
void F_22 ( struct V_22 * V_23 )
{
if ( V_23 -> V_20 ) {
F_21 ( V_23 -> V_20 , & V_23 -> V_25 ) ;
V_23 -> V_20 = NULL ;
}
}
static bool F_23 ( struct V_38 * V_39 , struct V_30 * V_31 ,
unsigned V_43 )
{
int V_44 ;
F_24 ( & V_39 -> V_45 ) ;
V_44 = V_43 - V_31 -> V_37 ;
F_25 ( & V_39 -> V_45 ) ;
return V_44 <= 0 ;
}
void F_26 ( struct V_38 * V_39 , struct V_30 * V_31 )
{
unsigned V_43 ;
int V_35 ;
F_24 ( & V_39 -> V_45 ) ;
V_43 = V_31 -> V_36 ;
V_31 -> V_35 ++ ;
F_25 ( & V_39 -> V_45 ) ;
F_27 ( V_31 -> V_34 , F_23 ( V_39 , V_31 , V_43 ) ) ;
F_24 ( & V_39 -> V_45 ) ;
V_35 = -- V_31 -> V_35 ;
F_25 ( & V_39 -> V_45 ) ;
F_28 ( V_35 < 0 ) ;
}
void F_29 ( struct V_22 * V_23 )
{
F_26 ( V_23 -> V_39 , & V_23 -> V_31 ) ;
}
void F_30 ( struct V_38 * V_39 , struct V_30 * V_31 )
{
unsigned long V_46 ;
F_31 ( & V_39 -> V_45 , V_46 ) ;
if ( F_32 ( & V_31 -> V_33 ) ) {
F_33 ( & V_31 -> V_33 , & V_39 -> V_47 ) ;
V_31 -> V_36 ++ ;
F_34 ( & V_39 -> V_45 , V_46 ) ;
F_35 ( V_39 -> V_48 ) ;
} else {
F_34 ( & V_39 -> V_45 , V_46 ) ;
}
}
void F_13 ( struct V_22 * V_23 )
{
F_30 ( V_23 -> V_39 , & V_23 -> V_31 ) ;
}
static void F_36 ( struct V_38 * V_39 ,
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
V_2 -> V_16 = F_2 () ;
F_1 ( V_2 ) ;
}
static int F_37 ( void * V_68 )
{
struct V_38 * V_39 = V_68 ;
struct V_30 * V_31 = NULL ;
unsigned V_69 ( V_43 ) ;
T_7 V_70 = F_38 () ;
F_39 ( V_71 ) ;
F_40 ( V_39 -> V_72 ) ;
for (; ; ) {
F_41 ( V_73 ) ;
F_24 ( & V_39 -> V_45 ) ;
if ( V_31 ) {
V_31 -> V_37 = V_43 ;
if ( V_31 -> V_35 )
F_42 ( & V_31 -> V_34 ) ;
}
if ( F_43 () ) {
F_25 ( & V_39 -> V_45 ) ;
F_44 ( V_74 ) ;
break;
}
if ( ! F_32 ( & V_39 -> V_47 ) ) {
V_31 = F_45 ( & V_39 -> V_47 ,
struct V_30 , V_33 ) ;
F_46 ( & V_31 -> V_33 ) ;
V_43 = V_31 -> V_36 ;
} else
V_31 = NULL ;
F_25 ( & V_39 -> V_45 ) ;
if ( V_31 ) {
F_44 ( V_74 ) ;
V_31 -> V_32 ( V_31 ) ;
if ( F_47 () )
F_48 () ;
} else
F_48 () ;
}
F_49 ( V_39 -> V_72 ) ;
F_39 ( V_70 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
F_51 ( V_2 -> log ) ;
V_2 -> log = NULL ;
F_51 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
static long F_52 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_39 -> V_78 ; ++ V_77 ) {
V_2 = V_39 -> V_79 [ V_77 ] ;
V_2 -> V_75 = F_53 ( sizeof * V_2 -> V_75 * V_80 ,
V_81 ) ;
V_2 -> log = F_53 ( sizeof * V_2 -> log * V_80 , V_81 ) ;
V_2 -> V_76 = F_53 ( sizeof * V_2 -> V_76 * V_80 , V_81 ) ;
if ( ! V_2 -> V_75 || ! V_2 -> log || ! V_2 -> V_76 )
goto V_82;
}
return 0 ;
V_82:
for (; V_77 >= 0 ; -- V_77 )
F_50 ( V_39 -> V_79 [ V_77 ] ) ;
return - V_83 ;
}
static void F_54 ( struct V_38 * V_39 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_39 -> V_78 ; ++ V_77 )
F_50 ( V_39 -> V_79 [ V_77 ] ) ;
}
void F_55 ( struct V_38 * V_39 ,
struct V_1 * * V_79 , int V_78 )
{
struct V_1 * V_2 ;
int V_77 ;
V_39 -> V_79 = V_79 ;
V_39 -> V_78 = V_78 ;
F_56 ( & V_39 -> V_84 ) ;
V_39 -> V_66 = NULL ;
V_39 -> V_85 = NULL ;
V_39 -> V_67 = NULL ;
V_39 -> V_72 = NULL ;
F_57 ( & V_39 -> V_45 ) ;
F_15 ( & V_39 -> V_47 ) ;
V_39 -> V_48 = NULL ;
for ( V_77 = 0 ; V_77 < V_39 -> V_78 ; ++ V_77 ) {
V_2 = V_39 -> V_79 [ V_77 ] ;
V_2 -> log = NULL ;
V_2 -> V_75 = NULL ;
V_2 -> V_76 = NULL ;
V_2 -> V_39 = V_39 ;
F_56 ( & V_2 -> V_84 ) ;
F_36 ( V_39 , V_2 ) ;
if ( V_2 -> V_86 )
F_17 ( & V_2 -> V_23 , V_2 -> V_86 ,
V_87 , V_39 ) ;
}
}
long F_58 ( struct V_38 * V_39 )
{
return V_39 -> V_72 == V_88 -> V_72 ? 0 : - V_89 ;
}
static void F_59 ( struct V_30 * V_31 )
{
struct V_90 * V_6 ;
V_6 = F_10 ( V_31 , struct V_90 , V_31 ) ;
V_6 -> V_40 = F_60 ( V_6 -> V_91 , V_88 ) ;
}
static int F_61 ( struct V_38 * V_39 )
{
struct V_90 V_92 ;
V_92 . V_91 = V_88 ;
F_14 ( & V_92 . V_31 , F_59 ) ;
F_30 ( V_39 , & V_92 . V_31 ) ;
F_26 ( V_39 , & V_92 . V_31 ) ;
return V_92 . V_40 ;
}
bool F_62 ( struct V_38 * V_39 )
{
return V_39 -> V_72 ;
}
long F_63 ( struct V_38 * V_39 )
{
struct V_93 * V_48 ;
int V_94 ;
if ( F_62 ( V_39 ) ) {
V_94 = - V_8 ;
goto V_95;
}
V_39 -> V_72 = F_64 ( V_88 ) ;
V_48 = F_65 ( F_37 , V_39 , L_1 , V_88 -> V_96 ) ;
if ( F_66 ( V_48 ) ) {
V_94 = F_67 ( V_48 ) ;
goto V_97;
}
V_39 -> V_48 = V_48 ;
F_35 ( V_48 ) ;
V_94 = F_61 ( V_39 ) ;
if ( V_94 )
goto V_98;
V_94 = F_52 ( V_39 ) ;
if ( V_94 )
goto V_98;
return 0 ;
V_98:
F_68 ( V_48 ) ;
V_39 -> V_48 = NULL ;
V_97:
if ( V_39 -> V_72 )
F_69 ( V_39 -> V_72 ) ;
V_39 -> V_72 = NULL ;
V_95:
return V_94 ;
}
struct V_99 * F_70 ( void )
{
return F_53 ( F_71 ( struct V_99 , V_100 ) , V_81 ) ;
}
void F_72 ( struct V_38 * V_39 , struct V_99 * V_67 )
{
int V_77 ;
F_73 ( V_39 , true ) ;
V_67 -> V_101 = 0 ;
V_39 -> V_67 = V_67 ;
for ( V_77 = 0 ; V_77 < V_39 -> V_78 ; ++ V_77 )
V_39 -> V_79 [ V_77 ] -> V_67 = V_67 ;
}
void F_74 ( struct V_38 * V_39 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_39 -> V_78 ; ++ V_77 ) {
if ( V_39 -> V_79 [ V_77 ] -> V_63 && V_39 -> V_79 [ V_77 ] -> V_86 ) {
F_22 ( & V_39 -> V_79 [ V_77 ] -> V_23 ) ;
F_29 ( & V_39 -> V_79 [ V_77 ] -> V_23 ) ;
}
}
}
void F_73 ( struct V_38 * V_39 , bool V_102 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_39 -> V_78 ; ++ V_77 ) {
if ( V_39 -> V_79 [ V_77 ] -> V_62 )
F_75 ( V_39 -> V_79 [ V_77 ] -> V_62 ) ;
if ( V_39 -> V_79 [ V_77 ] -> error )
F_76 ( V_39 -> V_79 [ V_77 ] -> error ) ;
if ( V_39 -> V_79 [ V_77 ] -> V_63 )
F_76 ( V_39 -> V_79 [ V_77 ] -> V_63 ) ;
if ( V_39 -> V_79 [ V_77 ] -> V_64 )
F_75 ( V_39 -> V_79 [ V_77 ] -> V_64 ) ;
if ( V_39 -> V_79 [ V_77 ] -> V_65 )
F_76 ( V_39 -> V_79 [ V_77 ] -> V_65 ) ;
F_36 ( V_39 , V_39 -> V_79 [ V_77 ] ) ;
}
F_54 ( V_39 ) ;
if ( V_39 -> V_66 )
F_75 ( V_39 -> V_66 ) ;
V_39 -> V_66 = NULL ;
if ( V_39 -> V_85 )
F_76 ( V_39 -> V_85 ) ;
V_39 -> V_85 = NULL ;
F_77 ( V_39 -> V_67 ) ;
V_39 -> V_67 = NULL ;
F_78 ( ! F_32 ( & V_39 -> V_47 ) ) ;
if ( V_39 -> V_48 ) {
F_68 ( V_39 -> V_48 ) ;
V_39 -> V_48 = NULL ;
}
if ( V_39 -> V_72 )
F_69 ( V_39 -> V_72 ) ;
V_39 -> V_72 = NULL ;
}
static int F_79 ( void T_1 * V_61 , T_8 V_103 , unsigned long V_104 )
{
T_8 V_105 = V_103 / V_106 / 8 ;
if ( V_105 > V_107 - ( unsigned long ) V_61 ||
V_105 + ( unsigned long ) V_61 > V_107 )
return 0 ;
return F_80 ( V_108 , V_61 + V_105 ,
( V_104 + V_106 * 8 - 1 ) / V_106 / 8 ) ;
}
static int F_81 ( void T_1 * V_61 , struct V_99 * V_109 ,
int V_110 )
{
int V_77 ;
if ( ! V_109 )
return 0 ;
for ( V_77 = 0 ; V_77 < V_109 -> V_101 ; ++ V_77 ) {
struct V_111 * V_112 = V_109 -> V_100 + V_77 ;
unsigned long V_105 = V_112 -> V_113 ;
if ( V_112 -> V_114 > V_107 )
return 0 ;
else if ( ! F_80 ( V_108 , ( void T_1 * ) V_105 ,
V_112 -> V_114 ) )
return 0 ;
else if ( V_110 && ! F_79 ( V_61 ,
V_112 -> V_115 ,
V_112 -> V_114 ) )
return 0 ;
}
return 1 ;
}
static int F_82 ( struct V_38 * V_116 , struct V_99 * V_109 ,
int V_110 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_116 -> V_78 ; ++ V_77 ) {
int V_117 ;
bool log ;
F_83 ( & V_116 -> V_79 [ V_77 ] -> V_84 ) ;
log = V_110 || F_8 ( V_116 -> V_79 [ V_77 ] , V_118 ) ;
if ( V_116 -> V_79 [ V_77 ] -> V_7 )
V_117 = F_81 ( V_116 -> V_79 [ V_77 ] -> V_61 , V_109 , log ) ;
else
V_117 = 1 ;
F_84 ( & V_116 -> V_79 [ V_77 ] -> V_84 ) ;
if ( ! V_117 )
return 0 ;
}
return 1 ;
}
static int F_85 ( struct V_1 * V_2 , unsigned int V_10 ,
struct V_119 T_1 * V_49 ,
struct V_120 T_1 * V_50 ,
struct V_121 T_1 * V_51 )
{
T_9 V_6 = F_8 ( V_2 , V_122 ) ? 2 : 0 ;
return F_80 ( V_123 , V_49 , V_10 * sizeof *V_49 ) &&
F_80 ( V_123 , V_50 ,
sizeof *V_50 + V_10 * sizeof * V_50 -> V_124 + V_6 ) &&
F_80 ( V_108 , V_51 ,
sizeof *V_51 + V_10 * sizeof * V_51 -> V_124 + V_6 ) ;
}
int F_86 ( struct V_38 * V_39 )
{
return F_82 ( V_39 , V_39 -> V_67 , 1 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
void T_1 * V_61 )
{
T_9 V_6 = F_8 ( V_2 , V_122 ) ? 2 : 0 ;
return F_81 ( V_61 , V_2 -> V_67 ,
F_8 ( V_2 , V_118 ) ) &&
( ! V_2 -> V_58 || F_79 ( V_61 , V_2 -> V_59 ,
sizeof * V_2 -> V_51 +
V_2 -> V_10 * sizeof * V_2 -> V_51 -> V_124 + V_6 ) ) ;
}
int F_88 ( struct V_1 * V_2 )
{
return F_85 ( V_2 , V_2 -> V_10 , V_2 -> V_49 , V_2 -> V_50 , V_2 -> V_51 ) &&
F_87 ( V_2 , V_2 -> V_61 ) ;
}
static int F_89 ( const void * V_125 , const void * V_126 )
{
const struct V_111 * V_127 = V_125 , * V_128 = V_126 ;
if ( V_127 -> V_115 < V_128 -> V_115 )
return 1 ;
if ( V_127 -> V_115 > V_128 -> V_115 )
return - 1 ;
return 0 ;
}
static void * F_90 ( unsigned long V_129 )
{
void * V_130 = F_91 ( V_129 , V_81 | V_131 | V_132 ) ;
if ( ! V_130 )
V_130 = F_92 ( V_129 ) ;
return V_130 ;
}
static long F_93 ( struct V_38 * V_116 , struct V_99 T_1 * V_112 )
{
struct V_99 V_109 , * V_133 , * V_134 ;
unsigned long V_129 = F_71 ( struct V_99 , V_100 ) ;
int V_77 ;
if ( F_4 ( & V_109 , V_112 , V_129 ) )
return - V_9 ;
if ( V_109 . V_135 )
return - V_136 ;
if ( V_109 . V_101 > V_137 )
return - V_138 ;
V_133 = F_90 ( V_129 + V_109 . V_101 * sizeof( * V_112 -> V_100 ) ) ;
if ( ! V_133 )
return - V_83 ;
memcpy ( V_133 , & V_109 , V_129 ) ;
if ( F_4 ( V_133 -> V_100 , V_112 -> V_100 ,
V_109 . V_101 * sizeof * V_112 -> V_100 ) ) {
F_77 ( V_133 ) ;
return - V_9 ;
}
F_94 ( V_133 -> V_100 , V_133 -> V_101 , sizeof( * V_133 -> V_100 ) ,
F_89 , NULL ) ;
if ( ! F_82 ( V_116 , V_133 , 0 ) ) {
F_77 ( V_133 ) ;
return - V_9 ;
}
V_134 = V_116 -> V_67 ;
V_116 -> V_67 = V_133 ;
for ( V_77 = 0 ; V_77 < V_116 -> V_78 ; ++ V_77 ) {
F_83 ( & V_116 -> V_79 [ V_77 ] -> V_84 ) ;
V_116 -> V_79 [ V_77 ] -> V_67 = V_133 ;
F_84 ( & V_116 -> V_79 [ V_77 ] -> V_84 ) ;
}
F_77 ( V_134 ) ;
return 0 ;
}
long F_95 ( struct V_38 * V_116 , int V_139 , void T_1 * V_4 )
{
struct V_19 * V_140 , * V_141 = NULL ;
bool V_142 = false , V_143 = false ;
struct V_144 * V_145 = NULL ;
T_2 T_1 * V_146 = V_4 ;
struct V_1 * V_2 ;
struct V_5 V_6 ;
struct V_147 V_148 ;
struct V_149 V_105 ;
T_2 V_14 ;
long V_150 ;
V_150 = F_96 ( V_14 , V_146 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_14 >= V_116 -> V_78 )
return - V_151 ;
V_2 = V_116 -> V_79 [ V_14 ] ;
F_83 ( & V_2 -> V_84 ) ;
switch ( V_139 ) {
case V_152 :
if ( V_2 -> V_7 ) {
V_150 = - V_8 ;
break;
}
if ( F_4 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_150 = - V_9 ;
break;
}
if ( ! V_6 . V_10 || V_6 . V_10 > 0xffff || ( V_6 . V_10 & ( V_6 . V_10 - 1 ) ) ) {
V_150 = - V_13 ;
break;
}
V_2 -> V_10 = V_6 . V_10 ;
break;
case V_153 :
if ( V_2 -> V_7 ) {
V_150 = - V_8 ;
break;
}
if ( F_4 ( & V_6 , V_4 , sizeof V_6 ) ) {
V_150 = - V_9 ;
break;
}
if ( V_6 . V_10 > 0xffff ) {
V_150 = - V_13 ;
break;
}
V_2 -> V_52 = V_6 . V_10 ;
V_2 -> V_53 = V_2 -> V_52 ;
break;
case V_154 :
V_6 . V_15 = V_14 ;
V_6 . V_10 = V_2 -> V_52 ;
if ( F_6 ( V_4 , & V_6 , sizeof V_6 ) )
V_150 = - V_9 ;
break;
case V_155 :
if ( F_4 ( & V_105 , V_4 , sizeof V_105 ) ) {
V_150 = - V_9 ;
break;
}
if ( V_105 . V_46 & ~ ( 0x1 << V_156 ) ) {
V_150 = - V_136 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_105 . V_157 != V_105 . V_157 ||
( T_8 ) ( unsigned long ) V_105 . V_158 != V_105 . V_158 ||
( T_8 ) ( unsigned long ) V_105 . V_159 != V_105 . V_159 ) {
V_150 = - V_9 ;
break;
}
F_97 ( V_160 * V_2 -> V_50 > V_161 ) ;
F_97 ( V_160 * V_2 -> V_51 > V_162 ) ;
if ( ( V_105 . V_159 & ( V_161 - 1 ) ) ||
( V_105 . V_158 & ( V_162 - 1 ) ) ||
( V_105 . V_163 & ( V_162 - 1 ) ) ) {
V_150 = - V_13 ;
break;
}
if ( V_2 -> V_7 ) {
if ( ! F_85 ( V_2 , V_2 -> V_10 ,
( void T_1 * ) ( unsigned long ) V_105 . V_157 ,
( void T_1 * ) ( unsigned long ) V_105 . V_159 ,
( void T_1 * ) ( unsigned long ) V_105 . V_158 ) ) {
V_150 = - V_13 ;
break;
}
if ( ( V_105 . V_46 & ( 0x1 << V_156 ) ) &&
! F_79 ( V_2 -> V_61 , V_105 . V_163 ,
sizeof * V_2 -> V_51 +
V_2 -> V_10 * sizeof * V_2 -> V_51 -> V_124 ) ) {
V_150 = - V_13 ;
break;
}
}
V_2 -> V_58 = ! ! ( V_105 . V_46 & ( 0x1 << V_156 ) ) ;
V_2 -> V_49 = ( void T_1 * ) ( unsigned long ) V_105 . V_157 ;
V_2 -> V_50 = ( void T_1 * ) ( unsigned long ) V_105 . V_159 ;
V_2 -> V_59 = V_105 . V_163 ;
V_2 -> V_51 = ( void T_1 * ) ( unsigned long ) V_105 . V_158 ;
break;
case V_164 :
if ( F_4 ( & V_148 , V_4 , sizeof V_148 ) ) {
V_150 = - V_9 ;
break;
}
V_140 = V_148 . V_165 == - 1 ? NULL : F_98 ( V_148 . V_165 ) ;
if ( F_66 ( V_140 ) ) {
V_150 = F_67 ( V_140 ) ;
break;
}
if ( V_140 != V_2 -> V_63 ) {
V_143 = ( V_141 = V_2 -> V_63 ) != NULL ;
V_142 = ( V_2 -> V_63 = V_140 ) != NULL ;
} else
V_141 = V_140 ;
break;
case V_166 :
if ( F_4 ( & V_148 , V_4 , sizeof V_148 ) ) {
V_150 = - V_9 ;
break;
}
V_140 = V_148 . V_165 == - 1 ? NULL : F_98 ( V_148 . V_165 ) ;
if ( F_66 ( V_140 ) ) {
V_150 = F_67 ( V_140 ) ;
break;
}
if ( V_140 != V_2 -> V_65 ) {
V_141 = V_2 -> V_65 ;
V_145 = V_2 -> V_64 ;
V_2 -> V_65 = V_140 ;
V_2 -> V_64 = V_140 ?
F_99 ( V_140 ) : NULL ;
} else
V_141 = V_140 ;
break;
case V_167 :
if ( F_4 ( & V_148 , V_4 , sizeof V_148 ) ) {
V_150 = - V_9 ;
break;
}
V_140 = V_148 . V_165 == - 1 ? NULL : F_98 ( V_148 . V_165 ) ;
if ( F_66 ( V_140 ) ) {
V_150 = F_67 ( V_140 ) ;
break;
}
if ( V_140 != V_2 -> error ) {
V_141 = V_2 -> error ;
V_2 -> error = V_140 ;
V_145 = V_2 -> V_62 ;
V_2 -> V_62 = V_140 ?
F_99 ( V_140 ) : NULL ;
} else
V_141 = V_140 ;
break;
case V_168 :
V_150 = F_3 ( V_2 , V_4 ) ;
break;
case V_169 :
V_150 = F_5 ( V_2 , V_14 , V_4 ) ;
break;
default:
V_150 = - V_18 ;
}
if ( V_143 && V_2 -> V_86 )
F_22 ( & V_2 -> V_23 ) ;
if ( V_145 )
F_75 ( V_145 ) ;
if ( V_141 )
F_76 ( V_141 ) ;
if ( V_142 && V_2 -> V_86 )
V_150 = F_20 ( & V_2 -> V_23 , V_2 -> V_63 ) ;
F_84 ( & V_2 -> V_84 ) ;
if ( V_143 && V_2 -> V_86 )
F_29 ( & V_2 -> V_23 ) ;
return V_150 ;
}
long F_100 ( struct V_38 * V_116 , unsigned int V_139 , void T_1 * V_4 )
{
struct V_19 * V_140 , * V_141 = NULL ;
struct V_144 * V_145 = NULL ;
T_8 V_170 ;
long V_150 ;
int V_77 , V_165 ;
if ( V_139 == V_171 ) {
V_150 = F_63 ( V_116 ) ;
goto V_34;
}
V_150 = F_58 ( V_116 ) ;
if ( V_150 )
goto V_34;
switch ( V_139 ) {
case V_172 :
V_150 = F_93 ( V_116 , V_4 ) ;
break;
case V_173 :
if ( F_4 ( & V_170 , V_4 , sizeof V_170 ) ) {
V_150 = - V_9 ;
break;
}
if ( ( T_8 ) ( unsigned long ) V_170 != V_170 ) {
V_150 = - V_9 ;
break;
}
for ( V_77 = 0 ; V_77 < V_116 -> V_78 ; ++ V_77 ) {
struct V_1 * V_2 ;
void T_1 * V_174 = ( void T_1 * ) ( unsigned long ) V_170 ;
V_2 = V_116 -> V_79 [ V_77 ] ;
F_83 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_7 && ! F_87 ( V_2 , V_174 ) )
V_150 = - V_9 ;
else
V_2 -> V_61 = V_174 ;
F_84 ( & V_2 -> V_84 ) ;
}
break;
case V_175 :
V_150 = F_96 ( V_165 , ( int T_1 * ) V_4 ) ;
if ( V_150 < 0 )
break;
V_140 = V_165 == - 1 ? NULL : F_98 ( V_165 ) ;
if ( F_66 ( V_140 ) ) {
V_150 = F_67 ( V_140 ) ;
break;
}
if ( V_140 != V_116 -> V_85 ) {
V_141 = V_116 -> V_85 ;
V_116 -> V_85 = V_140 ;
V_145 = V_116 -> V_66 ;
V_116 -> V_66 = V_140 ?
F_99 ( V_140 ) : NULL ;
} else
V_141 = V_140 ;
for ( V_77 = 0 ; V_77 < V_116 -> V_78 ; ++ V_77 ) {
F_83 ( & V_116 -> V_79 [ V_77 ] -> V_84 ) ;
V_116 -> V_79 [ V_77 ] -> V_66 = V_116 -> V_66 ;
F_84 ( & V_116 -> V_79 [ V_77 ] -> V_84 ) ;
}
if ( V_145 )
F_75 ( V_145 ) ;
if ( V_141 )
F_76 ( V_141 ) ;
break;
default:
V_150 = - V_18 ;
break;
}
V_34:
return V_150 ;
}
static const struct V_111 * F_101 ( struct V_99 * V_109 ,
T_10 V_103 , T_11 V_176 )
{
const struct V_111 * V_177 ;
int V_178 = 0 , V_179 = V_109 -> V_101 ;
while ( V_178 < V_179 ) {
int V_180 = V_178 + ( V_179 - V_178 ) / 2 ;
V_177 = V_109 -> V_100 + V_180 ;
if ( V_103 >= V_177 -> V_115 )
V_179 = V_180 ;
else
V_178 = V_180 + 1 ;
}
V_177 = V_109 -> V_100 + V_178 ;
if ( V_103 >= V_177 -> V_115 &&
V_177 -> V_115 + V_177 -> V_114 > V_103 )
return V_177 ;
return NULL ;
}
static int F_102 ( int V_181 , void T_1 * V_103 )
{
unsigned long log = ( unsigned long ) V_103 ;
struct V_182 * V_182 ;
void * V_174 ;
int V_183 = V_181 + ( log % V_184 ) * 8 ;
int V_150 ;
V_150 = F_103 ( log , 1 , 1 , & V_182 ) ;
if ( V_150 < 0 )
return V_150 ;
F_28 ( V_150 != 1 ) ;
V_174 = F_104 ( V_182 ) ;
F_105 ( V_183 , V_174 ) ;
F_106 ( V_174 ) ;
F_107 ( V_182 ) ;
F_108 ( V_182 ) ;
return 0 ;
}
static int F_109 ( void T_1 * V_61 ,
T_8 V_185 , T_8 V_186 )
{
T_8 V_187 = V_185 / V_106 ;
int V_150 ;
if ( ! V_186 )
return 0 ;
V_186 += V_185 % V_106 ;
for (; ; ) {
T_8 V_174 = ( T_8 ) ( unsigned long ) V_61 ;
T_8 log = V_174 + V_187 / 8 ;
int V_183 = V_187 % 8 ;
if ( ( T_8 ) ( unsigned long ) log != log )
return - V_9 ;
V_150 = F_102 ( V_183 , ( void T_1 * ) ( unsigned long ) log ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_186 <= V_106 )
break;
V_186 -= V_106 ;
V_187 += 1 ;
}
return V_150 ;
}
int F_110 ( struct V_1 * V_2 , struct V_188 * log ,
unsigned int V_189 , T_8 V_176 )
{
int V_77 , V_150 ;
F_111 () ;
for ( V_77 = 0 ; V_77 < V_189 ; ++ V_77 ) {
T_8 V_190 = F_112 ( log [ V_77 ] . V_176 , V_176 ) ;
V_150 = F_109 ( V_2 -> V_61 , log [ V_77 ] . V_103 , V_190 ) ;
if ( V_150 < 0 )
return V_150 ;
V_176 -= V_190 ;
if ( ! V_176 ) {
if ( V_2 -> V_66 )
F_113 ( V_2 -> V_66 , 1 ) ;
return 0 ;
}
}
F_114 () ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
void T_1 * V_51 ;
if ( F_116 ( F_117 ( V_2 , V_2 -> V_57 ) , & V_2 -> V_51 -> V_46 ) < 0 )
return - V_9 ;
if ( F_118 ( V_2 -> V_58 ) ) {
F_111 () ;
V_51 = & V_2 -> V_51 -> V_46 ;
F_109 ( V_2 -> V_61 , V_2 -> V_59 +
( V_51 - ( void T_1 * ) V_2 -> V_51 ) ,
sizeof V_2 -> V_51 -> V_46 ) ;
if ( V_2 -> V_66 )
F_113 ( V_2 -> V_66 , 1 ) ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , T_12 V_191 )
{
if ( F_116 ( F_117 ( V_2 , V_2 -> V_53 ) , F_120 ( V_2 ) ) )
return - V_9 ;
if ( F_118 ( V_2 -> V_58 ) ) {
void T_1 * V_51 ;
F_111 () ;
V_51 = F_120 ( V_2 ) ;
F_109 ( V_2 -> V_61 , V_2 -> V_59 +
( V_51 - ( void T_1 * ) V_2 -> V_51 ) ,
sizeof * F_120 ( V_2 ) ) ;
if ( V_2 -> V_66 )
F_113 ( V_2 -> V_66 , 1 ) ;
}
return 0 ;
}
int F_121 ( struct V_1 * V_2 )
{
T_13 V_54 ;
int V_150 ;
bool V_16 = V_2 -> V_16 ;
if ( ! V_2 -> V_7 ) {
V_2 -> V_16 = F_2 () ;
return 0 ;
}
F_7 ( V_2 ) ;
V_150 = F_115 ( V_2 ) ;
if ( V_150 )
goto V_94;
V_2 -> V_56 = false ;
if ( ! F_80 ( V_123 , & V_2 -> V_51 -> V_14 , sizeof V_2 -> V_51 -> V_14 ) ) {
V_150 = - V_9 ;
goto V_94;
}
V_150 = F_122 ( V_54 , & V_2 -> V_51 -> V_14 ) ;
if ( V_150 )
goto V_94;
V_2 -> V_54 = F_123 ( V_2 , V_54 ) ;
return 0 ;
V_94:
V_2 -> V_16 = V_16 ;
return V_150 ;
}
static int F_124 ( struct V_1 * V_2 , T_8 V_103 , T_2 V_176 ,
struct V_192 V_193 [] , int V_194 )
{
const struct V_111 * V_177 ;
struct V_99 * V_109 ;
struct V_192 * V_195 ;
T_8 V_6 = 0 ;
int V_40 = 0 ;
V_109 = V_2 -> V_67 ;
while ( ( T_8 ) V_176 > V_6 ) {
T_8 V_129 ;
if ( F_118 ( V_40 >= V_194 ) ) {
V_40 = - V_151 ;
break;
}
V_177 = F_101 ( V_109 , V_103 , V_176 ) ;
if ( F_118 ( ! V_177 ) ) {
V_40 = - V_9 ;
break;
}
V_195 = V_193 + V_40 ;
V_129 = V_177 -> V_114 - V_103 + V_177 -> V_115 ;
V_195 -> V_196 = F_112 ( ( T_8 ) V_176 - V_6 , V_129 ) ;
V_195 -> V_197 = ( void T_1 * ) ( unsigned long )
( V_177 -> V_113 + V_103 - V_177 -> V_115 ) ;
V_6 += V_129 ;
V_103 += V_129 ;
++ V_40 ;
}
return V_40 ;
}
static unsigned F_125 ( struct V_1 * V_2 , struct V_119 * V_49 )
{
unsigned int V_198 ;
if ( ! ( V_49 -> V_46 & F_117 ( V_2 , V_199 ) ) )
return - 1U ;
V_198 = F_123 ( V_2 , V_49 -> V_198 ) ;
F_126 () ;
return V_198 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_192 V_193 [] , unsigned int V_194 ,
unsigned int * V_200 , unsigned int * V_201 ,
struct V_188 * log , unsigned int * V_189 ,
struct V_119 * V_75 )
{
struct V_119 V_49 ;
unsigned int V_77 = 0 , V_202 , V_203 = 0 ;
T_2 V_176 = F_128 ( V_2 , V_75 -> V_176 ) ;
struct V_204 V_205 ;
int V_40 ;
if ( F_118 ( V_176 % sizeof V_49 ) ) {
F_129 ( V_2 , L_2
L_3 ,
( unsigned long long ) V_176 ,
sizeof V_49 ) ;
return - V_13 ;
}
V_40 = F_124 ( V_2 , F_130 ( V_2 , V_75 -> V_103 ) , V_176 , V_2 -> V_75 ,
V_80 ) ;
if ( F_118 ( V_40 < 0 ) ) {
F_129 ( V_2 , L_4 , V_40 ) ;
return V_40 ;
}
F_131 ( & V_205 , V_206 , V_2 -> V_75 , V_40 , V_176 ) ;
F_126 () ;
V_202 = V_176 / sizeof V_49 ;
if ( F_118 ( V_202 > V_207 + 1 ) ) {
F_129 ( V_2 , L_5 ,
V_75 -> V_176 ) ;
return - V_138 ;
}
do {
unsigned V_208 = * V_201 + * V_200 ;
if ( F_118 ( ++ V_203 > V_202 ) ) {
F_129 ( V_2 , L_6
L_7 ,
V_77 , V_202 ) ;
return - V_13 ;
}
if ( F_118 ( F_132 ( & V_49 , sizeof( V_49 ) , & V_205 ) !=
sizeof( V_49 ) ) ) {
F_129 ( V_2 , L_8 ,
V_77 , ( T_9 ) F_130 ( V_2 , V_75 -> V_103 ) + V_77 * sizeof V_49 ) ;
return - V_13 ;
}
if ( F_118 ( V_49 . V_46 & F_117 ( V_2 , V_209 ) ) ) {
F_129 ( V_2 , L_9 ,
V_77 , ( T_9 ) F_130 ( V_2 , V_75 -> V_103 ) + V_77 * sizeof V_49 ) ;
return - V_13 ;
}
V_40 = F_124 ( V_2 , F_130 ( V_2 , V_49 . V_103 ) ,
F_128 ( V_2 , V_49 . V_176 ) , V_193 + V_208 ,
V_194 - V_208 ) ;
if ( F_118 ( V_40 < 0 ) ) {
F_129 ( V_2 , L_10 ,
V_40 , V_77 ) ;
return V_40 ;
}
if ( V_49 . V_46 & F_117 ( V_2 , V_210 ) ) {
* V_201 += V_40 ;
if ( F_118 ( log ) ) {
log [ * V_189 ] . V_103 = F_130 ( V_2 , V_49 . V_103 ) ;
log [ * V_189 ] . V_176 = F_128 ( V_2 , V_49 . V_176 ) ;
++ * V_189 ;
}
} else {
if ( F_118 ( * V_201 ) ) {
F_129 ( V_2 , L_11
L_12 , V_77 ) ;
return - V_13 ;
}
* V_200 += V_40 ;
}
} while ( ( V_77 = F_125 ( V_2 , & V_49 ) ) != - 1 );
return 0 ;
}
int F_133 ( struct V_1 * V_2 ,
struct V_192 V_193 [] , unsigned int V_194 ,
unsigned int * V_200 , unsigned int * V_201 ,
struct V_188 * log , unsigned int * V_189 )
{
struct V_119 V_49 ;
unsigned int V_77 , V_211 , V_203 = 0 ;
T_12 V_52 ;
T_13 V_53 ;
T_13 V_212 ;
int V_40 ;
V_52 = V_2 -> V_52 ;
if ( F_118 ( F_122 ( V_53 , & V_2 -> V_50 -> V_14 ) ) ) {
F_129 ( V_2 , L_13 ,
& V_2 -> V_50 -> V_14 ) ;
return - V_9 ;
}
V_2 -> V_53 = F_123 ( V_2 , V_53 ) ;
if ( F_118 ( ( T_12 ) ( V_2 -> V_53 - V_52 ) > V_2 -> V_10 ) ) {
F_129 ( V_2 , L_14 ,
V_52 , V_2 -> V_53 ) ;
return - V_9 ;
}
if ( V_2 -> V_53 == V_52 )
return V_2 -> V_10 ;
F_134 () ;
if ( F_118 ( F_122 ( V_212 ,
& V_2 -> V_50 -> V_124 [ V_52 & ( V_2 -> V_10 - 1 ) ] ) ) ) {
F_129 ( V_2 , L_15 ,
V_52 ,
& V_2 -> V_50 -> V_124 [ V_52 % V_2 -> V_10 ] ) ;
return - V_9 ;
}
V_211 = F_123 ( V_2 , V_212 ) ;
if ( F_118 ( V_211 >= V_2 -> V_10 ) ) {
F_129 ( V_2 , L_16 ,
V_211 , V_2 -> V_10 ) ;
return - V_13 ;
}
* V_200 = * V_201 = 0 ;
if ( F_118 ( log ) )
* V_189 = 0 ;
V_77 = V_211 ;
do {
unsigned V_208 = * V_201 + * V_200 ;
if ( F_118 ( V_77 >= V_2 -> V_10 ) ) {
F_129 ( V_2 , L_17 ,
V_77 , V_2 -> V_10 , V_211 ) ;
return - V_13 ;
}
if ( F_118 ( ++ V_203 > V_2 -> V_10 ) ) {
F_129 ( V_2 , L_6
L_18 ,
V_77 , V_2 -> V_10 , V_211 ) ;
return - V_13 ;
}
V_40 = F_135 ( & V_49 , V_2 -> V_49 + V_77 , sizeof V_49 ) ;
if ( F_118 ( V_40 ) ) {
F_129 ( V_2 , L_19 ,
V_77 , V_2 -> V_49 + V_77 ) ;
return - V_9 ;
}
if ( V_49 . V_46 & F_117 ( V_2 , V_209 ) ) {
V_40 = F_127 ( V_2 , V_193 , V_194 ,
V_200 , V_201 ,
log , V_189 , & V_49 ) ;
if ( F_118 ( V_40 < 0 ) ) {
F_129 ( V_2 , L_20
L_21 , V_77 ) ;
return V_40 ;
}
continue;
}
V_40 = F_124 ( V_2 , F_130 ( V_2 , V_49 . V_103 ) ,
F_128 ( V_2 , V_49 . V_176 ) , V_193 + V_208 ,
V_194 - V_208 ) ;
if ( F_118 ( V_40 < 0 ) ) {
F_129 ( V_2 , L_22 ,
V_40 , V_77 ) ;
return V_40 ;
}
if ( V_49 . V_46 & F_117 ( V_2 , V_210 ) ) {
* V_201 += V_40 ;
if ( F_118 ( log ) ) {
log [ * V_189 ] . V_103 = F_130 ( V_2 , V_49 . V_103 ) ;
log [ * V_189 ] . V_176 = F_128 ( V_2 , V_49 . V_176 ) ;
++ * V_189 ;
}
} else {
if ( F_118 ( * V_201 ) ) {
F_129 ( V_2 , L_23
L_24 , V_77 ) ;
return - V_13 ;
}
* V_200 += V_40 ;
}
} while ( ( V_77 = F_125 ( V_2 , & V_49 ) ) != - 1 );
V_2 -> V_52 ++ ;
F_28 ( ! ( V_2 -> V_57 & V_213 ) ) ;
return V_211 ;
}
void F_136 ( struct V_1 * V_2 , int V_130 )
{
V_2 -> V_52 -= V_130 ;
}
int F_137 ( struct V_1 * V_2 , unsigned int V_211 , int V_176 )
{
struct V_214 V_76 = {
F_138 ( V_2 , V_211 ) ,
F_138 (vq, len)
} ;
return F_139 ( V_2 , & V_76 , 1 ) ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_214 * V_76 ,
unsigned V_202 )
{
struct V_214 T_1 * V_51 ;
T_12 V_215 , V_216 ;
int V_178 ;
V_178 = V_2 -> V_54 & ( V_2 -> V_10 - 1 ) ;
V_51 = V_2 -> V_51 -> V_124 + V_178 ;
if ( V_202 == 1 ) {
if ( F_116 ( V_76 [ 0 ] . V_217 , & V_51 -> V_217 ) ) {
F_129 ( V_2 , L_25 ) ;
return - V_9 ;
}
if ( F_116 ( V_76 [ 0 ] . V_176 , & V_51 -> V_176 ) ) {
F_129 ( V_2 , L_26 ) ;
return - V_9 ;
}
} else if ( F_141 ( V_51 , V_76 , V_202 * sizeof *V_51 ) ) {
F_129 ( V_2 , L_27 ) ;
return - V_9 ;
}
if ( F_118 ( V_2 -> V_58 ) ) {
F_111 () ;
F_109 ( V_2 -> V_61 ,
V_2 -> V_59 +
( ( void T_1 * ) V_51 - ( void T_1 * ) V_2 -> V_51 ) ,
V_202 * sizeof *V_51 ) ;
}
V_215 = V_2 -> V_54 ;
V_216 = ( V_2 -> V_54 += V_202 ) ;
if ( F_118 ( ( T_12 ) ( V_216 - V_2 -> V_55 ) < ( T_12 ) ( V_216 - V_215 ) ) )
V_2 -> V_56 = false ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 , struct V_214 * V_76 ,
unsigned V_202 )
{
int V_178 , V_130 , V_150 ;
V_178 = V_2 -> V_54 & ( V_2 -> V_10 - 1 ) ;
V_130 = V_2 -> V_10 - V_178 ;
if ( V_130 < V_202 ) {
V_150 = F_140 ( V_2 , V_76 , V_130 ) ;
if ( V_150 < 0 )
return V_150 ;
V_76 += V_130 ;
V_202 -= V_130 ;
}
V_150 = F_140 ( V_2 , V_76 , V_202 ) ;
F_111 () ;
if ( F_116 ( F_117 ( V_2 , V_2 -> V_54 ) , & V_2 -> V_51 -> V_14 ) ) {
F_129 ( V_2 , L_28 ) ;
return - V_9 ;
}
if ( F_118 ( V_2 -> V_58 ) ) {
F_109 ( V_2 -> V_61 ,
V_2 -> V_59 + F_71 ( struct V_121 , V_14 ) ,
sizeof V_2 -> V_51 -> V_14 ) ;
if ( V_2 -> V_66 )
F_113 ( V_2 -> V_66 , 1 ) ;
}
return V_150 ;
}
static bool F_142 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_14 V_215 , V_216 ;
T_13 V_218 ;
bool V_219 ;
F_143 () ;
if ( F_8 ( V_2 , V_220 ) &&
F_118 ( V_2 -> V_53 == V_2 -> V_52 ) )
return true ;
if ( ! F_8 ( V_2 , V_122 ) ) {
T_13 V_46 ;
if ( F_122 ( V_46 , & V_2 -> V_50 -> V_46 ) ) {
F_129 ( V_2 , L_29 ) ;
return true ;
}
return ! ( V_46 & F_117 ( V_2 , V_221 ) ) ;
}
V_215 = V_2 -> V_55 ;
V_219 = V_2 -> V_56 ;
V_216 = V_2 -> V_55 = V_2 -> V_54 ;
V_2 -> V_56 = true ;
if ( F_118 ( ! V_219 ) )
return true ;
if ( F_122 ( V_218 , F_144 ( V_2 ) ) ) {
F_129 ( V_2 , L_30 ) ;
return true ;
}
return F_145 ( F_123 ( V_2 , V_218 ) , V_216 , V_215 ) ;
}
void F_146 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
if ( V_2 -> V_64 && F_142 ( V_39 , V_2 ) )
F_113 ( V_2 -> V_64 , 1 ) ;
}
void F_147 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
unsigned int V_211 , int V_176 )
{
F_137 ( V_2 , V_211 , V_176 ) ;
F_146 ( V_39 , V_2 ) ;
}
void F_148 ( struct V_38 * V_39 ,
struct V_1 * V_2 ,
struct V_214 * V_76 , unsigned V_202 )
{
F_139 ( V_2 , V_76 , V_202 ) ;
F_146 ( V_39 , V_2 ) ;
}
bool F_149 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
T_13 V_53 ;
int V_150 ;
if ( ! ( V_2 -> V_57 & V_213 ) )
return false ;
V_2 -> V_57 &= ~ V_213 ;
if ( ! F_8 ( V_2 , V_122 ) ) {
V_150 = F_115 ( V_2 ) ;
if ( V_150 ) {
F_129 ( V_2 , L_31 ,
& V_2 -> V_51 -> V_46 , V_150 ) ;
return false ;
}
} else {
V_150 = F_119 ( V_2 , V_2 -> V_53 ) ;
if ( V_150 ) {
F_129 ( V_2 , L_32 ,
F_120 ( V_2 ) , V_150 ) ;
return false ;
}
}
F_143 () ;
V_150 = F_122 ( V_53 , & V_2 -> V_50 -> V_14 ) ;
if ( V_150 ) {
F_129 ( V_2 , L_33 ,
& V_2 -> V_50 -> V_14 , V_150 ) ;
return false ;
}
return F_123 ( V_2 , V_53 ) != V_2 -> V_53 ;
}
void F_150 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_150 ;
if ( V_2 -> V_57 & V_213 )
return;
V_2 -> V_57 |= V_213 ;
if ( ! F_8 ( V_2 , V_122 ) ) {
V_150 = F_115 ( V_2 ) ;
if ( V_150 )
F_129 ( V_2 , L_31 ,
& V_2 -> V_51 -> V_46 , V_150 ) ;
}
}
static int T_15 F_151 ( void )
{
return 0 ;
}
static void T_16 F_152 ( void )
{
}
