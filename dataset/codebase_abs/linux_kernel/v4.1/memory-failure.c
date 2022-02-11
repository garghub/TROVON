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
struct V_14 * V_15 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
if ( ! V_19 )
return 0 ;
V_15 = F_9 ( V_2 ) ;
if ( ! V_15 )
return - V_8 ;
V_17 = F_10 ( V_15 ) ;
V_18 = F_11 ( V_17 -> V_20 ) ;
F_12 ( V_17 ) ;
if ( V_18 != V_19 )
return - V_8 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ) { return 0 ; }
int F_13 ( struct V_1 * V_2 )
{
if ( ! V_21 )
return 0 ;
if ( F_1 ( V_2 ) )
return - V_8 ;
if ( F_6 ( V_2 ) )
return - V_8 ;
if ( F_8 ( V_2 ) )
return - V_8 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_22 * V_23 , unsigned long V_24 , int V_25 ,
unsigned long V_26 , struct V_1 * V_1 , int V_27 )
{
struct V_28 V_29 ;
int V_30 ;
F_15 ( V_31
L_1 ,
V_26 , V_23 -> V_32 , V_23 -> V_33 ) ;
V_29 . V_34 = V_35 ;
V_29 . V_36 = 0 ;
V_29 . V_37 = ( void * ) V_24 ;
#ifdef F_16
V_29 . V_38 = V_25 ;
#endif
V_29 . V_39 = F_17 ( F_18 ( V_1 ) ) + V_40 ;
if ( ( V_27 & V_41 ) && V_23 -> V_42 == V_43 -> V_42 ) {
V_29 . V_44 = V_45 ;
V_30 = F_19 ( V_35 , & V_29 , V_43 ) ;
} else {
V_29 . V_44 = V_46 ;
V_30 = F_20 ( V_35 , & V_29 , V_23 ) ;
}
if ( V_30 < 0 )
F_15 ( V_47 L_2 ,
V_23 -> V_32 , V_23 -> V_33 , V_30 ) ;
return V_30 ;
}
void F_21 ( struct V_1 * V_2 , int V_48 )
{
if ( ! F_2 ( V_2 ) ) {
F_22 () ;
if ( F_23 ( V_2 ) )
return;
F_24 ( F_25 ( V_2 ) ) ;
if ( F_23 ( V_2 ) || F_26 ( V_2 ) )
return;
}
if ( V_48 )
F_27 ( F_28 ( V_2 ) ) ;
}
static void F_29 ( struct V_22 * V_49 , struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_53 * * V_54 )
{
struct V_53 * V_55 ;
if ( * V_54 ) {
V_55 = * V_54 ;
* V_54 = NULL ;
} else {
V_55 = F_30 ( sizeof( struct V_53 ) , V_56 ) ;
if ( ! V_55 ) {
F_15 ( V_31
L_3 ) ;
return;
}
}
V_55 -> V_24 = F_31 ( V_2 , V_51 ) ;
V_55 -> V_57 = 1 ;
if ( V_55 -> V_24 == - V_58 ) {
F_32 ( L_4 ,
F_33 ( V_2 ) , V_49 -> V_32 ) ;
V_55 -> V_57 = 0 ;
}
F_34 ( V_49 ) ;
V_55 -> V_49 = V_49 ;
F_35 ( & V_55 -> V_59 , V_53 ) ;
}
static void F_36 ( struct V_52 * V_53 , int V_60 , int V_25 ,
int V_61 , struct V_1 * V_1 , unsigned long V_26 ,
int V_27 )
{
struct V_53 * V_55 , * V_62 ;
F_37 (tk, next, to_kill, nd) {
if ( V_60 ) {
if ( V_61 || V_55 -> V_57 == 0 ) {
F_15 ( V_31
L_5 ,
V_26 , V_55 -> V_49 -> V_32 , V_55 -> V_49 -> V_33 ) ;
F_38 ( V_63 , V_55 -> V_49 ) ;
}
else if ( F_14 ( V_55 -> V_49 , V_55 -> V_24 , V_25 ,
V_26 , V_1 , V_27 ) < 0 )
F_15 ( V_31
L_6 ,
V_26 , V_55 -> V_49 -> V_32 , V_55 -> V_49 -> V_33 ) ;
}
F_39 ( V_55 -> V_49 ) ;
F_40 ( V_55 ) ;
}
}
static struct V_22 * F_41 ( struct V_22 * V_49 )
{
struct V_22 * V_23 ;
F_42 (tsk, t)
if ( ( V_23 -> V_27 & V_64 ) && ( V_23 -> V_27 & V_65 ) )
return V_23 ;
return NULL ;
}
static struct V_22 * F_43 ( struct V_22 * V_49 ,
int V_66 )
{
struct V_22 * V_23 ;
if ( ! V_49 -> V_42 )
return NULL ;
if ( V_66 )
return V_49 ;
V_23 = F_41 ( V_49 ) ;
if ( V_23 )
return V_23 ;
if ( V_67 )
return V_49 ;
return NULL ;
}
static void F_44 ( struct V_1 * V_1 , struct V_52 * V_53 ,
struct V_53 * * V_54 , int V_66 )
{
struct V_50 * V_51 ;
struct V_22 * V_49 ;
struct V_68 * V_69 ;
T_2 V_70 ;
V_69 = F_45 ( V_1 ) ;
if ( V_69 == NULL )
return;
V_70 = F_46 ( V_1 ) ;
F_47 ( & V_71 ) ;
F_48 (tsk) {
struct V_72 * V_73 ;
struct V_22 * V_23 = F_43 ( V_49 , V_66 ) ;
if ( ! V_23 )
continue;
F_49 (vmac, &av->rb_root,
pgoff, pgoff) {
V_51 = V_73 -> V_51 ;
if ( ! F_50 ( V_1 , V_51 ) )
continue;
if ( V_51 -> V_74 == V_23 -> V_42 )
F_29 ( V_23 , V_1 , V_51 , V_53 , V_54 ) ;
}
}
F_51 ( & V_71 ) ;
F_52 ( V_69 ) ;
}
static void F_53 ( struct V_1 * V_1 , struct V_52 * V_53 ,
struct V_53 * * V_54 , int V_66 )
{
struct V_50 * V_51 ;
struct V_22 * V_49 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_54 ( V_4 ) ;
F_47 ( & V_71 ) ;
F_48 (tsk) {
T_2 V_70 = F_46 ( V_1 ) ;
struct V_22 * V_23 = F_43 ( V_49 , V_66 ) ;
if ( ! V_23 )
continue;
F_55 (vma, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_51 -> V_74 == V_23 -> V_42 )
F_29 ( V_23 , V_1 , V_51 , V_53 , V_54 ) ;
}
}
F_51 ( & V_71 ) ;
F_56 ( V_4 ) ;
}
static void F_57 ( struct V_1 * V_1 , struct V_52 * V_75 ,
int V_66 )
{
struct V_53 * V_55 ;
if ( ! V_1 -> V_4 )
return;
V_55 = F_30 ( sizeof( struct V_53 ) , V_76 ) ;
if ( ! V_55 )
return;
if ( F_58 ( V_1 ) )
F_44 ( V_1 , V_75 , & V_55 , V_66 ) ;
else
F_53 ( V_1 , V_75 , & V_55 , V_66 ) ;
F_40 ( V_55 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( ! F_60 ( V_2 ) ) {
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
return - V_77 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned long V_26 )
{
return V_78 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_15 ( V_31 L_7 , V_26 ) ;
return V_79 ;
}
static int F_66 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_80 ;
int V_30 = V_79 ;
struct V_3 * V_4 ;
F_59 ( V_2 ) ;
if ( F_58 ( V_2 ) )
return V_81 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_79 ;
}
if ( V_4 -> V_82 -> V_83 ) {
V_80 = V_4 -> V_82 -> V_83 ( V_4 , V_2 ) ;
if ( V_80 != 0 ) {
F_15 ( V_47 L_8 ,
V_26 , V_80 ) ;
} else if ( F_67 ( V_2 ) &&
! F_68 ( V_2 , V_76 ) ) {
F_32 ( L_9 , V_26 ) ;
} else {
V_30 = V_81 ;
}
} else {
if ( F_69 ( V_2 ) )
V_30 = V_81 ;
else
F_15 ( V_47 L_10 ,
V_26 ) ;
}
return V_30 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned long V_26 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_71 ( V_2 ) ;
if ( V_4 ) {
F_72 ( V_4 , V_77 ) ;
}
return F_66 ( V_2 , V_26 ) ;
}
static int F_73 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( ! F_59 ( V_2 ) )
return V_84 ;
else
return V_79 ;
}
static int F_76 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_77 ( V_2 ) ;
if ( ! F_59 ( V_2 ) )
return V_81 ;
else
return V_79 ;
}
static int F_78 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_85 = 0 ;
struct V_1 * V_86 = F_18 ( V_2 ) ;
if ( ! ( F_3 ( V_86 ) || F_58 ( V_86 ) ) ) {
V_85 = F_79 ( V_86 ) ;
if ( ! V_85 )
return V_81 ;
}
return V_84 ;
}
static void F_80 ( unsigned long V_26 , enum V_87 type , int V_88 )
{
F_81 ( L_11 ,
V_26 , V_89 [ type ] , V_90 [ V_88 ] ) ;
}
static int F_82 ( struct V_91 * V_92 , struct V_1 * V_2 ,
unsigned long V_26 )
{
int V_88 ;
int V_93 ;
V_88 = V_92 -> V_94 ( V_2 , V_26 ) ;
V_93 = F_83 ( V_2 ) - 1 ;
if ( V_92 -> V_94 == F_73 && V_88 == V_84 )
V_93 -- ;
if ( V_93 != 0 ) {
F_15 ( V_31
L_12 ,
V_26 , V_89 [ V_92 -> type ] , V_93 ) ;
V_88 = V_79 ;
}
F_80 ( V_26 , V_92 -> type , V_88 ) ;
return ( V_88 == V_81 || V_88 == V_84 ) ? 0 : - V_95 ;
}
static int F_84 ( struct V_1 * V_2 , unsigned long V_26 ,
int V_25 , int V_27 , struct V_1 * * V_96 )
{
enum V_97 V_98 = V_99 | V_100 | V_101 ;
struct V_3 * V_4 ;
F_85 ( V_75 ) ;
int V_30 ;
int V_102 = 1 , V_60 ;
struct V_1 * V_86 = * V_96 ;
struct V_1 * V_103 ;
if ( F_86 ( V_2 ) || F_2 ( V_2 ) )
return V_104 ;
if ( ! ( F_23 ( V_86 ) || F_87 ( V_2 ) ) )
return V_104 ;
if ( ! F_88 ( V_86 ) )
return V_104 ;
if ( F_89 ( V_2 ) ) {
F_81 ( L_13 , V_26 ) ;
return V_105 ;
}
if ( F_90 ( V_2 ) ) {
F_15 ( V_31
L_14 , V_26 ) ;
V_98 |= V_106 ;
}
V_4 = F_3 ( V_86 ) ;
if ( ! ( V_27 & V_107 ) && ! F_91 ( V_86 ) && V_4 &&
F_92 ( V_4 ) ) {
if ( F_93 ( V_86 ) ) {
F_94 ( V_86 ) ;
} else {
V_102 = 0 ;
V_98 |= V_106 ;
F_15 ( V_47
L_15 ,
V_26 ) ;
}
}
V_103 = V_86 ;
if ( F_95 ( V_86 ) ) {
if ( ! F_87 ( V_86 ) && F_58 ( V_86 ) ) {
if ( F_96 ( F_97 ( V_86 ) ) ) {
F_15 ( V_47
L_16 , V_26 ) ;
F_98 ( ! F_99 ( V_2 ) ) ;
return V_105 ;
}
if ( V_86 != V_2 ) {
if ( ! ( V_27 & V_108 ) ) {
F_100 ( V_86 ) ;
F_101 ( V_2 ) ;
}
F_102 ( V_2 ) ;
F_103 ( V_86 ) ;
* V_96 = V_2 ;
}
V_103 = V_2 ;
}
}
if ( V_102 )
F_57 ( V_103 , & V_75 , V_27 & V_41 ) ;
V_30 = F_104 ( V_103 , V_98 ) ;
if ( V_30 != V_104 )
F_15 ( V_31 L_17 ,
V_26 , F_105 ( V_103 ) ) ;
V_60 = F_91 ( V_103 ) || ( V_27 & V_107 ) ;
F_36 ( & V_75 , V_60 , V_25 ,
V_30 != V_104 , V_2 , V_26 , V_27 ) ;
return V_30 ;
}
static void F_106 ( struct V_1 * V_86 )
{
int V_109 ;
int V_110 = 1 << F_17 ( V_86 ) ;
for ( V_109 = 0 ; V_109 < V_110 ; V_109 ++ )
F_107 ( V_86 + V_109 ) ;
}
static void F_108 ( struct V_1 * V_86 )
{
int V_109 ;
int V_110 = 1 << F_17 ( V_86 ) ;
for ( V_109 = 0 ; V_109 < V_110 ; V_109 ++ )
F_109 ( V_86 + V_109 ) ;
}
int F_110 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_91 * V_92 ;
struct V_1 * V_2 ;
struct V_1 * V_86 ;
int V_85 ;
unsigned int V_110 ;
unsigned long V_111 ;
if ( ! V_112 )
F_111 ( L_18 , V_25 , V_26 ) ;
if ( ! F_112 ( V_26 ) ) {
F_15 ( V_31
L_19 ,
V_26 ) ;
return - V_113 ;
}
V_2 = F_113 ( V_26 ) ;
V_86 = F_18 ( V_2 ) ;
if ( F_114 ( V_2 ) ) {
F_15 ( V_31 L_20 , V_26 ) ;
return 0 ;
}
if ( F_87 ( V_2 ) )
V_110 = 1 << F_17 ( V_86 ) ;
else
V_110 = 1 ;
F_115 ( V_110 , & V_114 ) ;
if ( ! ( V_27 & V_108 ) &&
! F_116 ( V_86 ) ) {
if ( F_26 ( V_2 ) ) {
F_80 ( V_26 , V_115 , V_84 ) ;
return 0 ;
} else if ( F_87 ( V_86 ) ) {
F_102 ( V_86 ) ;
if ( F_99 ( V_86 ) ) {
if ( ( F_13 ( V_2 ) && F_117 ( V_2 ) )
|| ( V_2 != V_86 && F_114 ( V_86 ) ) ) {
F_118 ( V_110 , & V_114 ) ;
F_103 ( V_86 ) ;
return 0 ;
}
}
F_106 ( V_86 ) ;
V_85 = F_79 ( V_86 ) ;
F_80 ( V_26 , V_116 ,
V_85 ? V_78 : V_84 ) ;
F_103 ( V_86 ) ;
return V_85 ;
} else {
F_80 ( V_26 , V_117 , V_78 ) ;
return - V_95 ;
}
}
if ( ! F_87 ( V_2 ) ) {
if ( ! F_23 ( V_86 ) )
F_21 ( V_86 , 0 ) ;
if ( ! F_23 ( V_86 ) ) {
if ( F_26 ( V_2 ) ) {
if ( V_27 & V_108 )
F_80 ( V_26 , V_115 , V_84 ) ;
else
F_80 ( V_26 , V_118 ,
V_84 ) ;
return 0 ;
}
}
}
F_102 ( V_86 ) ;
if ( F_18 ( V_2 ) != V_86 ) {
F_80 ( V_26 , V_119 , V_78 ) ;
V_85 = - V_95 ;
goto V_120;
}
V_111 = V_2 -> V_27 ;
if ( ! F_99 ( V_2 ) ) {
F_15 ( V_31 L_21 , V_26 ) ;
F_118 ( V_110 , & V_114 ) ;
F_100 ( V_86 ) ;
V_85 = 0 ;
goto V_120;
}
if ( F_13 ( V_2 ) ) {
if ( F_117 ( V_2 ) )
F_118 ( V_110 , & V_114 ) ;
F_103 ( V_86 ) ;
F_100 ( V_86 ) ;
return 0 ;
}
if ( ! F_87 ( V_2 ) && ! F_119 ( V_2 ) && ! F_23 ( V_2 ) )
goto V_121;
if ( F_87 ( V_2 ) && F_120 ( V_2 ) && F_114 ( V_86 ) ) {
F_80 ( V_26 , V_122 , V_78 ) ;
F_103 ( V_86 ) ;
F_100 ( V_86 ) ;
return 0 ;
}
if ( F_87 ( V_2 ) )
F_106 ( V_86 ) ;
F_121 ( V_2 ) ;
if ( F_84 ( V_2 , V_26 , V_25 , V_27 , & V_86 )
!= V_104 ) {
F_80 ( V_26 , V_123 , V_78 ) ;
V_85 = - V_95 ;
goto V_120;
}
if ( F_23 ( V_2 ) && ! F_90 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_80 ( V_26 , V_124 , V_78 ) ;
V_85 = - V_95 ;
goto V_120;
}
V_121:
V_85 = - V_95 ;
for ( V_92 = V_125 ; ; V_92 ++ )
if ( ( V_2 -> V_27 & V_92 -> V_126 ) == V_92 -> V_85 )
break;
V_111 |= ( V_2 -> V_27 & ( 1UL << V_127 ) ) ;
if ( ! V_92 -> V_126 )
for ( V_92 = V_125 ; ; V_92 ++ )
if ( ( V_111 & V_92 -> V_126 ) == V_92 -> V_85 )
break;
V_85 = F_82 ( V_92 , V_2 , V_26 ) ;
V_120:
F_103 ( V_86 ) ;
return V_85 ;
}
void F_122 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_128 * V_129 ;
unsigned long V_130 ;
struct V_131 V_132 = {
. V_26 = V_26 ,
. V_25 = V_25 ,
. V_27 = V_27 ,
} ;
V_129 = & F_123 ( V_128 ) ;
F_124 ( & V_129 -> V_133 , V_130 ) ;
if ( F_125 ( & V_129 -> V_134 , V_132 ) )
F_126 ( F_127 () , & V_129 -> V_135 ) ;
else
F_81 ( L_22 ,
V_26 ) ;
F_128 ( & V_129 -> V_133 , V_130 ) ;
F_129 ( V_128 ) ;
}
static void F_130 ( struct V_136 * V_135 )
{
struct V_128 * V_129 ;
struct V_131 V_132 = { 0 , } ;
unsigned long V_130 ;
int V_137 ;
V_129 = F_131 ( & V_128 ) ;
for (; ; ) {
F_124 ( & V_129 -> V_133 , V_130 ) ;
V_137 = F_132 ( & V_129 -> V_134 , & V_132 ) ;
F_128 ( & V_129 -> V_133 , V_130 ) ;
if ( ! V_137 )
break;
if ( V_132 . V_27 & V_138 )
F_133 ( F_113 ( V_132 . V_26 ) , V_132 . V_27 ) ;
else
F_110 ( V_132 . V_26 , V_132 . V_25 , V_132 . V_27 ) ;
}
}
static int T_3 F_134 ( void )
{
struct V_128 * V_129 ;
int V_139 ;
F_135 (cpu) {
V_129 = & F_136 ( V_128 , V_139 ) ;
F_137 ( & V_129 -> V_133 ) ;
F_138 ( V_129 -> V_134 ) ;
F_139 ( & V_129 -> V_135 , F_130 ) ;
}
return 0 ;
}
int F_140 ( unsigned long V_26 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_140 = 0 ;
unsigned int V_110 ;
if ( ! F_112 ( V_26 ) )
return - V_113 ;
V_2 = F_113 ( V_26 ) ;
V_1 = F_18 ( V_2 ) ;
if ( ! F_99 ( V_2 ) ) {
F_32 ( L_23 , V_26 ) ;
return 0 ;
}
if ( ! F_87 ( V_1 ) && F_95 ( V_1 ) ) {
F_32 ( L_24 , V_26 ) ;
return 0 ;
}
V_110 = 1 << F_17 ( V_1 ) ;
if ( ! F_116 ( V_1 ) ) {
if ( F_87 ( V_1 ) ) {
F_32 ( L_25 , V_26 ) ;
return 0 ;
}
if ( F_117 ( V_2 ) )
F_141 ( & V_114 ) ;
F_32 ( L_26 , V_26 ) ;
return 0 ;
}
F_102 ( V_1 ) ;
if ( F_117 ( V_1 ) ) {
F_32 ( L_27 , V_26 ) ;
F_118 ( V_110 , & V_114 ) ;
V_140 = 1 ;
if ( F_87 ( V_1 ) )
F_108 ( V_1 ) ;
}
F_103 ( V_1 ) ;
F_100 ( V_1 ) ;
if ( V_140 && ! ( V_26 == F_142 ( 0 ) && F_83 ( V_2 ) == 1 ) )
F_100 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_143 ( struct V_1 * V_2 , unsigned long V_141 , int * * V_142 )
{
int V_143 = F_28 ( V_2 ) ;
if ( F_87 ( V_2 ) )
return F_144 ( F_145 ( F_18 ( V_2 ) ) ,
V_143 ) ;
else
return F_146 ( V_143 , V_144 , 0 ) ;
}
static int F_147 ( struct V_1 * V_2 , unsigned long V_26 , int V_27 )
{
int V_30 ;
if ( V_27 & V_108 )
return 1 ;
if ( ! F_116 ( F_18 ( V_2 ) ) ) {
if ( F_87 ( V_2 ) ) {
F_32 ( L_28 , V_145 , V_26 ) ;
V_30 = 0 ;
} else if ( F_26 ( V_2 ) ) {
F_32 ( L_29 , V_145 , V_26 ) ;
V_30 = 0 ;
} else {
F_32 ( L_30 ,
V_145 , V_26 , V_2 -> V_27 ) ;
V_30 = - V_77 ;
}
} else {
V_30 = 1 ;
}
return V_30 ;
}
static int F_148 ( struct V_1 * V_1 , unsigned long V_26 , int V_27 )
{
int V_30 = F_147 ( V_1 , V_26 , V_27 ) ;
if ( V_30 == 1 && ! F_87 ( V_1 ) && ! F_23 ( V_1 ) ) {
F_100 ( V_1 ) ;
F_21 ( V_1 , 1 ) ;
V_30 = F_147 ( V_1 , V_26 , 0 ) ;
if ( ! F_23 ( V_1 ) ) {
F_32 ( L_31 ,
V_26 , V_1 -> V_27 ) ;
return - V_77 ;
}
}
return V_30 ;
}
static int F_149 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_33 ( V_1 ) ;
struct V_1 * V_86 = F_18 ( V_1 ) ;
F_85 ( V_146 ) ;
F_102 ( V_86 ) ;
if ( F_99 ( V_86 ) ) {
F_103 ( V_86 ) ;
F_100 ( V_86 ) ;
F_32 ( L_32 , V_26 ) ;
return - V_95 ;
}
F_103 ( V_86 ) ;
V_30 = F_150 ( V_86 , & V_146 ) ;
if ( V_30 ) {
F_100 ( V_86 ) ;
} else {
F_32 ( L_33 , V_26 ) ;
return - V_95 ;
}
V_30 = F_151 ( & V_146 , F_143 , NULL , V_147 ,
V_148 , V_149 ) ;
if ( V_30 ) {
F_32 ( L_34 ,
V_26 , V_30 , V_1 -> V_27 ) ;
F_152 ( V_86 ) ;
if ( V_30 > 0 )
V_30 = - V_77 ;
} else {
if ( F_87 ( V_1 ) ) {
F_106 ( V_86 ) ;
F_79 ( V_86 ) ;
F_115 ( 1 << F_17 ( V_86 ) ,
& V_114 ) ;
} else {
F_107 ( V_1 ) ;
F_153 ( & V_114 ) ;
}
}
return V_30 ;
}
static int F_154 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_33 ( V_1 ) ;
F_102 ( V_1 ) ;
F_121 ( V_1 ) ;
if ( F_99 ( V_1 ) ) {
F_103 ( V_1 ) ;
F_100 ( V_1 ) ;
F_32 ( L_35 , V_26 ) ;
return - V_95 ;
}
V_30 = F_69 ( V_1 ) ;
F_103 ( V_1 ) ;
if ( V_30 == 1 ) {
F_100 ( V_1 ) ;
F_32 ( L_36 , V_26 ) ;
F_107 ( V_1 ) ;
F_153 ( & V_114 ) ;
return 0 ;
}
V_30 = F_60 ( V_1 ) ;
F_100 ( V_1 ) ;
if ( ! V_30 ) {
F_85 ( V_146 ) ;
F_155 ( V_1 , V_150 +
F_156 ( V_1 ) ) ;
F_157 ( & V_1 -> V_151 , & V_146 ) ;
V_30 = F_151 ( & V_146 , F_143 , NULL , V_147 ,
V_148 , V_149 ) ;
if ( V_30 ) {
if ( ! F_158 ( & V_146 ) ) {
F_159 ( & V_1 -> V_151 ) ;
F_160 ( V_1 , V_150 +
F_156 ( V_1 ) ) ;
F_161 ( V_1 ) ;
}
F_32 ( L_34 ,
V_26 , V_30 , V_1 -> V_27 ) ;
if ( V_30 > 0 )
V_30 = - V_77 ;
} else {
if ( ! F_26 ( V_1 ) )
F_24 ( F_25 ( V_1 ) ) ;
F_107 ( V_1 ) ;
if ( ! F_26 ( V_1 ) )
F_32 ( L_37 ,
V_26 ) ;
F_153 ( & V_114 ) ;
}
} else {
F_32 ( L_38 ,
V_26 , V_30 , F_83 ( V_1 ) , V_1 -> V_27 ) ;
}
return V_30 ;
}
int F_133 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_33 ( V_1 ) ;
struct V_1 * V_86 = F_18 ( V_1 ) ;
if ( F_99 ( V_1 ) ) {
F_32 ( L_35 , V_26 ) ;
return - V_95 ;
}
if ( ! F_87 ( V_1 ) && F_95 ( V_86 ) ) {
if ( F_58 ( V_86 ) && F_96 ( F_97 ( V_86 ) ) ) {
F_32 ( L_39 ,
V_26 ) ;
return - V_95 ;
}
}
F_162 () ;
if ( F_163 ( V_1 ) != V_152 )
F_164 ( V_1 , true ) ;
V_30 = F_148 ( V_1 , V_26 , V_27 ) ;
F_165 () ;
if ( V_30 > 0 ) {
if ( F_87 ( V_1 ) )
V_30 = F_149 ( V_1 , V_27 ) ;
else
V_30 = F_154 ( V_1 , V_27 ) ;
} else if ( V_30 == 0 ) {
if ( F_87 ( V_1 ) ) {
F_106 ( V_86 ) ;
if ( ! F_79 ( V_86 ) )
F_115 ( 1 << F_17 ( V_86 ) ,
& V_114 ) ;
} else {
if ( ! F_114 ( V_1 ) )
F_153 ( & V_114 ) ;
}
}
F_166 ( V_1 , V_153 ) ;
return V_30 ;
}
