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
F_96 ( & V_18 -> V_92 , 0 ) ;
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
T_5 V_205 = 0 ;
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
V_217 = 0 ;
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
void F_293 ( struct V_2 * V_20 , bool V_247 )
{
struct V_18 * V_18 = V_20 -> V_18 ;
struct V_2 * V_3 ;
int V_248 = V_20 -> V_18 -> V_248 ;
int V_249 = 0 ;
int V_250 = 3 ;
int V_251 ;
int V_19 ;
F_42 ( V_20 , true ) ;
for ( V_251 = 0 ; V_251 < 2 && ! V_249 && V_250 ; V_251 ++ ) {
F_26 (i, vcpu, kvm) {
if ( ! V_251 && V_19 <= V_248 ) {
V_19 = V_248 ;
continue;
} else if ( V_251 && V_19 > V_248 )
break;
if ( ! F_294 ( V_3 -> V_43 ) )
continue;
if ( V_3 == V_20 )
continue;
if ( F_295 ( & V_3 -> V_35 ) && ! F_259 ( V_3 ) )
continue;
if ( V_247 && ! F_296 ( V_3 ) )
continue;
if ( ! F_291 ( V_3 ) )
continue;
V_249 = F_284 ( V_3 ) ;
if ( V_249 > 0 ) {
V_18 -> V_248 = V_19 ;
break;
} else if ( V_249 < 0 ) {
V_250 -- ;
if ( ! V_250 )
break;
}
}
}
F_42 ( V_20 , false ) ;
F_43 ( V_20 , false ) ;
}
static int F_297 ( struct V_252 * V_253 )
{
struct V_2 * V_3 = V_253 -> V_171 -> V_254 -> V_120 ;
struct V_31 * V_31 ;
if ( V_253 -> V_255 == 0 )
V_31 = F_298 ( V_3 -> V_42 ) ;
#ifdef F_299
else if ( V_253 -> V_255 == V_256 )
V_31 = F_298 ( V_3 -> V_158 . V_257 ) ;
#endif
#ifdef F_300
else if ( V_253 -> V_255 == V_258 )
V_31 = F_298 ( V_3 -> V_18 -> V_259 ) ;
#endif
else
return F_301 ( V_3 , V_253 ) ;
F_218 ( V_31 ) ;
V_253 -> V_31 = V_31 ;
return 0 ;
}
static int F_302 ( struct V_118 * V_118 , struct V_170 * V_171 )
{
V_171 -> V_260 = & V_261 ;
return 0 ;
}
static int F_303 ( struct V_117 * V_117 , struct V_118 * V_119 )
{
struct V_2 * V_3 = V_119 -> V_120 ;
F_81 ( V_3 -> V_73 ) ;
F_127 ( V_3 -> V_18 ) ;
return 0 ;
}
static int F_304 ( struct V_2 * V_3 )
{
return F_305 ( L_2 , & V_262 , V_3 , V_263 | V_264 ) ;
}
static int F_306 ( struct V_2 * V_3 )
{
char V_77 [ V_78 * 2 ] ;
int V_211 ;
if ( ! F_307 () )
return 0 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_77 , sizeof( V_77 ) , L_3 , V_3 -> V_33 ) ;
V_3 -> V_73 = F_86 ( V_77 ,
V_3 -> V_18 -> V_73 ) ;
if ( ! V_3 -> V_73 )
return - V_40 ;
V_211 = F_308 ( V_3 ) ;
if ( V_211 < 0 ) {
F_81 ( V_3 -> V_73 ) ;
return V_211 ;
}
return 0 ;
}
static int F_309 ( struct V_18 * V_18 , T_4 V_30 )
{
int V_32 ;
struct V_2 * V_3 ;
if ( V_30 >= V_265 )
return - V_132 ;
F_149 ( & V_18 -> V_89 ) ;
if ( V_18 -> V_266 == V_267 ) {
F_16 ( & V_18 -> V_89 ) ;
return - V_132 ;
}
V_18 -> V_266 ++ ;
F_16 ( & V_18 -> V_89 ) ;
V_3 = F_310 ( V_18 , V_30 ) ;
if ( F_311 ( V_3 ) ) {
V_32 = F_312 ( V_3 ) ;
goto V_268;
}
F_313 ( & V_3 -> V_7 , & V_269 ) ;
V_32 = F_314 ( V_3 ) ;
if ( V_32 )
goto V_270;
V_32 = F_306 ( V_3 ) ;
if ( V_32 )
goto V_270;
F_149 ( & V_18 -> V_89 ) ;
if ( F_315 ( V_18 , V_30 ) ) {
V_32 = - V_154 ;
goto V_271;
}
F_62 ( V_18 -> V_272 [ F_316 ( & V_18 -> V_273 ) ] ) ;
F_125 ( V_18 ) ;
V_32 = F_304 ( V_3 ) ;
if ( V_32 < 0 ) {
F_127 ( V_18 ) ;
goto V_271;
}
V_18 -> V_272 [ F_316 ( & V_18 -> V_273 ) ] = V_3 ;
F_61 () ;
F_317 ( & V_18 -> V_273 ) ;
F_16 ( & V_18 -> V_89 ) ;
F_318 ( V_3 ) ;
return V_32 ;
V_271:
F_16 ( & V_18 -> V_89 ) ;
F_81 ( V_3 -> V_73 ) ;
V_270:
F_319 ( V_3 ) ;
V_268:
F_149 ( & V_18 -> V_89 ) ;
V_18 -> V_266 -- ;
F_16 ( & V_18 -> V_89 ) ;
return V_32 ;
}
static int F_320 ( struct V_2 * V_3 , T_9 * V_274 )
{
if ( V_274 ) {
F_321 ( V_274 , F_322 ( V_275 ) | F_322 ( V_276 ) ) ;
V_3 -> V_277 = 1 ;
V_3 -> V_274 = * V_274 ;
} else
V_3 -> V_277 = 0 ;
return 0 ;
}
static long F_323 ( struct V_118 * V_119 ,
unsigned int V_278 , unsigned long V_279 )
{
struct V_2 * V_3 = V_119 -> V_120 ;
void V_147 * V_280 = ( void V_147 * ) V_279 ;
int V_32 ;
struct V_281 * V_282 = NULL ;
struct V_283 * V_283 = NULL ;
if ( V_3 -> V_18 -> V_48 != V_62 -> V_48 )
return - V_284 ;
if ( F_21 ( F_324 ( V_278 ) != V_285 ) )
return - V_132 ;
#if F_121 ( V_286 ) || F_121 ( V_287 ) || F_121 ( V_288 )
if ( V_278 == V_289 || V_278 == V_290 || V_278 == V_291 )
return F_325 ( V_119 , V_278 , V_279 ) ;
#endif
V_32 = F_5 ( V_3 ) ;
if ( V_32 )
return V_32 ;
switch ( V_278 ) {
case V_292 : {
struct V_34 * V_293 ;
V_32 = - V_132 ;
if ( V_279 )
goto V_139;
V_293 = F_326 ( V_3 -> V_34 ) ;
if ( F_21 ( V_293 != V_62 -> V_294 [ V_242 ] . V_34 ) ) {
struct V_34 * V_295 = F_327 ( V_62 , V_242 ) ;
F_102 ( V_3 -> V_34 , V_295 ) ;
if ( V_293 )
F_328 () ;
F_47 ( V_293 ) ;
}
V_32 = F_329 ( V_3 , V_3 -> V_42 ) ;
F_330 ( V_3 -> V_42 -> V_296 , V_32 ) ;
break;
}
case V_297 : {
struct V_298 * V_298 ;
V_32 = - V_40 ;
V_298 = F_88 ( sizeof( struct V_298 ) , V_38 ) ;
if ( ! V_298 )
goto V_139;
V_32 = F_331 ( V_3 , V_298 ) ;
if ( V_32 )
goto V_299;
V_32 = - V_164 ;
if ( F_152 ( V_280 , V_298 , sizeof( struct V_298 ) ) )
goto V_299;
V_32 = 0 ;
V_299:
F_82 ( V_298 ) ;
break;
}
case V_300 : {
struct V_298 * V_298 ;
V_32 = - V_40 ;
V_298 = F_332 ( V_280 , sizeof( * V_298 ) ) ;
if ( F_311 ( V_298 ) ) {
V_32 = F_312 ( V_298 ) ;
goto V_139;
}
V_32 = F_333 ( V_3 , V_298 ) ;
F_82 ( V_298 ) ;
break;
}
case V_301 : {
V_283 = F_88 ( sizeof( struct V_283 ) , V_38 ) ;
V_32 = - V_40 ;
if ( ! V_283 )
goto V_139;
V_32 = F_334 ( V_3 , V_283 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_280 , V_283 , sizeof( struct V_283 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_302 : {
V_283 = F_332 ( V_280 , sizeof( * V_283 ) ) ;
if ( F_311 ( V_283 ) ) {
V_32 = F_312 ( V_283 ) ;
V_283 = NULL ;
goto V_139;
}
V_32 = F_335 ( V_3 , V_283 ) ;
break;
}
case V_303 : {
struct V_304 V_305 ;
V_32 = F_336 ( V_3 , & V_305 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_280 , & V_305 , sizeof( V_305 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_306 : {
struct V_304 V_305 ;
V_32 = - V_164 ;
if ( F_337 ( & V_305 , V_280 , sizeof( V_305 ) ) )
goto V_139;
V_32 = F_338 ( V_3 , & V_305 ) ;
break;
}
case V_307 : {
struct V_308 V_309 ;
V_32 = - V_164 ;
if ( F_337 ( & V_309 , V_280 , sizeof( V_309 ) ) )
goto V_139;
V_32 = F_339 ( V_3 , & V_309 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_280 , & V_309 , sizeof( V_309 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_310 : {
struct V_311 V_312 ;
V_32 = - V_164 ;
if ( F_337 ( & V_312 , V_280 , sizeof( V_312 ) ) )
goto V_139;
V_32 = F_340 ( V_3 , & V_312 ) ;
break;
}
case V_313 : {
struct V_314 V_147 * V_315 = V_280 ;
struct V_314 V_316 ;
T_9 V_274 , * V_82 ;
V_82 = NULL ;
if ( V_280 ) {
V_32 = - V_164 ;
if ( F_337 ( & V_316 , V_280 ,
sizeof( V_316 ) ) )
goto V_139;
V_32 = - V_132 ;
if ( V_316 . V_207 != sizeof( V_274 ) )
goto V_139;
V_32 = - V_164 ;
if ( F_337 ( & V_274 , V_315 -> V_274 ,
sizeof( V_274 ) ) )
goto V_139;
V_82 = & V_274 ;
}
V_32 = F_320 ( V_3 , V_82 ) ;
break;
}
case V_317 : {
V_282 = F_88 ( sizeof( struct V_281 ) , V_38 ) ;
V_32 = - V_40 ;
if ( ! V_282 )
goto V_139;
V_32 = F_341 ( V_3 , V_282 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_280 , V_282 , sizeof( struct V_281 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_318 : {
V_282 = F_332 ( V_280 , sizeof( * V_282 ) ) ;
if ( F_311 ( V_282 ) ) {
V_32 = F_312 ( V_282 ) ;
V_282 = NULL ;
goto V_139;
}
V_32 = F_342 ( V_3 , V_282 ) ;
break;
}
default:
V_32 = F_325 ( V_119 , V_278 , V_279 ) ;
}
V_139:
F_11 ( V_3 ) ;
F_82 ( V_282 ) ;
F_82 ( V_283 ) ;
return V_32 ;
}
static long F_343 ( struct V_118 * V_119 ,
unsigned int V_278 , unsigned long V_279 )
{
struct V_2 * V_3 = V_119 -> V_120 ;
void V_147 * V_280 = F_344 ( V_279 ) ;
int V_32 ;
if ( V_3 -> V_18 -> V_48 != V_62 -> V_48 )
return - V_284 ;
switch ( V_278 ) {
case V_313 : {
struct V_314 V_147 * V_315 = V_280 ;
struct V_314 V_316 ;
T_10 V_319 ;
T_9 V_274 ;
if ( V_280 ) {
V_32 = - V_164 ;
if ( F_337 ( & V_316 , V_280 ,
sizeof( V_316 ) ) )
goto V_139;
V_32 = - V_132 ;
if ( V_316 . V_207 != sizeof( V_319 ) )
goto V_139;
V_32 = - V_164 ;
if ( F_337 ( & V_319 , V_315 -> V_274 ,
sizeof( V_319 ) ) )
goto V_139;
F_345 ( & V_274 , & V_319 ) ;
V_32 = F_320 ( V_3 , & V_274 ) ;
} else
V_32 = F_320 ( V_3 , NULL ) ;
break;
}
default:
V_32 = F_323 ( V_119 , V_278 , V_279 ) ;
}
V_139:
return V_32 ;
}
static int F_346 ( struct V_108 * V_109 ,
int (* F_347)( struct V_108 * V_109 ,
struct V_320 * V_321 ) ,
unsigned long V_279 )
{
struct V_320 V_321 ;
if ( ! F_347 )
return - V_322 ;
if ( F_337 ( & V_321 , ( void V_147 * ) V_279 , sizeof( V_321 ) ) )
return - V_164 ;
return F_347 ( V_109 , & V_321 ) ;
}
static long F_348 ( struct V_118 * V_119 , unsigned int V_278 ,
unsigned long V_279 )
{
struct V_108 * V_109 = V_119 -> V_120 ;
switch ( V_278 ) {
case V_323 :
return F_346 ( V_109 , V_109 -> V_60 -> V_324 , V_279 ) ;
case V_325 :
return F_346 ( V_109 , V_109 -> V_60 -> V_326 , V_279 ) ;
case V_327 :
return F_346 ( V_109 , V_109 -> V_60 -> V_328 , V_279 ) ;
default:
if ( V_109 -> V_60 -> V_278 )
return V_109 -> V_60 -> V_278 ( V_109 , V_278 , V_279 ) ;
return - V_329 ;
}
}
static int F_349 ( struct V_117 * V_117 , struct V_118 * V_119 )
{
struct V_108 * V_109 = V_119 -> V_120 ;
struct V_18 * V_18 = V_109 -> V_18 ;
F_127 ( V_18 ) ;
return 0 ;
}
struct V_108 * F_350 ( struct V_118 * V_119 )
{
if ( V_119 -> V_330 != & V_331 )
return NULL ;
return V_119 -> V_120 ;
}
int F_351 ( struct V_332 * V_60 , T_4 type )
{
if ( type >= F_352 ( V_333 ) )
return - V_334 ;
if ( V_333 [ type ] != NULL )
return - V_154 ;
V_333 [ type ] = V_60 ;
return 0 ;
}
void F_353 ( T_4 type )
{
if ( V_333 [ type ] != NULL )
V_333 [ type ] = NULL ;
}
static int F_354 ( struct V_18 * V_18 ,
struct V_335 * V_336 )
{
struct V_332 * V_60 = NULL ;
struct V_108 * V_109 ;
bool V_337 = V_336 -> V_131 & V_338 ;
int V_211 ;
if ( V_336 -> type >= F_352 ( V_333 ) )
return - V_339 ;
V_60 = V_333 [ V_336 -> type ] ;
if ( V_60 == NULL )
return - V_339 ;
if ( V_337 )
return 0 ;
V_109 = F_88 ( sizeof( * V_109 ) , V_38 ) ;
if ( ! V_109 )
return - V_40 ;
V_109 -> V_60 = V_60 ;
V_109 -> V_18 = V_18 ;
F_149 ( & V_18 -> V_89 ) ;
V_211 = V_60 -> V_340 ( V_109 , V_336 -> type ) ;
if ( V_211 < 0 ) {
F_16 ( & V_18 -> V_89 ) ;
F_82 ( V_109 ) ;
return V_211 ;
}
F_104 ( & V_109 -> V_111 , & V_18 -> V_93 ) ;
F_16 ( & V_18 -> V_89 ) ;
if ( V_60 -> V_341 )
V_60 -> V_341 ( V_109 ) ;
V_211 = F_305 ( V_60 -> V_85 , & V_331 , V_109 , V_263 | V_264 ) ;
if ( V_211 < 0 ) {
F_149 ( & V_18 -> V_89 ) ;
F_114 ( & V_109 -> V_111 ) ;
F_16 ( & V_18 -> V_89 ) ;
V_60 -> V_112 ( V_109 ) ;
return V_211 ;
}
F_125 ( V_18 ) ;
V_336 -> V_76 = V_211 ;
return 0 ;
}
static long F_355 ( struct V_18 * V_18 , long V_279 )
{
switch ( V_279 ) {
case V_342 :
case V_343 :
case V_344 :
case V_345 :
#ifdef F_356
case V_346 :
#endif
#ifdef F_99
case V_347 :
case V_348 :
#endif
case V_349 :
case V_350 :
return 1 ;
#ifdef F_300
case V_351 :
return V_258 ;
#endif
#ifdef F_357
case V_352 :
return V_353 ;
#endif
#if V_97 > 1
case V_354 :
return V_97 ;
#endif
case V_355 :
return V_265 ;
default:
break;
}
return F_358 ( V_18 , V_279 ) ;
}
static long F_359 ( struct V_118 * V_119 ,
unsigned int V_278 , unsigned long V_279 )
{
struct V_18 * V_18 = V_119 -> V_120 ;
void V_147 * V_280 = ( void V_147 * ) V_279 ;
int V_32 ;
if ( V_18 -> V_48 != V_62 -> V_48 )
return - V_284 ;
switch ( V_278 ) {
case V_356 :
V_32 = F_309 ( V_18 , V_279 ) ;
break;
case V_357 : {
struct V_126 V_358 ;
V_32 = - V_164 ;
if ( F_337 ( & V_358 , V_280 ,
sizeof( V_358 ) ) )
goto V_139;
V_32 = F_150 ( V_18 , & V_358 ) ;
break;
}
case V_359 : {
struct V_159 log ;
V_32 = - V_164 ;
if ( F_337 ( & log , V_280 , sizeof( log ) ) )
goto V_139;
V_32 = F_360 ( V_18 , & log ) ;
break;
}
#ifdef F_300
case V_360 : {
struct V_361 V_362 ;
V_32 = - V_164 ;
if ( F_337 ( & V_362 , V_280 , sizeof( V_362 ) ) )
goto V_139;
V_32 = F_361 ( V_18 , & V_362 ) ;
break;
}
case V_363 : {
struct V_361 V_362 ;
V_32 = - V_164 ;
if ( F_337 ( & V_362 , V_280 , sizeof( V_362 ) ) )
goto V_139;
V_32 = F_362 ( V_18 , & V_362 ) ;
break;
}
#endif
case V_364 : {
struct V_365 V_208 ;
V_32 = - V_164 ;
if ( F_337 ( & V_208 , V_280 , sizeof( V_208 ) ) )
goto V_139;
V_32 = V_365 ( V_18 , & V_208 ) ;
break;
}
case V_366 : {
struct V_367 V_208 ;
V_32 = - V_164 ;
if ( F_337 ( & V_208 , V_280 , sizeof( V_208 ) ) )
goto V_139;
V_32 = V_367 ( V_18 , & V_208 ) ;
break;
}
#ifdef F_356
case V_368 : {
struct V_369 V_370 ;
V_32 = - V_164 ;
if ( F_337 ( & V_370 , V_280 , sizeof( V_370 ) ) )
goto V_139;
V_32 = F_363 ( V_18 , & V_370 ) ;
break;
}
#endif
#ifdef F_364
case V_371 :
case V_372 : {
struct V_373 V_374 ;
V_32 = - V_164 ;
if ( F_337 ( & V_374 , V_280 , sizeof( V_374 ) ) )
goto V_139;
V_32 = F_365 ( V_18 , & V_374 ,
V_278 == V_371 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( V_278 == V_371 ) {
if ( F_152 ( V_280 , & V_374 , sizeof( V_374 ) ) )
goto V_139;
}
V_32 = 0 ;
break;
}
#endif
#ifdef F_357
case V_375 : {
struct V_376 V_377 ;
struct V_376 V_147 * V_378 ;
struct V_379 * V_380 = NULL ;
V_32 = - V_164 ;
if ( F_337 ( & V_377 , V_280 , sizeof( V_377 ) ) )
goto V_139;
V_32 = - V_132 ;
if ( ! F_366 ( V_18 ) )
goto V_139;
if ( V_377 . V_381 > V_353 )
goto V_139;
if ( V_377 . V_131 )
goto V_139;
if ( V_377 . V_381 ) {
V_32 = - V_40 ;
V_380 = F_367 ( V_377 . V_381 * sizeof( * V_380 ) ) ;
if ( ! V_380 )
goto V_139;
V_32 = - V_164 ;
V_378 = V_280 ;
if ( F_337 ( V_380 , V_378 -> V_380 ,
V_377 . V_381 * sizeof( * V_380 ) ) )
goto V_382;
}
V_32 = F_368 ( V_18 , V_380 , V_377 . V_381 ,
V_377 . V_131 ) ;
V_382:
F_369 ( V_380 ) ;
break;
}
#endif
case V_383 : {
struct V_335 V_336 ;
V_32 = - V_164 ;
if ( F_337 ( & V_336 , V_280 , sizeof( V_336 ) ) )
goto V_139;
V_32 = F_354 ( V_18 , & V_336 ) ;
if ( V_32 )
goto V_139;
V_32 = - V_164 ;
if ( F_152 ( V_280 , & V_336 , sizeof( V_336 ) ) )
goto V_139;
V_32 = 0 ;
break;
}
case V_384 :
V_32 = F_355 ( V_18 , V_279 ) ;
break;
default:
V_32 = F_370 ( V_119 , V_278 , V_279 ) ;
}
V_139:
return V_32 ;
}
static long F_371 ( struct V_118 * V_119 ,
unsigned int V_278 , unsigned long V_279 )
{
struct V_18 * V_18 = V_119 -> V_120 ;
int V_32 ;
if ( V_18 -> V_48 != V_62 -> V_48 )
return - V_284 ;
switch ( V_278 ) {
case V_359 : {
struct V_385 V_386 ;
struct V_159 log ;
if ( F_337 ( & V_386 , ( void V_147 * ) V_279 ,
sizeof( V_386 ) ) )
return - V_164 ;
log . V_135 = V_386 . V_135 ;
log . V_387 = V_386 . V_387 ;
log . V_388 = V_386 . V_388 ;
log . V_70 = F_344 ( V_386 . V_70 ) ;
V_32 = F_360 ( V_18 , & log ) ;
break;
}
default:
V_32 = F_359 ( V_119 , V_278 , V_279 ) ;
}
return V_32 ;
}
static int F_372 ( unsigned long type )
{
int V_32 ;
struct V_18 * V_18 ;
struct V_118 * V_118 ;
V_18 = F_90 ( type ) ;
if ( F_311 ( V_18 ) )
return F_312 ( V_18 ) ;
#ifdef F_300
V_32 = F_373 ( V_18 ) ;
if ( V_32 < 0 ) {
F_127 ( V_18 ) ;
return V_32 ;
}
#endif
V_32 = F_374 ( V_264 ) ;
if ( V_32 < 0 ) {
F_127 ( V_18 ) ;
return V_32 ;
}
V_118 = F_375 ( L_4 , & V_389 , V_18 , V_263 ) ;
if ( F_311 ( V_118 ) ) {
F_376 ( V_32 ) ;
F_127 ( V_18 ) ;
return F_312 ( V_118 ) ;
}
if ( F_83 ( V_18 , V_32 ) < 0 ) {
F_376 ( V_32 ) ;
F_377 ( V_118 ) ;
return - V_40 ;
}
F_116 ( V_390 , V_18 ) ;
F_378 ( V_32 , V_118 ) ;
return V_32 ;
}
static long F_379 ( struct V_118 * V_119 ,
unsigned int V_278 , unsigned long V_279 )
{
long V_32 = - V_132 ;
switch ( V_278 ) {
case V_391 :
if ( V_279 )
goto V_139;
V_32 = V_392 ;
break;
case V_393 :
V_32 = F_372 ( V_279 ) ;
break;
case V_384 :
V_32 = F_355 ( NULL , V_279 ) ;
break;
case V_394 :
if ( V_279 )
goto V_139;
V_32 = V_142 ;
#ifdef F_299
V_32 += V_142 ;
#endif
#ifdef F_300
V_32 += V_142 ;
#endif
break;
case V_395 :
case V_396 :
case V_397 :
V_32 = - V_398 ;
break;
default:
return F_380 ( V_119 , V_278 , V_279 ) ;
}
V_139:
return V_32 ;
}
static void F_381 ( void * V_399 )
{
int V_4 = F_382 () ;
int V_32 ;
if ( F_383 ( V_4 , V_400 ) )
return;
F_384 ( V_4 , V_400 ) ;
V_32 = F_385 () ;
if ( V_32 ) {
F_386 ( V_4 , V_400 ) ;
F_317 ( & V_401 ) ;
F_387 ( L_5 , V_4 ) ;
}
}
static int F_388 ( unsigned int V_4 )
{
F_389 ( & V_402 ) ;
if ( V_403 )
F_381 ( NULL ) ;
F_390 ( & V_402 ) ;
return 0 ;
}
static void F_391 ( void * V_399 )
{
int V_4 = F_382 () ;
if ( ! F_383 ( V_4 , V_400 ) )
return;
F_386 ( V_4 , V_400 ) ;
F_392 () ;
}
static int F_393 ( unsigned int V_4 )
{
F_389 ( & V_402 ) ;
if ( V_403 )
F_391 ( NULL ) ;
F_390 ( & V_402 ) ;
return 0 ;
}
static void F_394 ( void )
{
F_62 ( ! V_403 ) ;
V_403 -- ;
if ( ! V_403 )
F_395 ( F_391 , NULL , 1 ) ;
}
static void F_107 ( void )
{
F_389 ( & V_402 ) ;
F_394 () ;
F_390 ( & V_402 ) ;
}
static int F_98 ( void )
{
int V_32 = 0 ;
F_389 ( & V_402 ) ;
V_403 ++ ;
if ( V_403 == 1 ) {
F_396 ( & V_401 , 0 ) ;
F_395 ( F_381 , NULL , 1 ) ;
if ( F_316 ( & V_401 ) ) {
F_394 () ;
V_32 = - V_404 ;
}
}
F_390 ( & V_402 ) ;
return V_32 ;
}
static int F_397 ( struct V_405 * V_406 , unsigned long V_220 ,
void * V_407 )
{
F_387 ( L_6 ) ;
V_408 = true ;
F_395 ( F_391 , NULL , 1 ) ;
return V_409 ;
}
static void F_119 ( struct V_104 * V_114 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_114 -> V_410 ; V_19 ++ ) {
struct V_411 * V_412 = V_114 -> V_413 [ V_19 ] . V_109 ;
F_398 ( V_412 ) ;
}
F_82 ( V_114 ) ;
}
static inline int F_399 ( const struct V_414 * V_415 ,
const struct V_414 * V_416 )
{
T_6 V_417 = V_415 -> V_172 ;
T_6 V_418 = V_416 -> V_172 ;
if ( V_417 < V_418 )
return - 1 ;
if ( V_416 -> V_207 ) {
V_417 += V_415 -> V_207 ;
V_418 += V_416 -> V_207 ;
}
if ( V_417 > V_418 )
return 1 ;
return 0 ;
}
static int F_400 ( const void * V_419 , const void * V_420 )
{
return F_399 ( V_419 , V_420 ) ;
}
static int F_401 ( struct V_104 * V_114 , struct V_411 * V_109 ,
T_6 V_172 , int V_207 )
{
V_114 -> V_413 [ V_114 -> V_410 ++ ] = (struct V_414 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
. V_109 = V_109 ,
} ;
F_402 ( V_114 -> V_413 , V_114 -> V_410 , sizeof( struct V_414 ) ,
F_400 , NULL ) ;
return 0 ;
}
static int F_403 ( struct V_104 * V_114 ,
T_6 V_172 , int V_207 )
{
struct V_414 * V_413 , V_421 ;
int V_422 ;
V_421 = (struct V_414 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_413 = bsearch ( & V_421 , V_114 -> V_413 , V_114 -> V_410 ,
sizeof( struct V_414 ) , F_400 ) ;
if ( V_413 == NULL )
return - V_163 ;
V_422 = V_413 - V_114 -> V_413 ;
while ( V_422 > 0 && F_399 ( & V_421 , & V_114 -> V_413 [ V_422 - 1 ] ) == 0 )
V_422 -- ;
return V_422 ;
}
static int F_404 ( struct V_2 * V_3 , struct V_104 * V_114 ,
struct V_414 * V_413 , const void * V_220 )
{
int V_51 ;
V_51 = F_403 ( V_114 , V_413 -> V_172 , V_413 -> V_207 ) ;
if ( V_51 < 0 )
return - V_398 ;
while ( V_51 < V_114 -> V_410 &&
F_399 ( V_413 , & V_114 -> V_413 [ V_51 ] ) == 0 ) {
if ( ! F_405 ( V_3 , V_114 -> V_413 [ V_51 ] . V_109 , V_413 -> V_172 ,
V_413 -> V_207 , V_220 ) )
return V_51 ;
V_51 ++ ;
}
return - V_398 ;
}
int F_406 ( struct V_2 * V_3 , enum V_423 V_424 , T_6 V_172 ,
int V_207 , const void * V_220 )
{
struct V_104 * V_114 ;
struct V_414 V_413 ;
int V_32 ;
V_413 = (struct V_414 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_114 = F_407 ( V_3 -> V_18 -> V_103 [ V_424 ] , & V_3 -> V_18 -> V_52 ) ;
if ( ! V_114 )
return - V_40 ;
V_32 = F_404 ( V_3 , V_114 , & V_413 , V_220 ) ;
return V_32 < 0 ? V_32 : 0 ;
}
int F_408 ( struct V_2 * V_3 , enum V_423 V_424 ,
T_6 V_172 , int V_207 , const void * V_220 , long V_425 )
{
struct V_104 * V_114 ;
struct V_414 V_413 ;
V_413 = (struct V_414 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_114 = F_407 ( V_3 -> V_18 -> V_103 [ V_424 ] , & V_3 -> V_18 -> V_52 ) ;
if ( ! V_114 )
return - V_40 ;
if ( ( V_425 >= 0 ) && ( V_425 < V_114 -> V_410 ) &&
( F_399 ( & V_413 , & V_114 -> V_413 [ V_425 ] ) == 0 ) )
if ( ! F_405 ( V_3 , V_114 -> V_413 [ V_425 ] . V_109 , V_172 , V_207 ,
V_220 ) )
return V_425 ;
return F_404 ( V_3 , V_114 , & V_413 , V_220 ) ;
}
static int F_409 ( struct V_2 * V_3 , struct V_104 * V_114 ,
struct V_414 * V_413 , void * V_220 )
{
int V_51 ;
V_51 = F_403 ( V_114 , V_413 -> V_172 , V_413 -> V_207 ) ;
if ( V_51 < 0 )
return - V_398 ;
while ( V_51 < V_114 -> V_410 &&
F_399 ( V_413 , & V_114 -> V_413 [ V_51 ] ) == 0 ) {
if ( ! F_410 ( V_3 , V_114 -> V_413 [ V_51 ] . V_109 , V_413 -> V_172 ,
V_413 -> V_207 , V_220 ) )
return V_51 ;
V_51 ++ ;
}
return - V_398 ;
}
int F_411 ( struct V_2 * V_3 , enum V_423 V_424 , T_6 V_172 ,
int V_207 , void * V_220 )
{
struct V_104 * V_114 ;
struct V_414 V_413 ;
int V_32 ;
V_413 = (struct V_414 ) {
. V_172 = V_172 ,
. V_207 = V_207 ,
} ;
V_114 = F_407 ( V_3 -> V_18 -> V_103 [ V_424 ] , & V_3 -> V_18 -> V_52 ) ;
if ( ! V_114 )
return - V_40 ;
V_32 = F_409 ( V_3 , V_114 , & V_413 , V_220 ) ;
return V_32 < 0 ? V_32 : 0 ;
}
int F_412 ( struct V_18 * V_18 , enum V_423 V_424 , T_6 V_172 ,
int V_207 , struct V_411 * V_109 )
{
struct V_104 * V_426 , * V_114 ;
V_114 = F_108 ( V_18 , V_424 ) ;
if ( ! V_114 )
return - V_40 ;
if ( V_114 -> V_410 - V_114 -> V_427 > V_428 - 1 )
return - V_334 ;
V_426 = F_413 ( sizeof( * V_114 ) + ( ( V_114 -> V_410 + 1 ) *
sizeof( struct V_414 ) ) , V_38 ) ;
if ( ! V_426 )
return - V_40 ;
memcpy ( V_426 , V_114 , sizeof( * V_114 ) + ( V_114 -> V_410 *
sizeof( struct V_414 ) ) ) ;
F_401 ( V_426 , V_109 , V_172 , V_207 ) ;
F_102 ( V_18 -> V_103 [ V_424 ] , V_426 ) ;
F_139 ( & V_18 -> V_52 ) ;
F_82 ( V_114 ) ;
return 0 ;
}
void F_414 ( struct V_18 * V_18 , enum V_423 V_424 ,
struct V_411 * V_109 )
{
int V_19 ;
struct V_104 * V_426 , * V_114 ;
V_114 = F_108 ( V_18 , V_424 ) ;
if ( ! V_114 )
return;
for ( V_19 = 0 ; V_19 < V_114 -> V_410 ; V_19 ++ )
if ( V_114 -> V_413 [ V_19 ] . V_109 == V_109 ) {
break;
}
if ( V_19 == V_114 -> V_410 )
return;
V_426 = F_413 ( sizeof( * V_114 ) + ( ( V_114 -> V_410 - 1 ) *
sizeof( struct V_414 ) ) , V_38 ) ;
if ( ! V_426 ) {
F_415 ( L_7 ) ;
goto V_429;
}
memcpy ( V_426 , V_114 , sizeof( * V_114 ) + V_19 * sizeof( struct V_414 ) ) ;
V_426 -> V_410 -- ;
memcpy ( V_426 -> V_413 + V_19 , V_114 -> V_413 + V_19 + 1 ,
( V_426 -> V_410 - V_19 ) * sizeof( struct V_414 ) ) ;
V_429:
F_102 ( V_18 -> V_103 [ V_424 ] , V_426 ) ;
F_139 ( & V_18 -> V_52 ) ;
F_82 ( V_114 ) ;
return;
}
struct V_411 * F_416 ( struct V_18 * V_18 , enum V_423 V_424 ,
T_6 V_172 )
{
struct V_104 * V_114 ;
int V_430 , V_431 ;
struct V_411 * V_432 = NULL ;
V_431 = F_53 ( & V_18 -> V_52 ) ;
V_114 = F_407 ( V_18 -> V_103 [ V_424 ] , & V_18 -> V_52 ) ;
if ( ! V_114 )
goto V_433;
V_430 = F_403 ( V_114 , V_172 , 1 ) ;
if ( V_430 < 0 )
goto V_433;
V_432 = V_114 -> V_413 [ V_430 ] . V_109 ;
V_433:
F_57 ( & V_18 -> V_52 , V_431 ) ;
return V_432 ;
}
static int F_417 ( struct V_117 * V_117 , struct V_118 * V_118 ,
int (* F_418)( void * , T_8 * ) , int (* F_419)( void * , T_8 ) ,
const char * V_434 )
{
struct V_79 * V_80 = (struct V_79 * )
V_117 -> V_435 ;
if ( ! F_420 ( & V_80 -> V_18 -> V_92 ) )
return - V_163 ;
if ( F_421 ( V_117 , V_118 , F_418 , F_419 , V_434 ) ) {
F_127 ( V_80 -> V_18 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_422 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
struct V_79 * V_80 = (struct V_79 * )
V_117 -> V_435 ;
F_423 ( V_117 , V_118 ) ;
F_127 ( V_80 -> V_18 ) ;
return 0 ;
}
static int F_424 ( void * V_208 , T_8 * V_220 )
{
struct V_79 * V_80 = (struct V_79 * ) V_208 ;
* V_220 = * ( V_436 * ) ( ( void * ) V_80 -> V_18 + V_80 -> V_86 ) ;
return 0 ;
}
static int F_425 ( void * V_208 , T_8 V_220 )
{
struct V_79 * V_80 = (struct V_79 * ) V_208 ;
if ( V_220 )
return - V_132 ;
* ( V_436 * ) ( ( void * ) V_80 -> V_18 + V_80 -> V_86 ) = 0 ;
return 0 ;
}
static int F_426 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
F_427 ( L_8 , 0ull ) ;
return F_417 ( V_117 , V_118 , F_424 ,
F_425 , L_8 ) ;
}
static int F_428 ( void * V_208 , T_8 * V_220 )
{
int V_19 ;
struct V_79 * V_80 = (struct V_79 * ) V_208 ;
struct V_2 * V_3 ;
* V_220 = 0 ;
F_26 ( V_19 , V_3 , V_80 -> V_18 )
* V_220 += * ( T_8 * ) ( ( void * ) V_3 + V_80 -> V_86 ) ;
return 0 ;
}
static int F_429 ( void * V_208 , T_8 V_220 )
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
static int F_430 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
F_427 ( L_8 , 0ull ) ;
return F_417 ( V_117 , V_118 , F_428 ,
F_429 , L_8 ) ;
}
static int F_431 ( void * V_437 , T_8 * V_220 )
{
unsigned V_86 = ( long ) V_437 ;
struct V_18 * V_18 ;
struct V_79 V_438 = { . V_86 = V_86 } ;
T_8 V_439 ;
* V_220 = 0 ;
F_54 ( & V_106 ) ;
F_432 (kvm, &vm_list, vm_list) {
V_438 . V_18 = V_18 ;
F_424 ( ( void * ) & V_438 , & V_439 ) ;
* V_220 += V_439 ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static int F_433 ( void * V_437 , T_8 V_220 )
{
unsigned V_86 = ( long ) V_437 ;
struct V_18 * V_18 ;
struct V_79 V_438 = { . V_86 = V_86 } ;
if ( V_220 )
return - V_132 ;
F_54 ( & V_106 ) ;
F_432 (kvm, &vm_list, vm_list) {
V_438 . V_18 = V_18 ;
F_425 ( ( void * ) & V_438 , 0 ) ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static int F_434 ( void * V_437 , T_8 * V_220 )
{
unsigned V_86 = ( long ) V_437 ;
struct V_18 * V_18 ;
struct V_79 V_438 = { . V_86 = V_86 } ;
T_8 V_439 ;
* V_220 = 0 ;
F_54 ( & V_106 ) ;
F_432 (kvm, &vm_list, vm_list) {
V_438 . V_18 = V_18 ;
F_428 ( ( void * ) & V_438 , & V_439 ) ;
* V_220 += V_439 ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static int F_435 ( void * V_437 , T_8 V_220 )
{
unsigned V_86 = ( long ) V_437 ;
struct V_18 * V_18 ;
struct V_79 V_438 = { . V_86 = V_86 } ;
if ( V_220 )
return - V_132 ;
F_54 ( & V_106 ) ;
F_432 (kvm, &vm_list, vm_list) {
V_438 . V_18 = V_18 ;
F_429 ( ( void * ) & V_438 , 0 ) ;
}
F_56 ( & V_106 ) ;
return 0 ;
}
static void F_116 ( unsigned int type , struct V_18 * V_18 )
{
struct V_440 * V_441 ;
unsigned long long V_442 , V_443 ;
if ( ! V_444 . V_445 || ! V_18 )
return;
F_54 ( & V_106 ) ;
if ( type == V_390 ) {
V_446 ++ ;
V_447 ++ ;
} else if ( type == V_113 ) {
V_447 -- ;
}
V_442 = V_446 ;
V_443 = V_447 ;
F_56 ( & V_106 ) ;
V_441 = F_88 ( sizeof( * V_441 ) , V_38 ) ;
if ( ! V_441 )
return;
F_436 ( V_441 , L_9 , V_442 ) ;
F_436 ( V_441 , L_10 , V_443 ) ;
if ( type == V_390 ) {
F_436 ( V_441 , L_11 ) ;
V_18 -> V_448 = F_85 ( V_62 ) ;
} else if ( type == V_113 ) {
F_436 ( V_441 , L_12 ) ;
}
F_436 ( V_441 , L_13 , V_18 -> V_448 ) ;
if ( V_18 -> V_73 ) {
char * V_110 , * V_82 = F_413 ( V_449 , V_38 ) ;
if ( V_82 ) {
V_110 = F_437 ( V_18 -> V_73 , V_82 , V_449 ) ;
if ( ! F_311 ( V_110 ) )
F_436 ( V_441 , L_14 , V_110 ) ;
F_82 ( V_82 ) ;
}
}
V_441 -> V_450 [ V_441 -> V_451 ++ ] = NULL ;
F_438 ( & V_444 . V_445 -> V_452 , V_453 , V_441 -> V_450 ) ;
F_82 ( V_441 ) ;
}
static int F_439 ( void )
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
V_454 [ V_82 -> V_88 ] ) )
goto V_455;
}
return 0 ;
V_455:
F_81 ( V_83 ) ;
V_139:
return V_32 ;
}
static int F_440 ( void )
{
if ( V_403 )
F_391 ( NULL ) ;
return 0 ;
}
static void F_441 ( void )
{
if ( V_403 ) {
F_134 ( F_442 ( & V_402 ) ) ;
F_381 ( NULL ) ;
}
}
static inline
struct V_2 * F_443 ( struct V_7 * V_456 )
{
return F_51 ( V_456 , struct V_2 , V_7 ) ;
}
static void F_444 ( struct V_7 * V_456 , int V_4 )
{
struct V_2 * V_3 = F_443 ( V_456 ) ;
if ( V_3 -> V_43 )
V_3 -> V_43 = false ;
F_445 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_446 ( struct V_7 * V_456 ,
struct V_240 * V_457 )
{
struct V_2 * V_3 = F_443 ( V_456 ) ;
if ( V_62 -> V_458 == V_459 )
V_3 -> V_43 = true ;
F_13 ( V_3 ) ;
}
int F_447 ( void * V_460 , unsigned V_461 , unsigned V_462 ,
struct V_463 * V_463 )
{
int V_32 ;
int V_4 ;
V_32 = F_448 ( V_460 ) ;
if ( V_32 )
goto V_464;
V_32 = F_449 () ;
if ( V_32 )
goto V_465;
if ( ! F_25 ( & V_400 , V_38 ) ) {
V_32 = - V_40 ;
goto V_466;
}
V_32 = F_450 () ;
if ( V_32 < 0 )
goto V_467;
F_451 (cpu) {
F_452 ( V_4 ,
V_468 ,
& V_32 , 1 ) ;
if ( V_32 < 0 )
goto V_469;
}
V_32 = F_453 ( V_470 , L_16 ,
F_388 , F_393 ) ;
if ( V_32 )
goto V_471;
F_454 ( & V_472 ) ;
if ( ! V_462 )
V_462 = F_455 ( struct V_2 ) ;
V_473 = F_456 ( L_17 , V_461 , V_462 ,
0 , NULL ) ;
if ( ! V_473 ) {
V_32 = - V_40 ;
goto V_474;
}
V_32 = F_457 () ;
if ( V_32 )
goto V_155;
V_475 . V_476 = V_463 ;
V_389 . V_476 = V_463 ;
V_262 . V_476 = V_463 ;
V_32 = F_458 ( & V_444 ) ;
if ( V_32 ) {
F_415 ( L_18 ) ;
goto V_477;
}
F_459 ( & V_478 ) ;
V_269 . V_479 = F_444 ;
V_269 . V_480 = F_446 ;
V_32 = F_439 () ;
if ( V_32 ) {
F_415 ( L_19 ) ;
goto V_481;
}
V_32 = F_460 () ;
F_134 ( V_32 ) ;
return 0 ;
V_481:
F_461 ( & V_478 ) ;
F_462 ( & V_444 ) ;
V_477:
F_463 () ;
V_155:
F_464 ( V_473 ) ;
V_474:
F_465 ( & V_472 ) ;
F_466 ( V_470 ) ;
V_471:
V_469:
F_467 () ;
V_467:
F_30 ( V_400 ) ;
V_466:
F_468 () ;
V_465:
F_469 () ;
V_464:
return V_32 ;
}
void F_470 ( void )
{
F_81 ( V_83 ) ;
F_462 ( & V_444 ) ;
F_464 ( V_473 ) ;
F_463 () ;
F_461 ( & V_478 ) ;
F_465 ( & V_472 ) ;
F_466 ( V_470 ) ;
F_395 ( F_391 , NULL , 1 ) ;
F_467 () ;
F_469 () ;
F_468 () ;
F_30 ( V_400 ) ;
F_471 () ;
}
