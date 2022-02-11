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
for ( V_11 = 0 ; V_11 < V_59 ; V_11 ++ )
V_58 -> V_60 [ V_11 ] = V_58 -> V_61 [ V_11 ] . V_24 = V_11 ;
return V_58 ;
}
static void F_74 ( struct V_62 * V_63 )
{
if ( ! V_63 -> V_64 )
return;
F_75 ( V_63 -> V_64 ) ;
V_63 -> V_64 = NULL ;
}
static void F_76 ( struct V_9 * V_9 , struct V_62 * free ,
struct V_62 * V_65 )
{
if ( ! V_65 || free -> V_64 != V_65 -> V_64 )
F_74 ( free ) ;
F_77 ( V_9 , free , V_65 ) ;
free -> V_66 = 0 ;
}
static void F_78 ( struct V_9 * V_9 , struct V_57 * V_58 )
{
struct V_62 * V_63 ;
if ( ! V_58 )
return;
F_79 (memslot, slots)
F_76 ( V_9 , V_63 , NULL ) ;
F_75 ( V_58 ) ;
}
static void F_80 ( struct V_9 * V_9 )
{
int V_11 ;
if ( ! V_9 -> V_67 )
return;
F_81 ( V_9 -> V_67 ) ;
if ( V_9 -> V_68 ) {
for ( V_11 = 0 ; V_11 < V_69 ; V_11 ++ )
F_82 ( V_9 -> V_68 [ V_11 ] ) ;
F_82 ( V_9 -> V_68 ) ;
}
}
static int F_83 ( struct V_9 * V_9 , int V_70 )
{
char V_71 [ V_72 * 2 ] ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_71 , sizeof( V_71 ) , L_1 , F_85 ( V_56 ) , V_70 ) ;
V_9 -> V_67 = F_86 ( V_71 ,
V_77 ) ;
if ( ! V_9 -> V_67 )
return - V_34 ;
V_9 -> V_68 = F_87 ( V_69 ,
sizeof( * V_9 -> V_68 ) ,
V_32 ) ;
if ( ! V_9 -> V_68 )
return - V_34 ;
for ( V_76 = V_78 ; V_76 -> V_79 ; V_76 ++ ) {
V_74 = F_88 ( sizeof( * V_74 ) , V_32 ) ;
if ( ! V_74 )
return - V_34 ;
V_74 -> V_9 = V_9 ;
V_74 -> V_80 = V_76 -> V_80 ;
V_9 -> V_68 [ V_76 - V_78 ] = V_74 ;
if ( ! F_89 ( V_76 -> V_79 , 0644 ,
V_9 -> V_67 ,
V_74 ,
V_81 [ V_76 -> V_82 ] ) )
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
F_94 ( V_56 -> V_42 ) ;
V_9 -> V_42 = V_56 -> V_42 ;
F_95 ( V_9 ) ;
F_34 ( & V_9 -> V_83 ) ;
F_34 ( & V_9 -> V_84 ) ;
F_34 ( & V_9 -> V_85 ) ;
F_96 ( & V_9 -> V_86 , 1 ) ;
F_37 ( & V_9 -> V_87 ) ;
V_26 = F_97 ( V_9 , type ) ;
if ( V_26 )
goto V_88;
V_26 = F_98 () ;
if ( V_26 )
goto V_88;
#ifdef F_99
F_100 ( & V_9 -> V_89 ) ;
#endif
F_101 ( V_59 > V_90 ) ;
V_26 = - V_34 ;
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ ) {
struct V_57 * V_58 = F_72 () ;
if ( ! V_58 )
goto V_92;
V_58 -> V_93 = V_11 * 2 - 150 ;
F_102 ( V_9 -> V_61 [ V_11 ] , V_58 ) ;
}
if ( F_103 ( & V_9 -> V_46 ) )
goto V_92;
if ( F_103 ( & V_9 -> V_94 ) )
goto V_95;
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ ) {
V_9 -> V_97 [ V_11 ] = F_88 ( sizeof( struct V_98 ) ,
V_32 ) ;
if ( ! V_9 -> V_97 [ V_11 ] )
goto V_99;
}
V_26 = F_70 ( V_9 ) ;
if ( V_26 )
goto V_99;
F_51 ( & V_100 ) ;
F_104 ( & V_9 -> V_101 , & V_101 ) ;
F_53 ( & V_100 ) ;
F_105 () ;
return V_9 ;
V_99:
F_106 ( & V_9 -> V_94 ) ;
V_95:
F_106 ( & V_9 -> V_46 ) ;
V_92:
F_107 () ;
V_88:
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ )
F_82 ( V_9 -> V_97 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_61 [ V_11 ] ) ;
F_108 ( V_9 ) ;
F_109 ( V_56 -> V_42 ) ;
return F_92 ( V_26 ) ;
}
void * F_73 ( unsigned long V_102 )
{
if ( V_102 > V_103 )
return F_110 ( V_102 ) ;
else
return F_88 ( V_102 , V_32 ) ;
}
static void F_111 ( struct V_9 * V_9 )
{
struct V_104 * V_105 , * V_106 ;
F_112 (dev, tmp, &kvm->devices, vm_node) {
F_113 ( & V_105 -> V_107 ) ;
V_105 -> V_54 -> V_108 ( V_105 ) ;
}
}
static void F_114 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_41 * V_42 = V_9 -> V_42 ;
F_80 ( V_9 ) ;
F_115 ( V_9 ) ;
F_51 ( & V_100 ) ;
F_113 ( & V_9 -> V_101 ) ;
F_53 ( & V_100 ) ;
F_116 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_96 ; V_11 ++ ) {
if ( V_9 -> V_97 [ V_11 ] )
F_117 ( V_9 -> V_97 [ V_11 ] ) ;
V_9 -> V_97 [ V_11 ] = NULL ;
}
F_118 ( V_9 ) ;
#if F_119 ( V_109 ) && F_119 ( V_110 )
F_120 ( & V_9 -> V_39 , V_9 -> V_42 ) ;
#else
F_69 ( V_9 ) ;
#endif
F_121 ( V_9 ) ;
F_111 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_91 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_61 [ V_11 ] ) ;
F_106 ( & V_9 -> V_94 ) ;
F_106 ( & V_9 -> V_46 ) ;
F_108 ( V_9 ) ;
F_122 () ;
F_107 () ;
F_109 ( V_42 ) ;
}
void F_123 ( struct V_9 * V_9 )
{
F_124 ( & V_9 -> V_86 ) ;
}
void F_125 ( struct V_9 * V_9 )
{
if ( F_126 ( & V_9 -> V_86 ) )
F_114 ( V_9 ) ;
}
static int F_127 ( struct V_111 * V_111 , struct V_112 * V_113 )
{
struct V_9 * V_9 = V_113 -> V_114 ;
F_128 ( V_9 ) ;
F_125 ( V_9 ) ;
return 0 ;
}
static int F_129 ( struct V_62 * V_63 )
{
unsigned long V_115 = 2 * F_130 ( V_63 ) ;
V_63 -> V_64 = F_73 ( V_115 ) ;
if ( ! V_63 -> V_64 )
return - V_34 ;
return 0 ;
}
static void F_131 ( struct V_57 * V_58 ,
struct V_62 * V_116 )
{
int V_24 = V_116 -> V_24 ;
int V_11 = V_58 -> V_60 [ V_24 ] ;
struct V_62 * V_117 = V_58 -> V_61 ;
F_132 ( V_117 [ V_11 ] . V_24 != V_24 ) ;
if ( ! V_116 -> V_66 ) {
F_132 ( ! V_117 [ V_11 ] . V_66 ) ;
if ( V_117 [ V_11 ] . V_66 )
V_58 -> V_118 -- ;
} else {
if ( ! V_117 [ V_11 ] . V_66 )
V_58 -> V_118 ++ ;
}
while ( V_11 < V_59 - 1 &&
V_116 -> V_119 <= V_117 [ V_11 + 1 ] . V_119 ) {
if ( ! V_117 [ V_11 + 1 ] . V_66 )
break;
V_117 [ V_11 ] = V_117 [ V_11 + 1 ] ;
V_58 -> V_60 [ V_117 [ V_11 ] . V_24 ] = V_11 ;
V_11 ++ ;
}
if ( V_116 -> V_66 ) {
while ( V_11 > 0 &&
V_116 -> V_119 >= V_117 [ V_11 - 1 ] . V_119 ) {
V_117 [ V_11 ] = V_117 [ V_11 - 1 ] ;
V_58 -> V_60 [ V_117 [ V_11 ] . V_24 ] = V_11 ;
V_11 -- ;
}
} else
F_133 ( V_11 != V_58 -> V_118 ) ;
V_117 [ V_11 ] = * V_116 ;
V_58 -> V_60 [ V_117 [ V_11 ] . V_24 ] = V_11 ;
}
static int F_134 ( const struct V_120 * V_121 )
{
T_4 V_122 = V_123 ;
#ifdef F_135
V_122 |= V_124 ;
#endif
if ( V_121 -> V_125 & ~ V_122 )
return - V_126 ;
return 0 ;
}
static struct V_57 * F_136 ( struct V_9 * V_9 ,
int V_127 , struct V_57 * V_58 )
{
struct V_57 * V_128 = F_137 ( V_9 , V_127 ) ;
F_132 ( V_128 -> V_93 & 1 ) ;
V_58 -> V_93 = V_128 -> V_93 + 1 ;
F_102 ( V_9 -> V_61 [ V_127 ] , V_58 ) ;
F_138 ( & V_9 -> V_46 ) ;
V_58 -> V_93 += V_91 * 2 - 1 ;
F_139 ( V_9 , V_58 ) ;
return V_128 ;
}
int F_140 ( struct V_9 * V_9 ,
const struct V_120 * V_121 )
{
int V_26 ;
T_5 V_119 ;
unsigned long V_66 ;
struct V_62 * V_129 ;
struct V_62 V_130 , V_116 ;
struct V_57 * V_58 = NULL , * V_128 ;
int V_127 , V_24 ;
enum V_131 V_132 ;
V_26 = F_134 ( V_121 ) ;
if ( V_26 )
goto V_133;
V_26 = - V_126 ;
V_127 = V_121 -> V_129 >> 16 ;
V_24 = ( V_134 ) V_121 -> V_129 ;
if ( V_121 -> V_135 & ( V_103 - 1 ) )
goto V_133;
if ( V_121 -> V_136 & ( V_103 - 1 ) )
goto V_133;
if ( ( V_24 < V_137 ) &&
( ( V_121 -> V_138 & ( V_103 - 1 ) ) ||
! F_141 ( V_139 ,
( void V_140 * ) ( unsigned long ) V_121 -> V_138 ,
V_121 -> V_135 ) ) )
goto V_133;
if ( V_127 >= V_91 || V_24 >= V_59 )
goto V_133;
if ( V_121 -> V_136 + V_121 -> V_135 < V_121 -> V_136 )
goto V_133;
V_129 = F_142 ( F_137 ( V_9 , V_127 ) , V_24 ) ;
V_119 = V_121 -> V_136 >> V_141 ;
V_66 = V_121 -> V_135 >> V_141 ;
if ( V_66 > V_142 )
goto V_133;
V_116 = V_130 = * V_129 ;
V_116 . V_24 = V_24 ;
V_116 . V_119 = V_119 ;
V_116 . V_66 = V_66 ;
V_116 . V_125 = V_121 -> V_125 ;
if ( V_66 ) {
if ( ! V_130 . V_66 )
V_132 = V_143 ;
else {
if ( ( V_121 -> V_138 != V_130 . V_138 ) ||
( V_66 != V_130 . V_66 ) ||
( ( V_116 . V_125 ^ V_130 . V_125 ) & V_124 ) )
goto V_133;
if ( V_119 != V_130 . V_119 )
V_132 = V_144 ;
else if ( V_116 . V_125 != V_130 . V_125 )
V_132 = V_145 ;
else {
V_26 = 0 ;
goto V_133;
}
}
} else {
if ( ! V_130 . V_66 )
goto V_133;
V_132 = V_146 ;
V_116 . V_119 = 0 ;
V_116 . V_125 = 0 ;
}
if ( ( V_132 == V_143 ) || ( V_132 == V_144 ) ) {
V_26 = - V_147 ;
F_79 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_129 -> V_24 >= V_137 ) ||
( V_129 -> V_24 == V_24 ) )
continue;
if ( ! ( ( V_119 + V_66 <= V_129 -> V_119 ) ||
( V_119 >= V_129 -> V_119 + V_129 -> V_66 ) ) )
goto V_133;
}
}
if ( ! ( V_116 . V_125 & V_123 ) )
V_116 . V_64 = NULL ;
V_26 = - V_34 ;
if ( V_132 == V_143 ) {
V_116 . V_138 = V_121 -> V_138 ;
if ( F_143 ( V_9 , & V_116 , V_66 ) )
goto V_148;
}
if ( ( V_116 . V_125 & V_123 ) && ! V_116 . V_64 ) {
if ( F_129 ( & V_116 ) < 0 )
goto V_148;
}
V_58 = F_73 ( sizeof( struct V_57 ) ) ;
if ( ! V_58 )
goto V_148;
memcpy ( V_58 , F_137 ( V_9 , V_127 ) , sizeof( struct V_57 ) ) ;
if ( ( V_132 == V_146 ) || ( V_132 == V_144 ) ) {
V_129 = F_142 ( V_58 , V_24 ) ;
V_129 -> V_125 |= V_149 ;
V_128 = F_136 ( V_9 , V_127 , V_58 ) ;
F_144 ( V_9 , & V_130 ) ;
F_145 ( V_9 , V_129 ) ;
V_58 = V_128 ;
}
V_26 = F_146 ( V_9 , & V_116 , V_121 , V_132 ) ;
if ( V_26 )
goto V_150;
if ( V_132 == V_146 ) {
V_116 . V_64 = NULL ;
memset ( & V_116 . V_151 , 0 , sizeof( V_116 . V_151 ) ) ;
}
F_131 ( V_58 , & V_116 ) ;
V_128 = F_136 ( V_9 , V_127 , V_58 ) ;
F_147 ( V_9 , V_121 , & V_130 , & V_116 , V_132 ) ;
F_76 ( V_9 , & V_130 , & V_116 ) ;
F_75 ( V_128 ) ;
if ( V_127 == 0 && ( V_132 == V_143 || V_132 == V_144 ) ) {
V_26 = F_148 ( V_9 , & V_116 ) ;
return V_26 ;
}
return 0 ;
V_150:
F_75 ( V_58 ) ;
V_148:
F_76 ( V_9 , & V_116 , & V_130 ) ;
V_133:
return V_26 ;
}
int F_149 ( struct V_9 * V_9 ,
const struct V_120 * V_121 )
{
int V_26 ;
F_150 ( & V_9 -> V_85 ) ;
V_26 = F_140 ( V_9 , V_121 ) ;
F_16 ( & V_9 -> V_85 ) ;
return V_26 ;
}
static int F_151 ( struct V_9 * V_9 ,
struct V_120 * V_121 )
{
if ( ( V_134 ) V_121 -> V_129 >= V_137 )
return - V_126 ;
return F_149 ( V_9 , V_121 ) ;
}
int F_152 ( struct V_9 * V_9 ,
struct V_152 * log , int * V_153 )
{
struct V_57 * V_58 ;
struct V_62 * V_63 ;
int V_11 , V_127 , V_24 ;
unsigned long V_154 ;
unsigned long V_155 = 0 ;
V_127 = log -> V_129 >> 16 ;
V_24 = ( V_134 ) log -> V_129 ;
if ( V_127 >= V_91 || V_24 >= V_137 )
return - V_126 ;
V_58 = F_137 ( V_9 , V_127 ) ;
V_63 = F_142 ( V_58 , V_24 ) ;
if ( ! V_63 -> V_64 )
return - V_156 ;
V_154 = F_130 ( V_63 ) ;
for ( V_11 = 0 ; ! V_155 && V_11 < V_154 / sizeof( long ) ; ++ V_11 )
V_155 = V_63 -> V_64 [ V_11 ] ;
if ( F_153 ( log -> V_64 , V_63 -> V_64 , V_154 ) )
return - V_157 ;
if ( V_155 )
* V_153 = 1 ;
return 0 ;
}
int F_154 ( struct V_9 * V_9 ,
struct V_152 * log , bool * V_153 )
{
struct V_57 * V_58 ;
struct V_62 * V_63 ;
int V_11 , V_127 , V_24 ;
unsigned long V_154 ;
unsigned long * V_64 ;
unsigned long * V_158 ;
V_127 = log -> V_129 >> 16 ;
V_24 = ( V_134 ) log -> V_129 ;
if ( V_127 >= V_91 || V_24 >= V_137 )
return - V_126 ;
V_58 = F_137 ( V_9 , V_127 ) ;
V_63 = F_142 ( V_58 , V_24 ) ;
V_64 = V_63 -> V_64 ;
if ( ! V_64 )
return - V_156 ;
V_154 = F_130 ( V_63 ) ;
V_158 = V_64 + V_154 / sizeof( long ) ;
memset ( V_158 , 0 , V_154 ) ;
F_51 ( & V_9 -> V_47 ) ;
* V_153 = false ;
for ( V_11 = 0 ; V_11 < V_154 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_159 ;
T_5 V_80 ;
if ( ! V_64 [ V_11 ] )
continue;
* V_153 = true ;
V_159 = F_155 ( & V_64 [ V_11 ] , 0 ) ;
V_158 [ V_11 ] = V_159 ;
if ( V_159 ) {
V_80 = V_11 * V_160 ;
F_156 ( V_9 , V_63 ,
V_80 , V_159 ) ;
}
}
F_53 ( & V_9 -> V_47 ) ;
if ( F_153 ( log -> V_64 , V_158 , V_154 ) )
return - V_157 ;
return 0 ;
}
bool F_157 ( void )
{
return V_161 ;
}
void F_158 ( void )
{
V_161 = false ;
}
struct V_62 * F_159 ( struct V_9 * V_9 , T_5 V_162 )
{
return F_160 ( V_57 ( V_9 ) , V_162 ) ;
}
struct V_62 * F_161 ( struct V_2 * V_3 , T_5 V_162 )
{
return F_160 ( F_162 ( V_3 ) , V_162 ) ;
}
bool F_163 ( struct V_9 * V_9 , T_5 V_162 )
{
struct V_62 * V_63 = F_159 ( V_9 , V_162 ) ;
if ( ! V_63 || V_63 -> V_24 >= V_137 ||
V_63 -> V_125 & V_149 )
return false ;
return true ;
}
unsigned long F_164 ( struct V_9 * V_9 , T_5 V_162 )
{
struct V_163 * V_164 ;
unsigned long V_165 , V_102 ;
V_102 = V_103 ;
V_165 = F_165 ( V_9 , V_162 ) ;
if ( F_166 ( V_165 ) )
return V_103 ;
F_167 ( & V_56 -> V_42 -> V_166 ) ;
V_164 = F_168 ( V_56 -> V_42 , V_165 ) ;
if ( ! V_164 )
goto V_133;
V_102 = F_169 ( V_164 ) ;
V_133:
F_170 ( & V_56 -> V_42 -> V_166 ) ;
return V_102 ;
}
static bool F_171 ( struct V_62 * V_129 )
{
return V_129 -> V_125 & V_124 ;
}
static unsigned long F_172 ( struct V_62 * V_129 , T_5 V_162 ,
T_5 * V_167 , bool V_168 )
{
if ( ! V_129 || V_129 -> V_125 & V_149 )
return V_169 ;
if ( F_171 ( V_129 ) && V_168 )
return V_170 ;
if ( V_167 )
* V_167 = V_129 -> V_66 - ( V_162 - V_129 -> V_119 ) ;
return F_173 ( V_129 , V_162 ) ;
}
static unsigned long F_174 ( struct V_62 * V_129 , T_5 V_162 ,
T_5 * V_167 )
{
return F_172 ( V_129 , V_162 , V_167 , true ) ;
}
unsigned long F_175 ( struct V_62 * V_129 ,
T_5 V_162 )
{
return F_174 ( V_129 , V_162 , NULL ) ;
}
unsigned long F_165 ( struct V_9 * V_9 , T_5 V_162 )
{
return F_174 ( F_159 ( V_9 , V_162 ) , V_162 , NULL ) ;
}
unsigned long F_176 ( struct V_2 * V_3 , T_5 V_162 )
{
return F_174 ( F_161 ( V_3 , V_162 ) , V_162 , NULL ) ;
}
unsigned long F_177 ( struct V_62 * V_129 ,
T_5 V_162 , bool * V_171 )
{
unsigned long V_172 = F_172 ( V_129 , V_162 , NULL , false ) ;
if ( ! F_166 ( V_172 ) && V_171 )
* V_171 = ! F_171 ( V_129 ) ;
return V_172 ;
}
unsigned long F_178 ( struct V_9 * V_9 , T_5 V_162 , bool * V_171 )
{
struct V_62 * V_129 = F_159 ( V_9 , V_162 ) ;
return F_177 ( V_129 , V_162 , V_171 ) ;
}
unsigned long F_179 ( struct V_2 * V_3 , T_5 V_162 , bool * V_171 )
{
struct V_62 * V_129 = F_161 ( V_3 , V_162 ) ;
return F_177 ( V_129 , V_162 , V_171 ) ;
}
static int F_180 ( unsigned long V_50 , int V_168 ,
struct V_25 * * V_25 )
{
int V_125 = V_173 | V_174 ;
if ( V_168 )
V_125 |= V_175 ;
return F_181 ( V_50 , 1 , V_125 , V_25 , NULL ) ;
}
static inline int F_182 ( unsigned long V_165 )
{
int V_176 , V_125 = V_174 | V_175 ;
V_176 = F_181 ( V_165 , 1 , V_125 , NULL , NULL ) ;
return V_176 == - V_177 ;
}
static bool F_183 ( unsigned long V_165 , bool V_178 , bool * V_179 ,
bool V_180 , bool * V_171 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_66 ;
if ( ! ( V_179 || V_178 ) )
return false ;
if ( ! ( V_180 || V_171 ) )
return false ;
V_66 = F_184 ( V_165 , 1 , 1 , V_25 ) ;
if ( V_66 == 1 ) {
* V_1 = F_185 ( V_25 [ 0 ] ) ;
if ( V_171 )
* V_171 = true ;
return true ;
}
return false ;
}
static int F_186 ( unsigned long V_165 , bool * V_179 , bool V_180 ,
bool * V_171 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_66 = 0 ;
F_187 () ;
if ( V_171 )
* V_171 = V_180 ;
if ( V_179 ) {
F_167 ( & V_56 -> V_42 -> V_166 ) ;
V_66 = F_180 ( V_165 , V_180 , V_25 ) ;
F_170 ( & V_56 -> V_42 -> V_166 ) ;
} else {
unsigned int V_125 = V_174 ;
if ( V_180 )
V_125 |= V_175 ;
V_66 = F_188 ( V_165 , 1 , V_25 , V_125 ) ;
}
if ( V_66 != 1 )
return V_66 ;
if ( F_25 ( ! V_180 ) && V_171 ) {
struct V_25 * V_181 [ 1 ] ;
V_66 = F_184 ( V_165 , 1 , 1 , V_181 ) ;
if ( V_66 == 1 ) {
* V_171 = true ;
F_189 ( V_25 [ 0 ] ) ;
V_25 [ 0 ] = V_181 [ 0 ] ;
}
V_66 = 1 ;
}
* V_1 = F_185 ( V_25 [ 0 ] ) ;
return V_66 ;
}
static bool F_190 ( struct V_163 * V_164 , bool V_180 )
{
if ( F_25 ( ! ( V_164 -> V_182 & V_183 ) ) )
return false ;
if ( V_180 && ( F_25 ( ! ( V_164 -> V_182 & V_184 ) ) ) )
return false ;
return true ;
}
static int F_191 ( struct V_163 * V_164 ,
unsigned long V_165 , bool * V_179 ,
bool V_180 , T_1 * V_185 )
{
unsigned long V_1 ;
int V_26 ;
V_26 = F_192 ( V_164 , V_165 , & V_1 ) ;
if ( V_26 ) {
bool V_186 = false ;
V_26 = F_193 ( V_56 , V_56 -> V_42 , V_165 ,
( V_180 ? V_187 : 0 ) ,
& V_186 ) ;
if ( V_186 )
return - V_188 ;
if ( V_26 )
return V_26 ;
V_26 = F_192 ( V_164 , V_165 , & V_1 ) ;
if ( V_26 )
return V_26 ;
}
F_194 ( V_1 ) ;
* V_185 = V_1 ;
return 0 ;
}
static T_1 F_195 ( unsigned long V_165 , bool V_178 , bool * V_179 ,
bool V_180 , bool * V_171 )
{
struct V_163 * V_164 ;
T_1 V_1 = 0 ;
int V_66 , V_26 ;
F_62 ( V_178 && V_179 ) ;
if ( F_183 ( V_165 , V_178 , V_179 , V_180 , V_171 , & V_1 ) )
return V_1 ;
if ( V_178 )
return V_189 ;
V_66 = F_186 ( V_165 , V_179 , V_180 , V_171 , & V_1 ) ;
if ( V_66 == 1 )
return V_1 ;
F_167 ( & V_56 -> V_42 -> V_166 ) ;
if ( V_66 == - V_177 ||
( ! V_179 && F_182 ( V_165 ) ) ) {
V_1 = V_190 ;
goto exit;
}
V_191:
V_164 = F_196 ( V_56 -> V_42 , V_165 , V_165 + 1 ) ;
if ( V_164 == NULL )
V_1 = V_189 ;
else if ( V_164 -> V_182 & ( V_192 | V_193 ) ) {
V_26 = F_191 ( V_164 , V_165 , V_179 , V_180 , & V_1 ) ;
if ( V_26 == - V_188 )
goto V_191;
if ( V_26 < 0 )
V_1 = V_189 ;
} else {
if ( V_179 && F_190 ( V_164 , V_180 ) )
* V_179 = true ;
V_1 = V_189 ;
}
exit:
F_170 ( & V_56 -> V_42 -> V_166 ) ;
return V_1 ;
}
T_1 F_197 ( struct V_62 * V_129 , T_5 V_162 ,
bool V_178 , bool * V_179 , bool V_180 ,
bool * V_171 )
{
unsigned long V_165 = F_172 ( V_129 , V_162 , NULL , V_180 ) ;
if ( V_165 == V_170 ) {
if ( V_171 )
* V_171 = false ;
return V_194 ;
}
if ( F_166 ( V_165 ) ) {
if ( V_171 )
* V_171 = false ;
return V_195 ;
}
if ( V_171 && F_171 ( V_129 ) ) {
* V_171 = false ;
V_171 = NULL ;
}
return F_195 ( V_165 , V_178 , V_179 , V_180 ,
V_171 ) ;
}
T_1 F_198 ( struct V_9 * V_9 , T_5 V_162 , bool V_180 ,
bool * V_171 )
{
return F_197 ( F_159 ( V_9 , V_162 ) , V_162 , false , NULL ,
V_180 , V_171 ) ;
}
T_1 F_199 ( struct V_62 * V_129 , T_5 V_162 )
{
return F_197 ( V_129 , V_162 , false , NULL , true , NULL ) ;
}
T_1 F_200 ( struct V_62 * V_129 , T_5 V_162 )
{
return F_197 ( V_129 , V_162 , true , NULL , true , NULL ) ;
}
T_1 F_201 ( struct V_9 * V_9 , T_5 V_162 )
{
return F_200 ( F_159 ( V_9 , V_162 ) , V_162 ) ;
}
T_1 F_202 ( struct V_2 * V_3 , T_5 V_162 )
{
return F_200 ( F_161 ( V_3 , V_162 ) , V_162 ) ;
}
T_1 F_203 ( struct V_9 * V_9 , T_5 V_162 )
{
return F_199 ( F_159 ( V_9 , V_162 ) , V_162 ) ;
}
T_1 F_204 ( struct V_2 * V_3 , T_5 V_162 )
{
return F_199 ( F_161 ( V_3 , V_162 ) , V_162 ) ;
}
int F_205 ( struct V_62 * V_129 , T_5 V_162 ,
struct V_25 * * V_196 , int V_167 )
{
unsigned long V_165 ;
T_5 V_197 ;
V_165 = F_174 ( V_129 , V_162 , & V_197 ) ;
if ( F_166 ( V_165 ) )
return - 1 ;
if ( V_197 < V_167 )
return 0 ;
return F_184 ( V_165 , V_167 , 1 , V_196 ) ;
}
static struct V_25 * F_206 ( T_1 V_1 )
{
if ( F_207 ( V_1 ) )
return V_198 ;
if ( F_1 ( V_1 ) ) {
F_132 ( 1 ) ;
return V_198 ;
}
return F_4 ( V_1 ) ;
}
struct V_25 * F_208 ( struct V_9 * V_9 , T_5 V_162 )
{
T_1 V_1 ;
V_1 = F_203 ( V_9 , V_162 ) ;
return F_206 ( V_1 ) ;
}
struct V_25 * F_209 ( struct V_2 * V_3 , T_5 V_162 )
{
T_1 V_1 ;
V_1 = F_204 ( V_3 , V_162 ) ;
return F_206 ( V_1 ) ;
}
void F_210 ( struct V_25 * V_25 )
{
F_132 ( F_211 ( V_25 ) ) ;
F_212 ( F_185 ( V_25 ) ) ;
}
void F_212 ( T_1 V_1 )
{
if ( ! F_207 ( V_1 ) && ! F_1 ( V_1 ) )
F_189 ( F_4 ( V_1 ) ) ;
}
void F_213 ( struct V_25 * V_25 )
{
F_132 ( F_211 ( V_25 ) ) ;
F_214 ( F_185 ( V_25 ) ) ;
}
static void F_214 ( T_1 V_1 )
{
F_215 ( V_1 ) ;
F_212 ( V_1 ) ;
}
void F_215 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_25 * V_25 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_25 ) )
F_216 ( V_25 ) ;
}
}
void F_217 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_218 ( F_4 ( V_1 ) ) ;
}
void F_194 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_219 ( F_4 ( V_1 ) ) ;
}
static int F_220 ( unsigned long V_199 , int V_80 )
{
if ( V_199 > V_103 - V_80 )
return V_103 - V_80 ;
else
return V_199 ;
}
static int F_221 ( struct V_62 * V_129 , T_5 V_162 ,
void * V_200 , int V_80 , int V_199 )
{
int V_26 ;
unsigned long V_165 ;
V_165 = F_177 ( V_129 , V_162 , NULL ) ;
if ( F_166 ( V_165 ) )
return - V_157 ;
V_26 = F_222 ( V_200 , ( void V_140 * ) V_165 + V_80 , V_199 ) ;
if ( V_26 )
return - V_157 ;
return 0 ;
}
int F_223 ( struct V_9 * V_9 , T_5 V_162 , void * V_200 , int V_80 ,
int V_199 )
{
struct V_62 * V_129 = F_159 ( V_9 , V_162 ) ;
return F_221 ( V_129 , V_162 , V_200 , V_80 , V_199 ) ;
}
int F_224 ( struct V_2 * V_3 , T_5 V_162 , void * V_200 ,
int V_80 , int V_199 )
{
struct V_62 * V_129 = F_161 ( V_3 , V_162 ) ;
return F_221 ( V_129 , V_162 , V_200 , V_80 , V_199 ) ;
}
int F_225 ( struct V_9 * V_9 , T_6 V_201 , void * V_200 , unsigned long V_199 )
{
T_5 V_162 = V_201 >> V_141 ;
int V_202 ;
int V_80 = F_226 ( V_201 ) ;
int V_203 ;
while ( ( V_202 = F_220 ( V_199 , V_80 ) ) != 0 ) {
V_203 = F_223 ( V_9 , V_162 , V_200 , V_80 , V_202 ) ;
if ( V_203 < 0 )
return V_203 ;
V_80 = 0 ;
V_199 -= V_202 ;
V_200 += V_202 ;
++ V_162 ;
}
return 0 ;
}
int F_227 ( struct V_2 * V_3 , T_6 V_201 , void * V_200 , unsigned long V_199 )
{
T_5 V_162 = V_201 >> V_141 ;
int V_202 ;
int V_80 = F_226 ( V_201 ) ;
int V_203 ;
while ( ( V_202 = F_220 ( V_199 , V_80 ) ) != 0 ) {
V_203 = F_224 ( V_3 , V_162 , V_200 , V_80 , V_202 ) ;
if ( V_203 < 0 )
return V_203 ;
V_80 = 0 ;
V_199 -= V_202 ;
V_200 += V_202 ;
++ V_162 ;
}
return 0 ;
}
static int F_228 ( struct V_62 * V_129 , T_5 V_162 ,
void * V_200 , int V_80 , unsigned long V_199 )
{
int V_26 ;
unsigned long V_165 ;
V_165 = F_177 ( V_129 , V_162 , NULL ) ;
if ( F_166 ( V_165 ) )
return - V_157 ;
F_229 () ;
V_26 = F_230 ( V_200 , ( void V_140 * ) V_165 + V_80 , V_199 ) ;
F_231 () ;
if ( V_26 )
return - V_157 ;
return 0 ;
}
int F_232 ( struct V_9 * V_9 , T_6 V_201 , void * V_200 ,
unsigned long V_199 )
{
T_5 V_162 = V_201 >> V_141 ;
struct V_62 * V_129 = F_159 ( V_9 , V_162 ) ;
int V_80 = F_226 ( V_201 ) ;
return F_228 ( V_129 , V_162 , V_200 , V_80 , V_199 ) ;
}
int F_233 ( struct V_2 * V_3 , T_6 V_201 ,
void * V_200 , unsigned long V_199 )
{
T_5 V_162 = V_201 >> V_141 ;
struct V_62 * V_129 = F_161 ( V_3 , V_162 ) ;
int V_80 = F_226 ( V_201 ) ;
return F_228 ( V_129 , V_162 , V_200 , V_80 , V_199 ) ;
}
static int F_234 ( struct V_62 * V_63 , T_5 V_162 ,
const void * V_200 , int V_80 , int V_199 )
{
int V_26 ;
unsigned long V_165 ;
V_165 = F_175 ( V_63 , V_162 ) ;
if ( F_166 ( V_165 ) )
return - V_157 ;
V_26 = F_235 ( ( void V_140 * ) V_165 + V_80 , V_200 , V_199 ) ;
if ( V_26 )
return - V_157 ;
F_236 ( V_63 , V_162 ) ;
return 0 ;
}
int F_237 ( struct V_9 * V_9 , T_5 V_162 ,
const void * V_200 , int V_80 , int V_199 )
{
struct V_62 * V_129 = F_159 ( V_9 , V_162 ) ;
return F_234 ( V_129 , V_162 , V_200 , V_80 , V_199 ) ;
}
int F_238 ( struct V_2 * V_3 , T_5 V_162 ,
const void * V_200 , int V_80 , int V_199 )
{
struct V_62 * V_129 = F_161 ( V_3 , V_162 ) ;
return F_234 ( V_129 , V_162 , V_200 , V_80 , V_199 ) ;
}
int F_239 ( struct V_9 * V_9 , T_6 V_201 , const void * V_200 ,
unsigned long V_199 )
{
T_5 V_162 = V_201 >> V_141 ;
int V_202 ;
int V_80 = F_226 ( V_201 ) ;
int V_203 ;
while ( ( V_202 = F_220 ( V_199 , V_80 ) ) != 0 ) {
V_203 = F_237 ( V_9 , V_162 , V_200 , V_80 , V_202 ) ;
if ( V_203 < 0 )
return V_203 ;
V_80 = 0 ;
V_199 -= V_202 ;
V_200 += V_202 ;
++ V_162 ;
}
return 0 ;
}
int F_240 ( struct V_2 * V_3 , T_6 V_201 , const void * V_200 ,
unsigned long V_199 )
{
T_5 V_162 = V_201 >> V_141 ;
int V_202 ;
int V_80 = F_226 ( V_201 ) ;
int V_203 ;
while ( ( V_202 = F_220 ( V_199 , V_80 ) ) != 0 ) {
V_203 = F_238 ( V_3 , V_162 , V_200 , V_80 , V_202 ) ;
if ( V_203 < 0 )
return V_203 ;
V_80 = 0 ;
V_199 -= V_202 ;
V_200 += V_202 ;
++ V_162 ;
}
return 0 ;
}
static int F_241 ( struct V_57 * V_58 ,
struct V_204 * V_205 ,
T_6 V_201 , unsigned long V_199 )
{
int V_80 = F_226 ( V_201 ) ;
T_5 V_206 = V_201 >> V_141 ;
T_5 V_207 = ( V_201 + V_199 - 1 ) >> V_141 ;
T_5 V_208 = V_207 - V_206 + 1 ;
T_5 V_209 ;
V_205 -> V_201 = V_201 ;
V_205 -> V_93 = V_58 -> V_93 ;
V_205 -> V_199 = V_199 ;
V_205 -> V_63 = F_160 ( V_58 , V_206 ) ;
V_205 -> V_172 = F_174 ( V_205 -> V_63 , V_206 , NULL ) ;
if ( ! F_166 ( V_205 -> V_172 ) && V_208 <= 1 ) {
V_205 -> V_172 += V_80 ;
} else {
while ( V_206 <= V_207 ) {
V_205 -> V_63 = F_160 ( V_58 , V_206 ) ;
V_205 -> V_172 = F_174 ( V_205 -> V_63 , V_206 ,
& V_209 ) ;
if ( F_166 ( V_205 -> V_172 ) )
return - V_157 ;
V_206 += V_209 ;
}
V_205 -> V_63 = NULL ;
}
return 0 ;
}
int F_242 ( struct V_2 * V_3 , struct V_204 * V_205 ,
T_6 V_201 , unsigned long V_199 )
{
struct V_57 * V_58 = F_162 ( V_3 ) ;
return F_241 ( V_58 , V_205 , V_201 , V_199 ) ;
}
int F_243 ( struct V_2 * V_3 , struct V_204 * V_205 ,
void * V_200 , int V_80 , unsigned long V_199 )
{
struct V_57 * V_58 = F_162 ( V_3 ) ;
int V_26 ;
T_6 V_201 = V_205 -> V_201 + V_80 ;
F_62 ( V_199 + V_80 > V_205 -> V_199 ) ;
if ( V_58 -> V_93 != V_205 -> V_93 )
F_241 ( V_58 , V_205 , V_205 -> V_201 , V_205 -> V_199 ) ;
if ( F_25 ( ! V_205 -> V_63 ) )
return F_240 ( V_3 , V_201 , V_200 , V_199 ) ;
if ( F_166 ( V_205 -> V_172 ) )
return - V_157 ;
V_26 = F_235 ( ( void V_140 * ) V_205 -> V_172 + V_80 , V_200 , V_199 ) ;
if ( V_26 )
return - V_157 ;
F_236 ( V_205 -> V_63 , V_201 >> V_141 ) ;
return 0 ;
}
int F_244 ( struct V_2 * V_3 , struct V_204 * V_205 ,
void * V_200 , unsigned long V_199 )
{
return F_243 ( V_3 , V_205 , V_200 , 0 , V_199 ) ;
}
int F_245 ( struct V_2 * V_3 , struct V_204 * V_205 ,
void * V_200 , unsigned long V_199 )
{
struct V_57 * V_58 = F_162 ( V_3 ) ;
int V_26 ;
F_62 ( V_199 > V_205 -> V_199 ) ;
if ( V_58 -> V_93 != V_205 -> V_93 )
F_241 ( V_58 , V_205 , V_205 -> V_201 , V_205 -> V_199 ) ;
if ( F_25 ( ! V_205 -> V_63 ) )
return F_227 ( V_3 , V_205 -> V_201 , V_200 , V_199 ) ;
if ( F_166 ( V_205 -> V_172 ) )
return - V_157 ;
V_26 = F_222 ( V_200 , ( void V_140 * ) V_205 -> V_172 , V_199 ) ;
if ( V_26 )
return - V_157 ;
return 0 ;
}
int F_246 ( struct V_9 * V_9 , T_5 V_162 , int V_80 , int V_199 )
{
const void * V_210 = ( const void * ) F_247 ( F_248 ( F_249 ( 0 ) ) ) ;
return F_237 ( V_9 , V_162 , V_210 , V_80 , V_199 ) ;
}
int F_250 ( struct V_9 * V_9 , T_6 V_201 , unsigned long V_199 )
{
T_5 V_162 = V_201 >> V_141 ;
int V_202 ;
int V_80 = F_226 ( V_201 ) ;
int V_203 ;
while ( ( V_202 = F_220 ( V_199 , V_80 ) ) != 0 ) {
V_203 = F_246 ( V_9 , V_162 , V_80 , V_202 ) ;
if ( V_203 < 0 )
return V_203 ;
V_80 = 0 ;
V_199 -= V_202 ;
++ V_162 ;
}
return 0 ;
}
static void F_236 ( struct V_62 * V_63 ,
T_5 V_162 )
{
if ( V_63 && V_63 -> V_64 ) {
unsigned long V_211 = V_162 - V_63 -> V_119 ;
F_251 ( V_211 , V_63 -> V_64 ) ;
}
}
void F_252 ( struct V_9 * V_9 , T_5 V_162 )
{
struct V_62 * V_63 ;
V_63 = F_159 ( V_9 , V_162 ) ;
F_236 ( V_63 , V_162 ) ;
}
void F_253 ( struct V_2 * V_3 , T_5 V_162 )
{
struct V_62 * V_63 ;
V_63 = F_161 ( V_3 , V_162 ) ;
F_236 ( V_63 , V_162 ) ;
}
static void F_254 ( struct V_2 * V_3 )
{
unsigned int V_130 , V_212 , V_213 ;
V_130 = V_212 = V_3 -> V_214 ;
V_213 = F_255 ( V_215 ) ;
if ( V_212 == 0 && V_213 )
V_212 = 10000 ;
else
V_212 *= V_213 ;
if ( V_212 > V_214 )
V_212 = V_214 ;
V_3 -> V_214 = V_212 ;
F_256 ( V_3 -> V_27 , V_212 , V_130 ) ;
}
static void F_257 ( struct V_2 * V_3 )
{
unsigned int V_130 , V_212 , V_216 ;
V_130 = V_212 = V_3 -> V_214 ;
V_216 = F_255 ( V_217 ) ;
if ( V_216 == 0 )
V_212 = 0 ;
else
V_212 /= V_216 ;
V_3 -> V_214 = V_212 ;
F_258 ( V_3 -> V_27 , V_212 , V_130 ) ;
}
static int F_259 ( struct V_2 * V_3 )
{
if ( F_260 ( V_3 ) ) {
F_21 ( V_218 , V_3 ) ;
return - V_6 ;
}
if ( F_261 ( V_3 ) )
return - V_6 ;
if ( F_262 ( V_56 ) )
return - V_6 ;
return 0 ;
}
void F_263 ( struct V_2 * V_3 )
{
T_7 V_50 , V_219 ;
F_264 ( V_220 ) ;
bool V_221 = false ;
T_8 V_222 ;
V_50 = V_219 = F_265 () ;
if ( V_3 -> V_214 ) {
T_7 V_223 = F_266 ( F_265 () , V_3 -> V_214 ) ;
++ V_3 -> V_21 . V_224 ;
do {
if ( F_259 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_225 ;
if ( ! F_267 ( V_3 ) )
++ V_3 -> V_21 . V_226 ;
goto V_133;
}
V_219 = F_265 () ;
} while ( F_268 () && F_269 ( V_219 , V_223 ) );
}
F_270 ( V_3 ) ;
for (; ; ) {
F_271 ( & V_3 -> V_29 , & V_220 , V_227 ) ;
if ( F_259 ( V_3 ) < 0 )
break;
V_221 = true ;
F_272 () ;
}
F_273 ( & V_3 -> V_29 , & V_220 ) ;
V_219 = F_265 () ;
F_274 ( V_3 ) ;
V_133:
V_222 = F_275 ( V_219 ) - F_275 ( V_50 ) ;
if ( ! F_267 ( V_3 ) )
F_257 ( V_3 ) ;
else if ( V_214 ) {
if ( V_222 <= V_3 -> V_214 )
;
else if ( V_3 -> V_214 && V_222 > V_214 )
F_257 ( V_3 ) ;
else if ( V_3 -> V_214 < V_214 &&
V_222 < V_214 )
F_254 ( V_3 ) ;
} else
V_3 -> V_214 = 0 ;
F_276 ( V_222 , V_221 , F_267 ( V_3 ) ) ;
F_277 ( V_3 ) ;
}
void F_278 ( struct V_2 * V_3 )
{
struct V_228 * V_229 ;
V_229 = F_279 ( V_3 ) ;
if ( F_280 ( V_229 ) ) {
F_281 ( V_229 ) ;
++ V_3 -> V_21 . V_230 ;
}
}
void F_282 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
F_278 ( V_3 ) ;
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_231 && F_283 ( V_4 ) )
if ( F_284 ( V_3 ) )
F_285 ( V_4 ) ;
F_10 () ;
}
int F_286 ( struct V_2 * V_232 )
{
struct V_28 * V_28 ;
struct V_233 * V_234 = NULL ;
int V_203 = 0 ;
F_287 () ;
V_28 = F_288 ( V_232 -> V_28 ) ;
if ( V_28 )
V_234 = F_289 ( V_28 , V_235 ) ;
F_290 () ;
if ( ! V_234 )
return V_203 ;
V_203 = F_291 ( V_234 , 1 ) ;
F_292 ( V_234 ) ;
return V_203 ;
}
static bool F_293 ( struct V_2 * V_3 )
{
#ifdef F_294
bool V_236 ;
V_236 = ! V_3 -> V_237 . V_238 ||
V_3 -> V_237 . V_239 ;
if ( V_3 -> V_237 . V_238 )
F_41 ( V_3 , ! V_3 -> V_237 . V_239 ) ;
return V_236 ;
#else
return true ;
#endif
}
void F_295 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_240 = V_12 -> V_9 -> V_240 ;
int V_241 = 0 ;
int V_242 = 3 ;
int V_243 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_243 = 0 ; V_243 < 2 && ! V_241 && V_242 ; V_243 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_243 && V_11 <= V_240 ) {
V_11 = V_240 ;
continue;
} else if ( V_243 && V_11 > V_240 )
break;
if ( ! F_296 ( V_3 -> V_37 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_280 ( & V_3 -> V_29 ) && ! F_260 ( V_3 ) )
continue;
if ( ! F_293 ( V_3 ) )
continue;
V_241 = F_286 ( V_3 ) ;
if ( V_241 > 0 ) {
V_9 -> V_240 = V_11 ;
break;
} else if ( V_241 < 0 ) {
V_242 -- ;
if ( ! V_242 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_297 ( struct V_244 * V_245 )
{
struct V_2 * V_3 = V_245 -> V_164 -> V_246 -> V_114 ;
struct V_25 * V_25 ;
if ( V_245 -> V_247 == 0 )
V_25 = F_298 ( V_3 -> V_36 ) ;
#ifdef F_299
else if ( V_245 -> V_247 == V_248 )
V_25 = F_298 ( V_3 -> V_151 . V_249 ) ;
#endif
#ifdef F_300
else if ( V_245 -> V_247 == F_300 )
V_25 = F_298 ( V_3 -> V_9 -> V_250 ) ;
#endif
else
return F_301 ( V_3 , V_245 ) ;
F_219 ( V_25 ) ;
V_245 -> V_25 = V_25 ;
return 0 ;
}
static int F_302 ( struct V_112 * V_112 , struct V_163 * V_164 )
{
V_164 -> V_251 = & V_252 ;
return 0 ;
}
static int F_303 ( struct V_111 * V_111 , struct V_112 * V_113 )
{
struct V_2 * V_3 = V_113 -> V_114 ;
F_81 ( V_3 -> V_67 ) ;
F_125 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_304 ( struct V_2 * V_3 )
{
return F_305 ( L_2 , & V_253 , V_3 , V_254 | V_255 ) ;
}
static int F_306 ( struct V_2 * V_3 )
{
char V_71 [ V_72 * 2 ] ;
int V_203 ;
if ( ! F_307 () )
return 0 ;
if ( ! F_84 () )
return 0 ;
snprintf ( V_71 , sizeof( V_71 ) , L_3 , V_3 -> V_27 ) ;
V_3 -> V_67 = F_86 ( V_71 ,
V_3 -> V_9 -> V_67 ) ;
if ( ! V_3 -> V_67 )
return - V_34 ;
V_203 = F_308 ( V_3 ) ;
if ( V_203 < 0 ) {
F_81 ( V_3 -> V_67 ) ;
return V_203 ;
}
return 0 ;
}
static int F_309 ( struct V_9 * V_9 , T_4 V_24 )
{
int V_26 ;
struct V_2 * V_3 ;
if ( V_24 >= V_256 )
return - V_126 ;
F_150 ( & V_9 -> V_83 ) ;
if ( V_9 -> V_257 == V_258 ) {
F_16 ( & V_9 -> V_83 ) ;
return - V_126 ;
}
V_9 -> V_257 ++ ;
F_16 ( & V_9 -> V_83 ) ;
V_3 = F_310 ( V_9 , V_24 ) ;
if ( F_311 ( V_3 ) ) {
V_26 = F_312 ( V_3 ) ;
goto V_259;
}
F_313 ( & V_3 -> V_7 , & V_260 ) ;
V_26 = F_314 ( V_3 ) ;
if ( V_26 )
goto V_261;
V_26 = F_306 ( V_3 ) ;
if ( V_26 )
goto V_261;
F_150 ( & V_9 -> V_83 ) ;
if ( F_315 ( V_9 , V_24 ) ) {
V_26 = - V_147 ;
goto V_262;
}
F_62 ( V_9 -> V_263 [ F_316 ( & V_9 -> V_264 ) ] ) ;
F_123 ( V_9 ) ;
V_26 = F_304 ( V_3 ) ;
if ( V_26 < 0 ) {
F_125 ( V_9 ) ;
goto V_262;
}
V_9 -> V_263 [ F_316 ( & V_9 -> V_264 ) ] = V_3 ;
F_61 () ;
F_317 ( & V_9 -> V_264 ) ;
F_16 ( & V_9 -> V_83 ) ;
F_318 ( V_3 ) ;
return V_26 ;
V_262:
F_16 ( & V_9 -> V_83 ) ;
F_81 ( V_3 -> V_67 ) ;
V_261:
F_319 ( V_3 ) ;
V_259:
F_150 ( & V_9 -> V_83 ) ;
V_9 -> V_257 -- ;
F_16 ( & V_9 -> V_83 ) ;
return V_26 ;
}
static int F_320 ( struct V_2 * V_3 , T_9 * V_265 )
{
if ( V_265 ) {
F_321 ( V_265 , F_322 ( V_266 ) | F_322 ( V_267 ) ) ;
V_3 -> V_268 = 1 ;
V_3 -> V_265 = * V_265 ;
} else
V_3 -> V_268 = 0 ;
return 0 ;
}
static long F_323 ( struct V_112 * V_113 ,
unsigned int V_269 , unsigned long V_270 )
{
struct V_2 * V_3 = V_113 -> V_114 ;
void V_140 * V_271 = ( void V_140 * ) V_270 ;
int V_26 ;
struct V_272 * V_273 = NULL ;
struct V_274 * V_274 = NULL ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_275 ;
if ( F_25 ( F_324 ( V_269 ) != V_276 ) )
return - V_126 ;
#if F_119 ( V_277 ) || F_119 ( V_278 ) || F_119 ( V_279 )
if ( V_269 == V_280 || V_269 == V_281 || V_269 == V_282 )
return F_325 ( V_113 , V_269 , V_270 ) ;
#endif
V_26 = F_5 ( V_3 ) ;
if ( V_26 )
return V_26 ;
switch ( V_269 ) {
case V_283 :
V_26 = - V_126 ;
if ( V_270 )
goto V_133;
if ( F_25 ( V_3 -> V_28 != V_56 -> V_284 [ V_235 ] . V_28 ) ) {
struct V_28 * V_285 = V_3 -> V_28 ;
struct V_28 * V_286 = F_326 ( V_56 , V_235 ) ;
F_102 ( V_3 -> V_28 , V_286 ) ;
if ( V_285 )
F_327 () ;
F_45 ( V_285 ) ;
}
V_26 = F_328 ( V_3 , V_3 -> V_36 ) ;
F_329 ( V_3 -> V_36 -> V_287 , V_26 ) ;
break;
case V_288 : {
struct V_289 * V_289 ;
V_26 = - V_34 ;
V_289 = F_88 ( sizeof( struct V_289 ) , V_32 ) ;
if ( ! V_289 )
goto V_133;
V_26 = F_330 ( V_3 , V_289 ) ;
if ( V_26 )
goto V_290;
V_26 = - V_157 ;
if ( F_153 ( V_271 , V_289 , sizeof( struct V_289 ) ) )
goto V_290;
V_26 = 0 ;
V_290:
F_82 ( V_289 ) ;
break;
}
case V_291 : {
struct V_289 * V_289 ;
V_26 = - V_34 ;
V_289 = F_331 ( V_271 , sizeof( * V_289 ) ) ;
if ( F_311 ( V_289 ) ) {
V_26 = F_312 ( V_289 ) ;
goto V_133;
}
V_26 = F_332 ( V_3 , V_289 ) ;
F_82 ( V_289 ) ;
break;
}
case V_292 : {
V_274 = F_88 ( sizeof( struct V_274 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_274 )
goto V_133;
V_26 = F_333 ( V_3 , V_274 ) ;
if ( V_26 )
goto V_133;
V_26 = - V_157 ;
if ( F_153 ( V_271 , V_274 , sizeof( struct V_274 ) ) )
goto V_133;
V_26 = 0 ;
break;
}
case V_293 : {
V_274 = F_331 ( V_271 , sizeof( * V_274 ) ) ;
if ( F_311 ( V_274 ) ) {
V_26 = F_312 ( V_274 ) ;
V_274 = NULL ;
goto V_133;
}
V_26 = F_334 ( V_3 , V_274 ) ;
break;
}
case V_294 : {
struct V_295 V_296 ;
V_26 = F_335 ( V_3 , & V_296 ) ;
if ( V_26 )
goto V_133;
V_26 = - V_157 ;
if ( F_153 ( V_271 , & V_296 , sizeof( V_296 ) ) )
goto V_133;
V_26 = 0 ;
break;
}
case V_297 : {
struct V_295 V_296 ;
V_26 = - V_157 ;
if ( F_336 ( & V_296 , V_271 , sizeof( V_296 ) ) )
goto V_133;
V_26 = F_337 ( V_3 , & V_296 ) ;
break;
}
case V_298 : {
struct V_299 V_300 ;
V_26 = - V_157 ;
if ( F_336 ( & V_300 , V_271 , sizeof( V_300 ) ) )
goto V_133;
V_26 = F_338 ( V_3 , & V_300 ) ;
if ( V_26 )
goto V_133;
V_26 = - V_157 ;
if ( F_153 ( V_271 , & V_300 , sizeof( V_300 ) ) )
goto V_133;
V_26 = 0 ;
break;
}
case V_301 : {
struct V_302 V_303 ;
V_26 = - V_157 ;
if ( F_336 ( & V_303 , V_271 , sizeof( V_303 ) ) )
goto V_133;
V_26 = F_339 ( V_3 , & V_303 ) ;
break;
}
case V_304 : {
struct V_305 V_140 * V_306 = V_271 ;
struct V_305 V_307 ;
T_9 V_265 , * V_76 ;
V_76 = NULL ;
if ( V_271 ) {
V_26 = - V_157 ;
if ( F_336 ( & V_307 , V_271 ,
sizeof( V_307 ) ) )
goto V_133;
V_26 = - V_126 ;
if ( V_307 . V_199 != sizeof( V_265 ) )
goto V_133;
V_26 = - V_157 ;
if ( F_336 ( & V_265 , V_306 -> V_265 ,
sizeof( V_265 ) ) )
goto V_133;
V_76 = & V_265 ;
}
V_26 = F_320 ( V_3 , V_76 ) ;
break;
}
case V_308 : {
V_273 = F_88 ( sizeof( struct V_272 ) , V_32 ) ;
V_26 = - V_34 ;
if ( ! V_273 )
goto V_133;
V_26 = F_340 ( V_3 , V_273 ) ;
if ( V_26 )
goto V_133;
V_26 = - V_157 ;
if ( F_153 ( V_271 , V_273 , sizeof( struct V_272 ) ) )
goto V_133;
V_26 = 0 ;
break;
}
case V_309 : {
V_273 = F_331 ( V_271 , sizeof( * V_273 ) ) ;
if ( F_311 ( V_273 ) ) {
V_26 = F_312 ( V_273 ) ;
V_273 = NULL ;
goto V_133;
}
V_26 = F_341 ( V_3 , V_273 ) ;
break;
}
default:
V_26 = F_325 ( V_113 , V_269 , V_270 ) ;
}
V_133:
F_11 ( V_3 ) ;
F_82 ( V_273 ) ;
F_82 ( V_274 ) ;
return V_26 ;
}
static long F_342 ( struct V_112 * V_113 ,
unsigned int V_269 , unsigned long V_270 )
{
struct V_2 * V_3 = V_113 -> V_114 ;
void V_140 * V_271 = F_343 ( V_270 ) ;
int V_26 ;
if ( V_3 -> V_9 -> V_42 != V_56 -> V_42 )
return - V_275 ;
switch ( V_269 ) {
case V_304 : {
struct V_305 V_140 * V_306 = V_271 ;
struct V_305 V_307 ;
T_10 V_310 ;
T_9 V_265 ;
if ( V_271 ) {
V_26 = - V_157 ;
if ( F_336 ( & V_307 , V_271 ,
sizeof( V_307 ) ) )
goto V_133;
V_26 = - V_126 ;
if ( V_307 . V_199 != sizeof( V_310 ) )
goto V_133;
V_26 = - V_157 ;
if ( F_336 ( & V_310 , V_306 -> V_265 ,
sizeof( V_310 ) ) )
goto V_133;
F_344 ( & V_265 , & V_310 ) ;
V_26 = F_320 ( V_3 , & V_265 ) ;
} else
V_26 = F_320 ( V_3 , NULL ) ;
break;
}
default:
V_26 = F_323 ( V_113 , V_269 , V_270 ) ;
}
V_133:
return V_26 ;
}
static int F_345 ( struct V_104 * V_105 ,
int (* F_346)( struct V_104 * V_105 ,
struct V_311 * V_312 ) ,
unsigned long V_270 )
{
struct V_311 V_312 ;
if ( ! F_346 )
return - V_313 ;
if ( F_336 ( & V_312 , ( void V_140 * ) V_270 , sizeof( V_312 ) ) )
return - V_157 ;
return F_346 ( V_105 , & V_312 ) ;
}
static long F_347 ( struct V_112 * V_113 , unsigned int V_269 ,
unsigned long V_270 )
{
struct V_104 * V_105 = V_113 -> V_114 ;
switch ( V_269 ) {
case V_314 :
return F_345 ( V_105 , V_105 -> V_54 -> V_315 , V_270 ) ;
case V_316 :
return F_345 ( V_105 , V_105 -> V_54 -> V_317 , V_270 ) ;
case V_318 :
return F_345 ( V_105 , V_105 -> V_54 -> V_319 , V_270 ) ;
default:
if ( V_105 -> V_54 -> V_269 )
return V_105 -> V_54 -> V_269 ( V_105 , V_269 , V_270 ) ;
return - V_320 ;
}
}
static int F_348 ( struct V_111 * V_111 , struct V_112 * V_113 )
{
struct V_104 * V_105 = V_113 -> V_114 ;
struct V_9 * V_9 = V_105 -> V_9 ;
F_125 ( V_9 ) ;
return 0 ;
}
struct V_104 * F_349 ( struct V_112 * V_113 )
{
if ( V_113 -> V_321 != & V_322 )
return NULL ;
return V_113 -> V_114 ;
}
int F_350 ( struct V_323 * V_54 , T_4 type )
{
if ( type >= F_351 ( V_324 ) )
return - V_325 ;
if ( V_324 [ type ] != NULL )
return - V_147 ;
V_324 [ type ] = V_54 ;
return 0 ;
}
void F_352 ( T_4 type )
{
if ( V_324 [ type ] != NULL )
V_324 [ type ] = NULL ;
}
static int F_353 ( struct V_9 * V_9 ,
struct V_326 * V_327 )
{
struct V_323 * V_54 = NULL ;
struct V_104 * V_105 ;
bool V_328 = V_327 -> V_125 & V_329 ;
int V_203 ;
if ( V_327 -> type >= F_351 ( V_324 ) )
return - V_330 ;
V_54 = V_324 [ V_327 -> type ] ;
if ( V_54 == NULL )
return - V_330 ;
if ( V_328 )
return 0 ;
V_105 = F_88 ( sizeof( * V_105 ) , V_32 ) ;
if ( ! V_105 )
return - V_34 ;
V_105 -> V_54 = V_54 ;
V_105 -> V_9 = V_9 ;
F_150 ( & V_9 -> V_83 ) ;
V_203 = V_54 -> V_331 ( V_105 , V_327 -> type ) ;
if ( V_203 < 0 ) {
F_16 ( & V_9 -> V_83 ) ;
F_82 ( V_105 ) ;
return V_203 ;
}
F_104 ( & V_105 -> V_107 , & V_9 -> V_87 ) ;
F_16 ( & V_9 -> V_83 ) ;
if ( V_54 -> V_332 )
V_54 -> V_332 ( V_105 ) ;
V_203 = F_305 ( V_54 -> V_79 , & V_322 , V_105 , V_254 | V_255 ) ;
if ( V_203 < 0 ) {
F_150 ( & V_9 -> V_83 ) ;
F_113 ( & V_105 -> V_107 ) ;
F_16 ( & V_9 -> V_83 ) ;
V_54 -> V_108 ( V_105 ) ;
return V_203 ;
}
F_123 ( V_9 ) ;
V_327 -> V_70 = V_203 ;
return 0 ;
}
static long F_354 ( struct V_9 * V_9 , long V_270 )
{
switch ( V_270 ) {
case V_333 :
case V_334 :
case V_335 :
case V_336 :
#ifdef F_355
case V_337 :
#endif
#ifdef F_99
case V_338 :
case V_339 :
#endif
case V_340 :
case V_341 :
return 1 ;
#ifdef F_356
case V_342 :
return V_343 ;
#endif
#if V_91 > 1
case V_344 :
return V_91 ;
#endif
case V_345 :
return V_256 ;
default:
break;
}
return F_357 ( V_9 , V_270 ) ;
}
static long F_358 ( struct V_112 * V_113 ,
unsigned int V_269 , unsigned long V_270 )
{
struct V_9 * V_9 = V_113 -> V_114 ;
void V_140 * V_271 = ( void V_140 * ) V_270 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_275 ;
switch ( V_269 ) {
case V_346 :
V_26 = F_309 ( V_9 , V_270 ) ;
break;
case V_347 : {
struct V_120 V_348 ;
V_26 = - V_157 ;
if ( F_336 ( & V_348 , V_271 ,
sizeof( V_348 ) ) )
goto V_133;
V_26 = F_151 ( V_9 , & V_348 ) ;
break;
}
case V_349 : {
struct V_152 log ;
V_26 = - V_157 ;
if ( F_336 ( & log , V_271 , sizeof( log ) ) )
goto V_133;
V_26 = F_359 ( V_9 , & log ) ;
break;
}
#ifdef F_300
case V_350 : {
struct V_351 V_352 ;
V_26 = - V_157 ;
if ( F_336 ( & V_352 , V_271 , sizeof( V_352 ) ) )
goto V_133;
V_26 = F_360 ( V_9 , & V_352 ) ;
break;
}
case V_353 : {
struct V_351 V_352 ;
V_26 = - V_157 ;
if ( F_336 ( & V_352 , V_271 , sizeof( V_352 ) ) )
goto V_133;
V_26 = F_361 ( V_9 , & V_352 ) ;
break;
}
#endif
case V_354 : {
struct V_355 V_200 ;
V_26 = - V_157 ;
if ( F_336 ( & V_200 , V_271 , sizeof( V_200 ) ) )
goto V_133;
V_26 = V_355 ( V_9 , & V_200 ) ;
break;
}
case V_356 : {
struct V_357 V_200 ;
V_26 = - V_157 ;
if ( F_336 ( & V_200 , V_271 , sizeof( V_200 ) ) )
goto V_133;
V_26 = V_357 ( V_9 , & V_200 ) ;
break;
}
#ifdef F_355
case V_358 : {
struct V_359 V_360 ;
V_26 = - V_157 ;
if ( F_336 ( & V_360 , V_271 , sizeof( V_360 ) ) )
goto V_133;
V_26 = F_362 ( V_9 , & V_360 ) ;
break;
}
#endif
#ifdef F_363
case V_361 :
case V_362 : {
struct V_363 V_364 ;
V_26 = - V_157 ;
if ( F_336 ( & V_364 , V_271 , sizeof( V_364 ) ) )
goto V_133;
V_26 = F_364 ( V_9 , & V_364 ,
V_269 == V_361 ) ;
if ( V_26 )
goto V_133;
V_26 = - V_157 ;
if ( V_269 == V_361 ) {
if ( F_153 ( V_271 , & V_364 , sizeof( V_364 ) ) )
goto V_133;
}
V_26 = 0 ;
break;
}
#endif
#ifdef F_356
case V_365 : {
struct V_366 V_367 ;
struct V_366 V_140 * V_368 ;
struct V_369 * V_370 = NULL ;
V_26 = - V_157 ;
if ( F_336 ( & V_367 , V_271 , sizeof( V_367 ) ) )
goto V_133;
V_26 = - V_126 ;
if ( V_367 . V_371 > V_343 )
goto V_133;
if ( V_367 . V_125 )
goto V_133;
if ( V_367 . V_371 ) {
V_26 = - V_34 ;
V_370 = F_365 ( V_367 . V_371 * sizeof( * V_370 ) ) ;
if ( ! V_370 )
goto V_133;
V_26 = - V_157 ;
V_368 = V_271 ;
if ( F_336 ( V_370 , V_368 -> V_370 ,
V_367 . V_371 * sizeof( * V_370 ) ) )
goto V_372;
}
V_26 = F_366 ( V_9 , V_370 , V_367 . V_371 ,
V_367 . V_125 ) ;
V_372:
F_367 ( V_370 ) ;
break;
}
#endif
case V_373 : {
struct V_326 V_327 ;
V_26 = - V_157 ;
if ( F_336 ( & V_327 , V_271 , sizeof( V_327 ) ) )
goto V_133;
V_26 = F_353 ( V_9 , & V_327 ) ;
if ( V_26 )
goto V_133;
V_26 = - V_157 ;
if ( F_153 ( V_271 , & V_327 , sizeof( V_327 ) ) )
goto V_133;
V_26 = 0 ;
break;
}
case V_374 :
V_26 = F_354 ( V_9 , V_270 ) ;
break;
default:
V_26 = F_368 ( V_113 , V_269 , V_270 ) ;
}
V_133:
return V_26 ;
}
static long F_369 ( struct V_112 * V_113 ,
unsigned int V_269 , unsigned long V_270 )
{
struct V_9 * V_9 = V_113 -> V_114 ;
int V_26 ;
if ( V_9 -> V_42 != V_56 -> V_42 )
return - V_275 ;
switch ( V_269 ) {
case V_349 : {
struct V_375 V_376 ;
struct V_152 log ;
if ( F_336 ( & V_376 , ( void V_140 * ) V_270 ,
sizeof( V_376 ) ) )
return - V_157 ;
log . V_129 = V_376 . V_129 ;
log . V_377 = V_376 . V_377 ;
log . V_378 = V_376 . V_378 ;
log . V_64 = F_343 ( V_376 . V_64 ) ;
V_26 = F_359 ( V_9 , & log ) ;
break;
}
default:
V_26 = F_358 ( V_113 , V_269 , V_270 ) ;
}
return V_26 ;
}
static int F_370 ( unsigned long type )
{
int V_26 ;
struct V_9 * V_9 ;
struct V_112 * V_112 ;
V_9 = F_90 ( type ) ;
if ( F_311 ( V_9 ) )
return F_312 ( V_9 ) ;
#ifdef F_300
V_26 = F_371 ( V_9 ) ;
if ( V_26 < 0 ) {
F_125 ( V_9 ) ;
return V_26 ;
}
#endif
V_26 = F_372 ( V_255 ) ;
if ( V_26 < 0 ) {
F_125 ( V_9 ) ;
return V_26 ;
}
V_112 = F_373 ( L_4 , & V_379 , V_9 , V_254 ) ;
if ( F_311 ( V_112 ) ) {
F_374 ( V_26 ) ;
F_125 ( V_9 ) ;
return F_312 ( V_112 ) ;
}
if ( F_83 ( V_9 , V_26 ) < 0 ) {
F_374 ( V_26 ) ;
F_375 ( V_112 ) ;
return - V_34 ;
}
F_376 ( V_26 , V_112 ) ;
return V_26 ;
}
static long F_377 ( struct V_112 * V_113 ,
unsigned int V_269 , unsigned long V_270 )
{
long V_26 = - V_126 ;
switch ( V_269 ) {
case V_380 :
if ( V_270 )
goto V_133;
V_26 = V_381 ;
break;
case V_382 :
V_26 = F_370 ( V_270 ) ;
break;
case V_374 :
V_26 = F_354 ( NULL , V_270 ) ;
break;
case V_383 :
if ( V_270 )
goto V_133;
V_26 = V_103 ;
#ifdef F_299
V_26 += V_103 ;
#endif
#ifdef F_300
V_26 += V_103 ;
#endif
break;
case V_384 :
case V_385 :
case V_386 :
V_26 = - V_387 ;
break;
default:
return F_378 ( V_113 , V_269 , V_270 ) ;
}
V_133:
return V_26 ;
}
static void F_379 ( void * V_388 )
{
int V_4 = F_380 () ;
int V_26 ;
if ( F_381 ( V_4 , V_389 ) )
return;
F_24 ( V_4 , V_389 ) ;
V_26 = F_382 () ;
if ( V_26 ) {
F_383 ( V_4 , V_389 ) ;
F_317 ( & V_390 ) ;
F_384 ( L_5 , V_4 ) ;
}
}
static int F_385 ( unsigned int V_4 )
{
F_386 ( & V_391 ) ;
if ( V_392 )
F_379 ( NULL ) ;
F_387 ( & V_391 ) ;
return 0 ;
}
static void F_388 ( void * V_388 )
{
int V_4 = F_380 () ;
if ( ! F_381 ( V_4 , V_389 ) )
return;
F_383 ( V_4 , V_389 ) ;
F_389 () ;
}
static int F_390 ( unsigned int V_4 )
{
F_386 ( & V_391 ) ;
if ( V_392 )
F_388 ( NULL ) ;
F_387 ( & V_391 ) ;
return 0 ;
}
static void F_391 ( void )
{
F_62 ( ! V_392 ) ;
V_392 -- ;
if ( ! V_392 )
F_392 ( F_388 , NULL , 1 ) ;
}
static void F_107 ( void )
{
F_386 ( & V_391 ) ;
F_391 () ;
F_387 ( & V_391 ) ;
}
static int F_98 ( void )
{
int V_26 = 0 ;
F_386 ( & V_391 ) ;
V_392 ++ ;
if ( V_392 == 1 ) {
F_393 ( & V_390 , 0 ) ;
F_392 ( F_379 , NULL , 1 ) ;
if ( F_316 ( & V_390 ) ) {
F_391 () ;
V_26 = - V_393 ;
}
}
F_387 ( & V_391 ) ;
return V_26 ;
}
static int F_394 ( struct V_394 * V_395 , unsigned long V_212 ,
void * V_396 )
{
F_384 ( L_6 ) ;
V_397 = true ;
F_392 ( F_388 , NULL , 1 ) ;
return V_398 ;
}
static void F_117 ( struct V_98 * V_399 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_399 -> V_400 ; V_11 ++ ) {
struct V_401 * V_402 = V_399 -> V_403 [ V_11 ] . V_105 ;
F_395 ( V_402 ) ;
}
F_82 ( V_399 ) ;
}
static inline int F_396 ( const struct V_404 * V_405 ,
const struct V_404 * V_406 )
{
T_6 V_407 = V_405 -> V_165 ;
T_6 V_408 = V_406 -> V_165 ;
if ( V_407 < V_408 )
return - 1 ;
if ( V_406 -> V_199 ) {
V_407 += V_405 -> V_199 ;
V_408 += V_406 -> V_199 ;
}
if ( V_407 > V_408 )
return 1 ;
return 0 ;
}
static int F_397 ( const void * V_409 , const void * V_410 )
{
return F_396 ( V_409 , V_410 ) ;
}
static int F_398 ( struct V_98 * V_399 , struct V_401 * V_105 ,
T_6 V_165 , int V_199 )
{
V_399 -> V_403 [ V_399 -> V_400 ++ ] = (struct V_404 ) {
. V_165 = V_165 ,
. V_199 = V_199 ,
. V_105 = V_105 ,
} ;
F_399 ( V_399 -> V_403 , V_399 -> V_400 , sizeof( struct V_404 ) ,
F_397 , NULL ) ;
return 0 ;
}
static int F_400 ( struct V_98 * V_399 ,
T_6 V_165 , int V_199 )
{
struct V_404 * V_403 , V_411 ;
int V_412 ;
V_411 = (struct V_404 ) {
. V_165 = V_165 ,
. V_199 = V_199 ,
} ;
V_403 = bsearch ( & V_411 , V_399 -> V_403 , V_399 -> V_400 ,
sizeof( struct V_404 ) , F_397 ) ;
if ( V_403 == NULL )
return - V_156 ;
V_412 = V_403 - V_399 -> V_403 ;
while ( V_412 > 0 && F_396 ( & V_411 , & V_399 -> V_403 [ V_412 - 1 ] ) == 0 )
V_412 -- ;
return V_412 ;
}
static int F_401 ( struct V_2 * V_3 , struct V_98 * V_399 ,
struct V_404 * V_403 , const void * V_212 )
{
int V_45 ;
V_45 = F_400 ( V_399 , V_403 -> V_165 , V_403 -> V_199 ) ;
if ( V_45 < 0 )
return - V_387 ;
while ( V_45 < V_399 -> V_400 &&
F_396 ( V_403 , & V_399 -> V_403 [ V_45 ] ) == 0 ) {
if ( ! F_402 ( V_3 , V_399 -> V_403 [ V_45 ] . V_105 , V_403 -> V_165 ,
V_403 -> V_199 , V_212 ) )
return V_45 ;
V_45 ++ ;
}
return - V_387 ;
}
int F_403 ( struct V_2 * V_3 , enum V_413 V_414 , T_6 V_165 ,
int V_199 , const void * V_212 )
{
struct V_98 * V_399 ;
struct V_404 V_403 ;
int V_26 ;
V_403 = (struct V_404 ) {
. V_165 = V_165 ,
. V_199 = V_199 ,
} ;
V_399 = F_404 ( V_3 -> V_9 -> V_97 [ V_414 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ! V_399 )
return - V_34 ;
V_26 = F_401 ( V_3 , V_399 , & V_403 , V_212 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_405 ( struct V_2 * V_3 , enum V_413 V_414 ,
T_6 V_165 , int V_199 , const void * V_212 , long V_415 )
{
struct V_98 * V_399 ;
struct V_404 V_403 ;
V_403 = (struct V_404 ) {
. V_165 = V_165 ,
. V_199 = V_199 ,
} ;
V_399 = F_404 ( V_3 -> V_9 -> V_97 [ V_414 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ! V_399 )
return - V_34 ;
if ( ( V_415 >= 0 ) && ( V_415 < V_399 -> V_400 ) &&
( F_396 ( & V_403 , & V_399 -> V_403 [ V_415 ] ) == 0 ) )
if ( ! F_402 ( V_3 , V_399 -> V_403 [ V_415 ] . V_105 , V_165 , V_199 ,
V_212 ) )
return V_415 ;
return F_401 ( V_3 , V_399 , & V_403 , V_212 ) ;
}
static int F_406 ( struct V_2 * V_3 , struct V_98 * V_399 ,
struct V_404 * V_403 , void * V_212 )
{
int V_45 ;
V_45 = F_400 ( V_399 , V_403 -> V_165 , V_403 -> V_199 ) ;
if ( V_45 < 0 )
return - V_387 ;
while ( V_45 < V_399 -> V_400 &&
F_396 ( V_403 , & V_399 -> V_403 [ V_45 ] ) == 0 ) {
if ( ! F_407 ( V_3 , V_399 -> V_403 [ V_45 ] . V_105 , V_403 -> V_165 ,
V_403 -> V_199 , V_212 ) )
return V_45 ;
V_45 ++ ;
}
return - V_387 ;
}
int F_408 ( struct V_2 * V_3 , enum V_413 V_414 , T_6 V_165 ,
int V_199 , void * V_212 )
{
struct V_98 * V_399 ;
struct V_404 V_403 ;
int V_26 ;
V_403 = (struct V_404 ) {
. V_165 = V_165 ,
. V_199 = V_199 ,
} ;
V_399 = F_404 ( V_3 -> V_9 -> V_97 [ V_414 ] , & V_3 -> V_9 -> V_46 ) ;
if ( ! V_399 )
return - V_34 ;
V_26 = F_406 ( V_3 , V_399 , & V_403 , V_212 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_409 ( struct V_9 * V_9 , enum V_413 V_414 , T_6 V_165 ,
int V_199 , struct V_401 * V_105 )
{
struct V_98 * V_416 , * V_399 ;
V_399 = V_9 -> V_97 [ V_414 ] ;
if ( ! V_399 )
return - V_34 ;
if ( V_399 -> V_400 - V_399 -> V_417 > V_418 - 1 )
return - V_325 ;
V_416 = F_410 ( sizeof( * V_399 ) + ( ( V_399 -> V_400 + 1 ) *
sizeof( struct V_404 ) ) , V_32 ) ;
if ( ! V_416 )
return - V_34 ;
memcpy ( V_416 , V_399 , sizeof( * V_399 ) + ( V_399 -> V_400 *
sizeof( struct V_404 ) ) ) ;
F_398 ( V_416 , V_105 , V_165 , V_199 ) ;
F_102 ( V_9 -> V_97 [ V_414 ] , V_416 ) ;
F_138 ( & V_9 -> V_46 ) ;
F_82 ( V_399 ) ;
return 0 ;
}
void F_411 ( struct V_9 * V_9 , enum V_413 V_414 ,
struct V_401 * V_105 )
{
int V_11 ;
struct V_98 * V_416 , * V_399 ;
V_399 = V_9 -> V_97 [ V_414 ] ;
if ( ! V_399 )
return;
for ( V_11 = 0 ; V_11 < V_399 -> V_400 ; V_11 ++ )
if ( V_399 -> V_403 [ V_11 ] . V_105 == V_105 ) {
break;
}
if ( V_11 == V_399 -> V_400 )
return;
V_416 = F_410 ( sizeof( * V_399 ) + ( ( V_399 -> V_400 - 1 ) *
sizeof( struct V_404 ) ) , V_32 ) ;
if ( ! V_416 ) {
F_412 ( L_7 ) ;
goto V_419;
}
memcpy ( V_416 , V_399 , sizeof( * V_399 ) + V_11 * sizeof( struct V_404 ) ) ;
V_416 -> V_400 -- ;
memcpy ( V_416 -> V_403 + V_11 , V_399 -> V_403 + V_11 + 1 ,
( V_416 -> V_400 - V_11 ) * sizeof( struct V_404 ) ) ;
V_419:
F_102 ( V_9 -> V_97 [ V_414 ] , V_416 ) ;
F_138 ( & V_9 -> V_46 ) ;
F_82 ( V_399 ) ;
return;
}
struct V_401 * F_413 ( struct V_9 * V_9 , enum V_413 V_414 ,
T_6 V_165 )
{
struct V_98 * V_399 ;
int V_420 , V_421 ;
struct V_401 * V_422 = NULL ;
V_421 = F_50 ( & V_9 -> V_46 ) ;
V_399 = F_404 ( V_9 -> V_97 [ V_414 ] , & V_9 -> V_46 ) ;
if ( ! V_399 )
goto V_423;
V_420 = F_400 ( V_399 , V_165 , 1 ) ;
if ( V_420 < 0 )
goto V_423;
V_422 = V_399 -> V_403 [ V_420 ] . V_105 ;
V_423:
F_55 ( & V_9 -> V_46 , V_421 ) ;
return V_422 ;
}
static int F_414 ( struct V_111 * V_111 , struct V_112 * V_112 ,
int (* F_415)( void * , T_8 * ) , int (* F_416)( void * , T_8 ) ,
const char * V_424 )
{
struct V_73 * V_74 = (struct V_73 * )
V_111 -> V_425 ;
if ( ! F_417 ( & V_74 -> V_9 -> V_86 ) )
return - V_156 ;
if ( F_418 ( V_111 , V_112 , F_415 , F_416 , V_424 ) ) {
F_125 ( V_74 -> V_9 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_419 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
struct V_73 * V_74 = (struct V_73 * )
V_111 -> V_425 ;
F_420 ( V_111 , V_112 ) ;
F_125 ( V_74 -> V_9 ) ;
return 0 ;
}
static int F_421 ( void * V_200 , T_8 * V_212 )
{
struct V_73 * V_74 = (struct V_73 * ) V_200 ;
* V_212 = * ( V_426 * ) ( ( void * ) V_74 -> V_9 + V_74 -> V_80 ) ;
return 0 ;
}
static int F_422 ( void * V_200 , T_8 V_212 )
{
struct V_73 * V_74 = (struct V_73 * ) V_200 ;
if ( V_212 )
return - V_126 ;
* ( V_426 * ) ( ( void * ) V_74 -> V_9 + V_74 -> V_80 ) = 0 ;
return 0 ;
}
static int F_423 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
F_424 ( L_8 , 0ull ) ;
return F_414 ( V_111 , V_112 , F_421 ,
F_422 , L_8 ) ;
}
static int F_425 ( void * V_200 , T_8 * V_212 )
{
int V_11 ;
struct V_73 * V_74 = (struct V_73 * ) V_200 ;
struct V_2 * V_3 ;
* V_212 = 0 ;
F_20 ( V_11 , V_3 , V_74 -> V_9 )
* V_212 += * ( T_8 * ) ( ( void * ) V_3 + V_74 -> V_80 ) ;
return 0 ;
}
static int F_426 ( void * V_200 , T_8 V_212 )
{
int V_11 ;
struct V_73 * V_74 = (struct V_73 * ) V_200 ;
struct V_2 * V_3 ;
if ( V_212 )
return - V_126 ;
F_20 ( V_11 , V_3 , V_74 -> V_9 )
* ( T_8 * ) ( ( void * ) V_3 + V_74 -> V_80 ) = 0 ;
return 0 ;
}
static int F_427 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
F_424 ( L_8 , 0ull ) ;
return F_414 ( V_111 , V_112 , F_425 ,
F_426 , L_8 ) ;
}
static int F_428 ( void * V_427 , T_8 * V_212 )
{
unsigned V_80 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_73 V_428 = { . V_80 = V_80 } ;
T_8 V_429 ;
* V_212 = 0 ;
F_51 ( & V_100 ) ;
F_429 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_421 ( ( void * ) & V_428 , & V_429 ) ;
* V_212 += V_429 ;
}
F_53 ( & V_100 ) ;
return 0 ;
}
static int F_430 ( void * V_427 , T_8 V_212 )
{
unsigned V_80 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_73 V_428 = { . V_80 = V_80 } ;
if ( V_212 )
return - V_126 ;
F_51 ( & V_100 ) ;
F_429 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_422 ( ( void * ) & V_428 , 0 ) ;
}
F_53 ( & V_100 ) ;
return 0 ;
}
static int F_431 ( void * V_427 , T_8 * V_212 )
{
unsigned V_80 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_73 V_428 = { . V_80 = V_80 } ;
T_8 V_429 ;
* V_212 = 0 ;
F_51 ( & V_100 ) ;
F_429 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_425 ( ( void * ) & V_428 , & V_429 ) ;
* V_212 += V_429 ;
}
F_53 ( & V_100 ) ;
return 0 ;
}
static int F_432 ( void * V_427 , T_8 V_212 )
{
unsigned V_80 = ( long ) V_427 ;
struct V_9 * V_9 ;
struct V_73 V_428 = { . V_80 = V_80 } ;
if ( V_212 )
return - V_126 ;
F_51 ( & V_100 ) ;
F_429 (kvm, &vm_list, vm_list) {
V_428 . V_9 = V_9 ;
F_426 ( ( void * ) & V_428 , 0 ) ;
}
F_53 ( & V_100 ) ;
return 0 ;
}
static int F_433 ( void )
{
int V_26 = - V_147 ;
struct V_75 * V_76 ;
V_77 = F_86 ( L_9 , NULL ) ;
if ( V_77 == NULL )
goto V_133;
V_69 = 0 ;
for ( V_76 = V_78 ; V_76 -> V_79 ; ++ V_76 , V_69 ++ ) {
if ( ! F_89 ( V_76 -> V_79 , 0644 , V_77 ,
( void * ) ( long ) V_76 -> V_80 ,
V_430 [ V_76 -> V_82 ] ) )
goto V_431;
}
return 0 ;
V_431:
F_81 ( V_77 ) ;
V_133:
return V_26 ;
}
static int F_434 ( void )
{
if ( V_392 )
F_388 ( NULL ) ;
return 0 ;
}
static void F_435 ( void )
{
if ( V_392 ) {
F_132 ( F_436 ( & V_391 ) ) ;
F_379 ( NULL ) ;
}
}
static inline
struct V_2 * F_437 ( struct V_7 * V_432 )
{
return F_48 ( V_432 , struct V_2 , V_7 ) ;
}
static void F_438 ( struct V_7 * V_432 , int V_4 )
{
struct V_2 * V_3 = F_437 ( V_432 ) ;
if ( V_3 -> V_37 )
V_3 -> V_37 = false ;
F_439 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_440 ( struct V_7 * V_432 ,
struct V_233 * V_433 )
{
struct V_2 * V_3 = F_437 ( V_432 ) ;
if ( V_56 -> V_434 == V_435 )
V_3 -> V_37 = true ;
F_13 ( V_3 ) ;
}
int F_441 ( void * V_436 , unsigned V_437 , unsigned V_438 ,
struct V_439 * V_439 )
{
int V_26 ;
int V_4 ;
V_26 = F_442 ( V_436 ) ;
if ( V_26 )
goto V_440;
V_26 = F_443 () ;
if ( V_26 )
goto V_441;
if ( ! F_19 ( & V_389 , V_32 ) ) {
V_26 = - V_34 ;
goto V_442;
}
V_26 = F_444 () ;
if ( V_26 < 0 )
goto V_443;
F_445 (cpu) {
F_446 ( V_4 ,
V_444 ,
& V_26 , 1 ) ;
if ( V_26 < 0 )
goto V_445;
}
V_26 = F_447 ( V_446 , L_10 ,
F_385 , F_390 ) ;
if ( V_26 )
goto V_447;
F_448 ( & V_448 ) ;
if ( ! V_438 )
V_438 = F_449 ( struct V_2 ) ;
V_449 = F_450 ( L_11 , V_437 , V_438 ,
0 , NULL ) ;
if ( ! V_449 ) {
V_26 = - V_34 ;
goto V_450;
}
V_26 = F_451 () ;
if ( V_26 )
goto V_148;
V_451 . V_452 = V_439 ;
V_379 . V_452 = V_439 ;
V_253 . V_452 = V_439 ;
V_26 = F_452 ( & V_453 ) ;
if ( V_26 ) {
F_412 ( L_12 ) ;
goto V_454;
}
F_453 ( & V_455 ) ;
V_260 . V_456 = F_438 ;
V_260 . V_457 = F_440 ;
V_26 = F_433 () ;
if ( V_26 ) {
F_412 ( L_13 ) ;
goto V_458;
}
V_26 = F_454 () ;
F_132 ( V_26 ) ;
return 0 ;
V_458:
F_455 ( & V_455 ) ;
F_456 ( & V_453 ) ;
V_454:
F_457 () ;
V_148:
F_458 ( V_449 ) ;
V_450:
F_459 ( & V_448 ) ;
F_460 ( V_446 ) ;
V_447:
V_445:
F_461 () ;
V_443:
F_28 ( V_389 ) ;
V_442:
F_462 () ;
V_441:
F_463 () ;
V_440:
return V_26 ;
}
void F_464 ( void )
{
F_81 ( V_77 ) ;
F_456 ( & V_453 ) ;
F_458 ( V_449 ) ;
F_457 () ;
F_455 ( & V_455 ) ;
F_459 ( & V_448 ) ;
F_460 ( V_446 ) ;
F_392 ( F_388 , NULL , 1 ) ;
F_461 () ;
F_463 () ;
F_462 () ;
F_28 ( V_389 ) ;
F_465 () ;
}
