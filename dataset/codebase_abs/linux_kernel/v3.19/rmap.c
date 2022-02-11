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
unsigned long F_62 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
unsigned long V_51 ;
if ( F_63 ( V_40 ) ) {
struct V_1 * V_53 = F_64 ( V_40 ) ;
if ( ! V_13 -> V_1 || ! V_53 ||
V_13 -> V_1 -> V_7 != V_53 -> V_7 )
return - V_54 ;
} else if ( V_40 -> V_42 && ! ( V_13 -> V_55 & V_56 ) ) {
if ( ! V_13 -> V_57 ||
V_13 -> V_57 -> V_58 != V_40 -> V_42 )
return - V_54 ;
} else
return - V_54 ;
V_51 = F_58 ( V_40 , V_13 ) ;
if ( F_18 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) )
return - V_54 ;
return V_51 ;
}
T_4 * F_65 ( struct V_17 * V_18 , unsigned long V_51 )
{
T_5 * V_59 ;
T_6 * V_60 ;
T_4 * V_61 = NULL ;
T_4 V_62 ;
V_59 = F_66 ( V_18 , V_51 ) ;
if ( ! F_67 ( * V_59 ) )
goto V_45;
V_60 = F_68 ( V_59 , V_51 ) ;
if ( ! F_69 ( * V_60 ) )
goto V_45;
V_61 = F_70 ( V_60 , V_51 ) ;
V_62 = * V_61 ;
F_71 () ;
if ( ! F_72 ( V_62 ) || F_73 ( V_62 ) )
V_61 = NULL ;
V_45:
return V_61 ;
}
T_7 * F_74 ( struct V_40 * V_40 , struct V_17 * V_18 ,
unsigned long V_51 , T_8 * * V_63 , int V_64 )
{
T_4 * V_61 ;
T_7 * V_65 ;
T_8 * V_66 ;
if ( F_18 ( F_75 ( V_40 ) ) ) {
V_65 = F_76 ( V_18 , V_51 ) ;
if ( ! V_65 )
return NULL ;
V_66 = F_77 ( F_78 ( V_40 ) , V_18 , V_65 ) ;
goto V_67;
}
V_61 = F_65 ( V_18 , V_51 ) ;
if ( ! V_61 )
return NULL ;
V_65 = F_79 ( V_61 , V_51 ) ;
if ( ! V_64 && ! F_80 ( * V_65 ) ) {
F_81 ( V_65 ) ;
return NULL ;
}
V_66 = F_82 ( V_18 , V_61 ) ;
V_67:
F_20 ( V_66 ) ;
if ( F_80 ( * V_65 ) && F_83 ( V_40 ) == F_84 ( * V_65 ) ) {
* V_63 = V_66 ;
return V_65 ;
}
F_85 ( V_65 , V_66 ) ;
return NULL ;
}
int F_86 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
unsigned long V_51 ;
T_7 * V_65 ;
T_8 * V_66 ;
V_51 = F_58 ( V_40 , V_13 ) ;
if ( F_18 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) )
return 0 ;
V_65 = F_87 ( V_40 , V_13 -> V_19 , V_51 , & V_66 , 1 ) ;
if ( ! V_65 )
return 0 ;
F_85 ( V_65 , V_66 ) ;
return 1 ;
}
static int F_88 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_68 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_8 * V_66 ;
int V_69 = 0 ;
struct V_70 * V_71 = V_68 ;
if ( F_18 ( F_89 ( V_40 ) ) ) {
T_4 * V_61 ;
V_61 = F_90 ( V_40 , V_18 , V_51 ,
V_72 , & V_66 ) ;
if ( ! V_61 )
return V_73 ;
if ( V_13 -> V_55 & V_74 ) {
F_22 ( V_66 ) ;
V_71 -> V_55 |= V_74 ;
return V_75 ;
}
if ( F_91 ( V_13 , V_51 , V_61 ) )
V_69 ++ ;
F_22 ( V_66 ) ;
} else {
T_7 * V_65 ;
V_65 = F_87 ( V_40 , V_18 , V_51 , & V_66 , 0 ) ;
if ( ! V_65 )
return V_73 ;
if ( V_13 -> V_55 & V_74 ) {
F_85 ( V_65 , V_66 ) ;
V_71 -> V_55 |= V_74 ;
return V_75 ;
}
if ( F_92 ( V_13 , V_51 , V_65 ) ) {
if ( F_21 ( ! ( V_13 -> V_55 & V_76 ) ) )
V_69 ++ ;
}
F_85 ( V_65 , V_66 ) ;
}
if ( V_69 ) {
V_71 -> V_69 ++ ;
V_71 -> V_55 |= V_13 -> V_55 ;
}
V_71 -> V_77 -- ;
if ( ! V_71 -> V_77 )
return V_78 ;
return V_73 ;
}
static bool F_93 ( struct V_12 * V_13 , void * V_68 )
{
struct V_70 * V_71 = V_68 ;
struct V_79 * V_80 = V_71 -> V_80 ;
if ( ! F_94 ( V_13 -> V_19 , V_80 ) )
return true ;
return false ;
}
int F_95 ( struct V_40 * V_40 ,
int V_81 ,
struct V_79 * V_80 ,
unsigned long * V_55 )
{
int V_82 ;
int V_83 = 0 ;
struct V_70 V_71 = {
. V_77 = F_96 ( V_40 ) ,
. V_80 = V_80 ,
} ;
struct V_84 V_85 = {
. V_86 = F_88 ,
. V_68 = ( void * ) & V_71 ,
. V_87 = F_50 ,
} ;
* V_55 = 0 ;
if ( ! F_47 ( V_40 ) )
return 0 ;
if ( ! F_97 ( V_40 ) )
return 0 ;
if ( ! V_81 && ( ! F_63 ( V_40 ) || F_98 ( V_40 ) ) ) {
V_83 = F_99 ( V_40 ) ;
if ( ! V_83 )
return 1 ;
}
if ( V_80 ) {
V_85 . V_88 = F_93 ;
}
V_82 = F_100 ( V_40 , & V_85 ) ;
* V_55 = V_71 . V_55 ;
if ( V_83 )
F_101 ( V_40 ) ;
return V_71 . V_69 ;
}
static int F_102 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_68 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_7 * V_65 ;
T_8 * V_66 ;
int V_82 = 0 ;
int * V_89 = V_68 ;
V_65 = F_87 ( V_40 , V_18 , V_51 , & V_66 , 1 ) ;
if ( ! V_65 )
goto V_45;
if ( F_103 ( * V_65 ) || F_104 ( * V_65 ) ) {
T_7 V_90 ;
F_105 ( V_13 , V_51 , F_84 ( * V_65 ) ) ;
V_90 = F_106 ( V_13 , V_51 , V_65 ) ;
V_90 = F_107 ( V_90 ) ;
V_90 = F_108 ( V_90 ) ;
F_109 ( V_18 , V_51 , V_65 , V_90 ) ;
V_82 = 1 ;
}
F_85 ( V_65 , V_66 ) ;
if ( V_82 ) {
F_110 ( V_18 , V_51 ) ;
( * V_89 ) ++ ;
}
V_45:
return V_73 ;
}
static bool F_111 ( struct V_12 * V_13 , void * V_68 )
{
if ( V_13 -> V_55 & V_91 )
return false ;
return true ;
}
int F_112 ( struct V_40 * V_40 )
{
int V_89 = 0 ;
struct V_92 * V_42 ;
struct V_84 V_85 = {
. V_68 = ( void * ) & V_89 ,
. V_86 = F_102 ,
. V_88 = F_111 ,
} ;
F_38 ( ! F_113 ( V_40 ) ) ;
if ( ! F_47 ( V_40 ) )
return 0 ;
V_42 = F_114 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
F_100 ( V_40 , & V_85 ) ;
return V_89 ;
}
void F_115 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_116 ( ! F_113 ( V_40 ) , V_40 ) ;
F_61 ( ! V_1 , V_13 ) ;
F_116 ( V_40 -> V_93 != F_117 ( V_13 , V_51 ) , V_40 ) ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_92 * ) V_1 ;
}
static void F_118 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_94 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_63 ( V_40 ) )
return;
if ( ! V_94 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_92 * ) V_1 ;
V_40 -> V_93 = F_117 ( V_13 , V_51 ) ;
}
static void F_119 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
#ifdef F_120
F_38 ( F_64 ( V_40 ) -> V_7 != V_13 -> V_1 -> V_7 ) ;
F_38 ( V_40 -> V_93 != F_117 ( V_13 , V_51 ) ) ;
#endif
}
void F_121 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_122 ( V_40 , V_13 , V_51 , 0 ) ;
}
void F_122 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_94 )
{
int V_95 = F_123 ( & V_40 -> V_96 ) ;
if ( V_95 ) {
if ( F_89 ( V_40 ) )
F_124 ( V_40 ,
V_97 ) ;
F_125 ( F_126 ( V_40 ) , V_98 ,
F_127 ( V_40 ) ) ;
}
if ( F_18 ( F_98 ( V_40 ) ) )
return;
F_116 ( ! F_113 ( V_40 ) , V_40 ) ;
if ( V_95 )
F_118 ( V_40 , V_13 , V_51 , V_94 ) ;
else
F_119 ( V_40 , V_13 , V_51 ) ;
}
void F_128 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_61 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 , V_13 ) ;
F_129 ( V_40 ) ;
F_3 ( & V_40 -> V_96 , 0 ) ;
if ( F_89 ( V_40 ) )
F_124 ( V_40 , V_97 ) ;
F_125 ( F_126 ( V_40 ) , V_98 ,
F_127 ( V_40 ) ) ;
F_118 ( V_40 , V_13 , V_51 , 1 ) ;
}
void F_130 ( struct V_40 * V_40 )
{
struct V_79 * V_80 ;
unsigned long V_99 ;
bool V_100 ;
V_80 = F_131 ( V_40 , & V_100 , & V_99 ) ;
if ( F_123 ( & V_40 -> V_96 ) ) {
F_124 ( V_40 , V_101 ) ;
F_132 ( V_80 , V_102 ) ;
}
F_133 ( V_80 , & V_100 , & V_99 ) ;
}
static void F_134 ( struct V_40 * V_40 )
{
struct V_79 * V_80 ;
unsigned long V_99 ;
bool V_100 ;
V_80 = F_131 ( V_40 , & V_100 , & V_99 ) ;
if ( ! F_135 ( - 1 , & V_40 -> V_96 ) )
goto V_45;
if ( F_18 ( F_75 ( V_40 ) ) )
goto V_45;
F_136 ( V_40 , V_101 ) ;
F_137 ( V_80 , V_102 ) ;
if ( F_18 ( F_138 ( V_40 ) ) )
F_139 ( V_40 ) ;
V_45:
F_133 ( V_80 , & V_100 , & V_99 ) ;
}
void F_140 ( struct V_40 * V_40 )
{
if ( ! F_63 ( V_40 ) ) {
F_134 ( V_40 ) ;
return;
}
if ( ! F_135 ( - 1 , & V_40 -> V_96 ) )
return;
if ( F_18 ( F_75 ( V_40 ) ) )
return;
if ( F_89 ( V_40 ) )
F_136 ( V_40 , V_97 ) ;
F_125 ( F_126 ( V_40 ) , V_98 ,
- F_127 ( V_40 ) ) ;
if ( F_18 ( F_138 ( V_40 ) ) )
F_139 ( V_40 ) ;
}
static int F_141 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_68 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_7 * V_65 ;
T_7 V_103 ;
T_8 * V_66 ;
int V_82 = V_73 ;
enum V_104 V_99 = (enum V_104 ) V_68 ;
V_65 = F_87 ( V_40 , V_18 , V_51 , & V_66 , 0 ) ;
if ( ! V_65 )
goto V_45;
if ( ! ( V_99 & V_105 ) ) {
if ( V_13 -> V_55 & V_74 )
goto V_106;
if ( V_99 & V_107 )
goto V_108;
}
if ( ! ( V_99 & V_109 ) ) {
if ( F_92 ( V_13 , V_51 , V_65 ) ) {
V_82 = V_75 ;
goto V_108;
}
}
F_105 ( V_13 , V_51 , F_83 ( V_40 ) ) ;
V_103 = F_106 ( V_13 , V_51 , V_65 ) ;
if ( F_103 ( V_103 ) )
F_142 ( V_40 ) ;
F_143 ( V_18 ) ;
if ( F_144 ( V_40 ) && ! ( V_99 & V_110 ) ) {
if ( ! F_75 ( V_40 ) ) {
if ( F_63 ( V_40 ) )
F_145 ( V_18 , V_111 ) ;
else
F_145 ( V_18 , V_112 ) ;
}
F_109 ( V_18 , V_51 , V_65 ,
F_146 ( F_147 ( V_40 ) ) ) ;
} else if ( F_148 ( V_103 ) ) {
if ( F_63 ( V_40 ) )
F_145 ( V_18 , V_111 ) ;
else
F_145 ( V_18 , V_112 ) ;
} else if ( F_63 ( V_40 ) ) {
T_9 V_90 = { . V_113 = F_149 (page) } ;
T_7 V_114 ;
if ( F_150 ( V_40 ) ) {
if ( F_151 ( V_90 ) < 0 ) {
F_109 ( V_18 , V_51 , V_65 , V_103 ) ;
V_82 = V_75 ;
goto V_108;
}
if ( F_152 ( & V_18 -> V_115 ) ) {
F_20 ( & V_116 ) ;
if ( F_152 ( & V_18 -> V_115 ) )
F_15 ( & V_18 -> V_115 , & V_117 . V_115 ) ;
F_22 ( & V_116 ) ;
}
F_145 ( V_18 , V_111 ) ;
F_153 ( V_18 , V_118 ) ;
} else if ( F_154 ( V_119 ) ) {
F_38 ( ! ( V_99 & V_120 ) ) ;
V_90 = F_155 ( V_40 , F_104 ( V_103 ) ) ;
}
V_114 = F_146 ( V_90 ) ;
if ( F_156 ( V_103 ) )
V_114 = F_157 ( V_114 ) ;
F_109 ( V_18 , V_51 , V_65 , V_114 ) ;
F_38 ( F_158 ( * V_65 ) ) ;
} else if ( F_154 ( V_119 ) &&
( V_99 & V_120 ) ) {
T_9 V_90 ;
V_90 = F_155 ( V_40 , F_104 ( V_103 ) ) ;
F_109 ( V_18 , V_51 , V_65 , F_146 ( V_90 ) ) ;
} else
F_145 ( V_18 , V_112 ) ;
F_140 ( V_40 ) ;
F_159 ( V_40 ) ;
V_108:
F_85 ( V_65 , V_66 ) ;
if ( V_82 != V_75 && ! ( V_99 & V_107 ) )
F_110 ( V_18 , V_51 ) ;
V_45:
return V_82 ;
V_106:
F_85 ( V_65 , V_66 ) ;
if ( F_51 ( & V_13 -> V_19 -> V_121 ) ) {
if ( V_13 -> V_55 & V_74 ) {
F_160 ( V_40 ) ;
V_82 = V_122 ;
}
F_52 ( & V_13 -> V_19 -> V_121 ) ;
}
return V_82 ;
}
static int F_161 ( unsigned long V_123 , unsigned int * V_77 ,
struct V_12 * V_13 , struct V_40 * V_124 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_4 * V_61 ;
T_7 * V_65 ;
T_7 V_103 ;
T_8 * V_66 ;
struct V_40 * V_40 ;
unsigned long V_51 ;
unsigned long V_125 ;
unsigned long V_126 ;
unsigned long V_127 ;
int V_82 = V_73 ;
int V_128 = 0 ;
V_51 = ( V_13 -> V_48 + V_123 ) & V_129 ;
V_127 = V_51 + V_130 ;
if ( V_51 < V_13 -> V_48 )
V_51 = V_13 -> V_48 ;
if ( V_127 > V_13 -> V_52 )
V_127 = V_13 -> V_52 ;
V_61 = F_65 ( V_18 , V_51 ) ;
if ( ! V_61 )
return V_82 ;
V_125 = V_51 ;
V_126 = V_127 ;
F_162 ( V_18 , V_125 , V_126 ) ;
if ( F_51 ( & V_13 -> V_19 -> V_121 ) ) {
V_128 = ( V_13 -> V_55 & V_74 ) ;
if ( ! V_128 )
F_52 ( & V_13 -> V_19 -> V_121 ) ;
}
V_65 = F_163 ( V_18 , V_61 , V_51 , & V_66 ) ;
F_143 ( V_18 ) ;
for (; V_51 < V_127 ; V_65 ++ , V_51 += V_131 ) {
if ( ! F_80 ( * V_65 ) )
continue;
V_40 = F_164 ( V_13 , V_51 , * V_65 ) ;
F_38 ( ! V_40 || F_63 ( V_40 ) ) ;
if ( V_128 ) {
if ( V_40 == V_124 ) {
F_160 ( V_40 ) ;
V_82 = V_122 ;
} else if ( F_99 ( V_40 ) ) {
F_160 ( V_40 ) ;
F_101 ( V_40 ) ;
}
continue;
}
if ( F_165 ( V_13 , V_51 , V_65 ) )
continue;
F_105 ( V_13 , V_51 , F_84 ( * V_65 ) ) ;
V_103 = F_166 ( V_13 , V_51 , V_65 ) ;
if ( V_40 -> V_93 != F_117 ( V_13 , V_51 ) ) {
T_7 V_132 = F_167 ( V_40 -> V_93 ) ;
if ( F_156 ( V_103 ) )
V_132 = F_168 ( V_132 ) ;
F_109 ( V_18 , V_51 , V_65 , V_132 ) ;
}
if ( F_103 ( V_103 ) )
F_142 ( V_40 ) ;
F_140 ( V_40 ) ;
F_159 ( V_40 ) ;
F_145 ( V_18 , V_112 ) ;
( * V_77 ) -- ;
}
F_85 ( V_65 - 1 , V_66 ) ;
F_169 ( V_18 , V_125 , V_126 ) ;
if ( V_128 )
F_52 ( & V_13 -> V_19 -> V_121 ) ;
return V_82 ;
}
static int F_170 ( struct V_40 * V_40 ,
struct V_92 * V_42 , void * V_68 )
{
struct V_12 * V_13 ;
int V_82 = V_73 ;
unsigned long V_123 ;
unsigned long V_133 = 0 ;
unsigned long V_134 = 0 ;
unsigned int V_77 ;
F_171 (vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
V_123 = ( unsigned long ) V_13 -> V_135 ;
if ( V_123 > V_133 )
V_133 = V_123 ;
V_123 = V_13 -> V_52 - V_13 -> V_48 ;
if ( V_123 > V_134 )
V_134 = V_123 ;
}
if ( V_134 == 0 ) {
return V_75 ;
}
V_77 = F_96 ( V_40 ) ;
if ( ! V_77 )
return V_82 ;
F_172 () ;
V_134 = ( V_134 + V_130 - 1 ) & V_129 ;
if ( V_133 == 0 )
V_133 = V_130 ;
do {
F_171 (vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
V_123 = ( unsigned long ) V_13 -> V_135 ;
while ( V_123 < V_133 &&
V_123 < V_13 -> V_52 - V_13 -> V_48 ) {
if ( F_161 ( V_123 , & V_77 ,
V_13 , V_40 ) == V_122 )
V_82 = V_122 ;
V_123 += V_130 ;
V_13 -> V_135 = ( void * ) V_123 ;
if ( ( int ) V_77 <= 0 )
return V_82 ;
}
V_13 -> V_135 = ( void * ) V_133 ;
}
F_172 () ;
V_133 += V_130 ;
} while ( V_133 <= V_134 );
F_171 (vma, &mapping->i_mmap_nonlinear, shared.nonlinear)
V_13 -> V_135 = NULL ;
return V_82 ;
}
bool F_173 ( struct V_12 * V_13 )
{
int V_136 = V_13 -> V_55 & ( V_137 | V_138 ) ;
if ( ! V_136 )
return false ;
if ( ( V_13 -> V_55 & V_139 ) ==
V_139 )
return true ;
return false ;
}
static bool F_174 ( struct V_12 * V_13 , void * V_68 )
{
return F_173 ( V_13 ) ;
}
static int F_175 ( struct V_40 * V_40 )
{
return ! F_47 ( V_40 ) ;
}
int F_176 ( struct V_40 * V_40 , enum V_104 V_99 )
{
int V_82 ;
struct V_84 V_85 = {
. V_86 = F_141 ,
. V_68 = ( void * ) V_99 ,
. V_140 = F_175 ,
. V_141 = F_170 ,
. V_87 = F_50 ,
} ;
F_116 ( ! F_75 ( V_40 ) && F_89 ( V_40 ) , V_40 ) ;
if ( ( V_99 & V_120 ) && ! F_98 ( V_40 ) && F_63 ( V_40 ) )
V_85 . V_88 = F_174 ;
V_82 = F_100 ( V_40 , & V_85 ) ;
if ( V_82 != V_122 && ! F_47 ( V_40 ) )
V_82 = V_78 ;
return V_82 ;
}
int F_177 ( struct V_40 * V_40 )
{
int V_82 ;
struct V_84 V_85 = {
. V_86 = F_141 ,
. V_68 = ( void * ) V_107 ,
. V_140 = F_175 ,
. V_141 = NULL ,
. V_87 = F_50 ,
} ;
F_116 ( ! F_113 ( V_40 ) || F_178 ( V_40 ) , V_40 ) ;
V_82 = F_100 ( V_40 , & V_85 ) ;
return V_82 ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_1 * V_7 = V_1 -> V_7 ;
F_4 ( V_1 ) ;
if ( V_7 != V_1 && F_54 ( & V_7 -> V_4 ) )
F_4 ( V_7 ) ;
}
static struct V_1 * F_179 ( struct V_40 * V_40 ,
struct V_84 * V_85 )
{
struct V_1 * V_1 ;
if ( V_85 -> V_87 )
return V_85 -> V_87 ( V_40 ) ;
V_1 = F_64 ( V_40 ) ;
if ( ! V_1 )
return NULL ;
F_53 ( V_1 ) ;
return V_1 ;
}
static int F_180 ( struct V_40 * V_40 , struct V_84 * V_85 )
{
struct V_1 * V_1 ;
T_3 V_47 ;
struct V_9 * V_14 ;
int V_82 = V_73 ;
V_1 = F_179 ( V_40 , V_85 ) ;
if ( ! V_1 )
return V_82 ;
V_47 = F_59 ( V_40 ) ;
F_181 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_12 * V_13 = V_14 -> V_13 ;
unsigned long V_51 = F_60 ( V_40 , V_13 ) ;
if ( V_85 -> V_88 && V_85 -> V_88 ( V_13 , V_85 -> V_68 ) )
continue;
V_82 = V_85 -> V_86 ( V_40 , V_13 , V_51 , V_85 -> V_68 ) ;
if ( V_82 != V_73 )
break;
if ( V_85 -> V_140 && V_85 -> V_140 ( V_40 ) )
break;
}
F_55 ( V_1 ) ;
return V_82 ;
}
static int F_182 ( struct V_40 * V_40 , struct V_84 * V_85 )
{
struct V_92 * V_42 = V_40 -> V_42 ;
T_3 V_47 ;
struct V_12 * V_13 ;
int V_82 = V_73 ;
F_116 ( ! F_113 ( V_40 ) , V_40 ) ;
if ( ! V_42 )
return V_82 ;
V_47 = F_59 ( V_40 ) ;
F_183 ( V_42 ) ;
F_184 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_60 ( V_40 , V_13 ) ;
if ( V_85 -> V_88 && V_85 -> V_88 ( V_13 , V_85 -> V_68 ) )
continue;
V_82 = V_85 -> V_86 ( V_40 , V_13 , V_51 , V_85 -> V_68 ) ;
if ( V_82 != V_73 )
goto V_140;
if ( V_85 -> V_140 && V_85 -> V_140 ( V_40 ) )
goto V_140;
}
if ( ! V_85 -> V_141 )
goto V_140;
if ( F_152 ( & V_42 -> V_142 ) )
goto V_140;
V_82 = V_85 -> V_141 ( V_40 , V_42 , V_85 -> V_68 ) ;
V_140:
F_185 ( V_42 ) ;
return V_82 ;
}
int F_100 ( struct V_40 * V_40 , struct V_84 * V_85 )
{
if ( F_18 ( F_98 ( V_40 ) ) )
return F_186 ( V_40 , V_85 ) ;
else if ( F_63 ( V_40 ) )
return F_180 ( V_40 , V_85 ) ;
else
return F_182 ( V_40 , V_85 ) ;
}
static void F_187 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_94 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_63 ( V_40 ) )
return;
if ( ! V_94 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_92 * ) V_1 ;
V_40 -> V_93 = F_117 ( V_13 , V_51 ) ;
}
void F_188 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
int V_95 ;
F_38 ( ! F_113 ( V_40 ) ) ;
F_38 ( ! V_1 ) ;
V_95 = F_123 ( & V_40 -> V_96 ) ;
if ( V_95 )
F_187 ( V_40 , V_13 , V_51 , 0 ) ;
}
void F_189 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_38 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) ;
F_3 ( & V_40 -> V_96 , 0 ) ;
F_187 ( V_40 , V_13 , V_51 , 1 ) ;
}
