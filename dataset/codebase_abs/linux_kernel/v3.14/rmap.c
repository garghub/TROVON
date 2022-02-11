static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , V_3 ) ;
if ( V_1 ) {
F_3 ( & V_1 -> V_4 , 1 ) ;
V_1 -> V_5 = V_1 ;
}
return V_1 ;
}
static inline void F_4 ( struct V_1 * V_1 )
{
F_5 ( F_6 ( & V_1 -> V_4 ) ) ;
if ( F_7 ( & V_1 -> V_5 -> V_6 ) ) {
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
}
F_10 ( V_2 , V_1 ) ;
}
static inline struct V_7 * F_11 ( T_1 V_8 )
{
return F_2 ( V_9 , V_8 ) ;
}
static void F_12 ( struct V_7 * V_7 )
{
F_10 ( V_9 , V_7 ) ;
}
static void F_13 ( struct V_10 * V_11 ,
struct V_7 * V_12 ,
struct V_1 * V_1 )
{
V_12 -> V_11 = V_11 ;
V_12 -> V_1 = V_1 ;
F_14 ( & V_12 -> V_13 , & V_11 -> V_7 ) ;
F_15 ( V_12 , & V_1 -> V_14 ) ;
}
int F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
struct V_7 * V_12 ;
F_17 () ;
if ( F_18 ( ! V_1 ) ) {
struct V_15 * V_16 = V_11 -> V_17 ;
struct V_1 * V_18 ;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_19;
V_1 = F_19 ( V_11 ) ;
V_18 = NULL ;
if ( ! V_1 ) {
V_1 = F_1 () ;
if ( F_18 ( ! V_1 ) )
goto V_20;
V_18 = V_1 ;
}
F_8 ( V_1 ) ;
F_20 ( & V_16 -> V_21 ) ;
if ( F_21 ( ! V_11 -> V_1 ) ) {
V_11 -> V_1 = V_1 ;
F_13 ( V_11 , V_12 , V_1 ) ;
V_18 = NULL ;
V_12 = NULL ;
}
F_22 ( & V_16 -> V_21 ) ;
F_9 ( V_1 ) ;
if ( F_18 ( V_18 ) )
F_23 ( V_18 ) ;
if ( F_18 ( V_12 ) )
F_12 ( V_12 ) ;
}
return 0 ;
V_20:
F_12 ( V_12 ) ;
V_19:
return - V_22 ;
}
static inline struct V_1 * F_24 ( struct V_1 * V_5 , struct V_1 * V_1 )
{
struct V_1 * V_23 = V_1 -> V_5 ;
if ( V_23 != V_5 ) {
if ( F_25 ( V_5 ) )
F_26 ( & V_5 -> V_6 ) ;
V_5 = V_23 ;
F_27 ( & V_5 -> V_6 ) ;
}
return V_5 ;
}
static inline void F_28 ( struct V_1 * V_5 )
{
if ( V_5 )
F_26 ( & V_5 -> V_6 ) ;
}
int F_29 ( struct V_10 * V_24 , struct V_10 * V_25 )
{
struct V_7 * V_12 , * V_26 ;
struct V_1 * V_5 = NULL ;
F_30 (pavc, &src->anon_vma_chain, same_vma) {
struct V_1 * V_1 ;
V_12 = F_11 ( V_27 | V_28 ) ;
if ( F_18 ( ! V_12 ) ) {
F_28 ( V_5 ) ;
V_5 = NULL ;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_29;
}
V_1 = V_26 -> V_1 ;
V_5 = F_24 ( V_5 , V_1 ) ;
F_13 ( V_24 , V_12 , V_1 ) ;
}
F_28 ( V_5 ) ;
return 0 ;
V_29:
F_31 ( V_24 ) ;
return - V_22 ;
}
int F_32 ( struct V_10 * V_11 , struct V_10 * V_30 )
{
struct V_7 * V_12 ;
struct V_1 * V_1 ;
if ( ! V_30 -> V_1 )
return 0 ;
if ( F_29 ( V_11 , V_30 ) )
return - V_22 ;
V_1 = F_1 () ;
if ( ! V_1 )
goto V_31;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_32;
V_1 -> V_5 = V_30 -> V_1 -> V_5 ;
F_33 ( V_1 -> V_5 ) ;
V_11 -> V_1 = V_1 ;
F_8 ( V_1 ) ;
F_13 ( V_11 , V_12 , V_1 ) ;
F_9 ( V_1 ) ;
return 0 ;
V_32:
F_23 ( V_1 ) ;
V_31:
F_31 ( V_11 ) ;
return - V_22 ;
}
void F_31 ( struct V_10 * V_11 )
{
struct V_7 * V_12 , * V_33 ;
struct V_1 * V_5 = NULL ;
F_34 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_12 -> V_1 ;
V_5 = F_24 ( V_5 , V_1 ) ;
F_35 ( V_12 , & V_1 -> V_14 ) ;
if ( F_36 ( & V_1 -> V_14 ) )
continue;
F_37 ( & V_12 -> V_13 ) ;
F_12 ( V_12 ) ;
}
F_28 ( V_5 ) ;
F_34 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_12 -> V_1 ;
F_23 ( V_1 ) ;
F_37 ( & V_12 -> V_13 ) ;
F_12 ( V_12 ) ;
}
}
static void F_38 ( void * V_34 )
{
struct V_1 * V_1 = V_34 ;
F_39 ( & V_1 -> V_6 ) ;
F_3 ( & V_1 -> V_4 , 0 ) ;
V_1 -> V_14 = V_35 ;
}
void T_2 F_40 ( void )
{
V_2 = F_41 ( L_1 , sizeof( struct V_1 ) ,
0 , V_36 | V_37 , F_38 ) ;
V_9 = F_42 ( V_7 , V_37 ) ;
}
struct V_1 * F_43 ( struct V_38 * V_38 )
{
struct V_1 * V_1 = NULL ;
unsigned long V_39 ;
F_44 () ;
V_39 = ( unsigned long ) F_45 ( V_38 -> V_40 ) ;
if ( ( V_39 & V_41 ) != V_42 )
goto V_43;
if ( ! F_46 ( V_38 ) )
goto V_43;
V_1 = (struct V_1 * ) ( V_39 - V_42 ) ;
if ( ! F_47 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_43;
}
if ( ! F_46 ( V_38 ) ) {
F_23 ( V_1 ) ;
V_1 = NULL ;
}
V_43:
F_48 () ;
return V_1 ;
}
struct V_1 * F_49 ( struct V_38 * V_38 )
{
struct V_1 * V_1 = NULL ;
struct V_1 * V_44 ;
unsigned long V_39 ;
F_44 () ;
V_39 = ( unsigned long ) F_45 ( V_38 -> V_40 ) ;
if ( ( V_39 & V_41 ) != V_42 )
goto V_43;
if ( ! F_46 ( V_38 ) )
goto V_43;
V_1 = (struct V_1 * ) ( V_39 - V_42 ) ;
V_44 = F_45 ( V_1 -> V_5 ) ;
if ( F_50 ( & V_44 -> V_6 ) ) {
if ( ! F_46 ( V_38 ) ) {
F_51 ( & V_44 -> V_6 ) ;
V_1 = NULL ;
}
goto V_43;
}
if ( ! F_47 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_43;
}
if ( ! F_46 ( V_38 ) ) {
F_23 ( V_1 ) ;
V_1 = NULL ;
goto V_43;
}
F_48 () ;
F_52 ( V_1 ) ;
if ( F_53 ( & V_1 -> V_4 ) ) {
F_54 ( V_1 ) ;
F_55 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
V_43:
F_48 () ;
return V_1 ;
}
void F_56 ( struct V_1 * V_1 )
{
F_54 ( V_1 ) ;
}
static inline unsigned long
F_57 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
if ( F_18 ( F_58 ( V_11 ) ) )
V_45 = V_38 -> V_46 << F_59 ( F_60 ( V_38 ) ) ;
return V_11 -> V_49 + ( ( V_45 - V_11 -> V_50 ) << V_48 ) ;
}
inline unsigned long
F_61 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_51 = F_57 ( V_38 , V_11 ) ;
F_5 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
return V_51 ;
}
unsigned long F_62 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_51 ;
if ( F_63 ( V_38 ) ) {
struct V_1 * V_53 = F_64 ( V_38 ) ;
if ( ! V_11 -> V_1 || ! V_53 ||
V_11 -> V_1 -> V_5 != V_53 -> V_5 )
return - V_54 ;
} else if ( V_38 -> V_40 && ! ( V_11 -> V_55 & V_56 ) ) {
if ( ! V_11 -> V_57 ||
V_11 -> V_57 -> V_58 != V_38 -> V_40 )
return - V_54 ;
} else
return - V_54 ;
V_51 = F_57 ( V_38 , V_11 ) ;
if ( F_18 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) )
return - V_54 ;
return V_51 ;
}
T_4 * F_65 ( struct V_15 * V_16 , unsigned long V_51 )
{
T_5 * V_59 ;
T_6 * V_60 ;
T_4 * V_61 = NULL ;
V_59 = F_66 ( V_16 , V_51 ) ;
if ( ! F_67 ( * V_59 ) )
goto V_43;
V_60 = F_68 ( V_59 , V_51 ) ;
if ( ! F_69 ( * V_60 ) )
goto V_43;
V_61 = F_70 ( V_60 , V_51 ) ;
if ( ! F_71 ( * V_61 ) )
V_61 = NULL ;
V_43:
return V_61 ;
}
T_7 * F_72 ( struct V_38 * V_38 , struct V_15 * V_16 ,
unsigned long V_51 , T_8 * * V_62 , int V_63 )
{
T_4 * V_61 ;
T_7 * V_64 ;
T_8 * V_65 ;
if ( F_18 ( F_73 ( V_38 ) ) ) {
V_64 = F_74 ( V_16 , V_51 ) ;
if ( ! V_64 )
return NULL ;
V_65 = F_75 ( F_60 ( V_38 ) , V_16 , V_64 ) ;
goto V_66;
}
V_61 = F_65 ( V_16 , V_51 ) ;
if ( ! V_61 )
return NULL ;
if ( F_76 ( * V_61 ) )
return NULL ;
V_64 = F_77 ( V_61 , V_51 ) ;
if ( ! V_63 && ! F_78 ( * V_64 ) ) {
F_79 ( V_64 ) ;
return NULL ;
}
V_65 = F_80 ( V_16 , V_61 ) ;
V_66:
F_20 ( V_65 ) ;
if ( F_78 ( * V_64 ) && F_81 ( V_38 ) == F_82 ( * V_64 ) ) {
* V_62 = V_65 ;
return V_64 ;
}
F_83 ( V_64 , V_65 ) ;
return NULL ;
}
int F_84 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_51 ;
T_7 * V_64 ;
T_8 * V_65 ;
V_51 = F_57 ( V_38 , V_11 ) ;
if ( F_18 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) )
return 0 ;
V_64 = F_85 ( V_38 , V_11 -> V_17 , V_51 , & V_65 , 1 ) ;
if ( ! V_64 )
return 0 ;
F_83 ( V_64 , V_65 ) ;
return 1 ;
}
int F_86 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 , void * V_67 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_8 * V_65 ;
int V_68 = 0 ;
struct V_69 * V_70 = V_67 ;
if ( F_18 ( F_87 ( V_38 ) ) ) {
T_4 * V_61 ;
V_61 = F_88 ( V_38 , V_16 , V_51 ,
V_71 , & V_65 ) ;
if ( ! V_61 )
return V_72 ;
if ( V_11 -> V_55 & V_73 ) {
F_22 ( V_65 ) ;
V_70 -> V_55 |= V_73 ;
return V_74 ;
}
if ( F_89 ( V_11 , V_51 , V_61 ) )
V_68 ++ ;
F_22 ( V_65 ) ;
} else {
T_7 * V_64 ;
V_64 = F_85 ( V_38 , V_16 , V_51 , & V_65 , 0 ) ;
if ( ! V_64 )
return V_72 ;
if ( V_11 -> V_55 & V_73 ) {
F_83 ( V_64 , V_65 ) ;
V_70 -> V_55 |= V_73 ;
return V_74 ;
}
if ( F_90 ( V_11 , V_51 , V_64 ) ) {
if ( F_21 ( ! ( V_11 -> V_55 & V_75 ) ) )
V_68 ++ ;
}
F_83 ( V_64 , V_65 ) ;
}
if ( V_68 ) {
V_70 -> V_68 ++ ;
V_70 -> V_55 |= V_11 -> V_55 ;
}
V_70 -> V_76 -- ;
if ( ! V_70 -> V_76 )
return V_77 ;
return V_72 ;
}
static bool F_91 ( struct V_10 * V_11 , void * V_67 )
{
struct V_69 * V_70 = V_67 ;
struct V_78 * V_79 = V_70 -> V_79 ;
if ( ! F_92 ( V_11 -> V_17 , V_79 ) )
return true ;
return false ;
}
int F_93 ( struct V_38 * V_38 ,
int V_80 ,
struct V_78 * V_79 ,
unsigned long * V_55 )
{
int V_81 ;
int V_82 = 0 ;
struct V_69 V_70 = {
. V_76 = F_94 ( V_38 ) ,
. V_79 = V_79 ,
} ;
struct V_83 V_84 = {
. V_85 = F_86 ,
. V_67 = ( void * ) & V_70 ,
. V_86 = F_49 ,
} ;
* V_55 = 0 ;
if ( ! F_46 ( V_38 ) )
return 0 ;
if ( ! F_95 ( V_38 ) )
return 0 ;
if ( ! V_80 && ( ! F_63 ( V_38 ) || F_96 ( V_38 ) ) ) {
V_82 = F_97 ( V_38 ) ;
if ( ! V_82 )
return 1 ;
}
if ( V_79 ) {
V_84 . V_87 = F_91 ;
}
V_81 = F_98 ( V_38 , & V_84 ) ;
* V_55 = V_70 . V_55 ;
if ( V_82 )
F_99 ( V_38 ) ;
return V_70 . V_68 ;
}
static int F_100 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 , void * V_67 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_7 * V_64 ;
T_8 * V_65 ;
int V_81 = 0 ;
int * V_88 = V_67 ;
V_64 = F_85 ( V_38 , V_16 , V_51 , & V_65 , 1 ) ;
if ( ! V_64 )
goto V_43;
if ( F_101 ( * V_64 ) || F_102 ( * V_64 ) ) {
T_7 V_89 ;
F_103 ( V_11 , V_51 , F_82 ( * V_64 ) ) ;
V_89 = F_104 ( V_11 , V_51 , V_64 ) ;
V_89 = F_105 ( V_89 ) ;
V_89 = F_106 ( V_89 ) ;
F_107 ( V_16 , V_51 , V_64 , V_89 ) ;
V_81 = 1 ;
}
F_83 ( V_64 , V_65 ) ;
if ( V_81 ) {
F_108 ( V_16 , V_51 ) ;
( * V_88 ) ++ ;
}
V_43:
return V_72 ;
}
static bool F_109 ( struct V_10 * V_11 , void * V_67 )
{
if ( V_11 -> V_55 & V_90 )
return false ;
return true ;
}
int F_110 ( struct V_38 * V_38 )
{
int V_88 = 0 ;
struct V_91 * V_40 ;
struct V_83 V_84 = {
. V_67 = ( void * ) & V_88 ,
. V_85 = F_100 ,
. V_87 = F_109 ,
} ;
F_111 ( ! F_112 ( V_38 ) ) ;
if ( ! F_46 ( V_38 ) )
return 0 ;
V_40 = F_113 ( V_38 ) ;
if ( ! V_40 )
return 0 ;
F_98 ( V_38 , & V_84 ) ;
return V_88 ;
}
void F_114 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_115 ( ! F_112 ( V_38 ) , V_38 ) ;
F_5 ( ! V_1 ) ;
F_115 ( V_38 -> V_46 != F_116 ( V_11 , V_51 ) , V_38 ) ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_91 * ) V_1 ;
}
static void F_117 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_92 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_111 ( ! V_1 ) ;
if ( F_63 ( V_38 ) )
return;
if ( ! V_92 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_91 * ) V_1 ;
V_38 -> V_46 = F_116 ( V_11 , V_51 ) ;
}
static void F_118 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
#ifdef F_119
F_111 ( F_64 ( V_38 ) -> V_5 != V_11 -> V_1 -> V_5 ) ;
F_111 ( V_38 -> V_46 != F_116 ( V_11 , V_51 ) ) ;
#endif
}
void F_120 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_121 ( V_38 , V_11 , V_51 , 0 ) ;
}
void F_121 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_92 )
{
int V_93 = F_122 ( & V_38 -> V_94 ) ;
if ( V_93 ) {
if ( F_87 ( V_38 ) )
F_123 ( V_38 ,
V_95 ) ;
F_124 ( F_125 ( V_38 ) , V_96 ,
F_126 ( V_38 ) ) ;
}
if ( F_18 ( F_96 ( V_38 ) ) )
return;
F_115 ( ! F_112 ( V_38 ) , V_38 ) ;
if ( V_93 )
F_117 ( V_38 , V_11 , V_51 , V_92 ) ;
else
F_118 ( V_38 , V_11 , V_51 ) ;
}
void F_127 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_5 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
F_128 ( V_38 ) ;
F_3 ( & V_38 -> V_94 , 0 ) ;
if ( F_87 ( V_38 ) )
F_123 ( V_38 , V_95 ) ;
F_124 ( F_125 ( V_38 ) , V_96 ,
F_126 ( V_38 ) ) ;
F_117 ( V_38 , V_11 , V_51 , 1 ) ;
if ( ! F_129 ( V_11 , V_38 ) ) {
F_130 ( V_38 ) ;
F_131 ( V_38 ) ;
} else
F_132 ( V_38 ) ;
}
void F_133 ( struct V_38 * V_38 )
{
bool V_97 ;
unsigned long V_98 ;
F_134 ( V_38 , & V_97 , & V_98 ) ;
if ( F_122 ( & V_38 -> V_94 ) ) {
F_123 ( V_38 , V_99 ) ;
F_135 ( V_38 , V_100 ) ;
}
F_136 ( V_38 , & V_97 , & V_98 ) ;
}
void F_137 ( struct V_38 * V_38 )
{
bool V_101 = F_63 ( V_38 ) ;
bool V_97 ;
unsigned long V_98 ;
if ( ! V_101 )
F_134 ( V_38 , & V_97 , & V_98 ) ;
if ( ! F_138 ( - 1 , & V_38 -> V_94 ) )
goto V_43;
if ( F_18 ( F_73 ( V_38 ) ) )
goto V_43;
if ( V_101 ) {
F_139 ( V_38 ) ;
if ( F_87 ( V_38 ) )
F_140 ( V_38 ,
V_95 ) ;
F_124 ( F_125 ( V_38 ) , V_96 ,
- F_126 ( V_38 ) ) ;
} else {
F_140 ( V_38 , V_99 ) ;
F_141 ( V_38 , V_100 ) ;
F_136 ( V_38 , & V_97 , & V_98 ) ;
}
if ( F_18 ( F_142 ( V_38 ) ) )
F_143 ( V_38 ) ;
return;
V_43:
if ( ! V_101 )
F_136 ( V_38 , & V_97 , & V_98 ) ;
}
int F_144 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 , void * V_67 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_7 * V_64 ;
T_7 V_102 ;
T_8 * V_65 ;
int V_81 = V_72 ;
enum V_103 V_98 = (enum V_103 ) V_67 ;
V_64 = F_85 ( V_38 , V_16 , V_51 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( ! ( V_98 & V_104 ) ) {
if ( V_11 -> V_55 & V_73 )
goto V_105;
if ( F_145 ( V_98 ) == V_106 )
goto V_107;
}
if ( ! ( V_98 & V_108 ) ) {
if ( F_90 ( V_11 , V_51 , V_64 ) ) {
V_81 = V_74 ;
goto V_107;
}
}
F_103 ( V_11 , V_51 , F_81 ( V_38 ) ) ;
V_102 = F_104 ( V_11 , V_51 , V_64 ) ;
if ( F_101 ( V_102 ) )
F_146 ( V_38 ) ;
F_147 ( V_16 ) ;
if ( F_148 ( V_38 ) && ! ( V_98 & V_109 ) ) {
if ( ! F_73 ( V_38 ) ) {
if ( F_63 ( V_38 ) )
F_149 ( V_16 , V_110 ) ;
else
F_149 ( V_16 , V_111 ) ;
}
F_107 ( V_16 , V_51 , V_64 ,
F_150 ( F_151 ( V_38 ) ) ) ;
} else if ( F_63 ( V_38 ) ) {
T_9 V_89 = { . V_112 = F_152 (page) } ;
T_7 V_113 ;
if ( F_153 ( V_38 ) ) {
if ( F_154 ( V_89 ) < 0 ) {
F_107 ( V_16 , V_51 , V_64 , V_102 ) ;
V_81 = V_74 ;
goto V_107;
}
if ( F_155 ( & V_16 -> V_114 ) ) {
F_20 ( & V_115 ) ;
if ( F_155 ( & V_16 -> V_114 ) )
F_14 ( & V_16 -> V_114 , & V_116 . V_114 ) ;
F_22 ( & V_115 ) ;
}
F_149 ( V_16 , V_110 ) ;
F_156 ( V_16 , V_117 ) ;
} else if ( F_157 ( V_118 ) ) {
F_111 ( F_145 ( V_98 ) != V_119 ) ;
V_89 = F_158 ( V_38 , F_102 ( V_102 ) ) ;
}
V_113 = F_150 ( V_89 ) ;
if ( F_159 ( V_102 ) )
V_113 = F_160 ( V_113 ) ;
F_107 ( V_16 , V_51 , V_64 , V_113 ) ;
F_111 ( F_161 ( * V_64 ) ) ;
} else if ( F_157 ( V_118 ) &&
( F_145 ( V_98 ) == V_119 ) ) {
T_9 V_89 ;
V_89 = F_158 ( V_38 , F_102 ( V_102 ) ) ;
F_107 ( V_16 , V_51 , V_64 , F_150 ( V_89 ) ) ;
} else
F_149 ( V_16 , V_111 ) ;
F_137 ( V_38 ) ;
F_162 ( V_38 ) ;
V_107:
F_83 ( V_64 , V_65 ) ;
if ( V_81 != V_74 )
F_108 ( V_16 , V_51 ) ;
V_43:
return V_81 ;
V_105:
F_83 ( V_64 , V_65 ) ;
if ( F_50 ( & V_11 -> V_17 -> V_120 ) ) {
if ( V_11 -> V_55 & V_73 ) {
F_163 ( V_38 ) ;
V_81 = V_121 ;
}
F_51 ( & V_11 -> V_17 -> V_120 ) ;
}
return V_81 ;
}
static int F_164 ( unsigned long V_122 , unsigned int * V_76 ,
struct V_10 * V_11 , struct V_38 * V_123 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_4 * V_61 ;
T_7 * V_64 ;
T_7 V_102 ;
T_8 * V_65 ;
struct V_38 * V_38 ;
unsigned long V_51 ;
unsigned long V_124 ;
unsigned long V_125 ;
unsigned long V_126 ;
int V_81 = V_72 ;
int V_127 = 0 ;
V_51 = ( V_11 -> V_49 + V_122 ) & V_128 ;
V_126 = V_51 + V_129 ;
if ( V_51 < V_11 -> V_49 )
V_51 = V_11 -> V_49 ;
if ( V_126 > V_11 -> V_52 )
V_126 = V_11 -> V_52 ;
V_61 = F_65 ( V_16 , V_51 ) ;
if ( ! V_61 )
return V_81 ;
V_124 = V_51 ;
V_125 = V_126 ;
F_165 ( V_16 , V_124 , V_125 ) ;
if ( F_50 ( & V_11 -> V_17 -> V_120 ) ) {
V_127 = ( V_11 -> V_55 & V_73 ) ;
if ( ! V_127 )
F_51 ( & V_11 -> V_17 -> V_120 ) ;
}
V_64 = F_166 ( V_16 , V_61 , V_51 , & V_65 ) ;
F_147 ( V_16 ) ;
for (; V_51 < V_126 ; V_64 ++ , V_51 += V_130 ) {
if ( ! F_78 ( * V_64 ) )
continue;
V_38 = F_167 ( V_11 , V_51 , * V_64 ) ;
F_111 ( ! V_38 || F_63 ( V_38 ) ) ;
if ( V_127 ) {
F_163 ( V_38 ) ;
if ( V_38 == V_123 )
V_81 = V_121 ;
continue;
}
if ( F_90 ( V_11 , V_51 , V_64 ) )
continue;
F_103 ( V_11 , V_51 , F_82 ( * V_64 ) ) ;
V_102 = F_104 ( V_11 , V_51 , V_64 ) ;
if ( V_38 -> V_46 != F_116 ( V_11 , V_51 ) ) {
T_7 V_131 = F_168 ( V_38 -> V_46 ) ;
if ( F_159 ( V_102 ) )
F_169 ( V_131 ) ;
F_107 ( V_16 , V_51 , V_64 , V_131 ) ;
}
if ( F_101 ( V_102 ) )
F_146 ( V_38 ) ;
F_137 ( V_38 ) ;
F_162 ( V_38 ) ;
F_149 ( V_16 , V_111 ) ;
( * V_76 ) -- ;
}
F_83 ( V_64 - 1 , V_65 ) ;
F_170 ( V_16 , V_124 , V_125 ) ;
if ( V_127 )
F_51 ( & V_11 -> V_17 -> V_120 ) ;
return V_81 ;
}
static int F_171 ( struct V_38 * V_38 ,
struct V_91 * V_40 , void * V_67 )
{
struct V_10 * V_11 ;
int V_81 = V_72 ;
unsigned long V_122 ;
unsigned long V_132 = 0 ;
unsigned long V_133 = 0 ;
unsigned int V_76 ;
F_172 (vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
V_122 = ( unsigned long ) V_11 -> V_134 ;
if ( V_122 > V_132 )
V_132 = V_122 ;
V_122 = V_11 -> V_52 - V_11 -> V_49 ;
if ( V_122 > V_133 )
V_133 = V_122 ;
}
if ( V_133 == 0 ) {
return V_74 ;
}
V_76 = F_94 ( V_38 ) ;
if ( ! V_76 )
return V_81 ;
F_173 () ;
V_133 = ( V_133 + V_129 - 1 ) & V_128 ;
if ( V_132 == 0 )
V_132 = V_129 ;
do {
F_172 (vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
V_122 = ( unsigned long ) V_11 -> V_134 ;
while ( V_122 < V_132 &&
V_122 < V_11 -> V_52 - V_11 -> V_49 ) {
if ( F_164 ( V_122 , & V_76 ,
V_11 , V_38 ) == V_121 )
V_81 = V_121 ;
V_122 += V_129 ;
V_11 -> V_134 = ( void * ) V_122 ;
if ( ( int ) V_76 <= 0 )
return V_81 ;
}
V_11 -> V_134 = ( void * ) V_132 ;
}
F_173 () ;
V_132 += V_129 ;
} while ( V_132 <= V_133 );
F_172 (vma, &mapping->i_mmap_nonlinear, shared.nonlinear)
V_11 -> V_134 = NULL ;
return V_81 ;
}
bool F_174 ( struct V_10 * V_11 )
{
int V_135 = V_11 -> V_55 & ( V_136 | V_137 ) ;
if ( ! V_135 )
return false ;
if ( ( V_11 -> V_55 & V_138 ) ==
V_138 )
return true ;
return false ;
}
static bool F_175 ( struct V_10 * V_11 , void * V_67 )
{
return F_174 ( V_11 ) ;
}
static int F_176 ( struct V_38 * V_38 )
{
return ! F_46 ( V_38 ) ;
}
int F_177 ( struct V_38 * V_38 , enum V_103 V_98 )
{
int V_81 ;
struct V_83 V_84 = {
. V_85 = F_144 ,
. V_67 = ( void * ) V_98 ,
. V_139 = F_176 ,
. V_140 = F_171 ,
. V_86 = F_49 ,
} ;
F_115 ( ! F_73 ( V_38 ) && F_87 ( V_38 ) , V_38 ) ;
if ( V_98 & V_119 && ! F_96 ( V_38 ) && F_63 ( V_38 ) )
V_84 . V_87 = F_175 ;
V_81 = F_98 ( V_38 , & V_84 ) ;
if ( V_81 != V_121 && ! F_46 ( V_38 ) )
V_81 = V_77 ;
return V_81 ;
}
int F_178 ( struct V_38 * V_38 )
{
int V_81 ;
struct V_83 V_84 = {
. V_85 = F_144 ,
. V_67 = ( void * ) V_106 ,
. V_139 = F_176 ,
. V_140 = NULL ,
. V_86 = F_49 ,
} ;
F_115 ( ! F_112 ( V_38 ) || F_179 ( V_38 ) , V_38 ) ;
V_81 = F_98 ( V_38 , & V_84 ) ;
return V_81 ;
}
void F_55 ( struct V_1 * V_1 )
{
struct V_1 * V_5 = V_1 -> V_5 ;
if ( V_5 != V_1 && F_53 ( & V_5 -> V_4 ) )
F_4 ( V_5 ) ;
F_4 ( V_1 ) ;
}
static struct V_1 * F_180 ( struct V_38 * V_38 ,
struct V_83 * V_84 )
{
struct V_1 * V_1 ;
if ( V_84 -> V_86 )
return V_84 -> V_86 ( V_38 ) ;
V_1 = F_64 ( V_38 ) ;
if ( ! V_1 )
return NULL ;
F_52 ( V_1 ) ;
return V_1 ;
}
static int F_181 ( struct V_38 * V_38 , struct V_83 * V_84 )
{
struct V_1 * V_1 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_7 * V_12 ;
int V_81 = V_72 ;
V_1 = F_180 ( V_38 , V_84 ) ;
if ( ! V_1 )
return V_81 ;
F_182 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
if ( V_84 -> V_87 && V_84 -> V_87 ( V_11 , V_84 -> V_67 ) )
continue;
V_81 = V_84 -> V_85 ( V_38 , V_11 , V_51 , V_84 -> V_67 ) ;
if ( V_81 != V_72 )
break;
if ( V_84 -> V_139 && V_84 -> V_139 ( V_38 ) )
break;
}
F_54 ( V_1 ) ;
return V_81 ;
}
static int F_183 ( struct V_38 * V_38 , struct V_83 * V_84 )
{
struct V_91 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << F_184 ( V_38 ) ;
struct V_10 * V_11 ;
int V_81 = V_72 ;
F_5 ( ! F_112 ( V_38 ) ) ;
if ( ! V_40 )
return V_81 ;
F_185 ( & V_40 -> V_141 ) ;
F_186 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
if ( V_84 -> V_87 && V_84 -> V_87 ( V_11 , V_84 -> V_67 ) )
continue;
V_81 = V_84 -> V_85 ( V_38 , V_11 , V_51 , V_84 -> V_67 ) ;
if ( V_81 != V_72 )
goto V_139;
if ( V_84 -> V_139 && V_84 -> V_139 ( V_38 ) )
goto V_139;
}
if ( ! V_84 -> V_140 )
goto V_139;
if ( F_155 ( & V_40 -> V_142 ) )
goto V_139;
V_81 = V_84 -> V_140 ( V_38 , V_40 , V_84 -> V_67 ) ;
V_139:
F_187 ( & V_40 -> V_141 ) ;
return V_81 ;
}
int F_98 ( struct V_38 * V_38 , struct V_83 * V_84 )
{
if ( F_18 ( F_96 ( V_38 ) ) )
return F_188 ( V_38 , V_84 ) ;
else if ( F_63 ( V_38 ) )
return F_181 ( V_38 , V_84 ) ;
else
return F_183 ( V_38 , V_84 ) ;
}
static void F_189 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_92 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_111 ( ! V_1 ) ;
if ( F_63 ( V_38 ) )
return;
if ( ! V_92 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_91 * ) V_1 ;
V_38 -> V_46 = F_116 ( V_11 , V_51 ) ;
}
void F_190 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
int V_93 ;
F_111 ( ! F_112 ( V_38 ) ) ;
F_111 ( ! V_1 ) ;
V_93 = F_122 ( & V_38 -> V_94 ) ;
if ( V_93 )
F_189 ( V_38 , V_11 , V_51 , 0 ) ;
}
void F_191 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_111 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
F_3 ( & V_38 -> V_94 , 0 ) ;
F_189 ( V_38 , V_11 , V_51 , 1 ) ;
}
