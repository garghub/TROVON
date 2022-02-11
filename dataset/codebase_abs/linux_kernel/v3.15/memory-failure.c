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
if ( ! V_18 || V_18 != V_19 )
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
if ( ( V_27 & V_41 ) && V_23 == V_42 ) {
V_29 . V_43 = V_44 ;
V_30 = F_19 ( V_35 , & V_29 , V_23 ) ;
} else {
V_29 . V_43 = V_45 ;
V_30 = F_20 ( V_35 , & V_29 , V_23 ) ;
}
if ( V_30 < 0 )
F_15 ( V_46 L_2 ,
V_23 -> V_32 , V_23 -> V_33 , V_30 ) ;
return V_30 ;
}
void F_21 ( struct V_1 * V_2 , int V_47 )
{
if ( ! F_2 ( V_2 ) ) {
F_22 () ;
if ( F_23 ( V_2 ) )
return;
F_24 () ;
if ( F_23 ( V_2 ) || F_25 ( V_2 ) )
return;
}
if ( V_47 ) {
int V_48 ;
int V_49 = F_26 ( V_2 ) ;
do {
struct V_50 V_51 = {
. V_52 = V_53 ,
} ;
F_27 ( V_49 , V_51 . V_54 ) ;
V_48 = F_28 ( & V_51 , 1000 , 1000 ) ;
if ( F_29 ( V_2 ) == 1 )
break;
} while ( V_48 > 10 );
}
}
static void F_30 ( struct V_22 * V_55 , struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_59 * * V_60 )
{
struct V_59 * V_61 ;
if ( * V_60 ) {
V_61 = * V_60 ;
* V_60 = NULL ;
} else {
V_61 = F_31 ( sizeof( struct V_59 ) , V_62 ) ;
if ( ! V_61 ) {
F_15 ( V_31
L_3 ) ;
return;
}
}
V_61 -> V_24 = F_32 ( V_2 , V_57 ) ;
V_61 -> V_63 = 1 ;
if ( V_61 -> V_24 == - V_64 ) {
F_33 ( L_4 ,
F_34 ( V_2 ) , V_55 -> V_32 ) ;
V_61 -> V_63 = 0 ;
}
F_35 ( V_55 ) ;
V_61 -> V_55 = V_55 ;
F_36 ( & V_61 -> V_65 , V_59 ) ;
}
static void F_37 ( struct V_58 * V_59 , int V_66 , int V_25 ,
int V_67 , struct V_1 * V_1 , unsigned long V_26 ,
int V_27 )
{
struct V_59 * V_61 , * V_68 ;
F_38 (tk, next, to_kill, nd) {
if ( V_66 ) {
if ( V_67 || V_61 -> V_63 == 0 ) {
F_15 ( V_31
L_5 ,
V_26 , V_61 -> V_55 -> V_32 , V_61 -> V_55 -> V_33 ) ;
F_39 ( V_69 , V_61 -> V_55 ) ;
}
else if ( F_14 ( V_61 -> V_55 , V_61 -> V_24 , V_25 ,
V_26 , V_1 , V_27 ) < 0 )
F_15 ( V_31
L_6 ,
V_26 , V_61 -> V_55 -> V_32 , V_61 -> V_55 -> V_33 ) ;
}
F_40 ( V_61 -> V_55 ) ;
F_41 ( V_61 ) ;
}
}
static int F_42 ( struct V_22 * V_55 )
{
if ( ! V_55 -> V_70 )
return 0 ;
if ( V_55 -> V_27 & V_71 )
return ! ! ( V_55 -> V_27 & V_72 ) ;
return V_73 ;
}
static void F_43 ( struct V_1 * V_1 , struct V_58 * V_59 ,
struct V_59 * * V_60 )
{
struct V_56 * V_57 ;
struct V_22 * V_55 ;
struct V_74 * V_75 ;
T_2 V_76 ;
V_75 = F_44 ( V_1 ) ;
if ( V_75 == NULL )
return;
V_76 = V_1 -> V_77 << ( V_78 - V_40 ) ;
F_45 ( & V_79 ) ;
F_46 (tsk) {
struct V_80 * V_81 ;
if ( ! F_42 ( V_55 ) )
continue;
F_47 (vmac, &av->rb_root,
pgoff, pgoff) {
V_57 = V_81 -> V_57 ;
if ( ! F_48 ( V_1 , V_57 ) )
continue;
if ( V_57 -> V_82 == V_55 -> V_70 )
F_30 ( V_55 , V_1 , V_57 , V_59 , V_60 ) ;
}
}
F_49 ( & V_79 ) ;
F_50 ( V_75 ) ;
}
static void F_51 ( struct V_1 * V_1 , struct V_58 * V_59 ,
struct V_59 * * V_60 )
{
struct V_56 * V_57 ;
struct V_22 * V_55 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_52 ( & V_4 -> V_83 ) ;
F_45 ( & V_79 ) ;
F_46 (tsk) {
T_2 V_76 = V_1 -> V_77 << ( V_78 - V_40 ) ;
if ( ! F_42 ( V_55 ) )
continue;
F_53 (vma, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_57 -> V_82 == V_55 -> V_70 )
F_30 ( V_55 , V_1 , V_57 , V_59 , V_60 ) ;
}
}
F_49 ( & V_79 ) ;
F_54 ( & V_4 -> V_83 ) ;
}
static void F_55 ( struct V_1 * V_1 , struct V_58 * V_84 )
{
struct V_59 * V_61 ;
if ( ! V_1 -> V_4 )
return;
V_61 = F_31 ( sizeof( struct V_59 ) , V_85 ) ;
if ( ! V_61 )
return;
if ( F_56 ( V_1 ) )
F_43 ( V_1 , V_84 , & V_61 ) ;
else
F_51 ( V_1 , V_84 , & V_61 ) ;
F_41 ( V_61 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
if ( ! F_58 ( V_2 ) ) {
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
return - V_86 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned long V_26 )
{
return V_87 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_15 ( V_31 L_7 , V_26 ) ;
return V_88 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_89 ;
int V_30 = V_88 ;
struct V_3 * V_4 ;
F_57 ( V_2 ) ;
if ( F_56 ( V_2 ) )
return V_90 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_88 ;
}
if ( V_4 -> V_91 -> V_92 ) {
V_89 = V_4 -> V_91 -> V_92 ( V_4 , V_2 ) ;
if ( V_89 != 0 ) {
F_15 ( V_46 L_8 ,
V_26 , V_89 ) ;
} else if ( F_65 ( V_2 ) &&
! F_66 ( V_2 , V_85 ) ) {
F_33 ( L_9 , V_26 ) ;
} else {
V_30 = V_90 ;
}
} else {
if ( F_67 ( V_2 ) )
V_30 = V_90 ;
else
F_15 ( V_46 L_10 ,
V_26 ) ;
}
return V_30 ;
}
static int F_68 ( struct V_1 * V_2 , unsigned long V_26 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_69 ( V_2 ) ;
if ( V_4 ) {
F_70 ( V_4 , V_86 ) ;
}
return F_64 ( V_2 , V_26 ) ;
}
static int F_71 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
if ( ! F_57 ( V_2 ) )
return V_93 ;
else
return V_88 ;
}
static int F_74 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_75 ( V_2 ) ;
if ( ! F_57 ( V_2 ) )
return V_90 ;
else
return V_88 ;
}
static int F_76 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_94 = 0 ;
struct V_1 * V_95 = F_18 ( V_2 ) ;
if ( ! ( F_3 ( V_95 ) || F_56 ( V_95 ) ) ) {
V_94 = F_77 ( V_95 ) ;
if ( ! V_94 )
return V_90 ;
}
return V_93 ;
}
static void F_78 ( unsigned long V_26 , char * V_96 , int V_97 )
{
F_79 ( L_11 ,
V_26 , V_96 , V_98 [ V_97 ] ) ;
}
static int F_80 ( struct V_99 * V_100 , struct V_1 * V_2 ,
unsigned long V_26 )
{
int V_97 ;
int V_101 ;
V_97 = V_100 -> V_102 ( V_2 , V_26 ) ;
F_78 ( V_26 , V_100 -> V_96 , V_97 ) ;
V_101 = F_29 ( V_2 ) - 1 ;
if ( V_100 -> V_102 == F_71 && V_97 == V_93 )
V_101 -- ;
if ( V_101 != 0 ) {
F_15 ( V_31
L_12 ,
V_26 , V_100 -> V_96 , V_101 ) ;
V_97 = V_88 ;
}
return ( V_97 == V_90 || V_97 == V_93 ) ? 0 : - V_103 ;
}
static int F_81 ( struct V_1 * V_2 , unsigned long V_26 ,
int V_25 , int V_27 , struct V_1 * * V_104 )
{
enum V_105 V_106 = V_107 | V_108 | V_109 ;
struct V_3 * V_4 ;
F_82 ( V_84 ) ;
int V_30 ;
int V_110 = 1 , V_66 ;
struct V_1 * V_95 = * V_104 ;
struct V_1 * V_111 ;
if ( F_83 ( V_2 ) || F_2 ( V_2 ) )
return V_112 ;
if ( ! F_84 ( V_95 ) )
return V_112 ;
if ( F_85 ( V_2 ) )
return V_113 ;
if ( F_86 ( V_2 ) ) {
F_15 ( V_31
L_13 , V_26 ) ;
V_106 |= V_114 ;
}
V_4 = F_3 ( V_95 ) ;
if ( ! ( V_27 & V_115 ) && ! F_87 ( V_95 ) && V_4 &&
F_88 ( V_4 ) ) {
if ( F_89 ( V_95 ) ) {
F_90 ( V_95 ) ;
} else {
V_110 = 0 ;
V_106 |= V_114 ;
F_15 ( V_46
L_14 ,
V_26 ) ;
}
}
V_111 = V_95 ;
if ( F_91 ( V_95 ) ) {
if ( ! F_92 ( V_95 ) && F_56 ( V_95 ) ) {
if ( F_93 ( F_94 ( V_95 ) ) ) {
F_15 ( V_46
L_15 , V_26 ) ;
F_95 ( ! F_96 ( V_2 ) ) ;
return V_113 ;
}
if ( V_95 != V_2 ) {
if ( ! ( V_27 & V_116 ) ) {
F_97 ( V_95 ) ;
F_98 ( V_2 ) ;
}
F_99 ( V_2 ) ;
F_100 ( V_95 ) ;
* V_104 = V_2 ;
}
V_111 = V_2 ;
}
}
if ( V_110 )
F_55 ( V_111 , & V_84 ) ;
V_30 = F_101 ( V_111 , V_106 ) ;
if ( V_30 != V_112 )
F_15 ( V_31 L_16 ,
V_26 , F_102 ( V_111 ) ) ;
V_66 = F_87 ( V_111 ) || ( V_27 & V_115 ) ;
F_37 ( & V_84 , V_66 , V_25 ,
V_30 != V_112 , V_2 , V_26 , V_27 ) ;
return V_30 ;
}
static void F_103 ( struct V_1 * V_95 )
{
int V_117 ;
int V_118 = 1 << F_17 ( V_95 ) ;
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ )
F_104 ( V_95 + V_117 ) ;
}
static void F_105 ( struct V_1 * V_95 )
{
int V_117 ;
int V_118 = 1 << F_17 ( V_95 ) ;
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ )
F_106 ( V_95 + V_117 ) ;
}
int F_107 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_99 * V_100 ;
struct V_1 * V_2 ;
struct V_1 * V_95 ;
int V_94 ;
unsigned int V_118 ;
unsigned long V_119 ;
if ( ! V_120 )
F_108 ( L_17 , V_25 , V_26 ) ;
if ( ! F_109 ( V_26 ) ) {
F_15 ( V_31
L_18 ,
V_26 ) ;
return - V_121 ;
}
V_2 = F_110 ( V_26 ) ;
V_95 = F_18 ( V_2 ) ;
if ( F_111 ( V_2 ) ) {
F_15 ( V_31 L_19 , V_26 ) ;
return 0 ;
}
if ( F_92 ( V_2 ) )
V_118 = 1 << F_17 ( V_95 ) ;
else
V_118 = 1 ;
F_112 ( V_118 , & V_122 ) ;
if ( ! ( V_27 & V_116 ) &&
! F_113 ( V_95 ) ) {
if ( F_25 ( V_2 ) ) {
F_78 ( V_26 , L_20 , V_93 ) ;
return 0 ;
} else if ( F_92 ( V_95 ) ) {
F_99 ( V_95 ) ;
if ( F_96 ( V_95 ) ) {
if ( ( F_13 ( V_2 ) && F_114 ( V_2 ) )
|| ( V_2 != V_95 && F_111 ( V_95 ) ) ) {
F_115 ( V_118 , & V_122 ) ;
F_100 ( V_95 ) ;
return 0 ;
}
}
F_103 ( V_95 ) ;
V_94 = F_77 ( V_95 ) ;
F_78 ( V_26 , L_21 ,
V_94 ? V_87 : V_93 ) ;
F_100 ( V_95 ) ;
return V_94 ;
} else {
F_78 ( V_26 , L_22 , V_87 ) ;
return - V_103 ;
}
}
if ( ! F_92 ( V_2 ) && ! F_116 ( V_2 ) ) {
if ( ! F_23 ( V_2 ) )
F_21 ( V_2 , 0 ) ;
if ( ! F_23 ( V_2 ) ) {
if ( F_25 ( V_2 ) ) {
if ( V_27 & V_116 )
F_78 ( V_26 , L_20 , V_93 ) ;
else
F_78 ( V_26 , L_23 , V_93 ) ;
return 0 ;
}
F_78 ( V_26 , L_24 , V_87 ) ;
F_97 ( V_2 ) ;
return - V_103 ;
}
}
F_99 ( V_95 ) ;
V_119 = V_2 -> V_27 ;
if ( ! F_96 ( V_2 ) ) {
F_15 ( V_31 L_25 , V_26 ) ;
F_115 ( V_118 , & V_122 ) ;
F_97 ( V_95 ) ;
V_94 = 0 ;
goto V_123;
}
if ( F_13 ( V_2 ) ) {
if ( F_114 ( V_2 ) )
F_115 ( V_118 , & V_122 ) ;
F_100 ( V_95 ) ;
F_97 ( V_95 ) ;
return 0 ;
}
if ( F_92 ( V_2 ) && F_117 ( V_2 ) && F_111 ( V_95 ) ) {
F_78 ( V_26 , L_26 ,
V_87 ) ;
F_100 ( V_95 ) ;
F_97 ( V_95 ) ;
return 0 ;
}
if ( F_92 ( V_2 ) )
F_103 ( V_95 ) ;
F_118 ( V_2 ) ;
if ( F_81 ( V_2 , V_26 , V_25 , V_27 , & V_95 )
!= V_112 ) {
F_15 ( V_31 L_27 , V_26 ) ;
V_94 = - V_103 ;
goto V_123;
}
if ( F_23 ( V_2 ) && ! F_86 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_78 ( V_26 , L_28 , V_87 ) ;
V_94 = - V_103 ;
goto V_123;
}
V_94 = - V_103 ;
for ( V_100 = V_124 ; ; V_100 ++ )
if ( ( V_2 -> V_27 & V_100 -> V_125 ) == V_100 -> V_94 )
break;
V_119 |= ( V_2 -> V_27 & ( 1UL << V_126 ) ) ;
if ( ! V_100 -> V_125 )
for ( V_100 = V_124 ; ; V_100 ++ )
if ( ( V_119 & V_100 -> V_125 ) == V_100 -> V_94 )
break;
V_94 = F_80 ( V_100 , V_2 , V_26 ) ;
V_123:
F_100 ( V_95 ) ;
return V_94 ;
}
void F_119 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_127 * V_128 ;
unsigned long V_129 ;
struct V_130 V_131 = {
. V_26 = V_26 ,
. V_25 = V_25 ,
. V_27 = V_27 ,
} ;
V_128 = & F_120 ( V_127 ) ;
F_121 ( & V_128 -> V_132 , V_129 ) ;
if ( F_122 ( & V_128 -> V_133 , V_131 ) )
F_123 ( F_124 () , & V_128 -> V_134 ) ;
else
F_79 ( L_29 ,
V_26 ) ;
F_125 ( & V_128 -> V_132 , V_129 ) ;
F_126 ( V_127 ) ;
}
static void F_127 ( struct V_135 * V_134 )
{
struct V_127 * V_128 ;
struct V_130 V_131 = { 0 , } ;
unsigned long V_129 ;
int V_136 ;
V_128 = & F_128 ( V_127 ) ;
for (; ; ) {
F_121 ( & V_128 -> V_132 , V_129 ) ;
V_136 = F_129 ( & V_128 -> V_133 , & V_131 ) ;
F_125 ( & V_128 -> V_132 , V_129 ) ;
if ( ! V_136 )
break;
if ( V_131 . V_27 & V_137 )
F_130 ( F_110 ( V_131 . V_26 ) , V_131 . V_27 ) ;
else
F_107 ( V_131 . V_26 , V_131 . V_25 , V_131 . V_27 ) ;
}
}
static int T_3 F_131 ( void )
{
struct V_127 * V_128 ;
int V_138 ;
F_132 (cpu) {
V_128 = & F_133 ( V_127 , V_138 ) ;
F_134 ( & V_128 -> V_132 ) ;
F_135 ( V_128 -> V_133 ) ;
F_136 ( & V_128 -> V_134 , F_127 ) ;
}
return 0 ;
}
int F_137 ( unsigned long V_26 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_139 = 0 ;
unsigned int V_118 ;
if ( ! F_109 ( V_26 ) )
return - V_121 ;
V_2 = F_110 ( V_26 ) ;
V_1 = F_18 ( V_2 ) ;
if ( ! F_96 ( V_2 ) ) {
F_33 ( L_30 , V_26 ) ;
return 0 ;
}
if ( ! F_92 ( V_1 ) && F_91 ( V_1 ) ) {
F_33 ( L_31 , V_26 ) ;
return 0 ;
}
V_118 = 1 << F_17 ( V_1 ) ;
if ( ! F_113 ( V_1 ) ) {
if ( F_92 ( V_1 ) ) {
F_33 ( L_32 , V_26 ) ;
return 0 ;
}
if ( F_114 ( V_2 ) )
F_138 ( & V_122 ) ;
F_33 ( L_33 , V_26 ) ;
return 0 ;
}
F_99 ( V_1 ) ;
if ( F_114 ( V_1 ) ) {
F_33 ( L_34 , V_26 ) ;
F_115 ( V_118 , & V_122 ) ;
V_139 = 1 ;
if ( F_92 ( V_1 ) )
F_105 ( V_1 ) ;
}
F_100 ( V_1 ) ;
F_97 ( V_1 ) ;
if ( V_139 && ! ( V_26 == F_139 ( 0 ) && F_29 ( V_2 ) == 1 ) )
F_97 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_140 ( struct V_1 * V_2 , unsigned long V_140 , int * * V_141 )
{
int V_49 = F_26 ( V_2 ) ;
if ( F_92 ( V_2 ) )
return F_141 ( F_142 ( F_18 ( V_2 ) ) ,
V_49 ) ;
else
return F_143 ( V_49 , V_142 , 0 ) ;
}
static int F_144 ( struct V_1 * V_2 , unsigned long V_26 , int V_27 )
{
int V_30 ;
if ( V_27 & V_116 )
return 1 ;
if ( ! F_113 ( F_18 ( V_2 ) ) ) {
if ( F_92 ( V_2 ) ) {
F_33 ( L_35 , V_143 , V_26 ) ;
V_30 = 0 ;
} else if ( F_25 ( V_2 ) ) {
F_33 ( L_36 , V_143 , V_26 ) ;
V_30 = 0 ;
} else {
F_33 ( L_37 ,
V_143 , V_26 , V_2 -> V_27 ) ;
V_30 = - V_86 ;
}
} else {
V_30 = 1 ;
}
return V_30 ;
}
static int F_145 ( struct V_1 * V_1 , unsigned long V_26 , int V_27 )
{
int V_30 = F_144 ( V_1 , V_26 , V_27 ) ;
if ( V_30 == 1 && ! F_92 ( V_1 ) && ! F_23 ( V_1 ) ) {
F_97 ( V_1 ) ;
F_21 ( V_1 , 1 ) ;
V_30 = F_144 ( V_1 , V_26 , 0 ) ;
if ( ! F_23 ( V_1 ) ) {
F_33 ( L_38 ,
V_26 , V_1 -> V_27 ) ;
return - V_86 ;
}
}
return V_30 ;
}
static int F_146 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_34 ( V_1 ) ;
struct V_1 * V_95 = F_18 ( V_1 ) ;
F_82 ( V_144 ) ;
F_99 ( V_95 ) ;
if ( F_96 ( V_95 ) ) {
F_100 ( V_95 ) ;
F_97 ( V_95 ) ;
F_33 ( L_39 , V_26 ) ;
return - V_103 ;
}
F_100 ( V_95 ) ;
F_147 ( & V_95 -> V_145 , & V_144 ) ;
V_30 = F_148 ( & V_144 , F_140 , V_146 ,
V_147 , V_148 ) ;
if ( V_30 ) {
F_33 ( L_40 ,
V_26 , V_30 , V_1 -> V_27 ) ;
F_149 ( V_95 ) ;
if ( V_30 > 0 )
V_30 = - V_86 ;
} else {
if ( F_92 ( V_1 ) ) {
F_103 ( V_95 ) ;
F_77 ( V_95 ) ;
F_112 ( 1 << F_17 ( V_95 ) ,
& V_122 ) ;
} else {
F_104 ( V_1 ) ;
F_150 ( & V_122 ) ;
}
}
return V_30 ;
}
static int F_151 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_34 ( V_1 ) ;
F_99 ( V_1 ) ;
F_118 ( V_1 ) ;
if ( F_96 ( V_1 ) ) {
F_100 ( V_1 ) ;
F_97 ( V_1 ) ;
F_33 ( L_41 , V_26 ) ;
return - V_103 ;
}
V_30 = F_67 ( V_1 ) ;
F_100 ( V_1 ) ;
if ( V_30 == 1 ) {
F_97 ( V_1 ) ;
F_33 ( L_42 , V_26 ) ;
F_104 ( V_1 ) ;
F_150 ( & V_122 ) ;
return 0 ;
}
V_30 = F_58 ( V_1 ) ;
F_97 ( V_1 ) ;
if ( ! V_30 ) {
F_82 ( V_144 ) ;
F_152 ( V_1 , V_149 +
F_153 ( V_1 ) ) ;
F_154 ( & V_1 -> V_145 , & V_144 ) ;
V_30 = F_148 ( & V_144 , F_140 , V_146 ,
V_147 , V_148 ) ;
if ( V_30 ) {
if ( ! F_155 ( & V_144 ) ) {
F_156 ( & V_1 -> V_145 ) ;
F_157 ( V_1 , V_149 +
F_153 ( V_1 ) ) ;
F_158 ( V_1 ) ;
}
F_33 ( L_40 ,
V_26 , V_30 , V_1 -> V_27 ) ;
if ( V_30 > 0 )
V_30 = - V_86 ;
} else {
if ( ! F_25 ( V_1 ) )
F_22 () ;
if ( ! F_25 ( V_1 ) )
F_24 () ;
F_104 ( V_1 ) ;
if ( ! F_25 ( V_1 ) )
F_33 ( L_43 ,
V_26 ) ;
F_150 ( & V_122 ) ;
}
} else {
F_33 ( L_44 ,
V_26 , V_30 , F_29 ( V_1 ) , V_1 -> V_27 ) ;
}
return V_30 ;
}
int F_130 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_34 ( V_1 ) ;
struct V_1 * V_95 = F_18 ( V_1 ) ;
if ( F_96 ( V_1 ) ) {
F_33 ( L_41 , V_26 ) ;
return - V_103 ;
}
if ( ! F_92 ( V_1 ) && F_91 ( V_95 ) ) {
if ( F_56 ( V_95 ) && F_93 ( F_94 ( V_95 ) ) ) {
F_33 ( L_45 ,
V_26 ) ;
return - V_103 ;
}
}
F_159 () ;
if ( F_160 ( V_1 ) != V_150 )
F_161 ( V_1 , true ) ;
V_30 = F_145 ( V_1 , V_26 , V_27 ) ;
F_162 () ;
if ( V_30 > 0 ) {
if ( F_92 ( V_1 ) )
V_30 = F_146 ( V_1 , V_27 ) ;
else
V_30 = F_151 ( V_1 , V_27 ) ;
} else if ( V_30 == 0 ) {
if ( F_92 ( V_1 ) ) {
F_103 ( V_95 ) ;
F_77 ( V_95 ) ;
F_112 ( 1 << F_17 ( V_95 ) ,
& V_122 ) ;
} else {
F_104 ( V_1 ) ;
F_150 ( & V_122 ) ;
}
}
F_163 ( V_1 , V_151 ) ;
return V_30 ;
}
