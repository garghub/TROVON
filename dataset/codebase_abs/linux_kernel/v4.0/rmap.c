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
unsigned long F_62 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
unsigned long V_51 ;
if ( F_63 ( V_40 ) ) {
struct V_1 * V_53 = F_64 ( V_40 ) ;
if ( ! V_13 -> V_1 || ! V_53 ||
V_13 -> V_1 -> V_7 != V_53 -> V_7 )
return - V_54 ;
} else if ( V_40 -> V_42 ) {
if ( ! V_13 -> V_55 || V_13 -> V_55 -> V_56 != V_40 -> V_42 )
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
T_5 * V_57 ;
T_6 * V_58 ;
T_4 * V_59 = NULL ;
T_4 V_60 ;
V_57 = F_66 ( V_18 , V_51 ) ;
if ( ! F_67 ( * V_57 ) )
goto V_45;
V_58 = F_68 ( V_57 , V_51 ) ;
if ( ! F_69 ( * V_58 ) )
goto V_45;
V_59 = F_70 ( V_58 , V_51 ) ;
V_60 = * V_59 ;
F_71 () ;
if ( ! F_72 ( V_60 ) || F_73 ( V_60 ) )
V_59 = NULL ;
V_45:
return V_59 ;
}
T_7 * F_74 ( struct V_40 * V_40 , struct V_17 * V_18 ,
unsigned long V_51 , T_8 * * V_61 , int V_62 )
{
T_4 * V_59 ;
T_7 * V_63 ;
T_8 * V_64 ;
if ( F_18 ( F_75 ( V_40 ) ) ) {
V_63 = F_76 ( V_18 , V_51 ) ;
if ( ! V_63 )
return NULL ;
V_64 = F_77 ( F_78 ( V_40 ) , V_18 , V_63 ) ;
goto V_65;
}
V_59 = F_65 ( V_18 , V_51 ) ;
if ( ! V_59 )
return NULL ;
V_63 = F_79 ( V_59 , V_51 ) ;
if ( ! V_62 && ! F_80 ( * V_63 ) ) {
F_81 ( V_63 ) ;
return NULL ;
}
V_64 = F_82 ( V_18 , V_59 ) ;
V_65:
F_20 ( V_64 ) ;
if ( F_80 ( * V_63 ) && F_83 ( V_40 ) == F_84 ( * V_63 ) ) {
* V_61 = V_64 ;
return V_63 ;
}
F_85 ( V_63 , V_64 ) ;
return NULL ;
}
int F_86 ( struct V_40 * V_40 , struct V_12 * V_13 )
{
unsigned long V_51 ;
T_7 * V_63 ;
T_8 * V_64 ;
V_51 = F_58 ( V_40 , V_13 ) ;
if ( F_18 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) )
return 0 ;
V_63 = F_87 ( V_40 , V_13 -> V_19 , V_51 , & V_64 , 1 ) ;
if ( ! V_63 )
return 0 ;
F_85 ( V_63 , V_64 ) ;
return 1 ;
}
static int F_88 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_66 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_8 * V_64 ;
int V_67 = 0 ;
struct V_68 * V_69 = V_66 ;
if ( F_18 ( F_89 ( V_40 ) ) ) {
T_4 * V_59 ;
V_59 = F_90 ( V_40 , V_18 , V_51 ,
V_70 , & V_64 ) ;
if ( ! V_59 )
return V_71 ;
if ( V_13 -> V_72 & V_73 ) {
F_22 ( V_64 ) ;
V_69 -> V_72 |= V_73 ;
return V_74 ;
}
if ( F_91 ( V_13 , V_51 , V_59 ) )
V_67 ++ ;
F_22 ( V_64 ) ;
} else {
T_7 * V_63 ;
V_63 = F_87 ( V_40 , V_18 , V_51 , & V_64 , 0 ) ;
if ( ! V_63 )
return V_71 ;
if ( V_13 -> V_72 & V_73 ) {
F_85 ( V_63 , V_64 ) ;
V_69 -> V_72 |= V_73 ;
return V_74 ;
}
if ( F_92 ( V_13 , V_51 , V_63 ) ) {
if ( F_21 ( ! ( V_13 -> V_72 & V_75 ) ) )
V_67 ++ ;
}
F_85 ( V_63 , V_64 ) ;
}
if ( V_67 ) {
V_69 -> V_67 ++ ;
V_69 -> V_72 |= V_13 -> V_72 ;
}
V_69 -> V_76 -- ;
if ( ! V_69 -> V_76 )
return V_77 ;
return V_71 ;
}
static bool F_93 ( struct V_12 * V_13 , void * V_66 )
{
struct V_68 * V_69 = V_66 ;
struct V_78 * V_79 = V_69 -> V_79 ;
if ( ! F_94 ( V_13 -> V_19 , V_79 ) )
return true ;
return false ;
}
int F_95 ( struct V_40 * V_40 ,
int V_80 ,
struct V_78 * V_79 ,
unsigned long * V_72 )
{
int V_81 ;
int V_82 = 0 ;
struct V_68 V_69 = {
. V_76 = F_96 ( V_40 ) ,
. V_79 = V_79 ,
} ;
struct V_83 V_84 = {
. V_85 = F_88 ,
. V_66 = ( void * ) & V_69 ,
. V_86 = F_50 ,
} ;
* V_72 = 0 ;
if ( ! F_47 ( V_40 ) )
return 0 ;
if ( ! F_97 ( V_40 ) )
return 0 ;
if ( ! V_80 && ( ! F_63 ( V_40 ) || F_98 ( V_40 ) ) ) {
V_82 = F_99 ( V_40 ) ;
if ( ! V_82 )
return 1 ;
}
if ( V_79 ) {
V_84 . V_87 = F_93 ;
}
V_81 = F_100 ( V_40 , & V_84 ) ;
* V_72 = V_69 . V_72 ;
if ( V_82 )
F_101 ( V_40 ) ;
return V_69 . V_67 ;
}
static int F_102 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_66 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_7 * V_63 ;
T_8 * V_64 ;
int V_81 = 0 ;
int * V_88 = V_66 ;
V_63 = F_87 ( V_40 , V_18 , V_51 , & V_64 , 1 ) ;
if ( ! V_63 )
goto V_45;
if ( F_103 ( * V_63 ) || F_104 ( * V_63 ) ) {
T_7 V_89 ;
F_105 ( V_13 , V_51 , F_84 ( * V_63 ) ) ;
V_89 = F_106 ( V_13 , V_51 , V_63 ) ;
V_89 = F_107 ( V_89 ) ;
V_89 = F_108 ( V_89 ) ;
F_109 ( V_18 , V_51 , V_63 , V_89 ) ;
V_81 = 1 ;
}
F_85 ( V_63 , V_64 ) ;
if ( V_81 ) {
F_110 ( V_18 , V_51 ) ;
( * V_88 ) ++ ;
}
V_45:
return V_71 ;
}
static bool F_111 ( struct V_12 * V_13 , void * V_66 )
{
if ( V_13 -> V_72 & V_90 )
return false ;
return true ;
}
int F_112 ( struct V_40 * V_40 )
{
int V_88 = 0 ;
struct V_91 * V_42 ;
struct V_83 V_84 = {
. V_66 = ( void * ) & V_88 ,
. V_85 = F_102 ,
. V_87 = F_111 ,
} ;
F_38 ( ! F_113 ( V_40 ) ) ;
if ( ! F_47 ( V_40 ) )
return 0 ;
V_42 = F_114 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
F_100 ( V_40 , & V_84 ) ;
return V_88 ;
}
void F_115 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_116 ( ! F_113 ( V_40 ) , V_40 ) ;
F_61 ( ! V_1 , V_13 ) ;
F_116 ( V_40 -> V_92 != F_117 ( V_13 , V_51 ) , V_40 ) ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_91 * ) V_1 ;
}
static void F_118 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_93 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_63 ( V_40 ) )
return;
if ( ! V_93 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_91 * ) V_1 ;
V_40 -> V_92 = F_117 ( V_13 , V_51 ) ;
}
static void F_119 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
#ifdef F_120
F_38 ( F_64 ( V_40 ) -> V_7 != V_13 -> V_1 -> V_7 ) ;
F_38 ( V_40 -> V_92 != F_117 ( V_13 , V_51 ) ) ;
#endif
}
void F_121 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_122 ( V_40 , V_13 , V_51 , 0 ) ;
}
void F_122 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_93 )
{
int V_94 = F_123 ( & V_40 -> V_95 ) ;
if ( V_94 ) {
if ( F_89 ( V_40 ) )
F_124 ( V_40 ,
V_96 ) ;
F_125 ( F_126 ( V_40 ) , V_97 ,
F_127 ( V_40 ) ) ;
}
if ( F_18 ( F_98 ( V_40 ) ) )
return;
F_116 ( ! F_113 ( V_40 ) , V_40 ) ;
if ( V_94 )
F_118 ( V_40 , V_13 , V_51 , V_93 ) ;
else
F_119 ( V_40 , V_13 , V_51 ) ;
}
void F_128 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_61 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 , V_13 ) ;
F_129 ( V_40 ) ;
F_3 ( & V_40 -> V_95 , 0 ) ;
if ( F_89 ( V_40 ) )
F_124 ( V_40 , V_96 ) ;
F_125 ( F_126 ( V_40 ) , V_97 ,
F_127 ( V_40 ) ) ;
F_118 ( V_40 , V_13 , V_51 , 1 ) ;
}
void F_130 ( struct V_40 * V_40 )
{
struct V_78 * V_79 ;
V_79 = F_131 ( V_40 ) ;
if ( F_123 ( & V_40 -> V_95 ) ) {
F_124 ( V_40 , V_98 ) ;
F_132 ( V_79 , V_99 ) ;
}
F_133 ( V_79 ) ;
}
static void F_134 ( struct V_40 * V_40 )
{
struct V_78 * V_79 ;
V_79 = F_131 ( V_40 ) ;
if ( ! F_135 ( - 1 , & V_40 -> V_95 ) )
goto V_45;
if ( F_18 ( F_75 ( V_40 ) ) )
goto V_45;
F_136 ( V_40 , V_98 ) ;
F_137 ( V_79 , V_99 ) ;
if ( F_18 ( F_138 ( V_40 ) ) )
F_139 ( V_40 ) ;
V_45:
F_133 ( V_79 ) ;
}
void F_140 ( struct V_40 * V_40 )
{
if ( ! F_63 ( V_40 ) ) {
F_134 ( V_40 ) ;
return;
}
if ( ! F_135 ( - 1 , & V_40 -> V_95 ) )
return;
if ( F_18 ( F_75 ( V_40 ) ) )
return;
if ( F_89 ( V_40 ) )
F_136 ( V_40 , V_96 ) ;
F_125 ( F_126 ( V_40 ) , V_97 ,
- F_127 ( V_40 ) ) ;
if ( F_18 ( F_138 ( V_40 ) ) )
F_139 ( V_40 ) ;
}
static int F_141 ( struct V_40 * V_40 , struct V_12 * V_13 ,
unsigned long V_51 , void * V_66 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_7 * V_63 ;
T_7 V_100 ;
T_8 * V_64 ;
int V_81 = V_71 ;
enum V_101 V_102 = (enum V_101 ) V_66 ;
V_63 = F_87 ( V_40 , V_18 , V_51 , & V_64 , 0 ) ;
if ( ! V_63 )
goto V_45;
if ( ! ( V_102 & V_103 ) ) {
if ( V_13 -> V_72 & V_73 )
goto V_104;
if ( V_102 & V_105 )
goto V_106;
}
if ( ! ( V_102 & V_107 ) ) {
if ( F_92 ( V_13 , V_51 , V_63 ) ) {
V_81 = V_74 ;
goto V_106;
}
}
F_105 ( V_13 , V_51 , F_83 ( V_40 ) ) ;
V_100 = F_106 ( V_13 , V_51 , V_63 ) ;
if ( F_103 ( V_100 ) )
F_142 ( V_40 ) ;
F_143 ( V_18 ) ;
if ( F_144 ( V_40 ) && ! ( V_102 & V_108 ) ) {
if ( ! F_75 ( V_40 ) ) {
if ( F_63 ( V_40 ) )
F_145 ( V_18 , V_109 ) ;
else
F_145 ( V_18 , V_110 ) ;
}
F_109 ( V_18 , V_51 , V_63 ,
F_146 ( F_147 ( V_40 ) ) ) ;
} else if ( F_148 ( V_100 ) ) {
if ( F_63 ( V_40 ) )
F_145 ( V_18 , V_109 ) ;
else
F_145 ( V_18 , V_110 ) ;
} else if ( F_63 ( V_40 ) ) {
T_9 V_89 = { . V_111 = F_149 (page) } ;
T_7 V_112 ;
if ( F_150 ( V_40 ) ) {
if ( F_151 ( V_89 ) < 0 ) {
F_109 ( V_18 , V_51 , V_63 , V_100 ) ;
V_81 = V_74 ;
goto V_106;
}
if ( F_152 ( & V_18 -> V_113 ) ) {
F_20 ( & V_114 ) ;
if ( F_152 ( & V_18 -> V_113 ) )
F_15 ( & V_18 -> V_113 , & V_115 . V_113 ) ;
F_22 ( & V_114 ) ;
}
F_145 ( V_18 , V_109 ) ;
F_153 ( V_18 , V_116 ) ;
} else if ( F_154 ( V_117 ) ) {
F_38 ( ! ( V_102 & V_118 ) ) ;
V_89 = F_155 ( V_40 , F_104 ( V_100 ) ) ;
}
V_112 = F_146 ( V_89 ) ;
if ( F_156 ( V_100 ) )
V_112 = F_157 ( V_112 ) ;
F_109 ( V_18 , V_51 , V_63 , V_112 ) ;
} else if ( F_154 ( V_117 ) &&
( V_102 & V_118 ) ) {
T_9 V_89 ;
V_89 = F_155 ( V_40 , F_104 ( V_100 ) ) ;
F_109 ( V_18 , V_51 , V_63 , F_146 ( V_89 ) ) ;
} else
F_145 ( V_18 , V_110 ) ;
F_140 ( V_40 ) ;
F_158 ( V_40 ) ;
V_106:
F_85 ( V_63 , V_64 ) ;
if ( V_81 != V_74 && ! ( V_102 & V_105 ) )
F_110 ( V_18 , V_51 ) ;
V_45:
return V_81 ;
V_104:
F_85 ( V_63 , V_64 ) ;
if ( F_51 ( & V_13 -> V_19 -> V_119 ) ) {
if ( V_13 -> V_72 & V_73 ) {
F_159 ( V_40 ) ;
V_81 = V_120 ;
}
F_52 ( & V_13 -> V_19 -> V_119 ) ;
}
return V_81 ;
}
bool F_160 ( struct V_12 * V_13 )
{
int V_121 = V_13 -> V_72 & ( V_122 | V_123 ) ;
if ( ! V_121 )
return false ;
if ( ( V_13 -> V_72 & V_124 ) ==
V_124 )
return true ;
return false ;
}
static bool F_161 ( struct V_12 * V_13 , void * V_66 )
{
return F_160 ( V_13 ) ;
}
static int F_162 ( struct V_40 * V_40 )
{
return ! F_47 ( V_40 ) ;
}
int F_163 ( struct V_40 * V_40 , enum V_101 V_102 )
{
int V_81 ;
struct V_83 V_84 = {
. V_85 = F_141 ,
. V_66 = ( void * ) V_102 ,
. V_125 = F_162 ,
. V_86 = F_50 ,
} ;
F_116 ( ! F_75 ( V_40 ) && F_89 ( V_40 ) , V_40 ) ;
if ( ( V_102 & V_118 ) && ! F_98 ( V_40 ) && F_63 ( V_40 ) )
V_84 . V_87 = F_161 ;
V_81 = F_100 ( V_40 , & V_84 ) ;
if ( V_81 != V_120 && ! F_47 ( V_40 ) )
V_81 = V_77 ;
return V_81 ;
}
int F_164 ( struct V_40 * V_40 )
{
int V_81 ;
struct V_83 V_84 = {
. V_85 = F_141 ,
. V_66 = ( void * ) V_105 ,
. V_125 = F_162 ,
. V_86 = F_50 ,
} ;
F_116 ( ! F_113 ( V_40 ) || F_165 ( V_40 ) , V_40 ) ;
V_81 = F_100 ( V_40 , & V_84 ) ;
return V_81 ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_1 * V_7 = V_1 -> V_7 ;
F_4 ( V_1 ) ;
if ( V_7 != V_1 && F_54 ( & V_7 -> V_4 ) )
F_4 ( V_7 ) ;
}
static struct V_1 * F_166 ( struct V_40 * V_40 ,
struct V_83 * V_84 )
{
struct V_1 * V_1 ;
if ( V_84 -> V_86 )
return V_84 -> V_86 ( V_40 ) ;
V_1 = F_64 ( V_40 ) ;
if ( ! V_1 )
return NULL ;
F_53 ( V_1 ) ;
return V_1 ;
}
static int F_167 ( struct V_40 * V_40 , struct V_83 * V_84 )
{
struct V_1 * V_1 ;
T_3 V_47 ;
struct V_9 * V_14 ;
int V_81 = V_71 ;
V_1 = F_166 ( V_40 , V_84 ) ;
if ( ! V_1 )
return V_81 ;
V_47 = F_59 ( V_40 ) ;
F_168 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_12 * V_13 = V_14 -> V_13 ;
unsigned long V_51 = F_60 ( V_40 , V_13 ) ;
if ( V_84 -> V_87 && V_84 -> V_87 ( V_13 , V_84 -> V_66 ) )
continue;
V_81 = V_84 -> V_85 ( V_40 , V_13 , V_51 , V_84 -> V_66 ) ;
if ( V_81 != V_71 )
break;
if ( V_84 -> V_125 && V_84 -> V_125 ( V_40 ) )
break;
}
F_55 ( V_1 ) ;
return V_81 ;
}
static int F_169 ( struct V_40 * V_40 , struct V_83 * V_84 )
{
struct V_91 * V_42 = V_40 -> V_42 ;
T_3 V_47 ;
struct V_12 * V_13 ;
int V_81 = V_71 ;
F_116 ( ! F_113 ( V_40 ) , V_40 ) ;
if ( ! V_42 )
return V_81 ;
V_47 = F_59 ( V_40 ) ;
F_170 ( V_42 ) ;
F_171 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_60 ( V_40 , V_13 ) ;
if ( V_84 -> V_87 && V_84 -> V_87 ( V_13 , V_84 -> V_66 ) )
continue;
V_81 = V_84 -> V_85 ( V_40 , V_13 , V_51 , V_84 -> V_66 ) ;
if ( V_81 != V_71 )
goto V_125;
if ( V_84 -> V_125 && V_84 -> V_125 ( V_40 ) )
goto V_125;
}
V_125:
F_172 ( V_42 ) ;
return V_81 ;
}
int F_100 ( struct V_40 * V_40 , struct V_83 * V_84 )
{
if ( F_18 ( F_98 ( V_40 ) ) )
return F_173 ( V_40 , V_84 ) ;
else if ( F_63 ( V_40 ) )
return F_167 ( V_40 , V_84 ) ;
else
return F_169 ( V_40 , V_84 ) ;
}
static void F_174 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 , int V_93 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_63 ( V_40 ) )
return;
if ( ! V_93 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_44 ;
V_40 -> V_42 = (struct V_91 * ) V_1 ;
V_40 -> V_92 = F_117 ( V_13 , V_51 ) ;
}
void F_175 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
int V_94 ;
F_38 ( ! F_113 ( V_40 ) ) ;
F_38 ( ! V_1 ) ;
V_94 = F_123 ( & V_40 -> V_95 ) ;
if ( V_94 )
F_174 ( V_40 , V_13 , V_51 , 0 ) ;
}
void F_176 ( struct V_40 * V_40 ,
struct V_12 * V_13 , unsigned long V_51 )
{
F_38 ( V_51 < V_13 -> V_48 || V_51 >= V_13 -> V_52 ) ;
F_3 ( & V_40 -> V_95 , 0 ) ;
F_174 ( V_40 , V_13 , V_51 , 1 ) ;
}
