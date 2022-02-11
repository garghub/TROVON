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
F_12 ( V_25
L_1 ,
V_20 , V_17 -> V_26 , V_17 -> V_27 ) ;
V_23 . V_28 = V_29 ;
V_23 . V_30 = 0 ;
V_23 . V_31 = ( void * ) V_18 ;
#ifdef F_13
V_23 . V_32 = V_19 ;
#endif
V_23 . V_33 = F_14 ( F_15 ( V_1 ) ) + V_34 ;
if ( ( V_21 & V_35 ) && V_17 -> V_36 == V_37 -> V_36 ) {
V_23 . V_38 = V_39 ;
V_24 = F_16 ( V_29 , & V_23 , V_37 ) ;
} else {
V_23 . V_38 = V_40 ;
V_24 = F_17 ( V_29 , & V_23 , V_17 ) ;
}
if ( V_24 < 0 )
F_12 ( V_41 L_2 ,
V_17 -> V_26 , V_17 -> V_27 , V_24 ) ;
return V_24 ;
}
void F_18 ( struct V_1 * V_2 , int V_42 )
{
if ( ! F_2 ( V_2 ) ) {
F_19 () ;
if ( F_20 ( V_2 ) )
return;
F_21 ( F_22 ( V_2 ) ) ;
if ( F_20 ( V_2 ) || F_23 ( V_2 ) )
return;
}
if ( V_42 )
F_24 ( F_25 ( V_2 ) ) ;
}
static void F_26 ( struct V_16 * V_43 , struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_47 * * V_48 )
{
struct V_47 * V_49 ;
if ( * V_48 ) {
V_49 = * V_48 ;
* V_48 = NULL ;
} else {
V_49 = F_27 ( sizeof( struct V_47 ) , V_50 ) ;
if ( ! V_49 ) {
F_12 ( V_25
L_3 ) ;
return;
}
}
V_49 -> V_18 = F_28 ( V_2 , V_45 ) ;
V_49 -> V_51 = 1 ;
if ( V_49 -> V_18 == - V_52 ) {
F_29 ( L_4 ,
F_30 ( V_2 ) , V_43 -> V_26 ) ;
V_49 -> V_51 = 0 ;
}
F_31 ( V_43 ) ;
V_49 -> V_43 = V_43 ;
F_32 ( & V_49 -> V_53 , V_47 ) ;
}
static void F_33 ( struct V_46 * V_47 , int V_54 , int V_19 ,
int V_55 , struct V_1 * V_1 , unsigned long V_20 ,
int V_21 )
{
struct V_47 * V_49 , * V_56 ;
F_34 (tk, next, to_kill, nd) {
if ( V_54 ) {
if ( V_55 || V_49 -> V_51 == 0 ) {
F_12 ( V_25
L_5 ,
V_20 , V_49 -> V_43 -> V_26 , V_49 -> V_43 -> V_27 ) ;
F_35 ( V_57 , V_49 -> V_43 ) ;
}
else if ( F_11 ( V_49 -> V_43 , V_49 -> V_18 , V_19 ,
V_20 , V_1 , V_21 ) < 0 )
F_12 ( V_25
L_6 ,
V_20 , V_49 -> V_43 -> V_26 , V_49 -> V_43 -> V_27 ) ;
}
F_36 ( V_49 -> V_43 ) ;
F_37 ( V_49 ) ;
}
}
static struct V_16 * F_38 ( struct V_16 * V_43 )
{
struct V_16 * V_17 ;
F_39 (tsk, t)
if ( ( V_17 -> V_21 & V_58 ) && ( V_17 -> V_21 & V_59 ) )
return V_17 ;
return NULL ;
}
static struct V_16 * F_40 ( struct V_16 * V_43 ,
int V_60 )
{
struct V_16 * V_17 ;
if ( ! V_43 -> V_36 )
return NULL ;
if ( V_60 )
return V_43 ;
V_17 = F_38 ( V_43 ) ;
if ( V_17 )
return V_17 ;
if ( V_61 )
return V_43 ;
return NULL ;
}
static void F_41 ( struct V_1 * V_1 , struct V_46 * V_47 ,
struct V_47 * * V_48 , int V_60 )
{
struct V_44 * V_45 ;
struct V_16 * V_43 ;
struct V_62 * V_63 ;
T_2 V_64 ;
V_63 = F_42 ( V_1 ) ;
if ( V_63 == NULL )
return;
V_64 = F_43 ( V_1 ) ;
F_44 ( & V_65 ) ;
F_45 (tsk) {
struct V_66 * V_67 ;
struct V_16 * V_17 = F_40 ( V_43 , V_60 ) ;
if ( ! V_17 )
continue;
F_46 (vmac, &av->rb_root,
pgoff, pgoff) {
V_45 = V_67 -> V_45 ;
if ( ! F_47 ( V_1 , V_45 ) )
continue;
if ( V_45 -> V_68 == V_17 -> V_36 )
F_26 ( V_17 , V_1 , V_45 , V_47 , V_48 ) ;
}
}
F_48 ( & V_65 ) ;
F_49 ( V_63 ) ;
}
static void F_50 ( struct V_1 * V_1 , struct V_46 * V_47 ,
struct V_47 * * V_48 , int V_60 )
{
struct V_44 * V_45 ;
struct V_16 * V_43 ;
struct V_3 * V_4 = V_1 -> V_4 ;
F_51 ( V_4 ) ;
F_44 ( & V_65 ) ;
F_45 (tsk) {
T_2 V_64 = F_43 ( V_1 ) ;
struct V_16 * V_17 = F_40 ( V_43 , V_60 ) ;
if ( ! V_17 )
continue;
F_52 (vma, &mapping->i_mmap, pgoff,
pgoff) {
if ( V_45 -> V_68 == V_17 -> V_36 )
F_26 ( V_17 , V_1 , V_45 , V_47 , V_48 ) ;
}
}
F_48 ( & V_65 ) ;
F_53 ( V_4 ) ;
}
static void F_54 ( struct V_1 * V_1 , struct V_46 * V_69 ,
int V_60 )
{
struct V_47 * V_49 ;
if ( ! V_1 -> V_4 )
return;
V_49 = F_27 ( sizeof( struct V_47 ) , V_70 ) ;
if ( ! V_49 )
return;
if ( F_55 ( V_1 ) )
F_41 ( V_1 , V_69 , & V_49 , V_60 ) ;
else
F_50 ( V_1 , V_69 , & V_49 , V_60 ) ;
F_37 ( V_49 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 ) ) {
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
return - V_71 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned long V_20 )
{
return V_72 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_12 ( V_25 L_7 , V_20 ) ;
return V_73 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned long V_20 )
{
int V_74 ;
int V_24 = V_73 ;
struct V_3 * V_4 ;
F_56 ( V_2 ) ;
if ( F_55 ( V_2 ) )
return V_75 ;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 ) {
return V_73 ;
}
if ( V_4 -> V_76 -> V_77 ) {
V_74 = V_4 -> V_76 -> V_77 ( V_4 , V_2 ) ;
if ( V_74 != 0 ) {
F_12 ( V_41 L_8 ,
V_20 , V_74 ) ;
} else if ( F_64 ( V_2 ) &&
! F_65 ( V_2 , V_70 ) ) {
F_29 ( L_9 , V_20 ) ;
} else {
V_24 = V_75 ;
}
} else {
if ( F_66 ( V_2 ) )
V_24 = V_75 ;
else
F_12 ( V_41 L_10 ,
V_20 ) ;
}
return V_24 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned long V_20 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
F_68 ( V_2 ) ;
if ( V_4 ) {
F_69 ( V_4 , V_71 ) ;
}
return F_63 ( V_2 , V_20 ) ;
}
static int F_70 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
return V_78 ;
else
return V_73 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned long V_20 )
{
F_74 ( V_2 ) ;
if ( ! F_56 ( V_2 ) )
return V_75 ;
else
return V_73 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned long V_20 )
{
int V_79 = 0 ;
struct V_1 * V_80 = F_15 ( V_2 ) ;
if ( ! F_76 ( V_80 ) )
return V_78 ;
if ( ! ( F_3 ( V_80 ) || F_55 ( V_80 ) ) ) {
V_79 = F_77 ( V_80 ) ;
if ( ! V_79 )
return V_75 ;
}
return V_78 ;
}
static void F_78 ( unsigned long V_20 , enum V_81 type ,
enum V_82 V_83 )
{
F_79 ( V_20 , type , V_83 ) ;
F_80 ( L_11 ,
V_20 , V_84 [ type ] , V_85 [ V_83 ] ) ;
}
static int F_81 ( struct V_86 * V_87 , struct V_1 * V_2 ,
unsigned long V_20 )
{
int V_83 ;
int V_88 ;
V_83 = V_87 -> V_89 ( V_2 , V_20 ) ;
V_88 = F_82 ( V_2 ) - 1 ;
if ( V_87 -> V_89 == F_70 && V_83 == V_78 )
V_88 -- ;
if ( V_88 != 0 ) {
F_12 ( V_25
L_12 ,
V_20 , V_84 [ V_87 -> type ] , V_88 ) ;
V_83 = V_73 ;
}
F_78 ( V_20 , V_87 -> type , V_83 ) ;
return ( V_83 == V_75 || V_83 == V_78 ) ? 0 : - V_90 ;
}
int F_83 ( struct V_1 * V_1 )
{
struct V_1 * V_91 = F_15 ( V_1 ) ;
if ( F_76 ( V_91 ) )
return F_84 ( V_91 ) ;
if ( F_85 ( V_91 ) ) {
if ( ! F_55 ( V_91 ) ) {
F_80 ( L_13 ,
F_30 ( V_1 ) ) ;
return 0 ;
}
if ( F_84 ( V_91 ) ) {
if ( F_86 ( V_1 ) )
F_87 ( V_1 ) ;
return 1 ;
} else {
return 0 ;
}
}
return F_84 ( V_1 ) ;
}
void F_88 ( struct V_1 * V_1 )
{
struct V_1 * V_91 = F_15 ( V_1 ) ;
if ( F_76 ( V_91 ) ) {
F_89 ( V_91 ) ;
return;
}
if ( F_85 ( V_91 ) )
if ( V_1 != V_91 )
F_89 ( V_91 ) ;
F_89 ( V_1 ) ;
}
static int F_90 ( struct V_1 * V_2 , unsigned long V_20 ,
int V_19 , int V_21 , struct V_1 * * V_92 )
{
enum V_93 V_94 = V_95 | V_96 | V_97 ;
struct V_3 * V_4 ;
F_91 ( V_69 ) ;
int V_24 ;
int V_98 = 1 , V_54 ;
struct V_1 * V_80 = * V_92 ;
if ( F_92 ( V_2 ) || F_2 ( V_2 ) )
return V_99 ;
if ( ! ( F_20 ( V_80 ) || F_76 ( V_2 ) ) )
return V_99 ;
if ( ! F_93 ( V_80 ) )
return V_99 ;
if ( F_94 ( V_2 ) ) {
F_80 ( L_14 , V_20 ) ;
return V_100 ;
}
if ( F_95 ( V_2 ) ) {
F_12 ( V_25
L_15 , V_20 ) ;
V_94 |= V_101 ;
}
V_4 = F_3 ( V_80 ) ;
if ( ! ( V_21 & V_102 ) && ! F_96 ( V_80 ) && V_4 &&
F_97 ( V_4 ) ) {
if ( F_98 ( V_80 ) ) {
F_99 ( V_80 ) ;
} else {
V_98 = 0 ;
V_94 |= V_101 ;
F_12 ( V_41
L_16 ,
V_20 ) ;
}
}
if ( V_98 )
F_54 ( V_80 , & V_69 , V_21 & V_35 ) ;
V_24 = F_100 ( V_80 , V_94 ) ;
if ( V_24 != V_99 )
F_12 ( V_25 L_17 ,
V_20 , F_101 ( V_80 ) ) ;
V_54 = F_96 ( V_80 ) || ( V_21 & V_102 ) ;
F_33 ( & V_69 , V_54 , V_19 ,
V_24 != V_99 , V_2 , V_20 , V_21 ) ;
return V_24 ;
}
static void F_102 ( struct V_1 * V_80 )
{
int V_103 ;
int V_104 = 1 << F_14 ( V_80 ) ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ )
F_103 ( V_80 + V_103 ) ;
}
static void F_104 ( struct V_1 * V_80 )
{
int V_103 ;
int V_104 = 1 << F_14 ( V_80 ) ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ )
F_105 ( V_80 + V_103 ) ;
}
int F_106 ( unsigned long V_20 , int V_19 , int V_21 )
{
struct V_86 * V_87 ;
struct V_1 * V_2 ;
struct V_1 * V_80 ;
struct V_1 * V_105 ;
int V_79 ;
unsigned int V_104 ;
unsigned long V_106 ;
if ( ! V_107 )
F_107 ( L_18 , V_19 , V_20 ) ;
if ( ! F_108 ( V_20 ) ) {
F_12 ( V_25
L_19 ,
V_20 ) ;
return - V_108 ;
}
V_2 = F_109 ( V_20 ) ;
V_105 = V_80 = F_15 ( V_2 ) ;
if ( F_110 ( V_2 ) ) {
F_12 ( V_25 L_20 , V_20 ) ;
return 0 ;
}
if ( F_76 ( V_2 ) )
V_104 = 1 << F_14 ( V_80 ) ;
else
V_104 = 1 ;
F_111 ( V_104 ) ;
if ( ! ( V_21 & V_109 ) && ! F_83 ( V_2 ) ) {
if ( F_23 ( V_2 ) ) {
F_78 ( V_20 , V_110 , V_78 ) ;
return 0 ;
} else if ( F_76 ( V_80 ) ) {
F_112 ( V_80 ) ;
if ( F_113 ( V_80 ) ) {
if ( ( F_10 ( V_2 ) && F_114 ( V_2 ) )
|| ( V_2 != V_80 && F_110 ( V_80 ) ) ) {
F_115 ( V_104 ) ;
F_116 ( V_80 ) ;
return 0 ;
}
}
F_102 ( V_80 ) ;
V_79 = F_77 ( V_80 ) ;
F_78 ( V_20 , V_111 ,
V_79 ? V_72 : V_78 ) ;
F_116 ( V_80 ) ;
return V_79 ;
} else {
F_78 ( V_20 , V_112 , V_72 ) ;
return - V_90 ;
}
}
if ( ! F_76 ( V_2 ) && F_85 ( V_80 ) ) {
if ( ! F_55 ( V_80 ) || F_117 ( F_118 ( V_80 ) ) ) {
if ( ! F_55 ( V_80 ) )
F_80 ( L_13 , V_20 ) ;
else
F_80 ( L_21 , V_20 ) ;
if ( F_114 ( V_2 ) )
F_115 ( V_104 ) ;
F_88 ( V_2 ) ;
return - V_90 ;
}
F_119 ( ! F_82 ( V_2 ) , V_2 ) ;
V_80 = F_15 ( V_2 ) ;
}
if ( ! F_76 ( V_2 ) ) {
if ( ! F_20 ( V_2 ) )
F_18 ( V_2 , 0 ) ;
if ( ! F_20 ( V_2 ) ) {
if ( F_23 ( V_2 ) ) {
if ( V_21 & V_109 )
F_78 ( V_20 , V_110 , V_78 ) ;
else
F_78 ( V_20 , V_113 ,
V_78 ) ;
return 0 ;
}
}
}
F_112 ( V_80 ) ;
if ( F_120 ( V_2 ) && F_15 ( V_2 ) != V_105 ) {
F_78 ( V_20 , V_114 , V_72 ) ;
V_79 = - V_90 ;
goto V_115;
}
V_106 = V_2 -> V_21 ;
if ( ! F_113 ( V_2 ) ) {
F_12 ( V_25 L_22 , V_20 ) ;
F_115 ( V_104 ) ;
F_116 ( V_80 ) ;
F_88 ( V_80 ) ;
return 0 ;
}
if ( F_10 ( V_2 ) ) {
if ( F_114 ( V_2 ) )
F_115 ( V_104 ) ;
F_116 ( V_80 ) ;
F_88 ( V_80 ) ;
return 0 ;
}
if ( ! F_76 ( V_2 ) && ! F_121 ( V_2 ) && ! F_20 ( V_2 ) )
goto V_116;
if ( F_76 ( V_2 ) && F_86 ( V_2 ) && F_110 ( V_80 ) ) {
F_78 ( V_20 , V_117 , V_72 ) ;
F_116 ( V_80 ) ;
F_88 ( V_80 ) ;
return 0 ;
}
if ( F_76 ( V_2 ) )
F_102 ( V_80 ) ;
F_122 ( V_2 ) ;
if ( F_90 ( V_2 , V_20 , V_19 , V_21 , & V_80 )
!= V_99 ) {
F_78 ( V_20 , V_118 , V_72 ) ;
V_79 = - V_90 ;
goto V_115;
}
if ( F_20 ( V_2 ) && ! F_95 ( V_2 ) && V_2 -> V_4 == NULL ) {
F_78 ( V_20 , V_119 , V_72 ) ;
V_79 = - V_90 ;
goto V_115;
}
V_116:
V_79 = - V_90 ;
for ( V_87 = V_120 ; ; V_87 ++ )
if ( ( V_2 -> V_21 & V_87 -> V_121 ) == V_87 -> V_79 )
break;
V_106 |= ( V_2 -> V_21 & ( 1UL << V_122 ) ) ;
if ( ! V_87 -> V_121 )
for ( V_87 = V_120 ; ; V_87 ++ )
if ( ( V_106 & V_87 -> V_121 ) == V_87 -> V_79 )
break;
V_79 = F_81 ( V_87 , V_2 , V_20 ) ;
V_115:
F_116 ( V_80 ) ;
return V_79 ;
}
void F_123 ( unsigned long V_20 , int V_19 , int V_21 )
{
struct V_123 * V_124 ;
unsigned long V_125 ;
struct V_126 V_127 = {
. V_20 = V_20 ,
. V_19 = V_19 ,
. V_21 = V_21 ,
} ;
V_124 = & F_124 ( V_123 ) ;
F_125 ( & V_124 -> V_128 , V_125 ) ;
if ( F_126 ( & V_124 -> V_129 , V_127 ) )
F_127 ( F_128 () , & V_124 -> V_130 ) ;
else
F_80 ( L_23 ,
V_20 ) ;
F_129 ( & V_124 -> V_128 , V_125 ) ;
F_130 ( V_123 ) ;
}
static void F_131 ( struct V_131 * V_130 )
{
struct V_123 * V_124 ;
struct V_126 V_127 = { 0 , } ;
unsigned long V_125 ;
int V_132 ;
V_124 = F_132 ( & V_123 ) ;
for (; ; ) {
F_125 ( & V_124 -> V_128 , V_125 ) ;
V_132 = F_133 ( & V_124 -> V_129 , & V_127 ) ;
F_129 ( & V_124 -> V_128 , V_125 ) ;
if ( ! V_132 )
break;
if ( V_127 . V_21 & V_133 )
F_134 ( F_109 ( V_127 . V_20 ) , V_127 . V_21 ) ;
else
F_106 ( V_127 . V_20 , V_127 . V_19 , V_127 . V_21 ) ;
}
}
static int T_3 F_135 ( void )
{
struct V_123 * V_124 ;
int V_134 ;
F_136 (cpu) {
V_124 = & F_137 ( V_123 , V_134 ) ;
F_138 ( & V_124 -> V_128 ) ;
F_139 ( V_124 -> V_129 ) ;
F_140 ( & V_124 -> V_130 , F_131 ) ;
}
return 0 ;
}
int F_141 ( unsigned long V_20 )
{
struct V_1 * V_1 ;
struct V_1 * V_2 ;
int V_135 = 0 ;
unsigned int V_104 ;
if ( ! F_108 ( V_20 ) )
return - V_108 ;
V_2 = F_109 ( V_20 ) ;
V_1 = F_15 ( V_2 ) ;
if ( ! F_113 ( V_2 ) ) {
F_29 ( L_24 , V_20 ) ;
return 0 ;
}
if ( F_82 ( V_1 ) > 1 ) {
F_29 ( L_25 , V_20 ) ;
return 0 ;
}
if ( F_93 ( V_1 ) ) {
F_29 ( L_26 , V_20 ) ;
return 0 ;
}
if ( F_3 ( V_1 ) ) {
F_29 ( L_27 ,
V_20 ) ;
return 0 ;
}
if ( ! F_76 ( V_1 ) && F_85 ( V_1 ) ) {
F_29 ( L_28 , V_20 ) ;
return 0 ;
}
V_104 = 1 << F_14 ( V_1 ) ;
if ( ! F_83 ( V_2 ) ) {
if ( F_76 ( V_1 ) ) {
F_29 ( L_29 , V_20 ) ;
return 0 ;
}
if ( F_114 ( V_2 ) )
F_142 () ;
F_29 ( L_30 , V_20 ) ;
return 0 ;
}
F_112 ( V_1 ) ;
if ( F_114 ( V_1 ) ) {
F_29 ( L_31 , V_20 ) ;
F_115 ( V_104 ) ;
V_135 = 1 ;
if ( F_76 ( V_1 ) )
F_104 ( V_1 ) ;
}
F_116 ( V_1 ) ;
F_88 ( V_1 ) ;
if ( V_135 && ! ( V_20 == F_143 ( 0 ) && F_82 ( V_2 ) == 1 ) )
F_88 ( V_1 ) ;
return 0 ;
}
static struct V_1 * F_144 ( struct V_1 * V_2 , unsigned long V_136 , int * * V_137 )
{
int V_138 = F_25 ( V_2 ) ;
if ( F_76 ( V_2 ) )
return F_145 ( F_146 ( F_15 ( V_2 ) ) ,
V_138 ) ;
else
return F_147 ( V_138 , V_139 , 0 ) ;
}
static int F_148 ( struct V_1 * V_2 , unsigned long V_20 , int V_21 )
{
int V_24 ;
if ( V_21 & V_109 )
return 1 ;
if ( ! F_83 ( V_2 ) ) {
if ( F_76 ( V_2 ) ) {
F_29 ( L_32 , V_140 , V_20 ) ;
V_24 = 0 ;
} else if ( F_23 ( V_2 ) ) {
F_29 ( L_33 , V_140 , V_20 ) ;
V_24 = 0 ;
} else {
F_29 ( L_34 ,
V_140 , V_20 , V_2 -> V_21 ) ;
V_24 = - V_71 ;
}
} else {
V_24 = 1 ;
}
return V_24 ;
}
static int F_149 ( struct V_1 * V_1 , unsigned long V_20 , int V_21 )
{
int V_24 = F_148 ( V_1 , V_20 , V_21 ) ;
if ( V_24 == 1 && ! F_76 ( V_1 ) && ! F_20 ( V_1 ) ) {
F_88 ( V_1 ) ;
F_18 ( V_1 , 1 ) ;
V_24 = F_148 ( V_1 , V_20 , 0 ) ;
if ( ! F_20 ( V_1 ) ) {
F_88 ( V_1 ) ;
F_29 ( L_35 ,
V_20 , V_1 -> V_21 ) ;
return - V_71 ;
}
}
return V_24 ;
}
static int F_150 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_30 ( V_1 ) ;
struct V_1 * V_80 = F_15 ( V_1 ) ;
F_91 ( V_141 ) ;
F_112 ( V_80 ) ;
if ( F_113 ( V_80 ) ) {
F_116 ( V_80 ) ;
F_88 ( V_80 ) ;
F_29 ( L_36 , V_20 ) ;
return - V_90 ;
}
F_116 ( V_80 ) ;
V_24 = F_151 ( V_80 , & V_141 ) ;
F_88 ( V_80 ) ;
if ( ! V_24 ) {
F_29 ( L_37 , V_20 ) ;
return - V_90 ;
}
V_24 = F_152 ( & V_141 , F_144 , NULL , V_142 ,
V_143 , V_144 ) ;
if ( V_24 ) {
F_29 ( L_38 ,
V_20 , V_24 , V_1 -> V_21 ) ;
F_153 ( V_80 ) ;
if ( V_24 > 0 )
V_24 = - V_71 ;
} else {
if ( F_76 ( V_1 ) ) {
F_102 ( V_80 ) ;
F_77 ( V_80 ) ;
F_111 ( 1 << F_14 ( V_80 ) ) ;
} else {
F_103 ( V_1 ) ;
F_154 () ;
}
}
return V_24 ;
}
static int F_155 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_30 ( V_1 ) ;
F_112 ( V_1 ) ;
F_122 ( V_1 ) ;
if ( F_113 ( V_1 ) ) {
F_116 ( V_1 ) ;
F_88 ( V_1 ) ;
F_29 ( L_39 , V_20 ) ;
return - V_90 ;
}
V_24 = F_66 ( V_1 ) ;
F_116 ( V_1 ) ;
if ( V_24 == 1 ) {
F_88 ( V_1 ) ;
F_29 ( L_40 , V_20 ) ;
F_103 ( V_1 ) ;
F_154 () ;
return 0 ;
}
V_24 = F_57 ( V_1 ) ;
F_88 ( V_1 ) ;
if ( ! V_24 ) {
F_91 ( V_141 ) ;
F_156 ( V_1 , V_145 +
F_157 ( V_1 ) ) ;
F_158 ( & V_1 -> V_146 , & V_141 ) ;
V_24 = F_152 ( & V_141 , F_144 , NULL , V_142 ,
V_143 , V_144 ) ;
if ( V_24 ) {
if ( ! F_159 ( & V_141 ) ) {
F_160 ( & V_1 -> V_146 ) ;
F_161 ( V_1 , V_145 +
F_157 ( V_1 ) ) ;
F_162 ( V_1 ) ;
}
F_29 ( L_38 ,
V_20 , V_24 , V_1 -> V_21 ) ;
if ( V_24 > 0 )
V_24 = - V_71 ;
}
} else {
F_29 ( L_41 ,
V_20 , V_24 , F_82 ( V_1 ) , V_1 -> V_21 ) ;
}
return V_24 ;
}
int F_134 ( struct V_1 * V_1 , int V_21 )
{
int V_24 ;
unsigned long V_20 = F_30 ( V_1 ) ;
struct V_1 * V_80 = F_15 ( V_1 ) ;
if ( F_113 ( V_1 ) ) {
F_29 ( L_39 , V_20 ) ;
if ( V_21 & V_109 )
F_88 ( V_1 ) ;
return - V_90 ;
}
if ( ! F_76 ( V_1 ) && F_85 ( V_80 ) ) {
if ( F_55 ( V_80 ) && F_117 ( F_118 ( V_80 ) ) ) {
F_29 ( L_42 ,
V_20 ) ;
if ( V_21 & V_109 )
F_88 ( V_1 ) ;
return - V_90 ;
}
}
F_163 () ;
V_24 = F_149 ( V_1 , V_20 , V_21 ) ;
F_164 () ;
if ( V_24 > 0 ) {
if ( F_76 ( V_1 ) )
V_24 = F_150 ( V_1 , V_21 ) ;
else
V_24 = F_155 ( V_1 , V_21 ) ;
} else if ( V_24 == 0 ) {
if ( F_76 ( V_1 ) ) {
F_102 ( V_80 ) ;
if ( ! F_77 ( V_80 ) )
F_111 ( 1 << F_14 ( V_80 ) ) ;
} else {
if ( ! F_110 ( V_1 ) )
F_154 () ;
}
}
return V_24 ;
}
