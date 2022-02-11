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
if ( V_23 == & V_24 -> V_19 ) {
V_23 -> V_10 = NULL ;
V_23 = NULL ;
}
if ( F_18 ( & V_9 -> V_13 ) )
V_9 -> V_28 -> V_29 ( V_9 ) ;
F_14 ( V_23 ) ;
}
static void F_19 ( struct V_30 * V_31 , int error )
{
V_31 -> error = error ;
F_20 () ;
F_21 ( V_32 , & V_31 -> V_33 ) ;
}
static struct V_34 *
F_22 ( struct V_35 * V_36 , struct V_37 * V_37 )
{
struct V_34 * V_38 = NULL ;
if ( F_23 ( V_37 ) )
V_38 = (struct V_34 * ) F_24 ( V_37 ) ;
else if ( F_25 ( F_26 ( V_37 ) ) ) {
struct V_34 * V_39 , * V_40 ;
F_27 (freq, t, &nfsi->commit_info.list, wb_list) {
if ( V_39 -> V_41 == V_37 ) {
V_38 = V_39 ;
break;
}
}
}
if ( V_38 )
F_28 ( & V_38 -> V_42 ) ;
return V_38 ;
}
static struct V_34 * F_29 ( struct V_37 * V_37 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_34 * V_38 = NULL ;
F_31 ( & V_43 -> V_45 ) ;
V_38 = F_22 ( F_32 ( V_43 ) , V_37 ) ;
F_33 ( & V_43 -> V_45 ) ;
return V_38 ;
}
static void F_34 ( struct V_37 * V_37 , unsigned int V_46 , unsigned int V_47 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
T_1 V_48 , V_49 ;
T_2 V_50 ;
F_31 ( & V_43 -> V_45 ) ;
V_49 = F_35 ( V_43 ) ;
V_50 = ( V_49 - 1 ) >> V_51 ;
if ( V_49 > 0 && F_36 ( V_37 ) < V_50 )
goto V_21;
V_48 = F_37 ( V_37 ) + ( ( T_1 ) V_46 + V_47 ) ;
if ( V_49 >= V_48 )
goto V_21;
F_38 ( V_43 , V_48 ) ;
F_39 ( V_43 , V_52 ) ;
V_21:
F_33 ( & V_43 -> V_45 ) ;
}
static void F_40 ( struct V_37 * V_37 )
{
F_41 ( F_30 ( V_37 ) -> V_44 , F_30 ( V_37 ) ) ;
}
static void F_42 ( struct V_37 * V_37 , unsigned int V_53 , unsigned int V_47 )
{
if ( F_43 ( V_37 ) )
return;
if ( V_53 != 0 )
return;
if ( V_47 != F_44 ( V_37 ) )
return;
F_45 ( V_37 ) ;
}
static int F_46 ( struct V_54 * V_55 )
{
if ( V_55 -> V_56 )
return V_57 | V_58 ;
if ( V_55 -> V_59 || V_55 -> V_60 )
return V_61 | V_62 ;
return V_62 ;
}
static void F_47 ( struct V_37 * V_37 )
{
struct V_63 * V_64 = F_48 ( F_30 ( V_37 ) -> V_44 ) ;
int V_65 = F_49 ( V_37 ) ;
F_50 ( V_65 != 0 ) ;
if ( F_51 ( & V_64 -> V_66 ) >
V_67 ) {
F_52 ( & V_64 -> V_68 ,
V_69 ) ;
}
}
static void F_53 ( struct V_37 * V_37 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_63 * V_64 = F_48 ( V_43 ) ;
F_54 ( V_37 ) ;
if ( F_55 ( & V_64 -> V_66 ) < V_70 )
F_56 ( & V_64 -> V_68 , V_69 ) ;
}
static struct V_34 * F_57 ( struct V_37 * V_37 , bool V_71 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_34 * V_38 ;
int V_65 ;
F_31 ( & V_43 -> V_45 ) ;
for (; ; ) {
V_38 = F_22 ( F_32 ( V_43 ) , V_37 ) ;
if ( V_38 == NULL )
break;
if ( F_58 ( V_38 ) )
break;
F_33 ( & V_43 -> V_45 ) ;
if ( ! V_71 )
V_65 = F_59 ( V_38 ) ;
else
V_65 = - V_72 ;
F_60 ( V_38 ) ;
if ( V_65 != 0 )
return F_61 ( V_65 ) ;
F_31 ( & V_43 -> V_45 ) ;
}
F_33 ( & V_43 -> V_45 ) ;
return V_38 ;
}
static int F_62 ( struct V_73 * V_74 ,
struct V_37 * V_37 , bool V_71 )
{
struct V_34 * V_38 ;
int V_65 = 0 ;
V_38 = F_57 ( V_37 , V_71 ) ;
if ( ! V_38 )
goto V_21;
V_65 = F_63 ( V_38 ) ;
if ( F_64 ( V_38 ) )
goto V_21;
F_47 ( V_37 ) ;
F_50 ( F_65 ( V_75 , & V_38 -> V_76 ) ) ;
V_65 = 0 ;
if ( ! F_66 ( V_74 , V_38 ) ) {
F_67 ( V_38 ) ;
V_65 = V_74 -> V_77 ;
}
V_21:
return V_65 ;
}
static int F_68 ( struct V_37 * V_37 , struct V_54 * V_55 , struct V_73 * V_74 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
int V_65 ;
F_39 ( V_43 , V_78 ) ;
F_69 ( V_43 , V_79 , 1 ) ;
F_70 ( V_74 , F_36 ( V_37 ) ) ;
V_65 = F_62 ( V_74 , V_37 , V_55 -> V_80 == V_81 ) ;
if ( V_65 == - V_72 ) {
F_71 ( V_55 , V_37 ) ;
V_65 = 0 ;
}
return V_65 ;
}
static int F_72 ( struct V_37 * V_37 , struct V_54 * V_55 )
{
struct V_73 V_74 ;
int V_82 ;
F_73 ( F_30 ( V_37 ) -> V_44 ) -> F_74 ( & V_74 ,
V_37 -> V_83 -> V_44 ,
F_46 ( V_55 ) ,
& V_84 ) ;
V_82 = F_68 ( V_37 , V_55 , & V_74 ) ;
F_75 ( & V_74 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_74 . V_77 < 0 )
return V_74 . V_77 ;
return 0 ;
}
int F_76 ( struct V_37 * V_37 , struct V_54 * V_55 )
{
int V_65 ;
V_65 = F_72 ( V_37 , V_55 ) ;
F_77 ( V_37 ) ;
return V_65 ;
}
static int F_78 ( struct V_37 * V_37 , struct V_54 * V_55 , void * V_17 )
{
int V_65 ;
V_65 = F_68 ( V_37 , V_55 , V_17 ) ;
F_77 ( V_37 ) ;
return V_65 ;
}
int F_79 ( struct V_85 * V_83 , struct V_54 * V_55 )
{
struct V_43 * V_43 = V_83 -> V_44 ;
unsigned long * V_86 = & F_32 ( V_43 ) -> V_33 ;
struct V_73 V_74 ;
int V_82 ;
V_82 = F_80 ( V_86 , V_87 ,
V_88 , V_89 ) ;
if ( V_82 )
goto V_90;
F_39 ( V_43 , V_91 ) ;
F_73 ( V_43 ) -> F_74 ( & V_74 , V_43 , F_46 ( V_55 ) , & V_84 ) ;
V_82 = F_81 ( V_83 , V_55 , F_78 , & V_74 ) ;
F_75 ( & V_74 ) ;
F_82 ( V_87 , V_86 ) ;
F_83 () ;
F_84 ( V_86 , V_87 ) ;
if ( V_82 < 0 )
goto V_90;
V_82 = V_74 . V_77 ;
if ( V_82 < 0 )
goto V_90;
return 0 ;
V_90:
return V_82 ;
}
static void F_85 ( struct V_43 * V_43 , struct V_34 * V_38 )
{
struct V_35 * V_36 = F_32 ( V_43 ) ;
F_58 ( V_38 ) ;
F_31 ( & V_43 -> V_45 ) ;
if ( ! V_36 -> V_92 && F_73 ( V_43 ) -> F_86 ( V_43 , V_93 ) )
V_43 -> V_94 ++ ;
if ( F_87 ( ! F_26 ( V_38 -> V_41 ) ) ) {
F_21 ( V_95 , & V_38 -> V_76 ) ;
F_88 ( V_38 -> V_41 ) ;
F_89 ( V_38 -> V_41 , ( unsigned long ) V_38 ) ;
}
V_36 -> V_92 ++ ;
F_28 ( & V_38 -> V_42 ) ;
F_33 ( & V_43 -> V_45 ) ;
}
static void F_90 ( struct V_34 * V_38 )
{
struct V_43 * V_43 = V_38 -> V_96 -> V_97 -> V_98 ;
struct V_35 * V_36 = F_32 ( V_43 ) ;
F_31 ( & V_43 -> V_45 ) ;
if ( F_87 ( ! F_26 ( V_38 -> V_41 ) ) ) {
F_89 ( V_38 -> V_41 , 0 ) ;
F_91 ( V_38 -> V_41 ) ;
F_92 ( V_95 , & V_38 -> V_76 ) ;
}
V_36 -> V_92 -- ;
F_33 ( & V_43 -> V_45 ) ;
F_60 ( V_38 ) ;
}
static void
F_93 ( struct V_34 * V_38 )
{
F_94 ( V_38 -> V_41 ) ;
}
void
F_95 ( struct V_34 * V_38 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
F_21 ( V_75 , & ( V_38 ) -> V_76 ) ;
F_31 ( V_102 -> V_12 ) ;
F_96 ( V_38 , V_100 ) ;
V_102 -> V_103 -> V_104 ++ ;
F_33 ( V_102 -> V_12 ) ;
if ( ! V_102 -> V_105 ) {
F_97 ( V_38 -> V_41 , V_106 ) ;
F_98 ( F_30 ( V_38 -> V_41 ) -> V_68 ,
V_107 ) ;
F_99 ( V_38 -> V_96 -> V_97 -> V_98 ,
V_108 ) ;
}
}
void
F_100 ( struct V_34 * V_38 ,
struct V_101 * V_102 )
{
if ( ! F_101 ( V_75 , & ( V_38 ) -> V_76 ) )
return;
F_102 ( V_38 ) ;
V_102 -> V_103 -> V_104 -- ;
}
static void F_103 ( struct V_101 * V_102 ,
struct V_43 * V_43 )
{
V_102 -> V_12 = & V_43 -> V_45 ;
V_102 -> V_103 = & F_32 ( V_43 ) -> V_109 ;
V_102 -> V_110 = F_104 ( V_43 ) ;
V_102 -> V_105 = NULL ;
V_102 -> V_28 = & V_111 ;
}
void F_105 ( struct V_101 * V_102 ,
struct V_43 * V_43 ,
struct V_112 * V_105 )
{
if ( V_105 )
F_106 ( V_102 , V_105 ) ;
else
F_103 ( V_102 , V_43 ) ;
}
void
F_107 ( struct V_34 * V_38 , struct V_113 * V_114 ,
struct V_101 * V_102 )
{
if ( F_108 ( V_38 , V_114 , V_102 ) )
return;
F_95 ( V_38 , & V_102 -> V_103 -> V_115 , V_102 ) ;
}
static void
F_109 ( struct V_37 * V_37 )
{
F_110 ( V_37 , V_106 ) ;
F_111 ( F_30 ( V_37 ) -> V_68 , V_107 ) ;
}
static void
F_112 ( struct V_34 * V_38 )
{
if ( F_65 ( V_75 , & V_38 -> V_76 ) ) {
struct V_43 * V_43 = V_38 -> V_96 -> V_97 -> V_98 ;
struct V_101 V_102 ;
F_103 ( & V_102 , V_43 ) ;
if ( ! F_113 ( V_38 , & V_102 ) ) {
F_31 ( V_102 . V_12 ) ;
F_100 ( V_38 , & V_102 ) ;
F_33 ( V_102 . V_12 ) ;
}
F_109 ( V_38 -> V_41 ) ;
}
}
static inline
int F_114 ( struct V_15 * V_17 )
{
if ( V_17 -> V_14 . V_116 == V_117 )
return V_17 -> V_10 -> V_114 == NULL ;
return V_17 -> V_14 . V_116 != V_118 ;
}
static void F_103 ( struct V_101 * V_102 ,
struct V_43 * V_43 )
{
}
void F_105 ( struct V_101 * V_102 ,
struct V_43 * V_43 ,
struct V_112 * V_105 )
{
}
void
F_107 ( struct V_34 * V_38 , struct V_113 * V_114 ,
struct V_101 * V_102 )
{
}
static void
F_112 ( struct V_34 * V_38 )
{
}
static inline
int F_114 ( struct V_15 * V_17 )
{
return 0 ;
}
static void F_115 ( struct V_8 * V_9 )
{
struct V_101 V_102 ;
unsigned long V_119 = 0 ;
if ( F_65 ( V_120 , & V_9 -> V_33 ) )
goto V_21;
F_103 ( & V_102 , V_9 -> V_43 ) ;
while ( ! F_116 ( & V_9 -> V_5 ) ) {
struct V_34 * V_38 = F_117 ( V_9 -> V_5 . V_121 ) ;
V_119 += V_38 -> V_122 ;
F_102 ( V_38 ) ;
if ( F_65 ( V_123 , & V_9 -> V_33 ) &&
( V_9 -> V_124 < V_119 ) ) {
F_40 ( V_38 -> V_41 ) ;
F_19 ( V_38 -> V_96 , V_9 -> error ) ;
goto V_125;
}
if ( F_65 ( V_126 , & V_9 -> V_33 ) ) {
F_93 ( V_38 ) ;
goto V_121;
}
if ( F_65 ( V_127 , & V_9 -> V_33 ) ) {
memcpy ( & V_38 -> V_128 , & V_9 -> V_14 -> V_129 , sizeof( V_38 -> V_128 ) ) ;
F_107 ( V_38 , V_9 -> V_114 , & V_102 ) ;
goto V_121;
}
V_125:
F_90 ( V_38 ) ;
V_121:
F_118 ( V_38 ) ;
F_53 ( V_38 -> V_41 ) ;
F_60 ( V_38 ) ;
}
V_21:
V_9 -> V_130 ( V_9 ) ;
}
static unsigned long
F_119 ( struct V_101 * V_102 )
{
return V_102 -> V_103 -> V_104 ;
}
int
F_120 ( struct V_99 * V_131 , struct V_99 * V_100 ,
struct V_101 * V_102 , int V_132 )
{
struct V_34 * V_38 , * V_133 ;
int V_65 = 0 ;
F_27 (req, tmp, src, wb_list) {
if ( ! F_58 ( V_38 ) )
continue;
F_28 ( & V_38 -> V_42 ) ;
if ( F_121 ( V_102 -> V_12 ) )
F_122 ( V_38 , V_133 , V_134 ) ;
F_100 ( V_38 , V_102 ) ;
F_96 ( V_38 , V_100 ) ;
V_65 ++ ;
if ( ( V_65 == V_132 ) && ! V_102 -> V_105 )
break;
}
return V_65 ;
}
int
F_123 ( struct V_43 * V_43 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
int V_65 = 0 ;
F_31 ( V_102 -> V_12 ) ;
if ( V_102 -> V_103 -> V_104 > 0 ) {
const int V_132 = V_135 ;
V_65 = F_120 ( & V_102 -> V_103 -> V_115 , V_100 ,
V_102 , V_132 ) ;
V_65 += F_124 ( V_43 , V_102 , V_132 - V_65 ) ;
}
F_33 ( V_102 -> V_12 ) ;
return V_65 ;
}
static unsigned long F_119 ( struct V_101 * V_102 )
{
return 0 ;
}
int F_123 ( struct V_43 * V_43 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
return 0 ;
}
static struct V_34 * F_125 ( struct V_43 * V_43 ,
struct V_37 * V_37 ,
unsigned int V_46 ,
unsigned int V_119 )
{
struct V_34 * V_38 ;
unsigned int V_136 ;
unsigned int V_48 ;
int error ;
if ( ! F_23 ( V_37 ) )
return NULL ;
V_48 = V_46 + V_119 ;
F_31 ( & V_43 -> V_45 ) ;
for (; ; ) {
V_38 = F_22 ( F_32 ( V_43 ) , V_37 ) ;
if ( V_38 == NULL )
goto V_137;
V_136 = V_38 -> V_138 + V_38 -> V_122 ;
if ( V_46 > V_136
|| V_48 < V_38 -> V_138 )
goto V_139;
if ( F_58 ( V_38 ) )
break;
F_33 ( & V_43 -> V_45 ) ;
error = F_59 ( V_38 ) ;
F_60 ( V_38 ) ;
if ( error != 0 )
goto V_90;
F_31 ( & V_43 -> V_45 ) ;
}
if ( V_46 < V_38 -> V_138 ) {
V_38 -> V_138 = V_46 ;
V_38 -> V_140 = V_46 ;
}
if ( V_48 > V_136 )
V_38 -> V_122 = V_48 - V_38 -> V_138 ;
else
V_38 -> V_122 = V_136 - V_38 -> V_138 ;
V_137:
F_33 ( & V_43 -> V_45 ) ;
if ( V_38 )
F_112 ( V_38 ) ;
return V_38 ;
V_139:
F_33 ( & V_43 -> V_45 ) ;
F_60 ( V_38 ) ;
error = F_126 ( V_43 , V_37 ) ;
V_90:
return F_61 ( error ) ;
}
static struct V_34 * F_127 ( struct V_30 * V_31 ,
struct V_37 * V_37 , unsigned int V_46 , unsigned int V_119 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_34 * V_38 ;
V_38 = F_125 ( V_43 , V_37 , V_46 , V_119 ) ;
if ( V_38 != NULL )
goto V_21;
V_38 = F_128 ( V_31 , V_43 , V_37 , V_46 , V_119 ) ;
if ( F_64 ( V_38 ) )
goto V_21;
F_85 ( V_43 , V_38 ) ;
V_21:
return V_38 ;
}
static int F_129 ( struct V_30 * V_31 , struct V_37 * V_37 ,
unsigned int V_46 , unsigned int V_47 )
{
struct V_34 * V_38 ;
V_38 = F_127 ( V_31 , V_37 , V_46 , V_47 ) ;
if ( F_64 ( V_38 ) )
return F_63 ( V_38 ) ;
F_34 ( V_37 , V_46 , V_47 ) ;
F_42 ( V_37 , V_38 -> V_140 , V_38 -> V_122 ) ;
F_93 ( V_38 ) ;
F_130 ( V_38 ) ;
return 0 ;
}
int F_131 ( struct V_141 * V_141 , struct V_37 * V_37 )
{
struct V_30 * V_31 = F_132 ( V_141 ) ;
struct V_142 * V_143 ;
struct V_34 * V_38 ;
int V_144 , V_145 ;
do {
V_38 = F_29 ( V_37 ) ;
if ( V_38 == NULL )
return 0 ;
V_143 = V_38 -> V_146 ;
V_144 = V_38 -> V_41 != V_37 || V_38 -> V_96 != V_31 ;
if ( V_143 ) {
V_144 |= V_143 -> V_147 . V_148 != V_149 -> V_150
|| V_143 -> V_147 . V_151 != V_149 -> V_152 ;
}
F_60 ( V_38 ) ;
if ( ! V_144 )
return 0 ;
V_145 = F_126 ( F_30 ( V_37 ) -> V_44 , V_37 ) ;
} while ( V_145 == 0 );
return V_145 ;
}
static bool F_133 ( struct V_37 * V_37 , struct V_43 * V_43 )
{
if ( F_134 ( V_43 ) )
goto V_21;
if ( F_32 ( V_43 ) -> V_153 & ( V_154 | V_155 ) )
return false ;
V_21:
return F_43 ( V_37 ) != 0 ;
}
static int F_135 ( struct V_141 * V_141 , struct V_37 * V_37 , struct V_43 * V_43 )
{
if ( V_141 -> V_156 & V_157 )
return 0 ;
if ( F_73 ( V_43 ) -> F_86 ( V_43 , V_93 ) )
return 1 ;
if ( F_133 ( V_37 , V_43 ) && ( V_43 -> V_158 == NULL ||
( V_43 -> V_158 -> V_159 == 0 &&
V_43 -> V_158 -> V_160 == V_161 &&
V_43 -> V_158 -> V_162 != V_163 ) ) )
return 1 ;
return 0 ;
}
int F_136 ( struct V_141 * V_141 , struct V_37 * V_37 ,
unsigned int V_46 , unsigned int V_47 )
{
struct V_30 * V_31 = F_132 ( V_141 ) ;
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
int V_145 = 0 ;
F_39 ( V_43 , V_164 ) ;
F_137 ( L_1 ,
V_141 -> V_165 . V_97 -> V_166 -> V_167 . V_168 ,
V_141 -> V_165 . V_97 -> V_167 . V_168 , V_47 ,
( long long ) ( F_37 ( V_37 ) + V_46 ) ) ;
if ( F_135 ( V_141 , V_37 , V_43 ) ) {
V_47 = V_132 ( V_47 + V_46 , F_44 ( V_37 ) ) ;
V_46 = 0 ;
}
V_145 = F_129 ( V_31 , V_37 , V_46 , V_47 ) ;
if ( V_145 < 0 )
F_40 ( V_37 ) ;
else
F_94 ( V_37 ) ;
F_137 ( L_2 ,
V_145 , ( long long ) F_35 ( V_43 ) ) ;
return V_145 ;
}
static int F_138 ( int V_169 )
{
switch ( V_169 & ( V_57 | V_61 ) ) {
case V_57 :
return V_170 ;
case V_61 :
return V_171 ;
}
return V_172 ;
}
int F_139 ( struct V_173 * V_174 ,
struct V_15 * V_17 ,
const struct V_175 * V_176 ,
int V_169 , int V_33 )
{
struct V_43 * V_43 = V_17 -> V_10 -> V_43 ;
int V_177 = F_138 ( V_169 ) ;
struct V_178 * V_179 ;
struct V_180 V_181 = {
. V_182 = & V_17 -> args ,
. V_183 = & V_17 -> V_184 ,
. V_185 = V_17 -> V_10 -> V_186 ,
} ;
struct V_187 V_188 = {
. V_189 = V_174 ,
. V_179 = & V_17 -> V_179 ,
. V_180 = & V_181 ,
. V_190 = V_176 ,
. V_191 = V_17 ,
. V_192 = V_193 ,
. V_33 = V_194 | V_33 ,
. V_177 = V_177 ,
} ;
int V_65 = 0 ;
F_73 ( V_43 ) -> F_140 ( V_17 , & V_181 ) ;
F_137 ( L_3
L_4 ,
V_17 -> V_179 . V_195 ,
V_43 -> V_196 -> V_197 ,
( long long ) F_141 ( V_43 ) ,
V_17 -> args . V_47 ,
( unsigned long long ) V_17 -> args . V_46 ) ;
V_179 = F_142 ( & V_188 ) ;
if ( F_64 ( V_179 ) ) {
V_65 = F_63 ( V_179 ) ;
goto V_21;
}
if ( V_169 & V_198 ) {
V_65 = F_143 ( V_179 ) ;
if ( V_65 == 0 )
V_65 = V_179 -> V_199 ;
}
F_144 ( V_179 ) ;
V_21:
return V_65 ;
}
static void F_145 ( struct V_15 * V_17 ,
unsigned int V_47 , unsigned int V_46 ,
int V_169 , struct V_101 * V_102 )
{
struct V_34 * V_38 = V_17 -> V_10 -> V_38 ;
V_17 -> args . V_200 = F_146 ( V_17 -> V_10 -> V_43 ) ;
V_17 -> args . V_46 = F_147 ( V_38 ) + V_46 ;
V_17 -> V_201 = V_17 -> args . V_46 ;
V_17 -> args . V_202 = V_38 -> V_140 + V_46 ;
V_17 -> args . V_5 = V_17 -> V_5 . V_26 ;
V_17 -> args . V_47 = V_47 ;
V_17 -> args . V_25 = F_148 ( V_38 -> V_96 ) ;
V_17 -> args . V_203 = V_38 -> V_146 ;
V_17 -> args . V_204 = V_205 ;
switch ( V_169 & ( V_58 | V_62 ) ) {
case 0 :
break;
case V_62 :
if ( F_119 ( V_102 ) )
break;
default:
V_17 -> args . V_204 = V_118 ;
}
V_17 -> V_184 . V_206 = & V_17 -> V_206 ;
V_17 -> V_184 . V_47 = V_47 ;
V_17 -> V_184 . V_14 = & V_17 -> V_14 ;
F_149 ( & V_17 -> V_206 ) ;
}
static int F_150 ( struct V_15 * V_17 ,
const struct V_175 * V_176 ,
int V_169 )
{
struct V_43 * V_43 = V_17 -> V_10 -> V_43 ;
return F_139 ( F_151 ( V_43 ) , V_17 , V_176 , V_169 , 0 ) ;
}
static int F_152 ( struct V_99 * V_207 ,
const struct V_175 * V_176 ,
int V_169 )
{
struct V_15 * V_17 ;
int V_65 = 0 ;
while ( ! F_116 ( V_207 ) ) {
int V_208 ;
V_17 = F_153 ( V_207 , struct V_15 , V_115 ) ;
F_154 ( & V_17 -> V_115 ) ;
V_208 = F_150 ( V_17 , V_176 , V_169 ) ;
if ( V_65 == 0 )
V_65 = V_208 ;
}
return V_65 ;
}
static void F_67 ( struct V_34 * V_38 )
{
F_93 ( V_38 ) ;
F_118 ( V_38 ) ;
F_53 ( V_38 -> V_41 ) ;
F_60 ( V_38 ) ;
}
static void F_155 ( struct V_99 * V_207 )
{
struct V_34 * V_38 ;
while ( ! F_116 ( V_207 ) ) {
V_38 = F_117 ( V_207 -> V_121 ) ;
F_102 ( V_38 ) ;
F_67 ( V_38 ) ;
}
}
static void F_156 ( struct V_73 * V_209 ,
struct V_8 * V_9 )
{
F_21 ( V_120 , & V_9 -> V_33 ) ;
while ( ! F_116 ( & V_9 -> V_11 ) ) {
struct V_15 * V_17 = F_153 ( & V_9 -> V_11 ,
struct V_15 , V_115 ) ;
F_157 ( & V_17 -> V_115 ) ;
F_16 ( V_17 ) ;
}
V_209 -> V_210 -> V_211 ( & V_209 -> V_212 ) ;
}
static int F_158 ( struct V_73 * V_209 ,
struct V_8 * V_9 )
{
struct V_34 * V_38 = V_9 -> V_38 ;
struct V_37 * V_37 = V_38 -> V_41 ;
struct V_15 * V_17 ;
T_3 V_213 = V_209 -> V_214 , V_215 ;
unsigned int V_46 ;
int V_216 = 0 ;
struct V_101 V_102 ;
F_105 ( & V_102 , V_209 -> V_217 , V_209 -> V_218 ) ;
if ( ( V_209 -> V_219 & V_62 ) &&
( V_209 -> V_220 || F_119 ( & V_102 ) ||
V_209 -> V_221 > V_213 ) )
V_209 -> V_219 &= ~ V_62 ;
V_46 = 0 ;
V_215 = V_209 -> V_221 ;
do {
T_3 V_222 = F_159 ( V_215 , V_213 ) ;
V_17 = F_9 ( V_9 , 1 ) ;
if ( ! V_17 ) {
F_156 ( V_209 , V_9 ) ;
return - V_223 ;
}
V_17 -> V_5 . V_26 [ 0 ] = V_37 ;
F_145 ( V_17 , V_222 , V_46 , V_209 -> V_219 , & V_102 ) ;
F_160 ( & V_17 -> V_115 , & V_9 -> V_11 ) ;
V_216 ++ ;
V_215 -= V_222 ;
V_46 += V_222 ;
} while ( V_215 != 0 );
F_102 ( V_38 ) ;
F_96 ( V_38 , & V_9 -> V_5 ) ;
V_209 -> V_224 = & V_225 ;
return 0 ;
}
static int F_161 ( struct V_73 * V_209 ,
struct V_8 * V_9 )
{
struct V_34 * V_38 ;
struct V_37 * * V_5 ;
struct V_15 * V_17 ;
struct V_99 * V_207 = & V_209 -> V_212 ;
struct V_101 V_102 ;
V_17 = F_9 ( V_9 , F_162 ( V_209 -> V_226 ,
V_209 -> V_221 ) ) ;
if ( ! V_17 ) {
F_156 ( V_209 , V_9 ) ;
return - V_223 ;
}
F_105 ( & V_102 , V_209 -> V_217 , V_209 -> V_218 ) ;
V_5 = V_17 -> V_5 . V_26 ;
while ( ! F_116 ( V_207 ) ) {
V_38 = F_117 ( V_207 -> V_121 ) ;
F_102 ( V_38 ) ;
F_96 ( V_38 , & V_9 -> V_5 ) ;
* V_5 ++ = V_38 -> V_41 ;
}
if ( ( V_209 -> V_219 & V_62 ) &&
( V_209 -> V_220 || F_119 ( & V_102 ) ) )
V_209 -> V_219 &= ~ V_62 ;
F_145 ( V_17 , V_209 -> V_221 , 0 , V_209 -> V_219 , & V_102 ) ;
F_160 ( & V_17 -> V_115 , & V_9 -> V_11 ) ;
V_209 -> V_224 = & V_225 ;
return 0 ;
}
int F_163 ( struct V_73 * V_209 ,
struct V_8 * V_9 )
{
if ( V_209 -> V_214 < V_227 )
return F_158 ( V_209 , V_9 ) ;
return F_161 ( V_209 , V_9 ) ;
}
static int F_164 ( struct V_73 * V_209 )
{
struct V_6 * V_22 ;
struct V_8 * V_9 ;
int V_65 ;
V_22 = F_6 () ;
if ( ! V_22 ) {
V_209 -> V_210 -> V_211 ( & V_209 -> V_212 ) ;
return - V_223 ;
}
V_9 = & V_22 -> V_10 ;
F_165 ( V_209 , V_9 , F_15 ) ;
F_13 ( & V_9 -> V_13 ) ;
V_65 = F_163 ( V_209 , V_9 ) ;
if ( V_65 == 0 )
V_65 = F_152 ( & V_9 -> V_11 ,
V_209 -> V_224 ,
V_209 -> V_219 ) ;
if ( F_18 ( & V_9 -> V_13 ) )
V_9 -> V_28 -> V_29 ( V_9 ) ;
return V_65 ;
}
void F_166 ( struct V_73 * V_74 ,
struct V_43 * V_43 , int V_228 ,
const struct V_229 * V_230 )
{
F_167 ( V_74 , V_43 , & V_231 , V_230 ,
F_48 ( V_43 ) -> V_213 , V_228 ) ;
}
void F_168 ( struct V_73 * V_74 )
{
V_74 -> V_232 = & V_231 ;
V_74 -> V_214 = F_48 ( V_74 -> V_217 ) -> V_213 ;
}
void F_169 ( struct V_178 * V_179 , void * V_233 )
{
struct V_15 * V_17 = V_233 ;
F_73 ( V_17 -> V_10 -> V_43 ) -> F_170 ( V_179 , V_17 ) ;
if ( F_25 ( F_65 ( V_234 , & V_17 -> args . V_25 -> V_33 ) ) )
F_171 ( V_179 , - V_235 ) ;
}
void F_172 ( struct V_178 * V_179 , void * V_233 )
{
struct V_1 * V_17 = V_233 ;
F_73 ( V_17 -> V_43 ) -> F_173 ( V_179 , V_17 ) ;
}
static void F_174 ( struct V_178 * V_179 , void * V_233 )
{
struct V_15 * V_17 = V_233 ;
F_175 ( V_179 , V_17 ) ;
}
static void F_176 ( void * V_233 )
{
struct V_15 * V_17 = V_233 ;
struct V_8 * V_9 = V_17 -> V_10 ;
int V_145 = V_17 -> V_179 . V_199 ;
if ( ( V_145 >= 0 ) && F_114 ( V_17 ) ) {
F_31 ( & V_9 -> V_12 ) ;
if ( F_65 ( V_126 , & V_9 -> V_33 ) )
;
else if ( ! F_177 ( V_127 , & V_9 -> V_33 ) )
memcpy ( V_9 -> V_14 , & V_17 -> V_14 , sizeof( * V_9 -> V_14 ) ) ;
else if ( memcmp ( V_9 -> V_14 , & V_17 -> V_14 , sizeof( * V_9 -> V_14 ) ) )
F_21 ( V_126 , & V_9 -> V_33 ) ;
F_33 ( & V_9 -> V_12 ) ;
}
F_16 ( V_17 ) ;
}
void F_175 ( struct V_178 * V_179 , struct V_15 * V_17 )
{
struct V_236 * V_237 = & V_17 -> args ;
struct V_238 * V_239 = & V_17 -> V_184 ;
struct V_43 * V_43 = V_17 -> V_10 -> V_43 ;
int V_145 ;
F_137 ( L_5 ,
V_179 -> V_195 , V_179 -> V_199 ) ;
V_145 = F_73 ( V_43 ) -> F_178 ( V_179 , V_17 ) ;
if ( V_145 != 0 )
return;
F_69 ( V_43 , V_240 , V_239 -> V_47 ) ;
#if F_179 ( V_241 ) || F_179 ( V_242 )
if ( V_239 -> V_14 -> V_116 < V_237 -> V_204 && V_179 -> V_199 >= 0 ) {
static unsigned long V_243 ;
if ( F_180 ( V_243 , V_244 ) ) {
F_137 ( L_6
L_7 ,
F_48 ( V_43 ) -> V_245 -> V_246 ,
V_239 -> V_14 -> V_116 , V_237 -> V_204 ) ;
V_243 = V_244 + 300 * V_247 ;
}
}
#endif
if ( V_179 -> V_199 < 0 )
F_181 ( V_17 -> V_10 , V_179 -> V_199 , V_237 -> V_46 ) ;
else if ( V_239 -> V_47 < V_237 -> V_47 ) {
static unsigned long V_243 ;
F_39 ( V_43 , V_248 ) ;
if ( V_239 -> V_47 == 0 ) {
if ( F_180 ( V_243 , V_244 ) ) {
F_182 ( V_249
L_8 ,
V_237 -> V_47 ) ;
V_243 = V_244 + 300 * V_247 ;
}
F_181 ( V_17 -> V_10 , - V_235 , V_237 -> V_46 ) ;
V_179 -> V_199 = - V_235 ;
return;
}
if ( V_239 -> V_14 -> V_116 != V_205 ) {
V_17 -> V_201 += V_239 -> V_47 ;
V_237 -> V_46 += V_239 -> V_47 ;
V_237 -> V_202 += V_239 -> V_47 ;
V_237 -> V_47 -= V_239 -> V_47 ;
} else {
V_237 -> V_204 = V_118 ;
}
F_183 ( V_179 ) ;
}
}
static int F_184 ( struct V_35 * V_36 , int V_250 )
{
int V_65 ;
if ( ! F_177 ( V_251 , & V_36 -> V_33 ) )
return 1 ;
if ( ! V_250 )
return 0 ;
V_65 = F_185 ( & V_36 -> V_33 ,
V_251 ,
V_88 ,
V_89 ) ;
return ( V_65 < 0 ) ? V_65 : 1 ;
}
static void F_186 ( struct V_35 * V_36 )
{
F_92 ( V_251 , & V_36 -> V_33 ) ;
F_83 () ;
F_84 ( & V_36 -> V_33 , V_251 ) ;
}
void F_187 ( struct V_1 * V_17 )
{
F_17 ( V_17 -> V_25 ) ;
F_4 ( V_17 ) ;
}
int F_188 ( struct V_173 * V_174 , struct V_1 * V_17 ,
const struct V_175 * V_176 ,
int V_169 , int V_33 )
{
struct V_178 * V_179 ;
int V_177 = F_138 ( V_169 ) ;
struct V_180 V_181 = {
. V_182 = & V_17 -> args ,
. V_183 = & V_17 -> V_184 ,
. V_185 = V_17 -> V_186 ,
} ;
struct V_187 V_188 = {
. V_179 = & V_17 -> V_179 ,
. V_189 = V_174 ,
. V_180 = & V_181 ,
. V_190 = V_176 ,
. V_191 = V_17 ,
. V_192 = V_193 ,
. V_33 = V_194 | V_33 ,
. V_177 = V_177 ,
} ;
F_73 ( V_17 -> V_43 ) -> F_189 ( V_17 , & V_181 ) ;
F_137 ( L_9 , V_17 -> V_179 . V_195 ) ;
V_179 = F_142 ( & V_188 ) ;
if ( F_64 ( V_179 ) )
return F_63 ( V_179 ) ;
if ( V_169 & V_198 )
F_143 ( V_179 ) ;
F_144 ( V_179 ) ;
return 0 ;
}
void F_190 ( struct V_1 * V_17 ,
struct V_99 * V_207 ,
struct V_113 * V_114 ,
struct V_101 * V_102 )
{
struct V_34 * V_252 = F_117 ( V_207 -> V_121 ) ;
struct V_43 * V_43 = V_252 -> V_96 -> V_97 -> V_98 ;
F_191 ( V_207 , & V_17 -> V_5 ) ;
V_17 -> V_43 = V_43 ;
V_17 -> V_186 = V_252 -> V_96 -> V_186 ;
V_17 -> V_114 = V_114 ;
V_17 -> V_253 = & V_254 ;
V_17 -> V_28 = V_102 -> V_28 ;
V_17 -> V_105 = V_102 -> V_105 ;
V_17 -> args . V_200 = F_146 ( V_17 -> V_43 ) ;
V_17 -> args . V_46 = 0 ;
V_17 -> args . V_47 = 0 ;
V_17 -> V_25 = F_148 ( V_252 -> V_96 ) ;
V_17 -> V_184 . V_206 = & V_17 -> V_206 ;
V_17 -> V_184 . V_14 = & V_17 -> V_14 ;
F_149 ( & V_17 -> V_206 ) ;
}
void F_192 ( struct V_99 * V_255 ,
struct V_113 * V_114 ,
struct V_101 * V_102 )
{
struct V_34 * V_38 ;
while ( ! F_116 ( V_255 ) ) {
V_38 = F_117 ( V_255 -> V_121 ) ;
F_102 ( V_38 ) ;
F_107 ( V_38 , V_114 , V_102 ) ;
if ( ! V_102 -> V_105 ) {
F_110 ( V_38 -> V_41 , V_106 ) ;
F_111 ( F_30 ( V_38 -> V_41 ) -> V_68 ,
V_107 ) ;
}
F_130 ( V_38 ) ;
}
}
static int
F_193 ( struct V_43 * V_43 , struct V_99 * V_207 , int V_169 ,
struct V_101 * V_102 )
{
struct V_1 * V_17 ;
V_17 = F_1 () ;
if ( ! V_17 )
goto V_256;
F_190 ( V_17 , V_207 , NULL , V_102 ) ;
F_13 ( & V_102 -> V_103 -> V_257 ) ;
return F_188 ( F_151 ( V_43 ) , V_17 , V_17 -> V_253 ,
V_169 , 0 ) ;
V_256:
F_192 ( V_207 , NULL , V_102 ) ;
V_102 -> V_28 -> V_211 ( F_32 ( V_43 ) ) ;
return - V_223 ;
}
static void F_194 ( struct V_178 * V_179 , void * V_233 )
{
struct V_1 * V_17 = V_233 ;
F_137 ( L_10 ,
V_179 -> V_195 , V_179 -> V_199 ) ;
F_73 ( V_17 -> V_43 ) -> F_195 ( V_179 , V_17 ) ;
}
static void F_196 ( struct V_1 * V_17 )
{
struct V_34 * V_38 ;
int V_145 = V_17 -> V_179 . V_199 ;
struct V_101 V_102 ;
while ( ! F_116 ( & V_17 -> V_5 ) ) {
V_38 = F_117 ( V_17 -> V_5 . V_121 ) ;
F_102 ( V_38 ) ;
F_109 ( V_38 -> V_41 ) ;
F_137 ( L_11 ,
V_38 -> V_96 -> V_97 -> V_258 -> V_197 ,
( long long ) F_141 ( V_38 -> V_96 -> V_97 -> V_98 ) ,
V_38 -> V_122 ,
( long long ) F_147 ( V_38 ) ) ;
if ( V_145 < 0 ) {
F_19 ( V_38 -> V_96 , V_145 ) ;
F_90 ( V_38 ) ;
F_137 ( L_12 , V_145 ) ;
goto V_121;
}
if ( ! memcmp ( & V_38 -> V_128 , & V_17 -> V_14 . V_129 , sizeof( V_38 -> V_128 ) ) ) {
F_90 ( V_38 ) ;
F_137 ( L_13 ) ;
goto V_121;
}
F_137 ( L_14 ) ;
F_93 ( V_38 ) ;
F_21 ( V_259 , & V_38 -> V_96 -> V_33 ) ;
V_121:
F_130 ( V_38 ) ;
}
F_105 ( & V_102 , V_17 -> V_43 , V_17 -> V_105 ) ;
if ( F_18 ( & V_102 . V_103 -> V_257 ) )
F_186 ( F_32 ( V_17 -> V_43 ) ) ;
}
static void F_197 ( void * V_233 )
{
struct V_1 * V_17 = V_233 ;
V_17 -> V_28 -> V_29 ( V_17 ) ;
F_187 ( V_233 ) ;
}
int F_198 ( struct V_43 * V_43 , struct V_99 * V_207 ,
int V_169 , struct V_101 * V_102 )
{
int V_145 ;
V_145 = F_199 ( V_43 , V_207 , V_169 , V_102 ) ;
if ( V_145 == V_260 )
V_145 = F_193 ( V_43 , V_207 , V_169 , V_102 ) ;
return V_145 ;
}
int F_200 ( struct V_43 * V_43 , int V_169 )
{
F_201 ( V_207 ) ;
struct V_101 V_102 ;
int V_250 = V_169 & V_198 ;
int V_184 ;
V_184 = F_184 ( F_32 ( V_43 ) , V_250 ) ;
if ( V_184 <= 0 )
goto V_261;
F_103 ( & V_102 , V_43 ) ;
V_184 = F_123 ( V_43 , & V_207 , & V_102 ) ;
if ( V_184 ) {
int error ;
error = F_198 ( V_43 , & V_207 , V_169 , & V_102 ) ;
if ( error < 0 )
return error ;
if ( ! V_250 )
goto V_261;
error = F_202 ( & F_32 ( V_43 ) -> V_33 ,
V_251 ,
V_88 ,
V_89 ) ;
if ( error < 0 )
return error ;
} else
F_186 ( F_32 ( V_43 ) ) ;
return V_184 ;
V_261:
F_99 ( V_43 , V_108 ) ;
return V_184 ;
}
static int F_203 ( struct V_43 * V_43 , struct V_54 * V_55 )
{
struct V_35 * V_36 = F_32 ( V_43 ) ;
int V_33 = V_198 ;
int V_65 = 0 ;
if ( ! V_36 -> V_109 . V_104 )
return V_65 ;
if ( V_55 -> V_80 == V_81 ) {
if ( V_36 -> V_109 . V_104 <= ( V_36 -> V_92 >> 1 ) )
goto V_261;
V_33 = 0 ;
}
V_65 = F_200 ( V_43 , V_33 ) ;
if ( V_65 >= 0 ) {
if ( V_55 -> V_80 == V_81 ) {
if ( V_65 < V_55 -> V_262 )
V_55 -> V_262 -= V_65 ;
else
V_55 -> V_262 = 0 ;
}
return 0 ;
}
V_261:
F_99 ( V_43 , V_108 ) ;
return V_65 ;
}
static int F_203 ( struct V_43 * V_43 , struct V_54 * V_55 )
{
return 0 ;
}
int F_204 ( struct V_43 * V_43 , struct V_54 * V_55 )
{
return F_203 ( V_43 , V_55 ) ;
}
int F_205 ( struct V_43 * V_43 )
{
struct V_54 V_55 = {
. V_80 = V_263 ,
. V_262 = V_264 ,
. V_265 = 0 ,
. V_266 = V_267 ,
} ;
return F_206 ( V_43 , & V_55 ) ;
}
int F_207 ( struct V_43 * V_43 , struct V_37 * V_37 )
{
struct V_34 * V_38 ;
int V_65 = 0 ;
for (; ; ) {
F_208 ( V_37 ) ;
V_38 = F_29 ( V_37 ) ;
if ( V_38 == NULL )
break;
if ( F_58 ( V_38 ) ) {
F_112 ( V_38 ) ;
F_90 ( V_38 ) ;
F_209 ( V_37 , V_227 ) ;
F_130 ( V_38 ) ;
break;
}
V_65 = F_59 ( V_38 ) ;
F_60 ( V_38 ) ;
if ( V_65 < 0 )
break;
}
return V_65 ;
}
int F_126 ( struct V_43 * V_43 , struct V_37 * V_37 )
{
T_1 V_265 = F_37 ( V_37 ) ;
T_1 V_266 = V_265 + ( T_1 ) ( V_227 - 1 ) ;
struct V_54 V_55 = {
. V_80 = V_263 ,
. V_262 = 0 ,
. V_265 = V_265 ,
. V_266 = V_266 ,
} ;
int V_65 ;
for (; ; ) {
F_208 ( V_37 ) ;
if ( F_210 ( V_37 ) ) {
V_65 = F_72 ( V_37 , & V_55 ) ;
if ( V_65 < 0 )
goto V_268;
continue;
}
if ( ! F_23 ( V_37 ) )
break;
V_65 = F_200 ( V_43 , V_198 ) ;
if ( V_65 < 0 )
goto V_268;
}
return 0 ;
V_268:
return V_65 ;
}
int F_211 ( struct V_85 * V_83 , struct V_37 * V_269 ,
struct V_37 * V_37 , enum V_270 V_271 )
{
if ( F_23 ( V_37 ) )
return - V_272 ;
if ( ! F_212 ( V_37 , V_20 ) )
return - V_272 ;
return F_213 ( V_83 , V_269 , V_37 , V_271 ) ;
}
int T_4 F_214 ( void )
{
V_273 = F_215 ( L_15 ,
sizeof( struct V_6 ) ,
0 , V_274 ,
NULL ) ;
if ( V_273 == NULL )
return - V_223 ;
V_7 = F_216 ( V_275 ,
V_273 ) ;
if ( V_7 == NULL )
goto V_276;
V_277 = F_215 ( L_16 ,
sizeof( struct V_1 ) ,
0 , V_274 ,
NULL ) ;
if ( V_277 == NULL )
goto V_278;
V_3 = F_216 ( V_279 ,
V_277 ) ;
if ( V_3 == NULL )
goto V_280;
V_281 = ( 16 * F_217 ( V_282 ) ) << ( V_283 - 10 ) ;
if ( V_281 > 256 * 1024 )
V_281 = 256 * 1024 ;
return 0 ;
V_280:
F_218 ( V_277 ) ;
V_278:
F_219 ( V_7 ) ;
V_276:
F_218 ( V_273 ) ;
return - V_223 ;
}
void F_220 ( void )
{
F_219 ( V_3 ) ;
F_218 ( V_277 ) ;
F_219 ( V_7 ) ;
F_218 ( V_273 ) ;
}
