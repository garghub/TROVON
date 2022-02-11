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
F_26 ( & V_21 -> V_28 , V_29 ) ;
F_27 ( V_21 -> V_31 ) ;
} else {
F_26 ( & V_21 -> V_28 , V_29 ) ;
}
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
V_33 -> V_47 = 0 ;
V_33 -> V_48 = NULL ;
V_33 -> V_49 = NULL ;
V_33 -> error = NULL ;
V_33 -> V_50 = NULL ;
V_33 -> V_51 = NULL ;
V_33 -> V_52 = NULL ;
V_33 -> V_53 = NULL ;
V_33 -> V_54 = NULL ;
}
static int F_29 ( void * V_55 )
{
struct V_20 * V_21 = V_55 ;
struct V_12 * V_13 = NULL ;
unsigned V_56 ( V_26 ) ;
T_5 V_57 = F_30 () ;
F_31 ( V_58 ) ;
F_32 ( V_21 -> V_59 ) ;
for (; ; ) {
F_33 ( V_60 ) ;
F_16 ( & V_21 -> V_28 ) ;
if ( V_13 ) {
V_13 -> V_19 = V_26 ;
if ( V_13 -> V_17 )
F_34 ( & V_13 -> V_16 ) ;
}
if ( F_35 () ) {
F_17 ( & V_21 -> V_28 ) ;
F_36 ( V_61 ) ;
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
static void F_42 ( struct V_32 * V_33 )
{
F_43 ( V_33 -> V_62 ) ;
V_33 -> V_62 = NULL ;
F_43 ( V_33 -> log ) ;
V_33 -> log = NULL ;
F_43 ( V_33 -> V_63 ) ;
V_33 -> V_63 = NULL ;
}
static long F_44 ( struct V_20 * V_21 )
{
struct V_32 * V_33 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_65 ; ++ V_64 ) {
V_33 = V_21 -> V_66 [ V_64 ] ;
V_33 -> V_62 = F_45 ( sizeof * V_33 -> V_62 * V_67 ,
V_68 ) ;
V_33 -> log = F_45 ( sizeof * V_33 -> log * V_67 , V_68 ) ;
V_33 -> V_63 = F_45 ( sizeof * V_33 -> V_63 * V_67 , V_68 ) ;
if ( ! V_33 -> V_62 || ! V_33 -> log || ! V_33 -> V_63 )
goto V_69;
}
return 0 ;
V_69:
for (; V_64 >= 0 ; -- V_64 )
F_42 ( V_21 -> V_66 [ V_64 ] ) ;
return - V_70 ;
}
static void F_46 ( struct V_20 * V_21 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_65 ; ++ V_64 )
F_42 ( V_21 -> V_66 [ V_64 ] ) ;
}
void F_47 ( struct V_20 * V_21 ,
struct V_32 * * V_66 , int V_65 )
{
struct V_32 * V_33 ;
int V_64 ;
V_21 -> V_66 = V_66 ;
V_21 -> V_65 = V_65 ;
F_48 ( & V_21 -> V_71 ) ;
V_21 -> V_53 = NULL ;
V_21 -> V_72 = NULL ;
V_21 -> V_54 = NULL ;
V_21 -> V_59 = NULL ;
F_49 ( & V_21 -> V_28 ) ;
F_7 ( & V_21 -> V_30 ) ;
V_21 -> V_31 = NULL ;
for ( V_64 = 0 ; V_64 < V_21 -> V_65 ; ++ V_64 ) {
V_33 = V_21 -> V_66 [ V_64 ] ;
V_33 -> log = NULL ;
V_33 -> V_62 = NULL ;
V_33 -> V_63 = NULL ;
V_33 -> V_21 = V_21 ;
F_48 ( & V_33 -> V_71 ) ;
F_28 ( V_21 , V_33 ) ;
if ( V_33 -> V_73 )
F_9 ( & V_33 -> V_5 , V_33 -> V_73 ,
V_74 , V_21 ) ;
}
}
long F_50 ( struct V_20 * V_21 )
{
return V_21 -> V_59 == V_75 -> V_59 ? 0 : - V_76 ;
}
static void F_51 ( struct V_12 * V_13 )
{
struct V_77 * V_78 ;
V_78 = F_2 ( V_13 , struct V_77 , V_13 ) ;
V_78 -> V_22 = F_52 ( V_78 -> V_79 , V_75 ) ;
}
static int F_53 ( struct V_20 * V_21 )
{
struct V_77 V_80 ;
V_80 . V_79 = V_75 ;
F_6 ( & V_80 . V_13 , F_51 ) ;
F_22 ( V_21 , & V_80 . V_13 ) ;
F_18 ( V_21 , & V_80 . V_13 ) ;
return V_80 . V_22 ;
}
bool F_54 ( struct V_20 * V_21 )
{
return V_21 -> V_59 ;
}
long F_55 ( struct V_20 * V_21 )
{
struct V_81 * V_31 ;
int V_82 ;
if ( F_54 ( V_21 ) ) {
V_82 = - V_83 ;
goto V_84;
}
V_21 -> V_59 = F_56 ( V_75 ) ;
V_31 = F_57 ( F_29 , V_21 , L_1 , V_75 -> V_85 ) ;
if ( F_58 ( V_31 ) ) {
V_82 = F_59 ( V_31 ) ;
goto V_86;
}
V_21 -> V_31 = V_31 ;
F_27 ( V_31 ) ;
V_82 = F_53 ( V_21 ) ;
if ( V_82 )
goto V_87;
V_82 = F_44 ( V_21 ) ;
if ( V_82 )
goto V_87;
return 0 ;
V_87:
F_60 ( V_31 ) ;
V_21 -> V_31 = NULL ;
V_86:
if ( V_21 -> V_59 )
F_61 ( V_21 -> V_59 ) ;
V_21 -> V_59 = NULL ;
V_84:
return V_82 ;
}
struct V_88 * F_62 ( void )
{
return F_45 ( F_63 ( struct V_88 , V_89 ) , V_68 ) ;
}
void F_64 ( struct V_20 * V_21 , struct V_88 * V_54 )
{
int V_64 ;
F_65 ( V_21 , true ) ;
V_54 -> V_90 = 0 ;
V_21 -> V_54 = V_54 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_65 ; ++ V_64 )
V_21 -> V_66 [ V_64 ] -> V_54 = V_54 ;
}
void F_66 ( struct V_20 * V_21 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_65 ; ++ V_64 ) {
if ( V_21 -> V_66 [ V_64 ] -> V_50 && V_21 -> V_66 [ V_64 ] -> V_73 ) {
F_14 ( & V_21 -> V_66 [ V_64 ] -> V_5 ) ;
F_21 ( & V_21 -> V_66 [ V_64 ] -> V_5 ) ;
}
}
}
void F_65 ( struct V_20 * V_21 , bool V_91 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_65 ; ++ V_64 ) {
if ( V_21 -> V_66 [ V_64 ] -> V_49 )
F_67 ( V_21 -> V_66 [ V_64 ] -> V_49 ) ;
if ( V_21 -> V_66 [ V_64 ] -> error )
F_68 ( V_21 -> V_66 [ V_64 ] -> error ) ;
if ( V_21 -> V_66 [ V_64 ] -> V_50 )
F_68 ( V_21 -> V_66 [ V_64 ] -> V_50 ) ;
if ( V_21 -> V_66 [ V_64 ] -> V_51 )
F_67 ( V_21 -> V_66 [ V_64 ] -> V_51 ) ;
if ( V_21 -> V_66 [ V_64 ] -> V_52 )
F_68 ( V_21 -> V_66 [ V_64 ] -> V_52 ) ;
F_28 ( V_21 , V_21 -> V_66 [ V_64 ] ) ;
}
F_46 ( V_21 ) ;
if ( V_21 -> V_53 )
F_67 ( V_21 -> V_53 ) ;
V_21 -> V_53 = NULL ;
if ( V_21 -> V_72 )
F_68 ( V_21 -> V_72 ) ;
V_21 -> V_72 = NULL ;
F_43 ( V_21 -> V_54 ) ;
V_21 -> V_54 = NULL ;
F_69 ( ! F_24 ( & V_21 -> V_30 ) ) ;
if ( V_21 -> V_31 ) {
F_60 ( V_21 -> V_31 ) ;
V_21 -> V_31 = NULL ;
}
if ( V_21 -> V_59 )
F_61 ( V_21 -> V_59 ) ;
V_21 -> V_59 = NULL ;
}
static int F_70 ( void T_6 * V_48 , T_7 V_92 , unsigned long V_93 )
{
T_7 V_94 = V_92 / V_95 / 8 ;
if ( V_94 > V_96 - ( unsigned long ) V_48 ||
V_94 + ( unsigned long ) V_48 > V_96 )
return 0 ;
return F_71 ( V_97 , V_48 + V_94 ,
( V_93 + V_95 * 8 - 1 ) / V_95 / 8 ) ;
}
static int F_72 ( void T_6 * V_48 , struct V_88 * V_98 ,
int V_99 )
{
int V_64 ;
if ( ! V_98 )
return 0 ;
for ( V_64 = 0 ; V_64 < V_98 -> V_90 ; ++ V_64 ) {
struct V_100 * V_101 = V_98 -> V_89 + V_64 ;
unsigned long V_94 = V_101 -> V_102 ;
if ( V_101 -> V_103 > V_96 )
return 0 ;
else if ( ! F_71 ( V_97 , ( void T_6 * ) V_94 ,
V_101 -> V_103 ) )
return 0 ;
else if ( V_99 && ! F_70 ( V_48 ,
V_101 -> V_104 ,
V_101 -> V_103 ) )
return 0 ;
}
return 1 ;
}
static int F_73 ( struct V_20 * V_105 , struct V_88 * V_98 ,
int V_99 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_105 -> V_65 ; ++ V_64 ) {
int V_106 ;
bool log ;
F_74 ( & V_105 -> V_66 [ V_64 ] -> V_71 ) ;
log = V_99 || F_75 ( V_105 -> V_66 [ V_64 ] , V_107 ) ;
if ( V_105 -> V_66 [ V_64 ] -> V_46 )
V_106 = F_72 ( V_105 -> V_66 [ V_64 ] -> V_48 , V_98 , log ) ;
else
V_106 = 1 ;
F_76 ( & V_105 -> V_66 [ V_64 ] -> V_71 ) ;
if ( ! V_106 )
return 0 ;
}
return 1 ;
}
static int F_77 ( struct V_32 * V_33 , unsigned int V_34 ,
struct V_108 T_6 * V_35 ,
struct V_109 T_6 * V_36 ,
struct V_110 T_6 * V_37 )
{
T_8 V_78 = F_75 ( V_33 , V_111 ) ? 2 : 0 ;
return F_71 ( V_112 , V_35 , V_34 * sizeof *V_35 ) &&
F_71 ( V_112 , V_36 ,
sizeof *V_36 + V_34 * sizeof * V_36 -> V_113 + V_78 ) &&
F_71 ( V_97 , V_37 ,
sizeof *V_37 + V_34 * sizeof * V_37 -> V_113 + V_78 ) ;
}
int F_78 ( struct V_20 * V_21 )
{
return F_73 ( V_21 , V_21 -> V_54 , 1 ) ;
}
static int F_79 ( struct V_32 * V_33 ,
void T_6 * V_48 )
{
T_8 V_78 = F_75 ( V_33 , V_111 ) ? 2 : 0 ;
return F_72 ( V_48 , V_33 -> V_54 ,
F_75 ( V_33 , V_107 ) ) &&
( ! V_33 -> V_44 || F_70 ( V_48 , V_33 -> V_45 ,
sizeof * V_33 -> V_37 +
V_33 -> V_34 * sizeof * V_33 -> V_37 -> V_113 + V_78 ) ) ;
}
int F_80 ( struct V_32 * V_33 )
{
return F_77 ( V_33 , V_33 -> V_34 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) &&
F_79 ( V_33 , V_33 -> V_48 ) ;
}
static long F_81 ( struct V_20 * V_105 , struct V_88 T_6 * V_101 )
{
struct V_88 V_98 , * V_114 , * V_115 ;
unsigned long V_116 = F_63 ( struct V_88 , V_89 ) ;
int V_64 ;
if ( F_82 ( & V_98 , V_101 , V_116 ) )
return - V_117 ;
if ( V_98 . V_118 )
return - V_119 ;
if ( V_98 . V_90 > V_120 )
return - V_121 ;
V_114 = F_45 ( V_116 + V_98 . V_90 * sizeof * V_101 -> V_89 , V_68 ) ;
if ( ! V_114 )
return - V_70 ;
memcpy ( V_114 , & V_98 , V_116 ) ;
if ( F_82 ( V_114 -> V_89 , V_101 -> V_89 ,
V_98 . V_90 * sizeof * V_101 -> V_89 ) ) {
F_43 ( V_114 ) ;
return - V_117 ;
}
if ( ! F_73 ( V_105 , V_114 , 0 ) ) {
F_43 ( V_114 ) ;
return - V_117 ;
}
V_115 = V_105 -> V_54 ;
V_105 -> V_54 = V_114 ;
for ( V_64 = 0 ; V_64 < V_105 -> V_65 ; ++ V_64 ) {
F_74 ( & V_105 -> V_66 [ V_64 ] -> V_71 ) ;
V_105 -> V_66 [ V_64 ] -> V_54 = V_114 ;
F_76 ( & V_105 -> V_66 [ V_64 ] -> V_71 ) ;
}
F_43 ( V_115 ) ;
return 0 ;
}
long F_83 ( struct V_20 * V_105 , int V_122 , void T_6 * V_123 )
{
struct V_1 * V_124 , * V_125 = NULL ;
bool V_126 = false , V_127 = false ;
struct V_128 * V_129 = NULL ;
T_9 T_6 * V_130 = V_123 ;
struct V_32 * V_33 ;
struct V_131 V_78 ;
struct V_132 V_133 ;
struct V_134 V_94 ;
T_9 V_135 ;
long V_136 ;
V_136 = F_84 ( V_135 , V_130 ) ;
if ( V_136 < 0 )
return V_136 ;
if ( V_135 >= V_105 -> V_65 )
return - V_137 ;
V_33 = V_105 -> V_66 [ V_135 ] ;
F_74 ( & V_33 -> V_71 ) ;
switch ( V_122 ) {
case V_138 :
if ( V_33 -> V_46 ) {
V_136 = - V_83 ;
break;
}
if ( F_82 ( & V_78 , V_123 , sizeof V_78 ) ) {
V_136 = - V_117 ;
break;
}
if ( ! V_78 . V_34 || V_78 . V_34 > 0xffff || ( V_78 . V_34 & ( V_78 . V_34 - 1 ) ) ) {
V_136 = - V_25 ;
break;
}
V_33 -> V_34 = V_78 . V_34 ;
break;
case V_139 :
if ( V_33 -> V_46 ) {
V_136 = - V_83 ;
break;
}
if ( F_82 ( & V_78 , V_123 , sizeof V_78 ) ) {
V_136 = - V_117 ;
break;
}
if ( V_78 . V_34 > 0xffff ) {
V_136 = - V_25 ;
break;
}
V_33 -> V_38 = V_78 . V_34 ;
V_33 -> V_39 = V_33 -> V_38 ;
break;
case V_140 :
V_78 . V_141 = V_135 ;
V_78 . V_34 = V_33 -> V_38 ;
if ( F_85 ( V_123 , & V_78 , sizeof V_78 ) )
V_136 = - V_117 ;
break;
case V_142 :
if ( F_82 ( & V_94 , V_123 , sizeof V_94 ) ) {
V_136 = - V_117 ;
break;
}
if ( V_94 . V_29 & ~ ( 0x1 << V_143 ) ) {
V_136 = - V_119 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_94 . V_144 != V_94 . V_144 ||
( T_7 ) ( unsigned long ) V_94 . V_145 != V_94 . V_145 ||
( T_7 ) ( unsigned long ) V_94 . V_146 != V_94 . V_146 ) {
V_136 = - V_117 ;
break;
}
F_86 ( V_147 * V_33 -> V_36 > V_148 ) ;
F_86 ( V_147 * V_33 -> V_37 > V_149 ) ;
if ( ( V_94 . V_146 & ( V_148 - 1 ) ) ||
( V_94 . V_145 & ( V_149 - 1 ) ) ||
( V_94 . V_150 & ( sizeof( T_7 ) - 1 ) ) ) {
V_136 = - V_25 ;
break;
}
if ( V_33 -> V_46 ) {
if ( ! F_77 ( V_33 , V_33 -> V_34 ,
( void T_6 * ) ( unsigned long ) V_94 . V_144 ,
( void T_6 * ) ( unsigned long ) V_94 . V_146 ,
( void T_6 * ) ( unsigned long ) V_94 . V_145 ) ) {
V_136 = - V_25 ;
break;
}
if ( ( V_94 . V_29 & ( 0x1 << V_143 ) ) &&
! F_70 ( V_33 -> V_48 , V_94 . V_150 ,
sizeof * V_33 -> V_37 +
V_33 -> V_34 * sizeof * V_33 -> V_37 -> V_113 ) ) {
V_136 = - V_25 ;
break;
}
}
V_33 -> V_44 = ! ! ( V_94 . V_29 & ( 0x1 << V_143 ) ) ;
V_33 -> V_35 = ( void T_6 * ) ( unsigned long ) V_94 . V_144 ;
V_33 -> V_36 = ( void T_6 * ) ( unsigned long ) V_94 . V_146 ;
V_33 -> V_45 = V_94 . V_150 ;
V_33 -> V_37 = ( void T_6 * ) ( unsigned long ) V_94 . V_145 ;
break;
case V_151 :
if ( F_82 ( & V_133 , V_123 , sizeof V_133 ) ) {
V_136 = - V_117 ;
break;
}
V_124 = V_133 . V_152 == - 1 ? NULL : F_87 ( V_133 . V_152 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_33 -> V_50 ) {
V_127 = ( V_125 = V_33 -> V_50 ) != NULL ;
V_126 = ( V_33 -> V_50 = V_124 ) != NULL ;
} else
V_125 = V_124 ;
break;
case V_153 :
if ( F_82 ( & V_133 , V_123 , sizeof V_133 ) ) {
V_136 = - V_117 ;
break;
}
V_124 = V_133 . V_152 == - 1 ? NULL : F_87 ( V_133 . V_152 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_33 -> V_52 ) {
V_125 = V_33 -> V_52 ;
V_129 = V_33 -> V_51 ;
V_33 -> V_52 = V_124 ;
V_33 -> V_51 = V_124 ?
F_88 ( V_124 ) : NULL ;
} else
V_125 = V_124 ;
break;
case V_154 :
if ( F_82 ( & V_133 , V_123 , sizeof V_133 ) ) {
V_136 = - V_117 ;
break;
}
V_124 = V_133 . V_152 == - 1 ? NULL : F_87 ( V_133 . V_152 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_33 -> error ) {
V_125 = V_33 -> error ;
V_33 -> error = V_124 ;
V_129 = V_33 -> V_49 ;
V_33 -> V_49 = V_124 ?
F_88 ( V_124 ) : NULL ;
} else
V_125 = V_124 ;
break;
default:
V_136 = - V_155 ;
}
if ( V_127 && V_33 -> V_73 )
F_14 ( & V_33 -> V_5 ) ;
if ( V_129 )
F_67 ( V_129 ) ;
if ( V_125 )
F_68 ( V_125 ) ;
if ( V_126 && V_33 -> V_73 )
V_136 = F_12 ( & V_33 -> V_5 , V_33 -> V_50 ) ;
F_76 ( & V_33 -> V_71 ) ;
if ( V_127 && V_33 -> V_73 )
F_21 ( & V_33 -> V_5 ) ;
return V_136 ;
}
long F_89 ( struct V_20 * V_105 , unsigned int V_122 , void T_6 * V_123 )
{
struct V_1 * V_124 , * V_125 = NULL ;
struct V_128 * V_129 = NULL ;
T_7 V_156 ;
long V_136 ;
int V_64 , V_152 ;
if ( V_122 == V_157 ) {
V_136 = F_55 ( V_105 ) ;
goto V_16;
}
V_136 = F_50 ( V_105 ) ;
if ( V_136 )
goto V_16;
switch ( V_122 ) {
case V_158 :
V_136 = F_81 ( V_105 , V_123 ) ;
break;
case V_159 :
if ( F_82 ( & V_156 , V_123 , sizeof V_156 ) ) {
V_136 = - V_117 ;
break;
}
if ( ( T_7 ) ( unsigned long ) V_156 != V_156 ) {
V_136 = - V_117 ;
break;
}
for ( V_64 = 0 ; V_64 < V_105 -> V_65 ; ++ V_64 ) {
struct V_32 * V_33 ;
void T_6 * V_160 = ( void T_6 * ) ( unsigned long ) V_156 ;
V_33 = V_105 -> V_66 [ V_64 ] ;
F_74 ( & V_33 -> V_71 ) ;
if ( V_33 -> V_46 && ! F_79 ( V_33 , V_160 ) )
V_136 = - V_117 ;
else
V_33 -> V_48 = V_160 ;
F_76 ( & V_33 -> V_71 ) ;
}
break;
case V_161 :
V_136 = F_84 ( V_152 , ( int T_6 * ) V_123 ) ;
if ( V_136 < 0 )
break;
V_124 = V_152 == - 1 ? NULL : F_87 ( V_152 ) ;
if ( F_58 ( V_124 ) ) {
V_136 = F_59 ( V_124 ) ;
break;
}
if ( V_124 != V_105 -> V_72 ) {
V_125 = V_105 -> V_72 ;
V_129 = V_105 -> V_53 ;
V_105 -> V_53 = V_124 ?
F_88 ( V_124 ) : NULL ;
} else
V_125 = V_124 ;
for ( V_64 = 0 ; V_64 < V_105 -> V_65 ; ++ V_64 ) {
F_74 ( & V_105 -> V_66 [ V_64 ] -> V_71 ) ;
V_105 -> V_66 [ V_64 ] -> V_53 = V_105 -> V_53 ;
F_76 ( & V_105 -> V_66 [ V_64 ] -> V_71 ) ;
}
if ( V_129 )
F_67 ( V_129 ) ;
if ( V_125 )
F_68 ( V_125 ) ;
break;
default:
V_136 = - V_155 ;
break;
}
V_16:
return V_136 ;
}
static const struct V_100 * F_90 ( struct V_88 * V_98 ,
T_10 V_92 , T_11 V_162 )
{
struct V_100 * V_163 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_98 -> V_90 ; ++ V_64 ) {
V_163 = V_98 -> V_89 + V_64 ;
if ( V_163 -> V_104 <= V_92 &&
V_163 -> V_104 + V_163 -> V_103 - 1 >= V_92 )
return V_163 ;
}
return NULL ;
}
static int F_91 ( int V_164 , void T_6 * V_92 )
{
unsigned long log = ( unsigned long ) V_92 ;
struct V_165 * V_165 ;
void * V_160 ;
int V_166 = V_164 + ( log % V_167 ) * 8 ;
int V_136 ;
V_136 = F_92 ( log , 1 , 1 , & V_165 ) ;
if ( V_136 < 0 )
return V_136 ;
F_20 ( V_136 != 1 ) ;
V_160 = F_93 ( V_165 ) ;
F_94 ( V_166 , V_160 ) ;
F_95 ( V_160 ) ;
F_96 ( V_165 ) ;
F_97 ( V_165 ) ;
return 0 ;
}
static int F_98 ( void T_6 * V_48 ,
T_7 V_168 , T_7 V_169 )
{
T_7 V_170 = V_168 / V_95 ;
int V_136 ;
if ( ! V_169 )
return 0 ;
V_169 += V_168 % V_95 ;
for (; ; ) {
T_7 V_160 = ( T_7 ) ( unsigned long ) V_48 ;
T_7 log = V_160 + V_170 / 8 ;
int V_166 = V_170 % 8 ;
if ( ( T_7 ) ( unsigned long ) log != log )
return - V_117 ;
V_136 = F_91 ( V_166 , ( void T_6 * ) ( unsigned long ) log ) ;
if ( V_136 < 0 )
return V_136 ;
if ( V_169 <= V_95 )
break;
V_169 -= V_95 ;
V_170 += 1 ;
}
return V_136 ;
}
int F_99 ( struct V_32 * V_33 , struct V_171 * log ,
unsigned int V_172 , T_7 V_162 )
{
int V_64 , V_136 ;
F_100 () ;
for ( V_64 = 0 ; V_64 < V_172 ; ++ V_64 ) {
T_7 V_173 = F_101 ( log [ V_64 ] . V_162 , V_162 ) ;
V_136 = F_98 ( V_33 -> V_48 , log [ V_64 ] . V_92 , V_173 ) ;
if ( V_136 < 0 )
return V_136 ;
V_162 -= V_173 ;
if ( ! V_162 ) {
if ( V_33 -> V_53 )
F_102 ( V_33 -> V_53 , 1 ) ;
return 0 ;
}
}
F_103 () ;
return 0 ;
}
static int F_104 ( struct V_32 * V_33 )
{
void T_6 * V_37 ;
if ( F_105 ( F_106 ( V_33 , V_33 -> V_43 ) , & V_33 -> V_37 -> V_29 ) < 0 )
return - V_117 ;
if ( F_107 ( V_33 -> V_44 ) ) {
F_100 () ;
V_37 = & V_33 -> V_37 -> V_29 ;
F_98 ( V_33 -> V_48 , V_33 -> V_45 +
( V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof V_33 -> V_37 -> V_29 ) ;
if ( V_33 -> V_53 )
F_102 ( V_33 -> V_53 , 1 ) ;
}
return 0 ;
}
static int F_108 ( struct V_32 * V_33 , T_12 V_174 )
{
if ( F_105 ( F_106 ( V_33 , V_33 -> V_39 ) , F_109 ( V_33 ) ) )
return - V_117 ;
if ( F_107 ( V_33 -> V_44 ) ) {
void T_6 * V_37 ;
F_100 () ;
V_37 = F_109 ( V_33 ) ;
F_98 ( V_33 -> V_48 , V_33 -> V_45 +
( V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
sizeof * F_109 ( V_33 ) ) ;
if ( V_33 -> V_53 )
F_102 ( V_33 -> V_53 , 1 ) ;
}
return 0 ;
}
int F_110 ( struct V_32 * V_33 )
{
T_13 V_40 ;
int V_136 ;
if ( ! V_33 -> V_46 )
return 0 ;
V_136 = F_104 ( V_33 ) ;
if ( V_136 )
return V_136 ;
V_33 -> V_42 = false ;
if ( ! F_71 ( V_112 , & V_33 -> V_37 -> V_135 , sizeof V_33 -> V_37 -> V_135 ) )
return - V_117 ;
V_136 = F_111 ( V_40 , & V_33 -> V_37 -> V_135 ) ;
if ( V_136 )
return V_136 ;
V_33 -> V_40 = F_112 ( V_33 , V_40 ) ;
return 0 ;
}
static int F_113 ( struct V_32 * V_33 , T_7 V_92 , T_9 V_162 ,
struct V_175 V_176 [] , int V_177 )
{
const struct V_100 * V_163 ;
struct V_88 * V_98 ;
struct V_175 * V_178 ;
T_7 V_78 = 0 ;
int V_22 = 0 ;
V_98 = V_33 -> V_54 ;
while ( ( T_7 ) V_162 > V_78 ) {
T_7 V_116 ;
if ( F_107 ( V_22 >= V_177 ) ) {
V_22 = - V_137 ;
break;
}
V_163 = F_90 ( V_98 , V_92 , V_162 ) ;
if ( F_107 ( ! V_163 ) ) {
V_22 = - V_117 ;
break;
}
V_178 = V_176 + V_22 ;
V_116 = V_163 -> V_103 - V_92 + V_163 -> V_104 ;
V_178 -> V_179 = F_101 ( ( T_7 ) V_162 - V_78 , V_116 ) ;
V_178 -> V_180 = ( void T_6 * ) ( unsigned long )
( V_163 -> V_102 + V_92 - V_163 -> V_104 ) ;
V_78 += V_116 ;
V_92 += V_116 ;
++ V_22 ;
}
return V_22 ;
}
static unsigned F_114 ( struct V_32 * V_33 , struct V_108 * V_35 )
{
unsigned int V_181 ;
if ( ! ( V_35 -> V_29 & F_106 ( V_33 , V_182 ) ) )
return - 1U ;
V_181 = F_112 ( V_33 , V_35 -> V_181 ) ;
F_115 () ;
return V_181 ;
}
static int F_116 ( struct V_32 * V_33 ,
struct V_175 V_176 [] , unsigned int V_177 ,
unsigned int * V_183 , unsigned int * V_184 ,
struct V_171 * log , unsigned int * V_172 ,
struct V_108 * V_62 )
{
struct V_108 V_35 ;
unsigned int V_64 = 0 , V_185 , V_186 = 0 ;
T_9 V_162 = F_117 ( V_33 , V_62 -> V_162 ) ;
int V_22 ;
if ( F_107 ( V_162 % sizeof V_35 ) ) {
F_118 ( V_33 , L_2
L_3 ,
( unsigned long long ) V_162 ,
sizeof V_35 ) ;
return - V_25 ;
}
V_22 = F_113 ( V_33 , F_119 ( V_33 , V_62 -> V_92 ) , V_162 , V_33 -> V_62 ,
V_67 ) ;
if ( F_107 ( V_22 < 0 ) ) {
F_118 ( V_33 , L_4 , V_22 ) ;
return V_22 ;
}
F_115 () ;
V_185 = V_162 / sizeof V_35 ;
if ( F_107 ( V_185 > V_187 + 1 ) ) {
F_118 ( V_33 , L_5 ,
V_62 -> V_162 ) ;
return - V_121 ;
}
do {
unsigned V_188 = * V_184 + * V_183 ;
if ( F_107 ( ++ V_186 > V_185 ) ) {
F_118 ( V_33 , L_6
L_7 ,
V_64 , V_185 ) ;
return - V_25 ;
}
if ( F_107 ( F_120 ( ( unsigned char * ) & V_35 ,
V_33 -> V_62 , sizeof V_35 ) ) ) {
F_118 ( V_33 , L_8 ,
V_64 , ( T_8 ) F_119 ( V_33 , V_62 -> V_92 ) + V_64 * sizeof V_35 ) ;
return - V_25 ;
}
if ( F_107 ( V_35 . V_29 & F_106 ( V_33 , V_189 ) ) ) {
F_118 ( V_33 , L_9 ,
V_64 , ( T_8 ) F_119 ( V_33 , V_62 -> V_92 ) + V_64 * sizeof V_35 ) ;
return - V_25 ;
}
V_22 = F_113 ( V_33 , F_119 ( V_33 , V_35 . V_92 ) ,
F_117 ( V_33 , V_35 . V_162 ) , V_176 + V_188 ,
V_177 - V_188 ) ;
if ( F_107 ( V_22 < 0 ) ) {
F_118 ( V_33 , L_10 ,
V_22 , V_64 ) ;
return V_22 ;
}
if ( V_35 . V_29 & F_106 ( V_33 , V_190 ) ) {
* V_184 += V_22 ;
if ( F_107 ( log ) ) {
log [ * V_172 ] . V_92 = F_119 ( V_33 , V_35 . V_92 ) ;
log [ * V_172 ] . V_162 = F_117 ( V_33 , V_35 . V_162 ) ;
++ * V_172 ;
}
} else {
if ( F_107 ( * V_184 ) ) {
F_118 ( V_33 , L_11
L_12 , V_64 ) ;
return - V_25 ;
}
* V_183 += V_22 ;
}
} while ( ( V_64 = F_114 ( V_33 , & V_35 ) ) != - 1 );
return 0 ;
}
int F_121 ( struct V_32 * V_33 ,
struct V_175 V_176 [] , unsigned int V_177 ,
unsigned int * V_183 , unsigned int * V_184 ,
struct V_171 * log , unsigned int * V_172 )
{
struct V_108 V_35 ;
unsigned int V_64 , V_191 , V_186 = 0 ;
T_12 V_38 ;
T_13 V_39 ;
T_13 V_192 ;
int V_22 ;
V_38 = V_33 -> V_38 ;
if ( F_107 ( F_111 ( V_39 , & V_33 -> V_36 -> V_135 ) ) ) {
F_118 ( V_33 , L_13 ,
& V_33 -> V_36 -> V_135 ) ;
return - V_117 ;
}
V_33 -> V_39 = F_112 ( V_33 , V_39 ) ;
if ( F_107 ( ( T_12 ) ( V_33 -> V_39 - V_38 ) > V_33 -> V_34 ) ) {
F_118 ( V_33 , L_14 ,
V_38 , V_33 -> V_39 ) ;
return - V_117 ;
}
if ( V_33 -> V_39 == V_38 )
return V_33 -> V_34 ;
F_122 () ;
if ( F_107 ( F_111 ( V_192 ,
& V_33 -> V_36 -> V_113 [ V_38 % V_33 -> V_34 ] ) ) ) {
F_118 ( V_33 , L_15 ,
V_38 ,
& V_33 -> V_36 -> V_113 [ V_38 % V_33 -> V_34 ] ) ;
return - V_117 ;
}
V_191 = F_112 ( V_33 , V_192 ) ;
if ( F_107 ( V_191 >= V_33 -> V_34 ) ) {
F_118 ( V_33 , L_16 ,
V_191 , V_33 -> V_34 ) ;
return - V_25 ;
}
* V_183 = * V_184 = 0 ;
if ( F_107 ( log ) )
* V_172 = 0 ;
V_64 = V_191 ;
do {
unsigned V_188 = * V_184 + * V_183 ;
if ( F_107 ( V_64 >= V_33 -> V_34 ) ) {
F_118 ( V_33 , L_17 ,
V_64 , V_33 -> V_34 , V_191 ) ;
return - V_25 ;
}
if ( F_107 ( ++ V_186 > V_33 -> V_34 ) ) {
F_118 ( V_33 , L_6
L_18 ,
V_64 , V_33 -> V_34 , V_191 ) ;
return - V_25 ;
}
V_22 = F_123 ( & V_35 , V_33 -> V_35 + V_64 , sizeof V_35 ) ;
if ( F_107 ( V_22 ) ) {
F_118 ( V_33 , L_19 ,
V_64 , V_33 -> V_35 + V_64 ) ;
return - V_117 ;
}
if ( V_35 . V_29 & F_106 ( V_33 , V_189 ) ) {
V_22 = F_116 ( V_33 , V_176 , V_177 ,
V_183 , V_184 ,
log , V_172 , & V_35 ) ;
if ( F_107 ( V_22 < 0 ) ) {
F_118 ( V_33 , L_20
L_21 , V_64 ) ;
return V_22 ;
}
continue;
}
V_22 = F_113 ( V_33 , F_119 ( V_33 , V_35 . V_92 ) ,
F_117 ( V_33 , V_35 . V_162 ) , V_176 + V_188 ,
V_177 - V_188 ) ;
if ( F_107 ( V_22 < 0 ) ) {
F_118 ( V_33 , L_22 ,
V_22 , V_64 ) ;
return V_22 ;
}
if ( V_35 . V_29 & F_106 ( V_33 , V_190 ) ) {
* V_184 += V_22 ;
if ( F_107 ( log ) ) {
log [ * V_172 ] . V_92 = F_119 ( V_33 , V_35 . V_92 ) ;
log [ * V_172 ] . V_162 = F_117 ( V_33 , V_35 . V_162 ) ;
++ * V_172 ;
}
} else {
if ( F_107 ( * V_184 ) ) {
F_118 ( V_33 , L_23
L_24 , V_64 ) ;
return - V_25 ;
}
* V_183 += V_22 ;
}
} while ( ( V_64 = F_114 ( V_33 , & V_35 ) ) != - 1 );
V_33 -> V_38 ++ ;
F_20 ( ! ( V_33 -> V_43 & V_193 ) ) ;
return V_191 ;
}
void F_124 ( struct V_32 * V_33 , int V_194 )
{
V_33 -> V_38 -= V_194 ;
}
int F_125 ( struct V_32 * V_33 , unsigned int V_191 , int V_162 )
{
struct V_195 V_63 = {
F_126 ( V_33 , V_191 ) ,
F_126 (vq, len)
} ;
return F_127 ( V_33 , & V_63 , 1 ) ;
}
static int F_128 ( struct V_32 * V_33 ,
struct V_195 * V_63 ,
unsigned V_185 )
{
struct V_195 T_6 * V_37 ;
T_12 V_196 , V_197 ;
int V_198 ;
V_198 = V_33 -> V_40 % V_33 -> V_34 ;
V_37 = V_33 -> V_37 -> V_113 + V_198 ;
if ( V_185 == 1 ) {
if ( F_105 ( V_63 [ 0 ] . V_199 , & V_37 -> V_199 ) ) {
F_118 ( V_33 , L_25 ) ;
return - V_117 ;
}
if ( F_105 ( V_63 [ 0 ] . V_162 , & V_37 -> V_162 ) ) {
F_118 ( V_33 , L_26 ) ;
return - V_117 ;
}
} else if ( F_129 ( V_37 , V_63 , V_185 * sizeof *V_37 ) ) {
F_118 ( V_33 , L_27 ) ;
return - V_117 ;
}
if ( F_107 ( V_33 -> V_44 ) ) {
F_100 () ;
F_98 ( V_33 -> V_48 ,
V_33 -> V_45 +
( ( void T_6 * ) V_37 - ( void T_6 * ) V_33 -> V_37 ) ,
V_185 * sizeof *V_37 ) ;
}
V_196 = V_33 -> V_40 ;
V_197 = ( V_33 -> V_40 += V_185 ) ;
if ( F_107 ( ( T_12 ) ( V_197 - V_33 -> V_41 ) < ( T_12 ) ( V_197 - V_196 ) ) )
V_33 -> V_42 = false ;
return 0 ;
}
int F_127 ( struct V_32 * V_33 , struct V_195 * V_63 ,
unsigned V_185 )
{
int V_198 , V_194 , V_136 ;
V_198 = V_33 -> V_40 % V_33 -> V_34 ;
V_194 = V_33 -> V_34 - V_198 ;
if ( V_194 < V_185 ) {
V_136 = F_128 ( V_33 , V_63 , V_194 ) ;
if ( V_136 < 0 )
return V_136 ;
V_63 += V_194 ;
V_185 -= V_194 ;
}
V_136 = F_128 ( V_33 , V_63 , V_185 ) ;
F_100 () ;
if ( F_105 ( F_106 ( V_33 , V_33 -> V_40 ) , & V_33 -> V_37 -> V_135 ) ) {
F_118 ( V_33 , L_28 ) ;
return - V_117 ;
}
if ( F_107 ( V_33 -> V_44 ) ) {
F_98 ( V_33 -> V_48 ,
V_33 -> V_45 + F_63 ( struct V_110 , V_135 ) ,
sizeof V_33 -> V_37 -> V_135 ) ;
if ( V_33 -> V_53 )
F_102 ( V_33 -> V_53 , 1 ) ;
}
return V_136 ;
}
static bool F_130 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
T_14 V_196 , V_197 ;
T_13 V_200 ;
bool V_201 ;
F_131 () ;
if ( F_75 ( V_33 , V_202 ) &&
F_107 ( V_33 -> V_39 == V_33 -> V_38 ) )
return true ;
if ( ! F_75 ( V_33 , V_111 ) ) {
T_13 V_29 ;
if ( F_111 ( V_29 , & V_33 -> V_36 -> V_29 ) ) {
F_118 ( V_33 , L_29 ) ;
return true ;
}
return ! ( V_29 & F_106 ( V_33 , V_203 ) ) ;
}
V_196 = V_33 -> V_41 ;
V_201 = V_33 -> V_42 ;
V_197 = V_33 -> V_41 = V_33 -> V_40 ;
V_33 -> V_42 = true ;
if ( F_107 ( ! V_201 ) )
return true ;
if ( F_111 ( V_200 , F_132 ( V_33 ) ) ) {
F_118 ( V_33 , L_30 ) ;
return true ;
}
return F_133 ( F_112 ( V_33 , V_200 ) , V_197 , V_196 ) ;
}
void F_134 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
if ( V_33 -> V_51 && F_130 ( V_21 , V_33 ) )
F_102 ( V_33 -> V_51 , 1 ) ;
}
void F_135 ( struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int V_191 , int V_162 )
{
F_125 ( V_33 , V_191 , V_162 ) ;
F_134 ( V_21 , V_33 ) ;
}
void F_136 ( struct V_20 * V_21 ,
struct V_32 * V_33 ,
struct V_195 * V_63 , unsigned V_185 )
{
F_127 ( V_33 , V_63 , V_185 ) ;
F_134 ( V_21 , V_33 ) ;
}
bool F_137 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
T_13 V_39 ;
int V_136 ;
if ( ! ( V_33 -> V_43 & V_193 ) )
return false ;
V_33 -> V_43 &= ~ V_193 ;
if ( ! F_75 ( V_33 , V_111 ) ) {
V_136 = F_104 ( V_33 ) ;
if ( V_136 ) {
F_118 ( V_33 , L_31 ,
& V_33 -> V_37 -> V_29 , V_136 ) ;
return false ;
}
} else {
V_136 = F_108 ( V_33 , V_33 -> V_39 ) ;
if ( V_136 ) {
F_118 ( V_33 , L_32 ,
F_109 ( V_33 ) , V_136 ) ;
return false ;
}
}
F_131 () ;
V_136 = F_111 ( V_39 , & V_33 -> V_36 -> V_135 ) ;
if ( V_136 ) {
F_118 ( V_33 , L_33 ,
& V_33 -> V_36 -> V_135 , V_136 ) ;
return false ;
}
return F_112 ( V_33 , V_39 ) != V_33 -> V_39 ;
}
void F_138 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
int V_136 ;
if ( V_33 -> V_43 & V_193 )
return;
V_33 -> V_43 |= V_193 ;
if ( ! F_75 ( V_33 , V_111 ) ) {
V_136 = F_104 ( V_33 ) ;
if ( V_136 )
F_118 ( V_33 , L_31 ,
& V_33 -> V_37 -> V_29 , V_136 ) ;
}
}
static int T_15 F_139 ( void )
{
return 0 ;
}
static void T_16 F_140 ( void )
{
}
