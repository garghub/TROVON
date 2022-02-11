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
V_4 = F_7 () ;
F_8 ( & V_3 -> V_7 ) ;
F_9 ( V_3 , V_4 ) ;
F_10 () ;
return 0 ;
}
void F_11 ( struct V_2 * V_3 )
{
F_12 () ;
F_13 ( V_3 ) ;
F_14 ( & V_3 -> V_7 ) ;
F_15 () ;
F_16 ( & V_3 -> V_5 ) ;
}
static bool F_17 ( struct V_2 * V_3 , unsigned V_8 )
{
int V_9 = F_18 ( V_3 ) ;
if ( V_8 & V_10 )
return V_9 != V_11 ;
return V_9 == V_12 ;
}
static void F_19 ( void * V_13 )
{
}
static inline bool F_20 ( const struct V_14 * V_15 , bool V_16 )
{
if ( F_21 ( ! V_15 ) )
V_15 = V_17 ;
if ( F_22 ( V_15 ) )
return false ;
F_23 ( V_15 , F_19 , NULL , V_16 ) ;
return true ;
}
bool F_24 ( struct V_18 * V_18 , unsigned int V_8 )
{
int V_19 , V_4 , V_20 ;
T_2 V_15 ;
bool V_21 ;
struct V_2 * V_3 ;
F_25 ( & V_15 , V_22 ) ;
V_20 = F_7 () ;
F_26 (i, vcpu, kvm) {
F_27 ( V_8 , V_3 ) ;
V_4 = V_3 -> V_4 ;
if ( ! ( V_8 & V_23 ) && F_28 ( V_3 ) )
continue;
if ( V_15 != NULL && V_4 != - 1 && V_4 != V_20 &&
F_17 ( V_3 , V_8 ) )
F_29 ( V_4 , V_15 ) ;
}
V_21 = F_20 ( V_15 , ! ! ( V_8 & V_10 ) ) ;
F_10 () ;
F_30 ( V_15 ) ;
return V_21 ;
}
void F_31 ( struct V_18 * V_18 )
{
long V_24 = F_32 ( & V_18 -> V_25 ) ;
if ( F_24 ( V_18 , V_26 ) )
++ V_18 -> V_27 . V_28 ;
F_33 ( & V_18 -> V_25 , V_24 , 0 ) ;
}
void F_34 ( struct V_18 * V_18 )
{
F_24 ( V_18 , V_29 ) ;
}
int F_35 ( struct V_2 * V_3 , struct V_18 * V_18 , unsigned V_30 )
{
struct V_31 * V_31 ;
int V_32 ;
F_36 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_33 = V_30 ;
V_3 -> V_34 = NULL ;
F_37 ( & V_3 -> V_35 ) ;
F_38 ( V_3 ) ;
V_3 -> V_36 = - 1 ;
F_39 ( & V_3 -> V_37 ) ;
V_31 = F_40 ( V_38 | V_39 ) ;
if ( ! V_31 ) {
V_32 = - V_40 ;
goto V_41;
}
V_3 -> V_42 = F_41 ( V_31 ) ;
F_42 ( V_3 , false ) ;
F_43 ( V_3 , false ) ;
V_3 -> V_43 = false ;
V_32 = F_44 ( V_3 ) ;
if ( V_32 < 0 )
goto V_44;
return 0 ;
V_44:
F_45 ( ( unsigned long ) V_3 -> V_42 ) ;
V_41:
return V_32 ;
}
void F_46 ( struct V_2 * V_3 )
{
F_47 ( F_48 ( V_3 -> V_34 , 1 ) ) ;
F_49 ( V_3 ) ;
F_45 ( ( unsigned long ) V_3 -> V_42 ) ;
}
static inline struct V_18 * F_50 ( struct V_45 * V_46 )
{
return F_51 ( V_46 , struct V_18 , V_45 ) ;
}
static void F_52 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_49 ,
T_3 V_50 )
{
struct V_18 * V_18 = F_50 ( V_46 ) ;
int V_51 ;
V_51 = F_53 ( & V_18 -> V_52 ) ;
F_54 ( & V_18 -> V_53 ) ;
V_18 -> V_54 ++ ;
F_55 ( V_18 , V_49 , V_50 ) ;
F_56 ( & V_18 -> V_53 ) ;
F_57 ( & V_18 -> V_52 , V_51 ) ;
}
static void F_58 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_18 * V_18 = F_50 ( V_46 ) ;
int V_57 = 0 , V_51 ;
V_51 = F_53 ( & V_18 -> V_52 ) ;
F_54 ( & V_18 -> V_53 ) ;
V_18 -> V_58 ++ ;
V_57 = F_59 ( V_18 , V_55 , V_56 ) ;
V_57 |= V_18 -> V_25 ;
if ( V_57 )
F_31 ( V_18 ) ;
F_56 ( & V_18 -> V_53 ) ;
F_57 ( & V_18 -> V_52 , V_51 ) ;
}
static void F_60 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_18 * V_18 = F_50 ( V_46 ) ;
F_54 ( & V_18 -> V_53 ) ;
V_18 -> V_54 ++ ;
F_61 () ;
V_18 -> V_58 -- ;
F_56 ( & V_18 -> V_53 ) ;
F_62 ( V_18 -> V_58 < 0 ) ;
}
static int F_63 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_18 * V_18 = F_50 ( V_46 ) ;
int V_59 , V_51 ;
V_51 = F_53 ( & V_18 -> V_52 ) ;
F_54 ( & V_18 -> V_53 ) ;
V_59 = F_64 ( V_18 , V_55 , V_56 ) ;
if ( V_59 )
F_31 ( V_18 ) ;
F_56 ( & V_18 -> V_53 ) ;
F_57 ( & V_18 -> V_52 , V_51 ) ;
return V_59 ;
}
static int F_65 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_18 * V_18 = F_50 ( V_46 ) ;
int V_59 , V_51 ;
V_51 = F_53 ( & V_18 -> V_52 ) ;
F_54 ( & V_18 -> V_53 ) ;
V_59 = F_64 ( V_18 , V_55 , V_56 ) ;
F_56 ( & V_18 -> V_53 ) ;
F_57 ( & V_18 -> V_52 , V_51 ) ;
return V_59 ;
}
static int F_66 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_49 )
{
struct V_18 * V_18 = F_50 ( V_46 ) ;
int V_59 , V_51 ;
V_51 = F_53 ( & V_18 -> V_52 ) ;
F_54 ( & V_18 -> V_53 ) ;
V_59 = F_67 ( V_18 , V_49 ) ;
F_56 ( & V_18 -> V_53 ) ;
F_57 ( & V_18 -> V_52 , V_51 ) ;
return V_59 ;
}
static void F_68 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_18 * V_18 = F_50 ( V_46 ) ;
int V_51 ;
V_51 = F_53 ( & V_18 -> V_52 ) ;
F_69 ( V_18 ) ;
F_57 ( & V_18 -> V_52 , V_51 ) ;
}
static int F_70 ( struct V_18 * V_18 )
{
V_18 -> V_45 . V_60 = & V_61 ;
return F_71 ( & V_18 -> V_45 , V_62 -> V_48 ) ;
}
static int F_70 ( struct V_18 * V_18 )
{
return 0 ;
}
static struct V_63 * F_72 ( void )
{
int V_19 ;
struct V_63 * V_64 ;
V_64 = F_73 ( sizeof( struct V_63 ) , V_38 ) ;
if ( ! V_64 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_65 ; V_19 ++ )
V_64 -> V_66 [ V_19 ] = V_64 -> V_67 [ V_19 ] . V_30 = V_19 ;
return V_64 ;
}
static void F_74 ( struct V_68 * V_69 )
{
if ( ! V_69 -> V_70 )
return;
F_75 ( V_69 -> V_70 ) ;
V_69 -> V_70 = NULL ;
}
static void F_76 ( struct V_18 * V_18 , struct V_68 * free ,
struct V_68 * V_71 )
{
if ( ! V_71 || free -> V_70 != V_71 -> V_70 )
F_74 ( free ) ;
F_77 ( V_18 , free , V_71 ) ;
free -> V_72 = 0 ;
}
static void F_78 ( struct V_18 * V_18 , struct V_63 * V_64 )
{
struct V_68 * V_69 ;
if ( ! V_64 )
return;
F_79 (memslot, slots)
F_76 ( V_18 , V_69 , NULL ) ;
F_75 ( V_64 ) ;
}
static void F_80 ( struct V_18 * V_18 )
{
int V_19 ;
if ( ! V_18 -> V_73 )
return;
F_81 ( V_18 -> V_73 ) ;
if ( V_18 -> V_74 ) {
for ( V_19 = 0 ; V_19 < V_75 ; V_19 ++ )
F_82 ( V_18 -> V_74 [ V_19 ] ) ;
F_82 ( V_18 -> V_74 ) ;
}
}
static int F_83 ( struct V_18 * V_18 , int V_76 )
{
char V_77 [ V_78 * 2 ] ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_77 , sizeof( V_77 ) , L_1 , F_85 ( V_62 ) , V_76 ) ;
V_18 -> V_73 = F_86 ( V_77 ,
V_83 ) ;
if ( ! V_18 -> V_73 )
return - V_40 ;
V_18 -> V_74 = F_87 ( V_75 ,
sizeof( * V_18 -> V_74 ) ,
V_38 ) ;
if ( ! V_18 -> V_74 )
return - V_40 ;
for ( V_82 = V_84 ; V_82 -> V_85 ; V_82 ++ ) {
V_80 = F_88 ( sizeof( * V_80 ) , V_38 ) ;
if ( ! V_80 )
return - V_40 ;
V_80 -> V_18 = V_18 ;
V_80 -> V_86 = V_82 -> V_86 ;
V_18 -> V_74 [ V_82 - V_84 ] = V_80 ;
if ( ! F_89 ( V_82 -> V_85 , 0644 ,
V_18 -> V_73 ,
V_80 ,
V_87 [ V_82 -> V_88 ] ) )
return - V_40 ;
}
return 0 ;
}
static struct V_18 * F_90 ( unsigned long type )
{
int V_32 , V_19 ;
struct V_18 * V_18 = F_91 () ;
if ( ! V_18 )
return F_92 ( - V_40 ) ;
F_93 ( & V_18 -> V_53 ) ;
F_94 ( V_62 -> V_48 ) ;
V_18 -> V_48 = V_62 -> V_48 ;
F_95 ( V_18 ) ;
F_36 ( & V_18 -> V_89 ) ;
F_36 ( & V_18 -> V_90 ) ;
F_36 ( & V_18 -> V_91 ) ;
F_96 ( & V_18 -> V_92 , 1 ) ;
F_39 ( & V_18 -> V_93 ) ;
V_32 = F_97 ( V_18 , type ) ;
if ( V_32 )
goto V_94;
V_32 = F_98 () ;
if ( V_32 )
goto V_94;
#ifdef F_99
F_100 ( & V_18 -> V_95 ) ;
#endif
F_101 ( V_65 > V_96 ) ;
V_32 = - V_40 ;
for ( V_19 = 0 ; V_19 < V_97 ; V_19 ++ ) {
struct V_63 * V_64 = F_72 () ;
if ( ! V_64 )
goto V_98;
V_64 -> V_99 = V_19 * 2 - 150 ;
F_102 ( V_18 -> V_67 [ V_19 ] , V_64 ) ;
}
if ( F_103 ( & V_18 -> V_52 ) )
goto V_98;
if ( F_103 ( & V_18 -> V_100 ) )
goto V_101;
for ( V_19 = 0 ; V_19 < V_102 ; V_19 ++ ) {
F_102 ( V_18 -> V_103 [ V_19 ] ,
F_88 ( sizeof( struct V_104 ) , V_38 ) ) ;
if ( ! V_18 -> V_103 [ V_19 ] )
goto V_105;
}
V_32 = F_70 ( V_18 ) ;
if ( V_32 )
goto V_105;
F_54 ( & V_106 ) ;
F_104 ( & V_18 -> V_107 , & V_107 ) ;
F_56 ( & V_106 ) ;
F_105 () ;
return V_18 ;
V_105:
F_106 ( & V_18 -> V_100 ) ;
V_101:
F_106 ( & V_18 -> V_52 ) ;
V_98:
F_107 () ;
V_94:
for ( V_19 = 0 ; V_19 < V_102 ; V_19 ++ )
F_82 ( F_108 ( V_18 , V_19 ) ) ;
for ( V_19 = 0 ; V_19 < V_97 ; V_19 ++ )
F_78 ( V_18 , F_109 ( V_18 , V_19 ) ) ;
F_110 ( V_18 ) ;
F_111 ( V_62 -> V_48 ) ;
return F_92 ( V_32 ) ;
}
static void F_112 ( struct V_18 * V_18 )
{
struct V_108 * V_109 , * V_110 ;
F_113 (dev, tmp, &kvm->devices, vm_node) {
F_114 ( & V_109 -> V_111 ) ;
V_109 -> V_60 -> V_112 ( V_109 ) ;
}
}
static void F_115 ( struct V_18 * V_18 )
{
int V_19 ;
struct V_47 * V_48 = V_18 -> V_48 ;
F_116 ( V_113 , V_18 ) ;
F_80 ( V_18 ) ;
F_117 ( V_18 ) ;
F_54 ( & V_106 ) ;
F_114 ( & V_18 -> V_107 ) ;
F_56 ( & V_106 ) ;
F_118 ( V_18 ) ;
for ( V_19 = 0 ; V_19 < V_102 ; V_19 ++ ) {
struct V_104 * V_114 = F_108 ( V_18 , V_19 ) ;
if ( V_114 )
F_119 ( V_114 ) ;
V_18 -> V_103 [ V_19 ] = NULL ;
}
F_120 ( V_18 ) ;
#if F_121 ( V_115 ) && F_121 ( V_116 )
F_122 ( & V_18 -> V_45 , V_18 -> V_48 ) ;
#else
F_69 ( V_18 ) ;
#endif
F_123 ( V_18 ) ;
F_112 ( V_18 ) ;
for ( V_19 = 0 ; V_19 < V_97 ; V_19 ++ )
F_78 ( V_18 , F_109 ( V_18 , V_19 ) ) ;
F_106 ( & V_18 -> V_100 ) ;
F_106 ( & V_18 -> V_52 ) ;
F_110 ( V_18 ) ;
F_124 () ;
F_107 () ;
F_111 ( V_48 ) ;
}
void F_125 ( struct V_18 * V_18 )
{
F_126 ( & V_18 -> V_92 ) ;
}
void F_127 ( struct V_18 * V_18 )
{
if ( F_128 ( & V_18 -> V_92 ) )
F_115 ( V_18 ) ;
}
static int F_129 ( struct V_117 * V_117 , struct V_118 * V_119 )
{
struct V_18 * V_18 = V_119 -> V_120 ;
F_130 ( V_18 ) ;
F_127 ( V_18 ) ;
return 0 ;
}
static int F_131 ( struct V_68 * V_69 )
{
unsigned long V_121 = 2 * F_132 ( V_69 ) ;
V_69 -> V_70 = F_73 ( V_121 , V_38 ) ;
if ( ! V_69 -> V_70 )
return - V_40 ;
return 0 ;
}
static void F_133 ( struct V_63 * V_64 ,
struct V_68 * V_122 )
{
int V_30 = V_122 -> V_30 ;
int V_19 = V_64 -> V_66 [ V_30 ] ;
struct V_68 * V_123 = V_64 -> V_67 ;
F_134 ( V_123 [ V_19 ] . V_30 != V_30 ) ;
if ( ! V_122 -> V_72 ) {
F_134 ( ! V_123 [ V_19 ] . V_72 ) ;
if ( V_123 [ V_19 ] . V_72 )
V_64 -> V_124 -- ;
} else {
if ( ! V_123 [ V_19 ] . V_72 )
V_64 -> V_124 ++ ;
}
while ( V_19 < V_65 - 1 &&
V_122 -> V_125 <= V_123 [ V_19 + 1 ] . V_125 ) {
if ( ! V_123 [ V_19 + 1 ] . V_72 )
break;
V_123 [ V_19 ] = V_123 [ V_19 + 1 ] ;
V_64 -> V_66 [ V_123 [ V_19 ] . V_30 ] = V_19 ;
V_19 ++ ;
}
if ( V_122 -> V_72 ) {
while ( V_19 > 0 &&
V_122 -> V_125 >= V_123 [ V_19 - 1 ] . V_125 ) {
V_123 [ V_19 ] = V_123 [ V_19 - 1 ] ;
V_64 -> V_66 [ V_123 [ V_19 ] . V_30 ] = V_19 ;
V_19 -- ;
}
} else
F_135 ( V_19 != V_64 -> V_124 ) ;
V_123 [ V_19 ] = * V_122 ;
V_64 -> V_66 [ V_123 [ V_19 ] . V_30 ] = V_19 ;
}
static int F_136 ( const struct V_126 * V_127 )
{
T_4 V_128 = V_129 ;
#ifdef F_137
V_128 |= V_130 ;
#endif
if ( V_127 -> V_131 & ~ V_128 )
return - V_132 ;
return 0 ;
}
static struct V_63 * F_138 ( struct V_18 * V_18 ,
int V_133 , struct V_63 * V_64 )
{
struct V_63 * V_134 = F_109 ( V_18 , V_133 ) ;
F_134 ( V_134 -> V_99 & 1 ) ;
V_64 -> V_99 = V_134 -> V_99 + 1 ;
F_102 ( V_18 -> V_67 [ V_133 ] , V_64 ) ;
F_139 ( & V_18 -> V_52 ) ;
V_64 -> V_99 += V_97 * 2 - 1 ;
F_140 ( V_18 , V_64 ) ;
return V_134 ;
}
int F_141 ( struct V_18 * V_18 ,
const struct V_126 * V_127 )
{
int V_32 ;
T_5 V_125 ;
unsigned long V_72 ;
struct V_68 * V_135 ;
struct V_68 V_136 , V_122 ;
struct V_63 * V_64 = NULL , * V_134 ;
int V_133 , V_30 ;
enum V_137 V_138 ;
V_32 = F_136 ( V_127 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_132 ;
V_133 = V_127 -> V_135 >> 16 ;
V_30 = ( V_140 ) V_127 -> V_135 ;
if ( V_127 -> V_141 & ( V_142 - 1 ) )
goto V_139;
if ( V_127 -> V_143 & ( V_142 - 1 ) )
goto V_139;
if ( ( V_30 < V_144 ) &&
( ( V_127 -> V_145 & ( V_142 - 1 ) ) ||
! F_142 ( V_146 ,
( void V_147 * ) ( unsigned long ) V_127 -> V_145 ,
V_127 -> V_141 ) ) )
goto V_139;
if ( V_133 >= V_97 || V_30 >= V_65 )
goto V_139;
if ( V_127 -> V_143 + V_127 -> V_141 < V_127 -> V_143 )
goto V_139;
V_135 = F_143 ( F_109 ( V_18 , V_133 ) , V_30 ) ;
V_125 = V_127 -> V_143 >> V_148 ;
V_72 = V_127 -> V_141 >> V_148 ;
if ( V_72 > V_149 )
goto V_139;
V_122 = V_136 = * V_135 ;
V_122 . V_30 = V_30 ;
V_122 . V_125 = V_125 ;
V_122 . V_72 = V_72 ;
V_122 . V_131 = V_127 -> V_131 ;
if ( V_72 ) {
if ( ! V_136 . V_72 )
V_138 = V_150 ;
else {
if ( ( V_127 -> V_145 != V_136 . V_145 ) ||
( V_72 != V_136 . V_72 ) ||
( ( V_122 . V_131 ^ V_136 . V_131 ) & V_130 ) )
goto V_139;
if ( V_125 != V_136 . V_125 )
V_138 = V_151 ;
else if ( V_122 . V_131 != V_136 . V_131 )
V_138 = V_152 ;
else {
V_32 = 0 ;
goto V_139;
}
}
} else {
if ( ! V_136 . V_72 )
goto V_139;
V_138 = V_153 ;
V_122 . V_125 = 0 ;
V_122 . V_131 = 0 ;
}
if ( ( V_138 == V_150 ) || ( V_138 == V_151 ) ) {
V_32 = - V_154 ;
F_79 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_135 -> V_30 >= V_144 ) ||
( V_135 -> V_30 == V_30 ) )
continue;
if ( ! ( ( V_125 + V_72 <= V_135 -> V_125 ) ||
( V_125 >= V_135 -> V_125 + V_135 -> V_72 ) ) )
goto V_139;
}
}
if ( ! ( V_122 . V_131 & V_129 ) )
V_122 . V_70 = NULL ;
V_32 = - V_40 ;
if ( V_138 == V_150 ) {
V_122 . V_145 = V_127 -> V_145 ;
if ( F_144 ( V_18 , & V_122 , V_72 ) )
goto V_155;
}
if ( ( V_122 . V_131 & V_129 ) && ! V_122 . V_70 ) {
if ( F_131 ( & V_122 ) < 0 )
goto V_155;
}
V_64 = F_73 ( sizeof( struct V_63 ) , V_38 ) ;
if ( ! V_64 )
goto V_155;
memcpy ( V_64 , F_109 ( V_18 , V_133 ) , sizeof( struct V_63 ) ) ;
if ( ( V_138 == V_153 ) || ( V_138 == V_151 ) ) {
V_135 = F_143 ( V_64 , V_30 ) ;
V_135 -> V_131 |= V_156 ;
V_134 = F_138 ( V_18 , V_133 , V_64 ) ;
F_145 ( V_18 , V_135 ) ;
V_64 = V_134 ;
}
V_32 = F_146 ( V_18 , & V_122 , V_127 , V_138 ) ;
if ( V_32 )
goto V_157;
if ( V_138 == V_153 ) {
V_122 . V_70 = NULL ;
memset ( & V_122 . V_158 , 0 , sizeof( V_122 . V_158 ) ) ;
}
F_133 ( V_64 , & V_122 ) ;
V_134 = F_138 ( V_18 , V_133 , V_64 ) ;
F_147 ( V_18 , V_127 , & V_136 , & V_122 , V_138 ) ;
F_76 ( V_18 , & V_136 , & V_122 ) ;
F_75 ( V_134 ) ;
return 0 ;
V_157:
F_75 ( V_64 ) ;
V_155:
F_76 ( V_18 , & V_122 , & V_136 ) ;
V_139:
return V_32 ;
}
int F_148 ( struct V_18 * V_18 ,
const struct V_126 * V_127 )
{
int V_32 ;
F_149 ( & V_18 -> V_91 ) ;
V_32 = F_141 ( V_18 , V_127 ) ;
F_16 ( & V_18 -> V_91 ) ;
return V_32 ;
}
static int F_150 ( struct V_18 * V_18 ,
struct V_126 * V_127 )
{
if ( ( V_140 ) V_127 -> V_135 >= V_144 )
return - V_132 ;
return F_148 ( V_18 , V_127 ) ;
}
int F_151 ( struct V_18 * V_18 ,
struct V_159 * log , int * V_160 )
{
struct V_63 * V_64 ;
struct V_68 * V_69 ;
int V_19 , V_133 , V_30 ;
unsigned long V_161 ;
unsigned long V_162 = 0 ;
V_133 = log -> V_135 >> 16 ;
V_30 = ( V_140 ) log -> V_135 ;
if ( V_133 >= V_97 || V_30 >= V_144 )
return - V_132 ;
V_64 = F_109 ( V_18 , V_133 ) ;
V_69 = F_143 ( V_64 , V_30 ) ;
if ( ! V_69 -> V_70 )
return - V_163 ;
V_161 = F_132 ( V_69 ) ;
for ( V_19 = 0 ; ! V_162 && V_19 < V_161 / sizeof( long ) ; ++ V_19 )
V_162 = V_69 -> V_70 [ V_19 ] ;
if ( F_152 ( log -> V_70 , V_69 -> V_70 , V_161 ) )
return - V_164 ;
if ( V_162 )
* V_160 = 1 ;
return 0 ;
}
int F_153 ( struct V_18 * V_18 ,
struct V_159 * log , bool * V_160 )
{
struct V_63 * V_64 ;
struct V_68 * V_69 ;
int V_19 , V_133 , V_30 ;
unsigned long V_161 ;
unsigned long * V_70 ;
unsigned long * V_165 ;
V_133 = log -> V_135 >> 16 ;
V_30 = ( V_140 ) log -> V_135 ;
if ( V_133 >= V_97 || V_30 >= V_144 )
return - V_132 ;
V_64 = F_109 ( V_18 , V_133 ) ;
V_69 = F_143 ( V_64 , V_30 ) ;
V_70 = V_69 -> V_70 ;
if ( ! V_70 )
return - V_163 ;
V_161 = F_132 ( V_69 ) ;
V_165 = V_70 + V_161 / sizeof( long ) ;
memset ( V_165 , 0 , V_161 ) ;
F_54 ( & V_18 -> V_53 ) ;
* V_160 = false ;
for ( V_19 = 0 ; V_19 < V_161 / sizeof( long ) ; V_19 ++ ) {
unsigned long V_166 ;
T_5 V_86 ;
if ( ! V_70 [ V_19 ] )
continue;
* V_160 = true ;
V_166 = F_154 ( & V_70 [ V_19 ] , 0 ) ;
V_165 [ V_19 ] = V_166 ;
if ( V_166 ) {
V_86 = V_19 * V_167 ;
F_155 ( V_18 , V_69 ,
V_86 , V_166 ) ;
}
}
F_56 ( & V_18 -> V_53 ) ;
if ( F_152 ( log -> V_70 , V_165 , V_161 ) )
return - V_164 ;
return 0 ;
}
bool F_156 ( void )
{
return V_168 ;
}
void F_157 ( void )
{
V_168 = false ;
}
struct V_68 * F_158 ( struct V_18 * V_18 , T_5 V_169 )
{
return F_159 ( V_63 ( V_18 ) , V_169 ) ;
}
struct V_68 * F_160 ( struct V_2 * V_3 , T_5 V_169 )
{
return F_159 ( F_161 ( V_3 ) , V_169 ) ;
}
bool F_162 ( struct V_18 * V_18 , T_5 V_169 )
{
struct V_68 * V_69 = F_158 ( V_18 , V_169 ) ;
if ( ! V_69 || V_69 -> V_30 >= V_144 ||
V_69 -> V_131 & V_156 )
return false ;
return true ;
}
unsigned long F_163 ( struct V_18 * V_18 , T_5 V_169 )
{
struct V_170 * V_171 ;
unsigned long V_172 , V_173 ;
V_173 = V_142 ;
V_172 = F_164 ( V_18 , V_169 ) ;
if ( F_165 ( V_172 ) )
return V_142 ;
F_166 ( & V_62 -> V_48 -> V_174 ) ;
V_171 = F_167 ( V_62 -> V_48 , V_172 ) ;
if ( ! V_171 )
goto V_139;
V_173 = F_168 ( V_171 ) ;
V_139:
F_169 ( & V_62 -> V_48 -> V_174 ) ;
return V_173 ;
}
static bool F_170 ( struct V_68 * V_135 )
{
return V_135 -> V_131 & V_130 ;
}
static unsigned long F_171 ( struct V_68 * V_135 , T_5 V_169 ,
T_5 * V_175 , bool V_176 )
{
if ( ! V_135 || V_135 -> V_131 & V_156 )
return V_177 ;
if ( F_170 ( V_135 ) && V_176 )
return V_178 ;
if ( V_175 )
* V_175 = V_135 -> V_72 - ( V_169 - V_135 -> V_125 ) ;
return F_172 ( V_135 , V_169 ) ;
}
static unsigned long F_173 ( struct V_68 * V_135 , T_5 V_169 ,
T_5 * V_175 )
{
return F_171 ( V_135 , V_169 , V_175 , true ) ;
}
unsigned long F_174 ( struct V_68 * V_135 ,
T_5 V_169 )
{
return F_173 ( V_135 , V_169 , NULL ) ;
}
unsigned long F_164 ( struct V_18 * V_18 , T_5 V_169 )
{
return F_173 ( F_158 ( V_18 , V_169 ) , V_169 , NULL ) ;
}
unsigned long F_175 ( struct V_2 * V_3 , T_5 V_169 )
{
return F_173 ( F_160 ( V_3 , V_169 ) , V_169 , NULL ) ;
}
unsigned long F_176 ( struct V_68 * V_135 ,
T_5 V_169 , bool * V_179 )
{
unsigned long V_180 = F_171 ( V_135 , V_169 , NULL , false ) ;
if ( ! F_165 ( V_180 ) && V_179 )
* V_179 = ! F_170 ( V_135 ) ;
return V_180 ;
}
unsigned long F_177 ( struct V_18 * V_18 , T_5 V_169 , bool * V_179 )
{
struct V_68 * V_135 = F_158 ( V_18 , V_169 ) ;
return F_176 ( V_135 , V_169 , V_179 ) ;
}
unsigned long F_178 ( struct V_2 * V_3 , T_5 V_169 , bool * V_179 )
{
struct V_68 * V_135 = F_160 ( V_3 , V_169 ) ;
return F_176 ( V_135 , V_169 , V_179 ) ;
}
static int F_179 ( unsigned long V_55 , int V_176 ,
struct V_31 * * V_31 )
{
int V_131 = V_181 | V_182 ;
if ( V_176 )
V_131 |= V_183 ;
return F_180 ( V_55 , 1 , V_131 , V_31 , NULL ) ;
}
static inline int F_181 ( unsigned long V_172 )
{
int V_184 , V_131 = V_182 | V_183 ;
V_184 = F_180 ( V_172 , 1 , V_131 , NULL , NULL ) ;
return V_184 == - V_185 ;
}
static bool F_182 ( unsigned long V_172 , bool V_186 , bool * V_187 ,
bool V_188 , bool * V_179 , T_1 * V_1 )
{
struct V_31 * V_31 [ 1 ] ;
int V_72 ;
if ( ! ( V_187 || V_186 ) )
return false ;
if ( ! ( V_188 || V_179 ) )
return false ;
V_72 = F_183 ( V_172 , 1 , 1 , V_31 ) ;
if ( V_72 == 1 ) {
* V_1 = F_184 ( V_31 [ 0 ] ) ;
if ( V_179 )
* V_179 = true ;
return true ;
}
return false ;
}
static int F_185 ( unsigned long V_172 , bool * V_187 , bool V_188 ,
bool * V_179 , T_1 * V_1 )
{
struct V_31 * V_31 [ 1 ] ;
int V_72 = 0 ;
F_186 () ;
if ( V_179 )
* V_179 = V_188 ;
if ( V_187 ) {
F_166 ( & V_62 -> V_48 -> V_174 ) ;
V_72 = F_179 ( V_172 , V_188 , V_31 ) ;
F_169 ( & V_62 -> V_48 -> V_174 ) ;
} else {
unsigned int V_131 = V_182 ;
if ( V_188 )
V_131 |= V_183 ;
V_72 = F_187 ( V_172 , 1 , V_31 , V_131 ) ;
}
if ( V_72 != 1 )
return V_72 ;
if ( F_21 ( ! V_188 ) && V_179 ) {
struct V_31 * V_189 [ 1 ] ;
V_72 = F_183 ( V_172 , 1 , 1 , V_189 ) ;
if ( V_72 == 1 ) {
* V_179 = true ;
F_188 ( V_31 [ 0 ] ) ;
V_31 [ 0 ] = V_189 [ 0 ] ;
}
V_72 = 1 ;
}
* V_1 = F_184 ( V_31 [ 0 ] ) ;
return V_72 ;
}
static bool F_189 ( struct V_170 * V_171 , bool V_188 )
{
if ( F_21 ( ! ( V_171 -> V_190 & V_191 ) ) )
return false ;
if ( V_188 && ( F_21 ( ! ( V_171 -> V_190 & V_192 ) ) ) )
return false ;
return true ;
}
static int F_190 ( struct V_170 * V_171 ,
unsigned long V_172 , bool * V_187 ,
bool V_188 , T_1 * V_193 )
{
unsigned long V_1 ;
int V_32 ;
V_32 = F_191 ( V_171 , V_172 , & V_1 ) ;
if ( V_32 ) {
bool V_194 = false ;
V_32 = F_192 ( V_62 , V_62 -> V_48 , V_172 ,
( V_188 ? V_195 : 0 ) ,
& V_194 ) ;
if ( V_194 )
return - V_196 ;
if ( V_32 )
return V_32 ;
V_32 = F_191 ( V_171 , V_172 , & V_1 ) ;
if ( V_32 )
return V_32 ;
}
F_193 ( V_1 ) ;
* V_193 = V_1 ;
return 0 ;
}
static T_1 F_194 ( unsigned long V_172 , bool V_186 , bool * V_187 ,
bool V_188 , bool * V_179 )
{
struct V_170 * V_171 ;
T_1 V_1 = 0 ;
int V_72 , V_32 ;
F_62 ( V_186 && V_187 ) ;
if ( F_182 ( V_172 , V_186 , V_187 , V_188 , V_179 , & V_1 ) )
return V_1 ;
if ( V_186 )
return V_197 ;
V_72 = F_185 ( V_172 , V_187 , V_188 , V_179 , & V_1 ) ;
if ( V_72 == 1 )
return V_1 ;
F_166 ( & V_62 -> V_48 -> V_174 ) ;
if ( V_72 == - V_185 ||
( ! V_187 && F_181 ( V_172 ) ) ) {
V_1 = V_198 ;
goto exit;
}
V_199:
V_171 = F_195 ( V_62 -> V_48 , V_172 , V_172 + 1 ) ;
if ( V_171 == NULL )
V_1 = V_197 ;
else if ( V_171 -> V_190 & ( V_200 | V_201 ) ) {
V_32 = F_190 ( V_171 , V_172 , V_187 , V_188 , & V_1 ) ;
if ( V_32 == - V_196 )
goto V_199;
if ( V_32 < 0 )
V_1 = V_197 ;
} else {
if ( V_187 && F_189 ( V_171 , V_188 ) )
* V_187 = true ;
V_1 = V_197 ;
}
exit:
F_169 ( & V_62 -> V_48 -> V_174 ) ;
return V_1 ;
}
T_1 F_196 ( struct V_68 * V_135 , T_5 V_169 ,
bool V_186 , bool * V_187 , bool V_188 ,
bool * V_179 )
{
unsigned long V_172 = F_171 ( V_135 , V_169 , NULL , V_188 ) ;
if ( V_172 == V_178 ) {
if ( V_179 )
* V_179 = false ;
return V_202 ;
}
if ( F_165 ( V_172 ) ) {
if ( V_179 )
* V_179 = false ;
return V_203 ;
}
if ( V_179 && F_170 ( V_135 ) ) {
* V_179 = false ;
V_179 = NULL ;
}
return F_194 ( V_172 , V_186 , V_187 , V_188 ,
V_179 ) ;
}
T_1 F_197 ( struct V_18 * V_18 , T_5 V_169 , bool V_188 ,
bool * V_179 )
{
return F_196 ( F_158 ( V_18 , V_169 ) , V_169 , false , NULL ,
V_188 , V_179 ) ;
}
T_1 F_198 ( struct V_68 * V_135 , T_5 V_169 )
{
return F_196 ( V_135 , V_169 , false , NULL , true , NULL ) ;
}
T_1 F_199 ( struct V_68 * V_135 , T_5 V_169 )
{
return F_196 ( V_135 , V_169 , true , NULL , true , NULL ) ;
}
T_1 F_200 ( struct V_18 * V_18 , T_5 V_169 )
{
return F_199 ( F_158 ( V_18 , V_169 ) , V_169 ) ;
}
T_1 F_201 ( struct V_2 * V_3 , T_5 V_169 )
{
return F_199 ( F_160 ( V_3 , V_169 ) , V_169 ) ;
}
T_1 F_202 ( struct V_18 * V_18 , T_5 V_169 )
{
return F_198 ( F_158 ( V_18 , V_169 ) , V_169 ) ;
}
T_1 F_203 ( struct V_2 * V_3 , T_5 V_169 )
{
return F_198 ( F_160 ( V_3 , V_169 ) , V_169 ) ;
}
int F_204 ( struct V_68 * V_135 , T_5 V_169 ,
struct V_31 * * V_204 , int V_175 )
{
unsigned long V_172 ;
T_5 V_205 ;
V_172 = F_173 ( V_135 , V_169 , & V_205 ) ;
if ( F_165 ( V_172 ) )
return - 1 ;
if ( V_205 < V_175 )
return 0 ;
return F_183 ( V_172 , V_175 , 1 , V_204 ) ;
}
static struct V_31 * F_205 ( T_1 V_1 )
{
if ( F_206 ( V_1 ) )
return V_206 ;
if ( F_1 ( V_1 ) ) {
F_134 ( 1 ) ;
return V_206 ;
}
return F_4 ( V_1 ) ;
}
struct V_31 * F_207 ( struct V_18 * V_18 , T_5 V_169 )
{
T_1 V_1 ;
V_1 = F_202 ( V_18 , V_169 ) ;
return F_205 ( V_1 ) ;
}
struct V_31 * F_208 ( struct V_2 * V_3 , T_5 V_169 )
{
T_1 V_1 ;
V_1 = F_203 ( V_3 , V_169 ) ;
return F_205 ( V_1 ) ;
}
void F_209 ( struct V_31 * V_31 )
{
F_134 ( F_210 ( V_31 ) ) ;
F_211 ( F_184 ( V_31 ) ) ;
}
void F_211 ( T_1 V_1 )
{
if ( ! F_206 ( V_1 ) && ! F_1 ( V_1 ) )
F_188 ( F_4 ( V_1 ) ) ;
}
void F_212 ( struct V_31 * V_31 )
{
F_134 ( F_210 ( V_31 ) ) ;
F_213 ( F_184 ( V_31 ) ) ;
}
static void F_213 ( T_1 V_1 )
{
F_214 ( V_1 ) ;
F_211 ( V_1 ) ;
}
void F_214 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_31 * V_31 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_31 ) )
F_215 ( V_31 ) ;
}
}
void F_216 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_217 ( F_4 ( V_1 ) ) ;
}
void F_193 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_218 ( F_4 ( V_1 ) ) ;
}
static int F_219 ( unsigned long V_207 , int V_86 )
{
if ( V_207 > V_142 - V_86 )
return V_142 - V_86 ;
else
return V_207 ;
}
static int F_220 ( struct V_68 * V_135 , T_5 V_169 ,
void * V_208 , int V_86 , int V_207 )
{
int V_32 ;
unsigned long V_172 ;
V_172 = F_176 ( V_135 , V_169 , NULL ) ;
if ( F_165 ( V_172 ) )
return - V_164 ;
V_32 = F_221 ( V_208 , ( void V_147 * ) V_172 + V_86 , V_207 ) ;
if ( V_32 )
return - V_164 ;
return 0 ;
}
int F_222 ( struct V_18 * V_18 , T_5 V_169 , void * V_208 , int V_86 ,
int V_207 )
{
struct V_68 * V_135 = F_158 ( V_18 , V_169 ) ;
return F_220 ( V_135 , V_169 , V_208 , V_86 , V_207 ) ;
}
int F_223 ( struct V_2 * V_3 , T_5 V_169 , void * V_208 ,
int V_86 , int V_207 )
{
struct V_68 * V_135 = F_160 ( V_3 , V_169 ) ;
return F_220 ( V_135 , V_169 , V_208 , V_86 , V_207 ) ;
}
int F_224 ( struct V_18 * V_18 , T_6 V_209 , void * V_208 , unsigned long V_207 )
{
T_5 V_169 = V_209 >> V_148 ;
int V_210 ;
int V_86 = F_225 ( V_209 ) ;
int V_211 ;
while ( ( V_210 = F_219 ( V_207 , V_86 ) ) != 0 ) {
V_211 = F_222 ( V_18 , V_169 , V_208 , V_86 , V_210 ) ;
if ( V_211 < 0 )
return V_211 ;
V_86 = 0 ;
V_207 -= V_210 ;
V_208 += V_210 ;
++ V_169 ;
}
return 0 ;
}
int F_226 ( struct V_2 * V_3 , T_6 V_209 , void * V_208 , unsigned long V_207 )
{
T_5 V_169 = V_209 >> V_148 ;
int V_210 ;
int V_86 = F_225 ( V_209 ) ;
int V_211 ;
while ( ( V_210 = F_219 ( V_207 , V_86 ) ) != 0 ) {
V_211 = F_223 ( V_3 , V_169 , V_208 , V_86 , V_210 ) ;
if ( V_211 < 0 )
return V_211 ;
V_86 = 0 ;
V_207 -= V_210 ;
V_208 += V_210 ;
++ V_169 ;
}
return 0 ;
}
static int F_227 ( struct V_68 * V_135 , T_5 V_169 ,
void * V_208 , int V_86 , unsigned long V_207 )
{
int V_32 ;
unsigned long V_172 ;
V_172 = F_176 ( V_135 , V_169 , NULL ) ;
if ( F_165 ( V_172 ) )
return - V_164 ;
F_228 () ;
V_32 = F_229 ( V_208 , ( void V_147 * ) V_172 + V_86 , V_207 ) ;
F_230 () ;
if ( V_32 )
return - V_164 ;
return 0 ;
}
int F_231 ( struct V_18 * V_18 , T_6 V_209 , void * V_208 ,
unsigned long V_207 )
{
T_5 V_169 = V_209 >> V_148 ;
struct V_68 * V_135 = F_158 ( V_18 , V_169 ) ;
int V_86 = F_225 ( V_209 ) ;
return F_227 ( V_135 , V_169 , V_208 , V_86 , V_207 ) ;
}
int F_232 ( struct V_2 * V_3 , T_6 V_209 ,
void * V_208 , unsigned long V_207 )
{
T_5 V_169 = V_209 >> V_148 ;
struct V_68 * V_135 = F_160 ( V_3 , V_169 ) ;
int V_86 = F_225 ( V_209 ) ;
return F_227 ( V_135 , V_169 , V_208 , V_86 , V_207 ) ;
}
static int F_233 ( struct V_68 * V_69 , T_5 V_169 ,
const void * V_208 , int V_86 , int V_207 )
{
int V_32 ;
unsigned long V_172 ;
V_172 = F_174 ( V_69 , V_169 ) ;
if ( F_165 ( V_172 ) )
return - V_164 ;
V_32 = F_234 ( ( void V_147 * ) V_172 + V_86 , V_208 , V_207 ) ;
if ( V_32 )
return - V_164 ;
F_235 ( V_69 , V_169 ) ;
return 0 ;
}
int F_236 ( struct V_18 * V_18 , T_5 V_169 ,
const void * V_208 , int V_86 , int V_207 )
{
struct V_68 * V_135 = F_158 ( V_18 , V_169 ) ;
return F_233 ( V_135 , V_169 , V_208 , V_86 , V_207 ) ;
}
int F_237 ( struct V_2 * V_3 , T_5 V_169 ,
const void * V_208 , int V_86 , int V_207 )
{
struct V_68 * V_135 = F_160 ( V_3 , V_169 ) ;
return F_233 ( V_135 , V_169 , V_208 , V_86 , V_207 ) ;
}
int F_238 ( struct V_18 * V_18 , T_6 V_209 , const void * V_208 ,
unsigned long V_207 )
{
T_5 V_169 = V_209 >> V_148 ;
int V_210 ;
int V_86 = F_225 ( V_209 ) ;
int V_211 ;
while ( ( V_210 = F_219 ( V_207 , V_86 ) ) != 0 ) {
V_211 = F_236 ( V_18 , V_169 , V_208 , V_86 , V_210 ) ;
if ( V_211 < 0 )
return V_211 ;
V_86 = 0 ;
V_207 -= V_210 ;
V_208 += V_210 ;
++ V_169 ;
}
return 0 ;
}
int F_239 ( struct V_2 * V_3 , T_6 V_209 , const void * V_208 ,
unsigned long V_207 )
{
T_5 V_169 = V_209 >> V_148 ;
int V_210 ;
int V_86 = F_225 ( V_209 ) ;
int V_211 ;
while ( ( V_210 = F_219 ( V_207 , V_86 ) ) != 0 ) {
V_211 = F_237 ( V_3 , V_169 , V_208 , V_86 , V_210 ) ;
if ( V_211 < 0 )
return V_211 ;
V_86 = 0 ;
V_207 -= V_210 ;
V_208 += V_210 ;
++ V_169 ;
}
return 0 ;
}
static int F_240 ( struct V_63 * V_64 ,
struct V_212 * V_213 ,
T_6 V_209 , unsigned long V_207 )
{
int V_86 = F_225 ( V_209 ) ;
T_5 V_214 = V_209 >> V_148 ;
T_5 V_215 = ( V_209 + V_207 - 1 ) >> V_148 ;
T_5 V_216 = V_215 - V_214 + 1 ;
T_5 V_217 ;
V_213 -> V_209 = V_209 ;
V_213 -> V_99 = V_64 -> V_99 ;
V_213 -> V_207 = V_207 ;
V_213 -> V_69 = F_159 ( V_64 , V_214 ) ;
V_213 -> V_180 = F_173 ( V_213 -> V_69 , V_214 , NULL ) ;
if ( ! F_165 ( V_213 -> V_180 ) && V_216 <= 1 ) {
V_213 -> V_180 += V_86 ;
} else {
while ( V_214 <= V_215 ) {
V_213 -> V_69 = F_159 ( V_64 , V_214 ) ;
V_213 -> V_180 = F_173 ( V_213 -> V_69 , V_214 ,
& V_217 ) ;
if ( F_165 ( V_213 -> V_180 ) )
return - V_164 ;
V_214 += V_217 ;
}
V_213 -> V_69 = NULL ;
}
return 0 ;
}
int F_241 ( struct V_18 * V_18 , struct V_212 * V_213 ,
T_6 V_209 , unsigned long V_207 )
{
struct V_63 * V_64 = V_63 ( V_18 ) ;
return F_240 ( V_64 , V_213 , V_209 , V_207 ) ;
}
int F_242 ( struct V_18 * V_18 , struct V_212 * V_213 ,
void * V_208 , int V_86 , unsigned long V_207 )
{
struct V_63 * V_64 = V_63 ( V_18 ) ;
int V_32 ;
T_6 V_209 = V_213 -> V_209 + V_86 ;
F_62 ( V_207 + V_86 > V_213 -> V_207 ) ;
if ( V_64 -> V_99 != V_213 -> V_99 )
F_240 ( V_64 , V_213 , V_213 -> V_209 , V_213 -> V_207 ) ;
if ( F_21 ( ! V_213 -> V_69 ) )
return F_238 ( V_18 , V_209 , V_208 , V_207 ) ;
if ( F_165 ( V_213 -> V_180 ) )
return - V_164 ;
V_32 = F_234 ( ( void V_147 * ) V_213 -> V_180 + V_86 , V_208 , V_207 ) ;
if ( V_32 )
return - V_164 ;
F_235 ( V_213 -> V_69 , V_209 >> V_148 ) ;
return 0 ;
}
int F_243 ( struct V_18 * V_18 , struct V_212 * V_213 ,
void * V_208 , unsigned long V_207 )
{
return F_242 ( V_18 , V_213 , V_208 , 0 , V_207 ) ;
}
int F_244 ( struct V_18 * V_18 , struct V_212 * V_213 ,
void * V_208 , unsigned long V_207 )
{
struct V_63 * V_64 = V_63 ( V_18 ) ;
int V_32 ;
F_62 ( V_207 > V_213 -> V_207 ) ;
if ( V_64 -> V_99 != V_213 -> V_99 )
F_240 ( V_64 , V_213 , V_213 -> V_209 , V_213 -> V_207 ) ;
if ( F_21 ( ! V_213 -> V_69 ) )
return F_224 ( V_18 , V_213 -> V_209 , V_208 , V_207 ) ;
if ( F_165 ( V_213 -> V_180 ) )
return - V_164 ;
V_32 = F_221 ( V_208 , ( void V_147 * ) V_213 -> V_180 , V_207 ) ;
if ( V_32 )
return - V_164 ;
return 0 ;
}
int F_245 ( struct V_18 * V_18 , T_5 V_169 , int V_86 , int V_207 )
{
const void * V_218 = ( const void * ) F_246 ( F_247 ( F_248 ( 0 ) ) ) ;
return F_236 ( V_18 , V_169 , V_218 , V_86 , V_207 ) ;
}
int F_249 ( struct V_18 * V_18 , T_6 V_209 , unsigned long V_207 )
{
T_5 V_169 = V_209 >> V_148 ;
int V_210 ;
int V_86 = F_225 ( V_209 ) ;
int V_211 ;
while ( ( V_210 = F_219 ( V_207 , V_86 ) ) != 0 ) {
V_211 = F_245 ( V_18 , V_169 , V_86 , V_210 ) ;
if ( V_211 < 0 )
return V_211 ;
V_86 = 0 ;
V_207 -= V_210 ;
++ V_169 ;
}
return 0 ;
}
static void F_235 ( struct V_68 * V_69 ,
T_5 V_169 )
{
if ( V_69 && V_69 -> V_70 ) {
unsigned long V_219 = V_169 - V_69 -> V_125 ;
F_250 ( V_219 , V_69 -> V_70 ) ;
}
}
void F_251 ( struct V_18 * V_18 , T_5 V_169 )
{
struct V_68 * V_69 ;
V_69 = F_158 ( V_18 , V_169 ) ;
F_235 ( V_69 , V_169 ) ;
}
void F_252 ( struct V_2 * V_3 , T_5 V_169 )
{
struct V_68 * V_69 ;
V_69 = F_160 ( V_3 , V_169 ) ;
F_235 ( V_69 , V_169 ) ;
}
static void F_253 ( struct V_2 * V_3 )
{
unsigned int V_136 , V_220 , V_221 ;
V_136 = V_220 = V_3 -> V_222 ;
V_221 = F_254 ( V_223 ) ;
if ( V_220 == 0 && V_221 )
V_220 = 10000 ;
else
V_220 *= V_221 ;
if ( V_220 > V_222 )
V_220 = V_222 ;
V_3 -> V_222 = V_220 ;
F_255 ( V_3 -> V_33 , V_220 , V_136 ) ;
}
static void F_256 ( struct V_2 * V_3 )
{
unsigned int V_136 , V_220 , V_224 ;
V_136 = V_220 = V_3 -> V_222 ;
V_224 = F_254 ( V_225 ) ;
if ( V_224 == 0 )
V_220 = 0 ;
else
V_220 /= V_224 ;
V_3 -> V_222 = V_220 ;
F_257 ( V_3 -> V_33 , V_220 , V_136 ) ;
}
static int F_258 ( struct V_2 * V_3 )
{
if ( F_259 ( V_3 ) ) {
F_27 ( V_226 , V_3 ) ;
return - V_6 ;
}
if ( F_260 ( V_3 ) )
return - V_6 ;
if ( F_261 ( V_62 ) )
return - V_6 ;
return 0 ;
}
void F_262 ( struct V_2 * V_3 )
{
T_7 V_55 , V_227 ;
F_263 ( V_16 ) ;
bool V_228 = false ;
T_8 V_229 ;
V_55 = V_227 = F_264 () ;
if ( V_3 -> V_222 ) {
T_7 V_230 = F_265 ( F_264 () , V_3 -> V_222 ) ;
++ V_3 -> V_27 . V_231 ;
do {
if ( F_258 ( V_3 ) < 0 ) {
++ V_3 -> V_27 . V_232 ;
if ( ! F_266 ( V_3 ) )
++ V_3 -> V_27 . V_233 ;
goto V_139;
}
V_227 = F_264 () ;
} while ( F_267 () && F_268 ( V_227 , V_230 ) );
}
F_269 ( V_3 ) ;
for (; ; ) {
F_270 ( & V_3 -> V_35 , & V_16 , V_234 ) ;
if ( F_258 ( V_3 ) < 0 )
break;
V_228 = true ;
F_271 () ;
}
F_272 ( & V_3 -> V_35 , & V_16 ) ;
V_227 = F_264 () ;
F_273 ( V_3 ) ;
V_139:
V_229 = F_274 ( V_227 ) - F_274 ( V_55 ) ;
if ( ! F_266 ( V_3 ) )
F_256 ( V_3 ) ;
else if ( V_222 ) {
if ( V_229 <= V_3 -> V_222 )
;
else if ( V_3 -> V_222 && V_229 > V_222 )
F_256 ( V_3 ) ;
else if ( V_3 -> V_222 < V_222 &&
V_229 < V_222 )
F_253 ( V_3 ) ;
} else
V_3 -> V_222 = 0 ;
F_275 ( V_229 , V_228 , F_266 ( V_3 ) ) ;
F_276 ( V_3 ) ;
}
bool F_28 ( struct V_2 * V_3 )
{
struct V_235 * V_236 ;
V_236 = F_277 ( V_3 ) ;
if ( F_278 ( V_236 ) ) {
F_279 ( V_236 ) ;
++ V_3 -> V_27 . V_237 ;
return true ;
}
return false ;
}
void F_280 ( struct V_2 * V_3 )
{
int V_20 ;
int V_4 = V_3 -> V_4 ;
if ( F_28 ( V_3 ) )
return;
V_20 = F_7 () ;
if ( V_4 != V_20 && ( unsigned ) V_4 < V_238 && F_281 ( V_4 ) )
if ( F_282 ( V_3 ) )
F_283 ( V_4 ) ;
F_10 () ;
}
int F_284 ( struct V_2 * V_239 )
{
struct V_34 * V_34 ;
struct V_240 * V_241 = NULL ;
int V_211 = 0 ;
F_285 () ;
V_34 = F_286 ( V_239 -> V_34 ) ;
if ( V_34 )
V_241 = F_287 ( V_34 , V_242 ) ;
F_288 () ;
if ( ! V_241 )
return V_211 ;
V_211 = F_289 ( V_241 , 1 ) ;
F_290 ( V_241 ) ;
return V_211 ;
}
static bool F_291 ( struct V_2 * V_3 )
{
#ifdef F_292
bool V_243 ;
V_243 = ! V_3 -> V_244 . V_245 ||
V_3 -> V_244 . V_246 ;
if ( V_3 -> V_244 . V_245 )
F_43 ( V_3 , ! V_3 -> V_244 . V_246 ) ;
return V_243 ;
#else
return true ;
#endif
}
void F_293 ( struct V_2 * V_20 )
{
struct V_18 * V_18 = V_20 -> V_18 ;
struct V_2 * V_3 ;
int V_247 = V_20 -> V_18 -> V_247 ;
int V_248 = 0 ;
int V_249 = 3 ;
int V_250 ;
int V_19 ;
F_42 ( V_20 , true ) ;
for ( V_250 = 0 ; V_250 < 2 && ! V_248 && V_249 ; V_250 ++ ) {
F_26 (i, vcpu, kvm) {
if ( ! V_250 && V_19 <= V_247 ) {
V_19 = V_247 ;
continue;
} else if ( V_250 && V_19 > V_247 )
break;
if ( ! F_294 ( V_3 -> V_43 ) )
continue;
if ( V_3 == V_20 )
continue;
if ( F_278 ( & V_3 -> V_35 ) && ! F_259 ( V_3 ) )
continue;
if ( ! F_291 ( V_3 ) )
continue;
V_248 = F_284 ( V_3 ) ;
if ( V_248 > 0 ) {
V_18 -> V_247 = V_19 ;
break;
} else if ( V_248 < 0 ) {
V_249 -- ;
if ( ! V_249 )
break;
}
}
}
F_42 ( V_20 , false ) ;
F_43 ( V_20 , false ) ;
}
static int F_295 ( struct V_251 * V_252 )
{
struct V_2 * V_3 = V_252 -> V_171 -> V_253 -> V_120 ;
struct V_31 * V_31 ;
if ( V_252 -> V_254 == 0 )
V_31 = F_296 ( V_3 -> V_42 ) ;
#ifdef F_297
else if ( V_252 -> V_254 == V_255 )
V_31 = F_296 ( V_3 -> V_158 . V_256 ) ;
#endif
#ifdef F_298
else if ( V_252 -> V_254 == V_257 )
V_31 = F_296 ( V_3 -> V_18 -> V_258 ) ;
#endif
else
return F_299 ( V_3 , V_252 ) ;
F_218 ( V_31 ) ;
V_252 -> V_31 = V_31 ;
return 0 ;
}
static int F_300 ( struct V_118 * V_118 , struct V_170 * V_171 )
{
V_171 -> V_259 = & V_260 ;
return 0 ;
}
static int F_301 ( struct V_117 * V_117 , struct V_118 * V_119 )
{
struct V_2 * V_3 = V_119 -> V_120 ;
F_81 ( V_3 -> V_73 ) ;
F_127 ( V_3 -> V_18 ) ;
return 0 ;
}
static int F_302 ( struct V_2 * V_3 )
{
return F_303 ( L_2 , & V_261 , V_3 , V_262 | V_263 ) ;
}
static int F_304 ( struct V_2 * V_3 )
{
char V_77 [ V_78 * 2 ] ;
int V_211 ;
if ( ! F_305 () )
return 0 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_77 , sizeof( V_77 ) , L_3 , V_3 -> V_33 ) ;
V_3 -> V_73 = F_86 ( V_77 ,
V_3 -> V_18 -> V_73 ) ;
if ( ! V_3 -> V_73 )
return - V_40 ;
V_211 = F_306 ( V_3 ) ;
if ( V_211 < 0 ) {
F_81 ( V_3 -> V_73 ) ;
return V_211 ;
}
return 0 ;
}
static int F_307 ( struct V_18 * V_18 , T_4 V_30 )
{
int V_32 ;
struct V_2 * V_3 ;
if ( V_30 >= V_264 )
return - V_132 ;
F_149 ( & V_18 -> V_89 ) ;
if ( V_18 -> V_265 == V_266 ) {
F_16 ( & V_18 -> V_89 ) ;
return - V_132 ;
}
V_18 -> V_265 ++ ;
F_16 ( & V_18 -> V_89 ) ;
V_3 = F_308 ( V_18 , V_30 ) ;
if ( F_309 ( V_3 ) ) {
V_32 = F_310 ( V_3 ) ;
goto V_267;
}
F_311 ( & V_3 -> V_7 , & V_268 ) ;
V_32 = F_312 ( V_3 ) ;
if ( V_32 )
goto V_269;
V_32 = F_304 ( V_3 ) ;
if ( V_32 )
goto V_269;
F_149 ( & V_18 -> V_89 ) ;
if ( F_313 ( V_18 , V_30 ) ) {
V_32 = - V_154 ;
goto V_270;
}
F_62 ( V_18 -> V_271 [ F_314 ( & V_18 -> V_272 ) ] ) ;
F_125 ( V_18 ) ;
V_32 = F_302 ( V_3 ) ;
if ( V_32 < 0 ) {
F_127 ( V_18 ) ;
goto V_270;
}
V_18 -> V_271 [ F_314 ( & V_18 -> V_272 ) ] = V_3 ;
F_61 () ;
F_315 ( & V_18 -> V_272 ) ;
F_16 ( & V_18 -> V_89 ) ;
F_316 ( V_3 ) ;
return V_32 ;
V_270:
F_16 ( & V_18 -> V_89 ) ;
F_81 ( V_3 -> V_73 ) ;
V_269:
F_317 ( V_3 ) ;
V_267:
F_149 ( & V_18 -> V_89 ) ;
V_18 -> V_265 -- ;
F_16 ( & V_18 -> V_89 ) ;
return V_32 ;
}
static int F_318 ( struct V_2 * V_3 , T_9 * V_273 )
{
if ( V_273 ) {
F_319 ( V_273 , F_320 ( V_274 ) | F_320 ( V_275 ) ) ;
V_3 -> V_276 = 1 ;
V_3 -> V_273 = * V_273 ;
} else
V_3 -> V_276 = 0 ;
return 0 ;
}
static long F_321 ( struct V_118 * V_119 ,
unsigned int V_277 , unsigned long V_278 )
{
struct V_2 * V_3 = V_119 -> V_120 ;
void V_147 * V_279 = ( void V_147 * ) V_278 ;
int V_32 ;
struct V_280 * V_281 = NULL ;
struct V_282 * V_282 = NULL ;
if ( V_3 -> V_18 -> V_48 != V_62 -> V_48 )
return - V_283 ;
if ( F_21 ( F_322 ( V_277 ) != V_284 ) )
return - V_132 ;
#if F_121 ( V_285 ) || F_121 ( V_286 ) || F_121 ( V_287 )
if ( V_277 == V_288 || V_277 == V_289 || V_277 == V_290 )
return F_323 ( V_119 , V_277 , V_278 ) ;
#endif
V_32 = F_5 ( V_3 ) ;
if ( V_32 )
return V_32 ;
switch ( V_277 ) {
case V_291 : {
struct V_34 * V_292 ;
V_32 = - V_132 ;
if ( V_278 )
goto V_139;
V_292 = F_324 ( V_3 -> V_34 ) ;
if ( F_21 ( V_292 != V_62 -> V_293 [ V_242 ] . V_34 ) ) {
struct V_34 * V_294 = F_325 ( V_62 , V_242 ) ;
F_102 ( V_3 -> V_34 , V_294 ) ;
if ( V_292 )
F_326 () ;
F_47 ( V_292 ) ;
}
V_32 = F_327 ( V_3 , V_3 -> V_42 ) ;
F_328 ( V_3 -> V_42 -> V_295 , V_32 ) ;
break;
}
case V_296 : {
struct V_297 * V_297 ;
V_32 = - V_40 ;
V_297 = F_88 ( sizeof( struct V_297 ) , V_38 ) ;
if ( ! V_297 )
goto V_139;
V_32 = F_329 ( V_3 , V_297 ) ;
if ( V_32 )
goto V_298;
V_32 = - V_164 ;
if ( F_152 ( V_279 , V_297 , sizeof( struct V_297 ) ) )
goto V_298;
V_32 = 0 ;
V_298:
F_82 ( V_297 ) ;
break;
}
case V_299 : {
struct V_297 * V_297 ;
V_32 = - V_40 ;
V_297 = F_330 ( V_279 , sizeof( * V_297 ) ) ;
if ( F_309 ( V_297 ) ) {
V_32 = F_310 ( V_297 ) ;
goto V_139;
}
V_32 = F_331 ( V_3 , V_297 ) ;
F_82 ( V_297 ) ;
break;
}
case V_300 : {
V_282 = F_88 ( sizeof( struct V_282 ) , V_38 ) ;
V_32 = - V_40 ;
if ( ! V_282 )
goto V_139;
V_32 = F_332 ( V_3 , V_282 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_279 , V_282 , sizeof( struct V_282 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_301 : {
V_282 = F_330 ( V_279 , sizeof( * V_282 ) ) ;
if ( F_309 ( V_282 ) ) {
V_32 = F_310 ( V_282 ) ;
V_282 = NULL ;
goto V_139;
}
V_32 = F_333 ( V_3 , V_282 ) ;
break;
}
case V_302 : {
struct V_303 V_304 ;
V_32 = F_334 ( V_3 , & V_304 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_279 , & V_304 , sizeof( V_304 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_305 : {
struct V_303 V_304 ;
V_32 = - V_164 ;
if ( F_335 ( & V_304 , V_279 , sizeof( V_304 ) ) )
goto V_139;
V_32 = F_336 ( V_3 , & V_304 ) ;
break;
}
case V_306 : {
struct V_307 V_308 ;
V_32 = - V_164 ;
if ( F_335 ( & V_308 , V_279 , sizeof( V_308 ) ) )
goto V_139;
V_32 = F_337 ( V_3 , & V_308 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_279 , & V_308 , sizeof( V_308 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_309 : {
struct V_310 V_311 ;
V_32 = - V_164 ;
if ( F_335 ( & V_311 , V_279 , sizeof( V_311 ) ) )
goto V_139;
V_32 = F_338 ( V_3 , & V_311 ) ;
break;
}
case V_312 : {
struct V_313 V_147 * V_314 = V_279 ;
struct V_313 V_315 ;
T_9 V_273 , * V_82 ;
V_82 = NULL ;
if ( V_279 ) {
V_32 = - V_164 ;
if ( F_335 ( & V_315 , V_279 ,
sizeof( V_315 ) ) )
goto V_139;
V_32 = - V_132 ;
if ( V_315 . V_207 != sizeof( V_273 ) )
goto V_139;
V_32 = - V_164 ;
if ( F_335 ( & V_273 , V_314 -> V_273 ,
sizeof( V_273 ) ) )
goto V_139;
V_82 = & V_273 ;
}
V_32 = F_318 ( V_3 , V_82 ) ;
break;
}
case V_316 : {
V_281 = F_88 ( sizeof( struct V_280 ) , V_38 ) ;
V_32 = - V_40 ;
if ( ! V_281 )
goto V_139;
V_32 = F_339 ( V_3 , V_281 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_279 , V_281 , sizeof( struct V_280 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_317 : {
V_281 = F_330 ( V_279 , sizeof( * V_281 ) ) ;
if ( F_309 ( V_281 ) ) {
V_32 = F_310 ( V_281 ) ;
V_281 = NULL ;
goto V_139;
}
V_32 = F_340 ( V_3 , V_281 ) ;
break;
}
default:
V_32 = F_323 ( V_119 , V_277 , V_278 ) ;
}
V_139:
F_11 ( V_3 ) ;
F_82 ( V_281 ) ;
F_82 ( V_282 ) ;
return V_32 ;
}
static long F_341 ( struct V_118 * V_119 ,
unsigned int V_277 , unsigned long V_278 )
{
struct V_2 * V_3 = V_119 -> V_120 ;
void V_147 * V_279 = F_342 ( V_278 ) ;
int V_32 ;
if ( V_3 -> V_18 -> V_48 != V_62 -> V_48 )
return - V_283 ;
switch ( V_277 ) {
case V_312 : {
struct V_313 V_147 * V_314 = V_279 ;
struct V_313 V_315 ;
T_10 V_318 ;
T_9 V_273 ;
if ( V_279 ) {
V_32 = - V_164 ;
if ( F_335 ( & V_315 , V_279 ,
sizeof( V_315 ) ) )
goto V_139;
V_32 = - V_132 ;
if ( V_315 . V_207 != sizeof( V_318 ) )
goto V_139;
V_32 = - V_164 ;
if ( F_335 ( & V_318 , V_314 -> V_273 ,
sizeof( V_318 ) ) )
goto V_139;
F_343 ( & V_273 , & V_318 ) ;
V_32 = F_318 ( V_3 , & V_273 ) ;
} else
V_32 = F_318 ( V_3 , NULL ) ;
break;
}
default:
V_32 = F_321 ( V_119 , V_277 , V_278 ) ;
}
V_139:
return V_32 ;
}
static int F_344 ( struct V_108 * V_109 ,
int (* F_345)( struct V_108 * V_109 ,
struct V_319 * V_320 ) ,
unsigned long V_278 )
{
struct V_319 V_320 ;
if ( ! F_345 )
return - V_321 ;
if ( F_335 ( & V_320 , ( void V_147 * ) V_278 , sizeof( V_320 ) ) )
return - V_164 ;
return F_345 ( V_109 , & V_320 ) ;
}
static long F_346 ( struct V_118 * V_119 , unsigned int V_277 ,
unsigned long V_278 )
{
struct V_108 * V_109 = V_119 -> V_120 ;
switch ( V_277 ) {
case V_322 :
return F_344 ( V_109 , V_109 -> V_60 -> V_323 , V_278 ) ;
case V_324 :
return F_344 ( V_109 , V_109 -> V_60 -> V_325 , V_278 ) ;
case V_326 :
return F_344 ( V_109 , V_109 -> V_60 -> V_327 , V_278 ) ;
default:
if ( V_109 -> V_60 -> V_277 )
return V_109 -> V_60 -> V_277 ( V_109 , V_277 , V_278 ) ;
return - V_328 ;
}
}
static int F_347 ( struct V_117 * V_117 , struct V_118 * V_119 )
{
struct V_108 * V_109 = V_119 -> V_120 ;
struct V_18 * V_18 = V_109 -> V_18 ;
F_127 ( V_18 ) ;
return 0 ;
}
struct V_108 * F_348 ( struct V_118 * V_119 )
{
if ( V_119 -> V_329 != & V_330 )
return NULL ;
return V_119 -> V_120 ;
}
int F_349 ( struct V_331 * V_60 , T_4 type )
{
if ( type >= F_350 ( V_332 ) )
return - V_333 ;
if ( V_332 [ type ] != NULL )
return - V_154 ;
V_332 [ type ] = V_60 ;
return 0 ;
}
void F_351 ( T_4 type )
{
if ( V_332 [ type ] != NULL )
V_332 [ type ] = NULL ;
}
static int F_352 ( struct V_18 * V_18 ,
struct V_334 * V_335 )
{
struct V_331 * V_60 = NULL ;
struct V_108 * V_109 ;
bool V_336 = V_335 -> V_131 & V_337 ;
int V_211 ;
if ( V_335 -> type >= F_350 ( V_332 ) )
return - V_338 ;
V_60 = V_332 [ V_335 -> type ] ;
if ( V_60 == NULL )
return - V_338 ;
if ( V_336 )
return 0 ;
V_109 = F_88 ( sizeof( * V_109 ) , V_38 ) ;
if ( ! V_109 )
return - V_40 ;
V_109 -> V_60 = V_60 ;
V_109 -> V_18 = V_18 ;
F_149 ( & V_18 -> V_89 ) ;
V_211 = V_60 -> V_339 ( V_109 , V_335 -> type ) ;
if ( V_211 < 0 ) {
F_16 ( & V_18 -> V_89 ) ;
F_82 ( V_109 ) ;
return V_211 ;
}
F_104 ( & V_109 -> V_111 , & V_18 -> V_93 ) ;
F_16 ( & V_18 -> V_89 ) ;
if ( V_60 -> V_340 )
V_60 -> V_340 ( V_109 ) ;
V_211 = F_303 ( V_60 -> V_85 , & V_330 , V_109 , V_262 | V_263 ) ;
if ( V_211 < 0 ) {
F_149 ( & V_18 -> V_89 ) ;
F_114 ( & V_109 -> V_111 ) ;
F_16 ( & V_18 -> V_89 ) ;
V_60 -> V_112 ( V_109 ) ;
return V_211 ;
}
F_125 ( V_18 ) ;
V_335 -> V_76 = V_211 ;
return 0 ;
}
static long F_353 ( struct V_18 * V_18 , long V_278 )
{
switch ( V_278 ) {
case V_341 :
case V_342 :
case V_343 :
case V_344 :
#ifdef F_354
case V_345 :
#endif
#ifdef F_99
case V_346 :
case V_347 :
#endif
case V_348 :
case V_349 :
return 1 ;
#ifdef F_298
case V_350 :
return V_257 ;
#endif
#ifdef F_355
case V_351 :
return V_352 ;
#endif
#if V_97 > 1
case V_353 :
return V_97 ;
#endif
case V_354 :
return V_264 ;
default:
break;
}
return F_356 ( V_18 , V_278 ) ;
}
static long F_357 ( struct V_118 * V_119 ,
unsigned int V_277 , unsigned long V_278 )
{
struct V_18 * V_18 = V_119 -> V_120 ;
void V_147 * V_279 = ( void V_147 * ) V_278 ;
int V_32 ;
if ( V_18 -> V_48 != V_62 -> V_48 )
return - V_283 ;
switch ( V_277 ) {
case V_355 :
V_32 = F_307 ( V_18 , V_278 ) ;
break;
case V_356 : {
struct V_126 V_357 ;
V_32 = - V_164 ;
if ( F_335 ( & V_357 , V_279 ,
sizeof( V_357 ) ) )
goto V_139;
V_32 = F_150 ( V_18 , & V_357 ) ;
break;
}
case V_358 : {
struct V_159 log ;
V_32 = - V_164 ;
if ( F_335 ( & log , V_279 , sizeof( log ) ) )
goto V_139;
V_32 = F_358 ( V_18 , & log ) ;
break;
}
#ifdef F_298
case V_359 : {
struct V_360 V_361 ;
V_32 = - V_164 ;
if ( F_335 ( & V_361 , V_279 , sizeof( V_361 ) ) )
goto V_139;
V_32 = F_359 ( V_18 , & V_361 ) ;
break;
}
case V_362 : {
struct V_360 V_361 ;
V_32 = - V_164 ;
if ( F_335 ( & V_361 , V_279 , sizeof( V_361 ) ) )
goto V_139;
V_32 = F_360 ( V_18 , & V_361 ) ;
break;
}
#endif
case V_363 : {
struct V_364 V_208 ;
V_32 = - V_164 ;
if ( F_335 ( & V_208 , V_279 , sizeof( V_208 ) ) )
goto V_139;
V_32 = V_364 ( V_18 , & V_208 ) ;
break;
}
case V_365 : {
struct V_366 V_208 ;
V_32 = - V_164 ;
if ( F_335 ( & V_208 , V_279 , sizeof( V_208 ) ) )
goto V_139;
V_32 = V_366 ( V_18 , & V_208 ) ;
break;
}
#ifdef F_354
case V_367 : {
struct V_368 V_369 ;
V_32 = - V_164 ;
if ( F_335 ( & V_369 , V_279 , sizeof( V_369 ) ) )
goto V_139;
V_32 = F_361 ( V_18 , & V_369 ) ;
break;
}
#endif
#ifdef F_362
case V_370 :
case V_371 : {
struct V_372 V_373 ;
V_32 = - V_164 ;
if ( F_335 ( & V_373 , V_279 , sizeof( V_373 ) ) )
goto V_139;
V_32 = F_363 ( V_18 , & V_373 ,
V_277 == V_370 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( V_277 == V_370 ) {
if ( F_152 ( V_279 , & V_373 , sizeof( V_373 ) ) )
goto V_139;
}
V_32 = 0 ;
break;
}
#endif
#ifdef F_355
case V_374 : {
struct V_375 V_376 ;
struct V_375 V_147 * V_377 ;
struct V_378 * V_379 = NULL ;
V_32 = - V_164 ;
if ( F_335 ( & V_376 , V_279 , sizeof( V_376 ) ) )
goto V_139;
V_32 = - V_132 ;
if ( ! F_364 ( V_18 ) )
goto V_139;
if ( V_376 . V_380 > V_352 )
goto V_139;
if ( V_376 . V_131 )
goto V_139;
if ( V_376 . V_380 ) {
V_32 = - V_40 ;
V_379 = F_365 ( V_376 . V_380 * sizeof( * V_379 ) ) ;
if ( ! V_379 )
goto V_139;
V_32 = - V_164 ;
V_377 = V_279 ;
if ( F_335 ( V_379 , V_377 -> V_379 ,
V_376 . V_380 * sizeof( * V_379 ) ) )
goto V_381;
}
V_32 = F_366 ( V_18 , V_379 , V_376 . V_380 ,
V_376 . V_131 ) ;
V_381:
F_367 ( V_379 ) ;
break;
}
#endif
case V_382 : {
struct V_334 V_335 ;
V_32 = - V_164 ;
if ( F_335 ( & V_335 , V_279 , sizeof( V_335 ) ) )
goto V_139;
V_32 = F_352 ( V_18 , & V_335 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_279 , & V_335 , sizeof( V_335 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_383 :
V_32 = F_353 ( V_18 , V_278 ) ;
break;
default:
V_32 = F_368 ( V_119 , V_277 , V_278 ) ;
}
V_139:
return V_32 ;
}
static long F_369 ( struct V_118 * V_119 ,
unsigned int V_277 , unsigned long V_278 )
{
struct V_18 * V_18 = V_119 -> V_120 ;
int V_32 ;
if ( V_18 -> V_48 != V_62 -> V_48 )
return - V_283 ;
switch ( V_277 ) {
case V_358 : {
struct V_384 V_385 ;
struct V_159 log ;
if ( F_335 ( & V_385 , ( void V_147 * ) V_278 ,
sizeof( V_385 ) ) )
return - V_164 ;
log . V_135 = V_385 . V_135 ;
log . V_386 = V_385 . V_386 ;
log . V_387 = V_385 . V_387 ;
log . V_70 = F_342 ( V_385 . V_70 ) ;
V_32 = F_358 ( V_18 , & log ) ;
break;
}
default:
V_32 = F_357 ( V_119 , V_277 , V_278 ) ;
}
return V_32 ;
}
static int F_370 ( unsigned long type )
{
int V_32 ;
struct V_18 * V_18 ;
struct V_118 * V_118 ;
V_18 = F_90 ( type ) ;
if ( F_309 ( V_18 ) )
return F_310 ( V_18 ) ;
#ifdef F_298
V_32 = F_371 ( V_18 ) ;
if ( V_32 < 0 ) {
F_127 ( V_18 ) ;
return V_32 ;
}
#endif
V_32 = F_372 ( V_263 ) ;
if ( V_32 < 0 ) {
F_127 ( V_18 ) ;
return V_32 ;
}
V_118 = F_373 ( L_4 , & V_388 , V_18 , V_262 ) ;
if ( F_309 ( V_118 ) ) {
F_374 ( V_32 ) ;
F_127 ( V_18 ) ;
return F_310 ( V_118 ) ;
}
if ( F_83 ( V_18 , V_32 ) < 0 ) {
F_374 ( V_32 ) ;
F_375 ( V_118 ) ;
return - V_40 ;
}
F_116 ( V_389 , V_18 ) ;
F_376 ( V_32 , V_118 ) ;
return V_32 ;
}
static long F_377 ( struct V_118 * V_119 ,
unsigned int V_277 , unsigned long V_278 )
{
long V_32 = - V_132 ;
switch ( V_277 ) {
case V_390 :
if ( V_278 )
goto V_139;
V_32 = V_391 ;
break;
case V_392 :
V_32 = F_370 ( V_278 ) ;
break;
case V_383 :
V_32 = F_353 ( NULL , V_278 ) ;
break;
case V_393 :
if ( V_278 )
goto V_139;
V_32 = V_142 ;
#ifdef F_297
V_32 += V_142 ;
#endif
#ifdef F_298
V_32 += V_142 ;
#endif
break;
case V_394 :
case V_395 :
case V_396 :
V_32 = - V_397 ;
break;
default:
return F_378 ( V_119 , V_277 , V_278 ) ;
}
V_139:
return V_32 ;
}
static void F_379 ( void * V_398 )
{
int V_4 = F_380 () ;
int V_32 ;
if ( F_381 ( V_4 , V_399 ) )
return;
F_382 ( V_4 , V_399 ) ;
V_32 = F_383 () ;
if ( V_32 ) {
F_384 ( V_4 , V_399 ) ;
F_315 ( & V_400 ) ;
F_385 ( L_5 , V_4 ) ;
}
}
static int F_386 ( unsigned int V_4 )
{
F_387 ( & V_401 ) ;
if ( V_402 )
F_379 ( NULL ) ;
F_388 ( & V_401 ) ;
return 0 ;
}
static void F_389 ( void * V_398 )
{
int V_4 = F_380 () ;
if ( ! F_381 ( V_4 , V_399 ) )
return;
F_384 ( V_4 , V_399 ) ;
F_390 () ;
}
static int F_391 ( unsigned int V_4 )
{
F_387 ( & V_401 ) ;
if ( V_402 )
F_389 ( NULL ) ;
F_388 ( & V_401 ) ;
return 0 ;
}
static void F_392 ( void )
{
F_62 ( ! V_402 ) ;
V_402 -- ;
if ( ! V_402 )
F_393 ( F_389 , NULL , 1 ) ;
}
static void F_107 ( void )
{
F_387 ( & V_401 ) ;
F_392 () ;
F_388 ( & V_401 ) ;
}
static int F_98 ( void )
{
int V_32 = 0 ;
F_387 ( & V_401 ) ;
V_402 ++ ;
if ( V_402 == 1 ) {
F_394 ( & V_400 , 0 ) ;
F_393 ( F_379 , NULL , 1 ) ;
if ( F_314 ( & V_400 ) ) {
F_392 () ;
V_32 = - V_403 ;
}
}
F_388 ( & V_401 ) ;
return V_32 ;
}
static int F_395 ( struct V_404 * V_405 , unsigned long V_220 ,
void * V_406 )
{
F_385 ( L_6 ) ;
V_407 = true ;
F_393 ( F_389 , NULL , 1 ) ;
return V_408 ;
}
static void F_119 ( struct V_104 * V_114 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_114 -> V_409 ; V_19 ++ ) {
struct V_410 * V_411 = V_114 -> V_412 [ V_19 ] . V_109 ;
F_396 ( V_411 ) ;
}
F_82 ( V_114 ) ;
}
static inline int F_397 ( const struct V_413 * V_414 ,
const struct V_413 * V_415 )
{
T_6 V_416 = V_414 -> V_172 ;
T_6 V_417 = V_415 -> V_172 ;
if ( V_416 < V_417 )
return - 1 ;
if ( V_415 -> V_207 ) {
V_416 += V_414 -> V_207 ;
V_417 += V_415 -> V_207 ;
}
if ( V_416 > V_417 )
return 1 ;
return 0 ;
}
static int F_398 ( const void * V_418 , const void * V_419 )
{
return F_397 ( V_418 , V_419 ) ;
}
static int F_399 ( struct V_104 * V_114 , struct V_410 * V_109 ,
T_6 V_172 , int V_207 )
{
V_114 -> V_412 [ V_114 -> V_409 ++ ] = (struct V_413 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
. V_109 = V_109 ,
} ;
F_400 ( V_114 -> V_412 , V_114 -> V_409 , sizeof( struct V_413 ) ,
F_398 , NULL ) ;
return 0 ;
}
static int F_401 ( struct V_104 * V_114 ,
T_6 V_172 , int V_207 )
{
struct V_413 * V_412 , V_420 ;
int V_421 ;
V_420 = (struct V_413 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_412 = bsearch ( & V_420 , V_114 -> V_412 , V_114 -> V_409 ,
sizeof( struct V_413 ) , F_398 ) ;
if ( V_412 == NULL )
return - V_163 ;
V_421 = V_412 - V_114 -> V_412 ;
while ( V_421 > 0 && F_397 ( & V_420 , & V_114 -> V_412 [ V_421 - 1 ] ) == 0 )
V_421 -- ;
return V_421 ;
}
static int F_402 ( struct V_2 * V_3 , struct V_104 * V_114 ,
struct V_413 * V_412 , const void * V_220 )
{
int V_51 ;
V_51 = F_401 ( V_114 , V_412 -> V_172 , V_412 -> V_207 ) ;
if ( V_51 < 0 )
return - V_397 ;
while ( V_51 < V_114 -> V_409 &&
F_397 ( V_412 , & V_114 -> V_412 [ V_51 ] ) == 0 ) {
if ( ! F_403 ( V_3 , V_114 -> V_412 [ V_51 ] . V_109 , V_412 -> V_172 ,
V_412 -> V_207 , V_220 ) )
return V_51 ;
V_51 ++ ;
}
return - V_397 ;
}
int F_404 ( struct V_2 * V_3 , enum V_422 V_423 , T_6 V_172 ,
int V_207 , const void * V_220 )
{
struct V_104 * V_114 ;
struct V_413 V_412 ;
int V_32 ;
V_412 = (struct V_413 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_114 = F_405 ( V_3 -> V_18 -> V_103 [ V_423 ] , & V_3 -> V_18 -> V_52 ) ;
if ( ! V_114 )
return - V_40 ;
V_32 = F_402 ( V_3 , V_114 , & V_412 , V_220 ) ;
return V_32 < 0 ? V_32 : 0 ;
}
int F_406 ( struct V_2 * V_3 , enum V_422 V_423 ,
T_6 V_172 , int V_207 , const void * V_220 , long V_424 )
{
struct V_104 * V_114 ;
struct V_413 V_412 ;
V_412 = (struct V_413 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_114 = F_405 ( V_3 -> V_18 -> V_103 [ V_423 ] , & V_3 -> V_18 -> V_52 ) ;
if ( ! V_114 )
return - V_40 ;
if ( ( V_424 >= 0 ) && ( V_424 < V_114 -> V_409 ) &&
( F_397 ( & V_412 , & V_114 -> V_412 [ V_424 ] ) == 0 ) )
if ( ! F_403 ( V_3 , V_114 -> V_412 [ V_424 ] . V_109 , V_172 , V_207 ,
V_220 ) )
return V_424 ;
return F_402 ( V_3 , V_114 , & V_412 , V_220 ) ;
}
static int F_407 ( struct V_2 * V_3 , struct V_104 * V_114 ,
struct V_413 * V_412 , void * V_220 )
{
int V_51 ;
V_51 = F_401 ( V_114 , V_412 -> V_172 , V_412 -> V_207 ) ;
if ( V_51 < 0 )
return - V_397 ;
while ( V_51 < V_114 -> V_409 &&
F_397 ( V_412 , & V_114 -> V_412 [ V_51 ] ) == 0 ) {
if ( ! F_408 ( V_3 , V_114 -> V_412 [ V_51 ] . V_109 , V_412 -> V_172 ,
V_412 -> V_207 , V_220 ) )
return V_51 ;
V_51 ++ ;
}
return - V_397 ;
}
int F_409 ( struct V_2 * V_3 , enum V_422 V_423 , T_6 V_172 ,
int V_207 , void * V_220 )
{
struct V_104 * V_114 ;
struct V_413 V_412 ;
int V_32 ;
V_412 = (struct V_413 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_114 = F_405 ( V_3 -> V_18 -> V_103 [ V_423 ] , & V_3 -> V_18 -> V_52 ) ;
if ( ! V_114 )
return - V_40 ;
V_32 = F_407 ( V_3 , V_114 , & V_412 , V_220 ) ;
return V_32 < 0 ? V_32 : 0 ;
}
int F_410 ( struct V_18 * V_18 , enum V_422 V_423 , T_6 V_172 ,
int V_207 , struct V_410 * V_109 )
{
struct V_104 * V_425 , * V_114 ;
V_114 = F_108 ( V_18 , V_423 ) ;
if ( ! V_114 )
return - V_40 ;
if ( V_114 -> V_409 - V_114 -> V_426 > V_427 - 1 )
return - V_333 ;
V_425 = F_411 ( sizeof( * V_114 ) + ( ( V_114 -> V_409 + 1 ) *
sizeof( struct V_413 ) ) , V_38 ) ;
if ( ! V_425 )
return - V_40 ;
memcpy ( V_425 , V_114 , sizeof( * V_114 ) + ( V_114 -> V_409 *
sizeof( struct V_413 ) ) ) ;
F_399 ( V_425 , V_109 , V_172 , V_207 ) ;
F_102 ( V_18 -> V_103 [ V_423 ] , V_425 ) ;
F_139 ( & V_18 -> V_52 ) ;
F_82 ( V_114 ) ;
return 0 ;
}
void F_412 ( struct V_18 * V_18 , enum V_422 V_423 ,
struct V_410 * V_109 )
{
int V_19 ;
struct V_104 * V_425 , * V_114 ;
V_114 = F_108 ( V_18 , V_423 ) ;
if ( ! V_114 )
return;
for ( V_19 = 0 ; V_19 < V_114 -> V_409 ; V_19 ++ )
if ( V_114 -> V_412 [ V_19 ] . V_109 == V_109 ) {
break;
}
if ( V_19 == V_114 -> V_409 )
return;
V_425 = F_411 ( sizeof( * V_114 ) + ( ( V_114 -> V_409 - 1 ) *
sizeof( struct V_413 ) ) , V_38 ) ;
if ( ! V_425 ) {
F_413 ( L_7 ) ;
goto V_428;
}
memcpy ( V_425 , V_114 , sizeof( * V_114 ) + V_19 * sizeof( struct V_413 ) ) ;
V_425 -> V_409 -- ;
memcpy ( V_425 -> V_412 + V_19 , V_114 -> V_412 + V_19 + 1 ,
( V_425 -> V_409 - V_19 ) * sizeof( struct V_413 ) ) ;
V_428:
F_102 ( V_18 -> V_103 [ V_423 ] , V_425 ) ;
F_139 ( & V_18 -> V_52 ) ;
F_82 ( V_114 ) ;
return;
}
struct V_410 * F_414 ( struct V_18 * V_18 , enum V_422 V_423 ,
T_6 V_172 )
{
struct V_104 * V_114 ;
int V_429 , V_430 ;
struct V_410 * V_431 = NULL ;
V_430 = F_53 ( & V_18 -> V_52 ) ;
V_114 = F_405 ( V_18 -> V_103 [ V_423 ] , & V_18 -> V_52 ) ;
if ( ! V_114 )
goto V_432;
V_429 = F_401 ( V_114 , V_172 , 1 ) ;
if ( V_429 < 0 )
goto V_432;
V_431 = V_114 -> V_412 [ V_429 ] . V_109 ;
V_432:
F_57 ( & V_18 -> V_52 , V_430 ) ;
return V_431 ;
}
static int F_415 ( struct V_117 * V_117 , struct V_118 * V_118 ,
int (* F_416)( void * , T_8 * ) , int (* F_417)( void * , T_8 ) ,
const char * V_433 )
{
struct V_79 * V_80 = (struct V_79 * )
V_117 -> V_434 ;
if ( ! F_418 ( & V_80 -> V_18 -> V_92 ) )
return - V_163 ;
if ( F_419 ( V_117 , V_118 , F_416 , F_417 , V_433 ) ) {
F_127 ( V_80 -> V_18 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_420 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
struct V_79 * V_80 = (struct V_79 * )
V_117 -> V_434 ;
F_421 ( V_117 , V_118 ) ;
F_127 ( V_80 -> V_18 ) ;
return 0 ;
}
static int F_422 ( void * V_208 , T_8 * V_220 )
{
struct V_79 * V_80 = (struct V_79 * ) V_208 ;
* V_220 = * ( V_435 * ) ( ( void * ) V_80 -> V_18 + V_80 -> V_86 ) ;
return 0 ;
}
static int F_423 ( void * V_208 , T_8 V_220 )
{
struct V_79 * V_80 = (struct V_79 * ) V_208 ;
if ( V_220 )
return - V_132 ;
* ( V_435 * ) ( ( void * ) V_80 -> V_18 + V_80 -> V_86 ) = 0 ;
return 0 ;
}
static int F_424 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
F_425 ( L_8 , 0ull ) ;
return F_415 ( V_117 , V_118 , F_422 ,
F_423 , L_8 ) ;
}
static int F_426 ( void * V_208 , T_8 * V_220 )
{
int V_19 ;
struct V_79 * V_80 = (struct V_79 * ) V_208 ;
struct V_2 * V_3 ;
* V_220 = 0 ;
F_26 ( V_19 , V_3 , V_80 -> V_18 )
* V_220 += * ( T_8 * ) ( ( void * ) V_3 + V_80 -> V_86 ) ;
return 0 ;
}
static int F_427 ( void * V_208 , T_8 V_220 )
{
int V_19 ;
struct V_79 * V_80 = (struct V_79 * ) V_208 ;
struct V_2 * V_3 ;
if ( V_220 )
return - V_132 ;
F_26 ( V_19 , V_3 , V_80 -> V_18 )
* ( T_8 * ) ( ( void * ) V_3 + V_80 -> V_86 ) = 0 ;
return 0 ;
}
static int F_428 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
F_425 ( L_8 , 0ull ) ;
return F_415 ( V_117 , V_118 , F_426 ,
F_427 , L_8 ) ;
}
static int F_429 ( void * V_436 , T_8 * V_220 )
{
unsigned V_86 = ( long ) V_436 ;
struct V_18 * V_18 ;
struct V_79 V_437 = { . V_86 = V_86 } ;
T_8 V_438 ;
* V_220 = 0 ;
F_54 ( & V_106 ) ;
F_430 (kvm, &vm_list, vm_list) {
V_437 . V_18 = V_18 ;
F_422 ( ( void * ) & V_437 , & V_438 ) ;
* V_220 += V_438 ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static int F_431 ( void * V_436 , T_8 V_220 )
{
unsigned V_86 = ( long ) V_436 ;
struct V_18 * V_18 ;
struct V_79 V_437 = { . V_86 = V_86 } ;
if ( V_220 )
return - V_132 ;
F_54 ( & V_106 ) ;
F_430 (kvm, &vm_list, vm_list) {
V_437 . V_18 = V_18 ;
F_423 ( ( void * ) & V_437 , 0 ) ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static int F_432 ( void * V_436 , T_8 * V_220 )
{
unsigned V_86 = ( long ) V_436 ;
struct V_18 * V_18 ;
struct V_79 V_437 = { . V_86 = V_86 } ;
T_8 V_438 ;
* V_220 = 0 ;
F_54 ( & V_106 ) ;
F_430 (kvm, &vm_list, vm_list) {
V_437 . V_18 = V_18 ;
F_426 ( ( void * ) & V_437 , & V_438 ) ;
* V_220 += V_438 ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static int F_433 ( void * V_436 , T_8 V_220 )
{
unsigned V_86 = ( long ) V_436 ;
struct V_18 * V_18 ;
struct V_79 V_437 = { . V_86 = V_86 } ;
if ( V_220 )
return - V_132 ;
F_54 ( & V_106 ) ;
F_430 (kvm, &vm_list, vm_list) {
V_437 . V_18 = V_18 ;
F_427 ( ( void * ) & V_437 , 0 ) ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static void F_116 ( unsigned int type , struct V_18 * V_18 )
{
struct V_439 * V_440 ;
unsigned long long V_441 , V_442 ;
if ( ! V_443 . V_444 || ! V_18 )
return;
F_54 ( & V_106 ) ;
if ( type == V_389 ) {
V_445 ++ ;
V_446 ++ ;
} else if ( type == V_113 ) {
V_446 -- ;
}
V_441 = V_445 ;
V_442 = V_446 ;
F_56 ( & V_106 ) ;
V_440 = F_88 ( sizeof( * V_440 ) , V_38 ) ;
if ( ! V_440 )
return;
F_434 ( V_440 , L_9 , V_441 ) ;
F_434 ( V_440 , L_10 , V_442 ) ;
if ( type == V_389 ) {
F_434 ( V_440 , L_11 ) ;
V_18 -> V_447 = F_85 ( V_62 ) ;
} else if ( type == V_113 ) {
F_434 ( V_440 , L_12 ) ;
}
F_434 ( V_440 , L_13 , V_18 -> V_447 ) ;
if ( V_18 -> V_73 ) {
char * V_110 , * V_82 = F_411 ( V_448 , V_38 ) ;
if ( V_82 ) {
V_110 = F_435 ( V_18 -> V_73 , V_82 , V_448 ) ;
if ( ! F_309 ( V_110 ) )
F_434 ( V_440 , L_14 , V_110 ) ;
F_82 ( V_82 ) ;
}
}
V_440 -> V_449 [ V_440 -> V_450 ++ ] = NULL ;
F_436 ( & V_443 . V_444 -> V_451 , V_452 , V_440 -> V_449 ) ;
F_82 ( V_440 ) ;
}
static int F_437 ( void )
{
int V_32 = - V_154 ;
struct V_81 * V_82 ;
V_83 = F_86 ( L_15 , NULL ) ;
if ( V_83 == NULL )
goto V_139;
V_75 = 0 ;
for ( V_82 = V_84 ; V_82 -> V_85 ; ++ V_82 , V_75 ++ ) {
if ( ! F_89 ( V_82 -> V_85 , 0644 , V_83 ,
( void * ) ( long ) V_82 -> V_86 ,
V_453 [ V_82 -> V_88 ] ) )
goto V_454;
}
return 0 ;
V_454:
F_81 ( V_83 ) ;
V_139:
return V_32 ;
}
static int F_438 ( void )
{
if ( V_402 )
F_389 ( NULL ) ;
return 0 ;
}
static void F_439 ( void )
{
if ( V_402 ) {
F_134 ( F_440 ( & V_401 ) ) ;
F_379 ( NULL ) ;
}
}
static inline
struct V_2 * F_441 ( struct V_7 * V_455 )
{
return F_51 ( V_455 , struct V_2 , V_7 ) ;
}
static void F_442 ( struct V_7 * V_455 , int V_4 )
{
struct V_2 * V_3 = F_441 ( V_455 ) ;
if ( V_3 -> V_43 )
V_3 -> V_43 = false ;
F_443 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_444 ( struct V_7 * V_455 ,
struct V_240 * V_456 )
{
struct V_2 * V_3 = F_441 ( V_455 ) ;
if ( V_62 -> V_457 == V_458 )
V_3 -> V_43 = true ;
F_13 ( V_3 ) ;
}
int F_445 ( void * V_459 , unsigned V_460 , unsigned V_461 ,
struct V_462 * V_462 )
{
int V_32 ;
int V_4 ;
V_32 = F_446 ( V_459 ) ;
if ( V_32 )
goto V_463;
V_32 = F_447 () ;
if ( V_32 )
goto V_464;
if ( ! F_25 ( & V_399 , V_38 ) ) {
V_32 = - V_40 ;
goto V_465;
}
V_32 = F_448 () ;
if ( V_32 < 0 )
goto V_466;
F_449 (cpu) {
F_450 ( V_4 ,
V_467 ,
& V_32 , 1 ) ;
if ( V_32 < 0 )
goto V_468;
}
V_32 = F_451 ( V_469 , L_16 ,
F_386 , F_391 ) ;
if ( V_32 )
goto V_470;
F_452 ( & V_471 ) ;
if ( ! V_461 )
V_461 = F_453 ( struct V_2 ) ;
V_472 = F_454 ( L_17 , V_460 , V_461 ,
0 , NULL ) ;
if ( ! V_472 ) {
V_32 = - V_40 ;
goto V_473;
}
V_32 = F_455 () ;
if ( V_32 )
goto V_155;
V_474 . V_475 = V_462 ;
V_388 . V_475 = V_462 ;
V_261 . V_475 = V_462 ;
V_32 = F_456 ( & V_443 ) ;
if ( V_32 ) {
F_413 ( L_18 ) ;
goto V_476;
}
F_457 ( & V_477 ) ;
V_268 . V_478 = F_442 ;
V_268 . V_479 = F_444 ;
V_32 = F_437 () ;
if ( V_32 ) {
F_413 ( L_19 ) ;
goto V_480;
}
V_32 = F_458 () ;
F_134 ( V_32 ) ;
return 0 ;
V_480:
F_459 ( & V_477 ) ;
F_460 ( & V_443 ) ;
V_476:
F_461 () ;
V_155:
F_462 ( V_472 ) ;
V_473:
F_463 ( & V_471 ) ;
F_464 ( V_469 ) ;
V_470:
V_468:
F_465 () ;
V_466:
F_30 ( V_399 ) ;
V_465:
F_466 () ;
V_464:
F_467 () ;
V_463:
return V_32 ;
}
void F_468 ( void )
{
F_81 ( V_83 ) ;
F_460 ( & V_443 ) ;
F_462 ( V_472 ) ;
F_461 () ;
F_459 ( & V_477 ) ;
F_463 ( & V_471 ) ;
F_464 ( V_469 ) ;
F_393 ( F_389 , NULL , 1 ) ;
F_465 () ;
F_467 () ;
F_466 () ;
F_30 ( V_399 ) ;
F_469 () ;
}
