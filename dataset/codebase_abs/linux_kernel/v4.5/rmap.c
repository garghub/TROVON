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
static void F_58 ( void * V_36 )
{
F_59 ( V_48 ) ;
F_60 () ;
}
void F_61 ( void )
{
struct V_49 * V_50 = & V_51 -> V_50 ;
int V_52 ;
if ( ! V_50 -> V_53 )
return;
V_52 = F_62 () ;
F_63 ( V_54 , - 1UL ) ;
if ( F_64 ( V_52 , & V_50 -> V_55 ) )
F_58 ( & V_50 -> V_55 ) ;
if ( F_65 ( & V_50 -> V_55 , V_52 ) < V_56 ) {
F_66 ( & V_50 -> V_55 ,
F_58 , ( void * ) V_50 , true ) ;
}
F_67 ( & V_50 -> V_55 ) ;
V_50 -> V_53 = false ;
V_50 -> V_57 = false ;
F_68 () ;
}
void F_69 ( void )
{
struct V_49 * V_50 = & V_51 -> V_50 ;
if ( V_50 -> V_57 )
F_61 () ;
}
static void F_70 ( struct V_17 * V_18 ,
struct V_41 * V_41 , bool V_57 )
{
struct V_49 * V_50 = & V_51 -> V_50 ;
F_71 ( & V_50 -> V_55 , & V_50 -> V_55 , F_72 ( V_18 ) ) ;
V_50 -> V_53 = true ;
if ( V_57 )
V_50 -> V_57 = true ;
}
static bool F_73 ( struct V_17 * V_18 , enum V_58 V_59 )
{
bool V_60 = false ;
if ( ! ( V_59 & V_61 ) )
return false ;
if ( F_65 ( F_72 ( V_18 ) , F_62 () ) < V_56 )
V_60 = true ;
F_68 () ;
return V_60 ;
}
static void F_70 ( struct V_17 * V_18 ,
struct V_41 * V_41 , bool V_57 )
{
}
static bool F_73 ( struct V_17 * V_18 , enum V_58 V_59 )
{
return false ;
}
unsigned long F_74 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
unsigned long V_62 ;
if ( F_75 ( V_41 ) ) {
struct V_1 * V_63 = F_76 ( V_41 ) ;
if ( ! V_13 -> V_1 || ! V_63 ||
V_13 -> V_1 -> V_7 != V_63 -> V_7 )
return - V_64 ;
} else if ( V_41 -> V_43 ) {
if ( ! V_13 -> V_65 || V_13 -> V_65 -> V_66 != V_41 -> V_43 )
return - V_64 ;
} else
return - V_64 ;
V_62 = F_77 ( V_41 , V_13 ) ;
if ( F_18 ( V_62 < V_13 -> V_67 || V_62 >= V_13 -> V_68 ) )
return - V_64 ;
return V_62 ;
}
T_3 * F_78 ( struct V_17 * V_18 , unsigned long V_62 )
{
T_4 * V_69 ;
T_5 * V_70 ;
T_3 * V_71 = NULL ;
T_3 V_72 ;
V_69 = F_79 ( V_18 , V_62 ) ;
if ( ! F_80 ( * V_69 ) )
goto V_46;
V_70 = F_81 ( V_69 , V_62 ) ;
if ( ! F_82 ( * V_70 ) )
goto V_46;
V_71 = F_83 ( V_70 , V_62 ) ;
V_72 = * V_71 ;
F_84 () ;
if ( ! F_85 ( V_72 ) || F_86 ( V_72 ) )
V_71 = NULL ;
V_46:
return V_71 ;
}
T_6 * F_87 ( struct V_41 * V_41 , struct V_17 * V_18 ,
unsigned long V_62 , T_7 * * V_73 , int V_74 )
{
T_3 * V_71 ;
T_6 * V_75 ;
T_7 * V_76 ;
if ( F_18 ( F_88 ( V_41 ) ) ) {
V_75 = F_89 ( V_18 , V_62 ) ;
if ( ! V_75 )
return NULL ;
V_76 = F_90 ( F_91 ( V_41 ) , V_18 , V_75 ) ;
goto V_77;
}
V_71 = F_78 ( V_18 , V_62 ) ;
if ( ! V_71 )
return NULL ;
V_75 = F_92 ( V_71 , V_62 ) ;
if ( ! V_74 && ! F_93 ( * V_75 ) ) {
F_94 ( V_75 ) ;
return NULL ;
}
V_76 = F_95 ( V_18 , V_71 ) ;
V_77:
F_20 ( V_76 ) ;
if ( F_93 ( * V_75 ) && F_96 ( V_41 ) == F_97 ( * V_75 ) ) {
* V_73 = V_76 ;
return V_75 ;
}
F_98 ( V_75 , V_76 ) ;
return NULL ;
}
int F_99 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
unsigned long V_62 ;
T_6 * V_75 ;
T_7 * V_76 ;
V_62 = F_77 ( V_41 , V_13 ) ;
if ( F_18 ( V_62 < V_13 -> V_67 || V_62 >= V_13 -> V_68 ) )
return 0 ;
V_75 = F_100 ( V_41 , V_13 -> V_19 , V_62 , & V_76 , 1 ) ;
if ( ! V_75 )
return 0 ;
F_98 ( V_75 , V_76 ) ;
return 1 ;
}
bool F_101 ( struct V_41 * V_41 , struct V_17 * V_18 ,
unsigned long V_62 , T_3 * * V_78 ,
T_6 * * V_79 , T_7 * * V_73 )
{
T_4 * V_69 ;
T_5 * V_70 ;
T_3 * V_71 ;
T_6 * V_75 ;
T_7 * V_76 ;
if ( F_18 ( F_88 ( V_41 ) ) ) {
V_75 = F_89 ( V_18 , V_62 ) ;
if ( ! V_75 )
return false ;
V_76 = F_90 ( F_91 ( V_41 ) , V_18 , V_75 ) ;
V_71 = NULL ;
goto V_80;
}
V_69 = F_79 ( V_18 , V_62 ) ;
if ( ! F_80 ( * V_69 ) )
return false ;
V_70 = F_81 ( V_69 , V_62 ) ;
if ( ! F_82 ( * V_70 ) )
return false ;
V_71 = F_83 ( V_70 , V_62 ) ;
if ( F_86 ( * V_71 ) ) {
V_76 = F_102 ( V_18 , V_71 ) ;
if ( ! F_85 ( * V_71 ) )
goto V_81;
if ( F_18 ( ! F_86 ( * V_71 ) ) ) {
F_22 ( V_76 ) ;
goto V_82;
}
if ( F_103 ( * V_71 ) != V_41 )
goto V_81;
V_75 = NULL ;
goto V_83;
V_81:
F_22 ( V_76 ) ;
return false ;
} else {
T_3 V_72 = * V_71 ;
F_84 () ;
if ( ! F_85 ( V_72 ) || F_86 ( V_72 ) )
return false ;
}
V_82:
V_75 = F_92 ( V_71 , V_62 ) ;
if ( ! F_93 ( * V_75 ) ) {
F_94 ( V_75 ) ;
return false ;
}
V_76 = F_95 ( V_18 , V_71 ) ;
V_80:
F_20 ( V_76 ) ;
if ( ! F_93 ( * V_75 ) ) {
F_98 ( V_75 , V_76 ) ;
return false ;
}
if ( F_97 ( * V_75 ) - F_96 ( V_41 ) >= F_104 ( V_41 ) ) {
F_98 ( V_75 , V_76 ) ;
return false ;
}
V_83:
* V_79 = V_75 ;
* V_78 = V_71 ;
* V_73 = V_76 ;
return true ;
}
static int F_105 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_62 , void * V_84 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_85 * V_86 = V_84 ;
T_3 * V_71 ;
T_6 * V_75 ;
T_7 * V_76 ;
int V_87 = 0 ;
if ( ! F_101 ( V_41 , V_18 , V_62 , & V_71 , & V_75 , & V_76 ) )
return V_88 ;
if ( V_13 -> V_89 & V_90 ) {
if ( V_75 )
F_94 ( V_75 ) ;
F_22 ( V_76 ) ;
V_86 -> V_89 |= V_90 ;
return V_91 ;
}
if ( V_75 ) {
if ( F_106 ( V_13 , V_62 , V_75 ) ) {
if ( F_21 ( ! ( V_13 -> V_89 & V_92 ) ) )
V_87 ++ ;
}
F_94 ( V_75 ) ;
} else if ( F_107 ( V_93 ) ) {
if ( F_108 ( V_13 , V_62 , V_71 ) )
V_87 ++ ;
} else {
F_25 ( 1 ) ;
}
F_22 ( V_76 ) ;
if ( V_87 )
F_109 ( V_41 ) ;
if ( F_110 ( V_41 ) )
V_87 ++ ;
if ( V_87 ) {
V_86 -> V_87 ++ ;
V_86 -> V_89 |= V_13 -> V_89 ;
}
V_86 -> V_94 -- ;
if ( ! V_86 -> V_94 )
return V_95 ;
return V_88 ;
}
static bool F_111 ( struct V_12 * V_13 , void * V_84 )
{
struct V_85 * V_86 = V_84 ;
struct V_96 * V_97 = V_86 -> V_97 ;
if ( ! F_112 ( V_13 -> V_19 , V_97 ) )
return true ;
return false ;
}
int F_113 ( struct V_41 * V_41 ,
int V_98 ,
struct V_96 * V_97 ,
unsigned long * V_89 )
{
int V_99 ;
int V_100 = 0 ;
struct V_85 V_86 = {
. V_94 = F_114 ( V_41 ) ,
. V_97 = V_97 ,
} ;
struct V_101 V_102 = {
. V_103 = F_105 ,
. V_84 = ( void * ) & V_86 ,
. V_104 = F_50 ,
} ;
* V_89 = 0 ;
if ( ! F_47 ( V_41 ) )
return 0 ;
if ( ! F_115 ( V_41 ) )
return 0 ;
if ( ! V_98 && ( ! F_75 ( V_41 ) || F_116 ( V_41 ) ) ) {
V_100 = F_117 ( V_41 ) ;
if ( ! V_100 )
return 1 ;
}
if ( V_97 ) {
V_102 . V_105 = F_111 ;
}
V_99 = F_118 ( V_41 , & V_102 ) ;
* V_89 = V_86 . V_89 ;
if ( V_100 )
F_119 ( V_41 ) ;
return V_86 . V_87 ;
}
static int F_120 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_62 , void * V_84 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_6 * V_75 ;
T_7 * V_76 ;
int V_99 = 0 ;
int * V_106 = V_84 ;
V_75 = F_100 ( V_41 , V_18 , V_62 , & V_76 , 1 ) ;
if ( ! V_75 )
goto V_46;
if ( F_121 ( * V_75 ) || F_122 ( * V_75 ) ) {
T_6 V_107 ;
F_123 ( V_13 , V_62 , F_97 ( * V_75 ) ) ;
V_107 = F_124 ( V_13 , V_62 , V_75 ) ;
V_107 = F_125 ( V_107 ) ;
V_107 = F_126 ( V_107 ) ;
F_127 ( V_18 , V_62 , V_75 , V_107 ) ;
V_99 = 1 ;
}
F_98 ( V_75 , V_76 ) ;
if ( V_99 ) {
F_128 ( V_18 , V_62 ) ;
( * V_106 ) ++ ;
}
V_46:
return V_88 ;
}
static bool F_129 ( struct V_12 * V_13 , void * V_84 )
{
if ( V_13 -> V_89 & V_108 )
return false ;
return true ;
}
int F_130 ( struct V_41 * V_41 )
{
int V_106 = 0 ;
struct V_109 * V_43 ;
struct V_101 V_102 = {
. V_84 = ( void * ) & V_106 ,
. V_103 = F_120 ,
. V_105 = F_129 ,
} ;
F_38 ( ! F_131 ( V_41 ) ) ;
if ( ! F_47 ( V_41 ) )
return 0 ;
V_43 = F_132 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
F_118 ( V_41 , & V_102 ) ;
return V_106 ;
}
void F_133 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_134 ( ! F_131 ( V_41 ) , V_41 ) ;
F_135 ( ! V_1 , V_13 ) ;
F_134 ( V_41 -> V_110 != F_136 ( V_13 , V_62 ) , V_41 ) ;
V_1 = ( void * ) V_1 + V_45 ;
F_137 ( V_41 -> V_43 , (struct V_109 * ) V_1 ) ;
}
static void F_138 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 , int V_111 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_75 ( V_41 ) )
return;
if ( ! V_111 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_109 * ) V_1 ;
V_41 -> V_110 = F_136 ( V_13 , V_62 ) ;
}
static void F_139 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 )
{
#ifdef F_140
F_38 ( F_76 ( V_41 ) -> V_7 != V_13 -> V_1 -> V_7 ) ;
F_38 ( F_141 ( V_41 ) != F_136 ( V_13 , V_62 ) ) ;
#endif
}
void F_142 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 , bool V_112 )
{
F_143 ( V_41 , V_13 , V_62 , V_112 ? V_113 : 0 ) ;
}
void F_143 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 , int V_59 )
{
bool V_112 = V_59 & V_113 ;
bool V_114 ;
if ( V_112 ) {
T_8 * V_94 ;
F_134 ( ! F_131 ( V_41 ) , V_41 ) ;
F_134 ( ! F_144 ( V_41 ) , V_41 ) ;
V_94 = F_145 ( V_41 ) ;
V_114 = F_146 ( V_94 ) ;
} else {
V_114 = F_146 ( & V_41 -> V_115 ) ;
}
if ( V_114 ) {
int V_116 = V_112 ? F_104 ( V_41 ) : 1 ;
if ( V_112 ) {
F_147 ( V_41 ,
V_117 ) ;
}
F_148 ( F_149 ( V_41 ) , V_118 , V_116 ) ;
}
if ( F_18 ( F_116 ( V_41 ) ) )
return;
F_134 ( ! F_131 ( V_41 ) , V_41 ) ;
if ( V_114 )
F_138 ( V_41 , V_13 , V_62 ,
V_59 & V_119 ) ;
else
F_139 ( V_41 , V_13 , V_62 ) ;
}
void F_150 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 , bool V_112 )
{
int V_116 = V_112 ? F_104 ( V_41 ) : 1 ;
F_135 ( V_62 < V_13 -> V_67 || V_62 >= V_13 -> V_68 , V_13 ) ;
F_151 ( V_41 ) ;
if ( V_112 ) {
F_134 ( ! F_144 ( V_41 ) , V_41 ) ;
F_3 ( F_145 ( V_41 ) , 0 ) ;
F_147 ( V_41 , V_117 ) ;
} else {
F_134 ( F_152 ( V_41 ) , V_41 ) ;
F_3 ( & V_41 -> V_115 , 0 ) ;
}
F_148 ( F_149 ( V_41 ) , V_118 , V_116 ) ;
F_138 ( V_41 , V_13 , V_62 , 1 ) ;
}
void F_153 ( struct V_41 * V_41 )
{
struct V_96 * V_97 ;
V_97 = F_154 ( V_41 ) ;
if ( F_146 ( & V_41 -> V_115 ) ) {
F_147 ( V_41 , V_120 ) ;
F_155 ( V_97 , V_121 ) ;
}
F_156 ( V_97 ) ;
}
static void F_157 ( struct V_41 * V_41 )
{
struct V_96 * V_97 ;
V_97 = F_154 ( V_41 ) ;
if ( F_18 ( F_88 ( V_41 ) ) ) {
F_158 ( F_145 ( V_41 ) ) ;
goto V_46;
}
if ( ! F_159 ( - 1 , & V_41 -> V_115 ) )
goto V_46;
F_160 ( V_41 , V_120 ) ;
F_161 ( V_97 , V_121 ) ;
if ( F_18 ( F_162 ( V_41 ) ) )
F_163 ( V_41 ) ;
V_46:
F_156 ( V_97 ) ;
}
static void F_164 ( struct V_41 * V_41 )
{
int V_122 , V_116 ;
if ( ! F_159 ( - 1 , F_145 ( V_41 ) ) )
return;
if ( F_18 ( F_88 ( V_41 ) ) )
return;
if ( ! F_107 ( V_93 ) )
return;
F_160 ( V_41 , V_117 ) ;
if ( F_165 ( V_41 ) ) {
for ( V_122 = 0 , V_116 = 0 ; V_122 < V_123 ; V_122 ++ ) {
if ( F_159 ( - 1 , & V_41 [ V_122 ] . V_115 ) )
V_116 ++ ;
}
} else {
V_116 = V_123 ;
}
if ( F_18 ( F_162 ( V_41 ) ) )
F_163 ( V_41 ) ;
if ( V_116 ) {
F_148 ( F_149 ( V_41 ) , V_118 , - V_116 ) ;
F_166 ( V_41 ) ;
}
}
void F_167 ( struct V_41 * V_41 , bool V_112 )
{
if ( ! F_75 ( V_41 ) ) {
F_134 ( V_112 && ! F_88 ( V_41 ) , V_41 ) ;
F_157 ( V_41 ) ;
return;
}
if ( V_112 )
return F_164 ( V_41 ) ;
if ( ! F_159 ( - 1 , & V_41 -> V_115 ) )
return;
F_160 ( V_41 , V_118 ) ;
if ( F_18 ( F_162 ( V_41 ) ) )
F_163 ( V_41 ) ;
if ( F_152 ( V_41 ) )
F_166 ( F_168 ( V_41 ) ) ;
}
static int F_169 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_62 , void * V_84 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_6 * V_75 ;
T_6 V_124 ;
T_7 * V_76 ;
int V_99 = V_88 ;
struct V_125 * V_126 = V_84 ;
enum V_58 V_59 = V_126 -> V_59 ;
if ( ( V_59 & V_127 ) && ! ( V_13 -> V_89 & V_90 ) )
goto V_46;
V_75 = F_100 ( V_41 , V_18 , V_62 , & V_76 , 0 ) ;
if ( ! V_75 )
goto V_46;
if ( ! ( V_59 & V_128 ) ) {
if ( V_13 -> V_89 & V_90 ) {
F_170 ( V_41 ) ;
V_99 = V_129 ;
goto V_130;
}
if ( V_59 & V_127 )
goto V_130;
}
if ( ! ( V_59 & V_131 ) ) {
if ( F_106 ( V_13 , V_62 , V_75 ) ) {
V_99 = V_91 ;
goto V_130;
}
}
F_123 ( V_13 , V_62 , F_96 ( V_41 ) ) ;
if ( F_73 ( V_18 , V_59 ) ) {
V_124 = F_171 ( V_18 , V_62 , V_75 ) ;
F_70 ( V_18 , V_41 , F_121 ( V_124 ) ) ;
} else {
V_124 = F_124 ( V_13 , V_62 , V_75 ) ;
}
if ( F_121 ( V_124 ) )
F_172 ( V_41 ) ;
F_173 ( V_18 ) ;
if ( F_174 ( V_41 ) && ! ( V_59 & V_132 ) ) {
if ( F_88 ( V_41 ) ) {
F_175 ( 1 << F_176 ( V_41 ) , V_18 ) ;
} else {
F_177 ( V_18 , F_178 ( V_41 ) ) ;
}
F_127 ( V_18 , V_62 , V_75 ,
F_179 ( F_180 ( V_41 ) ) ) ;
} else if ( F_181 ( V_124 ) ) {
F_177 ( V_18 , F_178 ( V_41 ) ) ;
} else if ( F_107 ( V_133 ) && ( V_59 & V_134 ) ) {
T_9 V_107 ;
T_6 V_135 ;
V_107 = F_182 ( V_41 , F_122 ( V_124 ) ) ;
V_135 = F_179 ( V_107 ) ;
if ( F_183 ( V_124 ) )
V_135 = F_184 ( V_135 ) ;
F_127 ( V_18 , V_62 , V_75 , V_135 ) ;
} else if ( F_75 ( V_41 ) ) {
T_9 V_107 = { . V_136 = F_185 (page) } ;
T_6 V_135 ;
F_134 ( ! F_186 ( V_41 ) , V_41 ) ;
if ( ! F_187 ( V_41 ) && ( V_59 & V_137 ) ) {
F_177 ( V_18 , V_138 ) ;
V_126 -> V_139 ++ ;
goto V_140;
}
if ( F_188 ( V_107 ) < 0 ) {
F_127 ( V_18 , V_62 , V_75 , V_124 ) ;
V_99 = V_91 ;
goto V_130;
}
if ( F_189 ( & V_18 -> V_141 ) ) {
F_20 ( & V_142 ) ;
if ( F_189 ( & V_18 -> V_141 ) )
F_15 ( & V_18 -> V_141 , & V_143 . V_141 ) ;
F_22 ( & V_142 ) ;
}
F_177 ( V_18 , V_138 ) ;
F_190 ( V_18 , V_144 ) ;
V_135 = F_179 ( V_107 ) ;
if ( F_183 ( V_124 ) )
V_135 = F_184 ( V_135 ) ;
F_127 ( V_18 , V_62 , V_75 , V_135 ) ;
} else
F_177 ( V_18 , F_191 ( V_41 ) ) ;
V_140:
F_167 ( V_41 , F_88 ( V_41 ) ) ;
F_192 ( V_41 ) ;
V_130:
F_98 ( V_75 , V_76 ) ;
if ( V_99 != V_91 && V_99 != V_129 && ! ( V_59 & V_127 ) )
F_128 ( V_18 , V_62 ) ;
V_46:
return V_99 ;
}
bool F_193 ( struct V_12 * V_13 )
{
int V_145 = V_13 -> V_89 & ( V_146 | V_147 ) ;
if ( ! V_145 )
return false ;
if ( ( V_13 -> V_89 & V_148 ) ==
V_148 )
return true ;
return false ;
}
static bool F_194 ( struct V_12 * V_13 , void * V_84 )
{
return F_193 ( V_13 ) ;
}
static int F_195 ( struct V_41 * V_41 )
{
return ! F_47 ( V_41 ) ;
}
int F_196 ( struct V_41 * V_41 , enum V_58 V_59 )
{
int V_99 ;
struct V_125 V_126 = {
. V_59 = V_59 ,
. V_139 = 0 ,
} ;
struct V_101 V_102 = {
. V_103 = F_169 ,
. V_84 = & V_126 ,
. V_149 = F_195 ,
. V_104 = F_50 ,
} ;
F_134 ( ! F_88 ( V_41 ) && F_144 ( V_41 ) , V_41 ) ;
if ( ( V_59 & V_134 ) && ! F_116 ( V_41 ) && F_75 ( V_41 ) )
V_102 . V_105 = F_194 ;
V_99 = F_118 ( V_41 , & V_102 ) ;
if ( V_99 != V_129 && ! F_47 ( V_41 ) ) {
V_99 = V_95 ;
if ( V_126 . V_139 && ! F_187 ( V_41 ) )
V_99 = V_150 ;
}
return V_99 ;
}
int F_197 ( struct V_41 * V_41 )
{
int V_99 ;
struct V_125 V_126 = {
. V_59 = V_127 ,
. V_139 = 0 ,
} ;
struct V_101 V_102 = {
. V_103 = F_169 ,
. V_84 = & V_126 ,
. V_149 = F_195 ,
. V_104 = F_50 ,
} ;
F_134 ( ! F_131 ( V_41 ) || F_198 ( V_41 ) , V_41 ) ;
V_99 = F_118 ( V_41 , & V_102 ) ;
return V_99 ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_1 * V_7 = V_1 -> V_7 ;
F_4 ( V_1 ) ;
if ( V_7 != V_1 && F_54 ( & V_7 -> V_4 ) )
F_4 ( V_7 ) ;
}
static struct V_1 * F_199 ( struct V_41 * V_41 ,
struct V_101 * V_102 )
{
struct V_1 * V_1 ;
if ( V_102 -> V_104 )
return V_102 -> V_104 ( V_41 ) ;
V_1 = F_76 ( V_41 ) ;
if ( ! V_1 )
return NULL ;
F_53 ( V_1 ) ;
return V_1 ;
}
static int F_200 ( struct V_41 * V_41 , struct V_101 * V_102 )
{
struct V_1 * V_1 ;
T_10 V_151 ;
struct V_9 * V_14 ;
int V_99 = V_88 ;
V_1 = F_199 ( V_41 , V_102 ) ;
if ( ! V_1 )
return V_99 ;
V_151 = F_141 ( V_41 ) ;
F_201 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_12 * V_13 = V_14 -> V_13 ;
unsigned long V_62 = F_202 ( V_41 , V_13 ) ;
F_203 () ;
if ( V_102 -> V_105 && V_102 -> V_105 ( V_13 , V_102 -> V_84 ) )
continue;
V_99 = V_102 -> V_103 ( V_41 , V_13 , V_62 , V_102 -> V_84 ) ;
if ( V_99 != V_88 )
break;
if ( V_102 -> V_149 && V_102 -> V_149 ( V_41 ) )
break;
}
F_55 ( V_1 ) ;
return V_99 ;
}
static int F_204 ( struct V_41 * V_41 , struct V_101 * V_102 )
{
struct V_109 * V_43 = V_41 -> V_43 ;
T_10 V_151 ;
struct V_12 * V_13 ;
int V_99 = V_88 ;
F_134 ( ! F_131 ( V_41 ) , V_41 ) ;
if ( ! V_43 )
return V_99 ;
V_151 = F_141 ( V_41 ) ;
F_205 ( V_43 ) ;
F_206 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_62 = F_202 ( V_41 , V_13 ) ;
F_203 () ;
if ( V_102 -> V_105 && V_102 -> V_105 ( V_13 , V_102 -> V_84 ) )
continue;
V_99 = V_102 -> V_103 ( V_41 , V_13 , V_62 , V_102 -> V_84 ) ;
if ( V_99 != V_88 )
goto V_149;
if ( V_102 -> V_149 && V_102 -> V_149 ( V_41 ) )
goto V_149;
}
V_149:
F_207 ( V_43 ) ;
return V_99 ;
}
int F_118 ( struct V_41 * V_41 , struct V_101 * V_102 )
{
if ( F_18 ( F_116 ( V_41 ) ) )
return F_208 ( V_41 , V_102 ) ;
else if ( F_75 ( V_41 ) )
return F_200 ( V_41 , V_102 ) ;
else
return F_204 ( V_41 , V_102 ) ;
}
static void F_209 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 , int V_111 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_38 ( ! V_1 ) ;
if ( F_75 ( V_41 ) )
return;
if ( ! V_111 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_109 * ) V_1 ;
V_41 -> V_110 = F_136 ( V_13 , V_62 ) ;
}
void F_210 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
int V_114 ;
F_38 ( ! F_131 ( V_41 ) ) ;
F_38 ( ! V_1 ) ;
V_114 = F_146 ( F_145 ( V_41 ) ) ;
if ( V_114 )
F_209 ( V_41 , V_13 , V_62 , 0 ) ;
}
void F_211 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_62 )
{
F_38 ( V_62 < V_13 -> V_67 || V_62 >= V_13 -> V_68 ) ;
F_3 ( F_145 ( V_41 ) , 0 ) ;
F_209 ( V_41 , V_13 , V_62 , 1 ) ;
}
