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
V_27 = F_38 ( V_33 | V_34 ) ;
if ( ! V_27 ) {
V_28 = - V_35 ;
goto V_36;
}
V_3 -> V_37 = F_39 ( V_27 ) ;
F_40 ( V_3 , false ) ;
F_41 ( V_3 , false ) ;
V_3 -> V_38 = false ;
V_28 = F_42 ( V_3 ) ;
if ( V_28 < 0 )
goto V_39;
return 0 ;
V_39:
F_43 ( ( unsigned long ) V_3 -> V_37 ) ;
V_36:
return V_28 ;
}
void F_44 ( struct V_2 * V_3 )
{
F_45 ( V_3 -> V_30 ) ;
F_46 ( V_3 ) ;
F_43 ( ( unsigned long ) V_3 -> V_37 ) ;
}
static inline struct V_9 * F_47 ( struct V_40 * V_41 )
{
return F_48 ( V_41 , struct V_9 , V_40 ) ;
}
static void F_49 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_44 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
int V_45 , V_46 ;
V_46 = F_50 ( & V_9 -> V_47 ) ;
F_51 ( & V_9 -> V_48 ) ;
V_9 -> V_49 ++ ;
V_45 = F_52 ( V_9 , V_44 ) | V_9 -> V_19 ;
if ( V_45 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_54 ( V_9 , V_44 ) ;
F_55 ( & V_9 -> V_47 , V_46 ) ;
}
static void F_56 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_44 ,
T_3 V_50 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
int V_46 ;
V_46 = F_50 ( & V_9 -> V_47 ) ;
F_51 ( & V_9 -> V_48 ) ;
V_9 -> V_49 ++ ;
F_57 ( V_9 , V_44 , V_50 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_47 , V_46 ) ;
}
static void F_58 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
int V_45 = 0 , V_46 ;
V_46 = F_50 ( & V_9 -> V_47 ) ;
F_51 ( & V_9 -> V_48 ) ;
V_9 -> V_53 ++ ;
V_45 = F_59 ( V_9 , V_51 , V_52 ) ;
V_45 |= V_9 -> V_19 ;
if ( V_45 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_47 , V_46 ) ;
}
static void F_60 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
F_51 ( & V_9 -> V_48 ) ;
V_9 -> V_49 ++ ;
F_61 () ;
V_9 -> V_53 -- ;
F_53 ( & V_9 -> V_48 ) ;
F_62 ( V_9 -> V_53 < 0 ) ;
}
static int F_63 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
int V_54 , V_46 ;
V_46 = F_50 ( & V_9 -> V_47 ) ;
F_51 ( & V_9 -> V_48 ) ;
V_54 = F_64 ( V_9 , V_51 , V_52 ) ;
if ( V_54 )
F_29 ( V_9 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_47 , V_46 ) ;
return V_54 ;
}
static int F_65 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
int V_54 , V_46 ;
V_46 = F_50 ( & V_9 -> V_47 ) ;
F_51 ( & V_9 -> V_48 ) ;
V_54 = F_64 ( V_9 , V_51 , V_52 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_47 , V_46 ) ;
return V_54 ;
}
static int F_66 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_44 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
int V_54 , V_46 ;
V_46 = F_50 ( & V_9 -> V_47 ) ;
F_51 ( & V_9 -> V_48 ) ;
V_54 = F_67 ( V_9 , V_44 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_47 , V_46 ) ;
return V_54 ;
}
static void F_68 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_9 * V_9 = F_47 ( V_41 ) ;
int V_46 ;
V_46 = F_50 ( & V_9 -> V_47 ) ;
F_69 ( V_9 ) ;
F_55 ( & V_9 -> V_47 , V_46 ) ;
}
static int F_70 ( struct V_9 * V_9 )
{
V_9 -> V_40 . V_55 = & V_56 ;
return F_71 ( & V_9 -> V_40 , V_57 -> V_43 ) ;
}
static int F_70 ( struct V_9 * V_9 )
{
return 0 ;
}
static struct V_58 * F_72 ( void )
{
int V_11 ;
struct V_58 * V_59 ;
V_59 = F_73 ( sizeof( struct V_58 ) ) ;
if ( ! V_59 )
return NULL ;
V_59 -> V_60 = - 150 ;
for ( V_11 = 0 ; V_11 < V_61 ; V_11 ++ )
V_59 -> V_62 [ V_11 ] = V_59 -> V_63 [ V_11 ] . V_26 = V_11 ;
return V_59 ;
}
static void F_74 ( struct V_64 * V_65 )
{
if ( ! V_65 -> V_66 )
return;
F_75 ( V_65 -> V_66 ) ;
V_65 -> V_66 = NULL ;
}
static void F_76 ( struct V_9 * V_9 , struct V_64 * free ,
struct V_64 * V_67 )
{
if ( ! V_67 || free -> V_66 != V_67 -> V_66 )
F_74 ( free ) ;
F_77 ( V_9 , free , V_67 ) ;
free -> V_68 = 0 ;
}
static void F_78 ( struct V_9 * V_9 , struct V_58 * V_59 )
{
struct V_64 * V_65 ;
if ( ! V_59 )
return;
F_79 (memslot, slots)
F_76 ( V_9 , V_65 , NULL ) ;
F_75 ( V_59 ) ;
}
static struct V_9 * F_80 ( unsigned long type )
{
int V_28 , V_11 ;
struct V_9 * V_9 = F_81 () ;
if ( ! V_9 )
return F_82 ( - V_35 ) ;
V_28 = F_83 ( V_9 , type ) ;
if ( V_28 )
goto V_69;
V_28 = F_84 () ;
if ( V_28 )
goto V_69;
#ifdef F_85
F_86 ( & V_9 -> V_70 ) ;
#endif
F_87 ( V_61 > V_71 ) ;
V_28 = - V_35 ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ ) {
V_9 -> V_63 [ V_11 ] = F_72 () ;
if ( ! V_9 -> V_63 [ V_11 ] )
goto V_73;
}
if ( F_88 ( & V_9 -> V_47 ) )
goto V_73;
if ( F_88 ( & V_9 -> V_74 ) )
goto V_75;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) {
V_9 -> V_77 [ V_11 ] = F_89 ( sizeof( struct V_78 ) ,
V_33 ) ;
if ( ! V_9 -> V_77 [ V_11 ] )
goto V_79;
}
F_90 ( & V_9 -> V_48 ) ;
V_9 -> V_43 = V_57 -> V_43 ;
F_91 ( & V_9 -> V_43 -> V_80 ) ;
F_92 ( V_9 ) ;
F_35 ( & V_9 -> V_81 ) ;
F_35 ( & V_9 -> V_82 ) ;
F_35 ( & V_9 -> V_83 ) ;
F_93 ( & V_9 -> V_84 , 1 ) ;
F_94 ( & V_9 -> V_85 ) ;
V_28 = F_70 ( V_9 ) ;
if ( V_28 )
goto V_79;
F_51 ( & V_86 ) ;
F_95 ( & V_9 -> V_87 , & V_87 ) ;
F_53 ( & V_86 ) ;
F_96 () ;
return V_9 ;
V_79:
F_97 ( & V_9 -> V_74 ) ;
V_75:
F_97 ( & V_9 -> V_47 ) ;
V_73:
F_98 () ;
V_69:
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ )
F_99 ( V_9 -> V_77 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_63 [ V_11 ] ) ;
F_100 ( V_9 ) ;
return F_82 ( V_28 ) ;
}
void * F_73 ( unsigned long V_88 )
{
if ( V_88 > V_89 )
return F_101 ( V_88 ) ;
else
return F_89 ( V_88 , V_33 ) ;
}
static void F_102 ( struct V_9 * V_9 )
{
struct V_90 * V_91 , * V_92 ;
F_103 (node, tmp, &kvm->devices) {
struct V_93 * V_94 =
F_104 ( V_91 , struct V_93 , V_95 ) ;
F_105 ( V_91 ) ;
V_94 -> V_55 -> V_96 ( V_94 ) ;
}
}
static void F_106 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_42 * V_43 = V_9 -> V_43 ;
F_107 ( V_9 ) ;
F_51 ( & V_86 ) ;
F_105 ( & V_9 -> V_87 ) ;
F_53 ( & V_86 ) ;
F_108 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ )
F_109 ( V_9 -> V_77 [ V_11 ] ) ;
F_110 ( V_9 ) ;
#if F_111 ( V_97 ) && F_111 ( V_98 )
F_112 ( & V_9 -> V_40 , V_9 -> V_43 ) ;
#else
F_69 ( V_9 ) ;
#endif
F_113 ( V_9 ) ;
F_102 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ )
F_78 ( V_9 , V_9 -> V_63 [ V_11 ] ) ;
F_97 ( & V_9 -> V_74 ) ;
F_97 ( & V_9 -> V_47 ) ;
F_100 ( V_9 ) ;
F_114 () ;
F_98 () ;
F_115 ( V_43 ) ;
}
void F_116 ( struct V_9 * V_9 )
{
F_91 ( & V_9 -> V_84 ) ;
}
void F_117 ( struct V_9 * V_9 )
{
if ( F_118 ( & V_9 -> V_84 ) )
F_106 ( V_9 ) ;
}
static int F_119 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_9 * V_9 = V_101 -> V_102 ;
F_120 ( V_9 ) ;
F_117 ( V_9 ) ;
return 0 ;
}
static int F_121 ( struct V_64 * V_65 )
{
unsigned long V_103 = 2 * F_122 ( V_65 ) ;
V_65 -> V_66 = F_73 ( V_103 ) ;
if ( ! V_65 -> V_66 )
return - V_35 ;
return 0 ;
}
static void F_123 ( struct V_58 * V_59 ,
struct V_64 * V_104 )
{
int V_26 = V_104 -> V_26 ;
int V_11 = V_59 -> V_62 [ V_26 ] ;
struct V_64 * V_105 = V_59 -> V_63 ;
F_124 ( V_105 [ V_11 ] . V_26 != V_26 ) ;
if ( ! V_104 -> V_68 ) {
F_124 ( ! V_105 [ V_11 ] . V_68 ) ;
if ( V_105 [ V_11 ] . V_68 )
V_59 -> V_106 -- ;
} else {
if ( ! V_105 [ V_11 ] . V_68 )
V_59 -> V_106 ++ ;
}
while ( V_11 < V_61 - 1 &&
V_104 -> V_107 <= V_105 [ V_11 + 1 ] . V_107 ) {
if ( ! V_105 [ V_11 + 1 ] . V_68 )
break;
V_105 [ V_11 ] = V_105 [ V_11 + 1 ] ;
V_59 -> V_62 [ V_105 [ V_11 ] . V_26 ] = V_11 ;
V_11 ++ ;
}
if ( V_104 -> V_68 ) {
while ( V_11 > 0 &&
V_104 -> V_107 >= V_105 [ V_11 - 1 ] . V_107 ) {
V_105 [ V_11 ] = V_105 [ V_11 - 1 ] ;
V_59 -> V_62 [ V_105 [ V_11 ] . V_26 ] = V_11 ;
V_11 -- ;
}
} else
F_125 ( V_11 != V_59 -> V_106 ) ;
V_105 [ V_11 ] = * V_104 ;
V_59 -> V_62 [ V_105 [ V_11 ] . V_26 ] = V_11 ;
}
static int F_126 ( const struct V_108 * V_109 )
{
T_4 V_110 = V_111 ;
#ifdef F_127
V_110 |= V_112 ;
#endif
if ( V_109 -> V_113 & ~ V_110 )
return - V_114 ;
return 0 ;
}
static struct V_58 * F_128 ( struct V_9 * V_9 ,
int V_115 , struct V_58 * V_59 )
{
struct V_58 * V_116 = F_129 ( V_9 , V_115 ) ;
F_124 ( V_116 -> V_60 & 1 ) ;
V_59 -> V_60 = V_116 -> V_60 + 1 ;
F_130 ( V_9 -> V_63 [ V_115 ] , V_59 ) ;
F_131 ( & V_9 -> V_47 ) ;
V_59 -> V_60 ++ ;
F_132 ( V_9 , V_59 ) ;
return V_116 ;
}
int F_133 ( struct V_9 * V_9 ,
const struct V_108 * V_109 )
{
int V_28 ;
T_5 V_107 ;
unsigned long V_68 ;
struct V_64 * V_117 ;
struct V_64 V_118 , V_104 ;
struct V_58 * V_59 = NULL , * V_116 ;
int V_115 , V_26 ;
enum V_119 V_120 ;
V_28 = F_126 ( V_109 ) ;
if ( V_28 )
goto V_121;
V_28 = - V_114 ;
V_115 = V_109 -> V_117 >> 16 ;
V_26 = ( V_122 ) V_109 -> V_117 ;
if ( V_109 -> V_123 & ( V_89 - 1 ) )
goto V_121;
if ( V_109 -> V_124 & ( V_89 - 1 ) )
goto V_121;
if ( ( V_26 < V_125 ) &&
( ( V_109 -> V_126 & ( V_89 - 1 ) ) ||
! F_134 ( V_127 ,
( void V_128 * ) ( unsigned long ) V_109 -> V_126 ,
V_109 -> V_123 ) ) )
goto V_121;
if ( V_115 >= V_72 || V_26 >= V_61 )
goto V_121;
if ( V_109 -> V_124 + V_109 -> V_123 < V_109 -> V_124 )
goto V_121;
V_117 = F_135 ( F_129 ( V_9 , V_115 ) , V_26 ) ;
V_107 = V_109 -> V_124 >> V_129 ;
V_68 = V_109 -> V_123 >> V_129 ;
if ( V_68 > V_130 )
goto V_121;
V_104 = V_118 = * V_117 ;
V_104 . V_26 = V_26 ;
V_104 . V_107 = V_107 ;
V_104 . V_68 = V_68 ;
V_104 . V_113 = V_109 -> V_113 ;
if ( V_68 ) {
if ( ! V_118 . V_68 )
V_120 = V_131 ;
else {
if ( ( V_109 -> V_126 != V_118 . V_126 ) ||
( V_68 != V_118 . V_68 ) ||
( ( V_104 . V_113 ^ V_118 . V_113 ) & V_112 ) )
goto V_121;
if ( V_107 != V_118 . V_107 )
V_120 = V_132 ;
else if ( V_104 . V_113 != V_118 . V_113 )
V_120 = V_133 ;
else {
V_28 = 0 ;
goto V_121;
}
}
} else {
if ( ! V_118 . V_68 )
goto V_121;
V_120 = V_134 ;
V_104 . V_107 = 0 ;
V_104 . V_113 = 0 ;
}
if ( ( V_120 == V_131 ) || ( V_120 == V_132 ) ) {
V_28 = - V_135 ;
F_79 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_117 -> V_26 >= V_125 ) ||
( V_117 -> V_26 == V_26 ) )
continue;
if ( ! ( ( V_107 + V_68 <= V_117 -> V_107 ) ||
( V_107 >= V_117 -> V_107 + V_117 -> V_68 ) ) )
goto V_121;
}
}
if ( ! ( V_104 . V_113 & V_111 ) )
V_104 . V_66 = NULL ;
V_28 = - V_35 ;
if ( V_120 == V_131 ) {
V_104 . V_126 = V_109 -> V_126 ;
if ( F_136 ( V_9 , & V_104 , V_68 ) )
goto V_136;
}
if ( ( V_104 . V_113 & V_111 ) && ! V_104 . V_66 ) {
if ( F_121 ( & V_104 ) < 0 )
goto V_136;
}
V_59 = F_73 ( sizeof( struct V_58 ) ) ;
if ( ! V_59 )
goto V_136;
memcpy ( V_59 , F_129 ( V_9 , V_115 ) , sizeof( struct V_58 ) ) ;
if ( ( V_120 == V_134 ) || ( V_120 == V_132 ) ) {
V_117 = F_135 ( V_59 , V_26 ) ;
V_117 -> V_113 |= V_137 ;
V_116 = F_128 ( V_9 , V_115 , V_59 ) ;
F_137 ( V_9 , & V_118 ) ;
F_138 ( V_9 , V_117 ) ;
V_59 = V_116 ;
}
V_28 = F_139 ( V_9 , & V_104 , V_109 , V_120 ) ;
if ( V_28 )
goto V_138;
if ( V_120 == V_134 ) {
V_104 . V_66 = NULL ;
memset ( & V_104 . V_139 , 0 , sizeof( V_104 . V_139 ) ) ;
}
F_123 ( V_59 , & V_104 ) ;
V_116 = F_128 ( V_9 , V_115 , V_59 ) ;
F_140 ( V_9 , V_109 , & V_118 , & V_104 , V_120 ) ;
F_76 ( V_9 , & V_118 , & V_104 ) ;
F_75 ( V_116 ) ;
if ( ( V_120 == V_131 ) || ( V_120 == V_132 ) ) {
V_28 = F_141 ( V_9 , & V_104 ) ;
return V_28 ;
}
return 0 ;
V_138:
F_75 ( V_59 ) ;
V_136:
F_76 ( V_9 , & V_104 , & V_118 ) ;
V_121:
return V_28 ;
}
int F_142 ( struct V_9 * V_9 ,
const struct V_108 * V_109 )
{
int V_28 ;
F_143 ( & V_9 -> V_83 ) ;
V_28 = F_133 ( V_9 , V_109 ) ;
F_16 ( & V_9 -> V_83 ) ;
return V_28 ;
}
static int F_144 ( struct V_9 * V_9 ,
struct V_108 * V_109 )
{
if ( ( V_122 ) V_109 -> V_117 >= V_125 )
return - V_114 ;
return F_142 ( V_9 , V_109 ) ;
}
int F_145 ( struct V_9 * V_9 ,
struct V_140 * log , int * V_141 )
{
struct V_58 * V_59 ;
struct V_64 * V_65 ;
int V_28 , V_11 , V_115 , V_26 ;
unsigned long V_142 ;
unsigned long V_143 = 0 ;
V_28 = - V_114 ;
V_115 = log -> V_117 >> 16 ;
V_26 = ( V_122 ) log -> V_117 ;
if ( V_115 >= V_72 || V_26 >= V_125 )
goto V_121;
V_59 = F_129 ( V_9 , V_115 ) ;
V_65 = F_135 ( V_59 , V_26 ) ;
V_28 = - V_144 ;
if ( ! V_65 -> V_66 )
goto V_121;
V_142 = F_122 ( V_65 ) ;
for ( V_11 = 0 ; ! V_143 && V_11 < V_142 / sizeof( long ) ; ++ V_11 )
V_143 = V_65 -> V_66 [ V_11 ] ;
V_28 = - V_145 ;
if ( F_146 ( log -> V_66 , V_65 -> V_66 , V_142 ) )
goto V_121;
if ( V_143 )
* V_141 = 1 ;
V_28 = 0 ;
V_121:
return V_28 ;
}
int F_147 ( struct V_9 * V_9 ,
struct V_140 * log , bool * V_141 )
{
struct V_58 * V_59 ;
struct V_64 * V_65 ;
int V_28 , V_11 , V_115 , V_26 ;
unsigned long V_142 ;
unsigned long * V_66 ;
unsigned long * V_146 ;
V_28 = - V_114 ;
V_115 = log -> V_117 >> 16 ;
V_26 = ( V_122 ) log -> V_117 ;
if ( V_115 >= V_72 || V_26 >= V_125 )
goto V_121;
V_59 = F_129 ( V_9 , V_115 ) ;
V_65 = F_135 ( V_59 , V_26 ) ;
V_66 = V_65 -> V_66 ;
V_28 = - V_144 ;
if ( ! V_66 )
goto V_121;
V_142 = F_122 ( V_65 ) ;
V_146 = V_66 + V_142 / sizeof( long ) ;
memset ( V_146 , 0 , V_142 ) ;
F_51 ( & V_9 -> V_48 ) ;
* V_141 = false ;
for ( V_11 = 0 ; V_11 < V_142 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_147 ;
T_5 V_148 ;
if ( ! V_66 [ V_11 ] )
continue;
* V_141 = true ;
V_147 = F_148 ( & V_66 [ V_11 ] , 0 ) ;
V_146 [ V_11 ] = V_147 ;
if ( V_147 ) {
V_148 = V_11 * V_149 ;
F_149 ( V_9 , V_65 ,
V_148 , V_147 ) ;
}
}
F_53 ( & V_9 -> V_48 ) ;
V_28 = - V_145 ;
if ( F_146 ( log -> V_66 , V_146 , V_142 ) )
goto V_121;
V_28 = 0 ;
V_121:
return V_28 ;
}
bool F_150 ( void )
{
return V_150 ;
}
void F_151 ( void )
{
V_150 = false ;
}
struct V_64 * F_152 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_153 ( V_58 ( V_9 ) , V_151 ) ;
}
struct V_64 * F_154 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_153 ( F_155 ( V_3 ) , V_151 ) ;
}
int F_156 ( struct V_9 * V_9 , T_5 V_151 )
{
struct V_64 * V_65 = F_152 ( V_9 , V_151 ) ;
if ( ! V_65 || V_65 -> V_26 >= V_125 ||
V_65 -> V_113 & V_137 )
return 0 ;
return 1 ;
}
unsigned long F_157 ( struct V_9 * V_9 , T_5 V_151 )
{
struct V_152 * V_153 ;
unsigned long V_154 , V_88 ;
V_88 = V_89 ;
V_154 = F_158 ( V_9 , V_151 ) ;
if ( F_159 ( V_154 ) )
return V_89 ;
F_160 ( & V_57 -> V_43 -> V_155 ) ;
V_153 = F_161 ( V_57 -> V_43 , V_154 ) ;
if ( ! V_153 )
goto V_121;
V_88 = F_162 ( V_153 ) ;
V_121:
F_163 ( & V_57 -> V_43 -> V_155 ) ;
return V_88 ;
}
static bool F_164 ( struct V_64 * V_117 )
{
return V_117 -> V_113 & V_112 ;
}
static unsigned long F_165 ( struct V_64 * V_117 , T_5 V_151 ,
T_5 * V_156 , bool V_157 )
{
if ( ! V_117 || V_117 -> V_113 & V_137 )
return V_158 ;
if ( F_164 ( V_117 ) && V_157 )
return V_159 ;
if ( V_156 )
* V_156 = V_117 -> V_68 - ( V_151 - V_117 -> V_107 ) ;
return F_166 ( V_117 , V_151 ) ;
}
static unsigned long F_167 ( struct V_64 * V_117 , T_5 V_151 ,
T_5 * V_156 )
{
return F_165 ( V_117 , V_151 , V_156 , true ) ;
}
unsigned long F_168 ( struct V_64 * V_117 ,
T_5 V_151 )
{
return F_167 ( V_117 , V_151 , NULL ) ;
}
unsigned long F_158 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_167 ( F_152 ( V_9 , V_151 ) , V_151 , NULL ) ;
}
unsigned long F_169 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_167 ( F_154 ( V_3 , V_151 ) , V_151 , NULL ) ;
}
unsigned long F_170 ( struct V_64 * V_117 ,
T_5 V_151 , bool * V_160 )
{
unsigned long V_161 = F_165 ( V_117 , V_151 , NULL , false ) ;
if ( ! F_159 ( V_161 ) && V_160 )
* V_160 = ! F_164 ( V_117 ) ;
return V_161 ;
}
unsigned long F_171 ( struct V_9 * V_9 , T_5 V_151 , bool * V_160 )
{
struct V_64 * V_117 = F_152 ( V_9 , V_151 ) ;
return F_170 ( V_117 , V_151 , V_160 ) ;
}
unsigned long F_172 ( struct V_2 * V_3 , T_5 V_151 , bool * V_160 )
{
struct V_64 * V_117 = F_154 ( V_3 , V_151 ) ;
return F_170 ( V_117 , V_151 , V_160 ) ;
}
static int F_173 ( struct V_162 * V_163 , struct V_42 * V_43 ,
unsigned long V_51 , int V_157 , struct V_27 * * V_27 )
{
int V_113 = V_164 | V_165 | V_166 | V_167 ;
if ( V_157 )
V_113 |= V_168 ;
return F_174 ( V_163 , V_43 , V_51 , 1 , V_113 , V_27 , NULL , NULL ) ;
}
static inline int F_175 ( unsigned long V_154 )
{
int V_169 , V_113 = V_164 | V_166 | V_168 ;
V_169 = F_174 ( V_57 , V_57 -> V_43 , V_154 , 1 ,
V_113 , NULL , NULL , NULL ) ;
return V_169 == - V_170 ;
}
static bool F_176 ( unsigned long V_154 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_160 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_68 ;
if ( ! ( V_172 || V_171 ) )
return false ;
if ( ! ( V_173 || V_160 ) )
return false ;
V_68 = F_177 ( V_154 , 1 , 1 , V_27 ) ;
if ( V_68 == 1 ) {
* V_1 = F_178 ( V_27 [ 0 ] ) ;
if ( V_160 )
* V_160 = true ;
return true ;
}
return false ;
}
static int F_179 ( unsigned long V_154 , bool * V_172 , bool V_173 ,
bool * V_160 , T_1 * V_1 )
{
struct V_27 * V_27 [ 1 ] ;
int V_68 = 0 ;
F_180 () ;
if ( V_160 )
* V_160 = V_173 ;
if ( V_172 ) {
F_160 ( & V_57 -> V_43 -> V_155 ) ;
V_68 = F_173 ( V_57 , V_57 -> V_43 ,
V_154 , V_173 , V_27 ) ;
F_163 ( & V_57 -> V_43 -> V_155 ) ;
} else
V_68 = F_181 ( V_57 , V_57 -> V_43 , V_154 , 1 ,
V_173 , 0 , V_27 ,
V_164 | V_166 ) ;
if ( V_68 != 1 )
return V_68 ;
if ( F_25 ( ! V_173 ) && V_160 ) {
struct V_27 * V_174 [ 1 ] ;
V_68 = F_177 ( V_154 , 1 , 1 , V_174 ) ;
if ( V_68 == 1 ) {
* V_160 = true ;
F_182 ( V_27 [ 0 ] ) ;
V_27 [ 0 ] = V_174 [ 0 ] ;
}
V_68 = 1 ;
}
* V_1 = F_178 ( V_27 [ 0 ] ) ;
return V_68 ;
}
static bool F_183 ( struct V_152 * V_153 , bool V_173 )
{
if ( F_25 ( ! ( V_153 -> V_175 & V_176 ) ) )
return false ;
if ( V_173 && ( F_25 ( ! ( V_153 -> V_175 & V_177 ) ) ) )
return false ;
return true ;
}
static T_1 F_184 ( unsigned long V_154 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_160 )
{
struct V_152 * V_153 ;
T_1 V_1 = 0 ;
int V_68 ;
F_62 ( V_171 && V_172 ) ;
if ( F_176 ( V_154 , V_171 , V_172 , V_173 , V_160 , & V_1 ) )
return V_1 ;
if ( V_171 )
return V_178 ;
V_68 = F_179 ( V_154 , V_172 , V_173 , V_160 , & V_1 ) ;
if ( V_68 == 1 )
return V_1 ;
F_160 ( & V_57 -> V_43 -> V_155 ) ;
if ( V_68 == - V_170 ||
( ! V_172 && F_175 ( V_154 ) ) ) {
V_1 = V_179 ;
goto exit;
}
V_153 = F_185 ( V_57 -> V_43 , V_154 , V_154 + 1 ) ;
if ( V_153 == NULL )
V_1 = V_178 ;
else if ( ( V_153 -> V_175 & V_180 ) ) {
V_1 = ( ( V_154 - V_153 -> V_181 ) >> V_129 ) +
V_153 -> V_182 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_172 && F_183 ( V_153 , V_173 ) )
* V_172 = true ;
V_1 = V_178 ;
}
exit:
F_163 ( & V_57 -> V_43 -> V_155 ) ;
return V_1 ;
}
T_1 F_186 ( struct V_64 * V_117 , T_5 V_151 , bool V_171 ,
bool * V_172 , bool V_173 , bool * V_160 )
{
unsigned long V_154 = F_165 ( V_117 , V_151 , NULL , V_173 ) ;
if ( V_154 == V_159 )
return V_183 ;
if ( F_159 ( V_154 ) )
return V_184 ;
if ( V_160 && F_164 ( V_117 ) ) {
* V_160 = false ;
V_160 = NULL ;
}
return F_184 ( V_154 , V_171 , V_172 , V_173 ,
V_160 ) ;
}
T_1 F_187 ( struct V_9 * V_9 , T_5 V_151 , bool V_173 ,
bool * V_160 )
{
return F_186 ( F_152 ( V_9 , V_151 ) , V_151 , false , NULL ,
V_173 , V_160 ) ;
}
T_1 F_188 ( struct V_64 * V_117 , T_5 V_151 )
{
return F_186 ( V_117 , V_151 , false , NULL , true , NULL ) ;
}
T_1 F_189 ( struct V_64 * V_117 , T_5 V_151 )
{
return F_186 ( V_117 , V_151 , true , NULL , true , NULL ) ;
}
T_1 F_190 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_189 ( F_152 ( V_9 , V_151 ) , V_151 ) ;
}
T_1 F_191 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_189 ( F_154 ( V_3 , V_151 ) , V_151 ) ;
}
T_1 F_192 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_188 ( F_152 ( V_9 , V_151 ) , V_151 ) ;
}
T_1 F_193 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_188 ( F_154 ( V_3 , V_151 ) , V_151 ) ;
}
int F_194 ( struct V_64 * V_117 , T_5 V_151 ,
struct V_27 * * V_185 , int V_156 )
{
unsigned long V_154 ;
T_5 V_186 ;
V_154 = F_167 ( V_117 , V_151 , & V_186 ) ;
if ( F_159 ( V_154 ) )
return - 1 ;
if ( V_186 < V_156 )
return 0 ;
return F_177 ( V_154 , V_156 , 1 , V_185 ) ;
}
static struct V_27 * F_195 ( T_1 V_1 )
{
if ( F_196 ( V_1 ) )
return V_187 ;
if ( F_1 ( V_1 ) ) {
F_124 ( 1 ) ;
return V_187 ;
}
return F_4 ( V_1 ) ;
}
struct V_27 * F_197 ( struct V_9 * V_9 , T_5 V_151 )
{
T_1 V_1 ;
V_1 = F_192 ( V_9 , V_151 ) ;
return F_195 ( V_1 ) ;
}
struct V_27 * F_198 ( struct V_2 * V_3 , T_5 V_151 )
{
T_1 V_1 ;
V_1 = F_193 ( V_3 , V_151 ) ;
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
static int F_210 ( unsigned long V_188 , int V_148 )
{
if ( V_188 > V_89 - V_148 )
return V_89 - V_148 ;
else
return V_188 ;
}
static int F_211 ( struct V_64 * V_117 , T_5 V_151 ,
void * V_189 , int V_148 , int V_188 )
{
int V_28 ;
unsigned long V_154 ;
V_154 = F_170 ( V_117 , V_151 , NULL ) ;
if ( F_159 ( V_154 ) )
return - V_145 ;
V_28 = F_212 ( V_189 , ( void V_128 * ) V_154 + V_148 , V_188 ) ;
if ( V_28 )
return - V_145 ;
return 0 ;
}
int F_213 ( struct V_9 * V_9 , T_5 V_151 , void * V_189 , int V_148 ,
int V_188 )
{
struct V_64 * V_117 = F_152 ( V_9 , V_151 ) ;
return F_211 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_214 ( struct V_2 * V_3 , T_5 V_151 , void * V_189 ,
int V_148 , int V_188 )
{
struct V_64 * V_117 = F_154 ( V_3 , V_151 ) ;
return F_211 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_215 ( struct V_9 * V_9 , T_6 V_190 , void * V_189 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_216 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_210 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_213 ( V_9 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
int F_217 ( struct V_2 * V_3 , T_6 V_190 , void * V_189 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_216 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_210 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_214 ( V_3 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
static int F_218 ( struct V_64 * V_117 , T_5 V_151 ,
void * V_189 , int V_148 , unsigned long V_188 )
{
int V_28 ;
unsigned long V_154 ;
V_154 = F_170 ( V_117 , V_151 , NULL ) ;
if ( F_159 ( V_154 ) )
return - V_145 ;
F_219 () ;
V_28 = F_220 ( V_189 , ( void V_128 * ) V_154 + V_148 , V_188 ) ;
F_221 () ;
if ( V_28 )
return - V_145 ;
return 0 ;
}
int F_222 ( struct V_9 * V_9 , T_6 V_190 , void * V_189 ,
unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
struct V_64 * V_117 = F_152 ( V_9 , V_151 ) ;
int V_148 = F_216 ( V_190 ) ;
return F_218 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_223 ( struct V_2 * V_3 , T_6 V_190 ,
void * V_189 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
struct V_64 * V_117 = F_154 ( V_3 , V_151 ) ;
int V_148 = F_216 ( V_190 ) ;
return F_218 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
static int F_224 ( struct V_64 * V_65 , T_5 V_151 ,
const void * V_189 , int V_148 , int V_188 )
{
int V_28 ;
unsigned long V_154 ;
V_154 = F_168 ( V_65 , V_151 ) ;
if ( F_159 ( V_154 ) )
return - V_145 ;
V_28 = F_225 ( ( void V_128 * ) V_154 + V_148 , V_189 , V_188 ) ;
if ( V_28 )
return - V_145 ;
F_226 ( V_65 , V_151 ) ;
return 0 ;
}
int F_227 ( struct V_9 * V_9 , T_5 V_151 ,
const void * V_189 , int V_148 , int V_188 )
{
struct V_64 * V_117 = F_152 ( V_9 , V_151 ) ;
return F_224 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_228 ( struct V_2 * V_3 , T_5 V_151 ,
const void * V_189 , int V_148 , int V_188 )
{
struct V_64 * V_117 = F_154 ( V_3 , V_151 ) ;
return F_224 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_229 ( struct V_9 * V_9 , T_6 V_190 , const void * V_189 ,
unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_216 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_210 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_227 ( V_9 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
int F_230 ( struct V_2 * V_3 , T_6 V_190 , const void * V_189 ,
unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_216 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_210 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_228 ( V_3 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
int F_231 ( struct V_9 * V_9 , struct V_193 * V_194 ,
T_6 V_190 , unsigned long V_188 )
{
struct V_58 * V_59 = V_58 ( V_9 ) ;
int V_148 = F_216 ( V_190 ) ;
T_5 V_195 = V_190 >> V_129 ;
T_5 V_196 = ( V_190 + V_188 - 1 ) >> V_129 ;
T_5 V_197 = V_196 - V_195 + 1 ;
T_5 V_198 ;
V_194 -> V_190 = V_190 ;
V_194 -> V_60 = V_59 -> V_60 ;
V_194 -> V_188 = V_188 ;
V_194 -> V_65 = F_152 ( V_9 , V_195 ) ;
V_194 -> V_161 = F_167 ( V_194 -> V_65 , V_195 , NULL ) ;
if ( ! F_159 ( V_194 -> V_161 ) && V_197 <= 1 ) {
V_194 -> V_161 += V_148 ;
} else {
while ( V_195 <= V_196 ) {
V_194 -> V_65 = F_152 ( V_9 , V_195 ) ;
V_194 -> V_161 = F_167 ( V_194 -> V_65 , V_195 ,
& V_198 ) ;
if ( F_159 ( V_194 -> V_161 ) )
return - V_145 ;
V_195 += V_198 ;
}
V_194 -> V_65 = NULL ;
}
return 0 ;
}
int F_232 ( struct V_9 * V_9 , struct V_193 * V_194 ,
void * V_189 , unsigned long V_188 )
{
struct V_58 * V_59 = V_58 ( V_9 ) ;
int V_28 ;
F_62 ( V_188 > V_194 -> V_188 ) ;
if ( V_59 -> V_60 != V_194 -> V_60 )
F_231 ( V_9 , V_194 , V_194 -> V_190 , V_194 -> V_188 ) ;
if ( F_25 ( ! V_194 -> V_65 ) )
return F_229 ( V_9 , V_194 -> V_190 , V_189 , V_188 ) ;
if ( F_159 ( V_194 -> V_161 ) )
return - V_145 ;
V_28 = F_225 ( ( void V_128 * ) V_194 -> V_161 , V_189 , V_188 ) ;
if ( V_28 )
return - V_145 ;
F_226 ( V_194 -> V_65 , V_194 -> V_190 >> V_129 ) ;
return 0 ;
}
int F_233 ( struct V_9 * V_9 , struct V_193 * V_194 ,
void * V_189 , unsigned long V_188 )
{
struct V_58 * V_59 = V_58 ( V_9 ) ;
int V_28 ;
F_62 ( V_188 > V_194 -> V_188 ) ;
if ( V_59 -> V_60 != V_194 -> V_60 )
F_231 ( V_9 , V_194 , V_194 -> V_190 , V_194 -> V_188 ) ;
if ( F_25 ( ! V_194 -> V_65 ) )
return F_215 ( V_9 , V_194 -> V_190 , V_189 , V_188 ) ;
if ( F_159 ( V_194 -> V_161 ) )
return - V_145 ;
V_28 = F_212 ( V_189 , ( void V_128 * ) V_194 -> V_161 , V_188 ) ;
if ( V_28 )
return - V_145 ;
return 0 ;
}
int F_234 ( struct V_9 * V_9 , T_5 V_151 , int V_148 , int V_188 )
{
const void * V_199 = ( const void * ) F_235 ( F_236 ( F_237 ( 0 ) ) ) ;
return F_227 ( V_9 , V_151 , V_199 , V_148 , V_188 ) ;
}
int F_238 ( struct V_9 * V_9 , T_6 V_190 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_216 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_210 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_234 ( V_9 , V_151 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
++ V_151 ;
}
return 0 ;
}
static void F_226 ( struct V_64 * V_65 ,
T_5 V_151 )
{
if ( V_65 && V_65 -> V_66 ) {
unsigned long V_200 = V_151 - V_65 -> V_107 ;
F_239 ( V_200 , V_65 -> V_66 ) ;
}
}
void F_240 ( struct V_9 * V_9 , T_5 V_151 )
{
struct V_64 * V_65 ;
V_65 = F_152 ( V_9 , V_151 ) ;
F_226 ( V_65 , V_151 ) ;
}
void F_241 ( struct V_2 * V_3 , T_5 V_151 )
{
struct V_64 * V_65 ;
V_65 = F_154 ( V_3 , V_151 ) ;
F_226 ( V_65 , V_151 ) ;
}
static void F_242 ( struct V_2 * V_3 )
{
int V_118 , V_201 ;
V_118 = V_201 = V_3 -> V_31 ;
if ( V_201 == 0 && V_202 )
V_201 = 10000 ;
else
V_201 *= V_202 ;
V_3 -> V_31 = V_201 ;
F_243 ( V_3 -> V_29 , V_201 , V_118 ) ;
}
static void F_244 ( struct V_2 * V_3 )
{
int V_118 , V_201 ;
V_118 = V_201 = V_3 -> V_31 ;
if ( V_203 == 0 )
V_201 = 0 ;
else
V_201 /= V_203 ;
V_3 -> V_31 = V_201 ;
F_245 ( V_3 -> V_29 , V_201 , V_118 ) ;
}
static int F_246 ( struct V_2 * V_3 )
{
if ( F_247 ( V_3 ) ) {
F_21 ( V_204 , V_3 ) ;
return - V_6 ;
}
if ( F_248 ( V_3 ) )
return - V_6 ;
if ( F_249 ( V_57 ) )
return - V_6 ;
return 0 ;
}
void F_250 ( struct V_2 * V_3 )
{
T_7 V_51 , V_205 ;
F_251 ( V_206 ) ;
bool V_207 = false ;
T_8 V_208 ;
V_51 = V_205 = F_252 () ;
if ( V_3 -> V_31 ) {
T_7 V_209 = F_253 ( F_252 () , V_3 -> V_31 ) ;
++ V_3 -> V_21 . V_210 ;
do {
if ( F_246 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_211 ;
goto V_121;
}
V_205 = F_252 () ;
} while ( F_254 () && F_255 ( V_205 , V_209 ) );
}
for (; ; ) {
F_256 ( & V_3 -> V_32 , & V_206 , V_212 ) ;
if ( F_246 ( V_3 ) < 0 )
break;
V_207 = true ;
F_257 () ;
}
F_258 ( & V_3 -> V_32 , & V_206 ) ;
V_205 = F_252 () ;
V_121:
V_208 = F_259 ( V_205 ) - F_259 ( V_51 ) ;
if ( V_31 ) {
if ( V_208 <= V_3 -> V_31 )
;
else if ( V_3 -> V_31 && V_208 > V_31 )
F_244 ( V_3 ) ;
else if ( V_3 -> V_31 < V_31 &&
V_208 < V_31 )
F_242 ( V_3 ) ;
} else
V_3 -> V_31 = 0 ;
F_260 ( V_208 , V_207 ) ;
}
void F_261 ( struct V_2 * V_3 )
{
int V_12 ;
int V_4 = V_3 -> V_4 ;
T_9 * V_213 ;
V_213 = F_262 ( V_3 ) ;
if ( F_263 ( V_213 ) ) {
F_264 ( V_213 ) ;
++ V_3 -> V_21 . V_214 ;
}
V_12 = F_7 () ;
if ( V_4 != V_12 && ( unsigned ) V_4 < V_215 && F_265 ( V_4 ) )
if ( F_266 ( V_3 ) )
F_267 ( V_4 ) ;
F_10 () ;
}
int F_268 ( struct V_2 * V_216 )
{
struct V_30 * V_30 ;
struct V_162 * V_217 = NULL ;
int V_192 = 0 ;
F_269 () ;
V_30 = F_270 ( V_216 -> V_30 ) ;
if ( V_30 )
V_217 = F_271 ( V_30 , V_218 ) ;
F_272 () ;
if ( ! V_217 )
return V_192 ;
V_192 = F_273 ( V_217 , 1 ) ;
F_274 ( V_217 ) ;
return V_192 ;
}
static bool F_275 ( struct V_2 * V_3 )
{
#ifdef F_276
bool V_219 ;
V_219 = ! V_3 -> V_220 . V_221 ||
V_3 -> V_220 . V_222 ;
if ( V_3 -> V_220 . V_221 )
F_41 ( V_3 , ! V_3 -> V_220 . V_222 ) ;
return V_219 ;
#else
return true ;
#endif
}
void F_277 ( struct V_2 * V_12 )
{
struct V_9 * V_9 = V_12 -> V_9 ;
struct V_2 * V_3 ;
int V_223 = V_12 -> V_9 -> V_223 ;
int V_224 = 0 ;
int V_225 = 3 ;
int V_226 ;
int V_11 ;
F_40 ( V_12 , true ) ;
for ( V_226 = 0 ; V_226 < 2 && ! V_224 && V_225 ; V_226 ++ ) {
F_20 (i, vcpu, kvm) {
if ( ! V_226 && V_11 <= V_223 ) {
V_11 = V_223 ;
continue;
} else if ( V_226 && V_11 > V_223 )
break;
if ( ! F_278 ( V_3 -> V_38 ) )
continue;
if ( V_3 == V_12 )
continue;
if ( F_263 ( & V_3 -> V_32 ) && ! F_247 ( V_3 ) )
continue;
if ( ! F_275 ( V_3 ) )
continue;
V_224 = F_268 ( V_3 ) ;
if ( V_224 > 0 ) {
V_9 -> V_223 = V_11 ;
break;
} else if ( V_224 < 0 ) {
V_225 -- ;
if ( ! V_225 )
break;
}
}
}
F_40 ( V_12 , false ) ;
F_41 ( V_12 , false ) ;
}
static int F_279 ( struct V_152 * V_153 , struct V_227 * V_228 )
{
struct V_2 * V_3 = V_153 -> V_229 -> V_102 ;
struct V_27 * V_27 ;
if ( V_228 -> V_230 == 0 )
V_27 = F_280 ( V_3 -> V_37 ) ;
#ifdef F_281
else if ( V_228 -> V_230 == V_231 )
V_27 = F_280 ( V_3 -> V_139 . V_232 ) ;
#endif
#ifdef F_282
else if ( V_228 -> V_230 == F_282 )
V_27 = F_280 ( V_3 -> V_9 -> V_233 ) ;
#endif
else
return F_283 ( V_3 , V_228 ) ;
F_209 ( V_27 ) ;
V_228 -> V_27 = V_27 ;
return 0 ;
}
static int F_284 ( struct V_100 * V_100 , struct V_152 * V_153 )
{
V_153 -> V_234 = & V_235 ;
return 0 ;
}
static int F_285 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
F_117 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_286 ( struct V_2 * V_3 )
{
return F_287 ( L_1 , & V_236 , V_3 , V_237 | V_238 ) ;
}
static int F_288 ( struct V_9 * V_9 , T_4 V_26 )
{
int V_28 ;
struct V_2 * V_3 , * V_239 ;
if ( V_26 >= V_240 )
return - V_114 ;
V_3 = F_289 ( V_9 , V_26 ) ;
if ( F_290 ( V_3 ) )
return F_291 ( V_3 ) ;
F_292 ( & V_3 -> V_7 , & V_241 ) ;
V_28 = F_293 ( V_3 ) ;
if ( V_28 )
goto V_242;
F_143 ( & V_9 -> V_81 ) ;
if ( ! F_294 ( V_3 ) ) {
V_28 = - V_114 ;
goto V_243;
}
if ( F_295 ( & V_9 -> V_244 ) == V_240 ) {
V_28 = - V_114 ;
goto V_243;
}
F_20 (r, v, kvm)
if ( V_239 -> V_29 == V_26 ) {
V_28 = - V_135 ;
goto V_243;
}
F_62 ( V_9 -> V_245 [ F_295 ( & V_9 -> V_244 ) ] ) ;
F_116 ( V_9 ) ;
V_28 = F_286 ( V_3 ) ;
if ( V_28 < 0 ) {
F_117 ( V_9 ) ;
goto V_243;
}
V_9 -> V_245 [ F_295 ( & V_9 -> V_244 ) ] = V_3 ;
F_61 () ;
F_91 ( & V_9 -> V_244 ) ;
F_16 ( & V_9 -> V_81 ) ;
F_296 ( V_3 ) ;
return V_28 ;
V_243:
F_16 ( & V_9 -> V_81 ) ;
V_242:
F_297 ( V_3 ) ;
return V_28 ;
}
static int F_298 ( struct V_2 * V_3 , T_10 * V_246 )
{
if ( V_246 ) {
F_299 ( V_246 , F_300 ( V_247 ) | F_300 ( V_248 ) ) ;
V_3 -> V_249 = 1 ;
V_3 -> V_246 = * V_246 ;
} else
V_3 -> V_249 = 0 ;
return 0 ;
}
static long F_301 ( struct V_100 * V_101 ,
unsigned int V_250 , unsigned long V_251 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
void V_128 * V_252 = ( void V_128 * ) V_251 ;
int V_28 ;
struct V_253 * V_254 = NULL ;
struct V_255 * V_255 = NULL ;
if ( V_3 -> V_9 -> V_43 != V_57 -> V_43 )
return - V_256 ;
if ( F_25 ( F_302 ( V_250 ) != V_257 ) )
return - V_114 ;
#if F_111 ( V_258 ) || F_111 ( V_259 ) || F_111 ( V_260 )
if ( V_250 == V_261 || V_250 == V_262 || V_250 == V_263 )
return F_303 ( V_101 , V_250 , V_251 ) ;
#endif
V_28 = F_5 ( V_3 ) ;
if ( V_28 )
return V_28 ;
switch ( V_250 ) {
case V_264 :
V_28 = - V_114 ;
if ( V_251 )
goto V_121;
if ( F_25 ( V_3 -> V_30 != V_57 -> V_265 [ V_218 ] . V_30 ) ) {
struct V_30 * V_266 = V_3 -> V_30 ;
struct V_30 * V_267 = F_304 ( V_57 , V_218 ) ;
F_130 ( V_3 -> V_30 , V_267 ) ;
if ( V_266 )
F_305 () ;
F_45 ( V_266 ) ;
}
V_28 = F_306 ( V_3 , V_3 -> V_37 ) ;
F_307 ( V_3 -> V_37 -> V_268 , V_28 ) ;
break;
case V_269 : {
struct V_270 * V_270 ;
V_28 = - V_35 ;
V_270 = F_89 ( sizeof( struct V_270 ) , V_33 ) ;
if ( ! V_270 )
goto V_121;
V_28 = F_308 ( V_3 , V_270 ) ;
if ( V_28 )
goto V_271;
V_28 = - V_145 ;
if ( F_146 ( V_252 , V_270 , sizeof( struct V_270 ) ) )
goto V_271;
V_28 = 0 ;
V_271:
F_99 ( V_270 ) ;
break;
}
case V_272 : {
struct V_270 * V_270 ;
V_28 = - V_35 ;
V_270 = F_309 ( V_252 , sizeof( * V_270 ) ) ;
if ( F_290 ( V_270 ) ) {
V_28 = F_291 ( V_270 ) ;
goto V_121;
}
V_28 = F_310 ( V_3 , V_270 ) ;
F_99 ( V_270 ) ;
break;
}
case V_273 : {
V_255 = F_89 ( sizeof( struct V_255 ) , V_33 ) ;
V_28 = - V_35 ;
if ( ! V_255 )
goto V_121;
V_28 = F_311 ( V_3 , V_255 ) ;
if ( V_28 )
goto V_121;
V_28 = - V_145 ;
if ( F_146 ( V_252 , V_255 , sizeof( struct V_255 ) ) )
goto V_121;
V_28 = 0 ;
break;
}
case V_274 : {
V_255 = F_309 ( V_252 , sizeof( * V_255 ) ) ;
if ( F_290 ( V_255 ) ) {
V_28 = F_291 ( V_255 ) ;
V_255 = NULL ;
goto V_121;
}
V_28 = F_312 ( V_3 , V_255 ) ;
break;
}
case V_275 : {
struct V_276 V_277 ;
V_28 = F_313 ( V_3 , & V_277 ) ;
if ( V_28 )
goto V_121;
V_28 = - V_145 ;
if ( F_146 ( V_252 , & V_277 , sizeof( V_277 ) ) )
goto V_121;
V_28 = 0 ;
break;
}
case V_278 : {
struct V_276 V_277 ;
V_28 = - V_145 ;
if ( F_314 ( & V_277 , V_252 , sizeof( V_277 ) ) )
goto V_121;
V_28 = F_315 ( V_3 , & V_277 ) ;
break;
}
case V_279 : {
struct V_280 V_281 ;
V_28 = - V_145 ;
if ( F_314 ( & V_281 , V_252 , sizeof( V_281 ) ) )
goto V_121;
V_28 = F_316 ( V_3 , & V_281 ) ;
if ( V_28 )
goto V_121;
V_28 = - V_145 ;
if ( F_146 ( V_252 , & V_281 , sizeof( V_281 ) ) )
goto V_121;
V_28 = 0 ;
break;
}
case V_282 : {
struct V_283 V_284 ;
V_28 = - V_145 ;
if ( F_314 ( & V_284 , V_252 , sizeof( V_284 ) ) )
goto V_121;
V_28 = F_317 ( V_3 , & V_284 ) ;
break;
}
case V_285 : {
struct V_286 V_128 * V_287 = V_252 ;
struct V_286 V_288 ;
T_10 V_246 , * V_289 ;
V_289 = NULL ;
if ( V_252 ) {
V_28 = - V_145 ;
if ( F_314 ( & V_288 , V_252 ,
sizeof( V_288 ) ) )
goto V_121;
V_28 = - V_114 ;
if ( V_288 . V_188 != sizeof( V_246 ) )
goto V_121;
V_28 = - V_145 ;
if ( F_314 ( & V_246 , V_287 -> V_246 ,
sizeof( V_246 ) ) )
goto V_121;
V_289 = & V_246 ;
}
V_28 = F_298 ( V_3 , V_289 ) ;
break;
}
case V_290 : {
V_254 = F_89 ( sizeof( struct V_253 ) , V_33 ) ;
V_28 = - V_35 ;
if ( ! V_254 )
goto V_121;
V_28 = F_318 ( V_3 , V_254 ) ;
if ( V_28 )
goto V_121;
V_28 = - V_145 ;
if ( F_146 ( V_252 , V_254 , sizeof( struct V_253 ) ) )
goto V_121;
V_28 = 0 ;
break;
}
case V_291 : {
V_254 = F_309 ( V_252 , sizeof( * V_254 ) ) ;
if ( F_290 ( V_254 ) ) {
V_28 = F_291 ( V_254 ) ;
V_254 = NULL ;
goto V_121;
}
V_28 = F_319 ( V_3 , V_254 ) ;
break;
}
default:
V_28 = F_303 ( V_101 , V_250 , V_251 ) ;
}
V_121:
F_11 ( V_3 ) ;
F_99 ( V_254 ) ;
F_99 ( V_255 ) ;
return V_28 ;
}
static long F_320 ( struct V_100 * V_101 ,
unsigned int V_250 , unsigned long V_251 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
void V_128 * V_252 = F_321 ( V_251 ) ;
int V_28 ;
if ( V_3 -> V_9 -> V_43 != V_57 -> V_43 )
return - V_256 ;
switch ( V_250 ) {
case V_285 : {
struct V_286 V_128 * V_287 = V_252 ;
struct V_286 V_288 ;
T_11 V_292 ;
T_10 V_246 ;
if ( V_252 ) {
V_28 = - V_145 ;
if ( F_314 ( & V_288 , V_252 ,
sizeof( V_288 ) ) )
goto V_121;
V_28 = - V_114 ;
if ( V_288 . V_188 != sizeof( V_292 ) )
goto V_121;
V_28 = - V_145 ;
if ( F_314 ( & V_292 , V_287 -> V_246 ,
sizeof( V_292 ) ) )
goto V_121;
F_322 ( & V_246 , & V_292 ) ;
V_28 = F_298 ( V_3 , & V_246 ) ;
} else
V_28 = F_298 ( V_3 , NULL ) ;
break;
}
default:
V_28 = F_301 ( V_101 , V_250 , V_251 ) ;
}
V_121:
return V_28 ;
}
static int F_323 ( struct V_93 * V_94 ,
int (* F_324)( struct V_93 * V_94 ,
struct V_293 * V_294 ) ,
unsigned long V_251 )
{
struct V_293 V_294 ;
if ( ! F_324 )
return - V_295 ;
if ( F_314 ( & V_294 , ( void V_128 * ) V_251 , sizeof( V_294 ) ) )
return - V_145 ;
return F_324 ( V_94 , & V_294 ) ;
}
static long F_325 ( struct V_100 * V_101 , unsigned int V_250 ,
unsigned long V_251 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
switch ( V_250 ) {
case V_296 :
return F_323 ( V_94 , V_94 -> V_55 -> V_297 , V_251 ) ;
case V_298 :
return F_323 ( V_94 , V_94 -> V_55 -> V_299 , V_251 ) ;
case V_300 :
return F_323 ( V_94 , V_94 -> V_55 -> V_301 , V_251 ) ;
default:
if ( V_94 -> V_55 -> V_250 )
return V_94 -> V_55 -> V_250 ( V_94 , V_250 , V_251 ) ;
return - V_302 ;
}
}
static int F_326 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
struct V_9 * V_9 = V_94 -> V_9 ;
F_117 ( V_9 ) ;
return 0 ;
}
struct V_93 * F_327 ( struct V_100 * V_101 )
{
if ( V_101 -> V_303 != & V_304 )
return NULL ;
return V_101 -> V_102 ;
}
int F_328 ( struct V_305 * V_55 , T_4 type )
{
if ( type >= F_329 ( V_306 ) )
return - V_307 ;
if ( V_306 [ type ] != NULL )
return - V_135 ;
V_306 [ type ] = V_55 ;
return 0 ;
}
void F_330 ( T_4 type )
{
if ( V_306 [ type ] != NULL )
V_306 [ type ] = NULL ;
}
static int F_331 ( struct V_9 * V_9 ,
struct V_308 * V_309 )
{
struct V_305 * V_55 = NULL ;
struct V_93 * V_94 ;
bool V_310 = V_309 -> V_113 & V_311 ;
int V_192 ;
if ( V_309 -> type >= F_329 ( V_306 ) )
return - V_312 ;
V_55 = V_306 [ V_309 -> type ] ;
if ( V_55 == NULL )
return - V_312 ;
if ( V_310 )
return 0 ;
V_94 = F_89 ( sizeof( * V_94 ) , V_33 ) ;
if ( ! V_94 )
return - V_35 ;
V_94 -> V_55 = V_55 ;
V_94 -> V_9 = V_9 ;
V_192 = V_55 -> V_313 ( V_94 , V_309 -> type ) ;
if ( V_192 < 0 ) {
F_99 ( V_94 ) ;
return V_192 ;
}
V_192 = F_287 ( V_55 -> V_314 , & V_304 , V_94 , V_237 | V_238 ) ;
if ( V_192 < 0 ) {
V_55 -> V_96 ( V_94 ) ;
return V_192 ;
}
F_95 ( & V_94 -> V_95 , & V_9 -> V_85 ) ;
F_116 ( V_9 ) ;
V_309 -> V_315 = V_192 ;
return 0 ;
}
static long F_332 ( struct V_9 * V_9 , long V_251 )
{
switch ( V_251 ) {
case V_316 :
case V_317 :
case V_318 :
case V_319 :
#ifdef F_333
case V_320 :
#endif
#ifdef F_85
case V_321 :
case V_322 :
#endif
case V_323 :
return 1 ;
#ifdef F_334
case V_324 :
return V_325 ;
#endif
#if V_72 > 1
case V_326 :
return V_72 ;
#endif
default:
break;
}
return F_335 ( V_9 , V_251 ) ;
}
static long F_336 ( struct V_100 * V_101 ,
unsigned int V_250 , unsigned long V_251 )
{
struct V_9 * V_9 = V_101 -> V_102 ;
void V_128 * V_252 = ( void V_128 * ) V_251 ;
int V_28 ;
if ( V_9 -> V_43 != V_57 -> V_43 )
return - V_256 ;
switch ( V_250 ) {
case V_327 :
V_28 = F_288 ( V_9 , V_251 ) ;
break;
case V_328 : {
struct V_108 V_329 ;
V_28 = - V_145 ;
if ( F_314 ( & V_329 , V_252 ,
sizeof( V_329 ) ) )
goto V_121;
V_28 = F_144 ( V_9 , & V_329 ) ;
break;
}
case V_330 : {
struct V_140 log ;
V_28 = - V_145 ;
if ( F_314 ( & log , V_252 , sizeof( log ) ) )
goto V_121;
V_28 = F_337 ( V_9 , & log ) ;
break;
}
#ifdef F_282
case V_331 : {
struct V_332 V_333 ;
V_28 = - V_145 ;
if ( F_314 ( & V_333 , V_252 , sizeof( V_333 ) ) )
goto V_121;
V_28 = F_338 ( V_9 , & V_333 ) ;
break;
}
case V_334 : {
struct V_332 V_333 ;
V_28 = - V_145 ;
if ( F_314 ( & V_333 , V_252 , sizeof( V_333 ) ) )
goto V_121;
V_28 = F_339 ( V_9 , & V_333 ) ;
break;
}
#endif
case V_335 : {
struct V_336 V_189 ;
V_28 = - V_145 ;
if ( F_314 ( & V_189 , V_252 , sizeof( V_189 ) ) )
goto V_121;
V_28 = V_336 ( V_9 , & V_189 ) ;
break;
}
case V_337 : {
struct V_338 V_189 ;
V_28 = - V_145 ;
if ( F_314 ( & V_189 , V_252 , sizeof( V_189 ) ) )
goto V_121;
V_28 = V_338 ( V_9 , & V_189 ) ;
break;
}
#ifdef F_333
case V_339 : {
struct V_340 V_341 ;
V_28 = - V_145 ;
if ( F_314 ( & V_341 , V_252 , sizeof( V_341 ) ) )
goto V_121;
V_28 = F_340 ( V_9 , & V_341 ) ;
break;
}
#endif
#ifdef F_341
case V_342 :
case V_343 : {
struct V_344 V_345 ;
V_28 = - V_145 ;
if ( F_314 ( & V_345 , V_252 , sizeof( V_345 ) ) )
goto V_121;
V_28 = F_342 ( V_9 , & V_345 ,
V_250 == V_342 ) ;
if ( V_28 )
goto V_121;
V_28 = - V_145 ;
if ( V_250 == V_342 ) {
if ( F_146 ( V_252 , & V_345 , sizeof( V_345 ) ) )
goto V_121;
}
V_28 = 0 ;
break;
}
#endif
#ifdef F_334
case V_346 : {
struct V_347 V_348 ;
struct V_347 V_128 * V_349 ;
struct V_350 * V_351 ;
V_28 = - V_145 ;
if ( F_314 ( & V_348 , V_252 , sizeof( V_348 ) ) )
goto V_121;
V_28 = - V_114 ;
if ( V_348 . V_352 >= V_325 )
goto V_121;
if ( V_348 . V_113 )
goto V_121;
V_28 = - V_35 ;
V_351 = F_343 ( V_348 . V_352 * sizeof( * V_351 ) ) ;
if ( ! V_351 )
goto V_121;
V_28 = - V_145 ;
V_349 = V_252 ;
if ( F_314 ( V_351 , V_349 -> V_351 ,
V_348 . V_352 * sizeof( * V_351 ) ) )
goto V_353;
V_28 = F_344 ( V_9 , V_351 , V_348 . V_352 ,
V_348 . V_113 ) ;
V_353:
F_345 ( V_351 ) ;
break;
}
#endif
case V_354 : {
struct V_308 V_309 ;
V_28 = - V_145 ;
if ( F_314 ( & V_309 , V_252 , sizeof( V_309 ) ) )
goto V_121;
V_28 = F_331 ( V_9 , & V_309 ) ;
if ( V_28 )
goto V_121;
V_28 = - V_145 ;
if ( F_146 ( V_252 , & V_309 , sizeof( V_309 ) ) )
goto V_121;
V_28 = 0 ;
break;
}
case V_355 :
V_28 = F_332 ( V_9 , V_251 ) ;
break;
default:
V_28 = F_346 ( V_101 , V_250 , V_251 ) ;
}
V_121:
return V_28 ;
}
static long F_347 ( struct V_100 * V_101 ,
unsigned int V_250 , unsigned long V_251 )
{
struct V_9 * V_9 = V_101 -> V_102 ;
int V_28 ;
if ( V_9 -> V_43 != V_57 -> V_43 )
return - V_256 ;
switch ( V_250 ) {
case V_330 : {
struct V_356 V_357 ;
struct V_140 log ;
V_28 = - V_145 ;
if ( F_314 ( & V_357 , ( void V_128 * ) V_251 ,
sizeof( V_357 ) ) )
goto V_121;
log . V_117 = V_357 . V_117 ;
log . V_358 = V_357 . V_358 ;
log . V_359 = V_357 . V_359 ;
log . V_66 = F_321 ( V_357 . V_66 ) ;
V_28 = F_337 ( V_9 , & log ) ;
break;
}
default:
V_28 = F_336 ( V_101 , V_250 , V_251 ) ;
}
V_121:
return V_28 ;
}
static int F_348 ( unsigned long type )
{
int V_28 ;
struct V_9 * V_9 ;
V_9 = F_80 ( type ) ;
if ( F_290 ( V_9 ) )
return F_291 ( V_9 ) ;
#ifdef F_282
V_28 = F_349 ( V_9 ) ;
if ( V_28 < 0 ) {
F_117 ( V_9 ) ;
return V_28 ;
}
#endif
V_28 = F_287 ( L_2 , & V_360 , V_9 , V_237 | V_238 ) ;
if ( V_28 < 0 )
F_117 ( V_9 ) ;
return V_28 ;
}
static long F_350 ( struct V_100 * V_101 ,
unsigned int V_250 , unsigned long V_251 )
{
long V_28 = - V_114 ;
switch ( V_250 ) {
case V_361 :
if ( V_251 )
goto V_121;
V_28 = V_362 ;
break;
case V_363 :
V_28 = F_348 ( V_251 ) ;
break;
case V_355 :
V_28 = F_332 ( NULL , V_251 ) ;
break;
case V_364 :
if ( V_251 )
goto V_121;
V_28 = V_89 ;
#ifdef F_281
V_28 += V_89 ;
#endif
#ifdef F_282
V_28 += V_89 ;
#endif
break;
case V_365 :
case V_366 :
case V_367 :
V_28 = - V_368 ;
break;
default:
return F_351 ( V_101 , V_250 , V_251 ) ;
}
V_121:
return V_28 ;
}
static void F_352 ( void * V_369 )
{
int V_4 = F_353 () ;
int V_28 ;
if ( F_354 ( V_4 , V_370 ) )
return;
F_24 ( V_4 , V_370 ) ;
V_28 = F_355 () ;
if ( V_28 ) {
F_356 ( V_4 , V_370 ) ;
F_91 ( & V_371 ) ;
F_357 ( L_3 , V_4 ) ;
}
}
static void F_358 ( void )
{
F_359 ( & V_372 ) ;
if ( V_373 )
F_352 ( NULL ) ;
F_360 ( & V_372 ) ;
}
static void F_361 ( void * V_369 )
{
int V_4 = F_353 () ;
if ( ! F_354 ( V_4 , V_370 ) )
return;
F_356 ( V_4 , V_370 ) ;
F_362 () ;
}
static void F_363 ( void )
{
F_359 ( & V_372 ) ;
if ( V_373 )
F_361 ( NULL ) ;
F_360 ( & V_372 ) ;
}
static void F_364 ( void )
{
F_62 ( ! V_373 ) ;
V_373 -- ;
if ( ! V_373 )
F_365 ( F_361 , NULL , 1 ) ;
}
static void F_98 ( void )
{
F_359 ( & V_372 ) ;
F_364 () ;
F_360 ( & V_372 ) ;
}
static int F_84 ( void )
{
int V_28 = 0 ;
F_359 ( & V_372 ) ;
V_373 ++ ;
if ( V_373 == 1 ) {
F_93 ( & V_371 , 0 ) ;
F_365 ( F_352 , NULL , 1 ) ;
if ( F_295 ( & V_371 ) ) {
F_364 () ;
V_28 = - V_374 ;
}
}
F_360 ( & V_372 ) ;
return V_28 ;
}
static int F_366 ( struct V_375 * V_376 , unsigned long V_201 ,
void * V_239 )
{
V_201 &= ~ V_377 ;
switch ( V_201 ) {
case V_378 :
F_363 () ;
break;
case V_379 :
F_358 () ;
break;
}
return V_380 ;
}
static int F_367 ( struct V_375 * V_376 , unsigned long V_201 ,
void * V_239 )
{
F_357 ( L_4 ) ;
V_381 = true ;
F_365 ( F_361 , NULL , 1 ) ;
return V_380 ;
}
static void F_109 ( struct V_78 * V_382 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_382 -> V_383 ; V_11 ++ ) {
struct V_384 * V_385 = V_382 -> V_386 [ V_11 ] . V_94 ;
F_368 ( V_385 ) ;
}
F_99 ( V_382 ) ;
}
static inline int F_369 ( const struct V_387 * V_388 ,
const struct V_387 * V_389 )
{
T_6 V_390 = V_388 -> V_154 ;
T_6 V_391 = V_389 -> V_154 ;
if ( V_390 < V_391 )
return - 1 ;
if ( V_389 -> V_188 ) {
V_390 += V_388 -> V_188 ;
V_391 += V_389 -> V_188 ;
}
if ( V_390 > V_391 )
return 1 ;
return 0 ;
}
static int F_370 ( const void * V_392 , const void * V_393 )
{
return F_369 ( V_392 , V_393 ) ;
}
static int F_371 ( struct V_78 * V_382 , struct V_384 * V_94 ,
T_6 V_154 , int V_188 )
{
V_382 -> V_386 [ V_382 -> V_383 ++ ] = (struct V_387 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
. V_94 = V_94 ,
} ;
F_372 ( V_382 -> V_386 , V_382 -> V_383 , sizeof( struct V_387 ) ,
F_370 , NULL ) ;
return 0 ;
}
static int F_373 ( struct V_78 * V_382 ,
T_6 V_154 , int V_188 )
{
struct V_387 * V_386 , V_394 ;
int V_395 ;
V_394 = (struct V_387 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_386 = bsearch ( & V_394 , V_382 -> V_386 , V_382 -> V_383 ,
sizeof( struct V_387 ) , F_370 ) ;
if ( V_386 == NULL )
return - V_144 ;
V_395 = V_386 - V_382 -> V_386 ;
while ( V_395 > 0 && F_369 ( & V_394 , & V_382 -> V_386 [ V_395 - 1 ] ) == 0 )
V_395 -- ;
return V_395 ;
}
static int F_374 ( struct V_2 * V_3 , struct V_78 * V_382 ,
struct V_387 * V_386 , const void * V_201 )
{
int V_46 ;
V_46 = F_373 ( V_382 , V_386 -> V_154 , V_386 -> V_188 ) ;
if ( V_46 < 0 )
return - V_368 ;
while ( V_46 < V_382 -> V_383 &&
F_369 ( V_386 , & V_382 -> V_386 [ V_46 ] ) == 0 ) {
if ( ! F_375 ( V_3 , V_382 -> V_386 [ V_46 ] . V_94 , V_386 -> V_154 ,
V_386 -> V_188 , V_201 ) )
return V_46 ;
V_46 ++ ;
}
return - V_368 ;
}
int F_376 ( struct V_2 * V_3 , enum V_396 V_397 , T_6 V_154 ,
int V_188 , const void * V_201 )
{
struct V_78 * V_382 ;
struct V_387 V_386 ;
int V_28 ;
V_386 = (struct V_387 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_382 = F_377 ( V_3 -> V_9 -> V_77 [ V_397 ] , & V_3 -> V_9 -> V_47 ) ;
V_28 = F_374 ( V_3 , V_382 , & V_386 , V_201 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_378 ( struct V_2 * V_3 , enum V_396 V_397 ,
T_6 V_154 , int V_188 , const void * V_201 , long V_398 )
{
struct V_78 * V_382 ;
struct V_387 V_386 ;
V_386 = (struct V_387 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_382 = F_377 ( V_3 -> V_9 -> V_77 [ V_397 ] , & V_3 -> V_9 -> V_47 ) ;
if ( ( V_398 >= 0 ) && ( V_398 < V_382 -> V_383 ) &&
( F_369 ( & V_386 , & V_382 -> V_386 [ V_398 ] ) == 0 ) )
if ( ! F_375 ( V_3 , V_382 -> V_386 [ V_398 ] . V_94 , V_154 , V_188 ,
V_201 ) )
return V_398 ;
return F_374 ( V_3 , V_382 , & V_386 , V_201 ) ;
}
static int F_379 ( struct V_2 * V_3 , struct V_78 * V_382 ,
struct V_387 * V_386 , void * V_201 )
{
int V_46 ;
V_46 = F_373 ( V_382 , V_386 -> V_154 , V_386 -> V_188 ) ;
if ( V_46 < 0 )
return - V_368 ;
while ( V_46 < V_382 -> V_383 &&
F_369 ( V_386 , & V_382 -> V_386 [ V_46 ] ) == 0 ) {
if ( ! F_380 ( V_3 , V_382 -> V_386 [ V_46 ] . V_94 , V_386 -> V_154 ,
V_386 -> V_188 , V_201 ) )
return V_46 ;
V_46 ++ ;
}
return - V_368 ;
}
int F_381 ( struct V_2 * V_3 , enum V_396 V_397 , T_6 V_154 ,
int V_188 , void * V_201 )
{
struct V_78 * V_382 ;
struct V_387 V_386 ;
int V_28 ;
V_386 = (struct V_387 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_382 = F_377 ( V_3 -> V_9 -> V_77 [ V_397 ] , & V_3 -> V_9 -> V_47 ) ;
V_28 = F_379 ( V_3 , V_382 , & V_386 , V_201 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
int F_382 ( struct V_9 * V_9 , enum V_396 V_397 , T_6 V_154 ,
int V_188 , struct V_384 * V_94 )
{
struct V_78 * V_399 , * V_382 ;
V_382 = V_9 -> V_77 [ V_397 ] ;
if ( V_382 -> V_383 - V_382 -> V_400 > V_401 - 1 )
return - V_307 ;
V_399 = F_89 ( sizeof( * V_382 ) + ( ( V_382 -> V_383 + 1 ) *
sizeof( struct V_387 ) ) , V_33 ) ;
if ( ! V_399 )
return - V_35 ;
memcpy ( V_399 , V_382 , sizeof( * V_382 ) + ( V_382 -> V_383 *
sizeof( struct V_387 ) ) ) ;
F_371 ( V_399 , V_94 , V_154 , V_188 ) ;
F_130 ( V_9 -> V_77 [ V_397 ] , V_399 ) ;
F_131 ( & V_9 -> V_47 ) ;
F_99 ( V_382 ) ;
return 0 ;
}
int F_383 ( struct V_9 * V_9 , enum V_396 V_397 ,
struct V_384 * V_94 )
{
int V_11 , V_28 ;
struct V_78 * V_399 , * V_382 ;
V_382 = V_9 -> V_77 [ V_397 ] ;
V_28 = - V_144 ;
for ( V_11 = 0 ; V_11 < V_382 -> V_383 ; V_11 ++ )
if ( V_382 -> V_386 [ V_11 ] . V_94 == V_94 ) {
V_28 = 0 ;
break;
}
if ( V_28 )
return V_28 ;
V_399 = F_89 ( sizeof( * V_382 ) + ( ( V_382 -> V_383 - 1 ) *
sizeof( struct V_387 ) ) , V_33 ) ;
if ( ! V_399 )
return - V_35 ;
memcpy ( V_399 , V_382 , sizeof( * V_382 ) + V_11 * sizeof( struct V_387 ) ) ;
V_399 -> V_383 -- ;
memcpy ( V_399 -> V_386 + V_11 , V_382 -> V_386 + V_11 + 1 ,
( V_399 -> V_383 - V_11 ) * sizeof( struct V_387 ) ) ;
F_130 ( V_9 -> V_77 [ V_397 ] , V_399 ) ;
F_131 ( & V_9 -> V_47 ) ;
F_99 ( V_382 ) ;
return V_28 ;
}
static int F_384 ( void * V_402 , T_8 * V_201 )
{
unsigned V_148 = ( long ) V_402 ;
struct V_9 * V_9 ;
* V_201 = 0 ;
F_51 ( & V_86 ) ;
F_385 ( V_9 , & V_87 , V_87 )
* V_201 += * ( T_4 * ) ( ( void * ) V_9 + V_148 ) ;
F_53 ( & V_86 ) ;
return 0 ;
}
static int F_386 ( void * V_402 , T_8 * V_201 )
{
unsigned V_148 = ( long ) V_402 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_201 = 0 ;
F_51 ( & V_86 ) ;
F_385 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_201 += * ( T_4 * ) ( ( void * ) V_3 + V_148 ) ;
F_53 ( & V_86 ) ;
return 0 ;
}
static int F_387 ( void )
{
int V_28 = - V_135 ;
struct V_403 * V_289 ;
V_404 = F_388 ( L_5 , NULL ) ;
if ( V_404 == NULL )
goto V_121;
for ( V_289 = V_405 ; V_289 -> V_314 ; ++ V_289 ) {
V_289 -> V_406 = F_389 ( V_289 -> V_314 , 0444 , V_404 ,
( void * ) ( long ) V_289 -> V_148 ,
V_407 [ V_289 -> V_408 ] ) ;
if ( V_289 -> V_406 == NULL )
goto V_409;
}
return 0 ;
V_409:
F_390 ( V_404 ) ;
V_121:
return V_28 ;
}
static void F_391 ( void )
{
struct V_403 * V_289 ;
for ( V_289 = V_405 ; V_289 -> V_314 ; ++ V_289 )
F_392 ( V_289 -> V_406 ) ;
F_392 ( V_404 ) ;
}
static int F_393 ( void )
{
if ( V_373 )
F_361 ( NULL ) ;
return 0 ;
}
static void F_394 ( void )
{
if ( V_373 ) {
F_124 ( F_395 ( & V_372 ) ) ;
F_352 ( NULL ) ;
}
}
static inline
struct V_2 * F_396 ( struct V_7 * V_410 )
{
return F_48 ( V_410 , struct V_2 , V_7 ) ;
}
static void F_397 ( struct V_7 * V_410 , int V_4 )
{
struct V_2 * V_3 = F_396 ( V_410 ) ;
if ( V_3 -> V_38 )
V_3 -> V_38 = false ;
F_398 ( V_3 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
}
static void F_399 ( struct V_7 * V_410 ,
struct V_162 * V_411 )
{
struct V_2 * V_3 = F_396 ( V_410 ) ;
if ( V_57 -> V_412 == V_413 )
V_3 -> V_38 = true ;
F_13 ( V_3 ) ;
}
int F_400 ( void * V_414 , unsigned V_415 , unsigned V_416 ,
struct V_417 * V_417 )
{
int V_28 ;
int V_4 ;
V_28 = F_401 ( V_414 ) ;
if ( V_28 )
goto V_418;
V_28 = F_402 () ;
if ( V_28 )
goto V_419;
if ( ! F_19 ( & V_370 , V_33 ) ) {
V_28 = - V_35 ;
goto V_420;
}
V_28 = F_403 () ;
if ( V_28 < 0 )
goto V_421;
F_404 (cpu) {
F_405 ( V_4 ,
V_422 ,
& V_28 , 1 ) ;
if ( V_28 < 0 )
goto V_423;
}
V_28 = F_406 ( & V_424 ) ;
if ( V_28 )
goto V_425;
F_407 ( & V_426 ) ;
if ( ! V_416 )
V_416 = F_408 ( struct V_2 ) ;
V_427 = F_409 ( L_6 , V_415 , V_416 ,
0 , NULL ) ;
if ( ! V_427 ) {
V_28 = - V_35 ;
goto V_428;
}
V_28 = F_410 () ;
if ( V_28 )
goto V_136;
V_429 . V_430 = V_417 ;
V_360 . V_430 = V_417 ;
V_236 . V_430 = V_417 ;
V_28 = F_411 ( & V_431 ) ;
if ( V_28 ) {
F_412 ( L_7 ) ;
goto V_432;
}
F_413 ( & V_433 ) ;
V_241 . V_434 = F_397 ;
V_241 . V_435 = F_399 ;
V_28 = F_387 () ;
if ( V_28 ) {
F_412 ( L_8 ) ;
goto V_436;
}
V_28 = F_414 () ;
F_124 ( V_28 ) ;
return 0 ;
V_436:
F_415 ( & V_433 ) ;
F_416 ( & V_431 ) ;
V_432:
F_417 () ;
V_136:
F_418 ( V_427 ) ;
V_428:
F_419 ( & V_426 ) ;
F_420 ( & V_424 ) ;
V_425:
V_423:
F_421 () ;
V_421:
F_28 ( V_370 ) ;
V_420:
F_422 () ;
V_419:
F_423 () ;
V_418:
return V_28 ;
}
void F_424 ( void )
{
F_391 () ;
F_416 ( & V_431 ) ;
F_418 ( V_427 ) ;
F_417 () ;
F_415 ( & V_433 ) ;
F_419 ( & V_426 ) ;
F_420 ( & V_424 ) ;
F_365 ( F_361 , NULL , 1 ) ;
F_421 () ;
F_423 () ;
F_422 () ;
F_28 ( V_370 ) ;
F_425 () ;
}
