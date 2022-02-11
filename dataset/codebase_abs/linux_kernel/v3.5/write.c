struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 , V_4 ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_3 ( & V_2 -> V_5 ) ;
}
return V_2 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_3 ) ;
}
struct V_6 * F_6 ( void )
{
struct V_6 * V_2 = F_2 ( V_7 , V_4 ) ;
if ( V_2 ) {
struct V_8 * V_9 = & V_2 -> V_10 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_3 ( & V_9 -> V_5 ) ;
F_3 ( & V_9 -> V_11 ) ;
F_7 ( & V_9 -> V_12 ) ;
F_8 ( & V_9 -> V_13 , 0 ) ;
V_9 -> V_14 = & V_2 -> V_14 ;
}
return V_2 ;
}
static struct V_15 * F_9 ( struct V_8 * V_9 ,
unsigned int V_16 )
{
struct V_15 * V_17 , * V_18 ;
V_18 = & F_10 ( V_9 , struct V_6 , V_10 ) -> V_19 ;
if ( V_18 -> V_10 == NULL )
V_17 = V_18 ;
else
V_17 = F_11 ( sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
goto V_21;
if ( F_12 ( & V_17 -> V_5 , V_16 ) ) {
V_17 -> V_10 = V_9 ;
F_13 ( & V_9 -> V_13 ) ;
} else {
if ( V_17 != V_18 )
F_14 ( V_17 ) ;
V_17 = NULL ;
}
V_21:
return V_17 ;
}
void F_15 ( struct V_8 * V_9 )
{
struct V_6 * V_22 = F_10 ( V_9 , struct V_6 , V_10 ) ;
F_5 ( V_22 , V_7 ) ;
}
void F_16 ( struct V_15 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_10 ;
struct V_6 * V_24 = F_10 ( V_9 , struct V_6 , V_10 ) ;
F_17 ( V_23 -> args . V_25 ) ;
if ( V_23 -> V_5 . V_26 != V_23 -> V_5 . V_27 )
F_14 ( V_23 -> V_5 . V_26 ) ;
if ( V_23 != & V_24 -> V_19 )
F_14 ( V_23 ) ;
else
V_23 -> V_10 = NULL ;
if ( F_18 ( & V_9 -> V_13 ) )
V_9 -> V_28 -> V_29 ( V_9 ) ;
}
static void F_19 ( struct V_30 * V_31 , int error )
{
V_31 -> error = error ;
F_20 () ;
F_21 ( V_32 , & V_31 -> V_33 ) ;
}
static struct V_34 * F_22 ( struct V_35 * V_35 )
{
struct V_34 * V_36 = NULL ;
if ( F_23 ( V_35 ) ) {
V_36 = (struct V_34 * ) F_24 ( V_35 ) ;
if ( V_36 != NULL )
F_25 ( & V_36 -> V_37 ) ;
}
return V_36 ;
}
static struct V_34 * F_26 ( struct V_35 * V_35 )
{
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
struct V_34 * V_36 = NULL ;
F_27 ( & V_38 -> V_41 ) ;
V_36 = F_22 ( V_35 ) ;
F_28 ( & V_38 -> V_41 ) ;
return V_36 ;
}
static void F_29 ( struct V_35 * V_35 , unsigned int V_42 , unsigned int V_43 )
{
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
T_1 V_44 , V_45 ;
T_2 V_46 ;
F_27 ( & V_38 -> V_41 ) ;
V_45 = F_30 ( V_38 ) ;
V_46 = ( V_45 - 1 ) >> V_47 ;
if ( V_45 > 0 && V_35 -> V_48 < V_46 )
goto V_21;
V_44 = ( ( T_1 ) V_35 -> V_48 << V_47 ) + ( ( T_1 ) V_42 + V_43 ) ;
if ( V_45 >= V_44 )
goto V_21;
F_31 ( V_38 , V_44 ) ;
F_32 ( V_38 , V_49 ) ;
V_21:
F_28 ( & V_38 -> V_41 ) ;
}
static void F_33 ( struct V_35 * V_35 )
{
F_34 ( V_35 ) ;
F_35 ( V_35 -> V_39 -> V_40 , V_35 -> V_39 ) ;
}
static void F_36 ( struct V_35 * V_35 , unsigned int V_50 , unsigned int V_43 )
{
if ( F_37 ( V_35 ) )
return;
if ( V_50 != 0 )
return;
if ( V_43 != F_38 ( V_35 ) )
return;
F_39 ( V_35 ) ;
}
static int F_40 ( struct V_51 * V_52 )
{
if ( V_52 -> V_53 )
return V_54 | V_55 ;
if ( V_52 -> V_56 || V_52 -> V_57 )
return V_58 | V_59 ;
return V_59 ;
}
static int F_41 ( struct V_35 * V_35 )
{
int V_60 = F_42 ( V_35 ) ;
if ( ! V_60 ) {
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
struct V_61 * V_62 = F_43 ( V_38 ) ;
if ( F_44 ( & V_62 -> V_63 ) >
V_64 ) {
F_45 ( & V_62 -> V_65 ,
V_66 ) ;
}
}
return V_60 ;
}
static void F_46 ( struct V_35 * V_35 )
{
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
struct V_61 * V_62 = F_43 ( V_38 ) ;
F_47 ( V_35 ) ;
if ( F_48 ( & V_62 -> V_63 ) < V_67 )
F_49 ( & V_62 -> V_65 , V_66 ) ;
}
static struct V_34 * F_50 ( struct V_35 * V_35 , bool V_68 )
{
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
struct V_34 * V_36 ;
int V_60 ;
F_27 ( & V_38 -> V_41 ) ;
for (; ; ) {
V_36 = F_22 ( V_35 ) ;
if ( V_36 == NULL )
break;
if ( F_51 ( V_36 ) )
break;
F_28 ( & V_38 -> V_41 ) ;
if ( ! V_68 )
V_60 = F_52 ( V_36 ) ;
else
V_60 = - V_69 ;
F_53 ( V_36 ) ;
if ( V_60 != 0 )
return F_54 ( V_60 ) ;
F_27 ( & V_38 -> V_41 ) ;
}
F_28 ( & V_38 -> V_41 ) ;
return V_36 ;
}
static int F_55 ( struct V_70 * V_71 ,
struct V_35 * V_35 , bool V_68 )
{
struct V_34 * V_36 ;
int V_60 = 0 ;
V_36 = F_50 ( V_35 , V_68 ) ;
if ( ! V_36 )
goto V_21;
V_60 = F_56 ( V_36 ) ;
if ( F_57 ( V_36 ) )
goto V_21;
V_60 = F_41 ( V_35 ) ;
F_58 ( V_60 != 0 ) ;
F_58 ( F_59 ( V_72 , & V_36 -> V_73 ) ) ;
if ( ! F_60 ( V_71 , V_36 ) ) {
F_61 ( V_36 ) ;
V_60 = V_71 -> V_74 ;
}
V_21:
return V_60 ;
}
static int F_62 ( struct V_35 * V_35 , struct V_51 * V_52 , struct V_70 * V_71 )
{
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
int V_60 ;
F_32 ( V_38 , V_75 ) ;
F_63 ( V_38 , V_76 , 1 ) ;
F_64 ( V_71 , V_35 -> V_48 ) ;
V_60 = F_55 ( V_71 , V_35 , V_52 -> V_77 == V_78 ) ;
if ( V_60 == - V_69 ) {
F_65 ( V_52 , V_35 ) ;
V_60 = 0 ;
}
return V_60 ;
}
static int F_66 ( struct V_35 * V_35 , struct V_51 * V_52 )
{
struct V_70 V_71 ;
int V_79 ;
F_67 ( & V_71 , V_35 -> V_39 -> V_40 , F_40 ( V_52 ) ,
& V_80 ) ;
V_79 = F_62 ( V_35 , V_52 , & V_71 ) ;
F_68 ( & V_71 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_71 . V_74 < 0 )
return V_71 . V_74 ;
return 0 ;
}
int F_69 ( struct V_35 * V_35 , struct V_51 * V_52 )
{
int V_60 ;
V_60 = F_66 ( V_35 , V_52 ) ;
F_70 ( V_35 ) ;
return V_60 ;
}
static int F_71 ( struct V_35 * V_35 , struct V_51 * V_52 , void * V_17 )
{
int V_60 ;
V_60 = F_62 ( V_35 , V_52 , V_17 ) ;
F_70 ( V_35 ) ;
return V_60 ;
}
int F_72 ( struct V_81 * V_39 , struct V_51 * V_52 )
{
struct V_38 * V_38 = V_39 -> V_40 ;
unsigned long * V_82 = & F_73 ( V_38 ) -> V_33 ;
struct V_70 V_71 ;
int V_79 ;
V_79 = F_74 ( V_82 , V_83 ,
V_84 , V_85 ) ;
if ( V_79 )
goto V_86;
F_32 ( V_38 , V_87 ) ;
F_67 ( & V_71 , V_38 , F_40 ( V_52 ) ,
& V_80 ) ;
V_79 = F_75 ( V_39 , V_52 , F_71 , & V_71 ) ;
F_68 ( & V_71 ) ;
F_76 ( V_83 , V_82 ) ;
F_77 () ;
F_78 ( V_82 , V_83 ) ;
if ( V_79 < 0 )
goto V_86;
V_79 = V_71 . V_74 ;
if ( V_79 < 0 )
goto V_86;
return 0 ;
V_86:
return V_79 ;
}
static void F_79 ( struct V_38 * V_38 , struct V_34 * V_36 )
{
struct V_88 * V_89 = F_73 ( V_38 ) ;
F_51 ( V_36 ) ;
F_27 ( & V_38 -> V_41 ) ;
if ( ! V_89 -> V_90 && F_80 ( V_38 , V_91 ) )
V_38 -> V_92 ++ ;
F_21 ( V_93 , & V_36 -> V_73 ) ;
F_81 ( V_36 -> V_94 ) ;
F_82 ( V_36 -> V_94 , ( unsigned long ) V_36 ) ;
V_89 -> V_90 ++ ;
F_25 ( & V_36 -> V_37 ) ;
F_28 ( & V_38 -> V_41 ) ;
}
static void F_83 ( struct V_34 * V_36 )
{
struct V_38 * V_38 = V_36 -> V_95 -> V_96 -> V_97 ;
struct V_88 * V_89 = F_73 ( V_38 ) ;
F_58 ( ! F_84 ( V_36 ) ) ;
F_27 ( & V_38 -> V_41 ) ;
F_82 ( V_36 -> V_94 , 0 ) ;
F_85 ( V_36 -> V_94 ) ;
F_86 ( V_93 , & V_36 -> V_73 ) ;
V_89 -> V_90 -- ;
F_28 ( & V_38 -> V_41 ) ;
F_53 ( V_36 ) ;
}
static void
F_87 ( struct V_34 * V_36 )
{
F_88 ( V_36 -> V_94 ) ;
}
void
F_89 ( struct V_34 * V_36 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
F_21 ( V_72 , & ( V_36 ) -> V_73 ) ;
F_27 ( V_101 -> V_12 ) ;
F_90 ( V_36 , V_99 ) ;
V_101 -> V_102 -> V_103 ++ ;
F_28 ( V_101 -> V_12 ) ;
if ( ! V_101 -> V_104 ) {
F_91 ( V_36 -> V_94 , V_105 ) ;
F_92 ( V_36 -> V_94 -> V_39 -> V_65 ,
V_106 ) ;
F_93 ( V_36 -> V_95 -> V_96 -> V_97 ,
V_107 ) ;
}
}
void
F_94 ( struct V_34 * V_36 ,
struct V_100 * V_101 )
{
if ( ! F_95 ( V_72 , & ( V_36 ) -> V_73 ) )
return;
F_96 ( V_36 ) ;
V_101 -> V_102 -> V_103 -- ;
}
static void F_97 ( struct V_100 * V_101 ,
struct V_38 * V_38 )
{
V_101 -> V_12 = & V_38 -> V_41 ;
V_101 -> V_102 = & F_73 ( V_38 ) -> V_108 ;
V_101 -> V_109 = F_98 ( V_38 ) ;
V_101 -> V_104 = NULL ;
V_101 -> V_28 = & V_110 ;
}
void F_99 ( struct V_100 * V_101 ,
struct V_38 * V_38 ,
struct V_111 * V_104 )
{
if ( V_104 )
F_100 ( V_101 , V_104 ) ;
else
F_97 ( V_101 , V_38 ) ;
}
void
F_101 ( struct V_34 * V_36 , struct V_112 * V_113 ,
struct V_100 * V_101 )
{
if ( F_102 ( V_36 , V_113 , V_101 ) )
return;
F_89 ( V_36 , & V_101 -> V_102 -> V_114 , V_101 ) ;
}
static void
F_103 ( struct V_35 * V_35 )
{
F_104 ( V_35 , V_105 ) ;
F_105 ( V_35 -> V_39 -> V_65 , V_106 ) ;
}
static void
F_106 ( struct V_34 * V_36 )
{
if ( F_59 ( V_72 , & V_36 -> V_73 ) ) {
struct V_38 * V_38 = V_36 -> V_95 -> V_96 -> V_97 ;
struct V_100 V_101 ;
F_97 ( & V_101 , V_38 ) ;
if ( ! F_107 ( V_36 , & V_101 ) ) {
F_27 ( V_101 . V_12 ) ;
F_94 ( V_36 , & V_101 ) ;
F_28 ( V_101 . V_12 ) ;
}
F_103 ( V_36 -> V_94 ) ;
}
}
static inline
int F_108 ( struct V_15 * V_17 )
{
if ( V_17 -> V_14 . V_115 == V_116 )
return V_17 -> V_10 -> V_113 == NULL ;
return V_17 -> V_14 . V_115 != V_117 ;
}
static void F_97 ( struct V_100 * V_101 ,
struct V_38 * V_38 )
{
}
void F_99 ( struct V_100 * V_101 ,
struct V_38 * V_38 ,
struct V_111 * V_104 )
{
}
void
F_101 ( struct V_34 * V_36 , struct V_112 * V_113 ,
struct V_100 * V_101 )
{
}
static void
F_106 ( struct V_34 * V_36 )
{
}
static inline
int F_108 ( struct V_15 * V_17 )
{
return 0 ;
}
static void F_109 ( struct V_8 * V_9 )
{
struct V_100 V_101 ;
unsigned long V_118 = 0 ;
if ( F_59 ( V_119 , & V_9 -> V_33 ) )
goto V_21;
F_97 ( & V_101 , V_9 -> V_38 ) ;
while ( ! F_110 ( & V_9 -> V_5 ) ) {
struct V_34 * V_36 = F_111 ( V_9 -> V_5 . V_120 ) ;
V_118 += V_36 -> V_121 ;
F_96 ( V_36 ) ;
if ( F_59 ( V_122 , & V_9 -> V_33 ) &&
( V_9 -> V_123 < V_118 ) ) {
F_33 ( V_36 -> V_94 ) ;
F_19 ( V_36 -> V_95 , V_9 -> error ) ;
goto V_124;
}
if ( F_59 ( V_125 , & V_9 -> V_33 ) ) {
F_87 ( V_36 ) ;
goto V_120;
}
if ( F_59 ( V_126 , & V_9 -> V_33 ) ) {
memcpy ( & V_36 -> V_127 , V_9 -> V_14 , sizeof( V_36 -> V_127 ) ) ;
F_101 ( V_36 , V_9 -> V_113 , & V_101 ) ;
goto V_120;
}
V_124:
F_83 ( V_36 ) ;
V_120:
F_112 ( V_36 ) ;
F_46 ( V_36 -> V_94 ) ;
F_53 ( V_36 ) ;
}
V_21:
V_9 -> V_128 ( V_9 ) ;
}
static unsigned long
F_113 ( struct V_100 * V_101 )
{
return V_101 -> V_102 -> V_103 ;
}
int
F_114 ( struct V_98 * V_129 , struct V_98 * V_99 ,
struct V_100 * V_101 , int V_130 )
{
struct V_34 * V_36 , * V_131 ;
int V_60 = 0 ;
F_115 (req, tmp, src, wb_list) {
if ( ! F_51 ( V_36 ) )
continue;
F_25 ( & V_36 -> V_37 ) ;
if ( F_116 ( V_101 -> V_12 ) )
F_117 ( V_36 , V_131 , V_132 ) ;
F_94 ( V_36 , V_101 ) ;
F_90 ( V_36 , V_99 ) ;
V_60 ++ ;
if ( ( V_60 == V_130 ) && ! V_101 -> V_104 )
break;
}
return V_60 ;
}
int
F_118 ( struct V_38 * V_38 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
int V_60 = 0 ;
F_27 ( V_101 -> V_12 ) ;
if ( V_101 -> V_102 -> V_103 > 0 ) {
const int V_130 = V_133 ;
V_60 = F_114 ( & V_101 -> V_102 -> V_114 , V_99 ,
V_101 , V_130 ) ;
V_60 += F_119 ( V_38 , V_101 , V_130 - V_60 ) ;
}
F_28 ( V_101 -> V_12 ) ;
return V_60 ;
}
static unsigned long F_113 ( struct V_100 * V_101 )
{
return 0 ;
}
int F_118 ( struct V_38 * V_38 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
return 0 ;
}
static struct V_34 * F_120 ( struct V_38 * V_38 ,
struct V_35 * V_35 ,
unsigned int V_42 ,
unsigned int V_118 )
{
struct V_34 * V_36 ;
unsigned int V_134 ;
unsigned int V_44 ;
int error ;
if ( ! F_23 ( V_35 ) )
return NULL ;
V_44 = V_42 + V_118 ;
F_27 ( & V_38 -> V_41 ) ;
for (; ; ) {
V_36 = F_22 ( V_35 ) ;
if ( V_36 == NULL )
goto V_135;
V_134 = V_36 -> V_136 + V_36 -> V_121 ;
if ( V_42 > V_134
|| V_44 < V_36 -> V_136 )
goto V_137;
if ( F_51 ( V_36 ) )
break;
F_28 ( & V_38 -> V_41 ) ;
error = F_52 ( V_36 ) ;
F_53 ( V_36 ) ;
if ( error != 0 )
goto V_86;
F_27 ( & V_38 -> V_41 ) ;
}
if ( V_42 < V_36 -> V_136 ) {
V_36 -> V_136 = V_42 ;
V_36 -> V_138 = V_42 ;
}
if ( V_44 > V_134 )
V_36 -> V_121 = V_44 - V_36 -> V_136 ;
else
V_36 -> V_121 = V_134 - V_36 -> V_136 ;
V_135:
F_28 ( & V_38 -> V_41 ) ;
if ( V_36 )
F_106 ( V_36 ) ;
return V_36 ;
V_137:
F_28 ( & V_38 -> V_41 ) ;
F_53 ( V_36 ) ;
error = F_121 ( V_38 , V_35 ) ;
V_86:
return F_54 ( error ) ;
}
static struct V_34 * F_122 ( struct V_30 * V_31 ,
struct V_35 * V_35 , unsigned int V_42 , unsigned int V_118 )
{
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
struct V_34 * V_36 ;
V_36 = F_120 ( V_38 , V_35 , V_42 , V_118 ) ;
if ( V_36 != NULL )
goto V_21;
V_36 = F_123 ( V_31 , V_38 , V_35 , V_42 , V_118 ) ;
if ( F_57 ( V_36 ) )
goto V_21;
F_79 ( V_38 , V_36 ) ;
V_21:
return V_36 ;
}
static int F_124 ( struct V_30 * V_31 , struct V_35 * V_35 ,
unsigned int V_42 , unsigned int V_43 )
{
struct V_34 * V_36 ;
V_36 = F_122 ( V_31 , V_35 , V_42 , V_43 ) ;
if ( F_57 ( V_36 ) )
return F_56 ( V_36 ) ;
F_29 ( V_35 , V_42 , V_43 ) ;
F_36 ( V_35 , V_36 -> V_138 , V_36 -> V_121 ) ;
F_87 ( V_36 ) ;
F_125 ( V_36 ) ;
return 0 ;
}
int F_126 ( struct V_139 * V_139 , struct V_35 * V_35 )
{
struct V_30 * V_31 = F_127 ( V_139 ) ;
struct V_34 * V_36 ;
int V_140 , V_141 ;
do {
V_36 = F_26 ( V_35 ) ;
if ( V_36 == NULL )
return 0 ;
V_140 = V_36 -> V_94 != V_35 || V_36 -> V_95 != V_31 ||
V_36 -> V_142 -> V_143 != V_144 -> V_145 ||
V_36 -> V_142 -> V_146 != V_144 -> V_147 ;
F_53 ( V_36 ) ;
if ( ! V_140 )
return 0 ;
V_141 = F_121 ( V_35 -> V_39 -> V_40 , V_35 ) ;
} while ( V_141 == 0 );
return V_141 ;
}
static bool F_128 ( struct V_35 * V_35 , struct V_38 * V_38 )
{
if ( F_129 ( V_38 ) )
goto V_21;
if ( F_73 ( V_38 ) -> V_148 & V_149 )
return false ;
V_21:
return F_37 ( V_35 ) != 0 ;
}
int F_130 ( struct V_139 * V_139 , struct V_35 * V_35 ,
unsigned int V_42 , unsigned int V_43 )
{
struct V_30 * V_31 = F_127 ( V_139 ) ;
struct V_38 * V_38 = V_35 -> V_39 -> V_40 ;
int V_141 = 0 ;
F_32 ( V_38 , V_150 ) ;
F_131 ( L_1 ,
V_139 -> V_151 . V_96 -> V_152 -> V_153 . V_154 ,
V_139 -> V_151 . V_96 -> V_153 . V_154 , V_43 ,
( long long ) ( F_132 ( V_35 ) + V_42 ) ) ;
if ( F_128 ( V_35 , V_38 ) &&
V_38 -> V_155 == NULL &&
! ( V_139 -> V_156 & V_157 ) ) {
V_43 = V_130 ( V_43 + V_42 , F_38 ( V_35 ) ) ;
V_42 = 0 ;
}
V_141 = F_124 ( V_31 , V_35 , V_42 , V_43 ) ;
if ( V_141 < 0 )
F_33 ( V_35 ) ;
else
F_88 ( V_35 ) ;
F_131 ( L_2 ,
V_141 , ( long long ) F_30 ( V_38 ) ) ;
return V_141 ;
}
static int F_133 ( int V_158 )
{
switch ( V_158 & ( V_54 | V_58 ) ) {
case V_54 :
return V_159 ;
case V_58 :
return V_160 ;
}
return V_161 ;
}
int F_134 ( struct V_162 * V_163 ,
struct V_15 * V_17 ,
const struct V_164 * V_165 ,
int V_158 , int V_33 )
{
struct V_38 * V_38 = V_17 -> V_10 -> V_38 ;
int V_166 = F_133 ( V_158 ) ;
struct V_167 * V_168 ;
struct V_169 V_170 = {
. V_171 = & V_17 -> args ,
. V_172 = & V_17 -> V_173 ,
. V_174 = V_17 -> V_10 -> V_175 ,
} ;
struct V_176 V_177 = {
. V_178 = V_163 ,
. V_168 = & V_17 -> V_168 ,
. V_169 = & V_170 ,
. V_179 = V_165 ,
. V_180 = V_17 ,
. V_181 = V_182 ,
. V_33 = V_183 | V_33 ,
. V_166 = V_166 ,
} ;
int V_60 = 0 ;
F_135 ( V_38 ) -> F_136 ( V_17 , & V_170 ) ;
F_131 ( L_3
L_4 ,
V_17 -> V_168 . V_184 ,
V_38 -> V_185 -> V_186 ,
( long long ) F_137 ( V_38 ) ,
V_17 -> args . V_43 ,
( unsigned long long ) V_17 -> args . V_42 ) ;
V_168 = F_138 ( & V_177 ) ;
if ( F_57 ( V_168 ) ) {
V_60 = F_56 ( V_168 ) ;
goto V_21;
}
if ( V_158 & V_187 ) {
V_60 = F_139 ( V_168 ) ;
if ( V_60 == 0 )
V_60 = V_168 -> V_188 ;
}
F_140 ( V_168 ) ;
V_21:
return V_60 ;
}
static void F_141 ( struct V_15 * V_17 ,
unsigned int V_43 , unsigned int V_42 ,
int V_158 , struct V_100 * V_101 )
{
struct V_34 * V_36 = V_17 -> V_10 -> V_36 ;
V_17 -> args . V_189 = F_142 ( V_17 -> V_10 -> V_38 ) ;
V_17 -> args . V_42 = F_143 ( V_36 ) + V_42 ;
V_17 -> V_190 = V_17 -> args . V_42 ;
V_17 -> args . V_191 = V_36 -> V_138 + V_42 ;
V_17 -> args . V_5 = V_17 -> V_5 . V_26 ;
V_17 -> args . V_43 = V_43 ;
V_17 -> args . V_25 = F_144 ( V_36 -> V_95 ) ;
V_17 -> args . V_192 = V_36 -> V_142 ;
V_17 -> args . V_193 = V_194 ;
switch ( V_158 & ( V_55 | V_59 ) ) {
case 0 :
break;
case V_59 :
if ( F_113 ( V_101 ) )
break;
default:
V_17 -> args . V_193 = V_117 ;
}
V_17 -> V_173 . V_195 = & V_17 -> V_195 ;
V_17 -> V_173 . V_43 = V_43 ;
V_17 -> V_173 . V_14 = & V_17 -> V_14 ;
F_145 ( & V_17 -> V_195 ) ;
}
static int F_146 ( struct V_15 * V_17 ,
const struct V_164 * V_165 ,
int V_158 )
{
struct V_38 * V_38 = V_17 -> V_10 -> V_38 ;
return F_134 ( F_147 ( V_38 ) , V_17 , V_165 , V_158 , 0 ) ;
}
static int F_148 ( struct V_98 * V_196 ,
const struct V_164 * V_165 ,
int V_158 )
{
struct V_15 * V_17 ;
int V_60 = 0 ;
while ( ! F_110 ( V_196 ) ) {
int V_197 ;
V_17 = F_149 ( V_196 , struct V_15 , V_114 ) ;
F_150 ( & V_17 -> V_114 ) ;
V_197 = F_146 ( V_17 , V_165 , V_158 ) ;
if ( V_60 == 0 )
V_60 = V_197 ;
}
return V_60 ;
}
static void F_61 ( struct V_34 * V_36 )
{
F_87 ( V_36 ) ;
F_112 ( V_36 ) ;
F_46 ( V_36 -> V_94 ) ;
F_53 ( V_36 ) ;
}
static void F_151 ( struct V_98 * V_196 )
{
struct V_34 * V_36 ;
while ( ! F_110 ( V_196 ) ) {
V_36 = F_111 ( V_196 -> V_120 ) ;
F_96 ( V_36 ) ;
F_61 ( V_36 ) ;
}
}
static void F_152 ( struct V_70 * V_198 ,
struct V_8 * V_9 )
{
F_21 ( V_119 , & V_9 -> V_33 ) ;
while ( ! F_110 ( & V_9 -> V_11 ) ) {
struct V_15 * V_17 = F_149 ( & V_9 -> V_11 ,
struct V_15 , V_114 ) ;
F_153 ( & V_17 -> V_114 ) ;
F_16 ( V_17 ) ;
}
V_198 -> V_199 -> V_200 ( & V_198 -> V_201 ) ;
}
static int F_154 ( struct V_70 * V_198 ,
struct V_8 * V_9 )
{
struct V_34 * V_36 = V_9 -> V_36 ;
struct V_35 * V_35 = V_36 -> V_94 ;
struct V_15 * V_17 ;
T_3 V_202 = V_198 -> V_203 , V_204 ;
unsigned int V_42 ;
int V_205 = 0 ;
struct V_100 V_101 ;
F_99 ( & V_101 , V_198 -> V_206 , V_198 -> V_207 ) ;
if ( ( V_198 -> V_208 & V_59 ) &&
( V_198 -> V_209 || F_113 ( & V_101 ) ||
V_198 -> V_210 > V_202 ) )
V_198 -> V_208 &= ~ V_59 ;
V_42 = 0 ;
V_204 = V_198 -> V_210 ;
do {
T_3 V_211 = F_155 ( V_204 , V_202 ) ;
V_17 = F_9 ( V_9 , 1 ) ;
if ( ! V_17 ) {
F_152 ( V_198 , V_9 ) ;
return - V_212 ;
}
V_17 -> V_5 . V_26 [ 0 ] = V_35 ;
F_141 ( V_17 , V_211 , V_42 , V_198 -> V_208 , & V_101 ) ;
F_156 ( & V_17 -> V_114 , & V_9 -> V_11 ) ;
V_205 ++ ;
V_204 -= V_211 ;
V_42 += V_211 ;
} while ( V_204 != 0 );
F_96 ( V_36 ) ;
F_90 ( V_36 , & V_9 -> V_5 ) ;
V_198 -> V_213 = & V_214 ;
return 0 ;
}
static int F_157 ( struct V_70 * V_198 ,
struct V_8 * V_9 )
{
struct V_34 * V_36 ;
struct V_35 * * V_5 ;
struct V_15 * V_17 ;
struct V_98 * V_196 = & V_198 -> V_201 ;
struct V_100 V_101 ;
V_17 = F_9 ( V_9 , F_158 ( V_198 -> V_215 ,
V_198 -> V_210 ) ) ;
if ( ! V_17 ) {
F_152 ( V_198 , V_9 ) ;
return - V_212 ;
}
F_99 ( & V_101 , V_198 -> V_206 , V_198 -> V_207 ) ;
V_5 = V_17 -> V_5 . V_26 ;
while ( ! F_110 ( V_196 ) ) {
V_36 = F_111 ( V_196 -> V_120 ) ;
F_96 ( V_36 ) ;
F_90 ( V_36 , & V_9 -> V_5 ) ;
* V_5 ++ = V_36 -> V_94 ;
}
if ( ( V_198 -> V_208 & V_59 ) &&
( V_198 -> V_209 || F_113 ( & V_101 ) ) )
V_198 -> V_208 &= ~ V_59 ;
F_141 ( V_17 , V_198 -> V_210 , 0 , V_198 -> V_208 , & V_101 ) ;
F_156 ( & V_17 -> V_114 , & V_9 -> V_11 ) ;
V_198 -> V_213 = & V_214 ;
return 0 ;
}
int F_159 ( struct V_70 * V_198 ,
struct V_8 * V_9 )
{
if ( V_198 -> V_203 < V_216 )
return F_154 ( V_198 , V_9 ) ;
return F_157 ( V_198 , V_9 ) ;
}
static int F_160 ( struct V_70 * V_198 )
{
struct V_6 * V_22 ;
struct V_8 * V_9 ;
int V_60 ;
V_22 = F_6 () ;
if ( ! V_22 ) {
V_198 -> V_199 -> V_200 ( & V_198 -> V_201 ) ;
return - V_212 ;
}
V_9 = & V_22 -> V_10 ;
F_161 ( V_198 , V_9 , F_15 ) ;
F_13 ( & V_9 -> V_13 ) ;
V_60 = F_159 ( V_198 , V_9 ) ;
if ( V_60 == 0 )
V_60 = F_148 ( & V_9 -> V_11 ,
V_198 -> V_213 ,
V_198 -> V_208 ) ;
if ( F_18 ( & V_9 -> V_13 ) )
V_9 -> V_28 -> V_29 ( V_9 ) ;
return V_60 ;
}
void F_162 ( struct V_70 * V_71 ,
struct V_38 * V_38 , int V_217 ,
const struct V_218 * V_219 )
{
F_163 ( V_71 , V_38 , & V_220 , V_219 ,
F_43 ( V_38 ) -> V_202 , V_217 ) ;
}
void F_164 ( struct V_70 * V_71 )
{
V_71 -> V_221 = & V_220 ;
V_71 -> V_203 = F_43 ( V_71 -> V_206 ) -> V_202 ;
}
void F_67 ( struct V_70 * V_71 ,
struct V_38 * V_38 , int V_217 ,
const struct V_218 * V_219 )
{
if ( ! F_165 ( V_71 , V_38 , V_217 , V_219 ) )
F_162 ( V_71 , V_38 , V_217 , V_219 ) ;
}
void F_166 ( struct V_167 * V_168 , void * V_222 )
{
struct V_15 * V_17 = V_222 ;
F_135 ( V_17 -> V_10 -> V_38 ) -> F_167 ( V_168 , V_17 ) ;
}
void F_168 ( struct V_167 * V_168 , void * V_222 )
{
struct V_1 * V_17 = V_222 ;
F_135 ( V_17 -> V_38 ) -> F_169 ( V_168 , V_17 ) ;
}
static void F_170 ( struct V_167 * V_168 , void * V_222 )
{
struct V_15 * V_17 = V_222 ;
F_171 ( V_168 , V_17 ) ;
}
static void F_172 ( void * V_222 )
{
struct V_15 * V_17 = V_222 ;
struct V_8 * V_9 = V_17 -> V_10 ;
int V_141 = V_17 -> V_168 . V_188 ;
if ( ( V_141 >= 0 ) && F_108 ( V_17 ) ) {
F_27 ( & V_9 -> V_12 ) ;
if ( F_59 ( V_125 , & V_9 -> V_33 ) )
;
else if ( ! F_173 ( V_126 , & V_9 -> V_33 ) )
memcpy ( V_9 -> V_14 , & V_17 -> V_14 , sizeof( * V_9 -> V_14 ) ) ;
else if ( memcmp ( V_9 -> V_14 , & V_17 -> V_14 , sizeof( * V_9 -> V_14 ) ) )
F_21 ( V_125 , & V_9 -> V_33 ) ;
F_28 ( & V_9 -> V_12 ) ;
}
F_16 ( V_17 ) ;
}
void F_171 ( struct V_167 * V_168 , struct V_15 * V_17 )
{
struct V_223 * V_224 = & V_17 -> args ;
struct V_225 * V_226 = & V_17 -> V_173 ;
struct V_38 * V_38 = V_17 -> V_10 -> V_38 ;
int V_141 ;
F_131 ( L_5 ,
V_168 -> V_184 , V_168 -> V_188 ) ;
V_141 = F_135 ( V_38 ) -> F_174 ( V_168 , V_17 ) ;
if ( V_141 != 0 )
return;
F_63 ( V_38 , V_227 , V_226 -> V_43 ) ;
#if F_175 ( V_228 ) || F_175 ( V_229 )
if ( V_226 -> V_14 -> V_115 < V_224 -> V_193 && V_168 -> V_188 >= 0 ) {
static unsigned long V_230 ;
if ( F_176 ( V_230 , V_231 ) ) {
F_131 ( L_6
L_7 ,
F_43 ( V_38 ) -> V_232 -> V_233 ,
V_226 -> V_14 -> V_115 , V_224 -> V_193 ) ;
V_230 = V_231 + 300 * V_234 ;
}
}
#endif
if ( V_168 -> V_188 < 0 )
F_177 ( V_17 -> V_10 , V_168 -> V_188 , V_224 -> V_42 ) ;
else if ( V_226 -> V_43 < V_224 -> V_43 ) {
static unsigned long V_230 ;
F_32 ( V_38 , V_235 ) ;
if ( V_226 -> V_43 == 0 ) {
if ( F_176 ( V_230 , V_231 ) ) {
F_178 ( V_236
L_8 ,
V_224 -> V_43 ) ;
V_230 = V_231 + 300 * V_234 ;
}
F_177 ( V_17 -> V_10 , - V_237 , V_224 -> V_42 ) ;
V_168 -> V_188 = - V_237 ;
return;
}
if ( V_226 -> V_14 -> V_115 != V_194 ) {
V_17 -> V_190 += V_226 -> V_43 ;
V_224 -> V_42 += V_226 -> V_43 ;
V_224 -> V_191 += V_226 -> V_43 ;
V_224 -> V_43 -= V_226 -> V_43 ;
} else {
V_224 -> V_193 = V_117 ;
}
F_179 ( V_168 ) ;
}
}
static int F_180 ( struct V_88 * V_89 , int V_238 )
{
int V_60 ;
if ( ! F_173 ( V_239 , & V_89 -> V_33 ) )
return 1 ;
if ( ! V_238 )
return 0 ;
V_60 = F_181 ( & V_89 -> V_33 ,
V_239 ,
V_84 ,
V_85 ) ;
return ( V_60 < 0 ) ? V_60 : 1 ;
}
static void F_182 ( struct V_88 * V_89 )
{
F_86 ( V_239 , & V_89 -> V_33 ) ;
F_77 () ;
F_78 ( & V_89 -> V_33 , V_239 ) ;
}
void F_183 ( struct V_1 * V_17 )
{
F_17 ( V_17 -> V_25 ) ;
F_4 ( V_17 ) ;
}
int F_184 ( struct V_162 * V_163 , struct V_1 * V_17 ,
const struct V_164 * V_165 ,
int V_158 , int V_33 )
{
struct V_167 * V_168 ;
int V_166 = F_133 ( V_158 ) ;
struct V_169 V_170 = {
. V_171 = & V_17 -> args ,
. V_172 = & V_17 -> V_173 ,
. V_174 = V_17 -> V_175 ,
} ;
struct V_176 V_177 = {
. V_168 = & V_17 -> V_168 ,
. V_178 = V_163 ,
. V_169 = & V_170 ,
. V_179 = V_165 ,
. V_180 = V_17 ,
. V_181 = V_182 ,
. V_33 = V_183 | V_33 ,
. V_166 = V_166 ,
} ;
F_135 ( V_17 -> V_38 ) -> F_185 ( V_17 , & V_170 ) ;
F_131 ( L_9 , V_17 -> V_168 . V_184 ) ;
V_168 = F_138 ( & V_177 ) ;
if ( F_57 ( V_168 ) )
return F_56 ( V_168 ) ;
if ( V_158 & V_187 )
F_139 ( V_168 ) ;
F_140 ( V_168 ) ;
return 0 ;
}
void F_186 ( struct V_1 * V_17 ,
struct V_98 * V_196 ,
struct V_112 * V_113 ,
struct V_100 * V_101 )
{
struct V_34 * V_240 = F_111 ( V_196 -> V_120 ) ;
struct V_38 * V_38 = V_240 -> V_95 -> V_96 -> V_97 ;
F_187 ( V_196 , & V_17 -> V_5 ) ;
V_17 -> V_38 = V_38 ;
V_17 -> V_175 = V_240 -> V_95 -> V_175 ;
V_17 -> V_113 = V_113 ;
V_17 -> V_241 = & V_242 ;
V_17 -> V_28 = V_101 -> V_28 ;
V_17 -> V_104 = V_101 -> V_104 ;
V_17 -> args . V_189 = F_142 ( V_17 -> V_38 ) ;
V_17 -> args . V_42 = 0 ;
V_17 -> args . V_43 = 0 ;
V_17 -> V_25 = F_144 ( V_240 -> V_95 ) ;
V_17 -> V_173 . V_195 = & V_17 -> V_195 ;
V_17 -> V_173 . V_14 = & V_17 -> V_14 ;
F_145 ( & V_17 -> V_195 ) ;
}
void F_188 ( struct V_98 * V_243 ,
struct V_112 * V_113 ,
struct V_100 * V_101 )
{
struct V_34 * V_36 ;
while ( ! F_110 ( V_243 ) ) {
V_36 = F_111 ( V_243 -> V_120 ) ;
F_96 ( V_36 ) ;
F_101 ( V_36 , V_113 , V_101 ) ;
if ( ! V_101 -> V_104 ) {
F_104 ( V_36 -> V_94 , V_105 ) ;
F_105 ( V_36 -> V_94 -> V_39 -> V_65 ,
V_106 ) ;
}
F_125 ( V_36 ) ;
}
}
static int
F_189 ( struct V_38 * V_38 , struct V_98 * V_196 , int V_158 ,
struct V_100 * V_101 )
{
struct V_1 * V_17 ;
V_17 = F_1 () ;
if ( ! V_17 )
goto V_244;
F_186 ( V_17 , V_196 , NULL , V_101 ) ;
F_13 ( & V_101 -> V_102 -> V_245 ) ;
return F_184 ( F_147 ( V_38 ) , V_17 , V_17 -> V_241 ,
V_158 , 0 ) ;
V_244:
F_188 ( V_196 , NULL , V_101 ) ;
V_101 -> V_28 -> V_200 ( F_73 ( V_38 ) ) ;
return - V_212 ;
}
static void F_190 ( struct V_167 * V_168 , void * V_222 )
{
struct V_1 * V_17 = V_222 ;
F_131 ( L_10 ,
V_168 -> V_184 , V_168 -> V_188 ) ;
F_135 ( V_17 -> V_38 ) -> F_191 ( V_168 , V_17 ) ;
}
static void F_192 ( struct V_1 * V_17 )
{
struct V_34 * V_36 ;
int V_141 = V_17 -> V_168 . V_188 ;
struct V_100 V_101 ;
while ( ! F_110 ( & V_17 -> V_5 ) ) {
V_36 = F_111 ( V_17 -> V_5 . V_120 ) ;
F_96 ( V_36 ) ;
F_103 ( V_36 -> V_94 ) ;
F_131 ( L_11 ,
V_36 -> V_95 -> V_96 -> V_246 -> V_186 ,
( long long ) F_137 ( V_36 -> V_95 -> V_96 -> V_97 ) ,
V_36 -> V_121 ,
( long long ) F_143 ( V_36 ) ) ;
if ( V_141 < 0 ) {
F_19 ( V_36 -> V_95 , V_141 ) ;
F_83 ( V_36 ) ;
F_131 ( L_12 , V_141 ) ;
goto V_120;
}
if ( ! memcmp ( V_36 -> V_127 . V_247 , V_17 -> V_14 . V_247 , sizeof( V_17 -> V_14 . V_247 ) ) ) {
F_83 ( V_36 ) ;
F_131 ( L_13 ) ;
goto V_120;
}
F_131 ( L_14 ) ;
F_87 ( V_36 ) ;
V_120:
F_125 ( V_36 ) ;
}
F_99 ( & V_101 , V_17 -> V_38 , V_17 -> V_104 ) ;
if ( F_18 ( & V_101 . V_102 -> V_245 ) )
F_182 ( F_73 ( V_17 -> V_38 ) ) ;
}
static void F_193 ( void * V_222 )
{
struct V_1 * V_17 = V_222 ;
V_17 -> V_28 -> V_29 ( V_17 ) ;
F_183 ( V_222 ) ;
}
int F_194 ( struct V_38 * V_38 , struct V_98 * V_196 ,
int V_158 , struct V_100 * V_101 )
{
int V_141 ;
V_141 = F_195 ( V_38 , V_196 , V_158 , V_101 ) ;
if ( V_141 == V_248 )
V_141 = F_189 ( V_38 , V_196 , V_158 , V_101 ) ;
return V_141 ;
}
int F_196 ( struct V_38 * V_38 , int V_158 )
{
F_197 ( V_196 ) ;
struct V_100 V_101 ;
int V_238 = V_158 & V_187 ;
int V_173 ;
V_173 = F_180 ( F_73 ( V_38 ) , V_238 ) ;
if ( V_173 <= 0 )
goto V_249;
F_97 ( & V_101 , V_38 ) ;
V_173 = F_118 ( V_38 , & V_196 , & V_101 ) ;
if ( V_173 ) {
int error ;
error = F_194 ( V_38 , & V_196 , V_158 , & V_101 ) ;
if ( error < 0 )
return error ;
if ( ! V_238 )
goto V_249;
error = F_198 ( & F_73 ( V_38 ) -> V_33 ,
V_239 ,
V_84 ,
V_85 ) ;
if ( error < 0 )
return error ;
} else
F_182 ( F_73 ( V_38 ) ) ;
return V_173 ;
V_249:
F_93 ( V_38 , V_107 ) ;
return V_173 ;
}
static int F_199 ( struct V_38 * V_38 , struct V_51 * V_52 )
{
struct V_88 * V_89 = F_73 ( V_38 ) ;
int V_33 = V_187 ;
int V_60 = 0 ;
if ( ! V_89 -> V_108 . V_103 )
return V_60 ;
if ( V_52 -> V_77 == V_78 ) {
if ( V_89 -> V_108 . V_103 <= ( V_89 -> V_90 >> 1 ) )
goto V_249;
V_33 = 0 ;
}
V_60 = F_196 ( V_38 , V_33 ) ;
if ( V_60 >= 0 ) {
if ( V_52 -> V_77 == V_78 ) {
if ( V_60 < V_52 -> V_250 )
V_52 -> V_250 -= V_60 ;
else
V_52 -> V_250 = 0 ;
}
return 0 ;
}
V_249:
F_93 ( V_38 , V_107 ) ;
return V_60 ;
}
static int F_199 ( struct V_38 * V_38 , struct V_51 * V_52 )
{
return 0 ;
}
int F_200 ( struct V_38 * V_38 , struct V_51 * V_52 )
{
int V_60 ;
V_60 = F_199 ( V_38 , V_52 ) ;
if ( V_60 >= 0 && F_59 ( V_251 , & F_73 ( V_38 ) -> V_33 ) ) {
int V_141 ;
bool V_252 = true ;
if ( V_52 -> V_77 == V_78 )
V_252 = false ;
V_141 = F_201 ( V_38 , V_252 ) ;
if ( V_141 < 0 )
return V_141 ;
}
return V_60 ;
}
int F_202 ( struct V_38 * V_38 )
{
struct V_51 V_52 = {
. V_77 = V_253 ,
. V_250 = V_254 ,
. V_255 = 0 ,
. V_256 = V_257 ,
} ;
return F_203 ( V_38 , & V_52 ) ;
}
int F_204 ( struct V_38 * V_38 , struct V_35 * V_35 )
{
struct V_34 * V_36 ;
int V_60 = 0 ;
F_58 ( ! F_205 ( V_35 ) ) ;
for (; ; ) {
F_206 ( V_35 ) ;
V_36 = F_26 ( V_35 ) ;
if ( V_36 == NULL )
break;
if ( F_51 ( V_36 ) ) {
F_106 ( V_36 ) ;
F_83 ( V_36 ) ;
F_207 ( V_35 , V_216 ) ;
F_125 ( V_36 ) ;
break;
}
V_60 = F_52 ( V_36 ) ;
F_53 ( V_36 ) ;
if ( V_60 < 0 )
break;
}
return V_60 ;
}
int F_121 ( struct V_38 * V_38 , struct V_35 * V_35 )
{
T_1 V_255 = F_132 ( V_35 ) ;
T_1 V_256 = V_255 + ( T_1 ) ( V_216 - 1 ) ;
struct V_51 V_52 = {
. V_77 = V_253 ,
. V_250 = 0 ,
. V_255 = V_255 ,
. V_256 = V_256 ,
} ;
int V_60 ;
for (; ; ) {
F_206 ( V_35 ) ;
if ( F_208 ( V_35 ) ) {
V_60 = F_66 ( V_35 , & V_52 ) ;
if ( V_60 < 0 )
goto V_258;
continue;
}
if ( ! F_23 ( V_35 ) )
break;
V_60 = F_196 ( V_38 , V_187 ) ;
if ( V_60 < 0 )
goto V_258;
}
return 0 ;
V_258:
return V_60 ;
}
int F_209 ( struct V_81 * V_39 , struct V_35 * V_259 ,
struct V_35 * V_35 , enum V_260 V_261 )
{
if ( F_23 ( V_35 ) )
return - V_262 ;
F_210 ( V_35 , V_20 ) ;
return F_211 ( V_39 , V_259 , V_35 , V_261 ) ;
}
int T_4 F_212 ( void )
{
V_263 = F_213 ( L_15 ,
sizeof( struct V_6 ) ,
0 , V_264 ,
NULL ) ;
if ( V_263 == NULL )
return - V_212 ;
V_7 = F_214 ( V_265 ,
V_263 ) ;
if ( V_7 == NULL )
return - V_212 ;
V_266 = F_213 ( L_16 ,
sizeof( struct V_1 ) ,
0 , V_264 ,
NULL ) ;
if ( V_266 == NULL )
return - V_212 ;
V_3 = F_214 ( V_267 ,
V_263 ) ;
if ( V_3 == NULL )
return - V_212 ;
V_268 = ( 16 * F_215 ( V_269 ) ) << ( V_270 - 10 ) ;
if ( V_268 > 256 * 1024 )
V_268 = 256 * 1024 ;
return 0 ;
}
void F_216 ( void )
{
F_217 ( V_3 ) ;
F_217 ( V_7 ) ;
F_218 ( V_263 ) ;
}
