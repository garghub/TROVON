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
static void F_92 ( struct V_81 * V_82 )
{
if ( ! V_82 -> V_83 )
return;
if ( 2 * F_93 ( V_82 ) > V_57 )
F_94 ( V_82 -> V_84 ) ;
else
F_90 ( V_82 -> V_84 ) ;
V_82 -> V_83 = NULL ;
V_82 -> V_84 = NULL ;
}
static void F_95 ( struct V_81 * free ,
struct V_81 * V_85 )
{
if ( ! V_85 || free -> V_86 != V_85 -> V_86 )
F_94 ( free -> V_86 ) ;
if ( ! V_85 || free -> V_83 != V_85 -> V_83 )
F_92 ( free ) ;
F_96 ( free , V_85 ) ;
free -> V_87 = 0 ;
free -> V_86 = NULL ;
}
void F_97 ( struct V_18 * V_18 )
{
struct V_61 * V_62 = V_18 -> V_63 ;
struct V_81 * V_82 ;
F_98 (memslot, slots)
F_95 ( V_82 , NULL ) ;
F_90 ( V_18 -> V_63 ) ;
}
static void F_99 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_45 * V_46 = V_18 -> V_46 ;
F_100 ( V_18 ) ;
F_85 ( & V_79 ) ;
F_101 ( & V_18 -> V_80 ) ;
F_87 ( & V_79 ) ;
F_102 ( V_18 ) ;
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ )
F_103 ( V_18 -> V_71 [ V_20 ] ) ;
F_104 ( V_18 ) ;
#if F_105 ( V_88 ) && F_105 ( V_89 )
F_106 ( & V_18 -> V_43 , V_18 -> V_46 ) ;
#else
F_68 ( V_18 ) ;
#endif
F_107 ( V_18 ) ;
F_97 ( V_18 ) ;
F_88 ( & V_18 -> V_50 ) ;
F_91 ( V_18 ) ;
F_89 () ;
F_108 ( V_46 ) ;
}
void F_109 ( struct V_18 * V_18 )
{
F_82 ( & V_18 -> V_78 ) ;
}
void F_110 ( struct V_18 * V_18 )
{
if ( F_111 ( & V_18 -> V_78 ) )
F_99 ( V_18 ) ;
}
static int F_112 ( struct V_90 * V_90 , struct V_91 * V_92 )
{
struct V_18 * V_18 = V_92 -> V_93 ;
F_113 ( V_18 ) ;
F_110 ( V_18 ) ;
return 0 ;
}
static int F_114 ( struct V_81 * V_82 )
{
#ifndef F_115
unsigned long V_94 = 2 * F_93 ( V_82 ) ;
if ( V_94 > V_57 )
V_82 -> V_83 = F_116 ( V_94 ) ;
else
V_82 -> V_83 = F_79 ( V_94 , V_37 ) ;
if ( ! V_82 -> V_83 )
return - V_39 ;
V_82 -> V_84 = V_82 -> V_83 ;
V_82 -> V_95 = 0 ;
#endif
return 0 ;
}
static int F_117 ( const void * V_96 , const void * V_97 )
{
struct V_81 * V_98 , * V_99 ;
V_98 = (struct V_81 * ) V_96 ;
V_99 = (struct V_81 * ) V_97 ;
if ( V_98 -> V_87 < V_99 -> V_87 )
return 1 ;
if ( V_98 -> V_87 > V_99 -> V_87 )
return - 1 ;
return 0 ;
}
static void F_118 ( struct V_61 * V_62 )
{
int V_20 ;
F_119 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_81 ) , F_117 , NULL ) ;
for ( V_20 = 0 ; V_20 < V_64 ; V_20 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_20 ] . V_33 ] = V_20 ;
}
void F_120 ( struct V_61 * V_62 , struct V_81 * V_100 )
{
if ( V_100 ) {
int V_33 = V_100 -> V_33 ;
struct V_81 * V_101 = F_121 ( V_62 , V_33 ) ;
unsigned long V_87 = V_101 -> V_87 ;
* V_101 = * V_100 ;
if ( V_100 -> V_87 != V_87 )
F_118 ( V_62 ) ;
}
V_62 -> V_102 ++ ;
}
int F_122 ( struct V_18 * V_18 ,
struct V_103 * V_104 ,
int V_105 )
{
int V_34 ;
T_4 V_106 ;
unsigned long V_87 ;
unsigned long V_20 ;
struct V_81 * V_82 ;
struct V_81 V_101 , V_100 ;
struct V_61 * V_62 , * V_107 ;
V_34 = - V_108 ;
if ( V_104 -> V_109 & ( V_57 - 1 ) )
goto V_110;
if ( V_104 -> V_111 & ( V_57 - 1 ) )
goto V_110;
if ( V_105 &&
( ( V_104 -> V_112 & ( V_57 - 1 ) ) ||
! F_123 ( V_113 ,
( void V_114 * ) ( unsigned long ) V_104 -> V_112 ,
V_104 -> V_109 ) ) )
goto V_110;
if ( V_104 -> V_115 >= V_64 )
goto V_110;
if ( V_104 -> V_111 + V_104 -> V_109 < V_104 -> V_111 )
goto V_110;
V_82 = F_121 ( V_18 -> V_63 , V_104 -> V_115 ) ;
V_106 = V_104 -> V_111 >> V_116 ;
V_87 = V_104 -> V_109 >> V_116 ;
V_34 = - V_108 ;
if ( V_87 > V_117 )
goto V_110;
if ( ! V_87 )
V_104 -> V_118 &= ~ V_119 ;
V_100 = V_101 = * V_82 ;
V_100 . V_33 = V_104 -> V_115 ;
V_100 . V_106 = V_106 ;
V_100 . V_87 = V_87 ;
V_100 . V_118 = V_104 -> V_118 ;
V_34 = - V_108 ;
if ( V_87 && V_101 . V_87 && V_87 != V_101 . V_87 )
goto V_120;
V_34 = - V_121 ;
for ( V_20 = 0 ; V_20 < V_122 ; ++ V_20 ) {
struct V_81 * V_123 = & V_18 -> V_63 -> V_63 [ V_20 ] ;
if ( V_123 == V_82 || ! V_123 -> V_87 )
continue;
if ( ! ( ( V_106 + V_87 <= V_123 -> V_106 ) ||
( V_106 >= V_123 -> V_106 + V_123 -> V_87 ) ) )
goto V_120;
}
if ( ! ( V_100 . V_118 & V_119 ) )
V_100 . V_83 = NULL ;
V_34 = - V_39 ;
if ( V_87 && ! V_101 . V_87 ) {
V_100 . V_105 = V_105 ;
V_100 . V_112 = V_104 -> V_112 ;
#ifndef F_115
V_100 . V_86 = F_116 ( V_87 * sizeof( * V_100 . V_86 ) ) ;
if ( ! V_100 . V_86 )
goto V_120;
#endif
if ( F_124 ( & V_100 , V_87 ) )
goto V_120;
}
if ( ( V_100 . V_118 & V_119 ) && ! V_100 . V_83 ) {
if ( F_114 ( & V_100 ) < 0 )
goto V_120;
}
if ( ! V_87 ) {
struct V_81 * V_115 ;
V_34 = - V_39 ;
V_62 = F_125 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_120;
V_115 = F_121 ( V_62 , V_104 -> V_115 ) ;
V_115 -> V_118 |= V_124 ;
F_120 ( V_62 , NULL ) ;
V_107 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_68 ( V_18 ) ;
F_90 ( V_107 ) ;
}
V_34 = F_127 ( V_18 , & V_100 , V_101 , V_104 , V_105 ) ;
if ( V_34 )
goto V_120;
if ( V_87 ) {
V_34 = F_128 ( V_18 , & V_100 ) ;
if ( V_34 )
goto V_120;
} else
F_129 ( V_18 , & V_101 ) ;
V_34 = - V_39 ;
V_62 = F_125 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_120;
if ( ! V_87 ) {
V_100 . V_86 = NULL ;
V_100 . V_83 = NULL ;
memset ( & V_100 . V_125 , 0 , sizeof( V_100 . V_125 ) ) ;
}
F_120 ( V_62 , & V_100 ) ;
V_107 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_130 ( V_18 , V_104 , V_101 , V_105 ) ;
if ( V_87 && V_101 . V_106 != V_104 -> V_111 >> V_116 )
F_68 ( V_18 ) ;
F_95 ( & V_101 , & V_100 ) ;
F_90 ( V_107 ) ;
return 0 ;
V_120:
F_95 ( & V_100 , & V_101 ) ;
V_110:
return V_34 ;
}
int F_131 ( struct V_18 * V_18 ,
struct V_103 * V_104 ,
int V_105 )
{
int V_34 ;
F_9 ( & V_18 -> V_77 ) ;
V_34 = F_122 ( V_18 , V_104 , V_105 ) ;
F_24 ( & V_18 -> V_77 ) ;
return V_34 ;
}
int F_132 ( struct V_18 * V_18 ,
struct
V_103 * V_104 ,
int V_105 )
{
if ( V_104 -> V_115 >= V_122 )
return - V_108 ;
return F_131 ( V_18 , V_104 , V_105 ) ;
}
int F_133 ( struct V_18 * V_18 ,
struct V_126 * log , int * V_127 )
{
struct V_81 * V_82 ;
int V_34 , V_20 ;
unsigned long V_128 ;
unsigned long V_129 = 0 ;
V_34 = - V_108 ;
if ( log -> V_115 >= V_122 )
goto V_110;
V_82 = F_121 ( V_18 -> V_63 , log -> V_115 ) ;
V_34 = - V_130 ;
if ( ! V_82 -> V_83 )
goto V_110;
V_128 = F_93 ( V_82 ) ;
for ( V_20 = 0 ; ! V_129 && V_20 < V_128 / sizeof( long ) ; ++ V_20 )
V_129 = V_82 -> V_83 [ V_20 ] ;
V_34 = - V_131 ;
if ( F_134 ( log -> V_83 , V_82 -> V_83 , V_128 ) )
goto V_110;
if ( V_129 )
* V_127 = 1 ;
V_34 = 0 ;
V_110:
return V_34 ;
}
bool F_135 ( void )
{
return V_132 ;
}
void F_136 ( void )
{
V_132 = false ;
}
int F_137 ( struct V_3 * V_3 )
{
return V_3 == V_133 || V_3 == V_134 || V_3 == V_135 ;
}
int F_138 ( T_1 V_1 )
{
return V_1 == V_136 || V_1 == V_137 || V_1 == V_138 ;
}
int F_139 ( T_1 V_1 )
{
return V_1 == V_137 ;
}
int F_140 ( T_1 V_1 )
{
return V_1 == V_138 ;
}
int F_141 ( T_1 V_1 )
{
return V_1 == V_136 ;
}
int F_142 ( T_1 V_1 )
{
return V_1 == V_137 || V_1 == V_138 ;
}
static inline unsigned long F_143 ( void )
{
return V_139 ;
}
int F_144 ( unsigned long V_140 )
{
return V_140 == F_143 () ;
}
struct V_81 * F_145 ( struct V_18 * V_18 , T_4 V_141 )
{
return F_146 ( V_61 ( V_18 ) , V_141 ) ;
}
int F_147 ( struct V_18 * V_18 , T_4 V_141 )
{
struct V_81 * V_82 = F_145 ( V_18 , V_141 ) ;
if ( ! V_82 || V_82 -> V_33 >= V_122 ||
V_82 -> V_118 & V_124 )
return 0 ;
return 1 ;
}
unsigned long F_148 ( struct V_18 * V_18 , T_4 V_141 )
{
struct V_142 * V_143 ;
unsigned long V_140 , V_144 ;
V_144 = V_57 ;
V_140 = F_149 ( V_18 , V_141 ) ;
if ( F_144 ( V_140 ) )
return V_57 ;
F_150 ( & V_11 -> V_46 -> V_145 ) ;
V_143 = F_151 ( V_11 -> V_46 , V_140 ) ;
if ( ! V_143 )
goto V_110;
V_144 = F_152 ( V_143 ) ;
V_110:
F_153 ( & V_11 -> V_46 -> V_145 ) ;
return V_144 ;
}
static unsigned long F_154 ( struct V_81 * V_115 , T_4 V_141 ,
T_4 * V_146 )
{
if ( ! V_115 || V_115 -> V_118 & V_124 )
return F_143 () ;
if ( V_146 )
* V_146 = V_115 -> V_87 - ( V_141 - V_115 -> V_106 ) ;
return F_155 ( V_115 , V_141 ) ;
}
unsigned long F_149 ( struct V_18 * V_18 , T_4 V_141 )
{
return F_154 ( F_145 ( V_18 , V_141 ) , V_141 , NULL ) ;
}
static T_1 F_156 ( void )
{
F_157 ( V_135 ) ;
return V_138 ;
}
int F_158 ( struct V_147 * V_148 , struct V_45 * V_46 ,
unsigned long V_54 , int V_149 , struct V_3 * * V_3 )
{
int V_118 = V_150 | V_151 | V_152 | V_153 ;
if ( V_149 )
V_118 |= V_154 ;
return F_159 ( V_148 , V_46 , V_54 , 1 , V_118 , V_3 , NULL , NULL ) ;
}
static inline int F_160 ( unsigned long V_140 )
{
int V_155 , V_118 = V_150 | V_152 | V_154 ;
V_155 = F_159 ( V_11 , V_11 -> V_46 , V_140 , 1 ,
V_118 , NULL , NULL , NULL ) ;
return V_155 == - V_156 ;
}
static T_1 F_161 ( struct V_18 * V_18 , unsigned long V_140 , bool V_157 ,
bool * V_158 , bool V_159 , bool * V_160 )
{
struct V_3 * V_3 [ 1 ] ;
int V_87 = 0 ;
T_1 V_1 ;
F_62 ( V_157 && V_158 ) ;
F_62 ( ! V_159 && ! V_160 ) ;
if ( V_160 )
* V_160 = true ;
if ( V_157 || V_158 )
V_87 = F_162 ( V_140 , 1 , 1 , V_3 ) ;
if ( F_10 ( V_87 != 1 ) && ! V_157 ) {
F_163 () ;
if ( V_160 )
* V_160 = V_159 ;
if ( V_158 ) {
F_150 ( & V_11 -> V_46 -> V_145 ) ;
V_87 = F_158 ( V_11 , V_11 -> V_46 ,
V_140 , V_159 , V_3 ) ;
F_153 ( & V_11 -> V_46 -> V_145 ) ;
} else
V_87 = F_164 ( V_140 , 1 , V_159 ,
V_3 ) ;
if ( F_10 ( ! V_159 ) && V_87 == 1 ) {
struct V_3 * V_161 [ 1 ] ;
V_87 = F_162 ( V_140 , 1 , 1 , V_161 ) ;
if ( V_87 == 1 ) {
* V_160 = true ;
F_165 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_161 [ 0 ] ;
}
V_87 = 1 ;
}
}
if ( F_10 ( V_87 != 1 ) ) {
struct V_142 * V_143 ;
if ( V_157 )
return F_156 () ;
F_150 ( & V_11 -> V_46 -> V_145 ) ;
if ( V_87 == - V_156 ||
( ! V_158 && F_160 ( V_140 ) ) ) {
F_153 ( & V_11 -> V_46 -> V_145 ) ;
F_157 ( V_134 ) ;
return F_166 ( V_134 ) ;
}
V_143 = F_167 ( V_11 -> V_46 , V_140 , V_140 + 1 ) ;
if ( V_143 == NULL )
V_1 = F_156 () ;
else if ( ( V_143 -> V_162 & V_163 ) ) {
V_1 = ( ( V_140 - V_143 -> V_164 ) >> V_116 ) +
V_143 -> V_165 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_158 && ( V_143 -> V_162 & V_166 ) )
* V_158 = true ;
V_1 = F_156 () ;
}
F_153 ( & V_11 -> V_46 -> V_145 ) ;
} else
V_1 = F_166 ( V_3 [ 0 ] ) ;
return V_1 ;
}
T_1 F_168 ( struct V_18 * V_18 , unsigned long V_140 )
{
return F_161 ( V_18 , V_140 , true , NULL , true , NULL ) ;
}
static T_1 F_169 ( struct V_18 * V_18 , T_4 V_141 , bool V_157 , bool * V_158 ,
bool V_159 , bool * V_160 )
{
unsigned long V_140 ;
if ( V_158 )
* V_158 = false ;
V_140 = F_149 ( V_18 , V_141 ) ;
if ( F_144 ( V_140 ) ) {
F_157 ( V_133 ) ;
return F_166 ( V_133 ) ;
}
return F_161 ( V_18 , V_140 , V_157 , V_158 , V_159 , V_160 ) ;
}
T_1 F_170 ( struct V_18 * V_18 , T_4 V_141 )
{
return F_169 ( V_18 , V_141 , true , NULL , true , NULL ) ;
}
T_1 F_171 ( struct V_18 * V_18 , T_4 V_141 , bool * V_158 ,
bool V_159 , bool * V_160 )
{
return F_169 ( V_18 , V_141 , false , V_158 , V_159 , V_160 ) ;
}
T_1 F_172 ( struct V_18 * V_18 , T_4 V_141 )
{
return F_169 ( V_18 , V_141 , false , NULL , true , NULL ) ;
}
T_1 F_173 ( struct V_18 * V_18 , T_4 V_141 , bool V_159 ,
bool * V_160 )
{
return F_169 ( V_18 , V_141 , false , NULL , V_159 , V_160 ) ;
}
T_1 F_174 ( struct V_18 * V_18 ,
struct V_81 * V_115 , T_4 V_141 )
{
unsigned long V_140 = F_155 ( V_115 , V_141 ) ;
return F_161 ( V_18 , V_140 , false , NULL , true , NULL ) ;
}
int F_175 ( struct V_18 * V_18 , T_4 V_141 , struct V_3 * * V_167 ,
int V_146 )
{
unsigned long V_140 ;
T_4 V_168 ;
V_140 = F_154 ( F_145 ( V_18 , V_141 ) , V_141 , & V_168 ) ;
if ( F_144 ( V_140 ) )
return - 1 ;
if ( V_168 < V_146 )
return 0 ;
return F_162 ( V_140 , V_146 , 1 , V_167 ) ;
}
struct V_3 * F_176 ( struct V_18 * V_18 , T_4 V_141 )
{
T_1 V_1 ;
V_1 = F_172 ( V_18 , V_141 ) ;
if ( ! F_1 ( V_1 ) )
return F_3 ( V_1 ) ;
F_177 ( F_1 ( V_1 ) ) ;
F_157 ( V_133 ) ;
return V_133 ;
}
void F_178 ( struct V_3 * V_3 )
{
F_179 ( F_166 ( V_3 ) ) ;
}
void F_179 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_165 ( F_3 ( V_1 ) ) ;
}
void F_180 ( struct V_3 * V_3 )
{
F_181 ( F_166 ( V_3 ) ) ;
}
void F_181 ( T_1 V_1 )
{
F_182 ( V_1 ) ;
F_179 ( V_1 ) ;
}
void F_183 ( struct V_3 * V_3 )
{
F_182 ( F_166 ( V_3 ) ) ;
}
void F_182 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_184 ( V_3 ) ;
}
}
void F_185 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_186 ( F_3 ( V_1 ) ) ;
}
void F_187 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_157 ( F_3 ( V_1 ) ) ;
}
static int F_188 ( unsigned long V_169 , int V_170 )
{
if ( V_169 > V_57 - V_170 )
return V_57 - V_170 ;
else
return V_169 ;
}
int F_189 ( struct V_18 * V_18 , T_4 V_141 , void * V_171 , int V_170 ,
int V_169 )
{
int V_34 ;
unsigned long V_140 ;
V_140 = F_149 ( V_18 , V_141 ) ;
if ( F_144 ( V_140 ) )
return - V_131 ;
V_34 = F_190 ( V_171 , ( void V_114 * ) V_140 + V_170 , V_169 ) ;
if ( V_34 )
return - V_131 ;
return 0 ;
}
int F_191 ( struct V_18 * V_18 , T_5 V_172 , void * V_171 , unsigned long V_169 )
{
T_4 V_141 = V_172 >> V_116 ;
int V_173 ;
int V_170 = F_192 ( V_172 ) ;
int V_174 ;
while ( ( V_173 = F_188 ( V_169 , V_170 ) ) != 0 ) {
V_174 = F_189 ( V_18 , V_141 , V_171 , V_170 , V_173 ) ;
if ( V_174 < 0 )
return V_174 ;
V_170 = 0 ;
V_169 -= V_173 ;
V_171 += V_173 ;
++ V_141 ;
}
return 0 ;
}
int F_193 ( struct V_18 * V_18 , T_5 V_172 , void * V_171 ,
unsigned long V_169 )
{
int V_34 ;
unsigned long V_140 ;
T_4 V_141 = V_172 >> V_116 ;
int V_170 = F_192 ( V_172 ) ;
V_140 = F_149 ( V_18 , V_141 ) ;
if ( F_144 ( V_140 ) )
return - V_131 ;
F_194 () ;
V_34 = F_195 ( V_171 , ( void V_114 * ) V_140 + V_170 , V_169 ) ;
F_196 () ;
if ( V_34 )
return - V_131 ;
return 0 ;
}
int F_197 ( struct V_18 * V_18 , T_4 V_141 , const void * V_171 ,
int V_170 , int V_169 )
{
int V_34 ;
unsigned long V_140 ;
V_140 = F_149 ( V_18 , V_141 ) ;
if ( F_144 ( V_140 ) )
return - V_131 ;
V_34 = F_198 ( ( void V_114 * ) V_140 + V_170 , V_171 , V_169 ) ;
if ( V_34 )
return - V_131 ;
F_199 ( V_18 , V_141 ) ;
return 0 ;
}
int F_200 ( struct V_18 * V_18 , T_5 V_172 , const void * V_171 ,
unsigned long V_169 )
{
T_4 V_141 = V_172 >> V_116 ;
int V_173 ;
int V_170 = F_192 ( V_172 ) ;
int V_174 ;
while ( ( V_173 = F_188 ( V_169 , V_170 ) ) != 0 ) {
V_174 = F_197 ( V_18 , V_141 , V_171 , V_170 , V_173 ) ;
if ( V_174 < 0 )
return V_174 ;
V_170 = 0 ;
V_169 -= V_173 ;
V_171 += V_173 ;
++ V_141 ;
}
return 0 ;
}
int F_201 ( struct V_18 * V_18 , struct V_175 * V_176 ,
T_5 V_172 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_170 = F_192 ( V_172 ) ;
T_4 V_141 = V_172 >> V_116 ;
V_176 -> V_172 = V_172 ;
V_176 -> V_102 = V_62 -> V_102 ;
V_176 -> V_82 = F_145 ( V_18 , V_141 ) ;
V_176 -> V_177 = F_154 ( V_176 -> V_82 , V_141 , NULL ) ;
if ( ! F_144 ( V_176 -> V_177 ) )
V_176 -> V_177 += V_170 ;
else
return - V_131 ;
return 0 ;
}
int F_202 ( struct V_18 * V_18 , struct V_175 * V_176 ,
void * V_171 , unsigned long V_169 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_102 != V_176 -> V_102 )
F_201 ( V_18 , V_176 , V_176 -> V_172 ) ;
if ( F_144 ( V_176 -> V_177 ) )
return - V_131 ;
V_34 = F_198 ( ( void V_114 * ) V_176 -> V_177 , V_171 , V_169 ) ;
if ( V_34 )
return - V_131 ;
F_203 ( V_18 , V_176 -> V_82 , V_176 -> V_172 >> V_116 ) ;
return 0 ;
}
int F_204 ( struct V_18 * V_18 , struct V_175 * V_176 ,
void * V_171 , unsigned long V_169 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_102 != V_176 -> V_102 )
F_201 ( V_18 , V_176 , V_176 -> V_172 ) ;
if ( F_144 ( V_176 -> V_177 ) )
return - V_131 ;
V_34 = F_190 ( V_171 , ( void V_114 * ) V_176 -> V_177 , V_169 ) ;
if ( V_34 )
return - V_131 ;
return 0 ;
}
int F_205 ( struct V_18 * V_18 , T_4 V_141 , int V_170 , int V_169 )
{
return F_197 ( V_18 , V_141 , ( const void * ) V_178 ,
V_170 , V_169 ) ;
}
int F_206 ( struct V_18 * V_18 , T_5 V_172 , unsigned long V_169 )
{
T_4 V_141 = V_172 >> V_116 ;
int V_173 ;
int V_170 = F_192 ( V_172 ) ;
int V_174 ;
while ( ( V_173 = F_188 ( V_169 , V_170 ) ) != 0 ) {
V_174 = F_205 ( V_18 , V_141 , V_170 , V_173 ) ;
if ( V_174 < 0 )
return V_174 ;
V_170 = 0 ;
V_169 -= V_173 ;
++ V_141 ;
}
return 0 ;
}
void F_203 ( struct V_18 * V_18 , struct V_81 * V_82 ,
T_4 V_141 )
{
if ( V_82 && V_82 -> V_83 ) {
unsigned long V_179 = V_141 - V_82 -> V_106 ;
if ( ! F_207 ( V_179 , V_82 -> V_83 ) )
V_82 -> V_95 ++ ;
}
}
void F_199 ( struct V_18 * V_18 , T_4 V_141 )
{
struct V_81 * V_82 ;
V_82 = F_145 ( V_18 , V_141 ) ;
F_203 ( V_18 , V_82 , V_141 ) ;
}
void F_208 ( struct V_6 * V_7 )
{
F_209 ( V_180 ) ;
for (; ; ) {
F_210 ( & V_7 -> V_36 , & V_180 , V_181 ) ;
if ( F_211 ( V_7 ) ) {
F_29 ( V_182 , V_7 ) ;
break;
}
if ( F_212 ( V_7 ) )
break;
if ( F_213 ( V_11 ) )
break;
F_214 () ;
}
F_215 ( & V_7 -> V_36 , & V_180 ) ;
}
void F_216 ( struct V_6 * V_7 )
{
if ( ! F_217 () )
return;
F_218 () ;
}
void F_219 ( struct V_6 * V_21 )
{
struct V_18 * V_18 = V_21 -> V_18 ;
struct V_6 * V_7 ;
int V_183 = V_21 -> V_18 -> V_183 ;
int V_184 = 0 ;
int V_185 ;
int V_20 ;
for ( V_185 = 0 ; V_185 < 2 && ! V_184 ; V_185 ++ ) {
F_28 (i, vcpu, kvm) {
struct V_147 * V_186 = NULL ;
struct V_10 * V_10 ;
if ( ! V_185 && V_20 < V_183 ) {
V_20 = V_183 ;
continue;
} else if ( V_185 && V_20 > V_183 )
break;
if ( V_7 == V_21 )
continue;
if ( F_220 ( & V_7 -> V_36 ) )
continue;
F_221 () ;
V_10 = F_222 ( V_7 -> V_10 ) ;
if ( V_10 )
V_186 = F_223 ( V_7 -> V_10 , V_13 ) ;
F_224 () ;
if ( ! V_186 )
continue;
if ( V_186 -> V_118 & V_187 ) {
F_225 ( V_186 ) ;
continue;
}
if ( F_226 ( V_186 , 1 ) ) {
F_225 ( V_186 ) ;
V_18 -> V_183 = V_20 ;
V_184 = 1 ;
break;
}
F_225 ( V_186 ) ;
}
}
}
static int F_227 ( struct V_142 * V_143 , struct V_188 * V_189 )
{
struct V_6 * V_7 = V_143 -> V_190 -> V_93 ;
struct V_3 * V_3 ;
if ( V_189 -> V_191 == 0 )
V_3 = F_228 ( V_7 -> V_41 ) ;
#ifdef F_229
else if ( V_189 -> V_191 == V_192 )
V_3 = F_228 ( V_7 -> V_125 . V_193 ) ;
#endif
#ifdef F_230
else if ( V_189 -> V_191 == F_230 )
V_3 = F_228 ( V_7 -> V_18 -> V_194 ) ;
#endif
else
return F_231 ( V_7 , V_189 ) ;
F_157 ( V_3 ) ;
V_189 -> V_3 = V_3 ;
return 0 ;
}
static int F_232 ( struct V_91 * V_91 , struct V_142 * V_143 )
{
V_143 -> V_195 = & V_196 ;
return 0 ;
}
static int F_233 ( struct V_90 * V_90 , struct V_91 * V_92 )
{
struct V_6 * V_7 = V_92 -> V_93 ;
F_110 ( V_7 -> V_18 ) ;
return 0 ;
}
static int F_234 ( struct V_6 * V_7 )
{
return F_235 ( L_1 , & V_197 , V_7 , V_198 ) ;
}
static int F_236 ( struct V_18 * V_18 , T_6 V_33 )
{
int V_34 ;
struct V_6 * V_7 , * V_199 ;
V_7 = F_237 ( V_18 , V_33 ) ;
if ( F_238 ( V_7 ) )
return F_239 ( V_7 ) ;
F_240 ( & V_7 -> V_16 , & V_200 ) ;
V_34 = F_241 ( V_7 ) ;
if ( V_34 )
goto V_201;
F_9 ( & V_18 -> V_75 ) ;
if ( ! F_242 ( V_7 ) ) {
V_34 = - V_108 ;
goto V_202;
}
if ( F_243 ( & V_18 -> V_203 ) == V_204 ) {
V_34 = - V_108 ;
goto V_202;
}
F_28 (r, v, kvm)
if ( V_199 -> V_35 == V_33 ) {
V_34 = - V_121 ;
goto V_202;
}
F_62 ( V_18 -> V_205 [ F_243 ( & V_18 -> V_203 ) ] ) ;
F_109 ( V_18 ) ;
V_34 = F_234 ( V_7 ) ;
if ( V_34 < 0 ) {
F_110 ( V_18 ) ;
goto V_202;
}
V_18 -> V_205 [ F_243 ( & V_18 -> V_203 ) ] = V_7 ;
F_61 () ;
F_82 ( & V_18 -> V_203 ) ;
F_24 ( & V_18 -> V_75 ) ;
return V_34 ;
V_202:
F_24 ( & V_18 -> V_75 ) ;
V_201:
F_244 ( V_7 ) ;
return V_34 ;
}
static int F_245 ( struct V_6 * V_7 , T_7 * V_206 )
{
if ( V_206 ) {
F_246 ( V_206 , F_247 ( V_207 ) | F_247 ( V_208 ) ) ;
V_7 -> V_209 = 1 ;
V_7 -> V_206 = * V_206 ;
} else
V_7 -> V_209 = 0 ;
return 0 ;
}
static long F_248 ( struct V_91 * V_92 ,
unsigned int V_210 , unsigned long V_211 )
{
struct V_6 * V_7 = V_92 -> V_93 ;
void V_114 * V_212 = ( void V_114 * ) V_211 ;
int V_34 ;
struct V_213 * V_214 = NULL ;
struct V_215 * V_215 = NULL ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_216 ;
#if F_105 ( F_115 ) || F_105 ( V_217 )
if ( V_210 == V_218 || V_210 == V_219 )
return F_249 ( V_92 , V_210 , V_211 ) ;
#endif
F_8 ( V_7 ) ;
switch ( V_210 ) {
case V_220 :
V_34 = - V_108 ;
if ( V_211 )
goto V_110;
V_34 = F_250 ( V_7 , V_7 -> V_41 ) ;
F_251 ( V_7 -> V_41 -> V_221 , V_34 ) ;
break;
case V_222 : {
struct V_223 * V_223 ;
V_34 = - V_39 ;
V_223 = F_79 ( sizeof( struct V_223 ) , V_37 ) ;
if ( ! V_223 )
goto V_110;
V_34 = F_252 ( V_7 , V_223 ) ;
if ( V_34 )
goto V_224;
V_34 = - V_131 ;
if ( F_134 ( V_212 , V_223 , sizeof( struct V_223 ) ) )
goto V_224;
V_34 = 0 ;
V_224:
F_90 ( V_223 ) ;
break;
}
case V_225 : {
struct V_223 * V_223 ;
V_34 = - V_39 ;
V_223 = F_253 ( V_212 , sizeof( * V_223 ) ) ;
if ( F_238 ( V_223 ) ) {
V_34 = F_239 ( V_223 ) ;
goto V_110;
}
V_34 = F_254 ( V_7 , V_223 ) ;
if ( V_34 )
goto V_226;
V_34 = 0 ;
V_226:
F_90 ( V_223 ) ;
break;
}
case V_227 : {
V_215 = F_79 ( sizeof( struct V_215 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_215 )
goto V_110;
V_34 = F_255 ( V_7 , V_215 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_134 ( V_212 , V_215 , sizeof( struct V_215 ) ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_228 : {
V_215 = F_253 ( V_212 , sizeof( * V_215 ) ) ;
if ( F_238 ( V_215 ) ) {
V_34 = F_239 ( V_215 ) ;
goto V_110;
}
V_34 = F_256 ( V_7 , V_215 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_229 : {
struct V_230 V_231 ;
V_34 = F_257 ( V_7 , & V_231 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_134 ( V_212 , & V_231 , sizeof V_231 ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_232 : {
struct V_230 V_231 ;
V_34 = - V_131 ;
if ( F_258 ( & V_231 , V_212 , sizeof V_231 ) )
goto V_110;
V_34 = F_259 ( V_7 , & V_231 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_233 : {
struct V_234 V_235 ;
V_34 = - V_131 ;
if ( F_258 ( & V_235 , V_212 , sizeof V_235 ) )
goto V_110;
V_34 = F_260 ( V_7 , & V_235 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_134 ( V_212 , & V_235 , sizeof V_235 ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_236 : {
struct V_237 V_238 ;
V_34 = - V_131 ;
if ( F_258 ( & V_238 , V_212 , sizeof V_238 ) )
goto V_110;
V_34 = F_261 ( V_7 , & V_238 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_239 : {
struct V_240 V_114 * V_241 = V_212 ;
struct V_240 V_242 ;
T_7 V_206 , * V_243 ;
V_243 = NULL ;
if ( V_212 ) {
V_34 = - V_131 ;
if ( F_258 ( & V_242 , V_212 ,
sizeof V_242 ) )
goto V_110;
V_34 = - V_108 ;
if ( V_242 . V_169 != sizeof V_206 )
goto V_110;
V_34 = - V_131 ;
if ( F_258 ( & V_206 , V_241 -> V_206 ,
sizeof V_206 ) )
goto V_110;
V_243 = & V_206 ;
}
V_34 = F_245 ( V_7 , V_243 ) ;
break;
}
case V_244 : {
V_214 = F_79 ( sizeof( struct V_213 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_214 )
goto V_110;
V_34 = F_262 ( V_7 , V_214 ) ;
if ( V_34 )
goto V_110;
V_34 = - V_131 ;
if ( F_134 ( V_212 , V_214 , sizeof( struct V_213 ) ) )
goto V_110;
V_34 = 0 ;
break;
}
case V_245 : {
V_214 = F_253 ( V_212 , sizeof( * V_214 ) ) ;
if ( F_238 ( V_214 ) ) {
V_34 = F_239 ( V_214 ) ;
goto V_110;
}
V_34 = F_263 ( V_7 , V_214 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
default:
V_34 = F_249 ( V_92 , V_210 , V_211 ) ;
}
V_110:
F_19 ( V_7 ) ;
F_90 ( V_214 ) ;
F_90 ( V_215 ) ;
return V_34 ;
}
static long F_264 ( struct V_91 * V_92 ,
unsigned int V_210 , unsigned long V_211 )
{
struct V_6 * V_7 = V_92 -> V_93 ;
void V_114 * V_212 = F_265 ( V_211 ) ;
int V_34 ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_216 ;
switch ( V_210 ) {
case V_239 : {
struct V_240 V_114 * V_241 = V_212 ;
struct V_240 V_242 ;
T_8 V_246 ;
T_7 V_206 ;
if ( V_212 ) {
V_34 = - V_131 ;
if ( F_258 ( & V_242 , V_212 ,
sizeof V_242 ) )
goto V_110;
V_34 = - V_108 ;
if ( V_242 . V_169 != sizeof V_246 )
goto V_110;
V_34 = - V_131 ;
if ( F_258 ( & V_246 , V_241 -> V_206 ,
sizeof V_246 ) )
goto V_110;
}
F_266 ( & V_206 , & V_246 ) ;
V_34 = F_245 ( V_7 , & V_206 ) ;
break;
}
default:
V_34 = F_248 ( V_92 , V_210 , V_211 ) ;
}
V_110:
return V_34 ;
}
static long F_267 ( struct V_91 * V_92 ,
unsigned int V_210 , unsigned long V_211 )
{
struct V_18 * V_18 = V_92 -> V_93 ;
void V_114 * V_212 = ( void V_114 * ) V_211 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_216 ;
switch ( V_210 ) {
case V_247 :
V_34 = F_236 ( V_18 , V_211 ) ;
if ( V_34 < 0 )
goto V_110;
break;
case V_248 : {
struct V_103 V_249 ;
V_34 = - V_131 ;
if ( F_258 ( & V_249 , V_212 ,
sizeof V_249 ) )
goto V_110;
V_34 = F_132 ( V_18 , & V_249 , 1 ) ;
if ( V_34 )
goto V_110;
break;
}
case V_250 : {
struct V_126 log ;
V_34 = - V_131 ;
if ( F_258 ( & log , V_212 , sizeof log ) )
goto V_110;
V_34 = F_268 ( V_18 , & log ) ;
if ( V_34 )
goto V_110;
break;
}
#ifdef F_230
case V_251 : {
struct V_252 V_253 ;
V_34 = - V_131 ;
if ( F_258 ( & V_253 , V_212 , sizeof V_253 ) )
goto V_110;
V_34 = F_269 ( V_18 , & V_253 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
case V_254 : {
struct V_252 V_253 ;
V_34 = - V_131 ;
if ( F_258 ( & V_253 , V_212 , sizeof V_253 ) )
goto V_110;
V_34 = F_270 ( V_18 , & V_253 ) ;
if ( V_34 )
goto V_110;
V_34 = 0 ;
break;
}
#endif
case V_255 : {
struct V_256 V_171 ;
V_34 = - V_131 ;
if ( F_258 ( & V_171 , V_212 , sizeof V_171 ) )
goto V_110;
V_34 = V_256 ( V_18 , V_171 . V_257 , V_171 . V_258 , V_171 . V_118 ) ;
break;
}
case V_259 : {
struct V_260 V_171 ;
V_34 = - V_131 ;
if ( F_258 ( & V_171 , V_212 , sizeof V_171 ) )
goto V_110;
V_34 = V_260 ( V_18 , & V_171 ) ;
break;
}
#ifdef F_271
case V_261 :
V_34 = 0 ;
F_9 ( & V_18 -> V_75 ) ;
if ( F_243 ( & V_18 -> V_203 ) != 0 )
V_34 = - V_262 ;
else
V_18 -> V_263 = V_211 ;
F_24 ( & V_18 -> V_75 ) ;
break;
#endif
default:
V_34 = F_272 ( V_92 , V_210 , V_211 ) ;
if ( V_34 == - V_264 )
V_34 = F_273 ( V_18 , V_210 , V_211 ) ;
}
V_110:
return V_34 ;
}
static long F_274 ( struct V_91 * V_92 ,
unsigned int V_210 , unsigned long V_211 )
{
struct V_18 * V_18 = V_92 -> V_93 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_216 ;
switch ( V_210 ) {
case V_250 : {
struct V_265 V_266 ;
struct V_126 log ;
V_34 = - V_131 ;
if ( F_258 ( & V_266 , ( void V_114 * ) V_211 ,
sizeof( V_266 ) ) )
goto V_110;
log . V_115 = V_266 . V_115 ;
log . V_267 = V_266 . V_267 ;
log . V_268 = V_266 . V_268 ;
log . V_83 = F_265 ( V_266 . V_83 ) ;
V_34 = F_268 ( V_18 , & log ) ;
if ( V_34 )
goto V_110;
break;
}
default:
V_34 = F_267 ( V_92 , V_210 , V_211 ) ;
}
V_110:
return V_34 ;
}
static int F_275 ( struct V_142 * V_143 , struct V_188 * V_189 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_140 ;
int V_87 ;
T_4 V_141 = V_189 -> V_191 ;
struct V_18 * V_18 = V_143 -> V_190 -> V_93 ;
V_140 = F_149 ( V_18 , V_141 ) ;
if ( F_144 ( V_140 ) )
return V_269 ;
V_87 = F_276 ( V_11 , V_11 -> V_46 , V_140 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_87 != 1 ) )
return V_269 ;
V_189 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_277 ( struct V_91 * V_91 , struct V_142 * V_143 )
{
V_143 -> V_195 = & V_270 ;
return 0 ;
}
static int F_278 ( unsigned long type )
{
int V_34 ;
struct V_18 * V_18 ;
V_18 = F_72 ( type ) ;
if ( F_238 ( V_18 ) )
return F_239 ( V_18 ) ;
#ifdef F_230
V_34 = F_279 ( V_18 ) ;
if ( V_34 < 0 ) {
F_110 ( V_18 ) ;
return V_34 ;
}
#endif
V_34 = F_235 ( L_2 , & V_271 , V_18 , V_198 ) ;
if ( V_34 < 0 )
F_110 ( V_18 ) ;
return V_34 ;
}
static long F_280 ( long V_211 )
{
switch ( V_211 ) {
case V_272 :
case V_273 :
case V_274 :
#ifdef F_271
case V_275 :
#endif
case V_276 :
return 1 ;
#ifdef F_77
case V_277 :
return V_278 ;
#endif
default:
break;
}
return F_281 ( V_211 ) ;
}
static long F_282 ( struct V_91 * V_92 ,
unsigned int V_210 , unsigned long V_211 )
{
long V_34 = - V_108 ;
switch ( V_210 ) {
case V_279 :
V_34 = - V_108 ;
if ( V_211 )
goto V_110;
V_34 = V_280 ;
break;
case V_281 :
V_34 = F_278 ( V_211 ) ;
break;
case V_282 :
V_34 = F_280 ( V_211 ) ;
break;
case V_283 :
V_34 = - V_108 ;
if ( V_211 )
goto V_110;
V_34 = V_57 ;
#ifdef F_229
V_34 += V_57 ;
#endif
#ifdef F_230
V_34 += V_57 ;
#endif
break;
case V_284 :
case V_285 :
case V_286 :
V_34 = - V_287 ;
break;
default:
return F_283 ( V_92 , V_210 , V_211 ) ;
}
V_110:
return V_34 ;
}
static void F_284 ( void * V_288 )
{
int V_8 = F_285 () ;
int V_34 ;
if ( F_286 ( V_8 , V_289 ) )
return;
F_32 ( V_8 , V_289 ) ;
V_34 = F_287 ( NULL ) ;
if ( V_34 ) {
F_288 ( V_8 , V_289 ) ;
F_82 ( & V_290 ) ;
F_289 ( V_291 L_3
L_4 , V_8 ) ;
}
}
static void F_290 ( void * V_288 )
{
F_85 ( & V_79 ) ;
F_284 ( V_288 ) ;
F_87 ( & V_79 ) ;
}
static void F_291 ( void * V_288 )
{
int V_8 = F_285 () ;
if ( ! F_286 ( V_8 , V_289 ) )
return;
F_288 ( V_8 , V_289 ) ;
F_292 ( NULL ) ;
}
static void F_293 ( void * V_288 )
{
F_85 ( & V_79 ) ;
F_291 ( V_288 ) ;
F_87 ( & V_79 ) ;
}
static void F_294 ( void )
{
F_62 ( ! V_292 ) ;
V_292 -- ;
if ( ! V_292 )
F_295 ( F_291 , NULL , 1 ) ;
}
static void F_89 ( void )
{
F_85 ( & V_79 ) ;
F_294 () ;
F_87 ( & V_79 ) ;
}
static int F_76 ( void )
{
int V_34 = 0 ;
F_85 ( & V_79 ) ;
V_292 ++ ;
if ( V_292 == 1 ) {
F_84 ( & V_290 , 0 ) ;
F_295 ( F_284 , NULL , 1 ) ;
if ( F_243 ( & V_290 ) ) {
F_294 () ;
V_34 = - V_262 ;
}
}
F_87 ( & V_79 ) ;
return V_34 ;
}
static int F_296 ( struct V_293 * V_294 , unsigned long V_295 ,
void * V_199 )
{
int V_8 = ( long ) V_199 ;
if ( ! V_292 )
return V_296 ;
V_295 &= ~ V_297 ;
switch ( V_295 ) {
case V_298 :
F_289 ( V_291 L_5 ,
V_8 ) ;
F_293 ( NULL ) ;
break;
case V_299 :
F_289 ( V_291 L_6 ,
V_8 ) ;
F_290 ( NULL ) ;
break;
}
return V_296 ;
}
T_9 void F_297 ( void )
{
F_298 () ;
}
static int F_299 ( struct V_293 * V_294 , unsigned long V_295 ,
void * V_199 )
{
F_289 ( V_291 L_7 ) ;
V_300 = true ;
F_295 ( F_291 , NULL , 1 ) ;
return V_296 ;
}
static void F_103 ( struct V_72 * V_301 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_301 -> V_302 ; V_20 ++ ) {
struct V_303 * V_304 = V_301 -> V_305 [ V_20 ] . V_306 ;
F_300 ( V_304 ) ;
}
F_90 ( V_301 ) ;
}
int F_301 ( const void * V_307 , const void * V_308 )
{
const struct V_309 * V_310 = V_307 ;
const struct V_309 * V_311 = V_308 ;
if ( V_310 -> V_140 < V_311 -> V_140 )
return - 1 ;
if ( V_310 -> V_140 + V_310 -> V_169 > V_311 -> V_140 + V_311 -> V_169 )
return 1 ;
return 0 ;
}
int F_302 ( struct V_72 * V_301 , struct V_303 * V_306 ,
T_5 V_140 , int V_169 )
{
if ( V_301 -> V_302 == V_312 )
return - V_313 ;
V_301 -> V_305 [ V_301 -> V_302 ++ ] = (struct V_309 ) {
. V_140 = V_140 ,
. V_169 = V_169 ,
. V_306 = V_306 ,
} ;
F_119 ( V_301 -> V_305 , V_301 -> V_302 , sizeof( struct V_309 ) ,
F_301 , NULL ) ;
return 0 ;
}
int F_303 ( struct V_72 * V_301 ,
T_5 V_140 , int V_169 )
{
struct V_309 * V_305 , V_314 ;
int V_315 ;
V_314 = (struct V_309 ) {
. V_140 = V_140 ,
. V_169 = V_169 ,
} ;
V_305 = bsearch ( & V_314 , V_301 -> V_305 , V_301 -> V_302 ,
sizeof( struct V_309 ) , F_301 ) ;
if ( V_305 == NULL )
return - V_130 ;
V_315 = V_305 - V_301 -> V_305 ;
while ( V_315 > 0 && F_301 ( & V_314 , & V_301 -> V_305 [ V_315 - 1 ] ) == 0 )
V_315 -- ;
return V_315 ;
}
int F_304 ( struct V_18 * V_18 , enum V_316 V_317 , T_5 V_140 ,
int V_169 , const void * V_295 )
{
int V_49 ;
struct V_72 * V_301 ;
struct V_309 V_305 ;
V_305 = (struct V_309 ) {
. V_140 = V_140 ,
. V_169 = V_169 ,
} ;
V_301 = F_305 ( V_18 -> V_71 [ V_317 ] , & V_18 -> V_50 ) ;
V_49 = F_303 ( V_301 , V_140 , V_169 ) ;
if ( V_49 < 0 )
return - V_287 ;
while ( V_49 < V_301 -> V_302 &&
F_301 ( & V_305 , & V_301 -> V_305 [ V_49 ] ) == 0 ) {
if ( ! F_306 ( V_301 -> V_305 [ V_49 ] . V_306 , V_140 , V_169 , V_295 ) )
return 0 ;
V_49 ++ ;
}
return - V_287 ;
}
int F_307 ( struct V_18 * V_18 , enum V_316 V_317 , T_5 V_140 ,
int V_169 , void * V_295 )
{
int V_49 ;
struct V_72 * V_301 ;
struct V_309 V_305 ;
V_305 = (struct V_309 ) {
. V_140 = V_140 ,
. V_169 = V_169 ,
} ;
V_301 = F_305 ( V_18 -> V_71 [ V_317 ] , & V_18 -> V_50 ) ;
V_49 = F_303 ( V_301 , V_140 , V_169 ) ;
if ( V_49 < 0 )
return - V_287 ;
while ( V_49 < V_301 -> V_302 &&
F_301 ( & V_305 , & V_301 -> V_305 [ V_49 ] ) == 0 ) {
if ( ! F_308 ( V_301 -> V_305 [ V_49 ] . V_306 , V_140 , V_169 , V_295 ) )
return 0 ;
V_49 ++ ;
}
return - V_287 ;
}
int F_309 ( struct V_18 * V_18 , enum V_316 V_317 , T_5 V_140 ,
int V_169 , struct V_303 * V_306 )
{
struct V_72 * V_318 , * V_301 ;
V_301 = V_18 -> V_71 [ V_317 ] ;
if ( V_301 -> V_302 > V_312 - 1 )
return - V_313 ;
V_318 = F_125 ( V_301 , sizeof( struct V_72 ) , V_37 ) ;
if ( ! V_318 )
return - V_39 ;
F_302 ( V_318 , V_306 , V_140 , V_169 ) ;
F_12 ( V_18 -> V_71 [ V_317 ] , V_318 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_90 ( V_301 ) ;
return 0 ;
}
int F_310 ( struct V_18 * V_18 , enum V_316 V_317 ,
struct V_303 * V_306 )
{
int V_20 , V_34 ;
struct V_72 * V_318 , * V_301 ;
V_301 = V_18 -> V_71 [ V_317 ] ;
V_318 = F_125 ( V_301 , sizeof( * V_301 ) , V_37 ) ;
if ( ! V_318 )
return - V_39 ;
V_34 = - V_130 ;
for ( V_20 = 0 ; V_20 < V_318 -> V_302 ; V_20 ++ )
if ( V_318 -> V_305 [ V_20 ] . V_306 == V_306 ) {
V_34 = 0 ;
V_318 -> V_302 -- ;
V_318 -> V_305 [ V_20 ] = V_318 -> V_305 [ V_318 -> V_302 ] ;
F_119 ( V_318 -> V_305 , V_318 -> V_302 ,
sizeof( struct V_309 ) ,
F_301 , NULL ) ;
break;
}
if ( V_34 ) {
F_90 ( V_318 ) ;
return V_34 ;
}
F_12 ( V_18 -> V_71 [ V_317 ] , V_318 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_90 ( V_301 ) ;
return V_34 ;
}
static int F_311 ( void * V_319 , T_10 * V_295 )
{
unsigned V_170 = ( long ) V_319 ;
struct V_18 * V_18 ;
* V_295 = 0 ;
F_85 ( & V_79 ) ;
F_312 ( V_18 , & V_80 , V_80 )
* V_295 += * ( T_6 * ) ( ( void * ) V_18 + V_170 ) ;
F_87 ( & V_79 ) ;
return 0 ;
}
static int F_313 ( void * V_319 , T_10 * V_295 )
{
unsigned V_170 = ( long ) V_319 ;
struct V_18 * V_18 ;
struct V_6 * V_7 ;
int V_20 ;
* V_295 = 0 ;
F_85 ( & V_79 ) ;
F_312 (kvm, &vm_list, vm_list)
F_28 ( V_20 , V_7 , V_18 )
* V_295 += * ( T_6 * ) ( ( void * ) V_7 + V_170 ) ;
F_87 ( & V_79 ) ;
return 0 ;
}
static int F_314 ( void )
{
int V_34 = - V_131 ;
struct V_320 * V_243 ;
V_321 = F_315 ( L_8 , NULL ) ;
if ( V_321 == NULL )
goto V_110;
for ( V_243 = V_322 ; V_243 -> V_323 ; ++ V_243 ) {
V_243 -> V_324 = F_316 ( V_243 -> V_323 , 0444 , V_321 ,
( void * ) ( long ) V_243 -> V_170 ,
V_325 [ V_243 -> V_326 ] ) ;
if ( V_243 -> V_324 == NULL )
goto V_327;
}
return 0 ;
V_327:
F_317 ( V_321 ) ;
V_110:
return V_34 ;
}
static void F_318 ( void )
{
struct V_320 * V_243 ;
for ( V_243 = V_322 ; V_243 -> V_323 ; ++ V_243 )
F_319 ( V_243 -> V_324 ) ;
F_319 ( V_321 ) ;
}
static int F_320 ( void )
{
if ( V_292 )
F_291 ( NULL ) ;
return 0 ;
}
static void F_321 ( void )
{
if ( V_292 ) {
F_177 ( F_322 ( & V_79 ) ) ;
F_284 ( NULL ) ;
}
}
static inline
struct V_6 * F_323 ( struct V_16 * V_328 )
{
return F_50 ( V_328 , struct V_6 , V_16 ) ;
}
static void F_324 ( struct V_16 * V_328 , int V_8 )
{
struct V_6 * V_7 = F_323 ( V_328 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_325 ( struct V_16 * V_328 ,
struct V_147 * V_329 )
{
struct V_6 * V_7 = F_323 ( V_328 ) ;
F_21 ( V_7 ) ;
}
int F_326 ( void * V_330 , unsigned V_331 , unsigned V_332 ,
struct V_333 * V_333 )
{
int V_34 ;
int V_8 ;
V_34 = F_327 ( V_330 ) ;
if ( V_34 )
goto V_334;
V_133 = F_43 ( V_37 | V_38 ) ;
if ( V_133 == NULL ) {
V_34 = - V_39 ;
goto V_110;
}
V_136 = F_166 ( V_133 ) ;
V_134 = F_43 ( V_37 | V_38 ) ;
if ( V_134 == NULL ) {
V_34 = - V_39 ;
goto V_335;
}
V_137 = F_166 ( V_134 ) ;
V_135 = F_43 ( V_37 | V_38 ) ;
if ( V_135 == NULL ) {
V_34 = - V_39 ;
goto V_335;
}
V_138 = F_166 ( V_135 ) ;
if ( ! F_27 ( & V_289 , V_37 ) ) {
V_34 = - V_39 ;
goto V_335;
}
V_34 = F_328 () ;
if ( V_34 < 0 )
goto V_336;
F_329 (cpu) {
F_330 ( V_8 ,
V_337 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_338;
}
V_34 = F_331 ( & V_339 ) ;
if ( V_34 )
goto V_340;
F_332 ( & V_341 ) ;
if ( ! V_332 )
V_332 = F_333 ( struct V_6 ) ;
V_342 = F_334 ( L_9 , V_331 , V_332 ,
0 , NULL ) ;
if ( ! V_342 ) {
V_34 = - V_39 ;
goto V_343;
}
V_34 = F_335 () ;
if ( V_34 )
goto V_120;
V_344 . V_345 = V_333 ;
V_271 . V_345 = V_333 ;
V_197 . V_345 = V_333 ;
V_34 = F_336 ( & V_346 ) ;
if ( V_34 ) {
F_289 ( V_347 L_10 ) ;
goto V_348;
}
F_337 ( & V_349 ) ;
V_200 . V_350 = F_324 ;
V_200 . V_351 = F_325 ;
V_34 = F_314 () ;
if ( V_34 ) {
F_289 ( V_347 L_11 ) ;
goto V_352;
}
return 0 ;
V_352:
F_338 ( & V_349 ) ;
V_348:
F_339 () ;
V_120:
F_340 ( V_342 ) ;
V_343:
F_341 ( & V_341 ) ;
F_342 ( & V_339 ) ;
V_340:
V_338:
F_343 () ;
V_336:
F_35 ( V_289 ) ;
V_335:
if ( V_135 )
F_344 ( V_135 ) ;
if ( V_134 )
F_344 ( V_134 ) ;
F_344 ( V_133 ) ;
V_110:
F_345 () ;
V_334:
return V_34 ;
}
void F_346 ( void )
{
F_318 () ;
F_347 ( & V_346 ) ;
F_340 ( V_342 ) ;
F_339 () ;
F_338 ( & V_349 ) ;
F_341 ( & V_341 ) ;
F_342 ( & V_339 ) ;
F_295 ( F_291 , NULL , 1 ) ;
F_343 () ;
F_345 () ;
F_35 ( V_289 ) ;
F_344 ( V_134 ) ;
F_344 ( V_133 ) ;
}
