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
static int F_63 ( struct V_1 * V_2 , unsigned long V_20 ,
struct V_3 * V_4 )
{
int V_24 = V_70 ;
if ( V_4 -> V_71 -> V_72 ) {
int V_73 = V_4 -> V_71 -> V_72 ( V_4 , V_2 ) ;
if ( V_73 != 0 ) {
F_18 ( L_7 ,
V_20 , V_73 ) ;
} else if ( F_64 ( V_2 ) &&
! F_65 ( V_2 , V_68 ) ) {
F_18 ( L_8 ,
V_20 ) ;
} else {
V_24 = V_74 ;
}
} else {
if ( F_66 ( V_2 ) )
V_24 = V_74 ;
else
F_18 ( L_9 ,
V_20 ) ;
}
return V_24 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned long V_20 )
{
return V_75 ;
}
static int F_68 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_12 ( L_10 , V_20 ) ;
return V_70 ;
}
static int F_69 ( struct V_1 * V_2 , unsigned long V_20 )
{
struct V_3 * V_4 ;
F_57 ( V_2 ) ;
if ( F_56 ( V_2 ) )
return V_74 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_70 ;
}
return F_63 ( V_2 , V_20 , V_4 ) ;
}
static int F_70 ( struct V_1 * V_2 , unsigned long V_20 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_71 ( V_2 ) ;
if ( V_4 ) {
F_72 ( V_4 , - V_69 ) ;
}
return F_69 ( V_2 , V_20 ) ;
}
static int F_73 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( ! F_57 ( V_2 ) )
return V_76 ;
else
return V_70 ;
}
static int F_76 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_77 ( V_2 ) ;
if ( ! F_57 ( V_2 ) )
return V_74 ;
else
return V_70 ;
}
static int F_78 ( struct V_1 * V_2 , unsigned long V_20 )
{
int V_77 = 0 ;
struct V_1 * V_78 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_20 ( V_78 ) )
return V_76 ;
V_4 = F_3 ( V_78 ) ;
if ( V_4 ) {
V_77 = F_63 ( V_78 , V_20 , V_4 ) ;
} else {
F_79 ( V_78 ) ;
if ( F_56 ( V_78 ) )
F_62 ( V_78 ) ;
F_80 ( V_2 ) ;
V_77 = V_74 ;
F_81 ( V_78 ) ;
}
return V_77 ;
}
static void F_82 ( unsigned long V_20 , enum V_79 type ,
enum V_80 V_81 )
{
F_83 ( V_20 , type , V_81 ) ;
F_12 ( L_11 ,
V_20 , V_82 [ type ] , V_83 [ V_81 ] ) ;
}
static int F_84 ( struct V_84 * V_85 , struct V_1 * V_2 ,
unsigned long V_20 )
{
int V_81 ;
int V_86 ;
V_81 = V_85 -> V_87 ( V_2 , V_20 ) ;
V_86 = F_85 ( V_2 ) - 1 ;
if ( V_85 -> V_87 == F_73 && V_81 == V_76 )
V_86 -- ;
if ( V_86 > 0 ) {
F_12 ( L_12 ,
V_20 , V_82 [ V_85 -> type ] , V_86 ) ;
V_81 = V_70 ;
}
F_82 ( V_20 , V_85 -> type , V_81 ) ;
return ( V_81 == V_74 || V_81 == V_76 ) ? 0 : - V_88 ;
}
int F_86 ( struct V_1 * V_1 )
{
struct V_1 * V_89 = F_15 ( V_1 ) ;
if ( ! F_20 ( V_89 ) && F_87 ( V_89 ) ) {
if ( ! F_56 ( V_89 ) ) {
F_12 ( L_13 ,
F_31 ( V_1 ) ) ;
return 0 ;
}
}
if ( F_88 ( V_89 ) ) {
if ( V_89 == F_15 ( V_1 ) )
return 1 ;
F_18 ( L_14 ,
F_31 ( V_1 ) ) ;
F_62 ( V_89 ) ;
}
return 0 ;
}
static bool F_89 ( struct V_1 * V_2 , unsigned long V_20 ,
int V_19 , int V_21 , struct V_1 * * V_90 )
{
enum V_91 V_92 = V_93 | V_94 ;
struct V_3 * V_4 ;
F_90 ( V_67 ) ;
bool V_95 ;
int V_96 = 1 , V_52 ;
struct V_1 * V_78 = * V_90 ;
bool V_97 = F_91 ( V_78 ) ;
if ( F_92 ( V_2 ) || F_2 ( V_2 ) )
return true ;
if ( ! ( F_22 ( V_78 ) || F_20 ( V_2 ) ) )
return true ;
if ( ! F_93 ( V_78 ) )
return true ;
if ( F_94 ( V_2 ) ) {
F_12 ( L_15 , V_20 ) ;
return false ;
}
if ( F_95 ( V_2 ) ) {
F_12 ( L_16 ,
V_20 ) ;
V_92 |= V_98 ;
}
V_4 = F_3 ( V_78 ) ;
if ( ! ( V_21 & V_99 ) && ! F_96 ( V_78 ) && V_4 &&
F_97 ( V_4 ) ) {
if ( F_98 ( V_78 ) ) {
F_99 ( V_78 ) ;
} else {
V_96 = 0 ;
V_92 |= V_98 ;
F_18 ( L_17 ,
V_20 ) ;
}
}
if ( V_96 )
F_55 ( V_78 , & V_67 , V_21 & V_34 ) ;
V_95 = F_100 ( V_78 , V_92 ) ;
if ( ! V_95 )
F_12 ( L_18 ,
V_20 , F_101 ( V_78 ) ) ;
if ( V_97 )
F_19 ( V_78 , 0 ) ;
V_52 = F_96 ( V_78 ) || ( V_21 & V_99 ) ;
F_34 ( & V_67 , V_52 , V_19 , ! V_95 , V_2 , V_20 , V_21 ) ;
return V_95 ;
}
static int F_102 ( unsigned long V_20 , struct V_1 * V_2 ,
unsigned long V_100 )
{
struct V_84 * V_85 ;
for ( V_85 = V_101 ; ; V_85 ++ )
if ( ( V_2 -> V_21 & V_85 -> V_102 ) == V_85 -> V_77 )
break;
V_100 |= ( V_2 -> V_21 & ( 1UL << V_103 ) ) ;
if ( ! V_85 -> V_102 )
for ( V_85 = V_101 ; ; V_85 ++ )
if ( ( V_100 & V_85 -> V_102 ) == V_85 -> V_77 )
break;
return F_84 ( V_85 , V_2 , V_20 ) ;
}
static int F_103 ( unsigned long V_20 , int V_19 , int V_21 )
{
struct V_1 * V_2 = F_104 ( V_20 ) ;
struct V_1 * V_89 = F_15 ( V_2 ) ;
int V_77 ;
unsigned long V_100 ;
if ( F_105 ( V_89 ) ) {
F_12 ( L_19 ,
V_20 ) ;
return 0 ;
}
F_106 () ;
if ( ! ( V_21 & V_104 ) && ! F_86 ( V_2 ) ) {
F_81 ( V_89 ) ;
if ( F_107 ( V_89 ) ) {
if ( ( F_10 ( V_2 ) && F_108 ( V_2 ) )
|| ( V_2 != V_89 && F_105 ( V_89 ) ) ) {
F_109 () ;
F_79 ( V_89 ) ;
return 0 ;
}
}
F_79 ( V_89 ) ;
F_80 ( V_2 ) ;
F_82 ( V_20 , V_105 , V_76 ) ;
return 0 ;
}
F_81 ( V_89 ) ;
V_100 = V_89 -> V_21 ;
if ( ! F_107 ( V_89 ) ) {
F_12 ( L_20 , V_20 ) ;
F_109 () ;
F_79 ( V_89 ) ;
F_110 ( V_89 ) ;
return 0 ;
}
if ( ! F_89 ( V_2 , V_20 , V_19 , V_21 , & V_89 ) ) {
F_82 ( V_20 , V_106 , V_75 ) ;
V_77 = - V_88 ;
goto V_107;
}
V_77 = F_102 ( V_20 , V_2 , V_100 ) ;
V_107:
F_79 ( V_89 ) ;
return V_77 ;
}
int F_111 ( unsigned long V_20 , int V_19 , int V_21 )
{
struct V_1 * V_2 ;
struct V_1 * V_78 ;
struct V_1 * V_108 ;
int V_77 ;
unsigned long V_100 ;
if ( ! V_109 )
F_112 ( L_21 , V_19 , V_20 ) ;
if ( ! F_113 ( V_20 ) ) {
F_12 ( L_22 ,
V_20 ) ;
return - V_110 ;
}
V_2 = F_104 ( V_20 ) ;
if ( F_20 ( V_2 ) )
return F_103 ( V_20 , V_19 , V_21 ) ;
if ( F_105 ( V_2 ) ) {
F_12 ( L_19 ,
V_20 ) ;
return 0 ;
}
F_114 ( V_20 ) ;
V_108 = V_78 = F_15 ( V_2 ) ;
F_106 () ;
if ( ! ( V_21 & V_104 ) && ! F_86 ( V_2 ) ) {
if ( F_25 ( V_2 ) ) {
F_82 ( V_20 , V_111 , V_76 ) ;
return 0 ;
} else {
F_82 ( V_20 , V_112 , V_75 ) ;
return - V_88 ;
}
}
if ( F_87 ( V_78 ) ) {
F_81 ( V_2 ) ;
if ( ! F_56 ( V_2 ) || F_115 ( F_116 ( V_2 ) ) ) {
F_79 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
F_12 ( L_13 ,
V_20 ) ;
else
F_12 ( L_23 ,
V_20 ) ;
if ( F_108 ( V_2 ) )
F_109 () ;
F_110 ( V_2 ) ;
return - V_88 ;
}
F_79 ( V_2 ) ;
F_117 ( ! F_85 ( V_2 ) , V_2 ) ;
V_78 = F_15 ( V_2 ) ;
}
F_19 ( V_2 , 0 ) ;
if ( ! F_22 ( V_2 ) && F_25 ( V_2 ) ) {
if ( V_21 & V_104 )
F_82 ( V_20 , V_111 , V_76 ) ;
else
F_82 ( V_20 , V_113 , V_76 ) ;
return 0 ;
}
F_81 ( V_2 ) ;
if ( F_118 ( V_2 ) && F_15 ( V_2 ) != V_108 ) {
F_82 ( V_20 , V_114 , V_75 ) ;
V_77 = - V_88 ;
goto V_107;
}
if ( F_20 ( V_2 ) )
V_100 = V_78 -> V_21 ;
else
V_100 = V_2 -> V_21 ;
if ( ! F_107 ( V_2 ) ) {
F_12 ( L_20 , V_20 ) ;
F_109 () ;
F_79 ( V_2 ) ;
F_110 ( V_2 ) ;
return 0 ;
}
if ( F_10 ( V_2 ) ) {
if ( F_108 ( V_2 ) )
F_109 () ;
F_79 ( V_2 ) ;
F_110 ( V_2 ) ;
return 0 ;
}
if ( ! F_119 ( V_2 ) && ! F_22 ( V_2 ) )
goto F_102;
F_120 ( V_2 ) ;
if ( ! F_89 ( V_2 , V_20 , V_19 , V_21 , & V_78 ) ) {
F_82 ( V_20 , V_106 , V_75 ) ;
V_77 = - V_88 ;
goto V_107;
}
if ( F_22 ( V_2 ) && ! F_95 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_82 ( V_20 , V_115 , V_75 ) ;
V_77 = - V_88 ;
goto V_107;
}
F_102:
V_77 = F_102 ( V_20 , V_2 , V_100 ) ;
V_107:
F_79 ( V_2 ) ;
return V_77 ;
}
void F_121 ( unsigned long V_20 , int V_19 , int V_21 )
{
struct V_116 * V_117 ;
unsigned long V_118 ;
struct V_119 V_120 = {
. V_20 = V_20 ,
. V_19 = V_19 ,
. V_21 = V_21 ,
} ;
V_117 = & F_122 ( V_116 ) ;
F_123 ( & V_117 -> V_121 , V_118 ) ;
if ( F_124 ( & V_117 -> V_122 , V_120 ) )
F_125 ( F_126 () , & V_117 -> V_123 ) ;
else
F_12 ( L_24 ,
V_20 ) ;
F_127 ( & V_117 -> V_121 , V_118 ) ;
F_128 ( V_116 ) ;
}
static void F_129 ( struct V_124 * V_123 )
{
struct V_116 * V_117 ;
struct V_119 V_120 = { 0 , } ;
unsigned long V_118 ;
int V_125 ;
V_117 = F_130 ( & V_116 ) ;
for (; ; ) {
F_123 ( & V_117 -> V_121 , V_118 ) ;
V_125 = F_131 ( & V_117 -> V_122 , & V_120 ) ;
F_127 ( & V_117 -> V_121 , V_118 ) ;
if ( ! V_125 )
break;
if ( V_120 . V_21 & V_126 )
F_132 ( F_104 ( V_120 . V_20 ) , V_120 . V_21 ) ;
else
F_111 ( V_120 . V_20 , V_120 . V_19 , V_120 . V_21 ) ;
}
}
static int T_3 F_133 ( void )
{
struct V_116 * V_117 ;
int V_127 ;
F_134 (cpu) {
V_117 = & F_135 ( V_116 , V_127 ) ;
F_136 ( & V_117 -> V_121 ) ;
F_137 ( V_117 -> V_122 ) ;
F_138 ( & V_117 -> V_123 , F_129 ) ;
}
return 0 ;
}
int F_139 ( unsigned long V_20 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_128 = 0 ;
static F_140 ( V_129 , V_130 ,
V_131 ) ;
if ( ! F_113 ( V_20 ) )
return - V_110 ;
V_2 = F_104 ( V_20 ) ;
V_1 = F_15 ( V_2 ) ;
if ( ! F_107 ( V_2 ) ) {
F_141 ( L_25 ,
V_20 , & V_129 ) ;
return 0 ;
}
if ( F_85 ( V_1 ) > 1 ) {
F_141 ( L_26 ,
V_20 , & V_129 ) ;
return 0 ;
}
if ( F_93 ( V_1 ) ) {
F_141 ( L_27 ,
V_20 , & V_129 ) ;
return 0 ;
}
if ( F_3 ( V_1 ) ) {
F_141 ( L_28 ,
V_20 , & V_129 ) ;
return 0 ;
}
if ( ! F_20 ( V_1 ) && F_87 ( V_1 ) ) {
F_141 ( L_29 ,
V_20 , & V_129 ) ;
return 0 ;
}
if ( ! F_86 ( V_2 ) ) {
if ( F_108 ( V_2 ) )
F_109 () ;
F_141 ( L_30 ,
V_20 , & V_129 ) ;
return 0 ;
}
F_81 ( V_1 ) ;
if ( F_108 ( V_1 ) ) {
F_141 ( L_31 ,
V_20 , & V_129 ) ;
F_109 () ;
V_128 = 1 ;
}
F_79 ( V_1 ) ;
F_110 ( V_1 ) ;
if ( V_128 && ! ( V_20 == F_142 ( 0 ) && F_85 ( V_2 ) == 1 ) )
F_110 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_143 ( struct V_1 * V_2 , unsigned long V_132 , int * * V_133 )
{
int V_134 = F_27 ( V_2 ) ;
return F_144 ( V_2 , V_134 , & V_135 [ V_136 ] ) ;
}
static int F_145 ( struct V_1 * V_2 , unsigned long V_20 , int V_21 )
{
int V_24 ;
if ( V_21 & V_104 )
return 1 ;
if ( ! F_86 ( V_2 ) ) {
if ( F_20 ( V_2 ) ) {
F_18 ( L_32 , V_137 , V_20 ) ;
V_24 = 0 ;
} else if ( F_25 ( V_2 ) ) {
F_18 ( L_33 , V_137 , V_20 ) ;
V_24 = 0 ;
} else {
F_18 ( L_34 ,
V_137 , V_20 , V_2 -> V_21 ) ;
V_24 = - V_69 ;
}
} else {
V_24 = 1 ;
}
return V_24 ;
}
static int F_146 ( struct V_1 * V_1 , unsigned long V_20 , int V_21 )
{
int V_24 = F_145 ( V_1 , V_20 , V_21 ) ;
if ( V_24 == 1 && ! F_20 ( V_1 ) &&
! F_22 ( V_1 ) && ! F_147 ( V_1 ) ) {
F_110 ( V_1 ) ;
F_19 ( V_1 , 1 ) ;
V_24 = F_145 ( V_1 , V_20 , 0 ) ;
if ( V_24 == 1 && ! F_22 ( V_1 ) ) {
F_110 ( V_1 ) ;
F_18 ( L_35 ,
V_20 , V_1 -> V_21 , & V_1 -> V_21 ) ;
return - V_69 ;
}
}
return V_24 ;
}
static int F_148 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_31 ( V_1 ) ;
struct V_1 * V_78 = F_15 ( V_1 ) ;
F_90 ( V_138 ) ;
F_81 ( V_78 ) ;
if ( F_107 ( V_78 ) ) {
F_79 ( V_78 ) ;
F_110 ( V_78 ) ;
F_18 ( L_36 , V_20 ) ;
return - V_88 ;
}
F_79 ( V_78 ) ;
V_24 = F_149 ( V_78 , & V_138 ) ;
F_110 ( V_78 ) ;
if ( ! V_24 ) {
F_18 ( L_37 , V_20 ) ;
return - V_88 ;
}
V_24 = F_150 ( & V_138 , F_143 , NULL , V_139 ,
V_140 , V_141 ) ;
if ( V_24 ) {
F_18 ( L_38 ,
V_20 , V_24 , V_1 -> V_21 , & V_1 -> V_21 ) ;
if ( ! F_151 ( & V_138 ) )
F_152 ( & V_138 ) ;
if ( V_24 > 0 )
V_24 = - V_69 ;
} else {
if ( F_20 ( V_1 ) )
F_80 ( V_1 ) ;
}
return V_24 ;
}
static int F_153 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_31 ( V_1 ) ;
F_81 ( V_1 ) ;
F_120 ( V_1 ) ;
if ( F_107 ( V_1 ) ) {
F_79 ( V_1 ) ;
F_110 ( V_1 ) ;
F_18 ( L_39 , V_20 ) ;
return - V_88 ;
}
V_24 = F_66 ( V_1 ) ;
F_79 ( V_1 ) ;
if ( V_24 == 1 ) {
F_110 ( V_1 ) ;
F_18 ( L_40 , V_20 ) ;
F_154 ( V_1 ) ;
F_106 () ;
return 0 ;
}
if ( F_22 ( V_1 ) )
V_24 = F_58 ( V_1 ) ;
else
V_24 = F_155 ( V_1 , V_142 ) ;
F_110 ( V_1 ) ;
if ( ! V_24 ) {
F_90 ( V_138 ) ;
if ( ! F_147 ( V_1 ) )
F_156 ( V_1 , V_143 +
F_157 ( V_1 ) ) ;
F_158 ( & V_1 -> V_144 , & V_138 ) ;
V_24 = F_150 ( & V_138 , F_143 , NULL , V_139 ,
V_140 , V_141 ) ;
if ( V_24 ) {
if ( ! F_151 ( & V_138 ) )
F_152 ( & V_138 ) ;
F_18 ( L_38 ,
V_20 , V_24 , V_1 -> V_21 , & V_1 -> V_21 ) ;
if ( V_24 > 0 )
V_24 = - V_69 ;
}
} else {
F_18 ( L_41 ,
V_20 , V_24 , F_85 ( V_1 ) , V_1 -> V_21 , & V_1 -> V_21 ) ;
}
return V_24 ;
}
static int F_159 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
struct V_1 * V_78 = F_15 ( V_1 ) ;
if ( ! F_20 ( V_1 ) && F_87 ( V_78 ) ) {
F_81 ( V_78 ) ;
if ( ! F_56 ( V_78 ) || F_115 ( F_116 ( V_78 ) ) ) {
F_79 ( V_78 ) ;
if ( ! F_56 ( V_78 ) )
F_18 ( L_42 , F_31 ( V_1 ) ) ;
else
F_18 ( L_43 , F_31 ( V_1 ) ) ;
F_110 ( V_78 ) ;
return - V_88 ;
}
F_79 ( V_78 ) ;
F_86 ( V_1 ) ;
F_110 ( V_78 ) ;
}
if ( F_20 ( V_1 ) )
V_24 = F_148 ( V_1 , V_21 ) ;
else
V_24 = F_153 ( V_1 , V_21 ) ;
return V_24 ;
}
static void F_160 ( struct V_1 * V_1 )
{
struct V_1 * V_89 = F_15 ( V_1 ) ;
if ( ! F_105 ( V_89 ) ) {
F_106 () ;
if ( F_20 ( V_89 ) )
F_80 ( V_1 ) ;
}
}
int F_132 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_31 ( V_1 ) ;
if ( F_107 ( V_1 ) ) {
F_18 ( L_39 , V_20 ) ;
if ( V_21 & V_104 )
F_110 ( V_1 ) ;
return - V_88 ;
}
F_161 () ;
V_24 = F_146 ( V_1 , V_20 , V_21 ) ;
F_162 () ;
if ( V_24 > 0 )
V_24 = F_159 ( V_1 , V_21 ) ;
else if ( V_24 == 0 )
F_160 ( V_1 ) ;
return V_24 ;
}
