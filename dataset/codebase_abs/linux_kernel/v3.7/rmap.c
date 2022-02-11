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
F_26 ( & V_44 -> V_6 ) ;
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
F_8 ( V_1 ) ;
if ( F_51 ( & V_1 -> V_4 ) ) {
F_9 ( V_1 ) ;
F_52 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
V_43:
F_48 () ;
return V_1 ;
}
void F_53 ( struct V_1 * V_1 )
{
F_9 ( V_1 ) ;
}
static inline unsigned long
F_54 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
if ( F_18 ( F_55 ( V_11 ) ) )
V_45 = V_38 -> V_46 << F_56 ( F_57 ( V_38 ) ) ;
return V_11 -> V_49 + ( ( V_45 - V_11 -> V_50 ) << V_48 ) ;
}
inline unsigned long
F_58 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_51 = F_54 ( V_38 , V_11 ) ;
F_5 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
return V_51 ;
}
unsigned long F_59 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_51 ;
if ( F_60 ( V_38 ) ) {
struct V_1 * V_53 = F_61 ( V_38 ) ;
if ( ! V_11 -> V_1 || ! V_53 ||
V_11 -> V_1 -> V_5 != V_53 -> V_5 )
return - V_54 ;
} else if ( V_38 -> V_40 && ! ( V_11 -> V_55 & V_56 ) ) {
if ( ! V_11 -> V_57 ||
V_11 -> V_57 -> V_58 != V_38 -> V_40 )
return - V_54 ;
} else
return - V_54 ;
V_51 = F_54 ( V_38 , V_11 ) ;
if ( F_18 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) )
return - V_54 ;
return V_51 ;
}
T_4 * F_62 ( struct V_38 * V_38 , struct V_15 * V_16 ,
unsigned long V_51 , T_5 * * V_59 , int V_60 )
{
T_6 * V_61 ;
T_7 * V_62 ;
T_8 * V_63 ;
T_4 * V_64 ;
T_5 * V_65 ;
if ( F_18 ( F_63 ( V_38 ) ) ) {
V_64 = F_64 ( V_16 , V_51 ) ;
V_65 = & V_16 -> V_21 ;
goto V_66;
}
V_61 = F_65 ( V_16 , V_51 ) ;
if ( ! F_66 ( * V_61 ) )
return NULL ;
V_62 = F_67 ( V_61 , V_51 ) ;
if ( ! F_68 ( * V_62 ) )
return NULL ;
V_63 = F_69 ( V_62 , V_51 ) ;
if ( ! F_70 ( * V_63 ) )
return NULL ;
if ( F_71 ( * V_63 ) )
return NULL ;
V_64 = F_72 ( V_63 , V_51 ) ;
if ( ! V_60 && ! F_73 ( * V_64 ) ) {
F_74 ( V_64 ) ;
return NULL ;
}
V_65 = F_75 ( V_16 , V_63 ) ;
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
unsigned long V_51 ;
T_4 * V_64 ;
T_5 * V_65 ;
V_51 = F_54 ( V_38 , V_11 ) ;
if ( F_18 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) )
return 0 ;
V_64 = F_80 ( V_38 , V_11 -> V_17 , V_51 , & V_65 , 1 ) ;
if ( ! V_64 )
return 0 ;
F_78 ( V_64 , V_65 ) ;
return 1 ;
}
int F_81 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 , unsigned int * V_67 ,
unsigned long * V_55 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
int V_68 = 0 ;
if ( F_18 ( F_82 ( V_38 ) ) ) {
T_8 * V_63 ;
F_20 ( & V_16 -> V_21 ) ;
V_63 = F_83 ( V_38 , V_16 , V_51 ,
V_69 ) ;
if ( ! V_63 ) {
F_22 ( & V_16 -> V_21 ) ;
goto V_43;
}
if ( V_11 -> V_55 & V_70 ) {
F_22 ( & V_16 -> V_21 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_84 ( V_11 , V_51 , V_63 ) )
V_68 ++ ;
F_22 ( & V_16 -> V_21 ) ;
} else {
T_4 * V_64 ;
T_5 * V_65 ;
V_64 = F_80 ( V_38 , V_16 , V_51 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( V_11 -> V_55 & V_70 ) {
F_78 ( V_64 , V_65 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_85 ( V_11 , V_51 , V_64 ) ) {
if ( F_21 ( ! F_86 ( V_11 ) ) )
V_68 ++ ;
}
F_78 ( V_64 , V_65 ) ;
}
( * V_67 ) -- ;
if ( V_68 )
* V_55 |= V_11 -> V_55 ;
V_43:
return V_68 ;
}
static int F_87 ( struct V_38 * V_38 ,
struct V_71 * V_72 ,
unsigned long * V_55 )
{
unsigned int V_67 ;
struct V_1 * V_1 ;
T_3 V_45 ;
struct V_7 * V_12 ;
int V_68 = 0 ;
V_1 = F_49 ( V_38 ) ;
if ( ! V_1 )
return V_68 ;
V_67 = F_88 ( V_38 ) ;
V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
F_89 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_51 = F_58 ( V_38 , V_11 ) ;
if ( V_72 && ! F_90 ( V_11 -> V_17 , V_72 ) )
continue;
V_68 += F_81 ( V_38 , V_11 , V_51 ,
& V_67 , V_55 ) ;
if ( ! V_67 )
break;
}
F_53 ( V_1 ) ;
return V_68 ;
}
static int F_91 ( struct V_38 * V_38 ,
struct V_71 * V_72 ,
unsigned long * V_55 )
{
unsigned int V_67 ;
struct V_73 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_68 = 0 ;
F_92 ( F_60 ( V_38 ) ) ;
F_92 ( ! F_93 ( V_38 ) ) ;
F_27 ( & V_40 -> V_74 ) ;
V_67 = F_88 ( V_38 ) ;
F_94 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_58 ( V_38 , V_11 ) ;
if ( V_72 && ! F_90 ( V_11 -> V_17 , V_72 ) )
continue;
V_68 += F_81 ( V_38 , V_11 , V_51 ,
& V_67 , V_55 ) ;
if ( ! V_67 )
break;
}
F_26 ( & V_40 -> V_74 ) ;
return V_68 ;
}
int F_95 ( struct V_38 * V_38 ,
int V_75 ,
struct V_71 * V_72 ,
unsigned long * V_55 )
{
int V_68 = 0 ;
int V_76 = 0 ;
* V_55 = 0 ;
if ( F_46 ( V_38 ) && F_96 ( V_38 ) ) {
if ( ! V_75 && ( ! F_60 ( V_38 ) || F_97 ( V_38 ) ) ) {
V_76 = F_98 ( V_38 ) ;
if ( ! V_76 ) {
V_68 ++ ;
goto V_43;
}
}
if ( F_18 ( F_97 ( V_38 ) ) )
V_68 += F_99 ( V_38 , V_72 ,
V_55 ) ;
else if ( F_60 ( V_38 ) )
V_68 += F_87 ( V_38 , V_72 ,
V_55 ) ;
else if ( V_38 -> V_40 )
V_68 += F_91 ( V_38 , V_72 ,
V_55 ) ;
if ( V_76 )
F_100 ( V_38 ) ;
if ( F_101 ( F_76 ( V_38 ) ) )
V_68 ++ ;
}
V_43:
return V_68 ;
}
static int F_102 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_4 * V_64 ;
T_5 * V_65 ;
int V_77 = 0 ;
V_64 = F_80 ( V_38 , V_16 , V_51 , & V_65 , 1 ) ;
if ( ! V_64 )
goto V_43;
if ( F_103 ( * V_64 ) || F_104 ( * V_64 ) ) {
T_4 V_78 ;
F_105 ( V_11 , V_51 , F_77 ( * V_64 ) ) ;
V_78 = F_106 ( V_11 , V_51 , V_64 ) ;
V_78 = F_107 ( V_78 ) ;
V_78 = F_108 ( V_78 ) ;
F_109 ( V_16 , V_51 , V_64 , V_78 ) ;
V_77 = 1 ;
}
F_78 ( V_64 , V_65 ) ;
if ( V_77 )
F_110 ( V_16 , V_51 ) ;
V_43:
return V_77 ;
}
static int F_111 ( struct V_73 * V_40 , struct V_38 * V_38 )
{
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_77 = 0 ;
F_92 ( F_60 ( V_38 ) ) ;
F_27 ( & V_40 -> V_74 ) ;
F_94 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_11 -> V_55 & V_79 ) {
unsigned long V_51 = F_58 ( V_38 , V_11 ) ;
V_77 += F_102 ( V_38 , V_11 , V_51 ) ;
}
}
F_26 ( & V_40 -> V_74 ) ;
return V_77 ;
}
int F_112 ( struct V_38 * V_38 )
{
int V_77 = 0 ;
F_92 ( ! F_93 ( V_38 ) ) ;
if ( F_46 ( V_38 ) ) {
struct V_73 * V_40 = F_113 ( V_38 ) ;
if ( V_40 )
V_77 = F_111 ( V_40 , V_38 ) ;
}
return V_77 ;
}
void F_114 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_5 ( ! F_93 ( V_38 ) ) ;
F_5 ( ! V_1 ) ;
F_5 ( V_38 -> V_46 != F_115 ( V_11 , V_51 ) ) ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_73 * ) V_1 ;
}
static void F_116 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_80 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_92 ( ! V_1 ) ;
if ( F_60 ( V_38 ) )
return;
if ( ! V_80 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_73 * ) V_1 ;
V_38 -> V_46 = F_115 ( V_11 , V_51 ) ;
}
static void F_117 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
#ifdef F_118
F_92 ( F_61 ( V_38 ) -> V_5 != V_11 -> V_1 -> V_5 ) ;
F_92 ( V_38 -> V_46 != F_115 ( V_11 , V_51 ) ) ;
#endif
}
void F_119 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_120 ( V_38 , V_11 , V_51 , 0 ) ;
}
void F_120 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_80 )
{
int V_81 = F_121 ( & V_38 -> V_82 ) ;
if ( V_81 ) {
if ( ! F_82 ( V_38 ) )
F_122 ( V_38 , V_83 ) ;
else
F_122 ( V_38 ,
V_84 ) ;
}
if ( F_18 ( F_97 ( V_38 ) ) )
return;
F_5 ( ! F_93 ( V_38 ) ) ;
if ( V_81 )
F_116 ( V_38 , V_11 , V_51 , V_80 ) ;
else
F_117 ( V_38 , V_11 , V_51 ) ;
}
void F_123 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_5 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
F_124 ( V_38 ) ;
F_3 ( & V_38 -> V_82 , 0 ) ;
if ( ! F_82 ( V_38 ) )
F_122 ( V_38 , V_83 ) ;
else
F_122 ( V_38 , V_84 ) ;
F_116 ( V_38 , V_11 , V_51 , 1 ) ;
if ( ! F_125 ( V_11 , V_38 ) )
F_126 ( V_38 , V_85 ) ;
else
F_127 ( V_38 ) ;
}
void F_128 ( struct V_38 * V_38 )
{
bool V_86 ;
unsigned long V_87 ;
F_129 ( V_38 , & V_86 , & V_87 ) ;
if ( F_121 ( & V_38 -> V_82 ) ) {
F_122 ( V_38 , V_88 ) ;
F_130 ( V_38 , V_89 ) ;
}
F_131 ( V_38 , & V_86 , & V_87 ) ;
}
void F_132 ( struct V_38 * V_38 )
{
struct V_73 * V_40 = F_113 ( V_38 ) ;
bool V_90 = F_60 ( V_38 ) ;
bool V_86 ;
unsigned long V_87 ;
if ( ! V_90 )
F_129 ( V_38 , & V_86 , & V_87 ) ;
if ( ! F_133 ( - 1 , & V_38 -> V_82 ) )
goto V_43;
if ( V_40 && ! F_134 ( V_40 ) &&
F_135 ( F_76 ( V_38 ) , 1 ) )
F_136 ( V_38 ) ;
if ( F_18 ( F_63 ( V_38 ) ) )
goto V_43;
if ( V_90 ) {
F_137 ( V_38 ) ;
if ( ! F_82 ( V_38 ) )
F_138 ( V_38 , V_83 ) ;
else
F_138 ( V_38 ,
V_84 ) ;
} else {
F_138 ( V_38 , V_88 ) ;
F_139 ( V_38 , V_89 ) ;
F_131 ( V_38 , & V_86 , & V_87 ) ;
}
if ( F_18 ( F_140 ( V_38 ) ) )
F_141 ( V_38 ) ;
return;
V_43:
if ( ! V_90 )
F_131 ( V_38 , & V_86 , & V_87 ) ;
}
int F_142 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 , enum V_91 V_87 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_4 * V_64 ;
T_4 V_92 ;
T_5 * V_65 ;
int V_77 = V_93 ;
V_64 = F_80 ( V_38 , V_16 , V_51 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( ! ( V_87 & V_94 ) ) {
if ( V_11 -> V_55 & V_70 )
goto V_95;
if ( F_143 ( V_87 ) == V_96 )
goto V_97;
}
if ( ! ( V_87 & V_98 ) ) {
if ( F_85 ( V_11 , V_51 , V_64 ) ) {
V_77 = V_99 ;
goto V_97;
}
}
F_105 ( V_11 , V_51 , F_76 ( V_38 ) ) ;
V_92 = F_106 ( V_11 , V_51 , V_64 ) ;
if ( F_103 ( V_92 ) )
F_136 ( V_38 ) ;
F_144 ( V_16 ) ;
if ( F_145 ( V_38 ) && ! ( V_87 & V_100 ) ) {
if ( F_60 ( V_38 ) )
F_146 ( V_16 , V_101 ) ;
else
F_146 ( V_16 , V_102 ) ;
F_109 ( V_16 , V_51 , V_64 ,
F_147 ( F_148 ( V_38 ) ) ) ;
} else if ( F_60 ( V_38 ) ) {
T_9 V_78 = { . V_103 = F_149 (page) } ;
if ( F_150 ( V_38 ) ) {
if ( F_151 ( V_78 ) < 0 ) {
F_109 ( V_16 , V_51 , V_64 , V_92 ) ;
V_77 = V_99 ;
goto V_97;
}
if ( F_152 ( & V_16 -> V_104 ) ) {
F_20 ( & V_105 ) ;
if ( F_152 ( & V_16 -> V_104 ) )
F_14 ( & V_16 -> V_104 , & V_106 . V_104 ) ;
F_22 ( & V_105 ) ;
}
F_146 ( V_16 , V_101 ) ;
F_153 ( V_16 , V_107 ) ;
} else if ( F_154 ( V_108 ) ) {
F_92 ( F_143 ( V_87 ) != V_109 ) ;
V_78 = F_155 ( V_38 , F_104 ( V_92 ) ) ;
}
F_109 ( V_16 , V_51 , V_64 , F_147 ( V_78 ) ) ;
F_92 ( F_156 ( * V_64 ) ) ;
} else if ( F_154 ( V_108 ) &&
( F_143 ( V_87 ) == V_109 ) ) {
T_9 V_78 ;
V_78 = F_155 ( V_38 , F_104 ( V_92 ) ) ;
F_109 ( V_16 , V_51 , V_64 , F_147 ( V_78 ) ) ;
} else
F_146 ( V_16 , V_102 ) ;
F_132 ( V_38 ) ;
F_157 ( V_38 ) ;
V_97:
F_78 ( V_64 , V_65 ) ;
if ( V_77 != V_99 )
F_110 ( V_16 , V_51 ) ;
V_43:
return V_77 ;
V_95:
F_78 ( V_64 , V_65 ) ;
if ( F_158 ( & V_11 -> V_17 -> V_110 ) ) {
if ( V_11 -> V_55 & V_70 ) {
F_159 ( V_38 ) ;
V_77 = V_111 ;
}
F_160 ( & V_11 -> V_17 -> V_110 ) ;
}
return V_77 ;
}
static int F_161 ( unsigned long V_112 , unsigned int * V_67 ,
struct V_10 * V_11 , struct V_38 * V_113 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_6 * V_61 ;
T_7 * V_62 ;
T_8 * V_63 ;
T_4 * V_64 ;
T_4 V_92 ;
T_5 * V_65 ;
struct V_38 * V_38 ;
unsigned long V_51 ;
unsigned long V_114 ;
unsigned long V_115 ;
unsigned long V_116 ;
int V_77 = V_93 ;
int V_117 = 0 ;
V_51 = ( V_11 -> V_49 + V_112 ) & V_118 ;
V_116 = V_51 + V_119 ;
if ( V_51 < V_11 -> V_49 )
V_51 = V_11 -> V_49 ;
if ( V_116 > V_11 -> V_52 )
V_116 = V_11 -> V_52 ;
V_61 = F_65 ( V_16 , V_51 ) ;
if ( ! F_66 ( * V_61 ) )
return V_77 ;
V_62 = F_67 ( V_61 , V_51 ) ;
if ( ! F_68 ( * V_62 ) )
return V_77 ;
V_63 = F_69 ( V_62 , V_51 ) ;
if ( ! F_70 ( * V_63 ) )
return V_77 ;
V_114 = V_51 ;
V_115 = V_116 ;
F_162 ( V_16 , V_114 , V_115 ) ;
if ( F_158 ( & V_11 -> V_17 -> V_110 ) ) {
V_117 = ( V_11 -> V_55 & V_70 ) ;
if ( ! V_117 )
F_160 ( & V_11 -> V_17 -> V_110 ) ;
}
V_64 = F_163 ( V_16 , V_63 , V_51 , & V_65 ) ;
F_144 ( V_16 ) ;
for (; V_51 < V_116 ; V_64 ++ , V_51 += V_120 ) {
if ( ! F_73 ( * V_64 ) )
continue;
V_38 = F_164 ( V_11 , V_51 , * V_64 ) ;
F_92 ( ! V_38 || F_60 ( V_38 ) ) ;
if ( V_117 ) {
F_159 ( V_38 ) ;
if ( V_38 == V_113 )
V_77 = V_111 ;
continue;
}
if ( F_85 ( V_11 , V_51 , V_64 ) )
continue;
F_105 ( V_11 , V_51 , F_77 ( * V_64 ) ) ;
V_92 = F_106 ( V_11 , V_51 , V_64 ) ;
if ( V_38 -> V_46 != F_115 ( V_11 , V_51 ) )
F_109 ( V_16 , V_51 , V_64 , F_165 ( V_38 -> V_46 ) ) ;
if ( F_103 ( V_92 ) )
F_136 ( V_38 ) ;
F_132 ( V_38 ) ;
F_157 ( V_38 ) ;
F_146 ( V_16 , V_102 ) ;
( * V_67 ) -- ;
}
F_78 ( V_64 - 1 , V_65 ) ;
F_166 ( V_16 , V_114 , V_115 ) ;
if ( V_117 )
F_160 ( & V_11 -> V_17 -> V_110 ) ;
return V_77 ;
}
bool F_167 ( struct V_10 * V_11 )
{
int V_121 = V_11 -> V_55 & ( V_122 | V_123 ) ;
if ( ! V_121 )
return false ;
if ( ( V_11 -> V_55 & V_124 ) ==
V_124 )
return true ;
return false ;
}
static int F_168 ( struct V_38 * V_38 , enum V_91 V_87 )
{
struct V_1 * V_1 ;
T_3 V_45 ;
struct V_7 * V_12 ;
int V_77 = V_93 ;
V_1 = F_49 ( V_38 ) ;
if ( ! V_1 )
return V_77 ;
V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
F_89 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_51 ;
if ( F_154 ( V_108 ) && ( V_87 & V_109 ) &&
F_167 ( V_11 ) )
continue;
V_51 = F_58 ( V_38 , V_11 ) ;
V_77 = F_142 ( V_38 , V_11 , V_51 , V_87 ) ;
if ( V_77 != V_93 || ! F_46 ( V_38 ) )
break;
}
F_53 ( V_1 ) ;
return V_77 ;
}
static int F_169 ( struct V_38 * V_38 , enum V_91 V_87 )
{
struct V_73 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_77 = V_93 ;
unsigned long V_112 ;
unsigned long V_125 = 0 ;
unsigned long V_126 = 0 ;
unsigned int V_67 ;
F_27 ( & V_40 -> V_74 ) ;
F_94 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_58 ( V_38 , V_11 ) ;
V_77 = F_142 ( V_38 , V_11 , V_51 , V_87 ) ;
if ( V_77 != V_93 || ! F_46 ( V_38 ) )
goto V_43;
}
if ( F_152 ( & V_40 -> V_127 ) )
goto V_43;
if ( F_143 ( V_87 ) == V_96 )
goto V_43;
F_170 (vma, &mapping->i_mmap_nonlinear,
shared.nonlinear) {
V_112 = ( unsigned long ) V_11 -> V_128 ;
if ( V_112 > V_125 )
V_125 = V_112 ;
V_112 = V_11 -> V_52 - V_11 -> V_49 ;
if ( V_112 > V_126 )
V_126 = V_112 ;
}
if ( V_126 == 0 ) {
V_77 = V_99 ;
goto V_43;
}
V_67 = F_88 ( V_38 ) ;
if ( ! V_67 )
goto V_43;
F_171 () ;
V_126 = ( V_126 + V_119 - 1 ) & V_118 ;
if ( V_125 == 0 )
V_125 = V_119 ;
do {
F_170 (vma, &mapping->i_mmap_nonlinear,
shared.nonlinear) {
V_112 = ( unsigned long ) V_11 -> V_128 ;
while ( V_112 < V_125 &&
V_112 < V_11 -> V_52 - V_11 -> V_49 ) {
if ( F_161 ( V_112 , & V_67 ,
V_11 , V_38 ) == V_111 )
V_77 = V_111 ;
V_112 += V_119 ;
V_11 -> V_128 = ( void * ) V_112 ;
if ( ( int ) V_67 <= 0 )
goto V_43;
}
V_11 -> V_128 = ( void * ) V_125 ;
}
F_171 () ;
V_125 += V_119 ;
} while ( V_125 <= V_126 );
F_170 (vma, &mapping->i_mmap_nonlinear, shared.nonlinear)
V_11 -> V_128 = NULL ;
V_43:
F_26 ( & V_40 -> V_74 ) ;
return V_77 ;
}
int F_172 ( struct V_38 * V_38 , enum V_91 V_87 )
{
int V_77 ;
F_92 ( ! F_93 ( V_38 ) ) ;
F_5 ( ! F_63 ( V_38 ) && F_82 ( V_38 ) ) ;
if ( F_18 ( F_97 ( V_38 ) ) )
V_77 = F_173 ( V_38 , V_87 ) ;
else if ( F_60 ( V_38 ) )
V_77 = F_168 ( V_38 , V_87 ) ;
else
V_77 = F_169 ( V_38 , V_87 ) ;
if ( V_77 != V_111 && ! F_46 ( V_38 ) )
V_77 = V_129 ;
return V_77 ;
}
int F_174 ( struct V_38 * V_38 )
{
F_5 ( ! F_93 ( V_38 ) || F_175 ( V_38 ) ) ;
if ( F_18 ( F_97 ( V_38 ) ) )
return F_173 ( V_38 , V_96 ) ;
else if ( F_60 ( V_38 ) )
return F_168 ( V_38 , V_96 ) ;
else
return F_169 ( V_38 , V_96 ) ;
}
void F_52 ( struct V_1 * V_1 )
{
struct V_1 * V_5 = V_1 -> V_5 ;
if ( V_5 != V_1 && F_51 ( & V_5 -> V_4 ) )
F_4 ( V_5 ) ;
F_4 ( V_1 ) ;
}
static int F_176 ( struct V_38 * V_38 , int (* F_177)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_130 )
{
struct V_1 * V_1 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_7 * V_12 ;
int V_77 = V_93 ;
V_1 = F_61 ( V_38 ) ;
if ( ! V_1 )
return V_77 ;
F_8 ( V_1 ) ;
F_89 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_51 = F_58 ( V_38 , V_11 ) ;
V_77 = F_177 ( V_38 , V_11 , V_51 , V_130 ) ;
if ( V_77 != V_93 )
break;
}
F_9 ( V_1 ) ;
return V_77 ;
}
static int F_178 ( struct V_38 * V_38 , int (* F_177)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_130 )
{
struct V_73 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_77 = V_93 ;
if ( ! V_40 )
return V_77 ;
F_27 ( & V_40 -> V_74 ) ;
F_94 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_58 ( V_38 , V_11 ) ;
V_77 = F_177 ( V_38 , V_11 , V_51 , V_130 ) ;
if ( V_77 != V_93 )
break;
}
F_26 ( & V_40 -> V_74 ) ;
return V_77 ;
}
int F_179 ( struct V_38 * V_38 , int (* F_177)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_130 )
{
F_5 ( ! F_93 ( V_38 ) ) ;
if ( F_18 ( F_97 ( V_38 ) ) )
return F_180 ( V_38 , F_177 , V_130 ) ;
else if ( F_60 ( V_38 ) )
return F_176 ( V_38 , F_177 , V_130 ) ;
else
return F_178 ( V_38 , F_177 , V_130 ) ;
}
static void F_181 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_80 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_92 ( ! V_1 ) ;
if ( F_60 ( V_38 ) )
return;
if ( ! V_80 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_73 * ) V_1 ;
V_38 -> V_46 = F_115 ( V_11 , V_51 ) ;
}
void F_182 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
int V_81 ;
F_92 ( ! F_93 ( V_38 ) ) ;
F_92 ( ! V_1 ) ;
V_81 = F_121 ( & V_38 -> V_82 ) ;
if ( V_81 )
F_181 ( V_38 , V_11 , V_51 , 0 ) ;
}
void F_183 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_92 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
F_3 ( & V_38 -> V_82 , 0 ) ;
F_181 ( V_38 , V_11 , V_51 , 1 ) ;
}
