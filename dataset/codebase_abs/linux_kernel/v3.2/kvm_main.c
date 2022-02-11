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
int V_27 = V_18 -> V_28 ;
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
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
if ( V_48 )
F_36 ( V_18 ) ;
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
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
if ( V_48 )
F_36 ( V_18 ) ;
}
static void F_60 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_54 ,
unsigned long V_55 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_18 -> V_52 ++ ;
V_18 -> V_56 -- ;
F_55 ( & V_18 -> V_51 ) ;
F_61 ( V_18 -> V_56 < 0 ) ;
}
static int F_62 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_58 , V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_58 = F_63 ( V_18 , V_47 ) ;
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
if ( V_58 )
F_36 ( V_18 ) ;
return V_58 ;
}
static int F_64 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_58 , V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_53 ( & V_18 -> V_51 ) ;
V_58 = F_65 ( V_18 , V_47 ) ;
F_55 ( & V_18 -> V_51 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
return V_58 ;
}
static void F_66 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_18 * V_18 = F_49 ( V_44 ) ;
int V_49 ;
V_49 = F_52 ( & V_18 -> V_50 ) ;
F_67 ( V_18 ) ;
F_56 ( & V_18 -> V_50 , V_49 ) ;
}
static int F_68 ( struct V_18 * V_18 )
{
V_18 -> V_43 . V_59 = & V_60 ;
return F_69 ( & V_18 -> V_43 , V_11 -> V_46 ) ;
}
static int F_68 ( struct V_18 * V_18 )
{
return 0 ;
}
static struct V_18 * F_70 ( void )
{
int V_34 , V_20 ;
struct V_18 * V_18 = F_71 () ;
if ( ! V_18 )
return F_72 ( - V_39 ) ;
V_34 = F_73 ( V_18 ) ;
if ( V_34 )
goto V_61;
V_34 = F_74 () ;
if ( V_34 )
goto V_61;
#ifdef F_75
F_76 ( & V_18 -> V_62 ) ;
F_76 ( & V_18 -> V_63 ) ;
#endif
V_34 = - V_39 ;
V_18 -> V_64 = F_77 ( sizeof( struct V_65 ) , V_37 ) ;
if ( ! V_18 -> V_64 )
goto V_66;
if ( F_78 ( & V_18 -> V_50 ) )
goto V_66;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ ) {
V_18 -> V_68 [ V_20 ] = F_77 ( sizeof( struct V_69 ) ,
V_37 ) ;
if ( ! V_18 -> V_68 [ V_20 ] )
goto V_70;
}
F_79 ( & V_18 -> V_51 ) ;
V_18 -> V_46 = V_11 -> V_46 ;
F_80 ( & V_18 -> V_46 -> V_71 ) ;
F_81 ( V_18 ) ;
F_40 ( & V_18 -> V_72 ) ;
F_40 ( & V_18 -> V_73 ) ;
F_40 ( & V_18 -> V_74 ) ;
F_82 ( & V_18 -> V_75 , 1 ) ;
V_34 = F_68 ( V_18 ) ;
if ( V_34 )
goto V_70;
F_83 ( & V_76 ) ;
F_84 ( & V_18 -> V_77 , & V_77 ) ;
F_85 ( & V_76 ) ;
return V_18 ;
V_70:
F_86 ( & V_18 -> V_50 ) ;
V_66:
F_87 () ;
V_61:
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
F_88 ( V_18 -> V_68 [ V_20 ] ) ;
F_88 ( V_18 -> V_64 ) ;
F_89 ( V_18 ) ;
return F_72 ( V_34 ) ;
}
static void F_90 ( struct V_78 * V_79 )
{
if ( ! V_79 -> V_80 )
return;
if ( 2 * F_91 ( V_79 ) > V_57 )
F_92 ( V_79 -> V_81 ) ;
else
F_88 ( V_79 -> V_81 ) ;
V_79 -> V_80 = NULL ;
V_79 -> V_81 = NULL ;
}
static void F_93 ( struct V_78 * free ,
struct V_78 * V_82 )
{
int V_20 ;
if ( ! V_82 || free -> V_83 != V_82 -> V_83 )
F_92 ( free -> V_83 ) ;
if ( ! V_82 || free -> V_80 != V_82 -> V_80 )
F_90 ( free ) ;
for ( V_20 = 0 ; V_20 < V_84 - 1 ; ++ V_20 ) {
if ( ! V_82 || free -> V_85 [ V_20 ] != V_82 -> V_85 [ V_20 ] ) {
F_92 ( free -> V_85 [ V_20 ] ) ;
free -> V_85 [ V_20 ] = NULL ;
}
}
free -> V_86 = 0 ;
free -> V_83 = NULL ;
}
void F_94 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_65 * V_87 = V_18 -> V_64 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_88 ; ++ V_20 )
F_93 ( & V_87 -> V_64 [ V_20 ] , NULL ) ;
F_88 ( V_18 -> V_64 ) ;
}
static void F_95 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_45 * V_46 = V_18 -> V_46 ;
F_96 ( V_18 ) ;
F_83 ( & V_76 ) ;
F_97 ( & V_18 -> V_77 ) ;
F_85 ( & V_76 ) ;
F_98 ( V_18 ) ;
for ( V_20 = 0 ; V_20 < V_67 ; V_20 ++ )
F_99 ( V_18 -> V_68 [ V_20 ] ) ;
F_100 ( V_18 ) ;
#if F_101 ( V_89 ) && F_101 ( V_90 )
F_102 ( & V_18 -> V_43 , V_18 -> V_46 ) ;
#else
F_67 ( V_18 ) ;
#endif
F_103 ( V_18 ) ;
F_94 ( V_18 ) ;
F_86 ( & V_18 -> V_50 ) ;
F_89 ( V_18 ) ;
F_87 () ;
F_104 ( V_46 ) ;
}
void F_105 ( struct V_18 * V_18 )
{
F_80 ( & V_18 -> V_75 ) ;
}
void F_106 ( struct V_18 * V_18 )
{
if ( F_107 ( & V_18 -> V_75 ) )
F_95 ( V_18 ) ;
}
static int F_108 ( struct V_91 * V_91 , struct V_92 * V_93 )
{
struct V_18 * V_18 = V_93 -> V_94 ;
F_109 ( V_18 ) ;
F_106 ( V_18 ) ;
return 0 ;
}
static int F_110 ( struct V_78 * V_79 )
{
unsigned long V_95 = 2 * F_91 ( V_79 ) ;
if ( V_95 > V_57 )
V_79 -> V_80 = F_111 ( V_95 ) ;
else
V_79 -> V_80 = F_77 ( V_95 , V_37 ) ;
if ( ! V_79 -> V_80 )
return - V_39 ;
V_79 -> V_81 = V_79 -> V_80 ;
return 0 ;
}
int F_112 ( struct V_18 * V_18 ,
struct V_96 * V_97 ,
int V_98 )
{
int V_34 ;
T_4 V_99 ;
unsigned long V_86 ;
unsigned long V_20 ;
struct V_78 * V_79 ;
struct V_78 V_100 , V_101 ;
struct V_65 * V_87 , * V_102 ;
V_34 = - V_103 ;
if ( V_97 -> V_104 & ( V_57 - 1 ) )
goto V_105;
if ( V_97 -> V_106 & ( V_57 - 1 ) )
goto V_105;
if ( V_98 &&
( ( V_97 -> V_107 & ( V_57 - 1 ) ) ||
! F_113 ( V_108 ,
( void V_109 * ) ( unsigned long ) V_97 -> V_107 ,
V_97 -> V_104 ) ) )
goto V_105;
if ( V_97 -> V_110 >= V_111 + V_112 )
goto V_105;
if ( V_97 -> V_106 + V_97 -> V_104 < V_97 -> V_106 )
goto V_105;
V_79 = & V_18 -> V_64 -> V_64 [ V_97 -> V_110 ] ;
V_99 = V_97 -> V_106 >> V_113 ;
V_86 = V_97 -> V_104 >> V_113 ;
V_34 = - V_103 ;
if ( V_86 > V_114 )
goto V_105;
if ( ! V_86 )
V_97 -> V_115 &= ~ V_116 ;
V_101 = V_100 = * V_79 ;
V_101 . V_33 = V_97 -> V_110 ;
V_101 . V_99 = V_99 ;
V_101 . V_86 = V_86 ;
V_101 . V_115 = V_97 -> V_115 ;
V_34 = - V_103 ;
if ( V_86 && V_100 . V_86 && V_86 != V_100 . V_86 )
goto V_117;
V_34 = - V_118 ;
for ( V_20 = 0 ; V_20 < V_111 ; ++ V_20 ) {
struct V_78 * V_119 = & V_18 -> V_64 -> V_64 [ V_20 ] ;
if ( V_119 == V_79 || ! V_119 -> V_86 )
continue;
if ( ! ( ( V_99 + V_86 <= V_119 -> V_99 ) ||
( V_99 >= V_119 -> V_99 + V_119 -> V_86 ) ) )
goto V_117;
}
if ( ! ( V_101 . V_115 & V_116 ) )
V_101 . V_80 = NULL ;
V_34 = - V_39 ;
#ifndef F_114
if ( V_86 && ! V_101 . V_83 ) {
V_101 . V_83 = F_111 ( V_86 * sizeof( * V_101 . V_83 ) ) ;
if ( ! V_101 . V_83 )
goto V_117;
V_101 . V_98 = V_98 ;
V_101 . V_107 = V_97 -> V_107 ;
}
if ( ! V_86 )
goto V_120;
for ( V_20 = 0 ; V_20 < V_84 - 1 ; ++ V_20 ) {
unsigned long V_121 ;
unsigned long V_122 ;
int V_123 ;
int V_124 = V_20 + 2 ;
( void ) V_124 ;
if ( V_101 . V_85 [ V_20 ] )
continue;
V_123 = 1 + ( ( V_99 + V_86 - 1 )
>> F_115 ( V_124 ) ) ;
V_123 -= V_99 >> F_115 ( V_124 ) ;
V_101 . V_85 [ V_20 ] = F_111 ( V_123 * sizeof( * V_101 . V_85 [ V_20 ] ) ) ;
if ( ! V_101 . V_85 [ V_20 ] )
goto V_117;
if ( V_99 & ( F_116 ( V_124 ) - 1 ) )
V_101 . V_85 [ V_20 ] [ 0 ] . V_125 = 1 ;
if ( ( V_99 + V_86 ) & ( F_116 ( V_124 ) - 1 ) )
V_101 . V_85 [ V_20 ] [ V_123 - 1 ] . V_125 = 1 ;
V_121 = V_101 . V_107 >> V_113 ;
if ( ( V_99 ^ V_121 ) & ( F_116 ( V_124 ) - 1 ) ||
! V_126 )
for ( V_122 = 0 ; V_122 < V_123 ; ++ V_122 )
V_101 . V_85 [ V_20 ] [ V_122 ] . V_125 = 1 ;
}
V_120:
if ( ( V_101 . V_115 & V_116 ) && ! V_101 . V_80 ) {
if ( F_110 ( & V_101 ) < 0 )
goto V_117;
}
#else
V_101 . V_98 = V_98 ;
if ( V_98 )
V_101 . V_107 = V_97 -> V_107 ;
#endif
if ( ! V_86 ) {
V_34 = - V_39 ;
V_87 = F_77 ( sizeof( struct V_65 ) , V_37 ) ;
if ( ! V_87 )
goto V_117;
memcpy ( V_87 , V_18 -> V_64 , sizeof( struct V_65 ) ) ;
if ( V_97 -> V_110 >= V_87 -> V_88 )
V_87 -> V_88 = V_97 -> V_110 + 1 ;
V_87 -> V_127 ++ ;
V_87 -> V_64 [ V_97 -> V_110 ] . V_115 |= V_128 ;
V_102 = V_18 -> V_64 ;
F_12 ( V_18 -> V_64 , V_87 ) ;
F_117 ( & V_18 -> V_50 ) ;
F_67 ( V_18 ) ;
F_88 ( V_102 ) ;
}
V_34 = F_118 ( V_18 , & V_101 , V_100 , V_97 , V_98 ) ;
if ( V_34 )
goto V_117;
if ( V_86 ) {
V_34 = F_119 ( V_18 , & V_101 ) ;
if ( V_34 )
goto V_117;
}
V_34 = - V_39 ;
V_87 = F_77 ( sizeof( struct V_65 ) , V_37 ) ;
if ( ! V_87 )
goto V_117;
memcpy ( V_87 , V_18 -> V_64 , sizeof( struct V_65 ) ) ;
if ( V_97 -> V_110 >= V_87 -> V_88 )
V_87 -> V_88 = V_97 -> V_110 + 1 ;
V_87 -> V_127 ++ ;
if ( ! V_86 ) {
V_101 . V_83 = NULL ;
V_101 . V_80 = NULL ;
for ( V_20 = 0 ; V_20 < V_84 - 1 ; ++ V_20 )
V_101 . V_85 [ V_20 ] = NULL ;
}
V_87 -> V_64 [ V_97 -> V_110 ] = V_101 ;
V_102 = V_18 -> V_64 ;
F_12 ( V_18 -> V_64 , V_87 ) ;
F_117 ( & V_18 -> V_50 ) ;
F_120 ( V_18 , V_97 , V_100 , V_98 ) ;
if ( V_86 && V_100 . V_99 != V_97 -> V_106 >> V_113 )
F_67 ( V_18 ) ;
F_93 ( & V_100 , & V_101 ) ;
F_88 ( V_102 ) ;
return 0 ;
V_117:
F_93 ( & V_101 , & V_100 ) ;
V_105:
return V_34 ;
}
int F_121 ( struct V_18 * V_18 ,
struct V_96 * V_97 ,
int V_98 )
{
int V_34 ;
F_9 ( & V_18 -> V_74 ) ;
V_34 = F_112 ( V_18 , V_97 , V_98 ) ;
F_24 ( & V_18 -> V_74 ) ;
return V_34 ;
}
int F_122 ( struct V_18 * V_18 ,
struct
V_96 * V_97 ,
int V_98 )
{
if ( V_97 -> V_110 >= V_111 )
return - V_103 ;
return F_121 ( V_18 , V_97 , V_98 ) ;
}
int F_123 ( struct V_18 * V_18 ,
struct V_129 * log , int * V_130 )
{
struct V_78 * V_79 ;
int V_34 , V_20 ;
unsigned long V_131 ;
unsigned long V_132 = 0 ;
V_34 = - V_103 ;
if ( log -> V_110 >= V_111 )
goto V_105;
V_79 = & V_18 -> V_64 -> V_64 [ log -> V_110 ] ;
V_34 = - V_133 ;
if ( ! V_79 -> V_80 )
goto V_105;
V_131 = F_91 ( V_79 ) ;
for ( V_20 = 0 ; ! V_132 && V_20 < V_131 / sizeof( long ) ; ++ V_20 )
V_132 = V_79 -> V_80 [ V_20 ] ;
V_34 = - V_134 ;
if ( F_124 ( log -> V_80 , V_79 -> V_80 , V_131 ) )
goto V_105;
if ( V_132 )
* V_130 = 1 ;
V_34 = 0 ;
V_105:
return V_34 ;
}
void F_125 ( void )
{
V_126 = false ;
}
int F_126 ( struct V_3 * V_3 )
{
return V_3 == V_135 || V_3 == V_136 || V_3 == V_137 ;
}
int F_127 ( T_1 V_1 )
{
return V_1 == V_138 || V_1 == V_139 || V_1 == V_140 ;
}
int F_128 ( T_1 V_1 )
{
return V_1 == V_139 ;
}
int F_129 ( T_1 V_1 )
{
return V_1 == V_140 ;
}
int F_130 ( T_1 V_1 )
{
return V_1 == V_138 ;
}
int F_131 ( T_1 V_1 )
{
return V_1 == V_139 || V_1 == V_140 ;
}
static inline unsigned long F_132 ( void )
{
return V_141 ;
}
int F_133 ( unsigned long V_142 )
{
return V_142 == F_132 () ;
}
static struct V_78 * F_134 ( struct V_65 * V_87 ,
T_4 V_143 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_87 -> V_88 ; ++ V_20 ) {
struct V_78 * V_79 = & V_87 -> V_64 [ V_20 ] ;
if ( V_143 >= V_79 -> V_99
&& V_143 < V_79 -> V_99 + V_79 -> V_86 )
return V_79 ;
}
return NULL ;
}
struct V_78 * F_135 ( struct V_18 * V_18 , T_4 V_143 )
{
return F_134 ( V_65 ( V_18 ) , V_143 ) ;
}
int F_136 ( struct V_18 * V_18 , T_4 V_143 )
{
int V_20 ;
struct V_65 * V_87 = V_65 ( V_18 ) ;
for ( V_20 = 0 ; V_20 < V_111 ; ++ V_20 ) {
struct V_78 * V_79 = & V_87 -> V_64 [ V_20 ] ;
if ( V_79 -> V_115 & V_128 )
continue;
if ( V_143 >= V_79 -> V_99
&& V_143 < V_79 -> V_99 + V_79 -> V_86 )
return 1 ;
}
return 0 ;
}
unsigned long F_137 ( struct V_18 * V_18 , T_4 V_143 )
{
struct V_144 * V_145 ;
unsigned long V_142 , V_146 ;
V_146 = V_57 ;
V_142 = F_138 ( V_18 , V_143 ) ;
if ( F_133 ( V_142 ) )
return V_57 ;
F_139 ( & V_11 -> V_46 -> V_147 ) ;
V_145 = F_140 ( V_11 -> V_46 , V_142 ) ;
if ( ! V_145 )
goto V_105;
V_146 = F_141 ( V_145 ) ;
V_105:
F_142 ( & V_11 -> V_46 -> V_147 ) ;
return V_146 ;
}
static unsigned long F_143 ( struct V_78 * V_110 , T_4 V_143 ,
T_4 * V_148 )
{
if ( ! V_110 || V_110 -> V_115 & V_128 )
return F_132 () ;
if ( V_148 )
* V_148 = V_110 -> V_86 - ( V_143 - V_110 -> V_99 ) ;
return F_144 ( V_110 , V_143 ) ;
}
unsigned long F_138 ( struct V_18 * V_18 , T_4 V_143 )
{
return F_143 ( F_135 ( V_18 , V_143 ) , V_143 , NULL ) ;
}
static T_1 F_145 ( void )
{
F_146 ( V_137 ) ;
return V_140 ;
}
int F_147 ( struct V_149 * V_150 , struct V_45 * V_46 ,
unsigned long V_54 , int V_151 , struct V_3 * * V_3 )
{
int V_115 = V_152 | V_153 | V_154 | V_155 ;
if ( V_151 )
V_115 |= V_156 ;
return F_148 ( V_150 , V_46 , V_54 , 1 , V_115 , V_3 , NULL , NULL ) ;
}
static inline int F_149 ( unsigned long V_142 )
{
int V_157 , V_115 = V_152 | V_154 | V_156 ;
V_157 = F_148 ( V_11 , V_11 -> V_46 , V_142 , 1 ,
V_115 , NULL , NULL , NULL ) ;
return V_157 == - V_158 ;
}
static T_1 F_150 ( struct V_18 * V_18 , unsigned long V_142 , bool V_159 ,
bool * V_160 , bool V_161 , bool * V_162 )
{
struct V_3 * V_3 [ 1 ] ;
int V_86 = 0 ;
T_1 V_1 ;
F_61 ( V_159 && V_160 ) ;
F_61 ( ! V_161 && ! V_162 ) ;
if ( V_162 )
* V_162 = true ;
if ( V_159 || V_160 )
V_86 = F_151 ( V_142 , 1 , 1 , V_3 ) ;
if ( F_10 ( V_86 != 1 ) && ! V_159 ) {
F_152 () ;
if ( V_162 )
* V_162 = V_161 ;
if ( V_160 ) {
F_139 ( & V_11 -> V_46 -> V_147 ) ;
V_86 = F_147 ( V_11 , V_11 -> V_46 ,
V_142 , V_161 , V_3 ) ;
F_142 ( & V_11 -> V_46 -> V_147 ) ;
} else
V_86 = F_153 ( V_142 , 1 , V_161 ,
V_3 ) ;
if ( F_10 ( ! V_161 ) && V_86 == 1 ) {
struct V_3 * V_163 [ 1 ] ;
V_86 = F_151 ( V_142 , 1 , 1 , V_163 ) ;
if ( V_86 == 1 ) {
* V_162 = true ;
F_154 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_163 [ 0 ] ;
}
V_86 = 1 ;
}
}
if ( F_10 ( V_86 != 1 ) ) {
struct V_144 * V_145 ;
if ( V_159 )
return F_145 () ;
F_139 ( & V_11 -> V_46 -> V_147 ) ;
if ( V_86 == - V_158 ||
( ! V_160 && F_149 ( V_142 ) ) ) {
F_142 ( & V_11 -> V_46 -> V_147 ) ;
F_146 ( V_136 ) ;
return F_155 ( V_136 ) ;
}
V_145 = F_156 ( V_11 -> V_46 , V_142 , V_142 + 1 ) ;
if ( V_145 == NULL )
V_1 = F_145 () ;
else if ( ( V_145 -> V_164 & V_165 ) ) {
V_1 = ( ( V_142 - V_145 -> V_166 ) >> V_113 ) +
V_145 -> V_167 ;
F_61 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_160 && ( V_145 -> V_164 & V_168 ) )
* V_160 = true ;
V_1 = F_145 () ;
}
F_142 ( & V_11 -> V_46 -> V_147 ) ;
} else
V_1 = F_155 ( V_3 [ 0 ] ) ;
return V_1 ;
}
T_1 F_157 ( struct V_18 * V_18 , unsigned long V_142 )
{
return F_150 ( V_18 , V_142 , true , NULL , true , NULL ) ;
}
static T_1 F_158 ( struct V_18 * V_18 , T_4 V_143 , bool V_159 , bool * V_160 ,
bool V_161 , bool * V_162 )
{
unsigned long V_142 ;
if ( V_160 )
* V_160 = false ;
V_142 = F_138 ( V_18 , V_143 ) ;
if ( F_133 ( V_142 ) ) {
F_146 ( V_135 ) ;
return F_155 ( V_135 ) ;
}
return F_150 ( V_18 , V_142 , V_159 , V_160 , V_161 , V_162 ) ;
}
T_1 F_159 ( struct V_18 * V_18 , T_4 V_143 )
{
return F_158 ( V_18 , V_143 , true , NULL , true , NULL ) ;
}
T_1 F_160 ( struct V_18 * V_18 , T_4 V_143 , bool * V_160 ,
bool V_161 , bool * V_162 )
{
return F_158 ( V_18 , V_143 , false , V_160 , V_161 , V_162 ) ;
}
T_1 F_161 ( struct V_18 * V_18 , T_4 V_143 )
{
return F_158 ( V_18 , V_143 , false , NULL , true , NULL ) ;
}
T_1 F_162 ( struct V_18 * V_18 , T_4 V_143 , bool V_161 ,
bool * V_162 )
{
return F_158 ( V_18 , V_143 , false , NULL , V_161 , V_162 ) ;
}
T_1 F_163 ( struct V_18 * V_18 ,
struct V_78 * V_110 , T_4 V_143 )
{
unsigned long V_142 = F_144 ( V_110 , V_143 ) ;
return F_150 ( V_18 , V_142 , false , NULL , true , NULL ) ;
}
int F_164 ( struct V_18 * V_18 , T_4 V_143 , struct V_3 * * V_169 ,
int V_148 )
{
unsigned long V_142 ;
T_4 V_170 ;
V_142 = F_143 ( F_135 ( V_18 , V_143 ) , V_143 , & V_170 ) ;
if ( F_133 ( V_142 ) )
return - 1 ;
if ( V_170 < V_148 )
return 0 ;
return F_151 ( V_142 , V_148 , 1 , V_169 ) ;
}
struct V_3 * F_165 ( struct V_18 * V_18 , T_4 V_143 )
{
T_1 V_1 ;
V_1 = F_161 ( V_18 , V_143 ) ;
if ( ! F_1 ( V_1 ) )
return F_3 ( V_1 ) ;
F_166 ( F_1 ( V_1 ) ) ;
F_146 ( V_135 ) ;
return V_135 ;
}
void F_167 ( struct V_3 * V_3 )
{
F_168 ( F_155 ( V_3 ) ) ;
}
void F_168 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_154 ( F_3 ( V_1 ) ) ;
}
void F_169 ( struct V_3 * V_3 )
{
F_170 ( F_155 ( V_3 ) ) ;
}
void F_170 ( T_1 V_1 )
{
F_171 ( V_1 ) ;
F_168 ( V_1 ) ;
}
void F_172 ( struct V_3 * V_3 )
{
F_171 ( F_155 ( V_3 ) ) ;
}
void F_171 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_173 ( V_3 ) ;
}
}
void F_174 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_175 ( F_3 ( V_1 ) ) ;
}
void F_176 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_146 ( F_3 ( V_1 ) ) ;
}
static int F_177 ( unsigned long V_171 , int V_172 )
{
if ( V_171 > V_57 - V_172 )
return V_57 - V_172 ;
else
return V_171 ;
}
int F_178 ( struct V_18 * V_18 , T_4 V_143 , void * V_173 , int V_172 ,
int V_171 )
{
int V_34 ;
unsigned long V_142 ;
V_142 = F_138 ( V_18 , V_143 ) ;
if ( F_133 ( V_142 ) )
return - V_134 ;
V_34 = F_179 ( V_173 , ( void V_109 * ) V_142 + V_172 , V_171 ) ;
if ( V_34 )
return - V_134 ;
return 0 ;
}
int F_180 ( struct V_18 * V_18 , T_5 V_174 , void * V_173 , unsigned long V_171 )
{
T_4 V_143 = V_174 >> V_113 ;
int V_175 ;
int V_172 = F_181 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_177 ( V_171 , V_172 ) ) != 0 ) {
V_176 = F_178 ( V_18 , V_143 , V_173 , V_172 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_172 = 0 ;
V_171 -= V_175 ;
V_173 += V_175 ;
++ V_143 ;
}
return 0 ;
}
int F_182 ( struct V_18 * V_18 , T_5 V_174 , void * V_173 ,
unsigned long V_171 )
{
int V_34 ;
unsigned long V_142 ;
T_4 V_143 = V_174 >> V_113 ;
int V_172 = F_181 ( V_174 ) ;
V_142 = F_138 ( V_18 , V_143 ) ;
if ( F_133 ( V_142 ) )
return - V_134 ;
F_183 () ;
V_34 = F_184 ( V_173 , ( void V_109 * ) V_142 + V_172 , V_171 ) ;
F_185 () ;
if ( V_34 )
return - V_134 ;
return 0 ;
}
int F_186 ( struct V_18 * V_18 , T_4 V_143 , const void * V_173 ,
int V_172 , int V_171 )
{
int V_34 ;
unsigned long V_142 ;
V_142 = F_138 ( V_18 , V_143 ) ;
if ( F_133 ( V_142 ) )
return - V_134 ;
V_34 = F_187 ( ( void V_109 * ) V_142 + V_172 , V_173 , V_171 ) ;
if ( V_34 )
return - V_134 ;
F_188 ( V_18 , V_143 ) ;
return 0 ;
}
int F_189 ( struct V_18 * V_18 , T_5 V_174 , const void * V_173 ,
unsigned long V_171 )
{
T_4 V_143 = V_174 >> V_113 ;
int V_175 ;
int V_172 = F_181 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_177 ( V_171 , V_172 ) ) != 0 ) {
V_176 = F_186 ( V_18 , V_143 , V_173 , V_172 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_172 = 0 ;
V_171 -= V_175 ;
V_173 += V_175 ;
++ V_143 ;
}
return 0 ;
}
int F_190 ( struct V_18 * V_18 , struct V_177 * V_178 ,
T_5 V_174 )
{
struct V_65 * V_87 = V_65 ( V_18 ) ;
int V_172 = F_181 ( V_174 ) ;
T_4 V_143 = V_174 >> V_113 ;
V_178 -> V_174 = V_174 ;
V_178 -> V_127 = V_87 -> V_127 ;
V_178 -> V_79 = F_134 ( V_87 , V_143 ) ;
V_178 -> V_179 = F_143 ( V_178 -> V_79 , V_143 , NULL ) ;
if ( ! F_133 ( V_178 -> V_179 ) )
V_178 -> V_179 += V_172 ;
else
return - V_134 ;
return 0 ;
}
int F_191 ( struct V_18 * V_18 , struct V_177 * V_178 ,
void * V_173 , unsigned long V_171 )
{
struct V_65 * V_87 = V_65 ( V_18 ) ;
int V_34 ;
if ( V_87 -> V_127 != V_178 -> V_127 )
F_190 ( V_18 , V_178 , V_178 -> V_174 ) ;
if ( F_133 ( V_178 -> V_179 ) )
return - V_134 ;
V_34 = F_187 ( ( void V_109 * ) V_178 -> V_179 , V_173 , V_171 ) ;
if ( V_34 )
return - V_134 ;
F_192 ( V_18 , V_178 -> V_79 , V_178 -> V_174 >> V_113 ) ;
return 0 ;
}
int F_193 ( struct V_18 * V_18 , struct V_177 * V_178 ,
void * V_173 , unsigned long V_171 )
{
struct V_65 * V_87 = V_65 ( V_18 ) ;
int V_34 ;
if ( V_87 -> V_127 != V_178 -> V_127 )
F_190 ( V_18 , V_178 , V_178 -> V_174 ) ;
if ( F_133 ( V_178 -> V_179 ) )
return - V_134 ;
V_34 = F_179 ( V_173 , ( void V_109 * ) V_178 -> V_179 , V_171 ) ;
if ( V_34 )
return - V_134 ;
return 0 ;
}
int F_194 ( struct V_18 * V_18 , T_4 V_143 , int V_172 , int V_171 )
{
return F_186 ( V_18 , V_143 , ( const void * ) V_180 ,
V_172 , V_171 ) ;
}
int F_195 ( struct V_18 * V_18 , T_5 V_174 , unsigned long V_171 )
{
T_4 V_143 = V_174 >> V_113 ;
int V_175 ;
int V_172 = F_181 ( V_174 ) ;
int V_176 ;
while ( ( V_175 = F_177 ( V_171 , V_172 ) ) != 0 ) {
V_176 = F_194 ( V_18 , V_143 , V_172 , V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
V_172 = 0 ;
V_171 -= V_175 ;
++ V_143 ;
}
return 0 ;
}
void F_192 ( struct V_18 * V_18 , struct V_78 * V_79 ,
T_4 V_143 )
{
if ( V_79 && V_79 -> V_80 ) {
unsigned long V_181 = V_143 - V_79 -> V_99 ;
F_196 ( V_181 , V_79 -> V_80 ) ;
}
}
void F_188 ( struct V_18 * V_18 , T_4 V_143 )
{
struct V_78 * V_79 ;
V_79 = F_135 ( V_18 , V_143 ) ;
F_192 ( V_18 , V_79 , V_143 ) ;
}
void F_197 ( struct V_6 * V_7 )
{
F_198 ( V_182 ) ;
for (; ; ) {
F_199 ( & V_7 -> V_36 , & V_182 , V_183 ) ;
if ( F_200 ( V_7 ) ) {
F_29 ( V_184 , V_7 ) ;
break;
}
if ( F_201 ( V_7 ) )
break;
if ( F_202 ( V_11 ) )
break;
F_203 () ;
}
F_204 ( & V_7 -> V_36 , & V_182 ) ;
}
void F_205 ( struct V_6 * V_7 )
{
if ( ! F_206 () )
return;
F_207 () ;
}
void F_208 ( struct V_6 * V_21 )
{
struct V_18 * V_18 = V_21 -> V_18 ;
struct V_6 * V_7 ;
int V_185 = V_21 -> V_18 -> V_185 ;
int V_186 = 0 ;
int V_187 ;
int V_20 ;
for ( V_187 = 0 ; V_187 < 2 && ! V_186 ; V_187 ++ ) {
F_28 (i, vcpu, kvm) {
struct V_149 * V_188 = NULL ;
struct V_10 * V_10 ;
if ( ! V_187 && V_20 < V_185 ) {
V_20 = V_185 ;
continue;
} else if ( V_187 && V_20 > V_185 )
break;
if ( V_7 == V_21 )
continue;
if ( F_209 ( & V_7 -> V_36 ) )
continue;
F_210 () ;
V_10 = F_211 ( V_7 -> V_10 ) ;
if ( V_10 )
V_188 = F_212 ( V_7 -> V_10 , V_13 ) ;
F_213 () ;
if ( ! V_188 )
continue;
if ( V_188 -> V_115 & V_189 ) {
F_214 ( V_188 ) ;
continue;
}
if ( F_215 ( V_188 , 1 ) ) {
F_214 ( V_188 ) ;
V_18 -> V_185 = V_20 ;
V_186 = 1 ;
break;
}
F_214 ( V_188 ) ;
}
}
}
static int F_216 ( struct V_144 * V_145 , struct V_190 * V_191 )
{
struct V_6 * V_7 = V_145 -> V_192 -> V_94 ;
struct V_3 * V_3 ;
if ( V_191 -> V_193 == 0 )
V_3 = F_217 ( V_7 -> V_41 ) ;
#ifdef F_218
else if ( V_191 -> V_193 == V_194 )
V_3 = F_217 ( V_7 -> V_195 . V_196 ) ;
#endif
#ifdef F_219
else if ( V_191 -> V_193 == F_219 )
V_3 = F_217 ( V_7 -> V_18 -> V_197 ) ;
#endif
else
return V_198 ;
F_146 ( V_3 ) ;
V_191 -> V_3 = V_3 ;
return 0 ;
}
static int F_220 ( struct V_92 * V_92 , struct V_144 * V_145 )
{
V_145 -> V_199 = & V_200 ;
return 0 ;
}
static int F_221 ( struct V_91 * V_91 , struct V_92 * V_93 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
F_106 ( V_7 -> V_18 ) ;
return 0 ;
}
static int F_222 ( struct V_6 * V_7 )
{
return F_223 ( L_1 , & V_201 , V_7 , V_202 ) ;
}
static int F_224 ( struct V_18 * V_18 , T_6 V_33 )
{
int V_34 ;
struct V_6 * V_7 , * V_203 ;
V_7 = F_225 ( V_18 , V_33 ) ;
if ( F_226 ( V_7 ) )
return F_227 ( V_7 ) ;
F_228 ( & V_7 -> V_16 , & V_204 ) ;
V_34 = F_229 ( V_7 ) ;
if ( V_34 )
goto V_205;
F_9 ( & V_18 -> V_72 ) ;
if ( F_230 ( & V_18 -> V_206 ) == V_207 ) {
V_34 = - V_103 ;
goto V_208;
}
F_28 (r, v, kvm)
if ( V_203 -> V_35 == V_33 ) {
V_34 = - V_118 ;
goto V_208;
}
F_61 ( V_18 -> V_209 [ F_230 ( & V_18 -> V_206 ) ] ) ;
F_105 ( V_18 ) ;
V_34 = F_222 ( V_7 ) ;
if ( V_34 < 0 ) {
F_106 ( V_18 ) ;
goto V_208;
}
V_18 -> V_209 [ F_230 ( & V_18 -> V_206 ) ] = V_7 ;
F_231 () ;
F_80 ( & V_18 -> V_206 ) ;
#ifdef F_232
if ( V_18 -> V_210 == V_33 )
V_18 -> V_211 = V_7 ;
#endif
F_24 ( & V_18 -> V_72 ) ;
return V_34 ;
V_208:
F_24 ( & V_18 -> V_72 ) ;
V_205:
F_233 ( V_7 ) ;
return V_34 ;
}
static int F_234 ( struct V_6 * V_7 , T_7 * V_212 )
{
if ( V_212 ) {
F_235 ( V_212 , F_236 ( V_213 ) | F_236 ( V_214 ) ) ;
V_7 -> V_215 = 1 ;
V_7 -> V_212 = * V_212 ;
} else
V_7 -> V_215 = 0 ;
return 0 ;
}
static long F_237 ( struct V_92 * V_93 ,
unsigned int V_216 , unsigned long V_217 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
void V_109 * V_218 = ( void V_109 * ) V_217 ;
int V_34 ;
struct V_219 * V_220 = NULL ;
struct V_221 * V_221 = NULL ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_222 ;
#if F_101 ( F_114 ) || F_101 ( V_223 )
if ( V_216 == V_224 || V_216 == V_225 )
return F_238 ( V_93 , V_216 , V_217 ) ;
#endif
F_8 ( V_7 ) ;
switch ( V_216 ) {
case V_226 :
V_34 = - V_103 ;
if ( V_217 )
goto V_105;
V_34 = F_239 ( V_7 , V_7 -> V_41 ) ;
F_240 ( V_7 -> V_41 -> V_227 , V_34 ) ;
break;
case V_228 : {
struct V_229 * V_229 ;
V_34 = - V_39 ;
V_229 = F_77 ( sizeof( struct V_229 ) , V_37 ) ;
if ( ! V_229 )
goto V_105;
V_34 = F_241 ( V_7 , V_229 ) ;
if ( V_34 )
goto V_230;
V_34 = - V_134 ;
if ( F_124 ( V_218 , V_229 , sizeof( struct V_229 ) ) )
goto V_230;
V_34 = 0 ;
V_230:
F_88 ( V_229 ) ;
break;
}
case V_231 : {
struct V_229 * V_229 ;
V_34 = - V_39 ;
V_229 = F_77 ( sizeof( struct V_229 ) , V_37 ) ;
if ( ! V_229 )
goto V_105;
V_34 = - V_134 ;
if ( F_242 ( V_229 , V_218 , sizeof( struct V_229 ) ) )
goto V_232;
V_34 = F_243 ( V_7 , V_229 ) ;
if ( V_34 )
goto V_232;
V_34 = 0 ;
V_232:
F_88 ( V_229 ) ;
break;
}
case V_233 : {
V_221 = F_77 ( sizeof( struct V_221 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_221 )
goto V_105;
V_34 = F_244 ( V_7 , V_221 ) ;
if ( V_34 )
goto V_105;
V_34 = - V_134 ;
if ( F_124 ( V_218 , V_221 , sizeof( struct V_221 ) ) )
goto V_105;
V_34 = 0 ;
break;
}
case V_234 : {
V_221 = F_245 ( sizeof( struct V_221 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_221 )
goto V_105;
V_34 = - V_134 ;
if ( F_242 ( V_221 , V_218 , sizeof( struct V_221 ) ) )
goto V_105;
V_34 = F_246 ( V_7 , V_221 ) ;
if ( V_34 )
goto V_105;
V_34 = 0 ;
break;
}
case V_235 : {
struct V_236 V_237 ;
V_34 = F_247 ( V_7 , & V_237 ) ;
if ( V_34 )
goto V_105;
V_34 = - V_134 ;
if ( F_124 ( V_218 , & V_237 , sizeof V_237 ) )
goto V_105;
V_34 = 0 ;
break;
}
case V_238 : {
struct V_236 V_237 ;
V_34 = - V_134 ;
if ( F_242 ( & V_237 , V_218 , sizeof V_237 ) )
goto V_105;
V_34 = F_248 ( V_7 , & V_237 ) ;
if ( V_34 )
goto V_105;
V_34 = 0 ;
break;
}
case V_239 : {
struct V_240 V_241 ;
V_34 = - V_134 ;
if ( F_242 ( & V_241 , V_218 , sizeof V_241 ) )
goto V_105;
V_34 = F_249 ( V_7 , & V_241 ) ;
if ( V_34 )
goto V_105;
V_34 = - V_134 ;
if ( F_124 ( V_218 , & V_241 , sizeof V_241 ) )
goto V_105;
V_34 = 0 ;
break;
}
case V_242 : {
struct V_243 V_244 ;
V_34 = - V_134 ;
if ( F_242 ( & V_244 , V_218 , sizeof V_244 ) )
goto V_105;
V_34 = F_250 ( V_7 , & V_244 ) ;
if ( V_34 )
goto V_105;
V_34 = 0 ;
break;
}
case V_245 : {
struct V_246 V_109 * V_247 = V_218 ;
struct V_246 V_248 ;
T_7 V_212 , * V_249 ;
V_249 = NULL ;
if ( V_218 ) {
V_34 = - V_134 ;
if ( F_242 ( & V_248 , V_218 ,
sizeof V_248 ) )
goto V_105;
V_34 = - V_103 ;
if ( V_248 . V_171 != sizeof V_212 )
goto V_105;
V_34 = - V_134 ;
if ( F_242 ( & V_212 , V_247 -> V_212 ,
sizeof V_212 ) )
goto V_105;
V_249 = & V_212 ;
}
V_34 = F_234 ( V_7 , V_249 ) ;
break;
}
case V_250 : {
V_220 = F_77 ( sizeof( struct V_219 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_220 )
goto V_105;
V_34 = F_251 ( V_7 , V_220 ) ;
if ( V_34 )
goto V_105;
V_34 = - V_134 ;
if ( F_124 ( V_218 , V_220 , sizeof( struct V_219 ) ) )
goto V_105;
V_34 = 0 ;
break;
}
case V_251 : {
V_220 = F_245 ( sizeof( struct V_219 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_220 )
goto V_105;
V_34 = - V_134 ;
if ( F_242 ( V_220 , V_218 , sizeof( struct V_219 ) ) )
goto V_105;
V_34 = F_252 ( V_7 , V_220 ) ;
if ( V_34 )
goto V_105;
V_34 = 0 ;
break;
}
default:
V_34 = F_238 ( V_93 , V_216 , V_217 ) ;
}
V_105:
F_19 ( V_7 ) ;
F_88 ( V_220 ) ;
F_88 ( V_221 ) ;
return V_34 ;
}
static long F_253 ( struct V_92 * V_93 ,
unsigned int V_216 , unsigned long V_217 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
void V_109 * V_218 = F_254 ( V_217 ) ;
int V_34 ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_222 ;
switch ( V_216 ) {
case V_245 : {
struct V_246 V_109 * V_247 = V_218 ;
struct V_246 V_248 ;
T_8 V_252 ;
T_7 V_212 ;
if ( V_218 ) {
V_34 = - V_134 ;
if ( F_242 ( & V_248 , V_218 ,
sizeof V_248 ) )
goto V_105;
V_34 = - V_103 ;
if ( V_248 . V_171 != sizeof V_252 )
goto V_105;
V_34 = - V_134 ;
if ( F_242 ( & V_252 , V_247 -> V_212 ,
sizeof V_252 ) )
goto V_105;
}
F_255 ( & V_212 , & V_252 ) ;
V_34 = F_234 ( V_7 , & V_212 ) ;
break;
}
default:
V_34 = F_237 ( V_93 , V_216 , V_217 ) ;
}
V_105:
return V_34 ;
}
static long F_256 ( struct V_92 * V_93 ,
unsigned int V_216 , unsigned long V_217 )
{
struct V_18 * V_18 = V_93 -> V_94 ;
void V_109 * V_218 = ( void V_109 * ) V_217 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_222 ;
switch ( V_216 ) {
case V_253 :
V_34 = F_224 ( V_18 , V_217 ) ;
if ( V_34 < 0 )
goto V_105;
break;
case V_254 : {
struct V_96 V_255 ;
V_34 = - V_134 ;
if ( F_242 ( & V_255 , V_218 ,
sizeof V_255 ) )
goto V_105;
V_34 = F_122 ( V_18 , & V_255 , 1 ) ;
if ( V_34 )
goto V_105;
break;
}
case V_256 : {
struct V_129 log ;
V_34 = - V_134 ;
if ( F_242 ( & log , V_218 , sizeof log ) )
goto V_105;
V_34 = F_257 ( V_18 , & log ) ;
if ( V_34 )
goto V_105;
break;
}
#ifdef F_219
case V_257 : {
struct V_258 V_259 ;
V_34 = - V_134 ;
if ( F_242 ( & V_259 , V_218 , sizeof V_259 ) )
goto V_105;
V_34 = F_258 ( V_18 , & V_259 ) ;
if ( V_34 )
goto V_105;
V_34 = 0 ;
break;
}
case V_260 : {
struct V_258 V_259 ;
V_34 = - V_134 ;
if ( F_242 ( & V_259 , V_218 , sizeof V_259 ) )
goto V_105;
V_34 = F_259 ( V_18 , & V_259 ) ;
if ( V_34 )
goto V_105;
V_34 = 0 ;
break;
}
#endif
case V_261 : {
struct V_262 V_173 ;
V_34 = - V_134 ;
if ( F_242 ( & V_173 , V_218 , sizeof V_173 ) )
goto V_105;
V_34 = V_262 ( V_18 , V_173 . V_263 , V_173 . V_264 , V_173 . V_115 ) ;
break;
}
case V_265 : {
struct V_266 V_173 ;
V_34 = - V_134 ;
if ( F_242 ( & V_173 , V_218 , sizeof V_173 ) )
goto V_105;
V_34 = V_266 ( V_18 , & V_173 ) ;
break;
}
#ifdef F_232
case V_267 :
V_34 = 0 ;
F_9 ( & V_18 -> V_72 ) ;
if ( F_230 ( & V_18 -> V_206 ) != 0 )
V_34 = - V_268 ;
else
V_18 -> V_210 = V_217 ;
F_24 ( & V_18 -> V_72 ) ;
break;
#endif
default:
V_34 = F_260 ( V_93 , V_216 , V_217 ) ;
if ( V_34 == - V_269 )
V_34 = F_261 ( V_18 , V_216 , V_217 ) ;
}
V_105:
return V_34 ;
}
static long F_262 ( struct V_92 * V_93 ,
unsigned int V_216 , unsigned long V_217 )
{
struct V_18 * V_18 = V_93 -> V_94 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_222 ;
switch ( V_216 ) {
case V_256 : {
struct V_270 V_271 ;
struct V_129 log ;
V_34 = - V_134 ;
if ( F_242 ( & V_271 , ( void V_109 * ) V_217 ,
sizeof( V_271 ) ) )
goto V_105;
log . V_110 = V_271 . V_110 ;
log . V_272 = V_271 . V_272 ;
log . V_273 = V_271 . V_273 ;
log . V_80 = F_254 ( V_271 . V_80 ) ;
V_34 = F_257 ( V_18 , & log ) ;
if ( V_34 )
goto V_105;
break;
}
default:
V_34 = F_256 ( V_93 , V_216 , V_217 ) ;
}
V_105:
return V_34 ;
}
static int F_263 ( struct V_144 * V_145 , struct V_190 * V_191 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_142 ;
int V_86 ;
T_4 V_143 = V_191 -> V_193 ;
struct V_18 * V_18 = V_145 -> V_192 -> V_94 ;
V_142 = F_138 ( V_18 , V_143 ) ;
if ( F_133 ( V_142 ) )
return V_198 ;
V_86 = F_264 ( V_11 , V_11 -> V_46 , V_142 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_86 != 1 ) )
return V_198 ;
V_191 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_265 ( struct V_92 * V_92 , struct V_144 * V_145 )
{
V_145 -> V_199 = & V_274 ;
return 0 ;
}
static int F_266 ( void )
{
int V_34 ;
struct V_18 * V_18 ;
V_18 = F_70 () ;
if ( F_226 ( V_18 ) )
return F_227 ( V_18 ) ;
#ifdef F_219
V_34 = F_267 ( V_18 ) ;
if ( V_34 < 0 ) {
F_106 ( V_18 ) ;
return V_34 ;
}
#endif
V_34 = F_223 ( L_2 , & V_275 , V_18 , V_202 ) ;
if ( V_34 < 0 )
F_106 ( V_18 ) ;
return V_34 ;
}
static long F_268 ( long V_217 )
{
switch ( V_217 ) {
case V_276 :
case V_277 :
case V_278 :
#ifdef F_232
case V_279 :
#endif
case V_280 :
return 1 ;
#ifdef F_75
case V_281 :
return V_282 ;
#endif
default:
break;
}
return F_269 ( V_217 ) ;
}
static long F_270 ( struct V_92 * V_93 ,
unsigned int V_216 , unsigned long V_217 )
{
long V_34 = - V_103 ;
switch ( V_216 ) {
case V_283 :
V_34 = - V_103 ;
if ( V_217 )
goto V_105;
V_34 = V_284 ;
break;
case V_285 :
V_34 = - V_103 ;
if ( V_217 )
goto V_105;
V_34 = F_266 () ;
break;
case V_286 :
V_34 = F_268 ( V_217 ) ;
break;
case V_287 :
V_34 = - V_103 ;
if ( V_217 )
goto V_105;
V_34 = V_57 ;
#ifdef F_218
V_34 += V_57 ;
#endif
#ifdef F_219
V_34 += V_57 ;
#endif
break;
case V_288 :
case V_289 :
case V_290 :
V_34 = - V_291 ;
break;
default:
return F_271 ( V_93 , V_216 , V_217 ) ;
}
V_105:
return V_34 ;
}
static void F_272 ( void * V_292 )
{
int V_8 = F_273 () ;
int V_34 ;
if ( F_274 ( V_8 , V_293 ) )
return;
F_32 ( V_8 , V_293 ) ;
V_34 = F_275 ( NULL ) ;
if ( V_34 ) {
F_276 ( V_8 , V_293 ) ;
F_80 ( & V_294 ) ;
F_277 ( V_295 L_3
L_4 , V_8 ) ;
}
}
static void F_278 ( void * V_292 )
{
F_83 ( & V_76 ) ;
F_272 ( V_292 ) ;
F_85 ( & V_76 ) ;
}
static void F_279 ( void * V_292 )
{
int V_8 = F_273 () ;
if ( ! F_274 ( V_8 , V_293 ) )
return;
F_276 ( V_8 , V_293 ) ;
F_280 ( NULL ) ;
}
static void F_281 ( void * V_292 )
{
F_83 ( & V_76 ) ;
F_279 ( V_292 ) ;
F_85 ( & V_76 ) ;
}
static void F_282 ( void )
{
F_61 ( ! V_296 ) ;
V_296 -- ;
if ( ! V_296 )
F_283 ( F_279 , NULL , 1 ) ;
}
static void F_87 ( void )
{
F_83 ( & V_76 ) ;
F_282 () ;
F_85 ( & V_76 ) ;
}
static int F_74 ( void )
{
int V_34 = 0 ;
F_83 ( & V_76 ) ;
V_296 ++ ;
if ( V_296 == 1 ) {
F_82 ( & V_294 , 0 ) ;
F_283 ( F_272 , NULL , 1 ) ;
if ( F_230 ( & V_294 ) ) {
F_282 () ;
V_34 = - V_268 ;
}
}
F_85 ( & V_76 ) ;
return V_34 ;
}
static int F_284 ( struct V_297 * V_298 , unsigned long V_299 ,
void * V_203 )
{
int V_8 = ( long ) V_203 ;
if ( ! V_296 )
return V_300 ;
V_299 &= ~ V_301 ;
switch ( V_299 ) {
case V_302 :
F_277 ( V_295 L_5 ,
V_8 ) ;
F_281 ( NULL ) ;
break;
case V_303 :
F_277 ( V_295 L_6 ,
V_8 ) ;
F_278 ( NULL ) ;
break;
}
return V_300 ;
}
T_9 void F_285 ( void )
{
F_286 () ;
}
static int F_287 ( struct V_297 * V_298 , unsigned long V_299 ,
void * V_203 )
{
F_277 ( V_295 L_7 ) ;
V_304 = true ;
F_283 ( F_279 , NULL , 1 ) ;
return V_300 ;
}
static void F_99 ( struct V_69 * V_305 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_305 -> V_306 ; V_20 ++ ) {
struct V_307 * V_308 = V_305 -> V_309 [ V_20 ] . V_310 ;
F_288 ( V_308 ) ;
}
F_88 ( V_305 ) ;
}
int F_289 ( const void * V_311 , const void * V_312 )
{
const struct V_313 * V_314 = V_311 ;
const struct V_313 * V_315 = V_312 ;
if ( V_314 -> V_142 < V_315 -> V_142 )
return - 1 ;
if ( V_314 -> V_142 + V_314 -> V_171 > V_315 -> V_142 + V_315 -> V_171 )
return 1 ;
return 0 ;
}
int F_290 ( struct V_69 * V_305 , struct V_307 * V_310 ,
T_5 V_142 , int V_171 )
{
if ( V_305 -> V_306 == V_316 )
return - V_317 ;
V_305 -> V_309 [ V_305 -> V_306 ++ ] = (struct V_313 ) {
. V_142 = V_142 ,
. V_171 = V_171 ,
. V_310 = V_310 ,
} ;
F_291 ( V_305 -> V_309 , V_305 -> V_306 , sizeof( struct V_313 ) ,
F_289 , NULL ) ;
return 0 ;
}
int F_292 ( struct V_69 * V_305 ,
T_5 V_142 , int V_171 )
{
struct V_313 * V_309 , V_318 ;
int V_319 ;
V_318 = (struct V_313 ) {
. V_142 = V_142 ,
. V_171 = V_171 ,
} ;
V_309 = bsearch ( & V_318 , V_305 -> V_309 , V_305 -> V_306 ,
sizeof( struct V_313 ) , F_289 ) ;
if ( V_309 == NULL )
return - V_133 ;
V_319 = V_309 - V_305 -> V_309 ;
while ( V_319 > 0 && F_289 ( & V_318 , & V_305 -> V_309 [ V_319 - 1 ] ) == 0 )
V_319 -- ;
return V_319 ;
}
int F_293 ( struct V_18 * V_18 , enum V_320 V_321 , T_5 V_142 ,
int V_171 , const void * V_299 )
{
int V_49 ;
struct V_69 * V_305 ;
struct V_313 V_309 ;
V_309 = (struct V_313 ) {
. V_142 = V_142 ,
. V_171 = V_171 ,
} ;
V_305 = F_294 ( V_18 -> V_68 [ V_321 ] , & V_18 -> V_50 ) ;
V_49 = F_292 ( V_305 , V_142 , V_171 ) ;
if ( V_49 < 0 )
return - V_291 ;
while ( V_49 < V_305 -> V_306 &&
F_289 ( & V_309 , & V_305 -> V_309 [ V_49 ] ) == 0 ) {
if ( ! F_295 ( V_305 -> V_309 [ V_49 ] . V_310 , V_142 , V_171 , V_299 ) )
return 0 ;
V_49 ++ ;
}
return - V_291 ;
}
int F_296 ( struct V_18 * V_18 , enum V_320 V_321 , T_5 V_142 ,
int V_171 , void * V_299 )
{
int V_49 ;
struct V_69 * V_305 ;
struct V_313 V_309 ;
V_309 = (struct V_313 ) {
. V_142 = V_142 ,
. V_171 = V_171 ,
} ;
V_305 = F_294 ( V_18 -> V_68 [ V_321 ] , & V_18 -> V_50 ) ;
V_49 = F_292 ( V_305 , V_142 , V_171 ) ;
if ( V_49 < 0 )
return - V_291 ;
while ( V_49 < V_305 -> V_306 &&
F_289 ( & V_309 , & V_305 -> V_309 [ V_49 ] ) == 0 ) {
if ( ! F_297 ( V_305 -> V_309 [ V_49 ] . V_310 , V_142 , V_171 , V_299 ) )
return 0 ;
V_49 ++ ;
}
return - V_291 ;
}
int F_298 ( struct V_18 * V_18 , enum V_320 V_321 , T_5 V_142 ,
int V_171 , struct V_307 * V_310 )
{
struct V_69 * V_322 , * V_305 ;
V_305 = V_18 -> V_68 [ V_321 ] ;
if ( V_305 -> V_306 > V_316 - 1 )
return - V_317 ;
V_322 = F_77 ( sizeof( struct V_69 ) , V_37 ) ;
if ( ! V_322 )
return - V_39 ;
memcpy ( V_322 , V_305 , sizeof( struct V_69 ) ) ;
F_290 ( V_322 , V_310 , V_142 , V_171 ) ;
F_12 ( V_18 -> V_68 [ V_321 ] , V_322 ) ;
F_117 ( & V_18 -> V_50 ) ;
F_88 ( V_305 ) ;
return 0 ;
}
int F_299 ( struct V_18 * V_18 , enum V_320 V_321 ,
struct V_307 * V_310 )
{
int V_20 , V_34 ;
struct V_69 * V_322 , * V_305 ;
V_322 = F_77 ( sizeof( struct V_69 ) , V_37 ) ;
if ( ! V_322 )
return - V_39 ;
V_305 = V_18 -> V_68 [ V_321 ] ;
memcpy ( V_322 , V_305 , sizeof( struct V_69 ) ) ;
V_34 = - V_133 ;
for ( V_20 = 0 ; V_20 < V_322 -> V_306 ; V_20 ++ )
if ( V_322 -> V_309 [ V_20 ] . V_310 == V_310 ) {
V_34 = 0 ;
V_322 -> V_306 -- ;
V_322 -> V_309 [ V_20 ] = V_322 -> V_309 [ V_322 -> V_306 ] ;
F_291 ( V_322 -> V_309 , V_322 -> V_306 ,
sizeof( struct V_313 ) ,
F_289 , NULL ) ;
break;
}
if ( V_34 ) {
F_88 ( V_322 ) ;
return V_34 ;
}
F_12 ( V_18 -> V_68 [ V_321 ] , V_322 ) ;
F_117 ( & V_18 -> V_50 ) ;
F_88 ( V_305 ) ;
return V_34 ;
}
static int F_300 ( void * V_323 , T_10 * V_299 )
{
unsigned V_172 = ( long ) V_323 ;
struct V_18 * V_18 ;
* V_299 = 0 ;
F_83 ( & V_76 ) ;
F_301 ( V_18 , & V_77 , V_77 )
* V_299 += * ( T_6 * ) ( ( void * ) V_18 + V_172 ) ;
F_85 ( & V_76 ) ;
return 0 ;
}
static int F_302 ( void * V_323 , T_10 * V_299 )
{
unsigned V_172 = ( long ) V_323 ;
struct V_18 * V_18 ;
struct V_6 * V_7 ;
int V_20 ;
* V_299 = 0 ;
F_83 ( & V_76 ) ;
F_301 (kvm, &vm_list, vm_list)
F_28 ( V_20 , V_7 , V_18 )
* V_299 += * ( T_6 * ) ( ( void * ) V_7 + V_172 ) ;
F_85 ( & V_76 ) ;
return 0 ;
}
static void F_303 ( void )
{
struct V_324 * V_249 ;
V_325 = F_304 ( L_8 , NULL ) ;
for ( V_249 = V_326 ; V_249 -> V_327 ; ++ V_249 )
V_249 -> V_328 = F_305 ( V_249 -> V_327 , 0444 , V_325 ,
( void * ) ( long ) V_249 -> V_172 ,
V_329 [ V_249 -> V_330 ] ) ;
}
static void F_306 ( void )
{
struct V_324 * V_249 ;
for ( V_249 = V_326 ; V_249 -> V_327 ; ++ V_249 )
F_307 ( V_249 -> V_328 ) ;
F_307 ( V_325 ) ;
}
static int F_308 ( void )
{
if ( V_296 )
F_279 ( NULL ) ;
return 0 ;
}
static void F_309 ( void )
{
if ( V_296 ) {
F_166 ( F_310 ( & V_76 ) ) ;
F_272 ( NULL ) ;
}
}
static inline
struct V_6 * F_311 ( struct V_16 * V_331 )
{
return F_50 ( V_331 , struct V_6 , V_16 ) ;
}
static void F_312 ( struct V_16 * V_331 , int V_8 )
{
struct V_6 * V_7 = F_311 ( V_331 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_313 ( struct V_16 * V_331 ,
struct V_149 * V_332 )
{
struct V_6 * V_7 = F_311 ( V_331 ) ;
F_21 ( V_7 ) ;
}
int F_314 ( void * V_333 , unsigned V_334 , unsigned V_335 ,
struct V_336 * V_336 )
{
int V_34 ;
int V_8 ;
V_34 = F_315 ( V_333 ) ;
if ( V_34 )
goto V_337;
V_135 = F_43 ( V_37 | V_38 ) ;
if ( V_135 == NULL ) {
V_34 = - V_39 ;
goto V_105;
}
V_138 = F_155 ( V_135 ) ;
V_136 = F_43 ( V_37 | V_38 ) ;
if ( V_136 == NULL ) {
V_34 = - V_39 ;
goto V_338;
}
V_139 = F_155 ( V_136 ) ;
V_137 = F_43 ( V_37 | V_38 ) ;
if ( V_137 == NULL ) {
V_34 = - V_39 ;
goto V_338;
}
V_140 = F_155 ( V_137 ) ;
if ( ! F_27 ( & V_293 , V_37 ) ) {
V_34 = - V_39 ;
goto V_338;
}
V_34 = F_316 () ;
if ( V_34 < 0 )
goto V_339;
F_317 (cpu) {
F_318 ( V_8 ,
V_340 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_341;
}
V_34 = F_319 ( & V_342 ) ;
if ( V_34 )
goto V_343;
F_320 ( & V_344 ) ;
if ( ! V_335 )
V_335 = F_321 ( struct V_6 ) ;
V_345 = F_322 ( L_9 , V_334 , V_335 ,
0 , NULL ) ;
if ( ! V_345 ) {
V_34 = - V_39 ;
goto V_346;
}
V_34 = F_323 () ;
if ( V_34 )
goto V_117;
V_347 . V_348 = V_336 ;
V_275 . V_348 = V_336 ;
V_201 . V_348 = V_336 ;
V_34 = F_324 ( & V_349 ) ;
if ( V_34 ) {
F_277 ( V_350 L_10 ) ;
goto V_351;
}
F_325 ( & V_352 ) ;
V_204 . V_353 = F_312 ;
V_204 . V_354 = F_313 ;
F_303 () ;
return 0 ;
V_351:
F_326 () ;
V_117:
F_327 ( V_345 ) ;
V_346:
F_328 ( & V_344 ) ;
F_329 ( & V_342 ) ;
V_343:
V_341:
F_330 () ;
V_339:
F_35 ( V_293 ) ;
V_338:
if ( V_137 )
F_331 ( V_137 ) ;
if ( V_136 )
F_331 ( V_136 ) ;
F_331 ( V_135 ) ;
V_105:
F_332 () ;
V_337:
return V_34 ;
}
void F_333 ( void )
{
F_306 () ;
F_334 ( & V_349 ) ;
F_327 ( V_345 ) ;
F_326 () ;
F_335 ( & V_352 ) ;
F_328 ( & V_344 ) ;
F_329 ( & V_342 ) ;
F_283 ( F_279 , NULL , 1 ) ;
F_330 () ;
F_332 () ;
F_35 ( V_293 ) ;
F_331 ( V_136 ) ;
F_331 ( V_135 ) ;
}
