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
static void F_17 ( void * V_8 )
{
}
bool F_18 ( struct V_9 * V_9 , unsigned int V_10 )
{
int V_11 , V_4 , V_12 ;
T_2 V_13 ;
bool V_14 = true ;
struct V_2 * V_3 ;
F_19 ( & V_13 , V_15 ) ;
V_12 = F_7 () ;
F_20 (i, vcpu, kvm) {
F_21 ( V_10 , V_3 ) ;
V_4 = V_3 -> V_4 ;
F_22 () ;
if ( V_13 != NULL && V_4 != - 1 && V_4 != V_12 &&
F_23 ( V_3 ) != V_16 )
F_24 ( V_4 , V_13 ) ;
}
if ( F_25 ( V_13 == NULL ) )
F_26 ( V_17 , F_17 , NULL , 1 ) ;
else if ( ! F_27 ( V_13 ) )
F_26 ( V_13 , F_17 , NULL , 1 ) ;
else
V_14 = false ;
F_10 () ;
F_28 ( V_13 ) ;
return V_14 ;
}
void F_29 ( struct V_9 * V_9 )
{
long V_18 = F_30 ( & V_9 -> V_19 ) ;
if ( F_18 ( V_9 , V_20 ) )
++ V_9 -> V_21 . V_22 ;
F_31 ( & V_9 -> V_19 , V_18 , 0 ) ;
}
void F_32 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_23 ) ;
}
int F_33 ( struct V_2 * V_3 , struct V_9 * V_9 , unsigned V_24 )
{
struct V_25 * V_25 ;
int V_26 ;
F_34 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_27 = V_24 ;
V_3 -> V_28 = NULL ;
F_35 ( & V_3 -> V_29 ) ;
F_36 ( V_3 ) ;
V_3 -> V_30 = - 1 ;
F_37 ( & V_3 -> V_31 ) ;
V_25 = F_38 ( V_32 | V_33 ) ;
if ( ! V_25 ) {
V_26 = - V_34 ;
goto V_35;
}
V_3 -> V_36 = F_39 ( V_25 ) ;
F_40 ( V_3 , false ) ;
F_41 ( V_3 , false ) ;
V_3 -> V_37 = false ;
V_26 = F_42 ( V_3 ) ;
if ( V_26 < 0 )
goto V_38;
return 0 ;
V_38:
F_43 ( ( unsigned long ) V_3 -> V_36 ) ;
V_35:
return V_26 ;
}
void F_44 ( struct V_2 * V_3 )
{
F_45 ( V_3 -> V_28 ) ;
F_46 ( V_3 ) ;
F_43 ( ( unsigned long ) V_3 -> V_36 ) ;
}
static inline struct V_9 * F_47 ( struct V_39 * V_40 )
{
return F_48 ( V_40 , struct V_9 , V_39 ) ;
}
static void F_49 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_44 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_48 ++ ;
V_44 = F_52 ( V_9 , V_43 ) | V_9 -> V_19 ;
if ( V_44 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_54 ( V_9 , V_43 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static void F_56 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_43 ,
T_3 V_49 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_48 ++ ;
F_57 ( V_9 , V_43 , V_49 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static void F_58 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_44 = 0 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_52 ++ ;
V_44 = F_59 ( V_9 , V_50 , V_51 ) ;
V_44 |= V_9 -> V_19 ;
if ( V_44 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static void F_60 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_9 -> V_48 ++ ;
F_61 () ;
V_9 -> V_52 -- ;
F_53 ( & V_9 -> V_47 ) ;
F_62 ( V_9 -> V_52 < 0 ) ;
}
static int F_63 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_53 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_53 = F_64 ( V_9 , V_50 , V_51 ) ;
if ( V_53 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
return V_53 ;
}
static int F_65 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_50 ,
unsigned long V_51 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_53 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_53 = F_64 ( V_9 , V_50 , V_51 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
return V_53 ;
}
static int F_66 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
unsigned long V_43 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_53 , V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_51 ( & V_9 -> V_47 ) ;
V_53 = F_67 ( V_9 , V_43 ) ;
F_53 ( & V_9 -> V_47 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
return V_53 ;
}
static void F_68 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_9 * V_9 = F_47 ( V_40 ) ;
int V_45 ;
V_45 = F_50 ( & V_9 -> V_46 ) ;
F_69 ( V_9 ) ;
F_55 ( & V_9 -> V_46 , V_45 ) ;
}
static int F_70 ( struct V_9 * V_9 )
{
V_9 -> V_39 . V_54 = & V_55 ;
return F_71 ( & V_9 -> V_39 , V_56 -> V_42 ) ;
}
static int F_70 ( struct V_9 * V_9 )
{
return 0 ;
}
static struct V_57 * F_72 ( void )
{
int V_11 ;
struct V_57 * V_58 ;
V_58 = F_73 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_59 = - 150 ;
for ( V_11 = 0 ; V_11 < V_60 ; V_11 ++ )
V_58 -> V_61 [ V_11 ] = V_58 -> V_62 [ V_11 ] . V_24 = V_11 ;
return V_58 ;
}
static void F_74 ( struct V_63 * V_64 )
{
if ( ! V_64 -> V_65 )
return;
F_75 ( V_64 -> V_65 ) ;
V_64 -> V_65 = NULL ;
}
static void F_76 ( struct V_9 * V_9 , struct V_63 * free ,
struct V_63 * V_66 )
{
if ( ! V_66 || free -> V_65 != V_66 -> V_65 )
F_74 ( free ) ;
F_77 ( V_9 , free , V_66 ) ;
free -> V_67 = 0 ;
}
static void F_78 ( struct V_9 * V_9 , struct V_57 * V_58 )
{
struct V_63 * V_64 ;
if ( ! V_58 )
return;
F_79 (memslot, slots)
F_76 ( V_9 , V_64 , NULL ) ;
F_75 ( V_58 ) ;
}
static void F_80 ( struct V_9 * V_9 )
{
int V_11 ;
if ( ! V_9 -> V_68 )
return;
F_81 ( V_9 -> V_68 ) ;
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ )
F_82 ( V_9 -> V_70 [ V_11 ] ) ;
F_82 ( V_9 -> V_70 ) ;
}
static int F_83 ( struct V_9 * V_9 , int V_71 )
{
char V_72 [ V_73 * 2 ] ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_72 , sizeof( V_72 ) , L_1 , F_85 ( V_56 ) , V_71 ) ;
V_9 -> V_68 = F_86 ( V_72 ,
V_78 ) ;
if ( ! V_9 -> V_68 )
return - V_34 ;
V_9 -> V_70 = F_87 ( V_69 ,
sizeof( * V_9 -> V_70 ) ,
V_32 ) ;
if ( ! V_9 -> V_70 )
return - V_34 ;
for ( V_77 = V_79 ; V_77 -> V_80 ; V_77 ++ ) {
V_75 = F_88 ( sizeof( * V_75 ) , V_32 ) ;
if ( ! V_75 )
return - V_34 ;
V_75 -> V_9 = V_9 ;
V_75 -> V_81 = V_77 -> V_81 ;
V_9 -> V_70 [ V_77 - V_79 ] = V_75 ;
if ( ! F_89 ( V_77 -> V_80 , 0444 ,
V_9 -> V_68 ,
V_75 ,
V_82 [ V_77 -> V_83 ] ) )
return - V_34 ;
}
return 0 ;
}
static struct V_9 * F_90 ( unsigned long type )
{
int V_26 , V_11 ;
struct V_9 * V_9 = F_91 () ;
if ( ! V_9 )
return F_92 ( - V_34 ) ;
F_93 ( & V_9 -> V_47 ) ;
F_94 ( & V_56 -> V_42 -> V_84 ) ;
V_9 -> V_42 = V_56 -> V_42 ;
F_95 ( V_9 ) ;
F_34 ( & V_9 -> V_85 ) ;
F_34 ( & V_9 -> V_86 ) ;
F_34 ( & V_9 -> V_87 ) ;
F_96 ( & V_9 -> V_88 , 1 ) ;
F_37 ( & V_9 -> V_89 ) ;
V_26 = F_97 ( V_9 , type ) ;
if ( V_26 )
goto V_90;
V_26 = F_98 () ;
if ( V_26 )
goto V_90;
#ifdef F_99
F_100 ( & V_9 -> V_91 ) ;
#endif
F_101 ( V_60 > V_92 ) ;
V_26 = - V_34 ;
for ( V_11 = 0 ; V_11 < V_93 ; V_11 ++ ) {
V_9 -> V_62 [ V_11 ] = F_72 () ;
if ( ! V_9 -> V_62 [ V_11 ] )
goto V_94;
}
if ( F_102 ( & V_9 -> V_46 ) )
goto V_94;
if ( F_102 ( & V_9 -> V_95 ) )
goto V_96;
for ( V_11 = 0 ; V_11 < V_97 ; V_11 ++ ) {
V_9 -> V_98 [ V_11 ] = F_88 ( sizeof( struct V_99 ) ,
V_32 ) ;
if ( ! V_9 -> V_98 [ V_11 ] )
goto V_100;
}
V_26 = F_70 ( V_9 ) ;
if ( V_26 )
goto V_100;
F_51 ( & V_101 ) ;
F_103 ( & V_9 -> V_102 , & V_102 ) ;
F_53 ( & V_101 ) ;
F_104 () ;
return V_9 ;
V_100:
F_105 ( & V_9 -> V_95 ) ;
V_96:
F_105 ( & V_9 -> V_46 ) ;
V_94:
F_106 () ;
V_90:
for ( V_11 = 0 ; V_11 < V_97 ; V_11 ++ )
F_82 ( V_9 -> V_98 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_93 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_62 [ V_11 ] ) ;
F_107 ( V_9 ) ;
F_108 ( V_56 -> V_42 ) ;
return F_92 ( V_26 ) ;
}
void * F_73 ( unsigned long V_103 )
{
if ( V_103 > V_104 )
return F_109 ( V_103 ) ;
else
return F_88 ( V_103 , V_32 ) ;
}
static void F_110 ( struct V_9 * V_9 )
{
struct V_105 * V_106 , * V_107 ;
F_111 (dev, tmp, &kvm->devices, vm_node) {
F_112 ( & V_106 -> V_108 ) ;
V_106 -> V_54 -> V_109 ( V_106 ) ;
}
}
static void F_113 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_41 * V_42 = V_9 -> V_42 ;
F_80 ( V_9 ) ;
F_114 ( V_9 ) ;
F_51 ( & V_101 ) ;
F_112 ( & V_9 -> V_102 ) ;
F_53 ( & V_101 ) ;
F_115 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_97 ; V_11 ++ )
F_116 ( V_9 -> V_98 [ V_11 ] ) ;
F_117 ( V_9 ) ;
#if F_118 ( V_110 ) && F_118 ( V_111 )
F_119 ( & V_9 -> V_39 , V_9 -> V_42 ) ;
#else
F_69 ( V_9 ) ;
#endif
F_120 ( V_9 ) ;
F_110 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_93 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_62 [ V_11 ] ) ;
F_105 ( & V_9 -> V_95 ) ;
F_105 ( & V_9 -> V_46 ) ;
F_107 ( V_9 ) ;
F_121 () ;
F_106 () ;
F_108 ( V_42 ) ;
}
void F_122 ( struct V_9 * V_9 )
{
F_94 ( & V_9 -> V_88 ) ;
}
void F_123 ( struct V_9 * V_9 )
{
if ( F_124 ( & V_9 -> V_88 ) )
F_113 ( V_9 ) ;
}
static int F_125 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
struct V_9 * V_9 = V_114 -> V_115 ;
F_126 ( V_9 ) ;
F_123 ( V_9 ) ;
return 0 ;
}
static int F_127 ( struct V_63 * V_64 )
{
unsigned long V_116 = 2 * F_128 ( V_64 ) ;
V_64 -> V_65 = F_73 ( V_116 ) ;
if ( ! V_64 -> V_65 )
return - V_34 ;
return 0 ;
}
static void F_129 ( struct V_57 * V_58 ,
struct V_63 * V_117 )
{
int V_24 = V_117 -> V_24 ;
int V_11 = V_58 -> V_61 [ V_24 ] ;
struct V_63 * V_118 = V_58 -> V_62 ;
F_130 ( V_118 [ V_11 ] . V_24 != V_24 ) ;
if ( ! V_117 -> V_67 ) {
F_130 ( ! V_118 [ V_11 ] . V_67 ) ;
if ( V_118 [ V_11 ] . V_67 )
V_58 -> V_119 -- ;
} else {
if ( ! V_118 [ V_11 ] . V_67 )
V_58 -> V_119 ++ ;
}
while ( V_11 < V_60 - 1 &&
V_117 -> V_120 <= V_118 [ V_11 + 1 ] . V_120 ) {
if ( ! V_118 [ V_11 + 1 ] . V_67 )
break;
V_118 [ V_11 ] = V_118 [ V_11 + 1 ] ;
V_58 -> V_61 [ V_118 [ V_11 ] . V_24 ] = V_11 ;
V_11 ++ ;
}
if ( V_117 -> V_67 ) {
while ( V_11 > 0 &&
V_117 -> V_120 >= V_118 [ V_11 - 1 ] . V_120 ) {
V_118 [ V_11 ] = V_118 [ V_11 - 1 ] ;
V_58 -> V_61 [ V_118 [ V_11 ] . V_24 ] = V_11 ;
V_11 -- ;
}
} else
F_131 ( V_11 != V_58 -> V_119 ) ;
V_118 [ V_11 ] = * V_117 ;
V_58 -> V_61 [ V_118 [ V_11 ] . V_24 ] = V_11 ;
}
static int F_132 ( const struct V_121 * V_122 )
{
T_4 V_123 = V_124 ;
#ifdef F_133
V_123 |= V_125 ;
#endif
if ( V_122 -> V_126 & ~ V_123 )
return - V_127 ;
return 0 ;
}
static struct V_57 * F_134 ( struct V_9 * V_9 ,
int V_128 , struct V_57 * V_58 )
{
struct V_57 * V_129 = F_135 ( V_9 , V_128 ) ;
F_130 ( V_129 -> V_59 & 1 ) ;
V_58 -> V_59 = V_129 -> V_59 + 1 ;
F_136 ( V_9 -> V_62 [ V_128 ] , V_58 ) ;
F_137 ( & V_9 -> V_46 ) ;
V_58 -> V_59 ++ ;
F_138 ( V_9 , V_58 ) ;
return V_129 ;
}
int F_139 ( struct V_9 * V_9 ,
const struct V_121 * V_122 )
{
int V_26 ;
T_5 V_120 ;
unsigned long V_67 ;
struct V_63 * V_130 ;
struct V_63 V_131 , V_117 ;
struct V_57 * V_58 = NULL , * V_129 ;
int V_128 , V_24 ;
enum V_132 V_133 ;
V_26 = F_132 ( V_122 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_127 ;
V_128 = V_122 -> V_130 >> 16 ;
V_24 = ( V_135 ) V_122 -> V_130 ;
if ( V_122 -> V_136 & ( V_104 - 1 ) )
goto V_134;
if ( V_122 -> V_137 & ( V_104 - 1 ) )
goto V_134;
if ( ( V_24 < V_138 ) &&
( ( V_122 -> V_139 & ( V_104 - 1 ) ) ||
! F_140 ( V_140 ,
( void V_141 * ) ( unsigned long ) V_122 -> V_139 ,
V_122 -> V_136 ) ) )
goto V_134;
if ( V_128 >= V_93 || V_24 >= V_60 )
goto V_134;
if ( V_122 -> V_137 + V_122 -> V_136 < V_122 -> V_137 )
goto V_134;
V_130 = F_141 ( F_135 ( V_9 , V_128 ) , V_24 ) ;
V_120 = V_122 -> V_137 >> V_142 ;
V_67 = V_122 -> V_136 >> V_142 ;
if ( V_67 > V_143 )
goto V_134;
V_117 = V_131 = * V_130 ;
V_117 . V_24 = V_24 ;
V_117 . V_120 = V_120 ;
V_117 . V_67 = V_67 ;
V_117 . V_126 = V_122 -> V_126 ;
if ( V_67 ) {
if ( ! V_131 . V_67 )
V_133 = V_144 ;
else {
if ( ( V_122 -> V_139 != V_131 . V_139 ) ||
( V_67 != V_131 . V_67 ) ||
( ( V_117 . V_126 ^ V_131 . V_126 ) & V_125 ) )
goto V_134;
if ( V_120 != V_131 . V_120 )
V_133 = V_145 ;
else if ( V_117 . V_126 != V_131 . V_126 )
V_133 = V_146 ;
else {
V_26 = 0 ;
goto V_134;
}
}
} else {
if ( ! V_131 . V_67 )
goto V_134;
V_133 = V_147 ;
V_117 . V_120 = 0 ;
V_117 . V_126 = 0 ;
}
if ( ( V_133 == V_144 ) || ( V_133 == V_145 ) ) {
V_26 = - V_148 ;
F_79 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_130 -> V_24 >= V_138 ) ||
( V_130 -> V_24 == V_24 ) )
continue;
if ( ! ( ( V_120 + V_67 <= V_130 -> V_120 ) ||
( V_120 >= V_130 -> V_120 + V_130 -> V_67 ) ) )
goto V_134;
}
}
if ( ! ( V_117 . V_126 & V_124 ) )
V_117 . V_65 = NULL ;
V_26 = - V_34 ;
if ( V_133 == V_144 ) {
V_117 . V_139 = V_122 -> V_139 ;
if ( F_142 ( V_9 , & V_117 , V_67 ) )
goto V_149;
}
if ( ( V_117 . V_126 & V_124 ) && ! V_117 . V_65 ) {
if ( F_127 ( & V_117 ) < 0 )
goto V_149;
}
V_58 = F_73 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
goto V_149;
memcpy ( V_58 , F_135 ( V_9 , V_128 ) , sizeof( struct V_57 ) ) ;
if ( ( V_133 == V_147 ) || ( V_133 == V_145 ) ) {
V_130 = F_141 ( V_58 , V_24 ) ;
V_130 -> V_126 |= V_150 ;
V_129 = F_134 ( V_9 , V_128 , V_58 ) ;
F_143 ( V_9 , & V_131 ) ;
F_144 ( V_9 , V_130 ) ;
V_58 = V_129 ;
}
V_26 = F_145 ( V_9 , & V_117 , V_122 , V_133 ) ;
if ( V_26 )
goto V_151;
if ( V_133 == V_147 ) {
V_117 . V_65 = NULL ;
memset ( & V_117 . V_152 , 0 , sizeof( V_117 . V_152 ) ) ;
}
F_129 ( V_58 , & V_117 ) ;
V_129 = F_134 ( V_9 , V_128 , V_58 ) ;
F_146 ( V_9 , V_122 , & V_131 , & V_117 , V_133 ) ;
F_76 ( V_9 , & V_131 , & V_117 ) ;
F_75 ( V_129 ) ;
if ( ( V_133 == V_144 ) || ( V_133 == V_145 ) ) {
V_26 = F_147 ( V_9 , & V_117 ) ;
return V_26 ;
}
return 0 ;
V_151:
F_75 ( V_58 ) ;
V_149:
F_76 ( V_9 , & V_117 , & V_131 ) ;
V_134:
return V_26 ;
}
int F_148 ( struct V_9 * V_9 ,
const struct V_121 * V_122 )
{
int V_26 ;
F_149 ( & V_9 -> V_87 ) ;
V_26 = F_139 ( V_9 , V_122 ) ;
F_16 ( & V_9 -> V_87 ) ;
return V_26 ;
}
static int F_150 ( struct V_9 * V_9 ,
struct V_121 * V_122 )
{
if ( ( V_135 ) V_122 -> V_130 >= V_138 )
return - V_127 ;
return F_148 ( V_9 , V_122 ) ;
}
int F_151 ( struct V_9 * V_9 ,
struct V_153 * log , int * V_154 )
{
struct V_57 * V_58 ;
struct V_63 * V_64 ;
int V_26 , V_11 , V_128 , V_24 ;
unsigned long V_155 ;
unsigned long V_156 = 0 ;
V_26 = - V_127 ;
V_128 = log -> V_130 >> 16 ;
V_24 = ( V_135 ) log -> V_130 ;
if ( V_128 >= V_93 || V_24 >= V_138 )
goto V_134;
V_58 = F_135 ( V_9 , V_128 ) ;
V_64 = F_141 ( V_58 , V_24 ) ;
V_26 = - V_157 ;
if ( ! V_64 -> V_65 )
goto V_134;
V_155 = F_128 ( V_64 ) ;
for ( V_11 = 0 ; ! V_156 && V_11 < V_155 / sizeof( long ) ; ++ V_11 )
V_156 = V_64 -> V_65 [ V_11 ] ;
V_26 = - V_158 ;
if ( F_152 ( log -> V_65 , V_64 -> V_65 , V_155 ) )
goto V_134;
if ( V_156 )
* V_154 = 1 ;
V_26 = 0 ;
V_134:
return V_26 ;
}
int F_153 ( struct V_9 * V_9 ,
struct V_153 * log , bool * V_154 )
{
struct V_57 * V_58 ;
struct V_63 * V_64 ;
int V_26 , V_11 , V_128 , V_24 ;
unsigned long V_155 ;
unsigned long * V_65 ;
unsigned long * V_159 ;
V_26 = - V_127 ;
V_128 = log -> V_130 >> 16 ;
V_24 = ( V_135 ) log -> V_130 ;
if ( V_128 >= V_93 || V_24 >= V_138 )
goto V_134;
V_58 = F_135 ( V_9 , V_128 ) ;
V_64 = F_141 ( V_58 , V_24 ) ;
V_65 = V_64 -> V_65 ;
V_26 = - V_157 ;
if ( ! V_65 )
goto V_134;
V_155 = F_128 ( V_64 ) ;
V_159 = V_65 + V_155 / sizeof( long ) ;
memset ( V_159 , 0 , V_155 ) ;
F_51 ( & V_9 -> V_47 ) ;
* V_154 = false ;
for ( V_11 = 0 ; V_11 < V_155 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_160 ;
T_5 V_81 ;
if ( ! V_65 [ V_11 ] )
continue;
* V_154 = true ;
V_160 = F_154 ( & V_65 [ V_11 ] , 0 ) ;
V_159 [ V_11 ] = V_160 ;
if ( V_160 ) {
V_81 = V_11 * V_161 ;
F_155 ( V_9 , V_64 ,
V_81 , V_160 ) ;
}
}
F_53 ( & V_9 -> V_47 ) ;
V_26 = - V_158 ;
if ( F_152 ( log -> V_65 , V_159 , V_155 ) )
goto V_134;
V_26 = 0 ;
V_134:
return V_26 ;
}
bool F_156 ( void )
{
return V_162 ;
}
void F_157 ( void )
{
V_162 = false ;
}
struct V_63 * F_158 ( struct V_9 * V_9 , T_5 V_163 )
{
return F_159 ( V_57 ( V_9 ) , V_163 ) ;
}
struct V_63 * F_160 ( struct V_2 * V_3 , T_5 V_163 )
{
return F_159 ( F_161 ( V_3 ) , V_163 ) ;
}
bool F_162 ( struct V_9 * V_9 , T_5 V_163 )
{
struct V_63 * V_64 = F_158 ( V_9 , V_163 ) ;
if ( ! V_64 || V_64 -> V_24 >= V_138 ||
V_64 -> V_126 & V_150 )
return false ;
return true ;
}
unsigned long F_163 ( struct V_9 * V_9 , T_5 V_163 )
{
struct V_164 * V_165 ;
unsigned long V_166 , V_103 ;
V_103 = V_104 ;
V_166 = F_164 ( V_9 , V_163 ) ;
if ( F_165 ( V_166 ) )
return V_104 ;
F_166 ( & V_56 -> V_42 -> V_167 ) ;
V_165 = F_167 ( V_56 -> V_42 , V_166 ) ;
if ( ! V_165 )
goto V_134;
V_103 = F_168 ( V_165 ) ;
V_134:
F_169 ( & V_56 -> V_42 -> V_167 ) ;
return V_103 ;
}
static bool F_170 ( struct V_63 * V_130 )
{
return V_130 -> V_126 & V_125 ;
}
static unsigned long F_171 ( struct V_63 * V_130 , T_5 V_163 ,
T_5 * V_168 , bool V_169 )
{
if ( ! V_130 || V_130 -> V_126 & V_150 )
return V_170 ;
if ( F_170 ( V_130 ) && V_169 )
return V_171 ;
if ( V_168 )
* V_168 = V_130 -> V_67 - ( V_163 - V_130 -> V_120 ) ;
return F_172 ( V_130 , V_163 ) ;
}
static unsigned long F_173 ( struct V_63 * V_130 , T_5 V_163 ,
T_5 * V_168 )
{
return F_171 ( V_130 , V_163 , V_168 , true ) ;
}
unsigned long F_174 ( struct V_63 * V_130 ,
T_5 V_163 )
{
return F_173 ( V_130 , V_163 , NULL ) ;
}
unsigned long F_164 ( struct V_9 * V_9 , T_5 V_163 )
{
return F_173 ( F_158 ( V_9 , V_163 ) , V_163 , NULL ) ;
}
unsigned long F_175 ( struct V_2 * V_3 , T_5 V_163 )
{
return F_173 ( F_160 ( V_3 , V_163 ) , V_163 , NULL ) ;
}
unsigned long F_176 ( struct V_63 * V_130 ,
T_5 V_163 , bool * V_172 )
{
unsigned long V_173 = F_171 ( V_130 , V_163 , NULL , false ) ;
if ( ! F_165 ( V_173 ) && V_172 )
* V_172 = ! F_170 ( V_130 ) ;
return V_173 ;
}
unsigned long F_177 ( struct V_9 * V_9 , T_5 V_163 , bool * V_172 )
{
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
return F_176 ( V_130 , V_163 , V_172 ) ;
}
unsigned long F_178 ( struct V_2 * V_3 , T_5 V_163 , bool * V_172 )
{
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
return F_176 ( V_130 , V_163 , V_172 ) ;
}
static int F_179 ( unsigned long V_50 , int V_169 ,
struct V_25 * * V_25 )
{
int V_126 = V_174 | V_175 | V_176 | V_177 ;
if ( V_169 )
V_126 |= V_178 ;
return F_180 ( V_56 , V_56 -> V_42 , V_50 , 1 , V_126 , V_25 ,
NULL , NULL ) ;
}
static inline int F_181 ( unsigned long V_166 )
{
int V_179 , V_126 = V_174 | V_176 | V_178 ;
V_179 = F_180 ( V_56 , V_56 -> V_42 , V_166 , 1 ,
V_126 , NULL , NULL , NULL ) ;
return V_179 == - V_180 ;
}
static bool F_182 ( unsigned long V_166 , bool V_181 , bool * V_182 ,
bool V_183 , bool * V_172 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_67 ;
if ( ! ( V_182 || V_181 ) )
return false ;
if ( ! ( V_183 || V_172 ) )
return false ;
V_67 = F_183 ( V_166 , 1 , 1 , V_25 ) ;
if ( V_67 == 1 ) {
* V_1 = F_184 ( V_25 [ 0 ] ) ;
if ( V_172 )
* V_172 = true ;
return true ;
}
return false ;
}
static int F_185 ( unsigned long V_166 , bool * V_182 , bool V_183 ,
bool * V_172 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_67 = 0 ;
F_186 () ;
if ( V_172 )
* V_172 = V_183 ;
if ( V_182 ) {
F_166 ( & V_56 -> V_42 -> V_167 ) ;
V_67 = F_179 ( V_166 , V_183 , V_25 ) ;
F_169 ( & V_56 -> V_42 -> V_167 ) ;
} else
V_67 = F_187 ( V_56 , V_56 -> V_42 , V_166 , 1 ,
V_183 , 0 , V_25 ,
V_174 | V_176 ) ;
if ( V_67 != 1 )
return V_67 ;
if ( F_25 ( ! V_183 ) && V_172 ) {
struct V_25 * V_184 [ 1 ] ;
V_67 = F_183 ( V_166 , 1 , 1 , V_184 ) ;
if ( V_67 == 1 ) {
* V_172 = true ;
F_188 ( V_25 [ 0 ] ) ;
V_25 [ 0 ] = V_184 [ 0 ] ;
}
V_67 = 1 ;
}
* V_1 = F_184 ( V_25 [ 0 ] ) ;
return V_67 ;
}
static bool F_189 ( struct V_164 * V_165 , bool V_183 )
{
if ( F_25 ( ! ( V_165 -> V_185 & V_186 ) ) )
return false ;
if ( V_183 && ( F_25 ( ! ( V_165 -> V_185 & V_187 ) ) ) )
return false ;
return true ;
}
static T_1 F_190 ( unsigned long V_166 , bool V_181 , bool * V_182 ,
bool V_183 , bool * V_172 )
{
struct V_164 * V_165 ;
T_1 V_1 = 0 ;
int V_67 ;
F_62 ( V_181 && V_182 ) ;
if ( F_182 ( V_166 , V_181 , V_182 , V_183 , V_172 , & V_1 ) )
return V_1 ;
if ( V_181 )
return V_188 ;
V_67 = F_185 ( V_166 , V_182 , V_183 , V_172 , & V_1 ) ;
if ( V_67 == 1 )
return V_1 ;
F_166 ( & V_56 -> V_42 -> V_167 ) ;
if ( V_67 == - V_180 ||
( ! V_182 && F_181 ( V_166 ) ) ) {
V_1 = V_189 ;
goto exit;
}
V_165 = F_191 ( V_56 -> V_42 , V_166 , V_166 + 1 ) ;
if ( V_165 == NULL )
V_1 = V_188 ;
else if ( ( V_165 -> V_185 & V_190 ) ) {
V_1 = ( ( V_166 - V_165 -> V_191 ) >> V_142 ) +
V_165 -> V_192 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_182 && F_189 ( V_165 , V_183 ) )
* V_182 = true ;
V_1 = V_188 ;
}
exit:
F_169 ( & V_56 -> V_42 -> V_167 ) ;
return V_1 ;
}
T_1 F_192 ( struct V_63 * V_130 , T_5 V_163 ,
bool V_181 , bool * V_182 , bool V_183 ,
bool * V_172 )
{
unsigned long V_166 = F_171 ( V_130 , V_163 , NULL , V_183 ) ;
if ( V_166 == V_171 ) {
if ( V_172 )
* V_172 = false ;
return V_193 ;
}
if ( F_165 ( V_166 ) ) {
if ( V_172 )
* V_172 = false ;
return V_194 ;
}
if ( V_172 && F_170 ( V_130 ) ) {
* V_172 = false ;
V_172 = NULL ;
}
return F_190 ( V_166 , V_181 , V_182 , V_183 ,
V_172 ) ;
}
T_1 F_193 ( struct V_9 * V_9 , T_5 V_163 , bool V_183 ,
bool * V_172 )
{
return F_192 ( F_158 ( V_9 , V_163 ) , V_163 , false , NULL ,
V_183 , V_172 ) ;
}
T_1 F_194 ( struct V_63 * V_130 , T_5 V_163 )
{
return F_192 ( V_130 , V_163 , false , NULL , true , NULL ) ;
}
T_1 F_195 ( struct V_63 * V_130 , T_5 V_163 )
{
return F_192 ( V_130 , V_163 , true , NULL , true , NULL ) ;
}
T_1 F_196 ( struct V_9 * V_9 , T_5 V_163 )
{
return F_195 ( F_158 ( V_9 , V_163 ) , V_163 ) ;
}
T_1 F_197 ( struct V_2 * V_3 , T_5 V_163 )
{
return F_195 ( F_160 ( V_3 , V_163 ) , V_163 ) ;
}
T_1 F_198 ( struct V_9 * V_9 , T_5 V_163 )
{
return F_194 ( F_158 ( V_9 , V_163 ) , V_163 ) ;
}
T_1 F_199 ( struct V_2 * V_3 , T_5 V_163 )
{
return F_194 ( F_160 ( V_3 , V_163 ) , V_163 ) ;
}
int F_200 ( struct V_63 * V_130 , T_5 V_163 ,
struct V_25 * * V_195 , int V_168 )
{
unsigned long V_166 ;
T_5 V_196 ;
V_166 = F_173 ( V_130 , V_163 , & V_196 ) ;
if ( F_165 ( V_166 ) )
return - 1 ;
if ( V_196 < V_168 )
return 0 ;
return F_183 ( V_166 , V_168 , 1 , V_195 ) ;
}
static struct V_25 * F_201 ( T_1 V_1 )
{
if ( F_202 ( V_1 ) )
return V_197 ;
if ( F_1 ( V_1 ) ) {
F_130 ( 1 ) ;
return V_197 ;
}
return F_4 ( V_1 ) ;
}
struct V_25 * F_203 ( struct V_9 * V_9 , T_5 V_163 )
{
T_1 V_1 ;
V_1 = F_198 ( V_9 , V_163 ) ;
return F_201 ( V_1 ) ;
}
struct V_25 * F_204 ( struct V_2 * V_3 , T_5 V_163 )
{
T_1 V_1 ;
V_1 = F_199 ( V_3 , V_163 ) ;
return F_201 ( V_1 ) ;
}
void F_205 ( struct V_25 * V_25 )
{
F_130 ( F_206 ( V_25 ) ) ;
F_207 ( F_184 ( V_25 ) ) ;
}
void F_207 ( T_1 V_1 )
{
if ( ! F_202 ( V_1 ) && ! F_1 ( V_1 ) )
F_188 ( F_4 ( V_1 ) ) ;
}
void F_208 ( struct V_25 * V_25 )
{
F_130 ( F_206 ( V_25 ) ) ;
F_209 ( F_184 ( V_25 ) ) ;
}
static void F_209 ( T_1 V_1 )
{
F_210 ( V_1 ) ;
F_207 ( V_1 ) ;
}
void F_210 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_25 * V_25 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_25 ) )
F_211 ( V_25 ) ;
}
}
void F_212 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_213 ( F_4 ( V_1 ) ) ;
}
void F_214 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_215 ( F_4 ( V_1 ) ) ;
}
static int F_216 ( unsigned long V_198 , int V_81 )
{
if ( V_198 > V_104 - V_81 )
return V_104 - V_81 ;
else
return V_198 ;
}
static int F_217 ( struct V_63 * V_130 , T_5 V_163 ,
void * V_199 , int V_81 , int V_198 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_176 ( V_130 , V_163 , NULL ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
V_26 = F_218 ( V_199 , ( void V_141 * ) V_166 + V_81 , V_198 ) ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_219 ( struct V_9 * V_9 , T_5 V_163 , void * V_199 , int V_81 ,
int V_198 )
{
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
return F_217 ( V_130 , V_163 , V_199 , V_81 , V_198 ) ;
}
int F_220 ( struct V_2 * V_3 , T_5 V_163 , void * V_199 ,
int V_81 , int V_198 )
{
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
return F_217 ( V_130 , V_163 , V_199 , V_81 , V_198 ) ;
}
int F_221 ( struct V_9 * V_9 , T_6 V_200 , void * V_199 , unsigned long V_198 )
{
T_5 V_163 = V_200 >> V_142 ;
int V_201 ;
int V_81 = F_222 ( V_200 ) ;
int V_202 ;
while ( ( V_201 = F_216 ( V_198 , V_81 ) ) != 0 ) {
V_202 = F_219 ( V_9 , V_163 , V_199 , V_81 , V_201 ) ;
if ( V_202 < 0 )
return V_202 ;
V_81 = 0 ;
V_198 -= V_201 ;
V_199 += V_201 ;
++ V_163 ;
}
return 0 ;
}
int F_223 ( struct V_2 * V_3 , T_6 V_200 , void * V_199 , unsigned long V_198 )
{
T_5 V_163 = V_200 >> V_142 ;
int V_201 ;
int V_81 = F_222 ( V_200 ) ;
int V_202 ;
while ( ( V_201 = F_216 ( V_198 , V_81 ) ) != 0 ) {
V_202 = F_220 ( V_3 , V_163 , V_199 , V_81 , V_201 ) ;
if ( V_202 < 0 )
return V_202 ;
V_81 = 0 ;
V_198 -= V_201 ;
V_199 += V_201 ;
++ V_163 ;
}
return 0 ;
}
static int F_224 ( struct V_63 * V_130 , T_5 V_163 ,
void * V_199 , int V_81 , unsigned long V_198 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_176 ( V_130 , V_163 , NULL ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
F_225 () ;
V_26 = F_226 ( V_199 , ( void V_141 * ) V_166 + V_81 , V_198 ) ;
F_227 () ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_228 ( struct V_9 * V_9 , T_6 V_200 , void * V_199 ,
unsigned long V_198 )
{
T_5 V_163 = V_200 >> V_142 ;
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
int V_81 = F_222 ( V_200 ) ;
return F_224 ( V_130 , V_163 , V_199 , V_81 , V_198 ) ;
}
int F_229 ( struct V_2 * V_3 , T_6 V_200 ,
void * V_199 , unsigned long V_198 )
{
T_5 V_163 = V_200 >> V_142 ;
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
int V_81 = F_222 ( V_200 ) ;
return F_224 ( V_130 , V_163 , V_199 , V_81 , V_198 ) ;
}
static int F_230 ( struct V_63 * V_64 , T_5 V_163 ,
const void * V_199 , int V_81 , int V_198 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_174 ( V_64 , V_163 ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
V_26 = F_231 ( ( void V_141 * ) V_166 + V_81 , V_199 , V_198 ) ;
if ( V_26 )
return - V_158 ;
F_232 ( V_64 , V_163 ) ;
return 0 ;
}
int F_233 ( struct V_9 * V_9 , T_5 V_163 ,
const void * V_199 , int V_81 , int V_198 )
{
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
return F_230 ( V_130 , V_163 , V_199 , V_81 , V_198 ) ;
}
int F_234 ( struct V_2 * V_3 , T_5 V_163 ,
const void * V_199 , int V_81 , int V_198 )
{
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
return F_230 ( V_130 , V_163 , V_199 , V_81 , V_198 ) ;
}
int F_235 ( struct V_9 * V_9 , T_6 V_200 , const void * V_199 ,
unsigned long V_198 )
{
T_5 V_163 = V_200 >> V_142 ;
int V_201 ;
int V_81 = F_222 ( V_200 ) ;
int V_202 ;
while ( ( V_201 = F_216 ( V_198 , V_81 ) ) != 0 ) {
V_202 = F_233 ( V_9 , V_163 , V_199 , V_81 , V_201 ) ;
if ( V_202 < 0 )
return V_202 ;
V_81 = 0 ;
V_198 -= V_201 ;
V_199 += V_201 ;
++ V_163 ;
}
return 0 ;
}
int F_236 ( struct V_2 * V_3 , T_6 V_200 , const void * V_199 ,
unsigned long V_198 )
{
T_5 V_163 = V_200 >> V_142 ;
int V_201 ;
int V_81 = F_222 ( V_200 ) ;
int V_202 ;
while ( ( V_201 = F_216 ( V_198 , V_81 ) ) != 0 ) {
V_202 = F_234 ( V_3 , V_163 , V_199 , V_81 , V_201 ) ;
if ( V_202 < 0 )
return V_202 ;
V_81 = 0 ;
V_198 -= V_201 ;
V_199 += V_201 ;
++ V_163 ;
}
return 0 ;
}
int F_237 ( struct V_9 * V_9 , struct V_203 * V_204 ,
T_6 V_200 , unsigned long V_198 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_81 = F_222 ( V_200 ) ;
T_5 V_205 = V_200 >> V_142 ;
T_5 V_206 = ( V_200 + V_198 - 1 ) >> V_142 ;
T_5 V_207 = V_206 - V_205 + 1 ;
T_5 V_208 ;
V_204 -> V_200 = V_200 ;
V_204 -> V_59 = V_58 -> V_59 ;
V_204 -> V_198 = V_198 ;
V_204 -> V_64 = F_158 ( V_9 , V_205 ) ;
V_204 -> V_173 = F_173 ( V_204 -> V_64 , V_205 , NULL ) ;
if ( ! F_165 ( V_204 -> V_173 ) && V_207 <= 1 ) {
V_204 -> V_173 += V_81 ;
} else {
while ( V_205 <= V_206 ) {
V_204 -> V_64 = F_158 ( V_9 , V_205 ) ;
V_204 -> V_173 = F_173 ( V_204 -> V_64 , V_205 ,
& V_208 ) ;
if ( F_165 ( V_204 -> V_173 ) )
return - V_158 ;
V_205 += V_208 ;
}
V_204 -> V_64 = NULL ;
}
return 0 ;
}
int F_238 ( struct V_9 * V_9 , struct V_203 * V_204 ,
void * V_199 , unsigned long V_198 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
F_62 ( V_198 > V_204 -> V_198 ) ;
if ( V_58 -> V_59 != V_204 -> V_59 )
F_237 ( V_9 , V_204 , V_204 -> V_200 , V_204 -> V_198 ) ;
if ( F_25 ( ! V_204 -> V_64 ) )
return F_235 ( V_9 , V_204 -> V_200 , V_199 , V_198 ) ;
if ( F_165 ( V_204 -> V_173 ) )
return - V_158 ;
V_26 = F_231 ( ( void V_141 * ) V_204 -> V_173 , V_199 , V_198 ) ;
if ( V_26 )
return - V_158 ;
F_232 ( V_204 -> V_64 , V_204 -> V_200 >> V_142 ) ;
return 0 ;
}
int F_239 ( struct V_9 * V_9 , struct V_203 * V_204 ,
void * V_199 , unsigned long V_198 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
F_62 ( V_198 > V_204 -> V_198 ) ;
if ( V_58 -> V_59 != V_204 -> V_59 )
F_237 ( V_9 , V_204 , V_204 -> V_200 , V_204 -> V_198 ) ;
if ( F_25 ( ! V_204 -> V_64 ) )
return F_221 ( V_9 , V_204 -> V_200 , V_199 , V_198 ) ;
if ( F_165 ( V_204 -> V_173 ) )
return - V_158 ;
V_26 = F_218 ( V_199 , ( void V_141 * ) V_204 -> V_173 , V_198 ) ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_240 ( struct V_9 * V_9 , T_5 V_163 , int V_81 , int V_198 )
{
const void * V_209 = ( const void * ) F_241 ( F_242 ( F_243 ( 0 ) ) ) ;
return F_233 ( V_9 , V_163 , V_209 , V_81 , V_198 ) ;
}
int F_244 ( struct V_9 * V_9 , T_6 V_200 , unsigned long V_198 )
{
T_5 V_163 = V_200 >> V_142 ;
int V_201 ;
int V_81 = F_222 ( V_200 ) ;
int V_202 ;
while ( ( V_201 = F_216 ( V_198 , V_81 ) ) != 0 ) {
V_202 = F_240 ( V_9 , V_163 , V_81 , V_201 ) ;
if ( V_202 < 0 )
return V_202 ;
V_81 = 0 ;
V_198 -= V_201 ;
++ V_163 ;
}
return 0 ;
}
static void F_232 ( struct V_63 * V_64 ,
T_5 V_163 )
{
if ( V_64 && V_64 -> V_65 ) {
unsigned long V_210 = V_163 - V_64 -> V_120 ;
F_245 ( V_210 , V_64 -> V_65 ) ;
}
}
void F_246 ( struct V_9 * V_9 , T_5 V_163 )
{
struct V_63 * V_64 ;
V_64 = F_158 ( V_9 , V_163 ) ;
F_232 ( V_64 , V_163 ) ;
}
void F_247 ( struct V_2 * V_3 , T_5 V_163 )
{
struct V_63 * V_64 ;
V_64 = F_160 ( V_3 , V_163 ) ;
F_232 ( V_64 , V_163 ) ;
}
static void F_248 ( struct V_2 * V_3 )
{
unsigned int V_131 , V_211 , V_212 ;
V_131 = V_211 = V_3 -> V_213 ;
V_212 = F_249 ( V_214 ) ;
if ( V_211 == 0 && V_212 )
V_211 = 10000 ;
else
V_211 *= V_212 ;
if ( V_211 > V_213 )
V_211 = V_213 ;
V_3 -> V_213 = V_211 ;
F_250 ( V_3 -> V_27 , V_211 , V_131 ) ;
}
static void F_251 ( struct V_2 * V_3 )
{
unsigned int V_131 , V_211 , V_215 ;
V_131 = V_211 = V_3 -> V_213 ;
V_215 = F_249 ( V_216 ) ;
if ( V_215 == 0 )
V_211 = 0 ;
else
V_211 /= V_215 ;
V_3 -> V_213 = V_211 ;
F_252 ( V_3 -> V_27 , V_211 , V_131 ) ;
}
static int F_253 ( struct V_2 * V_3 )
{
if ( F_254 ( V_3 ) ) {
F_21 ( V_217 , V_3 ) ;
return - V_6 ;
}
if ( F_255 ( V_3 ) )
return - V_6 ;
if ( F_256 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_257 ( struct V_2 * V_3 )
{
T_7 V_50 , V_218 ;
F_258 ( V_219 ) ;
bool V_220 = false ;
T_8 V_221 ;
V_50 = V_218 = F_259 () ;
if ( V_3 -> V_213 ) {
T_7 V_222 = F_260 ( F_259 () , V_3 -> V_213 ) ;
++ V_3 -> V_21 . V_223 ;
do {
if ( F_253 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_224 ;
if ( ! F_261 ( V_3 ) )
++ V_3 -> V_21 . V_225 ;
goto V_134;
}
V_218 = F_259 () ;
} while ( F_262 () && F_263 ( V_218 , V_222 ) );
}
F_264 ( V_3 ) ;
for (; ; ) {
F_265 ( & V_3 -> V_29 , & V_219 , V_226 ) ;
if ( F_253 ( V_3 ) < 0 )
break;
V_220 = true ;
F_266 () ;
}
F_267 ( & V_3 -> V_29 , & V_219 ) ;
V_218 = F_259 () ;
F_268 ( V_3 ) ;
V_134:
V_221 = F_269 ( V_218 ) - F_269 ( V_50 ) ;
if ( ! F_261 ( V_3 ) )
F_251 ( V_3 ) ;
else if ( V_213 ) {
if ( V_221 <= V_3 -> V_213 )
;
else if ( V_3 -> V_213 && V_221 > V_213 )
F_251 ( V_3 ) ;
else if ( V_3 -> V_213 < V_213 &&
V_221 < V_213 )
F_248 ( V_3 ) ;
} else
V_3 -> V_213 = 0 ;
F_270 ( V_221 , V_220 , F_261 ( V_3 ) ) ;
F_271 ( V_3 ) ;
}
void F_272 ( struct V_2 * V_3 )
{
struct V_227 * V_228 ;
V_228 = F_273 ( V_3 ) ;
if ( F_274 ( V_228 ) ) {
F_275 ( V_228 ) ;
++ V_3 -> V_21 . V_229 ;
}
}
void F_276 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
F_272 ( V_3 ) ;
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_230 && F_277 ( V_4 ) )
if ( F_278 ( V_3 ) )
F_279 ( V_4 ) ;
F_10 () ;
}
int F_280 ( struct V_2 * V_231 )
{
struct V_28 * V_28 ;
struct V_232 * V_233 = NULL ;
int V_202 = 0 ;
F_281 () ;
V_28 = F_282 ( V_231 -> V_28 ) ;
if ( V_28 )
V_233 = F_283 ( V_28 , V_234 ) ;
F_284 () ;
if ( ! V_233 )
return V_202 ;
V_202 = F_285 ( V_233 , 1 ) ;
F_286 ( V_233 ) ;
return V_202 ;
}
static bool F_287 ( struct V_2 * V_3 )
{
#ifdef F_288
bool V_235 ;
V_235 = ! V_3 -> V_236 . V_237 ||
V_3 -> V_236 . V_238 ;
if ( V_3 -> V_236 . V_237 )
F_41 ( V_3 , ! V_3 -> V_236 . V_238 ) ;
return V_235 ;
#else
return true ;
#endif
}
void F_289 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_239 = V_12 -> V_9 -> V_239 ;
int V_240 = 0 ;
int V_241 = 3 ;
int V_242 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_242 = 0 ; V_242 < 2 && ! V_240 && V_241 ; V_242 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_242 && V_11 <= V_239 ) {
V_11 = V_239 ;
continue;
} else if ( V_242 && V_11 > V_239 )
break;
if ( ! F_290 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_274 ( & V_3 -> V_29 ) && ! F_254 ( V_3 ) )
continue;
if ( ! F_287 ( V_3 ) )
continue;
V_240 = F_280 ( V_3 ) ;
if ( V_240 > 0 ) {
V_9 -> V_239 = V_11 ;
break;
} else if ( V_240 < 0 ) {
V_241 -- ;
if ( ! V_241 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_291 ( struct V_164 * V_165 , struct V_243 * V_244 )
{
struct V_2 * V_3 = V_165 -> V_245 -> V_115 ;
struct V_25 * V_25 ;
if ( V_244 -> V_246 == 0 )
V_25 = F_292 ( V_3 -> V_36 ) ;
#ifdef F_293
else if ( V_244 -> V_246 == V_247 )
V_25 = F_292 ( V_3 -> V_152 . V_248 ) ;
#endif
#ifdef F_294
else if ( V_244 -> V_246 == F_294 )
V_25 = F_292 ( V_3 -> V_9 -> V_249 ) ;
#endif
else
return F_295 ( V_3 , V_244 ) ;
F_215 ( V_25 ) ;
V_244 -> V_25 = V_25 ;
return 0 ;
}
static int F_296 ( struct V_113 * V_113 , struct V_164 * V_165 )
{
V_165 -> V_250 = & V_251 ;
return 0 ;
}
static int F_297 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
F_123 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_298 ( struct V_2 * V_3 )
{
return F_299 ( L_2 , & V_252 , V_3 , V_253 | V_254 ) ;
}
static int F_300 ( struct V_9 * V_9 , T_4 V_24 )
{
int V_26 ;
struct V_2 * V_3 ;
if ( V_24 >= V_255 )
return - V_127 ;
V_3 = F_301 ( V_9 , V_24 ) ;
if ( F_302 ( V_3 ) )
return F_303 ( V_3 ) ;
F_304 ( & V_3 -> V_7 , & V_256 ) ;
V_26 = F_305 ( V_3 ) ;
if ( V_26 )
goto V_257;
F_149 ( & V_9 -> V_85 ) ;
if ( ! F_306 ( V_3 ) ) {
V_26 = - V_127 ;
goto V_258;
}
if ( F_307 ( & V_9 -> V_259 ) == V_260 ) {
V_26 = - V_127 ;
goto V_258;
}
if ( F_308 ( V_9 , V_24 ) ) {
V_26 = - V_148 ;
goto V_258;
}
F_62 ( V_9 -> V_261 [ F_307 ( & V_9 -> V_259 ) ] ) ;
F_122 ( V_9 ) ;
V_26 = F_298 ( V_3 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
goto V_258;
}
V_9 -> V_261 [ F_307 ( & V_9 -> V_259 ) ] = V_3 ;
F_61 () ;
F_94 ( & V_9 -> V_259 ) ;
F_16 ( & V_9 -> V_85 ) ;
F_309 ( V_3 ) ;
return V_26 ;
V_258:
F_16 ( & V_9 -> V_85 ) ;
V_257:
F_310 ( V_3 ) ;
return V_26 ;
}
static int F_311 ( struct V_2 * V_3 , T_9 * V_262 )
{
if ( V_262 ) {
F_312 ( V_262 , F_313 ( V_263 ) | F_313 ( V_264 ) ) ;
V_3 -> V_265 = 1 ;
V_3 -> V_262 = * V_262 ;
} else
V_3 -> V_265 = 0 ;
return 0 ;
}
static long F_314 ( struct V_113 * V_114 ,
unsigned int V_266 , unsigned long V_267 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
void V_141 * V_268 = ( void V_141 * ) V_267 ;
int V_26 ;
struct V_269 * V_270 = NULL ;
struct V_271 * V_271 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_272 ;
if ( F_25 ( F_315 ( V_266 ) != V_273 ) )
return - V_127 ;
#if F_118 ( V_274 ) || F_118 ( V_275 ) || F_118 ( V_276 )
if ( V_266 == V_277 || V_266 == V_278 || V_266 == V_279 )
return F_316 ( V_114 , V_266 , V_267 ) ;
#endif
V_26 = F_5 ( V_3 ) ;
if ( V_26 )
return V_26 ;
switch ( V_266 ) {
case V_280 :
V_26 = - V_127 ;
if ( V_267 )
goto V_134;
if ( F_25 ( V_3 -> V_28 != V_56 -> V_281 [ V_234 ] . V_28 ) ) {
struct V_28 * V_282 = V_3 -> V_28 ;
struct V_28 * V_283 = F_317 ( V_56 , V_234 ) ;
F_136 ( V_3 -> V_28 , V_283 ) ;
if ( V_282 )
F_318 () ;
F_45 ( V_282 ) ;
}
V_26 = F_319 ( V_3 , V_3 -> V_36 ) ;
F_320 ( V_3 -> V_36 -> V_284 , V_26 ) ;
break;
case V_285 : {
struct V_286 * V_286 ;
V_26 = - V_34 ;
V_286 = F_88 ( sizeof( struct V_286 ) , V_32 ) ;
if ( ! V_286 )
goto V_134;
V_26 = F_321 ( V_3 , V_286 ) ;
if ( V_26 )
goto V_287;
V_26 = - V_158 ;
if ( F_152 ( V_268 , V_286 , sizeof( struct V_286 ) ) )
goto V_287;
V_26 = 0 ;
V_287:
F_82 ( V_286 ) ;
break;
}
case V_288 : {
struct V_286 * V_286 ;
V_26 = - V_34 ;
V_286 = F_322 ( V_268 , sizeof( * V_286 ) ) ;
if ( F_302 ( V_286 ) ) {
V_26 = F_303 ( V_286 ) ;
goto V_134;
}
V_26 = F_323 ( V_3 , V_286 ) ;
F_82 ( V_286 ) ;
break;
}
case V_289 : {
V_271 = F_88 ( sizeof( struct V_271 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_271 )
goto V_134;
V_26 = F_324 ( V_3 , V_271 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_268 , V_271 , sizeof( struct V_271 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_290 : {
V_271 = F_322 ( V_268 , sizeof( * V_271 ) ) ;
if ( F_302 ( V_271 ) ) {
V_26 = F_303 ( V_271 ) ;
V_271 = NULL ;
goto V_134;
}
V_26 = F_325 ( V_3 , V_271 ) ;
break;
}
case V_291 : {
struct V_292 V_293 ;
V_26 = F_326 ( V_3 , & V_293 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_268 , & V_293 , sizeof( V_293 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_294 : {
struct V_292 V_293 ;
V_26 = - V_158 ;
if ( F_327 ( & V_293 , V_268 , sizeof( V_293 ) ) )
goto V_134;
V_26 = F_328 ( V_3 , & V_293 ) ;
break;
}
case V_295 : {
struct V_296 V_297 ;
V_26 = - V_158 ;
if ( F_327 ( & V_297 , V_268 , sizeof( V_297 ) ) )
goto V_134;
V_26 = F_329 ( V_3 , & V_297 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_268 , & V_297 , sizeof( V_297 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_298 : {
struct V_299 V_300 ;
V_26 = - V_158 ;
if ( F_327 ( & V_300 , V_268 , sizeof( V_300 ) ) )
goto V_134;
V_26 = F_330 ( V_3 , & V_300 ) ;
break;
}
case V_301 : {
struct V_302 V_141 * V_303 = V_268 ;
struct V_302 V_304 ;
T_9 V_262 , * V_77 ;
V_77 = NULL ;
if ( V_268 ) {
V_26 = - V_158 ;
if ( F_327 ( & V_304 , V_268 ,
sizeof( V_304 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_304 . V_198 != sizeof( V_262 ) )
goto V_134;
V_26 = - V_158 ;
if ( F_327 ( & V_262 , V_303 -> V_262 ,
sizeof( V_262 ) ) )
goto V_134;
V_77 = & V_262 ;
}
V_26 = F_311 ( V_3 , V_77 ) ;
break;
}
case V_305 : {
V_270 = F_88 ( sizeof( struct V_269 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_270 )
goto V_134;
V_26 = F_331 ( V_3 , V_270 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_268 , V_270 , sizeof( struct V_269 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_306 : {
V_270 = F_322 ( V_268 , sizeof( * V_270 ) ) ;
if ( F_302 ( V_270 ) ) {
V_26 = F_303 ( V_270 ) ;
V_270 = NULL ;
goto V_134;
}
V_26 = F_332 ( V_3 , V_270 ) ;
break;
}
default:
V_26 = F_316 ( V_114 , V_266 , V_267 ) ;
}
V_134:
F_11 ( V_3 ) ;
F_82 ( V_270 ) ;
F_82 ( V_271 ) ;
return V_26 ;
}
static long F_333 ( struct V_113 * V_114 ,
unsigned int V_266 , unsigned long V_267 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
void V_141 * V_268 = F_334 ( V_267 ) ;
int V_26 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_272 ;
switch ( V_266 ) {
case V_301 : {
struct V_302 V_141 * V_303 = V_268 ;
struct V_302 V_304 ;
T_10 V_307 ;
T_9 V_262 ;
if ( V_268 ) {
V_26 = - V_158 ;
if ( F_327 ( & V_304 , V_268 ,
sizeof( V_304 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_304 . V_198 != sizeof( V_307 ) )
goto V_134;
V_26 = - V_158 ;
if ( F_327 ( & V_307 , V_303 -> V_262 ,
sizeof( V_307 ) ) )
goto V_134;
F_335 ( & V_262 , & V_307 ) ;
V_26 = F_311 ( V_3 , & V_262 ) ;
} else
V_26 = F_311 ( V_3 , NULL ) ;
break;
}
default:
V_26 = F_314 ( V_114 , V_266 , V_267 ) ;
}
V_134:
return V_26 ;
}
static int F_336 ( struct V_105 * V_106 ,
int (* F_337)( struct V_105 * V_106 ,
struct V_308 * V_309 ) ,
unsigned long V_267 )
{
struct V_308 V_309 ;
if ( ! F_337 )
return - V_310 ;
if ( F_327 ( & V_309 , ( void V_141 * ) V_267 , sizeof( V_309 ) ) )
return - V_158 ;
return F_337 ( V_106 , & V_309 ) ;
}
static long F_338 ( struct V_113 * V_114 , unsigned int V_266 ,
unsigned long V_267 )
{
struct V_105 * V_106 = V_114 -> V_115 ;
switch ( V_266 ) {
case V_311 :
return F_336 ( V_106 , V_106 -> V_54 -> V_312 , V_267 ) ;
case V_313 :
return F_336 ( V_106 , V_106 -> V_54 -> V_314 , V_267 ) ;
case V_315 :
return F_336 ( V_106 , V_106 -> V_54 -> V_316 , V_267 ) ;
default:
if ( V_106 -> V_54 -> V_266 )
return V_106 -> V_54 -> V_266 ( V_106 , V_266 , V_267 ) ;
return - V_317 ;
}
}
static int F_339 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
struct V_105 * V_106 = V_114 -> V_115 ;
struct V_9 * V_9 = V_106 -> V_9 ;
F_123 ( V_9 ) ;
return 0 ;
}
struct V_105 * F_340 ( struct V_113 * V_114 )
{
if ( V_114 -> V_318 != & V_319 )
return NULL ;
return V_114 -> V_115 ;
}
int F_341 ( struct V_320 * V_54 , T_4 type )
{
if ( type >= F_342 ( V_321 ) )
return - V_322 ;
if ( V_321 [ type ] != NULL )
return - V_148 ;
V_321 [ type ] = V_54 ;
return 0 ;
}
void F_343 ( T_4 type )
{
if ( V_321 [ type ] != NULL )
V_321 [ type ] = NULL ;
}
static int F_344 ( struct V_9 * V_9 ,
struct V_323 * V_324 )
{
struct V_320 * V_54 = NULL ;
struct V_105 * V_106 ;
bool V_325 = V_324 -> V_126 & V_326 ;
int V_202 ;
if ( V_324 -> type >= F_342 ( V_321 ) )
return - V_327 ;
V_54 = V_321 [ V_324 -> type ] ;
if ( V_54 == NULL )
return - V_327 ;
if ( V_325 )
return 0 ;
V_106 = F_88 ( sizeof( * V_106 ) , V_32 ) ;
if ( ! V_106 )
return - V_34 ;
V_106 -> V_54 = V_54 ;
V_106 -> V_9 = V_9 ;
V_202 = V_54 -> V_328 ( V_106 , V_324 -> type ) ;
if ( V_202 < 0 ) {
F_82 ( V_106 ) ;
return V_202 ;
}
V_202 = F_299 ( V_54 -> V_80 , & V_319 , V_106 , V_253 | V_254 ) ;
if ( V_202 < 0 ) {
V_54 -> V_109 ( V_106 ) ;
return V_202 ;
}
F_103 ( & V_106 -> V_108 , & V_9 -> V_89 ) ;
F_122 ( V_9 ) ;
V_324 -> V_71 = V_202 ;
return 0 ;
}
static long F_345 ( struct V_9 * V_9 , long V_267 )
{
switch ( V_267 ) {
case V_329 :
case V_330 :
case V_331 :
case V_332 :
#ifdef F_346
case V_333 :
#endif
#ifdef F_99
case V_334 :
case V_335 :
#endif
case V_336 :
case V_337 :
return 1 ;
#ifdef F_347
case V_338 :
return V_339 ;
#endif
#if V_93 > 1
case V_340 :
return V_93 ;
#endif
case V_341 :
return V_255 ;
default:
break;
}
return F_348 ( V_9 , V_267 ) ;
}
static long F_349 ( struct V_113 * V_114 ,
unsigned int V_266 , unsigned long V_267 )
{
struct V_9 * V_9 = V_114 -> V_115 ;
void V_141 * V_268 = ( void V_141 * ) V_267 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_272 ;
switch ( V_266 ) {
case V_342 :
V_26 = F_300 ( V_9 , V_267 ) ;
break;
case V_343 : {
struct V_121 V_344 ;
V_26 = - V_158 ;
if ( F_327 ( & V_344 , V_268 ,
sizeof( V_344 ) ) )
goto V_134;
V_26 = F_150 ( V_9 , & V_344 ) ;
break;
}
case V_345 : {
struct V_153 log ;
V_26 = - V_158 ;
if ( F_327 ( & log , V_268 , sizeof( log ) ) )
goto V_134;
V_26 = F_350 ( V_9 , & log ) ;
break;
}
#ifdef F_294
case V_346 : {
struct V_347 V_348 ;
V_26 = - V_158 ;
if ( F_327 ( & V_348 , V_268 , sizeof( V_348 ) ) )
goto V_134;
V_26 = F_351 ( V_9 , & V_348 ) ;
break;
}
case V_349 : {
struct V_347 V_348 ;
V_26 = - V_158 ;
if ( F_327 ( & V_348 , V_268 , sizeof( V_348 ) ) )
goto V_134;
V_26 = F_352 ( V_9 , & V_348 ) ;
break;
}
#endif
case V_350 : {
struct V_351 V_199 ;
V_26 = - V_158 ;
if ( F_327 ( & V_199 , V_268 , sizeof( V_199 ) ) )
goto V_134;
V_26 = V_351 ( V_9 , & V_199 ) ;
break;
}
case V_352 : {
struct V_353 V_199 ;
V_26 = - V_158 ;
if ( F_327 ( & V_199 , V_268 , sizeof( V_199 ) ) )
goto V_134;
V_26 = V_353 ( V_9 , & V_199 ) ;
break;
}
#ifdef F_346
case V_354 : {
struct V_355 V_356 ;
V_26 = - V_158 ;
if ( F_327 ( & V_356 , V_268 , sizeof( V_356 ) ) )
goto V_134;
V_26 = F_353 ( V_9 , & V_356 ) ;
break;
}
#endif
#ifdef F_354
case V_357 :
case V_358 : {
struct V_359 V_360 ;
V_26 = - V_158 ;
if ( F_327 ( & V_360 , V_268 , sizeof( V_360 ) ) )
goto V_134;
V_26 = F_355 ( V_9 , & V_360 ,
V_266 == V_357 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( V_266 == V_357 ) {
if ( F_152 ( V_268 , & V_360 , sizeof( V_360 ) ) )
goto V_134;
}
V_26 = 0 ;
break;
}
#endif
#ifdef F_347
case V_361 : {
struct V_362 V_363 ;
struct V_362 V_141 * V_364 ;
struct V_365 * V_366 = NULL ;
V_26 = - V_158 ;
if ( F_327 ( & V_363 , V_268 , sizeof( V_363 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_363 . V_367 > V_339 )
goto V_134;
if ( V_363 . V_126 )
goto V_134;
if ( V_363 . V_367 ) {
V_26 = - V_34 ;
V_366 = F_356 ( V_363 . V_367 * sizeof( * V_366 ) ) ;
if ( ! V_366 )
goto V_134;
V_26 = - V_158 ;
V_364 = V_268 ;
if ( F_327 ( V_366 , V_364 -> V_366 ,
V_363 . V_367 * sizeof( * V_366 ) ) )
goto V_368;
}
V_26 = F_357 ( V_9 , V_366 , V_363 . V_367 ,
V_363 . V_126 ) ;
V_368:
F_358 ( V_366 ) ;
break;
}
#endif
case V_369 : {
struct V_323 V_324 ;
V_26 = - V_158 ;
if ( F_327 ( & V_324 , V_268 , sizeof( V_324 ) ) )
goto V_134;
V_26 = F_344 ( V_9 , & V_324 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_268 , & V_324 , sizeof( V_324 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_370 :
V_26 = F_345 ( V_9 , V_267 ) ;
break;
default:
V_26 = F_359 ( V_114 , V_266 , V_267 ) ;
}
V_134:
return V_26 ;
}
static long F_360 ( struct V_113 * V_114 ,
unsigned int V_266 , unsigned long V_267 )
{
struct V_9 * V_9 = V_114 -> V_115 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_272 ;
switch ( V_266 ) {
case V_345 : {
struct V_371 V_372 ;
struct V_153 log ;
V_26 = - V_158 ;
if ( F_327 ( & V_372 , ( void V_141 * ) V_267 ,
sizeof( V_372 ) ) )
goto V_134;
log . V_130 = V_372 . V_130 ;
log . V_373 = V_372 . V_373 ;
log . V_374 = V_372 . V_374 ;
log . V_65 = F_334 ( V_372 . V_65 ) ;
V_26 = F_350 ( V_9 , & log ) ;
break;
}
default:
V_26 = F_349 ( V_114 , V_266 , V_267 ) ;
}
V_134:
return V_26 ;
}
static int F_361 ( unsigned long type )
{
int V_26 ;
struct V_9 * V_9 ;
V_9 = F_90 ( type ) ;
if ( F_302 ( V_9 ) )
return F_303 ( V_9 ) ;
#ifdef F_294
V_26 = F_362 ( V_9 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
return V_26 ;
}
#endif
V_26 = F_299 ( L_3 , & V_375 , V_9 , V_253 | V_254 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
return V_26 ;
}
if ( F_83 ( V_9 , V_26 ) < 0 ) {
F_123 ( V_9 ) ;
return - V_34 ;
}
return V_26 ;
}
static long F_363 ( struct V_113 * V_114 ,
unsigned int V_266 , unsigned long V_267 )
{
long V_26 = - V_127 ;
switch ( V_266 ) {
case V_376 :
if ( V_267 )
goto V_134;
V_26 = V_377 ;
break;
case V_378 :
V_26 = F_361 ( V_267 ) ;
break;
case V_370 :
V_26 = F_345 ( NULL , V_267 ) ;
break;
case V_379 :
if ( V_267 )
goto V_134;
V_26 = V_104 ;
#ifdef F_293
V_26 += V_104 ;
#endif
#ifdef F_294
V_26 += V_104 ;
#endif
break;
case V_380 :
case V_381 :
case V_382 :
V_26 = - V_383 ;
break;
default:
return F_364 ( V_114 , V_266 , V_267 ) ;
}
V_134:
return V_26 ;
}
static void F_365 ( void * V_384 )
{
int V_4 = F_366 () ;
int V_26 ;
if ( F_367 ( V_4 , V_385 ) )
return;
F_24 ( V_4 , V_385 ) ;
V_26 = F_368 () ;
if ( V_26 ) {
F_369 ( V_4 , V_385 ) ;
F_94 ( & V_386 ) ;
F_370 ( L_4 , V_4 ) ;
}
}
static void F_371 ( void )
{
F_372 ( & V_387 ) ;
if ( V_388 )
F_365 ( NULL ) ;
F_373 ( & V_387 ) ;
}
static void F_374 ( void * V_384 )
{
int V_4 = F_366 () ;
if ( ! F_367 ( V_4 , V_385 ) )
return;
F_369 ( V_4 , V_385 ) ;
F_375 () ;
}
static void F_376 ( void )
{
F_372 ( & V_387 ) ;
if ( V_388 )
F_374 ( NULL ) ;
F_373 ( & V_387 ) ;
}
static void F_377 ( void )
{
F_62 ( ! V_388 ) ;
V_388 -- ;
if ( ! V_388 )
F_378 ( F_374 , NULL , 1 ) ;
}
static void F_106 ( void )
{
F_372 ( & V_387 ) ;
F_377 () ;
F_373 ( & V_387 ) ;
}
static int F_98 ( void )
{
int V_26 = 0 ;
F_372 ( & V_387 ) ;
V_388 ++ ;
if ( V_388 == 1 ) {
F_96 ( & V_386 , 0 ) ;
F_378 ( F_365 , NULL , 1 ) ;
if ( F_307 ( & V_386 ) ) {
F_377 () ;
V_26 = - V_389 ;
}
}
F_373 ( & V_387 ) ;
return V_26 ;
}
static int F_379 ( struct V_390 * V_391 , unsigned long V_211 ,
void * V_392 )
{
V_211 &= ~ V_393 ;
switch ( V_211 ) {
case V_394 :
F_376 () ;
break;
case V_395 :
F_371 () ;
break;
}
return V_396 ;
}
static int F_380 ( struct V_390 * V_391 , unsigned long V_211 ,
void * V_392 )
{
F_370 ( L_5 ) ;
V_397 = true ;
F_378 ( F_374 , NULL , 1 ) ;
return V_396 ;
}
static void F_116 ( struct V_99 * V_398 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_398 -> V_399 ; V_11 ++ ) {
struct V_400 * V_401 = V_398 -> V_402 [ V_11 ] . V_106 ;
F_381 ( V_401 ) ;
}
F_82 ( V_398 ) ;
}
static inline int F_382 ( const struct V_403 * V_404 ,
const struct V_403 * V_405 )
{
T_6 V_406 = V_404 -> V_166 ;
T_6 V_407 = V_405 -> V_166 ;
if ( V_406 < V_407 )
return - 1 ;
if ( V_405 -> V_198 ) {
V_406 += V_404 -> V_198 ;
V_407 += V_405 -> V_198 ;
}
if ( V_406 > V_407 )
return 1 ;
return 0 ;
}
static int F_383 ( const void * V_408 , const void * V_409 )
{
return F_382 ( V_408 , V_409 ) ;
}
static int F_384 ( struct V_99 * V_398 , struct V_400 * V_106 ,
T_6 V_166 , int V_198 )
{
V_398 -> V_402 [ V_398 -> V_399 ++ ] = (struct V_403 ) {
. V_166 = V_166 ,
. V_198 = V_198 ,
. V_106 = V_106 ,
} ;
F_385 ( V_398 -> V_402 , V_398 -> V_399 , sizeof( struct V_403 ) ,
F_383 , NULL ) ;
return 0 ;
}
static int F_386 ( struct V_99 * V_398 ,
T_6 V_166 , int V_198 )
{
struct V_403 * V_402 , V_410 ;
int V_411 ;
V_410 = (struct V_403 ) {
. V_166 = V_166 ,
. V_198 = V_198 ,
} ;
V_402 = bsearch ( & V_410 , V_398 -> V_402 , V_398 -> V_399 ,
sizeof( struct V_403 ) , F_383 ) ;
if ( V_402 == NULL )
return - V_157 ;
V_411 = V_402 - V_398 -> V_402 ;
while ( V_411 > 0 && F_382 ( & V_410 , & V_398 -> V_402 [ V_411 - 1 ] ) == 0 )
V_411 -- ;
return V_411 ;
}
static int F_387 ( struct V_2 * V_3 , struct V_99 * V_398 ,
struct V_403 * V_402 , const void * V_211 )
{
int V_45 ;
V_45 = F_386 ( V_398 , V_402 -> V_166 , V_402 -> V_198 ) ;
if ( V_45 < 0 )
return - V_383 ;
while ( V_45 < V_398 -> V_399 &&
F_382 ( V_402 , & V_398 -> V_402 [ V_45 ] ) == 0 ) {
if ( ! F_388 ( V_3 , V_398 -> V_402 [ V_45 ] . V_106 , V_402 -> V_166 ,
V_402 -> V_198 , V_211 ) )
return V_45 ;
V_45 ++ ;
}
return - V_383 ;
}
int F_389 ( struct V_2 * V_3 , enum V_412 V_413 , T_6 V_166 ,
int V_198 , const void * V_211 )
{
struct V_99 * V_398 ;
struct V_403 V_402 ;
int V_26 ;
V_402 = (struct V_403 ) {
. V_166 = V_166 ,
. V_198 = V_198 ,
} ;
V_398 = F_390 ( V_3 -> V_9 -> V_98 [ V_413 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_387 ( V_3 , V_398 , & V_402 , V_211 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_391 ( struct V_2 * V_3 , enum V_412 V_413 ,
T_6 V_166 , int V_198 , const void * V_211 , long V_414 )
{
struct V_99 * V_398 ;
struct V_403 V_402 ;
V_402 = (struct V_403 ) {
. V_166 = V_166 ,
. V_198 = V_198 ,
} ;
V_398 = F_390 ( V_3 -> V_9 -> V_98 [ V_413 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ( V_414 >= 0 ) && ( V_414 < V_398 -> V_399 ) &&
( F_382 ( & V_402 , & V_398 -> V_402 [ V_414 ] ) == 0 ) )
if ( ! F_388 ( V_3 , V_398 -> V_402 [ V_414 ] . V_106 , V_166 , V_198 ,
V_211 ) )
return V_414 ;
return F_387 ( V_3 , V_398 , & V_402 , V_211 ) ;
}
static int F_392 ( struct V_2 * V_3 , struct V_99 * V_398 ,
struct V_403 * V_402 , void * V_211 )
{
int V_45 ;
V_45 = F_386 ( V_398 , V_402 -> V_166 , V_402 -> V_198 ) ;
if ( V_45 < 0 )
return - V_383 ;
while ( V_45 < V_398 -> V_399 &&
F_382 ( V_402 , & V_398 -> V_402 [ V_45 ] ) == 0 ) {
if ( ! F_393 ( V_3 , V_398 -> V_402 [ V_45 ] . V_106 , V_402 -> V_166 ,
V_402 -> V_198 , V_211 ) )
return V_45 ;
V_45 ++ ;
}
return - V_383 ;
}
int F_394 ( struct V_2 * V_3 , enum V_412 V_413 , T_6 V_166 ,
int V_198 , void * V_211 )
{
struct V_99 * V_398 ;
struct V_403 V_402 ;
int V_26 ;
V_402 = (struct V_403 ) {
. V_166 = V_166 ,
. V_198 = V_198 ,
} ;
V_398 = F_390 ( V_3 -> V_9 -> V_98 [ V_413 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_392 ( V_3 , V_398 , & V_402 , V_211 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_395 ( struct V_9 * V_9 , enum V_412 V_413 , T_6 V_166 ,
int V_198 , struct V_400 * V_106 )
{
struct V_99 * V_415 , * V_398 ;
V_398 = V_9 -> V_98 [ V_413 ] ;
if ( V_398 -> V_399 - V_398 -> V_416 > V_417 - 1 )
return - V_322 ;
V_415 = F_396 ( sizeof( * V_398 ) + ( ( V_398 -> V_399 + 1 ) *
sizeof( struct V_403 ) ) , V_32 ) ;
if ( ! V_415 )
return - V_34 ;
memcpy ( V_415 , V_398 , sizeof( * V_398 ) + ( V_398 -> V_399 *
sizeof( struct V_403 ) ) ) ;
F_384 ( V_415 , V_106 , V_166 , V_198 ) ;
F_136 ( V_9 -> V_98 [ V_413 ] , V_415 ) ;
F_137 ( & V_9 -> V_46 ) ;
F_82 ( V_398 ) ;
return 0 ;
}
int F_397 ( struct V_9 * V_9 , enum V_412 V_413 ,
struct V_400 * V_106 )
{
int V_11 , V_26 ;
struct V_99 * V_415 , * V_398 ;
V_398 = V_9 -> V_98 [ V_413 ] ;
V_26 = - V_157 ;
for ( V_11 = 0 ; V_11 < V_398 -> V_399 ; V_11 ++ )
if ( V_398 -> V_402 [ V_11 ] . V_106 == V_106 ) {
V_26 = 0 ;
break;
}
if ( V_26 )
return V_26 ;
V_415 = F_396 ( sizeof( * V_398 ) + ( ( V_398 -> V_399 - 1 ) *
sizeof( struct V_403 ) ) , V_32 ) ;
if ( ! V_415 )
return - V_34 ;
memcpy ( V_415 , V_398 , sizeof( * V_398 ) + V_11 * sizeof( struct V_403 ) ) ;
V_415 -> V_399 -- ;
memcpy ( V_415 -> V_402 + V_11 , V_398 -> V_402 + V_11 + 1 ,
( V_415 -> V_399 - V_11 ) * sizeof( struct V_403 ) ) ;
F_136 ( V_9 -> V_98 [ V_413 ] , V_415 ) ;
F_137 ( & V_9 -> V_46 ) ;
F_82 ( V_398 ) ;
return V_26 ;
}
static int F_398 ( struct V_112 * V_112 , struct V_113 * V_113 ,
int (* F_399)( void * , T_8 * ) , int (* F_400)( void * , T_8 ) ,
const char * V_418 )
{
struct V_74 * V_75 = (struct V_74 * )
V_112 -> V_419 ;
if ( ! F_401 ( & V_75 -> V_9 -> V_88 , 1 , 0 ) )
return - V_157 ;
if ( F_402 ( V_112 , V_113 , F_399 , F_400 , V_418 ) ) {
F_123 ( V_75 -> V_9 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_403 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
struct V_74 * V_75 = (struct V_74 * )
V_112 -> V_419 ;
F_404 ( V_112 , V_113 ) ;
F_123 ( V_75 -> V_9 ) ;
return 0 ;
}
static int F_405 ( void * V_199 , T_8 * V_211 )
{
struct V_74 * V_75 = (struct V_74 * ) V_199 ;
* V_211 = * ( T_4 * ) ( ( void * ) V_75 -> V_9 + V_75 -> V_81 ) ;
return 0 ;
}
static int F_406 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
F_407 ( L_6 , 0ull ) ;
return F_398 ( V_112 , V_113 , F_405 ,
NULL , L_6 ) ;
}
static int F_408 ( void * V_199 , T_8 * V_211 )
{
int V_11 ;
struct V_74 * V_75 = (struct V_74 * ) V_199 ;
struct V_2 * V_3 ;
* V_211 = 0 ;
F_20 ( V_11 , V_3 , V_75 -> V_9 )
* V_211 += * ( T_4 * ) ( ( void * ) V_3 + V_75 -> V_81 ) ;
return 0 ;
}
static int F_409 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
F_407 ( L_6 , 0ull ) ;
return F_398 ( V_112 , V_113 , F_408 ,
NULL , L_6 ) ;
}
static int F_410 ( void * V_420 , T_8 * V_211 )
{
unsigned V_81 = ( long ) V_420 ;
struct V_9 * V_9 ;
struct V_74 V_421 = { . V_81 = V_81 } ;
T_8 V_422 ;
* V_211 = 0 ;
F_51 ( & V_101 ) ;
F_411 (kvm, &vm_list, vm_list) {
V_421 . V_9 = V_9 ;
F_405 ( ( void * ) & V_421 , & V_422 ) ;
* V_211 += V_422 ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_412 ( void * V_420 , T_8 * V_211 )
{
unsigned V_81 = ( long ) V_420 ;
struct V_9 * V_9 ;
struct V_74 V_421 = { . V_81 = V_81 } ;
T_8 V_422 ;
* V_211 = 0 ;
F_51 ( & V_101 ) ;
F_411 (kvm, &vm_list, vm_list) {
V_421 . V_9 = V_9 ;
F_408 ( ( void * ) & V_421 , & V_422 ) ;
* V_211 += V_422 ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_413 ( void )
{
int V_26 = - V_148 ;
struct V_76 * V_77 ;
V_78 = F_86 ( L_7 , NULL ) ;
if ( V_78 == NULL )
goto V_134;
V_69 = 0 ;
for ( V_77 = V_79 ; V_77 -> V_80 ; ++ V_77 , V_69 ++ ) {
if ( ! F_89 ( V_77 -> V_80 , 0444 , V_78 ,
( void * ) ( long ) V_77 -> V_81 ,
V_423 [ V_77 -> V_83 ] ) )
goto V_424;
}
return 0 ;
V_424:
F_81 ( V_78 ) ;
V_134:
return V_26 ;
}
static int F_414 ( void )
{
if ( V_388 )
F_374 ( NULL ) ;
return 0 ;
}
static void F_415 ( void )
{
if ( V_388 ) {
F_130 ( F_416 ( & V_387 ) ) ;
F_365 ( NULL ) ;
}
}
static inline
struct V_2 * F_417 ( struct V_7 * V_425 )
{
return F_48 ( V_425 , struct V_2 , V_7 ) ;
}
static void F_418 ( struct V_7 * V_425 , int V_4 )
{
struct V_2 * V_3 = F_417 ( V_425 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_419 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_420 ( struct V_7 * V_425 ,
struct V_232 * V_426 )
{
struct V_2 * V_3 = F_417 ( V_425 ) ;
if ( V_56 -> V_427 == V_428 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_421 ( void * V_429 , unsigned V_430 , unsigned V_431 ,
struct V_432 * V_432 )
{
int V_26 ;
int V_4 ;
V_26 = F_422 ( V_429 ) ;
if ( V_26 )
goto V_433;
V_26 = F_423 () ;
if ( V_26 )
goto V_434;
if ( ! F_19 ( & V_385 , V_32 ) ) {
V_26 = - V_34 ;
goto V_435;
}
V_26 = F_424 () ;
if ( V_26 < 0 )
goto V_436;
F_425 (cpu) {
F_426 ( V_4 ,
V_437 ,
& V_26 , 1 ) ;
if ( V_26 < 0 )
goto V_438;
}
V_26 = F_427 ( & V_439 ) ;
if ( V_26 )
goto V_440;
F_428 ( & V_441 ) ;
if ( ! V_431 )
V_431 = F_429 ( struct V_2 ) ;
V_442 = F_430 ( L_8 , V_430 , V_431 ,
0 , NULL ) ;
if ( ! V_442 ) {
V_26 = - V_34 ;
goto V_443;
}
V_26 = F_431 () ;
if ( V_26 )
goto V_149;
V_444 . V_445 = V_432 ;
V_375 . V_445 = V_432 ;
V_252 . V_445 = V_432 ;
V_26 = F_432 ( & V_446 ) ;
if ( V_26 ) {
F_433 ( L_9 ) ;
goto V_447;
}
F_434 ( & V_448 ) ;
V_256 . V_449 = F_418 ;
V_256 . V_450 = F_420 ;
V_26 = F_413 () ;
if ( V_26 ) {
F_433 ( L_10 ) ;
goto V_451;
}
V_26 = F_435 () ;
F_130 ( V_26 ) ;
return 0 ;
V_451:
F_436 ( & V_448 ) ;
F_437 ( & V_446 ) ;
V_447:
F_438 () ;
V_149:
F_439 ( V_442 ) ;
V_443:
F_440 ( & V_441 ) ;
F_441 ( & V_439 ) ;
V_440:
V_438:
F_442 () ;
V_436:
F_28 ( V_385 ) ;
V_435:
F_443 () ;
V_434:
F_444 () ;
V_433:
return V_26 ;
}
void F_445 ( void )
{
F_81 ( V_78 ) ;
F_437 ( & V_446 ) ;
F_439 ( V_442 ) ;
F_438 () ;
F_436 ( & V_448 ) ;
F_440 ( & V_441 ) ;
F_441 ( & V_439 ) ;
F_378 ( F_374 , NULL , 1 ) ;
F_442 () ;
F_444 () ;
F_443 () ;
F_28 ( V_385 ) ;
F_446 () ;
}
