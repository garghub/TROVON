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
if ( V_48 ) {
int V_49 ;
int V_50 = F_27 ( V_2 ) ;
do {
V_49 = F_28 ( V_51 , V_50 , 1000 , 1000 ) ;
if ( F_29 ( V_2 ) == 1 )
break;
} while ( V_49 > 10 );
}
}
static void F_30 ( struct V_22 * V_52 , struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_56 * * V_57 )
{
struct V_56 * V_58 ;
if ( * V_57 ) {
V_58 = * V_57 ;
* V_57 = NULL ;
} else {
V_58 = F_31 ( sizeof( struct V_56 ) , V_59 ) ;
if ( ! V_58 ) {
F_15 ( V_31
L_3 ) ;
return;
}
}
V_58 -> V_24 = F_32 ( V_2 , V_54 ) ;
V_58 -> V_60 = 1 ;
if ( V_58 -> V_24 == - V_61 ) {
F_33 ( L_4 ,
F_34 ( V_2 ) , V_52 -> V_32 ) ;
V_58 -> V_60 = 0 ;
}
F_35 ( V_52 ) ;
V_58 -> V_52 = V_52 ;
F_36 ( & V_58 -> V_62 , V_56 ) ;
}
static void F_37 ( struct V_55 * V_56 , int V_63 , int V_25 ,
int V_64 , struct V_1 * V_1 , unsigned long V_26 ,
int V_27 )
{
struct V_56 * V_58 , * V_65 ;
F_38 (tk, next, to_kill, nd) {
if ( V_63 ) {
if ( V_64 || V_58 -> V_60 == 0 ) {
F_15 ( V_31
L_5 ,
V_26 , V_58 -> V_52 -> V_32 , V_58 -> V_52 -> V_33 ) ;
F_39 ( V_66 , V_58 -> V_52 ) ;
}
else if ( F_14 ( V_58 -> V_52 , V_58 -> V_24 , V_25 ,
V_26 , V_1 , V_27 ) < 0 )
F_15 ( V_31
L_6 ,
V_26 , V_58 -> V_52 -> V_32 , V_58 -> V_52 -> V_33 ) ;
}
F_40 ( V_58 -> V_52 ) ;
F_41 ( V_58 ) ;
}
}
static struct V_22 * F_42 ( struct V_22 * V_52 )
{
struct V_22 * V_23 ;
F_43 (tsk, t)
if ( ( V_23 -> V_27 & V_67 ) && ( V_23 -> V_27 & V_68 ) )
return V_23 ;
return NULL ;
}
static struct V_22 * F_44 ( struct V_22 * V_52 ,
int V_69 )
{
struct V_22 * V_23 ;
if ( ! V_52 -> V_42 )
return NULL ;
if ( V_69 )
return V_52 ;
V_23 = F_42 ( V_52 ) ;
if ( V_23 )
return V_23 ;
if ( V_70 )
return V_52 ;
return NULL ;
}
static void F_45 ( struct V_1 * V_1 , struct V_55 * V_56 ,
struct V_56 * * V_57 , int V_69 )
{
struct V_53 * V_54 ;
struct V_22 * V_52 ;
struct V_71 * V_72 ;
T_2 V_73 ;
V_72 = F_46 ( V_1 ) ;
if ( V_72 == NULL )
return;
V_73 = F_47 ( V_1 ) ;
F_48 ( & V_74 ) ;
F_49 (tsk) {
struct V_75 * V_76 ;
struct V_22 * V_23 = F_44 ( V_52 , V_69 ) ;
if ( ! V_23 )
continue;
F_50 (vmac, &av->rb_root,
pgoff, pgoff) {
V_54 = V_76 -> V_54 ;
if ( ! F_51 ( V_1 , V_54 ) )
continue;
if ( V_54 -> V_77 == V_23 -> V_42 )
F_30 ( V_23 , V_1 , V_54 , V_56 , V_57 ) ;
}
}
F_52 ( & V_74 ) ;
F_53 ( V_72 ) ;
}
static void F_54 ( struct V_1 * V_1 , struct V_55 * V_56 ,
struct V_56 * * V_57 , int V_69 )
{
struct V_53 * V_54 ;
struct V_22 * V_52 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_55 ( V_4 ) ;
F_48 ( & V_74 ) ;
F_49 (tsk) {
T_2 V_73 = F_47 ( V_1 ) ;
struct V_22 * V_23 = F_44 ( V_52 , V_69 ) ;
if ( ! V_23 )
continue;
F_56 (vma, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_54 -> V_77 == V_23 -> V_42 )
F_30 ( V_23 , V_1 , V_54 , V_56 , V_57 ) ;
}
}
F_52 ( & V_74 ) ;
F_57 ( V_4 ) ;
}
static void F_58 ( struct V_1 * V_1 , struct V_55 * V_78 ,
int V_69 )
{
struct V_56 * V_58 ;
if ( ! V_1 -> V_4 )
return;
V_58 = F_31 ( sizeof( struct V_56 ) , V_79 ) ;
if ( ! V_58 )
return;
if ( F_59 ( V_1 ) )
F_45 ( V_1 , V_78 , & V_58 , V_69 ) ;
else
F_54 ( V_1 , V_78 , & V_58 , V_69 ) ;
F_41 ( V_58 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
if ( ! F_61 ( V_2 ) ) {
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
return 0 ;
}
return - V_80 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned long V_26 )
{
return V_81 ;
}
static int F_66 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_15 ( V_31 L_7 , V_26 ) ;
return V_82 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_83 ;
int V_30 = V_82 ;
struct V_3 * V_4 ;
F_60 ( V_2 ) ;
if ( F_59 ( V_2 ) )
return V_84 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_82 ;
}
if ( V_4 -> V_85 -> V_86 ) {
V_83 = V_4 -> V_85 -> V_86 ( V_4 , V_2 ) ;
if ( V_83 != 0 ) {
F_15 ( V_47 L_8 ,
V_26 , V_83 ) ;
} else if ( F_68 ( V_2 ) &&
! F_69 ( V_2 , V_79 ) ) {
F_33 ( L_9 , V_26 ) ;
} else {
V_30 = V_84 ;
}
} else {
if ( F_70 ( V_2 ) )
V_30 = V_84 ;
else
F_15 ( V_47 L_10 ,
V_26 ) ;
}
return V_30 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned long V_26 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_4 ) {
F_73 ( V_4 , V_80 ) ;
}
return F_67 ( V_2 , V_26 ) ;
}
static int F_74 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
if ( ! F_60 ( V_2 ) )
return V_87 ;
else
return V_82 ;
}
static int F_77 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_78 ( V_2 ) ;
if ( ! F_60 ( V_2 ) )
return V_84 ;
else
return V_82 ;
}
static int F_79 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_88 = 0 ;
struct V_1 * V_89 = F_18 ( V_2 ) ;
if ( ! ( F_3 ( V_89 ) || F_59 ( V_89 ) ) ) {
V_88 = F_80 ( V_89 ) ;
if ( ! V_88 )
return V_84 ;
}
return V_87 ;
}
static void F_81 ( unsigned long V_26 , char * V_90 , int V_91 )
{
F_82 ( L_11 ,
V_26 , V_90 , V_92 [ V_91 ] ) ;
}
static int F_83 ( struct V_93 * V_94 , struct V_1 * V_2 ,
unsigned long V_26 )
{
int V_91 ;
int V_95 ;
V_91 = V_94 -> V_96 ( V_2 , V_26 ) ;
V_95 = F_29 ( V_2 ) - 1 ;
if ( V_94 -> V_96 == F_74 && V_91 == V_87 )
V_95 -- ;
if ( V_95 != 0 ) {
F_15 ( V_31
L_12 ,
V_26 , V_94 -> V_90 , V_95 ) ;
V_91 = V_82 ;
}
F_81 ( V_26 , V_94 -> V_90 , V_91 ) ;
return ( V_91 == V_84 || V_91 == V_87 ) ? 0 : - V_97 ;
}
static int F_84 ( struct V_1 * V_2 , unsigned long V_26 ,
int V_25 , int V_27 , struct V_1 * * V_98 )
{
enum V_99 V_100 = V_101 | V_102 | V_103 ;
struct V_3 * V_4 ;
F_85 ( V_78 ) ;
int V_30 ;
int V_104 = 1 , V_63 ;
struct V_1 * V_89 = * V_98 ;
struct V_1 * V_105 ;
if ( F_86 ( V_2 ) || F_2 ( V_2 ) )
return V_106 ;
if ( ! ( F_23 ( V_89 ) || F_87 ( V_2 ) ) )
return V_106 ;
if ( ! F_88 ( V_89 ) )
return V_106 ;
if ( F_89 ( V_2 ) ) {
F_82 ( L_13 , V_26 ) ;
return V_107 ;
}
if ( F_90 ( V_2 ) ) {
F_15 ( V_31
L_14 , V_26 ) ;
V_100 |= V_108 ;
}
V_4 = F_3 ( V_89 ) ;
if ( ! ( V_27 & V_109 ) && ! F_91 ( V_89 ) && V_4 &&
F_92 ( V_4 ) ) {
if ( F_93 ( V_89 ) ) {
F_94 ( V_89 ) ;
} else {
V_104 = 0 ;
V_100 |= V_108 ;
F_15 ( V_47
L_15 ,
V_26 ) ;
}
}
V_105 = V_89 ;
if ( F_95 ( V_89 ) ) {
if ( ! F_87 ( V_89 ) && F_59 ( V_89 ) ) {
if ( F_96 ( F_97 ( V_89 ) ) ) {
F_15 ( V_47
L_16 , V_26 ) ;
F_98 ( ! F_99 ( V_2 ) ) ;
return V_107 ;
}
if ( V_89 != V_2 ) {
if ( ! ( V_27 & V_110 ) ) {
F_100 ( V_89 ) ;
F_101 ( V_2 ) ;
}
F_102 ( V_2 ) ;
F_103 ( V_89 ) ;
* V_98 = V_2 ;
}
V_105 = V_2 ;
}
}
if ( V_104 )
F_58 ( V_105 , & V_78 , V_27 & V_41 ) ;
V_30 = F_104 ( V_105 , V_100 ) ;
if ( V_30 != V_106 )
F_15 ( V_31 L_17 ,
V_26 , F_105 ( V_105 ) ) ;
V_63 = F_91 ( V_105 ) || ( V_27 & V_109 ) ;
F_37 ( & V_78 , V_63 , V_25 ,
V_30 != V_106 , V_2 , V_26 , V_27 ) ;
return V_30 ;
}
static void F_106 ( struct V_1 * V_89 )
{
int V_111 ;
int V_112 = 1 << F_17 ( V_89 ) ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
F_107 ( V_89 + V_111 ) ;
}
static void F_108 ( struct V_1 * V_89 )
{
int V_111 ;
int V_112 = 1 << F_17 ( V_89 ) ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
F_109 ( V_89 + V_111 ) ;
}
int F_110 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_93 * V_94 ;
struct V_1 * V_2 ;
struct V_1 * V_89 ;
int V_88 ;
unsigned int V_112 ;
unsigned long V_113 ;
if ( ! V_114 )
F_111 ( L_18 , V_25 , V_26 ) ;
if ( ! F_112 ( V_26 ) ) {
F_15 ( V_31
L_19 ,
V_26 ) ;
return - V_115 ;
}
V_2 = F_113 ( V_26 ) ;
V_89 = F_18 ( V_2 ) ;
if ( F_114 ( V_2 ) ) {
F_15 ( V_31 L_20 , V_26 ) ;
return 0 ;
}
if ( F_87 ( V_2 ) )
V_112 = 1 << F_17 ( V_89 ) ;
else
V_112 = 1 ;
F_115 ( V_112 , & V_116 ) ;
if ( ! ( V_27 & V_110 ) &&
! F_116 ( V_89 ) ) {
if ( F_26 ( V_2 ) ) {
F_81 ( V_26 , L_21 , V_87 ) ;
return 0 ;
} else if ( F_87 ( V_89 ) ) {
F_102 ( V_89 ) ;
if ( F_99 ( V_89 ) ) {
if ( ( F_13 ( V_2 ) && F_117 ( V_2 ) )
|| ( V_2 != V_89 && F_114 ( V_89 ) ) ) {
F_118 ( V_112 , & V_116 ) ;
F_103 ( V_89 ) ;
return 0 ;
}
}
F_106 ( V_89 ) ;
V_88 = F_80 ( V_89 ) ;
F_81 ( V_26 , L_22 ,
V_88 ? V_81 : V_87 ) ;
F_103 ( V_89 ) ;
return V_88 ;
} else {
F_81 ( V_26 , L_23 , V_81 ) ;
return - V_97 ;
}
}
if ( ! F_87 ( V_2 ) && ! F_119 ( V_2 ) ) {
if ( ! F_23 ( V_2 ) )
F_21 ( V_2 , 0 ) ;
if ( ! F_23 ( V_2 ) ) {
if ( F_26 ( V_2 ) ) {
if ( V_27 & V_110 )
F_81 ( V_26 , L_21 , V_87 ) ;
else
F_81 ( V_26 , L_24 , V_87 ) ;
return 0 ;
}
}
}
F_102 ( V_89 ) ;
if ( F_18 ( V_2 ) != V_89 ) {
F_81 ( V_26 , L_25 , V_81 ) ;
V_88 = - V_97 ;
goto V_117;
}
V_113 = V_2 -> V_27 ;
if ( ! F_99 ( V_2 ) ) {
F_15 ( V_31 L_26 , V_26 ) ;
F_118 ( V_112 , & V_116 ) ;
F_100 ( V_89 ) ;
V_88 = 0 ;
goto V_117;
}
if ( F_13 ( V_2 ) ) {
if ( F_117 ( V_2 ) )
F_118 ( V_112 , & V_116 ) ;
F_103 ( V_89 ) ;
F_100 ( V_89 ) ;
return 0 ;
}
if ( ! F_87 ( V_2 ) && ! F_119 ( V_2 ) && ! F_23 ( V_2 ) )
goto V_118;
if ( F_87 ( V_2 ) && F_120 ( V_2 ) && F_114 ( V_89 ) ) {
F_81 ( V_26 , L_27 ,
V_81 ) ;
F_103 ( V_89 ) ;
F_100 ( V_89 ) ;
return 0 ;
}
if ( F_87 ( V_2 ) )
F_106 ( V_89 ) ;
F_121 ( V_2 ) ;
if ( F_84 ( V_2 , V_26 , V_25 , V_27 , & V_89 )
!= V_106 ) {
F_81 ( V_26 , L_28 , V_81 ) ;
V_88 = - V_97 ;
goto V_117;
}
if ( F_23 ( V_2 ) && ! F_90 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_81 ( V_26 , L_29 , V_81 ) ;
V_88 = - V_97 ;
goto V_117;
}
V_118:
V_88 = - V_97 ;
for ( V_94 = V_119 ; ; V_94 ++ )
if ( ( V_2 -> V_27 & V_94 -> V_120 ) == V_94 -> V_88 )
break;
V_113 |= ( V_2 -> V_27 & ( 1UL << V_121 ) ) ;
if ( ! V_94 -> V_120 )
for ( V_94 = V_119 ; ; V_94 ++ )
if ( ( V_113 & V_94 -> V_120 ) == V_94 -> V_88 )
break;
V_88 = F_83 ( V_94 , V_2 , V_26 ) ;
V_117:
F_103 ( V_89 ) ;
return V_88 ;
}
void F_122 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_122 * V_123 ;
unsigned long V_124 ;
struct V_125 V_126 = {
. V_26 = V_26 ,
. V_25 = V_25 ,
. V_27 = V_27 ,
} ;
V_123 = & F_123 ( V_122 ) ;
F_124 ( & V_123 -> V_127 , V_124 ) ;
if ( F_125 ( & V_123 -> V_128 , V_126 ) )
F_126 ( F_127 () , & V_123 -> V_129 ) ;
else
F_82 ( L_30 ,
V_26 ) ;
F_128 ( & V_123 -> V_127 , V_124 ) ;
F_129 ( V_122 ) ;
}
static void F_130 ( struct V_130 * V_129 )
{
struct V_122 * V_123 ;
struct V_125 V_126 = { 0 , } ;
unsigned long V_124 ;
int V_131 ;
V_123 = F_131 ( & V_122 ) ;
for (; ; ) {
F_124 ( & V_123 -> V_127 , V_124 ) ;
V_131 = F_132 ( & V_123 -> V_128 , & V_126 ) ;
F_128 ( & V_123 -> V_127 , V_124 ) ;
if ( ! V_131 )
break;
if ( V_126 . V_27 & V_132 )
F_133 ( F_113 ( V_126 . V_26 ) , V_126 . V_27 ) ;
else
F_110 ( V_126 . V_26 , V_126 . V_25 , V_126 . V_27 ) ;
}
}
static int T_3 F_134 ( void )
{
struct V_122 * V_123 ;
int V_133 ;
F_135 (cpu) {
V_123 = & F_136 ( V_122 , V_133 ) ;
F_137 ( & V_123 -> V_127 ) ;
F_138 ( V_123 -> V_128 ) ;
F_139 ( & V_123 -> V_129 , F_130 ) ;
}
return 0 ;
}
int F_140 ( unsigned long V_26 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_134 = 0 ;
unsigned int V_112 ;
if ( ! F_112 ( V_26 ) )
return - V_115 ;
V_2 = F_113 ( V_26 ) ;
V_1 = F_18 ( V_2 ) ;
if ( ! F_99 ( V_2 ) ) {
F_33 ( L_31 , V_26 ) ;
return 0 ;
}
if ( ! F_87 ( V_1 ) && F_95 ( V_1 ) ) {
F_33 ( L_32 , V_26 ) ;
return 0 ;
}
V_112 = 1 << F_17 ( V_1 ) ;
if ( ! F_116 ( V_1 ) ) {
if ( F_87 ( V_1 ) ) {
F_33 ( L_33 , V_26 ) ;
return 0 ;
}
if ( F_117 ( V_2 ) )
F_141 ( & V_116 ) ;
F_33 ( L_34 , V_26 ) ;
return 0 ;
}
F_102 ( V_1 ) ;
if ( F_117 ( V_1 ) ) {
F_33 ( L_35 , V_26 ) ;
F_118 ( V_112 , & V_116 ) ;
V_134 = 1 ;
if ( F_87 ( V_1 ) )
F_108 ( V_1 ) ;
}
F_103 ( V_1 ) ;
F_100 ( V_1 ) ;
if ( V_134 && ! ( V_26 == F_142 ( 0 ) && F_29 ( V_2 ) == 1 ) )
F_100 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_143 ( struct V_1 * V_2 , unsigned long V_135 , int * * V_136 )
{
int V_50 = F_27 ( V_2 ) ;
if ( F_87 ( V_2 ) )
return F_144 ( F_145 ( F_18 ( V_2 ) ) ,
V_50 ) ;
else
return F_146 ( V_50 , V_137 , 0 ) ;
}
static int F_147 ( struct V_1 * V_2 , unsigned long V_26 , int V_27 )
{
int V_30 ;
if ( V_27 & V_110 )
return 1 ;
if ( ! F_116 ( F_18 ( V_2 ) ) ) {
if ( F_87 ( V_2 ) ) {
F_33 ( L_36 , V_138 , V_26 ) ;
V_30 = 0 ;
} else if ( F_26 ( V_2 ) ) {
F_33 ( L_37 , V_138 , V_26 ) ;
V_30 = 0 ;
} else {
F_33 ( L_38 ,
V_138 , V_26 , V_2 -> V_27 ) ;
V_30 = - V_80 ;
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
F_33 ( L_39 ,
V_26 , V_1 -> V_27 ) ;
return - V_80 ;
}
}
return V_30 ;
}
static int F_149 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_34 ( V_1 ) ;
struct V_1 * V_89 = F_18 ( V_1 ) ;
F_85 ( V_139 ) ;
F_102 ( V_89 ) ;
if ( F_99 ( V_89 ) ) {
F_103 ( V_89 ) ;
F_100 ( V_89 ) ;
F_33 ( L_40 , V_26 ) ;
return - V_97 ;
}
F_103 ( V_89 ) ;
F_150 ( & V_89 -> V_140 , & V_139 ) ;
V_30 = F_151 ( & V_139 , F_143 , NULL , V_141 ,
V_142 , V_143 ) ;
if ( V_30 ) {
F_33 ( L_41 ,
V_26 , V_30 , V_1 -> V_27 ) ;
F_152 ( V_89 ) ;
if ( V_30 > 0 )
V_30 = - V_80 ;
} else {
if ( F_87 ( V_1 ) ) {
F_106 ( V_89 ) ;
F_80 ( V_89 ) ;
F_115 ( 1 << F_17 ( V_89 ) ,
& V_116 ) ;
} else {
F_107 ( V_1 ) ;
F_153 ( & V_116 ) ;
}
}
return V_30 ;
}
static int F_154 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_34 ( V_1 ) ;
F_102 ( V_1 ) ;
F_121 ( V_1 ) ;
if ( F_99 ( V_1 ) ) {
F_103 ( V_1 ) ;
F_100 ( V_1 ) ;
F_33 ( L_42 , V_26 ) ;
return - V_97 ;
}
V_30 = F_70 ( V_1 ) ;
F_103 ( V_1 ) ;
if ( V_30 == 1 ) {
F_100 ( V_1 ) ;
F_33 ( L_43 , V_26 ) ;
F_107 ( V_1 ) ;
F_153 ( & V_116 ) ;
return 0 ;
}
V_30 = F_61 ( V_1 ) ;
F_100 ( V_1 ) ;
if ( ! V_30 ) {
F_85 ( V_139 ) ;
F_155 ( V_1 , V_144 +
F_156 ( V_1 ) ) ;
F_157 ( & V_1 -> V_140 , & V_139 ) ;
V_30 = F_151 ( & V_139 , F_143 , NULL , V_141 ,
V_142 , V_143 ) ;
if ( V_30 ) {
if ( ! F_158 ( & V_139 ) ) {
F_159 ( & V_1 -> V_140 ) ;
F_160 ( V_1 , V_144 +
F_156 ( V_1 ) ) ;
F_161 ( V_1 ) ;
}
F_33 ( L_41 ,
V_26 , V_30 , V_1 -> V_27 ) ;
if ( V_30 > 0 )
V_30 = - V_80 ;
} else {
if ( ! F_26 ( V_1 ) )
F_22 () ;
if ( ! F_26 ( V_1 ) )
F_24 ( F_25 ( V_1 ) ) ;
F_107 ( V_1 ) ;
if ( ! F_26 ( V_1 ) )
F_33 ( L_44 ,
V_26 ) ;
F_153 ( & V_116 ) ;
}
} else {
F_33 ( L_45 ,
V_26 , V_30 , F_29 ( V_1 ) , V_1 -> V_27 ) ;
}
return V_30 ;
}
int F_133 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_34 ( V_1 ) ;
struct V_1 * V_89 = F_18 ( V_1 ) ;
if ( F_99 ( V_1 ) ) {
F_33 ( L_42 , V_26 ) ;
return - V_97 ;
}
if ( ! F_87 ( V_1 ) && F_95 ( V_89 ) ) {
if ( F_59 ( V_89 ) && F_96 ( F_97 ( V_89 ) ) ) {
F_33 ( L_46 ,
V_26 ) ;
return - V_97 ;
}
}
F_162 () ;
if ( F_163 ( V_1 ) != V_145 )
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
F_106 ( V_89 ) ;
F_80 ( V_89 ) ;
F_115 ( 1 << F_17 ( V_89 ) ,
& V_116 ) ;
} else {
F_107 ( V_1 ) ;
F_153 ( & V_116 ) ;
}
}
F_166 ( V_1 , V_146 ) ;
return V_30 ;
}
