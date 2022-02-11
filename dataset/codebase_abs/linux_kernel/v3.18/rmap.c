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
F_7 () ;
if ( F_8 ( & V_1 -> V_5 -> V_6 ) ) {
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
}
F_11 ( V_2 , V_1 ) ;
}
static inline struct V_7 * F_12 ( T_1 V_8 )
{
return F_2 ( V_9 , V_8 ) ;
}
static void F_13 ( struct V_7 * V_7 )
{
F_11 ( V_9 , V_7 ) ;
}
static void F_14 ( struct V_10 * V_11 ,
struct V_7 * V_12 ,
struct V_1 * V_1 )
{
V_12 -> V_11 = V_11 ;
V_12 -> V_1 = V_1 ;
F_15 ( & V_12 -> V_13 , & V_11 -> V_7 ) ;
F_16 ( V_12 , & V_1 -> V_14 ) ;
}
int F_17 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
struct V_7 * V_12 ;
F_7 () ;
if ( F_18 ( ! V_1 ) ) {
struct V_15 * V_16 = V_11 -> V_17 ;
struct V_1 * V_18 ;
V_12 = F_12 ( V_3 ) ;
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
F_9 ( V_1 ) ;
F_20 ( & V_16 -> V_21 ) ;
if ( F_21 ( ! V_11 -> V_1 ) ) {
V_11 -> V_1 = V_1 ;
F_14 ( V_11 , V_12 , V_1 ) ;
V_18 = NULL ;
V_12 = NULL ;
}
F_22 ( & V_16 -> V_21 ) ;
F_10 ( V_1 ) ;
if ( F_18 ( V_18 ) )
F_23 ( V_18 ) ;
if ( F_18 ( V_12 ) )
F_13 ( V_12 ) ;
}
return 0 ;
V_20:
F_13 ( V_12 ) ;
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
V_12 = F_12 ( V_27 | V_28 ) ;
if ( F_18 ( ! V_12 ) ) {
F_28 ( V_5 ) ;
V_5 = NULL ;
V_12 = F_12 ( V_3 ) ;
if ( ! V_12 )
goto V_29;
}
V_1 = V_26 -> V_1 ;
V_5 = F_24 ( V_5 , V_1 ) ;
F_14 ( V_24 , V_12 , V_1 ) ;
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
int error ;
if ( ! V_30 -> V_1 )
return 0 ;
error = F_29 ( V_11 , V_30 ) ;
if ( error )
return error ;
V_1 = F_1 () ;
if ( ! V_1 )
goto V_31;
V_12 = F_12 ( V_3 ) ;
if ( ! V_12 )
goto V_32;
V_1 -> V_5 = V_30 -> V_1 -> V_5 ;
F_33 ( V_1 -> V_5 ) ;
V_11 -> V_1 = V_1 ;
F_9 ( V_1 ) ;
F_14 ( V_11 , V_12 , V_1 ) ;
F_10 ( V_1 ) ;
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
F_13 ( V_12 ) ;
}
F_28 ( V_5 ) ;
F_34 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_12 -> V_1 ;
F_23 ( V_1 ) ;
F_37 ( & V_12 -> V_13 ) ;
F_13 ( V_12 ) ;
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
F_48 () ;
F_23 ( V_1 ) ;
return NULL ;
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
F_48 () ;
F_23 ( V_1 ) ;
return NULL ;
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
T_3 V_45 = F_58 ( V_38 ) ;
return V_11 -> V_46 + ( ( V_45 - V_11 -> V_47 ) << V_48 ) ;
}
inline unsigned long
F_59 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_49 = F_57 ( V_38 , V_11 ) ;
F_60 ( V_49 < V_11 -> V_46 || V_49 >= V_11 -> V_50 , V_11 ) ;
return V_49 ;
}
unsigned long F_61 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_49 ;
if ( F_62 ( V_38 ) ) {
struct V_1 * V_51 = F_63 ( V_38 ) ;
if ( ! V_11 -> V_1 || ! V_51 ||
V_11 -> V_1 -> V_5 != V_51 -> V_5 )
return - V_52 ;
} else if ( V_38 -> V_40 && ! ( V_11 -> V_53 & V_54 ) ) {
if ( ! V_11 -> V_55 ||
V_11 -> V_55 -> V_56 != V_38 -> V_40 )
return - V_52 ;
} else
return - V_52 ;
V_49 = F_57 ( V_38 , V_11 ) ;
if ( F_18 ( V_49 < V_11 -> V_46 || V_49 >= V_11 -> V_50 ) )
return - V_52 ;
return V_49 ;
}
T_4 * F_64 ( struct V_15 * V_16 , unsigned long V_49 )
{
T_5 * V_57 ;
T_6 * V_58 ;
T_4 * V_59 = NULL ;
T_4 V_60 ;
V_57 = F_65 ( V_16 , V_49 ) ;
if ( ! F_66 ( * V_57 ) )
goto V_43;
V_58 = F_67 ( V_57 , V_49 ) ;
if ( ! F_68 ( * V_58 ) )
goto V_43;
V_59 = F_69 ( V_58 , V_49 ) ;
V_60 = F_45 ( * V_59 ) ;
if ( ! F_70 ( V_60 ) || F_71 ( V_60 ) )
V_59 = NULL ;
V_43:
return V_59 ;
}
T_7 * F_72 ( struct V_38 * V_38 , struct V_15 * V_16 ,
unsigned long V_49 , T_8 * * V_61 , int V_62 )
{
T_4 * V_59 ;
T_7 * V_63 ;
T_8 * V_64 ;
if ( F_18 ( F_73 ( V_38 ) ) ) {
V_63 = F_74 ( V_16 , V_49 ) ;
if ( ! V_63 )
return NULL ;
V_64 = F_75 ( F_76 ( V_38 ) , V_16 , V_63 ) ;
goto V_65;
}
V_59 = F_64 ( V_16 , V_49 ) ;
if ( ! V_59 )
return NULL ;
V_63 = F_77 ( V_59 , V_49 ) ;
if ( ! V_62 && ! F_78 ( * V_63 ) ) {
F_79 ( V_63 ) ;
return NULL ;
}
V_64 = F_80 ( V_16 , V_59 ) ;
V_65:
F_20 ( V_64 ) ;
if ( F_78 ( * V_63 ) && F_81 ( V_38 ) == F_82 ( * V_63 ) ) {
* V_61 = V_64 ;
return V_63 ;
}
F_83 ( V_63 , V_64 ) ;
return NULL ;
}
int F_84 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_49 ;
T_7 * V_63 ;
T_8 * V_64 ;
V_49 = F_57 ( V_38 , V_11 ) ;
if ( F_18 ( V_49 < V_11 -> V_46 || V_49 >= V_11 -> V_50 ) )
return 0 ;
V_63 = F_85 ( V_38 , V_11 -> V_17 , V_49 , & V_64 , 1 ) ;
if ( ! V_63 )
return 0 ;
F_83 ( V_63 , V_64 ) ;
return 1 ;
}
static int F_86 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 , void * V_66 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_8 * V_64 ;
int V_67 = 0 ;
struct V_68 * V_69 = V_66 ;
if ( F_18 ( F_87 ( V_38 ) ) ) {
T_4 * V_59 ;
V_59 = F_88 ( V_38 , V_16 , V_49 ,
V_70 , & V_64 ) ;
if ( ! V_59 )
return V_71 ;
if ( V_11 -> V_53 & V_72 ) {
F_22 ( V_64 ) ;
V_69 -> V_53 |= V_72 ;
return V_73 ;
}
if ( F_89 ( V_11 , V_49 , V_59 ) )
V_67 ++ ;
F_22 ( V_64 ) ;
} else {
T_7 * V_63 ;
V_63 = F_85 ( V_38 , V_16 , V_49 , & V_64 , 0 ) ;
if ( ! V_63 )
return V_71 ;
if ( V_11 -> V_53 & V_72 ) {
F_83 ( V_63 , V_64 ) ;
V_69 -> V_53 |= V_72 ;
return V_73 ;
}
if ( F_90 ( V_11 , V_49 , V_63 ) ) {
if ( F_21 ( ! ( V_11 -> V_53 & V_74 ) ) )
V_67 ++ ;
}
F_83 ( V_63 , V_64 ) ;
}
if ( V_67 ) {
V_69 -> V_67 ++ ;
V_69 -> V_53 |= V_11 -> V_53 ;
}
V_69 -> V_75 -- ;
if ( ! V_69 -> V_75 )
return V_76 ;
return V_71 ;
}
static bool F_91 ( struct V_10 * V_11 , void * V_66 )
{
struct V_68 * V_69 = V_66 ;
struct V_77 * V_78 = V_69 -> V_78 ;
if ( ! F_92 ( V_11 -> V_17 , V_78 ) )
return true ;
return false ;
}
int F_93 ( struct V_38 * V_38 ,
int V_79 ,
struct V_77 * V_78 ,
unsigned long * V_53 )
{
int V_80 ;
int V_81 = 0 ;
struct V_68 V_69 = {
. V_75 = F_94 ( V_38 ) ,
. V_78 = V_78 ,
} ;
struct V_82 V_83 = {
. V_84 = F_86 ,
. V_66 = ( void * ) & V_69 ,
. V_85 = F_49 ,
} ;
* V_53 = 0 ;
if ( ! F_46 ( V_38 ) )
return 0 ;
if ( ! F_95 ( V_38 ) )
return 0 ;
if ( ! V_79 && ( ! F_62 ( V_38 ) || F_96 ( V_38 ) ) ) {
V_81 = F_97 ( V_38 ) ;
if ( ! V_81 )
return 1 ;
}
if ( V_78 ) {
V_83 . V_86 = F_91 ;
}
V_80 = F_98 ( V_38 , & V_83 ) ;
* V_53 = V_69 . V_53 ;
if ( V_81 )
F_99 ( V_38 ) ;
return V_69 . V_67 ;
}
static int F_100 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 , void * V_66 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_7 * V_63 ;
T_8 * V_64 ;
int V_80 = 0 ;
int * V_87 = V_66 ;
V_63 = F_85 ( V_38 , V_16 , V_49 , & V_64 , 1 ) ;
if ( ! V_63 )
goto V_43;
if ( F_101 ( * V_63 ) || F_102 ( * V_63 ) ) {
T_7 V_88 ;
F_103 ( V_11 , V_49 , F_82 ( * V_63 ) ) ;
V_88 = F_104 ( V_11 , V_49 , V_63 ) ;
V_88 = F_105 ( V_88 ) ;
V_88 = F_106 ( V_88 ) ;
F_107 ( V_16 , V_49 , V_63 , V_88 ) ;
V_80 = 1 ;
}
F_83 ( V_63 , V_64 ) ;
if ( V_80 ) {
F_108 ( V_16 , V_49 ) ;
( * V_87 ) ++ ;
}
V_43:
return V_71 ;
}
static bool F_109 ( struct V_10 * V_11 , void * V_66 )
{
if ( V_11 -> V_53 & V_89 )
return false ;
return true ;
}
int F_110 ( struct V_38 * V_38 )
{
int V_87 = 0 ;
struct V_90 * V_40 ;
struct V_82 V_83 = {
. V_66 = ( void * ) & V_87 ,
. V_84 = F_100 ,
. V_86 = F_109 ,
} ;
F_111 ( ! F_112 ( V_38 ) ) ;
if ( ! F_46 ( V_38 ) )
return 0 ;
V_40 = F_113 ( V_38 ) ;
if ( ! V_40 )
return 0 ;
F_98 ( V_38 , & V_83 ) ;
return V_87 ;
}
void F_114 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_115 ( ! F_112 ( V_38 ) , V_38 ) ;
F_60 ( ! V_1 , V_11 ) ;
F_115 ( V_38 -> V_91 != F_116 ( V_11 , V_49 ) , V_38 ) ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_90 * ) V_1 ;
}
static void F_117 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 , int V_92 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_111 ( ! V_1 ) ;
if ( F_62 ( V_38 ) )
return;
if ( ! V_92 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_90 * ) V_1 ;
V_38 -> V_91 = F_116 ( V_11 , V_49 ) ;
}
static void F_118 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
#ifdef F_119
F_111 ( F_63 ( V_38 ) -> V_5 != V_11 -> V_1 -> V_5 ) ;
F_111 ( V_38 -> V_91 != F_116 ( V_11 , V_49 ) ) ;
#endif
}
void F_120 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
F_121 ( V_38 , V_11 , V_49 , 0 ) ;
}
void F_121 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 , int V_92 )
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
F_117 ( V_38 , V_11 , V_49 , V_92 ) ;
else
F_118 ( V_38 , V_11 , V_49 ) ;
}
void F_127 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
F_60 ( V_49 < V_11 -> V_46 || V_49 >= V_11 -> V_50 , V_11 ) ;
F_128 ( V_38 ) ;
F_3 ( & V_38 -> V_94 , 0 ) ;
if ( F_87 ( V_38 ) )
F_123 ( V_38 , V_95 ) ;
F_124 ( F_125 ( V_38 ) , V_96 ,
F_126 ( V_38 ) ) ;
F_117 ( V_38 , V_11 , V_49 , 1 ) ;
}
void F_129 ( struct V_38 * V_38 )
{
struct V_77 * V_78 ;
unsigned long V_97 ;
bool V_98 ;
V_78 = F_130 ( V_38 , & V_98 , & V_97 ) ;
if ( F_122 ( & V_38 -> V_94 ) ) {
F_123 ( V_38 , V_99 ) ;
F_131 ( V_78 , V_100 ) ;
}
F_132 ( V_78 , V_98 , V_97 ) ;
}
static void F_133 ( struct V_38 * V_38 )
{
struct V_77 * V_78 ;
unsigned long V_97 ;
bool V_98 ;
V_78 = F_130 ( V_38 , & V_98 , & V_97 ) ;
if ( ! F_134 ( - 1 , & V_38 -> V_94 ) )
goto V_43;
if ( F_18 ( F_73 ( V_38 ) ) )
goto V_43;
F_135 ( V_38 , V_99 ) ;
F_136 ( V_78 , V_100 ) ;
if ( F_18 ( F_137 ( V_38 ) ) )
F_138 ( V_38 ) ;
V_43:
F_132 ( V_78 , V_98 , V_97 ) ;
}
void F_139 ( struct V_38 * V_38 )
{
if ( ! F_62 ( V_38 ) ) {
F_133 ( V_38 ) ;
return;
}
if ( ! F_134 ( - 1 , & V_38 -> V_94 ) )
return;
if ( F_18 ( F_73 ( V_38 ) ) )
return;
if ( F_87 ( V_38 ) )
F_135 ( V_38 , V_95 ) ;
F_124 ( F_125 ( V_38 ) , V_96 ,
- F_126 ( V_38 ) ) ;
if ( F_18 ( F_137 ( V_38 ) ) )
F_138 ( V_38 ) ;
}
static int F_140 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 , void * V_66 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_7 * V_63 ;
T_7 V_101 ;
T_8 * V_64 ;
int V_80 = V_71 ;
enum V_102 V_97 = (enum V_102 ) V_66 ;
V_63 = F_85 ( V_38 , V_16 , V_49 , & V_64 , 0 ) ;
if ( ! V_63 )
goto V_43;
if ( ! ( V_97 & V_103 ) ) {
if ( V_11 -> V_53 & V_72 )
goto V_104;
if ( V_97 & V_105 )
goto V_106;
}
if ( ! ( V_97 & V_107 ) ) {
if ( F_90 ( V_11 , V_49 , V_63 ) ) {
V_80 = V_73 ;
goto V_106;
}
}
F_103 ( V_11 , V_49 , F_81 ( V_38 ) ) ;
V_101 = F_104 ( V_11 , V_49 , V_63 ) ;
if ( F_101 ( V_101 ) )
F_141 ( V_38 ) ;
F_142 ( V_16 ) ;
if ( F_143 ( V_38 ) && ! ( V_97 & V_108 ) ) {
if ( ! F_73 ( V_38 ) ) {
if ( F_62 ( V_38 ) )
F_144 ( V_16 , V_109 ) ;
else
F_144 ( V_16 , V_110 ) ;
}
F_107 ( V_16 , V_49 , V_63 ,
F_145 ( F_146 ( V_38 ) ) ) ;
} else if ( F_147 ( V_101 ) ) {
if ( F_62 ( V_38 ) )
F_144 ( V_16 , V_109 ) ;
else
F_144 ( V_16 , V_110 ) ;
} else if ( F_62 ( V_38 ) ) {
T_9 V_88 = { . V_111 = F_148 (page) } ;
T_7 V_112 ;
if ( F_149 ( V_38 ) ) {
if ( F_150 ( V_88 ) < 0 ) {
F_107 ( V_16 , V_49 , V_63 , V_101 ) ;
V_80 = V_73 ;
goto V_106;
}
if ( F_151 ( & V_16 -> V_113 ) ) {
F_20 ( & V_114 ) ;
if ( F_151 ( & V_16 -> V_113 ) )
F_15 ( & V_16 -> V_113 , & V_115 . V_113 ) ;
F_22 ( & V_114 ) ;
}
F_144 ( V_16 , V_109 ) ;
F_152 ( V_16 , V_116 ) ;
} else if ( F_153 ( V_117 ) ) {
F_111 ( ! ( V_97 & V_118 ) ) ;
V_88 = F_154 ( V_38 , F_102 ( V_101 ) ) ;
}
V_112 = F_145 ( V_88 ) ;
if ( F_155 ( V_101 ) )
V_112 = F_156 ( V_112 ) ;
F_107 ( V_16 , V_49 , V_63 , V_112 ) ;
F_111 ( F_157 ( * V_63 ) ) ;
} else if ( F_153 ( V_117 ) &&
( V_97 & V_118 ) ) {
T_9 V_88 ;
V_88 = F_154 ( V_38 , F_102 ( V_101 ) ) ;
F_107 ( V_16 , V_49 , V_63 , F_145 ( V_88 ) ) ;
} else
F_144 ( V_16 , V_110 ) ;
F_139 ( V_38 ) ;
F_158 ( V_38 ) ;
V_106:
F_83 ( V_63 , V_64 ) ;
if ( V_80 != V_73 && ! ( V_97 & V_105 ) )
F_108 ( V_16 , V_49 ) ;
V_43:
return V_80 ;
V_104:
F_83 ( V_63 , V_64 ) ;
if ( F_50 ( & V_11 -> V_17 -> V_119 ) ) {
if ( V_11 -> V_53 & V_72 ) {
F_159 ( V_38 ) ;
V_80 = V_120 ;
}
F_51 ( & V_11 -> V_17 -> V_119 ) ;
}
return V_80 ;
}
static int F_160 ( unsigned long V_121 , unsigned int * V_75 ,
struct V_10 * V_11 , struct V_38 * V_122 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_4 * V_59 ;
T_7 * V_63 ;
T_7 V_101 ;
T_8 * V_64 ;
struct V_38 * V_38 ;
unsigned long V_49 ;
unsigned long V_123 ;
unsigned long V_124 ;
unsigned long V_125 ;
int V_80 = V_71 ;
int V_126 = 0 ;
V_49 = ( V_11 -> V_46 + V_121 ) & V_127 ;
V_125 = V_49 + V_128 ;
if ( V_49 < V_11 -> V_46 )
V_49 = V_11 -> V_46 ;
if ( V_125 > V_11 -> V_50 )
V_125 = V_11 -> V_50 ;
V_59 = F_64 ( V_16 , V_49 ) ;
if ( ! V_59 )
return V_80 ;
V_123 = V_49 ;
V_124 = V_125 ;
F_161 ( V_16 , V_123 , V_124 ) ;
if ( F_50 ( & V_11 -> V_17 -> V_119 ) ) {
V_126 = ( V_11 -> V_53 & V_72 ) ;
if ( ! V_126 )
F_51 ( & V_11 -> V_17 -> V_119 ) ;
}
V_63 = F_162 ( V_16 , V_59 , V_49 , & V_64 ) ;
F_142 ( V_16 ) ;
for (; V_49 < V_125 ; V_63 ++ , V_49 += V_129 ) {
if ( ! F_78 ( * V_63 ) )
continue;
V_38 = F_163 ( V_11 , V_49 , * V_63 ) ;
F_111 ( ! V_38 || F_62 ( V_38 ) ) ;
if ( V_126 ) {
if ( V_38 == V_122 ) {
F_159 ( V_38 ) ;
V_80 = V_120 ;
} else if ( F_97 ( V_38 ) ) {
F_159 ( V_38 ) ;
F_99 ( V_38 ) ;
}
continue;
}
if ( F_164 ( V_11 , V_49 , V_63 ) )
continue;
F_103 ( V_11 , V_49 , F_82 ( * V_63 ) ) ;
V_101 = F_104 ( V_11 , V_49 , V_63 ) ;
if ( V_38 -> V_91 != F_116 ( V_11 , V_49 ) ) {
T_7 V_130 = F_165 ( V_38 -> V_91 ) ;
if ( F_155 ( V_101 ) )
V_130 = F_166 ( V_130 ) ;
F_107 ( V_16 , V_49 , V_63 , V_130 ) ;
}
if ( F_101 ( V_101 ) )
F_141 ( V_38 ) ;
F_139 ( V_38 ) ;
F_158 ( V_38 ) ;
F_144 ( V_16 , V_110 ) ;
( * V_75 ) -- ;
}
F_83 ( V_63 - 1 , V_64 ) ;
F_167 ( V_16 , V_123 , V_124 ) ;
if ( V_126 )
F_51 ( & V_11 -> V_17 -> V_119 ) ;
return V_80 ;
}
static int F_168 ( struct V_38 * V_38 ,
struct V_90 * V_40 , void * V_66 )
{
struct V_10 * V_11 ;
int V_80 = V_71 ;
unsigned long V_121 ;
unsigned long V_131 = 0 ;
unsigned long V_132 = 0 ;
unsigned int V_75 ;
F_169 (vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
V_121 = ( unsigned long ) V_11 -> V_133 ;
if ( V_121 > V_131 )
V_131 = V_121 ;
V_121 = V_11 -> V_50 - V_11 -> V_46 ;
if ( V_121 > V_132 )
V_132 = V_121 ;
}
if ( V_132 == 0 ) {
return V_73 ;
}
V_75 = F_94 ( V_38 ) ;
if ( ! V_75 )
return V_80 ;
F_170 () ;
V_132 = ( V_132 + V_128 - 1 ) & V_127 ;
if ( V_131 == 0 )
V_131 = V_128 ;
do {
F_169 (vma,
&mapping->i_mmap_nonlinear, shared.nonlinear) {
V_121 = ( unsigned long ) V_11 -> V_133 ;
while ( V_121 < V_131 &&
V_121 < V_11 -> V_50 - V_11 -> V_46 ) {
if ( F_160 ( V_121 , & V_75 ,
V_11 , V_38 ) == V_120 )
V_80 = V_120 ;
V_121 += V_128 ;
V_11 -> V_133 = ( void * ) V_121 ;
if ( ( int ) V_75 <= 0 )
return V_80 ;
}
V_11 -> V_133 = ( void * ) V_131 ;
}
F_170 () ;
V_131 += V_128 ;
} while ( V_131 <= V_132 );
F_169 (vma, &mapping->i_mmap_nonlinear, shared.nonlinear)
V_11 -> V_133 = NULL ;
return V_80 ;
}
bool F_171 ( struct V_10 * V_11 )
{
int V_134 = V_11 -> V_53 & ( V_135 | V_136 ) ;
if ( ! V_134 )
return false ;
if ( ( V_11 -> V_53 & V_137 ) ==
V_137 )
return true ;
return false ;
}
static bool F_172 ( struct V_10 * V_11 , void * V_66 )
{
return F_171 ( V_11 ) ;
}
static int F_173 ( struct V_38 * V_38 )
{
return ! F_46 ( V_38 ) ;
}
int F_174 ( struct V_38 * V_38 , enum V_102 V_97 )
{
int V_80 ;
struct V_82 V_83 = {
. V_84 = F_140 ,
. V_66 = ( void * ) V_97 ,
. V_138 = F_173 ,
. V_139 = F_168 ,
. V_85 = F_49 ,
} ;
F_115 ( ! F_73 ( V_38 ) && F_87 ( V_38 ) , V_38 ) ;
if ( ( V_97 & V_118 ) && ! F_96 ( V_38 ) && F_62 ( V_38 ) )
V_83 . V_86 = F_172 ;
V_80 = F_98 ( V_38 , & V_83 ) ;
if ( V_80 != V_120 && ! F_46 ( V_38 ) )
V_80 = V_76 ;
return V_80 ;
}
int F_175 ( struct V_38 * V_38 )
{
int V_80 ;
struct V_82 V_83 = {
. V_84 = F_140 ,
. V_66 = ( void * ) V_105 ,
. V_138 = F_173 ,
. V_139 = NULL ,
. V_85 = F_49 ,
} ;
F_115 ( ! F_112 ( V_38 ) || F_176 ( V_38 ) , V_38 ) ;
V_80 = F_98 ( V_38 , & V_83 ) ;
return V_80 ;
}
void F_55 ( struct V_1 * V_1 )
{
struct V_1 * V_5 = V_1 -> V_5 ;
F_4 ( V_1 ) ;
if ( V_5 != V_1 && F_53 ( & V_5 -> V_4 ) )
F_4 ( V_5 ) ;
}
static struct V_1 * F_177 ( struct V_38 * V_38 ,
struct V_82 * V_83 )
{
struct V_1 * V_1 ;
if ( V_83 -> V_85 )
return V_83 -> V_85 ( V_38 ) ;
V_1 = F_63 ( V_38 ) ;
if ( ! V_1 )
return NULL ;
F_52 ( V_1 ) ;
return V_1 ;
}
static int F_178 ( struct V_38 * V_38 , struct V_82 * V_83 )
{
struct V_1 * V_1 ;
T_3 V_45 = F_58 ( V_38 ) ;
struct V_7 * V_12 ;
int V_80 = V_71 ;
V_1 = F_177 ( V_38 , V_83 ) ;
if ( ! V_1 )
return V_80 ;
F_179 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_49 = F_59 ( V_38 , V_11 ) ;
if ( V_83 -> V_86 && V_83 -> V_86 ( V_11 , V_83 -> V_66 ) )
continue;
V_80 = V_83 -> V_84 ( V_38 , V_11 , V_49 , V_83 -> V_66 ) ;
if ( V_80 != V_71 )
break;
if ( V_83 -> V_138 && V_83 -> V_138 ( V_38 ) )
break;
}
F_54 ( V_1 ) ;
return V_80 ;
}
static int F_180 ( struct V_38 * V_38 , struct V_82 * V_83 )
{
struct V_90 * V_40 = V_38 -> V_40 ;
T_3 V_45 = F_58 ( V_38 ) ;
struct V_10 * V_11 ;
int V_80 = V_71 ;
F_115 ( ! F_112 ( V_38 ) , V_38 ) ;
if ( ! V_40 )
return V_80 ;
F_181 ( & V_40 -> V_140 ) ;
F_182 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_49 = F_59 ( V_38 , V_11 ) ;
if ( V_83 -> V_86 && V_83 -> V_86 ( V_11 , V_83 -> V_66 ) )
continue;
V_80 = V_83 -> V_84 ( V_38 , V_11 , V_49 , V_83 -> V_66 ) ;
if ( V_80 != V_71 )
goto V_138;
if ( V_83 -> V_138 && V_83 -> V_138 ( V_38 ) )
goto V_138;
}
if ( ! V_83 -> V_139 )
goto V_138;
if ( F_151 ( & V_40 -> V_141 ) )
goto V_138;
V_80 = V_83 -> V_139 ( V_38 , V_40 , V_83 -> V_66 ) ;
V_138:
F_183 ( & V_40 -> V_140 ) ;
return V_80 ;
}
int F_98 ( struct V_38 * V_38 , struct V_82 * V_83 )
{
if ( F_18 ( F_96 ( V_38 ) ) )
return F_184 ( V_38 , V_83 ) ;
else if ( F_62 ( V_38 ) )
return F_178 ( V_38 , V_83 ) ;
else
return F_180 ( V_38 , V_83 ) ;
}
static void F_185 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 , int V_92 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_111 ( ! V_1 ) ;
if ( F_62 ( V_38 ) )
return;
if ( ! V_92 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_90 * ) V_1 ;
V_38 -> V_91 = F_116 ( V_11 , V_49 ) ;
}
void F_186 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
int V_93 ;
F_111 ( ! F_112 ( V_38 ) ) ;
F_111 ( ! V_1 ) ;
V_93 = F_122 ( & V_38 -> V_94 ) ;
if ( V_93 )
F_185 ( V_38 , V_11 , V_49 , 0 ) ;
}
void F_187 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
F_111 ( V_49 < V_11 -> V_46 || V_49 >= V_11 -> V_50 ) ;
F_3 ( & V_38 -> V_94 , 0 ) ;
F_185 ( V_38 , V_11 , V_49 , 1 ) ;
}
