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
F_94 ( V_82 -> V_83 ) ;
else
F_90 ( V_82 -> V_83 ) ;
V_82 -> V_83 = NULL ;
}
static void F_95 ( struct V_81 * free ,
struct V_81 * V_84 )
{
if ( ! V_84 || free -> V_85 != V_84 -> V_85 )
F_94 ( free -> V_85 ) ;
if ( ! V_84 || free -> V_83 != V_84 -> V_83 )
F_92 ( free ) ;
F_96 ( free , V_84 ) ;
free -> V_86 = 0 ;
free -> V_85 = NULL ;
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
#if F_105 ( V_87 ) && F_105 ( V_88 )
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
static int F_112 ( struct V_89 * V_89 , struct V_90 * V_91 )
{
struct V_18 * V_18 = V_91 -> V_92 ;
F_113 ( V_18 ) ;
F_110 ( V_18 ) ;
return 0 ;
}
static int F_114 ( struct V_81 * V_82 )
{
#ifndef F_115
unsigned long V_93 = 2 * F_93 ( V_82 ) ;
if ( V_93 > V_57 )
V_82 -> V_83 = F_116 ( V_93 ) ;
else
V_82 -> V_83 = F_79 ( V_93 , V_37 ) ;
if ( ! V_82 -> V_83 )
return - V_39 ;
#endif
return 0 ;
}
static int F_117 ( const void * V_94 , const void * V_95 )
{
struct V_81 * V_96 , * V_97 ;
V_96 = (struct V_81 * ) V_94 ;
V_97 = (struct V_81 * ) V_95 ;
if ( V_96 -> V_86 < V_97 -> V_86 )
return 1 ;
if ( V_96 -> V_86 > V_97 -> V_86 )
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
void F_120 ( struct V_61 * V_62 , struct V_81 * V_98 )
{
if ( V_98 ) {
int V_33 = V_98 -> V_33 ;
struct V_81 * V_99 = F_121 ( V_62 , V_33 ) ;
unsigned long V_86 = V_99 -> V_86 ;
* V_99 = * V_98 ;
if ( V_98 -> V_86 != V_86 )
F_118 ( V_62 ) ;
}
V_62 -> V_100 ++ ;
}
int F_122 ( struct V_18 * V_18 ,
struct V_101 * V_102 ,
int V_103 )
{
int V_34 ;
T_4 V_104 ;
unsigned long V_86 ;
unsigned long V_20 ;
struct V_81 * V_82 ;
struct V_81 V_99 , V_98 ;
struct V_61 * V_62 , * V_105 ;
V_34 = - V_106 ;
if ( V_102 -> V_107 & ( V_57 - 1 ) )
goto V_108;
if ( V_102 -> V_109 & ( V_57 - 1 ) )
goto V_108;
if ( V_103 &&
( ( V_102 -> V_110 & ( V_57 - 1 ) ) ||
! F_123 ( V_111 ,
( void V_112 * ) ( unsigned long ) V_102 -> V_110 ,
V_102 -> V_107 ) ) )
goto V_108;
if ( V_102 -> V_113 >= V_64 )
goto V_108;
if ( V_102 -> V_109 + V_102 -> V_107 < V_102 -> V_109 )
goto V_108;
V_82 = F_121 ( V_18 -> V_63 , V_102 -> V_113 ) ;
V_104 = V_102 -> V_109 >> V_114 ;
V_86 = V_102 -> V_107 >> V_114 ;
V_34 = - V_106 ;
if ( V_86 > V_115 )
goto V_108;
if ( ! V_86 )
V_102 -> V_116 &= ~ V_117 ;
V_98 = V_99 = * V_82 ;
V_98 . V_33 = V_102 -> V_113 ;
V_98 . V_104 = V_104 ;
V_98 . V_86 = V_86 ;
V_98 . V_116 = V_102 -> V_116 ;
V_34 = - V_106 ;
if ( V_86 && V_99 . V_86 && V_86 != V_99 . V_86 )
goto V_118;
V_34 = - V_119 ;
for ( V_20 = 0 ; V_20 < V_120 ; ++ V_20 ) {
struct V_81 * V_121 = & V_18 -> V_63 -> V_63 [ V_20 ] ;
if ( V_121 == V_82 || ! V_121 -> V_86 )
continue;
if ( ! ( ( V_104 + V_86 <= V_121 -> V_104 ) ||
( V_104 >= V_121 -> V_104 + V_121 -> V_86 ) ) )
goto V_118;
}
if ( ! ( V_98 . V_116 & V_117 ) )
V_98 . V_83 = NULL ;
V_34 = - V_39 ;
if ( V_86 && ! V_99 . V_86 ) {
V_98 . V_103 = V_103 ;
V_98 . V_110 = V_102 -> V_110 ;
#ifndef F_115
V_98 . V_85 = F_116 ( V_86 * sizeof( * V_98 . V_85 ) ) ;
if ( ! V_98 . V_85 )
goto V_118;
#endif
if ( F_124 ( & V_98 , V_86 ) )
goto V_118;
}
if ( ( V_98 . V_116 & V_117 ) && ! V_98 . V_83 ) {
if ( F_114 ( & V_98 ) < 0 )
goto V_118;
}
if ( ! V_86 ) {
struct V_81 * V_113 ;
V_34 = - V_39 ;
V_62 = F_125 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_118;
V_113 = F_121 ( V_62 , V_102 -> V_113 ) ;
V_113 -> V_116 |= V_122 ;
F_120 ( V_62 , NULL ) ;
V_105 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_68 ( V_18 ) ;
F_90 ( V_105 ) ;
}
V_34 = F_127 ( V_18 , & V_98 , V_99 , V_102 , V_103 ) ;
if ( V_34 )
goto V_118;
if ( V_86 ) {
V_34 = F_128 ( V_18 , & V_98 ) ;
if ( V_34 )
goto V_118;
} else
F_129 ( V_18 , & V_99 ) ;
V_34 = - V_39 ;
V_62 = F_125 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_118;
if ( ! V_86 ) {
V_98 . V_85 = NULL ;
V_98 . V_83 = NULL ;
memset ( & V_98 . V_123 , 0 , sizeof( V_98 . V_123 ) ) ;
}
F_120 ( V_62 , & V_98 ) ;
V_105 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_130 ( V_18 , V_102 , V_99 , V_103 ) ;
if ( V_86 && V_99 . V_104 != V_102 -> V_109 >> V_114 )
F_68 ( V_18 ) ;
F_95 ( & V_99 , & V_98 ) ;
F_90 ( V_105 ) ;
return 0 ;
V_118:
F_95 ( & V_98 , & V_99 ) ;
V_108:
return V_34 ;
}
int F_131 ( struct V_18 * V_18 ,
struct V_101 * V_102 ,
int V_103 )
{
int V_34 ;
F_9 ( & V_18 -> V_77 ) ;
V_34 = F_122 ( V_18 , V_102 , V_103 ) ;
F_24 ( & V_18 -> V_77 ) ;
return V_34 ;
}
int F_132 ( struct V_18 * V_18 ,
struct
V_101 * V_102 ,
int V_103 )
{
if ( V_102 -> V_113 >= V_120 )
return - V_106 ;
return F_131 ( V_18 , V_102 , V_103 ) ;
}
int F_133 ( struct V_18 * V_18 ,
struct V_124 * log , int * V_125 )
{
struct V_81 * V_82 ;
int V_34 , V_20 ;
unsigned long V_126 ;
unsigned long V_127 = 0 ;
V_34 = - V_106 ;
if ( log -> V_113 >= V_120 )
goto V_108;
V_82 = F_121 ( V_18 -> V_63 , log -> V_113 ) ;
V_34 = - V_128 ;
if ( ! V_82 -> V_83 )
goto V_108;
V_126 = F_93 ( V_82 ) ;
for ( V_20 = 0 ; ! V_127 && V_20 < V_126 / sizeof( long ) ; ++ V_20 )
V_127 = V_82 -> V_83 [ V_20 ] ;
V_34 = - V_129 ;
if ( F_134 ( log -> V_83 , V_82 -> V_83 , V_126 ) )
goto V_108;
if ( V_127 )
* V_125 = 1 ;
V_34 = 0 ;
V_108:
return V_34 ;
}
bool F_135 ( void )
{
return V_130 ;
}
void F_136 ( void )
{
V_130 = false ;
}
int F_137 ( struct V_3 * V_3 )
{
return V_3 == V_131 || V_3 == V_132 || V_3 == V_133 ;
}
int F_138 ( T_1 V_1 )
{
return V_1 == V_134 || V_1 == V_135 || V_1 == V_136 ;
}
int F_139 ( T_1 V_1 )
{
return V_1 == V_135 ;
}
int F_140 ( T_1 V_1 )
{
return V_1 == V_136 ;
}
int F_141 ( T_1 V_1 )
{
return V_1 == V_134 ;
}
int F_142 ( T_1 V_1 )
{
return V_1 == V_135 || V_1 == V_136 ;
}
static inline unsigned long F_143 ( void )
{
return V_137 ;
}
int F_144 ( unsigned long V_138 )
{
return V_138 == F_143 () ;
}
struct V_81 * F_145 ( struct V_18 * V_18 , T_4 V_139 )
{
return F_146 ( V_61 ( V_18 ) , V_139 ) ;
}
int F_147 ( struct V_18 * V_18 , T_4 V_139 )
{
struct V_81 * V_82 = F_145 ( V_18 , V_139 ) ;
if ( ! V_82 || V_82 -> V_33 >= V_120 ||
V_82 -> V_116 & V_122 )
return 0 ;
return 1 ;
}
unsigned long F_148 ( struct V_18 * V_18 , T_4 V_139 )
{
struct V_140 * V_141 ;
unsigned long V_138 , V_142 ;
V_142 = V_57 ;
V_138 = F_149 ( V_18 , V_139 ) ;
if ( F_144 ( V_138 ) )
return V_57 ;
F_150 ( & V_11 -> V_46 -> V_143 ) ;
V_141 = F_151 ( V_11 -> V_46 , V_138 ) ;
if ( ! V_141 )
goto V_108;
V_142 = F_152 ( V_141 ) ;
V_108:
F_153 ( & V_11 -> V_46 -> V_143 ) ;
return V_142 ;
}
static unsigned long F_154 ( struct V_81 * V_113 , T_4 V_139 ,
T_4 * V_144 )
{
if ( ! V_113 || V_113 -> V_116 & V_122 )
return F_143 () ;
if ( V_144 )
* V_144 = V_113 -> V_86 - ( V_139 - V_113 -> V_104 ) ;
return F_155 ( V_113 , V_139 ) ;
}
unsigned long F_149 ( struct V_18 * V_18 , T_4 V_139 )
{
return F_154 ( F_145 ( V_18 , V_139 ) , V_139 , NULL ) ;
}
static T_1 F_156 ( void )
{
F_157 ( V_133 ) ;
return V_136 ;
}
int F_158 ( struct V_145 * V_146 , struct V_45 * V_46 ,
unsigned long V_54 , int V_147 , struct V_3 * * V_3 )
{
int V_116 = V_148 | V_149 | V_150 | V_151 ;
if ( V_147 )
V_116 |= V_152 ;
return F_159 ( V_146 , V_46 , V_54 , 1 , V_116 , V_3 , NULL , NULL ) ;
}
static inline int F_160 ( unsigned long V_138 )
{
int V_153 , V_116 = V_148 | V_150 | V_152 ;
V_153 = F_159 ( V_11 , V_11 -> V_46 , V_138 , 1 ,
V_116 , NULL , NULL , NULL ) ;
return V_153 == - V_154 ;
}
static T_1 F_161 ( struct V_18 * V_18 , unsigned long V_138 , bool V_155 ,
bool * V_156 , bool V_157 , bool * V_158 )
{
struct V_3 * V_3 [ 1 ] ;
int V_86 = 0 ;
T_1 V_1 ;
F_62 ( V_155 && V_156 ) ;
F_62 ( ! V_157 && ! V_158 ) ;
if ( V_158 )
* V_158 = true ;
if ( V_155 || V_156 )
V_86 = F_162 ( V_138 , 1 , 1 , V_3 ) ;
if ( F_10 ( V_86 != 1 ) && ! V_155 ) {
F_163 () ;
if ( V_158 )
* V_158 = V_157 ;
if ( V_156 ) {
F_150 ( & V_11 -> V_46 -> V_143 ) ;
V_86 = F_158 ( V_11 , V_11 -> V_46 ,
V_138 , V_157 , V_3 ) ;
F_153 ( & V_11 -> V_46 -> V_143 ) ;
} else
V_86 = F_164 ( V_138 , 1 , V_157 ,
V_3 ) ;
if ( F_10 ( ! V_157 ) && V_86 == 1 ) {
struct V_3 * V_159 [ 1 ] ;
V_86 = F_162 ( V_138 , 1 , 1 , V_159 ) ;
if ( V_86 == 1 ) {
* V_158 = true ;
F_165 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_159 [ 0 ] ;
}
V_86 = 1 ;
}
}
if ( F_10 ( V_86 != 1 ) ) {
struct V_140 * V_141 ;
if ( V_155 )
return F_156 () ;
F_150 ( & V_11 -> V_46 -> V_143 ) ;
if ( V_86 == - V_154 ||
( ! V_156 && F_160 ( V_138 ) ) ) {
F_153 ( & V_11 -> V_46 -> V_143 ) ;
F_157 ( V_132 ) ;
return F_166 ( V_132 ) ;
}
V_141 = F_167 ( V_11 -> V_46 , V_138 , V_138 + 1 ) ;
if ( V_141 == NULL )
V_1 = F_156 () ;
else if ( ( V_141 -> V_160 & V_161 ) ) {
V_1 = ( ( V_138 - V_141 -> V_162 ) >> V_114 ) +
V_141 -> V_163 ;
F_62 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_156 && ( V_141 -> V_160 & V_164 ) )
* V_156 = true ;
V_1 = F_156 () ;
}
F_153 ( & V_11 -> V_46 -> V_143 ) ;
} else
V_1 = F_166 ( V_3 [ 0 ] ) ;
return V_1 ;
}
T_1 F_168 ( struct V_18 * V_18 , unsigned long V_138 )
{
return F_161 ( V_18 , V_138 , true , NULL , true , NULL ) ;
}
static T_1 F_169 ( struct V_18 * V_18 , T_4 V_139 , bool V_155 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
unsigned long V_138 ;
if ( V_156 )
* V_156 = false ;
V_138 = F_149 ( V_18 , V_139 ) ;
if ( F_144 ( V_138 ) ) {
F_157 ( V_131 ) ;
return F_166 ( V_131 ) ;
}
return F_161 ( V_18 , V_138 , V_155 , V_156 , V_157 , V_158 ) ;
}
T_1 F_170 ( struct V_18 * V_18 , T_4 V_139 )
{
return F_169 ( V_18 , V_139 , true , NULL , true , NULL ) ;
}
T_1 F_171 ( struct V_18 * V_18 , T_4 V_139 , bool * V_156 ,
bool V_157 , bool * V_158 )
{
return F_169 ( V_18 , V_139 , false , V_156 , V_157 , V_158 ) ;
}
T_1 F_172 ( struct V_18 * V_18 , T_4 V_139 )
{
return F_169 ( V_18 , V_139 , false , NULL , true , NULL ) ;
}
T_1 F_173 ( struct V_18 * V_18 , T_4 V_139 , bool V_157 ,
bool * V_158 )
{
return F_169 ( V_18 , V_139 , false , NULL , V_157 , V_158 ) ;
}
T_1 F_174 ( struct V_18 * V_18 ,
struct V_81 * V_113 , T_4 V_139 )
{
unsigned long V_138 = F_155 ( V_113 , V_139 ) ;
return F_161 ( V_18 , V_138 , false , NULL , true , NULL ) ;
}
int F_175 ( struct V_18 * V_18 , T_4 V_139 , struct V_3 * * V_165 ,
int V_144 )
{
unsigned long V_138 ;
T_4 V_166 ;
V_138 = F_154 ( F_145 ( V_18 , V_139 ) , V_139 , & V_166 ) ;
if ( F_144 ( V_138 ) )
return - 1 ;
if ( V_166 < V_144 )
return 0 ;
return F_162 ( V_138 , V_144 , 1 , V_165 ) ;
}
struct V_3 * F_176 ( struct V_18 * V_18 , T_4 V_139 )
{
T_1 V_1 ;
V_1 = F_172 ( V_18 , V_139 ) ;
if ( ! F_1 ( V_1 ) )
return F_3 ( V_1 ) ;
F_177 ( F_1 ( V_1 ) ) ;
F_157 ( V_131 ) ;
return V_131 ;
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
static int F_188 ( unsigned long V_167 , int V_168 )
{
if ( V_167 > V_57 - V_168 )
return V_57 - V_168 ;
else
return V_167 ;
}
int F_189 ( struct V_18 * V_18 , T_4 V_139 , void * V_169 , int V_168 ,
int V_167 )
{
int V_34 ;
unsigned long V_138 ;
V_138 = F_149 ( V_18 , V_139 ) ;
if ( F_144 ( V_138 ) )
return - V_129 ;
V_34 = F_190 ( V_169 , ( void V_112 * ) V_138 + V_168 , V_167 ) ;
if ( V_34 )
return - V_129 ;
return 0 ;
}
int F_191 ( struct V_18 * V_18 , T_5 V_170 , void * V_169 , unsigned long V_167 )
{
T_4 V_139 = V_170 >> V_114 ;
int V_171 ;
int V_168 = F_192 ( V_170 ) ;
int V_172 ;
while ( ( V_171 = F_188 ( V_167 , V_168 ) ) != 0 ) {
V_172 = F_189 ( V_18 , V_139 , V_169 , V_168 , V_171 ) ;
if ( V_172 < 0 )
return V_172 ;
V_168 = 0 ;
V_167 -= V_171 ;
V_169 += V_171 ;
++ V_139 ;
}
return 0 ;
}
int F_193 ( struct V_18 * V_18 , T_5 V_170 , void * V_169 ,
unsigned long V_167 )
{
int V_34 ;
unsigned long V_138 ;
T_4 V_139 = V_170 >> V_114 ;
int V_168 = F_192 ( V_170 ) ;
V_138 = F_149 ( V_18 , V_139 ) ;
if ( F_144 ( V_138 ) )
return - V_129 ;
F_194 () ;
V_34 = F_195 ( V_169 , ( void V_112 * ) V_138 + V_168 , V_167 ) ;
F_196 () ;
if ( V_34 )
return - V_129 ;
return 0 ;
}
int F_197 ( struct V_18 * V_18 , T_4 V_139 , const void * V_169 ,
int V_168 , int V_167 )
{
int V_34 ;
unsigned long V_138 ;
V_138 = F_149 ( V_18 , V_139 ) ;
if ( F_144 ( V_138 ) )
return - V_129 ;
V_34 = F_198 ( ( void V_112 * ) V_138 + V_168 , V_169 , V_167 ) ;
if ( V_34 )
return - V_129 ;
F_199 ( V_18 , V_139 ) ;
return 0 ;
}
int F_200 ( struct V_18 * V_18 , T_5 V_170 , const void * V_169 ,
unsigned long V_167 )
{
T_4 V_139 = V_170 >> V_114 ;
int V_171 ;
int V_168 = F_192 ( V_170 ) ;
int V_172 ;
while ( ( V_171 = F_188 ( V_167 , V_168 ) ) != 0 ) {
V_172 = F_197 ( V_18 , V_139 , V_169 , V_168 , V_171 ) ;
if ( V_172 < 0 )
return V_172 ;
V_168 = 0 ;
V_167 -= V_171 ;
V_169 += V_171 ;
++ V_139 ;
}
return 0 ;
}
int F_201 ( struct V_18 * V_18 , struct V_173 * V_174 ,
T_5 V_170 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_168 = F_192 ( V_170 ) ;
T_4 V_139 = V_170 >> V_114 ;
V_174 -> V_170 = V_170 ;
V_174 -> V_100 = V_62 -> V_100 ;
V_174 -> V_82 = F_145 ( V_18 , V_139 ) ;
V_174 -> V_175 = F_154 ( V_174 -> V_82 , V_139 , NULL ) ;
if ( ! F_144 ( V_174 -> V_175 ) )
V_174 -> V_175 += V_168 ;
else
return - V_129 ;
return 0 ;
}
int F_202 ( struct V_18 * V_18 , struct V_173 * V_174 ,
void * V_169 , unsigned long V_167 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_100 != V_174 -> V_100 )
F_201 ( V_18 , V_174 , V_174 -> V_170 ) ;
if ( F_144 ( V_174 -> V_175 ) )
return - V_129 ;
V_34 = F_198 ( ( void V_112 * ) V_174 -> V_175 , V_169 , V_167 ) ;
if ( V_34 )
return - V_129 ;
F_203 ( V_18 , V_174 -> V_82 , V_174 -> V_170 >> V_114 ) ;
return 0 ;
}
int F_204 ( struct V_18 * V_18 , struct V_173 * V_174 ,
void * V_169 , unsigned long V_167 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_100 != V_174 -> V_100 )
F_201 ( V_18 , V_174 , V_174 -> V_170 ) ;
if ( F_144 ( V_174 -> V_175 ) )
return - V_129 ;
V_34 = F_190 ( V_169 , ( void V_112 * ) V_174 -> V_175 , V_167 ) ;
if ( V_34 )
return - V_129 ;
return 0 ;
}
int F_205 ( struct V_18 * V_18 , T_4 V_139 , int V_168 , int V_167 )
{
return F_197 ( V_18 , V_139 , ( const void * ) V_176 ,
V_168 , V_167 ) ;
}
int F_206 ( struct V_18 * V_18 , T_5 V_170 , unsigned long V_167 )
{
T_4 V_139 = V_170 >> V_114 ;
int V_171 ;
int V_168 = F_192 ( V_170 ) ;
int V_172 ;
while ( ( V_171 = F_188 ( V_167 , V_168 ) ) != 0 ) {
V_172 = F_205 ( V_18 , V_139 , V_168 , V_171 ) ;
if ( V_172 < 0 )
return V_172 ;
V_168 = 0 ;
V_167 -= V_171 ;
++ V_139 ;
}
return 0 ;
}
void F_203 ( struct V_18 * V_18 , struct V_81 * V_82 ,
T_4 V_139 )
{
if ( V_82 && V_82 -> V_83 ) {
unsigned long V_177 = V_139 - V_82 -> V_104 ;
F_207 ( V_177 , V_82 -> V_83 ) ;
}
}
void F_199 ( struct V_18 * V_18 , T_4 V_139 )
{
struct V_81 * V_82 ;
V_82 = F_145 ( V_18 , V_139 ) ;
F_203 ( V_18 , V_82 , V_139 ) ;
}
void F_208 ( struct V_6 * V_7 )
{
F_209 ( V_178 ) ;
for (; ; ) {
F_210 ( & V_7 -> V_36 , & V_178 , V_179 ) ;
if ( F_211 ( V_7 ) ) {
F_29 ( V_180 , V_7 ) ;
break;
}
if ( F_212 ( V_7 ) )
break;
if ( F_213 ( V_11 ) )
break;
F_214 () ;
}
F_215 ( & V_7 -> V_36 , & V_178 ) ;
}
void F_216 ( struct V_6 * V_7 )
{
int V_21 ;
int V_8 = V_7 -> V_8 ;
T_6 * V_181 ;
V_181 = F_217 ( V_7 ) ;
if ( F_218 ( V_181 ) ) {
F_219 ( V_181 ) ;
++ V_7 -> V_30 . V_182 ;
}
V_21 = F_15 () ;
if ( V_8 != V_21 && ( unsigned ) V_8 < V_183 && F_220 ( V_8 ) )
if ( F_221 ( V_7 ) )
F_222 ( V_8 ) ;
F_18 () ;
}
void F_223 ( struct V_6 * V_7 )
{
if ( ! F_224 () )
return;
F_225 () ;
}
bool F_226 ( struct V_6 * V_184 )
{
struct V_10 * V_10 ;
struct V_145 * V_185 = NULL ;
F_227 () ;
V_10 = F_228 ( V_184 -> V_10 ) ;
if ( V_10 )
V_185 = F_229 ( V_184 -> V_10 , V_13 ) ;
F_230 () ;
if ( ! V_185 )
return false ;
if ( V_185 -> V_116 & V_186 ) {
F_231 ( V_185 ) ;
return false ;
}
if ( F_232 ( V_185 , 1 ) ) {
F_231 ( V_185 ) ;
return true ;
}
F_231 ( V_185 ) ;
return false ;
}
void F_233 ( struct V_6 * V_21 )
{
struct V_18 * V_18 = V_21 -> V_18 ;
struct V_6 * V_7 ;
int V_187 = V_21 -> V_18 -> V_187 ;
int V_188 = 0 ;
int V_189 ;
int V_20 ;
for ( V_189 = 0 ; V_189 < 2 && ! V_188 ; V_189 ++ ) {
F_28 (i, vcpu, kvm) {
if ( ! V_189 && V_20 < V_187 ) {
V_20 = V_187 ;
continue;
} else if ( V_189 && V_20 > V_187 )
break;
if ( V_7 == V_21 )
continue;
if ( F_218 ( & V_7 -> V_36 ) )
continue;
if ( F_226 ( V_7 ) ) {
V_18 -> V_187 = V_20 ;
V_188 = 1 ;
break;
}
}
}
}
static int F_234 ( struct V_140 * V_141 , struct V_190 * V_191 )
{
struct V_6 * V_7 = V_141 -> V_192 -> V_92 ;
struct V_3 * V_3 ;
if ( V_191 -> V_193 == 0 )
V_3 = F_235 ( V_7 -> V_41 ) ;
#ifdef F_236
else if ( V_191 -> V_193 == V_194 )
V_3 = F_235 ( V_7 -> V_123 . V_195 ) ;
#endif
#ifdef F_237
else if ( V_191 -> V_193 == F_237 )
V_3 = F_235 ( V_7 -> V_18 -> V_196 ) ;
#endif
else
return F_238 ( V_7 , V_191 ) ;
F_157 ( V_3 ) ;
V_191 -> V_3 = V_3 ;
return 0 ;
}
static int F_239 ( struct V_90 * V_90 , struct V_140 * V_141 )
{
V_141 -> V_197 = & V_198 ;
return 0 ;
}
static int F_240 ( struct V_89 * V_89 , struct V_90 * V_91 )
{
struct V_6 * V_7 = V_91 -> V_92 ;
F_110 ( V_7 -> V_18 ) ;
return 0 ;
}
static int F_241 ( struct V_6 * V_7 )
{
return F_242 ( L_1 , & V_199 , V_7 , V_200 ) ;
}
static int F_243 ( struct V_18 * V_18 , T_7 V_33 )
{
int V_34 ;
struct V_6 * V_7 , * V_201 ;
V_7 = F_244 ( V_18 , V_33 ) ;
if ( F_245 ( V_7 ) )
return F_246 ( V_7 ) ;
F_247 ( & V_7 -> V_16 , & V_202 ) ;
V_34 = F_248 ( V_7 ) ;
if ( V_34 )
goto V_203;
F_9 ( & V_18 -> V_75 ) ;
if ( ! F_249 ( V_7 ) ) {
V_34 = - V_106 ;
goto V_204;
}
if ( F_250 ( & V_18 -> V_205 ) == V_206 ) {
V_34 = - V_106 ;
goto V_204;
}
F_28 (r, v, kvm)
if ( V_201 -> V_35 == V_33 ) {
V_34 = - V_119 ;
goto V_204;
}
F_62 ( V_18 -> V_207 [ F_250 ( & V_18 -> V_205 ) ] ) ;
F_109 ( V_18 ) ;
V_34 = F_241 ( V_7 ) ;
if ( V_34 < 0 ) {
F_110 ( V_18 ) ;
goto V_204;
}
V_18 -> V_207 [ F_250 ( & V_18 -> V_205 ) ] = V_7 ;
F_61 () ;
F_82 ( & V_18 -> V_205 ) ;
F_24 ( & V_18 -> V_75 ) ;
return V_34 ;
V_204:
F_24 ( & V_18 -> V_75 ) ;
V_203:
F_251 ( V_7 ) ;
return V_34 ;
}
static int F_252 ( struct V_6 * V_7 , T_8 * V_208 )
{
if ( V_208 ) {
F_253 ( V_208 , F_254 ( V_209 ) | F_254 ( V_210 ) ) ;
V_7 -> V_211 = 1 ;
V_7 -> V_208 = * V_208 ;
} else
V_7 -> V_211 = 0 ;
return 0 ;
}
static long F_255 ( struct V_90 * V_91 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_6 * V_7 = V_91 -> V_92 ;
void V_112 * V_214 = ( void V_112 * ) V_213 ;
int V_34 ;
struct V_215 * V_216 = NULL ;
struct V_217 * V_217 = NULL ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
#if F_105 ( F_115 ) || F_105 ( V_219 )
if ( V_212 == V_220 || V_212 == V_221 )
return F_256 ( V_91 , V_212 , V_213 ) ;
#endif
F_8 ( V_7 ) ;
switch ( V_212 ) {
case V_222 :
V_34 = - V_106 ;
if ( V_213 )
goto V_108;
V_34 = F_257 ( V_7 , V_7 -> V_41 ) ;
F_258 ( V_7 -> V_41 -> V_223 , V_34 ) ;
break;
case V_224 : {
struct V_225 * V_225 ;
V_34 = - V_39 ;
V_225 = F_79 ( sizeof( struct V_225 ) , V_37 ) ;
if ( ! V_225 )
goto V_108;
V_34 = F_259 ( V_7 , V_225 ) ;
if ( V_34 )
goto V_226;
V_34 = - V_129 ;
if ( F_134 ( V_214 , V_225 , sizeof( struct V_225 ) ) )
goto V_226;
V_34 = 0 ;
V_226:
F_90 ( V_225 ) ;
break;
}
case V_227 : {
struct V_225 * V_225 ;
V_34 = - V_39 ;
V_225 = F_260 ( V_214 , sizeof( * V_225 ) ) ;
if ( F_245 ( V_225 ) ) {
V_34 = F_246 ( V_225 ) ;
goto V_108;
}
V_34 = F_261 ( V_7 , V_225 ) ;
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
goto V_108;
V_34 = F_262 ( V_7 , V_217 ) ;
if ( V_34 )
goto V_108;
V_34 = - V_129 ;
if ( F_134 ( V_214 , V_217 , sizeof( struct V_217 ) ) )
goto V_108;
V_34 = 0 ;
break;
}
case V_230 : {
V_217 = F_260 ( V_214 , sizeof( * V_217 ) ) ;
if ( F_245 ( V_217 ) ) {
V_34 = F_246 ( V_217 ) ;
goto V_108;
}
V_34 = F_263 ( V_7 , V_217 ) ;
if ( V_34 )
goto V_108;
V_34 = 0 ;
break;
}
case V_231 : {
struct V_232 V_233 ;
V_34 = F_264 ( V_7 , & V_233 ) ;
if ( V_34 )
goto V_108;
V_34 = - V_129 ;
if ( F_134 ( V_214 , & V_233 , sizeof V_233 ) )
goto V_108;
V_34 = 0 ;
break;
}
case V_234 : {
struct V_232 V_233 ;
V_34 = - V_129 ;
if ( F_265 ( & V_233 , V_214 , sizeof V_233 ) )
goto V_108;
V_34 = F_266 ( V_7 , & V_233 ) ;
if ( V_34 )
goto V_108;
V_34 = 0 ;
break;
}
case V_235 : {
struct V_236 V_237 ;
V_34 = - V_129 ;
if ( F_265 ( & V_237 , V_214 , sizeof V_237 ) )
goto V_108;
V_34 = F_267 ( V_7 , & V_237 ) ;
if ( V_34 )
goto V_108;
V_34 = - V_129 ;
if ( F_134 ( V_214 , & V_237 , sizeof V_237 ) )
goto V_108;
V_34 = 0 ;
break;
}
case V_238 : {
struct V_239 V_240 ;
V_34 = - V_129 ;
if ( F_265 ( & V_240 , V_214 , sizeof V_240 ) )
goto V_108;
V_34 = F_268 ( V_7 , & V_240 ) ;
if ( V_34 )
goto V_108;
V_34 = 0 ;
break;
}
case V_241 : {
struct V_242 V_112 * V_243 = V_214 ;
struct V_242 V_244 ;
T_8 V_208 , * V_245 ;
V_245 = NULL ;
if ( V_214 ) {
V_34 = - V_129 ;
if ( F_265 ( & V_244 , V_214 ,
sizeof V_244 ) )
goto V_108;
V_34 = - V_106 ;
if ( V_244 . V_167 != sizeof V_208 )
goto V_108;
V_34 = - V_129 ;
if ( F_265 ( & V_208 , V_243 -> V_208 ,
sizeof V_208 ) )
goto V_108;
V_245 = & V_208 ;
}
V_34 = F_252 ( V_7 , V_245 ) ;
break;
}
case V_246 : {
V_216 = F_79 ( sizeof( struct V_215 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_216 )
goto V_108;
V_34 = F_269 ( V_7 , V_216 ) ;
if ( V_34 )
goto V_108;
V_34 = - V_129 ;
if ( F_134 ( V_214 , V_216 , sizeof( struct V_215 ) ) )
goto V_108;
V_34 = 0 ;
break;
}
case V_247 : {
V_216 = F_260 ( V_214 , sizeof( * V_216 ) ) ;
if ( F_245 ( V_216 ) ) {
V_34 = F_246 ( V_216 ) ;
goto V_108;
}
V_34 = F_270 ( V_7 , V_216 ) ;
if ( V_34 )
goto V_108;
V_34 = 0 ;
break;
}
default:
V_34 = F_256 ( V_91 , V_212 , V_213 ) ;
}
V_108:
F_19 ( V_7 ) ;
F_90 ( V_216 ) ;
F_90 ( V_217 ) ;
return V_34 ;
}
static long F_271 ( struct V_90 * V_91 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_6 * V_7 = V_91 -> V_92 ;
void V_112 * V_214 = F_272 ( V_213 ) ;
int V_34 ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
switch ( V_212 ) {
case V_241 : {
struct V_242 V_112 * V_243 = V_214 ;
struct V_242 V_244 ;
T_9 V_248 ;
T_8 V_208 ;
if ( V_214 ) {
V_34 = - V_129 ;
if ( F_265 ( & V_244 , V_214 ,
sizeof V_244 ) )
goto V_108;
V_34 = - V_106 ;
if ( V_244 . V_167 != sizeof V_248 )
goto V_108;
V_34 = - V_129 ;
if ( F_265 ( & V_248 , V_243 -> V_208 ,
sizeof V_248 ) )
goto V_108;
}
F_273 ( & V_208 , & V_248 ) ;
V_34 = F_252 ( V_7 , & V_208 ) ;
break;
}
default:
V_34 = F_255 ( V_91 , V_212 , V_213 ) ;
}
V_108:
return V_34 ;
}
static long F_274 ( struct V_90 * V_91 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_18 * V_18 = V_91 -> V_92 ;
void V_112 * V_214 = ( void V_112 * ) V_213 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
switch ( V_212 ) {
case V_249 :
V_34 = F_243 ( V_18 , V_213 ) ;
if ( V_34 < 0 )
goto V_108;
break;
case V_250 : {
struct V_101 V_251 ;
V_34 = - V_129 ;
if ( F_265 ( & V_251 , V_214 ,
sizeof V_251 ) )
goto V_108;
V_34 = F_132 ( V_18 , & V_251 , 1 ) ;
if ( V_34 )
goto V_108;
break;
}
case V_252 : {
struct V_124 log ;
V_34 = - V_129 ;
if ( F_265 ( & log , V_214 , sizeof log ) )
goto V_108;
V_34 = F_275 ( V_18 , & log ) ;
if ( V_34 )
goto V_108;
break;
}
#ifdef F_237
case V_253 : {
struct V_254 V_255 ;
V_34 = - V_129 ;
if ( F_265 ( & V_255 , V_214 , sizeof V_255 ) )
goto V_108;
V_34 = F_276 ( V_18 , & V_255 ) ;
if ( V_34 )
goto V_108;
V_34 = 0 ;
break;
}
case V_256 : {
struct V_254 V_255 ;
V_34 = - V_129 ;
if ( F_265 ( & V_255 , V_214 , sizeof V_255 ) )
goto V_108;
V_34 = F_277 ( V_18 , & V_255 ) ;
if ( V_34 )
goto V_108;
V_34 = 0 ;
break;
}
#endif
case V_257 : {
struct V_258 V_169 ;
V_34 = - V_129 ;
if ( F_265 ( & V_169 , V_214 , sizeof V_169 ) )
goto V_108;
V_34 = V_258 ( V_18 , & V_169 ) ;
break;
}
case V_259 : {
struct V_260 V_169 ;
V_34 = - V_129 ;
if ( F_265 ( & V_169 , V_214 , sizeof V_169 ) )
goto V_108;
V_34 = V_260 ( V_18 , & V_169 ) ;
break;
}
#ifdef F_278
case V_261 :
V_34 = 0 ;
F_9 ( & V_18 -> V_75 ) ;
if ( F_250 ( & V_18 -> V_205 ) != 0 )
V_34 = - V_262 ;
else
V_18 -> V_263 = V_213 ;
F_24 ( & V_18 -> V_75 ) ;
break;
#endif
#ifdef F_279
case V_264 : {
struct V_265 V_266 ;
V_34 = - V_129 ;
if ( F_265 ( & V_266 , V_214 , sizeof V_266 ) )
goto V_108;
V_34 = F_280 ( V_18 , & V_266 ) ;
break;
}
#endif
default:
V_34 = F_281 ( V_91 , V_212 , V_213 ) ;
if ( V_34 == - V_267 )
V_34 = F_282 ( V_18 , V_212 , V_213 ) ;
}
V_108:
return V_34 ;
}
static long F_283 ( struct V_90 * V_91 ,
unsigned int V_212 , unsigned long V_213 )
{
struct V_18 * V_18 = V_91 -> V_92 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_218 ;
switch ( V_212 ) {
case V_252 : {
struct V_268 V_269 ;
struct V_124 log ;
V_34 = - V_129 ;
if ( F_265 ( & V_269 , ( void V_112 * ) V_213 ,
sizeof( V_269 ) ) )
goto V_108;
log . V_113 = V_269 . V_113 ;
log . V_270 = V_269 . V_270 ;
log . V_271 = V_269 . V_271 ;
log . V_83 = F_272 ( V_269 . V_83 ) ;
V_34 = F_275 ( V_18 , & log ) ;
if ( V_34 )
goto V_108;
break;
}
default:
V_34 = F_274 ( V_91 , V_212 , V_213 ) ;
}
V_108:
return V_34 ;
}
static int F_284 ( struct V_140 * V_141 , struct V_190 * V_191 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_138 ;
int V_86 ;
T_4 V_139 = V_191 -> V_193 ;
struct V_18 * V_18 = V_141 -> V_192 -> V_92 ;
V_138 = F_149 ( V_18 , V_139 ) ;
if ( F_144 ( V_138 ) )
return V_272 ;
V_86 = F_285 ( V_11 , V_11 -> V_46 , V_138 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_86 != 1 ) )
return V_272 ;
V_191 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_286 ( struct V_90 * V_90 , struct V_140 * V_141 )
{
V_141 -> V_197 = & V_273 ;
return 0 ;
}
static int F_287 ( unsigned long type )
{
int V_34 ;
struct V_18 * V_18 ;
V_18 = F_72 ( type ) ;
if ( F_245 ( V_18 ) )
return F_246 ( V_18 ) ;
#ifdef F_237
V_34 = F_288 ( V_18 ) ;
if ( V_34 < 0 ) {
F_110 ( V_18 ) ;
return V_34 ;
}
#endif
V_34 = F_242 ( L_2 , & V_274 , V_18 , V_200 ) ;
if ( V_34 < 0 )
F_110 ( V_18 ) ;
return V_34 ;
}
static long F_289 ( long V_213 )
{
switch ( V_213 ) {
case V_275 :
case V_276 :
case V_277 :
#ifdef F_278
case V_278 :
#endif
case V_279 :
#ifdef F_279
case V_280 :
#endif
return 1 ;
#ifdef F_77
case V_281 :
return V_282 ;
#endif
default:
break;
}
return F_290 ( V_213 ) ;
}
static long F_291 ( struct V_90 * V_91 ,
unsigned int V_212 , unsigned long V_213 )
{
long V_34 = - V_106 ;
switch ( V_212 ) {
case V_283 :
V_34 = - V_106 ;
if ( V_213 )
goto V_108;
V_34 = V_284 ;
break;
case V_285 :
V_34 = F_287 ( V_213 ) ;
break;
case V_286 :
V_34 = F_289 ( V_213 ) ;
break;
case V_287 :
V_34 = - V_106 ;
if ( V_213 )
goto V_108;
V_34 = V_57 ;
#ifdef F_236
V_34 += V_57 ;
#endif
#ifdef F_237
V_34 += V_57 ;
#endif
break;
case V_288 :
case V_289 :
case V_290 :
V_34 = - V_291 ;
break;
default:
return F_292 ( V_91 , V_212 , V_213 ) ;
}
V_108:
return V_34 ;
}
static void F_293 ( void * V_292 )
{
int V_8 = F_294 () ;
int V_34 ;
if ( F_295 ( V_8 , V_293 ) )
return;
F_32 ( V_8 , V_293 ) ;
V_34 = F_296 ( NULL ) ;
if ( V_34 ) {
F_297 ( V_8 , V_293 ) ;
F_82 ( & V_294 ) ;
F_298 ( V_295 L_3
L_4 , V_8 ) ;
}
}
static void F_299 ( void * V_292 )
{
F_85 ( & V_79 ) ;
F_293 ( V_292 ) ;
F_87 ( & V_79 ) ;
}
static void F_300 ( void * V_292 )
{
int V_8 = F_294 () ;
if ( ! F_295 ( V_8 , V_293 ) )
return;
F_297 ( V_8 , V_293 ) ;
F_301 ( NULL ) ;
}
static void F_302 ( void * V_292 )
{
F_85 ( & V_79 ) ;
F_300 ( V_292 ) ;
F_87 ( & V_79 ) ;
}
static void F_303 ( void )
{
F_62 ( ! V_296 ) ;
V_296 -- ;
if ( ! V_296 )
F_304 ( F_300 , NULL , 1 ) ;
}
static void F_89 ( void )
{
F_85 ( & V_79 ) ;
F_303 () ;
F_87 ( & V_79 ) ;
}
static int F_76 ( void )
{
int V_34 = 0 ;
F_85 ( & V_79 ) ;
V_296 ++ ;
if ( V_296 == 1 ) {
F_84 ( & V_294 , 0 ) ;
F_304 ( F_293 , NULL , 1 ) ;
if ( F_250 ( & V_294 ) ) {
F_303 () ;
V_34 = - V_262 ;
}
}
F_87 ( & V_79 ) ;
return V_34 ;
}
static int F_305 ( struct V_297 * V_298 , unsigned long V_299 ,
void * V_201 )
{
int V_8 = ( long ) V_201 ;
if ( ! V_296 )
return V_300 ;
V_299 &= ~ V_301 ;
switch ( V_299 ) {
case V_302 :
F_298 ( V_295 L_5 ,
V_8 ) ;
F_302 ( NULL ) ;
break;
case V_303 :
F_298 ( V_295 L_6 ,
V_8 ) ;
F_299 ( NULL ) ;
break;
}
return V_300 ;
}
T_10 void F_306 ( void )
{
F_307 () ;
}
static int F_308 ( struct V_297 * V_298 , unsigned long V_299 ,
void * V_201 )
{
F_298 ( V_295 L_7 ) ;
V_304 = true ;
F_304 ( F_300 , NULL , 1 ) ;
return V_300 ;
}
static void F_103 ( struct V_72 * V_305 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_305 -> V_306 ; V_20 ++ ) {
struct V_307 * V_308 = V_305 -> V_309 [ V_20 ] . V_310 ;
F_309 ( V_308 ) ;
}
F_90 ( V_305 ) ;
}
int F_310 ( const void * V_311 , const void * V_312 )
{
const struct V_313 * V_314 = V_311 ;
const struct V_313 * V_315 = V_312 ;
if ( V_314 -> V_138 < V_315 -> V_138 )
return - 1 ;
if ( V_314 -> V_138 + V_314 -> V_167 > V_315 -> V_138 + V_315 -> V_167 )
return 1 ;
return 0 ;
}
int F_311 ( struct V_72 * V_305 , struct V_307 * V_310 ,
T_5 V_138 , int V_167 )
{
V_305 -> V_309 [ V_305 -> V_306 ++ ] = (struct V_313 ) {
. V_138 = V_138 ,
. V_167 = V_167 ,
. V_310 = V_310 ,
} ;
F_119 ( V_305 -> V_309 , V_305 -> V_306 , sizeof( struct V_313 ) ,
F_310 , NULL ) ;
return 0 ;
}
int F_312 ( struct V_72 * V_305 ,
T_5 V_138 , int V_167 )
{
struct V_313 * V_309 , V_316 ;
int V_317 ;
V_316 = (struct V_313 ) {
. V_138 = V_138 ,
. V_167 = V_167 ,
} ;
V_309 = bsearch ( & V_316 , V_305 -> V_309 , V_305 -> V_306 ,
sizeof( struct V_313 ) , F_310 ) ;
if ( V_309 == NULL )
return - V_128 ;
V_317 = V_309 - V_305 -> V_309 ;
while ( V_317 > 0 && F_310 ( & V_316 , & V_305 -> V_309 [ V_317 - 1 ] ) == 0 )
V_317 -- ;
return V_317 ;
}
int F_313 ( struct V_18 * V_18 , enum V_318 V_319 , T_5 V_138 ,
int V_167 , const void * V_299 )
{
int V_49 ;
struct V_72 * V_305 ;
struct V_313 V_309 ;
V_309 = (struct V_313 ) {
. V_138 = V_138 ,
. V_167 = V_167 ,
} ;
V_305 = F_314 ( V_18 -> V_71 [ V_319 ] , & V_18 -> V_50 ) ;
V_49 = F_312 ( V_305 , V_138 , V_167 ) ;
if ( V_49 < 0 )
return - V_291 ;
while ( V_49 < V_305 -> V_306 &&
F_310 ( & V_309 , & V_305 -> V_309 [ V_49 ] ) == 0 ) {
if ( ! F_315 ( V_305 -> V_309 [ V_49 ] . V_310 , V_138 , V_167 , V_299 ) )
return 0 ;
V_49 ++ ;
}
return - V_291 ;
}
int F_316 ( struct V_18 * V_18 , enum V_318 V_319 , T_5 V_138 ,
int V_167 , void * V_299 )
{
int V_49 ;
struct V_72 * V_305 ;
struct V_313 V_309 ;
V_309 = (struct V_313 ) {
. V_138 = V_138 ,
. V_167 = V_167 ,
} ;
V_305 = F_314 ( V_18 -> V_71 [ V_319 ] , & V_18 -> V_50 ) ;
V_49 = F_312 ( V_305 , V_138 , V_167 ) ;
if ( V_49 < 0 )
return - V_291 ;
while ( V_49 < V_305 -> V_306 &&
F_310 ( & V_309 , & V_305 -> V_309 [ V_49 ] ) == 0 ) {
if ( ! F_317 ( V_305 -> V_309 [ V_49 ] . V_310 , V_138 , V_167 , V_299 ) )
return 0 ;
V_49 ++ ;
}
return - V_291 ;
}
int F_318 ( struct V_18 * V_18 , enum V_318 V_319 , T_5 V_138 ,
int V_167 , struct V_307 * V_310 )
{
struct V_72 * V_320 , * V_305 ;
V_305 = V_18 -> V_71 [ V_319 ] ;
if ( V_305 -> V_306 > V_321 - 1 )
return - V_322 ;
V_320 = F_79 ( sizeof( * V_305 ) + ( ( V_305 -> V_306 + 1 ) *
sizeof( struct V_313 ) ) , V_37 ) ;
if ( ! V_320 )
return - V_39 ;
memcpy ( V_320 , V_305 , sizeof( * V_305 ) + ( V_305 -> V_306 *
sizeof( struct V_313 ) ) ) ;
F_311 ( V_320 , V_310 , V_138 , V_167 ) ;
F_12 ( V_18 -> V_71 [ V_319 ] , V_320 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_90 ( V_305 ) ;
return 0 ;
}
int F_319 ( struct V_18 * V_18 , enum V_318 V_319 ,
struct V_307 * V_310 )
{
int V_20 , V_34 ;
struct V_72 * V_320 , * V_305 ;
V_305 = V_18 -> V_71 [ V_319 ] ;
V_34 = - V_128 ;
for ( V_20 = 0 ; V_20 < V_305 -> V_306 ; V_20 ++ )
if ( V_305 -> V_309 [ V_20 ] . V_310 == V_310 ) {
V_34 = 0 ;
break;
}
if ( V_34 )
return V_34 ;
V_320 = F_79 ( sizeof( * V_305 ) + ( ( V_305 -> V_306 - 1 ) *
sizeof( struct V_313 ) ) , V_37 ) ;
if ( ! V_320 )
return - V_39 ;
memcpy ( V_320 , V_305 , sizeof( * V_305 ) + V_20 * sizeof( struct V_313 ) ) ;
V_320 -> V_306 -- ;
memcpy ( V_320 -> V_309 + V_20 , V_305 -> V_309 + V_20 + 1 ,
( V_320 -> V_306 - V_20 ) * sizeof( struct V_313 ) ) ;
F_12 ( V_18 -> V_71 [ V_319 ] , V_320 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_90 ( V_305 ) ;
return V_34 ;
}
static int F_320 ( void * V_323 , T_11 * V_299 )
{
unsigned V_168 = ( long ) V_323 ;
struct V_18 * V_18 ;
* V_299 = 0 ;
F_85 ( & V_79 ) ;
F_321 ( V_18 , & V_80 , V_80 )
* V_299 += * ( T_7 * ) ( ( void * ) V_18 + V_168 ) ;
F_87 ( & V_79 ) ;
return 0 ;
}
static int F_322 ( void * V_323 , T_11 * V_299 )
{
unsigned V_168 = ( long ) V_323 ;
struct V_18 * V_18 ;
struct V_6 * V_7 ;
int V_20 ;
* V_299 = 0 ;
F_85 ( & V_79 ) ;
F_321 (kvm, &vm_list, vm_list)
F_28 ( V_20 , V_7 , V_18 )
* V_299 += * ( T_7 * ) ( ( void * ) V_7 + V_168 ) ;
F_87 ( & V_79 ) ;
return 0 ;
}
static int F_323 ( void )
{
int V_34 = - V_129 ;
struct V_324 * V_245 ;
V_325 = F_324 ( L_8 , NULL ) ;
if ( V_325 == NULL )
goto V_108;
for ( V_245 = V_326 ; V_245 -> V_327 ; ++ V_245 ) {
V_245 -> V_328 = F_325 ( V_245 -> V_327 , 0444 , V_325 ,
( void * ) ( long ) V_245 -> V_168 ,
V_329 [ V_245 -> V_330 ] ) ;
if ( V_245 -> V_328 == NULL )
goto V_331;
}
return 0 ;
V_331:
F_326 ( V_325 ) ;
V_108:
return V_34 ;
}
static void F_327 ( void )
{
struct V_324 * V_245 ;
for ( V_245 = V_326 ; V_245 -> V_327 ; ++ V_245 )
F_328 ( V_245 -> V_328 ) ;
F_328 ( V_325 ) ;
}
static int F_329 ( void )
{
if ( V_296 )
F_300 ( NULL ) ;
return 0 ;
}
static void F_330 ( void )
{
if ( V_296 ) {
F_177 ( F_331 ( & V_79 ) ) ;
F_293 ( NULL ) ;
}
}
static inline
struct V_6 * F_332 ( struct V_16 * V_332 )
{
return F_50 ( V_332 , struct V_6 , V_16 ) ;
}
static void F_333 ( struct V_16 * V_332 , int V_8 )
{
struct V_6 * V_7 = F_332 ( V_332 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_334 ( struct V_16 * V_332 ,
struct V_145 * V_333 )
{
struct V_6 * V_7 = F_332 ( V_332 ) ;
F_21 ( V_7 ) ;
}
int F_335 ( void * V_334 , unsigned V_335 , unsigned V_336 ,
struct V_337 * V_337 )
{
int V_34 ;
int V_8 ;
V_34 = F_336 ( V_334 ) ;
if ( V_34 )
goto V_338;
V_131 = F_43 ( V_37 | V_38 ) ;
if ( V_131 == NULL ) {
V_34 = - V_39 ;
goto V_108;
}
V_134 = F_166 ( V_131 ) ;
V_132 = F_43 ( V_37 | V_38 ) ;
if ( V_132 == NULL ) {
V_34 = - V_39 ;
goto V_339;
}
V_135 = F_166 ( V_132 ) ;
V_133 = F_43 ( V_37 | V_38 ) ;
if ( V_133 == NULL ) {
V_34 = - V_39 ;
goto V_339;
}
V_136 = F_166 ( V_133 ) ;
if ( ! F_27 ( & V_293 , V_37 ) ) {
V_34 = - V_39 ;
goto V_339;
}
V_34 = F_337 () ;
if ( V_34 < 0 )
goto V_340;
F_338 (cpu) {
F_339 ( V_8 ,
V_341 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_342;
}
V_34 = F_340 ( & V_343 ) ;
if ( V_34 )
goto V_344;
F_341 ( & V_345 ) ;
if ( ! V_336 )
V_336 = F_342 ( struct V_6 ) ;
V_346 = F_343 ( L_9 , V_335 , V_336 ,
0 , NULL ) ;
if ( ! V_346 ) {
V_34 = - V_39 ;
goto V_347;
}
V_34 = F_344 () ;
if ( V_34 )
goto V_118;
V_348 . V_349 = V_337 ;
V_274 . V_349 = V_337 ;
V_199 . V_349 = V_337 ;
V_34 = F_345 ( & V_350 ) ;
if ( V_34 ) {
F_298 ( V_351 L_10 ) ;
goto V_352;
}
F_346 ( & V_353 ) ;
V_202 . V_354 = F_333 ;
V_202 . V_355 = F_334 ;
V_34 = F_323 () ;
if ( V_34 ) {
F_298 ( V_351 L_11 ) ;
goto V_356;
}
return 0 ;
V_356:
F_347 ( & V_353 ) ;
V_352:
F_348 () ;
V_118:
F_349 ( V_346 ) ;
V_347:
F_350 ( & V_345 ) ;
F_351 ( & V_343 ) ;
V_344:
V_342:
F_352 () ;
V_340:
F_35 ( V_293 ) ;
V_339:
if ( V_133 )
F_353 ( V_133 ) ;
if ( V_132 )
F_353 ( V_132 ) ;
F_353 ( V_131 ) ;
V_108:
F_354 () ;
V_338:
return V_34 ;
}
void F_355 ( void )
{
F_327 () ;
F_356 ( & V_350 ) ;
F_349 ( V_346 ) ;
F_348 () ;
F_347 ( & V_353 ) ;
F_350 ( & V_345 ) ;
F_351 ( & V_343 ) ;
F_304 ( F_300 , NULL , 1 ) ;
F_352 () ;
F_354 () ;
F_35 ( V_293 ) ;
F_353 ( V_133 ) ;
F_353 ( V_132 ) ;
F_353 ( V_131 ) ;
}
