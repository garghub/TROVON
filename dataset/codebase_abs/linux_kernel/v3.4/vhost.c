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
V_30 -> V_52 = 0 ;
V_30 -> V_53 = 0 ;
V_30 -> V_54 = NULL ;
}
static int F_29 ( void * V_55 )
{
struct V_20 * V_21 = V_55 ;
struct V_12 * V_13 = NULL ;
unsigned V_56 ( V_23 ) ;
F_30 ( V_21 -> V_57 ) ;
for (; ; ) {
F_31 ( V_58 ) ;
F_16 ( & V_21 -> V_25 ) ;
if ( V_13 ) {
V_13 -> V_19 = V_23 ;
if ( V_13 -> V_17 )
F_32 ( & V_13 -> V_16 ) ;
}
if ( F_33 () ) {
F_17 ( & V_21 -> V_25 ) ;
F_34 ( V_59 ) ;
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
F_34 ( V_59 ) ;
V_13 -> V_14 ( V_13 ) ;
if ( F_37 () )
F_38 () ;
} else
F_38 () ;
}
F_39 ( V_21 -> V_57 ) ;
return 0 ;
}
static void F_40 ( struct V_29 * V_30 )
{
F_41 ( V_30 -> V_60 ) ;
V_30 -> V_60 = NULL ;
F_41 ( V_30 -> log ) ;
V_30 -> log = NULL ;
F_41 ( V_30 -> V_61 ) ;
V_30 -> V_61 = NULL ;
F_41 ( V_30 -> V_62 ) ;
V_30 -> V_62 = NULL ;
}
void F_42 ( int V_30 )
{
V_63 |= 0x1 << V_30 ;
}
static long F_43 ( struct V_20 * V_21 )
{
int V_64 ;
bool V_65 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_66 ; ++ V_64 ) {
V_21 -> V_67 [ V_64 ] . V_60 = F_44 ( sizeof * V_21 -> V_67 [ V_64 ] . V_60 *
V_68 , V_69 ) ;
V_21 -> V_67 [ V_64 ] . log = F_44 ( sizeof * V_21 -> V_67 [ V_64 ] . log * V_68 ,
V_69 ) ;
V_21 -> V_67 [ V_64 ] . V_61 = F_44 ( sizeof * V_21 -> V_67 [ V_64 ] . V_61 *
V_68 , V_69 ) ;
V_65 = V_63 & ( 0x1 << V_64 ) ;
if ( V_65 )
V_21 -> V_67 [ V_64 ] . V_62 =
F_44 ( sizeof * V_21 -> V_67 [ V_64 ] . V_62 *
V_68 , V_69 ) ;
if ( ! V_21 -> V_67 [ V_64 ] . V_60 || ! V_21 -> V_67 [ V_64 ] . log ||
! V_21 -> V_67 [ V_64 ] . V_61 ||
( V_65 && ! V_21 -> V_67 [ V_64 ] . V_62 ) )
goto V_70;
}
return 0 ;
V_70:
for (; V_64 >= 0 ; -- V_64 )
F_40 ( & V_21 -> V_67 [ V_64 ] ) ;
return - V_71 ;
}
static void F_45 ( struct V_20 * V_21 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_66 ; ++ V_64 )
F_40 ( & V_21 -> V_67 [ V_64 ] ) ;
}
long F_46 ( struct V_20 * V_21 ,
struct V_29 * V_67 , int V_66 )
{
int V_64 ;
V_21 -> V_67 = V_67 ;
V_21 -> V_66 = V_66 ;
F_47 ( & V_21 -> V_72 ) ;
V_21 -> V_51 = NULL ;
V_21 -> V_73 = NULL ;
V_21 -> V_74 = NULL ;
V_21 -> V_57 = NULL ;
F_48 ( & V_21 -> V_25 ) ;
F_7 ( & V_21 -> V_27 ) ;
V_21 -> V_28 = NULL ;
for ( V_64 = 0 ; V_64 < V_21 -> V_66 ; ++ V_64 ) {
V_21 -> V_67 [ V_64 ] . log = NULL ;
V_21 -> V_67 [ V_64 ] . V_60 = NULL ;
V_21 -> V_67 [ V_64 ] . V_61 = NULL ;
V_21 -> V_67 [ V_64 ] . V_62 = NULL ;
V_21 -> V_67 [ V_64 ] . V_21 = V_21 ;
F_47 ( & V_21 -> V_67 [ V_64 ] . V_72 ) ;
F_28 ( V_21 , V_21 -> V_67 + V_64 ) ;
if ( V_21 -> V_67 [ V_64 ] . V_75 )
F_9 ( & V_21 -> V_67 [ V_64 ] . V_5 ,
V_21 -> V_67 [ V_64 ] . V_75 , V_76 , V_21 ) ;
}
return 0 ;
}
long F_49 ( struct V_20 * V_21 )
{
return V_21 -> V_57 == V_77 -> V_57 ? 0 : - V_78 ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_79 * V_80 ;
V_80 = F_2 ( V_13 , struct V_79 , V_13 ) ;
V_80 -> V_81 = F_51 ( V_80 -> V_82 , V_77 ) ;
}
static int F_52 ( struct V_20 * V_21 )
{
struct V_79 V_83 ;
V_83 . V_82 = V_77 ;
F_6 ( & V_83 . V_13 , F_50 ) ;
F_22 ( V_21 , & V_83 . V_13 ) ;
F_18 ( V_21 , & V_83 . V_13 ) ;
return V_83 . V_81 ;
}
static long F_53 ( struct V_20 * V_21 )
{
struct V_84 * V_28 ;
int V_85 ;
if ( V_21 -> V_57 ) {
V_85 = - V_86 ;
goto V_87;
}
V_21 -> V_57 = F_54 ( V_77 ) ;
V_28 = F_55 ( F_29 , V_21 , L_1 , V_77 -> V_88 ) ;
if ( F_56 ( V_28 ) ) {
V_85 = F_57 ( V_28 ) ;
goto V_89;
}
V_21 -> V_28 = V_28 ;
F_26 ( V_28 ) ;
V_85 = F_52 ( V_21 ) ;
if ( V_85 )
goto V_90;
V_85 = F_43 ( V_21 ) ;
if ( V_85 )
goto V_90;
return 0 ;
V_90:
F_58 ( V_28 ) ;
V_21 -> V_28 = NULL ;
V_89:
if ( V_21 -> V_57 )
F_59 ( V_21 -> V_57 ) ;
V_21 -> V_57 = NULL ;
V_87:
return V_85 ;
}
long F_60 ( struct V_20 * V_21 )
{
struct V_91 * V_74 ;
V_74 = F_44 ( F_61 ( struct V_91 , V_92 ) , V_69 ) ;
if ( ! V_74 )
return - V_71 ;
F_62 ( V_21 , true ) ;
V_74 -> V_93 = 0 ;
F_63 ( V_21 -> V_74 , V_74 ) ;
return 0 ;
}
int F_64 ( struct V_29 * V_30 )
{
int V_64 ;
int V_94 = 0 ;
for ( V_64 = V_30 -> V_53 ; V_64 != V_30 -> V_52 ; V_64 = ( V_64 + 1 ) % V_68 ) {
if ( ( V_30 -> V_61 [ V_64 ] . V_95 == V_96 ) ) {
V_30 -> V_61 [ V_64 ] . V_95 = V_97 ;
F_65 ( V_30 -> V_21 , V_30 ,
V_30 -> V_61 [ V_64 ] . V_98 , 0 ) ;
++ V_94 ;
} else
break;
}
if ( V_94 )
V_30 -> V_53 = V_64 ;
return V_94 ;
}
void F_62 ( struct V_20 * V_21 , bool V_99 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_21 -> V_66 ; ++ V_64 ) {
if ( V_21 -> V_67 [ V_64 ] . V_48 && V_21 -> V_67 [ V_64 ] . V_75 ) {
F_13 ( & V_21 -> V_67 [ V_64 ] . V_5 ) ;
F_21 ( & V_21 -> V_67 [ V_64 ] . V_5 ) ;
}
if ( V_21 -> V_67 [ V_64 ] . V_54 )
F_66 ( V_21 -> V_67 [ V_64 ] . V_54 ) ;
F_64 ( & V_21 -> V_67 [ V_64 ] ) ;
if ( V_21 -> V_67 [ V_64 ] . V_47 )
F_67 ( V_21 -> V_67 [ V_64 ] . V_47 ) ;
if ( V_21 -> V_67 [ V_64 ] . error )
F_68 ( V_21 -> V_67 [ V_64 ] . error ) ;
if ( V_21 -> V_67 [ V_64 ] . V_48 )
F_68 ( V_21 -> V_67 [ V_64 ] . V_48 ) ;
if ( V_21 -> V_67 [ V_64 ] . V_49 )
F_67 ( V_21 -> V_67 [ V_64 ] . V_49 ) ;
if ( V_21 -> V_67 [ V_64 ] . V_50 )
F_68 ( V_21 -> V_67 [ V_64 ] . V_50 ) ;
F_28 ( V_21 , V_21 -> V_67 + V_64 ) ;
}
F_45 ( V_21 ) ;
if ( V_21 -> V_51 )
F_67 ( V_21 -> V_51 ) ;
V_21 -> V_51 = NULL ;
if ( V_21 -> V_73 )
F_68 ( V_21 -> V_73 ) ;
V_21 -> V_73 = NULL ;
F_41 ( F_69 ( V_21 -> V_74 ,
V_99 ==
F_70 ( & V_21 -> V_72 ) ) ) ;
F_63 ( V_21 -> V_74 , NULL ) ;
F_71 ( ! F_24 ( & V_21 -> V_27 ) ) ;
if ( V_21 -> V_28 ) {
F_58 ( V_21 -> V_28 ) ;
V_21 -> V_28 = NULL ;
}
if ( V_21 -> V_57 )
F_59 ( V_21 -> V_57 ) ;
V_21 -> V_57 = NULL ;
}
static int F_72 ( void T_5 * V_46 , T_6 V_100 , unsigned long V_101 )
{
T_6 V_102 = V_100 / V_103 / 8 ;
if ( V_102 > V_104 - ( unsigned long ) V_46 ||
V_102 + ( unsigned long ) V_46 > V_104 )
return 0 ;
return F_73 ( V_105 , V_46 + V_102 ,
( V_101 + V_103 * 8 - 1 ) / V_103 / 8 ) ;
}
static int F_74 ( void T_5 * V_46 , struct V_91 * V_106 ,
int V_107 )
{
int V_64 ;
if ( ! V_106 )
return 0 ;
for ( V_64 = 0 ; V_64 < V_106 -> V_93 ; ++ V_64 ) {
struct V_108 * V_109 = V_106 -> V_92 + V_64 ;
unsigned long V_102 = V_109 -> V_110 ;
if ( V_109 -> V_111 > V_104 )
return 0 ;
else if ( ! F_73 ( V_105 , ( void T_5 * ) V_102 ,
V_109 -> V_111 ) )
return 0 ;
else if ( V_107 && ! F_72 ( V_46 ,
V_109 -> V_112 ,
V_109 -> V_111 ) )
return 0 ;
}
return 1 ;
}
static int F_75 ( struct V_20 * V_113 , struct V_91 * V_106 ,
int V_107 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_113 -> V_66 ; ++ V_64 ) {
int V_114 ;
F_76 ( & V_113 -> V_67 [ V_64 ] . V_72 ) ;
if ( V_113 -> V_67 [ V_64 ] . V_45 )
V_114 = F_74 ( V_113 -> V_67 [ V_64 ] . V_46 , V_106 ,
V_107 ) ;
else
V_114 = 1 ;
F_77 ( & V_113 -> V_67 [ V_64 ] . V_72 ) ;
if ( ! V_114 )
return 0 ;
}
return 1 ;
}
static int F_78 ( struct V_20 * V_113 , unsigned int V_31 ,
struct V_115 T_5 * V_32 ,
struct V_116 T_5 * V_33 ,
struct V_117 T_5 * V_34 )
{
T_7 V_80 = F_79 ( V_113 , V_118 ) ? 2 : 0 ;
return F_73 ( V_119 , V_32 , V_31 * sizeof *V_32 ) &&
F_73 ( V_119 , V_33 ,
sizeof *V_33 + V_31 * sizeof * V_33 -> V_120 + V_80 ) &&
F_73 ( V_105 , V_34 ,
sizeof *V_34 + V_31 * sizeof * V_34 -> V_120 + V_80 ) ;
}
int F_80 ( struct V_20 * V_21 )
{
struct V_91 * V_121 ;
V_121 = F_69 ( V_21 -> V_74 ,
F_70 ( & V_21 -> V_72 ) ) ;
return F_75 ( V_21 , V_121 , 1 ) ;
}
static int F_81 ( struct V_20 * V_113 , struct V_29 * V_30 ,
void T_5 * V_46 )
{
struct V_91 * V_121 ;
T_7 V_80 = F_79 ( V_113 , V_118 ) ? 2 : 0 ;
V_121 = F_69 ( V_30 -> V_21 -> V_74 ,
F_70 ( & V_30 -> V_72 ) ) ;
return F_74 ( V_46 , V_121 ,
F_79 ( V_30 -> V_21 , V_122 ) ) &&
( ! V_30 -> V_41 || F_72 ( V_46 , V_30 -> V_42 ,
sizeof * V_30 -> V_34 +
V_30 -> V_31 * sizeof * V_30 -> V_34 -> V_120 + V_80 ) ) ;
}
int F_82 ( struct V_29 * V_30 )
{
return F_78 ( V_30 -> V_21 , V_30 -> V_31 , V_30 -> V_32 , V_30 -> V_33 , V_30 -> V_34 ) &&
F_81 ( V_30 -> V_21 , V_30 , V_30 -> V_46 ) ;
}
static long F_83 ( struct V_20 * V_113 , struct V_91 T_5 * V_109 )
{
struct V_91 V_106 , * V_123 , * V_124 ;
unsigned long V_125 = F_61 ( struct V_91 , V_92 ) ;
if ( F_84 ( & V_106 , V_109 , V_125 ) )
return - V_126 ;
if ( V_106 . V_127 )
return - V_128 ;
if ( V_106 . V_93 > V_129 )
return - V_130 ;
V_123 = F_44 ( V_125 + V_106 . V_93 * sizeof * V_109 -> V_92 , V_69 ) ;
if ( ! V_123 )
return - V_71 ;
memcpy ( V_123 , & V_106 , V_125 ) ;
if ( F_84 ( V_123 -> V_92 , V_109 -> V_92 ,
V_106 . V_93 * sizeof * V_109 -> V_92 ) ) {
F_41 ( V_123 ) ;
return - V_126 ;
}
if ( ! F_75 ( V_113 , V_123 ,
F_79 ( V_113 , V_122 ) ) ) {
F_41 ( V_123 ) ;
return - V_126 ;
}
V_124 = F_69 ( V_113 -> V_74 ,
F_70 ( & V_113 -> V_72 ) ) ;
F_85 ( V_113 -> V_74 , V_123 ) ;
F_86 () ;
F_41 ( V_124 ) ;
return 0 ;
}
static long F_87 ( struct V_20 * V_113 , int V_131 , void T_5 * V_132 )
{
struct V_1 * V_133 , * V_134 = NULL ,
* V_135 = NULL , * V_136 = NULL ;
struct V_137 * V_138 = NULL ;
T_8 T_5 * V_139 = V_132 ;
struct V_29 * V_30 ;
struct V_140 V_80 ;
struct V_141 V_142 ;
struct V_143 V_102 ;
T_8 V_144 ;
long V_145 ;
V_145 = F_88 ( V_144 , V_139 ) ;
if ( V_145 < 0 )
return V_145 ;
if ( V_144 >= V_113 -> V_66 )
return - V_146 ;
V_30 = V_113 -> V_67 + V_144 ;
F_76 ( & V_30 -> V_72 ) ;
switch ( V_131 ) {
case V_147 :
if ( V_30 -> V_45 ) {
V_145 = - V_86 ;
break;
}
if ( F_84 ( & V_80 , V_132 , sizeof V_80 ) ) {
V_145 = - V_126 ;
break;
}
if ( ! V_80 . V_31 || V_80 . V_31 > 0xffff || ( V_80 . V_31 & ( V_80 . V_31 - 1 ) ) ) {
V_145 = - V_148 ;
break;
}
V_30 -> V_31 = V_80 . V_31 ;
break;
case V_149 :
if ( V_30 -> V_45 ) {
V_145 = - V_86 ;
break;
}
if ( F_84 ( & V_80 , V_132 , sizeof V_80 ) ) {
V_145 = - V_126 ;
break;
}
if ( V_80 . V_31 > 0xffff ) {
V_145 = - V_148 ;
break;
}
V_30 -> V_35 = V_80 . V_31 ;
V_30 -> V_36 = V_30 -> V_35 ;
break;
case V_150 :
V_80 . V_151 = V_144 ;
V_80 . V_31 = V_30 -> V_35 ;
if ( F_89 ( V_132 , & V_80 , sizeof V_80 ) )
V_145 = - V_126 ;
break;
case V_152 :
if ( F_84 ( & V_102 , V_132 , sizeof V_102 ) ) {
V_145 = - V_126 ;
break;
}
if ( V_102 . V_26 & ~ ( 0x1 << V_153 ) ) {
V_145 = - V_128 ;
break;
}
if ( ( T_6 ) ( unsigned long ) V_102 . V_154 != V_102 . V_154 ||
( T_6 ) ( unsigned long ) V_102 . V_155 != V_102 . V_155 ||
( T_6 ) ( unsigned long ) V_102 . V_156 != V_102 . V_156 ) {
V_145 = - V_126 ;
break;
}
if ( ( V_102 . V_156 & ( sizeof * V_30 -> V_33 -> V_120 - 1 ) ) ||
( V_102 . V_155 & ( sizeof * V_30 -> V_34 -> V_120 - 1 ) ) ||
( V_102 . V_157 & ( sizeof * V_30 -> V_34 -> V_120 - 1 ) ) ) {
V_145 = - V_148 ;
break;
}
if ( V_30 -> V_45 ) {
if ( ! F_78 ( V_113 , V_30 -> V_31 ,
( void T_5 * ) ( unsigned long ) V_102 . V_154 ,
( void T_5 * ) ( unsigned long ) V_102 . V_156 ,
( void T_5 * ) ( unsigned long ) V_102 . V_155 ) ) {
V_145 = - V_148 ;
break;
}
if ( ( V_102 . V_26 & ( 0x1 << V_153 ) ) &&
! F_72 ( V_30 -> V_46 , V_102 . V_157 ,
sizeof * V_30 -> V_34 +
V_30 -> V_31 * sizeof * V_30 -> V_34 -> V_120 ) ) {
V_145 = - V_148 ;
break;
}
}
V_30 -> V_41 = ! ! ( V_102 . V_26 & ( 0x1 << V_153 ) ) ;
V_30 -> V_32 = ( void T_5 * ) ( unsigned long ) V_102 . V_154 ;
V_30 -> V_33 = ( void T_5 * ) ( unsigned long ) V_102 . V_156 ;
V_30 -> V_42 = V_102 . V_157 ;
V_30 -> V_34 = ( void T_5 * ) ( unsigned long ) V_102 . V_155 ;
break;
case V_158 :
if ( F_84 ( & V_142 , V_132 , sizeof V_142 ) ) {
V_145 = - V_126 ;
break;
}
V_133 = V_142 . V_159 == - 1 ? NULL : F_90 ( V_142 . V_159 ) ;
if ( F_56 ( V_133 ) ) {
V_145 = F_57 ( V_133 ) ;
break;
}
if ( V_133 != V_30 -> V_48 ) {
V_136 = V_134 = V_30 -> V_48 ;
V_135 = V_30 -> V_48 = V_133 ;
} else
V_134 = V_133 ;
break;
case V_160 :
if ( F_84 ( & V_142 , V_132 , sizeof V_142 ) ) {
V_145 = - V_126 ;
break;
}
V_133 = V_142 . V_159 == - 1 ? NULL : F_90 ( V_142 . V_159 ) ;
if ( F_56 ( V_133 ) ) {
V_145 = F_57 ( V_133 ) ;
break;
}
if ( V_133 != V_30 -> V_50 ) {
V_134 = V_30 -> V_50 ;
V_138 = V_30 -> V_49 ;
V_30 -> V_50 = V_133 ;
V_30 -> V_49 = V_133 ?
F_91 ( V_133 ) : NULL ;
} else
V_134 = V_133 ;
break;
case V_161 :
if ( F_84 ( & V_142 , V_132 , sizeof V_142 ) ) {
V_145 = - V_126 ;
break;
}
V_133 = V_142 . V_159 == - 1 ? NULL : F_90 ( V_142 . V_159 ) ;
if ( F_56 ( V_133 ) ) {
V_145 = F_57 ( V_133 ) ;
break;
}
if ( V_133 != V_30 -> error ) {
V_134 = V_30 -> error ;
V_30 -> error = V_133 ;
V_138 = V_30 -> V_47 ;
V_30 -> V_47 = V_133 ?
F_91 ( V_133 ) : NULL ;
} else
V_134 = V_133 ;
break;
default:
V_145 = - V_162 ;
}
if ( V_136 && V_30 -> V_75 )
F_13 ( & V_30 -> V_5 ) ;
if ( V_138 )
F_67 ( V_138 ) ;
if ( V_134 )
F_68 ( V_134 ) ;
if ( V_135 && V_30 -> V_75 )
F_12 ( & V_30 -> V_5 , V_30 -> V_48 ) ;
F_77 ( & V_30 -> V_72 ) ;
if ( V_136 && V_30 -> V_75 )
F_21 ( & V_30 -> V_5 ) ;
return V_145 ;
}
long F_92 ( struct V_20 * V_113 , unsigned int V_131 , unsigned long V_163 )
{
void T_5 * V_132 = ( void T_5 * ) V_163 ;
struct V_1 * V_133 , * V_134 = NULL ;
struct V_137 * V_138 = NULL ;
T_6 V_164 ;
long V_145 ;
int V_64 , V_159 ;
if ( V_131 == V_165 ) {
V_145 = F_53 ( V_113 ) ;
goto V_16;
}
V_145 = F_49 ( V_113 ) ;
if ( V_145 )
goto V_16;
switch ( V_131 ) {
case V_166 :
V_145 = F_83 ( V_113 , V_132 ) ;
break;
case V_167 :
if ( F_84 ( & V_164 , V_132 , sizeof V_164 ) ) {
V_145 = - V_126 ;
break;
}
if ( ( T_6 ) ( unsigned long ) V_164 != V_164 ) {
V_145 = - V_126 ;
break;
}
for ( V_64 = 0 ; V_64 < V_113 -> V_66 ; ++ V_64 ) {
struct V_29 * V_30 ;
void T_5 * V_168 = ( void T_5 * ) ( unsigned long ) V_164 ;
V_30 = V_113 -> V_67 + V_64 ;
F_76 ( & V_30 -> V_72 ) ;
if ( V_30 -> V_45 && ! F_81 ( V_113 , V_30 , V_168 ) )
V_145 = - V_126 ;
else
V_30 -> V_46 = V_168 ;
F_77 ( & V_30 -> V_72 ) ;
}
break;
case V_169 :
V_145 = F_88 ( V_159 , ( int T_5 * ) V_132 ) ;
if ( V_145 < 0 )
break;
V_133 = V_159 == - 1 ? NULL : F_90 ( V_159 ) ;
if ( F_56 ( V_133 ) ) {
V_145 = F_57 ( V_133 ) ;
break;
}
if ( V_133 != V_113 -> V_73 ) {
V_134 = V_113 -> V_73 ;
V_138 = V_113 -> V_51 ;
V_113 -> V_51 = V_133 ?
F_91 ( V_133 ) : NULL ;
} else
V_134 = V_133 ;
for ( V_64 = 0 ; V_64 < V_113 -> V_66 ; ++ V_64 ) {
F_76 ( & V_113 -> V_67 [ V_64 ] . V_72 ) ;
V_113 -> V_67 [ V_64 ] . V_51 = V_113 -> V_51 ;
F_77 ( & V_113 -> V_67 [ V_64 ] . V_72 ) ;
}
if ( V_138 )
F_67 ( V_138 ) ;
if ( V_134 )
F_68 ( V_134 ) ;
break;
default:
V_145 = F_87 ( V_113 , V_131 , V_132 ) ;
break;
}
V_16:
return V_145 ;
}
static const struct V_108 * F_93 ( struct V_91 * V_106 ,
T_9 V_100 , T_10 V_95 )
{
struct V_108 * V_170 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_106 -> V_93 ; ++ V_64 ) {
V_170 = V_106 -> V_92 + V_64 ;
if ( V_170 -> V_112 <= V_100 &&
V_170 -> V_112 + V_170 -> V_111 - 1 >= V_100 )
return V_170 ;
}
return NULL ;
}
static int F_94 ( int V_171 , void T_5 * V_100 )
{
unsigned long log = ( unsigned long ) V_100 ;
struct V_172 * V_172 ;
void * V_168 ;
int V_173 = V_171 + ( log % V_174 ) * 8 ;
int V_145 ;
V_145 = F_95 ( log , 1 , 1 , & V_172 ) ;
if ( V_145 < 0 )
return V_145 ;
F_20 ( V_145 != 1 ) ;
V_168 = F_96 ( V_172 ) ;
F_97 ( V_173 , V_168 ) ;
F_98 ( V_168 ) ;
F_99 ( V_172 ) ;
F_100 ( V_172 ) ;
return 0 ;
}
static int F_101 ( void T_5 * V_46 ,
T_6 V_175 , T_6 V_176 )
{
T_6 V_177 = V_175 / V_103 ;
int V_145 ;
if ( ! V_176 )
return 0 ;
V_176 += V_175 % V_103 ;
for (; ; ) {
T_6 V_168 = ( T_6 ) ( unsigned long ) V_46 ;
T_6 log = V_168 + V_177 / 8 ;
int V_173 = V_177 % 8 ;
if ( ( T_6 ) ( unsigned long ) log != log )
return - V_126 ;
V_145 = F_94 ( V_173 , ( void T_5 * ) ( unsigned long ) log ) ;
if ( V_145 < 0 )
return V_145 ;
if ( V_176 <= V_103 )
break;
V_176 -= V_103 ;
V_177 += 1 ;
}
return V_145 ;
}
int F_102 ( struct V_29 * V_30 , struct V_178 * log ,
unsigned int V_179 , T_6 V_95 )
{
int V_64 , V_145 ;
F_103 () ;
for ( V_64 = 0 ; V_64 < V_179 ; ++ V_64 ) {
T_6 V_180 = F_104 ( log [ V_64 ] . V_95 , V_95 ) ;
V_145 = F_101 ( V_30 -> V_46 , log [ V_64 ] . V_100 , V_180 ) ;
if ( V_145 < 0 )
return V_145 ;
V_95 -= V_180 ;
if ( ! V_95 ) {
if ( V_30 -> V_51 )
F_105 ( V_30 -> V_51 , 1 ) ;
return 0 ;
}
}
F_106 () ;
return 0 ;
}
static int F_107 ( struct V_29 * V_30 )
{
void T_5 * V_34 ;
if ( F_108 ( V_30 -> V_40 , & V_30 -> V_34 -> V_26 ) < 0 )
return - V_126 ;
if ( F_109 ( V_30 -> V_41 ) ) {
F_103 () ;
V_34 = & V_30 -> V_34 -> V_26 ;
F_101 ( V_30 -> V_46 , V_30 -> V_42 +
( V_34 - ( void T_5 * ) V_30 -> V_34 ) ,
sizeof V_30 -> V_34 -> V_26 ) ;
if ( V_30 -> V_51 )
F_105 ( V_30 -> V_51 , 1 ) ;
}
return 0 ;
}
static int F_110 ( struct V_29 * V_30 , T_11 V_181 )
{
if ( F_108 ( V_30 -> V_36 , F_111 ( V_30 ) ) )
return - V_126 ;
if ( F_109 ( V_30 -> V_41 ) ) {
void T_5 * V_34 ;
F_103 () ;
V_34 = F_111 ( V_30 ) ;
F_101 ( V_30 -> V_46 , V_30 -> V_42 +
( V_34 - ( void T_5 * ) V_30 -> V_34 ) ,
sizeof * F_111 ( V_30 ) ) ;
if ( V_30 -> V_51 )
F_105 ( V_30 -> V_51 , 1 ) ;
}
return 0 ;
}
int F_112 ( struct V_29 * V_30 )
{
int V_145 ;
if ( ! V_30 -> V_45 )
return 0 ;
V_145 = F_107 ( V_30 ) ;
if ( V_145 )
return V_145 ;
V_30 -> V_39 = false ;
return F_88 ( V_30 -> V_37 , & V_30 -> V_34 -> V_144 ) ;
}
static int F_113 ( struct V_20 * V_21 , T_6 V_100 , T_8 V_95 ,
struct V_182 V_183 [] , int V_184 )
{
const struct V_108 * V_170 ;
struct V_91 * V_106 ;
struct V_182 * V_185 ;
T_6 V_80 = 0 ;
int V_81 = 0 ;
F_114 () ;
V_106 = F_115 ( V_21 -> V_74 ) ;
while ( ( T_6 ) V_95 > V_80 ) {
T_6 V_125 ;
if ( F_109 ( V_81 >= V_184 ) ) {
V_81 = - V_146 ;
break;
}
V_170 = F_93 ( V_106 , V_100 , V_95 ) ;
if ( F_109 ( ! V_170 ) ) {
V_81 = - V_126 ;
break;
}
V_185 = V_183 + V_81 ;
V_125 = V_170 -> V_111 - V_100 + V_170 -> V_112 ;
V_185 -> V_186 = F_104 ( ( T_6 ) V_95 , V_125 ) ;
V_185 -> V_187 = ( void T_5 * ) ( unsigned long )
( V_170 -> V_110 + V_100 - V_170 -> V_112 ) ;
V_80 += V_125 ;
V_100 += V_125 ;
++ V_81 ;
}
F_116 () ;
return V_81 ;
}
static unsigned F_117 ( struct V_115 * V_32 )
{
unsigned int V_188 ;
if ( ! ( V_32 -> V_26 & V_189 ) )
return - 1U ;
V_188 = V_32 -> V_188 ;
F_118 () ;
return V_188 ;
}
static int F_119 ( struct V_20 * V_21 , struct V_29 * V_30 ,
struct V_182 V_183 [] , unsigned int V_184 ,
unsigned int * V_190 , unsigned int * V_191 ,
struct V_178 * log , unsigned int * V_179 ,
struct V_115 * V_60 )
{
struct V_115 V_32 ;
unsigned int V_64 = 0 , V_192 , V_193 = 0 ;
int V_81 ;
if ( F_109 ( V_60 -> V_95 % sizeof V_32 ) ) {
F_120 ( V_30 , L_2
L_3 ,
( unsigned long long ) V_60 -> V_95 ,
sizeof V_32 ) ;
return - V_148 ;
}
V_81 = F_113 ( V_21 , V_60 -> V_100 , V_60 -> V_95 , V_30 -> V_60 ,
V_68 ) ;
if ( F_109 ( V_81 < 0 ) ) {
F_120 ( V_30 , L_4 , V_81 ) ;
return V_81 ;
}
F_118 () ;
V_192 = V_60 -> V_95 / sizeof V_32 ;
if ( F_109 ( V_192 > V_194 + 1 ) ) {
F_120 ( V_30 , L_5 ,
V_60 -> V_95 ) ;
return - V_130 ;
}
do {
unsigned V_195 = * V_191 + * V_190 ;
if ( F_109 ( ++ V_193 > V_192 ) ) {
F_120 ( V_30 , L_6
L_7 ,
V_64 , V_192 ) ;
return - V_148 ;
}
if ( F_109 ( F_121 ( ( unsigned char * ) & V_32 ,
V_30 -> V_60 , sizeof V_32 ) ) ) {
F_120 ( V_30 , L_8 ,
V_64 , ( T_7 ) V_60 -> V_100 + V_64 * sizeof V_32 ) ;
return - V_148 ;
}
if ( F_109 ( V_32 . V_26 & V_196 ) ) {
F_120 ( V_30 , L_9 ,
V_64 , ( T_7 ) V_60 -> V_100 + V_64 * sizeof V_32 ) ;
return - V_148 ;
}
V_81 = F_113 ( V_21 , V_32 . V_100 , V_32 . V_95 , V_183 + V_195 ,
V_184 - V_195 ) ;
if ( F_109 ( V_81 < 0 ) ) {
F_120 ( V_30 , L_10 ,
V_81 , V_64 ) ;
return V_81 ;
}
if ( V_32 . V_26 & V_197 ) {
* V_191 += V_81 ;
if ( F_109 ( log ) ) {
log [ * V_179 ] . V_100 = V_32 . V_100 ;
log [ * V_179 ] . V_95 = V_32 . V_95 ;
++ * V_179 ;
}
} else {
if ( F_109 ( * V_191 ) ) {
F_120 ( V_30 , L_11
L_12 , V_64 ) ;
return - V_148 ;
}
* V_190 += V_81 ;
}
} while ( ( V_64 = F_117 ( & V_32 ) ) != - 1 );
return 0 ;
}
int F_122 ( struct V_20 * V_21 , struct V_29 * V_30 ,
struct V_182 V_183 [] , unsigned int V_184 ,
unsigned int * V_190 , unsigned int * V_191 ,
struct V_178 * log , unsigned int * V_179 )
{
struct V_115 V_32 ;
unsigned int V_64 , V_198 , V_193 = 0 ;
T_11 V_35 ;
int V_81 ;
V_35 = V_30 -> V_35 ;
if ( F_109 ( F_123 ( V_30 -> V_36 , & V_30 -> V_33 -> V_144 ) ) ) {
F_120 ( V_30 , L_13 ,
& V_30 -> V_33 -> V_144 ) ;
return - V_126 ;
}
if ( F_109 ( ( T_11 ) ( V_30 -> V_36 - V_35 ) > V_30 -> V_31 ) ) {
F_120 ( V_30 , L_14 ,
V_35 , V_30 -> V_36 ) ;
return - V_126 ;
}
if ( V_30 -> V_36 == V_35 )
return V_30 -> V_31 ;
F_124 () ;
if ( F_109 ( F_123 ( V_198 ,
& V_30 -> V_33 -> V_120 [ V_35 % V_30 -> V_31 ] ) ) ) {
F_120 ( V_30 , L_15 ,
V_35 ,
& V_30 -> V_33 -> V_120 [ V_35 % V_30 -> V_31 ] ) ;
return - V_126 ;
}
if ( F_109 ( V_198 >= V_30 -> V_31 ) ) {
F_120 ( V_30 , L_16 ,
V_198 , V_30 -> V_31 ) ;
return - V_148 ;
}
* V_190 = * V_191 = 0 ;
if ( F_109 ( log ) )
* V_179 = 0 ;
V_64 = V_198 ;
do {
unsigned V_195 = * V_191 + * V_190 ;
if ( F_109 ( V_64 >= V_30 -> V_31 ) ) {
F_120 ( V_30 , L_17 ,
V_64 , V_30 -> V_31 , V_198 ) ;
return - V_148 ;
}
if ( F_109 ( ++ V_193 > V_30 -> V_31 ) ) {
F_120 ( V_30 , L_6
L_18 ,
V_64 , V_30 -> V_31 , V_198 ) ;
return - V_148 ;
}
V_81 = F_125 ( & V_32 , V_30 -> V_32 + V_64 , sizeof V_32 ) ;
if ( F_109 ( V_81 ) ) {
F_120 ( V_30 , L_19 ,
V_64 , V_30 -> V_32 + V_64 ) ;
return - V_126 ;
}
if ( V_32 . V_26 & V_196 ) {
V_81 = F_119 ( V_21 , V_30 , V_183 , V_184 ,
V_190 , V_191 ,
log , V_179 , & V_32 ) ;
if ( F_109 ( V_81 < 0 ) ) {
F_120 ( V_30 , L_20
L_21 , V_64 ) ;
return V_81 ;
}
continue;
}
V_81 = F_113 ( V_21 , V_32 . V_100 , V_32 . V_95 , V_183 + V_195 ,
V_184 - V_195 ) ;
if ( F_109 ( V_81 < 0 ) ) {
F_120 ( V_30 , L_22 ,
V_81 , V_64 ) ;
return V_81 ;
}
if ( V_32 . V_26 & V_197 ) {
* V_191 += V_81 ;
if ( F_109 ( log ) ) {
log [ * V_179 ] . V_100 = V_32 . V_100 ;
log [ * V_179 ] . V_95 = V_32 . V_95 ;
++ * V_179 ;
}
} else {
if ( F_109 ( * V_191 ) ) {
F_120 ( V_30 , L_23
L_24 , V_64 ) ;
return - V_148 ;
}
* V_190 += V_81 ;
}
} while ( ( V_64 = F_117 ( & V_32 ) ) != - 1 );
V_30 -> V_35 ++ ;
F_20 ( ! ( V_30 -> V_40 & V_199 ) ) ;
return V_198 ;
}
void F_126 ( struct V_29 * V_30 , int V_200 )
{
V_30 -> V_35 -= V_200 ;
}
int F_127 ( struct V_29 * V_30 , unsigned int V_198 , int V_95 )
{
struct V_201 T_5 * V_34 ;
V_34 = & V_30 -> V_34 -> V_120 [ V_30 -> V_37 % V_30 -> V_31 ] ;
if ( F_108 ( V_198 , & V_34 -> V_98 ) ) {
F_120 ( V_30 , L_25 ) ;
return - V_126 ;
}
if ( F_108 ( V_95 , & V_34 -> V_95 ) ) {
F_120 ( V_30 , L_26 ) ;
return - V_126 ;
}
F_103 () ;
if ( F_108 ( V_30 -> V_37 + 1 , & V_30 -> V_34 -> V_144 ) ) {
F_120 ( V_30 , L_27 ) ;
return - V_126 ;
}
if ( F_109 ( V_30 -> V_41 ) ) {
F_103 () ;
F_101 ( V_30 -> V_46 ,
V_30 -> V_42 +
( ( void T_5 * ) V_34 - ( void T_5 * ) V_30 -> V_34 ) ,
sizeof *V_34 ) ;
F_101 ( V_30 -> V_46 ,
V_30 -> V_42 + F_61 ( struct V_117 , V_144 ) ,
sizeof V_30 -> V_34 -> V_144 ) ;
if ( V_30 -> V_51 )
F_105 ( V_30 -> V_51 , 1 ) ;
}
V_30 -> V_37 ++ ;
if ( F_109 ( V_30 -> V_37 == V_30 -> V_38 ) )
V_30 -> V_39 = false ;
return 0 ;
}
static int F_128 ( struct V_29 * V_30 ,
struct V_201 * V_61 ,
unsigned V_192 )
{
struct V_201 T_5 * V_34 ;
T_11 V_202 , V_203 ;
int V_204 ;
V_204 = V_30 -> V_37 % V_30 -> V_31 ;
V_34 = V_30 -> V_34 -> V_120 + V_204 ;
if ( F_129 ( V_34 , V_61 , V_192 * sizeof *V_34 ) ) {
F_120 ( V_30 , L_28 ) ;
return - V_126 ;
}
if ( F_109 ( V_30 -> V_41 ) ) {
F_103 () ;
F_101 ( V_30 -> V_46 ,
V_30 -> V_42 +
( ( void T_5 * ) V_34 - ( void T_5 * ) V_30 -> V_34 ) ,
V_192 * sizeof *V_34 ) ;
}
V_202 = V_30 -> V_37 ;
V_203 = ( V_30 -> V_37 += V_192 ) ;
if ( F_109 ( ( T_11 ) ( V_203 - V_30 -> V_38 ) < ( T_11 ) ( V_203 - V_202 ) ) )
V_30 -> V_39 = false ;
return 0 ;
}
int F_130 ( struct V_29 * V_30 , struct V_201 * V_61 ,
unsigned V_192 )
{
int V_204 , V_200 , V_145 ;
V_204 = V_30 -> V_37 % V_30 -> V_31 ;
V_200 = V_30 -> V_31 - V_204 ;
if ( V_200 < V_192 ) {
V_145 = F_128 ( V_30 , V_61 , V_200 ) ;
if ( V_145 < 0 )
return V_145 ;
V_61 += V_200 ;
V_192 -= V_200 ;
}
V_145 = F_128 ( V_30 , V_61 , V_192 ) ;
F_103 () ;
if ( F_131 ( V_30 -> V_37 , & V_30 -> V_34 -> V_144 ) ) {
F_120 ( V_30 , L_27 ) ;
return - V_126 ;
}
if ( F_109 ( V_30 -> V_41 ) ) {
F_101 ( V_30 -> V_46 ,
V_30 -> V_42 + F_61 ( struct V_117 , V_144 ) ,
sizeof V_30 -> V_34 -> V_144 ) ;
if ( V_30 -> V_51 )
F_105 ( V_30 -> V_51 , 1 ) ;
}
return V_145 ;
}
static bool F_132 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
T_12 V_202 , V_203 , V_205 ;
bool V_206 ;
F_133 () ;
if ( F_79 ( V_21 , V_207 ) &&
F_109 ( V_30 -> V_36 == V_30 -> V_35 ) )
return true ;
if ( ! F_79 ( V_21 , V_118 ) ) {
T_12 V_26 ;
if ( F_123 ( V_26 , & V_30 -> V_33 -> V_26 ) ) {
F_120 ( V_30 , L_29 ) ;
return true ;
}
return ! ( V_26 & V_208 ) ;
}
V_202 = V_30 -> V_38 ;
V_206 = V_30 -> V_39 ;
V_203 = V_30 -> V_38 = V_30 -> V_37 ;
V_30 -> V_39 = true ;
if ( F_109 ( ! V_206 ) )
return true ;
if ( F_88 ( V_205 , F_134 ( V_30 ) ) ) {
F_120 ( V_30 , L_30 ) ;
return true ;
}
return F_135 ( V_205 , V_203 , V_202 ) ;
}
void F_136 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
if ( V_30 -> V_49 && F_132 ( V_21 , V_30 ) )
F_105 ( V_30 -> V_49 , 1 ) ;
}
void F_65 ( struct V_20 * V_21 ,
struct V_29 * V_30 ,
unsigned int V_198 , int V_95 )
{
F_127 ( V_30 , V_198 , V_95 ) ;
F_136 ( V_21 , V_30 ) ;
}
void F_137 ( struct V_20 * V_21 ,
struct V_29 * V_30 ,
struct V_201 * V_61 , unsigned V_192 )
{
F_130 ( V_30 , V_61 , V_192 ) ;
F_136 ( V_21 , V_30 ) ;
}
bool F_138 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
T_11 V_36 ;
int V_145 ;
if ( ! ( V_30 -> V_40 & V_199 ) )
return false ;
V_30 -> V_40 &= ~ V_199 ;
if ( ! F_79 ( V_21 , V_118 ) ) {
V_145 = F_107 ( V_30 ) ;
if ( V_145 ) {
F_120 ( V_30 , L_31 ,
& V_30 -> V_34 -> V_26 , V_145 ) ;
return false ;
}
} else {
V_145 = F_110 ( V_30 , V_30 -> V_36 ) ;
if ( V_145 ) {
F_120 ( V_30 , L_32 ,
F_111 ( V_30 ) , V_145 ) ;
return false ;
}
}
F_133 () ;
V_145 = F_123 ( V_36 , & V_30 -> V_33 -> V_144 ) ;
if ( V_145 ) {
F_120 ( V_30 , L_33 ,
& V_30 -> V_33 -> V_144 , V_145 ) ;
return false ;
}
return V_36 != V_30 -> V_36 ;
}
void F_139 ( struct V_20 * V_21 , struct V_29 * V_30 )
{
int V_145 ;
if ( V_30 -> V_40 & V_199 )
return;
V_30 -> V_40 |= V_199 ;
if ( ! F_79 ( V_21 , V_118 ) ) {
V_145 = F_107 ( V_30 ) ;
if ( V_145 )
F_120 ( V_30 , L_31 ,
& V_30 -> V_34 -> V_26 , V_145 ) ;
}
}
static void F_140 ( struct V_209 * V_209 )
{
struct V_210 * V_54 = F_2 ( V_209 , struct V_210 ,
V_209 ) ;
F_141 ( & V_54 -> V_7 ) ;
}
struct V_210 * F_142 ( struct V_29 * V_30 ,
bool V_65 )
{
struct V_210 * V_54 ;
if ( ! V_65 )
return NULL ;
V_54 = F_44 ( sizeof *V_54 , V_69 ) ;
if ( ! V_54 )
return F_143 ( - V_71 ) ;
F_144 ( & V_54 -> V_209 ) ;
F_8 ( & V_54 -> V_7 ) ;
V_54 -> V_30 = V_30 ;
return V_54 ;
}
void F_145 ( struct V_210 * V_54 )
{
F_146 ( & V_54 -> V_209 , F_140 ) ;
}
void F_66 ( struct V_210 * V_54 )
{
F_146 ( & V_54 -> V_209 , F_140 ) ;
F_19 ( V_54 -> V_7 , ! F_147 ( & V_54 -> V_209 . V_211 ) ) ;
F_41 ( V_54 ) ;
}
void F_148 ( struct V_62 * V_212 )
{
struct V_210 * V_54 = V_212 -> V_138 ;
struct V_29 * V_30 = V_54 -> V_30 ;
V_30 -> V_61 [ V_212 -> V_32 ] . V_95 = V_96 ;
F_146 ( & V_54 -> V_209 , F_140 ) ;
}
