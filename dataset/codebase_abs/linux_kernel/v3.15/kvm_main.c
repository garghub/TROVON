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
static bool F_23 ( struct V_15 * V_15 , unsigned int V_16 )
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
if ( F_23 ( V_15 , V_24 ) )
++ V_15 -> V_25 . V_26 ;
V_15 -> V_27 = false ;
}
void F_34 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_28 ) ;
}
void F_35 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_29 ) ;
}
void F_36 ( struct V_15 * V_15 )
{
F_23 ( V_15 , V_30 ) ;
}
int F_37 ( struct V_2 * V_3 , struct V_15 * V_15 , unsigned V_31 )
{
struct V_32 * V_32 ;
int V_33 ;
F_38 ( & V_3 -> V_5 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_34 = V_31 ;
V_3 -> V_7 = NULL ;
F_39 ( & V_3 -> V_35 ) ;
F_40 ( V_3 ) ;
V_32 = F_41 ( V_36 | V_37 ) ;
if ( ! V_32 ) {
V_33 = - V_38 ;
goto V_39;
}
V_3 -> V_40 = F_42 ( V_32 ) ;
F_43 ( V_3 , false ) ;
F_44 ( V_3 , false ) ;
V_3 -> V_41 = false ;
V_33 = F_45 ( V_3 ) ;
if ( V_33 < 0 )
goto V_42;
return 0 ;
V_42:
F_46 ( ( unsigned long ) V_3 -> V_40 ) ;
V_39:
return V_33 ;
}
void F_47 ( struct V_2 * V_3 )
{
F_11 ( V_3 -> V_7 ) ;
F_48 ( V_3 ) ;
F_46 ( ( unsigned long ) V_3 -> V_40 ) ;
}
static inline struct V_15 * F_49 ( struct V_43 * V_44 )
{
return F_50 ( V_44 , struct V_15 , V_43 ) ;
}
static void F_51 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_15 * V_15 = F_49 ( V_44 ) ;
int V_48 , V_49 ;
V_49 = F_52 ( & V_15 -> V_50 ) ;
F_53 ( & V_15 -> V_51 ) ;
V_15 -> V_52 ++ ;
V_48 = F_54 ( V_15 , V_47 ) | V_15 -> V_27 ;
if ( V_48 )
F_33 ( V_15 ) ;
F_55 ( & V_15 -> V_51 ) ;
F_56 ( & V_15 -> V_50 , V_49 ) ;
}
static void F_57 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 ,
T_3 V_53 )
{
struct V_15 * V_15 = F_49 ( V_44 ) ;
int V_49 ;
V_49 = F_52 ( & V_15 -> V_50 ) ;
F_53 ( & V_15 -> V_51 ) ;
V_15 -> V_52 ++ ;
F_58 ( V_15 , V_47 , V_53 ) ;
F_55 ( & V_15 -> V_51 ) ;
F_56 ( & V_15 -> V_50 , V_49 ) ;
}
static void F_59 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_54 ,
unsigned long V_55 )
{
struct V_15 * V_15 = F_49 ( V_44 ) ;
int V_48 = 0 , V_49 ;
V_49 = F_52 ( & V_15 -> V_50 ) ;
F_53 ( & V_15 -> V_51 ) ;
V_15 -> V_56 ++ ;
V_48 = F_60 ( V_15 , V_54 , V_55 ) ;
V_48 |= V_15 -> V_27 ;
if ( V_48 )
F_33 ( V_15 ) ;
F_55 ( & V_15 -> V_51 ) ;
F_56 ( & V_15 -> V_50 , V_49 ) ;
}
static void F_61 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_54 ,
unsigned long V_55 )
{
struct V_15 * V_15 = F_49 ( V_44 ) ;
F_53 ( & V_15 -> V_51 ) ;
V_15 -> V_52 ++ ;
F_62 () ;
V_15 -> V_56 -- ;
F_55 ( & V_15 -> V_51 ) ;
F_63 ( V_15 -> V_56 < 0 ) ;
}
static int F_64 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_15 * V_15 = F_49 ( V_44 ) ;
int V_57 , V_49 ;
V_49 = F_52 ( & V_15 -> V_50 ) ;
F_53 ( & V_15 -> V_51 ) ;
V_57 = F_65 ( V_15 , V_47 ) ;
if ( V_57 )
F_33 ( V_15 ) ;
F_55 ( & V_15 -> V_51 ) ;
F_56 ( & V_15 -> V_50 , V_49 ) ;
return V_57 ;
}
static int F_66 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_15 * V_15 = F_49 ( V_44 ) ;
int V_57 , V_49 ;
V_49 = F_52 ( & V_15 -> V_50 ) ;
F_53 ( & V_15 -> V_51 ) ;
V_57 = F_67 ( V_15 , V_47 ) ;
F_55 ( & V_15 -> V_51 ) ;
F_56 ( & V_15 -> V_50 , V_49 ) ;
return V_57 ;
}
static void F_68 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_15 * V_15 = F_49 ( V_44 ) ;
int V_49 ;
V_49 = F_52 ( & V_15 -> V_50 ) ;
F_69 ( V_15 ) ;
F_56 ( & V_15 -> V_50 , V_49 ) ;
}
static int F_70 ( struct V_15 * V_15 )
{
V_15 -> V_43 . V_58 = & V_59 ;
return F_71 ( & V_15 -> V_43 , V_8 -> V_46 ) ;
}
static int F_70 ( struct V_15 * V_15 )
{
return 0 ;
}
static void F_72 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_60 * V_61 = V_15 -> V_62 ;
for ( V_17 = 0 ; V_17 < V_63 ; V_17 ++ )
V_61 -> V_64 [ V_17 ] = V_61 -> V_62 [ V_17 ] . V_31 = V_17 ;
}
static struct V_15 * F_73 ( unsigned long type )
{
int V_33 , V_17 ;
struct V_15 * V_15 = F_74 () ;
if ( ! V_15 )
return F_75 ( - V_38 ) ;
V_33 = F_76 ( V_15 , type ) ;
if ( V_33 )
goto V_65;
V_33 = F_77 () ;
if ( V_33 )
goto V_65;
#ifdef F_78
F_79 ( & V_15 -> V_66 ) ;
F_79 ( & V_15 -> V_67 ) ;
#endif
F_80 ( V_63 > V_68 ) ;
V_33 = - V_38 ;
V_15 -> V_62 = F_81 ( sizeof( struct V_60 ) , V_36 ) ;
if ( ! V_15 -> V_62 )
goto V_69;
F_72 ( V_15 ) ;
if ( F_82 ( & V_15 -> V_50 ) )
goto V_69;
for ( V_17 = 0 ; V_17 < V_70 ; V_17 ++ ) {
V_15 -> V_71 [ V_17 ] = F_81 ( sizeof( struct V_72 ) ,
V_36 ) ;
if ( ! V_15 -> V_71 [ V_17 ] )
goto V_73;
}
F_83 ( & V_15 -> V_51 ) ;
V_15 -> V_46 = V_8 -> V_46 ;
F_84 ( & V_15 -> V_46 -> V_74 ) ;
F_85 ( V_15 ) ;
F_38 ( & V_15 -> V_75 ) ;
F_38 ( & V_15 -> V_76 ) ;
F_38 ( & V_15 -> V_77 ) ;
F_86 ( & V_15 -> V_78 , 1 ) ;
F_87 ( & V_15 -> V_79 ) ;
V_33 = F_70 ( V_15 ) ;
if ( V_33 )
goto V_73;
F_53 ( & V_80 ) ;
F_88 ( & V_15 -> V_81 , & V_81 ) ;
F_55 ( & V_80 ) ;
return V_15 ;
V_73:
F_89 ( & V_15 -> V_50 ) ;
V_69:
F_90 () ;
V_65:
for ( V_17 = 0 ; V_17 < V_70 ; V_17 ++ )
F_91 ( V_15 -> V_71 [ V_17 ] ) ;
F_91 ( V_15 -> V_62 ) ;
F_92 ( V_15 ) ;
return F_75 ( V_33 ) ;
}
void * F_93 ( unsigned long V_82 )
{
if ( V_82 > V_83 )
return F_94 ( V_82 ) ;
else
return F_81 ( V_82 , V_36 ) ;
}
void F_95 ( const void * V_84 )
{
if ( F_96 ( V_84 ) )
F_97 ( V_84 ) ;
else
F_91 ( V_84 ) ;
}
static void F_98 ( struct V_85 * V_86 )
{
if ( ! V_86 -> V_87 )
return;
F_95 ( V_86 -> V_87 ) ;
V_86 -> V_87 = NULL ;
}
static void F_99 ( struct V_15 * V_15 , struct V_85 * free ,
struct V_85 * V_88 )
{
if ( ! V_88 || free -> V_87 != V_88 -> V_87 )
F_98 ( free ) ;
F_100 ( V_15 , free , V_88 ) ;
free -> V_89 = 0 ;
}
static void F_101 ( struct V_15 * V_15 )
{
struct V_60 * V_61 = V_15 -> V_62 ;
struct V_85 * V_86 ;
F_102 (memslot, slots)
F_99 ( V_15 , V_86 , NULL ) ;
F_91 ( V_15 -> V_62 ) ;
}
static void F_103 ( struct V_15 * V_15 )
{
struct V_90 * V_91 , * V_92 ;
F_104 (node, tmp, &kvm->devices) {
struct V_93 * V_94 =
F_105 ( V_91 , struct V_93 , V_95 ) ;
F_106 ( V_91 ) ;
V_94 -> V_58 -> V_96 ( V_94 ) ;
}
}
static void F_107 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_45 * V_46 = V_15 -> V_46 ;
F_108 ( V_15 ) ;
F_53 ( & V_80 ) ;
F_106 ( & V_15 -> V_81 ) ;
F_55 ( & V_80 ) ;
F_109 ( V_15 ) ;
for ( V_17 = 0 ; V_17 < V_70 ; V_17 ++ )
F_110 ( V_15 -> V_71 [ V_17 ] ) ;
F_111 ( V_15 ) ;
#if F_112 ( V_97 ) && F_112 ( V_98 )
F_113 ( & V_15 -> V_43 , V_15 -> V_46 ) ;
#else
F_69 ( V_15 ) ;
#endif
F_114 ( V_15 ) ;
F_103 ( V_15 ) ;
F_101 ( V_15 ) ;
F_89 ( & V_15 -> V_50 ) ;
F_92 ( V_15 ) ;
F_90 () ;
F_115 ( V_46 ) ;
}
void F_116 ( struct V_15 * V_15 )
{
F_84 ( & V_15 -> V_78 ) ;
}
void F_117 ( struct V_15 * V_15 )
{
if ( F_118 ( & V_15 -> V_78 ) )
F_107 ( V_15 ) ;
}
static int F_119 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_15 * V_15 = V_101 -> V_102 ;
F_120 ( V_15 ) ;
F_117 ( V_15 ) ;
return 0 ;
}
static int F_121 ( struct V_85 * V_86 )
{
#ifndef F_122
unsigned long V_103 = 2 * F_123 ( V_86 ) ;
V_86 -> V_87 = F_93 ( V_103 ) ;
if ( ! V_86 -> V_87 )
return - V_38 ;
#endif
return 0 ;
}
static int F_124 ( const void * V_104 , const void * V_105 )
{
struct V_85 * V_106 , * V_107 ;
V_106 = (struct V_85 * ) V_104 ;
V_107 = (struct V_85 * ) V_105 ;
if ( V_106 -> V_89 < V_107 -> V_89 )
return 1 ;
if ( V_106 -> V_89 > V_107 -> V_89 )
return - 1 ;
return 0 ;
}
static void F_125 ( struct V_60 * V_61 )
{
int V_17 ;
F_126 ( V_61 -> V_62 , V_63 ,
sizeof( struct V_85 ) , F_124 , NULL ) ;
for ( V_17 = 0 ; V_17 < V_63 ; V_17 ++ )
V_61 -> V_64 [ V_61 -> V_62 [ V_17 ] . V_31 ] = V_17 ;
}
static void F_127 ( struct V_60 * V_61 ,
struct V_85 * V_108 ,
T_4 V_109 )
{
if ( V_108 ) {
int V_31 = V_108 -> V_31 ;
struct V_85 * V_110 = F_128 ( V_61 , V_31 ) ;
unsigned long V_89 = V_110 -> V_89 ;
* V_110 = * V_108 ;
if ( V_108 -> V_89 != V_89 )
F_125 ( V_61 ) ;
}
V_61 -> V_111 = V_109 + 1 ;
}
static int F_129 ( struct V_112 * V_113 )
{
T_5 V_114 = V_115 ;
#ifdef F_130
V_114 |= V_116 ;
#endif
if ( V_113 -> V_117 & ~ V_114 )
return - V_118 ;
return 0 ;
}
static struct V_60 * F_131 ( struct V_15 * V_15 ,
struct V_60 * V_61 , struct V_85 * V_108 )
{
struct V_60 * V_119 = V_15 -> V_62 ;
F_127 ( V_61 , V_108 , V_15 -> V_62 -> V_111 ) ;
F_9 ( V_15 -> V_62 , V_61 ) ;
F_132 ( & V_15 -> V_50 ) ;
F_133 ( V_15 ) ;
return V_119 ;
}
int F_134 ( struct V_15 * V_15 ,
struct V_112 * V_113 )
{
int V_33 ;
T_6 V_120 ;
unsigned long V_89 ;
struct V_85 * V_121 ;
struct V_85 V_110 , V_108 ;
struct V_60 * V_61 = NULL , * V_119 ;
enum V_122 V_123 ;
V_33 = F_129 ( V_113 ) ;
if ( V_33 )
goto V_124;
V_33 = - V_118 ;
if ( V_113 -> V_125 & ( V_83 - 1 ) )
goto V_124;
if ( V_113 -> V_126 & ( V_83 - 1 ) )
goto V_124;
if ( ( V_113 -> V_121 < V_127 ) &&
( ( V_113 -> V_128 & ( V_83 - 1 ) ) ||
! F_135 ( V_129 ,
( void V_130 * ) ( unsigned long ) V_113 -> V_128 ,
V_113 -> V_125 ) ) )
goto V_124;
if ( V_113 -> V_121 >= V_63 )
goto V_124;
if ( V_113 -> V_126 + V_113 -> V_125 < V_113 -> V_126 )
goto V_124;
V_121 = F_128 ( V_15 -> V_62 , V_113 -> V_121 ) ;
V_120 = V_113 -> V_126 >> V_131 ;
V_89 = V_113 -> V_125 >> V_131 ;
V_33 = - V_118 ;
if ( V_89 > V_132 )
goto V_124;
if ( ! V_89 )
V_113 -> V_117 &= ~ V_115 ;
V_108 = V_110 = * V_121 ;
V_108 . V_31 = V_113 -> V_121 ;
V_108 . V_120 = V_120 ;
V_108 . V_89 = V_89 ;
V_108 . V_117 = V_113 -> V_117 ;
V_33 = - V_118 ;
if ( V_89 ) {
if ( ! V_110 . V_89 )
V_123 = V_133 ;
else {
if ( ( V_113 -> V_128 != V_110 . V_128 ) ||
( V_89 != V_110 . V_89 ) ||
( ( V_108 . V_117 ^ V_110 . V_117 ) & V_116 ) )
goto V_124;
if ( V_120 != V_110 . V_120 )
V_123 = V_134 ;
else if ( V_108 . V_117 != V_110 . V_117 )
V_123 = V_135 ;
else {
V_33 = 0 ;
goto V_124;
}
}
} else if ( V_110 . V_89 ) {
V_123 = V_136 ;
} else
goto V_124;
if ( ( V_123 == V_133 ) || ( V_123 == V_134 ) ) {
V_33 = - V_137 ;
F_102 (slot, kvm->memslots) {
if ( ( V_121 -> V_31 >= V_127 ) ||
( V_121 -> V_31 == V_113 -> V_121 ) )
continue;
if ( ! ( ( V_120 + V_89 <= V_121 -> V_120 ) ||
( V_120 >= V_121 -> V_120 + V_121 -> V_89 ) ) )
goto V_124;
}
}
if ( ! ( V_108 . V_117 & V_115 ) )
V_108 . V_87 = NULL ;
V_33 = - V_38 ;
if ( V_123 == V_133 ) {
V_108 . V_128 = V_113 -> V_128 ;
if ( F_136 ( V_15 , & V_108 , V_89 ) )
goto V_138;
}
if ( ( V_108 . V_117 & V_115 ) && ! V_108 . V_87 ) {
if ( F_121 ( & V_108 ) < 0 )
goto V_138;
}
if ( ( V_123 == V_136 ) || ( V_123 == V_134 ) ) {
V_33 = - V_38 ;
V_61 = F_137 ( V_15 -> V_62 , sizeof( struct V_60 ) ,
V_36 ) ;
if ( ! V_61 )
goto V_138;
V_121 = F_128 ( V_61 , V_113 -> V_121 ) ;
V_121 -> V_117 |= V_139 ;
V_119 = F_131 ( V_15 , V_61 , NULL ) ;
F_138 ( V_15 , & V_110 ) ;
F_139 ( V_15 , V_121 ) ;
V_61 = V_119 ;
}
V_33 = F_140 ( V_15 , & V_108 , V_113 , V_123 ) ;
if ( V_33 )
goto V_140;
V_33 = - V_38 ;
if ( ! V_61 ) {
V_61 = F_137 ( V_15 -> V_62 , sizeof( struct V_60 ) ,
V_36 ) ;
if ( ! V_61 )
goto V_138;
}
if ( V_123 == V_136 ) {
V_108 . V_87 = NULL ;
memset ( & V_108 . V_141 , 0 , sizeof( V_108 . V_141 ) ) ;
}
V_119 = F_131 ( V_15 , V_61 , & V_108 ) ;
F_141 ( V_15 , V_113 , & V_110 , V_123 ) ;
F_99 ( V_15 , & V_110 , & V_108 ) ;
F_91 ( V_119 ) ;
if ( ( V_123 == V_133 ) || ( V_123 == V_134 ) ) {
V_33 = F_142 ( V_15 , & V_108 ) ;
return V_33 ;
}
return 0 ;
V_140:
F_91 ( V_61 ) ;
V_138:
F_99 ( V_15 , & V_108 , & V_110 ) ;
V_124:
return V_33 ;
}
int F_143 ( struct V_15 * V_15 ,
struct V_112 * V_113 )
{
int V_33 ;
F_144 ( & V_15 -> V_77 ) ;
V_33 = F_134 ( V_15 , V_113 ) ;
F_21 ( & V_15 -> V_77 ) ;
return V_33 ;
}
static int F_145 ( struct V_15 * V_15 ,
struct V_112 * V_113 )
{
if ( V_113 -> V_121 >= V_127 )
return - V_118 ;
return F_143 ( V_15 , V_113 ) ;
}
int F_146 ( struct V_15 * V_15 ,
struct V_142 * log , int * V_143 )
{
struct V_85 * V_86 ;
int V_33 , V_17 ;
unsigned long V_144 ;
unsigned long V_145 = 0 ;
V_33 = - V_118 ;
if ( log -> V_121 >= V_127 )
goto V_124;
V_86 = F_128 ( V_15 -> V_62 , log -> V_121 ) ;
V_33 = - V_146 ;
if ( ! V_86 -> V_87 )
goto V_124;
V_144 = F_123 ( V_86 ) ;
for ( V_17 = 0 ; ! V_145 && V_17 < V_144 / sizeof( long ) ; ++ V_17 )
V_145 = V_86 -> V_87 [ V_17 ] ;
V_33 = - V_147 ;
if ( F_147 ( log -> V_87 , V_86 -> V_87 , V_144 ) )
goto V_124;
if ( V_145 )
* V_143 = 1 ;
V_33 = 0 ;
V_124:
return V_33 ;
}
bool F_148 ( void )
{
return V_148 ;
}
void F_149 ( void )
{
V_148 = false ;
}
struct V_85 * F_150 ( struct V_15 * V_15 , T_6 V_149 )
{
return F_151 ( V_60 ( V_15 ) , V_149 ) ;
}
int F_152 ( struct V_15 * V_15 , T_6 V_149 )
{
struct V_85 * V_86 = F_150 ( V_15 , V_149 ) ;
if ( ! V_86 || V_86 -> V_31 >= V_127 ||
V_86 -> V_117 & V_139 )
return 0 ;
return 1 ;
}
unsigned long F_153 ( struct V_15 * V_15 , T_6 V_149 )
{
struct V_150 * V_151 ;
unsigned long V_84 , V_82 ;
V_82 = V_83 ;
V_84 = F_154 ( V_15 , V_149 ) ;
if ( F_155 ( V_84 ) )
return V_83 ;
F_156 ( & V_8 -> V_46 -> V_152 ) ;
V_151 = F_157 ( V_8 -> V_46 , V_84 ) ;
if ( ! V_151 )
goto V_124;
V_82 = F_158 ( V_151 ) ;
V_124:
F_159 ( & V_8 -> V_46 -> V_152 ) ;
return V_82 ;
}
static bool F_160 ( struct V_85 * V_121 )
{
return V_121 -> V_117 & V_116 ;
}
static unsigned long F_161 ( struct V_85 * V_121 , T_6 V_149 ,
T_6 * V_153 , bool V_154 )
{
if ( ! V_121 || V_121 -> V_117 & V_139 )
return V_155 ;
if ( F_160 ( V_121 ) && V_154 )
return V_156 ;
if ( V_153 )
* V_153 = V_121 -> V_89 - ( V_149 - V_121 -> V_120 ) ;
return F_162 ( V_121 , V_149 ) ;
}
static unsigned long F_163 ( struct V_85 * V_121 , T_6 V_149 ,
T_6 * V_153 )
{
return F_161 ( V_121 , V_149 , V_153 , true ) ;
}
unsigned long F_164 ( struct V_85 * V_121 ,
T_6 V_149 )
{
return F_163 ( V_121 , V_149 , NULL ) ;
}
unsigned long F_154 ( struct V_15 * V_15 , T_6 V_149 )
{
return F_163 ( F_150 ( V_15 , V_149 ) , V_149 , NULL ) ;
}
unsigned long F_165 ( struct V_15 * V_15 , T_6 V_149 , bool * V_157 )
{
struct V_85 * V_121 = F_150 ( V_15 , V_149 ) ;
unsigned long V_158 = F_161 ( V_121 , V_149 , NULL , false ) ;
if ( ! F_155 ( V_158 ) && V_157 )
* V_157 = ! F_160 ( V_121 ) ;
return V_158 ;
}
static int F_166 ( void * V_159 , void V_130 * V_158 , int V_160 )
{
return F_167 ( V_159 , V_158 , V_160 ) ;
}
static int F_168 ( void * V_159 , void V_130 * V_158 , int V_160 )
{
return F_169 ( V_159 , V_158 , V_160 ) ;
}
static int F_170 ( struct V_161 * V_162 , struct V_45 * V_46 ,
unsigned long V_54 , int V_154 , struct V_32 * * V_32 )
{
int V_117 = V_163 | V_164 | V_165 | V_166 ;
if ( V_154 )
V_117 |= V_167 ;
return F_171 ( V_162 , V_46 , V_54 , 1 , V_117 , V_32 , NULL , NULL ) ;
}
static inline int F_172 ( unsigned long V_84 )
{
int V_168 , V_117 = V_163 | V_165 | V_167 ;
V_168 = F_171 ( V_8 , V_8 -> V_46 , V_84 , 1 ,
V_117 , NULL , NULL , NULL ) ;
return V_168 == - V_169 ;
}
static bool F_173 ( unsigned long V_84 , bool V_170 , bool * V_171 ,
bool V_172 , bool * V_157 , T_1 * V_1 )
{
struct V_32 * V_32 [ 1 ] ;
int V_89 ;
if ( ! ( V_171 || V_170 ) )
return false ;
if ( ! ( V_172 || V_157 ) )
return false ;
V_89 = F_174 ( V_84 , 1 , 1 , V_32 ) ;
if ( V_89 == 1 ) {
* V_1 = F_175 ( V_32 [ 0 ] ) ;
if ( V_157 )
* V_157 = true ;
return true ;
}
return false ;
}
static int F_176 ( unsigned long V_84 , bool * V_171 , bool V_172 ,
bool * V_157 , T_1 * V_1 )
{
struct V_32 * V_32 [ 1 ] ;
int V_89 = 0 ;
F_177 () ;
if ( V_157 )
* V_157 = V_172 ;
if ( V_171 ) {
F_156 ( & V_8 -> V_46 -> V_152 ) ;
V_89 = F_170 ( V_8 , V_8 -> V_46 ,
V_84 , V_172 , V_32 ) ;
F_159 ( & V_8 -> V_46 -> V_152 ) ;
} else
V_89 = F_178 ( V_84 , 1 , V_172 ,
V_32 ) ;
if ( V_89 != 1 )
return V_89 ;
if ( F_7 ( ! V_172 ) && V_157 ) {
struct V_32 * V_173 [ 1 ] ;
V_89 = F_174 ( V_84 , 1 , 1 , V_173 ) ;
if ( V_89 == 1 ) {
* V_157 = true ;
F_179 ( V_32 [ 0 ] ) ;
V_32 [ 0 ] = V_173 [ 0 ] ;
}
V_89 = 1 ;
}
* V_1 = F_175 ( V_32 [ 0 ] ) ;
return V_89 ;
}
static bool F_180 ( struct V_150 * V_151 , bool V_172 )
{
if ( F_7 ( ! ( V_151 -> V_174 & V_175 ) ) )
return false ;
if ( V_172 && ( F_7 ( ! ( V_151 -> V_174 & V_176 ) ) ) )
return false ;
return true ;
}
static T_1 F_181 ( unsigned long V_84 , bool V_170 , bool * V_171 ,
bool V_172 , bool * V_157 )
{
struct V_150 * V_151 ;
T_1 V_1 = 0 ;
int V_89 ;
F_63 ( V_170 && V_171 ) ;
if ( F_173 ( V_84 , V_170 , V_171 , V_172 , V_157 , & V_1 ) )
return V_1 ;
if ( V_170 )
return V_177 ;
V_89 = F_176 ( V_84 , V_171 , V_172 , V_157 , & V_1 ) ;
if ( V_89 == 1 )
return V_1 ;
F_156 ( & V_8 -> V_46 -> V_152 ) ;
if ( V_89 == - V_169 ||
( ! V_171 && F_172 ( V_84 ) ) ) {
V_1 = V_178 ;
goto exit;
}
V_151 = F_182 ( V_8 -> V_46 , V_84 , V_84 + 1 ) ;
if ( V_151 == NULL )
V_1 = V_177 ;
else if ( ( V_151 -> V_174 & V_179 ) ) {
V_1 = ( ( V_84 - V_151 -> V_180 ) >> V_131 ) +
V_151 -> V_181 ;
F_63 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_171 && F_180 ( V_151 , V_172 ) )
* V_171 = true ;
V_1 = V_177 ;
}
exit:
F_159 ( & V_8 -> V_46 -> V_152 ) ;
return V_1 ;
}
static T_1
F_183 ( struct V_85 * V_121 , T_6 V_149 , bool V_170 ,
bool * V_171 , bool V_172 , bool * V_157 )
{
unsigned long V_84 = F_161 ( V_121 , V_149 , NULL , V_172 ) ;
if ( V_84 == V_156 )
return V_182 ;
if ( F_155 ( V_84 ) )
return V_183 ;
if ( V_157 && F_160 ( V_121 ) ) {
* V_157 = false ;
V_157 = NULL ;
}
return F_181 ( V_84 , V_170 , V_171 , V_172 ,
V_157 ) ;
}
static T_1 F_184 ( struct V_15 * V_15 , T_6 V_149 , bool V_170 , bool * V_171 ,
bool V_172 , bool * V_157 )
{
struct V_85 * V_121 ;
if ( V_171 )
* V_171 = false ;
V_121 = F_150 ( V_15 , V_149 ) ;
return F_183 ( V_121 , V_149 , V_170 , V_171 , V_172 ,
V_157 ) ;
}
T_1 F_185 ( struct V_15 * V_15 , T_6 V_149 )
{
return F_184 ( V_15 , V_149 , true , NULL , true , NULL ) ;
}
T_1 F_186 ( struct V_15 * V_15 , T_6 V_149 , bool * V_171 ,
bool V_172 , bool * V_157 )
{
return F_184 ( V_15 , V_149 , false , V_171 , V_172 , V_157 ) ;
}
T_1 F_187 ( struct V_15 * V_15 , T_6 V_149 )
{
return F_184 ( V_15 , V_149 , false , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_15 * V_15 , T_6 V_149 , bool V_172 ,
bool * V_157 )
{
return F_184 ( V_15 , V_149 , false , NULL , V_172 , V_157 ) ;
}
T_1 F_189 ( struct V_85 * V_121 , T_6 V_149 )
{
return F_183 ( V_121 , V_149 , false , NULL , true , NULL ) ;
}
T_1 F_190 ( struct V_85 * V_121 , T_6 V_149 )
{
return F_183 ( V_121 , V_149 , true , NULL , true , NULL ) ;
}
int F_191 ( struct V_15 * V_15 , T_6 V_149 , struct V_32 * * V_184 ,
int V_153 )
{
unsigned long V_84 ;
T_6 V_185 ;
V_84 = F_163 ( F_150 ( V_15 , V_149 ) , V_149 , & V_185 ) ;
if ( F_155 ( V_84 ) )
return - 1 ;
if ( V_185 < V_153 )
return 0 ;
return F_174 ( V_84 , V_153 , 1 , V_184 ) ;
}
static struct V_32 * F_192 ( T_1 V_1 )
{
if ( F_193 ( V_1 ) )
return V_186 ;
if ( F_1 ( V_1 ) ) {
F_194 ( 1 ) ;
return V_186 ;
}
return F_4 ( V_1 ) ;
}
struct V_32 * F_195 ( struct V_15 * V_15 , T_6 V_149 )
{
T_1 V_1 ;
V_1 = F_187 ( V_15 , V_149 ) ;
return F_192 ( V_1 ) ;
}
void F_196 ( struct V_32 * V_32 )
{
F_194 ( F_197 ( V_32 ) ) ;
F_198 ( F_175 ( V_32 ) ) ;
}
void F_198 ( T_1 V_1 )
{
if ( ! F_193 ( V_1 ) && ! F_1 ( V_1 ) )
F_179 ( F_4 ( V_1 ) ) ;
}
void F_199 ( struct V_32 * V_32 )
{
F_194 ( F_197 ( V_32 ) ) ;
F_200 ( F_175 ( V_32 ) ) ;
}
static void F_200 ( T_1 V_1 )
{
F_201 ( V_1 ) ;
F_198 ( V_1 ) ;
}
void F_201 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_32 * V_32 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_32 ) )
F_202 ( V_32 ) ;
}
}
void F_203 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_204 ( F_4 ( V_1 ) ) ;
}
void F_205 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_206 ( F_4 ( V_1 ) ) ;
}
static int F_207 ( unsigned long V_160 , int V_187 )
{
if ( V_160 > V_83 - V_187 )
return V_83 - V_187 ;
else
return V_160 ;
}
int F_208 ( struct V_15 * V_15 , T_6 V_149 , void * V_159 , int V_187 ,
int V_160 )
{
int V_33 ;
unsigned long V_84 ;
V_84 = F_165 ( V_15 , V_149 , NULL ) ;
if ( F_155 ( V_84 ) )
return - V_147 ;
V_33 = F_166 ( V_159 , ( void V_130 * ) V_84 + V_187 , V_160 ) ;
if ( V_33 )
return - V_147 ;
return 0 ;
}
int F_209 ( struct V_15 * V_15 , T_7 V_188 , void * V_159 , unsigned long V_160 )
{
T_6 V_149 = V_188 >> V_131 ;
int V_189 ;
int V_187 = F_210 ( V_188 ) ;
int V_190 ;
while ( ( V_189 = F_207 ( V_160 , V_187 ) ) != 0 ) {
V_190 = F_208 ( V_15 , V_149 , V_159 , V_187 , V_189 ) ;
if ( V_190 < 0 )
return V_190 ;
V_187 = 0 ;
V_160 -= V_189 ;
V_159 += V_189 ;
++ V_149 ;
}
return 0 ;
}
int F_211 ( struct V_15 * V_15 , T_7 V_188 , void * V_159 ,
unsigned long V_160 )
{
int V_33 ;
unsigned long V_84 ;
T_6 V_149 = V_188 >> V_131 ;
int V_187 = F_210 ( V_188 ) ;
V_84 = F_165 ( V_15 , V_149 , NULL ) ;
if ( F_155 ( V_84 ) )
return - V_147 ;
F_212 () ;
V_33 = F_168 ( V_159 , ( void V_130 * ) V_84 + V_187 , V_160 ) ;
F_213 () ;
if ( V_33 )
return - V_147 ;
return 0 ;
}
int F_214 ( struct V_15 * V_15 , T_6 V_149 , const void * V_159 ,
int V_187 , int V_160 )
{
int V_33 ;
unsigned long V_84 ;
V_84 = F_154 ( V_15 , V_149 ) ;
if ( F_155 ( V_84 ) )
return - V_147 ;
V_33 = F_215 ( ( void V_130 * ) V_84 + V_187 , V_159 , V_160 ) ;
if ( V_33 )
return - V_147 ;
F_216 ( V_15 , V_149 ) ;
return 0 ;
}
int F_217 ( struct V_15 * V_15 , T_7 V_188 , const void * V_159 ,
unsigned long V_160 )
{
T_6 V_149 = V_188 >> V_131 ;
int V_189 ;
int V_187 = F_210 ( V_188 ) ;
int V_190 ;
while ( ( V_189 = F_207 ( V_160 , V_187 ) ) != 0 ) {
V_190 = F_214 ( V_15 , V_149 , V_159 , V_187 , V_189 ) ;
if ( V_190 < 0 )
return V_190 ;
V_187 = 0 ;
V_160 -= V_189 ;
V_159 += V_189 ;
++ V_149 ;
}
return 0 ;
}
int F_218 ( struct V_15 * V_15 , struct V_191 * V_192 ,
T_7 V_188 , unsigned long V_160 )
{
struct V_60 * V_61 = V_60 ( V_15 ) ;
int V_187 = F_210 ( V_188 ) ;
T_6 V_193 = V_188 >> V_131 ;
T_6 V_194 = ( V_188 + V_160 - 1 ) >> V_131 ;
T_6 V_195 = V_194 - V_193 + 1 ;
T_6 V_196 ;
V_192 -> V_188 = V_188 ;
V_192 -> V_111 = V_61 -> V_111 ;
V_192 -> V_160 = V_160 ;
V_192 -> V_86 = F_150 ( V_15 , V_193 ) ;
V_192 -> V_158 = F_163 ( V_192 -> V_86 , V_193 , & V_196 ) ;
if ( ! F_155 ( V_192 -> V_158 ) && V_196 >= V_195 ) {
V_192 -> V_158 += V_187 ;
} else {
while ( V_193 <= V_194 ) {
V_192 -> V_86 = F_150 ( V_15 , V_193 ) ;
V_192 -> V_158 = F_163 ( V_192 -> V_86 , V_193 ,
& V_196 ) ;
if ( F_155 ( V_192 -> V_158 ) )
return - V_147 ;
V_193 += V_196 ;
}
V_192 -> V_86 = NULL ;
}
return 0 ;
}
int F_219 ( struct V_15 * V_15 , struct V_191 * V_192 ,
void * V_159 , unsigned long V_160 )
{
struct V_60 * V_61 = V_60 ( V_15 ) ;
int V_33 ;
F_63 ( V_160 > V_192 -> V_160 ) ;
if ( V_61 -> V_111 != V_192 -> V_111 )
F_218 ( V_15 , V_192 , V_192 -> V_188 , V_192 -> V_160 ) ;
if ( F_7 ( ! V_192 -> V_86 ) )
return F_217 ( V_15 , V_192 -> V_188 , V_159 , V_160 ) ;
if ( F_155 ( V_192 -> V_158 ) )
return - V_147 ;
V_33 = F_215 ( ( void V_130 * ) V_192 -> V_158 , V_159 , V_160 ) ;
if ( V_33 )
return - V_147 ;
F_220 ( V_15 , V_192 -> V_86 , V_192 -> V_188 >> V_131 ) ;
return 0 ;
}
int F_221 ( struct V_15 * V_15 , struct V_191 * V_192 ,
void * V_159 , unsigned long V_160 )
{
struct V_60 * V_61 = V_60 ( V_15 ) ;
int V_33 ;
F_63 ( V_160 > V_192 -> V_160 ) ;
if ( V_61 -> V_111 != V_192 -> V_111 )
F_218 ( V_15 , V_192 , V_192 -> V_188 , V_192 -> V_160 ) ;
if ( F_7 ( ! V_192 -> V_86 ) )
return F_209 ( V_15 , V_192 -> V_188 , V_159 , V_160 ) ;
if ( F_155 ( V_192 -> V_158 ) )
return - V_147 ;
V_33 = F_167 ( V_159 , ( void V_130 * ) V_192 -> V_158 , V_160 ) ;
if ( V_33 )
return - V_147 ;
return 0 ;
}
int F_222 ( struct V_15 * V_15 , T_6 V_149 , int V_187 , int V_160 )
{
const void * V_197 = ( const void * ) F_223 ( F_224 ( F_225 ( 0 ) ) ) ;
return F_214 ( V_15 , V_149 , V_197 , V_187 , V_160 ) ;
}
int F_226 ( struct V_15 * V_15 , T_7 V_188 , unsigned long V_160 )
{
T_6 V_149 = V_188 >> V_131 ;
int V_189 ;
int V_187 = F_210 ( V_188 ) ;
int V_190 ;
while ( ( V_189 = F_207 ( V_160 , V_187 ) ) != 0 ) {
V_190 = F_222 ( V_15 , V_149 , V_187 , V_189 ) ;
if ( V_190 < 0 )
return V_190 ;
V_187 = 0 ;
V_160 -= V_189 ;
++ V_149 ;
}
return 0 ;
}
static void F_220 ( struct V_15 * V_15 ,
struct V_85 * V_86 ,
T_6 V_149 )
{
if ( V_86 && V_86 -> V_87 ) {
unsigned long V_198 = V_149 - V_86 -> V_120 ;
F_227 ( V_198 , V_86 -> V_87 ) ;
}
}
void F_216 ( struct V_15 * V_15 , T_6 V_149 )
{
struct V_85 * V_86 ;
V_86 = F_150 ( V_15 , V_149 ) ;
F_220 ( V_15 , V_86 , V_149 ) ;
}
void F_228 ( struct V_2 * V_3 )
{
F_229 ( V_199 ) ;
for (; ; ) {
F_230 ( & V_3 -> V_35 , & V_199 , V_200 ) ;
if ( F_231 ( V_3 ) ) {
F_26 ( V_201 , V_3 ) ;
break;
}
if ( F_232 ( V_3 ) )
break;
if ( F_233 ( V_8 ) )
break;
F_234 () ;
}
F_235 ( & V_3 -> V_35 , & V_199 ) ;
}
void F_236 ( struct V_2 * V_3 )
{
int V_18 ;
int V_4 = V_3 -> V_4 ;
T_8 * V_202 ;
V_202 = F_237 ( V_3 ) ;
if ( F_238 ( V_202 ) ) {
F_239 ( V_202 ) ;
++ V_3 -> V_25 . V_203 ;
}
V_18 = F_12 () ;
if ( V_4 != V_18 && ( unsigned ) V_4 < V_204 && F_240 ( V_4 ) )
if ( F_241 ( V_3 ) )
F_242 ( V_4 ) ;
F_15 () ;
}
bool F_243 ( struct V_2 * V_205 )
{
struct V_7 * V_7 ;
struct V_161 * V_206 = NULL ;
bool V_190 = false ;
F_244 () ;
V_7 = F_245 ( V_205 -> V_7 ) ;
if ( V_7 )
V_206 = F_246 ( V_205 -> V_7 , V_10 ) ;
F_247 () ;
if ( ! V_206 )
return V_190 ;
if ( V_206 -> V_117 & V_207 ) {
F_248 ( V_206 ) ;
return V_190 ;
}
V_190 = F_249 ( V_206 , 1 ) ;
F_248 ( V_206 ) ;
return V_190 ;
}
static bool F_250 ( struct V_2 * V_3 )
{
#ifdef F_251
bool V_208 ;
V_208 = ! V_3 -> V_209 . V_210 ||
( V_3 -> V_209 . V_210 &&
V_3 -> V_209 . V_211 ) ;
if ( V_3 -> V_209 . V_210 )
F_44 ( V_3 , ! V_3 -> V_209 . V_211 ) ;
return V_208 ;
#else
return true ;
#endif
}
void F_252 ( struct V_2 * V_18 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_2 * V_3 ;
int V_212 = V_18 -> V_15 -> V_212 ;
int V_213 = 0 ;
int V_214 = 3 ;
int V_215 ;
int V_17 ;
F_43 ( V_18 , true ) ;
for ( V_215 = 0 ; V_215 < 2 && ! V_213 && V_214 ; V_215 ++ ) {
F_25 (i, vcpu, kvm) {
if ( ! V_215 && V_17 <= V_212 ) {
V_17 = V_212 ;
continue;
} else if ( V_215 && V_17 > V_212 )
break;
if ( ! F_253 ( V_3 -> V_41 ) )
continue;
if ( V_3 == V_18 )
continue;
if ( F_238 ( & V_3 -> V_35 ) && ! F_231 ( V_3 ) )
continue;
if ( ! F_250 ( V_3 ) )
continue;
V_213 = F_243 ( V_3 ) ;
if ( V_213 > 0 ) {
V_15 -> V_212 = V_17 ;
break;
} else if ( V_213 < 0 ) {
V_214 -- ;
if ( ! V_214 )
break;
}
}
}
F_43 ( V_18 , false ) ;
F_44 ( V_18 , false ) ;
}
static int F_254 ( struct V_150 * V_151 , struct V_216 * V_217 )
{
struct V_2 * V_3 = V_151 -> V_218 -> V_102 ;
struct V_32 * V_32 ;
if ( V_217 -> V_219 == 0 )
V_32 = F_255 ( V_3 -> V_40 ) ;
#ifdef F_256
else if ( V_217 -> V_219 == V_220 )
V_32 = F_255 ( V_3 -> V_141 . V_221 ) ;
#endif
#ifdef F_257
else if ( V_217 -> V_219 == F_257 )
V_32 = F_255 ( V_3 -> V_15 -> V_222 ) ;
#endif
else
return F_258 ( V_3 , V_217 ) ;
F_206 ( V_32 ) ;
V_217 -> V_32 = V_32 ;
return 0 ;
}
static int F_259 ( struct V_100 * V_100 , struct V_150 * V_151 )
{
V_151 -> V_223 = & V_224 ;
return 0 ;
}
static int F_260 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
F_117 ( V_3 -> V_15 ) ;
return 0 ;
}
static int F_261 ( struct V_2 * V_3 )
{
return F_262 ( L_1 , & V_225 , V_3 , V_226 | V_227 ) ;
}
static int F_263 ( struct V_15 * V_15 , T_5 V_31 )
{
int V_33 ;
struct V_2 * V_3 , * V_228 ;
if ( V_31 >= V_229 )
return - V_118 ;
V_3 = F_264 ( V_15 , V_31 ) ;
if ( F_265 ( V_3 ) )
return F_266 ( V_3 ) ;
F_267 ( & V_3 -> V_13 , & V_230 ) ;
V_33 = F_268 ( V_3 ) ;
if ( V_33 )
goto V_231;
F_144 ( & V_15 -> V_75 ) ;
if ( ! F_269 ( V_3 ) ) {
V_33 = - V_118 ;
goto V_232;
}
if ( F_270 ( & V_15 -> V_233 ) == V_229 ) {
V_33 = - V_118 ;
goto V_232;
}
F_25 (r, v, kvm)
if ( V_228 -> V_34 == V_31 ) {
V_33 = - V_137 ;
goto V_232;
}
F_63 ( V_15 -> V_234 [ F_270 ( & V_15 -> V_233 ) ] ) ;
F_116 ( V_15 ) ;
V_33 = F_261 ( V_3 ) ;
if ( V_33 < 0 ) {
F_117 ( V_15 ) ;
goto V_232;
}
V_15 -> V_234 [ F_270 ( & V_15 -> V_233 ) ] = V_3 ;
F_62 () ;
F_84 ( & V_15 -> V_233 ) ;
F_21 ( & V_15 -> V_75 ) ;
F_271 ( V_3 ) ;
return V_33 ;
V_232:
F_21 ( & V_15 -> V_75 ) ;
V_231:
F_272 ( V_3 ) ;
return V_33 ;
}
static int F_273 ( struct V_2 * V_3 , T_9 * V_235 )
{
if ( V_235 ) {
F_274 ( V_235 , F_275 ( V_236 ) | F_275 ( V_237 ) ) ;
V_3 -> V_238 = 1 ;
V_3 -> V_235 = * V_235 ;
} else
V_3 -> V_238 = 0 ;
return 0 ;
}
static long F_276 ( struct V_100 * V_101 ,
unsigned int V_239 , unsigned long V_240 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
void V_130 * V_241 = ( void V_130 * ) V_240 ;
int V_33 ;
struct V_242 * V_243 = NULL ;
struct V_244 * V_244 = NULL ;
if ( V_3 -> V_15 -> V_46 != V_8 -> V_46 )
return - V_245 ;
#if F_112 ( F_122 ) || F_112 ( V_246 ) || F_112 ( V_247 )
if ( V_239 == V_248 || V_239 == V_249 )
return F_277 ( V_101 , V_239 , V_240 ) ;
#endif
V_33 = F_5 ( V_3 ) ;
if ( V_33 )
return V_33 ;
switch ( V_239 ) {
case V_250 :
V_33 = - V_118 ;
if ( V_240 )
goto V_124;
V_33 = F_278 ( V_3 , V_3 -> V_40 ) ;
F_279 ( V_3 -> V_40 -> V_251 , V_33 ) ;
break;
case V_252 : {
struct V_253 * V_253 ;
V_33 = - V_38 ;
V_253 = F_81 ( sizeof( struct V_253 ) , V_36 ) ;
if ( ! V_253 )
goto V_124;
V_33 = F_280 ( V_3 , V_253 ) ;
if ( V_33 )
goto V_254;
V_33 = - V_147 ;
if ( F_147 ( V_241 , V_253 , sizeof( struct V_253 ) ) )
goto V_254;
V_33 = 0 ;
V_254:
F_91 ( V_253 ) ;
break;
}
case V_255 : {
struct V_253 * V_253 ;
V_33 = - V_38 ;
V_253 = F_281 ( V_241 , sizeof( * V_253 ) ) ;
if ( F_265 ( V_253 ) ) {
V_33 = F_266 ( V_253 ) ;
goto V_124;
}
V_33 = F_282 ( V_3 , V_253 ) ;
F_91 ( V_253 ) ;
break;
}
case V_256 : {
V_244 = F_81 ( sizeof( struct V_244 ) , V_36 ) ;
V_33 = - V_38 ;
if ( ! V_244 )
goto V_124;
V_33 = F_283 ( V_3 , V_244 ) ;
if ( V_33 )
goto V_124;
V_33 = - V_147 ;
if ( F_147 ( V_241 , V_244 , sizeof( struct V_244 ) ) )
goto V_124;
V_33 = 0 ;
break;
}
case V_257 : {
V_244 = F_281 ( V_241 , sizeof( * V_244 ) ) ;
if ( F_265 ( V_244 ) ) {
V_33 = F_266 ( V_244 ) ;
V_244 = NULL ;
goto V_124;
}
V_33 = F_284 ( V_3 , V_244 ) ;
break;
}
case V_258 : {
struct V_259 V_260 ;
V_33 = F_285 ( V_3 , & V_260 ) ;
if ( V_33 )
goto V_124;
V_33 = - V_147 ;
if ( F_147 ( V_241 , & V_260 , sizeof V_260 ) )
goto V_124;
V_33 = 0 ;
break;
}
case V_261 : {
struct V_259 V_260 ;
V_33 = - V_147 ;
if ( F_286 ( & V_260 , V_241 , sizeof V_260 ) )
goto V_124;
V_33 = F_287 ( V_3 , & V_260 ) ;
break;
}
case V_262 : {
struct V_263 V_264 ;
V_33 = - V_147 ;
if ( F_286 ( & V_264 , V_241 , sizeof V_264 ) )
goto V_124;
V_33 = F_288 ( V_3 , & V_264 ) ;
if ( V_33 )
goto V_124;
V_33 = - V_147 ;
if ( F_147 ( V_241 , & V_264 , sizeof V_264 ) )
goto V_124;
V_33 = 0 ;
break;
}
case V_265 : {
struct V_266 V_267 ;
V_33 = - V_147 ;
if ( F_286 ( & V_267 , V_241 , sizeof V_267 ) )
goto V_124;
V_33 = F_289 ( V_3 , & V_267 ) ;
break;
}
case V_268 : {
struct V_269 V_130 * V_270 = V_241 ;
struct V_269 V_271 ;
T_9 V_235 , * V_272 ;
V_272 = NULL ;
if ( V_241 ) {
V_33 = - V_147 ;
if ( F_286 ( & V_271 , V_241 ,
sizeof V_271 ) )
goto V_124;
V_33 = - V_118 ;
if ( V_271 . V_160 != sizeof V_235 )
goto V_124;
V_33 = - V_147 ;
if ( F_286 ( & V_235 , V_270 -> V_235 ,
sizeof V_235 ) )
goto V_124;
V_272 = & V_235 ;
}
V_33 = F_273 ( V_3 , V_272 ) ;
break;
}
case V_273 : {
V_243 = F_81 ( sizeof( struct V_242 ) , V_36 ) ;
V_33 = - V_38 ;
if ( ! V_243 )
goto V_124;
V_33 = F_290 ( V_3 , V_243 ) ;
if ( V_33 )
goto V_124;
V_33 = - V_147 ;
if ( F_147 ( V_241 , V_243 , sizeof( struct V_242 ) ) )
goto V_124;
V_33 = 0 ;
break;
}
case V_274 : {
V_243 = F_281 ( V_241 , sizeof( * V_243 ) ) ;
if ( F_265 ( V_243 ) ) {
V_33 = F_266 ( V_243 ) ;
V_243 = NULL ;
goto V_124;
}
V_33 = F_291 ( V_3 , V_243 ) ;
break;
}
default:
V_33 = F_277 ( V_101 , V_239 , V_240 ) ;
}
V_124:
F_16 ( V_3 ) ;
F_91 ( V_243 ) ;
F_91 ( V_244 ) ;
return V_33 ;
}
static long F_292 ( struct V_100 * V_101 ,
unsigned int V_239 , unsigned long V_240 )
{
struct V_2 * V_3 = V_101 -> V_102 ;
void V_130 * V_241 = F_293 ( V_240 ) ;
int V_33 ;
if ( V_3 -> V_15 -> V_46 != V_8 -> V_46 )
return - V_245 ;
switch ( V_239 ) {
case V_268 : {
struct V_269 V_130 * V_270 = V_241 ;
struct V_269 V_271 ;
T_10 V_275 ;
T_9 V_235 ;
if ( V_241 ) {
V_33 = - V_147 ;
if ( F_286 ( & V_271 , V_241 ,
sizeof V_271 ) )
goto V_124;
V_33 = - V_118 ;
if ( V_271 . V_160 != sizeof V_275 )
goto V_124;
V_33 = - V_147 ;
if ( F_286 ( & V_275 , V_270 -> V_235 ,
sizeof V_275 ) )
goto V_124;
F_294 ( & V_235 , & V_275 ) ;
V_33 = F_273 ( V_3 , & V_235 ) ;
} else
V_33 = F_273 ( V_3 , NULL ) ;
break;
}
default:
V_33 = F_276 ( V_101 , V_239 , V_240 ) ;
}
V_124:
return V_33 ;
}
static int F_295 ( struct V_93 * V_94 ,
int (* F_296)( struct V_93 * V_94 ,
struct V_276 * V_277 ) ,
unsigned long V_240 )
{
struct V_276 V_277 ;
if ( ! F_296 )
return - V_278 ;
if ( F_286 ( & V_277 , ( void V_130 * ) V_240 , sizeof( V_277 ) ) )
return - V_147 ;
return F_296 ( V_94 , & V_277 ) ;
}
static long F_297 ( struct V_100 * V_101 , unsigned int V_239 ,
unsigned long V_240 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
switch ( V_239 ) {
case V_279 :
return F_295 ( V_94 , V_94 -> V_58 -> V_280 , V_240 ) ;
case V_281 :
return F_295 ( V_94 , V_94 -> V_58 -> V_282 , V_240 ) ;
case V_283 :
return F_295 ( V_94 , V_94 -> V_58 -> V_284 , V_240 ) ;
default:
if ( V_94 -> V_58 -> V_239 )
return V_94 -> V_58 -> V_239 ( V_94 , V_239 , V_240 ) ;
return - V_285 ;
}
}
static int F_298 ( struct V_99 * V_99 , struct V_100 * V_101 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
struct V_15 * V_15 = V_94 -> V_15 ;
F_117 ( V_15 ) ;
return 0 ;
}
struct V_93 * F_299 ( struct V_100 * V_101 )
{
if ( V_101 -> V_286 != & V_287 )
return NULL ;
return V_101 -> V_102 ;
}
static int F_300 ( struct V_15 * V_15 ,
struct V_288 * V_289 )
{
struct V_290 * V_58 = NULL ;
struct V_93 * V_94 ;
bool V_291 = V_289 -> V_117 & V_292 ;
int V_190 ;
switch ( V_289 -> type ) {
#ifdef F_301
case V_293 :
case V_294 :
V_58 = & V_295 ;
break;
#endif
#ifdef F_302
case V_296 :
V_58 = & V_297 ;
break;
#endif
#ifdef F_303
case V_298 :
V_58 = & V_299 ;
break;
#endif
#ifdef F_304
case V_300 :
V_58 = & V_301 ;
break;
#endif
#ifdef F_122
case V_302 :
V_58 = & V_303 ;
break;
#endif
default:
return - V_304 ;
}
if ( V_291 )
return 0 ;
V_94 = F_81 ( sizeof( * V_94 ) , V_36 ) ;
if ( ! V_94 )
return - V_38 ;
V_94 -> V_58 = V_58 ;
V_94 -> V_15 = V_15 ;
V_190 = V_58 -> V_305 ( V_94 , V_289 -> type ) ;
if ( V_190 < 0 ) {
F_91 ( V_94 ) ;
return V_190 ;
}
V_190 = F_262 ( V_58 -> V_306 , & V_287 , V_94 , V_226 | V_227 ) ;
if ( V_190 < 0 ) {
V_58 -> V_96 ( V_94 ) ;
return V_190 ;
}
F_88 ( & V_94 -> V_95 , & V_15 -> V_79 ) ;
F_116 ( V_15 ) ;
V_289 -> V_307 = V_190 ;
return 0 ;
}
static long F_305 ( struct V_100 * V_101 ,
unsigned int V_239 , unsigned long V_240 )
{
struct V_15 * V_15 = V_101 -> V_102 ;
void V_130 * V_241 = ( void V_130 * ) V_240 ;
int V_33 ;
if ( V_15 -> V_46 != V_8 -> V_46 )
return - V_245 ;
switch ( V_239 ) {
case V_308 :
V_33 = F_263 ( V_15 , V_240 ) ;
break;
case V_309 : {
struct V_112 V_310 ;
V_33 = - V_147 ;
if ( F_286 ( & V_310 , V_241 ,
sizeof V_310 ) )
goto V_124;
V_33 = F_145 ( V_15 , & V_310 ) ;
break;
}
case V_311 : {
struct V_142 log ;
V_33 = - V_147 ;
if ( F_286 ( & log , V_241 , sizeof log ) )
goto V_124;
V_33 = F_306 ( V_15 , & log ) ;
break;
}
#ifdef F_257
case V_312 : {
struct V_313 V_314 ;
V_33 = - V_147 ;
if ( F_286 ( & V_314 , V_241 , sizeof V_314 ) )
goto V_124;
V_33 = F_307 ( V_15 , & V_314 ) ;
break;
}
case V_315 : {
struct V_313 V_314 ;
V_33 = - V_147 ;
if ( F_286 ( & V_314 , V_241 , sizeof V_314 ) )
goto V_124;
V_33 = F_308 ( V_15 , & V_314 ) ;
break;
}
#endif
case V_316 : {
struct V_317 V_159 ;
V_33 = - V_147 ;
if ( F_286 ( & V_159 , V_241 , sizeof V_159 ) )
goto V_124;
V_33 = V_317 ( V_15 , & V_159 ) ;
break;
}
case V_318 : {
struct V_319 V_159 ;
V_33 = - V_147 ;
if ( F_286 ( & V_159 , V_241 , sizeof V_159 ) )
goto V_124;
V_33 = V_319 ( V_15 , & V_159 ) ;
break;
}
#ifdef F_309
case V_320 :
V_33 = 0 ;
F_144 ( & V_15 -> V_75 ) ;
if ( F_270 ( & V_15 -> V_233 ) != 0 )
V_33 = - V_321 ;
else
V_15 -> V_322 = V_240 ;
F_21 ( & V_15 -> V_75 ) ;
break;
#endif
#ifdef F_310
case V_323 : {
struct V_324 V_325 ;
V_33 = - V_147 ;
if ( F_286 ( & V_325 , V_241 , sizeof V_325 ) )
goto V_124;
V_33 = F_311 ( V_15 , & V_325 ) ;
break;
}
#endif
#ifdef F_312
case V_326 :
case V_327 : {
struct V_328 V_329 ;
V_33 = - V_147 ;
if ( F_286 ( & V_329 , V_241 , sizeof V_329 ) )
goto V_124;
V_33 = F_313 ( V_15 , & V_329 ,
V_239 == V_326 ) ;
if ( V_33 )
goto V_124;
V_33 = - V_147 ;
if ( V_239 == V_326 ) {
if ( F_147 ( V_241 , & V_329 , sizeof V_329 ) )
goto V_124;
}
V_33 = 0 ;
break;
}
#endif
#ifdef F_314
case V_330 : {
struct V_331 V_332 ;
struct V_331 V_130 * V_333 ;
struct V_334 * V_335 ;
V_33 = - V_147 ;
if ( F_286 ( & V_332 , V_241 , sizeof( V_332 ) ) )
goto V_124;
V_33 = - V_118 ;
if ( V_332 . V_336 >= V_337 )
goto V_124;
if ( V_332 . V_117 )
goto V_124;
V_33 = - V_38 ;
V_335 = F_315 ( V_332 . V_336 * sizeof( * V_335 ) ) ;
if ( ! V_335 )
goto V_124;
V_33 = - V_147 ;
V_333 = V_241 ;
if ( F_286 ( V_335 , V_333 -> V_335 ,
V_332 . V_336 * sizeof( * V_335 ) ) )
goto V_338;
V_33 = F_316 ( V_15 , V_335 , V_332 . V_336 ,
V_332 . V_117 ) ;
V_338:
F_97 ( V_335 ) ;
break;
}
#endif
case V_339 : {
struct V_288 V_289 ;
V_33 = - V_147 ;
if ( F_286 ( & V_289 , V_241 , sizeof( V_289 ) ) )
goto V_124;
V_33 = F_300 ( V_15 , & V_289 ) ;
if ( V_33 )
goto V_124;
V_33 = - V_147 ;
if ( F_147 ( V_241 , & V_289 , sizeof( V_289 ) ) )
goto V_124;
V_33 = 0 ;
break;
}
default:
V_33 = F_317 ( V_101 , V_239 , V_240 ) ;
if ( V_33 == - V_285 )
V_33 = F_318 ( V_15 , V_239 , V_240 ) ;
}
V_124:
return V_33 ;
}
static long F_319 ( struct V_100 * V_101 ,
unsigned int V_239 , unsigned long V_240 )
{
struct V_15 * V_15 = V_101 -> V_102 ;
int V_33 ;
if ( V_15 -> V_46 != V_8 -> V_46 )
return - V_245 ;
switch ( V_239 ) {
case V_311 : {
struct V_340 V_341 ;
struct V_142 log ;
V_33 = - V_147 ;
if ( F_286 ( & V_341 , ( void V_130 * ) V_240 ,
sizeof( V_341 ) ) )
goto V_124;
log . V_121 = V_341 . V_121 ;
log . V_342 = V_341 . V_342 ;
log . V_343 = V_341 . V_343 ;
log . V_87 = F_293 ( V_341 . V_87 ) ;
V_33 = F_306 ( V_15 , & log ) ;
break;
}
default:
V_33 = F_305 ( V_101 , V_239 , V_240 ) ;
}
V_124:
return V_33 ;
}
static int F_320 ( unsigned long type )
{
int V_33 ;
struct V_15 * V_15 ;
V_15 = F_73 ( type ) ;
if ( F_265 ( V_15 ) )
return F_266 ( V_15 ) ;
#ifdef F_257
V_33 = F_321 ( V_15 ) ;
if ( V_33 < 0 ) {
F_117 ( V_15 ) ;
return V_33 ;
}
#endif
V_33 = F_262 ( L_2 , & V_344 , V_15 , V_226 | V_227 ) ;
if ( V_33 < 0 )
F_117 ( V_15 ) ;
return V_33 ;
}
static long F_322 ( long V_240 )
{
switch ( V_240 ) {
case V_345 :
case V_346 :
case V_347 :
#ifdef F_309
case V_348 :
#endif
case V_349 :
#ifdef F_310
case V_350 :
#endif
#ifdef F_314
case V_351 :
#endif
return 1 ;
#ifdef F_314
case V_352 :
return V_337 ;
#endif
default:
break;
}
return F_323 ( V_240 ) ;
}
static long F_324 ( struct V_100 * V_101 ,
unsigned int V_239 , unsigned long V_240 )
{
long V_33 = - V_118 ;
switch ( V_239 ) {
case V_353 :
V_33 = - V_118 ;
if ( V_240 )
goto V_124;
V_33 = V_354 ;
break;
case V_355 :
V_33 = F_320 ( V_240 ) ;
break;
case V_356 :
V_33 = F_322 ( V_240 ) ;
break;
case V_357 :
V_33 = - V_118 ;
if ( V_240 )
goto V_124;
V_33 = V_83 ;
#ifdef F_256
V_33 += V_83 ;
#endif
#ifdef F_257
V_33 += V_83 ;
#endif
break;
case V_358 :
case V_359 :
case V_360 :
V_33 = - V_361 ;
break;
default:
return F_325 ( V_101 , V_239 , V_240 ) ;
}
V_124:
return V_33 ;
}
static void F_326 ( void * V_362 )
{
int V_4 = F_327 () ;
int V_33 ;
if ( F_328 ( V_4 , V_363 ) )
return;
F_29 ( V_4 , V_363 ) ;
V_33 = F_329 ( NULL ) ;
if ( V_33 ) {
F_330 ( V_4 , V_363 ) ;
F_84 ( & V_364 ) ;
F_331 ( V_365 L_3
L_4 , V_4 ) ;
}
}
static void F_332 ( void )
{
F_333 ( & V_366 ) ;
if ( V_367 )
F_326 ( NULL ) ;
F_334 ( & V_366 ) ;
}
static void F_335 ( void * V_362 )
{
int V_4 = F_327 () ;
if ( ! F_328 ( V_4 , V_363 ) )
return;
F_330 ( V_4 , V_363 ) ;
F_336 ( NULL ) ;
}
static void F_337 ( void )
{
F_333 ( & V_366 ) ;
if ( V_367 )
F_335 ( NULL ) ;
F_334 ( & V_366 ) ;
}
static void F_338 ( void )
{
F_63 ( ! V_367 ) ;
V_367 -- ;
if ( ! V_367 )
F_339 ( F_335 , NULL , 1 ) ;
}
static void F_90 ( void )
{
F_333 ( & V_366 ) ;
F_338 () ;
F_334 ( & V_366 ) ;
}
static int F_77 ( void )
{
int V_33 = 0 ;
F_333 ( & V_366 ) ;
V_367 ++ ;
if ( V_367 == 1 ) {
F_86 ( & V_364 , 0 ) ;
F_339 ( F_326 , NULL , 1 ) ;
if ( F_270 ( & V_364 ) ) {
F_338 () ;
V_33 = - V_321 ;
}
}
F_334 ( & V_366 ) ;
return V_33 ;
}
static int F_340 ( struct V_368 * V_369 , unsigned long V_370 ,
void * V_228 )
{
int V_4 = ( long ) V_228 ;
V_370 &= ~ V_371 ;
switch ( V_370 ) {
case V_372 :
F_331 ( V_365 L_5 ,
V_4 ) ;
F_337 () ;
break;
case V_373 :
F_331 ( V_365 L_6 ,
V_4 ) ;
F_332 () ;
break;
}
return V_374 ;
}
static int F_341 ( struct V_368 * V_369 , unsigned long V_370 ,
void * V_228 )
{
F_331 ( V_365 L_7 ) ;
V_375 = true ;
F_339 ( F_335 , NULL , 1 ) ;
return V_374 ;
}
static void F_110 ( struct V_72 * V_376 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_376 -> V_377 ; V_17 ++ ) {
struct V_378 * V_379 = V_376 -> V_380 [ V_17 ] . V_94 ;
F_342 ( V_379 ) ;
}
F_91 ( V_376 ) ;
}
static inline int F_343 ( const struct V_381 * V_382 ,
const struct V_381 * V_383 )
{
if ( V_382 -> V_84 < V_383 -> V_84 )
return - 1 ;
if ( V_382 -> V_84 + V_382 -> V_160 > V_383 -> V_84 + V_383 -> V_160 )
return 1 ;
return 0 ;
}
static int F_344 ( const void * V_384 , const void * V_385 )
{
return F_343 ( V_384 , V_385 ) ;
}
static int F_345 ( struct V_72 * V_376 , struct V_378 * V_94 ,
T_7 V_84 , int V_160 )
{
V_376 -> V_380 [ V_376 -> V_377 ++ ] = (struct V_381 ) {
. V_84 = V_84 ,
. V_160 = V_160 ,
. V_94 = V_94 ,
} ;
F_126 ( V_376 -> V_380 , V_376 -> V_377 , sizeof( struct V_381 ) ,
F_344 , NULL ) ;
return 0 ;
}
static int F_346 ( struct V_72 * V_376 ,
T_7 V_84 , int V_160 )
{
struct V_381 * V_380 , V_386 ;
int V_387 ;
V_386 = (struct V_381 ) {
. V_84 = V_84 ,
. V_160 = V_160 ,
} ;
V_380 = bsearch ( & V_386 , V_376 -> V_380 , V_376 -> V_377 ,
sizeof( struct V_381 ) , F_344 ) ;
if ( V_380 == NULL )
return - V_146 ;
V_387 = V_380 - V_376 -> V_380 ;
while ( V_387 > 0 && F_343 ( & V_386 , & V_376 -> V_380 [ V_387 - 1 ] ) == 0 )
V_387 -- ;
return V_387 ;
}
static int F_347 ( struct V_72 * V_376 ,
struct V_381 * V_380 , const void * V_370 )
{
int V_49 ;
V_49 = F_346 ( V_376 , V_380 -> V_84 , V_380 -> V_160 ) ;
if ( V_49 < 0 )
return - V_361 ;
while ( V_49 < V_376 -> V_377 &&
F_343 ( V_380 , & V_376 -> V_380 [ V_49 ] ) == 0 ) {
if ( ! F_348 ( V_376 -> V_380 [ V_49 ] . V_94 , V_380 -> V_84 ,
V_380 -> V_160 , V_370 ) )
return V_49 ;
V_49 ++ ;
}
return - V_361 ;
}
int F_349 ( struct V_15 * V_15 , enum V_388 V_389 , T_7 V_84 ,
int V_160 , const void * V_370 )
{
struct V_72 * V_376 ;
struct V_381 V_380 ;
int V_33 ;
V_380 = (struct V_381 ) {
. V_84 = V_84 ,
. V_160 = V_160 ,
} ;
V_376 = F_350 ( V_15 -> V_71 [ V_389 ] , & V_15 -> V_50 ) ;
V_33 = F_347 ( V_376 , & V_380 , V_370 ) ;
return V_33 < 0 ? V_33 : 0 ;
}
int F_351 ( struct V_15 * V_15 , enum V_388 V_389 , T_7 V_84 ,
int V_160 , const void * V_370 , long V_390 )
{
struct V_72 * V_376 ;
struct V_381 V_380 ;
V_380 = (struct V_381 ) {
. V_84 = V_84 ,
. V_160 = V_160 ,
} ;
V_376 = F_350 ( V_15 -> V_71 [ V_389 ] , & V_15 -> V_50 ) ;
if ( ( V_390 >= 0 ) && ( V_390 < V_376 -> V_377 ) &&
( F_343 ( & V_380 , & V_376 -> V_380 [ V_390 ] ) == 0 ) )
if ( ! F_348 ( V_376 -> V_380 [ V_390 ] . V_94 , V_84 , V_160 ,
V_370 ) )
return V_390 ;
return F_347 ( V_376 , & V_380 , V_370 ) ;
}
static int F_352 ( struct V_72 * V_376 , struct V_381 * V_380 ,
void * V_370 )
{
int V_49 ;
V_49 = F_346 ( V_376 , V_380 -> V_84 , V_380 -> V_160 ) ;
if ( V_49 < 0 )
return - V_361 ;
while ( V_49 < V_376 -> V_377 &&
F_343 ( V_380 , & V_376 -> V_380 [ V_49 ] ) == 0 ) {
if ( ! F_353 ( V_376 -> V_380 [ V_49 ] . V_94 , V_380 -> V_84 ,
V_380 -> V_160 , V_370 ) )
return V_49 ;
V_49 ++ ;
}
return - V_361 ;
}
int F_354 ( struct V_15 * V_15 , enum V_388 V_389 , T_7 V_84 ,
int V_160 , void * V_370 )
{
struct V_72 * V_376 ;
struct V_381 V_380 ;
int V_33 ;
V_380 = (struct V_381 ) {
. V_84 = V_84 ,
. V_160 = V_160 ,
} ;
V_376 = F_350 ( V_15 -> V_71 [ V_389 ] , & V_15 -> V_50 ) ;
V_33 = F_352 ( V_376 , & V_380 , V_370 ) ;
return V_33 < 0 ? V_33 : 0 ;
}
int F_355 ( struct V_15 * V_15 , enum V_388 V_389 , T_7 V_84 ,
int V_160 , struct V_378 * V_94 )
{
struct V_72 * V_391 , * V_376 ;
V_376 = V_15 -> V_71 [ V_389 ] ;
if ( V_376 -> V_377 - V_376 -> V_392 > V_393 - 1 )
return - V_394 ;
V_391 = F_81 ( sizeof( * V_376 ) + ( ( V_376 -> V_377 + 1 ) *
sizeof( struct V_381 ) ) , V_36 ) ;
if ( ! V_391 )
return - V_38 ;
memcpy ( V_391 , V_376 , sizeof( * V_376 ) + ( V_376 -> V_377 *
sizeof( struct V_381 ) ) ) ;
F_345 ( V_391 , V_94 , V_84 , V_160 ) ;
F_9 ( V_15 -> V_71 [ V_389 ] , V_391 ) ;
F_132 ( & V_15 -> V_50 ) ;
F_91 ( V_376 ) ;
return 0 ;
}
int F_356 ( struct V_15 * V_15 , enum V_388 V_389 ,
struct V_378 * V_94 )
{
int V_17 , V_33 ;
struct V_72 * V_391 , * V_376 ;
V_376 = V_15 -> V_71 [ V_389 ] ;
V_33 = - V_146 ;
for ( V_17 = 0 ; V_17 < V_376 -> V_377 ; V_17 ++ )
if ( V_376 -> V_380 [ V_17 ] . V_94 == V_94 ) {
V_33 = 0 ;
break;
}
if ( V_33 )
return V_33 ;
V_391 = F_81 ( sizeof( * V_376 ) + ( ( V_376 -> V_377 - 1 ) *
sizeof( struct V_381 ) ) , V_36 ) ;
if ( ! V_391 )
return - V_38 ;
memcpy ( V_391 , V_376 , sizeof( * V_376 ) + V_17 * sizeof( struct V_381 ) ) ;
V_391 -> V_377 -- ;
memcpy ( V_391 -> V_380 + V_17 , V_376 -> V_380 + V_17 + 1 ,
( V_391 -> V_377 - V_17 ) * sizeof( struct V_381 ) ) ;
F_9 ( V_15 -> V_71 [ V_389 ] , V_391 ) ;
F_132 ( & V_15 -> V_50 ) ;
F_91 ( V_376 ) ;
return V_33 ;
}
static int F_357 ( void * V_395 , T_4 * V_370 )
{
unsigned V_187 = ( long ) V_395 ;
struct V_15 * V_15 ;
* V_370 = 0 ;
F_53 ( & V_80 ) ;
F_358 ( V_15 , & V_81 , V_81 )
* V_370 += * ( T_5 * ) ( ( void * ) V_15 + V_187 ) ;
F_55 ( & V_80 ) ;
return 0 ;
}
static int F_359 ( void * V_395 , T_4 * V_370 )
{
unsigned V_187 = ( long ) V_395 ;
struct V_15 * V_15 ;
struct V_2 * V_3 ;
int V_17 ;
* V_370 = 0 ;
F_53 ( & V_80 ) ;
F_358 (kvm, &vm_list, vm_list)
F_25 ( V_17 , V_3 , V_15 )
* V_370 += * ( T_5 * ) ( ( void * ) V_3 + V_187 ) ;
F_55 ( & V_80 ) ;
return 0 ;
}
static int F_360 ( void )
{
int V_33 = - V_137 ;
struct V_396 * V_272 ;
V_397 = F_361 ( L_8 , NULL ) ;
if ( V_397 == NULL )
goto V_124;
for ( V_272 = V_398 ; V_272 -> V_306 ; ++ V_272 ) {
V_272 -> V_399 = F_362 ( V_272 -> V_306 , 0444 , V_397 ,
( void * ) ( long ) V_272 -> V_187 ,
V_400 [ V_272 -> V_401 ] ) ;
if ( V_272 -> V_399 == NULL )
goto V_402;
}
return 0 ;
V_402:
F_363 ( V_397 ) ;
V_124:
return V_33 ;
}
static void F_364 ( void )
{
struct V_396 * V_272 ;
for ( V_272 = V_398 ; V_272 -> V_306 ; ++ V_272 )
F_365 ( V_272 -> V_399 ) ;
F_365 ( V_397 ) ;
}
static int F_366 ( void )
{
if ( V_367 )
F_335 ( NULL ) ;
return 0 ;
}
static void F_367 ( void )
{
if ( V_367 ) {
F_194 ( F_368 ( & V_366 ) ) ;
F_326 ( NULL ) ;
}
}
static inline
struct V_2 * F_369 ( struct V_13 * V_403 )
{
return F_50 ( V_403 , struct V_2 , V_13 ) ;
}
static void F_370 ( struct V_13 * V_403 , int V_4 )
{
struct V_2 * V_3 = F_369 ( V_403 ) ;
if ( V_3 -> V_41 )
V_3 -> V_41 = false ;
F_14 ( V_3 , V_4 ) ;
}
static void F_371 ( struct V_13 * V_403 ,
struct V_161 * V_404 )
{
struct V_2 * V_3 = F_369 ( V_403 ) ;
if ( V_8 -> V_405 == V_406 )
V_3 -> V_41 = true ;
F_18 ( V_3 ) ;
}
int F_372 ( void * V_407 , unsigned V_408 , unsigned V_409 ,
struct V_410 * V_410 )
{
int V_33 ;
int V_4 ;
V_33 = F_373 ( V_407 ) ;
if ( V_33 )
goto V_411;
V_33 = F_374 () ;
if ( V_33 )
goto V_412;
if ( ! F_24 ( & V_363 , V_36 ) ) {
V_33 = - V_38 ;
goto V_413;
}
V_33 = F_375 () ;
if ( V_33 < 0 )
goto V_414;
F_376 (cpu) {
F_377 ( V_4 ,
V_415 ,
& V_33 , 1 ) ;
if ( V_33 < 0 )
goto V_416;
}
V_33 = F_378 ( & V_417 ) ;
if ( V_33 )
goto V_418;
F_379 ( & V_419 ) ;
if ( ! V_409 )
V_409 = F_380 ( struct V_2 ) ;
V_420 = F_381 ( L_9 , V_408 , V_409 ,
0 , NULL ) ;
if ( ! V_420 ) {
V_33 = - V_38 ;
goto V_421;
}
V_33 = F_382 () ;
if ( V_33 )
goto V_138;
V_422 . V_423 = V_410 ;
V_344 . V_423 = V_410 ;
V_225 . V_423 = V_410 ;
V_33 = F_383 ( & V_424 ) ;
if ( V_33 ) {
F_331 ( V_425 L_10 ) ;
goto V_426;
}
F_384 ( & V_427 ) ;
V_230 . V_428 = F_370 ;
V_230 . V_429 = F_371 ;
V_33 = F_360 () ;
if ( V_33 ) {
F_331 ( V_425 L_11 ) ;
goto V_430;
}
return 0 ;
V_430:
F_385 ( & V_427 ) ;
F_386 ( & V_424 ) ;
V_426:
F_387 () ;
V_138:
F_388 ( V_420 ) ;
V_421:
F_389 ( & V_419 ) ;
F_390 ( & V_417 ) ;
V_418:
V_416:
F_391 () ;
V_414:
F_32 ( V_363 ) ;
V_413:
F_392 () ;
V_412:
F_393 () ;
V_411:
return V_33 ;
}
void F_394 ( void )
{
F_364 () ;
F_386 ( & V_424 ) ;
F_388 ( V_420 ) ;
F_387 () ;
F_385 ( & V_427 ) ;
F_389 ( & V_419 ) ;
F_390 ( & V_417 ) ;
F_339 ( F_335 , NULL , 1 ) ;
F_391 () ;
F_393 () ;
F_392 () ;
F_32 ( V_363 ) ;
}
