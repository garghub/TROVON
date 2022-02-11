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
unsigned long V_29 , struct V_1 * V_1 , int V_30 )
{
struct V_31 V_32 ;
int V_33 ;
F_14 ( V_34
L_1 ,
V_29 , V_26 -> V_35 , V_26 -> V_36 ) ;
V_32 . V_37 = V_38 ;
V_32 . V_39 = 0 ;
V_32 . V_40 = ( void * ) V_27 ;
#ifdef F_15
V_32 . V_41 = V_28 ;
#endif
V_32 . V_42 = F_16 ( F_17 ( V_1 ) ) + V_43 ;
if ( ( V_30 & V_44 ) && V_26 == V_45 ) {
V_32 . V_46 = V_47 ;
V_33 = F_18 ( V_38 , & V_32 , V_26 ) ;
} else {
V_32 . V_46 = V_48 ;
V_33 = F_19 ( V_38 , & V_32 , V_26 ) ;
}
if ( V_33 < 0 )
F_14 ( V_49 L_2 ,
V_26 -> V_35 , V_26 -> V_36 , V_33 ) ;
return V_33 ;
}
void F_20 ( struct V_1 * V_2 , int V_50 )
{
if ( ! F_2 ( V_2 ) ) {
F_21 () ;
if ( F_22 ( V_2 ) )
return;
F_23 () ;
if ( F_22 ( V_2 ) || F_24 ( V_2 ) )
return;
}
if ( V_50 ) {
int V_51 ;
do {
struct V_52 V_53 = {
. V_54 = V_55 ,
} ;
V_51 = F_25 ( & V_53 , 1000 , 1000 ) ;
if ( F_26 ( V_2 ) == 1 )
break;
} while ( V_51 > 10 );
}
}
static void F_27 ( struct V_25 * V_56 , struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_60 * * V_61 )
{
struct V_60 * V_62 ;
if ( * V_61 ) {
V_62 = * V_61 ;
* V_61 = NULL ;
} else {
V_62 = F_28 ( sizeof( struct V_60 ) , V_63 ) ;
if ( ! V_62 ) {
F_14 ( V_34
L_3 ) ;
return;
}
}
V_62 -> V_27 = F_29 ( V_2 , V_58 ) ;
V_62 -> V_64 = 1 ;
if ( V_62 -> V_27 == - V_65 ) {
F_30 ( L_4 ,
F_31 ( V_2 ) , V_56 -> V_35 ) ;
V_62 -> V_64 = 0 ;
}
F_32 ( V_56 ) ;
V_62 -> V_56 = V_56 ;
F_33 ( & V_62 -> V_66 , V_60 ) ;
}
static void F_34 ( struct V_59 * V_60 , int V_67 , int V_28 ,
int V_68 , struct V_1 * V_1 , unsigned long V_29 ,
int V_30 )
{
struct V_60 * V_62 , * V_69 ;
F_35 (tk, next, to_kill, nd) {
if ( V_67 ) {
if ( V_68 || V_62 -> V_64 == 0 ) {
F_14 ( V_34
L_5 ,
V_29 , V_62 -> V_56 -> V_35 , V_62 -> V_56 -> V_36 ) ;
F_36 ( V_70 , V_62 -> V_56 ) ;
}
else if ( F_13 ( V_62 -> V_56 , V_62 -> V_27 , V_28 ,
V_29 , V_1 , V_30 ) < 0 )
F_14 ( V_34
L_6 ,
V_29 , V_62 -> V_56 -> V_35 , V_62 -> V_56 -> V_36 ) ;
}
F_37 ( V_62 -> V_56 ) ;
F_38 ( V_62 ) ;
}
}
static int F_39 ( struct V_25 * V_56 )
{
if ( ! V_56 -> V_71 )
return 0 ;
if ( V_56 -> V_30 & V_72 )
return ! ! ( V_56 -> V_30 & V_73 ) ;
return V_74 ;
}
static void F_40 ( struct V_1 * V_1 , struct V_59 * V_60 ,
struct V_60 * * V_61 )
{
struct V_57 * V_58 ;
struct V_25 * V_56 ;
struct V_75 * V_76 ;
V_76 = F_41 ( V_1 ) ;
if ( V_76 == NULL )
return;
F_42 ( & V_77 ) ;
F_43 (tsk) {
struct V_78 * V_79 ;
if ( ! F_39 ( V_56 ) )
continue;
F_44 (vmac, &av->head, same_anon_vma) {
V_58 = V_79 -> V_58 ;
if ( ! F_45 ( V_1 , V_58 ) )
continue;
if ( V_58 -> V_80 == V_56 -> V_71 )
F_27 ( V_56 , V_1 , V_58 , V_60 , V_61 ) ;
}
}
F_46 ( & V_77 ) ;
F_47 ( V_76 ) ;
}
static void F_48 ( struct V_1 * V_1 , struct V_59 * V_60 ,
struct V_60 * * V_61 )
{
struct V_57 * V_58 ;
struct V_25 * V_56 ;
struct V_81 V_82 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_49 ( & V_4 -> V_83 ) ;
F_42 ( & V_77 ) ;
F_43 (tsk) {
T_2 V_84 = V_1 -> V_85 << ( V_86 - V_43 ) ;
if ( ! F_39 ( V_56 ) )
continue;
F_50 (vma, &iter, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_58 -> V_80 == V_56 -> V_71 )
F_27 ( V_56 , V_1 , V_58 , V_60 , V_61 ) ;
}
}
F_46 ( & V_77 ) ;
F_51 ( & V_4 -> V_83 ) ;
}
static void F_52 ( struct V_1 * V_1 , struct V_59 * V_87 )
{
struct V_60 * V_62 ;
if ( ! V_1 -> V_4 )
return;
V_62 = F_28 ( sizeof( struct V_60 ) , V_88 ) ;
if ( ! V_62 )
return;
if ( F_53 ( V_1 ) )
F_40 ( V_1 , V_87 , & V_62 ) ;
else
F_48 ( V_1 , V_87 , & V_62 ) ;
F_38 ( V_62 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( ! F_55 ( V_2 ) ) {
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
return - V_89 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned long V_29 )
{
return V_90 ;
}
static int F_60 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_14 ( V_34 L_7 , V_29 ) ;
return V_91 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned long V_29 )
{
int V_92 ;
int V_33 = V_91 ;
struct V_3 * V_4 ;
F_54 ( V_2 ) ;
if ( F_53 ( V_2 ) )
return V_93 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_91 ;
}
if ( V_4 -> V_94 -> V_95 ) {
V_92 = V_4 -> V_94 -> V_95 ( V_4 , V_2 ) ;
if ( V_92 != 0 ) {
F_14 ( V_49 L_8 ,
V_29 , V_92 ) ;
} else if ( F_62 ( V_2 ) &&
! F_63 ( V_2 , V_88 ) ) {
F_30 ( L_9 , V_29 ) ;
} else {
V_33 = V_93 ;
}
} else {
if ( F_64 ( V_2 ) )
V_33 = V_93 ;
else
F_14 ( V_49 L_10 ,
V_29 ) ;
}
return V_33 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( V_4 ) {
F_67 ( V_4 , V_89 ) ;
}
return F_61 ( V_2 , V_29 ) ;
}
static int F_68 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
if ( ! F_54 ( V_2 ) )
return V_96 ;
else
return V_91 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_72 ( V_2 ) ;
if ( ! F_54 ( V_2 ) )
return V_93 ;
else
return V_91 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned long V_29 )
{
int V_97 = 0 ;
struct V_1 * V_98 = F_17 ( V_2 ) ;
if ( ! ( F_3 ( V_98 ) || F_53 ( V_98 ) ) ) {
V_97 = F_74 ( V_98 ) ;
if ( ! V_97 )
return V_93 ;
}
return V_96 ;
}
static void F_75 ( unsigned long V_29 , char * V_99 , int V_100 )
{
struct V_1 * V_1 = F_76 ( V_29 ) ;
F_14 ( V_34 L_11 ,
V_29 ,
F_77 ( V_1 ) ? L_12 : L_13 ,
V_99 , V_101 [ V_100 ] ) ;
}
static int F_78 ( struct V_102 * V_103 , struct V_1 * V_2 ,
unsigned long V_29 )
{
int V_100 ;
int V_104 ;
V_100 = V_103 -> V_105 ( V_2 , V_29 ) ;
F_75 ( V_29 , V_103 -> V_99 , V_100 ) ;
V_104 = F_26 ( V_2 ) - 1 ;
if ( V_103 -> V_105 == F_68 && V_100 == V_96 )
V_104 -- ;
if ( V_104 != 0 ) {
F_14 ( V_34
L_14 ,
V_29 , V_103 -> V_99 , V_104 ) ;
V_100 = V_91 ;
}
return ( V_100 == V_93 || V_100 == V_96 ) ? 0 : - V_106 ;
}
static int F_79 ( struct V_1 * V_2 , unsigned long V_29 ,
int V_28 , int V_30 )
{
enum V_107 V_108 = V_109 | V_110 | V_111 ;
struct V_3 * V_4 ;
F_80 ( V_87 ) ;
int V_33 ;
int V_112 = 1 , V_67 ;
struct V_1 * V_98 = F_17 ( V_2 ) ;
struct V_1 * V_113 ;
if ( F_81 ( V_2 ) || F_2 ( V_2 ) )
return V_114 ;
if ( ! F_82 ( V_98 ) )
return V_114 ;
if ( F_83 ( V_2 ) )
return V_115 ;
if ( F_84 ( V_2 ) ) {
F_14 ( V_34
L_15 , V_29 ) ;
V_108 |= V_116 ;
}
V_4 = F_3 ( V_98 ) ;
if ( ! ( V_30 & V_117 ) && ! F_77 ( V_98 ) && V_4 &&
F_85 ( V_4 ) ) {
if ( F_86 ( V_98 ) ) {
F_87 ( V_98 ) ;
} else {
V_112 = 0 ;
V_108 |= V_116 ;
F_14 ( V_49
L_16 ,
V_29 ) ;
}
}
V_113 = V_98 ;
if ( F_88 ( V_98 ) ) {
if ( ! F_89 ( V_98 ) && F_53 ( V_98 ) ) {
if ( F_90 ( F_91 ( V_98 ) ) ) {
F_14 ( V_49
L_17 , V_29 ) ;
F_92 ( ! F_93 ( V_2 ) ) ;
return V_115 ;
}
V_113 = V_2 ;
}
}
if ( V_112 )
F_52 ( V_113 , & V_87 ) ;
if ( V_98 != V_113 )
F_94 ( V_113 ) ;
V_33 = F_95 ( V_113 , V_108 ) ;
if ( V_33 != V_114 )
F_14 ( V_34 L_18 ,
V_29 , F_96 ( V_113 ) ) ;
if ( V_98 != V_113 )
F_97 ( V_113 ) ;
V_67 = F_77 ( V_113 ) || ( V_30 & V_117 ) ;
F_34 ( & V_87 , V_67 , V_28 ,
V_33 != V_114 , V_2 , V_29 , V_30 ) ;
return V_33 ;
}
static void F_98 ( struct V_1 * V_98 )
{
int V_118 ;
int V_119 = 1 << F_16 ( V_98 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
F_99 ( V_98 + V_118 ) ;
}
static void F_100 ( struct V_1 * V_98 )
{
int V_118 ;
int V_119 = 1 << F_16 ( V_98 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
F_101 ( V_98 + V_118 ) ;
}
int F_102 ( unsigned long V_29 , int V_28 , int V_30 )
{
struct V_102 * V_103 ;
struct V_1 * V_2 ;
struct V_1 * V_98 ;
int V_97 ;
unsigned int V_119 ;
if ( ! V_120 )
F_103 ( L_19 , V_28 , V_29 ) ;
if ( ! F_104 ( V_29 ) ) {
F_14 ( V_34
L_20 ,
V_29 ) ;
return - V_121 ;
}
V_2 = F_76 ( V_29 ) ;
V_98 = F_17 ( V_2 ) ;
if ( F_105 ( V_2 ) ) {
F_14 ( V_34 L_21 , V_29 ) ;
return 0 ;
}
V_119 = 1 << F_16 ( V_98 ) ;
F_106 ( V_119 , & V_122 ) ;
if ( ! ( V_30 & V_123 ) &&
! F_107 ( V_98 ) ) {
if ( F_24 ( V_2 ) ) {
F_75 ( V_29 , L_22 , V_96 ) ;
return 0 ;
} else if ( F_89 ( V_98 ) ) {
F_94 ( V_98 ) ;
if ( ! F_93 ( V_98 )
|| ( F_12 ( V_2 ) && F_108 ( V_2 ) )
|| ( V_2 != V_98 && F_105 ( V_98 ) ) ) {
F_109 ( V_119 , & V_122 ) ;
return 0 ;
}
F_98 ( V_98 ) ;
V_97 = F_74 ( V_98 ) ;
F_75 ( V_29 , L_23 ,
V_97 ? V_90 : V_96 ) ;
F_97 ( V_98 ) ;
return V_97 ;
} else {
F_75 ( V_29 , L_24 , V_90 ) ;
return - V_106 ;
}
}
if ( ! F_89 ( V_2 ) && ! F_110 ( V_2 ) ) {
if ( ! F_22 ( V_2 ) )
F_20 ( V_2 , 0 ) ;
if ( ! F_22 ( V_2 ) ) {
if ( F_24 ( V_2 ) ) {
F_75 ( V_29 , L_25 ,
V_96 ) ;
return 0 ;
}
F_75 ( V_29 , L_26 , V_90 ) ;
F_111 ( V_2 ) ;
return - V_106 ;
}
}
F_94 ( V_98 ) ;
if ( ! F_93 ( V_2 ) ) {
F_14 ( V_34 L_27 , V_29 ) ;
V_97 = 0 ;
goto V_124;
}
if ( F_12 ( V_2 ) ) {
if ( F_108 ( V_2 ) )
F_109 ( V_119 , & V_122 ) ;
F_97 ( V_98 ) ;
F_111 ( V_98 ) ;
return 0 ;
}
if ( F_89 ( V_2 ) && F_112 ( V_2 ) && F_105 ( V_98 ) ) {
F_75 ( V_29 , L_28 ,
V_90 ) ;
F_97 ( V_98 ) ;
F_111 ( V_98 ) ;
return 0 ;
}
if ( F_89 ( V_2 ) )
F_98 ( V_98 ) ;
F_113 ( V_2 ) ;
if ( F_79 ( V_2 , V_29 , V_28 , V_30 ) != V_114 ) {
F_14 ( V_34 L_29 , V_29 ) ;
V_97 = - V_106 ;
goto V_124;
}
if ( F_22 ( V_2 ) && ! F_84 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_75 ( V_29 , L_30 , V_90 ) ;
V_97 = - V_106 ;
goto V_124;
}
V_97 = - V_106 ;
for ( V_103 = V_125 ; ; V_103 ++ ) {
if ( ( V_2 -> V_30 & V_103 -> V_126 ) == V_103 -> V_97 ) {
V_97 = F_78 ( V_103 , V_2 , V_29 ) ;
break;
}
}
V_124:
F_97 ( V_98 ) ;
return V_97 ;
}
void F_114 ( unsigned long V_29 , int V_28 , int V_30 )
{
struct V_127 * V_128 ;
unsigned long V_129 ;
struct V_130 V_131 = {
. V_29 = V_29 ,
. V_28 = V_28 ,
. V_30 = V_30 ,
} ;
V_128 = & F_115 ( V_127 ) ;
F_116 ( & V_128 -> V_132 , V_129 ) ;
if ( F_117 ( & V_128 -> V_133 , & V_131 ) )
F_118 ( F_119 () , & V_128 -> V_134 ) ;
else
F_120 ( L_31 ,
V_29 ) ;
F_121 ( & V_128 -> V_132 , V_129 ) ;
F_122 ( V_127 ) ;
}
static void F_123 ( struct V_135 * V_134 )
{
struct V_127 * V_128 ;
struct V_130 V_131 = { 0 , } ;
unsigned long V_129 ;
int V_136 ;
V_128 = & F_124 ( V_127 ) ;
for (; ; ) {
F_116 ( & V_128 -> V_132 , V_129 ) ;
V_136 = F_125 ( & V_128 -> V_133 , & V_131 ) ;
F_121 ( & V_128 -> V_132 , V_129 ) ;
if ( ! V_136 )
break;
F_102 ( V_131 . V_29 , V_131 . V_28 , V_131 . V_30 ) ;
}
}
static int T_3 F_126 ( void )
{
struct V_127 * V_128 ;
int V_137 ;
F_127 (cpu) {
V_128 = & F_128 ( V_127 , V_137 ) ;
F_129 ( & V_128 -> V_132 ) ;
F_130 ( V_128 -> V_133 ) ;
F_131 ( & V_128 -> V_134 , F_123 ) ;
}
return 0 ;
}
int F_132 ( unsigned long V_29 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_138 = 0 ;
unsigned int V_119 ;
if ( ! F_104 ( V_29 ) )
return - V_121 ;
V_2 = F_76 ( V_29 ) ;
V_1 = F_17 ( V_2 ) ;
if ( ! F_93 ( V_2 ) ) {
F_30 ( L_32 , V_29 ) ;
return 0 ;
}
V_119 = 1 << F_16 ( V_1 ) ;
if ( ! F_107 ( V_1 ) ) {
if ( F_89 ( V_1 ) ) {
F_30 ( L_33 , V_29 ) ;
return 0 ;
}
if ( F_108 ( V_2 ) )
F_109 ( V_119 , & V_122 ) ;
F_30 ( L_34 , V_29 ) ;
return 0 ;
}
F_94 ( V_1 ) ;
if ( F_108 ( V_1 ) ) {
F_30 ( L_35 , V_29 ) ;
F_109 ( V_119 , & V_122 ) ;
V_138 = 1 ;
if ( F_89 ( V_1 ) )
F_100 ( V_1 ) ;
}
F_97 ( V_1 ) ;
F_111 ( V_1 ) ;
if ( V_138 )
F_111 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_133 ( struct V_1 * V_2 , unsigned long V_139 , int * * V_140 )
{
int V_141 = F_134 ( V_2 ) ;
if ( F_89 ( V_2 ) )
return F_135 ( F_136 ( F_17 ( V_2 ) ) ,
V_141 ) ;
else
return F_137 ( V_141 , V_142 , 0 ) ;
}
static int F_138 ( struct V_1 * V_2 , unsigned long V_29 , int V_30 )
{
int V_33 ;
if ( V_30 & V_123 )
return 1 ;
F_139 () ;
F_140 ( V_2 ) ;
if ( ! F_107 ( F_17 ( V_2 ) ) ) {
if ( F_89 ( V_2 ) ) {
F_30 ( L_36 , V_143 , V_29 ) ;
V_33 = F_74 ( F_17 ( V_2 ) ) ;
} else if ( F_24 ( V_2 ) ) {
F_30 ( L_37 , V_143 , V_29 ) ;
F_99 ( V_2 ) ;
V_33 = 0 ;
} else {
F_30 ( L_38 ,
V_143 , V_29 , V_2 -> V_30 ) ;
V_33 = - V_89 ;
}
} else {
V_33 = 1 ;
}
F_141 ( V_2 , V_144 ) ;
F_142 () ;
return V_33 ;
}
static int F_143 ( struct V_1 * V_1 , int V_30 )
{
int V_33 ;
unsigned long V_29 = F_31 ( V_1 ) ;
struct V_1 * V_98 = F_17 ( V_1 ) ;
V_33 = F_138 ( V_1 , V_29 , V_30 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 == 0 )
goto V_145;
if ( F_93 ( V_98 ) ) {
F_111 ( V_98 ) ;
F_30 ( L_39 , V_29 ) ;
return - V_106 ;
}
V_33 = F_144 ( V_98 , F_133 , V_146 , false ,
V_147 ) ;
F_111 ( V_98 ) ;
if ( V_33 ) {
F_30 ( L_40 ,
V_29 , V_33 , V_1 -> V_30 ) ;
return V_33 ;
}
V_145:
if ( ! F_93 ( V_98 ) )
F_106 ( 1 << F_16 ( V_98 ) ,
& V_122 ) ;
F_98 ( V_98 ) ;
F_74 ( V_98 ) ;
return V_33 ;
}
int F_145 ( struct V_1 * V_1 , int V_30 )
{
int V_33 ;
unsigned long V_29 = F_31 ( V_1 ) ;
if ( F_89 ( V_1 ) )
return F_143 ( V_1 , V_30 ) ;
V_33 = F_138 ( V_1 , V_29 , V_30 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 == 0 )
goto V_145;
if ( ! F_22 ( V_1 ) ) {
F_111 ( V_1 ) ;
F_20 ( V_1 , 1 ) ;
V_33 = F_138 ( V_1 , V_29 , 0 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 == 0 )
goto V_145;
}
if ( ! F_22 ( V_1 ) ) {
F_30 ( L_41 ,
V_29 , V_1 -> V_30 ) ;
return - V_89 ;
}
F_94 ( V_1 ) ;
F_113 ( V_1 ) ;
if ( F_93 ( V_1 ) ) {
F_97 ( V_1 ) ;
F_111 ( V_1 ) ;
F_30 ( L_42 , V_29 ) ;
return - V_106 ;
}
V_33 = F_64 ( V_1 ) ;
F_97 ( V_1 ) ;
if ( V_33 == 1 ) {
F_111 ( V_1 ) ;
V_33 = 0 ;
F_30 ( L_43 , V_29 ) ;
goto V_145;
}
V_33 = F_55 ( V_1 ) ;
F_111 ( V_1 ) ;
if ( ! V_33 ) {
F_80 ( V_148 ) ;
F_146 ( V_1 , V_149 +
F_147 ( V_1 ) ) ;
F_148 ( & V_1 -> V_150 , & V_148 ) ;
V_33 = F_149 ( & V_148 , F_133 , V_146 ,
false , V_147 ) ;
if ( V_33 ) {
F_150 ( & V_148 ) ;
F_30 ( L_40 ,
V_29 , V_33 , V_1 -> V_30 ) ;
if ( V_33 > 0 )
V_33 = - V_89 ;
}
} else {
F_30 ( L_44 ,
V_29 , V_33 , F_26 ( V_1 ) , V_1 -> V_30 ) ;
}
if ( V_33 )
return V_33 ;
V_145:
F_106 ( 1 , & V_122 ) ;
F_99 ( V_1 ) ;
return V_33 ;
}
