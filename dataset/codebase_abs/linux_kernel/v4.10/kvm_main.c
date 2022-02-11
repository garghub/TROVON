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
if ( V_9 -> V_69 ) {
for ( V_11 = 0 ; V_11 < V_70 ; V_11 ++ )
F_82 ( V_9 -> V_69 [ V_11 ] ) ;
F_82 ( V_9 -> V_69 ) ;
}
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
V_9 -> V_69 = F_87 ( V_70 ,
sizeof( * V_9 -> V_69 ) ,
V_32 ) ;
if ( ! V_9 -> V_69 )
return - V_34 ;
for ( V_77 = V_79 ; V_77 -> V_80 ; V_77 ++ ) {
V_75 = F_88 ( sizeof( * V_75 ) , V_32 ) ;
if ( ! V_75 )
return - V_34 ;
V_75 -> V_9 = V_9 ;
V_75 -> V_81 = V_77 -> V_81 ;
V_9 -> V_69 [ V_77 - V_79 ] = V_75 ;
if ( ! F_89 ( V_77 -> V_80 , 0644 ,
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
int V_126 = V_174 | V_175 ;
if ( V_169 )
V_126 |= V_176 ;
return F_180 ( V_50 , 1 , V_126 , V_25 , NULL ) ;
}
static inline int F_181 ( unsigned long V_166 )
{
int V_177 , V_126 = V_175 | V_176 ;
V_177 = F_180 ( V_166 , 1 , V_126 , NULL , NULL ) ;
return V_177 == - V_178 ;
}
static bool F_182 ( unsigned long V_166 , bool V_179 , bool * V_180 ,
bool V_181 , bool * V_172 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_67 ;
if ( ! ( V_180 || V_179 ) )
return false ;
if ( ! ( V_181 || V_172 ) )
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
static int F_185 ( unsigned long V_166 , bool * V_180 , bool V_181 ,
bool * V_172 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_67 = 0 ;
F_186 () ;
if ( V_172 )
* V_172 = V_181 ;
if ( V_180 ) {
F_166 ( & V_56 -> V_42 -> V_167 ) ;
V_67 = F_179 ( V_166 , V_181 , V_25 ) ;
F_169 ( & V_56 -> V_42 -> V_167 ) ;
} else {
unsigned int V_126 = V_175 ;
if ( V_181 )
V_126 |= V_176 ;
V_67 = F_187 ( V_166 , 1 , V_25 , V_126 ) ;
}
if ( V_67 != 1 )
return V_67 ;
if ( F_25 ( ! V_181 ) && V_172 ) {
struct V_25 * V_182 [ 1 ] ;
V_67 = F_183 ( V_166 , 1 , 1 , V_182 ) ;
if ( V_67 == 1 ) {
* V_172 = true ;
F_188 ( V_25 [ 0 ] ) ;
V_25 [ 0 ] = V_182 [ 0 ] ;
}
V_67 = 1 ;
}
* V_1 = F_184 ( V_25 [ 0 ] ) ;
return V_67 ;
}
static bool F_189 ( struct V_164 * V_165 , bool V_181 )
{
if ( F_25 ( ! ( V_165 -> V_183 & V_184 ) ) )
return false ;
if ( V_181 && ( F_25 ( ! ( V_165 -> V_183 & V_185 ) ) ) )
return false ;
return true ;
}
static int F_190 ( struct V_164 * V_165 ,
unsigned long V_166 , bool * V_180 ,
bool V_181 , T_1 * V_186 )
{
unsigned long V_1 ;
int V_26 ;
V_26 = F_191 ( V_165 , V_166 , & V_1 ) ;
if ( V_26 ) {
bool V_187 = false ;
V_26 = F_192 ( V_56 , V_56 -> V_42 , V_166 ,
( V_181 ? V_188 : 0 ) ,
& V_187 ) ;
if ( V_187 )
return - V_189 ;
if ( V_26 )
return V_26 ;
V_26 = F_191 ( V_165 , V_166 , & V_1 ) ;
if ( V_26 )
return V_26 ;
}
F_193 ( V_1 ) ;
* V_186 = V_1 ;
return 0 ;
}
static T_1 F_194 ( unsigned long V_166 , bool V_179 , bool * V_180 ,
bool V_181 , bool * V_172 )
{
struct V_164 * V_165 ;
T_1 V_1 = 0 ;
int V_67 , V_26 ;
F_62 ( V_179 && V_180 ) ;
if ( F_182 ( V_166 , V_179 , V_180 , V_181 , V_172 , & V_1 ) )
return V_1 ;
if ( V_179 )
return V_190 ;
V_67 = F_185 ( V_166 , V_180 , V_181 , V_172 , & V_1 ) ;
if ( V_67 == 1 )
return V_1 ;
F_166 ( & V_56 -> V_42 -> V_167 ) ;
if ( V_67 == - V_178 ||
( ! V_180 && F_181 ( V_166 ) ) ) {
V_1 = V_191 ;
goto exit;
}
V_192:
V_165 = F_195 ( V_56 -> V_42 , V_166 , V_166 + 1 ) ;
if ( V_165 == NULL )
V_1 = V_190 ;
else if ( V_165 -> V_183 & ( V_193 | V_194 ) ) {
V_26 = F_190 ( V_165 , V_166 , V_180 , V_181 , & V_1 ) ;
if ( V_26 == - V_189 )
goto V_192;
if ( V_26 < 0 )
V_1 = V_190 ;
} else {
if ( V_180 && F_189 ( V_165 , V_181 ) )
* V_180 = true ;
V_1 = V_190 ;
}
exit:
F_169 ( & V_56 -> V_42 -> V_167 ) ;
return V_1 ;
}
T_1 F_196 ( struct V_63 * V_130 , T_5 V_163 ,
bool V_179 , bool * V_180 , bool V_181 ,
bool * V_172 )
{
unsigned long V_166 = F_171 ( V_130 , V_163 , NULL , V_181 ) ;
if ( V_166 == V_171 ) {
if ( V_172 )
* V_172 = false ;
return V_195 ;
}
if ( F_165 ( V_166 ) ) {
if ( V_172 )
* V_172 = false ;
return V_196 ;
}
if ( V_172 && F_170 ( V_130 ) ) {
* V_172 = false ;
V_172 = NULL ;
}
return F_194 ( V_166 , V_179 , V_180 , V_181 ,
V_172 ) ;
}
T_1 F_197 ( struct V_9 * V_9 , T_5 V_163 , bool V_181 ,
bool * V_172 )
{
return F_196 ( F_158 ( V_9 , V_163 ) , V_163 , false , NULL ,
V_181 , V_172 ) ;
}
T_1 F_198 ( struct V_63 * V_130 , T_5 V_163 )
{
return F_196 ( V_130 , V_163 , false , NULL , true , NULL ) ;
}
T_1 F_199 ( struct V_63 * V_130 , T_5 V_163 )
{
return F_196 ( V_130 , V_163 , true , NULL , true , NULL ) ;
}
T_1 F_200 ( struct V_9 * V_9 , T_5 V_163 )
{
return F_199 ( F_158 ( V_9 , V_163 ) , V_163 ) ;
}
T_1 F_201 ( struct V_2 * V_3 , T_5 V_163 )
{
return F_199 ( F_160 ( V_3 , V_163 ) , V_163 ) ;
}
T_1 F_202 ( struct V_9 * V_9 , T_5 V_163 )
{
return F_198 ( F_158 ( V_9 , V_163 ) , V_163 ) ;
}
T_1 F_203 ( struct V_2 * V_3 , T_5 V_163 )
{
return F_198 ( F_160 ( V_3 , V_163 ) , V_163 ) ;
}
int F_204 ( struct V_63 * V_130 , T_5 V_163 ,
struct V_25 * * V_197 , int V_168 )
{
unsigned long V_166 ;
T_5 V_198 ;
V_166 = F_173 ( V_130 , V_163 , & V_198 ) ;
if ( F_165 ( V_166 ) )
return - 1 ;
if ( V_198 < V_168 )
return 0 ;
return F_183 ( V_166 , V_168 , 1 , V_197 ) ;
}
static struct V_25 * F_205 ( T_1 V_1 )
{
if ( F_206 ( V_1 ) )
return V_199 ;
if ( F_1 ( V_1 ) ) {
F_130 ( 1 ) ;
return V_199 ;
}
return F_4 ( V_1 ) ;
}
struct V_25 * F_207 ( struct V_9 * V_9 , T_5 V_163 )
{
T_1 V_1 ;
V_1 = F_202 ( V_9 , V_163 ) ;
return F_205 ( V_1 ) ;
}
struct V_25 * F_208 ( struct V_2 * V_3 , T_5 V_163 )
{
T_1 V_1 ;
V_1 = F_203 ( V_3 , V_163 ) ;
return F_205 ( V_1 ) ;
}
void F_209 ( struct V_25 * V_25 )
{
F_130 ( F_210 ( V_25 ) ) ;
F_211 ( F_184 ( V_25 ) ) ;
}
void F_211 ( T_1 V_1 )
{
if ( ! F_206 ( V_1 ) && ! F_1 ( V_1 ) )
F_188 ( F_4 ( V_1 ) ) ;
}
void F_212 ( struct V_25 * V_25 )
{
F_130 ( F_210 ( V_25 ) ) ;
F_213 ( F_184 ( V_25 ) ) ;
}
static void F_213 ( T_1 V_1 )
{
F_214 ( V_1 ) ;
F_211 ( V_1 ) ;
}
void F_214 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_25 * V_25 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_25 ) )
F_215 ( V_25 ) ;
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
static int F_219 ( unsigned long V_200 , int V_81 )
{
if ( V_200 > V_104 - V_81 )
return V_104 - V_81 ;
else
return V_200 ;
}
static int F_220 ( struct V_63 * V_130 , T_5 V_163 ,
void * V_201 , int V_81 , int V_200 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_176 ( V_130 , V_163 , NULL ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
V_26 = F_221 ( V_201 , ( void V_141 * ) V_166 + V_81 , V_200 ) ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_222 ( struct V_9 * V_9 , T_5 V_163 , void * V_201 , int V_81 ,
int V_200 )
{
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
return F_220 ( V_130 , V_163 , V_201 , V_81 , V_200 ) ;
}
int F_223 ( struct V_2 * V_3 , T_5 V_163 , void * V_201 ,
int V_81 , int V_200 )
{
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
return F_220 ( V_130 , V_163 , V_201 , V_81 , V_200 ) ;
}
int F_224 ( struct V_9 * V_9 , T_6 V_202 , void * V_201 , unsigned long V_200 )
{
T_5 V_163 = V_202 >> V_142 ;
int V_203 ;
int V_81 = F_225 ( V_202 ) ;
int V_204 ;
while ( ( V_203 = F_219 ( V_200 , V_81 ) ) != 0 ) {
V_204 = F_222 ( V_9 , V_163 , V_201 , V_81 , V_203 ) ;
if ( V_204 < 0 )
return V_204 ;
V_81 = 0 ;
V_200 -= V_203 ;
V_201 += V_203 ;
++ V_163 ;
}
return 0 ;
}
int F_226 ( struct V_2 * V_3 , T_6 V_202 , void * V_201 , unsigned long V_200 )
{
T_5 V_163 = V_202 >> V_142 ;
int V_203 ;
int V_81 = F_225 ( V_202 ) ;
int V_204 ;
while ( ( V_203 = F_219 ( V_200 , V_81 ) ) != 0 ) {
V_204 = F_223 ( V_3 , V_163 , V_201 , V_81 , V_203 ) ;
if ( V_204 < 0 )
return V_204 ;
V_81 = 0 ;
V_200 -= V_203 ;
V_201 += V_203 ;
++ V_163 ;
}
return 0 ;
}
static int F_227 ( struct V_63 * V_130 , T_5 V_163 ,
void * V_201 , int V_81 , unsigned long V_200 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_176 ( V_130 , V_163 , NULL ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
F_228 () ;
V_26 = F_229 ( V_201 , ( void V_141 * ) V_166 + V_81 , V_200 ) ;
F_230 () ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_231 ( struct V_9 * V_9 , T_6 V_202 , void * V_201 ,
unsigned long V_200 )
{
T_5 V_163 = V_202 >> V_142 ;
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
int V_81 = F_225 ( V_202 ) ;
return F_227 ( V_130 , V_163 , V_201 , V_81 , V_200 ) ;
}
int F_232 ( struct V_2 * V_3 , T_6 V_202 ,
void * V_201 , unsigned long V_200 )
{
T_5 V_163 = V_202 >> V_142 ;
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
int V_81 = F_225 ( V_202 ) ;
return F_227 ( V_130 , V_163 , V_201 , V_81 , V_200 ) ;
}
static int F_233 ( struct V_63 * V_64 , T_5 V_163 ,
const void * V_201 , int V_81 , int V_200 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_174 ( V_64 , V_163 ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
V_26 = F_234 ( ( void V_141 * ) V_166 + V_81 , V_201 , V_200 ) ;
if ( V_26 )
return - V_158 ;
F_235 ( V_64 , V_163 ) ;
return 0 ;
}
int F_236 ( struct V_9 * V_9 , T_5 V_163 ,
const void * V_201 , int V_81 , int V_200 )
{
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
return F_233 ( V_130 , V_163 , V_201 , V_81 , V_200 ) ;
}
int F_237 ( struct V_2 * V_3 , T_5 V_163 ,
const void * V_201 , int V_81 , int V_200 )
{
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
return F_233 ( V_130 , V_163 , V_201 , V_81 , V_200 ) ;
}
int F_238 ( struct V_9 * V_9 , T_6 V_202 , const void * V_201 ,
unsigned long V_200 )
{
T_5 V_163 = V_202 >> V_142 ;
int V_203 ;
int V_81 = F_225 ( V_202 ) ;
int V_204 ;
while ( ( V_203 = F_219 ( V_200 , V_81 ) ) != 0 ) {
V_204 = F_236 ( V_9 , V_163 , V_201 , V_81 , V_203 ) ;
if ( V_204 < 0 )
return V_204 ;
V_81 = 0 ;
V_200 -= V_203 ;
V_201 += V_203 ;
++ V_163 ;
}
return 0 ;
}
int F_239 ( struct V_2 * V_3 , T_6 V_202 , const void * V_201 ,
unsigned long V_200 )
{
T_5 V_163 = V_202 >> V_142 ;
int V_203 ;
int V_81 = F_225 ( V_202 ) ;
int V_204 ;
while ( ( V_203 = F_219 ( V_200 , V_81 ) ) != 0 ) {
V_204 = F_237 ( V_3 , V_163 , V_201 , V_81 , V_203 ) ;
if ( V_204 < 0 )
return V_204 ;
V_81 = 0 ;
V_200 -= V_203 ;
V_201 += V_203 ;
++ V_163 ;
}
return 0 ;
}
int F_240 ( struct V_9 * V_9 , struct V_205 * V_206 ,
T_6 V_202 , unsigned long V_200 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_81 = F_225 ( V_202 ) ;
T_5 V_207 = V_202 >> V_142 ;
T_5 V_208 = ( V_202 + V_200 - 1 ) >> V_142 ;
T_5 V_209 = V_208 - V_207 + 1 ;
T_5 V_210 ;
V_206 -> V_202 = V_202 ;
V_206 -> V_59 = V_58 -> V_59 ;
V_206 -> V_200 = V_200 ;
V_206 -> V_64 = F_158 ( V_9 , V_207 ) ;
V_206 -> V_173 = F_173 ( V_206 -> V_64 , V_207 , NULL ) ;
if ( ! F_165 ( V_206 -> V_173 ) && V_209 <= 1 ) {
V_206 -> V_173 += V_81 ;
} else {
while ( V_207 <= V_208 ) {
V_206 -> V_64 = F_158 ( V_9 , V_207 ) ;
V_206 -> V_173 = F_173 ( V_206 -> V_64 , V_207 ,
& V_210 ) ;
if ( F_165 ( V_206 -> V_173 ) )
return - V_158 ;
V_207 += V_210 ;
}
V_206 -> V_64 = NULL ;
}
return 0 ;
}
int F_241 ( struct V_9 * V_9 , struct V_205 * V_206 ,
void * V_201 , int V_81 , unsigned long V_200 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
T_6 V_202 = V_206 -> V_202 + V_81 ;
F_62 ( V_200 + V_81 > V_206 -> V_200 ) ;
if ( V_58 -> V_59 != V_206 -> V_59 )
F_240 ( V_9 , V_206 , V_206 -> V_202 , V_206 -> V_200 ) ;
if ( F_25 ( ! V_206 -> V_64 ) )
return F_238 ( V_9 , V_202 , V_201 , V_200 ) ;
if ( F_165 ( V_206 -> V_173 ) )
return - V_158 ;
V_26 = F_234 ( ( void V_141 * ) V_206 -> V_173 + V_81 , V_201 , V_200 ) ;
if ( V_26 )
return - V_158 ;
F_235 ( V_206 -> V_64 , V_202 >> V_142 ) ;
return 0 ;
}
int F_242 ( struct V_9 * V_9 , struct V_205 * V_206 ,
void * V_201 , unsigned long V_200 )
{
return F_241 ( V_9 , V_206 , V_201 , 0 , V_200 ) ;
}
int F_243 ( struct V_9 * V_9 , struct V_205 * V_206 ,
void * V_201 , unsigned long V_200 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
F_62 ( V_200 > V_206 -> V_200 ) ;
if ( V_58 -> V_59 != V_206 -> V_59 )
F_240 ( V_9 , V_206 , V_206 -> V_202 , V_206 -> V_200 ) ;
if ( F_25 ( ! V_206 -> V_64 ) )
return F_224 ( V_9 , V_206 -> V_202 , V_201 , V_200 ) ;
if ( F_165 ( V_206 -> V_173 ) )
return - V_158 ;
V_26 = F_221 ( V_201 , ( void V_141 * ) V_206 -> V_173 , V_200 ) ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_244 ( struct V_9 * V_9 , T_5 V_163 , int V_81 , int V_200 )
{
const void * V_211 = ( const void * ) F_245 ( F_246 ( F_247 ( 0 ) ) ) ;
return F_236 ( V_9 , V_163 , V_211 , V_81 , V_200 ) ;
}
int F_248 ( struct V_9 * V_9 , T_6 V_202 , unsigned long V_200 )
{
T_5 V_163 = V_202 >> V_142 ;
int V_203 ;
int V_81 = F_225 ( V_202 ) ;
int V_204 ;
while ( ( V_203 = F_219 ( V_200 , V_81 ) ) != 0 ) {
V_204 = F_244 ( V_9 , V_163 , V_81 , V_203 ) ;
if ( V_204 < 0 )
return V_204 ;
V_81 = 0 ;
V_200 -= V_203 ;
++ V_163 ;
}
return 0 ;
}
static void F_235 ( struct V_63 * V_64 ,
T_5 V_163 )
{
if ( V_64 && V_64 -> V_65 ) {
unsigned long V_212 = V_163 - V_64 -> V_120 ;
F_249 ( V_212 , V_64 -> V_65 ) ;
}
}
void F_250 ( struct V_9 * V_9 , T_5 V_163 )
{
struct V_63 * V_64 ;
V_64 = F_158 ( V_9 , V_163 ) ;
F_235 ( V_64 , V_163 ) ;
}
void F_251 ( struct V_2 * V_3 , T_5 V_163 )
{
struct V_63 * V_64 ;
V_64 = F_160 ( V_3 , V_163 ) ;
F_235 ( V_64 , V_163 ) ;
}
static void F_252 ( struct V_2 * V_3 )
{
unsigned int V_131 , V_213 , V_214 ;
V_131 = V_213 = V_3 -> V_215 ;
V_214 = F_253 ( V_216 ) ;
if ( V_213 == 0 && V_214 )
V_213 = 10000 ;
else
V_213 *= V_214 ;
if ( V_213 > V_215 )
V_213 = V_215 ;
V_3 -> V_215 = V_213 ;
F_254 ( V_3 -> V_27 , V_213 , V_131 ) ;
}
static void F_255 ( struct V_2 * V_3 )
{
unsigned int V_131 , V_213 , V_217 ;
V_131 = V_213 = V_3 -> V_215 ;
V_217 = F_253 ( V_218 ) ;
if ( V_217 == 0 )
V_213 = 0 ;
else
V_213 /= V_217 ;
V_3 -> V_215 = V_213 ;
F_256 ( V_3 -> V_27 , V_213 , V_131 ) ;
}
static int F_257 ( struct V_2 * V_3 )
{
if ( F_258 ( V_3 ) ) {
F_21 ( V_219 , V_3 ) ;
return - V_6 ;
}
if ( F_259 ( V_3 ) )
return - V_6 ;
if ( F_260 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_261 ( struct V_2 * V_3 )
{
T_7 V_50 , V_220 ;
F_262 ( V_221 ) ;
bool V_222 = false ;
T_8 V_223 ;
V_50 = V_220 = F_263 () ;
if ( V_3 -> V_215 ) {
T_7 V_224 = F_264 ( F_263 () , V_3 -> V_215 ) ;
++ V_3 -> V_21 . V_225 ;
do {
if ( F_257 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_226 ;
if ( ! F_265 ( V_3 ) )
++ V_3 -> V_21 . V_227 ;
goto V_134;
}
V_220 = F_263 () ;
} while ( F_266 () && F_267 ( V_220 , V_224 ) );
}
F_268 ( V_3 ) ;
for (; ; ) {
F_269 ( & V_3 -> V_29 , & V_221 , V_228 ) ;
if ( F_257 ( V_3 ) < 0 )
break;
V_222 = true ;
F_270 () ;
}
F_271 ( & V_3 -> V_29 , & V_221 ) ;
V_220 = F_263 () ;
F_272 ( V_3 ) ;
V_134:
V_223 = F_273 ( V_220 ) - F_273 ( V_50 ) ;
if ( ! F_265 ( V_3 ) )
F_255 ( V_3 ) ;
else if ( V_215 ) {
if ( V_223 <= V_3 -> V_215 )
;
else if ( V_3 -> V_215 && V_223 > V_215 )
F_255 ( V_3 ) ;
else if ( V_3 -> V_215 < V_215 &&
V_223 < V_215 )
F_252 ( V_3 ) ;
} else
V_3 -> V_215 = 0 ;
F_274 ( V_223 , V_222 , F_265 ( V_3 ) ) ;
F_275 ( V_3 ) ;
}
void F_276 ( struct V_2 * V_3 )
{
struct V_229 * V_230 ;
V_230 = F_277 ( V_3 ) ;
if ( F_278 ( V_230 ) ) {
F_279 ( V_230 ) ;
++ V_3 -> V_21 . V_231 ;
}
}
void F_280 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
F_276 ( V_3 ) ;
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_232 && F_281 ( V_4 ) )
if ( F_282 ( V_3 ) )
F_283 ( V_4 ) ;
F_10 () ;
}
int F_284 ( struct V_2 * V_233 )
{
struct V_28 * V_28 ;
struct V_234 * V_235 = NULL ;
int V_204 = 0 ;
F_285 () ;
V_28 = F_286 ( V_233 -> V_28 ) ;
if ( V_28 )
V_235 = F_287 ( V_28 , V_236 ) ;
F_288 () ;
if ( ! V_235 )
return V_204 ;
V_204 = F_289 ( V_235 , 1 ) ;
F_290 ( V_235 ) ;
return V_204 ;
}
static bool F_291 ( struct V_2 * V_3 )
{
#ifdef F_292
bool V_237 ;
V_237 = ! V_3 -> V_238 . V_239 ||
V_3 -> V_238 . V_240 ;
if ( V_3 -> V_238 . V_239 )
F_41 ( V_3 , ! V_3 -> V_238 . V_240 ) ;
return V_237 ;
#else
return true ;
#endif
}
void F_293 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_241 = V_12 -> V_9 -> V_241 ;
int V_242 = 0 ;
int V_243 = 3 ;
int V_244 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_244 = 0 ; V_244 < 2 && ! V_242 && V_243 ; V_244 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_244 && V_11 <= V_241 ) {
V_11 = V_241 ;
continue;
} else if ( V_244 && V_11 > V_241 )
break;
if ( ! F_294 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_278 ( & V_3 -> V_29 ) && ! F_258 ( V_3 ) )
continue;
if ( ! F_291 ( V_3 ) )
continue;
V_242 = F_284 ( V_3 ) ;
if ( V_242 > 0 ) {
V_9 -> V_241 = V_11 ;
break;
} else if ( V_242 < 0 ) {
V_243 -- ;
if ( ! V_243 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_295 ( struct V_164 * V_165 , struct V_245 * V_246 )
{
struct V_2 * V_3 = V_165 -> V_247 -> V_115 ;
struct V_25 * V_25 ;
if ( V_246 -> V_248 == 0 )
V_25 = F_296 ( V_3 -> V_36 ) ;
#ifdef F_297
else if ( V_246 -> V_248 == V_249 )
V_25 = F_296 ( V_3 -> V_152 . V_250 ) ;
#endif
#ifdef F_298
else if ( V_246 -> V_248 == F_298 )
V_25 = F_296 ( V_3 -> V_9 -> V_251 ) ;
#endif
else
return F_299 ( V_3 , V_246 ) ;
F_218 ( V_25 ) ;
V_246 -> V_25 = V_25 ;
return 0 ;
}
static int F_300 ( struct V_113 * V_113 , struct V_164 * V_165 )
{
V_165 -> V_252 = & V_253 ;
return 0 ;
}
static int F_301 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
F_81 ( V_3 -> V_68 ) ;
F_123 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_302 ( struct V_2 * V_3 )
{
return F_303 ( L_2 , & V_254 , V_3 , V_255 | V_256 ) ;
}
static int F_304 ( struct V_2 * V_3 )
{
char V_72 [ V_73 * 2 ] ;
int V_204 ;
if ( ! F_305 () )
return 0 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_72 , sizeof( V_72 ) , L_3 , V_3 -> V_27 ) ;
V_3 -> V_68 = F_86 ( V_72 ,
V_3 -> V_9 -> V_68 ) ;
if ( ! V_3 -> V_68 )
return - V_34 ;
V_204 = F_306 ( V_3 ) ;
if ( V_204 < 0 ) {
F_81 ( V_3 -> V_68 ) ;
return V_204 ;
}
return 0 ;
}
static int F_307 ( struct V_9 * V_9 , T_4 V_24 )
{
int V_26 ;
struct V_2 * V_3 ;
if ( V_24 >= V_257 )
return - V_127 ;
F_149 ( & V_9 -> V_85 ) ;
if ( V_9 -> V_258 == V_259 ) {
F_16 ( & V_9 -> V_85 ) ;
return - V_127 ;
}
V_9 -> V_258 ++ ;
F_16 ( & V_9 -> V_85 ) ;
V_3 = F_308 ( V_9 , V_24 ) ;
if ( F_309 ( V_3 ) ) {
V_26 = F_310 ( V_3 ) ;
goto V_260;
}
F_311 ( & V_3 -> V_7 , & V_261 ) ;
V_26 = F_312 ( V_3 ) ;
if ( V_26 )
goto V_262;
V_26 = F_304 ( V_3 ) ;
if ( V_26 )
goto V_262;
F_149 ( & V_9 -> V_85 ) ;
if ( F_313 ( V_9 , V_24 ) ) {
V_26 = - V_148 ;
goto V_263;
}
F_62 ( V_9 -> V_264 [ F_314 ( & V_9 -> V_265 ) ] ) ;
F_122 ( V_9 ) ;
V_26 = F_302 ( V_3 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
goto V_263;
}
V_9 -> V_264 [ F_314 ( & V_9 -> V_265 ) ] = V_3 ;
F_61 () ;
F_94 ( & V_9 -> V_265 ) ;
F_16 ( & V_9 -> V_85 ) ;
F_315 ( V_3 ) ;
return V_26 ;
V_263:
F_16 ( & V_9 -> V_85 ) ;
F_81 ( V_3 -> V_68 ) ;
V_262:
F_316 ( V_3 ) ;
V_260:
F_149 ( & V_9 -> V_85 ) ;
V_9 -> V_258 -- ;
F_16 ( & V_9 -> V_85 ) ;
return V_26 ;
}
static int F_317 ( struct V_2 * V_3 , T_9 * V_266 )
{
if ( V_266 ) {
F_318 ( V_266 , F_319 ( V_267 ) | F_319 ( V_268 ) ) ;
V_3 -> V_269 = 1 ;
V_3 -> V_266 = * V_266 ;
} else
V_3 -> V_269 = 0 ;
return 0 ;
}
static long F_320 ( struct V_113 * V_114 ,
unsigned int V_270 , unsigned long V_271 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
void V_141 * V_272 = ( void V_141 * ) V_271 ;
int V_26 ;
struct V_273 * V_274 = NULL ;
struct V_275 * V_275 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_276 ;
if ( F_25 ( F_321 ( V_270 ) != V_277 ) )
return - V_127 ;
#if F_118 ( V_278 ) || F_118 ( V_279 ) || F_118 ( V_280 )
if ( V_270 == V_281 || V_270 == V_282 || V_270 == V_283 )
return F_322 ( V_114 , V_270 , V_271 ) ;
#endif
V_26 = F_5 ( V_3 ) ;
if ( V_26 )
return V_26 ;
switch ( V_270 ) {
case V_284 :
V_26 = - V_127 ;
if ( V_271 )
goto V_134;
if ( F_25 ( V_3 -> V_28 != V_56 -> V_285 [ V_236 ] . V_28 ) ) {
struct V_28 * V_286 = V_3 -> V_28 ;
struct V_28 * V_287 = F_323 ( V_56 , V_236 ) ;
F_136 ( V_3 -> V_28 , V_287 ) ;
if ( V_286 )
F_324 () ;
F_45 ( V_286 ) ;
}
V_26 = F_325 ( V_3 , V_3 -> V_36 ) ;
F_326 ( V_3 -> V_36 -> V_288 , V_26 ) ;
break;
case V_289 : {
struct V_290 * V_290 ;
V_26 = - V_34 ;
V_290 = F_88 ( sizeof( struct V_290 ) , V_32 ) ;
if ( ! V_290 )
goto V_134;
V_26 = F_327 ( V_3 , V_290 ) ;
if ( V_26 )
goto V_291;
V_26 = - V_158 ;
if ( F_152 ( V_272 , V_290 , sizeof( struct V_290 ) ) )
goto V_291;
V_26 = 0 ;
V_291:
F_82 ( V_290 ) ;
break;
}
case V_292 : {
struct V_290 * V_290 ;
V_26 = - V_34 ;
V_290 = F_328 ( V_272 , sizeof( * V_290 ) ) ;
if ( F_309 ( V_290 ) ) {
V_26 = F_310 ( V_290 ) ;
goto V_134;
}
V_26 = F_329 ( V_3 , V_290 ) ;
F_82 ( V_290 ) ;
break;
}
case V_293 : {
V_275 = F_88 ( sizeof( struct V_275 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_275 )
goto V_134;
V_26 = F_330 ( V_3 , V_275 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_272 , V_275 , sizeof( struct V_275 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_294 : {
V_275 = F_328 ( V_272 , sizeof( * V_275 ) ) ;
if ( F_309 ( V_275 ) ) {
V_26 = F_310 ( V_275 ) ;
V_275 = NULL ;
goto V_134;
}
V_26 = F_331 ( V_3 , V_275 ) ;
break;
}
case V_295 : {
struct V_296 V_297 ;
V_26 = F_332 ( V_3 , & V_297 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_272 , & V_297 , sizeof( V_297 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_298 : {
struct V_296 V_297 ;
V_26 = - V_158 ;
if ( F_333 ( & V_297 , V_272 , sizeof( V_297 ) ) )
goto V_134;
V_26 = F_334 ( V_3 , & V_297 ) ;
break;
}
case V_299 : {
struct V_300 V_301 ;
V_26 = - V_158 ;
if ( F_333 ( & V_301 , V_272 , sizeof( V_301 ) ) )
goto V_134;
V_26 = F_335 ( V_3 , & V_301 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_272 , & V_301 , sizeof( V_301 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_302 : {
struct V_303 V_304 ;
V_26 = - V_158 ;
if ( F_333 ( & V_304 , V_272 , sizeof( V_304 ) ) )
goto V_134;
V_26 = F_336 ( V_3 , & V_304 ) ;
break;
}
case V_305 : {
struct V_306 V_141 * V_307 = V_272 ;
struct V_306 V_308 ;
T_9 V_266 , * V_77 ;
V_77 = NULL ;
if ( V_272 ) {
V_26 = - V_158 ;
if ( F_333 ( & V_308 , V_272 ,
sizeof( V_308 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_308 . V_200 != sizeof( V_266 ) )
goto V_134;
V_26 = - V_158 ;
if ( F_333 ( & V_266 , V_307 -> V_266 ,
sizeof( V_266 ) ) )
goto V_134;
V_77 = & V_266 ;
}
V_26 = F_317 ( V_3 , V_77 ) ;
break;
}
case V_309 : {
V_274 = F_88 ( sizeof( struct V_273 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_274 )
goto V_134;
V_26 = F_337 ( V_3 , V_274 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_272 , V_274 , sizeof( struct V_273 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_310 : {
V_274 = F_328 ( V_272 , sizeof( * V_274 ) ) ;
if ( F_309 ( V_274 ) ) {
V_26 = F_310 ( V_274 ) ;
V_274 = NULL ;
goto V_134;
}
V_26 = F_338 ( V_3 , V_274 ) ;
break;
}
default:
V_26 = F_322 ( V_114 , V_270 , V_271 ) ;
}
V_134:
F_11 ( V_3 ) ;
F_82 ( V_274 ) ;
F_82 ( V_275 ) ;
return V_26 ;
}
static long F_339 ( struct V_113 * V_114 ,
unsigned int V_270 , unsigned long V_271 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
void V_141 * V_272 = F_340 ( V_271 ) ;
int V_26 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_276 ;
switch ( V_270 ) {
case V_305 : {
struct V_306 V_141 * V_307 = V_272 ;
struct V_306 V_308 ;
T_10 V_311 ;
T_9 V_266 ;
if ( V_272 ) {
V_26 = - V_158 ;
if ( F_333 ( & V_308 , V_272 ,
sizeof( V_308 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_308 . V_200 != sizeof( V_311 ) )
goto V_134;
V_26 = - V_158 ;
if ( F_333 ( & V_311 , V_307 -> V_266 ,
sizeof( V_311 ) ) )
goto V_134;
F_341 ( & V_266 , & V_311 ) ;
V_26 = F_317 ( V_3 , & V_266 ) ;
} else
V_26 = F_317 ( V_3 , NULL ) ;
break;
}
default:
V_26 = F_320 ( V_114 , V_270 , V_271 ) ;
}
V_134:
return V_26 ;
}
static int F_342 ( struct V_105 * V_106 ,
int (* F_343)( struct V_105 * V_106 ,
struct V_312 * V_313 ) ,
unsigned long V_271 )
{
struct V_312 V_313 ;
if ( ! F_343 )
return - V_314 ;
if ( F_333 ( & V_313 , ( void V_141 * ) V_271 , sizeof( V_313 ) ) )
return - V_158 ;
return F_343 ( V_106 , & V_313 ) ;
}
static long F_344 ( struct V_113 * V_114 , unsigned int V_270 ,
unsigned long V_271 )
{
struct V_105 * V_106 = V_114 -> V_115 ;
switch ( V_270 ) {
case V_315 :
return F_342 ( V_106 , V_106 -> V_54 -> V_316 , V_271 ) ;
case V_317 :
return F_342 ( V_106 , V_106 -> V_54 -> V_318 , V_271 ) ;
case V_319 :
return F_342 ( V_106 , V_106 -> V_54 -> V_320 , V_271 ) ;
default:
if ( V_106 -> V_54 -> V_270 )
return V_106 -> V_54 -> V_270 ( V_106 , V_270 , V_271 ) ;
return - V_321 ;
}
}
static int F_345 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
struct V_105 * V_106 = V_114 -> V_115 ;
struct V_9 * V_9 = V_106 -> V_9 ;
F_123 ( V_9 ) ;
return 0 ;
}
struct V_105 * F_346 ( struct V_113 * V_114 )
{
if ( V_114 -> V_322 != & V_323 )
return NULL ;
return V_114 -> V_115 ;
}
int F_347 ( struct V_324 * V_54 , T_4 type )
{
if ( type >= F_348 ( V_325 ) )
return - V_326 ;
if ( V_325 [ type ] != NULL )
return - V_148 ;
V_325 [ type ] = V_54 ;
return 0 ;
}
void F_349 ( T_4 type )
{
if ( V_325 [ type ] != NULL )
V_325 [ type ] = NULL ;
}
static int F_350 ( struct V_9 * V_9 ,
struct V_327 * V_328 )
{
struct V_324 * V_54 = NULL ;
struct V_105 * V_106 ;
bool V_329 = V_328 -> V_126 & V_330 ;
int V_204 ;
if ( V_328 -> type >= F_348 ( V_325 ) )
return - V_331 ;
V_54 = V_325 [ V_328 -> type ] ;
if ( V_54 == NULL )
return - V_331 ;
if ( V_329 )
return 0 ;
V_106 = F_88 ( sizeof( * V_106 ) , V_32 ) ;
if ( ! V_106 )
return - V_34 ;
V_106 -> V_54 = V_54 ;
V_106 -> V_9 = V_9 ;
F_149 ( & V_9 -> V_85 ) ;
V_204 = V_54 -> V_332 ( V_106 , V_328 -> type ) ;
if ( V_204 < 0 ) {
F_16 ( & V_9 -> V_85 ) ;
F_82 ( V_106 ) ;
return V_204 ;
}
F_103 ( & V_106 -> V_108 , & V_9 -> V_89 ) ;
F_16 ( & V_9 -> V_85 ) ;
if ( V_54 -> V_333 )
V_54 -> V_333 ( V_106 ) ;
V_204 = F_303 ( V_54 -> V_80 , & V_323 , V_106 , V_255 | V_256 ) ;
if ( V_204 < 0 ) {
F_149 ( & V_9 -> V_85 ) ;
F_112 ( & V_106 -> V_108 ) ;
F_16 ( & V_9 -> V_85 ) ;
V_54 -> V_109 ( V_106 ) ;
return V_204 ;
}
F_122 ( V_9 ) ;
V_328 -> V_71 = V_204 ;
return 0 ;
}
static long F_351 ( struct V_9 * V_9 , long V_271 )
{
switch ( V_271 ) {
case V_334 :
case V_335 :
case V_336 :
case V_337 :
#ifdef F_352
case V_338 :
#endif
#ifdef F_99
case V_339 :
case V_340 :
#endif
case V_341 :
case V_342 :
return 1 ;
#ifdef F_353
case V_343 :
return V_344 ;
#endif
#if V_93 > 1
case V_345 :
return V_93 ;
#endif
case V_346 :
return V_257 ;
default:
break;
}
return F_354 ( V_9 , V_271 ) ;
}
static long F_355 ( struct V_113 * V_114 ,
unsigned int V_270 , unsigned long V_271 )
{
struct V_9 * V_9 = V_114 -> V_115 ;
void V_141 * V_272 = ( void V_141 * ) V_271 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_276 ;
switch ( V_270 ) {
case V_347 :
V_26 = F_307 ( V_9 , V_271 ) ;
break;
case V_348 : {
struct V_121 V_349 ;
V_26 = - V_158 ;
if ( F_333 ( & V_349 , V_272 ,
sizeof( V_349 ) ) )
goto V_134;
V_26 = F_150 ( V_9 , & V_349 ) ;
break;
}
case V_350 : {
struct V_153 log ;
V_26 = - V_158 ;
if ( F_333 ( & log , V_272 , sizeof( log ) ) )
goto V_134;
V_26 = F_356 ( V_9 , & log ) ;
break;
}
#ifdef F_298
case V_351 : {
struct V_352 V_353 ;
V_26 = - V_158 ;
if ( F_333 ( & V_353 , V_272 , sizeof( V_353 ) ) )
goto V_134;
V_26 = F_357 ( V_9 , & V_353 ) ;
break;
}
case V_354 : {
struct V_352 V_353 ;
V_26 = - V_158 ;
if ( F_333 ( & V_353 , V_272 , sizeof( V_353 ) ) )
goto V_134;
V_26 = F_358 ( V_9 , & V_353 ) ;
break;
}
#endif
case V_355 : {
struct V_356 V_201 ;
V_26 = - V_158 ;
if ( F_333 ( & V_201 , V_272 , sizeof( V_201 ) ) )
goto V_134;
V_26 = V_356 ( V_9 , & V_201 ) ;
break;
}
case V_357 : {
struct V_358 V_201 ;
V_26 = - V_158 ;
if ( F_333 ( & V_201 , V_272 , sizeof( V_201 ) ) )
goto V_134;
V_26 = V_358 ( V_9 , & V_201 ) ;
break;
}
#ifdef F_352
case V_359 : {
struct V_360 V_361 ;
V_26 = - V_158 ;
if ( F_333 ( & V_361 , V_272 , sizeof( V_361 ) ) )
goto V_134;
V_26 = F_359 ( V_9 , & V_361 ) ;
break;
}
#endif
#ifdef F_360
case V_362 :
case V_363 : {
struct V_364 V_365 ;
V_26 = - V_158 ;
if ( F_333 ( & V_365 , V_272 , sizeof( V_365 ) ) )
goto V_134;
V_26 = F_361 ( V_9 , & V_365 ,
V_270 == V_362 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( V_270 == V_362 ) {
if ( F_152 ( V_272 , & V_365 , sizeof( V_365 ) ) )
goto V_134;
}
V_26 = 0 ;
break;
}
#endif
#ifdef F_353
case V_366 : {
struct V_367 V_368 ;
struct V_367 V_141 * V_369 ;
struct V_370 * V_371 = NULL ;
V_26 = - V_158 ;
if ( F_333 ( & V_368 , V_272 , sizeof( V_368 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_368 . V_372 > V_344 )
goto V_134;
if ( V_368 . V_126 )
goto V_134;
if ( V_368 . V_372 ) {
V_26 = - V_34 ;
V_371 = F_362 ( V_368 . V_372 * sizeof( * V_371 ) ) ;
if ( ! V_371 )
goto V_134;
V_26 = - V_158 ;
V_369 = V_272 ;
if ( F_333 ( V_371 , V_369 -> V_371 ,
V_368 . V_372 * sizeof( * V_371 ) ) )
goto V_373;
}
V_26 = F_363 ( V_9 , V_371 , V_368 . V_372 ,
V_368 . V_126 ) ;
V_373:
F_364 ( V_371 ) ;
break;
}
#endif
case V_374 : {
struct V_327 V_328 ;
V_26 = - V_158 ;
if ( F_333 ( & V_328 , V_272 , sizeof( V_328 ) ) )
goto V_134;
V_26 = F_350 ( V_9 , & V_328 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_272 , & V_328 , sizeof( V_328 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_375 :
V_26 = F_351 ( V_9 , V_271 ) ;
break;
default:
V_26 = F_365 ( V_114 , V_270 , V_271 ) ;
}
V_134:
return V_26 ;
}
static long F_366 ( struct V_113 * V_114 ,
unsigned int V_270 , unsigned long V_271 )
{
struct V_9 * V_9 = V_114 -> V_115 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_276 ;
switch ( V_270 ) {
case V_350 : {
struct V_376 V_377 ;
struct V_153 log ;
V_26 = - V_158 ;
if ( F_333 ( & V_377 , ( void V_141 * ) V_271 ,
sizeof( V_377 ) ) )
goto V_134;
log . V_130 = V_377 . V_130 ;
log . V_378 = V_377 . V_378 ;
log . V_379 = V_377 . V_379 ;
log . V_65 = F_340 ( V_377 . V_65 ) ;
V_26 = F_356 ( V_9 , & log ) ;
break;
}
default:
V_26 = F_355 ( V_114 , V_270 , V_271 ) ;
}
V_134:
return V_26 ;
}
static int F_367 ( unsigned long type )
{
int V_26 ;
struct V_9 * V_9 ;
struct V_113 * V_113 ;
V_9 = F_90 ( type ) ;
if ( F_309 ( V_9 ) )
return F_310 ( V_9 ) ;
#ifdef F_298
V_26 = F_368 ( V_9 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
return V_26 ;
}
#endif
V_26 = F_369 ( V_256 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
return V_26 ;
}
V_113 = F_370 ( L_4 , & V_380 , V_9 , V_255 ) ;
if ( F_309 ( V_113 ) ) {
F_371 ( V_26 ) ;
F_123 ( V_9 ) ;
return F_310 ( V_113 ) ;
}
if ( F_83 ( V_9 , V_26 ) < 0 ) {
F_371 ( V_26 ) ;
F_372 ( V_113 ) ;
return - V_34 ;
}
F_373 ( V_26 , V_113 ) ;
return V_26 ;
}
static long F_374 ( struct V_113 * V_114 ,
unsigned int V_270 , unsigned long V_271 )
{
long V_26 = - V_127 ;
switch ( V_270 ) {
case V_381 :
if ( V_271 )
goto V_134;
V_26 = V_382 ;
break;
case V_383 :
V_26 = F_367 ( V_271 ) ;
break;
case V_375 :
V_26 = F_351 ( NULL , V_271 ) ;
break;
case V_384 :
if ( V_271 )
goto V_134;
V_26 = V_104 ;
#ifdef F_297
V_26 += V_104 ;
#endif
#ifdef F_298
V_26 += V_104 ;
#endif
break;
case V_385 :
case V_386 :
case V_387 :
V_26 = - V_388 ;
break;
default:
return F_375 ( V_114 , V_270 , V_271 ) ;
}
V_134:
return V_26 ;
}
static void F_376 ( void * V_389 )
{
int V_4 = F_377 () ;
int V_26 ;
if ( F_378 ( V_4 , V_390 ) )
return;
F_24 ( V_4 , V_390 ) ;
V_26 = F_379 () ;
if ( V_26 ) {
F_380 ( V_4 , V_390 ) ;
F_94 ( & V_391 ) ;
F_381 ( L_5 , V_4 ) ;
}
}
static int F_382 ( unsigned int V_4 )
{
F_383 ( & V_392 ) ;
if ( V_393 )
F_376 ( NULL ) ;
F_384 ( & V_392 ) ;
return 0 ;
}
static void F_385 ( void * V_389 )
{
int V_4 = F_377 () ;
if ( ! F_378 ( V_4 , V_390 ) )
return;
F_380 ( V_4 , V_390 ) ;
F_386 () ;
}
static int F_387 ( unsigned int V_4 )
{
F_383 ( & V_392 ) ;
if ( V_393 )
F_385 ( NULL ) ;
F_384 ( & V_392 ) ;
return 0 ;
}
static void F_388 ( void )
{
F_62 ( ! V_393 ) ;
V_393 -- ;
if ( ! V_393 )
F_389 ( F_385 , NULL , 1 ) ;
}
static void F_106 ( void )
{
F_383 ( & V_392 ) ;
F_388 () ;
F_384 ( & V_392 ) ;
}
static int F_98 ( void )
{
int V_26 = 0 ;
F_383 ( & V_392 ) ;
V_393 ++ ;
if ( V_393 == 1 ) {
F_96 ( & V_391 , 0 ) ;
F_389 ( F_376 , NULL , 1 ) ;
if ( F_314 ( & V_391 ) ) {
F_388 () ;
V_26 = - V_394 ;
}
}
F_384 ( & V_392 ) ;
return V_26 ;
}
static int F_390 ( struct V_395 * V_396 , unsigned long V_213 ,
void * V_397 )
{
F_381 ( L_6 ) ;
V_398 = true ;
F_389 ( F_385 , NULL , 1 ) ;
return V_399 ;
}
static void F_116 ( struct V_99 * V_400 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_400 -> V_401 ; V_11 ++ ) {
struct V_402 * V_403 = V_400 -> V_404 [ V_11 ] . V_106 ;
F_391 ( V_403 ) ;
}
F_82 ( V_400 ) ;
}
static inline int F_392 ( const struct V_405 * V_406 ,
const struct V_405 * V_407 )
{
T_6 V_408 = V_406 -> V_166 ;
T_6 V_409 = V_407 -> V_166 ;
if ( V_408 < V_409 )
return - 1 ;
if ( V_407 -> V_200 ) {
V_408 += V_406 -> V_200 ;
V_409 += V_407 -> V_200 ;
}
if ( V_408 > V_409 )
return 1 ;
return 0 ;
}
static int F_393 ( const void * V_410 , const void * V_411 )
{
return F_392 ( V_410 , V_411 ) ;
}
static int F_394 ( struct V_99 * V_400 , struct V_402 * V_106 ,
T_6 V_166 , int V_200 )
{
V_400 -> V_404 [ V_400 -> V_401 ++ ] = (struct V_405 ) {
. V_166 = V_166 ,
. V_200 = V_200 ,
. V_106 = V_106 ,
} ;
F_395 ( V_400 -> V_404 , V_400 -> V_401 , sizeof( struct V_405 ) ,
F_393 , NULL ) ;
return 0 ;
}
static int F_396 ( struct V_99 * V_400 ,
T_6 V_166 , int V_200 )
{
struct V_405 * V_404 , V_412 ;
int V_413 ;
V_412 = (struct V_405 ) {
. V_166 = V_166 ,
. V_200 = V_200 ,
} ;
V_404 = bsearch ( & V_412 , V_400 -> V_404 , V_400 -> V_401 ,
sizeof( struct V_405 ) , F_393 ) ;
if ( V_404 == NULL )
return - V_157 ;
V_413 = V_404 - V_400 -> V_404 ;
while ( V_413 > 0 && F_392 ( & V_412 , & V_400 -> V_404 [ V_413 - 1 ] ) == 0 )
V_413 -- ;
return V_413 ;
}
static int F_397 ( struct V_2 * V_3 , struct V_99 * V_400 ,
struct V_405 * V_404 , const void * V_213 )
{
int V_45 ;
V_45 = F_396 ( V_400 , V_404 -> V_166 , V_404 -> V_200 ) ;
if ( V_45 < 0 )
return - V_388 ;
while ( V_45 < V_400 -> V_401 &&
F_392 ( V_404 , & V_400 -> V_404 [ V_45 ] ) == 0 ) {
if ( ! F_398 ( V_3 , V_400 -> V_404 [ V_45 ] . V_106 , V_404 -> V_166 ,
V_404 -> V_200 , V_213 ) )
return V_45 ;
V_45 ++ ;
}
return - V_388 ;
}
int F_399 ( struct V_2 * V_3 , enum V_414 V_415 , T_6 V_166 ,
int V_200 , const void * V_213 )
{
struct V_99 * V_400 ;
struct V_405 V_404 ;
int V_26 ;
V_404 = (struct V_405 ) {
. V_166 = V_166 ,
. V_200 = V_200 ,
} ;
V_400 = F_400 ( V_3 -> V_9 -> V_98 [ V_415 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_397 ( V_3 , V_400 , & V_404 , V_213 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_401 ( struct V_2 * V_3 , enum V_414 V_415 ,
T_6 V_166 , int V_200 , const void * V_213 , long V_416 )
{
struct V_99 * V_400 ;
struct V_405 V_404 ;
V_404 = (struct V_405 ) {
. V_166 = V_166 ,
. V_200 = V_200 ,
} ;
V_400 = F_400 ( V_3 -> V_9 -> V_98 [ V_415 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ( V_416 >= 0 ) && ( V_416 < V_400 -> V_401 ) &&
( F_392 ( & V_404 , & V_400 -> V_404 [ V_416 ] ) == 0 ) )
if ( ! F_398 ( V_3 , V_400 -> V_404 [ V_416 ] . V_106 , V_166 , V_200 ,
V_213 ) )
return V_416 ;
return F_397 ( V_3 , V_400 , & V_404 , V_213 ) ;
}
static int F_402 ( struct V_2 * V_3 , struct V_99 * V_400 ,
struct V_405 * V_404 , void * V_213 )
{
int V_45 ;
V_45 = F_396 ( V_400 , V_404 -> V_166 , V_404 -> V_200 ) ;
if ( V_45 < 0 )
return - V_388 ;
while ( V_45 < V_400 -> V_401 &&
F_392 ( V_404 , & V_400 -> V_404 [ V_45 ] ) == 0 ) {
if ( ! F_403 ( V_3 , V_400 -> V_404 [ V_45 ] . V_106 , V_404 -> V_166 ,
V_404 -> V_200 , V_213 ) )
return V_45 ;
V_45 ++ ;
}
return - V_388 ;
}
int F_404 ( struct V_2 * V_3 , enum V_414 V_415 , T_6 V_166 ,
int V_200 , void * V_213 )
{
struct V_99 * V_400 ;
struct V_405 V_404 ;
int V_26 ;
V_404 = (struct V_405 ) {
. V_166 = V_166 ,
. V_200 = V_200 ,
} ;
V_400 = F_400 ( V_3 -> V_9 -> V_98 [ V_415 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_402 ( V_3 , V_400 , & V_404 , V_213 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_405 ( struct V_9 * V_9 , enum V_414 V_415 , T_6 V_166 ,
int V_200 , struct V_402 * V_106 )
{
struct V_99 * V_417 , * V_400 ;
V_400 = V_9 -> V_98 [ V_415 ] ;
if ( V_400 -> V_401 - V_400 -> V_418 > V_419 - 1 )
return - V_326 ;
V_417 = F_406 ( sizeof( * V_400 ) + ( ( V_400 -> V_401 + 1 ) *
sizeof( struct V_405 ) ) , V_32 ) ;
if ( ! V_417 )
return - V_34 ;
memcpy ( V_417 , V_400 , sizeof( * V_400 ) + ( V_400 -> V_401 *
sizeof( struct V_405 ) ) ) ;
F_394 ( V_417 , V_106 , V_166 , V_200 ) ;
F_136 ( V_9 -> V_98 [ V_415 ] , V_417 ) ;
F_137 ( & V_9 -> V_46 ) ;
F_82 ( V_400 ) ;
return 0 ;
}
int F_407 ( struct V_9 * V_9 , enum V_414 V_415 ,
struct V_402 * V_106 )
{
int V_11 , V_26 ;
struct V_99 * V_417 , * V_400 ;
V_400 = V_9 -> V_98 [ V_415 ] ;
V_26 = - V_157 ;
for ( V_11 = 0 ; V_11 < V_400 -> V_401 ; V_11 ++ )
if ( V_400 -> V_404 [ V_11 ] . V_106 == V_106 ) {
V_26 = 0 ;
break;
}
if ( V_26 )
return V_26 ;
V_417 = F_406 ( sizeof( * V_400 ) + ( ( V_400 -> V_401 - 1 ) *
sizeof( struct V_405 ) ) , V_32 ) ;
if ( ! V_417 )
return - V_34 ;
memcpy ( V_417 , V_400 , sizeof( * V_400 ) + V_11 * sizeof( struct V_405 ) ) ;
V_417 -> V_401 -- ;
memcpy ( V_417 -> V_404 + V_11 , V_400 -> V_404 + V_11 + 1 ,
( V_417 -> V_401 - V_11 ) * sizeof( struct V_405 ) ) ;
F_136 ( V_9 -> V_98 [ V_415 ] , V_417 ) ;
F_137 ( & V_9 -> V_46 ) ;
F_82 ( V_400 ) ;
return V_26 ;
}
struct V_402 * F_408 ( struct V_9 * V_9 , enum V_414 V_415 ,
T_6 V_166 )
{
struct V_99 * V_400 ;
int V_420 , V_421 ;
struct V_402 * V_422 = NULL ;
V_421 = F_50 ( & V_9 -> V_46 ) ;
V_400 = F_400 ( V_9 -> V_98 [ V_415 ] , & V_9 -> V_46 ) ;
V_420 = F_396 ( V_400 , V_166 , 1 ) ;
if ( V_420 < 0 )
goto V_423;
V_422 = V_400 -> V_404 [ V_420 ] . V_106 ;
V_423:
F_55 ( & V_9 -> V_46 , V_421 ) ;
return V_422 ;
}
static int F_409 ( struct V_112 * V_112 , struct V_113 * V_113 ,
int (* F_410)( void * , T_8 * ) , int (* F_411)( void * , T_8 ) ,
const char * V_424 )
{
struct V_74 * V_75 = (struct V_74 * )
V_112 -> V_425 ;
if ( ! F_412 ( & V_75 -> V_9 -> V_88 , 1 , 0 ) )
return - V_157 ;
if ( F_413 ( V_112 , V_113 , F_410 , F_411 , V_424 ) ) {
F_123 ( V_75 -> V_9 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_414 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
struct V_74 * V_75 = (struct V_74 * )
V_112 -> V_425 ;
F_415 ( V_112 , V_113 ) ;
F_123 ( V_75 -> V_9 ) ;
return 0 ;
}
static int F_416 ( void * V_201 , T_8 * V_213 )
{
struct V_74 * V_75 = (struct V_74 * ) V_201 ;
* V_213 = * ( V_426 * ) ( ( void * ) V_75 -> V_9 + V_75 -> V_81 ) ;
return 0 ;
}
static int F_417 ( void * V_201 , T_8 V_213 )
{
struct V_74 * V_75 = (struct V_74 * ) V_201 ;
if ( V_213 )
return - V_127 ;
* ( V_426 * ) ( ( void * ) V_75 -> V_9 + V_75 -> V_81 ) = 0 ;
return 0 ;
}
static int F_418 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
F_419 ( L_7 , 0ull ) ;
return F_409 ( V_112 , V_113 , F_416 ,
F_417 , L_7 ) ;
}
static int F_420 ( void * V_201 , T_8 * V_213 )
{
int V_11 ;
struct V_74 * V_75 = (struct V_74 * ) V_201 ;
struct V_2 * V_3 ;
* V_213 = 0 ;
F_20 ( V_11 , V_3 , V_75 -> V_9 )
* V_213 += * ( T_8 * ) ( ( void * ) V_3 + V_75 -> V_81 ) ;
return 0 ;
}
static int F_421 ( void * V_201 , T_8 V_213 )
{
int V_11 ;
struct V_74 * V_75 = (struct V_74 * ) V_201 ;
struct V_2 * V_3 ;
if ( V_213 )
return - V_127 ;
F_20 ( V_11 , V_3 , V_75 -> V_9 )
* ( T_8 * ) ( ( void * ) V_3 + V_75 -> V_81 ) = 0 ;
return 0 ;
}
static int F_422 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
F_419 ( L_7 , 0ull ) ;
return F_409 ( V_112 , V_113 , F_420 ,
F_421 , L_7 ) ;
}
static int F_423 ( void * V_427 , T_8 * V_213 )
{
unsigned V_81 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_74 V_428 = { . V_81 = V_81 } ;
T_8 V_429 ;
* V_213 = 0 ;
F_51 ( & V_101 ) ;
F_424 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_416 ( ( void * ) & V_428 , & V_429 ) ;
* V_213 += V_429 ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_425 ( void * V_427 , T_8 V_213 )
{
unsigned V_81 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_74 V_428 = { . V_81 = V_81 } ;
if ( V_213 )
return - V_127 ;
F_51 ( & V_101 ) ;
F_424 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_417 ( ( void * ) & V_428 , 0 ) ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_426 ( void * V_427 , T_8 * V_213 )
{
unsigned V_81 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_74 V_428 = { . V_81 = V_81 } ;
T_8 V_429 ;
* V_213 = 0 ;
F_51 ( & V_101 ) ;
F_424 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_420 ( ( void * ) & V_428 , & V_429 ) ;
* V_213 += V_429 ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_427 ( void * V_427 , T_8 V_213 )
{
unsigned V_81 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_74 V_428 = { . V_81 = V_81 } ;
if ( V_213 )
return - V_127 ;
F_51 ( & V_101 ) ;
F_424 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_421 ( ( void * ) & V_428 , 0 ) ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_428 ( void )
{
int V_26 = - V_148 ;
struct V_76 * V_77 ;
V_78 = F_86 ( L_8 , NULL ) ;
if ( V_78 == NULL )
goto V_134;
V_70 = 0 ;
for ( V_77 = V_79 ; V_77 -> V_80 ; ++ V_77 , V_70 ++ ) {
if ( ! F_89 ( V_77 -> V_80 , 0644 , V_78 ,
( void * ) ( long ) V_77 -> V_81 ,
V_430 [ V_77 -> V_83 ] ) )
goto V_431;
}
return 0 ;
V_431:
F_81 ( V_78 ) ;
V_134:
return V_26 ;
}
static int F_429 ( void )
{
if ( V_393 )
F_385 ( NULL ) ;
return 0 ;
}
static void F_430 ( void )
{
if ( V_393 ) {
F_130 ( F_431 ( & V_392 ) ) ;
F_376 ( NULL ) ;
}
}
static inline
struct V_2 * F_432 ( struct V_7 * V_432 )
{
return F_48 ( V_432 , struct V_2 , V_7 ) ;
}
static void F_433 ( struct V_7 * V_432 , int V_4 )
{
struct V_2 * V_3 = F_432 ( V_432 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_434 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_435 ( struct V_7 * V_432 ,
struct V_234 * V_433 )
{
struct V_2 * V_3 = F_432 ( V_432 ) ;
if ( V_56 -> V_434 == V_435 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_436 ( void * V_436 , unsigned V_437 , unsigned V_438 ,
struct V_439 * V_439 )
{
int V_26 ;
int V_4 ;
V_26 = F_437 ( V_436 ) ;
if ( V_26 )
goto V_440;
V_26 = F_438 () ;
if ( V_26 )
goto V_441;
if ( ! F_19 ( & V_390 , V_32 ) ) {
V_26 = - V_34 ;
goto V_442;
}
V_26 = F_439 () ;
if ( V_26 < 0 )
goto V_443;
F_440 (cpu) {
F_441 ( V_4 ,
V_444 ,
& V_26 , 1 ) ;
if ( V_26 < 0 )
goto V_445;
}
V_26 = F_442 ( V_446 , L_9 ,
F_382 , F_387 ) ;
if ( V_26 )
goto V_447;
F_443 ( & V_448 ) ;
if ( ! V_438 )
V_438 = F_444 ( struct V_2 ) ;
V_449 = F_445 ( L_10 , V_437 , V_438 ,
0 , NULL ) ;
if ( ! V_449 ) {
V_26 = - V_34 ;
goto V_450;
}
V_26 = F_446 () ;
if ( V_26 )
goto V_149;
V_451 . V_452 = V_439 ;
V_380 . V_452 = V_439 ;
V_254 . V_452 = V_439 ;
V_26 = F_447 ( & V_453 ) ;
if ( V_26 ) {
F_448 ( L_11 ) ;
goto V_454;
}
F_449 ( & V_455 ) ;
V_261 . V_456 = F_433 ;
V_261 . V_457 = F_435 ;
V_26 = F_428 () ;
if ( V_26 ) {
F_448 ( L_12 ) ;
goto V_458;
}
V_26 = F_450 () ;
F_130 ( V_26 ) ;
return 0 ;
V_458:
F_451 ( & V_455 ) ;
F_452 ( & V_453 ) ;
V_454:
F_453 () ;
V_149:
F_454 ( V_449 ) ;
V_450:
F_455 ( & V_448 ) ;
F_456 ( V_446 ) ;
V_447:
V_445:
F_457 () ;
V_443:
F_28 ( V_390 ) ;
V_442:
F_458 () ;
V_441:
F_459 () ;
V_440:
return V_26 ;
}
void F_460 ( void )
{
F_81 ( V_78 ) ;
F_452 ( & V_453 ) ;
F_454 ( V_449 ) ;
F_453 () ;
F_451 ( & V_455 ) ;
F_455 ( & V_448 ) ;
F_456 ( V_446 ) ;
F_389 ( F_385 , NULL , 1 ) ;
F_457 () ;
F_459 () ;
F_458 () ;
F_28 ( V_390 ) ;
F_461 () ;
}
