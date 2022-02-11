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
int V_52 = F_25 ( V_2 ) ;
do {
struct V_53 V_54 = {
. V_55 = V_56 ,
} ;
F_26 ( V_52 , V_54 . V_57 ) ;
V_51 = F_27 ( & V_54 , 1000 , 1000 ) ;
if ( F_28 ( V_2 ) == 1 )
break;
} while ( V_51 > 10 );
}
}
static void F_29 ( struct V_25 * V_58 , struct V_1 * V_2 ,
struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_62 * * V_63 )
{
struct V_62 * V_64 ;
if ( * V_63 ) {
V_64 = * V_63 ;
* V_63 = NULL ;
} else {
V_64 = F_30 ( sizeof( struct V_62 ) , V_65 ) ;
if ( ! V_64 ) {
F_14 ( V_34
L_3 ) ;
return;
}
}
V_64 -> V_27 = F_31 ( V_2 , V_60 ) ;
V_64 -> V_66 = 1 ;
if ( V_64 -> V_27 == - V_67 ) {
F_32 ( L_4 ,
F_33 ( V_2 ) , V_58 -> V_35 ) ;
V_64 -> V_66 = 0 ;
}
F_34 ( V_58 ) ;
V_64 -> V_58 = V_58 ;
F_35 ( & V_64 -> V_68 , V_62 ) ;
}
static void F_36 ( struct V_61 * V_62 , int V_69 , int V_28 ,
int V_70 , struct V_1 * V_1 , unsigned long V_29 ,
int V_30 )
{
struct V_62 * V_64 , * V_71 ;
F_37 (tk, next, to_kill, nd) {
if ( V_69 ) {
if ( V_70 || V_64 -> V_66 == 0 ) {
F_14 ( V_34
L_5 ,
V_29 , V_64 -> V_58 -> V_35 , V_64 -> V_58 -> V_36 ) ;
F_38 ( V_72 , V_64 -> V_58 ) ;
}
else if ( F_13 ( V_64 -> V_58 , V_64 -> V_27 , V_28 ,
V_29 , V_1 , V_30 ) < 0 )
F_14 ( V_34
L_6 ,
V_29 , V_64 -> V_58 -> V_35 , V_64 -> V_58 -> V_36 ) ;
}
F_39 ( V_64 -> V_58 ) ;
F_40 ( V_64 ) ;
}
}
static int F_41 ( struct V_25 * V_58 )
{
if ( ! V_58 -> V_73 )
return 0 ;
if ( V_58 -> V_30 & V_74 )
return ! ! ( V_58 -> V_30 & V_75 ) ;
return V_76 ;
}
static void F_42 ( struct V_1 * V_1 , struct V_61 * V_62 ,
struct V_62 * * V_63 )
{
struct V_59 * V_60 ;
struct V_25 * V_58 ;
struct V_77 * V_78 ;
T_2 V_79 ;
V_78 = F_43 ( V_1 ) ;
if ( V_78 == NULL )
return;
V_79 = V_1 -> V_80 << ( V_81 - V_43 ) ;
F_44 ( & V_82 ) ;
F_45 (tsk) {
struct V_83 * V_84 ;
if ( ! F_41 ( V_58 ) )
continue;
F_46 (vmac, &av->rb_root,
pgoff, pgoff) {
V_60 = V_84 -> V_60 ;
if ( ! F_47 ( V_1 , V_60 ) )
continue;
if ( V_60 -> V_85 == V_58 -> V_73 )
F_29 ( V_58 , V_1 , V_60 , V_62 , V_63 ) ;
}
}
F_48 ( & V_82 ) ;
F_49 ( V_78 ) ;
}
static void F_50 ( struct V_1 * V_1 , struct V_61 * V_62 ,
struct V_62 * * V_63 )
{
struct V_59 * V_60 ;
struct V_25 * V_58 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_51 ( & V_4 -> V_86 ) ;
F_44 ( & V_82 ) ;
F_45 (tsk) {
T_2 V_79 = V_1 -> V_80 << ( V_81 - V_43 ) ;
if ( ! F_41 ( V_58 ) )
continue;
F_52 (vma, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_60 -> V_85 == V_58 -> V_73 )
F_29 ( V_58 , V_1 , V_60 , V_62 , V_63 ) ;
}
}
F_48 ( & V_82 ) ;
F_53 ( & V_4 -> V_86 ) ;
}
static void F_54 ( struct V_1 * V_1 , struct V_61 * V_87 )
{
struct V_62 * V_64 ;
if ( ! V_1 -> V_4 )
return;
V_64 = F_30 ( sizeof( struct V_62 ) , V_88 ) ;
if ( ! V_64 )
return;
if ( F_55 ( V_1 ) )
F_42 ( V_1 , V_87 , & V_64 ) ;
else
F_50 ( V_1 , V_87 , & V_64 ) ;
F_40 ( V_64 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 ) ) {
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
return - V_89 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned long V_29 )
{
return V_90 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_14 ( V_34 L_7 , V_29 ) ;
return V_91 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned long V_29 )
{
int V_92 ;
int V_33 = V_91 ;
struct V_3 * V_4 ;
F_56 ( V_2 ) ;
if ( F_55 ( V_2 ) )
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
} else if ( F_64 ( V_2 ) &&
! F_65 ( V_2 , V_88 ) ) {
F_32 ( L_9 , V_29 ) ;
} else {
V_33 = V_93 ;
}
} else {
if ( F_66 ( V_2 ) )
V_33 = V_93 ;
else
F_14 ( V_49 L_10 ,
V_29 ) ;
}
return V_33 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_68 ( V_2 ) ;
if ( V_4 ) {
F_69 ( V_4 , V_89 ) ;
}
return F_63 ( V_2 , V_29 ) ;
}
static int F_70 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
return V_96 ;
else
return V_91 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned long V_29 )
{
F_74 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
return V_93 ;
else
return V_91 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned long V_29 )
{
int V_97 = 0 ;
struct V_1 * V_98 = F_17 ( V_2 ) ;
if ( ! ( F_3 ( V_98 ) || F_55 ( V_98 ) ) ) {
V_97 = F_76 ( V_98 ) ;
if ( ! V_97 )
return V_93 ;
}
return V_96 ;
}
static void F_77 ( unsigned long V_29 , char * V_99 , int V_100 )
{
F_78 ( L_11 ,
V_29 , V_99 , V_101 [ V_100 ] ) ;
}
static int F_79 ( struct V_102 * V_103 , struct V_1 * V_2 ,
unsigned long V_29 )
{
int V_100 ;
int V_104 ;
V_100 = V_103 -> V_105 ( V_2 , V_29 ) ;
F_77 ( V_29 , V_103 -> V_99 , V_100 ) ;
V_104 = F_28 ( V_2 ) - 1 ;
if ( V_103 -> V_105 == F_70 && V_100 == V_96 )
V_104 -- ;
if ( V_104 != 0 ) {
F_14 ( V_34
L_12 ,
V_29 , V_103 -> V_99 , V_104 ) ;
V_100 = V_91 ;
}
return ( V_100 == V_93 || V_100 == V_96 ) ? 0 : - V_106 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned long V_29 ,
int V_28 , int V_30 )
{
enum V_107 V_108 = V_109 | V_110 | V_111 ;
struct V_3 * V_4 ;
F_81 ( V_87 ) ;
int V_33 ;
int V_112 = 1 , V_69 ;
struct V_1 * V_98 = F_17 ( V_2 ) ;
struct V_1 * V_113 ;
if ( F_82 ( V_2 ) || F_2 ( V_2 ) )
return V_114 ;
if ( ! F_83 ( V_98 ) )
return V_114 ;
if ( F_84 ( V_2 ) )
return V_115 ;
if ( F_85 ( V_2 ) ) {
F_14 ( V_34
L_13 , V_29 ) ;
V_108 |= V_116 ;
}
V_4 = F_3 ( V_98 ) ;
if ( ! ( V_30 & V_117 ) && ! F_86 ( V_98 ) && V_4 &&
F_87 ( V_4 ) ) {
if ( F_88 ( V_98 ) ) {
F_89 ( V_98 ) ;
} else {
V_112 = 0 ;
V_108 |= V_116 ;
F_14 ( V_49
L_14 ,
V_29 ) ;
}
}
V_113 = V_98 ;
if ( F_90 ( V_98 ) ) {
if ( ! F_91 ( V_98 ) && F_55 ( V_98 ) ) {
if ( F_92 ( F_93 ( V_98 ) ) ) {
F_14 ( V_49
L_15 , V_29 ) ;
F_94 ( ! F_95 ( V_2 ) ) ;
return V_115 ;
}
V_113 = V_2 ;
}
}
if ( V_112 )
F_54 ( V_113 , & V_87 ) ;
if ( V_98 != V_113 )
F_96 ( V_113 ) ;
V_33 = F_97 ( V_113 , V_108 ) ;
if ( V_33 != V_114 )
F_14 ( V_34 L_16 ,
V_29 , F_98 ( V_113 ) ) ;
if ( V_98 != V_113 )
F_99 ( V_113 ) ;
V_69 = F_86 ( V_113 ) || ( V_30 & V_117 ) ;
F_36 ( & V_87 , V_69 , V_28 ,
V_33 != V_114 , V_2 , V_29 , V_30 ) ;
return V_33 ;
}
static void F_100 ( struct V_1 * V_98 )
{
int V_118 ;
int V_119 = 1 << F_16 ( V_98 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
F_101 ( V_98 + V_118 ) ;
}
static void F_102 ( struct V_1 * V_98 )
{
int V_118 ;
int V_119 = 1 << F_16 ( V_98 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
F_103 ( V_98 + V_118 ) ;
}
int F_104 ( unsigned long V_29 , int V_28 , int V_30 )
{
struct V_102 * V_103 ;
struct V_1 * V_2 ;
struct V_1 * V_98 ;
int V_97 ;
unsigned int V_119 ;
unsigned long V_120 ;
if ( ! V_121 )
F_105 ( L_17 , V_28 , V_29 ) ;
if ( ! F_106 ( V_29 ) ) {
F_14 ( V_34
L_18 ,
V_29 ) ;
return - V_122 ;
}
V_2 = F_107 ( V_29 ) ;
V_98 = F_17 ( V_2 ) ;
if ( F_108 ( V_2 ) ) {
F_14 ( V_34 L_19 , V_29 ) ;
return 0 ;
}
if ( F_91 ( V_2 ) )
V_119 = 1 << F_16 ( V_98 ) ;
else
V_119 = 1 ;
F_109 ( V_119 , & V_123 ) ;
if ( ! ( V_30 & V_124 ) &&
! F_110 ( V_98 ) ) {
if ( F_24 ( V_2 ) ) {
F_77 ( V_29 , L_20 , V_96 ) ;
return 0 ;
} else if ( F_91 ( V_98 ) ) {
F_96 ( V_98 ) ;
if ( ! F_95 ( V_98 )
|| ( F_12 ( V_2 ) && F_111 ( V_2 ) )
|| ( V_2 != V_98 && F_108 ( V_98 ) ) ) {
F_112 ( V_119 , & V_123 ) ;
return 0 ;
}
F_100 ( V_98 ) ;
V_97 = F_76 ( V_98 ) ;
F_77 ( V_29 , L_21 ,
V_97 ? V_90 : V_96 ) ;
F_99 ( V_98 ) ;
return V_97 ;
} else {
F_77 ( V_29 , L_22 , V_90 ) ;
return - V_106 ;
}
}
if ( ! F_91 ( V_2 ) && ! F_113 ( V_2 ) ) {
if ( ! F_22 ( V_2 ) )
F_20 ( V_2 , 0 ) ;
if ( ! F_22 ( V_2 ) ) {
if ( F_24 ( V_2 ) ) {
if ( V_30 & V_124 )
F_77 ( V_29 , L_20 , V_96 ) ;
else
F_77 ( V_29 , L_23 , V_96 ) ;
return 0 ;
}
F_77 ( V_29 , L_24 , V_90 ) ;
F_114 ( V_2 ) ;
return - V_106 ;
}
}
F_96 ( V_98 ) ;
V_120 = V_2 -> V_30 ;
if ( ! F_95 ( V_2 ) ) {
F_14 ( V_34 L_25 , V_29 ) ;
V_97 = 0 ;
goto V_125;
}
if ( F_12 ( V_2 ) ) {
if ( F_111 ( V_2 ) )
F_112 ( V_119 , & V_123 ) ;
F_99 ( V_98 ) ;
F_114 ( V_98 ) ;
return 0 ;
}
if ( F_91 ( V_2 ) && F_115 ( V_2 ) && F_108 ( V_98 ) ) {
F_77 ( V_29 , L_26 ,
V_90 ) ;
F_99 ( V_98 ) ;
F_114 ( V_98 ) ;
return 0 ;
}
if ( F_91 ( V_2 ) )
F_100 ( V_98 ) ;
F_116 ( V_2 ) ;
if ( F_80 ( V_2 , V_29 , V_28 , V_30 ) != V_114 ) {
F_14 ( V_34 L_27 , V_29 ) ;
V_97 = - V_106 ;
goto V_125;
}
if ( F_22 ( V_2 ) && ! F_85 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_77 ( V_29 , L_28 , V_90 ) ;
V_97 = - V_106 ;
goto V_125;
}
V_97 = - V_106 ;
for ( V_103 = V_126 ; ; V_103 ++ )
if ( ( V_2 -> V_30 & V_103 -> V_127 ) == V_103 -> V_97 )
break;
V_120 |= ( V_2 -> V_30 & ( 1UL << V_128 ) ) ;
if ( ! V_103 -> V_127 )
for ( V_103 = V_126 ; ; V_103 ++ )
if ( ( V_120 & V_103 -> V_127 ) == V_103 -> V_97 )
break;
V_97 = F_79 ( V_103 , V_2 , V_29 ) ;
V_125:
F_99 ( V_98 ) ;
return V_97 ;
}
void F_117 ( unsigned long V_29 , int V_28 , int V_30 )
{
struct V_129 * V_130 ;
unsigned long V_131 ;
struct V_132 V_133 = {
. V_29 = V_29 ,
. V_28 = V_28 ,
. V_30 = V_30 ,
} ;
V_130 = & F_118 ( V_129 ) ;
F_119 ( & V_130 -> V_134 , V_131 ) ;
if ( F_120 ( & V_130 -> V_135 , & V_133 ) )
F_121 ( F_122 () , & V_130 -> V_136 ) ;
else
F_78 ( L_29 ,
V_29 ) ;
F_123 ( & V_130 -> V_134 , V_131 ) ;
F_124 ( V_129 ) ;
}
static void F_125 ( struct V_137 * V_136 )
{
struct V_129 * V_130 ;
struct V_132 V_133 = { 0 , } ;
unsigned long V_131 ;
int V_138 ;
V_130 = & F_126 ( V_129 ) ;
for (; ; ) {
F_119 ( & V_130 -> V_134 , V_131 ) ;
V_138 = F_127 ( & V_130 -> V_135 , & V_133 ) ;
F_123 ( & V_130 -> V_134 , V_131 ) ;
if ( ! V_138 )
break;
if ( V_133 . V_30 & V_139 )
F_128 ( F_107 ( V_133 . V_29 ) , V_133 . V_30 ) ;
else
F_104 ( V_133 . V_29 , V_133 . V_28 , V_133 . V_30 ) ;
}
}
static int T_3 F_129 ( void )
{
struct V_129 * V_130 ;
int V_140 ;
F_130 (cpu) {
V_130 = & F_131 ( V_129 , V_140 ) ;
F_132 ( & V_130 -> V_134 ) ;
F_133 ( V_130 -> V_135 ) ;
F_134 ( & V_130 -> V_136 , F_125 ) ;
}
return 0 ;
}
int F_135 ( unsigned long V_29 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_141 = 0 ;
unsigned int V_119 ;
if ( ! F_106 ( V_29 ) )
return - V_122 ;
V_2 = F_107 ( V_29 ) ;
V_1 = F_17 ( V_2 ) ;
if ( ! F_95 ( V_2 ) ) {
F_32 ( L_30 , V_29 ) ;
return 0 ;
}
if ( ! F_91 ( V_1 ) && F_90 ( V_1 ) ) {
F_32 ( L_31 , V_29 ) ;
return 0 ;
}
V_119 = 1 << F_16 ( V_1 ) ;
if ( ! F_110 ( V_1 ) ) {
if ( F_91 ( V_1 ) ) {
F_32 ( L_32 , V_29 ) ;
return 0 ;
}
if ( F_111 ( V_2 ) )
F_136 ( & V_123 ) ;
F_32 ( L_33 , V_29 ) ;
return 0 ;
}
F_96 ( V_1 ) ;
if ( F_111 ( V_1 ) ) {
F_32 ( L_34 , V_29 ) ;
F_112 ( V_119 , & V_123 ) ;
V_141 = 1 ;
if ( F_91 ( V_1 ) )
F_102 ( V_1 ) ;
}
F_99 ( V_1 ) ;
F_114 ( V_1 ) ;
if ( V_141 && ! ( V_29 == F_137 ( 0 ) && F_28 ( V_2 ) == 1 ) )
F_114 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_138 ( struct V_1 * V_2 , unsigned long V_142 , int * * V_143 )
{
int V_52 = F_25 ( V_2 ) ;
if ( F_91 ( V_2 ) )
return F_139 ( F_140 ( F_17 ( V_2 ) ) ,
V_52 ) ;
else
return F_141 ( V_52 , V_144 , 0 ) ;
}
static int F_142 ( struct V_1 * V_2 , unsigned long V_29 , int V_30 )
{
int V_33 ;
if ( V_30 & V_124 )
return 1 ;
F_143 () ;
if ( F_144 ( V_2 ) != V_145 )
F_145 ( V_2 , true ) ;
if ( ! F_110 ( F_17 ( V_2 ) ) ) {
if ( F_91 ( V_2 ) ) {
F_32 ( L_35 , V_146 , V_29 ) ;
V_33 = 0 ;
} else if ( F_24 ( V_2 ) ) {
F_32 ( L_36 , V_146 , V_29 ) ;
V_33 = 0 ;
} else {
F_32 ( L_37 ,
V_146 , V_29 , V_2 -> V_30 ) ;
V_33 = - V_89 ;
}
} else {
V_33 = 1 ;
}
F_146 () ;
return V_33 ;
}
static int F_147 ( struct V_1 * V_1 , unsigned long V_29 , int V_30 )
{
int V_33 = F_142 ( V_1 , V_29 , V_30 ) ;
if ( V_33 == 1 && ! F_91 ( V_1 ) && ! F_22 ( V_1 ) ) {
F_114 ( V_1 ) ;
F_20 ( V_1 , 1 ) ;
V_33 = F_142 ( V_1 , V_29 , 0 ) ;
if ( ! F_22 ( V_1 ) ) {
F_32 ( L_38 ,
V_29 , V_1 -> V_30 ) ;
return - V_89 ;
}
}
return V_33 ;
}
static int F_148 ( struct V_1 * V_1 , int V_30 )
{
int V_33 ;
unsigned long V_29 = F_33 ( V_1 ) ;
struct V_1 * V_98 = F_17 ( V_1 ) ;
F_81 ( V_147 ) ;
F_96 ( V_98 ) ;
if ( F_95 ( V_98 ) ) {
F_99 ( V_98 ) ;
F_114 ( V_98 ) ;
F_32 ( L_39 , V_29 ) ;
return - V_106 ;
}
F_99 ( V_98 ) ;
F_149 ( & V_98 -> V_148 , & V_147 ) ;
V_33 = F_150 ( & V_147 , F_138 , V_149 ,
V_150 , V_151 ) ;
if ( V_33 ) {
F_32 ( L_40 ,
V_29 , V_33 , V_1 -> V_30 ) ;
F_151 ( V_98 ) ;
if ( V_33 > 0 )
V_33 = - V_89 ;
} else {
F_100 ( V_98 ) ;
F_76 ( V_98 ) ;
F_109 ( 1 << F_16 ( V_98 ) ,
& V_123 ) ;
}
return V_33 ;
}
static int F_152 ( struct V_1 * V_1 , int V_30 )
{
int V_33 ;
unsigned long V_29 = F_33 ( V_1 ) ;
F_96 ( V_1 ) ;
F_116 ( V_1 ) ;
if ( F_95 ( V_1 ) ) {
F_99 ( V_1 ) ;
F_114 ( V_1 ) ;
F_32 ( L_41 , V_29 ) ;
return - V_106 ;
}
V_33 = F_66 ( V_1 ) ;
F_99 ( V_1 ) ;
if ( V_33 == 1 ) {
F_114 ( V_1 ) ;
F_32 ( L_42 , V_29 ) ;
F_101 ( V_1 ) ;
F_153 ( & V_123 ) ;
return 0 ;
}
V_33 = F_57 ( V_1 ) ;
F_114 ( V_1 ) ;
if ( ! V_33 ) {
F_81 ( V_147 ) ;
F_154 ( V_1 , V_152 +
F_155 ( V_1 ) ) ;
F_156 ( & V_1 -> V_148 , & V_147 ) ;
V_33 = F_150 ( & V_147 , F_138 , V_149 ,
V_150 , V_151 ) ;
if ( V_33 ) {
F_157 ( & V_147 ) ;
F_32 ( L_40 ,
V_29 , V_33 , V_1 -> V_30 ) ;
if ( V_33 > 0 )
V_33 = - V_89 ;
} else {
if ( ! F_24 ( V_1 ) )
F_21 () ;
if ( ! F_24 ( V_1 ) )
F_23 () ;
F_101 ( V_1 ) ;
if ( ! F_24 ( V_1 ) )
F_32 ( L_43 ,
V_29 ) ;
F_153 ( & V_123 ) ;
}
} else {
F_32 ( L_44 ,
V_29 , V_33 , F_28 ( V_1 ) , V_1 -> V_30 ) ;
}
return V_33 ;
}
int F_128 ( struct V_1 * V_1 , int V_30 )
{
int V_33 ;
unsigned long V_29 = F_33 ( V_1 ) ;
struct V_1 * V_98 = F_158 ( V_1 ) ;
if ( F_95 ( V_1 ) ) {
F_32 ( L_41 , V_29 ) ;
return - V_106 ;
}
if ( ! F_91 ( V_1 ) && F_90 ( V_98 ) ) {
if ( F_55 ( V_98 ) && F_92 ( F_93 ( V_98 ) ) ) {
F_32 ( L_45 ,
V_29 ) ;
return - V_106 ;
}
}
V_33 = F_147 ( V_1 , V_29 , V_30 ) ;
if ( V_33 < 0 )
goto V_153;
if ( V_33 ) {
if ( F_91 ( V_1 ) )
V_33 = F_148 ( V_1 , V_30 ) ;
else
V_33 = F_152 ( V_1 , V_30 ) ;
} else {
if ( F_91 ( V_1 ) ) {
F_100 ( V_98 ) ;
F_76 ( V_98 ) ;
F_109 ( 1 << F_16 ( V_98 ) ,
& V_123 ) ;
} else {
F_101 ( V_1 ) ;
F_153 ( & V_123 ) ;
}
}
V_153:
F_159 ( V_1 , V_154 ) ;
return V_33 ;
}
