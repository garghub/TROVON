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
F_41 ( V_37 ) ;
F_42 ( F_30 ( V_37 ) -> V_44 , F_30 ( V_37 ) ) ;
}
static void F_43 ( struct V_37 * V_37 , unsigned int V_53 , unsigned int V_47 )
{
if ( F_44 ( V_37 ) )
return;
if ( V_53 != 0 )
return;
if ( V_47 != F_45 ( V_37 ) )
return;
F_46 ( V_37 ) ;
}
static int F_47 ( struct V_54 * V_55 )
{
if ( V_55 -> V_56 )
return V_57 | V_58 ;
if ( V_55 -> V_59 || V_55 -> V_60 )
return V_61 | V_62 ;
return V_62 ;
}
static int F_48 ( struct V_37 * V_37 )
{
int V_63 = F_49 ( V_37 ) ;
if ( ! V_63 ) {
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_64 * V_65 = F_50 ( V_43 ) ;
if ( F_51 ( & V_65 -> V_66 ) >
V_67 ) {
F_52 ( & V_65 -> V_68 ,
V_69 ) ;
}
}
return V_63 ;
}
static void F_53 ( struct V_37 * V_37 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_64 * V_65 = F_50 ( V_43 ) ;
F_54 ( V_37 ) ;
if ( F_55 ( & V_65 -> V_66 ) < V_70 )
F_56 ( & V_65 -> V_68 , V_69 ) ;
}
static struct V_34 * F_57 ( struct V_37 * V_37 , bool V_71 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_34 * V_38 ;
int V_63 ;
F_31 ( & V_43 -> V_45 ) ;
for (; ; ) {
V_38 = F_22 ( F_32 ( V_43 ) , V_37 ) ;
if ( V_38 == NULL )
break;
if ( F_58 ( V_38 ) )
break;
F_33 ( & V_43 -> V_45 ) ;
if ( ! V_71 )
V_63 = F_59 ( V_38 ) ;
else
V_63 = - V_72 ;
F_60 ( V_38 ) ;
if ( V_63 != 0 )
return F_61 ( V_63 ) ;
F_31 ( & V_43 -> V_45 ) ;
}
F_33 ( & V_43 -> V_45 ) ;
return V_38 ;
}
static int F_62 ( struct V_73 * V_74 ,
struct V_37 * V_37 , bool V_71 )
{
struct V_34 * V_38 ;
int V_63 = 0 ;
V_38 = F_57 ( V_37 , V_71 ) ;
if ( ! V_38 )
goto V_21;
V_63 = F_63 ( V_38 ) ;
if ( F_64 ( V_38 ) )
goto V_21;
V_63 = F_48 ( V_37 ) ;
F_65 ( V_63 != 0 ) ;
F_65 ( F_66 ( V_75 , & V_38 -> V_76 ) ) ;
if ( ! F_67 ( V_74 , V_38 ) ) {
F_68 ( V_38 ) ;
V_63 = V_74 -> V_77 ;
}
V_21:
return V_63 ;
}
static int F_69 ( struct V_37 * V_37 , struct V_54 * V_55 , struct V_73 * V_74 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
int V_63 ;
F_39 ( V_43 , V_78 ) ;
F_70 ( V_43 , V_79 , 1 ) ;
F_71 ( V_74 , F_36 ( V_37 ) ) ;
V_63 = F_62 ( V_74 , V_37 , V_55 -> V_80 == V_81 ) ;
if ( V_63 == - V_72 ) {
F_72 ( V_55 , V_37 ) ;
V_63 = 0 ;
}
return V_63 ;
}
static int F_73 ( struct V_37 * V_37 , struct V_54 * V_55 )
{
struct V_73 V_74 ;
int V_82 ;
F_74 ( F_30 ( V_37 ) -> V_44 ) -> F_75 ( & V_74 ,
V_37 -> V_83 -> V_44 ,
F_47 ( V_55 ) ,
& V_84 ) ;
V_82 = F_69 ( V_37 , V_55 , & V_74 ) ;
F_76 ( & V_74 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_74 . V_77 < 0 )
return V_74 . V_77 ;
return 0 ;
}
int F_77 ( struct V_37 * V_37 , struct V_54 * V_55 )
{
int V_63 ;
V_63 = F_73 ( V_37 , V_55 ) ;
F_78 ( V_37 ) ;
return V_63 ;
}
static int F_79 ( struct V_37 * V_37 , struct V_54 * V_55 , void * V_17 )
{
int V_63 ;
V_63 = F_69 ( V_37 , V_55 , V_17 ) ;
F_78 ( V_37 ) ;
return V_63 ;
}
int F_80 ( struct V_85 * V_83 , struct V_54 * V_55 )
{
struct V_43 * V_43 = V_83 -> V_44 ;
unsigned long * V_86 = & F_32 ( V_43 ) -> V_33 ;
struct V_73 V_74 ;
int V_82 ;
V_82 = F_81 ( V_86 , V_87 ,
V_88 , V_89 ) ;
if ( V_82 )
goto V_90;
F_39 ( V_43 , V_91 ) ;
F_74 ( V_43 ) -> F_75 ( & V_74 , V_43 , F_47 ( V_55 ) , & V_84 ) ;
V_82 = F_82 ( V_83 , V_55 , F_79 , & V_74 ) ;
F_76 ( & V_74 ) ;
F_83 ( V_87 , V_86 ) ;
F_84 () ;
F_85 ( V_86 , V_87 ) ;
if ( V_82 < 0 )
goto V_90;
V_82 = V_74 . V_77 ;
if ( V_82 < 0 )
goto V_90;
return 0 ;
V_90:
return V_82 ;
}
static void F_86 ( struct V_43 * V_43 , struct V_34 * V_38 )
{
struct V_35 * V_36 = F_32 ( V_43 ) ;
F_58 ( V_38 ) ;
F_31 ( & V_43 -> V_45 ) ;
if ( ! V_36 -> V_92 && F_74 ( V_43 ) -> F_87 ( V_43 , V_93 ) )
V_43 -> V_94 ++ ;
if ( F_88 ( ! F_26 ( V_38 -> V_41 ) ) ) {
F_21 ( V_95 , & V_38 -> V_76 ) ;
F_89 ( V_38 -> V_41 ) ;
F_90 ( V_38 -> V_41 , ( unsigned long ) V_38 ) ;
}
V_36 -> V_92 ++ ;
F_28 ( & V_38 -> V_42 ) ;
F_33 ( & V_43 -> V_45 ) ;
}
static void F_91 ( struct V_34 * V_38 )
{
struct V_43 * V_43 = V_38 -> V_96 -> V_97 -> V_98 ;
struct V_35 * V_36 = F_32 ( V_43 ) ;
F_65 ( ! F_92 ( V_38 ) ) ;
F_31 ( & V_43 -> V_45 ) ;
if ( F_88 ( ! F_26 ( V_38 -> V_41 ) ) ) {
F_90 ( V_38 -> V_41 , 0 ) ;
F_93 ( V_38 -> V_41 ) ;
F_94 ( V_95 , & V_38 -> V_76 ) ;
}
V_36 -> V_92 -- ;
F_33 ( & V_43 -> V_45 ) ;
F_60 ( V_38 ) ;
}
static void
F_95 ( struct V_34 * V_38 )
{
F_96 ( V_38 -> V_41 ) ;
}
void
F_97 ( struct V_34 * V_38 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
F_21 ( V_75 , & ( V_38 ) -> V_76 ) ;
F_31 ( V_102 -> V_12 ) ;
F_98 ( V_38 , V_100 ) ;
V_102 -> V_103 -> V_104 ++ ;
F_33 ( V_102 -> V_12 ) ;
if ( ! V_102 -> V_105 ) {
F_99 ( V_38 -> V_41 , V_106 ) ;
F_100 ( F_30 ( V_38 -> V_41 ) -> V_68 ,
V_107 ) ;
F_101 ( V_38 -> V_96 -> V_97 -> V_98 ,
V_108 ) ;
}
}
void
F_102 ( struct V_34 * V_38 ,
struct V_101 * V_102 )
{
if ( ! F_103 ( V_75 , & ( V_38 ) -> V_76 ) )
return;
F_104 ( V_38 ) ;
V_102 -> V_103 -> V_104 -- ;
}
static void F_105 ( struct V_101 * V_102 ,
struct V_43 * V_43 )
{
V_102 -> V_12 = & V_43 -> V_45 ;
V_102 -> V_103 = & F_32 ( V_43 ) -> V_109 ;
V_102 -> V_110 = F_106 ( V_43 ) ;
V_102 -> V_105 = NULL ;
V_102 -> V_28 = & V_111 ;
}
void F_107 ( struct V_101 * V_102 ,
struct V_43 * V_43 ,
struct V_112 * V_105 )
{
if ( V_105 )
F_108 ( V_102 , V_105 ) ;
else
F_105 ( V_102 , V_43 ) ;
}
void
F_109 ( struct V_34 * V_38 , struct V_113 * V_114 ,
struct V_101 * V_102 )
{
if ( F_110 ( V_38 , V_114 , V_102 ) )
return;
F_97 ( V_38 , & V_102 -> V_103 -> V_115 , V_102 ) ;
}
static void
F_111 ( struct V_37 * V_37 )
{
F_112 ( V_37 , V_106 ) ;
F_113 ( F_30 ( V_37 ) -> V_68 , V_107 ) ;
}
static void
F_114 ( struct V_34 * V_38 )
{
if ( F_66 ( V_75 , & V_38 -> V_76 ) ) {
struct V_43 * V_43 = V_38 -> V_96 -> V_97 -> V_98 ;
struct V_101 V_102 ;
F_105 ( & V_102 , V_43 ) ;
if ( ! F_115 ( V_38 , & V_102 ) ) {
F_31 ( V_102 . V_12 ) ;
F_102 ( V_38 , & V_102 ) ;
F_33 ( V_102 . V_12 ) ;
}
F_111 ( V_38 -> V_41 ) ;
}
}
static inline
int F_116 ( struct V_15 * V_17 )
{
if ( V_17 -> V_14 . V_116 == V_117 )
return V_17 -> V_10 -> V_114 == NULL ;
return V_17 -> V_14 . V_116 != V_118 ;
}
static void F_105 ( struct V_101 * V_102 ,
struct V_43 * V_43 )
{
}
void F_107 ( struct V_101 * V_102 ,
struct V_43 * V_43 ,
struct V_112 * V_105 )
{
}
void
F_109 ( struct V_34 * V_38 , struct V_113 * V_114 ,
struct V_101 * V_102 )
{
}
static void
F_114 ( struct V_34 * V_38 )
{
}
static inline
int F_116 ( struct V_15 * V_17 )
{
return 0 ;
}
static void F_117 ( struct V_8 * V_9 )
{
struct V_101 V_102 ;
unsigned long V_119 = 0 ;
if ( F_66 ( V_120 , & V_9 -> V_33 ) )
goto V_21;
F_105 ( & V_102 , V_9 -> V_43 ) ;
while ( ! F_118 ( & V_9 -> V_5 ) ) {
struct V_34 * V_38 = F_119 ( V_9 -> V_5 . V_121 ) ;
V_119 += V_38 -> V_122 ;
F_104 ( V_38 ) ;
if ( F_66 ( V_123 , & V_9 -> V_33 ) &&
( V_9 -> V_124 < V_119 ) ) {
F_40 ( V_38 -> V_41 ) ;
F_19 ( V_38 -> V_96 , V_9 -> error ) ;
goto V_125;
}
if ( F_66 ( V_126 , & V_9 -> V_33 ) ) {
F_95 ( V_38 ) ;
goto V_121;
}
if ( F_66 ( V_127 , & V_9 -> V_33 ) ) {
memcpy ( & V_38 -> V_128 , & V_9 -> V_14 -> V_129 , sizeof( V_38 -> V_128 ) ) ;
F_109 ( V_38 , V_9 -> V_114 , & V_102 ) ;
goto V_121;
}
V_125:
F_91 ( V_38 ) ;
V_121:
F_120 ( V_38 ) ;
F_53 ( V_38 -> V_41 ) ;
F_60 ( V_38 ) ;
}
V_21:
V_9 -> V_130 ( V_9 ) ;
}
static unsigned long
F_121 ( struct V_101 * V_102 )
{
return V_102 -> V_103 -> V_104 ;
}
int
F_122 ( struct V_99 * V_131 , struct V_99 * V_100 ,
struct V_101 * V_102 , int V_132 )
{
struct V_34 * V_38 , * V_133 ;
int V_63 = 0 ;
F_27 (req, tmp, src, wb_list) {
if ( ! F_58 ( V_38 ) )
continue;
F_28 ( & V_38 -> V_42 ) ;
if ( F_123 ( V_102 -> V_12 ) )
F_124 ( V_38 , V_133 , V_134 ) ;
F_102 ( V_38 , V_102 ) ;
F_98 ( V_38 , V_100 ) ;
V_63 ++ ;
if ( ( V_63 == V_132 ) && ! V_102 -> V_105 )
break;
}
return V_63 ;
}
int
F_125 ( struct V_43 * V_43 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
int V_63 = 0 ;
F_31 ( V_102 -> V_12 ) ;
if ( V_102 -> V_103 -> V_104 > 0 ) {
const int V_132 = V_135 ;
V_63 = F_122 ( & V_102 -> V_103 -> V_115 , V_100 ,
V_102 , V_132 ) ;
V_63 += F_126 ( V_43 , V_102 , V_132 - V_63 ) ;
}
F_33 ( V_102 -> V_12 ) ;
return V_63 ;
}
static unsigned long F_121 ( struct V_101 * V_102 )
{
return 0 ;
}
int F_125 ( struct V_43 * V_43 , struct V_99 * V_100 ,
struct V_101 * V_102 )
{
return 0 ;
}
static struct V_34 * F_127 ( struct V_43 * V_43 ,
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
F_114 ( V_38 ) ;
return V_38 ;
V_139:
F_33 ( & V_43 -> V_45 ) ;
F_60 ( V_38 ) ;
error = F_128 ( V_43 , V_37 ) ;
V_90:
return F_61 ( error ) ;
}
static struct V_34 * F_129 ( struct V_30 * V_31 ,
struct V_37 * V_37 , unsigned int V_46 , unsigned int V_119 )
{
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
struct V_34 * V_38 ;
V_38 = F_127 ( V_43 , V_37 , V_46 , V_119 ) ;
if ( V_38 != NULL )
goto V_21;
V_38 = F_130 ( V_31 , V_43 , V_37 , V_46 , V_119 ) ;
if ( F_64 ( V_38 ) )
goto V_21;
F_86 ( V_43 , V_38 ) ;
V_21:
return V_38 ;
}
static int F_131 ( struct V_30 * V_31 , struct V_37 * V_37 ,
unsigned int V_46 , unsigned int V_47 )
{
struct V_34 * V_38 ;
V_38 = F_129 ( V_31 , V_37 , V_46 , V_47 ) ;
if ( F_64 ( V_38 ) )
return F_63 ( V_38 ) ;
F_34 ( V_37 , V_46 , V_47 ) ;
F_43 ( V_37 , V_38 -> V_140 , V_38 -> V_122 ) ;
F_95 ( V_38 ) ;
F_132 ( V_38 ) ;
return 0 ;
}
int F_133 ( struct V_141 * V_141 , struct V_37 * V_37 )
{
struct V_30 * V_31 = F_134 ( V_141 ) ;
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
V_145 = F_128 ( F_30 ( V_37 ) -> V_44 , V_37 ) ;
} while ( V_145 == 0 );
return V_145 ;
}
static bool F_135 ( struct V_37 * V_37 , struct V_43 * V_43 )
{
if ( F_136 ( V_43 ) )
goto V_21;
if ( F_32 ( V_43 ) -> V_153 & V_154 )
return false ;
V_21:
return F_44 ( V_37 ) != 0 ;
}
int F_137 ( struct V_141 * V_141 , struct V_37 * V_37 ,
unsigned int V_46 , unsigned int V_47 )
{
struct V_30 * V_31 = F_134 ( V_141 ) ;
struct V_43 * V_43 = F_30 ( V_37 ) -> V_44 ;
int V_145 = 0 ;
F_39 ( V_43 , V_155 ) ;
F_138 ( L_1 ,
V_141 -> V_156 . V_97 -> V_157 -> V_158 . V_159 ,
V_141 -> V_156 . V_97 -> V_158 . V_159 , V_47 ,
( long long ) ( F_37 ( V_37 ) + V_46 ) ) ;
if ( F_135 ( V_37 , V_43 ) &&
V_43 -> V_160 == NULL &&
! ( V_141 -> V_161 & V_162 ) ) {
V_47 = V_132 ( V_47 + V_46 , F_45 ( V_37 ) ) ;
V_46 = 0 ;
}
V_145 = F_131 ( V_31 , V_37 , V_46 , V_47 ) ;
if ( V_145 < 0 )
F_40 ( V_37 ) ;
else
F_96 ( V_37 ) ;
F_138 ( L_2 ,
V_145 , ( long long ) F_35 ( V_43 ) ) ;
return V_145 ;
}
static int F_139 ( int V_163 )
{
switch ( V_163 & ( V_57 | V_61 ) ) {
case V_57 :
return V_164 ;
case V_61 :
return V_165 ;
}
return V_166 ;
}
int F_140 ( struct V_167 * V_168 ,
struct V_15 * V_17 ,
const struct V_169 * V_170 ,
int V_163 , int V_33 )
{
struct V_43 * V_43 = V_17 -> V_10 -> V_43 ;
int V_171 = F_139 ( V_163 ) ;
struct V_172 * V_173 ;
struct V_174 V_175 = {
. V_176 = & V_17 -> args ,
. V_177 = & V_17 -> V_178 ,
. V_179 = V_17 -> V_10 -> V_180 ,
} ;
struct V_181 V_182 = {
. V_183 = V_168 ,
. V_173 = & V_17 -> V_173 ,
. V_174 = & V_175 ,
. V_184 = V_170 ,
. V_185 = V_17 ,
. V_186 = V_187 ,
. V_33 = V_188 | V_33 ,
. V_171 = V_171 ,
} ;
int V_63 = 0 ;
F_74 ( V_43 ) -> F_141 ( V_17 , & V_175 ) ;
F_138 ( L_3
L_4 ,
V_17 -> V_173 . V_189 ,
V_43 -> V_190 -> V_191 ,
( long long ) F_142 ( V_43 ) ,
V_17 -> args . V_47 ,
( unsigned long long ) V_17 -> args . V_46 ) ;
V_173 = F_143 ( & V_182 ) ;
if ( F_64 ( V_173 ) ) {
V_63 = F_63 ( V_173 ) ;
goto V_21;
}
if ( V_163 & V_192 ) {
V_63 = F_144 ( V_173 ) ;
if ( V_63 == 0 )
V_63 = V_173 -> V_193 ;
}
F_145 ( V_173 ) ;
V_21:
return V_63 ;
}
static void F_146 ( struct V_15 * V_17 ,
unsigned int V_47 , unsigned int V_46 ,
int V_163 , struct V_101 * V_102 )
{
struct V_34 * V_38 = V_17 -> V_10 -> V_38 ;
V_17 -> args . V_194 = F_147 ( V_17 -> V_10 -> V_43 ) ;
V_17 -> args . V_46 = F_148 ( V_38 ) + V_46 ;
V_17 -> V_195 = V_17 -> args . V_46 ;
V_17 -> args . V_196 = V_38 -> V_140 + V_46 ;
V_17 -> args . V_5 = V_17 -> V_5 . V_26 ;
V_17 -> args . V_47 = V_47 ;
V_17 -> args . V_25 = F_149 ( V_38 -> V_96 ) ;
V_17 -> args . V_197 = V_38 -> V_146 ;
V_17 -> args . V_198 = V_199 ;
switch ( V_163 & ( V_58 | V_62 ) ) {
case 0 :
break;
case V_62 :
if ( F_121 ( V_102 ) )
break;
default:
V_17 -> args . V_198 = V_118 ;
}
V_17 -> V_178 . V_200 = & V_17 -> V_200 ;
V_17 -> V_178 . V_47 = V_47 ;
V_17 -> V_178 . V_14 = & V_17 -> V_14 ;
F_150 ( & V_17 -> V_200 ) ;
}
static int F_151 ( struct V_15 * V_17 ,
const struct V_169 * V_170 ,
int V_163 )
{
struct V_43 * V_43 = V_17 -> V_10 -> V_43 ;
return F_140 ( F_152 ( V_43 ) , V_17 , V_170 , V_163 , 0 ) ;
}
static int F_153 ( struct V_99 * V_201 ,
const struct V_169 * V_170 ,
int V_163 )
{
struct V_15 * V_17 ;
int V_63 = 0 ;
while ( ! F_118 ( V_201 ) ) {
int V_202 ;
V_17 = F_154 ( V_201 , struct V_15 , V_115 ) ;
F_155 ( & V_17 -> V_115 ) ;
V_202 = F_151 ( V_17 , V_170 , V_163 ) ;
if ( V_63 == 0 )
V_63 = V_202 ;
}
return V_63 ;
}
static void F_68 ( struct V_34 * V_38 )
{
F_95 ( V_38 ) ;
F_120 ( V_38 ) ;
F_53 ( V_38 -> V_41 ) ;
F_60 ( V_38 ) ;
}
static void F_156 ( struct V_99 * V_201 )
{
struct V_34 * V_38 ;
while ( ! F_118 ( V_201 ) ) {
V_38 = F_119 ( V_201 -> V_121 ) ;
F_104 ( V_38 ) ;
F_68 ( V_38 ) ;
}
}
static void F_157 ( struct V_73 * V_203 ,
struct V_8 * V_9 )
{
F_21 ( V_120 , & V_9 -> V_33 ) ;
while ( ! F_118 ( & V_9 -> V_11 ) ) {
struct V_15 * V_17 = F_154 ( & V_9 -> V_11 ,
struct V_15 , V_115 ) ;
F_158 ( & V_17 -> V_115 ) ;
F_16 ( V_17 ) ;
}
V_203 -> V_204 -> V_205 ( & V_203 -> V_206 ) ;
}
static int F_159 ( struct V_73 * V_203 ,
struct V_8 * V_9 )
{
struct V_34 * V_38 = V_9 -> V_38 ;
struct V_37 * V_37 = V_38 -> V_41 ;
struct V_15 * V_17 ;
T_3 V_207 = V_203 -> V_208 , V_209 ;
unsigned int V_46 ;
int V_210 = 0 ;
struct V_101 V_102 ;
F_107 ( & V_102 , V_203 -> V_211 , V_203 -> V_212 ) ;
if ( ( V_203 -> V_213 & V_62 ) &&
( V_203 -> V_214 || F_121 ( & V_102 ) ||
V_203 -> V_215 > V_207 ) )
V_203 -> V_213 &= ~ V_62 ;
V_46 = 0 ;
V_209 = V_203 -> V_215 ;
do {
T_3 V_216 = F_160 ( V_209 , V_207 ) ;
V_17 = F_9 ( V_9 , 1 ) ;
if ( ! V_17 ) {
F_157 ( V_203 , V_9 ) ;
return - V_217 ;
}
V_17 -> V_5 . V_26 [ 0 ] = V_37 ;
F_146 ( V_17 , V_216 , V_46 , V_203 -> V_213 , & V_102 ) ;
F_161 ( & V_17 -> V_115 , & V_9 -> V_11 ) ;
V_210 ++ ;
V_209 -= V_216 ;
V_46 += V_216 ;
} while ( V_209 != 0 );
F_104 ( V_38 ) ;
F_98 ( V_38 , & V_9 -> V_5 ) ;
V_203 -> V_218 = & V_219 ;
return 0 ;
}
static int F_162 ( struct V_73 * V_203 ,
struct V_8 * V_9 )
{
struct V_34 * V_38 ;
struct V_37 * * V_5 ;
struct V_15 * V_17 ;
struct V_99 * V_201 = & V_203 -> V_206 ;
struct V_101 V_102 ;
V_17 = F_9 ( V_9 , F_163 ( V_203 -> V_220 ,
V_203 -> V_215 ) ) ;
if ( ! V_17 ) {
F_157 ( V_203 , V_9 ) ;
return - V_217 ;
}
F_107 ( & V_102 , V_203 -> V_211 , V_203 -> V_212 ) ;
V_5 = V_17 -> V_5 . V_26 ;
while ( ! F_118 ( V_201 ) ) {
V_38 = F_119 ( V_201 -> V_121 ) ;
F_104 ( V_38 ) ;
F_98 ( V_38 , & V_9 -> V_5 ) ;
* V_5 ++ = V_38 -> V_41 ;
}
if ( ( V_203 -> V_213 & V_62 ) &&
( V_203 -> V_214 || F_121 ( & V_102 ) ) )
V_203 -> V_213 &= ~ V_62 ;
F_146 ( V_17 , V_203 -> V_215 , 0 , V_203 -> V_213 , & V_102 ) ;
F_161 ( & V_17 -> V_115 , & V_9 -> V_11 ) ;
V_203 -> V_218 = & V_219 ;
return 0 ;
}
int F_164 ( struct V_73 * V_203 ,
struct V_8 * V_9 )
{
if ( V_203 -> V_208 < V_221 )
return F_159 ( V_203 , V_9 ) ;
return F_162 ( V_203 , V_9 ) ;
}
static int F_165 ( struct V_73 * V_203 )
{
struct V_6 * V_22 ;
struct V_8 * V_9 ;
int V_63 ;
V_22 = F_6 () ;
if ( ! V_22 ) {
V_203 -> V_204 -> V_205 ( & V_203 -> V_206 ) ;
return - V_217 ;
}
V_9 = & V_22 -> V_10 ;
F_166 ( V_203 , V_9 , F_15 ) ;
F_13 ( & V_9 -> V_13 ) ;
V_63 = F_164 ( V_203 , V_9 ) ;
if ( V_63 == 0 )
V_63 = F_153 ( & V_9 -> V_11 ,
V_203 -> V_218 ,
V_203 -> V_213 ) ;
if ( F_18 ( & V_9 -> V_13 ) )
V_9 -> V_28 -> V_29 ( V_9 ) ;
return V_63 ;
}
void F_167 ( struct V_73 * V_74 ,
struct V_43 * V_43 , int V_222 ,
const struct V_223 * V_224 )
{
F_168 ( V_74 , V_43 , & V_225 , V_224 ,
F_50 ( V_43 ) -> V_207 , V_222 ) ;
}
void F_169 ( struct V_73 * V_74 )
{
V_74 -> V_226 = & V_225 ;
V_74 -> V_208 = F_50 ( V_74 -> V_211 ) -> V_207 ;
}
void F_170 ( struct V_172 * V_173 , void * V_227 )
{
struct V_15 * V_17 = V_227 ;
F_74 ( V_17 -> V_10 -> V_43 ) -> F_171 ( V_173 , V_17 ) ;
}
void F_172 ( struct V_172 * V_173 , void * V_227 )
{
struct V_1 * V_17 = V_227 ;
F_74 ( V_17 -> V_43 ) -> F_173 ( V_173 , V_17 ) ;
}
static void F_174 ( struct V_172 * V_173 , void * V_227 )
{
struct V_15 * V_17 = V_227 ;
F_175 ( V_173 , V_17 ) ;
}
static void F_176 ( void * V_227 )
{
struct V_15 * V_17 = V_227 ;
struct V_8 * V_9 = V_17 -> V_10 ;
int V_145 = V_17 -> V_173 . V_193 ;
if ( ( V_145 >= 0 ) && F_116 ( V_17 ) ) {
F_31 ( & V_9 -> V_12 ) ;
if ( F_66 ( V_126 , & V_9 -> V_33 ) )
;
else if ( ! F_177 ( V_127 , & V_9 -> V_33 ) )
memcpy ( V_9 -> V_14 , & V_17 -> V_14 , sizeof( * V_9 -> V_14 ) ) ;
else if ( memcmp ( V_9 -> V_14 , & V_17 -> V_14 , sizeof( * V_9 -> V_14 ) ) )
F_21 ( V_126 , & V_9 -> V_33 ) ;
F_33 ( & V_9 -> V_12 ) ;
}
F_16 ( V_17 ) ;
}
void F_175 ( struct V_172 * V_173 , struct V_15 * V_17 )
{
struct V_228 * V_229 = & V_17 -> args ;
struct V_230 * V_231 = & V_17 -> V_178 ;
struct V_43 * V_43 = V_17 -> V_10 -> V_43 ;
int V_145 ;
F_138 ( L_5 ,
V_173 -> V_189 , V_173 -> V_193 ) ;
V_145 = F_74 ( V_43 ) -> F_178 ( V_173 , V_17 ) ;
if ( V_145 != 0 )
return;
F_70 ( V_43 , V_232 , V_231 -> V_47 ) ;
#if F_179 ( V_233 ) || F_179 ( V_234 )
if ( V_231 -> V_14 -> V_116 < V_229 -> V_198 && V_173 -> V_193 >= 0 ) {
static unsigned long V_235 ;
if ( F_180 ( V_235 , V_236 ) ) {
F_138 ( L_6
L_7 ,
F_50 ( V_43 ) -> V_237 -> V_238 ,
V_231 -> V_14 -> V_116 , V_229 -> V_198 ) ;
V_235 = V_236 + 300 * V_239 ;
}
}
#endif
if ( V_173 -> V_193 < 0 )
F_181 ( V_17 -> V_10 , V_173 -> V_193 , V_229 -> V_46 ) ;
else if ( V_231 -> V_47 < V_229 -> V_47 ) {
static unsigned long V_235 ;
F_39 ( V_43 , V_240 ) ;
if ( V_231 -> V_47 == 0 ) {
if ( F_180 ( V_235 , V_236 ) ) {
F_182 ( V_241
L_8 ,
V_229 -> V_47 ) ;
V_235 = V_236 + 300 * V_239 ;
}
F_181 ( V_17 -> V_10 , - V_242 , V_229 -> V_46 ) ;
V_173 -> V_193 = - V_242 ;
return;
}
if ( V_231 -> V_14 -> V_116 != V_199 ) {
V_17 -> V_195 += V_231 -> V_47 ;
V_229 -> V_46 += V_231 -> V_47 ;
V_229 -> V_196 += V_231 -> V_47 ;
V_229 -> V_47 -= V_231 -> V_47 ;
} else {
V_229 -> V_198 = V_118 ;
}
F_183 ( V_173 ) ;
}
}
static int F_184 ( struct V_35 * V_36 , int V_243 )
{
int V_63 ;
if ( ! F_177 ( V_244 , & V_36 -> V_33 ) )
return 1 ;
if ( ! V_243 )
return 0 ;
V_63 = F_185 ( & V_36 -> V_33 ,
V_244 ,
V_88 ,
V_89 ) ;
return ( V_63 < 0 ) ? V_63 : 1 ;
}
static void F_186 ( struct V_35 * V_36 )
{
F_94 ( V_244 , & V_36 -> V_33 ) ;
F_84 () ;
F_85 ( & V_36 -> V_33 , V_244 ) ;
}
void F_187 ( struct V_1 * V_17 )
{
F_17 ( V_17 -> V_25 ) ;
F_4 ( V_17 ) ;
}
int F_188 ( struct V_167 * V_168 , struct V_1 * V_17 ,
const struct V_169 * V_170 ,
int V_163 , int V_33 )
{
struct V_172 * V_173 ;
int V_171 = F_139 ( V_163 ) ;
struct V_174 V_175 = {
. V_176 = & V_17 -> args ,
. V_177 = & V_17 -> V_178 ,
. V_179 = V_17 -> V_180 ,
} ;
struct V_181 V_182 = {
. V_173 = & V_17 -> V_173 ,
. V_183 = V_168 ,
. V_174 = & V_175 ,
. V_184 = V_170 ,
. V_185 = V_17 ,
. V_186 = V_187 ,
. V_33 = V_188 | V_33 ,
. V_171 = V_171 ,
} ;
F_74 ( V_17 -> V_43 ) -> F_189 ( V_17 , & V_175 ) ;
F_138 ( L_9 , V_17 -> V_173 . V_189 ) ;
V_173 = F_143 ( & V_182 ) ;
if ( F_64 ( V_173 ) )
return F_63 ( V_173 ) ;
if ( V_163 & V_192 )
F_144 ( V_173 ) ;
F_145 ( V_173 ) ;
return 0 ;
}
void F_190 ( struct V_1 * V_17 ,
struct V_99 * V_201 ,
struct V_113 * V_114 ,
struct V_101 * V_102 )
{
struct V_34 * V_245 = F_119 ( V_201 -> V_121 ) ;
struct V_43 * V_43 = V_245 -> V_96 -> V_97 -> V_98 ;
F_191 ( V_201 , & V_17 -> V_5 ) ;
V_17 -> V_43 = V_43 ;
V_17 -> V_180 = V_245 -> V_96 -> V_180 ;
V_17 -> V_114 = V_114 ;
V_17 -> V_246 = & V_247 ;
V_17 -> V_28 = V_102 -> V_28 ;
V_17 -> V_105 = V_102 -> V_105 ;
V_17 -> args . V_194 = F_147 ( V_17 -> V_43 ) ;
V_17 -> args . V_46 = 0 ;
V_17 -> args . V_47 = 0 ;
V_17 -> V_25 = F_149 ( V_245 -> V_96 ) ;
V_17 -> V_178 . V_200 = & V_17 -> V_200 ;
V_17 -> V_178 . V_14 = & V_17 -> V_14 ;
F_150 ( & V_17 -> V_200 ) ;
}
void F_192 ( struct V_99 * V_248 ,
struct V_113 * V_114 ,
struct V_101 * V_102 )
{
struct V_34 * V_38 ;
while ( ! F_118 ( V_248 ) ) {
V_38 = F_119 ( V_248 -> V_121 ) ;
F_104 ( V_38 ) ;
F_109 ( V_38 , V_114 , V_102 ) ;
if ( ! V_102 -> V_105 ) {
F_112 ( V_38 -> V_41 , V_106 ) ;
F_113 ( F_30 ( V_38 -> V_41 ) -> V_68 ,
V_107 ) ;
}
F_132 ( V_38 ) ;
}
}
static int
F_193 ( struct V_43 * V_43 , struct V_99 * V_201 , int V_163 ,
struct V_101 * V_102 )
{
struct V_1 * V_17 ;
V_17 = F_1 () ;
if ( ! V_17 )
goto V_249;
F_190 ( V_17 , V_201 , NULL , V_102 ) ;
F_13 ( & V_102 -> V_103 -> V_250 ) ;
return F_188 ( F_152 ( V_43 ) , V_17 , V_17 -> V_246 ,
V_163 , 0 ) ;
V_249:
F_192 ( V_201 , NULL , V_102 ) ;
V_102 -> V_28 -> V_205 ( F_32 ( V_43 ) ) ;
return - V_217 ;
}
static void F_194 ( struct V_172 * V_173 , void * V_227 )
{
struct V_1 * V_17 = V_227 ;
F_138 ( L_10 ,
V_173 -> V_189 , V_173 -> V_193 ) ;
F_74 ( V_17 -> V_43 ) -> F_195 ( V_173 , V_17 ) ;
}
static void F_196 ( struct V_1 * V_17 )
{
struct V_34 * V_38 ;
int V_145 = V_17 -> V_173 . V_193 ;
struct V_101 V_102 ;
while ( ! F_118 ( & V_17 -> V_5 ) ) {
V_38 = F_119 ( V_17 -> V_5 . V_121 ) ;
F_104 ( V_38 ) ;
F_111 ( V_38 -> V_41 ) ;
F_138 ( L_11 ,
V_38 -> V_96 -> V_97 -> V_251 -> V_191 ,
( long long ) F_142 ( V_38 -> V_96 -> V_97 -> V_98 ) ,
V_38 -> V_122 ,
( long long ) F_148 ( V_38 ) ) ;
if ( V_145 < 0 ) {
F_19 ( V_38 -> V_96 , V_145 ) ;
F_91 ( V_38 ) ;
F_138 ( L_12 , V_145 ) ;
goto V_121;
}
if ( ! memcmp ( & V_38 -> V_128 , & V_17 -> V_14 . V_129 , sizeof( V_38 -> V_128 ) ) ) {
F_91 ( V_38 ) ;
F_138 ( L_13 ) ;
goto V_121;
}
F_138 ( L_14 ) ;
F_95 ( V_38 ) ;
F_21 ( V_252 , & V_38 -> V_96 -> V_33 ) ;
V_121:
F_132 ( V_38 ) ;
}
F_107 ( & V_102 , V_17 -> V_43 , V_17 -> V_105 ) ;
if ( F_18 ( & V_102 . V_103 -> V_250 ) )
F_186 ( F_32 ( V_17 -> V_43 ) ) ;
}
static void F_197 ( void * V_227 )
{
struct V_1 * V_17 = V_227 ;
V_17 -> V_28 -> V_29 ( V_17 ) ;
F_187 ( V_227 ) ;
}
int F_198 ( struct V_43 * V_43 , struct V_99 * V_201 ,
int V_163 , struct V_101 * V_102 )
{
int V_145 ;
V_145 = F_199 ( V_43 , V_201 , V_163 , V_102 ) ;
if ( V_145 == V_253 )
V_145 = F_193 ( V_43 , V_201 , V_163 , V_102 ) ;
return V_145 ;
}
int F_200 ( struct V_43 * V_43 , int V_163 )
{
F_201 ( V_201 ) ;
struct V_101 V_102 ;
int V_243 = V_163 & V_192 ;
int V_178 ;
V_178 = F_184 ( F_32 ( V_43 ) , V_243 ) ;
if ( V_178 <= 0 )
goto V_254;
F_105 ( & V_102 , V_43 ) ;
V_178 = F_125 ( V_43 , & V_201 , & V_102 ) ;
if ( V_178 ) {
int error ;
error = F_198 ( V_43 , & V_201 , V_163 , & V_102 ) ;
if ( error < 0 )
return error ;
if ( ! V_243 )
goto V_254;
error = F_202 ( & F_32 ( V_43 ) -> V_33 ,
V_244 ,
V_88 ,
V_89 ) ;
if ( error < 0 )
return error ;
} else
F_186 ( F_32 ( V_43 ) ) ;
return V_178 ;
V_254:
F_101 ( V_43 , V_108 ) ;
return V_178 ;
}
static int F_203 ( struct V_43 * V_43 , struct V_54 * V_55 )
{
struct V_35 * V_36 = F_32 ( V_43 ) ;
int V_33 = V_192 ;
int V_63 = 0 ;
if ( ! V_36 -> V_109 . V_104 )
return V_63 ;
if ( V_55 -> V_80 == V_81 ) {
if ( V_36 -> V_109 . V_104 <= ( V_36 -> V_92 >> 1 ) )
goto V_254;
V_33 = 0 ;
}
V_63 = F_200 ( V_43 , V_33 ) ;
if ( V_63 >= 0 ) {
if ( V_55 -> V_80 == V_81 ) {
if ( V_63 < V_55 -> V_255 )
V_55 -> V_255 -= V_63 ;
else
V_55 -> V_255 = 0 ;
}
return 0 ;
}
V_254:
F_101 ( V_43 , V_108 ) ;
return V_63 ;
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
. V_80 = V_256 ,
. V_255 = V_257 ,
. V_258 = 0 ,
. V_259 = V_260 ,
} ;
return F_206 ( V_43 , & V_55 ) ;
}
int F_207 ( struct V_43 * V_43 , struct V_37 * V_37 )
{
struct V_34 * V_38 ;
int V_63 = 0 ;
F_65 ( ! F_208 ( V_37 ) ) ;
for (; ; ) {
F_209 ( V_37 ) ;
V_38 = F_29 ( V_37 ) ;
if ( V_38 == NULL )
break;
if ( F_58 ( V_38 ) ) {
F_114 ( V_38 ) ;
F_91 ( V_38 ) ;
F_210 ( V_37 , V_221 ) ;
F_132 ( V_38 ) ;
break;
}
V_63 = F_59 ( V_38 ) ;
F_60 ( V_38 ) ;
if ( V_63 < 0 )
break;
}
return V_63 ;
}
int F_128 ( struct V_43 * V_43 , struct V_37 * V_37 )
{
T_1 V_258 = F_37 ( V_37 ) ;
T_1 V_259 = V_258 + ( T_1 ) ( V_221 - 1 ) ;
struct V_54 V_55 = {
. V_80 = V_256 ,
. V_255 = 0 ,
. V_258 = V_258 ,
. V_259 = V_259 ,
} ;
int V_63 ;
for (; ; ) {
F_209 ( V_37 ) ;
if ( F_211 ( V_37 ) ) {
V_63 = F_73 ( V_37 , & V_55 ) ;
if ( V_63 < 0 )
goto V_261;
continue;
}
if ( ! F_23 ( V_37 ) )
break;
V_63 = F_200 ( V_43 , V_192 ) ;
if ( V_63 < 0 )
goto V_261;
}
return 0 ;
V_261:
return V_63 ;
}
int F_212 ( struct V_85 * V_83 , struct V_37 * V_262 ,
struct V_37 * V_37 , enum V_263 V_264 )
{
if ( F_23 ( V_37 ) )
return - V_265 ;
F_213 ( V_37 , V_20 ) ;
return F_214 ( V_83 , V_262 , V_37 , V_264 ) ;
}
int T_4 F_215 ( void )
{
V_266 = F_216 ( L_15 ,
sizeof( struct V_6 ) ,
0 , V_267 ,
NULL ) ;
if ( V_266 == NULL )
return - V_217 ;
V_7 = F_217 ( V_268 ,
V_266 ) ;
if ( V_7 == NULL )
goto V_269;
V_270 = F_216 ( L_16 ,
sizeof( struct V_1 ) ,
0 , V_267 ,
NULL ) ;
if ( V_270 == NULL )
goto V_271;
V_3 = F_217 ( V_272 ,
V_266 ) ;
if ( V_3 == NULL )
goto V_273;
V_274 = ( 16 * F_218 ( V_275 ) ) << ( V_276 - 10 ) ;
if ( V_274 > 256 * 1024 )
V_274 = 256 * 1024 ;
return 0 ;
V_273:
F_219 ( V_270 ) ;
V_271:
F_220 ( V_7 ) ;
V_269:
F_219 ( V_266 ) ;
return - V_217 ;
}
void F_221 ( void )
{
F_220 ( V_3 ) ;
F_219 ( V_270 ) ;
F_220 ( V_7 ) ;
F_219 ( V_266 ) ;
}
