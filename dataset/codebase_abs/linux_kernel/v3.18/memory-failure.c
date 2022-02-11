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
F_24 () ;
if ( F_23 ( V_2 ) || F_25 ( V_2 ) )
return;
}
if ( V_48 ) {
int V_49 ;
int V_50 = F_26 ( V_2 ) ;
do {
struct V_51 V_52 = {
. V_53 = V_54 ,
} ;
F_27 ( V_50 , V_52 . V_55 ) ;
V_49 = F_28 ( & V_52 , 1000 , 1000 ) ;
if ( F_29 ( V_2 ) == 1 )
break;
} while ( V_49 > 10 );
}
}
static void F_30 ( struct V_22 * V_56 , struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_60 * * V_61 )
{
struct V_60 * V_62 ;
if ( * V_61 ) {
V_62 = * V_61 ;
* V_61 = NULL ;
} else {
V_62 = F_31 ( sizeof( struct V_60 ) , V_63 ) ;
if ( ! V_62 ) {
F_15 ( V_31
L_3 ) ;
return;
}
}
V_62 -> V_24 = F_32 ( V_2 , V_58 ) ;
V_62 -> V_64 = 1 ;
if ( V_62 -> V_24 == - V_65 ) {
F_33 ( L_4 ,
F_34 ( V_2 ) , V_56 -> V_32 ) ;
V_62 -> V_64 = 0 ;
}
F_35 ( V_56 ) ;
V_62 -> V_56 = V_56 ;
F_36 ( & V_62 -> V_66 , V_60 ) ;
}
static void F_37 ( struct V_59 * V_60 , int V_67 , int V_25 ,
int V_68 , struct V_1 * V_1 , unsigned long V_26 ,
int V_27 )
{
struct V_60 * V_62 , * V_69 ;
F_38 (tk, next, to_kill, nd) {
if ( V_67 ) {
if ( V_68 || V_62 -> V_64 == 0 ) {
F_15 ( V_31
L_5 ,
V_26 , V_62 -> V_56 -> V_32 , V_62 -> V_56 -> V_33 ) ;
F_39 ( V_70 , V_62 -> V_56 ) ;
}
else if ( F_14 ( V_62 -> V_56 , V_62 -> V_24 , V_25 ,
V_26 , V_1 , V_27 ) < 0 )
F_15 ( V_31
L_6 ,
V_26 , V_62 -> V_56 -> V_32 , V_62 -> V_56 -> V_33 ) ;
}
F_40 ( V_62 -> V_56 ) ;
F_41 ( V_62 ) ;
}
}
static struct V_22 * F_42 ( struct V_22 * V_56 )
{
struct V_22 * V_23 ;
F_43 (tsk, t)
if ( ( V_23 -> V_27 & V_71 ) && ( V_23 -> V_27 & V_72 ) )
return V_23 ;
return NULL ;
}
static struct V_22 * F_44 ( struct V_22 * V_56 ,
int V_73 )
{
struct V_22 * V_23 ;
if ( ! V_56 -> V_42 )
return NULL ;
if ( V_73 )
return V_56 ;
V_23 = F_42 ( V_56 ) ;
if ( V_23 )
return V_23 ;
if ( V_74 )
return V_56 ;
return NULL ;
}
static void F_45 ( struct V_1 * V_1 , struct V_59 * V_60 ,
struct V_60 * * V_61 , int V_73 )
{
struct V_57 * V_58 ;
struct V_22 * V_56 ;
struct V_75 * V_76 ;
T_2 V_77 ;
V_76 = F_46 ( V_1 ) ;
if ( V_76 == NULL )
return;
V_77 = F_47 ( V_1 ) ;
F_48 ( & V_78 ) ;
F_49 (tsk) {
struct V_79 * V_80 ;
struct V_22 * V_23 = F_44 ( V_56 , V_73 ) ;
if ( ! V_23 )
continue;
F_50 (vmac, &av->rb_root,
pgoff, pgoff) {
V_58 = V_80 -> V_58 ;
if ( ! F_51 ( V_1 , V_58 ) )
continue;
if ( V_58 -> V_81 == V_23 -> V_42 )
F_30 ( V_23 , V_1 , V_58 , V_60 , V_61 ) ;
}
}
F_52 ( & V_78 ) ;
F_53 ( V_76 ) ;
}
static void F_54 ( struct V_1 * V_1 , struct V_59 * V_60 ,
struct V_60 * * V_61 , int V_73 )
{
struct V_57 * V_58 ;
struct V_22 * V_56 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_55 ( & V_4 -> V_82 ) ;
F_48 ( & V_78 ) ;
F_49 (tsk) {
T_2 V_77 = F_47 ( V_1 ) ;
struct V_22 * V_23 = F_44 ( V_56 , V_73 ) ;
if ( ! V_23 )
continue;
F_56 (vma, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_58 -> V_81 == V_23 -> V_42 )
F_30 ( V_23 , V_1 , V_58 , V_60 , V_61 ) ;
}
}
F_52 ( & V_78 ) ;
F_57 ( & V_4 -> V_82 ) ;
}
static void F_58 ( struct V_1 * V_1 , struct V_59 * V_83 ,
int V_73 )
{
struct V_60 * V_62 ;
if ( ! V_1 -> V_4 )
return;
V_62 = F_31 ( sizeof( struct V_60 ) , V_84 ) ;
if ( ! V_62 )
return;
if ( F_59 ( V_1 ) )
F_45 ( V_1 , V_83 , & V_62 , V_73 ) ;
else
F_54 ( V_1 , V_83 , & V_62 , V_73 ) ;
F_41 ( V_62 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
if ( ! F_61 ( V_2 ) ) {
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
return 0 ;
}
return - V_85 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned long V_26 )
{
return V_86 ;
}
static int F_66 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_15 ( V_31 L_7 , V_26 ) ;
return V_87 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_88 ;
int V_30 = V_87 ;
struct V_3 * V_4 ;
F_60 ( V_2 ) ;
if ( F_59 ( V_2 ) )
return V_89 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_87 ;
}
if ( V_4 -> V_90 -> V_91 ) {
V_88 = V_4 -> V_90 -> V_91 ( V_4 , V_2 ) ;
if ( V_88 != 0 ) {
F_15 ( V_47 L_8 ,
V_26 , V_88 ) ;
} else if ( F_68 ( V_2 ) &&
! F_69 ( V_2 , V_84 ) ) {
F_33 ( L_9 , V_26 ) ;
} else {
V_30 = V_89 ;
}
} else {
if ( F_70 ( V_2 ) )
V_30 = V_89 ;
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
F_73 ( V_4 , V_85 ) ;
}
return F_67 ( V_2 , V_26 ) ;
}
static int F_74 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
if ( ! F_60 ( V_2 ) )
return V_92 ;
else
return V_87 ;
}
static int F_77 ( struct V_1 * V_2 , unsigned long V_26 )
{
F_78 ( V_2 ) ;
if ( ! F_60 ( V_2 ) )
return V_89 ;
else
return V_87 ;
}
static int F_79 ( struct V_1 * V_2 , unsigned long V_26 )
{
int V_93 = 0 ;
struct V_1 * V_94 = F_18 ( V_2 ) ;
if ( ! ( F_3 ( V_94 ) || F_59 ( V_94 ) ) ) {
V_93 = F_80 ( V_94 ) ;
if ( ! V_93 )
return V_89 ;
}
return V_92 ;
}
static void F_81 ( unsigned long V_26 , char * V_95 , int V_96 )
{
F_82 ( L_11 ,
V_26 , V_95 , V_97 [ V_96 ] ) ;
}
static int F_83 ( struct V_98 * V_99 , struct V_1 * V_2 ,
unsigned long V_26 )
{
int V_96 ;
int V_100 ;
V_96 = V_99 -> V_101 ( V_2 , V_26 ) ;
F_81 ( V_26 , V_99 -> V_95 , V_96 ) ;
V_100 = F_29 ( V_2 ) - 1 ;
if ( V_99 -> V_101 == F_74 && V_96 == V_92 )
V_100 -- ;
if ( V_100 != 0 ) {
F_15 ( V_31
L_12 ,
V_26 , V_99 -> V_95 , V_100 ) ;
V_96 = V_87 ;
}
return ( V_96 == V_89 || V_96 == V_92 ) ? 0 : - V_102 ;
}
static int F_84 ( struct V_1 * V_2 , unsigned long V_26 ,
int V_25 , int V_27 , struct V_1 * * V_103 )
{
enum V_104 V_105 = V_106 | V_107 | V_108 ;
struct V_3 * V_4 ;
F_85 ( V_83 ) ;
int V_30 ;
int V_109 = 1 , V_67 ;
struct V_1 * V_94 = * V_103 ;
struct V_1 * V_110 ;
if ( F_86 ( V_2 ) || F_2 ( V_2 ) )
return V_111 ;
if ( ! ( F_23 ( V_94 ) || F_87 ( V_2 ) ) )
return V_111 ;
if ( ! F_88 ( V_94 ) )
return V_111 ;
if ( F_89 ( V_2 ) ) {
F_82 ( L_13 , V_26 ) ;
return V_112 ;
}
if ( F_90 ( V_2 ) ) {
F_15 ( V_31
L_14 , V_26 ) ;
V_105 |= V_113 ;
}
V_4 = F_3 ( V_94 ) ;
if ( ! ( V_27 & V_114 ) && ! F_91 ( V_94 ) && V_4 &&
F_92 ( V_4 ) ) {
if ( F_93 ( V_94 ) ) {
F_94 ( V_94 ) ;
} else {
V_109 = 0 ;
V_105 |= V_113 ;
F_15 ( V_47
L_15 ,
V_26 ) ;
}
}
V_110 = V_94 ;
if ( F_95 ( V_94 ) ) {
if ( ! F_87 ( V_94 ) && F_59 ( V_94 ) ) {
if ( F_96 ( F_97 ( V_94 ) ) ) {
F_15 ( V_47
L_16 , V_26 ) ;
F_98 ( ! F_99 ( V_2 ) ) ;
return V_112 ;
}
if ( V_94 != V_2 ) {
if ( ! ( V_27 & V_115 ) ) {
F_100 ( V_94 ) ;
F_101 ( V_2 ) ;
}
F_102 ( V_2 ) ;
F_103 ( V_94 ) ;
* V_103 = V_2 ;
}
V_110 = V_2 ;
}
}
if ( V_109 )
F_58 ( V_110 , & V_83 , V_27 & V_41 ) ;
V_30 = F_104 ( V_110 , V_105 ) ;
if ( V_30 != V_111 )
F_15 ( V_31 L_17 ,
V_26 , F_105 ( V_110 ) ) ;
V_67 = F_91 ( V_110 ) || ( V_27 & V_114 ) ;
F_37 ( & V_83 , V_67 , V_25 ,
V_30 != V_111 , V_2 , V_26 , V_27 ) ;
return V_30 ;
}
static void F_106 ( struct V_1 * V_94 )
{
int V_116 ;
int V_117 = 1 << F_17 ( V_94 ) ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ )
F_107 ( V_94 + V_116 ) ;
}
static void F_108 ( struct V_1 * V_94 )
{
int V_116 ;
int V_117 = 1 << F_17 ( V_94 ) ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ )
F_109 ( V_94 + V_116 ) ;
}
int F_110 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_98 * V_99 ;
struct V_1 * V_2 ;
struct V_1 * V_94 ;
int V_93 ;
unsigned int V_117 ;
unsigned long V_118 ;
if ( ! V_119 )
F_111 ( L_18 , V_25 , V_26 ) ;
if ( ! F_112 ( V_26 ) ) {
F_15 ( V_31
L_19 ,
V_26 ) ;
return - V_120 ;
}
V_2 = F_113 ( V_26 ) ;
V_94 = F_18 ( V_2 ) ;
if ( F_114 ( V_2 ) ) {
F_15 ( V_31 L_20 , V_26 ) ;
return 0 ;
}
if ( F_87 ( V_2 ) )
V_117 = 1 << F_17 ( V_94 ) ;
else
V_117 = 1 ;
F_115 ( V_117 , & V_121 ) ;
if ( ! ( V_27 & V_115 ) &&
! F_116 ( V_94 ) ) {
if ( F_25 ( V_2 ) ) {
F_81 ( V_26 , L_21 , V_92 ) ;
return 0 ;
} else if ( F_87 ( V_94 ) ) {
F_102 ( V_94 ) ;
if ( F_99 ( V_94 ) ) {
if ( ( F_13 ( V_2 ) && F_117 ( V_2 ) )
|| ( V_2 != V_94 && F_114 ( V_94 ) ) ) {
F_118 ( V_117 , & V_121 ) ;
F_103 ( V_94 ) ;
return 0 ;
}
}
F_106 ( V_94 ) ;
V_93 = F_80 ( V_94 ) ;
F_81 ( V_26 , L_22 ,
V_93 ? V_86 : V_92 ) ;
F_103 ( V_94 ) ;
return V_93 ;
} else {
F_81 ( V_26 , L_23 , V_86 ) ;
return - V_102 ;
}
}
if ( ! F_87 ( V_2 ) && ! F_119 ( V_2 ) ) {
if ( ! F_23 ( V_2 ) )
F_21 ( V_2 , 0 ) ;
if ( ! F_23 ( V_2 ) ) {
if ( F_25 ( V_2 ) ) {
if ( V_27 & V_115 )
F_81 ( V_26 , L_21 , V_92 ) ;
else
F_81 ( V_26 , L_24 , V_92 ) ;
return 0 ;
}
}
}
F_102 ( V_94 ) ;
if ( F_18 ( V_2 ) != V_94 ) {
F_81 ( V_26 , L_25 , V_86 ) ;
V_93 = - V_102 ;
goto V_122;
}
V_118 = V_2 -> V_27 ;
if ( ! F_99 ( V_2 ) ) {
F_15 ( V_31 L_26 , V_26 ) ;
F_118 ( V_117 , & V_121 ) ;
F_100 ( V_94 ) ;
V_93 = 0 ;
goto V_122;
}
if ( F_13 ( V_2 ) ) {
if ( F_117 ( V_2 ) )
F_118 ( V_117 , & V_121 ) ;
F_103 ( V_94 ) ;
F_100 ( V_94 ) ;
return 0 ;
}
if ( ! F_87 ( V_2 ) && ! F_119 ( V_2 ) && ! F_23 ( V_2 ) )
goto V_123;
if ( F_87 ( V_2 ) && F_120 ( V_2 ) && F_114 ( V_94 ) ) {
F_81 ( V_26 , L_27 ,
V_86 ) ;
F_103 ( V_94 ) ;
F_100 ( V_94 ) ;
return 0 ;
}
if ( F_87 ( V_2 ) )
F_106 ( V_94 ) ;
F_121 ( V_2 ) ;
if ( F_84 ( V_2 , V_26 , V_25 , V_27 , & V_94 )
!= V_111 ) {
F_81 ( V_26 , L_28 , V_86 ) ;
V_93 = - V_102 ;
goto V_122;
}
if ( F_23 ( V_2 ) && ! F_90 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_81 ( V_26 , L_29 , V_86 ) ;
V_93 = - V_102 ;
goto V_122;
}
V_123:
V_93 = - V_102 ;
for ( V_99 = V_124 ; ; V_99 ++ )
if ( ( V_2 -> V_27 & V_99 -> V_125 ) == V_99 -> V_93 )
break;
V_118 |= ( V_2 -> V_27 & ( 1UL << V_126 ) ) ;
if ( ! V_99 -> V_125 )
for ( V_99 = V_124 ; ; V_99 ++ )
if ( ( V_118 & V_99 -> V_125 ) == V_99 -> V_93 )
break;
V_93 = F_83 ( V_99 , V_2 , V_26 ) ;
V_122:
F_103 ( V_94 ) ;
return V_93 ;
}
void F_122 ( unsigned long V_26 , int V_25 , int V_27 )
{
struct V_127 * V_128 ;
unsigned long V_129 ;
struct V_130 V_131 = {
. V_26 = V_26 ,
. V_25 = V_25 ,
. V_27 = V_27 ,
} ;
V_128 = & F_123 ( V_127 ) ;
F_124 ( & V_128 -> V_132 , V_129 ) ;
if ( F_125 ( & V_128 -> V_133 , V_131 ) )
F_126 ( F_127 () , & V_128 -> V_134 ) ;
else
F_82 ( L_30 ,
V_26 ) ;
F_128 ( & V_128 -> V_132 , V_129 ) ;
F_129 ( V_127 ) ;
}
static void F_130 ( struct V_135 * V_134 )
{
struct V_127 * V_128 ;
struct V_130 V_131 = { 0 , } ;
unsigned long V_129 ;
int V_136 ;
V_128 = F_131 ( & V_127 ) ;
for (; ; ) {
F_124 ( & V_128 -> V_132 , V_129 ) ;
V_136 = F_132 ( & V_128 -> V_133 , & V_131 ) ;
F_128 ( & V_128 -> V_132 , V_129 ) ;
if ( ! V_136 )
break;
if ( V_131 . V_27 & V_137 )
F_133 ( F_113 ( V_131 . V_26 ) , V_131 . V_27 ) ;
else
F_110 ( V_131 . V_26 , V_131 . V_25 , V_131 . V_27 ) ;
}
}
static int T_3 F_134 ( void )
{
struct V_127 * V_128 ;
int V_138 ;
F_135 (cpu) {
V_128 = & F_136 ( V_127 , V_138 ) ;
F_137 ( & V_128 -> V_132 ) ;
F_138 ( V_128 -> V_133 ) ;
F_139 ( & V_128 -> V_134 , F_130 ) ;
}
return 0 ;
}
int F_140 ( unsigned long V_26 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_139 = 0 ;
unsigned int V_117 ;
if ( ! F_112 ( V_26 ) )
return - V_120 ;
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
V_117 = 1 << F_17 ( V_1 ) ;
if ( ! F_116 ( V_1 ) ) {
if ( F_87 ( V_1 ) ) {
F_33 ( L_33 , V_26 ) ;
return 0 ;
}
if ( F_117 ( V_2 ) )
F_141 ( & V_121 ) ;
F_33 ( L_34 , V_26 ) ;
return 0 ;
}
F_102 ( V_1 ) ;
if ( F_117 ( V_1 ) ) {
F_33 ( L_35 , V_26 ) ;
F_118 ( V_117 , & V_121 ) ;
V_139 = 1 ;
if ( F_87 ( V_1 ) )
F_108 ( V_1 ) ;
}
F_103 ( V_1 ) ;
F_100 ( V_1 ) ;
if ( V_139 && ! ( V_26 == F_142 ( 0 ) && F_29 ( V_2 ) == 1 ) )
F_100 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_143 ( struct V_1 * V_2 , unsigned long V_140 , int * * V_141 )
{
int V_50 = F_26 ( V_2 ) ;
if ( F_87 ( V_2 ) )
return F_144 ( F_145 ( F_18 ( V_2 ) ) ,
V_50 ) ;
else
return F_146 ( V_50 , V_142 , 0 ) ;
}
static int F_147 ( struct V_1 * V_2 , unsigned long V_26 , int V_27 )
{
int V_30 ;
if ( V_27 & V_115 )
return 1 ;
if ( ! F_116 ( F_18 ( V_2 ) ) ) {
if ( F_87 ( V_2 ) ) {
F_33 ( L_36 , V_143 , V_26 ) ;
V_30 = 0 ;
} else if ( F_25 ( V_2 ) ) {
F_33 ( L_37 , V_143 , V_26 ) ;
V_30 = 0 ;
} else {
F_33 ( L_38 ,
V_143 , V_26 , V_2 -> V_27 ) ;
V_30 = - V_85 ;
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
return - V_85 ;
}
}
return V_30 ;
}
static int F_149 ( struct V_1 * V_1 , int V_27 )
{
int V_30 ;
unsigned long V_26 = F_34 ( V_1 ) ;
struct V_1 * V_94 = F_18 ( V_1 ) ;
F_85 ( V_144 ) ;
F_102 ( V_94 ) ;
if ( F_99 ( V_94 ) ) {
F_103 ( V_94 ) ;
F_100 ( V_94 ) ;
F_33 ( L_40 , V_26 ) ;
return - V_102 ;
}
F_103 ( V_94 ) ;
F_150 ( & V_94 -> V_145 , & V_144 ) ;
V_30 = F_151 ( & V_144 , F_143 , NULL , V_146 ,
V_147 , V_148 ) ;
if ( V_30 ) {
F_33 ( L_41 ,
V_26 , V_30 , V_1 -> V_27 ) ;
F_152 ( V_94 ) ;
if ( V_30 > 0 )
V_30 = - V_85 ;
} else {
if ( F_87 ( V_1 ) ) {
F_106 ( V_94 ) ;
F_80 ( V_94 ) ;
F_115 ( 1 << F_17 ( V_94 ) ,
& V_121 ) ;
} else {
F_107 ( V_1 ) ;
F_153 ( & V_121 ) ;
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
return - V_102 ;
}
V_30 = F_70 ( V_1 ) ;
F_103 ( V_1 ) ;
if ( V_30 == 1 ) {
F_100 ( V_1 ) ;
F_33 ( L_43 , V_26 ) ;
F_107 ( V_1 ) ;
F_153 ( & V_121 ) ;
return 0 ;
}
V_30 = F_61 ( V_1 ) ;
F_100 ( V_1 ) ;
if ( ! V_30 ) {
F_85 ( V_144 ) ;
F_155 ( V_1 , V_149 +
F_156 ( V_1 ) ) ;
F_157 ( & V_1 -> V_145 , & V_144 ) ;
V_30 = F_151 ( & V_144 , F_143 , NULL , V_146 ,
V_147 , V_148 ) ;
if ( V_30 ) {
if ( ! F_158 ( & V_144 ) ) {
F_159 ( & V_1 -> V_145 ) ;
F_160 ( V_1 , V_149 +
F_156 ( V_1 ) ) ;
F_161 ( V_1 ) ;
}
F_33 ( L_41 ,
V_26 , V_30 , V_1 -> V_27 ) ;
if ( V_30 > 0 )
V_30 = - V_85 ;
} else {
if ( ! F_25 ( V_1 ) )
F_22 () ;
if ( ! F_25 ( V_1 ) )
F_24 () ;
F_107 ( V_1 ) ;
if ( ! F_25 ( V_1 ) )
F_33 ( L_44 ,
V_26 ) ;
F_153 ( & V_121 ) ;
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
struct V_1 * V_94 = F_18 ( V_1 ) ;
if ( F_99 ( V_1 ) ) {
F_33 ( L_42 , V_26 ) ;
return - V_102 ;
}
if ( ! F_87 ( V_1 ) && F_95 ( V_94 ) ) {
if ( F_59 ( V_94 ) && F_96 ( F_97 ( V_94 ) ) ) {
F_33 ( L_46 ,
V_26 ) ;
return - V_102 ;
}
}
F_162 () ;
if ( F_163 ( V_1 ) != V_150 )
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
F_106 ( V_94 ) ;
F_80 ( V_94 ) ;
F_115 ( 1 << F_17 ( V_94 ) ,
& V_121 ) ;
} else {
F_107 ( V_1 ) ;
F_153 ( & V_121 ) ;
}
}
F_166 ( V_1 , V_151 ) ;
return V_30 ;
}
