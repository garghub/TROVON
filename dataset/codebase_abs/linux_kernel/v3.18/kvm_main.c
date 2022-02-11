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
if ( F_7 ( V_3 -> V_7 != V_8 -> V_9 [ V_10 ] . V_7 ) ) {
struct V_7 * V_11 = V_3 -> V_7 ;
struct V_7 * V_12 = F_8 ( V_8 , V_10 ) ;
F_9 ( V_3 -> V_7 , V_12 ) ;
if ( V_11 )
F_10 () ;
F_11 ( V_11 ) ;
}
V_4 = F_12 () ;
F_13 ( & V_3 -> V_13 ) ;
F_14 ( V_3 , V_4 ) ;
F_15 () ;
return 0 ;
}
void F_16 ( struct V_2 * V_3 )
{
F_17 () ;
F_18 ( V_3 ) ;
F_19 ( & V_3 -> V_13 ) ;
F_20 () ;
F_21 ( & V_3 -> V_5 ) ;
}
static void F_22 ( void * V_14 )
{
}
bool F_23 ( struct V_15 * V_15 , unsigned int V_16 )
{
int V_17 , V_4 , V_18 ;
T_2 V_19 ;
bool V_20 = true ;
struct V_2 * V_3 ;
F_24 ( & V_19 , V_21 ) ;
V_18 = F_12 () ;
F_25 (i, vcpu, kvm) {
F_26 ( V_16 , V_3 ) ;
V_4 = V_3 -> V_4 ;
F_27 () ;
if ( V_19 != NULL && V_4 != - 1 && V_4 != V_18 &&
F_28 ( V_3 ) != V_22 )
F_29 ( V_4 , V_19 ) ;
}
if ( F_7 ( V_19 == NULL ) )
F_30 ( V_23 , F_22 , NULL , 1 ) ;
else if ( ! F_31 ( V_19 ) )
F_30 ( V_19 , F_22 , NULL , 1 ) ;
else
V_20 = false ;
F_15 () ;
F_32 ( V_19 ) ;
return V_20 ;
}
void F_33 ( struct V_15 * V_15 )
{
long V_24 = V_15 -> V_25 ;
F_27 () ;
if ( F_23 ( V_15 , V_26 ) )
++ V_15 -> V_27 . V_28 ;
F_34 ( & V_15 -> V_25 , V_24 , 0 ) ;
}
void F_35 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_29 ) ;
}
void F_36 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_30 ) ;
}
void F_37 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_31 ) ;
}
int F_38 ( struct V_2 * V_3 , struct V_15 * V_15 , unsigned V_32 )
{
struct V_33 * V_33 ;
int V_34 ;
F_39 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_35 = V_32 ;
V_3 -> V_7 = NULL ;
F_40 ( & V_3 -> V_36 ) ;
F_41 ( V_3 ) ;
V_33 = F_42 ( V_37 | V_38 ) ;
if ( ! V_33 ) {
V_34 = - V_39 ;
goto V_40;
}
V_3 -> V_41 = F_43 ( V_33 ) ;
F_44 ( V_3 , false ) ;
F_45 ( V_3 , false ) ;
V_3 -> V_42 = false ;
V_34 = F_46 ( V_3 ) ;
if ( V_34 < 0 )
goto V_43;
return 0 ;
V_43:
F_47 ( ( unsigned long ) V_3 -> V_41 ) ;
V_40:
return V_34 ;
}
void F_48 ( struct V_2 * V_3 )
{
F_11 ( V_3 -> V_7 ) ;
F_49 ( V_3 ) ;
F_47 ( ( unsigned long ) V_3 -> V_41 ) ;
}
static inline struct V_15 * F_50 ( struct V_44 * V_45 )
{
return F_51 ( V_45 , struct V_15 , V_44 ) ;
}
static void F_52 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_49 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
V_49 = F_55 ( V_15 , V_48 ) | V_15 -> V_25 ;
if ( V_49 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( V_15 , V_48 ) ;
F_58 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_59 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 ,
T_3 V_54 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
F_60 ( V_15 , V_48 , V_54 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_58 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_61 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_49 = 0 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_57 ++ ;
V_49 = F_62 ( V_15 , V_55 , V_56 ) ;
V_49 |= V_15 -> V_25 ;
if ( V_49 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_58 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_63 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
F_64 () ;
V_15 -> V_57 -- ;
F_56 ( & V_15 -> V_52 ) ;
F_65 ( V_15 -> V_57 < 0 ) ;
}
static int F_66 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_58 = F_67 ( V_15 , V_55 , V_56 ) ;
if ( V_58 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_58 ( & V_15 -> V_51 , V_50 ) ;
return V_58 ;
}
static int F_68 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_58 = F_69 ( V_15 , V_48 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_58 ( & V_15 -> V_51 , V_50 ) ;
return V_58 ;
}
static void F_70 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_71 ( V_15 ) ;
F_58 ( & V_15 -> V_51 , V_50 ) ;
}
static int F_72 ( struct V_15 * V_15 )
{
V_15 -> V_44 . V_59 = & V_60 ;
return F_73 ( & V_15 -> V_44 , V_8 -> V_47 ) ;
}
static int F_72 ( struct V_15 * V_15 )
{
return 0 ;
}
static void F_74 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_61 * V_62 = V_15 -> V_63 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ )
V_62 -> V_65 [ V_17 ] = V_62 -> V_63 [ V_17 ] . V_32 = V_17 ;
}
static struct V_15 * F_75 ( unsigned long type )
{
int V_34 , V_17 ;
struct V_15 * V_15 = F_76 () ;
if ( ! V_15 )
return F_77 ( - V_39 ) ;
V_34 = F_78 ( V_15 , type ) ;
if ( V_34 )
goto V_66;
V_34 = F_79 () ;
if ( V_34 )
goto V_66;
#ifdef F_80
F_81 ( & V_15 -> V_67 ) ;
#endif
#ifdef F_82
F_81 ( & V_15 -> V_68 ) ;
#endif
F_83 ( V_64 > V_69 ) ;
V_34 = - V_39 ;
V_15 -> V_63 = F_84 ( sizeof( struct V_61 ) , V_37 ) ;
if ( ! V_15 -> V_63 )
goto V_70;
V_15 -> V_63 -> V_71 = - 150 ;
F_74 ( V_15 ) ;
if ( F_85 ( & V_15 -> V_51 ) )
goto V_70;
if ( F_85 ( & V_15 -> V_72 ) )
goto V_73;
for ( V_17 = 0 ; V_17 < V_74 ; V_17 ++ ) {
V_15 -> V_75 [ V_17 ] = F_84 ( sizeof( struct V_76 ) ,
V_37 ) ;
if ( ! V_15 -> V_75 [ V_17 ] )
goto V_77;
}
F_86 ( & V_15 -> V_52 ) ;
V_15 -> V_47 = V_8 -> V_47 ;
F_87 ( & V_15 -> V_47 -> V_78 ) ;
F_88 ( V_15 ) ;
F_39 ( & V_15 -> V_79 ) ;
F_39 ( & V_15 -> V_80 ) ;
F_39 ( & V_15 -> V_81 ) ;
F_89 ( & V_15 -> V_82 , 1 ) ;
F_90 ( & V_15 -> V_83 ) ;
V_34 = F_72 ( V_15 ) ;
if ( V_34 )
goto V_77;
F_54 ( & V_84 ) ;
F_91 ( & V_15 -> V_85 , & V_85 ) ;
F_56 ( & V_84 ) ;
return V_15 ;
V_77:
F_92 ( & V_15 -> V_72 ) ;
V_73:
F_92 ( & V_15 -> V_51 ) ;
V_70:
F_93 () ;
V_66:
for ( V_17 = 0 ; V_17 < V_74 ; V_17 ++ )
F_94 ( V_15 -> V_75 [ V_17 ] ) ;
F_94 ( V_15 -> V_63 ) ;
F_95 ( V_15 ) ;
return F_77 ( V_34 ) ;
}
void * F_96 ( unsigned long V_86 )
{
if ( V_86 > V_87 )
return F_97 ( V_86 ) ;
else
return F_84 ( V_86 , V_37 ) ;
}
void F_98 ( const void * V_88 )
{
if ( F_99 ( V_88 ) )
F_100 ( V_88 ) ;
else
F_94 ( V_88 ) ;
}
static void F_101 ( struct V_89 * V_90 )
{
if ( ! V_90 -> V_91 )
return;
F_98 ( V_90 -> V_91 ) ;
V_90 -> V_91 = NULL ;
}
static void F_102 ( struct V_15 * V_15 , struct V_89 * free ,
struct V_89 * V_92 )
{
if ( ! V_92 || free -> V_91 != V_92 -> V_91 )
F_101 ( free ) ;
F_103 ( V_15 , free , V_92 ) ;
free -> V_93 = 0 ;
}
static void F_104 ( struct V_15 * V_15 )
{
struct V_61 * V_62 = V_15 -> V_63 ;
struct V_89 * V_90 ;
F_105 (memslot, slots)
F_102 ( V_15 , V_90 , NULL ) ;
F_94 ( V_15 -> V_63 ) ;
}
static void F_106 ( struct V_15 * V_15 )
{
struct V_94 * V_95 , * V_96 ;
F_107 (node, tmp, &kvm->devices) {
struct V_97 * V_98 =
F_108 ( V_95 , struct V_97 , V_99 ) ;
F_109 ( V_95 ) ;
V_98 -> V_59 -> V_100 ( V_98 ) ;
}
}
static void F_110 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_46 * V_47 = V_15 -> V_47 ;
F_111 ( V_15 ) ;
F_54 ( & V_84 ) ;
F_109 ( & V_15 -> V_85 ) ;
F_56 ( & V_84 ) ;
F_112 ( V_15 ) ;
for ( V_17 = 0 ; V_17 < V_74 ; V_17 ++ )
F_113 ( V_15 -> V_75 [ V_17 ] ) ;
F_114 ( V_15 ) ;
#if F_115 ( V_101 ) && F_115 ( V_102 )
F_116 ( & V_15 -> V_44 , V_15 -> V_47 ) ;
#else
F_71 ( V_15 ) ;
#endif
F_117 ( V_15 ) ;
F_106 ( V_15 ) ;
F_104 ( V_15 ) ;
F_92 ( & V_15 -> V_72 ) ;
F_92 ( & V_15 -> V_51 ) ;
F_95 ( V_15 ) ;
F_93 () ;
F_118 ( V_47 ) ;
}
void F_119 ( struct V_15 * V_15 )
{
F_87 ( & V_15 -> V_82 ) ;
}
void F_120 ( struct V_15 * V_15 )
{
if ( F_121 ( & V_15 -> V_82 ) )
F_110 ( V_15 ) ;
}
static int F_122 ( struct V_103 * V_103 , struct V_104 * V_105 )
{
struct V_15 * V_15 = V_105 -> V_106 ;
F_123 ( V_15 ) ;
F_120 ( V_15 ) ;
return 0 ;
}
static int F_124 ( struct V_89 * V_90 )
{
unsigned long V_107 = 2 * F_125 ( V_90 ) ;
V_90 -> V_91 = F_96 ( V_107 ) ;
if ( ! V_90 -> V_91 )
return - V_39 ;
return 0 ;
}
static int F_126 ( const void * V_108 , const void * V_109 )
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
static void F_127 ( struct V_61 * V_62 )
{
int V_17 ;
F_128 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_89 ) , F_126 , NULL ) ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_17 ] . V_32 ] = V_17 ;
}
static void F_129 ( struct V_61 * V_62 ,
struct V_89 * V_112 )
{
if ( V_112 ) {
int V_32 = V_112 -> V_32 ;
struct V_89 * V_113 = F_130 ( V_62 , V_32 ) ;
unsigned long V_93 = V_113 -> V_93 ;
* V_113 = * V_112 ;
if ( V_112 -> V_93 != V_93 )
F_127 ( V_62 ) ;
}
}
static int F_131 ( struct V_114 * V_115 )
{
T_4 V_116 = V_117 ;
#ifdef F_132
V_116 |= V_118 ;
#endif
if ( V_115 -> V_119 & ~ V_116 )
return - V_120 ;
return 0 ;
}
static struct V_61 * F_133 ( struct V_15 * V_15 ,
struct V_61 * V_62 , struct V_89 * V_112 )
{
struct V_61 * V_121 = V_15 -> V_63 ;
F_134 ( V_121 -> V_71 & 1 ) ;
V_62 -> V_71 = V_121 -> V_71 + 1 ;
F_129 ( V_62 , V_112 ) ;
F_9 ( V_15 -> V_63 , V_62 ) ;
F_135 ( & V_15 -> V_51 ) ;
V_62 -> V_71 ++ ;
F_136 ( V_15 ) ;
return V_121 ;
}
int F_137 ( struct V_15 * V_15 ,
struct V_114 * V_115 )
{
int V_34 ;
T_5 V_122 ;
unsigned long V_93 ;
struct V_89 * V_123 ;
struct V_89 V_113 , V_112 ;
struct V_61 * V_62 = NULL , * V_121 ;
enum V_124 V_125 ;
V_34 = F_131 ( V_115 ) ;
if ( V_34 )
goto V_126;
V_34 = - V_120 ;
if ( V_115 -> V_127 & ( V_87 - 1 ) )
goto V_126;
if ( V_115 -> V_128 & ( V_87 - 1 ) )
goto V_126;
if ( ( V_115 -> V_123 < V_129 ) &&
( ( V_115 -> V_130 & ( V_87 - 1 ) ) ||
! F_138 ( V_131 ,
( void V_132 * ) ( unsigned long ) V_115 -> V_130 ,
V_115 -> V_127 ) ) )
goto V_126;
if ( V_115 -> V_123 >= V_64 )
goto V_126;
if ( V_115 -> V_128 + V_115 -> V_127 < V_115 -> V_128 )
goto V_126;
V_123 = F_130 ( V_15 -> V_63 , V_115 -> V_123 ) ;
V_122 = V_115 -> V_128 >> V_133 ;
V_93 = V_115 -> V_127 >> V_133 ;
if ( V_93 > V_134 )
goto V_126;
if ( ! V_93 )
V_115 -> V_119 &= ~ V_117 ;
V_112 = V_113 = * V_123 ;
V_112 . V_32 = V_115 -> V_123 ;
V_112 . V_122 = V_122 ;
V_112 . V_93 = V_93 ;
V_112 . V_119 = V_115 -> V_119 ;
if ( V_93 ) {
if ( ! V_113 . V_93 )
V_125 = V_135 ;
else {
if ( ( V_115 -> V_130 != V_113 . V_130 ) ||
( V_93 != V_113 . V_93 ) ||
( ( V_112 . V_119 ^ V_113 . V_119 ) & V_118 ) )
goto V_126;
if ( V_122 != V_113 . V_122 )
V_125 = V_136 ;
else if ( V_112 . V_119 != V_113 . V_119 )
V_125 = V_137 ;
else {
V_34 = 0 ;
goto V_126;
}
}
} else if ( V_113 . V_93 ) {
V_125 = V_138 ;
} else
goto V_126;
if ( ( V_125 == V_135 ) || ( V_125 == V_136 ) ) {
V_34 = - V_139 ;
F_105 (slot, kvm->memslots) {
if ( ( V_123 -> V_32 >= V_129 ) ||
( V_123 -> V_32 == V_115 -> V_123 ) )
continue;
if ( ! ( ( V_122 + V_93 <= V_123 -> V_122 ) ||
( V_122 >= V_123 -> V_122 + V_123 -> V_93 ) ) )
goto V_126;
}
}
if ( ! ( V_112 . V_119 & V_117 ) )
V_112 . V_91 = NULL ;
V_34 = - V_39 ;
if ( V_125 == V_135 ) {
V_112 . V_130 = V_115 -> V_130 ;
if ( F_139 ( V_15 , & V_112 , V_93 ) )
goto V_140;
}
if ( ( V_112 . V_119 & V_117 ) && ! V_112 . V_91 ) {
if ( F_124 ( & V_112 ) < 0 )
goto V_140;
}
if ( ( V_125 == V_138 ) || ( V_125 == V_136 ) ) {
V_62 = F_140 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_140;
V_123 = F_130 ( V_62 , V_115 -> V_123 ) ;
V_123 -> V_119 |= V_141 ;
V_121 = F_133 ( V_15 , V_62 , NULL ) ;
F_141 ( V_15 , & V_113 ) ;
F_142 ( V_15 , V_123 ) ;
V_62 = V_121 ;
}
V_34 = F_143 ( V_15 , & V_112 , V_115 , V_125 ) ;
if ( V_34 )
goto V_142;
V_34 = - V_39 ;
if ( ! V_62 ) {
V_62 = F_140 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_140;
}
if ( V_125 == V_138 ) {
V_112 . V_91 = NULL ;
memset ( & V_112 . V_143 , 0 , sizeof( V_112 . V_143 ) ) ;
}
V_121 = F_133 ( V_15 , V_62 , & V_112 ) ;
F_144 ( V_15 , V_115 , & V_113 , V_125 ) ;
F_102 ( V_15 , & V_113 , & V_112 ) ;
F_94 ( V_121 ) ;
if ( ( V_125 == V_135 ) || ( V_125 == V_136 ) ) {
V_34 = F_145 ( V_15 , & V_112 ) ;
return V_34 ;
}
return 0 ;
V_142:
F_94 ( V_62 ) ;
V_140:
F_102 ( V_15 , & V_112 , & V_113 ) ;
V_126:
return V_34 ;
}
int F_146 ( struct V_15 * V_15 ,
struct V_114 * V_115 )
{
int V_34 ;
F_147 ( & V_15 -> V_81 ) ;
V_34 = F_137 ( V_15 , V_115 ) ;
F_21 ( & V_15 -> V_81 ) ;
return V_34 ;
}
static int F_148 ( struct V_15 * V_15 ,
struct V_114 * V_115 )
{
if ( V_115 -> V_123 >= V_129 )
return - V_120 ;
return F_146 ( V_15 , V_115 ) ;
}
int F_149 ( struct V_15 * V_15 ,
struct V_144 * log , int * V_145 )
{
struct V_89 * V_90 ;
int V_34 , V_17 ;
unsigned long V_146 ;
unsigned long V_147 = 0 ;
V_34 = - V_120 ;
if ( log -> V_123 >= V_129 )
goto V_126;
V_90 = F_130 ( V_15 -> V_63 , log -> V_123 ) ;
V_34 = - V_148 ;
if ( ! V_90 -> V_91 )
goto V_126;
V_146 = F_125 ( V_90 ) ;
for ( V_17 = 0 ; ! V_147 && V_17 < V_146 / sizeof( long ) ; ++ V_17 )
V_147 = V_90 -> V_91 [ V_17 ] ;
V_34 = - V_149 ;
if ( F_150 ( log -> V_91 , V_90 -> V_91 , V_146 ) )
goto V_126;
if ( V_147 )
* V_145 = 1 ;
V_34 = 0 ;
V_126:
return V_34 ;
}
bool F_151 ( void )
{
return V_150 ;
}
void F_152 ( void )
{
V_150 = false ;
}
struct V_89 * F_153 ( struct V_15 * V_15 , T_5 V_151 )
{
return F_154 ( V_61 ( V_15 ) , V_151 ) ;
}
int F_155 ( struct V_15 * V_15 , T_5 V_151 )
{
struct V_89 * V_90 = F_153 ( V_15 , V_151 ) ;
if ( ! V_90 || V_90 -> V_32 >= V_129 ||
V_90 -> V_119 & V_141 )
return 0 ;
return 1 ;
}
unsigned long F_156 ( struct V_15 * V_15 , T_5 V_151 )
{
struct V_152 * V_153 ;
unsigned long V_88 , V_86 ;
V_86 = V_87 ;
V_88 = F_157 ( V_15 , V_151 ) ;
if ( F_158 ( V_88 ) )
return V_87 ;
F_159 ( & V_8 -> V_47 -> V_154 ) ;
V_153 = F_160 ( V_8 -> V_47 , V_88 ) ;
if ( ! V_153 )
goto V_126;
V_86 = F_161 ( V_153 ) ;
V_126:
F_162 ( & V_8 -> V_47 -> V_154 ) ;
return V_86 ;
}
static bool F_163 ( struct V_89 * V_123 )
{
return V_123 -> V_119 & V_118 ;
}
static unsigned long F_164 ( struct V_89 * V_123 , T_5 V_151 ,
T_5 * V_155 , bool V_156 )
{
if ( ! V_123 || V_123 -> V_119 & V_141 )
return V_157 ;
if ( F_163 ( V_123 ) && V_156 )
return V_158 ;
if ( V_155 )
* V_155 = V_123 -> V_93 - ( V_151 - V_123 -> V_122 ) ;
return F_165 ( V_123 , V_151 ) ;
}
static unsigned long F_166 ( struct V_89 * V_123 , T_5 V_151 ,
T_5 * V_155 )
{
return F_164 ( V_123 , V_151 , V_155 , true ) ;
}
unsigned long F_167 ( struct V_89 * V_123 ,
T_5 V_151 )
{
return F_166 ( V_123 , V_151 , NULL ) ;
}
unsigned long F_157 ( struct V_15 * V_15 , T_5 V_151 )
{
return F_166 ( F_153 ( V_15 , V_151 ) , V_151 , NULL ) ;
}
unsigned long F_168 ( struct V_89 * V_123 ,
T_5 V_151 , bool * V_159 )
{
unsigned long V_160 = F_164 ( V_123 , V_151 , NULL , false ) ;
if ( ! F_158 ( V_160 ) && V_159 )
* V_159 = ! F_163 ( V_123 ) ;
return V_160 ;
}
unsigned long F_169 ( struct V_15 * V_15 , T_5 V_151 , bool * V_159 )
{
struct V_89 * V_123 = F_153 ( V_15 , V_151 ) ;
return F_168 ( V_123 , V_151 , V_159 ) ;
}
static int F_170 ( void * V_161 , void V_132 * V_160 , int V_162 )
{
return F_171 ( V_161 , V_160 , V_162 ) ;
}
static int F_172 ( void * V_161 , void V_132 * V_160 , int V_162 )
{
return F_173 ( V_161 , V_160 , V_162 ) ;
}
static int F_174 ( struct V_163 * V_164 , struct V_46 * V_47 ,
unsigned long V_55 , int V_156 , struct V_33 * * V_33 )
{
int V_119 = V_165 | V_166 | V_167 | V_168 ;
if ( V_156 )
V_119 |= V_169 ;
return F_175 ( V_164 , V_47 , V_55 , 1 , V_119 , V_33 , NULL , NULL ) ;
}
int F_176 ( struct V_163 * V_164 , struct V_46 * V_47 ,
unsigned long V_88 , bool V_170 ,
struct V_33 * * V_171 )
{
int V_93 ;
int V_172 = 1 ;
int V_119 = V_165 | V_167 |
( V_171 ? V_168 : 0 ) |
( V_170 ? V_169 : 0 ) ;
F_159 ( & V_47 -> V_154 ) ;
V_93 = F_175 ( V_164 , V_47 , V_88 , 1 , V_119 , V_171 , NULL ,
& V_172 ) ;
if ( ! V_172 ) {
F_177 ( V_93 ) ;
if ( ! V_171 )
return 0 ;
F_159 ( & V_47 -> V_154 ) ;
V_93 = F_175 ( V_164 , V_47 , V_88 , 1 , V_119 | V_173 ,
V_171 , NULL , NULL ) ;
}
F_162 ( & V_47 -> V_154 ) ;
return V_93 ;
}
static inline int F_178 ( unsigned long V_88 )
{
int V_174 , V_119 = V_165 | V_167 | V_169 ;
V_174 = F_175 ( V_8 , V_8 -> V_47 , V_88 , 1 ,
V_119 , NULL , NULL , NULL ) ;
return V_174 == - V_175 ;
}
static bool F_179 ( unsigned long V_88 , bool V_176 , bool * V_177 ,
bool V_170 , bool * V_159 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_93 ;
if ( ! ( V_177 || V_176 ) )
return false ;
if ( ! ( V_170 || V_159 ) )
return false ;
V_93 = F_180 ( V_88 , 1 , 1 , V_33 ) ;
if ( V_93 == 1 ) {
* V_1 = F_181 ( V_33 [ 0 ] ) ;
if ( V_159 )
* V_159 = true ;
return true ;
}
return false ;
}
static int F_182 ( unsigned long V_88 , bool * V_177 , bool V_170 ,
bool * V_159 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_93 = 0 ;
F_183 () ;
if ( V_159 )
* V_159 = V_170 ;
if ( V_177 ) {
F_159 ( & V_8 -> V_47 -> V_154 ) ;
V_93 = F_174 ( V_8 , V_8 -> V_47 ,
V_88 , V_170 , V_33 ) ;
F_162 ( & V_8 -> V_47 -> V_154 ) ;
} else {
V_93 = F_176 ( V_8 , V_8 -> V_47 , V_88 ,
V_170 , V_33 ) ;
}
if ( V_93 != 1 )
return V_93 ;
if ( F_7 ( ! V_170 ) && V_159 ) {
struct V_33 * V_178 [ 1 ] ;
V_93 = F_180 ( V_88 , 1 , 1 , V_178 ) ;
if ( V_93 == 1 ) {
* V_159 = true ;
F_184 ( V_33 [ 0 ] ) ;
V_33 [ 0 ] = V_178 [ 0 ] ;
}
V_93 = 1 ;
}
* V_1 = F_181 ( V_33 [ 0 ] ) ;
return V_93 ;
}
static bool F_185 ( struct V_152 * V_153 , bool V_170 )
{
if ( F_7 ( ! ( V_153 -> V_179 & V_180 ) ) )
return false ;
if ( V_170 && ( F_7 ( ! ( V_153 -> V_179 & V_181 ) ) ) )
return false ;
return true ;
}
static T_1 F_186 ( unsigned long V_88 , bool V_176 , bool * V_177 ,
bool V_170 , bool * V_159 )
{
struct V_152 * V_153 ;
T_1 V_1 = 0 ;
int V_93 ;
F_65 ( V_176 && V_177 ) ;
if ( F_179 ( V_88 , V_176 , V_177 , V_170 , V_159 , & V_1 ) )
return V_1 ;
if ( V_176 )
return V_182 ;
V_93 = F_182 ( V_88 , V_177 , V_170 , V_159 , & V_1 ) ;
if ( V_93 == 1 )
return V_1 ;
F_159 ( & V_8 -> V_47 -> V_154 ) ;
if ( V_93 == - V_175 ||
( ! V_177 && F_178 ( V_88 ) ) ) {
V_1 = V_183 ;
goto exit;
}
V_153 = F_187 ( V_8 -> V_47 , V_88 , V_88 + 1 ) ;
if ( V_153 == NULL )
V_1 = V_182 ;
else if ( ( V_153 -> V_179 & V_184 ) ) {
V_1 = ( ( V_88 - V_153 -> V_185 ) >> V_133 ) +
V_153 -> V_186 ;
F_65 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_177 && F_185 ( V_153 , V_170 ) )
* V_177 = true ;
V_1 = V_182 ;
}
exit:
F_162 ( & V_8 -> V_47 -> V_154 ) ;
return V_1 ;
}
static T_1
F_188 ( struct V_89 * V_123 , T_5 V_151 , bool V_176 ,
bool * V_177 , bool V_170 , bool * V_159 )
{
unsigned long V_88 = F_164 ( V_123 , V_151 , NULL , V_170 ) ;
if ( V_88 == V_158 )
return V_187 ;
if ( F_158 ( V_88 ) )
return V_188 ;
if ( V_159 && F_163 ( V_123 ) ) {
* V_159 = false ;
V_159 = NULL ;
}
return F_186 ( V_88 , V_176 , V_177 , V_170 ,
V_159 ) ;
}
static T_1 F_189 ( struct V_15 * V_15 , T_5 V_151 , bool V_176 , bool * V_177 ,
bool V_170 , bool * V_159 )
{
struct V_89 * V_123 ;
if ( V_177 )
* V_177 = false ;
V_123 = F_153 ( V_15 , V_151 ) ;
return F_188 ( V_123 , V_151 , V_176 , V_177 , V_170 ,
V_159 ) ;
}
T_1 F_190 ( struct V_15 * V_15 , T_5 V_151 )
{
return F_189 ( V_15 , V_151 , true , NULL , true , NULL ) ;
}
T_1 F_191 ( struct V_15 * V_15 , T_5 V_151 , bool * V_177 ,
bool V_170 , bool * V_159 )
{
return F_189 ( V_15 , V_151 , false , V_177 , V_170 , V_159 ) ;
}
T_1 F_192 ( struct V_15 * V_15 , T_5 V_151 )
{
return F_189 ( V_15 , V_151 , false , NULL , true , NULL ) ;
}
T_1 F_193 ( struct V_15 * V_15 , T_5 V_151 , bool V_170 ,
bool * V_159 )
{
return F_189 ( V_15 , V_151 , false , NULL , V_170 , V_159 ) ;
}
T_1 F_194 ( struct V_89 * V_123 , T_5 V_151 )
{
return F_188 ( V_123 , V_151 , false , NULL , true , NULL ) ;
}
T_1 F_195 ( struct V_89 * V_123 , T_5 V_151 )
{
return F_188 ( V_123 , V_151 , true , NULL , true , NULL ) ;
}
int F_196 ( struct V_15 * V_15 , T_5 V_151 , struct V_33 * * V_189 ,
int V_155 )
{
unsigned long V_88 ;
T_5 V_190 ;
V_88 = F_166 ( F_153 ( V_15 , V_151 ) , V_151 , & V_190 ) ;
if ( F_158 ( V_88 ) )
return - 1 ;
if ( V_190 < V_155 )
return 0 ;
return F_180 ( V_88 , V_155 , 1 , V_189 ) ;
}
static struct V_33 * F_197 ( T_1 V_1 )
{
if ( F_198 ( V_1 ) )
return V_191 ;
if ( F_1 ( V_1 ) ) {
F_134 ( 1 ) ;
return V_191 ;
}
return F_4 ( V_1 ) ;
}
struct V_33 * F_199 ( struct V_15 * V_15 , T_5 V_151 )
{
T_1 V_1 ;
V_1 = F_192 ( V_15 , V_151 ) ;
return F_197 ( V_1 ) ;
}
void F_200 ( struct V_33 * V_33 )
{
F_134 ( F_201 ( V_33 ) ) ;
F_202 ( F_181 ( V_33 ) ) ;
}
void F_202 ( T_1 V_1 )
{
if ( ! F_198 ( V_1 ) && ! F_1 ( V_1 ) )
F_184 ( F_4 ( V_1 ) ) ;
}
void F_203 ( struct V_33 * V_33 )
{
F_134 ( F_201 ( V_33 ) ) ;
F_204 ( F_181 ( V_33 ) ) ;
}
static void F_204 ( T_1 V_1 )
{
F_205 ( V_1 ) ;
F_202 ( V_1 ) ;
}
void F_205 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_33 * V_33 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_33 ) )
F_206 ( V_33 ) ;
}
}
void F_207 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_208 ( F_4 ( V_1 ) ) ;
}
void F_209 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_210 ( F_4 ( V_1 ) ) ;
}
static int F_211 ( unsigned long V_162 , int V_192 )
{
if ( V_162 > V_87 - V_192 )
return V_87 - V_192 ;
else
return V_162 ;
}
int F_212 ( struct V_15 * V_15 , T_5 V_151 , void * V_161 , int V_192 ,
int V_162 )
{
int V_34 ;
unsigned long V_88 ;
V_88 = F_169 ( V_15 , V_151 , NULL ) ;
if ( F_158 ( V_88 ) )
return - V_149 ;
V_34 = F_170 ( V_161 , ( void V_132 * ) V_88 + V_192 , V_162 ) ;
if ( V_34 )
return - V_149 ;
return 0 ;
}
int F_213 ( struct V_15 * V_15 , T_6 V_193 , void * V_161 , unsigned long V_162 )
{
T_5 V_151 = V_193 >> V_133 ;
int V_194 ;
int V_192 = F_214 ( V_193 ) ;
int V_195 ;
while ( ( V_194 = F_211 ( V_162 , V_192 ) ) != 0 ) {
V_195 = F_212 ( V_15 , V_151 , V_161 , V_192 , V_194 ) ;
if ( V_195 < 0 )
return V_195 ;
V_192 = 0 ;
V_162 -= V_194 ;
V_161 += V_194 ;
++ V_151 ;
}
return 0 ;
}
int F_215 ( struct V_15 * V_15 , T_6 V_193 , void * V_161 ,
unsigned long V_162 )
{
int V_34 ;
unsigned long V_88 ;
T_5 V_151 = V_193 >> V_133 ;
int V_192 = F_214 ( V_193 ) ;
V_88 = F_169 ( V_15 , V_151 , NULL ) ;
if ( F_158 ( V_88 ) )
return - V_149 ;
F_216 () ;
V_34 = F_172 ( V_161 , ( void V_132 * ) V_88 + V_192 , V_162 ) ;
F_217 () ;
if ( V_34 )
return - V_149 ;
return 0 ;
}
int F_218 ( struct V_15 * V_15 , T_5 V_151 , const void * V_161 ,
int V_192 , int V_162 )
{
int V_34 ;
unsigned long V_88 ;
V_88 = F_157 ( V_15 , V_151 ) ;
if ( F_158 ( V_88 ) )
return - V_149 ;
V_34 = F_219 ( ( void V_132 * ) V_88 + V_192 , V_161 , V_162 ) ;
if ( V_34 )
return - V_149 ;
F_220 ( V_15 , V_151 ) ;
return 0 ;
}
int F_221 ( struct V_15 * V_15 , T_6 V_193 , const void * V_161 ,
unsigned long V_162 )
{
T_5 V_151 = V_193 >> V_133 ;
int V_194 ;
int V_192 = F_214 ( V_193 ) ;
int V_195 ;
while ( ( V_194 = F_211 ( V_162 , V_192 ) ) != 0 ) {
V_195 = F_218 ( V_15 , V_151 , V_161 , V_192 , V_194 ) ;
if ( V_195 < 0 )
return V_195 ;
V_192 = 0 ;
V_162 -= V_194 ;
V_161 += V_194 ;
++ V_151 ;
}
return 0 ;
}
int F_222 ( struct V_15 * V_15 , struct V_196 * V_197 ,
T_6 V_193 , unsigned long V_162 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_192 = F_214 ( V_193 ) ;
T_5 V_198 = V_193 >> V_133 ;
T_5 V_199 = ( V_193 + V_162 - 1 ) >> V_133 ;
T_5 V_200 = V_199 - V_198 + 1 ;
T_5 V_201 ;
V_197 -> V_193 = V_193 ;
V_197 -> V_71 = V_62 -> V_71 ;
V_197 -> V_162 = V_162 ;
V_197 -> V_90 = F_153 ( V_15 , V_198 ) ;
V_197 -> V_160 = F_166 ( V_197 -> V_90 , V_198 , & V_201 ) ;
if ( ! F_158 ( V_197 -> V_160 ) && V_201 >= V_200 ) {
V_197 -> V_160 += V_192 ;
} else {
while ( V_198 <= V_199 ) {
V_197 -> V_90 = F_153 ( V_15 , V_198 ) ;
V_197 -> V_160 = F_166 ( V_197 -> V_90 , V_198 ,
& V_201 ) ;
if ( F_158 ( V_197 -> V_160 ) )
return - V_149 ;
V_198 += V_201 ;
}
V_197 -> V_90 = NULL ;
}
return 0 ;
}
int F_223 ( struct V_15 * V_15 , struct V_196 * V_197 ,
void * V_161 , unsigned long V_162 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_65 ( V_162 > V_197 -> V_162 ) ;
if ( V_62 -> V_71 != V_197 -> V_71 )
F_222 ( V_15 , V_197 , V_197 -> V_193 , V_197 -> V_162 ) ;
if ( F_7 ( ! V_197 -> V_90 ) )
return F_221 ( V_15 , V_197 -> V_193 , V_161 , V_162 ) ;
if ( F_158 ( V_197 -> V_160 ) )
return - V_149 ;
V_34 = F_219 ( ( void V_132 * ) V_197 -> V_160 , V_161 , V_162 ) ;
if ( V_34 )
return - V_149 ;
F_224 ( V_15 , V_197 -> V_90 , V_197 -> V_193 >> V_133 ) ;
return 0 ;
}
int F_225 ( struct V_15 * V_15 , struct V_196 * V_197 ,
void * V_161 , unsigned long V_162 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_65 ( V_162 > V_197 -> V_162 ) ;
if ( V_62 -> V_71 != V_197 -> V_71 )
F_222 ( V_15 , V_197 , V_197 -> V_193 , V_197 -> V_162 ) ;
if ( F_7 ( ! V_197 -> V_90 ) )
return F_213 ( V_15 , V_197 -> V_193 , V_161 , V_162 ) ;
if ( F_158 ( V_197 -> V_160 ) )
return - V_149 ;
V_34 = F_171 ( V_161 , ( void V_132 * ) V_197 -> V_160 , V_162 ) ;
if ( V_34 )
return - V_149 ;
return 0 ;
}
int F_226 ( struct V_15 * V_15 , T_5 V_151 , int V_192 , int V_162 )
{
const void * V_202 = ( const void * ) F_227 ( F_228 ( F_229 ( 0 ) ) ) ;
return F_218 ( V_15 , V_151 , V_202 , V_192 , V_162 ) ;
}
int F_230 ( struct V_15 * V_15 , T_6 V_193 , unsigned long V_162 )
{
T_5 V_151 = V_193 >> V_133 ;
int V_194 ;
int V_192 = F_214 ( V_193 ) ;
int V_195 ;
while ( ( V_194 = F_211 ( V_162 , V_192 ) ) != 0 ) {
V_195 = F_226 ( V_15 , V_151 , V_192 , V_194 ) ;
if ( V_195 < 0 )
return V_195 ;
V_192 = 0 ;
V_162 -= V_194 ;
++ V_151 ;
}
return 0 ;
}
static void F_224 ( struct V_15 * V_15 ,
struct V_89 * V_90 ,
T_5 V_151 )
{
if ( V_90 && V_90 -> V_91 ) {
unsigned long V_203 = V_151 - V_90 -> V_122 ;
F_231 ( V_203 , V_90 -> V_91 ) ;
}
}
void F_220 ( struct V_15 * V_15 , T_5 V_151 )
{
struct V_89 * V_90 ;
V_90 = F_153 ( V_15 , V_151 ) ;
F_224 ( V_15 , V_90 , V_151 ) ;
}
void F_232 ( struct V_2 * V_3 )
{
F_233 ( V_204 ) ;
for (; ; ) {
F_234 ( & V_3 -> V_36 , & V_204 , V_205 ) ;
if ( F_235 ( V_3 ) ) {
F_26 ( V_206 , V_3 ) ;
break;
}
if ( F_236 ( V_3 ) )
break;
if ( F_237 ( V_8 ) )
break;
F_238 () ;
}
F_239 ( & V_3 -> V_36 , & V_204 ) ;
}
void F_240 ( struct V_2 * V_3 )
{
int V_18 ;
int V_4 = V_3 -> V_4 ;
T_7 * V_207 ;
V_207 = F_241 ( V_3 ) ;
if ( F_242 ( V_207 ) ) {
F_243 ( V_207 ) ;
++ V_3 -> V_27 . V_208 ;
}
V_18 = F_12 () ;
if ( V_4 != V_18 && ( unsigned ) V_4 < V_209 && F_244 ( V_4 ) )
if ( F_245 ( V_3 ) )
F_246 ( V_4 ) ;
F_15 () ;
}
int F_247 ( struct V_2 * V_210 )
{
struct V_7 * V_7 ;
struct V_163 * V_211 = NULL ;
int V_195 = 0 ;
F_248 () ;
V_7 = F_249 ( V_210 -> V_7 ) ;
if ( V_7 )
V_211 = F_250 ( V_7 , V_10 ) ;
F_251 () ;
if ( ! V_211 )
return V_195 ;
if ( V_211 -> V_119 & V_212 ) {
F_252 ( V_211 ) ;
return V_195 ;
}
V_195 = F_253 ( V_211 , 1 ) ;
F_252 ( V_211 ) ;
return V_195 ;
}
static bool F_254 ( struct V_2 * V_3 )
{
#ifdef F_255
bool V_213 ;
V_213 = ! V_3 -> V_214 . V_215 ||
V_3 -> V_214 . V_216 ;
if ( V_3 -> V_214 . V_215 )
F_45 ( V_3 , ! V_3 -> V_214 . V_216 ) ;
return V_213 ;
#else
return true ;
#endif
}
void F_256 ( struct V_2 * V_18 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_2 * V_3 ;
int V_217 = V_18 -> V_15 -> V_217 ;
int V_218 = 0 ;
int V_219 = 3 ;
int V_220 ;
int V_17 ;
F_44 ( V_18 , true ) ;
for ( V_220 = 0 ; V_220 < 2 && ! V_218 && V_219 ; V_220 ++ ) {
F_25 (i, vcpu, kvm) {
if ( ! V_220 && V_17 <= V_217 ) {
V_17 = V_217 ;
continue;
} else if ( V_220 && V_17 > V_217 )
break;
if ( ! F_257 ( V_3 -> V_42 ) )
continue;
if ( V_3 == V_18 )
continue;
if ( F_242 ( & V_3 -> V_36 ) && ! F_235 ( V_3 ) )
continue;
if ( ! F_254 ( V_3 ) )
continue;
V_218 = F_247 ( V_3 ) ;
if ( V_218 > 0 ) {
V_15 -> V_217 = V_17 ;
break;
} else if ( V_218 < 0 ) {
V_219 -- ;
if ( ! V_219 )
break;
}
}
}
F_44 ( V_18 , false ) ;
F_45 ( V_18 , false ) ;
}
static int F_258 ( struct V_152 * V_153 , struct V_221 * V_222 )
{
struct V_2 * V_3 = V_153 -> V_223 -> V_106 ;
struct V_33 * V_33 ;
if ( V_222 -> V_224 == 0 )
V_33 = F_259 ( V_3 -> V_41 ) ;
#ifdef F_260
else if ( V_222 -> V_224 == V_225 )
V_33 = F_259 ( V_3 -> V_143 . V_226 ) ;
#endif
#ifdef F_261
else if ( V_222 -> V_224 == F_261 )
V_33 = F_259 ( V_3 -> V_15 -> V_227 ) ;
#endif
else
return F_262 ( V_3 , V_222 ) ;
F_210 ( V_33 ) ;
V_222 -> V_33 = V_33 ;
return 0 ;
}
static int F_263 ( struct V_104 * V_104 , struct V_152 * V_153 )
{
V_153 -> V_228 = & V_229 ;
return 0 ;
}
static int F_264 ( struct V_103 * V_103 , struct V_104 * V_105 )
{
struct V_2 * V_3 = V_105 -> V_106 ;
F_120 ( V_3 -> V_15 ) ;
return 0 ;
}
static int F_265 ( struct V_2 * V_3 )
{
return F_266 ( L_1 , & V_230 , V_3 , V_231 | V_232 ) ;
}
static int F_267 ( struct V_15 * V_15 , T_4 V_32 )
{
int V_34 ;
struct V_2 * V_3 , * V_233 ;
if ( V_32 >= V_234 )
return - V_120 ;
V_3 = F_268 ( V_15 , V_32 ) ;
if ( F_269 ( V_3 ) )
return F_270 ( V_3 ) ;
F_271 ( & V_3 -> V_13 , & V_235 ) ;
V_34 = F_272 ( V_3 ) ;
if ( V_34 )
goto V_236;
F_147 ( & V_15 -> V_79 ) ;
if ( ! F_273 ( V_3 ) ) {
V_34 = - V_120 ;
goto V_237;
}
if ( F_274 ( & V_15 -> V_238 ) == V_234 ) {
V_34 = - V_120 ;
goto V_237;
}
F_25 (r, v, kvm)
if ( V_233 -> V_35 == V_32 ) {
V_34 = - V_139 ;
goto V_237;
}
F_65 ( V_15 -> V_239 [ F_274 ( & V_15 -> V_238 ) ] ) ;
F_119 ( V_15 ) ;
V_34 = F_265 ( V_3 ) ;
if ( V_34 < 0 ) {
F_120 ( V_15 ) ;
goto V_237;
}
V_15 -> V_239 [ F_274 ( & V_15 -> V_238 ) ] = V_3 ;
F_64 () ;
F_87 ( & V_15 -> V_238 ) ;
F_21 ( & V_15 -> V_79 ) ;
F_275 ( V_3 ) ;
return V_34 ;
V_237:
F_21 ( & V_15 -> V_79 ) ;
V_236:
F_276 ( V_3 ) ;
return V_34 ;
}
static int F_277 ( struct V_2 * V_3 , T_8 * V_240 )
{
if ( V_240 ) {
F_278 ( V_240 , F_279 ( V_241 ) | F_279 ( V_242 ) ) ;
V_3 -> V_243 = 1 ;
V_3 -> V_240 = * V_240 ;
} else
V_3 -> V_243 = 0 ;
return 0 ;
}
static long F_280 ( struct V_104 * V_105 ,
unsigned int V_244 , unsigned long V_245 )
{
struct V_2 * V_3 = V_105 -> V_106 ;
void V_132 * V_246 = ( void V_132 * ) V_245 ;
int V_34 ;
struct V_247 * V_248 = NULL ;
struct V_249 * V_249 = NULL ;
if ( V_3 -> V_15 -> V_47 != V_8 -> V_47 )
return - V_250 ;
if ( F_7 ( F_281 ( V_244 ) != V_251 ) )
return - V_120 ;
#if F_115 ( V_252 ) || F_115 ( V_253 ) || F_115 ( V_254 )
if ( V_244 == V_255 || V_244 == V_256 )
return F_282 ( V_105 , V_244 , V_245 ) ;
#endif
V_34 = F_5 ( V_3 ) ;
if ( V_34 )
return V_34 ;
switch ( V_244 ) {
case V_257 :
V_34 = - V_120 ;
if ( V_245 )
goto V_126;
V_34 = F_283 ( V_3 , V_3 -> V_41 ) ;
F_284 ( V_3 -> V_41 -> V_258 , V_34 ) ;
break;
case V_259 : {
struct V_260 * V_260 ;
V_34 = - V_39 ;
V_260 = F_84 ( sizeof( struct V_260 ) , V_37 ) ;
if ( ! V_260 )
goto V_126;
V_34 = F_285 ( V_3 , V_260 ) ;
if ( V_34 )
goto V_261;
V_34 = - V_149 ;
if ( F_150 ( V_246 , V_260 , sizeof( struct V_260 ) ) )
goto V_261;
V_34 = 0 ;
V_261:
F_94 ( V_260 ) ;
break;
}
case V_262 : {
struct V_260 * V_260 ;
V_34 = - V_39 ;
V_260 = F_286 ( V_246 , sizeof( * V_260 ) ) ;
if ( F_269 ( V_260 ) ) {
V_34 = F_270 ( V_260 ) ;
goto V_126;
}
V_34 = F_287 ( V_3 , V_260 ) ;
F_94 ( V_260 ) ;
break;
}
case V_263 : {
V_249 = F_84 ( sizeof( struct V_249 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_249 )
goto V_126;
V_34 = F_288 ( V_3 , V_249 ) ;
if ( V_34 )
goto V_126;
V_34 = - V_149 ;
if ( F_150 ( V_246 , V_249 , sizeof( struct V_249 ) ) )
goto V_126;
V_34 = 0 ;
break;
}
case V_264 : {
V_249 = F_286 ( V_246 , sizeof( * V_249 ) ) ;
if ( F_269 ( V_249 ) ) {
V_34 = F_270 ( V_249 ) ;
V_249 = NULL ;
goto V_126;
}
V_34 = F_289 ( V_3 , V_249 ) ;
break;
}
case V_265 : {
struct V_266 V_267 ;
V_34 = F_290 ( V_3 , & V_267 ) ;
if ( V_34 )
goto V_126;
V_34 = - V_149 ;
if ( F_150 ( V_246 , & V_267 , sizeof V_267 ) )
goto V_126;
V_34 = 0 ;
break;
}
case V_268 : {
struct V_266 V_267 ;
V_34 = - V_149 ;
if ( F_291 ( & V_267 , V_246 , sizeof V_267 ) )
goto V_126;
V_34 = F_292 ( V_3 , & V_267 ) ;
break;
}
case V_269 : {
struct V_270 V_271 ;
V_34 = - V_149 ;
if ( F_291 ( & V_271 , V_246 , sizeof V_271 ) )
goto V_126;
V_34 = F_293 ( V_3 , & V_271 ) ;
if ( V_34 )
goto V_126;
V_34 = - V_149 ;
if ( F_150 ( V_246 , & V_271 , sizeof V_271 ) )
goto V_126;
V_34 = 0 ;
break;
}
case V_272 : {
struct V_273 V_274 ;
V_34 = - V_149 ;
if ( F_291 ( & V_274 , V_246 , sizeof V_274 ) )
goto V_126;
V_34 = F_294 ( V_3 , & V_274 ) ;
break;
}
case V_275 : {
struct V_276 V_132 * V_277 = V_246 ;
struct V_276 V_278 ;
T_8 V_240 , * V_279 ;
V_279 = NULL ;
if ( V_246 ) {
V_34 = - V_149 ;
if ( F_291 ( & V_278 , V_246 ,
sizeof V_278 ) )
goto V_126;
V_34 = - V_120 ;
if ( V_278 . V_162 != sizeof V_240 )
goto V_126;
V_34 = - V_149 ;
if ( F_291 ( & V_240 , V_277 -> V_240 ,
sizeof V_240 ) )
goto V_126;
V_279 = & V_240 ;
}
V_34 = F_277 ( V_3 , V_279 ) ;
break;
}
case V_280 : {
V_248 = F_84 ( sizeof( struct V_247 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_248 )
goto V_126;
V_34 = F_295 ( V_3 , V_248 ) ;
if ( V_34 )
goto V_126;
V_34 = - V_149 ;
if ( F_150 ( V_246 , V_248 , sizeof( struct V_247 ) ) )
goto V_126;
V_34 = 0 ;
break;
}
case V_281 : {
V_248 = F_286 ( V_246 , sizeof( * V_248 ) ) ;
if ( F_269 ( V_248 ) ) {
V_34 = F_270 ( V_248 ) ;
V_248 = NULL ;
goto V_126;
}
V_34 = F_296 ( V_3 , V_248 ) ;
break;
}
default:
V_34 = F_282 ( V_105 , V_244 , V_245 ) ;
}
V_126:
F_16 ( V_3 ) ;
F_94 ( V_248 ) ;
F_94 ( V_249 ) ;
return V_34 ;
}
static long F_297 ( struct V_104 * V_105 ,
unsigned int V_244 , unsigned long V_245 )
{
struct V_2 * V_3 = V_105 -> V_106 ;
void V_132 * V_246 = F_298 ( V_245 ) ;
int V_34 ;
if ( V_3 -> V_15 -> V_47 != V_8 -> V_47 )
return - V_250 ;
switch ( V_244 ) {
case V_275 : {
struct V_276 V_132 * V_277 = V_246 ;
struct V_276 V_278 ;
T_9 V_282 ;
T_8 V_240 ;
if ( V_246 ) {
V_34 = - V_149 ;
if ( F_291 ( & V_278 , V_246 ,
sizeof V_278 ) )
goto V_126;
V_34 = - V_120 ;
if ( V_278 . V_162 != sizeof V_282 )
goto V_126;
V_34 = - V_149 ;
if ( F_291 ( & V_282 , V_277 -> V_240 ,
sizeof V_282 ) )
goto V_126;
F_299 ( & V_240 , & V_282 ) ;
V_34 = F_277 ( V_3 , & V_240 ) ;
} else
V_34 = F_277 ( V_3 , NULL ) ;
break;
}
default:
V_34 = F_280 ( V_105 , V_244 , V_245 ) ;
}
V_126:
return V_34 ;
}
static int F_300 ( struct V_97 * V_98 ,
int (* F_301)( struct V_97 * V_98 ,
struct V_283 * V_284 ) ,
unsigned long V_245 )
{
struct V_283 V_284 ;
if ( ! F_301 )
return - V_285 ;
if ( F_291 ( & V_284 , ( void V_132 * ) V_245 , sizeof( V_284 ) ) )
return - V_149 ;
return F_301 ( V_98 , & V_284 ) ;
}
static long F_302 ( struct V_104 * V_105 , unsigned int V_244 ,
unsigned long V_245 )
{
struct V_97 * V_98 = V_105 -> V_106 ;
switch ( V_244 ) {
case V_286 :
return F_300 ( V_98 , V_98 -> V_59 -> V_287 , V_245 ) ;
case V_288 :
return F_300 ( V_98 , V_98 -> V_59 -> V_289 , V_245 ) ;
case V_290 :
return F_300 ( V_98 , V_98 -> V_59 -> V_291 , V_245 ) ;
default:
if ( V_98 -> V_59 -> V_244 )
return V_98 -> V_59 -> V_244 ( V_98 , V_244 , V_245 ) ;
return - V_292 ;
}
}
static int F_303 ( struct V_103 * V_103 , struct V_104 * V_105 )
{
struct V_97 * V_98 = V_105 -> V_106 ;
struct V_15 * V_15 = V_98 -> V_15 ;
F_120 ( V_15 ) ;
return 0 ;
}
struct V_97 * F_304 ( struct V_104 * V_105 )
{
if ( V_105 -> V_293 != & V_294 )
return NULL ;
return V_105 -> V_106 ;
}
int F_305 ( struct V_295 * V_59 , T_4 type )
{
if ( type >= F_306 ( V_296 ) )
return - V_297 ;
if ( V_296 [ type ] != NULL )
return - V_139 ;
V_296 [ type ] = V_59 ;
return 0 ;
}
void F_307 ( T_4 type )
{
if ( V_296 [ type ] != NULL )
V_296 [ type ] = NULL ;
}
static int F_308 ( struct V_15 * V_15 ,
struct V_298 * V_299 )
{
struct V_295 * V_59 = NULL ;
struct V_97 * V_98 ;
bool V_300 = V_299 -> V_119 & V_301 ;
int V_195 ;
if ( V_299 -> type >= F_306 ( V_296 ) )
return - V_302 ;
V_59 = V_296 [ V_299 -> type ] ;
if ( V_59 == NULL )
return - V_302 ;
if ( V_300 )
return 0 ;
V_98 = F_84 ( sizeof( * V_98 ) , V_37 ) ;
if ( ! V_98 )
return - V_39 ;
V_98 -> V_59 = V_59 ;
V_98 -> V_15 = V_15 ;
V_195 = V_59 -> V_303 ( V_98 , V_299 -> type ) ;
if ( V_195 < 0 ) {
F_94 ( V_98 ) ;
return V_195 ;
}
V_195 = F_266 ( V_59 -> V_304 , & V_294 , V_98 , V_231 | V_232 ) ;
if ( V_195 < 0 ) {
V_59 -> V_100 ( V_98 ) ;
return V_195 ;
}
F_91 ( & V_98 -> V_99 , & V_15 -> V_83 ) ;
F_119 ( V_15 ) ;
V_299 -> V_305 = V_195 ;
return 0 ;
}
static long F_309 ( struct V_15 * V_15 , long V_245 )
{
switch ( V_245 ) {
case V_306 :
case V_307 :
case V_308 :
#ifdef F_310
case V_309 :
#endif
case V_310 :
#ifdef F_311
case V_311 :
#endif
#ifdef F_82
case V_312 :
#endif
case V_313 :
return 1 ;
#ifdef F_312
case V_314 :
return V_315 ;
#endif
default:
break;
}
return F_313 ( V_15 , V_245 ) ;
}
static long F_314 ( struct V_104 * V_105 ,
unsigned int V_244 , unsigned long V_245 )
{
struct V_15 * V_15 = V_105 -> V_106 ;
void V_132 * V_246 = ( void V_132 * ) V_245 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_250 ;
switch ( V_244 ) {
case V_316 :
V_34 = F_267 ( V_15 , V_245 ) ;
break;
case V_317 : {
struct V_114 V_318 ;
V_34 = - V_149 ;
if ( F_291 ( & V_318 , V_246 ,
sizeof V_318 ) )
goto V_126;
V_34 = F_148 ( V_15 , & V_318 ) ;
break;
}
case V_319 : {
struct V_144 log ;
V_34 = - V_149 ;
if ( F_291 ( & log , V_246 , sizeof log ) )
goto V_126;
V_34 = F_315 ( V_15 , & log ) ;
break;
}
#ifdef F_261
case V_320 : {
struct V_321 V_322 ;
V_34 = - V_149 ;
if ( F_291 ( & V_322 , V_246 , sizeof V_322 ) )
goto V_126;
V_34 = F_316 ( V_15 , & V_322 ) ;
break;
}
case V_323 : {
struct V_321 V_322 ;
V_34 = - V_149 ;
if ( F_291 ( & V_322 , V_246 , sizeof V_322 ) )
goto V_126;
V_34 = F_317 ( V_15 , & V_322 ) ;
break;
}
#endif
case V_324 : {
struct V_325 V_161 ;
V_34 = - V_149 ;
if ( F_291 ( & V_161 , V_246 , sizeof V_161 ) )
goto V_126;
V_34 = V_325 ( V_15 , & V_161 ) ;
break;
}
case V_326 : {
struct V_327 V_161 ;
V_34 = - V_149 ;
if ( F_291 ( & V_161 , V_246 , sizeof V_161 ) )
goto V_126;
V_34 = V_327 ( V_15 , & V_161 ) ;
break;
}
#ifdef F_310
case V_328 :
V_34 = 0 ;
F_147 ( & V_15 -> V_79 ) ;
if ( F_274 ( & V_15 -> V_238 ) != 0 )
V_34 = - V_329 ;
else
V_15 -> V_330 = V_245 ;
F_21 ( & V_15 -> V_79 ) ;
break;
#endif
#ifdef F_311
case V_331 : {
struct V_332 V_333 ;
V_34 = - V_149 ;
if ( F_291 ( & V_333 , V_246 , sizeof V_333 ) )
goto V_126;
V_34 = F_318 ( V_15 , & V_333 ) ;
break;
}
#endif
#ifdef F_319
case V_334 :
case V_335 : {
struct V_336 V_337 ;
V_34 = - V_149 ;
if ( F_291 ( & V_337 , V_246 , sizeof V_337 ) )
goto V_126;
V_34 = F_320 ( V_15 , & V_337 ,
V_244 == V_334 ) ;
if ( V_34 )
goto V_126;
V_34 = - V_149 ;
if ( V_244 == V_334 ) {
if ( F_150 ( V_246 , & V_337 , sizeof V_337 ) )
goto V_126;
}
V_34 = 0 ;
break;
}
#endif
#ifdef F_312
case V_338 : {
struct V_339 V_340 ;
struct V_339 V_132 * V_341 ;
struct V_342 * V_343 ;
V_34 = - V_149 ;
if ( F_291 ( & V_340 , V_246 , sizeof( V_340 ) ) )
goto V_126;
V_34 = - V_120 ;
if ( V_340 . V_344 >= V_315 )
goto V_126;
if ( V_340 . V_119 )
goto V_126;
V_34 = - V_39 ;
V_343 = F_321 ( V_340 . V_344 * sizeof( * V_343 ) ) ;
if ( ! V_343 )
goto V_126;
V_34 = - V_149 ;
V_341 = V_246 ;
if ( F_291 ( V_343 , V_341 -> V_343 ,
V_340 . V_344 * sizeof( * V_343 ) ) )
goto V_345;
V_34 = F_322 ( V_15 , V_343 , V_340 . V_344 ,
V_340 . V_119 ) ;
V_345:
F_100 ( V_343 ) ;
break;
}
#endif
case V_346 : {
struct V_298 V_299 ;
V_34 = - V_149 ;
if ( F_291 ( & V_299 , V_246 , sizeof( V_299 ) ) )
goto V_126;
V_34 = F_308 ( V_15 , & V_299 ) ;
if ( V_34 )
goto V_126;
V_34 = - V_149 ;
if ( F_150 ( V_246 , & V_299 , sizeof( V_299 ) ) )
goto V_126;
V_34 = 0 ;
break;
}
case V_347 :
V_34 = F_309 ( V_15 , V_245 ) ;
break;
default:
V_34 = F_323 ( V_105 , V_244 , V_245 ) ;
if ( V_34 == - V_292 )
V_34 = F_324 ( V_15 , V_244 , V_245 ) ;
}
V_126:
return V_34 ;
}
static long F_325 ( struct V_104 * V_105 ,
unsigned int V_244 , unsigned long V_245 )
{
struct V_15 * V_15 = V_105 -> V_106 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_250 ;
switch ( V_244 ) {
case V_319 : {
struct V_348 V_349 ;
struct V_144 log ;
V_34 = - V_149 ;
if ( F_291 ( & V_349 , ( void V_132 * ) V_245 ,
sizeof( V_349 ) ) )
goto V_126;
log . V_123 = V_349 . V_123 ;
log . V_350 = V_349 . V_350 ;
log . V_351 = V_349 . V_351 ;
log . V_91 = F_298 ( V_349 . V_91 ) ;
V_34 = F_315 ( V_15 , & log ) ;
break;
}
default:
V_34 = F_314 ( V_105 , V_244 , V_245 ) ;
}
V_126:
return V_34 ;
}
static int F_326 ( unsigned long type )
{
int V_34 ;
struct V_15 * V_15 ;
V_15 = F_75 ( type ) ;
if ( F_269 ( V_15 ) )
return F_270 ( V_15 ) ;
#ifdef F_261
V_34 = F_327 ( V_15 ) ;
if ( V_34 < 0 ) {
F_120 ( V_15 ) ;
return V_34 ;
}
#endif
V_34 = F_266 ( L_2 , & V_352 , V_15 , V_231 | V_232 ) ;
if ( V_34 < 0 )
F_120 ( V_15 ) ;
return V_34 ;
}
static long F_328 ( struct V_104 * V_105 ,
unsigned int V_244 , unsigned long V_245 )
{
long V_34 = - V_120 ;
switch ( V_244 ) {
case V_353 :
if ( V_245 )
goto V_126;
V_34 = V_354 ;
break;
case V_355 :
V_34 = F_326 ( V_245 ) ;
break;
case V_347 :
V_34 = F_309 ( NULL , V_245 ) ;
break;
case V_356 :
if ( V_245 )
goto V_126;
V_34 = V_87 ;
#ifdef F_260
V_34 += V_87 ;
#endif
#ifdef F_261
V_34 += V_87 ;
#endif
break;
case V_357 :
case V_358 :
case V_359 :
V_34 = - V_360 ;
break;
default:
return F_329 ( V_105 , V_244 , V_245 ) ;
}
V_126:
return V_34 ;
}
static void F_330 ( void * V_361 )
{
int V_4 = F_331 () ;
int V_34 ;
if ( F_332 ( V_4 , V_362 ) )
return;
F_29 ( V_4 , V_362 ) ;
V_34 = F_333 () ;
if ( V_34 ) {
F_334 ( V_4 , V_362 ) ;
F_87 ( & V_363 ) ;
F_335 ( V_364 L_3
L_4 , V_4 ) ;
}
}
static void F_336 ( void )
{
F_337 ( & V_365 ) ;
if ( V_366 )
F_330 ( NULL ) ;
F_338 ( & V_365 ) ;
}
static void F_339 ( void * V_361 )
{
int V_4 = F_331 () ;
if ( ! F_332 ( V_4 , V_362 ) )
return;
F_334 ( V_4 , V_362 ) ;
F_340 () ;
}
static void F_341 ( void )
{
F_337 ( & V_365 ) ;
if ( V_366 )
F_339 ( NULL ) ;
F_338 ( & V_365 ) ;
}
static void F_342 ( void )
{
F_65 ( ! V_366 ) ;
V_366 -- ;
if ( ! V_366 )
F_343 ( F_339 , NULL , 1 ) ;
}
static void F_93 ( void )
{
F_337 ( & V_365 ) ;
F_342 () ;
F_338 ( & V_365 ) ;
}
static int F_79 ( void )
{
int V_34 = 0 ;
F_337 ( & V_365 ) ;
V_366 ++ ;
if ( V_366 == 1 ) {
F_89 ( & V_363 , 0 ) ;
F_343 ( F_330 , NULL , 1 ) ;
if ( F_274 ( & V_363 ) ) {
F_342 () ;
V_34 = - V_329 ;
}
}
F_338 ( & V_365 ) ;
return V_34 ;
}
static int F_344 ( struct V_367 * V_368 , unsigned long V_369 ,
void * V_233 )
{
int V_4 = ( long ) V_233 ;
V_369 &= ~ V_370 ;
switch ( V_369 ) {
case V_371 :
F_335 ( V_364 L_5 ,
V_4 ) ;
F_341 () ;
break;
case V_372 :
F_335 ( V_364 L_6 ,
V_4 ) ;
F_336 () ;
break;
}
return V_373 ;
}
static int F_345 ( struct V_367 * V_368 , unsigned long V_369 ,
void * V_233 )
{
F_335 ( V_364 L_7 ) ;
V_374 = true ;
F_343 ( F_339 , NULL , 1 ) ;
return V_373 ;
}
static void F_113 ( struct V_76 * V_375 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_375 -> V_376 ; V_17 ++ ) {
struct V_377 * V_378 = V_375 -> V_379 [ V_17 ] . V_98 ;
F_346 ( V_378 ) ;
}
F_94 ( V_375 ) ;
}
static inline int F_347 ( const struct V_380 * V_381 ,
const struct V_380 * V_382 )
{
if ( V_381 -> V_88 < V_382 -> V_88 )
return - 1 ;
if ( V_381 -> V_88 + V_381 -> V_162 > V_382 -> V_88 + V_382 -> V_162 )
return 1 ;
return 0 ;
}
static int F_348 ( const void * V_383 , const void * V_384 )
{
return F_347 ( V_383 , V_384 ) ;
}
static int F_349 ( struct V_76 * V_375 , struct V_377 * V_98 ,
T_6 V_88 , int V_162 )
{
V_375 -> V_379 [ V_375 -> V_376 ++ ] = (struct V_380 ) {
. V_88 = V_88 ,
. V_162 = V_162 ,
. V_98 = V_98 ,
} ;
F_128 ( V_375 -> V_379 , V_375 -> V_376 , sizeof( struct V_380 ) ,
F_348 , NULL ) ;
return 0 ;
}
static int F_350 ( struct V_76 * V_375 ,
T_6 V_88 , int V_162 )
{
struct V_380 * V_379 , V_385 ;
int V_386 ;
V_385 = (struct V_380 ) {
. V_88 = V_88 ,
. V_162 = V_162 ,
} ;
V_379 = bsearch ( & V_385 , V_375 -> V_379 , V_375 -> V_376 ,
sizeof( struct V_380 ) , F_348 ) ;
if ( V_379 == NULL )
return - V_148 ;
V_386 = V_379 - V_375 -> V_379 ;
while ( V_386 > 0 && F_347 ( & V_385 , & V_375 -> V_379 [ V_386 - 1 ] ) == 0 )
V_386 -- ;
return V_386 ;
}
static int F_351 ( struct V_76 * V_375 ,
struct V_380 * V_379 , const void * V_369 )
{
int V_50 ;
V_50 = F_350 ( V_375 , V_379 -> V_88 , V_379 -> V_162 ) ;
if ( V_50 < 0 )
return - V_360 ;
while ( V_50 < V_375 -> V_376 &&
F_347 ( V_379 , & V_375 -> V_379 [ V_50 ] ) == 0 ) {
if ( ! F_352 ( V_375 -> V_379 [ V_50 ] . V_98 , V_379 -> V_88 ,
V_379 -> V_162 , V_369 ) )
return V_50 ;
V_50 ++ ;
}
return - V_360 ;
}
int F_353 ( struct V_15 * V_15 , enum V_387 V_388 , T_6 V_88 ,
int V_162 , const void * V_369 )
{
struct V_76 * V_375 ;
struct V_380 V_379 ;
int V_34 ;
V_379 = (struct V_380 ) {
. V_88 = V_88 ,
. V_162 = V_162 ,
} ;
V_375 = F_354 ( V_15 -> V_75 [ V_388 ] , & V_15 -> V_51 ) ;
V_34 = F_351 ( V_375 , & V_379 , V_369 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_355 ( struct V_15 * V_15 , enum V_387 V_388 , T_6 V_88 ,
int V_162 , const void * V_369 , long V_389 )
{
struct V_76 * V_375 ;
struct V_380 V_379 ;
V_379 = (struct V_380 ) {
. V_88 = V_88 ,
. V_162 = V_162 ,
} ;
V_375 = F_354 ( V_15 -> V_75 [ V_388 ] , & V_15 -> V_51 ) ;
if ( ( V_389 >= 0 ) && ( V_389 < V_375 -> V_376 ) &&
( F_347 ( & V_379 , & V_375 -> V_379 [ V_389 ] ) == 0 ) )
if ( ! F_352 ( V_375 -> V_379 [ V_389 ] . V_98 , V_88 , V_162 ,
V_369 ) )
return V_389 ;
return F_351 ( V_375 , & V_379 , V_369 ) ;
}
static int F_356 ( struct V_76 * V_375 , struct V_380 * V_379 ,
void * V_369 )
{
int V_50 ;
V_50 = F_350 ( V_375 , V_379 -> V_88 , V_379 -> V_162 ) ;
if ( V_50 < 0 )
return - V_360 ;
while ( V_50 < V_375 -> V_376 &&
F_347 ( V_379 , & V_375 -> V_379 [ V_50 ] ) == 0 ) {
if ( ! F_357 ( V_375 -> V_379 [ V_50 ] . V_98 , V_379 -> V_88 ,
V_379 -> V_162 , V_369 ) )
return V_50 ;
V_50 ++ ;
}
return - V_360 ;
}
int F_358 ( struct V_15 * V_15 , enum V_387 V_388 , T_6 V_88 ,
int V_162 , void * V_369 )
{
struct V_76 * V_375 ;
struct V_380 V_379 ;
int V_34 ;
V_379 = (struct V_380 ) {
. V_88 = V_88 ,
. V_162 = V_162 ,
} ;
V_375 = F_354 ( V_15 -> V_75 [ V_388 ] , & V_15 -> V_51 ) ;
V_34 = F_356 ( V_375 , & V_379 , V_369 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_359 ( struct V_15 * V_15 , enum V_387 V_388 , T_6 V_88 ,
int V_162 , struct V_377 * V_98 )
{
struct V_76 * V_390 , * V_375 ;
V_375 = V_15 -> V_75 [ V_388 ] ;
if ( V_375 -> V_376 - V_375 -> V_391 > V_392 - 1 )
return - V_297 ;
V_390 = F_84 ( sizeof( * V_375 ) + ( ( V_375 -> V_376 + 1 ) *
sizeof( struct V_380 ) ) , V_37 ) ;
if ( ! V_390 )
return - V_39 ;
memcpy ( V_390 , V_375 , sizeof( * V_375 ) + ( V_375 -> V_376 *
sizeof( struct V_380 ) ) ) ;
F_349 ( V_390 , V_98 , V_88 , V_162 ) ;
F_9 ( V_15 -> V_75 [ V_388 ] , V_390 ) ;
F_135 ( & V_15 -> V_51 ) ;
F_94 ( V_375 ) ;
return 0 ;
}
int F_360 ( struct V_15 * V_15 , enum V_387 V_388 ,
struct V_377 * V_98 )
{
int V_17 , V_34 ;
struct V_76 * V_390 , * V_375 ;
V_375 = V_15 -> V_75 [ V_388 ] ;
V_34 = - V_148 ;
for ( V_17 = 0 ; V_17 < V_375 -> V_376 ; V_17 ++ )
if ( V_375 -> V_379 [ V_17 ] . V_98 == V_98 ) {
V_34 = 0 ;
break;
}
if ( V_34 )
return V_34 ;
V_390 = F_84 ( sizeof( * V_375 ) + ( ( V_375 -> V_376 - 1 ) *
sizeof( struct V_380 ) ) , V_37 ) ;
if ( ! V_390 )
return - V_39 ;
memcpy ( V_390 , V_375 , sizeof( * V_375 ) + V_17 * sizeof( struct V_380 ) ) ;
V_390 -> V_376 -- ;
memcpy ( V_390 -> V_379 + V_17 , V_375 -> V_379 + V_17 + 1 ,
( V_390 -> V_376 - V_17 ) * sizeof( struct V_380 ) ) ;
F_9 ( V_15 -> V_75 [ V_388 ] , V_390 ) ;
F_135 ( & V_15 -> V_51 ) ;
F_94 ( V_375 ) ;
return V_34 ;
}
static int F_361 ( void * V_393 , T_10 * V_369 )
{
unsigned V_192 = ( long ) V_393 ;
struct V_15 * V_15 ;
* V_369 = 0 ;
F_54 ( & V_84 ) ;
F_362 ( V_15 , & V_85 , V_85 )
* V_369 += * ( T_4 * ) ( ( void * ) V_15 + V_192 ) ;
F_56 ( & V_84 ) ;
return 0 ;
}
static int F_363 ( void * V_393 , T_10 * V_369 )
{
unsigned V_192 = ( long ) V_393 ;
struct V_15 * V_15 ;
struct V_2 * V_3 ;
int V_17 ;
* V_369 = 0 ;
F_54 ( & V_84 ) ;
F_362 (kvm, &vm_list, vm_list)
F_25 ( V_17 , V_3 , V_15 )
* V_369 += * ( T_4 * ) ( ( void * ) V_3 + V_192 ) ;
F_56 ( & V_84 ) ;
return 0 ;
}
static int F_364 ( void )
{
int V_34 = - V_139 ;
struct V_394 * V_279 ;
V_395 = F_365 ( L_8 , NULL ) ;
if ( V_395 == NULL )
goto V_126;
for ( V_279 = V_396 ; V_279 -> V_304 ; ++ V_279 ) {
V_279 -> V_397 = F_366 ( V_279 -> V_304 , 0444 , V_395 ,
( void * ) ( long ) V_279 -> V_192 ,
V_398 [ V_279 -> V_399 ] ) ;
if ( V_279 -> V_397 == NULL )
goto V_400;
}
return 0 ;
V_400:
F_367 ( V_395 ) ;
V_126:
return V_34 ;
}
static void F_368 ( void )
{
struct V_394 * V_279 ;
for ( V_279 = V_396 ; V_279 -> V_304 ; ++ V_279 )
F_369 ( V_279 -> V_397 ) ;
F_369 ( V_395 ) ;
}
static int F_370 ( void )
{
if ( V_366 )
F_339 ( NULL ) ;
return 0 ;
}
static void F_371 ( void )
{
if ( V_366 ) {
F_134 ( F_372 ( & V_365 ) ) ;
F_330 ( NULL ) ;
}
}
static inline
struct V_2 * F_373 ( struct V_13 * V_401 )
{
return F_51 ( V_401 , struct V_2 , V_13 ) ;
}
static void F_374 ( struct V_13 * V_401 , int V_4 )
{
struct V_2 * V_3 = F_373 ( V_401 ) ;
if ( V_3 -> V_42 )
V_3 -> V_42 = false ;
F_375 ( V_3 , V_4 ) ;
F_14 ( V_3 , V_4 ) ;
}
static void F_376 ( struct V_13 * V_401 ,
struct V_163 * V_402 )
{
struct V_2 * V_3 = F_373 ( V_401 ) ;
if ( V_8 -> V_403 == V_404 )
V_3 -> V_42 = true ;
F_18 ( V_3 ) ;
}
int F_377 ( void * V_405 , unsigned V_406 , unsigned V_407 ,
struct V_408 * V_408 )
{
int V_34 ;
int V_4 ;
V_34 = F_378 ( V_405 ) ;
if ( V_34 )
goto V_409;
V_34 = F_379 () ;
if ( V_34 )
goto V_410;
if ( ! F_24 ( & V_362 , V_37 ) ) {
V_34 = - V_39 ;
goto V_411;
}
V_34 = F_380 () ;
if ( V_34 < 0 )
goto V_412;
F_381 (cpu) {
F_382 ( V_4 ,
V_413 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_414;
}
V_34 = F_383 ( & V_415 ) ;
if ( V_34 )
goto V_416;
F_384 ( & V_417 ) ;
if ( ! V_407 )
V_407 = F_385 ( struct V_2 ) ;
V_418 = F_386 ( L_9 , V_406 , V_407 ,
0 , NULL ) ;
if ( ! V_418 ) {
V_34 = - V_39 ;
goto V_419;
}
V_34 = F_387 () ;
if ( V_34 )
goto V_140;
V_420 . V_421 = V_408 ;
V_352 . V_421 = V_408 ;
V_230 . V_421 = V_408 ;
V_34 = F_388 ( & V_422 ) ;
if ( V_34 ) {
F_335 ( V_423 L_10 ) ;
goto V_424;
}
F_389 ( & V_425 ) ;
V_235 . V_426 = F_374 ;
V_235 . V_427 = F_376 ;
V_34 = F_364 () ;
if ( V_34 ) {
F_335 ( V_423 L_11 ) ;
goto V_428;
}
V_34 = F_390 () ;
F_134 ( V_34 ) ;
return 0 ;
V_428:
F_391 ( & V_425 ) ;
F_392 ( & V_422 ) ;
V_424:
F_393 () ;
V_140:
F_394 ( V_418 ) ;
V_419:
F_395 ( & V_417 ) ;
F_396 ( & V_415 ) ;
V_416:
V_414:
F_397 () ;
V_412:
F_32 ( V_362 ) ;
V_411:
F_398 () ;
V_410:
F_399 () ;
V_409:
return V_34 ;
}
void F_400 ( void )
{
F_368 () ;
F_392 ( & V_422 ) ;
F_394 ( V_418 ) ;
F_393 () ;
F_391 ( & V_425 ) ;
F_395 ( & V_417 ) ;
F_396 ( & V_415 ) ;
F_343 ( F_339 , NULL , 1 ) ;
F_397 () ;
F_399 () ;
F_398 () ;
F_32 ( V_362 ) ;
F_401 () ;
}
