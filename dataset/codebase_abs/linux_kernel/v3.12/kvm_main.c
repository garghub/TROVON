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
F_89 ( & V_81 ) ;
F_90 ( & V_15 -> V_82 , & V_82 ) ;
F_91 ( & V_81 ) ;
return V_15 ;
V_74:
F_92 ( & V_15 -> V_51 ) ;
V_70:
F_93 () ;
V_66:
for ( V_17 = 0 ; V_17 < V_71 ; V_17 ++ )
F_94 ( V_15 -> V_72 [ V_17 ] ) ;
F_94 ( V_15 -> V_63 ) ;
F_95 ( V_15 ) ;
return F_76 ( V_34 ) ;
}
void * F_96 ( unsigned long V_83 )
{
if ( V_83 > V_84 )
return F_97 ( V_83 ) ;
else
return F_82 ( V_83 , V_37 ) ;
}
void F_98 ( const void * V_85 )
{
if ( F_99 ( V_85 ) )
F_100 ( V_85 ) ;
else
F_94 ( V_85 ) ;
}
static void F_101 ( struct V_86 * V_87 )
{
if ( ! V_87 -> V_88 )
return;
F_98 ( V_87 -> V_88 ) ;
V_87 -> V_88 = NULL ;
}
static void F_102 ( struct V_86 * free ,
struct V_86 * V_89 )
{
if ( ! V_89 || free -> V_88 != V_89 -> V_88 )
F_101 ( free ) ;
F_103 ( free , V_89 ) ;
free -> V_90 = 0 ;
}
void F_104 ( struct V_15 * V_15 )
{
struct V_61 * V_62 = V_15 -> V_63 ;
struct V_86 * V_87 ;
F_105 (memslot, slots)
F_102 ( V_87 , NULL ) ;
F_94 ( V_15 -> V_63 ) ;
}
static void F_106 ( struct V_15 * V_15 )
{
struct V_91 * V_92 , * V_93 ;
F_107 (node, tmp, &kvm->devices) {
struct V_94 * V_95 =
F_108 ( V_92 , struct V_94 , V_96 ) ;
F_109 ( V_92 ) ;
V_95 -> V_59 -> V_97 ( V_95 ) ;
}
}
static void F_110 ( struct V_15 * V_15 )
{
int V_17 ;
struct V_46 * V_47 = V_15 -> V_47 ;
F_111 ( V_15 ) ;
F_89 ( & V_81 ) ;
F_109 ( & V_15 -> V_82 ) ;
F_91 ( & V_81 ) ;
F_112 ( V_15 ) ;
for ( V_17 = 0 ; V_17 < V_71 ; V_17 ++ )
F_113 ( V_15 -> V_72 [ V_17 ] ) ;
F_114 ( V_15 ) ;
#if F_115 ( V_98 ) && F_115 ( V_99 )
F_116 ( & V_15 -> V_44 , V_15 -> V_47 ) ;
#else
F_70 ( V_15 ) ;
#endif
F_117 ( V_15 ) ;
F_106 ( V_15 ) ;
F_104 ( V_15 ) ;
F_92 ( & V_15 -> V_51 ) ;
F_95 ( V_15 ) ;
F_93 () ;
F_118 ( V_47 ) ;
}
void F_119 ( struct V_15 * V_15 )
{
F_85 ( & V_15 -> V_79 ) ;
}
void F_120 ( struct V_15 * V_15 )
{
if ( F_121 ( & V_15 -> V_79 ) )
F_110 ( V_15 ) ;
}
static int F_122 ( struct V_100 * V_100 , struct V_101 * V_102 )
{
struct V_15 * V_15 = V_102 -> V_103 ;
F_123 ( V_15 ) ;
F_120 ( V_15 ) ;
return 0 ;
}
static int F_124 ( struct V_86 * V_87 )
{
#ifndef F_125
unsigned long V_104 = 2 * F_126 ( V_87 ) ;
V_87 -> V_88 = F_96 ( V_104 ) ;
if ( ! V_87 -> V_88 )
return - V_39 ;
#endif
return 0 ;
}
static int F_127 ( const void * V_105 , const void * V_106 )
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
static void F_128 ( struct V_61 * V_62 )
{
int V_17 ;
F_129 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_86 ) , F_127 , NULL ) ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_17 ] . V_32 ] = V_17 ;
}
void F_130 ( struct V_61 * V_62 , struct V_86 * V_109 ,
T_4 V_110 )
{
if ( V_109 ) {
int V_32 = V_109 -> V_32 ;
struct V_86 * V_111 = F_131 ( V_62 , V_32 ) ;
unsigned long V_90 = V_111 -> V_90 ;
* V_111 = * V_109 ;
if ( V_109 -> V_90 != V_90 )
F_128 ( V_62 ) ;
}
V_62 -> V_112 = V_110 + 1 ;
}
static int F_132 ( struct V_113 * V_114 )
{
T_5 V_115 = V_116 ;
#ifdef F_133
V_115 |= V_117 ;
#endif
if ( V_114 -> V_118 & ~ V_115 )
return - V_119 ;
return 0 ;
}
static struct V_61 * F_134 ( struct V_15 * V_15 ,
struct V_61 * V_62 , struct V_86 * V_109 )
{
struct V_61 * V_120 = V_15 -> V_63 ;
F_130 ( V_62 , V_109 , V_15 -> V_63 -> V_112 ) ;
F_9 ( V_15 -> V_63 , V_62 ) ;
F_135 ( & V_15 -> V_51 ) ;
F_136 ( V_15 ) ;
return V_120 ;
}
int F_137 ( struct V_15 * V_15 ,
struct V_113 * V_114 )
{
int V_34 ;
T_6 V_121 ;
unsigned long V_90 ;
struct V_86 * V_122 ;
struct V_86 V_111 , V_109 ;
struct V_61 * V_62 = NULL , * V_120 ;
enum V_123 V_124 ;
V_34 = F_132 ( V_114 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_119 ;
if ( V_114 -> V_126 & ( V_84 - 1 ) )
goto V_125;
if ( V_114 -> V_127 & ( V_84 - 1 ) )
goto V_125;
if ( ( V_114 -> V_122 < V_128 ) &&
( ( V_114 -> V_129 & ( V_84 - 1 ) ) ||
! F_138 ( V_130 ,
( void V_131 * ) ( unsigned long ) V_114 -> V_129 ,
V_114 -> V_126 ) ) )
goto V_125;
if ( V_114 -> V_122 >= V_64 )
goto V_125;
if ( V_114 -> V_127 + V_114 -> V_126 < V_114 -> V_127 )
goto V_125;
V_122 = F_131 ( V_15 -> V_63 , V_114 -> V_122 ) ;
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
F_105 (slot, kvm->memslots) {
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
if ( F_139 ( & V_109 , V_90 ) )
goto V_139;
}
if ( ( V_109 . V_118 & V_116 ) && ! V_109 . V_88 ) {
if ( F_124 ( & V_109 ) < 0 )
goto V_139;
}
if ( ( V_124 == V_137 ) || ( V_124 == V_135 ) ) {
V_34 = - V_39 ;
V_62 = F_140 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_139;
V_122 = F_131 ( V_62 , V_114 -> V_122 ) ;
V_122 -> V_118 |= V_140 ;
V_120 = F_134 ( V_15 , V_62 , NULL ) ;
F_141 ( V_15 , & V_111 ) ;
F_142 ( V_15 , V_122 ) ;
V_62 = V_120 ;
}
V_34 = F_143 ( V_15 , & V_109 , V_114 , V_124 ) ;
if ( V_34 )
goto V_141;
V_34 = - V_39 ;
if ( ! V_62 ) {
V_62 = F_140 ( V_15 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_139;
}
if ( ( V_124 == V_134 ) || ( V_124 == V_135 ) ) {
V_34 = F_144 ( V_15 , & V_109 ) ;
if ( V_34 )
goto V_141;
}
if ( V_124 == V_137 ) {
V_109 . V_88 = NULL ;
memset ( & V_109 . V_142 , 0 , sizeof( V_109 . V_142 ) ) ;
}
V_120 = F_134 ( V_15 , V_62 , & V_109 ) ;
F_145 ( V_15 , V_114 , & V_111 , V_124 ) ;
F_102 ( & V_111 , & V_109 ) ;
F_94 ( V_120 ) ;
return 0 ;
V_141:
F_94 ( V_62 ) ;
V_139:
F_102 ( & V_109 , & V_111 ) ;
V_125:
return V_34 ;
}
int F_146 ( struct V_15 * V_15 ,
struct V_113 * V_114 )
{
int V_34 ;
F_147 ( & V_15 -> V_78 ) ;
V_34 = F_137 ( V_15 , V_114 ) ;
F_21 ( & V_15 -> V_78 ) ;
return V_34 ;
}
int F_148 ( struct V_15 * V_15 ,
struct V_113 * V_114 )
{
if ( V_114 -> V_122 >= V_128 )
return - V_119 ;
return F_146 ( V_15 , V_114 ) ;
}
int F_149 ( struct V_15 * V_15 ,
struct V_143 * log , int * V_144 )
{
struct V_86 * V_87 ;
int V_34 , V_17 ;
unsigned long V_145 ;
unsigned long V_146 = 0 ;
V_34 = - V_119 ;
if ( log -> V_122 >= V_128 )
goto V_125;
V_87 = F_131 ( V_15 -> V_63 , log -> V_122 ) ;
V_34 = - V_147 ;
if ( ! V_87 -> V_88 )
goto V_125;
V_145 = F_126 ( V_87 ) ;
for ( V_17 = 0 ; ! V_146 && V_17 < V_145 / sizeof( long ) ; ++ V_17 )
V_146 = V_87 -> V_88 [ V_17 ] ;
V_34 = - V_148 ;
if ( F_150 ( log -> V_88 , V_87 -> V_88 , V_145 ) )
goto V_125;
if ( V_146 )
* V_144 = 1 ;
V_34 = 0 ;
V_125:
return V_34 ;
}
bool F_151 ( void )
{
return V_149 ;
}
void F_152 ( void )
{
V_149 = false ;
}
struct V_86 * F_153 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_154 ( V_61 ( V_15 ) , V_150 ) ;
}
int F_155 ( struct V_15 * V_15 , T_6 V_150 )
{
struct V_86 * V_87 = F_153 ( V_15 , V_150 ) ;
if ( ! V_87 || V_87 -> V_32 >= V_128 ||
V_87 -> V_118 & V_140 )
return 0 ;
return 1 ;
}
unsigned long F_156 ( struct V_15 * V_15 , T_6 V_150 )
{
struct V_151 * V_152 ;
unsigned long V_85 , V_83 ;
V_83 = V_84 ;
V_85 = F_157 ( V_15 , V_150 ) ;
if ( F_158 ( V_85 ) )
return V_84 ;
F_159 ( & V_8 -> V_47 -> V_153 ) ;
V_152 = F_160 ( V_8 -> V_47 , V_85 ) ;
if ( ! V_152 )
goto V_125;
V_83 = F_161 ( V_152 ) ;
V_125:
F_162 ( & V_8 -> V_47 -> V_153 ) ;
return V_83 ;
}
static bool F_163 ( struct V_86 * V_122 )
{
return V_122 -> V_118 & V_117 ;
}
static unsigned long F_164 ( struct V_86 * V_122 , T_6 V_150 ,
T_6 * V_154 , bool V_155 )
{
if ( ! V_122 || V_122 -> V_118 & V_140 )
return V_156 ;
if ( F_163 ( V_122 ) && V_155 )
return V_157 ;
if ( V_154 )
* V_154 = V_122 -> V_90 - ( V_150 - V_122 -> V_121 ) ;
return F_165 ( V_122 , V_150 ) ;
}
static unsigned long F_166 ( struct V_86 * V_122 , T_6 V_150 ,
T_6 * V_154 )
{
return F_164 ( V_122 , V_150 , V_154 , true ) ;
}
unsigned long F_167 ( struct V_86 * V_122 ,
T_6 V_150 )
{
return F_166 ( V_122 , V_150 , NULL ) ;
}
unsigned long F_157 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_166 ( F_153 ( V_15 , V_150 ) , V_150 , NULL ) ;
}
unsigned long F_168 ( struct V_15 * V_15 , T_6 V_150 , bool * V_158 )
{
struct V_86 * V_122 = F_153 ( V_15 , V_150 ) ;
unsigned long V_159 = F_164 ( V_122 , V_150 , NULL , false ) ;
if ( ! F_158 ( V_159 ) && V_158 )
* V_158 = ! F_163 ( V_122 ) ;
return V_159 ;
}
static int F_169 ( void * V_160 , void V_131 * V_159 , int V_161 )
{
return F_170 ( V_160 , V_159 , V_161 ) ;
}
static int F_171 ( void * V_160 , void V_131 * V_159 , int V_161 )
{
return F_172 ( V_160 , V_159 , V_161 ) ;
}
static int F_173 ( struct V_162 * V_163 , struct V_46 * V_47 ,
unsigned long V_55 , int V_155 , struct V_33 * * V_33 )
{
int V_118 = V_164 | V_165 | V_166 | V_167 ;
if ( V_155 )
V_118 |= V_168 ;
return F_174 ( V_163 , V_47 , V_55 , 1 , V_118 , V_33 , NULL , NULL ) ;
}
static inline int F_175 ( unsigned long V_85 )
{
int V_169 , V_118 = V_164 | V_166 | V_168 ;
V_169 = F_174 ( V_8 , V_8 -> V_47 , V_85 , 1 ,
V_118 , NULL , NULL , NULL ) ;
return V_169 == - V_170 ;
}
static bool F_176 ( unsigned long V_85 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_158 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_90 ;
if ( ! ( V_172 || V_171 ) )
return false ;
if ( ! ( V_173 || V_158 ) )
return false ;
V_90 = F_177 ( V_85 , 1 , 1 , V_33 ) ;
if ( V_90 == 1 ) {
* V_1 = F_178 ( V_33 [ 0 ] ) ;
if ( V_158 )
* V_158 = true ;
return true ;
}
return false ;
}
static int F_179 ( unsigned long V_85 , bool * V_172 , bool V_173 ,
bool * V_158 , T_1 * V_1 )
{
struct V_33 * V_33 [ 1 ] ;
int V_90 = 0 ;
F_180 () ;
if ( V_158 )
* V_158 = V_173 ;
if ( V_172 ) {
F_159 ( & V_8 -> V_47 -> V_153 ) ;
V_90 = F_173 ( V_8 , V_8 -> V_47 ,
V_85 , V_173 , V_33 ) ;
F_162 ( & V_8 -> V_47 -> V_153 ) ;
} else
V_90 = F_181 ( V_85 , 1 , V_173 ,
V_33 ) ;
if ( V_90 != 1 )
return V_90 ;
if ( F_7 ( ! V_173 ) && V_158 ) {
struct V_33 * V_174 [ 1 ] ;
V_90 = F_177 ( V_85 , 1 , 1 , V_174 ) ;
if ( V_90 == 1 ) {
* V_158 = true ;
F_182 ( V_33 [ 0 ] ) ;
V_33 [ 0 ] = V_174 [ 0 ] ;
}
V_90 = 1 ;
}
* V_1 = F_178 ( V_33 [ 0 ] ) ;
return V_90 ;
}
static bool F_183 ( struct V_151 * V_152 , bool V_173 )
{
if ( F_7 ( ! ( V_152 -> V_175 & V_176 ) ) )
return false ;
if ( V_173 && ( F_7 ( ! ( V_152 -> V_175 & V_177 ) ) ) )
return false ;
return true ;
}
static T_1 F_184 ( unsigned long V_85 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_158 )
{
struct V_151 * V_152 ;
T_1 V_1 = 0 ;
int V_90 ;
F_64 ( V_171 && V_172 ) ;
if ( F_176 ( V_85 , V_171 , V_172 , V_173 , V_158 , & V_1 ) )
return V_1 ;
if ( V_171 )
return V_178 ;
V_90 = F_179 ( V_85 , V_172 , V_173 , V_158 , & V_1 ) ;
if ( V_90 == 1 )
return V_1 ;
F_159 ( & V_8 -> V_47 -> V_153 ) ;
if ( V_90 == - V_170 ||
( ! V_172 && F_175 ( V_85 ) ) ) {
V_1 = V_179 ;
goto exit;
}
V_152 = F_185 ( V_8 -> V_47 , V_85 , V_85 + 1 ) ;
if ( V_152 == NULL )
V_1 = V_178 ;
else if ( ( V_152 -> V_175 & V_180 ) ) {
V_1 = ( ( V_85 - V_152 -> V_181 ) >> V_132 ) +
V_152 -> V_182 ;
F_64 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_172 && F_183 ( V_152 , V_173 ) )
* V_172 = true ;
V_1 = V_178 ;
}
exit:
F_162 ( & V_8 -> V_47 -> V_153 ) ;
return V_1 ;
}
static T_1
F_186 ( struct V_86 * V_122 , T_6 V_150 , bool V_171 ,
bool * V_172 , bool V_173 , bool * V_158 )
{
unsigned long V_85 = F_164 ( V_122 , V_150 , NULL , V_173 ) ;
if ( V_85 == V_157 )
return V_183 ;
if ( F_158 ( V_85 ) )
return V_184 ;
if ( V_158 && F_163 ( V_122 ) ) {
* V_158 = false ;
V_158 = NULL ;
}
return F_184 ( V_85 , V_171 , V_172 , V_173 ,
V_158 ) ;
}
static T_1 F_187 ( struct V_15 * V_15 , T_6 V_150 , bool V_171 , bool * V_172 ,
bool V_173 , bool * V_158 )
{
struct V_86 * V_122 ;
if ( V_172 )
* V_172 = false ;
V_122 = F_153 ( V_15 , V_150 ) ;
return F_186 ( V_122 , V_150 , V_171 , V_172 , V_173 ,
V_158 ) ;
}
T_1 F_188 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_187 ( V_15 , V_150 , true , NULL , true , NULL ) ;
}
T_1 F_189 ( struct V_15 * V_15 , T_6 V_150 , bool * V_172 ,
bool V_173 , bool * V_158 )
{
return F_187 ( V_15 , V_150 , false , V_172 , V_173 , V_158 ) ;
}
T_1 F_190 ( struct V_15 * V_15 , T_6 V_150 )
{
return F_187 ( V_15 , V_150 , false , NULL , true , NULL ) ;
}
T_1 F_191 ( struct V_15 * V_15 , T_6 V_150 , bool V_173 ,
bool * V_158 )
{
return F_187 ( V_15 , V_150 , false , NULL , V_173 , V_158 ) ;
}
T_1 F_192 ( struct V_86 * V_122 , T_6 V_150 )
{
return F_186 ( V_122 , V_150 , false , NULL , true , NULL ) ;
}
T_1 F_193 ( struct V_86 * V_122 , T_6 V_150 )
{
return F_186 ( V_122 , V_150 , true , NULL , true , NULL ) ;
}
int F_194 ( struct V_15 * V_15 , T_6 V_150 , struct V_33 * * V_185 ,
int V_154 )
{
unsigned long V_85 ;
T_6 V_186 ;
V_85 = F_166 ( F_153 ( V_15 , V_150 ) , V_150 , & V_186 ) ;
if ( F_158 ( V_85 ) )
return - 1 ;
if ( V_186 < V_154 )
return 0 ;
return F_177 ( V_85 , V_154 , 1 , V_185 ) ;
}
static struct V_33 * F_195 ( T_1 V_1 )
{
if ( F_196 ( V_1 ) )
return V_187 ;
if ( F_1 ( V_1 ) ) {
F_197 ( 1 ) ;
return V_187 ;
}
return F_4 ( V_1 ) ;
}
struct V_33 * F_198 ( struct V_15 * V_15 , T_6 V_150 )
{
T_1 V_1 ;
V_1 = F_190 ( V_15 , V_150 ) ;
return F_195 ( V_1 ) ;
}
void F_199 ( struct V_33 * V_33 )
{
F_197 ( F_200 ( V_33 ) ) ;
F_201 ( F_178 ( V_33 ) ) ;
}
void F_201 ( T_1 V_1 )
{
if ( ! F_196 ( V_1 ) && ! F_1 ( V_1 ) )
F_182 ( F_4 ( V_1 ) ) ;
}
void F_202 ( struct V_33 * V_33 )
{
F_197 ( F_200 ( V_33 ) ) ;
F_203 ( F_178 ( V_33 ) ) ;
}
void F_203 ( T_1 V_1 )
{
F_204 ( V_1 ) ;
F_201 ( V_1 ) ;
}
void F_205 ( struct V_33 * V_33 )
{
F_204 ( F_178 ( V_33 ) ) ;
}
void F_204 ( T_1 V_1 )
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
static int F_211 ( unsigned long V_161 , int V_188 )
{
if ( V_161 > V_84 - V_188 )
return V_84 - V_188 ;
else
return V_161 ;
}
int F_212 ( struct V_15 * V_15 , T_6 V_150 , void * V_160 , int V_188 ,
int V_161 )
{
int V_34 ;
unsigned long V_85 ;
V_85 = F_168 ( V_15 , V_150 , NULL ) ;
if ( F_158 ( V_85 ) )
return - V_148 ;
V_34 = F_169 ( V_160 , ( void V_131 * ) V_85 + V_188 , V_161 ) ;
if ( V_34 )
return - V_148 ;
return 0 ;
}
int F_213 ( struct V_15 * V_15 , T_7 V_189 , void * V_160 , unsigned long V_161 )
{
T_6 V_150 = V_189 >> V_132 ;
int V_190 ;
int V_188 = F_214 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_211 ( V_161 , V_188 ) ) != 0 ) {
V_191 = F_212 ( V_15 , V_150 , V_160 , V_188 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_188 = 0 ;
V_161 -= V_190 ;
V_160 += V_190 ;
++ V_150 ;
}
return 0 ;
}
int F_215 ( struct V_15 * V_15 , T_7 V_189 , void * V_160 ,
unsigned long V_161 )
{
int V_34 ;
unsigned long V_85 ;
T_6 V_150 = V_189 >> V_132 ;
int V_188 = F_214 ( V_189 ) ;
V_85 = F_168 ( V_15 , V_150 , NULL ) ;
if ( F_158 ( V_85 ) )
return - V_148 ;
F_216 () ;
V_34 = F_171 ( V_160 , ( void V_131 * ) V_85 + V_188 , V_161 ) ;
F_217 () ;
if ( V_34 )
return - V_148 ;
return 0 ;
}
int F_218 ( struct V_15 * V_15 , T_6 V_150 , const void * V_160 ,
int V_188 , int V_161 )
{
int V_34 ;
unsigned long V_85 ;
V_85 = F_157 ( V_15 , V_150 ) ;
if ( F_158 ( V_85 ) )
return - V_148 ;
V_34 = F_219 ( ( void V_131 * ) V_85 + V_188 , V_160 , V_161 ) ;
if ( V_34 )
return - V_148 ;
F_220 ( V_15 , V_150 ) ;
return 0 ;
}
int F_221 ( struct V_15 * V_15 , T_7 V_189 , const void * V_160 ,
unsigned long V_161 )
{
T_6 V_150 = V_189 >> V_132 ;
int V_190 ;
int V_188 = F_214 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_211 ( V_161 , V_188 ) ) != 0 ) {
V_191 = F_218 ( V_15 , V_150 , V_160 , V_188 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_188 = 0 ;
V_161 -= V_190 ;
V_160 += V_190 ;
++ V_150 ;
}
return 0 ;
}
int F_222 ( struct V_15 * V_15 , struct V_192 * V_193 ,
T_7 V_189 , unsigned long V_161 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_188 = F_214 ( V_189 ) ;
T_6 V_194 = V_189 >> V_132 ;
T_6 V_195 = ( V_189 + V_161 - 1 ) >> V_132 ;
T_6 V_196 = V_195 - V_194 + 1 ;
T_6 V_197 ;
V_193 -> V_189 = V_189 ;
V_193 -> V_112 = V_62 -> V_112 ;
V_193 -> V_161 = V_161 ;
V_193 -> V_87 = F_153 ( V_15 , V_194 ) ;
V_193 -> V_159 = F_166 ( V_193 -> V_87 , V_194 , & V_197 ) ;
if ( ! F_158 ( V_193 -> V_159 ) && V_197 >= V_196 ) {
V_193 -> V_159 += V_188 ;
} else {
while ( V_194 <= V_195 ) {
V_193 -> V_87 = F_153 ( V_15 , V_194 ) ;
V_193 -> V_159 = F_166 ( V_193 -> V_87 , V_194 ,
& V_197 ) ;
if ( F_158 ( V_193 -> V_159 ) )
return - V_148 ;
V_194 += V_197 ;
}
V_193 -> V_87 = NULL ;
}
return 0 ;
}
int F_223 ( struct V_15 * V_15 , struct V_192 * V_193 ,
void * V_160 , unsigned long V_161 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_64 ( V_161 > V_193 -> V_161 ) ;
if ( V_62 -> V_112 != V_193 -> V_112 )
F_222 ( V_15 , V_193 , V_193 -> V_189 , V_193 -> V_161 ) ;
if ( F_7 ( ! V_193 -> V_87 ) )
return F_221 ( V_15 , V_193 -> V_189 , V_160 , V_161 ) ;
if ( F_158 ( V_193 -> V_159 ) )
return - V_148 ;
V_34 = F_219 ( ( void V_131 * ) V_193 -> V_159 , V_160 , V_161 ) ;
if ( V_34 )
return - V_148 ;
F_224 ( V_15 , V_193 -> V_87 , V_193 -> V_189 >> V_132 ) ;
return 0 ;
}
int F_225 ( struct V_15 * V_15 , struct V_192 * V_193 ,
void * V_160 , unsigned long V_161 )
{
struct V_61 * V_62 = V_61 ( V_15 ) ;
int V_34 ;
F_64 ( V_161 > V_193 -> V_161 ) ;
if ( V_62 -> V_112 != V_193 -> V_112 )
F_222 ( V_15 , V_193 , V_193 -> V_189 , V_193 -> V_161 ) ;
if ( F_7 ( ! V_193 -> V_87 ) )
return F_213 ( V_15 , V_193 -> V_189 , V_160 , V_161 ) ;
if ( F_158 ( V_193 -> V_159 ) )
return - V_148 ;
V_34 = F_170 ( V_160 , ( void V_131 * ) V_193 -> V_159 , V_161 ) ;
if ( V_34 )
return - V_148 ;
return 0 ;
}
int F_226 ( struct V_15 * V_15 , T_6 V_150 , int V_188 , int V_161 )
{
return F_218 ( V_15 , V_150 , ( const void * ) V_198 ,
V_188 , V_161 ) ;
}
int F_227 ( struct V_15 * V_15 , T_7 V_189 , unsigned long V_161 )
{
T_6 V_150 = V_189 >> V_132 ;
int V_190 ;
int V_188 = F_214 ( V_189 ) ;
int V_191 ;
while ( ( V_190 = F_211 ( V_161 , V_188 ) ) != 0 ) {
V_191 = F_226 ( V_15 , V_150 , V_188 , V_190 ) ;
if ( V_191 < 0 )
return V_191 ;
V_188 = 0 ;
V_161 -= V_190 ;
++ V_150 ;
}
return 0 ;
}
void F_224 ( struct V_15 * V_15 , struct V_86 * V_87 ,
T_6 V_150 )
{
if ( V_87 && V_87 -> V_88 ) {
unsigned long V_199 = V_150 - V_87 -> V_121 ;
F_228 ( V_199 , V_87 -> V_88 ) ;
}
}
void F_220 ( struct V_15 * V_15 , T_6 V_150 )
{
struct V_86 * V_87 ;
V_87 = F_153 ( V_15 , V_150 ) ;
F_224 ( V_15 , V_87 , V_150 ) ;
}
void F_229 ( struct V_2 * V_3 )
{
F_230 ( V_200 ) ;
for (; ; ) {
F_231 ( & V_3 -> V_36 , & V_200 , V_201 ) ;
if ( F_232 ( V_3 ) ) {
F_26 ( V_202 , V_3 ) ;
break;
}
if ( F_233 ( V_3 ) )
break;
if ( F_234 ( V_8 ) )
break;
F_235 () ;
}
F_236 ( & V_3 -> V_36 , & V_200 ) ;
}
void F_237 ( struct V_2 * V_3 )
{
int V_18 ;
int V_4 = V_3 -> V_4 ;
T_8 * V_203 ;
V_203 = F_238 ( V_3 ) ;
if ( F_239 ( V_203 ) ) {
F_240 ( V_203 ) ;
++ V_3 -> V_27 . V_204 ;
}
V_18 = F_12 () ;
if ( V_4 != V_18 && ( unsigned ) V_4 < V_205 && F_241 ( V_4 ) )
if ( F_242 ( V_3 ) )
F_243 ( V_4 ) ;
F_15 () ;
}
void F_244 ( struct V_2 * V_3 )
{
if ( ! F_245 () )
return;
F_246 () ;
}
bool F_247 ( struct V_2 * V_206 )
{
struct V_7 * V_7 ;
struct V_162 * V_207 = NULL ;
bool V_191 = false ;
F_248 () ;
V_7 = F_249 ( V_206 -> V_7 ) ;
if ( V_7 )
V_207 = F_250 ( V_206 -> V_7 , V_10 ) ;
F_251 () ;
if ( ! V_207 )
return V_191 ;
if ( V_207 -> V_118 & V_208 ) {
F_252 ( V_207 ) ;
return V_191 ;
}
V_191 = F_253 ( V_207 , 1 ) ;
F_252 ( V_207 ) ;
return V_191 ;
}
bool F_254 ( struct V_2 * V_3 )
{
bool V_209 ;
V_209 = ! V_3 -> V_210 . V_211 ||
( V_3 -> V_210 . V_211 &&
V_3 -> V_210 . V_212 ) ;
if ( V_3 -> V_210 . V_211 )
F_45 ( V_3 , ! V_3 -> V_210 . V_212 ) ;
return V_209 ;
}
void F_255 ( struct V_2 * V_18 )
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
if ( ! F_256 ( V_3 -> V_42 ) )
continue;
if ( V_3 == V_18 )
continue;
if ( F_239 ( & V_3 -> V_36 ) )
continue;
if ( ! F_254 ( V_3 ) )
continue;
V_214 = F_247 ( V_3 ) ;
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
static int F_257 ( struct V_151 * V_152 , struct V_217 * V_218 )
{
struct V_2 * V_3 = V_152 -> V_219 -> V_103 ;
struct V_33 * V_33 ;
if ( V_218 -> V_220 == 0 )
V_33 = F_258 ( V_3 -> V_41 ) ;
#ifdef F_259
else if ( V_218 -> V_220 == V_221 )
V_33 = F_258 ( V_3 -> V_142 . V_222 ) ;
#endif
#ifdef F_260
else if ( V_218 -> V_220 == F_260 )
V_33 = F_258 ( V_3 -> V_15 -> V_223 ) ;
#endif
else
return F_261 ( V_3 , V_218 ) ;
F_210 ( V_33 ) ;
V_218 -> V_33 = V_33 ;
return 0 ;
}
static int F_262 ( struct V_101 * V_101 , struct V_151 * V_152 )
{
V_152 -> V_224 = & V_225 ;
return 0 ;
}
static int F_263 ( struct V_100 * V_100 , struct V_101 * V_102 )
{
struct V_2 * V_3 = V_102 -> V_103 ;
F_120 ( V_3 -> V_15 ) ;
return 0 ;
}
static int F_264 ( struct V_2 * V_3 )
{
return F_265 ( L_1 , & V_226 , V_3 , V_227 | V_228 ) ;
}
static int F_266 ( struct V_15 * V_15 , T_5 V_32 )
{
int V_34 ;
struct V_2 * V_3 , * V_229 ;
V_3 = F_267 ( V_15 , V_32 ) ;
if ( F_268 ( V_3 ) )
return F_269 ( V_3 ) ;
F_270 ( & V_3 -> V_13 , & V_230 ) ;
V_34 = F_271 ( V_3 ) ;
if ( V_34 )
goto V_231;
F_147 ( & V_15 -> V_76 ) ;
if ( ! F_272 ( V_3 ) ) {
V_34 = - V_119 ;
goto V_232;
}
if ( F_273 ( & V_15 -> V_233 ) == V_234 ) {
V_34 = - V_119 ;
goto V_232;
}
F_25 (r, v, kvm)
if ( V_229 -> V_35 == V_32 ) {
V_34 = - V_138 ;
goto V_232;
}
F_64 ( V_15 -> V_235 [ F_273 ( & V_15 -> V_233 ) ] ) ;
F_119 ( V_15 ) ;
V_34 = F_264 ( V_3 ) ;
if ( V_34 < 0 ) {
F_120 ( V_15 ) ;
goto V_232;
}
V_15 -> V_235 [ F_273 ( & V_15 -> V_233 ) ] = V_3 ;
F_63 () ;
F_85 ( & V_15 -> V_233 ) ;
F_21 ( & V_15 -> V_76 ) ;
F_274 ( V_3 ) ;
return V_34 ;
V_232:
F_21 ( & V_15 -> V_76 ) ;
V_231:
F_275 ( V_3 ) ;
return V_34 ;
}
static int F_276 ( struct V_2 * V_3 , T_9 * V_236 )
{
if ( V_236 ) {
F_277 ( V_236 , F_278 ( V_237 ) | F_278 ( V_238 ) ) ;
V_3 -> V_239 = 1 ;
V_3 -> V_236 = * V_236 ;
} else
V_3 -> V_239 = 0 ;
return 0 ;
}
static long F_279 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_2 * V_3 = V_102 -> V_103 ;
void V_131 * V_242 = ( void V_131 * ) V_241 ;
int V_34 ;
struct V_243 * V_244 = NULL ;
struct V_245 * V_245 = NULL ;
if ( V_3 -> V_15 -> V_47 != V_8 -> V_47 )
return - V_246 ;
#if F_115 ( F_125 ) || F_115 ( V_247 ) || F_115 ( V_248 )
if ( V_240 == V_249 || V_240 == V_250 )
return F_280 ( V_102 , V_240 , V_241 ) ;
#endif
V_34 = F_5 ( V_3 ) ;
if ( V_34 )
return V_34 ;
switch ( V_240 ) {
case V_251 :
V_34 = - V_119 ;
if ( V_241 )
goto V_125;
V_34 = F_281 ( V_3 , V_3 -> V_41 ) ;
F_282 ( V_3 -> V_41 -> V_252 , V_34 ) ;
break;
case V_253 : {
struct V_254 * V_254 ;
V_34 = - V_39 ;
V_254 = F_82 ( sizeof( struct V_254 ) , V_37 ) ;
if ( ! V_254 )
goto V_125;
V_34 = F_283 ( V_3 , V_254 ) ;
if ( V_34 )
goto V_255;
V_34 = - V_148 ;
if ( F_150 ( V_242 , V_254 , sizeof( struct V_254 ) ) )
goto V_255;
V_34 = 0 ;
V_255:
F_94 ( V_254 ) ;
break;
}
case V_256 : {
struct V_254 * V_254 ;
V_34 = - V_39 ;
V_254 = F_284 ( V_242 , sizeof( * V_254 ) ) ;
if ( F_268 ( V_254 ) ) {
V_34 = F_269 ( V_254 ) ;
goto V_125;
}
V_34 = F_285 ( V_3 , V_254 ) ;
F_94 ( V_254 ) ;
break;
}
case V_257 : {
V_245 = F_82 ( sizeof( struct V_245 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_245 )
goto V_125;
V_34 = F_286 ( V_3 , V_245 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_150 ( V_242 , V_245 , sizeof( struct V_245 ) ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_258 : {
V_245 = F_284 ( V_242 , sizeof( * V_245 ) ) ;
if ( F_268 ( V_245 ) ) {
V_34 = F_269 ( V_245 ) ;
V_245 = NULL ;
goto V_125;
}
V_34 = F_287 ( V_3 , V_245 ) ;
break;
}
case V_259 : {
struct V_260 V_261 ;
V_34 = F_288 ( V_3 , & V_261 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_150 ( V_242 , & V_261 , sizeof V_261 ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_262 : {
struct V_260 V_261 ;
V_34 = - V_148 ;
if ( F_289 ( & V_261 , V_242 , sizeof V_261 ) )
goto V_125;
V_34 = F_290 ( V_3 , & V_261 ) ;
break;
}
case V_263 : {
struct V_264 V_265 ;
V_34 = - V_148 ;
if ( F_289 ( & V_265 , V_242 , sizeof V_265 ) )
goto V_125;
V_34 = F_291 ( V_3 , & V_265 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_150 ( V_242 , & V_265 , sizeof V_265 ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_266 : {
struct V_267 V_268 ;
V_34 = - V_148 ;
if ( F_289 ( & V_268 , V_242 , sizeof V_268 ) )
goto V_125;
V_34 = F_292 ( V_3 , & V_268 ) ;
break;
}
case V_269 : {
struct V_270 V_131 * V_271 = V_242 ;
struct V_270 V_272 ;
T_9 V_236 , * V_273 ;
V_273 = NULL ;
if ( V_242 ) {
V_34 = - V_148 ;
if ( F_289 ( & V_272 , V_242 ,
sizeof V_272 ) )
goto V_125;
V_34 = - V_119 ;
if ( V_272 . V_161 != sizeof V_236 )
goto V_125;
V_34 = - V_148 ;
if ( F_289 ( & V_236 , V_271 -> V_236 ,
sizeof V_236 ) )
goto V_125;
V_273 = & V_236 ;
}
V_34 = F_276 ( V_3 , V_273 ) ;
break;
}
case V_274 : {
V_244 = F_82 ( sizeof( struct V_243 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_244 )
goto V_125;
V_34 = F_293 ( V_3 , V_244 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_150 ( V_242 , V_244 , sizeof( struct V_243 ) ) )
goto V_125;
V_34 = 0 ;
break;
}
case V_275 : {
V_244 = F_284 ( V_242 , sizeof( * V_244 ) ) ;
if ( F_268 ( V_244 ) ) {
V_34 = F_269 ( V_244 ) ;
V_244 = NULL ;
goto V_125;
}
V_34 = F_294 ( V_3 , V_244 ) ;
break;
}
default:
V_34 = F_280 ( V_102 , V_240 , V_241 ) ;
}
V_125:
F_16 ( V_3 ) ;
F_94 ( V_244 ) ;
F_94 ( V_245 ) ;
return V_34 ;
}
static long F_295 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_2 * V_3 = V_102 -> V_103 ;
void V_131 * V_242 = F_296 ( V_241 ) ;
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
if ( F_289 ( & V_272 , V_242 ,
sizeof V_272 ) )
goto V_125;
V_34 = - V_119 ;
if ( V_272 . V_161 != sizeof V_276 )
goto V_125;
V_34 = - V_148 ;
if ( F_289 ( & V_276 , V_271 -> V_236 ,
sizeof V_276 ) )
goto V_125;
F_297 ( & V_236 , & V_276 ) ;
V_34 = F_276 ( V_3 , & V_236 ) ;
} else
V_34 = F_276 ( V_3 , NULL ) ;
break;
}
default:
V_34 = F_279 ( V_102 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static int F_298 ( struct V_94 * V_95 ,
int (* F_299)( struct V_94 * V_95 ,
struct V_277 * V_278 ) ,
unsigned long V_241 )
{
struct V_277 V_278 ;
if ( ! F_299 )
return - V_279 ;
if ( F_289 ( & V_278 , ( void V_131 * ) V_241 , sizeof( V_278 ) ) )
return - V_148 ;
return F_299 ( V_95 , & V_278 ) ;
}
static long F_300 ( struct V_101 * V_102 , unsigned int V_240 ,
unsigned long V_241 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
switch ( V_240 ) {
case V_280 :
return F_298 ( V_95 , V_95 -> V_59 -> V_281 , V_241 ) ;
case V_282 :
return F_298 ( V_95 , V_95 -> V_59 -> V_283 , V_241 ) ;
case V_284 :
return F_298 ( V_95 , V_95 -> V_59 -> V_285 , V_241 ) ;
default:
if ( V_95 -> V_59 -> V_240 )
return V_95 -> V_59 -> V_240 ( V_95 , V_240 , V_241 ) ;
return - V_286 ;
}
}
static int F_301 ( struct V_100 * V_100 , struct V_101 * V_102 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_15 * V_15 = V_95 -> V_15 ;
F_120 ( V_15 ) ;
return 0 ;
}
struct V_94 * F_302 ( struct V_101 * V_102 )
{
if ( V_102 -> V_287 != & V_288 )
return NULL ;
return V_102 -> V_103 ;
}
static int F_303 ( struct V_15 * V_15 ,
struct V_289 * V_290 )
{
struct V_291 * V_59 = NULL ;
struct V_94 * V_95 ;
bool V_292 = V_290 -> V_118 & V_293 ;
int V_191 ;
switch ( V_290 -> type ) {
#ifdef F_304
case V_294 :
case V_295 :
V_59 = & V_296 ;
break;
#endif
#ifdef F_305
case V_297 :
V_59 = & V_298 ;
break;
#endif
default:
return - V_299 ;
}
if ( V_292 )
return 0 ;
V_95 = F_82 ( sizeof( * V_95 ) , V_37 ) ;
if ( ! V_95 )
return - V_39 ;
V_95 -> V_59 = V_59 ;
V_95 -> V_15 = V_15 ;
V_191 = V_59 -> V_300 ( V_95 , V_290 -> type ) ;
if ( V_191 < 0 ) {
F_94 ( V_95 ) ;
return V_191 ;
}
V_191 = F_265 ( V_59 -> V_301 , & V_288 , V_95 , V_227 | V_228 ) ;
if ( V_191 < 0 ) {
V_59 -> V_97 ( V_95 ) ;
return V_191 ;
}
F_90 ( & V_95 -> V_96 , & V_15 -> V_80 ) ;
F_119 ( V_15 ) ;
V_290 -> V_302 = V_191 ;
return 0 ;
}
static long F_306 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_15 * V_15 = V_102 -> V_103 ;
void V_131 * V_242 = ( void V_131 * ) V_241 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_246 ;
switch ( V_240 ) {
case V_303 :
V_34 = F_266 ( V_15 , V_241 ) ;
break;
case V_304 : {
struct V_113 V_305 ;
V_34 = - V_148 ;
if ( F_289 ( & V_305 , V_242 ,
sizeof V_305 ) )
goto V_125;
V_34 = F_148 ( V_15 , & V_305 ) ;
break;
}
case V_306 : {
struct V_143 log ;
V_34 = - V_148 ;
if ( F_289 ( & log , V_242 , sizeof log ) )
goto V_125;
V_34 = F_307 ( V_15 , & log ) ;
break;
}
#ifdef F_260
case V_307 : {
struct V_308 V_309 ;
V_34 = - V_148 ;
if ( F_289 ( & V_309 , V_242 , sizeof V_309 ) )
goto V_125;
V_34 = F_308 ( V_15 , & V_309 ) ;
break;
}
case V_310 : {
struct V_308 V_309 ;
V_34 = - V_148 ;
if ( F_289 ( & V_309 , V_242 , sizeof V_309 ) )
goto V_125;
V_34 = F_309 ( V_15 , & V_309 ) ;
break;
}
#endif
case V_311 : {
struct V_312 V_160 ;
V_34 = - V_148 ;
if ( F_289 ( & V_160 , V_242 , sizeof V_160 ) )
goto V_125;
V_34 = V_312 ( V_15 , & V_160 ) ;
break;
}
case V_313 : {
struct V_314 V_160 ;
V_34 = - V_148 ;
if ( F_289 ( & V_160 , V_242 , sizeof V_160 ) )
goto V_125;
V_34 = V_314 ( V_15 , & V_160 ) ;
break;
}
#ifdef F_310
case V_315 :
V_34 = 0 ;
F_147 ( & V_15 -> V_76 ) ;
if ( F_273 ( & V_15 -> V_233 ) != 0 )
V_34 = - V_316 ;
else
V_15 -> V_317 = V_241 ;
F_21 ( & V_15 -> V_76 ) ;
break;
#endif
#ifdef F_311
case V_318 : {
struct V_319 V_320 ;
V_34 = - V_148 ;
if ( F_289 ( & V_320 , V_242 , sizeof V_320 ) )
goto V_125;
V_34 = F_312 ( V_15 , & V_320 ) ;
break;
}
#endif
#ifdef F_313
case V_321 :
case V_322 : {
struct V_323 V_324 ;
V_34 = - V_148 ;
if ( F_289 ( & V_324 , V_242 , sizeof V_324 ) )
goto V_125;
V_34 = F_314 ( V_15 , & V_324 ,
V_240 == V_321 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( V_240 == V_321 ) {
if ( F_150 ( V_242 , & V_324 , sizeof V_324 ) )
goto V_125;
}
V_34 = 0 ;
break;
}
#endif
#ifdef F_315
case V_325 : {
struct V_326 V_327 ;
struct V_326 V_131 * V_328 ;
struct V_329 * V_330 ;
V_34 = - V_148 ;
if ( F_289 ( & V_327 , V_242 , sizeof( V_327 ) ) )
goto V_125;
V_34 = - V_119 ;
if ( V_327 . V_331 >= V_332 )
goto V_125;
if ( V_327 . V_118 )
goto V_125;
V_34 = - V_39 ;
V_330 = F_316 ( V_327 . V_331 * sizeof( * V_330 ) ) ;
if ( ! V_330 )
goto V_125;
V_34 = - V_148 ;
V_328 = V_242 ;
if ( F_289 ( V_330 , V_328 -> V_330 ,
V_327 . V_331 * sizeof( * V_330 ) ) )
goto V_333;
V_34 = F_317 ( V_15 , V_330 , V_327 . V_331 ,
V_327 . V_118 ) ;
V_333:
F_100 ( V_330 ) ;
break;
}
#endif
case V_334 : {
struct V_289 V_290 ;
V_34 = - V_148 ;
if ( F_289 ( & V_290 , V_242 , sizeof( V_290 ) ) )
goto V_125;
V_34 = F_303 ( V_15 , & V_290 ) ;
if ( V_34 )
goto V_125;
V_34 = - V_148 ;
if ( F_150 ( V_242 , & V_290 , sizeof( V_290 ) ) )
goto V_125;
V_34 = 0 ;
break;
}
default:
V_34 = F_318 ( V_102 , V_240 , V_241 ) ;
if ( V_34 == - V_286 )
V_34 = F_319 ( V_15 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static long F_320 ( struct V_101 * V_102 ,
unsigned int V_240 , unsigned long V_241 )
{
struct V_15 * V_15 = V_102 -> V_103 ;
int V_34 ;
if ( V_15 -> V_47 != V_8 -> V_47 )
return - V_246 ;
switch ( V_240 ) {
case V_306 : {
struct V_335 V_336 ;
struct V_143 log ;
V_34 = - V_148 ;
if ( F_289 ( & V_336 , ( void V_131 * ) V_241 ,
sizeof( V_336 ) ) )
goto V_125;
log . V_122 = V_336 . V_122 ;
log . V_337 = V_336 . V_337 ;
log . V_338 = V_336 . V_338 ;
log . V_88 = F_296 ( V_336 . V_88 ) ;
V_34 = F_307 ( V_15 , & log ) ;
break;
}
default:
V_34 = F_306 ( V_102 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static int F_321 ( struct V_151 * V_152 , struct V_217 * V_218 )
{
struct V_33 * V_33 [ 1 ] ;
unsigned long V_85 ;
int V_90 ;
T_6 V_150 = V_218 -> V_220 ;
struct V_15 * V_15 = V_152 -> V_219 -> V_103 ;
V_85 = F_157 ( V_15 , V_150 ) ;
if ( F_158 ( V_85 ) )
return V_339 ;
V_90 = F_322 ( V_8 , V_8 -> V_47 , V_85 , 1 , 1 , 0 , V_33 ,
NULL ) ;
if ( F_7 ( V_90 != 1 ) )
return V_339 ;
V_218 -> V_33 = V_33 [ 0 ] ;
return 0 ;
}
static int F_323 ( struct V_101 * V_101 , struct V_151 * V_152 )
{
V_152 -> V_224 = & V_340 ;
return 0 ;
}
static int F_324 ( unsigned long type )
{
int V_34 ;
struct V_15 * V_15 ;
V_15 = F_74 ( type ) ;
if ( F_268 ( V_15 ) )
return F_269 ( V_15 ) ;
#ifdef F_260
V_34 = F_325 ( V_15 ) ;
if ( V_34 < 0 ) {
F_120 ( V_15 ) ;
return V_34 ;
}
#endif
V_34 = F_265 ( L_2 , & V_341 , V_15 , V_227 | V_228 ) ;
if ( V_34 < 0 )
F_120 ( V_15 ) ;
return V_34 ;
}
static long F_326 ( long V_241 )
{
switch ( V_241 ) {
case V_342 :
case V_343 :
case V_344 :
#ifdef F_310
case V_345 :
#endif
case V_346 :
#ifdef F_311
case V_347 :
#endif
#ifdef F_315
case V_348 :
#endif
return 1 ;
#ifdef F_315
case V_349 :
return V_332 ;
#endif
default:
break;
}
return F_327 ( V_241 ) ;
}
static long F_328 ( struct V_101 * V_102 ,
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
V_34 = F_324 ( V_241 ) ;
break;
case V_353 :
V_34 = F_326 ( V_241 ) ;
break;
case V_354 :
V_34 = - V_119 ;
if ( V_241 )
goto V_125;
V_34 = V_84 ;
#ifdef F_259
V_34 += V_84 ;
#endif
#ifdef F_260
V_34 += V_84 ;
#endif
break;
case V_355 :
case V_356 :
case V_357 :
V_34 = - V_358 ;
break;
default:
return F_329 ( V_102 , V_240 , V_241 ) ;
}
V_125:
return V_34 ;
}
static void F_330 ( void * V_359 )
{
int V_4 = F_331 () ;
int V_34 ;
if ( F_332 ( V_4 , V_360 ) )
return;
F_29 ( V_4 , V_360 ) ;
V_34 = F_333 ( NULL ) ;
if ( V_34 ) {
F_334 ( V_4 , V_360 ) ;
F_85 ( & V_361 ) ;
F_335 ( V_362 L_3
L_4 , V_4 ) ;
}
}
static void F_336 ( void * V_359 )
{
F_89 ( & V_81 ) ;
F_330 ( V_359 ) ;
F_91 ( & V_81 ) ;
}
static void F_337 ( void * V_359 )
{
int V_4 = F_331 () ;
if ( ! F_332 ( V_4 , V_360 ) )
return;
F_334 ( V_4 , V_360 ) ;
F_338 ( NULL ) ;
}
static void F_339 ( void * V_359 )
{
F_89 ( & V_81 ) ;
F_337 ( V_359 ) ;
F_91 ( & V_81 ) ;
}
static void F_340 ( void )
{
F_64 ( ! V_363 ) ;
V_363 -- ;
if ( ! V_363 )
F_341 ( F_337 , NULL , 1 ) ;
}
static void F_93 ( void )
{
F_89 ( & V_81 ) ;
F_340 () ;
F_91 ( & V_81 ) ;
}
static int F_78 ( void )
{
int V_34 = 0 ;
F_89 ( & V_81 ) ;
V_363 ++ ;
if ( V_363 == 1 ) {
F_87 ( & V_361 , 0 ) ;
F_341 ( F_330 , NULL , 1 ) ;
if ( F_273 ( & V_361 ) ) {
F_340 () ;
V_34 = - V_316 ;
}
}
F_91 ( & V_81 ) ;
return V_34 ;
}
static int F_342 ( struct V_364 * V_365 , unsigned long V_366 ,
void * V_229 )
{
int V_4 = ( long ) V_229 ;
if ( ! V_363 )
return V_367 ;
V_366 &= ~ V_368 ;
switch ( V_366 ) {
case V_369 :
F_335 ( V_362 L_5 ,
V_4 ) ;
F_339 ( NULL ) ;
break;
case V_370 :
F_335 ( V_362 L_6 ,
V_4 ) ;
F_336 ( NULL ) ;
break;
}
return V_367 ;
}
static int F_343 ( struct V_364 * V_365 , unsigned long V_366 ,
void * V_229 )
{
F_335 ( V_362 L_7 ) ;
V_371 = true ;
F_341 ( F_337 , NULL , 1 ) ;
return V_367 ;
}
static void F_113 ( struct V_73 * V_372 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_372 -> V_373 ; V_17 ++ ) {
struct V_374 * V_375 = V_372 -> V_376 [ V_17 ] . V_95 ;
F_344 ( V_375 ) ;
}
F_94 ( V_372 ) ;
}
static inline int F_345 ( const struct V_377 * V_378 ,
const struct V_377 * V_379 )
{
if ( V_378 -> V_85 < V_379 -> V_85 )
return - 1 ;
if ( V_378 -> V_85 + V_378 -> V_161 > V_379 -> V_85 + V_379 -> V_161 )
return 1 ;
return 0 ;
}
static int F_346 ( const void * V_380 , const void * V_381 )
{
return F_345 ( V_380 , V_381 ) ;
}
static int F_347 ( struct V_73 * V_372 , struct V_374 * V_95 ,
T_7 V_85 , int V_161 )
{
V_372 -> V_376 [ V_372 -> V_373 ++ ] = (struct V_377 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
. V_95 = V_95 ,
} ;
F_129 ( V_372 -> V_376 , V_372 -> V_373 , sizeof( struct V_377 ) ,
F_346 , NULL ) ;
return 0 ;
}
static int F_348 ( struct V_73 * V_372 ,
T_7 V_85 , int V_161 )
{
struct V_377 * V_376 , V_382 ;
int V_383 ;
V_382 = (struct V_377 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_376 = bsearch ( & V_382 , V_372 -> V_376 , V_372 -> V_373 ,
sizeof( struct V_377 ) , F_346 ) ;
if ( V_376 == NULL )
return - V_147 ;
V_383 = V_376 - V_372 -> V_376 ;
while ( V_383 > 0 && F_345 ( & V_382 , & V_372 -> V_376 [ V_383 - 1 ] ) == 0 )
V_383 -- ;
return V_383 ;
}
static int F_349 ( struct V_73 * V_372 ,
struct V_377 * V_376 , const void * V_366 )
{
int V_50 ;
V_50 = F_348 ( V_372 , V_376 -> V_85 , V_376 -> V_161 ) ;
if ( V_50 < 0 )
return - V_358 ;
while ( V_50 < V_372 -> V_373 &&
F_345 ( V_376 , & V_372 -> V_376 [ V_50 ] ) == 0 ) {
if ( ! F_350 ( V_372 -> V_376 [ V_50 ] . V_95 , V_376 -> V_85 ,
V_376 -> V_161 , V_366 ) )
return V_50 ;
V_50 ++ ;
}
return - V_358 ;
}
int F_351 ( struct V_15 * V_15 , enum V_384 V_385 , T_7 V_85 ,
int V_161 , const void * V_366 )
{
struct V_73 * V_372 ;
struct V_377 V_376 ;
int V_34 ;
V_376 = (struct V_377 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_372 = F_352 ( V_15 -> V_72 [ V_385 ] , & V_15 -> V_51 ) ;
V_34 = F_349 ( V_372 , & V_376 , V_366 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_353 ( struct V_15 * V_15 , enum V_384 V_385 , T_7 V_85 ,
int V_161 , const void * V_366 , long V_386 )
{
struct V_73 * V_372 ;
struct V_377 V_376 ;
V_376 = (struct V_377 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_372 = F_352 ( V_15 -> V_72 [ V_385 ] , & V_15 -> V_51 ) ;
if ( ( V_386 >= 0 ) && ( V_386 < V_372 -> V_373 ) &&
( F_345 ( & V_376 , & V_372 -> V_376 [ V_386 ] ) == 0 ) )
if ( ! F_350 ( V_372 -> V_376 [ V_386 ] . V_95 , V_85 , V_161 ,
V_366 ) )
return V_386 ;
return F_349 ( V_372 , & V_376 , V_366 ) ;
}
static int F_354 ( struct V_73 * V_372 , struct V_377 * V_376 ,
void * V_366 )
{
int V_50 ;
V_50 = F_348 ( V_372 , V_376 -> V_85 , V_376 -> V_161 ) ;
if ( V_50 < 0 )
return - V_358 ;
while ( V_50 < V_372 -> V_373 &&
F_345 ( V_376 , & V_372 -> V_376 [ V_50 ] ) == 0 ) {
if ( ! F_355 ( V_372 -> V_376 [ V_50 ] . V_95 , V_376 -> V_85 ,
V_376 -> V_161 , V_366 ) )
return V_50 ;
V_50 ++ ;
}
return - V_358 ;
}
int F_356 ( struct V_15 * V_15 , enum V_384 V_385 , T_7 V_85 ,
int V_161 , void * V_366 )
{
struct V_73 * V_372 ;
struct V_377 V_376 ;
int V_34 ;
V_376 = (struct V_377 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_372 = F_352 ( V_15 -> V_72 [ V_385 ] , & V_15 -> V_51 ) ;
V_34 = F_354 ( V_372 , & V_376 , V_366 ) ;
return V_34 < 0 ? V_34 : 0 ;
}
int F_357 ( struct V_15 * V_15 , enum V_384 V_385 , T_7 V_85 ,
int V_161 , void * V_366 , long V_386 )
{
struct V_73 * V_372 ;
struct V_377 V_376 ;
V_376 = (struct V_377 ) {
. V_85 = V_85 ,
. V_161 = V_161 ,
} ;
V_372 = F_352 ( V_15 -> V_72 [ V_385 ] , & V_15 -> V_51 ) ;
if ( ( V_386 >= 0 ) && ( V_386 < V_372 -> V_373 ) &&
( F_345 ( & V_376 , & V_372 -> V_376 [ V_386 ] ) == 0 ) )
if ( ! F_355 ( V_372 -> V_376 [ V_386 ] . V_95 , V_85 , V_161 ,
V_366 ) )
return V_386 ;
return F_354 ( V_372 , & V_376 , V_366 ) ;
}
int F_358 ( struct V_15 * V_15 , enum V_384 V_385 , T_7 V_85 ,
int V_161 , struct V_374 * V_95 )
{
struct V_73 * V_387 , * V_372 ;
V_372 = V_15 -> V_72 [ V_385 ] ;
if ( V_372 -> V_373 - V_372 -> V_388 > V_389 - 1 )
return - V_390 ;
V_387 = F_82 ( sizeof( * V_372 ) + ( ( V_372 -> V_373 + 1 ) *
sizeof( struct V_377 ) ) , V_37 ) ;
if ( ! V_387 )
return - V_39 ;
memcpy ( V_387 , V_372 , sizeof( * V_372 ) + ( V_372 -> V_373 *
sizeof( struct V_377 ) ) ) ;
F_347 ( V_387 , V_95 , V_85 , V_161 ) ;
F_9 ( V_15 -> V_72 [ V_385 ] , V_387 ) ;
F_135 ( & V_15 -> V_51 ) ;
F_94 ( V_372 ) ;
return 0 ;
}
int F_359 ( struct V_15 * V_15 , enum V_384 V_385 ,
struct V_374 * V_95 )
{
int V_17 , V_34 ;
struct V_73 * V_387 , * V_372 ;
V_372 = V_15 -> V_72 [ V_385 ] ;
V_34 = - V_147 ;
for ( V_17 = 0 ; V_17 < V_372 -> V_373 ; V_17 ++ )
if ( V_372 -> V_376 [ V_17 ] . V_95 == V_95 ) {
V_34 = 0 ;
break;
}
if ( V_34 )
return V_34 ;
V_387 = F_82 ( sizeof( * V_372 ) + ( ( V_372 -> V_373 - 1 ) *
sizeof( struct V_377 ) ) , V_37 ) ;
if ( ! V_387 )
return - V_39 ;
memcpy ( V_387 , V_372 , sizeof( * V_372 ) + V_17 * sizeof( struct V_377 ) ) ;
V_387 -> V_373 -- ;
memcpy ( V_387 -> V_376 + V_17 , V_372 -> V_376 + V_17 + 1 ,
( V_387 -> V_373 - V_17 ) * sizeof( struct V_377 ) ) ;
F_9 ( V_15 -> V_72 [ V_385 ] , V_387 ) ;
F_135 ( & V_15 -> V_51 ) ;
F_94 ( V_372 ) ;
return V_34 ;
}
static int F_360 ( void * V_391 , T_4 * V_366 )
{
unsigned V_188 = ( long ) V_391 ;
struct V_15 * V_15 ;
* V_366 = 0 ;
F_89 ( & V_81 ) ;
F_361 ( V_15 , & V_82 , V_82 )
* V_366 += * ( T_5 * ) ( ( void * ) V_15 + V_188 ) ;
F_91 ( & V_81 ) ;
return 0 ;
}
static int F_362 ( void * V_391 , T_4 * V_366 )
{
unsigned V_188 = ( long ) V_391 ;
struct V_15 * V_15 ;
struct V_2 * V_3 ;
int V_17 ;
* V_366 = 0 ;
F_89 ( & V_81 ) ;
F_361 (kvm, &vm_list, vm_list)
F_25 ( V_17 , V_3 , V_15 )
* V_366 += * ( T_5 * ) ( ( void * ) V_3 + V_188 ) ;
F_91 ( & V_81 ) ;
return 0 ;
}
static int F_363 ( void )
{
int V_34 = - V_138 ;
struct V_392 * V_273 ;
V_393 = F_364 ( L_8 , NULL ) ;
if ( V_393 == NULL )
goto V_125;
for ( V_273 = V_394 ; V_273 -> V_301 ; ++ V_273 ) {
V_273 -> V_395 = F_365 ( V_273 -> V_301 , 0444 , V_393 ,
( void * ) ( long ) V_273 -> V_188 ,
V_396 [ V_273 -> V_397 ] ) ;
if ( V_273 -> V_395 == NULL )
goto V_398;
}
return 0 ;
V_398:
F_366 ( V_393 ) ;
V_125:
return V_34 ;
}
static void F_367 ( void )
{
struct V_392 * V_273 ;
for ( V_273 = V_394 ; V_273 -> V_301 ; ++ V_273 )
F_368 ( V_273 -> V_395 ) ;
F_368 ( V_393 ) ;
}
static int F_369 ( void )
{
if ( V_363 )
F_337 ( NULL ) ;
return 0 ;
}
static void F_370 ( void )
{
if ( V_363 ) {
F_197 ( F_371 ( & V_81 ) ) ;
F_330 ( NULL ) ;
}
}
static inline
struct V_2 * F_372 ( struct V_13 * V_399 )
{
return F_51 ( V_399 , struct V_2 , V_13 ) ;
}
static void F_373 ( struct V_13 * V_399 , int V_4 )
{
struct V_2 * V_3 = F_372 ( V_399 ) ;
if ( V_3 -> V_42 )
V_3 -> V_42 = false ;
F_14 ( V_3 , V_4 ) ;
}
static void F_374 ( struct V_13 * V_399 ,
struct V_162 * V_400 )
{
struct V_2 * V_3 = F_372 ( V_399 ) ;
if ( V_8 -> V_401 == V_402 )
V_3 -> V_42 = true ;
F_18 ( V_3 ) ;
}
int F_375 ( void * V_403 , unsigned V_404 , unsigned V_405 ,
struct V_406 * V_406 )
{
int V_34 ;
int V_4 ;
V_34 = F_376 ( V_403 ) ;
if ( V_34 )
goto V_407;
V_34 = F_377 () ;
if ( V_34 )
goto V_408;
if ( ! F_24 ( & V_360 , V_37 ) ) {
V_34 = - V_39 ;
goto V_409;
}
V_34 = F_378 () ;
if ( V_34 < 0 )
goto V_410;
F_379 (cpu) {
F_380 ( V_4 ,
V_411 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_412;
}
V_34 = F_381 ( & V_413 ) ;
if ( V_34 )
goto V_414;
F_382 ( & V_415 ) ;
if ( ! V_405 )
V_405 = F_383 ( struct V_2 ) ;
V_416 = F_384 ( L_9 , V_404 , V_405 ,
0 , NULL ) ;
if ( ! V_416 ) {
V_34 = - V_39 ;
goto V_417;
}
V_34 = F_385 () ;
if ( V_34 )
goto V_139;
V_418 . V_419 = V_406 ;
V_341 . V_419 = V_406 ;
V_226 . V_419 = V_406 ;
V_34 = F_386 ( & V_420 ) ;
if ( V_34 ) {
F_335 ( V_421 L_10 ) ;
goto V_422;
}
F_387 ( & V_423 ) ;
V_230 . V_424 = F_373 ;
V_230 . V_425 = F_374 ;
V_34 = F_363 () ;
if ( V_34 ) {
F_335 ( V_421 L_11 ) ;
goto V_426;
}
return 0 ;
V_426:
F_388 ( & V_423 ) ;
F_389 ( & V_420 ) ;
V_422:
F_390 () ;
V_139:
F_391 ( V_416 ) ;
V_417:
F_392 ( & V_415 ) ;
F_393 ( & V_413 ) ;
V_414:
V_412:
F_394 () ;
V_410:
F_32 ( V_360 ) ;
V_409:
F_395 () ;
V_408:
F_396 () ;
V_407:
return V_34 ;
}
void F_397 ( void )
{
F_367 () ;
F_389 ( & V_420 ) ;
F_391 ( V_416 ) ;
F_390 () ;
F_388 ( & V_423 ) ;
F_392 ( & V_415 ) ;
F_393 ( & V_413 ) ;
F_341 ( F_337 , NULL , 1 ) ;
F_394 () ;
F_396 () ;
F_395 () ;
F_32 ( V_360 ) ;
}
