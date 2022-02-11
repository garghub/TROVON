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
F_15 ( & V_12 -> V_14 , & V_1 -> V_15 ) ;
}
int F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
struct V_7 * V_12 ;
F_17 () ;
if ( F_18 ( ! V_1 ) ) {
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_1 * V_19 ;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_20;
V_1 = F_19 ( V_11 ) ;
V_19 = NULL ;
if ( ! V_1 ) {
V_1 = F_1 () ;
if ( F_18 ( ! V_1 ) )
goto V_21;
V_19 = V_1 ;
}
F_8 ( V_1 ) ;
F_20 ( & V_17 -> V_22 ) ;
if ( F_21 ( ! V_11 -> V_1 ) ) {
V_11 -> V_1 = V_1 ;
F_13 ( V_11 , V_12 , V_1 ) ;
V_19 = NULL ;
V_12 = NULL ;
}
F_22 ( & V_17 -> V_22 ) ;
F_9 ( V_1 ) ;
if ( F_18 ( V_19 ) )
F_23 ( V_19 ) ;
if ( F_18 ( V_12 ) )
F_12 ( V_12 ) ;
}
return 0 ;
V_21:
F_12 ( V_12 ) ;
V_20:
return - V_23 ;
}
static inline struct V_1 * F_24 ( struct V_1 * V_5 , struct V_1 * V_1 )
{
struct V_1 * V_24 = V_1 -> V_5 ;
if ( V_24 != V_5 ) {
if ( F_25 ( V_5 ) )
F_26 ( & V_5 -> V_6 ) ;
V_5 = V_24 ;
F_27 ( & V_5 -> V_6 ) ;
}
return V_5 ;
}
static inline void F_28 ( struct V_1 * V_5 )
{
if ( V_5 )
F_26 ( & V_5 -> V_6 ) ;
}
int F_29 ( struct V_10 * V_25 , struct V_10 * V_26 )
{
struct V_7 * V_12 , * V_27 ;
struct V_1 * V_5 = NULL ;
F_30 (pavc, &src->anon_vma_chain, same_vma) {
struct V_1 * V_1 ;
V_12 = F_11 ( V_28 | V_29 ) ;
if ( F_18 ( ! V_12 ) ) {
F_28 ( V_5 ) ;
V_5 = NULL ;
V_12 = F_11 ( V_3 ) ;
if ( ! V_12 )
goto V_30;
}
V_1 = V_27 -> V_1 ;
V_5 = F_24 ( V_5 , V_1 ) ;
F_13 ( V_25 , V_12 , V_1 ) ;
}
F_28 ( V_5 ) ;
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
V_5 = F_24 ( V_5 , V_1 ) ;
F_33 ( & V_27 -> V_14 ) ;
F_15 ( & V_27 -> V_14 , & V_1 -> V_15 ) ;
}
F_28 ( V_5 ) ;
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
F_13 ( V_11 , V_12 , V_1 ) ;
F_9 ( V_1 ) ;
return 0 ;
V_33:
F_23 ( V_1 ) ;
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
V_5 = F_24 ( V_5 , V_1 ) ;
F_33 ( & V_12 -> V_14 ) ;
if ( F_37 ( & V_1 -> V_15 ) )
continue;
F_33 ( & V_12 -> V_13 ) ;
F_12 ( V_12 ) ;
}
F_28 ( V_5 ) ;
F_36 (avc, next, &vma->anon_vma_chain, same_vma) {
struct V_1 * V_1 = V_12 -> V_1 ;
F_23 ( V_1 ) ;
F_33 ( & V_12 -> V_13 ) ;
F_12 ( V_12 ) ;
}
}
static void F_38 ( void * V_35 )
{
struct V_1 * V_1 = V_35 ;
F_39 ( & V_1 -> V_6 ) ;
F_3 ( & V_1 -> V_4 , 0 ) ;
F_40 ( & V_1 -> V_15 ) ;
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
F_23 ( V_1 ) ;
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
F_26 ( & V_44 -> V_6 ) ;
V_1 = NULL ;
}
goto V_43;
}
if ( ! F_48 ( & V_1 -> V_4 ) ) {
V_1 = NULL ;
goto V_43;
}
if ( ! F_47 ( V_38 ) ) {
F_23 ( V_1 ) ;
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
if ( F_18 ( F_56 ( V_11 ) ) )
V_45 = V_38 -> V_46 << F_57 ( F_58 ( V_38 ) ) ;
V_49 = V_11 -> V_50 + ( ( V_45 - V_11 -> V_51 ) << V_48 ) ;
if ( F_18 ( V_49 < V_11 -> V_50 || V_49 >= V_11 -> V_52 ) ) {
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
T_4 * F_62 ( struct V_38 * V_38 , struct V_16 * V_17 ,
unsigned long V_49 , T_5 * * V_59 , int V_60 )
{
T_6 * V_61 ;
T_7 * V_62 ;
T_8 * V_63 ;
T_4 * V_64 ;
T_5 * V_65 ;
if ( F_18 ( F_63 ( V_38 ) ) ) {
V_64 = F_64 ( V_17 , V_49 ) ;
V_65 = & V_17 -> V_22 ;
goto V_66;
}
V_61 = F_65 ( V_17 , V_49 ) ;
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
V_65 = F_75 ( V_17 , V_63 ) ;
V_66:
F_20 ( V_65 ) ;
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
V_64 = F_80 ( V_38 , V_11 -> V_18 , V_49 , & V_65 , 1 ) ;
if ( ! V_64 )
return 0 ;
F_78 ( V_64 , V_65 ) ;
return 1 ;
}
int F_81 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 , unsigned int * V_67 ,
unsigned long * V_55 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
int V_68 = 0 ;
if ( F_18 ( F_82 ( V_38 ) ) ) {
T_8 * V_63 ;
F_20 ( & V_17 -> V_22 ) ;
V_63 = F_83 ( V_38 , V_17 , V_49 ,
V_69 ) ;
if ( ! V_63 ) {
F_22 ( & V_17 -> V_22 ) ;
goto V_43;
}
if ( V_11 -> V_55 & V_70 ) {
F_22 ( & V_17 -> V_22 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_84 ( V_11 , V_49 , V_63 ) )
V_68 ++ ;
F_22 ( & V_17 -> V_22 ) ;
} else {
T_4 * V_64 ;
T_5 * V_65 ;
V_64 = F_80 ( V_38 , V_17 , V_49 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( V_11 -> V_55 & V_70 ) {
F_78 ( V_64 , V_65 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_85 ( V_11 , V_49 , V_64 ) ) {
if ( F_21 ( ! F_86 ( V_11 ) ) )
V_68 ++ ;
}
F_78 ( V_64 , V_65 ) ;
}
if ( V_17 != V_71 -> V_17 && F_87 ( V_17 ) &&
F_88 ( & V_17 -> V_72 ) )
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
if ( V_74 && ! F_92 ( V_11 -> V_18 , V_74 ) )
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
F_27 ( & V_40 -> V_78 ) ;
V_67 = F_90 ( V_38 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
if ( V_74 && ! F_92 ( V_11 -> V_18 , V_74 ) )
continue;
V_68 += F_81 ( V_38 , V_11 , V_49 ,
& V_67 , V_55 ) ;
if ( ! V_67 )
break;
}
F_26 ( & V_40 -> V_78 ) ;
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
if ( F_18 ( F_99 ( V_38 ) ) )
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
struct V_16 * V_17 = V_11 -> V_18 ;
T_4 * V_64 ;
T_5 * V_65 ;
int V_81 = 0 ;
V_64 = F_80 ( V_38 , V_17 , V_49 , & V_65 , 1 ) ;
if ( ! V_64 )
goto V_43;
if ( F_105 ( * V_64 ) || F_106 ( * V_64 ) ) {
T_4 V_82 ;
F_107 ( V_11 , V_49 , F_77 ( * V_64 ) ) ;
V_82 = F_108 ( V_11 , V_49 , V_64 ) ;
V_82 = F_109 ( V_82 ) ;
V_82 = F_110 ( V_82 ) ;
F_111 ( V_17 , V_49 , V_64 , V_82 ) ;
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
F_27 ( & V_40 -> V_78 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if ( V_11 -> V_55 & V_83 ) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 += F_104 ( V_38 , V_11 , V_49 ) ;
}
}
F_26 ( & V_40 -> V_78 ) ;
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
if ( F_18 ( F_99 ( V_38 ) ) )
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
bool V_90 ;
unsigned long V_91 ;
F_131 ( V_38 , & V_90 , & V_91 ) ;
if ( F_123 ( & V_38 -> V_86 ) ) {
F_124 ( V_38 , V_92 ) ;
F_132 ( V_38 , V_93 ) ;
}
F_133 ( V_38 , & V_90 , & V_91 ) ;
}
void F_134 ( struct V_38 * V_38 )
{
bool V_94 = F_60 ( V_38 ) ;
bool V_90 ;
unsigned long V_91 ;
if ( ! V_94 )
F_131 ( V_38 , & V_90 , & V_91 ) ;
if ( ! F_135 ( - 1 , & V_38 -> V_86 ) )
goto V_43;
if ( ( ! V_94 || F_136 ( V_38 ) ) &&
F_115 ( F_76 ( V_38 ) , 1 ) )
F_137 ( V_38 ) ;
if ( F_18 ( F_63 ( V_38 ) ) )
goto V_43;
if ( V_94 ) {
F_138 ( V_38 ) ;
if ( ! F_82 ( V_38 ) )
F_139 ( V_38 , V_87 ) ;
else
F_139 ( V_38 ,
V_88 ) ;
} else {
F_139 ( V_38 , V_92 ) ;
F_140 ( V_38 , V_93 ) ;
}
V_43:
if ( ! V_94 )
F_133 ( V_38 , & V_90 , & V_91 ) ;
}
int F_141 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_49 , enum V_95 V_91 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
T_4 * V_64 ;
T_4 V_96 ;
T_5 * V_65 ;
int V_81 = V_97 ;
V_64 = F_80 ( V_38 , V_17 , V_49 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( ! ( V_91 & V_98 ) ) {
if ( V_11 -> V_55 & V_70 )
goto V_99;
if ( F_142 ( V_91 ) == V_100 )
goto V_101;
}
if ( ! ( V_91 & V_102 ) ) {
if ( F_85 ( V_11 , V_49 , V_64 ) ) {
V_81 = V_103 ;
goto V_101;
}
}
F_107 ( V_11 , V_49 , F_76 ( V_38 ) ) ;
V_96 = F_108 ( V_11 , V_49 , V_64 ) ;
if ( F_105 ( V_96 ) )
F_137 ( V_38 ) ;
F_143 ( V_17 ) ;
if ( F_144 ( V_38 ) && ! ( V_91 & V_104 ) ) {
if ( F_60 ( V_38 ) )
F_145 ( V_17 , V_105 ) ;
else
F_145 ( V_17 , V_106 ) ;
F_111 ( V_17 , V_49 , V_64 ,
F_146 ( F_147 ( V_38 ) ) ) ;
} else if ( F_60 ( V_38 ) ) {
T_9 V_82 = { . V_107 = F_148 (page) } ;
if ( F_136 ( V_38 ) ) {
if ( F_149 ( V_82 ) < 0 ) {
F_111 ( V_17 , V_49 , V_64 , V_96 ) ;
V_81 = V_103 ;
goto V_101;
}
if ( F_37 ( & V_17 -> V_108 ) ) {
F_20 ( & V_109 ) ;
if ( F_37 ( & V_17 -> V_108 ) )
F_14 ( & V_17 -> V_108 , & V_110 . V_108 ) ;
F_22 ( & V_109 ) ;
}
F_145 ( V_17 , V_105 ) ;
F_150 ( V_17 , V_111 ) ;
} else if ( F_151 ( V_112 ) ) {
F_94 ( F_142 ( V_91 ) != V_113 ) ;
V_82 = F_152 ( V_38 , F_106 ( V_96 ) ) ;
}
F_111 ( V_17 , V_49 , V_64 , F_146 ( V_82 ) ) ;
F_94 ( F_153 ( * V_64 ) ) ;
} else if ( F_151 ( V_112 ) &&
( F_142 ( V_91 ) == V_113 ) ) {
T_9 V_82 ;
V_82 = F_152 ( V_38 , F_106 ( V_96 ) ) ;
F_111 ( V_17 , V_49 , V_64 , F_146 ( V_82 ) ) ;
} else
F_145 ( V_17 , V_106 ) ;
F_134 ( V_38 ) ;
F_154 ( V_38 ) ;
V_101:
F_78 ( V_64 , V_65 ) ;
V_43:
return V_81 ;
V_99:
F_78 ( V_64 , V_65 ) ;
if ( F_155 ( & V_11 -> V_18 -> V_72 ) ) {
if ( V_11 -> V_55 & V_70 ) {
F_156 ( V_38 ) ;
V_81 = V_114 ;
}
F_157 ( & V_11 -> V_18 -> V_72 ) ;
}
return V_81 ;
}
static int F_158 ( unsigned long V_115 , unsigned int * V_67 ,
struct V_10 * V_11 , struct V_38 * V_116 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
T_6 * V_61 ;
T_7 * V_62 ;
T_8 * V_63 ;
T_4 * V_64 ;
T_4 V_96 ;
T_5 * V_65 ;
struct V_38 * V_38 ;
unsigned long V_49 ;
unsigned long V_117 ;
int V_81 = V_97 ;
int V_118 = 0 ;
V_49 = ( V_11 -> V_50 + V_115 ) & V_119 ;
V_117 = V_49 + V_120 ;
if ( V_49 < V_11 -> V_50 )
V_49 = V_11 -> V_50 ;
if ( V_117 > V_11 -> V_52 )
V_117 = V_11 -> V_52 ;
V_61 = F_65 ( V_17 , V_49 ) ;
if ( ! F_66 ( * V_61 ) )
return V_81 ;
V_62 = F_67 ( V_61 , V_49 ) ;
if ( ! F_68 ( * V_62 ) )
return V_81 ;
V_63 = F_69 ( V_62 , V_49 ) ;
if ( ! F_70 ( * V_63 ) )
return V_81 ;
if ( F_155 ( & V_11 -> V_18 -> V_72 ) ) {
V_118 = ( V_11 -> V_55 & V_70 ) ;
if ( ! V_118 )
F_157 ( & V_11 -> V_18 -> V_72 ) ;
}
V_64 = F_159 ( V_17 , V_63 , V_49 , & V_65 ) ;
F_143 ( V_17 ) ;
for (; V_49 < V_117 ; V_64 ++ , V_49 += V_121 ) {
if ( ! F_73 ( * V_64 ) )
continue;
V_38 = F_160 ( V_11 , V_49 , * V_64 ) ;
F_94 ( ! V_38 || F_60 ( V_38 ) ) ;
if ( V_118 ) {
F_156 ( V_38 ) ;
if ( V_38 == V_116 )
V_81 = V_114 ;
continue;
}
if ( F_85 ( V_11 , V_49 , V_64 ) )
continue;
F_107 ( V_11 , V_49 , F_77 ( * V_64 ) ) ;
V_96 = F_108 ( V_11 , V_49 , V_64 ) ;
if ( V_38 -> V_46 != F_117 ( V_11 , V_49 ) )
F_111 ( V_17 , V_49 , V_64 , F_161 ( V_38 -> V_46 ) ) ;
if ( F_105 ( V_96 ) )
F_137 ( V_38 ) ;
F_134 ( V_38 ) ;
F_154 ( V_38 ) ;
F_145 ( V_17 , V_106 ) ;
( * V_67 ) -- ;
}
F_78 ( V_64 - 1 , V_65 ) ;
if ( V_118 )
F_157 ( & V_11 -> V_18 -> V_72 ) ;
return V_81 ;
}
bool F_162 ( struct V_10 * V_11 )
{
int V_122 = V_11 -> V_55 & ( V_123 | V_124 ) ;
if ( ! V_122 )
return false ;
if ( ( V_11 -> V_55 & V_125 ) ==
V_125 )
return true ;
return false ;
}
static int F_163 ( struct V_38 * V_38 , enum V_95 V_91 )
{
struct V_1 * V_1 ;
struct V_7 * V_12 ;
int V_81 = V_97 ;
V_1 = F_50 ( V_38 ) ;
if ( ! V_1 )
return V_81 ;
F_91 (avc, &anon_vma->head, same_anon_vma) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_49 ;
if ( F_151 ( V_112 ) && ( V_91 & V_113 ) &&
F_162 ( V_11 ) )
continue;
V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_141 ( V_38 , V_11 , V_49 , V_91 ) ;
if ( V_81 != V_97 || ! F_47 ( V_38 ) )
break;
}
F_54 ( V_1 ) ;
return V_81 ;
}
static int F_164 ( struct V_38 * V_38 , enum V_95 V_91 )
{
struct V_75 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
struct V_76 V_77 ;
int V_81 = V_97 ;
unsigned long V_115 ;
unsigned long V_126 = 0 ;
unsigned long V_127 = 0 ;
unsigned int V_67 ;
F_27 ( & V_40 -> V_78 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_141 ( V_38 , V_11 , V_49 , V_91 ) ;
if ( V_81 != V_97 || ! F_47 ( V_38 ) )
goto V_43;
}
if ( F_37 ( & V_40 -> V_128 ) )
goto V_43;
if ( F_142 ( V_91 ) == V_100 )
goto V_43;
F_91 (vma, &mapping->i_mmap_nonlinear,
shared.vm_set.list) {
V_115 = ( unsigned long ) V_11 -> V_129 ;
if ( V_115 > V_126 )
V_126 = V_115 ;
V_115 = V_11 -> V_52 - V_11 -> V_50 ;
if ( V_115 > V_127 )
V_127 = V_115 ;
}
if ( V_127 == 0 ) {
V_81 = V_103 ;
goto V_43;
}
V_67 = F_90 ( V_38 ) ;
if ( ! V_67 )
goto V_43;
F_165 () ;
V_127 = ( V_127 + V_120 - 1 ) & V_119 ;
if ( V_126 == 0 )
V_126 = V_120 ;
do {
F_91 (vma, &mapping->i_mmap_nonlinear,
shared.vm_set.list) {
V_115 = ( unsigned long ) V_11 -> V_129 ;
while ( V_115 < V_126 &&
V_115 < V_11 -> V_52 - V_11 -> V_50 ) {
if ( F_158 ( V_115 , & V_67 ,
V_11 , V_38 ) == V_114 )
V_81 = V_114 ;
V_115 += V_120 ;
V_11 -> V_129 = ( void * ) V_115 ;
if ( ( int ) V_67 <= 0 )
goto V_43;
}
V_11 -> V_129 = ( void * ) V_126 ;
}
F_165 () ;
V_126 += V_120 ;
} while ( V_126 <= V_127 );
F_91 (vma, &mapping->i_mmap_nonlinear, shared.vm_set.list)
V_11 -> V_129 = NULL ;
V_43:
F_26 ( & V_40 -> V_78 ) ;
return V_81 ;
}
int F_166 ( struct V_38 * V_38 , enum V_95 V_91 )
{
int V_81 ;
F_94 ( ! F_95 ( V_38 ) ) ;
F_5 ( ! F_63 ( V_38 ) && F_82 ( V_38 ) ) ;
if ( F_18 ( F_99 ( V_38 ) ) )
V_81 = F_167 ( V_38 , V_91 ) ;
else if ( F_60 ( V_38 ) )
V_81 = F_163 ( V_38 , V_91 ) ;
else
V_81 = F_164 ( V_38 , V_91 ) ;
if ( V_81 != V_114 && ! F_47 ( V_38 ) )
V_81 = V_130 ;
return V_81 ;
}
int F_168 ( struct V_38 * V_38 )
{
F_5 ( ! F_95 ( V_38 ) || F_169 ( V_38 ) ) ;
if ( F_18 ( F_99 ( V_38 ) ) )
return F_167 ( V_38 , V_100 ) ;
else if ( F_60 ( V_38 ) )
return F_163 ( V_38 , V_100 ) ;
else
return F_164 ( V_38 , V_100 ) ;
}
void F_53 ( struct V_1 * V_1 )
{
struct V_1 * V_5 = V_1 -> V_5 ;
if ( V_5 != V_1 && F_52 ( & V_5 -> V_4 ) )
F_4 ( V_5 ) ;
F_4 ( V_1 ) ;
}
static int F_170 ( struct V_38 * V_38 , int (* F_171)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_131 )
{
struct V_1 * V_1 ;
struct V_7 * V_12 ;
int V_81 = V_97 ;
V_1 = F_61 ( V_38 ) ;
if ( ! V_1 )
return V_81 ;
F_8 ( V_1 ) ;
F_91 (avc, &anon_vma->head, same_anon_vma) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_171 ( V_38 , V_11 , V_49 , V_131 ) ;
if ( V_81 != V_97 )
break;
}
F_9 ( V_1 ) ;
return V_81 ;
}
static int F_172 ( struct V_38 * V_38 , int (* F_171)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_131 )
{
struct V_75 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
struct V_76 V_77 ;
int V_81 = V_97 ;
if ( ! V_40 )
return V_81 ;
F_27 ( & V_40 -> V_78 ) ;
F_96 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_49 = F_55 ( V_38 , V_11 ) ;
if ( V_49 == - V_53 )
continue;
V_81 = F_171 ( V_38 , V_11 , V_49 , V_131 ) ;
if ( V_81 != V_97 )
break;
}
F_26 ( & V_40 -> V_78 ) ;
return V_81 ;
}
int F_173 ( struct V_38 * V_38 , int (* F_171)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_131 )
{
F_5 ( ! F_95 ( V_38 ) ) ;
if ( F_18 ( F_99 ( V_38 ) ) )
return F_174 ( V_38 , F_171 , V_131 ) ;
else if ( F_60 ( V_38 ) )
return F_170 ( V_38 , F_171 , V_131 ) ;
else
return F_172 ( V_38 , F_171 , V_131 ) ;
}
static void F_175 ( struct V_38 * V_38 ,
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
void F_176 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
int V_85 ;
F_94 ( ! F_95 ( V_38 ) ) ;
F_94 ( ! V_1 ) ;
V_85 = F_123 ( & V_38 -> V_86 ) ;
if ( V_85 )
F_175 ( V_38 , V_11 , V_49 , 0 ) ;
}
void F_177 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_49 )
{
F_94 ( V_49 < V_11 -> V_50 || V_49 >= V_11 -> V_52 ) ;
F_3 ( & V_38 -> V_86 , 0 ) ;
F_175 ( V_38 , V_11 , V_49 , 1 ) ;
}
