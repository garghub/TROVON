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
static void F_69 ( struct V_17 * V_18 ,
struct V_41 * V_41 , bool V_58 )
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
static void F_69 ( struct V_17 * V_18 ,
struct V_41 * V_41 , bool V_58 )
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
if ( F_18 ( V_63 < V_13 -> V_68 || V_63 >= V_13 -> V_69 ) )
return - V_65 ;
return V_63 ;
}
T_3 * F_77 ( struct V_17 * V_18 , unsigned long V_63 )
{
T_4 * V_70 ;
T_5 * V_71 ;
T_3 * V_72 = NULL ;
T_3 V_73 ;
V_70 = F_78 ( V_18 , V_63 ) ;
if ( ! F_79 ( * V_70 ) )
goto V_46;
V_71 = F_80 ( V_70 , V_63 ) ;
if ( ! F_81 ( * V_71 ) )
goto V_46;
V_72 = F_82 ( V_71 , V_63 ) ;
V_73 = * V_72 ;
F_83 () ;
if ( ! F_84 ( V_73 ) || F_85 ( V_73 ) )
V_72 = NULL ;
V_46:
return V_72 ;
}
T_6 * F_86 ( struct V_41 * V_41 , struct V_17 * V_18 ,
unsigned long V_63 , T_7 * * V_74 , int V_75 )
{
T_3 * V_72 ;
T_6 * V_76 ;
T_7 * V_77 ;
if ( F_18 ( F_87 ( V_41 ) ) ) {
V_76 = F_88 ( V_18 , V_63 ) ;
if ( ! V_76 )
return NULL ;
V_77 = F_89 ( F_90 ( V_41 ) , V_18 , V_76 ) ;
goto V_78;
}
V_72 = F_77 ( V_18 , V_63 ) ;
if ( ! V_72 )
return NULL ;
V_76 = F_91 ( V_72 , V_63 ) ;
if ( ! V_75 && ! F_92 ( * V_76 ) ) {
F_93 ( V_76 ) ;
return NULL ;
}
V_77 = F_94 ( V_18 , V_72 ) ;
V_78:
F_20 ( V_77 ) ;
if ( F_92 ( * V_76 ) && F_95 ( V_41 ) == F_96 ( * V_76 ) ) {
* V_74 = V_77 ;
return V_76 ;
}
F_97 ( V_76 , V_77 ) ;
return NULL ;
}
int F_98 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
unsigned long V_63 ;
T_6 * V_76 ;
T_7 * V_77 ;
V_63 = F_76 ( V_41 , V_13 ) ;
if ( F_18 ( V_63 < V_13 -> V_68 || V_63 >= V_13 -> V_69 ) )
return 0 ;
V_76 = F_99 ( V_41 , V_13 -> V_19 , V_63 , & V_77 , 1 ) ;
if ( ! V_76 )
return 0 ;
F_97 ( V_76 , V_77 ) ;
return 1 ;
}
bool F_100 ( struct V_41 * V_41 , struct V_17 * V_18 ,
unsigned long V_63 , T_3 * * V_79 ,
T_6 * * V_80 , T_7 * * V_74 )
{
T_4 * V_70 ;
T_5 * V_71 ;
T_3 * V_72 ;
T_6 * V_76 ;
T_7 * V_77 ;
if ( F_18 ( F_87 ( V_41 ) ) ) {
V_76 = F_88 ( V_18 , V_63 ) ;
if ( ! V_76 )
return false ;
V_77 = F_89 ( F_90 ( V_41 ) , V_18 , V_76 ) ;
V_72 = NULL ;
goto V_81;
}
V_70 = F_78 ( V_18 , V_63 ) ;
if ( ! F_79 ( * V_70 ) )
return false ;
V_71 = F_80 ( V_70 , V_63 ) ;
if ( ! F_81 ( * V_71 ) )
return false ;
V_72 = F_82 ( V_71 , V_63 ) ;
if ( F_85 ( * V_72 ) ) {
V_77 = F_101 ( V_18 , V_72 ) ;
if ( ! F_84 ( * V_72 ) )
goto V_82;
if ( F_18 ( ! F_85 ( * V_72 ) ) ) {
F_22 ( V_77 ) ;
goto V_83;
}
if ( F_102 ( * V_72 ) != V_41 )
goto V_82;
V_76 = NULL ;
goto V_84;
V_82:
F_22 ( V_77 ) ;
return false ;
} else {
T_3 V_73 = * V_72 ;
F_83 () ;
if ( ! F_84 ( V_73 ) || F_85 ( V_73 ) )
return false ;
}
V_83:
V_76 = F_91 ( V_72 , V_63 ) ;
if ( ! F_92 ( * V_76 ) ) {
F_93 ( V_76 ) ;
return false ;
}
V_77 = F_94 ( V_18 , V_72 ) ;
V_81:
F_20 ( V_77 ) ;
if ( ! F_92 ( * V_76 ) ) {
F_97 ( V_76 , V_77 ) ;
return false ;
}
if ( F_96 ( * V_76 ) - F_95 ( V_41 ) >= F_103 ( V_41 ) ) {
F_97 ( V_76 , V_77 ) ;
return false ;
}
V_84:
* V_80 = V_76 ;
* V_79 = V_72 ;
* V_74 = V_77 ;
return true ;
}
static int F_104 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_63 , void * V_85 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_86 * V_87 = V_85 ;
T_3 * V_72 ;
T_6 * V_76 ;
T_7 * V_77 ;
int V_88 = 0 ;
if ( ! F_100 ( V_41 , V_18 , V_63 , & V_72 , & V_76 , & V_77 ) )
return V_89 ;
if ( V_13 -> V_90 & V_91 ) {
if ( V_76 )
F_93 ( V_76 ) ;
F_22 ( V_77 ) ;
V_87 -> V_90 |= V_91 ;
return V_92 ;
}
if ( V_76 ) {
if ( F_105 ( V_13 , V_63 , V_76 ) ) {
if ( F_21 ( ! ( V_13 -> V_90 & V_93 ) ) )
V_88 ++ ;
}
F_93 ( V_76 ) ;
} else if ( F_106 ( V_94 ) ) {
if ( F_107 ( V_13 , V_63 , V_72 ) )
V_88 ++ ;
} else {
F_25 ( 1 ) ;
}
F_22 ( V_77 ) ;
if ( V_88 )
F_108 ( V_41 ) ;
if ( F_109 ( V_41 ) )
V_88 ++ ;
if ( V_88 ) {
V_87 -> V_88 ++ ;
V_87 -> V_90 |= V_13 -> V_90 ;
}
V_87 -> V_95 -- ;
if ( ! V_87 -> V_95 )
return V_96 ;
return V_89 ;
}
static bool F_110 ( struct V_12 * V_13 , void * V_85 )
{
struct V_86 * V_87 = V_85 ;
struct V_97 * V_98 = V_87 -> V_98 ;
if ( ! F_111 ( V_13 -> V_19 , V_98 ) )
return true ;
return false ;
}
int F_112 ( struct V_41 * V_41 ,
int V_99 ,
struct V_97 * V_98 ,
unsigned long * V_90 )
{
int V_100 ;
int V_101 = 0 ;
struct V_86 V_87 = {
. V_95 = F_113 ( V_41 ) ,
. V_98 = V_98 ,
} ;
struct V_102 V_103 = {
. V_104 = F_104 ,
. V_85 = ( void * ) & V_87 ,
. V_105 = F_50 ,
} ;
* V_90 = 0 ;
if ( ! F_47 ( V_41 ) )
return 0 ;
if ( ! F_114 ( V_41 ) )
return 0 ;
if ( ! V_99 && ( ! F_74 ( V_41 ) || F_115 ( V_41 ) ) ) {
V_101 = F_116 ( V_41 ) ;
if ( ! V_101 )
return 1 ;
}
if ( V_98 ) {
V_103 . V_106 = F_110 ;
}
V_100 = F_117 ( V_41 , & V_103 ) ;
* V_90 = V_87 . V_90 ;
if ( V_101 )
F_118 ( V_41 ) ;
return V_87 . V_88 ;
}
static int F_119 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_63 , void * V_85 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_6 * V_76 ;
T_7 * V_77 ;
int V_100 = 0 ;
int * V_107 = V_85 ;
V_76 = F_99 ( V_41 , V_18 , V_63 , & V_77 , 1 ) ;
if ( ! V_76 )
goto V_46;
if ( F_120 ( * V_76 ) || F_121 ( * V_76 ) ) {
T_6 V_108 ;
F_122 ( V_13 , V_63 , F_96 ( * V_76 ) ) ;
V_108 = F_123 ( V_13 , V_63 , V_76 ) ;
V_108 = F_124 ( V_108 ) ;
V_108 = F_125 ( V_108 ) ;
F_126 ( V_18 , V_63 , V_76 , V_108 ) ;
V_100 = 1 ;
}
F_97 ( V_76 , V_77 ) ;
if ( V_100 ) {
F_127 ( V_18 , V_63 ) ;
( * V_107 ) ++ ;
}
V_46:
return V_89 ;
}
static bool F_128 ( struct V_12 * V_13 , void * V_85 )
{
if ( V_13 -> V_90 & V_109 )
return false ;
return true ;
}
int F_129 ( struct V_41 * V_41 )
{
int V_107 = 0 ;
struct V_110 * V_43 ;
struct V_102 V_103 = {
. V_85 = ( void * ) & V_107 ,
. V_104 = F_119 ,
. V_106 = F_128 ,
} ;
F_130 ( ! F_131 ( V_41 ) ) ;
if ( ! F_47 ( V_41 ) )
return 0 ;
V_43 = F_132 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
F_117 ( V_41 , & V_103 ) ;
return V_107 ;
}
void F_133 ( struct V_41 * V_41 , struct V_12 * V_13 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
V_41 = F_134 ( V_41 ) ;
F_135 ( ! F_131 ( V_41 ) , V_41 ) ;
F_136 ( ! V_1 , V_13 ) ;
V_1 = ( void * ) V_1 + V_45 ;
F_137 ( V_41 -> V_43 , (struct V_110 * ) V_1 ) ;
}
static void F_138 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , int V_111 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_130 ( ! V_1 ) ;
if ( F_74 ( V_41 ) )
return;
if ( ! V_111 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_110 * ) V_1 ;
V_41 -> V_112 = F_139 ( V_13 , V_63 ) ;
}
static void F_140 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 )
{
#ifdef F_141
F_130 ( F_75 ( V_41 ) -> V_7 != V_13 -> V_1 -> V_7 ) ;
F_130 ( F_142 ( V_41 ) != F_139 ( V_13 , V_63 ) ) ;
#endif
}
void F_143 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , bool V_113 )
{
F_144 ( V_41 , V_13 , V_63 , V_113 ? V_114 : 0 ) ;
}
void F_144 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , int V_60 )
{
bool V_113 = V_60 & V_114 ;
bool V_115 ;
if ( V_113 ) {
T_8 * V_95 ;
F_135 ( ! F_131 ( V_41 ) , V_41 ) ;
F_135 ( ! F_145 ( V_41 ) , V_41 ) ;
V_95 = F_146 ( V_41 ) ;
V_115 = F_147 ( V_95 ) ;
} else {
V_115 = F_147 ( & V_41 -> V_116 ) ;
}
if ( V_115 ) {
int V_117 = V_113 ? F_103 ( V_41 ) : 1 ;
if ( V_113 )
F_148 ( V_41 , V_118 ) ;
F_149 ( F_150 ( V_41 ) , V_119 , V_117 ) ;
}
if ( F_18 ( F_115 ( V_41 ) ) )
return;
F_135 ( ! F_131 ( V_41 ) , V_41 ) ;
if ( V_115 )
F_138 ( V_41 , V_13 , V_63 ,
V_60 & V_120 ) ;
else
F_140 ( V_41 , V_13 , V_63 ) ;
}
void F_151 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , bool V_113 )
{
int V_117 = V_113 ? F_103 ( V_41 ) : 1 ;
F_136 ( V_63 < V_13 -> V_68 || V_63 >= V_13 -> V_69 , V_13 ) ;
F_152 ( V_41 ) ;
if ( V_113 ) {
F_135 ( ! F_145 ( V_41 ) , V_41 ) ;
F_3 ( F_146 ( V_41 ) , 0 ) ;
F_148 ( V_41 , V_118 ) ;
} else {
F_135 ( F_153 ( V_41 ) , V_41 ) ;
F_3 ( & V_41 -> V_116 , 0 ) ;
}
F_149 ( F_150 ( V_41 ) , V_119 , V_117 ) ;
F_138 ( V_41 , V_13 , V_63 , 1 ) ;
}
void F_154 ( struct V_41 * V_41 , bool V_113 )
{
int V_121 , V_117 = 1 ;
F_135 ( V_113 && ! F_145 ( V_41 ) , V_41 ) ;
F_155 ( V_41 ) ;
if ( V_113 && F_145 ( V_41 ) ) {
for ( V_121 = 0 , V_117 = 0 ; V_121 < V_122 ; V_121 ++ ) {
if ( F_147 ( & V_41 [ V_121 ] . V_116 ) )
V_117 ++ ;
}
if ( ! F_147 ( F_146 ( V_41 ) ) )
goto V_46;
F_135 ( ! F_156 ( V_41 ) , V_41 ) ;
F_148 ( V_41 , V_123 ) ;
} else {
if ( F_153 ( V_41 ) && F_132 ( V_41 ) ) {
F_157 ( ! F_131 ( V_41 ) ) ;
F_158 ( F_134 ( V_41 ) ) ;
if ( F_159 ( V_41 ) )
F_160 ( F_134 ( V_41 ) ) ;
}
if ( ! F_147 ( & V_41 -> V_116 ) )
goto V_46;
}
F_149 ( F_150 ( V_41 ) , V_124 , V_117 ) ;
F_161 ( V_41 , V_125 ) ;
V_46:
F_162 ( V_41 ) ;
}
static void F_163 ( struct V_41 * V_41 , bool V_113 )
{
int V_121 , V_117 = 1 ;
F_135 ( V_113 && ! F_164 ( V_41 ) , V_41 ) ;
F_155 ( V_41 ) ;
if ( F_18 ( F_87 ( V_41 ) ) ) {
F_165 ( F_146 ( V_41 ) ) ;
goto V_46;
}
if ( V_113 && F_145 ( V_41 ) ) {
for ( V_121 = 0 , V_117 = 0 ; V_121 < V_122 ; V_121 ++ ) {
if ( F_166 ( - 1 , & V_41 [ V_121 ] . V_116 ) )
V_117 ++ ;
}
if ( ! F_166 ( - 1 , F_146 ( V_41 ) ) )
goto V_46;
F_135 ( ! F_156 ( V_41 ) , V_41 ) ;
F_167 ( V_41 , V_123 ) ;
} else {
if ( ! F_166 ( - 1 , & V_41 -> V_116 ) )
goto V_46;
}
F_149 ( F_150 ( V_41 ) , V_124 , - V_117 ) ;
F_168 ( V_41 , V_125 ) ;
if ( F_18 ( F_159 ( V_41 ) ) )
F_160 ( V_41 ) ;
V_46:
F_162 ( V_41 ) ;
}
static void F_169 ( struct V_41 * V_41 )
{
int V_121 , V_117 ;
if ( ! F_166 ( - 1 , F_146 ( V_41 ) ) )
return;
if ( F_18 ( F_87 ( V_41 ) ) )
return;
if ( ! F_106 ( V_94 ) )
return;
F_167 ( V_41 , V_118 ) ;
if ( F_170 ( V_41 ) ) {
for ( V_121 = 0 , V_117 = 0 ; V_121 < V_122 ; V_121 ++ ) {
if ( F_166 ( - 1 , & V_41 [ V_121 ] . V_116 ) )
V_117 ++ ;
}
} else {
V_117 = V_122 ;
}
if ( F_18 ( F_159 ( V_41 ) ) )
F_160 ( V_41 ) ;
if ( V_117 ) {
F_149 ( F_150 ( V_41 ) , V_119 , - V_117 ) ;
F_171 ( V_41 ) ;
}
}
void F_172 ( struct V_41 * V_41 , bool V_113 )
{
if ( ! F_74 ( V_41 ) )
return F_163 ( V_41 , V_113 ) ;
if ( V_113 )
return F_169 ( V_41 ) ;
if ( ! F_166 ( - 1 , & V_41 -> V_116 ) )
return;
F_167 ( V_41 , V_119 ) ;
if ( F_18 ( F_159 ( V_41 ) ) )
F_160 ( V_41 ) ;
if ( F_153 ( V_41 ) )
F_171 ( F_134 ( V_41 ) ) ;
}
static int F_173 ( struct V_41 * V_41 , struct V_12 * V_13 ,
unsigned long V_63 , void * V_85 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_6 * V_76 ;
T_6 V_126 ;
T_7 * V_77 ;
int V_100 = V_89 ;
struct V_127 * V_128 = V_85 ;
enum V_59 V_60 = V_128 -> V_60 ;
if ( ( V_60 & V_129 ) && ! ( V_13 -> V_90 & V_91 ) )
goto V_46;
if ( V_60 & V_130 ) {
F_174 ( V_13 , V_63 ,
V_60 & V_131 , V_41 ) ;
if ( F_175 ( V_41 ) == 0 )
goto V_46;
}
V_76 = F_99 ( V_41 , V_18 , V_63 , & V_77 ,
F_153 ( V_41 ) ) ;
if ( ! V_76 )
goto V_46;
if ( ! ( V_60 & V_132 ) ) {
if ( V_13 -> V_90 & V_91 ) {
if ( ! F_153 ( V_41 ) ) {
F_176 ( V_41 ) ;
}
V_100 = V_133 ;
goto V_134;
}
if ( V_60 & V_129 )
goto V_134;
}
if ( ! ( V_60 & V_135 ) ) {
if ( F_105 ( V_13 , V_63 , V_76 ) ) {
V_100 = V_92 ;
goto V_134;
}
}
F_122 ( V_13 , V_63 , F_95 ( V_41 ) ) ;
if ( F_72 ( V_18 , V_60 ) ) {
V_126 = F_177 ( V_18 , V_63 , V_76 ) ;
F_69 ( V_18 , V_41 , F_120 ( V_126 ) ) ;
} else {
V_126 = F_123 ( V_13 , V_63 , V_76 ) ;
}
if ( F_120 ( V_126 ) )
F_178 ( V_41 ) ;
F_179 ( V_18 ) ;
if ( F_180 ( V_41 ) && ! ( V_60 & V_136 ) ) {
if ( F_87 ( V_41 ) ) {
F_181 ( 1 << F_182 ( V_41 ) , V_18 ) ;
} else {
F_183 ( V_18 , F_184 ( V_41 ) ) ;
}
F_126 ( V_18 , V_63 , V_76 ,
F_185 ( F_186 ( V_41 ) ) ) ;
} else if ( F_187 ( V_126 ) ) {
F_183 ( V_18 , F_184 ( V_41 ) ) ;
} else if ( F_106 ( V_137 ) && ( V_60 & V_131 ) ) {
T_9 V_108 ;
T_6 V_138 ;
V_108 = F_188 ( V_41 , F_121 ( V_126 ) ) ;
V_138 = F_185 ( V_108 ) ;
if ( F_189 ( V_126 ) )
V_138 = F_190 ( V_138 ) ;
F_126 ( V_18 , V_63 , V_76 , V_138 ) ;
} else if ( F_74 ( V_41 ) ) {
T_9 V_108 = { . V_139 = F_191 (page) } ;
T_6 V_138 ;
F_135 ( ! F_192 ( V_41 ) , V_41 ) ;
if ( ! F_193 ( V_41 ) && ( V_60 & V_140 ) ) {
F_183 ( V_18 , V_141 ) ;
V_128 -> V_142 ++ ;
goto V_143;
}
if ( F_194 ( V_108 ) < 0 ) {
F_126 ( V_18 , V_63 , V_76 , V_126 ) ;
V_100 = V_92 ;
goto V_134;
}
if ( F_195 ( & V_18 -> V_144 ) ) {
F_20 ( & V_145 ) ;
if ( F_195 ( & V_18 -> V_144 ) )
F_15 ( & V_18 -> V_144 , & V_146 . V_144 ) ;
F_22 ( & V_145 ) ;
}
F_183 ( V_18 , V_141 ) ;
F_196 ( V_18 , V_147 ) ;
V_138 = F_185 ( V_108 ) ;
if ( F_189 ( V_126 ) )
V_138 = F_190 ( V_138 ) ;
F_126 ( V_18 , V_63 , V_76 , V_138 ) ;
} else
F_183 ( V_18 , F_197 ( V_41 ) ) ;
V_143:
F_172 ( V_41 , F_87 ( V_41 ) ) ;
F_198 ( V_41 ) ;
V_134:
F_97 ( V_76 , V_77 ) ;
if ( V_100 != V_92 && V_100 != V_133 && ! ( V_60 & V_129 ) )
F_127 ( V_18 , V_63 ) ;
V_46:
return V_100 ;
}
bool F_199 ( struct V_12 * V_13 )
{
int V_148 = V_13 -> V_90 & ( V_149 | V_150 ) ;
if ( ! V_148 )
return false ;
if ( ( V_13 -> V_90 & V_151 ) ==
V_151 )
return true ;
return false ;
}
static bool F_200 ( struct V_12 * V_13 , void * V_85 )
{
return F_199 ( V_13 ) ;
}
static int F_201 ( struct V_41 * V_41 )
{
return ! F_175 ( V_41 ) ;
}
int F_202 ( struct V_41 * V_41 , enum V_59 V_60 )
{
int V_100 ;
struct V_127 V_128 = {
. V_60 = V_60 ,
. V_142 = 0 ,
} ;
struct V_102 V_103 = {
. V_104 = F_173 ,
. V_85 = & V_128 ,
. V_152 = F_201 ,
. V_105 = F_50 ,
} ;
if ( ( V_60 & V_131 ) && ! F_115 ( V_41 ) && F_74 ( V_41 ) )
V_103 . V_106 = F_200 ;
if ( V_60 & V_153 )
V_100 = F_203 ( V_41 , & V_103 ) ;
else
V_100 = F_117 ( V_41 , & V_103 ) ;
if ( V_100 != V_133 && ! F_175 ( V_41 ) ) {
V_100 = V_96 ;
if ( V_128 . V_142 && ! F_193 ( V_41 ) )
V_100 = V_154 ;
}
return V_100 ;
}
static int F_204 ( struct V_41 * V_41 )
{
return ! F_47 ( V_41 ) ;
}
int F_205 ( struct V_41 * V_41 )
{
int V_100 ;
struct V_127 V_128 = {
. V_60 = V_129 ,
. V_142 = 0 ,
} ;
struct V_102 V_103 = {
. V_104 = F_173 ,
. V_85 = & V_128 ,
. V_152 = F_204 ,
. V_105 = F_50 ,
} ;
F_135 ( ! F_131 ( V_41 ) || F_206 ( V_41 ) , V_41 ) ;
V_100 = F_117 ( V_41 , & V_103 ) ;
return V_100 ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_1 * V_7 = V_1 -> V_7 ;
F_4 ( V_1 ) ;
if ( V_7 != V_1 && F_54 ( & V_7 -> V_4 ) )
F_4 ( V_7 ) ;
}
static struct V_1 * F_207 ( struct V_41 * V_41 ,
struct V_102 * V_103 )
{
struct V_1 * V_1 ;
if ( V_103 -> V_105 )
return V_103 -> V_105 ( V_41 ) ;
V_1 = F_75 ( V_41 ) ;
if ( ! V_1 )
return NULL ;
F_53 ( V_1 ) ;
return V_1 ;
}
static int F_208 ( struct V_41 * V_41 , struct V_102 * V_103 ,
bool V_155 )
{
struct V_1 * V_1 ;
T_10 V_156 ;
struct V_9 * V_14 ;
int V_100 = V_89 ;
if ( V_155 ) {
V_1 = F_75 ( V_41 ) ;
F_135 ( ! V_1 , V_41 ) ;
} else {
V_1 = F_207 ( V_41 , V_103 ) ;
}
if ( ! V_1 )
return V_100 ;
V_156 = F_142 ( V_41 ) ;
F_209 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_12 * V_13 = V_14 -> V_13 ;
unsigned long V_63 = F_210 ( V_41 , V_13 ) ;
F_211 () ;
if ( V_103 -> V_106 && V_103 -> V_106 ( V_13 , V_103 -> V_85 ) )
continue;
V_100 = V_103 -> V_104 ( V_41 , V_13 , V_63 , V_103 -> V_85 ) ;
if ( V_100 != V_89 )
break;
if ( V_103 -> V_152 && V_103 -> V_152 ( V_41 ) )
break;
}
if ( ! V_155 )
F_55 ( V_1 ) ;
return V_100 ;
}
static int F_212 ( struct V_41 * V_41 , struct V_102 * V_103 ,
bool V_155 )
{
struct V_110 * V_43 = F_132 ( V_41 ) ;
T_10 V_156 ;
struct V_12 * V_13 ;
int V_100 = V_89 ;
F_135 ( ! F_131 ( V_41 ) , V_41 ) ;
if ( ! V_43 )
return V_100 ;
V_156 = F_142 ( V_41 ) ;
if ( ! V_155 )
F_213 ( V_43 ) ;
F_214 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_63 = F_210 ( V_41 , V_13 ) ;
F_211 () ;
if ( V_103 -> V_106 && V_103 -> V_106 ( V_13 , V_103 -> V_85 ) )
continue;
V_100 = V_103 -> V_104 ( V_41 , V_13 , V_63 , V_103 -> V_85 ) ;
if ( V_100 != V_89 )
goto V_152;
if ( V_103 -> V_152 && V_103 -> V_152 ( V_41 ) )
goto V_152;
}
V_152:
if ( ! V_155 )
F_215 ( V_43 ) ;
return V_100 ;
}
int F_117 ( struct V_41 * V_41 , struct V_102 * V_103 )
{
if ( F_18 ( F_115 ( V_41 ) ) )
return F_216 ( V_41 , V_103 ) ;
else if ( F_74 ( V_41 ) )
return F_208 ( V_41 , V_103 , false ) ;
else
return F_212 ( V_41 , V_103 , false ) ;
}
int F_203 ( struct V_41 * V_41 , struct V_102 * V_103 )
{
F_135 ( F_115 ( V_41 ) , V_41 ) ;
if ( F_74 ( V_41 ) )
return F_208 ( V_41 , V_103 , true ) ;
else
return F_212 ( V_41 , V_103 , true ) ;
}
static void F_217 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 , int V_111 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
F_130 ( ! V_1 ) ;
if ( F_74 ( V_41 ) )
return;
if ( ! V_111 )
V_1 = V_1 -> V_7 ;
V_1 = ( void * ) V_1 + V_45 ;
V_41 -> V_43 = (struct V_110 * ) V_1 ;
V_41 -> V_112 = F_139 ( V_13 , V_63 ) ;
}
void F_218 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
int V_115 ;
F_130 ( ! F_131 ( V_41 ) ) ;
F_130 ( ! V_1 ) ;
V_115 = F_147 ( F_146 ( V_41 ) ) ;
if ( V_115 )
F_217 ( V_41 , V_13 , V_63 , 0 ) ;
}
void F_219 ( struct V_41 * V_41 ,
struct V_12 * V_13 , unsigned long V_63 )
{
F_130 ( V_63 < V_13 -> V_68 || V_63 >= V_13 -> V_69 ) ;
F_3 ( F_146 ( V_41 ) , 0 ) ;
F_217 ( V_41 , V_13 , V_63 , 1 ) ;
}
