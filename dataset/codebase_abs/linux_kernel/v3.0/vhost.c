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
static void F_6 ( struct V_12 * V_13 , T_4 V_14 )
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
static inline void F_22 ( struct V_20 * V_21 ,
struct V_12 * V_13 )
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
}
static int F_29 ( void * V_52 )
{
struct V_20 * V_21 = V_52 ;
struct V_12 * V_13 = NULL ;
unsigned V_53 ( V_23 ) ;
F_30 ( V_21 -> V_54 ) ;
for (; ; ) {
F_31 ( V_55 ) ;
F_16 ( & V_21 -> V_25 ) ;
if ( V_13 ) {
V_13 -> V_19 = V_23 ;
if ( V_13 -> V_17 )
F_32 ( & V_13 -> V_16 ) ;
}
if ( F_33 () ) {
F_17 ( & V_21 -> V_25 ) ;
F_34 ( V_56 ) ;
break;
}
if ( ! F_24 ( & V_21 -> V_27 ) ) {
V_13 = F_35 ( & V_21 -> V_27 ,
struct V_12 , V_15 ) ;
F_36 ( & V_13 -> V_15 ) ;
V_23 = V_13 -> V_18 ;
} else
V_13 = NULL ;
F_17 ( & V_21 -> V_25 ) ;
if ( V_13 ) {
F_34 ( V_56 ) ;
V_13 -> V_14 ( V_13 ) ;
} else
F_37 () ;
}
F_38 ( V_21 -> V_54 ) ;
return 0 ;
}
static long F_39 ( struct V_20 * V_21 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_21 -> V_58 ; ++ V_57 ) {
V_21 -> V_59 [ V_57 ] . V_60 = F_40 ( sizeof * V_21 -> V_59 [ V_57 ] . V_60 *
V_61 , V_62 ) ;
V_21 -> V_59 [ V_57 ] . log = F_40 ( sizeof * V_21 -> V_59 [ V_57 ] . log * V_61 ,
V_62 ) ;
V_21 -> V_59 [ V_57 ] . V_63 = F_40 ( sizeof * V_21 -> V_59 [ V_57 ] . V_63 *
V_61 , V_62 ) ;
if ( ! V_21 -> V_59 [ V_57 ] . V_60 || ! V_21 -> V_59 [ V_57 ] . log ||
! V_21 -> V_59 [ V_57 ] . V_63 )
goto V_64;
}
return 0 ;
V_64:
for (; V_57 >= 0 ; -- V_57 ) {
F_41 ( V_21 -> V_59 [ V_57 ] . V_60 ) ;
F_41 ( V_21 -> V_59 [ V_57 ] . log ) ;
F_41 ( V_21 -> V_59 [ V_57 ] . V_63 ) ;
}
return - V_65 ;
}
static void F_42 ( struct V_20 * V_21 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_21 -> V_58 ; ++ V_57 ) {
F_41 ( V_21 -> V_59 [ V_57 ] . V_60 ) ;
V_21 -> V_59 [ V_57 ] . V_60 = NULL ;
F_41 ( V_21 -> V_59 [ V_57 ] . log ) ;
V_21 -> V_59 [ V_57 ] . log = NULL ;
F_41 ( V_21 -> V_59 [ V_57 ] . V_63 ) ;
V_21 -> V_59 [ V_57 ] . V_63 = NULL ;
}
}
long F_43 ( struct V_20 * V_21 ,
struct V_29 * V_59 , int V_58 )
{
int V_57 ;
V_21 -> V_59 = V_59 ;
V_21 -> V_58 = V_58 ;
F_44 ( & V_21 -> V_66 ) ;
V_21 -> V_51 = NULL ;
V_21 -> V_67 = NULL ;
V_21 -> V_68 = NULL ;
V_21 -> V_54 = NULL ;
F_45 ( & V_21 -> V_25 ) ;
F_7 ( & V_21 -> V_27 ) ;
V_21 -> V_28 = NULL ;
for ( V_57 = 0 ; V_57 < V_21 -> V_58 ; ++ V_57 ) {
V_21 -> V_59 [ V_57 ] . log = NULL ;
V_21 -> V_59 [ V_57 ] . V_60 = NULL ;
V_21 -> V_59 [ V_57 ] . V_63 = NULL ;
V_21 -> V_59 [ V_57 ] . V_21 = V_21 ;
F_44 ( & V_21 -> V_59 [ V_57 ] . V_66 ) ;
F_28 ( V_21 , V_21 -> V_59 + V_57 ) ;
if ( V_21 -> V_59 [ V_57 ] . V_69 )
F_9 ( & V_21 -> V_59 [ V_57 ] . V_5 ,
V_21 -> V_59 [ V_57 ] . V_69 , V_70 , V_21 ) ;
}
return 0 ;
}
long F_46 ( struct V_20 * V_21 )
{
return V_21 -> V_54 == V_71 -> V_54 ? 0 : - V_72 ;
}
static void F_47 ( struct V_12 * V_13 )
{
struct V_73 * V_74 ;
V_74 = F_2 ( V_13 , struct V_73 , V_13 ) ;
V_74 -> V_75 = F_48 ( V_74 -> V_76 , V_71 ) ;
}
static int F_49 ( struct V_20 * V_21 )
{
struct V_73 V_77 ;
V_77 . V_76 = V_71 ;
F_6 ( & V_77 . V_13 , F_47 ) ;
F_22 ( V_21 , & V_77 . V_13 ) ;
F_18 ( V_21 , & V_77 . V_13 ) ;
return V_77 . V_75 ;
}
static long F_50 ( struct V_20 * V_21 )
{
struct V_78 * V_28 ;
int V_79 ;
if ( V_21 -> V_54 ) {
V_79 = - V_80 ;
goto V_81;
}
V_21 -> V_54 = F_51 ( V_71 ) ;
V_28 = F_52 ( F_29 , V_21 , L_1 , V_71 -> V_82 ) ;
if ( F_53 ( V_28 ) ) {
V_79 = F_54 ( V_28 ) ;
goto V_83;
}
V_21 -> V_28 = V_28 ;
F_26 ( V_28 ) ;
V_79 = F_49 ( V_21 ) ;
if ( V_79 )
goto V_84;
V_79 = F_39 ( V_21 ) ;
if ( V_79 )
goto V_84;
return 0 ;
V_84:
F_55 ( V_28 ) ;
V_21 -> V_28 = NULL ;
V_83:
if ( V_21 -> V_54 )
F_56 ( V_21 -> V_54 ) ;
V_21 -> V_54 = NULL ;
V_81:
return V_79 ;
}
long F_57 ( struct V_20 * V_21 )
{
struct V_85 * V_68 ;
V_68 = F_40 ( F_58 ( struct V_85 , V_86 ) , V_62 ) ;
if ( ! V_68 )
return - V_65 ;
F_59 ( V_21 ) ;
V_68 -> V_87 = 0 ;
F_60 ( V_21 -> V_68 , V_68 ) ;
return 0 ;
}
void F_59 ( struct V_20 * V_21 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_21 -> V_58 ; ++ V_57 ) {
if ( V_21 -> V_59 [ V_57 ] . V_48 && V_21 -> V_59 [ V_57 ] . V_69 ) {
F_13 ( & V_21 -> V_59 [ V_57 ] . V_5 ) ;
F_21 ( & V_21 -> V_59 [ V_57 ] . V_5 ) ;
}
if ( V_21 -> V_59 [ V_57 ] . V_47 )
F_61 ( V_21 -> V_59 [ V_57 ] . V_47 ) ;
if ( V_21 -> V_59 [ V_57 ] . error )
F_62 ( V_21 -> V_59 [ V_57 ] . error ) ;
if ( V_21 -> V_59 [ V_57 ] . V_48 )
F_62 ( V_21 -> V_59 [ V_57 ] . V_48 ) ;
if ( V_21 -> V_59 [ V_57 ] . V_49 )
F_61 ( V_21 -> V_59 [ V_57 ] . V_49 ) ;
if ( V_21 -> V_59 [ V_57 ] . V_50 )
F_62 ( V_21 -> V_59 [ V_57 ] . V_50 ) ;
F_28 ( V_21 , V_21 -> V_59 + V_57 ) ;
}
F_42 ( V_21 ) ;
if ( V_21 -> V_51 )
F_61 ( V_21 -> V_51 ) ;
V_21 -> V_51 = NULL ;
if ( V_21 -> V_67 )
F_62 ( V_21 -> V_67 ) ;
V_21 -> V_67 = NULL ;
F_41 ( F_63 ( V_21 -> V_68 ,
F_64 ( & V_21 -> V_66 ) ) ) ;
F_60 ( V_21 -> V_68 , NULL ) ;
F_65 ( ! F_24 ( & V_21 -> V_27 ) ) ;
if ( V_21 -> V_28 ) {
F_55 ( V_21 -> V_28 ) ;
V_21 -> V_28 = NULL ;
}
if ( V_21 -> V_54 )
F_56 ( V_21 -> V_54 ) ;
V_21 -> V_54 = NULL ;
}
static int F_66 ( void T_5 * V_46 , T_6 V_88 , unsigned long V_89 )
{
T_6 V_90 = V_88 / V_91 / 8 ;
if ( V_90 > V_92 - ( unsigned long ) V_46 ||
V_90 + ( unsigned long ) V_46 > V_92 )
return 0 ;
return F_67 ( V_93 , V_46 + V_90 ,
( V_89 + V_91 * 8 - 1 ) / V_91 / 8 ) ;
}
static int F_68 ( void T_5 * V_46 , struct V_85 * V_94 ,
int V_95 )
{
int V_57 ;
if ( ! V_94 )
return 0 ;
for ( V_57 = 0 ; V_57 < V_94 -> V_87 ; ++ V_57 ) {
struct V_96 * V_97 = V_94 -> V_86 + V_57 ;
unsigned long V_90 = V_97 -> V_98 ;
if ( V_97 -> V_99 > V_92 )
return 0 ;
else if ( ! F_67 ( V_93 , ( void T_5 * ) V_90 ,
V_97 -> V_99 ) )
return 0 ;
else if ( V_95 && ! F_66 ( V_46 ,
V_97 -> V_100 ,
V_97 -> V_99 ) )
return 0 ;
}
return 1 ;
}
static int F_69 ( struct V_20 * V_101 , struct V_85 * V_94 ,
int V_95 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_101 -> V_58 ; ++ V_57 ) {
int V_102 ;
F_70 ( & V_101 -> V_59 [ V_57 ] . V_66 ) ;
if ( V_101 -> V_59 [ V_57 ] . V_45 )
V_102 = F_68 ( V_101 -> V_59 [ V_57 ] . V_46 , V_94 ,
V_95 ) ;
else
V_102 = 1 ;
F_71 ( & V_101 -> V_59 [ V_57 ] . V_66 ) ;
if ( ! V_102 )
return 0 ;
}
return 1 ;
}
static int F_72 ( struct V_20 * V_101 , unsigned int V_31 ,
struct V_103 T_5 * V_32 ,
struct V_104 T_5 * V_33 ,
struct V_105 T_5 * V_34 )
{
T_7 V_74 = F_73 ( V_101 , V_106 ) ? 2 : 0 ;
return F_67 ( V_107 , V_32 , V_31 * sizeof *V_32 ) &&
F_67 ( V_107 , V_33 ,
sizeof *V_33 + V_31 * sizeof * V_33 -> V_108 + V_74 ) &&
F_67 ( V_93 , V_34 ,
sizeof *V_34 + V_31 * sizeof * V_34 -> V_108 + V_74 ) ;
}
int F_74 ( struct V_20 * V_21 )
{
struct V_85 * V_109 ;
V_109 = F_63 ( V_21 -> V_68 ,
F_64 ( & V_21 -> V_66 ) ) ;
return F_69 ( V_21 , V_109 , 1 ) ;
}
static int F_75 ( struct V_20 * V_101 , struct V_29 * V_30 ,
void T_5 * V_46 )
{
struct V_85 * V_109 ;
T_7 V_74 = F_73 ( V_101 , V_106 ) ? 2 : 0 ;
V_109 = F_63 ( V_30 -> V_21 -> V_68 ,
F_64 ( & V_30 -> V_66 ) ) ;
return F_68 ( V_46 , V_109 ,
F_73 ( V_30 -> V_21 , V_110 ) ) &&
( ! V_30 -> V_41 || F_66 ( V_46 , V_30 -> V_42 ,
sizeof * V_30 -> V_34 +
V_30 -> V_31 * sizeof * V_30 -> V_34 -> V_108 + V_74 ) ) ;
}
int F_76 ( struct V_29 * V_30 )
{
return F_72 ( V_30 -> V_21 , V_30 -> V_31 , V_30 -> V_32 , V_30 -> V_33 , V_30 -> V_34 ) &&
F_75 ( V_30 -> V_21 , V_30 , V_30 -> V_46 ) ;
}
static long F_77 ( struct V_20 * V_101 , struct V_85 T_5 * V_97 )
{
struct V_85 V_94 , * V_111 , * V_112 ;
unsigned long V_113 = F_58 ( struct V_85 , V_86 ) ;
if ( F_78 ( & V_94 , V_97 , V_113 ) )
return - V_114 ;
if ( V_94 . V_115 )
return - V_116 ;
if ( V_94 . V_87 > V_117 )
return - V_118 ;
V_111 = F_40 ( V_113 + V_94 . V_87 * sizeof * V_97 -> V_86 , V_62 ) ;
if ( ! V_111 )
return - V_65 ;
memcpy ( V_111 , & V_94 , V_113 ) ;
if ( F_78 ( V_111 -> V_86 , V_97 -> V_86 ,
V_94 . V_87 * sizeof * V_97 -> V_86 ) ) {
F_41 ( V_111 ) ;
return - V_114 ;
}
if ( ! F_69 ( V_101 , V_111 ,
F_73 ( V_101 , V_110 ) ) ) {
F_41 ( V_111 ) ;
return - V_114 ;
}
V_112 = F_63 ( V_101 -> V_68 ,
F_64 ( & V_101 -> V_66 ) ) ;
F_79 ( V_101 -> V_68 , V_111 ) ;
F_80 () ;
F_41 ( V_112 ) ;
return 0 ;
}
static int F_81 ( struct V_29 * V_30 ,
struct V_105 T_5 * V_34 )
{
int V_119 = F_82 ( V_30 -> V_40 , & V_34 -> V_26 ) ;
if ( V_119 )
return V_119 ;
V_30 -> V_39 = false ;
return F_83 ( V_30 -> V_37 , & V_34 -> V_120 ) ;
}
static long F_84 ( struct V_20 * V_101 , int V_121 , void T_5 * V_122 )
{
struct V_1 * V_123 , * V_124 = NULL ,
* V_125 = NULL , * V_126 = NULL ;
struct V_127 * V_128 = NULL ;
T_8 T_5 * V_129 = V_122 ;
struct V_29 * V_30 ;
struct V_130 V_74 ;
struct V_131 V_132 ;
struct V_133 V_90 ;
T_8 V_120 ;
long V_119 ;
V_119 = F_83 ( V_120 , V_129 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_120 >= V_101 -> V_58 )
return - V_134 ;
V_30 = V_101 -> V_59 + V_120 ;
F_70 ( & V_30 -> V_66 ) ;
switch ( V_121 ) {
case V_135 :
if ( V_30 -> V_45 ) {
V_119 = - V_80 ;
break;
}
if ( F_78 ( & V_74 , V_122 , sizeof V_74 ) ) {
V_119 = - V_114 ;
break;
}
if ( ! V_74 . V_31 || V_74 . V_31 > 0xffff || ( V_74 . V_31 & ( V_74 . V_31 - 1 ) ) ) {
V_119 = - V_136 ;
break;
}
V_30 -> V_31 = V_74 . V_31 ;
break;
case V_137 :
if ( V_30 -> V_45 ) {
V_119 = - V_80 ;
break;
}
if ( F_78 ( & V_74 , V_122 , sizeof V_74 ) ) {
V_119 = - V_114 ;
break;
}
if ( V_74 . V_31 > 0xffff ) {
V_119 = - V_136 ;
break;
}
V_30 -> V_35 = V_74 . V_31 ;
V_30 -> V_36 = V_30 -> V_35 ;
break;
case V_138 :
V_74 . V_139 = V_120 ;
V_74 . V_31 = V_30 -> V_35 ;
if ( F_85 ( V_122 , & V_74 , sizeof V_74 ) )
V_119 = - V_114 ;
break;
case V_140 :
if ( F_78 ( & V_90 , V_122 , sizeof V_90 ) ) {
V_119 = - V_114 ;
break;
}
if ( V_90 . V_26 & ~ ( 0x1 << V_141 ) ) {
V_119 = - V_116 ;
break;
}
if ( ( T_6 ) ( unsigned long ) V_90 . V_142 != V_90 . V_142 ||
( T_6 ) ( unsigned long ) V_90 . V_143 != V_90 . V_143 ||
( T_6 ) ( unsigned long ) V_90 . V_144 != V_90 . V_144 ) {
V_119 = - V_114 ;
break;
}
if ( ( V_90 . V_144 & ( sizeof * V_30 -> V_33 -> V_108 - 1 ) ) ||
( V_90 . V_143 & ( sizeof * V_30 -> V_34 -> V_108 - 1 ) ) ||
( V_90 . V_145 & ( sizeof * V_30 -> V_34 -> V_108 - 1 ) ) ) {
V_119 = - V_136 ;
break;
}
if ( V_30 -> V_45 ) {
if ( ! F_72 ( V_101 , V_30 -> V_31 ,
( void T_5 * ) ( unsigned long ) V_90 . V_142 ,
( void T_5 * ) ( unsigned long ) V_90 . V_144 ,
( void T_5 * ) ( unsigned long ) V_90 . V_143 ) ) {
V_119 = - V_136 ;
break;
}
if ( ( V_90 . V_26 & ( 0x1 << V_141 ) ) &&
! F_66 ( V_30 -> V_46 , V_90 . V_145 ,
sizeof * V_30 -> V_34 +
V_30 -> V_31 * sizeof * V_30 -> V_34 -> V_108 ) ) {
V_119 = - V_136 ;
break;
}
}
V_119 = F_81 ( V_30 , (struct V_105 T_5 * ) ( unsigned long )
V_90 . V_143 ) ;
if ( V_119 )
break;
V_30 -> V_41 = ! ! ( V_90 . V_26 & ( 0x1 << V_141 ) ) ;
V_30 -> V_32 = ( void T_5 * ) ( unsigned long ) V_90 . V_142 ;
V_30 -> V_33 = ( void T_5 * ) ( unsigned long ) V_90 . V_144 ;
V_30 -> V_42 = V_90 . V_145 ;
V_30 -> V_34 = ( void T_5 * ) ( unsigned long ) V_90 . V_143 ;
break;
case V_146 :
if ( F_78 ( & V_132 , V_122 , sizeof V_132 ) ) {
V_119 = - V_114 ;
break;
}
V_123 = V_132 . V_147 == - 1 ? NULL : F_86 ( V_132 . V_147 ) ;
if ( F_53 ( V_123 ) ) {
V_119 = F_54 ( V_123 ) ;
break;
}
if ( V_123 != V_30 -> V_48 ) {
V_126 = V_124 = V_30 -> V_48 ;
V_125 = V_30 -> V_48 = V_123 ;
} else
V_124 = V_123 ;
break;
case V_148 :
if ( F_78 ( & V_132 , V_122 , sizeof V_132 ) ) {
V_119 = - V_114 ;
break;
}
V_123 = V_132 . V_147 == - 1 ? NULL : F_86 ( V_132 . V_147 ) ;
if ( F_53 ( V_123 ) ) {
V_119 = F_54 ( V_123 ) ;
break;
}
if ( V_123 != V_30 -> V_50 ) {
V_124 = V_30 -> V_50 ;
V_128 = V_30 -> V_49 ;
V_30 -> V_50 = V_123 ;
V_30 -> V_49 = V_123 ?
F_87 ( V_123 ) : NULL ;
} else
V_124 = V_123 ;
break;
case V_149 :
if ( F_78 ( & V_132 , V_122 , sizeof V_132 ) ) {
V_119 = - V_114 ;
break;
}
V_123 = V_132 . V_147 == - 1 ? NULL : F_86 ( V_132 . V_147 ) ;
if ( F_53 ( V_123 ) ) {
V_119 = F_54 ( V_123 ) ;
break;
}
if ( V_123 != V_30 -> error ) {
V_124 = V_30 -> error ;
V_30 -> error = V_123 ;
V_128 = V_30 -> V_47 ;
V_30 -> V_47 = V_123 ?
F_87 ( V_123 ) : NULL ;
} else
V_124 = V_123 ;
break;
default:
V_119 = - V_150 ;
}
if ( V_126 && V_30 -> V_69 )
F_13 ( & V_30 -> V_5 ) ;
if ( V_128 )
F_61 ( V_128 ) ;
if ( V_124 )
F_62 ( V_124 ) ;
if ( V_125 && V_30 -> V_69 )
F_12 ( & V_30 -> V_5 , V_30 -> V_48 ) ;
F_71 ( & V_30 -> V_66 ) ;
if ( V_126 && V_30 -> V_69 )
F_21 ( & V_30 -> V_5 ) ;
return V_119 ;
}
long F_88 ( struct V_20 * V_101 , unsigned int V_121 , unsigned long V_151 )
{
void T_5 * V_122 = ( void T_5 * ) V_151 ;
struct V_1 * V_123 , * V_124 = NULL ;
struct V_127 * V_128 = NULL ;
T_6 V_152 ;
long V_119 ;
int V_57 , V_147 ;
if ( V_121 == V_153 ) {
V_119 = F_50 ( V_101 ) ;
goto V_16;
}
V_119 = F_46 ( V_101 ) ;
if ( V_119 )
goto V_16;
switch ( V_121 ) {
case V_154 :
V_119 = F_77 ( V_101 , V_122 ) ;
break;
case V_155 :
if ( F_78 ( & V_152 , V_122 , sizeof V_152 ) ) {
V_119 = - V_114 ;
break;
}
if ( ( T_6 ) ( unsigned long ) V_152 != V_152 ) {
V_119 = - V_114 ;
break;
}
for ( V_57 = 0 ; V_57 < V_101 -> V_58 ; ++ V_57 ) {
struct V_29 * V_30 ;
void T_5 * V_156 = ( void T_5 * ) ( unsigned long ) V_152 ;
V_30 = V_101 -> V_59 + V_57 ;
F_70 ( & V_30 -> V_66 ) ;
if ( V_30 -> V_45 && ! F_75 ( V_101 , V_30 , V_156 ) )
V_119 = - V_114 ;
else
V_30 -> V_46 = V_156 ;
F_71 ( & V_30 -> V_66 ) ;
}
break;
case V_157 :
V_119 = F_83 ( V_147 , ( int T_5 * ) V_122 ) ;
if ( V_119 < 0 )
break;
V_123 = V_147 == - 1 ? NULL : F_86 ( V_147 ) ;
if ( F_53 ( V_123 ) ) {
V_119 = F_54 ( V_123 ) ;
break;
}
if ( V_123 != V_101 -> V_67 ) {
V_124 = V_101 -> V_67 ;
V_128 = V_101 -> V_51 ;
V_101 -> V_51 = V_123 ?
F_87 ( V_123 ) : NULL ;
} else
V_124 = V_123 ;
for ( V_57 = 0 ; V_57 < V_101 -> V_58 ; ++ V_57 ) {
F_70 ( & V_101 -> V_59 [ V_57 ] . V_66 ) ;
V_101 -> V_59 [ V_57 ] . V_51 = V_101 -> V_51 ;
F_71 ( & V_101 -> V_59 [ V_57 ] . V_66 ) ;
}
if ( V_128 )
F_61 ( V_128 ) ;
if ( V_124 )
F_62 ( V_124 ) ;
break;
default:
V_119 = F_84 ( V_101 , V_121 , V_122 ) ;
break;
}
V_16:
return V_119 ;
}
static const struct V_96 * F_89 ( struct V_85 * V_94 ,
T_9 V_88 , T_10 V_158 )
{
struct V_96 * V_159 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_94 -> V_87 ; ++ V_57 ) {
V_159 = V_94 -> V_86 + V_57 ;
if ( V_159 -> V_100 <= V_88 &&
V_159 -> V_100 + V_159 -> V_99 - 1 >= V_88 )
return V_159 ;
}
return NULL ;
}
static int F_90 ( int V_160 , void T_5 * V_88 )
{
unsigned long log = ( unsigned long ) V_88 ;
struct V_161 * V_161 ;
void * V_156 ;
int V_162 = V_160 + ( log % V_163 ) * 8 ;
int V_119 ;
V_119 = F_91 ( log , 1 , 1 , & V_161 ) ;
if ( V_119 < 0 )
return V_119 ;
F_20 ( V_119 != 1 ) ;
V_156 = F_92 ( V_161 , V_164 ) ;
F_93 ( V_162 , V_156 ) ;
F_94 ( V_156 , V_164 ) ;
F_95 ( V_161 ) ;
F_96 ( V_161 ) ;
return 0 ;
}
static int F_97 ( void T_5 * V_46 ,
T_6 V_165 , T_6 V_166 )
{
T_6 V_167 = V_165 / V_91 ;
int V_119 ;
if ( ! V_166 )
return 0 ;
V_166 += V_165 % V_91 ;
for (; ; ) {
T_6 V_156 = ( T_6 ) ( unsigned long ) V_46 ;
T_6 log = V_156 + V_167 / 8 ;
int V_162 = V_167 % 8 ;
if ( ( T_6 ) ( unsigned long ) log != log )
return - V_114 ;
V_119 = F_90 ( V_162 , ( void T_5 * ) ( unsigned long ) log ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_166 <= V_91 )
break;
V_166 -= V_91 ;
V_167 += 1 ;
}
return V_119 ;
}
int F_98 ( struct V_29 * V_30 , struct V_168 * log ,
unsigned int V_169 , T_6 V_158 )
{
int V_57 , V_119 ;
F_99 () ;
for ( V_57 = 0 ; V_57 < V_169 ; ++ V_57 ) {
T_6 V_170 = F_100 ( log [ V_57 ] . V_158 , V_158 ) ;
V_119 = F_97 ( V_30 -> V_46 , log [ V_57 ] . V_88 , V_170 ) ;
if ( V_119 < 0 )
return V_119 ;
V_158 -= V_170 ;
if ( ! V_158 ) {
if ( V_30 -> V_51 )
F_101 ( V_30 -> V_51 , 1 ) ;
return 0 ;
}
}
F_102 () ;
return 0 ;
}
static int F_103 ( struct V_20 * V_21 , T_6 V_88 , T_8 V_158 ,
struct V_171 V_172 [] , int V_173 )
{
const struct V_96 * V_159 ;
struct V_85 * V_94 ;
struct V_171 * V_174 ;
T_6 V_74 = 0 ;
int V_75 = 0 ;
F_104 () ;
V_94 = F_105 ( V_21 -> V_68 ) ;
while ( ( T_6 ) V_158 > V_74 ) {
T_6 V_113 ;
if ( F_106 ( V_75 >= V_173 ) ) {
V_75 = - V_134 ;
break;
}
V_159 = F_89 ( V_94 , V_88 , V_158 ) ;
if ( F_106 ( ! V_159 ) ) {
V_75 = - V_114 ;
break;
}
V_174 = V_172 + V_75 ;
V_113 = V_159 -> V_99 - V_88 + V_159 -> V_100 ;
V_174 -> V_175 = F_100 ( ( T_6 ) V_158 , V_113 ) ;
V_174 -> V_176 = ( void T_5 * ) ( unsigned long )
( V_159 -> V_98 + V_88 - V_159 -> V_100 ) ;
V_74 += V_113 ;
V_88 += V_113 ;
++ V_75 ;
}
F_107 () ;
return V_75 ;
}
static unsigned F_108 ( struct V_103 * V_32 )
{
unsigned int V_177 ;
if ( ! ( V_32 -> V_26 & V_178 ) )
return - 1U ;
V_177 = V_32 -> V_177 ;
F_109 () ;
return V_177 ;
}
static int F_110 ( struct V_20 * V_21 , struct V_29 * V_30 ,
struct V_171 V_172 [] , unsigned int V_173 ,
unsigned int * V_179 , unsigned int * V_180 ,
struct V_168 * log , unsigned int * V_169 ,
struct V_103 * V_60 )
{
struct V_103 V_32 ;
unsigned int V_57 = 0 , V_181 , V_182 = 0 ;
int V_75 ;
if ( F_106 ( V_60 -> V_158 % sizeof V_32 ) ) {
F_111 ( V_30 , L_2
L_3 ,
( unsigned long long ) V_60 -> V_158 ,
sizeof V_32 ) ;
return - V_136 ;
}
V_75 = F_103 ( V_21 , V_60 -> V_88 , V_60 -> V_158 , V_30 -> V_60 ,
V_61 ) ;
if ( F_106 ( V_75 < 0 ) ) {
F_111 ( V_30 , L_4 , V_75 ) ;
return V_75 ;
}
F_109 () ;
V_181 = V_60 -> V_158 / sizeof V_32 ;
if ( F_106 ( V_181 > V_183 + 1 ) ) {
F_111 ( V_30 , L_5 ,
V_60 -> V_158 ) ;
return - V_118 ;
}
do {
unsigned V_184 = * V_180 + * V_179 ;
if ( F_106 ( ++ V_182 > V_181 ) ) {
F_111 ( V_30 , L_6
L_7 ,
V_57 , V_181 ) ;
return - V_136 ;
}
if ( F_106 ( F_112 ( ( unsigned char * ) & V_32 ,
V_30 -> V_60 , sizeof V_32 ) ) ) {
F_111 ( V_30 , L_8 ,
V_57 , ( T_7 ) V_60 -> V_88 + V_57 * sizeof V_32 ) ;
return - V_136 ;
}
if ( F_106 ( V_32 . V_26 & V_185 ) ) {
F_111 ( V_30 , L_9 ,
V_57 , ( T_7 ) V_60 -> V_88 + V_57 * sizeof V_32 ) ;
return - V_136 ;
}
V_75 = F_103 ( V_21 , V_32 . V_88 , V_32 . V_158 , V_172 + V_184 ,
V_173 - V_184 ) ;
if ( F_106 ( V_75 < 0 ) ) {
F_111 ( V_30 , L_10 ,
V_75 , V_57 ) ;
return V_75 ;
}
if ( V_32 . V_26 & V_186 ) {
* V_180 += V_75 ;
if ( F_106 ( log ) ) {
log [ * V_169 ] . V_88 = V_32 . V_88 ;
log [ * V_169 ] . V_158 = V_32 . V_158 ;
++ * V_169 ;
}
} else {
if ( F_106 ( * V_180 ) ) {
F_111 ( V_30 , L_11
L_12 , V_57 ) ;
return - V_136 ;
}
* V_179 += V_75 ;
}
} while ( ( V_57 = F_108 ( & V_32 ) ) != - 1 );
return 0 ;
}
int F_113 ( struct V_20 * V_21 , struct V_29 * V_30 ,
struct V_171 V_172 [] , unsigned int V_173 ,
unsigned int * V_179 , unsigned int * V_180 ,
struct V_168 * log , unsigned int * V_169 )
{
struct V_103 V_32 ;
unsigned int V_57 , V_187 , V_182 = 0 ;
T_11 V_35 ;
int V_75 ;
V_35 = V_30 -> V_35 ;
if ( F_106 ( F_114 ( V_30 -> V_36 , & V_30 -> V_33 -> V_120 ) ) ) {
F_111 ( V_30 , L_13 ,
& V_30 -> V_33 -> V_120 ) ;
return - V_114 ;
}
if ( F_106 ( ( T_11 ) ( V_30 -> V_36 - V_35 ) > V_30 -> V_31 ) ) {
F_111 ( V_30 , L_14 ,
V_35 , V_30 -> V_36 ) ;
return - V_114 ;
}
if ( V_30 -> V_36 == V_35 )
return V_30 -> V_31 ;
F_115 () ;
if ( F_106 ( F_114 ( V_187 ,
& V_30 -> V_33 -> V_108 [ V_35 % V_30 -> V_31 ] ) ) ) {
F_111 ( V_30 , L_15 ,
V_35 ,
& V_30 -> V_33 -> V_108 [ V_35 % V_30 -> V_31 ] ) ;
return - V_114 ;
}
if ( F_106 ( V_187 >= V_30 -> V_31 ) ) {
F_111 ( V_30 , L_16 ,
V_187 , V_30 -> V_31 ) ;
return - V_136 ;
}
* V_179 = * V_180 = 0 ;
if ( F_106 ( log ) )
* V_169 = 0 ;
V_57 = V_187 ;
do {
unsigned V_184 = * V_180 + * V_179 ;
if ( F_106 ( V_57 >= V_30 -> V_31 ) ) {
F_111 ( V_30 , L_17 ,
V_57 , V_30 -> V_31 , V_187 ) ;
return - V_136 ;
}
if ( F_106 ( ++ V_182 > V_30 -> V_31 ) ) {
F_111 ( V_30 , L_6
L_18 ,
V_57 , V_30 -> V_31 , V_187 ) ;
return - V_136 ;
}
V_75 = F_116 ( & V_32 , V_30 -> V_32 + V_57 , sizeof V_32 ) ;
if ( F_106 ( V_75 ) ) {
F_111 ( V_30 , L_19 ,
V_57 , V_30 -> V_32 + V_57 ) ;
return - V_114 ;
}
if ( V_32 . V_26 & V_185 ) {
V_75 = F_110 ( V_21 , V_30 , V_172 , V_173 ,
V_179 , V_180 ,
log , V_169 , & V_32 ) ;
if ( F_106 ( V_75 < 0 ) ) {
F_111 ( V_30 , L_20
L_21 , V_57 ) ;
return V_75 ;
}
continue;
}
V_75 = F_103 ( V_21 , V_32 . V_88 , V_32 . V_158 , V_172 + V_184 ,
V_173 - V_184 ) ;
if ( F_106 ( V_75 < 0 ) ) {
F_111 ( V_30 , L_22 ,
V_75 , V_57 ) ;
return V_75 ;
}
if ( V_32 . V_26 & V_186 ) {
* V_180 += V_75 ;
if ( F_106 ( log ) ) {
log [ * V_169 ] . V_88 = V_32 . V_88 ;
log [ * V_169 ] . V_158 = V_32 . V_158 ;
++ * V_169 ;
}
} else {
if ( F_106 ( * V_180 ) ) {
F_111 ( V_30 , L_23
L_24 , V_57 ) ;
return - V_136 ;
}
* V_179 += V_75 ;
}
} while ( ( V_57 = F_108 ( & V_32 ) ) != - 1 );
V_30 -> V_35 ++ ;
F_20 ( ! ( V_30 -> V_40 & V_188 ) ) ;
return V_187 ;
}
void F_117 ( struct V_29 * V_30 , int V_189 )
{
V_30 -> V_35 -= V_189 ;
}
int F_118 ( struct V_29 * V_30 , unsigned int V_187 , int V_158 )
{
struct V_190 T_5 * V_34 ;
V_34 = & V_30 -> V_34 -> V_108 [ V_30 -> V_37 % V_30 -> V_31 ] ;
if ( F_119 ( V_187 , & V_34 -> V_191 ) ) {
F_111 ( V_30 , L_25 ) ;
return - V_114 ;
}
if ( F_119 ( V_158 , & V_34 -> V_158 ) ) {
F_111 ( V_30 , L_26 ) ;
return - V_114 ;
}
F_99 () ;
if ( F_119 ( V_30 -> V_37 + 1 , & V_30 -> V_34 -> V_120 ) ) {
F_111 ( V_30 , L_27 ) ;
return - V_114 ;
}
if ( F_106 ( V_30 -> V_41 ) ) {
F_99 () ;
F_97 ( V_30 -> V_46 ,
V_30 -> V_42 +
( ( void T_5 * ) V_34 - ( void T_5 * ) V_30 -> V_34 ) ,
sizeof *V_34 ) ;
F_97 ( V_30 -> V_46 ,
V_30 -> V_42 + F_58 ( struct V_105 , V_120 ) ,
sizeof V_30 -> V_34 -> V_120 ) ;
if ( V_30 -> V_51 )
F_101 ( V_30 -> V_51 , 1 ) ;
}
V_30 -> V_37 ++ ;
if ( F_106 ( V_30 -> V_37 == V_30 -> V_38 ) )
V_30 -> V_39 = false ;
return 0 ;
}
static int F_120 ( struct V_29 * V_30 ,
struct V_190 * V_63 ,
unsigned V_181 )
{
struct V_190 T_5 * V_34 ;
T_11 V_192 , V_193 ;
int V_194 ;
V_194 = V_30 -> V_37 % V_30 -> V_31 ;
V_34 = V_30 -> V_34 -> V_108 + V_194 ;
if ( F_121 ( V_34 , V_63 , V_181 * sizeof *V_34 ) ) {
F_111 ( V_30 , L_28 ) ;
return - V_114 ;
}
if ( F_106 ( V_30 -> V_41 ) ) {
F_99 () ;
F_97 ( V_30 -> V_46 ,
V_30 -> V_42 +
( ( void T_5 * ) V_34 - ( void T_5 * ) V_30 -> V_34 ) ,
V_181 * sizeof *V_34 ) ;
}
V_192 = V_30 -> V_37 ;
V_193 = ( V_30 -> V_37 += V_181 ) ;
if ( F_106 ( ( T_11 ) ( V_193 - V_30 -> V_38 ) < ( T_11 ) ( V_193 - V_192 ) ) )
V_30 -> V_39 = false ;
return 0 ;
}
int F_122 ( struct V_29 * V_30 , struct V_190 * V_63 ,
unsigned V_181 )
{
int V_194 , V_189 , V_119 ;
V_194 = V_30 -> V_37 % V_30 -> V_31 ;
V_189 = V_30 -> V_31 - V_194 ;
if ( V_189 < V_181 ) {
V_119 = F_120 ( V_30 , V_63 , V_189 ) ;
if ( V_119 < 0 )
return V_119 ;
V_63 += V_189 ;
V_181 -= V_189 ;
}
V_119 = F_120 ( V_30 , V_63 , V_181 ) ;
F_99 () ;
if ( F_82 ( V_30 -> V_37 , & V_30 -> V_34 -> V_120 ) ) {
F_111 ( V_30 , L_27 ) ;
return - V_114 ;
}
if ( F_106 ( V_30 -> V_41 ) ) {
F_97 ( V_30 -> V_46 ,
V_30 -> V_42 + F_58 ( struct V_105 , V_120 ) ,
sizeof V_30 -> V_34 -> V_120 ) ;
if ( V_30 -> V_51 )
F_101 ( V_30 -> V_51 , 1 ) ;
}
return V_119 ;
}
static bool F_123 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
T_12 V_192 , V_193 , V_195 ;
bool V_196 ;
F_124 () ;
if ( F_73 ( V_21 , V_197 ) &&
F_106 ( V_30 -> V_36 == V_30 -> V_35 ) )
return true ;
if ( ! F_73 ( V_21 , V_106 ) ) {
T_12 V_26 ;
if ( F_114 ( V_26 , & V_30 -> V_33 -> V_26 ) ) {
F_111 ( V_30 , L_29 ) ;
return true ;
}
return ! ( V_26 & V_198 ) ;
}
V_192 = V_30 -> V_38 ;
V_196 = V_30 -> V_39 ;
V_193 = V_30 -> V_38 = V_30 -> V_37 ;
V_30 -> V_39 = true ;
if ( F_106 ( ! V_196 ) )
return true ;
if ( F_83 ( V_195 , F_125 ( V_30 ) ) ) {
F_111 ( V_30 , L_30 ) ;
return true ;
}
return F_126 ( V_195 , V_193 , V_192 ) ;
}
void F_127 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
if ( V_30 -> V_49 && F_123 ( V_21 , V_30 ) )
F_101 ( V_30 -> V_49 , 1 ) ;
}
void F_128 ( struct V_20 * V_21 ,
struct V_29 * V_30 ,
unsigned int V_187 , int V_158 )
{
F_118 ( V_30 , V_187 , V_158 ) ;
F_127 ( V_21 , V_30 ) ;
}
void F_129 ( struct V_20 * V_21 ,
struct V_29 * V_30 ,
struct V_190 * V_63 , unsigned V_181 )
{
F_122 ( V_30 , V_63 , V_181 ) ;
F_127 ( V_21 , V_30 ) ;
}
bool F_130 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
T_11 V_36 ;
int V_119 ;
if ( ! ( V_30 -> V_40 & V_188 ) )
return false ;
V_30 -> V_40 &= ~ V_188 ;
if ( ! F_73 ( V_21 , V_106 ) ) {
V_119 = F_82 ( V_30 -> V_40 , & V_30 -> V_34 -> V_26 ) ;
if ( V_119 ) {
F_111 ( V_30 , L_31 ,
& V_30 -> V_34 -> V_26 , V_119 ) ;
return false ;
}
} else {
V_119 = F_82 ( V_30 -> V_36 , F_131 ( V_30 ) ) ;
if ( V_119 ) {
F_111 ( V_30 , L_32 ,
F_131 ( V_30 ) , V_119 ) ;
return false ;
}
}
if ( F_106 ( V_30 -> V_41 ) ) {
void T_5 * V_34 ;
F_99 () ;
V_34 = F_73 ( V_21 , V_106 ) ?
& V_30 -> V_34 -> V_26 : F_131 ( V_30 ) ;
F_97 ( V_30 -> V_46 , V_30 -> V_42 +
( V_34 - ( void T_5 * ) V_30 -> V_34 ) ,
sizeof( T_11 ) ) ;
if ( V_30 -> V_51 )
F_101 ( V_30 -> V_51 , 1 ) ;
}
F_124 () ;
V_119 = F_114 ( V_36 , & V_30 -> V_33 -> V_120 ) ;
if ( V_119 ) {
F_111 ( V_30 , L_33 ,
& V_30 -> V_33 -> V_120 , V_119 ) ;
return false ;
}
return V_36 != V_30 -> V_36 ;
}
void F_132 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
int V_119 ;
if ( V_30 -> V_40 & V_188 )
return;
V_30 -> V_40 |= V_188 ;
if ( ! F_73 ( V_21 , V_106 ) ) {
V_119 = F_82 ( V_30 -> V_40 , & V_30 -> V_34 -> V_26 ) ;
if ( V_119 )
F_111 ( V_30 , L_31 ,
& V_30 -> V_34 -> V_26 , V_119 ) ;
}
}
