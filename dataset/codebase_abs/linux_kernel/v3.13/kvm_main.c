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
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_58 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 ,
T_3 V_54 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
F_59 ( V_15 , V_48 , V_54 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_60 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_49 = 0 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_57 ++ ;
V_49 = F_61 ( V_15 , V_55 , V_56 ) ;
V_49 |= V_15 -> V_25 ;
if ( V_49 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static void F_62 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_15 -> V_53 ++ ;
F_63 () ;
V_15 -> V_57 -- ;
F_56 ( & V_15 -> V_52 ) ;
F_64 ( V_15 -> V_57 < 0 ) ;
}
static int F_65 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_58 = F_66 ( V_15 , V_48 ) ;
if ( V_58 )
F_33 ( V_15 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
return V_58 ;
}
static int F_67 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_54 ( & V_15 -> V_52 ) ;
V_58 = F_68 ( V_15 , V_48 ) ;
F_56 ( & V_15 -> V_52 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
return V_58 ;
}
static void F_69 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_15 * V_15 = F_50 ( V_45 ) ;
int V_50 ;
V_50 = F_53 ( & V_15 -> V_51 ) ;
F_70 ( V_15 ) ;
F_57 ( & V_15 -> V_51 , V_50 ) ;
}
static int F_71 ( struct V_15 * V_15 )
{
V_15 -> V_44 . V_59 = & V_60 ;
return F_72 ( & V_15 -> V_44 , V_8 -> V_47 ) ;
}
static int F_71 ( struct V_15 * V_15 )
{
return 0 ;
}
static void F_73 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_61 * V_62 = V_15 -> V_63 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ )
V_62 -> V_65 [ V_17 ] = V_62 -> V_63 [ V_17 ] . V_32 = V_17 ;
}
static struct V_15 * F_74 ( unsigned long type )
{
int V_34 , V_17 ;
struct V_15 * V_15 = F_75 () ;
if ( ! V_15 )
return F_76 ( - V_39 ) ;
V_34 = F_77 ( V_15 , type ) ;
if ( V_34 )
goto V_66;
V_34 = F_78 () ;
if ( V_34 )
goto V_66;
#ifdef F_79
F_80 ( & V_15 -> V_67 ) ;
F_80 ( & V_15 -> V_68 ) ;
#endif
F_81 ( V_64 > V_69 ) ;
V_34 = - V_39 ;
V_15 -> V_63 = F_82 ( sizeof( struct V_61 ) , V_37 ) ;
if ( ! V_15 -> V_63 )
goto V_70;
F_73 ( V_15 ) ;
if ( F_83 ( & V_15 -> V_51 ) )
goto V_70;
for ( V_17 = 0 ; V_17 < V_71 ; V_17 ++ ) {
V_15 -> V_72 [ V_17 ] = F_82 ( sizeof( struct V_73 ) ,
V_37 ) ;
if ( ! V_15 -> V_72 [ V_17 ] )
goto V_74;
}
F_84 ( & V_15 -> V_52 ) ;
V_15 -> V_47 = V_8 -> V_47 ;
F_85 ( & V_15 -> V_47 -> V_75 ) ;
F_86 ( V_15 ) ;
F_39 ( & V_15 -> V_76 ) ;
F_39 ( & V_15 -> V_77 ) ;
F_39 ( & V_15 -> V_78 ) ;
F_87 ( & V_15 -> V_79 , 1 ) ;
F_88 ( & V_15 -> V_80 ) ;
V_34 = F_71 ( V_15 ) ;
if ( V_34 )
goto V_74;
F_54 ( & V_81 ) ;
F_89 ( & V_15 -> V_82 , & V_82 ) ;
F_56 ( & V_81 ) ;
return V_15 ;
V_74:
F_90 ( & V_15 -> V_51 ) ;
V_70:
F_91 () ;
V_66:
for ( V_17 = 0 ; V_17 < V_71 ; V_17 ++ )
F_92 ( V_15 -> V_72 [ V_17 ] ) ;
F_92 ( V_15 -> V_63 ) ;
F_93 ( V_15 ) ;
return F_76 ( V_34 ) ;
}
void * F_94 ( unsigned long V_83 )
{
if ( V_83 > V_84 )
return F_95 ( V_83 ) ;
else
return F_82 ( V_83 , V_37 ) ;
}
void F_96 ( const void * V_85 )
{
if ( F_97 ( V_85 ) )
F_98 ( V_85 ) ;
else
F_92 ( V_85 ) ;
}
static void F_99 ( struct V_86 * V_87 )
{
if ( ! V_87 -> V_88 )
return;
F_96 ( V_87 -> V_88 ) ;
V_87 -> V_88 = NULL ;
}
static void F_100 ( struct V_15 * V_15 , struct V_86 * free ,
struct V_86 * V_89 )
{
if ( ! V_89 || free -> V_88 != V_89 -> V_88 )
F_99 ( free ) ;
F_101 ( V_15 , free , V_89 ) ;
free -> V_90 = 0 ;
}
void F_102 ( struct V_15 * V_15 )
{
struct V_61 * V_62 = V_15 -> V_63 ;
struct V_86 * V_87 ;
F_103 (memslot, slots)
F_100 ( V_15 , V_87 , NULL ) ;
F_92 ( V_15 -> V_63 ) ;
}
static void F_104 ( struct V_15 * V_15 )
{
struct V_91 * V_92 , * V_93 ;
F_105 (node, tmp, &kvm->devices) {
struct V_94 * V_95 =
F_106 ( V_92 , struct V_94 , V_96 ) ;
F_107 ( V_92 ) ;
V_95 -> V_59 -> V_97 ( V_95 ) ;
}
}
static void F_108 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_46 * V_47 = V_15 -> V_47 ;
F_109 ( V_15 ) ;
F_54 ( & V_81 ) ;
F_107 ( & V_15 -> V_82 ) ;
F_56 ( & V_81 ) ;
F_110 ( V_15 ) ;
for ( V_17 = 0 ; V_17 < V_71 ; V_17 ++ )
F_111 ( V_15 -> V_72 [ V_17 ] ) ;
F_112 ( V_15 ) ;
#if F_113 ( V_98 ) && F_113 ( V_99 )
F_114 ( & V_15 -> V_44 , V_15 -> V_47 ) ;
#else
F_70 ( V_15 ) ;
#endif
F_115 ( V_15 ) ;
F_104 ( V_15 ) ;
F_102 ( V_15 ) ;
F_90 ( & V_15 -> V_51 ) ;
F_93 ( V_15 ) ;
F_91 () ;
F_116 ( V_47 ) ;
}
void F_117 ( struct V_15 * V_15 )
{
F_85 ( & V_15 -> V_79 ) ;
}
void F_118 ( struct V_15 * V_15 )
{
if ( F_119 ( & V_15 -> V_79 ) )
F_108 ( V_15 ) ;
}
static int F_120 ( struct V_100 * V_100 , struct V_101 * V_102 )
{
struct V_15 * V_15 = V_102 -> V_103 ;
F_121 ( V_15 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
static int F_122 ( struct V_86 * V_87 )
{
#ifndef F_123
unsigned long V_104 = 2 * F_124 ( V_87 ) ;
V_87 -> V_88 = F_94 ( V_104 ) ;
if ( ! V_87 -> V_88 )
return - V_39 ;
#endif
return 0 ;
}
static int F_125 ( const void * V_105 , const void * V_106 )
{
struct V_86 * V_107 , * V_108 ;
V_107 = (struct V_86 * ) V_105 ;
V_108 = (struct V_86 * ) V_106 ;
if ( V_107 -> V_90 < V_108 -> V_90 )
return 1 ;
if ( V_107 -> V_90 > V_108 -> V_90 )
return - 1 ;
return 0 ;
}
static void F_126 ( struct V_61 * V_62 )
{
int V_17 ;
F_127 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_86 ) , F_125 , NULL ) ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_17 ] . V_32 ] = V_17 ;
}
void F_128 ( struct V_61 * V_62 , struct V_86 * V_109 ,
T_4 V_110 )
{
if ( V_109 ) {
int V_32 = V_109 -> V_32 ;
struct V_86 * V_111 = F_129 ( V_62 , V_32 ) ;
unsigned long V_90 = V_111 -> V_90 ;
* V_111 = * V_109 ;
if ( V_109 -> V_90 != V_90 )
F_126 ( V_62 ) ;
}
V_62 -> V_112 = V_110 + 1 ;
}
static int F_130 ( struct V_113 * V_114 )
{
T_5 V_115 = V_116 ;
#ifdef F_131
V_115 |= V_117 ;
#endif
if ( V_114 -> V_118 & ~ V_115 )
return - V_119 ;
return 0 ;
}
static struct V_61 * F_132 ( struct V_15 * V_15 ,
struct V_61 * V_62 , struct V_86 * V_109 )
{
struct V_61 * V_120 = V_15 -> V_63 ;
F_128 ( V_62 , V_109 , V_15 -> V_63 -> V_112 ) ;
F_9 ( V_15 -> V_63 , V_62 ) ;
F_133 ( & V_15 -> V_51 ) ;
F_134 ( V_15 ) ;
return V_120 ;
}
int F_135 ( struct V_15 * V_15 ,
struct V_113 * V_114 )
{
int V_34 ;
T_6 V_121 ;
unsigned long V_90 ;
struct V_86 * V_122 ;
struct V_86 V_111 , V_109 ;
struct V_61 * V_62 = NULL , * V_120 ;
enum V_123 V_124 ;
V_34 = F_130 ( V_114 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_119 ;
if ( V_114 -> V_126 & ( V_84 - 1 ) )
goto V_125;
if ( V_114 -> V_127 & ( V_84 - 1 ) )
goto V_125;
if ( ( V_114 -> V_122 < V_128 ) &&
( ( V_114 -> V_129 & ( V_84 - 1 ) ) ||
! F_136 ( V_130 ,
( void V_131 * ) ( unsigned long ) V_114 -> V_129 ,
V_114 -> V_126 ) ) )
goto V_125;
if ( V_114 -> V_122 >= V_64 )
goto V_125;
if ( V_114 -> V_127 + V_114 -> V_126 < V_114 -> V_127 )
goto V_125;
V_122 = F_129 ( V_15 -> V_63 , V_114 -> V_122 ) ;
V_121 = V_114 -> V_127 >> V_132 ;
V_90 = V_114 -> V_126 >> V_132 ;
V_34 = - V_119 ;
if ( V_90 > V_133 )
goto V_125;
if ( ! V_90 )
V_114 -> V_118 &= ~ V_116 ;
V_109 = V_111 = * V_122 ;
V_109 . V_32 = V_114 -> V_122 ;
V_109 . V_121 = V_121 ;
V_109 . V_90 = V_90 ;
V_109 . V_118 = V_114 -> V_118 ;
V_34 = - V_119 ;
if ( V_90 ) {
if ( ! V_111 . V_90 )
V_124 = V_134 ;
else {
if ( ( V_114 -> V_129 != V_111 . V_129 ) ||
( V_90 != V_111 . V_90 ) ||
( ( V_109 . V_118 ^ V_111 . V_118 ) & V_117 ) )
goto V_125;
if ( V_121 != V_111 . V_121 )
V_124 = V_135 ;
else if ( V_109 . V_118 != V_111 . V_118 )
V_124 = V_136 ;
else {
V_34 = 0 ;
goto V_125;
}
}
} else if ( V_111 . V_90 ) {
V_124 = V_137 ;
} else
goto V_125;
if ( ( V_124 == V_134 ) || ( V_124 == V_135 ) ) {
V_34 = - V_138 ;
F_103 (slot, kvm->memslots) {
if ( ( V_122 -> V_32 >= V_128 ) ||
( V_122 -> V_32 == V_114 -> V_122 ) )
continue;
if ( ! ( ( V_121 + V_90 <= V_122 -> V_121 ) ||
( V_121 >= V_122 -> V_121 + V_122 -> V_90 ) ) )
goto V_125;
}
}
if ( ! ( V_109 . V_118 & V_116 ) )
V_109 . V_88 = NULL ;
V_34 = - V_39 ;
if ( V_124 == V_134 ) {
V_109 . V_129 = V_114 -> V_129 ;
if ( F_137 ( V_15 , & V_109 , V_90 ) )
goto V_139;
}
if ( ( V_109 . V_118 & V_116 ) && ! V_109 . V_88 ) {
if ( F_122 ( & V_109 ) < 0 )
goto V_139;
}
if ( ( V_124 == V_137 ) || ( V_124 == V_135 ) ) {
V_34 = - V_39 ;
V_62 = F_138 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_139;
V_122 = F_129 ( V_62 , V_114 -> V_122 ) ;
V_122 -> V_118 |= V_140 ;
V_120 = F_132 ( V_15 , V_62 , NULL ) ;
F_139 ( V_15 , & V_111 ) ;
F_140 ( V_15 , V_122 ) ;
V_62 = V_120 ;
}
V_34 = F_141 ( V_15 , & V_109 , V_114 , V_124 ) ;
if ( V_34 )
goto V_141;
V_34 = - V_39 ;
if ( ! V_62 ) {
V_62 = F_138 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_139;
}
if ( V_124 == V_137 ) {
V_109 . V_88 = NULL ;
memset ( & V_109 . V_142 , 0 , sizeof( V_109 . V_142 ) ) ;
}
V_120 = F_132 ( V_15 , V_62 , & V_109 ) ;
F_142 ( V_15 , V_114 , & V_111 , V_124 ) ;
F_100 ( V_15 , & V_111 , & V_109 ) ;
F_92 ( V_120 ) ;
if ( ( V_124 == V_134 ) || ( V_124 == V_135 ) ) {
V_34 = F_143 ( V_15 , & V_109 ) ;
return V_34 ;
}
return 0 ;
V_141:
F_92 ( V_62 ) ;
V_139:
F_100 ( V_15 , & V_109 , & V_111 ) ;
V_125:
return V_34 ;
}
int F_144 ( struct V_15 * V_15 ,
struct V_113 * V_114 )
{
int V_34 ;
F_145 ( & V_15 -> V_78 ) ;
V_34 = F_135 ( V_15 , V_114 ) ;
F_21 ( & V_15 -> V_78 ) ;
return V_34 ;
}
int F_146 ( struct V_15 * V_15 ,
struct V_113 * V_114 )
{
if ( V_114 -> V_122 >= V_128 )
return - V_119 ;
return F_144 ( V_15 , V_114 ) ;
}
int F_147 ( struct V_15 * V_15 ,
struct V_143 * log , int * V_144 )
{
struct V_86 * V_87 ;
int V_34 , V_17 ;
unsigned long V_145 ;
unsigned long V_146 = 0 ;
V_34 = - V_119 ;
if ( log -> V_122 >= V_128 )
goto V_125;
V_87 = F_129 ( V_15 -> V_63 , log -> V_122 ) ;
V_34 = - V_147 ;
if ( ! V_87 -> V_88 )
goto V_125;
V_145 = F_124 ( V_87 ) ;
for ( V_17 = 0 ; ! V_146 && V_17 < V_145 / sizeof( long ) ; ++ V_17 )
V_146 = V_87 -> V_88 [ V_17 ] ;
V_34 = - V_148 ;
if ( F_148 ( log -> V_88 , V_87 -> V_88 , V_145 ) )
goto V_125;
if ( V_146 )
* V_144 = 1 ;
V_34 = 0 ;
V_125:
return V_34 ;
}
bool F_149 ( void )
{
return V_149 ;
}
void F_150 ( void )
{
V_149 = false ;
}
struct V_86 * F_151 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_152 ( V_61 ( V_15 ) , V_150 ) ;
}
int F_153 ( struct V_15 * V_15 , T_6 V_150 )
{
struct V_86 * V_87 = F_151 ( V_15 , V_150 ) ;
if ( ! V_87 || V_87 -> V_32 >= V_128 ||
V_87 -> V_118 & V_140 )
return 0 ;
return 1 ;
}
unsigned long F_154 ( struct V_15 * V_15 , T_6 V_150 )
{
struct V_151 * V_152 ;
unsigned long V_85 , V_83 ;
V_83 = V_84 ;
V_85 = F_155 ( V_15 , V_150 ) ;
if ( F_156 ( V_85 ) )
return V_84 ;
F_157 ( & V_8 -> V_47 -> V_153 ) ;
V_152 = F_158 ( V_8 -> V_47 , V_85 ) ;
if ( ! V_152 )
goto V_125;
V_83 = F_159 ( V_152 ) ;
V_125:
F_160 ( & V_8 -> V_47 -> V_153 ) ;
return V_83 ;
}
static bool F_161 ( struct V_86 * V_122 )
{
return V_122 -> V_118 & V_117 ;
}
static unsigned long F_162 ( struct V_86 * V_122 , T_6 V_150 ,
T_6 * V_154 , bool V_155 )
{
if ( ! V_122 || V_122 -> V_118 & V_140 )
return V_156 ;
if ( F_161 ( V_122 ) && V_155 )
return V_157 ;
if ( V_154 )
* V_154 = V_122 -> V_90 - ( V_150 - V_122 -> V_121 ) ;
return F_163 ( V_122 , V_150 ) ;
}
static unsigned long F_164 ( struct V_86 * V_122 , T_6 V_150 ,
T_6 * V_154 )
{
return F_162 ( V_122 , V_150 , V_154 , true ) ;
}
unsigned long F_165 ( struct V_86 * V_122 ,
T_6 V_150 )
{
return F_164 ( V_122 , V_150 , NULL ) ;
}
unsigned long F_155 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_164 ( F_151 ( V_15 , V_150 ) , V_150 , NULL ) ;
}
unsigned long F_166 ( struct V_15 * V_15 , T_6 V_150 , bool * V_158 )
{
struct V_86 * V_122 = F_151 ( V_15 , V_150 ) ;
unsigned long V_159 = F_162 ( V_122 , V_150 , NULL , false ) ;
if ( ! F_156 ( V_159 ) && V_158 )
* V_158 = ! F_161 ( V_122 ) ;
return V_159 ;
}
static int F_167 ( void * V_160 , void V_131 * V_159 , int V_161 )
{
return F_168 ( V_160 , V_159 , V_161 ) ;
}
static int F_169 ( void * V_160 , void V_131 * V_159 , int V_161 )
{
return F_170 ( V_160 , V_159 , V_161 ) ;
}
static int F_171 ( struct V_162 * V_163 , struct V_46 * V_47 ,
unsigned long V_55 , int V_155 , struct V_33 * * V_33 )
{
int V_118 = V_164 | V_165 | V_166 | V_167 ;
if ( V_155 )
V_118 |= V_168 ;
return F_172 ( V_163 , V_47 , V_55 , 1 , V_118 , V_33 , NULL , NULL ) ;
}
static inline int F_173 ( unsigned long V_85 )
{
int V_169 , V_118 = V_164 | V_166 | V_168 ;
V_169 = F_172 ( V_8 , V_8 -> V_47 , V_85 , 1 ,
V_118 , NULL , NULL , NULL ) ;
return V_169 == - V_170 ;
}
static bool F_174 ( unsigned long V_85 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_158 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_90 ;
if ( ! ( V_172 || V_171 ) )
return false ;
if ( ! ( V_173 || V_158 ) )
return false ;
V_90 = F_175 ( V_85 , 1 , 1 , V_33 ) ;
if ( V_90 == 1 ) {
* V_1 = F_176 ( V_33 [ 0 ] ) ;
if ( V_158 )
* V_158 = true ;
return true ;
}
return false ;
}
static int F_177 ( unsigned long V_85 , bool * V_172 , bool V_173 ,
bool * V_158 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_90 = 0 ;
F_178 () ;
if ( V_158 )
* V_158 = V_173 ;
if ( V_172 ) {
F_157 ( & V_8 -> V_47 -> V_153 ) ;
V_90 = F_171 ( V_8 , V_8 -> V_47 ,
V_85 , V_173 , V_33 ) ;
F_160 ( & V_8 -> V_47 -> V_153 ) ;
} else
V_90 = F_179 ( V_85 , 1 , V_173 ,
V_33 ) ;
if ( V_90 != 1 )
return V_90 ;
if ( F_7 ( ! V_173 ) && V_158 ) {
struct V_33 * V_174 [ 1 ] ;
V_90 = F_175 ( V_85 , 1 , 1 , V_174 ) ;
if ( V_90 == 1 ) {
* V_158 = true ;
F_180 ( V_33 [ 0 ] ) ;
V_33 [ 0 ] = V_174 [ 0 ] ;
}
V_90 = 1 ;
}
* V_1 = F_176 ( V_33 [ 0 ] ) ;
return V_90 ;
}
static bool F_181 ( struct V_151 * V_152 , bool V_173 )
{
if ( F_7 ( ! ( V_152 -> V_175 & V_176 ) ) )
return false ;
if ( V_173 && ( F_7 ( ! ( V_152 -> V_175 & V_177 ) ) ) )
return false ;
return true ;
}
static T_1 F_182 ( unsigned long V_85 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_158 )
{
struct V_151 * V_152 ;
T_1 V_1 = 0 ;
int V_90 ;
F_64 ( V_171 && V_172 ) ;
if ( F_174 ( V_85 , V_171 , V_172 , V_173 , V_158 , & V_1 ) )
return V_1 ;
if ( V_171 )
return V_178 ;
V_90 = F_177 ( V_85 , V_172 , V_173 , V_158 , & V_1 ) ;
if ( V_90 == 1 )
return V_1 ;
F_157 ( & V_8 -> V_47 -> V_153 ) ;
if ( V_90 == - V_170 ||
( ! V_172 && F_173 ( V_85 ) ) ) {
V_1 = V_179 ;
goto exit;
}
V_152 = F_183 ( V_8 -> V_47 , V_85 , V_85 + 1 ) ;
if ( V_152 == NULL )
V_1 = V_178 ;
else if ( ( V_152 -> V_175 & V_180 ) ) {
V_1 = ( ( V_85 - V_152 -> V_181 ) >> V_132 ) +
V_152 -> V_182 ;
F_64 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_172 && F_181 ( V_152 , V_173 ) )
* V_172 = true ;
V_1 = V_178 ;
}
exit:
F_160 ( & V_8 -> V_47 -> V_153 ) ;
return V_1 ;
}
static T_1
F_184 ( struct V_86 * V_122 , T_6 V_150 , bool V_171 ,
bool * V_172 , bool V_173 , bool * V_158 )
{
unsigned long V_85 = F_162 ( V_122 , V_150 , NULL , V_173 ) ;
if ( V_85 == V_157 )
return V_183 ;
if ( F_156 ( V_85 ) )
return V_184 ;
if ( V_158 && F_161 ( V_122 ) ) {
* V_158 = false ;
V_158 = NULL ;
}
return F_182 ( V_85 , V_171 , V_172 , V_173 ,
V_158 ) ;
}
static T_1 F_185 ( struct V_15 * V_15 , T_6 V_150 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_158 )
{
struct V_86 * V_122 ;
if ( V_172 )
* V_172 = false ;
V_122 = F_151 ( V_15 , V_150 ) ;
return F_184 ( V_122 , V_150 , V_171 , V_172 , V_173 ,
V_158 ) ;
}
T_1 F_186 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_185 ( V_15 , V_150 , true , NULL , true , NULL ) ;
}
T_1 F_187 ( struct V_15 * V_15 , T_6 V_150 , bool * V_172 ,
bool V_173 , bool * V_158 )
{
return F_185 ( V_15 , V_150 , false , V_172 , V_173 , V_158 ) ;
}
T_1 F_188 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_185 ( V_15 , V_150 , false , NULL , true , NULL ) ;
}
T_1 F_189 ( struct V_15 * V_15 , T_6 V_150 , bool V_173 ,
bool * V_158 )
{
return F_185 ( V_15 , V_150 , false , NULL , V_173 , V_158 ) ;
}
T_1 F_190 ( struct V_86 * V_122 , T_6 V_150 )
{
return F_184 ( V_122 , V_150 , false , NULL , true , NULL ) ;
}
T_1 F_191 ( struct V_86 * V_122 , T_6 V_150 )
{
return F_184 ( V_122 , V_150 , true , NULL , true , NULL ) ;
}
int F_192 ( struct V_15 * V_15 , T_6 V_150 , struct V_33 * * V_185 ,
int V_154 )
{
unsigned long V_85 ;
T_6 V_186 ;
V_85 = F_164 ( F_151 ( V_15 , V_150 ) , V_150 , & V_186 ) ;
if ( F_156 ( V_85 ) )
return - 1 ;
if ( V_186 < V_154 )
return 0 ;
return F_175 ( V_85 , V_154 , 1 , V_185 ) ;
}
static struct V_33 * F_193 ( T_1 V_1 )
{
if ( F_194 ( V_1 ) )
return V_187 ;
if ( F_1 ( V_1 ) ) {
F_195 ( 1 ) ;
return V_187 ;
}
return F_4 ( V_1 ) ;
}
struct V_33 * F_196 ( struct V_15 * V_15 , T_6 V_150 )
{
T_1 V_1 ;
V_1 = F_188 ( V_15 , V_150 ) ;
return F_193 ( V_1 ) ;
}
void F_197 ( struct V_33 * V_33 )
{
F_195 ( F_198 ( V_33 ) ) ;
F_199 ( F_176 ( V_33 ) ) ;
}
void F_199 ( T_1 V_1 )
{
if ( ! F_194 ( V_1 ) && ! F_1 ( V_1 ) )
F_180 ( F_4 ( V_1 ) ) ;
}
void F_200 ( struct V_33 * V_33 )
{
F_195 ( F_198 ( V_33 ) ) ;
F_201 ( F_176 ( V_33 ) ) ;
}
void F_201 ( T_1 V_1 )
{
F_202 ( V_1 ) ;
F_199 ( V_1 ) ;
}
void F_203 ( struct V_33 * V_33 )
{
F_202 ( F_176 ( V_33 ) ) ;
}
void F_202 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_33 * V_33 = F_4 ( V_1 ) ;
if ( ! F_3 ( V_33 ) )
F_204 ( V_33 ) ;
}
}
void F_205 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_206 ( F_4 ( V_1 ) ) ;
}
void F_207 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_208 ( F_4 ( V_1 ) ) ;
}
static int F_209 ( unsigned long V_161 , int V_188 )
{
if ( V_161 > V_84 - V_188 )
return V_84 - V_188 ;
else
return V_161 ;
}
int F_210 ( struct V_15 * V_15 , T_6 V_150 , void * V_160 , int V_188 ,
int V_161 )
{
int V_34 ;
unsigned long V_85 ;
V_85 = F_166 ( V_15 , V_150 , NULL ) ;
if ( F_156 ( V_85 ) )
return - V_148 ;
V_34 = F_167 ( V_160 , ( void V_131 * ) V_85 + V_188 , V_161 ) ;
if ( V_34 )
return - V_148 ;
return 0 ;
}
int F_211 ( struct V_15 * V_15 , T_7 V_189 , void * V_160 , unsigned long V_161 )
{
T_6 V_150 = V_189 >> V_132 ;
int V_190 ;
int V_188 = F_212 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_161 , V_188 ) ) != 0 ) {
V_191 = F_210 ( V_15 , V_150 , V_160 , V_188 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_188 = 0 ;
V_161 -= V_190 ;
V_160 += V_190 ;
++ V_150 ;
}
return 0 ;
}
int F_213 ( struct V_15 * V_15 , T_7 V_189 , void * V_160 ,
unsigned long V_161 )
{
int V_34 ;
unsigned long V_85 ;
T_6 V_150 = V_189 >> V_132 ;
int V_188 = F_212 ( V_189 ) ;
V_85 = F_166 ( V_15 , V_150 , NULL ) ;
if ( F_156 ( V_85 ) )
return - V_148 ;
F_214 () ;
V_34 = F_169 ( V_160 , ( void V_131 * ) V_85 + V_188 , V_161 ) ;
F_215 () ;
if ( V_34 )
return - V_148 ;
return 0 ;
}
int F_216 ( struct V_15 * V_15 , T_6 V_150 , const void * V_160 ,
int V_188 , int V_161 )
{
int V_34 ;
unsigned long V_85 ;
V_85 = F_155 ( V_15 , V_150 ) ;
if ( F_156 ( V_85 ) )
return - V_148 ;
V_34 = F_217 ( ( void V_131 * ) V_85 + V_188 , V_160 , V_161 ) ;
if ( V_34 )
return - V_148 ;
F_218 ( V_15 , V_150 ) ;
return 0 ;
}
int F_219 ( struct V_15 * V_15 , T_7 V_189 , const void * V_160 ,
unsigned long V_161 )
{
T_6 V_150 = V_189 >> V_132 ;
int V_190 ;
int V_188 = F_212 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_161 , V_188 ) ) != 0 ) {
V_191 = F_216 ( V_15 , V_150 , V_160 , V_188 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_188 = 0 ;
V_161 -= V_190 ;
V_160 += V_190 ;
++ V_150 ;
}
return 0 ;
}
int F_220 ( struct V_15 * V_15 , struct V_192 * V_193 ,
T_7 V_189 , unsigned long V_161 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_188 = F_212 ( V_189 ) ;
T_6 V_194 = V_189 >> V_132 ;
T_6 V_195 = ( V_189 + V_161 - 1 ) >> V_132 ;
T_6 V_196 = V_195 - V_194 + 1 ;
T_6 V_197 ;
V_193 -> V_189 = V_189 ;
V_193 -> V_112 = V_62 -> V_112 ;
V_193 -> V_161 = V_161 ;
V_193 -> V_87 = F_151 ( V_15 , V_194 ) ;
V_193 -> V_159 = F_164 ( V_193 -> V_87 , V_194 , & V_197 ) ;
if ( ! F_156 ( V_193 -> V_159 ) && V_197 >= V_196 ) {
V_193 -> V_159 += V_188 ;
} else {
while ( V_194 <= V_195 ) {
V_193 -> V_87 = F_151 ( V_15 , V_194 ) ;
V_193 -> V_159 = F_164 ( V_193 -> V_87 , V_194 ,
& V_197 ) ;
if ( F_156 ( V_193 -> V_159 ) )
return - V_148 ;
V_194 += V_197 ;
}
V_193 -> V_87 = NULL ;
}
return 0 ;
}
int F_221 ( struct V_15 * V_15 , struct V_192 * V_193 ,
void * V_160 , unsigned long V_161 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_64 ( V_161 > V_193 -> V_161 ) ;
if ( V_62 -> V_112 != V_193 -> V_112 )
F_220 ( V_15 , V_193 , V_193 -> V_189 , V_193 -> V_161 ) ;
if ( F_7 ( ! V_193 -> V_87 ) )
return F_219 ( V_15 , V_193 -> V_189 , V_160 , V_161 ) ;
if ( F_156 ( V_193 -> V_159 ) )
return - V_148 ;
V_34 = F_217 ( ( void V_131 * ) V_193 -> V_159 , V_160 , V_161 ) ;
if ( V_34 )
return - V_148 ;
F_222 ( V_15 , V_193 -> V_87 , V_193 -> V_189 >> V_132 ) ;
return 0 ;
}
int F_223 ( struct V_15 * V_15 , struct V_192 * V_193 ,
void * V_160 , unsigned long V_161 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_64 ( V_161 > V_193 -> V_161 ) ;
if ( V_62 -> V_112 != V_193 -> V_112 )
F_220 ( V_15 , V_193 , V_193 -> V_189 , V_193 -> V_161 ) ;
if ( F_7 ( ! V_193 -> V_87 ) )
return F_211 ( V_15 , V_193 -> V_189 , V_160 , V_161 ) ;
if ( F_156 ( V_193 -> V_159 ) )
return - V_148 ;
V_34 = F_168 ( V_160 , ( void V_131 * ) V_193 -> V_159 , V_161 ) ;
if ( V_34 )
return - V_148 ;
return 0 ;
}
int F_224 ( struct V_15 * V_15 , T_6 V_150 , int V_188 , int V_161 )
{
const void * V_198 = ( const void * ) F_225 ( F_226 ( F_227 ( 0 ) ) ) ;
return F_216 ( V_15 , V_150 , V_198 , V_188 , V_161 ) ;
}
int F_228 ( struct V_15 * V_15 , T_7 V_189 , unsigned long V_161 )
{
T_6 V_150 = V_189 >> V_132 ;
int V_190 ;
int V_188 = F_212 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_209 ( V_161 , V_188 ) ) != 0 ) {
V_191 = F_224 ( V_15 , V_150 , V_188 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_188 = 0 ;
V_161 -= V_190 ;
++ V_150 ;
}
return 0 ;
}
void F_222 ( struct V_15 * V_15 , struct V_86 * V_87 ,
T_6 V_150 )
{
if ( V_87 && V_87 -> V_88 ) {
unsigned long V_199 = V_150 - V_87 -> V_121 ;
F_229 ( V_199 , V_87 -> V_88 ) ;
}
}
void F_218 ( struct V_15 * V_15 , T_6 V_150 )
{
struct V_86 * V_87 ;
V_87 = F_151 ( V_15 , V_150 ) ;
F_222 ( V_15 , V_87 , V_150 ) ;
}
void F_230 ( struct V_2 * V_3 )
{
F_231 ( V_200 ) ;
for (; ; ) {
F_232 ( & V_3 -> V_36 , & V_200 , V_201 ) ;
if ( F_233 ( V_3 ) ) {
F_26 ( V_202 , V_3 ) ;
break;
}
if ( F_234 ( V_3 ) )
break;
if ( F_235 ( V_8 ) )
break;
F_236 () ;
}
F_237 ( & V_3 -> V_36 , & V_200 ) ;
}
void F_238 ( struct V_2 * V_3 )
{
int V_18 ;
int V_4 = V_3 -> V_4 ;
T_8 * V_203 ;
V_203 = F_239 ( V_3 ) ;
if ( F_240 ( V_203 ) ) {
F_241 ( V_203 ) ;
++ V_3 -> V_27 . V_204 ;
}
V_18 = F_12 () ;
if ( V_4 != V_18 && ( unsigned ) V_4 < V_205 && F_242 ( V_4 ) )
if ( F_243 ( V_3 ) )
F_244 ( V_4 ) ;
F_15 () ;
}
void F_245 ( struct V_2 * V_3 )
{
if ( ! F_246 () )
return;
F_247 () ;
}
bool F_248 ( struct V_2 * V_206 )
{
struct V_7 * V_7 ;
struct V_162 * V_207 = NULL ;
bool V_191 = false ;
F_249 () ;
V_7 = F_250 ( V_206 -> V_7 ) ;
if ( V_7 )
V_207 = F_251 ( V_206 -> V_7 , V_10 ) ;
F_252 () ;
if ( ! V_207 )
return V_191 ;
if ( V_207 -> V_118 & V_208 ) {
F_253 ( V_207 ) ;
return V_191 ;
}
V_191 = F_254 ( V_207 , 1 ) ;
F_253 ( V_207 ) ;
return V_191 ;
}
bool F_255 ( struct V_2 * V_3 )
{
bool V_209 ;
V_209 = ! V_3 -> V_210 . V_211 ||
( V_3 -> V_210 . V_211 &&
V_3 -> V_210 . V_212 ) ;
if ( V_3 -> V_210 . V_211 )
F_45 ( V_3 , ! V_3 -> V_210 . V_212 ) ;
return V_209 ;
}
void F_256 ( struct V_2 * V_18 )
{
struct V_15 * V_15 = V_18 -> V_15 ;
struct V_2 * V_3 ;
int V_213 = V_18 -> V_15 -> V_213 ;
int V_214 = 0 ;
int V_215 = 3 ;
int V_216 ;
int V_17 ;
F_44 ( V_18 , true ) ;
for ( V_216 = 0 ; V_216 < 2 && ! V_214 && V_215 ; V_216 ++ ) {
F_25 (i, vcpu, kvm) {
if ( ! V_216 && V_17 <= V_213 ) {
V_17 = V_213 ;
continue;
} else if ( V_216 && V_17 > V_213 )
break;
if ( ! F_257 ( V_3 -> V_42 ) )
continue;
if ( V_3 == V_18 )
continue;
if ( F_240 ( & V_3 -> V_36 ) )
continue;
if ( ! F_255 ( V_3 ) )
continue;
V_214 = F_248 ( V_3 ) ;
if ( V_214 > 0 ) {
V_15 -> V_213 = V_17 ;
break;
} else if ( V_214 < 0 ) {
V_215 -- ;
if ( ! V_215 )
break;
}
}
}
F_44 ( V_18 , false ) ;
F_45 ( V_18 , false ) ;
}
static int F_258 ( struct V_151 * V_152 , struct V_217 * V_218 )
{
struct V_2 * V_3 = V_152 -> V_219 -> V_103 ;
struct V_33 * V_33 ;
if ( V_218 -> V_220 == 0 )
V_33 = F_259 ( V_3 -> V_41 ) ;
#ifdef F_260
else if ( V_218 -> V_220 == V_221 )
V_33 = F_259 ( V_3 -> V_142 . V_222 ) ;
#endif
#ifdef F_261
else if ( V_218 -> V_220 == F_261 )
V_33 = F_259 ( V_3 -> V_15 -> V_223 ) ;
#endif
else
return F_262 ( V_3 , V_218 ) ;
F_208 ( V_33 ) ;
V_218 -> V_33 = V_33 ;
return 0 ;
}
static int F_263 ( struct V_101 * V_101 , struct V_151 * V_152 )
{
V_152 -> V_224 = & V_225 ;
return 0 ;
}
static int F_264 ( struct V_100 * V_100 , struct V_101 * V_102 )
{
struct V_2 * V_3 = V_102 -> V_103 ;
F_118 ( V_3 -> V_15 ) ;
return 0 ;
}
static int F_265 ( struct V_2 * V_3 )
{
return F_266 ( L_1 , & V_226 , V_3 , V_227 | V_228 ) ;
}
static int F_267 ( struct V_15 * V_15 , T_5 V_32 )
{
int V_34 ;
struct V_2 * V_3 , * V_229 ;
if ( V_32 >= V_230 )
return - V_119 ;
V_3 = F_268 ( V_15 , V_32 ) ;
if ( F_269 ( V_3 ) )
return F_270 ( V_3 ) ;
F_271 ( & V_3 -> V_13 , & V_231 ) ;
V_34 = F_272 ( V_3 ) ;
if ( V_34 )
goto V_232;
F_145 ( & V_15 -> V_76 ) ;
if ( ! F_273 ( V_3 ) ) {
V_34 = - V_119 ;
goto V_233;
}
if ( F_274 ( & V_15 -> V_234 ) == V_230 ) {
V_34 = - V_119 ;
goto V_233;
}
F_25 (r, v, kvm)
if ( V_229 -> V_35 == V_32 ) {
V_34 = - V_138 ;
goto V_233;
}
F_64 ( V_15 -> V_235 [ F_274 ( & V_15 -> V_234 ) ] ) ;
F_117 ( V_15 ) ;
V_34 = F_265 ( V_3 ) ;
if ( V_34 < 0 ) {
F_118 ( V_15 ) ;
goto V_233;
}
V_15 -> V_235 [ F_274 ( & V_15 -> V_234 ) ] = V_3 ;
F_63 () ;
F_85 ( & V_15 -> V_234 ) ;
F_21 ( & V_15 -> V_76 ) ;
F_275 ( V_3 ) ;
return V_34 ;
V_233:
F_21 ( & V_15 -> V_76 ) ;
V_232:
F_276 ( V_3 ) ;
return V_34 ;
}
static int F_277 ( struct V_2 * V_3 , T_9 * V_236 )
{
if ( V_236 ) {
F_278 ( V_236 , F_279 ( V_237 ) | F_279 ( V_238 ) ) ;
V_3 -> V_239 = 1 ;
V_3 -> V_236 = * V_236 ;
} else
V_3 -> V_239 = 0 ;
return 0 ;
}
static long F_280 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_2 * V_3 = V_102 -> V_103 ;
void V_131 * V_242 = ( void V_131 * ) V_241 ;
int V_34 ;
struct V_243 * V_244 = NULL ;
struct V_245 * V_245 = NULL ;
if ( V_3 -> V_15 -> V_47 != V_8 -> V_47 )
return - V_246 ;
#if F_113 ( F_123 ) || F_113 ( V_247 ) || F_113 ( V_248 )
if ( V_240 == V_249 || V_240 == V_250 )
return F_281 ( V_102 , V_240 , V_241 ) ;
#endif
V_34 = F_5 ( V_3 ) ;
if ( V_34 )
return V_34 ;
switch ( V_240 ) {
case V_251 :
V_34 = - V_119 ;
if ( V_241 )
goto V_125;
V_34 = F_282 ( V_3 , V_3 -> V_41 ) ;
F_283 ( V_3 -> V_41 -> V_252 , V_34 ) ;
break;
case V_253 : {
struct V_254 * V_254 ;
V_34 = - V_39 ;
V_254 = F_82 ( sizeof( struct V_254 ) , V_37 ) ;
if ( ! V_254 )
goto V_125;
V_34 = F_284 ( V_3 , V_254 ) ;
if ( V_34 )
goto V_255;
V_34 = - V_148 ;
if ( F_148 ( V_242 , V_254 , sizeof( struct V_254 ) ) )
goto V_255;
V_34 = 0 ;
V_255:
F_92 ( V_254 ) ;
break;
}
case V_256 : {
struct V_254 * V_254 ;
V_34 = - V_39 ;
V_254 = F_285 ( V_242 , sizeof( * V_254 ) ) ;
if ( F_269 ( V_254 ) ) {
V_34 = F_270 ( V_254 ) ;
goto V_125;
}
V_34 = F_286 ( V_3 , V_254 ) ;
F_92 ( V_254 ) ;
break;
}
case V_257 : {
V_245 = F_82 ( sizeof( struct V_245 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_245 )
goto V_125;
V_34 = F_287 ( V_3 , V_245 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_148 ( V_242 , V_245 , sizeof( struct V_245 ) ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_258 : {
V_245 = F_285 ( V_242 , sizeof( * V_245 ) ) ;
if ( F_269 ( V_245 ) ) {
V_34 = F_270 ( V_245 ) ;
V_245 = NULL ;
goto V_125;
}
V_34 = F_288 ( V_3 , V_245 ) ;
break;
}
case V_259 : {
struct V_260 V_261 ;
V_34 = F_289 ( V_3 , & V_261 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_148 ( V_242 , & V_261 , sizeof V_261 ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_262 : {
struct V_260 V_261 ;
V_34 = - V_148 ;
if ( F_290 ( & V_261 , V_242 , sizeof V_261 ) )
goto V_125;
V_34 = F_291 ( V_3 , & V_261 ) ;
break;
}
case V_263 : {
struct V_264 V_265 ;
V_34 = - V_148 ;
if ( F_290 ( & V_265 , V_242 , sizeof V_265 ) )
goto V_125;
V_34 = F_292 ( V_3 , & V_265 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_148 ( V_242 , & V_265 , sizeof V_265 ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_266 : {
struct V_267 V_268 ;
V_34 = - V_148 ;
if ( F_290 ( & V_268 , V_242 , sizeof V_268 ) )
goto V_125;
V_34 = F_293 ( V_3 , & V_268 ) ;
break;
}
case V_269 : {
struct V_270 V_131 * V_271 = V_242 ;
struct V_270 V_272 ;
T_9 V_236 , * V_273 ;
V_273 = NULL ;
if ( V_242 ) {
V_34 = - V_148 ;
if ( F_290 ( & V_272 , V_242 ,
sizeof V_272 ) )
goto V_125;
V_34 = - V_119 ;
if ( V_272 . V_161 != sizeof V_236 )
goto V_125;
V_34 = - V_148 ;
if ( F_290 ( & V_236 , V_271 -> V_236 ,
sizeof V_236 ) )
goto V_125;
V_273 = & V_236 ;
}
V_34 = F_277 ( V_3 , V_273 ) ;
break;
}
case V_274 : {
V_244 = F_82 ( sizeof( struct V_243 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_244 )
goto V_125;
V_34 = F_294 ( V_3 , V_244 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_148 ( V_242 , V_244 , sizeof( struct V_243 ) ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_275 : {
V_244 = F_285 ( V_242 , sizeof( * V_244 ) ) ;
if ( F_269 ( V_244 ) ) {
V_34 = F_270 ( V_244 ) ;
V_244 = NULL ;
goto V_125;
}
V_34 = F_295 ( V_3 , V_244 ) ;
break;
}
default:
V_34 = F_281 ( V_102 , V_240 , V_241 ) ;
}
V_125:
F_16 ( V_3 ) ;
F_92 ( V_244 ) ;
F_92 ( V_245 ) ;
return V_34 ;
}
static long F_296 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_2 * V_3 = V_102 -> V_103 ;
void V_131 * V_242 = F_297 ( V_241 ) ;
int V_34 ;
if ( V_3 -> V_15 -> V_47 != V_8 -> V_47 )
return - V_246 ;
switch ( V_240 ) {
case V_269 : {
struct V_270 V_131 * V_271 = V_242 ;
struct V_270 V_272 ;
T_10 V_276 ;
T_9 V_236 ;
if ( V_242 ) {
V_34 = - V_148 ;
if ( F_290 ( & V_272 , V_242 ,
sizeof V_272 ) )
goto V_125;
V_34 = - V_119 ;
if ( V_272 . V_161 != sizeof V_276 )
goto V_125;
V_34 = - V_148 ;
if ( F_290 ( & V_276 , V_271 -> V_236 ,
sizeof V_276 ) )
goto V_125;
F_298 ( & V_236 , & V_276 ) ;
V_34 = F_277 ( V_3 , & V_236 ) ;
} else
V_34 = F_277 ( V_3 , NULL ) ;
break;
}
default:
V_34 = F_280 ( V_102 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static int F_299 ( struct V_94 * V_95 ,
int (* F_300)( struct V_94 * V_95 ,
struct V_277 * V_278 ) ,
unsigned long V_241 )
{
struct V_277 V_278 ;
if ( ! F_300 )
return - V_279 ;
if ( F_290 ( & V_278 , ( void V_131 * ) V_241 , sizeof( V_278 ) ) )
return - V_148 ;
return F_300 ( V_95 , & V_278 ) ;
}
static long F_301 ( struct V_101 * V_102 , unsigned int V_240 ,
unsigned long V_241 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
switch ( V_240 ) {
case V_280 :
return F_299 ( V_95 , V_95 -> V_59 -> V_281 , V_241 ) ;
case V_282 :
return F_299 ( V_95 , V_95 -> V_59 -> V_283 , V_241 ) ;
case V_284 :
return F_299 ( V_95 , V_95 -> V_59 -> V_285 , V_241 ) ;
default:
if ( V_95 -> V_59 -> V_240 )
return V_95 -> V_59 -> V_240 ( V_95 , V_240 , V_241 ) ;
return - V_286 ;
}
}
static int F_302 ( struct V_100 * V_100 , struct V_101 * V_102 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_15 * V_15 = V_95 -> V_15 ;
F_118 ( V_15 ) ;
return 0 ;
}
struct V_94 * F_303 ( struct V_101 * V_102 )
{
if ( V_102 -> V_287 != & V_288 )
return NULL ;
return V_102 -> V_103 ;
}
static int F_304 ( struct V_15 * V_15 ,
struct V_289 * V_290 )
{
struct V_291 * V_59 = NULL ;
struct V_94 * V_95 ;
bool V_292 = V_290 -> V_118 & V_293 ;
int V_191 ;
switch ( V_290 -> type ) {
#ifdef F_305
case V_294 :
case V_295 :
V_59 = & V_296 ;
break;
#endif
#ifdef F_306
case V_297 :
V_59 = & V_298 ;
break;
#endif
#ifdef F_307
case V_299 :
V_59 = & V_300 ;
break;
#endif
default:
return - V_301 ;
}
if ( V_292 )
return 0 ;
V_95 = F_82 ( sizeof( * V_95 ) , V_37 ) ;
if ( ! V_95 )
return - V_39 ;
V_95 -> V_59 = V_59 ;
V_95 -> V_15 = V_15 ;
V_191 = V_59 -> V_302 ( V_95 , V_290 -> type ) ;
if ( V_191 < 0 ) {
F_92 ( V_95 ) ;
return V_191 ;
}
V_191 = F_266 ( V_59 -> V_303 , & V_288 , V_95 , V_227 | V_228 ) ;
if ( V_191 < 0 ) {
V_59 -> V_97 ( V_95 ) ;
return V_191 ;
}
F_89 ( & V_95 -> V_96 , & V_15 -> V_80 ) ;
F_117 ( V_15 ) ;
V_290 -> V_304 = V_191 ;
return 0 ;
}
static long F_308 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_15 * V_15 = V_102 -> V_103 ;
void V_131 * V_242 = ( void V_131 * ) V_241 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_246 ;
switch ( V_240 ) {
case V_305 :
V_34 = F_267 ( V_15 , V_241 ) ;
break;
case V_306 : {
struct V_113 V_307 ;
V_34 = - V_148 ;
if ( F_290 ( & V_307 , V_242 ,
sizeof V_307 ) )
goto V_125;
V_34 = F_146 ( V_15 , & V_307 ) ;
break;
}
case V_308 : {
struct V_143 log ;
V_34 = - V_148 ;
if ( F_290 ( & log , V_242 , sizeof log ) )
goto V_125;
V_34 = F_309 ( V_15 , & log ) ;
break;
}
#ifdef F_261
case V_309 : {
struct V_310 V_311 ;
V_34 = - V_148 ;
if ( F_290 ( & V_311 , V_242 , sizeof V_311 ) )
goto V_125;
V_34 = F_310 ( V_15 , & V_311 ) ;
break;
}
case V_312 : {
struct V_310 V_311 ;
V_34 = - V_148 ;
if ( F_290 ( & V_311 , V_242 , sizeof V_311 ) )
goto V_125;
V_34 = F_311 ( V_15 , & V_311 ) ;
break;
}
#endif
case V_313 : {
struct V_314 V_160 ;
V_34 = - V_148 ;
if ( F_290 ( & V_160 , V_242 , sizeof V_160 ) )
goto V_125;
V_34 = V_314 ( V_15 , & V_160 ) ;
break;
}
case V_315 : {
struct V_316 V_160 ;
V_34 = - V_148 ;
if ( F_290 ( & V_160 , V_242 , sizeof V_160 ) )
goto V_125;
V_34 = V_316 ( V_15 , & V_160 ) ;
break;
}
#ifdef F_312
case V_317 :
V_34 = 0 ;
F_145 ( & V_15 -> V_76 ) ;
if ( F_274 ( & V_15 -> V_234 ) != 0 )
V_34 = - V_318 ;
else
V_15 -> V_319 = V_241 ;
F_21 ( & V_15 -> V_76 ) ;
break;
#endif
#ifdef F_313
case V_320 : {
struct V_321 V_322 ;
V_34 = - V_148 ;
if ( F_290 ( & V_322 , V_242 , sizeof V_322 ) )
goto V_125;
V_34 = F_314 ( V_15 , & V_322 ) ;
break;
}
#endif
#ifdef F_315
case V_323 :
case V_324 : {
struct V_325 V_326 ;
V_34 = - V_148 ;
if ( F_290 ( & V_326 , V_242 , sizeof V_326 ) )
goto V_125;
V_34 = F_316 ( V_15 , & V_326 ,
V_240 == V_323 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( V_240 == V_323 ) {
if ( F_148 ( V_242 , & V_326 , sizeof V_326 ) )
goto V_125;
}
V_34 = 0 ;
break;
}
#endif
#ifdef F_317
case V_327 : {
struct V_328 V_329 ;
struct V_328 V_131 * V_330 ;
struct V_331 * V_332 ;
V_34 = - V_148 ;
if ( F_290 ( & V_329 , V_242 , sizeof( V_329 ) ) )
goto V_125;
V_34 = - V_119 ;
if ( V_329 . V_333 >= V_334 )
goto V_125;
if ( V_329 . V_118 )
goto V_125;
V_34 = - V_39 ;
V_332 = F_318 ( V_329 . V_333 * sizeof( * V_332 ) ) ;
if ( ! V_332 )
goto V_125;
V_34 = - V_148 ;
V_330 = V_242 ;
if ( F_290 ( V_332 , V_330 -> V_332 ,
V_329 . V_333 * sizeof( * V_332 ) ) )
goto V_335;
V_34 = F_319 ( V_15 , V_332 , V_329 . V_333 ,
V_329 . V_118 ) ;
V_335:
F_98 ( V_332 ) ;
break;
}
#endif
case V_336 : {
struct V_289 V_290 ;
V_34 = - V_148 ;
if ( F_290 ( & V_290 , V_242 , sizeof( V_290 ) ) )
goto V_125;
V_34 = F_304 ( V_15 , & V_290 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_148 ( V_242 , & V_290 , sizeof( V_290 ) ) )
goto V_125;
V_34 = 0 ;
break;
}
default:
V_34 = F_320 ( V_102 , V_240 , V_241 ) ;
if ( V_34 == - V_286 )
V_34 = F_321 ( V_15 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static long F_322 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_15 * V_15 = V_102 -> V_103 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_246 ;
switch ( V_240 ) {
case V_308 : {
struct V_337 V_338 ;
struct V_143 log ;
V_34 = - V_148 ;
if ( F_290 ( & V_338 , ( void V_131 * ) V_241 ,
sizeof( V_338 ) ) )
goto V_125;
log . V_122 = V_338 . V_122 ;
log . V_339 = V_338 . V_339 ;
log . V_340 = V_338 . V_340 ;
log . V_88 = F_297 ( V_338 . V_88 ) ;
V_34 = F_309 ( V_15 , & log ) ;
break;
}
default:
V_34 = F_308 ( V_102 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static int F_323 ( unsigned long type )
{
int V_34 ;
struct V_15 * V_15 ;
V_15 = F_74 ( type ) ;
if ( F_269 ( V_15 ) )
return F_270 ( V_15 ) ;
#ifdef F_261
V_34 = F_324 ( V_15 ) ;
if ( V_34 < 0 ) {
F_118 ( V_15 ) ;
return V_34 ;
}
#endif
V_34 = F_266 ( L_2 , & V_341 , V_15 , V_227 | V_228 ) ;
if ( V_34 < 0 )
F_118 ( V_15 ) ;
return V_34 ;
}
static long F_325 ( long V_241 )
{
switch ( V_241 ) {
case V_342 :
case V_343 :
case V_344 :
#ifdef F_312
case V_345 :
#endif
case V_346 :
#ifdef F_313
case V_347 :
#endif
#ifdef F_317
case V_348 :
#endif
return 1 ;
#ifdef F_317
case V_349 :
return V_334 ;
#endif
default:
break;
}
return F_326 ( V_241 ) ;
}
static long F_327 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
long V_34 = - V_119 ;
switch ( V_240 ) {
case V_350 :
V_34 = - V_119 ;
if ( V_241 )
goto V_125;
V_34 = V_351 ;
break;
case V_352 :
V_34 = F_323 ( V_241 ) ;
break;
case V_353 :
V_34 = F_325 ( V_241 ) ;
break;
case V_354 :
V_34 = - V_119 ;
if ( V_241 )
goto V_125;
V_34 = V_84 ;
#ifdef F_260
V_34 += V_84 ;
#endif
#ifdef F_261
V_34 += V_84 ;
#endif
break;
case V_355 :
case V_356 :
case V_357 :
V_34 = - V_358 ;
break;
default:
return F_328 ( V_102 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static void F_329 ( void * V_359 )
{
int V_4 = F_330 () ;
int V_34 ;
if ( F_331 ( V_4 , V_360 ) )
return;
F_29 ( V_4 , V_360 ) ;
V_34 = F_332 ( NULL ) ;
if ( V_34 ) {
F_333 ( V_4 , V_360 ) ;
F_85 ( & V_361 ) ;
F_334 ( V_362 L_3
L_4 , V_4 ) ;
}
}
static void F_335 ( void )
{
F_336 ( & V_363 ) ;
if ( V_364 )
F_329 ( NULL ) ;
F_337 ( & V_363 ) ;
}
static void F_338 ( void * V_359 )
{
int V_4 = F_330 () ;
if ( ! F_331 ( V_4 , V_360 ) )
return;
F_333 ( V_4 , V_360 ) ;
F_339 ( NULL ) ;
}
static void F_340 ( void )
{
F_336 ( & V_363 ) ;
if ( V_364 )
F_338 ( NULL ) ;
F_337 ( & V_363 ) ;
}
static void F_341 ( void )
{
F_64 ( ! V_364 ) ;
V_364 -- ;
if ( ! V_364 )
F_342 ( F_338 , NULL , 1 ) ;
}
static void F_91 ( void )
{
F_336 ( & V_363 ) ;
F_341 () ;
F_337 ( & V_363 ) ;
}
static int F_78 ( void )
{
int V_34 = 0 ;
F_336 ( & V_363 ) ;
V_364 ++ ;
if ( V_364 == 1 ) {
F_87 ( & V_361 , 0 ) ;
F_342 ( F_329 , NULL , 1 ) ;
if ( F_274 ( & V_361 ) ) {
F_341 () ;
V_34 = - V_318 ;
}
}
F_337 ( & V_363 ) ;
return V_34 ;
}
static int F_343 ( struct V_365 * V_366 , unsigned long V_367 ,
void * V_229 )
{
int V_4 = ( long ) V_229 ;
V_367 &= ~ V_368 ;
switch ( V_367 ) {
case V_369 :
F_334 ( V_362 L_5 ,
V_4 ) ;
F_340 () ;
break;
case V_370 :
F_334 ( V_362 L_6 ,
V_4 ) ;
F_335 () ;
break;
}
return V_371 ;
}
static int F_344 ( struct V_365 * V_366 , unsigned long V_367 ,
void * V_229 )
{
F_334 ( V_362 L_7 ) ;
V_372 = true ;
F_342 ( F_338 , NULL , 1 ) ;
return V_371 ;
}
static void F_111 ( struct V_73 * V_373 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_373 -> V_374 ; V_17 ++ ) {
struct V_375 * V_376 = V_373 -> V_377 [ V_17 ] . V_95 ;
F_345 ( V_376 ) ;
}
F_92 ( V_373 ) ;
}
static inline int F_346 ( const struct V_378 * V_379 ,
const struct V_378 * V_380 )
{
if ( V_379 -> V_85 < V_380 -> V_85 )
return - 1 ;
if ( V_379 -> V_85 + V_379 -> V_161 > V_380 -> V_85 + V_380 -> V_161 )
return 1 ;
return 0 ;
}
static int F_347 ( const void * V_381 , const void * V_382 )
{
return F_346 ( V_381 , V_382 ) ;
}
static int F_348 ( struct V_73 * V_373 , struct V_375 * V_95 ,
T_7 V_85 , int V_161 )
{
V_373 -> V_377 [ V_373 -> V_374 ++ ] = (struct V_378 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
. V_95 = V_95 ,
} ;
F_127 ( V_373 -> V_377 , V_373 -> V_374 , sizeof( struct V_378 ) ,
F_347 , NULL ) ;
return 0 ;
}
static int F_349 ( struct V_73 * V_373 ,
T_7 V_85 , int V_161 )
{
struct V_378 * V_377 , V_383 ;
int V_384 ;
V_383 = (struct V_378 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_377 = bsearch ( & V_383 , V_373 -> V_377 , V_373 -> V_374 ,
sizeof( struct V_378 ) , F_347 ) ;
if ( V_377 == NULL )
return - V_147 ;
V_384 = V_377 - V_373 -> V_377 ;
while ( V_384 > 0 && F_346 ( & V_383 , & V_373 -> V_377 [ V_384 - 1 ] ) == 0 )
V_384 -- ;
return V_384 ;
}
static int F_350 ( struct V_73 * V_373 ,
struct V_378 * V_377 , const void * V_367 )
{
int V_50 ;
V_50 = F_349 ( V_373 , V_377 -> V_85 , V_377 -> V_161 ) ;
if ( V_50 < 0 )
return - V_358 ;
while ( V_50 < V_373 -> V_374 &&
F_346 ( V_377 , & V_373 -> V_377 [ V_50 ] ) == 0 ) {
if ( ! F_351 ( V_373 -> V_377 [ V_50 ] . V_95 , V_377 -> V_85 ,
V_377 -> V_161 , V_367 ) )
return V_50 ;
V_50 ++ ;
}
return - V_358 ;
}
int F_352 ( struct V_15 * V_15 , enum V_385 V_386 , T_7 V_85 ,
int V_161 , const void * V_367 )
{
struct V_73 * V_373 ;
struct V_378 V_377 ;
int V_34 ;
V_377 = (struct V_378 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_373 = F_353 ( V_15 -> V_72 [ V_386 ] , & V_15 -> V_51 ) ;
V_34 = F_350 ( V_373 , & V_377 , V_367 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_354 ( struct V_15 * V_15 , enum V_385 V_386 , T_7 V_85 ,
int V_161 , const void * V_367 , long V_387 )
{
struct V_73 * V_373 ;
struct V_378 V_377 ;
V_377 = (struct V_378 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_373 = F_353 ( V_15 -> V_72 [ V_386 ] , & V_15 -> V_51 ) ;
if ( ( V_387 >= 0 ) && ( V_387 < V_373 -> V_374 ) &&
( F_346 ( & V_377 , & V_373 -> V_377 [ V_387 ] ) == 0 ) )
if ( ! F_351 ( V_373 -> V_377 [ V_387 ] . V_95 , V_85 , V_161 ,
V_367 ) )
return V_387 ;
return F_350 ( V_373 , & V_377 , V_367 ) ;
}
static int F_355 ( struct V_73 * V_373 , struct V_378 * V_377 ,
void * V_367 )
{
int V_50 ;
V_50 = F_349 ( V_373 , V_377 -> V_85 , V_377 -> V_161 ) ;
if ( V_50 < 0 )
return - V_358 ;
while ( V_50 < V_373 -> V_374 &&
F_346 ( V_377 , & V_373 -> V_377 [ V_50 ] ) == 0 ) {
if ( ! F_356 ( V_373 -> V_377 [ V_50 ] . V_95 , V_377 -> V_85 ,
V_377 -> V_161 , V_367 ) )
return V_50 ;
V_50 ++ ;
}
return - V_358 ;
}
int F_357 ( struct V_15 * V_15 , enum V_385 V_386 , T_7 V_85 ,
int V_161 , void * V_367 )
{
struct V_73 * V_373 ;
struct V_378 V_377 ;
int V_34 ;
V_377 = (struct V_378 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_373 = F_353 ( V_15 -> V_72 [ V_386 ] , & V_15 -> V_51 ) ;
V_34 = F_355 ( V_373 , & V_377 , V_367 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_358 ( struct V_15 * V_15 , enum V_385 V_386 , T_7 V_85 ,
int V_161 , void * V_367 , long V_387 )
{
struct V_73 * V_373 ;
struct V_378 V_377 ;
V_377 = (struct V_378 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_373 = F_353 ( V_15 -> V_72 [ V_386 ] , & V_15 -> V_51 ) ;
if ( ( V_387 >= 0 ) && ( V_387 < V_373 -> V_374 ) &&
( F_346 ( & V_377 , & V_373 -> V_377 [ V_387 ] ) == 0 ) )
if ( ! F_356 ( V_373 -> V_377 [ V_387 ] . V_95 , V_85 , V_161 ,
V_367 ) )
return V_387 ;
return F_355 ( V_373 , & V_377 , V_367 ) ;
}
int F_359 ( struct V_15 * V_15 , enum V_385 V_386 , T_7 V_85 ,
int V_161 , struct V_375 * V_95 )
{
struct V_73 * V_388 , * V_373 ;
V_373 = V_15 -> V_72 [ V_386 ] ;
if ( V_373 -> V_374 - V_373 -> V_389 > V_390 - 1 )
return - V_391 ;
V_388 = F_82 ( sizeof( * V_373 ) + ( ( V_373 -> V_374 + 1 ) *
sizeof( struct V_378 ) ) , V_37 ) ;
if ( ! V_388 )
return - V_39 ;
memcpy ( V_388 , V_373 , sizeof( * V_373 ) + ( V_373 -> V_374 *
sizeof( struct V_378 ) ) ) ;
F_348 ( V_388 , V_95 , V_85 , V_161 ) ;
F_9 ( V_15 -> V_72 [ V_386 ] , V_388 ) ;
F_133 ( & V_15 -> V_51 ) ;
F_92 ( V_373 ) ;
return 0 ;
}
int F_360 ( struct V_15 * V_15 , enum V_385 V_386 ,
struct V_375 * V_95 )
{
int V_17 , V_34 ;
struct V_73 * V_388 , * V_373 ;
V_373 = V_15 -> V_72 [ V_386 ] ;
V_34 = - V_147 ;
for ( V_17 = 0 ; V_17 < V_373 -> V_374 ; V_17 ++ )
if ( V_373 -> V_377 [ V_17 ] . V_95 == V_95 ) {
V_34 = 0 ;
break;
}
if ( V_34 )
return V_34 ;
V_388 = F_82 ( sizeof( * V_373 ) + ( ( V_373 -> V_374 - 1 ) *
sizeof( struct V_378 ) ) , V_37 ) ;
if ( ! V_388 )
return - V_39 ;
memcpy ( V_388 , V_373 , sizeof( * V_373 ) + V_17 * sizeof( struct V_378 ) ) ;
V_388 -> V_374 -- ;
memcpy ( V_388 -> V_377 + V_17 , V_373 -> V_377 + V_17 + 1 ,
( V_388 -> V_374 - V_17 ) * sizeof( struct V_378 ) ) ;
F_9 ( V_15 -> V_72 [ V_386 ] , V_388 ) ;
F_133 ( & V_15 -> V_51 ) ;
F_92 ( V_373 ) ;
return V_34 ;
}
static int F_361 ( void * V_392 , T_4 * V_367 )
{
unsigned V_188 = ( long ) V_392 ;
struct V_15 * V_15 ;
* V_367 = 0 ;
F_54 ( & V_81 ) ;
F_362 ( V_15 , & V_82 , V_82 )
* V_367 += * ( T_5 * ) ( ( void * ) V_15 + V_188 ) ;
F_56 ( & V_81 ) ;
return 0 ;
}
static int F_363 ( void * V_392 , T_4 * V_367 )
{
unsigned V_188 = ( long ) V_392 ;
struct V_15 * V_15 ;
struct V_2 * V_3 ;
int V_17 ;
* V_367 = 0 ;
F_54 ( & V_81 ) ;
F_362 (kvm, &vm_list, vm_list)
F_25 ( V_17 , V_3 , V_15 )
* V_367 += * ( T_5 * ) ( ( void * ) V_3 + V_188 ) ;
F_56 ( & V_81 ) ;
return 0 ;
}
static int F_364 ( void )
{
int V_34 = - V_138 ;
struct V_393 * V_273 ;
V_394 = F_365 ( L_8 , NULL ) ;
if ( V_394 == NULL )
goto V_125;
for ( V_273 = V_395 ; V_273 -> V_303 ; ++ V_273 ) {
V_273 -> V_396 = F_366 ( V_273 -> V_303 , 0444 , V_394 ,
( void * ) ( long ) V_273 -> V_188 ,
V_397 [ V_273 -> V_398 ] ) ;
if ( V_273 -> V_396 == NULL )
goto V_399;
}
return 0 ;
V_399:
F_367 ( V_394 ) ;
V_125:
return V_34 ;
}
static void F_368 ( void )
{
struct V_393 * V_273 ;
for ( V_273 = V_395 ; V_273 -> V_303 ; ++ V_273 )
F_369 ( V_273 -> V_396 ) ;
F_369 ( V_394 ) ;
}
static int F_370 ( void )
{
if ( V_364 )
F_338 ( NULL ) ;
return 0 ;
}
static void F_371 ( void )
{
if ( V_364 ) {
F_195 ( F_372 ( & V_363 ) ) ;
F_329 ( NULL ) ;
}
}
static inline
struct V_2 * F_373 ( struct V_13 * V_400 )
{
return F_51 ( V_400 , struct V_2 , V_13 ) ;
}
static void F_374 ( struct V_13 * V_400 , int V_4 )
{
struct V_2 * V_3 = F_373 ( V_400 ) ;
if ( V_3 -> V_42 )
V_3 -> V_42 = false ;
F_14 ( V_3 , V_4 ) ;
}
static void F_375 ( struct V_13 * V_400 ,
struct V_162 * V_401 )
{
struct V_2 * V_3 = F_373 ( V_400 ) ;
if ( V_8 -> V_402 == V_403 )
V_3 -> V_42 = true ;
F_18 ( V_3 ) ;
}
int F_376 ( void * V_404 , unsigned V_405 , unsigned V_406 ,
struct V_407 * V_407 )
{
int V_34 ;
int V_4 ;
V_34 = F_377 ( V_404 ) ;
if ( V_34 )
goto V_408;
V_34 = F_378 () ;
if ( V_34 )
goto V_409;
if ( ! F_24 ( & V_360 , V_37 ) ) {
V_34 = - V_39 ;
goto V_410;
}
V_34 = F_379 () ;
if ( V_34 < 0 )
goto V_411;
F_380 (cpu) {
F_381 ( V_4 ,
V_412 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_413;
}
V_34 = F_382 ( & V_414 ) ;
if ( V_34 )
goto V_415;
F_383 ( & V_416 ) ;
if ( ! V_406 )
V_406 = F_384 ( struct V_2 ) ;
V_417 = F_385 ( L_9 , V_405 , V_406 ,
0 , NULL ) ;
if ( ! V_417 ) {
V_34 = - V_39 ;
goto V_418;
}
V_34 = F_386 () ;
if ( V_34 )
goto V_139;
V_419 . V_420 = V_407 ;
V_341 . V_420 = V_407 ;
V_226 . V_420 = V_407 ;
V_34 = F_387 ( & V_421 ) ;
if ( V_34 ) {
F_334 ( V_422 L_10 ) ;
goto V_423;
}
F_388 ( & V_424 ) ;
V_231 . V_425 = F_374 ;
V_231 . V_426 = F_375 ;
V_34 = F_364 () ;
if ( V_34 ) {
F_334 ( V_422 L_11 ) ;
goto V_427;
}
return 0 ;
V_427:
F_389 ( & V_424 ) ;
F_390 ( & V_421 ) ;
V_423:
F_391 () ;
V_139:
F_392 ( V_417 ) ;
V_418:
F_393 ( & V_416 ) ;
F_394 ( & V_414 ) ;
V_415:
V_413:
F_395 () ;
V_411:
F_32 ( V_360 ) ;
V_410:
F_396 () ;
V_409:
F_397 () ;
V_408:
return V_34 ;
}
void F_398 ( void )
{
F_368 () ;
F_390 ( & V_421 ) ;
F_392 ( V_417 ) ;
F_391 () ;
F_389 ( & V_424 ) ;
F_393 ( & V_416 ) ;
F_394 ( & V_414 ) ;
F_342 ( F_338 , NULL , 1 ) ;
F_395 () ;
F_397 () ;
F_396 () ;
F_32 ( V_360 ) ;
}
