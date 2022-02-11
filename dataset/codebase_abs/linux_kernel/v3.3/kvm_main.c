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
static void F_70 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_61 * V_62 = V_18 -> V_63 ;
for ( V_20 = 0 ; V_20 < V_64 ; V_20 ++ )
V_62 -> V_65 [ V_20 ] = V_62 -> V_63 [ V_20 ] . V_33 = V_20 ;
}
static struct V_18 * F_71 ( void )
{
int V_34 , V_20 ;
struct V_18 * V_18 = F_72 () ;
if ( ! V_18 )
return F_73 ( - V_39 ) ;
V_34 = F_74 ( V_18 ) ;
if ( V_34 )
goto V_66;
V_34 = F_75 () ;
if ( V_34 )
goto V_66;
#ifdef F_76
F_77 ( & V_18 -> V_67 ) ;
F_77 ( & V_18 -> V_68 ) ;
#endif
V_34 = - V_39 ;
V_18 -> V_63 = F_78 ( sizeof( struct V_61 ) , V_37 ) ;
if ( ! V_18 -> V_63 )
goto V_69;
F_70 ( V_18 ) ;
if ( F_79 ( & V_18 -> V_50 ) )
goto V_69;
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ ) {
V_18 -> V_71 [ V_20 ] = F_78 ( sizeof( struct V_72 ) ,
V_37 ) ;
if ( ! V_18 -> V_71 [ V_20 ] )
goto V_73;
}
F_80 ( & V_18 -> V_51 ) ;
V_18 -> V_46 = V_11 -> V_46 ;
F_81 ( & V_18 -> V_46 -> V_74 ) ;
F_82 ( V_18 ) ;
F_40 ( & V_18 -> V_75 ) ;
F_40 ( & V_18 -> V_76 ) ;
F_40 ( & V_18 -> V_77 ) ;
F_83 ( & V_18 -> V_78 , 1 ) ;
V_34 = F_68 ( V_18 ) ;
if ( V_34 )
goto V_73;
F_84 ( & V_79 ) ;
F_85 ( & V_18 -> V_80 , & V_80 ) ;
F_86 ( & V_79 ) ;
return V_18 ;
V_73:
F_87 ( & V_18 -> V_50 ) ;
V_69:
F_88 () ;
V_66:
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ )
F_89 ( V_18 -> V_71 [ V_20 ] ) ;
F_89 ( V_18 -> V_63 ) ;
F_90 ( V_18 ) ;
return F_73 ( V_34 ) ;
}
static void F_91 ( struct V_81 * V_82 )
{
if ( ! V_82 -> V_83 )
return;
if ( 2 * F_92 ( V_82 ) > V_57 )
F_93 ( V_82 -> V_84 ) ;
else
F_89 ( V_82 -> V_84 ) ;
V_82 -> V_83 = NULL ;
V_82 -> V_84 = NULL ;
}
static void F_94 ( struct V_81 * free ,
struct V_81 * V_85 )
{
int V_20 ;
if ( ! V_85 || free -> V_86 != V_85 -> V_86 )
F_93 ( free -> V_86 ) ;
if ( ! V_85 || free -> V_83 != V_85 -> V_83 )
F_91 ( free ) ;
for ( V_20 = 0 ; V_20 < V_87 - 1 ; ++ V_20 ) {
if ( ! V_85 || free -> V_88 [ V_20 ] != V_85 -> V_88 [ V_20 ] ) {
F_93 ( free -> V_88 [ V_20 ] ) ;
free -> V_88 [ V_20 ] = NULL ;
}
}
free -> V_89 = 0 ;
free -> V_86 = NULL ;
}
void F_95 ( struct V_18 * V_18 )
{
struct V_61 * V_62 = V_18 -> V_63 ;
struct V_81 * V_82 ;
F_96 (memslot, slots)
F_94 ( V_82 , NULL ) ;
F_89 ( V_18 -> V_63 ) ;
}
static void F_97 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_45 * V_46 = V_18 -> V_46 ;
F_98 ( V_18 ) ;
F_84 ( & V_79 ) ;
F_99 ( & V_18 -> V_80 ) ;
F_86 ( & V_79 ) ;
F_100 ( V_18 ) ;
for ( V_20 = 0 ; V_20 < V_70 ; V_20 ++ )
F_101 ( V_18 -> V_71 [ V_20 ] ) ;
F_102 ( V_18 ) ;
#if F_103 ( V_90 ) && F_103 ( V_91 )
F_104 ( & V_18 -> V_43 , V_18 -> V_46 ) ;
#else
F_67 ( V_18 ) ;
#endif
F_105 ( V_18 ) ;
F_95 ( V_18 ) ;
F_87 ( & V_18 -> V_50 ) ;
F_90 ( V_18 ) ;
F_88 () ;
F_106 ( V_46 ) ;
}
void F_107 ( struct V_18 * V_18 )
{
F_81 ( & V_18 -> V_78 ) ;
}
void F_108 ( struct V_18 * V_18 )
{
if ( F_109 ( & V_18 -> V_78 ) )
F_97 ( V_18 ) ;
}
static int F_110 ( struct V_92 * V_92 , struct V_93 * V_94 )
{
struct V_18 * V_18 = V_94 -> V_95 ;
F_111 ( V_18 ) ;
F_108 ( V_18 ) ;
return 0 ;
}
static int F_112 ( struct V_81 * V_82 )
{
unsigned long V_96 = 2 * F_92 ( V_82 ) ;
if ( V_96 > V_57 )
V_82 -> V_83 = F_113 ( V_96 ) ;
else
V_82 -> V_83 = F_78 ( V_96 , V_37 ) ;
if ( ! V_82 -> V_83 )
return - V_39 ;
V_82 -> V_84 = V_82 -> V_83 ;
V_82 -> V_97 = 0 ;
return 0 ;
}
static struct V_81 *
F_114 ( struct V_61 * V_62 , T_4 V_98 )
{
struct V_81 * V_82 ;
F_96 (memslot, slots)
if ( V_98 >= V_82 -> V_99 &&
V_98 < V_82 -> V_99 + V_82 -> V_89 )
return V_82 ;
return NULL ;
}
static int F_115 ( const void * V_100 , const void * V_101 )
{
struct V_81 * V_102 , * V_103 ;
V_102 = (struct V_81 * ) V_100 ;
V_103 = (struct V_81 * ) V_101 ;
if ( V_102 -> V_89 < V_103 -> V_89 )
return 1 ;
if ( V_102 -> V_89 > V_103 -> V_89 )
return - 1 ;
return 0 ;
}
static void F_116 ( struct V_61 * V_62 )
{
int V_20 ;
F_117 ( V_62 -> V_63 , V_64 ,
sizeof( struct V_81 ) , F_115 , NULL ) ;
for ( V_20 = 0 ; V_20 < V_64 ; V_20 ++ )
V_62 -> V_65 [ V_62 -> V_63 [ V_20 ] . V_33 ] = V_20 ;
}
void F_118 ( struct V_61 * V_62 , struct V_81 * V_104 )
{
if ( V_104 ) {
int V_33 = V_104 -> V_33 ;
struct V_81 * V_105 = F_119 ( V_62 , V_33 ) ;
unsigned long V_89 = V_105 -> V_89 ;
* V_105 = * V_104 ;
if ( V_104 -> V_89 != V_89 )
F_116 ( V_62 ) ;
}
V_62 -> V_106 ++ ;
}
int F_120 ( struct V_18 * V_18 ,
struct V_107 * V_108 ,
int V_109 )
{
int V_34 ;
T_4 V_99 ;
unsigned long V_89 ;
unsigned long V_20 ;
struct V_81 * V_82 ;
struct V_81 V_105 , V_104 ;
struct V_61 * V_62 , * V_110 ;
V_34 = - V_111 ;
if ( V_108 -> V_112 & ( V_57 - 1 ) )
goto V_113;
if ( V_108 -> V_114 & ( V_57 - 1 ) )
goto V_113;
if ( V_109 &&
( ( V_108 -> V_115 & ( V_57 - 1 ) ) ||
! F_121 ( V_116 ,
( void V_117 * ) ( unsigned long ) V_108 -> V_115 ,
V_108 -> V_112 ) ) )
goto V_113;
if ( V_108 -> V_118 >= V_64 )
goto V_113;
if ( V_108 -> V_114 + V_108 -> V_112 < V_108 -> V_114 )
goto V_113;
V_82 = F_119 ( V_18 -> V_63 , V_108 -> V_118 ) ;
V_99 = V_108 -> V_114 >> V_119 ;
V_89 = V_108 -> V_112 >> V_119 ;
V_34 = - V_111 ;
if ( V_89 > V_120 )
goto V_113;
if ( ! V_89 )
V_108 -> V_121 &= ~ V_122 ;
V_104 = V_105 = * V_82 ;
V_104 . V_33 = V_108 -> V_118 ;
V_104 . V_99 = V_99 ;
V_104 . V_89 = V_89 ;
V_104 . V_121 = V_108 -> V_121 ;
V_34 = - V_111 ;
if ( V_89 && V_105 . V_89 && V_89 != V_105 . V_89 )
goto V_123;
V_34 = - V_124 ;
for ( V_20 = 0 ; V_20 < V_125 ; ++ V_20 ) {
struct V_81 * V_126 = & V_18 -> V_63 -> V_63 [ V_20 ] ;
if ( V_126 == V_82 || ! V_126 -> V_89 )
continue;
if ( ! ( ( V_99 + V_89 <= V_126 -> V_99 ) ||
( V_99 >= V_126 -> V_99 + V_126 -> V_89 ) ) )
goto V_123;
}
if ( ! ( V_104 . V_121 & V_122 ) )
V_104 . V_83 = NULL ;
V_34 = - V_39 ;
#ifndef F_122
if ( V_89 && ! V_104 . V_86 ) {
V_104 . V_86 = F_113 ( V_89 * sizeof( * V_104 . V_86 ) ) ;
if ( ! V_104 . V_86 )
goto V_123;
V_104 . V_109 = V_109 ;
V_104 . V_115 = V_108 -> V_115 ;
}
if ( ! V_89 )
goto V_127;
for ( V_20 = 0 ; V_20 < V_87 - 1 ; ++ V_20 ) {
unsigned long V_128 ;
unsigned long V_129 ;
int V_130 ;
int V_131 = V_20 + 2 ;
( void ) V_131 ;
if ( V_104 . V_88 [ V_20 ] )
continue;
V_130 = 1 + ( ( V_99 + V_89 - 1 )
>> F_123 ( V_131 ) ) ;
V_130 -= V_99 >> F_123 ( V_131 ) ;
V_104 . V_88 [ V_20 ] = F_113 ( V_130 * sizeof( * V_104 . V_88 [ V_20 ] ) ) ;
if ( ! V_104 . V_88 [ V_20 ] )
goto V_123;
if ( V_99 & ( F_124 ( V_131 ) - 1 ) )
V_104 . V_88 [ V_20 ] [ 0 ] . V_132 = 1 ;
if ( ( V_99 + V_89 ) & ( F_124 ( V_131 ) - 1 ) )
V_104 . V_88 [ V_20 ] [ V_130 - 1 ] . V_132 = 1 ;
V_128 = V_104 . V_115 >> V_119 ;
if ( ( V_99 ^ V_128 ) & ( F_124 ( V_131 ) - 1 ) ||
! V_133 )
for ( V_129 = 0 ; V_129 < V_130 ; ++ V_129 )
V_104 . V_88 [ V_20 ] [ V_129 ] . V_132 = 1 ;
}
V_127:
if ( ( V_104 . V_121 & V_122 ) && ! V_104 . V_83 ) {
if ( F_112 ( & V_104 ) < 0 )
goto V_123;
}
#else
V_104 . V_109 = V_109 ;
if ( V_109 )
V_104 . V_115 = V_108 -> V_115 ;
#endif
if ( ! V_89 ) {
struct V_81 * V_118 ;
V_34 = - V_39 ;
V_62 = F_125 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_123;
V_118 = F_119 ( V_62 , V_108 -> V_118 ) ;
V_118 -> V_121 |= V_134 ;
F_118 ( V_62 , NULL ) ;
V_110 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_67 ( V_18 ) ;
F_89 ( V_110 ) ;
}
V_34 = F_127 ( V_18 , & V_104 , V_105 , V_108 , V_109 ) ;
if ( V_34 )
goto V_123;
if ( V_89 ) {
V_34 = F_128 ( V_18 , & V_104 ) ;
if ( V_34 )
goto V_123;
}
V_34 = - V_39 ;
V_62 = F_125 ( V_18 -> V_63 , sizeof( struct V_61 ) ,
V_37 ) ;
if ( ! V_62 )
goto V_123;
if ( ! V_89 ) {
V_104 . V_86 = NULL ;
V_104 . V_83 = NULL ;
for ( V_20 = 0 ; V_20 < V_87 - 1 ; ++ V_20 )
V_104 . V_88 [ V_20 ] = NULL ;
}
F_118 ( V_62 , & V_104 ) ;
V_110 = V_18 -> V_63 ;
F_12 ( V_18 -> V_63 , V_62 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_129 ( V_18 , V_108 , V_105 , V_109 ) ;
if ( V_89 && V_105 . V_99 != V_108 -> V_114 >> V_119 )
F_67 ( V_18 ) ;
F_94 ( & V_105 , & V_104 ) ;
F_89 ( V_110 ) ;
return 0 ;
V_123:
F_94 ( & V_104 , & V_105 ) ;
V_113:
return V_34 ;
}
int F_130 ( struct V_18 * V_18 ,
struct V_107 * V_108 ,
int V_109 )
{
int V_34 ;
F_9 ( & V_18 -> V_77 ) ;
V_34 = F_120 ( V_18 , V_108 , V_109 ) ;
F_24 ( & V_18 -> V_77 ) ;
return V_34 ;
}
int F_131 ( struct V_18 * V_18 ,
struct
V_107 * V_108 ,
int V_109 )
{
if ( V_108 -> V_118 >= V_125 )
return - V_111 ;
return F_130 ( V_18 , V_108 , V_109 ) ;
}
int F_132 ( struct V_18 * V_18 ,
struct V_135 * log , int * V_136 )
{
struct V_81 * V_82 ;
int V_34 , V_20 ;
unsigned long V_137 ;
unsigned long V_138 = 0 ;
V_34 = - V_111 ;
if ( log -> V_118 >= V_125 )
goto V_113;
V_82 = F_119 ( V_18 -> V_63 , log -> V_118 ) ;
V_34 = - V_139 ;
if ( ! V_82 -> V_83 )
goto V_113;
V_137 = F_92 ( V_82 ) ;
for ( V_20 = 0 ; ! V_138 && V_20 < V_137 / sizeof( long ) ; ++ V_20 )
V_138 = V_82 -> V_83 [ V_20 ] ;
V_34 = - V_140 ;
if ( F_133 ( log -> V_83 , V_82 -> V_83 , V_137 ) )
goto V_113;
if ( V_138 )
* V_136 = 1 ;
V_34 = 0 ;
V_113:
return V_34 ;
}
void F_134 ( void )
{
V_133 = false ;
}
int F_135 ( struct V_3 * V_3 )
{
return V_3 == V_141 || V_3 == V_142 || V_3 == V_143 ;
}
int F_136 ( T_1 V_1 )
{
return V_1 == V_144 || V_1 == V_145 || V_1 == V_146 ;
}
int F_137 ( T_1 V_1 )
{
return V_1 == V_145 ;
}
int F_138 ( T_1 V_1 )
{
return V_1 == V_146 ;
}
int F_139 ( T_1 V_1 )
{
return V_1 == V_144 ;
}
int F_140 ( T_1 V_1 )
{
return V_1 == V_145 || V_1 == V_146 ;
}
static inline unsigned long F_141 ( void )
{
return V_147 ;
}
int F_142 ( unsigned long V_148 )
{
return V_148 == F_141 () ;
}
static struct V_81 * F_143 ( struct V_61 * V_62 ,
T_4 V_98 )
{
return F_114 ( V_62 , V_98 ) ;
}
struct V_81 * F_144 ( struct V_18 * V_18 , T_4 V_98 )
{
return F_143 ( V_61 ( V_18 ) , V_98 ) ;
}
int F_145 ( struct V_18 * V_18 , T_4 V_98 )
{
struct V_81 * V_82 = F_144 ( V_18 , V_98 ) ;
if ( ! V_82 || V_82 -> V_33 >= V_125 ||
V_82 -> V_121 & V_134 )
return 0 ;
return 1 ;
}
unsigned long F_146 ( struct V_18 * V_18 , T_4 V_98 )
{
struct V_149 * V_150 ;
unsigned long V_148 , V_151 ;
V_151 = V_57 ;
V_148 = F_147 ( V_18 , V_98 ) ;
if ( F_142 ( V_148 ) )
return V_57 ;
F_148 ( & V_11 -> V_46 -> V_152 ) ;
V_150 = F_149 ( V_11 -> V_46 , V_148 ) ;
if ( ! V_150 )
goto V_113;
V_151 = F_150 ( V_150 ) ;
V_113:
F_151 ( & V_11 -> V_46 -> V_152 ) ;
return V_151 ;
}
static unsigned long F_152 ( struct V_81 * V_118 , T_4 V_98 ,
T_4 * V_153 )
{
if ( ! V_118 || V_118 -> V_121 & V_134 )
return F_141 () ;
if ( V_153 )
* V_153 = V_118 -> V_89 - ( V_98 - V_118 -> V_99 ) ;
return F_153 ( V_118 , V_98 ) ;
}
unsigned long F_147 ( struct V_18 * V_18 , T_4 V_98 )
{
return F_152 ( F_144 ( V_18 , V_98 ) , V_98 , NULL ) ;
}
static T_1 F_154 ( void )
{
F_155 ( V_143 ) ;
return V_146 ;
}
int F_156 ( struct V_154 * V_155 , struct V_45 * V_46 ,
unsigned long V_54 , int V_156 , struct V_3 * * V_3 )
{
int V_121 = V_157 | V_158 | V_159 | V_160 ;
if ( V_156 )
V_121 |= V_161 ;
return F_157 ( V_155 , V_46 , V_54 , 1 , V_121 , V_3 , NULL , NULL ) ;
}
static inline int F_158 ( unsigned long V_148 )
{
int V_162 , V_121 = V_157 | V_159 | V_161 ;
V_162 = F_157 ( V_11 , V_11 -> V_46 , V_148 , 1 ,
V_121 , NULL , NULL , NULL ) ;
return V_162 == - V_163 ;
}
static T_1 F_159 ( struct V_18 * V_18 , unsigned long V_148 , bool V_164 ,
bool * V_165 , bool V_166 , bool * V_167 )
{
struct V_3 * V_3 [ 1 ] ;
int V_89 = 0 ;
T_1 V_1 ;
F_61 ( V_164 && V_165 ) ;
F_61 ( ! V_166 && ! V_167 ) ;
if ( V_167 )
* V_167 = true ;
if ( V_164 || V_165 )
V_89 = F_160 ( V_148 , 1 , 1 , V_3 ) ;
if ( F_10 ( V_89 != 1 ) && ! V_164 ) {
F_161 () ;
if ( V_167 )
* V_167 = V_166 ;
if ( V_165 ) {
F_148 ( & V_11 -> V_46 -> V_152 ) ;
V_89 = F_156 ( V_11 , V_11 -> V_46 ,
V_148 , V_166 , V_3 ) ;
F_151 ( & V_11 -> V_46 -> V_152 ) ;
} else
V_89 = F_162 ( V_148 , 1 , V_166 ,
V_3 ) ;
if ( F_10 ( ! V_166 ) && V_89 == 1 ) {
struct V_3 * V_168 [ 1 ] ;
V_89 = F_160 ( V_148 , 1 , 1 , V_168 ) ;
if ( V_89 == 1 ) {
* V_167 = true ;
F_163 ( V_3 [ 0 ] ) ;
V_3 [ 0 ] = V_168 [ 0 ] ;
}
V_89 = 1 ;
}
}
if ( F_10 ( V_89 != 1 ) ) {
struct V_149 * V_150 ;
if ( V_164 )
return F_154 () ;
F_148 ( & V_11 -> V_46 -> V_152 ) ;
if ( V_89 == - V_163 ||
( ! V_165 && F_158 ( V_148 ) ) ) {
F_151 ( & V_11 -> V_46 -> V_152 ) ;
F_155 ( V_142 ) ;
return F_164 ( V_142 ) ;
}
V_150 = F_165 ( V_11 -> V_46 , V_148 , V_148 + 1 ) ;
if ( V_150 == NULL )
V_1 = F_154 () ;
else if ( ( V_150 -> V_169 & V_170 ) ) {
V_1 = ( ( V_148 - V_150 -> V_171 ) >> V_119 ) +
V_150 -> V_172 ;
F_61 ( ! F_1 ( V_1 ) ) ;
} else {
if ( V_165 && ( V_150 -> V_169 & V_173 ) )
* V_165 = true ;
V_1 = F_154 () ;
}
F_151 ( & V_11 -> V_46 -> V_152 ) ;
} else
V_1 = F_164 ( V_3 [ 0 ] ) ;
return V_1 ;
}
T_1 F_166 ( struct V_18 * V_18 , unsigned long V_148 )
{
return F_159 ( V_18 , V_148 , true , NULL , true , NULL ) ;
}
static T_1 F_167 ( struct V_18 * V_18 , T_4 V_98 , bool V_164 , bool * V_165 ,
bool V_166 , bool * V_167 )
{
unsigned long V_148 ;
if ( V_165 )
* V_165 = false ;
V_148 = F_147 ( V_18 , V_98 ) ;
if ( F_142 ( V_148 ) ) {
F_155 ( V_141 ) ;
return F_164 ( V_141 ) ;
}
return F_159 ( V_18 , V_148 , V_164 , V_165 , V_166 , V_167 ) ;
}
T_1 F_168 ( struct V_18 * V_18 , T_4 V_98 )
{
return F_167 ( V_18 , V_98 , true , NULL , true , NULL ) ;
}
T_1 F_169 ( struct V_18 * V_18 , T_4 V_98 , bool * V_165 ,
bool V_166 , bool * V_167 )
{
return F_167 ( V_18 , V_98 , false , V_165 , V_166 , V_167 ) ;
}
T_1 F_170 ( struct V_18 * V_18 , T_4 V_98 )
{
return F_167 ( V_18 , V_98 , false , NULL , true , NULL ) ;
}
T_1 F_171 ( struct V_18 * V_18 , T_4 V_98 , bool V_166 ,
bool * V_167 )
{
return F_167 ( V_18 , V_98 , false , NULL , V_166 , V_167 ) ;
}
T_1 F_172 ( struct V_18 * V_18 ,
struct V_81 * V_118 , T_4 V_98 )
{
unsigned long V_148 = F_153 ( V_118 , V_98 ) ;
return F_159 ( V_18 , V_148 , false , NULL , true , NULL ) ;
}
int F_173 ( struct V_18 * V_18 , T_4 V_98 , struct V_3 * * V_174 ,
int V_153 )
{
unsigned long V_148 ;
T_4 V_175 ;
V_148 = F_152 ( F_144 ( V_18 , V_98 ) , V_98 , & V_175 ) ;
if ( F_142 ( V_148 ) )
return - 1 ;
if ( V_175 < V_153 )
return 0 ;
return F_160 ( V_148 , V_153 , 1 , V_174 ) ;
}
struct V_3 * F_174 ( struct V_18 * V_18 , T_4 V_98 )
{
T_1 V_1 ;
V_1 = F_170 ( V_18 , V_98 ) ;
if ( ! F_1 ( V_1 ) )
return F_3 ( V_1 ) ;
F_175 ( F_1 ( V_1 ) ) ;
F_155 ( V_141 ) ;
return V_141 ;
}
void F_176 ( struct V_3 * V_3 )
{
F_177 ( F_164 ( V_3 ) ) ;
}
void F_177 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_163 ( F_3 ( V_1 ) ) ;
}
void F_178 ( struct V_3 * V_3 )
{
F_179 ( F_164 ( V_3 ) ) ;
}
void F_179 ( T_1 V_1 )
{
F_180 ( V_1 ) ;
F_177 ( V_1 ) ;
}
void F_181 ( struct V_3 * V_3 )
{
F_180 ( F_164 ( V_3 ) ) ;
}
void F_180 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) ) {
struct V_3 * V_3 = F_3 ( V_1 ) ;
if ( ! F_5 ( V_3 ) )
F_182 ( V_3 ) ;
}
}
void F_183 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_184 ( F_3 ( V_1 ) ) ;
}
void F_185 ( T_1 V_1 )
{
if ( ! F_1 ( V_1 ) )
F_155 ( F_3 ( V_1 ) ) ;
}
static int F_186 ( unsigned long V_176 , int V_177 )
{
if ( V_176 > V_57 - V_177 )
return V_57 - V_177 ;
else
return V_176 ;
}
int F_187 ( struct V_18 * V_18 , T_4 V_98 , void * V_178 , int V_177 ,
int V_176 )
{
int V_34 ;
unsigned long V_148 ;
V_148 = F_147 ( V_18 , V_98 ) ;
if ( F_142 ( V_148 ) )
return - V_140 ;
V_34 = F_188 ( V_178 , ( void V_117 * ) V_148 + V_177 , V_176 ) ;
if ( V_34 )
return - V_140 ;
return 0 ;
}
int F_189 ( struct V_18 * V_18 , T_5 V_179 , void * V_178 , unsigned long V_176 )
{
T_4 V_98 = V_179 >> V_119 ;
int V_180 ;
int V_177 = F_190 ( V_179 ) ;
int V_181 ;
while ( ( V_180 = F_186 ( V_176 , V_177 ) ) != 0 ) {
V_181 = F_187 ( V_18 , V_98 , V_178 , V_177 , V_180 ) ;
if ( V_181 < 0 )
return V_181 ;
V_177 = 0 ;
V_176 -= V_180 ;
V_178 += V_180 ;
++ V_98 ;
}
return 0 ;
}
int F_191 ( struct V_18 * V_18 , T_5 V_179 , void * V_178 ,
unsigned long V_176 )
{
int V_34 ;
unsigned long V_148 ;
T_4 V_98 = V_179 >> V_119 ;
int V_177 = F_190 ( V_179 ) ;
V_148 = F_147 ( V_18 , V_98 ) ;
if ( F_142 ( V_148 ) )
return - V_140 ;
F_192 () ;
V_34 = F_193 ( V_178 , ( void V_117 * ) V_148 + V_177 , V_176 ) ;
F_194 () ;
if ( V_34 )
return - V_140 ;
return 0 ;
}
int F_195 ( struct V_18 * V_18 , T_4 V_98 , const void * V_178 ,
int V_177 , int V_176 )
{
int V_34 ;
unsigned long V_148 ;
V_148 = F_147 ( V_18 , V_98 ) ;
if ( F_142 ( V_148 ) )
return - V_140 ;
V_34 = F_196 ( ( void V_117 * ) V_148 + V_177 , V_178 , V_176 ) ;
if ( V_34 )
return - V_140 ;
F_197 ( V_18 , V_98 ) ;
return 0 ;
}
int F_198 ( struct V_18 * V_18 , T_5 V_179 , const void * V_178 ,
unsigned long V_176 )
{
T_4 V_98 = V_179 >> V_119 ;
int V_180 ;
int V_177 = F_190 ( V_179 ) ;
int V_181 ;
while ( ( V_180 = F_186 ( V_176 , V_177 ) ) != 0 ) {
V_181 = F_195 ( V_18 , V_98 , V_178 , V_177 , V_180 ) ;
if ( V_181 < 0 )
return V_181 ;
V_177 = 0 ;
V_176 -= V_180 ;
V_178 += V_180 ;
++ V_98 ;
}
return 0 ;
}
int F_199 ( struct V_18 * V_18 , struct V_182 * V_183 ,
T_5 V_179 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_177 = F_190 ( V_179 ) ;
T_4 V_98 = V_179 >> V_119 ;
V_183 -> V_179 = V_179 ;
V_183 -> V_106 = V_62 -> V_106 ;
V_183 -> V_82 = F_143 ( V_62 , V_98 ) ;
V_183 -> V_184 = F_152 ( V_183 -> V_82 , V_98 , NULL ) ;
if ( ! F_142 ( V_183 -> V_184 ) )
V_183 -> V_184 += V_177 ;
else
return - V_140 ;
return 0 ;
}
int F_200 ( struct V_18 * V_18 , struct V_182 * V_183 ,
void * V_178 , unsigned long V_176 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_106 != V_183 -> V_106 )
F_199 ( V_18 , V_183 , V_183 -> V_179 ) ;
if ( F_142 ( V_183 -> V_184 ) )
return - V_140 ;
V_34 = F_196 ( ( void V_117 * ) V_183 -> V_184 , V_178 , V_176 ) ;
if ( V_34 )
return - V_140 ;
F_201 ( V_18 , V_183 -> V_82 , V_183 -> V_179 >> V_119 ) ;
return 0 ;
}
int F_202 ( struct V_18 * V_18 , struct V_182 * V_183 ,
void * V_178 , unsigned long V_176 )
{
struct V_61 * V_62 = V_61 ( V_18 ) ;
int V_34 ;
if ( V_62 -> V_106 != V_183 -> V_106 )
F_199 ( V_18 , V_183 , V_183 -> V_179 ) ;
if ( F_142 ( V_183 -> V_184 ) )
return - V_140 ;
V_34 = F_188 ( V_178 , ( void V_117 * ) V_183 -> V_184 , V_176 ) ;
if ( V_34 )
return - V_140 ;
return 0 ;
}
int F_203 ( struct V_18 * V_18 , T_4 V_98 , int V_177 , int V_176 )
{
return F_195 ( V_18 , V_98 , ( const void * ) V_185 ,
V_177 , V_176 ) ;
}
int F_204 ( struct V_18 * V_18 , T_5 V_179 , unsigned long V_176 )
{
T_4 V_98 = V_179 >> V_119 ;
int V_180 ;
int V_177 = F_190 ( V_179 ) ;
int V_181 ;
while ( ( V_180 = F_186 ( V_176 , V_177 ) ) != 0 ) {
V_181 = F_203 ( V_18 , V_98 , V_177 , V_180 ) ;
if ( V_181 < 0 )
return V_181 ;
V_177 = 0 ;
V_176 -= V_180 ;
++ V_98 ;
}
return 0 ;
}
void F_201 ( struct V_18 * V_18 , struct V_81 * V_82 ,
T_4 V_98 )
{
if ( V_82 && V_82 -> V_83 ) {
unsigned long V_186 = V_98 - V_82 -> V_99 ;
if ( ! F_205 ( V_186 , V_82 -> V_83 ) )
V_82 -> V_97 ++ ;
}
}
void F_197 ( struct V_18 * V_18 , T_4 V_98 )
{
struct V_81 * V_82 ;
V_82 = F_144 ( V_18 , V_98 ) ;
F_201 ( V_18 , V_82 , V_98 ) ;
}
void F_206 ( struct V_6 * V_7 )
{
F_207 ( V_187 ) ;
for (; ; ) {
F_208 ( & V_7 -> V_36 , & V_187 , V_188 ) ;
if ( F_209 ( V_7 ) ) {
F_29 ( V_189 , V_7 ) ;
break;
}
if ( F_210 ( V_7 ) )
break;
if ( F_211 ( V_11 ) )
break;
F_212 () ;
}
F_213 ( & V_7 -> V_36 , & V_187 ) ;
}
void F_214 ( struct V_6 * V_7 )
{
if ( ! F_215 () )
return;
F_216 () ;
}
void F_217 ( struct V_6 * V_21 )
{
struct V_18 * V_18 = V_21 -> V_18 ;
struct V_6 * V_7 ;
int V_190 = V_21 -> V_18 -> V_190 ;
int V_191 = 0 ;
int V_192 ;
int V_20 ;
for ( V_192 = 0 ; V_192 < 2 && ! V_191 ; V_192 ++ ) {
F_28 (i, vcpu, kvm) {
struct V_154 * V_193 = NULL ;
struct V_10 * V_10 ;
if ( ! V_192 && V_20 < V_190 ) {
V_20 = V_190 ;
continue;
} else if ( V_192 && V_20 > V_190 )
break;
if ( V_7 == V_21 )
continue;
if ( F_218 ( & V_7 -> V_36 ) )
continue;
F_219 () ;
V_10 = F_220 ( V_7 -> V_10 ) ;
if ( V_10 )
V_193 = F_221 ( V_7 -> V_10 , V_13 ) ;
F_222 () ;
if ( ! V_193 )
continue;
if ( V_193 -> V_121 & V_194 ) {
F_223 ( V_193 ) ;
continue;
}
if ( F_224 ( V_193 , 1 ) ) {
F_223 ( V_193 ) ;
V_18 -> V_190 = V_20 ;
V_191 = 1 ;
break;
}
F_223 ( V_193 ) ;
}
}
}
static int F_225 ( struct V_149 * V_150 , struct V_195 * V_196 )
{
struct V_6 * V_7 = V_150 -> V_197 -> V_95 ;
struct V_3 * V_3 ;
if ( V_196 -> V_198 == 0 )
V_3 = F_226 ( V_7 -> V_41 ) ;
#ifdef F_227
else if ( V_196 -> V_198 == V_199 )
V_3 = F_226 ( V_7 -> V_200 . V_201 ) ;
#endif
#ifdef F_228
else if ( V_196 -> V_198 == F_228 )
V_3 = F_226 ( V_7 -> V_18 -> V_202 ) ;
#endif
else
return V_203 ;
F_155 ( V_3 ) ;
V_196 -> V_3 = V_3 ;
return 0 ;
}
static int F_229 ( struct V_93 * V_93 , struct V_149 * V_150 )
{
V_150 -> V_204 = & V_205 ;
return 0 ;
}
static int F_230 ( struct V_92 * V_92 , struct V_93 * V_94 )
{
struct V_6 * V_7 = V_94 -> V_95 ;
F_108 ( V_7 -> V_18 ) ;
return 0 ;
}
static int F_231 ( struct V_6 * V_7 )
{
return F_232 ( L_1 , & V_206 , V_7 , V_207 ) ;
}
static int F_233 ( struct V_18 * V_18 , T_6 V_33 )
{
int V_34 ;
struct V_6 * V_7 , * V_208 ;
V_7 = F_234 ( V_18 , V_33 ) ;
if ( F_235 ( V_7 ) )
return F_236 ( V_7 ) ;
F_237 ( & V_7 -> V_16 , & V_209 ) ;
V_34 = F_238 ( V_7 ) ;
if ( V_34 )
goto V_210;
F_9 ( & V_18 -> V_75 ) ;
if ( F_239 ( & V_18 -> V_211 ) == V_212 ) {
V_34 = - V_111 ;
goto V_213;
}
F_28 (r, v, kvm)
if ( V_208 -> V_35 == V_33 ) {
V_34 = - V_124 ;
goto V_213;
}
F_61 ( V_18 -> V_214 [ F_239 ( & V_18 -> V_211 ) ] ) ;
F_107 ( V_18 ) ;
V_34 = F_231 ( V_7 ) ;
if ( V_34 < 0 ) {
F_108 ( V_18 ) ;
goto V_213;
}
V_18 -> V_214 [ F_239 ( & V_18 -> V_211 ) ] = V_7 ;
F_240 () ;
F_81 ( & V_18 -> V_211 ) ;
F_24 ( & V_18 -> V_75 ) ;
return V_34 ;
V_213:
F_24 ( & V_18 -> V_75 ) ;
V_210:
F_241 ( V_7 ) ;
return V_34 ;
}
static int F_242 ( struct V_6 * V_7 , T_7 * V_215 )
{
if ( V_215 ) {
F_243 ( V_215 , F_244 ( V_216 ) | F_244 ( V_217 ) ) ;
V_7 -> V_218 = 1 ;
V_7 -> V_215 = * V_215 ;
} else
V_7 -> V_218 = 0 ;
return 0 ;
}
static long F_245 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_6 * V_7 = V_94 -> V_95 ;
void V_117 * V_221 = ( void V_117 * ) V_220 ;
int V_34 ;
struct V_222 * V_223 = NULL ;
struct V_224 * V_224 = NULL ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_225 ;
#if F_103 ( F_122 ) || F_103 ( V_226 )
if ( V_219 == V_227 || V_219 == V_228 )
return F_246 ( V_94 , V_219 , V_220 ) ;
#endif
F_8 ( V_7 ) ;
switch ( V_219 ) {
case V_229 :
V_34 = - V_111 ;
if ( V_220 )
goto V_113;
V_34 = F_247 ( V_7 , V_7 -> V_41 ) ;
F_248 ( V_7 -> V_41 -> V_230 , V_34 ) ;
break;
case V_231 : {
struct V_232 * V_232 ;
V_34 = - V_39 ;
V_232 = F_78 ( sizeof( struct V_232 ) , V_37 ) ;
if ( ! V_232 )
goto V_113;
V_34 = F_249 ( V_7 , V_232 ) ;
if ( V_34 )
goto V_233;
V_34 = - V_140 ;
if ( F_133 ( V_221 , V_232 , sizeof( struct V_232 ) ) )
goto V_233;
V_34 = 0 ;
V_233:
F_89 ( V_232 ) ;
break;
}
case V_234 : {
struct V_232 * V_232 ;
V_34 = - V_39 ;
V_232 = F_250 ( V_221 , sizeof( * V_232 ) ) ;
if ( F_235 ( V_232 ) ) {
V_34 = F_236 ( V_232 ) ;
goto V_113;
}
V_34 = F_251 ( V_7 , V_232 ) ;
if ( V_34 )
goto V_235;
V_34 = 0 ;
V_235:
F_89 ( V_232 ) ;
break;
}
case V_236 : {
V_224 = F_78 ( sizeof( struct V_224 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_224 )
goto V_113;
V_34 = F_252 ( V_7 , V_224 ) ;
if ( V_34 )
goto V_113;
V_34 = - V_140 ;
if ( F_133 ( V_221 , V_224 , sizeof( struct V_224 ) ) )
goto V_113;
V_34 = 0 ;
break;
}
case V_237 : {
V_224 = F_250 ( V_221 , sizeof( * V_224 ) ) ;
if ( F_235 ( V_224 ) ) {
V_34 = F_236 ( V_224 ) ;
goto V_113;
}
V_34 = F_253 ( V_7 , V_224 ) ;
if ( V_34 )
goto V_113;
V_34 = 0 ;
break;
}
case V_238 : {
struct V_239 V_240 ;
V_34 = F_254 ( V_7 , & V_240 ) ;
if ( V_34 )
goto V_113;
V_34 = - V_140 ;
if ( F_133 ( V_221 , & V_240 , sizeof V_240 ) )
goto V_113;
V_34 = 0 ;
break;
}
case V_241 : {
struct V_239 V_240 ;
V_34 = - V_140 ;
if ( F_255 ( & V_240 , V_221 , sizeof V_240 ) )
goto V_113;
V_34 = F_256 ( V_7 , & V_240 ) ;
if ( V_34 )
goto V_113;
V_34 = 0 ;
break;
}
case V_242 : {
struct V_243 V_244 ;
V_34 = - V_140 ;
if ( F_255 ( & V_244 , V_221 , sizeof V_244 ) )
goto V_113;
V_34 = F_257 ( V_7 , & V_244 ) ;
if ( V_34 )
goto V_113;
V_34 = - V_140 ;
if ( F_133 ( V_221 , & V_244 , sizeof V_244 ) )
goto V_113;
V_34 = 0 ;
break;
}
case V_245 : {
struct V_246 V_247 ;
V_34 = - V_140 ;
if ( F_255 ( & V_247 , V_221 , sizeof V_247 ) )
goto V_113;
V_34 = F_258 ( V_7 , & V_247 ) ;
if ( V_34 )
goto V_113;
V_34 = 0 ;
break;
}
case V_248 : {
struct V_249 V_117 * V_250 = V_221 ;
struct V_249 V_251 ;
T_7 V_215 , * V_252 ;
V_252 = NULL ;
if ( V_221 ) {
V_34 = - V_140 ;
if ( F_255 ( & V_251 , V_221 ,
sizeof V_251 ) )
goto V_113;
V_34 = - V_111 ;
if ( V_251 . V_176 != sizeof V_215 )
goto V_113;
V_34 = - V_140 ;
if ( F_255 ( & V_215 , V_250 -> V_215 ,
sizeof V_215 ) )
goto V_113;
V_252 = & V_215 ;
}
V_34 = F_242 ( V_7 , V_252 ) ;
break;
}
case V_253 : {
V_223 = F_78 ( sizeof( struct V_222 ) , V_37 ) ;
V_34 = - V_39 ;
if ( ! V_223 )
goto V_113;
V_34 = F_259 ( V_7 , V_223 ) ;
if ( V_34 )
goto V_113;
V_34 = - V_140 ;
if ( F_133 ( V_221 , V_223 , sizeof( struct V_222 ) ) )
goto V_113;
V_34 = 0 ;
break;
}
case V_254 : {
V_223 = F_250 ( V_221 , sizeof( * V_223 ) ) ;
if ( F_235 ( V_223 ) ) {
V_34 = F_236 ( V_223 ) ;
goto V_113;
}
V_34 = F_260 ( V_7 , V_223 ) ;
if ( V_34 )
goto V_113;
V_34 = 0 ;
break;
}
default:
V_34 = F_246 ( V_94 , V_219 , V_220 ) ;
}
V_113:
F_19 ( V_7 ) ;
F_89 ( V_223 ) ;
F_89 ( V_224 ) ;
return V_34 ;
}
static long F_261 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_6 * V_7 = V_94 -> V_95 ;
void V_117 * V_221 = F_262 ( V_220 ) ;
int V_34 ;
if ( V_7 -> V_18 -> V_46 != V_11 -> V_46 )
return - V_225 ;
switch ( V_219 ) {
case V_248 : {
struct V_249 V_117 * V_250 = V_221 ;
struct V_249 V_251 ;
T_8 V_255 ;
T_7 V_215 ;
if ( V_221 ) {
V_34 = - V_140 ;
if ( F_255 ( & V_251 , V_221 ,
sizeof V_251 ) )
goto V_113;
V_34 = - V_111 ;
if ( V_251 . V_176 != sizeof V_255 )
goto V_113;
V_34 = - V_140 ;
if ( F_255 ( & V_255 , V_250 -> V_215 ,
sizeof V_255 ) )
goto V_113;
}
F_263 ( & V_215 , & V_255 ) ;
V_34 = F_242 ( V_7 , & V_215 ) ;
break;
}
default:
V_34 = F_245 ( V_94 , V_219 , V_220 ) ;
}
V_113:
return V_34 ;
}
static long F_264 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_18 * V_18 = V_94 -> V_95 ;
void V_117 * V_221 = ( void V_117 * ) V_220 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_225 ;
switch ( V_219 ) {
case V_256 :
V_34 = F_233 ( V_18 , V_220 ) ;
if ( V_34 < 0 )
goto V_113;
break;
case V_257 : {
struct V_107 V_258 ;
V_34 = - V_140 ;
if ( F_255 ( & V_258 , V_221 ,
sizeof V_258 ) )
goto V_113;
V_34 = F_131 ( V_18 , & V_258 , 1 ) ;
if ( V_34 )
goto V_113;
break;
}
case V_259 : {
struct V_135 log ;
V_34 = - V_140 ;
if ( F_255 ( & log , V_221 , sizeof log ) )
goto V_113;
V_34 = F_265 ( V_18 , & log ) ;
if ( V_34 )
goto V_113;
break;
}
#ifdef F_228
case V_260 : {
struct V_261 V_262 ;
V_34 = - V_140 ;
if ( F_255 ( & V_262 , V_221 , sizeof V_262 ) )
goto V_113;
V_34 = F_266 ( V_18 , & V_262 ) ;
if ( V_34 )
goto V_113;
V_34 = 0 ;
break;
}
case V_263 : {
struct V_261 V_262 ;
V_34 = - V_140 ;
if ( F_255 ( & V_262 , V_221 , sizeof V_262 ) )
goto V_113;
V_34 = F_267 ( V_18 , & V_262 ) ;
if ( V_34 )
goto V_113;
V_34 = 0 ;
break;
}
#endif
case V_264 : {
struct V_265 V_178 ;
V_34 = - V_140 ;
if ( F_255 ( & V_178 , V_221 , sizeof V_178 ) )
goto V_113;
V_34 = V_265 ( V_18 , V_178 . V_266 , V_178 . V_267 , V_178 . V_121 ) ;
break;
}
case V_268 : {
struct V_269 V_178 ;
V_34 = - V_140 ;
if ( F_255 ( & V_178 , V_221 , sizeof V_178 ) )
goto V_113;
V_34 = V_269 ( V_18 , & V_178 ) ;
break;
}
#ifdef F_268
case V_270 :
V_34 = 0 ;
F_9 ( & V_18 -> V_75 ) ;
if ( F_239 ( & V_18 -> V_211 ) != 0 )
V_34 = - V_271 ;
else
V_18 -> V_272 = V_220 ;
F_24 ( & V_18 -> V_75 ) ;
break;
#endif
default:
V_34 = F_269 ( V_94 , V_219 , V_220 ) ;
if ( V_34 == - V_273 )
V_34 = F_270 ( V_18 , V_219 , V_220 ) ;
}
V_113:
return V_34 ;
}
static long F_271 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
struct V_18 * V_18 = V_94 -> V_95 ;
int V_34 ;
if ( V_18 -> V_46 != V_11 -> V_46 )
return - V_225 ;
switch ( V_219 ) {
case V_259 : {
struct V_274 V_275 ;
struct V_135 log ;
V_34 = - V_140 ;
if ( F_255 ( & V_275 , ( void V_117 * ) V_220 ,
sizeof( V_275 ) ) )
goto V_113;
log . V_118 = V_275 . V_118 ;
log . V_276 = V_275 . V_276 ;
log . V_277 = V_275 . V_277 ;
log . V_83 = F_262 ( V_275 . V_83 ) ;
V_34 = F_265 ( V_18 , & log ) ;
if ( V_34 )
goto V_113;
break;
}
default:
V_34 = F_264 ( V_94 , V_219 , V_220 ) ;
}
V_113:
return V_34 ;
}
static int F_272 ( struct V_149 * V_150 , struct V_195 * V_196 )
{
struct V_3 * V_3 [ 1 ] ;
unsigned long V_148 ;
int V_89 ;
T_4 V_98 = V_196 -> V_198 ;
struct V_18 * V_18 = V_150 -> V_197 -> V_95 ;
V_148 = F_147 ( V_18 , V_98 ) ;
if ( F_142 ( V_148 ) )
return V_203 ;
V_89 = F_273 ( V_11 , V_11 -> V_46 , V_148 , 1 , 1 , 0 , V_3 ,
NULL ) ;
if ( F_10 ( V_89 != 1 ) )
return V_203 ;
V_196 -> V_3 = V_3 [ 0 ] ;
return 0 ;
}
static int F_274 ( struct V_93 * V_93 , struct V_149 * V_150 )
{
V_150 -> V_204 = & V_278 ;
return 0 ;
}
static int F_275 ( void )
{
int V_34 ;
struct V_18 * V_18 ;
V_18 = F_71 () ;
if ( F_235 ( V_18 ) )
return F_236 ( V_18 ) ;
#ifdef F_228
V_34 = F_276 ( V_18 ) ;
if ( V_34 < 0 ) {
F_108 ( V_18 ) ;
return V_34 ;
}
#endif
V_34 = F_232 ( L_2 , & V_279 , V_18 , V_207 ) ;
if ( V_34 < 0 )
F_108 ( V_18 ) ;
return V_34 ;
}
static long F_277 ( long V_220 )
{
switch ( V_220 ) {
case V_280 :
case V_281 :
case V_282 :
#ifdef F_268
case V_283 :
#endif
case V_284 :
return 1 ;
#ifdef F_76
case V_285 :
return V_286 ;
#endif
default:
break;
}
return F_278 ( V_220 ) ;
}
static long F_279 ( struct V_93 * V_94 ,
unsigned int V_219 , unsigned long V_220 )
{
long V_34 = - V_111 ;
switch ( V_219 ) {
case V_287 :
V_34 = - V_111 ;
if ( V_220 )
goto V_113;
V_34 = V_288 ;
break;
case V_289 :
V_34 = - V_111 ;
if ( V_220 )
goto V_113;
V_34 = F_275 () ;
break;
case V_290 :
V_34 = F_277 ( V_220 ) ;
break;
case V_291 :
V_34 = - V_111 ;
if ( V_220 )
goto V_113;
V_34 = V_57 ;
#ifdef F_227
V_34 += V_57 ;
#endif
#ifdef F_228
V_34 += V_57 ;
#endif
break;
case V_292 :
case V_293 :
case V_294 :
V_34 = - V_295 ;
break;
default:
return F_280 ( V_94 , V_219 , V_220 ) ;
}
V_113:
return V_34 ;
}
static void F_281 ( void * V_296 )
{
int V_8 = F_282 () ;
int V_34 ;
if ( F_283 ( V_8 , V_297 ) )
return;
F_32 ( V_8 , V_297 ) ;
V_34 = F_284 ( NULL ) ;
if ( V_34 ) {
F_285 ( V_8 , V_297 ) ;
F_81 ( & V_298 ) ;
F_286 ( V_299 L_3
L_4 , V_8 ) ;
}
}
static void F_287 ( void * V_296 )
{
F_84 ( & V_79 ) ;
F_281 ( V_296 ) ;
F_86 ( & V_79 ) ;
}
static void F_288 ( void * V_296 )
{
int V_8 = F_282 () ;
if ( ! F_283 ( V_8 , V_297 ) )
return;
F_285 ( V_8 , V_297 ) ;
F_289 ( NULL ) ;
}
static void F_290 ( void * V_296 )
{
F_84 ( & V_79 ) ;
F_288 ( V_296 ) ;
F_86 ( & V_79 ) ;
}
static void F_291 ( void )
{
F_61 ( ! V_300 ) ;
V_300 -- ;
if ( ! V_300 )
F_292 ( F_288 , NULL , 1 ) ;
}
static void F_88 ( void )
{
F_84 ( & V_79 ) ;
F_291 () ;
F_86 ( & V_79 ) ;
}
static int F_75 ( void )
{
int V_34 = 0 ;
F_84 ( & V_79 ) ;
V_300 ++ ;
if ( V_300 == 1 ) {
F_83 ( & V_298 , 0 ) ;
F_292 ( F_281 , NULL , 1 ) ;
if ( F_239 ( & V_298 ) ) {
F_291 () ;
V_34 = - V_271 ;
}
}
F_86 ( & V_79 ) ;
return V_34 ;
}
static int F_293 ( struct V_301 * V_302 , unsigned long V_303 ,
void * V_208 )
{
int V_8 = ( long ) V_208 ;
if ( ! V_300 )
return V_304 ;
V_303 &= ~ V_305 ;
switch ( V_303 ) {
case V_306 :
F_286 ( V_299 L_5 ,
V_8 ) ;
F_290 ( NULL ) ;
break;
case V_307 :
F_286 ( V_299 L_6 ,
V_8 ) ;
F_287 ( NULL ) ;
break;
}
return V_304 ;
}
T_9 void F_294 ( void )
{
F_295 () ;
}
static int F_296 ( struct V_301 * V_302 , unsigned long V_303 ,
void * V_208 )
{
F_286 ( V_299 L_7 ) ;
V_308 = true ;
F_292 ( F_288 , NULL , 1 ) ;
return V_304 ;
}
static void F_101 ( struct V_72 * V_309 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_309 -> V_310 ; V_20 ++ ) {
struct V_311 * V_312 = V_309 -> V_313 [ V_20 ] . V_314 ;
F_297 ( V_312 ) ;
}
F_89 ( V_309 ) ;
}
int F_298 ( const void * V_315 , const void * V_316 )
{
const struct V_317 * V_318 = V_315 ;
const struct V_317 * V_319 = V_316 ;
if ( V_318 -> V_148 < V_319 -> V_148 )
return - 1 ;
if ( V_318 -> V_148 + V_318 -> V_176 > V_319 -> V_148 + V_319 -> V_176 )
return 1 ;
return 0 ;
}
int F_299 ( struct V_72 * V_309 , struct V_311 * V_314 ,
T_5 V_148 , int V_176 )
{
if ( V_309 -> V_310 == V_320 )
return - V_321 ;
V_309 -> V_313 [ V_309 -> V_310 ++ ] = (struct V_317 ) {
. V_148 = V_148 ,
. V_176 = V_176 ,
. V_314 = V_314 ,
} ;
F_117 ( V_309 -> V_313 , V_309 -> V_310 , sizeof( struct V_317 ) ,
F_298 , NULL ) ;
return 0 ;
}
int F_300 ( struct V_72 * V_309 ,
T_5 V_148 , int V_176 )
{
struct V_317 * V_313 , V_322 ;
int V_323 ;
V_322 = (struct V_317 ) {
. V_148 = V_148 ,
. V_176 = V_176 ,
} ;
V_313 = bsearch ( & V_322 , V_309 -> V_313 , V_309 -> V_310 ,
sizeof( struct V_317 ) , F_298 ) ;
if ( V_313 == NULL )
return - V_139 ;
V_323 = V_313 - V_309 -> V_313 ;
while ( V_323 > 0 && F_298 ( & V_322 , & V_309 -> V_313 [ V_323 - 1 ] ) == 0 )
V_323 -- ;
return V_323 ;
}
int F_301 ( struct V_18 * V_18 , enum V_324 V_325 , T_5 V_148 ,
int V_176 , const void * V_303 )
{
int V_49 ;
struct V_72 * V_309 ;
struct V_317 V_313 ;
V_313 = (struct V_317 ) {
. V_148 = V_148 ,
. V_176 = V_176 ,
} ;
V_309 = F_302 ( V_18 -> V_71 [ V_325 ] , & V_18 -> V_50 ) ;
V_49 = F_300 ( V_309 , V_148 , V_176 ) ;
if ( V_49 < 0 )
return - V_295 ;
while ( V_49 < V_309 -> V_310 &&
F_298 ( & V_313 , & V_309 -> V_313 [ V_49 ] ) == 0 ) {
if ( ! F_303 ( V_309 -> V_313 [ V_49 ] . V_314 , V_148 , V_176 , V_303 ) )
return 0 ;
V_49 ++ ;
}
return - V_295 ;
}
int F_304 ( struct V_18 * V_18 , enum V_324 V_325 , T_5 V_148 ,
int V_176 , void * V_303 )
{
int V_49 ;
struct V_72 * V_309 ;
struct V_317 V_313 ;
V_313 = (struct V_317 ) {
. V_148 = V_148 ,
. V_176 = V_176 ,
} ;
V_309 = F_302 ( V_18 -> V_71 [ V_325 ] , & V_18 -> V_50 ) ;
V_49 = F_300 ( V_309 , V_148 , V_176 ) ;
if ( V_49 < 0 )
return - V_295 ;
while ( V_49 < V_309 -> V_310 &&
F_298 ( & V_313 , & V_309 -> V_313 [ V_49 ] ) == 0 ) {
if ( ! F_305 ( V_309 -> V_313 [ V_49 ] . V_314 , V_148 , V_176 , V_303 ) )
return 0 ;
V_49 ++ ;
}
return - V_295 ;
}
int F_306 ( struct V_18 * V_18 , enum V_324 V_325 , T_5 V_148 ,
int V_176 , struct V_311 * V_314 )
{
struct V_72 * V_326 , * V_309 ;
V_309 = V_18 -> V_71 [ V_325 ] ;
if ( V_309 -> V_310 > V_320 - 1 )
return - V_321 ;
V_326 = F_125 ( V_309 , sizeof( struct V_72 ) , V_37 ) ;
if ( ! V_326 )
return - V_39 ;
F_299 ( V_326 , V_314 , V_148 , V_176 ) ;
F_12 ( V_18 -> V_71 [ V_325 ] , V_326 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_89 ( V_309 ) ;
return 0 ;
}
int F_307 ( struct V_18 * V_18 , enum V_324 V_325 ,
struct V_311 * V_314 )
{
int V_20 , V_34 ;
struct V_72 * V_326 , * V_309 ;
V_309 = V_18 -> V_71 [ V_325 ] ;
V_326 = F_125 ( V_309 , sizeof( * V_309 ) , V_37 ) ;
if ( ! V_326 )
return - V_39 ;
V_34 = - V_139 ;
for ( V_20 = 0 ; V_20 < V_326 -> V_310 ; V_20 ++ )
if ( V_326 -> V_313 [ V_20 ] . V_314 == V_314 ) {
V_34 = 0 ;
V_326 -> V_310 -- ;
V_326 -> V_313 [ V_20 ] = V_326 -> V_313 [ V_326 -> V_310 ] ;
F_117 ( V_326 -> V_313 , V_326 -> V_310 ,
sizeof( struct V_317 ) ,
F_298 , NULL ) ;
break;
}
if ( V_34 ) {
F_89 ( V_326 ) ;
return V_34 ;
}
F_12 ( V_18 -> V_71 [ V_325 ] , V_326 ) ;
F_126 ( & V_18 -> V_50 ) ;
F_89 ( V_309 ) ;
return V_34 ;
}
static int F_308 ( void * V_327 , T_10 * V_303 )
{
unsigned V_177 = ( long ) V_327 ;
struct V_18 * V_18 ;
* V_303 = 0 ;
F_84 ( & V_79 ) ;
F_309 ( V_18 , & V_80 , V_80 )
* V_303 += * ( T_6 * ) ( ( void * ) V_18 + V_177 ) ;
F_86 ( & V_79 ) ;
return 0 ;
}
static int F_310 ( void * V_327 , T_10 * V_303 )
{
unsigned V_177 = ( long ) V_327 ;
struct V_18 * V_18 ;
struct V_6 * V_7 ;
int V_20 ;
* V_303 = 0 ;
F_84 ( & V_79 ) ;
F_309 (kvm, &vm_list, vm_list)
F_28 ( V_20 , V_7 , V_18 )
* V_303 += * ( T_6 * ) ( ( void * ) V_7 + V_177 ) ;
F_86 ( & V_79 ) ;
return 0 ;
}
static int F_311 ( void )
{
int V_34 = - V_140 ;
struct V_328 * V_252 ;
V_329 = F_312 ( L_8 , NULL ) ;
if ( V_329 == NULL )
goto V_113;
for ( V_252 = V_330 ; V_252 -> V_331 ; ++ V_252 ) {
V_252 -> V_332 = F_313 ( V_252 -> V_331 , 0444 , V_329 ,
( void * ) ( long ) V_252 -> V_177 ,
V_333 [ V_252 -> V_334 ] ) ;
if ( V_252 -> V_332 == NULL )
goto V_335;
}
return 0 ;
V_335:
F_314 ( V_329 ) ;
V_113:
return V_34 ;
}
static void F_315 ( void )
{
struct V_328 * V_252 ;
for ( V_252 = V_330 ; V_252 -> V_331 ; ++ V_252 )
F_316 ( V_252 -> V_332 ) ;
F_316 ( V_329 ) ;
}
static int F_317 ( void )
{
if ( V_300 )
F_288 ( NULL ) ;
return 0 ;
}
static void F_318 ( void )
{
if ( V_300 ) {
F_175 ( F_319 ( & V_79 ) ) ;
F_281 ( NULL ) ;
}
}
static inline
struct V_6 * F_320 ( struct V_16 * V_336 )
{
return F_50 ( V_336 , struct V_6 , V_16 ) ;
}
static void F_321 ( struct V_16 * V_336 , int V_8 )
{
struct V_6 * V_7 = F_320 ( V_336 ) ;
F_17 ( V_7 , V_8 ) ;
}
static void F_322 ( struct V_16 * V_336 ,
struct V_154 * V_337 )
{
struct V_6 * V_7 = F_320 ( V_336 ) ;
F_21 ( V_7 ) ;
}
int F_323 ( void * V_338 , unsigned V_339 , unsigned V_340 ,
struct V_341 * V_341 )
{
int V_34 ;
int V_8 ;
V_34 = F_324 ( V_338 ) ;
if ( V_34 )
goto V_342;
V_141 = F_43 ( V_37 | V_38 ) ;
if ( V_141 == NULL ) {
V_34 = - V_39 ;
goto V_113;
}
V_144 = F_164 ( V_141 ) ;
V_142 = F_43 ( V_37 | V_38 ) ;
if ( V_142 == NULL ) {
V_34 = - V_39 ;
goto V_343;
}
V_145 = F_164 ( V_142 ) ;
V_143 = F_43 ( V_37 | V_38 ) ;
if ( V_143 == NULL ) {
V_34 = - V_39 ;
goto V_343;
}
V_146 = F_164 ( V_143 ) ;
if ( ! F_27 ( & V_297 , V_37 ) ) {
V_34 = - V_39 ;
goto V_343;
}
V_34 = F_325 () ;
if ( V_34 < 0 )
goto V_344;
F_326 (cpu) {
F_327 ( V_8 ,
V_345 ,
& V_34 , 1 ) ;
if ( V_34 < 0 )
goto V_346;
}
V_34 = F_328 ( & V_347 ) ;
if ( V_34 )
goto V_348;
F_329 ( & V_349 ) ;
if ( ! V_340 )
V_340 = F_330 ( struct V_6 ) ;
V_350 = F_331 ( L_9 , V_339 , V_340 ,
0 , NULL ) ;
if ( ! V_350 ) {
V_34 = - V_39 ;
goto V_351;
}
V_34 = F_332 () ;
if ( V_34 )
goto V_123;
V_352 . V_353 = V_341 ;
V_279 . V_353 = V_341 ;
V_206 . V_353 = V_341 ;
V_34 = F_333 ( & V_354 ) ;
if ( V_34 ) {
F_286 ( V_355 L_10 ) ;
goto V_356;
}
F_334 ( & V_357 ) ;
V_209 . V_358 = F_321 ;
V_209 . V_359 = F_322 ;
V_34 = F_311 () ;
if ( V_34 ) {
F_286 ( V_355 L_11 ) ;
goto V_360;
}
return 0 ;
V_360:
F_335 ( & V_357 ) ;
V_356:
F_336 () ;
V_123:
F_337 ( V_350 ) ;
V_351:
F_338 ( & V_349 ) ;
F_339 ( & V_347 ) ;
V_348:
V_346:
F_340 () ;
V_344:
F_35 ( V_297 ) ;
V_343:
if ( V_143 )
F_341 ( V_143 ) ;
if ( V_142 )
F_341 ( V_142 ) ;
F_341 ( V_141 ) ;
V_113:
F_342 () ;
V_342:
return V_34 ;
}
void F_343 ( void )
{
F_315 () ;
F_344 ( & V_354 ) ;
F_337 ( V_350 ) ;
F_336 () ;
F_335 ( & V_357 ) ;
F_338 ( & V_349 ) ;
F_339 ( & V_347 ) ;
F_292 ( F_288 , NULL , 1 ) ;
F_340 () ;
F_342 () ;
F_35 ( V_297 ) ;
F_341 ( V_142 ) ;
F_341 ( V_141 ) ;
}
