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
int F_40 ( struct V_6 * V_7 , struct V_19 * V_19 , unsigned V_35 )
{
struct V_3 * V_3 ;
int V_36 ;
F_41 ( & V_7 -> V_9 ) ;
V_7 -> V_8 = - 1 ;
V_7 -> V_19 = V_19 ;
V_7 -> V_37 = V_35 ;
V_7 -> V_11 = NULL ;
F_42 ( & V_7 -> V_38 ) ;
F_43 ( V_7 ) ;
V_3 = F_44 ( V_39 | V_40 ) ;
if ( ! V_3 ) {
V_36 = - V_41 ;
goto V_42;
}
V_7 -> V_43 = F_45 ( V_3 ) ;
F_46 ( V_7 , false ) ;
F_47 ( V_7 , false ) ;
V_36 = F_48 ( V_7 ) ;
if ( V_36 < 0 )
goto V_44;
return 0 ;
V_44:
F_49 ( ( unsigned long ) V_7 -> V_43 ) ;
V_42:
return V_36 ;
}
void F_50 ( struct V_6 * V_7 )
{
F_14 ( V_7 -> V_11 ) ;
F_51 ( V_7 ) ;
F_49 ( ( unsigned long ) V_7 -> V_43 ) ;
}
static inline struct V_19 * F_52 ( struct V_45 * V_46 )
{
return F_53 ( V_46 , struct V_19 , V_45 ) ;
}
static void F_54 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_49 )
{
struct V_19 * V_19 = F_52 ( V_46 ) ;
int V_50 , V_51 ;
V_51 = F_55 ( & V_19 -> V_52 ) ;
F_56 ( & V_19 -> V_53 ) ;
V_19 -> V_54 ++ ;
V_50 = F_57 ( V_19 , V_49 ) | V_19 -> V_29 ;
if ( V_50 )
F_36 ( V_19 ) ;
F_58 ( & V_19 -> V_53 ) ;
F_59 ( & V_19 -> V_52 , V_51 ) ;
}
static void F_60 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_49 ,
T_3 V_55 )
{
struct V_19 * V_19 = F_52 ( V_46 ) ;
int V_51 ;
V_51 = F_55 ( & V_19 -> V_52 ) ;
F_56 ( & V_19 -> V_53 ) ;
V_19 -> V_54 ++ ;
F_61 ( V_19 , V_49 , V_55 ) ;
F_58 ( & V_19 -> V_53 ) ;
F_59 ( & V_19 -> V_52 , V_51 ) ;
}
static void F_62 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_56 ,
unsigned long V_57 )
{
struct V_19 * V_19 = F_52 ( V_46 ) ;
int V_50 = 0 , V_51 ;
V_51 = F_55 ( & V_19 -> V_52 ) ;
F_56 ( & V_19 -> V_53 ) ;
V_19 -> V_58 ++ ;
V_50 = F_63 ( V_19 , V_56 , V_57 ) ;
V_50 |= V_19 -> V_29 ;
if ( V_50 )
F_36 ( V_19 ) ;
F_58 ( & V_19 -> V_53 ) ;
F_59 ( & V_19 -> V_52 , V_51 ) ;
}
static void F_64 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_56 ,
unsigned long V_57 )
{
struct V_19 * V_19 = F_52 ( V_46 ) ;
F_56 ( & V_19 -> V_53 ) ;
V_19 -> V_54 ++ ;
F_65 () ;
V_19 -> V_58 -- ;
F_58 ( & V_19 -> V_53 ) ;
F_66 ( V_19 -> V_58 < 0 ) ;
}
static int F_67 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_49 )
{
struct V_19 * V_19 = F_52 ( V_46 ) ;
int V_59 , V_51 ;
V_51 = F_55 ( & V_19 -> V_52 ) ;
F_56 ( & V_19 -> V_53 ) ;
V_59 = F_68 ( V_19 , V_49 ) ;
if ( V_59 )
F_36 ( V_19 ) ;
F_58 ( & V_19 -> V_53 ) ;
F_59 ( & V_19 -> V_52 , V_51 ) ;
return V_59 ;
}
static int F_69 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
unsigned long V_49 )
{
struct V_19 * V_19 = F_52 ( V_46 ) ;
int V_59 , V_51 ;
V_51 = F_55 ( & V_19 -> V_52 ) ;
F_56 ( & V_19 -> V_53 ) ;
V_59 = F_70 ( V_19 , V_49 ) ;
F_58 ( & V_19 -> V_53 ) ;
F_59 ( & V_19 -> V_52 , V_51 ) ;
return V_59 ;
}
static void F_71 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_19 * V_19 = F_52 ( V_46 ) ;
int V_51 ;
V_51 = F_55 ( & V_19 -> V_52 ) ;
F_72 ( V_19 ) ;
F_59 ( & V_19 -> V_52 , V_51 ) ;
}
static int F_73 ( struct V_19 * V_19 )
{
V_19 -> V_45 . V_60 = & V_61 ;
return F_74 ( & V_19 -> V_45 , V_12 -> V_48 ) ;
}
static int F_73 ( struct V_19 * V_19 )
{
return 0 ;
}
static void F_75 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_62 * V_63 = V_19 -> V_64 ;
for ( V_21 = 0 ; V_21 < V_65 ; V_21 ++ )
V_63 -> V_66 [ V_21 ] = V_63 -> V_64 [ V_21 ] . V_35 = V_21 ;
}
static struct V_19 * F_76 ( unsigned long type )
{
int V_36 , V_21 ;
struct V_19 * V_19 = F_77 () ;
if ( ! V_19 )
return F_78 ( - V_41 ) ;
V_36 = F_79 ( V_19 , type ) ;
if ( V_36 )
goto V_67;
V_36 = F_80 () ;
if ( V_36 )
goto V_67;
#ifdef F_81
F_82 ( & V_19 -> V_68 ) ;
F_82 ( & V_19 -> V_69 ) ;
#endif
V_36 = - V_41 ;
V_19 -> V_64 = F_83 ( sizeof( struct V_62 ) , V_39 ) ;
if ( ! V_19 -> V_64 )
goto V_70;
F_75 ( V_19 ) ;
if ( F_84 ( & V_19 -> V_52 ) )
goto V_70;
for ( V_21 = 0 ; V_21 < V_71 ; V_21 ++ ) {
V_19 -> V_72 [ V_21 ] = F_83 ( sizeof( struct V_73 ) ,
V_39 ) ;
if ( ! V_19 -> V_72 [ V_21 ] )
goto V_74;
}
F_85 ( & V_19 -> V_53 ) ;
V_19 -> V_48 = V_12 -> V_48 ;
F_86 ( & V_19 -> V_48 -> V_75 ) ;
F_87 ( V_19 ) ;
F_41 ( & V_19 -> V_76 ) ;
F_41 ( & V_19 -> V_77 ) ;
F_41 ( & V_19 -> V_78 ) ;
F_88 ( & V_19 -> V_79 , 1 ) ;
V_36 = F_73 ( V_19 ) ;
if ( V_36 )
goto V_74;
F_89 ( & V_80 ) ;
F_90 ( & V_19 -> V_81 , & V_81 ) ;
F_91 ( & V_80 ) ;
return V_19 ;
V_74:
F_92 ( & V_19 -> V_52 ) ;
V_70:
F_93 () ;
V_67:
for ( V_21 = 0 ; V_21 < V_71 ; V_21 ++ )
F_94 ( V_19 -> V_72 [ V_21 ] ) ;
F_94 ( V_19 -> V_64 ) ;
F_95 ( V_19 ) ;
return F_78 ( V_36 ) ;
}
void * F_96 ( unsigned long V_82 )
{
if ( V_82 > V_83 )
return F_97 ( V_82 ) ;
else
return F_83 ( V_82 , V_39 ) ;
}
void F_98 ( const void * V_84 )
{
if ( F_99 ( V_84 ) )
F_100 ( V_84 ) ;
else
F_94 ( V_84 ) ;
}
static void F_101 ( struct V_85 * V_86 )
{
if ( ! V_86 -> V_87 )
return;
F_98 ( V_86 -> V_87 ) ;
V_86 -> V_87 = NULL ;
}
static void F_102 ( struct V_85 * free ,
struct V_85 * V_88 )
{
if ( ! V_88 || free -> V_87 != V_88 -> V_87 )
F_101 ( free ) ;
F_103 ( free , V_88 ) ;
free -> V_89 = 0 ;
}
void F_104 ( struct V_19 * V_19 )
{
struct V_62 * V_63 = V_19 -> V_64 ;
struct V_85 * V_86 ;
F_105 (memslot, slots)
F_102 ( V_86 , NULL ) ;
F_94 ( V_19 -> V_64 ) ;
}
static void F_106 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_47 * V_48 = V_19 -> V_48 ;
F_107 ( V_19 ) ;
F_89 ( & V_80 ) ;
F_108 ( & V_19 -> V_81 ) ;
F_91 ( & V_80 ) ;
F_109 ( V_19 ) ;
for ( V_21 = 0 ; V_21 < V_71 ; V_21 ++ )
F_110 ( V_19 -> V_72 [ V_21 ] ) ;
F_111 ( V_19 ) ;
#if F_112 ( V_90 ) && F_112 ( V_91 )
F_113 ( & V_19 -> V_45 , V_19 -> V_48 ) ;
#else
F_72 ( V_19 ) ;
#endif
F_114 ( V_19 ) ;
F_104 ( V_19 ) ;
F_92 ( & V_19 -> V_52 ) ;
F_95 ( V_19 ) ;
F_93 () ;
F_115 ( V_48 ) ;
}
void F_116 ( struct V_19 * V_19 )
{
F_86 ( & V_19 -> V_79 ) ;
}
void F_117 ( struct V_19 * V_19 )
{
if ( F_118 ( & V_19 -> V_79 ) )
F_106 ( V_19 ) ;
}
static int F_119 ( struct V_92 * V_92 , struct V_93 * V_94 )
{
struct V_19 * V_19 = V_94 -> V_95 ;
F_120 ( V_19 ) ;
F_117 ( V_19 ) ;
return 0 ;
}
static int F_121 ( struct V_85 * V_86 )
{
#ifndef F_122
unsigned long V_96 = 2 * F_123 ( V_86 ) ;
V_86 -> V_87 = F_96 ( V_96 ) ;
if ( ! V_86 -> V_87 )
return - V_41 ;
#endif
return 0 ;
}
static int F_124 ( const void * V_97 , const void * V_98 )
{
struct V_85 * V_99 , * V_100 ;
V_99 = (struct V_85 * ) V_97 ;
V_100 = (struct V_85 * ) V_98 ;
if ( V_99 -> V_89 < V_100 -> V_89 )
return 1 ;
if ( V_99 -> V_89 > V_100 -> V_89 )
return - 1 ;
return 0 ;
}
static void F_125 ( struct V_62 * V_63 )
{
int V_21 ;
F_126 ( V_63 -> V_64 , V_65 ,
sizeof( struct V_85 ) , F_124 , NULL ) ;
for ( V_21 = 0 ; V_21 < V_65 ; V_21 ++ )
V_63 -> V_66 [ V_63 -> V_64 [ V_21 ] . V_35 ] = V_21 ;
}
void F_127 ( struct V_62 * V_63 , struct V_85 * V_101 )
{
if ( V_101 ) {
int V_35 = V_101 -> V_35 ;
struct V_85 * V_102 = F_128 ( V_63 , V_35 ) ;
unsigned long V_89 = V_102 -> V_89 ;
* V_102 = * V_101 ;
if ( V_101 -> V_89 != V_89 )
F_125 ( V_63 ) ;
}
V_63 -> V_103 ++ ;
}
static int F_129 ( struct V_104 * V_105 )
{
T_4 V_106 = V_107 ;
#ifdef F_130
V_106 |= V_108 ;
#endif
if ( V_105 -> V_109 & ~ V_106 )
return - V_110 ;
return 0 ;
}
int F_131 ( struct V_19 * V_19 ,
struct V_104 * V_105 ,
int V_111 )
{
int V_36 ;
T_5 V_112 ;
unsigned long V_89 ;
struct V_85 * V_86 , * V_113 ;
struct V_85 V_102 , V_101 ;
struct V_62 * V_63 , * V_114 ;
V_36 = F_129 ( V_105 ) ;
if ( V_36 )
goto V_115;
V_36 = - V_110 ;
if ( V_105 -> V_116 & ( V_83 - 1 ) )
goto V_115;
if ( V_105 -> V_117 & ( V_83 - 1 ) )
goto V_115;
if ( V_111 &&
( ( V_105 -> V_118 & ( V_83 - 1 ) ) ||
! F_132 ( V_119 ,
( void V_120 * ) ( unsigned long ) V_105 -> V_118 ,
V_105 -> V_116 ) ) )
goto V_115;
if ( V_105 -> V_113 >= V_65 )
goto V_115;
if ( V_105 -> V_117 + V_105 -> V_116 < V_105 -> V_117 )
goto V_115;
V_86 = F_128 ( V_19 -> V_64 , V_105 -> V_113 ) ;
V_112 = V_105 -> V_117 >> V_121 ;
V_89 = V_105 -> V_116 >> V_121 ;
V_36 = - V_110 ;
if ( V_89 > V_122 )
goto V_115;
if ( ! V_89 )
V_105 -> V_109 &= ~ V_107 ;
V_101 = V_102 = * V_86 ;
V_101 . V_35 = V_105 -> V_113 ;
V_101 . V_112 = V_112 ;
V_101 . V_89 = V_89 ;
V_101 . V_109 = V_105 -> V_109 ;
V_36 = - V_110 ;
if ( V_89 && V_102 . V_89 && V_89 != V_102 . V_89 )
goto V_123;
V_36 = - V_124 ;
F_105 (slot, kvm->memslots) {
if ( V_113 -> V_35 >= V_125 || V_113 == V_86 )
continue;
if ( ! ( ( V_112 + V_89 <= V_113 -> V_112 ) ||
( V_112 >= V_113 -> V_112 + V_113 -> V_89 ) ) )
goto V_123;
}
if ( ! ( V_101 . V_109 & V_107 ) )
V_101 . V_87 = NULL ;
V_36 = - V_41 ;
if ( V_89 && ! V_102 . V_89 ) {
V_101 . V_111 = V_111 ;
V_101 . V_118 = V_105 -> V_118 ;
if ( F_133 ( & V_101 , V_89 ) )
goto V_123;
}
if ( ( V_101 . V_109 & V_107 ) && ! V_101 . V_87 ) {
if ( F_121 ( & V_101 ) < 0 )
goto V_123;
}
if ( ! V_89 || V_112 != V_102 . V_112 ) {
struct V_85 * V_113 ;
V_36 = - V_41 ;
V_63 = F_134 ( V_19 -> V_64 , sizeof( struct V_62 ) ,
V_39 ) ;
if ( ! V_63 )
goto V_123;
V_113 = F_128 ( V_63 , V_105 -> V_113 ) ;
V_113 -> V_109 |= V_126 ;
F_127 ( V_63 , NULL ) ;
V_114 = V_19 -> V_64 ;
F_12 ( V_19 -> V_64 , V_63 ) ;
F_135 ( & V_19 -> V_52 ) ;
F_136 ( V_19 , V_113 ) ;
F_94 ( V_114 ) ;
}
V_36 = F_137 ( V_19 , & V_101 , V_102 , V_105 , V_111 ) ;
if ( V_36 )
goto V_123;
if ( V_89 ) {
V_36 = F_138 ( V_19 , & V_101 ) ;
if ( V_36 )
goto V_123;
} else
F_139 ( V_19 , & V_102 ) ;
V_36 = - V_41 ;
V_63 = F_134 ( V_19 -> V_64 , sizeof( struct V_62 ) ,
V_39 ) ;
if ( ! V_63 )
goto V_123;
if ( ! V_89 ) {
V_101 . V_87 = NULL ;
memset ( & V_101 . V_127 , 0 , sizeof( V_101 . V_127 ) ) ;
}
F_127 ( V_63 , & V_101 ) ;
V_114 = V_19 -> V_64 ;
F_12 ( V_19 -> V_64 , V_63 ) ;
F_135 ( & V_19 -> V_52 ) ;
F_140 ( V_19 , V_105 , V_102 , V_111 ) ;
F_102 ( & V_102 , & V_101 ) ;
F_94 ( V_114 ) ;
return 0 ;
V_123:
F_102 ( & V_101 , & V_102 ) ;
V_115:
return V_36 ;
}
int F_141 ( struct V_19 * V_19 ,
struct V_104 * V_105 ,
int V_111 )
{
int V_36 ;
F_142 ( & V_19 -> V_78 ) ;
V_36 = F_131 ( V_19 , V_105 , V_111 ) ;
F_24 ( & V_19 -> V_78 ) ;
return V_36 ;
}
int F_143 ( struct V_19 * V_19 ,
struct
V_104 * V_105 ,
int V_111 )
{
if ( V_105 -> V_113 >= V_125 )
return - V_110 ;
return F_141 ( V_19 , V_105 , V_111 ) ;
}
int F_144 ( struct V_19 * V_19 ,
struct V_128 * log , int * V_129 )
{
struct V_85 * V_86 ;
int V_36 , V_21 ;
unsigned long V_130 ;
unsigned long V_131 = 0 ;
V_36 = - V_110 ;
if ( log -> V_113 >= V_125 )
goto V_115;
V_86 = F_128 ( V_19 -> V_64 , log -> V_113 ) ;
V_36 = - V_132 ;
if ( ! V_86 -> V_87 )
goto V_115;
V_130 = F_123 ( V_86 ) ;
for ( V_21 = 0 ; ! V_131 && V_21 < V_130 / sizeof( long ) ; ++ V_21 )
V_131 = V_86 -> V_87 [ V_21 ] ;
V_36 = - V_133 ;
if ( F_145 ( log -> V_87 , V_86 -> V_87 , V_130 ) )
goto V_115;
if ( V_131 )
* V_129 = 1 ;
V_36 = 0 ;
V_115:
return V_36 ;
}
bool F_146 ( void )
{
return V_134 ;
}
void F_147 ( void )
{
V_134 = false ;
}
struct V_85 * F_148 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_149 ( V_62 ( V_19 ) , V_135 ) ;
}
int F_150 ( struct V_19 * V_19 , T_5 V_135 )
{
struct V_85 * V_86 = F_148 ( V_19 , V_135 ) ;
if ( ! V_86 || V_86 -> V_35 >= V_125 ||
V_86 -> V_109 & V_126 )
return 0 ;
return 1 ;
}
unsigned long F_151 ( struct V_19 * V_19 , T_5 V_135 )
{
struct V_136 * V_137 ;
unsigned long V_84 , V_82 ;
V_82 = V_83 ;
V_84 = F_152 ( V_19 , V_135 ) ;
if ( F_153 ( V_84 ) )
return V_83 ;
F_154 ( & V_12 -> V_48 -> V_138 ) ;
V_137 = F_155 ( V_12 -> V_48 , V_84 ) ;
if ( ! V_137 )
goto V_115;
V_82 = F_156 ( V_137 ) ;
V_115:
F_157 ( & V_12 -> V_48 -> V_138 ) ;
return V_82 ;
}
static bool F_158 ( struct V_85 * V_113 )
{
return V_113 -> V_109 & V_108 ;
}
static unsigned long F_159 ( struct V_85 * V_113 , T_5 V_135 ,
T_5 * V_139 , bool V_140 )
{
if ( ! V_113 || V_113 -> V_109 & V_126 )
return V_141 ;
if ( F_158 ( V_113 ) && V_140 )
return V_142 ;
if ( V_139 )
* V_139 = V_113 -> V_89 - ( V_135 - V_113 -> V_112 ) ;
return F_160 ( V_113 , V_135 ) ;
}
static unsigned long F_161 ( struct V_85 * V_113 , T_5 V_135 ,
T_5 * V_139 )
{
return F_159 ( V_113 , V_135 , V_139 , true ) ;
}
unsigned long F_162 ( struct V_85 * V_113 ,
T_5 V_135 )
{
return F_161 ( V_113 , V_135 , NULL ) ;
}
unsigned long F_152 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_161 ( F_148 ( V_19 , V_135 ) , V_135 , NULL ) ;
}
static unsigned long F_163 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_159 ( F_148 ( V_19 , V_135 ) , V_135 , NULL , false ) ;
}
static int F_164 ( void * V_143 , void V_120 * V_144 , int V_145 )
{
return F_165 ( V_143 , V_144 , V_145 ) ;
}
static int F_166 ( void * V_143 , void V_120 * V_144 , int V_145 )
{
return F_167 ( V_143 , V_144 , V_145 ) ;
}
int F_168 ( struct V_146 * V_147 , struct V_47 * V_48 ,
unsigned long V_56 , int V_140 , struct V_3 * * V_3 )
{
int V_109 = V_148 | V_149 | V_150 | V_151 ;
if ( V_140 )
V_109 |= V_152 ;
return F_169 ( V_147 , V_48 , V_56 , 1 , V_109 , V_3 , NULL , NULL ) ;
}
static inline int F_170 ( unsigned long V_84 )
{
int V_153 , V_109 = V_148 | V_150 | V_152 ;
V_153 = F_169 ( V_12 , V_12 -> V_48 , V_84 , 1 ,
V_109 , NULL , NULL , NULL ) ;
return V_153 == - V_154 ;
}
static bool F_171 ( unsigned long V_84 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_89 ;
if ( ! ( V_156 || V_155 ) )
return false ;
if ( ! ( V_157 || V_158 ) )
return false ;
V_89 = F_172 ( V_84 , 1 , 1 , V_3 ) ;
if ( V_89 == 1 ) {
* V_1 = F_173 ( V_3 [ 0 ] ) ;
if ( V_158 )
* V_158 = true ;
return true ;
}
return false ;
}
static int F_174 ( unsigned long V_84 , bool * V_156 , bool V_157 ,
bool * V_158 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_89 = 0 ;
F_175 () ;
if ( V_158 )
* V_158 = V_157 ;
if ( V_156 ) {
F_154 ( & V_12 -> V_48 -> V_138 ) ;
V_89 = F_168 ( V_12 , V_12 -> V_48 ,
V_84 , V_157 , V_3 ) ;
F_157 ( & V_12 -> V_48 -> V_138 ) ;
} else
V_89 = F_176 ( V_84 , 1 , V_157 ,
V_3 ) ;
if ( V_89 != 1 )
return V_89 ;
if ( F_10 ( ! V_157 ) && V_158 ) {
struct V_3 * V_159 [ 1 ] ;
V_89 = F_172 ( V_84 , 1 , 1 , V_159 ) ;
if ( V_89 == 1 ) {
* V_158 = true ;
F_177 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_159 [ 0 ] ;
}
V_89 = 1 ;
}
* V_1 = F_173 ( V_3 [ 0 ] ) ;
return V_89 ;
}
static bool F_178 ( struct V_136 * V_137 , bool V_157 )
{
if ( F_10 ( ! ( V_137 -> V_160 & V_161 ) ) )
return false ;
if ( V_157 && ( F_10 ( ! ( V_137 -> V_160 & V_162 ) ) ) )
return false ;
return true ;
}
static T_1 F_179 ( unsigned long V_84 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
struct V_136 * V_137 ;
T_1 V_1 = 0 ;
int V_89 ;
F_66 ( V_155 && V_156 ) ;
if ( F_171 ( V_84 , V_155 , V_156 , V_157 , V_158 , & V_1 ) )
return V_1 ;
if ( V_155 )
return V_163 ;
V_89 = F_174 ( V_84 , V_156 , V_157 , V_158 , & V_1 ) ;
if ( V_89 == 1 )
return V_1 ;
F_154 ( & V_12 -> V_48 -> V_138 ) ;
if ( V_89 == - V_154 ||
( ! V_156 && F_170 ( V_84 ) ) ) {
V_1 = V_164 ;
goto exit;
}
V_137 = F_180 ( V_12 -> V_48 , V_84 , V_84 + 1 ) ;
if ( V_137 == NULL )
V_1 = V_163 ;
else if ( ( V_137 -> V_160 & V_165 ) ) {
V_1 = ( ( V_84 - V_137 -> V_166 ) >> V_121 ) +
V_137 -> V_167 ;
F_66 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_156 && F_178 ( V_137 , V_157 ) )
* V_156 = true ;
V_1 = V_163 ;
}
exit:
F_157 ( & V_12 -> V_48 -> V_138 ) ;
return V_1 ;
}
static T_1
F_181 ( struct V_85 * V_113 , T_5 V_135 , bool V_155 ,
bool * V_156 , bool V_157 , bool * V_158 )
{
unsigned long V_84 = F_159 ( V_113 , V_135 , NULL , V_157 ) ;
if ( V_84 == V_142 )
return V_168 ;
if ( F_153 ( V_84 ) )
return V_169 ;
if ( V_158 && F_158 ( V_113 ) ) {
* V_158 = false ;
V_158 = NULL ;
}
return F_179 ( V_84 , V_155 , V_156 , V_157 ,
V_158 ) ;
}
static T_1 F_182 ( struct V_19 * V_19 , T_5 V_135 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
struct V_85 * V_113 ;
if ( V_156 )
* V_156 = false ;
V_113 = F_148 ( V_19 , V_135 ) ;
return F_181 ( V_113 , V_135 , V_155 , V_156 , V_157 ,
V_158 ) ;
}
T_1 F_183 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_182 ( V_19 , V_135 , true , NULL , true , NULL ) ;
}
T_1 F_184 ( struct V_19 * V_19 , T_5 V_135 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
return F_182 ( V_19 , V_135 , false , V_156 , V_157 , V_158 ) ;
}
T_1 F_185 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_182 ( V_19 , V_135 , false , NULL , true , NULL ) ;
}
T_1 F_186 ( struct V_19 * V_19 , T_5 V_135 , bool V_157 ,
bool * V_158 )
{
return F_182 ( V_19 , V_135 , false , NULL , V_157 , V_158 ) ;
}
T_1 F_187 ( struct V_85 * V_113 , T_5 V_135 )
{
return F_181 ( V_113 , V_135 , false , NULL , true , NULL ) ;
}
T_1 F_188 ( struct V_85 * V_113 , T_5 V_135 )
{
return F_181 ( V_113 , V_135 , true , NULL , true , NULL ) ;
}
int F_189 ( struct V_19 * V_19 , T_5 V_135 , struct V_3 * * V_170 ,
int V_139 )
{
unsigned long V_84 ;
T_5 V_171 ;
V_84 = F_161 ( F_148 ( V_19 , V_135 ) , V_135 , & V_171 ) ;
if ( F_153 ( V_84 ) )
return - 1 ;
if ( V_171 < V_139 )
return 0 ;
return F_172 ( V_84 , V_139 , 1 , V_170 ) ;
}
static struct V_3 * F_190 ( T_1 V_1 )
{
if ( F_191 ( V_1 ) )
return V_172 ;
if ( F_1 ( V_1 ) ) {
F_192 ( 1 ) ;
return V_172 ;
}
return F_3 ( V_1 ) ;
}
struct V_3 * F_193 ( struct V_19 * V_19 , T_5 V_135 )
{
T_1 V_1 ;
V_1 = F_185 ( V_19 , V_135 ) ;
return F_190 ( V_1 ) ;
}
void F_194 ( struct V_3 * V_3 )
{
F_192 ( F_195 ( V_3 ) ) ;
F_196 ( F_173 ( V_3 ) ) ;
}
void F_196 ( T_1 V_1 )
{
if ( ! F_191 ( V_1 ) && ! F_1 ( V_1 ) )
F_177 ( F_3 ( V_1 ) ) ;
}
void F_197 ( struct V_3 * V_3 )
{
F_192 ( F_195 ( V_3 ) ) ;
F_198 ( F_173 ( V_3 ) ) ;
}
void F_198 ( T_1 V_1 )
{
F_199 ( V_1 ) ;
F_196 ( V_1 ) ;
}
void F_200 ( struct V_3 * V_3 )
{
F_199 ( F_173 ( V_3 ) ) ;
}
void F_199 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_201 ( V_3 ) ;
}
}
void F_202 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_203 ( F_3 ( V_1 ) ) ;
}
void F_204 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_205 ( F_3 ( V_1 ) ) ;
}
static int F_206 ( unsigned long V_145 , int V_173 )
{
if ( V_145 > V_83 - V_173 )
return V_83 - V_173 ;
else
return V_145 ;
}
int F_207 ( struct V_19 * V_19 , T_5 V_135 , void * V_143 , int V_173 ,
int V_145 )
{
int V_36 ;
unsigned long V_84 ;
V_84 = F_163 ( V_19 , V_135 ) ;
if ( F_153 ( V_84 ) )
return - V_133 ;
V_36 = F_164 ( V_143 , ( void V_120 * ) V_84 + V_173 , V_145 ) ;
if ( V_36 )
return - V_133 ;
return 0 ;
}
int F_208 ( struct V_19 * V_19 , T_6 V_174 , void * V_143 , unsigned long V_145 )
{
T_5 V_135 = V_174 >> V_121 ;
int V_175 ;
int V_173 = F_209 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_206 ( V_145 , V_173 ) ) != 0 ) {
V_176 = F_207 ( V_19 , V_135 , V_143 , V_173 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_173 = 0 ;
V_145 -= V_175 ;
V_143 += V_175 ;
++ V_135 ;
}
return 0 ;
}
int F_210 ( struct V_19 * V_19 , T_6 V_174 , void * V_143 ,
unsigned long V_145 )
{
int V_36 ;
unsigned long V_84 ;
T_5 V_135 = V_174 >> V_121 ;
int V_173 = F_209 ( V_174 ) ;
V_84 = F_163 ( V_19 , V_135 ) ;
if ( F_153 ( V_84 ) )
return - V_133 ;
F_211 () ;
V_36 = F_166 ( V_143 , ( void V_120 * ) V_84 + V_173 , V_145 ) ;
F_212 () ;
if ( V_36 )
return - V_133 ;
return 0 ;
}
int F_213 ( struct V_19 * V_19 , T_5 V_135 , const void * V_143 ,
int V_173 , int V_145 )
{
int V_36 ;
unsigned long V_84 ;
V_84 = F_152 ( V_19 , V_135 ) ;
if ( F_153 ( V_84 ) )
return - V_133 ;
V_36 = F_214 ( ( void V_120 * ) V_84 + V_173 , V_143 , V_145 ) ;
if ( V_36 )
return - V_133 ;
F_215 ( V_19 , V_135 ) ;
return 0 ;
}
int F_216 ( struct V_19 * V_19 , T_6 V_174 , const void * V_143 ,
unsigned long V_145 )
{
T_5 V_135 = V_174 >> V_121 ;
int V_175 ;
int V_173 = F_209 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_206 ( V_145 , V_173 ) ) != 0 ) {
V_176 = F_213 ( V_19 , V_135 , V_143 , V_173 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_173 = 0 ;
V_145 -= V_175 ;
V_143 += V_175 ;
++ V_135 ;
}
return 0 ;
}
int F_217 ( struct V_19 * V_19 , struct V_177 * V_178 ,
T_6 V_174 )
{
struct V_62 * V_63 = V_62 ( V_19 ) ;
int V_173 = F_209 ( V_174 ) ;
T_5 V_135 = V_174 >> V_121 ;
V_178 -> V_174 = V_174 ;
V_178 -> V_103 = V_63 -> V_103 ;
V_178 -> V_86 = F_148 ( V_19 , V_135 ) ;
V_178 -> V_144 = F_161 ( V_178 -> V_86 , V_135 , NULL ) ;
if ( ! F_153 ( V_178 -> V_144 ) )
V_178 -> V_144 += V_173 ;
else
return - V_133 ;
return 0 ;
}
int F_218 ( struct V_19 * V_19 , struct V_177 * V_178 ,
void * V_143 , unsigned long V_145 )
{
struct V_62 * V_63 = V_62 ( V_19 ) ;
int V_36 ;
if ( V_63 -> V_103 != V_178 -> V_103 )
F_217 ( V_19 , V_178 , V_178 -> V_174 ) ;
if ( F_153 ( V_178 -> V_144 ) )
return - V_133 ;
V_36 = F_214 ( ( void V_120 * ) V_178 -> V_144 , V_143 , V_145 ) ;
if ( V_36 )
return - V_133 ;
F_219 ( V_19 , V_178 -> V_86 , V_178 -> V_174 >> V_121 ) ;
return 0 ;
}
int F_220 ( struct V_19 * V_19 , struct V_177 * V_178 ,
void * V_143 , unsigned long V_145 )
{
struct V_62 * V_63 = V_62 ( V_19 ) ;
int V_36 ;
if ( V_63 -> V_103 != V_178 -> V_103 )
F_217 ( V_19 , V_178 , V_178 -> V_174 ) ;
if ( F_153 ( V_178 -> V_144 ) )
return - V_133 ;
V_36 = F_165 ( V_143 , ( void V_120 * ) V_178 -> V_144 , V_145 ) ;
if ( V_36 )
return - V_133 ;
return 0 ;
}
int F_221 ( struct V_19 * V_19 , T_5 V_135 , int V_173 , int V_145 )
{
return F_213 ( V_19 , V_135 , ( const void * ) V_179 ,
V_173 , V_145 ) ;
}
int F_222 ( struct V_19 * V_19 , T_6 V_174 , unsigned long V_145 )
{
T_5 V_135 = V_174 >> V_121 ;
int V_175 ;
int V_173 = F_209 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_206 ( V_145 , V_173 ) ) != 0 ) {
V_176 = F_221 ( V_19 , V_135 , V_173 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_173 = 0 ;
V_145 -= V_175 ;
++ V_135 ;
}
return 0 ;
}
void F_219 ( struct V_19 * V_19 , struct V_85 * V_86 ,
T_5 V_135 )
{
if ( V_86 && V_86 -> V_87 ) {
unsigned long V_180 = V_135 - V_86 -> V_112 ;
F_223 ( V_180 , V_86 -> V_87 ) ;
}
}
void F_215 ( struct V_19 * V_19 , T_5 V_135 )
{
struct V_85 * V_86 ;
V_86 = F_148 ( V_19 , V_135 ) ;
F_219 ( V_19 , V_86 , V_135 ) ;
}
void F_224 ( struct V_6 * V_7 )
{
F_225 ( V_181 ) ;
for (; ; ) {
F_226 ( & V_7 -> V_38 , & V_181 , V_182 ) ;
if ( F_227 ( V_7 ) ) {
F_29 ( V_183 , V_7 ) ;
break;
}
if ( F_228 ( V_7 ) )
break;
if ( F_229 ( V_12 ) )
break;
F_230 () ;
}
F_231 ( & V_7 -> V_38 , & V_181 ) ;
}
void F_232 ( struct V_6 * V_7 )
{
int V_22 ;
int V_8 = V_7 -> V_8 ;
T_7 * V_184 ;
V_184 = F_233 ( V_7 ) ;
if ( F_234 ( V_184 ) ) {
F_235 ( V_184 ) ;
++ V_7 -> V_31 . V_185 ;
}
V_22 = F_15 () ;
if ( V_8 != V_22 && ( unsigned ) V_8 < V_186 && F_236 ( V_8 ) )
if ( F_237 ( V_7 ) )
F_238 ( V_8 ) ;
F_18 () ;
}
void F_239 ( struct V_6 * V_7 )
{
if ( ! F_240 () )
return;
F_241 () ;
}
bool F_242 ( struct V_6 * V_187 )
{
struct V_11 * V_11 ;
struct V_146 * V_188 = NULL ;
F_243 () ;
V_11 = F_244 ( V_187 -> V_11 ) ;
if ( V_11 )
V_188 = F_245 ( V_187 -> V_11 , V_14 ) ;
F_246 () ;
if ( ! V_188 )
return false ;
if ( V_188 -> V_109 & V_189 ) {
F_247 ( V_188 ) ;
return false ;
}
if ( F_248 ( V_188 , 1 ) ) {
F_247 ( V_188 ) ;
return true ;
}
F_247 ( V_188 ) ;
return false ;
}
bool F_249 ( struct V_6 * V_7 )
{
bool V_190 ;
V_190 = ! V_7 -> V_191 . V_192 ||
( V_7 -> V_191 . V_192 &&
V_7 -> V_191 . V_193 ) ;
if ( V_7 -> V_191 . V_192 )
F_47 ( V_7 , ! V_7 -> V_191 . V_193 ) ;
return V_190 ;
}
void F_250 ( struct V_6 * V_22 )
{
struct V_19 * V_19 = V_22 -> V_19 ;
struct V_6 * V_7 ;
int V_194 = V_22 -> V_19 -> V_194 ;
int V_195 = 0 ;
int V_196 ;
int V_21 ;
F_46 ( V_22 , true ) ;
for ( V_196 = 0 ; V_196 < 2 && ! V_195 ; V_196 ++ ) {
F_28 (i, vcpu, kvm) {
if ( ! V_196 && V_21 <= V_194 ) {
V_21 = V_194 ;
continue;
} else if ( V_196 && V_21 > V_194 )
break;
if ( V_7 == V_22 )
continue;
if ( F_234 ( & V_7 -> V_38 ) )
continue;
if ( ! F_249 ( V_7 ) )
continue;
if ( F_242 ( V_7 ) ) {
V_19 -> V_194 = V_21 ;
V_195 = 1 ;
break;
}
}
}
F_46 ( V_22 , false ) ;
F_47 ( V_22 , false ) ;
}
static int F_251 ( struct V_136 * V_137 , struct V_197 * V_198 )
{
struct V_6 * V_7 = V_137 -> V_199 -> V_95 ;
struct V_3 * V_3 ;
if ( V_198 -> V_200 == 0 )
V_3 = F_252 ( V_7 -> V_43 ) ;
#ifdef F_253
else if ( V_198 -> V_200 == V_201 )
V_3 = F_252 ( V_7 -> V_127 . V_202 ) ;
#endif
#ifdef F_254
else if ( V_198 -> V_200 == F_254 )
V_3 = F_252 ( V_7 -> V_19 -> V_203 ) ;
#endif
else
return F_255 ( V_7 , V_198 ) ;
F_205 ( V_3 ) ;
V_198 -> V_3 = V_3 ;
return 0 ;
}
static int F_256 ( struct V_93 * V_93 , struct V_136 * V_137 )
{
V_137 -> V_204 = & V_205 ;
return 0 ;
}
static int F_257 ( struct V_92 * V_92 , struct V_93 * V_94 )
{
struct V_6 * V_7 = V_94 -> V_95 ;
F_117 ( V_7 -> V_19 ) ;
return 0 ;
}
static int F_258 ( struct V_6 * V_7 )
{
return F_259 ( L_1 , & V_206 , V_7 , V_207 ) ;
}
static int F_260 ( struct V_19 * V_19 , T_4 V_35 )
{
int V_36 ;
struct V_6 * V_7 , * V_208 ;
V_7 = F_261 ( V_19 , V_35 ) ;
if ( F_262 ( V_7 ) )
return F_263 ( V_7 ) ;
F_264 ( & V_7 -> V_17 , & V_209 ) ;
V_36 = F_265 ( V_7 ) ;
if ( V_36 )
goto V_210;
F_142 ( & V_19 -> V_76 ) ;
if ( ! F_266 ( V_7 ) ) {
V_36 = - V_110 ;
goto V_211;
}
if ( F_267 ( & V_19 -> V_212 ) == V_213 ) {
V_36 = - V_110 ;
goto V_211;
}
F_28 (r, v, kvm)
if ( V_208 -> V_37 == V_35 ) {
V_36 = - V_124 ;
goto V_211;
}
F_66 ( V_19 -> V_214 [ F_267 ( & V_19 -> V_212 ) ] ) ;
F_116 ( V_19 ) ;
V_36 = F_258 ( V_7 ) ;
if ( V_36 < 0 ) {
F_117 ( V_19 ) ;
goto V_211;
}
V_19 -> V_214 [ F_267 ( & V_19 -> V_212 ) ] = V_7 ;
F_65 () ;
F_86 ( & V_19 -> V_212 ) ;
F_24 ( & V_19 -> V_76 ) ;
F_268 ( V_7 ) ;
return V_36 ;
V_211:
F_24 ( & V_19 -> V_76 ) ;
V_210:
F_269 ( V_7 ) ;
return V_36 ;
}
static int F_270 ( struct V_6 * V_7 , T_8 * V_215 )
{
if ( V_215 ) {
F_271 ( V_215 , F_272 ( V_216 ) | F_272 ( V_217 ) ) ;
V_7 -> V_218 = 1 ;
V_7 -> V_215 = * V_215 ;
} else
V_7 -> V_218 = 0 ;
return 0 ;
}
static long F_273 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_6 * V_7 = V_94 -> V_95 ;
void V_120 * V_221 = ( void V_120 * ) V_220 ;
int V_36 ;
struct V_222 * V_223 = NULL ;
struct V_224 * V_224 = NULL ;
if ( V_7 -> V_19 -> V_48 != V_12 -> V_48 )
return - V_225 ;
#if F_112 ( F_122 ) || F_112 ( V_226 )
if ( V_219 == V_227 || V_219 == V_228 )
return F_274 ( V_94 , V_219 , V_220 ) ;
#endif
V_36 = F_8 ( V_7 ) ;
if ( V_36 )
return V_36 ;
switch ( V_219 ) {
case V_229 :
V_36 = - V_110 ;
if ( V_220 )
goto V_115;
V_36 = F_275 ( V_7 , V_7 -> V_43 ) ;
F_276 ( V_7 -> V_43 -> V_230 , V_36 ) ;
break;
case V_231 : {
struct V_232 * V_232 ;
V_36 = - V_41 ;
V_232 = F_83 ( sizeof( struct V_232 ) , V_39 ) ;
if ( ! V_232 )
goto V_115;
V_36 = F_277 ( V_7 , V_232 ) ;
if ( V_36 )
goto V_233;
V_36 = - V_133 ;
if ( F_145 ( V_221 , V_232 , sizeof( struct V_232 ) ) )
goto V_233;
V_36 = 0 ;
V_233:
F_94 ( V_232 ) ;
break;
}
case V_234 : {
struct V_232 * V_232 ;
V_36 = - V_41 ;
V_232 = F_278 ( V_221 , sizeof( * V_232 ) ) ;
if ( F_262 ( V_232 ) ) {
V_36 = F_263 ( V_232 ) ;
goto V_115;
}
V_36 = F_279 ( V_7 , V_232 ) ;
F_94 ( V_232 ) ;
break;
}
case V_235 : {
V_224 = F_83 ( sizeof( struct V_224 ) , V_39 ) ;
V_36 = - V_41 ;
if ( ! V_224 )
goto V_115;
V_36 = F_280 ( V_7 , V_224 ) ;
if ( V_36 )
goto V_115;
V_36 = - V_133 ;
if ( F_145 ( V_221 , V_224 , sizeof( struct V_224 ) ) )
goto V_115;
V_36 = 0 ;
break;
}
case V_236 : {
V_224 = F_278 ( V_221 , sizeof( * V_224 ) ) ;
if ( F_262 ( V_224 ) ) {
V_36 = F_263 ( V_224 ) ;
V_224 = NULL ;
goto V_115;
}
V_36 = F_281 ( V_7 , V_224 ) ;
break;
}
case V_237 : {
struct V_238 V_239 ;
V_36 = F_282 ( V_7 , & V_239 ) ;
if ( V_36 )
goto V_115;
V_36 = - V_133 ;
if ( F_145 ( V_221 , & V_239 , sizeof V_239 ) )
goto V_115;
V_36 = 0 ;
break;
}
case V_240 : {
struct V_238 V_239 ;
V_36 = - V_133 ;
if ( F_283 ( & V_239 , V_221 , sizeof V_239 ) )
goto V_115;
V_36 = F_284 ( V_7 , & V_239 ) ;
break;
}
case V_241 : {
struct V_242 V_243 ;
V_36 = - V_133 ;
if ( F_283 ( & V_243 , V_221 , sizeof V_243 ) )
goto V_115;
V_36 = F_285 ( V_7 , & V_243 ) ;
if ( V_36 )
goto V_115;
V_36 = - V_133 ;
if ( F_145 ( V_221 , & V_243 , sizeof V_243 ) )
goto V_115;
V_36 = 0 ;
break;
}
case V_244 : {
struct V_245 V_246 ;
V_36 = - V_133 ;
if ( F_283 ( & V_246 , V_221 , sizeof V_246 ) )
goto V_115;
V_36 = F_286 ( V_7 , & V_246 ) ;
break;
}
case V_247 : {
struct V_248 V_120 * V_249 = V_221 ;
struct V_248 V_250 ;
T_8 V_215 , * V_251 ;
V_251 = NULL ;
if ( V_221 ) {
V_36 = - V_133 ;
if ( F_283 ( & V_250 , V_221 ,
sizeof V_250 ) )
goto V_115;
V_36 = - V_110 ;
if ( V_250 . V_145 != sizeof V_215 )
goto V_115;
V_36 = - V_133 ;
if ( F_283 ( & V_215 , V_249 -> V_215 ,
sizeof V_215 ) )
goto V_115;
V_251 = & V_215 ;
}
V_36 = F_270 ( V_7 , V_251 ) ;
break;
}
case V_252 : {
V_223 = F_83 ( sizeof( struct V_222 ) , V_39 ) ;
V_36 = - V_41 ;
if ( ! V_223 )
goto V_115;
V_36 = F_287 ( V_7 , V_223 ) ;
if ( V_36 )
goto V_115;
V_36 = - V_133 ;
if ( F_145 ( V_221 , V_223 , sizeof( struct V_222 ) ) )
goto V_115;
V_36 = 0 ;
break;
}
case V_253 : {
V_223 = F_278 ( V_221 , sizeof( * V_223 ) ) ;
if ( F_262 ( V_223 ) ) {
V_36 = F_263 ( V_223 ) ;
V_223 = NULL ;
goto V_115;
}
V_36 = F_288 ( V_7 , V_223 ) ;
break;
}
default:
V_36 = F_274 ( V_94 , V_219 , V_220 ) ;
}
V_115:
F_19 ( V_7 ) ;
F_94 ( V_223 ) ;
F_94 ( V_224 ) ;
return V_36 ;
}
static long F_289 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_6 * V_7 = V_94 -> V_95 ;
void V_120 * V_221 = F_290 ( V_220 ) ;
int V_36 ;
if ( V_7 -> V_19 -> V_48 != V_12 -> V_48 )
return - V_225 ;
switch ( V_219 ) {
case V_247 : {
struct V_248 V_120 * V_249 = V_221 ;
struct V_248 V_250 ;
T_9 V_254 ;
T_8 V_215 ;
if ( V_221 ) {
V_36 = - V_133 ;
if ( F_283 ( & V_250 , V_221 ,
sizeof V_250 ) )
goto V_115;
V_36 = - V_110 ;
if ( V_250 . V_145 != sizeof V_254 )
goto V_115;
V_36 = - V_133 ;
if ( F_283 ( & V_254 , V_249 -> V_215 ,
sizeof V_254 ) )
goto V_115;
F_291 ( & V_215 , & V_254 ) ;
V_36 = F_270 ( V_7 , & V_215 ) ;
} else
V_36 = F_270 ( V_7 , NULL ) ;
break;
}
default:
V_36 = F_273 ( V_94 , V_219 , V_220 ) ;
}
V_115:
return V_36 ;
}
static long F_292 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_19 * V_19 = V_94 -> V_95 ;
void V_120 * V_221 = ( void V_120 * ) V_220 ;
int V_36 ;
if ( V_19 -> V_48 != V_12 -> V_48 )
return - V_225 ;
switch ( V_219 ) {
case V_255 :
V_36 = F_260 ( V_19 , V_220 ) ;
break;
case V_256 : {
struct V_104 V_257 ;
V_36 = - V_133 ;
if ( F_283 ( & V_257 , V_221 ,
sizeof V_257 ) )
goto V_115;
V_36 = F_143 ( V_19 , & V_257 , 1 ) ;
break;
}
case V_258 : {
struct V_128 log ;
V_36 = - V_133 ;
if ( F_283 ( & log , V_221 , sizeof log ) )
goto V_115;
V_36 = F_293 ( V_19 , & log ) ;
break;
}
#ifdef F_254
case V_259 : {
struct V_260 V_261 ;
V_36 = - V_133 ;
if ( F_283 ( & V_261 , V_221 , sizeof V_261 ) )
goto V_115;
V_36 = F_294 ( V_19 , & V_261 ) ;
break;
}
case V_262 : {
struct V_260 V_261 ;
V_36 = - V_133 ;
if ( F_283 ( & V_261 , V_221 , sizeof V_261 ) )
goto V_115;
V_36 = F_295 ( V_19 , & V_261 ) ;
break;
}
#endif
case V_263 : {
struct V_264 V_143 ;
V_36 = - V_133 ;
if ( F_283 ( & V_143 , V_221 , sizeof V_143 ) )
goto V_115;
V_36 = V_264 ( V_19 , & V_143 ) ;
break;
}
case V_265 : {
struct V_266 V_143 ;
V_36 = - V_133 ;
if ( F_283 ( & V_143 , V_221 , sizeof V_143 ) )
goto V_115;
V_36 = V_266 ( V_19 , & V_143 ) ;
break;
}
#ifdef F_296
case V_267 :
V_36 = 0 ;
F_142 ( & V_19 -> V_76 ) ;
if ( F_267 ( & V_19 -> V_212 ) != 0 )
V_36 = - V_268 ;
else
V_19 -> V_269 = V_220 ;
F_24 ( & V_19 -> V_76 ) ;
break;
#endif
#ifdef F_297
case V_270 : {
struct V_271 V_272 ;
V_36 = - V_133 ;
if ( F_283 ( & V_272 , V_221 , sizeof V_272 ) )
goto V_115;
V_36 = F_298 ( V_19 , & V_272 ) ;
break;
}
#endif
#ifdef F_299
case V_273 :
case V_274 : {
struct V_275 V_276 ;
V_36 = - V_133 ;
if ( F_283 ( & V_276 , V_221 , sizeof V_276 ) )
goto V_115;
V_36 = F_300 ( V_19 , & V_276 ) ;
if ( V_36 )
goto V_115;
V_36 = - V_133 ;
if ( V_219 == V_273 ) {
if ( F_145 ( V_221 , & V_276 , sizeof V_276 ) )
goto V_115;
}
V_36 = 0 ;
break;
}
#endif
default:
V_36 = F_301 ( V_94 , V_219 , V_220 ) ;
if ( V_36 == - V_277 )
V_36 = F_302 ( V_19 , V_219 , V_220 ) ;
}
V_115:
return V_36 ;
}
static long F_303 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_19 * V_19 = V_94 -> V_95 ;
int V_36 ;
if ( V_19 -> V_48 != V_12 -> V_48 )
return - V_225 ;
switch ( V_219 ) {
case V_258 : {
struct V_278 V_279 ;
struct V_128 log ;
V_36 = - V_133 ;
if ( F_283 ( & V_279 , ( void V_120 * ) V_220 ,
sizeof( V_279 ) ) )
goto V_115;
log . V_113 = V_279 . V_113 ;
log . V_280 = V_279 . V_280 ;
log . V_281 = V_279 . V_281 ;
log . V_87 = F_290 ( V_279 . V_87 ) ;
V_36 = F_293 ( V_19 , & log ) ;
break;
}
default:
V_36 = F_292 ( V_94 , V_219 , V_220 ) ;
}
V_115:
return V_36 ;
}
static int F_304 ( struct V_136 * V_137 , struct V_197 * V_198 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_84 ;
int V_89 ;
T_5 V_135 = V_198 -> V_200 ;
struct V_19 * V_19 = V_137 -> V_199 -> V_95 ;
V_84 = F_152 ( V_19 , V_135 ) ;
if ( F_153 ( V_84 ) )
return V_282 ;
V_89 = F_305 ( V_12 , V_12 -> V_48 , V_84 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_89 != 1 ) )
return V_282 ;
V_198 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_306 ( struct V_93 * V_93 , struct V_136 * V_137 )
{
V_137 -> V_204 = & V_283 ;
return 0 ;
}
static int F_307 ( unsigned long type )
{
int V_36 ;
struct V_19 * V_19 ;
V_19 = F_76 ( type ) ;
if ( F_262 ( V_19 ) )
return F_263 ( V_19 ) ;
#ifdef F_254
V_36 = F_308 ( V_19 ) ;
if ( V_36 < 0 ) {
F_117 ( V_19 ) ;
return V_36 ;
}
#endif
V_36 = F_259 ( L_2 , & V_284 , V_19 , V_207 ) ;
if ( V_36 < 0 )
F_117 ( V_19 ) ;
return V_36 ;
}
static long F_309 ( long V_220 )
{
switch ( V_220 ) {
case V_285 :
case V_286 :
case V_287 :
#ifdef F_296
case V_288 :
#endif
case V_289 :
#ifdef F_297
case V_290 :
#endif
return 1 ;
#ifdef F_310
case F_310 :
return V_291 ;
#endif
default:
break;
}
return F_311 ( V_220 ) ;
}
static long F_312 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
long V_36 = - V_110 ;
switch ( V_219 ) {
case V_292 :
V_36 = - V_110 ;
if ( V_220 )
goto V_115;
V_36 = V_293 ;
break;
case V_294 :
V_36 = F_307 ( V_220 ) ;
break;
case V_295 :
V_36 = F_309 ( V_220 ) ;
break;
case V_296 :
V_36 = - V_110 ;
if ( V_220 )
goto V_115;
V_36 = V_83 ;
#ifdef F_253
V_36 += V_83 ;
#endif
#ifdef F_254
V_36 += V_83 ;
#endif
break;
case V_297 :
case V_298 :
case V_299 :
V_36 = - V_300 ;
break;
default:
return F_313 ( V_94 , V_219 , V_220 ) ;
}
V_115:
return V_36 ;
}
static void F_314 ( void * V_301 )
{
int V_8 = F_315 () ;
int V_36 ;
if ( F_316 ( V_8 , V_302 ) )
return;
F_32 ( V_8 , V_302 ) ;
V_36 = F_317 ( NULL ) ;
if ( V_36 ) {
F_318 ( V_8 , V_302 ) ;
F_86 ( & V_303 ) ;
F_319 ( V_304 L_3
L_4 , V_8 ) ;
}
}
static void F_320 ( void * V_301 )
{
F_89 ( & V_80 ) ;
F_314 ( V_301 ) ;
F_91 ( & V_80 ) ;
}
static void F_321 ( void * V_301 )
{
int V_8 = F_315 () ;
if ( ! F_316 ( V_8 , V_302 ) )
return;
F_318 ( V_8 , V_302 ) ;
F_322 ( NULL ) ;
}
static void F_323 ( void * V_301 )
{
F_89 ( & V_80 ) ;
F_321 ( V_301 ) ;
F_91 ( & V_80 ) ;
}
static void F_324 ( void )
{
F_66 ( ! V_305 ) ;
V_305 -- ;
if ( ! V_305 )
F_325 ( F_321 , NULL , 1 ) ;
}
static void F_93 ( void )
{
F_89 ( & V_80 ) ;
F_324 () ;
F_91 ( & V_80 ) ;
}
static int F_80 ( void )
{
int V_36 = 0 ;
F_89 ( & V_80 ) ;
V_305 ++ ;
if ( V_305 == 1 ) {
F_88 ( & V_303 , 0 ) ;
F_325 ( F_314 , NULL , 1 ) ;
if ( F_267 ( & V_303 ) ) {
F_324 () ;
V_36 = - V_268 ;
}
}
F_91 ( & V_80 ) ;
return V_36 ;
}
static int F_326 ( struct V_306 * V_307 , unsigned long V_308 ,
void * V_208 )
{
int V_8 = ( long ) V_208 ;
if ( ! V_305 )
return V_309 ;
V_308 &= ~ V_310 ;
switch ( V_308 ) {
case V_311 :
F_319 ( V_304 L_5 ,
V_8 ) ;
F_323 ( NULL ) ;
break;
case V_312 :
F_319 ( V_304 L_6 ,
V_8 ) ;
F_320 ( NULL ) ;
break;
}
return V_309 ;
}
T_10 void F_327 ( void )
{
F_328 () ;
}
static int F_329 ( struct V_306 * V_307 , unsigned long V_308 ,
void * V_208 )
{
F_319 ( V_304 L_7 ) ;
V_313 = true ;
F_325 ( F_321 , NULL , 1 ) ;
return V_309 ;
}
static void F_110 ( struct V_73 * V_314 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_314 -> V_315 ; V_21 ++ ) {
struct V_316 * V_317 = V_314 -> V_318 [ V_21 ] . V_319 ;
F_330 ( V_317 ) ;
}
F_94 ( V_314 ) ;
}
int F_331 ( const void * V_320 , const void * V_321 )
{
const struct V_322 * V_323 = V_320 ;
const struct V_322 * V_324 = V_321 ;
if ( V_323 -> V_84 < V_324 -> V_84 )
return - 1 ;
if ( V_323 -> V_84 + V_323 -> V_145 > V_324 -> V_84 + V_324 -> V_145 )
return 1 ;
return 0 ;
}
int F_332 ( struct V_73 * V_314 , struct V_316 * V_319 ,
T_6 V_84 , int V_145 )
{
V_314 -> V_318 [ V_314 -> V_315 ++ ] = (struct V_322 ) {
. V_84 = V_84 ,
. V_145 = V_145 ,
. V_319 = V_319 ,
} ;
F_126 ( V_314 -> V_318 , V_314 -> V_315 , sizeof( struct V_322 ) ,
F_331 , NULL ) ;
return 0 ;
}
int F_333 ( struct V_73 * V_314 ,
T_6 V_84 , int V_145 )
{
struct V_322 * V_318 , V_325 ;
int V_326 ;
V_325 = (struct V_322 ) {
. V_84 = V_84 ,
. V_145 = V_145 ,
} ;
V_318 = bsearch ( & V_325 , V_314 -> V_318 , V_314 -> V_315 ,
sizeof( struct V_322 ) , F_331 ) ;
if ( V_318 == NULL )
return - V_132 ;
V_326 = V_318 - V_314 -> V_318 ;
while ( V_326 > 0 && F_331 ( & V_325 , & V_314 -> V_318 [ V_326 - 1 ] ) == 0 )
V_326 -- ;
return V_326 ;
}
int F_334 ( struct V_19 * V_19 , enum V_327 V_328 , T_6 V_84 ,
int V_145 , const void * V_308 )
{
int V_51 ;
struct V_73 * V_314 ;
struct V_322 V_318 ;
V_318 = (struct V_322 ) {
. V_84 = V_84 ,
. V_145 = V_145 ,
} ;
V_314 = F_335 ( V_19 -> V_72 [ V_328 ] , & V_19 -> V_52 ) ;
V_51 = F_333 ( V_314 , V_84 , V_145 ) ;
if ( V_51 < 0 )
return - V_300 ;
while ( V_51 < V_314 -> V_315 &&
F_331 ( & V_318 , & V_314 -> V_318 [ V_51 ] ) == 0 ) {
if ( ! F_336 ( V_314 -> V_318 [ V_51 ] . V_319 , V_84 , V_145 , V_308 ) )
return 0 ;
V_51 ++ ;
}
return - V_300 ;
}
int F_337 ( struct V_19 * V_19 , enum V_327 V_328 , T_6 V_84 ,
int V_145 , void * V_308 )
{
int V_51 ;
struct V_73 * V_314 ;
struct V_322 V_318 ;
V_318 = (struct V_322 ) {
. V_84 = V_84 ,
. V_145 = V_145 ,
} ;
V_314 = F_335 ( V_19 -> V_72 [ V_328 ] , & V_19 -> V_52 ) ;
V_51 = F_333 ( V_314 , V_84 , V_145 ) ;
if ( V_51 < 0 )
return - V_300 ;
while ( V_51 < V_314 -> V_315 &&
F_331 ( & V_318 , & V_314 -> V_318 [ V_51 ] ) == 0 ) {
if ( ! F_338 ( V_314 -> V_318 [ V_51 ] . V_319 , V_84 , V_145 , V_308 ) )
return 0 ;
V_51 ++ ;
}
return - V_300 ;
}
int F_339 ( struct V_19 * V_19 , enum V_327 V_328 , T_6 V_84 ,
int V_145 , struct V_316 * V_319 )
{
struct V_73 * V_329 , * V_314 ;
V_314 = V_19 -> V_72 [ V_328 ] ;
if ( V_314 -> V_315 > V_330 - 1 )
return - V_331 ;
V_329 = F_83 ( sizeof( * V_314 ) + ( ( V_314 -> V_315 + 1 ) *
sizeof( struct V_322 ) ) , V_39 ) ;
if ( ! V_329 )
return - V_41 ;
memcpy ( V_329 , V_314 , sizeof( * V_314 ) + ( V_314 -> V_315 *
sizeof( struct V_322 ) ) ) ;
F_332 ( V_329 , V_319 , V_84 , V_145 ) ;
F_12 ( V_19 -> V_72 [ V_328 ] , V_329 ) ;
F_135 ( & V_19 -> V_52 ) ;
F_94 ( V_314 ) ;
return 0 ;
}
int F_340 ( struct V_19 * V_19 , enum V_327 V_328 ,
struct V_316 * V_319 )
{
int V_21 , V_36 ;
struct V_73 * V_329 , * V_314 ;
V_314 = V_19 -> V_72 [ V_328 ] ;
V_36 = - V_132 ;
for ( V_21 = 0 ; V_21 < V_314 -> V_315 ; V_21 ++ )
if ( V_314 -> V_318 [ V_21 ] . V_319 == V_319 ) {
V_36 = 0 ;
break;
}
if ( V_36 )
return V_36 ;
V_329 = F_83 ( sizeof( * V_314 ) + ( ( V_314 -> V_315 - 1 ) *
sizeof( struct V_322 ) ) , V_39 ) ;
if ( ! V_329 )
return - V_41 ;
memcpy ( V_329 , V_314 , sizeof( * V_314 ) + V_21 * sizeof( struct V_322 ) ) ;
V_329 -> V_315 -- ;
memcpy ( V_329 -> V_318 + V_21 , V_314 -> V_318 + V_21 + 1 ,
( V_329 -> V_315 - V_21 ) * sizeof( struct V_322 ) ) ;
F_12 ( V_19 -> V_72 [ V_328 ] , V_329 ) ;
F_135 ( & V_19 -> V_52 ) ;
F_94 ( V_314 ) ;
return V_36 ;
}
static int F_341 ( void * V_332 , T_11 * V_308 )
{
unsigned V_173 = ( long ) V_332 ;
struct V_19 * V_19 ;
* V_308 = 0 ;
F_89 ( & V_80 ) ;
F_342 ( V_19 , & V_81 , V_81 )
* V_308 += * ( T_4 * ) ( ( void * ) V_19 + V_173 ) ;
F_91 ( & V_80 ) ;
return 0 ;
}
static int F_343 ( void * V_332 , T_11 * V_308 )
{
unsigned V_173 = ( long ) V_332 ;
struct V_19 * V_19 ;
struct V_6 * V_7 ;
int V_21 ;
* V_308 = 0 ;
F_89 ( & V_80 ) ;
F_342 (kvm, &vm_list, vm_list)
F_28 ( V_21 , V_7 , V_19 )
* V_308 += * ( T_4 * ) ( ( void * ) V_7 + V_173 ) ;
F_91 ( & V_80 ) ;
return 0 ;
}
static int F_344 ( void )
{
int V_36 = - V_133 ;
struct V_333 * V_251 ;
V_334 = F_345 ( L_8 , NULL ) ;
if ( V_334 == NULL )
goto V_115;
for ( V_251 = V_335 ; V_251 -> V_336 ; ++ V_251 ) {
V_251 -> V_337 = F_346 ( V_251 -> V_336 , 0444 , V_334 ,
( void * ) ( long ) V_251 -> V_173 ,
V_338 [ V_251 -> V_339 ] ) ;
if ( V_251 -> V_337 == NULL )
goto V_340;
}
return 0 ;
V_340:
F_347 ( V_334 ) ;
V_115:
return V_36 ;
}
static void F_348 ( void )
{
struct V_333 * V_251 ;
for ( V_251 = V_335 ; V_251 -> V_336 ; ++ V_251 )
F_349 ( V_251 -> V_337 ) ;
F_349 ( V_334 ) ;
}
static int F_350 ( void )
{
if ( V_305 )
F_321 ( NULL ) ;
return 0 ;
}
static void F_351 ( void )
{
if ( V_305 ) {
F_192 ( F_352 ( & V_80 ) ) ;
F_314 ( NULL ) ;
}
}
static inline
struct V_6 * F_353 ( struct V_17 * V_341 )
{
return F_53 ( V_341 , struct V_6 , V_17 ) ;
}
static void F_354 ( struct V_17 * V_341 , int V_8 )
{
struct V_6 * V_7 = F_353 ( V_341 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_355 ( struct V_17 * V_341 ,
struct V_146 * V_342 )
{
struct V_6 * V_7 = F_353 ( V_341 ) ;
F_21 ( V_7 ) ;
}
int F_356 ( void * V_343 , unsigned V_344 , unsigned V_345 ,
struct V_346 * V_346 )
{
int V_36 ;
int V_8 ;
V_36 = F_357 ( V_343 ) ;
if ( V_36 )
goto V_347;
if ( ! F_27 ( & V_302 , V_39 ) ) {
V_36 = - V_41 ;
goto V_348;
}
V_36 = F_358 () ;
if ( V_36 < 0 )
goto V_349;
F_359 (cpu) {
F_360 ( V_8 ,
V_350 ,
& V_36 , 1 ) ;
if ( V_36 < 0 )
goto V_351;
}
V_36 = F_361 ( & V_352 ) ;
if ( V_36 )
goto V_353;
F_362 ( & V_354 ) ;
if ( ! V_345 )
V_345 = F_363 ( struct V_6 ) ;
V_355 = F_364 ( L_9 , V_344 , V_345 ,
0 , NULL ) ;
if ( ! V_355 ) {
V_36 = - V_41 ;
goto V_356;
}
V_36 = F_365 () ;
if ( V_36 )
goto V_123;
V_357 . V_358 = V_346 ;
V_284 . V_358 = V_346 ;
V_206 . V_358 = V_346 ;
V_36 = F_366 ( & V_359 ) ;
if ( V_36 ) {
F_319 ( V_360 L_10 ) ;
goto V_361;
}
F_367 ( & V_362 ) ;
V_209 . V_363 = F_354 ;
V_209 . V_364 = F_355 ;
V_36 = F_344 () ;
if ( V_36 ) {
F_319 ( V_360 L_11 ) ;
goto V_365;
}
return 0 ;
V_365:
F_368 ( & V_362 ) ;
V_361:
F_369 () ;
V_123:
F_370 ( V_355 ) ;
V_356:
F_371 ( & V_354 ) ;
F_372 ( & V_352 ) ;
V_353:
V_351:
F_373 () ;
V_349:
F_35 ( V_302 ) ;
V_348:
F_374 () ;
V_347:
return V_36 ;
}
void F_375 ( void )
{
F_348 () ;
F_376 ( & V_359 ) ;
F_370 ( V_355 ) ;
F_369 () ;
F_368 ( & V_362 ) ;
F_371 ( & V_354 ) ;
F_372 ( & V_352 ) ;
F_325 ( F_321 , NULL , 1 ) ;
F_373 () ;
F_374 () ;
F_35 ( V_302 ) ;
}
