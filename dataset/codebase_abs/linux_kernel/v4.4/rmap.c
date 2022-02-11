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
struct V_1 * V_1 = V_13 -> V_1 ;
struct V_9 * V_14 ;
F_7 () ;
if ( F_18 ( ! V_1 ) ) {
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_1 * V_20 ;
V_14 = F_12 ( V_3 ) ;
if ( ! V_14 )
goto V_21;
V_1 = F_19 ( V_13 ) ;
V_20 = NULL ;
if ( ! V_1 ) {
V_1 = F_1 () ;
if ( F_18 ( ! V_1 ) )
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
if ( F_18 ( V_20 ) )
F_23 ( V_20 ) ;
if ( F_18 ( V_14 ) )
F_13 ( V_14 ) ;
}
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
if ( F_18 ( ! V_14 ) ) {
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
0 , V_38 | V_39 , F_39 ) ;
V_11 = F_43 ( V_9 , V_39 ) ;
}
struct V_1 * F_44 ( struct V_40 * V_40 )
{
struct V_1 * V_1 = NULL ;
unsigned long V_41 ;
F_45 () ;
V_41 = ( unsigned long ) F_46 ( V_40 -> V_42 ) ;
if ( ( V_41 & V_43 ) != V_44 )
goto V_45;
if ( ! F_47 ( V_40 ) )
goto V_45;
V_1 = (struct V_1 * ) ( V_41 - V_44 ) ;
if ( ! F_48 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_45;
}
if ( ! F_47 ( V_40 ) ) {
F_49 () ;
F_23 ( V_1 ) ;
return NULL ;
}
V_45:
F_49 () ;
return V_1 ;
}
struct V_1 * F_50 ( struct V_40 * V_40 )
{
struct V_1 * V_1 = NULL ;
struct V_1 * V_46 ;
unsigned long V_41 ;
F_45 () ;
V_41 = ( unsigned long ) F_46 ( V_40 -> V_42 ) ;
if ( ( V_41 & V_43 ) != V_44 )
goto V_45;
if ( ! F_47 ( V_40 ) )
goto V_45;
V_1 = (struct V_1 * ) ( V_41 - V_44 ) ;
V_46 = F_46 ( V_1 -> V_7 ) ;
if ( F_51 ( & V_46 -> V_8 ) ) {
if ( ! F_47 ( V_40 ) ) {
F_52 ( & V_46 -> V_8 ) ;
V_1 = NULL ;
}
goto V_45;
}
if ( ! F_48 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_45;
}
if ( ! F_47 ( V_40 ) ) {
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
V_45:
F_49 () ;
return V_1 ;
}
void F_57 ( struct V_1 * V_1 )
{
F_55 ( V_1 ) ;
}
static inline unsigned long
F_58 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
T_3 V_47 = F_59 ( V_40 ) ;
return V_13 -> V_48 + ( ( V_47 - V_13 -> V_49 ) << V_50 ) ;
}
inline unsigned long
F_60 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
unsigned long V_51 = F_58 ( V_40 , V_13 ) ;
F_61 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 , V_13 ) ;
return V_51 ;
}
static void F_62 ( void * V_36 )
{
F_63 ( V_53 ) ;
F_64 () ;
}
void F_65 ( void )
{
struct V_54 * V_55 = & V_56 -> V_55 ;
int V_57 ;
if ( ! V_55 -> V_58 )
return;
V_57 = F_66 () ;
F_67 ( V_59 , - 1UL ) ;
if ( F_68 ( V_57 , & V_55 -> V_60 ) )
F_62 ( & V_55 -> V_60 ) ;
if ( F_69 ( & V_55 -> V_60 , V_57 ) < V_61 ) {
F_70 ( & V_55 -> V_60 ,
F_62 , ( void * ) V_55 , true ) ;
}
F_71 ( & V_55 -> V_60 ) ;
V_55 -> V_58 = false ;
V_55 -> V_62 = false ;
F_72 () ;
}
void F_73 ( void )
{
struct V_54 * V_55 = & V_56 -> V_55 ;
if ( V_55 -> V_62 )
F_65 () ;
}
static void F_74 ( struct V_17 * V_18 ,
struct V_40 * V_40 , bool V_62 )
{
struct V_54 * V_55 = & V_56 -> V_55 ;
F_75 ( & V_55 -> V_60 , & V_55 -> V_60 , F_76 ( V_18 ) ) ;
V_55 -> V_58 = true ;
if ( V_62 )
V_55 -> V_62 = true ;
}
static bool F_77 ( struct V_17 * V_18 , enum V_63 V_64 )
{
bool V_65 = false ;
if ( ! ( V_64 & V_66 ) )
return false ;
if ( F_69 ( F_76 ( V_18 ) , F_66 () ) < V_61 )
V_65 = true ;
F_72 () ;
return V_65 ;
}
static void F_74 ( struct V_17 * V_18 ,
struct V_40 * V_40 , bool V_62 )
{
}
static bool F_77 ( struct V_17 * V_18 , enum V_63 V_64 )
{
return false ;
}
unsigned long F_78 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
unsigned long V_51 ;
if ( F_79 ( V_40 ) ) {
struct V_1 * V_67 = F_80 ( V_40 ) ;
if ( ! V_13 -> V_1 || ! V_67 ||
V_13 -> V_1 -> V_7 != V_67 -> V_7 )
return - V_68 ;
} else if ( V_40 -> V_42 ) {
if ( ! V_13 -> V_69 || V_13 -> V_69 -> V_70 != V_40 -> V_42 )
return - V_68 ;
} else
return - V_68 ;
V_51 = F_58 ( V_40 , V_13 ) ;
if ( F_18 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) )
return - V_68 ;
return V_51 ;
}
T_4 * F_81 ( struct V_17 * V_18 , unsigned long V_51 )
{
T_5 * V_71 ;
T_6 * V_72 ;
T_4 * V_73 = NULL ;
T_4 V_74 ;
V_71 = F_82 ( V_18 , V_51 ) ;
if ( ! F_83 ( * V_71 ) )
goto V_45;
V_72 = F_84 ( V_71 , V_51 ) ;
if ( ! F_85 ( * V_72 ) )
goto V_45;
V_73 = F_86 ( V_72 , V_51 ) ;
V_74 = * V_73 ;
F_87 () ;
if ( ! F_88 ( V_74 ) || F_89 ( V_74 ) )
V_73 = NULL ;
V_45:
return V_73 ;
}
T_7 * F_90 ( struct V_40 * V_40 , struct V_17 * V_18 ,
unsigned long V_51 , T_8 * * V_75 , int V_76 )
{
T_4 * V_73 ;
T_7 * V_77 ;
T_8 * V_78 ;
if ( F_18 ( F_91 ( V_40 ) ) ) {
V_77 = F_92 ( V_18 , V_51 ) ;
if ( ! V_77 )
return NULL ;
V_78 = F_93 ( F_94 ( V_40 ) , V_18 , V_77 ) ;
goto V_79;
}
V_73 = F_81 ( V_18 , V_51 ) ;
if ( ! V_73 )
return NULL ;
V_77 = F_95 ( V_73 , V_51 ) ;
if ( ! V_76 && ! F_96 ( * V_77 ) ) {
F_97 ( V_77 ) ;
return NULL ;
}
V_78 = F_98 ( V_18 , V_73 ) ;
V_79:
F_20 ( V_78 ) ;
if ( F_96 ( * V_77 ) && F_99 ( V_40 ) == F_100 ( * V_77 ) ) {
* V_75 = V_78 ;
return V_77 ;
}
F_101 ( V_77 , V_78 ) ;
return NULL ;
}
int F_102 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
unsigned long V_51 ;
T_7 * V_77 ;
T_8 * V_78 ;
V_51 = F_58 ( V_40 , V_13 ) ;
if ( F_18 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) )
return 0 ;
V_77 = F_103 ( V_40 , V_13 -> V_19 , V_51 , & V_78 , 1 ) ;
if ( ! V_77 )
return 0 ;
F_101 ( V_77 , V_78 ) ;
return 1 ;
}
static int F_104 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_80 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_8 * V_78 ;
int V_81 = 0 ;
struct V_82 * V_83 = V_80 ;
if ( F_18 ( F_105 ( V_40 ) ) ) {
T_4 * V_73 ;
V_73 = F_106 ( V_40 , V_18 , V_51 ,
V_84 , & V_78 ) ;
if ( ! V_73 )
return V_85 ;
if ( V_13 -> V_86 & V_87 ) {
F_22 ( V_78 ) ;
V_83 -> V_86 |= V_87 ;
return V_88 ;
}
if ( F_107 ( V_13 , V_51 , V_73 ) )
V_81 ++ ;
F_22 ( V_78 ) ;
} else {
T_7 * V_77 ;
V_77 = F_103 ( V_40 , V_18 , V_51 , & V_78 , 0 ) ;
if ( ! V_77 )
return V_85 ;
if ( V_13 -> V_86 & V_87 ) {
F_101 ( V_77 , V_78 ) ;
V_83 -> V_86 |= V_87 ;
return V_88 ;
}
if ( F_108 ( V_13 , V_51 , V_77 ) ) {
if ( F_21 ( ! ( V_13 -> V_86 & V_89 ) ) )
V_81 ++ ;
}
F_101 ( V_77 , V_78 ) ;
}
if ( V_81 )
F_109 ( V_40 ) ;
if ( F_110 ( V_40 ) )
V_81 ++ ;
if ( V_81 ) {
V_83 -> V_81 ++ ;
V_83 -> V_86 |= V_13 -> V_86 ;
}
V_83 -> V_90 -- ;
if ( ! V_83 -> V_90 )
return V_91 ;
return V_85 ;
}
static bool F_111 ( struct V_12 * V_13 , void * V_80 )
{
struct V_82 * V_83 = V_80 ;
struct V_92 * V_93 = V_83 -> V_93 ;
if ( ! F_112 ( V_13 -> V_19 , V_93 ) )
return true ;
return false ;
}
int F_113 ( struct V_40 * V_40 ,
int V_94 ,
struct V_92 * V_93 ,
unsigned long * V_86 )
{
int V_95 ;
int V_96 = 0 ;
struct V_82 V_83 = {
. V_90 = F_114 ( V_40 ) ,
. V_93 = V_93 ,
} ;
struct V_97 V_98 = {
. V_99 = F_104 ,
. V_80 = ( void * ) & V_83 ,
. V_100 = F_50 ,
} ;
* V_86 = 0 ;
if ( ! F_47 ( V_40 ) )
return 0 ;
if ( ! F_115 ( V_40 ) )
return 0 ;
if ( ! V_94 && ( ! F_79 ( V_40 ) || F_116 ( V_40 ) ) ) {
V_96 = F_117 ( V_40 ) ;
if ( ! V_96 )
return 1 ;
}
if ( V_93 ) {
V_98 . V_101 = F_111 ;
}
V_95 = F_118 ( V_40 , & V_98 ) ;
* V_86 = V_83 . V_86 ;
if ( V_96 )
F_119 ( V_40 ) ;
return V_83 . V_81 ;
}
static int F_120 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_80 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_7 * V_77 ;
T_8 * V_78 ;
int V_95 = 0 ;
int * V_102 = V_80 ;
V_77 = F_103 ( V_40 , V_18 , V_51 , & V_78 , 1 ) ;
if ( ! V_77 )
goto V_45;
if ( F_121 ( * V_77 ) || F_122 ( * V_77 ) ) {
T_7 V_103 ;
F_123 ( V_13 , V_51 , F_100 ( * V_77 ) ) ;
V_103 = F_124 ( V_13 , V_51 , V_77 ) ;
V_103 = F_125 ( V_103 ) ;
V_103 = F_126 ( V_103 ) ;
F_127 ( V_18 , V_51 , V_77 , V_103 ) ;
V_95 = 1 ;
}
F_101 ( V_77 , V_78 ) ;
if ( V_95 ) {
F_128 ( V_18 , V_51 ) ;
( * V_102 ) ++ ;
}
V_45:
return V_85 ;
}
static bool F_129 ( struct V_12 * V_13 , void * V_80 )
{
if ( V_13 -> V_86 & V_104 )
return false ;
return true ;
}
int F_130 ( struct V_40 * V_40 )
{
int V_102 = 0 ;
struct V_105 * V_42 ;
struct V_97 V_98 = {
. V_80 = ( void * ) & V_102 ,
. V_99 = F_120 ,
. V_101 = F_129 ,
} ;
F_38 ( ! F_131 ( V_40 ) ) ;
if ( ! F_47 ( V_40 ) )
return 0 ;
V_42 = F_132 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
F_118 ( V_40 , & V_98 ) ;
return V_102 ;
}
void F_133 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_134 ( ! F_131 ( V_40 ) , V_40 ) ;
F_61 ( ! V_1 , V_13 ) ;
F_134 ( V_40 -> V_106 != F_135 ( V_13 , V_51 ) , V_40 ) ;
V_1 = ( void * ) V_1 + V_44 ;
F_136 ( V_40 -> V_42 , (struct V_105 * ) V_1 ) ;
}
static void F_137 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_107 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_79 ( V_40 ) )
return;
if ( ! V_107 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_105 * ) V_1 ;
V_40 -> V_106 = F_135 ( V_13 , V_51 ) ;
}
static void F_138 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
#ifdef F_139
F_38 ( F_80 ( V_40 ) -> V_7 != V_13 -> V_1 -> V_7 ) ;
F_38 ( V_40 -> V_106 != F_135 ( V_13 , V_51 ) ) ;
#endif
}
void F_140 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_141 ( V_40 , V_13 , V_51 , 0 ) ;
}
void F_141 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_107 )
{
int V_108 = F_142 ( & V_40 -> V_109 ) ;
if ( V_108 ) {
if ( F_105 ( V_40 ) )
F_143 ( V_40 ,
V_110 ) ;
F_144 ( F_145 ( V_40 ) , V_111 ,
F_146 ( V_40 ) ) ;
}
if ( F_18 ( F_116 ( V_40 ) ) )
return;
F_134 ( ! F_131 ( V_40 ) , V_40 ) ;
if ( V_108 )
F_137 ( V_40 , V_13 , V_51 , V_107 ) ;
else
F_138 ( V_40 , V_13 , V_51 ) ;
}
void F_147 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_61 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 , V_13 ) ;
F_148 ( V_40 ) ;
F_3 ( & V_40 -> V_109 , 0 ) ;
if ( F_105 ( V_40 ) )
F_143 ( V_40 , V_110 ) ;
F_144 ( F_145 ( V_40 ) , V_111 ,
F_146 ( V_40 ) ) ;
F_137 ( V_40 , V_13 , V_51 , 1 ) ;
}
void F_149 ( struct V_40 * V_40 )
{
struct V_92 * V_93 ;
V_93 = F_150 ( V_40 ) ;
if ( F_142 ( & V_40 -> V_109 ) ) {
F_143 ( V_40 , V_112 ) ;
F_151 ( V_93 , V_113 ) ;
}
F_152 ( V_93 ) ;
}
static void F_153 ( struct V_40 * V_40 )
{
struct V_92 * V_93 ;
V_93 = F_150 ( V_40 ) ;
if ( ! F_154 ( - 1 , & V_40 -> V_109 ) )
goto V_45;
if ( F_18 ( F_91 ( V_40 ) ) )
goto V_45;
F_155 ( V_40 , V_112 ) ;
F_156 ( V_93 , V_113 ) ;
if ( F_18 ( F_157 ( V_40 ) ) )
F_158 ( V_40 ) ;
V_45:
F_152 ( V_93 ) ;
}
void F_159 ( struct V_40 * V_40 )
{
if ( ! F_79 ( V_40 ) ) {
F_153 ( V_40 ) ;
return;
}
if ( ! F_154 ( - 1 , & V_40 -> V_109 ) )
return;
if ( F_18 ( F_91 ( V_40 ) ) )
return;
if ( F_105 ( V_40 ) )
F_155 ( V_40 , V_110 ) ;
F_144 ( F_145 ( V_40 ) , V_111 ,
- F_146 ( V_40 ) ) ;
if ( F_18 ( F_157 ( V_40 ) ) )
F_158 ( V_40 ) ;
}
static int F_160 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_80 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_7 * V_77 ;
T_7 V_114 ;
T_8 * V_78 ;
int V_95 = V_85 ;
enum V_63 V_64 = (enum V_63 ) V_80 ;
if ( ( V_64 & V_115 ) && ! ( V_13 -> V_86 & V_87 ) )
goto V_45;
V_77 = F_103 ( V_40 , V_18 , V_51 , & V_78 , 0 ) ;
if ( ! V_77 )
goto V_45;
if ( ! ( V_64 & V_116 ) ) {
if ( V_13 -> V_86 & V_87 ) {
F_161 ( V_40 ) ;
V_95 = V_117 ;
goto V_118;
}
if ( V_64 & V_115 )
goto V_118;
}
if ( ! ( V_64 & V_119 ) ) {
if ( F_108 ( V_13 , V_51 , V_77 ) ) {
V_95 = V_88 ;
goto V_118;
}
}
F_123 ( V_13 , V_51 , F_99 ( V_40 ) ) ;
if ( F_77 ( V_18 , V_64 ) ) {
V_114 = F_162 ( V_18 , V_51 , V_77 ) ;
F_74 ( V_18 , V_40 , F_121 ( V_114 ) ) ;
} else {
V_114 = F_124 ( V_13 , V_51 , V_77 ) ;
}
if ( F_121 ( V_114 ) )
F_163 ( V_40 ) ;
F_164 ( V_18 ) ;
if ( F_165 ( V_40 ) && ! ( V_64 & V_120 ) ) {
if ( F_91 ( V_40 ) ) {
F_166 ( 1 << F_167 ( V_40 ) , V_18 ) ;
} else {
if ( F_79 ( V_40 ) )
F_168 ( V_18 , V_121 ) ;
else
F_168 ( V_18 , V_122 ) ;
}
F_127 ( V_18 , V_51 , V_77 ,
F_169 ( F_170 ( V_40 ) ) ) ;
} else if ( F_171 ( V_114 ) ) {
if ( F_79 ( V_40 ) )
F_168 ( V_18 , V_121 ) ;
else
F_168 ( V_18 , V_122 ) ;
} else if ( F_172 ( V_123 ) && ( V_64 & V_124 ) ) {
T_9 V_103 ;
T_7 V_125 ;
V_103 = F_173 ( V_40 , F_122 ( V_114 ) ) ;
V_125 = F_169 ( V_103 ) ;
if ( F_174 ( V_114 ) )
V_125 = F_175 ( V_125 ) ;
F_127 ( V_18 , V_51 , V_77 , V_125 ) ;
} else if ( F_79 ( V_40 ) ) {
T_9 V_103 = { . V_126 = F_176 (page) } ;
T_7 V_125 ;
F_134 ( ! F_177 ( V_40 ) , V_40 ) ;
if ( F_178 ( V_103 ) < 0 ) {
F_127 ( V_18 , V_51 , V_77 , V_114 ) ;
V_95 = V_88 ;
goto V_118;
}
if ( F_179 ( & V_18 -> V_127 ) ) {
F_20 ( & V_128 ) ;
if ( F_179 ( & V_18 -> V_127 ) )
F_15 ( & V_18 -> V_127 , & V_129 . V_127 ) ;
F_22 ( & V_128 ) ;
}
F_168 ( V_18 , V_121 ) ;
F_180 ( V_18 , V_130 ) ;
V_125 = F_169 ( V_103 ) ;
if ( F_174 ( V_114 ) )
V_125 = F_175 ( V_125 ) ;
F_127 ( V_18 , V_51 , V_77 , V_125 ) ;
} else
F_168 ( V_18 , V_122 ) ;
F_159 ( V_40 ) ;
F_181 ( V_40 ) ;
V_118:
F_101 ( V_77 , V_78 ) ;
if ( V_95 != V_88 && V_95 != V_117 && ! ( V_64 & V_115 ) )
F_128 ( V_18 , V_51 ) ;
V_45:
return V_95 ;
}
bool F_182 ( struct V_12 * V_13 )
{
int V_131 = V_13 -> V_86 & ( V_132 | V_133 ) ;
if ( ! V_131 )
return false ;
if ( ( V_13 -> V_86 & V_134 ) ==
V_134 )
return true ;
return false ;
}
static bool F_183 ( struct V_12 * V_13 , void * V_80 )
{
return F_182 ( V_13 ) ;
}
static int F_184 ( struct V_40 * V_40 )
{
return ! F_47 ( V_40 ) ;
}
int F_185 ( struct V_40 * V_40 , enum V_63 V_64 )
{
int V_95 ;
struct V_97 V_98 = {
. V_99 = F_160 ,
. V_80 = ( void * ) V_64 ,
. V_135 = F_184 ,
. V_100 = F_50 ,
} ;
F_134 ( ! F_91 ( V_40 ) && F_105 ( V_40 ) , V_40 ) ;
if ( ( V_64 & V_124 ) && ! F_116 ( V_40 ) && F_79 ( V_40 ) )
V_98 . V_101 = F_183 ;
V_95 = F_118 ( V_40 , & V_98 ) ;
if ( V_95 != V_117 && ! F_47 ( V_40 ) )
V_95 = V_91 ;
return V_95 ;
}
int F_186 ( struct V_40 * V_40 )
{
int V_95 ;
struct V_97 V_98 = {
. V_99 = F_160 ,
. V_80 = ( void * ) V_115 ,
. V_135 = F_184 ,
. V_100 = F_50 ,
} ;
F_134 ( ! F_131 ( V_40 ) || F_187 ( V_40 ) , V_40 ) ;
V_95 = F_118 ( V_40 , & V_98 ) ;
return V_95 ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_1 * V_7 = V_1 -> V_7 ;
F_4 ( V_1 ) ;
if ( V_7 != V_1 && F_54 ( & V_7 -> V_4 ) )
F_4 ( V_7 ) ;
}
static struct V_1 * F_188 ( struct V_40 * V_40 ,
struct V_97 * V_98 )
{
struct V_1 * V_1 ;
if ( V_98 -> V_100 )
return V_98 -> V_100 ( V_40 ) ;
V_1 = F_80 ( V_40 ) ;
if ( ! V_1 )
return NULL ;
F_53 ( V_1 ) ;
return V_1 ;
}
static int F_189 ( struct V_40 * V_40 , struct V_97 * V_98 )
{
struct V_1 * V_1 ;
T_3 V_47 ;
struct V_9 * V_14 ;
int V_95 = V_85 ;
V_1 = F_188 ( V_40 , V_98 ) ;
if ( ! V_1 )
return V_95 ;
V_47 = F_59 ( V_40 ) ;
F_190 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_12 * V_13 = V_14 -> V_13 ;
unsigned long V_51 = F_60 ( V_40 , V_13 ) ;
F_191 () ;
if ( V_98 -> V_101 && V_98 -> V_101 ( V_13 , V_98 -> V_80 ) )
continue;
V_95 = V_98 -> V_99 ( V_40 , V_13 , V_51 , V_98 -> V_80 ) ;
if ( V_95 != V_85 )
break;
if ( V_98 -> V_135 && V_98 -> V_135 ( V_40 ) )
break;
}
F_55 ( V_1 ) ;
return V_95 ;
}
static int F_192 ( struct V_40 * V_40 , struct V_97 * V_98 )
{
struct V_105 * V_42 = V_40 -> V_42 ;
T_3 V_47 ;
struct V_12 * V_13 ;
int V_95 = V_85 ;
F_134 ( ! F_131 ( V_40 ) , V_40 ) ;
if ( ! V_42 )
return V_95 ;
V_47 = F_59 ( V_40 ) ;
F_193 ( V_42 ) ;
F_194 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_60 ( V_40 , V_13 ) ;
F_191 () ;
if ( V_98 -> V_101 && V_98 -> V_101 ( V_13 , V_98 -> V_80 ) )
continue;
V_95 = V_98 -> V_99 ( V_40 , V_13 , V_51 , V_98 -> V_80 ) ;
if ( V_95 != V_85 )
goto V_135;
if ( V_98 -> V_135 && V_98 -> V_135 ( V_40 ) )
goto V_135;
}
V_135:
F_195 ( V_42 ) ;
return V_95 ;
}
int F_118 ( struct V_40 * V_40 , struct V_97 * V_98 )
{
if ( F_18 ( F_116 ( V_40 ) ) )
return F_196 ( V_40 , V_98 ) ;
else if ( F_79 ( V_40 ) )
return F_189 ( V_40 , V_98 ) ;
else
return F_192 ( V_40 , V_98 ) ;
}
static void F_197 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_107 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_79 ( V_40 ) )
return;
if ( ! V_107 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_105 * ) V_1 ;
V_40 -> V_106 = F_135 ( V_13 , V_51 ) ;
}
void F_198 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
int V_108 ;
F_38 ( ! F_131 ( V_40 ) ) ;
F_38 ( ! V_1 ) ;
V_108 = F_142 ( & V_40 -> V_109 ) ;
if ( V_108 )
F_197 ( V_40 , V_13 , V_51 , 0 ) ;
}
void F_199 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_38 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) ;
F_3 ( & V_40 -> V_109 , 0 ) ;
F_197 ( V_40 , V_13 , V_51 , 1 ) ;
}
