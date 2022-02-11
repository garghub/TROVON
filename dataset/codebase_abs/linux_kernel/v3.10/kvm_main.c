bool F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 ) ) {
int V_2 ;
struct V_3 * V_4 = F_3 ( V_1 ) ;
struct V_3 * V_5 = F_4 ( V_4 ) ;
V_2 = F_5 ( V_5 ) ;
if ( V_5 != V_4 ) {
F_6 () ;
if ( F_7 ( V_4 ) )
return V_2 ;
}
return F_5 ( V_4 ) ;
}
return true ;
}
int F_8 ( struct V_6 * V_7 )
{
int V_8 ;
if ( F_9 ( & V_7 -> V_9 ) )
return - V_10 ;
if ( F_10 ( V_7 -> V_11 != V_12 -> V_13 [ V_14 ] . V_11 ) ) {
struct V_11 * V_15 = V_7 -> V_11 ;
struct V_11 * V_16 = F_11 ( V_12 , V_14 ) ;
F_12 ( V_7 -> V_11 , V_16 ) ;
F_13 () ;
F_14 ( V_15 ) ;
}
V_8 = F_15 () ;
F_16 ( & V_7 -> V_17 ) ;
F_17 ( V_7 , V_8 ) ;
F_18 () ;
return 0 ;
}
void F_19 ( struct V_6 * V_7 )
{
F_20 () ;
F_21 ( V_7 ) ;
F_22 ( & V_7 -> V_17 ) ;
F_23 () ;
F_24 ( & V_7 -> V_9 ) ;
}
static void F_25 ( void * V_18 )
{
}
static bool F_26 ( struct V_19 * V_19 , unsigned int V_20 )
{
int V_21 , V_8 , V_22 ;
T_2 V_23 ;
bool V_24 = true ;
struct V_6 * V_7 ;
F_27 ( & V_23 , V_25 ) ;
V_22 = F_15 () ;
F_28 (i, vcpu, kvm) {
F_29 ( V_20 , V_7 ) ;
V_8 = V_7 -> V_8 ;
F_30 () ;
if ( V_23 != NULL && V_8 != - 1 && V_8 != V_22 &&
F_31 ( V_7 ) != V_26 )
F_32 ( V_8 , V_23 ) ;
}
if ( F_10 ( V_23 == NULL ) )
F_33 ( V_27 , F_25 , NULL , 1 ) ;
else if ( ! F_34 ( V_23 ) )
F_33 ( V_23 , F_25 , NULL , 1 ) ;
else
V_24 = false ;
F_18 () ;
F_35 ( V_23 ) ;
return V_24 ;
}
void F_36 ( struct V_19 * V_19 )
{
long V_28 = V_19 -> V_29 ;
F_30 () ;
if ( F_26 ( V_19 , V_30 ) )
++ V_19 -> V_31 . V_32 ;
F_37 ( & V_19 -> V_29 , V_28 , 0 ) ;
}
void F_38 ( struct V_19 * V_19 )
{
F_26 ( V_19 , V_33 ) ;
}
void F_39 ( struct V_19 * V_19 )
{
F_26 ( V_19 , V_34 ) ;
}
void F_40 ( struct V_19 * V_19 )
{
F_26 ( V_19 , V_35 ) ;
}
int F_41 ( struct V_6 * V_7 , struct V_19 * V_19 , unsigned V_36 )
{
struct V_3 * V_3 ;
int V_37 ;
F_42 ( & V_7 -> V_9 ) ;
V_7 -> V_8 = - 1 ;
V_7 -> V_19 = V_19 ;
V_7 -> V_38 = V_36 ;
V_7 -> V_11 = NULL ;
F_43 ( & V_7 -> V_39 ) ;
F_44 ( V_7 ) ;
V_3 = F_45 ( V_40 | V_41 ) ;
if ( ! V_3 ) {
V_37 = - V_42 ;
goto V_43;
}
V_7 -> V_44 = F_46 ( V_3 ) ;
F_47 ( V_7 , false ) ;
F_48 ( V_7 , false ) ;
V_7 -> V_45 = false ;
V_37 = F_49 ( V_7 ) ;
if ( V_37 < 0 )
goto V_46;
return 0 ;
V_46:
F_50 ( ( unsigned long ) V_7 -> V_44 ) ;
V_43:
return V_37 ;
}
void F_51 ( struct V_6 * V_7 )
{
F_14 ( V_7 -> V_11 ) ;
F_52 ( V_7 ) ;
F_50 ( ( unsigned long ) V_7 -> V_44 ) ;
}
static inline struct V_19 * F_53 ( struct V_47 * V_48 )
{
return F_54 ( V_48 , struct V_19 , V_47 ) ;
}
static void F_55 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
unsigned long V_51 )
{
struct V_19 * V_19 = F_53 ( V_48 ) ;
int V_52 , V_53 ;
V_53 = F_56 ( & V_19 -> V_54 ) ;
F_57 ( & V_19 -> V_55 ) ;
V_19 -> V_56 ++ ;
V_52 = F_58 ( V_19 , V_51 ) | V_19 -> V_29 ;
if ( V_52 )
F_36 ( V_19 ) ;
F_59 ( & V_19 -> V_55 ) ;
F_60 ( & V_19 -> V_54 , V_53 ) ;
}
static void F_61 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
unsigned long V_51 ,
T_3 V_57 )
{
struct V_19 * V_19 = F_53 ( V_48 ) ;
int V_53 ;
V_53 = F_56 ( & V_19 -> V_54 ) ;
F_57 ( & V_19 -> V_55 ) ;
V_19 -> V_56 ++ ;
F_62 ( V_19 , V_51 , V_57 ) ;
F_59 ( & V_19 -> V_55 ) ;
F_60 ( & V_19 -> V_54 , V_53 ) ;
}
static void F_63 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
unsigned long V_58 ,
unsigned long V_59 )
{
struct V_19 * V_19 = F_53 ( V_48 ) ;
int V_52 = 0 , V_53 ;
V_53 = F_56 ( & V_19 -> V_54 ) ;
F_57 ( & V_19 -> V_55 ) ;
V_19 -> V_60 ++ ;
V_52 = F_64 ( V_19 , V_58 , V_59 ) ;
V_52 |= V_19 -> V_29 ;
if ( V_52 )
F_36 ( V_19 ) ;
F_59 ( & V_19 -> V_55 ) ;
F_60 ( & V_19 -> V_54 , V_53 ) ;
}
static void F_65 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
unsigned long V_58 ,
unsigned long V_59 )
{
struct V_19 * V_19 = F_53 ( V_48 ) ;
F_57 ( & V_19 -> V_55 ) ;
V_19 -> V_56 ++ ;
F_66 () ;
V_19 -> V_60 -- ;
F_59 ( & V_19 -> V_55 ) ;
F_67 ( V_19 -> V_60 < 0 ) ;
}
static int F_68 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
unsigned long V_51 )
{
struct V_19 * V_19 = F_53 ( V_48 ) ;
int V_61 , V_53 ;
V_53 = F_56 ( & V_19 -> V_54 ) ;
F_57 ( & V_19 -> V_55 ) ;
V_61 = F_69 ( V_19 , V_51 ) ;
if ( V_61 )
F_36 ( V_19 ) ;
F_59 ( & V_19 -> V_55 ) ;
F_60 ( & V_19 -> V_54 , V_53 ) ;
return V_61 ;
}
static int F_70 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
unsigned long V_51 )
{
struct V_19 * V_19 = F_53 ( V_48 ) ;
int V_61 , V_53 ;
V_53 = F_56 ( & V_19 -> V_54 ) ;
F_57 ( & V_19 -> V_55 ) ;
V_61 = F_71 ( V_19 , V_51 ) ;
F_59 ( & V_19 -> V_55 ) ;
F_60 ( & V_19 -> V_54 , V_53 ) ;
return V_61 ;
}
static void F_72 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_19 * V_19 = F_53 ( V_48 ) ;
int V_53 ;
V_53 = F_56 ( & V_19 -> V_54 ) ;
F_73 ( V_19 ) ;
F_60 ( & V_19 -> V_54 , V_53 ) ;
}
static int F_74 ( struct V_19 * V_19 )
{
V_19 -> V_47 . V_62 = & V_63 ;
return F_75 ( & V_19 -> V_47 , V_12 -> V_50 ) ;
}
static int F_74 ( struct V_19 * V_19 )
{
return 0 ;
}
static void F_76 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_64 * V_65 = V_19 -> V_66 ;
for ( V_21 = 0 ; V_21 < V_67 ; V_21 ++ )
V_65 -> V_68 [ V_21 ] = V_65 -> V_66 [ V_21 ] . V_36 = V_21 ;
}
static struct V_19 * F_77 ( unsigned long type )
{
int V_37 , V_21 ;
struct V_19 * V_19 = F_78 () ;
if ( ! V_19 )
return F_79 ( - V_42 ) ;
V_37 = F_80 ( V_19 , type ) ;
if ( V_37 )
goto V_69;
V_37 = F_81 () ;
if ( V_37 )
goto V_69;
#ifdef F_82
F_83 ( & V_19 -> V_70 ) ;
F_83 ( & V_19 -> V_71 ) ;
#endif
F_84 ( V_67 > V_72 ) ;
V_37 = - V_42 ;
V_19 -> V_66 = F_85 ( sizeof( struct V_64 ) , V_40 ) ;
if ( ! V_19 -> V_66 )
goto V_73;
F_76 ( V_19 ) ;
if ( F_86 ( & V_19 -> V_54 ) )
goto V_73;
for ( V_21 = 0 ; V_21 < V_74 ; V_21 ++ ) {
V_19 -> V_75 [ V_21 ] = F_85 ( sizeof( struct V_76 ) ,
V_40 ) ;
if ( ! V_19 -> V_75 [ V_21 ] )
goto V_77;
}
F_87 ( & V_19 -> V_55 ) ;
V_19 -> V_50 = V_12 -> V_50 ;
F_88 ( & V_19 -> V_50 -> V_78 ) ;
F_89 ( V_19 ) ;
F_42 ( & V_19 -> V_79 ) ;
F_42 ( & V_19 -> V_80 ) ;
F_42 ( & V_19 -> V_81 ) ;
F_90 ( & V_19 -> V_82 , 1 ) ;
F_91 ( & V_19 -> V_83 ) ;
V_37 = F_74 ( V_19 ) ;
if ( V_37 )
goto V_77;
F_92 ( & V_84 ) ;
F_93 ( & V_19 -> V_85 , & V_85 ) ;
F_94 ( & V_84 ) ;
return V_19 ;
V_77:
F_95 ( & V_19 -> V_54 ) ;
V_73:
F_96 () ;
V_69:
for ( V_21 = 0 ; V_21 < V_74 ; V_21 ++ )
F_97 ( V_19 -> V_75 [ V_21 ] ) ;
F_97 ( V_19 -> V_66 ) ;
F_98 ( V_19 ) ;
return F_79 ( V_37 ) ;
}
void * F_99 ( unsigned long V_86 )
{
if ( V_86 > V_87 )
return F_100 ( V_86 ) ;
else
return F_85 ( V_86 , V_40 ) ;
}
void F_101 ( const void * V_88 )
{
if ( F_102 ( V_88 ) )
F_103 ( V_88 ) ;
else
F_97 ( V_88 ) ;
}
static void F_104 ( struct V_89 * V_90 )
{
if ( ! V_90 -> V_91 )
return;
F_101 ( V_90 -> V_91 ) ;
V_90 -> V_91 = NULL ;
}
static void F_105 ( struct V_89 * free ,
struct V_89 * V_92 )
{
if ( ! V_92 || free -> V_91 != V_92 -> V_91 )
F_104 ( free ) ;
F_106 ( free , V_92 ) ;
free -> V_93 = 0 ;
}
void F_107 ( struct V_19 * V_19 )
{
struct V_64 * V_65 = V_19 -> V_66 ;
struct V_89 * V_90 ;
F_108 (memslot, slots)
F_105 ( V_90 , NULL ) ;
F_97 ( V_19 -> V_66 ) ;
}
static void F_109 ( struct V_19 * V_19 )
{
struct V_94 * V_95 , * V_96 ;
F_110 (node, tmp, &kvm->devices) {
struct V_97 * V_98 =
F_111 ( V_95 , struct V_97 , V_99 ) ;
F_112 ( V_95 ) ;
V_98 -> V_62 -> V_100 ( V_98 ) ;
}
}
static void F_113 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_49 * V_50 = V_19 -> V_50 ;
F_114 ( V_19 ) ;
F_92 ( & V_84 ) ;
F_112 ( & V_19 -> V_85 ) ;
F_94 ( & V_84 ) ;
F_115 ( V_19 ) ;
for ( V_21 = 0 ; V_21 < V_74 ; V_21 ++ )
F_116 ( V_19 -> V_75 [ V_21 ] ) ;
F_117 ( V_19 ) ;
#if F_118 ( V_101 ) && F_118 ( V_102 )
F_119 ( & V_19 -> V_47 , V_19 -> V_50 ) ;
#else
F_73 ( V_19 ) ;
#endif
F_120 ( V_19 ) ;
F_109 ( V_19 ) ;
F_107 ( V_19 ) ;
F_95 ( & V_19 -> V_54 ) ;
F_98 ( V_19 ) ;
F_96 () ;
F_121 ( V_50 ) ;
}
void F_122 ( struct V_19 * V_19 )
{
F_88 ( & V_19 -> V_82 ) ;
}
void F_123 ( struct V_19 * V_19 )
{
if ( F_124 ( & V_19 -> V_82 ) )
F_113 ( V_19 ) ;
}
static int F_125 ( struct V_103 * V_103 , struct V_104 * V_105 )
{
struct V_19 * V_19 = V_105 -> V_106 ;
F_126 ( V_19 ) ;
F_123 ( V_19 ) ;
return 0 ;
}
static int F_127 ( struct V_89 * V_90 )
{
#ifndef F_128
unsigned long V_107 = 2 * F_129 ( V_90 ) ;
V_90 -> V_91 = F_99 ( V_107 ) ;
if ( ! V_90 -> V_91 )
return - V_42 ;
#endif
return 0 ;
}
static int F_130 ( const void * V_108 , const void * V_109 )
{
struct V_89 * V_110 , * V_111 ;
V_110 = (struct V_89 * ) V_108 ;
V_111 = (struct V_89 * ) V_109 ;
if ( V_110 -> V_93 < V_111 -> V_93 )
return 1 ;
if ( V_110 -> V_93 > V_111 -> V_93 )
return - 1 ;
return 0 ;
}
static void F_131 ( struct V_64 * V_65 )
{
int V_21 ;
F_132 ( V_65 -> V_66 , V_67 ,
sizeof( struct V_89 ) , F_130 , NULL ) ;
for ( V_21 = 0 ; V_21 < V_67 ; V_21 ++ )
V_65 -> V_68 [ V_65 -> V_66 [ V_21 ] . V_36 ] = V_21 ;
}
void F_133 ( struct V_64 * V_65 , struct V_89 * V_112 ,
T_4 V_113 )
{
if ( V_112 ) {
int V_36 = V_112 -> V_36 ;
struct V_89 * V_114 = F_134 ( V_65 , V_36 ) ;
unsigned long V_93 = V_114 -> V_93 ;
* V_114 = * V_112 ;
if ( V_112 -> V_93 != V_93 )
F_131 ( V_65 ) ;
}
V_65 -> V_115 = V_113 + 1 ;
}
static int F_135 ( struct V_116 * V_117 )
{
T_5 V_118 = V_119 ;
#ifdef F_136
V_118 |= V_120 ;
#endif
if ( V_117 -> V_121 & ~ V_118 )
return - V_122 ;
return 0 ;
}
static struct V_64 * F_137 ( struct V_19 * V_19 ,
struct V_64 * V_65 , struct V_89 * V_112 )
{
struct V_64 * V_123 = V_19 -> V_66 ;
F_133 ( V_65 , V_112 , V_19 -> V_66 -> V_115 ) ;
F_12 ( V_19 -> V_66 , V_65 ) ;
F_138 ( & V_19 -> V_54 ) ;
return V_123 ;
}
int F_139 ( struct V_19 * V_19 ,
struct V_116 * V_117 )
{
int V_37 ;
T_6 V_124 ;
unsigned long V_93 ;
struct V_89 * V_125 ;
struct V_89 V_114 , V_112 ;
struct V_64 * V_65 = NULL , * V_123 ;
enum V_126 V_127 ;
V_37 = F_135 ( V_117 ) ;
if ( V_37 )
goto V_128;
V_37 = - V_122 ;
if ( V_117 -> V_129 & ( V_87 - 1 ) )
goto V_128;
if ( V_117 -> V_130 & ( V_87 - 1 ) )
goto V_128;
if ( ( V_117 -> V_125 < V_131 ) &&
( ( V_117 -> V_132 & ( V_87 - 1 ) ) ||
! F_140 ( V_133 ,
( void V_134 * ) ( unsigned long ) V_117 -> V_132 ,
V_117 -> V_129 ) ) )
goto V_128;
if ( V_117 -> V_125 >= V_67 )
goto V_128;
if ( V_117 -> V_130 + V_117 -> V_129 < V_117 -> V_130 )
goto V_128;
V_125 = F_134 ( V_19 -> V_66 , V_117 -> V_125 ) ;
V_124 = V_117 -> V_130 >> V_135 ;
V_93 = V_117 -> V_129 >> V_135 ;
V_37 = - V_122 ;
if ( V_93 > V_136 )
goto V_128;
if ( ! V_93 )
V_117 -> V_121 &= ~ V_119 ;
V_112 = V_114 = * V_125 ;
V_112 . V_36 = V_117 -> V_125 ;
V_112 . V_124 = V_124 ;
V_112 . V_93 = V_93 ;
V_112 . V_121 = V_117 -> V_121 ;
V_37 = - V_122 ;
if ( V_93 ) {
if ( ! V_114 . V_93 )
V_127 = V_137 ;
else {
if ( ( V_117 -> V_132 != V_114 . V_132 ) ||
( V_93 != V_114 . V_93 ) ||
( ( V_112 . V_121 ^ V_114 . V_121 ) & V_120 ) )
goto V_128;
if ( V_124 != V_114 . V_124 )
V_127 = V_138 ;
else if ( V_112 . V_121 != V_114 . V_121 )
V_127 = V_139 ;
else {
V_37 = 0 ;
goto V_128;
}
}
} else if ( V_114 . V_93 ) {
V_127 = V_140 ;
} else
goto V_128;
if ( ( V_127 == V_137 ) || ( V_127 == V_138 ) ) {
V_37 = - V_141 ;
F_108 (slot, kvm->memslots) {
if ( ( V_125 -> V_36 >= V_131 ) ||
( V_125 -> V_36 == V_117 -> V_125 ) )
continue;
if ( ! ( ( V_124 + V_93 <= V_125 -> V_124 ) ||
( V_124 >= V_125 -> V_124 + V_125 -> V_93 ) ) )
goto V_128;
}
}
if ( ! ( V_112 . V_121 & V_119 ) )
V_112 . V_91 = NULL ;
V_37 = - V_42 ;
if ( V_127 == V_137 ) {
V_112 . V_132 = V_117 -> V_132 ;
if ( F_141 ( & V_112 , V_93 ) )
goto V_142;
}
if ( ( V_112 . V_121 & V_119 ) && ! V_112 . V_91 ) {
if ( F_127 ( & V_112 ) < 0 )
goto V_142;
}
if ( ( V_127 == V_140 ) || ( V_127 == V_138 ) ) {
V_37 = - V_42 ;
V_65 = F_142 ( V_19 -> V_66 , sizeof( struct V_64 ) ,
V_40 ) ;
if ( ! V_65 )
goto V_142;
V_125 = F_134 ( V_65 , V_117 -> V_125 ) ;
V_125 -> V_121 |= V_143 ;
V_123 = F_137 ( V_19 , V_65 , NULL ) ;
F_143 ( V_19 , & V_114 ) ;
F_144 ( V_19 , V_125 ) ;
V_65 = V_123 ;
}
V_37 = F_145 ( V_19 , & V_112 , V_117 , V_127 ) ;
if ( V_37 )
goto V_144;
V_37 = - V_42 ;
if ( ! V_65 ) {
V_65 = F_142 ( V_19 -> V_66 , sizeof( struct V_64 ) ,
V_40 ) ;
if ( ! V_65 )
goto V_142;
}
if ( ( V_127 == V_137 ) || ( V_127 == V_138 ) ) {
V_37 = F_146 ( V_19 , & V_112 ) ;
if ( V_37 )
goto V_144;
}
if ( V_127 == V_140 ) {
V_112 . V_91 = NULL ;
memset ( & V_112 . V_145 , 0 , sizeof( V_112 . V_145 ) ) ;
}
V_123 = F_137 ( V_19 , V_65 , & V_112 ) ;
F_147 ( V_19 , V_117 , & V_114 , V_127 ) ;
F_105 ( & V_114 , & V_112 ) ;
F_97 ( V_123 ) ;
return 0 ;
V_144:
F_97 ( V_65 ) ;
V_142:
F_105 ( & V_112 , & V_114 ) ;
V_128:
return V_37 ;
}
int F_148 ( struct V_19 * V_19 ,
struct V_116 * V_117 )
{
int V_37 ;
F_149 ( & V_19 -> V_81 ) ;
V_37 = F_139 ( V_19 , V_117 ) ;
F_24 ( & V_19 -> V_81 ) ;
return V_37 ;
}
int F_150 ( struct V_19 * V_19 ,
struct V_116 * V_117 )
{
if ( V_117 -> V_125 >= V_131 )
return - V_122 ;
return F_148 ( V_19 , V_117 ) ;
}
int F_151 ( struct V_19 * V_19 ,
struct V_146 * log , int * V_147 )
{
struct V_89 * V_90 ;
int V_37 , V_21 ;
unsigned long V_148 ;
unsigned long V_149 = 0 ;
V_37 = - V_122 ;
if ( log -> V_125 >= V_131 )
goto V_128;
V_90 = F_134 ( V_19 -> V_66 , log -> V_125 ) ;
V_37 = - V_150 ;
if ( ! V_90 -> V_91 )
goto V_128;
V_148 = F_129 ( V_90 ) ;
for ( V_21 = 0 ; ! V_149 && V_21 < V_148 / sizeof( long ) ; ++ V_21 )
V_149 = V_90 -> V_91 [ V_21 ] ;
V_37 = - V_151 ;
if ( F_152 ( log -> V_91 , V_90 -> V_91 , V_148 ) )
goto V_128;
if ( V_149 )
* V_147 = 1 ;
V_37 = 0 ;
V_128:
return V_37 ;
}
bool F_153 ( void )
{
return V_152 ;
}
void F_154 ( void )
{
V_152 = false ;
}
struct V_89 * F_155 ( struct V_19 * V_19 , T_6 V_153 )
{
return F_156 ( V_64 ( V_19 ) , V_153 ) ;
}
int F_157 ( struct V_19 * V_19 , T_6 V_153 )
{
struct V_89 * V_90 = F_155 ( V_19 , V_153 ) ;
if ( ! V_90 || V_90 -> V_36 >= V_131 ||
V_90 -> V_121 & V_143 )
return 0 ;
return 1 ;
}
unsigned long F_158 ( struct V_19 * V_19 , T_6 V_153 )
{
struct V_154 * V_155 ;
unsigned long V_88 , V_86 ;
V_86 = V_87 ;
V_88 = F_159 ( V_19 , V_153 ) ;
if ( F_160 ( V_88 ) )
return V_87 ;
F_161 ( & V_12 -> V_50 -> V_156 ) ;
V_155 = F_162 ( V_12 -> V_50 , V_88 ) ;
if ( ! V_155 )
goto V_128;
V_86 = F_163 ( V_155 ) ;
V_128:
F_164 ( & V_12 -> V_50 -> V_156 ) ;
return V_86 ;
}
static bool F_165 ( struct V_89 * V_125 )
{
return V_125 -> V_121 & V_120 ;
}
static unsigned long F_166 ( struct V_89 * V_125 , T_6 V_153 ,
T_6 * V_157 , bool V_158 )
{
if ( ! V_125 || V_125 -> V_121 & V_143 )
return V_159 ;
if ( F_165 ( V_125 ) && V_158 )
return V_160 ;
if ( V_157 )
* V_157 = V_125 -> V_93 - ( V_153 - V_125 -> V_124 ) ;
return F_167 ( V_125 , V_153 ) ;
}
static unsigned long F_168 ( struct V_89 * V_125 , T_6 V_153 ,
T_6 * V_157 )
{
return F_166 ( V_125 , V_153 , V_157 , true ) ;
}
unsigned long F_169 ( struct V_89 * V_125 ,
T_6 V_153 )
{
return F_168 ( V_125 , V_153 , NULL ) ;
}
unsigned long F_159 ( struct V_19 * V_19 , T_6 V_153 )
{
return F_168 ( F_155 ( V_19 , V_153 ) , V_153 , NULL ) ;
}
static unsigned long F_170 ( struct V_19 * V_19 , T_6 V_153 )
{
return F_166 ( F_155 ( V_19 , V_153 ) , V_153 , NULL , false ) ;
}
static int F_171 ( void * V_161 , void V_134 * V_162 , int V_163 )
{
return F_172 ( V_161 , V_162 , V_163 ) ;
}
static int F_173 ( void * V_161 , void V_134 * V_162 , int V_163 )
{
return F_174 ( V_161 , V_162 , V_163 ) ;
}
static int F_175 ( struct V_164 * V_165 , struct V_49 * V_50 ,
unsigned long V_58 , int V_158 , struct V_3 * * V_3 )
{
int V_121 = V_166 | V_167 | V_168 | V_169 ;
if ( V_158 )
V_121 |= V_170 ;
return F_176 ( V_165 , V_50 , V_58 , 1 , V_121 , V_3 , NULL , NULL ) ;
}
static inline int F_177 ( unsigned long V_88 )
{
int V_171 , V_121 = V_166 | V_168 | V_170 ;
V_171 = F_176 ( V_12 , V_12 -> V_50 , V_88 , 1 ,
V_121 , NULL , NULL , NULL ) ;
return V_171 == - V_172 ;
}
static bool F_178 ( unsigned long V_88 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_176 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_93 ;
if ( ! ( V_174 || V_173 ) )
return false ;
if ( ! ( V_175 || V_176 ) )
return false ;
V_93 = F_179 ( V_88 , 1 , 1 , V_3 ) ;
if ( V_93 == 1 ) {
* V_1 = F_180 ( V_3 [ 0 ] ) ;
if ( V_176 )
* V_176 = true ;
return true ;
}
return false ;
}
static int F_181 ( unsigned long V_88 , bool * V_174 , bool V_175 ,
bool * V_176 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_93 = 0 ;
F_182 () ;
if ( V_176 )
* V_176 = V_175 ;
if ( V_174 ) {
F_161 ( & V_12 -> V_50 -> V_156 ) ;
V_93 = F_175 ( V_12 , V_12 -> V_50 ,
V_88 , V_175 , V_3 ) ;
F_164 ( & V_12 -> V_50 -> V_156 ) ;
} else
V_93 = F_183 ( V_88 , 1 , V_175 ,
V_3 ) ;
if ( V_93 != 1 )
return V_93 ;
if ( F_10 ( ! V_175 ) && V_176 ) {
struct V_3 * V_177 [ 1 ] ;
V_93 = F_179 ( V_88 , 1 , 1 , V_177 ) ;
if ( V_93 == 1 ) {
* V_176 = true ;
F_184 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_177 [ 0 ] ;
}
V_93 = 1 ;
}
* V_1 = F_180 ( V_3 [ 0 ] ) ;
return V_93 ;
}
static bool F_185 ( struct V_154 * V_155 , bool V_175 )
{
if ( F_10 ( ! ( V_155 -> V_178 & V_179 ) ) )
return false ;
if ( V_175 && ( F_10 ( ! ( V_155 -> V_178 & V_180 ) ) ) )
return false ;
return true ;
}
static T_1 F_186 ( unsigned long V_88 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_176 )
{
struct V_154 * V_155 ;
T_1 V_1 = 0 ;
int V_93 ;
F_67 ( V_173 && V_174 ) ;
if ( F_178 ( V_88 , V_173 , V_174 , V_175 , V_176 , & V_1 ) )
return V_1 ;
if ( V_173 )
return V_181 ;
V_93 = F_181 ( V_88 , V_174 , V_175 , V_176 , & V_1 ) ;
if ( V_93 == 1 )
return V_1 ;
F_161 ( & V_12 -> V_50 -> V_156 ) ;
if ( V_93 == - V_172 ||
( ! V_174 && F_177 ( V_88 ) ) ) {
V_1 = V_182 ;
goto exit;
}
V_155 = F_187 ( V_12 -> V_50 , V_88 , V_88 + 1 ) ;
if ( V_155 == NULL )
V_1 = V_181 ;
else if ( ( V_155 -> V_178 & V_183 ) ) {
V_1 = ( ( V_88 - V_155 -> V_184 ) >> V_135 ) +
V_155 -> V_185 ;
F_67 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_174 && F_185 ( V_155 , V_175 ) )
* V_174 = true ;
V_1 = V_181 ;
}
exit:
F_164 ( & V_12 -> V_50 -> V_156 ) ;
return V_1 ;
}
static T_1
F_188 ( struct V_89 * V_125 , T_6 V_153 , bool V_173 ,
bool * V_174 , bool V_175 , bool * V_176 )
{
unsigned long V_88 = F_166 ( V_125 , V_153 , NULL , V_175 ) ;
if ( V_88 == V_160 )
return V_186 ;
if ( F_160 ( V_88 ) )
return V_187 ;
if ( V_176 && F_165 ( V_125 ) ) {
* V_176 = false ;
V_176 = NULL ;
}
return F_186 ( V_88 , V_173 , V_174 , V_175 ,
V_176 ) ;
}
static T_1 F_189 ( struct V_19 * V_19 , T_6 V_153 , bool V_173 , bool * V_174 ,
bool V_175 , bool * V_176 )
{
struct V_89 * V_125 ;
if ( V_174 )
* V_174 = false ;
V_125 = F_155 ( V_19 , V_153 ) ;
return F_188 ( V_125 , V_153 , V_173 , V_174 , V_175 ,
V_176 ) ;
}
T_1 F_190 ( struct V_19 * V_19 , T_6 V_153 )
{
return F_189 ( V_19 , V_153 , true , NULL , true , NULL ) ;
}
T_1 F_191 ( struct V_19 * V_19 , T_6 V_153 , bool * V_174 ,
bool V_175 , bool * V_176 )
{
return F_189 ( V_19 , V_153 , false , V_174 , V_175 , V_176 ) ;
}
T_1 F_192 ( struct V_19 * V_19 , T_6 V_153 )
{
return F_189 ( V_19 , V_153 , false , NULL , true , NULL ) ;
}
T_1 F_193 ( struct V_19 * V_19 , T_6 V_153 , bool V_175 ,
bool * V_176 )
{
return F_189 ( V_19 , V_153 , false , NULL , V_175 , V_176 ) ;
}
T_1 F_194 ( struct V_89 * V_125 , T_6 V_153 )
{
return F_188 ( V_125 , V_153 , false , NULL , true , NULL ) ;
}
T_1 F_195 ( struct V_89 * V_125 , T_6 V_153 )
{
return F_188 ( V_125 , V_153 , true , NULL , true , NULL ) ;
}
int F_196 ( struct V_19 * V_19 , T_6 V_153 , struct V_3 * * V_188 ,
int V_157 )
{
unsigned long V_88 ;
T_6 V_189 ;
V_88 = F_168 ( F_155 ( V_19 , V_153 ) , V_153 , & V_189 ) ;
if ( F_160 ( V_88 ) )
return - 1 ;
if ( V_189 < V_157 )
return 0 ;
return F_179 ( V_88 , V_157 , 1 , V_188 ) ;
}
static struct V_3 * F_197 ( T_1 V_1 )
{
if ( F_198 ( V_1 ) )
return V_190 ;
if ( F_1 ( V_1 ) ) {
F_199 ( 1 ) ;
return V_190 ;
}
return F_3 ( V_1 ) ;
}
struct V_3 * F_200 ( struct V_19 * V_19 , T_6 V_153 )
{
T_1 V_1 ;
V_1 = F_192 ( V_19 , V_153 ) ;
return F_197 ( V_1 ) ;
}
void F_201 ( struct V_3 * V_3 )
{
F_199 ( F_202 ( V_3 ) ) ;
F_203 ( F_180 ( V_3 ) ) ;
}
void F_203 ( T_1 V_1 )
{
if ( ! F_198 ( V_1 ) && ! F_1 ( V_1 ) )
F_184 ( F_3 ( V_1 ) ) ;
}
void F_204 ( struct V_3 * V_3 )
{
F_199 ( F_202 ( V_3 ) ) ;
F_205 ( F_180 ( V_3 ) ) ;
}
void F_205 ( T_1 V_1 )
{
F_206 ( V_1 ) ;
F_203 ( V_1 ) ;
}
void F_207 ( struct V_3 * V_3 )
{
F_206 ( F_180 ( V_3 ) ) ;
}
void F_206 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_208 ( V_3 ) ;
}
}
void F_209 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_210 ( F_3 ( V_1 ) ) ;
}
void F_211 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_212 ( F_3 ( V_1 ) ) ;
}
static int F_213 ( unsigned long V_163 , int V_191 )
{
if ( V_163 > V_87 - V_191 )
return V_87 - V_191 ;
else
return V_163 ;
}
int F_214 ( struct V_19 * V_19 , T_6 V_153 , void * V_161 , int V_191 ,
int V_163 )
{
int V_37 ;
unsigned long V_88 ;
V_88 = F_170 ( V_19 , V_153 ) ;
if ( F_160 ( V_88 ) )
return - V_151 ;
V_37 = F_171 ( V_161 , ( void V_134 * ) V_88 + V_191 , V_163 ) ;
if ( V_37 )
return - V_151 ;
return 0 ;
}
int F_215 ( struct V_19 * V_19 , T_7 V_192 , void * V_161 , unsigned long V_163 )
{
T_6 V_153 = V_192 >> V_135 ;
int V_193 ;
int V_191 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_213 ( V_163 , V_191 ) ) != 0 ) {
V_194 = F_214 ( V_19 , V_153 , V_161 , V_191 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_191 = 0 ;
V_163 -= V_193 ;
V_161 += V_193 ;
++ V_153 ;
}
return 0 ;
}
int F_217 ( struct V_19 * V_19 , T_7 V_192 , void * V_161 ,
unsigned long V_163 )
{
int V_37 ;
unsigned long V_88 ;
T_6 V_153 = V_192 >> V_135 ;
int V_191 = F_216 ( V_192 ) ;
V_88 = F_170 ( V_19 , V_153 ) ;
if ( F_160 ( V_88 ) )
return - V_151 ;
F_218 () ;
V_37 = F_173 ( V_161 , ( void V_134 * ) V_88 + V_191 , V_163 ) ;
F_219 () ;
if ( V_37 )
return - V_151 ;
return 0 ;
}
int F_220 ( struct V_19 * V_19 , T_6 V_153 , const void * V_161 ,
int V_191 , int V_163 )
{
int V_37 ;
unsigned long V_88 ;
V_88 = F_159 ( V_19 , V_153 ) ;
if ( F_160 ( V_88 ) )
return - V_151 ;
V_37 = F_221 ( ( void V_134 * ) V_88 + V_191 , V_161 , V_163 ) ;
if ( V_37 )
return - V_151 ;
F_222 ( V_19 , V_153 ) ;
return 0 ;
}
int F_223 ( struct V_19 * V_19 , T_7 V_192 , const void * V_161 ,
unsigned long V_163 )
{
T_6 V_153 = V_192 >> V_135 ;
int V_193 ;
int V_191 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_213 ( V_163 , V_191 ) ) != 0 ) {
V_194 = F_220 ( V_19 , V_153 , V_161 , V_191 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_191 = 0 ;
V_163 -= V_193 ;
V_161 += V_193 ;
++ V_153 ;
}
return 0 ;
}
int F_224 ( struct V_19 * V_19 , struct V_195 * V_196 ,
T_7 V_192 , unsigned long V_163 )
{
struct V_64 * V_65 = V_64 ( V_19 ) ;
int V_191 = F_216 ( V_192 ) ;
T_6 V_197 = V_192 >> V_135 ;
T_6 V_198 = ( V_192 + V_163 - 1 ) >> V_135 ;
T_6 V_199 = V_198 - V_197 + 1 ;
T_6 V_200 ;
V_196 -> V_192 = V_192 ;
V_196 -> V_115 = V_65 -> V_115 ;
V_196 -> V_163 = V_163 ;
V_196 -> V_90 = F_155 ( V_19 , V_197 ) ;
V_196 -> V_162 = F_168 ( V_196 -> V_90 , V_197 , & V_200 ) ;
if ( ! F_160 ( V_196 -> V_162 ) && V_200 >= V_199 ) {
V_196 -> V_162 += V_191 ;
} else {
while ( V_197 <= V_198 ) {
V_196 -> V_90 = F_155 ( V_19 , V_197 ) ;
V_196 -> V_162 = F_168 ( V_196 -> V_90 , V_197 ,
& V_200 ) ;
if ( F_160 ( V_196 -> V_162 ) )
return - V_151 ;
V_197 += V_200 ;
}
V_196 -> V_90 = NULL ;
}
return 0 ;
}
int F_225 ( struct V_19 * V_19 , struct V_195 * V_196 ,
void * V_161 , unsigned long V_163 )
{
struct V_64 * V_65 = V_64 ( V_19 ) ;
int V_37 ;
F_67 ( V_163 > V_196 -> V_163 ) ;
if ( V_65 -> V_115 != V_196 -> V_115 )
F_224 ( V_19 , V_196 , V_196 -> V_192 , V_196 -> V_163 ) ;
if ( F_10 ( ! V_196 -> V_90 ) )
return F_223 ( V_19 , V_196 -> V_192 , V_161 , V_163 ) ;
if ( F_160 ( V_196 -> V_162 ) )
return - V_151 ;
V_37 = F_221 ( ( void V_134 * ) V_196 -> V_162 , V_161 , V_163 ) ;
if ( V_37 )
return - V_151 ;
F_226 ( V_19 , V_196 -> V_90 , V_196 -> V_192 >> V_135 ) ;
return 0 ;
}
int F_227 ( struct V_19 * V_19 , struct V_195 * V_196 ,
void * V_161 , unsigned long V_163 )
{
struct V_64 * V_65 = V_64 ( V_19 ) ;
int V_37 ;
F_67 ( V_163 > V_196 -> V_163 ) ;
if ( V_65 -> V_115 != V_196 -> V_115 )
F_224 ( V_19 , V_196 , V_196 -> V_192 , V_196 -> V_163 ) ;
if ( F_10 ( ! V_196 -> V_90 ) )
return F_215 ( V_19 , V_196 -> V_192 , V_161 , V_163 ) ;
if ( F_160 ( V_196 -> V_162 ) )
return - V_151 ;
V_37 = F_172 ( V_161 , ( void V_134 * ) V_196 -> V_162 , V_163 ) ;
if ( V_37 )
return - V_151 ;
return 0 ;
}
int F_228 ( struct V_19 * V_19 , T_6 V_153 , int V_191 , int V_163 )
{
return F_220 ( V_19 , V_153 , ( const void * ) V_201 ,
V_191 , V_163 ) ;
}
int F_229 ( struct V_19 * V_19 , T_7 V_192 , unsigned long V_163 )
{
T_6 V_153 = V_192 >> V_135 ;
int V_193 ;
int V_191 = F_216 ( V_192 ) ;
int V_194 ;
while ( ( V_193 = F_213 ( V_163 , V_191 ) ) != 0 ) {
V_194 = F_228 ( V_19 , V_153 , V_191 , V_193 ) ;
if ( V_194 < 0 )
return V_194 ;
V_191 = 0 ;
V_163 -= V_193 ;
++ V_153 ;
}
return 0 ;
}
void F_226 ( struct V_19 * V_19 , struct V_89 * V_90 ,
T_6 V_153 )
{
if ( V_90 && V_90 -> V_91 ) {
unsigned long V_202 = V_153 - V_90 -> V_124 ;
F_230 ( V_202 , V_90 -> V_91 ) ;
}
}
void F_222 ( struct V_19 * V_19 , T_6 V_153 )
{
struct V_89 * V_90 ;
V_90 = F_155 ( V_19 , V_153 ) ;
F_226 ( V_19 , V_90 , V_153 ) ;
}
void F_231 ( struct V_6 * V_7 )
{
F_232 ( V_203 ) ;
for (; ; ) {
F_233 ( & V_7 -> V_39 , & V_203 , V_204 ) ;
if ( F_234 ( V_7 ) ) {
F_29 ( V_205 , V_7 ) ;
break;
}
if ( F_235 ( V_7 ) )
break;
if ( F_236 ( V_12 ) )
break;
F_237 () ;
}
F_238 ( & V_7 -> V_39 , & V_203 ) ;
}
void F_239 ( struct V_6 * V_7 )
{
int V_22 ;
int V_8 = V_7 -> V_8 ;
T_8 * V_206 ;
V_206 = F_240 ( V_7 ) ;
if ( F_241 ( V_206 ) ) {
F_242 ( V_206 ) ;
++ V_7 -> V_31 . V_207 ;
}
V_22 = F_15 () ;
if ( V_8 != V_22 && ( unsigned ) V_8 < V_208 && F_243 ( V_8 ) )
if ( F_244 ( V_7 ) )
F_245 ( V_8 ) ;
F_18 () ;
}
void F_246 ( struct V_6 * V_7 )
{
if ( ! F_247 () )
return;
F_248 () ;
}
bool F_249 ( struct V_6 * V_209 )
{
struct V_11 * V_11 ;
struct V_164 * V_210 = NULL ;
bool V_194 = false ;
F_250 () ;
V_11 = F_251 ( V_209 -> V_11 ) ;
if ( V_11 )
V_210 = F_252 ( V_209 -> V_11 , V_14 ) ;
F_253 () ;
if ( ! V_210 )
return V_194 ;
if ( V_210 -> V_121 & V_211 ) {
F_254 ( V_210 ) ;
return V_194 ;
}
V_194 = F_255 ( V_210 , 1 ) ;
F_254 ( V_210 ) ;
return V_194 ;
}
bool F_256 ( struct V_6 * V_7 )
{
bool V_212 ;
V_212 = ! V_7 -> V_213 . V_214 ||
( V_7 -> V_213 . V_214 &&
V_7 -> V_213 . V_215 ) ;
if ( V_7 -> V_213 . V_214 )
F_48 ( V_7 , ! V_7 -> V_213 . V_215 ) ;
return V_212 ;
}
void F_257 ( struct V_6 * V_22 )
{
struct V_19 * V_19 = V_22 -> V_19 ;
struct V_6 * V_7 ;
int V_216 = V_22 -> V_19 -> V_216 ;
int V_217 = 0 ;
int V_218 = 3 ;
int V_219 ;
int V_21 ;
F_47 ( V_22 , true ) ;
for ( V_219 = 0 ; V_219 < 2 && ! V_217 && V_218 ; V_219 ++ ) {
F_28 (i, vcpu, kvm) {
if ( ! V_219 && V_21 <= V_216 ) {
V_21 = V_216 ;
continue;
} else if ( V_219 && V_21 > V_216 )
break;
if ( ! F_258 ( V_7 -> V_45 ) )
continue;
if ( V_7 == V_22 )
continue;
if ( F_241 ( & V_7 -> V_39 ) )
continue;
if ( ! F_256 ( V_7 ) )
continue;
V_217 = F_249 ( V_7 ) ;
if ( V_217 > 0 ) {
V_19 -> V_216 = V_21 ;
break;
} else if ( V_217 < 0 ) {
V_218 -- ;
if ( ! V_218 )
break;
}
}
}
F_47 ( V_22 , false ) ;
F_48 ( V_22 , false ) ;
}
static int F_259 ( struct V_154 * V_155 , struct V_220 * V_221 )
{
struct V_6 * V_7 = V_155 -> V_222 -> V_106 ;
struct V_3 * V_3 ;
if ( V_221 -> V_223 == 0 )
V_3 = F_260 ( V_7 -> V_44 ) ;
#ifdef F_261
else if ( V_221 -> V_223 == V_224 )
V_3 = F_260 ( V_7 -> V_145 . V_225 ) ;
#endif
#ifdef F_262
else if ( V_221 -> V_223 == F_262 )
V_3 = F_260 ( V_7 -> V_19 -> V_226 ) ;
#endif
else
return F_263 ( V_7 , V_221 ) ;
F_212 ( V_3 ) ;
V_221 -> V_3 = V_3 ;
return 0 ;
}
static int F_264 ( struct V_104 * V_104 , struct V_154 * V_155 )
{
V_155 -> V_227 = & V_228 ;
return 0 ;
}
static int F_265 ( struct V_103 * V_103 , struct V_104 * V_105 )
{
struct V_6 * V_7 = V_105 -> V_106 ;
F_123 ( V_7 -> V_19 ) ;
return 0 ;
}
static int F_266 ( struct V_6 * V_7 )
{
return F_267 ( L_1 , & V_229 , V_7 , V_230 ) ;
}
static int F_268 ( struct V_19 * V_19 , T_5 V_36 )
{
int V_37 ;
struct V_6 * V_7 , * V_231 ;
V_7 = F_269 ( V_19 , V_36 ) ;
if ( F_270 ( V_7 ) )
return F_271 ( V_7 ) ;
F_272 ( & V_7 -> V_17 , & V_232 ) ;
V_37 = F_273 ( V_7 ) ;
if ( V_37 )
goto V_233;
F_149 ( & V_19 -> V_79 ) ;
if ( ! F_274 ( V_7 ) ) {
V_37 = - V_122 ;
goto V_234;
}
if ( F_275 ( & V_19 -> V_235 ) == V_236 ) {
V_37 = - V_122 ;
goto V_234;
}
F_28 (r, v, kvm)
if ( V_231 -> V_38 == V_36 ) {
V_37 = - V_141 ;
goto V_234;
}
F_67 ( V_19 -> V_237 [ F_275 ( & V_19 -> V_235 ) ] ) ;
F_122 ( V_19 ) ;
V_37 = F_266 ( V_7 ) ;
if ( V_37 < 0 ) {
F_123 ( V_19 ) ;
goto V_234;
}
V_19 -> V_237 [ F_275 ( & V_19 -> V_235 ) ] = V_7 ;
F_66 () ;
F_88 ( & V_19 -> V_235 ) ;
F_24 ( & V_19 -> V_79 ) ;
F_276 ( V_7 ) ;
return V_37 ;
V_234:
F_24 ( & V_19 -> V_79 ) ;
V_233:
F_277 ( V_7 ) ;
return V_37 ;
}
static int F_278 ( struct V_6 * V_7 , T_9 * V_238 )
{
if ( V_238 ) {
F_279 ( V_238 , F_280 ( V_239 ) | F_280 ( V_240 ) ) ;
V_7 -> V_241 = 1 ;
V_7 -> V_238 = * V_238 ;
} else
V_7 -> V_241 = 0 ;
return 0 ;
}
static long F_281 ( struct V_104 * V_105 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_6 * V_7 = V_105 -> V_106 ;
void V_134 * V_244 = ( void V_134 * ) V_243 ;
int V_37 ;
struct V_245 * V_246 = NULL ;
struct V_247 * V_247 = NULL ;
if ( V_7 -> V_19 -> V_50 != V_12 -> V_50 )
return - V_248 ;
#if F_118 ( F_128 ) || F_118 ( V_249 ) || F_118 ( V_250 )
if ( V_242 == V_251 || V_242 == V_252 )
return F_282 ( V_105 , V_242 , V_243 ) ;
#endif
V_37 = F_8 ( V_7 ) ;
if ( V_37 )
return V_37 ;
switch ( V_242 ) {
case V_253 :
V_37 = - V_122 ;
if ( V_243 )
goto V_128;
V_37 = F_283 ( V_7 , V_7 -> V_44 ) ;
F_284 ( V_7 -> V_44 -> V_254 , V_37 ) ;
break;
case V_255 : {
struct V_256 * V_256 ;
V_37 = - V_42 ;
V_256 = F_85 ( sizeof( struct V_256 ) , V_40 ) ;
if ( ! V_256 )
goto V_128;
V_37 = F_285 ( V_7 , V_256 ) ;
if ( V_37 )
goto V_257;
V_37 = - V_151 ;
if ( F_152 ( V_244 , V_256 , sizeof( struct V_256 ) ) )
goto V_257;
V_37 = 0 ;
V_257:
F_97 ( V_256 ) ;
break;
}
case V_258 : {
struct V_256 * V_256 ;
V_37 = - V_42 ;
V_256 = F_286 ( V_244 , sizeof( * V_256 ) ) ;
if ( F_270 ( V_256 ) ) {
V_37 = F_271 ( V_256 ) ;
goto V_128;
}
V_37 = F_287 ( V_7 , V_256 ) ;
F_97 ( V_256 ) ;
break;
}
case V_259 : {
V_247 = F_85 ( sizeof( struct V_247 ) , V_40 ) ;
V_37 = - V_42 ;
if ( ! V_247 )
goto V_128;
V_37 = F_288 ( V_7 , V_247 ) ;
if ( V_37 )
goto V_128;
V_37 = - V_151 ;
if ( F_152 ( V_244 , V_247 , sizeof( struct V_247 ) ) )
goto V_128;
V_37 = 0 ;
break;
}
case V_260 : {
V_247 = F_286 ( V_244 , sizeof( * V_247 ) ) ;
if ( F_270 ( V_247 ) ) {
V_37 = F_271 ( V_247 ) ;
V_247 = NULL ;
goto V_128;
}
V_37 = F_289 ( V_7 , V_247 ) ;
break;
}
case V_261 : {
struct V_262 V_263 ;
V_37 = F_290 ( V_7 , & V_263 ) ;
if ( V_37 )
goto V_128;
V_37 = - V_151 ;
if ( F_152 ( V_244 , & V_263 , sizeof V_263 ) )
goto V_128;
V_37 = 0 ;
break;
}
case V_264 : {
struct V_262 V_263 ;
V_37 = - V_151 ;
if ( F_291 ( & V_263 , V_244 , sizeof V_263 ) )
goto V_128;
V_37 = F_292 ( V_7 , & V_263 ) ;
break;
}
case V_265 : {
struct V_266 V_267 ;
V_37 = - V_151 ;
if ( F_291 ( & V_267 , V_244 , sizeof V_267 ) )
goto V_128;
V_37 = F_293 ( V_7 , & V_267 ) ;
if ( V_37 )
goto V_128;
V_37 = - V_151 ;
if ( F_152 ( V_244 , & V_267 , sizeof V_267 ) )
goto V_128;
V_37 = 0 ;
break;
}
case V_268 : {
struct V_269 V_270 ;
V_37 = - V_151 ;
if ( F_291 ( & V_270 , V_244 , sizeof V_270 ) )
goto V_128;
V_37 = F_294 ( V_7 , & V_270 ) ;
break;
}
case V_271 : {
struct V_272 V_134 * V_273 = V_244 ;
struct V_272 V_274 ;
T_9 V_238 , * V_275 ;
V_275 = NULL ;
if ( V_244 ) {
V_37 = - V_151 ;
if ( F_291 ( & V_274 , V_244 ,
sizeof V_274 ) )
goto V_128;
V_37 = - V_122 ;
if ( V_274 . V_163 != sizeof V_238 )
goto V_128;
V_37 = - V_151 ;
if ( F_291 ( & V_238 , V_273 -> V_238 ,
sizeof V_238 ) )
goto V_128;
V_275 = & V_238 ;
}
V_37 = F_278 ( V_7 , V_275 ) ;
break;
}
case V_276 : {
V_246 = F_85 ( sizeof( struct V_245 ) , V_40 ) ;
V_37 = - V_42 ;
if ( ! V_246 )
goto V_128;
V_37 = F_295 ( V_7 , V_246 ) ;
if ( V_37 )
goto V_128;
V_37 = - V_151 ;
if ( F_152 ( V_244 , V_246 , sizeof( struct V_245 ) ) )
goto V_128;
V_37 = 0 ;
break;
}
case V_277 : {
V_246 = F_286 ( V_244 , sizeof( * V_246 ) ) ;
if ( F_270 ( V_246 ) ) {
V_37 = F_271 ( V_246 ) ;
V_246 = NULL ;
goto V_128;
}
V_37 = F_296 ( V_7 , V_246 ) ;
break;
}
default:
V_37 = F_282 ( V_105 , V_242 , V_243 ) ;
}
V_128:
F_19 ( V_7 ) ;
F_97 ( V_246 ) ;
F_97 ( V_247 ) ;
return V_37 ;
}
static long F_297 ( struct V_104 * V_105 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_6 * V_7 = V_105 -> V_106 ;
void V_134 * V_244 = F_298 ( V_243 ) ;
int V_37 ;
if ( V_7 -> V_19 -> V_50 != V_12 -> V_50 )
return - V_248 ;
switch ( V_242 ) {
case V_271 : {
struct V_272 V_134 * V_273 = V_244 ;
struct V_272 V_274 ;
T_10 V_278 ;
T_9 V_238 ;
if ( V_244 ) {
V_37 = - V_151 ;
if ( F_291 ( & V_274 , V_244 ,
sizeof V_274 ) )
goto V_128;
V_37 = - V_122 ;
if ( V_274 . V_163 != sizeof V_278 )
goto V_128;
V_37 = - V_151 ;
if ( F_291 ( & V_278 , V_273 -> V_238 ,
sizeof V_278 ) )
goto V_128;
F_299 ( & V_238 , & V_278 ) ;
V_37 = F_278 ( V_7 , & V_238 ) ;
} else
V_37 = F_278 ( V_7 , NULL ) ;
break;
}
default:
V_37 = F_281 ( V_105 , V_242 , V_243 ) ;
}
V_128:
return V_37 ;
}
static int F_300 ( struct V_97 * V_98 ,
int (* F_301)( struct V_97 * V_98 ,
struct V_279 * V_280 ) ,
unsigned long V_243 )
{
struct V_279 V_280 ;
if ( ! F_301 )
return - V_281 ;
if ( F_291 ( & V_280 , ( void V_134 * ) V_243 , sizeof( V_280 ) ) )
return - V_151 ;
return F_301 ( V_98 , & V_280 ) ;
}
static long F_302 ( struct V_104 * V_105 , unsigned int V_242 ,
unsigned long V_243 )
{
struct V_97 * V_98 = V_105 -> V_106 ;
switch ( V_242 ) {
case V_282 :
return F_300 ( V_98 , V_98 -> V_62 -> V_283 , V_243 ) ;
case V_284 :
return F_300 ( V_98 , V_98 -> V_62 -> V_285 , V_243 ) ;
case V_286 :
return F_300 ( V_98 , V_98 -> V_62 -> V_287 , V_243 ) ;
default:
if ( V_98 -> V_62 -> V_242 )
return V_98 -> V_62 -> V_242 ( V_98 , V_242 , V_243 ) ;
return - V_288 ;
}
}
static int F_303 ( struct V_103 * V_103 , struct V_104 * V_105 )
{
struct V_97 * V_98 = V_105 -> V_106 ;
struct V_19 * V_19 = V_98 -> V_19 ;
F_123 ( V_19 ) ;
return 0 ;
}
struct V_97 * F_304 ( struct V_104 * V_105 )
{
if ( V_105 -> V_289 != & V_290 )
return NULL ;
return V_105 -> V_106 ;
}
static int F_305 ( struct V_19 * V_19 ,
struct V_291 * V_292 )
{
struct V_293 * V_62 = NULL ;
struct V_97 * V_98 ;
bool V_294 = V_292 -> V_121 & V_295 ;
int V_194 ;
switch ( V_292 -> type ) {
#ifdef F_306
case V_296 :
case V_297 :
V_62 = & V_298 ;
break;
#endif
#ifdef F_307
case V_299 :
V_62 = & V_300 ;
break;
#endif
default:
return - V_301 ;
}
if ( V_294 )
return 0 ;
V_98 = F_85 ( sizeof( * V_98 ) , V_40 ) ;
if ( ! V_98 )
return - V_42 ;
V_98 -> V_62 = V_62 ;
V_98 -> V_19 = V_19 ;
V_194 = V_62 -> V_302 ( V_98 , V_292 -> type ) ;
if ( V_194 < 0 ) {
F_97 ( V_98 ) ;
return V_194 ;
}
V_194 = F_267 ( V_62 -> V_303 , & V_290 , V_98 , V_230 ) ;
if ( V_194 < 0 ) {
V_62 -> V_100 ( V_98 ) ;
return V_194 ;
}
F_93 ( & V_98 -> V_99 , & V_19 -> V_83 ) ;
F_122 ( V_19 ) ;
V_292 -> V_304 = V_194 ;
return 0 ;
}
static long F_308 ( struct V_104 * V_105 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_19 * V_19 = V_105 -> V_106 ;
void V_134 * V_244 = ( void V_134 * ) V_243 ;
int V_37 ;
if ( V_19 -> V_50 != V_12 -> V_50 )
return - V_248 ;
switch ( V_242 ) {
case V_305 :
V_37 = F_268 ( V_19 , V_243 ) ;
break;
case V_306 : {
struct V_116 V_307 ;
V_37 = - V_151 ;
if ( F_291 ( & V_307 , V_244 ,
sizeof V_307 ) )
goto V_128;
V_37 = F_150 ( V_19 , & V_307 ) ;
break;
}
case V_308 : {
struct V_146 log ;
V_37 = - V_151 ;
if ( F_291 ( & log , V_244 , sizeof log ) )
goto V_128;
V_37 = F_309 ( V_19 , & log ) ;
break;
}
#ifdef F_262
case V_309 : {
struct V_310 V_311 ;
V_37 = - V_151 ;
if ( F_291 ( & V_311 , V_244 , sizeof V_311 ) )
goto V_128;
V_37 = F_310 ( V_19 , & V_311 ) ;
break;
}
case V_312 : {
struct V_310 V_311 ;
V_37 = - V_151 ;
if ( F_291 ( & V_311 , V_244 , sizeof V_311 ) )
goto V_128;
V_37 = F_311 ( V_19 , & V_311 ) ;
break;
}
#endif
case V_313 : {
struct V_314 V_161 ;
V_37 = - V_151 ;
if ( F_291 ( & V_161 , V_244 , sizeof V_161 ) )
goto V_128;
V_37 = V_314 ( V_19 , & V_161 ) ;
break;
}
case V_315 : {
struct V_316 V_161 ;
V_37 = - V_151 ;
if ( F_291 ( & V_161 , V_244 , sizeof V_161 ) )
goto V_128;
V_37 = V_316 ( V_19 , & V_161 ) ;
break;
}
#ifdef F_312
case V_317 :
V_37 = 0 ;
F_149 ( & V_19 -> V_79 ) ;
if ( F_275 ( & V_19 -> V_235 ) != 0 )
V_37 = - V_318 ;
else
V_19 -> V_319 = V_243 ;
F_24 ( & V_19 -> V_79 ) ;
break;
#endif
#ifdef F_313
case V_320 : {
struct V_321 V_322 ;
V_37 = - V_151 ;
if ( F_291 ( & V_322 , V_244 , sizeof V_322 ) )
goto V_128;
V_37 = F_314 ( V_19 , & V_322 ) ;
break;
}
#endif
#ifdef F_315
case V_323 :
case V_324 : {
struct V_325 V_326 ;
V_37 = - V_151 ;
if ( F_291 ( & V_326 , V_244 , sizeof V_326 ) )
goto V_128;
V_37 = F_316 ( V_19 , & V_326 ,
V_242 == V_323 ) ;
if ( V_37 )
goto V_128;
V_37 = - V_151 ;
if ( V_242 == V_323 ) {
if ( F_152 ( V_244 , & V_326 , sizeof V_326 ) )
goto V_128;
}
V_37 = 0 ;
break;
}
#endif
#ifdef F_317
case V_327 : {
struct V_328 V_329 ;
struct V_328 V_134 * V_330 ;
struct V_331 * V_332 ;
V_37 = - V_151 ;
if ( F_291 ( & V_329 , V_244 , sizeof( V_329 ) ) )
goto V_128;
V_37 = - V_122 ;
if ( V_329 . V_333 >= V_334 )
goto V_128;
if ( V_329 . V_121 )
goto V_128;
V_37 = - V_42 ;
V_332 = F_318 ( V_329 . V_333 * sizeof( * V_332 ) ) ;
if ( ! V_332 )
goto V_128;
V_37 = - V_151 ;
V_330 = V_244 ;
if ( F_291 ( V_332 , V_330 -> V_332 ,
V_329 . V_333 * sizeof( * V_332 ) ) )
goto V_335;
V_37 = F_319 ( V_19 , V_332 , V_329 . V_333 ,
V_329 . V_121 ) ;
V_335:
F_103 ( V_332 ) ;
break;
}
#endif
case V_336 : {
struct V_291 V_292 ;
V_37 = - V_151 ;
if ( F_291 ( & V_292 , V_244 , sizeof( V_292 ) ) )
goto V_128;
V_37 = F_305 ( V_19 , & V_292 ) ;
if ( V_37 )
goto V_128;
V_37 = - V_151 ;
if ( F_152 ( V_244 , & V_292 , sizeof( V_292 ) ) )
goto V_128;
V_37 = 0 ;
break;
}
default:
V_37 = F_320 ( V_105 , V_242 , V_243 ) ;
if ( V_37 == - V_288 )
V_37 = F_321 ( V_19 , V_242 , V_243 ) ;
}
V_128:
return V_37 ;
}
static long F_322 ( struct V_104 * V_105 ,
unsigned int V_242 , unsigned long V_243 )
{
struct V_19 * V_19 = V_105 -> V_106 ;
int V_37 ;
if ( V_19 -> V_50 != V_12 -> V_50 )
return - V_248 ;
switch ( V_242 ) {
case V_308 : {
struct V_337 V_338 ;
struct V_146 log ;
V_37 = - V_151 ;
if ( F_291 ( & V_338 , ( void V_134 * ) V_243 ,
sizeof( V_338 ) ) )
goto V_128;
log . V_125 = V_338 . V_125 ;
log . V_339 = V_338 . V_339 ;
log . V_340 = V_338 . V_340 ;
log . V_91 = F_298 ( V_338 . V_91 ) ;
V_37 = F_309 ( V_19 , & log ) ;
break;
}
default:
V_37 = F_308 ( V_105 , V_242 , V_243 ) ;
}
V_128:
return V_37 ;
}
static int F_323 ( struct V_154 * V_155 , struct V_220 * V_221 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_88 ;
int V_93 ;
T_6 V_153 = V_221 -> V_223 ;
struct V_19 * V_19 = V_155 -> V_222 -> V_106 ;
V_88 = F_159 ( V_19 , V_153 ) ;
if ( F_160 ( V_88 ) )
return V_341 ;
V_93 = F_324 ( V_12 , V_12 -> V_50 , V_88 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_93 != 1 ) )
return V_341 ;
V_221 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_325 ( struct V_104 * V_104 , struct V_154 * V_155 )
{
V_155 -> V_227 = & V_342 ;
return 0 ;
}
static int F_326 ( unsigned long type )
{
int V_37 ;
struct V_19 * V_19 ;
V_19 = F_77 ( type ) ;
if ( F_270 ( V_19 ) )
return F_271 ( V_19 ) ;
#ifdef F_262
V_37 = F_327 ( V_19 ) ;
if ( V_37 < 0 ) {
F_123 ( V_19 ) ;
return V_37 ;
}
#endif
V_37 = F_267 ( L_2 , & V_343 , V_19 , V_230 ) ;
if ( V_37 < 0 )
F_123 ( V_19 ) ;
return V_37 ;
}
static long F_328 ( long V_243 )
{
switch ( V_243 ) {
case V_344 :
case V_345 :
case V_346 :
#ifdef F_312
case V_347 :
#endif
case V_348 :
#ifdef F_313
case V_349 :
#endif
#ifdef F_317
case V_350 :
#endif
return 1 ;
#ifdef F_317
case V_351 :
return V_334 ;
#endif
default:
break;
}
return F_329 ( V_243 ) ;
}
static long F_330 ( struct V_104 * V_105 ,
unsigned int V_242 , unsigned long V_243 )
{
long V_37 = - V_122 ;
switch ( V_242 ) {
case V_352 :
V_37 = - V_122 ;
if ( V_243 )
goto V_128;
V_37 = V_353 ;
break;
case V_354 :
V_37 = F_326 ( V_243 ) ;
break;
case V_355 :
V_37 = F_328 ( V_243 ) ;
break;
case V_356 :
V_37 = - V_122 ;
if ( V_243 )
goto V_128;
V_37 = V_87 ;
#ifdef F_261
V_37 += V_87 ;
#endif
#ifdef F_262
V_37 += V_87 ;
#endif
break;
case V_357 :
case V_358 :
case V_359 :
V_37 = - V_360 ;
break;
default:
return F_331 ( V_105 , V_242 , V_243 ) ;
}
V_128:
return V_37 ;
}
static void F_332 ( void * V_361 )
{
int V_8 = F_333 () ;
int V_37 ;
if ( F_334 ( V_8 , V_362 ) )
return;
F_32 ( V_8 , V_362 ) ;
V_37 = F_335 ( NULL ) ;
if ( V_37 ) {
F_336 ( V_8 , V_362 ) ;
F_88 ( & V_363 ) ;
F_337 ( V_364 L_3
L_4 , V_8 ) ;
}
}
static void F_338 ( void * V_361 )
{
F_92 ( & V_84 ) ;
F_332 ( V_361 ) ;
F_94 ( & V_84 ) ;
}
static void F_339 ( void * V_361 )
{
int V_8 = F_333 () ;
if ( ! F_334 ( V_8 , V_362 ) )
return;
F_336 ( V_8 , V_362 ) ;
F_340 ( NULL ) ;
}
static void F_341 ( void * V_361 )
{
F_92 ( & V_84 ) ;
F_339 ( V_361 ) ;
F_94 ( & V_84 ) ;
}
static void F_342 ( void )
{
F_67 ( ! V_365 ) ;
V_365 -- ;
if ( ! V_365 )
F_343 ( F_339 , NULL , 1 ) ;
}
static void F_96 ( void )
{
F_92 ( & V_84 ) ;
F_342 () ;
F_94 ( & V_84 ) ;
}
static int F_81 ( void )
{
int V_37 = 0 ;
F_92 ( & V_84 ) ;
V_365 ++ ;
if ( V_365 == 1 ) {
F_90 ( & V_363 , 0 ) ;
F_343 ( F_332 , NULL , 1 ) ;
if ( F_275 ( & V_363 ) ) {
F_342 () ;
V_37 = - V_318 ;
}
}
F_94 ( & V_84 ) ;
return V_37 ;
}
static int F_344 ( struct V_366 * V_367 , unsigned long V_368 ,
void * V_231 )
{
int V_8 = ( long ) V_231 ;
if ( ! V_365 )
return V_369 ;
V_368 &= ~ V_370 ;
switch ( V_368 ) {
case V_371 :
F_337 ( V_364 L_5 ,
V_8 ) ;
F_341 ( NULL ) ;
break;
case V_372 :
F_337 ( V_364 L_6 ,
V_8 ) ;
F_338 ( NULL ) ;
break;
}
return V_369 ;
}
static int F_345 ( struct V_366 * V_367 , unsigned long V_368 ,
void * V_231 )
{
F_337 ( V_364 L_7 ) ;
V_373 = true ;
F_343 ( F_339 , NULL , 1 ) ;
return V_369 ;
}
static void F_116 ( struct V_76 * V_374 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_374 -> V_375 ; V_21 ++ ) {
struct V_376 * V_377 = V_374 -> V_378 [ V_21 ] . V_98 ;
F_346 ( V_377 ) ;
}
F_97 ( V_374 ) ;
}
static int F_347 ( const void * V_379 , const void * V_380 )
{
const struct V_381 * V_382 = V_379 ;
const struct V_381 * V_383 = V_380 ;
if ( V_382 -> V_88 < V_383 -> V_88 )
return - 1 ;
if ( V_382 -> V_88 + V_382 -> V_163 > V_383 -> V_88 + V_383 -> V_163 )
return 1 ;
return 0 ;
}
static int F_348 ( struct V_76 * V_374 , struct V_376 * V_98 ,
T_7 V_88 , int V_163 )
{
V_374 -> V_378 [ V_374 -> V_375 ++ ] = (struct V_381 ) {
. V_88 = V_88 ,
. V_163 = V_163 ,
. V_98 = V_98 ,
} ;
F_132 ( V_374 -> V_378 , V_374 -> V_375 , sizeof( struct V_381 ) ,
F_347 , NULL ) ;
return 0 ;
}
static int F_349 ( struct V_76 * V_374 ,
T_7 V_88 , int V_163 )
{
struct V_381 * V_378 , V_384 ;
int V_385 ;
V_384 = (struct V_381 ) {
. V_88 = V_88 ,
. V_163 = V_163 ,
} ;
V_378 = bsearch ( & V_384 , V_374 -> V_378 , V_374 -> V_375 ,
sizeof( struct V_381 ) , F_347 ) ;
if ( V_378 == NULL )
return - V_150 ;
V_385 = V_378 - V_374 -> V_378 ;
while ( V_385 > 0 && F_347 ( & V_384 , & V_374 -> V_378 [ V_385 - 1 ] ) == 0 )
V_385 -- ;
return V_385 ;
}
int F_350 ( struct V_19 * V_19 , enum V_386 V_387 , T_7 V_88 ,
int V_163 , const void * V_368 )
{
int V_53 ;
struct V_76 * V_374 ;
struct V_381 V_378 ;
V_378 = (struct V_381 ) {
. V_88 = V_88 ,
. V_163 = V_163 ,
} ;
V_374 = F_351 ( V_19 -> V_75 [ V_387 ] , & V_19 -> V_54 ) ;
V_53 = F_349 ( V_374 , V_88 , V_163 ) ;
if ( V_53 < 0 )
return - V_360 ;
while ( V_53 < V_374 -> V_375 &&
F_347 ( & V_378 , & V_374 -> V_378 [ V_53 ] ) == 0 ) {
if ( ! F_352 ( V_374 -> V_378 [ V_53 ] . V_98 , V_88 , V_163 , V_368 ) )
return 0 ;
V_53 ++ ;
}
return - V_360 ;
}
int F_353 ( struct V_19 * V_19 , enum V_386 V_387 , T_7 V_88 ,
int V_163 , void * V_368 )
{
int V_53 ;
struct V_76 * V_374 ;
struct V_381 V_378 ;
V_378 = (struct V_381 ) {
. V_88 = V_88 ,
. V_163 = V_163 ,
} ;
V_374 = F_351 ( V_19 -> V_75 [ V_387 ] , & V_19 -> V_54 ) ;
V_53 = F_349 ( V_374 , V_88 , V_163 ) ;
if ( V_53 < 0 )
return - V_360 ;
while ( V_53 < V_374 -> V_375 &&
F_347 ( & V_378 , & V_374 -> V_378 [ V_53 ] ) == 0 ) {
if ( ! F_354 ( V_374 -> V_378 [ V_53 ] . V_98 , V_88 , V_163 , V_368 ) )
return 0 ;
V_53 ++ ;
}
return - V_360 ;
}
int F_355 ( struct V_19 * V_19 , enum V_386 V_387 , T_7 V_88 ,
int V_163 , struct V_376 * V_98 )
{
struct V_76 * V_388 , * V_374 ;
V_374 = V_19 -> V_75 [ V_387 ] ;
if ( V_374 -> V_375 > V_389 - 1 )
return - V_390 ;
V_388 = F_85 ( sizeof( * V_374 ) + ( ( V_374 -> V_375 + 1 ) *
sizeof( struct V_381 ) ) , V_40 ) ;
if ( ! V_388 )
return - V_42 ;
memcpy ( V_388 , V_374 , sizeof( * V_374 ) + ( V_374 -> V_375 *
sizeof( struct V_381 ) ) ) ;
F_348 ( V_388 , V_98 , V_88 , V_163 ) ;
F_12 ( V_19 -> V_75 [ V_387 ] , V_388 ) ;
F_138 ( & V_19 -> V_54 ) ;
F_97 ( V_374 ) ;
return 0 ;
}
int F_356 ( struct V_19 * V_19 , enum V_386 V_387 ,
struct V_376 * V_98 )
{
int V_21 , V_37 ;
struct V_76 * V_388 , * V_374 ;
V_374 = V_19 -> V_75 [ V_387 ] ;
V_37 = - V_150 ;
for ( V_21 = 0 ; V_21 < V_374 -> V_375 ; V_21 ++ )
if ( V_374 -> V_378 [ V_21 ] . V_98 == V_98 ) {
V_37 = 0 ;
break;
}
if ( V_37 )
return V_37 ;
V_388 = F_85 ( sizeof( * V_374 ) + ( ( V_374 -> V_375 - 1 ) *
sizeof( struct V_381 ) ) , V_40 ) ;
if ( ! V_388 )
return - V_42 ;
memcpy ( V_388 , V_374 , sizeof( * V_374 ) + V_21 * sizeof( struct V_381 ) ) ;
V_388 -> V_375 -- ;
memcpy ( V_388 -> V_378 + V_21 , V_374 -> V_378 + V_21 + 1 ,
( V_388 -> V_375 - V_21 ) * sizeof( struct V_381 ) ) ;
F_12 ( V_19 -> V_75 [ V_387 ] , V_388 ) ;
F_138 ( & V_19 -> V_54 ) ;
F_97 ( V_374 ) ;
return V_37 ;
}
static int F_357 ( void * V_391 , T_4 * V_368 )
{
unsigned V_191 = ( long ) V_391 ;
struct V_19 * V_19 ;
* V_368 = 0 ;
F_92 ( & V_84 ) ;
F_358 ( V_19 , & V_85 , V_85 )
* V_368 += * ( T_5 * ) ( ( void * ) V_19 + V_191 ) ;
F_94 ( & V_84 ) ;
return 0 ;
}
static int F_359 ( void * V_391 , T_4 * V_368 )
{
unsigned V_191 = ( long ) V_391 ;
struct V_19 * V_19 ;
struct V_6 * V_7 ;
int V_21 ;
* V_368 = 0 ;
F_92 ( & V_84 ) ;
F_358 (kvm, &vm_list, vm_list)
F_28 ( V_21 , V_7 , V_19 )
* V_368 += * ( T_5 * ) ( ( void * ) V_7 + V_191 ) ;
F_94 ( & V_84 ) ;
return 0 ;
}
static int F_360 ( void )
{
int V_37 = - V_151 ;
struct V_392 * V_275 ;
V_393 = F_361 ( L_8 , NULL ) ;
if ( V_393 == NULL )
goto V_128;
for ( V_275 = V_394 ; V_275 -> V_303 ; ++ V_275 ) {
V_275 -> V_395 = F_362 ( V_275 -> V_303 , 0444 , V_393 ,
( void * ) ( long ) V_275 -> V_191 ,
V_396 [ V_275 -> V_397 ] ) ;
if ( V_275 -> V_395 == NULL )
goto V_398;
}
return 0 ;
V_398:
F_363 ( V_393 ) ;
V_128:
return V_37 ;
}
static void F_364 ( void )
{
struct V_392 * V_275 ;
for ( V_275 = V_394 ; V_275 -> V_303 ; ++ V_275 )
F_365 ( V_275 -> V_395 ) ;
F_365 ( V_393 ) ;
}
static int F_366 ( void )
{
if ( V_365 )
F_339 ( NULL ) ;
return 0 ;
}
static void F_367 ( void )
{
if ( V_365 ) {
F_199 ( F_368 ( & V_84 ) ) ;
F_332 ( NULL ) ;
}
}
static inline
struct V_6 * F_369 ( struct V_17 * V_399 )
{
return F_54 ( V_399 , struct V_6 , V_17 ) ;
}
static void F_370 ( struct V_17 * V_399 , int V_8 )
{
struct V_6 * V_7 = F_369 ( V_399 ) ;
if ( V_7 -> V_45 )
V_7 -> V_45 = false ;
F_17 ( V_7 , V_8 ) ;
}
static void F_371 ( struct V_17 * V_399 ,
struct V_164 * V_400 )
{
struct V_6 * V_7 = F_369 ( V_399 ) ;
if ( V_12 -> V_401 == V_402 )
V_7 -> V_45 = true ;
F_21 ( V_7 ) ;
}
int F_372 ( void * V_403 , unsigned V_404 , unsigned V_405 ,
struct V_406 * V_406 )
{
int V_37 ;
int V_8 ;
V_37 = F_373 ( V_403 ) ;
if ( V_37 )
goto V_407;
V_37 = F_374 () ;
if ( V_37 )
goto V_408;
if ( ! F_27 ( & V_362 , V_40 ) ) {
V_37 = - V_42 ;
goto V_409;
}
V_37 = F_375 () ;
if ( V_37 < 0 )
goto V_410;
F_376 (cpu) {
F_377 ( V_8 ,
V_411 ,
& V_37 , 1 ) ;
if ( V_37 < 0 )
goto V_412;
}
V_37 = F_378 ( & V_413 ) ;
if ( V_37 )
goto V_414;
F_379 ( & V_415 ) ;
if ( ! V_405 )
V_405 = F_380 ( struct V_6 ) ;
V_416 = F_381 ( L_9 , V_404 , V_405 ,
0 , NULL ) ;
if ( ! V_416 ) {
V_37 = - V_42 ;
goto V_417;
}
V_37 = F_382 () ;
if ( V_37 )
goto V_142;
V_418 . V_419 = V_406 ;
V_343 . V_419 = V_406 ;
V_229 . V_419 = V_406 ;
V_37 = F_383 ( & V_420 ) ;
if ( V_37 ) {
F_337 ( V_421 L_10 ) ;
goto V_422;
}
F_384 ( & V_423 ) ;
V_232 . V_424 = F_370 ;
V_232 . V_425 = F_371 ;
V_37 = F_360 () ;
if ( V_37 ) {
F_337 ( V_421 L_11 ) ;
goto V_426;
}
return 0 ;
V_426:
F_385 ( & V_423 ) ;
V_422:
F_386 () ;
V_142:
F_387 ( V_416 ) ;
V_417:
F_388 ( & V_415 ) ;
F_389 ( & V_413 ) ;
V_414:
V_412:
F_390 () ;
V_410:
F_35 ( V_362 ) ;
V_409:
F_391 () ;
V_408:
F_392 () ;
V_407:
return V_37 ;
}
void F_393 ( void )
{
F_364 () ;
F_394 ( & V_420 ) ;
F_387 ( V_416 ) ;
F_386 () ;
F_385 ( & V_423 ) ;
F_388 ( & V_415 ) ;
F_389 ( & V_413 ) ;
F_343 ( F_339 , NULL , 1 ) ;
F_390 () ;
F_392 () ;
F_391 () ;
F_35 ( V_362 ) ;
}
