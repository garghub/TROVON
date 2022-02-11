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
if ( ! V_49 -> V_51 )
return;
F_59 ( & V_49 -> V_52 ) ;
V_49 -> V_51 = false ;
V_49 -> V_53 = false ;
}
void F_60 ( void )
{
struct V_48 * V_49 = & V_50 -> V_49 ;
if ( V_49 -> V_53 )
F_58 () ;
}
static void F_61 ( struct V_17 * V_18 , bool V_53 )
{
struct V_48 * V_49 = & V_50 -> V_49 ;
F_62 ( & V_49 -> V_52 , V_18 ) ;
V_49 -> V_51 = true ;
F_63 () ;
V_18 -> V_54 = true ;
if ( V_53 )
V_49 -> V_53 = true ;
}
static bool F_64 ( struct V_17 * V_18 , enum V_55 V_56 )
{
bool V_57 = false ;
if ( ! ( V_56 & V_58 ) )
return false ;
if ( F_65 ( F_66 ( V_18 ) , F_67 () ) < V_59 )
V_57 = true ;
F_68 () ;
return V_57 ;
}
void F_69 ( struct V_17 * V_18 )
{
if ( V_18 -> V_54 ) {
F_70 ( V_18 ) ;
F_63 () ;
V_18 -> V_54 = false ;
}
}
static void F_61 ( struct V_17 * V_18 , bool V_53 )
{
}
static bool F_64 ( struct V_17 * V_18 , enum V_55 V_56 )
{
return false ;
}
unsigned long F_71 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
unsigned long V_60 ;
if ( F_72 ( V_41 ) ) {
struct V_1 * V_61 = F_73 ( V_41 ) ;
if ( ! V_13 -> V_1 || ! V_61 ||
V_13 -> V_1 -> V_7 != V_61 -> V_7 )
return - V_62 ;
} else if ( V_41 -> V_43 ) {
if ( ! V_13 -> V_63 || V_13 -> V_63 -> V_64 != V_41 -> V_43 )
return - V_62 ;
} else
return - V_62 ;
V_60 = F_74 ( V_41 , V_13 ) ;
if ( F_19 ( V_60 < V_13 -> V_65 || V_60 >= V_13 -> V_66 ) )
return - V_62 ;
return V_60 ;
}
T_3 * F_75 ( struct V_17 * V_18 , unsigned long V_60 )
{
T_4 * V_67 ;
T_5 * V_68 ;
T_6 * V_69 ;
T_3 * V_70 = NULL ;
T_3 V_71 ;
V_67 = F_76 ( V_18 , V_60 ) ;
if ( ! F_77 ( * V_67 ) )
goto V_46;
V_68 = F_78 ( V_67 , V_60 ) ;
if ( ! F_79 ( * V_68 ) )
goto V_46;
V_69 = F_80 ( V_68 , V_60 ) ;
if ( ! F_81 ( * V_69 ) )
goto V_46;
V_70 = F_82 ( V_69 , V_60 ) ;
V_71 = * V_70 ;
F_63 () ;
if ( ! F_83 ( V_71 ) || F_84 ( V_71 ) )
V_70 = NULL ;
V_46:
return V_70 ;
}
static bool F_85 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_60 , void * V_72 )
{
struct V_73 * V_74 = V_72 ;
struct V_75 V_76 = {
. V_41 = V_41 ,
. V_13 = V_13 ,
. V_60 = V_60 ,
} ;
int V_77 = 0 ;
while ( V_75 ( & V_76 ) ) {
V_60 = V_76 . V_60 ;
if ( V_13 -> V_78 & V_79 ) {
F_86 ( & V_76 ) ;
V_74 -> V_78 |= V_79 ;
return false ;
}
if ( V_76 . V_80 ) {
if ( F_87 ( V_13 , V_60 ,
V_76 . V_80 ) ) {
if ( F_21 ( ! ( V_13 -> V_78 & V_81 ) ) )
V_77 ++ ;
}
} else if ( F_88 ( V_82 ) ) {
if ( F_89 ( V_13 , V_60 ,
V_76 . V_70 ) )
V_77 ++ ;
} else {
F_25 ( 1 ) ;
}
V_74 -> V_83 -- ;
}
if ( V_77 )
F_90 ( V_41 ) ;
if ( F_91 ( V_41 ) )
V_77 ++ ;
if ( V_77 ) {
V_74 -> V_77 ++ ;
V_74 -> V_78 |= V_13 -> V_78 ;
}
if ( ! V_74 -> V_83 )
return false ;
return true ;
}
static bool F_92 ( struct V_12 * V_13 , void * V_72 )
{
struct V_73 * V_74 = V_72 ;
struct V_84 * V_85 = V_74 -> V_85 ;
if ( ! F_93 ( V_13 -> V_19 , V_85 ) )
return true ;
return false ;
}
int F_94 ( struct V_41 * V_41 ,
int V_86 ,
struct V_84 * V_85 ,
unsigned long * V_78 )
{
int V_87 = 0 ;
struct V_73 V_74 = {
. V_83 = F_95 ( V_41 ) ,
. V_85 = V_85 ,
} ;
struct V_88 V_89 = {
. V_90 = F_85 ,
. V_72 = ( void * ) & V_74 ,
. V_91 = F_50 ,
} ;
* V_78 = 0 ;
if ( ! F_47 ( V_41 ) )
return 0 ;
if ( ! F_96 ( V_41 ) )
return 0 ;
if ( ! V_86 && ( ! F_72 ( V_41 ) || F_97 ( V_41 ) ) ) {
V_87 = F_98 ( V_41 ) ;
if ( ! V_87 )
return 1 ;
}
if ( V_85 ) {
V_89 . V_92 = F_92 ;
}
F_99 ( V_41 , & V_89 ) ;
* V_78 = V_74 . V_78 ;
if ( V_87 )
F_100 ( V_41 ) ;
return V_74 . V_77 ;
}
static bool F_101 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_60 , void * V_72 )
{
struct V_75 V_76 = {
. V_41 = V_41 ,
. V_13 = V_13 ,
. V_60 = V_60 ,
. V_56 = V_93 ,
} ;
unsigned long V_94 = V_60 , V_95 ;
int * V_96 = V_72 ;
V_95 = F_102 ( V_13 -> V_66 , V_94 + ( V_97 << F_103 ( V_41 ) ) ) ;
F_104 ( V_13 -> V_19 , V_94 , V_95 ) ;
while ( V_75 ( & V_76 ) ) {
unsigned long V_98 , V_99 ;
int V_100 = 0 ;
V_98 = V_60 = V_76 . V_60 ;
if ( V_76 . V_80 ) {
T_7 V_101 ;
T_7 * V_80 = V_76 . V_80 ;
if ( ! F_105 ( * V_80 ) && ! F_106 ( * V_80 ) )
continue;
F_107 ( V_13 , V_60 , F_108 ( * V_80 ) ) ;
V_101 = F_109 ( V_13 , V_60 , V_80 ) ;
V_101 = F_110 ( V_101 ) ;
V_101 = F_111 ( V_101 ) ;
F_112 ( V_13 -> V_19 , V_60 , V_80 , V_101 ) ;
V_99 = V_98 + V_97 ;
V_100 = 1 ;
} else {
#ifdef F_113
T_3 * V_70 = V_76 . V_70 ;
T_3 V_101 ;
if ( ! F_114 ( * V_70 ) && ! F_115 ( * V_70 ) )
continue;
F_107 ( V_13 , V_60 , F_116 ( V_41 ) ) ;
V_101 = F_117 ( V_13 , V_60 , V_70 ) ;
V_101 = F_118 ( V_101 ) ;
V_101 = F_119 ( V_101 ) ;
F_120 ( V_13 -> V_19 , V_60 , V_70 , V_101 ) ;
V_98 &= V_102 ;
V_99 = V_98 + V_103 ;
V_100 = 1 ;
#else
F_25 ( 1 ) ;
#endif
}
if ( V_100 ) {
F_121 ( V_13 -> V_19 , V_98 , V_99 ) ;
( * V_96 ) ++ ;
}
}
F_122 ( V_13 -> V_19 , V_94 , V_95 ) ;
return true ;
}
static bool F_123 ( struct V_12 * V_13 , void * V_72 )
{
if ( V_13 -> V_78 & V_104 )
return false ;
return true ;
}
int F_124 ( struct V_41 * V_41 )
{
int V_96 = 0 ;
struct V_105 * V_43 ;
struct V_88 V_89 = {
. V_72 = ( void * ) & V_96 ,
. V_90 = F_101 ,
. V_92 = F_123 ,
} ;
F_125 ( ! F_126 ( V_41 ) ) ;
if ( ! F_47 ( V_41 ) )
return 0 ;
V_43 = F_127 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
F_99 ( V_41 , & V_89 ) ;
return V_96 ;
}
void F_128 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
V_41 = F_129 ( V_41 ) ;
F_130 ( ! F_126 ( V_41 ) , V_41 ) ;
F_131 ( ! V_1 , V_13 ) ;
V_1 = ( void * ) V_1 + V_45 ;
F_132 ( V_41 -> V_43 , (struct V_105 * ) V_1 ) ;
}
static void F_133 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 , int V_106 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_125 ( ! V_1 ) ;
if ( F_72 ( V_41 ) )
return;
if ( ! V_106 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_105 * ) V_1 ;
V_41 -> V_107 = F_134 ( V_13 , V_60 ) ;
}
static void F_135 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 )
{
#ifdef F_136
F_125 ( F_73 ( V_41 ) -> V_7 != V_13 -> V_1 -> V_7 ) ;
F_125 ( F_137 ( V_41 ) != F_134 ( V_13 , V_60 ) ) ;
#endif
}
void F_138 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 , bool V_108 )
{
F_139 ( V_41 , V_13 , V_60 , V_108 ? V_109 : 0 ) ;
}
void F_139 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 , int V_56 )
{
bool V_108 = V_56 & V_109 ;
bool V_110 ;
if ( V_108 ) {
T_8 * V_83 ;
F_130 ( ! F_126 ( V_41 ) , V_41 ) ;
F_130 ( ! F_140 ( V_41 ) , V_41 ) ;
V_83 = F_141 ( V_41 ) ;
V_110 = F_142 ( V_83 ) ;
} else {
V_110 = F_142 ( & V_41 -> V_111 ) ;
}
if ( V_110 ) {
int V_112 = V_108 ? F_143 ( V_41 ) : 1 ;
if ( V_108 )
F_144 ( V_41 , V_113 ) ;
F_145 ( F_146 ( V_41 ) , V_114 , V_112 ) ;
}
if ( F_19 ( F_97 ( V_41 ) ) )
return;
F_130 ( ! F_126 ( V_41 ) , V_41 ) ;
if ( V_110 )
F_133 ( V_41 , V_13 , V_60 ,
V_56 & V_115 ) ;
else
F_135 ( V_41 , V_13 , V_60 ) ;
}
void F_147 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 , bool V_108 )
{
int V_112 = V_108 ? F_143 ( V_41 ) : 1 ;
F_131 ( V_60 < V_13 -> V_65 || V_60 >= V_13 -> V_66 , V_13 ) ;
F_148 ( V_41 ) ;
if ( V_108 ) {
F_130 ( ! F_140 ( V_41 ) , V_41 ) ;
F_3 ( F_141 ( V_41 ) , 0 ) ;
F_144 ( V_41 , V_113 ) ;
} else {
F_130 ( F_149 ( V_41 ) , V_41 ) ;
F_3 ( & V_41 -> V_111 , 0 ) ;
}
F_145 ( F_146 ( V_41 ) , V_114 , V_112 ) ;
F_133 ( V_41 , V_13 , V_60 , 1 ) ;
}
void F_150 ( struct V_41 * V_41 , bool V_108 )
{
int V_116 , V_112 = 1 ;
F_130 ( V_108 && ! F_140 ( V_41 ) , V_41 ) ;
F_151 ( V_41 ) ;
if ( V_108 && F_140 ( V_41 ) ) {
for ( V_116 = 0 , V_112 = 0 ; V_116 < V_117 ; V_116 ++ ) {
if ( F_142 ( & V_41 [ V_116 ] . V_111 ) )
V_112 ++ ;
}
if ( ! F_142 ( F_141 ( V_41 ) ) )
goto V_46;
F_130 ( ! F_152 ( V_41 ) , V_41 ) ;
F_144 ( V_41 , V_118 ) ;
} else {
if ( F_149 ( V_41 ) && F_127 ( V_41 ) ) {
F_153 ( ! F_126 ( V_41 ) ) ;
F_154 ( F_129 ( V_41 ) ) ;
if ( F_155 ( V_41 ) )
F_156 ( F_129 ( V_41 ) ) ;
}
if ( ! F_142 ( & V_41 -> V_111 ) )
goto V_46;
}
F_157 ( V_41 , V_119 , V_112 ) ;
V_46:
F_158 ( V_41 ) ;
}
static void F_159 ( struct V_41 * V_41 , bool V_108 )
{
int V_116 , V_112 = 1 ;
F_130 ( V_108 && ! F_160 ( V_41 ) , V_41 ) ;
F_151 ( V_41 ) ;
if ( F_19 ( F_161 ( V_41 ) ) ) {
F_162 ( F_141 ( V_41 ) ) ;
goto V_46;
}
if ( V_108 && F_140 ( V_41 ) ) {
for ( V_116 = 0 , V_112 = 0 ; V_116 < V_117 ; V_116 ++ ) {
if ( F_163 ( - 1 , & V_41 [ V_116 ] . V_111 ) )
V_112 ++ ;
}
if ( ! F_163 ( - 1 , F_141 ( V_41 ) ) )
goto V_46;
F_130 ( ! F_152 ( V_41 ) , V_41 ) ;
F_164 ( V_41 , V_118 ) ;
} else {
if ( ! F_163 ( - 1 , & V_41 -> V_111 ) )
goto V_46;
}
F_157 ( V_41 , V_119 , - V_112 ) ;
if ( F_19 ( F_155 ( V_41 ) ) )
F_156 ( V_41 ) ;
V_46:
F_158 ( V_41 ) ;
}
static void F_165 ( struct V_41 * V_41 )
{
int V_116 , V_112 ;
if ( ! F_163 ( - 1 , F_141 ( V_41 ) ) )
return;
if ( F_19 ( F_161 ( V_41 ) ) )
return;
if ( ! F_88 ( V_82 ) )
return;
F_164 ( V_41 , V_113 ) ;
if ( F_166 ( V_41 ) ) {
for ( V_116 = 0 , V_112 = 0 ; V_116 < V_117 ; V_116 ++ ) {
if ( F_163 ( - 1 , & V_41 [ V_116 ] . V_111 ) )
V_112 ++ ;
}
} else {
V_112 = V_117 ;
}
if ( F_19 ( F_155 ( V_41 ) ) )
F_156 ( V_41 ) ;
if ( V_112 ) {
F_145 ( F_146 ( V_41 ) , V_114 , - V_112 ) ;
F_167 ( V_41 ) ;
}
}
void F_168 ( struct V_41 * V_41 , bool V_108 )
{
if ( ! F_72 ( V_41 ) )
return F_159 ( V_41 , V_108 ) ;
if ( V_108 )
return F_165 ( V_41 ) ;
if ( ! F_163 ( - 1 , & V_41 -> V_111 ) )
return;
F_164 ( V_41 , V_114 ) ;
if ( F_19 ( F_155 ( V_41 ) ) )
F_156 ( V_41 ) ;
if ( F_149 ( V_41 ) )
F_167 ( F_129 ( V_41 ) ) ;
}
static bool F_169 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_60 , void * V_72 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_75 V_76 = {
. V_41 = V_41 ,
. V_13 = V_13 ,
. V_60 = V_60 ,
} ;
T_7 V_120 ;
struct V_41 * V_121 ;
bool V_100 = true ;
unsigned long V_94 = V_60 , V_95 ;
enum V_55 V_56 = (enum V_55 ) V_72 ;
if ( ( V_56 & V_122 ) && ! ( V_13 -> V_78 & V_79 ) )
return true ;
if ( V_56 & V_123 ) {
F_170 ( V_13 , V_60 ,
V_56 & V_124 , V_41 ) ;
}
V_95 = F_102 ( V_13 -> V_66 , V_94 + ( V_97 << F_103 ( V_41 ) ) ) ;
F_104 ( V_13 -> V_19 , V_94 , V_95 ) ;
while ( V_75 ( & V_76 ) ) {
if ( ! ( V_56 & V_125 ) ) {
if ( V_13 -> V_78 & V_79 ) {
if ( ! F_149 ( V_41 ) ) {
F_171 ( V_41 ) ;
}
V_100 = false ;
F_86 ( & V_76 ) ;
break;
}
if ( V_56 & V_122 )
continue;
}
F_130 ( ! V_76 . V_80 , V_41 ) ;
V_121 = V_41 - F_116 ( V_41 ) + F_108 ( * V_76 . V_80 ) ;
V_60 = V_76 . V_60 ;
if ( ! ( V_56 & V_126 ) ) {
if ( F_87 ( V_13 , V_60 ,
V_76 . V_80 ) ) {
V_100 = false ;
F_86 ( & V_76 ) ;
break;
}
}
F_107 ( V_13 , V_60 , F_108 ( * V_76 . V_80 ) ) ;
if ( F_64 ( V_18 , V_56 ) ) {
V_120 = F_172 ( V_18 , V_60 , V_76 . V_80 ) ;
F_61 ( V_18 , F_105 ( V_120 ) ) ;
} else {
V_120 = F_109 ( V_13 , V_60 , V_76 . V_80 ) ;
}
if ( F_105 ( V_120 ) )
F_173 ( V_41 ) ;
F_174 ( V_18 ) ;
if ( F_175 ( V_41 ) && ! ( V_56 & V_127 ) ) {
V_120 = F_176 ( F_177 ( V_121 ) ) ;
if ( F_161 ( V_41 ) ) {
int V_112 = 1 << F_103 ( V_41 ) ;
F_178 ( V_112 , V_18 ) ;
F_179 ( V_18 , V_60 ,
V_76 . V_80 , V_120 ,
F_180 ( V_13 ) ) ;
} else {
F_181 ( V_18 , F_182 ( V_41 ) ) ;
F_112 ( V_18 , V_60 , V_76 . V_80 , V_120 ) ;
}
} else if ( F_183 ( V_120 ) ) {
F_181 ( V_18 , F_182 ( V_41 ) ) ;
} else if ( F_88 ( V_128 ) &&
( V_56 & V_124 ) ) {
T_9 V_101 ;
T_7 V_129 ;
V_101 = F_184 ( V_121 ,
F_106 ( V_120 ) ) ;
V_129 = F_176 ( V_101 ) ;
if ( F_185 ( V_120 ) )
V_129 = F_186 ( V_129 ) ;
F_112 ( V_18 , V_60 , V_76 . V_80 , V_129 ) ;
} else if ( F_72 ( V_41 ) ) {
T_9 V_101 = { . V_130 = F_187 (subpage) } ;
T_7 V_129 ;
if ( F_19 ( F_152 ( V_41 ) != F_188 ( V_41 ) ) ) {
F_25 ( 1 ) ;
V_100 = false ;
F_86 ( & V_76 ) ;
break;
}
if ( ! F_152 ( V_41 ) ) {
if ( ! F_189 ( V_41 ) ) {
F_181 ( V_18 , V_131 ) ;
goto V_132;
}
F_112 ( V_18 , V_60 , V_76 . V_80 , V_120 ) ;
F_190 ( V_41 ) ;
V_100 = false ;
F_86 ( & V_76 ) ;
break;
}
if ( F_191 ( V_101 ) < 0 ) {
F_112 ( V_18 , V_60 , V_76 . V_80 , V_120 ) ;
V_100 = false ;
F_86 ( & V_76 ) ;
break;
}
if ( F_192 ( & V_18 -> V_133 ) ) {
F_20 ( & V_134 ) ;
if ( F_192 ( & V_18 -> V_133 ) )
F_15 ( & V_18 -> V_133 , & V_135 . V_133 ) ;
F_22 ( & V_134 ) ;
}
F_181 ( V_18 , V_131 ) ;
F_193 ( V_18 , V_136 ) ;
V_129 = F_176 ( V_101 ) ;
if ( F_185 ( V_120 ) )
V_129 = F_186 ( V_129 ) ;
F_112 ( V_18 , V_60 , V_76 . V_80 , V_129 ) ;
} else
F_181 ( V_18 , F_194 ( V_41 ) ) ;
V_132:
F_168 ( V_121 , F_161 ( V_41 ) ) ;
F_195 ( V_41 ) ;
F_121 ( V_18 , V_60 ,
V_60 + V_97 ) ;
}
F_122 ( V_13 -> V_19 , V_94 , V_95 ) ;
return V_100 ;
}
bool F_196 ( struct V_12 * V_13 )
{
int V_137 = V_13 -> V_78 & ( V_138 | V_139 ) ;
if ( ! V_137 )
return false ;
if ( ( V_13 -> V_78 & V_140 ) ==
V_140 )
return true ;
return false ;
}
static bool F_197 ( struct V_12 * V_13 , void * V_72 )
{
return F_196 ( V_13 ) ;
}
static int F_198 ( struct V_41 * V_41 )
{
return ! F_95 ( V_41 ) ;
}
bool F_199 ( struct V_41 * V_41 , enum V_55 V_56 )
{
struct V_88 V_89 = {
. V_90 = F_169 ,
. V_72 = ( void * ) V_56 ,
. V_141 = F_198 ,
. V_91 = F_50 ,
} ;
if ( ( V_56 & V_124 ) && ! F_97 ( V_41 ) && F_72 ( V_41 ) )
V_89 . V_92 = F_197 ;
if ( V_56 & V_142 )
F_200 ( V_41 , & V_89 ) ;
else
F_99 ( V_41 , & V_89 ) ;
return ! F_201 ( V_41 ) ? true : false ;
}
static int F_202 ( struct V_41 * V_41 )
{
return ! F_47 ( V_41 ) ;
}
void F_203 ( struct V_41 * V_41 )
{
struct V_88 V_89 = {
. V_90 = F_169 ,
. V_72 = ( void * ) V_122 ,
. V_141 = F_202 ,
. V_91 = F_50 ,
} ;
F_130 ( ! F_126 ( V_41 ) || F_204 ( V_41 ) , V_41 ) ;
F_130 ( F_205 ( V_41 ) && F_206 ( V_41 ) , V_41 ) ;
F_99 ( V_41 , & V_89 ) ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_1 * V_7 = V_1 -> V_7 ;
F_4 ( V_1 ) ;
if ( V_7 != V_1 && F_54 ( & V_7 -> V_4 ) )
F_4 ( V_7 ) ;
}
static struct V_1 * F_207 ( struct V_41 * V_41 ,
struct V_88 * V_89 )
{
struct V_1 * V_1 ;
if ( V_89 -> V_91 )
return V_89 -> V_91 ( V_41 ) ;
V_1 = F_73 ( V_41 ) ;
if ( ! V_1 )
return NULL ;
F_53 ( V_1 ) ;
return V_1 ;
}
static void F_208 ( struct V_41 * V_41 , struct V_88 * V_89 ,
bool V_143 )
{
struct V_1 * V_1 ;
T_10 V_144 , V_145 ;
struct V_9 * V_14 ;
if ( V_143 ) {
V_1 = F_73 ( V_41 ) ;
F_130 ( ! V_1 , V_41 ) ;
} else {
V_1 = F_207 ( V_41 , V_89 ) ;
}
if ( ! V_1 )
return;
V_144 = F_137 ( V_41 ) ;
V_145 = V_144 + F_143 ( V_41 ) - 1 ;
F_209 (avc, &anon_vma->rb_root,
pgoff_start, pgoff_end) {
struct V_12 * V_13 = V_14 -> V_13 ;
unsigned long V_60 = F_210 ( V_41 , V_13 ) ;
F_211 () ;
if ( V_89 -> V_92 && V_89 -> V_92 ( V_13 , V_89 -> V_72 ) )
continue;
if ( ! V_89 -> V_90 ( V_41 , V_13 , V_60 , V_89 -> V_72 ) )
break;
if ( V_89 -> V_141 && V_89 -> V_141 ( V_41 ) )
break;
}
if ( ! V_143 )
F_55 ( V_1 ) ;
}
static void F_212 ( struct V_41 * V_41 , struct V_88 * V_89 ,
bool V_143 )
{
struct V_105 * V_43 = F_127 ( V_41 ) ;
T_10 V_144 , V_145 ;
struct V_12 * V_13 ;
F_130 ( ! F_126 ( V_41 ) , V_41 ) ;
if ( ! V_43 )
return;
V_144 = F_137 ( V_41 ) ;
V_145 = V_144 + F_143 ( V_41 ) - 1 ;
if ( ! V_143 )
F_213 ( V_43 ) ;
F_214 (vma, &mapping->i_mmap,
pgoff_start, pgoff_end) {
unsigned long V_60 = F_210 ( V_41 , V_13 ) ;
F_211 () ;
if ( V_89 -> V_92 && V_89 -> V_92 ( V_13 , V_89 -> V_72 ) )
continue;
if ( ! V_89 -> V_90 ( V_41 , V_13 , V_60 , V_89 -> V_72 ) )
goto V_141;
if ( V_89 -> V_141 && V_89 -> V_141 ( V_41 ) )
goto V_141;
}
V_141:
if ( ! V_143 )
F_215 ( V_43 ) ;
}
void F_99 ( struct V_41 * V_41 , struct V_88 * V_89 )
{
if ( F_19 ( F_97 ( V_41 ) ) )
F_216 ( V_41 , V_89 ) ;
else if ( F_72 ( V_41 ) )
F_208 ( V_41 , V_89 , false ) ;
else
F_212 ( V_41 , V_89 , false ) ;
}
void F_200 ( struct V_41 * V_41 , struct V_88 * V_89 )
{
F_130 ( F_97 ( V_41 ) , V_41 ) ;
if ( F_72 ( V_41 ) )
F_208 ( V_41 , V_89 , true ) ;
else
F_212 ( V_41 , V_89 , true ) ;
}
static void F_217 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 , int V_106 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_125 ( ! V_1 ) ;
if ( F_72 ( V_41 ) )
return;
if ( ! V_106 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_105 * ) V_1 ;
V_41 -> V_107 = F_134 ( V_13 , V_60 ) ;
}
void F_218 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
int V_110 ;
F_125 ( ! F_126 ( V_41 ) ) ;
F_125 ( ! V_1 ) ;
V_110 = F_142 ( F_141 ( V_41 ) ) ;
if ( V_110 )
F_217 ( V_41 , V_13 , V_60 , 0 ) ;
}
void F_219 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_60 )
{
F_125 ( V_60 < V_13 -> V_65 || V_60 >= V_13 -> V_66 ) ;
F_3 ( F_141 ( V_41 ) , 0 ) ;
F_217 ( V_41 , V_13 , V_60 , 1 ) ;
}
