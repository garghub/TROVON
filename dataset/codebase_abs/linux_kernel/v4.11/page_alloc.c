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
static inline bool F_13 ( T_1 * V_9 ,
unsigned long V_12 , unsigned long V_14 ,
unsigned long * V_15 )
{
unsigned long V_16 ;
if ( V_14 < F_14 ( V_9 ) )
return true ;
V_16 = F_15 ( 2UL << ( 30 - V_17 ) ,
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
static inline bool F_13 ( T_1 * V_9 ,
unsigned long V_12 , unsigned long V_14 ,
unsigned long * V_15 )
{
return true ;
}
static inline unsigned long * F_16 ( struct V_1 * V_1 ,
unsigned long V_12 )
{
#ifdef F_17
return F_18 ( V_12 ) -> V_20 ;
#else
return F_19 ( V_1 ) -> V_20 ;
#endif
}
static inline int F_20 ( struct V_1 * V_1 , unsigned long V_12 )
{
#ifdef F_17
V_12 &= ( V_19 - 1 ) ;
return ( V_12 >> V_21 ) * V_22 ;
#else
V_12 = V_12 - F_21 ( F_19 ( V_1 ) -> V_23 , V_24 ) ;
return ( V_12 >> V_21 ) * V_22 ;
#endif
}
static T_3 unsigned long F_22 ( struct V_1 * V_1 ,
unsigned long V_12 ,
unsigned long V_25 ,
unsigned long V_26 )
{
unsigned long * V_27 ;
unsigned long V_28 , V_29 ;
unsigned long V_30 ;
V_27 = F_16 ( V_1 , V_12 ) ;
V_28 = F_20 ( V_1 , V_12 ) ;
V_29 = V_28 / V_31 ;
V_28 &= ( V_31 - 1 ) ;
V_30 = V_27 [ V_29 ] ;
V_28 += V_25 ;
return ( V_30 >> ( V_31 - V_28 - 1 ) ) & V_26 ;
}
unsigned long F_23 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_25 ,
unsigned long V_26 )
{
return F_22 ( V_1 , V_12 , V_25 , V_26 ) ;
}
static T_3 int F_24 ( struct V_1 * V_1 , unsigned long V_12 )
{
return F_22 ( V_1 , V_12 , V_32 , V_33 ) ;
}
void F_25 ( struct V_1 * V_1 , unsigned long V_34 ,
unsigned long V_12 ,
unsigned long V_25 ,
unsigned long V_26 )
{
unsigned long * V_27 ;
unsigned long V_28 , V_29 ;
unsigned long V_35 , V_30 ;
F_26 ( V_22 != 4 ) ;
V_27 = F_16 ( V_1 , V_12 ) ;
V_28 = F_20 ( V_1 , V_12 ) ;
V_29 = V_28 / V_31 ;
V_28 &= ( V_31 - 1 ) ;
F_27 ( ! F_28 ( F_19 ( V_1 ) , V_12 ) , V_1 ) ;
V_28 += V_25 ;
V_26 <<= ( V_31 - V_28 - 1 ) ;
V_34 <<= ( V_31 - V_28 - 1 ) ;
V_30 = F_29 ( V_27 [ V_29 ] ) ;
for (; ; ) {
V_35 = F_30 ( & V_27 [ V_29 ] , V_30 , ( V_30 & ~ V_26 ) | V_34 ) ;
if ( V_30 == V_35 )
break;
V_30 = V_35 ;
}
}
void F_31 ( struct V_1 * V_1 , int V_3 )
{
if ( F_32 ( V_36 &&
V_3 < V_37 ) )
V_3 = V_38 ;
F_33 ( V_1 , ( unsigned long ) V_3 ,
V_39 , V_32 ) ;
}
static int F_34 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
int V_41 = 0 ;
unsigned V_42 ;
unsigned long V_12 = F_35 ( V_1 ) ;
unsigned long V_43 , V_44 ;
do {
V_42 = F_36 ( V_40 ) ;
V_44 = V_40 -> V_23 ;
V_43 = V_40 -> V_45 ;
if ( ! F_28 ( V_40 , V_12 ) )
V_41 = 1 ;
} while ( F_37 ( V_40 , V_42 ) );
if ( V_41 )
F_38 ( L_1 ,
V_12 , F_39 ( V_40 ) , V_40 -> V_46 ,
V_44 , V_44 + V_43 ) ;
return V_41 ;
}
static int F_40 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
if ( ! F_41 ( F_35 ( V_1 ) ) )
return 0 ;
if ( V_40 != F_19 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_42 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
if ( F_34 ( V_40 , V_1 ) )
return 1 ;
if ( ! F_40 ( V_40 , V_1 ) )
return 1 ;
return 0 ;
}
static inline int F_42 ( struct V_40 * V_40 , struct V_1 * V_1 )
{
return 0 ;
}
static void F_43 ( struct V_1 * V_1 , const char * V_47 ,
unsigned long V_48 )
{
static unsigned long V_49 ;
static unsigned long V_50 ;
static unsigned long V_51 ;
if ( V_50 == 60 ) {
if ( F_44 ( V_52 , V_49 ) ) {
V_51 ++ ;
goto V_53;
}
if ( V_51 ) {
F_45 (
L_2 ,
V_51 ) ;
V_51 = 0 ;
}
V_50 = 0 ;
}
if ( V_50 ++ == 0 )
V_49 = V_52 + 60 * V_54 ;
F_45 ( L_3 ,
V_55 -> V_56 , F_35 ( V_1 ) ) ;
F_46 ( V_1 , V_47 ) ;
V_48 &= V_1 -> V_34 ;
if ( V_48 )
F_45 ( L_4 ,
V_48 , & V_48 ) ;
F_47 ( V_1 ) ;
F_48 () ;
F_49 () ;
V_53:
F_50 ( V_1 ) ;
F_51 ( V_57 , V_58 ) ;
}
void F_52 ( struct V_1 * V_1 )
{
F_53 ( V_1 , F_54 ( V_1 ) ) ;
}
void F_55 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
int V_61 = 1 << V_59 ;
F_56 ( V_1 , V_62 ) ;
F_57 ( V_1 , V_59 ) ;
F_58 ( V_1 ) ;
for ( V_60 = 1 ; V_60 < V_61 ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
F_59 ( V_63 , 0 ) ;
V_63 -> V_64 = V_65 ;
F_60 ( V_63 , V_1 ) ;
}
F_61 ( F_62 ( V_1 ) , - 1 ) ;
}
static int T_4 F_63 ( char * V_66 )
{
if ( ! V_66 )
return - V_67 ;
return F_64 ( V_66 , & V_68 ) ;
}
static bool F_65 ( void )
{
if ( ! F_66 () )
return false ;
if ( ! F_67 () )
return false ;
return true ;
}
static void F_68 ( void )
{
if ( ! F_66 () )
return;
if ( ! F_67 () )
return;
V_69 = true ;
}
static int T_4 F_69 ( char * V_66 )
{
unsigned long V_70 ;
if ( F_70 ( V_66 , 10 , & V_70 ) < 0 || V_70 > V_71 / 2 ) {
F_38 ( L_5 ) ;
return 0 ;
}
V_72 = V_70 ;
F_71 ( L_6 , V_70 ) ;
return 0 ;
}
static inline bool F_72 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 )
{
struct V_73 * V_73 ;
if ( ! F_73 () )
return false ;
if ( V_59 >= F_67 () )
return false ;
V_73 = F_74 ( V_1 ) ;
if ( F_32 ( ! V_73 ) )
return false ;
F_75 ( V_74 , & V_73 -> V_34 ) ;
F_76 ( & V_1 -> V_75 ) ;
F_77 ( V_1 , V_59 ) ;
F_78 ( V_40 , - ( 1 << V_59 ) , V_3 ) ;
return true ;
}
static inline void F_79 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 )
{
struct V_73 * V_73 ;
if ( ! F_73 () )
return;
V_73 = F_74 ( V_1 ) ;
if ( F_32 ( ! V_73 ) )
return;
F_80 ( V_74 , & V_73 -> V_34 ) ;
F_77 ( V_1 , 0 ) ;
if ( ! F_81 ( V_3 ) )
F_78 ( V_40 , ( 1 << V_59 ) , V_3 ) ;
}
static inline bool F_72 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 ) { return false ; }
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
if ( F_87 ( V_76 ) && F_88 ( V_76 ) == V_59 ) {
if ( F_89 ( V_1 ) != F_89 ( V_76 ) )
return 0 ;
F_27 ( F_90 ( V_76 ) != 0 , V_76 ) ;
return 1 ;
}
if ( F_91 ( V_76 ) && F_88 ( V_76 ) == V_59 ) {
if ( F_89 ( V_1 ) != F_89 ( V_76 ) )
return 0 ;
F_27 ( F_90 ( V_76 ) != 0 , V_76 ) ;
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
unsigned long V_78 ( V_79 ) ;
struct V_1 * V_76 ;
unsigned int V_80 ;
V_80 = F_93 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
F_94 ( ! F_95 ( V_40 ) ) ;
F_27 ( V_1 -> V_34 & V_81 , V_1 ) ;
F_94 ( V_3 == - 1 ) ;
if ( F_96 ( ! F_81 ( V_3 ) ) )
F_78 ( V_40 , 1 << V_59 , V_3 ) ;
F_27 ( V_12 & ( ( 1 << V_59 ) - 1 ) , V_1 ) ;
F_27 ( F_42 ( V_40 , V_1 ) , V_1 ) ;
V_82:
while ( V_59 < V_80 - 1 ) {
V_79 = F_97 ( V_12 , V_59 ) ;
V_76 = V_1 + ( V_79 - V_12 ) ;
if ( ! F_41 ( V_79 ) )
goto V_83;
if ( ! F_86 ( V_1 , V_76 , V_59 ) )
goto V_83;
if ( F_87 ( V_76 ) ) {
F_79 ( V_40 , V_76 , V_59 , V_3 ) ;
} else {
F_98 ( & V_76 -> V_75 ) ;
V_40 -> V_84 [ V_59 ] . V_85 -- ;
F_84 ( V_76 ) ;
}
V_77 = V_79 & V_12 ;
V_1 = V_1 + ( V_77 - V_12 ) ;
V_12 = V_77 ;
V_59 ++ ;
}
if ( V_80 < V_71 ) {
if ( F_32 ( F_99 ( V_40 ) ) ) {
int V_86 ;
V_79 = F_97 ( V_12 , V_59 ) ;
V_76 = V_1 + ( V_79 - V_12 ) ;
V_86 = F_100 ( V_76 ) ;
if ( V_3 != V_86
&& ( F_81 ( V_3 ) ||
F_81 ( V_86 ) ) )
goto V_83;
}
V_80 ++ ;
goto V_82;
}
V_83:
F_82 ( V_1 , V_59 ) ;
if ( ( V_59 < V_71 - 2 ) && F_41 ( V_79 ) ) {
struct V_1 * V_87 , * V_88 ;
V_77 = V_79 & V_12 ;
V_87 = V_1 + ( V_77 - V_12 ) ;
V_79 = F_97 ( V_77 , V_59 + 1 ) ;
V_88 = V_87 + ( V_79 - V_77 ) ;
if ( F_41 ( V_79 ) &&
F_86 ( V_87 , V_88 , V_59 + 1 ) ) {
F_101 ( & V_1 -> V_75 ,
& V_40 -> V_84 [ V_59 ] . V_89 [ V_3 ] ) ;
goto V_53;
}
}
F_102 ( & V_1 -> V_75 , & V_40 -> V_84 [ V_59 ] . V_89 [ V_3 ] ) ;
V_53:
V_40 -> V_84 [ V_59 ] . V_85 ++ ;
}
static inline bool F_103 ( struct V_1 * V_1 ,
unsigned long V_90 )
{
if ( F_32 ( F_104 ( & V_1 -> V_91 ) != - 1 ) )
return false ;
if ( F_32 ( ( unsigned long ) V_1 -> V_64 |
F_105 ( V_1 ) |
#ifdef F_106
( unsigned long ) V_1 -> V_92 |
#endif
( V_1 -> V_34 & V_90 ) ) )
return false ;
return true ;
}
static void F_107 ( struct V_1 * V_1 )
{
const char * V_93 ;
unsigned long V_48 ;
V_93 = NULL ;
V_48 = 0 ;
if ( F_32 ( F_104 ( & V_1 -> V_91 ) != - 1 ) )
V_93 = L_7 ;
if ( F_32 ( V_1 -> V_64 != NULL ) )
V_93 = L_8 ;
if ( F_32 ( F_105 ( V_1 ) != 0 ) )
V_93 = L_9 ;
if ( F_32 ( V_1 -> V_34 & V_94 ) ) {
V_93 = L_10 ;
V_48 = V_94 ;
}
#ifdef F_106
if ( F_32 ( V_1 -> V_92 ) )
V_93 = L_11 ;
#endif
F_43 ( V_1 , V_93 , V_48 ) ;
}
static inline int F_108 ( struct V_1 * V_1 )
{
if ( F_96 ( F_103 ( V_1 , V_94 ) ) )
return 0 ;
F_107 ( V_1 ) ;
return 1 ;
}
static int F_109 ( struct V_1 * V_95 , struct V_1 * V_1 )
{
int V_41 = 1 ;
F_26 ( ( unsigned long ) V_96 & 1 ) ;
if ( ! F_110 ( V_97 ) ) {
V_41 = 0 ;
goto V_53;
}
switch ( V_1 - V_95 ) {
case 1 :
if ( F_32 ( F_111 ( V_1 ) ) ) {
F_43 ( V_1 , L_12 , 0 ) ;
goto V_53;
}
break;
case 2 :
break;
default:
if ( V_1 -> V_64 != V_65 ) {
F_43 ( V_1 , L_13 , 0 ) ;
goto V_53;
}
break;
}
if ( F_32 ( ! F_112 ( V_1 ) ) ) {
F_43 ( V_1 , L_14 , 0 ) ;
goto V_53;
}
if ( F_32 ( F_113 ( V_1 ) != V_95 ) ) {
F_43 ( V_1 , L_15 , 0 ) ;
goto V_53;
}
V_41 = 0 ;
V_53:
V_1 -> V_64 = NULL ;
F_114 ( V_1 ) ;
return V_41 ;
}
static T_3 bool F_115 ( struct V_1 * V_1 ,
unsigned int V_59 , bool V_98 )
{
int V_99 = 0 ;
F_27 ( F_112 ( V_1 ) , V_1 ) ;
F_116 ( V_1 , V_59 ) ;
F_117 ( V_1 , V_59 ) ;
if ( F_32 ( V_59 ) ) {
bool V_100 = F_118 ( V_1 ) ;
int V_60 ;
F_27 ( V_100 && F_54 ( V_1 ) != V_59 , V_1 ) ;
if ( V_100 )
F_119 ( V_1 ) ;
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
if ( V_100 )
V_99 += F_109 ( V_1 , V_1 + V_60 ) ;
if ( F_32 ( F_108 ( V_1 + V_60 ) ) ) {
V_99 ++ ;
continue;
}
( V_1 + V_60 ) -> V_34 &= ~ V_81 ;
}
}
if ( F_120 ( V_1 ) )
V_1 -> V_64 = NULL ;
if ( F_121 () && F_122 ( V_1 ) )
F_123 ( V_1 , V_59 ) ;
if ( V_98 )
V_99 += F_108 ( V_1 ) ;
if ( V_99 )
return false ;
F_124 ( V_1 ) ;
V_1 -> V_34 &= ~ V_81 ;
F_125 ( V_1 , V_59 ) ;
if ( ! F_126 ( V_1 ) ) {
F_127 ( F_128 ( V_1 ) ,
V_101 << V_59 ) ;
F_129 ( F_128 ( V_1 ) ,
V_101 << V_59 ) ;
}
F_130 ( V_1 , V_59 ) ;
F_131 ( V_1 , 1 << V_59 , 0 ) ;
F_132 ( V_1 , 1 << V_59 , 0 ) ;
F_133 ( V_1 , V_59 ) ;
return true ;
}
static inline bool F_134 ( struct V_1 * V_1 )
{
return F_115 ( V_1 , 0 , true ) ;
}
static inline bool F_135 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_134 ( struct V_1 * V_1 )
{
return F_115 ( V_1 , 0 , false ) ;
}
static bool F_135 ( struct V_1 * V_1 )
{
return F_108 ( V_1 ) ;
}
static void F_136 ( struct V_40 * V_40 , int V_102 ,
struct V_103 * V_104 )
{
int V_3 = 0 ;
int V_105 = 0 ;
unsigned long V_106 ;
bool V_107 ;
F_137 ( & V_40 -> V_108 ) ;
V_107 = F_99 ( V_40 ) ;
V_106 = F_138 ( V_40 -> V_109 , V_110 ) ;
if ( V_106 )
F_139 ( V_40 -> V_109 , V_110 , - V_106 ) ;
while ( V_102 ) {
struct V_1 * V_1 ;
struct V_111 * V_112 ;
do {
V_105 ++ ;
if ( ++ V_3 == V_37 )
V_3 = 0 ;
V_112 = & V_104 -> V_113 [ V_3 ] ;
} while ( F_140 ( V_112 ) );
if ( V_105 == V_37 )
V_105 = V_102 ;
do {
int V_114 ;
V_1 = F_141 ( V_112 , struct V_1 , V_75 ) ;
F_98 ( & V_1 -> V_75 ) ;
V_114 = F_1 ( V_1 ) ;
F_27 ( F_81 ( V_114 ) , V_1 ) ;
if ( F_32 ( V_107 ) )
V_114 = F_100 ( V_1 ) ;
if ( F_135 ( V_1 ) )
continue;
F_92 ( V_1 , F_35 ( V_1 ) , V_40 , 0 , V_114 ) ;
F_142 ( V_1 , 0 , V_114 ) ;
} while ( -- V_102 && -- V_105 && ! F_140 ( V_112 ) );
}
F_143 ( & V_40 -> V_108 ) ;
}
static void F_144 ( struct V_40 * V_40 ,
struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_59 ,
int V_3 )
{
unsigned long V_106 ;
F_137 ( & V_40 -> V_108 ) ;
V_106 = F_138 ( V_40 -> V_109 , V_110 ) ;
if ( V_106 )
F_139 ( V_40 -> V_109 , V_110 , - V_106 ) ;
if ( F_32 ( F_99 ( V_40 ) ||
F_81 ( V_3 ) ) ) {
V_3 = F_24 ( V_1 , V_12 ) ;
}
F_92 ( V_1 , V_12 , V_40 , V_59 , V_3 ) ;
F_143 ( & V_40 -> V_108 ) ;
}
static void T_2 F_145 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_40 , int V_13 )
{
F_146 ( V_1 , V_40 , V_13 , V_12 ) ;
F_147 ( V_1 ) ;
F_50 ( V_1 ) ;
F_124 ( V_1 ) ;
F_76 ( & V_1 -> V_75 ) ;
#ifdef F_148
if ( ! F_149 ( V_40 ) )
F_150 ( V_1 , F_151 ( V_12 << V_17 ) ) ;
#endif
}
static void T_2 F_152 ( unsigned long V_12 , unsigned long V_40 ,
int V_13 )
{
return F_145 ( F_153 ( V_12 ) , V_12 , V_40 , V_13 ) ;
}
static void F_154 ( unsigned long V_12 )
{
T_1 * V_9 ;
int V_13 , V_115 ;
if ( ! F_9 ( V_12 ) )
return;
V_13 = F_10 ( V_12 ) ;
V_9 = F_12 ( V_13 ) ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
struct V_40 * V_40 = & V_9 -> V_117 [ V_115 ] ;
if ( V_12 >= V_40 -> V_23 && V_12 < F_155 ( V_40 ) )
break;
}
F_152 ( V_12 , V_115 , V_13 ) ;
}
static inline void F_154 ( unsigned long V_12 )
{
}
void T_2 F_156 ( T_5 V_118 , T_5 V_119 )
{
unsigned long V_44 = F_157 ( V_118 ) ;
unsigned long V_120 = F_158 ( V_119 ) ;
for (; V_44 < V_120 ; V_44 ++ ) {
if ( F_159 ( V_44 ) ) {
struct V_1 * V_1 = F_153 ( V_44 ) ;
F_154 ( V_44 ) ;
F_76 ( & V_1 -> V_75 ) ;
F_160 ( V_1 ) ;
}
}
}
static void F_53 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned long V_34 ;
int V_3 ;
unsigned long V_12 = F_35 ( V_1 ) ;
if ( ! F_115 ( V_1 , V_59 , true ) )
return;
V_3 = F_24 ( V_1 , V_12 ) ;
F_161 ( V_34 ) ;
F_162 ( V_121 , 1 << V_59 ) ;
F_144 ( F_19 ( V_1 ) , V_1 , V_12 , V_59 , V_3 ) ;
F_163 ( V_34 ) ;
}
static void T_4 F_164 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned int V_61 = 1 << V_59 ;
struct V_1 * V_63 = V_1 ;
unsigned int V_122 ;
F_165 ( V_63 ) ;
for ( V_122 = 0 ; V_122 < ( V_61 - 1 ) ; V_122 ++ , V_63 ++ ) {
F_165 ( V_63 + 1 ) ;
F_166 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
}
F_166 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
F_19 ( V_1 ) -> V_123 += V_61 ;
F_167 ( V_1 ) ;
F_168 ( V_1 , V_59 ) ;
}
int T_2 F_10 ( unsigned long V_12 )
{
static F_169 ( V_124 ) ;
int V_13 ;
F_137 ( & V_124 ) ;
V_13 = F_170 ( V_12 , & V_125 ) ;
if ( V_13 < 0 )
V_13 = V_126 ;
F_143 ( & V_124 ) ;
return V_13 ;
}
static inline bool T_2 F_171 ( unsigned long V_12 , int V_127 ,
struct V_128 * V_129 )
{
int V_13 ;
V_13 = F_170 ( V_12 , V_129 ) ;
if ( V_13 >= 0 && V_13 != V_127 )
return false ;
return true ;
}
static inline bool T_2 F_172 ( unsigned long V_12 , int V_127 )
{
return F_171 ( V_12 , V_127 , & V_125 ) ;
}
static inline bool T_2 F_172 ( unsigned long V_12 , int V_127 )
{
return true ;
}
static inline bool T_2 F_171 ( unsigned long V_12 , int V_127 ,
struct V_128 * V_129 )
{
return true ;
}
void T_4 F_173 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_59 )
{
if ( F_9 ( V_12 ) )
return;
return F_164 ( V_1 , V_59 ) ;
}
struct V_1 * F_174 ( unsigned long V_44 ,
unsigned long V_120 , struct V_40 * V_40 )
{
struct V_1 * V_130 ;
struct V_1 * V_131 ;
V_120 -- ;
if ( ! F_159 ( V_44 ) || ! F_159 ( V_120 ) )
return NULL ;
V_130 = F_153 ( V_44 ) ;
if ( F_19 ( V_130 ) != V_40 )
return NULL ;
V_131 = F_153 ( V_120 ) ;
if ( F_89 ( V_130 ) != F_89 ( V_131 ) )
return NULL ;
return V_130 ;
}
void F_175 ( struct V_40 * V_40 )
{
unsigned long V_132 = V_40 -> V_23 ;
unsigned long V_133 ;
V_133 = F_176 ( V_132 + 1 , V_24 ) ;
for (; V_132 < F_155 ( V_40 ) ;
V_132 = V_133 ,
V_133 += V_24 ) {
V_133 = F_177 ( V_133 , F_155 ( V_40 ) ) ;
if ( ! F_174 ( V_132 ,
V_133 , V_40 ) )
return;
}
V_40 -> V_134 = true ;
}
void F_178 ( struct V_40 * V_40 )
{
V_40 -> V_134 = false ;
}
static void T_4 F_179 ( struct V_1 * V_1 ,
unsigned long V_12 , int V_61 )
{
int V_60 ;
if ( ! V_1 )
return;
if ( V_61 == V_24 &&
( V_12 & ( V_24 - 1 ) ) == 0 ) {
F_31 ( V_1 , V_135 ) ;
F_164 ( V_1 , V_21 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ , V_1 ++ , V_12 ++ ) {
if ( ( V_12 & ( V_24 - 1 ) ) == 0 )
F_31 ( V_1 , V_135 ) ;
F_164 ( V_1 , 0 ) ;
}
}
static inline void T_4 F_180 ( void )
{
if ( F_181 ( & V_136 ) )
F_182 ( & V_137 ) ;
}
static int T_4 F_183 ( void * V_138 )
{
T_1 * V_9 = V_138 ;
int V_13 = V_9 -> V_139 ;
struct V_128 V_140 = { } ;
unsigned long V_118 = V_52 ;
unsigned long V_61 = 0 ;
unsigned long V_141 , V_142 ;
int V_60 , V_115 ;
struct V_40 * V_40 ;
unsigned long V_143 = V_9 -> V_10 ;
const struct V_144 * V_144 = F_184 ( V_9 -> V_139 ) ;
if ( V_143 == V_11 ) {
F_180 () ;
return 0 ;
}
if ( ! F_185 ( V_144 ) )
F_186 ( V_55 , V_144 ) ;
F_187 ( V_9 -> V_10 < V_9 -> V_145 ) ;
F_187 ( V_9 -> V_10 > F_14 ( V_9 ) ) ;
V_9 -> V_10 = V_11 ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
V_40 = V_9 -> V_117 + V_115 ;
if ( V_143 < F_155 ( V_40 ) )
break;
}
F_188 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_12 , V_120 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_146 = NULL ;
unsigned long V_147 = 0 ;
int V_148 = 0 ;
V_120 = F_177 ( V_142 , F_155 ( V_40 ) ) ;
V_12 = V_143 ;
if ( V_12 < V_141 )
V_12 = V_141 ;
if ( V_12 < V_40 -> V_23 )
V_12 = V_40 -> V_23 ;
for (; V_12 < V_120 ; V_12 ++ ) {
if ( ! F_41 ( V_12 ) )
goto V_149;
if ( ( V_12 & ( V_24 - 1 ) ) == 0 ) {
if ( ! F_159 ( V_12 ) ) {
V_1 = NULL ;
goto V_149;
}
}
if ( ! F_171 ( V_12 , V_13 , & V_140 ) ) {
V_1 = NULL ;
goto V_149;
}
if ( V_1 && ( V_12 & ( V_24 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_61 += V_148 ;
F_179 ( V_146 ,
V_147 , V_148 ) ;
V_146 = NULL ;
V_147 = V_148 = 0 ;
V_1 = F_153 ( V_12 ) ;
F_189 () ;
}
if ( V_1 -> V_34 ) {
F_94 ( F_19 ( V_1 ) != V_40 ) ;
goto V_149;
}
F_145 ( V_1 , V_12 , V_115 , V_13 ) ;
if ( ! V_146 ) {
V_146 = V_1 ;
V_147 = V_12 ;
V_148 = 0 ;
}
V_148 ++ ;
continue;
V_149:
V_61 += V_148 ;
F_179 ( V_146 , V_147 ,
V_148 ) ;
V_146 = NULL ;
V_147 = V_148 = 0 ;
}
V_61 += V_148 ;
F_179 ( V_146 , V_147 , V_148 ) ;
V_143 = F_15 ( V_120 , V_143 ) ;
}
F_4 ( ++ V_115 < V_116 && F_190 ( ++ V_40 ) ) ;
F_71 ( L_16 , V_13 , V_61 ,
F_191 ( V_52 - V_118 ) ) ;
F_180 () ;
return 0 ;
}
void T_4 F_192 ( void )
{
struct V_40 * V_40 ;
#ifdef F_193
int V_13 ;
F_61 ( & V_136 , F_194 ( V_150 ) ) ;
F_195 (nid, N_MEMORY) {
F_196 ( F_183 , F_12 ( V_13 ) , L_17 , V_13 ) ;
}
F_197 ( & V_137 ) ;
F_198 () ;
#endif
F_199 (zone)
F_175 ( V_40 ) ;
}
void T_4 F_200 ( struct V_1 * V_1 )
{
unsigned V_60 = V_24 ;
struct V_1 * V_63 = V_1 ;
do {
F_166 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
} while ( ++ V_63 , -- V_60 );
F_31 ( V_1 , V_151 ) ;
if ( V_21 >= V_71 ) {
V_60 = V_24 ;
V_63 = V_1 ;
do {
F_167 ( V_63 ) ;
F_168 ( V_63 , V_71 - 1 ) ;
V_63 += V_152 ;
} while ( V_60 -= V_152 );
} else {
F_167 ( V_1 ) ;
F_168 ( V_1 , V_21 ) ;
}
F_201 ( V_1 , V_24 ) ;
}
static inline void F_202 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_153 , int V_154 , struct V_84 * V_155 ,
int V_3 )
{
unsigned long V_156 = 1 << V_154 ;
while ( V_154 > V_153 ) {
V_155 -- ;
V_154 -- ;
V_156 >>= 1 ;
F_27 ( F_42 ( V_40 , & V_1 [ V_156 ] ) , & V_1 [ V_156 ] ) ;
if ( F_72 ( V_40 , & V_1 [ V_156 ] , V_154 , V_3 ) )
continue;
F_102 ( & V_1 [ V_156 ] . V_75 , & V_155 -> V_89 [ V_3 ] ) ;
V_155 -> V_85 ++ ;
F_82 ( & V_1 [ V_156 ] , V_154 ) ;
}
}
static void F_203 ( struct V_1 * V_1 )
{
const char * V_93 = NULL ;
unsigned long V_48 = 0 ;
if ( F_32 ( F_104 ( & V_1 -> V_91 ) != - 1 ) )
V_93 = L_7 ;
if ( F_32 ( V_1 -> V_64 != NULL ) )
V_93 = L_8 ;
if ( F_32 ( F_105 ( V_1 ) != 0 ) )
V_93 = L_18 ;
if ( F_32 ( V_1 -> V_34 & V_157 ) ) {
V_93 = L_19 ;
V_48 = V_157 ;
F_50 ( V_1 ) ;
return;
}
if ( F_32 ( V_1 -> V_34 & V_81 ) ) {
V_93 = L_20 ;
V_48 = V_81 ;
}
#ifdef F_106
if ( F_32 ( V_1 -> V_92 ) )
V_93 = L_11 ;
#endif
F_43 ( V_1 , V_93 , V_48 ) ;
}
static inline int F_204 ( struct V_1 * V_1 )
{
if ( F_96 ( F_103 ( V_1 ,
V_81 | V_157 ) ) )
return 0 ;
F_203 ( V_1 ) ;
return 1 ;
}
static inline bool F_205 ( bool V_158 )
{
return F_110 ( V_159 ) &&
F_206 () && V_158 ;
}
static bool F_207 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_208 ( struct V_1 * V_1 )
{
return F_204 ( V_1 ) ;
}
static bool F_207 ( struct V_1 * V_1 )
{
return F_204 ( V_1 ) ;
}
static bool F_208 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_209 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
if ( F_32 ( F_204 ( V_63 ) ) )
return true ;
}
return false ;
}
inline void F_210 ( struct V_1 * V_1 , unsigned int V_59 ,
T_6 V_160 )
{
F_77 ( V_1 , 0 ) ;
F_167 ( V_1 ) ;
F_211 ( V_1 , V_59 ) ;
F_132 ( V_1 , 1 << V_59 , 1 ) ;
F_131 ( V_1 , 1 << V_59 , 1 ) ;
F_212 ( V_1 , V_59 ) ;
F_213 ( V_1 , V_59 , V_160 ) ;
}
static void F_214 ( struct V_1 * V_1 , unsigned int V_59 , T_6 V_160 ,
unsigned int V_161 )
{
int V_60 ;
bool V_158 = true ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
if ( V_158 )
V_158 &= F_215 ( V_63 ) ;
}
F_210 ( V_1 , V_59 , V_160 ) ;
if ( ! F_205 ( V_158 ) && ( V_160 & V_162 ) )
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_216 ( V_1 + V_60 ) ;
if ( V_59 && ( V_160 & V_163 ) )
F_55 ( V_1 , V_59 ) ;
if ( V_161 & V_164 )
F_217 ( V_1 ) ;
else
F_218 ( V_1 ) ;
}
static inline
struct V_1 * F_219 ( struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
unsigned int V_165 ;
struct V_84 * V_155 ;
struct V_1 * V_1 ;
for ( V_165 = V_59 ; V_165 < V_71 ; ++ V_165 ) {
V_155 = & ( V_40 -> V_84 [ V_165 ] ) ;
V_1 = F_220 ( & V_155 -> V_89 [ V_3 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
V_155 -> V_85 -- ;
F_202 ( V_40 , V_1 , V_59 , V_165 , V_155 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_221 ( struct V_40 * V_40 ,
unsigned int V_59 )
{
return F_219 ( V_40 , V_59 , V_151 ) ;
}
static inline struct V_1 * F_221 ( struct V_40 * V_40 ,
unsigned int V_59 ) { return NULL ; }
int F_222 ( struct V_40 * V_40 ,
struct V_1 * V_130 , struct V_1 * V_131 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned int V_59 ;
int V_166 = 0 ;
#ifndef F_223
F_94 ( F_19 ( V_130 ) != F_19 ( V_131 ) ) ;
#endif
for ( V_1 = V_130 ; V_1 <= V_131 ; ) {
if ( ! F_41 ( F_35 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
F_27 ( F_224 ( V_1 ) != F_39 ( V_40 ) , V_1 ) ;
if ( ! F_91 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_59 = F_88 ( V_1 ) ;
F_225 ( & V_1 -> V_75 ,
& V_40 -> V_84 [ V_59 ] . V_89 [ V_3 ] ) ;
V_1 += 1 << V_59 ;
V_166 += 1 << V_59 ;
}
return V_166 ;
}
int F_226 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_44 , V_120 ;
struct V_1 * V_130 , * V_131 ;
V_44 = F_35 ( V_1 ) ;
V_44 = V_44 & ~ ( V_24 - 1 ) ;
V_130 = F_153 ( V_44 ) ;
V_131 = V_130 + V_24 - 1 ;
V_120 = V_44 + V_24 - 1 ;
if ( ! F_28 ( V_40 , V_44 ) )
V_130 = V_1 ;
if ( ! F_28 ( V_40 , V_120 ) )
return 0 ;
return F_222 ( V_40 , V_130 , V_131 , V_3 ) ;
}
static void F_227 ( struct V_1 * V_167 ,
int V_168 , int V_3 )
{
int V_169 = 1 << ( V_168 - V_21 ) ;
while ( V_169 -- ) {
F_31 ( V_167 , V_3 ) ;
V_167 += V_24 ;
}
}
static bool F_228 ( unsigned int V_59 , int V_170 )
{
if ( V_59 >= V_21 )
return true ;
if ( V_59 >= V_21 / 2 ||
V_170 == V_171 ||
V_170 == V_38 ||
V_36 )
return true ;
return false ;
}
static void F_229 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_172 )
{
unsigned int V_165 = F_88 ( V_1 ) ;
int V_173 ;
if ( V_165 >= V_21 ) {
F_227 ( V_1 , V_165 , V_172 ) ;
return;
}
V_173 = F_226 ( V_40 , V_1 , V_172 ) ;
if ( V_173 >= ( 1 << ( V_21 - 1 ) ) ||
V_36 )
F_31 ( V_1 , V_172 ) ;
}
int F_230 ( struct V_84 * V_155 , unsigned int V_59 ,
int V_3 , bool V_174 , bool * V_175 )
{
int V_60 ;
int V_176 ;
if ( V_155 -> V_85 == 0 )
return - 1 ;
* V_175 = false ;
for ( V_60 = 0 ; ; V_60 ++ ) {
V_176 = V_177 [ V_3 ] [ V_60 ] ;
if ( V_176 == V_178 )
break;
if ( F_140 ( & V_155 -> V_89 [ V_176 ] ) )
continue;
if ( F_228 ( V_59 , V_3 ) )
* V_175 = true ;
if ( ! V_174 )
return V_176 ;
if ( * V_175 )
return V_176 ;
}
return - 1 ;
}
static void F_231 ( struct V_1 * V_1 , struct V_40 * V_40 ,
unsigned int V_179 )
{
int V_114 ;
unsigned long V_180 , V_34 ;
V_180 = ( V_40 -> V_123 / 100 ) + V_24 ;
if ( V_40 -> V_181 >= V_180 )
return;
F_232 ( & V_40 -> V_108 , V_34 ) ;
if ( V_40 -> V_181 >= V_180 )
goto V_182;
V_114 = F_100 ( V_1 ) ;
if ( V_114 != V_183 &&
! F_81 ( V_114 ) && ! F_233 ( V_114 ) ) {
V_40 -> V_181 += V_24 ;
F_31 ( V_1 , V_183 ) ;
F_226 ( V_40 , V_1 , V_183 ) ;
}
V_182:
F_234 ( & V_40 -> V_108 , V_34 ) ;
}
static bool F_235 ( const struct V_184 * V_185 ,
bool V_186 )
{
struct V_187 * V_187 = V_185 -> V_187 ;
unsigned long V_34 ;
struct V_188 * V_189 ;
struct V_40 * V_40 ;
struct V_1 * V_1 ;
int V_59 ;
bool V_41 ;
F_236 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( ! V_186 && V_40 -> V_181 <=
V_24 )
continue;
F_232 ( & V_40 -> V_108 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_84 * V_155 = & ( V_40 -> V_84 [ V_59 ] ) ;
V_1 = F_220 (
& V_155 -> V_89 [ V_183 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
if ( F_100 ( V_1 ) ==
V_183 ) {
V_40 -> V_181 -= F_177 (
V_24 ,
V_40 -> V_181 ) ;
}
F_31 ( V_1 , V_185 -> V_3 ) ;
V_41 = F_226 ( V_40 , V_1 , V_185 -> V_3 ) ;
if ( V_41 ) {
F_234 ( & V_40 -> V_108 , V_34 ) ;
return V_41 ;
}
}
F_234 ( & V_40 -> V_108 , V_34 ) ;
}
return false ;
}
static inline struct V_1 *
F_237 ( struct V_40 * V_40 , unsigned int V_59 , int V_190 )
{
struct V_84 * V_155 ;
unsigned int V_165 ;
struct V_1 * V_1 ;
int V_176 ;
bool V_175 ;
for ( V_165 = V_71 - 1 ;
V_165 >= V_59 && V_165 <= V_71 - 1 ;
-- V_165 ) {
V_155 = & ( V_40 -> V_84 [ V_165 ] ) ;
V_176 = F_230 ( V_155 , V_165 ,
V_190 , false , & V_175 ) ;
if ( V_176 == - 1 )
continue;
V_1 = F_238 ( & V_155 -> V_89 [ V_176 ] ,
struct V_1 , V_75 ) ;
if ( V_175 &&
F_100 ( V_1 ) != V_183 )
F_229 ( V_40 , V_1 , V_190 ) ;
V_155 -> V_85 -- ;
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
F_202 ( V_40 , V_1 , V_59 , V_165 , V_155 ,
V_190 ) ;
F_2 ( V_1 , V_190 ) ;
F_239 ( V_1 , V_59 , V_165 ,
V_190 , V_176 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_240 ( struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
struct V_1 * V_1 ;
V_1 = F_219 ( V_40 , V_59 , V_3 ) ;
if ( F_32 ( ! V_1 ) ) {
if ( V_3 == V_135 )
V_1 = F_221 ( V_40 , V_59 ) ;
if ( ! V_1 )
V_1 = F_237 ( V_40 , V_59 , V_3 ) ;
}
F_241 ( V_1 , V_59 , V_3 ) ;
return V_1 ;
}
static int F_242 ( struct V_40 * V_40 , unsigned int V_59 ,
unsigned long V_102 , struct V_111 * V_112 ,
int V_3 , bool V_191 )
{
int V_60 , V_192 = 0 ;
F_137 ( & V_40 -> V_108 ) ;
for ( V_60 = 0 ; V_60 < V_102 ; ++ V_60 ) {
struct V_1 * V_1 = F_240 ( V_40 , V_59 , V_3 ) ;
if ( F_32 ( V_1 == NULL ) )
break;
if ( F_32 ( F_207 ( V_1 ) ) )
continue;
if ( F_96 ( ! V_191 ) )
F_102 ( & V_1 -> V_75 , V_112 ) ;
else
F_101 ( & V_1 -> V_75 , V_112 ) ;
V_112 = & V_1 -> V_75 ;
V_192 ++ ;
if ( F_233 ( F_1 ( V_1 ) ) )
F_243 ( V_40 , V_193 ,
- ( 1 << V_59 ) ) ;
}
F_243 ( V_40 , V_194 , - ( V_60 << V_59 ) ) ;
F_143 ( & V_40 -> V_108 ) ;
return V_192 ;
}
void F_244 ( struct V_40 * V_40 , struct V_103 * V_104 )
{
unsigned long V_34 ;
int V_195 , V_196 ;
F_161 ( V_34 ) ;
V_196 = F_29 ( V_104 -> V_196 ) ;
V_195 = F_177 ( V_104 -> V_102 , V_196 ) ;
if ( V_195 > 0 ) {
F_136 ( V_40 , V_195 , V_104 ) ;
V_104 -> V_102 -= V_195 ;
}
F_163 ( V_34 ) ;
}
static void F_245 ( unsigned int V_197 , struct V_40 * V_40 )
{
unsigned long V_34 ;
struct V_198 * V_199 ;
struct V_103 * V_104 ;
F_161 ( V_34 ) ;
V_199 = F_246 ( V_40 -> V_200 , V_197 ) ;
V_104 = & V_199 -> V_104 ;
if ( V_104 -> V_102 ) {
F_136 ( V_40 , V_104 -> V_102 , V_104 ) ;
V_104 -> V_102 = 0 ;
}
F_163 ( V_34 ) ;
}
static void F_247 ( unsigned int V_197 )
{
struct V_40 * V_40 ;
F_199 (zone) {
F_245 ( V_197 , V_40 ) ;
}
}
void F_248 ( struct V_40 * V_40 )
{
int V_197 = F_249 () ;
if ( V_40 )
F_245 ( V_197 , V_40 ) ;
else
F_247 ( V_197 ) ;
}
static void F_250 ( struct V_201 * V_202 )
{
F_251 () ;
F_248 ( NULL ) ;
F_252 () ;
}
void F_253 ( struct V_40 * V_40 )
{
int V_197 ;
static T_7 V_203 ;
if ( F_254 ( ! V_204 ) )
return;
if ( V_55 -> V_34 & V_205 )
return;
if ( F_32 ( ! F_255 ( & V_206 ) ) ) {
if ( ! V_40 )
return;
F_256 ( & V_206 ) ;
}
F_257 (cpu) {
struct V_198 * V_104 ;
struct V_40 * V_189 ;
bool V_207 = false ;
if ( V_40 ) {
V_104 = F_246 ( V_40 -> V_200 , V_197 ) ;
if ( V_104 -> V_104 . V_102 )
V_207 = true ;
} else {
F_199 (z) {
V_104 = F_246 ( V_189 -> V_200 , V_197 ) ;
if ( V_104 -> V_104 . V_102 ) {
V_207 = true ;
break;
}
}
}
if ( V_207 )
F_258 ( V_197 , & V_203 ) ;
else
F_259 ( V_197 , & V_203 ) ;
}
F_260 (cpu, &cpus_with_pcps) {
struct V_201 * V_202 = F_246 ( & V_208 , V_197 ) ;
F_261 ( V_202 , F_250 ) ;
F_262 ( V_197 , V_204 , V_202 ) ;
}
F_260 (cpu, &cpus_with_pcps)
F_263 ( F_246 ( & V_208 , V_197 ) ) ;
F_264 ( & V_206 ) ;
}
void F_265 ( struct V_40 * V_40 )
{
unsigned long V_12 , V_209 ;
unsigned long V_34 ;
unsigned int V_59 , V_210 ;
struct V_1 * V_1 ;
if ( F_266 ( V_40 ) )
return;
F_232 ( & V_40 -> V_108 , V_34 ) ;
V_209 = F_155 ( V_40 ) ;
for ( V_12 = V_40 -> V_23 ; V_12 < V_209 ; V_12 ++ )
if ( F_159 ( V_12 ) ) {
V_1 = F_153 ( V_12 ) ;
if ( F_19 ( V_1 ) != V_40 )
continue;
if ( ! F_267 ( V_1 ) )
F_268 ( V_1 ) ;
}
F_269 (order, t) {
F_270 (page,
&zone->free_area[order].free_list[t], lru) {
unsigned long V_60 ;
V_12 = F_35 ( V_1 ) ;
for ( V_60 = 0 ; V_60 < ( 1UL << V_59 ) ; V_60 ++ )
F_271 ( F_153 ( V_12 + V_60 ) ) ;
}
}
F_234 ( & V_40 -> V_108 , V_34 ) ;
}
void F_272 ( struct V_1 * V_1 , bool V_191 )
{
struct V_40 * V_40 = F_19 ( V_1 ) ;
struct V_103 * V_104 ;
unsigned long V_34 ;
unsigned long V_12 = F_35 ( V_1 ) ;
int V_3 ;
if ( ! F_134 ( V_1 ) )
return;
V_3 = F_24 ( V_1 , V_12 ) ;
F_2 ( V_1 , V_3 ) ;
F_161 ( V_34 ) ;
F_273 ( V_121 ) ;
if ( V_3 >= V_37 ) {
if ( F_32 ( F_81 ( V_3 ) ) ) {
F_144 ( V_40 , V_1 , V_12 , 0 , V_3 ) ;
goto V_53;
}
V_3 = V_135 ;
}
V_104 = & F_274 ( V_40 -> V_200 ) -> V_104 ;
if ( ! V_191 )
F_102 ( & V_1 -> V_75 , & V_104 -> V_113 [ V_3 ] ) ;
else
F_101 ( & V_1 -> V_75 , & V_104 -> V_113 [ V_3 ] ) ;
V_104 -> V_102 ++ ;
if ( V_104 -> V_102 >= V_104 -> V_154 ) {
unsigned long V_196 = F_29 ( V_104 -> V_196 ) ;
F_136 ( V_40 , V_196 , V_104 ) ;
V_104 -> V_102 -= V_196 ;
}
V_53:
F_163 ( V_34 ) ;
}
void F_275 ( struct V_111 * V_112 , bool V_191 )
{
struct V_1 * V_1 , * V_211 ;
F_276 (page, next, list, lru) {
F_277 ( V_1 , V_191 ) ;
F_272 ( V_1 , V_191 ) ;
}
}
void F_278 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
F_27 ( F_118 ( V_1 ) , V_1 ) ;
F_27 ( ! F_90 ( V_1 ) , V_1 ) ;
#ifdef F_279
if ( F_280 ( V_1 ) )
F_278 ( F_281 ( V_1 [ 0 ] . V_212 ) , V_59 ) ;
#endif
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_167 ( V_1 + V_60 ) ;
F_282 ( V_1 , V_59 ) ;
}
int F_283 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned long V_213 ;
struct V_40 * V_40 ;
int V_114 ;
F_187 ( ! F_91 ( V_1 ) ) ;
V_40 = F_19 ( V_1 ) ;
V_114 = F_100 ( V_1 ) ;
if ( ! F_81 ( V_114 ) ) {
V_213 = F_284 ( V_40 ) + ( 1UL << V_59 ) ;
if ( ! F_285 ( V_40 , 0 , V_213 , 0 , V_214 ) )
return 0 ;
F_78 ( V_40 , - ( 1UL << V_59 ) , V_114 ) ;
}
F_98 ( & V_1 -> V_75 ) ;
V_40 -> V_84 [ V_59 ] . V_85 -- ;
F_84 ( V_1 ) ;
if ( V_59 >= V_21 - 1 ) {
struct V_1 * V_215 = V_1 + ( 1 << V_59 ) - 1 ;
for (; V_1 < V_215 ; V_1 += V_24 ) {
int V_114 = F_100 ( V_1 ) ;
if ( ! F_81 ( V_114 ) && ! F_233 ( V_114 )
&& V_114 != V_183 )
F_31 ( V_1 ,
V_135 ) ;
}
}
return 1UL << V_59 ;
}
static inline void F_286 ( struct V_40 * V_216 , struct V_40 * V_189 )
{
#ifdef F_287
enum V_217 V_218 = V_219 ;
if ( V_189 -> V_127 != F_288 () )
V_218 = V_220 ;
if ( V_189 -> V_127 == V_216 -> V_127 )
F_289 ( V_189 , V_221 ) ;
else {
F_289 ( V_189 , V_222 ) ;
F_289 ( V_216 , V_223 ) ;
}
F_289 ( V_189 , V_218 ) ;
#endif
}
static struct V_1 * F_290 ( struct V_40 * V_40 , int V_3 ,
bool V_191 , struct V_103 * V_104 ,
struct V_111 * V_112 )
{
struct V_1 * V_1 ;
do {
if ( F_140 ( V_112 ) ) {
V_104 -> V_102 += F_242 ( V_40 , 0 ,
V_104 -> V_196 , V_112 ,
V_3 , V_191 ) ;
if ( F_32 ( F_140 ( V_112 ) ) )
return NULL ;
}
if ( V_191 )
V_1 = F_141 ( V_112 , struct V_1 , V_75 ) ;
else
V_1 = F_238 ( V_112 , struct V_1 , V_75 ) ;
F_98 ( & V_1 -> V_75 ) ;
V_104 -> V_102 -- ;
} while ( F_208 ( V_1 ) );
return V_1 ;
}
static struct V_1 * F_291 ( struct V_40 * V_216 ,
struct V_40 * V_40 , unsigned int V_59 ,
T_6 V_160 , int V_3 )
{
struct V_103 * V_104 ;
struct V_111 * V_112 ;
bool V_191 = ( ( V_160 & V_224 ) != 0 ) ;
struct V_1 * V_1 ;
unsigned long V_34 ;
F_161 ( V_34 ) ;
V_104 = & F_274 ( V_40 -> V_200 ) -> V_104 ;
V_112 = & V_104 -> V_113 [ V_3 ] ;
V_1 = F_290 ( V_40 , V_3 , V_191 , V_104 , V_112 ) ;
if ( V_1 ) {
F_292 ( V_225 , F_293 ( V_1 ) , 1 << V_59 ) ;
F_286 ( V_216 , V_40 ) ;
}
F_163 ( V_34 ) ;
return V_1 ;
}
static inline
struct V_1 * F_294 ( struct V_40 * V_216 ,
struct V_40 * V_40 , unsigned int V_59 ,
T_6 V_160 , unsigned int V_161 ,
int V_3 )
{
unsigned long V_34 ;
struct V_1 * V_1 ;
if ( F_96 ( V_59 == 0 ) ) {
V_1 = F_291 ( V_216 , V_40 , V_59 ,
V_160 , V_3 ) ;
goto V_53;
}
F_254 ( ( V_160 & V_226 ) && ( V_59 > 1 ) ) ;
F_232 ( & V_40 -> V_108 , V_34 ) ;
do {
V_1 = NULL ;
if ( V_161 & V_227 ) {
V_1 = F_219 ( V_40 , V_59 , V_183 ) ;
if ( V_1 )
F_241 ( V_1 , V_59 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_240 ( V_40 , V_59 , V_3 ) ;
} while ( V_1 && F_209 ( V_1 , V_59 ) );
F_143 ( & V_40 -> V_108 ) ;
if ( ! V_1 )
goto V_228;
F_78 ( V_40 , - ( 1 << V_59 ) ,
F_1 ( V_1 ) ) ;
F_292 ( V_225 , F_293 ( V_1 ) , 1 << V_59 ) ;
F_286 ( V_216 , V_40 ) ;
F_163 ( V_34 ) ;
V_53:
F_27 ( V_1 && F_42 ( V_40 , V_1 ) , V_1 ) ;
return V_1 ;
V_228:
F_163 ( V_34 ) ;
return NULL ;
}
static int T_4 F_295 ( char * V_229 )
{
return F_296 ( & V_230 . V_231 , V_229 ) ;
}
static bool F_297 ( T_6 V_232 , unsigned int V_59 )
{
if ( V_59 < V_230 . V_233 )
return false ;
if ( V_232 & V_226 )
return false ;
if ( V_230 . V_234 && ( V_232 & V_235 ) )
return false ;
if ( V_230 . V_236 &&
( V_232 & V_237 ) )
return false ;
return F_298 ( & V_230 . V_231 , 1 << V_59 ) ;
}
static int T_4 F_299 ( void )
{
T_8 V_238 = V_239 | V_240 | V_241 ;
struct V_242 * V_243 ;
V_243 = F_300 ( L_21 , NULL ,
& V_230 . V_231 ) ;
if ( F_301 ( V_243 ) )
return F_302 ( V_243 ) ;
if ( ! F_303 ( L_22 , V_238 , V_243 ,
& V_230 . V_236 ) )
goto V_244;
if ( ! F_303 ( L_23 , V_238 , V_243 ,
& V_230 . V_234 ) )
goto V_244;
if ( ! F_304 ( L_24 , V_238 , V_243 ,
& V_230 . V_233 ) )
goto V_244;
return 0 ;
V_244:
F_305 ( V_243 ) ;
return - V_245 ;
}
static inline bool F_297 ( T_6 V_232 , unsigned int V_59 )
{
return false ;
}
bool F_306 ( struct V_40 * V_189 , unsigned int V_59 , unsigned long V_246 ,
int V_247 , unsigned int V_161 ,
long V_248 )
{
long F_177 = V_246 ;
int V_249 ;
const bool V_250 = ( V_161 & V_227 ) ;
V_248 -= ( 1 << V_59 ) - 1 ;
if ( V_161 & V_251 )
F_177 -= F_177 / 2 ;
if ( F_96 ( ! V_250 ) )
V_248 -= V_189 -> V_181 ;
else
F_177 -= F_177 / 4 ;
#ifdef F_307
if ( ! ( V_161 & V_214 ) )
V_248 -= F_308 ( V_189 , V_193 ) ;
#endif
if ( V_248 <= F_177 + V_189 -> V_252 [ V_247 ] )
return false ;
if ( ! V_59 )
return true ;
for ( V_249 = V_59 ; V_249 < V_71 ; V_249 ++ ) {
struct V_84 * V_155 = & V_189 -> V_84 [ V_249 ] ;
int V_114 ;
if ( ! V_155 -> V_85 )
continue;
if ( V_250 )
return true ;
for ( V_114 = 0 ; V_114 < V_37 ; V_114 ++ ) {
if ( ! F_140 ( & V_155 -> V_89 [ V_114 ] ) )
return true ;
}
#ifdef F_307
if ( ( V_161 & V_214 ) &&
! F_140 ( & V_155 -> V_89 [ V_151 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_285 ( struct V_40 * V_189 , unsigned int V_59 , unsigned long V_246 ,
int V_247 , unsigned int V_161 )
{
return F_306 ( V_189 , V_59 , V_246 , V_247 , V_161 ,
F_308 ( V_189 , V_194 ) ) ;
}
static inline bool F_309 ( struct V_40 * V_189 , unsigned int V_59 ,
unsigned long V_246 , int V_247 , unsigned int V_161 )
{
long V_248 = F_308 ( V_189 , V_194 ) ;
long V_253 = 0 ;
#ifdef F_307
if ( ! ( V_161 & V_214 ) )
V_253 = F_308 ( V_189 , V_193 ) ;
#endif
if ( ! V_59 && ( V_248 - V_253 ) > V_246 + V_189 -> V_252 [ V_247 ] )
return true ;
return F_306 ( V_189 , V_59 , V_246 , V_247 , V_161 ,
V_248 ) ;
}
bool F_310 ( struct V_40 * V_189 , unsigned int V_59 ,
unsigned long V_246 , int V_247 )
{
long V_248 = F_308 ( V_189 , V_194 ) ;
if ( V_189 -> V_254 && V_248 < V_189 -> V_254 )
V_248 = F_311 ( V_189 , V_194 ) ;
return F_306 ( V_189 , V_59 , V_246 , V_247 , 0 ,
V_248 ) ;
}
static bool F_312 ( struct V_40 * V_255 , struct V_40 * V_40 )
{
return F_313 ( F_39 ( V_255 ) , F_39 ( V_40 ) ) <=
V_256 ;
}
static bool F_312 ( struct V_40 * V_255 , struct V_40 * V_40 )
{
return true ;
}
static struct V_1 *
F_314 ( T_6 V_232 , unsigned int V_59 , int V_161 ,
const struct V_184 * V_185 )
{
struct V_188 * V_189 = V_185 -> V_257 ;
struct V_40 * V_40 ;
struct V_258 * V_259 = NULL ;
F_315 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct V_1 * V_1 ;
unsigned long V_246 ;
if ( F_316 () &&
( V_161 & V_260 ) &&
! F_317 ( V_40 , V_232 ) )
continue;
if ( V_185 -> V_261 ) {
if ( V_259 == V_40 -> V_109 )
continue;
if ( ! F_318 ( V_40 -> V_109 ) ) {
V_259 = V_40 -> V_109 ;
continue;
}
}
V_246 = V_40 -> V_213 [ V_161 & V_262 ] ;
if ( ! F_309 ( V_40 , V_59 , V_246 ,
F_319 ( V_185 ) , V_161 ) ) {
int V_41 ;
F_26 ( V_164 < V_263 ) ;
if ( V_161 & V_164 )
goto V_264;
if ( V_265 == 0 ||
! F_312 ( V_185 -> V_257 -> V_40 , V_40 ) )
continue;
V_41 = F_320 ( V_40 -> V_109 , V_232 , V_59 ) ;
switch ( V_41 ) {
case V_266 :
continue;
case V_267 :
continue;
default:
if ( F_285 ( V_40 , V_59 , V_246 ,
F_319 ( V_185 ) , V_161 ) )
goto V_264;
continue;
}
}
V_264:
V_1 = F_294 ( V_185 -> V_257 -> V_40 , V_40 , V_59 ,
V_232 , V_161 , V_185 -> V_3 ) ;
if ( V_1 ) {
F_214 ( V_1 , V_59 , V_232 , V_161 ) ;
if ( F_32 ( V_59 && ( V_161 & V_227 ) ) )
F_231 ( V_1 , V_40 , V_59 ) ;
return V_1 ;
}
}
return NULL ;
}
static inline bool F_321 ( void )
{
bool V_41 = false ;
#if V_268 > 8
V_41 = F_322 () ;
#endif
return V_41 ;
}
static void F_323 ( T_6 V_232 , T_9 * V_269 )
{
unsigned int V_270 = V_271 ;
static F_324 ( V_272 , V_54 , 1 ) ;
if ( F_321 () || ! F_325 ( & V_272 ) )
return;
if ( ! ( V_232 & V_273 ) )
if ( F_326 ( V_274 ) ||
( V_55 -> V_34 & ( V_275 | V_276 ) ) )
V_270 &= ~ V_271 ;
if ( F_322 () || ! ( V_232 & V_237 ) )
V_270 &= ~ V_271 ;
F_327 ( V_270 , V_269 ) ;
}
void F_328 ( T_6 V_232 , T_9 * V_269 , const char * V_277 , ... )
{
struct V_278 V_279 ;
T_10 args ;
static F_324 ( V_280 , V_281 ,
V_282 ) ;
if ( ( V_232 & V_283 ) || ! F_325 ( & V_280 ) ||
F_67 () > 0 )
return;
F_329 ( L_25 , V_55 -> V_56 ) ;
va_start ( args , V_277 ) ;
V_279 . V_277 = V_277 ;
V_279 . V_284 = & args ;
F_330 ( L_26 , & V_279 ) ;
va_end ( args ) ;
F_330 ( L_27 , V_232 , & V_232 ) ;
if ( V_269 )
F_330 ( L_28 , F_331 ( V_269 ) ) ;
else
F_330 ( L_29 ) ;
F_332 () ;
F_49 () ;
F_323 ( V_232 , V_269 ) ;
}
static inline struct V_1 *
F_333 ( T_6 V_232 , unsigned int V_59 ,
unsigned int V_161 ,
const struct V_184 * V_185 )
{
struct V_1 * V_1 ;
V_1 = F_314 ( V_232 , V_59 ,
V_161 | V_260 , V_185 ) ;
if ( ! V_1 )
V_1 = F_314 ( V_232 , V_59 ,
V_161 , V_185 ) ;
return V_1 ;
}
static inline struct V_1 *
F_334 ( T_6 V_232 , unsigned int V_59 ,
const struct V_184 * V_185 , unsigned long * V_285 )
{
struct V_286 V_287 = {
. V_187 = V_185 -> V_187 ,
. V_269 = V_185 -> V_269 ,
. V_288 = NULL ,
. V_232 = V_232 ,
. V_59 = V_59 ,
} ;
struct V_1 * V_1 ;
* V_285 = 0 ;
if ( ! F_255 ( & V_289 ) ) {
* V_285 = 1 ;
F_335 ( 1 ) ;
return NULL ;
}
V_1 = F_314 ( V_232 | V_290 , V_59 ,
V_291 | V_260 , V_185 ) ;
if ( V_1 )
goto V_53;
if ( V_55 -> V_34 & V_292 )
goto V_53;
if ( V_59 > V_293 )
goto V_53;
if ( V_185 -> V_294 < V_295 )
goto V_53;
if ( F_7 () )
goto V_53;
if ( V_232 & V_296 )
goto V_53;
if ( F_336 ( & V_287 ) || F_254 ( V_232 & V_226 ) ) {
* V_285 = 1 ;
if ( V_232 & V_226 )
V_1 = F_333 ( V_232 , V_59 ,
V_164 , V_185 ) ;
}
V_53:
F_264 ( & V_289 ) ;
return V_1 ;
}
static struct V_1 *
F_337 ( T_6 V_232 , unsigned int V_59 ,
unsigned int V_161 , const struct V_184 * V_185 ,
enum V_297 V_298 , enum V_299 * V_299 )
{
struct V_1 * V_1 ;
if ( ! V_59 )
return NULL ;
V_55 -> V_34 |= V_275 ;
* V_299 = F_338 ( V_232 , V_59 , V_161 , V_185 ,
V_298 ) ;
V_55 -> V_34 &= ~ V_275 ;
if ( * V_299 <= V_300 )
return NULL ;
F_339 ( V_301 ) ;
V_1 = F_314 ( V_232 , V_59 , V_161 , V_185 ) ;
if ( V_1 ) {
struct V_40 * V_40 = F_19 ( V_1 ) ;
V_40 -> V_302 = false ;
F_340 ( V_40 , V_59 , true ) ;
F_339 ( V_303 ) ;
return V_1 ;
}
F_339 ( V_304 ) ;
F_189 () ;
return NULL ;
}
static inline bool
F_341 ( struct V_184 * V_185 , int V_59 , int V_161 ,
enum V_299 V_299 ,
enum V_297 * V_297 ,
int * V_305 )
{
int V_306 = V_307 ;
int V_308 ;
bool V_41 = false ;
int V_309 = * V_305 ;
enum V_297 V_310 = * V_297 ;
if ( ! V_59 )
return false ;
if ( F_342 ( V_299 ) )
( * V_305 ) ++ ;
if ( F_343 ( V_299 ) )
goto V_311;
if ( F_344 ( V_299 ) ) {
V_41 = F_345 ( V_185 , V_59 , V_161 ) ;
goto V_53;
}
if ( V_59 > V_293 )
V_306 /= 4 ;
if ( * V_305 <= V_306 ) {
V_41 = true ;
goto V_53;
}
V_311:
V_308 = ( V_59 > V_293 ) ?
V_312 : V_313 ;
if ( * V_297 > V_308 ) {
( * V_297 ) -- ;
* V_305 = 0 ;
V_41 = true ;
}
V_53:
F_346 ( V_59 , V_310 , V_299 , V_309 , V_306 , V_41 ) ;
return V_41 ;
}
static inline struct V_1 *
F_337 ( T_6 V_232 , unsigned int V_59 ,
unsigned int V_161 , const struct V_184 * V_185 ,
enum V_297 V_298 , enum V_299 * V_299 )
{
* V_299 = V_314 ;
return NULL ;
}
static inline bool
F_341 ( struct V_184 * V_185 , unsigned int V_59 , int V_161 ,
enum V_299 V_299 ,
enum V_297 * V_297 ,
int * V_305 )
{
struct V_40 * V_40 ;
struct V_188 * V_189 ;
if ( ! V_59 || V_59 > V_293 )
return false ;
F_236 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( F_285 ( V_40 , 0 , F_284 ( V_40 ) ,
F_319 ( V_185 ) , V_161 ) )
return true ;
}
return false ;
}
static int
F_347 ( T_6 V_232 , unsigned int V_59 ,
const struct V_184 * V_185 )
{
struct V_315 V_315 ;
int V_316 ;
F_189 () ;
F_348 () ;
V_55 -> V_34 |= V_275 ;
F_349 ( V_232 ) ;
V_315 . V_317 = 0 ;
V_55 -> V_315 = & V_315 ;
V_316 = F_350 ( V_185 -> V_187 , V_59 , V_232 ,
V_185 -> V_269 ) ;
V_55 -> V_315 = NULL ;
F_351 () ;
V_55 -> V_34 &= ~ V_275 ;
F_189 () ;
return V_316 ;
}
static inline struct V_1 *
F_352 ( T_6 V_232 , unsigned int V_59 ,
unsigned int V_161 , const struct V_184 * V_185 ,
unsigned long * V_285 )
{
struct V_1 * V_1 = NULL ;
bool V_318 = false ;
* V_285 = F_347 ( V_232 , V_59 , V_185 ) ;
if ( F_32 ( ! ( * V_285 ) ) )
return NULL ;
V_319:
V_1 = F_314 ( V_232 , V_59 , V_161 , V_185 ) ;
if ( ! V_1 && ! V_318 ) {
F_235 ( V_185 , false ) ;
F_253 ( NULL ) ;
V_318 = true ;
goto V_319;
}
return V_1 ;
}
static void F_353 ( unsigned int V_59 , const struct V_184 * V_185 )
{
struct V_188 * V_189 ;
struct V_40 * V_40 ;
T_1 * V_320 = NULL ;
F_236 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask) {
if ( V_320 != V_40 -> V_109 )
F_354 ( V_40 , V_59 , V_185 -> V_294 ) ;
V_320 = V_40 -> V_109 ;
}
}
static inline unsigned int
F_355 ( T_6 V_232 )
{
unsigned int V_161 = V_321 | V_260 ;
F_26 ( V_322 != ( V_323 T_6 ) V_251 ) ;
V_161 |= ( V_323 int ) ( V_232 & V_322 ) ;
if ( V_232 & V_324 ) {
if ( ! ( V_232 & V_273 ) )
V_161 |= V_227 ;
V_161 &= ~ V_260 ;
} else if ( F_32 ( F_356 ( V_55 ) ) && ! F_322 () )
V_161 |= V_227 ;
#ifdef F_307
if ( F_357 ( V_232 ) == V_135 )
V_161 |= V_214 ;
#endif
return V_161 ;
}
bool F_358 ( T_6 V_232 )
{
if ( F_32 ( V_232 & V_273 ) )
return false ;
if ( V_232 & V_325 )
return true ;
if ( F_359 () && ( V_55 -> V_34 & V_275 ) )
return true ;
if ( ! F_322 () &&
( ( V_55 -> V_34 & V_275 ) ||
F_32 ( F_326 ( V_274 ) ) ) )
return true ;
return false ;
}
static inline bool
F_360 ( T_6 V_232 , unsigned V_59 ,
struct V_184 * V_185 , int V_161 ,
bool V_285 , int * V_326 )
{
struct V_40 * V_40 ;
struct V_188 * V_189 ;
if ( V_285 && V_59 <= V_293 )
* V_326 = 0 ;
else
( * V_326 ) ++ ;
if ( * V_326 > V_327 ) {
return F_235 ( V_185 , true ) ;
}
F_236 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_328 ;
unsigned long V_329 ;
unsigned long V_330 = F_284 ( V_40 ) ;
bool V_331 ;
V_328 = V_329 = F_361 ( V_40 ) ;
V_328 -= F_362 ( ( * V_326 ) * V_328 ,
V_327 ) ;
V_328 += F_311 ( V_40 , V_194 ) ;
V_331 = F_306 ( V_40 , V_59 , V_330 ,
F_319 ( V_185 ) , V_161 , V_328 ) ;
F_363 ( V_189 , V_59 , V_329 ,
V_328 , V_330 , * V_326 , V_331 ) ;
if ( V_331 ) {
if ( ! V_285 ) {
unsigned long V_332 ;
V_332 = F_311 ( V_40 ,
V_333 ) ;
if ( 2 * V_332 > V_329 ) {
F_364 ( V_334 , V_54 / 10 ) ;
return true ;
}
}
if ( V_55 -> V_34 & V_205 )
F_335 ( 1 ) ;
else
F_189 () ;
return true ;
}
}
return false ;
}
static inline struct V_1 *
F_365 ( T_6 V_232 , unsigned int V_59 ,
struct V_184 * V_185 )
{
bool V_335 = V_232 & V_237 ;
struct V_1 * V_1 = NULL ;
unsigned int V_161 ;
unsigned long V_285 ;
enum V_297 V_297 ;
enum V_299 V_299 ;
int V_305 ;
int V_326 ;
unsigned long V_336 = V_52 ;
unsigned int V_337 = 10 * V_54 ;
unsigned int V_338 ;
if ( V_59 >= V_71 ) {
F_254 ( ! ( V_232 & V_283 ) ) ;
return NULL ;
}
if ( F_254 ( ( V_232 & ( V_324 | V_237 ) ) ==
( V_324 | V_237 ) ) )
V_232 &= ~ V_324 ;
V_339:
V_305 = 0 ;
V_326 = 0 ;
V_297 = V_340 ;
V_338 = F_366 () ;
V_161 = F_355 ( V_232 ) ;
V_185 -> V_257 = F_367 ( V_185 -> V_187 ,
V_185 -> V_294 , V_185 -> V_269 ) ;
if ( ! V_185 -> V_257 -> V_40 )
goto V_341;
if ( V_232 & V_342 )
F_353 ( V_59 , V_185 ) ;
V_1 = F_314 ( V_232 , V_59 , V_161 , V_185 ) ;
if ( V_1 )
goto V_343;
if ( V_335 && V_59 > V_293 &&
! F_358 ( V_232 ) ) {
V_1 = F_337 ( V_232 , V_59 ,
V_161 , V_185 ,
V_344 ,
& V_299 ) ;
if ( V_1 )
goto V_343;
if ( V_232 & V_345 ) {
if ( V_299 == V_346 )
goto V_341;
V_297 = V_344 ;
}
}
V_319:
if ( V_232 & V_342 )
F_353 ( V_59 , V_185 ) ;
if ( F_358 ( V_232 ) )
V_161 = V_164 ;
if ( ! ( V_161 & V_260 ) || ( V_161 & V_164 ) ) {
V_185 -> V_187 = F_368 ( F_288 () , V_232 ) ;
V_185 -> V_257 = F_367 ( V_185 -> V_187 ,
V_185 -> V_294 , V_185 -> V_269 ) ;
}
V_1 = F_314 ( V_232 , V_59 , V_161 , V_185 ) ;
if ( V_1 )
goto V_343;
if ( ! V_335 )
goto V_341;
if ( F_369 ( V_52 , V_336 + V_337 ) ) {
F_328 ( V_232 , V_185 -> V_269 ,
L_30 ,
F_191 ( V_52 - V_336 ) , V_59 ) ;
V_337 += 10 * V_54 ;
}
if ( V_55 -> V_34 & V_275 )
goto V_341;
V_1 = F_352 ( V_232 , V_59 , V_161 , V_185 ,
& V_285 ) ;
if ( V_1 )
goto V_343;
V_1 = F_337 ( V_232 , V_59 , V_161 , V_185 ,
V_297 , & V_299 ) ;
if ( V_1 )
goto V_343;
if ( V_232 & V_345 )
goto V_341;
if ( V_59 > V_293 && ! ( V_232 & V_347 ) )
goto V_341;
if ( F_360 ( V_232 , V_59 , V_185 , V_161 ,
V_285 > 0 , & V_326 ) )
goto V_319;
if ( V_285 > 0 &&
F_341 ( V_185 , V_59 , V_161 ,
V_299 , & V_297 ,
& V_305 ) )
goto V_319;
if ( F_370 ( V_338 ) )
goto V_339;
V_1 = F_334 ( V_232 , V_59 , V_185 , & V_285 ) ;
if ( V_1 )
goto V_343;
if ( F_326 ( V_274 ) )
goto V_341;
if ( V_285 ) {
V_326 = 0 ;
goto V_319;
}
V_341:
if ( F_370 ( V_338 ) )
goto V_339;
if ( V_232 & V_226 ) {
if ( F_254 ( ! V_335 ) )
goto V_244;
F_254 ( V_55 -> V_34 & V_275 ) ;
F_254 ( V_59 > V_293 ) ;
V_1 = F_333 ( V_232 , V_59 , V_227 , V_185 ) ;
if ( V_1 )
goto V_343;
F_189 () ;
goto V_319;
}
V_244:
F_328 ( V_232 , V_185 -> V_269 ,
L_31 , V_59 ) ;
V_343:
return V_1 ;
}
static inline bool F_371 ( T_6 V_232 , unsigned int V_59 ,
struct V_187 * V_187 , T_9 * V_269 ,
struct V_184 * V_185 , T_6 * V_348 ,
unsigned int * V_161 )
{
V_185 -> V_294 = F_372 ( V_232 ) ;
V_185 -> V_187 = V_187 ;
V_185 -> V_269 = V_269 ;
V_185 -> V_3 = F_357 ( V_232 ) ;
if ( F_316 () ) {
* V_348 |= V_290 ;
if ( ! V_185 -> V_269 )
V_185 -> V_269 = & V_349 ;
else
* V_161 |= V_260 ;
}
F_373 ( V_232 ) ;
F_374 ( V_232 & V_237 ) ;
if ( F_297 ( V_232 , V_59 ) )
return false ;
if ( F_110 ( F_307 ) && V_185 -> V_3 == V_135 )
* V_161 |= V_214 ;
return true ;
}
static inline void F_375 ( T_6 V_232 ,
unsigned int V_59 , struct V_184 * V_185 )
{
V_185 -> V_261 = ( V_232 & V_350 ) ;
V_185 -> V_257 = F_367 ( V_185 -> V_187 ,
V_185 -> V_294 , V_185 -> V_269 ) ;
}
struct V_1 *
F_376 ( T_6 V_232 , unsigned int V_59 ,
struct V_187 * V_187 , T_9 * V_269 )
{
struct V_1 * V_1 ;
unsigned int V_161 = V_351 ;
T_6 V_348 = V_232 ;
struct V_184 V_185 = { } ;
V_232 &= V_6 ;
if ( ! F_371 ( V_232 , V_59 , V_187 , V_269 , & V_185 , & V_348 , & V_161 ) )
return NULL ;
F_375 ( V_232 , V_59 , & V_185 ) ;
V_1 = F_314 ( V_348 , V_59 , V_161 , & V_185 ) ;
if ( F_96 ( V_1 ) )
goto V_53;
V_348 = F_377 ( V_232 ) ;
V_185 . V_261 = false ;
if ( F_32 ( V_185 . V_269 != V_269 ) )
V_185 . V_269 = V_269 ;
V_1 = F_365 ( V_348 , V_59 , & V_185 ) ;
V_53:
if ( F_121 () && ( V_232 & V_352 ) && V_1 &&
F_32 ( F_378 ( V_1 , V_232 , V_59 ) != 0 ) ) {
F_168 ( V_1 , V_59 ) ;
V_1 = NULL ;
}
if ( V_353 && V_1 )
F_379 ( V_1 , V_59 , V_232 ) ;
F_380 ( V_1 , V_59 , V_348 , V_185 . V_3 ) ;
return V_1 ;
}
unsigned long F_381 ( T_6 V_232 , unsigned int V_59 )
{
struct V_1 * V_1 ;
F_94 ( ( V_232 & V_235 ) != 0 ) ;
V_1 = F_382 ( V_232 , V_59 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_128 ( V_1 ) ;
}
unsigned long F_383 ( T_6 V_232 )
{
return F_381 ( V_232 | V_162 , 0 ) ;
}
void F_168 ( struct V_1 * V_1 , unsigned int V_59 )
{
if ( F_384 ( V_1 ) ) {
if ( V_59 == 0 )
F_272 ( V_1 , false ) ;
else
F_53 ( V_1 , V_59 ) ;
}
}
void V_248 ( unsigned long V_354 , unsigned int V_59 )
{
if ( V_354 != 0 ) {
F_94 ( ! F_385 ( ( void * ) V_354 ) ) ;
F_168 ( F_281 ( ( void * ) V_354 ) , V_59 ) ;
}
}
static struct V_1 * F_386 ( struct V_355 * V_356 ,
T_6 V_232 )
{
struct V_1 * V_1 = NULL ;
T_6 V_357 = V_232 ;
#if ( V_101 < V_358 )
V_232 |= V_163 | V_283 | V_345 |
V_273 ;
V_1 = F_387 ( V_359 , V_232 ,
V_360 ) ;
V_356 -> V_156 = V_1 ? V_358 : V_101 ;
#endif
if ( F_32 ( ! V_1 ) )
V_1 = F_387 ( V_359 , V_357 , 0 ) ;
V_356 -> V_284 = V_1 ? F_128 ( V_1 ) : NULL ;
return V_1 ;
}
void F_388 ( struct V_1 * V_1 , unsigned int V_102 )
{
F_27 ( F_105 ( V_1 ) == 0 , V_1 ) ;
if ( F_389 ( V_1 , V_102 ) ) {
unsigned int V_59 = F_54 ( V_1 ) ;
if ( V_59 == 0 )
F_272 ( V_1 , false ) ;
else
F_53 ( V_1 , V_59 ) ;
}
}
void * F_390 ( struct V_355 * V_356 ,
unsigned int V_361 , T_6 V_232 )
{
unsigned int V_156 = V_101 ;
struct V_1 * V_1 ;
int V_362 ;
if ( F_32 ( ! V_356 -> V_284 ) ) {
V_363:
V_1 = F_386 ( V_356 , V_232 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_101 < V_358 )
V_156 = V_356 -> V_156 ;
#endif
F_391 ( V_1 , V_156 - 1 ) ;
V_356 -> V_364 = F_392 ( V_1 ) ;
V_356 -> V_365 = V_156 ;
V_356 -> V_362 = V_156 ;
}
V_362 = V_356 -> V_362 - V_361 ;
if ( F_32 ( V_362 < 0 ) ) {
V_1 = F_281 ( V_356 -> V_284 ) ;
if ( ! F_389 ( V_1 , V_356 -> V_365 ) )
goto V_363;
#if ( V_101 < V_358 )
V_156 = V_356 -> V_156 ;
#endif
F_59 ( V_1 , V_156 ) ;
V_356 -> V_365 = V_156 ;
V_362 = V_156 - V_361 ;
}
V_356 -> V_365 -- ;
V_356 -> V_362 = V_362 ;
return V_356 -> V_284 + V_362 ;
}
void F_393 ( void * V_354 )
{
struct V_1 * V_1 = F_394 ( V_354 ) ;
if ( F_32 ( F_384 ( V_1 ) ) )
F_53 ( V_1 , F_54 ( V_1 ) ) ;
}
static void * F_395 ( unsigned long V_354 , unsigned int V_59 ,
T_11 V_156 )
{
if ( V_354 ) {
unsigned long V_366 = V_354 + ( V_101 << V_59 ) ;
unsigned long V_367 = V_354 + F_396 ( V_156 ) ;
F_278 ( F_281 ( ( void * ) V_354 ) , V_59 ) ;
while ( V_367 < V_366 ) {
F_397 ( V_367 ) ;
V_367 += V_101 ;
}
}
return ( void * ) V_354 ;
}
void * F_398 ( T_11 V_156 , T_6 V_232 )
{
unsigned int V_59 = F_399 ( V_156 ) ;
unsigned long V_354 ;
V_354 = F_381 ( V_232 , V_59 ) ;
return F_395 ( V_354 , V_59 , V_156 ) ;
}
void * T_2 F_400 ( int V_13 , T_11 V_156 , T_6 V_232 )
{
unsigned int V_59 = F_399 ( V_156 ) ;
struct V_1 * V_63 = F_387 ( V_13 , V_232 , V_59 ) ;
if ( ! V_63 )
return NULL ;
return F_395 ( ( unsigned long ) F_128 ( V_63 ) , V_59 , V_156 ) ;
}
void F_401 ( void * V_368 , T_11 V_156 )
{
unsigned long V_354 = ( unsigned long ) V_368 ;
unsigned long V_119 = V_354 + F_396 ( V_156 ) ;
while ( V_354 < V_119 ) {
F_397 ( V_354 ) ;
V_354 += V_101 ;
}
}
static unsigned long F_402 ( int V_362 )
{
struct V_188 * V_189 ;
struct V_40 * V_40 ;
unsigned long V_369 = 0 ;
struct V_187 * V_187 = F_368 ( F_288 () , V_370 ) ;
F_403 (zone, z, zonelist, offset) {
unsigned long V_156 = V_40 -> V_123 ;
unsigned long V_154 = F_404 ( V_40 ) ;
if ( V_156 > V_154 )
V_369 += V_156 - V_154 ;
}
return V_369 ;
}
unsigned long F_405 ( void )
{
return F_402 ( F_372 ( V_371 ) ) ;
}
unsigned long F_406 ( void )
{
return F_402 ( F_372 ( V_372 ) ) ;
}
static inline void F_407 ( struct V_40 * V_40 )
{
if ( F_110 ( F_287 ) )
F_408 ( L_32 , F_39 ( V_40 ) ) ;
}
long F_409 ( void )
{
long V_328 ;
unsigned long V_373 ;
unsigned long V_374 = 0 ;
unsigned long V_173 [ V_375 ] ;
struct V_40 * V_40 ;
int V_75 ;
for ( V_75 = V_376 ; V_75 < V_375 ; V_75 ++ )
V_173 [ V_75 ] = F_410 ( V_377 + V_75 ) ;
F_411 (zone)
V_374 += V_40 -> V_213 [ V_378 ] ;
V_328 = F_412 ( V_194 ) - V_379 ;
V_373 = V_173 [ V_380 ] + V_173 [ V_381 ] ;
V_373 -= F_177 ( V_373 / 2 , V_374 ) ;
V_328 += V_373 ;
V_328 += F_412 ( V_382 ) -
F_177 ( F_412 ( V_382 ) / 2 , V_374 ) ;
if ( V_328 < 0 )
V_328 = 0 ;
return V_328 ;
}
void F_413 ( struct V_383 * V_384 )
{
V_384 -> V_385 = V_386 ;
V_384 -> V_387 = F_410 ( V_388 ) ;
V_384 -> V_389 = F_412 ( V_194 ) ;
V_384 -> V_390 = F_414 () ;
V_384 -> V_391 = V_392 ;
V_384 -> V_393 = F_415 () ;
V_384 -> V_394 = V_101 ;
}
void F_416 ( struct V_383 * V_384 , int V_13 )
{
int V_395 ;
unsigned long V_123 = 0 ;
unsigned long V_396 = 0 ;
unsigned long V_397 = 0 ;
T_1 * V_9 = F_12 ( V_13 ) ;
for ( V_395 = 0 ; V_395 < V_116 ; V_395 ++ )
V_123 += V_9 -> V_117 [ V_395 ] . V_123 ;
V_384 -> V_385 = V_123 ;
V_384 -> V_387 = F_138 ( V_9 , V_388 ) ;
V_384 -> V_389 = F_417 ( V_13 , V_194 ) ;
#ifdef F_418
for ( V_395 = 0 ; V_395 < V_116 ; V_395 ++ ) {
struct V_40 * V_40 = & V_9 -> V_117 [ V_395 ] ;
if ( F_419 ( V_40 ) ) {
V_396 += V_40 -> V_123 ;
V_397 += F_308 ( V_40 , V_194 ) ;
}
}
V_384 -> V_391 = V_396 ;
V_384 -> V_393 = V_397 ;
#else
V_384 -> V_391 = V_396 ;
V_384 -> V_393 = V_397 ;
#endif
V_384 -> V_394 = V_101 ;
}
static bool F_420 ( unsigned int V_34 , int V_13 , T_9 * V_269 )
{
if ( ! ( V_34 & V_271 ) )
return false ;
if ( ! V_269 )
V_269 = & V_349 ;
return ! F_421 ( V_13 , * V_269 ) ;
}
static void F_422 ( unsigned char type )
{
static const char V_398 [ V_178 ] = {
[ V_38 ] = 'U' ,
[ V_135 ] = 'M' ,
[ V_171 ] = 'E' ,
[ V_183 ] = 'H' ,
#ifdef F_307
[ V_151 ] = 'C' ,
#endif
#ifdef F_423
[ V_399 ] = 'I' ,
#endif
} ;
char V_400 [ V_178 + 1 ] ;
char * V_63 = V_400 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_178 ; V_60 ++ ) {
if ( type & ( 1 << V_60 ) )
* V_63 ++ = V_398 [ V_60 ] ;
}
* V_63 = '\0' ;
F_408 ( V_401 L_33 , V_400 ) ;
}
void F_424 ( unsigned int V_270 , T_9 * V_269 )
{
unsigned long V_402 = 0 ;
int V_197 ;
struct V_40 * V_40 ;
T_1 * V_9 ;
F_199 (zone) {
if ( F_420 ( V_270 , F_39 ( V_40 ) , V_269 ) )
continue;
F_257 (cpu)
V_402 += F_246 ( V_40 -> V_200 , V_197 ) -> V_104 . V_102 ;
}
F_408 ( L_34
L_35
L_36
L_37
L_38
L_39 ,
F_410 ( V_403 ) ,
F_410 ( V_404 ) ,
F_410 ( V_405 ) ,
F_410 ( V_406 ) ,
F_410 ( V_407 ) ,
F_410 ( V_408 ) ,
F_410 ( V_409 ) ,
F_410 ( V_410 ) ,
F_410 ( V_411 ) ,
F_410 ( V_412 ) ,
F_412 ( V_382 ) ,
F_412 ( V_413 ) ,
F_410 ( V_414 ) ,
F_410 ( V_388 ) ,
F_412 ( V_415 ) ,
F_412 ( V_416 ) ,
F_412 ( V_194 ) ,
V_402 ,
F_412 ( V_193 ) ) ;
F_425 (pgdat) {
if ( F_420 ( V_270 , V_9 -> V_139 , V_269 ) )
continue;
F_408 ( L_40
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
#ifdef F_426
L_52
L_53
L_54
#endif
L_55
L_56
L_57
L_58
L_59 ,
V_9 -> V_139 ,
F_427 ( F_138 ( V_9 , V_403 ) ) ,
F_427 ( F_138 ( V_9 , V_404 ) ) ,
F_427 ( F_138 ( V_9 , V_406 ) ) ,
F_427 ( F_138 ( V_9 , V_407 ) ) ,
F_427 ( F_138 ( V_9 , V_409 ) ) ,
F_427 ( F_138 ( V_9 , V_405 ) ) ,
F_427 ( F_138 ( V_9 , V_408 ) ) ,
F_427 ( F_138 ( V_9 , V_414 ) ) ,
F_427 ( F_138 ( V_9 , V_410 ) ) ,
F_427 ( F_138 ( V_9 , V_411 ) ) ,
F_427 ( F_138 ( V_9 , V_388 ) ) ,
#ifdef F_426
F_427 ( F_138 ( V_9 , V_417 ) * V_418 ) ,
F_427 ( F_138 ( V_9 , V_419 )
* V_418 ) ,
F_427 ( F_138 ( V_9 , V_420 ) * V_418 ) ,
#endif
F_427 ( F_138 ( V_9 , V_421 ) ) ,
F_427 ( F_138 ( V_9 , V_412 ) ) ,
F_138 ( V_9 , V_110 ) ,
! F_428 ( V_9 ) ? L_60 : L_61 ) ;
}
F_199 (zone) {
int V_60 ;
if ( F_420 ( V_270 , F_39 ( V_40 ) , V_269 ) )
continue;
V_402 = 0 ;
F_257 (cpu)
V_402 += F_246 ( V_40 -> V_200 , V_197 ) -> V_104 . V_102 ;
F_407 ( V_40 ) ;
F_408 ( V_401
L_62
L_63
L_64
L_65
L_66
L_41
L_42
L_43
L_44
L_45
L_67
L_68
L_69
L_70
L_71
L_72
L_73
L_74
L_75
L_76
L_77
L_78
L_59 ,
V_40 -> V_46 ,
F_427 ( F_308 ( V_40 , V_194 ) ) ,
F_427 ( F_284 ( V_40 ) ) ,
F_427 ( F_429 ( V_40 ) ) ,
F_427 ( F_404 ( V_40 ) ) ,
F_427 ( F_308 ( V_40 , V_422 ) ) ,
F_427 ( F_308 ( V_40 , V_423 ) ) ,
F_427 ( F_308 ( V_40 , V_424 ) ) ,
F_427 ( F_308 ( V_40 , V_425 ) ) ,
F_427 ( F_308 ( V_40 , V_426 ) ) ,
F_427 ( F_308 ( V_40 , V_333 ) ) ,
F_427 ( V_40 -> V_427 ) ,
F_427 ( V_40 -> V_123 ) ,
F_427 ( F_308 ( V_40 , V_428 ) ) ,
F_427 ( F_308 ( V_40 , V_382 ) ) ,
F_427 ( F_308 ( V_40 , V_413 ) ) ,
F_308 ( V_40 , V_429 ) ,
F_427 ( F_308 ( V_40 , V_415 ) ) ,
F_427 ( F_308 ( V_40 , V_416 ) ) ,
F_427 ( V_402 ) ,
F_427 ( F_430 ( V_40 -> V_200 -> V_104 . V_102 ) ) ,
F_427 ( F_308 ( V_40 , V_193 ) ) ) ;
F_408 ( L_79 ) ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ )
F_408 ( V_401 L_80 , V_40 -> V_252 [ V_60 ] ) ;
F_408 ( V_401 L_59 ) ;
}
F_199 (zone) {
unsigned int V_59 ;
unsigned long V_430 [ V_71 ] , V_34 , V_431 = 0 ;
unsigned char V_398 [ V_71 ] ;
if ( F_420 ( V_270 , F_39 ( V_40 ) , V_269 ) )
continue;
F_407 ( V_40 ) ;
F_408 ( V_401 L_25 , V_40 -> V_46 ) ;
F_232 ( & V_40 -> V_108 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_84 * V_155 = & V_40 -> V_84 [ V_59 ] ;
int type ;
V_430 [ V_59 ] = V_155 -> V_85 ;
V_431 += V_430 [ V_59 ] << V_59 ;
V_398 [ V_59 ] = 0 ;
for ( type = 0 ; type < V_178 ; type ++ ) {
if ( ! F_140 ( & V_155 -> V_89 [ type ] ) )
V_398 [ V_59 ] |= 1 << type ;
}
}
F_234 ( & V_40 -> V_108 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
F_408 ( V_401 L_81 ,
V_430 [ V_59 ] , F_427 ( 1UL ) << V_59 ) ;
if ( V_430 [ V_59 ] )
F_422 ( V_398 [ V_59 ] ) ;
}
F_408 ( V_401 L_82 , F_427 ( V_431 ) ) ;
}
F_431 () ;
F_408 ( L_83 , F_410 ( V_432 ) ) ;
F_432 () ;
}
static void F_433 ( struct V_40 * V_40 , struct V_188 * V_188 )
{
V_188 -> V_40 = V_40 ;
V_188 -> V_433 = V_433 ( V_40 ) ;
}
static int F_434 ( T_1 * V_9 , struct V_187 * V_187 ,
int V_434 )
{
struct V_40 * V_40 ;
enum V_395 V_395 = V_116 ;
do {
V_395 -- ;
V_40 = V_9 -> V_117 + V_395 ;
if ( F_435 ( V_40 ) ) {
F_433 ( V_40 ,
& V_187 -> V_435 [ V_434 ++ ] ) ;
F_436 ( V_395 ) ;
}
} while ( V_395 );
return V_434 ;
}
static int F_437 ( char * V_436 )
{
if ( * V_436 == 'd' || * V_436 == 'D' ) {
V_437 = V_438 ;
} else if ( * V_436 == 'n' || * V_436 == 'N' ) {
V_437 = V_439 ;
} else if ( * V_436 == 'z' || * V_436 == 'Z' ) {
V_437 = V_440 ;
} else {
F_329 ( L_84 , V_436 ) ;
return - V_67 ;
}
return 0 ;
}
static T_4 int F_438 ( char * V_436 )
{
int V_41 ;
if ( ! V_436 )
return 0 ;
V_41 = F_437 ( V_436 ) ;
if ( V_41 == 0 )
F_439 ( V_441 , V_436 , V_442 ) ;
return V_41 ;
}
int F_440 ( struct V_443 * V_444 , int V_445 ,
void T_12 * V_446 , T_11 * V_447 ,
T_13 * V_448 )
{
char V_449 [ V_442 ] ;
int V_41 ;
static F_441 ( V_450 ) ;
F_256 ( & V_450 ) ;
if ( V_445 ) {
if ( strlen ( ( char * ) V_444 -> V_138 ) >= V_442 ) {
V_41 = - V_67 ;
goto V_53;
}
strcpy ( V_449 , ( char * ) V_444 -> V_138 ) ;
}
V_41 = F_442 ( V_444 , V_445 , V_446 , V_447 , V_448 ) ;
if ( V_41 )
goto V_53;
if ( V_445 ) {
int V_451 = V_437 ;
V_41 = F_437 ( ( char * ) V_444 -> V_138 ) ;
if ( V_41 ) {
strncpy ( ( char * ) V_444 -> V_138 , V_449 ,
V_442 ) ;
V_437 = V_451 ;
} else if ( V_451 != V_437 ) {
F_256 ( & V_452 ) ;
F_443 ( NULL , NULL ) ;
F_264 ( & V_452 ) ;
}
}
V_53:
F_264 ( & V_450 ) ;
return V_41 ;
}
static int F_444 ( int V_127 , T_9 * V_453 )
{
int V_454 , V_384 ;
int V_455 = V_456 ;
int V_457 = V_359 ;
const struct V_144 * V_400 = F_184 ( 0 ) ;
if ( ! F_421 ( V_127 , * V_453 ) ) {
F_445 ( V_127 , * V_453 ) ;
return V_127 ;
}
F_195 (n, N_MEMORY) {
if ( F_421 ( V_454 , * V_453 ) )
continue;
V_384 = F_313 ( V_127 , V_454 ) ;
V_384 += ( V_454 < V_127 ) ;
V_400 = F_184 ( V_454 ) ;
if ( ! F_185 ( V_400 ) )
V_384 += V_458 ;
V_384 *= ( V_459 * V_460 ) ;
V_384 += V_461 [ V_454 ] ;
if ( V_384 < V_455 ) {
V_455 = V_384 ;
V_457 = V_454 ;
}
}
if ( V_457 >= 0 )
F_445 ( V_457 , * V_453 ) ;
return V_457 ;
}
static void F_446 ( T_1 * V_9 , int V_127 )
{
int V_462 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_463 [ V_464 ] ;
for ( V_462 = 0 ; V_187 -> V_435 [ V_462 ] . V_40 != NULL ; V_462 ++ )
;
V_462 = F_434 ( F_12 ( V_127 ) , V_187 , V_462 ) ;
V_187 -> V_435 [ V_462 ] . V_40 = NULL ;
V_187 -> V_435 [ V_462 ] . V_433 = 0 ;
}
static void F_447 ( T_1 * V_9 )
{
int V_462 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_463 [ V_465 ] ;
V_462 = F_434 ( V_9 , V_187 , 0 ) ;
V_187 -> V_435 [ V_462 ] . V_40 = NULL ;
V_187 -> V_435 [ V_462 ] . V_433 = 0 ;
}
static void F_448 ( T_1 * V_9 , int V_466 )
{
int V_467 , V_462 , V_127 ;
int V_395 ;
struct V_40 * V_189 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_463 [ V_464 ] ;
V_467 = 0 ;
for ( V_395 = V_116 - 1 ; V_395 >= 0 ; V_395 -- ) {
for ( V_462 = 0 ; V_462 < V_466 ; V_462 ++ ) {
V_127 = V_468 [ V_462 ] ;
V_189 = & F_12 ( V_127 ) -> V_117 [ V_395 ] ;
if ( F_435 ( V_189 ) ) {
F_433 ( V_189 ,
& V_187 -> V_435 [ V_467 ++ ] ) ;
F_436 ( V_395 ) ;
}
}
}
V_187 -> V_435 [ V_467 ] . V_40 = NULL ;
V_187 -> V_435 [ V_467 ] . V_433 = 0 ;
}
static int F_449 ( void )
{
return V_439 ;
}
static int F_449 ( void )
{
return V_440 ;
}
static void F_450 ( void )
{
if ( V_437 == V_438 )
V_469 = F_449 () ;
else
V_469 = V_437 ;
}
static void F_451 ( T_1 * V_9 )
{
int V_60 , V_127 , V_470 ;
T_9 V_471 ;
int V_472 , V_473 ;
struct V_187 * V_187 ;
unsigned int V_59 = V_469 ;
for ( V_60 = 0 ; V_60 < V_474 ; V_60 ++ ) {
V_187 = V_9 -> V_463 + V_60 ;
V_187 -> V_435 [ 0 ] . V_40 = NULL ;
V_187 -> V_435 [ 0 ] . V_433 = 0 ;
}
V_472 = V_9 -> V_139 ;
V_470 = V_475 ;
V_473 = V_472 ;
F_452 ( V_471 ) ;
memset ( V_468 , 0 , sizeof( V_468 ) ) ;
V_60 = 0 ;
while ( ( V_127 = F_444 ( V_472 , & V_471 ) ) >= 0 ) {
if ( F_313 ( V_472 , V_127 ) !=
F_313 ( V_472 , V_473 ) )
V_461 [ V_127 ] = V_470 ;
V_473 = V_127 ;
V_470 -- ;
if ( V_59 == V_439 )
F_446 ( V_9 , V_127 ) ;
else
V_468 [ V_60 ++ ] = V_127 ;
}
if ( V_59 == V_440 ) {
F_448 ( V_9 , V_60 ) ;
}
F_447 ( V_9 ) ;
}
int F_453 ( int V_127 )
{
struct V_188 * V_189 ;
V_189 = F_367 ( F_368 ( V_127 , V_370 ) ,
F_372 ( V_370 ) ,
NULL ) ;
return V_189 -> V_40 -> V_127 ;
}
static void F_450 ( void )
{
V_469 = V_440 ;
}
static void F_451 ( T_1 * V_9 )
{
int V_127 , V_472 ;
enum V_395 V_462 ;
struct V_187 * V_187 ;
V_472 = V_9 -> V_139 ;
V_187 = & V_9 -> V_463 [ V_464 ] ;
V_462 = F_434 ( V_9 , V_187 , 0 ) ;
for ( V_127 = V_472 + 1 ; V_127 < V_460 ; V_127 ++ ) {
if ( ! F_11 ( V_127 ) )
continue;
V_462 = F_434 ( F_12 ( V_127 ) , V_187 , V_462 ) ;
}
for ( V_127 = 0 ; V_127 < V_472 ; V_127 ++ ) {
if ( ! F_11 ( V_127 ) )
continue;
V_462 = F_434 ( F_12 ( V_127 ) , V_187 , V_462 ) ;
}
V_187 -> V_435 [ V_462 ] . V_40 = NULL ;
V_187 -> V_435 [ V_462 ] . V_433 = 0 ;
}
static int F_454 ( void * V_138 )
{
int V_13 ;
int V_197 ;
T_1 * V_476 = V_138 ;
#ifdef F_287
memset ( V_461 , 0 , sizeof( V_461 ) ) ;
#endif
if ( V_476 && ! F_11 ( V_476 -> V_139 ) ) {
F_451 ( V_476 ) ;
}
F_455 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_451 ( V_9 ) ;
}
F_456 (cpu) {
F_457 ( & F_458 ( V_477 , V_197 ) , 0 ) ;
#ifdef F_459
if ( F_460 ( V_197 ) )
F_461 ( V_197 , F_453 ( F_462 ( V_197 ) ) ) ;
#endif
}
return 0 ;
}
static T_14 void T_4
F_463 ( void )
{
F_454 ( NULL ) ;
F_464 () ;
F_465 () ;
}
void T_15 F_443 ( T_1 * V_9 , struct V_40 * V_40 )
{
F_450 () ;
if ( V_478 == V_479 ) {
F_463 () ;
} else {
#ifdef F_466
if ( V_40 )
F_467 ( V_40 ) ;
#endif
F_468 ( F_454 , V_9 , NULL ) ;
}
V_480 = F_406 () ;
if ( V_480 < ( V_24 * V_178 ) )
V_36 = 1 ;
else
V_36 = 0 ;
F_71 ( L_85 ,
V_475 ,
V_481 [ V_469 ] ,
V_36 ? L_86 : L_87 ,
V_480 ) ;
#ifdef F_287
F_71 ( L_88 , V_482 [ V_483 ] ) ;
#endif
}
void T_2 F_469 ( unsigned long V_156 , int V_13 , unsigned long V_40 ,
unsigned long V_44 , enum V_484 V_485 )
{
struct V_486 * V_487 = F_470 ( F_471 ( V_44 ) ) ;
unsigned long V_120 = V_44 + V_156 ;
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_12 ;
unsigned long V_15 = 0 ;
#ifdef F_472
struct V_488 * V_489 = NULL , * V_400 ;
#endif
if ( V_490 < V_120 - 1 )
V_490 = V_120 - 1 ;
if ( V_487 && V_44 == V_487 -> V_491 )
V_44 += V_487 -> V_492 ;
for ( V_12 = V_44 ; V_12 < V_120 ; V_12 ++ ) {
if ( V_485 != V_493 )
goto V_494;
if ( ! F_473 ( V_12 ) ) {
#ifdef F_472
V_12 = F_474 ( V_12 , V_120 ) - 1 ;
#endif
continue;
}
if ( ! F_172 ( V_12 , V_13 ) )
continue;
if ( ! F_13 ( V_9 , V_12 , V_120 , & V_15 ) )
break;
#ifdef F_472
if ( V_495 && V_40 == V_496 ) {
if ( ! V_489 || V_12 >= F_475 ( V_489 ) ) {
F_476 (memory, tmp)
if ( V_12 < F_475 ( V_400 ) )
break;
V_489 = V_400 ;
}
if ( V_12 >= F_477 ( V_489 ) &&
F_478 ( V_489 ) ) {
V_12 = F_475 ( V_489 ) ;
continue;
}
}
#endif
V_494:
if ( ! ( V_12 & ( V_24 - 1 ) ) ) {
struct V_1 * V_1 = F_153 ( V_12 ) ;
F_145 ( V_1 , V_12 , V_40 , V_13 ) ;
F_31 ( V_1 , V_135 ) ;
} else {
F_152 ( V_12 , V_40 , V_13 ) ;
}
}
}
static void T_2 F_479 ( struct V_40 * V_40 )
{
unsigned int V_59 , V_210 ;
F_269 (order, t) {
F_76 ( & V_40 -> V_84 [ V_59 ] . V_89 [ V_210 ] ) ;
V_40 -> V_84 [ V_59 ] . V_85 = 0 ;
}
}
static int F_480 ( struct V_40 * V_40 )
{
#ifdef F_481
int V_196 ;
V_196 = V_40 -> V_123 / 1024 ;
if ( V_196 * V_101 > 512 * 1024 )
V_196 = ( 512 * 1024 ) / V_101 ;
V_196 /= 4 ;
if ( V_196 < 1 )
V_196 = 1 ;
V_196 = F_482 ( V_196 + V_196 / 2 ) - 1 ;
return V_196 ;
#else
return 0 ;
#endif
}
static void F_483 ( struct V_103 * V_104 , unsigned long V_154 ,
unsigned long V_196 )
{
V_104 -> V_196 = 1 ;
F_484 () ;
V_104 -> V_154 = V_154 ;
F_484 () ;
V_104 -> V_196 = V_196 ;
}
static void F_485 ( struct V_198 * V_63 , unsigned long V_196 )
{
F_483 ( & V_63 -> V_104 , 6 * V_196 , F_15 ( 1UL , 1 * V_196 ) ) ;
}
static void F_486 ( struct V_198 * V_63 )
{
struct V_103 * V_104 ;
int V_3 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_104 = & V_63 -> V_104 ;
V_104 -> V_102 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ )
F_76 ( & V_104 -> V_113 [ V_3 ] ) ;
}
static void F_457 ( struct V_198 * V_63 , unsigned long V_196 )
{
F_486 ( V_63 ) ;
F_485 ( V_63 , V_196 ) ;
}
static void F_487 ( struct V_198 * V_63 ,
unsigned long V_154 )
{
unsigned long V_196 = F_15 ( 1UL , V_154 / 4 ) ;
if ( ( V_154 / 4 ) > ( V_17 * 8 ) )
V_196 = V_17 * 8 ;
F_483 ( & V_63 -> V_104 , V_154 , V_196 ) ;
}
static void F_488 ( struct V_40 * V_40 ,
struct V_198 * V_104 )
{
if ( V_497 )
F_487 ( V_104 ,
( V_40 -> V_123 /
V_497 ) ) ;
else
F_485 ( V_104 , F_480 ( V_40 ) ) ;
}
static void T_2 F_489 ( struct V_40 * V_40 , int V_197 )
{
struct V_198 * V_104 = F_246 ( V_40 -> V_200 , V_197 ) ;
F_486 ( V_104 ) ;
F_488 ( V_40 , V_104 ) ;
}
static void T_2 F_467 ( struct V_40 * V_40 )
{
int V_197 ;
V_40 -> V_200 = F_490 ( struct V_198 ) ;
F_456 (cpu)
F_489 ( V_40 , V_197 ) ;
}
void T_4 F_491 ( void )
{
struct V_258 * V_9 ;
struct V_40 * V_40 ;
F_199 (zone)
F_467 ( V_40 ) ;
F_425 (pgdat)
V_9 -> V_498 =
F_490 ( struct V_499 ) ;
}
static T_2 void F_492 ( struct V_40 * V_40 )
{
V_40 -> V_200 = & V_477 ;
if ( F_190 ( V_40 ) )
F_408 ( V_500 L_89 ,
V_40 -> V_46 , V_40 -> V_427 ,
F_480 ( V_40 ) ) ;
}
int T_2 F_493 ( struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_156 )
{
struct V_258 * V_9 = V_40 -> V_109 ;
V_9 -> V_434 = V_433 ( V_40 ) + 1 ;
V_40 -> V_23 = V_23 ;
F_494 ( V_501 , L_90 ,
L_91 ,
V_9 -> V_139 ,
( unsigned long ) V_433 ( V_40 ) ,
V_23 , ( V_23 + V_156 ) ) ;
F_479 ( V_40 ) ;
V_40 -> V_502 = 1 ;
return 0 ;
}
int T_2 F_170 ( unsigned long V_12 ,
struct V_128 * V_129 )
{
unsigned long V_44 , V_120 ;
int V_13 ;
if ( V_129 -> V_503 <= V_12 && V_12 < V_129 -> V_504 )
return V_129 -> V_505 ;
V_13 = F_495 ( V_12 , & V_44 , & V_120 ) ;
if ( V_13 != - 1 ) {
V_129 -> V_503 = V_44 ;
V_129 -> V_504 = V_120 ;
V_129 -> V_505 = V_13 ;
}
return V_13 ;
}
void T_4 F_496 ( int V_13 , unsigned long V_506 )
{
unsigned long V_44 , V_120 ;
int V_60 , V_507 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_44 = F_177 ( V_44 , V_506 ) ;
V_120 = F_177 ( V_120 , V_506 ) ;
if ( V_44 < V_120 )
F_497 ( F_498 ( V_44 ) ,
( V_120 - V_44 ) << V_17 ,
V_507 ) ;
}
}
void T_4 F_499 ( int V_13 )
{
unsigned long V_44 , V_120 ;
int V_60 , V_507 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_500 ( V_507 , V_44 , V_120 ) ;
}
void T_2 F_501 ( unsigned int V_13 ,
unsigned long * V_44 , unsigned long * V_120 )
{
unsigned long V_508 , V_509 ;
int V_60 ;
* V_44 = - 1UL ;
* V_120 = 0 ;
F_188 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_44 = F_177 ( * V_44 , V_508 ) ;
* V_120 = F_15 ( * V_120 , V_509 ) ;
}
if ( * V_44 == - 1UL )
* V_44 = 0 ;
}
static void T_4 F_502 ( void )
{
int V_510 ;
for ( V_510 = V_116 - 1 ; V_510 >= 0 ; V_510 -- ) {
if ( V_510 == V_496 )
continue;
if ( V_511 [ V_510 ] >
V_512 [ V_510 ] )
break;
}
F_94 ( V_510 == - 1 ) ;
V_513 = V_510 ;
}
static void T_2 F_503 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_145 ,
unsigned long V_514 ,
unsigned long * V_23 ,
unsigned long * F_155 )
{
if ( V_515 [ V_13 ] ) {
if ( V_395 == V_496 ) {
* V_23 = V_515 [ V_13 ] ;
* F_155 = F_177 ( V_514 ,
V_511 [ V_513 ] ) ;
} else if ( ! V_495 &&
* V_23 < V_515 [ V_13 ] &&
* F_155 > V_515 [ V_13 ] ) {
* F_155 = V_515 [ V_13 ] ;
} else if ( * V_23 >= V_515 [ V_13 ] )
* V_23 = * F_155 ;
}
}
static unsigned long T_2 F_504 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_145 ,
unsigned long V_514 ,
unsigned long * V_23 ,
unsigned long * F_155 ,
unsigned long * V_516 )
{
if ( ! V_145 && ! V_514 )
return 0 ;
* V_23 = V_512 [ V_395 ] ;
* F_155 = V_511 [ V_395 ] ;
F_503 ( V_13 , V_395 ,
V_145 , V_514 ,
V_23 , F_155 ) ;
if ( * F_155 < V_145 || * V_23 > V_514 )
return 0 ;
* F_155 = F_177 ( * F_155 , V_514 ) ;
* V_23 = F_15 ( * V_23 , V_145 ) ;
return * F_155 - * V_23 ;
}
unsigned long T_2 F_505 ( int V_13 ,
unsigned long V_517 ,
unsigned long V_518 )
{
unsigned long V_519 = V_518 - V_517 ;
unsigned long V_44 , V_120 ;
int V_60 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
V_44 = F_506 ( V_44 , V_517 , V_518 ) ;
V_120 = F_506 ( V_120 , V_517 , V_518 ) ;
V_519 -= V_120 - V_44 ;
}
return V_519 ;
}
unsigned long T_4 F_507 ( unsigned long V_44 ,
unsigned long V_120 )
{
return F_505 ( V_460 , V_44 , V_120 ) ;
}
static unsigned long T_2 F_508 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_145 ,
unsigned long V_514 ,
unsigned long * V_516 )
{
unsigned long V_520 = V_512 [ V_395 ] ;
unsigned long V_521 = V_511 [ V_395 ] ;
unsigned long V_23 , F_155 ;
unsigned long V_519 ;
if ( ! V_145 && ! V_514 )
return 0 ;
V_23 = F_506 ( V_145 , V_520 , V_521 ) ;
F_155 = F_506 ( V_514 , V_520 , V_521 ) ;
F_503 ( V_13 , V_395 ,
V_145 , V_514 ,
& V_23 , & F_155 ) ;
V_519 = F_505 ( V_13 , V_23 , F_155 ) ;
if ( V_495 && V_515 [ V_13 ] ) {
unsigned long V_44 , V_120 ;
struct V_488 * V_489 ;
F_476 (memory, r) {
V_44 = F_506 ( F_477 ( V_489 ) ,
V_23 , F_155 ) ;
V_120 = F_506 ( F_475 ( V_489 ) ,
V_23 , F_155 ) ;
if ( V_395 == V_496 &&
F_478 ( V_489 ) )
V_519 += V_120 - V_44 ;
if ( V_395 == V_295 &&
! F_478 ( V_489 ) )
V_519 += V_120 - V_44 ;
}
}
return V_519 ;
}
static inline unsigned long T_2 F_504 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_145 ,
unsigned long V_514 ,
unsigned long * V_23 ,
unsigned long * F_155 ,
unsigned long * V_522 )
{
unsigned int V_40 ;
* V_23 = V_145 ;
for ( V_40 = 0 ; V_40 < V_395 ; V_40 ++ )
* V_23 += V_522 [ V_40 ] ;
* F_155 = * V_23 + V_522 [ V_395 ] ;
return V_522 [ V_395 ] ;
}
static inline unsigned long T_2 F_508 ( int V_13 ,
unsigned long V_395 ,
unsigned long V_145 ,
unsigned long V_514 ,
unsigned long * V_523 )
{
if ( ! V_523 )
return 0 ;
return V_523 [ V_395 ] ;
}
static void T_2 F_509 ( struct V_258 * V_9 ,
unsigned long V_145 ,
unsigned long V_514 ,
unsigned long * V_522 ,
unsigned long * V_523 )
{
unsigned long V_524 = 0 , V_525 = 0 ;
enum V_395 V_60 ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_60 ;
unsigned long V_23 , F_155 ;
unsigned long V_156 , V_526 ;
V_156 = F_504 ( V_9 -> V_139 , V_60 ,
V_145 ,
V_514 ,
& V_23 ,
& F_155 ,
V_522 ) ;
V_526 = V_156 - F_508 ( V_9 -> V_139 , V_60 ,
V_145 , V_514 ,
V_523 ) ;
if ( V_156 )
V_40 -> V_23 = V_23 ;
else
V_40 -> V_23 = 0 ;
V_40 -> V_45 = V_156 ;
V_40 -> V_427 = V_526 ;
V_525 += V_156 ;
V_524 += V_526 ;
}
V_9 -> V_18 = V_525 ;
V_9 -> V_527 = V_524 ;
F_408 ( V_500 L_92 , V_9 -> V_139 ,
V_524 ) ;
}
static unsigned long T_4 F_510 ( unsigned long V_23 , unsigned long V_528 )
{
unsigned long V_529 ;
V_528 += V_23 & ( V_24 - 1 ) ;
V_529 = F_511 ( V_528 , V_24 ) ;
V_529 = V_529 >> V_21 ;
V_529 *= V_22 ;
V_529 = F_511 ( V_529 , 8 * sizeof( unsigned long ) ) ;
return V_529 / 8 ;
}
static void T_4 F_512 ( struct V_258 * V_9 ,
struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_528 )
{
unsigned long V_529 = F_510 ( V_23 , V_528 ) ;
V_40 -> V_20 = NULL ;
if ( V_529 )
V_40 -> V_20 =
F_513 ( V_529 ,
V_9 -> V_139 ) ;
}
static inline void F_512 ( struct V_258 * V_9 , struct V_40 * V_40 ,
unsigned long V_23 , unsigned long V_528 ) {}
void T_16 F_514 ( void )
{
unsigned int V_59 ;
if ( V_21 )
return;
if ( V_530 > V_17 )
V_59 = V_531 ;
else
V_59 = V_71 - 1 ;
V_21 = V_59 ;
}
void T_16 F_514 ( void )
{
}
static unsigned long T_16 F_515 ( unsigned long V_45 ,
unsigned long V_427 )
{
unsigned long V_173 = V_45 ;
if ( V_45 > V_427 + ( V_427 >> 4 ) &&
F_110 ( F_17 ) )
V_173 = V_427 ;
return F_396 ( V_173 * sizeof( struct V_1 ) ) >> V_17 ;
}
static void T_16 F_516 ( struct V_258 * V_9 )
{
enum V_395 V_462 ;
int V_13 = V_9 -> V_139 ;
int V_41 ;
F_517 ( V_9 ) ;
#ifdef F_518
F_519 ( & V_9 -> V_532 ) ;
V_9 -> V_533 = 0 ;
V_9 -> V_534 = V_52 ;
#endif
#ifdef F_426
F_519 ( & V_9 -> V_535 ) ;
F_76 ( & V_9 -> V_536 ) ;
V_9 -> V_537 = 0 ;
#endif
F_520 ( & V_9 -> V_538 ) ;
F_520 ( & V_9 -> V_539 ) ;
#ifdef F_521
F_520 ( & V_9 -> V_540 ) ;
#endif
F_522 ( V_9 ) ;
F_519 ( & V_9 -> V_541 ) ;
F_523 ( F_524 ( V_9 ) ) ;
for ( V_462 = 0 ; V_462 < V_116 ; V_462 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_462 ;
unsigned long V_156 , V_542 , V_543 , V_544 ;
unsigned long V_23 = V_40 -> V_23 ;
V_156 = V_40 -> V_45 ;
V_542 = V_543 = V_40 -> V_427 ;
V_544 = F_515 ( V_156 , V_542 ) ;
if ( ! F_149 ( V_462 ) ) {
if ( V_543 >= V_544 ) {
V_543 -= V_544 ;
if ( V_544 )
F_408 ( V_500
L_93 ,
V_482 [ V_462 ] , V_544 ) ;
} else
F_329 ( L_94 ,
V_482 [ V_462 ] , V_544 , V_543 ) ;
}
if ( V_462 == 0 && V_543 > V_545 ) {
V_543 -= V_545 ;
F_408 ( V_500 L_95 ,
V_482 [ 0 ] , V_545 ) ;
}
if ( ! F_149 ( V_462 ) )
V_546 += V_543 ;
else if ( V_546 > V_544 * 2 )
V_546 -= V_544 ;
V_547 += V_543 ;
V_40 -> V_123 = F_149 ( V_462 ) ? V_542 : V_543 ;
#ifdef F_287
V_40 -> V_127 = V_13 ;
#endif
V_40 -> V_46 = V_482 [ V_462 ] ;
V_40 -> V_109 = V_9 ;
F_519 ( & V_40 -> V_108 ) ;
F_525 ( V_40 ) ;
F_492 ( V_40 ) ;
if ( ! V_156 )
continue;
F_514 () ;
F_512 ( V_9 , V_40 , V_23 , V_156 ) ;
V_41 = F_493 ( V_40 , V_23 , V_156 ) ;
F_187 ( V_41 ) ;
F_526 ( V_156 , V_13 , V_462 , V_23 ) ;
}
}
static void T_15 F_527 ( struct V_258 * V_9 )
{
unsigned long T_17 V_118 = 0 ;
unsigned long T_17 V_362 = 0 ;
if ( ! V_9 -> V_18 )
return;
#ifdef F_528
V_118 = V_9 -> V_145 & ~ ( V_152 - 1 ) ;
V_362 = V_9 -> V_145 - V_118 ;
if ( ! V_9 -> V_548 ) {
unsigned long V_156 , V_119 ;
struct V_1 * V_549 ;
V_119 = F_14 ( V_9 ) ;
V_119 = F_176 ( V_119 , V_152 ) ;
V_156 = ( V_119 - V_118 ) * sizeof( struct V_1 ) ;
V_549 = F_529 ( V_9 -> V_139 , V_156 ) ;
if ( ! V_549 )
V_549 = F_513 ( V_156 ,
V_9 -> V_139 ) ;
V_9 -> V_548 = V_549 + V_362 ;
}
#ifndef F_530
if ( V_9 == F_12 ( 0 ) ) {
V_550 = F_12 ( 0 ) -> V_548 ;
#if F_531 ( F_472 ) || F_531 ( V_551 )
if ( F_35 ( V_550 ) != V_9 -> V_145 )
V_550 -= V_362 ;
#endif
}
#endif
#endif
}
void T_16 F_532 ( int V_13 , unsigned long * V_522 ,
unsigned long V_145 , unsigned long * V_523 )
{
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_44 = 0 ;
unsigned long V_120 = 0 ;
F_4 ( V_9 -> V_434 || V_9 -> V_552 ) ;
F_8 ( V_9 ) ;
V_9 -> V_139 = V_13 ;
V_9 -> V_145 = V_145 ;
V_9 -> V_498 = NULL ;
#ifdef F_472
F_501 ( V_13 , & V_44 , & V_120 ) ;
F_71 ( L_96 , V_13 ,
( V_553 ) V_44 << V_17 ,
V_120 ? ( ( V_553 ) V_120 << V_17 ) - 1 : 0 ) ;
#else
V_44 = V_145 ;
#endif
F_509 ( V_9 , V_44 , V_120 ,
V_522 , V_523 ) ;
F_527 ( V_9 ) ;
#ifdef F_528
F_408 ( V_500 L_97 ,
V_13 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_548 ) ;
#endif
F_516 ( V_9 ) ;
}
void T_4 F_533 ( void )
{
unsigned int V_554 ;
V_554 = F_534 ( V_555 . V_556 , V_460 ) ;
V_557 = V_554 + 1 ;
}
unsigned long T_4 F_535 ( void )
{
unsigned long V_558 = 0 , V_504 = 0 ;
unsigned long V_118 , V_119 , V_26 ;
int V_505 = - 1 ;
int V_60 , V_13 ;
F_188 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_118 || V_505 < 0 || V_505 == V_13 ) {
V_505 = V_13 ;
V_504 = V_119 ;
continue;
}
V_26 = ~ ( ( 1 << F_536 ( V_118 ) ) - 1 ) ;
while ( V_26 && V_504 <= ( V_118 & ( V_26 << 1 ) ) )
V_26 <<= 1 ;
V_558 |= V_26 ;
}
return ~ V_558 + 1 ;
}
static unsigned long T_4 F_537 ( int V_13 )
{
unsigned long V_559 = V_11 ;
unsigned long V_44 ;
int V_60 ;
F_188 (i, nid, &start_pfn, NULL, NULL)
V_559 = F_177 ( V_559 , V_44 ) ;
if ( V_559 == V_11 ) {
F_329 ( L_98 , V_13 ) ;
return 0 ;
}
return V_559 ;
}
unsigned long T_4 F_538 ( void )
{
return F_537 ( V_460 ) ;
}
static unsigned long T_4 F_539 ( void )
{
unsigned long V_525 = 0 ;
unsigned long V_44 , V_120 ;
int V_60 , V_13 ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_173 = V_120 - V_44 ;
V_525 += V_173 ;
if ( V_173 )
F_540 ( V_13 , V_150 ) ;
}
return V_525 ;
}
static void T_4 F_541 ( void )
{
int V_60 , V_13 ;
unsigned long V_560 ;
unsigned long V_561 , V_562 ;
T_9 V_563 = V_564 [ V_150 ] ;
unsigned long V_525 = F_539 () ;
int V_565 = F_542 ( V_564 [ V_150 ] ) ;
struct V_488 * V_489 ;
F_502 () ;
if ( F_543 () ) {
F_476 (memory, r) {
if ( ! F_544 ( V_489 ) )
continue;
V_13 = V_489 -> V_13 ;
V_560 = F_157 ( V_489 -> V_566 ) ;
V_515 [ V_13 ] = V_515 [ V_13 ] ?
F_177 ( V_560 , V_515 [ V_13 ] ) :
V_560 ;
}
goto V_567;
}
if ( V_495 ) {
bool V_568 = false ;
F_476 (memory, r) {
if ( F_478 ( V_489 ) )
continue;
V_13 = V_489 -> V_13 ;
V_560 = F_477 ( V_489 ) ;
if ( V_560 < 0x100000 ) {
V_568 = true ;
continue;
}
V_515 [ V_13 ] = V_515 [ V_13 ] ?
F_177 ( V_560 , V_515 [ V_13 ] ) :
V_560 ;
}
if ( V_568 )
F_329 ( L_99 ) ;
goto V_567;
}
if ( V_569 ) {
unsigned long V_570 ;
V_569 =
F_511 ( V_569 , V_152 ) ;
V_569 = F_177 ( V_525 , V_569 ) ;
V_570 = V_525 - V_569 ;
V_571 = F_15 ( V_571 , V_570 ) ;
}
if ( ! V_571 || V_571 >= V_525 )
goto V_53;
V_560 = V_512 [ V_513 ] ;
V_572:
V_561 = V_571 / V_565 ;
F_195 (nid, N_MEMORY) {
unsigned long V_44 , V_120 ;
if ( V_571 < V_561 )
V_561 = V_571 / V_565 ;
V_562 = V_561 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_573 ;
V_44 = F_15 ( V_44 , V_515 [ V_13 ] ) ;
if ( V_44 >= V_120 )
continue;
if ( V_44 < V_560 ) {
unsigned long V_574 ;
V_574 = F_177 ( V_120 , V_560 )
- V_44 ;
V_562 -= F_177 ( V_574 ,
V_562 ) ;
V_571 -= F_177 ( V_574 ,
V_571 ) ;
if ( V_120 <= V_560 ) {
V_515 [ V_13 ] = V_120 ;
continue;
}
V_44 = V_560 ;
}
V_573 = V_120 - V_44 ;
if ( V_573 > V_562 )
V_573 = V_562 ;
V_515 [ V_13 ] = V_44 + V_573 ;
V_571 -= F_177 ( V_571 ,
V_573 ) ;
V_562 -= V_573 ;
if ( ! V_562 )
break;
}
}
V_565 -- ;
if ( V_565 && V_571 > V_565 )
goto V_572;
V_567:
for ( V_13 = 0 ; V_13 < V_460 ; V_13 ++ )
V_515 [ V_13 ] =
F_511 ( V_515 [ V_13 ] , V_152 ) ;
V_53:
V_564 [ V_150 ] = V_563 ;
}
static void F_545 ( T_1 * V_9 , int V_13 )
{
enum V_395 V_395 ;
if ( V_150 == V_575 )
return;
for ( V_395 = 0 ; V_395 <= V_496 - 1 ; V_395 ++ ) {
struct V_40 * V_40 = & V_9 -> V_117 [ V_395 ] ;
if ( F_190 ( V_40 ) ) {
F_540 ( V_13 , V_576 ) ;
if ( V_575 != V_576 &&
V_395 <= V_295 )
F_540 ( V_13 , V_575 ) ;
break;
}
}
}
void T_4 F_546 ( unsigned long * V_209 )
{
unsigned long V_44 , V_120 ;
int V_60 , V_13 ;
memset ( V_512 , 0 ,
sizeof( V_512 ) ) ;
memset ( V_511 , 0 ,
sizeof( V_511 ) ) ;
V_44 = F_538 () ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ ) {
if ( V_60 == V_496 )
continue;
V_120 = F_15 ( V_209 [ V_60 ] , V_44 ) ;
V_512 [ V_60 ] = V_44 ;
V_511 [ V_60 ] = V_120 ;
V_44 = V_120 ;
}
memset ( V_515 , 0 , sizeof( V_515 ) ) ;
F_541 () ;
F_71 ( L_100 ) ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ ) {
if ( V_60 == V_496 )
continue;
F_71 ( L_101 , V_482 [ V_60 ] ) ;
if ( V_512 [ V_60 ] ==
V_511 [ V_60 ] )
F_330 ( L_102 ) ;
else
F_330 ( L_103 ,
( V_553 ) V_512 [ V_60 ]
<< V_17 ,
( ( V_553 ) V_511 [ V_60 ]
<< V_17 ) - 1 ) ;
}
F_71 ( L_104 ) ;
for ( V_60 = 0 ; V_60 < V_460 ; V_60 ++ ) {
if ( V_515 [ V_60 ] )
F_71 ( L_105 , V_60 ,
( V_553 ) V_515 [ V_60 ] << V_17 ) ;
}
F_71 ( L_106 ) ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_71 ( L_107 , V_13 ,
( V_553 ) V_44 << V_17 ,
( ( V_553 ) V_120 << V_17 ) - 1 ) ;
F_547 () ;
F_533 () ;
F_455 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_532 ( V_13 , NULL ,
F_537 ( V_13 ) , NULL ) ;
if ( V_9 -> V_527 )
F_540 ( V_13 , V_150 ) ;
F_545 ( V_9 , V_13 ) ;
}
}
static int T_4 F_548 ( char * V_63 , unsigned long * V_577 )
{
unsigned long long V_578 ;
if ( ! V_63 )
return - V_67 ;
V_578 = F_549 ( V_63 , & V_63 ) ;
* V_577 = V_578 >> V_17 ;
F_4 ( ( V_578 >> V_17 ) > V_11 ) ;
return 0 ;
}
static int T_4 F_550 ( char * V_63 )
{
if ( F_551 ( V_63 , L_108 ) ) {
V_495 = true ;
return 0 ;
}
return F_548 ( V_63 , & V_571 ) ;
}
static int T_4 F_552 ( char * V_63 )
{
return F_548 ( V_63 , & V_569 ) ;
}
void F_201 ( struct V_1 * V_1 , long V_102 )
{
F_137 ( & V_579 ) ;
F_19 ( V_1 ) -> V_123 += V_102 ;
V_386 += V_102 ;
#ifdef F_418
if ( F_126 ( V_1 ) )
V_392 += V_102 ;
#endif
F_143 ( & V_579 ) ;
}
unsigned long F_553 ( void * V_118 , void * V_119 , int V_580 , char * V_436 )
{
void * V_467 ;
unsigned long V_173 = 0 ;
V_118 = ( void * ) F_396 ( ( unsigned long ) V_118 ) ;
V_119 = ( void * ) ( ( unsigned long ) V_119 & V_581 ) ;
for ( V_467 = V_118 ; V_467 < V_119 ; V_467 += V_101 , V_173 ++ ) {
if ( ( unsigned int ) V_580 <= 0xFF )
memset ( V_467 , V_580 , V_101 ) ;
F_554 ( F_281 ( V_467 ) ) ;
}
if ( V_173 && V_436 )
F_71 ( L_109 ,
V_436 , V_173 << ( V_17 - 10 ) ) ;
return V_173 ;
}
void F_555 ( struct V_1 * V_1 )
{
F_556 ( V_1 ) ;
V_386 ++ ;
F_19 ( V_1 ) -> V_123 ++ ;
V_392 ++ ;
}
void T_4 F_557 ( const char * V_229 )
{
unsigned long V_582 , V_583 , V_584 , V_585 , V_586 ;
unsigned long V_587 , V_588 ;
V_582 = F_558 () ;
V_583 = V_589 - V_590 ;
V_584 = V_591 - V_592 ;
V_585 = V_593 - V_594 ;
V_586 = V_595 - V_596 ;
V_588 = V_597 - V_598 ;
V_587 = V_599 - V_600 ;
#define F_559 ( V_118 , V_119 , V_156 , V_467 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_559 ( V_598 , V_597 , V_588 ,
V_600 , V_587 ) ;
F_559 ( V_590 , V_589 , V_583 , V_600 , V_587 ) ;
F_559 ( V_592 , V_591 , V_584 , V_598 , V_588 ) ;
F_559 ( V_590 , V_589 , V_583 , V_594 , V_585 ) ;
F_559 ( V_592 , V_591 , V_584 , V_594 , V_585 ) ;
#undef F_559
F_71 ( L_110
#ifdef F_418
L_111
#endif
L_112 ,
F_560 () << ( V_17 - 10 ) ,
V_582 << ( V_17 - 10 ) ,
V_583 >> 10 , V_584 >> 10 , V_585 >> 10 ,
( V_588 + V_587 ) >> 10 , V_586 >> 10 ,
( V_582 - V_386 - V_601 ) << ( V_17 - 10 ) ,
V_601 << ( V_17 - 10 ) ,
#ifdef F_418
V_392 << ( V_17 - 10 ) ,
#endif
V_229 ? L_113 : L_114 , V_229 ? V_229 : L_114 ) ;
}
void T_4 F_561 ( unsigned long V_602 )
{
V_545 = V_602 ;
}
void T_4 F_562 ( unsigned long * V_522 )
{
F_532 ( 0 , V_522 ,
F_563 ( V_603 ) >> V_17 , NULL ) ;
}
static int F_564 ( unsigned int V_197 )
{
F_565 ( V_197 ) ;
F_247 ( V_197 ) ;
F_566 ( V_197 ) ;
F_567 ( V_197 ) ;
return 0 ;
}
void T_4 F_568 ( void )
{
int V_41 ;
V_41 = F_569 ( V_604 ,
L_115 , NULL ,
F_564 ) ;
F_4 ( V_41 < 0 ) ;
}
static void F_570 ( void )
{
struct V_258 * V_9 ;
unsigned long V_605 = 0 ;
enum V_395 V_60 , V_462 ;
F_425 (pgdat) {
V_9 -> V_379 = 0 ;
for ( V_60 = 0 ; V_60 < V_116 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_60 ;
long F_15 = 0 ;
for ( V_462 = V_60 ; V_462 < V_116 ; V_462 ++ ) {
if ( V_40 -> V_252 [ V_462 ] > F_15 )
F_15 = V_40 -> V_252 [ V_462 ] ;
}
F_15 += F_404 ( V_40 ) ;
if ( F_15 > V_40 -> V_123 )
F_15 = V_40 -> V_123 ;
V_9 -> V_379 += F_15 ;
V_605 += F_15 ;
}
}
V_379 = V_605 ;
}
static void F_571 ( void )
{
struct V_258 * V_9 ;
enum V_395 V_462 , V_606 ;
F_425 (pgdat) {
for ( V_462 = 0 ; V_462 < V_116 ; V_462 ++ ) {
struct V_40 * V_40 = V_9 -> V_117 + V_462 ;
unsigned long V_123 = V_40 -> V_123 ;
V_40 -> V_252 [ V_462 ] = 0 ;
V_606 = V_462 ;
while ( V_606 ) {
struct V_40 * V_607 ;
V_606 -- ;
if ( V_608 [ V_606 ] < 1 )
V_608 [ V_606 ] = 1 ;
V_607 = V_9 -> V_117 + V_606 ;
V_607 -> V_252 [ V_462 ] = V_123 /
V_608 [ V_606 ] ;
V_123 += V_607 -> V_123 ;
}
}
}
F_570 () ;
}
static void F_572 ( void )
{
unsigned long V_609 = V_610 >> ( V_17 - 10 ) ;
unsigned long V_611 = 0 ;
struct V_40 * V_40 ;
unsigned long V_34 ;
F_411 (zone) {
if ( ! F_419 ( V_40 ) )
V_611 += V_40 -> V_123 ;
}
F_411 (zone) {
V_553 V_400 ;
F_232 ( & V_40 -> V_108 , V_34 ) ;
V_400 = ( V_553 ) V_609 * V_40 -> V_123 ;
F_573 ( V_400 , V_611 ) ;
if ( F_419 ( V_40 ) ) {
unsigned long V_612 ;
V_612 = V_40 -> V_123 / 1024 ;
V_612 = F_506 ( V_612 , V_613 , 128UL ) ;
V_40 -> V_213 [ V_614 ] = V_612 ;
} else {
V_40 -> V_213 [ V_614 ] = V_400 ;
}
V_400 = F_574 ( V_553 , V_400 >> 2 ,
F_575 ( V_40 -> V_123 ,
V_615 , 10000 ) ) ;
V_40 -> V_213 [ V_378 ] = F_284 ( V_40 ) + V_400 ;
V_40 -> V_213 [ V_616 ] = F_284 ( V_40 ) + V_400 * 2 ;
F_234 ( & V_40 -> V_108 , V_34 ) ;
}
F_570 () ;
}
void F_576 ( void )
{
F_256 ( & V_452 ) ;
F_572 () ;
F_264 ( & V_452 ) ;
}
int T_2 F_577 ( void )
{
unsigned long V_617 ;
int V_618 ;
V_617 = F_405 () * ( V_101 >> 10 ) ;
V_618 = F_578 ( V_617 * 16 ) ;
if ( V_618 > V_619 ) {
V_610 = V_618 ;
if ( V_610 < 128 )
V_610 = 128 ;
if ( V_610 > 65536 )
V_610 = 65536 ;
} else {
F_329 ( L_116 ,
V_618 , V_619 ) ;
}
F_576 () ;
F_579 () ;
F_571 () ;
#ifdef F_287
F_580 () ;
F_581 () ;
#endif
return 0 ;
}
int F_582 ( struct V_443 * V_444 , int V_445 ,
void T_12 * V_446 , T_11 * V_447 , T_13 * V_448 )
{
int V_620 ;
V_620 = F_583 ( V_444 , V_445 , V_446 , V_447 , V_448 ) ;
if ( V_620 )
return V_620 ;
if ( V_445 ) {
V_619 = V_610 ;
F_576 () ;
}
return 0 ;
}
int F_584 ( struct V_443 * V_444 , int V_445 ,
void T_12 * V_446 , T_11 * V_447 , T_13 * V_448 )
{
int V_620 ;
V_620 = F_583 ( V_444 , V_445 , V_446 , V_447 , V_448 ) ;
if ( V_620 )
return V_620 ;
if ( V_445 )
F_576 () ;
return 0 ;
}
static void F_580 ( void )
{
T_1 * V_9 ;
struct V_40 * V_40 ;
F_425 (pgdat)
V_9 -> V_621 = 0 ;
F_411 (zone)
V_40 -> V_109 -> V_621 += ( V_40 -> V_123 *
V_622 ) / 100 ;
}
int F_585 ( struct V_443 * V_444 , int V_445 ,
void T_12 * V_446 , T_11 * V_447 , T_13 * V_448 )
{
int V_620 ;
V_620 = F_583 ( V_444 , V_445 , V_446 , V_447 , V_448 ) ;
if ( V_620 )
return V_620 ;
F_580 () ;
return 0 ;
}
static void F_581 ( void )
{
T_1 * V_9 ;
struct V_40 * V_40 ;
F_425 (pgdat)
V_9 -> V_623 = 0 ;
F_411 (zone)
V_40 -> V_109 -> V_623 += ( V_40 -> V_123 *
V_624 ) / 100 ;
}
int F_586 ( struct V_443 * V_444 , int V_445 ,
void T_12 * V_446 , T_11 * V_447 , T_13 * V_448 )
{
int V_620 ;
V_620 = F_583 ( V_444 , V_445 , V_446 , V_447 , V_448 ) ;
if ( V_620 )
return V_620 ;
F_581 () ;
return 0 ;
}
int F_587 ( struct V_443 * V_444 , int V_445 ,
void T_12 * V_446 , T_11 * V_447 , T_13 * V_448 )
{
F_583 ( V_444 , V_445 , V_446 , V_447 , V_448 ) ;
F_571 () ;
return 0 ;
}
int F_588 ( struct V_443 * V_444 , int V_445 ,
void T_12 * V_446 , T_11 * V_447 , T_13 * V_448 )
{
struct V_40 * V_40 ;
int V_625 ;
int V_41 ;
F_256 ( & V_626 ) ;
V_625 = V_497 ;
V_41 = F_583 ( V_444 , V_445 , V_446 , V_447 , V_448 ) ;
if ( ! V_445 || V_41 < 0 )
goto V_53;
if ( V_497 &&
V_497 < V_627 ) {
V_497 = V_625 ;
V_41 = - V_67 ;
goto V_53;
}
if ( V_497 == V_625 )
goto V_53;
F_199 (zone) {
unsigned int V_197 ;
F_456 (cpu)
F_488 ( V_40 ,
F_246 ( V_40 -> V_200 , V_197 ) ) ;
}
V_53:
F_264 ( & V_626 ) ;
return V_41 ;
}
static int T_4 F_589 ( char * V_229 )
{
if ( ! V_229 )
return 0 ;
V_628 = F_590 ( V_229 , & V_229 , 0 ) ;
return 1 ;
}
static unsigned long T_4 F_591 ( void )
{
return 0 ;
}
void * T_4 F_592 ( const char * V_629 ,
unsigned long V_630 ,
unsigned long V_631 ,
int V_632 ,
int V_34 ,
unsigned int * V_633 ,
unsigned int * V_634 ,
unsigned long V_635 ,
unsigned long V_636 )
{
unsigned long long F_15 = V_636 ;
unsigned long V_637 , V_156 ;
void * V_444 = NULL ;
if ( ! V_631 ) {
V_631 = V_546 ;
V_631 -= F_591 () ;
if ( V_17 < 20 )
V_631 = F_593 ( V_631 , ( 1 << 20 ) / V_101 ) ;
if ( V_632 > V_17 )
V_631 >>= ( V_632 - V_17 ) ;
else
V_631 <<= ( V_17 - V_632 ) ;
if ( F_32 ( V_34 & V_638 ) ) {
F_4 ( ! ( V_34 & V_639 ) ) ;
if ( ! ( V_631 >> * V_633 ) ) {
V_631 = 1UL << * V_633 ;
F_187 ( ! V_631 ) ;
}
} else if ( F_32 ( ( V_631 * V_630 ) < V_101 ) )
V_631 = V_101 / V_630 ;
}
V_631 = F_594 ( V_631 ) ;
if ( F_15 == 0 ) {
F_15 = ( ( unsigned long long ) V_547 << V_17 ) >> 4 ;
F_573 ( F_15 , V_630 ) ;
}
F_15 = F_177 ( F_15 , 0x80000000ULL ) ;
if ( V_631 < V_635 )
V_631 = V_635 ;
if ( V_631 > F_15 )
V_631 = F_15 ;
V_637 = F_595 ( V_631 ) ;
do {
V_156 = V_630 << V_637 ;
if ( V_34 & V_639 )
V_444 = F_596 ( V_156 , 0 ) ;
else if ( V_628 )
V_444 = F_597 ( V_156 , V_640 , V_641 ) ;
else {
if ( F_399 ( V_156 ) < V_71 ) {
V_444 = F_398 ( V_156 , V_640 ) ;
F_598 ( V_444 , V_156 , 1 , V_640 ) ;
}
}
} while ( ! V_444 && V_156 > V_101 && -- V_637 );
if ( ! V_444 )
F_599 ( L_117 , V_629 ) ;
F_71 ( L_118 ,
V_629 , 1UL << V_637 , F_595 ( V_156 ) - V_17 , V_156 ) ;
if ( V_633 )
* V_633 = V_637 ;
if ( V_634 )
* V_634 = ( 1 << V_637 ) - 1 ;
return V_444 ;
}
bool F_600 ( struct V_40 * V_40 , struct V_1 * V_1 , int V_102 ,
bool V_642 )
{
unsigned long V_12 , V_643 , V_644 ;
int V_114 ;
if ( V_433 ( V_40 ) == V_496 )
return false ;
V_114 = F_100 ( V_1 ) ;
if ( V_114 == V_135 || F_233 ( V_114 ) )
return false ;
V_12 = F_35 ( V_1 ) ;
for ( V_644 = 0 , V_643 = 0 ; V_643 < V_24 ; V_643 ++ ) {
unsigned long V_645 = V_12 + V_643 ;
if ( ! F_41 ( V_645 ) )
continue;
V_1 = F_153 ( V_645 ) ;
if ( F_601 ( V_1 ) ) {
V_643 = F_593 ( V_643 + 1 , 1 << F_54 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_105 ( V_1 ) ) {
if ( F_91 ( V_1 ) )
V_643 += ( 1 << F_88 ( V_1 ) ) - 1 ;
continue;
}
if ( V_642 && F_602 ( V_1 ) )
continue;
if ( F_603 ( V_1 ) )
continue;
if ( ! F_604 ( V_1 ) )
V_644 ++ ;
if ( V_644 > V_102 )
return true ;
}
return false ;
}
bool F_605 ( struct V_1 * V_1 )
{
struct V_40 * V_40 ;
unsigned long V_12 ;
if ( ! F_11 ( F_224 ( V_1 ) ) )
return false ;
V_40 = F_19 ( V_1 ) ;
V_12 = F_35 ( V_1 ) ;
if ( ! F_28 ( V_40 , V_12 ) )
return false ;
return ! F_600 ( V_40 , V_1 , 0 , true ) ;
}
static unsigned long F_606 ( unsigned long V_12 )
{
return V_12 & ~ ( F_574 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_607 ( unsigned long V_12 )
{
return F_176 ( V_12 , F_574 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_608 ( struct V_646 * V_647 ,
unsigned long V_118 , unsigned long V_119 )
{
unsigned long V_648 ;
unsigned long V_12 = V_118 ;
unsigned int V_649 = 0 ;
int V_41 = 0 ;
F_609 () ;
while ( V_12 < V_119 || ! F_140 ( & V_647 -> V_650 ) ) {
if ( F_610 ( V_55 ) ) {
V_41 = - V_651 ;
break;
}
if ( F_140 ( & V_647 -> V_650 ) ) {
V_647 -> V_652 = 0 ;
V_12 = F_611 ( V_647 , V_12 , V_119 ) ;
if ( ! V_12 ) {
V_41 = - V_651 ;
break;
}
V_649 = 0 ;
} else if ( ++ V_649 == 5 ) {
V_41 = V_41 < 0 ? V_41 : - V_653 ;
break;
}
V_648 = F_612 ( V_647 -> V_40 ,
& V_647 -> V_650 ) ;
V_647 -> V_652 -= V_648 ;
V_41 = F_613 ( & V_647 -> V_650 , V_654 ,
NULL , 0 , V_647 -> V_238 , V_655 ) ;
}
if ( V_41 < 0 ) {
F_614 ( & V_647 -> V_650 ) ;
return V_41 ;
}
return 0 ;
}
int F_615 ( unsigned long V_118 , unsigned long V_119 ,
unsigned V_3 , T_6 V_232 )
{
unsigned long V_656 , V_657 ;
unsigned int V_59 ;
int V_41 = 0 ;
struct V_646 V_647 = {
. V_652 = 0 ,
. V_59 = - 1 ,
. V_40 = F_19 ( F_153 ( V_118 ) ) ,
. V_238 = V_658 ,
. V_659 = true ,
. V_232 = F_377 ( V_232 ) ,
} ;
F_76 ( & V_647 . V_650 ) ;
V_41 = F_616 ( F_606 ( V_118 ) ,
F_607 ( V_119 ) , V_3 ,
false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_608 ( & V_647 , V_118 , V_119 ) ;
if ( V_41 && V_41 != - V_653 )
goto V_660;
F_617 () ;
F_253 ( V_647 . V_40 ) ;
V_59 = 0 ;
V_656 = V_118 ;
while ( ! F_91 ( F_153 ( V_656 ) ) ) {
if ( ++ V_59 >= V_71 ) {
V_656 = V_118 ;
break;
}
V_656 &= ~ 0UL << V_59 ;
}
if ( V_656 != V_118 ) {
V_59 = F_88 ( F_153 ( V_656 ) ) ;
if ( V_656 + ( 1UL << V_59 ) <= V_118 )
V_656 = V_118 ;
}
if ( F_618 ( V_656 , V_119 , false ) ) {
F_71 ( L_119 ,
V_661 , V_656 , V_119 ) ;
V_41 = - V_653 ;
goto V_660;
}
V_657 = F_619 ( & V_647 , V_656 , V_119 ) ;
if ( ! V_657 ) {
V_41 = - V_653 ;
goto V_660;
}
if ( V_118 != V_656 )
F_620 ( V_656 , V_118 - V_656 ) ;
if ( V_119 != V_657 )
F_620 ( V_119 , V_657 - V_119 ) ;
V_660:
F_621 ( F_606 ( V_118 ) ,
F_607 ( V_119 ) , V_3 ) ;
return V_41 ;
}
void F_620 ( unsigned long V_12 , unsigned V_61 )
{
unsigned int V_102 = 0 ;
for (; V_61 -- ; V_12 ++ ) {
struct V_1 * V_1 = F_153 ( V_12 ) ;
V_102 += F_90 ( V_1 ) != 1 ;
F_622 ( V_1 ) ;
}
F_623 ( V_102 != 0 , L_120 , V_102 ) ;
}
void T_2 F_624 ( struct V_40 * V_40 )
{
unsigned V_197 ;
F_256 ( & V_626 ) ;
F_456 (cpu)
F_488 ( V_40 ,
F_246 ( V_40 -> V_200 , V_197 ) ) ;
F_264 ( & V_626 ) ;
}
void F_625 ( struct V_40 * V_40 )
{
unsigned long V_34 ;
int V_197 ;
struct V_198 * V_199 ;
F_161 ( V_34 ) ;
if ( V_40 -> V_200 != & V_477 ) {
F_257 (cpu) {
V_199 = F_246 ( V_40 -> V_200 , V_197 ) ;
F_626 ( V_40 , V_199 ) ;
}
F_627 ( V_40 -> V_200 ) ;
V_40 -> V_200 = & V_477 ;
}
F_163 ( V_34 ) ;
}
void
F_628 ( unsigned long V_44 , unsigned long V_120 )
{
struct V_1 * V_1 ;
struct V_40 * V_40 ;
unsigned int V_59 , V_60 ;
unsigned long V_12 ;
unsigned long V_34 ;
for ( V_12 = V_44 ; V_12 < V_120 ; V_12 ++ )
if ( F_159 ( V_12 ) )
break;
if ( V_12 == V_120 )
return;
V_40 = F_19 ( F_153 ( V_12 ) ) ;
F_232 ( & V_40 -> V_108 , V_34 ) ;
V_12 = V_44 ;
while ( V_12 < V_120 ) {
if ( ! F_159 ( V_12 ) ) {
V_12 ++ ;
continue;
}
V_1 = F_153 ( V_12 ) ;
if ( F_32 ( ! F_91 ( V_1 ) && F_602 ( V_1 ) ) ) {
V_12 ++ ;
F_160 ( V_1 ) ;
continue;
}
F_187 ( F_90 ( V_1 ) ) ;
F_187 ( ! F_91 ( V_1 ) ) ;
V_59 = F_88 ( V_1 ) ;
#ifdef V_97
F_71 ( L_121 ,
V_12 , 1 << V_59 , V_120 ) ;
#endif
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
V_40 -> V_84 [ V_59 ] . V_85 -- ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_160 ( ( V_1 + V_60 ) ) ;
V_12 += ( 1 << V_59 ) ;
}
F_234 ( & V_40 -> V_108 , V_34 ) ;
}
bool F_629 ( struct V_1 * V_1 )
{
struct V_40 * V_40 = F_19 ( V_1 ) ;
unsigned long V_12 = F_35 ( V_1 ) ;
unsigned long V_34 ;
unsigned int V_59 ;
F_232 ( & V_40 -> V_108 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_1 * V_662 = V_1 - ( V_12 & ( ( 1 << V_59 ) - 1 ) ) ;
if ( F_91 ( V_662 ) && F_88 ( V_662 ) >= V_59 )
break;
}
F_234 ( & V_40 -> V_108 , V_34 ) ;
return V_59 < V_71 ;
}
