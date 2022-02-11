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
if ( ! V_17 -> V_20 -> V_21 )
return - V_8 ;
V_18 = V_17 -> V_20 -> V_21 -> V_22 -> V_23 ;
F_11 ( V_17 ) ;
if ( V_18 != V_19 )
return - V_8 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ) { return 0 ; }
int F_12 ( struct V_1 * V_2 )
{
if ( ! V_24 )
return 0 ;
if ( F_1 ( V_2 ) )
return - V_8 ;
if ( F_6 ( V_2 ) )
return - V_8 ;
if ( F_8 ( V_2 ) )
return - V_8 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_13 ( struct V_25 * V_26 , unsigned long V_27 , int V_28 ,
unsigned long V_29 , struct V_1 * V_1 )
{
struct V_30 V_31 ;
int V_32 ;
F_14 ( V_33
L_1 ,
V_29 , V_26 -> V_34 , V_26 -> V_35 ) ;
V_31 . V_36 = V_37 ;
V_31 . V_38 = 0 ;
V_31 . V_39 = V_40 ;
V_31 . V_41 = ( void * ) V_27 ;
#ifdef F_15
V_31 . V_42 = V_28 ;
#endif
V_31 . V_43 = F_16 ( F_17 ( V_1 ) ) + V_44 ;
V_32 = F_18 ( V_37 , & V_31 , V_26 ) ;
if ( V_32 < 0 )
F_14 ( V_45 L_2 ,
V_26 -> V_34 , V_26 -> V_35 , V_32 ) ;
return V_32 ;
}
void F_19 ( struct V_1 * V_2 , int V_46 )
{
if ( ! F_2 ( V_2 ) ) {
F_20 () ;
if ( F_21 ( V_2 ) )
return;
F_22 () ;
if ( F_21 ( V_2 ) || F_23 ( V_2 ) )
return;
}
if ( V_46 ) {
int V_47 ;
do {
struct V_48 V_49 = {
. V_50 = V_51 ,
} ;
V_47 = F_24 ( & V_49 , 1000 , 1000 ) ;
if ( F_25 ( V_2 ) == 1 )
break;
} while ( V_47 > 10 );
}
}
static void F_26 ( struct V_25 * V_52 , struct V_1 * V_2 ,
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_56 * * V_57 )
{
struct V_56 * V_58 ;
if ( * V_57 ) {
V_58 = * V_57 ;
* V_57 = NULL ;
} else {
V_58 = F_27 ( sizeof( struct V_56 ) , V_59 ) ;
if ( ! V_58 ) {
F_14 ( V_33
L_3 ) ;
return;
}
}
V_58 -> V_27 = F_28 ( V_2 , V_54 ) ;
V_58 -> V_60 = 1 ;
if ( V_58 -> V_27 == - V_61 ) {
F_29 ( L_4 ,
F_30 ( V_2 ) , V_52 -> V_34 ) ;
V_58 -> V_60 = 0 ;
}
F_31 ( V_52 ) ;
V_58 -> V_52 = V_52 ;
F_32 ( & V_58 -> V_62 , V_56 ) ;
}
static void F_33 ( struct V_55 * V_56 , int V_63 , int V_28 ,
int V_64 , struct V_1 * V_1 , unsigned long V_29 )
{
struct V_56 * V_58 , * V_65 ;
F_34 (tk, next, to_kill, nd) {
if ( V_63 ) {
if ( V_64 || V_58 -> V_60 == 0 ) {
F_14 ( V_33
L_5 ,
V_29 , V_58 -> V_52 -> V_34 , V_58 -> V_52 -> V_35 ) ;
F_35 ( V_66 , V_58 -> V_52 ) ;
}
else if ( F_13 ( V_58 -> V_52 , V_58 -> V_27 , V_28 ,
V_29 , V_1 ) < 0 )
F_14 ( V_33
L_6 ,
V_29 , V_58 -> V_52 -> V_34 , V_58 -> V_52 -> V_35 ) ;
}
F_36 ( V_58 -> V_52 ) ;
F_37 ( V_58 ) ;
}
}
static int F_38 ( struct V_25 * V_52 )
{
if ( ! V_52 -> V_67 )
return 0 ;
if ( V_52 -> V_68 & V_69 )
return ! ! ( V_52 -> V_68 & V_70 ) ;
return V_71 ;
}
static void F_39 ( struct V_1 * V_1 , struct V_55 * V_56 ,
struct V_56 * * V_57 )
{
struct V_53 * V_54 ;
struct V_25 * V_52 ;
struct V_72 * V_73 ;
V_73 = F_40 ( V_1 ) ;
if ( V_73 == NULL )
return;
F_41 ( & V_74 ) ;
F_42 (tsk) {
struct V_75 * V_76 ;
if ( ! F_38 ( V_52 ) )
continue;
F_43 (vmac, &av->head, same_anon_vma) {
V_54 = V_76 -> V_54 ;
if ( ! F_44 ( V_1 , V_54 ) )
continue;
if ( V_54 -> V_77 == V_52 -> V_67 )
F_26 ( V_52 , V_1 , V_54 , V_56 , V_57 ) ;
}
}
F_45 ( & V_74 ) ;
F_46 ( V_73 ) ;
}
static void F_47 ( struct V_1 * V_1 , struct V_55 * V_56 ,
struct V_56 * * V_57 )
{
struct V_53 * V_54 ;
struct V_25 * V_52 ;
struct V_78 V_79 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_48 ( & V_4 -> V_80 ) ;
F_41 ( & V_74 ) ;
F_42 (tsk) {
T_2 V_81 = V_1 -> V_82 << ( V_83 - V_44 ) ;
if ( ! F_38 ( V_52 ) )
continue;
F_49 (vma, &iter, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_54 -> V_77 == V_52 -> V_67 )
F_26 ( V_52 , V_1 , V_54 , V_56 , V_57 ) ;
}
}
F_45 ( & V_74 ) ;
F_50 ( & V_4 -> V_80 ) ;
}
static void F_51 ( struct V_1 * V_1 , struct V_55 * V_84 )
{
struct V_56 * V_58 ;
if ( ! V_1 -> V_4 )
return;
V_58 = F_27 ( sizeof( struct V_56 ) , V_85 ) ;
if ( ! V_58 )
return;
if ( F_52 ( V_1 ) )
F_39 ( V_1 , V_84 , & V_58 ) ;
else
F_47 ( V_1 , V_84 , & V_58 ) ;
F_37 ( V_58 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( ! F_54 ( V_2 ) ) {
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
return - V_86 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned long V_29 )
{
return V_87 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_14 ( V_33 L_7 , V_29 ) ;
return V_88 ;
}
static int F_60 ( struct V_1 * V_2 , unsigned long V_29 )
{
int V_89 ;
int V_32 = V_88 ;
struct V_3 * V_4 ;
F_53 ( V_2 ) ;
if ( F_52 ( V_2 ) )
return V_90 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_88 ;
}
if ( V_4 -> V_91 -> V_92 ) {
V_89 = V_4 -> V_91 -> V_92 ( V_4 , V_2 ) ;
if ( V_89 != 0 ) {
F_14 ( V_45 L_8 ,
V_29 , V_89 ) ;
} else if ( F_61 ( V_2 ) &&
! F_62 ( V_2 , V_85 ) ) {
F_29 ( L_9 , V_29 ) ;
} else {
V_32 = V_90 ;
}
} else {
if ( F_63 ( V_2 ) )
V_32 = V_90 ;
else
F_14 ( V_45 L_10 ,
V_29 ) ;
}
return V_32 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_4 ) {
F_66 ( V_4 , V_86 ) ;
}
return F_60 ( V_2 , V_29 ) ;
}
static int F_67 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
if ( ! F_53 ( V_2 ) )
return V_93 ;
else
return V_88 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_71 ( V_2 ) ;
if ( ! F_53 ( V_2 ) )
return V_90 ;
else
return V_88 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned long V_29 )
{
int V_94 = 0 ;
struct V_1 * V_95 = F_17 ( V_2 ) ;
if ( ! ( F_3 ( V_95 ) || F_52 ( V_95 ) ) ) {
V_94 = F_73 ( V_95 ) ;
if ( ! V_94 )
return V_90 ;
}
return V_93 ;
}
static void F_74 ( unsigned long V_29 , char * V_96 , int V_97 )
{
struct V_1 * V_1 = F_75 ( V_29 ) ;
F_14 ( V_33 L_11 ,
V_29 ,
F_76 ( V_1 ) ? L_12 : L_13 ,
V_96 , V_98 [ V_97 ] ) ;
}
static int F_77 ( struct V_99 * V_100 , struct V_1 * V_2 ,
unsigned long V_29 )
{
int V_97 ;
int V_101 ;
V_97 = V_100 -> V_102 ( V_2 , V_29 ) ;
F_74 ( V_29 , V_100 -> V_96 , V_97 ) ;
V_101 = F_25 ( V_2 ) - 1 ;
if ( V_100 -> V_102 == F_67 && V_97 == V_93 )
V_101 -- ;
if ( V_101 != 0 ) {
F_14 ( V_33
L_14 ,
V_29 , V_100 -> V_96 , V_101 ) ;
V_97 = V_88 ;
}
return ( V_97 == V_90 || V_97 == V_93 ) ? 0 : - V_103 ;
}
static int F_78 ( struct V_1 * V_2 , unsigned long V_29 ,
int V_28 )
{
enum V_104 V_105 = V_106 | V_107 | V_108 ;
struct V_3 * V_4 ;
F_79 ( V_84 ) ;
int V_32 ;
int V_109 = 1 ;
struct V_1 * V_95 = F_17 ( V_2 ) ;
struct V_1 * V_110 ;
if ( F_80 ( V_2 ) || F_2 ( V_2 ) )
return V_111 ;
if ( ! F_81 ( V_95 ) )
return V_111 ;
if ( F_82 ( V_2 ) )
return V_112 ;
if ( F_83 ( V_2 ) ) {
F_14 ( V_33
L_15 , V_29 ) ;
V_105 |= V_113 ;
}
V_4 = F_3 ( V_95 ) ;
if ( ! F_76 ( V_95 ) && V_4 &&
F_84 ( V_4 ) ) {
if ( F_85 ( V_95 ) ) {
F_86 ( V_95 ) ;
} else {
V_109 = 0 ;
V_105 |= V_113 ;
F_14 ( V_45
L_16 ,
V_29 ) ;
}
}
V_110 = V_95 ;
if ( F_87 ( V_95 ) ) {
if ( ! F_88 ( V_95 ) && F_52 ( V_95 ) ) {
if ( F_89 ( F_90 ( V_95 ) ) ) {
F_14 ( V_45
L_17 , V_29 ) ;
F_91 ( ! F_92 ( V_2 ) ) ;
return V_112 ;
}
V_110 = V_2 ;
}
}
if ( V_109 )
F_51 ( V_110 , & V_84 ) ;
if ( V_95 != V_110 )
F_93 ( V_110 ) ;
V_32 = F_94 ( V_110 , V_105 ) ;
if ( V_32 != V_111 )
F_14 ( V_33 L_18 ,
V_29 , F_95 ( V_110 ) ) ;
if ( V_95 != V_110 )
F_96 ( V_110 ) ;
F_33 ( & V_84 , ! ! F_76 ( V_110 ) , V_28 ,
V_32 != V_111 , V_2 , V_29 ) ;
return V_32 ;
}
static void F_97 ( struct V_1 * V_95 )
{
int V_114 ;
int V_115 = 1 << F_16 ( V_95 ) ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
F_98 ( V_95 + V_114 ) ;
}
static void F_99 ( struct V_1 * V_95 )
{
int V_114 ;
int V_115 = 1 << F_16 ( V_95 ) ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
F_100 ( V_95 + V_114 ) ;
}
int F_101 ( unsigned long V_29 , int V_28 , int V_68 )
{
struct V_99 * V_100 ;
struct V_1 * V_2 ;
struct V_1 * V_95 ;
int V_94 ;
unsigned int V_115 ;
if ( ! V_116 )
F_102 ( L_19 , V_28 , V_29 ) ;
if ( ! F_103 ( V_29 ) ) {
F_14 ( V_33
L_20 ,
V_29 ) ;
return - V_117 ;
}
V_2 = F_75 ( V_29 ) ;
V_95 = F_17 ( V_2 ) ;
if ( F_104 ( V_2 ) ) {
F_14 ( V_33 L_21 , V_29 ) ;
return 0 ;
}
V_115 = 1 << F_16 ( V_95 ) ;
F_105 ( V_115 , & V_118 ) ;
if ( ! ( V_68 & V_119 ) &&
! F_106 ( V_95 ) ) {
if ( F_23 ( V_2 ) ) {
F_74 ( V_29 , L_22 , V_93 ) ;
return 0 ;
} else if ( F_88 ( V_95 ) ) {
F_93 ( V_95 ) ;
if ( ! F_92 ( V_95 )
|| ( F_12 ( V_2 ) && F_107 ( V_2 ) )
|| ( V_2 != V_95 && F_104 ( V_95 ) ) ) {
F_108 ( V_115 , & V_118 ) ;
return 0 ;
}
F_97 ( V_95 ) ;
V_94 = F_73 ( V_95 ) ;
F_74 ( V_29 , L_23 ,
V_94 ? V_87 : V_93 ) ;
F_96 ( V_95 ) ;
return V_94 ;
} else {
F_74 ( V_29 , L_24 , V_87 ) ;
return - V_103 ;
}
}
if ( ! F_88 ( V_2 ) && ! F_109 ( V_2 ) ) {
if ( ! F_21 ( V_2 ) )
F_19 ( V_2 , 0 ) ;
if ( ! F_21 ( V_2 ) ) {
if ( F_23 ( V_2 ) ) {
F_74 ( V_29 , L_25 ,
V_93 ) ;
return 0 ;
}
F_74 ( V_29 , L_26 , V_87 ) ;
F_110 ( V_2 ) ;
return - V_103 ;
}
}
F_93 ( V_95 ) ;
if ( ! F_92 ( V_2 ) ) {
F_14 ( V_33 L_27 , V_29 ) ;
V_94 = 0 ;
goto V_120;
}
if ( F_12 ( V_2 ) ) {
if ( F_107 ( V_2 ) )
F_108 ( V_115 , & V_118 ) ;
F_96 ( V_95 ) ;
F_110 ( V_95 ) ;
return 0 ;
}
if ( F_88 ( V_2 ) && F_111 ( V_2 ) && F_104 ( V_95 ) ) {
F_74 ( V_29 , L_28 ,
V_87 ) ;
F_96 ( V_95 ) ;
F_110 ( V_95 ) ;
return 0 ;
}
if ( F_88 ( V_2 ) )
F_97 ( V_95 ) ;
F_112 ( V_2 ) ;
if ( F_78 ( V_2 , V_29 , V_28 ) != V_111 ) {
F_14 ( V_33 L_29 , V_29 ) ;
V_94 = - V_103 ;
goto V_120;
}
if ( F_21 ( V_2 ) && ! F_83 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_74 ( V_29 , L_30 , V_87 ) ;
V_94 = - V_103 ;
goto V_120;
}
V_94 = - V_103 ;
for ( V_100 = V_121 ; ; V_100 ++ ) {
if ( ( V_2 -> V_68 & V_100 -> V_122 ) == V_100 -> V_94 ) {
V_94 = F_77 ( V_100 , V_2 , V_29 ) ;
break;
}
}
V_120:
F_96 ( V_95 ) ;
return V_94 ;
}
void F_113 ( unsigned long V_29 , int V_28 )
{
F_101 ( V_29 , V_28 , 0 ) ;
}
void F_114 ( unsigned long V_29 , int V_28 , int V_68 )
{
struct V_123 * V_124 ;
unsigned long V_125 ;
struct V_126 V_127 = {
. V_29 = V_29 ,
. V_28 = V_28 ,
. V_68 = V_68 ,
} ;
V_124 = & F_115 ( V_123 ) ;
F_116 ( & V_124 -> V_128 , V_125 ) ;
if ( F_117 ( & V_124 -> V_129 , & V_127 ) )
F_118 ( F_119 () , & V_124 -> V_130 ) ;
else
F_120 ( L_31 ,
V_29 ) ;
F_121 ( & V_124 -> V_128 , V_125 ) ;
F_122 ( V_123 ) ;
}
static void F_123 ( struct V_131 * V_130 )
{
struct V_123 * V_124 ;
struct V_126 V_127 = { 0 , } ;
unsigned long V_125 ;
int V_132 ;
V_124 = & F_124 ( V_123 ) ;
for (; ; ) {
F_116 ( & V_124 -> V_128 , V_125 ) ;
V_132 = F_125 ( & V_124 -> V_129 , & V_127 ) ;
F_121 ( & V_124 -> V_128 , V_125 ) ;
if ( ! V_132 )
break;
F_101 ( V_127 . V_29 , V_127 . V_28 , V_127 . V_68 ) ;
}
}
static int T_3 F_126 ( void )
{
struct V_123 * V_124 ;
int V_133 ;
F_127 (cpu) {
V_124 = & F_128 ( V_123 , V_133 ) ;
F_129 ( & V_124 -> V_128 ) ;
F_130 ( V_124 -> V_129 ) ;
F_131 ( & V_124 -> V_130 , F_123 ) ;
}
return 0 ;
}
int F_132 ( unsigned long V_29 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_134 = 0 ;
unsigned int V_115 ;
if ( ! F_103 ( V_29 ) )
return - V_117 ;
V_2 = F_75 ( V_29 ) ;
V_1 = F_17 ( V_2 ) ;
if ( ! F_92 ( V_2 ) ) {
F_29 ( L_32 , V_29 ) ;
return 0 ;
}
V_115 = 1 << F_16 ( V_1 ) ;
if ( ! F_106 ( V_1 ) ) {
if ( F_88 ( V_1 ) ) {
F_133 ( L_33 , V_29 ) ;
return 0 ;
}
if ( F_107 ( V_2 ) )
F_108 ( V_115 , & V_118 ) ;
F_29 ( L_34 , V_29 ) ;
return 0 ;
}
F_93 ( V_1 ) ;
if ( F_107 ( V_1 ) ) {
F_29 ( L_35 , V_29 ) ;
F_108 ( V_115 , & V_118 ) ;
V_134 = 1 ;
if ( F_88 ( V_1 ) )
F_99 ( V_1 ) ;
}
F_96 ( V_1 ) ;
F_110 ( V_1 ) ;
if ( V_134 )
F_110 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_134 ( struct V_1 * V_2 , unsigned long V_135 , int * * V_136 )
{
int V_137 = F_135 ( V_2 ) ;
if ( F_88 ( V_2 ) )
return F_136 ( F_137 ( F_17 ( V_2 ) ) ,
V_137 ) ;
else
return F_138 ( V_137 , V_138 , 0 ) ;
}
static int F_139 ( struct V_1 * V_2 , unsigned long V_29 , int V_68 )
{
int V_32 ;
if ( V_68 & V_119 )
return 1 ;
F_140 () ;
F_141 ( V_2 ) ;
if ( ! F_106 ( F_17 ( V_2 ) ) ) {
if ( F_88 ( V_2 ) ) {
F_29 ( L_36 , V_29 ) ;
V_32 = F_73 ( F_17 ( V_2 ) ) ;
} else if ( F_23 ( V_2 ) ) {
F_29 ( L_37 , V_29 ) ;
F_98 ( V_2 ) ;
V_32 = 0 ;
} else {
F_29 ( L_38 ,
V_29 , V_2 -> V_68 ) ;
V_32 = - V_86 ;
}
} else {
V_32 = 1 ;
}
F_142 ( V_2 ) ;
F_143 () ;
return V_32 ;
}
static int F_144 ( struct V_1 * V_1 , int V_68 )
{
int V_32 ;
unsigned long V_29 = F_30 ( V_1 ) ;
struct V_1 * V_95 = F_17 ( V_1 ) ;
F_79 ( V_139 ) ;
V_32 = F_139 ( V_1 , V_29 , V_68 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 )
goto V_140;
if ( F_92 ( V_95 ) ) {
F_110 ( V_95 ) ;
F_133 ( L_39 , V_29 ) ;
return - V_103 ;
}
F_145 ( & V_95 -> V_141 , & V_139 ) ;
V_32 = F_146 ( & V_139 , F_134 , V_142 , 0 ,
true ) ;
if ( V_32 ) {
struct V_1 * V_143 , * V_144 ;
F_34 (page1, page2, &pagelist, lru)
F_110 ( V_143 ) ;
F_133 ( L_40 ,
V_29 , V_32 , V_1 -> V_68 ) ;
if ( V_32 > 0 )
V_32 = - V_86 ;
return V_32 ;
}
V_140:
if ( ! F_92 ( V_95 ) )
F_105 ( 1 << F_16 ( V_95 ) , & V_118 ) ;
F_97 ( V_95 ) ;
F_73 ( V_95 ) ;
return V_32 ;
}
int F_147 ( struct V_1 * V_1 , int V_68 )
{
int V_32 ;
unsigned long V_29 = F_30 ( V_1 ) ;
if ( F_88 ( V_1 ) )
return F_144 ( V_1 , V_68 ) ;
V_32 = F_139 ( V_1 , V_29 , V_68 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 )
goto V_140;
if ( ! F_21 ( V_1 ) ) {
F_110 ( V_1 ) ;
F_19 ( V_1 , 1 ) ;
V_32 = F_139 ( V_1 , V_29 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == 0 )
goto V_140;
}
if ( ! F_21 ( V_1 ) ) {
F_29 ( L_41 ,
V_29 , V_1 -> V_68 ) ;
return - V_86 ;
}
F_93 ( V_1 ) ;
F_112 ( V_1 ) ;
if ( F_92 ( V_1 ) ) {
F_96 ( V_1 ) ;
F_110 ( V_1 ) ;
F_29 ( L_42 , V_29 ) ;
return - V_103 ;
}
V_32 = F_63 ( V_1 ) ;
F_96 ( V_1 ) ;
if ( V_32 == 1 ) {
F_110 ( V_1 ) ;
V_32 = 0 ;
F_29 ( L_43 , V_29 ) ;
goto V_140;
}
V_32 = F_54 ( V_1 ) ;
F_110 ( V_1 ) ;
if ( ! V_32 ) {
F_79 ( V_139 ) ;
F_148 ( V_1 , V_145 +
F_149 ( V_1 ) ) ;
F_145 ( & V_1 -> V_141 , & V_139 ) ;
V_32 = F_150 ( & V_139 , F_134 , V_142 ,
0 , true ) ;
if ( V_32 ) {
F_151 ( & V_139 ) ;
F_29 ( L_40 ,
V_29 , V_32 , V_1 -> V_68 ) ;
if ( V_32 > 0 )
V_32 = - V_86 ;
}
} else {
F_29 ( L_44 ,
V_29 , V_32 , F_25 ( V_1 ) , V_1 -> V_68 ) ;
}
if ( V_32 )
return V_32 ;
V_140:
F_105 ( 1 , & V_118 ) ;
F_98 ( V_1 ) ;
return V_32 ;
}
