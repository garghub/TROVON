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
int F_39 ( struct V_6 * V_7 , struct V_19 * V_19 , unsigned V_34 )
{
struct V_3 * V_3 ;
int V_35 ;
F_40 ( & V_7 -> V_9 ) ;
V_7 -> V_8 = - 1 ;
V_7 -> V_19 = V_19 ;
V_7 -> V_36 = V_34 ;
V_7 -> V_11 = NULL ;
F_41 ( & V_7 -> V_37 ) ;
F_42 ( V_7 ) ;
V_3 = F_43 ( V_38 | V_39 ) ;
if ( ! V_3 ) {
V_35 = - V_40 ;
goto V_41;
}
V_7 -> V_42 = F_44 ( V_3 ) ;
F_45 ( V_7 , false ) ;
F_46 ( V_7 , false ) ;
V_35 = F_47 ( V_7 ) ;
if ( V_35 < 0 )
goto V_43;
return 0 ;
V_43:
F_48 ( ( unsigned long ) V_7 -> V_42 ) ;
V_41:
return V_35 ;
}
void F_49 ( struct V_6 * V_7 )
{
F_14 ( V_7 -> V_11 ) ;
F_50 ( V_7 ) ;
F_48 ( ( unsigned long ) V_7 -> V_42 ) ;
}
static inline struct V_19 * F_51 ( struct V_44 * V_45 )
{
return F_52 ( V_45 , struct V_19 , V_44 ) ;
}
static void F_53 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_19 * V_19 = F_51 ( V_45 ) ;
int V_49 , V_50 ;
V_50 = F_54 ( & V_19 -> V_51 ) ;
F_55 ( & V_19 -> V_52 ) ;
V_19 -> V_53 ++ ;
V_49 = F_56 ( V_19 , V_48 ) | V_19 -> V_29 ;
if ( V_49 )
F_36 ( V_19 ) ;
F_57 ( & V_19 -> V_52 ) ;
F_58 ( & V_19 -> V_51 , V_50 ) ;
}
static void F_59 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 ,
T_3 V_54 )
{
struct V_19 * V_19 = F_51 ( V_45 ) ;
int V_50 ;
V_50 = F_54 ( & V_19 -> V_51 ) ;
F_55 ( & V_19 -> V_52 ) ;
V_19 -> V_53 ++ ;
F_60 ( V_19 , V_48 , V_54 ) ;
F_57 ( & V_19 -> V_52 ) ;
F_58 ( & V_19 -> V_51 , V_50 ) ;
}
static void F_61 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_19 * V_19 = F_51 ( V_45 ) ;
int V_49 = 0 , V_50 ;
V_50 = F_54 ( & V_19 -> V_51 ) ;
F_55 ( & V_19 -> V_52 ) ;
V_19 -> V_57 ++ ;
V_49 = F_62 ( V_19 , V_55 , V_56 ) ;
V_49 |= V_19 -> V_29 ;
if ( V_49 )
F_36 ( V_19 ) ;
F_57 ( & V_19 -> V_52 ) ;
F_58 ( & V_19 -> V_51 , V_50 ) ;
}
static void F_63 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_55 ,
unsigned long V_56 )
{
struct V_19 * V_19 = F_51 ( V_45 ) ;
F_55 ( & V_19 -> V_52 ) ;
V_19 -> V_53 ++ ;
F_64 () ;
V_19 -> V_57 -- ;
F_57 ( & V_19 -> V_52 ) ;
F_65 ( V_19 -> V_57 < 0 ) ;
}
static int F_66 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_19 * V_19 = F_51 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_54 ( & V_19 -> V_51 ) ;
F_55 ( & V_19 -> V_52 ) ;
V_58 = F_67 ( V_19 , V_48 ) ;
if ( V_58 )
F_36 ( V_19 ) ;
F_57 ( & V_19 -> V_52 ) ;
F_58 ( & V_19 -> V_51 , V_50 ) ;
return V_58 ;
}
static int F_68 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
unsigned long V_48 )
{
struct V_19 * V_19 = F_51 ( V_45 ) ;
int V_58 , V_50 ;
V_50 = F_54 ( & V_19 -> V_51 ) ;
F_55 ( & V_19 -> V_52 ) ;
V_58 = F_69 ( V_19 , V_48 ) ;
F_57 ( & V_19 -> V_52 ) ;
F_58 ( & V_19 -> V_51 , V_50 ) ;
return V_58 ;
}
static void F_70 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_19 * V_19 = F_51 ( V_45 ) ;
int V_50 ;
V_50 = F_54 ( & V_19 -> V_51 ) ;
F_71 ( V_19 ) ;
F_58 ( & V_19 -> V_51 , V_50 ) ;
}
static int F_72 ( struct V_19 * V_19 )
{
V_19 -> V_44 . V_59 = & V_60 ;
return F_73 ( & V_19 -> V_44 , V_12 -> V_47 ) ;
}
static int F_72 ( struct V_19 * V_19 )
{
return 0 ;
}
static void F_74 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_61 * V_62 = V_19 -> V_63 ;
for ( V_21 = 0 ; V_21 < V_64 ; V_21 ++ )
V_62 -> V_65 [ V_21 ] = V_62 -> V_63 [ V_21 ] . V_34 = V_21 ;
}
static struct V_19 * F_75 ( unsigned long type )
{
int V_35 , V_21 ;
struct V_19 * V_19 = F_76 () ;
if ( ! V_19 )
return F_77 ( - V_40 ) ;
V_35 = F_78 ( V_19 , type ) ;
if ( V_35 )
goto V_66;
V_35 = F_79 () ;
if ( V_35 )
goto V_66;
#ifdef F_80
F_81 ( & V_19 -> V_67 ) ;
F_81 ( & V_19 -> V_68 ) ;
#endif
V_35 = - V_40 ;
V_19 -> V_63 = F_82 ( sizeof( struct V_61 ) , V_38 ) ;
if ( ! V_19 -> V_63 )
goto V_69;
F_74 ( V_19 ) ;
if ( F_83 ( & V_19 -> V_51 ) )
goto V_69;
for ( V_21 = 0 ; V_21 < V_70 ; V_21 ++ ) {
V_19 -> V_71 [ V_21 ] = F_82 ( sizeof( struct V_72 ) ,
V_38 ) ;
if ( ! V_19 -> V_71 [ V_21 ] )
goto V_73;
}
F_84 ( & V_19 -> V_52 ) ;
V_19 -> V_47 = V_12 -> V_47 ;
F_85 ( & V_19 -> V_47 -> V_74 ) ;
F_86 ( V_19 ) ;
F_40 ( & V_19 -> V_75 ) ;
F_40 ( & V_19 -> V_76 ) ;
F_40 ( & V_19 -> V_77 ) ;
F_87 ( & V_19 -> V_78 , 1 ) ;
V_35 = F_72 ( V_19 ) ;
if ( V_35 )
goto V_73;
F_88 ( & V_79 ) ;
F_89 ( & V_19 -> V_80 , & V_80 ) ;
F_90 ( & V_79 ) ;
return V_19 ;
V_73:
F_91 ( & V_19 -> V_51 ) ;
V_69:
F_92 () ;
V_66:
for ( V_21 = 0 ; V_21 < V_70 ; V_21 ++ )
F_93 ( V_19 -> V_71 [ V_21 ] ) ;
F_93 ( V_19 -> V_63 ) ;
F_94 ( V_19 ) ;
return F_77 ( V_35 ) ;
}
void * F_95 ( unsigned long V_81 )
{
if ( V_81 > V_82 )
return F_96 ( V_81 ) ;
else
return F_82 ( V_81 , V_38 ) ;
}
void F_97 ( const void * V_83 )
{
if ( F_98 ( V_83 ) )
F_99 ( V_83 ) ;
else
F_93 ( V_83 ) ;
}
static void F_100 ( struct V_84 * V_85 )
{
if ( ! V_85 -> V_86 )
return;
F_97 ( V_85 -> V_86 ) ;
V_85 -> V_86 = NULL ;
}
static void F_101 ( struct V_84 * free ,
struct V_84 * V_87 )
{
if ( ! V_87 || free -> V_86 != V_87 -> V_86 )
F_100 ( free ) ;
F_102 ( free , V_87 ) ;
free -> V_88 = 0 ;
}
void F_103 ( struct V_19 * V_19 )
{
struct V_61 * V_62 = V_19 -> V_63 ;
struct V_84 * V_85 ;
F_104 (memslot, slots)
F_101 ( V_85 , NULL ) ;
F_93 ( V_19 -> V_63 ) ;
}
static void F_105 ( struct V_19 * V_19 )
{
int V_21 ;
struct V_46 * V_47 = V_19 -> V_47 ;
F_106 ( V_19 ) ;
F_88 ( & V_79 ) ;
F_107 ( & V_19 -> V_80 ) ;
F_90 ( & V_79 ) ;
F_108 ( V_19 ) ;
for ( V_21 = 0 ; V_21 < V_70 ; V_21 ++ )
F_109 ( V_19 -> V_71 [ V_21 ] ) ;
F_110 ( V_19 ) ;
#if F_111 ( V_89 ) && F_111 ( V_90 )
F_112 ( & V_19 -> V_44 , V_19 -> V_47 ) ;
#else
F_71 ( V_19 ) ;
#endif
F_113 ( V_19 ) ;
F_103 ( V_19 ) ;
F_91 ( & V_19 -> V_51 ) ;
F_94 ( V_19 ) ;
F_92 () ;
F_114 ( V_47 ) ;
}
void F_115 ( struct V_19 * V_19 )
{
F_85 ( & V_19 -> V_78 ) ;
}
void F_116 ( struct V_19 * V_19 )
{
if ( F_117 ( & V_19 -> V_78 ) )
F_105 ( V_19 ) ;
}
static int F_118 ( struct V_91 * V_91 , struct V_92 * V_93 )
{
struct V_19 * V_19 = V_93 -> V_94 ;
F_119 ( V_19 ) ;
F_116 ( V_19 ) ;
return 0 ;
}
static int F_120 ( struct V_84 * V_85 )
{
#ifndef F_121
unsigned long V_95 = 2 * F_122 ( V_85 ) ;
V_85 -> V_86 = F_95 ( V_95 ) ;
if ( ! V_85 -> V_86 )
return - V_40 ;
#endif
return 0 ;
}
static int F_123 ( const void * V_96 , const void * V_97 )
{
struct V_84 * V_98 , * V_99 ;
V_98 = (struct V_84 * ) V_96 ;
V_99 = (struct V_84 * ) V_97 ;
if ( V_98 -> V_88 < V_99 -> V_88 )
return 1 ;
if ( V_98 -> V_88 > V_99 -> V_88 )
return - 1 ;
return 0 ;
}
static void F_124 ( struct V_61 * V_62 )
{
int V_21 ;
F_125 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_84 ) , F_123 , NULL ) ;
for ( V_21 = 0 ; V_21 < V_64 ; V_21 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_21 ] . V_34 ] = V_21 ;
}
void F_126 ( struct V_61 * V_62 , struct V_84 * V_100 )
{
if ( V_100 ) {
int V_34 = V_100 -> V_34 ;
struct V_84 * V_101 = F_127 ( V_62 , V_34 ) ;
unsigned long V_88 = V_101 -> V_88 ;
* V_101 = * V_100 ;
if ( V_100 -> V_88 != V_88 )
F_124 ( V_62 ) ;
}
V_62 -> V_102 ++ ;
}
static int F_128 ( struct V_103 * V_104 )
{
T_4 V_105 = V_106 ;
#ifdef F_129
V_105 |= V_107 ;
#endif
if ( V_104 -> V_108 & ~ V_105 )
return - V_109 ;
return 0 ;
}
int F_130 ( struct V_19 * V_19 ,
struct V_103 * V_104 ,
int V_110 )
{
int V_35 ;
T_5 V_111 ;
unsigned long V_88 ;
unsigned long V_21 ;
struct V_84 * V_85 ;
struct V_84 V_101 , V_100 ;
struct V_61 * V_62 , * V_112 ;
V_35 = F_128 ( V_104 ) ;
if ( V_35 )
goto V_113;
V_35 = - V_109 ;
if ( V_104 -> V_114 & ( V_82 - 1 ) )
goto V_113;
if ( V_104 -> V_115 & ( V_82 - 1 ) )
goto V_113;
if ( V_110 &&
( ( V_104 -> V_116 & ( V_82 - 1 ) ) ||
! F_131 ( V_117 ,
( void V_118 * ) ( unsigned long ) V_104 -> V_116 ,
V_104 -> V_114 ) ) )
goto V_113;
if ( V_104 -> V_119 >= V_64 )
goto V_113;
if ( V_104 -> V_115 + V_104 -> V_114 < V_104 -> V_115 )
goto V_113;
V_85 = F_127 ( V_19 -> V_63 , V_104 -> V_119 ) ;
V_111 = V_104 -> V_115 >> V_120 ;
V_88 = V_104 -> V_114 >> V_120 ;
V_35 = - V_109 ;
if ( V_88 > V_121 )
goto V_113;
if ( ! V_88 )
V_104 -> V_108 &= ~ V_106 ;
V_100 = V_101 = * V_85 ;
V_100 . V_34 = V_104 -> V_119 ;
V_100 . V_111 = V_111 ;
V_100 . V_88 = V_88 ;
V_100 . V_108 = V_104 -> V_108 ;
V_35 = - V_109 ;
if ( V_88 && V_101 . V_88 && V_88 != V_101 . V_88 )
goto V_122;
V_35 = - V_123 ;
for ( V_21 = 0 ; V_21 < V_124 ; ++ V_21 ) {
struct V_84 * V_125 = & V_19 -> V_63 -> V_63 [ V_21 ] ;
if ( V_125 == V_85 || ! V_125 -> V_88 )
continue;
if ( ! ( ( V_111 + V_88 <= V_125 -> V_111 ) ||
( V_111 >= V_125 -> V_111 + V_125 -> V_88 ) ) )
goto V_122;
}
if ( ! ( V_100 . V_108 & V_106 ) )
V_100 . V_86 = NULL ;
V_35 = - V_40 ;
if ( V_88 && ! V_101 . V_88 ) {
V_100 . V_110 = V_110 ;
V_100 . V_116 = V_104 -> V_116 ;
if ( F_132 ( & V_100 , V_88 ) )
goto V_122;
}
if ( ( V_100 . V_108 & V_106 ) && ! V_100 . V_86 ) {
if ( F_120 ( & V_100 ) < 0 )
goto V_122;
}
if ( ! V_88 || V_111 != V_101 . V_111 ) {
struct V_84 * V_119 ;
V_35 = - V_40 ;
V_62 = F_133 ( V_19 -> V_63 , sizeof( struct V_61 ) ,
V_38 ) ;
if ( ! V_62 )
goto V_122;
V_119 = F_127 ( V_62 , V_104 -> V_119 ) ;
V_119 -> V_108 |= V_126 ;
F_126 ( V_62 , NULL ) ;
V_112 = V_19 -> V_63 ;
F_12 ( V_19 -> V_63 , V_62 ) ;
F_134 ( & V_19 -> V_51 ) ;
F_135 ( V_19 , V_119 ) ;
F_93 ( V_112 ) ;
}
V_35 = F_136 ( V_19 , & V_100 , V_101 , V_104 , V_110 ) ;
if ( V_35 )
goto V_122;
if ( V_88 ) {
V_35 = F_137 ( V_19 , & V_100 ) ;
if ( V_35 )
goto V_122;
} else
F_138 ( V_19 , & V_101 ) ;
V_35 = - V_40 ;
V_62 = F_133 ( V_19 -> V_63 , sizeof( struct V_61 ) ,
V_38 ) ;
if ( ! V_62 )
goto V_122;
if ( ! V_88 ) {
V_100 . V_86 = NULL ;
memset ( & V_100 . V_127 , 0 , sizeof( V_100 . V_127 ) ) ;
}
F_126 ( V_62 , & V_100 ) ;
V_112 = V_19 -> V_63 ;
F_12 ( V_19 -> V_63 , V_62 ) ;
F_134 ( & V_19 -> V_51 ) ;
F_139 ( V_19 , V_104 , V_101 , V_110 ) ;
F_101 ( & V_101 , & V_100 ) ;
F_93 ( V_112 ) ;
return 0 ;
V_122:
F_101 ( & V_100 , & V_101 ) ;
V_113:
return V_35 ;
}
int F_140 ( struct V_19 * V_19 ,
struct V_103 * V_104 ,
int V_110 )
{
int V_35 ;
F_141 ( & V_19 -> V_77 ) ;
V_35 = F_130 ( V_19 , V_104 , V_110 ) ;
F_24 ( & V_19 -> V_77 ) ;
return V_35 ;
}
int F_142 ( struct V_19 * V_19 ,
struct
V_103 * V_104 ,
int V_110 )
{
if ( V_104 -> V_119 >= V_124 )
return - V_109 ;
return F_140 ( V_19 , V_104 , V_110 ) ;
}
int F_143 ( struct V_19 * V_19 ,
struct V_128 * log , int * V_129 )
{
struct V_84 * V_85 ;
int V_35 , V_21 ;
unsigned long V_130 ;
unsigned long V_131 = 0 ;
V_35 = - V_109 ;
if ( log -> V_119 >= V_124 )
goto V_113;
V_85 = F_127 ( V_19 -> V_63 , log -> V_119 ) ;
V_35 = - V_132 ;
if ( ! V_85 -> V_86 )
goto V_113;
V_130 = F_122 ( V_85 ) ;
for ( V_21 = 0 ; ! V_131 && V_21 < V_130 / sizeof( long ) ; ++ V_21 )
V_131 = V_85 -> V_86 [ V_21 ] ;
V_35 = - V_133 ;
if ( F_144 ( log -> V_86 , V_85 -> V_86 , V_130 ) )
goto V_113;
if ( V_131 )
* V_129 = 1 ;
V_35 = 0 ;
V_113:
return V_35 ;
}
bool F_145 ( void )
{
return V_134 ;
}
void F_146 ( void )
{
V_134 = false ;
}
struct V_84 * F_147 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_148 ( V_61 ( V_19 ) , V_135 ) ;
}
int F_149 ( struct V_19 * V_19 , T_5 V_135 )
{
struct V_84 * V_85 = F_147 ( V_19 , V_135 ) ;
if ( ! V_85 || V_85 -> V_34 >= V_124 ||
V_85 -> V_108 & V_126 )
return 0 ;
return 1 ;
}
unsigned long F_150 ( struct V_19 * V_19 , T_5 V_135 )
{
struct V_136 * V_137 ;
unsigned long V_83 , V_81 ;
V_81 = V_82 ;
V_83 = F_151 ( V_19 , V_135 ) ;
if ( F_152 ( V_83 ) )
return V_82 ;
F_153 ( & V_12 -> V_47 -> V_138 ) ;
V_137 = F_154 ( V_12 -> V_47 , V_83 ) ;
if ( ! V_137 )
goto V_113;
V_81 = F_155 ( V_137 ) ;
V_113:
F_156 ( & V_12 -> V_47 -> V_138 ) ;
return V_81 ;
}
static bool F_157 ( struct V_84 * V_119 )
{
return V_119 -> V_108 & V_107 ;
}
static unsigned long F_158 ( struct V_84 * V_119 , T_5 V_135 ,
T_5 * V_139 , bool V_140 )
{
if ( ! V_119 || V_119 -> V_108 & V_126 )
return V_141 ;
if ( F_157 ( V_119 ) && V_140 )
return V_142 ;
if ( V_139 )
* V_139 = V_119 -> V_88 - ( V_135 - V_119 -> V_111 ) ;
return F_159 ( V_119 , V_135 ) ;
}
static unsigned long F_160 ( struct V_84 * V_119 , T_5 V_135 ,
T_5 * V_139 )
{
return F_158 ( V_119 , V_135 , V_139 , true ) ;
}
unsigned long F_161 ( struct V_84 * V_119 ,
T_5 V_135 )
{
return F_160 ( V_119 , V_135 , NULL ) ;
}
unsigned long F_151 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_160 ( F_147 ( V_19 , V_135 ) , V_135 , NULL ) ;
}
static unsigned long F_162 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_158 ( F_147 ( V_19 , V_135 ) , V_135 , NULL , false ) ;
}
static int F_163 ( void * V_143 , void V_118 * V_144 , int V_145 )
{
return F_164 ( V_143 , V_144 , V_145 ) ;
}
static int F_165 ( void * V_143 , void V_118 * V_144 , int V_145 )
{
return F_166 ( V_143 , V_144 , V_145 ) ;
}
int F_167 ( struct V_146 * V_147 , struct V_46 * V_47 ,
unsigned long V_55 , int V_140 , struct V_3 * * V_3 )
{
int V_108 = V_148 | V_149 | V_150 | V_151 ;
if ( V_140 )
V_108 |= V_152 ;
return F_168 ( V_147 , V_47 , V_55 , 1 , V_108 , V_3 , NULL , NULL ) ;
}
static inline int F_169 ( unsigned long V_83 )
{
int V_153 , V_108 = V_148 | V_150 | V_152 ;
V_153 = F_168 ( V_12 , V_12 -> V_47 , V_83 , 1 ,
V_108 , NULL , NULL , NULL ) ;
return V_153 == - V_154 ;
}
static bool F_170 ( unsigned long V_83 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_88 ;
if ( ! ( V_156 || V_155 ) )
return false ;
if ( ! ( V_157 || V_158 ) )
return false ;
V_88 = F_171 ( V_83 , 1 , 1 , V_3 ) ;
if ( V_88 == 1 ) {
* V_1 = F_172 ( V_3 [ 0 ] ) ;
if ( V_158 )
* V_158 = true ;
return true ;
}
return false ;
}
static int F_173 ( unsigned long V_83 , bool * V_156 , bool V_157 ,
bool * V_158 , T_1 * V_1 )
{
struct V_3 * V_3 [ 1 ] ;
int V_88 = 0 ;
F_174 () ;
if ( V_158 )
* V_158 = V_157 ;
if ( V_156 ) {
F_153 ( & V_12 -> V_47 -> V_138 ) ;
V_88 = F_167 ( V_12 , V_12 -> V_47 ,
V_83 , V_157 , V_3 ) ;
F_156 ( & V_12 -> V_47 -> V_138 ) ;
} else
V_88 = F_175 ( V_83 , 1 , V_157 ,
V_3 ) ;
if ( V_88 != 1 )
return V_88 ;
if ( F_10 ( ! V_157 ) && V_158 ) {
struct V_3 * V_159 [ 1 ] ;
V_88 = F_171 ( V_83 , 1 , 1 , V_159 ) ;
if ( V_88 == 1 ) {
* V_158 = true ;
F_176 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_159 [ 0 ] ;
}
V_88 = 1 ;
}
* V_1 = F_172 ( V_3 [ 0 ] ) ;
return V_88 ;
}
static bool F_177 ( struct V_136 * V_137 , bool V_157 )
{
if ( F_10 ( ! ( V_137 -> V_160 & V_161 ) ) )
return false ;
if ( V_157 && ( F_10 ( ! ( V_137 -> V_160 & V_162 ) ) ) )
return false ;
return true ;
}
static T_1 F_178 ( unsigned long V_83 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
struct V_136 * V_137 ;
T_1 V_1 = 0 ;
int V_88 ;
F_65 ( V_155 && V_156 ) ;
if ( F_170 ( V_83 , V_155 , V_156 , V_157 , V_158 , & V_1 ) )
return V_1 ;
if ( V_155 )
return V_163 ;
V_88 = F_173 ( V_83 , V_156 , V_157 , V_158 , & V_1 ) ;
if ( V_88 == 1 )
return V_1 ;
F_153 ( & V_12 -> V_47 -> V_138 ) ;
if ( V_88 == - V_154 ||
( ! V_156 && F_169 ( V_83 ) ) ) {
V_1 = V_164 ;
goto exit;
}
V_137 = F_179 ( V_12 -> V_47 , V_83 , V_83 + 1 ) ;
if ( V_137 == NULL )
V_1 = V_163 ;
else if ( ( V_137 -> V_160 & V_165 ) ) {
V_1 = ( ( V_83 - V_137 -> V_166 ) >> V_120 ) +
V_137 -> V_167 ;
F_65 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_156 && F_177 ( V_137 , V_157 ) )
* V_156 = true ;
V_1 = V_163 ;
}
exit:
F_156 ( & V_12 -> V_47 -> V_138 ) ;
return V_1 ;
}
static T_1
F_180 ( struct V_84 * V_119 , T_5 V_135 , bool V_155 ,
bool * V_156 , bool V_157 , bool * V_158 )
{
unsigned long V_83 = F_158 ( V_119 , V_135 , NULL , V_157 ) ;
if ( V_83 == V_142 )
return V_168 ;
if ( F_152 ( V_83 ) )
return V_169 ;
if ( V_158 && F_157 ( V_119 ) ) {
* V_158 = false ;
V_158 = NULL ;
}
return F_178 ( V_83 , V_155 , V_156 , V_157 ,
V_158 ) ;
}
static T_1 F_181 ( struct V_19 * V_19 , T_5 V_135 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
struct V_84 * V_119 ;
if ( V_156 )
* V_156 = false ;
V_119 = F_147 ( V_19 , V_135 ) ;
return F_180 ( V_119 , V_135 , V_155 , V_156 , V_157 ,
V_158 ) ;
}
T_1 F_182 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_181 ( V_19 , V_135 , true , NULL , true , NULL ) ;
}
T_1 F_183 ( struct V_19 * V_19 , T_5 V_135 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
return F_181 ( V_19 , V_135 , false , V_156 , V_157 , V_158 ) ;
}
T_1 F_184 ( struct V_19 * V_19 , T_5 V_135 )
{
return F_181 ( V_19 , V_135 , false , NULL , true , NULL ) ;
}
T_1 F_185 ( struct V_19 * V_19 , T_5 V_135 , bool V_157 ,
bool * V_158 )
{
return F_181 ( V_19 , V_135 , false , NULL , V_157 , V_158 ) ;
}
T_1 F_186 ( struct V_84 * V_119 , T_5 V_135 )
{
return F_180 ( V_119 , V_135 , false , NULL , true , NULL ) ;
}
T_1 F_187 ( struct V_84 * V_119 , T_5 V_135 )
{
return F_180 ( V_119 , V_135 , true , NULL , true , NULL ) ;
}
int F_188 ( struct V_19 * V_19 , T_5 V_135 , struct V_3 * * V_170 ,
int V_139 )
{
unsigned long V_83 ;
T_5 V_171 ;
V_83 = F_160 ( F_147 ( V_19 , V_135 ) , V_135 , & V_171 ) ;
if ( F_152 ( V_83 ) )
return - 1 ;
if ( V_171 < V_139 )
return 0 ;
return F_171 ( V_83 , V_139 , 1 , V_170 ) ;
}
static struct V_3 * F_189 ( T_1 V_1 )
{
if ( F_190 ( V_1 ) )
return V_172 ;
if ( F_1 ( V_1 ) ) {
F_191 ( 1 ) ;
return V_172 ;
}
return F_3 ( V_1 ) ;
}
struct V_3 * F_192 ( struct V_19 * V_19 , T_5 V_135 )
{
T_1 V_1 ;
V_1 = F_184 ( V_19 , V_135 ) ;
return F_189 ( V_1 ) ;
}
void F_193 ( struct V_3 * V_3 )
{
F_191 ( F_194 ( V_3 ) ) ;
F_195 ( F_172 ( V_3 ) ) ;
}
void F_195 ( T_1 V_1 )
{
if ( ! F_190 ( V_1 ) && ! F_1 ( V_1 ) )
F_176 ( F_3 ( V_1 ) ) ;
}
void F_196 ( struct V_3 * V_3 )
{
F_191 ( F_194 ( V_3 ) ) ;
F_197 ( F_172 ( V_3 ) ) ;
}
void F_197 ( T_1 V_1 )
{
F_198 ( V_1 ) ;
F_195 ( V_1 ) ;
}
void F_199 ( struct V_3 * V_3 )
{
F_198 ( F_172 ( V_3 ) ) ;
}
void F_198 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_200 ( V_3 ) ;
}
}
void F_201 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_202 ( F_3 ( V_1 ) ) ;
}
void F_203 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_204 ( F_3 ( V_1 ) ) ;
}
static int F_205 ( unsigned long V_145 , int V_173 )
{
if ( V_145 > V_82 - V_173 )
return V_82 - V_173 ;
else
return V_145 ;
}
int F_206 ( struct V_19 * V_19 , T_5 V_135 , void * V_143 , int V_173 ,
int V_145 )
{
int V_35 ;
unsigned long V_83 ;
V_83 = F_162 ( V_19 , V_135 ) ;
if ( F_152 ( V_83 ) )
return - V_133 ;
V_35 = F_163 ( V_143 , ( void V_118 * ) V_83 + V_173 , V_145 ) ;
if ( V_35 )
return - V_133 ;
return 0 ;
}
int F_207 ( struct V_19 * V_19 , T_6 V_174 , void * V_143 , unsigned long V_145 )
{
T_5 V_135 = V_174 >> V_120 ;
int V_175 ;
int V_173 = F_208 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_205 ( V_145 , V_173 ) ) != 0 ) {
V_176 = F_206 ( V_19 , V_135 , V_143 , V_173 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_173 = 0 ;
V_145 -= V_175 ;
V_143 += V_175 ;
++ V_135 ;
}
return 0 ;
}
int F_209 ( struct V_19 * V_19 , T_6 V_174 , void * V_143 ,
unsigned long V_145 )
{
int V_35 ;
unsigned long V_83 ;
T_5 V_135 = V_174 >> V_120 ;
int V_173 = F_208 ( V_174 ) ;
V_83 = F_162 ( V_19 , V_135 ) ;
if ( F_152 ( V_83 ) )
return - V_133 ;
F_210 () ;
V_35 = F_165 ( V_143 , ( void V_118 * ) V_83 + V_173 , V_145 ) ;
F_211 () ;
if ( V_35 )
return - V_133 ;
return 0 ;
}
int F_212 ( struct V_19 * V_19 , T_5 V_135 , const void * V_143 ,
int V_173 , int V_145 )
{
int V_35 ;
unsigned long V_83 ;
V_83 = F_151 ( V_19 , V_135 ) ;
if ( F_152 ( V_83 ) )
return - V_133 ;
V_35 = F_213 ( ( void V_118 * ) V_83 + V_173 , V_143 , V_145 ) ;
if ( V_35 )
return - V_133 ;
F_214 ( V_19 , V_135 ) ;
return 0 ;
}
int F_215 ( struct V_19 * V_19 , T_6 V_174 , const void * V_143 ,
unsigned long V_145 )
{
T_5 V_135 = V_174 >> V_120 ;
int V_175 ;
int V_173 = F_208 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_205 ( V_145 , V_173 ) ) != 0 ) {
V_176 = F_212 ( V_19 , V_135 , V_143 , V_173 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_173 = 0 ;
V_145 -= V_175 ;
V_143 += V_175 ;
++ V_135 ;
}
return 0 ;
}
int F_216 ( struct V_19 * V_19 , struct V_177 * V_178 ,
T_6 V_174 )
{
struct V_61 * V_62 = V_61 ( V_19 ) ;
int V_173 = F_208 ( V_174 ) ;
T_5 V_135 = V_174 >> V_120 ;
V_178 -> V_174 = V_174 ;
V_178 -> V_102 = V_62 -> V_102 ;
V_178 -> V_85 = F_147 ( V_19 , V_135 ) ;
V_178 -> V_144 = F_160 ( V_178 -> V_85 , V_135 , NULL ) ;
if ( ! F_152 ( V_178 -> V_144 ) )
V_178 -> V_144 += V_173 ;
else
return - V_133 ;
return 0 ;
}
int F_217 ( struct V_19 * V_19 , struct V_177 * V_178 ,
void * V_143 , unsigned long V_145 )
{
struct V_61 * V_62 = V_61 ( V_19 ) ;
int V_35 ;
if ( V_62 -> V_102 != V_178 -> V_102 )
F_216 ( V_19 , V_178 , V_178 -> V_174 ) ;
if ( F_152 ( V_178 -> V_144 ) )
return - V_133 ;
V_35 = F_213 ( ( void V_118 * ) V_178 -> V_144 , V_143 , V_145 ) ;
if ( V_35 )
return - V_133 ;
F_218 ( V_19 , V_178 -> V_85 , V_178 -> V_174 >> V_120 ) ;
return 0 ;
}
int F_219 ( struct V_19 * V_19 , struct V_177 * V_178 ,
void * V_143 , unsigned long V_145 )
{
struct V_61 * V_62 = V_61 ( V_19 ) ;
int V_35 ;
if ( V_62 -> V_102 != V_178 -> V_102 )
F_216 ( V_19 , V_178 , V_178 -> V_174 ) ;
if ( F_152 ( V_178 -> V_144 ) )
return - V_133 ;
V_35 = F_164 ( V_143 , ( void V_118 * ) V_178 -> V_144 , V_145 ) ;
if ( V_35 )
return - V_133 ;
return 0 ;
}
int F_220 ( struct V_19 * V_19 , T_5 V_135 , int V_173 , int V_145 )
{
return F_212 ( V_19 , V_135 , ( const void * ) V_179 ,
V_173 , V_145 ) ;
}
int F_221 ( struct V_19 * V_19 , T_6 V_174 , unsigned long V_145 )
{
T_5 V_135 = V_174 >> V_120 ;
int V_175 ;
int V_173 = F_208 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_205 ( V_145 , V_173 ) ) != 0 ) {
V_176 = F_220 ( V_19 , V_135 , V_173 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_173 = 0 ;
V_145 -= V_175 ;
++ V_135 ;
}
return 0 ;
}
void F_218 ( struct V_19 * V_19 , struct V_84 * V_85 ,
T_5 V_135 )
{
if ( V_85 && V_85 -> V_86 ) {
unsigned long V_180 = V_135 - V_85 -> V_111 ;
F_222 ( V_180 , V_85 -> V_86 ) ;
}
}
void F_214 ( struct V_19 * V_19 , T_5 V_135 )
{
struct V_84 * V_85 ;
V_85 = F_147 ( V_19 , V_135 ) ;
F_218 ( V_19 , V_85 , V_135 ) ;
}
void F_223 ( struct V_6 * V_7 )
{
F_224 ( V_181 ) ;
for (; ; ) {
F_225 ( & V_7 -> V_37 , & V_181 , V_182 ) ;
if ( F_226 ( V_7 ) ) {
F_29 ( V_183 , V_7 ) ;
break;
}
if ( F_227 ( V_7 ) )
break;
if ( F_228 ( V_12 ) )
break;
F_229 () ;
}
F_230 ( & V_7 -> V_37 , & V_181 ) ;
}
void F_231 ( struct V_6 * V_7 )
{
int V_22 ;
int V_8 = V_7 -> V_8 ;
T_7 * V_184 ;
V_184 = F_232 ( V_7 ) ;
if ( F_233 ( V_184 ) ) {
F_234 ( V_184 ) ;
++ V_7 -> V_31 . V_185 ;
}
V_22 = F_15 () ;
if ( V_8 != V_22 && ( unsigned ) V_8 < V_186 && F_235 ( V_8 ) )
if ( F_236 ( V_7 ) )
F_237 ( V_8 ) ;
F_18 () ;
}
void F_238 ( struct V_6 * V_7 )
{
if ( ! F_239 () )
return;
F_240 () ;
}
bool F_241 ( struct V_6 * V_187 )
{
struct V_11 * V_11 ;
struct V_146 * V_188 = NULL ;
F_242 () ;
V_11 = F_243 ( V_187 -> V_11 ) ;
if ( V_11 )
V_188 = F_244 ( V_187 -> V_11 , V_14 ) ;
F_245 () ;
if ( ! V_188 )
return false ;
if ( V_188 -> V_108 & V_189 ) {
F_246 ( V_188 ) ;
return false ;
}
if ( F_247 ( V_188 , 1 ) ) {
F_246 ( V_188 ) ;
return true ;
}
F_246 ( V_188 ) ;
return false ;
}
bool F_248 ( struct V_6 * V_7 )
{
bool V_190 ;
V_190 = ! V_7 -> V_191 . V_192 ||
( V_7 -> V_191 . V_192 &&
V_7 -> V_191 . V_193 ) ;
if ( V_7 -> V_191 . V_192 )
F_46 ( V_7 , ! V_7 -> V_191 . V_193 ) ;
return V_190 ;
}
void F_249 ( struct V_6 * V_22 )
{
struct V_19 * V_19 = V_22 -> V_19 ;
struct V_6 * V_7 ;
int V_194 = V_22 -> V_19 -> V_194 ;
int V_195 = 0 ;
int V_196 ;
int V_21 ;
F_45 ( V_22 , true ) ;
for ( V_196 = 0 ; V_196 < 2 && ! V_195 ; V_196 ++ ) {
F_28 (i, vcpu, kvm) {
if ( ! V_196 && V_21 <= V_194 ) {
V_21 = V_194 ;
continue;
} else if ( V_196 && V_21 > V_194 )
break;
if ( V_7 == V_22 )
continue;
if ( F_233 ( & V_7 -> V_37 ) )
continue;
if ( ! F_248 ( V_7 ) )
continue;
if ( F_241 ( V_7 ) ) {
V_19 -> V_194 = V_21 ;
V_195 = 1 ;
break;
}
}
}
F_45 ( V_22 , false ) ;
F_46 ( V_22 , false ) ;
}
static int F_250 ( struct V_136 * V_137 , struct V_197 * V_198 )
{
struct V_6 * V_7 = V_137 -> V_199 -> V_94 ;
struct V_3 * V_3 ;
if ( V_198 -> V_200 == 0 )
V_3 = F_251 ( V_7 -> V_42 ) ;
#ifdef F_252
else if ( V_198 -> V_200 == V_201 )
V_3 = F_251 ( V_7 -> V_127 . V_202 ) ;
#endif
#ifdef F_253
else if ( V_198 -> V_200 == F_253 )
V_3 = F_251 ( V_7 -> V_19 -> V_203 ) ;
#endif
else
return F_254 ( V_7 , V_198 ) ;
F_204 ( V_3 ) ;
V_198 -> V_3 = V_3 ;
return 0 ;
}
static int F_255 ( struct V_92 * V_92 , struct V_136 * V_137 )
{
V_137 -> V_204 = & V_205 ;
return 0 ;
}
static int F_256 ( struct V_91 * V_91 , struct V_92 * V_93 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
F_116 ( V_7 -> V_19 ) ;
return 0 ;
}
static int F_257 ( struct V_6 * V_7 )
{
return F_258 ( L_1 , & V_206 , V_7 , V_207 ) ;
}
static int F_259 ( struct V_19 * V_19 , T_4 V_34 )
{
int V_35 ;
struct V_6 * V_7 , * V_208 ;
V_7 = F_260 ( V_19 , V_34 ) ;
if ( F_261 ( V_7 ) )
return F_262 ( V_7 ) ;
F_263 ( & V_7 -> V_17 , & V_209 ) ;
V_35 = F_264 ( V_7 ) ;
if ( V_35 )
goto V_210;
F_141 ( & V_19 -> V_75 ) ;
if ( ! F_265 ( V_7 ) ) {
V_35 = - V_109 ;
goto V_211;
}
if ( F_266 ( & V_19 -> V_212 ) == V_213 ) {
V_35 = - V_109 ;
goto V_211;
}
F_28 (r, v, kvm)
if ( V_208 -> V_36 == V_34 ) {
V_35 = - V_123 ;
goto V_211;
}
F_65 ( V_19 -> V_214 [ F_266 ( & V_19 -> V_212 ) ] ) ;
F_115 ( V_19 ) ;
V_35 = F_257 ( V_7 ) ;
if ( V_35 < 0 ) {
F_116 ( V_19 ) ;
goto V_211;
}
V_19 -> V_214 [ F_266 ( & V_19 -> V_212 ) ] = V_7 ;
F_64 () ;
F_85 ( & V_19 -> V_212 ) ;
F_24 ( & V_19 -> V_75 ) ;
return V_35 ;
V_211:
F_24 ( & V_19 -> V_75 ) ;
V_210:
F_267 ( V_7 ) ;
return V_35 ;
}
static int F_268 ( struct V_6 * V_7 , T_8 * V_215 )
{
if ( V_215 ) {
F_269 ( V_215 , F_270 ( V_216 ) | F_270 ( V_217 ) ) ;
V_7 -> V_218 = 1 ;
V_7 -> V_215 = * V_215 ;
} else
V_7 -> V_218 = 0 ;
return 0 ;
}
static long F_271 ( struct V_92 * V_93 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
void V_118 * V_221 = ( void V_118 * ) V_220 ;
int V_35 ;
struct V_222 * V_223 = NULL ;
struct V_224 * V_224 = NULL ;
if ( V_7 -> V_19 -> V_47 != V_12 -> V_47 )
return - V_225 ;
#if F_111 ( F_121 ) || F_111 ( V_226 )
if ( V_219 == V_227 || V_219 == V_228 )
return F_272 ( V_93 , V_219 , V_220 ) ;
#endif
V_35 = F_8 ( V_7 ) ;
if ( V_35 )
return V_35 ;
switch ( V_219 ) {
case V_229 :
V_35 = - V_109 ;
if ( V_220 )
goto V_113;
V_35 = F_273 ( V_7 , V_7 -> V_42 ) ;
F_274 ( V_7 -> V_42 -> V_230 , V_35 ) ;
break;
case V_231 : {
struct V_232 * V_232 ;
V_35 = - V_40 ;
V_232 = F_82 ( sizeof( struct V_232 ) , V_38 ) ;
if ( ! V_232 )
goto V_113;
V_35 = F_275 ( V_7 , V_232 ) ;
if ( V_35 )
goto V_233;
V_35 = - V_133 ;
if ( F_144 ( V_221 , V_232 , sizeof( struct V_232 ) ) )
goto V_233;
V_35 = 0 ;
V_233:
F_93 ( V_232 ) ;
break;
}
case V_234 : {
struct V_232 * V_232 ;
V_35 = - V_40 ;
V_232 = F_276 ( V_221 , sizeof( * V_232 ) ) ;
if ( F_261 ( V_232 ) ) {
V_35 = F_262 ( V_232 ) ;
goto V_113;
}
V_35 = F_277 ( V_7 , V_232 ) ;
if ( V_35 )
goto V_235;
V_35 = 0 ;
V_235:
F_93 ( V_232 ) ;
break;
}
case V_236 : {
V_224 = F_82 ( sizeof( struct V_224 ) , V_38 ) ;
V_35 = - V_40 ;
if ( ! V_224 )
goto V_113;
V_35 = F_278 ( V_7 , V_224 ) ;
if ( V_35 )
goto V_113;
V_35 = - V_133 ;
if ( F_144 ( V_221 , V_224 , sizeof( struct V_224 ) ) )
goto V_113;
V_35 = 0 ;
break;
}
case V_237 : {
V_224 = F_276 ( V_221 , sizeof( * V_224 ) ) ;
if ( F_261 ( V_224 ) ) {
V_35 = F_262 ( V_224 ) ;
goto V_113;
}
V_35 = F_279 ( V_7 , V_224 ) ;
if ( V_35 )
goto V_113;
V_35 = 0 ;
break;
}
case V_238 : {
struct V_239 V_240 ;
V_35 = F_280 ( V_7 , & V_240 ) ;
if ( V_35 )
goto V_113;
V_35 = - V_133 ;
if ( F_144 ( V_221 , & V_240 , sizeof V_240 ) )
goto V_113;
V_35 = 0 ;
break;
}
case V_241 : {
struct V_239 V_240 ;
V_35 = - V_133 ;
if ( F_281 ( & V_240 , V_221 , sizeof V_240 ) )
goto V_113;
V_35 = F_282 ( V_7 , & V_240 ) ;
if ( V_35 )
goto V_113;
V_35 = 0 ;
break;
}
case V_242 : {
struct V_243 V_244 ;
V_35 = - V_133 ;
if ( F_281 ( & V_244 , V_221 , sizeof V_244 ) )
goto V_113;
V_35 = F_283 ( V_7 , & V_244 ) ;
if ( V_35 )
goto V_113;
V_35 = - V_133 ;
if ( F_144 ( V_221 , & V_244 , sizeof V_244 ) )
goto V_113;
V_35 = 0 ;
break;
}
case V_245 : {
struct V_246 V_247 ;
V_35 = - V_133 ;
if ( F_281 ( & V_247 , V_221 , sizeof V_247 ) )
goto V_113;
V_35 = F_284 ( V_7 , & V_247 ) ;
if ( V_35 )
goto V_113;
V_35 = 0 ;
break;
}
case V_248 : {
struct V_249 V_118 * V_250 = V_221 ;
struct V_249 V_251 ;
T_8 V_215 , * V_252 ;
V_252 = NULL ;
if ( V_221 ) {
V_35 = - V_133 ;
if ( F_281 ( & V_251 , V_221 ,
sizeof V_251 ) )
goto V_113;
V_35 = - V_109 ;
if ( V_251 . V_145 != sizeof V_215 )
goto V_113;
V_35 = - V_133 ;
if ( F_281 ( & V_215 , V_250 -> V_215 ,
sizeof V_215 ) )
goto V_113;
V_252 = & V_215 ;
}
V_35 = F_268 ( V_7 , V_252 ) ;
break;
}
case V_253 : {
V_223 = F_82 ( sizeof( struct V_222 ) , V_38 ) ;
V_35 = - V_40 ;
if ( ! V_223 )
goto V_113;
V_35 = F_285 ( V_7 , V_223 ) ;
if ( V_35 )
goto V_113;
V_35 = - V_133 ;
if ( F_144 ( V_221 , V_223 , sizeof( struct V_222 ) ) )
goto V_113;
V_35 = 0 ;
break;
}
case V_254 : {
V_223 = F_276 ( V_221 , sizeof( * V_223 ) ) ;
if ( F_261 ( V_223 ) ) {
V_35 = F_262 ( V_223 ) ;
goto V_113;
}
V_35 = F_286 ( V_7 , V_223 ) ;
if ( V_35 )
goto V_113;
V_35 = 0 ;
break;
}
default:
V_35 = F_272 ( V_93 , V_219 , V_220 ) ;
}
V_113:
F_19 ( V_7 ) ;
F_93 ( V_223 ) ;
F_93 ( V_224 ) ;
return V_35 ;
}
static long F_287 ( struct V_92 * V_93 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
void V_118 * V_221 = F_288 ( V_220 ) ;
int V_35 ;
if ( V_7 -> V_19 -> V_47 != V_12 -> V_47 )
return - V_225 ;
switch ( V_219 ) {
case V_248 : {
struct V_249 V_118 * V_250 = V_221 ;
struct V_249 V_251 ;
T_9 V_255 ;
T_8 V_215 ;
if ( V_221 ) {
V_35 = - V_133 ;
if ( F_281 ( & V_251 , V_221 ,
sizeof V_251 ) )
goto V_113;
V_35 = - V_109 ;
if ( V_251 . V_145 != sizeof V_255 )
goto V_113;
V_35 = - V_133 ;
if ( F_281 ( & V_255 , V_250 -> V_215 ,
sizeof V_255 ) )
goto V_113;
F_289 ( & V_215 , & V_255 ) ;
V_35 = F_268 ( V_7 , & V_215 ) ;
} else
V_35 = F_268 ( V_7 , NULL ) ;
break;
}
default:
V_35 = F_271 ( V_93 , V_219 , V_220 ) ;
}
V_113:
return V_35 ;
}
static long F_290 ( struct V_92 * V_93 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_19 * V_19 = V_93 -> V_94 ;
void V_118 * V_221 = ( void V_118 * ) V_220 ;
int V_35 ;
if ( V_19 -> V_47 != V_12 -> V_47 )
return - V_225 ;
switch ( V_219 ) {
case V_256 :
V_35 = F_259 ( V_19 , V_220 ) ;
if ( V_35 < 0 )
goto V_113;
break;
case V_257 : {
struct V_103 V_258 ;
V_35 = - V_133 ;
if ( F_281 ( & V_258 , V_221 ,
sizeof V_258 ) )
goto V_113;
V_35 = F_142 ( V_19 , & V_258 , 1 ) ;
if ( V_35 )
goto V_113;
break;
}
case V_259 : {
struct V_128 log ;
V_35 = - V_133 ;
if ( F_281 ( & log , V_221 , sizeof log ) )
goto V_113;
V_35 = F_291 ( V_19 , & log ) ;
if ( V_35 )
goto V_113;
break;
}
#ifdef F_253
case V_260 : {
struct V_261 V_262 ;
V_35 = - V_133 ;
if ( F_281 ( & V_262 , V_221 , sizeof V_262 ) )
goto V_113;
V_35 = F_292 ( V_19 , & V_262 ) ;
if ( V_35 )
goto V_113;
V_35 = 0 ;
break;
}
case V_263 : {
struct V_261 V_262 ;
V_35 = - V_133 ;
if ( F_281 ( & V_262 , V_221 , sizeof V_262 ) )
goto V_113;
V_35 = F_293 ( V_19 , & V_262 ) ;
if ( V_35 )
goto V_113;
V_35 = 0 ;
break;
}
#endif
case V_264 : {
struct V_265 V_143 ;
V_35 = - V_133 ;
if ( F_281 ( & V_143 , V_221 , sizeof V_143 ) )
goto V_113;
V_35 = V_265 ( V_19 , & V_143 ) ;
break;
}
case V_266 : {
struct V_267 V_143 ;
V_35 = - V_133 ;
if ( F_281 ( & V_143 , V_221 , sizeof V_143 ) )
goto V_113;
V_35 = V_267 ( V_19 , & V_143 ) ;
break;
}
#ifdef F_294
case V_268 :
V_35 = 0 ;
F_141 ( & V_19 -> V_75 ) ;
if ( F_266 ( & V_19 -> V_212 ) != 0 )
V_35 = - V_269 ;
else
V_19 -> V_270 = V_220 ;
F_24 ( & V_19 -> V_75 ) ;
break;
#endif
#ifdef F_295
case V_271 : {
struct V_272 V_273 ;
V_35 = - V_133 ;
if ( F_281 ( & V_273 , V_221 , sizeof V_273 ) )
goto V_113;
V_35 = F_296 ( V_19 , & V_273 ) ;
break;
}
#endif
#ifdef F_297
case V_274 :
case V_275 : {
struct V_276 V_277 ;
V_35 = - V_133 ;
if ( F_281 ( & V_277 , V_221 , sizeof V_277 ) )
goto V_113;
V_35 = F_298 ( V_19 , & V_277 ) ;
if ( V_35 )
goto V_113;
V_35 = - V_133 ;
if ( V_219 == V_274 ) {
if ( F_144 ( V_221 , & V_277 , sizeof V_277 ) )
goto V_113;
}
V_35 = 0 ;
break;
}
#endif
default:
V_35 = F_299 ( V_93 , V_219 , V_220 ) ;
if ( V_35 == - V_278 )
V_35 = F_300 ( V_19 , V_219 , V_220 ) ;
}
V_113:
return V_35 ;
}
static long F_301 ( struct V_92 * V_93 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_19 * V_19 = V_93 -> V_94 ;
int V_35 ;
if ( V_19 -> V_47 != V_12 -> V_47 )
return - V_225 ;
switch ( V_219 ) {
case V_259 : {
struct V_279 V_280 ;
struct V_128 log ;
V_35 = - V_133 ;
if ( F_281 ( & V_280 , ( void V_118 * ) V_220 ,
sizeof( V_280 ) ) )
goto V_113;
log . V_119 = V_280 . V_119 ;
log . V_281 = V_280 . V_281 ;
log . V_282 = V_280 . V_282 ;
log . V_86 = F_288 ( V_280 . V_86 ) ;
V_35 = F_291 ( V_19 , & log ) ;
if ( V_35 )
goto V_113;
break;
}
default:
V_35 = F_290 ( V_93 , V_219 , V_220 ) ;
}
V_113:
return V_35 ;
}
static int F_302 ( struct V_136 * V_137 , struct V_197 * V_198 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_83 ;
int V_88 ;
T_5 V_135 = V_198 -> V_200 ;
struct V_19 * V_19 = V_137 -> V_199 -> V_94 ;
V_83 = F_151 ( V_19 , V_135 ) ;
if ( F_152 ( V_83 ) )
return V_283 ;
V_88 = F_303 ( V_12 , V_12 -> V_47 , V_83 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_88 != 1 ) )
return V_283 ;
V_198 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_304 ( struct V_92 * V_92 , struct V_136 * V_137 )
{
V_137 -> V_204 = & V_284 ;
return 0 ;
}
static int F_305 ( unsigned long type )
{
int V_35 ;
struct V_19 * V_19 ;
V_19 = F_75 ( type ) ;
if ( F_261 ( V_19 ) )
return F_262 ( V_19 ) ;
#ifdef F_253
V_35 = F_306 ( V_19 ) ;
if ( V_35 < 0 ) {
F_116 ( V_19 ) ;
return V_35 ;
}
#endif
V_35 = F_258 ( L_2 , & V_285 , V_19 , V_207 ) ;
if ( V_35 < 0 )
F_116 ( V_19 ) ;
return V_35 ;
}
static long F_307 ( long V_220 )
{
switch ( V_220 ) {
case V_286 :
case V_287 :
case V_288 :
#ifdef F_294
case V_289 :
#endif
case V_290 :
#ifdef F_295
case V_291 :
#endif
return 1 ;
#ifdef F_308
case F_308 :
return V_292 ;
#endif
default:
break;
}
return F_309 ( V_220 ) ;
}
static long F_310 ( struct V_92 * V_93 ,
unsigned int V_219 , unsigned long V_220 )
{
long V_35 = - V_109 ;
switch ( V_219 ) {
case V_293 :
V_35 = - V_109 ;
if ( V_220 )
goto V_113;
V_35 = V_294 ;
break;
case V_295 :
V_35 = F_305 ( V_220 ) ;
break;
case V_296 :
V_35 = F_307 ( V_220 ) ;
break;
case V_297 :
V_35 = - V_109 ;
if ( V_220 )
goto V_113;
V_35 = V_82 ;
#ifdef F_252
V_35 += V_82 ;
#endif
#ifdef F_253
V_35 += V_82 ;
#endif
break;
case V_298 :
case V_299 :
case V_300 :
V_35 = - V_301 ;
break;
default:
return F_311 ( V_93 , V_219 , V_220 ) ;
}
V_113:
return V_35 ;
}
static void F_312 ( void * V_302 )
{
int V_8 = F_313 () ;
int V_35 ;
if ( F_314 ( V_8 , V_303 ) )
return;
F_32 ( V_8 , V_303 ) ;
V_35 = F_315 ( NULL ) ;
if ( V_35 ) {
F_316 ( V_8 , V_303 ) ;
F_85 ( & V_304 ) ;
F_317 ( V_305 L_3
L_4 , V_8 ) ;
}
}
static void F_318 ( void * V_302 )
{
F_88 ( & V_79 ) ;
F_312 ( V_302 ) ;
F_90 ( & V_79 ) ;
}
static void F_319 ( void * V_302 )
{
int V_8 = F_313 () ;
if ( ! F_314 ( V_8 , V_303 ) )
return;
F_316 ( V_8 , V_303 ) ;
F_320 ( NULL ) ;
}
static void F_321 ( void * V_302 )
{
F_88 ( & V_79 ) ;
F_319 ( V_302 ) ;
F_90 ( & V_79 ) ;
}
static void F_322 ( void )
{
F_65 ( ! V_306 ) ;
V_306 -- ;
if ( ! V_306 )
F_323 ( F_319 , NULL , 1 ) ;
}
static void F_92 ( void )
{
F_88 ( & V_79 ) ;
F_322 () ;
F_90 ( & V_79 ) ;
}
static int F_79 ( void )
{
int V_35 = 0 ;
F_88 ( & V_79 ) ;
V_306 ++ ;
if ( V_306 == 1 ) {
F_87 ( & V_304 , 0 ) ;
F_323 ( F_312 , NULL , 1 ) ;
if ( F_266 ( & V_304 ) ) {
F_322 () ;
V_35 = - V_269 ;
}
}
F_90 ( & V_79 ) ;
return V_35 ;
}
static int F_324 ( struct V_307 * V_308 , unsigned long V_309 ,
void * V_208 )
{
int V_8 = ( long ) V_208 ;
if ( ! V_306 )
return V_310 ;
V_309 &= ~ V_311 ;
switch ( V_309 ) {
case V_312 :
F_317 ( V_305 L_5 ,
V_8 ) ;
F_321 ( NULL ) ;
break;
case V_313 :
F_317 ( V_305 L_6 ,
V_8 ) ;
F_318 ( NULL ) ;
break;
}
return V_310 ;
}
T_10 void F_325 ( void )
{
F_326 () ;
}
static int F_327 ( struct V_307 * V_308 , unsigned long V_309 ,
void * V_208 )
{
F_317 ( V_305 L_7 ) ;
V_314 = true ;
F_323 ( F_319 , NULL , 1 ) ;
return V_310 ;
}
static void F_109 ( struct V_72 * V_315 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_315 -> V_316 ; V_21 ++ ) {
struct V_317 * V_318 = V_315 -> V_319 [ V_21 ] . V_320 ;
F_328 ( V_318 ) ;
}
F_93 ( V_315 ) ;
}
int F_329 ( const void * V_321 , const void * V_322 )
{
const struct V_323 * V_324 = V_321 ;
const struct V_323 * V_325 = V_322 ;
if ( V_324 -> V_83 < V_325 -> V_83 )
return - 1 ;
if ( V_324 -> V_83 + V_324 -> V_145 > V_325 -> V_83 + V_325 -> V_145 )
return 1 ;
return 0 ;
}
int F_330 ( struct V_72 * V_315 , struct V_317 * V_320 ,
T_6 V_83 , int V_145 )
{
V_315 -> V_319 [ V_315 -> V_316 ++ ] = (struct V_323 ) {
. V_83 = V_83 ,
. V_145 = V_145 ,
. V_320 = V_320 ,
} ;
F_125 ( V_315 -> V_319 , V_315 -> V_316 , sizeof( struct V_323 ) ,
F_329 , NULL ) ;
return 0 ;
}
int F_331 ( struct V_72 * V_315 ,
T_6 V_83 , int V_145 )
{
struct V_323 * V_319 , V_326 ;
int V_327 ;
V_326 = (struct V_323 ) {
. V_83 = V_83 ,
. V_145 = V_145 ,
} ;
V_319 = bsearch ( & V_326 , V_315 -> V_319 , V_315 -> V_316 ,
sizeof( struct V_323 ) , F_329 ) ;
if ( V_319 == NULL )
return - V_132 ;
V_327 = V_319 - V_315 -> V_319 ;
while ( V_327 > 0 && F_329 ( & V_326 , & V_315 -> V_319 [ V_327 - 1 ] ) == 0 )
V_327 -- ;
return V_327 ;
}
int F_332 ( struct V_19 * V_19 , enum V_328 V_329 , T_6 V_83 ,
int V_145 , const void * V_309 )
{
int V_50 ;
struct V_72 * V_315 ;
struct V_323 V_319 ;
V_319 = (struct V_323 ) {
. V_83 = V_83 ,
. V_145 = V_145 ,
} ;
V_315 = F_333 ( V_19 -> V_71 [ V_329 ] , & V_19 -> V_51 ) ;
V_50 = F_331 ( V_315 , V_83 , V_145 ) ;
if ( V_50 < 0 )
return - V_301 ;
while ( V_50 < V_315 -> V_316 &&
F_329 ( & V_319 , & V_315 -> V_319 [ V_50 ] ) == 0 ) {
if ( ! F_334 ( V_315 -> V_319 [ V_50 ] . V_320 , V_83 , V_145 , V_309 ) )
return 0 ;
V_50 ++ ;
}
return - V_301 ;
}
int F_335 ( struct V_19 * V_19 , enum V_328 V_329 , T_6 V_83 ,
int V_145 , void * V_309 )
{
int V_50 ;
struct V_72 * V_315 ;
struct V_323 V_319 ;
V_319 = (struct V_323 ) {
. V_83 = V_83 ,
. V_145 = V_145 ,
} ;
V_315 = F_333 ( V_19 -> V_71 [ V_329 ] , & V_19 -> V_51 ) ;
V_50 = F_331 ( V_315 , V_83 , V_145 ) ;
if ( V_50 < 0 )
return - V_301 ;
while ( V_50 < V_315 -> V_316 &&
F_329 ( & V_319 , & V_315 -> V_319 [ V_50 ] ) == 0 ) {
if ( ! F_336 ( V_315 -> V_319 [ V_50 ] . V_320 , V_83 , V_145 , V_309 ) )
return 0 ;
V_50 ++ ;
}
return - V_301 ;
}
int F_337 ( struct V_19 * V_19 , enum V_328 V_329 , T_6 V_83 ,
int V_145 , struct V_317 * V_320 )
{
struct V_72 * V_330 , * V_315 ;
V_315 = V_19 -> V_71 [ V_329 ] ;
if ( V_315 -> V_316 > V_331 - 1 )
return - V_332 ;
V_330 = F_82 ( sizeof( * V_315 ) + ( ( V_315 -> V_316 + 1 ) *
sizeof( struct V_323 ) ) , V_38 ) ;
if ( ! V_330 )
return - V_40 ;
memcpy ( V_330 , V_315 , sizeof( * V_315 ) + ( V_315 -> V_316 *
sizeof( struct V_323 ) ) ) ;
F_330 ( V_330 , V_320 , V_83 , V_145 ) ;
F_12 ( V_19 -> V_71 [ V_329 ] , V_330 ) ;
F_134 ( & V_19 -> V_51 ) ;
F_93 ( V_315 ) ;
return 0 ;
}
int F_338 ( struct V_19 * V_19 , enum V_328 V_329 ,
struct V_317 * V_320 )
{
int V_21 , V_35 ;
struct V_72 * V_330 , * V_315 ;
V_315 = V_19 -> V_71 [ V_329 ] ;
V_35 = - V_132 ;
for ( V_21 = 0 ; V_21 < V_315 -> V_316 ; V_21 ++ )
if ( V_315 -> V_319 [ V_21 ] . V_320 == V_320 ) {
V_35 = 0 ;
break;
}
if ( V_35 )
return V_35 ;
V_330 = F_82 ( sizeof( * V_315 ) + ( ( V_315 -> V_316 - 1 ) *
sizeof( struct V_323 ) ) , V_38 ) ;
if ( ! V_330 )
return - V_40 ;
memcpy ( V_330 , V_315 , sizeof( * V_315 ) + V_21 * sizeof( struct V_323 ) ) ;
V_330 -> V_316 -- ;
memcpy ( V_330 -> V_319 + V_21 , V_315 -> V_319 + V_21 + 1 ,
( V_330 -> V_316 - V_21 ) * sizeof( struct V_323 ) ) ;
F_12 ( V_19 -> V_71 [ V_329 ] , V_330 ) ;
F_134 ( & V_19 -> V_51 ) ;
F_93 ( V_315 ) ;
return V_35 ;
}
static int F_339 ( void * V_333 , T_11 * V_309 )
{
unsigned V_173 = ( long ) V_333 ;
struct V_19 * V_19 ;
* V_309 = 0 ;
F_88 ( & V_79 ) ;
F_340 ( V_19 , & V_80 , V_80 )
* V_309 += * ( T_4 * ) ( ( void * ) V_19 + V_173 ) ;
F_90 ( & V_79 ) ;
return 0 ;
}
static int F_341 ( void * V_333 , T_11 * V_309 )
{
unsigned V_173 = ( long ) V_333 ;
struct V_19 * V_19 ;
struct V_6 * V_7 ;
int V_21 ;
* V_309 = 0 ;
F_88 ( & V_79 ) ;
F_340 (kvm, &vm_list, vm_list)
F_28 ( V_21 , V_7 , V_19 )
* V_309 += * ( T_4 * ) ( ( void * ) V_7 + V_173 ) ;
F_90 ( & V_79 ) ;
return 0 ;
}
static int F_342 ( void )
{
int V_35 = - V_133 ;
struct V_334 * V_252 ;
V_335 = F_343 ( L_8 , NULL ) ;
if ( V_335 == NULL )
goto V_113;
for ( V_252 = V_336 ; V_252 -> V_337 ; ++ V_252 ) {
V_252 -> V_338 = F_344 ( V_252 -> V_337 , 0444 , V_335 ,
( void * ) ( long ) V_252 -> V_173 ,
V_339 [ V_252 -> V_340 ] ) ;
if ( V_252 -> V_338 == NULL )
goto V_341;
}
return 0 ;
V_341:
F_345 ( V_335 ) ;
V_113:
return V_35 ;
}
static void F_346 ( void )
{
struct V_334 * V_252 ;
for ( V_252 = V_336 ; V_252 -> V_337 ; ++ V_252 )
F_347 ( V_252 -> V_338 ) ;
F_347 ( V_335 ) ;
}
static int F_348 ( void )
{
if ( V_306 )
F_319 ( NULL ) ;
return 0 ;
}
static void F_349 ( void )
{
if ( V_306 ) {
F_191 ( F_350 ( & V_79 ) ) ;
F_312 ( NULL ) ;
}
}
static inline
struct V_6 * F_351 ( struct V_17 * V_342 )
{
return F_52 ( V_342 , struct V_6 , V_17 ) ;
}
static void F_352 ( struct V_17 * V_342 , int V_8 )
{
struct V_6 * V_7 = F_351 ( V_342 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_353 ( struct V_17 * V_342 ,
struct V_146 * V_343 )
{
struct V_6 * V_7 = F_351 ( V_342 ) ;
F_21 ( V_7 ) ;
}
int F_354 ( void * V_344 , unsigned V_345 , unsigned V_346 ,
struct V_347 * V_347 )
{
int V_35 ;
int V_8 ;
V_35 = F_355 ( V_344 ) ;
if ( V_35 )
goto V_348;
if ( ! F_27 ( & V_303 , V_38 ) ) {
V_35 = - V_40 ;
goto V_349;
}
V_35 = F_356 () ;
if ( V_35 < 0 )
goto V_350;
F_357 (cpu) {
F_358 ( V_8 ,
V_351 ,
& V_35 , 1 ) ;
if ( V_35 < 0 )
goto V_352;
}
V_35 = F_359 ( & V_353 ) ;
if ( V_35 )
goto V_354;
F_360 ( & V_355 ) ;
if ( ! V_346 )
V_346 = F_361 ( struct V_6 ) ;
V_356 = F_362 ( L_9 , V_345 , V_346 ,
0 , NULL ) ;
if ( ! V_356 ) {
V_35 = - V_40 ;
goto V_357;
}
V_35 = F_363 () ;
if ( V_35 )
goto V_122;
V_358 . V_359 = V_347 ;
V_285 . V_359 = V_347 ;
V_206 . V_359 = V_347 ;
V_35 = F_364 ( & V_360 ) ;
if ( V_35 ) {
F_317 ( V_361 L_10 ) ;
goto V_362;
}
F_365 ( & V_363 ) ;
V_209 . V_364 = F_352 ;
V_209 . V_365 = F_353 ;
V_35 = F_342 () ;
if ( V_35 ) {
F_317 ( V_361 L_11 ) ;
goto V_366;
}
return 0 ;
V_366:
F_366 ( & V_363 ) ;
V_362:
F_367 () ;
V_122:
F_368 ( V_356 ) ;
V_357:
F_369 ( & V_355 ) ;
F_370 ( & V_353 ) ;
V_354:
V_352:
F_371 () ;
V_350:
F_35 ( V_303 ) ;
V_349:
F_372 () ;
V_348:
return V_35 ;
}
void F_373 ( void )
{
F_346 () ;
F_374 ( & V_360 ) ;
F_368 ( V_356 ) ;
F_367 () ;
F_366 ( & V_363 ) ;
F_369 ( & V_355 ) ;
F_370 ( & V_353 ) ;
F_323 ( F_319 , NULL , 1 ) ;
F_371 () ;
F_372 () ;
F_35 ( V_303 ) ;
}
