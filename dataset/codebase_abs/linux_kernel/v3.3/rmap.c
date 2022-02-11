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
int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
struct V_7 * V_12 ;
F_14 () ;
if ( F_15 ( ! V_1 ) ) {
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_1 * V_16 ;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_17;
V_1 = F_16 ( V_11 ) ;
V_16 = NULL ;
if ( ! V_1 ) {
V_1 = F_1 () ;
if ( F_15 ( ! V_1 ) )
goto V_18;
V_16 = V_1 ;
}
F_8 ( V_1 ) ;
F_17 ( & V_14 -> V_19 ) ;
if ( F_18 ( ! V_11 -> V_1 ) ) {
V_11 -> V_1 = V_1 ;
V_12 -> V_1 = V_1 ;
V_12 -> V_11 = V_11 ;
F_19 ( & V_12 -> V_20 , & V_11 -> V_7 ) ;
F_20 ( & V_12 -> V_21 , & V_1 -> V_22 ) ;
V_16 = NULL ;
V_12 = NULL ;
}
F_21 ( & V_14 -> V_19 ) ;
F_9 ( V_1 ) ;
if ( F_15 ( V_16 ) )
F_22 ( V_16 ) ;
if ( F_15 ( V_12 ) )
F_12 ( V_12 ) ;
}
return 0 ;
V_18:
F_12 ( V_12 ) ;
V_17:
return - V_23 ;
}
static inline struct V_1 * F_23 ( struct V_1 * V_5 , struct V_1 * V_1 )
{
struct V_1 * V_24 = V_1 -> V_5 ;
if ( V_24 != V_5 ) {
if ( F_24 ( V_5 ) )
F_25 ( & V_5 -> V_6 ) ;
V_5 = V_24 ;
F_26 ( & V_5 -> V_6 ) ;
}
return V_5 ;
}
static inline void F_27 ( struct V_1 * V_5 )
{
if ( V_5 )
F_25 ( & V_5 -> V_6 ) ;
}
static void F_28 ( struct V_10 * V_11 ,
struct V_7 * V_12 ,
struct V_1 * V_1 )
{
V_12 -> V_11 = V_11 ;
V_12 -> V_1 = V_1 ;
F_19 ( & V_12 -> V_20 , & V_11 -> V_7 ) ;
F_20 ( & V_12 -> V_21 , & V_1 -> V_22 ) ;
}
int F_29 ( struct V_10 * V_25 , struct V_10 * V_26 )
{
struct V_7 * V_12 , * V_27 ;
struct V_1 * V_5 = NULL ;
F_30 (pavc, &src->anon_vma_chain, same_vma) {
struct V_1 * V_1 ;
V_12 = F_11 ( V_28 | V_29 ) ;
if ( F_15 ( ! V_12 ) ) {
F_27 ( V_5 ) ;
V_5 = NULL ;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_30;
}
V_1 = V_27 -> V_1 ;
V_5 = F_23 ( V_5 , V_1 ) ;
F_28 ( V_25 , V_12 , V_1 ) ;
}
F_27 ( V_5 ) ;
return 0 ;
V_30:
F_31 ( V_25 ) ;
return - V_23 ;
}
void F_32 ( struct V_10 * V_25 )
{
struct V_7 * V_27 ;
struct V_1 * V_5 = NULL ;
F_30 (pavc, &dst->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_27 -> V_1 ;
F_5 ( V_27 -> V_11 != V_25 ) ;
V_5 = F_23 ( V_5 , V_1 ) ;
F_33 ( & V_27 -> V_21 ) ;
F_20 ( & V_27 -> V_21 , & V_1 -> V_22 ) ;
}
F_27 ( V_5 ) ;
}
int F_34 ( struct V_10 * V_11 , struct V_10 * V_31 )
{
struct V_7 * V_12 ;
struct V_1 * V_1 ;
if ( ! V_31 -> V_1 )
return 0 ;
if ( F_29 ( V_11 , V_31 ) )
return - V_23 ;
V_1 = F_1 () ;
if ( ! V_1 )
goto V_32;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_33;
V_1 -> V_5 = V_31 -> V_1 -> V_5 ;
F_35 ( V_1 -> V_5 ) ;
V_11 -> V_1 = V_1 ;
F_8 ( V_1 ) ;
F_28 ( V_11 , V_12 , V_1 ) ;
F_9 ( V_1 ) ;
return 0 ;
V_33:
F_22 ( V_1 ) ;
V_32:
F_31 ( V_11 ) ;
return - V_23 ;
}
void F_31 ( struct V_10 * V_11 )
{
struct V_7 * V_12 , * V_34 ;
struct V_1 * V_5 = NULL ;
F_36 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_12 -> V_1 ;
V_5 = F_23 ( V_5 , V_1 ) ;
F_33 ( & V_12 -> V_21 ) ;
if ( F_37 ( & V_1 -> V_22 ) )
continue;
F_33 ( & V_12 -> V_20 ) ;
F_12 ( V_12 ) ;
}
F_27 ( V_5 ) ;
F_36 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_12 -> V_1 ;
F_22 ( V_1 ) ;
F_33 ( & V_12 -> V_20 ) ;
F_12 ( V_12 ) ;
}
}
static void F_38 ( void * V_35 )
{
struct V_1 * V_1 = V_35 ;
F_39 ( & V_1 -> V_6 ) ;
F_3 ( & V_1 -> V_4 , 0 ) ;
F_40 ( & V_1 -> V_22 ) ;
}
void T_2 F_41 ( void )
{
V_2 = F_42 ( L_1 , sizeof( struct V_1 ) ,
0 , V_36 | V_37 , F_38 ) ;
V_9 = F_43 ( V_7 , V_37 ) ;
}
struct V_1 * F_44 ( struct V_38 * V_38 )
{
struct V_1 * V_1 = NULL ;
unsigned long V_39 ;
F_45 () ;
V_39 = ( unsigned long ) F_46 ( V_38 -> V_40 ) ;
if ( ( V_39 & V_41 ) != V_42 )
goto V_43;
if ( ! F_47 ( V_38 ) )
goto V_43;
V_1 = (struct V_1 * ) ( V_39 - V_42 ) ;
if ( ! F_48 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_43;
}
if ( ! F_47 ( V_38 ) ) {
F_22 ( V_1 ) ;
V_1 = NULL ;
}
V_43:
F_49 () ;
return V_1 ;
}
struct V_1 * F_50 ( struct V_38 * V_38 )
{
struct V_1 * V_1 = NULL ;
struct V_1 * V_44 ;
unsigned long V_39 ;
F_45 () ;
V_39 = ( unsigned long ) F_46 ( V_38 -> V_40 ) ;
if ( ( V_39 & V_41 ) != V_42 )
goto V_43;
if ( ! F_47 ( V_38 ) )
goto V_43;
V_1 = (struct V_1 * ) ( V_39 - V_42 ) ;
V_44 = F_46 ( V_1 -> V_5 ) ;
if ( F_51 ( & V_44 -> V_6 ) ) {
if ( ! F_47 ( V_38 ) ) {
F_25 ( & V_44 -> V_6 ) ;
V_1 = NULL ;
}
goto V_43;
}
if ( ! F_48 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_43;
}
if ( ! F_47 ( V_38 ) ) {
F_22 ( V_1 ) ;
V_1 = NULL ;
goto V_43;
}
F_49 () ;
F_8 ( V_1 ) ;
if ( F_52 ( & V_1 -> V_4 ) ) {
F_9 ( V_1 ) ;
F_53 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
V_43:
F_49 () ;
return V_1 ;
}
void F_54 ( struct V_1 * V_1 )
{
F_9 ( V_1 ) ;
}
inline unsigned long
F_55 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
unsigned long V_49 ;
if ( F_15 ( F_56 ( V_11 ) ) )
V_45 = V_38 -> V_46 << F_57 ( F_58 ( V_38 ) ) ;
V_49 = V_11 -> V_50 + ( ( V_45 - V_11 -> V_51 ) << V_48 ) ;
if ( F_15 ( V_49 < V_11 -> V_50 || V_49 >= V_11 -> V_52 ) ) {
return - V_53 ;
}
return V_49 ;
}
unsigned long F_59 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
if ( F_60 ( V_38 ) ) {
struct V_1 * V_54 = F_61 ( V_38 ) ;
if ( ! V_11 -> V_1 || ! V_54 ||
V_11 -> V_1 -> V_5 != V_54 -> V_5 )
return - V_53 ;
} else if ( V_38 -> V_40 && ! ( V_11 -> V_55 & V_56 ) ) {
if ( ! V_11 -> V_57 ||
V_11 -> V_57 -> V_58 != V_38 -> V_40 )
return - V_53 ;
} else
return - V_53 ;
return F_55 ( V_38 , V_11 ) ;
}
T_4 * F_62 ( struct V_38 * V_38 , struct V_13 * V_14 ,
unsigned long V_49 , T_5 * * V_59 , int V_60 )
{
T_6 * V_61 ;
T_7 * V_62 ;
T_8 * V_63 ;
T_4 * V_64 ;
T_5 * V_65 ;
if ( F_15 ( F_63 ( V_38 ) ) ) {
V_64 = F_64 ( V_14 , V_49 ) ;
V_65 = & V_14 -> V_19 ;
goto V_66;
}
V_61 = F_65 ( V_14 , V_49 ) ;
if ( ! F_66 ( * V_61 ) )
return NULL ;
V_62 = F_67 ( V_61 , V_49 ) ;
if ( ! F_68 ( * V_62 ) )
return NULL ;
V_63 = F_69 ( V_62 , V_49 ) ;
if ( ! F_70 ( * V_63 ) )
return NULL ;
if ( F_71 ( * V_63 ) )
return NULL ;
V_64 = F_72 ( V_63 , V_49 ) ;
if ( ! V_60 && ! F_73 ( * V_64 ) ) {
F_74 ( V_64 ) ;
return NULL ;
}
V_65 = F_75 ( V_14 , V_63 ) ;
V_66:
F_17 ( V_65 ) ;
if ( F_73 ( * V_64 ) && F_76 ( V_38 ) == F_77 ( * V_64 ) ) {
* V_59 = V_65 ;
return V_64 ;
}
F_78 ( V_64 , V_65 ) ;
return NULL ;
}
int F_79 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_49 ;
T_4 * V_64 ;
T_5 * V_65 ;
V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
return 0 ;
V_64 = F_80 ( V_38 , V_11 -> V_15 , V_49 , & V_65 , 1 ) ;
if ( ! V_64 )
return 0 ;
F_78 ( V_64 , V_65 ) ;
return 1 ;
}
int F_81 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 , unsigned int * V_67 ,
unsigned long * V_55 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
int V_68 = 0 ;
if ( F_15 ( F_82 ( V_38 ) ) ) {
T_8 * V_63 ;
F_17 ( & V_14 -> V_19 ) ;
V_63 = F_83 ( V_38 , V_14 , V_49 ,
V_69 ) ;
if ( ! V_63 ) {
F_21 ( & V_14 -> V_19 ) ;
goto V_43;
}
if ( V_11 -> V_55 & V_70 ) {
F_21 ( & V_14 -> V_19 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_84 ( V_11 , V_49 , V_63 ) )
V_68 ++ ;
F_21 ( & V_14 -> V_19 ) ;
} else {
T_4 * V_64 ;
T_5 * V_65 ;
V_64 = F_80 ( V_38 , V_14 , V_49 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( V_11 -> V_55 & V_70 ) {
F_78 ( V_64 , V_65 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_85 ( V_11 , V_49 , V_64 ) ) {
if ( F_18 ( ! F_86 ( V_11 ) ) )
V_68 ++ ;
}
F_78 ( V_64 , V_65 ) ;
}
if ( V_14 != V_71 -> V_14 && F_87 ( V_14 ) &&
F_88 ( & V_14 -> V_72 ) )
V_68 ++ ;
( * V_67 ) -- ;
if ( V_68 )
* V_55 |= V_11 -> V_55 ;
V_43:
return V_68 ;
}
static int F_89 ( struct V_38 * V_38 ,
struct V_73 * V_74 ,
unsigned long * V_55 )
{
unsigned int V_67 ;
struct V_1 * V_1 ;
struct V_7 * V_12 ;
int V_68 = 0 ;
V_1 = F_50 ( V_38 ) ;
if ( ! V_1 )
return V_68 ;
V_67 = F_90 ( V_38 ) ;
F_91 (avc, &anon_vma->head, same_anon_vma) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
if ( V_74 && ! F_92 ( V_11 -> V_15 , V_74 ) )
continue;
V_68 += F_81 ( V_38 , V_11 , V_49 ,
& V_67 , V_55 ) ;
if ( ! V_67 )
break;
}
F_54 ( V_1 ) ;
return V_68 ;
}
static int F_93 ( struct V_38 * V_38 ,
struct V_73 * V_74 ,
unsigned long * V_55 )
{
unsigned int V_67 ;
struct V_75 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
struct V_76 V_77 ;
int V_68 = 0 ;
F_94 ( F_60 ( V_38 ) ) ;
F_94 ( ! F_95 ( V_38 ) ) ;
F_26 ( & V_40 -> V_78 ) ;
V_67 = F_90 ( V_38 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
if ( V_74 && ! F_92 ( V_11 -> V_15 , V_74 ) )
continue;
V_68 += F_81 ( V_38 , V_11 , V_49 ,
& V_67 , V_55 ) ;
if ( ! V_67 )
break;
}
F_25 ( & V_40 -> V_78 ) ;
return V_68 ;
}
int F_97 ( struct V_38 * V_38 ,
int V_79 ,
struct V_73 * V_74 ,
unsigned long * V_55 )
{
int V_68 = 0 ;
int V_80 = 0 ;
* V_55 = 0 ;
if ( F_47 ( V_38 ) && F_98 ( V_38 ) ) {
if ( ! V_79 && ( ! F_60 ( V_38 ) || F_99 ( V_38 ) ) ) {
V_80 = F_100 ( V_38 ) ;
if ( ! V_80 ) {
V_68 ++ ;
goto V_43;
}
}
if ( F_15 ( F_99 ( V_38 ) ) )
V_68 += F_101 ( V_38 , V_74 ,
V_55 ) ;
else if ( F_60 ( V_38 ) )
V_68 += F_89 ( V_38 , V_74 ,
V_55 ) ;
else if ( V_38 -> V_40 )
V_68 += F_93 ( V_38 , V_74 ,
V_55 ) ;
if ( V_80 )
F_102 ( V_38 ) ;
if ( F_103 ( F_76 ( V_38 ) ) )
V_68 ++ ;
}
V_43:
return V_68 ;
}
static int F_104 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 * V_64 ;
T_5 * V_65 ;
int V_81 = 0 ;
V_64 = F_80 ( V_38 , V_14 , V_49 , & V_65 , 1 ) ;
if ( ! V_64 )
goto V_43;
if ( F_105 ( * V_64 ) || F_106 ( * V_64 ) ) {
T_4 V_82 ;
F_107 ( V_11 , V_49 , F_77 ( * V_64 ) ) ;
V_82 = F_108 ( V_11 , V_49 , V_64 ) ;
V_82 = F_109 ( V_82 ) ;
V_82 = F_110 ( V_82 ) ;
F_111 ( V_14 , V_49 , V_64 , V_82 ) ;
V_81 = 1 ;
}
F_78 ( V_64 , V_65 ) ;
V_43:
return V_81 ;
}
static int F_112 ( struct V_75 * V_40 , struct V_38 * V_38 )
{
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
struct V_76 V_77 ;
int V_81 = 0 ;
F_94 ( F_60 ( V_38 ) ) ;
F_26 ( & V_40 -> V_78 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if ( V_11 -> V_55 & V_83 ) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 += F_104 ( V_38 , V_11 , V_49 ) ;
}
}
F_25 ( & V_40 -> V_78 ) ;
return V_81 ;
}
int F_113 ( struct V_38 * V_38 )
{
int V_81 = 0 ;
F_94 ( ! F_95 ( V_38 ) ) ;
if ( F_47 ( V_38 ) ) {
struct V_75 * V_40 = F_114 ( V_38 ) ;
if ( V_40 ) {
V_81 = F_112 ( V_40 , V_38 ) ;
if ( F_115 ( F_76 ( V_38 ) , 1 ) )
V_81 = 1 ;
}
}
return V_81 ;
}
void F_116 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_5 ( ! F_95 ( V_38 ) ) ;
F_5 ( ! V_1 ) ;
F_5 ( V_38 -> V_46 != F_117 ( V_11 , V_49 ) ) ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_75 * ) V_1 ;
}
static void F_118 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 , int V_84 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_94 ( ! V_1 ) ;
if ( F_60 ( V_38 ) )
return;
if ( ! V_84 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_75 * ) V_1 ;
V_38 -> V_46 = F_117 ( V_11 , V_49 ) ;
}
static void F_119 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
#ifdef F_120
F_94 ( F_61 ( V_38 ) -> V_5 != V_11 -> V_1 -> V_5 ) ;
F_94 ( V_38 -> V_46 != F_117 ( V_11 , V_49 ) ) ;
#endif
}
void F_121 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
F_122 ( V_38 , V_11 , V_49 , 0 ) ;
}
void F_122 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 , int V_84 )
{
int V_85 = F_123 ( & V_38 -> V_86 ) ;
if ( V_85 ) {
if ( ! F_82 ( V_38 ) )
F_124 ( V_38 , V_87 ) ;
else
F_124 ( V_38 ,
V_88 ) ;
}
if ( F_15 ( F_99 ( V_38 ) ) )
return;
F_5 ( ! F_95 ( V_38 ) ) ;
if ( V_85 )
F_118 ( V_38 , V_11 , V_49 , V_84 ) ;
else
F_119 ( V_38 , V_11 , V_49 ) ;
}
void F_125 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
F_5 ( V_49 < V_11 -> V_50 || V_49 >= V_11 -> V_52 ) ;
F_126 ( V_38 ) ;
F_3 ( & V_38 -> V_86 , 0 ) ;
if ( ! F_82 ( V_38 ) )
F_124 ( V_38 , V_87 ) ;
else
F_124 ( V_38 , V_88 ) ;
F_118 ( V_38 , V_11 , V_49 , 1 ) ;
if ( F_127 ( V_38 , V_11 ) )
F_128 ( V_38 , V_89 ) ;
else
F_129 ( V_38 ) ;
}
void F_130 ( struct V_38 * V_38 )
{
if ( F_123 ( & V_38 -> V_86 ) ) {
F_124 ( V_38 , V_90 ) ;
F_131 ( V_38 , V_91 ) ;
}
}
void F_132 ( struct V_38 * V_38 )
{
if ( ! F_133 ( - 1 , & V_38 -> V_86 ) )
return;
if ( ( ! F_60 ( V_38 ) || F_134 ( V_38 ) ) &&
F_115 ( F_76 ( V_38 ) , 1 ) )
F_135 ( V_38 ) ;
if ( F_15 ( F_63 ( V_38 ) ) )
return;
if ( F_60 ( V_38 ) ) {
F_136 ( V_38 ) ;
if ( ! F_82 ( V_38 ) )
F_137 ( V_38 , V_87 ) ;
else
F_137 ( V_38 ,
V_88 ) ;
} else {
F_137 ( V_38 , V_90 ) ;
F_138 ( V_38 , V_91 ) ;
}
}
int F_139 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 , enum V_92 V_93 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_4 * V_64 ;
T_4 V_94 ;
T_5 * V_65 ;
int V_81 = V_95 ;
V_64 = F_80 ( V_38 , V_14 , V_49 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( ! ( V_93 & V_96 ) ) {
if ( V_11 -> V_55 & V_70 )
goto V_97;
if ( F_140 ( V_93 ) == V_98 )
goto V_99;
}
if ( ! ( V_93 & V_100 ) ) {
if ( F_85 ( V_11 , V_49 , V_64 ) ) {
V_81 = V_101 ;
goto V_99;
}
}
F_107 ( V_11 , V_49 , F_76 ( V_38 ) ) ;
V_94 = F_108 ( V_11 , V_49 , V_64 ) ;
if ( F_105 ( V_94 ) )
F_135 ( V_38 ) ;
F_141 ( V_14 ) ;
if ( F_142 ( V_38 ) && ! ( V_93 & V_102 ) ) {
if ( F_60 ( V_38 ) )
F_143 ( V_14 , V_103 ) ;
else
F_143 ( V_14 , V_104 ) ;
F_111 ( V_14 , V_49 , V_64 ,
F_144 ( F_145 ( V_38 ) ) ) ;
} else if ( F_60 ( V_38 ) ) {
T_9 V_82 = { . V_105 = F_146 (page) } ;
if ( F_134 ( V_38 ) ) {
if ( F_147 ( V_82 ) < 0 ) {
F_111 ( V_14 , V_49 , V_64 , V_94 ) ;
V_81 = V_101 ;
goto V_99;
}
if ( F_37 ( & V_14 -> V_106 ) ) {
F_17 ( & V_107 ) ;
if ( F_37 ( & V_14 -> V_106 ) )
F_19 ( & V_14 -> V_106 , & V_108 . V_106 ) ;
F_21 ( & V_107 ) ;
}
F_143 ( V_14 , V_103 ) ;
F_148 ( V_14 , V_109 ) ;
} else if ( V_110 ) {
F_94 ( F_140 ( V_93 ) != V_111 ) ;
V_82 = F_149 ( V_38 , F_106 ( V_94 ) ) ;
}
F_111 ( V_14 , V_49 , V_64 , F_144 ( V_82 ) ) ;
F_94 ( F_150 ( * V_64 ) ) ;
} else if ( V_110 && ( F_140 ( V_93 ) == V_111 ) ) {
T_9 V_82 ;
V_82 = F_149 ( V_38 , F_106 ( V_94 ) ) ;
F_111 ( V_14 , V_49 , V_64 , F_144 ( V_82 ) ) ;
} else
F_143 ( V_14 , V_104 ) ;
F_132 ( V_38 ) ;
F_151 ( V_38 ) ;
V_99:
F_78 ( V_64 , V_65 ) ;
V_43:
return V_81 ;
V_97:
F_78 ( V_64 , V_65 ) ;
if ( F_152 ( & V_11 -> V_15 -> V_72 ) ) {
if ( V_11 -> V_55 & V_70 ) {
F_153 ( V_38 ) ;
V_81 = V_112 ;
}
F_154 ( & V_11 -> V_15 -> V_72 ) ;
}
return V_81 ;
}
static int F_155 ( unsigned long V_113 , unsigned int * V_67 ,
struct V_10 * V_11 , struct V_38 * V_114 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
T_6 * V_61 ;
T_7 * V_62 ;
T_8 * V_63 ;
T_4 * V_64 ;
T_4 V_94 ;
T_5 * V_65 ;
struct V_38 * V_38 ;
unsigned long V_49 ;
unsigned long V_115 ;
int V_81 = V_95 ;
int V_116 = 0 ;
V_49 = ( V_11 -> V_50 + V_113 ) & V_117 ;
V_115 = V_49 + V_118 ;
if ( V_49 < V_11 -> V_50 )
V_49 = V_11 -> V_50 ;
if ( V_115 > V_11 -> V_52 )
V_115 = V_11 -> V_52 ;
V_61 = F_65 ( V_14 , V_49 ) ;
if ( ! F_66 ( * V_61 ) )
return V_81 ;
V_62 = F_67 ( V_61 , V_49 ) ;
if ( ! F_68 ( * V_62 ) )
return V_81 ;
V_63 = F_69 ( V_62 , V_49 ) ;
if ( ! F_70 ( * V_63 ) )
return V_81 ;
if ( F_152 ( & V_11 -> V_15 -> V_72 ) ) {
V_116 = ( V_11 -> V_55 & V_70 ) ;
if ( ! V_116 )
F_154 ( & V_11 -> V_15 -> V_72 ) ;
}
V_64 = F_156 ( V_14 , V_63 , V_49 , & V_65 ) ;
F_141 ( V_14 ) ;
for (; V_49 < V_115 ; V_64 ++ , V_49 += V_119 ) {
if ( ! F_73 ( * V_64 ) )
continue;
V_38 = F_157 ( V_11 , V_49 , * V_64 ) ;
F_94 ( ! V_38 || F_60 ( V_38 ) ) ;
if ( V_116 ) {
F_153 ( V_38 ) ;
if ( V_38 == V_114 )
V_81 = V_112 ;
continue;
}
if ( F_85 ( V_11 , V_49 , V_64 ) )
continue;
F_107 ( V_11 , V_49 , F_77 ( * V_64 ) ) ;
V_94 = F_108 ( V_11 , V_49 , V_64 ) ;
if ( V_38 -> V_46 != F_117 ( V_11 , V_49 ) )
F_111 ( V_14 , V_49 , V_64 , F_158 ( V_38 -> V_46 ) ) ;
if ( F_105 ( V_94 ) )
F_135 ( V_38 ) ;
F_132 ( V_38 ) ;
F_151 ( V_38 ) ;
F_143 ( V_14 , V_104 ) ;
( * V_67 ) -- ;
}
F_78 ( V_64 - 1 , V_65 ) ;
if ( V_116 )
F_154 ( & V_11 -> V_15 -> V_72 ) ;
return V_81 ;
}
bool F_159 ( struct V_10 * V_11 )
{
int V_120 = V_11 -> V_55 & ( V_121 | V_122 ) ;
if ( ! V_120 )
return false ;
if ( ( V_11 -> V_55 & V_123 ) ==
V_123 )
return true ;
return false ;
}
static int F_160 ( struct V_38 * V_38 , enum V_92 V_93 )
{
struct V_1 * V_1 ;
struct V_7 * V_12 ;
int V_81 = V_95 ;
V_1 = F_50 ( V_38 ) ;
if ( ! V_1 )
return V_81 ;
F_91 (avc, &anon_vma->head, same_anon_vma) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_49 ;
if ( V_110 && ( V_93 & V_111 ) &&
F_159 ( V_11 ) )
continue;
V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_139 ( V_38 , V_11 , V_49 , V_93 ) ;
if ( V_81 != V_95 || ! F_47 ( V_38 ) )
break;
}
F_54 ( V_1 ) ;
return V_81 ;
}
static int F_161 ( struct V_38 * V_38 , enum V_92 V_93 )
{
struct V_75 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
struct V_76 V_77 ;
int V_81 = V_95 ;
unsigned long V_113 ;
unsigned long V_124 = 0 ;
unsigned long V_125 = 0 ;
unsigned int V_67 ;
F_26 ( & V_40 -> V_78 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_139 ( V_38 , V_11 , V_49 , V_93 ) ;
if ( V_81 != V_95 || ! F_47 ( V_38 ) )
goto V_43;
}
if ( F_37 ( & V_40 -> V_126 ) )
goto V_43;
if ( F_140 ( V_93 ) == V_98 )
goto V_43;
F_91 (vma, &mapping->i_mmap_nonlinear,
shared.vm_set.list) {
V_113 = ( unsigned long ) V_11 -> V_127 ;
if ( V_113 > V_124 )
V_124 = V_113 ;
V_113 = V_11 -> V_52 - V_11 -> V_50 ;
if ( V_113 > V_125 )
V_125 = V_113 ;
}
if ( V_125 == 0 ) {
V_81 = V_101 ;
goto V_43;
}
V_67 = F_90 ( V_38 ) ;
if ( ! V_67 )
goto V_43;
F_162 () ;
V_125 = ( V_125 + V_118 - 1 ) & V_117 ;
if ( V_124 == 0 )
V_124 = V_118 ;
do {
F_91 (vma, &mapping->i_mmap_nonlinear,
shared.vm_set.list) {
V_113 = ( unsigned long ) V_11 -> V_127 ;
while ( V_113 < V_124 &&
V_113 < V_11 -> V_52 - V_11 -> V_50 ) {
if ( F_155 ( V_113 , & V_67 ,
V_11 , V_38 ) == V_112 )
V_81 = V_112 ;
V_113 += V_118 ;
V_11 -> V_127 = ( void * ) V_113 ;
if ( ( int ) V_67 <= 0 )
goto V_43;
}
V_11 -> V_127 = ( void * ) V_124 ;
}
F_162 () ;
V_124 += V_118 ;
} while ( V_124 <= V_125 );
F_91 (vma, &mapping->i_mmap_nonlinear, shared.vm_set.list)
V_11 -> V_127 = NULL ;
V_43:
F_25 ( & V_40 -> V_78 ) ;
return V_81 ;
}
int F_163 ( struct V_38 * V_38 , enum V_92 V_93 )
{
int V_81 ;
F_94 ( ! F_95 ( V_38 ) ) ;
F_5 ( ! F_63 ( V_38 ) && F_82 ( V_38 ) ) ;
if ( F_15 ( F_99 ( V_38 ) ) )
V_81 = F_164 ( V_38 , V_93 ) ;
else if ( F_60 ( V_38 ) )
V_81 = F_160 ( V_38 , V_93 ) ;
else
V_81 = F_161 ( V_38 , V_93 ) ;
if ( V_81 != V_112 && ! F_47 ( V_38 ) )
V_81 = V_128 ;
return V_81 ;
}
int F_165 ( struct V_38 * V_38 )
{
F_5 ( ! F_95 ( V_38 ) || F_166 ( V_38 ) ) ;
if ( F_15 ( F_99 ( V_38 ) ) )
return F_164 ( V_38 , V_98 ) ;
else if ( F_60 ( V_38 ) )
return F_160 ( V_38 , V_98 ) ;
else
return F_161 ( V_38 , V_98 ) ;
}
void F_53 ( struct V_1 * V_1 )
{
struct V_1 * V_5 = V_1 -> V_5 ;
if ( V_5 != V_1 && F_52 ( & V_5 -> V_4 ) )
F_4 ( V_5 ) ;
F_4 ( V_1 ) ;
}
static int F_167 ( struct V_38 * V_38 , int (* F_168)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_129 )
{
struct V_1 * V_1 ;
struct V_7 * V_12 ;
int V_81 = V_95 ;
V_1 = F_61 ( V_38 ) ;
if ( ! V_1 )
return V_81 ;
F_8 ( V_1 ) ;
F_91 (avc, &anon_vma->head, same_anon_vma) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_168 ( V_38 , V_11 , V_49 , V_129 ) ;
if ( V_81 != V_95 )
break;
}
F_9 ( V_1 ) ;
return V_81 ;
}
static int F_169 ( struct V_38 * V_38 , int (* F_168)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_129 )
{
struct V_75 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
struct V_76 V_77 ;
int V_81 = V_95 ;
if ( ! V_40 )
return V_81 ;
F_26 ( & V_40 -> V_78 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_168 ( V_38 , V_11 , V_49 , V_129 ) ;
if ( V_81 != V_95 )
break;
}
F_25 ( & V_40 -> V_78 ) ;
return V_81 ;
}
int F_170 ( struct V_38 * V_38 , int (* F_168)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_129 )
{
F_5 ( ! F_95 ( V_38 ) ) ;
if ( F_15 ( F_99 ( V_38 ) ) )
return F_171 ( V_38 , F_168 , V_129 ) ;
else if ( F_60 ( V_38 ) )
return F_167 ( V_38 , F_168 , V_129 ) ;
else
return F_169 ( V_38 , F_168 , V_129 ) ;
}
static void F_172 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 , int V_84 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_94 ( ! V_1 ) ;
if ( F_60 ( V_38 ) )
return;
if ( ! V_84 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_75 * ) V_1 ;
V_38 -> V_46 = F_117 ( V_11 , V_49 ) ;
}
void F_173 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
int V_85 ;
F_94 ( ! F_95 ( V_38 ) ) ;
F_94 ( ! V_1 ) ;
V_85 = F_123 ( & V_38 -> V_86 ) ;
if ( V_85 )
F_172 ( V_38 , V_11 , V_49 , 0 ) ;
}
void F_174 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
F_94 ( V_49 < V_11 -> V_50 || V_49 >= V_11 -> V_52 ) ;
F_3 ( & V_38 -> V_86 , 0 ) ;
F_172 ( V_38 , V_11 , V_49 , 1 ) ;
}
