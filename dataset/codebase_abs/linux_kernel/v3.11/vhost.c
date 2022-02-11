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
if ( V_5 -> V_2 )
return 0 ;
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
void F_18 ( struct V_20 * V_21 , struct V_12 * V_13 )
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
V_33 -> V_46 = NULL ;
V_33 -> V_47 = NULL ;
V_33 -> V_48 = NULL ;
V_33 -> error = NULL ;
V_33 -> V_49 = NULL ;
V_33 -> V_50 = NULL ;
V_33 -> V_51 = NULL ;
V_33 -> V_52 = NULL ;
}
static int F_29 ( void * V_53 )
{
struct V_20 * V_21 = V_53 ;
struct V_12 * V_13 = NULL ;
unsigned V_54 ( V_26 ) ;
T_5 V_55 = F_30 () ;
F_31 ( V_56 ) ;
F_32 ( V_21 -> V_57 ) ;
for (; ; ) {
F_33 ( V_58 ) ;
F_16 ( & V_21 -> V_28 ) ;
if ( V_13 ) {
V_13 -> V_19 = V_26 ;
if ( V_13 -> V_17 )
F_34 ( & V_13 -> V_16 ) ;
}
if ( F_35 () ) {
F_17 ( & V_21 -> V_28 ) ;
F_36 ( V_59 ) ;
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
F_36 ( V_59 ) ;
V_13 -> V_14 ( V_13 ) ;
if ( F_39 () )
F_40 () ;
} else
F_40 () ;
}
F_41 ( V_21 -> V_57 ) ;
F_31 ( V_55 ) ;
return 0 ;
}
static void F_42 ( struct V_32 * V_33 )
{
F_43 ( V_33 -> V_60 ) ;
V_33 -> V_60 = NULL ;
F_43 ( V_33 -> log ) ;
V_33 -> log = NULL ;
F_43 ( V_33 -> V_61 ) ;
V_33 -> V_61 = NULL ;
}
static long F_44 ( struct V_20 * V_21 )
{
struct V_32 * V_33 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_21 -> V_63 ; ++ V_62 ) {
V_33 = V_21 -> V_64 [ V_62 ] ;
V_33 -> V_60 = F_45 ( sizeof * V_33 -> V_60 * V_65 ,
V_66 ) ;
V_33 -> log = F_45 ( sizeof * V_33 -> log * V_65 , V_66 ) ;
V_33 -> V_61 = F_45 ( sizeof * V_33 -> V_61 * V_65 , V_66 ) ;
if ( ! V_33 -> V_60 || ! V_33 -> log || ! V_33 -> V_61 )
goto V_67;
}
return 0 ;
V_67:
for (; V_62 >= 0 ; -- V_62 )
F_42 ( V_21 -> V_64 [ V_62 ] ) ;
return - V_68 ;
}
static void F_46 ( struct V_20 * V_21 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_21 -> V_63 ; ++ V_62 )
F_42 ( V_21 -> V_64 [ V_62 ] ) ;
}
long F_47 ( struct V_20 * V_21 ,
struct V_32 * * V_64 , int V_63 )
{
struct V_32 * V_33 ;
int V_62 ;
V_21 -> V_64 = V_64 ;
V_21 -> V_63 = V_63 ;
F_48 ( & V_21 -> V_69 ) ;
V_21 -> V_52 = NULL ;
V_21 -> V_70 = NULL ;
V_21 -> V_71 = NULL ;
V_21 -> V_57 = NULL ;
F_49 ( & V_21 -> V_28 ) ;
F_7 ( & V_21 -> V_30 ) ;
V_21 -> V_31 = NULL ;
for ( V_62 = 0 ; V_62 < V_21 -> V_63 ; ++ V_62 ) {
V_33 = V_21 -> V_64 [ V_62 ] ;
V_33 -> log = NULL ;
V_33 -> V_60 = NULL ;
V_33 -> V_61 = NULL ;
V_33 -> V_21 = V_21 ;
F_48 ( & V_33 -> V_69 ) ;
F_28 ( V_21 , V_33 ) ;
if ( V_33 -> V_72 )
F_9 ( & V_33 -> V_5 , V_33 -> V_72 ,
V_73 , V_21 ) ;
}
return 0 ;
}
long F_50 ( struct V_20 * V_21 )
{
return V_21 -> V_57 == V_74 -> V_57 ? 0 : - V_75 ;
}
static void F_51 ( struct V_12 * V_13 )
{
struct V_76 * V_77 ;
V_77 = F_2 ( V_13 , struct V_76 , V_13 ) ;
V_77 -> V_22 = F_52 ( V_77 -> V_78 , V_74 ) ;
}
static int F_53 ( struct V_20 * V_21 )
{
struct V_76 V_79 ;
V_79 . V_78 = V_74 ;
F_6 ( & V_79 . V_13 , F_51 ) ;
F_22 ( V_21 , & V_79 . V_13 ) ;
F_18 ( V_21 , & V_79 . V_13 ) ;
return V_79 . V_22 ;
}
bool F_54 ( struct V_20 * V_21 )
{
return V_21 -> V_57 ;
}
long F_55 ( struct V_20 * V_21 )
{
struct V_80 * V_31 ;
int V_81 ;
if ( F_54 ( V_21 ) ) {
V_81 = - V_82 ;
goto V_83;
}
V_21 -> V_57 = F_56 ( V_74 ) ;
V_31 = F_57 ( F_29 , V_21 , L_1 , V_74 -> V_84 ) ;
if ( F_58 ( V_31 ) ) {
V_81 = F_59 ( V_31 ) ;
goto V_85;
}
V_21 -> V_31 = V_31 ;
F_26 ( V_31 ) ;
V_81 = F_53 ( V_21 ) ;
if ( V_81 )
goto V_86;
V_81 = F_44 ( V_21 ) ;
if ( V_81 )
goto V_86;
return 0 ;
V_86:
F_60 ( V_31 ) ;
V_21 -> V_31 = NULL ;
V_85:
if ( V_21 -> V_57 )
F_61 ( V_21 -> V_57 ) ;
V_21 -> V_57 = NULL ;
V_83:
return V_81 ;
}
struct V_87 * F_62 ( void )
{
return F_45 ( F_63 ( struct V_87 , V_88 ) , V_66 ) ;
}
void F_64 ( struct V_20 * V_21 , struct V_87 * V_71 )
{
F_65 ( V_21 , true ) ;
V_71 -> V_89 = 0 ;
F_66 ( V_21 -> V_71 , V_71 ) ;
}
void F_67 ( struct V_20 * V_21 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_21 -> V_63 ; ++ V_62 ) {
if ( V_21 -> V_64 [ V_62 ] -> V_49 && V_21 -> V_64 [ V_62 ] -> V_72 ) {
F_14 ( & V_21 -> V_64 [ V_62 ] -> V_5 ) ;
F_21 ( & V_21 -> V_64 [ V_62 ] -> V_5 ) ;
}
}
}
void F_65 ( struct V_20 * V_21 , bool V_90 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_21 -> V_63 ; ++ V_62 ) {
if ( V_21 -> V_64 [ V_62 ] -> V_48 )
F_68 ( V_21 -> V_64 [ V_62 ] -> V_48 ) ;
if ( V_21 -> V_64 [ V_62 ] -> error )
F_69 ( V_21 -> V_64 [ V_62 ] -> error ) ;
if ( V_21 -> V_64 [ V_62 ] -> V_49 )
F_69 ( V_21 -> V_64 [ V_62 ] -> V_49 ) ;
if ( V_21 -> V_64 [ V_62 ] -> V_50 )
F_68 ( V_21 -> V_64 [ V_62 ] -> V_50 ) ;
if ( V_21 -> V_64 [ V_62 ] -> V_51 )
F_69 ( V_21 -> V_64 [ V_62 ] -> V_51 ) ;
F_28 ( V_21 , V_21 -> V_64 [ V_62 ] ) ;
}
F_46 ( V_21 ) ;
if ( V_21 -> V_52 )
F_68 ( V_21 -> V_52 ) ;
V_21 -> V_52 = NULL ;
if ( V_21 -> V_70 )
F_69 ( V_21 -> V_70 ) ;
V_21 -> V_70 = NULL ;
F_43 ( F_70 ( V_21 -> V_71 ,
V_90 ==
F_71 ( & V_21 -> V_69 ) ) ) ;
F_66 ( V_21 -> V_71 , NULL ) ;
F_72 ( ! F_24 ( & V_21 -> V_30 ) ) ;
if ( V_21 -> V_31 ) {
F_60 ( V_21 -> V_31 ) ;
V_21 -> V_31 = NULL ;
}
if ( V_21 -> V_57 )
F_61 ( V_21 -> V_57 ) ;
V_21 -> V_57 = NULL ;
}
static int F_73 ( void T_6 * V_47 , T_7 V_91 , unsigned long V_92 )
{
T_7 V_93 = V_91 / V_94 / 8 ;
if ( V_93 > V_95 - ( unsigned long ) V_47 ||
V_93 + ( unsigned long ) V_47 > V_95 )
return 0 ;
return F_74 ( V_96 , V_47 + V_93 ,
( V_92 + V_94 * 8 - 1 ) / V_94 / 8 ) ;
}
static int F_75 ( void T_6 * V_47 , struct V_87 * V_97 ,
int V_98 )
{
int V_62 ;
if ( ! V_97 )
return 0 ;
for ( V_62 = 0 ; V_62 < V_97 -> V_89 ; ++ V_62 ) {
struct V_99 * V_100 = V_97 -> V_88 + V_62 ;
unsigned long V_93 = V_100 -> V_101 ;
if ( V_100 -> V_102 > V_95 )
return 0 ;
else if ( ! F_74 ( V_96 , ( void T_6 * ) V_93 ,
V_100 -> V_102 ) )
return 0 ;
else if ( V_98 && ! F_73 ( V_47 ,
V_100 -> V_103 ,
V_100 -> V_102 ) )
return 0 ;
}
return 1 ;
}
static int F_76 ( struct V_20 * V_104 , struct V_87 * V_97 ,
int V_98 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_104 -> V_63 ; ++ V_62 ) {
int V_105 ;
F_77 ( & V_104 -> V_64 [ V_62 ] -> V_69 ) ;
if ( V_104 -> V_64 [ V_62 ] -> V_46 )
V_105 = F_75 ( V_104 -> V_64 [ V_62 ] -> V_47 , V_97 ,
V_98 ) ;
else
V_105 = 1 ;
F_78 ( & V_104 -> V_64 [ V_62 ] -> V_69 ) ;
if ( ! V_105 )
return 0 ;
}
return 1 ;
}
static int F_79 ( struct V_20 * V_104 , unsigned int V_34 ,
struct V_106 T_6 * V_35 ,
struct V_107 T_6 * V_36 ,
struct V_108 T_6 * V_37 )
{
T_8 V_77 = F_80 ( V_104 , V_109 ) ? 2 : 0 ;
return F_74 ( V_110 , V_35 , V_34 * sizeof *V_35 ) &&
F_74 ( V_110 , V_36 ,
sizeof *V_36 + V_34 * sizeof * V_36 -> V_111 + V_77 ) &&
F_74 ( V_96 , V_37 ,
sizeof *V_37 + V_34 * sizeof * V_37 -> V_111 + V_77 ) ;
}
int F_81 ( struct V_20 * V_21 )
{
struct V_87 * V_112 ;
V_112 = F_70 ( V_21 -> V_71 ,
F_71 ( & V_21 -> V_69 ) ) ;
return F_76 ( V_21 , V_112 , 1 ) ;
}
static int F_82 ( struct V_20 * V_104 , struct V_32 * V_33 ,
void T_6 * V_47 )
{
struct V_87 * V_112 ;
T_8 V_77 = F_80 ( V_104 , V_109 ) ? 2 : 0 ;
V_112 = F_70 ( V_33 -> V_21 -> V_71 ,
F_71 ( & V_33 -> V_69 ) ) ;
return F_75 ( V_47 , V_112 ,
F_80 ( V_33 -> V_21 , V_113 ) ) &&
( ! V_33 -> V_44 || F_73 ( V_47 , V_33 -> V_45 ,
sizeof * V_33 -> V_37 +
V_33 -> V_34 * sizeof * V_33 -> V_37 -> V_111 + V_77 ) ) ;
}
int F_83 ( struct V_32 * V_33 )
{
return F_79 ( V_33 -> V_21 , V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) &&
F_82 ( V_33 -> V_21 , V_33 , V_33 -> V_47 ) ;
}
static long F_84 ( struct V_20 * V_104 , struct V_87 T_6 * V_100 )
{
struct V_87 V_97 , * V_114 , * V_115 ;
unsigned long V_116 = F_63 ( struct V_87 , V_88 ) ;
if ( F_85 ( & V_97 , V_100 , V_116 ) )
return - V_117 ;
if ( V_97 . V_118 )
return - V_119 ;
if ( V_97 . V_89 > V_120 )
return - V_121 ;
V_114 = F_45 ( V_116 + V_97 . V_89 * sizeof * V_100 -> V_88 , V_66 ) ;
if ( ! V_114 )
return - V_68 ;
memcpy ( V_114 , & V_97 , V_116 ) ;
if ( F_85 ( V_114 -> V_88 , V_100 -> V_88 ,
V_97 . V_89 * sizeof * V_100 -> V_88 ) ) {
F_43 ( V_114 ) ;
return - V_117 ;
}
if ( ! F_76 ( V_104 , V_114 ,
F_80 ( V_104 , V_113 ) ) ) {
F_43 ( V_114 ) ;
return - V_117 ;
}
V_115 = F_70 ( V_104 -> V_71 ,
F_71 ( & V_104 -> V_69 ) ) ;
F_86 ( V_104 -> V_71 , V_114 ) ;
F_87 () ;
F_43 ( V_115 ) ;
return 0 ;
}
long F_88 ( struct V_20 * V_104 , int V_122 , void T_6 * V_123 )
{
struct V_1 * V_124 , * V_125 = NULL ;
bool V_126 = false , V_127 = false ;
struct V_128 * V_129 = NULL ;
T_9 T_6 * V_130 = V_123 ;
struct V_32 * V_33 ;
struct V_131 V_77 ;
struct V_132 V_133 ;
struct V_134 V_93 ;
T_9 V_135 ;
long V_136 ;
V_136 = F_89 ( V_135 , V_130 ) ;
if ( V_136 < 0 )
return V_136 ;
if ( V_135 >= V_104 -> V_63 )
return - V_137 ;
V_33 = V_104 -> V_64 [ V_135 ] ;
F_77 ( & V_33 -> V_69 ) ;
switch ( V_122 ) {
case V_138 :
if ( V_33 -> V_46 ) {
V_136 = - V_82 ;
break;
}
if ( F_85 ( & V_77 , V_123 , sizeof V_77 ) ) {
V_136 = - V_117 ;
break;
}
if ( ! V_77 . V_34 || V_77 . V_34 > 0xffff || ( V_77 . V_34 & ( V_77 . V_34 - 1 ) ) ) {
V_136 = - V_25 ;
break;
}
V_33 -> V_34 = V_77 . V_34 ;
break;
case V_139 :
if ( V_33 -> V_46 ) {
V_136 = - V_82 ;
break;
}
if ( F_85 ( & V_77 , V_123 , sizeof V_77 ) ) {
V_136 = - V_117 ;
break;
}
if ( V_77 . V_34 > 0xffff ) {
V_136 = - V_25 ;
break;
}
V_33 -> V_38 = V_77 . V_34 ;
V_33 -> V_39 = V_33 -> V_38 ;
break;
case V_140 :
V_77 . V_141 = V_135 ;
V_77 . V_34 = V_33 -> V_38 ;
if ( F_90 ( V_123 , & V_77 , sizeof V_77 ) )
V_136 = - V_117 ;
break;
case V_142 :
if ( F_85 ( & V_93 , V_123 , sizeof V_93 ) ) {
V_136 = - V_117 ;
break;
}
if ( V_93 . V_29 & ~ ( 0x1 << V_143 ) ) {
V_136 = - V_119 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_93 . V_144 != V_93 . V_144 ||
( T_7 ) ( unsigned long ) V_93 . V_145 != V_93 . V_145 ||
( T_7 ) ( unsigned long ) V_93 . V_146 != V_93 . V_146 ) {
V_136 = - V_117 ;
break;
}
if ( ( V_93 . V_146 & ( sizeof * V_33 -> V_36 -> V_111 - 1 ) ) ||
( V_93 . V_145 & ( sizeof * V_33 -> V_37 -> V_111 - 1 ) ) ||
( V_93 . V_147 & ( sizeof * V_33 -> V_37 -> V_111 - 1 ) ) ) {
V_136 = - V_25 ;
break;
}
if ( V_33 -> V_46 ) {
if ( ! F_79 ( V_104 , V_33 -> V_34 ,
( void T_6 * ) ( unsigned long ) V_93 . V_144 ,
( void T_6 * ) ( unsigned long ) V_93 . V_146 ,
( void T_6 * ) ( unsigned long ) V_93 . V_145 ) ) {
V_136 = - V_25 ;
break;
}
if ( ( V_93 . V_29 & ( 0x1 << V_143 ) ) &&
! F_73 ( V_33 -> V_47 , V_93 . V_147 ,
sizeof * V_33 -> V_37 +
V_33 -> V_34 * sizeof * V_33 -> V_37 -> V_111 ) ) {
V_136 = - V_25 ;
break;
}
}
V_33 -> V_44 = ! ! ( V_93 . V_29 & ( 0x1 << V_143 ) ) ;
V_33 -> V_35 = ( void T_6 * ) ( unsigned long ) V_93 . V_144 ;
V_33 -> V_36 = ( void T_6 * ) ( unsigned long ) V_93 . V_146 ;
V_33 -> V_45 = V_93 . V_147 ;
V_33 -> V_37 = ( void T_6 * ) ( unsigned long ) V_93 . V_145 ;
break;
case V_148 :
if ( F_85 ( & V_133 , V_123 , sizeof V_133 ) ) {
V_136 = - V_117 ;
break;
}
V_124 = V_133 . V_149 == - 1 ? NULL : F_91 ( V_133 . V_149 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_33 -> V_49 ) {
V_127 = ( V_125 = V_33 -> V_49 ) != NULL ;
V_126 = ( V_33 -> V_49 = V_124 ) != NULL ;
} else
V_125 = V_124 ;
break;
case V_150 :
if ( F_85 ( & V_133 , V_123 , sizeof V_133 ) ) {
V_136 = - V_117 ;
break;
}
V_124 = V_133 . V_149 == - 1 ? NULL : F_91 ( V_133 . V_149 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_33 -> V_51 ) {
V_125 = V_33 -> V_51 ;
V_129 = V_33 -> V_50 ;
V_33 -> V_51 = V_124 ;
V_33 -> V_50 = V_124 ?
F_92 ( V_124 ) : NULL ;
} else
V_125 = V_124 ;
break;
case V_151 :
if ( F_85 ( & V_133 , V_123 , sizeof V_133 ) ) {
V_136 = - V_117 ;
break;
}
V_124 = V_133 . V_149 == - 1 ? NULL : F_91 ( V_133 . V_149 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_33 -> error ) {
V_125 = V_33 -> error ;
V_33 -> error = V_124 ;
V_129 = V_33 -> V_48 ;
V_33 -> V_48 = V_124 ?
F_92 ( V_124 ) : NULL ;
} else
V_125 = V_124 ;
break;
default:
V_136 = - V_152 ;
}
if ( V_127 && V_33 -> V_72 )
F_14 ( & V_33 -> V_5 ) ;
if ( V_129 )
F_68 ( V_129 ) ;
if ( V_125 )
F_69 ( V_125 ) ;
if ( V_126 && V_33 -> V_72 )
V_136 = F_12 ( & V_33 -> V_5 , V_33 -> V_49 ) ;
F_78 ( & V_33 -> V_69 ) ;
if ( V_127 && V_33 -> V_72 )
F_21 ( & V_33 -> V_5 ) ;
return V_136 ;
}
long F_93 ( struct V_20 * V_104 , unsigned int V_122 , void T_6 * V_123 )
{
struct V_1 * V_124 , * V_125 = NULL ;
struct V_128 * V_129 = NULL ;
T_7 V_153 ;
long V_136 ;
int V_62 , V_149 ;
if ( V_122 == V_154 ) {
V_136 = F_55 ( V_104 ) ;
goto V_16;
}
V_136 = F_50 ( V_104 ) ;
if ( V_136 )
goto V_16;
switch ( V_122 ) {
case V_155 :
V_136 = F_84 ( V_104 , V_123 ) ;
break;
case V_156 :
if ( F_85 ( & V_153 , V_123 , sizeof V_153 ) ) {
V_136 = - V_117 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_153 != V_153 ) {
V_136 = - V_117 ;
break;
}
for ( V_62 = 0 ; V_62 < V_104 -> V_63 ; ++ V_62 ) {
struct V_32 * V_33 ;
void T_6 * V_157 = ( void T_6 * ) ( unsigned long ) V_153 ;
V_33 = V_104 -> V_64 [ V_62 ] ;
F_77 ( & V_33 -> V_69 ) ;
if ( V_33 -> V_46 && ! F_82 ( V_104 , V_33 , V_157 ) )
V_136 = - V_117 ;
else
V_33 -> V_47 = V_157 ;
F_78 ( & V_33 -> V_69 ) ;
}
break;
case V_158 :
V_136 = F_89 ( V_149 , ( int T_6 * ) V_123 ) ;
if ( V_136 < 0 )
break;
V_124 = V_149 == - 1 ? NULL : F_91 ( V_149 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_104 -> V_70 ) {
V_125 = V_104 -> V_70 ;
V_129 = V_104 -> V_52 ;
V_104 -> V_52 = V_124 ?
F_92 ( V_124 ) : NULL ;
} else
V_125 = V_124 ;
for ( V_62 = 0 ; V_62 < V_104 -> V_63 ; ++ V_62 ) {
F_77 ( & V_104 -> V_64 [ V_62 ] -> V_69 ) ;
V_104 -> V_64 [ V_62 ] -> V_52 = V_104 -> V_52 ;
F_78 ( & V_104 -> V_64 [ V_62 ] -> V_69 ) ;
}
if ( V_129 )
F_68 ( V_129 ) ;
if ( V_125 )
F_69 ( V_125 ) ;
break;
default:
V_136 = - V_152 ;
break;
}
V_16:
return V_136 ;
}
static const struct V_99 * F_94 ( struct V_87 * V_97 ,
T_10 V_91 , T_11 V_159 )
{
struct V_99 * V_160 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_97 -> V_89 ; ++ V_62 ) {
V_160 = V_97 -> V_88 + V_62 ;
if ( V_160 -> V_103 <= V_91 &&
V_160 -> V_103 + V_160 -> V_102 - 1 >= V_91 )
return V_160 ;
}
return NULL ;
}
static int F_95 ( int V_161 , void T_6 * V_91 )
{
unsigned long log = ( unsigned long ) V_91 ;
struct V_162 * V_162 ;
void * V_157 ;
int V_163 = V_161 + ( log % V_164 ) * 8 ;
int V_136 ;
V_136 = F_96 ( log , 1 , 1 , & V_162 ) ;
if ( V_136 < 0 )
return V_136 ;
F_20 ( V_136 != 1 ) ;
V_157 = F_97 ( V_162 ) ;
F_98 ( V_163 , V_157 ) ;
F_99 ( V_157 ) ;
F_100 ( V_162 ) ;
F_101 ( V_162 ) ;
return 0 ;
}
static int F_102 ( void T_6 * V_47 ,
T_7 V_165 , T_7 V_166 )
{
T_7 V_167 = V_165 / V_94 ;
int V_136 ;
if ( ! V_166 )
return 0 ;
V_166 += V_165 % V_94 ;
for (; ; ) {
T_7 V_157 = ( T_7 ) ( unsigned long ) V_47 ;
T_7 log = V_157 + V_167 / 8 ;
int V_163 = V_167 % 8 ;
if ( ( T_7 ) ( unsigned long ) log != log )
return - V_117 ;
V_136 = F_95 ( V_163 , ( void T_6 * ) ( unsigned long ) log ) ;
if ( V_136 < 0 )
return V_136 ;
if ( V_166 <= V_94 )
break;
V_166 -= V_94 ;
V_167 += 1 ;
}
return V_136 ;
}
int F_103 ( struct V_32 * V_33 , struct V_168 * log ,
unsigned int V_169 , T_7 V_159 )
{
int V_62 , V_136 ;
F_104 () ;
for ( V_62 = 0 ; V_62 < V_169 ; ++ V_62 ) {
T_7 V_170 = F_105 ( log [ V_62 ] . V_159 , V_159 ) ;
V_136 = F_102 ( V_33 -> V_47 , log [ V_62 ] . V_91 , V_170 ) ;
if ( V_136 < 0 )
return V_136 ;
V_159 -= V_170 ;
if ( ! V_159 ) {
if ( V_33 -> V_52 )
F_106 ( V_33 -> V_52 , 1 ) ;
return 0 ;
}
}
F_107 () ;
return 0 ;
}
static int F_108 ( struct V_32 * V_33 )
{
void T_6 * V_37 ;
if ( F_109 ( V_33 -> V_43 , & V_33 -> V_37 -> V_29 ) < 0 )
return - V_117 ;
if ( F_110 ( V_33 -> V_44 ) ) {
F_104 () ;
V_37 = & V_33 -> V_37 -> V_29 ;
F_102 ( V_33 -> V_47 , V_33 -> V_45 +
( V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof V_33 -> V_37 -> V_29 ) ;
if ( V_33 -> V_52 )
F_106 ( V_33 -> V_52 , 1 ) ;
}
return 0 ;
}
static int F_111 ( struct V_32 * V_33 , T_12 V_171 )
{
if ( F_109 ( V_33 -> V_39 , F_112 ( V_33 ) ) )
return - V_117 ;
if ( F_110 ( V_33 -> V_44 ) ) {
void T_6 * V_37 ;
F_104 () ;
V_37 = F_112 ( V_33 ) ;
F_102 ( V_33 -> V_47 , V_33 -> V_45 +
( V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof * F_112 ( V_33 ) ) ;
if ( V_33 -> V_52 )
F_106 ( V_33 -> V_52 , 1 ) ;
}
return 0 ;
}
int F_113 ( struct V_32 * V_33 )
{
int V_136 ;
if ( ! V_33 -> V_46 )
return 0 ;
V_136 = F_108 ( V_33 ) ;
if ( V_136 )
return V_136 ;
V_33 -> V_42 = false ;
return F_89 ( V_33 -> V_40 , & V_33 -> V_37 -> V_135 ) ;
}
static int F_114 ( struct V_20 * V_21 , T_7 V_91 , T_9 V_159 ,
struct V_172 V_173 [] , int V_174 )
{
const struct V_99 * V_160 ;
struct V_87 * V_97 ;
struct V_172 * V_175 ;
T_7 V_77 = 0 ;
int V_22 = 0 ;
F_115 () ;
V_97 = F_116 ( V_21 -> V_71 ) ;
while ( ( T_7 ) V_159 > V_77 ) {
T_7 V_116 ;
if ( F_110 ( V_22 >= V_174 ) ) {
V_22 = - V_137 ;
break;
}
V_160 = F_94 ( V_97 , V_91 , V_159 ) ;
if ( F_110 ( ! V_160 ) ) {
V_22 = - V_117 ;
break;
}
V_175 = V_173 + V_22 ;
V_116 = V_160 -> V_102 - V_91 + V_160 -> V_103 ;
V_175 -> V_176 = F_105 ( ( T_7 ) V_159 - V_77 , V_116 ) ;
V_175 -> V_177 = ( void T_6 * ) ( unsigned long )
( V_160 -> V_101 + V_91 - V_160 -> V_103 ) ;
V_77 += V_116 ;
V_91 += V_116 ;
++ V_22 ;
}
F_117 () ;
return V_22 ;
}
static unsigned F_118 ( struct V_106 * V_35 )
{
unsigned int V_178 ;
if ( ! ( V_35 -> V_29 & V_179 ) )
return - 1U ;
V_178 = V_35 -> V_178 ;
F_119 () ;
return V_178 ;
}
static int F_120 ( struct V_20 * V_21 , struct V_32 * V_33 ,
struct V_172 V_173 [] , unsigned int V_174 ,
unsigned int * V_180 , unsigned int * V_181 ,
struct V_168 * log , unsigned int * V_169 ,
struct V_106 * V_60 )
{
struct V_106 V_35 ;
unsigned int V_62 = 0 , V_182 , V_183 = 0 ;
int V_22 ;
if ( F_110 ( V_60 -> V_159 % sizeof V_35 ) ) {
F_121 ( V_33 , L_2
L_3 ,
( unsigned long long ) V_60 -> V_159 ,
sizeof V_35 ) ;
return - V_25 ;
}
V_22 = F_114 ( V_21 , V_60 -> V_91 , V_60 -> V_159 , V_33 -> V_60 ,
V_65 ) ;
if ( F_110 ( V_22 < 0 ) ) {
F_121 ( V_33 , L_4 , V_22 ) ;
return V_22 ;
}
F_119 () ;
V_182 = V_60 -> V_159 / sizeof V_35 ;
if ( F_110 ( V_182 > V_184 + 1 ) ) {
F_121 ( V_33 , L_5 ,
V_60 -> V_159 ) ;
return - V_121 ;
}
do {
unsigned V_185 = * V_181 + * V_180 ;
if ( F_110 ( ++ V_183 > V_182 ) ) {
F_121 ( V_33 , L_6
L_7 ,
V_62 , V_182 ) ;
return - V_25 ;
}
if ( F_110 ( F_122 ( ( unsigned char * ) & V_35 ,
V_33 -> V_60 , sizeof V_35 ) ) ) {
F_121 ( V_33 , L_8 ,
V_62 , ( T_8 ) V_60 -> V_91 + V_62 * sizeof V_35 ) ;
return - V_25 ;
}
if ( F_110 ( V_35 . V_29 & V_186 ) ) {
F_121 ( V_33 , L_9 ,
V_62 , ( T_8 ) V_60 -> V_91 + V_62 * sizeof V_35 ) ;
return - V_25 ;
}
V_22 = F_114 ( V_21 , V_35 . V_91 , V_35 . V_159 , V_173 + V_185 ,
V_174 - V_185 ) ;
if ( F_110 ( V_22 < 0 ) ) {
F_121 ( V_33 , L_10 ,
V_22 , V_62 ) ;
return V_22 ;
}
if ( V_35 . V_29 & V_187 ) {
* V_181 += V_22 ;
if ( F_110 ( log ) ) {
log [ * V_169 ] . V_91 = V_35 . V_91 ;
log [ * V_169 ] . V_159 = V_35 . V_159 ;
++ * V_169 ;
}
} else {
if ( F_110 ( * V_181 ) ) {
F_121 ( V_33 , L_11
L_12 , V_62 ) ;
return - V_25 ;
}
* V_180 += V_22 ;
}
} while ( ( V_62 = F_118 ( & V_35 ) ) != - 1 );
return 0 ;
}
int F_123 ( struct V_20 * V_21 , struct V_32 * V_33 ,
struct V_172 V_173 [] , unsigned int V_174 ,
unsigned int * V_180 , unsigned int * V_181 ,
struct V_168 * log , unsigned int * V_169 )
{
struct V_106 V_35 ;
unsigned int V_62 , V_188 , V_183 = 0 ;
T_12 V_38 ;
int V_22 ;
V_38 = V_33 -> V_38 ;
if ( F_110 ( F_124 ( V_33 -> V_39 , & V_33 -> V_36 -> V_135 ) ) ) {
F_121 ( V_33 , L_13 ,
& V_33 -> V_36 -> V_135 ) ;
return - V_117 ;
}
if ( F_110 ( ( T_12 ) ( V_33 -> V_39 - V_38 ) > V_33 -> V_34 ) ) {
F_121 ( V_33 , L_14 ,
V_38 , V_33 -> V_39 ) ;
return - V_117 ;
}
if ( V_33 -> V_39 == V_38 )
return V_33 -> V_34 ;
F_125 () ;
if ( F_110 ( F_124 ( V_188 ,
& V_33 -> V_36 -> V_111 [ V_38 % V_33 -> V_34 ] ) ) ) {
F_121 ( V_33 , L_15 ,
V_38 ,
& V_33 -> V_36 -> V_111 [ V_38 % V_33 -> V_34 ] ) ;
return - V_117 ;
}
if ( F_110 ( V_188 >= V_33 -> V_34 ) ) {
F_121 ( V_33 , L_16 ,
V_188 , V_33 -> V_34 ) ;
return - V_25 ;
}
* V_180 = * V_181 = 0 ;
if ( F_110 ( log ) )
* V_169 = 0 ;
V_62 = V_188 ;
do {
unsigned V_185 = * V_181 + * V_180 ;
if ( F_110 ( V_62 >= V_33 -> V_34 ) ) {
F_121 ( V_33 , L_17 ,
V_62 , V_33 -> V_34 , V_188 ) ;
return - V_25 ;
}
if ( F_110 ( ++ V_183 > V_33 -> V_34 ) ) {
F_121 ( V_33 , L_6
L_18 ,
V_62 , V_33 -> V_34 , V_188 ) ;
return - V_25 ;
}
V_22 = F_126 ( & V_35 , V_33 -> V_35 + V_62 , sizeof V_35 ) ;
if ( F_110 ( V_22 ) ) {
F_121 ( V_33 , L_19 ,
V_62 , V_33 -> V_35 + V_62 ) ;
return - V_117 ;
}
if ( V_35 . V_29 & V_186 ) {
V_22 = F_120 ( V_21 , V_33 , V_173 , V_174 ,
V_180 , V_181 ,
log , V_169 , & V_35 ) ;
if ( F_110 ( V_22 < 0 ) ) {
F_121 ( V_33 , L_20
L_21 , V_62 ) ;
return V_22 ;
}
continue;
}
V_22 = F_114 ( V_21 , V_35 . V_91 , V_35 . V_159 , V_173 + V_185 ,
V_174 - V_185 ) ;
if ( F_110 ( V_22 < 0 ) ) {
F_121 ( V_33 , L_22 ,
V_22 , V_62 ) ;
return V_22 ;
}
if ( V_35 . V_29 & V_187 ) {
* V_181 += V_22 ;
if ( F_110 ( log ) ) {
log [ * V_169 ] . V_91 = V_35 . V_91 ;
log [ * V_169 ] . V_159 = V_35 . V_159 ;
++ * V_169 ;
}
} else {
if ( F_110 ( * V_181 ) ) {
F_121 ( V_33 , L_23
L_24 , V_62 ) ;
return - V_25 ;
}
* V_180 += V_22 ;
}
} while ( ( V_62 = F_118 ( & V_35 ) ) != - 1 );
V_33 -> V_38 ++ ;
F_20 ( ! ( V_33 -> V_43 & V_189 ) ) ;
return V_188 ;
}
void F_127 ( struct V_32 * V_33 , int V_190 )
{
V_33 -> V_38 -= V_190 ;
}
int F_128 ( struct V_32 * V_33 , unsigned int V_188 , int V_159 )
{
struct V_191 T_6 * V_37 ;
V_37 = & V_33 -> V_37 -> V_111 [ V_33 -> V_40 % V_33 -> V_34 ] ;
if ( F_109 ( V_188 , & V_37 -> V_192 ) ) {
F_121 ( V_33 , L_25 ) ;
return - V_117 ;
}
if ( F_109 ( V_159 , & V_37 -> V_159 ) ) {
F_121 ( V_33 , L_26 ) ;
return - V_117 ;
}
F_104 () ;
if ( F_109 ( V_33 -> V_40 + 1 , & V_33 -> V_37 -> V_135 ) ) {
F_121 ( V_33 , L_27 ) ;
return - V_117 ;
}
if ( F_110 ( V_33 -> V_44 ) ) {
F_104 () ;
F_102 ( V_33 -> V_47 ,
V_33 -> V_45 +
( ( void T_6 * ) V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof *V_37 ) ;
F_102 ( V_33 -> V_47 ,
V_33 -> V_45 + F_63 ( struct V_108 , V_135 ) ,
sizeof V_33 -> V_37 -> V_135 ) ;
if ( V_33 -> V_52 )
F_106 ( V_33 -> V_52 , 1 ) ;
}
V_33 -> V_40 ++ ;
if ( F_110 ( V_33 -> V_40 == V_33 -> V_41 ) )
V_33 -> V_42 = false ;
return 0 ;
}
static int F_129 ( struct V_32 * V_33 ,
struct V_191 * V_61 ,
unsigned V_182 )
{
struct V_191 T_6 * V_37 ;
T_12 V_193 , V_194 ;
int V_195 ;
V_195 = V_33 -> V_40 % V_33 -> V_34 ;
V_37 = V_33 -> V_37 -> V_111 + V_195 ;
if ( F_130 ( V_37 , V_61 , V_182 * sizeof *V_37 ) ) {
F_121 ( V_33 , L_28 ) ;
return - V_117 ;
}
if ( F_110 ( V_33 -> V_44 ) ) {
F_104 () ;
F_102 ( V_33 -> V_47 ,
V_33 -> V_45 +
( ( void T_6 * ) V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
V_182 * sizeof *V_37 ) ;
}
V_193 = V_33 -> V_40 ;
V_194 = ( V_33 -> V_40 += V_182 ) ;
if ( F_110 ( ( T_12 ) ( V_194 - V_33 -> V_41 ) < ( T_12 ) ( V_194 - V_193 ) ) )
V_33 -> V_42 = false ;
return 0 ;
}
int F_131 ( struct V_32 * V_33 , struct V_191 * V_61 ,
unsigned V_182 )
{
int V_195 , V_190 , V_136 ;
V_195 = V_33 -> V_40 % V_33 -> V_34 ;
V_190 = V_33 -> V_34 - V_195 ;
if ( V_190 < V_182 ) {
V_136 = F_129 ( V_33 , V_61 , V_190 ) ;
if ( V_136 < 0 )
return V_136 ;
V_61 += V_190 ;
V_182 -= V_190 ;
}
V_136 = F_129 ( V_33 , V_61 , V_182 ) ;
F_104 () ;
if ( F_132 ( V_33 -> V_40 , & V_33 -> V_37 -> V_135 ) ) {
F_121 ( V_33 , L_27 ) ;
return - V_117 ;
}
if ( F_110 ( V_33 -> V_44 ) ) {
F_102 ( V_33 -> V_47 ,
V_33 -> V_45 + F_63 ( struct V_108 , V_135 ) ,
sizeof V_33 -> V_37 -> V_135 ) ;
if ( V_33 -> V_52 )
F_106 ( V_33 -> V_52 , 1 ) ;
}
return V_136 ;
}
static bool F_133 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
T_13 V_193 , V_194 , V_196 ;
bool V_197 ;
F_134 () ;
if ( F_80 ( V_21 , V_198 ) &&
F_110 ( V_33 -> V_39 == V_33 -> V_38 ) )
return true ;
if ( ! F_80 ( V_21 , V_109 ) ) {
T_13 V_29 ;
if ( F_124 ( V_29 , & V_33 -> V_36 -> V_29 ) ) {
F_121 ( V_33 , L_29 ) ;
return true ;
}
return ! ( V_29 & V_199 ) ;
}
V_193 = V_33 -> V_41 ;
V_197 = V_33 -> V_42 ;
V_194 = V_33 -> V_41 = V_33 -> V_40 ;
V_33 -> V_42 = true ;
if ( F_110 ( ! V_197 ) )
return true ;
if ( F_89 ( V_196 , F_135 ( V_33 ) ) ) {
F_121 ( V_33 , L_30 ) ;
return true ;
}
return F_136 ( V_196 , V_194 , V_193 ) ;
}
void F_137 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
if ( V_33 -> V_50 && F_133 ( V_21 , V_33 ) )
F_106 ( V_33 -> V_50 , 1 ) ;
}
void F_138 ( struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int V_188 , int V_159 )
{
F_128 ( V_33 , V_188 , V_159 ) ;
F_137 ( V_21 , V_33 ) ;
}
void F_139 ( struct V_20 * V_21 ,
struct V_32 * V_33 ,
struct V_191 * V_61 , unsigned V_182 )
{
F_131 ( V_33 , V_61 , V_182 ) ;
F_137 ( V_21 , V_33 ) ;
}
bool F_140 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
T_12 V_39 ;
int V_136 ;
if ( ! ( V_33 -> V_43 & V_189 ) )
return false ;
V_33 -> V_43 &= ~ V_189 ;
if ( ! F_80 ( V_21 , V_109 ) ) {
V_136 = F_108 ( V_33 ) ;
if ( V_136 ) {
F_121 ( V_33 , L_31 ,
& V_33 -> V_37 -> V_29 , V_136 ) ;
return false ;
}
} else {
V_136 = F_111 ( V_33 , V_33 -> V_39 ) ;
if ( V_136 ) {
F_121 ( V_33 , L_32 ,
F_112 ( V_33 ) , V_136 ) ;
return false ;
}
}
F_134 () ;
V_136 = F_124 ( V_39 , & V_33 -> V_36 -> V_135 ) ;
if ( V_136 ) {
F_121 ( V_33 , L_33 ,
& V_33 -> V_36 -> V_135 , V_136 ) ;
return false ;
}
return V_39 != V_33 -> V_39 ;
}
void F_141 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
int V_136 ;
if ( V_33 -> V_43 & V_189 )
return;
V_33 -> V_43 |= V_189 ;
if ( ! F_80 ( V_21 , V_109 ) ) {
V_136 = F_108 ( V_33 ) ;
if ( V_136 )
F_121 ( V_33 , L_31 ,
& V_33 -> V_37 -> V_29 , V_136 ) ;
}
}
static int T_14 F_142 ( void )
{
return 0 ;
}
static void T_15 F_143 ( void )
{
}
