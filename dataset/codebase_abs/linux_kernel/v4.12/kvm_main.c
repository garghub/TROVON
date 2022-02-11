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
bool F_20 ( struct V_14 * V_14 , unsigned int V_8 )
{
int V_15 , V_4 , V_16 ;
T_2 V_17 ;
bool V_18 = true ;
bool V_19 = V_8 & V_10 ;
struct V_2 * V_3 ;
F_21 ( & V_17 , V_20 ) ;
V_16 = F_7 () ;
F_22 (i, vcpu, kvm) {
F_23 ( V_8 , V_3 ) ;
V_4 = V_3 -> V_4 ;
if ( ! ( V_8 & V_21 ) && F_24 ( V_3 ) )
continue;
if ( V_17 != NULL && V_4 != - 1 && V_4 != V_16 &&
F_17 ( V_3 , V_8 ) )
F_25 ( V_4 , V_17 ) ;
}
if ( F_26 ( V_17 == NULL ) )
F_27 ( V_22 , F_19 , NULL , V_19 ) ;
else if ( ! F_28 ( V_17 ) )
F_27 ( V_17 , F_19 , NULL , V_19 ) ;
else
V_18 = false ;
F_10 () ;
F_29 ( V_17 ) ;
return V_18 ;
}
void F_30 ( struct V_14 * V_14 )
{
long V_23 = F_31 ( & V_14 -> V_24 ) ;
if ( F_20 ( V_14 , V_25 ) )
++ V_14 -> V_26 . V_27 ;
F_32 ( & V_14 -> V_24 , V_23 , 0 ) ;
}
void F_33 ( struct V_14 * V_14 )
{
F_20 ( V_14 , V_28 ) ;
}
int F_34 ( struct V_2 * V_3 , struct V_14 * V_14 , unsigned V_29 )
{
struct V_30 * V_30 ;
int V_31 ;
F_35 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_32 = V_29 ;
V_3 -> V_33 = NULL ;
F_36 ( & V_3 -> V_34 ) ;
F_37 ( V_3 ) ;
V_3 -> V_35 = - 1 ;
F_38 ( & V_3 -> V_36 ) ;
V_30 = F_39 ( V_37 | V_38 ) ;
if ( ! V_30 ) {
V_31 = - V_39 ;
goto V_40;
}
V_3 -> V_41 = F_40 ( V_30 ) ;
F_41 ( V_3 , false ) ;
F_42 ( V_3 , false ) ;
V_3 -> V_42 = false ;
V_31 = F_43 ( V_3 ) ;
if ( V_31 < 0 )
goto V_43;
return 0 ;
V_43:
F_44 ( ( unsigned long ) V_3 -> V_41 ) ;
V_40:
return V_31 ;
}
void F_45 ( struct V_2 * V_3 )
{
F_46 ( V_3 -> V_33 ) ;
F_47 ( V_3 ) ;
F_44 ( ( unsigned long ) V_3 -> V_41 ) ;
}
static inline struct V_14 * F_48 ( struct V_44 * V_45 )
{
return F_49 ( V_45 , struct V_14 , V_44 ) ;
}
static void F_50 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
int V_49 , V_50 ;
V_50 = F_51 ( & V_14 -> V_51 ) ;
F_52 ( & V_14 -> V_52 ) ;
V_14 -> V_53 ++ ;
V_49 = F_53 ( V_14 , V_48 ) | V_14 -> V_24 ;
if ( V_49 )
F_30 ( V_14 ) ;
F_54 ( & V_14 -> V_52 ) ;
F_55 ( V_14 , V_48 ) ;
F_56 ( & V_14 -> V_51 , V_50 ) ;
}
static void F_57 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 ,
T_3 V_54 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
int V_50 ;
V_50 = F_51 ( & V_14 -> V_51 ) ;
F_52 ( & V_14 -> V_52 ) ;
V_14 -> V_53 ++ ;
F_58 ( V_14 , V_48 , V_54 ) ;
F_54 ( & V_14 -> V_52 ) ;
F_56 ( & V_14 -> V_51 , V_50 ) ;
}
static void F_59 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
int V_49 = 0 , V_50 ;
V_50 = F_51 ( & V_14 -> V_51 ) ;
F_52 ( & V_14 -> V_52 ) ;
V_14 -> V_57 ++ ;
V_49 = F_60 ( V_14 , V_55 , V_56 ) ;
V_49 |= V_14 -> V_24 ;
if ( V_49 )
F_30 ( V_14 ) ;
F_54 ( & V_14 -> V_52 ) ;
F_56 ( & V_14 -> V_51 , V_50 ) ;
}
static void F_61 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
F_52 ( & V_14 -> V_52 ) ;
V_14 -> V_53 ++ ;
F_62 () ;
V_14 -> V_57 -- ;
F_54 ( & V_14 -> V_52 ) ;
F_63 ( V_14 -> V_57 < 0 ) ;
}
static int F_64 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_51 ( & V_14 -> V_51 ) ;
F_52 ( & V_14 -> V_52 ) ;
V_58 = F_65 ( V_14 , V_55 , V_56 ) ;
if ( V_58 )
F_30 ( V_14 ) ;
F_54 ( & V_14 -> V_52 ) ;
F_56 ( & V_14 -> V_51 , V_50 ) ;
return V_58 ;
}
static int F_66 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_51 ( & V_14 -> V_51 ) ;
F_52 ( & V_14 -> V_52 ) ;
V_58 = F_65 ( V_14 , V_55 , V_56 ) ;
F_54 ( & V_14 -> V_52 ) ;
F_56 ( & V_14 -> V_51 , V_50 ) ;
return V_58 ;
}
static int F_67 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_51 ( & V_14 -> V_51 ) ;
F_52 ( & V_14 -> V_52 ) ;
V_58 = F_68 ( V_14 , V_48 ) ;
F_54 ( & V_14 -> V_52 ) ;
F_56 ( & V_14 -> V_51 , V_50 ) ;
return V_58 ;
}
static void F_69 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_14 * V_14 = F_48 ( V_45 ) ;
int V_50 ;
V_50 = F_51 ( & V_14 -> V_51 ) ;
F_70 ( V_14 ) ;
F_56 ( & V_14 -> V_51 , V_50 ) ;
}
static int F_71 ( struct V_14 * V_14 )
{
V_14 -> V_44 . V_59 = & V_60 ;
return F_72 ( & V_14 -> V_44 , V_61 -> V_47 ) ;
}
static int F_71 ( struct V_14 * V_14 )
{
return 0 ;
}
static struct V_62 * F_73 ( void )
{
int V_15 ;
struct V_62 * V_63 ;
V_63 = F_74 ( sizeof( struct V_62 ) , V_37 ) ;
if ( ! V_63 )
return NULL ;
for ( V_15 = 0 ; V_15 < V_64 ; V_15 ++ )
V_63 -> V_65 [ V_15 ] = V_63 -> V_66 [ V_15 ] . V_29 = V_15 ;
return V_63 ;
}
static void F_75 ( struct V_67 * V_68 )
{
if ( ! V_68 -> V_69 )
return;
F_76 ( V_68 -> V_69 ) ;
V_68 -> V_69 = NULL ;
}
static void F_77 ( struct V_14 * V_14 , struct V_67 * free ,
struct V_67 * V_70 )
{
if ( ! V_70 || free -> V_69 != V_70 -> V_69 )
F_75 ( free ) ;
F_78 ( V_14 , free , V_70 ) ;
free -> V_71 = 0 ;
}
static void F_79 ( struct V_14 * V_14 , struct V_62 * V_63 )
{
struct V_67 * V_68 ;
if ( ! V_63 )
return;
F_80 (memslot, slots)
F_77 ( V_14 , V_68 , NULL ) ;
F_76 ( V_63 ) ;
}
static void F_81 ( struct V_14 * V_14 )
{
int V_15 ;
if ( ! V_14 -> V_72 )
return;
F_82 ( V_14 -> V_72 ) ;
if ( V_14 -> V_73 ) {
for ( V_15 = 0 ; V_15 < V_74 ; V_15 ++ )
F_83 ( V_14 -> V_73 [ V_15 ] ) ;
F_83 ( V_14 -> V_73 ) ;
}
}
static int F_84 ( struct V_14 * V_14 , int V_75 )
{
char V_76 [ V_77 * 2 ] ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
if ( ! F_85 () )
return 0 ;
snprintf ( V_76 , sizeof( V_76 ) , L_1 , F_86 ( V_61 ) , V_75 ) ;
V_14 -> V_72 = F_87 ( V_76 ,
V_82 ) ;
if ( ! V_14 -> V_72 )
return - V_39 ;
V_14 -> V_73 = F_88 ( V_74 ,
sizeof( * V_14 -> V_73 ) ,
V_37 ) ;
if ( ! V_14 -> V_73 )
return - V_39 ;
for ( V_81 = V_83 ; V_81 -> V_84 ; V_81 ++ ) {
V_79 = F_89 ( sizeof( * V_79 ) , V_37 ) ;
if ( ! V_79 )
return - V_39 ;
V_79 -> V_14 = V_14 ;
V_79 -> V_85 = V_81 -> V_85 ;
V_14 -> V_73 [ V_81 - V_83 ] = V_79 ;
if ( ! F_90 ( V_81 -> V_84 , 0644 ,
V_14 -> V_72 ,
V_79 ,
V_86 [ V_81 -> V_87 ] ) )
return - V_39 ;
}
return 0 ;
}
static struct V_14 * F_91 ( unsigned long type )
{
int V_31 , V_15 ;
struct V_14 * V_14 = F_92 () ;
if ( ! V_14 )
return F_93 ( - V_39 ) ;
F_94 ( & V_14 -> V_52 ) ;
F_95 ( V_61 -> V_47 ) ;
V_14 -> V_47 = V_61 -> V_47 ;
F_96 ( V_14 ) ;
F_35 ( & V_14 -> V_88 ) ;
F_35 ( & V_14 -> V_89 ) ;
F_35 ( & V_14 -> V_90 ) ;
F_97 ( & V_14 -> V_91 , 1 ) ;
F_38 ( & V_14 -> V_92 ) ;
V_31 = F_98 ( V_14 , type ) ;
if ( V_31 )
goto V_93;
V_31 = F_99 () ;
if ( V_31 )
goto V_93;
#ifdef F_100
F_101 ( & V_14 -> V_94 ) ;
#endif
F_102 ( V_64 > V_95 ) ;
V_31 = - V_39 ;
for ( V_15 = 0 ; V_15 < V_96 ; V_15 ++ ) {
struct V_62 * V_63 = F_73 () ;
if ( ! V_63 )
goto V_97;
V_63 -> V_98 = V_15 * 2 - 150 ;
F_103 ( V_14 -> V_66 [ V_15 ] , V_63 ) ;
}
if ( F_104 ( & V_14 -> V_51 ) )
goto V_97;
if ( F_104 ( & V_14 -> V_99 ) )
goto V_100;
for ( V_15 = 0 ; V_15 < V_101 ; V_15 ++ ) {
V_14 -> V_102 [ V_15 ] = F_89 ( sizeof( struct V_103 ) ,
V_37 ) ;
if ( ! V_14 -> V_102 [ V_15 ] )
goto V_104;
}
V_31 = F_71 ( V_14 ) ;
if ( V_31 )
goto V_104;
F_52 ( & V_105 ) ;
F_105 ( & V_14 -> V_106 , & V_106 ) ;
F_54 ( & V_105 ) ;
F_106 () ;
return V_14 ;
V_104:
F_107 ( & V_14 -> V_99 ) ;
V_100:
F_107 ( & V_14 -> V_51 ) ;
V_97:
F_108 () ;
V_93:
for ( V_15 = 0 ; V_15 < V_101 ; V_15 ++ )
F_83 ( V_14 -> V_102 [ V_15 ] ) ;
for ( V_15 = 0 ; V_15 < V_96 ; V_15 ++ )
F_79 ( V_14 , V_14 -> V_66 [ V_15 ] ) ;
F_109 ( V_14 ) ;
F_110 ( V_61 -> V_47 ) ;
return F_93 ( V_31 ) ;
}
static void F_111 ( struct V_14 * V_14 )
{
struct V_107 * V_108 , * V_109 ;
F_112 (dev, tmp, &kvm->devices, vm_node) {
F_113 ( & V_108 -> V_110 ) ;
V_108 -> V_59 -> V_111 ( V_108 ) ;
}
}
static void F_114 ( struct V_14 * V_14 )
{
int V_15 ;
struct V_46 * V_47 = V_14 -> V_47 ;
F_81 ( V_14 ) ;
F_115 ( V_14 ) ;
F_52 ( & V_105 ) ;
F_113 ( & V_14 -> V_106 ) ;
F_54 ( & V_105 ) ;
F_116 ( V_14 ) ;
for ( V_15 = 0 ; V_15 < V_101 ; V_15 ++ ) {
if ( V_14 -> V_102 [ V_15 ] )
F_117 ( V_14 -> V_102 [ V_15 ] ) ;
V_14 -> V_102 [ V_15 ] = NULL ;
}
F_118 ( V_14 ) ;
#if F_119 ( V_112 ) && F_119 ( V_113 )
F_120 ( & V_14 -> V_44 , V_14 -> V_47 ) ;
#else
F_70 ( V_14 ) ;
#endif
F_121 ( V_14 ) ;
F_111 ( V_14 ) ;
for ( V_15 = 0 ; V_15 < V_96 ; V_15 ++ )
F_79 ( V_14 , V_14 -> V_66 [ V_15 ] ) ;
F_107 ( & V_14 -> V_99 ) ;
F_107 ( & V_14 -> V_51 ) ;
F_109 ( V_14 ) ;
F_122 () ;
F_108 () ;
F_110 ( V_47 ) ;
}
void F_123 ( struct V_14 * V_14 )
{
F_124 ( & V_14 -> V_91 ) ;
}
void F_125 ( struct V_14 * V_14 )
{
if ( F_126 ( & V_14 -> V_91 ) )
F_114 ( V_14 ) ;
}
static int F_127 ( struct V_114 * V_114 , struct V_115 * V_116 )
{
struct V_14 * V_14 = V_116 -> V_117 ;
F_128 ( V_14 ) ;
F_125 ( V_14 ) ;
return 0 ;
}
static int F_129 ( struct V_67 * V_68 )
{
unsigned long V_118 = 2 * F_130 ( V_68 ) ;
V_68 -> V_69 = F_74 ( V_118 , V_37 ) ;
if ( ! V_68 -> V_69 )
return - V_39 ;
return 0 ;
}
static void F_131 ( struct V_62 * V_63 ,
struct V_67 * V_119 )
{
int V_29 = V_119 -> V_29 ;
int V_15 = V_63 -> V_65 [ V_29 ] ;
struct V_67 * V_120 = V_63 -> V_66 ;
F_132 ( V_120 [ V_15 ] . V_29 != V_29 ) ;
if ( ! V_119 -> V_71 ) {
F_132 ( ! V_120 [ V_15 ] . V_71 ) ;
if ( V_120 [ V_15 ] . V_71 )
V_63 -> V_121 -- ;
} else {
if ( ! V_120 [ V_15 ] . V_71 )
V_63 -> V_121 ++ ;
}
while ( V_15 < V_64 - 1 &&
V_119 -> V_122 <= V_120 [ V_15 + 1 ] . V_122 ) {
if ( ! V_120 [ V_15 + 1 ] . V_71 )
break;
V_120 [ V_15 ] = V_120 [ V_15 + 1 ] ;
V_63 -> V_65 [ V_120 [ V_15 ] . V_29 ] = V_15 ;
V_15 ++ ;
}
if ( V_119 -> V_71 ) {
while ( V_15 > 0 &&
V_119 -> V_122 >= V_120 [ V_15 - 1 ] . V_122 ) {
V_120 [ V_15 ] = V_120 [ V_15 - 1 ] ;
V_63 -> V_65 [ V_120 [ V_15 ] . V_29 ] = V_15 ;
V_15 -- ;
}
} else
F_133 ( V_15 != V_63 -> V_121 ) ;
V_120 [ V_15 ] = * V_119 ;
V_63 -> V_65 [ V_120 [ V_15 ] . V_29 ] = V_15 ;
}
static int F_134 ( const struct V_123 * V_124 )
{
T_4 V_125 = V_126 ;
#ifdef F_135
V_125 |= V_127 ;
#endif
if ( V_124 -> V_128 & ~ V_125 )
return - V_129 ;
return 0 ;
}
static struct V_62 * F_136 ( struct V_14 * V_14 ,
int V_130 , struct V_62 * V_63 )
{
struct V_62 * V_131 = F_137 ( V_14 , V_130 ) ;
F_132 ( V_131 -> V_98 & 1 ) ;
V_63 -> V_98 = V_131 -> V_98 + 1 ;
F_103 ( V_14 -> V_66 [ V_130 ] , V_63 ) ;
F_138 ( & V_14 -> V_51 ) ;
V_63 -> V_98 += V_96 * 2 - 1 ;
F_139 ( V_14 , V_63 ) ;
return V_131 ;
}
int F_140 ( struct V_14 * V_14 ,
const struct V_123 * V_124 )
{
int V_31 ;
T_5 V_122 ;
unsigned long V_71 ;
struct V_67 * V_132 ;
struct V_67 V_133 , V_119 ;
struct V_62 * V_63 = NULL , * V_131 ;
int V_130 , V_29 ;
enum V_134 V_135 ;
V_31 = F_134 ( V_124 ) ;
if ( V_31 )
goto V_136;
V_31 = - V_129 ;
V_130 = V_124 -> V_132 >> 16 ;
V_29 = ( V_137 ) V_124 -> V_132 ;
if ( V_124 -> V_138 & ( V_139 - 1 ) )
goto V_136;
if ( V_124 -> V_140 & ( V_139 - 1 ) )
goto V_136;
if ( ( V_29 < V_141 ) &&
( ( V_124 -> V_142 & ( V_139 - 1 ) ) ||
! F_141 ( V_143 ,
( void V_144 * ) ( unsigned long ) V_124 -> V_142 ,
V_124 -> V_138 ) ) )
goto V_136;
if ( V_130 >= V_96 || V_29 >= V_64 )
goto V_136;
if ( V_124 -> V_140 + V_124 -> V_138 < V_124 -> V_140 )
goto V_136;
V_132 = F_142 ( F_137 ( V_14 , V_130 ) , V_29 ) ;
V_122 = V_124 -> V_140 >> V_145 ;
V_71 = V_124 -> V_138 >> V_145 ;
if ( V_71 > V_146 )
goto V_136;
V_119 = V_133 = * V_132 ;
V_119 . V_29 = V_29 ;
V_119 . V_122 = V_122 ;
V_119 . V_71 = V_71 ;
V_119 . V_128 = V_124 -> V_128 ;
if ( V_71 ) {
if ( ! V_133 . V_71 )
V_135 = V_147 ;
else {
if ( ( V_124 -> V_142 != V_133 . V_142 ) ||
( V_71 != V_133 . V_71 ) ||
( ( V_119 . V_128 ^ V_133 . V_128 ) & V_127 ) )
goto V_136;
if ( V_122 != V_133 . V_122 )
V_135 = V_148 ;
else if ( V_119 . V_128 != V_133 . V_128 )
V_135 = V_149 ;
else {
V_31 = 0 ;
goto V_136;
}
}
} else {
if ( ! V_133 . V_71 )
goto V_136;
V_135 = V_150 ;
V_119 . V_122 = 0 ;
V_119 . V_128 = 0 ;
}
if ( ( V_135 == V_147 ) || ( V_135 == V_148 ) ) {
V_31 = - V_151 ;
F_80 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_132 -> V_29 >= V_141 ) ||
( V_132 -> V_29 == V_29 ) )
continue;
if ( ! ( ( V_122 + V_71 <= V_132 -> V_122 ) ||
( V_122 >= V_132 -> V_122 + V_132 -> V_71 ) ) )
goto V_136;
}
}
if ( ! ( V_119 . V_128 & V_126 ) )
V_119 . V_69 = NULL ;
V_31 = - V_39 ;
if ( V_135 == V_147 ) {
V_119 . V_142 = V_124 -> V_142 ;
if ( F_143 ( V_14 , & V_119 , V_71 ) )
goto V_152;
}
if ( ( V_119 . V_128 & V_126 ) && ! V_119 . V_69 ) {
if ( F_129 ( & V_119 ) < 0 )
goto V_152;
}
V_63 = F_74 ( sizeof( struct V_62 ) , V_37 ) ;
if ( ! V_63 )
goto V_152;
memcpy ( V_63 , F_137 ( V_14 , V_130 ) , sizeof( struct V_62 ) ) ;
if ( ( V_135 == V_150 ) || ( V_135 == V_148 ) ) {
V_132 = F_142 ( V_63 , V_29 ) ;
V_132 -> V_128 |= V_153 ;
V_131 = F_136 ( V_14 , V_130 , V_63 ) ;
F_144 ( V_14 , V_132 ) ;
V_63 = V_131 ;
}
V_31 = F_145 ( V_14 , & V_119 , V_124 , V_135 ) ;
if ( V_31 )
goto V_154;
if ( V_135 == V_150 ) {
V_119 . V_69 = NULL ;
memset ( & V_119 . V_155 , 0 , sizeof( V_119 . V_155 ) ) ;
}
F_131 ( V_63 , & V_119 ) ;
V_131 = F_136 ( V_14 , V_130 , V_63 ) ;
F_146 ( V_14 , V_124 , & V_133 , & V_119 , V_135 ) ;
F_77 ( V_14 , & V_133 , & V_119 ) ;
F_76 ( V_131 ) ;
return 0 ;
V_154:
F_76 ( V_63 ) ;
V_152:
F_77 ( V_14 , & V_119 , & V_133 ) ;
V_136:
return V_31 ;
}
int F_147 ( struct V_14 * V_14 ,
const struct V_123 * V_124 )
{
int V_31 ;
F_148 ( & V_14 -> V_90 ) ;
V_31 = F_140 ( V_14 , V_124 ) ;
F_16 ( & V_14 -> V_90 ) ;
return V_31 ;
}
static int F_149 ( struct V_14 * V_14 ,
struct V_123 * V_124 )
{
if ( ( V_137 ) V_124 -> V_132 >= V_141 )
return - V_129 ;
return F_147 ( V_14 , V_124 ) ;
}
int F_150 ( struct V_14 * V_14 ,
struct V_156 * log , int * V_157 )
{
struct V_62 * V_63 ;
struct V_67 * V_68 ;
int V_15 , V_130 , V_29 ;
unsigned long V_158 ;
unsigned long V_159 = 0 ;
V_130 = log -> V_132 >> 16 ;
V_29 = ( V_137 ) log -> V_132 ;
if ( V_130 >= V_96 || V_29 >= V_141 )
return - V_129 ;
V_63 = F_137 ( V_14 , V_130 ) ;
V_68 = F_142 ( V_63 , V_29 ) ;
if ( ! V_68 -> V_69 )
return - V_160 ;
V_158 = F_130 ( V_68 ) ;
for ( V_15 = 0 ; ! V_159 && V_15 < V_158 / sizeof( long ) ; ++ V_15 )
V_159 = V_68 -> V_69 [ V_15 ] ;
if ( F_151 ( log -> V_69 , V_68 -> V_69 , V_158 ) )
return - V_161 ;
if ( V_159 )
* V_157 = 1 ;
return 0 ;
}
int F_152 ( struct V_14 * V_14 ,
struct V_156 * log , bool * V_157 )
{
struct V_62 * V_63 ;
struct V_67 * V_68 ;
int V_15 , V_130 , V_29 ;
unsigned long V_158 ;
unsigned long * V_69 ;
unsigned long * V_162 ;
V_130 = log -> V_132 >> 16 ;
V_29 = ( V_137 ) log -> V_132 ;
if ( V_130 >= V_96 || V_29 >= V_141 )
return - V_129 ;
V_63 = F_137 ( V_14 , V_130 ) ;
V_68 = F_142 ( V_63 , V_29 ) ;
V_69 = V_68 -> V_69 ;
if ( ! V_69 )
return - V_160 ;
V_158 = F_130 ( V_68 ) ;
V_162 = V_69 + V_158 / sizeof( long ) ;
memset ( V_162 , 0 , V_158 ) ;
F_52 ( & V_14 -> V_52 ) ;
* V_157 = false ;
for ( V_15 = 0 ; V_15 < V_158 / sizeof( long ) ; V_15 ++ ) {
unsigned long V_163 ;
T_5 V_85 ;
if ( ! V_69 [ V_15 ] )
continue;
* V_157 = true ;
V_163 = F_153 ( & V_69 [ V_15 ] , 0 ) ;
V_162 [ V_15 ] = V_163 ;
if ( V_163 ) {
V_85 = V_15 * V_164 ;
F_154 ( V_14 , V_68 ,
V_85 , V_163 ) ;
}
}
F_54 ( & V_14 -> V_52 ) ;
if ( F_151 ( log -> V_69 , V_162 , V_158 ) )
return - V_161 ;
return 0 ;
}
bool F_155 ( void )
{
return V_165 ;
}
void F_156 ( void )
{
V_165 = false ;
}
struct V_67 * F_157 ( struct V_14 * V_14 , T_5 V_166 )
{
return F_158 ( V_62 ( V_14 ) , V_166 ) ;
}
struct V_67 * F_159 ( struct V_2 * V_3 , T_5 V_166 )
{
return F_158 ( F_160 ( V_3 ) , V_166 ) ;
}
bool F_161 ( struct V_14 * V_14 , T_5 V_166 )
{
struct V_67 * V_68 = F_157 ( V_14 , V_166 ) ;
if ( ! V_68 || V_68 -> V_29 >= V_141 ||
V_68 -> V_128 & V_153 )
return false ;
return true ;
}
unsigned long F_162 ( struct V_14 * V_14 , T_5 V_166 )
{
struct V_167 * V_168 ;
unsigned long V_169 , V_170 ;
V_170 = V_139 ;
V_169 = F_163 ( V_14 , V_166 ) ;
if ( F_164 ( V_169 ) )
return V_139 ;
F_165 ( & V_61 -> V_47 -> V_171 ) ;
V_168 = F_166 ( V_61 -> V_47 , V_169 ) ;
if ( ! V_168 )
goto V_136;
V_170 = F_167 ( V_168 ) ;
V_136:
F_168 ( & V_61 -> V_47 -> V_171 ) ;
return V_170 ;
}
static bool F_169 ( struct V_67 * V_132 )
{
return V_132 -> V_128 & V_127 ;
}
static unsigned long F_170 ( struct V_67 * V_132 , T_5 V_166 ,
T_5 * V_172 , bool V_173 )
{
if ( ! V_132 || V_132 -> V_128 & V_153 )
return V_174 ;
if ( F_169 ( V_132 ) && V_173 )
return V_175 ;
if ( V_172 )
* V_172 = V_132 -> V_71 - ( V_166 - V_132 -> V_122 ) ;
return F_171 ( V_132 , V_166 ) ;
}
static unsigned long F_172 ( struct V_67 * V_132 , T_5 V_166 ,
T_5 * V_172 )
{
return F_170 ( V_132 , V_166 , V_172 , true ) ;
}
unsigned long F_173 ( struct V_67 * V_132 ,
T_5 V_166 )
{
return F_172 ( V_132 , V_166 , NULL ) ;
}
unsigned long F_163 ( struct V_14 * V_14 , T_5 V_166 )
{
return F_172 ( F_157 ( V_14 , V_166 ) , V_166 , NULL ) ;
}
unsigned long F_174 ( struct V_2 * V_3 , T_5 V_166 )
{
return F_172 ( F_159 ( V_3 , V_166 ) , V_166 , NULL ) ;
}
unsigned long F_175 ( struct V_67 * V_132 ,
T_5 V_166 , bool * V_176 )
{
unsigned long V_177 = F_170 ( V_132 , V_166 , NULL , false ) ;
if ( ! F_164 ( V_177 ) && V_176 )
* V_176 = ! F_169 ( V_132 ) ;
return V_177 ;
}
unsigned long F_176 ( struct V_14 * V_14 , T_5 V_166 , bool * V_176 )
{
struct V_67 * V_132 = F_157 ( V_14 , V_166 ) ;
return F_175 ( V_132 , V_166 , V_176 ) ;
}
unsigned long F_177 ( struct V_2 * V_3 , T_5 V_166 , bool * V_176 )
{
struct V_67 * V_132 = F_159 ( V_3 , V_166 ) ;
return F_175 ( V_132 , V_166 , V_176 ) ;
}
static int F_178 ( unsigned long V_55 , int V_173 ,
struct V_30 * * V_30 )
{
int V_128 = V_178 | V_179 ;
if ( V_173 )
V_128 |= V_180 ;
return F_179 ( V_55 , 1 , V_128 , V_30 , NULL ) ;
}
static inline int F_180 ( unsigned long V_169 )
{
int V_181 , V_128 = V_179 | V_180 ;
V_181 = F_179 ( V_169 , 1 , V_128 , NULL , NULL ) ;
return V_181 == - V_182 ;
}
static bool F_181 ( unsigned long V_169 , bool V_183 , bool * V_184 ,
bool V_185 , bool * V_176 , T_1 * V_1 )
{
struct V_30 * V_30 [ 1 ] ;
int V_71 ;
if ( ! ( V_184 || V_183 ) )
return false ;
if ( ! ( V_185 || V_176 ) )
return false ;
V_71 = F_182 ( V_169 , 1 , 1 , V_30 ) ;
if ( V_71 == 1 ) {
* V_1 = F_183 ( V_30 [ 0 ] ) ;
if ( V_176 )
* V_176 = true ;
return true ;
}
return false ;
}
static int F_184 ( unsigned long V_169 , bool * V_184 , bool V_185 ,
bool * V_176 , T_1 * V_1 )
{
struct V_30 * V_30 [ 1 ] ;
int V_71 = 0 ;
F_185 () ;
if ( V_176 )
* V_176 = V_185 ;
if ( V_184 ) {
F_165 ( & V_61 -> V_47 -> V_171 ) ;
V_71 = F_178 ( V_169 , V_185 , V_30 ) ;
F_168 ( & V_61 -> V_47 -> V_171 ) ;
} else {
unsigned int V_128 = V_179 ;
if ( V_185 )
V_128 |= V_180 ;
V_71 = F_186 ( V_169 , 1 , V_30 , V_128 ) ;
}
if ( V_71 != 1 )
return V_71 ;
if ( F_26 ( ! V_185 ) && V_176 ) {
struct V_30 * V_186 [ 1 ] ;
V_71 = F_182 ( V_169 , 1 , 1 , V_186 ) ;
if ( V_71 == 1 ) {
* V_176 = true ;
F_187 ( V_30 [ 0 ] ) ;
V_30 [ 0 ] = V_186 [ 0 ] ;
}
V_71 = 1 ;
}
* V_1 = F_183 ( V_30 [ 0 ] ) ;
return V_71 ;
}
static bool F_188 ( struct V_167 * V_168 , bool V_185 )
{
if ( F_26 ( ! ( V_168 -> V_187 & V_188 ) ) )
return false ;
if ( V_185 && ( F_26 ( ! ( V_168 -> V_187 & V_189 ) ) ) )
return false ;
return true ;
}
static int F_189 ( struct V_167 * V_168 ,
unsigned long V_169 , bool * V_184 ,
bool V_185 , T_1 * V_190 )
{
unsigned long V_1 ;
int V_31 ;
V_31 = F_190 ( V_168 , V_169 , & V_1 ) ;
if ( V_31 ) {
bool V_191 = false ;
V_31 = F_191 ( V_61 , V_61 -> V_47 , V_169 ,
( V_185 ? V_192 : 0 ) ,
& V_191 ) ;
if ( V_191 )
return - V_193 ;
if ( V_31 )
return V_31 ;
V_31 = F_190 ( V_168 , V_169 , & V_1 ) ;
if ( V_31 )
return V_31 ;
}
F_192 ( V_1 ) ;
* V_190 = V_1 ;
return 0 ;
}
static T_1 F_193 ( unsigned long V_169 , bool V_183 , bool * V_184 ,
bool V_185 , bool * V_176 )
{
struct V_167 * V_168 ;
T_1 V_1 = 0 ;
int V_71 , V_31 ;
F_63 ( V_183 && V_184 ) ;
if ( F_181 ( V_169 , V_183 , V_184 , V_185 , V_176 , & V_1 ) )
return V_1 ;
if ( V_183 )
return V_194 ;
V_71 = F_184 ( V_169 , V_184 , V_185 , V_176 , & V_1 ) ;
if ( V_71 == 1 )
return V_1 ;
F_165 ( & V_61 -> V_47 -> V_171 ) ;
if ( V_71 == - V_182 ||
( ! V_184 && F_180 ( V_169 ) ) ) {
V_1 = V_195 ;
goto exit;
}
V_196:
V_168 = F_194 ( V_61 -> V_47 , V_169 , V_169 + 1 ) ;
if ( V_168 == NULL )
V_1 = V_194 ;
else if ( V_168 -> V_187 & ( V_197 | V_198 ) ) {
V_31 = F_189 ( V_168 , V_169 , V_184 , V_185 , & V_1 ) ;
if ( V_31 == - V_193 )
goto V_196;
if ( V_31 < 0 )
V_1 = V_194 ;
} else {
if ( V_184 && F_188 ( V_168 , V_185 ) )
* V_184 = true ;
V_1 = V_194 ;
}
exit:
F_168 ( & V_61 -> V_47 -> V_171 ) ;
return V_1 ;
}
T_1 F_195 ( struct V_67 * V_132 , T_5 V_166 ,
bool V_183 , bool * V_184 , bool V_185 ,
bool * V_176 )
{
unsigned long V_169 = F_170 ( V_132 , V_166 , NULL , V_185 ) ;
if ( V_169 == V_175 ) {
if ( V_176 )
* V_176 = false ;
return V_199 ;
}
if ( F_164 ( V_169 ) ) {
if ( V_176 )
* V_176 = false ;
return V_200 ;
}
if ( V_176 && F_169 ( V_132 ) ) {
* V_176 = false ;
V_176 = NULL ;
}
return F_193 ( V_169 , V_183 , V_184 , V_185 ,
V_176 ) ;
}
T_1 F_196 ( struct V_14 * V_14 , T_5 V_166 , bool V_185 ,
bool * V_176 )
{
return F_195 ( F_157 ( V_14 , V_166 ) , V_166 , false , NULL ,
V_185 , V_176 ) ;
}
T_1 F_197 ( struct V_67 * V_132 , T_5 V_166 )
{
return F_195 ( V_132 , V_166 , false , NULL , true , NULL ) ;
}
T_1 F_198 ( struct V_67 * V_132 , T_5 V_166 )
{
return F_195 ( V_132 , V_166 , true , NULL , true , NULL ) ;
}
T_1 F_199 ( struct V_14 * V_14 , T_5 V_166 )
{
return F_198 ( F_157 ( V_14 , V_166 ) , V_166 ) ;
}
T_1 F_200 ( struct V_2 * V_3 , T_5 V_166 )
{
return F_198 ( F_159 ( V_3 , V_166 ) , V_166 ) ;
}
T_1 F_201 ( struct V_14 * V_14 , T_5 V_166 )
{
return F_197 ( F_157 ( V_14 , V_166 ) , V_166 ) ;
}
T_1 F_202 ( struct V_2 * V_3 , T_5 V_166 )
{
return F_197 ( F_159 ( V_3 , V_166 ) , V_166 ) ;
}
int F_203 ( struct V_67 * V_132 , T_5 V_166 ,
struct V_30 * * V_201 , int V_172 )
{
unsigned long V_169 ;
T_5 V_202 ;
V_169 = F_172 ( V_132 , V_166 , & V_202 ) ;
if ( F_164 ( V_169 ) )
return - 1 ;
if ( V_202 < V_172 )
return 0 ;
return F_182 ( V_169 , V_172 , 1 , V_201 ) ;
}
static struct V_30 * F_204 ( T_1 V_1 )
{
if ( F_205 ( V_1 ) )
return V_203 ;
if ( F_1 ( V_1 ) ) {
F_132 ( 1 ) ;
return V_203 ;
}
return F_4 ( V_1 ) ;
}
struct V_30 * F_206 ( struct V_14 * V_14 , T_5 V_166 )
{
T_1 V_1 ;
V_1 = F_201 ( V_14 , V_166 ) ;
return F_204 ( V_1 ) ;
}
struct V_30 * F_207 ( struct V_2 * V_3 , T_5 V_166 )
{
T_1 V_1 ;
V_1 = F_202 ( V_3 , V_166 ) ;
return F_204 ( V_1 ) ;
}
void F_208 ( struct V_30 * V_30 )
{
F_132 ( F_209 ( V_30 ) ) ;
F_210 ( F_183 ( V_30 ) ) ;
}
void F_210 ( T_1 V_1 )
{
if ( ! F_205 ( V_1 ) && ! F_1 ( V_1 ) )
F_187 ( F_4 ( V_1 ) ) ;
}
void F_211 ( struct V_30 * V_30 )
{
F_132 ( F_209 ( V_30 ) ) ;
F_212 ( F_183 ( V_30 ) ) ;
}
static void F_212 ( T_1 V_1 )
{
F_213 ( V_1 ) ;
F_210 ( V_1 ) ;
}
void F_213 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_30 * V_30 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_30 ) )
F_214 ( V_30 ) ;
}
}
void F_215 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_216 ( F_4 ( V_1 ) ) ;
}
void F_192 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_217 ( F_4 ( V_1 ) ) ;
}
static int F_218 ( unsigned long V_204 , int V_85 )
{
if ( V_204 > V_139 - V_85 )
return V_139 - V_85 ;
else
return V_204 ;
}
static int F_219 ( struct V_67 * V_132 , T_5 V_166 ,
void * V_205 , int V_85 , int V_204 )
{
int V_31 ;
unsigned long V_169 ;
V_169 = F_175 ( V_132 , V_166 , NULL ) ;
if ( F_164 ( V_169 ) )
return - V_161 ;
V_31 = F_220 ( V_205 , ( void V_144 * ) V_169 + V_85 , V_204 ) ;
if ( V_31 )
return - V_161 ;
return 0 ;
}
int F_221 ( struct V_14 * V_14 , T_5 V_166 , void * V_205 , int V_85 ,
int V_204 )
{
struct V_67 * V_132 = F_157 ( V_14 , V_166 ) ;
return F_219 ( V_132 , V_166 , V_205 , V_85 , V_204 ) ;
}
int F_222 ( struct V_2 * V_3 , T_5 V_166 , void * V_205 ,
int V_85 , int V_204 )
{
struct V_67 * V_132 = F_159 ( V_3 , V_166 ) ;
return F_219 ( V_132 , V_166 , V_205 , V_85 , V_204 ) ;
}
int F_223 ( struct V_14 * V_14 , T_6 V_206 , void * V_205 , unsigned long V_204 )
{
T_5 V_166 = V_206 >> V_145 ;
int V_207 ;
int V_85 = F_224 ( V_206 ) ;
int V_208 ;
while ( ( V_207 = F_218 ( V_204 , V_85 ) ) != 0 ) {
V_208 = F_221 ( V_14 , V_166 , V_205 , V_85 , V_207 ) ;
if ( V_208 < 0 )
return V_208 ;
V_85 = 0 ;
V_204 -= V_207 ;
V_205 += V_207 ;
++ V_166 ;
}
return 0 ;
}
int F_225 ( struct V_2 * V_3 , T_6 V_206 , void * V_205 , unsigned long V_204 )
{
T_5 V_166 = V_206 >> V_145 ;
int V_207 ;
int V_85 = F_224 ( V_206 ) ;
int V_208 ;
while ( ( V_207 = F_218 ( V_204 , V_85 ) ) != 0 ) {
V_208 = F_222 ( V_3 , V_166 , V_205 , V_85 , V_207 ) ;
if ( V_208 < 0 )
return V_208 ;
V_85 = 0 ;
V_204 -= V_207 ;
V_205 += V_207 ;
++ V_166 ;
}
return 0 ;
}
static int F_226 ( struct V_67 * V_132 , T_5 V_166 ,
void * V_205 , int V_85 , unsigned long V_204 )
{
int V_31 ;
unsigned long V_169 ;
V_169 = F_175 ( V_132 , V_166 , NULL ) ;
if ( F_164 ( V_169 ) )
return - V_161 ;
F_227 () ;
V_31 = F_228 ( V_205 , ( void V_144 * ) V_169 + V_85 , V_204 ) ;
F_229 () ;
if ( V_31 )
return - V_161 ;
return 0 ;
}
int F_230 ( struct V_14 * V_14 , T_6 V_206 , void * V_205 ,
unsigned long V_204 )
{
T_5 V_166 = V_206 >> V_145 ;
struct V_67 * V_132 = F_157 ( V_14 , V_166 ) ;
int V_85 = F_224 ( V_206 ) ;
return F_226 ( V_132 , V_166 , V_205 , V_85 , V_204 ) ;
}
int F_231 ( struct V_2 * V_3 , T_6 V_206 ,
void * V_205 , unsigned long V_204 )
{
T_5 V_166 = V_206 >> V_145 ;
struct V_67 * V_132 = F_159 ( V_3 , V_166 ) ;
int V_85 = F_224 ( V_206 ) ;
return F_226 ( V_132 , V_166 , V_205 , V_85 , V_204 ) ;
}
static int F_232 ( struct V_67 * V_68 , T_5 V_166 ,
const void * V_205 , int V_85 , int V_204 )
{
int V_31 ;
unsigned long V_169 ;
V_169 = F_173 ( V_68 , V_166 ) ;
if ( F_164 ( V_169 ) )
return - V_161 ;
V_31 = F_233 ( ( void V_144 * ) V_169 + V_85 , V_205 , V_204 ) ;
if ( V_31 )
return - V_161 ;
F_234 ( V_68 , V_166 ) ;
return 0 ;
}
int F_235 ( struct V_14 * V_14 , T_5 V_166 ,
const void * V_205 , int V_85 , int V_204 )
{
struct V_67 * V_132 = F_157 ( V_14 , V_166 ) ;
return F_232 ( V_132 , V_166 , V_205 , V_85 , V_204 ) ;
}
int F_236 ( struct V_2 * V_3 , T_5 V_166 ,
const void * V_205 , int V_85 , int V_204 )
{
struct V_67 * V_132 = F_159 ( V_3 , V_166 ) ;
return F_232 ( V_132 , V_166 , V_205 , V_85 , V_204 ) ;
}
int F_237 ( struct V_14 * V_14 , T_6 V_206 , const void * V_205 ,
unsigned long V_204 )
{
T_5 V_166 = V_206 >> V_145 ;
int V_207 ;
int V_85 = F_224 ( V_206 ) ;
int V_208 ;
while ( ( V_207 = F_218 ( V_204 , V_85 ) ) != 0 ) {
V_208 = F_235 ( V_14 , V_166 , V_205 , V_85 , V_207 ) ;
if ( V_208 < 0 )
return V_208 ;
V_85 = 0 ;
V_204 -= V_207 ;
V_205 += V_207 ;
++ V_166 ;
}
return 0 ;
}
int F_238 ( struct V_2 * V_3 , T_6 V_206 , const void * V_205 ,
unsigned long V_204 )
{
T_5 V_166 = V_206 >> V_145 ;
int V_207 ;
int V_85 = F_224 ( V_206 ) ;
int V_208 ;
while ( ( V_207 = F_218 ( V_204 , V_85 ) ) != 0 ) {
V_208 = F_236 ( V_3 , V_166 , V_205 , V_85 , V_207 ) ;
if ( V_208 < 0 )
return V_208 ;
V_85 = 0 ;
V_204 -= V_207 ;
V_205 += V_207 ;
++ V_166 ;
}
return 0 ;
}
static int F_239 ( struct V_62 * V_63 ,
struct V_209 * V_210 ,
T_6 V_206 , unsigned long V_204 )
{
int V_85 = F_224 ( V_206 ) ;
T_5 V_211 = V_206 >> V_145 ;
T_5 V_212 = ( V_206 + V_204 - 1 ) >> V_145 ;
T_5 V_213 = V_212 - V_211 + 1 ;
T_5 V_214 ;
V_210 -> V_206 = V_206 ;
V_210 -> V_98 = V_63 -> V_98 ;
V_210 -> V_204 = V_204 ;
V_210 -> V_68 = F_158 ( V_63 , V_211 ) ;
V_210 -> V_177 = F_172 ( V_210 -> V_68 , V_211 , NULL ) ;
if ( ! F_164 ( V_210 -> V_177 ) && V_213 <= 1 ) {
V_210 -> V_177 += V_85 ;
} else {
while ( V_211 <= V_212 ) {
V_210 -> V_68 = F_158 ( V_63 , V_211 ) ;
V_210 -> V_177 = F_172 ( V_210 -> V_68 , V_211 ,
& V_214 ) ;
if ( F_164 ( V_210 -> V_177 ) )
return - V_161 ;
V_211 += V_214 ;
}
V_210 -> V_68 = NULL ;
}
return 0 ;
}
int F_240 ( struct V_14 * V_14 , struct V_209 * V_210 ,
T_6 V_206 , unsigned long V_204 )
{
struct V_62 * V_63 = V_62 ( V_14 ) ;
return F_239 ( V_63 , V_210 , V_206 , V_204 ) ;
}
int F_241 ( struct V_14 * V_14 , struct V_209 * V_210 ,
void * V_205 , int V_85 , unsigned long V_204 )
{
struct V_62 * V_63 = V_62 ( V_14 ) ;
int V_31 ;
T_6 V_206 = V_210 -> V_206 + V_85 ;
F_63 ( V_204 + V_85 > V_210 -> V_204 ) ;
if ( V_63 -> V_98 != V_210 -> V_98 )
F_239 ( V_63 , V_210 , V_210 -> V_206 , V_210 -> V_204 ) ;
if ( F_26 ( ! V_210 -> V_68 ) )
return F_237 ( V_14 , V_206 , V_205 , V_204 ) ;
if ( F_164 ( V_210 -> V_177 ) )
return - V_161 ;
V_31 = F_233 ( ( void V_144 * ) V_210 -> V_177 + V_85 , V_205 , V_204 ) ;
if ( V_31 )
return - V_161 ;
F_234 ( V_210 -> V_68 , V_206 >> V_145 ) ;
return 0 ;
}
int F_242 ( struct V_14 * V_14 , struct V_209 * V_210 ,
void * V_205 , unsigned long V_204 )
{
return F_241 ( V_14 , V_210 , V_205 , 0 , V_204 ) ;
}
int F_243 ( struct V_14 * V_14 , struct V_209 * V_210 ,
void * V_205 , unsigned long V_204 )
{
struct V_62 * V_63 = V_62 ( V_14 ) ;
int V_31 ;
F_63 ( V_204 > V_210 -> V_204 ) ;
if ( V_63 -> V_98 != V_210 -> V_98 )
F_239 ( V_63 , V_210 , V_210 -> V_206 , V_210 -> V_204 ) ;
if ( F_26 ( ! V_210 -> V_68 ) )
return F_223 ( V_14 , V_210 -> V_206 , V_205 , V_204 ) ;
if ( F_164 ( V_210 -> V_177 ) )
return - V_161 ;
V_31 = F_220 ( V_205 , ( void V_144 * ) V_210 -> V_177 , V_204 ) ;
if ( V_31 )
return - V_161 ;
return 0 ;
}
int F_244 ( struct V_14 * V_14 , T_5 V_166 , int V_85 , int V_204 )
{
const void * V_215 = ( const void * ) F_245 ( F_246 ( F_247 ( 0 ) ) ) ;
return F_235 ( V_14 , V_166 , V_215 , V_85 , V_204 ) ;
}
int F_248 ( struct V_14 * V_14 , T_6 V_206 , unsigned long V_204 )
{
T_5 V_166 = V_206 >> V_145 ;
int V_207 ;
int V_85 = F_224 ( V_206 ) ;
int V_208 ;
while ( ( V_207 = F_218 ( V_204 , V_85 ) ) != 0 ) {
V_208 = F_244 ( V_14 , V_166 , V_85 , V_207 ) ;
if ( V_208 < 0 )
return V_208 ;
V_85 = 0 ;
V_204 -= V_207 ;
++ V_166 ;
}
return 0 ;
}
static void F_234 ( struct V_67 * V_68 ,
T_5 V_166 )
{
if ( V_68 && V_68 -> V_69 ) {
unsigned long V_216 = V_166 - V_68 -> V_122 ;
F_249 ( V_216 , V_68 -> V_69 ) ;
}
}
void F_250 ( struct V_14 * V_14 , T_5 V_166 )
{
struct V_67 * V_68 ;
V_68 = F_157 ( V_14 , V_166 ) ;
F_234 ( V_68 , V_166 ) ;
}
void F_251 ( struct V_2 * V_3 , T_5 V_166 )
{
struct V_67 * V_68 ;
V_68 = F_159 ( V_3 , V_166 ) ;
F_234 ( V_68 , V_166 ) ;
}
static void F_252 ( struct V_2 * V_3 )
{
unsigned int V_133 , V_217 , V_218 ;
V_133 = V_217 = V_3 -> V_219 ;
V_218 = F_253 ( V_220 ) ;
if ( V_217 == 0 && V_218 )
V_217 = 10000 ;
else
V_217 *= V_218 ;
if ( V_217 > V_219 )
V_217 = V_219 ;
V_3 -> V_219 = V_217 ;
F_254 ( V_3 -> V_32 , V_217 , V_133 ) ;
}
static void F_255 ( struct V_2 * V_3 )
{
unsigned int V_133 , V_217 , V_221 ;
V_133 = V_217 = V_3 -> V_219 ;
V_221 = F_253 ( V_222 ) ;
if ( V_221 == 0 )
V_217 = 0 ;
else
V_217 /= V_221 ;
V_3 -> V_219 = V_217 ;
F_256 ( V_3 -> V_32 , V_217 , V_133 ) ;
}
static int F_257 ( struct V_2 * V_3 )
{
if ( F_258 ( V_3 ) ) {
F_23 ( V_223 , V_3 ) ;
return - V_6 ;
}
if ( F_259 ( V_3 ) )
return - V_6 ;
if ( F_260 ( V_61 ) )
return - V_6 ;
return 0 ;
}
void F_261 ( struct V_2 * V_3 )
{
T_7 V_55 , V_224 ;
F_262 ( V_19 ) ;
bool V_225 = false ;
T_8 V_226 ;
V_55 = V_224 = F_263 () ;
if ( V_3 -> V_219 ) {
T_7 V_227 = F_264 ( F_263 () , V_3 -> V_219 ) ;
++ V_3 -> V_26 . V_228 ;
do {
if ( F_257 ( V_3 ) < 0 ) {
++ V_3 -> V_26 . V_229 ;
if ( ! F_265 ( V_3 ) )
++ V_3 -> V_26 . V_230 ;
goto V_136;
}
V_224 = F_263 () ;
} while ( F_266 () && F_267 ( V_224 , V_227 ) );
}
F_268 ( V_3 ) ;
for (; ; ) {
F_269 ( & V_3 -> V_34 , & V_19 , V_231 ) ;
if ( F_257 ( V_3 ) < 0 )
break;
V_225 = true ;
F_270 () ;
}
F_271 ( & V_3 -> V_34 , & V_19 ) ;
V_224 = F_263 () ;
F_272 ( V_3 ) ;
V_136:
V_226 = F_273 ( V_224 ) - F_273 ( V_55 ) ;
if ( ! F_265 ( V_3 ) )
F_255 ( V_3 ) ;
else if ( V_219 ) {
if ( V_226 <= V_3 -> V_219 )
;
else if ( V_3 -> V_219 && V_226 > V_219 )
F_255 ( V_3 ) ;
else if ( V_3 -> V_219 < V_219 &&
V_226 < V_219 )
F_252 ( V_3 ) ;
} else
V_3 -> V_219 = 0 ;
F_274 ( V_226 , V_225 , F_265 ( V_3 ) ) ;
F_275 ( V_3 ) ;
}
bool F_24 ( struct V_2 * V_3 )
{
struct V_232 * V_233 ;
V_233 = F_276 ( V_3 ) ;
if ( F_277 ( V_233 ) ) {
F_278 ( V_233 ) ;
++ V_3 -> V_26 . V_234 ;
return true ;
}
return false ;
}
void F_279 ( struct V_2 * V_3 )
{
int V_16 ;
int V_4 = V_3 -> V_4 ;
if ( F_24 ( V_3 ) )
return;
V_16 = F_7 () ;
if ( V_4 != V_16 && ( unsigned ) V_4 < V_235 && F_280 ( V_4 ) )
if ( F_281 ( V_3 ) )
F_282 ( V_4 ) ;
F_10 () ;
}
int F_283 ( struct V_2 * V_236 )
{
struct V_33 * V_33 ;
struct V_237 * V_238 = NULL ;
int V_208 = 0 ;
F_284 () ;
V_33 = F_285 ( V_236 -> V_33 ) ;
if ( V_33 )
V_238 = F_286 ( V_33 , V_239 ) ;
F_287 () ;
if ( ! V_238 )
return V_208 ;
V_208 = F_288 ( V_238 , 1 ) ;
F_289 ( V_238 ) ;
return V_208 ;
}
static bool F_290 ( struct V_2 * V_3 )
{
#ifdef F_291
bool V_240 ;
V_240 = ! V_3 -> V_241 . V_242 ||
V_3 -> V_241 . V_243 ;
if ( V_3 -> V_241 . V_242 )
F_42 ( V_3 , ! V_3 -> V_241 . V_243 ) ;
return V_240 ;
#else
return true ;
#endif
}
void F_292 ( struct V_2 * V_16 )
{
struct V_14 * V_14 = V_16 -> V_14 ;
struct V_2 * V_3 ;
int V_244 = V_16 -> V_14 -> V_244 ;
int V_245 = 0 ;
int V_246 = 3 ;
int V_247 ;
int V_15 ;
F_41 ( V_16 , true ) ;
for ( V_247 = 0 ; V_247 < 2 && ! V_245 && V_246 ; V_247 ++ ) {
F_22 (i, vcpu, kvm) {
if ( ! V_247 && V_15 <= V_244 ) {
V_15 = V_244 ;
continue;
} else if ( V_247 && V_15 > V_244 )
break;
if ( ! F_293 ( V_3 -> V_42 ) )
continue;
if ( V_3 == V_16 )
continue;
if ( F_277 ( & V_3 -> V_34 ) && ! F_258 ( V_3 ) )
continue;
if ( ! F_290 ( V_3 ) )
continue;
V_245 = F_283 ( V_3 ) ;
if ( V_245 > 0 ) {
V_14 -> V_244 = V_15 ;
break;
} else if ( V_245 < 0 ) {
V_246 -- ;
if ( ! V_246 )
break;
}
}
}
F_41 ( V_16 , false ) ;
F_42 ( V_16 , false ) ;
}
static int F_294 ( struct V_248 * V_249 )
{
struct V_2 * V_3 = V_249 -> V_168 -> V_250 -> V_117 ;
struct V_30 * V_30 ;
if ( V_249 -> V_251 == 0 )
V_30 = F_295 ( V_3 -> V_41 ) ;
#ifdef F_296
else if ( V_249 -> V_251 == V_252 )
V_30 = F_295 ( V_3 -> V_155 . V_253 ) ;
#endif
#ifdef F_297
else if ( V_249 -> V_251 == V_254 )
V_30 = F_295 ( V_3 -> V_14 -> V_255 ) ;
#endif
else
return F_298 ( V_3 , V_249 ) ;
F_217 ( V_30 ) ;
V_249 -> V_30 = V_30 ;
return 0 ;
}
static int F_299 ( struct V_115 * V_115 , struct V_167 * V_168 )
{
V_168 -> V_256 = & V_257 ;
return 0 ;
}
static int F_300 ( struct V_114 * V_114 , struct V_115 * V_116 )
{
struct V_2 * V_3 = V_116 -> V_117 ;
F_82 ( V_3 -> V_72 ) ;
F_125 ( V_3 -> V_14 ) ;
return 0 ;
}
static int F_301 ( struct V_2 * V_3 )
{
return F_302 ( L_2 , & V_258 , V_3 , V_259 | V_260 ) ;
}
static int F_303 ( struct V_2 * V_3 )
{
char V_76 [ V_77 * 2 ] ;
int V_208 ;
if ( ! F_304 () )
return 0 ;
if ( ! F_85 () )
return 0 ;
snprintf ( V_76 , sizeof( V_76 ) , L_3 , V_3 -> V_32 ) ;
V_3 -> V_72 = F_87 ( V_76 ,
V_3 -> V_14 -> V_72 ) ;
if ( ! V_3 -> V_72 )
return - V_39 ;
V_208 = F_305 ( V_3 ) ;
if ( V_208 < 0 ) {
F_82 ( V_3 -> V_72 ) ;
return V_208 ;
}
return 0 ;
}
static int F_306 ( struct V_14 * V_14 , T_4 V_29 )
{
int V_31 ;
struct V_2 * V_3 ;
if ( V_29 >= V_261 )
return - V_129 ;
F_148 ( & V_14 -> V_88 ) ;
if ( V_14 -> V_262 == V_263 ) {
F_16 ( & V_14 -> V_88 ) ;
return - V_129 ;
}
V_14 -> V_262 ++ ;
F_16 ( & V_14 -> V_88 ) ;
V_3 = F_307 ( V_14 , V_29 ) ;
if ( F_308 ( V_3 ) ) {
V_31 = F_309 ( V_3 ) ;
goto V_264;
}
F_310 ( & V_3 -> V_7 , & V_265 ) ;
V_31 = F_311 ( V_3 ) ;
if ( V_31 )
goto V_266;
V_31 = F_303 ( V_3 ) ;
if ( V_31 )
goto V_266;
F_148 ( & V_14 -> V_88 ) ;
if ( F_312 ( V_14 , V_29 ) ) {
V_31 = - V_151 ;
goto V_267;
}
F_63 ( V_14 -> V_268 [ F_313 ( & V_14 -> V_269 ) ] ) ;
F_123 ( V_14 ) ;
V_31 = F_301 ( V_3 ) ;
if ( V_31 < 0 ) {
F_125 ( V_14 ) ;
goto V_267;
}
V_14 -> V_268 [ F_313 ( & V_14 -> V_269 ) ] = V_3 ;
F_62 () ;
F_314 ( & V_14 -> V_269 ) ;
F_16 ( & V_14 -> V_88 ) ;
F_315 ( V_3 ) ;
return V_31 ;
V_267:
F_16 ( & V_14 -> V_88 ) ;
F_82 ( V_3 -> V_72 ) ;
V_266:
F_316 ( V_3 ) ;
V_264:
F_148 ( & V_14 -> V_88 ) ;
V_14 -> V_262 -- ;
F_16 ( & V_14 -> V_88 ) ;
return V_31 ;
}
static int F_317 ( struct V_2 * V_3 , T_9 * V_270 )
{
if ( V_270 ) {
F_318 ( V_270 , F_319 ( V_271 ) | F_319 ( V_272 ) ) ;
V_3 -> V_273 = 1 ;
V_3 -> V_270 = * V_270 ;
} else
V_3 -> V_273 = 0 ;
return 0 ;
}
static long F_320 ( struct V_115 * V_116 ,
unsigned int V_274 , unsigned long V_275 )
{
struct V_2 * V_3 = V_116 -> V_117 ;
void V_144 * V_276 = ( void V_144 * ) V_275 ;
int V_31 ;
struct V_277 * V_278 = NULL ;
struct V_279 * V_279 = NULL ;
if ( V_3 -> V_14 -> V_47 != V_61 -> V_47 )
return - V_280 ;
if ( F_26 ( F_321 ( V_274 ) != V_281 ) )
return - V_129 ;
#if F_119 ( V_282 ) || F_119 ( V_283 ) || F_119 ( V_284 )
if ( V_274 == V_285 || V_274 == V_286 || V_274 == V_287 )
return F_322 ( V_116 , V_274 , V_275 ) ;
#endif
V_31 = F_5 ( V_3 ) ;
if ( V_31 )
return V_31 ;
switch ( V_274 ) {
case V_288 :
V_31 = - V_129 ;
if ( V_275 )
goto V_136;
if ( F_26 ( V_3 -> V_33 != V_61 -> V_289 [ V_239 ] . V_33 ) ) {
struct V_33 * V_290 = V_3 -> V_33 ;
struct V_33 * V_291 = F_323 ( V_61 , V_239 ) ;
F_103 ( V_3 -> V_33 , V_291 ) ;
if ( V_290 )
F_324 () ;
F_46 ( V_290 ) ;
}
V_31 = F_325 ( V_3 , V_3 -> V_41 ) ;
F_326 ( V_3 -> V_41 -> V_292 , V_31 ) ;
break;
case V_293 : {
struct V_294 * V_294 ;
V_31 = - V_39 ;
V_294 = F_89 ( sizeof( struct V_294 ) , V_37 ) ;
if ( ! V_294 )
goto V_136;
V_31 = F_327 ( V_3 , V_294 ) ;
if ( V_31 )
goto V_295;
V_31 = - V_161 ;
if ( F_151 ( V_276 , V_294 , sizeof( struct V_294 ) ) )
goto V_295;
V_31 = 0 ;
V_295:
F_83 ( V_294 ) ;
break;
}
case V_296 : {
struct V_294 * V_294 ;
V_31 = - V_39 ;
V_294 = F_328 ( V_276 , sizeof( * V_294 ) ) ;
if ( F_308 ( V_294 ) ) {
V_31 = F_309 ( V_294 ) ;
goto V_136;
}
V_31 = F_329 ( V_3 , V_294 ) ;
F_83 ( V_294 ) ;
break;
}
case V_297 : {
V_279 = F_89 ( sizeof( struct V_279 ) , V_37 ) ;
V_31 = - V_39 ;
if ( ! V_279 )
goto V_136;
V_31 = F_330 ( V_3 , V_279 ) ;
if ( V_31 )
goto V_136;
V_31 = - V_161 ;
if ( F_151 ( V_276 , V_279 , sizeof( struct V_279 ) ) )
goto V_136;
V_31 = 0 ;
break;
}
case V_298 : {
V_279 = F_328 ( V_276 , sizeof( * V_279 ) ) ;
if ( F_308 ( V_279 ) ) {
V_31 = F_309 ( V_279 ) ;
V_279 = NULL ;
goto V_136;
}
V_31 = F_331 ( V_3 , V_279 ) ;
break;
}
case V_299 : {
struct V_300 V_301 ;
V_31 = F_332 ( V_3 , & V_301 ) ;
if ( V_31 )
goto V_136;
V_31 = - V_161 ;
if ( F_151 ( V_276 , & V_301 , sizeof( V_301 ) ) )
goto V_136;
V_31 = 0 ;
break;
}
case V_302 : {
struct V_300 V_301 ;
V_31 = - V_161 ;
if ( F_333 ( & V_301 , V_276 , sizeof( V_301 ) ) )
goto V_136;
V_31 = F_334 ( V_3 , & V_301 ) ;
break;
}
case V_303 : {
struct V_304 V_305 ;
V_31 = - V_161 ;
if ( F_333 ( & V_305 , V_276 , sizeof( V_305 ) ) )
goto V_136;
V_31 = F_335 ( V_3 , & V_305 ) ;
if ( V_31 )
goto V_136;
V_31 = - V_161 ;
if ( F_151 ( V_276 , & V_305 , sizeof( V_305 ) ) )
goto V_136;
V_31 = 0 ;
break;
}
case V_306 : {
struct V_307 V_308 ;
V_31 = - V_161 ;
if ( F_333 ( & V_308 , V_276 , sizeof( V_308 ) ) )
goto V_136;
V_31 = F_336 ( V_3 , & V_308 ) ;
break;
}
case V_309 : {
struct V_310 V_144 * V_311 = V_276 ;
struct V_310 V_312 ;
T_9 V_270 , * V_81 ;
V_81 = NULL ;
if ( V_276 ) {
V_31 = - V_161 ;
if ( F_333 ( & V_312 , V_276 ,
sizeof( V_312 ) ) )
goto V_136;
V_31 = - V_129 ;
if ( V_312 . V_204 != sizeof( V_270 ) )
goto V_136;
V_31 = - V_161 ;
if ( F_333 ( & V_270 , V_311 -> V_270 ,
sizeof( V_270 ) ) )
goto V_136;
V_81 = & V_270 ;
}
V_31 = F_317 ( V_3 , V_81 ) ;
break;
}
case V_313 : {
V_278 = F_89 ( sizeof( struct V_277 ) , V_37 ) ;
V_31 = - V_39 ;
if ( ! V_278 )
goto V_136;
V_31 = F_337 ( V_3 , V_278 ) ;
if ( V_31 )
goto V_136;
V_31 = - V_161 ;
if ( F_151 ( V_276 , V_278 , sizeof( struct V_277 ) ) )
goto V_136;
V_31 = 0 ;
break;
}
case V_314 : {
V_278 = F_328 ( V_276 , sizeof( * V_278 ) ) ;
if ( F_308 ( V_278 ) ) {
V_31 = F_309 ( V_278 ) ;
V_278 = NULL ;
goto V_136;
}
V_31 = F_338 ( V_3 , V_278 ) ;
break;
}
default:
V_31 = F_322 ( V_116 , V_274 , V_275 ) ;
}
V_136:
F_11 ( V_3 ) ;
F_83 ( V_278 ) ;
F_83 ( V_279 ) ;
return V_31 ;
}
static long F_339 ( struct V_115 * V_116 ,
unsigned int V_274 , unsigned long V_275 )
{
struct V_2 * V_3 = V_116 -> V_117 ;
void V_144 * V_276 = F_340 ( V_275 ) ;
int V_31 ;
if ( V_3 -> V_14 -> V_47 != V_61 -> V_47 )
return - V_280 ;
switch ( V_274 ) {
case V_309 : {
struct V_310 V_144 * V_311 = V_276 ;
struct V_310 V_312 ;
T_10 V_315 ;
T_9 V_270 ;
if ( V_276 ) {
V_31 = - V_161 ;
if ( F_333 ( & V_312 , V_276 ,
sizeof( V_312 ) ) )
goto V_136;
V_31 = - V_129 ;
if ( V_312 . V_204 != sizeof( V_315 ) )
goto V_136;
V_31 = - V_161 ;
if ( F_333 ( & V_315 , V_311 -> V_270 ,
sizeof( V_315 ) ) )
goto V_136;
F_341 ( & V_270 , & V_315 ) ;
V_31 = F_317 ( V_3 , & V_270 ) ;
} else
V_31 = F_317 ( V_3 , NULL ) ;
break;
}
default:
V_31 = F_320 ( V_116 , V_274 , V_275 ) ;
}
V_136:
return V_31 ;
}
static int F_342 ( struct V_107 * V_108 ,
int (* F_343)( struct V_107 * V_108 ,
struct V_316 * V_317 ) ,
unsigned long V_275 )
{
struct V_316 V_317 ;
if ( ! F_343 )
return - V_318 ;
if ( F_333 ( & V_317 , ( void V_144 * ) V_275 , sizeof( V_317 ) ) )
return - V_161 ;
return F_343 ( V_108 , & V_317 ) ;
}
static long F_344 ( struct V_115 * V_116 , unsigned int V_274 ,
unsigned long V_275 )
{
struct V_107 * V_108 = V_116 -> V_117 ;
switch ( V_274 ) {
case V_319 :
return F_342 ( V_108 , V_108 -> V_59 -> V_320 , V_275 ) ;
case V_321 :
return F_342 ( V_108 , V_108 -> V_59 -> V_322 , V_275 ) ;
case V_323 :
return F_342 ( V_108 , V_108 -> V_59 -> V_324 , V_275 ) ;
default:
if ( V_108 -> V_59 -> V_274 )
return V_108 -> V_59 -> V_274 ( V_108 , V_274 , V_275 ) ;
return - V_325 ;
}
}
static int F_345 ( struct V_114 * V_114 , struct V_115 * V_116 )
{
struct V_107 * V_108 = V_116 -> V_117 ;
struct V_14 * V_14 = V_108 -> V_14 ;
F_125 ( V_14 ) ;
return 0 ;
}
struct V_107 * F_346 ( struct V_115 * V_116 )
{
if ( V_116 -> V_326 != & V_327 )
return NULL ;
return V_116 -> V_117 ;
}
int F_347 ( struct V_328 * V_59 , T_4 type )
{
if ( type >= F_348 ( V_329 ) )
return - V_330 ;
if ( V_329 [ type ] != NULL )
return - V_151 ;
V_329 [ type ] = V_59 ;
return 0 ;
}
void F_349 ( T_4 type )
{
if ( V_329 [ type ] != NULL )
V_329 [ type ] = NULL ;
}
static int F_350 ( struct V_14 * V_14 ,
struct V_331 * V_332 )
{
struct V_328 * V_59 = NULL ;
struct V_107 * V_108 ;
bool V_333 = V_332 -> V_128 & V_334 ;
int V_208 ;
if ( V_332 -> type >= F_348 ( V_329 ) )
return - V_335 ;
V_59 = V_329 [ V_332 -> type ] ;
if ( V_59 == NULL )
return - V_335 ;
if ( V_333 )
return 0 ;
V_108 = F_89 ( sizeof( * V_108 ) , V_37 ) ;
if ( ! V_108 )
return - V_39 ;
V_108 -> V_59 = V_59 ;
V_108 -> V_14 = V_14 ;
F_148 ( & V_14 -> V_88 ) ;
V_208 = V_59 -> V_336 ( V_108 , V_332 -> type ) ;
if ( V_208 < 0 ) {
F_16 ( & V_14 -> V_88 ) ;
F_83 ( V_108 ) ;
return V_208 ;
}
F_105 ( & V_108 -> V_110 , & V_14 -> V_92 ) ;
F_16 ( & V_14 -> V_88 ) ;
if ( V_59 -> V_337 )
V_59 -> V_337 ( V_108 ) ;
V_208 = F_302 ( V_59 -> V_84 , & V_327 , V_108 , V_259 | V_260 ) ;
if ( V_208 < 0 ) {
F_148 ( & V_14 -> V_88 ) ;
F_113 ( & V_108 -> V_110 ) ;
F_16 ( & V_14 -> V_88 ) ;
V_59 -> V_111 ( V_108 ) ;
return V_208 ;
}
F_123 ( V_14 ) ;
V_332 -> V_75 = V_208 ;
return 0 ;
}
static long F_351 ( struct V_14 * V_14 , long V_275 )
{
switch ( V_275 ) {
case V_338 :
case V_339 :
case V_340 :
case V_341 :
#ifdef F_352
case V_342 :
#endif
#ifdef F_100
case V_343 :
case V_344 :
#endif
case V_345 :
case V_346 :
return 1 ;
#ifdef F_297
case V_347 :
return V_254 ;
#endif
#ifdef F_353
case V_348 :
return V_349 ;
#endif
#if V_96 > 1
case V_350 :
return V_96 ;
#endif
case V_351 :
return V_261 ;
default:
break;
}
return F_354 ( V_14 , V_275 ) ;
}
static long F_355 ( struct V_115 * V_116 ,
unsigned int V_274 , unsigned long V_275 )
{
struct V_14 * V_14 = V_116 -> V_117 ;
void V_144 * V_276 = ( void V_144 * ) V_275 ;
int V_31 ;
if ( V_14 -> V_47 != V_61 -> V_47 )
return - V_280 ;
switch ( V_274 ) {
case V_352 :
V_31 = F_306 ( V_14 , V_275 ) ;
break;
case V_353 : {
struct V_123 V_354 ;
V_31 = - V_161 ;
if ( F_333 ( & V_354 , V_276 ,
sizeof( V_354 ) ) )
goto V_136;
V_31 = F_149 ( V_14 , & V_354 ) ;
break;
}
case V_355 : {
struct V_156 log ;
V_31 = - V_161 ;
if ( F_333 ( & log , V_276 , sizeof( log ) ) )
goto V_136;
V_31 = F_356 ( V_14 , & log ) ;
break;
}
#ifdef F_297
case V_356 : {
struct V_357 V_358 ;
V_31 = - V_161 ;
if ( F_333 ( & V_358 , V_276 , sizeof( V_358 ) ) )
goto V_136;
V_31 = F_357 ( V_14 , & V_358 ) ;
break;
}
case V_359 : {
struct V_357 V_358 ;
V_31 = - V_161 ;
if ( F_333 ( & V_358 , V_276 , sizeof( V_358 ) ) )
goto V_136;
V_31 = F_358 ( V_14 , & V_358 ) ;
break;
}
#endif
case V_360 : {
struct V_361 V_205 ;
V_31 = - V_161 ;
if ( F_333 ( & V_205 , V_276 , sizeof( V_205 ) ) )
goto V_136;
V_31 = V_361 ( V_14 , & V_205 ) ;
break;
}
case V_362 : {
struct V_363 V_205 ;
V_31 = - V_161 ;
if ( F_333 ( & V_205 , V_276 , sizeof( V_205 ) ) )
goto V_136;
V_31 = V_363 ( V_14 , & V_205 ) ;
break;
}
#ifdef F_352
case V_364 : {
struct V_365 V_366 ;
V_31 = - V_161 ;
if ( F_333 ( & V_366 , V_276 , sizeof( V_366 ) ) )
goto V_136;
V_31 = F_359 ( V_14 , & V_366 ) ;
break;
}
#endif
#ifdef F_360
case V_367 :
case V_368 : {
struct V_369 V_370 ;
V_31 = - V_161 ;
if ( F_333 ( & V_370 , V_276 , sizeof( V_370 ) ) )
goto V_136;
V_31 = F_361 ( V_14 , & V_370 ,
V_274 == V_367 ) ;
if ( V_31 )
goto V_136;
V_31 = - V_161 ;
if ( V_274 == V_367 ) {
if ( F_151 ( V_276 , & V_370 , sizeof( V_370 ) ) )
goto V_136;
}
V_31 = 0 ;
break;
}
#endif
#ifdef F_353
case V_371 : {
struct V_372 V_373 ;
struct V_372 V_144 * V_374 ;
struct V_375 * V_376 = NULL ;
V_31 = - V_161 ;
if ( F_333 ( & V_373 , V_276 , sizeof( V_373 ) ) )
goto V_136;
V_31 = - V_129 ;
if ( ! F_362 ( V_14 ) )
goto V_136;
if ( V_373 . V_377 > V_349 )
goto V_136;
if ( V_373 . V_128 )
goto V_136;
if ( V_373 . V_377 ) {
V_31 = - V_39 ;
V_376 = F_363 ( V_373 . V_377 * sizeof( * V_376 ) ) ;
if ( ! V_376 )
goto V_136;
V_31 = - V_161 ;
V_374 = V_276 ;
if ( F_333 ( V_376 , V_374 -> V_376 ,
V_373 . V_377 * sizeof( * V_376 ) ) )
goto V_378;
}
V_31 = F_364 ( V_14 , V_376 , V_373 . V_377 ,
V_373 . V_128 ) ;
V_378:
F_365 ( V_376 ) ;
break;
}
#endif
case V_379 : {
struct V_331 V_332 ;
V_31 = - V_161 ;
if ( F_333 ( & V_332 , V_276 , sizeof( V_332 ) ) )
goto V_136;
V_31 = F_350 ( V_14 , & V_332 ) ;
if ( V_31 )
goto V_136;
V_31 = - V_161 ;
if ( F_151 ( V_276 , & V_332 , sizeof( V_332 ) ) )
goto V_136;
V_31 = 0 ;
break;
}
case V_380 :
V_31 = F_351 ( V_14 , V_275 ) ;
break;
default:
V_31 = F_366 ( V_116 , V_274 , V_275 ) ;
}
V_136:
return V_31 ;
}
static long F_367 ( struct V_115 * V_116 ,
unsigned int V_274 , unsigned long V_275 )
{
struct V_14 * V_14 = V_116 -> V_117 ;
int V_31 ;
if ( V_14 -> V_47 != V_61 -> V_47 )
return - V_280 ;
switch ( V_274 ) {
case V_355 : {
struct V_381 V_382 ;
struct V_156 log ;
if ( F_333 ( & V_382 , ( void V_144 * ) V_275 ,
sizeof( V_382 ) ) )
return - V_161 ;
log . V_132 = V_382 . V_132 ;
log . V_383 = V_382 . V_383 ;
log . V_384 = V_382 . V_384 ;
log . V_69 = F_340 ( V_382 . V_69 ) ;
V_31 = F_356 ( V_14 , & log ) ;
break;
}
default:
V_31 = F_355 ( V_116 , V_274 , V_275 ) ;
}
return V_31 ;
}
static int F_368 ( unsigned long type )
{
int V_31 ;
struct V_14 * V_14 ;
struct V_115 * V_115 ;
V_14 = F_91 ( type ) ;
if ( F_308 ( V_14 ) )
return F_309 ( V_14 ) ;
#ifdef F_297
V_31 = F_369 ( V_14 ) ;
if ( V_31 < 0 ) {
F_125 ( V_14 ) ;
return V_31 ;
}
#endif
V_31 = F_370 ( V_260 ) ;
if ( V_31 < 0 ) {
F_125 ( V_14 ) ;
return V_31 ;
}
V_115 = F_371 ( L_4 , & V_385 , V_14 , V_259 ) ;
if ( F_308 ( V_115 ) ) {
F_372 ( V_31 ) ;
F_125 ( V_14 ) ;
return F_309 ( V_115 ) ;
}
if ( F_84 ( V_14 , V_31 ) < 0 ) {
F_372 ( V_31 ) ;
F_373 ( V_115 ) ;
return - V_39 ;
}
F_374 ( V_31 , V_115 ) ;
return V_31 ;
}
static long F_375 ( struct V_115 * V_116 ,
unsigned int V_274 , unsigned long V_275 )
{
long V_31 = - V_129 ;
switch ( V_274 ) {
case V_386 :
if ( V_275 )
goto V_136;
V_31 = V_387 ;
break;
case V_388 :
V_31 = F_368 ( V_275 ) ;
break;
case V_380 :
V_31 = F_351 ( NULL , V_275 ) ;
break;
case V_389 :
if ( V_275 )
goto V_136;
V_31 = V_139 ;
#ifdef F_296
V_31 += V_139 ;
#endif
#ifdef F_297
V_31 += V_139 ;
#endif
break;
case V_390 :
case V_391 :
case V_392 :
V_31 = - V_393 ;
break;
default:
return F_376 ( V_116 , V_274 , V_275 ) ;
}
V_136:
return V_31 ;
}
static void F_377 ( void * V_394 )
{
int V_4 = F_378 () ;
int V_31 ;
if ( F_379 ( V_4 , V_395 ) )
return;
F_25 ( V_4 , V_395 ) ;
V_31 = F_380 () ;
if ( V_31 ) {
F_381 ( V_4 , V_395 ) ;
F_314 ( & V_396 ) ;
F_382 ( L_5 , V_4 ) ;
}
}
static int F_383 ( unsigned int V_4 )
{
F_384 ( & V_397 ) ;
if ( V_398 )
F_377 ( NULL ) ;
F_385 ( & V_397 ) ;
return 0 ;
}
static void F_386 ( void * V_394 )
{
int V_4 = F_378 () ;
if ( ! F_379 ( V_4 , V_395 ) )
return;
F_381 ( V_4 , V_395 ) ;
F_387 () ;
}
static int F_388 ( unsigned int V_4 )
{
F_384 ( & V_397 ) ;
if ( V_398 )
F_386 ( NULL ) ;
F_385 ( & V_397 ) ;
return 0 ;
}
static void F_389 ( void )
{
F_63 ( ! V_398 ) ;
V_398 -- ;
if ( ! V_398 )
F_390 ( F_386 , NULL , 1 ) ;
}
static void F_108 ( void )
{
F_384 ( & V_397 ) ;
F_389 () ;
F_385 ( & V_397 ) ;
}
static int F_99 ( void )
{
int V_31 = 0 ;
F_384 ( & V_397 ) ;
V_398 ++ ;
if ( V_398 == 1 ) {
F_391 ( & V_396 , 0 ) ;
F_390 ( F_377 , NULL , 1 ) ;
if ( F_313 ( & V_396 ) ) {
F_389 () ;
V_31 = - V_399 ;
}
}
F_385 ( & V_397 ) ;
return V_31 ;
}
static int F_392 ( struct V_400 * V_401 , unsigned long V_217 ,
void * V_402 )
{
F_382 ( L_6 ) ;
V_403 = true ;
F_390 ( F_386 , NULL , 1 ) ;
return V_404 ;
}
static void F_117 ( struct V_103 * V_405 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_405 -> V_406 ; V_15 ++ ) {
struct V_407 * V_408 = V_405 -> V_409 [ V_15 ] . V_108 ;
F_393 ( V_408 ) ;
}
F_83 ( V_405 ) ;
}
static inline int F_394 ( const struct V_410 * V_411 ,
const struct V_410 * V_412 )
{
T_6 V_413 = V_411 -> V_169 ;
T_6 V_414 = V_412 -> V_169 ;
if ( V_413 < V_414 )
return - 1 ;
if ( V_412 -> V_204 ) {
V_413 += V_411 -> V_204 ;
V_414 += V_412 -> V_204 ;
}
if ( V_413 > V_414 )
return 1 ;
return 0 ;
}
static int F_395 ( const void * V_415 , const void * V_416 )
{
return F_394 ( V_415 , V_416 ) ;
}
static int F_396 ( struct V_103 * V_405 , struct V_407 * V_108 ,
T_6 V_169 , int V_204 )
{
V_405 -> V_409 [ V_405 -> V_406 ++ ] = (struct V_410 ) {
. V_169 = V_169 ,
. V_204 = V_204 ,
. V_108 = V_108 ,
} ;
F_397 ( V_405 -> V_409 , V_405 -> V_406 , sizeof( struct V_410 ) ,
F_395 , NULL ) ;
return 0 ;
}
static int F_398 ( struct V_103 * V_405 ,
T_6 V_169 , int V_204 )
{
struct V_410 * V_409 , V_417 ;
int V_418 ;
V_417 = (struct V_410 ) {
. V_169 = V_169 ,
. V_204 = V_204 ,
} ;
V_409 = bsearch ( & V_417 , V_405 -> V_409 , V_405 -> V_406 ,
sizeof( struct V_410 ) , F_395 ) ;
if ( V_409 == NULL )
return - V_160 ;
V_418 = V_409 - V_405 -> V_409 ;
while ( V_418 > 0 && F_394 ( & V_417 , & V_405 -> V_409 [ V_418 - 1 ] ) == 0 )
V_418 -- ;
return V_418 ;
}
static int F_399 ( struct V_2 * V_3 , struct V_103 * V_405 ,
struct V_410 * V_409 , const void * V_217 )
{
int V_50 ;
V_50 = F_398 ( V_405 , V_409 -> V_169 , V_409 -> V_204 ) ;
if ( V_50 < 0 )
return - V_393 ;
while ( V_50 < V_405 -> V_406 &&
F_394 ( V_409 , & V_405 -> V_409 [ V_50 ] ) == 0 ) {
if ( ! F_400 ( V_3 , V_405 -> V_409 [ V_50 ] . V_108 , V_409 -> V_169 ,
V_409 -> V_204 , V_217 ) )
return V_50 ;
V_50 ++ ;
}
return - V_393 ;
}
int F_401 ( struct V_2 * V_3 , enum V_419 V_420 , T_6 V_169 ,
int V_204 , const void * V_217 )
{
struct V_103 * V_405 ;
struct V_410 V_409 ;
int V_31 ;
V_409 = (struct V_410 ) {
. V_169 = V_169 ,
. V_204 = V_204 ,
} ;
V_405 = F_402 ( V_3 -> V_14 -> V_102 [ V_420 ] , & V_3 -> V_14 -> V_51 ) ;
if ( ! V_405 )
return - V_39 ;
V_31 = F_399 ( V_3 , V_405 , & V_409 , V_217 ) ;
return V_31 < 0 ? V_31 : 0 ;
}
int F_403 ( struct V_2 * V_3 , enum V_419 V_420 ,
T_6 V_169 , int V_204 , const void * V_217 , long V_421 )
{
struct V_103 * V_405 ;
struct V_410 V_409 ;
V_409 = (struct V_410 ) {
. V_169 = V_169 ,
. V_204 = V_204 ,
} ;
V_405 = F_402 ( V_3 -> V_14 -> V_102 [ V_420 ] , & V_3 -> V_14 -> V_51 ) ;
if ( ! V_405 )
return - V_39 ;
if ( ( V_421 >= 0 ) && ( V_421 < V_405 -> V_406 ) &&
( F_394 ( & V_409 , & V_405 -> V_409 [ V_421 ] ) == 0 ) )
if ( ! F_400 ( V_3 , V_405 -> V_409 [ V_421 ] . V_108 , V_169 , V_204 ,
V_217 ) )
return V_421 ;
return F_399 ( V_3 , V_405 , & V_409 , V_217 ) ;
}
static int F_404 ( struct V_2 * V_3 , struct V_103 * V_405 ,
struct V_410 * V_409 , void * V_217 )
{
int V_50 ;
V_50 = F_398 ( V_405 , V_409 -> V_169 , V_409 -> V_204 ) ;
if ( V_50 < 0 )
return - V_393 ;
while ( V_50 < V_405 -> V_406 &&
F_394 ( V_409 , & V_405 -> V_409 [ V_50 ] ) == 0 ) {
if ( ! F_405 ( V_3 , V_405 -> V_409 [ V_50 ] . V_108 , V_409 -> V_169 ,
V_409 -> V_204 , V_217 ) )
return V_50 ;
V_50 ++ ;
}
return - V_393 ;
}
int F_406 ( struct V_2 * V_3 , enum V_419 V_420 , T_6 V_169 ,
int V_204 , void * V_217 )
{
struct V_103 * V_405 ;
struct V_410 V_409 ;
int V_31 ;
V_409 = (struct V_410 ) {
. V_169 = V_169 ,
. V_204 = V_204 ,
} ;
V_405 = F_402 ( V_3 -> V_14 -> V_102 [ V_420 ] , & V_3 -> V_14 -> V_51 ) ;
if ( ! V_405 )
return - V_39 ;
V_31 = F_404 ( V_3 , V_405 , & V_409 , V_217 ) ;
return V_31 < 0 ? V_31 : 0 ;
}
int F_407 ( struct V_14 * V_14 , enum V_419 V_420 , T_6 V_169 ,
int V_204 , struct V_407 * V_108 )
{
struct V_103 * V_422 , * V_405 ;
V_405 = V_14 -> V_102 [ V_420 ] ;
if ( ! V_405 )
return - V_39 ;
if ( V_405 -> V_406 - V_405 -> V_423 > V_424 - 1 )
return - V_330 ;
V_422 = F_408 ( sizeof( * V_405 ) + ( ( V_405 -> V_406 + 1 ) *
sizeof( struct V_410 ) ) , V_37 ) ;
if ( ! V_422 )
return - V_39 ;
memcpy ( V_422 , V_405 , sizeof( * V_405 ) + ( V_405 -> V_406 *
sizeof( struct V_410 ) ) ) ;
F_396 ( V_422 , V_108 , V_169 , V_204 ) ;
F_103 ( V_14 -> V_102 [ V_420 ] , V_422 ) ;
F_138 ( & V_14 -> V_51 ) ;
F_83 ( V_405 ) ;
return 0 ;
}
void F_409 ( struct V_14 * V_14 , enum V_419 V_420 ,
struct V_407 * V_108 )
{
int V_15 ;
struct V_103 * V_422 , * V_405 ;
V_405 = V_14 -> V_102 [ V_420 ] ;
if ( ! V_405 )
return;
for ( V_15 = 0 ; V_15 < V_405 -> V_406 ; V_15 ++ )
if ( V_405 -> V_409 [ V_15 ] . V_108 == V_108 ) {
break;
}
if ( V_15 == V_405 -> V_406 )
return;
V_422 = F_408 ( sizeof( * V_405 ) + ( ( V_405 -> V_406 - 1 ) *
sizeof( struct V_410 ) ) , V_37 ) ;
if ( ! V_422 ) {
F_410 ( L_7 ) ;
goto V_425;
}
memcpy ( V_422 , V_405 , sizeof( * V_405 ) + V_15 * sizeof( struct V_410 ) ) ;
V_422 -> V_406 -- ;
memcpy ( V_422 -> V_409 + V_15 , V_405 -> V_409 + V_15 + 1 ,
( V_422 -> V_406 - V_15 ) * sizeof( struct V_410 ) ) ;
V_425:
F_103 ( V_14 -> V_102 [ V_420 ] , V_422 ) ;
F_138 ( & V_14 -> V_51 ) ;
F_83 ( V_405 ) ;
return;
}
struct V_407 * F_411 ( struct V_14 * V_14 , enum V_419 V_420 ,
T_6 V_169 )
{
struct V_103 * V_405 ;
int V_426 , V_427 ;
struct V_407 * V_428 = NULL ;
V_427 = F_51 ( & V_14 -> V_51 ) ;
V_405 = F_402 ( V_14 -> V_102 [ V_420 ] , & V_14 -> V_51 ) ;
if ( ! V_405 )
goto V_429;
V_426 = F_398 ( V_405 , V_169 , 1 ) ;
if ( V_426 < 0 )
goto V_429;
V_428 = V_405 -> V_409 [ V_426 ] . V_108 ;
V_429:
F_56 ( & V_14 -> V_51 , V_427 ) ;
return V_428 ;
}
static int F_412 ( struct V_114 * V_114 , struct V_115 * V_115 ,
int (* F_413)( void * , T_8 * ) , int (* F_414)( void * , T_8 ) ,
const char * V_430 )
{
struct V_78 * V_79 = (struct V_78 * )
V_114 -> V_431 ;
if ( ! F_415 ( & V_79 -> V_14 -> V_91 ) )
return - V_160 ;
if ( F_416 ( V_114 , V_115 , F_413 , F_414 , V_430 ) ) {
F_125 ( V_79 -> V_14 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_417 ( struct V_114 * V_114 , struct V_115 * V_115 )
{
struct V_78 * V_79 = (struct V_78 * )
V_114 -> V_431 ;
F_418 ( V_114 , V_115 ) ;
F_125 ( V_79 -> V_14 ) ;
return 0 ;
}
static int F_419 ( void * V_205 , T_8 * V_217 )
{
struct V_78 * V_79 = (struct V_78 * ) V_205 ;
* V_217 = * ( V_432 * ) ( ( void * ) V_79 -> V_14 + V_79 -> V_85 ) ;
return 0 ;
}
static int F_420 ( void * V_205 , T_8 V_217 )
{
struct V_78 * V_79 = (struct V_78 * ) V_205 ;
if ( V_217 )
return - V_129 ;
* ( V_432 * ) ( ( void * ) V_79 -> V_14 + V_79 -> V_85 ) = 0 ;
return 0 ;
}
static int F_421 ( struct V_114 * V_114 , struct V_115 * V_115 )
{
F_422 ( L_8 , 0ull ) ;
return F_412 ( V_114 , V_115 , F_419 ,
F_420 , L_8 ) ;
}
static int F_423 ( void * V_205 , T_8 * V_217 )
{
int V_15 ;
struct V_78 * V_79 = (struct V_78 * ) V_205 ;
struct V_2 * V_3 ;
* V_217 = 0 ;
F_22 ( V_15 , V_3 , V_79 -> V_14 )
* V_217 += * ( T_8 * ) ( ( void * ) V_3 + V_79 -> V_85 ) ;
return 0 ;
}
static int F_424 ( void * V_205 , T_8 V_217 )
{
int V_15 ;
struct V_78 * V_79 = (struct V_78 * ) V_205 ;
struct V_2 * V_3 ;
if ( V_217 )
return - V_129 ;
F_22 ( V_15 , V_3 , V_79 -> V_14 )
* ( T_8 * ) ( ( void * ) V_3 + V_79 -> V_85 ) = 0 ;
return 0 ;
}
static int F_425 ( struct V_114 * V_114 , struct V_115 * V_115 )
{
F_422 ( L_8 , 0ull ) ;
return F_412 ( V_114 , V_115 , F_423 ,
F_424 , L_8 ) ;
}
static int F_426 ( void * V_433 , T_8 * V_217 )
{
unsigned V_85 = ( long ) V_433 ;
struct V_14 * V_14 ;
struct V_78 V_434 = { . V_85 = V_85 } ;
T_8 V_435 ;
* V_217 = 0 ;
F_52 ( & V_105 ) ;
F_427 (kvm, &vm_list, vm_list) {
V_434 . V_14 = V_14 ;
F_419 ( ( void * ) & V_434 , & V_435 ) ;
* V_217 += V_435 ;
}
F_54 ( & V_105 ) ;
return 0 ;
}
static int F_428 ( void * V_433 , T_8 V_217 )
{
unsigned V_85 = ( long ) V_433 ;
struct V_14 * V_14 ;
struct V_78 V_434 = { . V_85 = V_85 } ;
if ( V_217 )
return - V_129 ;
F_52 ( & V_105 ) ;
F_427 (kvm, &vm_list, vm_list) {
V_434 . V_14 = V_14 ;
F_420 ( ( void * ) & V_434 , 0 ) ;
}
F_54 ( & V_105 ) ;
return 0 ;
}
static int F_429 ( void * V_433 , T_8 * V_217 )
{
unsigned V_85 = ( long ) V_433 ;
struct V_14 * V_14 ;
struct V_78 V_434 = { . V_85 = V_85 } ;
T_8 V_435 ;
* V_217 = 0 ;
F_52 ( & V_105 ) ;
F_427 (kvm, &vm_list, vm_list) {
V_434 . V_14 = V_14 ;
F_423 ( ( void * ) & V_434 , & V_435 ) ;
* V_217 += V_435 ;
}
F_54 ( & V_105 ) ;
return 0 ;
}
static int F_430 ( void * V_433 , T_8 V_217 )
{
unsigned V_85 = ( long ) V_433 ;
struct V_14 * V_14 ;
struct V_78 V_434 = { . V_85 = V_85 } ;
if ( V_217 )
return - V_129 ;
F_52 ( & V_105 ) ;
F_427 (kvm, &vm_list, vm_list) {
V_434 . V_14 = V_14 ;
F_424 ( ( void * ) & V_434 , 0 ) ;
}
F_54 ( & V_105 ) ;
return 0 ;
}
static int F_431 ( void )
{
int V_31 = - V_151 ;
struct V_80 * V_81 ;
V_82 = F_87 ( L_9 , NULL ) ;
if ( V_82 == NULL )
goto V_136;
V_74 = 0 ;
for ( V_81 = V_83 ; V_81 -> V_84 ; ++ V_81 , V_74 ++ ) {
if ( ! F_90 ( V_81 -> V_84 , 0644 , V_82 ,
( void * ) ( long ) V_81 -> V_85 ,
V_436 [ V_81 -> V_87 ] ) )
goto V_437;
}
return 0 ;
V_437:
F_82 ( V_82 ) ;
V_136:
return V_31 ;
}
static int F_432 ( void )
{
if ( V_398 )
F_386 ( NULL ) ;
return 0 ;
}
static void F_433 ( void )
{
if ( V_398 ) {
F_132 ( F_434 ( & V_397 ) ) ;
F_377 ( NULL ) ;
}
}
static inline
struct V_2 * F_435 ( struct V_7 * V_438 )
{
return F_49 ( V_438 , struct V_2 , V_7 ) ;
}
static void F_436 ( struct V_7 * V_438 , int V_4 )
{
struct V_2 * V_3 = F_435 ( V_438 ) ;
if ( V_3 -> V_42 )
V_3 -> V_42 = false ;
F_437 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_438 ( struct V_7 * V_438 ,
struct V_237 * V_439 )
{
struct V_2 * V_3 = F_435 ( V_438 ) ;
if ( V_61 -> V_440 == V_441 )
V_3 -> V_42 = true ;
F_13 ( V_3 ) ;
}
int F_439 ( void * V_442 , unsigned V_443 , unsigned V_444 ,
struct V_445 * V_445 )
{
int V_31 ;
int V_4 ;
V_31 = F_440 ( V_442 ) ;
if ( V_31 )
goto V_446;
V_31 = F_441 () ;
if ( V_31 )
goto V_447;
if ( ! F_21 ( & V_395 , V_37 ) ) {
V_31 = - V_39 ;
goto V_448;
}
V_31 = F_442 () ;
if ( V_31 < 0 )
goto V_449;
F_443 (cpu) {
F_444 ( V_4 ,
V_450 ,
& V_31 , 1 ) ;
if ( V_31 < 0 )
goto V_451;
}
V_31 = F_445 ( V_452 , L_10 ,
F_383 , F_388 ) ;
if ( V_31 )
goto V_453;
F_446 ( & V_454 ) ;
if ( ! V_444 )
V_444 = F_447 ( struct V_2 ) ;
V_455 = F_448 ( L_11 , V_443 , V_444 ,
0 , NULL ) ;
if ( ! V_455 ) {
V_31 = - V_39 ;
goto V_456;
}
V_31 = F_449 () ;
if ( V_31 )
goto V_152;
V_457 . V_458 = V_445 ;
V_385 . V_458 = V_445 ;
V_258 . V_458 = V_445 ;
V_31 = F_450 ( & V_459 ) ;
if ( V_31 ) {
F_410 ( L_12 ) ;
goto V_460;
}
F_451 ( & V_461 ) ;
V_265 . V_462 = F_436 ;
V_265 . V_463 = F_438 ;
V_31 = F_431 () ;
if ( V_31 ) {
F_410 ( L_13 ) ;
goto V_464;
}
V_31 = F_452 () ;
F_132 ( V_31 ) ;
return 0 ;
V_464:
F_453 ( & V_461 ) ;
F_454 ( & V_459 ) ;
V_460:
F_455 () ;
V_152:
F_456 ( V_455 ) ;
V_456:
F_457 ( & V_454 ) ;
F_458 ( V_452 ) ;
V_453:
V_451:
F_459 () ;
V_449:
F_29 ( V_395 ) ;
V_448:
F_460 () ;
V_447:
F_461 () ;
V_446:
return V_31 ;
}
void F_462 ( void )
{
F_82 ( V_82 ) ;
F_454 ( & V_459 ) ;
F_456 ( V_455 ) ;
F_455 () ;
F_453 ( & V_461 ) ;
F_457 ( & V_454 ) ;
F_458 ( V_452 ) ;
F_390 ( F_386 , NULL , 1 ) ;
F_459 () ;
F_461 () ;
F_460 () ;
F_29 ( V_395 ) ;
F_463 () ;
}
