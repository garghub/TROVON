bool F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 ) )
return F_3 ( F_4 ( V_1 ) ) ;
return true ;
}
int F_5 ( struct V_2 * V_3 )
{
int V_4 ;
if ( F_6 ( & V_3 -> V_5 ) )
return - V_6 ;
if ( F_7 ( V_3 -> V_7 != V_8 -> V_9 [ V_10 ] . V_7 ) ) {
struct V_7 * V_11 = V_3 -> V_7 ;
struct V_7 * V_12 = F_8 ( V_8 , V_10 ) ;
F_9 ( V_3 -> V_7 , V_12 ) ;
F_10 () ;
F_11 ( V_11 ) ;
}
V_4 = F_12 () ;
F_13 ( & V_3 -> V_13 ) ;
F_14 ( V_3 , V_4 ) ;
F_15 () ;
return 0 ;
}
void F_16 ( struct V_2 * V_3 )
{
F_17 () ;
F_18 ( V_3 ) ;
F_19 ( & V_3 -> V_13 ) ;
F_20 () ;
F_21 ( & V_3 -> V_5 ) ;
}
static void F_22 ( void * V_14 )
{
}
static bool F_23 ( struct V_15 * V_15 , unsigned int V_16 )
{
int V_17 , V_4 , V_18 ;
T_2 V_19 ;
bool V_20 = true ;
struct V_2 * V_3 ;
F_24 ( & V_19 , V_21 ) ;
V_18 = F_12 () ;
F_25 (i, vcpu, kvm) {
F_26 ( V_16 , V_3 ) ;
V_4 = V_3 -> V_4 ;
F_27 () ;
if ( V_19 != NULL && V_4 != - 1 && V_4 != V_18 &&
F_28 ( V_3 ) != V_22 )
F_29 ( V_4 , V_19 ) ;
}
if ( F_7 ( V_19 == NULL ) )
F_30 ( V_23 , F_22 , NULL , 1 ) ;
else if ( ! F_31 ( V_19 ) )
F_30 ( V_19 , F_22 , NULL , 1 ) ;
else
V_20 = false ;
F_15 () ;
F_32 ( V_19 ) ;
return V_20 ;
}
void F_33 ( struct V_15 * V_15 )
{
long V_24 = V_15 -> V_25 ;
F_27 () ;
if ( F_23 ( V_15 , V_26 ) )
++ V_15 -> V_27 . V_28 ;
F_34 ( & V_15 -> V_25 , V_24 , 0 ) ;
}
void F_35 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_29 ) ;
}
void F_36 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_30 ) ;
}
void F_37 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_31 ) ;
}
int F_38 ( struct V_2 * V_3 , struct V_15 * V_15 , unsigned V_32 )
{
struct V_33 * V_33 ;
int V_34 ;
F_39 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_35 = V_32 ;
V_3 -> V_7 = NULL ;
F_40 ( & V_3 -> V_36 ) ;
F_41 ( V_3 ) ;
V_33 = F_42 ( V_37 | V_38 ) ;
if ( ! V_33 ) {
V_34 = - V_39 ;
goto V_40;
}
V_3 -> V_41 = F_43 ( V_33 ) ;
F_44 ( V_3 , false ) ;
F_45 ( V_3 , false ) ;
V_3 -> V_42 = false ;
V_34 = F_46 ( V_3 ) ;
if ( V_34 < 0 )
goto V_43;
return 0 ;
V_43:
F_47 ( ( unsigned long ) V_3 -> V_41 ) ;
V_40:
return V_34 ;
}
void F_48 ( struct V_2 * V_3 )
{
F_11 ( V_3 -> V_7 ) ;
F_49 ( V_3 ) ;
F_47 ( ( unsigned long ) V_3 -> V_41 ) ;
}
static inline struct V_15 * F_50 ( struct V_44 * V_45 )
{
return F_51 ( V_45 , struct V_15 , V_44 ) ;
}
static void F_52 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_49 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
V_49 = F_55 ( V_15 , V_48 ) | V_15 -> V_25 ;
if ( V_49 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_58 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 ,
T_3 V_54 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
F_59 ( V_15 , V_48 , V_54 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_60 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_49 = 0 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_57 ++ ;
V_49 = F_61 ( V_15 , V_55 , V_56 ) ;
V_49 |= V_15 -> V_25 ;
if ( V_49 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_62 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
F_63 () ;
V_15 -> V_57 -- ;
F_56 ( & V_15 -> V_52 ) ;
F_64 ( V_15 -> V_57 < 0 ) ;
}
static int F_65 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_58 = F_66 ( V_15 , V_48 ) ;
if ( V_58 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
return V_58 ;
}
static int F_67 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_58 = F_68 ( V_15 , V_48 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
return V_58 ;
}
static void F_69 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_70 ( V_15 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static int F_71 ( struct V_15 * V_15 )
{
V_15 -> V_44 . V_59 = & V_60 ;
return F_72 ( & V_15 -> V_44 , V_8 -> V_47 ) ;
}
static int F_71 ( struct V_15 * V_15 )
{
return 0 ;
}
static void F_73 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_61 * V_62 = V_15 -> V_63 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ )
V_62 -> V_65 [ V_17 ] = V_62 -> V_63 [ V_17 ] . V_32 = V_17 ;
}
static struct V_15 * F_74 ( unsigned long type )
{
int V_34 , V_17 ;
struct V_15 * V_15 = F_75 () ;
if ( ! V_15 )
return F_76 ( - V_39 ) ;
V_34 = F_77 ( V_15 , type ) ;
if ( V_34 )
goto V_66;
V_34 = F_78 () ;
if ( V_34 )
goto V_66;
#ifdef F_79
F_80 ( & V_15 -> V_67 ) ;
F_80 ( & V_15 -> V_68 ) ;
#endif
F_81 ( V_64 > V_69 ) ;
V_34 = - V_39 ;
V_15 -> V_63 = F_82 ( sizeof( struct V_61 ) , V_37 ) ;
if ( ! V_15 -> V_63 )
goto V_70;
F_73 ( V_15 ) ;
if ( F_83 ( & V_15 -> V_51 ) )
goto V_70;
if ( F_83 ( & V_15 -> V_71 ) )
goto V_72;
for ( V_17 = 0 ; V_17 < V_73 ; V_17 ++ ) {
V_15 -> V_74 [ V_17 ] = F_82 ( sizeof( struct V_75 ) ,
V_37 ) ;
if ( ! V_15 -> V_74 [ V_17 ] )
goto V_76;
}
F_84 ( & V_15 -> V_52 ) ;
V_15 -> V_47 = V_8 -> V_47 ;
F_85 ( & V_15 -> V_47 -> V_77 ) ;
F_86 ( V_15 ) ;
F_39 ( & V_15 -> V_78 ) ;
F_39 ( & V_15 -> V_79 ) ;
F_39 ( & V_15 -> V_80 ) ;
F_87 ( & V_15 -> V_81 , 1 ) ;
F_88 ( & V_15 -> V_82 ) ;
V_34 = F_71 ( V_15 ) ;
if ( V_34 )
goto V_76;
F_54 ( & V_83 ) ;
F_89 ( & V_15 -> V_84 , & V_84 ) ;
F_56 ( & V_83 ) ;
return V_15 ;
V_76:
F_90 ( & V_15 -> V_71 ) ;
V_72:
F_90 ( & V_15 -> V_51 ) ;
V_70:
F_91 () ;
V_66:
for ( V_17 = 0 ; V_17 < V_73 ; V_17 ++ )
F_92 ( V_15 -> V_74 [ V_17 ] ) ;
F_92 ( V_15 -> V_63 ) ;
F_93 ( V_15 ) ;
return F_76 ( V_34 ) ;
}
void * F_94 ( unsigned long V_85 )
{
if ( V_85 > V_86 )
return F_95 ( V_85 ) ;
else
return F_82 ( V_85 , V_37 ) ;
}
void F_96 ( const void * V_87 )
{
if ( F_97 ( V_87 ) )
F_98 ( V_87 ) ;
else
F_92 ( V_87 ) ;
}
static void F_99 ( struct V_88 * V_89 )
{
if ( ! V_89 -> V_90 )
return;
F_96 ( V_89 -> V_90 ) ;
V_89 -> V_90 = NULL ;
}
static void F_100 ( struct V_15 * V_15 , struct V_88 * free ,
struct V_88 * V_91 )
{
if ( ! V_91 || free -> V_90 != V_91 -> V_90 )
F_99 ( free ) ;
F_101 ( V_15 , free , V_91 ) ;
free -> V_92 = 0 ;
}
static void F_102 ( struct V_15 * V_15 )
{
struct V_61 * V_62 = V_15 -> V_63 ;
struct V_88 * V_89 ;
F_103 (memslot, slots)
F_100 ( V_15 , V_89 , NULL ) ;
F_92 ( V_15 -> V_63 ) ;
}
static void F_104 ( struct V_15 * V_15 )
{
struct V_93 * V_94 , * V_95 ;
F_105 (node, tmp, &kvm->devices) {
struct V_96 * V_97 =
F_106 ( V_94 , struct V_96 , V_98 ) ;
F_107 ( V_94 ) ;
V_97 -> V_59 -> V_99 ( V_97 ) ;
}
}
static void F_108 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_46 * V_47 = V_15 -> V_47 ;
F_109 ( V_15 ) ;
F_54 ( & V_83 ) ;
F_107 ( & V_15 -> V_84 ) ;
F_56 ( & V_83 ) ;
F_110 ( V_15 ) ;
for ( V_17 = 0 ; V_17 < V_73 ; V_17 ++ )
F_111 ( V_15 -> V_74 [ V_17 ] ) ;
F_112 ( V_15 ) ;
#if F_113 ( V_100 ) && F_113 ( V_101 )
F_114 ( & V_15 -> V_44 , V_15 -> V_47 ) ;
#else
F_70 ( V_15 ) ;
#endif
F_115 ( V_15 ) ;
F_104 ( V_15 ) ;
F_102 ( V_15 ) ;
F_90 ( & V_15 -> V_71 ) ;
F_90 ( & V_15 -> V_51 ) ;
F_93 ( V_15 ) ;
F_91 () ;
F_116 ( V_47 ) ;
}
void F_117 ( struct V_15 * V_15 )
{
F_85 ( & V_15 -> V_81 ) ;
}
void F_118 ( struct V_15 * V_15 )
{
if ( F_119 ( & V_15 -> V_81 ) )
F_108 ( V_15 ) ;
}
static int F_120 ( struct V_102 * V_102 , struct V_103 * V_104 )
{
struct V_15 * V_15 = V_104 -> V_105 ;
F_121 ( V_15 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
static int F_122 ( struct V_88 * V_89 )
{
unsigned long V_106 = 2 * F_123 ( V_89 ) ;
V_89 -> V_90 = F_94 ( V_106 ) ;
if ( ! V_89 -> V_90 )
return - V_39 ;
return 0 ;
}
static int F_124 ( const void * V_107 , const void * V_108 )
{
struct V_88 * V_109 , * V_110 ;
V_109 = (struct V_88 * ) V_107 ;
V_110 = (struct V_88 * ) V_108 ;
if ( V_109 -> V_92 < V_110 -> V_92 )
return 1 ;
if ( V_109 -> V_92 > V_110 -> V_92 )
return - 1 ;
return 0 ;
}
static void F_125 ( struct V_61 * V_62 )
{
int V_17 ;
F_126 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_88 ) , F_124 , NULL ) ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_17 ] . V_32 ] = V_17 ;
}
static void F_127 ( struct V_61 * V_62 ,
struct V_88 * V_111 ,
T_4 V_112 )
{
if ( V_111 ) {
int V_32 = V_111 -> V_32 ;
struct V_88 * V_113 = F_128 ( V_62 , V_32 ) ;
unsigned long V_92 = V_113 -> V_92 ;
* V_113 = * V_111 ;
if ( V_111 -> V_92 != V_92 )
F_125 ( V_62 ) ;
}
V_62 -> V_114 = V_112 + 1 ;
}
static int F_129 ( struct V_115 * V_116 )
{
T_5 V_117 = V_118 ;
#ifdef F_130
V_117 |= V_119 ;
#endif
if ( V_116 -> V_120 & ~ V_117 )
return - V_121 ;
return 0 ;
}
static struct V_61 * F_131 ( struct V_15 * V_15 ,
struct V_61 * V_62 , struct V_88 * V_111 )
{
struct V_61 * V_122 = V_15 -> V_63 ;
F_127 ( V_62 , V_111 , V_15 -> V_63 -> V_114 ) ;
F_9 ( V_15 -> V_63 , V_62 ) ;
F_132 ( & V_15 -> V_51 ) ;
F_133 ( V_15 ) ;
return V_122 ;
}
int F_134 ( struct V_15 * V_15 ,
struct V_115 * V_116 )
{
int V_34 ;
T_6 V_123 ;
unsigned long V_92 ;
struct V_88 * V_124 ;
struct V_88 V_113 , V_111 ;
struct V_61 * V_62 = NULL , * V_122 ;
enum V_125 V_126 ;
V_34 = F_129 ( V_116 ) ;
if ( V_34 )
goto V_127;
V_34 = - V_121 ;
if ( V_116 -> V_128 & ( V_86 - 1 ) )
goto V_127;
if ( V_116 -> V_129 & ( V_86 - 1 ) )
goto V_127;
if ( ( V_116 -> V_124 < V_130 ) &&
( ( V_116 -> V_131 & ( V_86 - 1 ) ) ||
! F_135 ( V_132 ,
( void V_133 * ) ( unsigned long ) V_116 -> V_131 ,
V_116 -> V_128 ) ) )
goto V_127;
if ( V_116 -> V_124 >= V_64 )
goto V_127;
if ( V_116 -> V_129 + V_116 -> V_128 < V_116 -> V_129 )
goto V_127;
V_124 = F_128 ( V_15 -> V_63 , V_116 -> V_124 ) ;
V_123 = V_116 -> V_129 >> V_134 ;
V_92 = V_116 -> V_128 >> V_134 ;
V_34 = - V_121 ;
if ( V_92 > V_135 )
goto V_127;
if ( ! V_92 )
V_116 -> V_120 &= ~ V_118 ;
V_111 = V_113 = * V_124 ;
V_111 . V_32 = V_116 -> V_124 ;
V_111 . V_123 = V_123 ;
V_111 . V_92 = V_92 ;
V_111 . V_120 = V_116 -> V_120 ;
V_34 = - V_121 ;
if ( V_92 ) {
if ( ! V_113 . V_92 )
V_126 = V_136 ;
else {
if ( ( V_116 -> V_131 != V_113 . V_131 ) ||
( V_92 != V_113 . V_92 ) ||
( ( V_111 . V_120 ^ V_113 . V_120 ) & V_119 ) )
goto V_127;
if ( V_123 != V_113 . V_123 )
V_126 = V_137 ;
else if ( V_111 . V_120 != V_113 . V_120 )
V_126 = V_138 ;
else {
V_34 = 0 ;
goto V_127;
}
}
} else if ( V_113 . V_92 ) {
V_126 = V_139 ;
} else
goto V_127;
if ( ( V_126 == V_136 ) || ( V_126 == V_137 ) ) {
V_34 = - V_140 ;
F_103 (slot, kvm->memslots) {
if ( ( V_124 -> V_32 >= V_130 ) ||
( V_124 -> V_32 == V_116 -> V_124 ) )
continue;
if ( ! ( ( V_123 + V_92 <= V_124 -> V_123 ) ||
( V_123 >= V_124 -> V_123 + V_124 -> V_92 ) ) )
goto V_127;
}
}
if ( ! ( V_111 . V_120 & V_118 ) )
V_111 . V_90 = NULL ;
V_34 = - V_39 ;
if ( V_126 == V_136 ) {
V_111 . V_131 = V_116 -> V_131 ;
if ( F_136 ( V_15 , & V_111 , V_92 ) )
goto V_141;
}
if ( ( V_111 . V_120 & V_118 ) && ! V_111 . V_90 ) {
if ( F_122 ( & V_111 ) < 0 )
goto V_141;
}
if ( ( V_126 == V_139 ) || ( V_126 == V_137 ) ) {
V_34 = - V_39 ;
V_62 = F_137 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_141;
V_124 = F_128 ( V_62 , V_116 -> V_124 ) ;
V_124 -> V_120 |= V_142 ;
V_122 = F_131 ( V_15 , V_62 , NULL ) ;
F_138 ( V_15 , & V_113 ) ;
F_139 ( V_15 , V_124 ) ;
V_62 = V_122 ;
}
V_34 = F_140 ( V_15 , & V_111 , V_116 , V_126 ) ;
if ( V_34 )
goto V_143;
V_34 = - V_39 ;
if ( ! V_62 ) {
V_62 = F_137 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_141;
}
if ( V_126 == V_139 ) {
V_111 . V_90 = NULL ;
memset ( & V_111 . V_144 , 0 , sizeof( V_111 . V_144 ) ) ;
}
V_122 = F_131 ( V_15 , V_62 , & V_111 ) ;
F_141 ( V_15 , V_116 , & V_113 , V_126 ) ;
F_100 ( V_15 , & V_113 , & V_111 ) ;
F_92 ( V_122 ) ;
if ( ( V_126 == V_136 ) || ( V_126 == V_137 ) ) {
V_34 = F_142 ( V_15 , & V_111 ) ;
return V_34 ;
}
return 0 ;
V_143:
F_92 ( V_62 ) ;
V_141:
F_100 ( V_15 , & V_111 , & V_113 ) ;
V_127:
return V_34 ;
}
int F_143 ( struct V_15 * V_15 ,
struct V_115 * V_116 )
{
int V_34 ;
F_144 ( & V_15 -> V_80 ) ;
V_34 = F_134 ( V_15 , V_116 ) ;
F_21 ( & V_15 -> V_80 ) ;
return V_34 ;
}
static int F_145 ( struct V_15 * V_15 ,
struct V_115 * V_116 )
{
if ( V_116 -> V_124 >= V_130 )
return - V_121 ;
return F_143 ( V_15 , V_116 ) ;
}
int F_146 ( struct V_15 * V_15 ,
struct V_145 * log , int * V_146 )
{
struct V_88 * V_89 ;
int V_34 , V_17 ;
unsigned long V_147 ;
unsigned long V_148 = 0 ;
V_34 = - V_121 ;
if ( log -> V_124 >= V_130 )
goto V_127;
V_89 = F_128 ( V_15 -> V_63 , log -> V_124 ) ;
V_34 = - V_149 ;
if ( ! V_89 -> V_90 )
goto V_127;
V_147 = F_123 ( V_89 ) ;
for ( V_17 = 0 ; ! V_148 && V_17 < V_147 / sizeof( long ) ; ++ V_17 )
V_148 = V_89 -> V_90 [ V_17 ] ;
V_34 = - V_150 ;
if ( F_147 ( log -> V_90 , V_89 -> V_90 , V_147 ) )
goto V_127;
if ( V_148 )
* V_146 = 1 ;
V_34 = 0 ;
V_127:
return V_34 ;
}
bool F_148 ( void )
{
return V_151 ;
}
void F_149 ( void )
{
V_151 = false ;
}
struct V_88 * F_150 ( struct V_15 * V_15 , T_6 V_152 )
{
return F_151 ( V_61 ( V_15 ) , V_152 ) ;
}
int F_152 ( struct V_15 * V_15 , T_6 V_152 )
{
struct V_88 * V_89 = F_150 ( V_15 , V_152 ) ;
if ( ! V_89 || V_89 -> V_32 >= V_130 ||
V_89 -> V_120 & V_142 )
return 0 ;
return 1 ;
}
unsigned long F_153 ( struct V_15 * V_15 , T_6 V_152 )
{
struct V_153 * V_154 ;
unsigned long V_87 , V_85 ;
V_85 = V_86 ;
V_87 = F_154 ( V_15 , V_152 ) ;
if ( F_155 ( V_87 ) )
return V_86 ;
F_156 ( & V_8 -> V_47 -> V_155 ) ;
V_154 = F_157 ( V_8 -> V_47 , V_87 ) ;
if ( ! V_154 )
goto V_127;
V_85 = F_158 ( V_154 ) ;
V_127:
F_159 ( & V_8 -> V_47 -> V_155 ) ;
return V_85 ;
}
static bool F_160 ( struct V_88 * V_124 )
{
return V_124 -> V_120 & V_119 ;
}
static unsigned long F_161 ( struct V_88 * V_124 , T_6 V_152 ,
T_6 * V_156 , bool V_157 )
{
if ( ! V_124 || V_124 -> V_120 & V_142 )
return V_158 ;
if ( F_160 ( V_124 ) && V_157 )
return V_159 ;
if ( V_156 )
* V_156 = V_124 -> V_92 - ( V_152 - V_124 -> V_123 ) ;
return F_162 ( V_124 , V_152 ) ;
}
static unsigned long F_163 ( struct V_88 * V_124 , T_6 V_152 ,
T_6 * V_156 )
{
return F_161 ( V_124 , V_152 , V_156 , true ) ;
}
unsigned long F_164 ( struct V_88 * V_124 ,
T_6 V_152 )
{
return F_163 ( V_124 , V_152 , NULL ) ;
}
unsigned long F_154 ( struct V_15 * V_15 , T_6 V_152 )
{
return F_163 ( F_150 ( V_15 , V_152 ) , V_152 , NULL ) ;
}
unsigned long F_165 ( struct V_15 * V_15 , T_6 V_152 , bool * V_160 )
{
struct V_88 * V_124 = F_150 ( V_15 , V_152 ) ;
unsigned long V_161 = F_161 ( V_124 , V_152 , NULL , false ) ;
if ( ! F_155 ( V_161 ) && V_160 )
* V_160 = ! F_160 ( V_124 ) ;
return V_161 ;
}
static int F_166 ( void * V_162 , void V_133 * V_161 , int V_163 )
{
return F_167 ( V_162 , V_161 , V_163 ) ;
}
static int F_168 ( void * V_162 , void V_133 * V_161 , int V_163 )
{
return F_169 ( V_162 , V_161 , V_163 ) ;
}
static int F_170 ( struct V_164 * V_165 , struct V_46 * V_47 ,
unsigned long V_55 , int V_157 , struct V_33 * * V_33 )
{
int V_120 = V_166 | V_167 | V_168 | V_169 ;
if ( V_157 )
V_120 |= V_170 ;
return F_171 ( V_165 , V_47 , V_55 , 1 , V_120 , V_33 , NULL , NULL ) ;
}
static inline int F_172 ( unsigned long V_87 )
{
int V_171 , V_120 = V_166 | V_168 | V_170 ;
V_171 = F_171 ( V_8 , V_8 -> V_47 , V_87 , 1 ,
V_120 , NULL , NULL , NULL ) ;
return V_171 == - V_172 ;
}
static bool F_173 ( unsigned long V_87 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_160 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_92 ;
if ( ! ( V_174 || V_173 ) )
return false ;
if ( ! ( V_175 || V_160 ) )
return false ;
V_92 = F_174 ( V_87 , 1 , 1 , V_33 ) ;
if ( V_92 == 1 ) {
* V_1 = F_175 ( V_33 [ 0 ] ) ;
if ( V_160 )
* V_160 = true ;
return true ;
}
return false ;
}
static int F_176 ( unsigned long V_87 , bool * V_174 , bool V_175 ,
bool * V_160 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_92 = 0 ;
F_177 () ;
if ( V_160 )
* V_160 = V_175 ;
if ( V_174 ) {
F_156 ( & V_8 -> V_47 -> V_155 ) ;
V_92 = F_170 ( V_8 , V_8 -> V_47 ,
V_87 , V_175 , V_33 ) ;
F_159 ( & V_8 -> V_47 -> V_155 ) ;
} else
V_92 = F_178 ( V_87 , 1 , V_175 ,
V_33 ) ;
if ( V_92 != 1 )
return V_92 ;
if ( F_7 ( ! V_175 ) && V_160 ) {
struct V_33 * V_176 [ 1 ] ;
V_92 = F_174 ( V_87 , 1 , 1 , V_176 ) ;
if ( V_92 == 1 ) {
* V_160 = true ;
F_179 ( V_33 [ 0 ] ) ;
V_33 [ 0 ] = V_176 [ 0 ] ;
}
V_92 = 1 ;
}
* V_1 = F_175 ( V_33 [ 0 ] ) ;
return V_92 ;
}
static bool F_180 ( struct V_153 * V_154 , bool V_175 )
{
if ( F_7 ( ! ( V_154 -> V_177 & V_178 ) ) )
return false ;
if ( V_175 && ( F_7 ( ! ( V_154 -> V_177 & V_179 ) ) ) )
return false ;
return true ;
}
static T_1 F_181 ( unsigned long V_87 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_160 )
{
struct V_153 * V_154 ;
T_1 V_1 = 0 ;
int V_92 ;
F_64 ( V_173 && V_174 ) ;
if ( F_173 ( V_87 , V_173 , V_174 , V_175 , V_160 , & V_1 ) )
return V_1 ;
if ( V_173 )
return V_180 ;
V_92 = F_176 ( V_87 , V_174 , V_175 , V_160 , & V_1 ) ;
if ( V_92 == 1 )
return V_1 ;
F_156 ( & V_8 -> V_47 -> V_155 ) ;
if ( V_92 == - V_172 ||
( ! V_174 && F_172 ( V_87 ) ) ) {
V_1 = V_181 ;
goto exit;
}
V_154 = F_182 ( V_8 -> V_47 , V_87 , V_87 + 1 ) ;
if ( V_154 == NULL )
V_1 = V_180 ;
else if ( ( V_154 -> V_177 & V_182 ) ) {
V_1 = ( ( V_87 - V_154 -> V_183 ) >> V_134 ) +
V_154 -> V_184 ;
F_64 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_174 && F_180 ( V_154 , V_175 ) )
* V_174 = true ;
V_1 = V_180 ;
}
exit:
F_159 ( & V_8 -> V_47 -> V_155 ) ;
return V_1 ;
}
static T_1
F_183 ( struct V_88 * V_124 , T_6 V_152 , bool V_173 ,
bool * V_174 , bool V_175 , bool * V_160 )
{
unsigned long V_87 = F_161 ( V_124 , V_152 , NULL , V_175 ) ;
if ( V_87 == V_159 )
return V_185 ;
if ( F_155 ( V_87 ) )
return V_186 ;
if ( V_160 && F_160 ( V_124 ) ) {
* V_160 = false ;
V_160 = NULL ;
}
return F_181 ( V_87 , V_173 , V_174 , V_175 ,
V_160 ) ;
}
static T_1 F_184 ( struct V_15 * V_15 , T_6 V_152 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_160 )
{
struct V_88 * V_124 ;
if ( V_174 )
* V_174 = false ;
V_124 = F_150 ( V_15 , V_152 ) ;
return F_183 ( V_124 , V_152 , V_173 , V_174 , V_175 ,
V_160 ) ;
}
T_1 F_185 ( struct V_15 * V_15 , T_6 V_152 )
{
return F_184 ( V_15 , V_152 , true , NULL , true , NULL ) ;
}
T_1 F_186 ( struct V_15 * V_15 , T_6 V_152 , bool * V_174 ,
bool V_175 , bool * V_160 )
{
return F_184 ( V_15 , V_152 , false , V_174 , V_175 , V_160 ) ;
}
T_1 F_187 ( struct V_15 * V_15 , T_6 V_152 )
{
return F_184 ( V_15 , V_152 , false , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_15 * V_15 , T_6 V_152 , bool V_175 ,
bool * V_160 )
{
return F_184 ( V_15 , V_152 , false , NULL , V_175 , V_160 ) ;
}
T_1 F_189 ( struct V_88 * V_124 , T_6 V_152 )
{
return F_183 ( V_124 , V_152 , false , NULL , true , NULL ) ;
}
T_1 F_190 ( struct V_88 * V_124 , T_6 V_152 )
{
return F_183 ( V_124 , V_152 , true , NULL , true , NULL ) ;
}
int F_191 ( struct V_15 * V_15 , T_6 V_152 , struct V_33 * * V_187 ,
int V_156 )
{
unsigned long V_87 ;
T_6 V_188 ;
V_87 = F_163 ( F_150 ( V_15 , V_152 ) , V_152 , & V_188 ) ;
if ( F_155 ( V_87 ) )
return - 1 ;
if ( V_188 < V_156 )
return 0 ;
return F_174 ( V_87 , V_156 , 1 , V_187 ) ;
}
static struct V_33 * F_192 ( T_1 V_1 )
{
if ( F_193 ( V_1 ) )
return V_189 ;
if ( F_1 ( V_1 ) ) {
F_194 ( 1 ) ;
return V_189 ;
}
return F_4 ( V_1 ) ;
}
struct V_33 * F_195 ( struct V_15 * V_15 , T_6 V_152 )
{
T_1 V_1 ;
V_1 = F_187 ( V_15 , V_152 ) ;
return F_192 ( V_1 ) ;
}
void F_196 ( struct V_33 * V_33 )
{
F_194 ( F_197 ( V_33 ) ) ;
F_198 ( F_175 ( V_33 ) ) ;
}
void F_198 ( T_1 V_1 )
{
if ( ! F_193 ( V_1 ) && ! F_1 ( V_1 ) )
F_179 ( F_4 ( V_1 ) ) ;
}
void F_199 ( struct V_33 * V_33 )
{
F_194 ( F_197 ( V_33 ) ) ;
F_200 ( F_175 ( V_33 ) ) ;
}
static void F_200 ( T_1 V_1 )
{
F_201 ( V_1 ) ;
F_198 ( V_1 ) ;
}
void F_201 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_33 * V_33 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_33 ) )
F_202 ( V_33 ) ;
}
}
void F_203 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_204 ( F_4 ( V_1 ) ) ;
}
void F_205 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_206 ( F_4 ( V_1 ) ) ;
}
static int F_207 ( unsigned long V_163 , int V_190 )
{
if ( V_163 > V_86 - V_190 )
return V_86 - V_190 ;
else
return V_163 ;
}
int F_208 ( struct V_15 * V_15 , T_6 V_152 , void * V_162 , int V_190 ,
int V_163 )
{
int V_34 ;
unsigned long V_87 ;
V_87 = F_165 ( V_15 , V_152 , NULL ) ;
if ( F_155 ( V_87 ) )
return - V_150 ;
V_34 = F_166 ( V_162 , ( void V_133 * ) V_87 + V_190 , V_163 ) ;
if ( V_34 )
return - V_150 ;
return 0 ;
}
int F_209 ( struct V_15 * V_15 , T_7 V_191 , void * V_162 , unsigned long V_163 )
{
T_6 V_152 = V_191 >> V_134 ;
int V_192 ;
int V_190 = F_210 ( V_191 ) ;
int V_193 ;
while ( ( V_192 = F_207 ( V_163 , V_190 ) ) != 0 ) {
V_193 = F_208 ( V_15 , V_152 , V_162 , V_190 , V_192 ) ;
if ( V_193 < 0 )
return V_193 ;
V_190 = 0 ;
V_163 -= V_192 ;
V_162 += V_192 ;
++ V_152 ;
}
return 0 ;
}
int F_211 ( struct V_15 * V_15 , T_7 V_191 , void * V_162 ,
unsigned long V_163 )
{
int V_34 ;
unsigned long V_87 ;
T_6 V_152 = V_191 >> V_134 ;
int V_190 = F_210 ( V_191 ) ;
V_87 = F_165 ( V_15 , V_152 , NULL ) ;
if ( F_155 ( V_87 ) )
return - V_150 ;
F_212 () ;
V_34 = F_168 ( V_162 , ( void V_133 * ) V_87 + V_190 , V_163 ) ;
F_213 () ;
if ( V_34 )
return - V_150 ;
return 0 ;
}
int F_214 ( struct V_15 * V_15 , T_6 V_152 , const void * V_162 ,
int V_190 , int V_163 )
{
int V_34 ;
unsigned long V_87 ;
V_87 = F_154 ( V_15 , V_152 ) ;
if ( F_155 ( V_87 ) )
return - V_150 ;
V_34 = F_215 ( ( void V_133 * ) V_87 + V_190 , V_162 , V_163 ) ;
if ( V_34 )
return - V_150 ;
F_216 ( V_15 , V_152 ) ;
return 0 ;
}
int F_217 ( struct V_15 * V_15 , T_7 V_191 , const void * V_162 ,
unsigned long V_163 )
{
T_6 V_152 = V_191 >> V_134 ;
int V_192 ;
int V_190 = F_210 ( V_191 ) ;
int V_193 ;
while ( ( V_192 = F_207 ( V_163 , V_190 ) ) != 0 ) {
V_193 = F_214 ( V_15 , V_152 , V_162 , V_190 , V_192 ) ;
if ( V_193 < 0 )
return V_193 ;
V_190 = 0 ;
V_163 -= V_192 ;
V_162 += V_192 ;
++ V_152 ;
}
return 0 ;
}
int F_218 ( struct V_15 * V_15 , struct V_194 * V_195 ,
T_7 V_191 , unsigned long V_163 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_190 = F_210 ( V_191 ) ;
T_6 V_196 = V_191 >> V_134 ;
T_6 V_197 = ( V_191 + V_163 - 1 ) >> V_134 ;
T_6 V_198 = V_197 - V_196 + 1 ;
T_6 V_199 ;
V_195 -> V_191 = V_191 ;
V_195 -> V_114 = V_62 -> V_114 ;
V_195 -> V_163 = V_163 ;
V_195 -> V_89 = F_150 ( V_15 , V_196 ) ;
V_195 -> V_161 = F_163 ( V_195 -> V_89 , V_196 , & V_199 ) ;
if ( ! F_155 ( V_195 -> V_161 ) && V_199 >= V_198 ) {
V_195 -> V_161 += V_190 ;
} else {
while ( V_196 <= V_197 ) {
V_195 -> V_89 = F_150 ( V_15 , V_196 ) ;
V_195 -> V_161 = F_163 ( V_195 -> V_89 , V_196 ,
& V_199 ) ;
if ( F_155 ( V_195 -> V_161 ) )
return - V_150 ;
V_196 += V_199 ;
}
V_195 -> V_89 = NULL ;
}
return 0 ;
}
int F_219 ( struct V_15 * V_15 , struct V_194 * V_195 ,
void * V_162 , unsigned long V_163 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_64 ( V_163 > V_195 -> V_163 ) ;
if ( V_62 -> V_114 != V_195 -> V_114 )
F_218 ( V_15 , V_195 , V_195 -> V_191 , V_195 -> V_163 ) ;
if ( F_7 ( ! V_195 -> V_89 ) )
return F_217 ( V_15 , V_195 -> V_191 , V_162 , V_163 ) ;
if ( F_155 ( V_195 -> V_161 ) )
return - V_150 ;
V_34 = F_215 ( ( void V_133 * ) V_195 -> V_161 , V_162 , V_163 ) ;
if ( V_34 )
return - V_150 ;
F_220 ( V_15 , V_195 -> V_89 , V_195 -> V_191 >> V_134 ) ;
return 0 ;
}
int F_221 ( struct V_15 * V_15 , struct V_194 * V_195 ,
void * V_162 , unsigned long V_163 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_64 ( V_163 > V_195 -> V_163 ) ;
if ( V_62 -> V_114 != V_195 -> V_114 )
F_218 ( V_15 , V_195 , V_195 -> V_191 , V_195 -> V_163 ) ;
if ( F_7 ( ! V_195 -> V_89 ) )
return F_209 ( V_15 , V_195 -> V_191 , V_162 , V_163 ) ;
if ( F_155 ( V_195 -> V_161 ) )
return - V_150 ;
V_34 = F_167 ( V_162 , ( void V_133 * ) V_195 -> V_161 , V_163 ) ;
if ( V_34 )
return - V_150 ;
return 0 ;
}
int F_222 ( struct V_15 * V_15 , T_6 V_152 , int V_190 , int V_163 )
{
const void * V_200 = ( const void * ) F_223 ( F_224 ( F_225 ( 0 ) ) ) ;
return F_214 ( V_15 , V_152 , V_200 , V_190 , V_163 ) ;
}
int F_226 ( struct V_15 * V_15 , T_7 V_191 , unsigned long V_163 )
{
T_6 V_152 = V_191 >> V_134 ;
int V_192 ;
int V_190 = F_210 ( V_191 ) ;
int V_193 ;
while ( ( V_192 = F_207 ( V_163 , V_190 ) ) != 0 ) {
V_193 = F_222 ( V_15 , V_152 , V_190 , V_192 ) ;
if ( V_193 < 0 )
return V_193 ;
V_190 = 0 ;
V_163 -= V_192 ;
++ V_152 ;
}
return 0 ;
}
static void F_220 ( struct V_15 * V_15 ,
struct V_88 * V_89 ,
T_6 V_152 )
{
if ( V_89 && V_89 -> V_90 ) {
unsigned long V_201 = V_152 - V_89 -> V_123 ;
F_227 ( V_201 , V_89 -> V_90 ) ;
}
}
void F_216 ( struct V_15 * V_15 , T_6 V_152 )
{
struct V_88 * V_89 ;
V_89 = F_150 ( V_15 , V_152 ) ;
F_220 ( V_15 , V_89 , V_152 ) ;
}
void F_228 ( struct V_2 * V_3 )
{
F_229 ( V_202 ) ;
for (; ; ) {
F_230 ( & V_3 -> V_36 , & V_202 , V_203 ) ;
if ( F_231 ( V_3 ) ) {
F_26 ( V_204 , V_3 ) ;
break;
}
if ( F_232 ( V_3 ) )
break;
if ( F_233 ( V_8 ) )
break;
F_234 () ;
}
F_235 ( & V_3 -> V_36 , & V_202 ) ;
}
void F_236 ( struct V_2 * V_3 )
{
int V_18 ;
int V_4 = V_3 -> V_4 ;
T_8 * V_205 ;
V_205 = F_237 ( V_3 ) ;
if ( F_238 ( V_205 ) ) {
F_239 ( V_205 ) ;
++ V_3 -> V_27 . V_206 ;
}
V_18 = F_12 () ;
if ( V_4 != V_18 && ( unsigned ) V_4 < V_207 && F_240 ( V_4 ) )
if ( F_241 ( V_3 ) )
F_242 ( V_4 ) ;
F_15 () ;
}
int F_243 ( struct V_2 * V_208 )
{
struct V_7 * V_7 ;
struct V_164 * V_209 = NULL ;
int V_193 = 0 ;
F_244 () ;
V_7 = F_245 ( V_208 -> V_7 ) ;
if ( V_7 )
V_209 = F_246 ( V_208 -> V_7 , V_10 ) ;
F_247 () ;
if ( ! V_209 )
return V_193 ;
if ( V_209 -> V_120 & V_210 ) {
F_248 ( V_209 ) ;
return V_193 ;
}
V_193 = F_249 ( V_209 , 1 ) ;
F_248 ( V_209 ) ;
return V_193 ;
}
static bool F_250 ( struct V_2 * V_3 )
{
#ifdef F_251
bool V_211 ;
V_211 = ! V_3 -> V_212 . V_213 ||
( V_3 -> V_212 . V_213 &&
V_3 -> V_212 . V_214 ) ;
if ( V_3 -> V_212 . V_213 )
F_45 ( V_3 , ! V_3 -> V_212 . V_214 ) ;
return V_211 ;
#else
return true ;
#endif
}
void F_252 ( struct V_2 * V_18 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_2 * V_3 ;
int V_215 = V_18 -> V_15 -> V_215 ;
int V_216 = 0 ;
int V_217 = 3 ;
int V_218 ;
int V_17 ;
F_44 ( V_18 , true ) ;
for ( V_218 = 0 ; V_218 < 2 && ! V_216 && V_217 ; V_218 ++ ) {
F_25 (i, vcpu, kvm) {
if ( ! V_218 && V_17 <= V_215 ) {
V_17 = V_215 ;
continue;
} else if ( V_218 && V_17 > V_215 )
break;
if ( ! F_253 ( V_3 -> V_42 ) )
continue;
if ( V_3 == V_18 )
continue;
if ( F_238 ( & V_3 -> V_36 ) && ! F_231 ( V_3 ) )
continue;
if ( ! F_250 ( V_3 ) )
continue;
V_216 = F_243 ( V_3 ) ;
if ( V_216 > 0 ) {
V_15 -> V_215 = V_17 ;
break;
} else if ( V_216 < 0 ) {
V_217 -- ;
if ( ! V_217 )
break;
}
}
}
F_44 ( V_18 , false ) ;
F_45 ( V_18 , false ) ;
}
static int F_254 ( struct V_153 * V_154 , struct V_219 * V_220 )
{
struct V_2 * V_3 = V_154 -> V_221 -> V_105 ;
struct V_33 * V_33 ;
if ( V_220 -> V_222 == 0 )
V_33 = F_255 ( V_3 -> V_41 ) ;
#ifdef F_256
else if ( V_220 -> V_222 == V_223 )
V_33 = F_255 ( V_3 -> V_144 . V_224 ) ;
#endif
#ifdef F_257
else if ( V_220 -> V_222 == F_257 )
V_33 = F_255 ( V_3 -> V_15 -> V_225 ) ;
#endif
else
return F_258 ( V_3 , V_220 ) ;
F_206 ( V_33 ) ;
V_220 -> V_33 = V_33 ;
return 0 ;
}
static int F_259 ( struct V_103 * V_103 , struct V_153 * V_154 )
{
V_154 -> V_226 = & V_227 ;
return 0 ;
}
static int F_260 ( struct V_102 * V_102 , struct V_103 * V_104 )
{
struct V_2 * V_3 = V_104 -> V_105 ;
F_118 ( V_3 -> V_15 ) ;
return 0 ;
}
static int F_261 ( struct V_2 * V_3 )
{
return F_262 ( L_1 , & V_228 , V_3 , V_229 | V_230 ) ;
}
static int F_263 ( struct V_15 * V_15 , T_5 V_32 )
{
int V_34 ;
struct V_2 * V_3 , * V_231 ;
if ( V_32 >= V_232 )
return - V_121 ;
V_3 = F_264 ( V_15 , V_32 ) ;
if ( F_265 ( V_3 ) )
return F_266 ( V_3 ) ;
F_267 ( & V_3 -> V_13 , & V_233 ) ;
V_34 = F_268 ( V_3 ) ;
if ( V_34 )
goto V_234;
F_144 ( & V_15 -> V_78 ) ;
if ( ! F_269 ( V_3 ) ) {
V_34 = - V_121 ;
goto V_235;
}
if ( F_270 ( & V_15 -> V_236 ) == V_232 ) {
V_34 = - V_121 ;
goto V_235;
}
F_25 (r, v, kvm)
if ( V_231 -> V_35 == V_32 ) {
V_34 = - V_140 ;
goto V_235;
}
F_64 ( V_15 -> V_237 [ F_270 ( & V_15 -> V_236 ) ] ) ;
F_117 ( V_15 ) ;
V_34 = F_261 ( V_3 ) ;
if ( V_34 < 0 ) {
F_118 ( V_15 ) ;
goto V_235;
}
V_15 -> V_237 [ F_270 ( & V_15 -> V_236 ) ] = V_3 ;
F_63 () ;
F_85 ( & V_15 -> V_236 ) ;
F_21 ( & V_15 -> V_78 ) ;
F_271 ( V_3 ) ;
return V_34 ;
V_235:
F_21 ( & V_15 -> V_78 ) ;
V_234:
F_272 ( V_3 ) ;
return V_34 ;
}
static int F_273 ( struct V_2 * V_3 , T_9 * V_238 )
{
if ( V_238 ) {
F_274 ( V_238 , F_275 ( V_239 ) | F_275 ( V_240 ) ) ;
V_3 -> V_241 = 1 ;
V_3 -> V_238 = * V_238 ;
} else
V_3 -> V_241 = 0 ;
return 0 ;
}
static long F_276 ( struct V_103 * V_104 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_2 * V_3 = V_104 -> V_105 ;
void V_133 * V_244 = ( void V_133 * ) V_243 ;
int V_34 ;
struct V_245 * V_246 = NULL ;
struct V_247 * V_247 = NULL ;
if ( V_3 -> V_15 -> V_47 != V_8 -> V_47 )
return - V_248 ;
#if F_113 ( V_249 ) || F_113 ( V_250 ) || F_113 ( V_251 )
if ( V_242 == V_252 || V_242 == V_253 )
return F_277 ( V_104 , V_242 , V_243 ) ;
#endif
V_34 = F_5 ( V_3 ) ;
if ( V_34 )
return V_34 ;
switch ( V_242 ) {
case V_254 :
V_34 = - V_121 ;
if ( V_243 )
goto V_127;
V_34 = F_278 ( V_3 , V_3 -> V_41 ) ;
F_279 ( V_3 -> V_41 -> V_255 , V_34 ) ;
break;
case V_256 : {
struct V_257 * V_257 ;
V_34 = - V_39 ;
V_257 = F_82 ( sizeof( struct V_257 ) , V_37 ) ;
if ( ! V_257 )
goto V_127;
V_34 = F_280 ( V_3 , V_257 ) ;
if ( V_34 )
goto V_258;
V_34 = - V_150 ;
if ( F_147 ( V_244 , V_257 , sizeof( struct V_257 ) ) )
goto V_258;
V_34 = 0 ;
V_258:
F_92 ( V_257 ) ;
break;
}
case V_259 : {
struct V_257 * V_257 ;
V_34 = - V_39 ;
V_257 = F_281 ( V_244 , sizeof( * V_257 ) ) ;
if ( F_265 ( V_257 ) ) {
V_34 = F_266 ( V_257 ) ;
goto V_127;
}
V_34 = F_282 ( V_3 , V_257 ) ;
F_92 ( V_257 ) ;
break;
}
case V_260 : {
V_247 = F_82 ( sizeof( struct V_247 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_247 )
goto V_127;
V_34 = F_283 ( V_3 , V_247 ) ;
if ( V_34 )
goto V_127;
V_34 = - V_150 ;
if ( F_147 ( V_244 , V_247 , sizeof( struct V_247 ) ) )
goto V_127;
V_34 = 0 ;
break;
}
case V_261 : {
V_247 = F_281 ( V_244 , sizeof( * V_247 ) ) ;
if ( F_265 ( V_247 ) ) {
V_34 = F_266 ( V_247 ) ;
V_247 = NULL ;
goto V_127;
}
V_34 = F_284 ( V_3 , V_247 ) ;
break;
}
case V_262 : {
struct V_263 V_264 ;
V_34 = F_285 ( V_3 , & V_264 ) ;
if ( V_34 )
goto V_127;
V_34 = - V_150 ;
if ( F_147 ( V_244 , & V_264 , sizeof V_264 ) )
goto V_127;
V_34 = 0 ;
break;
}
case V_265 : {
struct V_263 V_264 ;
V_34 = - V_150 ;
if ( F_286 ( & V_264 , V_244 , sizeof V_264 ) )
goto V_127;
V_34 = F_287 ( V_3 , & V_264 ) ;
break;
}
case V_266 : {
struct V_267 V_268 ;
V_34 = - V_150 ;
if ( F_286 ( & V_268 , V_244 , sizeof V_268 ) )
goto V_127;
V_34 = F_288 ( V_3 , & V_268 ) ;
if ( V_34 )
goto V_127;
V_34 = - V_150 ;
if ( F_147 ( V_244 , & V_268 , sizeof V_268 ) )
goto V_127;
V_34 = 0 ;
break;
}
case V_269 : {
struct V_270 V_271 ;
V_34 = - V_150 ;
if ( F_286 ( & V_271 , V_244 , sizeof V_271 ) )
goto V_127;
V_34 = F_289 ( V_3 , & V_271 ) ;
break;
}
case V_272 : {
struct V_273 V_133 * V_274 = V_244 ;
struct V_273 V_275 ;
T_9 V_238 , * V_276 ;
V_276 = NULL ;
if ( V_244 ) {
V_34 = - V_150 ;
if ( F_286 ( & V_275 , V_244 ,
sizeof V_275 ) )
goto V_127;
V_34 = - V_121 ;
if ( V_275 . V_163 != sizeof V_238 )
goto V_127;
V_34 = - V_150 ;
if ( F_286 ( & V_238 , V_274 -> V_238 ,
sizeof V_238 ) )
goto V_127;
V_276 = & V_238 ;
}
V_34 = F_273 ( V_3 , V_276 ) ;
break;
}
case V_277 : {
V_246 = F_82 ( sizeof( struct V_245 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_246 )
goto V_127;
V_34 = F_290 ( V_3 , V_246 ) ;
if ( V_34 )
goto V_127;
V_34 = - V_150 ;
if ( F_147 ( V_244 , V_246 , sizeof( struct V_245 ) ) )
goto V_127;
V_34 = 0 ;
break;
}
case V_278 : {
V_246 = F_281 ( V_244 , sizeof( * V_246 ) ) ;
if ( F_265 ( V_246 ) ) {
V_34 = F_266 ( V_246 ) ;
V_246 = NULL ;
goto V_127;
}
V_34 = F_291 ( V_3 , V_246 ) ;
break;
}
default:
V_34 = F_277 ( V_104 , V_242 , V_243 ) ;
}
V_127:
F_16 ( V_3 ) ;
F_92 ( V_246 ) ;
F_92 ( V_247 ) ;
return V_34 ;
}
static long F_292 ( struct V_103 * V_104 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_2 * V_3 = V_104 -> V_105 ;
void V_133 * V_244 = F_293 ( V_243 ) ;
int V_34 ;
if ( V_3 -> V_15 -> V_47 != V_8 -> V_47 )
return - V_248 ;
switch ( V_242 ) {
case V_272 : {
struct V_273 V_133 * V_274 = V_244 ;
struct V_273 V_275 ;
T_10 V_279 ;
T_9 V_238 ;
if ( V_244 ) {
V_34 = - V_150 ;
if ( F_286 ( & V_275 , V_244 ,
sizeof V_275 ) )
goto V_127;
V_34 = - V_121 ;
if ( V_275 . V_163 != sizeof V_279 )
goto V_127;
V_34 = - V_150 ;
if ( F_286 ( & V_279 , V_274 -> V_238 ,
sizeof V_279 ) )
goto V_127;
F_294 ( & V_238 , & V_279 ) ;
V_34 = F_273 ( V_3 , & V_238 ) ;
} else
V_34 = F_273 ( V_3 , NULL ) ;
break;
}
default:
V_34 = F_276 ( V_104 , V_242 , V_243 ) ;
}
V_127:
return V_34 ;
}
static int F_295 ( struct V_96 * V_97 ,
int (* F_296)( struct V_96 * V_97 ,
struct V_280 * V_281 ) ,
unsigned long V_243 )
{
struct V_280 V_281 ;
if ( ! F_296 )
return - V_282 ;
if ( F_286 ( & V_281 , ( void V_133 * ) V_243 , sizeof( V_281 ) ) )
return - V_150 ;
return F_296 ( V_97 , & V_281 ) ;
}
static long F_297 ( struct V_103 * V_104 , unsigned int V_242 ,
unsigned long V_243 )
{
struct V_96 * V_97 = V_104 -> V_105 ;
switch ( V_242 ) {
case V_283 :
return F_295 ( V_97 , V_97 -> V_59 -> V_284 , V_243 ) ;
case V_285 :
return F_295 ( V_97 , V_97 -> V_59 -> V_286 , V_243 ) ;
case V_287 :
return F_295 ( V_97 , V_97 -> V_59 -> V_288 , V_243 ) ;
default:
if ( V_97 -> V_59 -> V_242 )
return V_97 -> V_59 -> V_242 ( V_97 , V_242 , V_243 ) ;
return - V_289 ;
}
}
static int F_298 ( struct V_102 * V_102 , struct V_103 * V_104 )
{
struct V_96 * V_97 = V_104 -> V_105 ;
struct V_15 * V_15 = V_97 -> V_15 ;
F_118 ( V_15 ) ;
return 0 ;
}
struct V_96 * F_299 ( struct V_103 * V_104 )
{
if ( V_104 -> V_290 != & V_291 )
return NULL ;
return V_104 -> V_105 ;
}
static int F_300 ( struct V_15 * V_15 ,
struct V_292 * V_293 )
{
struct V_294 * V_59 = NULL ;
struct V_96 * V_97 ;
bool V_295 = V_293 -> V_120 & V_296 ;
int V_193 ;
switch ( V_293 -> type ) {
#ifdef F_301
case V_297 :
case V_298 :
V_59 = & V_299 ;
break;
#endif
#ifdef F_302
case V_300 :
V_59 = & V_301 ;
break;
#endif
#ifdef F_303
case V_302 :
V_59 = & V_303 ;
break;
#endif
#ifdef F_304
case V_304 :
V_59 = & V_305 ;
break;
#endif
#ifdef V_249
case V_306 :
V_59 = & V_307 ;
break;
#endif
default:
return - V_308 ;
}
if ( V_295 )
return 0 ;
V_97 = F_82 ( sizeof( * V_97 ) , V_37 ) ;
if ( ! V_97 )
return - V_39 ;
V_97 -> V_59 = V_59 ;
V_97 -> V_15 = V_15 ;
V_193 = V_59 -> V_309 ( V_97 , V_293 -> type ) ;
if ( V_193 < 0 ) {
F_92 ( V_97 ) ;
return V_193 ;
}
V_193 = F_262 ( V_59 -> V_310 , & V_291 , V_97 , V_229 | V_230 ) ;
if ( V_193 < 0 ) {
V_59 -> V_99 ( V_97 ) ;
return V_193 ;
}
F_89 ( & V_97 -> V_98 , & V_15 -> V_82 ) ;
F_117 ( V_15 ) ;
V_293 -> V_311 = V_193 ;
return 0 ;
}
static long F_305 ( struct V_103 * V_104 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_15 * V_15 = V_104 -> V_105 ;
void V_133 * V_244 = ( void V_133 * ) V_243 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_248 ;
switch ( V_242 ) {
case V_312 :
V_34 = F_263 ( V_15 , V_243 ) ;
break;
case V_313 : {
struct V_115 V_314 ;
V_34 = - V_150 ;
if ( F_286 ( & V_314 , V_244 ,
sizeof V_314 ) )
goto V_127;
V_34 = F_145 ( V_15 , & V_314 ) ;
break;
}
case V_315 : {
struct V_145 log ;
V_34 = - V_150 ;
if ( F_286 ( & log , V_244 , sizeof log ) )
goto V_127;
V_34 = F_306 ( V_15 , & log ) ;
break;
}
#ifdef F_257
case V_316 : {
struct V_317 V_318 ;
V_34 = - V_150 ;
if ( F_286 ( & V_318 , V_244 , sizeof V_318 ) )
goto V_127;
V_34 = F_307 ( V_15 , & V_318 ) ;
break;
}
case V_319 : {
struct V_317 V_318 ;
V_34 = - V_150 ;
if ( F_286 ( & V_318 , V_244 , sizeof V_318 ) )
goto V_127;
V_34 = F_308 ( V_15 , & V_318 ) ;
break;
}
#endif
case V_320 : {
struct V_321 V_162 ;
V_34 = - V_150 ;
if ( F_286 ( & V_162 , V_244 , sizeof V_162 ) )
goto V_127;
V_34 = V_321 ( V_15 , & V_162 ) ;
break;
}
case V_322 : {
struct V_323 V_162 ;
V_34 = - V_150 ;
if ( F_286 ( & V_162 , V_244 , sizeof V_162 ) )
goto V_127;
V_34 = V_323 ( V_15 , & V_162 ) ;
break;
}
#ifdef F_309
case V_324 :
V_34 = 0 ;
F_144 ( & V_15 -> V_78 ) ;
if ( F_270 ( & V_15 -> V_236 ) != 0 )
V_34 = - V_325 ;
else
V_15 -> V_326 = V_243 ;
F_21 ( & V_15 -> V_78 ) ;
break;
#endif
#ifdef F_310
case V_327 : {
struct V_328 V_329 ;
V_34 = - V_150 ;
if ( F_286 ( & V_329 , V_244 , sizeof V_329 ) )
goto V_127;
V_34 = F_311 ( V_15 , & V_329 ) ;
break;
}
#endif
#ifdef F_312
case V_330 :
case V_331 : {
struct V_332 V_333 ;
V_34 = - V_150 ;
if ( F_286 ( & V_333 , V_244 , sizeof V_333 ) )
goto V_127;
V_34 = F_313 ( V_15 , & V_333 ,
V_242 == V_330 ) ;
if ( V_34 )
goto V_127;
V_34 = - V_150 ;
if ( V_242 == V_330 ) {
if ( F_147 ( V_244 , & V_333 , sizeof V_333 ) )
goto V_127;
}
V_34 = 0 ;
break;
}
#endif
#ifdef F_314
case V_334 : {
struct V_335 V_336 ;
struct V_335 V_133 * V_337 ;
struct V_338 * V_339 ;
V_34 = - V_150 ;
if ( F_286 ( & V_336 , V_244 , sizeof( V_336 ) ) )
goto V_127;
V_34 = - V_121 ;
if ( V_336 . V_340 >= V_341 )
goto V_127;
if ( V_336 . V_120 )
goto V_127;
V_34 = - V_39 ;
V_339 = F_315 ( V_336 . V_340 * sizeof( * V_339 ) ) ;
if ( ! V_339 )
goto V_127;
V_34 = - V_150 ;
V_337 = V_244 ;
if ( F_286 ( V_339 , V_337 -> V_339 ,
V_336 . V_340 * sizeof( * V_339 ) ) )
goto V_342;
V_34 = F_316 ( V_15 , V_339 , V_336 . V_340 ,
V_336 . V_120 ) ;
V_342:
F_98 ( V_339 ) ;
break;
}
#endif
case V_343 : {
struct V_292 V_293 ;
V_34 = - V_150 ;
if ( F_286 ( & V_293 , V_244 , sizeof( V_293 ) ) )
goto V_127;
V_34 = F_300 ( V_15 , & V_293 ) ;
if ( V_34 )
goto V_127;
V_34 = - V_150 ;
if ( F_147 ( V_244 , & V_293 , sizeof( V_293 ) ) )
goto V_127;
V_34 = 0 ;
break;
}
default:
V_34 = F_317 ( V_104 , V_242 , V_243 ) ;
if ( V_34 == - V_289 )
V_34 = F_318 ( V_15 , V_242 , V_243 ) ;
}
V_127:
return V_34 ;
}
static long F_319 ( struct V_103 * V_104 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_15 * V_15 = V_104 -> V_105 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_248 ;
switch ( V_242 ) {
case V_315 : {
struct V_344 V_345 ;
struct V_145 log ;
V_34 = - V_150 ;
if ( F_286 ( & V_345 , ( void V_133 * ) V_243 ,
sizeof( V_345 ) ) )
goto V_127;
log . V_124 = V_345 . V_124 ;
log . V_346 = V_345 . V_346 ;
log . V_347 = V_345 . V_347 ;
log . V_90 = F_293 ( V_345 . V_90 ) ;
V_34 = F_306 ( V_15 , & log ) ;
break;
}
default:
V_34 = F_305 ( V_104 , V_242 , V_243 ) ;
}
V_127:
return V_34 ;
}
static int F_320 ( unsigned long type )
{
int V_34 ;
struct V_15 * V_15 ;
V_15 = F_74 ( type ) ;
if ( F_265 ( V_15 ) )
return F_266 ( V_15 ) ;
#ifdef F_257
V_34 = F_321 ( V_15 ) ;
if ( V_34 < 0 ) {
F_118 ( V_15 ) ;
return V_34 ;
}
#endif
V_34 = F_262 ( L_2 , & V_348 , V_15 , V_229 | V_230 ) ;
if ( V_34 < 0 )
F_118 ( V_15 ) ;
return V_34 ;
}
static long F_322 ( long V_243 )
{
switch ( V_243 ) {
case V_349 :
case V_350 :
case V_351 :
#ifdef F_309
case V_352 :
#endif
case V_353 :
#ifdef F_310
case V_354 :
#endif
#ifdef F_314
case V_355 :
#endif
return 1 ;
#ifdef F_314
case V_356 :
return V_341 ;
#endif
default:
break;
}
return F_323 ( V_243 ) ;
}
static long F_324 ( struct V_103 * V_104 ,
unsigned int V_242 , unsigned long V_243 )
{
long V_34 = - V_121 ;
switch ( V_242 ) {
case V_357 :
V_34 = - V_121 ;
if ( V_243 )
goto V_127;
V_34 = V_358 ;
break;
case V_359 :
V_34 = F_320 ( V_243 ) ;
break;
case V_360 :
V_34 = F_322 ( V_243 ) ;
break;
case V_361 :
V_34 = - V_121 ;
if ( V_243 )
goto V_127;
V_34 = V_86 ;
#ifdef F_256
V_34 += V_86 ;
#endif
#ifdef F_257
V_34 += V_86 ;
#endif
break;
case V_362 :
case V_363 :
case V_364 :
V_34 = - V_365 ;
break;
default:
return F_325 ( V_104 , V_242 , V_243 ) ;
}
V_127:
return V_34 ;
}
static void F_326 ( void * V_366 )
{
int V_4 = F_327 () ;
int V_34 ;
if ( F_328 ( V_4 , V_367 ) )
return;
F_29 ( V_4 , V_367 ) ;
V_34 = F_329 ( NULL ) ;
if ( V_34 ) {
F_330 ( V_4 , V_367 ) ;
F_85 ( & V_368 ) ;
F_331 ( V_369 L_3
L_4 , V_4 ) ;
}
}
static void F_332 ( void )
{
F_333 ( & V_370 ) ;
if ( V_371 )
F_326 ( NULL ) ;
F_334 ( & V_370 ) ;
}
static void F_335 ( void * V_366 )
{
int V_4 = F_327 () ;
if ( ! F_328 ( V_4 , V_367 ) )
return;
F_330 ( V_4 , V_367 ) ;
F_336 ( NULL ) ;
}
static void F_337 ( void )
{
F_333 ( & V_370 ) ;
if ( V_371 )
F_335 ( NULL ) ;
F_334 ( & V_370 ) ;
}
static void F_338 ( void )
{
F_64 ( ! V_371 ) ;
V_371 -- ;
if ( ! V_371 )
F_339 ( F_335 , NULL , 1 ) ;
}
static void F_91 ( void )
{
F_333 ( & V_370 ) ;
F_338 () ;
F_334 ( & V_370 ) ;
}
static int F_78 ( void )
{
int V_34 = 0 ;
F_333 ( & V_370 ) ;
V_371 ++ ;
if ( V_371 == 1 ) {
F_87 ( & V_368 , 0 ) ;
F_339 ( F_326 , NULL , 1 ) ;
if ( F_270 ( & V_368 ) ) {
F_338 () ;
V_34 = - V_325 ;
}
}
F_334 ( & V_370 ) ;
return V_34 ;
}
static int F_340 ( struct V_372 * V_373 , unsigned long V_374 ,
void * V_231 )
{
int V_4 = ( long ) V_231 ;
V_374 &= ~ V_375 ;
switch ( V_374 ) {
case V_376 :
F_331 ( V_369 L_5 ,
V_4 ) ;
F_337 () ;
break;
case V_377 :
F_331 ( V_369 L_6 ,
V_4 ) ;
F_332 () ;
break;
}
return V_378 ;
}
static int F_341 ( struct V_372 * V_373 , unsigned long V_374 ,
void * V_231 )
{
F_331 ( V_369 L_7 ) ;
V_379 = true ;
F_339 ( F_335 , NULL , 1 ) ;
return V_378 ;
}
static void F_111 ( struct V_75 * V_380 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_380 -> V_381 ; V_17 ++ ) {
struct V_382 * V_383 = V_380 -> V_384 [ V_17 ] . V_97 ;
F_342 ( V_383 ) ;
}
F_92 ( V_380 ) ;
}
static inline int F_343 ( const struct V_385 * V_386 ,
const struct V_385 * V_387 )
{
if ( V_386 -> V_87 < V_387 -> V_87 )
return - 1 ;
if ( V_386 -> V_87 + V_386 -> V_163 > V_387 -> V_87 + V_387 -> V_163 )
return 1 ;
return 0 ;
}
static int F_344 ( const void * V_388 , const void * V_389 )
{
return F_343 ( V_388 , V_389 ) ;
}
static int F_345 ( struct V_75 * V_380 , struct V_382 * V_97 ,
T_7 V_87 , int V_163 )
{
V_380 -> V_384 [ V_380 -> V_381 ++ ] = (struct V_385 ) {
. V_87 = V_87 ,
. V_163 = V_163 ,
. V_97 = V_97 ,
} ;
F_126 ( V_380 -> V_384 , V_380 -> V_381 , sizeof( struct V_385 ) ,
F_344 , NULL ) ;
return 0 ;
}
static int F_346 ( struct V_75 * V_380 ,
T_7 V_87 , int V_163 )
{
struct V_385 * V_384 , V_390 ;
int V_391 ;
V_390 = (struct V_385 ) {
. V_87 = V_87 ,
. V_163 = V_163 ,
} ;
V_384 = bsearch ( & V_390 , V_380 -> V_384 , V_380 -> V_381 ,
sizeof( struct V_385 ) , F_344 ) ;
if ( V_384 == NULL )
return - V_149 ;
V_391 = V_384 - V_380 -> V_384 ;
while ( V_391 > 0 && F_343 ( & V_390 , & V_380 -> V_384 [ V_391 - 1 ] ) == 0 )
V_391 -- ;
return V_391 ;
}
static int F_347 ( struct V_75 * V_380 ,
struct V_385 * V_384 , const void * V_374 )
{
int V_50 ;
V_50 = F_346 ( V_380 , V_384 -> V_87 , V_384 -> V_163 ) ;
if ( V_50 < 0 )
return - V_365 ;
while ( V_50 < V_380 -> V_381 &&
F_343 ( V_384 , & V_380 -> V_384 [ V_50 ] ) == 0 ) {
if ( ! F_348 ( V_380 -> V_384 [ V_50 ] . V_97 , V_384 -> V_87 ,
V_384 -> V_163 , V_374 ) )
return V_50 ;
V_50 ++ ;
}
return - V_365 ;
}
int F_349 ( struct V_15 * V_15 , enum V_392 V_393 , T_7 V_87 ,
int V_163 , const void * V_374 )
{
struct V_75 * V_380 ;
struct V_385 V_384 ;
int V_34 ;
V_384 = (struct V_385 ) {
. V_87 = V_87 ,
. V_163 = V_163 ,
} ;
V_380 = F_350 ( V_15 -> V_74 [ V_393 ] , & V_15 -> V_51 ) ;
V_34 = F_347 ( V_380 , & V_384 , V_374 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_351 ( struct V_15 * V_15 , enum V_392 V_393 , T_7 V_87 ,
int V_163 , const void * V_374 , long V_394 )
{
struct V_75 * V_380 ;
struct V_385 V_384 ;
V_384 = (struct V_385 ) {
. V_87 = V_87 ,
. V_163 = V_163 ,
} ;
V_380 = F_350 ( V_15 -> V_74 [ V_393 ] , & V_15 -> V_51 ) ;
if ( ( V_394 >= 0 ) && ( V_394 < V_380 -> V_381 ) &&
( F_343 ( & V_384 , & V_380 -> V_384 [ V_394 ] ) == 0 ) )
if ( ! F_348 ( V_380 -> V_384 [ V_394 ] . V_97 , V_87 , V_163 ,
V_374 ) )
return V_394 ;
return F_347 ( V_380 , & V_384 , V_374 ) ;
}
static int F_352 ( struct V_75 * V_380 , struct V_385 * V_384 ,
void * V_374 )
{
int V_50 ;
V_50 = F_346 ( V_380 , V_384 -> V_87 , V_384 -> V_163 ) ;
if ( V_50 < 0 )
return - V_365 ;
while ( V_50 < V_380 -> V_381 &&
F_343 ( V_384 , & V_380 -> V_384 [ V_50 ] ) == 0 ) {
if ( ! F_353 ( V_380 -> V_384 [ V_50 ] . V_97 , V_384 -> V_87 ,
V_384 -> V_163 , V_374 ) )
return V_50 ;
V_50 ++ ;
}
return - V_365 ;
}
int F_354 ( struct V_15 * V_15 , enum V_392 V_393 , T_7 V_87 ,
int V_163 , void * V_374 )
{
struct V_75 * V_380 ;
struct V_385 V_384 ;
int V_34 ;
V_384 = (struct V_385 ) {
. V_87 = V_87 ,
. V_163 = V_163 ,
} ;
V_380 = F_350 ( V_15 -> V_74 [ V_393 ] , & V_15 -> V_51 ) ;
V_34 = F_352 ( V_380 , & V_384 , V_374 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_355 ( struct V_15 * V_15 , enum V_392 V_393 , T_7 V_87 ,
int V_163 , struct V_382 * V_97 )
{
struct V_75 * V_395 , * V_380 ;
V_380 = V_15 -> V_74 [ V_393 ] ;
if ( V_380 -> V_381 - V_380 -> V_396 > V_397 - 1 )
return - V_398 ;
V_395 = F_82 ( sizeof( * V_380 ) + ( ( V_380 -> V_381 + 1 ) *
sizeof( struct V_385 ) ) , V_37 ) ;
if ( ! V_395 )
return - V_39 ;
memcpy ( V_395 , V_380 , sizeof( * V_380 ) + ( V_380 -> V_381 *
sizeof( struct V_385 ) ) ) ;
F_345 ( V_395 , V_97 , V_87 , V_163 ) ;
F_9 ( V_15 -> V_74 [ V_393 ] , V_395 ) ;
F_132 ( & V_15 -> V_51 ) ;
F_92 ( V_380 ) ;
return 0 ;
}
int F_356 ( struct V_15 * V_15 , enum V_392 V_393 ,
struct V_382 * V_97 )
{
int V_17 , V_34 ;
struct V_75 * V_395 , * V_380 ;
V_380 = V_15 -> V_74 [ V_393 ] ;
V_34 = - V_149 ;
for ( V_17 = 0 ; V_17 < V_380 -> V_381 ; V_17 ++ )
if ( V_380 -> V_384 [ V_17 ] . V_97 == V_97 ) {
V_34 = 0 ;
break;
}
if ( V_34 )
return V_34 ;
V_395 = F_82 ( sizeof( * V_380 ) + ( ( V_380 -> V_381 - 1 ) *
sizeof( struct V_385 ) ) , V_37 ) ;
if ( ! V_395 )
return - V_39 ;
memcpy ( V_395 , V_380 , sizeof( * V_380 ) + V_17 * sizeof( struct V_385 ) ) ;
V_395 -> V_381 -- ;
memcpy ( V_395 -> V_384 + V_17 , V_380 -> V_384 + V_17 + 1 ,
( V_395 -> V_381 - V_17 ) * sizeof( struct V_385 ) ) ;
F_9 ( V_15 -> V_74 [ V_393 ] , V_395 ) ;
F_132 ( & V_15 -> V_51 ) ;
F_92 ( V_380 ) ;
return V_34 ;
}
static int F_357 ( void * V_399 , T_4 * V_374 )
{
unsigned V_190 = ( long ) V_399 ;
struct V_15 * V_15 ;
* V_374 = 0 ;
F_54 ( & V_83 ) ;
F_358 ( V_15 , & V_84 , V_84 )
* V_374 += * ( T_5 * ) ( ( void * ) V_15 + V_190 ) ;
F_56 ( & V_83 ) ;
return 0 ;
}
static int F_359 ( void * V_399 , T_4 * V_374 )
{
unsigned V_190 = ( long ) V_399 ;
struct V_15 * V_15 ;
struct V_2 * V_3 ;
int V_17 ;
* V_374 = 0 ;
F_54 ( & V_83 ) ;
F_358 (kvm, &vm_list, vm_list)
F_25 ( V_17 , V_3 , V_15 )
* V_374 += * ( T_5 * ) ( ( void * ) V_3 + V_190 ) ;
F_56 ( & V_83 ) ;
return 0 ;
}
static int F_360 ( void )
{
int V_34 = - V_140 ;
struct V_400 * V_276 ;
V_401 = F_361 ( L_8 , NULL ) ;
if ( V_401 == NULL )
goto V_127;
for ( V_276 = V_402 ; V_276 -> V_310 ; ++ V_276 ) {
V_276 -> V_403 = F_362 ( V_276 -> V_310 , 0444 , V_401 ,
( void * ) ( long ) V_276 -> V_190 ,
V_404 [ V_276 -> V_405 ] ) ;
if ( V_276 -> V_403 == NULL )
goto V_406;
}
return 0 ;
V_406:
F_363 ( V_401 ) ;
V_127:
return V_34 ;
}
static void F_364 ( void )
{
struct V_400 * V_276 ;
for ( V_276 = V_402 ; V_276 -> V_310 ; ++ V_276 )
F_365 ( V_276 -> V_403 ) ;
F_365 ( V_401 ) ;
}
static int F_366 ( void )
{
if ( V_371 )
F_335 ( NULL ) ;
return 0 ;
}
static void F_367 ( void )
{
if ( V_371 ) {
F_194 ( F_368 ( & V_370 ) ) ;
F_326 ( NULL ) ;
}
}
static inline
struct V_2 * F_369 ( struct V_13 * V_407 )
{
return F_51 ( V_407 , struct V_2 , V_13 ) ;
}
static void F_370 ( struct V_13 * V_407 , int V_4 )
{
struct V_2 * V_3 = F_369 ( V_407 ) ;
if ( V_3 -> V_42 )
V_3 -> V_42 = false ;
F_14 ( V_3 , V_4 ) ;
}
static void F_371 ( struct V_13 * V_407 ,
struct V_164 * V_408 )
{
struct V_2 * V_3 = F_369 ( V_407 ) ;
if ( V_8 -> V_409 == V_410 )
V_3 -> V_42 = true ;
F_18 ( V_3 ) ;
}
int F_372 ( void * V_411 , unsigned V_412 , unsigned V_413 ,
struct V_414 * V_414 )
{
int V_34 ;
int V_4 ;
V_34 = F_373 ( V_411 ) ;
if ( V_34 )
goto V_415;
V_34 = F_374 () ;
if ( V_34 )
goto V_416;
if ( ! F_24 ( & V_367 , V_37 ) ) {
V_34 = - V_39 ;
goto V_417;
}
V_34 = F_375 () ;
if ( V_34 < 0 )
goto V_418;
F_376 (cpu) {
F_377 ( V_4 ,
V_419 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_420;
}
V_34 = F_378 ( & V_421 ) ;
if ( V_34 )
goto V_422;
F_379 ( & V_423 ) ;
if ( ! V_413 )
V_413 = F_380 ( struct V_2 ) ;
V_424 = F_381 ( L_9 , V_412 , V_413 ,
0 , NULL ) ;
if ( ! V_424 ) {
V_34 = - V_39 ;
goto V_425;
}
V_34 = F_382 () ;
if ( V_34 )
goto V_141;
V_426 . V_427 = V_414 ;
V_348 . V_427 = V_414 ;
V_228 . V_427 = V_414 ;
V_34 = F_383 ( & V_428 ) ;
if ( V_34 ) {
F_331 ( V_429 L_10 ) ;
goto V_430;
}
F_384 ( & V_431 ) ;
V_233 . V_432 = F_370 ;
V_233 . V_433 = F_371 ;
V_34 = F_360 () ;
if ( V_34 ) {
F_331 ( V_429 L_11 ) ;
goto V_434;
}
return 0 ;
V_434:
F_385 ( & V_431 ) ;
F_386 ( & V_428 ) ;
V_430:
F_387 () ;
V_141:
F_388 ( V_424 ) ;
V_425:
F_389 ( & V_423 ) ;
F_390 ( & V_421 ) ;
V_422:
V_420:
F_391 () ;
V_418:
F_32 ( V_367 ) ;
V_417:
F_392 () ;
V_416:
F_393 () ;
V_415:
return V_34 ;
}
void F_394 ( void )
{
F_364 () ;
F_386 ( & V_428 ) ;
F_388 ( V_424 ) ;
F_387 () ;
F_385 ( & V_431 ) ;
F_389 ( & V_423 ) ;
F_390 ( & V_421 ) ;
F_339 ( F_335 , NULL , 1 ) ;
F_391 () ;
F_393 () ;
F_392 () ;
F_32 ( V_367 ) ;
}
