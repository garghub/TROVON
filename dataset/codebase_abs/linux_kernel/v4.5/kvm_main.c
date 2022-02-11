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
int F_32 ( struct V_2 * V_3 , struct V_9 * V_9 , unsigned V_24 )
{
struct V_25 * V_25 ;
int V_26 ;
F_33 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_27 = V_24 ;
V_3 -> V_28 = NULL ;
V_3 -> V_29 = 0 ;
F_34 ( & V_3 -> V_30 ) ;
F_35 ( V_3 ) ;
V_3 -> V_31 = - 1 ;
F_36 ( & V_3 -> V_32 ) ;
V_25 = F_37 ( V_33 | V_34 ) ;
if ( ! V_25 ) {
V_26 = - V_35 ;
goto V_36;
}
V_3 -> V_37 = F_38 ( V_25 ) ;
F_39 ( V_3 , false ) ;
F_40 ( V_3 , false ) ;
V_3 -> V_38 = false ;
V_26 = F_41 ( V_3 ) ;
if ( V_26 < 0 )
goto V_39;
return 0 ;
V_39:
F_42 ( ( unsigned long ) V_3 -> V_37 ) ;
V_36:
return V_26 ;
}
void F_43 ( struct V_2 * V_3 )
{
F_44 ( V_3 -> V_28 ) ;
F_45 ( V_3 ) ;
F_42 ( ( unsigned long ) V_3 -> V_37 ) ;
}
static inline struct V_9 * F_46 ( struct V_40 * V_41 )
{
return F_47 ( V_41 , struct V_9 , V_40 ) ;
}
static void F_48 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_44 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
int V_45 , V_46 ;
V_46 = F_49 ( & V_9 -> V_47 ) ;
F_50 ( & V_9 -> V_48 ) ;
V_9 -> V_49 ++ ;
V_45 = F_51 ( V_9 , V_44 ) | V_9 -> V_19 ;
if ( V_45 )
F_29 ( V_9 ) ;
F_52 ( & V_9 -> V_48 ) ;
F_53 ( V_9 , V_44 ) ;
F_54 ( & V_9 -> V_47 , V_46 ) ;
}
static void F_55 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_44 ,
T_3 V_50 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
int V_46 ;
V_46 = F_49 ( & V_9 -> V_47 ) ;
F_50 ( & V_9 -> V_48 ) ;
V_9 -> V_49 ++ ;
F_56 ( V_9 , V_44 , V_50 ) ;
F_52 ( & V_9 -> V_48 ) ;
F_54 ( & V_9 -> V_47 , V_46 ) ;
}
static void F_57 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
int V_45 = 0 , V_46 ;
V_46 = F_49 ( & V_9 -> V_47 ) ;
F_50 ( & V_9 -> V_48 ) ;
V_9 -> V_53 ++ ;
V_45 = F_58 ( V_9 , V_51 , V_52 ) ;
V_45 |= V_9 -> V_19 ;
if ( V_45 )
F_29 ( V_9 ) ;
F_52 ( & V_9 -> V_48 ) ;
F_54 ( & V_9 -> V_47 , V_46 ) ;
}
static void F_59 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
F_50 ( & V_9 -> V_48 ) ;
V_9 -> V_49 ++ ;
F_60 () ;
V_9 -> V_53 -- ;
F_52 ( & V_9 -> V_48 ) ;
F_61 ( V_9 -> V_53 < 0 ) ;
}
static int F_62 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
int V_54 , V_46 ;
V_46 = F_49 ( & V_9 -> V_47 ) ;
F_50 ( & V_9 -> V_48 ) ;
V_54 = F_63 ( V_9 , V_51 , V_52 ) ;
if ( V_54 )
F_29 ( V_9 ) ;
F_52 ( & V_9 -> V_48 ) ;
F_54 ( & V_9 -> V_47 , V_46 ) ;
return V_54 ;
}
static int F_64 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
int V_54 , V_46 ;
V_46 = F_49 ( & V_9 -> V_47 ) ;
F_50 ( & V_9 -> V_48 ) ;
V_54 = F_63 ( V_9 , V_51 , V_52 ) ;
F_52 ( & V_9 -> V_48 ) ;
F_54 ( & V_9 -> V_47 , V_46 ) ;
return V_54 ;
}
static int F_65 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned long V_44 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
int V_54 , V_46 ;
V_46 = F_49 ( & V_9 -> V_47 ) ;
F_50 ( & V_9 -> V_48 ) ;
V_54 = F_66 ( V_9 , V_44 ) ;
F_52 ( & V_9 -> V_48 ) ;
F_54 ( & V_9 -> V_47 , V_46 ) ;
return V_54 ;
}
static void F_67 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_9 * V_9 = F_46 ( V_41 ) ;
int V_46 ;
V_46 = F_49 ( & V_9 -> V_47 ) ;
F_68 ( V_9 ) ;
F_54 ( & V_9 -> V_47 , V_46 ) ;
}
static int F_69 ( struct V_9 * V_9 )
{
V_9 -> V_40 . V_55 = & V_56 ;
return F_70 ( & V_9 -> V_40 , V_57 -> V_43 ) ;
}
static int F_69 ( struct V_9 * V_9 )
{
return 0 ;
}
static struct V_58 * F_71 ( void )
{
int V_11 ;
struct V_58 * V_59 ;
V_59 = F_72 ( sizeof( struct V_58 ) ) ;
if ( ! V_59 )
return NULL ;
V_59 -> V_60 = - 150 ;
for ( V_11 = 0 ; V_11 < V_61 ; V_11 ++ )
V_59 -> V_62 [ V_11 ] = V_59 -> V_63 [ V_11 ] . V_24 = V_11 ;
return V_59 ;
}
static void F_73 ( struct V_64 * V_65 )
{
if ( ! V_65 -> V_66 )
return;
F_74 ( V_65 -> V_66 ) ;
V_65 -> V_66 = NULL ;
}
static void F_75 ( struct V_9 * V_9 , struct V_64 * free ,
struct V_64 * V_67 )
{
if ( ! V_67 || free -> V_66 != V_67 -> V_66 )
F_73 ( free ) ;
F_76 ( V_9 , free , V_67 ) ;
free -> V_68 = 0 ;
}
static void F_77 ( struct V_9 * V_9 , struct V_58 * V_59 )
{
struct V_64 * V_65 ;
if ( ! V_59 )
return;
F_78 (memslot, slots)
F_75 ( V_9 , V_65 , NULL ) ;
F_74 ( V_59 ) ;
}
static struct V_9 * F_79 ( unsigned long type )
{
int V_26 , V_11 ;
struct V_9 * V_9 = F_80 () ;
if ( ! V_9 )
return F_81 ( - V_35 ) ;
V_26 = F_82 ( V_9 , type ) ;
if ( V_26 )
goto V_69;
V_26 = F_83 () ;
if ( V_26 )
goto V_69;
#ifdef F_84
F_85 ( & V_9 -> V_70 ) ;
#endif
F_86 ( V_61 > V_71 ) ;
V_26 = - V_35 ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ ) {
V_9 -> V_63 [ V_11 ] = F_71 () ;
if ( ! V_9 -> V_63 [ V_11 ] )
goto V_73;
}
if ( F_87 ( & V_9 -> V_47 ) )
goto V_73;
if ( F_87 ( & V_9 -> V_74 ) )
goto V_75;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) {
V_9 -> V_77 [ V_11 ] = F_88 ( sizeof( struct V_78 ) ,
V_33 ) ;
if ( ! V_9 -> V_77 [ V_11 ] )
goto V_79;
}
F_89 ( & V_9 -> V_48 ) ;
V_9 -> V_43 = V_57 -> V_43 ;
F_90 ( & V_9 -> V_43 -> V_80 ) ;
F_91 ( V_9 ) ;
F_33 ( & V_9 -> V_81 ) ;
F_33 ( & V_9 -> V_82 ) ;
F_33 ( & V_9 -> V_83 ) ;
F_92 ( & V_9 -> V_84 , 1 ) ;
F_36 ( & V_9 -> V_85 ) ;
V_26 = F_69 ( V_9 ) ;
if ( V_26 )
goto V_79;
F_50 ( & V_86 ) ;
F_93 ( & V_9 -> V_87 , & V_87 ) ;
F_52 ( & V_86 ) ;
F_94 () ;
return V_9 ;
V_79:
F_95 ( & V_9 -> V_74 ) ;
V_75:
F_95 ( & V_9 -> V_47 ) ;
V_73:
F_96 () ;
V_69:
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ )
F_97 ( V_9 -> V_77 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ )
F_77 ( V_9 , V_9 -> V_63 [ V_11 ] ) ;
F_98 ( V_9 ) ;
return F_81 ( V_26 ) ;
}
void * F_72 ( unsigned long V_88 )
{
if ( V_88 > V_89 )
return F_99 ( V_88 ) ;
else
return F_88 ( V_88 , V_33 ) ;
}
static void F_100 ( struct V_9 * V_9 )
{
struct V_90 * V_91 , * V_92 ;
F_101 (node, tmp, &kvm->devices) {
struct V_93 * V_94 =
F_102 ( V_91 , struct V_93 , V_95 ) ;
F_103 ( V_91 ) ;
V_94 -> V_55 -> V_96 ( V_94 ) ;
}
}
static void F_104 ( struct V_9 * V_9 )
{
int V_11 ;
struct V_42 * V_43 = V_9 -> V_43 ;
F_105 ( V_9 ) ;
F_50 ( & V_86 ) ;
F_103 ( & V_9 -> V_87 ) ;
F_52 ( & V_86 ) ;
F_106 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ )
F_107 ( V_9 -> V_77 [ V_11 ] ) ;
F_108 ( V_9 ) ;
#if F_109 ( V_97 ) && F_109 ( V_98 )
F_110 ( & V_9 -> V_40 , V_9 -> V_43 ) ;
#else
F_68 ( V_9 ) ;
#endif
F_111 ( V_9 ) ;
F_100 ( V_9 ) ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ )
F_77 ( V_9 , V_9 -> V_63 [ V_11 ] ) ;
F_95 ( & V_9 -> V_74 ) ;
F_95 ( & V_9 -> V_47 ) ;
F_98 ( V_9 ) ;
F_112 () ;
F_96 () ;
F_113 ( V_43 ) ;
}
void F_114 ( struct V_9 * V_9 )
{
F_90 ( & V_9 -> V_84 ) ;
}
void F_115 ( struct V_9 * V_9 )
{
if ( F_116 ( & V_9 -> V_84 ) )
F_104 ( V_9 ) ;
}
static int F_117 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_9 * V_9 = V_101 -> V_102 ;
F_118 ( V_9 ) ;
F_115 ( V_9 ) ;
return 0 ;
}
static int F_119 ( struct V_64 * V_65 )
{
unsigned long V_103 = 2 * F_120 ( V_65 ) ;
V_65 -> V_66 = F_72 ( V_103 ) ;
if ( ! V_65 -> V_66 )
return - V_35 ;
return 0 ;
}
static void F_121 ( struct V_58 * V_59 ,
struct V_64 * V_104 )
{
int V_24 = V_104 -> V_24 ;
int V_11 = V_59 -> V_62 [ V_24 ] ;
struct V_64 * V_105 = V_59 -> V_63 ;
F_122 ( V_105 [ V_11 ] . V_24 != V_24 ) ;
if ( ! V_104 -> V_68 ) {
F_122 ( ! V_105 [ V_11 ] . V_68 ) ;
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
V_59 -> V_62 [ V_105 [ V_11 ] . V_24 ] = V_11 ;
V_11 ++ ;
}
if ( V_104 -> V_68 ) {
while ( V_11 > 0 &&
V_104 -> V_107 >= V_105 [ V_11 - 1 ] . V_107 ) {
V_105 [ V_11 ] = V_105 [ V_11 - 1 ] ;
V_59 -> V_62 [ V_105 [ V_11 ] . V_24 ] = V_11 ;
V_11 -- ;
}
} else
F_123 ( V_11 != V_59 -> V_106 ) ;
V_105 [ V_11 ] = * V_104 ;
V_59 -> V_62 [ V_105 [ V_11 ] . V_24 ] = V_11 ;
}
static int F_124 ( const struct V_108 * V_109 )
{
T_4 V_110 = V_111 ;
#ifdef F_125
V_110 |= V_112 ;
#endif
if ( V_109 -> V_113 & ~ V_110 )
return - V_114 ;
return 0 ;
}
static struct V_58 * F_126 ( struct V_9 * V_9 ,
int V_115 , struct V_58 * V_59 )
{
struct V_58 * V_116 = F_127 ( V_9 , V_115 ) ;
F_122 ( V_116 -> V_60 & 1 ) ;
V_59 -> V_60 = V_116 -> V_60 + 1 ;
F_128 ( V_9 -> V_63 [ V_115 ] , V_59 ) ;
F_129 ( & V_9 -> V_47 ) ;
V_59 -> V_60 ++ ;
F_130 ( V_9 , V_59 ) ;
return V_116 ;
}
int F_131 ( struct V_9 * V_9 ,
const struct V_108 * V_109 )
{
int V_26 ;
T_5 V_107 ;
unsigned long V_68 ;
struct V_64 * V_117 ;
struct V_64 V_118 , V_104 ;
struct V_58 * V_59 = NULL , * V_116 ;
int V_115 , V_24 ;
enum V_119 V_120 ;
V_26 = F_124 ( V_109 ) ;
if ( V_26 )
goto V_121;
V_26 = - V_114 ;
V_115 = V_109 -> V_117 >> 16 ;
V_24 = ( V_122 ) V_109 -> V_117 ;
if ( V_109 -> V_123 & ( V_89 - 1 ) )
goto V_121;
if ( V_109 -> V_124 & ( V_89 - 1 ) )
goto V_121;
if ( ( V_24 < V_125 ) &&
( ( V_109 -> V_126 & ( V_89 - 1 ) ) ||
! F_132 ( V_127 ,
( void V_128 * ) ( unsigned long ) V_109 -> V_126 ,
V_109 -> V_123 ) ) )
goto V_121;
if ( V_115 >= V_72 || V_24 >= V_61 )
goto V_121;
if ( V_109 -> V_124 + V_109 -> V_123 < V_109 -> V_124 )
goto V_121;
V_117 = F_133 ( F_127 ( V_9 , V_115 ) , V_24 ) ;
V_107 = V_109 -> V_124 >> V_129 ;
V_68 = V_109 -> V_123 >> V_129 ;
if ( V_68 > V_130 )
goto V_121;
V_104 = V_118 = * V_117 ;
V_104 . V_24 = V_24 ;
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
V_26 = 0 ;
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
V_26 = - V_135 ;
F_78 (slot, __kvm_memslots(kvm, as_id)) {
if ( ( V_117 -> V_24 >= V_125 ) ||
( V_117 -> V_24 == V_24 ) )
continue;
if ( ! ( ( V_107 + V_68 <= V_117 -> V_107 ) ||
( V_107 >= V_117 -> V_107 + V_117 -> V_68 ) ) )
goto V_121;
}
}
if ( ! ( V_104 . V_113 & V_111 ) )
V_104 . V_66 = NULL ;
V_26 = - V_35 ;
if ( V_120 == V_131 ) {
V_104 . V_126 = V_109 -> V_126 ;
if ( F_134 ( V_9 , & V_104 , V_68 ) )
goto V_136;
}
if ( ( V_104 . V_113 & V_111 ) && ! V_104 . V_66 ) {
if ( F_119 ( & V_104 ) < 0 )
goto V_136;
}
V_59 = F_72 ( sizeof( struct V_58 ) ) ;
if ( ! V_59 )
goto V_136;
memcpy ( V_59 , F_127 ( V_9 , V_115 ) , sizeof( struct V_58 ) ) ;
if ( ( V_120 == V_134 ) || ( V_120 == V_132 ) ) {
V_117 = F_133 ( V_59 , V_24 ) ;
V_117 -> V_113 |= V_137 ;
V_116 = F_126 ( V_9 , V_115 , V_59 ) ;
F_135 ( V_9 , & V_118 ) ;
F_136 ( V_9 , V_117 ) ;
V_59 = V_116 ;
}
V_26 = F_137 ( V_9 , & V_104 , V_109 , V_120 ) ;
if ( V_26 )
goto V_138;
if ( V_120 == V_134 ) {
V_104 . V_66 = NULL ;
memset ( & V_104 . V_139 , 0 , sizeof( V_104 . V_139 ) ) ;
}
F_121 ( V_59 , & V_104 ) ;
V_116 = F_126 ( V_9 , V_115 , V_59 ) ;
F_138 ( V_9 , V_109 , & V_118 , & V_104 , V_120 ) ;
F_75 ( V_9 , & V_118 , & V_104 ) ;
F_74 ( V_116 ) ;
if ( ( V_120 == V_131 ) || ( V_120 == V_132 ) ) {
V_26 = F_139 ( V_9 , & V_104 ) ;
return V_26 ;
}
return 0 ;
V_138:
F_74 ( V_59 ) ;
V_136:
F_75 ( V_9 , & V_104 , & V_118 ) ;
V_121:
return V_26 ;
}
int F_140 ( struct V_9 * V_9 ,
const struct V_108 * V_109 )
{
int V_26 ;
F_141 ( & V_9 -> V_83 ) ;
V_26 = F_131 ( V_9 , V_109 ) ;
F_16 ( & V_9 -> V_83 ) ;
return V_26 ;
}
static int F_142 ( struct V_9 * V_9 ,
struct V_108 * V_109 )
{
if ( ( V_122 ) V_109 -> V_117 >= V_125 )
return - V_114 ;
return F_140 ( V_9 , V_109 ) ;
}
int F_143 ( struct V_9 * V_9 ,
struct V_140 * log , int * V_141 )
{
struct V_58 * V_59 ;
struct V_64 * V_65 ;
int V_26 , V_11 , V_115 , V_24 ;
unsigned long V_142 ;
unsigned long V_143 = 0 ;
V_26 = - V_114 ;
V_115 = log -> V_117 >> 16 ;
V_24 = ( V_122 ) log -> V_117 ;
if ( V_115 >= V_72 || V_24 >= V_125 )
goto V_121;
V_59 = F_127 ( V_9 , V_115 ) ;
V_65 = F_133 ( V_59 , V_24 ) ;
V_26 = - V_144 ;
if ( ! V_65 -> V_66 )
goto V_121;
V_142 = F_120 ( V_65 ) ;
for ( V_11 = 0 ; ! V_143 && V_11 < V_142 / sizeof( long ) ; ++ V_11 )
V_143 = V_65 -> V_66 [ V_11 ] ;
V_26 = - V_145 ;
if ( F_144 ( log -> V_66 , V_65 -> V_66 , V_142 ) )
goto V_121;
if ( V_143 )
* V_141 = 1 ;
V_26 = 0 ;
V_121:
return V_26 ;
}
int F_145 ( struct V_9 * V_9 ,
struct V_140 * log , bool * V_141 )
{
struct V_58 * V_59 ;
struct V_64 * V_65 ;
int V_26 , V_11 , V_115 , V_24 ;
unsigned long V_142 ;
unsigned long * V_66 ;
unsigned long * V_146 ;
V_26 = - V_114 ;
V_115 = log -> V_117 >> 16 ;
V_24 = ( V_122 ) log -> V_117 ;
if ( V_115 >= V_72 || V_24 >= V_125 )
goto V_121;
V_59 = F_127 ( V_9 , V_115 ) ;
V_65 = F_133 ( V_59 , V_24 ) ;
V_66 = V_65 -> V_66 ;
V_26 = - V_144 ;
if ( ! V_66 )
goto V_121;
V_142 = F_120 ( V_65 ) ;
V_146 = V_66 + V_142 / sizeof( long ) ;
memset ( V_146 , 0 , V_142 ) ;
F_50 ( & V_9 -> V_48 ) ;
* V_141 = false ;
for ( V_11 = 0 ; V_11 < V_142 / sizeof( long ) ; V_11 ++ ) {
unsigned long V_147 ;
T_5 V_148 ;
if ( ! V_66 [ V_11 ] )
continue;
* V_141 = true ;
V_147 = F_146 ( & V_66 [ V_11 ] , 0 ) ;
V_146 [ V_11 ] = V_147 ;
if ( V_147 ) {
V_148 = V_11 * V_149 ;
F_147 ( V_9 , V_65 ,
V_148 , V_147 ) ;
}
}
F_52 ( & V_9 -> V_48 ) ;
V_26 = - V_145 ;
if ( F_144 ( log -> V_66 , V_146 , V_142 ) )
goto V_121;
V_26 = 0 ;
V_121:
return V_26 ;
}
bool F_148 ( void )
{
return V_150 ;
}
void F_149 ( void )
{
V_150 = false ;
}
struct V_64 * F_150 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_151 ( V_58 ( V_9 ) , V_151 ) ;
}
struct V_64 * F_152 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_151 ( F_153 ( V_3 ) , V_151 ) ;
}
bool F_154 ( struct V_9 * V_9 , T_5 V_151 )
{
struct V_64 * V_65 = F_150 ( V_9 , V_151 ) ;
if ( ! V_65 || V_65 -> V_24 >= V_125 ||
V_65 -> V_113 & V_137 )
return false ;
return true ;
}
unsigned long F_155 ( struct V_9 * V_9 , T_5 V_151 )
{
struct V_152 * V_153 ;
unsigned long V_154 , V_88 ;
V_88 = V_89 ;
V_154 = F_156 ( V_9 , V_151 ) ;
if ( F_157 ( V_154 ) )
return V_89 ;
F_158 ( & V_57 -> V_43 -> V_155 ) ;
V_153 = F_159 ( V_57 -> V_43 , V_154 ) ;
if ( ! V_153 )
goto V_121;
V_88 = F_160 ( V_153 ) ;
V_121:
F_161 ( & V_57 -> V_43 -> V_155 ) ;
return V_88 ;
}
static bool F_162 ( struct V_64 * V_117 )
{
return V_117 -> V_113 & V_112 ;
}
static unsigned long F_163 ( struct V_64 * V_117 , T_5 V_151 ,
T_5 * V_156 , bool V_157 )
{
if ( ! V_117 || V_117 -> V_113 & V_137 )
return V_158 ;
if ( F_162 ( V_117 ) && V_157 )
return V_159 ;
if ( V_156 )
* V_156 = V_117 -> V_68 - ( V_151 - V_117 -> V_107 ) ;
return F_164 ( V_117 , V_151 ) ;
}
static unsigned long F_165 ( struct V_64 * V_117 , T_5 V_151 ,
T_5 * V_156 )
{
return F_163 ( V_117 , V_151 , V_156 , true ) ;
}
unsigned long F_166 ( struct V_64 * V_117 ,
T_5 V_151 )
{
return F_165 ( V_117 , V_151 , NULL ) ;
}
unsigned long F_156 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_165 ( F_150 ( V_9 , V_151 ) , V_151 , NULL ) ;
}
unsigned long F_167 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_165 ( F_152 ( V_3 , V_151 ) , V_151 , NULL ) ;
}
unsigned long F_168 ( struct V_64 * V_117 ,
T_5 V_151 , bool * V_160 )
{
unsigned long V_161 = F_163 ( V_117 , V_151 , NULL , false ) ;
if ( ! F_157 ( V_161 ) && V_160 )
* V_160 = ! F_162 ( V_117 ) ;
return V_161 ;
}
unsigned long F_169 ( struct V_9 * V_9 , T_5 V_151 , bool * V_160 )
{
struct V_64 * V_117 = F_150 ( V_9 , V_151 ) ;
return F_168 ( V_117 , V_151 , V_160 ) ;
}
unsigned long F_170 ( struct V_2 * V_3 , T_5 V_151 , bool * V_160 )
{
struct V_64 * V_117 = F_152 ( V_3 , V_151 ) ;
return F_168 ( V_117 , V_151 , V_160 ) ;
}
static int F_171 ( struct V_162 * V_163 , struct V_42 * V_43 ,
unsigned long V_51 , int V_157 , struct V_25 * * V_25 )
{
int V_113 = V_164 | V_165 | V_166 | V_167 ;
if ( V_157 )
V_113 |= V_168 ;
return F_172 ( V_163 , V_43 , V_51 , 1 , V_113 , V_25 , NULL , NULL ) ;
}
static inline int F_173 ( unsigned long V_154 )
{
int V_169 , V_113 = V_164 | V_166 | V_168 ;
V_169 = F_172 ( V_57 , V_57 -> V_43 , V_154 , 1 ,
V_113 , NULL , NULL , NULL ) ;
return V_169 == - V_170 ;
}
static bool F_174 ( unsigned long V_154 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_160 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_68 ;
if ( ! ( V_172 || V_171 ) )
return false ;
if ( ! ( V_173 || V_160 ) )
return false ;
V_68 = F_175 ( V_154 , 1 , 1 , V_25 ) ;
if ( V_68 == 1 ) {
* V_1 = F_176 ( V_25 [ 0 ] ) ;
if ( V_160 )
* V_160 = true ;
return true ;
}
return false ;
}
static int F_177 ( unsigned long V_154 , bool * V_172 , bool V_173 ,
bool * V_160 , T_1 * V_1 )
{
struct V_25 * V_25 [ 1 ] ;
int V_68 = 0 ;
F_178 () ;
if ( V_160 )
* V_160 = V_173 ;
if ( V_172 ) {
F_158 ( & V_57 -> V_43 -> V_155 ) ;
V_68 = F_171 ( V_57 , V_57 -> V_43 ,
V_154 , V_173 , V_25 ) ;
F_161 ( & V_57 -> V_43 -> V_155 ) ;
} else
V_68 = F_179 ( V_57 , V_57 -> V_43 , V_154 , 1 ,
V_173 , 0 , V_25 ,
V_164 | V_166 ) ;
if ( V_68 != 1 )
return V_68 ;
if ( F_25 ( ! V_173 ) && V_160 ) {
struct V_25 * V_174 [ 1 ] ;
V_68 = F_175 ( V_154 , 1 , 1 , V_174 ) ;
if ( V_68 == 1 ) {
* V_160 = true ;
F_180 ( V_25 [ 0 ] ) ;
V_25 [ 0 ] = V_174 [ 0 ] ;
}
V_68 = 1 ;
}
* V_1 = F_176 ( V_25 [ 0 ] ) ;
return V_68 ;
}
static bool F_181 ( struct V_152 * V_153 , bool V_173 )
{
if ( F_25 ( ! ( V_153 -> V_175 & V_176 ) ) )
return false ;
if ( V_173 && ( F_25 ( ! ( V_153 -> V_175 & V_177 ) ) ) )
return false ;
return true ;
}
static T_1 F_182 ( unsigned long V_154 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_160 )
{
struct V_152 * V_153 ;
T_1 V_1 = 0 ;
int V_68 ;
F_61 ( V_171 && V_172 ) ;
if ( F_174 ( V_154 , V_171 , V_172 , V_173 , V_160 , & V_1 ) )
return V_1 ;
if ( V_171 )
return V_178 ;
V_68 = F_177 ( V_154 , V_172 , V_173 , V_160 , & V_1 ) ;
if ( V_68 == 1 )
return V_1 ;
F_158 ( & V_57 -> V_43 -> V_155 ) ;
if ( V_68 == - V_170 ||
( ! V_172 && F_173 ( V_154 ) ) ) {
V_1 = V_179 ;
goto exit;
}
V_153 = F_183 ( V_57 -> V_43 , V_154 , V_154 + 1 ) ;
if ( V_153 == NULL )
V_1 = V_178 ;
else if ( ( V_153 -> V_175 & V_180 ) ) {
V_1 = ( ( V_154 - V_153 -> V_181 ) >> V_129 ) +
V_153 -> V_182 ;
F_61 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_172 && F_181 ( V_153 , V_173 ) )
* V_172 = true ;
V_1 = V_178 ;
}
exit:
F_161 ( & V_57 -> V_43 -> V_155 ) ;
return V_1 ;
}
T_1 F_184 ( struct V_64 * V_117 , T_5 V_151 ,
bool V_171 , bool * V_172 , bool V_173 ,
bool * V_160 )
{
unsigned long V_154 = F_163 ( V_117 , V_151 , NULL , V_173 ) ;
if ( V_154 == V_159 )
return V_183 ;
if ( F_157 ( V_154 ) )
return V_184 ;
if ( V_160 && F_162 ( V_117 ) ) {
* V_160 = false ;
V_160 = NULL ;
}
return F_182 ( V_154 , V_171 , V_172 , V_173 ,
V_160 ) ;
}
T_1 F_185 ( struct V_9 * V_9 , T_5 V_151 , bool V_173 ,
bool * V_160 )
{
return F_184 ( F_150 ( V_9 , V_151 ) , V_151 , false , NULL ,
V_173 , V_160 ) ;
}
T_1 F_186 ( struct V_64 * V_117 , T_5 V_151 )
{
return F_184 ( V_117 , V_151 , false , NULL , true , NULL ) ;
}
T_1 F_187 ( struct V_64 * V_117 , T_5 V_151 )
{
return F_184 ( V_117 , V_151 , true , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_187 ( F_150 ( V_9 , V_151 ) , V_151 ) ;
}
T_1 F_189 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_187 ( F_152 ( V_3 , V_151 ) , V_151 ) ;
}
T_1 F_190 ( struct V_9 * V_9 , T_5 V_151 )
{
return F_186 ( F_150 ( V_9 , V_151 ) , V_151 ) ;
}
T_1 F_191 ( struct V_2 * V_3 , T_5 V_151 )
{
return F_186 ( F_152 ( V_3 , V_151 ) , V_151 ) ;
}
int F_192 ( struct V_64 * V_117 , T_5 V_151 ,
struct V_25 * * V_185 , int V_156 )
{
unsigned long V_154 ;
T_5 V_186 ;
V_154 = F_165 ( V_117 , V_151 , & V_186 ) ;
if ( F_157 ( V_154 ) )
return - 1 ;
if ( V_186 < V_156 )
return 0 ;
return F_175 ( V_154 , V_156 , 1 , V_185 ) ;
}
static struct V_25 * F_193 ( T_1 V_1 )
{
if ( F_194 ( V_1 ) )
return V_187 ;
if ( F_1 ( V_1 ) ) {
F_122 ( 1 ) ;
return V_187 ;
}
return F_4 ( V_1 ) ;
}
struct V_25 * F_195 ( struct V_9 * V_9 , T_5 V_151 )
{
T_1 V_1 ;
V_1 = F_190 ( V_9 , V_151 ) ;
return F_193 ( V_1 ) ;
}
struct V_25 * F_196 ( struct V_2 * V_3 , T_5 V_151 )
{
T_1 V_1 ;
V_1 = F_191 ( V_3 , V_151 ) ;
return F_193 ( V_1 ) ;
}
void F_197 ( struct V_25 * V_25 )
{
F_122 ( F_198 ( V_25 ) ) ;
F_199 ( F_176 ( V_25 ) ) ;
}
void F_199 ( T_1 V_1 )
{
if ( ! F_194 ( V_1 ) && ! F_1 ( V_1 ) )
F_180 ( F_4 ( V_1 ) ) ;
}
void F_200 ( struct V_25 * V_25 )
{
F_122 ( F_198 ( V_25 ) ) ;
F_201 ( F_176 ( V_25 ) ) ;
}
static void F_201 ( T_1 V_1 )
{
F_202 ( V_1 ) ;
F_199 ( V_1 ) ;
}
void F_202 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_25 * V_25 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_25 ) )
F_203 ( V_25 ) ;
}
}
void F_204 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_205 ( F_4 ( V_1 ) ) ;
}
void F_206 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_207 ( F_4 ( V_1 ) ) ;
}
static int F_208 ( unsigned long V_188 , int V_148 )
{
if ( V_188 > V_89 - V_148 )
return V_89 - V_148 ;
else
return V_188 ;
}
static int F_209 ( struct V_64 * V_117 , T_5 V_151 ,
void * V_189 , int V_148 , int V_188 )
{
int V_26 ;
unsigned long V_154 ;
V_154 = F_168 ( V_117 , V_151 , NULL ) ;
if ( F_157 ( V_154 ) )
return - V_145 ;
V_26 = F_210 ( V_189 , ( void V_128 * ) V_154 + V_148 , V_188 ) ;
if ( V_26 )
return - V_145 ;
return 0 ;
}
int F_211 ( struct V_9 * V_9 , T_5 V_151 , void * V_189 , int V_148 ,
int V_188 )
{
struct V_64 * V_117 = F_150 ( V_9 , V_151 ) ;
return F_209 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_212 ( struct V_2 * V_3 , T_5 V_151 , void * V_189 ,
int V_148 , int V_188 )
{
struct V_64 * V_117 = F_152 ( V_3 , V_151 ) ;
return F_209 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_213 ( struct V_9 * V_9 , T_6 V_190 , void * V_189 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_214 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_208 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_211 ( V_9 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
int F_215 ( struct V_2 * V_3 , T_6 V_190 , void * V_189 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_214 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_208 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_212 ( V_3 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
static int F_216 ( struct V_64 * V_117 , T_5 V_151 ,
void * V_189 , int V_148 , unsigned long V_188 )
{
int V_26 ;
unsigned long V_154 ;
V_154 = F_168 ( V_117 , V_151 , NULL ) ;
if ( F_157 ( V_154 ) )
return - V_145 ;
F_217 () ;
V_26 = F_218 ( V_189 , ( void V_128 * ) V_154 + V_148 , V_188 ) ;
F_219 () ;
if ( V_26 )
return - V_145 ;
return 0 ;
}
int F_220 ( struct V_9 * V_9 , T_6 V_190 , void * V_189 ,
unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
struct V_64 * V_117 = F_150 ( V_9 , V_151 ) ;
int V_148 = F_214 ( V_190 ) ;
return F_216 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_221 ( struct V_2 * V_3 , T_6 V_190 ,
void * V_189 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
struct V_64 * V_117 = F_152 ( V_3 , V_151 ) ;
int V_148 = F_214 ( V_190 ) ;
return F_216 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
static int F_222 ( struct V_64 * V_65 , T_5 V_151 ,
const void * V_189 , int V_148 , int V_188 )
{
int V_26 ;
unsigned long V_154 ;
V_154 = F_166 ( V_65 , V_151 ) ;
if ( F_157 ( V_154 ) )
return - V_145 ;
V_26 = F_223 ( ( void V_128 * ) V_154 + V_148 , V_189 , V_188 ) ;
if ( V_26 )
return - V_145 ;
F_224 ( V_65 , V_151 ) ;
return 0 ;
}
int F_225 ( struct V_9 * V_9 , T_5 V_151 ,
const void * V_189 , int V_148 , int V_188 )
{
struct V_64 * V_117 = F_150 ( V_9 , V_151 ) ;
return F_222 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_226 ( struct V_2 * V_3 , T_5 V_151 ,
const void * V_189 , int V_148 , int V_188 )
{
struct V_64 * V_117 = F_152 ( V_3 , V_151 ) ;
return F_222 ( V_117 , V_151 , V_189 , V_148 , V_188 ) ;
}
int F_227 ( struct V_9 * V_9 , T_6 V_190 , const void * V_189 ,
unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_214 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_208 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_225 ( V_9 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
int F_228 ( struct V_2 * V_3 , T_6 V_190 , const void * V_189 ,
unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_214 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_208 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_226 ( V_3 , V_151 , V_189 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
V_189 += V_191 ;
++ V_151 ;
}
return 0 ;
}
int F_229 ( struct V_9 * V_9 , struct V_193 * V_194 ,
T_6 V_190 , unsigned long V_188 )
{
struct V_58 * V_59 = V_58 ( V_9 ) ;
int V_148 = F_214 ( V_190 ) ;
T_5 V_195 = V_190 >> V_129 ;
T_5 V_196 = ( V_190 + V_188 - 1 ) >> V_129 ;
T_5 V_197 = V_196 - V_195 + 1 ;
T_5 V_198 ;
V_194 -> V_190 = V_190 ;
V_194 -> V_60 = V_59 -> V_60 ;
V_194 -> V_188 = V_188 ;
V_194 -> V_65 = F_150 ( V_9 , V_195 ) ;
V_194 -> V_161 = F_165 ( V_194 -> V_65 , V_195 , NULL ) ;
if ( ! F_157 ( V_194 -> V_161 ) && V_197 <= 1 ) {
V_194 -> V_161 += V_148 ;
} else {
while ( V_195 <= V_196 ) {
V_194 -> V_65 = F_150 ( V_9 , V_195 ) ;
V_194 -> V_161 = F_165 ( V_194 -> V_65 , V_195 ,
& V_198 ) ;
if ( F_157 ( V_194 -> V_161 ) )
return - V_145 ;
V_195 += V_198 ;
}
V_194 -> V_65 = NULL ;
}
return 0 ;
}
int F_230 ( struct V_9 * V_9 , struct V_193 * V_194 ,
void * V_189 , unsigned long V_188 )
{
struct V_58 * V_59 = V_58 ( V_9 ) ;
int V_26 ;
F_61 ( V_188 > V_194 -> V_188 ) ;
if ( V_59 -> V_60 != V_194 -> V_60 )
F_229 ( V_9 , V_194 , V_194 -> V_190 , V_194 -> V_188 ) ;
if ( F_25 ( ! V_194 -> V_65 ) )
return F_227 ( V_9 , V_194 -> V_190 , V_189 , V_188 ) ;
if ( F_157 ( V_194 -> V_161 ) )
return - V_145 ;
V_26 = F_223 ( ( void V_128 * ) V_194 -> V_161 , V_189 , V_188 ) ;
if ( V_26 )
return - V_145 ;
F_224 ( V_194 -> V_65 , V_194 -> V_190 >> V_129 ) ;
return 0 ;
}
int F_231 ( struct V_9 * V_9 , struct V_193 * V_194 ,
void * V_189 , unsigned long V_188 )
{
struct V_58 * V_59 = V_58 ( V_9 ) ;
int V_26 ;
F_61 ( V_188 > V_194 -> V_188 ) ;
if ( V_59 -> V_60 != V_194 -> V_60 )
F_229 ( V_9 , V_194 , V_194 -> V_190 , V_194 -> V_188 ) ;
if ( F_25 ( ! V_194 -> V_65 ) )
return F_213 ( V_9 , V_194 -> V_190 , V_189 , V_188 ) ;
if ( F_157 ( V_194 -> V_161 ) )
return - V_145 ;
V_26 = F_210 ( V_189 , ( void V_128 * ) V_194 -> V_161 , V_188 ) ;
if ( V_26 )
return - V_145 ;
return 0 ;
}
int F_232 ( struct V_9 * V_9 , T_5 V_151 , int V_148 , int V_188 )
{
const void * V_199 = ( const void * ) F_233 ( F_234 ( F_235 ( 0 ) ) ) ;
return F_225 ( V_9 , V_151 , V_199 , V_148 , V_188 ) ;
}
int F_236 ( struct V_9 * V_9 , T_6 V_190 , unsigned long V_188 )
{
T_5 V_151 = V_190 >> V_129 ;
int V_191 ;
int V_148 = F_214 ( V_190 ) ;
int V_192 ;
while ( ( V_191 = F_208 ( V_188 , V_148 ) ) != 0 ) {
V_192 = F_232 ( V_9 , V_151 , V_148 , V_191 ) ;
if ( V_192 < 0 )
return V_192 ;
V_148 = 0 ;
V_188 -= V_191 ;
++ V_151 ;
}
return 0 ;
}
static void F_224 ( struct V_64 * V_65 ,
T_5 V_151 )
{
if ( V_65 && V_65 -> V_66 ) {
unsigned long V_200 = V_151 - V_65 -> V_107 ;
F_237 ( V_200 , V_65 -> V_66 ) ;
}
}
void F_238 ( struct V_9 * V_9 , T_5 V_151 )
{
struct V_64 * V_65 ;
V_65 = F_150 ( V_9 , V_151 ) ;
F_224 ( V_65 , V_151 ) ;
}
void F_239 ( struct V_2 * V_3 , T_5 V_151 )
{
struct V_64 * V_65 ;
V_65 = F_152 ( V_3 , V_151 ) ;
F_224 ( V_65 , V_151 ) ;
}
static void F_240 ( struct V_2 * V_3 )
{
int V_118 , V_201 ;
V_118 = V_201 = V_3 -> V_29 ;
if ( V_201 == 0 && V_202 )
V_201 = 10000 ;
else
V_201 *= V_202 ;
if ( V_201 > V_29 )
V_201 = V_29 ;
V_3 -> V_29 = V_201 ;
F_241 ( V_3 -> V_27 , V_201 , V_118 ) ;
}
static void F_242 ( struct V_2 * V_3 )
{
int V_118 , V_201 ;
V_118 = V_201 = V_3 -> V_29 ;
if ( V_203 == 0 )
V_201 = 0 ;
else
V_201 /= V_203 ;
V_3 -> V_29 = V_201 ;
F_243 ( V_3 -> V_27 , V_201 , V_118 ) ;
}
static int F_244 ( struct V_2 * V_3 )
{
if ( F_245 ( V_3 ) ) {
F_21 ( V_204 , V_3 ) ;
return - V_6 ;
}
if ( F_246 ( V_3 ) )
return - V_6 ;
if ( F_247 ( V_57 ) )
return - V_6 ;
return 0 ;
}
void F_248 ( struct V_2 * V_3 )
{
T_7 V_51 , V_205 ;
F_249 ( V_206 ) ;
bool V_207 = false ;
T_8 V_208 ;
V_51 = V_205 = F_250 () ;
if ( V_3 -> V_29 ) {
T_7 V_209 = F_251 ( F_250 () , V_3 -> V_29 ) ;
++ V_3 -> V_21 . V_210 ;
do {
if ( F_244 ( V_3 ) < 0 ) {
++ V_3 -> V_21 . V_211 ;
goto V_121;
}
V_205 = F_250 () ;
} while ( F_252 () && F_253 ( V_205 , V_209 ) );
}
F_254 ( V_3 ) ;
for (; ; ) {
F_255 ( & V_3 -> V_30 , & V_206 , V_212 ) ;
if ( F_244 ( V_3 ) < 0 )
break;
V_207 = true ;
F_256 () ;
}
F_257 ( & V_3 -> V_30 , & V_206 ) ;
V_205 = F_250 () ;
F_258 ( V_3 ) ;
V_121:
V_208 = F_259 ( V_205 ) - F_259 ( V_51 ) ;
if ( V_29 ) {
if ( V_208 <= V_3 -> V_29 )
;
else if ( V_3 -> V_29 && V_208 > V_29 )
F_242 ( V_3 ) ;
else if ( V_3 -> V_29 < V_29 &&
V_208 < V_29 )
F_240 ( V_3 ) ;
} else
V_3 -> V_29 = 0 ;
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
struct V_28 * V_28 ;
struct V_162 * V_217 = NULL ;
int V_192 = 0 ;
F_269 () ;
V_28 = F_270 ( V_216 -> V_28 ) ;
if ( V_28 )
V_217 = F_271 ( V_28 , V_218 ) ;
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
F_40 ( V_3 , ! V_3 -> V_220 . V_222 ) ;
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
F_39 ( V_12 , true ) ;
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
if ( F_263 ( & V_3 -> V_30 ) && ! F_245 ( V_3 ) )
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
F_39 ( V_12 , false ) ;
F_40 ( V_12 , false ) ;
}
static int F_279 ( struct V_152 * V_153 , struct V_227 * V_228 )
{
struct V_2 * V_3 = V_153 -> V_229 -> V_102 ;
struct V_25 * V_25 ;
if ( V_228 -> V_230 == 0 )
V_25 = F_280 ( V_3 -> V_37 ) ;
#ifdef F_281
else if ( V_228 -> V_230 == V_231 )
V_25 = F_280 ( V_3 -> V_139 . V_232 ) ;
#endif
#ifdef F_282
else if ( V_228 -> V_230 == F_282 )
V_25 = F_280 ( V_3 -> V_9 -> V_233 ) ;
#endif
else
return F_283 ( V_3 , V_228 ) ;
F_207 ( V_25 ) ;
V_228 -> V_25 = V_25 ;
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
F_115 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_286 ( struct V_2 * V_3 )
{
return F_287 ( L_1 , & V_236 , V_3 , V_237 | V_238 ) ;
}
static int F_288 ( struct V_9 * V_9 , T_4 V_24 )
{
int V_26 ;
struct V_2 * V_3 ;
if ( V_24 >= V_239 )
return - V_114 ;
V_3 = F_289 ( V_9 , V_24 ) ;
if ( F_290 ( V_3 ) )
return F_291 ( V_3 ) ;
F_292 ( & V_3 -> V_7 , & V_240 ) ;
V_26 = F_293 ( V_3 ) ;
if ( V_26 )
goto V_241;
F_141 ( & V_9 -> V_81 ) ;
if ( ! F_294 ( V_3 ) ) {
V_26 = - V_114 ;
goto V_242;
}
if ( F_295 ( & V_9 -> V_243 ) == V_239 ) {
V_26 = - V_114 ;
goto V_242;
}
if ( F_296 ( V_9 , V_24 ) ) {
V_26 = - V_135 ;
goto V_242;
}
F_61 ( V_9 -> V_244 [ F_295 ( & V_9 -> V_243 ) ] ) ;
F_114 ( V_9 ) ;
V_26 = F_286 ( V_3 ) ;
if ( V_26 < 0 ) {
F_115 ( V_9 ) ;
goto V_242;
}
V_9 -> V_244 [ F_295 ( & V_9 -> V_243 ) ] = V_3 ;
F_60 () ;
F_90 ( & V_9 -> V_243 ) ;
F_16 ( & V_9 -> V_81 ) ;
F_297 ( V_3 ) ;
return V_26 ;
V_242:
F_16 ( & V_9 -> V_81 ) ;
V_241:
F_298 ( V_3 ) ;
return V_26 ;
}
static int F_299 ( struct V_2 * V_3 , T_10 * V_245 )
{
if ( V_245 ) {
F_300 ( V_245 , F_301 ( V_246 ) | F_301 ( V_247 ) ) ;
V_3 -> V_248 = 1 ;
V_3 -> V_245 = * V_245 ;
} else
V_3 -> V_248 = 0 ;
return 0 ;
}
static long F_302 ( struct V_100 * V_101 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
void V_128 * V_251 = ( void V_128 * ) V_250 ;
int V_26 ;
struct V_252 * V_253 = NULL ;
struct V_254 * V_254 = NULL ;
if ( V_3 -> V_9 -> V_43 != V_57 -> V_43 )
return - V_255 ;
if ( F_25 ( F_303 ( V_249 ) != V_256 ) )
return - V_114 ;
#if F_109 ( V_257 ) || F_109 ( V_258 ) || F_109 ( V_259 )
if ( V_249 == V_260 || V_249 == V_261 || V_249 == V_262 )
return F_304 ( V_101 , V_249 , V_250 ) ;
#endif
V_26 = F_5 ( V_3 ) ;
if ( V_26 )
return V_26 ;
switch ( V_249 ) {
case V_263 :
V_26 = - V_114 ;
if ( V_250 )
goto V_121;
if ( F_25 ( V_3 -> V_28 != V_57 -> V_264 [ V_218 ] . V_28 ) ) {
struct V_28 * V_265 = V_3 -> V_28 ;
struct V_28 * V_266 = F_305 ( V_57 , V_218 ) ;
F_128 ( V_3 -> V_28 , V_266 ) ;
if ( V_265 )
F_306 () ;
F_44 ( V_265 ) ;
}
V_26 = F_307 ( V_3 , V_3 -> V_37 ) ;
F_308 ( V_3 -> V_37 -> V_267 , V_26 ) ;
break;
case V_268 : {
struct V_269 * V_269 ;
V_26 = - V_35 ;
V_269 = F_88 ( sizeof( struct V_269 ) , V_33 ) ;
if ( ! V_269 )
goto V_121;
V_26 = F_309 ( V_3 , V_269 ) ;
if ( V_26 )
goto V_270;
V_26 = - V_145 ;
if ( F_144 ( V_251 , V_269 , sizeof( struct V_269 ) ) )
goto V_270;
V_26 = 0 ;
V_270:
F_97 ( V_269 ) ;
break;
}
case V_271 : {
struct V_269 * V_269 ;
V_26 = - V_35 ;
V_269 = F_310 ( V_251 , sizeof( * V_269 ) ) ;
if ( F_290 ( V_269 ) ) {
V_26 = F_291 ( V_269 ) ;
goto V_121;
}
V_26 = F_311 ( V_3 , V_269 ) ;
F_97 ( V_269 ) ;
break;
}
case V_272 : {
V_254 = F_88 ( sizeof( struct V_254 ) , V_33 ) ;
V_26 = - V_35 ;
if ( ! V_254 )
goto V_121;
V_26 = F_312 ( V_3 , V_254 ) ;
if ( V_26 )
goto V_121;
V_26 = - V_145 ;
if ( F_144 ( V_251 , V_254 , sizeof( struct V_254 ) ) )
goto V_121;
V_26 = 0 ;
break;
}
case V_273 : {
V_254 = F_310 ( V_251 , sizeof( * V_254 ) ) ;
if ( F_290 ( V_254 ) ) {
V_26 = F_291 ( V_254 ) ;
V_254 = NULL ;
goto V_121;
}
V_26 = F_313 ( V_3 , V_254 ) ;
break;
}
case V_274 : {
struct V_275 V_276 ;
V_26 = F_314 ( V_3 , & V_276 ) ;
if ( V_26 )
goto V_121;
V_26 = - V_145 ;
if ( F_144 ( V_251 , & V_276 , sizeof( V_276 ) ) )
goto V_121;
V_26 = 0 ;
break;
}
case V_277 : {
struct V_275 V_276 ;
V_26 = - V_145 ;
if ( F_315 ( & V_276 , V_251 , sizeof( V_276 ) ) )
goto V_121;
V_26 = F_316 ( V_3 , & V_276 ) ;
break;
}
case V_278 : {
struct V_279 V_280 ;
V_26 = - V_145 ;
if ( F_315 ( & V_280 , V_251 , sizeof( V_280 ) ) )
goto V_121;
V_26 = F_317 ( V_3 , & V_280 ) ;
if ( V_26 )
goto V_121;
V_26 = - V_145 ;
if ( F_144 ( V_251 , & V_280 , sizeof( V_280 ) ) )
goto V_121;
V_26 = 0 ;
break;
}
case V_281 : {
struct V_282 V_283 ;
V_26 = - V_145 ;
if ( F_315 ( & V_283 , V_251 , sizeof( V_283 ) ) )
goto V_121;
V_26 = F_318 ( V_3 , & V_283 ) ;
break;
}
case V_284 : {
struct V_285 V_128 * V_286 = V_251 ;
struct V_285 V_287 ;
T_10 V_245 , * V_288 ;
V_288 = NULL ;
if ( V_251 ) {
V_26 = - V_145 ;
if ( F_315 ( & V_287 , V_251 ,
sizeof( V_287 ) ) )
goto V_121;
V_26 = - V_114 ;
if ( V_287 . V_188 != sizeof( V_245 ) )
goto V_121;
V_26 = - V_145 ;
if ( F_315 ( & V_245 , V_286 -> V_245 ,
sizeof( V_245 ) ) )
goto V_121;
V_288 = & V_245 ;
}
V_26 = F_299 ( V_3 , V_288 ) ;
break;
}
case V_289 : {
V_253 = F_88 ( sizeof( struct V_252 ) , V_33 ) ;
V_26 = - V_35 ;
if ( ! V_253 )
goto V_121;
V_26 = F_319 ( V_3 , V_253 ) ;
if ( V_26 )
goto V_121;
V_26 = - V_145 ;
if ( F_144 ( V_251 , V_253 , sizeof( struct V_252 ) ) )
goto V_121;
V_26 = 0 ;
break;
}
case V_290 : {
V_253 = F_310 ( V_251 , sizeof( * V_253 ) ) ;
if ( F_290 ( V_253 ) ) {
V_26 = F_291 ( V_253 ) ;
V_253 = NULL ;
goto V_121;
}
V_26 = F_320 ( V_3 , V_253 ) ;
break;
}
default:
V_26 = F_304 ( V_101 , V_249 , V_250 ) ;
}
V_121:
F_11 ( V_3 ) ;
F_97 ( V_253 ) ;
F_97 ( V_254 ) ;
return V_26 ;
}
static long F_321 ( struct V_100 * V_101 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
void V_128 * V_251 = F_322 ( V_250 ) ;
int V_26 ;
if ( V_3 -> V_9 -> V_43 != V_57 -> V_43 )
return - V_255 ;
switch ( V_249 ) {
case V_284 : {
struct V_285 V_128 * V_286 = V_251 ;
struct V_285 V_287 ;
T_11 V_291 ;
T_10 V_245 ;
if ( V_251 ) {
V_26 = - V_145 ;
if ( F_315 ( & V_287 , V_251 ,
sizeof( V_287 ) ) )
goto V_121;
V_26 = - V_114 ;
if ( V_287 . V_188 != sizeof( V_291 ) )
goto V_121;
V_26 = - V_145 ;
if ( F_315 ( & V_291 , V_286 -> V_245 ,
sizeof( V_291 ) ) )
goto V_121;
F_323 ( & V_245 , & V_291 ) ;
V_26 = F_299 ( V_3 , & V_245 ) ;
} else
V_26 = F_299 ( V_3 , NULL ) ;
break;
}
default:
V_26 = F_302 ( V_101 , V_249 , V_250 ) ;
}
V_121:
return V_26 ;
}
static int F_324 ( struct V_93 * V_94 ,
int (* F_325)( struct V_93 * V_94 ,
struct V_292 * V_293 ) ,
unsigned long V_250 )
{
struct V_292 V_293 ;
if ( ! F_325 )
return - V_294 ;
if ( F_315 ( & V_293 , ( void V_128 * ) V_250 , sizeof( V_293 ) ) )
return - V_145 ;
return F_325 ( V_94 , & V_293 ) ;
}
static long F_326 ( struct V_100 * V_101 , unsigned int V_249 ,
unsigned long V_250 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
switch ( V_249 ) {
case V_295 :
return F_324 ( V_94 , V_94 -> V_55 -> V_296 , V_250 ) ;
case V_297 :
return F_324 ( V_94 , V_94 -> V_55 -> V_298 , V_250 ) ;
case V_299 :
return F_324 ( V_94 , V_94 -> V_55 -> V_300 , V_250 ) ;
default:
if ( V_94 -> V_55 -> V_249 )
return V_94 -> V_55 -> V_249 ( V_94 , V_249 , V_250 ) ;
return - V_301 ;
}
}
static int F_327 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
struct V_9 * V_9 = V_94 -> V_9 ;
F_115 ( V_9 ) ;
return 0 ;
}
struct V_93 * F_328 ( struct V_100 * V_101 )
{
if ( V_101 -> V_302 != & V_303 )
return NULL ;
return V_101 -> V_102 ;
}
int F_329 ( struct V_304 * V_55 , T_4 type )
{
if ( type >= F_330 ( V_305 ) )
return - V_306 ;
if ( V_305 [ type ] != NULL )
return - V_135 ;
V_305 [ type ] = V_55 ;
return 0 ;
}
void F_331 ( T_4 type )
{
if ( V_305 [ type ] != NULL )
V_305 [ type ] = NULL ;
}
static int F_332 ( struct V_9 * V_9 ,
struct V_307 * V_308 )
{
struct V_304 * V_55 = NULL ;
struct V_93 * V_94 ;
bool V_309 = V_308 -> V_113 & V_310 ;
int V_192 ;
if ( V_308 -> type >= F_330 ( V_305 ) )
return - V_311 ;
V_55 = V_305 [ V_308 -> type ] ;
if ( V_55 == NULL )
return - V_311 ;
if ( V_309 )
return 0 ;
V_94 = F_88 ( sizeof( * V_94 ) , V_33 ) ;
if ( ! V_94 )
return - V_35 ;
V_94 -> V_55 = V_55 ;
V_94 -> V_9 = V_9 ;
V_192 = V_55 -> V_312 ( V_94 , V_308 -> type ) ;
if ( V_192 < 0 ) {
F_97 ( V_94 ) ;
return V_192 ;
}
V_192 = F_287 ( V_55 -> V_313 , & V_303 , V_94 , V_237 | V_238 ) ;
if ( V_192 < 0 ) {
V_55 -> V_96 ( V_94 ) ;
return V_192 ;
}
F_93 ( & V_94 -> V_95 , & V_9 -> V_85 ) ;
F_114 ( V_9 ) ;
V_308 -> V_314 = V_192 ;
return 0 ;
}
static long F_333 ( struct V_9 * V_9 , long V_250 )
{
switch ( V_250 ) {
case V_315 :
case V_316 :
case V_317 :
case V_318 :
#ifdef F_334
case V_319 :
#endif
#ifdef F_84
case V_320 :
case V_321 :
#endif
case V_322 :
case V_323 :
return 1 ;
#ifdef F_335
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
return F_336 ( V_9 , V_250 ) ;
}
static long F_337 ( struct V_100 * V_101 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_9 * V_9 = V_101 -> V_102 ;
void V_128 * V_251 = ( void V_128 * ) V_250 ;
int V_26 ;
if ( V_9 -> V_43 != V_57 -> V_43 )
return - V_255 ;
switch ( V_249 ) {
case V_327 :
V_26 = F_288 ( V_9 , V_250 ) ;
break;
case V_328 : {
struct V_108 V_329 ;
V_26 = - V_145 ;
if ( F_315 ( & V_329 , V_251 ,
sizeof( V_329 ) ) )
goto V_121;
V_26 = F_142 ( V_9 , & V_329 ) ;
break;
}
case V_330 : {
struct V_140 log ;
V_26 = - V_145 ;
if ( F_315 ( & log , V_251 , sizeof( log ) ) )
goto V_121;
V_26 = F_338 ( V_9 , & log ) ;
break;
}
#ifdef F_282
case V_331 : {
struct V_332 V_333 ;
V_26 = - V_145 ;
if ( F_315 ( & V_333 , V_251 , sizeof( V_333 ) ) )
goto V_121;
V_26 = F_339 ( V_9 , & V_333 ) ;
break;
}
case V_334 : {
struct V_332 V_333 ;
V_26 = - V_145 ;
if ( F_315 ( & V_333 , V_251 , sizeof( V_333 ) ) )
goto V_121;
V_26 = F_340 ( V_9 , & V_333 ) ;
break;
}
#endif
case V_335 : {
struct V_336 V_189 ;
V_26 = - V_145 ;
if ( F_315 ( & V_189 , V_251 , sizeof( V_189 ) ) )
goto V_121;
V_26 = V_336 ( V_9 , & V_189 ) ;
break;
}
case V_337 : {
struct V_338 V_189 ;
V_26 = - V_145 ;
if ( F_315 ( & V_189 , V_251 , sizeof( V_189 ) ) )
goto V_121;
V_26 = V_338 ( V_9 , & V_189 ) ;
break;
}
#ifdef F_334
case V_339 : {
struct V_340 V_341 ;
V_26 = - V_145 ;
if ( F_315 ( & V_341 , V_251 , sizeof( V_341 ) ) )
goto V_121;
V_26 = F_341 ( V_9 , & V_341 ) ;
break;
}
#endif
#ifdef F_342
case V_342 :
case V_343 : {
struct V_344 V_345 ;
V_26 = - V_145 ;
if ( F_315 ( & V_345 , V_251 , sizeof( V_345 ) ) )
goto V_121;
V_26 = F_343 ( V_9 , & V_345 ,
V_249 == V_342 ) ;
if ( V_26 )
goto V_121;
V_26 = - V_145 ;
if ( V_249 == V_342 ) {
if ( F_144 ( V_251 , & V_345 , sizeof( V_345 ) ) )
goto V_121;
}
V_26 = 0 ;
break;
}
#endif
#ifdef F_335
case V_346 : {
struct V_347 V_348 ;
struct V_347 V_128 * V_349 ;
struct V_350 * V_351 ;
V_26 = - V_145 ;
if ( F_315 ( & V_348 , V_251 , sizeof( V_348 ) ) )
goto V_121;
V_26 = - V_114 ;
if ( V_348 . V_352 >= V_325 )
goto V_121;
if ( V_348 . V_113 )
goto V_121;
V_26 = - V_35 ;
V_351 = F_344 ( V_348 . V_352 * sizeof( * V_351 ) ) ;
if ( ! V_351 )
goto V_121;
V_26 = - V_145 ;
V_349 = V_251 ;
if ( F_315 ( V_351 , V_349 -> V_351 ,
V_348 . V_352 * sizeof( * V_351 ) ) )
goto V_353;
V_26 = F_345 ( V_9 , V_351 , V_348 . V_352 ,
V_348 . V_113 ) ;
V_353:
F_346 ( V_351 ) ;
break;
}
#endif
case V_354 : {
struct V_307 V_308 ;
V_26 = - V_145 ;
if ( F_315 ( & V_308 , V_251 , sizeof( V_308 ) ) )
goto V_121;
V_26 = F_332 ( V_9 , & V_308 ) ;
if ( V_26 )
goto V_121;
V_26 = - V_145 ;
if ( F_144 ( V_251 , & V_308 , sizeof( V_308 ) ) )
goto V_121;
V_26 = 0 ;
break;
}
case V_355 :
V_26 = F_333 ( V_9 , V_250 ) ;
break;
default:
V_26 = F_347 ( V_101 , V_249 , V_250 ) ;
}
V_121:
return V_26 ;
}
static long F_348 ( struct V_100 * V_101 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_9 * V_9 = V_101 -> V_102 ;
int V_26 ;
if ( V_9 -> V_43 != V_57 -> V_43 )
return - V_255 ;
switch ( V_249 ) {
case V_330 : {
struct V_356 V_357 ;
struct V_140 log ;
V_26 = - V_145 ;
if ( F_315 ( & V_357 , ( void V_128 * ) V_250 ,
sizeof( V_357 ) ) )
goto V_121;
log . V_117 = V_357 . V_117 ;
log . V_358 = V_357 . V_358 ;
log . V_359 = V_357 . V_359 ;
log . V_66 = F_322 ( V_357 . V_66 ) ;
V_26 = F_338 ( V_9 , & log ) ;
break;
}
default:
V_26 = F_337 ( V_101 , V_249 , V_250 ) ;
}
V_121:
return V_26 ;
}
static int F_349 ( unsigned long type )
{
int V_26 ;
struct V_9 * V_9 ;
V_9 = F_79 ( type ) ;
if ( F_290 ( V_9 ) )
return F_291 ( V_9 ) ;
#ifdef F_282
V_26 = F_350 ( V_9 ) ;
if ( V_26 < 0 ) {
F_115 ( V_9 ) ;
return V_26 ;
}
#endif
V_26 = F_287 ( L_2 , & V_360 , V_9 , V_237 | V_238 ) ;
if ( V_26 < 0 )
F_115 ( V_9 ) ;
return V_26 ;
}
static long F_351 ( struct V_100 * V_101 ,
unsigned int V_249 , unsigned long V_250 )
{
long V_26 = - V_114 ;
switch ( V_249 ) {
case V_361 :
if ( V_250 )
goto V_121;
V_26 = V_362 ;
break;
case V_363 :
V_26 = F_349 ( V_250 ) ;
break;
case V_355 :
V_26 = F_333 ( NULL , V_250 ) ;
break;
case V_364 :
if ( V_250 )
goto V_121;
V_26 = V_89 ;
#ifdef F_281
V_26 += V_89 ;
#endif
#ifdef F_282
V_26 += V_89 ;
#endif
break;
case V_365 :
case V_366 :
case V_367 :
V_26 = - V_368 ;
break;
default:
return F_352 ( V_101 , V_249 , V_250 ) ;
}
V_121:
return V_26 ;
}
static void F_353 ( void * V_369 )
{
int V_4 = F_354 () ;
int V_26 ;
if ( F_355 ( V_4 , V_370 ) )
return;
F_24 ( V_4 , V_370 ) ;
V_26 = F_356 () ;
if ( V_26 ) {
F_357 ( V_4 , V_370 ) ;
F_90 ( & V_371 ) ;
F_358 ( L_3 , V_4 ) ;
}
}
static void F_359 ( void )
{
F_360 ( & V_372 ) ;
if ( V_373 )
F_353 ( NULL ) ;
F_361 ( & V_372 ) ;
}
static void F_362 ( void * V_369 )
{
int V_4 = F_354 () ;
if ( ! F_355 ( V_4 , V_370 ) )
return;
F_357 ( V_4 , V_370 ) ;
F_363 () ;
}
static void F_364 ( void )
{
F_360 ( & V_372 ) ;
if ( V_373 )
F_362 ( NULL ) ;
F_361 ( & V_372 ) ;
}
static void F_365 ( void )
{
F_61 ( ! V_373 ) ;
V_373 -- ;
if ( ! V_373 )
F_366 ( F_362 , NULL , 1 ) ;
}
static void F_96 ( void )
{
F_360 ( & V_372 ) ;
F_365 () ;
F_361 ( & V_372 ) ;
}
static int F_83 ( void )
{
int V_26 = 0 ;
F_360 ( & V_372 ) ;
V_373 ++ ;
if ( V_373 == 1 ) {
F_92 ( & V_371 , 0 ) ;
F_366 ( F_353 , NULL , 1 ) ;
if ( F_295 ( & V_371 ) ) {
F_365 () ;
V_26 = - V_374 ;
}
}
F_361 ( & V_372 ) ;
return V_26 ;
}
static int F_367 ( struct V_375 * V_376 , unsigned long V_201 ,
void * V_377 )
{
V_201 &= ~ V_378 ;
switch ( V_201 ) {
case V_379 :
F_364 () ;
break;
case V_380 :
F_359 () ;
break;
}
return V_381 ;
}
static int F_368 ( struct V_375 * V_376 , unsigned long V_201 ,
void * V_377 )
{
F_358 ( L_4 ) ;
V_382 = true ;
F_366 ( F_362 , NULL , 1 ) ;
return V_381 ;
}
static void F_107 ( struct V_78 * V_383 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_383 -> V_384 ; V_11 ++ ) {
struct V_385 * V_386 = V_383 -> V_387 [ V_11 ] . V_94 ;
F_369 ( V_386 ) ;
}
F_97 ( V_383 ) ;
}
static inline int F_370 ( const struct V_388 * V_389 ,
const struct V_388 * V_390 )
{
T_6 V_391 = V_389 -> V_154 ;
T_6 V_392 = V_390 -> V_154 ;
if ( V_391 < V_392 )
return - 1 ;
if ( V_390 -> V_188 ) {
V_391 += V_389 -> V_188 ;
V_392 += V_390 -> V_188 ;
}
if ( V_391 > V_392 )
return 1 ;
return 0 ;
}
static int F_371 ( const void * V_393 , const void * V_394 )
{
return F_370 ( V_393 , V_394 ) ;
}
static int F_372 ( struct V_78 * V_383 , struct V_385 * V_94 ,
T_6 V_154 , int V_188 )
{
V_383 -> V_387 [ V_383 -> V_384 ++ ] = (struct V_388 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
. V_94 = V_94 ,
} ;
F_373 ( V_383 -> V_387 , V_383 -> V_384 , sizeof( struct V_388 ) ,
F_371 , NULL ) ;
return 0 ;
}
static int F_374 ( struct V_78 * V_383 ,
T_6 V_154 , int V_188 )
{
struct V_388 * V_387 , V_395 ;
int V_396 ;
V_395 = (struct V_388 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_387 = bsearch ( & V_395 , V_383 -> V_387 , V_383 -> V_384 ,
sizeof( struct V_388 ) , F_371 ) ;
if ( V_387 == NULL )
return - V_144 ;
V_396 = V_387 - V_383 -> V_387 ;
while ( V_396 > 0 && F_370 ( & V_395 , & V_383 -> V_387 [ V_396 - 1 ] ) == 0 )
V_396 -- ;
return V_396 ;
}
static int F_375 ( struct V_2 * V_3 , struct V_78 * V_383 ,
struct V_388 * V_387 , const void * V_201 )
{
int V_46 ;
V_46 = F_374 ( V_383 , V_387 -> V_154 , V_387 -> V_188 ) ;
if ( V_46 < 0 )
return - V_368 ;
while ( V_46 < V_383 -> V_384 &&
F_370 ( V_387 , & V_383 -> V_387 [ V_46 ] ) == 0 ) {
if ( ! F_376 ( V_3 , V_383 -> V_387 [ V_46 ] . V_94 , V_387 -> V_154 ,
V_387 -> V_188 , V_201 ) )
return V_46 ;
V_46 ++ ;
}
return - V_368 ;
}
int F_377 ( struct V_2 * V_3 , enum V_397 V_398 , T_6 V_154 ,
int V_188 , const void * V_201 )
{
struct V_78 * V_383 ;
struct V_388 V_387 ;
int V_26 ;
V_387 = (struct V_388 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_383 = F_378 ( V_3 -> V_9 -> V_77 [ V_398 ] , & V_3 -> V_9 -> V_47 ) ;
V_26 = F_375 ( V_3 , V_383 , & V_387 , V_201 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_379 ( struct V_2 * V_3 , enum V_397 V_398 ,
T_6 V_154 , int V_188 , const void * V_201 , long V_399 )
{
struct V_78 * V_383 ;
struct V_388 V_387 ;
V_387 = (struct V_388 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_383 = F_378 ( V_3 -> V_9 -> V_77 [ V_398 ] , & V_3 -> V_9 -> V_47 ) ;
if ( ( V_399 >= 0 ) && ( V_399 < V_383 -> V_384 ) &&
( F_370 ( & V_387 , & V_383 -> V_387 [ V_399 ] ) == 0 ) )
if ( ! F_376 ( V_3 , V_383 -> V_387 [ V_399 ] . V_94 , V_154 , V_188 ,
V_201 ) )
return V_399 ;
return F_375 ( V_3 , V_383 , & V_387 , V_201 ) ;
}
static int F_380 ( struct V_2 * V_3 , struct V_78 * V_383 ,
struct V_388 * V_387 , void * V_201 )
{
int V_46 ;
V_46 = F_374 ( V_383 , V_387 -> V_154 , V_387 -> V_188 ) ;
if ( V_46 < 0 )
return - V_368 ;
while ( V_46 < V_383 -> V_384 &&
F_370 ( V_387 , & V_383 -> V_387 [ V_46 ] ) == 0 ) {
if ( ! F_381 ( V_3 , V_383 -> V_387 [ V_46 ] . V_94 , V_387 -> V_154 ,
V_387 -> V_188 , V_201 ) )
return V_46 ;
V_46 ++ ;
}
return - V_368 ;
}
int F_382 ( struct V_2 * V_3 , enum V_397 V_398 , T_6 V_154 ,
int V_188 , void * V_201 )
{
struct V_78 * V_383 ;
struct V_388 V_387 ;
int V_26 ;
V_387 = (struct V_388 ) {
. V_154 = V_154 ,
. V_188 = V_188 ,
} ;
V_383 = F_378 ( V_3 -> V_9 -> V_77 [ V_398 ] , & V_3 -> V_9 -> V_47 ) ;
V_26 = F_380 ( V_3 , V_383 , & V_387 , V_201 ) ;
return V_26 < 0 ? V_26 : 0 ;
}
int F_383 ( struct V_9 * V_9 , enum V_397 V_398 , T_6 V_154 ,
int V_188 , struct V_385 * V_94 )
{
struct V_78 * V_400 , * V_383 ;
V_383 = V_9 -> V_77 [ V_398 ] ;
if ( V_383 -> V_384 - V_383 -> V_401 > V_402 - 1 )
return - V_306 ;
V_400 = F_384 ( sizeof( * V_383 ) + ( ( V_383 -> V_384 + 1 ) *
sizeof( struct V_388 ) ) , V_33 ) ;
if ( ! V_400 )
return - V_35 ;
memcpy ( V_400 , V_383 , sizeof( * V_383 ) + ( V_383 -> V_384 *
sizeof( struct V_388 ) ) ) ;
F_372 ( V_400 , V_94 , V_154 , V_188 ) ;
F_128 ( V_9 -> V_77 [ V_398 ] , V_400 ) ;
F_129 ( & V_9 -> V_47 ) ;
F_97 ( V_383 ) ;
return 0 ;
}
int F_385 ( struct V_9 * V_9 , enum V_397 V_398 ,
struct V_385 * V_94 )
{
int V_11 , V_26 ;
struct V_78 * V_400 , * V_383 ;
V_383 = V_9 -> V_77 [ V_398 ] ;
V_26 = - V_144 ;
for ( V_11 = 0 ; V_11 < V_383 -> V_384 ; V_11 ++ )
if ( V_383 -> V_387 [ V_11 ] . V_94 == V_94 ) {
V_26 = 0 ;
break;
}
if ( V_26 )
return V_26 ;
V_400 = F_384 ( sizeof( * V_383 ) + ( ( V_383 -> V_384 - 1 ) *
sizeof( struct V_388 ) ) , V_33 ) ;
if ( ! V_400 )
return - V_35 ;
memcpy ( V_400 , V_383 , sizeof( * V_383 ) + V_11 * sizeof( struct V_388 ) ) ;
V_400 -> V_384 -- ;
memcpy ( V_400 -> V_387 + V_11 , V_383 -> V_387 + V_11 + 1 ,
( V_400 -> V_384 - V_11 ) * sizeof( struct V_388 ) ) ;
F_128 ( V_9 -> V_77 [ V_398 ] , V_400 ) ;
F_129 ( & V_9 -> V_47 ) ;
F_97 ( V_383 ) ;
return V_26 ;
}
static int F_386 ( void * V_403 , T_8 * V_201 )
{
unsigned V_148 = ( long ) V_403 ;
struct V_9 * V_9 ;
* V_201 = 0 ;
F_50 ( & V_86 ) ;
F_387 ( V_9 , & V_87 , V_87 )
* V_201 += * ( T_4 * ) ( ( void * ) V_9 + V_148 ) ;
F_52 ( & V_86 ) ;
return 0 ;
}
static int F_388 ( void * V_403 , T_8 * V_201 )
{
unsigned V_148 = ( long ) V_403 ;
struct V_9 * V_9 ;
struct V_2 * V_3 ;
int V_11 ;
* V_201 = 0 ;
F_50 ( & V_86 ) ;
F_387 (kvm, &vm_list, vm_list)
F_20 ( V_11 , V_3 , V_9 )
* V_201 += * ( T_4 * ) ( ( void * ) V_3 + V_148 ) ;
F_52 ( & V_86 ) ;
return 0 ;
}
static int F_389 ( void )
{
int V_26 = - V_135 ;
struct V_404 * V_288 ;
V_405 = F_390 ( L_5 , NULL ) ;
if ( V_405 == NULL )
goto V_121;
for ( V_288 = V_406 ; V_288 -> V_313 ; ++ V_288 ) {
if ( ! F_391 ( V_288 -> V_313 , 0444 , V_405 ,
( void * ) ( long ) V_288 -> V_148 ,
V_407 [ V_288 -> V_408 ] ) )
goto V_409;
}
return 0 ;
V_409:
F_392 ( V_405 ) ;
V_121:
return V_26 ;
}
static int F_393 ( void )
{
if ( V_373 )
F_362 ( NULL ) ;
return 0 ;
}
static void F_394 ( void )
{
if ( V_373 ) {
F_122 ( F_395 ( & V_372 ) ) ;
F_353 ( NULL ) ;
}
}
static inline
struct V_2 * F_396 ( struct V_7 * V_410 )
{
return F_47 ( V_410 , struct V_2 , V_7 ) ;
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
int V_26 ;
int V_4 ;
V_26 = F_401 ( V_414 ) ;
if ( V_26 )
goto V_418;
V_26 = F_402 () ;
if ( V_26 )
goto V_419;
if ( ! F_19 ( & V_370 , V_33 ) ) {
V_26 = - V_35 ;
goto V_420;
}
V_26 = F_403 () ;
if ( V_26 < 0 )
goto V_421;
F_404 (cpu) {
F_405 ( V_4 ,
V_422 ,
& V_26 , 1 ) ;
if ( V_26 < 0 )
goto V_423;
}
V_26 = F_406 ( & V_424 ) ;
if ( V_26 )
goto V_425;
F_407 ( & V_426 ) ;
if ( ! V_416 )
V_416 = F_408 ( struct V_2 ) ;
V_427 = F_409 ( L_6 , V_415 , V_416 ,
0 , NULL ) ;
if ( ! V_427 ) {
V_26 = - V_35 ;
goto V_428;
}
V_26 = F_410 () ;
if ( V_26 )
goto V_136;
V_429 . V_430 = V_417 ;
V_360 . V_430 = V_417 ;
V_236 . V_430 = V_417 ;
V_26 = F_411 ( & V_431 ) ;
if ( V_26 ) {
F_412 ( L_7 ) ;
goto V_432;
}
F_413 ( & V_433 ) ;
V_240 . V_434 = F_397 ;
V_240 . V_435 = F_399 ;
V_26 = F_389 () ;
if ( V_26 ) {
F_412 ( L_8 ) ;
goto V_436;
}
V_26 = F_414 () ;
F_122 ( V_26 ) ;
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
return V_26 ;
}
void F_424 ( void )
{
F_392 ( V_405 ) ;
F_416 ( & V_431 ) ;
F_418 ( V_427 ) ;
F_417 () ;
F_415 ( & V_433 ) ;
F_419 ( & V_426 ) ;
F_420 ( & V_424 ) ;
F_366 ( F_362 , NULL , 1 ) ;
F_421 () ;
F_423 () ;
F_422 () ;
F_28 ( V_370 ) ;
F_425 () ;
}
