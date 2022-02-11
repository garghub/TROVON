static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , V_3 ) ;
if ( V_1 ) {
F_3 ( & V_1 -> V_4 , 1 ) ;
V_1 -> V_5 = 1 ;
V_1 -> V_6 = V_1 ;
V_1 -> V_7 = V_1 ;
}
return V_1 ;
}
static inline void F_4 ( struct V_1 * V_1 )
{
F_5 ( F_6 ( & V_1 -> V_4 ) ) ;
F_7 () ;
if ( F_8 ( & V_1 -> V_7 -> V_8 ) ) {
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
}
F_11 ( V_2 , V_1 ) ;
}
static inline struct V_9 * F_12 ( T_1 V_10 )
{
return F_2 ( V_11 , V_10 ) ;
}
static void F_13 ( struct V_9 * V_9 )
{
F_11 ( V_11 , V_9 ) ;
}
static void F_14 ( struct V_12 * V_13 ,
struct V_9 * V_14 ,
struct V_1 * V_1 )
{
V_14 -> V_13 = V_13 ;
V_14 -> V_1 = V_1 ;
F_15 ( & V_14 -> V_15 , & V_13 -> V_9 ) ;
F_16 ( V_14 , & V_1 -> V_16 ) ;
}
int F_17 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_1 * V_1 , * V_20 ;
struct V_9 * V_14 ;
F_7 () ;
V_14 = F_12 ( V_3 ) ;
if ( ! V_14 )
goto V_21;
V_1 = F_18 ( V_13 ) ;
V_20 = NULL ;
if ( ! V_1 ) {
V_1 = F_1 () ;
if ( F_19 ( ! V_1 ) )
goto V_22;
V_20 = V_1 ;
}
F_9 ( V_1 ) ;
F_20 ( & V_18 -> V_23 ) ;
if ( F_21 ( ! V_13 -> V_1 ) ) {
V_13 -> V_1 = V_1 ;
F_14 ( V_13 , V_14 , V_1 ) ;
V_1 -> V_5 ++ ;
V_20 = NULL ;
V_14 = NULL ;
}
F_22 ( & V_18 -> V_23 ) ;
F_10 ( V_1 ) ;
if ( F_19 ( V_20 ) )
F_23 ( V_20 ) ;
if ( F_19 ( V_14 ) )
F_13 ( V_14 ) ;
return 0 ;
V_22:
F_13 ( V_14 ) ;
V_21:
return - V_24 ;
}
static inline struct V_1 * F_24 ( struct V_1 * V_7 , struct V_1 * V_1 )
{
struct V_1 * V_25 = V_1 -> V_7 ;
if ( V_25 != V_7 ) {
if ( F_25 ( V_7 ) )
F_26 ( & V_7 -> V_8 ) ;
V_7 = V_25 ;
F_27 ( & V_7 -> V_8 ) ;
}
return V_7 ;
}
static inline void F_28 ( struct V_1 * V_7 )
{
if ( V_7 )
F_26 ( & V_7 -> V_8 ) ;
}
int F_29 ( struct V_12 * V_26 , struct V_12 * V_27 )
{
struct V_9 * V_14 , * V_28 ;
struct V_1 * V_7 = NULL ;
F_30 (pavc, &src->anon_vma_chain, same_vma) {
struct V_1 * V_1 ;
V_14 = F_12 ( V_29 | V_30 ) ;
if ( F_19 ( ! V_14 ) ) {
F_28 ( V_7 ) ;
V_7 = NULL ;
V_14 = F_12 ( V_3 ) ;
if ( ! V_14 )
goto V_31;
}
V_1 = V_28 -> V_1 ;
V_7 = F_24 ( V_7 , V_1 ) ;
F_14 ( V_26 , V_14 , V_1 ) ;
if ( ! V_26 -> V_1 && V_1 != V_27 -> V_1 &&
V_1 -> V_5 < 2 )
V_26 -> V_1 = V_1 ;
}
if ( V_26 -> V_1 )
V_26 -> V_1 -> V_5 ++ ;
F_28 ( V_7 ) ;
return 0 ;
V_31:
V_26 -> V_1 = NULL ;
F_31 ( V_26 ) ;
return - V_24 ;
}
int F_32 ( struct V_12 * V_13 , struct V_12 * V_32 )
{
struct V_9 * V_14 ;
struct V_1 * V_1 ;
int error ;
if ( ! V_32 -> V_1 )
return 0 ;
V_13 -> V_1 = NULL ;
error = F_29 ( V_13 , V_32 ) ;
if ( error )
return error ;
if ( V_13 -> V_1 )
return 0 ;
V_1 = F_1 () ;
if ( ! V_1 )
goto V_33;
V_14 = F_12 ( V_3 ) ;
if ( ! V_14 )
goto V_34;
V_1 -> V_7 = V_32 -> V_1 -> V_7 ;
V_1 -> V_6 = V_32 -> V_1 ;
F_33 ( V_1 -> V_7 ) ;
V_13 -> V_1 = V_1 ;
F_9 ( V_1 ) ;
F_14 ( V_13 , V_14 , V_1 ) ;
V_1 -> V_6 -> V_5 ++ ;
F_10 ( V_1 ) ;
return 0 ;
V_34:
F_23 ( V_1 ) ;
V_33:
F_31 ( V_13 ) ;
return - V_24 ;
}
void F_31 ( struct V_12 * V_13 )
{
struct V_9 * V_14 , * V_35 ;
struct V_1 * V_7 = NULL ;
F_34 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_14 -> V_1 ;
V_7 = F_24 ( V_7 , V_1 ) ;
F_35 ( V_14 , & V_1 -> V_16 ) ;
if ( F_36 ( & V_1 -> V_16 ) ) {
V_1 -> V_6 -> V_5 -- ;
continue;
}
F_37 ( & V_14 -> V_15 ) ;
F_13 ( V_14 ) ;
}
if ( V_13 -> V_1 )
V_13 -> V_1 -> V_5 -- ;
F_28 ( V_7 ) ;
F_34 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_14 -> V_1 ;
F_38 ( V_1 -> V_5 ) ;
F_23 ( V_1 ) ;
F_37 ( & V_14 -> V_15 ) ;
F_13 ( V_14 ) ;
}
}
static void F_39 ( void * V_36 )
{
struct V_1 * V_1 = V_36 ;
F_40 ( & V_1 -> V_8 ) ;
F_3 ( & V_1 -> V_4 , 0 ) ;
V_1 -> V_16 = V_37 ;
}
void T_2 F_41 ( void )
{
V_2 = F_42 ( L_1 , sizeof( struct V_1 ) ,
0 , V_38 | V_39 | V_40 ,
F_39 ) ;
V_11 = F_43 ( V_9 ,
V_39 | V_40 ) ;
}
struct V_1 * F_44 ( struct V_41 * V_41 )
{
struct V_1 * V_1 = NULL ;
unsigned long V_42 ;
F_45 () ;
V_42 = ( unsigned long ) F_46 ( V_41 -> V_43 ) ;
if ( ( V_42 & V_44 ) != V_45 )
goto V_46;
if ( ! F_47 ( V_41 ) )
goto V_46;
V_1 = (struct V_1 * ) ( V_42 - V_45 ) ;
if ( ! F_48 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_46;
}
if ( ! F_47 ( V_41 ) ) {
F_49 () ;
F_23 ( V_1 ) ;
return NULL ;
}
V_46:
F_49 () ;
return V_1 ;
}
struct V_1 * F_50 ( struct V_41 * V_41 )
{
struct V_1 * V_1 = NULL ;
struct V_1 * V_47 ;
unsigned long V_42 ;
F_45 () ;
V_42 = ( unsigned long ) F_46 ( V_41 -> V_43 ) ;
if ( ( V_42 & V_44 ) != V_45 )
goto V_46;
if ( ! F_47 ( V_41 ) )
goto V_46;
V_1 = (struct V_1 * ) ( V_42 - V_45 ) ;
V_47 = F_46 ( V_1 -> V_7 ) ;
if ( F_51 ( & V_47 -> V_8 ) ) {
if ( ! F_47 ( V_41 ) ) {
F_52 ( & V_47 -> V_8 ) ;
V_1 = NULL ;
}
goto V_46;
}
if ( ! F_48 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_46;
}
if ( ! F_47 ( V_41 ) ) {
F_49 () ;
F_23 ( V_1 ) ;
return NULL ;
}
F_49 () ;
F_53 ( V_1 ) ;
if ( F_54 ( & V_1 -> V_4 ) ) {
F_55 ( V_1 ) ;
F_56 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
V_46:
F_49 () ;
return V_1 ;
}
void F_57 ( struct V_1 * V_1 )
{
F_55 ( V_1 ) ;
}
void F_58 ( void )
{
struct V_48 * V_49 = & V_50 -> V_49 ;
int V_51 ;
if ( ! V_49 -> V_52 )
return;
V_51 = F_59 () ;
if ( F_60 ( V_51 , & V_49 -> V_53 ) ) {
F_61 ( V_54 ) ;
F_62 () ;
F_63 ( V_55 , V_56 ) ;
}
if ( F_64 ( & V_49 -> V_53 , V_51 ) < V_57 )
F_65 ( & V_49 -> V_53 , NULL , 0 , V_56 ) ;
F_66 ( & V_49 -> V_53 ) ;
V_49 -> V_52 = false ;
V_49 -> V_58 = false ;
F_67 () ;
}
void F_68 ( void )
{
struct V_48 * V_49 = & V_50 -> V_49 ;
if ( V_49 -> V_58 )
F_58 () ;
}
static void F_69 ( struct V_17 * V_18 , bool V_58 )
{
struct V_48 * V_49 = & V_50 -> V_49 ;
F_70 ( & V_49 -> V_53 , & V_49 -> V_53 , F_71 ( V_18 ) ) ;
V_49 -> V_52 = true ;
if ( V_58 )
V_49 -> V_58 = true ;
}
static bool F_72 ( struct V_17 * V_18 , enum V_59 V_60 )
{
bool V_61 = false ;
if ( ! ( V_60 & V_62 ) )
return false ;
if ( F_64 ( F_71 ( V_18 ) , F_59 () ) < V_57 )
V_61 = true ;
F_67 () ;
return V_61 ;
}
static void F_69 ( struct V_17 * V_18 , bool V_58 )
{
}
static bool F_72 ( struct V_17 * V_18 , enum V_59 V_60 )
{
return false ;
}
unsigned long F_73 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
unsigned long V_63 ;
if ( F_74 ( V_41 ) ) {
struct V_1 * V_64 = F_75 ( V_41 ) ;
if ( ! V_13 -> V_1 || ! V_64 ||
V_13 -> V_1 -> V_7 != V_64 -> V_7 )
return - V_65 ;
} else if ( V_41 -> V_43 ) {
if ( ! V_13 -> V_66 || V_13 -> V_66 -> V_67 != V_41 -> V_43 )
return - V_65 ;
} else
return - V_65 ;
V_63 = F_76 ( V_41 , V_13 ) ;
if ( F_19 ( V_63 < V_13 -> V_68 || V_63 >= V_13 -> V_69 ) )
return - V_65 ;
return V_63 ;
}
T_3 * F_77 ( struct V_17 * V_18 , unsigned long V_63 )
{
T_4 * V_70 ;
T_5 * V_71 ;
T_6 * V_72 ;
T_3 * V_73 = NULL ;
T_3 V_74 ;
V_70 = F_78 ( V_18 , V_63 ) ;
if ( ! F_79 ( * V_70 ) )
goto V_46;
V_71 = F_80 ( V_70 , V_63 ) ;
if ( ! F_81 ( * V_71 ) )
goto V_46;
V_72 = F_82 ( V_71 , V_63 ) ;
if ( ! F_83 ( * V_72 ) )
goto V_46;
V_73 = F_84 ( V_72 , V_63 ) ;
V_74 = * V_73 ;
F_85 () ;
if ( ! F_86 ( V_74 ) || F_87 ( V_74 ) )
V_73 = NULL ;
V_46:
return V_73 ;
}
static int F_88 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_63 , void * V_75 )
{
struct V_76 * V_77 = V_75 ;
struct V_78 V_79 = {
. V_41 = V_41 ,
. V_13 = V_13 ,
. V_63 = V_63 ,
} ;
int V_80 = 0 ;
while ( V_78 ( & V_79 ) ) {
V_63 = V_79 . V_63 ;
if ( V_13 -> V_81 & V_82 ) {
F_89 ( & V_79 ) ;
V_77 -> V_81 |= V_82 ;
return V_83 ;
}
if ( V_79 . V_84 ) {
if ( F_90 ( V_13 , V_63 ,
V_79 . V_84 ) ) {
if ( F_21 ( ! ( V_13 -> V_81 & V_85 ) ) )
V_80 ++ ;
}
} else if ( F_91 ( V_86 ) ) {
if ( F_92 ( V_13 , V_63 ,
V_79 . V_73 ) )
V_80 ++ ;
} else {
F_25 ( 1 ) ;
}
V_77 -> V_87 -- ;
}
if ( V_80 )
F_93 ( V_41 ) ;
if ( F_94 ( V_41 ) )
V_80 ++ ;
if ( V_80 ) {
V_77 -> V_80 ++ ;
V_77 -> V_81 |= V_13 -> V_81 ;
}
if ( ! V_77 -> V_87 )
return V_88 ;
return V_89 ;
}
static bool F_95 ( struct V_12 * V_13 , void * V_75 )
{
struct V_76 * V_77 = V_75 ;
struct V_90 * V_91 = V_77 -> V_91 ;
if ( ! F_96 ( V_13 -> V_19 , V_91 ) )
return true ;
return false ;
}
int F_97 ( struct V_41 * V_41 ,
int V_92 ,
struct V_90 * V_91 ,
unsigned long * V_81 )
{
int V_93 ;
int V_94 = 0 ;
struct V_76 V_77 = {
. V_87 = F_98 ( V_41 ) ,
. V_91 = V_91 ,
} ;
struct V_95 V_96 = {
. V_97 = F_88 ,
. V_75 = ( void * ) & V_77 ,
. V_98 = F_50 ,
} ;
* V_81 = 0 ;
if ( ! F_47 ( V_41 ) )
return 0 ;
if ( ! F_99 ( V_41 ) )
return 0 ;
if ( ! V_92 && ( ! F_74 ( V_41 ) || F_100 ( V_41 ) ) ) {
V_94 = F_101 ( V_41 ) ;
if ( ! V_94 )
return 1 ;
}
if ( V_91 ) {
V_96 . V_99 = F_95 ;
}
V_93 = F_102 ( V_41 , & V_96 ) ;
* V_81 = V_77 . V_81 ;
if ( V_94 )
F_103 ( V_41 ) ;
return V_77 . V_80 ;
}
static int F_104 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_63 , void * V_75 )
{
struct V_78 V_79 = {
. V_41 = V_41 ,
. V_13 = V_13 ,
. V_63 = V_63 ,
. V_60 = V_100 ,
} ;
int * V_101 = V_75 ;
while ( V_78 ( & V_79 ) ) {
int V_93 = 0 ;
V_63 = V_79 . V_63 ;
if ( V_79 . V_84 ) {
T_7 V_102 ;
T_7 * V_84 = V_79 . V_84 ;
if ( ! F_105 ( * V_84 ) && ! F_106 ( * V_84 ) )
continue;
F_107 ( V_13 , V_63 , F_108 ( * V_84 ) ) ;
V_102 = F_109 ( V_13 , V_63 , V_84 ) ;
V_102 = F_110 ( V_102 ) ;
V_102 = F_111 ( V_102 ) ;
F_112 ( V_13 -> V_19 , V_63 , V_84 , V_102 ) ;
V_93 = 1 ;
} else {
#ifdef F_113
T_3 * V_73 = V_79 . V_73 ;
T_3 V_102 ;
if ( ! F_114 ( * V_73 ) && ! F_115 ( * V_73 ) )
continue;
F_107 ( V_13 , V_63 , F_116 ( V_41 ) ) ;
V_102 = F_117 ( V_13 , V_63 , V_73 ) ;
V_102 = F_118 ( V_102 ) ;
V_102 = F_119 ( V_102 ) ;
F_120 ( V_13 -> V_19 , V_63 , V_73 , V_102 ) ;
V_93 = 1 ;
#else
F_25 ( 1 ) ;
#endif
}
if ( V_93 ) {
F_121 ( V_13 -> V_19 , V_63 ) ;
( * V_101 ) ++ ;
}
}
return V_89 ;
}
static bool F_122 ( struct V_12 * V_13 , void * V_75 )
{
if ( V_13 -> V_81 & V_103 )
return false ;
return true ;
}
int F_123 ( struct V_41 * V_41 )
{
int V_101 = 0 ;
struct V_104 * V_43 ;
struct V_95 V_96 = {
. V_75 = ( void * ) & V_101 ,
. V_97 = F_104 ,
. V_99 = F_122 ,
} ;
F_124 ( ! F_125 ( V_41 ) ) ;
if ( ! F_47 ( V_41 ) )
return 0 ;
V_43 = F_126 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
F_102 ( V_41 , & V_96 ) ;
return V_101 ;
}
void F_127 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
V_41 = F_128 ( V_41 ) ;
F_129 ( ! F_125 ( V_41 ) , V_41 ) ;
F_130 ( ! V_1 , V_13 ) ;
V_1 = ( void * ) V_1 + V_45 ;
F_131 ( V_41 -> V_43 , (struct V_104 * ) V_1 ) ;
}
static void F_132 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , int V_105 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_124 ( ! V_1 ) ;
if ( F_74 ( V_41 ) )
return;
if ( ! V_105 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_104 * ) V_1 ;
V_41 -> V_106 = F_133 ( V_13 , V_63 ) ;
}
static void F_134 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 )
{
#ifdef F_135
F_124 ( F_75 ( V_41 ) -> V_7 != V_13 -> V_1 -> V_7 ) ;
F_124 ( F_136 ( V_41 ) != F_133 ( V_13 , V_63 ) ) ;
#endif
}
void F_137 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , bool V_107 )
{
F_138 ( V_41 , V_13 , V_63 , V_107 ? V_108 : 0 ) ;
}
void F_138 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , int V_60 )
{
bool V_107 = V_60 & V_108 ;
bool V_109 ;
if ( V_107 ) {
T_8 * V_87 ;
F_129 ( ! F_125 ( V_41 ) , V_41 ) ;
F_129 ( ! F_139 ( V_41 ) , V_41 ) ;
V_87 = F_140 ( V_41 ) ;
V_109 = F_141 ( V_87 ) ;
} else {
V_109 = F_141 ( & V_41 -> V_110 ) ;
}
if ( V_109 ) {
int V_111 = V_107 ? F_142 ( V_41 ) : 1 ;
if ( V_107 )
F_143 ( V_41 , V_112 ) ;
F_144 ( F_145 ( V_41 ) , V_113 , V_111 ) ;
}
if ( F_19 ( F_100 ( V_41 ) ) )
return;
F_129 ( ! F_125 ( V_41 ) , V_41 ) ;
if ( V_109 )
F_132 ( V_41 , V_13 , V_63 ,
V_60 & V_114 ) ;
else
F_134 ( V_41 , V_13 , V_63 ) ;
}
void F_146 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , bool V_107 )
{
int V_111 = V_107 ? F_142 ( V_41 ) : 1 ;
F_130 ( V_63 < V_13 -> V_68 || V_63 >= V_13 -> V_69 , V_13 ) ;
F_147 ( V_41 ) ;
if ( V_107 ) {
F_129 ( ! F_139 ( V_41 ) , V_41 ) ;
F_3 ( F_140 ( V_41 ) , 0 ) ;
F_143 ( V_41 , V_112 ) ;
} else {
F_129 ( F_148 ( V_41 ) , V_41 ) ;
F_3 ( & V_41 -> V_110 , 0 ) ;
}
F_144 ( F_145 ( V_41 ) , V_113 , V_111 ) ;
F_132 ( V_41 , V_13 , V_63 , 1 ) ;
}
void F_149 ( struct V_41 * V_41 , bool V_107 )
{
int V_115 , V_111 = 1 ;
F_129 ( V_107 && ! F_139 ( V_41 ) , V_41 ) ;
F_150 ( V_41 ) ;
if ( V_107 && F_139 ( V_41 ) ) {
for ( V_115 = 0 , V_111 = 0 ; V_115 < V_116 ; V_115 ++ ) {
if ( F_141 ( & V_41 [ V_115 ] . V_110 ) )
V_111 ++ ;
}
if ( ! F_141 ( F_140 ( V_41 ) ) )
goto V_46;
F_129 ( ! F_151 ( V_41 ) , V_41 ) ;
F_143 ( V_41 , V_117 ) ;
} else {
if ( F_148 ( V_41 ) && F_126 ( V_41 ) ) {
F_152 ( ! F_125 ( V_41 ) ) ;
F_153 ( F_128 ( V_41 ) ) ;
if ( F_154 ( V_41 ) )
F_155 ( F_128 ( V_41 ) ) ;
}
if ( ! F_141 ( & V_41 -> V_110 ) )
goto V_46;
}
F_144 ( F_145 ( V_41 ) , V_118 , V_111 ) ;
F_156 ( V_41 , V_119 , V_111 ) ;
V_46:
F_157 ( V_41 ) ;
}
static void F_158 ( struct V_41 * V_41 , bool V_107 )
{
int V_115 , V_111 = 1 ;
F_129 ( V_107 && ! F_159 ( V_41 ) , V_41 ) ;
F_150 ( V_41 ) ;
if ( F_19 ( F_160 ( V_41 ) ) ) {
F_161 ( F_140 ( V_41 ) ) ;
goto V_46;
}
if ( V_107 && F_139 ( V_41 ) ) {
for ( V_115 = 0 , V_111 = 0 ; V_115 < V_116 ; V_115 ++ ) {
if ( F_162 ( - 1 , & V_41 [ V_115 ] . V_110 ) )
V_111 ++ ;
}
if ( ! F_162 ( - 1 , F_140 ( V_41 ) ) )
goto V_46;
F_129 ( ! F_151 ( V_41 ) , V_41 ) ;
F_163 ( V_41 , V_117 ) ;
} else {
if ( ! F_162 ( - 1 , & V_41 -> V_110 ) )
goto V_46;
}
F_144 ( F_145 ( V_41 ) , V_118 , - V_111 ) ;
F_156 ( V_41 , V_119 , - V_111 ) ;
if ( F_19 ( F_154 ( V_41 ) ) )
F_155 ( V_41 ) ;
V_46:
F_157 ( V_41 ) ;
}
static void F_164 ( struct V_41 * V_41 )
{
int V_115 , V_111 ;
if ( ! F_162 ( - 1 , F_140 ( V_41 ) ) )
return;
if ( F_19 ( F_160 ( V_41 ) ) )
return;
if ( ! F_91 ( V_86 ) )
return;
F_163 ( V_41 , V_112 ) ;
if ( F_165 ( V_41 ) ) {
for ( V_115 = 0 , V_111 = 0 ; V_115 < V_116 ; V_115 ++ ) {
if ( F_162 ( - 1 , & V_41 [ V_115 ] . V_110 ) )
V_111 ++ ;
}
} else {
V_111 = V_116 ;
}
if ( F_19 ( F_154 ( V_41 ) ) )
F_155 ( V_41 ) ;
if ( V_111 ) {
F_144 ( F_145 ( V_41 ) , V_113 , - V_111 ) ;
F_166 ( V_41 ) ;
}
}
void F_167 ( struct V_41 * V_41 , bool V_107 )
{
if ( ! F_74 ( V_41 ) )
return F_158 ( V_41 , V_107 ) ;
if ( V_107 )
return F_164 ( V_41 ) ;
if ( ! F_162 ( - 1 , & V_41 -> V_110 ) )
return;
F_163 ( V_41 , V_113 ) ;
if ( F_19 ( F_154 ( V_41 ) ) )
F_155 ( V_41 ) ;
if ( F_148 ( V_41 ) )
F_166 ( F_128 ( V_41 ) ) ;
}
static int F_168 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_63 , void * V_75 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_78 V_79 = {
. V_41 = V_41 ,
. V_13 = V_13 ,
. V_63 = V_63 ,
} ;
T_7 V_120 ;
struct V_41 * V_121 ;
int V_93 = V_89 ;
struct V_122 * V_123 = V_75 ;
enum V_59 V_60 = V_123 -> V_60 ;
if ( ( V_60 & V_124 ) && ! ( V_13 -> V_81 & V_82 ) )
return V_89 ;
if ( V_60 & V_125 ) {
F_169 ( V_13 , V_63 ,
V_60 & V_126 , V_41 ) ;
}
while ( V_78 ( & V_79 ) ) {
if ( ! ( V_60 & V_127 ) ) {
if ( V_13 -> V_81 & V_82 ) {
if ( ! F_148 ( V_41 ) ) {
F_170 ( V_41 ) ;
}
V_93 = V_128 ;
F_89 ( & V_79 ) ;
break;
}
if ( V_60 & V_124 )
continue;
}
F_129 ( ! V_79 . V_84 , V_41 ) ;
V_121 = V_41 - F_116 ( V_41 ) + F_108 ( * V_79 . V_84 ) ;
V_63 = V_79 . V_63 ;
if ( ! ( V_60 & V_129 ) ) {
if ( F_90 ( V_13 , V_63 ,
V_79 . V_84 ) ) {
V_93 = V_83 ;
F_89 ( & V_79 ) ;
break;
}
}
F_107 ( V_13 , V_63 , F_108 ( * V_79 . V_84 ) ) ;
if ( F_72 ( V_18 , V_60 ) ) {
V_120 = F_171 ( V_18 , V_63 , V_79 . V_84 ) ;
F_69 ( V_18 , F_105 ( V_120 ) ) ;
} else {
V_120 = F_109 ( V_13 , V_63 , V_79 . V_84 ) ;
}
if ( F_105 ( V_120 ) )
F_172 ( V_41 ) ;
F_173 ( V_18 ) ;
if ( F_174 ( V_41 ) && ! ( V_60 & V_130 ) ) {
if ( F_160 ( V_41 ) ) {
int V_111 = 1 << F_175 ( V_41 ) ;
F_176 ( V_111 , V_18 ) ;
} else {
F_177 ( V_18 , F_178 ( V_41 ) ) ;
}
V_120 = F_179 ( F_180 ( V_121 ) ) ;
F_112 ( V_18 , V_63 , V_79 . V_84 , V_120 ) ;
} else if ( F_181 ( V_120 ) ) {
F_177 ( V_18 , F_178 ( V_41 ) ) ;
} else if ( F_91 ( V_131 ) &&
( V_60 & V_126 ) ) {
T_9 V_102 ;
T_7 V_132 ;
V_102 = F_182 ( V_121 ,
F_106 ( V_120 ) ) ;
V_132 = F_179 ( V_102 ) ;
if ( F_183 ( V_120 ) )
V_132 = F_184 ( V_132 ) ;
F_112 ( V_18 , V_63 , V_79 . V_84 , V_132 ) ;
} else if ( F_74 ( V_41 ) ) {
T_9 V_102 = { . V_133 = F_185 (subpage) } ;
T_7 V_132 ;
F_129 ( ! F_186 ( V_41 ) , V_41 ) ;
if ( ! F_187 ( V_41 ) && ( V_60 & V_134 ) ) {
F_177 ( V_18 , V_135 ) ;
V_123 -> V_136 ++ ;
goto V_137;
}
if ( F_188 ( V_102 ) < 0 ) {
F_112 ( V_18 , V_63 , V_79 . V_84 , V_120 ) ;
V_93 = V_83 ;
F_89 ( & V_79 ) ;
break;
}
if ( F_189 ( & V_18 -> V_138 ) ) {
F_20 ( & V_139 ) ;
if ( F_189 ( & V_18 -> V_138 ) )
F_15 ( & V_18 -> V_138 , & V_140 . V_138 ) ;
F_22 ( & V_139 ) ;
}
F_177 ( V_18 , V_135 ) ;
F_190 ( V_18 , V_141 ) ;
V_132 = F_179 ( V_102 ) ;
if ( F_183 ( V_120 ) )
V_132 = F_184 ( V_132 ) ;
F_112 ( V_18 , V_63 , V_79 . V_84 , V_132 ) ;
} else
F_177 ( V_18 , F_191 ( V_41 ) ) ;
V_137:
F_167 ( V_121 , F_160 ( V_41 ) ) ;
F_192 ( V_41 ) ;
F_121 ( V_18 , V_63 ) ;
}
return V_93 ;
}
bool F_193 ( struct V_12 * V_13 )
{
int V_142 = V_13 -> V_81 & ( V_143 | V_144 ) ;
if ( ! V_142 )
return false ;
if ( ( V_13 -> V_81 & V_145 ) ==
V_145 )
return true ;
return false ;
}
static bool F_194 ( struct V_12 * V_13 , void * V_75 )
{
return F_193 ( V_13 ) ;
}
static int F_195 ( struct V_41 * V_41 )
{
return ! F_98 ( V_41 ) ;
}
int F_196 ( struct V_41 * V_41 , enum V_59 V_60 )
{
int V_93 ;
struct V_122 V_123 = {
. V_60 = V_60 ,
. V_136 = 0 ,
} ;
struct V_95 V_96 = {
. V_97 = F_168 ,
. V_75 = & V_123 ,
. V_146 = F_195 ,
. V_98 = F_50 ,
} ;
if ( ( V_60 & V_126 ) && ! F_100 ( V_41 ) && F_74 ( V_41 ) )
V_96 . V_99 = F_194 ;
if ( V_60 & V_147 )
V_93 = F_197 ( V_41 , & V_96 ) ;
else
V_93 = F_102 ( V_41 , & V_96 ) ;
if ( V_93 != V_128 && ! F_198 ( V_41 ) ) {
V_93 = V_88 ;
if ( V_123 . V_136 && ! F_187 ( V_41 ) )
V_93 = V_148 ;
}
return V_93 ;
}
static int F_199 ( struct V_41 * V_41 )
{
return ! F_47 ( V_41 ) ;
}
int F_200 ( struct V_41 * V_41 )
{
int V_93 ;
struct V_122 V_123 = {
. V_60 = V_124 ,
. V_136 = 0 ,
} ;
struct V_95 V_96 = {
. V_97 = F_168 ,
. V_75 = & V_123 ,
. V_146 = F_199 ,
. V_98 = F_50 ,
} ;
F_129 ( ! F_125 ( V_41 ) || F_201 ( V_41 ) , V_41 ) ;
V_93 = F_102 ( V_41 , & V_96 ) ;
return V_93 ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_1 * V_7 = V_1 -> V_7 ;
F_4 ( V_1 ) ;
if ( V_7 != V_1 && F_54 ( & V_7 -> V_4 ) )
F_4 ( V_7 ) ;
}
static struct V_1 * F_202 ( struct V_41 * V_41 ,
struct V_95 * V_96 )
{
struct V_1 * V_1 ;
if ( V_96 -> V_98 )
return V_96 -> V_98 ( V_41 ) ;
V_1 = F_75 ( V_41 ) ;
if ( ! V_1 )
return NULL ;
F_53 ( V_1 ) ;
return V_1 ;
}
static int F_203 ( struct V_41 * V_41 , struct V_95 * V_96 ,
bool V_149 )
{
struct V_1 * V_1 ;
T_10 V_150 , V_151 ;
struct V_9 * V_14 ;
int V_93 = V_89 ;
if ( V_149 ) {
V_1 = F_75 ( V_41 ) ;
F_129 ( ! V_1 , V_41 ) ;
} else {
V_1 = F_202 ( V_41 , V_96 ) ;
}
if ( ! V_1 )
return V_93 ;
V_150 = F_136 ( V_41 ) ;
V_151 = V_150 + F_142 ( V_41 ) - 1 ;
F_204 (avc, &anon_vma->rb_root,
pgoff_start, pgoff_end) {
struct V_12 * V_13 = V_14 -> V_13 ;
unsigned long V_63 = F_205 ( V_41 , V_13 ) ;
F_206 () ;
if ( V_96 -> V_99 && V_96 -> V_99 ( V_13 , V_96 -> V_75 ) )
continue;
V_93 = V_96 -> V_97 ( V_41 , V_13 , V_63 , V_96 -> V_75 ) ;
if ( V_93 != V_89 )
break;
if ( V_96 -> V_146 && V_96 -> V_146 ( V_41 ) )
break;
}
if ( ! V_149 )
F_55 ( V_1 ) ;
return V_93 ;
}
static int F_207 ( struct V_41 * V_41 , struct V_95 * V_96 ,
bool V_149 )
{
struct V_104 * V_43 = F_126 ( V_41 ) ;
T_10 V_150 , V_151 ;
struct V_12 * V_13 ;
int V_93 = V_89 ;
F_129 ( ! F_125 ( V_41 ) , V_41 ) ;
if ( ! V_43 )
return V_93 ;
V_150 = F_136 ( V_41 ) ;
V_151 = V_150 + F_142 ( V_41 ) - 1 ;
if ( ! V_149 )
F_208 ( V_43 ) ;
F_209 (vma, &mapping->i_mmap,
pgoff_start, pgoff_end) {
unsigned long V_63 = F_205 ( V_41 , V_13 ) ;
F_206 () ;
if ( V_96 -> V_99 && V_96 -> V_99 ( V_13 , V_96 -> V_75 ) )
continue;
V_93 = V_96 -> V_97 ( V_41 , V_13 , V_63 , V_96 -> V_75 ) ;
if ( V_93 != V_89 )
goto V_146;
if ( V_96 -> V_146 && V_96 -> V_146 ( V_41 ) )
goto V_146;
}
V_146:
if ( ! V_149 )
F_210 ( V_43 ) ;
return V_93 ;
}
int F_102 ( struct V_41 * V_41 , struct V_95 * V_96 )
{
if ( F_19 ( F_100 ( V_41 ) ) )
return F_211 ( V_41 , V_96 ) ;
else if ( F_74 ( V_41 ) )
return F_203 ( V_41 , V_96 , false ) ;
else
return F_207 ( V_41 , V_96 , false ) ;
}
int F_197 ( struct V_41 * V_41 , struct V_95 * V_96 )
{
F_129 ( F_100 ( V_41 ) , V_41 ) ;
if ( F_74 ( V_41 ) )
return F_203 ( V_41 , V_96 , true ) ;
else
return F_207 ( V_41 , V_96 , true ) ;
}
static void F_212 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , int V_105 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_124 ( ! V_1 ) ;
if ( F_74 ( V_41 ) )
return;
if ( ! V_105 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_104 * ) V_1 ;
V_41 -> V_106 = F_133 ( V_13 , V_63 ) ;
}
void F_213 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
int V_109 ;
F_124 ( ! F_125 ( V_41 ) ) ;
F_124 ( ! V_1 ) ;
V_109 = F_141 ( F_140 ( V_41 ) ) ;
if ( V_109 )
F_212 ( V_41 , V_13 , V_63 , 0 ) ;
}
void F_214 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 )
{
F_124 ( V_63 < V_13 -> V_68 || V_63 >= V_13 -> V_69 ) ;
F_3 ( F_140 ( V_41 ) , 0 ) ;
F_212 ( V_41 , V_13 , V_63 , 1 ) ;
}
