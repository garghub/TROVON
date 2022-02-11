inline int F_1 ( T_1 V_1 )
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
void F_8 ( struct V_6 * V_7 )
{
int V_8 ;
F_9 ( & V_7 -> V_9 ) ;
if ( F_10 ( V_7 -> V_10 != V_11 -> V_12 [ V_13 ] . V_10 ) ) {
struct V_10 * V_14 = V_7 -> V_10 ;
struct V_10 * V_15 = F_11 ( V_11 , V_13 ) ;
F_12 ( V_7 -> V_10 , V_15 ) ;
F_13 () ;
F_14 ( V_14 ) ;
}
V_8 = F_15 () ;
F_16 ( & V_7 -> V_16 ) ;
F_17 ( V_7 , V_8 ) ;
F_18 () ;
}
void F_19 ( struct V_6 * V_7 )
{
F_20 () ;
F_21 ( V_7 ) ;
F_22 ( & V_7 -> V_16 ) ;
F_23 () ;
F_24 ( & V_7 -> V_9 ) ;
}
static void F_25 ( void * V_17 )
{
}
static bool F_26 ( struct V_18 * V_18 , unsigned int V_19 )
{
int V_20 , V_8 , V_21 ;
T_2 V_22 ;
bool V_23 = true ;
struct V_6 * V_7 ;
F_27 ( & V_22 , V_24 ) ;
V_21 = F_15 () ;
F_28 (i, vcpu, kvm) {
F_29 ( V_19 , V_7 ) ;
V_8 = V_7 -> V_8 ;
F_30 () ;
if ( V_22 != NULL && V_8 != - 1 && V_8 != V_21 &&
F_31 ( V_7 ) != V_25 )
F_32 ( V_8 , V_22 ) ;
}
if ( F_10 ( V_22 == NULL ) )
F_33 ( V_26 , F_25 , NULL , 1 ) ;
else if ( ! F_34 ( V_22 ) )
F_33 ( V_22 , F_25 , NULL , 1 ) ;
else
V_23 = false ;
F_18 () ;
F_35 ( V_22 ) ;
return V_23 ;
}
void F_36 ( struct V_18 * V_18 )
{
long V_27 = V_18 -> V_28 ;
F_30 () ;
if ( F_26 ( V_18 , V_29 ) )
++ V_18 -> V_30 . V_31 ;
F_37 ( & V_18 -> V_28 , V_27 , 0 ) ;
}
void F_38 ( struct V_18 * V_18 )
{
F_26 ( V_18 , V_32 ) ;
}
int F_39 ( struct V_6 * V_7 , struct V_18 * V_18 , unsigned V_33 )
{
struct V_3 * V_3 ;
int V_34 ;
F_40 ( & V_7 -> V_9 ) ;
V_7 -> V_8 = - 1 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_35 = V_33 ;
V_7 -> V_10 = NULL ;
F_41 ( & V_7 -> V_36 ) ;
F_42 ( V_7 ) ;
V_3 = F_43 ( V_37 | V_38 ) ;
if ( ! V_3 ) {
V_34 = - V_39 ;
goto V_40;
}
V_7 -> V_41 = F_44 ( V_3 ) ;
V_34 = F_45 ( V_7 ) ;
if ( V_34 < 0 )
goto V_42;
return 0 ;
V_42:
F_46 ( ( unsigned long ) V_7 -> V_41 ) ;
V_40:
return V_34 ;
}
void F_47 ( struct V_6 * V_7 )
{
F_14 ( V_7 -> V_10 ) ;
F_48 ( V_7 ) ;
F_46 ( ( unsigned long ) V_7 -> V_41 ) ;
}
static inline struct V_18 * F_49 ( struct V_43 * V_44 )
{
return F_50 ( V_44 , struct V_18 , V_43 ) ;
}
static void F_51 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_48 , V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_18 -> V_52 ++ ;
V_48 = F_54 ( V_18 , V_47 ) | V_18 -> V_28 ;
if ( V_48 )
F_36 ( V_18 ) ;
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
}
static void F_57 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 ,
T_3 V_53 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_18 -> V_52 ++ ;
F_58 ( V_18 , V_47 , V_53 ) ;
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
}
static void F_59 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_54 ,
unsigned long V_55 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_48 = 0 , V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_18 -> V_56 ++ ;
for (; V_54 < V_55 ; V_54 += V_57 )
V_48 |= F_54 ( V_18 , V_54 ) ;
V_48 |= V_18 -> V_28 ;
if ( V_48 )
F_36 ( V_18 ) ;
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
}
static void F_60 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_54 ,
unsigned long V_55 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_18 -> V_52 ++ ;
F_61 () ;
V_18 -> V_56 -- ;
F_55 ( & V_18 -> V_51 ) ;
F_62 ( V_18 -> V_56 < 0 ) ;
}
static int F_63 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_58 , V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_58 = F_64 ( V_18 , V_47 ) ;
if ( V_58 )
F_36 ( V_18 ) ;
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
return V_58 ;
}
static int F_65 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_58 , V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_58 = F_66 ( V_18 , V_47 ) ;
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
return V_58 ;
}
static void F_67 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_68 ( V_18 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
}
static int F_69 ( struct V_18 * V_18 )
{
V_18 -> V_43 . V_59 = & V_60 ;
return F_70 ( & V_18 -> V_43 , V_11 -> V_46 ) ;
}
static int F_69 ( struct V_18 * V_18 )
{
return 0 ;
}
static void F_71 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_61 * V_62 = V_18 -> V_63 ;
for ( V_20 = 0 ; V_20 < V_64 ; V_20 ++ )
V_62 -> V_65 [ V_20 ] = V_62 -> V_63 [ V_20 ] . V_33 = V_20 ;
}
static struct V_18 * F_72 ( unsigned long type )
{
int V_34 , V_20 ;
struct V_18 * V_18 = F_73 () ;
if ( ! V_18 )
return F_74 ( - V_39 ) ;
V_34 = F_75 ( V_18 , type ) ;
if ( V_34 )
goto V_66;
V_34 = F_76 () ;
if ( V_34 )
goto V_66;
#ifdef F_77
F_78 ( & V_18 -> V_67 ) ;
F_78 ( & V_18 -> V_68 ) ;
#endif
V_34 = - V_39 ;
V_18 -> V_63 = F_79 ( sizeof( struct V_61 ) , V_37 ) ;
if ( ! V_18 -> V_63 )
goto V_69;
F_71 ( V_18 ) ;
if ( F_80 ( & V_18 -> V_50 ) )
goto V_69;
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ ) {
V_18 -> V_71 [ V_20 ] = F_79 ( sizeof( struct V_72 ) ,
V_37 ) ;
if ( ! V_18 -> V_71 [ V_20 ] )
goto V_73;
}
F_81 ( & V_18 -> V_51 ) ;
V_18 -> V_46 = V_11 -> V_46 ;
F_82 ( & V_18 -> V_46 -> V_74 ) ;
F_83 ( V_18 ) ;
F_40 ( & V_18 -> V_75 ) ;
F_40 ( & V_18 -> V_76 ) ;
F_40 ( & V_18 -> V_77 ) ;
F_84 ( & V_18 -> V_78 , 1 ) ;
V_34 = F_69 ( V_18 ) ;
if ( V_34 )
goto V_73;
F_85 ( & V_79 ) ;
F_86 ( & V_18 -> V_80 , & V_80 ) ;
F_87 ( & V_79 ) ;
return V_18 ;
V_73:
F_88 ( & V_18 -> V_50 ) ;
V_69:
F_89 () ;
V_66:
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ )
F_90 ( V_18 -> V_71 [ V_20 ] ) ;
F_90 ( V_18 -> V_63 ) ;
F_91 ( V_18 ) ;
return F_74 ( V_34 ) ;
}
void * F_92 ( unsigned long V_81 )
{
if ( V_81 > V_57 )
return F_93 ( V_81 ) ;
else
return F_79 ( V_81 , V_37 ) ;
}
void F_94 ( const void * V_82 )
{
if ( F_95 ( V_82 ) )
F_96 ( V_82 ) ;
else
F_90 ( V_82 ) ;
}
static void F_97 ( struct V_83 * V_84 )
{
if ( ! V_84 -> V_85 )
return;
F_94 ( V_84 -> V_85 ) ;
V_84 -> V_85 = NULL ;
}
static void F_98 ( struct V_83 * free ,
struct V_83 * V_86 )
{
if ( ! V_86 || free -> V_87 != V_86 -> V_87 )
F_96 ( free -> V_87 ) ;
if ( ! V_86 || free -> V_85 != V_86 -> V_85 )
F_97 ( free ) ;
F_99 ( free , V_86 ) ;
free -> V_88 = 0 ;
free -> V_87 = NULL ;
}
void F_100 ( struct V_18 * V_18 )
{
struct V_61 * V_62 = V_18 -> V_63 ;
struct V_83 * V_84 ;
F_101 (memslot, slots)
F_98 ( V_84 , NULL ) ;
F_90 ( V_18 -> V_63 ) ;
}
static void F_102 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_45 * V_46 = V_18 -> V_46 ;
F_103 ( V_18 ) ;
F_85 ( & V_79 ) ;
F_104 ( & V_18 -> V_80 ) ;
F_87 ( & V_79 ) ;
F_105 ( V_18 ) ;
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ )
F_106 ( V_18 -> V_71 [ V_20 ] ) ;
F_107 ( V_18 ) ;
#if F_108 ( V_89 ) && F_108 ( V_90 )
F_109 ( & V_18 -> V_43 , V_18 -> V_46 ) ;
#else
F_68 ( V_18 ) ;
#endif
F_110 ( V_18 ) ;
F_100 ( V_18 ) ;
F_88 ( & V_18 -> V_50 ) ;
F_91 ( V_18 ) ;
F_89 () ;
F_111 ( V_46 ) ;
}
void F_112 ( struct V_18 * V_18 )
{
F_82 ( & V_18 -> V_78 ) ;
}
void F_113 ( struct V_18 * V_18 )
{
if ( F_114 ( & V_18 -> V_78 ) )
F_102 ( V_18 ) ;
}
static int F_115 ( struct V_91 * V_91 , struct V_92 * V_93 )
{
struct V_18 * V_18 = V_93 -> V_94 ;
F_116 ( V_18 ) ;
F_113 ( V_18 ) ;
return 0 ;
}
static int F_117 ( struct V_83 * V_84 )
{
#ifndef F_118
unsigned long V_95 = 2 * F_119 ( V_84 ) ;
V_84 -> V_85 = F_92 ( V_95 ) ;
if ( ! V_84 -> V_85 )
return - V_39 ;
#endif
return 0 ;
}
static int F_120 ( const void * V_96 , const void * V_97 )
{
struct V_83 * V_98 , * V_99 ;
V_98 = (struct V_83 * ) V_96 ;
V_99 = (struct V_83 * ) V_97 ;
if ( V_98 -> V_88 < V_99 -> V_88 )
return 1 ;
if ( V_98 -> V_88 > V_99 -> V_88 )
return - 1 ;
return 0 ;
}
static void F_121 ( struct V_61 * V_62 )
{
int V_20 ;
F_122 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_83 ) , F_120 , NULL ) ;
for ( V_20 = 0 ; V_20 < V_64 ; V_20 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_20 ] . V_33 ] = V_20 ;
}
void F_123 ( struct V_61 * V_62 , struct V_83 * V_100 )
{
if ( V_100 ) {
int V_33 = V_100 -> V_33 ;
struct V_83 * V_101 = F_124 ( V_62 , V_33 ) ;
unsigned long V_88 = V_101 -> V_88 ;
* V_101 = * V_100 ;
if ( V_100 -> V_88 != V_88 )
F_121 ( V_62 ) ;
}
V_62 -> V_102 ++ ;
}
int F_125 ( struct V_18 * V_18 ,
struct V_103 * V_104 ,
int V_105 )
{
int V_34 ;
T_4 V_106 ;
unsigned long V_88 ;
unsigned long V_20 ;
struct V_83 * V_84 ;
struct V_83 V_101 , V_100 ;
struct V_61 * V_62 , * V_107 ;
V_34 = - V_108 ;
if ( V_104 -> V_109 & ( V_57 - 1 ) )
goto V_110;
if ( V_104 -> V_111 & ( V_57 - 1 ) )
goto V_110;
if ( V_105 &&
( ( V_104 -> V_112 & ( V_57 - 1 ) ) ||
! F_126 ( V_113 ,
( void V_114 * ) ( unsigned long ) V_104 -> V_112 ,
V_104 -> V_109 ) ) )
goto V_110;
if ( V_104 -> V_115 >= V_64 )
goto V_110;
if ( V_104 -> V_111 + V_104 -> V_109 < V_104 -> V_111 )
goto V_110;
V_84 = F_124 ( V_18 -> V_63 , V_104 -> V_115 ) ;
V_106 = V_104 -> V_111 >> V_116 ;
V_88 = V_104 -> V_109 >> V_116 ;
V_34 = - V_108 ;
if ( V_88 > V_117 )
goto V_110;
if ( ! V_88 )
V_104 -> V_118 &= ~ V_119 ;
V_100 = V_101 = * V_84 ;
V_100 . V_33 = V_104 -> V_115 ;
V_100 . V_106 = V_106 ;
V_100 . V_88 = V_88 ;
V_100 . V_118 = V_104 -> V_118 ;
V_34 = - V_108 ;
if ( V_88 && V_101 . V_88 && V_88 != V_101 . V_88 )
goto V_120;
V_34 = - V_121 ;
for ( V_20 = 0 ; V_20 < V_122 ; ++ V_20 ) {
struct V_83 * V_123 = & V_18 -> V_63 -> V_63 [ V_20 ] ;
if ( V_123 == V_84 || ! V_123 -> V_88 )
continue;
if ( ! ( ( V_106 + V_88 <= V_123 -> V_106 ) ||
( V_106 >= V_123 -> V_106 + V_123 -> V_88 ) ) )
goto V_120;
}
if ( ! ( V_100 . V_118 & V_119 ) )
V_100 . V_85 = NULL ;
V_34 = - V_39 ;
if ( V_88 && ! V_101 . V_88 ) {
V_100 . V_105 = V_105 ;
V_100 . V_112 = V_104 -> V_112 ;
#ifndef F_118
V_100 . V_87 = F_93 ( V_88 * sizeof( * V_100 . V_87 ) ) ;
if ( ! V_100 . V_87 )
goto V_120;
#endif
if ( F_127 ( & V_100 , V_88 ) )
goto V_120;
}
if ( ( V_100 . V_118 & V_119 ) && ! V_100 . V_85 ) {
if ( F_117 ( & V_100 ) < 0 )
goto V_120;
}
if ( ! V_88 ) {
struct V_83 * V_115 ;
V_34 = - V_39 ;
V_62 = F_128 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_120;
V_115 = F_124 ( V_62 , V_104 -> V_115 ) ;
V_115 -> V_118 |= V_124 ;
F_123 ( V_62 , NULL ) ;
V_107 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_129 ( & V_18 -> V_50 ) ;
F_68 ( V_18 ) ;
F_90 ( V_107 ) ;
}
V_34 = F_130 ( V_18 , & V_100 , V_101 , V_104 , V_105 ) ;
if ( V_34 )
goto V_120;
if ( V_88 ) {
V_34 = F_131 ( V_18 , & V_100 ) ;
if ( V_34 )
goto V_120;
} else
F_132 ( V_18 , & V_101 ) ;
V_34 = - V_39 ;
V_62 = F_128 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_120;
if ( ! V_88 ) {
V_100 . V_87 = NULL ;
V_100 . V_85 = NULL ;
memset ( & V_100 . V_125 , 0 , sizeof( V_100 . V_125 ) ) ;
}
F_123 ( V_62 , & V_100 ) ;
V_107 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_129 ( & V_18 -> V_50 ) ;
F_133 ( V_18 , V_104 , V_101 , V_105 ) ;
if ( V_88 && V_101 . V_106 != V_104 -> V_111 >> V_116 )
F_68 ( V_18 ) ;
F_98 ( & V_101 , & V_100 ) ;
F_90 ( V_107 ) ;
return 0 ;
V_120:
F_98 ( & V_100 , & V_101 ) ;
V_110:
return V_34 ;
}
int F_134 ( struct V_18 * V_18 ,
struct V_103 * V_104 ,
int V_105 )
{
int V_34 ;
F_9 ( & V_18 -> V_77 ) ;
V_34 = F_125 ( V_18 , V_104 , V_105 ) ;
F_24 ( & V_18 -> V_77 ) ;
return V_34 ;
}
int F_135 ( struct V_18 * V_18 ,
struct
V_103 * V_104 ,
int V_105 )
{
if ( V_104 -> V_115 >= V_122 )
return - V_108 ;
return F_134 ( V_18 , V_104 , V_105 ) ;
}
int F_136 ( struct V_18 * V_18 ,
struct V_126 * log , int * V_127 )
{
struct V_83 * V_84 ;
int V_34 , V_20 ;
unsigned long V_128 ;
unsigned long V_129 = 0 ;
V_34 = - V_108 ;
if ( log -> V_115 >= V_122 )
goto V_110;
V_84 = F_124 ( V_18 -> V_63 , log -> V_115 ) ;
V_34 = - V_130 ;
if ( ! V_84 -> V_85 )
goto V_110;
V_128 = F_119 ( V_84 ) ;
for ( V_20 = 0 ; ! V_129 && V_20 < V_128 / sizeof( long ) ; ++ V_20 )
V_129 = V_84 -> V_85 [ V_20 ] ;
V_34 = - V_131 ;
if ( F_137 ( log -> V_85 , V_84 -> V_85 , V_128 ) )
goto V_110;
if ( V_129 )
* V_127 = 1 ;
V_34 = 0 ;
V_110:
return V_34 ;
}
bool F_138 ( void )
{
return V_132 ;
}
void F_139 ( void )
{
V_132 = false ;
}
int F_140 ( struct V_3 * V_3 )
{
return V_3 == V_133 || V_3 == V_134 || V_3 == V_135 ;
}
int F_141 ( T_1 V_1 )
{
return V_1 == V_136 || V_1 == V_137 || V_1 == V_138 ;
}
int F_142 ( T_1 V_1 )
{
return V_1 == V_137 ;
}
int F_143 ( T_1 V_1 )
{
return V_1 == V_138 ;
}
int F_144 ( T_1 V_1 )
{
return V_1 == V_136 ;
}
int F_145 ( T_1 V_1 )
{
return V_1 == V_137 || V_1 == V_138 ;
}
static inline unsigned long F_146 ( void )
{
return V_139 ;
}
int F_147 ( unsigned long V_82 )
{
return V_82 == F_146 () ;
}
struct V_83 * F_148 ( struct V_18 * V_18 , T_4 V_140 )
{
return F_149 ( V_61 ( V_18 ) , V_140 ) ;
}
int F_150 ( struct V_18 * V_18 , T_4 V_140 )
{
struct V_83 * V_84 = F_148 ( V_18 , V_140 ) ;
if ( ! V_84 || V_84 -> V_33 >= V_122 ||
V_84 -> V_118 & V_124 )
return 0 ;
return 1 ;
}
unsigned long F_151 ( struct V_18 * V_18 , T_4 V_140 )
{
struct V_141 * V_142 ;
unsigned long V_82 , V_81 ;
V_81 = V_57 ;
V_82 = F_152 ( V_18 , V_140 ) ;
if ( F_147 ( V_82 ) )
return V_57 ;
F_153 ( & V_11 -> V_46 -> V_143 ) ;
V_142 = F_154 ( V_11 -> V_46 , V_82 ) ;
if ( ! V_142 )
goto V_110;
V_81 = F_155 ( V_142 ) ;
V_110:
F_156 ( & V_11 -> V_46 -> V_143 ) ;
return V_81 ;
}
static unsigned long F_157 ( struct V_83 * V_115 , T_4 V_140 ,
T_4 * V_144 )
{
if ( ! V_115 || V_115 -> V_118 & V_124 )
return F_146 () ;
if ( V_144 )
* V_144 = V_115 -> V_88 - ( V_140 - V_115 -> V_106 ) ;
return F_158 ( V_115 , V_140 ) ;
}
unsigned long F_152 ( struct V_18 * V_18 , T_4 V_140 )
{
return F_157 ( F_148 ( V_18 , V_140 ) , V_140 , NULL ) ;
}
static T_1 F_159 ( void )
{
F_160 ( V_135 ) ;
return V_138 ;
}
int F_161 ( struct V_145 * V_146 , struct V_45 * V_46 ,
unsigned long V_54 , int V_147 , struct V_3 * * V_3 )
{
int V_118 = V_148 | V_149 | V_150 | V_151 ;
if ( V_147 )
V_118 |= V_152 ;
return F_162 ( V_146 , V_46 , V_54 , 1 , V_118 , V_3 , NULL , NULL ) ;
}
static inline int F_163 ( unsigned long V_82 )
{
int V_153 , V_118 = V_148 | V_150 | V_152 ;
V_153 = F_162 ( V_11 , V_11 -> V_46 , V_82 , 1 ,
V_118 , NULL , NULL , NULL ) ;
return V_153 == - V_154 ;
}
static T_1 F_164 ( struct V_18 * V_18 , unsigned long V_82 , bool V_155 ,
bool * V_156 , bool V_157 , bool * V_158 )
{
struct V_3 * V_3 [ 1 ] ;
int V_88 = 0 ;
T_1 V_1 ;
F_62 ( V_155 && V_156 ) ;
F_62 ( ! V_157 && ! V_158 ) ;
if ( V_158 )
* V_158 = true ;
if ( V_155 || V_156 )
V_88 = F_165 ( V_82 , 1 , 1 , V_3 ) ;
if ( F_10 ( V_88 != 1 ) && ! V_155 ) {
F_166 () ;
if ( V_158 )
* V_158 = V_157 ;
if ( V_156 ) {
F_153 ( & V_11 -> V_46 -> V_143 ) ;
V_88 = F_161 ( V_11 , V_11 -> V_46 ,
V_82 , V_157 , V_3 ) ;
F_156 ( & V_11 -> V_46 -> V_143 ) ;
} else
V_88 = F_167 ( V_82 , 1 , V_157 ,
V_3 ) ;
if ( F_10 ( ! V_157 ) && V_88 == 1 ) {
struct V_3 * V_159 [ 1 ] ;
V_88 = F_165 ( V_82 , 1 , 1 , V_159 ) ;
if ( V_88 == 1 ) {
* V_158 = true ;
F_168 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_159 [ 0 ] ;
}
V_88 = 1 ;
}
}
if ( F_10 ( V_88 != 1 ) ) {
struct V_141 * V_142 ;
if ( V_155 )
return F_159 () ;
F_153 ( & V_11 -> V_46 -> V_143 ) ;
if ( V_88 == - V_154 ||
( ! V_156 && F_163 ( V_82 ) ) ) {
F_156 ( & V_11 -> V_46 -> V_143 ) ;
F_160 ( V_134 ) ;
return F_169 ( V_134 ) ;
}
V_142 = F_170 ( V_11 -> V_46 , V_82 , V_82 + 1 ) ;
if ( V_142 == NULL )
V_1 = F_159 () ;
else if ( ( V_142 -> V_160 & V_161 ) ) {
V_1 = ( ( V_82 - V_142 -> V_162 ) >> V_116 ) +
V_142 -> V_163 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_156 && ( V_142 -> V_160 & V_164 ) )
* V_156 = true ;
V_1 = F_159 () ;
}
F_156 ( & V_11 -> V_46 -> V_143 ) ;
} else
V_1 = F_169 ( V_3 [ 0 ] ) ;
return V_1 ;
}
T_1 F_171 ( struct V_18 * V_18 , unsigned long V_82 )
{
return F_164 ( V_18 , V_82 , true , NULL , true , NULL ) ;
}
static T_1 F_172 ( struct V_18 * V_18 , T_4 V_140 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
unsigned long V_82 ;
if ( V_156 )
* V_156 = false ;
V_82 = F_152 ( V_18 , V_140 ) ;
if ( F_147 ( V_82 ) ) {
F_160 ( V_133 ) ;
return F_169 ( V_133 ) ;
}
return F_164 ( V_18 , V_82 , V_155 , V_156 , V_157 , V_158 ) ;
}
T_1 F_173 ( struct V_18 * V_18 , T_4 V_140 )
{
return F_172 ( V_18 , V_140 , true , NULL , true , NULL ) ;
}
T_1 F_174 ( struct V_18 * V_18 , T_4 V_140 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
return F_172 ( V_18 , V_140 , false , V_156 , V_157 , V_158 ) ;
}
T_1 F_175 ( struct V_18 * V_18 , T_4 V_140 )
{
return F_172 ( V_18 , V_140 , false , NULL , true , NULL ) ;
}
T_1 F_176 ( struct V_18 * V_18 , T_4 V_140 , bool V_157 ,
bool * V_158 )
{
return F_172 ( V_18 , V_140 , false , NULL , V_157 , V_158 ) ;
}
T_1 F_177 ( struct V_18 * V_18 ,
struct V_83 * V_115 , T_4 V_140 )
{
unsigned long V_82 = F_158 ( V_115 , V_140 ) ;
return F_164 ( V_18 , V_82 , false , NULL , true , NULL ) ;
}
int F_178 ( struct V_18 * V_18 , T_4 V_140 , struct V_3 * * V_165 ,
int V_144 )
{
unsigned long V_82 ;
T_4 V_166 ;
V_82 = F_157 ( F_148 ( V_18 , V_140 ) , V_140 , & V_166 ) ;
if ( F_147 ( V_82 ) )
return - 1 ;
if ( V_166 < V_144 )
return 0 ;
return F_165 ( V_82 , V_144 , 1 , V_165 ) ;
}
struct V_3 * F_179 ( struct V_18 * V_18 , T_4 V_140 )
{
T_1 V_1 ;
V_1 = F_175 ( V_18 , V_140 ) ;
if ( ! F_1 ( V_1 ) )
return F_3 ( V_1 ) ;
F_180 ( F_1 ( V_1 ) ) ;
F_160 ( V_133 ) ;
return V_133 ;
}
void F_181 ( struct V_3 * V_3 )
{
F_182 ( F_169 ( V_3 ) ) ;
}
void F_182 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_168 ( F_3 ( V_1 ) ) ;
}
void F_183 ( struct V_3 * V_3 )
{
F_184 ( F_169 ( V_3 ) ) ;
}
void F_184 ( T_1 V_1 )
{
F_185 ( V_1 ) ;
F_182 ( V_1 ) ;
}
void F_186 ( struct V_3 * V_3 )
{
F_185 ( F_169 ( V_3 ) ) ;
}
void F_185 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_187 ( V_3 ) ;
}
}
void F_188 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_189 ( F_3 ( V_1 ) ) ;
}
void F_190 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_160 ( F_3 ( V_1 ) ) ;
}
static int F_191 ( unsigned long V_167 , int V_168 )
{
if ( V_167 > V_57 - V_168 )
return V_57 - V_168 ;
else
return V_167 ;
}
int F_192 ( struct V_18 * V_18 , T_4 V_140 , void * V_169 , int V_168 ,
int V_167 )
{
int V_34 ;
unsigned long V_82 ;
V_82 = F_152 ( V_18 , V_140 ) ;
if ( F_147 ( V_82 ) )
return - V_131 ;
V_34 = F_193 ( V_169 , ( void V_114 * ) V_82 + V_168 , V_167 ) ;
if ( V_34 )
return - V_131 ;
return 0 ;
}
int F_194 ( struct V_18 * V_18 , T_5 V_170 , void * V_169 , unsigned long V_167 )
{
T_4 V_140 = V_170 >> V_116 ;
int V_171 ;
int V_168 = F_195 ( V_170 ) ;
int V_172 ;
while ( ( V_171 = F_191 ( V_167 , V_168 ) ) != 0 ) {
V_172 = F_192 ( V_18 , V_140 , V_169 , V_168 , V_171 ) ;
if ( V_172 < 0 )
return V_172 ;
V_168 = 0 ;
V_167 -= V_171 ;
V_169 += V_171 ;
++ V_140 ;
}
return 0 ;
}
int F_196 ( struct V_18 * V_18 , T_5 V_170 , void * V_169 ,
unsigned long V_167 )
{
int V_34 ;
unsigned long V_82 ;
T_4 V_140 = V_170 >> V_116 ;
int V_168 = F_195 ( V_170 ) ;
V_82 = F_152 ( V_18 , V_140 ) ;
if ( F_147 ( V_82 ) )
return - V_131 ;
F_197 () ;
V_34 = F_198 ( V_169 , ( void V_114 * ) V_82 + V_168 , V_167 ) ;
F_199 () ;
if ( V_34 )
return - V_131 ;
return 0 ;
}
int F_200 ( struct V_18 * V_18 , T_4 V_140 , const void * V_169 ,
int V_168 , int V_167 )
{
int V_34 ;
unsigned long V_82 ;
V_82 = F_152 ( V_18 , V_140 ) ;
if ( F_147 ( V_82 ) )
return - V_131 ;
V_34 = F_201 ( ( void V_114 * ) V_82 + V_168 , V_169 , V_167 ) ;
if ( V_34 )
return - V_131 ;
F_202 ( V_18 , V_140 ) ;
return 0 ;
}
int F_203 ( struct V_18 * V_18 , T_5 V_170 , const void * V_169 ,
unsigned long V_167 )
{
T_4 V_140 = V_170 >> V_116 ;
int V_171 ;
int V_168 = F_195 ( V_170 ) ;
int V_172 ;
while ( ( V_171 = F_191 ( V_167 , V_168 ) ) != 0 ) {
V_172 = F_200 ( V_18 , V_140 , V_169 , V_168 , V_171 ) ;
if ( V_172 < 0 )
return V_172 ;
V_168 = 0 ;
V_167 -= V_171 ;
V_169 += V_171 ;
++ V_140 ;
}
return 0 ;
}
int F_204 ( struct V_18 * V_18 , struct V_173 * V_174 ,
T_5 V_170 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_168 = F_195 ( V_170 ) ;
T_4 V_140 = V_170 >> V_116 ;
V_174 -> V_170 = V_170 ;
V_174 -> V_102 = V_62 -> V_102 ;
V_174 -> V_84 = F_148 ( V_18 , V_140 ) ;
V_174 -> V_175 = F_157 ( V_174 -> V_84 , V_140 , NULL ) ;
if ( ! F_147 ( V_174 -> V_175 ) )
V_174 -> V_175 += V_168 ;
else
return - V_131 ;
return 0 ;
}
int F_205 ( struct V_18 * V_18 , struct V_173 * V_174 ,
void * V_169 , unsigned long V_167 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_102 != V_174 -> V_102 )
F_204 ( V_18 , V_174 , V_174 -> V_170 ) ;
if ( F_147 ( V_174 -> V_175 ) )
return - V_131 ;
V_34 = F_201 ( ( void V_114 * ) V_174 -> V_175 , V_169 , V_167 ) ;
if ( V_34 )
return - V_131 ;
F_206 ( V_18 , V_174 -> V_84 , V_174 -> V_170 >> V_116 ) ;
return 0 ;
}
int F_207 ( struct V_18 * V_18 , struct V_173 * V_174 ,
void * V_169 , unsigned long V_167 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_102 != V_174 -> V_102 )
F_204 ( V_18 , V_174 , V_174 -> V_170 ) ;
if ( F_147 ( V_174 -> V_175 ) )
return - V_131 ;
V_34 = F_193 ( V_169 , ( void V_114 * ) V_174 -> V_175 , V_167 ) ;
if ( V_34 )
return - V_131 ;
return 0 ;
}
int F_208 ( struct V_18 * V_18 , T_4 V_140 , int V_168 , int V_167 )
{
return F_200 ( V_18 , V_140 , ( const void * ) V_176 ,
V_168 , V_167 ) ;
}
int F_209 ( struct V_18 * V_18 , T_5 V_170 , unsigned long V_167 )
{
T_4 V_140 = V_170 >> V_116 ;
int V_171 ;
int V_168 = F_195 ( V_170 ) ;
int V_172 ;
while ( ( V_171 = F_191 ( V_167 , V_168 ) ) != 0 ) {
V_172 = F_208 ( V_18 , V_140 , V_168 , V_171 ) ;
if ( V_172 < 0 )
return V_172 ;
V_168 = 0 ;
V_167 -= V_171 ;
++ V_140 ;
}
return 0 ;
}
void F_206 ( struct V_18 * V_18 , struct V_83 * V_84 ,
T_4 V_140 )
{
if ( V_84 && V_84 -> V_85 ) {
unsigned long V_177 = V_140 - V_84 -> V_106 ;
F_210 ( V_177 , V_84 -> V_85 ) ;
}
}
void F_202 ( struct V_18 * V_18 , T_4 V_140 )
{
struct V_83 * V_84 ;
V_84 = F_148 ( V_18 , V_140 ) ;
F_206 ( V_18 , V_84 , V_140 ) ;
}
void F_211 ( struct V_6 * V_7 )
{
F_212 ( V_178 ) ;
for (; ; ) {
F_213 ( & V_7 -> V_36 , & V_178 , V_179 ) ;
if ( F_214 ( V_7 ) ) {
F_29 ( V_180 , V_7 ) ;
break;
}
if ( F_215 ( V_7 ) )
break;
if ( F_216 ( V_11 ) )
break;
F_217 () ;
}
F_218 ( & V_7 -> V_36 , & V_178 ) ;
}
void F_219 ( struct V_6 * V_7 )
{
int V_21 ;
int V_8 = V_7 -> V_8 ;
T_6 * V_181 ;
V_181 = F_220 ( V_7 ) ;
if ( F_221 ( V_181 ) ) {
F_222 ( V_181 ) ;
++ V_7 -> V_30 . V_182 ;
}
V_21 = F_15 () ;
if ( V_8 != V_21 && ( unsigned ) V_8 < V_183 && F_223 ( V_8 ) )
if ( F_224 ( V_7 ) )
F_225 ( V_8 ) ;
F_18 () ;
}
void F_226 ( struct V_6 * V_7 )
{
if ( ! F_227 () )
return;
F_228 () ;
}
bool F_229 ( struct V_6 * V_184 )
{
struct V_10 * V_10 ;
struct V_145 * V_185 = NULL ;
F_230 () ;
V_10 = F_231 ( V_184 -> V_10 ) ;
if ( V_10 )
V_185 = F_232 ( V_184 -> V_10 , V_13 ) ;
F_233 () ;
if ( ! V_185 )
return false ;
if ( V_185 -> V_118 & V_186 ) {
F_234 ( V_185 ) ;
return false ;
}
if ( F_235 ( V_185 , 1 ) ) {
F_234 ( V_185 ) ;
return true ;
}
F_234 ( V_185 ) ;
return false ;
}
void F_236 ( struct V_6 * V_21 )
{
struct V_18 * V_18 = V_21 -> V_18 ;
struct V_6 * V_7 ;
int V_187 = V_21 -> V_18 -> V_187 ;
int V_188 = 0 ;
int V_189 ;
int V_20 ;
for ( V_189 = 0 ; V_189 < 2 && ! V_188 ; V_189 ++ ) {
F_28 (i, vcpu, kvm) {
if ( ! V_189 && V_20 <= V_187 ) {
V_20 = V_187 ;
continue;
} else if ( V_189 && V_20 > V_187 )
break;
if ( V_7 == V_21 )
continue;
if ( F_221 ( & V_7 -> V_36 ) )
continue;
if ( F_229 ( V_7 ) ) {
V_18 -> V_187 = V_20 ;
V_188 = 1 ;
break;
}
}
}
}
static int F_237 ( struct V_141 * V_142 , struct V_190 * V_191 )
{
struct V_6 * V_7 = V_142 -> V_192 -> V_94 ;
struct V_3 * V_3 ;
if ( V_191 -> V_193 == 0 )
V_3 = F_238 ( V_7 -> V_41 ) ;
#ifdef F_239
else if ( V_191 -> V_193 == V_194 )
V_3 = F_238 ( V_7 -> V_125 . V_195 ) ;
#endif
#ifdef F_240
else if ( V_191 -> V_193 == F_240 )
V_3 = F_238 ( V_7 -> V_18 -> V_196 ) ;
#endif
else
return F_241 ( V_7 , V_191 ) ;
F_160 ( V_3 ) ;
V_191 -> V_3 = V_3 ;
return 0 ;
}
static int F_242 ( struct V_92 * V_92 , struct V_141 * V_142 )
{
V_142 -> V_197 = & V_198 ;
return 0 ;
}
static int F_243 ( struct V_91 * V_91 , struct V_92 * V_93 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
F_113 ( V_7 -> V_18 ) ;
return 0 ;
}
static int F_244 ( struct V_6 * V_7 )
{
return F_245 ( L_1 , & V_199 , V_7 , V_200 ) ;
}
static int F_246 ( struct V_18 * V_18 , T_7 V_33 )
{
int V_34 ;
struct V_6 * V_7 , * V_201 ;
V_7 = F_247 ( V_18 , V_33 ) ;
if ( F_248 ( V_7 ) )
return F_249 ( V_7 ) ;
F_250 ( & V_7 -> V_16 , & V_202 ) ;
V_34 = F_251 ( V_7 ) ;
if ( V_34 )
goto V_203;
F_9 ( & V_18 -> V_75 ) ;
if ( ! F_252 ( V_7 ) ) {
V_34 = - V_108 ;
goto V_204;
}
if ( F_253 ( & V_18 -> V_205 ) == V_206 ) {
V_34 = - V_108 ;
goto V_204;
}
F_28 (r, v, kvm)
if ( V_201 -> V_35 == V_33 ) {
V_34 = - V_121 ;
goto V_204;
}
F_62 ( V_18 -> V_207 [ F_253 ( & V_18 -> V_205 ) ] ) ;
F_112 ( V_18 ) ;
V_34 = F_244 ( V_7 ) ;
if ( V_34 < 0 ) {
F_113 ( V_18 ) ;
goto V_204;
}
V_18 -> V_207 [ F_253 ( & V_18 -> V_205 ) ] = V_7 ;
F_61 () ;
F_82 ( & V_18 -> V_205 ) ;
F_24 ( & V_18 -> V_75 ) ;
return V_34 ;
V_204:
F_24 ( & V_18 -> V_75 ) ;
V_203:
F_254 ( V_7 ) ;
return V_34 ;
}
static int F_255 ( struct V_6 * V_7 , T_8 * V_208 )
{
if ( V_208 ) {
F_256 ( V_208 , F_257 ( V_209 ) | F_257 ( V_210 ) ) ;
V_7 -> V_211 = 1 ;
V_7 -> V_208 = * V_208 ;
} else
V_7 -> V_211 = 0 ;
return 0 ;
}
static long F_258 ( struct V_92 * V_93 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
void V_114 * V_214 = ( void V_114 * ) V_213 ;
int V_34 ;
struct V_215 * V_216 = NULL ;
struct V_217 * V_217 = NULL ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
#if F_108 ( F_118 ) || F_108 ( V_219 )
if ( V_212 == V_220 || V_212 == V_221 )
return F_259 ( V_93 , V_212 , V_213 ) ;
#endif
F_8 ( V_7 ) ;
switch ( V_212 ) {
case V_222 :
V_34 = - V_108 ;
if ( V_213 )
goto V_110;
V_34 = F_260 ( V_7 , V_7 -> V_41 ) ;
F_261 ( V_7 -> V_41 -> V_223 , V_34 ) ;
break;
case V_224 : {
struct V_225 * V_225 ;
V_34 = - V_39 ;
V_225 = F_79 ( sizeof( struct V_225 ) , V_37 ) ;
if ( ! V_225 )
goto V_110;
V_34 = F_262 ( V_7 , V_225 ) ;
if ( V_34 )
goto V_226;
V_34 = - V_131 ;
if ( F_137 ( V_214 , V_225 , sizeof( struct V_225 ) ) )
goto V_226;
V_34 = 0 ;
V_226:
F_90 ( V_225 ) ;
break;
}
case V_227 : {
struct V_225 * V_225 ;
V_34 = - V_39 ;
V_225 = F_263 ( V_214 , sizeof( * V_225 ) ) ;
if ( F_248 ( V_225 ) ) {
V_34 = F_249 ( V_225 ) ;
goto V_110;
}
V_34 = F_264 ( V_7 , V_225 ) ;
if ( V_34 )
goto V_228;
V_34 = 0 ;
V_228:
F_90 ( V_225 ) ;
break;
}
case V_229 : {
V_217 = F_79 ( sizeof( struct V_217 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_217 )
goto V_110;
V_34 = F_265 ( V_7 , V_217 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_137 ( V_214 , V_217 , sizeof( struct V_217 ) ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_230 : {
V_217 = F_263 ( V_214 , sizeof( * V_217 ) ) ;
if ( F_248 ( V_217 ) ) {
V_34 = F_249 ( V_217 ) ;
goto V_110;
}
V_34 = F_266 ( V_7 , V_217 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_231 : {
struct V_232 V_233 ;
V_34 = F_267 ( V_7 , & V_233 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_137 ( V_214 , & V_233 , sizeof V_233 ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_234 : {
struct V_232 V_233 ;
V_34 = - V_131 ;
if ( F_268 ( & V_233 , V_214 , sizeof V_233 ) )
goto V_110;
V_34 = F_269 ( V_7 , & V_233 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_235 : {
struct V_236 V_237 ;
V_34 = - V_131 ;
if ( F_268 ( & V_237 , V_214 , sizeof V_237 ) )
goto V_110;
V_34 = F_270 ( V_7 , & V_237 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_137 ( V_214 , & V_237 , sizeof V_237 ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_238 : {
struct V_239 V_240 ;
V_34 = - V_131 ;
if ( F_268 ( & V_240 , V_214 , sizeof V_240 ) )
goto V_110;
V_34 = F_271 ( V_7 , & V_240 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_241 : {
struct V_242 V_114 * V_243 = V_214 ;
struct V_242 V_244 ;
T_8 V_208 , * V_245 ;
V_245 = NULL ;
if ( V_214 ) {
V_34 = - V_131 ;
if ( F_268 ( & V_244 , V_214 ,
sizeof V_244 ) )
goto V_110;
V_34 = - V_108 ;
if ( V_244 . V_167 != sizeof V_208 )
goto V_110;
V_34 = - V_131 ;
if ( F_268 ( & V_208 , V_243 -> V_208 ,
sizeof V_208 ) )
goto V_110;
V_245 = & V_208 ;
}
V_34 = F_255 ( V_7 , V_245 ) ;
break;
}
case V_246 : {
V_216 = F_79 ( sizeof( struct V_215 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_216 )
goto V_110;
V_34 = F_272 ( V_7 , V_216 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_137 ( V_214 , V_216 , sizeof( struct V_215 ) ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_247 : {
V_216 = F_263 ( V_214 , sizeof( * V_216 ) ) ;
if ( F_248 ( V_216 ) ) {
V_34 = F_249 ( V_216 ) ;
goto V_110;
}
V_34 = F_273 ( V_7 , V_216 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
default:
V_34 = F_259 ( V_93 , V_212 , V_213 ) ;
}
V_110:
F_19 ( V_7 ) ;
F_90 ( V_216 ) ;
F_90 ( V_217 ) ;
return V_34 ;
}
static long F_274 ( struct V_92 * V_93 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
void V_114 * V_214 = F_275 ( V_213 ) ;
int V_34 ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
switch ( V_212 ) {
case V_241 : {
struct V_242 V_114 * V_243 = V_214 ;
struct V_242 V_244 ;
T_9 V_248 ;
T_8 V_208 ;
if ( V_214 ) {
V_34 = - V_131 ;
if ( F_268 ( & V_244 , V_214 ,
sizeof V_244 ) )
goto V_110;
V_34 = - V_108 ;
if ( V_244 . V_167 != sizeof V_248 )
goto V_110;
V_34 = - V_131 ;
if ( F_268 ( & V_248 , V_243 -> V_208 ,
sizeof V_248 ) )
goto V_110;
F_276 ( & V_208 , & V_248 ) ;
V_34 = F_255 ( V_7 , & V_208 ) ;
} else
V_34 = F_255 ( V_7 , NULL ) ;
break;
}
default:
V_34 = F_258 ( V_93 , V_212 , V_213 ) ;
}
V_110:
return V_34 ;
}
static long F_277 ( struct V_92 * V_93 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_18 * V_18 = V_93 -> V_94 ;
void V_114 * V_214 = ( void V_114 * ) V_213 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
switch ( V_212 ) {
case V_249 :
V_34 = F_246 ( V_18 , V_213 ) ;
if ( V_34 < 0 )
goto V_110;
break;
case V_250 : {
struct V_103 V_251 ;
V_34 = - V_131 ;
if ( F_268 ( & V_251 , V_214 ,
sizeof V_251 ) )
goto V_110;
V_34 = F_135 ( V_18 , & V_251 , 1 ) ;
if ( V_34 )
goto V_110;
break;
}
case V_252 : {
struct V_126 log ;
V_34 = - V_131 ;
if ( F_268 ( & log , V_214 , sizeof log ) )
goto V_110;
V_34 = F_278 ( V_18 , & log ) ;
if ( V_34 )
goto V_110;
break;
}
#ifdef F_240
case V_253 : {
struct V_254 V_255 ;
V_34 = - V_131 ;
if ( F_268 ( & V_255 , V_214 , sizeof V_255 ) )
goto V_110;
V_34 = F_279 ( V_18 , & V_255 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_256 : {
struct V_254 V_255 ;
V_34 = - V_131 ;
if ( F_268 ( & V_255 , V_214 , sizeof V_255 ) )
goto V_110;
V_34 = F_280 ( V_18 , & V_255 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
#endif
case V_257 : {
struct V_258 V_169 ;
V_34 = - V_131 ;
if ( F_268 ( & V_169 , V_214 , sizeof V_169 ) )
goto V_110;
V_34 = V_258 ( V_18 , & V_169 ) ;
break;
}
case V_259 : {
struct V_260 V_169 ;
V_34 = - V_131 ;
if ( F_268 ( & V_169 , V_214 , sizeof V_169 ) )
goto V_110;
V_34 = V_260 ( V_18 , & V_169 ) ;
break;
}
#ifdef F_281
case V_261 :
V_34 = 0 ;
F_9 ( & V_18 -> V_75 ) ;
if ( F_253 ( & V_18 -> V_205 ) != 0 )
V_34 = - V_262 ;
else
V_18 -> V_263 = V_213 ;
F_24 ( & V_18 -> V_75 ) ;
break;
#endif
#ifdef F_282
case V_264 : {
struct V_265 V_266 ;
V_34 = - V_131 ;
if ( F_268 ( & V_266 , V_214 , sizeof V_266 ) )
goto V_110;
V_34 = F_283 ( V_18 , & V_266 ) ;
break;
}
#endif
default:
V_34 = F_284 ( V_93 , V_212 , V_213 ) ;
if ( V_34 == - V_267 )
V_34 = F_285 ( V_18 , V_212 , V_213 ) ;
}
V_110:
return V_34 ;
}
static long F_286 ( struct V_92 * V_93 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_18 * V_18 = V_93 -> V_94 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
switch ( V_212 ) {
case V_252 : {
struct V_268 V_269 ;
struct V_126 log ;
V_34 = - V_131 ;
if ( F_268 ( & V_269 , ( void V_114 * ) V_213 ,
sizeof( V_269 ) ) )
goto V_110;
log . V_115 = V_269 . V_115 ;
log . V_270 = V_269 . V_270 ;
log . V_271 = V_269 . V_271 ;
log . V_85 = F_275 ( V_269 . V_85 ) ;
V_34 = F_278 ( V_18 , & log ) ;
if ( V_34 )
goto V_110;
break;
}
default:
V_34 = F_277 ( V_93 , V_212 , V_213 ) ;
}
V_110:
return V_34 ;
}
static int F_287 ( struct V_141 * V_142 , struct V_190 * V_191 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_82 ;
int V_88 ;
T_4 V_140 = V_191 -> V_193 ;
struct V_18 * V_18 = V_142 -> V_192 -> V_94 ;
V_82 = F_152 ( V_18 , V_140 ) ;
if ( F_147 ( V_82 ) )
return V_272 ;
V_88 = F_288 ( V_11 , V_11 -> V_46 , V_82 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_88 != 1 ) )
return V_272 ;
V_191 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_289 ( struct V_92 * V_92 , struct V_141 * V_142 )
{
V_142 -> V_197 = & V_273 ;
return 0 ;
}
static int F_290 ( unsigned long type )
{
int V_34 ;
struct V_18 * V_18 ;
V_18 = F_72 ( type ) ;
if ( F_248 ( V_18 ) )
return F_249 ( V_18 ) ;
#ifdef F_240
V_34 = F_291 ( V_18 ) ;
if ( V_34 < 0 ) {
F_113 ( V_18 ) ;
return V_34 ;
}
#endif
V_34 = F_245 ( L_2 , & V_274 , V_18 , V_200 ) ;
if ( V_34 < 0 )
F_113 ( V_18 ) ;
return V_34 ;
}
static long F_292 ( long V_213 )
{
switch ( V_213 ) {
case V_275 :
case V_276 :
case V_277 :
#ifdef F_281
case V_278 :
#endif
case V_279 :
#ifdef F_282
case V_280 :
#endif
return 1 ;
#ifdef F_293
case F_293 :
return V_281 ;
#endif
default:
break;
}
return F_294 ( V_213 ) ;
}
static long F_295 ( struct V_92 * V_93 ,
unsigned int V_212 , unsigned long V_213 )
{
long V_34 = - V_108 ;
switch ( V_212 ) {
case V_282 :
V_34 = - V_108 ;
if ( V_213 )
goto V_110;
V_34 = V_283 ;
break;
case V_284 :
V_34 = F_290 ( V_213 ) ;
break;
case V_285 :
V_34 = F_292 ( V_213 ) ;
break;
case V_286 :
V_34 = - V_108 ;
if ( V_213 )
goto V_110;
V_34 = V_57 ;
#ifdef F_239
V_34 += V_57 ;
#endif
#ifdef F_240
V_34 += V_57 ;
#endif
break;
case V_287 :
case V_288 :
case V_289 :
V_34 = - V_290 ;
break;
default:
return F_296 ( V_93 , V_212 , V_213 ) ;
}
V_110:
return V_34 ;
}
static void F_297 ( void * V_291 )
{
int V_8 = F_298 () ;
int V_34 ;
if ( F_299 ( V_8 , V_292 ) )
return;
F_32 ( V_8 , V_292 ) ;
V_34 = F_300 ( NULL ) ;
if ( V_34 ) {
F_301 ( V_8 , V_292 ) ;
F_82 ( & V_293 ) ;
F_302 ( V_294 L_3
L_4 , V_8 ) ;
}
}
static void F_303 ( void * V_291 )
{
F_85 ( & V_79 ) ;
F_297 ( V_291 ) ;
F_87 ( & V_79 ) ;
}
static void F_304 ( void * V_291 )
{
int V_8 = F_298 () ;
if ( ! F_299 ( V_8 , V_292 ) )
return;
F_301 ( V_8 , V_292 ) ;
F_305 ( NULL ) ;
}
static void F_306 ( void * V_291 )
{
F_85 ( & V_79 ) ;
F_304 ( V_291 ) ;
F_87 ( & V_79 ) ;
}
static void F_307 ( void )
{
F_62 ( ! V_295 ) ;
V_295 -- ;
if ( ! V_295 )
F_308 ( F_304 , NULL , 1 ) ;
}
static void F_89 ( void )
{
F_85 ( & V_79 ) ;
F_307 () ;
F_87 ( & V_79 ) ;
}
static int F_76 ( void )
{
int V_34 = 0 ;
F_85 ( & V_79 ) ;
V_295 ++ ;
if ( V_295 == 1 ) {
F_84 ( & V_293 , 0 ) ;
F_308 ( F_297 , NULL , 1 ) ;
if ( F_253 ( & V_293 ) ) {
F_307 () ;
V_34 = - V_262 ;
}
}
F_87 ( & V_79 ) ;
return V_34 ;
}
static int F_309 ( struct V_296 * V_297 , unsigned long V_298 ,
void * V_201 )
{
int V_8 = ( long ) V_201 ;
if ( ! V_295 )
return V_299 ;
V_298 &= ~ V_300 ;
switch ( V_298 ) {
case V_301 :
F_302 ( V_294 L_5 ,
V_8 ) ;
F_306 ( NULL ) ;
break;
case V_302 :
F_302 ( V_294 L_6 ,
V_8 ) ;
F_303 ( NULL ) ;
break;
}
return V_299 ;
}
T_10 void F_310 ( void )
{
F_311 () ;
}
static int F_312 ( struct V_296 * V_297 , unsigned long V_298 ,
void * V_201 )
{
F_302 ( V_294 L_7 ) ;
V_303 = true ;
F_308 ( F_304 , NULL , 1 ) ;
return V_299 ;
}
static void F_106 ( struct V_72 * V_304 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_304 -> V_305 ; V_20 ++ ) {
struct V_306 * V_307 = V_304 -> V_308 [ V_20 ] . V_309 ;
F_313 ( V_307 ) ;
}
F_90 ( V_304 ) ;
}
int F_314 ( const void * V_310 , const void * V_311 )
{
const struct V_312 * V_313 = V_310 ;
const struct V_312 * V_314 = V_311 ;
if ( V_313 -> V_82 < V_314 -> V_82 )
return - 1 ;
if ( V_313 -> V_82 + V_313 -> V_167 > V_314 -> V_82 + V_314 -> V_167 )
return 1 ;
return 0 ;
}
int F_315 ( struct V_72 * V_304 , struct V_306 * V_309 ,
T_5 V_82 , int V_167 )
{
V_304 -> V_308 [ V_304 -> V_305 ++ ] = (struct V_312 ) {
. V_82 = V_82 ,
. V_167 = V_167 ,
. V_309 = V_309 ,
} ;
F_122 ( V_304 -> V_308 , V_304 -> V_305 , sizeof( struct V_312 ) ,
F_314 , NULL ) ;
return 0 ;
}
int F_316 ( struct V_72 * V_304 ,
T_5 V_82 , int V_167 )
{
struct V_312 * V_308 , V_315 ;
int V_316 ;
V_315 = (struct V_312 ) {
. V_82 = V_82 ,
. V_167 = V_167 ,
} ;
V_308 = bsearch ( & V_315 , V_304 -> V_308 , V_304 -> V_305 ,
sizeof( struct V_312 ) , F_314 ) ;
if ( V_308 == NULL )
return - V_130 ;
V_316 = V_308 - V_304 -> V_308 ;
while ( V_316 > 0 && F_314 ( & V_315 , & V_304 -> V_308 [ V_316 - 1 ] ) == 0 )
V_316 -- ;
return V_316 ;
}
int F_317 ( struct V_18 * V_18 , enum V_317 V_318 , T_5 V_82 ,
int V_167 , const void * V_298 )
{
int V_49 ;
struct V_72 * V_304 ;
struct V_312 V_308 ;
V_308 = (struct V_312 ) {
. V_82 = V_82 ,
. V_167 = V_167 ,
} ;
V_304 = F_318 ( V_18 -> V_71 [ V_318 ] , & V_18 -> V_50 ) ;
V_49 = F_316 ( V_304 , V_82 , V_167 ) ;
if ( V_49 < 0 )
return - V_290 ;
while ( V_49 < V_304 -> V_305 &&
F_314 ( & V_308 , & V_304 -> V_308 [ V_49 ] ) == 0 ) {
if ( ! F_319 ( V_304 -> V_308 [ V_49 ] . V_309 , V_82 , V_167 , V_298 ) )
return 0 ;
V_49 ++ ;
}
return - V_290 ;
}
int F_320 ( struct V_18 * V_18 , enum V_317 V_318 , T_5 V_82 ,
int V_167 , void * V_298 )
{
int V_49 ;
struct V_72 * V_304 ;
struct V_312 V_308 ;
V_308 = (struct V_312 ) {
. V_82 = V_82 ,
. V_167 = V_167 ,
} ;
V_304 = F_318 ( V_18 -> V_71 [ V_318 ] , & V_18 -> V_50 ) ;
V_49 = F_316 ( V_304 , V_82 , V_167 ) ;
if ( V_49 < 0 )
return - V_290 ;
while ( V_49 < V_304 -> V_305 &&
F_314 ( & V_308 , & V_304 -> V_308 [ V_49 ] ) == 0 ) {
if ( ! F_321 ( V_304 -> V_308 [ V_49 ] . V_309 , V_82 , V_167 , V_298 ) )
return 0 ;
V_49 ++ ;
}
return - V_290 ;
}
int F_322 ( struct V_18 * V_18 , enum V_317 V_318 , T_5 V_82 ,
int V_167 , struct V_306 * V_309 )
{
struct V_72 * V_319 , * V_304 ;
V_304 = V_18 -> V_71 [ V_318 ] ;
if ( V_304 -> V_305 > V_320 - 1 )
return - V_321 ;
V_319 = F_79 ( sizeof( * V_304 ) + ( ( V_304 -> V_305 + 1 ) *
sizeof( struct V_312 ) ) , V_37 ) ;
if ( ! V_319 )
return - V_39 ;
memcpy ( V_319 , V_304 , sizeof( * V_304 ) + ( V_304 -> V_305 *
sizeof( struct V_312 ) ) ) ;
F_315 ( V_319 , V_309 , V_82 , V_167 ) ;
F_12 ( V_18 -> V_71 [ V_318 ] , V_319 ) ;
F_129 ( & V_18 -> V_50 ) ;
F_90 ( V_304 ) ;
return 0 ;
}
int F_323 ( struct V_18 * V_18 , enum V_317 V_318 ,
struct V_306 * V_309 )
{
int V_20 , V_34 ;
struct V_72 * V_319 , * V_304 ;
V_304 = V_18 -> V_71 [ V_318 ] ;
V_34 = - V_130 ;
for ( V_20 = 0 ; V_20 < V_304 -> V_305 ; V_20 ++ )
if ( V_304 -> V_308 [ V_20 ] . V_309 == V_309 ) {
V_34 = 0 ;
break;
}
if ( V_34 )
return V_34 ;
V_319 = F_79 ( sizeof( * V_304 ) + ( ( V_304 -> V_305 - 1 ) *
sizeof( struct V_312 ) ) , V_37 ) ;
if ( ! V_319 )
return - V_39 ;
memcpy ( V_319 , V_304 , sizeof( * V_304 ) + V_20 * sizeof( struct V_312 ) ) ;
V_319 -> V_305 -- ;
memcpy ( V_319 -> V_308 + V_20 , V_304 -> V_308 + V_20 + 1 ,
( V_319 -> V_305 - V_20 ) * sizeof( struct V_312 ) ) ;
F_12 ( V_18 -> V_71 [ V_318 ] , V_319 ) ;
F_129 ( & V_18 -> V_50 ) ;
F_90 ( V_304 ) ;
return V_34 ;
}
static int F_324 ( void * V_322 , T_11 * V_298 )
{
unsigned V_168 = ( long ) V_322 ;
struct V_18 * V_18 ;
* V_298 = 0 ;
F_85 ( & V_79 ) ;
F_325 ( V_18 , & V_80 , V_80 )
* V_298 += * ( T_7 * ) ( ( void * ) V_18 + V_168 ) ;
F_87 ( & V_79 ) ;
return 0 ;
}
static int F_326 ( void * V_322 , T_11 * V_298 )
{
unsigned V_168 = ( long ) V_322 ;
struct V_18 * V_18 ;
struct V_6 * V_7 ;
int V_20 ;
* V_298 = 0 ;
F_85 ( & V_79 ) ;
F_325 (kvm, &vm_list, vm_list)
F_28 ( V_20 , V_7 , V_18 )
* V_298 += * ( T_7 * ) ( ( void * ) V_7 + V_168 ) ;
F_87 ( & V_79 ) ;
return 0 ;
}
static int F_327 ( void )
{
int V_34 = - V_131 ;
struct V_323 * V_245 ;
V_324 = F_328 ( L_8 , NULL ) ;
if ( V_324 == NULL )
goto V_110;
for ( V_245 = V_325 ; V_245 -> V_326 ; ++ V_245 ) {
V_245 -> V_327 = F_329 ( V_245 -> V_326 , 0444 , V_324 ,
( void * ) ( long ) V_245 -> V_168 ,
V_328 [ V_245 -> V_329 ] ) ;
if ( V_245 -> V_327 == NULL )
goto V_330;
}
return 0 ;
V_330:
F_330 ( V_324 ) ;
V_110:
return V_34 ;
}
static void F_331 ( void )
{
struct V_323 * V_245 ;
for ( V_245 = V_325 ; V_245 -> V_326 ; ++ V_245 )
F_332 ( V_245 -> V_327 ) ;
F_332 ( V_324 ) ;
}
static int F_333 ( void )
{
if ( V_295 )
F_304 ( NULL ) ;
return 0 ;
}
static void F_334 ( void )
{
if ( V_295 ) {
F_180 ( F_335 ( & V_79 ) ) ;
F_297 ( NULL ) ;
}
}
static inline
struct V_6 * F_336 ( struct V_16 * V_331 )
{
return F_50 ( V_331 , struct V_6 , V_16 ) ;
}
static void F_337 ( struct V_16 * V_331 , int V_8 )
{
struct V_6 * V_7 = F_336 ( V_331 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_338 ( struct V_16 * V_331 ,
struct V_145 * V_332 )
{
struct V_6 * V_7 = F_336 ( V_331 ) ;
F_21 ( V_7 ) ;
}
int F_339 ( void * V_333 , unsigned V_334 , unsigned V_335 ,
struct V_336 * V_336 )
{
int V_34 ;
int V_8 ;
V_34 = F_340 ( V_333 ) ;
if ( V_34 )
goto V_337;
V_133 = F_43 ( V_37 | V_38 ) ;
if ( V_133 == NULL ) {
V_34 = - V_39 ;
goto V_110;
}
V_136 = F_169 ( V_133 ) ;
V_134 = F_43 ( V_37 | V_38 ) ;
if ( V_134 == NULL ) {
V_34 = - V_39 ;
goto V_338;
}
V_137 = F_169 ( V_134 ) ;
V_135 = F_43 ( V_37 | V_38 ) ;
if ( V_135 == NULL ) {
V_34 = - V_39 ;
goto V_338;
}
V_138 = F_169 ( V_135 ) ;
if ( ! F_27 ( & V_292 , V_37 ) ) {
V_34 = - V_39 ;
goto V_338;
}
V_34 = F_341 () ;
if ( V_34 < 0 )
goto V_339;
F_342 (cpu) {
F_343 ( V_8 ,
V_340 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_341;
}
V_34 = F_344 ( & V_342 ) ;
if ( V_34 )
goto V_343;
F_345 ( & V_344 ) ;
if ( ! V_335 )
V_335 = F_346 ( struct V_6 ) ;
V_345 = F_347 ( L_9 , V_334 , V_335 ,
0 , NULL ) ;
if ( ! V_345 ) {
V_34 = - V_39 ;
goto V_346;
}
V_34 = F_348 () ;
if ( V_34 )
goto V_120;
V_347 . V_348 = V_336 ;
V_274 . V_348 = V_336 ;
V_199 . V_348 = V_336 ;
V_34 = F_349 ( & V_349 ) ;
if ( V_34 ) {
F_302 ( V_350 L_10 ) ;
goto V_351;
}
F_350 ( & V_352 ) ;
V_202 . V_353 = F_337 ;
V_202 . V_354 = F_338 ;
V_34 = F_327 () ;
if ( V_34 ) {
F_302 ( V_350 L_11 ) ;
goto V_355;
}
return 0 ;
V_355:
F_351 ( & V_352 ) ;
V_351:
F_352 () ;
V_120:
F_353 ( V_345 ) ;
V_346:
F_354 ( & V_344 ) ;
F_355 ( & V_342 ) ;
V_343:
V_341:
F_356 () ;
V_339:
F_35 ( V_292 ) ;
V_338:
if ( V_135 )
F_357 ( V_135 ) ;
if ( V_134 )
F_357 ( V_134 ) ;
F_357 ( V_133 ) ;
V_110:
F_358 () ;
V_337:
return V_34 ;
}
void F_359 ( void )
{
F_331 () ;
F_360 ( & V_349 ) ;
F_353 ( V_345 ) ;
F_352 () ;
F_351 ( & V_352 ) ;
F_354 ( & V_344 ) ;
F_355 ( & V_342 ) ;
F_308 ( F_304 , NULL , 1 ) ;
F_356 () ;
F_358 () ;
F_35 ( V_292 ) ;
F_357 ( V_135 ) ;
F_357 ( V_134 ) ;
F_357 ( V_133 ) ;
}
