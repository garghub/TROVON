static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 ;
}
static inline void F_2 ( struct V_1 * V_1 , int V_3 )
{
V_1 -> V_2 = V_3 ;
}
void F_3 ( void )
{
F_4 ( ! F_5 ( & V_4 ) ) ;
if ( V_5 ) {
V_6 = V_5 ;
V_5 = 0 ;
}
}
void F_6 ( void )
{
F_4 ( ! F_5 ( & V_4 ) ) ;
F_4 ( V_5 ) ;
V_5 = V_6 ;
V_6 &= ~ ( V_7 | V_8 ) ;
}
bool F_7 ( void )
{
if ( ( V_6 & ( V_7 | V_8 ) ) == ( V_7 | V_8 ) )
return false ;
return true ;
}
static inline void F_8 ( T_1 * V_9 )
{
V_9 -> V_10 = V_11 ;
}
static inline bool T_2 F_9 ( unsigned long V_12 )
{
int V_13 = F_10 ( V_12 ) ;
if ( F_11 ( V_13 ) && V_12 >= F_12 ( V_13 ) -> V_10 )
return true ;
return false ;
}
static inline bool F_13 ( unsigned long V_12 , int V_13 )
{
if ( V_12 >= F_12 ( V_13 ) -> V_10 )
return true ;
return false ;
}
static inline bool F_14 ( T_1 * V_9 ,
unsigned long V_12 , unsigned long V_14 ,
unsigned long * V_15 )
{
unsigned long V_16 ;
if ( V_14 < F_15 ( V_9 ) )
return true ;
V_16 = F_16 ( 2UL << ( 30 - V_17 ) ,
( V_9 -> V_18 >> 8 ) ) ;
( * V_15 ) ++ ;
if ( ( * V_15 > V_16 ) &&
( V_12 & ( V_19 - 1 ) ) == 0 ) {
V_9 -> V_10 = V_12 ;
return false ;
}
return true ;
}
static inline void F_8 ( T_1 * V_9 )
{
}
static inline bool F_9 ( unsigned long V_12 )
{
return false ;
}
static inline bool F_13 ( unsigned long V_12 , int V_13 )
{
return false ;
}
static inline bool F_14 ( T_1 * V_9 ,
unsigned long V_12 , unsigned long V_14 ,
unsigned long * V_15 )
{
return true ;
}
static inline unsigned long * F_17 ( struct V_1 * V_1 ,
unsigned long V_12 )
{
#ifdef F_18
return F_19 ( V_12 ) -> V_20 ;
#else
return F_20 ( V_1 ) -> V_20 ;
#endif
}
static inline int F_21 ( struct V_1 * V_1 , unsigned long V_12 )
{
#ifdef F_18
V_12 &= ( V_19 - 1 ) ;
return ( V_12 >> V_21 ) * V_22 ;
#else
V_12 = V_12 - F_22 ( F_20 ( V_1 ) -> V_23 , V_24 ) ;
return ( V_12 >> V_21 ) * V_22 ;
#endif
}
static T_3 unsigned long F_23 ( struct V_1 * V_1 ,
unsigned long V_12 ,
unsigned long V_25 ,
unsigned long V_26 )
{
unsigned long * V_27 ;
unsigned long V_28 , V_29 ;
unsigned long V_30 ;
V_27 = F_17 ( V_1 , V_12 ) ;
V_28 = F_21 ( V_1 , V_12 ) ;
V_29 = V_28 / V_31 ;
V_28 &= ( V_31 - 1 ) ;
V_30 = V_27 [ V_29 ] ;
V_28 += V_25 ;
return ( V_30 >> ( V_31 - V_28 - 1 ) ) & V_26 ;
}
unsigned long F_24 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_25 ,
unsigned long V_26 )
{
return F_23 ( V_1 , V_12 , V_25 , V_26 ) ;
}
static T_3 int F_25 ( struct V_1 * V_1 , unsigned long V_12 )
{
return F_23 ( V_1 , V_12 , V_32 , V_33 ) ;
}
void F_26 ( struct V_1 * V_1 , unsigned long V_34 ,
unsigned long V_12 ,
unsigned long V_25 ,
unsigned long V_26 )
{
unsigned long * V_27 ;
unsigned long V_28 , V_29 ;
unsigned long V_35 , V_30 ;
F_27 ( V_22 != 4 ) ;
V_27 = F_17 ( V_1 , V_12 ) ;
V_28 = F_21 ( V_1 , V_12 ) ;
V_29 = V_28 / V_31 ;
V_28 &= ( V_31 - 1 ) ;
F_28 ( ! F_29 ( F_20 ( V_1 ) , V_12 ) , V_1 ) ;
V_28 += V_25 ;
V_26 <<= ( V_31 - V_28 - 1 ) ;
V_34 <<= ( V_31 - V_28 - 1 ) ;
V_30 = F_30 ( V_27 [ V_29 ] ) ;
for (; ; ) {
V_35 = F_31 ( & V_27 [ V_29 ] , V_30 , ( V_30 & ~ V_26 ) | V_34 ) ;
if ( V_30 == V_35 )
break;
V_30 = V_35 ;
}
}
void F_32 ( struct V_1 * V_1 , int V_3 )
{
if ( F_33 ( V_36 &&
V_3 < V_37 ) )
V_3 = V_38 ;
F_34 ( V_1 , ( unsigned long ) V_3 ,
V_39 , V_32 ) ;
}
static int F_35 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
int V_41 = 0 ;
unsigned V_42 ;
unsigned long V_12 = F_36 ( V_1 ) ;
unsigned long V_43 , V_44 ;
do {
V_42 = F_37 ( V_40 ) ;
V_44 = V_40 -> V_23 ;
V_43 = V_40 -> V_45 ;
if ( ! F_29 ( V_40 , V_12 ) )
V_41 = 1 ;
} while ( F_38 ( V_40 , V_42 ) );
if ( V_41 )
F_39 ( L_1 ,
V_12 , F_40 ( V_40 ) , V_40 -> V_46 ,
V_44 , V_44 + V_43 ) ;
return V_41 ;
}
static int F_41 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
if ( ! F_42 ( F_36 ( V_1 ) ) )
return 0 ;
if ( V_40 != F_20 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_43 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
if ( F_35 ( V_40 , V_1 ) )
return 1 ;
if ( ! F_41 ( V_40 , V_1 ) )
return 1 ;
return 0 ;
}
static inline int F_43 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
return 0 ;
}
static void F_44 ( struct V_1 * V_1 , const char * V_47 ,
unsigned long V_48 )
{
static unsigned long V_49 ;
static unsigned long V_50 ;
static unsigned long V_51 ;
if ( V_50 == 60 ) {
if ( F_45 ( V_52 , V_49 ) ) {
V_51 ++ ;
goto V_53;
}
if ( V_51 ) {
F_46 (
L_2 ,
V_51 ) ;
V_51 = 0 ;
}
V_50 = 0 ;
}
if ( V_50 ++ == 0 )
V_49 = V_52 + 60 * V_54 ;
F_46 ( L_3 ,
V_55 -> V_56 , F_36 ( V_1 ) ) ;
F_47 ( V_1 , V_47 ) ;
V_48 &= V_1 -> V_34 ;
if ( V_48 )
F_46 ( L_4 ,
V_48 , & V_48 ) ;
F_48 ( V_1 ) ;
F_49 () ;
F_50 () ;
V_53:
F_51 ( V_1 ) ;
F_52 ( V_57 , V_58 ) ;
}
void F_53 ( struct V_1 * V_1 )
{
F_54 ( V_1 , F_55 ( V_1 ) ) ;
}
void F_56 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
int V_61 = 1 << V_59 ;
F_57 ( V_1 , V_62 ) ;
F_58 ( V_1 , V_59 ) ;
F_59 ( V_1 ) ;
for ( V_60 = 1 ; V_60 < V_61 ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
F_60 ( V_63 , 0 ) ;
V_63 -> V_64 = V_65 ;
F_61 ( V_63 , V_1 ) ;
}
F_62 ( F_63 ( V_1 ) , - 1 ) ;
}
static int T_4 F_64 ( char * V_66 )
{
if ( ! V_66 )
return - V_67 ;
return F_65 ( V_66 , & V_68 ) ;
}
static bool F_66 ( void )
{
if ( ! F_67 () )
return false ;
return true ;
}
static void F_68 ( void )
{
if ( ! F_67 () )
return;
V_69 = true ;
}
static int T_4 F_69 ( char * V_66 )
{
unsigned long V_70 ;
if ( F_70 ( V_66 , 10 , & V_70 ) < 0 || V_70 > V_71 / 2 ) {
F_39 ( L_5 ) ;
return 0 ;
}
V_72 = V_70 ;
F_71 ( L_6 , V_70 ) ;
return 0 ;
}
static inline void F_72 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 )
{
struct V_73 * V_73 ;
if ( ! F_73 () )
return;
V_73 = F_74 ( V_1 ) ;
if ( F_33 ( ! V_73 ) )
return;
F_75 ( V_74 , & V_73 -> V_34 ) ;
F_76 ( & V_1 -> V_75 ) ;
F_77 ( V_1 , V_59 ) ;
F_78 ( V_40 , - ( 1 << V_59 ) , V_3 ) ;
}
static inline void F_79 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 )
{
struct V_73 * V_73 ;
if ( ! F_73 () )
return;
V_73 = F_74 ( V_1 ) ;
if ( F_33 ( ! V_73 ) )
return;
F_80 ( V_74 , & V_73 -> V_34 ) ;
F_77 ( V_1 , 0 ) ;
if ( ! F_81 ( V_3 ) )
F_78 ( V_40 , ( 1 << V_59 ) , V_3 ) ;
}
static inline void F_72 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 ) {}
static inline void F_79 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 ) {}
static inline void F_82 ( struct V_1 * V_1 , unsigned int V_59 )
{
F_77 ( V_1 , V_59 ) ;
F_83 ( V_1 ) ;
}
static inline void F_84 ( struct V_1 * V_1 )
{
F_85 ( V_1 ) ;
F_77 ( V_1 , 0 ) ;
}
static inline int F_86 ( struct V_1 * V_1 , struct V_1 * V_76 ,
unsigned int V_59 )
{
if ( ! F_42 ( F_36 ( V_76 ) ) )
return 0 ;
if ( F_87 ( V_76 ) && F_88 ( V_76 ) == V_59 ) {
if ( F_89 ( V_1 ) != F_89 ( V_76 ) )
return 0 ;
F_28 ( F_90 ( V_76 ) != 0 , V_76 ) ;
return 1 ;
}
if ( F_91 ( V_76 ) && F_88 ( V_76 ) == V_59 ) {
if ( F_89 ( V_1 ) != F_89 ( V_76 ) )
return 0 ;
F_28 ( F_90 ( V_76 ) != 0 , V_76 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_92 ( struct V_1 * V_1 ,
unsigned long V_12 ,
struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
unsigned long V_77 ;
unsigned long V_78 ;
unsigned long V_79 ( V_80 ) ;
struct V_1 * V_76 ;
unsigned int V_81 ;
V_81 = F_93 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
F_94 ( ! F_95 ( V_40 ) ) ;
F_28 ( V_1 -> V_34 & V_82 , V_1 ) ;
F_94 ( V_3 == - 1 ) ;
if ( F_96 ( ! F_81 ( V_3 ) ) )
F_78 ( V_40 , 1 << V_59 , V_3 ) ;
V_77 = V_12 & ( ( 1 << V_71 ) - 1 ) ;
F_28 ( V_77 & ( ( 1 << V_59 ) - 1 ) , V_1 ) ;
F_28 ( F_43 ( V_40 , V_1 ) , V_1 ) ;
V_83:
while ( V_59 < V_81 - 1 ) {
V_80 = F_97 ( V_77 , V_59 ) ;
V_76 = V_1 + ( V_80 - V_77 ) ;
if ( ! F_86 ( V_1 , V_76 , V_59 ) )
goto V_84;
if ( F_87 ( V_76 ) ) {
F_79 ( V_40 , V_76 , V_59 , V_3 ) ;
} else {
F_98 ( & V_76 -> V_75 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
F_84 ( V_76 ) ;
}
V_78 = V_80 & V_77 ;
V_1 = V_1 + ( V_78 - V_77 ) ;
V_77 = V_78 ;
V_59 ++ ;
}
if ( V_81 < V_71 ) {
if ( F_33 ( F_99 ( V_40 ) ) ) {
int V_87 ;
V_80 = F_97 ( V_77 , V_59 ) ;
V_76 = V_1 + ( V_80 - V_77 ) ;
V_87 = F_100 ( V_76 ) ;
if ( V_3 != V_87
&& ( F_81 ( V_3 ) ||
F_81 ( V_87 ) ) )
goto V_84;
}
V_81 ++ ;
goto V_83;
}
V_84:
F_82 ( V_1 , V_59 ) ;
if ( ( V_59 < V_71 - 2 ) && F_42 ( F_36 ( V_76 ) ) ) {
struct V_1 * V_88 , * V_89 ;
V_78 = V_80 & V_77 ;
V_88 = V_1 + ( V_78 - V_77 ) ;
V_80 = F_97 ( V_78 , V_59 + 1 ) ;
V_89 = V_88 + ( V_80 - V_78 ) ;
if ( F_86 ( V_88 , V_89 , V_59 + 1 ) ) {
F_101 ( & V_1 -> V_75 ,
& V_40 -> V_85 [ V_59 ] . V_90 [ V_3 ] ) ;
goto V_53;
}
}
F_102 ( & V_1 -> V_75 , & V_40 -> V_85 [ V_59 ] . V_90 [ V_3 ] ) ;
V_53:
V_40 -> V_85 [ V_59 ] . V_86 ++ ;
}
static inline bool F_103 ( struct V_1 * V_1 ,
unsigned long V_91 )
{
if ( F_33 ( F_104 ( & V_1 -> V_92 ) != - 1 ) )
return false ;
if ( F_33 ( ( unsigned long ) V_1 -> V_64 |
F_105 ( V_1 ) |
#ifdef F_106
( unsigned long ) V_1 -> V_93 |
#endif
( V_1 -> V_34 & V_91 ) ) )
return false ;
return true ;
}
static void F_107 ( struct V_1 * V_1 )
{
const char * V_94 ;
unsigned long V_48 ;
V_94 = NULL ;
V_48 = 0 ;
if ( F_33 ( F_104 ( & V_1 -> V_92 ) != - 1 ) )
V_94 = L_7 ;
if ( F_33 ( V_1 -> V_64 != NULL ) )
V_94 = L_8 ;
if ( F_33 ( F_105 ( V_1 ) != 0 ) )
V_94 = L_9 ;
if ( F_33 ( V_1 -> V_34 & V_95 ) ) {
V_94 = L_10 ;
V_48 = V_95 ;
}
#ifdef F_106
if ( F_33 ( V_1 -> V_93 ) )
V_94 = L_11 ;
#endif
F_44 ( V_1 , V_94 , V_48 ) ;
}
static inline int F_108 ( struct V_1 * V_1 )
{
if ( F_96 ( F_103 ( V_1 , V_95 ) ) )
return 0 ;
F_107 ( V_1 ) ;
return 1 ;
}
static int F_109 ( struct V_1 * V_96 , struct V_1 * V_1 )
{
int V_41 = 1 ;
F_27 ( ( unsigned long ) V_97 & 1 ) ;
if ( ! F_110 ( V_98 ) ) {
V_41 = 0 ;
goto V_53;
}
switch ( V_1 - V_96 ) {
case 1 :
if ( F_33 ( F_111 ( V_1 ) ) ) {
F_44 ( V_1 , L_12 , 0 ) ;
goto V_53;
}
break;
case 2 :
break;
default:
if ( V_1 -> V_64 != V_65 ) {
F_44 ( V_1 , L_13 , 0 ) ;
goto V_53;
}
break;
}
if ( F_33 ( ! F_112 ( V_1 ) ) ) {
F_44 ( V_1 , L_14 , 0 ) ;
goto V_53;
}
if ( F_33 ( F_113 ( V_1 ) != V_96 ) ) {
F_44 ( V_1 , L_15 , 0 ) ;
goto V_53;
}
V_41 = 0 ;
V_53:
V_1 -> V_64 = NULL ;
F_114 ( V_1 ) ;
return V_41 ;
}
static T_3 bool F_115 ( struct V_1 * V_1 ,
unsigned int V_59 , bool V_99 )
{
int V_100 = 0 ;
F_28 ( F_112 ( V_1 ) , V_1 ) ;
F_116 ( V_1 , V_59 ) ;
F_117 ( V_1 , V_59 ) ;
if ( F_33 ( V_59 ) ) {
bool V_101 = F_118 ( V_1 ) ;
int V_60 ;
F_28 ( V_101 && F_55 ( V_1 ) != V_59 , V_1 ) ;
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
if ( V_101 )
V_100 += F_109 ( V_1 , V_1 + V_60 ) ;
if ( F_33 ( F_108 ( V_1 + V_60 ) ) ) {
V_100 ++ ;
continue;
}
( V_1 + V_60 ) -> V_34 &= ~ V_82 ;
}
}
if ( F_119 ( V_1 ) )
V_1 -> V_64 = NULL ;
if ( V_99 )
V_100 += F_108 ( V_1 ) ;
if ( V_100 )
return false ;
F_120 ( V_1 ) ;
V_1 -> V_34 &= ~ V_82 ;
F_121 ( V_1 , V_59 ) ;
if ( ! F_122 ( V_1 ) ) {
F_123 ( F_124 ( V_1 ) ,
V_102 << V_59 ) ;
F_125 ( F_124 ( V_1 ) ,
V_102 << V_59 ) ;
}
F_126 ( V_1 , V_59 ) ;
F_127 ( V_1 , 1 << V_59 , 0 ) ;
F_128 ( V_1 , 1 << V_59 , 0 ) ;
F_129 ( V_1 , V_59 ) ;
return true ;
}
static inline bool F_130 ( struct V_1 * V_1 )
{
return F_115 ( V_1 , 0 , true ) ;
}
static inline bool F_131 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_130 ( struct V_1 * V_1 )
{
return F_115 ( V_1 , 0 , false ) ;
}
static bool F_131 ( struct V_1 * V_1 )
{
return F_108 ( V_1 ) ;
}
static void F_132 ( struct V_40 * V_40 , int V_103 ,
struct V_104 * V_105 )
{
int V_3 = 0 ;
int V_106 = 0 ;
unsigned long V_107 ;
bool V_108 ;
F_133 ( & V_40 -> V_109 ) ;
V_108 = F_99 ( V_40 ) ;
V_107 = F_134 ( V_40 , V_110 ) ;
if ( V_107 )
F_135 ( V_40 , V_110 , - V_107 ) ;
while ( V_103 ) {
struct V_1 * V_1 ;
struct V_111 * V_112 ;
do {
V_106 ++ ;
if ( ++ V_3 == V_37 )
V_3 = 0 ;
V_112 = & V_105 -> V_113 [ V_3 ] ;
} while ( F_136 ( V_112 ) );
if ( V_106 == V_37 )
V_106 = V_103 ;
do {
int V_114 ;
V_1 = F_137 ( V_112 , struct V_1 , V_75 ) ;
F_98 ( & V_1 -> V_75 ) ;
V_114 = F_1 ( V_1 ) ;
F_28 ( F_81 ( V_114 ) , V_1 ) ;
if ( F_33 ( V_108 ) )
V_114 = F_100 ( V_1 ) ;
if ( F_131 ( V_1 ) )
continue;
F_92 ( V_1 , F_36 ( V_1 ) , V_40 , 0 , V_114 ) ;
F_138 ( V_1 , 0 , V_114 ) ;
} while ( -- V_103 && -- V_106 && ! F_136 ( V_112 ) );
}
F_139 ( & V_40 -> V_109 ) ;
}
static void F_140 ( struct V_40 * V_40 ,
struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_59 ,
int V_3 )
{
unsigned long V_107 ;
F_133 ( & V_40 -> V_109 ) ;
V_107 = F_134 ( V_40 , V_110 ) ;
if ( V_107 )
F_135 ( V_40 , V_110 , - V_107 ) ;
if ( F_33 ( F_99 ( V_40 ) ||
F_81 ( V_3 ) ) ) {
V_3 = F_25 ( V_1 , V_12 ) ;
}
F_92 ( V_1 , V_12 , V_40 , V_59 , V_3 ) ;
F_139 ( & V_40 -> V_109 ) ;
}
static void T_2 F_141 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_40 , int V_13 )
{
F_142 ( V_1 , V_40 , V_13 , V_12 ) ;
F_143 ( V_1 ) ;
F_51 ( V_1 ) ;
F_120 ( V_1 ) ;
F_76 ( & V_1 -> V_75 ) ;
#ifdef F_144
if ( ! F_145 ( V_40 ) )
F_146 ( V_1 , F_147 ( V_12 << V_17 ) ) ;
#endif
}
static void T_2 F_148 ( unsigned long V_12 , unsigned long V_40 ,
int V_13 )
{
return F_141 ( F_149 ( V_12 ) , V_12 , V_40 , V_13 ) ;
}
static void F_150 ( unsigned long V_12 )
{
T_1 * V_9 ;
int V_13 , V_115 ;
if ( ! F_9 ( V_12 ) )
return;
V_13 = F_10 ( V_12 ) ;
V_9 = F_12 ( V_13 ) ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
struct V_40 * V_40 = & V_9 -> V_117 [ V_115 ] ;
if ( V_12 >= V_40 -> V_23 && V_12 < F_151 ( V_40 ) )
break;
}
F_148 ( V_12 , V_115 , V_13 ) ;
}
static inline void F_150 ( unsigned long V_12 )
{
}
void T_2 F_152 ( T_5 V_118 , T_5 V_119 )
{
unsigned long V_44 = F_153 ( V_118 ) ;
unsigned long V_120 = F_154 ( V_119 ) ;
for (; V_44 < V_120 ; V_44 ++ ) {
if ( F_155 ( V_44 ) ) {
struct V_1 * V_1 = F_149 ( V_44 ) ;
F_150 ( V_44 ) ;
F_76 ( & V_1 -> V_75 ) ;
F_156 ( V_1 ) ;
}
}
}
static void F_54 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned long V_34 ;
int V_3 ;
unsigned long V_12 = F_36 ( V_1 ) ;
if ( ! F_115 ( V_1 , V_59 , true ) )
return;
V_3 = F_25 ( V_1 , V_12 ) ;
F_157 ( V_34 ) ;
F_158 ( V_121 , 1 << V_59 ) ;
F_140 ( F_20 ( V_1 ) , V_1 , V_12 , V_59 , V_3 ) ;
F_159 ( V_34 ) ;
}
static void T_4 F_160 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned int V_61 = 1 << V_59 ;
struct V_1 * V_63 = V_1 ;
unsigned int V_122 ;
F_161 ( V_63 ) ;
for ( V_122 = 0 ; V_122 < ( V_61 - 1 ) ; V_122 ++ , V_63 ++ ) {
F_161 ( V_63 + 1 ) ;
F_162 ( V_63 ) ;
F_60 ( V_63 , 0 ) ;
}
F_162 ( V_63 ) ;
F_60 ( V_63 , 0 ) ;
F_20 ( V_1 ) -> V_123 += V_61 ;
F_163 ( V_1 ) ;
F_164 ( V_1 , V_59 ) ;
}
int T_2 F_10 ( unsigned long V_12 )
{
static F_165 ( V_124 ) ;
int V_13 ;
F_133 ( & V_124 ) ;
V_13 = F_166 ( V_12 , & V_125 ) ;
if ( V_13 < 0 )
V_13 = V_126 ;
F_139 ( & V_124 ) ;
return V_13 ;
}
static inline bool T_2 F_167 ( unsigned long V_12 , int V_127 ,
struct V_128 * V_129 )
{
int V_13 ;
V_13 = F_166 ( V_12 , V_129 ) ;
if ( V_13 >= 0 && V_13 != V_127 )
return false ;
return true ;
}
static inline bool T_2 F_168 ( unsigned long V_12 , int V_127 )
{
return F_167 ( V_12 , V_127 , & V_125 ) ;
}
static inline bool T_2 F_168 ( unsigned long V_12 , int V_127 )
{
return true ;
}
static inline bool T_2 F_167 ( unsigned long V_12 , int V_127 ,
struct V_128 * V_129 )
{
return true ;
}
void T_4 F_169 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_59 )
{
if ( F_9 ( V_12 ) )
return;
return F_160 ( V_1 , V_59 ) ;
}
struct V_1 * F_170 ( unsigned long V_44 ,
unsigned long V_120 , struct V_40 * V_40 )
{
struct V_1 * V_130 ;
struct V_1 * V_131 ;
V_120 -- ;
if ( ! F_155 ( V_44 ) || ! F_155 ( V_120 ) )
return NULL ;
V_130 = F_149 ( V_44 ) ;
if ( F_20 ( V_130 ) != V_40 )
return NULL ;
V_131 = F_149 ( V_120 ) ;
if ( F_89 ( V_130 ) != F_89 ( V_131 ) )
return NULL ;
return V_130 ;
}
void F_171 ( struct V_40 * V_40 )
{
unsigned long V_132 = V_40 -> V_23 ;
unsigned long V_133 ;
V_133 = F_172 ( V_132 + 1 , V_24 ) ;
for (; V_132 < F_151 ( V_40 ) ;
V_132 = V_133 ,
V_133 += V_24 ) {
V_133 = F_173 ( V_133 , F_151 ( V_40 ) ) ;
if ( ! F_170 ( V_132 ,
V_133 , V_40 ) )
return;
}
V_40 -> V_134 = true ;
}
void F_174 ( struct V_40 * V_40 )
{
V_40 -> V_134 = false ;
}
static void T_4 F_175 ( struct V_1 * V_1 ,
unsigned long V_12 , int V_61 )
{
int V_60 ;
if ( ! V_1 )
return;
if ( V_61 == V_135 &&
( V_12 & ( V_135 - 1 ) ) == 0 ) {
F_32 ( V_1 , V_136 ) ;
F_160 ( V_1 , V_71 - 1 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ , V_1 ++ )
F_160 ( V_1 , 0 ) ;
}
static inline void T_4 F_176 ( void )
{
if ( F_177 ( & V_137 ) )
F_178 ( & V_138 ) ;
}
static int T_4 F_179 ( void * V_139 )
{
T_1 * V_9 = V_139 ;
int V_13 = V_9 -> V_140 ;
struct V_128 V_141 = { } ;
unsigned long V_118 = V_52 ;
unsigned long V_61 = 0 ;
unsigned long V_142 , V_143 ;
int V_60 , V_115 ;
struct V_40 * V_40 ;
unsigned long V_144 = V_9 -> V_10 ;
const struct V_145 * V_145 = F_180 ( V_9 -> V_140 ) ;
if ( V_144 == V_11 ) {
F_176 () ;
return 0 ;
}
if ( ! F_181 ( V_145 ) )
F_182 ( V_55 , V_145 ) ;
F_183 ( V_9 -> V_10 < V_9 -> V_146 ) ;
F_183 ( V_9 -> V_10 > F_15 ( V_9 ) ) ;
V_9 -> V_10 = V_11 ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
V_40 = V_9 -> V_117 + V_115 ;
if ( V_144 < F_151 ( V_40 ) )
break;
}
F_184 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_12 , V_120 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_147 = NULL ;
unsigned long V_148 = 0 ;
int V_149 = 0 ;
V_120 = F_173 ( V_143 , F_151 ( V_40 ) ) ;
V_12 = V_144 ;
if ( V_12 < V_142 )
V_12 = V_142 ;
if ( V_12 < V_40 -> V_23 )
V_12 = V_40 -> V_23 ;
for (; V_12 < V_120 ; V_12 ++ ) {
if ( ! F_42 ( V_12 ) )
goto V_150;
if ( ( V_12 & ( V_135 - 1 ) ) == 0 ) {
if ( ! F_155 ( V_12 ) ) {
V_1 = NULL ;
goto V_150;
}
}
if ( ! F_167 ( V_12 , V_13 , & V_141 ) ) {
V_1 = NULL ;
goto V_150;
}
if ( V_1 && ( V_12 & ( V_135 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_61 += V_149 ;
F_175 ( V_147 ,
V_148 , V_149 ) ;
V_147 = NULL ;
V_148 = V_149 = 0 ;
V_1 = F_149 ( V_12 ) ;
F_185 () ;
}
if ( V_1 -> V_34 ) {
F_94 ( F_20 ( V_1 ) != V_40 ) ;
goto V_150;
}
F_141 ( V_1 , V_12 , V_115 , V_13 ) ;
if ( ! V_147 ) {
V_147 = V_1 ;
V_148 = V_12 ;
V_149 = 0 ;
}
V_149 ++ ;
continue;
V_150:
V_61 += V_149 ;
F_175 ( V_147 , V_148 ,
V_149 ) ;
V_147 = NULL ;
V_148 = V_149 = 0 ;
}
V_144 = F_16 ( V_120 , V_144 ) ;
}
F_4 ( ++ V_115 < V_116 && F_186 ( ++ V_40 ) ) ;
F_71 ( L_16 , V_13 , V_61 ,
F_187 ( V_52 - V_118 ) ) ;
F_176 () ;
return 0 ;
}
void T_4 F_188 ( void )
{
struct V_40 * V_40 ;
#ifdef F_189
int V_13 ;
F_62 ( & V_137 , F_190 ( V_151 ) ) ;
F_191 (nid, N_MEMORY) {
F_192 ( F_179 , F_12 ( V_13 ) , L_17 , V_13 ) ;
}
F_193 ( & V_138 ) ;
F_194 () ;
#endif
F_195 (zone)
F_171 ( V_40 ) ;
}
void T_4 F_196 ( struct V_1 * V_1 )
{
unsigned V_60 = V_24 ;
struct V_1 * V_63 = V_1 ;
do {
F_162 ( V_63 ) ;
F_60 ( V_63 , 0 ) ;
} while ( ++ V_63 , -- V_60 );
F_32 ( V_1 , V_152 ) ;
if ( V_21 >= V_71 ) {
V_60 = V_24 ;
V_63 = V_1 ;
do {
F_163 ( V_63 ) ;
F_164 ( V_63 , V_71 - 1 ) ;
V_63 += V_135 ;
} while ( V_60 -= V_135 );
} else {
F_163 ( V_1 ) ;
F_164 ( V_1 , V_21 ) ;
}
F_197 ( V_1 , V_24 ) ;
}
static inline void F_198 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_153 , int V_154 , struct V_85 * V_155 ,
int V_3 )
{
unsigned long V_156 = 1 << V_154 ;
while ( V_154 > V_153 ) {
V_155 -- ;
V_154 -- ;
V_156 >>= 1 ;
F_28 ( F_43 ( V_40 , & V_1 [ V_156 ] ) , & V_1 [ V_156 ] ) ;
if ( F_110 ( V_157 ) &&
F_73 () &&
V_154 < F_199 () ) {
F_72 ( V_40 , & V_1 [ V_156 ] , V_154 , V_3 ) ;
continue;
}
F_102 ( & V_1 [ V_156 ] . V_75 , & V_155 -> V_90 [ V_3 ] ) ;
V_155 -> V_86 ++ ;
F_82 ( & V_1 [ V_156 ] , V_154 ) ;
}
}
static void F_200 ( struct V_1 * V_1 )
{
const char * V_94 = NULL ;
unsigned long V_48 = 0 ;
if ( F_33 ( F_104 ( & V_1 -> V_92 ) != - 1 ) )
V_94 = L_7 ;
if ( F_33 ( V_1 -> V_64 != NULL ) )
V_94 = L_8 ;
if ( F_33 ( F_105 ( V_1 ) != 0 ) )
V_94 = L_18 ;
if ( F_33 ( V_1 -> V_34 & V_158 ) ) {
V_94 = L_19 ;
V_48 = V_158 ;
F_51 ( V_1 ) ;
return;
}
if ( F_33 ( V_1 -> V_34 & V_82 ) ) {
V_94 = L_20 ;
V_48 = V_82 ;
}
#ifdef F_106
if ( F_33 ( V_1 -> V_93 ) )
V_94 = L_11 ;
#endif
F_44 ( V_1 , V_94 , V_48 ) ;
}
static inline int F_201 ( struct V_1 * V_1 )
{
if ( F_96 ( F_103 ( V_1 ,
V_82 | V_158 ) ) )
return 0 ;
F_200 ( V_1 ) ;
return 1 ;
}
static inline bool F_202 ( bool V_159 )
{
return F_110 ( V_160 ) &&
F_203 () && V_159 ;
}
static bool F_204 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_205 ( struct V_1 * V_1 )
{
return F_201 ( V_1 ) ;
}
static bool F_204 ( struct V_1 * V_1 )
{
return F_201 ( V_1 ) ;
}
static bool F_205 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_206 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
if ( F_33 ( F_201 ( V_63 ) ) )
return true ;
}
return false ;
}
static void F_207 ( struct V_1 * V_1 , unsigned int V_59 , T_6 V_161 ,
unsigned int V_162 )
{
int V_60 ;
bool V_159 = true ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
if ( V_159 )
V_159 &= F_208 ( V_63 ) ;
}
F_77 ( V_1 , 0 ) ;
F_163 ( V_1 ) ;
F_209 ( V_1 , V_59 ) ;
F_128 ( V_1 , 1 << V_59 , 1 ) ;
F_127 ( V_1 , 1 << V_59 , 1 ) ;
F_210 ( V_1 , V_59 ) ;
if ( ! F_202 ( V_159 ) && ( V_161 & V_163 ) )
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_211 ( V_1 + V_60 ) ;
if ( V_59 && ( V_161 & V_164 ) )
F_56 ( V_1 , V_59 ) ;
F_212 ( V_1 , V_59 , V_161 ) ;
if ( V_162 & V_165 )
F_213 ( V_1 ) ;
else
F_214 ( V_1 ) ;
}
static inline
struct V_1 * F_215 ( struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
unsigned int V_166 ;
struct V_85 * V_155 ;
struct V_1 * V_1 ;
for ( V_166 = V_59 ; V_166 < V_71 ; ++ V_166 ) {
V_155 = & ( V_40 -> V_85 [ V_166 ] ) ;
V_1 = F_216 ( & V_155 -> V_90 [ V_3 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
V_155 -> V_86 -- ;
F_198 ( V_40 , V_1 , V_59 , V_166 , V_155 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_217 ( struct V_40 * V_40 ,
unsigned int V_59 )
{
return F_215 ( V_40 , V_59 , V_152 ) ;
}
static inline struct V_1 * F_217 ( struct V_40 * V_40 ,
unsigned int V_59 ) { return NULL ; }
int F_218 ( struct V_40 * V_40 ,
struct V_1 * V_130 , struct V_1 * V_131 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned int V_59 ;
int V_167 = 0 ;
#ifndef F_219
F_94 ( F_20 ( V_130 ) != F_20 ( V_131 ) ) ;
#endif
for ( V_1 = V_130 ; V_1 <= V_131 ; ) {
F_28 ( F_220 ( V_1 ) != F_40 ( V_40 ) , V_1 ) ;
if ( ! F_42 ( F_36 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
if ( ! F_91 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_59 = F_88 ( V_1 ) ;
F_221 ( & V_1 -> V_75 ,
& V_40 -> V_85 [ V_59 ] . V_90 [ V_3 ] ) ;
V_1 += 1 << V_59 ;
V_167 += 1 << V_59 ;
}
return V_167 ;
}
int F_222 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_44 , V_120 ;
struct V_1 * V_130 , * V_131 ;
V_44 = F_36 ( V_1 ) ;
V_44 = V_44 & ~ ( V_24 - 1 ) ;
V_130 = F_149 ( V_44 ) ;
V_131 = V_130 + V_24 - 1 ;
V_120 = V_44 + V_24 - 1 ;
if ( ! F_29 ( V_40 , V_44 ) )
V_130 = V_1 ;
if ( ! F_29 ( V_40 , V_120 ) )
return 0 ;
return F_218 ( V_40 , V_130 , V_131 , V_3 ) ;
}
static void F_223 ( struct V_1 * V_168 ,
int V_169 , int V_3 )
{
int V_170 = 1 << ( V_169 - V_21 ) ;
while ( V_170 -- ) {
F_32 ( V_168 , V_3 ) ;
V_168 += V_24 ;
}
}
static bool F_224 ( unsigned int V_59 , int V_171 )
{
if ( V_59 >= V_21 )
return true ;
if ( V_59 >= V_21 / 2 ||
V_171 == V_172 ||
V_171 == V_38 ||
V_36 )
return true ;
return false ;
}
static void F_225 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_173 )
{
unsigned int V_166 = F_88 ( V_1 ) ;
int V_174 ;
if ( V_166 >= V_21 ) {
F_223 ( V_1 , V_166 , V_173 ) ;
return;
}
V_174 = F_222 ( V_40 , V_1 , V_173 ) ;
if ( V_174 >= ( 1 << ( V_21 - 1 ) ) ||
V_36 )
F_32 ( V_1 , V_173 ) ;
}
int F_226 ( struct V_85 * V_155 , unsigned int V_59 ,
int V_3 , bool V_175 , bool * V_176 )
{
int V_60 ;
int V_177 ;
if ( V_155 -> V_86 == 0 )
return - 1 ;
* V_176 = false ;
for ( V_60 = 0 ; ; V_60 ++ ) {
V_177 = V_178 [ V_3 ] [ V_60 ] ;
if ( V_177 == V_179 )
break;
if ( F_136 ( & V_155 -> V_90 [ V_177 ] ) )
continue;
if ( F_224 ( V_59 , V_3 ) )
* V_176 = true ;
if ( ! V_175 )
return V_177 ;
if ( * V_176 )
return V_177 ;
}
return - 1 ;
}
static void F_227 ( struct V_1 * V_1 , struct V_40 * V_40 ,
unsigned int V_180 )
{
int V_114 ;
unsigned long V_181 , V_34 ;
V_181 = ( V_40 -> V_123 / 100 ) + V_24 ;
if ( V_40 -> V_182 >= V_181 )
return;
F_228 ( & V_40 -> V_109 , V_34 ) ;
if ( V_40 -> V_182 >= V_181 )
goto V_183;
V_114 = F_100 ( V_1 ) ;
if ( V_114 != V_184 &&
! F_81 ( V_114 ) && ! F_229 ( V_114 ) ) {
V_40 -> V_182 += V_24 ;
F_32 ( V_1 , V_184 ) ;
F_222 ( V_40 , V_1 , V_184 ) ;
}
V_183:
F_230 ( & V_40 -> V_109 , V_34 ) ;
}
static void F_231 ( const struct V_185 * V_186 )
{
struct V_187 * V_187 = V_186 -> V_187 ;
unsigned long V_34 ;
struct V_188 * V_189 ;
struct V_40 * V_40 ;
struct V_1 * V_1 ;
int V_59 ;
F_232 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( V_40 -> V_182 <= V_24 )
continue;
F_228 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_85 * V_155 = & ( V_40 -> V_85 [ V_59 ] ) ;
V_1 = F_216 (
& V_155 -> V_90 [ V_184 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
V_40 -> V_182 -= F_173 ( V_24 ,
V_40 -> V_182 ) ;
F_32 ( V_1 , V_186 -> V_3 ) ;
F_222 ( V_40 , V_1 , V_186 -> V_3 ) ;
F_230 ( & V_40 -> V_109 , V_34 ) ;
return;
}
F_230 ( & V_40 -> V_109 , V_34 ) ;
}
}
static inline struct V_1 *
F_233 ( struct V_40 * V_40 , unsigned int V_59 , int V_190 )
{
struct V_85 * V_155 ;
unsigned int V_166 ;
struct V_1 * V_1 ;
int V_177 ;
bool V_176 ;
for ( V_166 = V_71 - 1 ;
V_166 >= V_59 && V_166 <= V_71 - 1 ;
-- V_166 ) {
V_155 = & ( V_40 -> V_85 [ V_166 ] ) ;
V_177 = F_226 ( V_155 , V_166 ,
V_190 , false , & V_176 ) ;
if ( V_177 == - 1 )
continue;
V_1 = F_234 ( & V_155 -> V_90 [ V_177 ] ,
struct V_1 , V_75 ) ;
if ( V_176 )
F_225 ( V_40 , V_1 , V_190 ) ;
V_155 -> V_86 -- ;
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
F_198 ( V_40 , V_1 , V_59 , V_166 , V_155 ,
V_190 ) ;
F_2 ( V_1 , V_190 ) ;
F_235 ( V_1 , V_59 , V_166 ,
V_190 , V_177 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_236 ( struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
struct V_1 * V_1 ;
V_1 = F_215 ( V_40 , V_59 , V_3 ) ;
if ( F_33 ( ! V_1 ) ) {
if ( V_3 == V_136 )
V_1 = F_217 ( V_40 , V_59 ) ;
if ( ! V_1 )
V_1 = F_233 ( V_40 , V_59 , V_3 ) ;
}
F_237 ( V_1 , V_59 , V_3 ) ;
return V_1 ;
}
static int F_238 ( struct V_40 * V_40 , unsigned int V_59 ,
unsigned long V_103 , struct V_111 * V_112 ,
int V_3 , bool V_191 )
{
int V_60 ;
F_133 ( & V_40 -> V_109 ) ;
for ( V_60 = 0 ; V_60 < V_103 ; ++ V_60 ) {
struct V_1 * V_1 = F_236 ( V_40 , V_59 , V_3 ) ;
if ( F_33 ( V_1 == NULL ) )
break;
if ( F_33 ( F_204 ( V_1 ) ) )
continue;
if ( F_96 ( ! V_191 ) )
F_102 ( & V_1 -> V_75 , V_112 ) ;
else
F_101 ( & V_1 -> V_75 , V_112 ) ;
V_112 = & V_1 -> V_75 ;
if ( F_229 ( F_1 ( V_1 ) ) )
F_135 ( V_40 , V_192 ,
- ( 1 << V_59 ) ) ;
}
F_135 ( V_40 , V_193 , - ( V_60 << V_59 ) ) ;
F_139 ( & V_40 -> V_109 ) ;
return V_60 ;
}
void F_239 ( struct V_40 * V_40 , struct V_104 * V_105 )
{
unsigned long V_34 ;
int V_194 , V_195 ;
F_157 ( V_34 ) ;
V_195 = F_30 ( V_105 -> V_195 ) ;
V_194 = F_173 ( V_105 -> V_103 , V_195 ) ;
if ( V_194 > 0 ) {
F_132 ( V_40 , V_194 , V_105 ) ;
V_105 -> V_103 -= V_194 ;
}
F_159 ( V_34 ) ;
}
static void F_240 ( unsigned int V_196 , struct V_40 * V_40 )
{
unsigned long V_34 ;
struct V_197 * V_198 ;
struct V_104 * V_105 ;
F_157 ( V_34 ) ;
V_198 = F_241 ( V_40 -> V_199 , V_196 ) ;
V_105 = & V_198 -> V_105 ;
if ( V_105 -> V_103 ) {
F_132 ( V_40 , V_105 -> V_103 , V_105 ) ;
V_105 -> V_103 = 0 ;
}
F_159 ( V_34 ) ;
}
static void F_242 ( unsigned int V_196 )
{
struct V_40 * V_40 ;
F_195 (zone) {
F_240 ( V_196 , V_40 ) ;
}
}
void F_243 ( struct V_40 * V_40 )
{
int V_196 = F_244 () ;
if ( V_40 )
F_240 ( V_196 , V_40 ) ;
else
F_242 ( V_196 ) ;
}
void F_245 ( struct V_40 * V_40 )
{
int V_196 ;
static T_7 V_200 ;
F_246 (cpu) {
struct V_197 * V_105 ;
struct V_40 * V_189 ;
bool V_201 = false ;
if ( V_40 ) {
V_105 = F_241 ( V_40 -> V_199 , V_196 ) ;
if ( V_105 -> V_105 . V_103 )
V_201 = true ;
} else {
F_195 (z) {
V_105 = F_241 ( V_189 -> V_199 , V_196 ) ;
if ( V_105 -> V_105 . V_103 ) {
V_201 = true ;
break;
}
}
}
if ( V_201 )
F_247 ( V_196 , & V_200 ) ;
else
F_248 ( V_196 , & V_200 ) ;
}
F_249 ( & V_200 , ( V_202 ) F_243 ,
V_40 , 1 ) ;
}
void F_250 ( struct V_40 * V_40 )
{
unsigned long V_12 , V_203 ;
unsigned long V_34 ;
unsigned int V_59 , V_204 ;
struct V_1 * V_1 ;
if ( F_251 ( V_40 ) )
return;
F_228 ( & V_40 -> V_109 , V_34 ) ;
V_203 = F_151 ( V_40 ) ;
for ( V_12 = V_40 -> V_23 ; V_12 < V_203 ; V_12 ++ )
if ( F_155 ( V_12 ) ) {
V_1 = F_149 ( V_12 ) ;
if ( F_20 ( V_1 ) != V_40 )
continue;
if ( ! F_252 ( V_1 ) )
F_253 ( V_1 ) ;
}
F_254 (order, t) {
F_255 (page,
&zone->free_area[order].free_list[t], lru) {
unsigned long V_60 ;
V_12 = F_36 ( V_1 ) ;
for ( V_60 = 0 ; V_60 < ( 1UL << V_59 ) ; V_60 ++ )
F_256 ( F_149 ( V_12 + V_60 ) ) ;
}
}
F_230 ( & V_40 -> V_109 , V_34 ) ;
}
void F_257 ( struct V_1 * V_1 , bool V_191 )
{
struct V_40 * V_40 = F_20 ( V_1 ) ;
struct V_104 * V_105 ;
unsigned long V_34 ;
unsigned long V_12 = F_36 ( V_1 ) ;
int V_3 ;
if ( ! F_130 ( V_1 ) )
return;
V_3 = F_25 ( V_1 , V_12 ) ;
F_2 ( V_1 , V_3 ) ;
F_157 ( V_34 ) ;
F_258 ( V_121 ) ;
if ( V_3 >= V_37 ) {
if ( F_33 ( F_81 ( V_3 ) ) ) {
F_140 ( V_40 , V_1 , V_12 , 0 , V_3 ) ;
goto V_53;
}
V_3 = V_136 ;
}
V_105 = & F_259 ( V_40 -> V_199 ) -> V_105 ;
if ( ! V_191 )
F_102 ( & V_1 -> V_75 , & V_105 -> V_113 [ V_3 ] ) ;
else
F_101 ( & V_1 -> V_75 , & V_105 -> V_113 [ V_3 ] ) ;
V_105 -> V_103 ++ ;
if ( V_105 -> V_103 >= V_105 -> V_154 ) {
unsigned long V_195 = F_30 ( V_105 -> V_195 ) ;
F_132 ( V_40 , V_195 , V_105 ) ;
V_105 -> V_103 -= V_195 ;
}
V_53:
F_159 ( V_34 ) ;
}
void F_260 ( struct V_111 * V_112 , bool V_191 )
{
struct V_1 * V_1 , * V_205 ;
F_261 (page, next, list, lru) {
F_262 ( V_1 , V_191 ) ;
F_257 ( V_1 , V_191 ) ;
}
}
void F_263 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
T_6 V_206 ;
F_28 ( F_118 ( V_1 ) , V_1 ) ;
F_28 ( ! F_90 ( V_1 ) , V_1 ) ;
#ifdef F_264
if ( F_265 ( V_1 ) )
F_263 ( F_266 ( V_1 [ 0 ] . V_207 ) , V_59 ) ;
#endif
V_206 = F_267 ( V_1 ) ;
F_212 ( V_1 , 0 , V_206 ) ;
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
F_163 ( V_1 + V_60 ) ;
F_212 ( V_1 + V_60 , 0 , V_206 ) ;
}
}
int F_268 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned long V_208 ;
struct V_40 * V_40 ;
int V_114 ;
F_183 ( ! F_91 ( V_1 ) ) ;
V_40 = F_20 ( V_1 ) ;
V_114 = F_100 ( V_1 ) ;
if ( ! F_81 ( V_114 ) ) {
V_208 = F_269 ( V_40 ) + ( 1 << V_59 ) ;
if ( ! F_270 ( V_40 , 0 , V_208 , 0 , 0 ) )
return 0 ;
F_78 ( V_40 , - ( 1UL << V_59 ) , V_114 ) ;
}
F_98 ( & V_1 -> V_75 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
F_84 ( V_1 ) ;
F_212 ( V_1 , V_59 , V_209 ) ;
if ( V_59 >= V_21 - 1 ) {
struct V_1 * V_210 = V_1 + ( 1 << V_59 ) - 1 ;
for (; V_1 < V_210 ; V_1 += V_24 ) {
int V_114 = F_100 ( V_1 ) ;
if ( ! F_81 ( V_114 ) && ! F_229 ( V_114 ) )
F_32 ( V_1 ,
V_136 ) ;
}
}
return 1UL << V_59 ;
}
int F_271 ( struct V_1 * V_1 )
{
unsigned int V_59 ;
int V_61 ;
V_59 = F_88 ( V_1 ) ;
V_61 = F_268 ( V_1 , V_59 ) ;
if ( ! V_61 )
return 0 ;
F_163 ( V_1 ) ;
F_263 ( V_1 , V_59 ) ;
return V_61 ;
}
static inline void F_272 ( struct V_40 * V_211 , struct V_40 * V_189 ,
T_6 V_34 )
{
#ifdef F_273
int V_212 = F_274 () ;
enum V_213 V_214 = V_215 ;
if ( F_33 ( V_34 & V_216 ) ) {
V_214 = V_217 ;
V_212 = V_211 -> V_127 ;
}
if ( V_189 -> V_127 == V_212 ) {
F_275 ( V_189 , V_218 ) ;
F_275 ( V_189 , V_214 ) ;
} else {
F_275 ( V_189 , V_219 ) ;
F_275 ( V_211 , V_220 ) ;
}
#endif
}
static inline
struct V_1 * F_276 ( struct V_40 * V_211 ,
struct V_40 * V_40 , unsigned int V_59 ,
T_6 V_161 , unsigned int V_162 ,
int V_3 )
{
unsigned long V_34 ;
struct V_1 * V_1 ;
bool V_191 = ( ( V_161 & V_221 ) != 0 ) ;
if ( F_96 ( V_59 == 0 ) ) {
struct V_104 * V_105 ;
struct V_111 * V_112 ;
F_157 ( V_34 ) ;
do {
V_105 = & F_259 ( V_40 -> V_199 ) -> V_105 ;
V_112 = & V_105 -> V_113 [ V_3 ] ;
if ( F_136 ( V_112 ) ) {
V_105 -> V_103 += F_238 ( V_40 , 0 ,
V_105 -> V_195 , V_112 ,
V_3 , V_191 ) ;
if ( F_33 ( F_136 ( V_112 ) ) )
goto V_222;
}
if ( V_191 )
V_1 = F_137 ( V_112 , struct V_1 , V_75 ) ;
else
V_1 = F_234 ( V_112 , struct V_1 , V_75 ) ;
F_277 ( V_40 , V_223 ) ;
F_98 ( & V_1 -> V_75 ) ;
V_105 -> V_103 -- ;
} while ( F_205 ( V_1 ) );
} else {
F_278 ( ( V_161 & V_224 ) && ( V_59 > 1 ) ) ;
F_228 ( & V_40 -> V_109 , V_34 ) ;
do {
V_1 = NULL ;
if ( V_162 & V_225 ) {
V_1 = F_215 ( V_40 , V_59 , V_184 ) ;
if ( V_1 )
F_237 ( V_1 , V_59 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_236 ( V_40 , V_59 , V_3 ) ;
} while ( V_1 && F_206 ( V_1 , V_59 ) );
F_139 ( & V_40 -> V_109 ) ;
if ( ! V_1 )
goto V_222;
F_135 ( V_40 , V_223 , - ( 1 << V_59 ) ) ;
F_78 ( V_40 , - ( 1 << V_59 ) ,
F_1 ( V_1 ) ) ;
}
if ( F_279 ( & V_40 -> V_226 [ V_223 ] ) <= 0 &&
! F_280 ( V_227 , & V_40 -> V_34 ) )
F_281 ( V_227 , & V_40 -> V_34 ) ;
F_282 ( V_228 , V_40 , 1 << V_59 ) ;
F_272 ( V_211 , V_40 , V_161 ) ;
F_159 ( V_34 ) ;
F_28 ( F_43 ( V_40 , V_1 ) , V_1 ) ;
return V_1 ;
V_222:
F_159 ( V_34 ) ;
return NULL ;
}
static int T_4 F_283 ( char * V_229 )
{
return F_284 ( & V_230 . V_231 , V_229 ) ;
}
static bool F_285 ( T_6 V_206 , unsigned int V_59 )
{
if ( V_59 < V_230 . V_232 )
return false ;
if ( V_206 & V_224 )
return false ;
if ( V_230 . V_233 && ( V_206 & V_234 ) )
return false ;
if ( V_230 . V_235 &&
( V_206 & V_236 ) )
return false ;
return F_286 ( & V_230 . V_231 , 1 << V_59 ) ;
}
static int T_4 F_287 ( void )
{
T_8 V_237 = V_238 | V_239 | V_240 ;
struct V_241 * V_242 ;
V_242 = F_288 ( L_21 , NULL ,
& V_230 . V_231 ) ;
if ( F_289 ( V_242 ) )
return F_290 ( V_242 ) ;
if ( ! F_291 ( L_22 , V_237 , V_242 ,
& V_230 . V_235 ) )
goto V_243;
if ( ! F_291 ( L_23 , V_237 , V_242 ,
& V_230 . V_233 ) )
goto V_243;
if ( ! F_292 ( L_24 , V_237 , V_242 ,
& V_230 . V_232 ) )
goto V_243;
return 0 ;
V_243:
F_293 ( V_242 ) ;
return - V_244 ;
}
static inline bool F_285 ( T_6 V_206 , unsigned int V_59 )
{
return false ;
}
bool F_294 ( struct V_40 * V_189 , unsigned int V_59 , unsigned long V_245 ,
int V_246 , unsigned int V_162 ,
long V_247 )
{
long F_173 = V_245 ;
int V_248 ;
const bool V_249 = ( V_162 & V_225 ) ;
V_247 -= ( 1 << V_59 ) - 1 ;
if ( V_162 & V_250 )
F_173 -= F_173 / 2 ;
if ( F_96 ( ! V_249 ) )
V_247 -= V_189 -> V_182 ;
else
F_173 -= F_173 / 4 ;
#ifdef F_295
if ( ! ( V_162 & V_251 ) )
V_247 -= F_134 ( V_189 , V_192 ) ;
#endif
if ( V_247 <= F_173 + V_189 -> V_252 [ V_246 ] )
return false ;
if ( ! V_59 )
return true ;
for ( V_248 = V_59 ; V_248 < V_71 ; V_248 ++ ) {
struct V_85 * V_155 = & V_189 -> V_85 [ V_248 ] ;
int V_114 ;
if ( ! V_155 -> V_86 )
continue;
if ( V_249 )
return true ;
for ( V_114 = 0 ; V_114 < V_37 ; V_114 ++ ) {
if ( ! F_136 ( & V_155 -> V_90 [ V_114 ] ) )
return true ;
}
#ifdef F_295
if ( ( V_162 & V_251 ) &&
! F_136 ( & V_155 -> V_90 [ V_152 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_270 ( struct V_40 * V_189 , unsigned int V_59 , unsigned long V_245 ,
int V_246 , unsigned int V_162 )
{
return F_294 ( V_189 , V_59 , V_245 , V_246 , V_162 ,
F_134 ( V_189 , V_193 ) ) ;
}
static inline bool F_296 ( struct V_40 * V_189 , unsigned int V_59 ,
unsigned long V_245 , int V_246 , unsigned int V_162 )
{
long V_247 = F_134 ( V_189 , V_193 ) ;
long V_253 = 0 ;
#ifdef F_295
if ( ! ( V_162 & V_251 ) )
V_253 = F_134 ( V_189 , V_192 ) ;
#endif
if ( ! V_59 && ( V_247 - V_253 ) > V_245 + V_189 -> V_252 [ V_246 ] )
return true ;
return F_294 ( V_189 , V_59 , V_245 , V_246 , V_162 ,
V_247 ) ;
}
bool F_297 ( struct V_40 * V_189 , unsigned int V_59 ,
unsigned long V_245 , int V_246 )
{
long V_247 = F_134 ( V_189 , V_193 ) ;
if ( V_189 -> V_254 && V_247 < V_189 -> V_254 )
V_247 = F_298 ( V_189 , V_193 ) ;
return F_294 ( V_189 , V_59 , V_245 , V_246 , 0 ,
V_247 ) ;
}
static bool F_299 ( struct V_40 * V_255 , struct V_40 * V_40 )
{
return V_255 -> V_127 == V_40 -> V_127 ;
}
static bool F_300 ( struct V_40 * V_255 , struct V_40 * V_40 )
{
return F_301 ( F_40 ( V_255 ) , F_40 ( V_40 ) ) <
V_256 ;
}
static bool F_299 ( struct V_40 * V_255 , struct V_40 * V_40 )
{
return true ;
}
static bool F_300 ( struct V_40 * V_255 , struct V_40 * V_40 )
{
return true ;
}
static void F_302 ( struct V_40 * V_211 )
{
struct V_40 * V_40 = V_211 -> V_257 -> V_117 ;
do {
F_303 ( V_40 , V_223 ,
F_304 ( V_40 ) - F_269 ( V_40 ) -
F_279 ( & V_40 -> V_226 [ V_223 ] ) ) ;
F_305 ( V_227 , & V_40 -> V_34 ) ;
} while ( V_40 ++ != V_211 );
}
static struct V_1 *
F_306 ( T_6 V_206 , unsigned int V_59 , int V_162 ,
const struct V_185 * V_186 )
{
struct V_188 * V_189 = V_186 -> V_258 ;
struct V_40 * V_40 ;
bool V_259 = false ;
bool V_260 = ( V_162 & V_261 ) ;
V_262:
F_307 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct V_1 * V_1 ;
unsigned long V_245 ;
if ( F_308 () &&
( V_162 & V_263 ) &&
! F_309 ( V_40 , V_206 ) )
continue;
if ( V_260 ) {
if ( F_280 ( V_227 , & V_40 -> V_34 ) ) {
V_259 = true ;
continue;
}
if ( ! F_299 ( V_186 -> V_258 -> V_40 , V_40 ) ) {
if ( V_259 )
goto V_264;
V_260 = false ;
}
}
if ( V_186 -> V_265 && ! F_310 ( V_40 ) )
continue;
V_245 = V_40 -> V_208 [ V_162 & V_266 ] ;
if ( ! F_296 ( V_40 , V_59 , V_245 ,
F_311 ( V_186 ) , V_162 ) ) {
int V_41 ;
F_27 ( V_165 < V_267 ) ;
if ( V_162 & V_165 )
goto V_268;
if ( V_269 == 0 ||
! F_300 ( V_186 -> V_258 -> V_40 , V_40 ) )
continue;
V_41 = F_312 ( V_40 , V_206 , V_59 ) ;
switch ( V_41 ) {
case V_270 :
continue;
case V_271 :
continue;
default:
if ( F_270 ( V_40 , V_59 , V_245 ,
F_311 ( V_186 ) , V_162 ) )
goto V_268;
continue;
}
}
V_268:
V_1 = F_276 ( V_186 -> V_258 -> V_40 , V_40 , V_59 ,
V_206 , V_162 , V_186 -> V_3 ) ;
if ( V_1 ) {
F_207 ( V_1 , V_59 , V_206 , V_162 ) ;
if ( F_33 ( V_59 && ( V_162 & V_225 ) ) )
F_227 ( V_1 , V_40 , V_59 ) ;
return V_1 ;
}
}
if ( V_259 ) {
V_264:
V_260 = false ;
V_259 = false ;
F_302 ( V_186 -> V_258 -> V_40 ) ;
V_189 = V_186 -> V_258 ;
goto V_262;
}
return NULL ;
}
static inline bool F_313 ( void )
{
bool V_41 = false ;
#if V_272 > 8
V_41 = F_314 () ;
#endif
return V_41 ;
}
void F_315 ( T_6 V_206 , unsigned int V_59 , const char * V_273 , ... )
{
unsigned int V_274 = V_275 ;
if ( ( V_206 & V_276 ) || ! F_316 ( & V_277 ) ||
F_199 () > 0 )
return;
if ( ! ( V_206 & V_278 ) )
if ( F_317 ( V_279 ) ||
( V_55 -> V_34 & ( V_280 | V_281 ) ) )
V_274 &= ~ V_275 ;
if ( F_314 () || ! ( V_206 & V_236 ) )
V_274 &= ~ V_275 ;
if ( V_273 ) {
struct V_282 V_283 ;
T_9 args ;
va_start ( args , V_273 ) ;
V_283 . V_273 = V_273 ;
V_283 . V_284 = & args ;
F_318 ( L_25 , & V_283 ) ;
va_end ( args ) ;
}
F_318 ( L_26 ,
V_55 -> V_56 , V_59 , V_206 , & V_206 ) ;
F_50 () ;
if ( ! F_313 () )
F_319 ( V_274 ) ;
}
static inline struct V_1 *
F_320 ( T_6 V_206 , unsigned int V_59 ,
const struct V_185 * V_186 , unsigned long * V_285 )
{
struct V_286 V_287 = {
. V_187 = V_186 -> V_187 ,
. V_288 = V_186 -> V_288 ,
. V_206 = V_206 ,
. V_59 = V_59 ,
} ;
struct V_1 * V_1 ;
* V_285 = 0 ;
if ( ! F_321 ( & V_289 ) ) {
* V_285 = 1 ;
F_322 ( 1 ) ;
return NULL ;
}
V_1 = F_306 ( V_206 | V_290 , V_59 ,
V_291 | V_263 , V_186 ) ;
if ( V_1 )
goto V_53;
if ( ! ( V_206 & V_224 ) ) {
if ( V_55 -> V_34 & V_292 )
goto V_53;
if ( V_59 > V_293 )
goto V_53;
if ( V_186 -> V_294 < V_295 )
goto V_53;
if ( F_7 () )
goto V_53;
if ( V_206 & V_296 )
goto V_53;
}
if ( F_323 ( & V_287 ) || F_278 ( V_206 & V_224 ) ) {
* V_285 = 1 ;
if ( V_206 & V_224 ) {
V_1 = F_306 ( V_206 , V_59 ,
V_165 | V_263 , V_186 ) ;
if ( ! V_1 )
V_1 = F_306 ( V_206 , V_59 ,
V_165 , V_186 ) ;
}
}
V_53:
F_324 ( & V_289 ) ;
return V_1 ;
}
static struct V_1 *
F_325 ( T_6 V_206 , unsigned int V_59 ,
unsigned int V_162 , const struct V_185 * V_186 ,
enum V_297 V_237 , enum V_298 * V_298 )
{
struct V_1 * V_1 ;
int V_299 ;
if ( ! V_59 )
return NULL ;
V_55 -> V_34 |= V_280 ;
* V_298 = F_326 ( V_206 , V_59 , V_162 , V_186 ,
V_237 , & V_299 ) ;
V_55 -> V_34 &= ~ V_280 ;
if ( * V_298 <= V_300 )
return NULL ;
F_327 ( V_301 ) ;
V_1 = F_306 ( V_206 , V_59 ,
V_162 & ~ V_165 , V_186 ) ;
if ( V_1 ) {
struct V_40 * V_40 = F_20 ( V_1 ) ;
V_40 -> V_302 = false ;
F_328 ( V_40 , V_59 , true ) ;
F_327 ( V_303 ) ;
return V_1 ;
}
F_327 ( V_304 ) ;
if ( V_299 == V_305 )
* V_298 = V_306 ;
if ( V_299 == V_307
&& ! ( V_55 -> V_34 & V_308 ) )
* V_298 = V_306 ;
F_185 () ;
return NULL ;
}
static inline bool
F_329 ( struct V_185 * V_186 , int V_59 , int V_162 ,
enum V_298 V_298 , enum V_297 * V_297 ,
int V_309 )
{
int V_310 = V_311 ;
if ( ! V_59 )
return false ;
if ( F_330 ( V_298 ) ) {
if ( * V_297 == V_312 ) {
* V_297 = V_313 ;
return true ;
}
return false ;
}
if ( F_331 ( V_298 ) )
return F_332 ( V_186 , V_59 , V_162 ) ;
if ( V_59 > V_293 )
V_310 /= 4 ;
if ( V_309 <= V_310 )
return true ;
return false ;
}
static inline struct V_1 *
F_325 ( T_6 V_206 , unsigned int V_59 ,
unsigned int V_162 , const struct V_185 * V_186 ,
enum V_297 V_237 , enum V_298 * V_298 )
{
* V_298 = V_314 ;
return NULL ;
}
static inline bool
F_329 ( struct V_185 * V_186 , unsigned int V_59 , int V_162 ,
enum V_298 V_298 ,
enum V_297 * V_297 ,
int V_309 )
{
struct V_40 * V_40 ;
struct V_188 * V_189 ;
if ( ! V_59 || V_59 > V_293 )
return false ;
F_232 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( F_270 ( V_40 , 0 , F_333 ( V_40 ) ,
F_311 ( V_186 ) , V_162 ) )
return true ;
}
return false ;
}
static int
F_334 ( T_6 V_206 , unsigned int V_59 ,
const struct V_185 * V_186 )
{
struct V_315 V_315 ;
int V_316 ;
F_185 () ;
F_335 () ;
V_55 -> V_34 |= V_280 ;
F_336 ( V_206 ) ;
V_315 . V_317 = 0 ;
V_55 -> V_315 = & V_315 ;
V_316 = F_337 ( V_186 -> V_187 , V_59 , V_206 ,
V_186 -> V_288 ) ;
V_55 -> V_315 = NULL ;
F_338 () ;
V_55 -> V_34 &= ~ V_280 ;
F_185 () ;
return V_316 ;
}
static inline struct V_1 *
F_339 ( T_6 V_206 , unsigned int V_59 ,
unsigned int V_162 , const struct V_185 * V_186 ,
unsigned long * V_285 )
{
struct V_1 * V_1 = NULL ;
bool V_318 = false ;
* V_285 = F_334 ( V_206 , V_59 , V_186 ) ;
if ( F_33 ( ! ( * V_285 ) ) )
return NULL ;
V_319:
V_1 = F_306 ( V_206 , V_59 ,
V_162 & ~ V_165 , V_186 ) ;
if ( ! V_1 && ! V_318 ) {
F_231 ( V_186 ) ;
F_245 ( NULL ) ;
V_318 = true ;
goto V_319;
}
return V_1 ;
}
static void F_340 ( unsigned int V_59 , const struct V_185 * V_186 )
{
struct V_188 * V_189 ;
struct V_40 * V_40 ;
F_232 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_341 ( V_40 , V_59 , F_311 ( V_186 ) ) ;
}
static inline unsigned int
F_342 ( T_6 V_206 )
{
unsigned int V_162 = V_320 | V_263 ;
F_27 ( V_321 != ( V_322 T_6 ) V_250 ) ;
V_162 |= ( V_322 int ) ( V_206 & V_321 ) ;
if ( V_206 & V_323 ) {
if ( ! ( V_206 & V_278 ) )
V_162 |= V_225 ;
V_162 &= ~ V_263 ;
} else if ( F_33 ( F_343 ( V_55 ) ) && ! F_314 () )
V_162 |= V_225 ;
if ( F_96 ( ! ( V_206 & V_278 ) ) ) {
if ( V_206 & V_324 )
V_162 |= V_165 ;
else if ( F_344 () && ( V_55 -> V_34 & V_280 ) )
V_162 |= V_165 ;
else if ( ! F_314 () &&
( ( V_55 -> V_34 & V_280 ) ||
F_33 ( F_317 ( V_279 ) ) ) )
V_162 |= V_165 ;
}
#ifdef F_295
if ( F_345 ( V_206 ) == V_136 )
V_162 |= V_251 ;
#endif
return V_162 ;
}
bool F_346 ( T_6 V_206 )
{
return ! ! ( F_342 ( V_206 ) & V_165 ) ;
}
static inline bool F_347 ( T_6 V_206 )
{
return ( V_206 & ( V_325 | V_326 ) ) == V_325 ;
}
static inline bool
F_348 ( T_6 V_206 , unsigned V_59 ,
struct V_185 * V_186 , int V_162 ,
bool V_285 , int V_327 )
{
struct V_40 * V_40 ;
struct V_188 * V_189 ;
if ( V_327 > V_328 )
return false ;
F_232 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_329 ;
unsigned long V_330 ;
V_329 = V_330 = F_349 ( V_40 ) ;
V_329 -= F_350 ( V_327 * V_329 ,
V_328 ) ;
V_329 += F_298 ( V_40 , V_193 ) ;
if ( F_294 ( V_40 , V_59 , F_333 ( V_40 ) ,
F_311 ( V_186 ) , V_162 , V_329 ) ) {
if ( ! V_285 ) {
unsigned long V_331 ;
unsigned long V_332 ;
V_331 = F_298 ( V_40 ,
V_333 ) ;
V_332 = F_298 ( V_40 , V_334 ) ;
if ( 2 * ( V_331 + V_332 ) > V_330 ) {
F_351 ( V_335 , V_54 / 10 ) ;
return true ;
}
}
if ( V_55 -> V_34 & V_336 )
F_322 ( 1 ) ;
else
F_185 () ;
return true ;
}
}
return false ;
}
static inline struct V_1 *
F_352 ( T_6 V_206 , unsigned int V_59 ,
struct V_185 * V_186 )
{
bool V_337 = V_206 & V_236 ;
struct V_1 * V_1 = NULL ;
unsigned int V_162 ;
unsigned long V_285 ;
enum V_297 V_338 = V_312 ;
enum V_298 V_298 ;
int V_309 = 0 ;
int V_327 = 0 ;
if ( V_59 >= V_71 ) {
F_278 ( ! ( V_206 & V_276 ) ) ;
return NULL ;
}
if ( F_278 ( ( V_206 & ( V_323 | V_236 ) ) ==
( V_323 | V_236 ) ) )
V_206 &= ~ V_323 ;
V_319:
if ( V_206 & V_326 )
F_340 ( V_59 , V_186 ) ;
V_162 = F_342 ( V_206 ) ;
if ( ( V_162 & V_165 ) || ! ( V_162 & V_263 ) ) {
V_186 -> V_187 = F_353 ( F_274 () , V_206 ) ;
V_186 -> V_258 = F_354 ( V_186 -> V_187 ,
V_186 -> V_294 , V_186 -> V_288 ) ;
}
V_1 = F_306 ( V_206 , V_59 ,
V_162 & ~ V_165 , V_186 ) ;
if ( V_1 )
goto V_339;
if ( V_162 & V_165 ) {
V_1 = F_306 ( V_206 , V_59 ,
V_165 , V_186 ) ;
if ( V_1 )
goto V_339;
}
if ( ! V_337 ) {
F_278 ( V_206 & V_224 ) ;
goto V_340;
}
if ( V_55 -> V_34 & V_280 ) {
if ( F_278 ( V_206 & V_224 ) ) {
F_185 () ;
goto V_319;
}
goto V_340;
}
if ( F_317 ( V_279 ) && ! ( V_206 & V_224 ) )
goto V_340;
V_1 = F_325 ( V_206 , V_59 , V_162 , V_186 ,
V_338 ,
& V_298 ) ;
if ( V_1 )
goto V_339;
if ( F_347 ( V_206 ) ) {
if ( V_298 == V_341 )
goto V_340;
if( V_298 == V_306 )
goto V_340;
}
if ( V_59 && F_355 ( V_298 ) )
V_309 ++ ;
V_1 = F_339 ( V_206 , V_59 , V_162 , V_186 ,
& V_285 ) ;
if ( V_1 )
goto V_339;
if ( V_206 & V_342 )
goto V_343;
if ( V_59 > V_293 && ! ( V_206 & V_344 ) )
goto V_343;
if ( V_285 && V_59 <= V_293 )
V_327 = 0 ;
else
V_327 ++ ;
if ( F_348 ( V_206 , V_59 , V_186 , V_162 ,
V_285 > 0 , V_327 ) )
goto V_319;
if ( V_285 > 0 &&
F_329 ( V_186 , V_59 , V_162 ,
V_298 , & V_338 ,
V_309 ) )
goto V_319;
V_1 = F_320 ( V_206 , V_59 , V_186 , & V_285 ) ;
if ( V_1 )
goto V_339;
if ( V_285 ) {
V_327 = 0 ;
goto V_319;
}
V_343:
if ( F_347 ( V_206 ) && ! ( V_55 -> V_34 & V_308 ) )
V_338 = V_312 ;
else
V_338 = V_313 ;
V_1 = F_325 ( V_206 , V_59 , V_162 ,
V_186 , V_338 ,
& V_298 ) ;
if ( V_1 )
goto V_339;
V_340:
F_315 ( V_206 , V_59 , NULL ) ;
V_339:
return V_1 ;
}
struct V_1 *
F_356 ( T_6 V_206 , unsigned int V_59 ,
struct V_187 * V_187 , T_10 * V_288 )
{
struct V_1 * V_1 ;
unsigned int V_345 ;
unsigned int V_162 = V_346 | V_261 ;
T_6 V_347 = V_206 ;
struct V_185 V_186 = {
. V_294 = F_357 ( V_206 ) ,
. V_187 = V_187 ,
. V_288 = V_288 ,
. V_3 = F_345 ( V_206 ) ,
} ;
if ( F_308 () ) {
V_347 |= V_290 ;
V_162 |= V_263 ;
if ( ! V_186 . V_288 )
V_186 . V_288 = & V_348 ;
}
V_206 &= V_6 ;
F_358 ( V_206 ) ;
F_359 ( V_206 & V_236 ) ;
if ( F_285 ( V_206 , V_59 ) )
return NULL ;
if ( F_33 ( ! V_187 -> V_349 -> V_40 ) )
return NULL ;
if ( F_110 ( F_295 ) && V_186 . V_3 == V_136 )
V_162 |= V_251 ;
V_350:
V_345 = F_360 () ;
V_186 . V_265 = ( V_206 & V_351 ) ;
V_186 . V_258 = F_354 ( V_186 . V_187 ,
V_186 . V_294 , V_186 . V_288 ) ;
if ( ! V_186 . V_258 ) {
V_1 = NULL ;
goto V_352;
}
V_1 = F_306 ( V_347 , V_59 , V_162 , & V_186 ) ;
if ( F_96 ( V_1 ) )
goto V_53;
V_347 = F_361 ( V_206 ) ;
V_186 . V_265 = false ;
if ( F_308 () )
V_186 . V_288 = V_288 ;
V_1 = F_352 ( V_347 , V_59 , & V_186 ) ;
V_352:
if ( F_33 ( ! V_1 && F_362 ( V_345 ) ) ) {
V_347 = V_206 ;
goto V_350;
}
V_53:
if ( V_353 && V_1 )
F_363 ( V_1 , V_59 , V_206 ) ;
F_364 ( V_1 , V_59 , V_347 , V_186 . V_3 ) ;
return V_1 ;
}
unsigned long F_365 ( T_6 V_206 , unsigned int V_59 )
{
struct V_1 * V_1 ;
F_94 ( ( V_206 & V_234 ) != 0 ) ;
V_1 = F_366 ( V_206 , V_59 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_124 ( V_1 ) ;
}
unsigned long F_367 ( T_6 V_206 )
{
return F_365 ( V_206 | V_163 , 0 ) ;
}
void F_164 ( struct V_1 * V_1 , unsigned int V_59 )
{
if ( F_368 ( V_1 ) ) {
if ( V_59 == 0 )
F_257 ( V_1 , false ) ;
else
F_54 ( V_1 , V_59 ) ;
}
}
void V_247 ( unsigned long V_354 , unsigned int V_59 )
{
if ( V_354 != 0 ) {
F_94 ( ! F_369 ( ( void * ) V_354 ) ) ;
F_164 ( F_266 ( ( void * ) V_354 ) , V_59 ) ;
}
}
static struct V_1 * F_370 ( struct V_355 * V_356 ,
T_6 V_206 )
{
struct V_1 * V_1 = NULL ;
T_6 V_357 = V_206 ;
#if ( V_102 < V_358 )
V_206 |= V_164 | V_276 | V_342 |
V_278 ;
V_1 = F_371 ( V_359 , V_206 ,
V_360 ) ;
V_356 -> V_156 = V_1 ? V_358 : V_102 ;
#endif
if ( F_33 ( ! V_1 ) )
V_1 = F_371 ( V_359 , V_357 , 0 ) ;
V_356 -> V_284 = V_1 ? F_124 ( V_1 ) : NULL ;
return V_1 ;
}
void * F_372 ( struct V_355 * V_356 ,
unsigned int V_361 , T_6 V_206 )
{
unsigned int V_156 = V_102 ;
struct V_1 * V_1 ;
int V_362 ;
if ( F_33 ( ! V_356 -> V_284 ) ) {
V_363:
V_1 = F_370 ( V_356 , V_206 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_102 < V_358 )
V_156 = V_356 -> V_156 ;
#endif
F_373 ( V_1 , V_156 - 1 ) ;
V_356 -> V_364 = F_374 ( V_1 ) ;
V_356 -> V_365 = V_156 ;
V_356 -> V_362 = V_156 ;
}
V_362 = V_356 -> V_362 - V_361 ;
if ( F_33 ( V_362 < 0 ) ) {
V_1 = F_266 ( V_356 -> V_284 ) ;
if ( ! F_375 ( V_1 , V_356 -> V_365 ) )
goto V_363;
#if ( V_102 < V_358 )
V_156 = V_356 -> V_156 ;
#endif
F_60 ( V_1 , V_156 ) ;
V_356 -> V_365 = V_156 ;
V_362 = V_156 - V_361 ;
}
V_356 -> V_365 -- ;
V_356 -> V_362 = V_362 ;
return V_356 -> V_284 + V_362 ;
}
void F_376 ( void * V_354 )
{
struct V_1 * V_1 = F_377 ( V_354 ) ;
if ( F_33 ( F_368 ( V_1 ) ) )
F_54 ( V_1 , F_55 ( V_1 ) ) ;
}
struct V_1 * F_378 ( T_6 V_206 , unsigned int V_59 )
{
struct V_1 * V_1 ;
V_1 = F_366 ( V_206 , V_59 ) ;
if ( V_1 && F_379 ( V_1 , V_206 , V_59 ) != 0 ) {
F_164 ( V_1 , V_59 ) ;
V_1 = NULL ;
}
return V_1 ;
}
struct V_1 * F_380 ( int V_13 , T_6 V_206 , unsigned int V_59 )
{
struct V_1 * V_1 ;
V_1 = F_371 ( V_13 , V_206 , V_59 ) ;
if ( V_1 && F_379 ( V_1 , V_206 , V_59 ) != 0 ) {
F_164 ( V_1 , V_59 ) ;
V_1 = NULL ;
}
return V_1 ;
}
void F_381 ( struct V_1 * V_1 , unsigned int V_59 )
{
F_382 ( V_1 , V_59 ) ;
F_164 ( V_1 , V_59 ) ;
}
void F_383 ( unsigned long V_354 , unsigned int V_59 )
{
if ( V_354 != 0 ) {
F_94 ( ! F_369 ( ( void * ) V_354 ) ) ;
F_381 ( F_266 ( ( void * ) V_354 ) , V_59 ) ;
}
}
static void * F_384 ( unsigned long V_354 , unsigned int V_59 ,
T_11 V_156 )
{
if ( V_354 ) {
unsigned long V_366 = V_354 + ( V_102 << V_59 ) ;
unsigned long V_367 = V_354 + F_385 ( V_156 ) ;
F_263 ( F_266 ( ( void * ) V_354 ) , V_59 ) ;
while ( V_367 < V_366 ) {
F_386 ( V_367 ) ;
V_367 += V_102 ;
}
}
return ( void * ) V_354 ;
}
void * F_387 ( T_11 V_156 , T_6 V_206 )
{
unsigned int V_59 = F_388 ( V_156 ) ;
unsigned long V_354 ;
V_354 = F_365 ( V_206 , V_59 ) ;
return F_384 ( V_354 , V_59 , V_156 ) ;
}
void * T_2 F_389 ( int V_13 , T_11 V_156 , T_6 V_206 )
{
unsigned int V_59 = F_388 ( V_156 ) ;
struct V_1 * V_63 = F_371 ( V_13 , V_206 , V_59 ) ;
if ( ! V_63 )
return NULL ;
return F_384 ( ( unsigned long ) F_124 ( V_63 ) , V_59 , V_156 ) ;
}
void F_390 ( void * V_368 , T_11 V_156 )
{
unsigned long V_354 = ( unsigned long ) V_368 ;
unsigned long V_119 = V_354 + F_385 ( V_156 ) ;
while ( V_354 < V_119 ) {
F_386 ( V_354 ) ;
V_354 += V_102 ;
}
}
static unsigned long F_391 ( int V_362 )
{
struct V_188 * V_189 ;
struct V_40 * V_40 ;
unsigned long V_369 = 0 ;
struct V_187 * V_187 = F_353 ( F_274 () , V_370 ) ;
F_392 (zone, z, zonelist, offset) {
unsigned long V_156 = V_40 -> V_123 ;
unsigned long V_154 = F_304 ( V_40 ) ;
if ( V_156 > V_154 )
V_369 += V_156 - V_154 ;
}
return V_369 ;
}
unsigned long F_393 ( void )
{
return F_391 ( F_357 ( V_371 ) ) ;
}
unsigned long F_394 ( void )
{
return F_391 ( F_357 ( V_372 ) ) ;
}
static inline void F_395 ( struct V_40 * V_40 )
{
if ( F_110 ( F_273 ) )
F_396 ( L_27 , F_40 ( V_40 ) ) ;
}
long F_397 ( void )
{
long V_329 ;
unsigned long V_373 ;
unsigned long V_374 = 0 ;
unsigned long V_174 [ V_375 ] ;
struct V_40 * V_40 ;
int V_75 ;
for ( V_75 = V_376 ; V_75 < V_375 ; V_75 ++ )
V_174 [ V_75 ] = F_398 ( V_377 + V_75 ) ;
F_399 (zone)
V_374 += V_40 -> V_208 [ V_378 ] ;
V_329 = F_398 ( V_193 ) - V_379 ;
V_373 = V_174 [ V_380 ] + V_174 [ V_381 ] ;
V_373 -= F_173 ( V_373 / 2 , V_374 ) ;
V_329 += V_373 ;
V_329 += F_398 ( V_382 ) -
F_173 ( F_398 ( V_382 ) / 2 , V_374 ) ;
if ( V_329 < 0 )
V_329 = 0 ;
return V_329 ;
}
void F_400 ( struct V_383 * V_384 )
{
V_384 -> V_385 = V_386 ;
V_384 -> V_387 = F_398 ( V_388 ) ;
V_384 -> V_389 = F_398 ( V_193 ) ;
V_384 -> V_390 = F_401 () ;
V_384 -> V_391 = V_392 ;
V_384 -> V_393 = F_402 () ;
V_384 -> V_394 = V_102 ;
}
void F_403 ( struct V_383 * V_384 , int V_13 )
{
int V_395 ;
unsigned long V_123 = 0 ;
unsigned long V_396 = 0 ;
unsigned long V_397 = 0 ;
T_1 * V_9 = F_12 ( V_13 ) ;
for ( V_395 = 0 ; V_395 < V_116 ; V_395 ++ )
V_123 += V_9 -> V_117 [ V_395 ] . V_123 ;
V_384 -> V_385 = V_123 ;
V_384 -> V_387 = F_404 ( V_13 , V_388 ) ;
V_384 -> V_389 = F_404 ( V_13 , V_193 ) ;
#ifdef F_405
for ( V_395 = 0 ; V_395 < V_116 ; V_395 ++ ) {
struct V_40 * V_40 = & V_9 -> V_117 [ V_395 ] ;
if ( F_406 ( V_40 ) ) {
V_396 += V_40 -> V_123 ;
V_397 += F_134 ( V_40 , V_193 ) ;
}
}
V_384 -> V_391 = V_396 ;
V_384 -> V_393 = V_397 ;
#else
V_384 -> V_391 = V_396 ;
V_384 -> V_393 = V_397 ;
#endif
V_384 -> V_394 = V_102 ;
}
bool F_407 ( unsigned int V_34 , int V_13 )
{
bool V_41 = false ;
unsigned int V_345 ;
if ( ! ( V_34 & V_275 ) )
goto V_53;
do {
V_345 = F_360 () ;
V_41 = ! F_408 ( V_13 , V_348 ) ;
} while ( F_362 ( V_345 ) );
V_53:
return V_41 ;
}
static void F_409 ( unsigned char type )
{
static const char V_398 [ V_179 ] = {
[ V_38 ] = 'U' ,
[ V_136 ] = 'M' ,
[ V_172 ] = 'E' ,
[ V_184 ] = 'H' ,
#ifdef F_295
[ V_152 ] = 'C' ,
#endif
#ifdef F_410
[ V_399 ] = 'I' ,
#endif
} ;
char V_400 [ V_179 + 1 ] ;
char * V_63 = V_400 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_179 ; V_60 ++ ) {
if ( type & ( 1 << V_60 ) )
* V_63 ++ = V_398 [ V_60 ] ;
}
* V_63 = '\0' ;
F_396 ( L_28 , V_400 ) ;
}
void F_411 ( unsigned int V_274 )
{
unsigned long V_401 = 0 ;
int V_196 ;
struct V_40 * V_40 ;
F_195 (zone) {
if ( F_407 ( V_274 , F_40 ( V_40 ) ) )
continue;
F_246 (cpu)
V_401 += F_241 ( V_40 -> V_199 , V_196 ) -> V_105 . V_103 ;
}
F_396 ( L_29
L_30
L_31
L_32
L_33
L_34 ,
F_398 ( V_402 ) ,
F_398 ( V_403 ) ,
F_398 ( V_404 ) ,
F_398 ( V_405 ) ,
F_398 ( V_406 ) ,
F_398 ( V_407 ) ,
F_398 ( V_408 ) ,
F_398 ( V_334 ) ,
F_398 ( V_333 ) ,
F_398 ( V_409 ) ,
F_398 ( V_382 ) ,
F_398 ( V_410 ) ,
F_398 ( V_411 ) ,
F_398 ( V_388 ) ,
F_398 ( V_412 ) ,
F_398 ( V_413 ) ,
F_398 ( V_193 ) ,
V_401 ,
F_398 ( V_192 ) ) ;
F_195 (zone) {
int V_60 ;
if ( F_407 ( V_274 , F_40 ( V_40 ) ) )
continue;
V_401 = 0 ;
F_246 (cpu)
V_401 += F_241 ( V_40 -> V_199 , V_196 ) -> V_105 . V_103 ;
F_395 ( V_40 ) ;
F_396 ( L_35
L_36
L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62
L_63
L_64
L_65
L_66 ,
V_40 -> V_46 ,
F_412 ( F_134 ( V_40 , V_193 ) ) ,
F_412 ( F_333 ( V_40 ) ) ,
F_412 ( F_269 ( V_40 ) ) ,
F_412 ( F_304 ( V_40 ) ) ,
F_412 ( F_134 ( V_40 , V_402 ) ) ,
F_412 ( F_134 ( V_40 , V_403 ) ) ,
F_412 ( F_134 ( V_40 , V_405 ) ) ,
F_412 ( F_134 ( V_40 , V_406 ) ) ,
F_412 ( F_134 ( V_40 , V_408 ) ) ,
F_412 ( F_134 ( V_40 , V_404 ) ) ,
F_412 ( F_134 ( V_40 , V_407 ) ) ,
F_412 ( V_40 -> V_414 ) ,
F_412 ( V_40 -> V_123 ) ,
F_412 ( F_134 ( V_40 , V_415 ) ) ,
F_412 ( F_134 ( V_40 , V_334 ) ) ,
F_412 ( F_134 ( V_40 , V_333 ) ) ,
F_412 ( F_134 ( V_40 , V_411 ) ) ,
F_412 ( F_134 ( V_40 , V_388 ) ) ,
F_412 ( F_134 ( V_40 , V_382 ) ) ,
F_412 ( F_134 ( V_40 , V_410 ) ) ,
F_134 ( V_40 , V_416 ) *
V_417 / 1024 ,
F_412 ( F_134 ( V_40 , V_412 ) ) ,
F_412 ( F_134 ( V_40 , V_409 ) ) ,
F_412 ( F_134 ( V_40 , V_413 ) ) ,
F_412 ( V_401 ) ,
F_412 ( F_413 ( V_40 -> V_199 -> V_105 . V_103 ) ) ,
F_412 ( F_134 ( V_40 , V_192 ) ) ,
F_412 ( F_134 ( V_40 , V_418 ) ) ,
F_412 ( F_134 ( V_40 , V_110 ) ) ,
( ! F_414 ( V_40 ) ? L_67 : L_68 )
) ;
F_396 ( L_69 ) ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ )
F_396 ( L_70 , V_40 -> V_252 [ V_60 ] ) ;
F_396 ( L_66 ) ;
}
F_195 (zone) {
unsigned int V_59 ;
unsigned long V_419 [ V_71 ] , V_34 , V_420 = 0 ;
unsigned char V_398 [ V_71 ] ;
if ( F_407 ( V_274 , F_40 ( V_40 ) ) )
continue;
F_395 ( V_40 ) ;
F_396 ( L_71 , V_40 -> V_46 ) ;
F_228 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_85 * V_155 = & V_40 -> V_85 [ V_59 ] ;
int type ;
V_419 [ V_59 ] = V_155 -> V_86 ;
V_420 += V_419 [ V_59 ] << V_59 ;
V_398 [ V_59 ] = 0 ;
for ( type = 0 ; type < V_179 ; type ++ ) {
if ( ! F_136 ( & V_155 -> V_90 [ type ] ) )
V_398 [ V_59 ] |= 1 << type ;
}
}
F_230 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
F_396 ( L_72 , V_419 [ V_59 ] , F_412 ( 1UL ) << V_59 ) ;
if ( V_419 [ V_59 ] )
F_409 ( V_398 [ V_59 ] ) ;
}
F_396 ( L_73 , F_412 ( V_420 ) ) ;
}
F_415 () ;
F_396 ( L_74 , F_398 ( V_421 ) ) ;
F_416 () ;
}
static void F_417 ( struct V_40 * V_40 , struct V_188 * V_188 )
{
V_188 -> V_40 = V_40 ;
V_188 -> V_422 = V_422 ( V_40 ) ;
}
static int F_418 ( T_1 * V_9 , struct V_187 * V_187 ,
int V_423 )
{
struct V_40 * V_40 ;
enum V_395 V_395 = V_116 ;
do {
V_395 -- ;
V_40 = V_9 -> V_117 + V_395 ;
if ( F_186 ( V_40 ) ) {
F_417 ( V_40 ,
& V_187 -> V_349 [ V_423 ++ ] ) ;
F_419 ( V_395 ) ;
}
} while ( V_395 );
return V_423 ;
}
static int F_420 ( char * V_424 )
{
if ( * V_424 == 'd' || * V_424 == 'D' ) {
V_425 = V_426 ;
} else if ( * V_424 == 'n' || * V_424 == 'N' ) {
V_425 = V_427 ;
} else if ( * V_424 == 'z' || * V_424 == 'Z' ) {
V_425 = V_428 ;
} else {
F_318 ( L_75 , V_424 ) ;
return - V_67 ;
}
return 0 ;
}
static T_4 int F_421 ( char * V_424 )
{
int V_41 ;
if ( ! V_424 )
return 0 ;
V_41 = F_420 ( V_424 ) ;
if ( V_41 == 0 )
F_422 ( V_429 , V_424 , V_430 ) ;
return V_41 ;
}
int F_423 ( struct V_431 * V_432 , int V_433 ,
void T_12 * V_434 , T_11 * V_435 ,
T_13 * V_436 )
{
char V_437 [ V_430 ] ;
int V_41 ;
static F_424 ( V_438 ) ;
F_425 ( & V_438 ) ;
if ( V_433 ) {
if ( strlen ( ( char * ) V_432 -> V_139 ) >= V_430 ) {
V_41 = - V_67 ;
goto V_53;
}
strcpy ( V_437 , ( char * ) V_432 -> V_139 ) ;
}
V_41 = F_426 ( V_432 , V_433 , V_434 , V_435 , V_436 ) ;
if ( V_41 )
goto V_53;
if ( V_433 ) {
int V_439 = V_425 ;
V_41 = F_420 ( ( char * ) V_432 -> V_139 ) ;
if ( V_41 ) {
strncpy ( ( char * ) V_432 -> V_139 , V_437 ,
V_430 ) ;
V_425 = V_439 ;
} else if ( V_439 != V_425 ) {
F_425 ( & V_440 ) ;
F_427 ( NULL , NULL ) ;
F_324 ( & V_440 ) ;
}
}
V_53:
F_324 ( & V_438 ) ;
return V_41 ;
}
static int F_428 ( int V_127 , T_10 * V_441 )
{
int V_442 , V_384 ;
int V_443 = V_444 ;
int V_445 = V_359 ;
const struct V_145 * V_400 = F_180 ( 0 ) ;
if ( ! F_408 ( V_127 , * V_441 ) ) {
F_429 ( V_127 , * V_441 ) ;
return V_127 ;
}
F_191 (n, N_MEMORY) {
if ( F_408 ( V_442 , * V_441 ) )
continue;
V_384 = F_301 ( V_127 , V_442 ) ;
V_384 += ( V_442 < V_127 ) ;
V_400 = F_180 ( V_442 ) ;
if ( ! F_181 ( V_400 ) )
V_384 += V_446 ;
V_384 *= ( V_447 * V_448 ) ;
V_384 += V_449 [ V_442 ] ;
if ( V_384 < V_443 ) {
V_443 = V_384 ;
V_445 = V_442 ;
}
}
if ( V_445 >= 0 )
F_429 ( V_445 , * V_441 ) ;
return V_445 ;
}
static void F_430 ( T_1 * V_9 , int V_127 )
{
int V_450 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_451 [ 0 ] ;
for ( V_450 = 0 ; V_187 -> V_349 [ V_450 ] . V_40 != NULL ; V_450 ++ )
;
V_450 = F_418 ( F_12 ( V_127 ) , V_187 , V_450 ) ;
V_187 -> V_349 [ V_450 ] . V_40 = NULL ;
V_187 -> V_349 [ V_450 ] . V_422 = 0 ;
}
static void F_431 ( T_1 * V_9 )
{
int V_450 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_451 [ 1 ] ;
V_450 = F_418 ( V_9 , V_187 , 0 ) ;
V_187 -> V_349 [ V_450 ] . V_40 = NULL ;
V_187 -> V_349 [ V_450 ] . V_422 = 0 ;
}
static void F_432 ( T_1 * V_9 , int V_452 )
{
int V_453 , V_450 , V_127 ;
int V_395 ;
struct V_40 * V_189 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_451 [ 0 ] ;
V_453 = 0 ;
for ( V_395 = V_116 - 1 ; V_395 >= 0 ; V_395 -- ) {
for ( V_450 = 0 ; V_450 < V_452 ; V_450 ++ ) {
V_127 = V_454 [ V_450 ] ;
V_189 = & F_12 ( V_127 ) -> V_117 [ V_395 ] ;
if ( F_186 ( V_189 ) ) {
F_417 ( V_189 ,
& V_187 -> V_349 [ V_453 ++ ] ) ;
F_419 ( V_395 ) ;
}
}
}
V_187 -> V_349 [ V_453 ] . V_40 = NULL ;
V_187 -> V_349 [ V_453 ] . V_422 = 0 ;
}
static int F_433 ( void )
{
return V_427 ;
}
static int F_433 ( void )
{
return V_428 ;
}
static void F_434 ( void )
{
if ( V_425 == V_426 )
V_455 = F_433 () ;
else
V_455 = V_425 ;
}
static void F_435 ( T_1 * V_9 )
{
int V_60 , V_127 , V_456 ;
T_10 V_457 ;
int V_458 , V_459 ;
struct V_187 * V_187 ;
unsigned int V_59 = V_455 ;
for ( V_60 = 0 ; V_60 < V_460 ; V_60 ++ ) {
V_187 = V_9 -> V_451 + V_60 ;
V_187 -> V_349 [ 0 ] . V_40 = NULL ;
V_187 -> V_349 [ 0 ] . V_422 = 0 ;
}
V_458 = V_9 -> V_140 ;
V_456 = V_461 ;
V_459 = V_458 ;
F_436 ( V_457 ) ;
memset ( V_454 , 0 , sizeof( V_454 ) ) ;
V_60 = 0 ;
while ( ( V_127 = F_428 ( V_458 , & V_457 ) ) >= 0 ) {
if ( F_301 ( V_458 , V_127 ) !=
F_301 ( V_458 , V_459 ) )
V_449 [ V_127 ] = V_456 ;
V_459 = V_127 ;
V_456 -- ;
if ( V_59 == V_427 )
F_430 ( V_9 , V_127 ) ;
else
V_454 [ V_60 ++ ] = V_127 ;
}
if ( V_59 == V_428 ) {
F_432 ( V_9 , V_60 ) ;
}
F_431 ( V_9 ) ;
}
int F_437 ( int V_127 )
{
struct V_188 * V_189 ;
V_189 = F_354 ( F_353 ( V_127 , V_370 ) ,
F_357 ( V_370 ) ,
NULL ) ;
return V_189 -> V_40 -> V_127 ;
}
static void F_434 ( void )
{
V_455 = V_428 ;
}
static void F_435 ( T_1 * V_9 )
{
int V_127 , V_458 ;
enum V_395 V_450 ;
struct V_187 * V_187 ;
V_458 = V_9 -> V_140 ;
V_187 = & V_9 -> V_451 [ 0 ] ;
V_450 = F_418 ( V_9 , V_187 , 0 ) ;
for ( V_127 = V_458 + 1 ; V_127 < V_448 ; V_127 ++ ) {
if ( ! F_11 ( V_127 ) )
continue;
V_450 = F_418 ( F_12 ( V_127 ) , V_187 , V_450 ) ;
}
for ( V_127 = 0 ; V_127 < V_458 ; V_127 ++ ) {
if ( ! F_11 ( V_127 ) )
continue;
V_450 = F_418 ( F_12 ( V_127 ) , V_187 , V_450 ) ;
}
V_187 -> V_349 [ V_450 ] . V_40 = NULL ;
V_187 -> V_349 [ V_450 ] . V_422 = 0 ;
}
static int F_438 ( void * V_139 )
{
int V_13 ;
int V_196 ;
T_1 * V_462 = V_139 ;
#ifdef F_273
memset ( V_449 , 0 , sizeof( V_449 ) ) ;
#endif
if ( V_462 && ! F_11 ( V_462 -> V_140 ) ) {
F_435 ( V_462 ) ;
}
F_439 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_435 ( V_9 ) ;
}
F_440 (cpu) {
F_441 ( & F_442 ( V_463 , V_196 ) , 0 ) ;
#ifdef F_443
if ( F_444 ( V_196 ) )
F_445 ( V_196 , F_437 ( F_446 ( V_196 ) ) ) ;
#endif
}
return 0 ;
}
static T_14 void T_4
F_447 ( void )
{
F_438 ( NULL ) ;
F_448 () ;
F_449 () ;
}
void T_15 F_427 ( T_1 * V_9 , struct V_40 * V_40 )
{
F_434 () ;
if ( V_464 == V_465 ) {
F_447 () ;
} else {
#ifdef F_450
if ( V_40 )
F_451 ( V_40 ) ;
#endif
F_452 ( F_438 , V_9 , NULL ) ;
}
V_466 = F_394 () ;
if ( V_466 < ( V_24 * V_179 ) )
V_36 = 1 ;
else
V_36 = 0 ;
F_71 ( L_76 ,
V_461 ,
V_467 [ V_455 ] ,
V_36 ? L_77 : L_78 ,
V_466 ) ;
#ifdef F_273
F_71 ( L_79 , V_468 [ V_469 ] ) ;
#endif
}
static inline unsigned long F_453 ( unsigned long V_174 )
{
unsigned long V_156 = 1 ;
V_174 /= V_470 ;
while ( V_156 < V_174 )
V_156 <<= 1 ;
V_156 = F_173 ( V_156 , 4096UL ) ;
return F_16 ( V_156 , 4UL ) ;
}
static inline unsigned long F_453 ( unsigned long V_174 )
{
return 4096UL ;
}
static inline unsigned long F_454 ( unsigned long V_156 )
{
return F_455 ( ~ V_156 ) ;
}
void T_2 F_456 ( unsigned long V_156 , int V_13 , unsigned long V_40 ,
unsigned long V_44 , enum V_471 V_472 )
{
struct V_473 * V_474 = F_457 ( F_458 ( V_44 ) ) ;
unsigned long V_120 = V_44 + V_156 ;
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_12 ;
unsigned long V_15 = 0 ;
#ifdef F_459
struct V_475 * V_476 = NULL , * V_400 ;
#endif
if ( V_477 < V_120 - 1 )
V_477 = V_120 - 1 ;
if ( V_474 && V_44 == V_474 -> V_478 )
V_44 += V_474 -> V_479 ;
for ( V_12 = V_44 ; V_12 < V_120 ; V_12 ++ ) {
if ( V_472 != V_480 )
goto V_481;
if ( ! F_460 ( V_12 ) )
continue;
if ( ! F_168 ( V_12 , V_13 ) )
continue;
if ( ! F_14 ( V_9 , V_12 , V_120 , & V_15 ) )
break;
#ifdef F_459
if ( ! V_482 && V_483 [ V_13 ] )
if ( V_40 == V_295 && V_12 >= V_483 [ V_13 ] )
continue;
if ( V_482 && V_40 == V_484 ) {
if ( ! V_476 || V_12 >= F_461 ( V_476 ) ) {
F_462 (memory, tmp)
if ( V_12 < F_461 ( V_400 ) )
break;
V_476 = V_400 ;
}
if ( V_12 >= F_463 ( V_476 ) &&
F_464 ( V_476 ) ) {
V_12 = F_461 ( V_476 ) ;
continue;
}
}
#endif
V_481:
if ( ! ( V_12 & ( V_24 - 1 ) ) ) {
struct V_1 * V_1 = F_149 ( V_12 ) ;
F_141 ( V_1 , V_12 , V_40 , V_13 ) ;
F_32 ( V_1 , V_136 ) ;
} else {
F_148 ( V_12 , V_40 , V_13 ) ;
}
}
}
static void T_2 F_465 ( struct V_40 * V_40 )
{
unsigned int V_59 , V_204 ;
F_254 (order, t) {
F_76 ( & V_40 -> V_85 [ V_59 ] . V_90 [ V_204 ] ) ;
V_40 -> V_85 [ V_59 ] . V_86 = 0 ;
}
}
static int F_466 ( struct V_40 * V_40 )
{
#ifdef F_467
int V_195 ;
V_195 = V_40 -> V_123 / 1024 ;
if ( V_195 * V_102 > 512 * 1024 )
V_195 = ( 512 * 1024 ) / V_102 ;
V_195 /= 4 ;
if ( V_195 < 1 )
V_195 = 1 ;
V_195 = F_468 ( V_195 + V_195 / 2 ) - 1 ;
return V_195 ;
#else
return 0 ;
#endif
}
static void F_469 ( struct V_104 * V_105 , unsigned long V_154 ,
unsigned long V_195 )
{
V_105 -> V_195 = 1 ;
F_470 () ;
V_105 -> V_154 = V_154 ;
F_470 () ;
V_105 -> V_195 = V_195 ;
}
static void F_471 ( struct V_197 * V_63 , unsigned long V_195 )
{
F_469 ( & V_63 -> V_105 , 6 * V_195 , F_16 ( 1UL , 1 * V_195 ) ) ;
}
static void F_472 ( struct V_197 * V_63 )
{
struct V_104 * V_105 ;
int V_3 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_105 = & V_63 -> V_105 ;
V_105 -> V_103 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ )
F_76 ( & V_105 -> V_113 [ V_3 ] ) ;
}
static void F_441 ( struct V_197 * V_63 , unsigned long V_195 )
{
F_472 ( V_63 ) ;
F_471 ( V_63 , V_195 ) ;
}
static void F_473 ( struct V_197 * V_63 ,
unsigned long V_154 )
{
unsigned long V_195 = F_16 ( 1UL , V_154 / 4 ) ;
if ( ( V_154 / 4 ) > ( V_17 * 8 ) )
V_195 = V_17 * 8 ;
F_469 ( & V_63 -> V_105 , V_154 , V_195 ) ;
}
static void F_474 ( struct V_40 * V_40 ,
struct V_197 * V_105 )
{
if ( V_485 )
F_473 ( V_105 ,
( V_40 -> V_123 /
V_485 ) ) ;
else
F_471 ( V_105 , F_466 ( V_40 ) ) ;
}
static void T_2 F_475 ( struct V_40 * V_40 , int V_196 )
{
struct V_197 * V_105 = F_241 ( V_40 -> V_199 , V_196 ) ;
F_472 ( V_105 ) ;
F_474 ( V_40 , V_105 ) ;
}
static void T_2 F_451 ( struct V_40 * V_40 )
{
int V_196 ;
V_40 -> V_199 = F_476 ( struct V_197 ) ;
F_440 (cpu)
F_475 ( V_40 , V_196 ) ;
}
void T_4 F_477 ( void )
{
struct V_40 * V_40 ;
F_195 (zone)
F_451 ( V_40 ) ;
}
static T_14 T_16
int F_478 ( struct V_40 * V_40 , unsigned long V_486 )
{
int V_60 ;
T_11 V_487 ;
V_40 -> F_453 =
F_453 ( V_486 ) ;
V_40 -> F_454 =
F_454 ( V_40 -> F_453 ) ;
V_487 = V_40 -> F_453
* sizeof( V_488 ) ;
if ( ! F_479 () ) {
V_40 -> V_489 = ( V_488 * )
F_480 (
V_487 , V_40 -> V_257 -> V_140 ) ;
} else {
V_40 -> V_489 = F_481 ( V_487 ) ;
}
if ( ! V_40 -> V_489 )
return - V_244 ;
for ( V_60 = 0 ; V_60 < V_40 -> F_453 ; ++ V_60 )
F_482 ( V_40 -> V_489 + V_60 ) ;
return 0 ;
}
static T_2 void F_483 ( struct V_40 * V_40 )
{
V_40 -> V_199 = & V_463 ;
if ( F_186 ( V_40 ) )
F_396 ( V_490 L_80 ,
V_40 -> V_46 , V_40 -> V_414 ,
F_466 ( V_40 ) ) ;
}
int T_2 F_484 ( struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_156 )
{
struct V_491 * V_9 = V_40 -> V_257 ;
int V_41 ;
V_41 = F_478 ( V_40 , V_156 ) ;
if ( V_41 )
return V_41 ;
V_9 -> V_423 = V_422 ( V_40 ) + 1 ;
V_40 -> V_23 = V_23 ;
F_485 ( V_492 , L_81 ,
L_82 ,
V_9 -> V_140 ,
( unsigned long ) V_422 ( V_40 ) ,
V_23 , ( V_23 + V_156 ) ) ;
F_465 ( V_40 ) ;
return 0 ;
}
int T_2 F_166 ( unsigned long V_12 ,
struct V_128 * V_129 )
{
unsigned long V_44 , V_120 ;
int V_13 ;
if ( V_129 -> V_493 <= V_12 && V_12 < V_129 -> V_494 )
return V_129 -> V_495 ;
V_13 = F_486 ( V_12 , & V_44 , & V_120 ) ;
if ( V_13 != - 1 ) {
V_129 -> V_493 = V_44 ;
V_129 -> V_494 = V_120 ;
V_129 -> V_495 = V_13 ;
}
return V_13 ;
}
void T_4 F_487 ( int V_13 , unsigned long V_496 )
{
unsigned long V_44 , V_120 ;
int V_60 , V_497 ;
F_184 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_44 = F_173 ( V_44 , V_496 ) ;
V_120 = F_173 ( V_120 , V_496 ) ;
if ( V_44 < V_120 )
F_488 ( F_489 ( V_44 ) ,
( V_120 - V_44 ) << V_17 ,
V_497 ) ;
}
}
void T_4 F_490 ( int V_13 )
{
unsigned long V_44 , V_120 ;
int V_60 , V_497 ;
F_184 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_491 ( V_497 , V_44 , V_120 ) ;
}
void T_2 F_492 ( unsigned int V_13 ,
unsigned long * V_44 , unsigned long * V_120 )
{
unsigned long V_498 , V_499 ;
int V_60 ;
* V_44 = - 1UL ;
* V_120 = 0 ;
F_184 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_44 = F_173 ( * V_44 , V_498 ) ;
* V_120 = F_16 ( * V_120 , V_499 ) ;
}
if ( * V_44 == - 1UL )
* V_44 = 0 ;
}
static void T_4 F_493 ( void )
{
int V_500 ;
for ( V_500 = V_116 - 1 ; V_500 >= 0 ; V_500 -- ) {
if ( V_500 == V_484 )
continue;
if ( V_501 [ V_500 ] >
V_502 [ V_500 ] )
break;
}
F_94 ( V_500 == - 1 ) ;
V_503 = V_500 ;
}
static void T_2 F_494 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_146 ,
unsigned long V_504 ,
unsigned long * V_23 ,
unsigned long * F_151 )
{
if ( V_483 [ V_13 ] ) {
if ( V_395 == V_484 ) {
* V_23 = V_483 [ V_13 ] ;
* F_151 = F_173 ( V_504 ,
V_501 [ V_503 ] ) ;
} else if ( * V_23 >= V_483 [ V_13 ] )
* V_23 = * F_151 ;
}
}
static unsigned long T_2 F_495 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_146 ,
unsigned long V_504 ,
unsigned long * V_23 ,
unsigned long * F_151 ,
unsigned long * V_505 )
{
if ( ! V_146 && ! V_504 )
return 0 ;
* V_23 = V_502 [ V_395 ] ;
* F_151 = V_501 [ V_395 ] ;
F_494 ( V_13 , V_395 ,
V_146 , V_504 ,
V_23 , F_151 ) ;
if ( * F_151 < V_146 || * V_23 > V_504 )
return 0 ;
* F_151 = F_173 ( * F_151 , V_504 ) ;
* V_23 = F_16 ( * V_23 , V_146 ) ;
return * F_151 - * V_23 ;
}
unsigned long T_2 F_496 ( int V_13 ,
unsigned long V_506 ,
unsigned long V_507 )
{
unsigned long V_508 = V_507 - V_506 ;
unsigned long V_44 , V_120 ;
int V_60 ;
F_184 (i, nid, &start_pfn, &end_pfn, NULL) {
V_44 = F_497 ( V_44 , V_506 , V_507 ) ;
V_120 = F_497 ( V_120 , V_506 , V_507 ) ;
V_508 -= V_120 - V_44 ;
}
return V_508 ;
}
unsigned long T_4 F_498 ( unsigned long V_44 ,
unsigned long V_120 )
{
return F_496 ( V_448 , V_44 , V_120 ) ;
}
static unsigned long T_2 F_499 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_146 ,
unsigned long V_504 ,
unsigned long * V_505 )
{
unsigned long V_509 = V_502 [ V_395 ] ;
unsigned long V_510 = V_501 [ V_395 ] ;
unsigned long V_23 , F_151 ;
unsigned long V_508 ;
if ( ! V_146 && ! V_504 )
return 0 ;
V_23 = F_497 ( V_146 , V_509 , V_510 ) ;
F_151 = F_497 ( V_504 , V_509 , V_510 ) ;
F_494 ( V_13 , V_395 ,
V_146 , V_504 ,
& V_23 , & F_151 ) ;
V_508 = F_496 ( V_13 , V_23 , F_151 ) ;
if ( V_483 [ V_13 ] ) {
if ( V_482 ) {
unsigned long V_44 , V_120 ;
struct V_475 * V_476 ;
F_462 (memory, r) {
V_44 = F_497 ( F_463 ( V_476 ) ,
V_23 , F_151 ) ;
V_120 = F_497 ( F_461 ( V_476 ) ,
V_23 , F_151 ) ;
if ( V_395 == V_484 &&
F_464 ( V_476 ) )
V_508 += V_120 - V_44 ;
if ( V_395 == V_295 &&
! F_464 ( V_476 ) )
V_508 += V_120 - V_44 ;
}
} else {
if ( V_395 == V_295 )
V_508 += V_504 - V_483 [ V_13 ] ;
}
}
return V_508 ;
}
static inline unsigned long T_2 F_495 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_146 ,
unsigned long V_504 ,
unsigned long * V_23 ,
unsigned long * F_151 ,
unsigned long * V_511 )
{
unsigned int V_40 ;
* V_23 = V_146 ;
for ( V_40 = 0 ; V_40 < V_395 ; V_40 ++ )
* V_23 += V_511 [ V_40 ] ;
* F_151 = * V_23 + V_511 [ V_395 ] ;
return V_511 [ V_395 ] ;
}
static inline unsigned long T_2 F_499 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_146 ,
unsigned long V_504 ,
unsigned long * V_512 )
{
if ( ! V_512 )
return 0 ;
return V_512 [ V_395 ] ;
}
static void T_2 F_500 ( struct V_491 * V_9 ,
unsigned long V_146 ,
unsigned long V_504 ,
unsigned long * V_511 ,
unsigned long * V_512 )
{
unsigned long V_513 = 0 , V_514 = 0 ;
enum V_395 V_60 ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_60 ;
unsigned long V_23 , F_151 ;
unsigned long V_156 , V_515 ;
V_156 = F_495 ( V_9 -> V_140 , V_60 ,
V_146 ,
V_504 ,
& V_23 ,
& F_151 ,
V_511 ) ;
V_515 = V_156 - F_499 ( V_9 -> V_140 , V_60 ,
V_146 , V_504 ,
V_512 ) ;
if ( V_156 )
V_40 -> V_23 = V_23 ;
else
V_40 -> V_23 = 0 ;
V_40 -> V_45 = V_156 ;
V_40 -> V_414 = V_515 ;
V_514 += V_156 ;
V_513 += V_515 ;
}
V_9 -> V_18 = V_514 ;
V_9 -> V_516 = V_513 ;
F_396 ( V_490 L_83 , V_9 -> V_140 ,
V_513 ) ;
}
static unsigned long T_4 F_501 ( unsigned long V_23 , unsigned long V_517 )
{
unsigned long V_518 ;
V_517 += V_23 & ( V_24 - 1 ) ;
V_518 = F_502 ( V_517 , V_24 ) ;
V_518 = V_518 >> V_21 ;
V_518 *= V_22 ;
V_518 = F_502 ( V_518 , 8 * sizeof( unsigned long ) ) ;
return V_518 / 8 ;
}
static void T_4 F_503 ( struct V_491 * V_9 ,
struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_517 )
{
unsigned long V_518 = F_501 ( V_23 , V_517 ) ;
V_40 -> V_20 = NULL ;
if ( V_518 )
V_40 -> V_20 =
F_480 ( V_518 ,
V_9 -> V_140 ) ;
}
static inline void F_503 ( struct V_491 * V_9 , struct V_40 * V_40 ,
unsigned long V_23 , unsigned long V_517 ) {}
void T_17 F_504 ( void )
{
unsigned int V_59 ;
if ( V_21 )
return;
if ( V_519 > V_17 )
V_59 = V_520 ;
else
V_59 = V_71 - 1 ;
V_21 = V_59 ;
}
void T_17 F_504 ( void )
{
}
static unsigned long T_17 F_505 ( unsigned long V_45 ,
unsigned long V_414 )
{
unsigned long V_174 = V_45 ;
if ( V_45 > V_414 + ( V_414 >> 4 ) &&
F_110 ( F_18 ) )
V_174 = V_414 ;
return F_385 ( V_174 * sizeof( struct V_1 ) ) >> V_17 ;
}
static void T_17 F_506 ( struct V_491 * V_9 )
{
enum V_395 V_450 ;
int V_13 = V_9 -> V_140 ;
int V_41 ;
F_507 ( V_9 ) ;
#ifdef F_508
F_509 ( & V_9 -> V_521 ) ;
V_9 -> V_522 = 0 ;
V_9 -> V_523 = V_52 ;
#endif
#ifdef F_510
F_509 ( & V_9 -> V_524 ) ;
F_76 ( & V_9 -> V_525 ) ;
V_9 -> V_526 = 0 ;
#endif
F_482 ( & V_9 -> V_527 ) ;
F_482 ( & V_9 -> V_528 ) ;
#ifdef F_511
F_482 ( & V_9 -> V_529 ) ;
#endif
F_512 ( V_9 ) ;
for ( V_450 = 0 ; V_450 < V_116 ; V_450 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_450 ;
unsigned long V_156 , V_530 , V_531 , V_532 ;
unsigned long V_23 = V_40 -> V_23 ;
V_156 = V_40 -> V_45 ;
V_530 = V_531 = V_40 -> V_414 ;
V_532 = F_505 ( V_156 , V_530 ) ;
if ( ! F_145 ( V_450 ) ) {
if ( V_531 >= V_532 ) {
V_531 -= V_532 ;
if ( V_532 )
F_396 ( V_490
L_84 ,
V_468 [ V_450 ] , V_532 ) ;
} else
F_318 ( L_85 ,
V_468 [ V_450 ] , V_532 , V_531 ) ;
}
if ( V_450 == 0 && V_531 > V_533 ) {
V_531 -= V_533 ;
F_396 ( V_490 L_86 ,
V_468 [ 0 ] , V_533 ) ;
}
if ( ! F_145 ( V_450 ) )
V_534 += V_531 ;
else if ( V_534 > V_532 * 2 )
V_534 -= V_532 ;
V_535 += V_531 ;
V_40 -> V_123 = F_145 ( V_450 ) ? V_530 : V_531 ;
#ifdef F_273
V_40 -> V_127 = V_13 ;
V_40 -> V_536 = ( V_531 * V_537 )
/ 100 ;
V_40 -> V_538 = ( V_531 * V_539 ) / 100 ;
#endif
V_40 -> V_46 = V_468 [ V_450 ] ;
F_509 ( & V_40 -> V_109 ) ;
F_509 ( & V_40 -> V_540 ) ;
F_513 ( V_40 ) ;
V_40 -> V_257 = V_9 ;
F_483 ( V_40 ) ;
F_303 ( V_40 , V_223 , V_40 -> V_123 ) ;
F_514 ( & V_40 -> V_541 ) ;
if ( ! V_156 )
continue;
F_504 () ;
F_503 ( V_9 , V_40 , V_23 , V_156 ) ;
V_41 = F_484 ( V_40 , V_23 , V_156 ) ;
F_183 ( V_41 ) ;
F_515 ( V_156 , V_13 , V_450 , V_23 ) ;
}
}
static void T_16 F_516 ( struct V_491 * V_9 )
{
unsigned long T_18 V_118 = 0 ;
unsigned long T_18 V_362 = 0 ;
if ( ! V_9 -> V_18 )
return;
#ifdef F_517
V_118 = V_9 -> V_146 & ~ ( V_135 - 1 ) ;
V_362 = V_9 -> V_146 - V_118 ;
if ( ! V_9 -> V_542 ) {
unsigned long V_156 , V_119 ;
struct V_1 * V_543 ;
V_119 = F_15 ( V_9 ) ;
V_119 = F_172 ( V_119 , V_135 ) ;
V_156 = ( V_119 - V_118 ) * sizeof( struct V_1 ) ;
V_543 = F_518 ( V_9 -> V_140 , V_156 ) ;
if ( ! V_543 )
V_543 = F_480 ( V_156 ,
V_9 -> V_140 ) ;
V_9 -> V_542 = V_543 + V_362 ;
}
#ifndef F_519
if ( V_9 == F_12 ( 0 ) ) {
V_544 = F_12 ( 0 ) -> V_542 ;
#if F_520 ( F_459 ) || F_520 ( V_545 )
if ( F_36 ( V_544 ) != V_9 -> V_146 )
V_544 -= V_362 ;
#endif
}
#endif
#endif
}
void T_17 F_521 ( int V_13 , unsigned long * V_511 ,
unsigned long V_146 , unsigned long * V_512 )
{
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_44 = 0 ;
unsigned long V_120 = 0 ;
F_4 ( V_9 -> V_423 || V_9 -> V_246 ) ;
F_8 ( V_9 ) ;
V_9 -> V_140 = V_13 ;
V_9 -> V_146 = V_146 ;
#ifdef F_459
F_492 ( V_13 , & V_44 , & V_120 ) ;
F_71 ( L_87 , V_13 ,
( V_546 ) V_44 << V_17 ,
V_120 ? ( ( V_546 ) V_120 << V_17 ) - 1 : 0 ) ;
#else
V_44 = V_146 ;
#endif
F_500 ( V_9 , V_44 , V_120 ,
V_511 , V_512 ) ;
F_516 ( V_9 ) ;
#ifdef F_517
F_396 ( V_490 L_88 ,
V_13 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_542 ) ;
#endif
F_506 ( V_9 ) ;
}
void T_4 F_522 ( void )
{
unsigned int V_547 ;
V_547 = F_523 ( V_548 . V_549 , V_448 ) ;
V_550 = V_547 + 1 ;
}
unsigned long T_4 F_524 ( void )
{
unsigned long V_551 = 0 , V_494 = 0 ;
unsigned long V_118 , V_119 , V_26 ;
int V_495 = - 1 ;
int V_60 , V_13 ;
F_184 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_118 || V_495 < 0 || V_495 == V_13 ) {
V_495 = V_13 ;
V_494 = V_119 ;
continue;
}
V_26 = ~ ( ( 1 << F_525 ( V_118 ) ) - 1 ) ;
while ( V_26 && V_494 <= ( V_118 & ( V_26 << 1 ) ) )
V_26 <<= 1 ;
V_551 |= V_26 ;
}
return ~ V_551 + 1 ;
}
static unsigned long T_4 F_526 ( int V_13 )
{
unsigned long V_552 = V_11 ;
unsigned long V_44 ;
int V_60 ;
F_184 (i, nid, &start_pfn, NULL, NULL)
V_552 = F_173 ( V_552 , V_44 ) ;
if ( V_552 == V_11 ) {
F_318 ( L_89 , V_13 ) ;
return 0 ;
}
return V_552 ;
}
unsigned long T_4 F_527 ( void )
{
return F_526 ( V_448 ) ;
}
static unsigned long T_4 F_528 ( void )
{
unsigned long V_514 = 0 ;
unsigned long V_44 , V_120 ;
int V_60 , V_13 ;
F_184 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_174 = V_120 - V_44 ;
V_514 += V_174 ;
if ( V_174 )
F_529 ( V_13 , V_151 ) ;
}
return V_514 ;
}
static void T_4 F_530 ( void )
{
int V_60 , V_13 ;
unsigned long V_553 ;
unsigned long V_554 , V_555 ;
T_10 V_556 = V_557 [ V_151 ] ;
unsigned long V_514 = F_528 () ;
int V_558 = F_531 ( V_557 [ V_151 ] ) ;
struct V_475 * V_476 ;
F_493 () ;
if ( F_532 () ) {
F_462 (memory, r) {
if ( ! F_533 ( V_476 ) )
continue;
V_13 = V_476 -> V_13 ;
V_553 = F_153 ( V_476 -> V_559 ) ;
V_483 [ V_13 ] = V_483 [ V_13 ] ?
F_173 ( V_553 , V_483 [ V_13 ] ) :
V_553 ;
}
goto V_560;
}
if ( V_482 ) {
bool V_561 = false ;
F_462 (memory, r) {
if ( F_464 ( V_476 ) )
continue;
V_13 = V_476 -> V_13 ;
V_553 = F_463 ( V_476 ) ;
if ( V_553 < 0x100000 ) {
V_561 = true ;
continue;
}
V_483 [ V_13 ] = V_483 [ V_13 ] ?
F_173 ( V_553 , V_483 [ V_13 ] ) :
V_553 ;
}
if ( V_561 )
F_318 ( L_90 ) ;
goto V_560;
}
if ( V_562 ) {
unsigned long V_563 ;
V_562 =
F_502 ( V_562 , V_135 ) ;
V_562 = F_173 ( V_514 , V_562 ) ;
V_563 = V_514 - V_562 ;
V_564 = F_16 ( V_564 , V_563 ) ;
}
if ( ! V_564 || V_564 >= V_514 )
goto V_53;
V_553 = V_502 [ V_503 ] ;
V_565:
V_554 = V_564 / V_558 ;
F_191 (nid, N_MEMORY) {
unsigned long V_44 , V_120 ;
if ( V_564 < V_554 )
V_554 = V_564 / V_558 ;
V_555 = V_554 ;
F_184 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_566 ;
V_44 = F_16 ( V_44 , V_483 [ V_13 ] ) ;
if ( V_44 >= V_120 )
continue;
if ( V_44 < V_553 ) {
unsigned long V_567 ;
V_567 = F_173 ( V_120 , V_553 )
- V_44 ;
V_555 -= F_173 ( V_567 ,
V_555 ) ;
V_564 -= F_173 ( V_567 ,
V_564 ) ;
if ( V_120 <= V_553 ) {
V_483 [ V_13 ] = V_120 ;
continue;
}
V_44 = V_553 ;
}
V_566 = V_120 - V_44 ;
if ( V_566 > V_555 )
V_566 = V_555 ;
V_483 [ V_13 ] = V_44 + V_566 ;
V_564 -= F_173 ( V_564 ,
V_566 ) ;
V_555 -= V_566 ;
if ( ! V_555 )
break;
}
}
V_558 -- ;
if ( V_558 && V_564 > V_558 )
goto V_565;
V_560:
for ( V_13 = 0 ; V_13 < V_448 ; V_13 ++ )
V_483 [ V_13 ] =
F_502 ( V_483 [ V_13 ] , V_135 ) ;
V_53:
V_557 [ V_151 ] = V_556 ;
}
static void F_534 ( T_1 * V_9 , int V_13 )
{
enum V_395 V_395 ;
if ( V_151 == V_568 )
return;
for ( V_395 = 0 ; V_395 <= V_484 - 1 ; V_395 ++ ) {
struct V_40 * V_40 = & V_9 -> V_117 [ V_395 ] ;
if ( F_186 ( V_40 ) ) {
F_529 ( V_13 , V_569 ) ;
if ( V_568 != V_569 &&
V_395 <= V_295 )
F_529 ( V_13 , V_568 ) ;
break;
}
}
}
void T_4 F_535 ( unsigned long * V_203 )
{
unsigned long V_44 , V_120 ;
int V_60 , V_13 ;
memset ( V_502 , 0 ,
sizeof( V_502 ) ) ;
memset ( V_501 , 0 ,
sizeof( V_501 ) ) ;
V_502 [ 0 ] = F_527 () ;
V_501 [ 0 ] = V_203 [ 0 ] ;
for ( V_60 = 1 ; V_60 < V_116 ; V_60 ++ ) {
if ( V_60 == V_484 )
continue;
V_502 [ V_60 ] =
V_501 [ V_60 - 1 ] ;
V_501 [ V_60 ] =
F_16 ( V_203 [ V_60 ] , V_502 [ V_60 ] ) ;
}
V_502 [ V_484 ] = 0 ;
V_501 [ V_484 ] = 0 ;
memset ( V_483 , 0 , sizeof( V_483 ) ) ;
F_530 () ;
F_71 ( L_91 ) ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ ) {
if ( V_60 == V_484 )
continue;
F_71 ( L_92 , V_468 [ V_60 ] ) ;
if ( V_502 [ V_60 ] ==
V_501 [ V_60 ] )
F_536 ( L_93 ) ;
else
F_536 ( L_94 ,
( V_546 ) V_502 [ V_60 ]
<< V_17 ,
( ( V_546 ) V_501 [ V_60 ]
<< V_17 ) - 1 ) ;
}
F_71 ( L_95 ) ;
for ( V_60 = 0 ; V_60 < V_448 ; V_60 ++ ) {
if ( V_483 [ V_60 ] )
F_71 ( L_96 , V_60 ,
( V_546 ) V_483 [ V_60 ] << V_17 ) ;
}
F_71 ( L_97 ) ;
F_184 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_71 ( L_98 , V_13 ,
( V_546 ) V_44 << V_17 ,
( ( V_546 ) V_120 << V_17 ) - 1 ) ;
F_537 () ;
F_522 () ;
F_439 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_521 ( V_13 , NULL ,
F_526 ( V_13 ) , NULL ) ;
if ( V_9 -> V_516 )
F_529 ( V_13 , V_151 ) ;
F_534 ( V_9 , V_13 ) ;
}
}
static int T_4 F_538 ( char * V_63 , unsigned long * V_570 )
{
unsigned long long V_571 ;
if ( ! V_63 )
return - V_67 ;
V_571 = F_539 ( V_63 , & V_63 ) ;
* V_570 = V_571 >> V_17 ;
F_4 ( ( V_571 >> V_17 ) > V_11 ) ;
return 0 ;
}
static int T_4 F_540 ( char * V_63 )
{
if ( F_541 ( V_63 , L_99 ) ) {
V_482 = true ;
return 0 ;
}
return F_538 ( V_63 , & V_564 ) ;
}
static int T_4 F_542 ( char * V_63 )
{
return F_538 ( V_63 , & V_562 ) ;
}
void F_197 ( struct V_1 * V_1 , long V_103 )
{
F_133 ( & V_572 ) ;
F_20 ( V_1 ) -> V_123 += V_103 ;
V_386 += V_103 ;
#ifdef F_405
if ( F_122 ( V_1 ) )
V_392 += V_103 ;
#endif
F_139 ( & V_572 ) ;
}
unsigned long F_543 ( void * V_118 , void * V_119 , int V_573 , char * V_424 )
{
void * V_453 ;
unsigned long V_174 = 0 ;
V_118 = ( void * ) F_385 ( ( unsigned long ) V_118 ) ;
V_119 = ( void * ) ( ( unsigned long ) V_119 & V_574 ) ;
for ( V_453 = V_118 ; V_453 < V_119 ; V_453 += V_102 , V_174 ++ ) {
if ( ( unsigned int ) V_573 <= 0xFF )
memset ( V_453 , V_573 , V_102 ) ;
F_544 ( F_266 ( V_453 ) ) ;
}
if ( V_174 && V_424 )
F_71 ( L_100 ,
V_424 , V_174 << ( V_17 - 10 ) , V_118 , V_119 ) ;
return V_174 ;
}
void F_545 ( struct V_1 * V_1 )
{
F_546 ( V_1 ) ;
V_386 ++ ;
F_20 ( V_1 ) -> V_123 ++ ;
V_392 ++ ;
}
void T_4 F_547 ( const char * V_229 )
{
unsigned long V_575 , V_576 , V_577 , V_578 , V_579 ;
unsigned long V_580 , V_581 ;
V_575 = F_548 () ;
V_576 = V_582 - V_583 ;
V_577 = V_584 - V_585 ;
V_578 = V_586 - V_587 ;
V_579 = V_588 - V_589 ;
V_581 = V_590 - V_591 ;
V_580 = V_592 - V_593 ;
#define F_549 ( V_118 , V_119 , V_156 , V_453 , T_19 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_549 ( V_591 , V_590 , V_581 ,
V_593 , V_580 ) ;
F_549 ( V_583 , V_582 , V_576 , V_593 , V_580 ) ;
F_549 ( V_585 , V_584 , V_577 , V_591 , V_581 ) ;
F_549 ( V_583 , V_582 , V_576 , V_587 , V_578 ) ;
F_549 ( V_585 , V_584 , V_577 , V_587 , V_578 ) ;
#undef F_549
F_71 ( L_101
#ifdef F_405
L_102
#endif
L_103 ,
F_550 () << ( V_17 - 10 ) ,
V_575 << ( V_17 - 10 ) ,
V_576 >> 10 , V_577 >> 10 , V_578 >> 10 ,
( V_581 + V_580 ) >> 10 , V_579 >> 10 ,
( V_575 - V_386 - V_594 ) << ( V_17 - 10 ) ,
V_594 << ( V_17 - 10 ) ,
#ifdef F_405
V_392 << ( V_17 - 10 ) ,
#endif
V_229 ? L_104 : L_105 , V_229 ? V_229 : L_105 ) ;
}
void T_4 F_551 ( unsigned long V_595 )
{
V_533 = V_595 ;
}
void T_4 F_552 ( unsigned long * V_511 )
{
F_521 ( 0 , V_511 ,
F_553 ( V_596 ) >> V_17 , NULL ) ;
}
static int F_554 ( struct V_597 * V_462 ,
unsigned long V_598 , void * V_599 )
{
int V_196 = ( unsigned long ) V_599 ;
if ( V_598 == V_600 || V_598 == V_601 ) {
F_555 ( V_196 ) ;
F_242 ( V_196 ) ;
F_556 ( V_196 ) ;
F_557 ( V_196 ) ;
}
return V_602 ;
}
void T_4 F_558 ( void )
{
F_559 ( F_554 , 0 ) ;
}
static void F_560 ( void )
{
struct V_491 * V_9 ;
unsigned long V_603 = 0 ;
enum V_395 V_60 , V_450 ;
F_561 (pgdat) {
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_60 ;
long F_16 = 0 ;
for ( V_450 = V_60 ; V_450 < V_116 ; V_450 ++ ) {
if ( V_40 -> V_252 [ V_450 ] > F_16 )
F_16 = V_40 -> V_252 [ V_450 ] ;
}
F_16 += F_304 ( V_40 ) ;
if ( F_16 > V_40 -> V_123 )
F_16 = V_40 -> V_123 ;
V_40 -> V_379 = F_16 ;
V_603 += F_16 ;
}
}
V_379 = V_603 ;
}
static void F_562 ( void )
{
struct V_491 * V_9 ;
enum V_395 V_450 , V_604 ;
F_561 (pgdat) {
for ( V_450 = 0 ; V_450 < V_116 ; V_450 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_450 ;
unsigned long V_123 = V_40 -> V_123 ;
V_40 -> V_252 [ V_450 ] = 0 ;
V_604 = V_450 ;
while ( V_604 ) {
struct V_40 * V_605 ;
V_604 -- ;
if ( V_606 [ V_604 ] < 1 )
V_606 [ V_604 ] = 1 ;
V_605 = V_9 -> V_117 + V_604 ;
V_605 -> V_252 [ V_450 ] = V_123 /
V_606 [ V_604 ] ;
V_123 += V_605 -> V_123 ;
}
}
}
F_560 () ;
}
static void F_563 ( void )
{
unsigned long V_607 = V_608 >> ( V_17 - 10 ) ;
unsigned long V_609 = 0 ;
struct V_40 * V_40 ;
unsigned long V_34 ;
F_399 (zone) {
if ( ! F_406 ( V_40 ) )
V_609 += V_40 -> V_123 ;
}
F_399 (zone) {
V_546 V_400 ;
F_228 ( & V_40 -> V_109 , V_34 ) ;
V_400 = ( V_546 ) V_607 * V_40 -> V_123 ;
F_564 ( V_400 , V_609 ) ;
if ( F_406 ( V_40 ) ) {
unsigned long V_610 ;
V_610 = V_40 -> V_123 / 1024 ;
V_610 = F_497 ( V_610 , V_611 , 128UL ) ;
V_40 -> V_208 [ V_612 ] = V_610 ;
} else {
V_40 -> V_208 [ V_612 ] = V_400 ;
}
V_400 = F_565 ( V_546 , V_400 >> 2 ,
F_566 ( V_40 -> V_123 ,
V_613 , 10000 ) ) ;
V_40 -> V_208 [ V_378 ] = F_333 ( V_40 ) + V_400 ;
V_40 -> V_208 [ V_614 ] = F_333 ( V_40 ) + V_400 * 2 ;
F_135 ( V_40 , V_223 ,
F_304 ( V_40 ) - F_269 ( V_40 ) -
F_279 ( & V_40 -> V_226 [ V_223 ] ) ) ;
F_230 ( & V_40 -> V_109 , V_34 ) ;
}
F_560 () ;
}
void F_567 ( void )
{
F_425 ( & V_440 ) ;
F_563 () ;
F_324 ( & V_440 ) ;
}
int T_2 F_568 ( void )
{
unsigned long V_615 ;
int V_616 ;
V_615 = F_393 () * ( V_102 >> 10 ) ;
V_616 = F_569 ( V_615 * 16 ) ;
if ( V_616 > V_617 ) {
V_608 = V_616 ;
if ( V_608 < 128 )
V_608 = 128 ;
if ( V_608 > 65536 )
V_608 = 65536 ;
} else {
F_318 ( L_106 ,
V_616 , V_617 ) ;
}
F_567 () ;
F_570 () ;
F_562 () ;
return 0 ;
}
int F_571 ( struct V_431 * V_432 , int V_433 ,
void T_12 * V_434 , T_11 * V_435 , T_13 * V_436 )
{
int V_618 ;
V_618 = F_572 ( V_432 , V_433 , V_434 , V_435 , V_436 ) ;
if ( V_618 )
return V_618 ;
if ( V_433 ) {
V_617 = V_608 ;
F_567 () ;
}
return 0 ;
}
int F_573 ( struct V_431 * V_432 , int V_433 ,
void T_12 * V_434 , T_11 * V_435 , T_13 * V_436 )
{
int V_618 ;
V_618 = F_572 ( V_432 , V_433 , V_434 , V_435 , V_436 ) ;
if ( V_618 )
return V_618 ;
if ( V_433 )
F_567 () ;
return 0 ;
}
int F_574 ( struct V_431 * V_432 , int V_433 ,
void T_12 * V_434 , T_11 * V_435 , T_13 * V_436 )
{
struct V_40 * V_40 ;
int V_618 ;
V_618 = F_572 ( V_432 , V_433 , V_434 , V_435 , V_436 ) ;
if ( V_618 )
return V_618 ;
F_399 (zone)
V_40 -> V_536 = ( V_40 -> V_123 *
V_537 ) / 100 ;
return 0 ;
}
int F_575 ( struct V_431 * V_432 , int V_433 ,
void T_12 * V_434 , T_11 * V_435 , T_13 * V_436 )
{
struct V_40 * V_40 ;
int V_618 ;
V_618 = F_572 ( V_432 , V_433 , V_434 , V_435 , V_436 ) ;
if ( V_618 )
return V_618 ;
F_399 (zone)
V_40 -> V_538 = ( V_40 -> V_123 *
V_539 ) / 100 ;
return 0 ;
}
int F_576 ( struct V_431 * V_432 , int V_433 ,
void T_12 * V_434 , T_11 * V_435 , T_13 * V_436 )
{
F_572 ( V_432 , V_433 , V_434 , V_435 , V_436 ) ;
F_562 () ;
return 0 ;
}
int F_577 ( struct V_431 * V_432 , int V_433 ,
void T_12 * V_434 , T_11 * V_435 , T_13 * V_436 )
{
struct V_40 * V_40 ;
int V_619 ;
int V_41 ;
F_425 ( & V_620 ) ;
V_619 = V_485 ;
V_41 = F_572 ( V_432 , V_433 , V_434 , V_435 , V_436 ) ;
if ( ! V_433 || V_41 < 0 )
goto V_53;
if ( V_485 &&
V_485 < V_621 ) {
V_485 = V_619 ;
V_41 = - V_67 ;
goto V_53;
}
if ( V_485 == V_619 )
goto V_53;
F_195 (zone) {
unsigned int V_196 ;
F_440 (cpu)
F_474 ( V_40 ,
F_241 ( V_40 -> V_199 , V_196 ) ) ;
}
V_53:
F_324 ( & V_620 ) ;
return V_41 ;
}
static int T_4 F_578 ( char * V_229 )
{
if ( ! V_229 )
return 0 ;
V_622 = F_579 ( V_229 , & V_229 , 0 ) ;
return 1 ;
}
void * T_4 F_580 ( const char * V_623 ,
unsigned long V_624 ,
unsigned long V_625 ,
int V_626 ,
int V_34 ,
unsigned int * V_627 ,
unsigned int * V_628 ,
unsigned long V_629 ,
unsigned long V_630 )
{
unsigned long long F_16 = V_630 ;
unsigned long V_631 , V_156 ;
void * V_432 = NULL ;
if ( ! V_625 ) {
V_625 = V_534 ;
if ( V_17 < 20 )
V_625 = F_581 ( V_625 , ( 1 << 20 ) / V_102 ) ;
if ( V_626 > V_17 )
V_625 >>= ( V_626 - V_17 ) ;
else
V_625 <<= ( V_17 - V_626 ) ;
if ( F_33 ( V_34 & V_632 ) ) {
F_4 ( ! ( V_34 & V_633 ) ) ;
if ( ! ( V_625 >> * V_627 ) ) {
V_625 = 1UL << * V_627 ;
F_183 ( ! V_625 ) ;
}
} else if ( F_33 ( ( V_625 * V_624 ) < V_102 ) )
V_625 = V_102 / V_624 ;
}
V_625 = F_582 ( V_625 ) ;
if ( F_16 == 0 ) {
F_16 = ( ( unsigned long long ) V_535 << V_17 ) >> 4 ;
F_564 ( F_16 , V_624 ) ;
}
F_16 = F_173 ( F_16 , 0x80000000ULL ) ;
if ( V_625 < V_629 )
V_625 = V_629 ;
if ( V_625 > F_16 )
V_625 = F_16 ;
V_631 = F_583 ( V_625 ) ;
do {
V_156 = V_624 << V_631 ;
if ( V_34 & V_633 )
V_432 = F_584 ( V_156 , 0 ) ;
else if ( V_622 )
V_432 = F_585 ( V_156 , V_634 , V_635 ) ;
else {
if ( F_388 ( V_156 ) < V_71 ) {
V_432 = F_387 ( V_156 , V_634 ) ;
F_586 ( V_432 , V_156 , 1 , V_634 ) ;
}
}
} while ( ! V_432 && V_156 > V_102 && -- V_631 );
if ( ! V_432 )
F_587 ( L_107 , V_623 ) ;
F_71 ( L_108 ,
V_623 , 1UL << V_631 , F_583 ( V_156 ) - V_17 , V_156 ) ;
if ( V_627 )
* V_627 = V_631 ;
if ( V_628 )
* V_628 = ( 1 << V_631 ) - 1 ;
return V_432 ;
}
bool F_588 ( struct V_40 * V_40 , struct V_1 * V_1 , int V_103 ,
bool V_636 )
{
unsigned long V_12 , V_637 , V_638 ;
int V_114 ;
if ( V_422 ( V_40 ) == V_484 )
return false ;
V_114 = F_100 ( V_1 ) ;
if ( V_114 == V_136 || F_229 ( V_114 ) )
return false ;
V_12 = F_36 ( V_1 ) ;
for ( V_638 = 0 , V_637 = 0 ; V_637 < V_24 ; V_637 ++ ) {
unsigned long V_639 = V_12 + V_637 ;
if ( ! F_42 ( V_639 ) )
continue;
V_1 = F_149 ( V_639 ) ;
if ( F_589 ( V_1 ) ) {
V_637 = F_581 ( V_637 + 1 , 1 << F_55 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_105 ( V_1 ) ) {
if ( F_91 ( V_1 ) )
V_637 += ( 1 << F_88 ( V_1 ) ) - 1 ;
continue;
}
if ( V_636 && F_590 ( V_1 ) )
continue;
if ( ! F_591 ( V_1 ) )
V_638 ++ ;
if ( V_638 > V_103 )
return true ;
}
return false ;
}
bool F_592 ( struct V_1 * V_1 )
{
struct V_40 * V_40 ;
unsigned long V_12 ;
if ( ! F_11 ( F_220 ( V_1 ) ) )
return false ;
V_40 = F_20 ( V_1 ) ;
V_12 = F_36 ( V_1 ) ;
if ( ! F_29 ( V_40 , V_12 ) )
return false ;
return ! F_588 ( V_40 , V_1 , 0 , true ) ;
}
static unsigned long F_593 ( unsigned long V_12 )
{
return V_12 & ~ ( F_565 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_594 ( unsigned long V_12 )
{
return F_172 ( V_12 , F_565 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_595 ( struct V_640 * V_641 ,
unsigned long V_118 , unsigned long V_119 )
{
unsigned long V_642 ;
unsigned long V_12 = V_118 ;
unsigned int V_643 = 0 ;
int V_41 = 0 ;
F_596 () ;
while ( V_12 < V_119 || ! F_136 ( & V_641 -> V_644 ) ) {
if ( F_597 ( V_55 ) ) {
V_41 = - V_645 ;
break;
}
if ( F_136 ( & V_641 -> V_644 ) ) {
V_641 -> V_646 = 0 ;
V_12 = F_598 ( V_641 , V_12 , V_119 ) ;
if ( ! V_12 ) {
V_41 = - V_645 ;
break;
}
V_643 = 0 ;
} else if ( ++ V_643 == 5 ) {
V_41 = V_41 < 0 ? V_41 : - V_647 ;
break;
}
V_642 = F_599 ( V_641 -> V_40 ,
& V_641 -> V_644 ) ;
V_641 -> V_646 -= V_642 ;
V_41 = F_600 ( & V_641 -> V_644 , V_648 ,
NULL , 0 , V_641 -> V_237 , V_649 ) ;
}
if ( V_41 < 0 ) {
F_601 ( & V_641 -> V_644 ) ;
return V_41 ;
}
return 0 ;
}
int F_602 ( unsigned long V_118 , unsigned long V_119 ,
unsigned V_3 )
{
unsigned long V_650 , V_651 ;
unsigned int V_59 ;
int V_41 = 0 ;
struct V_640 V_641 = {
. V_646 = 0 ,
. V_59 = - 1 ,
. V_40 = F_20 ( F_149 ( V_118 ) ) ,
. V_237 = V_652 ,
. V_653 = true ,
} ;
F_76 ( & V_641 . V_644 ) ;
V_41 = F_603 ( F_593 ( V_118 ) ,
F_594 ( V_119 ) , V_3 ,
false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_595 ( & V_641 , V_118 , V_119 ) ;
if ( V_41 && V_41 != - V_647 )
goto V_654;
F_604 () ;
F_245 ( V_641 . V_40 ) ;
V_59 = 0 ;
V_650 = V_118 ;
while ( ! F_91 ( F_149 ( V_650 ) ) ) {
if ( ++ V_59 >= V_71 ) {
V_650 = V_118 ;
break;
}
V_650 &= ~ 0UL << V_59 ;
}
if ( V_650 != V_118 ) {
V_59 = F_88 ( F_149 ( V_650 ) ) ;
if ( V_650 + ( 1UL << V_59 ) <= V_118 )
V_650 = V_118 ;
}
if ( F_605 ( V_650 , V_119 , false ) ) {
F_71 ( L_109 ,
V_655 , V_650 , V_119 ) ;
V_41 = - V_647 ;
goto V_654;
}
V_651 = F_606 ( & V_641 , V_650 , V_119 ) ;
if ( ! V_651 ) {
V_41 = - V_647 ;
goto V_654;
}
if ( V_118 != V_650 )
F_607 ( V_650 , V_118 - V_650 ) ;
if ( V_119 != V_651 )
F_607 ( V_119 , V_651 - V_119 ) ;
V_654:
F_608 ( F_593 ( V_118 ) ,
F_594 ( V_119 ) , V_3 ) ;
return V_41 ;
}
void F_607 ( unsigned long V_12 , unsigned V_61 )
{
unsigned int V_103 = 0 ;
for (; V_61 -- ; V_12 ++ ) {
struct V_1 * V_1 = F_149 ( V_12 ) ;
V_103 += F_90 ( V_1 ) != 1 ;
F_609 ( V_1 ) ;
}
F_610 ( V_103 != 0 , L_110 , V_103 ) ;
}
void T_2 F_611 ( struct V_40 * V_40 )
{
unsigned V_196 ;
F_425 ( & V_620 ) ;
F_440 (cpu)
F_474 ( V_40 ,
F_241 ( V_40 -> V_199 , V_196 ) ) ;
F_324 ( & V_620 ) ;
}
void F_612 ( struct V_40 * V_40 )
{
unsigned long V_34 ;
int V_196 ;
struct V_197 * V_198 ;
F_157 ( V_34 ) ;
if ( V_40 -> V_199 != & V_463 ) {
F_246 (cpu) {
V_198 = F_241 ( V_40 -> V_199 , V_196 ) ;
F_613 ( V_40 , V_198 ) ;
}
F_614 ( V_40 -> V_199 ) ;
V_40 -> V_199 = & V_463 ;
}
F_159 ( V_34 ) ;
}
void
F_615 ( unsigned long V_44 , unsigned long V_120 )
{
struct V_1 * V_1 ;
struct V_40 * V_40 ;
unsigned int V_59 , V_60 ;
unsigned long V_12 ;
unsigned long V_34 ;
for ( V_12 = V_44 ; V_12 < V_120 ; V_12 ++ )
if ( F_155 ( V_12 ) )
break;
if ( V_12 == V_120 )
return;
V_40 = F_20 ( F_149 ( V_12 ) ) ;
F_228 ( & V_40 -> V_109 , V_34 ) ;
V_12 = V_44 ;
while ( V_12 < V_120 ) {
if ( ! F_155 ( V_12 ) ) {
V_12 ++ ;
continue;
}
V_1 = F_149 ( V_12 ) ;
if ( F_33 ( ! F_91 ( V_1 ) && F_590 ( V_1 ) ) ) {
V_12 ++ ;
F_156 ( V_1 ) ;
continue;
}
F_183 ( F_90 ( V_1 ) ) ;
F_183 ( ! F_91 ( V_1 ) ) ;
V_59 = F_88 ( V_1 ) ;
#ifdef V_98
F_71 ( L_111 ,
V_12 , 1 << V_59 , V_120 ) ;
#endif
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_156 ( ( V_1 + V_60 ) ) ;
V_12 += ( 1 << V_59 ) ;
}
F_230 ( & V_40 -> V_109 , V_34 ) ;
}
bool F_616 ( struct V_1 * V_1 )
{
struct V_40 * V_40 = F_20 ( V_1 ) ;
unsigned long V_12 = F_36 ( V_1 ) ;
unsigned long V_34 ;
unsigned int V_59 ;
F_228 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_1 * V_656 = V_1 - ( V_12 & ( ( 1 << V_59 ) - 1 ) ) ;
if ( F_91 ( V_656 ) && F_88 ( V_656 ) >= V_59 )
break;
}
F_230 ( & V_40 -> V_109 , V_34 ) ;
return V_59 < V_71 ;
}
