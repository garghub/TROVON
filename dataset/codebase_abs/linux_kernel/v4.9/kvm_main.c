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
unsigned int V_126 = V_182 | V_175 ;
if ( V_181 )
V_126 |= V_176 ;
V_67 = F_187 ( V_56 , V_56 -> V_42 , V_166 , 1 ,
V_25 , V_126 ) ;
}
if ( V_67 != 1 )
return V_67 ;
if ( F_25 ( ! V_181 ) && V_172 ) {
struct V_25 * V_183 [ 1 ] ;
V_67 = F_183 ( V_166 , 1 , 1 , V_183 ) ;
if ( V_67 == 1 ) {
* V_172 = true ;
F_188 ( V_25 [ 0 ] ) ;
V_25 [ 0 ] = V_183 [ 0 ] ;
}
V_67 = 1 ;
}
* V_1 = F_184 ( V_25 [ 0 ] ) ;
return V_67 ;
}
static bool F_189 ( struct V_164 * V_165 , bool V_181 )
{
if ( F_25 ( ! ( V_165 -> V_184 & V_185 ) ) )
return false ;
if ( V_181 && ( F_25 ( ! ( V_165 -> V_184 & V_186 ) ) ) )
return false ;
return true ;
}
static int F_190 ( struct V_164 * V_165 ,
unsigned long V_166 , bool * V_180 ,
bool V_181 , T_1 * V_187 )
{
unsigned long V_1 ;
int V_26 ;
V_26 = F_191 ( V_165 , V_166 , & V_1 ) ;
if ( V_26 ) {
bool V_188 = false ;
V_26 = F_192 ( V_56 , V_56 -> V_42 , V_166 ,
( V_181 ? V_189 : 0 ) ,
& V_188 ) ;
if ( V_188 )
return - V_190 ;
if ( V_26 )
return V_26 ;
V_26 = F_191 ( V_165 , V_166 , & V_1 ) ;
if ( V_26 )
return V_26 ;
}
F_193 ( V_1 ) ;
* V_187 = V_1 ;
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
return V_191 ;
V_67 = F_185 ( V_166 , V_180 , V_181 , V_172 , & V_1 ) ;
if ( V_67 == 1 )
return V_1 ;
F_166 ( & V_56 -> V_42 -> V_167 ) ;
if ( V_67 == - V_178 ||
( ! V_180 && F_181 ( V_166 ) ) ) {
V_1 = V_192 ;
goto exit;
}
V_193:
V_165 = F_195 ( V_56 -> V_42 , V_166 , V_166 + 1 ) ;
if ( V_165 == NULL )
V_1 = V_191 ;
else if ( V_165 -> V_184 & ( V_194 | V_195 ) ) {
V_26 = F_190 ( V_165 , V_166 , V_180 , V_181 , & V_1 ) ;
if ( V_26 == - V_190 )
goto V_193;
if ( V_26 < 0 )
V_1 = V_191 ;
} else {
if ( V_180 && F_189 ( V_165 , V_181 ) )
* V_180 = true ;
V_1 = V_191 ;
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
return V_196 ;
}
if ( F_165 ( V_166 ) ) {
if ( V_172 )
* V_172 = false ;
return V_197 ;
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
struct V_25 * * V_198 , int V_168 )
{
unsigned long V_166 ;
T_5 V_199 ;
V_166 = F_173 ( V_130 , V_163 , & V_199 ) ;
if ( F_165 ( V_166 ) )
return - 1 ;
if ( V_199 < V_168 )
return 0 ;
return F_183 ( V_166 , V_168 , 1 , V_198 ) ;
}
static struct V_25 * F_205 ( T_1 V_1 )
{
if ( F_206 ( V_1 ) )
return V_200 ;
if ( F_1 ( V_1 ) ) {
F_130 ( 1 ) ;
return V_200 ;
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
static int F_219 ( unsigned long V_201 , int V_81 )
{
if ( V_201 > V_104 - V_81 )
return V_104 - V_81 ;
else
return V_201 ;
}
static int F_220 ( struct V_63 * V_130 , T_5 V_163 ,
void * V_202 , int V_81 , int V_201 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_176 ( V_130 , V_163 , NULL ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
V_26 = F_221 ( V_202 , ( void V_141 * ) V_166 + V_81 , V_201 ) ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_222 ( struct V_9 * V_9 , T_5 V_163 , void * V_202 , int V_81 ,
int V_201 )
{
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
return F_220 ( V_130 , V_163 , V_202 , V_81 , V_201 ) ;
}
int F_223 ( struct V_2 * V_3 , T_5 V_163 , void * V_202 ,
int V_81 , int V_201 )
{
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
return F_220 ( V_130 , V_163 , V_202 , V_81 , V_201 ) ;
}
int F_224 ( struct V_9 * V_9 , T_6 V_203 , void * V_202 , unsigned long V_201 )
{
T_5 V_163 = V_203 >> V_142 ;
int V_204 ;
int V_81 = F_225 ( V_203 ) ;
int V_205 ;
while ( ( V_204 = F_219 ( V_201 , V_81 ) ) != 0 ) {
V_205 = F_222 ( V_9 , V_163 , V_202 , V_81 , V_204 ) ;
if ( V_205 < 0 )
return V_205 ;
V_81 = 0 ;
V_201 -= V_204 ;
V_202 += V_204 ;
++ V_163 ;
}
return 0 ;
}
int F_226 ( struct V_2 * V_3 , T_6 V_203 , void * V_202 , unsigned long V_201 )
{
T_5 V_163 = V_203 >> V_142 ;
int V_204 ;
int V_81 = F_225 ( V_203 ) ;
int V_205 ;
while ( ( V_204 = F_219 ( V_201 , V_81 ) ) != 0 ) {
V_205 = F_223 ( V_3 , V_163 , V_202 , V_81 , V_204 ) ;
if ( V_205 < 0 )
return V_205 ;
V_81 = 0 ;
V_201 -= V_204 ;
V_202 += V_204 ;
++ V_163 ;
}
return 0 ;
}
static int F_227 ( struct V_63 * V_130 , T_5 V_163 ,
void * V_202 , int V_81 , unsigned long V_201 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_176 ( V_130 , V_163 , NULL ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
F_228 () ;
V_26 = F_229 ( V_202 , ( void V_141 * ) V_166 + V_81 , V_201 ) ;
F_230 () ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_231 ( struct V_9 * V_9 , T_6 V_203 , void * V_202 ,
unsigned long V_201 )
{
T_5 V_163 = V_203 >> V_142 ;
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
int V_81 = F_225 ( V_203 ) ;
return F_227 ( V_130 , V_163 , V_202 , V_81 , V_201 ) ;
}
int F_232 ( struct V_2 * V_3 , T_6 V_203 ,
void * V_202 , unsigned long V_201 )
{
T_5 V_163 = V_203 >> V_142 ;
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
int V_81 = F_225 ( V_203 ) ;
return F_227 ( V_130 , V_163 , V_202 , V_81 , V_201 ) ;
}
static int F_233 ( struct V_63 * V_64 , T_5 V_163 ,
const void * V_202 , int V_81 , int V_201 )
{
int V_26 ;
unsigned long V_166 ;
V_166 = F_174 ( V_64 , V_163 ) ;
if ( F_165 ( V_166 ) )
return - V_158 ;
V_26 = F_234 ( ( void V_141 * ) V_166 + V_81 , V_202 , V_201 ) ;
if ( V_26 )
return - V_158 ;
F_235 ( V_64 , V_163 ) ;
return 0 ;
}
int F_236 ( struct V_9 * V_9 , T_5 V_163 ,
const void * V_202 , int V_81 , int V_201 )
{
struct V_63 * V_130 = F_158 ( V_9 , V_163 ) ;
return F_233 ( V_130 , V_163 , V_202 , V_81 , V_201 ) ;
}
int F_237 ( struct V_2 * V_3 , T_5 V_163 ,
const void * V_202 , int V_81 , int V_201 )
{
struct V_63 * V_130 = F_160 ( V_3 , V_163 ) ;
return F_233 ( V_130 , V_163 , V_202 , V_81 , V_201 ) ;
}
int F_238 ( struct V_9 * V_9 , T_6 V_203 , const void * V_202 ,
unsigned long V_201 )
{
T_5 V_163 = V_203 >> V_142 ;
int V_204 ;
int V_81 = F_225 ( V_203 ) ;
int V_205 ;
while ( ( V_204 = F_219 ( V_201 , V_81 ) ) != 0 ) {
V_205 = F_236 ( V_9 , V_163 , V_202 , V_81 , V_204 ) ;
if ( V_205 < 0 )
return V_205 ;
V_81 = 0 ;
V_201 -= V_204 ;
V_202 += V_204 ;
++ V_163 ;
}
return 0 ;
}
int F_239 ( struct V_2 * V_3 , T_6 V_203 , const void * V_202 ,
unsigned long V_201 )
{
T_5 V_163 = V_203 >> V_142 ;
int V_204 ;
int V_81 = F_225 ( V_203 ) ;
int V_205 ;
while ( ( V_204 = F_219 ( V_201 , V_81 ) ) != 0 ) {
V_205 = F_237 ( V_3 , V_163 , V_202 , V_81 , V_204 ) ;
if ( V_205 < 0 )
return V_205 ;
V_81 = 0 ;
V_201 -= V_204 ;
V_202 += V_204 ;
++ V_163 ;
}
return 0 ;
}
int F_240 ( struct V_9 * V_9 , struct V_206 * V_207 ,
T_6 V_203 , unsigned long V_201 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_81 = F_225 ( V_203 ) ;
T_5 V_208 = V_203 >> V_142 ;
T_5 V_209 = ( V_203 + V_201 - 1 ) >> V_142 ;
T_5 V_210 = V_209 - V_208 + 1 ;
T_5 V_211 ;
V_207 -> V_203 = V_203 ;
V_207 -> V_59 = V_58 -> V_59 ;
V_207 -> V_201 = V_201 ;
V_207 -> V_64 = F_158 ( V_9 , V_208 ) ;
V_207 -> V_173 = F_173 ( V_207 -> V_64 , V_208 , NULL ) ;
if ( ! F_165 ( V_207 -> V_173 ) && V_210 <= 1 ) {
V_207 -> V_173 += V_81 ;
} else {
while ( V_208 <= V_209 ) {
V_207 -> V_64 = F_158 ( V_9 , V_208 ) ;
V_207 -> V_173 = F_173 ( V_207 -> V_64 , V_208 ,
& V_211 ) ;
if ( F_165 ( V_207 -> V_173 ) )
return - V_158 ;
V_208 += V_211 ;
}
V_207 -> V_64 = NULL ;
}
return 0 ;
}
int F_241 ( struct V_9 * V_9 , struct V_206 * V_207 ,
void * V_202 , unsigned long V_201 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
F_62 ( V_201 > V_207 -> V_201 ) ;
if ( V_58 -> V_59 != V_207 -> V_59 )
F_240 ( V_9 , V_207 , V_207 -> V_203 , V_207 -> V_201 ) ;
if ( F_25 ( ! V_207 -> V_64 ) )
return F_238 ( V_9 , V_207 -> V_203 , V_202 , V_201 ) ;
if ( F_165 ( V_207 -> V_173 ) )
return - V_158 ;
V_26 = F_234 ( ( void V_141 * ) V_207 -> V_173 , V_202 , V_201 ) ;
if ( V_26 )
return - V_158 ;
F_235 ( V_207 -> V_64 , V_207 -> V_203 >> V_142 ) ;
return 0 ;
}
int F_242 ( struct V_9 * V_9 , struct V_206 * V_207 ,
void * V_202 , unsigned long V_201 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
int V_26 ;
F_62 ( V_201 > V_207 -> V_201 ) ;
if ( V_58 -> V_59 != V_207 -> V_59 )
F_240 ( V_9 , V_207 , V_207 -> V_203 , V_207 -> V_201 ) ;
if ( F_25 ( ! V_207 -> V_64 ) )
return F_224 ( V_9 , V_207 -> V_203 , V_202 , V_201 ) ;
if ( F_165 ( V_207 -> V_173 ) )
return - V_158 ;
V_26 = F_221 ( V_202 , ( void V_141 * ) V_207 -> V_173 , V_201 ) ;
if ( V_26 )
return - V_158 ;
return 0 ;
}
int F_243 ( struct V_9 * V_9 , T_5 V_163 , int V_81 , int V_201 )
{
const void * V_212 = ( const void * ) F_244 ( F_245 ( F_246 ( 0 ) ) ) ;
return F_236 ( V_9 , V_163 , V_212 , V_81 , V_201 ) ;
}
int F_247 ( struct V_9 * V_9 , T_6 V_203 , unsigned long V_201 )
{
T_5 V_163 = V_203 >> V_142 ;
int V_204 ;
int V_81 = F_225 ( V_203 ) ;
int V_205 ;
while ( ( V_204 = F_219 ( V_201 , V_81 ) ) != 0 ) {
V_205 = F_243 ( V_9 , V_163 , V_81 , V_204 ) ;
if ( V_205 < 0 )
return V_205 ;
V_81 = 0 ;
V_201 -= V_204 ;
++ V_163 ;
}
return 0 ;
}
static void F_235 ( struct V_63 * V_64 ,
T_5 V_163 )
{
if ( V_64 && V_64 -> V_65 ) {
unsigned long V_213 = V_163 - V_64 -> V_120 ;
F_248 ( V_213 , V_64 -> V_65 ) ;
}
}
void F_249 ( struct V_9 * V_9 , T_5 V_163 )
{
struct V_63 * V_64 ;
V_64 = F_158 ( V_9 , V_163 ) ;
F_235 ( V_64 , V_163 ) ;
}
void F_250 ( struct V_2 * V_3 , T_5 V_163 )
{
struct V_63 * V_64 ;
V_64 = F_160 ( V_3 , V_163 ) ;
F_235 ( V_64 , V_163 ) ;
}
static void F_251 ( struct V_2 * V_3 )
{
unsigned int V_131 , V_214 , V_215 ;
V_131 = V_214 = V_3 -> V_216 ;
V_215 = F_252 ( V_217 ) ;
if ( V_214 == 0 && V_215 )
V_214 = 10000 ;
else
V_214 *= V_215 ;
if ( V_214 > V_216 )
V_214 = V_216 ;
V_3 -> V_216 = V_214 ;
F_253 ( V_3 -> V_27 , V_214 , V_131 ) ;
}
static void F_254 ( struct V_2 * V_3 )
{
unsigned int V_131 , V_214 , V_218 ;
V_131 = V_214 = V_3 -> V_216 ;
V_218 = F_252 ( V_219 ) ;
if ( V_218 == 0 )
V_214 = 0 ;
else
V_214 /= V_218 ;
V_3 -> V_216 = V_214 ;
F_255 ( V_3 -> V_27 , V_214 , V_131 ) ;
}
static int F_256 ( struct V_2 * V_3 )
{
if ( F_257 ( V_3 ) ) {
F_21 ( V_220 , V_3 ) ;
return - V_6 ;
}
if ( F_258 ( V_3 ) )
return - V_6 ;
if ( F_259 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_260 ( struct V_2 * V_3 )
{
T_7 V_50 , V_221 ;
F_261 ( V_222 ) ;
bool V_223 = false ;
T_8 V_224 ;
V_50 = V_221 = F_262 () ;
if ( V_3 -> V_216 ) {
T_7 V_225 = F_263 ( F_262 () , V_3 -> V_216 ) ;
++ V_3 -> V_21 . V_226 ;
do {
if ( F_256 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_227 ;
if ( ! F_264 ( V_3 ) )
++ V_3 -> V_21 . V_228 ;
goto V_134;
}
V_221 = F_262 () ;
} while ( F_265 () && F_266 ( V_221 , V_225 ) );
}
F_267 ( V_3 ) ;
for (; ; ) {
F_268 ( & V_3 -> V_29 , & V_222 , V_229 ) ;
if ( F_256 ( V_3 ) < 0 )
break;
V_223 = true ;
F_269 () ;
}
F_270 ( & V_3 -> V_29 , & V_222 ) ;
V_221 = F_262 () ;
F_271 ( V_3 ) ;
V_134:
V_224 = F_272 ( V_221 ) - F_272 ( V_50 ) ;
if ( ! F_264 ( V_3 ) )
F_254 ( V_3 ) ;
else if ( V_216 ) {
if ( V_224 <= V_3 -> V_216 )
;
else if ( V_3 -> V_216 && V_224 > V_216 )
F_254 ( V_3 ) ;
else if ( V_3 -> V_216 < V_216 &&
V_224 < V_216 )
F_251 ( V_3 ) ;
} else
V_3 -> V_216 = 0 ;
F_273 ( V_224 , V_223 , F_264 ( V_3 ) ) ;
F_274 ( V_3 ) ;
}
void F_275 ( struct V_2 * V_3 )
{
struct V_230 * V_231 ;
V_231 = F_276 ( V_3 ) ;
if ( F_277 ( V_231 ) ) {
F_278 ( V_231 ) ;
++ V_3 -> V_21 . V_232 ;
}
}
void F_279 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
F_275 ( V_3 ) ;
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_233 && F_280 ( V_4 ) )
if ( F_281 ( V_3 ) )
F_282 ( V_4 ) ;
F_10 () ;
}
int F_283 ( struct V_2 * V_234 )
{
struct V_28 * V_28 ;
struct V_235 * V_236 = NULL ;
int V_205 = 0 ;
F_284 () ;
V_28 = F_285 ( V_234 -> V_28 ) ;
if ( V_28 )
V_236 = F_286 ( V_28 , V_237 ) ;
F_287 () ;
if ( ! V_236 )
return V_205 ;
V_205 = F_288 ( V_236 , 1 ) ;
F_289 ( V_236 ) ;
return V_205 ;
}
static bool F_290 ( struct V_2 * V_3 )
{
#ifdef F_291
bool V_238 ;
V_238 = ! V_3 -> V_239 . V_240 ||
V_3 -> V_239 . V_241 ;
if ( V_3 -> V_239 . V_240 )
F_41 ( V_3 , ! V_3 -> V_239 . V_241 ) ;
return V_238 ;
#else
return true ;
#endif
}
void F_292 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_242 = V_12 -> V_9 -> V_242 ;
int V_243 = 0 ;
int V_244 = 3 ;
int V_245 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_245 = 0 ; V_245 < 2 && ! V_243 && V_244 ; V_245 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_245 && V_11 <= V_242 ) {
V_11 = V_242 ;
continue;
} else if ( V_245 && V_11 > V_242 )
break;
if ( ! F_293 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_277 ( & V_3 -> V_29 ) && ! F_257 ( V_3 ) )
continue;
if ( ! F_290 ( V_3 ) )
continue;
V_243 = F_283 ( V_3 ) ;
if ( V_243 > 0 ) {
V_9 -> V_242 = V_11 ;
break;
} else if ( V_243 < 0 ) {
V_244 -- ;
if ( ! V_244 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_294 ( struct V_164 * V_165 , struct V_246 * V_247 )
{
struct V_2 * V_3 = V_165 -> V_248 -> V_115 ;
struct V_25 * V_25 ;
if ( V_247 -> V_249 == 0 )
V_25 = F_295 ( V_3 -> V_36 ) ;
#ifdef F_296
else if ( V_247 -> V_249 == V_250 )
V_25 = F_295 ( V_3 -> V_152 . V_251 ) ;
#endif
#ifdef F_297
else if ( V_247 -> V_249 == F_297 )
V_25 = F_295 ( V_3 -> V_9 -> V_252 ) ;
#endif
else
return F_298 ( V_3 , V_247 ) ;
F_218 ( V_25 ) ;
V_247 -> V_25 = V_25 ;
return 0 ;
}
static int F_299 ( struct V_113 * V_113 , struct V_164 * V_165 )
{
V_165 -> V_253 = & V_254 ;
return 0 ;
}
static int F_300 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
F_81 ( V_3 -> V_68 ) ;
F_123 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_301 ( struct V_2 * V_3 )
{
return F_302 ( L_2 , & V_255 , V_3 , V_256 | V_257 ) ;
}
static int F_303 ( struct V_2 * V_3 )
{
char V_72 [ V_73 * 2 ] ;
int V_205 ;
if ( ! F_304 () )
return 0 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_72 , sizeof( V_72 ) , L_3 , V_3 -> V_27 ) ;
V_3 -> V_68 = F_86 ( V_72 ,
V_3 -> V_9 -> V_68 ) ;
if ( ! V_3 -> V_68 )
return - V_34 ;
V_205 = F_305 ( V_3 ) ;
if ( V_205 < 0 ) {
F_81 ( V_3 -> V_68 ) ;
return V_205 ;
}
return 0 ;
}
static int F_306 ( struct V_9 * V_9 , T_4 V_24 )
{
int V_26 ;
struct V_2 * V_3 ;
if ( V_24 >= V_258 )
return - V_127 ;
F_149 ( & V_9 -> V_85 ) ;
if ( V_9 -> V_259 == V_260 ) {
F_16 ( & V_9 -> V_85 ) ;
return - V_127 ;
}
V_9 -> V_259 ++ ;
F_16 ( & V_9 -> V_85 ) ;
V_3 = F_307 ( V_9 , V_24 ) ;
if ( F_308 ( V_3 ) ) {
V_26 = F_309 ( V_3 ) ;
goto V_261;
}
F_310 ( & V_3 -> V_7 , & V_262 ) ;
V_26 = F_311 ( V_3 ) ;
if ( V_26 )
goto V_263;
V_26 = F_303 ( V_3 ) ;
if ( V_26 )
goto V_263;
F_149 ( & V_9 -> V_85 ) ;
if ( F_312 ( V_9 , V_24 ) ) {
V_26 = - V_148 ;
goto V_264;
}
F_62 ( V_9 -> V_265 [ F_313 ( & V_9 -> V_266 ) ] ) ;
F_122 ( V_9 ) ;
V_26 = F_301 ( V_3 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
goto V_264;
}
V_9 -> V_265 [ F_313 ( & V_9 -> V_266 ) ] = V_3 ;
F_61 () ;
F_94 ( & V_9 -> V_266 ) ;
F_16 ( & V_9 -> V_85 ) ;
F_314 ( V_3 ) ;
return V_26 ;
V_264:
F_16 ( & V_9 -> V_85 ) ;
F_81 ( V_3 -> V_68 ) ;
V_263:
F_315 ( V_3 ) ;
V_261:
F_149 ( & V_9 -> V_85 ) ;
V_9 -> V_259 -- ;
F_16 ( & V_9 -> V_85 ) ;
return V_26 ;
}
static int F_316 ( struct V_2 * V_3 , T_9 * V_267 )
{
if ( V_267 ) {
F_317 ( V_267 , F_318 ( V_268 ) | F_318 ( V_269 ) ) ;
V_3 -> V_270 = 1 ;
V_3 -> V_267 = * V_267 ;
} else
V_3 -> V_270 = 0 ;
return 0 ;
}
static long F_319 ( struct V_113 * V_114 ,
unsigned int V_271 , unsigned long V_272 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
void V_141 * V_273 = ( void V_141 * ) V_272 ;
int V_26 ;
struct V_274 * V_275 = NULL ;
struct V_276 * V_276 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_277 ;
if ( F_25 ( F_320 ( V_271 ) != V_278 ) )
return - V_127 ;
#if F_118 ( V_279 ) || F_118 ( V_280 ) || F_118 ( V_281 )
if ( V_271 == V_282 || V_271 == V_283 || V_271 == V_284 )
return F_321 ( V_114 , V_271 , V_272 ) ;
#endif
V_26 = F_5 ( V_3 ) ;
if ( V_26 )
return V_26 ;
switch ( V_271 ) {
case V_285 :
V_26 = - V_127 ;
if ( V_272 )
goto V_134;
if ( F_25 ( V_3 -> V_28 != V_56 -> V_286 [ V_237 ] . V_28 ) ) {
struct V_28 * V_287 = V_3 -> V_28 ;
struct V_28 * V_288 = F_322 ( V_56 , V_237 ) ;
F_136 ( V_3 -> V_28 , V_288 ) ;
if ( V_287 )
F_323 () ;
F_45 ( V_287 ) ;
}
V_26 = F_324 ( V_3 , V_3 -> V_36 ) ;
F_325 ( V_3 -> V_36 -> V_289 , V_26 ) ;
break;
case V_290 : {
struct V_291 * V_291 ;
V_26 = - V_34 ;
V_291 = F_88 ( sizeof( struct V_291 ) , V_32 ) ;
if ( ! V_291 )
goto V_134;
V_26 = F_326 ( V_3 , V_291 ) ;
if ( V_26 )
goto V_292;
V_26 = - V_158 ;
if ( F_152 ( V_273 , V_291 , sizeof( struct V_291 ) ) )
goto V_292;
V_26 = 0 ;
V_292:
F_82 ( V_291 ) ;
break;
}
case V_293 : {
struct V_291 * V_291 ;
V_26 = - V_34 ;
V_291 = F_327 ( V_273 , sizeof( * V_291 ) ) ;
if ( F_308 ( V_291 ) ) {
V_26 = F_309 ( V_291 ) ;
goto V_134;
}
V_26 = F_328 ( V_3 , V_291 ) ;
F_82 ( V_291 ) ;
break;
}
case V_294 : {
V_276 = F_88 ( sizeof( struct V_276 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_276 )
goto V_134;
V_26 = F_329 ( V_3 , V_276 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_273 , V_276 , sizeof( struct V_276 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_295 : {
V_276 = F_327 ( V_273 , sizeof( * V_276 ) ) ;
if ( F_308 ( V_276 ) ) {
V_26 = F_309 ( V_276 ) ;
V_276 = NULL ;
goto V_134;
}
V_26 = F_330 ( V_3 , V_276 ) ;
break;
}
case V_296 : {
struct V_297 V_298 ;
V_26 = F_331 ( V_3 , & V_298 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_273 , & V_298 , sizeof( V_298 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_299 : {
struct V_297 V_298 ;
V_26 = - V_158 ;
if ( F_332 ( & V_298 , V_273 , sizeof( V_298 ) ) )
goto V_134;
V_26 = F_333 ( V_3 , & V_298 ) ;
break;
}
case V_300 : {
struct V_301 V_302 ;
V_26 = - V_158 ;
if ( F_332 ( & V_302 , V_273 , sizeof( V_302 ) ) )
goto V_134;
V_26 = F_334 ( V_3 , & V_302 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_273 , & V_302 , sizeof( V_302 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_303 : {
struct V_304 V_305 ;
V_26 = - V_158 ;
if ( F_332 ( & V_305 , V_273 , sizeof( V_305 ) ) )
goto V_134;
V_26 = F_335 ( V_3 , & V_305 ) ;
break;
}
case V_306 : {
struct V_307 V_141 * V_308 = V_273 ;
struct V_307 V_309 ;
T_9 V_267 , * V_77 ;
V_77 = NULL ;
if ( V_273 ) {
V_26 = - V_158 ;
if ( F_332 ( & V_309 , V_273 ,
sizeof( V_309 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_309 . V_201 != sizeof( V_267 ) )
goto V_134;
V_26 = - V_158 ;
if ( F_332 ( & V_267 , V_308 -> V_267 ,
sizeof( V_267 ) ) )
goto V_134;
V_77 = & V_267 ;
}
V_26 = F_316 ( V_3 , V_77 ) ;
break;
}
case V_310 : {
V_275 = F_88 ( sizeof( struct V_274 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_275 )
goto V_134;
V_26 = F_336 ( V_3 , V_275 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_273 , V_275 , sizeof( struct V_274 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_311 : {
V_275 = F_327 ( V_273 , sizeof( * V_275 ) ) ;
if ( F_308 ( V_275 ) ) {
V_26 = F_309 ( V_275 ) ;
V_275 = NULL ;
goto V_134;
}
V_26 = F_337 ( V_3 , V_275 ) ;
break;
}
default:
V_26 = F_321 ( V_114 , V_271 , V_272 ) ;
}
V_134:
F_11 ( V_3 ) ;
F_82 ( V_275 ) ;
F_82 ( V_276 ) ;
return V_26 ;
}
static long F_338 ( struct V_113 * V_114 ,
unsigned int V_271 , unsigned long V_272 )
{
struct V_2 * V_3 = V_114 -> V_115 ;
void V_141 * V_273 = F_339 ( V_272 ) ;
int V_26 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_277 ;
switch ( V_271 ) {
case V_306 : {
struct V_307 V_141 * V_308 = V_273 ;
struct V_307 V_309 ;
T_10 V_312 ;
T_9 V_267 ;
if ( V_273 ) {
V_26 = - V_158 ;
if ( F_332 ( & V_309 , V_273 ,
sizeof( V_309 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_309 . V_201 != sizeof( V_312 ) )
goto V_134;
V_26 = - V_158 ;
if ( F_332 ( & V_312 , V_308 -> V_267 ,
sizeof( V_312 ) ) )
goto V_134;
F_340 ( & V_267 , & V_312 ) ;
V_26 = F_316 ( V_3 , & V_267 ) ;
} else
V_26 = F_316 ( V_3 , NULL ) ;
break;
}
default:
V_26 = F_319 ( V_114 , V_271 , V_272 ) ;
}
V_134:
return V_26 ;
}
static int F_341 ( struct V_105 * V_106 ,
int (* F_342)( struct V_105 * V_106 ,
struct V_313 * V_314 ) ,
unsigned long V_272 )
{
struct V_313 V_314 ;
if ( ! F_342 )
return - V_315 ;
if ( F_332 ( & V_314 , ( void V_141 * ) V_272 , sizeof( V_314 ) ) )
return - V_158 ;
return F_342 ( V_106 , & V_314 ) ;
}
static long F_343 ( struct V_113 * V_114 , unsigned int V_271 ,
unsigned long V_272 )
{
struct V_105 * V_106 = V_114 -> V_115 ;
switch ( V_271 ) {
case V_316 :
return F_341 ( V_106 , V_106 -> V_54 -> V_317 , V_272 ) ;
case V_318 :
return F_341 ( V_106 , V_106 -> V_54 -> V_319 , V_272 ) ;
case V_320 :
return F_341 ( V_106 , V_106 -> V_54 -> V_321 , V_272 ) ;
default:
if ( V_106 -> V_54 -> V_271 )
return V_106 -> V_54 -> V_271 ( V_106 , V_271 , V_272 ) ;
return - V_322 ;
}
}
static int F_344 ( struct V_112 * V_112 , struct V_113 * V_114 )
{
struct V_105 * V_106 = V_114 -> V_115 ;
struct V_9 * V_9 = V_106 -> V_9 ;
F_123 ( V_9 ) ;
return 0 ;
}
struct V_105 * F_345 ( struct V_113 * V_114 )
{
if ( V_114 -> V_323 != & V_324 )
return NULL ;
return V_114 -> V_115 ;
}
int F_346 ( struct V_325 * V_54 , T_4 type )
{
if ( type >= F_347 ( V_326 ) )
return - V_327 ;
if ( V_326 [ type ] != NULL )
return - V_148 ;
V_326 [ type ] = V_54 ;
return 0 ;
}
void F_348 ( T_4 type )
{
if ( V_326 [ type ] != NULL )
V_326 [ type ] = NULL ;
}
static int F_349 ( struct V_9 * V_9 ,
struct V_328 * V_329 )
{
struct V_325 * V_54 = NULL ;
struct V_105 * V_106 ;
bool V_330 = V_329 -> V_126 & V_331 ;
int V_205 ;
if ( V_329 -> type >= F_347 ( V_326 ) )
return - V_332 ;
V_54 = V_326 [ V_329 -> type ] ;
if ( V_54 == NULL )
return - V_332 ;
if ( V_330 )
return 0 ;
V_106 = F_88 ( sizeof( * V_106 ) , V_32 ) ;
if ( ! V_106 )
return - V_34 ;
V_106 -> V_54 = V_54 ;
V_106 -> V_9 = V_9 ;
F_149 ( & V_9 -> V_85 ) ;
V_205 = V_54 -> V_333 ( V_106 , V_329 -> type ) ;
if ( V_205 < 0 ) {
F_16 ( & V_9 -> V_85 ) ;
F_82 ( V_106 ) ;
return V_205 ;
}
F_103 ( & V_106 -> V_108 , & V_9 -> V_89 ) ;
F_16 ( & V_9 -> V_85 ) ;
if ( V_54 -> V_334 )
V_54 -> V_334 ( V_106 ) ;
V_205 = F_302 ( V_54 -> V_80 , & V_324 , V_106 , V_256 | V_257 ) ;
if ( V_205 < 0 ) {
F_149 ( & V_9 -> V_85 ) ;
F_112 ( & V_106 -> V_108 ) ;
F_16 ( & V_9 -> V_85 ) ;
V_54 -> V_109 ( V_106 ) ;
return V_205 ;
}
F_122 ( V_9 ) ;
V_329 -> V_71 = V_205 ;
return 0 ;
}
static long F_350 ( struct V_9 * V_9 , long V_272 )
{
switch ( V_272 ) {
case V_335 :
case V_336 :
case V_337 :
case V_338 :
#ifdef F_351
case V_339 :
#endif
#ifdef F_99
case V_340 :
case V_341 :
#endif
case V_342 :
case V_343 :
return 1 ;
#ifdef F_352
case V_344 :
return V_345 ;
#endif
#if V_93 > 1
case V_346 :
return V_93 ;
#endif
case V_347 :
return V_258 ;
default:
break;
}
return F_353 ( V_9 , V_272 ) ;
}
static long F_354 ( struct V_113 * V_114 ,
unsigned int V_271 , unsigned long V_272 )
{
struct V_9 * V_9 = V_114 -> V_115 ;
void V_141 * V_273 = ( void V_141 * ) V_272 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_277 ;
switch ( V_271 ) {
case V_348 :
V_26 = F_306 ( V_9 , V_272 ) ;
break;
case V_349 : {
struct V_121 V_350 ;
V_26 = - V_158 ;
if ( F_332 ( & V_350 , V_273 ,
sizeof( V_350 ) ) )
goto V_134;
V_26 = F_150 ( V_9 , & V_350 ) ;
break;
}
case V_351 : {
struct V_153 log ;
V_26 = - V_158 ;
if ( F_332 ( & log , V_273 , sizeof( log ) ) )
goto V_134;
V_26 = F_355 ( V_9 , & log ) ;
break;
}
#ifdef F_297
case V_352 : {
struct V_353 V_354 ;
V_26 = - V_158 ;
if ( F_332 ( & V_354 , V_273 , sizeof( V_354 ) ) )
goto V_134;
V_26 = F_356 ( V_9 , & V_354 ) ;
break;
}
case V_355 : {
struct V_353 V_354 ;
V_26 = - V_158 ;
if ( F_332 ( & V_354 , V_273 , sizeof( V_354 ) ) )
goto V_134;
V_26 = F_357 ( V_9 , & V_354 ) ;
break;
}
#endif
case V_356 : {
struct V_357 V_202 ;
V_26 = - V_158 ;
if ( F_332 ( & V_202 , V_273 , sizeof( V_202 ) ) )
goto V_134;
V_26 = V_357 ( V_9 , & V_202 ) ;
break;
}
case V_358 : {
struct V_359 V_202 ;
V_26 = - V_158 ;
if ( F_332 ( & V_202 , V_273 , sizeof( V_202 ) ) )
goto V_134;
V_26 = V_359 ( V_9 , & V_202 ) ;
break;
}
#ifdef F_351
case V_360 : {
struct V_361 V_362 ;
V_26 = - V_158 ;
if ( F_332 ( & V_362 , V_273 , sizeof( V_362 ) ) )
goto V_134;
V_26 = F_358 ( V_9 , & V_362 ) ;
break;
}
#endif
#ifdef F_359
case V_363 :
case V_364 : {
struct V_365 V_366 ;
V_26 = - V_158 ;
if ( F_332 ( & V_366 , V_273 , sizeof( V_366 ) ) )
goto V_134;
V_26 = F_360 ( V_9 , & V_366 ,
V_271 == V_363 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( V_271 == V_363 ) {
if ( F_152 ( V_273 , & V_366 , sizeof( V_366 ) ) )
goto V_134;
}
V_26 = 0 ;
break;
}
#endif
#ifdef F_352
case V_367 : {
struct V_368 V_369 ;
struct V_368 V_141 * V_370 ;
struct V_371 * V_372 = NULL ;
V_26 = - V_158 ;
if ( F_332 ( & V_369 , V_273 , sizeof( V_369 ) ) )
goto V_134;
V_26 = - V_127 ;
if ( V_369 . V_373 > V_345 )
goto V_134;
if ( V_369 . V_126 )
goto V_134;
if ( V_369 . V_373 ) {
V_26 = - V_34 ;
V_372 = F_361 ( V_369 . V_373 * sizeof( * V_372 ) ) ;
if ( ! V_372 )
goto V_134;
V_26 = - V_158 ;
V_370 = V_273 ;
if ( F_332 ( V_372 , V_370 -> V_372 ,
V_369 . V_373 * sizeof( * V_372 ) ) )
goto V_374;
}
V_26 = F_362 ( V_9 , V_372 , V_369 . V_373 ,
V_369 . V_126 ) ;
V_374:
F_363 ( V_372 ) ;
break;
}
#endif
case V_375 : {
struct V_328 V_329 ;
V_26 = - V_158 ;
if ( F_332 ( & V_329 , V_273 , sizeof( V_329 ) ) )
goto V_134;
V_26 = F_349 ( V_9 , & V_329 ) ;
if ( V_26 )
goto V_134;
V_26 = - V_158 ;
if ( F_152 ( V_273 , & V_329 , sizeof( V_329 ) ) )
goto V_134;
V_26 = 0 ;
break;
}
case V_376 :
V_26 = F_350 ( V_9 , V_272 ) ;
break;
default:
V_26 = F_364 ( V_114 , V_271 , V_272 ) ;
}
V_134:
return V_26 ;
}
static long F_365 ( struct V_113 * V_114 ,
unsigned int V_271 , unsigned long V_272 )
{
struct V_9 * V_9 = V_114 -> V_115 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_277 ;
switch ( V_271 ) {
case V_351 : {
struct V_377 V_378 ;
struct V_153 log ;
V_26 = - V_158 ;
if ( F_332 ( & V_378 , ( void V_141 * ) V_272 ,
sizeof( V_378 ) ) )
goto V_134;
log . V_130 = V_378 . V_130 ;
log . V_379 = V_378 . V_379 ;
log . V_380 = V_378 . V_380 ;
log . V_65 = F_339 ( V_378 . V_65 ) ;
V_26 = F_355 ( V_9 , & log ) ;
break;
}
default:
V_26 = F_354 ( V_114 , V_271 , V_272 ) ;
}
V_134:
return V_26 ;
}
static int F_366 ( unsigned long type )
{
int V_26 ;
struct V_9 * V_9 ;
struct V_113 * V_113 ;
V_9 = F_90 ( type ) ;
if ( F_308 ( V_9 ) )
return F_309 ( V_9 ) ;
#ifdef F_297
V_26 = F_367 ( V_9 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
return V_26 ;
}
#endif
V_26 = F_368 ( V_257 ) ;
if ( V_26 < 0 ) {
F_123 ( V_9 ) ;
return V_26 ;
}
V_113 = F_369 ( L_4 , & V_381 , V_9 , V_256 ) ;
if ( F_308 ( V_113 ) ) {
F_370 ( V_26 ) ;
F_123 ( V_9 ) ;
return F_309 ( V_113 ) ;
}
if ( F_83 ( V_9 , V_26 ) < 0 ) {
F_370 ( V_26 ) ;
F_371 ( V_113 ) ;
return - V_34 ;
}
F_372 ( V_26 , V_113 ) ;
return V_26 ;
}
static long F_373 ( struct V_113 * V_114 ,
unsigned int V_271 , unsigned long V_272 )
{
long V_26 = - V_127 ;
switch ( V_271 ) {
case V_382 :
if ( V_272 )
goto V_134;
V_26 = V_383 ;
break;
case V_384 :
V_26 = F_366 ( V_272 ) ;
break;
case V_376 :
V_26 = F_350 ( NULL , V_272 ) ;
break;
case V_385 :
if ( V_272 )
goto V_134;
V_26 = V_104 ;
#ifdef F_296
V_26 += V_104 ;
#endif
#ifdef F_297
V_26 += V_104 ;
#endif
break;
case V_386 :
case V_387 :
case V_388 :
V_26 = - V_389 ;
break;
default:
return F_374 ( V_114 , V_271 , V_272 ) ;
}
V_134:
return V_26 ;
}
static void F_375 ( void * V_390 )
{
int V_4 = F_376 () ;
int V_26 ;
if ( F_377 ( V_4 , V_391 ) )
return;
F_24 ( V_4 , V_391 ) ;
V_26 = F_378 () ;
if ( V_26 ) {
F_379 ( V_4 , V_391 ) ;
F_94 ( & V_392 ) ;
F_380 ( L_5 , V_4 ) ;
}
}
static int F_381 ( unsigned int V_4 )
{
F_382 ( & V_393 ) ;
if ( V_394 )
F_375 ( NULL ) ;
F_383 ( & V_393 ) ;
return 0 ;
}
static void F_384 ( void * V_390 )
{
int V_4 = F_376 () ;
if ( ! F_377 ( V_4 , V_391 ) )
return;
F_379 ( V_4 , V_391 ) ;
F_385 () ;
}
static int F_386 ( unsigned int V_4 )
{
F_382 ( & V_393 ) ;
if ( V_394 )
F_384 ( NULL ) ;
F_383 ( & V_393 ) ;
return 0 ;
}
static void F_387 ( void )
{
F_62 ( ! V_394 ) ;
V_394 -- ;
if ( ! V_394 )
F_388 ( F_384 , NULL , 1 ) ;
}
static void F_106 ( void )
{
F_382 ( & V_393 ) ;
F_387 () ;
F_383 ( & V_393 ) ;
}
static int F_98 ( void )
{
int V_26 = 0 ;
F_382 ( & V_393 ) ;
V_394 ++ ;
if ( V_394 == 1 ) {
F_96 ( & V_392 , 0 ) ;
F_388 ( F_375 , NULL , 1 ) ;
if ( F_313 ( & V_392 ) ) {
F_387 () ;
V_26 = - V_395 ;
}
}
F_383 ( & V_393 ) ;
return V_26 ;
}
static int F_389 ( struct V_396 * V_397 , unsigned long V_214 ,
void * V_398 )
{
F_380 ( L_6 ) ;
V_399 = true ;
F_388 ( F_384 , NULL , 1 ) ;
return V_400 ;
}
static void F_116 ( struct V_99 * V_401 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_401 -> V_402 ; V_11 ++ ) {
struct V_403 * V_404 = V_401 -> V_405 [ V_11 ] . V_106 ;
F_390 ( V_404 ) ;
}
F_82 ( V_401 ) ;
}
static inline int F_391 ( const struct V_406 * V_407 ,
const struct V_406 * V_408 )
{
T_6 V_409 = V_407 -> V_166 ;
T_6 V_410 = V_408 -> V_166 ;
if ( V_409 < V_410 )
return - 1 ;
if ( V_408 -> V_201 ) {
V_409 += V_407 -> V_201 ;
V_410 += V_408 -> V_201 ;
}
if ( V_409 > V_410 )
return 1 ;
return 0 ;
}
static int F_392 ( const void * V_411 , const void * V_412 )
{
return F_391 ( V_411 , V_412 ) ;
}
static int F_393 ( struct V_99 * V_401 , struct V_403 * V_106 ,
T_6 V_166 , int V_201 )
{
V_401 -> V_405 [ V_401 -> V_402 ++ ] = (struct V_406 ) {
. V_166 = V_166 ,
. V_201 = V_201 ,
. V_106 = V_106 ,
} ;
F_394 ( V_401 -> V_405 , V_401 -> V_402 , sizeof( struct V_406 ) ,
F_392 , NULL ) ;
return 0 ;
}
static int F_395 ( struct V_99 * V_401 ,
T_6 V_166 , int V_201 )
{
struct V_406 * V_405 , V_413 ;
int V_414 ;
V_413 = (struct V_406 ) {
. V_166 = V_166 ,
. V_201 = V_201 ,
} ;
V_405 = bsearch ( & V_413 , V_401 -> V_405 , V_401 -> V_402 ,
sizeof( struct V_406 ) , F_392 ) ;
if ( V_405 == NULL )
return - V_157 ;
V_414 = V_405 - V_401 -> V_405 ;
while ( V_414 > 0 && F_391 ( & V_413 , & V_401 -> V_405 [ V_414 - 1 ] ) == 0 )
V_414 -- ;
return V_414 ;
}
static int F_396 ( struct V_2 * V_3 , struct V_99 * V_401 ,
struct V_406 * V_405 , const void * V_214 )
{
int V_45 ;
V_45 = F_395 ( V_401 , V_405 -> V_166 , V_405 -> V_201 ) ;
if ( V_45 < 0 )
return - V_389 ;
while ( V_45 < V_401 -> V_402 &&
F_391 ( V_405 , & V_401 -> V_405 [ V_45 ] ) == 0 ) {
if ( ! F_397 ( V_3 , V_401 -> V_405 [ V_45 ] . V_106 , V_405 -> V_166 ,
V_405 -> V_201 , V_214 ) )
return V_45 ;
V_45 ++ ;
}
return - V_389 ;
}
int F_398 ( struct V_2 * V_3 , enum V_415 V_416 , T_6 V_166 ,
int V_201 , const void * V_214 )
{
struct V_99 * V_401 ;
struct V_406 V_405 ;
int V_26 ;
V_405 = (struct V_406 ) {
. V_166 = V_166 ,
. V_201 = V_201 ,
} ;
V_401 = F_399 ( V_3 -> V_9 -> V_98 [ V_416 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_396 ( V_3 , V_401 , & V_405 , V_214 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_400 ( struct V_2 * V_3 , enum V_415 V_416 ,
T_6 V_166 , int V_201 , const void * V_214 , long V_417 )
{
struct V_99 * V_401 ;
struct V_406 V_405 ;
V_405 = (struct V_406 ) {
. V_166 = V_166 ,
. V_201 = V_201 ,
} ;
V_401 = F_399 ( V_3 -> V_9 -> V_98 [ V_416 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ( V_417 >= 0 ) && ( V_417 < V_401 -> V_402 ) &&
( F_391 ( & V_405 , & V_401 -> V_405 [ V_417 ] ) == 0 ) )
if ( ! F_397 ( V_3 , V_401 -> V_405 [ V_417 ] . V_106 , V_166 , V_201 ,
V_214 ) )
return V_417 ;
return F_396 ( V_3 , V_401 , & V_405 , V_214 ) ;
}
static int F_401 ( struct V_2 * V_3 , struct V_99 * V_401 ,
struct V_406 * V_405 , void * V_214 )
{
int V_45 ;
V_45 = F_395 ( V_401 , V_405 -> V_166 , V_405 -> V_201 ) ;
if ( V_45 < 0 )
return - V_389 ;
while ( V_45 < V_401 -> V_402 &&
F_391 ( V_405 , & V_401 -> V_405 [ V_45 ] ) == 0 ) {
if ( ! F_402 ( V_3 , V_401 -> V_405 [ V_45 ] . V_106 , V_405 -> V_166 ,
V_405 -> V_201 , V_214 ) )
return V_45 ;
V_45 ++ ;
}
return - V_389 ;
}
int F_403 ( struct V_2 * V_3 , enum V_415 V_416 , T_6 V_166 ,
int V_201 , void * V_214 )
{
struct V_99 * V_401 ;
struct V_406 V_405 ;
int V_26 ;
V_405 = (struct V_406 ) {
. V_166 = V_166 ,
. V_201 = V_201 ,
} ;
V_401 = F_399 ( V_3 -> V_9 -> V_98 [ V_416 ] , & V_3 -> V_9 -> V_46 ) ;
V_26 = F_401 ( V_3 , V_401 , & V_405 , V_214 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_404 ( struct V_9 * V_9 , enum V_415 V_416 , T_6 V_166 ,
int V_201 , struct V_403 * V_106 )
{
struct V_99 * V_418 , * V_401 ;
V_401 = V_9 -> V_98 [ V_416 ] ;
if ( V_401 -> V_402 - V_401 -> V_419 > V_420 - 1 )
return - V_327 ;
V_418 = F_405 ( sizeof( * V_401 ) + ( ( V_401 -> V_402 + 1 ) *
sizeof( struct V_406 ) ) , V_32 ) ;
if ( ! V_418 )
return - V_34 ;
memcpy ( V_418 , V_401 , sizeof( * V_401 ) + ( V_401 -> V_402 *
sizeof( struct V_406 ) ) ) ;
F_393 ( V_418 , V_106 , V_166 , V_201 ) ;
F_136 ( V_9 -> V_98 [ V_416 ] , V_418 ) ;
F_137 ( & V_9 -> V_46 ) ;
F_82 ( V_401 ) ;
return 0 ;
}
int F_406 ( struct V_9 * V_9 , enum V_415 V_416 ,
struct V_403 * V_106 )
{
int V_11 , V_26 ;
struct V_99 * V_418 , * V_401 ;
V_401 = V_9 -> V_98 [ V_416 ] ;
V_26 = - V_157 ;
for ( V_11 = 0 ; V_11 < V_401 -> V_402 ; V_11 ++ )
if ( V_401 -> V_405 [ V_11 ] . V_106 == V_106 ) {
V_26 = 0 ;
break;
}
if ( V_26 )
return V_26 ;
V_418 = F_405 ( sizeof( * V_401 ) + ( ( V_401 -> V_402 - 1 ) *
sizeof( struct V_406 ) ) , V_32 ) ;
if ( ! V_418 )
return - V_34 ;
memcpy ( V_418 , V_401 , sizeof( * V_401 ) + V_11 * sizeof( struct V_406 ) ) ;
V_418 -> V_402 -- ;
memcpy ( V_418 -> V_405 + V_11 , V_401 -> V_405 + V_11 + 1 ,
( V_418 -> V_402 - V_11 ) * sizeof( struct V_406 ) ) ;
F_136 ( V_9 -> V_98 [ V_416 ] , V_418 ) ;
F_137 ( & V_9 -> V_46 ) ;
F_82 ( V_401 ) ;
return V_26 ;
}
struct V_403 * F_407 ( struct V_9 * V_9 , enum V_415 V_416 ,
T_6 V_166 )
{
struct V_99 * V_401 ;
int V_421 , V_422 ;
struct V_403 * V_423 = NULL ;
V_422 = F_50 ( & V_9 -> V_46 ) ;
V_401 = F_399 ( V_9 -> V_98 [ V_416 ] , & V_9 -> V_46 ) ;
V_421 = F_395 ( V_401 , V_166 , 1 ) ;
if ( V_421 < 0 )
goto V_424;
V_423 = V_401 -> V_405 [ V_421 ] . V_106 ;
V_424:
F_55 ( & V_9 -> V_46 , V_422 ) ;
return V_423 ;
}
static int F_408 ( struct V_112 * V_112 , struct V_113 * V_113 ,
int (* F_409)( void * , T_8 * ) , int (* F_410)( void * , T_8 ) ,
const char * V_425 )
{
struct V_74 * V_75 = (struct V_74 * )
V_112 -> V_426 ;
if ( ! F_411 ( & V_75 -> V_9 -> V_88 , 1 , 0 ) )
return - V_157 ;
if ( F_412 ( V_112 , V_113 , F_409 , F_410 , V_425 ) ) {
F_123 ( V_75 -> V_9 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_413 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
struct V_74 * V_75 = (struct V_74 * )
V_112 -> V_426 ;
F_414 ( V_112 , V_113 ) ;
F_123 ( V_75 -> V_9 ) ;
return 0 ;
}
static int F_415 ( void * V_202 , T_8 * V_214 )
{
struct V_74 * V_75 = (struct V_74 * ) V_202 ;
* V_214 = * ( V_427 * ) ( ( void * ) V_75 -> V_9 + V_75 -> V_81 ) ;
return 0 ;
}
static int F_416 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
F_417 ( L_7 , 0ull ) ;
return F_408 ( V_112 , V_113 , F_415 ,
NULL , L_7 ) ;
}
static int F_418 ( void * V_202 , T_8 * V_214 )
{
int V_11 ;
struct V_74 * V_75 = (struct V_74 * ) V_202 ;
struct V_2 * V_3 ;
* V_214 = 0 ;
F_20 ( V_11 , V_3 , V_75 -> V_9 )
* V_214 += * ( T_8 * ) ( ( void * ) V_3 + V_75 -> V_81 ) ;
return 0 ;
}
static int F_419 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
F_417 ( L_7 , 0ull ) ;
return F_408 ( V_112 , V_113 , F_418 ,
NULL , L_7 ) ;
}
static int F_420 ( void * V_428 , T_8 * V_214 )
{
unsigned V_81 = ( long ) V_428 ;
struct V_9 * V_9 ;
struct V_74 V_429 = { . V_81 = V_81 } ;
T_8 V_430 ;
* V_214 = 0 ;
F_51 ( & V_101 ) ;
F_421 (kvm, &vm_list, vm_list) {
V_429 . V_9 = V_9 ;
F_415 ( ( void * ) & V_429 , & V_430 ) ;
* V_214 += V_430 ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_422 ( void * V_428 , T_8 * V_214 )
{
unsigned V_81 = ( long ) V_428 ;
struct V_9 * V_9 ;
struct V_74 V_429 = { . V_81 = V_81 } ;
T_8 V_430 ;
* V_214 = 0 ;
F_51 ( & V_101 ) ;
F_421 (kvm, &vm_list, vm_list) {
V_429 . V_9 = V_9 ;
F_418 ( ( void * ) & V_429 , & V_430 ) ;
* V_214 += V_430 ;
}
F_53 ( & V_101 ) ;
return 0 ;
}
static int F_423 ( void )
{
int V_26 = - V_148 ;
struct V_76 * V_77 ;
V_78 = F_86 ( L_8 , NULL ) ;
if ( V_78 == NULL )
goto V_134;
V_70 = 0 ;
for ( V_77 = V_79 ; V_77 -> V_80 ; ++ V_77 , V_70 ++ ) {
if ( ! F_89 ( V_77 -> V_80 , 0444 , V_78 ,
( void * ) ( long ) V_77 -> V_81 ,
V_431 [ V_77 -> V_83 ] ) )
goto V_432;
}
return 0 ;
V_432:
F_81 ( V_78 ) ;
V_134:
return V_26 ;
}
static int F_424 ( void )
{
if ( V_394 )
F_384 ( NULL ) ;
return 0 ;
}
static void F_425 ( void )
{
if ( V_394 ) {
F_130 ( F_426 ( & V_393 ) ) ;
F_375 ( NULL ) ;
}
}
static inline
struct V_2 * F_427 ( struct V_7 * V_433 )
{
return F_48 ( V_433 , struct V_2 , V_7 ) ;
}
static void F_428 ( struct V_7 * V_433 , int V_4 )
{
struct V_2 * V_3 = F_427 ( V_433 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_429 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_430 ( struct V_7 * V_433 ,
struct V_235 * V_434 )
{
struct V_2 * V_3 = F_427 ( V_433 ) ;
if ( V_56 -> V_435 == V_436 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_431 ( void * V_437 , unsigned V_438 , unsigned V_439 ,
struct V_440 * V_440 )
{
int V_26 ;
int V_4 ;
V_26 = F_432 ( V_437 ) ;
if ( V_26 )
goto V_441;
V_26 = F_433 () ;
if ( V_26 )
goto V_442;
if ( ! F_19 ( & V_391 , V_32 ) ) {
V_26 = - V_34 ;
goto V_443;
}
V_26 = F_434 () ;
if ( V_26 < 0 )
goto V_444;
F_435 (cpu) {
F_436 ( V_4 ,
V_445 ,
& V_26 , 1 ) ;
if ( V_26 < 0 )
goto V_446;
}
V_26 = F_437 ( V_447 , L_9 ,
F_381 , F_386 ) ;
if ( V_26 )
goto V_448;
F_438 ( & V_449 ) ;
if ( ! V_439 )
V_439 = F_439 ( struct V_2 ) ;
V_450 = F_440 ( L_10 , V_438 , V_439 ,
0 , NULL ) ;
if ( ! V_450 ) {
V_26 = - V_34 ;
goto V_451;
}
V_26 = F_441 () ;
if ( V_26 )
goto V_149;
V_452 . V_453 = V_440 ;
V_381 . V_453 = V_440 ;
V_255 . V_453 = V_440 ;
V_26 = F_442 ( & V_454 ) ;
if ( V_26 ) {
F_443 ( L_11 ) ;
goto V_455;
}
F_444 ( & V_456 ) ;
V_262 . V_457 = F_428 ;
V_262 . V_458 = F_430 ;
V_26 = F_423 () ;
if ( V_26 ) {
F_443 ( L_12 ) ;
goto V_459;
}
V_26 = F_445 () ;
F_130 ( V_26 ) ;
return 0 ;
V_459:
F_446 ( & V_456 ) ;
F_447 ( & V_454 ) ;
V_455:
F_448 () ;
V_149:
F_449 ( V_450 ) ;
V_451:
F_450 ( & V_449 ) ;
F_451 ( V_447 ) ;
V_448:
V_446:
F_452 () ;
V_444:
F_28 ( V_391 ) ;
V_443:
F_453 () ;
V_442:
F_454 () ;
V_441:
return V_26 ;
}
void F_455 ( void )
{
F_81 ( V_78 ) ;
F_447 ( & V_454 ) ;
F_449 ( V_450 ) ;
F_448 () ;
F_446 ( & V_456 ) ;
F_450 ( & V_449 ) ;
F_451 ( V_447 ) ;
F_388 ( F_384 , NULL , 1 ) ;
F_452 () ;
F_454 () ;
F_453 () ;
F_28 ( V_391 ) ;
F_456 () ;
}
