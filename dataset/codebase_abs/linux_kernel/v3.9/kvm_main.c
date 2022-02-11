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
V_37 = F_49 ( V_7 ) ;
if ( V_37 < 0 )
goto V_45;
return 0 ;
V_45:
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
static inline struct V_19 * F_53 ( struct V_46 * V_47 )
{
return F_54 ( V_47 , struct V_19 , V_46 ) ;
}
static void F_55 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_50 )
{
struct V_19 * V_19 = F_53 ( V_47 ) ;
int V_51 , V_52 ;
V_52 = F_56 ( & V_19 -> V_53 ) ;
F_57 ( & V_19 -> V_54 ) ;
V_19 -> V_55 ++ ;
V_51 = F_58 ( V_19 , V_50 ) | V_19 -> V_29 ;
if ( V_51 )
F_36 ( V_19 ) ;
F_59 ( & V_19 -> V_54 ) ;
F_60 ( & V_19 -> V_53 , V_52 ) ;
}
static void F_61 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_50 ,
T_3 V_56 )
{
struct V_19 * V_19 = F_53 ( V_47 ) ;
int V_52 ;
V_52 = F_56 ( & V_19 -> V_53 ) ;
F_57 ( & V_19 -> V_54 ) ;
V_19 -> V_55 ++ ;
F_62 ( V_19 , V_50 , V_56 ) ;
F_59 ( & V_19 -> V_54 ) ;
F_60 ( & V_19 -> V_53 , V_52 ) ;
}
static void F_63 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_57 ,
unsigned long V_58 )
{
struct V_19 * V_19 = F_53 ( V_47 ) ;
int V_51 = 0 , V_52 ;
V_52 = F_56 ( & V_19 -> V_53 ) ;
F_57 ( & V_19 -> V_54 ) ;
V_19 -> V_59 ++ ;
V_51 = F_64 ( V_19 , V_57 , V_58 ) ;
V_51 |= V_19 -> V_29 ;
if ( V_51 )
F_36 ( V_19 ) ;
F_59 ( & V_19 -> V_54 ) ;
F_60 ( & V_19 -> V_53 , V_52 ) ;
}
static void F_65 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_57 ,
unsigned long V_58 )
{
struct V_19 * V_19 = F_53 ( V_47 ) ;
F_57 ( & V_19 -> V_54 ) ;
V_19 -> V_55 ++ ;
F_66 () ;
V_19 -> V_59 -- ;
F_59 ( & V_19 -> V_54 ) ;
F_67 ( V_19 -> V_59 < 0 ) ;
}
static int F_68 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_50 )
{
struct V_19 * V_19 = F_53 ( V_47 ) ;
int V_60 , V_52 ;
V_52 = F_56 ( & V_19 -> V_53 ) ;
F_57 ( & V_19 -> V_54 ) ;
V_60 = F_69 ( V_19 , V_50 ) ;
if ( V_60 )
F_36 ( V_19 ) ;
F_59 ( & V_19 -> V_54 ) ;
F_60 ( & V_19 -> V_53 , V_52 ) ;
return V_60 ;
}
static int F_70 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned long V_50 )
{
struct V_19 * V_19 = F_53 ( V_47 ) ;
int V_60 , V_52 ;
V_52 = F_56 ( & V_19 -> V_53 ) ;
F_57 ( & V_19 -> V_54 ) ;
V_60 = F_71 ( V_19 , V_50 ) ;
F_59 ( & V_19 -> V_54 ) ;
F_60 ( & V_19 -> V_53 , V_52 ) ;
return V_60 ;
}
static void F_72 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_19 * V_19 = F_53 ( V_47 ) ;
int V_52 ;
V_52 = F_56 ( & V_19 -> V_53 ) ;
F_73 ( V_19 ) ;
F_60 ( & V_19 -> V_53 , V_52 ) ;
}
static int F_74 ( struct V_19 * V_19 )
{
V_19 -> V_46 . V_61 = & V_62 ;
return F_75 ( & V_19 -> V_46 , V_12 -> V_49 ) ;
}
static int F_74 ( struct V_19 * V_19 )
{
return 0 ;
}
static void F_76 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_63 * V_64 = V_19 -> V_65 ;
for ( V_21 = 0 ; V_21 < V_66 ; V_21 ++ )
V_64 -> V_67 [ V_21 ] = V_64 -> V_65 [ V_21 ] . V_36 = V_21 ;
}
static struct V_19 * F_77 ( unsigned long type )
{
int V_37 , V_21 ;
struct V_19 * V_19 = F_78 () ;
if ( ! V_19 )
return F_79 ( - V_42 ) ;
V_37 = F_80 ( V_19 , type ) ;
if ( V_37 )
goto V_68;
V_37 = F_81 () ;
if ( V_37 )
goto V_68;
#ifdef F_82
F_83 ( & V_19 -> V_69 ) ;
F_83 ( & V_19 -> V_70 ) ;
#endif
F_84 ( V_66 > V_71 ) ;
V_37 = - V_42 ;
V_19 -> V_65 = F_85 ( sizeof( struct V_63 ) , V_40 ) ;
if ( ! V_19 -> V_65 )
goto V_72;
F_76 ( V_19 ) ;
if ( F_86 ( & V_19 -> V_53 ) )
goto V_72;
for ( V_21 = 0 ; V_21 < V_73 ; V_21 ++ ) {
V_19 -> V_74 [ V_21 ] = F_85 ( sizeof( struct V_75 ) ,
V_40 ) ;
if ( ! V_19 -> V_74 [ V_21 ] )
goto V_76;
}
F_87 ( & V_19 -> V_54 ) ;
V_19 -> V_49 = V_12 -> V_49 ;
F_88 ( & V_19 -> V_49 -> V_77 ) ;
F_89 ( V_19 ) ;
F_42 ( & V_19 -> V_78 ) ;
F_42 ( & V_19 -> V_79 ) ;
F_42 ( & V_19 -> V_80 ) ;
F_90 ( & V_19 -> V_81 , 1 ) ;
V_37 = F_74 ( V_19 ) ;
if ( V_37 )
goto V_76;
F_91 ( & V_82 ) ;
F_92 ( & V_19 -> V_83 , & V_83 ) ;
F_93 ( & V_82 ) ;
return V_19 ;
V_76:
F_94 ( & V_19 -> V_53 ) ;
V_72:
F_95 () ;
V_68:
for ( V_21 = 0 ; V_21 < V_73 ; V_21 ++ )
F_96 ( V_19 -> V_74 [ V_21 ] ) ;
F_96 ( V_19 -> V_65 ) ;
F_97 ( V_19 ) ;
return F_79 ( V_37 ) ;
}
void * F_98 ( unsigned long V_84 )
{
if ( V_84 > V_85 )
return F_99 ( V_84 ) ;
else
return F_85 ( V_84 , V_40 ) ;
}
void F_100 ( const void * V_86 )
{
if ( F_101 ( V_86 ) )
F_102 ( V_86 ) ;
else
F_96 ( V_86 ) ;
}
static void F_103 ( struct V_87 * V_88 )
{
if ( ! V_88 -> V_89 )
return;
F_100 ( V_88 -> V_89 ) ;
V_88 -> V_89 = NULL ;
}
static void F_104 ( struct V_87 * free ,
struct V_87 * V_90 )
{
if ( ! V_90 || free -> V_89 != V_90 -> V_89 )
F_103 ( free ) ;
F_105 ( free , V_90 ) ;
free -> V_91 = 0 ;
}
void F_106 ( struct V_19 * V_19 )
{
struct V_63 * V_64 = V_19 -> V_65 ;
struct V_87 * V_88 ;
F_107 (memslot, slots)
F_104 ( V_88 , NULL ) ;
F_96 ( V_19 -> V_65 ) ;
}
static void F_108 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_48 * V_49 = V_19 -> V_49 ;
F_109 ( V_19 ) ;
F_91 ( & V_82 ) ;
F_110 ( & V_19 -> V_83 ) ;
F_93 ( & V_82 ) ;
F_111 ( V_19 ) ;
for ( V_21 = 0 ; V_21 < V_73 ; V_21 ++ )
F_112 ( V_19 -> V_74 [ V_21 ] ) ;
F_113 ( V_19 ) ;
#if F_114 ( V_92 ) && F_114 ( V_93 )
F_115 ( & V_19 -> V_46 , V_19 -> V_49 ) ;
#else
F_73 ( V_19 ) ;
#endif
F_116 ( V_19 ) ;
F_106 ( V_19 ) ;
F_94 ( & V_19 -> V_53 ) ;
F_97 ( V_19 ) ;
F_95 () ;
F_117 ( V_49 ) ;
}
void F_118 ( struct V_19 * V_19 )
{
F_88 ( & V_19 -> V_81 ) ;
}
void F_119 ( struct V_19 * V_19 )
{
if ( F_120 ( & V_19 -> V_81 ) )
F_108 ( V_19 ) ;
}
static int F_121 ( struct V_94 * V_94 , struct V_95 * V_96 )
{
struct V_19 * V_19 = V_96 -> V_97 ;
F_122 ( V_19 ) ;
F_119 ( V_19 ) ;
return 0 ;
}
static int F_123 ( struct V_87 * V_88 )
{
#ifndef F_124
unsigned long V_98 = 2 * F_125 ( V_88 ) ;
V_88 -> V_89 = F_98 ( V_98 ) ;
if ( ! V_88 -> V_89 )
return - V_42 ;
#endif
return 0 ;
}
static int F_126 ( const void * V_99 , const void * V_100 )
{
struct V_87 * V_101 , * V_102 ;
V_101 = (struct V_87 * ) V_99 ;
V_102 = (struct V_87 * ) V_100 ;
if ( V_101 -> V_91 < V_102 -> V_91 )
return 1 ;
if ( V_101 -> V_91 > V_102 -> V_91 )
return - 1 ;
return 0 ;
}
static void F_127 ( struct V_63 * V_64 )
{
int V_21 ;
F_128 ( V_64 -> V_65 , V_66 ,
sizeof( struct V_87 ) , F_126 , NULL ) ;
for ( V_21 = 0 ; V_21 < V_66 ; V_21 ++ )
V_64 -> V_67 [ V_64 -> V_65 [ V_21 ] . V_36 ] = V_21 ;
}
void F_129 ( struct V_63 * V_64 , struct V_87 * V_103 ,
T_4 V_104 )
{
if ( V_103 ) {
int V_36 = V_103 -> V_36 ;
struct V_87 * V_105 = F_130 ( V_64 , V_36 ) ;
unsigned long V_91 = V_105 -> V_91 ;
* V_105 = * V_103 ;
if ( V_103 -> V_91 != V_91 )
F_127 ( V_64 ) ;
}
V_64 -> V_106 = V_104 + 1 ;
}
static int F_131 ( struct V_107 * V_108 )
{
T_5 V_109 = V_110 ;
#ifdef F_132
V_109 |= V_111 ;
#endif
if ( V_108 -> V_112 & ~ V_109 )
return - V_113 ;
return 0 ;
}
static struct V_63 * F_133 ( struct V_19 * V_19 ,
struct V_63 * V_64 , struct V_87 * V_103 )
{
struct V_63 * V_114 = V_19 -> V_65 ;
F_129 ( V_64 , V_103 , V_19 -> V_65 -> V_106 ) ;
F_12 ( V_19 -> V_65 , V_64 ) ;
F_134 ( & V_19 -> V_53 ) ;
return V_114 ;
}
int F_135 ( struct V_19 * V_19 ,
struct V_107 * V_108 ,
bool V_115 )
{
int V_37 ;
T_6 V_116 ;
unsigned long V_91 ;
struct V_87 * V_117 ;
struct V_87 V_105 , V_103 ;
struct V_63 * V_64 = NULL , * V_114 ;
enum V_118 V_119 ;
V_37 = F_131 ( V_108 ) ;
if ( V_37 )
goto V_120;
V_37 = - V_113 ;
if ( V_108 -> V_121 & ( V_85 - 1 ) )
goto V_120;
if ( V_108 -> V_122 & ( V_85 - 1 ) )
goto V_120;
if ( V_115 &&
( ( V_108 -> V_123 & ( V_85 - 1 ) ) ||
! F_136 ( V_124 ,
( void V_125 * ) ( unsigned long ) V_108 -> V_123 ,
V_108 -> V_121 ) ) )
goto V_120;
if ( V_108 -> V_117 >= V_66 )
goto V_120;
if ( V_108 -> V_122 + V_108 -> V_121 < V_108 -> V_122 )
goto V_120;
V_117 = F_130 ( V_19 -> V_65 , V_108 -> V_117 ) ;
V_116 = V_108 -> V_122 >> V_126 ;
V_91 = V_108 -> V_121 >> V_126 ;
V_37 = - V_113 ;
if ( V_91 > V_127 )
goto V_120;
if ( ! V_91 )
V_108 -> V_112 &= ~ V_110 ;
V_103 = V_105 = * V_117 ;
V_103 . V_36 = V_108 -> V_117 ;
V_103 . V_116 = V_116 ;
V_103 . V_91 = V_91 ;
V_103 . V_112 = V_108 -> V_112 ;
V_37 = - V_113 ;
if ( V_91 ) {
if ( ! V_105 . V_91 )
V_119 = V_128 ;
else {
if ( ( V_108 -> V_123 != V_105 . V_123 ) ||
( V_91 != V_105 . V_91 ) ||
( ( V_103 . V_112 ^ V_105 . V_112 ) & V_111 ) )
goto V_120;
if ( V_116 != V_105 . V_116 )
V_119 = V_129 ;
else if ( V_103 . V_112 != V_105 . V_112 )
V_119 = V_130 ;
else {
V_37 = 0 ;
goto V_120;
}
}
} else if ( V_105 . V_91 ) {
V_119 = V_131 ;
} else
goto V_120;
if ( ( V_119 == V_128 ) || ( V_119 == V_129 ) ) {
V_37 = - V_132 ;
F_107 (slot, kvm->memslots) {
if ( ( V_117 -> V_36 >= V_133 ) ||
( V_117 -> V_36 == V_108 -> V_117 ) )
continue;
if ( ! ( ( V_116 + V_91 <= V_117 -> V_116 ) ||
( V_116 >= V_117 -> V_116 + V_117 -> V_91 ) ) )
goto V_120;
}
}
if ( ! ( V_103 . V_112 & V_110 ) )
V_103 . V_89 = NULL ;
V_37 = - V_42 ;
if ( V_119 == V_128 ) {
V_103 . V_123 = V_108 -> V_123 ;
if ( F_137 ( & V_103 , V_91 ) )
goto V_134;
}
if ( ( V_103 . V_112 & V_110 ) && ! V_103 . V_89 ) {
if ( F_123 ( & V_103 ) < 0 )
goto V_134;
}
if ( ( V_119 == V_131 ) || ( V_119 == V_129 ) ) {
V_37 = - V_42 ;
V_64 = F_138 ( V_19 -> V_65 , sizeof( struct V_63 ) ,
V_40 ) ;
if ( ! V_64 )
goto V_134;
V_117 = F_130 ( V_64 , V_108 -> V_117 ) ;
V_117 -> V_112 |= V_135 ;
V_114 = F_133 ( V_19 , V_64 , NULL ) ;
F_139 ( V_19 , & V_105 ) ;
F_140 ( V_19 , V_117 ) ;
V_64 = V_114 ;
}
V_37 = F_141 ( V_19 , & V_103 , V_105 , V_108 , V_115 ) ;
if ( V_37 )
goto V_136;
V_37 = - V_42 ;
if ( ! V_64 ) {
V_64 = F_138 ( V_19 -> V_65 , sizeof( struct V_63 ) ,
V_40 ) ;
if ( ! V_64 )
goto V_134;
}
if ( ( V_119 == V_128 ) || ( V_119 == V_129 ) ) {
V_37 = F_142 ( V_19 , & V_103 ) ;
if ( V_37 )
goto V_136;
}
if ( V_119 == V_131 ) {
V_103 . V_89 = NULL ;
memset ( & V_103 . V_137 , 0 , sizeof( V_103 . V_137 ) ) ;
}
V_114 = F_133 ( V_19 , V_64 , & V_103 ) ;
F_143 ( V_19 , V_108 , V_105 , V_115 ) ;
F_104 ( & V_105 , & V_103 ) ;
F_96 ( V_114 ) ;
return 0 ;
V_136:
F_96 ( V_64 ) ;
V_134:
F_104 ( & V_103 , & V_105 ) ;
V_120:
return V_37 ;
}
int F_144 ( struct V_19 * V_19 ,
struct V_107 * V_108 ,
bool V_115 )
{
int V_37 ;
F_145 ( & V_19 -> V_80 ) ;
V_37 = F_135 ( V_19 , V_108 , V_115 ) ;
F_24 ( & V_19 -> V_80 ) ;
return V_37 ;
}
int F_146 ( struct V_19 * V_19 ,
struct
V_107 * V_108 ,
bool V_115 )
{
if ( V_108 -> V_117 >= V_133 )
return - V_113 ;
return F_144 ( V_19 , V_108 , V_115 ) ;
}
int F_147 ( struct V_19 * V_19 ,
struct V_138 * log , int * V_139 )
{
struct V_87 * V_88 ;
int V_37 , V_21 ;
unsigned long V_140 ;
unsigned long V_141 = 0 ;
V_37 = - V_113 ;
if ( log -> V_117 >= V_133 )
goto V_120;
V_88 = F_130 ( V_19 -> V_65 , log -> V_117 ) ;
V_37 = - V_142 ;
if ( ! V_88 -> V_89 )
goto V_120;
V_140 = F_125 ( V_88 ) ;
for ( V_21 = 0 ; ! V_141 && V_21 < V_140 / sizeof( long ) ; ++ V_21 )
V_141 = V_88 -> V_89 [ V_21 ] ;
V_37 = - V_143 ;
if ( F_148 ( log -> V_89 , V_88 -> V_89 , V_140 ) )
goto V_120;
if ( V_141 )
* V_139 = 1 ;
V_37 = 0 ;
V_120:
return V_37 ;
}
bool F_149 ( void )
{
return V_144 ;
}
void F_150 ( void )
{
V_144 = false ;
}
struct V_87 * F_151 ( struct V_19 * V_19 , T_6 V_145 )
{
return F_152 ( V_63 ( V_19 ) , V_145 ) ;
}
int F_153 ( struct V_19 * V_19 , T_6 V_145 )
{
struct V_87 * V_88 = F_151 ( V_19 , V_145 ) ;
if ( ! V_88 || V_88 -> V_36 >= V_133 ||
V_88 -> V_112 & V_135 )
return 0 ;
return 1 ;
}
unsigned long F_154 ( struct V_19 * V_19 , T_6 V_145 )
{
struct V_146 * V_147 ;
unsigned long V_86 , V_84 ;
V_84 = V_85 ;
V_86 = F_155 ( V_19 , V_145 ) ;
if ( F_156 ( V_86 ) )
return V_85 ;
F_157 ( & V_12 -> V_49 -> V_148 ) ;
V_147 = F_158 ( V_12 -> V_49 , V_86 ) ;
if ( ! V_147 )
goto V_120;
V_84 = F_159 ( V_147 ) ;
V_120:
F_160 ( & V_12 -> V_49 -> V_148 ) ;
return V_84 ;
}
static bool F_161 ( struct V_87 * V_117 )
{
return V_117 -> V_112 & V_111 ;
}
static unsigned long F_162 ( struct V_87 * V_117 , T_6 V_145 ,
T_6 * V_149 , bool V_150 )
{
if ( ! V_117 || V_117 -> V_112 & V_135 )
return V_151 ;
if ( F_161 ( V_117 ) && V_150 )
return V_152 ;
if ( V_149 )
* V_149 = V_117 -> V_91 - ( V_145 - V_117 -> V_116 ) ;
return F_163 ( V_117 , V_145 ) ;
}
static unsigned long F_164 ( struct V_87 * V_117 , T_6 V_145 ,
T_6 * V_149 )
{
return F_162 ( V_117 , V_145 , V_149 , true ) ;
}
unsigned long F_165 ( struct V_87 * V_117 ,
T_6 V_145 )
{
return F_164 ( V_117 , V_145 , NULL ) ;
}
unsigned long F_155 ( struct V_19 * V_19 , T_6 V_145 )
{
return F_164 ( F_151 ( V_19 , V_145 ) , V_145 , NULL ) ;
}
static unsigned long F_166 ( struct V_19 * V_19 , T_6 V_145 )
{
return F_162 ( F_151 ( V_19 , V_145 ) , V_145 , NULL , false ) ;
}
static int F_167 ( void * V_153 , void V_125 * V_154 , int V_155 )
{
return F_168 ( V_153 , V_154 , V_155 ) ;
}
static int F_169 ( void * V_153 , void V_125 * V_154 , int V_155 )
{
return F_170 ( V_153 , V_154 , V_155 ) ;
}
int F_171 ( struct V_156 * V_157 , struct V_48 * V_49 ,
unsigned long V_57 , int V_150 , struct V_3 * * V_3 )
{
int V_112 = V_158 | V_159 | V_160 | V_161 ;
if ( V_150 )
V_112 |= V_162 ;
return F_172 ( V_157 , V_49 , V_57 , 1 , V_112 , V_3 , NULL , NULL ) ;
}
static inline int F_173 ( unsigned long V_86 )
{
int V_163 , V_112 = V_158 | V_160 | V_162 ;
V_163 = F_172 ( V_12 , V_12 -> V_49 , V_86 , 1 ,
V_112 , NULL , NULL , NULL ) ;
return V_163 == - V_164 ;
}
static bool F_174 ( unsigned long V_86 , bool V_165 , bool * V_166 ,
bool V_167 , bool * V_168 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_91 ;
if ( ! ( V_166 || V_165 ) )
return false ;
if ( ! ( V_167 || V_168 ) )
return false ;
V_91 = F_175 ( V_86 , 1 , 1 , V_3 ) ;
if ( V_91 == 1 ) {
* V_1 = F_176 ( V_3 [ 0 ] ) ;
if ( V_168 )
* V_168 = true ;
return true ;
}
return false ;
}
static int F_177 ( unsigned long V_86 , bool * V_166 , bool V_167 ,
bool * V_168 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_91 = 0 ;
F_178 () ;
if ( V_168 )
* V_168 = V_167 ;
if ( V_166 ) {
F_157 ( & V_12 -> V_49 -> V_148 ) ;
V_91 = F_171 ( V_12 , V_12 -> V_49 ,
V_86 , V_167 , V_3 ) ;
F_160 ( & V_12 -> V_49 -> V_148 ) ;
} else
V_91 = F_179 ( V_86 , 1 , V_167 ,
V_3 ) ;
if ( V_91 != 1 )
return V_91 ;
if ( F_10 ( ! V_167 ) && V_168 ) {
struct V_3 * V_169 [ 1 ] ;
V_91 = F_175 ( V_86 , 1 , 1 , V_169 ) ;
if ( V_91 == 1 ) {
* V_168 = true ;
F_180 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_169 [ 0 ] ;
}
V_91 = 1 ;
}
* V_1 = F_176 ( V_3 [ 0 ] ) ;
return V_91 ;
}
static bool F_181 ( struct V_146 * V_147 , bool V_167 )
{
if ( F_10 ( ! ( V_147 -> V_170 & V_171 ) ) )
return false ;
if ( V_167 && ( F_10 ( ! ( V_147 -> V_170 & V_172 ) ) ) )
return false ;
return true ;
}
static T_1 F_182 ( unsigned long V_86 , bool V_165 , bool * V_166 ,
bool V_167 , bool * V_168 )
{
struct V_146 * V_147 ;
T_1 V_1 = 0 ;
int V_91 ;
F_67 ( V_165 && V_166 ) ;
if ( F_174 ( V_86 , V_165 , V_166 , V_167 , V_168 , & V_1 ) )
return V_1 ;
if ( V_165 )
return V_173 ;
V_91 = F_177 ( V_86 , V_166 , V_167 , V_168 , & V_1 ) ;
if ( V_91 == 1 )
return V_1 ;
F_157 ( & V_12 -> V_49 -> V_148 ) ;
if ( V_91 == - V_164 ||
( ! V_166 && F_173 ( V_86 ) ) ) {
V_1 = V_174 ;
goto exit;
}
V_147 = F_183 ( V_12 -> V_49 , V_86 , V_86 + 1 ) ;
if ( V_147 == NULL )
V_1 = V_173 ;
else if ( ( V_147 -> V_170 & V_175 ) ) {
V_1 = ( ( V_86 - V_147 -> V_176 ) >> V_126 ) +
V_147 -> V_177 ;
F_67 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_166 && F_181 ( V_147 , V_167 ) )
* V_166 = true ;
V_1 = V_173 ;
}
exit:
F_160 ( & V_12 -> V_49 -> V_148 ) ;
return V_1 ;
}
static T_1
F_184 ( struct V_87 * V_117 , T_6 V_145 , bool V_165 ,
bool * V_166 , bool V_167 , bool * V_168 )
{
unsigned long V_86 = F_162 ( V_117 , V_145 , NULL , V_167 ) ;
if ( V_86 == V_152 )
return V_178 ;
if ( F_156 ( V_86 ) )
return V_179 ;
if ( V_168 && F_161 ( V_117 ) ) {
* V_168 = false ;
V_168 = NULL ;
}
return F_182 ( V_86 , V_165 , V_166 , V_167 ,
V_168 ) ;
}
static T_1 F_185 ( struct V_19 * V_19 , T_6 V_145 , bool V_165 , bool * V_166 ,
bool V_167 , bool * V_168 )
{
struct V_87 * V_117 ;
if ( V_166 )
* V_166 = false ;
V_117 = F_151 ( V_19 , V_145 ) ;
return F_184 ( V_117 , V_145 , V_165 , V_166 , V_167 ,
V_168 ) ;
}
T_1 F_186 ( struct V_19 * V_19 , T_6 V_145 )
{
return F_185 ( V_19 , V_145 , true , NULL , true , NULL ) ;
}
T_1 F_187 ( struct V_19 * V_19 , T_6 V_145 , bool * V_166 ,
bool V_167 , bool * V_168 )
{
return F_185 ( V_19 , V_145 , false , V_166 , V_167 , V_168 ) ;
}
T_1 F_188 ( struct V_19 * V_19 , T_6 V_145 )
{
return F_185 ( V_19 , V_145 , false , NULL , true , NULL ) ;
}
T_1 F_189 ( struct V_19 * V_19 , T_6 V_145 , bool V_167 ,
bool * V_168 )
{
return F_185 ( V_19 , V_145 , false , NULL , V_167 , V_168 ) ;
}
T_1 F_190 ( struct V_87 * V_117 , T_6 V_145 )
{
return F_184 ( V_117 , V_145 , false , NULL , true , NULL ) ;
}
T_1 F_191 ( struct V_87 * V_117 , T_6 V_145 )
{
return F_184 ( V_117 , V_145 , true , NULL , true , NULL ) ;
}
int F_192 ( struct V_19 * V_19 , T_6 V_145 , struct V_3 * * V_180 ,
int V_149 )
{
unsigned long V_86 ;
T_6 V_181 ;
V_86 = F_164 ( F_151 ( V_19 , V_145 ) , V_145 , & V_181 ) ;
if ( F_156 ( V_86 ) )
return - 1 ;
if ( V_181 < V_149 )
return 0 ;
return F_175 ( V_86 , V_149 , 1 , V_180 ) ;
}
static struct V_3 * F_193 ( T_1 V_1 )
{
if ( F_194 ( V_1 ) )
return V_182 ;
if ( F_1 ( V_1 ) ) {
F_195 ( 1 ) ;
return V_182 ;
}
return F_3 ( V_1 ) ;
}
struct V_3 * F_196 ( struct V_19 * V_19 , T_6 V_145 )
{
T_1 V_1 ;
V_1 = F_188 ( V_19 , V_145 ) ;
return F_193 ( V_1 ) ;
}
void F_197 ( struct V_3 * V_3 )
{
F_195 ( F_198 ( V_3 ) ) ;
F_199 ( F_176 ( V_3 ) ) ;
}
void F_199 ( T_1 V_1 )
{
if ( ! F_194 ( V_1 ) && ! F_1 ( V_1 ) )
F_180 ( F_3 ( V_1 ) ) ;
}
void F_200 ( struct V_3 * V_3 )
{
F_195 ( F_198 ( V_3 ) ) ;
F_201 ( F_176 ( V_3 ) ) ;
}
void F_201 ( T_1 V_1 )
{
F_202 ( V_1 ) ;
F_199 ( V_1 ) ;
}
void F_203 ( struct V_3 * V_3 )
{
F_202 ( F_176 ( V_3 ) ) ;
}
void F_202 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_204 ( V_3 ) ;
}
}
void F_205 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_206 ( F_3 ( V_1 ) ) ;
}
void F_207 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_208 ( F_3 ( V_1 ) ) ;
}
static int F_209 ( unsigned long V_155 , int V_183 )
{
if ( V_155 > V_85 - V_183 )
return V_85 - V_183 ;
else
return V_155 ;
}
int F_210 ( struct V_19 * V_19 , T_6 V_145 , void * V_153 , int V_183 ,
int V_155 )
{
int V_37 ;
unsigned long V_86 ;
V_86 = F_166 ( V_19 , V_145 ) ;
if ( F_156 ( V_86 ) )
return - V_143 ;
V_37 = F_167 ( V_153 , ( void V_125 * ) V_86 + V_183 , V_155 ) ;
if ( V_37 )
return - V_143 ;
return 0 ;
}
int F_211 ( struct V_19 * V_19 , T_7 V_184 , void * V_153 , unsigned long V_155 )
{
T_6 V_145 = V_184 >> V_126 ;
int V_185 ;
int V_183 = F_212 ( V_184 ) ;
int V_186 ;
while ( ( V_185 = F_209 ( V_155 , V_183 ) ) != 0 ) {
V_186 = F_210 ( V_19 , V_145 , V_153 , V_183 , V_185 ) ;
if ( V_186 < 0 )
return V_186 ;
V_183 = 0 ;
V_155 -= V_185 ;
V_153 += V_185 ;
++ V_145 ;
}
return 0 ;
}
int F_213 ( struct V_19 * V_19 , T_7 V_184 , void * V_153 ,
unsigned long V_155 )
{
int V_37 ;
unsigned long V_86 ;
T_6 V_145 = V_184 >> V_126 ;
int V_183 = F_212 ( V_184 ) ;
V_86 = F_166 ( V_19 , V_145 ) ;
if ( F_156 ( V_86 ) )
return - V_143 ;
F_214 () ;
V_37 = F_169 ( V_153 , ( void V_125 * ) V_86 + V_183 , V_155 ) ;
F_215 () ;
if ( V_37 )
return - V_143 ;
return 0 ;
}
int F_216 ( struct V_19 * V_19 , T_6 V_145 , const void * V_153 ,
int V_183 , int V_155 )
{
int V_37 ;
unsigned long V_86 ;
V_86 = F_155 ( V_19 , V_145 ) ;
if ( F_156 ( V_86 ) )
return - V_143 ;
V_37 = F_217 ( ( void V_125 * ) V_86 + V_183 , V_153 , V_155 ) ;
if ( V_37 )
return - V_143 ;
F_218 ( V_19 , V_145 ) ;
return 0 ;
}
int F_219 ( struct V_19 * V_19 , T_7 V_184 , const void * V_153 ,
unsigned long V_155 )
{
T_6 V_145 = V_184 >> V_126 ;
int V_185 ;
int V_183 = F_212 ( V_184 ) ;
int V_186 ;
while ( ( V_185 = F_209 ( V_155 , V_183 ) ) != 0 ) {
V_186 = F_216 ( V_19 , V_145 , V_153 , V_183 , V_185 ) ;
if ( V_186 < 0 )
return V_186 ;
V_183 = 0 ;
V_155 -= V_185 ;
V_153 += V_185 ;
++ V_145 ;
}
return 0 ;
}
int F_220 ( struct V_19 * V_19 , struct V_187 * V_188 ,
T_7 V_184 , unsigned long V_155 )
{
struct V_63 * V_64 = V_63 ( V_19 ) ;
int V_183 = F_212 ( V_184 ) ;
T_6 V_189 = V_184 >> V_126 ;
T_6 V_190 = ( V_184 + V_155 - 1 ) >> V_126 ;
T_6 V_191 = V_190 - V_189 + 1 ;
T_6 V_192 ;
V_188 -> V_184 = V_184 ;
V_188 -> V_106 = V_64 -> V_106 ;
V_188 -> V_155 = V_155 ;
V_188 -> V_88 = F_151 ( V_19 , V_189 ) ;
V_188 -> V_154 = F_164 ( V_188 -> V_88 , V_189 , & V_192 ) ;
if ( ! F_156 ( V_188 -> V_154 ) && V_192 >= V_191 ) {
V_188 -> V_154 += V_183 ;
} else {
while ( V_189 <= V_190 ) {
V_188 -> V_88 = F_151 ( V_19 , V_189 ) ;
V_188 -> V_154 = F_164 ( V_188 -> V_88 , V_189 ,
& V_192 ) ;
if ( F_156 ( V_188 -> V_154 ) )
return - V_143 ;
V_189 += V_192 ;
}
V_188 -> V_88 = NULL ;
}
return 0 ;
}
int F_221 ( struct V_19 * V_19 , struct V_187 * V_188 ,
void * V_153 , unsigned long V_155 )
{
struct V_63 * V_64 = V_63 ( V_19 ) ;
int V_37 ;
F_67 ( V_155 > V_188 -> V_155 ) ;
if ( V_64 -> V_106 != V_188 -> V_106 )
F_220 ( V_19 , V_188 , V_188 -> V_184 , V_188 -> V_155 ) ;
if ( F_10 ( ! V_188 -> V_88 ) )
return F_219 ( V_19 , V_188 -> V_184 , V_153 , V_155 ) ;
if ( F_156 ( V_188 -> V_154 ) )
return - V_143 ;
V_37 = F_217 ( ( void V_125 * ) V_188 -> V_154 , V_153 , V_155 ) ;
if ( V_37 )
return - V_143 ;
F_222 ( V_19 , V_188 -> V_88 , V_188 -> V_184 >> V_126 ) ;
return 0 ;
}
int F_223 ( struct V_19 * V_19 , struct V_187 * V_188 ,
void * V_153 , unsigned long V_155 )
{
struct V_63 * V_64 = V_63 ( V_19 ) ;
int V_37 ;
F_67 ( V_155 > V_188 -> V_155 ) ;
if ( V_64 -> V_106 != V_188 -> V_106 )
F_220 ( V_19 , V_188 , V_188 -> V_184 , V_188 -> V_155 ) ;
if ( F_10 ( ! V_188 -> V_88 ) )
return F_211 ( V_19 , V_188 -> V_184 , V_153 , V_155 ) ;
if ( F_156 ( V_188 -> V_154 ) )
return - V_143 ;
V_37 = F_168 ( V_153 , ( void V_125 * ) V_188 -> V_154 , V_155 ) ;
if ( V_37 )
return - V_143 ;
return 0 ;
}
int F_224 ( struct V_19 * V_19 , T_6 V_145 , int V_183 , int V_155 )
{
return F_216 ( V_19 , V_145 , ( const void * ) V_193 ,
V_183 , V_155 ) ;
}
int F_225 ( struct V_19 * V_19 , T_7 V_184 , unsigned long V_155 )
{
T_6 V_145 = V_184 >> V_126 ;
int V_185 ;
int V_183 = F_212 ( V_184 ) ;
int V_186 ;
while ( ( V_185 = F_209 ( V_155 , V_183 ) ) != 0 ) {
V_186 = F_224 ( V_19 , V_145 , V_183 , V_185 ) ;
if ( V_186 < 0 )
return V_186 ;
V_183 = 0 ;
V_155 -= V_185 ;
++ V_145 ;
}
return 0 ;
}
void F_222 ( struct V_19 * V_19 , struct V_87 * V_88 ,
T_6 V_145 )
{
if ( V_88 && V_88 -> V_89 ) {
unsigned long V_194 = V_145 - V_88 -> V_116 ;
F_226 ( V_194 , V_88 -> V_89 ) ;
}
}
void F_218 ( struct V_19 * V_19 , T_6 V_145 )
{
struct V_87 * V_88 ;
V_88 = F_151 ( V_19 , V_145 ) ;
F_222 ( V_19 , V_88 , V_145 ) ;
}
void F_227 ( struct V_6 * V_7 )
{
F_228 ( V_195 ) ;
for (; ; ) {
F_229 ( & V_7 -> V_39 , & V_195 , V_196 ) ;
if ( F_230 ( V_7 ) ) {
F_29 ( V_197 , V_7 ) ;
break;
}
if ( F_231 ( V_7 ) )
break;
if ( F_232 ( V_12 ) )
break;
F_233 () ;
}
F_234 ( & V_7 -> V_39 , & V_195 ) ;
}
void F_235 ( struct V_6 * V_7 )
{
int V_22 ;
int V_8 = V_7 -> V_8 ;
T_8 * V_198 ;
V_198 = F_236 ( V_7 ) ;
if ( F_237 ( V_198 ) ) {
F_238 ( V_198 ) ;
++ V_7 -> V_31 . V_199 ;
}
V_22 = F_15 () ;
if ( V_8 != V_22 && ( unsigned ) V_8 < V_200 && F_239 ( V_8 ) )
if ( F_240 ( V_7 ) )
F_241 ( V_8 ) ;
F_18 () ;
}
void F_242 ( struct V_6 * V_7 )
{
if ( ! F_243 () )
return;
F_244 () ;
}
bool F_245 ( struct V_6 * V_201 )
{
struct V_11 * V_11 ;
struct V_156 * V_202 = NULL ;
bool V_186 = false ;
F_246 () ;
V_11 = F_247 ( V_201 -> V_11 ) ;
if ( V_11 )
V_202 = F_248 ( V_201 -> V_11 , V_14 ) ;
F_249 () ;
if ( ! V_202 )
return V_186 ;
if ( V_202 -> V_112 & V_203 ) {
F_250 ( V_202 ) ;
return V_186 ;
}
V_186 = F_251 ( V_202 , 1 ) ;
F_250 ( V_202 ) ;
return V_186 ;
}
bool F_252 ( struct V_6 * V_7 )
{
bool V_204 ;
V_204 = ! V_7 -> V_205 . V_206 ||
( V_7 -> V_205 . V_206 &&
V_7 -> V_205 . V_207 ) ;
if ( V_7 -> V_205 . V_206 )
F_48 ( V_7 , ! V_7 -> V_205 . V_207 ) ;
return V_204 ;
}
void F_253 ( struct V_6 * V_22 )
{
struct V_19 * V_19 = V_22 -> V_19 ;
struct V_6 * V_7 ;
int V_208 = V_22 -> V_19 -> V_208 ;
int V_209 = 0 ;
int V_210 = 3 ;
int V_211 ;
int V_21 ;
F_47 ( V_22 , true ) ;
for ( V_211 = 0 ; V_211 < 2 && ! V_209 && V_210 ; V_211 ++ ) {
F_28 (i, vcpu, kvm) {
if ( ! V_211 && V_21 <= V_208 ) {
V_21 = V_208 ;
continue;
} else if ( V_211 && V_21 > V_208 )
break;
if ( V_7 == V_22 )
continue;
if ( F_237 ( & V_7 -> V_39 ) )
continue;
if ( ! F_252 ( V_7 ) )
continue;
V_209 = F_245 ( V_7 ) ;
if ( V_209 > 0 ) {
V_19 -> V_208 = V_21 ;
break;
} else if ( V_209 < 0 ) {
V_210 -- ;
if ( ! V_210 )
break;
}
}
}
F_47 ( V_22 , false ) ;
F_48 ( V_22 , false ) ;
}
static int F_254 ( struct V_146 * V_147 , struct V_212 * V_213 )
{
struct V_6 * V_7 = V_147 -> V_214 -> V_97 ;
struct V_3 * V_3 ;
if ( V_213 -> V_215 == 0 )
V_3 = F_255 ( V_7 -> V_44 ) ;
#ifdef F_256
else if ( V_213 -> V_215 == V_216 )
V_3 = F_255 ( V_7 -> V_137 . V_217 ) ;
#endif
#ifdef F_257
else if ( V_213 -> V_215 == F_257 )
V_3 = F_255 ( V_7 -> V_19 -> V_218 ) ;
#endif
else
return F_258 ( V_7 , V_213 ) ;
F_208 ( V_3 ) ;
V_213 -> V_3 = V_3 ;
return 0 ;
}
static int F_259 ( struct V_95 * V_95 , struct V_146 * V_147 )
{
V_147 -> V_219 = & V_220 ;
return 0 ;
}
static int F_260 ( struct V_94 * V_94 , struct V_95 * V_96 )
{
struct V_6 * V_7 = V_96 -> V_97 ;
F_119 ( V_7 -> V_19 ) ;
return 0 ;
}
static int F_261 ( struct V_6 * V_7 )
{
return F_262 ( L_1 , & V_221 , V_7 , V_222 ) ;
}
static int F_263 ( struct V_19 * V_19 , T_5 V_36 )
{
int V_37 ;
struct V_6 * V_7 , * V_223 ;
V_7 = F_264 ( V_19 , V_36 ) ;
if ( F_265 ( V_7 ) )
return F_266 ( V_7 ) ;
F_267 ( & V_7 -> V_17 , & V_224 ) ;
V_37 = F_268 ( V_7 ) ;
if ( V_37 )
goto V_225;
F_145 ( & V_19 -> V_78 ) ;
if ( ! F_269 ( V_7 ) ) {
V_37 = - V_113 ;
goto V_226;
}
if ( F_270 ( & V_19 -> V_227 ) == V_228 ) {
V_37 = - V_113 ;
goto V_226;
}
F_28 (r, v, kvm)
if ( V_223 -> V_38 == V_36 ) {
V_37 = - V_132 ;
goto V_226;
}
F_67 ( V_19 -> V_229 [ F_270 ( & V_19 -> V_227 ) ] ) ;
F_118 ( V_19 ) ;
V_37 = F_261 ( V_7 ) ;
if ( V_37 < 0 ) {
F_119 ( V_19 ) ;
goto V_226;
}
V_19 -> V_229 [ F_270 ( & V_19 -> V_227 ) ] = V_7 ;
F_66 () ;
F_88 ( & V_19 -> V_227 ) ;
F_24 ( & V_19 -> V_78 ) ;
F_271 ( V_7 ) ;
return V_37 ;
V_226:
F_24 ( & V_19 -> V_78 ) ;
V_225:
F_272 ( V_7 ) ;
return V_37 ;
}
static int F_273 ( struct V_6 * V_7 , T_9 * V_230 )
{
if ( V_230 ) {
F_274 ( V_230 , F_275 ( V_231 ) | F_275 ( V_232 ) ) ;
V_7 -> V_233 = 1 ;
V_7 -> V_230 = * V_230 ;
} else
V_7 -> V_233 = 0 ;
return 0 ;
}
static long F_276 ( struct V_95 * V_96 ,
unsigned int V_234 , unsigned long V_235 )
{
struct V_6 * V_7 = V_96 -> V_97 ;
void V_125 * V_236 = ( void V_125 * ) V_235 ;
int V_37 ;
struct V_237 * V_238 = NULL ;
struct V_239 * V_239 = NULL ;
if ( V_7 -> V_19 -> V_49 != V_12 -> V_49 )
return - V_240 ;
#if F_114 ( F_124 ) || F_114 ( V_241 )
if ( V_234 == V_242 || V_234 == V_243 )
return F_277 ( V_96 , V_234 , V_235 ) ;
#endif
V_37 = F_8 ( V_7 ) ;
if ( V_37 )
return V_37 ;
switch ( V_234 ) {
case V_244 :
V_37 = - V_113 ;
if ( V_235 )
goto V_120;
V_37 = F_278 ( V_7 , V_7 -> V_44 ) ;
F_279 ( V_7 -> V_44 -> V_245 , V_37 ) ;
break;
case V_246 : {
struct V_247 * V_247 ;
V_37 = - V_42 ;
V_247 = F_85 ( sizeof( struct V_247 ) , V_40 ) ;
if ( ! V_247 )
goto V_120;
V_37 = F_280 ( V_7 , V_247 ) ;
if ( V_37 )
goto V_248;
V_37 = - V_143 ;
if ( F_148 ( V_236 , V_247 , sizeof( struct V_247 ) ) )
goto V_248;
V_37 = 0 ;
V_248:
F_96 ( V_247 ) ;
break;
}
case V_249 : {
struct V_247 * V_247 ;
V_37 = - V_42 ;
V_247 = F_281 ( V_236 , sizeof( * V_247 ) ) ;
if ( F_265 ( V_247 ) ) {
V_37 = F_266 ( V_247 ) ;
goto V_120;
}
V_37 = F_282 ( V_7 , V_247 ) ;
F_96 ( V_247 ) ;
break;
}
case V_250 : {
V_239 = F_85 ( sizeof( struct V_239 ) , V_40 ) ;
V_37 = - V_42 ;
if ( ! V_239 )
goto V_120;
V_37 = F_283 ( V_7 , V_239 ) ;
if ( V_37 )
goto V_120;
V_37 = - V_143 ;
if ( F_148 ( V_236 , V_239 , sizeof( struct V_239 ) ) )
goto V_120;
V_37 = 0 ;
break;
}
case V_251 : {
V_239 = F_281 ( V_236 , sizeof( * V_239 ) ) ;
if ( F_265 ( V_239 ) ) {
V_37 = F_266 ( V_239 ) ;
V_239 = NULL ;
goto V_120;
}
V_37 = F_284 ( V_7 , V_239 ) ;
break;
}
case V_252 : {
struct V_253 V_254 ;
V_37 = F_285 ( V_7 , & V_254 ) ;
if ( V_37 )
goto V_120;
V_37 = - V_143 ;
if ( F_148 ( V_236 , & V_254 , sizeof V_254 ) )
goto V_120;
V_37 = 0 ;
break;
}
case V_255 : {
struct V_253 V_254 ;
V_37 = - V_143 ;
if ( F_286 ( & V_254 , V_236 , sizeof V_254 ) )
goto V_120;
V_37 = F_287 ( V_7 , & V_254 ) ;
break;
}
case V_256 : {
struct V_257 V_258 ;
V_37 = - V_143 ;
if ( F_286 ( & V_258 , V_236 , sizeof V_258 ) )
goto V_120;
V_37 = F_288 ( V_7 , & V_258 ) ;
if ( V_37 )
goto V_120;
V_37 = - V_143 ;
if ( F_148 ( V_236 , & V_258 , sizeof V_258 ) )
goto V_120;
V_37 = 0 ;
break;
}
case V_259 : {
struct V_260 V_261 ;
V_37 = - V_143 ;
if ( F_286 ( & V_261 , V_236 , sizeof V_261 ) )
goto V_120;
V_37 = F_289 ( V_7 , & V_261 ) ;
break;
}
case V_262 : {
struct V_263 V_125 * V_264 = V_236 ;
struct V_263 V_265 ;
T_9 V_230 , * V_266 ;
V_266 = NULL ;
if ( V_236 ) {
V_37 = - V_143 ;
if ( F_286 ( & V_265 , V_236 ,
sizeof V_265 ) )
goto V_120;
V_37 = - V_113 ;
if ( V_265 . V_155 != sizeof V_230 )
goto V_120;
V_37 = - V_143 ;
if ( F_286 ( & V_230 , V_264 -> V_230 ,
sizeof V_230 ) )
goto V_120;
V_266 = & V_230 ;
}
V_37 = F_273 ( V_7 , V_266 ) ;
break;
}
case V_267 : {
V_238 = F_85 ( sizeof( struct V_237 ) , V_40 ) ;
V_37 = - V_42 ;
if ( ! V_238 )
goto V_120;
V_37 = F_290 ( V_7 , V_238 ) ;
if ( V_37 )
goto V_120;
V_37 = - V_143 ;
if ( F_148 ( V_236 , V_238 , sizeof( struct V_237 ) ) )
goto V_120;
V_37 = 0 ;
break;
}
case V_268 : {
V_238 = F_281 ( V_236 , sizeof( * V_238 ) ) ;
if ( F_265 ( V_238 ) ) {
V_37 = F_266 ( V_238 ) ;
V_238 = NULL ;
goto V_120;
}
V_37 = F_291 ( V_7 , V_238 ) ;
break;
}
default:
V_37 = F_277 ( V_96 , V_234 , V_235 ) ;
}
V_120:
F_19 ( V_7 ) ;
F_96 ( V_238 ) ;
F_96 ( V_239 ) ;
return V_37 ;
}
static long F_292 ( struct V_95 * V_96 ,
unsigned int V_234 , unsigned long V_235 )
{
struct V_6 * V_7 = V_96 -> V_97 ;
void V_125 * V_236 = F_293 ( V_235 ) ;
int V_37 ;
if ( V_7 -> V_19 -> V_49 != V_12 -> V_49 )
return - V_240 ;
switch ( V_234 ) {
case V_262 : {
struct V_263 V_125 * V_264 = V_236 ;
struct V_263 V_265 ;
T_10 V_269 ;
T_9 V_230 ;
if ( V_236 ) {
V_37 = - V_143 ;
if ( F_286 ( & V_265 , V_236 ,
sizeof V_265 ) )
goto V_120;
V_37 = - V_113 ;
if ( V_265 . V_155 != sizeof V_269 )
goto V_120;
V_37 = - V_143 ;
if ( F_286 ( & V_269 , V_264 -> V_230 ,
sizeof V_269 ) )
goto V_120;
F_294 ( & V_230 , & V_269 ) ;
V_37 = F_273 ( V_7 , & V_230 ) ;
} else
V_37 = F_273 ( V_7 , NULL ) ;
break;
}
default:
V_37 = F_276 ( V_96 , V_234 , V_235 ) ;
}
V_120:
return V_37 ;
}
static long F_295 ( struct V_95 * V_96 ,
unsigned int V_234 , unsigned long V_235 )
{
struct V_19 * V_19 = V_96 -> V_97 ;
void V_125 * V_236 = ( void V_125 * ) V_235 ;
int V_37 ;
if ( V_19 -> V_49 != V_12 -> V_49 )
return - V_240 ;
switch ( V_234 ) {
case V_270 :
V_37 = F_263 ( V_19 , V_235 ) ;
break;
case V_271 : {
struct V_107 V_272 ;
V_37 = - V_143 ;
if ( F_286 ( & V_272 , V_236 ,
sizeof V_272 ) )
goto V_120;
V_37 = F_146 ( V_19 , & V_272 , true ) ;
break;
}
case V_273 : {
struct V_138 log ;
V_37 = - V_143 ;
if ( F_286 ( & log , V_236 , sizeof log ) )
goto V_120;
V_37 = F_296 ( V_19 , & log ) ;
break;
}
#ifdef F_257
case V_274 : {
struct V_275 V_276 ;
V_37 = - V_143 ;
if ( F_286 ( & V_276 , V_236 , sizeof V_276 ) )
goto V_120;
V_37 = F_297 ( V_19 , & V_276 ) ;
break;
}
case V_277 : {
struct V_275 V_276 ;
V_37 = - V_143 ;
if ( F_286 ( & V_276 , V_236 , sizeof V_276 ) )
goto V_120;
V_37 = F_298 ( V_19 , & V_276 ) ;
break;
}
#endif
case V_278 : {
struct V_279 V_153 ;
V_37 = - V_143 ;
if ( F_286 ( & V_153 , V_236 , sizeof V_153 ) )
goto V_120;
V_37 = V_279 ( V_19 , & V_153 ) ;
break;
}
case V_280 : {
struct V_281 V_153 ;
V_37 = - V_143 ;
if ( F_286 ( & V_153 , V_236 , sizeof V_153 ) )
goto V_120;
V_37 = V_281 ( V_19 , & V_153 ) ;
break;
}
#ifdef F_299
case V_282 :
V_37 = 0 ;
F_145 ( & V_19 -> V_78 ) ;
if ( F_270 ( & V_19 -> V_227 ) != 0 )
V_37 = - V_283 ;
else
V_19 -> V_284 = V_235 ;
F_24 ( & V_19 -> V_78 ) ;
break;
#endif
#ifdef F_300
case V_285 : {
struct V_286 V_287 ;
V_37 = - V_143 ;
if ( F_286 ( & V_287 , V_236 , sizeof V_287 ) )
goto V_120;
V_37 = F_301 ( V_19 , & V_287 ) ;
break;
}
#endif
#ifdef F_302
case V_288 :
case V_289 : {
struct V_290 V_291 ;
V_37 = - V_143 ;
if ( F_286 ( & V_291 , V_236 , sizeof V_291 ) )
goto V_120;
V_37 = F_303 ( V_19 , & V_291 ) ;
if ( V_37 )
goto V_120;
V_37 = - V_143 ;
if ( V_234 == V_288 ) {
if ( F_148 ( V_236 , & V_291 , sizeof V_291 ) )
goto V_120;
}
V_37 = 0 ;
break;
}
#endif
default:
V_37 = F_304 ( V_96 , V_234 , V_235 ) ;
if ( V_37 == - V_292 )
V_37 = F_305 ( V_19 , V_234 , V_235 ) ;
}
V_120:
return V_37 ;
}
static long F_306 ( struct V_95 * V_96 ,
unsigned int V_234 , unsigned long V_235 )
{
struct V_19 * V_19 = V_96 -> V_97 ;
int V_37 ;
if ( V_19 -> V_49 != V_12 -> V_49 )
return - V_240 ;
switch ( V_234 ) {
case V_273 : {
struct V_293 V_294 ;
struct V_138 log ;
V_37 = - V_143 ;
if ( F_286 ( & V_294 , ( void V_125 * ) V_235 ,
sizeof( V_294 ) ) )
goto V_120;
log . V_117 = V_294 . V_117 ;
log . V_295 = V_294 . V_295 ;
log . V_296 = V_294 . V_296 ;
log . V_89 = F_293 ( V_294 . V_89 ) ;
V_37 = F_296 ( V_19 , & log ) ;
break;
}
default:
V_37 = F_295 ( V_96 , V_234 , V_235 ) ;
}
V_120:
return V_37 ;
}
static int F_307 ( struct V_146 * V_147 , struct V_212 * V_213 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_86 ;
int V_91 ;
T_6 V_145 = V_213 -> V_215 ;
struct V_19 * V_19 = V_147 -> V_214 -> V_97 ;
V_86 = F_155 ( V_19 , V_145 ) ;
if ( F_156 ( V_86 ) )
return V_297 ;
V_91 = F_308 ( V_12 , V_12 -> V_49 , V_86 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_91 != 1 ) )
return V_297 ;
V_213 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_309 ( struct V_95 * V_95 , struct V_146 * V_147 )
{
V_147 -> V_219 = & V_298 ;
return 0 ;
}
static int F_310 ( unsigned long type )
{
int V_37 ;
struct V_19 * V_19 ;
V_19 = F_77 ( type ) ;
if ( F_265 ( V_19 ) )
return F_266 ( V_19 ) ;
#ifdef F_257
V_37 = F_311 ( V_19 ) ;
if ( V_37 < 0 ) {
F_119 ( V_19 ) ;
return V_37 ;
}
#endif
V_37 = F_262 ( L_2 , & V_299 , V_19 , V_222 ) ;
if ( V_37 < 0 )
F_119 ( V_19 ) ;
return V_37 ;
}
static long F_312 ( long V_235 )
{
switch ( V_235 ) {
case V_300 :
case V_301 :
case V_302 :
#ifdef F_299
case V_303 :
#endif
case V_304 :
#ifdef F_300
case V_305 :
#endif
return 1 ;
#ifdef F_313
case F_313 :
return V_306 ;
#endif
default:
break;
}
return F_314 ( V_235 ) ;
}
static long F_315 ( struct V_95 * V_96 ,
unsigned int V_234 , unsigned long V_235 )
{
long V_37 = - V_113 ;
switch ( V_234 ) {
case V_307 :
V_37 = - V_113 ;
if ( V_235 )
goto V_120;
V_37 = V_308 ;
break;
case V_309 :
V_37 = F_310 ( V_235 ) ;
break;
case V_310 :
V_37 = F_312 ( V_235 ) ;
break;
case V_311 :
V_37 = - V_113 ;
if ( V_235 )
goto V_120;
V_37 = V_85 ;
#ifdef F_256
V_37 += V_85 ;
#endif
#ifdef F_257
V_37 += V_85 ;
#endif
break;
case V_312 :
case V_313 :
case V_314 :
V_37 = - V_315 ;
break;
default:
return F_316 ( V_96 , V_234 , V_235 ) ;
}
V_120:
return V_37 ;
}
static void F_317 ( void * V_316 )
{
int V_8 = F_318 () ;
int V_37 ;
if ( F_319 ( V_8 , V_317 ) )
return;
F_32 ( V_8 , V_317 ) ;
V_37 = F_320 ( NULL ) ;
if ( V_37 ) {
F_321 ( V_8 , V_317 ) ;
F_88 ( & V_318 ) ;
F_322 ( V_319 L_3
L_4 , V_8 ) ;
}
}
static void F_323 ( void * V_316 )
{
F_91 ( & V_82 ) ;
F_317 ( V_316 ) ;
F_93 ( & V_82 ) ;
}
static void F_324 ( void * V_316 )
{
int V_8 = F_318 () ;
if ( ! F_319 ( V_8 , V_317 ) )
return;
F_321 ( V_8 , V_317 ) ;
F_325 ( NULL ) ;
}
static void F_326 ( void * V_316 )
{
F_91 ( & V_82 ) ;
F_324 ( V_316 ) ;
F_93 ( & V_82 ) ;
}
static void F_327 ( void )
{
F_67 ( ! V_320 ) ;
V_320 -- ;
if ( ! V_320 )
F_328 ( F_324 , NULL , 1 ) ;
}
static void F_95 ( void )
{
F_91 ( & V_82 ) ;
F_327 () ;
F_93 ( & V_82 ) ;
}
static int F_81 ( void )
{
int V_37 = 0 ;
F_91 ( & V_82 ) ;
V_320 ++ ;
if ( V_320 == 1 ) {
F_90 ( & V_318 , 0 ) ;
F_328 ( F_317 , NULL , 1 ) ;
if ( F_270 ( & V_318 ) ) {
F_327 () ;
V_37 = - V_283 ;
}
}
F_93 ( & V_82 ) ;
return V_37 ;
}
static int F_329 ( struct V_321 * V_322 , unsigned long V_323 ,
void * V_223 )
{
int V_8 = ( long ) V_223 ;
if ( ! V_320 )
return V_324 ;
V_323 &= ~ V_325 ;
switch ( V_323 ) {
case V_326 :
F_322 ( V_319 L_5 ,
V_8 ) ;
F_326 ( NULL ) ;
break;
case V_327 :
F_322 ( V_319 L_6 ,
V_8 ) ;
F_323 ( NULL ) ;
break;
}
return V_324 ;
}
T_11 void F_330 ( void )
{
F_331 () ;
}
static int F_332 ( struct V_321 * V_322 , unsigned long V_323 ,
void * V_223 )
{
F_322 ( V_319 L_7 ) ;
V_328 = true ;
F_328 ( F_324 , NULL , 1 ) ;
return V_324 ;
}
static void F_112 ( struct V_75 * V_329 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_329 -> V_330 ; V_21 ++ ) {
struct V_331 * V_332 = V_329 -> V_333 [ V_21 ] . V_334 ;
F_333 ( V_332 ) ;
}
F_96 ( V_329 ) ;
}
int F_334 ( const void * V_335 , const void * V_336 )
{
const struct V_337 * V_338 = V_335 ;
const struct V_337 * V_339 = V_336 ;
if ( V_338 -> V_86 < V_339 -> V_86 )
return - 1 ;
if ( V_338 -> V_86 + V_338 -> V_155 > V_339 -> V_86 + V_339 -> V_155 )
return 1 ;
return 0 ;
}
int F_335 ( struct V_75 * V_329 , struct V_331 * V_334 ,
T_7 V_86 , int V_155 )
{
V_329 -> V_333 [ V_329 -> V_330 ++ ] = (struct V_337 ) {
. V_86 = V_86 ,
. V_155 = V_155 ,
. V_334 = V_334 ,
} ;
F_128 ( V_329 -> V_333 , V_329 -> V_330 , sizeof( struct V_337 ) ,
F_334 , NULL ) ;
return 0 ;
}
int F_336 ( struct V_75 * V_329 ,
T_7 V_86 , int V_155 )
{
struct V_337 * V_333 , V_340 ;
int V_341 ;
V_340 = (struct V_337 ) {
. V_86 = V_86 ,
. V_155 = V_155 ,
} ;
V_333 = bsearch ( & V_340 , V_329 -> V_333 , V_329 -> V_330 ,
sizeof( struct V_337 ) , F_334 ) ;
if ( V_333 == NULL )
return - V_142 ;
V_341 = V_333 - V_329 -> V_333 ;
while ( V_341 > 0 && F_334 ( & V_340 , & V_329 -> V_333 [ V_341 - 1 ] ) == 0 )
V_341 -- ;
return V_341 ;
}
int F_337 ( struct V_19 * V_19 , enum V_342 V_343 , T_7 V_86 ,
int V_155 , const void * V_323 )
{
int V_52 ;
struct V_75 * V_329 ;
struct V_337 V_333 ;
V_333 = (struct V_337 ) {
. V_86 = V_86 ,
. V_155 = V_155 ,
} ;
V_329 = F_338 ( V_19 -> V_74 [ V_343 ] , & V_19 -> V_53 ) ;
V_52 = F_336 ( V_329 , V_86 , V_155 ) ;
if ( V_52 < 0 )
return - V_315 ;
while ( V_52 < V_329 -> V_330 &&
F_334 ( & V_333 , & V_329 -> V_333 [ V_52 ] ) == 0 ) {
if ( ! F_339 ( V_329 -> V_333 [ V_52 ] . V_334 , V_86 , V_155 , V_323 ) )
return 0 ;
V_52 ++ ;
}
return - V_315 ;
}
int F_340 ( struct V_19 * V_19 , enum V_342 V_343 , T_7 V_86 ,
int V_155 , void * V_323 )
{
int V_52 ;
struct V_75 * V_329 ;
struct V_337 V_333 ;
V_333 = (struct V_337 ) {
. V_86 = V_86 ,
. V_155 = V_155 ,
} ;
V_329 = F_338 ( V_19 -> V_74 [ V_343 ] , & V_19 -> V_53 ) ;
V_52 = F_336 ( V_329 , V_86 , V_155 ) ;
if ( V_52 < 0 )
return - V_315 ;
while ( V_52 < V_329 -> V_330 &&
F_334 ( & V_333 , & V_329 -> V_333 [ V_52 ] ) == 0 ) {
if ( ! F_341 ( V_329 -> V_333 [ V_52 ] . V_334 , V_86 , V_155 , V_323 ) )
return 0 ;
V_52 ++ ;
}
return - V_315 ;
}
int F_342 ( struct V_19 * V_19 , enum V_342 V_343 , T_7 V_86 ,
int V_155 , struct V_331 * V_334 )
{
struct V_75 * V_344 , * V_329 ;
V_329 = V_19 -> V_74 [ V_343 ] ;
if ( V_329 -> V_330 > V_345 - 1 )
return - V_346 ;
V_344 = F_85 ( sizeof( * V_329 ) + ( ( V_329 -> V_330 + 1 ) *
sizeof( struct V_337 ) ) , V_40 ) ;
if ( ! V_344 )
return - V_42 ;
memcpy ( V_344 , V_329 , sizeof( * V_329 ) + ( V_329 -> V_330 *
sizeof( struct V_337 ) ) ) ;
F_335 ( V_344 , V_334 , V_86 , V_155 ) ;
F_12 ( V_19 -> V_74 [ V_343 ] , V_344 ) ;
F_134 ( & V_19 -> V_53 ) ;
F_96 ( V_329 ) ;
return 0 ;
}
int F_343 ( struct V_19 * V_19 , enum V_342 V_343 ,
struct V_331 * V_334 )
{
int V_21 , V_37 ;
struct V_75 * V_344 , * V_329 ;
V_329 = V_19 -> V_74 [ V_343 ] ;
V_37 = - V_142 ;
for ( V_21 = 0 ; V_21 < V_329 -> V_330 ; V_21 ++ )
if ( V_329 -> V_333 [ V_21 ] . V_334 == V_334 ) {
V_37 = 0 ;
break;
}
if ( V_37 )
return V_37 ;
V_344 = F_85 ( sizeof( * V_329 ) + ( ( V_329 -> V_330 - 1 ) *
sizeof( struct V_337 ) ) , V_40 ) ;
if ( ! V_344 )
return - V_42 ;
memcpy ( V_344 , V_329 , sizeof( * V_329 ) + V_21 * sizeof( struct V_337 ) ) ;
V_344 -> V_330 -- ;
memcpy ( V_344 -> V_333 + V_21 , V_329 -> V_333 + V_21 + 1 ,
( V_344 -> V_330 - V_21 ) * sizeof( struct V_337 ) ) ;
F_12 ( V_19 -> V_74 [ V_343 ] , V_344 ) ;
F_134 ( & V_19 -> V_53 ) ;
F_96 ( V_329 ) ;
return V_37 ;
}
static int F_344 ( void * V_347 , T_4 * V_323 )
{
unsigned V_183 = ( long ) V_347 ;
struct V_19 * V_19 ;
* V_323 = 0 ;
F_91 ( & V_82 ) ;
F_345 ( V_19 , & V_83 , V_83 )
* V_323 += * ( T_5 * ) ( ( void * ) V_19 + V_183 ) ;
F_93 ( & V_82 ) ;
return 0 ;
}
static int F_346 ( void * V_347 , T_4 * V_323 )
{
unsigned V_183 = ( long ) V_347 ;
struct V_19 * V_19 ;
struct V_6 * V_7 ;
int V_21 ;
* V_323 = 0 ;
F_91 ( & V_82 ) ;
F_345 (kvm, &vm_list, vm_list)
F_28 ( V_21 , V_7 , V_19 )
* V_323 += * ( T_5 * ) ( ( void * ) V_7 + V_183 ) ;
F_93 ( & V_82 ) ;
return 0 ;
}
static int F_347 ( void )
{
int V_37 = - V_143 ;
struct V_348 * V_266 ;
V_349 = F_348 ( L_8 , NULL ) ;
if ( V_349 == NULL )
goto V_120;
for ( V_266 = V_350 ; V_266 -> V_351 ; ++ V_266 ) {
V_266 -> V_352 = F_349 ( V_266 -> V_351 , 0444 , V_349 ,
( void * ) ( long ) V_266 -> V_183 ,
V_353 [ V_266 -> V_354 ] ) ;
if ( V_266 -> V_352 == NULL )
goto V_355;
}
return 0 ;
V_355:
F_350 ( V_349 ) ;
V_120:
return V_37 ;
}
static void F_351 ( void )
{
struct V_348 * V_266 ;
for ( V_266 = V_350 ; V_266 -> V_351 ; ++ V_266 )
F_352 ( V_266 -> V_352 ) ;
F_352 ( V_349 ) ;
}
static int F_353 ( void )
{
if ( V_320 )
F_324 ( NULL ) ;
return 0 ;
}
static void F_354 ( void )
{
if ( V_320 ) {
F_195 ( F_355 ( & V_82 ) ) ;
F_317 ( NULL ) ;
}
}
static inline
struct V_6 * F_356 ( struct V_17 * V_356 )
{
return F_54 ( V_356 , struct V_6 , V_17 ) ;
}
static void F_357 ( struct V_17 * V_356 , int V_8 )
{
struct V_6 * V_7 = F_356 ( V_356 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_358 ( struct V_17 * V_356 ,
struct V_156 * V_357 )
{
struct V_6 * V_7 = F_356 ( V_356 ) ;
F_21 ( V_7 ) ;
}
int F_359 ( void * V_358 , unsigned V_359 , unsigned V_360 ,
struct V_361 * V_361 )
{
int V_37 ;
int V_8 ;
V_37 = F_360 ( V_358 ) ;
if ( V_37 )
goto V_362;
if ( ! F_27 ( & V_317 , V_40 ) ) {
V_37 = - V_42 ;
goto V_363;
}
V_37 = F_361 () ;
if ( V_37 < 0 )
goto V_364;
F_362 (cpu) {
F_363 ( V_8 ,
V_365 ,
& V_37 , 1 ) ;
if ( V_37 < 0 )
goto V_366;
}
V_37 = F_364 ( & V_367 ) ;
if ( V_37 )
goto V_368;
F_365 ( & V_369 ) ;
if ( ! V_360 )
V_360 = F_366 ( struct V_6 ) ;
V_370 = F_367 ( L_9 , V_359 , V_360 ,
0 , NULL ) ;
if ( ! V_370 ) {
V_37 = - V_42 ;
goto V_371;
}
V_37 = F_368 () ;
if ( V_37 )
goto V_134;
V_372 . V_373 = V_361 ;
V_299 . V_373 = V_361 ;
V_221 . V_373 = V_361 ;
V_37 = F_369 ( & V_374 ) ;
if ( V_37 ) {
F_322 ( V_375 L_10 ) ;
goto V_376;
}
F_370 ( & V_377 ) ;
V_224 . V_378 = F_357 ;
V_224 . V_379 = F_358 ;
V_37 = F_347 () ;
if ( V_37 ) {
F_322 ( V_375 L_11 ) ;
goto V_380;
}
return 0 ;
V_380:
F_371 ( & V_377 ) ;
V_376:
F_372 () ;
V_134:
F_373 ( V_370 ) ;
V_371:
F_374 ( & V_369 ) ;
F_375 ( & V_367 ) ;
V_368:
V_366:
F_376 () ;
V_364:
F_35 ( V_317 ) ;
V_363:
F_377 () ;
V_362:
return V_37 ;
}
void F_378 ( void )
{
F_351 () ;
F_379 ( & V_374 ) ;
F_373 ( V_370 ) ;
F_372 () ;
F_371 ( & V_377 ) ;
F_374 ( & V_369 ) ;
F_375 ( & V_367 ) ;
F_328 ( F_324 , NULL , 1 ) ;
F_376 () ;
F_377 () ;
F_35 ( V_317 ) ;
}
