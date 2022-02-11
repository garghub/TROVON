static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
if ( V_6 == ~ 0U &&
V_7 == ~ 0U )
return 0 ;
if ( F_2 ( V_2 ) )
return - V_8 ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL || V_4 -> V_9 == NULL )
return - V_8 ;
V_5 = V_4 -> V_9 -> V_10 -> V_11 ;
if ( V_6 != ~ 0U &&
V_6 != F_4 ( V_5 ) )
return - V_8 ;
if ( V_7 != ~ 0U &&
V_7 != F_5 ( V_5 ) )
return - V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( ! V_12 )
return 0 ;
if ( ( F_7 ( V_2 ) & V_12 ) ==
V_13 )
return 0 ;
else
return - V_8 ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( ! V_14 )
return 0 ;
if ( F_9 ( V_2 ) != V_14 )
return - V_8 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ) { return 0 ; }
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_15 )
return 0 ;
if ( F_1 ( V_2 ) )
return - V_8 ;
if ( F_6 ( V_2 ) )
return - V_8 ;
if ( F_8 ( V_2 ) )
return - V_8 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_16 * V_17 , unsigned long V_18 , int V_19 ,
unsigned long V_20 , struct V_1 * V_1 , int V_21 )
{
struct V_22 V_23 ;
int V_24 ;
F_12 ( L_1 ,
V_20 , V_17 -> V_25 , V_17 -> V_26 ) ;
V_23 . V_27 = V_28 ;
V_23 . V_29 = 0 ;
V_23 . V_30 = ( void * ) V_18 ;
#ifdef F_13
V_23 . V_31 = V_19 ;
#endif
V_23 . V_32 = F_14 ( F_15 ( V_1 ) ) + V_33 ;
if ( ( V_21 & V_34 ) && V_17 -> V_35 == V_36 -> V_35 ) {
V_23 . V_37 = V_38 ;
V_24 = F_16 ( V_28 , & V_23 , V_36 ) ;
} else {
V_23 . V_37 = V_39 ;
V_24 = F_17 ( V_28 , & V_23 , V_17 ) ;
}
if ( V_24 < 0 )
F_18 ( L_2 ,
V_17 -> V_25 , V_17 -> V_26 , V_24 ) ;
return V_24 ;
}
void F_19 ( struct V_1 * V_2 , int V_40 )
{
if ( F_20 ( V_2 ) )
return;
if ( ! F_2 ( V_2 ) ) {
F_21 () ;
if ( F_22 ( V_2 ) )
return;
F_23 ( F_24 ( V_2 ) ) ;
if ( F_22 ( V_2 ) || F_25 ( V_2 ) )
return;
}
if ( V_40 )
F_26 ( F_27 ( V_2 ) ) ;
}
static void F_28 ( struct V_16 * V_41 , struct V_1 * V_2 ,
struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_45 * * V_46 )
{
struct V_45 * V_47 ;
if ( * V_46 ) {
V_47 = * V_46 ;
* V_46 = NULL ;
} else {
V_47 = F_29 ( sizeof( struct V_45 ) , V_48 ) ;
if ( ! V_47 ) {
F_12 ( L_3 ) ;
return;
}
}
V_47 -> V_18 = F_30 ( V_2 , V_43 ) ;
V_47 -> V_49 = 1 ;
if ( V_47 -> V_18 == - V_50 ) {
F_18 ( L_4 ,
F_31 ( V_2 ) , V_41 -> V_25 ) ;
V_47 -> V_49 = 0 ;
}
F_32 ( V_41 ) ;
V_47 -> V_41 = V_41 ;
F_33 ( & V_47 -> V_51 , V_45 ) ;
}
static void F_34 ( struct V_44 * V_45 , int V_52 , int V_19 ,
bool V_53 , struct V_1 * V_1 , unsigned long V_20 ,
int V_21 )
{
struct V_45 * V_47 , * V_54 ;
F_35 (tk, next, to_kill, nd) {
if ( V_52 ) {
if ( V_53 || V_47 -> V_49 == 0 ) {
F_12 ( L_5 ,
V_20 , V_47 -> V_41 -> V_25 , V_47 -> V_41 -> V_26 ) ;
F_36 ( V_55 , V_47 -> V_41 ) ;
}
else if ( F_11 ( V_47 -> V_41 , V_47 -> V_18 , V_19 ,
V_20 , V_1 , V_21 ) < 0 )
F_12 ( L_6 ,
V_20 , V_47 -> V_41 -> V_25 , V_47 -> V_41 -> V_26 ) ;
}
F_37 ( V_47 -> V_41 ) ;
F_38 ( V_47 ) ;
}
}
static struct V_16 * F_39 ( struct V_16 * V_41 )
{
struct V_16 * V_17 ;
F_40 (tsk, t)
if ( ( V_17 -> V_21 & V_56 ) && ( V_17 -> V_21 & V_57 ) )
return V_17 ;
return NULL ;
}
static struct V_16 * F_41 ( struct V_16 * V_41 ,
int V_58 )
{
struct V_16 * V_17 ;
if ( ! V_41 -> V_35 )
return NULL ;
if ( V_58 )
return V_41 ;
V_17 = F_39 ( V_41 ) ;
if ( V_17 )
return V_17 ;
if ( V_59 )
return V_41 ;
return NULL ;
}
static void F_42 ( struct V_1 * V_1 , struct V_44 * V_45 ,
struct V_45 * * V_46 , int V_58 )
{
struct V_42 * V_43 ;
struct V_16 * V_41 ;
struct V_60 * V_61 ;
T_2 V_62 ;
V_61 = F_43 ( V_1 ) ;
if ( V_61 == NULL )
return;
V_62 = F_44 ( V_1 ) ;
F_45 ( & V_63 ) ;
F_46 (tsk) {
struct V_64 * V_65 ;
struct V_16 * V_17 = F_41 ( V_41 , V_58 ) ;
if ( ! V_17 )
continue;
F_47 (vmac, &av->rb_root,
pgoff, pgoff) {
V_43 = V_65 -> V_43 ;
if ( ! F_48 ( V_1 , V_43 ) )
continue;
if ( V_43 -> V_66 == V_17 -> V_35 )
F_28 ( V_17 , V_1 , V_43 , V_45 , V_46 ) ;
}
}
F_49 ( & V_63 ) ;
F_50 ( V_61 ) ;
}
static void F_51 ( struct V_1 * V_1 , struct V_44 * V_45 ,
struct V_45 * * V_46 , int V_58 )
{
struct V_42 * V_43 ;
struct V_16 * V_41 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_52 ( V_4 ) ;
F_45 ( & V_63 ) ;
F_46 (tsk) {
T_2 V_62 = F_44 ( V_1 ) ;
struct V_16 * V_17 = F_41 ( V_41 , V_58 ) ;
if ( ! V_17 )
continue;
F_53 (vma, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_43 -> V_66 == V_17 -> V_35 )
F_28 ( V_17 , V_1 , V_43 , V_45 , V_46 ) ;
}
}
F_49 ( & V_63 ) ;
F_54 ( V_4 ) ;
}
static void F_55 ( struct V_1 * V_1 , struct V_44 * V_67 ,
int V_58 )
{
struct V_45 * V_47 ;
if ( ! V_1 -> V_4 )
return;
V_47 = F_29 ( sizeof( struct V_45 ) , V_68 ) ;
if ( ! V_47 )
return;
if ( F_56 ( V_1 ) )
F_42 ( V_1 , V_67 , & V_47 , V_58 ) ;
else
F_51 ( V_1 , V_67 , & V_47 , V_58 ) ;
F_38 ( V_47 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
if ( ! F_58 ( V_2 ) ) {
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
return - V_69 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned long V_20 )
{
return V_70 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_12 ( L_7 , V_20 ) ;
return V_71 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned long V_20 )
{
int V_72 ;
int V_24 = V_71 ;
struct V_3 * V_4 ;
F_57 ( V_2 ) ;
if ( F_56 ( V_2 ) )
return V_73 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_71 ;
}
if ( V_4 -> V_74 -> V_75 ) {
V_72 = V_4 -> V_74 -> V_75 ( V_4 , V_2 ) ;
if ( V_72 != 0 ) {
F_18 ( L_8 ,
V_20 , V_72 ) ;
} else if ( F_66 ( V_2 ) &&
! F_67 ( V_2 , V_68 ) ) {
F_18 ( L_9 ,
V_20 ) ;
} else {
V_24 = V_73 ;
}
} else {
if ( F_68 ( V_2 ) )
V_24 = V_73 ;
else
F_18 ( L_10 ,
V_20 ) ;
}
return V_24 ;
}
static int F_69 ( struct V_1 * V_2 , unsigned long V_20 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_70 ( V_2 ) ;
if ( V_4 ) {
F_71 ( V_4 , V_69 ) ;
}
return F_65 ( V_2 , V_20 ) ;
}
static int F_72 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
if ( ! F_57 ( V_2 ) )
return V_76 ;
else
return V_71 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_76 ( V_2 ) ;
if ( ! F_57 ( V_2 ) )
return V_73 ;
else
return V_71 ;
}
static int F_77 ( struct V_1 * V_2 , unsigned long V_20 )
{
int V_77 = 0 ;
struct V_1 * V_78 = F_15 ( V_2 ) ;
if ( ! F_20 ( V_78 ) )
return V_76 ;
if ( ! ( F_3 ( V_78 ) || F_56 ( V_78 ) ) ) {
V_77 = F_78 ( V_78 ) ;
if ( ! V_77 )
return V_73 ;
}
return V_76 ;
}
static void F_79 ( unsigned long V_20 , enum V_79 type ,
enum V_80 V_81 )
{
F_80 ( V_20 , type , V_81 ) ;
F_12 ( L_11 ,
V_20 , V_82 [ type ] , V_83 [ V_81 ] ) ;
}
static int F_81 ( struct V_84 * V_85 , struct V_1 * V_2 ,
unsigned long V_20 )
{
int V_81 ;
int V_86 ;
V_81 = V_85 -> V_87 ( V_2 , V_20 ) ;
V_86 = F_82 ( V_2 ) - 1 ;
if ( V_85 -> V_87 == F_72 && V_81 == V_76 )
V_86 -- ;
if ( V_86 != 0 ) {
F_12 ( L_12 ,
V_20 , V_82 [ V_85 -> type ] , V_86 ) ;
V_81 = V_71 ;
}
F_79 ( V_20 , V_85 -> type , V_81 ) ;
return ( V_81 == V_73 || V_81 == V_76 ) ? 0 : - V_88 ;
}
int F_83 ( struct V_1 * V_1 )
{
struct V_1 * V_89 = F_15 ( V_1 ) ;
if ( ! F_20 ( V_89 ) && F_84 ( V_89 ) ) {
if ( ! F_56 ( V_89 ) ) {
F_12 ( L_13 ,
F_31 ( V_1 ) ) ;
return 0 ;
}
}
if ( F_85 ( V_89 ) ) {
if ( V_89 == F_15 ( V_1 ) )
return 1 ;
F_18 ( L_14 ,
F_31 ( V_1 ) ) ;
F_62 ( V_89 ) ;
}
return 0 ;
}
static bool F_86 ( struct V_1 * V_2 , unsigned long V_20 ,
int V_19 , int V_21 , struct V_1 * * V_90 )
{
enum V_91 V_92 = V_93 | V_94 ;
struct V_3 * V_4 ;
F_87 ( V_67 ) ;
bool V_95 ;
int V_96 = 1 , V_52 ;
struct V_1 * V_78 = * V_90 ;
bool V_97 = F_88 ( V_78 ) ;
if ( F_89 ( V_2 ) || F_2 ( V_2 ) )
return true ;
if ( ! ( F_22 ( V_78 ) || F_20 ( V_2 ) ) )
return true ;
if ( ! F_90 ( V_78 ) )
return true ;
if ( F_91 ( V_2 ) ) {
F_12 ( L_15 , V_20 ) ;
return false ;
}
if ( F_92 ( V_2 ) ) {
F_12 ( L_16 ,
V_20 ) ;
V_92 |= V_98 ;
}
V_4 = F_3 ( V_78 ) ;
if ( ! ( V_21 & V_99 ) && ! F_93 ( V_78 ) && V_4 &&
F_94 ( V_4 ) ) {
if ( F_95 ( V_78 ) ) {
F_96 ( V_78 ) ;
} else {
V_96 = 0 ;
V_92 |= V_98 ;
F_18 ( L_17 ,
V_20 ) ;
}
}
if ( V_96 )
F_55 ( V_78 , & V_67 , V_21 & V_34 ) ;
V_95 = F_97 ( V_78 , V_92 ) ;
if ( ! V_95 )
F_12 ( L_18 ,
V_20 , F_98 ( V_78 ) ) ;
if ( V_97 )
F_19 ( V_78 , 0 ) ;
V_52 = F_93 ( V_78 ) || ( V_21 & V_99 ) ;
F_34 ( & V_67 , V_52 , V_19 , ! V_95 , V_2 , V_20 , V_21 ) ;
return V_95 ;
}
static void F_99 ( struct V_1 * V_78 )
{
int V_100 ;
int V_101 = 1 << F_14 ( V_78 ) ;
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ )
F_100 ( V_78 + V_100 ) ;
}
static void F_101 ( struct V_1 * V_78 )
{
int V_100 ;
int V_101 = 1 << F_14 ( V_78 ) ;
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ )
F_102 ( V_78 + V_100 ) ;
}
int F_103 ( unsigned long V_20 , int V_19 , int V_21 )
{
struct V_84 * V_85 ;
struct V_1 * V_2 ;
struct V_1 * V_78 ;
struct V_1 * V_102 ;
int V_77 ;
unsigned int V_101 ;
unsigned long V_103 ;
if ( ! V_104 )
F_104 ( L_19 , V_19 , V_20 ) ;
if ( ! F_105 ( V_20 ) ) {
F_12 ( L_20 ,
V_20 ) ;
return - V_105 ;
}
V_2 = F_106 ( V_20 ) ;
V_102 = V_78 = F_15 ( V_2 ) ;
if ( F_107 ( V_2 ) ) {
F_12 ( L_21 ,
V_20 ) ;
return 0 ;
}
if ( F_20 ( V_2 ) )
V_101 = 1 << F_14 ( V_78 ) ;
else
V_101 = 1 ;
F_108 ( V_101 ) ;
if ( ! ( V_21 & V_106 ) && ! F_83 ( V_2 ) ) {
if ( F_25 ( V_2 ) ) {
F_79 ( V_20 , V_107 , V_76 ) ;
return 0 ;
} else if ( F_20 ( V_78 ) ) {
F_109 ( V_78 ) ;
if ( F_110 ( V_78 ) ) {
if ( ( F_10 ( V_2 ) && F_111 ( V_2 ) )
|| ( V_2 != V_78 && F_107 ( V_78 ) ) ) {
F_112 ( V_101 ) ;
F_113 ( V_78 ) ;
return 0 ;
}
}
F_99 ( V_78 ) ;
V_77 = F_78 ( V_78 ) ;
F_79 ( V_20 , V_108 ,
V_77 ? V_70 : V_76 ) ;
F_113 ( V_78 ) ;
return V_77 ;
} else {
F_79 ( V_20 , V_109 , V_70 ) ;
return - V_88 ;
}
}
if ( ! F_20 ( V_2 ) && F_84 ( V_78 ) ) {
F_109 ( V_2 ) ;
if ( ! F_56 ( V_2 ) || F_114 ( F_115 ( V_2 ) ) ) {
F_113 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
F_12 ( L_13 ,
V_20 ) ;
else
F_12 ( L_22 ,
V_20 ) ;
if ( F_111 ( V_2 ) )
F_112 ( V_101 ) ;
F_116 ( V_2 ) ;
return - V_88 ;
}
F_113 ( V_2 ) ;
F_117 ( ! F_82 ( V_2 ) , V_2 ) ;
V_78 = F_15 ( V_2 ) ;
}
F_19 ( V_2 , 0 ) ;
if ( ! F_22 ( V_2 ) && F_25 ( V_2 ) ) {
if ( V_21 & V_106 )
F_79 ( V_20 , V_107 , V_76 ) ;
else
F_79 ( V_20 , V_110 , V_76 ) ;
return 0 ;
}
F_109 ( V_78 ) ;
if ( F_118 ( V_2 ) && F_15 ( V_2 ) != V_102 ) {
F_79 ( V_20 , V_111 , V_70 ) ;
V_77 = - V_88 ;
goto V_112;
}
if ( F_20 ( V_2 ) )
V_103 = V_78 -> V_21 ;
else
V_103 = V_2 -> V_21 ;
if ( ! F_110 ( V_2 ) ) {
F_12 ( L_23 , V_20 ) ;
F_112 ( V_101 ) ;
F_113 ( V_78 ) ;
F_116 ( V_78 ) ;
return 0 ;
}
if ( F_10 ( V_2 ) ) {
if ( F_111 ( V_2 ) )
F_112 ( V_101 ) ;
F_113 ( V_78 ) ;
F_116 ( V_78 ) ;
return 0 ;
}
if ( ! F_20 ( V_2 ) && ! F_119 ( V_2 ) && ! F_22 ( V_2 ) )
goto V_113;
if ( F_20 ( V_2 ) && F_120 ( V_2 ) && F_107 ( V_78 ) ) {
F_79 ( V_20 , V_114 , V_70 ) ;
F_113 ( V_78 ) ;
F_116 ( V_78 ) ;
return 0 ;
}
if ( F_20 ( V_2 ) )
F_99 ( V_78 ) ;
F_121 ( V_2 ) ;
if ( ! F_86 ( V_2 , V_20 , V_19 , V_21 , & V_78 ) ) {
F_79 ( V_20 , V_115 , V_70 ) ;
V_77 = - V_88 ;
goto V_112;
}
if ( F_22 ( V_2 ) && ! F_92 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_79 ( V_20 , V_116 , V_70 ) ;
V_77 = - V_88 ;
goto V_112;
}
V_113:
V_77 = - V_88 ;
for ( V_85 = V_117 ; ; V_85 ++ )
if ( ( V_2 -> V_21 & V_85 -> V_118 ) == V_85 -> V_77 )
break;
V_103 |= ( V_2 -> V_21 & ( 1UL << V_119 ) ) ;
if ( ! V_85 -> V_118 )
for ( V_85 = V_117 ; ; V_85 ++ )
if ( ( V_103 & V_85 -> V_118 ) == V_85 -> V_77 )
break;
V_77 = F_81 ( V_85 , V_2 , V_20 ) ;
V_112:
F_113 ( V_78 ) ;
return V_77 ;
}
void F_122 ( unsigned long V_20 , int V_19 , int V_21 )
{
struct V_120 * V_121 ;
unsigned long V_122 ;
struct V_123 V_124 = {
. V_20 = V_20 ,
. V_19 = V_19 ,
. V_21 = V_21 ,
} ;
V_121 = & F_123 ( V_120 ) ;
F_124 ( & V_121 -> V_125 , V_122 ) ;
if ( F_125 ( & V_121 -> V_126 , V_124 ) )
F_126 ( F_127 () , & V_121 -> V_127 ) ;
else
F_12 ( L_24 ,
V_20 ) ;
F_128 ( & V_121 -> V_125 , V_122 ) ;
F_129 ( V_120 ) ;
}
static void F_130 ( struct V_128 * V_127 )
{
struct V_120 * V_121 ;
struct V_123 V_124 = { 0 , } ;
unsigned long V_122 ;
int V_129 ;
V_121 = F_131 ( & V_120 ) ;
for (; ; ) {
F_124 ( & V_121 -> V_125 , V_122 ) ;
V_129 = F_132 ( & V_121 -> V_126 , & V_124 ) ;
F_128 ( & V_121 -> V_125 , V_122 ) ;
if ( ! V_129 )
break;
if ( V_124 . V_21 & V_130 )
F_133 ( F_106 ( V_124 . V_20 ) , V_124 . V_21 ) ;
else
F_103 ( V_124 . V_20 , V_124 . V_19 , V_124 . V_21 ) ;
}
}
static int T_3 F_134 ( void )
{
struct V_120 * V_121 ;
int V_131 ;
F_135 (cpu) {
V_121 = & F_136 ( V_120 , V_131 ) ;
F_137 ( & V_121 -> V_125 ) ;
F_138 ( V_121 -> V_126 ) ;
F_139 ( & V_121 -> V_127 , F_130 ) ;
}
return 0 ;
}
int F_140 ( unsigned long V_20 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_132 = 0 ;
unsigned int V_101 ;
static F_141 ( V_133 , V_134 ,
V_135 ) ;
if ( ! F_105 ( V_20 ) )
return - V_105 ;
V_2 = F_106 ( V_20 ) ;
V_1 = F_15 ( V_2 ) ;
if ( ! F_110 ( V_2 ) ) {
F_142 ( L_25 ,
V_20 , & V_133 ) ;
return 0 ;
}
if ( F_82 ( V_1 ) > 1 ) {
F_142 ( L_26 ,
V_20 , & V_133 ) ;
return 0 ;
}
if ( F_90 ( V_1 ) ) {
F_142 ( L_27 ,
V_20 , & V_133 ) ;
return 0 ;
}
if ( F_3 ( V_1 ) ) {
F_142 ( L_28 ,
V_20 , & V_133 ) ;
return 0 ;
}
if ( ! F_20 ( V_1 ) && F_84 ( V_1 ) ) {
F_142 ( L_29 ,
V_20 , & V_133 ) ;
return 0 ;
}
V_101 = 1 << F_14 ( V_1 ) ;
if ( ! F_83 ( V_2 ) ) {
if ( F_20 ( V_1 ) ) {
F_142 ( L_30 ,
V_20 , & V_133 ) ;
return 0 ;
}
if ( F_111 ( V_2 ) )
F_143 () ;
F_142 ( L_31 ,
V_20 , & V_133 ) ;
return 0 ;
}
F_109 ( V_1 ) ;
if ( F_111 ( V_1 ) ) {
F_142 ( L_32 ,
V_20 , & V_133 ) ;
F_112 ( V_101 ) ;
V_132 = 1 ;
if ( F_20 ( V_1 ) )
F_101 ( V_1 ) ;
}
F_113 ( V_1 ) ;
F_116 ( V_1 ) ;
if ( V_132 && ! ( V_20 == F_144 ( 0 ) && F_82 ( V_2 ) == 1 ) )
F_116 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_145 ( struct V_1 * V_2 , unsigned long V_136 , int * * V_137 )
{
int V_138 = F_27 ( V_2 ) ;
if ( F_20 ( V_2 ) )
return F_146 ( F_147 ( F_15 ( V_2 ) ) ,
V_138 ) ;
else
return F_148 ( V_138 , V_139 , 0 ) ;
}
static int F_149 ( struct V_1 * V_2 , unsigned long V_20 , int V_21 )
{
int V_24 ;
if ( V_21 & V_106 )
return 1 ;
if ( ! F_83 ( V_2 ) ) {
if ( F_20 ( V_2 ) ) {
F_18 ( L_33 , V_140 , V_20 ) ;
V_24 = 0 ;
} else if ( F_25 ( V_2 ) ) {
F_18 ( L_34 , V_140 , V_20 ) ;
V_24 = 0 ;
} else {
F_18 ( L_35 ,
V_140 , V_20 , V_2 -> V_21 ) ;
V_24 = - V_69 ;
}
} else {
V_24 = 1 ;
}
return V_24 ;
}
static int F_150 ( struct V_1 * V_1 , unsigned long V_20 , int V_21 )
{
int V_24 = F_149 ( V_1 , V_20 , V_21 ) ;
if ( V_24 == 1 && ! F_20 ( V_1 ) &&
! F_22 ( V_1 ) && ! F_151 ( V_1 ) ) {
F_116 ( V_1 ) ;
F_19 ( V_1 , 1 ) ;
V_24 = F_149 ( V_1 , V_20 , 0 ) ;
if ( V_24 == 1 && ! F_22 ( V_1 ) ) {
F_116 ( V_1 ) ;
F_18 ( L_36 ,
V_20 , V_1 -> V_21 , & V_1 -> V_21 ) ;
return - V_69 ;
}
}
return V_24 ;
}
static int F_152 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_31 ( V_1 ) ;
struct V_1 * V_78 = F_15 ( V_1 ) ;
F_87 ( V_141 ) ;
F_109 ( V_78 ) ;
if ( F_110 ( V_78 ) ) {
F_113 ( V_78 ) ;
F_116 ( V_78 ) ;
F_18 ( L_37 , V_20 ) ;
return - V_88 ;
}
F_113 ( V_78 ) ;
V_24 = F_153 ( V_78 , & V_141 ) ;
F_116 ( V_78 ) ;
if ( ! V_24 ) {
F_18 ( L_38 , V_20 ) ;
return - V_88 ;
}
V_24 = F_154 ( & V_141 , F_145 , NULL , V_142 ,
V_143 , V_144 ) ;
if ( V_24 ) {
F_18 ( L_39 ,
V_20 , V_24 , V_1 -> V_21 , & V_1 -> V_21 ) ;
if ( ! F_155 ( & V_141 ) )
F_156 ( & V_141 ) ;
if ( V_24 > 0 )
V_24 = - V_69 ;
} else {
if ( F_20 ( V_1 ) ) {
F_99 ( V_78 ) ;
F_78 ( V_78 ) ;
F_108 ( 1 << F_14 ( V_78 ) ) ;
} else {
F_100 ( V_1 ) ;
F_157 () ;
}
}
return V_24 ;
}
static int F_158 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_31 ( V_1 ) ;
F_109 ( V_1 ) ;
F_121 ( V_1 ) ;
if ( F_110 ( V_1 ) ) {
F_113 ( V_1 ) ;
F_116 ( V_1 ) ;
F_18 ( L_40 , V_20 ) ;
return - V_88 ;
}
V_24 = F_68 ( V_1 ) ;
F_113 ( V_1 ) ;
if ( V_24 == 1 ) {
F_116 ( V_1 ) ;
F_18 ( L_41 , V_20 ) ;
F_100 ( V_1 ) ;
F_157 () ;
return 0 ;
}
if ( F_22 ( V_1 ) )
V_24 = F_58 ( V_1 ) ;
else
V_24 = F_159 ( V_1 , V_145 ) ;
F_116 ( V_1 ) ;
if ( ! V_24 ) {
F_87 ( V_141 ) ;
if ( ! F_151 ( V_1 ) )
F_160 ( V_1 , V_146 +
F_161 ( V_1 ) ) ;
F_162 ( & V_1 -> V_147 , & V_141 ) ;
V_24 = F_154 ( & V_141 , F_145 , NULL , V_142 ,
V_143 , V_144 ) ;
if ( V_24 ) {
if ( ! F_155 ( & V_141 ) )
F_156 ( & V_141 ) ;
F_18 ( L_39 ,
V_20 , V_24 , V_1 -> V_21 , & V_1 -> V_21 ) ;
if ( V_24 > 0 )
V_24 = - V_69 ;
}
} else {
F_18 ( L_42 ,
V_20 , V_24 , F_82 ( V_1 ) , V_1 -> V_21 , & V_1 -> V_21 ) ;
}
return V_24 ;
}
static int F_163 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
struct V_1 * V_78 = F_15 ( V_1 ) ;
if ( ! F_20 ( V_1 ) && F_84 ( V_78 ) ) {
F_109 ( V_78 ) ;
if ( ! F_56 ( V_78 ) || F_114 ( F_115 ( V_78 ) ) ) {
F_113 ( V_78 ) ;
if ( ! F_56 ( V_78 ) )
F_18 ( L_43 , F_31 ( V_1 ) ) ;
else
F_18 ( L_44 , F_31 ( V_1 ) ) ;
F_116 ( V_78 ) ;
return - V_88 ;
}
F_113 ( V_78 ) ;
F_83 ( V_1 ) ;
F_116 ( V_78 ) ;
}
if ( F_20 ( V_1 ) )
V_24 = F_152 ( V_1 , V_21 ) ;
else
V_24 = F_158 ( V_1 , V_21 ) ;
return V_24 ;
}
static void F_164 ( struct V_1 * V_1 )
{
if ( F_20 ( V_1 ) ) {
struct V_1 * V_78 = F_15 ( V_1 ) ;
F_99 ( V_78 ) ;
if ( ! F_78 ( V_78 ) )
F_108 ( 1 << F_14 ( V_78 ) ) ;
} else {
if ( ! F_107 ( V_1 ) )
F_157 () ;
}
}
int F_133 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_31 ( V_1 ) ;
if ( F_110 ( V_1 ) ) {
F_18 ( L_40 , V_20 ) ;
if ( V_21 & V_106 )
F_116 ( V_1 ) ;
return - V_88 ;
}
F_165 () ;
V_24 = F_150 ( V_1 , V_20 , V_21 ) ;
F_166 () ;
if ( V_24 > 0 )
V_24 = F_163 ( V_1 , V_21 ) ;
else if ( V_24 == 0 )
F_164 ( V_1 ) ;
return V_24 ;
}
