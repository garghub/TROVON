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
long V_18 = V_9 -> V_19 ;
F_22 () ;
if ( F_18 ( V_9 , V_20 ) )
++ V_9 -> V_21 . V_22 ;
F_30 ( & V_9 -> V_19 , V_18 , 0 ) ;
}
void F_31 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_23 ) ;
}
void F_32 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_24 ) ;
}
void F_33 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_25 ) ;
}
int F_34 ( struct V_2 * V_3 , struct V_9 * V_9 , unsigned V_26 )
{
struct V_27 * V_27 ;
int V_28 ;
F_35 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_29 = V_26 ;
V_3 -> V_30 = NULL ;
V_3 -> V_31 = 0 ;
F_36 ( & V_3 -> V_32 ) ;
F_37 ( V_3 ) ;
V_3 -> V_33 = - 1 ;
F_38 ( & V_3 -> V_34 ) ;
V_27 = F_39 ( V_35 | V_36 ) ;
if ( ! V_27 ) {
V_28 = - V_37 ;
goto V_38;
}
V_3 -> V_39 = F_40 ( V_27 ) ;
F_41 ( V_3 , false ) ;
F_42 ( V_3 , false ) ;
V_3 -> V_40 = false ;
V_28 = F_43 ( V_3 ) ;
if ( V_28 < 0 )
goto V_41;
return 0 ;
V_41:
F_44 ( ( unsigned long ) V_3 -> V_39 ) ;
V_38:
return V_28 ;
}
void F_45 ( struct V_2 * V_3 )
{
F_46 ( V_3 -> V_30 ) ;
F_47 ( V_3 ) ;
F_44 ( ( unsigned long ) V_3 -> V_39 ) ;
}
static inline struct V_9 * F_48 ( struct V_42 * V_43 )
{
return F_49 ( V_43 , struct V_9 , V_42 ) ;
}
static void F_50 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
unsigned long V_46 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
int V_47 , V_48 ;
V_48 = F_51 ( & V_9 -> V_49 ) ;
F_52 ( & V_9 -> V_50 ) ;
V_9 -> V_51 ++ ;
V_47 = F_53 ( V_9 , V_46 ) | V_9 -> V_19 ;
if ( V_47 )
F_29 ( V_9 ) ;
F_54 ( & V_9 -> V_50 ) ;
F_55 ( V_9 , V_46 ) ;
F_56 ( & V_9 -> V_49 , V_48 ) ;
}
static void F_57 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
unsigned long V_46 ,
T_3 V_52 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
int V_48 ;
V_48 = F_51 ( & V_9 -> V_49 ) ;
F_52 ( & V_9 -> V_50 ) ;
V_9 -> V_51 ++ ;
F_58 ( V_9 , V_46 , V_52 ) ;
F_54 ( & V_9 -> V_50 ) ;
F_56 ( & V_9 -> V_49 , V_48 ) ;
}
static void F_59 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
unsigned long V_53 ,
unsigned long V_54 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
int V_47 = 0 , V_48 ;
V_48 = F_51 ( & V_9 -> V_49 ) ;
F_52 ( & V_9 -> V_50 ) ;
V_9 -> V_55 ++ ;
V_47 = F_60 ( V_9 , V_53 , V_54 ) ;
V_47 |= V_9 -> V_19 ;
if ( V_47 )
F_29 ( V_9 ) ;
F_54 ( & V_9 -> V_50 ) ;
F_56 ( & V_9 -> V_49 , V_48 ) ;
}
static void F_61 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
unsigned long V_53 ,
unsigned long V_54 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
F_52 ( & V_9 -> V_50 ) ;
V_9 -> V_51 ++ ;
F_62 () ;
V_9 -> V_55 -- ;
F_54 ( & V_9 -> V_50 ) ;
F_63 ( V_9 -> V_55 < 0 ) ;
}
static int F_64 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
unsigned long V_53 ,
unsigned long V_54 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
int V_56 , V_48 ;
V_48 = F_51 ( & V_9 -> V_49 ) ;
F_52 ( & V_9 -> V_50 ) ;
V_56 = F_65 ( V_9 , V_53 , V_54 ) ;
if ( V_56 )
F_29 ( V_9 ) ;
F_54 ( & V_9 -> V_50 ) ;
F_56 ( & V_9 -> V_49 , V_48 ) ;
return V_56 ;
}
static int F_66 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
unsigned long V_53 ,
unsigned long V_54 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
int V_56 , V_48 ;
V_48 = F_51 ( & V_9 -> V_49 ) ;
F_52 ( & V_9 -> V_50 ) ;
V_56 = F_65 ( V_9 , V_53 , V_54 ) ;
F_54 ( & V_9 -> V_50 ) ;
F_56 ( & V_9 -> V_49 , V_48 ) ;
return V_56 ;
}
static int F_67 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
unsigned long V_46 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
int V_56 , V_48 ;
V_48 = F_51 ( & V_9 -> V_49 ) ;
F_52 ( & V_9 -> V_50 ) ;
V_56 = F_68 ( V_9 , V_46 ) ;
F_54 ( & V_9 -> V_50 ) ;
F_56 ( & V_9 -> V_49 , V_48 ) ;
return V_56 ;
}
static void F_69 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_9 * V_9 = F_48 ( V_43 ) ;
int V_48 ;
V_48 = F_51 ( & V_9 -> V_49 ) ;
F_70 ( V_9 ) ;
F_56 ( & V_9 -> V_49 , V_48 ) ;
}
static int F_71 ( struct V_9 * V_9 )
{
V_9 -> V_42 . V_57 = & V_58 ;
return F_72 ( & V_9 -> V_42 , V_59 -> V_45 ) ;
}
static int F_71 ( struct V_9 * V_9 )
{
return 0 ;
}
static struct V_60 * F_73 ( void )
{
int V_11 ;
struct V_60 * V_61 ;
V_61 = F_74 ( sizeof( struct V_60 ) ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_62 = - 150 ;
for ( V_11 = 0 ; V_11 < V_63 ; V_11 ++ )
V_61 -> V_64 [ V_11 ] = V_61 -> V_65 [ V_11 ] . V_26 = V_11 ;
return V_61 ;
}
static void F_75 ( struct V_66 * V_67 )
{
if ( ! V_67 -> V_68 )
return;
F_76 ( V_67 -> V_68 ) ;
V_67 -> V_68 = NULL ;
}
static void F_77 ( struct V_9 * V_9 , struct V_66 * free ,
struct V_66 * V_69 )
{
if ( ! V_69 || free -> V_68 != V_69 -> V_68 )
F_75 ( free ) ;
F_78 ( V_9 , free , V_69 ) ;
free -> V_70 = 0 ;
}
static void F_79 ( struct V_9 * V_9 , struct V_60 * V_61 )
{
struct V_66 * V_67 ;
if ( ! V_61 )
return;
F_80 (memslot, slots)
F_77 ( V_9 , V_67 , NULL ) ;
F_76 ( V_61 ) ;
}
static struct V_9 * F_81 ( unsigned long type )
{
int V_28 , V_11 ;
struct V_9 * V_9 = F_82 () ;
if ( ! V_9 )
return F_83 ( - V_37 ) ;
V_28 = F_84 ( V_9 , type ) ;
if ( V_28 )
goto V_71;
V_28 = F_85 () ;
if ( V_28 )
goto V_71;
#ifdef F_86
F_87 ( & V_9 -> V_72 ) ;
#endif
F_88 ( V_63 > V_73 ) ;
V_28 = - V_37 ;
for ( V_11 = 0 ; V_11 < V_74 ; V_11 ++ ) {
V_9 -> V_65 [ V_11 ] = F_73 () ;
if ( ! V_9 -> V_65 [ V_11 ] )
goto V_75;
}
if ( F_89 ( & V_9 -> V_49 ) )
goto V_75;
if ( F_89 ( & V_9 -> V_76 ) )
goto V_77;
for ( V_11 = 0 ; V_11 < V_78 ; V_11 ++ ) {
V_9 -> V_79 [ V_11 ] = F_90 ( sizeof( struct V_80 ) ,
V_35 ) ;
if ( ! V_9 -> V_79 [ V_11 ] )
goto V_81;
}
F_91 ( & V_9 -> V_50 ) ;
V_9 -> V_45 = V_59 -> V_45 ;
F_92 ( & V_9 -> V_45 -> V_82 ) ;
F_93 ( V_9 ) ;
F_35 ( & V_9 -> V_83 ) ;
F_35 ( & V_9 -> V_84 ) ;
F_35 ( & V_9 -> V_85 ) ;
F_94 ( & V_9 -> V_86 , 1 ) ;
F_38 ( & V_9 -> V_87 ) ;
V_28 = F_71 ( V_9 ) ;
if ( V_28 )
goto V_81;
F_52 ( & V_88 ) ;
F_95 ( & V_9 -> V_89 , & V_89 ) ;
F_54 ( & V_88 ) ;
F_96 () ;
return V_9 ;
V_81:
F_97 ( & V_9 -> V_76 ) ;
V_77:
F_97 ( & V_9 -> V_49 ) ;
V_75:
F_98 () ;
V_71:
for ( V_11 = 0 ; V_11 < V_78 ; V_11 ++ )
F_99 ( V_9 -> V_79 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_74 ; V_11 ++ )
F_79 ( V_9 , V_9 -> V_65 [ V_11 ] ) ;
F_100 ( V_9 ) ;
return F_83 ( V_28 ) ;
}
void * F_74 ( unsigned long V_90 )
{
if ( V_90 > V_91 )
return F_101 ( V_90 ) ;
else
return F_90 ( V_90 , V_35 ) ;
}
static void F_102 ( struct V_9 * V_9 )
{
struct V_92 * V_93 , * V_94 ;
F_103 (node, tmp, &kvm->devices) {
struct V_95 * V_96 =
F_104 ( V_93 , struct V_95 , V_97 ) ;
F_105 ( V_93 ) ;
V_96 -> V_57 -> V_98 ( V_96 ) ;
}
}
static void F_106 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_44 * V_45 = V_9 -> V_45 ;
F_107 ( V_9 ) ;
F_52 ( & V_88 ) ;
F_105 ( & V_9 -> V_89 ) ;
F_54 ( & V_88 ) ;
F_108 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_78 ; V_11 ++ )
F_109 ( V_9 -> V_79 [ V_11 ] ) ;
F_110 ( V_9 ) ;
#if F_111 ( V_99 ) && F_111 ( V_100 )
F_112 ( & V_9 -> V_42 , V_9 -> V_45 ) ;
#else
F_70 ( V_9 ) ;
#endif
F_113 ( V_9 ) ;
F_102 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_74 ; V_11 ++ )
F_79 ( V_9 , V_9 -> V_65 [ V_11 ] ) ;
F_97 ( & V_9 -> V_76 ) ;
F_97 ( & V_9 -> V_49 ) ;
F_100 ( V_9 ) ;
F_114 () ;
F_98 () ;
F_115 ( V_45 ) ;
}
void F_116 ( struct V_9 * V_9 )
{
F_92 ( & V_9 -> V_86 ) ;
}
void F_117 ( struct V_9 * V_9 )
{
if ( F_118 ( & V_9 -> V_86 ) )
F_106 ( V_9 ) ;
}
static int F_119 ( struct V_101 * V_101 , struct V_102 * V_103 )
{
struct V_9 * V_9 = V_103 -> V_104 ;
F_120 ( V_9 ) ;
F_117 ( V_9 ) ;
return 0 ;
}
static int F_121 ( struct V_66 * V_67 )
{
unsigned long V_105 = 2 * F_122 ( V_67 ) ;
V_67 -> V_68 = F_74 ( V_105 ) ;
if ( ! V_67 -> V_68 )
return - V_37 ;
return 0 ;
}
static void F_123 ( struct V_60 * V_61 ,
struct V_66 * V_106 )
{
int V_26 = V_106 -> V_26 ;
int V_11 = V_61 -> V_64 [ V_26 ] ;
struct V_66 * V_107 = V_61 -> V_65 ;
F_124 ( V_107 [ V_11 ] . V_26 != V_26 ) ;
if ( ! V_106 -> V_70 ) {
F_124 ( ! V_107 [ V_11 ] . V_70 ) ;
if ( V_107 [ V_11 ] . V_70 )
V_61 -> V_108 -- ;
} else {
if ( ! V_107 [ V_11 ] . V_70 )
V_61 -> V_108 ++ ;
}
while ( V_11 < V_63 - 1 &&
V_106 -> V_109 <= V_107 [ V_11 + 1 ] . V_109 ) {
if ( ! V_107 [ V_11 + 1 ] . V_70 )
break;
V_107 [ V_11 ] = V_107 [ V_11 + 1 ] ;
V_61 -> V_64 [ V_107 [ V_11 ] . V_26 ] = V_11 ;
V_11 ++ ;
}
if ( V_106 -> V_70 ) {
while ( V_11 > 0 &&
V_106 -> V_109 >= V_107 [ V_11 - 1 ] . V_109 ) {
V_107 [ V_11 ] = V_107 [ V_11 - 1 ] ;
V_61 -> V_64 [ V_107 [ V_11 ] . V_26 ] = V_11 ;
V_11 -- ;
}
} else
F_125 ( V_11 != V_61 -> V_108 ) ;
V_107 [ V_11 ] = * V_106 ;
V_61 -> V_64 [ V_107 [ V_11 ] . V_26 ] = V_11 ;
}
static int F_126 ( const struct V_110 * V_111 )
{
T_4 V_112 = V_113 ;
#ifdef F_127
V_112 |= V_114 ;
#endif
if ( V_111 -> V_115 & ~ V_112 )
return - V_116 ;
return 0 ;
}
static struct V_60 * F_128 ( struct V_9 * V_9 ,
int V_117 , struct V_60 * V_61 )
{
struct V_60 * V_118 = F_129 ( V_9 , V_117 ) ;
F_124 ( V_118 -> V_62 & 1 ) ;
V_61 -> V_62 = V_118 -> V_62 + 1 ;
F_130 ( V_9 -> V_65 [ V_117 ] , V_61 ) ;
F_131 ( & V_9 -> V_49 ) ;
V_61 -> V_62 ++ ;
F_132 ( V_9 , V_61 ) ;
return V_118 ;
}
int F_133 ( struct V_9 * V_9 ,
const struct V_110 * V_111 )
{
int V_28 ;
T_5 V_109 ;
unsigned long V_70 ;
struct V_66 * V_119 ;
struct V_66 V_120 , V_106 ;
struct V_60 * V_61 = NULL , * V_118 ;
int V_117 , V_26 ;
enum V_121 V_122 ;
V_28 = F_126 ( V_111 ) ;
if ( V_28 )
goto V_123;
V_28 = - V_116 ;
V_117 = V_111 -> V_119 >> 16 ;
V_26 = ( V_124 ) V_111 -> V_119 ;
if ( V_111 -> V_125 & ( V_91 - 1 ) )
goto V_123;
if ( V_111 -> V_126 & ( V_91 - 1 ) )
goto V_123;
if ( ( V_26 < V_127 ) &&
( ( V_111 -> V_128 & ( V_91 - 1 ) ) ||
! F_134 ( V_129 ,
( void V_130 * ) ( unsigned long ) V_111 -> V_128 ,
V_111 -> V_125 ) ) )
goto V_123;
if ( V_117 >= V_74 || V_26 >= V_63 )
goto V_123;
if ( V_111 -> V_126 + V_111 -> V_125 < V_111 -> V_126 )
goto V_123;
V_119 = F_135 ( F_129 ( V_9 , V_117 ) , V_26 ) ;
V_109 = V_111 -> V_126 >> V_131 ;
V_70 = V_111 -> V_125 >> V_131 ;
if ( V_70 > V_132 )
goto V_123;
V_106 = V_120 = * V_119 ;
V_106 . V_26 = V_26 ;
V_106 . V_109 = V_109 ;
V_106 . V_70 = V_70 ;
V_106 . V_115 = V_111 -> V_115 ;
if ( V_70 ) {
if ( ! V_120 . V_70 )
V_122 = V_133 ;
else {
if ( ( V_111 -> V_128 != V_120 . V_128 ) ||
( V_70 != V_120 . V_70 ) ||
( ( V_106 . V_115 ^ V_120 . V_115 ) & V_114 ) )
goto V_123;
if ( V_109 != V_120 . V_109 )
V_122 = V_134 ;
else if ( V_106 . V_115 != V_120 . V_115 )
V_122 = V_135 ;
else {
V_28 = 0 ;
goto V_123;
}
}
} else {
if ( ! V_120 . V_70 )
goto V_123;
V_122 = V_136 ;
V_106 . V_109 = 0 ;
V_106 . V_115 = 0 ;
}
if ( ( V_122 == V_133 ) || ( V_122 == V_134 ) ) {
V_28 = - V_137 ;
F_80 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_119 -> V_26 >= V_127 ) ||
( V_119 -> V_26 == V_26 ) )
continue;
if ( ! ( ( V_109 + V_70 <= V_119 -> V_109 ) ||
( V_109 >= V_119 -> V_109 + V_119 -> V_70 ) ) )
goto V_123;
}
}
if ( ! ( V_106 . V_115 & V_113 ) )
V_106 . V_68 = NULL ;
V_28 = - V_37 ;
if ( V_122 == V_133 ) {
V_106 . V_128 = V_111 -> V_128 ;
if ( F_136 ( V_9 , & V_106 , V_70 ) )
goto V_138;
}
if ( ( V_106 . V_115 & V_113 ) && ! V_106 . V_68 ) {
if ( F_121 ( & V_106 ) < 0 )
goto V_138;
}
V_61 = F_74 ( sizeof( struct V_60 ) ) ;
if ( ! V_61 )
goto V_138;
memcpy ( V_61 , F_129 ( V_9 , V_117 ) , sizeof( struct V_60 ) ) ;
if ( ( V_122 == V_136 ) || ( V_122 == V_134 ) ) {
V_119 = F_135 ( V_61 , V_26 ) ;
V_119 -> V_115 |= V_139 ;
V_118 = F_128 ( V_9 , V_117 , V_61 ) ;
F_137 ( V_9 , & V_120 ) ;
F_138 ( V_9 , V_119 ) ;
V_61 = V_118 ;
}
V_28 = F_139 ( V_9 , & V_106 , V_111 , V_122 ) ;
if ( V_28 )
goto V_140;
if ( V_122 == V_136 ) {
V_106 . V_68 = NULL ;
memset ( & V_106 . V_141 , 0 , sizeof( V_106 . V_141 ) ) ;
}
F_123 ( V_61 , & V_106 ) ;
V_118 = F_128 ( V_9 , V_117 , V_61 ) ;
F_140 ( V_9 , V_111 , & V_120 , & V_106 , V_122 ) ;
F_77 ( V_9 , & V_120 , & V_106 ) ;
F_76 ( V_118 ) ;
if ( ( V_122 == V_133 ) || ( V_122 == V_134 ) ) {
V_28 = F_141 ( V_9 , & V_106 ) ;
return V_28 ;
}
return 0 ;
V_140:
F_76 ( V_61 ) ;
V_138:
F_77 ( V_9 , & V_106 , & V_120 ) ;
V_123:
return V_28 ;
}
int F_142 ( struct V_9 * V_9 ,
const struct V_110 * V_111 )
{
int V_28 ;
F_143 ( & V_9 -> V_85 ) ;
V_28 = F_133 ( V_9 , V_111 ) ;
F_16 ( & V_9 -> V_85 ) ;
return V_28 ;
}
static int F_144 ( struct V_9 * V_9 ,
struct V_110 * V_111 )
{
if ( ( V_124 ) V_111 -> V_119 >= V_127 )
return - V_116 ;
return F_142 ( V_9 , V_111 ) ;
}
int F_145 ( struct V_9 * V_9 ,
struct V_142 * log , int * V_143 )
{
struct V_60 * V_61 ;
struct V_66 * V_67 ;
int V_28 , V_11 , V_117 , V_26 ;
unsigned long V_144 ;
unsigned long V_145 = 0 ;
V_28 = - V_116 ;
V_117 = log -> V_119 >> 16 ;
V_26 = ( V_124 ) log -> V_119 ;
if ( V_117 >= V_74 || V_26 >= V_127 )
goto V_123;
V_61 = F_129 ( V_9 , V_117 ) ;
V_67 = F_135 ( V_61 , V_26 ) ;
V_28 = - V_146 ;
if ( ! V_67 -> V_68 )
goto V_123;
V_144 = F_122 ( V_67 ) ;
for ( V_11 = 0 ; ! V_145 && V_11 < V_144 / sizeof( long ) ; ++ V_11 )
V_145 = V_67 -> V_68 [ V_11 ] ;
V_28 = - V_147 ;
if ( F_146 ( log -> V_68 , V_67 -> V_68 , V_144 ) )
goto V_123;
if ( V_145 )
* V_143 = 1 ;
V_28 = 0 ;
V_123:
return V_28 ;
}
int F_147 ( struct V_9 * V_9 ,
struct V_142 * log , bool * V_143 )
{
struct V_60 * V_61 ;
struct V_66 * V_67 ;
int V_28 , V_11 , V_117 , V_26 ;
unsigned long V_144 ;
unsigned long * V_68 ;
unsigned long * V_148 ;
V_28 = - V_116 ;
V_117 = log -> V_119 >> 16 ;
V_26 = ( V_124 ) log -> V_119 ;
if ( V_117 >= V_74 || V_26 >= V_127 )
goto V_123;
V_61 = F_129 ( V_9 , V_117 ) ;
V_67 = F_135 ( V_61 , V_26 ) ;
V_68 = V_67 -> V_68 ;
V_28 = - V_146 ;
if ( ! V_68 )
goto V_123;
V_144 = F_122 ( V_67 ) ;
V_148 = V_68 + V_144 / sizeof( long ) ;
memset ( V_148 , 0 , V_144 ) ;
F_52 ( & V_9 -> V_50 ) ;
* V_143 = false ;
for ( V_11 = 0 ; V_11 < V_144 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_149 ;
T_5 V_150 ;
if ( ! V_68 [ V_11 ] )
continue;
* V_143 = true ;
V_149 = F_148 ( & V_68 [ V_11 ] , 0 ) ;
V_148 [ V_11 ] = V_149 ;
if ( V_149 ) {
V_150 = V_11 * V_151 ;
F_149 ( V_9 , V_67 ,
V_150 , V_149 ) ;
}
}
F_54 ( & V_9 -> V_50 ) ;
V_28 = - V_147 ;
if ( F_146 ( log -> V_68 , V_148 , V_144 ) )
goto V_123;
V_28 = 0 ;
V_123:
return V_28 ;
}
bool F_150 ( void )
{
return V_152 ;
}
void F_151 ( void )
{
V_152 = false ;
}
struct V_66 * F_152 ( struct V_9 * V_9 , T_5 V_153 )
{
return F_153 ( V_60 ( V_9 ) , V_153 ) ;
}
struct V_66 * F_154 ( struct V_2 * V_3 , T_5 V_153 )
{
return F_153 ( F_155 ( V_3 ) , V_153 ) ;
}
int F_156 ( struct V_9 * V_9 , T_5 V_153 )
{
struct V_66 * V_67 = F_152 ( V_9 , V_153 ) ;
if ( ! V_67 || V_67 -> V_26 >= V_127 ||
V_67 -> V_115 & V_139 )
return 0 ;
return 1 ;
}
unsigned long F_157 ( struct V_9 * V_9 , T_5 V_153 )
{
struct V_154 * V_155 ;
unsigned long V_156 , V_90 ;
V_90 = V_91 ;
V_156 = F_158 ( V_9 , V_153 ) ;
if ( F_159 ( V_156 ) )
return V_91 ;
F_160 ( & V_59 -> V_45 -> V_157 ) ;
V_155 = F_161 ( V_59 -> V_45 , V_156 ) ;
if ( ! V_155 )
goto V_123;
V_90 = F_162 ( V_155 ) ;
V_123:
F_163 ( & V_59 -> V_45 -> V_157 ) ;
return V_90 ;
}
static bool F_164 ( struct V_66 * V_119 )
{
return V_119 -> V_115 & V_114 ;
}
static unsigned long F_165 ( struct V_66 * V_119 , T_5 V_153 ,
T_5 * V_158 , bool V_159 )
{
if ( ! V_119 || V_119 -> V_115 & V_139 )
return V_160 ;
if ( F_164 ( V_119 ) && V_159 )
return V_161 ;
if ( V_158 )
* V_158 = V_119 -> V_70 - ( V_153 - V_119 -> V_109 ) ;
return F_166 ( V_119 , V_153 ) ;
}
static unsigned long F_167 ( struct V_66 * V_119 , T_5 V_153 ,
T_5 * V_158 )
{
return F_165 ( V_119 , V_153 , V_158 , true ) ;
}
unsigned long F_168 ( struct V_66 * V_119 ,
T_5 V_153 )
{
return F_167 ( V_119 , V_153 , NULL ) ;
}
unsigned long F_158 ( struct V_9 * V_9 , T_5 V_153 )
{
return F_167 ( F_152 ( V_9 , V_153 ) , V_153 , NULL ) ;
}
unsigned long F_169 ( struct V_2 * V_3 , T_5 V_153 )
{
return F_167 ( F_154 ( V_3 , V_153 ) , V_153 , NULL ) ;
}
unsigned long F_170 ( struct V_66 * V_119 ,
T_5 V_153 , bool * V_162 )
{
unsigned long V_163 = F_165 ( V_119 , V_153 , NULL , false ) ;
if ( ! F_159 ( V_163 ) && V_162 )
* V_162 = ! F_164 ( V_119 ) ;
return V_163 ;
}
unsigned long F_171 ( struct V_9 * V_9 , T_5 V_153 , bool * V_162 )
{
struct V_66 * V_119 = F_152 ( V_9 , V_153 ) ;
return F_170 ( V_119 , V_153 , V_162 ) ;
}
unsigned long F_172 ( struct V_2 * V_3 , T_5 V_153 , bool * V_162 )
{
struct V_66 * V_119 = F_154 ( V_3 , V_153 ) ;
return F_170 ( V_119 , V_153 , V_162 ) ;
}
static int F_173 ( struct V_164 * V_165 , struct V_44 * V_45 ,
unsigned long V_53 , int V_159 , struct V_27 * * V_27 )
{
int V_115 = V_166 | V_167 | V_168 | V_169 ;
if ( V_159 )
V_115 |= V_170 ;
return F_174 ( V_165 , V_45 , V_53 , 1 , V_115 , V_27 , NULL , NULL ) ;
}
static inline int F_175 ( unsigned long V_156 )
{
int V_171 , V_115 = V_166 | V_168 | V_170 ;
V_171 = F_174 ( V_59 , V_59 -> V_45 , V_156 , 1 ,
V_115 , NULL , NULL , NULL ) ;
return V_171 == - V_172 ;
}
static bool F_176 ( unsigned long V_156 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_162 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_70 ;
if ( ! ( V_174 || V_173 ) )
return false ;
if ( ! ( V_175 || V_162 ) )
return false ;
V_70 = F_177 ( V_156 , 1 , 1 , V_27 ) ;
if ( V_70 == 1 ) {
* V_1 = F_178 ( V_27 [ 0 ] ) ;
if ( V_162 )
* V_162 = true ;
return true ;
}
return false ;
}
static int F_179 ( unsigned long V_156 , bool * V_174 , bool V_175 ,
bool * V_162 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_70 = 0 ;
F_180 () ;
if ( V_162 )
* V_162 = V_175 ;
if ( V_174 ) {
F_160 ( & V_59 -> V_45 -> V_157 ) ;
V_70 = F_173 ( V_59 , V_59 -> V_45 ,
V_156 , V_175 , V_27 ) ;
F_163 ( & V_59 -> V_45 -> V_157 ) ;
} else
V_70 = F_181 ( V_59 , V_59 -> V_45 , V_156 , 1 ,
V_175 , 0 , V_27 ,
V_166 | V_168 ) ;
if ( V_70 != 1 )
return V_70 ;
if ( F_25 ( ! V_175 ) && V_162 ) {
struct V_27 * V_176 [ 1 ] ;
V_70 = F_177 ( V_156 , 1 , 1 , V_176 ) ;
if ( V_70 == 1 ) {
* V_162 = true ;
F_182 ( V_27 [ 0 ] ) ;
V_27 [ 0 ] = V_176 [ 0 ] ;
}
V_70 = 1 ;
}
* V_1 = F_178 ( V_27 [ 0 ] ) ;
return V_70 ;
}
static bool F_183 ( struct V_154 * V_155 , bool V_175 )
{
if ( F_25 ( ! ( V_155 -> V_177 & V_178 ) ) )
return false ;
if ( V_175 && ( F_25 ( ! ( V_155 -> V_177 & V_179 ) ) ) )
return false ;
return true ;
}
static T_1 F_184 ( unsigned long V_156 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_162 )
{
struct V_154 * V_155 ;
T_1 V_1 = 0 ;
int V_70 ;
F_63 ( V_173 && V_174 ) ;
if ( F_176 ( V_156 , V_173 , V_174 , V_175 , V_162 , & V_1 ) )
return V_1 ;
if ( V_173 )
return V_180 ;
V_70 = F_179 ( V_156 , V_174 , V_175 , V_162 , & V_1 ) ;
if ( V_70 == 1 )
return V_1 ;
F_160 ( & V_59 -> V_45 -> V_157 ) ;
if ( V_70 == - V_172 ||
( ! V_174 && F_175 ( V_156 ) ) ) {
V_1 = V_181 ;
goto exit;
}
V_155 = F_185 ( V_59 -> V_45 , V_156 , V_156 + 1 ) ;
if ( V_155 == NULL )
V_1 = V_180 ;
else if ( ( V_155 -> V_177 & V_182 ) ) {
V_1 = ( ( V_156 - V_155 -> V_183 ) >> V_131 ) +
V_155 -> V_184 ;
F_63 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_174 && F_183 ( V_155 , V_175 ) )
* V_174 = true ;
V_1 = V_180 ;
}
exit:
F_163 ( & V_59 -> V_45 -> V_157 ) ;
return V_1 ;
}
T_1 F_186 ( struct V_66 * V_119 , T_5 V_153 , bool V_173 ,
bool * V_174 , bool V_175 , bool * V_162 )
{
unsigned long V_156 = F_165 ( V_119 , V_153 , NULL , V_175 ) ;
if ( V_156 == V_161 )
return V_185 ;
if ( F_159 ( V_156 ) )
return V_186 ;
if ( V_162 && F_164 ( V_119 ) ) {
* V_162 = false ;
V_162 = NULL ;
}
return F_184 ( V_156 , V_173 , V_174 , V_175 ,
V_162 ) ;
}
T_1 F_187 ( struct V_9 * V_9 , T_5 V_153 , bool V_175 ,
bool * V_162 )
{
return F_186 ( F_152 ( V_9 , V_153 ) , V_153 , false , NULL ,
V_175 , V_162 ) ;
}
T_1 F_188 ( struct V_66 * V_119 , T_5 V_153 )
{
return F_186 ( V_119 , V_153 , false , NULL , true , NULL ) ;
}
T_1 F_189 ( struct V_66 * V_119 , T_5 V_153 )
{
return F_186 ( V_119 , V_153 , true , NULL , true , NULL ) ;
}
T_1 F_190 ( struct V_9 * V_9 , T_5 V_153 )
{
return F_189 ( F_152 ( V_9 , V_153 ) , V_153 ) ;
}
T_1 F_191 ( struct V_2 * V_3 , T_5 V_153 )
{
return F_189 ( F_154 ( V_3 , V_153 ) , V_153 ) ;
}
T_1 F_192 ( struct V_9 * V_9 , T_5 V_153 )
{
return F_188 ( F_152 ( V_9 , V_153 ) , V_153 ) ;
}
T_1 F_193 ( struct V_2 * V_3 , T_5 V_153 )
{
return F_188 ( F_154 ( V_3 , V_153 ) , V_153 ) ;
}
int F_194 ( struct V_66 * V_119 , T_5 V_153 ,
struct V_27 * * V_187 , int V_158 )
{
unsigned long V_156 ;
T_5 V_188 ;
V_156 = F_167 ( V_119 , V_153 , & V_188 ) ;
if ( F_159 ( V_156 ) )
return - 1 ;
if ( V_188 < V_158 )
return 0 ;
return F_177 ( V_156 , V_158 , 1 , V_187 ) ;
}
static struct V_27 * F_195 ( T_1 V_1 )
{
if ( F_196 ( V_1 ) )
return V_189 ;
if ( F_1 ( V_1 ) ) {
F_124 ( 1 ) ;
return V_189 ;
}
return F_4 ( V_1 ) ;
}
struct V_27 * F_197 ( struct V_9 * V_9 , T_5 V_153 )
{
T_1 V_1 ;
V_1 = F_192 ( V_9 , V_153 ) ;
return F_195 ( V_1 ) ;
}
struct V_27 * F_198 ( struct V_2 * V_3 , T_5 V_153 )
{
T_1 V_1 ;
V_1 = F_193 ( V_3 , V_153 ) ;
return F_195 ( V_1 ) ;
}
void F_199 ( struct V_27 * V_27 )
{
F_124 ( F_200 ( V_27 ) ) ;
F_201 ( F_178 ( V_27 ) ) ;
}
void F_201 ( T_1 V_1 )
{
if ( ! F_196 ( V_1 ) && ! F_1 ( V_1 ) )
F_182 ( F_4 ( V_1 ) ) ;
}
void F_202 ( struct V_27 * V_27 )
{
F_124 ( F_200 ( V_27 ) ) ;
F_203 ( F_178 ( V_27 ) ) ;
}
static void F_203 ( T_1 V_1 )
{
F_204 ( V_1 ) ;
F_201 ( V_1 ) ;
}
void F_204 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_27 * V_27 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_27 ) )
F_205 ( V_27 ) ;
}
}
void F_206 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_207 ( F_4 ( V_1 ) ) ;
}
void F_208 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_209 ( F_4 ( V_1 ) ) ;
}
static int F_210 ( unsigned long V_190 , int V_150 )
{
if ( V_190 > V_91 - V_150 )
return V_91 - V_150 ;
else
return V_190 ;
}
static int F_211 ( struct V_66 * V_119 , T_5 V_153 ,
void * V_191 , int V_150 , int V_190 )
{
int V_28 ;
unsigned long V_156 ;
V_156 = F_170 ( V_119 , V_153 , NULL ) ;
if ( F_159 ( V_156 ) )
return - V_147 ;
V_28 = F_212 ( V_191 , ( void V_130 * ) V_156 + V_150 , V_190 ) ;
if ( V_28 )
return - V_147 ;
return 0 ;
}
int F_213 ( struct V_9 * V_9 , T_5 V_153 , void * V_191 , int V_150 ,
int V_190 )
{
struct V_66 * V_119 = F_152 ( V_9 , V_153 ) ;
return F_211 ( V_119 , V_153 , V_191 , V_150 , V_190 ) ;
}
int F_214 ( struct V_2 * V_3 , T_5 V_153 , void * V_191 ,
int V_150 , int V_190 )
{
struct V_66 * V_119 = F_154 ( V_3 , V_153 ) ;
return F_211 ( V_119 , V_153 , V_191 , V_150 , V_190 ) ;
}
int F_215 ( struct V_9 * V_9 , T_6 V_192 , void * V_191 , unsigned long V_190 )
{
T_5 V_153 = V_192 >> V_131 ;
int V_193 ;
int V_150 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_210 ( V_190 , V_150 ) ) != 0 ) {
V_194 = F_213 ( V_9 , V_153 , V_191 , V_150 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_150 = 0 ;
V_190 -= V_193 ;
V_191 += V_193 ;
++ V_153 ;
}
return 0 ;
}
int F_217 ( struct V_2 * V_3 , T_6 V_192 , void * V_191 , unsigned long V_190 )
{
T_5 V_153 = V_192 >> V_131 ;
int V_193 ;
int V_150 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_210 ( V_190 , V_150 ) ) != 0 ) {
V_194 = F_214 ( V_3 , V_153 , V_191 , V_150 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_150 = 0 ;
V_190 -= V_193 ;
V_191 += V_193 ;
++ V_153 ;
}
return 0 ;
}
static int F_218 ( struct V_66 * V_119 , T_5 V_153 ,
void * V_191 , int V_150 , unsigned long V_190 )
{
int V_28 ;
unsigned long V_156 ;
V_156 = F_170 ( V_119 , V_153 , NULL ) ;
if ( F_159 ( V_156 ) )
return - V_147 ;
F_219 () ;
V_28 = F_220 ( V_191 , ( void V_130 * ) V_156 + V_150 , V_190 ) ;
F_221 () ;
if ( V_28 )
return - V_147 ;
return 0 ;
}
int F_222 ( struct V_9 * V_9 , T_6 V_192 , void * V_191 ,
unsigned long V_190 )
{
T_5 V_153 = V_192 >> V_131 ;
struct V_66 * V_119 = F_152 ( V_9 , V_153 ) ;
int V_150 = F_216 ( V_192 ) ;
return F_218 ( V_119 , V_153 , V_191 , V_150 , V_190 ) ;
}
int F_223 ( struct V_2 * V_3 , T_6 V_192 ,
void * V_191 , unsigned long V_190 )
{
T_5 V_153 = V_192 >> V_131 ;
struct V_66 * V_119 = F_154 ( V_3 , V_153 ) ;
int V_150 = F_216 ( V_192 ) ;
return F_218 ( V_119 , V_153 , V_191 , V_150 , V_190 ) ;
}
static int F_224 ( struct V_66 * V_67 , T_5 V_153 ,
const void * V_191 , int V_150 , int V_190 )
{
int V_28 ;
unsigned long V_156 ;
V_156 = F_168 ( V_67 , V_153 ) ;
if ( F_159 ( V_156 ) )
return - V_147 ;
V_28 = F_225 ( ( void V_130 * ) V_156 + V_150 , V_191 , V_190 ) ;
if ( V_28 )
return - V_147 ;
F_226 ( V_67 , V_153 ) ;
return 0 ;
}
int F_227 ( struct V_9 * V_9 , T_5 V_153 ,
const void * V_191 , int V_150 , int V_190 )
{
struct V_66 * V_119 = F_152 ( V_9 , V_153 ) ;
return F_224 ( V_119 , V_153 , V_191 , V_150 , V_190 ) ;
}
int F_228 ( struct V_2 * V_3 , T_5 V_153 ,
const void * V_191 , int V_150 , int V_190 )
{
struct V_66 * V_119 = F_154 ( V_3 , V_153 ) ;
return F_224 ( V_119 , V_153 , V_191 , V_150 , V_190 ) ;
}
int F_229 ( struct V_9 * V_9 , T_6 V_192 , const void * V_191 ,
unsigned long V_190 )
{
T_5 V_153 = V_192 >> V_131 ;
int V_193 ;
int V_150 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_210 ( V_190 , V_150 ) ) != 0 ) {
V_194 = F_227 ( V_9 , V_153 , V_191 , V_150 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_150 = 0 ;
V_190 -= V_193 ;
V_191 += V_193 ;
++ V_153 ;
}
return 0 ;
}
int F_230 ( struct V_2 * V_3 , T_6 V_192 , const void * V_191 ,
unsigned long V_190 )
{
T_5 V_153 = V_192 >> V_131 ;
int V_193 ;
int V_150 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_210 ( V_190 , V_150 ) ) != 0 ) {
V_194 = F_228 ( V_3 , V_153 , V_191 , V_150 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_150 = 0 ;
V_190 -= V_193 ;
V_191 += V_193 ;
++ V_153 ;
}
return 0 ;
}
int F_231 ( struct V_9 * V_9 , struct V_195 * V_196 ,
T_6 V_192 , unsigned long V_190 )
{
struct V_60 * V_61 = V_60 ( V_9 ) ;
int V_150 = F_216 ( V_192 ) ;
T_5 V_197 = V_192 >> V_131 ;
T_5 V_198 = ( V_192 + V_190 - 1 ) >> V_131 ;
T_5 V_199 = V_198 - V_197 + 1 ;
T_5 V_200 ;
V_196 -> V_192 = V_192 ;
V_196 -> V_62 = V_61 -> V_62 ;
V_196 -> V_190 = V_190 ;
V_196 -> V_67 = F_152 ( V_9 , V_197 ) ;
V_196 -> V_163 = F_167 ( V_196 -> V_67 , V_197 , NULL ) ;
if ( ! F_159 ( V_196 -> V_163 ) && V_199 <= 1 ) {
V_196 -> V_163 += V_150 ;
} else {
while ( V_197 <= V_198 ) {
V_196 -> V_67 = F_152 ( V_9 , V_197 ) ;
V_196 -> V_163 = F_167 ( V_196 -> V_67 , V_197 ,
& V_200 ) ;
if ( F_159 ( V_196 -> V_163 ) )
return - V_147 ;
V_197 += V_200 ;
}
V_196 -> V_67 = NULL ;
}
return 0 ;
}
int F_232 ( struct V_9 * V_9 , struct V_195 * V_196 ,
void * V_191 , unsigned long V_190 )
{
struct V_60 * V_61 = V_60 ( V_9 ) ;
int V_28 ;
F_63 ( V_190 > V_196 -> V_190 ) ;
if ( V_61 -> V_62 != V_196 -> V_62 )
F_231 ( V_9 , V_196 , V_196 -> V_192 , V_196 -> V_190 ) ;
if ( F_25 ( ! V_196 -> V_67 ) )
return F_229 ( V_9 , V_196 -> V_192 , V_191 , V_190 ) ;
if ( F_159 ( V_196 -> V_163 ) )
return - V_147 ;
V_28 = F_225 ( ( void V_130 * ) V_196 -> V_163 , V_191 , V_190 ) ;
if ( V_28 )
return - V_147 ;
F_226 ( V_196 -> V_67 , V_196 -> V_192 >> V_131 ) ;
return 0 ;
}
int F_233 ( struct V_9 * V_9 , struct V_195 * V_196 ,
void * V_191 , unsigned long V_190 )
{
struct V_60 * V_61 = V_60 ( V_9 ) ;
int V_28 ;
F_63 ( V_190 > V_196 -> V_190 ) ;
if ( V_61 -> V_62 != V_196 -> V_62 )
F_231 ( V_9 , V_196 , V_196 -> V_192 , V_196 -> V_190 ) ;
if ( F_25 ( ! V_196 -> V_67 ) )
return F_215 ( V_9 , V_196 -> V_192 , V_191 , V_190 ) ;
if ( F_159 ( V_196 -> V_163 ) )
return - V_147 ;
V_28 = F_212 ( V_191 , ( void V_130 * ) V_196 -> V_163 , V_190 ) ;
if ( V_28 )
return - V_147 ;
return 0 ;
}
int F_234 ( struct V_9 * V_9 , T_5 V_153 , int V_150 , int V_190 )
{
const void * V_201 = ( const void * ) F_235 ( F_236 ( F_237 ( 0 ) ) ) ;
return F_227 ( V_9 , V_153 , V_201 , V_150 , V_190 ) ;
}
int F_238 ( struct V_9 * V_9 , T_6 V_192 , unsigned long V_190 )
{
T_5 V_153 = V_192 >> V_131 ;
int V_193 ;
int V_150 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_210 ( V_190 , V_150 ) ) != 0 ) {
V_194 = F_234 ( V_9 , V_153 , V_150 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_150 = 0 ;
V_190 -= V_193 ;
++ V_153 ;
}
return 0 ;
}
static void F_226 ( struct V_66 * V_67 ,
T_5 V_153 )
{
if ( V_67 && V_67 -> V_68 ) {
unsigned long V_202 = V_153 - V_67 -> V_109 ;
F_239 ( V_202 , V_67 -> V_68 ) ;
}
}
void F_240 ( struct V_9 * V_9 , T_5 V_153 )
{
struct V_66 * V_67 ;
V_67 = F_152 ( V_9 , V_153 ) ;
F_226 ( V_67 , V_153 ) ;
}
void F_241 ( struct V_2 * V_3 , T_5 V_153 )
{
struct V_66 * V_67 ;
V_67 = F_154 ( V_3 , V_153 ) ;
F_226 ( V_67 , V_153 ) ;
}
static void F_242 ( struct V_2 * V_3 )
{
int V_120 , V_203 ;
V_120 = V_203 = V_3 -> V_31 ;
if ( V_203 == 0 && V_204 )
V_203 = 10000 ;
else
V_203 *= V_204 ;
V_3 -> V_31 = V_203 ;
F_243 ( V_3 -> V_29 , V_203 , V_120 ) ;
}
static void F_244 ( struct V_2 * V_3 )
{
int V_120 , V_203 ;
V_120 = V_203 = V_3 -> V_31 ;
if ( V_205 == 0 )
V_203 = 0 ;
else
V_203 /= V_205 ;
V_3 -> V_31 = V_203 ;
F_245 ( V_3 -> V_29 , V_203 , V_120 ) ;
}
static int F_246 ( struct V_2 * V_3 )
{
if ( F_247 ( V_3 ) ) {
F_21 ( V_206 , V_3 ) ;
return - V_6 ;
}
if ( F_248 ( V_3 ) )
return - V_6 ;
if ( F_249 ( V_59 ) )
return - V_6 ;
return 0 ;
}
void F_250 ( struct V_2 * V_3 )
{
T_7 V_53 , V_207 ;
F_251 ( V_208 ) ;
bool V_209 = false ;
T_8 V_210 ;
V_53 = V_207 = F_252 () ;
if ( V_3 -> V_31 ) {
T_7 V_211 = F_253 ( F_252 () , V_3 -> V_31 ) ;
++ V_3 -> V_21 . V_212 ;
do {
if ( F_246 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_213 ;
goto V_123;
}
V_207 = F_252 () ;
} while ( F_254 () && F_255 ( V_207 , V_211 ) );
}
F_256 ( V_3 ) ;
for (; ; ) {
F_257 ( & V_3 -> V_32 , & V_208 , V_214 ) ;
if ( F_246 ( V_3 ) < 0 )
break;
V_209 = true ;
F_258 () ;
}
F_259 ( & V_3 -> V_32 , & V_208 ) ;
V_207 = F_252 () ;
F_260 ( V_3 ) ;
V_123:
V_210 = F_261 ( V_207 ) - F_261 ( V_53 ) ;
if ( V_31 ) {
if ( V_210 <= V_3 -> V_31 )
;
else if ( V_3 -> V_31 && V_210 > V_31 )
F_244 ( V_3 ) ;
else if ( V_3 -> V_31 < V_31 &&
V_210 < V_31 )
F_242 ( V_3 ) ;
} else
V_3 -> V_31 = 0 ;
F_262 ( V_210 , V_209 ) ;
}
void F_263 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
T_9 * V_215 ;
V_215 = F_264 ( V_3 ) ;
if ( F_265 ( V_215 ) ) {
F_266 ( V_215 ) ;
++ V_3 -> V_21 . V_216 ;
}
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_217 && F_267 ( V_4 ) )
if ( F_268 ( V_3 ) )
F_269 ( V_4 ) ;
F_10 () ;
}
int F_270 ( struct V_2 * V_218 )
{
struct V_30 * V_30 ;
struct V_164 * V_219 = NULL ;
int V_194 = 0 ;
F_271 () ;
V_30 = F_272 ( V_218 -> V_30 ) ;
if ( V_30 )
V_219 = F_273 ( V_30 , V_220 ) ;
F_274 () ;
if ( ! V_219 )
return V_194 ;
V_194 = F_275 ( V_219 , 1 ) ;
F_276 ( V_219 ) ;
return V_194 ;
}
static bool F_277 ( struct V_2 * V_3 )
{
#ifdef F_278
bool V_221 ;
V_221 = ! V_3 -> V_222 . V_223 ||
V_3 -> V_222 . V_224 ;
if ( V_3 -> V_222 . V_223 )
F_42 ( V_3 , ! V_3 -> V_222 . V_224 ) ;
return V_221 ;
#else
return true ;
#endif
}
void F_279 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_225 = V_12 -> V_9 -> V_225 ;
int V_226 = 0 ;
int V_227 = 3 ;
int V_228 ;
int V_11 ;
F_41 ( V_12 , true ) ;
for ( V_228 = 0 ; V_228 < 2 && ! V_226 && V_227 ; V_228 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_228 && V_11 <= V_225 ) {
V_11 = V_225 ;
continue;
} else if ( V_228 && V_11 > V_225 )
break;
if ( ! F_280 ( V_3 -> V_40 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_265 ( & V_3 -> V_32 ) && ! F_247 ( V_3 ) )
continue;
if ( ! F_277 ( V_3 ) )
continue;
V_226 = F_270 ( V_3 ) ;
if ( V_226 > 0 ) {
V_9 -> V_225 = V_11 ;
break;
} else if ( V_226 < 0 ) {
V_227 -- ;
if ( ! V_227 )
break;
}
}
}
F_41 ( V_12 , false ) ;
F_42 ( V_12 , false ) ;
}
static int F_281 ( struct V_154 * V_155 , struct V_229 * V_230 )
{
struct V_2 * V_3 = V_155 -> V_231 -> V_104 ;
struct V_27 * V_27 ;
if ( V_230 -> V_232 == 0 )
V_27 = F_282 ( V_3 -> V_39 ) ;
#ifdef F_283
else if ( V_230 -> V_232 == V_233 )
V_27 = F_282 ( V_3 -> V_141 . V_234 ) ;
#endif
#ifdef F_284
else if ( V_230 -> V_232 == F_284 )
V_27 = F_282 ( V_3 -> V_9 -> V_235 ) ;
#endif
else
return F_285 ( V_3 , V_230 ) ;
F_209 ( V_27 ) ;
V_230 -> V_27 = V_27 ;
return 0 ;
}
static int F_286 ( struct V_102 * V_102 , struct V_154 * V_155 )
{
V_155 -> V_236 = & V_237 ;
return 0 ;
}
static int F_287 ( struct V_101 * V_101 , struct V_102 * V_103 )
{
struct V_2 * V_3 = V_103 -> V_104 ;
F_117 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_288 ( struct V_2 * V_3 )
{
return F_289 ( L_1 , & V_238 , V_3 , V_239 | V_240 ) ;
}
static int F_290 ( struct V_9 * V_9 , T_4 V_26 )
{
int V_28 ;
struct V_2 * V_3 , * V_241 ;
if ( V_26 >= V_242 )
return - V_116 ;
V_3 = F_291 ( V_9 , V_26 ) ;
if ( F_292 ( V_3 ) )
return F_293 ( V_3 ) ;
F_294 ( & V_3 -> V_7 , & V_243 ) ;
V_28 = F_295 ( V_3 ) ;
if ( V_28 )
goto V_244;
F_143 ( & V_9 -> V_83 ) ;
if ( ! F_296 ( V_3 ) ) {
V_28 = - V_116 ;
goto V_245;
}
if ( F_297 ( & V_9 -> V_246 ) == V_242 ) {
V_28 = - V_116 ;
goto V_245;
}
F_20 (r, v, kvm)
if ( V_241 -> V_29 == V_26 ) {
V_28 = - V_137 ;
goto V_245;
}
F_63 ( V_9 -> V_247 [ F_297 ( & V_9 -> V_246 ) ] ) ;
F_116 ( V_9 ) ;
V_28 = F_288 ( V_3 ) ;
if ( V_28 < 0 ) {
F_117 ( V_9 ) ;
goto V_245;
}
V_9 -> V_247 [ F_297 ( & V_9 -> V_246 ) ] = V_3 ;
F_62 () ;
F_92 ( & V_9 -> V_246 ) ;
F_16 ( & V_9 -> V_83 ) ;
F_298 ( V_3 ) ;
return V_28 ;
V_245:
F_16 ( & V_9 -> V_83 ) ;
V_244:
F_299 ( V_3 ) ;
return V_28 ;
}
static int F_300 ( struct V_2 * V_3 , T_10 * V_248 )
{
if ( V_248 ) {
F_301 ( V_248 , F_302 ( V_249 ) | F_302 ( V_250 ) ) ;
V_3 -> V_251 = 1 ;
V_3 -> V_248 = * V_248 ;
} else
V_3 -> V_251 = 0 ;
return 0 ;
}
static long F_303 ( struct V_102 * V_103 ,
unsigned int V_252 , unsigned long V_253 )
{
struct V_2 * V_3 = V_103 -> V_104 ;
void V_130 * V_254 = ( void V_130 * ) V_253 ;
int V_28 ;
struct V_255 * V_256 = NULL ;
struct V_257 * V_257 = NULL ;
if ( V_3 -> V_9 -> V_45 != V_59 -> V_45 )
return - V_258 ;
if ( F_25 ( F_304 ( V_252 ) != V_259 ) )
return - V_116 ;
#if F_111 ( V_260 ) || F_111 ( V_261 ) || F_111 ( V_262 )
if ( V_252 == V_263 || V_252 == V_264 || V_252 == V_265 )
return F_305 ( V_103 , V_252 , V_253 ) ;
#endif
V_28 = F_5 ( V_3 ) ;
if ( V_28 )
return V_28 ;
switch ( V_252 ) {
case V_266 :
V_28 = - V_116 ;
if ( V_253 )
goto V_123;
if ( F_25 ( V_3 -> V_30 != V_59 -> V_267 [ V_220 ] . V_30 ) ) {
struct V_30 * V_268 = V_3 -> V_30 ;
struct V_30 * V_269 = F_306 ( V_59 , V_220 ) ;
F_130 ( V_3 -> V_30 , V_269 ) ;
if ( V_268 )
F_307 () ;
F_46 ( V_268 ) ;
}
V_28 = F_308 ( V_3 , V_3 -> V_39 ) ;
F_309 ( V_3 -> V_39 -> V_270 , V_28 ) ;
break;
case V_271 : {
struct V_272 * V_272 ;
V_28 = - V_37 ;
V_272 = F_90 ( sizeof( struct V_272 ) , V_35 ) ;
if ( ! V_272 )
goto V_123;
V_28 = F_310 ( V_3 , V_272 ) ;
if ( V_28 )
goto V_273;
V_28 = - V_147 ;
if ( F_146 ( V_254 , V_272 , sizeof( struct V_272 ) ) )
goto V_273;
V_28 = 0 ;
V_273:
F_99 ( V_272 ) ;
break;
}
case V_274 : {
struct V_272 * V_272 ;
V_28 = - V_37 ;
V_272 = F_311 ( V_254 , sizeof( * V_272 ) ) ;
if ( F_292 ( V_272 ) ) {
V_28 = F_293 ( V_272 ) ;
goto V_123;
}
V_28 = F_312 ( V_3 , V_272 ) ;
F_99 ( V_272 ) ;
break;
}
case V_275 : {
V_257 = F_90 ( sizeof( struct V_257 ) , V_35 ) ;
V_28 = - V_37 ;
if ( ! V_257 )
goto V_123;
V_28 = F_313 ( V_3 , V_257 ) ;
if ( V_28 )
goto V_123;
V_28 = - V_147 ;
if ( F_146 ( V_254 , V_257 , sizeof( struct V_257 ) ) )
goto V_123;
V_28 = 0 ;
break;
}
case V_276 : {
V_257 = F_311 ( V_254 , sizeof( * V_257 ) ) ;
if ( F_292 ( V_257 ) ) {
V_28 = F_293 ( V_257 ) ;
V_257 = NULL ;
goto V_123;
}
V_28 = F_314 ( V_3 , V_257 ) ;
break;
}
case V_277 : {
struct V_278 V_279 ;
V_28 = F_315 ( V_3 , & V_279 ) ;
if ( V_28 )
goto V_123;
V_28 = - V_147 ;
if ( F_146 ( V_254 , & V_279 , sizeof( V_279 ) ) )
goto V_123;
V_28 = 0 ;
break;
}
case V_280 : {
struct V_278 V_279 ;
V_28 = - V_147 ;
if ( F_316 ( & V_279 , V_254 , sizeof( V_279 ) ) )
goto V_123;
V_28 = F_317 ( V_3 , & V_279 ) ;
break;
}
case V_281 : {
struct V_282 V_283 ;
V_28 = - V_147 ;
if ( F_316 ( & V_283 , V_254 , sizeof( V_283 ) ) )
goto V_123;
V_28 = F_318 ( V_3 , & V_283 ) ;
if ( V_28 )
goto V_123;
V_28 = - V_147 ;
if ( F_146 ( V_254 , & V_283 , sizeof( V_283 ) ) )
goto V_123;
V_28 = 0 ;
break;
}
case V_284 : {
struct V_285 V_286 ;
V_28 = - V_147 ;
if ( F_316 ( & V_286 , V_254 , sizeof( V_286 ) ) )
goto V_123;
V_28 = F_319 ( V_3 , & V_286 ) ;
break;
}
case V_287 : {
struct V_288 V_130 * V_289 = V_254 ;
struct V_288 V_290 ;
T_10 V_248 , * V_291 ;
V_291 = NULL ;
if ( V_254 ) {
V_28 = - V_147 ;
if ( F_316 ( & V_290 , V_254 ,
sizeof( V_290 ) ) )
goto V_123;
V_28 = - V_116 ;
if ( V_290 . V_190 != sizeof( V_248 ) )
goto V_123;
V_28 = - V_147 ;
if ( F_316 ( & V_248 , V_289 -> V_248 ,
sizeof( V_248 ) ) )
goto V_123;
V_291 = & V_248 ;
}
V_28 = F_300 ( V_3 , V_291 ) ;
break;
}
case V_292 : {
V_256 = F_90 ( sizeof( struct V_255 ) , V_35 ) ;
V_28 = - V_37 ;
if ( ! V_256 )
goto V_123;
V_28 = F_320 ( V_3 , V_256 ) ;
if ( V_28 )
goto V_123;
V_28 = - V_147 ;
if ( F_146 ( V_254 , V_256 , sizeof( struct V_255 ) ) )
goto V_123;
V_28 = 0 ;
break;
}
case V_293 : {
V_256 = F_311 ( V_254 , sizeof( * V_256 ) ) ;
if ( F_292 ( V_256 ) ) {
V_28 = F_293 ( V_256 ) ;
V_256 = NULL ;
goto V_123;
}
V_28 = F_321 ( V_3 , V_256 ) ;
break;
}
default:
V_28 = F_305 ( V_103 , V_252 , V_253 ) ;
}
V_123:
F_11 ( V_3 ) ;
F_99 ( V_256 ) ;
F_99 ( V_257 ) ;
return V_28 ;
}
static long F_322 ( struct V_102 * V_103 ,
unsigned int V_252 , unsigned long V_253 )
{
struct V_2 * V_3 = V_103 -> V_104 ;
void V_130 * V_254 = F_323 ( V_253 ) ;
int V_28 ;
if ( V_3 -> V_9 -> V_45 != V_59 -> V_45 )
return - V_258 ;
switch ( V_252 ) {
case V_287 : {
struct V_288 V_130 * V_289 = V_254 ;
struct V_288 V_290 ;
T_11 V_294 ;
T_10 V_248 ;
if ( V_254 ) {
V_28 = - V_147 ;
if ( F_316 ( & V_290 , V_254 ,
sizeof( V_290 ) ) )
goto V_123;
V_28 = - V_116 ;
if ( V_290 . V_190 != sizeof( V_294 ) )
goto V_123;
V_28 = - V_147 ;
if ( F_316 ( & V_294 , V_289 -> V_248 ,
sizeof( V_294 ) ) )
goto V_123;
F_324 ( & V_248 , & V_294 ) ;
V_28 = F_300 ( V_3 , & V_248 ) ;
} else
V_28 = F_300 ( V_3 , NULL ) ;
break;
}
default:
V_28 = F_303 ( V_103 , V_252 , V_253 ) ;
}
V_123:
return V_28 ;
}
static int F_325 ( struct V_95 * V_96 ,
int (* F_326)( struct V_95 * V_96 ,
struct V_295 * V_296 ) ,
unsigned long V_253 )
{
struct V_295 V_296 ;
if ( ! F_326 )
return - V_297 ;
if ( F_316 ( & V_296 , ( void V_130 * ) V_253 , sizeof( V_296 ) ) )
return - V_147 ;
return F_326 ( V_96 , & V_296 ) ;
}
static long F_327 ( struct V_102 * V_103 , unsigned int V_252 ,
unsigned long V_253 )
{
struct V_95 * V_96 = V_103 -> V_104 ;
switch ( V_252 ) {
case V_298 :
return F_325 ( V_96 , V_96 -> V_57 -> V_299 , V_253 ) ;
case V_300 :
return F_325 ( V_96 , V_96 -> V_57 -> V_301 , V_253 ) ;
case V_302 :
return F_325 ( V_96 , V_96 -> V_57 -> V_303 , V_253 ) ;
default:
if ( V_96 -> V_57 -> V_252 )
return V_96 -> V_57 -> V_252 ( V_96 , V_252 , V_253 ) ;
return - V_304 ;
}
}
static int F_328 ( struct V_101 * V_101 , struct V_102 * V_103 )
{
struct V_95 * V_96 = V_103 -> V_104 ;
struct V_9 * V_9 = V_96 -> V_9 ;
F_117 ( V_9 ) ;
return 0 ;
}
struct V_95 * F_329 ( struct V_102 * V_103 )
{
if ( V_103 -> V_305 != & V_306 )
return NULL ;
return V_103 -> V_104 ;
}
int F_330 ( struct V_307 * V_57 , T_4 type )
{
if ( type >= F_331 ( V_308 ) )
return - V_309 ;
if ( V_308 [ type ] != NULL )
return - V_137 ;
V_308 [ type ] = V_57 ;
return 0 ;
}
void F_332 ( T_4 type )
{
if ( V_308 [ type ] != NULL )
V_308 [ type ] = NULL ;
}
static int F_333 ( struct V_9 * V_9 ,
struct V_310 * V_311 )
{
struct V_307 * V_57 = NULL ;
struct V_95 * V_96 ;
bool V_312 = V_311 -> V_115 & V_313 ;
int V_194 ;
if ( V_311 -> type >= F_331 ( V_308 ) )
return - V_314 ;
V_57 = V_308 [ V_311 -> type ] ;
if ( V_57 == NULL )
return - V_314 ;
if ( V_312 )
return 0 ;
V_96 = F_90 ( sizeof( * V_96 ) , V_35 ) ;
if ( ! V_96 )
return - V_37 ;
V_96 -> V_57 = V_57 ;
V_96 -> V_9 = V_9 ;
V_194 = V_57 -> V_315 ( V_96 , V_311 -> type ) ;
if ( V_194 < 0 ) {
F_99 ( V_96 ) ;
return V_194 ;
}
V_194 = F_289 ( V_57 -> V_316 , & V_306 , V_96 , V_239 | V_240 ) ;
if ( V_194 < 0 ) {
V_57 -> V_98 ( V_96 ) ;
return V_194 ;
}
F_95 ( & V_96 -> V_97 , & V_9 -> V_87 ) ;
F_116 ( V_9 ) ;
V_311 -> V_317 = V_194 ;
return 0 ;
}
static long F_334 ( struct V_9 * V_9 , long V_253 )
{
switch ( V_253 ) {
case V_318 :
case V_319 :
case V_320 :
case V_321 :
#ifdef F_335
case V_322 :
#endif
#ifdef F_86
case V_323 :
case V_324 :
#endif
case V_325 :
case V_326 :
return 1 ;
#ifdef F_336
case V_327 :
return V_328 ;
#endif
#if V_74 > 1
case V_329 :
return V_74 ;
#endif
default:
break;
}
return F_337 ( V_9 , V_253 ) ;
}
static long F_338 ( struct V_102 * V_103 ,
unsigned int V_252 , unsigned long V_253 )
{
struct V_9 * V_9 = V_103 -> V_104 ;
void V_130 * V_254 = ( void V_130 * ) V_253 ;
int V_28 ;
if ( V_9 -> V_45 != V_59 -> V_45 )
return - V_258 ;
switch ( V_252 ) {
case V_330 :
V_28 = F_290 ( V_9 , V_253 ) ;
break;
case V_331 : {
struct V_110 V_332 ;
V_28 = - V_147 ;
if ( F_316 ( & V_332 , V_254 ,
sizeof( V_332 ) ) )
goto V_123;
V_28 = F_144 ( V_9 , & V_332 ) ;
break;
}
case V_333 : {
struct V_142 log ;
V_28 = - V_147 ;
if ( F_316 ( & log , V_254 , sizeof( log ) ) )
goto V_123;
V_28 = F_339 ( V_9 , & log ) ;
break;
}
#ifdef F_284
case V_334 : {
struct V_335 V_336 ;
V_28 = - V_147 ;
if ( F_316 ( & V_336 , V_254 , sizeof( V_336 ) ) )
goto V_123;
V_28 = F_340 ( V_9 , & V_336 ) ;
break;
}
case V_337 : {
struct V_335 V_336 ;
V_28 = - V_147 ;
if ( F_316 ( & V_336 , V_254 , sizeof( V_336 ) ) )
goto V_123;
V_28 = F_341 ( V_9 , & V_336 ) ;
break;
}
#endif
case V_338 : {
struct V_339 V_191 ;
V_28 = - V_147 ;
if ( F_316 ( & V_191 , V_254 , sizeof( V_191 ) ) )
goto V_123;
V_28 = V_339 ( V_9 , & V_191 ) ;
break;
}
case V_340 : {
struct V_341 V_191 ;
V_28 = - V_147 ;
if ( F_316 ( & V_191 , V_254 , sizeof( V_191 ) ) )
goto V_123;
V_28 = V_341 ( V_9 , & V_191 ) ;
break;
}
#ifdef F_335
case V_342 : {
struct V_343 V_344 ;
V_28 = - V_147 ;
if ( F_316 ( & V_344 , V_254 , sizeof( V_344 ) ) )
goto V_123;
V_28 = F_342 ( V_9 , & V_344 ) ;
break;
}
#endif
#ifdef F_343
case V_345 :
case V_346 : {
struct V_347 V_348 ;
V_28 = - V_147 ;
if ( F_316 ( & V_348 , V_254 , sizeof( V_348 ) ) )
goto V_123;
V_28 = F_344 ( V_9 , & V_348 ,
V_252 == V_345 ) ;
if ( V_28 )
goto V_123;
V_28 = - V_147 ;
if ( V_252 == V_345 ) {
if ( F_146 ( V_254 , & V_348 , sizeof( V_348 ) ) )
goto V_123;
}
V_28 = 0 ;
break;
}
#endif
#ifdef F_336
case V_349 : {
struct V_350 V_351 ;
struct V_350 V_130 * V_352 ;
struct V_353 * V_354 ;
V_28 = - V_147 ;
if ( F_316 ( & V_351 , V_254 , sizeof( V_351 ) ) )
goto V_123;
V_28 = - V_116 ;
if ( V_351 . V_355 >= V_328 )
goto V_123;
if ( V_351 . V_115 )
goto V_123;
V_28 = - V_37 ;
V_354 = F_345 ( V_351 . V_355 * sizeof( * V_354 ) ) ;
if ( ! V_354 )
goto V_123;
V_28 = - V_147 ;
V_352 = V_254 ;
if ( F_316 ( V_354 , V_352 -> V_354 ,
V_351 . V_355 * sizeof( * V_354 ) ) )
goto V_356;
V_28 = F_346 ( V_9 , V_354 , V_351 . V_355 ,
V_351 . V_115 ) ;
V_356:
F_347 ( V_354 ) ;
break;
}
#endif
case V_357 : {
struct V_310 V_311 ;
V_28 = - V_147 ;
if ( F_316 ( & V_311 , V_254 , sizeof( V_311 ) ) )
goto V_123;
V_28 = F_333 ( V_9 , & V_311 ) ;
if ( V_28 )
goto V_123;
V_28 = - V_147 ;
if ( F_146 ( V_254 , & V_311 , sizeof( V_311 ) ) )
goto V_123;
V_28 = 0 ;
break;
}
case V_358 :
V_28 = F_334 ( V_9 , V_253 ) ;
break;
default:
V_28 = F_348 ( V_103 , V_252 , V_253 ) ;
}
V_123:
return V_28 ;
}
static long F_349 ( struct V_102 * V_103 ,
unsigned int V_252 , unsigned long V_253 )
{
struct V_9 * V_9 = V_103 -> V_104 ;
int V_28 ;
if ( V_9 -> V_45 != V_59 -> V_45 )
return - V_258 ;
switch ( V_252 ) {
case V_333 : {
struct V_359 V_360 ;
struct V_142 log ;
V_28 = - V_147 ;
if ( F_316 ( & V_360 , ( void V_130 * ) V_253 ,
sizeof( V_360 ) ) )
goto V_123;
log . V_119 = V_360 . V_119 ;
log . V_361 = V_360 . V_361 ;
log . V_362 = V_360 . V_362 ;
log . V_68 = F_323 ( V_360 . V_68 ) ;
V_28 = F_339 ( V_9 , & log ) ;
break;
}
default:
V_28 = F_338 ( V_103 , V_252 , V_253 ) ;
}
V_123:
return V_28 ;
}
static int F_350 ( unsigned long type )
{
int V_28 ;
struct V_9 * V_9 ;
V_9 = F_81 ( type ) ;
if ( F_292 ( V_9 ) )
return F_293 ( V_9 ) ;
#ifdef F_284
V_28 = F_351 ( V_9 ) ;
if ( V_28 < 0 ) {
F_117 ( V_9 ) ;
return V_28 ;
}
#endif
V_28 = F_289 ( L_2 , & V_363 , V_9 , V_239 | V_240 ) ;
if ( V_28 < 0 )
F_117 ( V_9 ) ;
return V_28 ;
}
static long F_352 ( struct V_102 * V_103 ,
unsigned int V_252 , unsigned long V_253 )
{
long V_28 = - V_116 ;
switch ( V_252 ) {
case V_364 :
if ( V_253 )
goto V_123;
V_28 = V_365 ;
break;
case V_366 :
V_28 = F_350 ( V_253 ) ;
break;
case V_358 :
V_28 = F_334 ( NULL , V_253 ) ;
break;
case V_367 :
if ( V_253 )
goto V_123;
V_28 = V_91 ;
#ifdef F_283
V_28 += V_91 ;
#endif
#ifdef F_284
V_28 += V_91 ;
#endif
break;
case V_368 :
case V_369 :
case V_370 :
V_28 = - V_371 ;
break;
default:
return F_353 ( V_103 , V_252 , V_253 ) ;
}
V_123:
return V_28 ;
}
static void F_354 ( void * V_372 )
{
int V_4 = F_355 () ;
int V_28 ;
if ( F_356 ( V_4 , V_373 ) )
return;
F_24 ( V_4 , V_373 ) ;
V_28 = F_357 () ;
if ( V_28 ) {
F_358 ( V_4 , V_373 ) ;
F_92 ( & V_374 ) ;
F_359 ( L_3 , V_4 ) ;
}
}
static void F_360 ( void )
{
F_361 ( & V_375 ) ;
if ( V_376 )
F_354 ( NULL ) ;
F_362 ( & V_375 ) ;
}
static void F_363 ( void * V_372 )
{
int V_4 = F_355 () ;
if ( ! F_356 ( V_4 , V_373 ) )
return;
F_358 ( V_4 , V_373 ) ;
F_364 () ;
}
static void F_365 ( void )
{
F_361 ( & V_375 ) ;
if ( V_376 )
F_363 ( NULL ) ;
F_362 ( & V_375 ) ;
}
static void F_366 ( void )
{
F_63 ( ! V_376 ) ;
V_376 -- ;
if ( ! V_376 )
F_367 ( F_363 , NULL , 1 ) ;
}
static void F_98 ( void )
{
F_361 ( & V_375 ) ;
F_366 () ;
F_362 ( & V_375 ) ;
}
static int F_85 ( void )
{
int V_28 = 0 ;
F_361 ( & V_375 ) ;
V_376 ++ ;
if ( V_376 == 1 ) {
F_94 ( & V_374 , 0 ) ;
F_367 ( F_354 , NULL , 1 ) ;
if ( F_297 ( & V_374 ) ) {
F_366 () ;
V_28 = - V_377 ;
}
}
F_362 ( & V_375 ) ;
return V_28 ;
}
static int F_368 ( struct V_378 * V_379 , unsigned long V_203 ,
void * V_241 )
{
V_203 &= ~ V_380 ;
switch ( V_203 ) {
case V_381 :
F_365 () ;
break;
case V_382 :
F_360 () ;
break;
}
return V_383 ;
}
static int F_369 ( struct V_378 * V_379 , unsigned long V_203 ,
void * V_241 )
{
F_359 ( L_4 ) ;
V_384 = true ;
F_367 ( F_363 , NULL , 1 ) ;
return V_383 ;
}
static void F_109 ( struct V_80 * V_385 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_385 -> V_386 ; V_11 ++ ) {
struct V_387 * V_388 = V_385 -> V_389 [ V_11 ] . V_96 ;
F_370 ( V_388 ) ;
}
F_99 ( V_385 ) ;
}
static inline int F_371 ( const struct V_390 * V_391 ,
const struct V_390 * V_392 )
{
T_6 V_393 = V_391 -> V_156 ;
T_6 V_394 = V_392 -> V_156 ;
if ( V_393 < V_394 )
return - 1 ;
if ( V_392 -> V_190 ) {
V_393 += V_391 -> V_190 ;
V_394 += V_392 -> V_190 ;
}
if ( V_393 > V_394 )
return 1 ;
return 0 ;
}
static int F_372 ( const void * V_395 , const void * V_396 )
{
return F_371 ( V_395 , V_396 ) ;
}
static int F_373 ( struct V_80 * V_385 , struct V_387 * V_96 ,
T_6 V_156 , int V_190 )
{
V_385 -> V_389 [ V_385 -> V_386 ++ ] = (struct V_390 ) {
. V_156 = V_156 ,
. V_190 = V_190 ,
. V_96 = V_96 ,
} ;
F_374 ( V_385 -> V_389 , V_385 -> V_386 , sizeof( struct V_390 ) ,
F_372 , NULL ) ;
return 0 ;
}
static int F_375 ( struct V_80 * V_385 ,
T_6 V_156 , int V_190 )
{
struct V_390 * V_389 , V_397 ;
int V_398 ;
V_397 = (struct V_390 ) {
. V_156 = V_156 ,
. V_190 = V_190 ,
} ;
V_389 = bsearch ( & V_397 , V_385 -> V_389 , V_385 -> V_386 ,
sizeof( struct V_390 ) , F_372 ) ;
if ( V_389 == NULL )
return - V_146 ;
V_398 = V_389 - V_385 -> V_389 ;
while ( V_398 > 0 && F_371 ( & V_397 , & V_385 -> V_389 [ V_398 - 1 ] ) == 0 )
V_398 -- ;
return V_398 ;
}
static int F_376 ( struct V_2 * V_3 , struct V_80 * V_385 ,
struct V_390 * V_389 , const void * V_203 )
{
int V_48 ;
V_48 = F_375 ( V_385 , V_389 -> V_156 , V_389 -> V_190 ) ;
if ( V_48 < 0 )
return - V_371 ;
while ( V_48 < V_385 -> V_386 &&
F_371 ( V_389 , & V_385 -> V_389 [ V_48 ] ) == 0 ) {
if ( ! F_377 ( V_3 , V_385 -> V_389 [ V_48 ] . V_96 , V_389 -> V_156 ,
V_389 -> V_190 , V_203 ) )
return V_48 ;
V_48 ++ ;
}
return - V_371 ;
}
int F_378 ( struct V_2 * V_3 , enum V_399 V_400 , T_6 V_156 ,
int V_190 , const void * V_203 )
{
struct V_80 * V_385 ;
struct V_390 V_389 ;
int V_28 ;
V_389 = (struct V_390 ) {
. V_156 = V_156 ,
. V_190 = V_190 ,
} ;
V_385 = F_379 ( V_3 -> V_9 -> V_79 [ V_400 ] , & V_3 -> V_9 -> V_49 ) ;
V_28 = F_376 ( V_3 , V_385 , & V_389 , V_203 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_380 ( struct V_2 * V_3 , enum V_399 V_400 ,
T_6 V_156 , int V_190 , const void * V_203 , long V_401 )
{
struct V_80 * V_385 ;
struct V_390 V_389 ;
V_389 = (struct V_390 ) {
. V_156 = V_156 ,
. V_190 = V_190 ,
} ;
V_385 = F_379 ( V_3 -> V_9 -> V_79 [ V_400 ] , & V_3 -> V_9 -> V_49 ) ;
if ( ( V_401 >= 0 ) && ( V_401 < V_385 -> V_386 ) &&
( F_371 ( & V_389 , & V_385 -> V_389 [ V_401 ] ) == 0 ) )
if ( ! F_377 ( V_3 , V_385 -> V_389 [ V_401 ] . V_96 , V_156 , V_190 ,
V_203 ) )
return V_401 ;
return F_376 ( V_3 , V_385 , & V_389 , V_203 ) ;
}
static int F_381 ( struct V_2 * V_3 , struct V_80 * V_385 ,
struct V_390 * V_389 , void * V_203 )
{
int V_48 ;
V_48 = F_375 ( V_385 , V_389 -> V_156 , V_389 -> V_190 ) ;
if ( V_48 < 0 )
return - V_371 ;
while ( V_48 < V_385 -> V_386 &&
F_371 ( V_389 , & V_385 -> V_389 [ V_48 ] ) == 0 ) {
if ( ! F_382 ( V_3 , V_385 -> V_389 [ V_48 ] . V_96 , V_389 -> V_156 ,
V_389 -> V_190 , V_203 ) )
return V_48 ;
V_48 ++ ;
}
return - V_371 ;
}
int F_383 ( struct V_2 * V_3 , enum V_399 V_400 , T_6 V_156 ,
int V_190 , void * V_203 )
{
struct V_80 * V_385 ;
struct V_390 V_389 ;
int V_28 ;
V_389 = (struct V_390 ) {
. V_156 = V_156 ,
. V_190 = V_190 ,
} ;
V_385 = F_379 ( V_3 -> V_9 -> V_79 [ V_400 ] , & V_3 -> V_9 -> V_49 ) ;
V_28 = F_381 ( V_3 , V_385 , & V_389 , V_203 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_384 ( struct V_9 * V_9 , enum V_399 V_400 , T_6 V_156 ,
int V_190 , struct V_387 * V_96 )
{
struct V_80 * V_402 , * V_385 ;
V_385 = V_9 -> V_79 [ V_400 ] ;
if ( V_385 -> V_386 - V_385 -> V_403 > V_404 - 1 )
return - V_309 ;
V_402 = F_385 ( sizeof( * V_385 ) + ( ( V_385 -> V_386 + 1 ) *
sizeof( struct V_390 ) ) , V_35 ) ;
if ( ! V_402 )
return - V_37 ;
memcpy ( V_402 , V_385 , sizeof( * V_385 ) + ( V_385 -> V_386 *
sizeof( struct V_390 ) ) ) ;
F_373 ( V_402 , V_96 , V_156 , V_190 ) ;
F_130 ( V_9 -> V_79 [ V_400 ] , V_402 ) ;
F_131 ( & V_9 -> V_49 ) ;
F_99 ( V_385 ) ;
return 0 ;
}
int F_386 ( struct V_9 * V_9 , enum V_399 V_400 ,
struct V_387 * V_96 )
{
int V_11 , V_28 ;
struct V_80 * V_402 , * V_385 ;
V_385 = V_9 -> V_79 [ V_400 ] ;
V_28 = - V_146 ;
for ( V_11 = 0 ; V_11 < V_385 -> V_386 ; V_11 ++ )
if ( V_385 -> V_389 [ V_11 ] . V_96 == V_96 ) {
V_28 = 0 ;
break;
}
if ( V_28 )
return V_28 ;
V_402 = F_385 ( sizeof( * V_385 ) + ( ( V_385 -> V_386 - 1 ) *
sizeof( struct V_390 ) ) , V_35 ) ;
if ( ! V_402 )
return - V_37 ;
memcpy ( V_402 , V_385 , sizeof( * V_385 ) + V_11 * sizeof( struct V_390 ) ) ;
V_402 -> V_386 -- ;
memcpy ( V_402 -> V_389 + V_11 , V_385 -> V_389 + V_11 + 1 ,
( V_402 -> V_386 - V_11 ) * sizeof( struct V_390 ) ) ;
F_130 ( V_9 -> V_79 [ V_400 ] , V_402 ) ;
F_131 ( & V_9 -> V_49 ) ;
F_99 ( V_385 ) ;
return V_28 ;
}
static int F_387 ( void * V_405 , T_8 * V_203 )
{
unsigned V_150 = ( long ) V_405 ;
struct V_9 * V_9 ;
* V_203 = 0 ;
F_52 ( & V_88 ) ;
F_388 ( V_9 , & V_89 , V_89 )
* V_203 += * ( T_4 * ) ( ( void * ) V_9 + V_150 ) ;
F_54 ( & V_88 ) ;
return 0 ;
}
static int F_389 ( void * V_405 , T_8 * V_203 )
{
unsigned V_150 = ( long ) V_405 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_203 = 0 ;
F_52 ( & V_88 ) ;
F_388 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_203 += * ( T_4 * ) ( ( void * ) V_3 + V_150 ) ;
F_54 ( & V_88 ) ;
return 0 ;
}
static int F_390 ( void )
{
int V_28 = - V_137 ;
struct V_406 * V_291 ;
V_407 = F_391 ( L_5 , NULL ) ;
if ( V_407 == NULL )
goto V_123;
for ( V_291 = V_408 ; V_291 -> V_316 ; ++ V_291 ) {
V_291 -> V_409 = F_392 ( V_291 -> V_316 , 0444 , V_407 ,
( void * ) ( long ) V_291 -> V_150 ,
V_410 [ V_291 -> V_411 ] ) ;
if ( V_291 -> V_409 == NULL )
goto V_412;
}
return 0 ;
V_412:
F_393 ( V_407 ) ;
V_123:
return V_28 ;
}
static void F_394 ( void )
{
struct V_406 * V_291 ;
for ( V_291 = V_408 ; V_291 -> V_316 ; ++ V_291 )
F_395 ( V_291 -> V_409 ) ;
F_395 ( V_407 ) ;
}
static int F_396 ( void )
{
if ( V_376 )
F_363 ( NULL ) ;
return 0 ;
}
static void F_397 ( void )
{
if ( V_376 ) {
F_124 ( F_398 ( & V_375 ) ) ;
F_354 ( NULL ) ;
}
}
static inline
struct V_2 * F_399 ( struct V_7 * V_413 )
{
return F_49 ( V_413 , struct V_2 , V_7 ) ;
}
static void F_400 ( struct V_7 * V_413 , int V_4 )
{
struct V_2 * V_3 = F_399 ( V_413 ) ;
if ( V_3 -> V_40 )
V_3 -> V_40 = false ;
F_401 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_402 ( struct V_7 * V_413 ,
struct V_164 * V_414 )
{
struct V_2 * V_3 = F_399 ( V_413 ) ;
if ( V_59 -> V_415 == V_416 )
V_3 -> V_40 = true ;
F_13 ( V_3 ) ;
}
int F_403 ( void * V_417 , unsigned V_418 , unsigned V_419 ,
struct V_420 * V_420 )
{
int V_28 ;
int V_4 ;
V_28 = F_404 ( V_417 ) ;
if ( V_28 )
goto V_421;
V_28 = F_405 () ;
if ( V_28 )
goto V_422;
if ( ! F_19 ( & V_373 , V_35 ) ) {
V_28 = - V_37 ;
goto V_423;
}
V_28 = F_406 () ;
if ( V_28 < 0 )
goto V_424;
F_407 (cpu) {
F_408 ( V_4 ,
V_425 ,
& V_28 , 1 ) ;
if ( V_28 < 0 )
goto V_426;
}
V_28 = F_409 ( & V_427 ) ;
if ( V_28 )
goto V_428;
F_410 ( & V_429 ) ;
if ( ! V_419 )
V_419 = F_411 ( struct V_2 ) ;
V_430 = F_412 ( L_6 , V_418 , V_419 ,
0 , NULL ) ;
if ( ! V_430 ) {
V_28 = - V_37 ;
goto V_431;
}
V_28 = F_413 () ;
if ( V_28 )
goto V_138;
V_432 . V_433 = V_420 ;
V_363 . V_433 = V_420 ;
V_238 . V_433 = V_420 ;
V_28 = F_414 ( & V_434 ) ;
if ( V_28 ) {
F_415 ( L_7 ) ;
goto V_435;
}
F_416 ( & V_436 ) ;
V_243 . V_437 = F_400 ;
V_243 . V_438 = F_402 ;
V_28 = F_390 () ;
if ( V_28 ) {
F_415 ( L_8 ) ;
goto V_439;
}
V_28 = F_417 () ;
F_124 ( V_28 ) ;
return 0 ;
V_439:
F_418 ( & V_436 ) ;
F_419 ( & V_434 ) ;
V_435:
F_420 () ;
V_138:
F_421 ( V_430 ) ;
V_431:
F_422 ( & V_429 ) ;
F_423 ( & V_427 ) ;
V_428:
V_426:
F_424 () ;
V_424:
F_28 ( V_373 ) ;
V_423:
F_425 () ;
V_422:
F_426 () ;
V_421:
return V_28 ;
}
void F_427 ( void )
{
F_394 () ;
F_419 ( & V_434 ) ;
F_421 ( V_430 ) ;
F_420 () ;
F_418 ( & V_436 ) ;
F_422 ( & V_429 ) ;
F_423 ( & V_427 ) ;
F_367 ( F_363 , NULL , 1 ) ;
F_424 () ;
F_426 () ;
F_425 () ;
F_28 ( V_373 ) ;
F_428 () ;
}
