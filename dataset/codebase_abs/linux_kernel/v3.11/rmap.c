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
V_65 = & V_16 -> V_21 ;
goto V_66;
}
V_61 = F_65 ( V_16 , V_51 ) ;
if ( ! V_61 )
return NULL ;
if ( F_75 ( * V_61 ) )
return NULL ;
V_64 = F_76 ( V_61 , V_51 ) ;
if ( ! V_63 && ! F_77 ( * V_64 ) ) {
F_78 ( V_64 ) ;
return NULL ;
}
V_65 = F_79 ( V_16 , V_61 ) ;
V_66:
F_20 ( V_65 ) ;
if ( F_77 ( * V_64 ) && F_80 ( V_38 ) == F_81 ( * V_64 ) ) {
* V_62 = V_65 ;
return V_64 ;
}
F_82 ( V_64 , V_65 ) ;
return NULL ;
}
int F_83 ( struct V_38 * V_38 , struct V_10 * V_11 )
{
unsigned long V_51 ;
T_7 * V_64 ;
T_8 * V_65 ;
V_51 = F_57 ( V_38 , V_11 ) ;
if ( F_18 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) )
return 0 ;
V_64 = F_84 ( V_38 , V_11 -> V_17 , V_51 , & V_65 , 1 ) ;
if ( ! V_64 )
return 0 ;
F_82 ( V_64 , V_65 ) ;
return 1 ;
}
int F_85 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 , unsigned int * V_67 ,
unsigned long * V_55 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
int V_68 = 0 ;
if ( F_18 ( F_86 ( V_38 ) ) ) {
T_4 * V_61 ;
F_20 ( & V_16 -> V_21 ) ;
V_61 = F_87 ( V_38 , V_16 , V_51 ,
V_69 ) ;
if ( ! V_61 ) {
F_22 ( & V_16 -> V_21 ) ;
goto V_43;
}
if ( V_11 -> V_55 & V_70 ) {
F_22 ( & V_16 -> V_21 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_88 ( V_11 , V_51 , V_61 ) )
V_68 ++ ;
F_22 ( & V_16 -> V_21 ) ;
} else {
T_7 * V_64 ;
T_8 * V_65 ;
V_64 = F_84 ( V_38 , V_16 , V_51 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( V_11 -> V_55 & V_70 ) {
F_82 ( V_64 , V_65 ) ;
* V_67 = 0 ;
* V_55 |= V_70 ;
goto V_43;
}
if ( F_89 ( V_11 , V_51 , V_64 ) ) {
if ( F_21 ( ! ( V_11 -> V_55 & V_71 ) ) )
V_68 ++ ;
}
F_82 ( V_64 , V_65 ) ;
}
( * V_67 ) -- ;
if ( V_68 )
* V_55 |= V_11 -> V_55 ;
V_43:
return V_68 ;
}
static int F_90 ( struct V_38 * V_38 ,
struct V_72 * V_73 ,
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
V_67 = F_91 ( V_38 ) ;
V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
F_92 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
if ( V_73 && ! F_93 ( V_11 -> V_17 , V_73 ) )
continue;
V_68 += F_85 ( V_38 , V_11 , V_51 ,
& V_67 , V_55 ) ;
if ( ! V_67 )
break;
}
F_56 ( V_1 ) ;
return V_68 ;
}
static int F_94 ( struct V_38 * V_38 ,
struct V_72 * V_73 ,
unsigned long * V_55 )
{
unsigned int V_67 ;
struct V_74 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_68 = 0 ;
F_95 ( F_63 ( V_38 ) ) ;
F_95 ( ! F_96 ( V_38 ) ) ;
F_97 ( & V_40 -> V_75 ) ;
V_67 = F_91 ( V_38 ) ;
F_98 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
if ( V_73 && ! F_93 ( V_11 -> V_17 , V_73 ) )
continue;
V_68 += F_85 ( V_38 , V_11 , V_51 ,
& V_67 , V_55 ) ;
if ( ! V_67 )
break;
}
F_99 ( & V_40 -> V_75 ) ;
return V_68 ;
}
int F_100 ( struct V_38 * V_38 ,
int V_76 ,
struct V_72 * V_73 ,
unsigned long * V_55 )
{
int V_68 = 0 ;
int V_77 = 0 ;
* V_55 = 0 ;
if ( F_46 ( V_38 ) && F_101 ( V_38 ) ) {
if ( ! V_76 && ( ! F_63 ( V_38 ) || F_102 ( V_38 ) ) ) {
V_77 = F_103 ( V_38 ) ;
if ( ! V_77 ) {
V_68 ++ ;
goto V_43;
}
}
if ( F_18 ( F_102 ( V_38 ) ) )
V_68 += F_104 ( V_38 , V_73 ,
V_55 ) ;
else if ( F_63 ( V_38 ) )
V_68 += F_90 ( V_38 , V_73 ,
V_55 ) ;
else if ( V_38 -> V_40 )
V_68 += F_94 ( V_38 , V_73 ,
V_55 ) ;
if ( V_77 )
F_105 ( V_38 ) ;
if ( F_106 ( F_80 ( V_38 ) ) )
V_68 ++ ;
}
V_43:
return V_68 ;
}
static int F_107 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_7 * V_64 ;
T_8 * V_65 ;
int V_78 = 0 ;
V_64 = F_84 ( V_38 , V_16 , V_51 , & V_65 , 1 ) ;
if ( ! V_64 )
goto V_43;
if ( F_108 ( * V_64 ) || F_109 ( * V_64 ) ) {
T_7 V_79 ;
F_110 ( V_11 , V_51 , F_81 ( * V_64 ) ) ;
V_79 = F_111 ( V_11 , V_51 , V_64 ) ;
V_79 = F_112 ( V_79 ) ;
V_79 = F_113 ( V_79 ) ;
F_114 ( V_16 , V_51 , V_64 , V_79 ) ;
V_78 = 1 ;
}
F_82 ( V_64 , V_65 ) ;
if ( V_78 )
F_115 ( V_16 , V_51 ) ;
V_43:
return V_78 ;
}
static int F_116 ( struct V_74 * V_40 , struct V_38 * V_38 )
{
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_78 = 0 ;
F_95 ( F_63 ( V_38 ) ) ;
F_97 ( & V_40 -> V_75 ) ;
F_98 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_11 -> V_55 & V_80 ) {
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
V_78 += F_107 ( V_38 , V_11 , V_51 ) ;
}
}
F_99 ( & V_40 -> V_75 ) ;
return V_78 ;
}
int F_117 ( struct V_38 * V_38 )
{
int V_78 = 0 ;
F_95 ( ! F_96 ( V_38 ) ) ;
if ( F_46 ( V_38 ) ) {
struct V_74 * V_40 = F_118 ( V_38 ) ;
if ( V_40 )
V_78 = F_116 ( V_40 , V_38 ) ;
}
return V_78 ;
}
void F_119 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_5 ( ! F_96 ( V_38 ) ) ;
F_5 ( ! V_1 ) ;
F_5 ( V_38 -> V_46 != F_120 ( V_11 , V_51 ) ) ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_74 * ) V_1 ;
}
static void F_121 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_81 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_95 ( ! V_1 ) ;
if ( F_63 ( V_38 ) )
return;
if ( ! V_81 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_74 * ) V_1 ;
V_38 -> V_46 = F_120 ( V_11 , V_51 ) ;
}
static void F_122 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
#ifdef F_123
F_95 ( F_64 ( V_38 ) -> V_5 != V_11 -> V_1 -> V_5 ) ;
F_95 ( V_38 -> V_46 != F_120 ( V_11 , V_51 ) ) ;
#endif
}
void F_124 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_125 ( V_38 , V_11 , V_51 , 0 ) ;
}
void F_125 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_81 )
{
int V_82 = F_126 ( & V_38 -> V_83 ) ;
if ( V_82 ) {
if ( ! F_86 ( V_38 ) )
F_127 ( V_38 , V_84 ) ;
else
F_127 ( V_38 ,
V_85 ) ;
}
if ( F_18 ( F_102 ( V_38 ) ) )
return;
F_5 ( ! F_96 ( V_38 ) ) ;
if ( V_82 )
F_121 ( V_38 , V_11 , V_51 , V_81 ) ;
else
F_122 ( V_38 , V_11 , V_51 ) ;
}
void F_128 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_5 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
F_129 ( V_38 ) ;
F_3 ( & V_38 -> V_83 , 0 ) ;
if ( ! F_86 ( V_38 ) )
F_127 ( V_38 , V_84 ) ;
else
F_127 ( V_38 , V_85 ) ;
F_121 ( V_38 , V_11 , V_51 , 1 ) ;
if ( ! F_130 ( V_11 , V_38 ) ) {
F_131 ( V_38 ) ;
F_132 ( V_38 ) ;
} else
F_133 ( V_38 ) ;
}
void F_134 ( struct V_38 * V_38 )
{
bool V_86 ;
unsigned long V_87 ;
F_135 ( V_38 , & V_86 , & V_87 ) ;
if ( F_126 ( & V_38 -> V_83 ) ) {
F_127 ( V_38 , V_88 ) ;
F_136 ( V_38 , V_89 ) ;
}
F_137 ( V_38 , & V_86 , & V_87 ) ;
}
void F_138 ( struct V_38 * V_38 )
{
bool V_90 = F_63 ( V_38 ) ;
bool V_86 ;
unsigned long V_87 ;
if ( ! V_90 )
F_135 ( V_38 , & V_86 , & V_87 ) ;
if ( ! F_139 ( - 1 , & V_38 -> V_83 ) )
goto V_43;
if ( F_18 ( F_73 ( V_38 ) ) )
goto V_43;
if ( V_90 ) {
F_140 ( V_38 ) ;
if ( ! F_86 ( V_38 ) )
F_141 ( V_38 , V_84 ) ;
else
F_141 ( V_38 ,
V_85 ) ;
} else {
F_141 ( V_38 , V_88 ) ;
F_142 ( V_38 , V_89 ) ;
F_137 ( V_38 , & V_86 , & V_87 ) ;
}
if ( F_18 ( F_143 ( V_38 ) ) )
F_144 ( V_38 ) ;
return;
V_43:
if ( ! V_90 )
F_137 ( V_38 , & V_86 , & V_87 ) ;
}
int F_145 ( struct V_38 * V_38 , struct V_10 * V_11 ,
unsigned long V_51 , enum V_91 V_87 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_7 * V_64 ;
T_7 V_92 ;
T_8 * V_65 ;
int V_78 = V_93 ;
V_64 = F_84 ( V_38 , V_16 , V_51 , & V_65 , 0 ) ;
if ( ! V_64 )
goto V_43;
if ( ! ( V_87 & V_94 ) ) {
if ( V_11 -> V_55 & V_70 )
goto V_95;
if ( F_146 ( V_87 ) == V_96 )
goto V_97;
}
if ( ! ( V_87 & V_98 ) ) {
if ( F_89 ( V_11 , V_51 , V_64 ) ) {
V_78 = V_99 ;
goto V_97;
}
}
F_110 ( V_11 , V_51 , F_80 ( V_38 ) ) ;
V_92 = F_111 ( V_11 , V_51 , V_64 ) ;
if ( F_108 ( V_92 ) )
F_147 ( V_38 ) ;
F_148 ( V_16 ) ;
if ( F_149 ( V_38 ) && ! ( V_87 & V_100 ) ) {
if ( ! F_73 ( V_38 ) ) {
if ( F_63 ( V_38 ) )
F_150 ( V_16 , V_101 ) ;
else
F_150 ( V_16 , V_102 ) ;
}
F_114 ( V_16 , V_51 , V_64 ,
F_151 ( F_152 ( V_38 ) ) ) ;
} else if ( F_63 ( V_38 ) ) {
T_9 V_79 = { . V_103 = F_153 (page) } ;
T_7 V_104 ;
if ( F_154 ( V_38 ) ) {
if ( F_155 ( V_79 ) < 0 ) {
F_114 ( V_16 , V_51 , V_64 , V_92 ) ;
V_78 = V_99 ;
goto V_97;
}
if ( F_156 ( & V_16 -> V_105 ) ) {
F_20 ( & V_106 ) ;
if ( F_156 ( & V_16 -> V_105 ) )
F_14 ( & V_16 -> V_105 , & V_107 . V_105 ) ;
F_22 ( & V_106 ) ;
}
F_150 ( V_16 , V_101 ) ;
F_157 ( V_16 , V_108 ) ;
} else if ( F_158 ( V_109 ) ) {
F_95 ( F_146 ( V_87 ) != V_110 ) ;
V_79 = F_159 ( V_38 , F_109 ( V_92 ) ) ;
}
V_104 = F_151 ( V_79 ) ;
if ( F_160 ( V_92 ) )
V_104 = F_161 ( V_104 ) ;
F_114 ( V_16 , V_51 , V_64 , V_104 ) ;
F_95 ( F_162 ( * V_64 ) ) ;
} else if ( F_158 ( V_109 ) &&
( F_146 ( V_87 ) == V_110 ) ) {
T_9 V_79 ;
V_79 = F_159 ( V_38 , F_109 ( V_92 ) ) ;
F_114 ( V_16 , V_51 , V_64 , F_151 ( V_79 ) ) ;
} else
F_150 ( V_16 , V_102 ) ;
F_138 ( V_38 ) ;
F_163 ( V_38 ) ;
V_97:
F_82 ( V_64 , V_65 ) ;
if ( V_78 != V_99 )
F_115 ( V_16 , V_51 ) ;
V_43:
return V_78 ;
V_95:
F_82 ( V_64 , V_65 ) ;
if ( F_50 ( & V_11 -> V_17 -> V_111 ) ) {
if ( V_11 -> V_55 & V_70 ) {
F_164 ( V_38 ) ;
V_78 = V_112 ;
}
F_51 ( & V_11 -> V_17 -> V_111 ) ;
}
return V_78 ;
}
static int F_165 ( unsigned long V_113 , unsigned int * V_67 ,
struct V_10 * V_11 , struct V_38 * V_114 )
{
struct V_15 * V_16 = V_11 -> V_17 ;
T_4 * V_61 ;
T_7 * V_64 ;
T_7 V_92 ;
T_8 * V_65 ;
struct V_38 * V_38 ;
unsigned long V_51 ;
unsigned long V_115 ;
unsigned long V_116 ;
unsigned long V_117 ;
int V_78 = V_93 ;
int V_118 = 0 ;
V_51 = ( V_11 -> V_49 + V_113 ) & V_119 ;
V_117 = V_51 + V_120 ;
if ( V_51 < V_11 -> V_49 )
V_51 = V_11 -> V_49 ;
if ( V_117 > V_11 -> V_52 )
V_117 = V_11 -> V_52 ;
V_61 = F_65 ( V_16 , V_51 ) ;
if ( ! V_61 )
return V_78 ;
V_115 = V_51 ;
V_116 = V_117 ;
F_166 ( V_16 , V_115 , V_116 ) ;
if ( F_50 ( & V_11 -> V_17 -> V_111 ) ) {
V_118 = ( V_11 -> V_55 & V_70 ) ;
if ( ! V_118 )
F_51 ( & V_11 -> V_17 -> V_111 ) ;
}
V_64 = F_167 ( V_16 , V_61 , V_51 , & V_65 ) ;
F_148 ( V_16 ) ;
for (; V_51 < V_117 ; V_64 ++ , V_51 += V_121 ) {
if ( ! F_77 ( * V_64 ) )
continue;
V_38 = F_168 ( V_11 , V_51 , * V_64 ) ;
F_95 ( ! V_38 || F_63 ( V_38 ) ) ;
if ( V_118 ) {
F_164 ( V_38 ) ;
if ( V_38 == V_114 )
V_78 = V_112 ;
continue;
}
if ( F_89 ( V_11 , V_51 , V_64 ) )
continue;
F_110 ( V_11 , V_51 , F_81 ( * V_64 ) ) ;
V_92 = F_111 ( V_11 , V_51 , V_64 ) ;
if ( V_38 -> V_46 != F_120 ( V_11 , V_51 ) ) {
T_7 V_122 = F_169 ( V_38 -> V_46 ) ;
if ( F_160 ( V_92 ) )
F_170 ( V_122 ) ;
F_114 ( V_16 , V_51 , V_64 , V_122 ) ;
}
if ( F_108 ( V_92 ) )
F_147 ( V_38 ) ;
F_138 ( V_38 ) ;
F_163 ( V_38 ) ;
F_150 ( V_16 , V_102 ) ;
( * V_67 ) -- ;
}
F_82 ( V_64 - 1 , V_65 ) ;
F_171 ( V_16 , V_115 , V_116 ) ;
if ( V_118 )
F_51 ( & V_11 -> V_17 -> V_111 ) ;
return V_78 ;
}
bool F_172 ( struct V_10 * V_11 )
{
int V_123 = V_11 -> V_55 & ( V_124 | V_125 ) ;
if ( ! V_123 )
return false ;
if ( ( V_11 -> V_55 & V_126 ) ==
V_126 )
return true ;
return false ;
}
static int F_173 ( struct V_38 * V_38 , enum V_91 V_87 )
{
struct V_1 * V_1 ;
T_3 V_45 ;
struct V_7 * V_12 ;
int V_78 = V_93 ;
V_1 = F_49 ( V_38 ) ;
if ( ! V_1 )
return V_78 ;
V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
F_92 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_51 ;
if ( F_158 ( V_109 ) && ( V_87 & V_110 ) &&
F_172 ( V_11 ) )
continue;
V_51 = F_61 ( V_38 , V_11 ) ;
V_78 = F_145 ( V_38 , V_11 , V_51 , V_87 ) ;
if ( V_78 != V_93 || ! F_46 ( V_38 ) )
break;
}
F_56 ( V_1 ) ;
return V_78 ;
}
static int F_174 ( struct V_38 * V_38 , enum V_91 V_87 )
{
struct V_74 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_78 = V_93 ;
unsigned long V_113 ;
unsigned long V_127 = 0 ;
unsigned long V_128 = 0 ;
unsigned int V_67 ;
if ( F_73 ( V_38 ) )
V_45 = V_38 -> V_46 << F_175 ( V_38 ) ;
F_97 ( & V_40 -> V_75 ) ;
F_98 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
V_78 = F_145 ( V_38 , V_11 , V_51 , V_87 ) ;
if ( V_78 != V_93 || ! F_46 ( V_38 ) )
goto V_43;
}
if ( F_156 ( & V_40 -> V_129 ) )
goto V_43;
if ( F_146 ( V_87 ) == V_96 )
goto V_43;
F_176 (vma, &mapping->i_mmap_nonlinear,
shared.nonlinear) {
V_113 = ( unsigned long ) V_11 -> V_130 ;
if ( V_113 > V_127 )
V_127 = V_113 ;
V_113 = V_11 -> V_52 - V_11 -> V_49 ;
if ( V_113 > V_128 )
V_128 = V_113 ;
}
if ( V_128 == 0 ) {
V_78 = V_99 ;
goto V_43;
}
V_67 = F_91 ( V_38 ) ;
if ( ! V_67 )
goto V_43;
F_177 () ;
V_128 = ( V_128 + V_120 - 1 ) & V_119 ;
if ( V_127 == 0 )
V_127 = V_120 ;
do {
F_176 (vma, &mapping->i_mmap_nonlinear,
shared.nonlinear) {
V_113 = ( unsigned long ) V_11 -> V_130 ;
while ( V_113 < V_127 &&
V_113 < V_11 -> V_52 - V_11 -> V_49 ) {
if ( F_165 ( V_113 , & V_67 ,
V_11 , V_38 ) == V_112 )
V_78 = V_112 ;
V_113 += V_120 ;
V_11 -> V_130 = ( void * ) V_113 ;
if ( ( int ) V_67 <= 0 )
goto V_43;
}
V_11 -> V_130 = ( void * ) V_127 ;
}
F_177 () ;
V_127 += V_120 ;
} while ( V_127 <= V_128 );
F_176 (vma, &mapping->i_mmap_nonlinear, shared.nonlinear)
V_11 -> V_130 = NULL ;
V_43:
F_99 ( & V_40 -> V_75 ) ;
return V_78 ;
}
int F_178 ( struct V_38 * V_38 , enum V_91 V_87 )
{
int V_78 ;
F_95 ( ! F_96 ( V_38 ) ) ;
F_5 ( ! F_73 ( V_38 ) && F_86 ( V_38 ) ) ;
if ( F_18 ( F_102 ( V_38 ) ) )
V_78 = F_179 ( V_38 , V_87 ) ;
else if ( F_63 ( V_38 ) )
V_78 = F_173 ( V_38 , V_87 ) ;
else
V_78 = F_174 ( V_38 , V_87 ) ;
if ( V_78 != V_112 && ! F_46 ( V_38 ) )
V_78 = V_131 ;
return V_78 ;
}
int F_180 ( struct V_38 * V_38 )
{
F_5 ( ! F_96 ( V_38 ) || F_181 ( V_38 ) ) ;
if ( F_18 ( F_102 ( V_38 ) ) )
return F_179 ( V_38 , V_96 ) ;
else if ( F_63 ( V_38 ) )
return F_173 ( V_38 , V_96 ) ;
else
return F_174 ( V_38 , V_96 ) ;
}
void F_55 ( struct V_1 * V_1 )
{
struct V_1 * V_5 = V_1 -> V_5 ;
if ( V_5 != V_1 && F_53 ( & V_5 -> V_4 ) )
F_4 ( V_5 ) ;
F_4 ( V_1 ) ;
}
static int F_182 ( struct V_38 * V_38 , int (* F_183)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_132 )
{
struct V_1 * V_1 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_7 * V_12 ;
int V_78 = V_93 ;
V_1 = F_64 ( V_38 ) ;
if ( ! V_1 )
return V_78 ;
F_52 ( V_1 ) ;
F_92 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_10 * V_11 = V_12 -> V_11 ;
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
V_78 = F_183 ( V_38 , V_11 , V_51 , V_132 ) ;
if ( V_78 != V_93 )
break;
}
F_54 ( V_1 ) ;
return V_78 ;
}
static int F_184 ( struct V_38 * V_38 , int (* F_183)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_132 )
{
struct V_74 * V_40 = V_38 -> V_40 ;
T_3 V_45 = V_38 -> V_46 << ( V_47 - V_48 ) ;
struct V_10 * V_11 ;
int V_78 = V_93 ;
if ( ! V_40 )
return V_78 ;
F_97 ( & V_40 -> V_75 ) ;
F_98 (vma, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_51 = F_61 ( V_38 , V_11 ) ;
V_78 = F_183 ( V_38 , V_11 , V_51 , V_132 ) ;
if ( V_78 != V_93 )
break;
}
F_99 ( & V_40 -> V_75 ) ;
return V_78 ;
}
int F_185 ( struct V_38 * V_38 , int (* F_183)( struct V_38 * ,
struct V_10 * , unsigned long , void * ) , void * V_132 )
{
F_5 ( ! F_96 ( V_38 ) ) ;
if ( F_18 ( F_102 ( V_38 ) ) )
return F_186 ( V_38 , F_183 , V_132 ) ;
else if ( F_63 ( V_38 ) )
return F_182 ( V_38 , F_183 , V_132 ) ;
else
return F_184 ( V_38 , F_183 , V_132 ) ;
}
static void F_187 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 , int V_81 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
F_95 ( ! V_1 ) ;
if ( F_63 ( V_38 ) )
return;
if ( ! V_81 )
V_1 = V_1 -> V_5 ;
V_1 = ( void * ) V_1 + V_42 ;
V_38 -> V_40 = (struct V_74 * ) V_1 ;
V_38 -> V_46 = F_120 ( V_11 , V_51 ) ;
}
void F_188 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
int V_82 ;
F_95 ( ! F_96 ( V_38 ) ) ;
F_95 ( ! V_1 ) ;
V_82 = F_126 ( & V_38 -> V_83 ) ;
if ( V_82 )
F_187 ( V_38 , V_11 , V_51 , 0 ) ;
}
void F_189 ( struct V_38 * V_38 ,
struct V_10 * V_11 , unsigned long V_51 )
{
F_95 ( V_51 < V_11 -> V_49 || V_51 >= V_11 -> V_52 ) ;
F_3 ( & V_38 -> V_83 , 0 ) ;
F_187 ( V_38 , V_11 , V_51 , 1 ) ;
}
