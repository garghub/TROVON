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
if ( ! F_41 ( F_35 ( V_76 ) ) )
return 0 ;
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
unsigned long V_78 ;
unsigned long V_79 ( V_80 ) ;
struct V_1 * V_76 ;
unsigned int V_81 ;
V_81 = F_93 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
F_94 ( ! F_95 ( V_40 ) ) ;
F_27 ( V_1 -> V_34 & V_82 , V_1 ) ;
F_94 ( V_3 == - 1 ) ;
if ( F_96 ( ! F_81 ( V_3 ) ) )
F_78 ( V_40 , 1 << V_59 , V_3 ) ;
V_77 = V_12 & ( ( 1 << V_71 ) - 1 ) ;
F_27 ( V_77 & ( ( 1 << V_59 ) - 1 ) , V_1 ) ;
F_27 ( F_42 ( V_40 , V_1 ) , V_1 ) ;
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
if ( F_32 ( F_99 ( V_40 ) ) ) {
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
if ( ( V_59 < V_71 - 2 ) && F_41 ( F_35 ( V_76 ) ) ) {
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
if ( F_32 ( F_104 ( & V_1 -> V_92 ) != - 1 ) )
return false ;
if ( F_32 ( ( unsigned long ) V_1 -> V_64 |
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
if ( F_32 ( F_104 ( & V_1 -> V_92 ) != - 1 ) )
V_94 = L_7 ;
if ( F_32 ( V_1 -> V_64 != NULL ) )
V_94 = L_8 ;
if ( F_32 ( F_105 ( V_1 ) != 0 ) )
V_94 = L_9 ;
if ( F_32 ( V_1 -> V_34 & V_95 ) ) {
V_94 = L_10 ;
V_48 = V_95 ;
}
#ifdef F_106
if ( F_32 ( V_1 -> V_93 ) )
V_94 = L_11 ;
#endif
F_43 ( V_1 , V_94 , V_48 ) ;
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
F_26 ( ( unsigned long ) V_97 & 1 ) ;
if ( ! F_110 ( V_98 ) ) {
V_41 = 0 ;
goto V_53;
}
switch ( V_1 - V_96 ) {
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
if ( F_32 ( F_113 ( V_1 ) != V_96 ) ) {
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
unsigned int V_59 , bool V_99 )
{
int V_100 = 0 ;
F_27 ( F_112 ( V_1 ) , V_1 ) ;
F_116 ( V_1 , V_59 ) ;
F_117 ( V_1 , V_59 ) ;
if ( F_32 ( V_59 ) ) {
bool V_101 = F_118 ( V_1 ) ;
int V_60 ;
F_27 ( V_101 && F_54 ( V_1 ) != V_59 , V_1 ) ;
if ( V_101 )
F_119 ( V_1 ) ;
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
if ( V_101 )
V_100 += F_109 ( V_1 , V_1 + V_60 ) ;
if ( F_32 ( F_108 ( V_1 + V_60 ) ) ) {
V_100 ++ ;
continue;
}
( V_1 + V_60 ) -> V_34 &= ~ V_82 ;
}
}
if ( F_120 ( V_1 ) )
V_1 -> V_64 = NULL ;
if ( F_121 () && F_122 ( V_1 ) )
F_123 ( V_1 , V_59 ) ;
if ( V_99 )
V_100 += F_108 ( V_1 ) ;
if ( V_100 )
return false ;
F_124 ( V_1 ) ;
V_1 -> V_34 &= ~ V_82 ;
F_125 ( V_1 , V_59 ) ;
if ( ! F_126 ( V_1 ) ) {
F_127 ( F_128 ( V_1 ) ,
V_102 << V_59 ) ;
F_129 ( F_128 ( V_1 ) ,
V_102 << V_59 ) ;
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
static void F_136 ( struct V_40 * V_40 , int V_103 ,
struct V_104 * V_105 )
{
int V_3 = 0 ;
int V_106 = 0 ;
unsigned long V_107 ;
bool V_108 ;
F_137 ( & V_40 -> V_109 ) ;
V_108 = F_99 ( V_40 ) ;
V_107 = F_138 ( V_40 -> V_110 , V_111 ) ;
if ( V_107 )
F_139 ( V_40 -> V_110 , V_111 , - V_107 ) ;
while ( V_103 ) {
struct V_1 * V_1 ;
struct V_112 * V_113 ;
do {
V_106 ++ ;
if ( ++ V_3 == V_37 )
V_3 = 0 ;
V_113 = & V_105 -> V_114 [ V_3 ] ;
} while ( F_140 ( V_113 ) );
if ( V_106 == V_37 )
V_106 = V_103 ;
do {
int V_115 ;
V_1 = F_141 ( V_113 , struct V_1 , V_75 ) ;
F_98 ( & V_1 -> V_75 ) ;
V_115 = F_1 ( V_1 ) ;
F_27 ( F_81 ( V_115 ) , V_1 ) ;
if ( F_32 ( V_108 ) )
V_115 = F_100 ( V_1 ) ;
if ( F_135 ( V_1 ) )
continue;
F_92 ( V_1 , F_35 ( V_1 ) , V_40 , 0 , V_115 ) ;
F_142 ( V_1 , 0 , V_115 ) ;
} while ( -- V_103 && -- V_106 && ! F_140 ( V_113 ) );
}
F_143 ( & V_40 -> V_109 ) ;
}
static void F_144 ( struct V_40 * V_40 ,
struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_59 ,
int V_3 )
{
unsigned long V_107 ;
F_137 ( & V_40 -> V_109 ) ;
V_107 = F_138 ( V_40 -> V_110 , V_111 ) ;
if ( V_107 )
F_139 ( V_40 -> V_110 , V_111 , - V_107 ) ;
if ( F_32 ( F_99 ( V_40 ) ||
F_81 ( V_3 ) ) ) {
V_3 = F_24 ( V_1 , V_12 ) ;
}
F_92 ( V_1 , V_12 , V_40 , V_59 , V_3 ) ;
F_143 ( & V_40 -> V_109 ) ;
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
int V_13 , V_116 ;
if ( ! F_9 ( V_12 ) )
return;
V_13 = F_10 ( V_12 ) ;
V_9 = F_12 ( V_13 ) ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
struct V_40 * V_40 = & V_9 -> V_118 [ V_116 ] ;
if ( V_12 >= V_40 -> V_23 && V_12 < F_155 ( V_40 ) )
break;
}
F_152 ( V_12 , V_116 , V_13 ) ;
}
static inline void F_154 ( unsigned long V_12 )
{
}
void T_2 F_156 ( T_5 V_119 , T_5 V_120 )
{
unsigned long V_44 = F_157 ( V_119 ) ;
unsigned long V_121 = F_158 ( V_120 ) ;
for (; V_44 < V_121 ; V_44 ++ ) {
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
F_162 ( V_122 , 1 << V_59 ) ;
F_144 ( F_19 ( V_1 ) , V_1 , V_12 , V_59 , V_3 ) ;
F_163 ( V_34 ) ;
}
static void T_4 F_164 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned int V_61 = 1 << V_59 ;
struct V_1 * V_63 = V_1 ;
unsigned int V_123 ;
F_165 ( V_63 ) ;
for ( V_123 = 0 ; V_123 < ( V_61 - 1 ) ; V_123 ++ , V_63 ++ ) {
F_165 ( V_63 + 1 ) ;
F_166 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
}
F_166 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
F_19 ( V_1 ) -> V_124 += V_61 ;
F_167 ( V_1 ) ;
F_168 ( V_1 , V_59 ) ;
}
int T_2 F_10 ( unsigned long V_12 )
{
static F_169 ( V_125 ) ;
int V_13 ;
F_137 ( & V_125 ) ;
V_13 = F_170 ( V_12 , & V_126 ) ;
if ( V_13 < 0 )
V_13 = V_127 ;
F_143 ( & V_125 ) ;
return V_13 ;
}
static inline bool T_2 F_171 ( unsigned long V_12 , int V_128 ,
struct V_129 * V_130 )
{
int V_13 ;
V_13 = F_170 ( V_12 , V_130 ) ;
if ( V_13 >= 0 && V_13 != V_128 )
return false ;
return true ;
}
static inline bool T_2 F_172 ( unsigned long V_12 , int V_128 )
{
return F_171 ( V_12 , V_128 , & V_126 ) ;
}
static inline bool T_2 F_172 ( unsigned long V_12 , int V_128 )
{
return true ;
}
static inline bool T_2 F_171 ( unsigned long V_12 , int V_128 ,
struct V_129 * V_130 )
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
unsigned long V_121 , struct V_40 * V_40 )
{
struct V_1 * V_131 ;
struct V_1 * V_132 ;
V_121 -- ;
if ( ! F_159 ( V_44 ) || ! F_159 ( V_121 ) )
return NULL ;
V_131 = F_153 ( V_44 ) ;
if ( F_19 ( V_131 ) != V_40 )
return NULL ;
V_132 = F_153 ( V_121 ) ;
if ( F_89 ( V_131 ) != F_89 ( V_132 ) )
return NULL ;
return V_131 ;
}
void F_175 ( struct V_40 * V_40 )
{
unsigned long V_133 = V_40 -> V_23 ;
unsigned long V_134 ;
V_134 = F_176 ( V_133 + 1 , V_24 ) ;
for (; V_133 < F_155 ( V_40 ) ;
V_133 = V_134 ,
V_134 += V_24 ) {
V_134 = F_177 ( V_134 , F_155 ( V_40 ) ) ;
if ( ! F_174 ( V_133 ,
V_134 , V_40 ) )
return;
}
V_40 -> V_135 = true ;
}
void F_178 ( struct V_40 * V_40 )
{
V_40 -> V_135 = false ;
}
static void T_4 F_179 ( struct V_1 * V_1 ,
unsigned long V_12 , int V_61 )
{
int V_60 ;
if ( ! V_1 )
return;
if ( V_61 == V_24 &&
( V_12 & ( V_24 - 1 ) ) == 0 ) {
F_31 ( V_1 , V_136 ) ;
F_164 ( V_1 , V_21 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ , V_1 ++ , V_12 ++ ) {
if ( ( V_12 & ( V_24 - 1 ) ) == 0 )
F_31 ( V_1 , V_136 ) ;
F_164 ( V_1 , 0 ) ;
}
}
static inline void T_4 F_180 ( void )
{
if ( F_181 ( & V_137 ) )
F_182 ( & V_138 ) ;
}
static int T_4 F_183 ( void * V_139 )
{
T_1 * V_9 = V_139 ;
int V_13 = V_9 -> V_140 ;
struct V_129 V_141 = { } ;
unsigned long V_119 = V_52 ;
unsigned long V_61 = 0 ;
unsigned long V_142 , V_143 ;
int V_60 , V_116 ;
struct V_40 * V_40 ;
unsigned long V_144 = V_9 -> V_10 ;
const struct V_145 * V_145 = F_184 ( V_9 -> V_140 ) ;
if ( V_144 == V_11 ) {
F_180 () ;
return 0 ;
}
if ( ! F_185 ( V_145 ) )
F_186 ( V_55 , V_145 ) ;
F_187 ( V_9 -> V_10 < V_9 -> V_146 ) ;
F_187 ( V_9 -> V_10 > F_14 ( V_9 ) ) ;
V_9 -> V_10 = V_11 ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
V_40 = V_9 -> V_118 + V_116 ;
if ( V_144 < F_155 ( V_40 ) )
break;
}
F_188 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_12 , V_121 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_147 = NULL ;
unsigned long V_148 = 0 ;
int V_149 = 0 ;
V_121 = F_177 ( V_143 , F_155 ( V_40 ) ) ;
V_12 = V_144 ;
if ( V_12 < V_142 )
V_12 = V_142 ;
if ( V_12 < V_40 -> V_23 )
V_12 = V_40 -> V_23 ;
for (; V_12 < V_121 ; V_12 ++ ) {
if ( ! F_41 ( V_12 ) )
goto V_150;
if ( ( V_12 & ( V_24 - 1 ) ) == 0 ) {
if ( ! F_159 ( V_12 ) ) {
V_1 = NULL ;
goto V_150;
}
}
if ( ! F_171 ( V_12 , V_13 , & V_141 ) ) {
V_1 = NULL ;
goto V_150;
}
if ( V_1 && ( V_12 & ( V_24 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_61 += V_149 ;
F_179 ( V_147 ,
V_148 , V_149 ) ;
V_147 = NULL ;
V_148 = V_149 = 0 ;
V_1 = F_153 ( V_12 ) ;
F_189 () ;
}
if ( V_1 -> V_34 ) {
F_94 ( F_19 ( V_1 ) != V_40 ) ;
goto V_150;
}
F_145 ( V_1 , V_12 , V_116 , V_13 ) ;
if ( ! V_147 ) {
V_147 = V_1 ;
V_148 = V_12 ;
V_149 = 0 ;
}
V_149 ++ ;
continue;
V_150:
V_61 += V_149 ;
F_179 ( V_147 , V_148 ,
V_149 ) ;
V_147 = NULL ;
V_148 = V_149 = 0 ;
}
V_61 += V_149 ;
F_179 ( V_147 , V_148 , V_149 ) ;
V_144 = F_15 ( V_121 , V_144 ) ;
}
F_4 ( ++ V_116 < V_117 && F_190 ( ++ V_40 ) ) ;
F_71 ( L_16 , V_13 , V_61 ,
F_191 ( V_52 - V_119 ) ) ;
F_180 () ;
return 0 ;
}
void T_4 F_192 ( void )
{
struct V_40 * V_40 ;
#ifdef F_193
int V_13 ;
F_61 ( & V_137 , F_194 ( V_151 ) ) ;
F_195 (nid, N_MEMORY) {
F_196 ( F_183 , F_12 ( V_13 ) , L_17 , V_13 ) ;
}
F_197 ( & V_138 ) ;
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
F_31 ( V_1 , V_152 ) ;
if ( V_21 >= V_71 ) {
V_60 = V_24 ;
V_63 = V_1 ;
do {
F_167 ( V_63 ) ;
F_168 ( V_63 , V_71 - 1 ) ;
V_63 += V_153 ;
} while ( V_60 -= V_153 );
} else {
F_167 ( V_1 ) ;
F_168 ( V_1 , V_21 ) ;
}
F_201 ( V_1 , V_24 ) ;
}
static inline void F_202 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_154 , int V_155 , struct V_85 * V_156 ,
int V_3 )
{
unsigned long V_157 = 1 << V_155 ;
while ( V_155 > V_154 ) {
V_156 -- ;
V_155 -- ;
V_157 >>= 1 ;
F_27 ( F_42 ( V_40 , & V_1 [ V_157 ] ) , & V_1 [ V_157 ] ) ;
if ( F_72 ( V_40 , & V_1 [ V_157 ] , V_155 , V_3 ) )
continue;
F_102 ( & V_1 [ V_157 ] . V_75 , & V_156 -> V_90 [ V_3 ] ) ;
V_156 -> V_86 ++ ;
F_82 ( & V_1 [ V_157 ] , V_155 ) ;
}
}
static void F_203 ( struct V_1 * V_1 )
{
const char * V_94 = NULL ;
unsigned long V_48 = 0 ;
if ( F_32 ( F_104 ( & V_1 -> V_92 ) != - 1 ) )
V_94 = L_7 ;
if ( F_32 ( V_1 -> V_64 != NULL ) )
V_94 = L_8 ;
if ( F_32 ( F_105 ( V_1 ) != 0 ) )
V_94 = L_18 ;
if ( F_32 ( V_1 -> V_34 & V_158 ) ) {
V_94 = L_19 ;
V_48 = V_158 ;
F_50 ( V_1 ) ;
return;
}
if ( F_32 ( V_1 -> V_34 & V_82 ) ) {
V_94 = L_20 ;
V_48 = V_82 ;
}
#ifdef F_106
if ( F_32 ( V_1 -> V_93 ) )
V_94 = L_11 ;
#endif
F_43 ( V_1 , V_94 , V_48 ) ;
}
static inline int F_204 ( struct V_1 * V_1 )
{
if ( F_96 ( F_103 ( V_1 ,
V_82 | V_158 ) ) )
return 0 ;
F_203 ( V_1 ) ;
return 1 ;
}
static inline bool F_205 ( bool V_159 )
{
return F_110 ( V_160 ) &&
F_206 () && V_159 ;
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
T_6 V_161 )
{
F_77 ( V_1 , 0 ) ;
F_167 ( V_1 ) ;
F_211 ( V_1 , V_59 ) ;
F_132 ( V_1 , 1 << V_59 , 1 ) ;
F_131 ( V_1 , 1 << V_59 , 1 ) ;
F_212 ( V_1 , V_59 ) ;
F_213 ( V_1 , V_59 , V_161 ) ;
}
static void F_214 ( struct V_1 * V_1 , unsigned int V_59 , T_6 V_161 ,
unsigned int V_162 )
{
int V_60 ;
bool V_159 = true ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
if ( V_159 )
V_159 &= F_215 ( V_63 ) ;
}
F_210 ( V_1 , V_59 , V_161 ) ;
if ( ! F_205 ( V_159 ) && ( V_161 & V_163 ) )
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_216 ( V_1 + V_60 ) ;
if ( V_59 && ( V_161 & V_164 ) )
F_55 ( V_1 , V_59 ) ;
if ( V_162 & V_165 )
F_217 ( V_1 ) ;
else
F_218 ( V_1 ) ;
}
static inline
struct V_1 * F_219 ( struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
unsigned int V_166 ;
struct V_85 * V_156 ;
struct V_1 * V_1 ;
for ( V_166 = V_59 ; V_166 < V_71 ; ++ V_166 ) {
V_156 = & ( V_40 -> V_85 [ V_166 ] ) ;
V_1 = F_220 ( & V_156 -> V_90 [ V_3 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
V_156 -> V_86 -- ;
F_202 ( V_40 , V_1 , V_59 , V_166 , V_156 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_221 ( struct V_40 * V_40 ,
unsigned int V_59 )
{
return F_219 ( V_40 , V_59 , V_152 ) ;
}
static inline struct V_1 * F_221 ( struct V_40 * V_40 ,
unsigned int V_59 ) { return NULL ; }
int F_222 ( struct V_40 * V_40 ,
struct V_1 * V_131 , struct V_1 * V_132 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned int V_59 ;
int V_167 = 0 ;
#ifndef F_223
F_94 ( F_19 ( V_131 ) != F_19 ( V_132 ) ) ;
#endif
for ( V_1 = V_131 ; V_1 <= V_132 ; ) {
F_27 ( F_224 ( V_1 ) != F_39 ( V_40 ) , V_1 ) ;
if ( ! F_41 ( F_35 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
if ( ! F_91 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_59 = F_88 ( V_1 ) ;
F_225 ( & V_1 -> V_75 ,
& V_40 -> V_85 [ V_59 ] . V_90 [ V_3 ] ) ;
V_1 += 1 << V_59 ;
V_167 += 1 << V_59 ;
}
return V_167 ;
}
int F_226 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_44 , V_121 ;
struct V_1 * V_131 , * V_132 ;
V_44 = F_35 ( V_1 ) ;
V_44 = V_44 & ~ ( V_24 - 1 ) ;
V_131 = F_153 ( V_44 ) ;
V_132 = V_131 + V_24 - 1 ;
V_121 = V_44 + V_24 - 1 ;
if ( ! F_28 ( V_40 , V_44 ) )
V_131 = V_1 ;
if ( ! F_28 ( V_40 , V_121 ) )
return 0 ;
return F_222 ( V_40 , V_131 , V_132 , V_3 ) ;
}
static void F_227 ( struct V_1 * V_168 ,
int V_169 , int V_3 )
{
int V_170 = 1 << ( V_169 - V_21 ) ;
while ( V_170 -- ) {
F_31 ( V_168 , V_3 ) ;
V_168 += V_24 ;
}
}
static bool F_228 ( unsigned int V_59 , int V_171 )
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
static void F_229 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_173 )
{
unsigned int V_166 = F_88 ( V_1 ) ;
int V_174 ;
if ( V_166 >= V_21 ) {
F_227 ( V_1 , V_166 , V_173 ) ;
return;
}
V_174 = F_226 ( V_40 , V_1 , V_173 ) ;
if ( V_174 >= ( 1 << ( V_21 - 1 ) ) ||
V_36 )
F_31 ( V_1 , V_173 ) ;
}
int F_230 ( struct V_85 * V_156 , unsigned int V_59 ,
int V_3 , bool V_175 , bool * V_176 )
{
int V_60 ;
int V_177 ;
if ( V_156 -> V_86 == 0 )
return - 1 ;
* V_176 = false ;
for ( V_60 = 0 ; ; V_60 ++ ) {
V_177 = V_178 [ V_3 ] [ V_60 ] ;
if ( V_177 == V_179 )
break;
if ( F_140 ( & V_156 -> V_90 [ V_177 ] ) )
continue;
if ( F_228 ( V_59 , V_3 ) )
* V_176 = true ;
if ( ! V_175 )
return V_177 ;
if ( * V_176 )
return V_177 ;
}
return - 1 ;
}
static void F_231 ( struct V_1 * V_1 , struct V_40 * V_40 ,
unsigned int V_180 )
{
int V_115 ;
unsigned long V_181 , V_34 ;
V_181 = ( V_40 -> V_124 / 100 ) + V_24 ;
if ( V_40 -> V_182 >= V_181 )
return;
F_232 ( & V_40 -> V_109 , V_34 ) ;
if ( V_40 -> V_182 >= V_181 )
goto V_183;
V_115 = F_100 ( V_1 ) ;
if ( V_115 != V_184 &&
! F_81 ( V_115 ) && ! F_233 ( V_115 ) ) {
V_40 -> V_182 += V_24 ;
F_31 ( V_1 , V_184 ) ;
F_226 ( V_40 , V_1 , V_184 ) ;
}
V_183:
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
static void F_235 ( const struct V_185 * V_186 )
{
struct V_187 * V_187 = V_186 -> V_187 ;
unsigned long V_34 ;
struct V_188 * V_189 ;
struct V_40 * V_40 ;
struct V_1 * V_1 ;
int V_59 ;
F_236 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( V_40 -> V_182 <= V_24 )
continue;
F_232 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_85 * V_156 = & ( V_40 -> V_85 [ V_59 ] ) ;
V_1 = F_220 (
& V_156 -> V_90 [ V_184 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
V_40 -> V_182 -= F_177 ( V_24 ,
V_40 -> V_182 ) ;
F_31 ( V_1 , V_186 -> V_3 ) ;
F_226 ( V_40 , V_1 , V_186 -> V_3 ) ;
F_234 ( & V_40 -> V_109 , V_34 ) ;
return;
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
}
static inline struct V_1 *
F_237 ( struct V_40 * V_40 , unsigned int V_59 , int V_190 )
{
struct V_85 * V_156 ;
unsigned int V_166 ;
struct V_1 * V_1 ;
int V_177 ;
bool V_176 ;
for ( V_166 = V_71 - 1 ;
V_166 >= V_59 && V_166 <= V_71 - 1 ;
-- V_166 ) {
V_156 = & ( V_40 -> V_85 [ V_166 ] ) ;
V_177 = F_230 ( V_156 , V_166 ,
V_190 , false , & V_176 ) ;
if ( V_177 == - 1 )
continue;
V_1 = F_238 ( & V_156 -> V_90 [ V_177 ] ,
struct V_1 , V_75 ) ;
if ( V_176 )
F_229 ( V_40 , V_1 , V_190 ) ;
V_156 -> V_86 -- ;
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
F_202 ( V_40 , V_1 , V_59 , V_166 , V_156 ,
V_190 ) ;
F_2 ( V_1 , V_190 ) ;
F_239 ( V_1 , V_59 , V_166 ,
V_190 , V_177 ) ;
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
if ( V_3 == V_136 )
V_1 = F_221 ( V_40 , V_59 ) ;
if ( ! V_1 )
V_1 = F_237 ( V_40 , V_59 , V_3 ) ;
}
F_241 ( V_1 , V_59 , V_3 ) ;
return V_1 ;
}
static int F_242 ( struct V_40 * V_40 , unsigned int V_59 ,
unsigned long V_103 , struct V_112 * V_113 ,
int V_3 , bool V_191 )
{
int V_60 ;
F_137 ( & V_40 -> V_109 ) ;
for ( V_60 = 0 ; V_60 < V_103 ; ++ V_60 ) {
struct V_1 * V_1 = F_240 ( V_40 , V_59 , V_3 ) ;
if ( F_32 ( V_1 == NULL ) )
break;
if ( F_32 ( F_207 ( V_1 ) ) )
continue;
if ( F_96 ( ! V_191 ) )
F_102 ( & V_1 -> V_75 , V_113 ) ;
else
F_101 ( & V_1 -> V_75 , V_113 ) ;
V_113 = & V_1 -> V_75 ;
if ( F_233 ( F_1 ( V_1 ) ) )
F_243 ( V_40 , V_192 ,
- ( 1 << V_59 ) ) ;
}
F_243 ( V_40 , V_193 , - ( V_60 << V_59 ) ) ;
F_143 ( & V_40 -> V_109 ) ;
return V_60 ;
}
void F_244 ( struct V_40 * V_40 , struct V_104 * V_105 )
{
unsigned long V_34 ;
int V_194 , V_195 ;
F_161 ( V_34 ) ;
V_195 = F_29 ( V_105 -> V_195 ) ;
V_194 = F_177 ( V_105 -> V_103 , V_195 ) ;
if ( V_194 > 0 ) {
F_136 ( V_40 , V_194 , V_105 ) ;
V_105 -> V_103 -= V_194 ;
}
F_163 ( V_34 ) ;
}
static void F_245 ( unsigned int V_196 , struct V_40 * V_40 )
{
unsigned long V_34 ;
struct V_197 * V_198 ;
struct V_104 * V_105 ;
F_161 ( V_34 ) ;
V_198 = F_246 ( V_40 -> V_199 , V_196 ) ;
V_105 = & V_198 -> V_105 ;
if ( V_105 -> V_103 ) {
F_136 ( V_40 , V_105 -> V_103 , V_105 ) ;
V_105 -> V_103 = 0 ;
}
F_163 ( V_34 ) ;
}
static void F_247 ( unsigned int V_196 )
{
struct V_40 * V_40 ;
F_199 (zone) {
F_245 ( V_196 , V_40 ) ;
}
}
void F_248 ( struct V_40 * V_40 )
{
int V_196 = F_249 () ;
if ( V_40 )
F_245 ( V_196 , V_40 ) ;
else
F_247 ( V_196 ) ;
}
void F_250 ( struct V_40 * V_40 )
{
int V_196 ;
static T_7 V_200 ;
F_251 (cpu) {
struct V_197 * V_105 ;
struct V_40 * V_189 ;
bool V_201 = false ;
if ( V_40 ) {
V_105 = F_246 ( V_40 -> V_199 , V_196 ) ;
if ( V_105 -> V_105 . V_103 )
V_201 = true ;
} else {
F_199 (z) {
V_105 = F_246 ( V_189 -> V_199 , V_196 ) ;
if ( V_105 -> V_105 . V_103 ) {
V_201 = true ;
break;
}
}
}
if ( V_201 )
F_252 ( V_196 , & V_200 ) ;
else
F_253 ( V_196 , & V_200 ) ;
}
F_254 ( & V_200 , ( V_202 ) F_248 ,
V_40 , 1 ) ;
}
void F_255 ( struct V_40 * V_40 )
{
unsigned long V_12 , V_203 ;
unsigned long V_34 ;
unsigned int V_59 , V_204 ;
struct V_1 * V_1 ;
if ( F_256 ( V_40 ) )
return;
F_232 ( & V_40 -> V_109 , V_34 ) ;
V_203 = F_155 ( V_40 ) ;
for ( V_12 = V_40 -> V_23 ; V_12 < V_203 ; V_12 ++ )
if ( F_159 ( V_12 ) ) {
V_1 = F_153 ( V_12 ) ;
if ( F_19 ( V_1 ) != V_40 )
continue;
if ( ! F_257 ( V_1 ) )
F_258 ( V_1 ) ;
}
F_259 (order, t) {
F_260 (page,
&zone->free_area[order].free_list[t], lru) {
unsigned long V_60 ;
V_12 = F_35 ( V_1 ) ;
for ( V_60 = 0 ; V_60 < ( 1UL << V_59 ) ; V_60 ++ )
F_261 ( F_153 ( V_12 + V_60 ) ) ;
}
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
void F_262 ( struct V_1 * V_1 , bool V_191 )
{
struct V_40 * V_40 = F_19 ( V_1 ) ;
struct V_104 * V_105 ;
unsigned long V_34 ;
unsigned long V_12 = F_35 ( V_1 ) ;
int V_3 ;
if ( ! F_134 ( V_1 ) )
return;
V_3 = F_24 ( V_1 , V_12 ) ;
F_2 ( V_1 , V_3 ) ;
F_161 ( V_34 ) ;
F_263 ( V_122 ) ;
if ( V_3 >= V_37 ) {
if ( F_32 ( F_81 ( V_3 ) ) ) {
F_144 ( V_40 , V_1 , V_12 , 0 , V_3 ) ;
goto V_53;
}
V_3 = V_136 ;
}
V_105 = & F_264 ( V_40 -> V_199 ) -> V_105 ;
if ( ! V_191 )
F_102 ( & V_1 -> V_75 , & V_105 -> V_114 [ V_3 ] ) ;
else
F_101 ( & V_1 -> V_75 , & V_105 -> V_114 [ V_3 ] ) ;
V_105 -> V_103 ++ ;
if ( V_105 -> V_103 >= V_105 -> V_155 ) {
unsigned long V_195 = F_29 ( V_105 -> V_195 ) ;
F_136 ( V_40 , V_195 , V_105 ) ;
V_105 -> V_103 -= V_195 ;
}
V_53:
F_163 ( V_34 ) ;
}
void F_265 ( struct V_112 * V_113 , bool V_191 )
{
struct V_1 * V_1 , * V_205 ;
F_266 (page, next, list, lru) {
F_267 ( V_1 , V_191 ) ;
F_262 ( V_1 , V_191 ) ;
}
}
void F_268 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
F_27 ( F_118 ( V_1 ) , V_1 ) ;
F_27 ( ! F_90 ( V_1 ) , V_1 ) ;
#ifdef F_269
if ( F_270 ( V_1 ) )
F_268 ( F_271 ( V_1 [ 0 ] . V_206 ) , V_59 ) ;
#endif
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_167 ( V_1 + V_60 ) ;
F_272 ( V_1 , V_59 ) ;
}
int F_273 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned long V_207 ;
struct V_40 * V_40 ;
int V_115 ;
F_187 ( ! F_91 ( V_1 ) ) ;
V_40 = F_19 ( V_1 ) ;
V_115 = F_100 ( V_1 ) ;
if ( ! F_81 ( V_115 ) ) {
V_207 = F_274 ( V_40 ) + ( 1UL << V_59 ) ;
if ( ! F_275 ( V_40 , 0 , V_207 , 0 , V_208 ) )
return 0 ;
F_78 ( V_40 , - ( 1UL << V_59 ) , V_115 ) ;
}
F_98 ( & V_1 -> V_75 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
F_84 ( V_1 ) ;
if ( V_59 >= V_21 - 1 ) {
struct V_1 * V_209 = V_1 + ( 1 << V_59 ) - 1 ;
for (; V_1 < V_209 ; V_1 += V_24 ) {
int V_115 = F_100 ( V_1 ) ;
if ( ! F_81 ( V_115 ) && ! F_233 ( V_115 ) )
F_31 ( V_1 ,
V_136 ) ;
}
}
return 1UL << V_59 ;
}
static inline void F_276 ( struct V_40 * V_210 , struct V_40 * V_189 ,
T_6 V_34 )
{
#ifdef F_277
int V_211 = F_278 () ;
enum V_212 V_213 = V_214 ;
if ( F_32 ( V_34 & V_215 ) ) {
V_213 = V_216 ;
V_211 = V_210 -> V_128 ;
}
if ( V_189 -> V_128 == V_211 ) {
F_279 ( V_189 , V_217 ) ;
F_279 ( V_189 , V_213 ) ;
} else {
F_279 ( V_189 , V_218 ) ;
F_279 ( V_210 , V_219 ) ;
}
#endif
}
static inline
struct V_1 * F_280 ( struct V_40 * V_210 ,
struct V_40 * V_40 , unsigned int V_59 ,
T_6 V_161 , unsigned int V_162 ,
int V_3 )
{
unsigned long V_34 ;
struct V_1 * V_1 ;
bool V_191 = ( ( V_161 & V_220 ) != 0 ) ;
if ( F_96 ( V_59 == 0 ) ) {
struct V_104 * V_105 ;
struct V_112 * V_113 ;
F_161 ( V_34 ) ;
do {
V_105 = & F_264 ( V_40 -> V_199 ) -> V_105 ;
V_113 = & V_105 -> V_114 [ V_3 ] ;
if ( F_140 ( V_113 ) ) {
V_105 -> V_103 += F_242 ( V_40 , 0 ,
V_105 -> V_195 , V_113 ,
V_3 , V_191 ) ;
if ( F_32 ( F_140 ( V_113 ) ) )
goto V_221;
}
if ( V_191 )
V_1 = F_141 ( V_113 , struct V_1 , V_75 ) ;
else
V_1 = F_238 ( V_113 , struct V_1 , V_75 ) ;
F_98 ( & V_1 -> V_75 ) ;
V_105 -> V_103 -- ;
} while ( F_208 ( V_1 ) );
} else {
F_281 ( ( V_161 & V_222 ) && ( V_59 > 1 ) ) ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
do {
V_1 = NULL ;
if ( V_162 & V_223 ) {
V_1 = F_219 ( V_40 , V_59 , V_184 ) ;
if ( V_1 )
F_241 ( V_1 , V_59 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_240 ( V_40 , V_59 , V_3 ) ;
} while ( V_1 && F_209 ( V_1 , V_59 ) );
F_143 ( & V_40 -> V_109 ) ;
if ( ! V_1 )
goto V_221;
F_78 ( V_40 , - ( 1 << V_59 ) ,
F_1 ( V_1 ) ) ;
}
F_282 ( V_224 , F_283 ( V_1 ) , 1 << V_59 ) ;
F_276 ( V_210 , V_40 , V_161 ) ;
F_163 ( V_34 ) ;
F_27 ( F_42 ( V_40 , V_1 ) , V_1 ) ;
return V_1 ;
V_221:
F_163 ( V_34 ) ;
return NULL ;
}
static int T_4 F_284 ( char * V_225 )
{
return F_285 ( & V_226 . V_227 , V_225 ) ;
}
static bool F_286 ( T_6 V_228 , unsigned int V_59 )
{
if ( V_59 < V_226 . V_229 )
return false ;
if ( V_228 & V_222 )
return false ;
if ( V_226 . V_230 && ( V_228 & V_231 ) )
return false ;
if ( V_226 . V_232 &&
( V_228 & V_233 ) )
return false ;
return F_287 ( & V_226 . V_227 , 1 << V_59 ) ;
}
static int T_4 F_288 ( void )
{
T_8 V_234 = V_235 | V_236 | V_237 ;
struct V_238 * V_239 ;
V_239 = F_289 ( L_21 , NULL ,
& V_226 . V_227 ) ;
if ( F_290 ( V_239 ) )
return F_291 ( V_239 ) ;
if ( ! F_292 ( L_22 , V_234 , V_239 ,
& V_226 . V_232 ) )
goto V_240;
if ( ! F_292 ( L_23 , V_234 , V_239 ,
& V_226 . V_230 ) )
goto V_240;
if ( ! F_293 ( L_24 , V_234 , V_239 ,
& V_226 . V_229 ) )
goto V_240;
return 0 ;
V_240:
F_294 ( V_239 ) ;
return - V_241 ;
}
static inline bool F_286 ( T_6 V_228 , unsigned int V_59 )
{
return false ;
}
bool F_295 ( struct V_40 * V_189 , unsigned int V_59 , unsigned long V_242 ,
int V_243 , unsigned int V_162 ,
long V_244 )
{
long F_177 = V_242 ;
int V_245 ;
const bool V_246 = ( V_162 & V_223 ) ;
V_244 -= ( 1 << V_59 ) - 1 ;
if ( V_162 & V_247 )
F_177 -= F_177 / 2 ;
if ( F_96 ( ! V_246 ) )
V_244 -= V_189 -> V_182 ;
else
F_177 -= F_177 / 4 ;
#ifdef F_296
if ( ! ( V_162 & V_208 ) )
V_244 -= F_297 ( V_189 , V_192 ) ;
#endif
if ( V_244 <= F_177 + V_189 -> V_248 [ V_243 ] )
return false ;
if ( ! V_59 )
return true ;
for ( V_245 = V_59 ; V_245 < V_71 ; V_245 ++ ) {
struct V_85 * V_156 = & V_189 -> V_85 [ V_245 ] ;
int V_115 ;
if ( ! V_156 -> V_86 )
continue;
if ( V_246 )
return true ;
for ( V_115 = 0 ; V_115 < V_37 ; V_115 ++ ) {
if ( ! F_140 ( & V_156 -> V_90 [ V_115 ] ) )
return true ;
}
#ifdef F_296
if ( ( V_162 & V_208 ) &&
! F_140 ( & V_156 -> V_90 [ V_152 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_275 ( struct V_40 * V_189 , unsigned int V_59 , unsigned long V_242 ,
int V_243 , unsigned int V_162 )
{
return F_295 ( V_189 , V_59 , V_242 , V_243 , V_162 ,
F_297 ( V_189 , V_193 ) ) ;
}
static inline bool F_298 ( struct V_40 * V_189 , unsigned int V_59 ,
unsigned long V_242 , int V_243 , unsigned int V_162 )
{
long V_244 = F_297 ( V_189 , V_193 ) ;
long V_249 = 0 ;
#ifdef F_296
if ( ! ( V_162 & V_208 ) )
V_249 = F_297 ( V_189 , V_192 ) ;
#endif
if ( ! V_59 && ( V_244 - V_249 ) > V_242 + V_189 -> V_248 [ V_243 ] )
return true ;
return F_295 ( V_189 , V_59 , V_242 , V_243 , V_162 ,
V_244 ) ;
}
bool F_299 ( struct V_40 * V_189 , unsigned int V_59 ,
unsigned long V_242 , int V_243 )
{
long V_244 = F_297 ( V_189 , V_193 ) ;
if ( V_189 -> V_250 && V_244 < V_189 -> V_250 )
V_244 = F_300 ( V_189 , V_193 ) ;
return F_295 ( V_189 , V_59 , V_242 , V_243 , 0 ,
V_244 ) ;
}
static bool F_301 ( struct V_40 * V_251 , struct V_40 * V_40 )
{
return F_302 ( F_39 ( V_251 ) , F_39 ( V_40 ) ) <
V_252 ;
}
static bool F_301 ( struct V_40 * V_251 , struct V_40 * V_40 )
{
return true ;
}
static struct V_1 *
F_303 ( T_6 V_228 , unsigned int V_59 , int V_162 ,
const struct V_185 * V_186 )
{
struct V_188 * V_189 = V_186 -> V_253 ;
struct V_40 * V_40 ;
struct V_254 * V_255 = NULL ;
F_304 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct V_1 * V_1 ;
unsigned long V_242 ;
if ( F_305 () &&
( V_162 & V_256 ) &&
! F_306 ( V_40 , V_228 ) )
continue;
if ( V_186 -> V_257 ) {
if ( V_255 == V_40 -> V_110 )
continue;
if ( ! F_307 ( V_40 -> V_110 ) ) {
V_255 = V_40 -> V_110 ;
continue;
}
}
V_242 = V_40 -> V_207 [ V_162 & V_258 ] ;
if ( ! F_298 ( V_40 , V_59 , V_242 ,
F_308 ( V_186 ) , V_162 ) ) {
int V_41 ;
F_26 ( V_165 < V_259 ) ;
if ( V_162 & V_165 )
goto V_260;
if ( V_261 == 0 ||
! F_301 ( V_186 -> V_253 -> V_40 , V_40 ) )
continue;
V_41 = F_309 ( V_40 -> V_110 , V_228 , V_59 ) ;
switch ( V_41 ) {
case V_262 :
continue;
case V_263 :
continue;
default:
if ( F_275 ( V_40 , V_59 , V_242 ,
F_308 ( V_186 ) , V_162 ) )
goto V_260;
continue;
}
}
V_260:
V_1 = F_280 ( V_186 -> V_253 -> V_40 , V_40 , V_59 ,
V_228 , V_162 , V_186 -> V_3 ) ;
if ( V_1 ) {
F_214 ( V_1 , V_59 , V_228 , V_162 ) ;
if ( F_32 ( V_59 && ( V_162 & V_223 ) ) )
F_231 ( V_1 , V_40 , V_59 ) ;
return V_1 ;
}
}
return NULL ;
}
static inline bool F_310 ( void )
{
bool V_41 = false ;
#if V_264 > 8
V_41 = F_311 () ;
#endif
return V_41 ;
}
void F_312 ( T_6 V_228 , const char * V_265 , ... )
{
unsigned int V_266 = V_267 ;
struct V_268 V_269 ;
T_9 args ;
if ( ( V_228 & V_270 ) || ! F_313 ( & V_271 ) ||
F_67 () > 0 )
return;
if ( ! ( V_228 & V_272 ) )
if ( F_314 ( V_273 ) ||
( V_55 -> V_34 & ( V_274 | V_275 ) ) )
V_266 &= ~ V_267 ;
if ( F_311 () || ! ( V_228 & V_233 ) )
V_266 &= ~ V_267 ;
F_315 ( L_25 , V_55 -> V_56 ) ;
va_start ( args , V_265 ) ;
V_269 . V_265 = V_265 ;
V_269 . V_276 = & args ;
F_316 ( L_26 , & V_269 ) ;
va_end ( args ) ;
F_316 ( L_27 , V_228 , & V_228 ) ;
F_49 () ;
if ( ! F_310 () )
F_317 ( V_266 ) ;
}
static inline struct V_1 *
F_318 ( T_6 V_228 , unsigned int V_59 ,
const struct V_185 * V_186 , unsigned long * V_277 )
{
struct V_278 V_279 = {
. V_187 = V_186 -> V_187 ,
. V_280 = V_186 -> V_280 ,
. V_281 = NULL ,
. V_228 = V_228 ,
. V_59 = V_59 ,
} ;
struct V_1 * V_1 ;
* V_277 = 0 ;
if ( ! F_319 ( & V_282 ) ) {
* V_277 = 1 ;
F_320 ( 1 ) ;
return NULL ;
}
V_1 = F_303 ( V_228 | V_283 , V_59 ,
V_284 | V_256 , V_186 ) ;
if ( V_1 )
goto V_53;
if ( ! ( V_228 & V_222 ) ) {
if ( V_55 -> V_34 & V_285 )
goto V_53;
if ( V_59 > V_286 )
goto V_53;
if ( V_186 -> V_287 < V_288 )
goto V_53;
if ( F_7 () )
goto V_53;
if ( V_228 & V_289 )
goto V_53;
}
if ( F_321 ( & V_279 ) || F_281 ( V_228 & V_222 ) ) {
* V_277 = 1 ;
if ( V_228 & V_222 ) {
V_1 = F_303 ( V_228 , V_59 ,
V_165 | V_256 , V_186 ) ;
if ( ! V_1 )
V_1 = F_303 ( V_228 , V_59 ,
V_165 , V_186 ) ;
}
}
V_53:
F_322 ( & V_282 ) ;
return V_1 ;
}
static struct V_1 *
F_323 ( T_6 V_228 , unsigned int V_59 ,
unsigned int V_162 , const struct V_185 * V_186 ,
enum V_290 V_291 , enum V_292 * V_292 )
{
struct V_1 * V_1 ;
if ( ! V_59 )
return NULL ;
V_55 -> V_34 |= V_274 ;
* V_292 = F_324 ( V_228 , V_59 , V_162 , V_186 ,
V_291 ) ;
V_55 -> V_34 &= ~ V_274 ;
if ( * V_292 <= V_293 )
return NULL ;
F_325 ( V_294 ) ;
V_1 = F_303 ( V_228 , V_59 , V_162 , V_186 ) ;
if ( V_1 ) {
struct V_40 * V_40 = F_19 ( V_1 ) ;
V_40 -> V_295 = false ;
F_326 ( V_40 , V_59 , true ) ;
F_325 ( V_296 ) ;
return V_1 ;
}
F_325 ( V_297 ) ;
F_189 () ;
return NULL ;
}
static inline bool
F_327 ( struct V_185 * V_186 , int V_59 , int V_162 ,
enum V_292 V_292 ,
enum V_290 * V_290 ,
int * V_298 )
{
int V_299 = V_300 ;
int V_301 ;
if ( ! V_59 )
return false ;
if ( F_328 ( V_292 ) )
( * V_298 ) ++ ;
if ( F_329 ( V_292 ) )
goto V_302;
if ( F_330 ( V_292 ) )
return F_331 ( V_186 , V_59 , V_162 ) ;
if ( V_59 > V_286 )
V_299 /= 4 ;
if ( * V_298 <= V_299 )
return true ;
V_302:
V_301 = ( V_59 > V_286 ) ?
V_303 : V_304 ;
if ( * V_290 > V_301 ) {
( * V_290 ) -- ;
* V_298 = 0 ;
return true ;
}
return false ;
}
static inline struct V_1 *
F_323 ( T_6 V_228 , unsigned int V_59 ,
unsigned int V_162 , const struct V_185 * V_186 ,
enum V_290 V_291 , enum V_292 * V_292 )
{
* V_292 = V_305 ;
return NULL ;
}
static inline bool
F_327 ( struct V_185 * V_186 , unsigned int V_59 , int V_162 ,
enum V_292 V_292 ,
enum V_290 * V_290 ,
int * V_298 )
{
struct V_40 * V_40 ;
struct V_188 * V_189 ;
if ( ! V_59 || V_59 > V_286 )
return false ;
F_236 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( F_275 ( V_40 , 0 , F_274 ( V_40 ) ,
F_308 ( V_186 ) , V_162 ) )
return true ;
}
return false ;
}
static int
F_332 ( T_6 V_228 , unsigned int V_59 ,
const struct V_185 * V_186 )
{
struct V_306 V_306 ;
int V_307 ;
F_189 () ;
F_333 () ;
V_55 -> V_34 |= V_274 ;
F_334 ( V_228 ) ;
V_306 . V_308 = 0 ;
V_55 -> V_306 = & V_306 ;
V_307 = F_335 ( V_186 -> V_187 , V_59 , V_228 ,
V_186 -> V_280 ) ;
V_55 -> V_306 = NULL ;
F_336 () ;
V_55 -> V_34 &= ~ V_274 ;
F_189 () ;
return V_307 ;
}
static inline struct V_1 *
F_337 ( T_6 V_228 , unsigned int V_59 ,
unsigned int V_162 , const struct V_185 * V_186 ,
unsigned long * V_277 )
{
struct V_1 * V_1 = NULL ;
bool V_309 = false ;
* V_277 = F_332 ( V_228 , V_59 , V_186 ) ;
if ( F_32 ( ! ( * V_277 ) ) )
return NULL ;
V_310:
V_1 = F_303 ( V_228 , V_59 , V_162 , V_186 ) ;
if ( ! V_1 && ! V_309 ) {
F_235 ( V_186 ) ;
F_250 ( NULL ) ;
V_309 = true ;
goto V_310;
}
return V_1 ;
}
static void F_338 ( unsigned int V_59 , const struct V_185 * V_186 )
{
struct V_188 * V_189 ;
struct V_40 * V_40 ;
T_1 * V_311 = NULL ;
F_236 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask) {
if ( V_311 != V_40 -> V_110 )
F_339 ( V_40 , V_59 , V_186 -> V_287 ) ;
V_311 = V_40 -> V_110 ;
}
}
static inline unsigned int
F_340 ( T_6 V_228 )
{
unsigned int V_162 = V_312 | V_256 ;
F_26 ( V_313 != ( V_314 T_6 ) V_247 ) ;
V_162 |= ( V_314 int ) ( V_228 & V_313 ) ;
if ( V_228 & V_315 ) {
if ( ! ( V_228 & V_272 ) )
V_162 |= V_223 ;
V_162 &= ~ V_256 ;
} else if ( F_32 ( F_341 ( V_55 ) ) && ! F_311 () )
V_162 |= V_223 ;
#ifdef F_296
if ( F_342 ( V_228 ) == V_136 )
V_162 |= V_208 ;
#endif
return V_162 ;
}
bool F_343 ( T_6 V_228 )
{
if ( F_32 ( V_228 & V_272 ) )
return false ;
if ( V_228 & V_316 )
return true ;
if ( F_344 () && ( V_55 -> V_34 & V_274 ) )
return true ;
if ( ! F_311 () &&
( ( V_55 -> V_34 & V_274 ) ||
F_32 ( F_314 ( V_273 ) ) ) )
return true ;
return false ;
}
static inline bool
F_345 ( T_6 V_228 , unsigned V_59 ,
struct V_185 * V_186 , int V_162 ,
bool V_277 , int * V_317 )
{
struct V_40 * V_40 ;
struct V_188 * V_189 ;
if ( V_277 && V_59 <= V_286 )
* V_317 = 0 ;
else
( * V_317 ) ++ ;
if ( * V_317 > V_318 )
return false ;
F_236 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_319 ;
unsigned long V_320 ;
V_319 = V_320 = F_346 ( V_40 ) ;
V_319 -= F_347 ( ( * V_317 ) * V_319 ,
V_318 ) ;
V_319 += F_300 ( V_40 , V_193 ) ;
if ( F_295 ( V_40 , V_59 , F_274 ( V_40 ) ,
F_308 ( V_186 ) , V_162 , V_319 ) ) {
if ( ! V_277 ) {
unsigned long V_321 ;
V_321 = F_300 ( V_40 ,
V_322 ) ;
if ( 2 * V_321 > V_320 ) {
F_348 ( V_323 , V_54 / 10 ) ;
return true ;
}
}
if ( V_55 -> V_34 & V_324 )
F_320 ( 1 ) ;
else
F_189 () ;
return true ;
}
}
return false ;
}
static inline struct V_1 *
F_349 ( T_6 V_228 , unsigned int V_59 ,
struct V_185 * V_186 )
{
bool V_325 = V_228 & V_233 ;
struct V_1 * V_1 = NULL ;
unsigned int V_162 ;
unsigned long V_277 ;
enum V_290 V_290 = V_326 ;
enum V_292 V_292 ;
int V_298 = 0 ;
int V_317 = 0 ;
unsigned long V_327 = V_52 ;
unsigned int V_328 = 10 * V_54 ;
if ( V_59 >= V_71 ) {
F_281 ( ! ( V_228 & V_270 ) ) ;
return NULL ;
}
if ( F_281 ( ( V_228 & ( V_315 | V_233 ) ) ==
( V_315 | V_233 ) ) )
V_228 &= ~ V_315 ;
V_162 = F_340 ( V_228 ) ;
if ( V_228 & V_329 )
F_338 ( V_59 , V_186 ) ;
V_1 = F_303 ( V_228 , V_59 , V_162 , V_186 ) ;
if ( V_1 )
goto V_330;
if ( V_325 && V_59 > V_286 &&
! F_343 ( V_228 ) ) {
V_1 = F_323 ( V_228 , V_59 ,
V_162 , V_186 ,
V_331 ,
& V_292 ) ;
if ( V_1 )
goto V_330;
if ( V_228 & V_332 ) {
if ( V_292 == V_333 )
goto V_334;
V_290 = V_331 ;
}
}
V_310:
if ( V_228 & V_329 )
F_338 ( V_59 , V_186 ) ;
if ( F_343 ( V_228 ) )
V_162 = V_165 ;
if ( ! ( V_162 & V_256 ) || ( V_162 & V_165 ) ) {
V_186 -> V_187 = F_350 ( F_278 () , V_228 ) ;
V_186 -> V_253 = F_351 ( V_186 -> V_187 ,
V_186 -> V_287 , V_186 -> V_280 ) ;
}
V_1 = F_303 ( V_228 , V_59 , V_162 , V_186 ) ;
if ( V_1 )
goto V_330;
if ( ! V_325 ) {
F_281 ( V_228 & V_222 ) ;
goto V_334;
}
if ( V_55 -> V_34 & V_274 ) {
if ( F_281 ( V_228 & V_222 ) ) {
F_189 () ;
goto V_310;
}
goto V_334;
}
if ( F_314 ( V_273 ) && ! ( V_228 & V_222 ) )
goto V_334;
V_1 = F_337 ( V_228 , V_59 , V_162 , V_186 ,
& V_277 ) ;
if ( V_1 )
goto V_330;
V_1 = F_323 ( V_228 , V_59 , V_162 , V_186 ,
V_290 , & V_292 ) ;
if ( V_1 )
goto V_330;
if ( V_228 & V_332 )
goto V_334;
if ( V_59 > V_286 && ! ( V_228 & V_335 ) )
goto V_334;
if ( F_352 ( V_52 , V_327 + V_328 ) ) {
F_312 ( V_228 ,
L_28 ,
F_191 ( V_52 - V_327 ) , V_59 ) ;
V_328 += 10 * V_54 ;
}
if ( F_345 ( V_228 , V_59 , V_186 , V_162 ,
V_277 > 0 , & V_317 ) )
goto V_310;
if ( V_277 > 0 &&
F_327 ( V_186 , V_59 , V_162 ,
V_292 , & V_290 ,
& V_298 ) )
goto V_310;
V_1 = F_318 ( V_228 , V_59 , V_186 , & V_277 ) ;
if ( V_1 )
goto V_330;
if ( V_277 ) {
V_317 = 0 ;
goto V_310;
}
V_334:
F_312 ( V_228 ,
L_29 , V_59 ) ;
V_330:
return V_1 ;
}
struct V_1 *
F_353 ( T_6 V_228 , unsigned int V_59 ,
struct V_187 * V_187 , T_10 * V_280 )
{
struct V_1 * V_1 ;
unsigned int V_336 ;
unsigned int V_162 = V_337 ;
T_6 V_338 = V_228 ;
struct V_185 V_186 = {
. V_287 = F_354 ( V_228 ) ,
. V_187 = V_187 ,
. V_280 = V_280 ,
. V_3 = F_342 ( V_228 ) ,
} ;
if ( F_305 () ) {
V_338 |= V_283 ;
V_162 |= V_256 ;
if ( ! V_186 . V_280 )
V_186 . V_280 = & V_339 ;
}
V_228 &= V_6 ;
F_355 ( V_228 ) ;
F_356 ( V_228 & V_233 ) ;
if ( F_286 ( V_228 , V_59 ) )
return NULL ;
if ( F_32 ( ! V_187 -> V_340 -> V_40 ) )
return NULL ;
if ( F_110 ( F_296 ) && V_186 . V_3 == V_136 )
V_162 |= V_208 ;
V_341:
V_336 = F_357 () ;
V_186 . V_257 = ( V_228 & V_342 ) ;
V_186 . V_253 = F_351 ( V_186 . V_187 ,
V_186 . V_287 , V_186 . V_280 ) ;
if ( ! V_186 . V_253 ) {
V_1 = NULL ;
goto V_343;
}
V_1 = F_303 ( V_338 , V_59 , V_162 , & V_186 ) ;
if ( F_96 ( V_1 ) )
goto V_53;
V_338 = F_358 ( V_228 ) ;
V_186 . V_257 = false ;
if ( F_305 () )
V_186 . V_280 = V_280 ;
V_1 = F_349 ( V_338 , V_59 , & V_186 ) ;
V_343:
if ( F_32 ( ! V_1 && F_359 ( V_336 ) ) ) {
V_338 = V_228 ;
goto V_341;
}
V_53:
if ( F_121 () && ( V_228 & V_344 ) && V_1 &&
F_32 ( F_360 ( V_1 , V_228 , V_59 ) != 0 ) ) {
F_168 ( V_1 , V_59 ) ;
V_1 = NULL ;
}
if ( V_345 && V_1 )
F_361 ( V_1 , V_59 , V_228 ) ;
F_362 ( V_1 , V_59 , V_338 , V_186 . V_3 ) ;
return V_1 ;
}
unsigned long F_363 ( T_6 V_228 , unsigned int V_59 )
{
struct V_1 * V_1 ;
F_94 ( ( V_228 & V_231 ) != 0 ) ;
V_1 = F_364 ( V_228 , V_59 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_128 ( V_1 ) ;
}
unsigned long F_365 ( T_6 V_228 )
{
return F_363 ( V_228 | V_163 , 0 ) ;
}
void F_168 ( struct V_1 * V_1 , unsigned int V_59 )
{
if ( F_366 ( V_1 ) ) {
if ( V_59 == 0 )
F_262 ( V_1 , false ) ;
else
F_53 ( V_1 , V_59 ) ;
}
}
void V_244 ( unsigned long V_346 , unsigned int V_59 )
{
if ( V_346 != 0 ) {
F_94 ( ! F_367 ( ( void * ) V_346 ) ) ;
F_168 ( F_271 ( ( void * ) V_346 ) , V_59 ) ;
}
}
static struct V_1 * F_368 ( struct V_347 * V_348 ,
T_6 V_228 )
{
struct V_1 * V_1 = NULL ;
T_6 V_349 = V_228 ;
#if ( V_102 < V_350 )
V_228 |= V_164 | V_270 | V_332 |
V_272 ;
V_1 = F_369 ( V_351 , V_228 ,
V_352 ) ;
V_348 -> V_157 = V_1 ? V_350 : V_102 ;
#endif
if ( F_32 ( ! V_1 ) )
V_1 = F_369 ( V_351 , V_349 , 0 ) ;
V_348 -> V_276 = V_1 ? F_128 ( V_1 ) : NULL ;
return V_1 ;
}
void * F_370 ( struct V_347 * V_348 ,
unsigned int V_353 , T_6 V_228 )
{
unsigned int V_157 = V_102 ;
struct V_1 * V_1 ;
int V_354 ;
if ( F_32 ( ! V_348 -> V_276 ) ) {
V_355:
V_1 = F_368 ( V_348 , V_228 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_102 < V_350 )
V_157 = V_348 -> V_157 ;
#endif
F_371 ( V_1 , V_157 - 1 ) ;
V_348 -> V_356 = F_372 ( V_1 ) ;
V_348 -> V_357 = V_157 ;
V_348 -> V_354 = V_157 ;
}
V_354 = V_348 -> V_354 - V_353 ;
if ( F_32 ( V_354 < 0 ) ) {
V_1 = F_271 ( V_348 -> V_276 ) ;
if ( ! F_373 ( V_1 , V_348 -> V_357 ) )
goto V_355;
#if ( V_102 < V_350 )
V_157 = V_348 -> V_157 ;
#endif
F_59 ( V_1 , V_157 ) ;
V_348 -> V_357 = V_157 ;
V_354 = V_157 - V_353 ;
}
V_348 -> V_357 -- ;
V_348 -> V_354 = V_354 ;
return V_348 -> V_276 + V_354 ;
}
void F_374 ( void * V_346 )
{
struct V_1 * V_1 = F_375 ( V_346 ) ;
if ( F_32 ( F_366 ( V_1 ) ) )
F_53 ( V_1 , F_54 ( V_1 ) ) ;
}
static void * F_376 ( unsigned long V_346 , unsigned int V_59 ,
T_11 V_157 )
{
if ( V_346 ) {
unsigned long V_358 = V_346 + ( V_102 << V_59 ) ;
unsigned long V_359 = V_346 + F_377 ( V_157 ) ;
F_268 ( F_271 ( ( void * ) V_346 ) , V_59 ) ;
while ( V_359 < V_358 ) {
F_378 ( V_359 ) ;
V_359 += V_102 ;
}
}
return ( void * ) V_346 ;
}
void * F_379 ( T_11 V_157 , T_6 V_228 )
{
unsigned int V_59 = F_380 ( V_157 ) ;
unsigned long V_346 ;
V_346 = F_363 ( V_228 , V_59 ) ;
return F_376 ( V_346 , V_59 , V_157 ) ;
}
void * T_2 F_381 ( int V_13 , T_11 V_157 , T_6 V_228 )
{
unsigned int V_59 = F_380 ( V_157 ) ;
struct V_1 * V_63 = F_369 ( V_13 , V_228 , V_59 ) ;
if ( ! V_63 )
return NULL ;
return F_376 ( ( unsigned long ) F_128 ( V_63 ) , V_59 , V_157 ) ;
}
void F_382 ( void * V_360 , T_11 V_157 )
{
unsigned long V_346 = ( unsigned long ) V_360 ;
unsigned long V_120 = V_346 + F_377 ( V_157 ) ;
while ( V_346 < V_120 ) {
F_378 ( V_346 ) ;
V_346 += V_102 ;
}
}
static unsigned long F_383 ( int V_354 )
{
struct V_188 * V_189 ;
struct V_40 * V_40 ;
unsigned long V_361 = 0 ;
struct V_187 * V_187 = F_350 ( F_278 () , V_362 ) ;
F_384 (zone, z, zonelist, offset) {
unsigned long V_157 = V_40 -> V_124 ;
unsigned long V_155 = F_385 ( V_40 ) ;
if ( V_157 > V_155 )
V_361 += V_157 - V_155 ;
}
return V_361 ;
}
unsigned long F_386 ( void )
{
return F_383 ( F_354 ( V_363 ) ) ;
}
unsigned long F_387 ( void )
{
return F_383 ( F_354 ( V_364 ) ) ;
}
static inline void F_388 ( struct V_40 * V_40 )
{
if ( F_110 ( F_277 ) )
F_389 ( L_30 , F_39 ( V_40 ) ) ;
}
long F_390 ( void )
{
long V_319 ;
unsigned long V_365 ;
unsigned long V_366 = 0 ;
unsigned long V_174 [ V_367 ] ;
struct V_40 * V_40 ;
int V_75 ;
for ( V_75 = V_368 ; V_75 < V_367 ; V_75 ++ )
V_174 [ V_75 ] = F_391 ( V_369 + V_75 ) ;
F_392 (zone)
V_366 += V_40 -> V_207 [ V_370 ] ;
V_319 = F_393 ( V_193 ) - V_371 ;
V_365 = V_174 [ V_372 ] + V_174 [ V_373 ] ;
V_365 -= F_177 ( V_365 / 2 , V_366 ) ;
V_319 += V_365 ;
V_319 += F_393 ( V_374 ) -
F_177 ( F_393 ( V_374 ) / 2 , V_366 ) ;
if ( V_319 < 0 )
V_319 = 0 ;
return V_319 ;
}
void F_394 ( struct V_375 * V_376 )
{
V_376 -> V_377 = V_378 ;
V_376 -> V_379 = F_391 ( V_380 ) ;
V_376 -> V_381 = F_393 ( V_193 ) ;
V_376 -> V_382 = F_395 () ;
V_376 -> V_383 = V_384 ;
V_376 -> V_385 = F_396 () ;
V_376 -> V_386 = V_102 ;
}
void F_397 ( struct V_375 * V_376 , int V_13 )
{
int V_387 ;
unsigned long V_124 = 0 ;
unsigned long V_388 = 0 ;
unsigned long V_389 = 0 ;
T_1 * V_9 = F_12 ( V_13 ) ;
for ( V_387 = 0 ; V_387 < V_117 ; V_387 ++ )
V_124 += V_9 -> V_118 [ V_387 ] . V_124 ;
V_376 -> V_377 = V_124 ;
V_376 -> V_379 = F_138 ( V_9 , V_380 ) ;
V_376 -> V_381 = F_398 ( V_13 , V_193 ) ;
#ifdef F_399
for ( V_387 = 0 ; V_387 < V_117 ; V_387 ++ ) {
struct V_40 * V_40 = & V_9 -> V_118 [ V_387 ] ;
if ( F_400 ( V_40 ) ) {
V_388 += V_40 -> V_124 ;
V_389 += F_297 ( V_40 , V_193 ) ;
}
}
V_376 -> V_383 = V_388 ;
V_376 -> V_385 = V_389 ;
#else
V_376 -> V_383 = V_388 ;
V_376 -> V_385 = V_389 ;
#endif
V_376 -> V_386 = V_102 ;
}
bool F_401 ( unsigned int V_34 , int V_13 )
{
bool V_41 = false ;
unsigned int V_336 ;
if ( ! ( V_34 & V_267 ) )
goto V_53;
do {
V_336 = F_357 () ;
V_41 = ! F_402 ( V_13 , V_339 ) ;
} while ( F_359 ( V_336 ) );
V_53:
return V_41 ;
}
static void F_403 ( unsigned char type )
{
static const char V_390 [ V_179 ] = {
[ V_38 ] = 'U' ,
[ V_136 ] = 'M' ,
[ V_172 ] = 'E' ,
[ V_184 ] = 'H' ,
#ifdef F_296
[ V_152 ] = 'C' ,
#endif
#ifdef F_404
[ V_391 ] = 'I' ,
#endif
} ;
char V_392 [ V_179 + 1 ] ;
char * V_63 = V_392 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_179 ; V_60 ++ ) {
if ( type & ( 1 << V_60 ) )
* V_63 ++ = V_390 [ V_60 ] ;
}
* V_63 = '\0' ;
F_389 ( V_393 L_31 , V_392 ) ;
}
void F_405 ( unsigned int V_266 )
{
unsigned long V_394 = 0 ;
int V_196 ;
struct V_40 * V_40 ;
T_1 * V_9 ;
F_199 (zone) {
if ( F_401 ( V_266 , F_39 ( V_40 ) ) )
continue;
F_251 (cpu)
V_394 += F_246 ( V_40 -> V_199 , V_196 ) -> V_105 . V_103 ;
}
F_389 ( L_32
L_33
L_34
L_35
L_36
L_37 ,
F_391 ( V_395 ) ,
F_391 ( V_396 ) ,
F_391 ( V_397 ) ,
F_391 ( V_398 ) ,
F_391 ( V_399 ) ,
F_391 ( V_400 ) ,
F_391 ( V_401 ) ,
F_391 ( V_402 ) ,
F_391 ( V_403 ) ,
F_391 ( V_404 ) ,
F_393 ( V_374 ) ,
F_393 ( V_405 ) ,
F_391 ( V_406 ) ,
F_391 ( V_380 ) ,
F_393 ( V_407 ) ,
F_393 ( V_408 ) ,
F_393 ( V_193 ) ,
V_394 ,
F_393 ( V_192 ) ) ;
F_406 (pgdat) {
F_389 ( L_38
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
#ifdef F_407
L_50
L_51
L_52
#endif
L_53
L_54
L_55
L_56
L_57 ,
V_9 -> V_140 ,
F_408 ( F_138 ( V_9 , V_395 ) ) ,
F_408 ( F_138 ( V_9 , V_396 ) ) ,
F_408 ( F_138 ( V_9 , V_398 ) ) ,
F_408 ( F_138 ( V_9 , V_399 ) ) ,
F_408 ( F_138 ( V_9 , V_401 ) ) ,
F_408 ( F_138 ( V_9 , V_397 ) ) ,
F_408 ( F_138 ( V_9 , V_400 ) ) ,
F_408 ( F_138 ( V_9 , V_406 ) ) ,
F_408 ( F_138 ( V_9 , V_402 ) ) ,
F_408 ( F_138 ( V_9 , V_403 ) ) ,
#ifdef F_407
F_408 ( F_138 ( V_9 , V_409 ) * V_410 ) ,
F_408 ( F_138 ( V_9 , V_411 )
* V_410 ) ,
F_408 ( F_138 ( V_9 , V_412 ) * V_410 ) ,
#endif
F_408 ( F_138 ( V_9 , V_380 ) ) ,
F_408 ( F_138 ( V_9 , V_413 ) ) ,
F_408 ( F_138 ( V_9 , V_404 ) ) ,
F_138 ( V_9 , V_111 ) ,
! F_409 ( V_9 ) ? L_58 : L_59 ) ;
}
F_199 (zone) {
int V_60 ;
if ( F_401 ( V_266 , F_39 ( V_40 ) ) )
continue;
V_394 = 0 ;
F_251 (cpu)
V_394 += F_246 ( V_40 -> V_199 , V_196 ) -> V_105 . V_103 ;
F_388 ( V_40 ) ;
F_389 ( V_393
L_60
L_61
L_62
L_63
L_64
L_39
L_40
L_41
L_42
L_43
L_65
L_66
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
L_57 ,
V_40 -> V_46 ,
F_408 ( F_297 ( V_40 , V_193 ) ) ,
F_408 ( F_274 ( V_40 ) ) ,
F_408 ( F_410 ( V_40 ) ) ,
F_408 ( F_385 ( V_40 ) ) ,
F_408 ( F_297 ( V_40 , V_414 ) ) ,
F_408 ( F_297 ( V_40 , V_415 ) ) ,
F_408 ( F_297 ( V_40 , V_416 ) ) ,
F_408 ( F_297 ( V_40 , V_417 ) ) ,
F_408 ( F_297 ( V_40 , V_418 ) ) ,
F_408 ( F_297 ( V_40 , V_322 ) ) ,
F_408 ( V_40 -> V_419 ) ,
F_408 ( V_40 -> V_124 ) ,
F_408 ( F_297 ( V_40 , V_420 ) ) ,
F_408 ( F_297 ( V_40 , V_374 ) ) ,
F_408 ( F_297 ( V_40 , V_405 ) ) ,
F_297 ( V_40 , V_421 ) ,
F_408 ( F_297 ( V_40 , V_407 ) ) ,
F_408 ( F_297 ( V_40 , V_408 ) ) ,
F_408 ( V_394 ) ,
F_408 ( F_411 ( V_40 -> V_199 -> V_105 . V_103 ) ) ,
F_408 ( F_297 ( V_40 , V_192 ) ) ) ;
F_389 ( L_77 ) ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ )
F_389 ( V_393 L_78 , V_40 -> V_248 [ V_60 ] ) ;
F_389 ( V_393 L_57 ) ;
}
F_199 (zone) {
unsigned int V_59 ;
unsigned long V_422 [ V_71 ] , V_34 , V_423 = 0 ;
unsigned char V_390 [ V_71 ] ;
if ( F_401 ( V_266 , F_39 ( V_40 ) ) )
continue;
F_388 ( V_40 ) ;
F_389 ( V_393 L_25 , V_40 -> V_46 ) ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_85 * V_156 = & V_40 -> V_85 [ V_59 ] ;
int type ;
V_422 [ V_59 ] = V_156 -> V_86 ;
V_423 += V_422 [ V_59 ] << V_59 ;
V_390 [ V_59 ] = 0 ;
for ( type = 0 ; type < V_179 ; type ++ ) {
if ( ! F_140 ( & V_156 -> V_90 [ type ] ) )
V_390 [ V_59 ] |= 1 << type ;
}
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
F_389 ( V_393 L_79 ,
V_422 [ V_59 ] , F_408 ( 1UL ) << V_59 ) ;
if ( V_422 [ V_59 ] )
F_403 ( V_390 [ V_59 ] ) ;
}
F_389 ( V_393 L_80 , F_408 ( V_423 ) ) ;
}
F_412 () ;
F_389 ( L_81 , F_391 ( V_424 ) ) ;
F_413 () ;
}
static void F_414 ( struct V_40 * V_40 , struct V_188 * V_188 )
{
V_188 -> V_40 = V_40 ;
V_188 -> V_425 = V_425 ( V_40 ) ;
}
static int F_415 ( T_1 * V_9 , struct V_187 * V_187 ,
int V_426 )
{
struct V_40 * V_40 ;
enum V_387 V_387 = V_117 ;
do {
V_387 -- ;
V_40 = V_9 -> V_118 + V_387 ;
if ( F_416 ( V_40 ) ) {
F_414 ( V_40 ,
& V_187 -> V_340 [ V_426 ++ ] ) ;
F_417 ( V_387 ) ;
}
} while ( V_387 );
return V_426 ;
}
static int F_418 ( char * V_427 )
{
if ( * V_427 == 'd' || * V_427 == 'D' ) {
V_428 = V_429 ;
} else if ( * V_427 == 'n' || * V_427 == 'N' ) {
V_428 = V_430 ;
} else if ( * V_427 == 'z' || * V_427 == 'Z' ) {
V_428 = V_431 ;
} else {
F_315 ( L_82 , V_427 ) ;
return - V_67 ;
}
return 0 ;
}
static T_4 int F_419 ( char * V_427 )
{
int V_41 ;
if ( ! V_427 )
return 0 ;
V_41 = F_418 ( V_427 ) ;
if ( V_41 == 0 )
F_420 ( V_432 , V_427 , V_433 ) ;
return V_41 ;
}
int F_421 ( struct V_434 * V_435 , int V_436 ,
void T_12 * V_437 , T_11 * V_438 ,
T_13 * V_439 )
{
char V_440 [ V_433 ] ;
int V_41 ;
static F_422 ( V_441 ) ;
F_423 ( & V_441 ) ;
if ( V_436 ) {
if ( strlen ( ( char * ) V_435 -> V_139 ) >= V_433 ) {
V_41 = - V_67 ;
goto V_53;
}
strcpy ( V_440 , ( char * ) V_435 -> V_139 ) ;
}
V_41 = F_424 ( V_435 , V_436 , V_437 , V_438 , V_439 ) ;
if ( V_41 )
goto V_53;
if ( V_436 ) {
int V_442 = V_428 ;
V_41 = F_418 ( ( char * ) V_435 -> V_139 ) ;
if ( V_41 ) {
strncpy ( ( char * ) V_435 -> V_139 , V_440 ,
V_433 ) ;
V_428 = V_442 ;
} else if ( V_442 != V_428 ) {
F_423 ( & V_443 ) ;
F_425 ( NULL , NULL ) ;
F_322 ( & V_443 ) ;
}
}
V_53:
F_322 ( & V_441 ) ;
return V_41 ;
}
static int F_426 ( int V_128 , T_10 * V_444 )
{
int V_445 , V_376 ;
int V_446 = V_447 ;
int V_448 = V_351 ;
const struct V_145 * V_392 = F_184 ( 0 ) ;
if ( ! F_402 ( V_128 , * V_444 ) ) {
F_427 ( V_128 , * V_444 ) ;
return V_128 ;
}
F_195 (n, N_MEMORY) {
if ( F_402 ( V_445 , * V_444 ) )
continue;
V_376 = F_302 ( V_128 , V_445 ) ;
V_376 += ( V_445 < V_128 ) ;
V_392 = F_184 ( V_445 ) ;
if ( ! F_185 ( V_392 ) )
V_376 += V_449 ;
V_376 *= ( V_450 * V_451 ) ;
V_376 += V_452 [ V_445 ] ;
if ( V_376 < V_446 ) {
V_446 = V_376 ;
V_448 = V_445 ;
}
}
if ( V_448 >= 0 )
F_427 ( V_448 , * V_444 ) ;
return V_448 ;
}
static void F_428 ( T_1 * V_9 , int V_128 )
{
int V_453 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_454 [ V_455 ] ;
for ( V_453 = 0 ; V_187 -> V_340 [ V_453 ] . V_40 != NULL ; V_453 ++ )
;
V_453 = F_415 ( F_12 ( V_128 ) , V_187 , V_453 ) ;
V_187 -> V_340 [ V_453 ] . V_40 = NULL ;
V_187 -> V_340 [ V_453 ] . V_425 = 0 ;
}
static void F_429 ( T_1 * V_9 )
{
int V_453 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_454 [ V_456 ] ;
V_453 = F_415 ( V_9 , V_187 , 0 ) ;
V_187 -> V_340 [ V_453 ] . V_40 = NULL ;
V_187 -> V_340 [ V_453 ] . V_425 = 0 ;
}
static void F_430 ( T_1 * V_9 , int V_457 )
{
int V_458 , V_453 , V_128 ;
int V_387 ;
struct V_40 * V_189 ;
struct V_187 * V_187 ;
V_187 = & V_9 -> V_454 [ V_455 ] ;
V_458 = 0 ;
for ( V_387 = V_117 - 1 ; V_387 >= 0 ; V_387 -- ) {
for ( V_453 = 0 ; V_453 < V_457 ; V_453 ++ ) {
V_128 = V_459 [ V_453 ] ;
V_189 = & F_12 ( V_128 ) -> V_118 [ V_387 ] ;
if ( F_416 ( V_189 ) ) {
F_414 ( V_189 ,
& V_187 -> V_340 [ V_458 ++ ] ) ;
F_417 ( V_387 ) ;
}
}
}
V_187 -> V_340 [ V_458 ] . V_40 = NULL ;
V_187 -> V_340 [ V_458 ] . V_425 = 0 ;
}
static int F_431 ( void )
{
return V_430 ;
}
static int F_431 ( void )
{
return V_431 ;
}
static void F_432 ( void )
{
if ( V_428 == V_429 )
V_460 = F_431 () ;
else
V_460 = V_428 ;
}
static void F_433 ( T_1 * V_9 )
{
int V_60 , V_128 , V_461 ;
T_10 V_462 ;
int V_463 , V_464 ;
struct V_187 * V_187 ;
unsigned int V_59 = V_460 ;
for ( V_60 = 0 ; V_60 < V_465 ; V_60 ++ ) {
V_187 = V_9 -> V_454 + V_60 ;
V_187 -> V_340 [ 0 ] . V_40 = NULL ;
V_187 -> V_340 [ 0 ] . V_425 = 0 ;
}
V_463 = V_9 -> V_140 ;
V_461 = V_466 ;
V_464 = V_463 ;
F_434 ( V_462 ) ;
memset ( V_459 , 0 , sizeof( V_459 ) ) ;
V_60 = 0 ;
while ( ( V_128 = F_426 ( V_463 , & V_462 ) ) >= 0 ) {
if ( F_302 ( V_463 , V_128 ) !=
F_302 ( V_463 , V_464 ) )
V_452 [ V_128 ] = V_461 ;
V_464 = V_128 ;
V_461 -- ;
if ( V_59 == V_430 )
F_428 ( V_9 , V_128 ) ;
else
V_459 [ V_60 ++ ] = V_128 ;
}
if ( V_59 == V_431 ) {
F_430 ( V_9 , V_60 ) ;
}
F_429 ( V_9 ) ;
}
int F_435 ( int V_128 )
{
struct V_188 * V_189 ;
V_189 = F_351 ( F_350 ( V_128 , V_362 ) ,
F_354 ( V_362 ) ,
NULL ) ;
return V_189 -> V_40 -> V_128 ;
}
static void F_432 ( void )
{
V_460 = V_431 ;
}
static void F_433 ( T_1 * V_9 )
{
int V_128 , V_463 ;
enum V_387 V_453 ;
struct V_187 * V_187 ;
V_463 = V_9 -> V_140 ;
V_187 = & V_9 -> V_454 [ V_455 ] ;
V_453 = F_415 ( V_9 , V_187 , 0 ) ;
for ( V_128 = V_463 + 1 ; V_128 < V_451 ; V_128 ++ ) {
if ( ! F_11 ( V_128 ) )
continue;
V_453 = F_415 ( F_12 ( V_128 ) , V_187 , V_453 ) ;
}
for ( V_128 = 0 ; V_128 < V_463 ; V_128 ++ ) {
if ( ! F_11 ( V_128 ) )
continue;
V_453 = F_415 ( F_12 ( V_128 ) , V_187 , V_453 ) ;
}
V_187 -> V_340 [ V_453 ] . V_40 = NULL ;
V_187 -> V_340 [ V_453 ] . V_425 = 0 ;
}
static int F_436 ( void * V_139 )
{
int V_13 ;
int V_196 ;
T_1 * V_467 = V_139 ;
#ifdef F_277
memset ( V_452 , 0 , sizeof( V_452 ) ) ;
#endif
if ( V_467 && ! F_11 ( V_467 -> V_140 ) ) {
F_433 ( V_467 ) ;
}
F_437 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_433 ( V_9 ) ;
}
F_438 (cpu) {
F_439 ( & F_440 ( V_468 , V_196 ) , 0 ) ;
#ifdef F_441
if ( F_442 ( V_196 ) )
F_443 ( V_196 , F_435 ( F_444 ( V_196 ) ) ) ;
#endif
}
return 0 ;
}
static T_14 void T_4
F_445 ( void )
{
F_436 ( NULL ) ;
F_446 () ;
F_447 () ;
}
void T_15 F_425 ( T_1 * V_9 , struct V_40 * V_40 )
{
F_432 () ;
if ( V_469 == V_470 ) {
F_445 () ;
} else {
#ifdef F_448
if ( V_40 )
F_449 ( V_40 ) ;
#endif
F_450 ( F_436 , V_9 , NULL ) ;
}
V_471 = F_387 () ;
if ( V_471 < ( V_24 * V_179 ) )
V_36 = 1 ;
else
V_36 = 0 ;
F_71 ( L_83 ,
V_466 ,
V_472 [ V_460 ] ,
V_36 ? L_84 : L_85 ,
V_471 ) ;
#ifdef F_277
F_71 ( L_86 , V_473 [ V_474 ] ) ;
#endif
}
void T_2 F_451 ( unsigned long V_157 , int V_13 , unsigned long V_40 ,
unsigned long V_44 , enum V_475 V_476 )
{
struct V_477 * V_478 = F_452 ( F_453 ( V_44 ) ) ;
unsigned long V_121 = V_44 + V_157 ;
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_12 ;
unsigned long V_15 = 0 ;
#ifdef F_454
struct V_479 * V_480 = NULL , * V_392 ;
#endif
if ( V_481 < V_121 - 1 )
V_481 = V_121 - 1 ;
if ( V_478 && V_44 == V_478 -> V_482 )
V_44 += V_478 -> V_483 ;
for ( V_12 = V_44 ; V_12 < V_121 ; V_12 ++ ) {
if ( V_476 != V_484 )
goto V_485;
if ( ! F_455 ( V_12 ) )
continue;
if ( ! F_172 ( V_12 , V_13 ) )
continue;
if ( ! F_13 ( V_9 , V_12 , V_121 , & V_15 ) )
break;
#ifdef F_454
if ( V_486 && V_40 == V_487 ) {
if ( ! V_480 || V_12 >= F_456 ( V_480 ) ) {
F_457 (memory, tmp)
if ( V_12 < F_456 ( V_392 ) )
break;
V_480 = V_392 ;
}
if ( V_12 >= F_458 ( V_480 ) &&
F_459 ( V_480 ) ) {
V_12 = F_456 ( V_480 ) ;
continue;
}
}
#endif
V_485:
if ( ! ( V_12 & ( V_24 - 1 ) ) ) {
struct V_1 * V_1 = F_153 ( V_12 ) ;
F_145 ( V_1 , V_12 , V_40 , V_13 ) ;
F_31 ( V_1 , V_136 ) ;
} else {
F_152 ( V_12 , V_40 , V_13 ) ;
}
}
}
static void T_2 F_460 ( struct V_40 * V_40 )
{
unsigned int V_59 , V_204 ;
F_259 (order, t) {
F_76 ( & V_40 -> V_85 [ V_59 ] . V_90 [ V_204 ] ) ;
V_40 -> V_85 [ V_59 ] . V_86 = 0 ;
}
}
static int F_461 ( struct V_40 * V_40 )
{
#ifdef F_462
int V_195 ;
V_195 = V_40 -> V_124 / 1024 ;
if ( V_195 * V_102 > 512 * 1024 )
V_195 = ( 512 * 1024 ) / V_102 ;
V_195 /= 4 ;
if ( V_195 < 1 )
V_195 = 1 ;
V_195 = F_463 ( V_195 + V_195 / 2 ) - 1 ;
return V_195 ;
#else
return 0 ;
#endif
}
static void F_464 ( struct V_104 * V_105 , unsigned long V_155 ,
unsigned long V_195 )
{
V_105 -> V_195 = 1 ;
F_465 () ;
V_105 -> V_155 = V_155 ;
F_465 () ;
V_105 -> V_195 = V_195 ;
}
static void F_466 ( struct V_197 * V_63 , unsigned long V_195 )
{
F_464 ( & V_63 -> V_105 , 6 * V_195 , F_15 ( 1UL , 1 * V_195 ) ) ;
}
static void F_467 ( struct V_197 * V_63 )
{
struct V_104 * V_105 ;
int V_3 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_105 = & V_63 -> V_105 ;
V_105 -> V_103 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ )
F_76 ( & V_105 -> V_114 [ V_3 ] ) ;
}
static void F_439 ( struct V_197 * V_63 , unsigned long V_195 )
{
F_467 ( V_63 ) ;
F_466 ( V_63 , V_195 ) ;
}
static void F_468 ( struct V_197 * V_63 ,
unsigned long V_155 )
{
unsigned long V_195 = F_15 ( 1UL , V_155 / 4 ) ;
if ( ( V_155 / 4 ) > ( V_17 * 8 ) )
V_195 = V_17 * 8 ;
F_464 ( & V_63 -> V_105 , V_155 , V_195 ) ;
}
static void F_469 ( struct V_40 * V_40 ,
struct V_197 * V_105 )
{
if ( V_488 )
F_468 ( V_105 ,
( V_40 -> V_124 /
V_488 ) ) ;
else
F_466 ( V_105 , F_461 ( V_40 ) ) ;
}
static void T_2 F_470 ( struct V_40 * V_40 , int V_196 )
{
struct V_197 * V_105 = F_246 ( V_40 -> V_199 , V_196 ) ;
F_467 ( V_105 ) ;
F_469 ( V_40 , V_105 ) ;
}
static void T_2 F_449 ( struct V_40 * V_40 )
{
int V_196 ;
V_40 -> V_199 = F_471 ( struct V_197 ) ;
F_438 (cpu)
F_470 ( V_40 , V_196 ) ;
}
void T_4 F_472 ( void )
{
struct V_254 * V_9 ;
struct V_40 * V_40 ;
F_199 (zone)
F_449 ( V_40 ) ;
F_406 (pgdat)
V_9 -> V_489 =
F_471 ( struct V_490 ) ;
}
static T_2 void F_473 ( struct V_40 * V_40 )
{
V_40 -> V_199 = & V_468 ;
if ( F_190 ( V_40 ) )
F_389 ( V_491 L_87 ,
V_40 -> V_46 , V_40 -> V_419 ,
F_461 ( V_40 ) ) ;
}
int T_2 F_474 ( struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_157 )
{
struct V_254 * V_9 = V_40 -> V_110 ;
V_9 -> V_426 = V_425 ( V_40 ) + 1 ;
V_40 -> V_23 = V_23 ;
F_475 ( V_492 , L_88 ,
L_89 ,
V_9 -> V_140 ,
( unsigned long ) V_425 ( V_40 ) ,
V_23 , ( V_23 + V_157 ) ) ;
F_460 ( V_40 ) ;
V_40 -> V_493 = 1 ;
return 0 ;
}
int T_2 F_170 ( unsigned long V_12 ,
struct V_129 * V_130 )
{
unsigned long V_44 , V_121 ;
int V_13 ;
if ( V_130 -> V_494 <= V_12 && V_12 < V_130 -> V_495 )
return V_130 -> V_496 ;
V_13 = F_476 ( V_12 , & V_44 , & V_121 ) ;
if ( V_13 != - 1 ) {
V_130 -> V_494 = V_44 ;
V_130 -> V_495 = V_121 ;
V_130 -> V_496 = V_13 ;
}
return V_13 ;
}
void T_4 F_477 ( int V_13 , unsigned long V_497 )
{
unsigned long V_44 , V_121 ;
int V_60 , V_498 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_44 = F_177 ( V_44 , V_497 ) ;
V_121 = F_177 ( V_121 , V_497 ) ;
if ( V_44 < V_121 )
F_478 ( F_479 ( V_44 ) ,
( V_121 - V_44 ) << V_17 ,
V_498 ) ;
}
}
void T_4 F_480 ( int V_13 )
{
unsigned long V_44 , V_121 ;
int V_60 , V_498 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_481 ( V_498 , V_44 , V_121 ) ;
}
void T_2 F_482 ( unsigned int V_13 ,
unsigned long * V_44 , unsigned long * V_121 )
{
unsigned long V_499 , V_500 ;
int V_60 ;
* V_44 = - 1UL ;
* V_121 = 0 ;
F_188 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_44 = F_177 ( * V_44 , V_499 ) ;
* V_121 = F_15 ( * V_121 , V_500 ) ;
}
if ( * V_44 == - 1UL )
* V_44 = 0 ;
}
static void T_4 F_483 ( void )
{
int V_501 ;
for ( V_501 = V_117 - 1 ; V_501 >= 0 ; V_501 -- ) {
if ( V_501 == V_487 )
continue;
if ( V_502 [ V_501 ] >
V_503 [ V_501 ] )
break;
}
F_94 ( V_501 == - 1 ) ;
V_504 = V_501 ;
}
static void T_2 F_484 ( int V_13 ,
unsigned long V_387 ,
unsigned long V_146 ,
unsigned long V_505 ,
unsigned long * V_23 ,
unsigned long * F_155 )
{
if ( V_506 [ V_13 ] ) {
if ( V_387 == V_487 ) {
* V_23 = V_506 [ V_13 ] ;
* F_155 = F_177 ( V_505 ,
V_502 [ V_504 ] ) ;
} else if ( ! V_486 &&
* V_23 < V_506 [ V_13 ] &&
* F_155 > V_506 [ V_13 ] ) {
* F_155 = V_506 [ V_13 ] ;
} else if ( * V_23 >= V_506 [ V_13 ] )
* V_23 = * F_155 ;
}
}
static unsigned long T_2 F_485 ( int V_13 ,
unsigned long V_387 ,
unsigned long V_146 ,
unsigned long V_505 ,
unsigned long * V_23 ,
unsigned long * F_155 ,
unsigned long * V_507 )
{
if ( ! V_146 && ! V_505 )
return 0 ;
* V_23 = V_503 [ V_387 ] ;
* F_155 = V_502 [ V_387 ] ;
F_484 ( V_13 , V_387 ,
V_146 , V_505 ,
V_23 , F_155 ) ;
if ( * F_155 < V_146 || * V_23 > V_505 )
return 0 ;
* F_155 = F_177 ( * F_155 , V_505 ) ;
* V_23 = F_15 ( * V_23 , V_146 ) ;
return * F_155 - * V_23 ;
}
unsigned long T_2 F_486 ( int V_13 ,
unsigned long V_508 ,
unsigned long V_509 )
{
unsigned long V_510 = V_509 - V_508 ;
unsigned long V_44 , V_121 ;
int V_60 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
V_44 = F_487 ( V_44 , V_508 , V_509 ) ;
V_121 = F_487 ( V_121 , V_508 , V_509 ) ;
V_510 -= V_121 - V_44 ;
}
return V_510 ;
}
unsigned long T_4 F_488 ( unsigned long V_44 ,
unsigned long V_121 )
{
return F_486 ( V_451 , V_44 , V_121 ) ;
}
static unsigned long T_2 F_489 ( int V_13 ,
unsigned long V_387 ,
unsigned long V_146 ,
unsigned long V_505 ,
unsigned long * V_507 )
{
unsigned long V_511 = V_503 [ V_387 ] ;
unsigned long V_512 = V_502 [ V_387 ] ;
unsigned long V_23 , F_155 ;
unsigned long V_510 ;
if ( ! V_146 && ! V_505 )
return 0 ;
V_23 = F_487 ( V_146 , V_511 , V_512 ) ;
F_155 = F_487 ( V_505 , V_511 , V_512 ) ;
F_484 ( V_13 , V_387 ,
V_146 , V_505 ,
& V_23 , & F_155 ) ;
V_510 = F_486 ( V_13 , V_23 , F_155 ) ;
if ( V_486 && V_506 [ V_13 ] ) {
unsigned long V_44 , V_121 ;
struct V_479 * V_480 ;
F_457 (memory, r) {
V_44 = F_487 ( F_458 ( V_480 ) ,
V_23 , F_155 ) ;
V_121 = F_487 ( F_456 ( V_480 ) ,
V_23 , F_155 ) ;
if ( V_387 == V_487 &&
F_459 ( V_480 ) )
V_510 += V_121 - V_44 ;
if ( V_387 == V_288 &&
! F_459 ( V_480 ) )
V_510 += V_121 - V_44 ;
}
}
return V_510 ;
}
static inline unsigned long T_2 F_485 ( int V_13 ,
unsigned long V_387 ,
unsigned long V_146 ,
unsigned long V_505 ,
unsigned long * V_23 ,
unsigned long * F_155 ,
unsigned long * V_513 )
{
unsigned int V_40 ;
* V_23 = V_146 ;
for ( V_40 = 0 ; V_40 < V_387 ; V_40 ++ )
* V_23 += V_513 [ V_40 ] ;
* F_155 = * V_23 + V_513 [ V_387 ] ;
return V_513 [ V_387 ] ;
}
static inline unsigned long T_2 F_489 ( int V_13 ,
unsigned long V_387 ,
unsigned long V_146 ,
unsigned long V_505 ,
unsigned long * V_514 )
{
if ( ! V_514 )
return 0 ;
return V_514 [ V_387 ] ;
}
static void T_2 F_490 ( struct V_254 * V_9 ,
unsigned long V_146 ,
unsigned long V_505 ,
unsigned long * V_513 ,
unsigned long * V_514 )
{
unsigned long V_515 = 0 , V_516 = 0 ;
enum V_387 V_60 ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_60 ;
unsigned long V_23 , F_155 ;
unsigned long V_157 , V_517 ;
V_157 = F_485 ( V_9 -> V_140 , V_60 ,
V_146 ,
V_505 ,
& V_23 ,
& F_155 ,
V_513 ) ;
V_517 = V_157 - F_489 ( V_9 -> V_140 , V_60 ,
V_146 , V_505 ,
V_514 ) ;
if ( V_157 )
V_40 -> V_23 = V_23 ;
else
V_40 -> V_23 = 0 ;
V_40 -> V_45 = V_157 ;
V_40 -> V_419 = V_517 ;
V_516 += V_157 ;
V_515 += V_517 ;
}
V_9 -> V_18 = V_516 ;
V_9 -> V_518 = V_515 ;
F_389 ( V_491 L_90 , V_9 -> V_140 ,
V_515 ) ;
}
static unsigned long T_4 F_491 ( unsigned long V_23 , unsigned long V_519 )
{
unsigned long V_520 ;
V_519 += V_23 & ( V_24 - 1 ) ;
V_520 = F_492 ( V_519 , V_24 ) ;
V_520 = V_520 >> V_21 ;
V_520 *= V_22 ;
V_520 = F_492 ( V_520 , 8 * sizeof( unsigned long ) ) ;
return V_520 / 8 ;
}
static void T_4 F_493 ( struct V_254 * V_9 ,
struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_519 )
{
unsigned long V_520 = F_491 ( V_23 , V_519 ) ;
V_40 -> V_20 = NULL ;
if ( V_520 )
V_40 -> V_20 =
F_494 ( V_520 ,
V_9 -> V_140 ) ;
}
static inline void F_493 ( struct V_254 * V_9 , struct V_40 * V_40 ,
unsigned long V_23 , unsigned long V_519 ) {}
void T_16 F_495 ( void )
{
unsigned int V_59 ;
if ( V_21 )
return;
if ( V_521 > V_17 )
V_59 = V_522 ;
else
V_59 = V_71 - 1 ;
V_21 = V_59 ;
}
void T_16 F_495 ( void )
{
}
static unsigned long T_16 F_496 ( unsigned long V_45 ,
unsigned long V_419 )
{
unsigned long V_174 = V_45 ;
if ( V_45 > V_419 + ( V_419 >> 4 ) &&
F_110 ( F_17 ) )
V_174 = V_419 ;
return F_377 ( V_174 * sizeof( struct V_1 ) ) >> V_17 ;
}
static void T_16 F_497 ( struct V_254 * V_9 )
{
enum V_387 V_453 ;
int V_13 = V_9 -> V_140 ;
int V_41 ;
F_498 ( V_9 ) ;
#ifdef F_499
F_500 ( & V_9 -> V_523 ) ;
V_9 -> V_524 = 0 ;
V_9 -> V_525 = V_52 ;
#endif
#ifdef F_407
F_500 ( & V_9 -> V_526 ) ;
F_76 ( & V_9 -> V_527 ) ;
V_9 -> V_528 = 0 ;
#endif
F_501 ( & V_9 -> V_529 ) ;
F_501 ( & V_9 -> V_530 ) ;
#ifdef F_502
F_501 ( & V_9 -> V_531 ) ;
#endif
F_503 ( V_9 ) ;
F_500 ( & V_9 -> V_532 ) ;
F_504 ( F_505 ( V_9 ) ) ;
for ( V_453 = 0 ; V_453 < V_117 ; V_453 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_453 ;
unsigned long V_157 , V_533 , V_534 , V_535 ;
unsigned long V_23 = V_40 -> V_23 ;
V_157 = V_40 -> V_45 ;
V_533 = V_534 = V_40 -> V_419 ;
V_535 = F_496 ( V_157 , V_533 ) ;
if ( ! F_149 ( V_453 ) ) {
if ( V_534 >= V_535 ) {
V_534 -= V_535 ;
if ( V_535 )
F_389 ( V_491
L_91 ,
V_473 [ V_453 ] , V_535 ) ;
} else
F_315 ( L_92 ,
V_473 [ V_453 ] , V_535 , V_534 ) ;
}
if ( V_453 == 0 && V_534 > V_536 ) {
V_534 -= V_536 ;
F_389 ( V_491 L_93 ,
V_473 [ 0 ] , V_536 ) ;
}
if ( ! F_149 ( V_453 ) )
V_537 += V_534 ;
else if ( V_537 > V_535 * 2 )
V_537 -= V_535 ;
V_538 += V_534 ;
V_40 -> V_124 = F_149 ( V_453 ) ? V_533 : V_534 ;
#ifdef F_277
V_40 -> V_128 = V_13 ;
#endif
V_40 -> V_46 = V_473 [ V_453 ] ;
V_40 -> V_110 = V_9 ;
F_500 ( & V_40 -> V_109 ) ;
F_506 ( V_40 ) ;
F_473 ( V_40 ) ;
if ( ! V_157 )
continue;
F_495 () ;
F_493 ( V_9 , V_40 , V_23 , V_157 ) ;
V_41 = F_474 ( V_40 , V_23 , V_157 ) ;
F_187 ( V_41 ) ;
F_507 ( V_157 , V_13 , V_453 , V_23 ) ;
}
}
static void T_15 F_508 ( struct V_254 * V_9 )
{
unsigned long T_17 V_119 = 0 ;
unsigned long T_17 V_354 = 0 ;
if ( ! V_9 -> V_18 )
return;
#ifdef F_509
V_119 = V_9 -> V_146 & ~ ( V_153 - 1 ) ;
V_354 = V_9 -> V_146 - V_119 ;
if ( ! V_9 -> V_539 ) {
unsigned long V_157 , V_120 ;
struct V_1 * V_540 ;
V_120 = F_14 ( V_9 ) ;
V_120 = F_176 ( V_120 , V_153 ) ;
V_157 = ( V_120 - V_119 ) * sizeof( struct V_1 ) ;
V_540 = F_510 ( V_9 -> V_140 , V_157 ) ;
if ( ! V_540 )
V_540 = F_494 ( V_157 ,
V_9 -> V_140 ) ;
V_9 -> V_539 = V_540 + V_354 ;
}
#ifndef F_511
if ( V_9 == F_12 ( 0 ) ) {
V_541 = F_12 ( 0 ) -> V_539 ;
#if F_512 ( F_454 ) || F_512 ( V_542 )
if ( F_35 ( V_541 ) != V_9 -> V_146 )
V_541 -= V_354 ;
#endif
}
#endif
#endif
}
void T_16 F_513 ( int V_13 , unsigned long * V_513 ,
unsigned long V_146 , unsigned long * V_514 )
{
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_44 = 0 ;
unsigned long V_121 = 0 ;
F_4 ( V_9 -> V_426 || V_9 -> V_543 ) ;
F_8 ( V_9 ) ;
V_9 -> V_140 = V_13 ;
V_9 -> V_146 = V_146 ;
V_9 -> V_489 = NULL ;
#ifdef F_454
F_482 ( V_13 , & V_44 , & V_121 ) ;
F_71 ( L_94 , V_13 ,
( V_544 ) V_44 << V_17 ,
V_121 ? ( ( V_544 ) V_121 << V_17 ) - 1 : 0 ) ;
#else
V_44 = V_146 ;
#endif
F_490 ( V_9 , V_44 , V_121 ,
V_513 , V_514 ) ;
F_508 ( V_9 ) ;
#ifdef F_509
F_389 ( V_491 L_95 ,
V_13 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_539 ) ;
#endif
F_497 ( V_9 ) ;
}
void T_4 F_514 ( void )
{
unsigned int V_545 ;
V_545 = F_515 ( V_546 . V_547 , V_451 ) ;
V_548 = V_545 + 1 ;
}
unsigned long T_4 F_516 ( void )
{
unsigned long V_549 = 0 , V_495 = 0 ;
unsigned long V_119 , V_120 , V_26 ;
int V_496 = - 1 ;
int V_60 , V_13 ;
F_188 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_119 || V_496 < 0 || V_496 == V_13 ) {
V_496 = V_13 ;
V_495 = V_120 ;
continue;
}
V_26 = ~ ( ( 1 << F_517 ( V_119 ) ) - 1 ) ;
while ( V_26 && V_495 <= ( V_119 & ( V_26 << 1 ) ) )
V_26 <<= 1 ;
V_549 |= V_26 ;
}
return ~ V_549 + 1 ;
}
static unsigned long T_4 F_518 ( int V_13 )
{
unsigned long V_550 = V_11 ;
unsigned long V_44 ;
int V_60 ;
F_188 (i, nid, &start_pfn, NULL, NULL)
V_550 = F_177 ( V_550 , V_44 ) ;
if ( V_550 == V_11 ) {
F_315 ( L_96 , V_13 ) ;
return 0 ;
}
return V_550 ;
}
unsigned long T_4 F_519 ( void )
{
return F_518 ( V_451 ) ;
}
static unsigned long T_4 F_520 ( void )
{
unsigned long V_516 = 0 ;
unsigned long V_44 , V_121 ;
int V_60 , V_13 ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_174 = V_121 - V_44 ;
V_516 += V_174 ;
if ( V_174 )
F_521 ( V_13 , V_151 ) ;
}
return V_516 ;
}
static void T_4 F_522 ( void )
{
int V_60 , V_13 ;
unsigned long V_551 ;
unsigned long V_552 , V_553 ;
T_10 V_554 = V_555 [ V_151 ] ;
unsigned long V_516 = F_520 () ;
int V_556 = F_523 ( V_555 [ V_151 ] ) ;
struct V_479 * V_480 ;
F_483 () ;
if ( F_524 () ) {
F_457 (memory, r) {
if ( ! F_525 ( V_480 ) )
continue;
V_13 = V_480 -> V_13 ;
V_551 = F_157 ( V_480 -> V_557 ) ;
V_506 [ V_13 ] = V_506 [ V_13 ] ?
F_177 ( V_551 , V_506 [ V_13 ] ) :
V_551 ;
}
goto V_558;
}
if ( V_486 ) {
bool V_559 = false ;
F_457 (memory, r) {
if ( F_459 ( V_480 ) )
continue;
V_13 = V_480 -> V_13 ;
V_551 = F_458 ( V_480 ) ;
if ( V_551 < 0x100000 ) {
V_559 = true ;
continue;
}
V_506 [ V_13 ] = V_506 [ V_13 ] ?
F_177 ( V_551 , V_506 [ V_13 ] ) :
V_551 ;
}
if ( V_559 )
F_315 ( L_97 ) ;
goto V_558;
}
if ( V_560 ) {
unsigned long V_561 ;
V_560 =
F_492 ( V_560 , V_153 ) ;
V_560 = F_177 ( V_516 , V_560 ) ;
V_561 = V_516 - V_560 ;
V_562 = F_15 ( V_562 , V_561 ) ;
}
if ( ! V_562 || V_562 >= V_516 )
goto V_53;
V_551 = V_503 [ V_504 ] ;
V_563:
V_552 = V_562 / V_556 ;
F_195 (nid, N_MEMORY) {
unsigned long V_44 , V_121 ;
if ( V_562 < V_552 )
V_552 = V_562 / V_556 ;
V_553 = V_552 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_564 ;
V_44 = F_15 ( V_44 , V_506 [ V_13 ] ) ;
if ( V_44 >= V_121 )
continue;
if ( V_44 < V_551 ) {
unsigned long V_565 ;
V_565 = F_177 ( V_121 , V_551 )
- V_44 ;
V_553 -= F_177 ( V_565 ,
V_553 ) ;
V_562 -= F_177 ( V_565 ,
V_562 ) ;
if ( V_121 <= V_551 ) {
V_506 [ V_13 ] = V_121 ;
continue;
}
V_44 = V_551 ;
}
V_564 = V_121 - V_44 ;
if ( V_564 > V_553 )
V_564 = V_553 ;
V_506 [ V_13 ] = V_44 + V_564 ;
V_562 -= F_177 ( V_562 ,
V_564 ) ;
V_553 -= V_564 ;
if ( ! V_553 )
break;
}
}
V_556 -- ;
if ( V_556 && V_562 > V_556 )
goto V_563;
V_558:
for ( V_13 = 0 ; V_13 < V_451 ; V_13 ++ )
V_506 [ V_13 ] =
F_492 ( V_506 [ V_13 ] , V_153 ) ;
V_53:
V_555 [ V_151 ] = V_554 ;
}
static void F_526 ( T_1 * V_9 , int V_13 )
{
enum V_387 V_387 ;
if ( V_151 == V_566 )
return;
for ( V_387 = 0 ; V_387 <= V_487 - 1 ; V_387 ++ ) {
struct V_40 * V_40 = & V_9 -> V_118 [ V_387 ] ;
if ( F_190 ( V_40 ) ) {
F_521 ( V_13 , V_567 ) ;
if ( V_566 != V_567 &&
V_387 <= V_288 )
F_521 ( V_13 , V_566 ) ;
break;
}
}
}
void T_4 F_527 ( unsigned long * V_203 )
{
unsigned long V_44 , V_121 ;
int V_60 , V_13 ;
memset ( V_503 , 0 ,
sizeof( V_503 ) ) ;
memset ( V_502 , 0 ,
sizeof( V_502 ) ) ;
V_44 = F_519 () ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
if ( V_60 == V_487 )
continue;
V_121 = F_15 ( V_203 [ V_60 ] , V_44 ) ;
V_503 [ V_60 ] = V_44 ;
V_502 [ V_60 ] = V_121 ;
V_44 = V_121 ;
}
V_503 [ V_487 ] = 0 ;
V_502 [ V_487 ] = 0 ;
memset ( V_506 , 0 , sizeof( V_506 ) ) ;
F_522 () ;
F_71 ( L_98 ) ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
if ( V_60 == V_487 )
continue;
F_71 ( L_99 , V_473 [ V_60 ] ) ;
if ( V_503 [ V_60 ] ==
V_502 [ V_60 ] )
F_316 ( L_100 ) ;
else
F_316 ( L_101 ,
( V_544 ) V_503 [ V_60 ]
<< V_17 ,
( ( V_544 ) V_502 [ V_60 ]
<< V_17 ) - 1 ) ;
}
F_71 ( L_102 ) ;
for ( V_60 = 0 ; V_60 < V_451 ; V_60 ++ ) {
if ( V_506 [ V_60 ] )
F_71 ( L_103 , V_60 ,
( V_544 ) V_506 [ V_60 ] << V_17 ) ;
}
F_71 ( L_104 ) ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_71 ( L_105 , V_13 ,
( V_544 ) V_44 << V_17 ,
( ( V_544 ) V_121 << V_17 ) - 1 ) ;
F_528 () ;
F_514 () ;
F_437 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_513 ( V_13 , NULL ,
F_518 ( V_13 ) , NULL ) ;
if ( V_9 -> V_518 )
F_521 ( V_13 , V_151 ) ;
F_526 ( V_9 , V_13 ) ;
}
}
static int T_4 F_529 ( char * V_63 , unsigned long * V_568 )
{
unsigned long long V_569 ;
if ( ! V_63 )
return - V_67 ;
V_569 = F_530 ( V_63 , & V_63 ) ;
* V_568 = V_569 >> V_17 ;
F_4 ( ( V_569 >> V_17 ) > V_11 ) ;
return 0 ;
}
static int T_4 F_531 ( char * V_63 )
{
if ( F_532 ( V_63 , L_106 ) ) {
V_486 = true ;
return 0 ;
}
return F_529 ( V_63 , & V_562 ) ;
}
static int T_4 F_533 ( char * V_63 )
{
return F_529 ( V_63 , & V_560 ) ;
}
void F_201 ( struct V_1 * V_1 , long V_103 )
{
F_137 ( & V_570 ) ;
F_19 ( V_1 ) -> V_124 += V_103 ;
V_378 += V_103 ;
#ifdef F_399
if ( F_126 ( V_1 ) )
V_384 += V_103 ;
#endif
F_143 ( & V_570 ) ;
}
unsigned long F_534 ( void * V_119 , void * V_120 , int V_571 , char * V_427 )
{
void * V_458 ;
unsigned long V_174 = 0 ;
V_119 = ( void * ) F_377 ( ( unsigned long ) V_119 ) ;
V_120 = ( void * ) ( ( unsigned long ) V_120 & V_572 ) ;
for ( V_458 = V_119 ; V_458 < V_120 ; V_458 += V_102 , V_174 ++ ) {
if ( ( unsigned int ) V_571 <= 0xFF )
memset ( V_458 , V_571 , V_102 ) ;
F_535 ( F_271 ( V_458 ) ) ;
}
if ( V_174 && V_427 )
F_71 ( L_107 ,
V_427 , V_174 << ( V_17 - 10 ) , V_119 , V_120 ) ;
return V_174 ;
}
void F_536 ( struct V_1 * V_1 )
{
F_537 ( V_1 ) ;
V_378 ++ ;
F_19 ( V_1 ) -> V_124 ++ ;
V_384 ++ ;
}
void T_4 F_538 ( const char * V_225 )
{
unsigned long V_573 , V_574 , V_575 , V_576 , V_577 ;
unsigned long V_578 , V_579 ;
V_573 = F_539 () ;
V_574 = V_580 - V_581 ;
V_575 = V_582 - V_583 ;
V_576 = V_584 - V_585 ;
V_577 = V_586 - V_587 ;
V_579 = V_588 - V_589 ;
V_578 = V_590 - V_591 ;
#define F_540 ( V_119 , V_120 , V_157 , V_458 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_540 ( V_589 , V_588 , V_579 ,
V_591 , V_578 ) ;
F_540 ( V_581 , V_580 , V_574 , V_591 , V_578 ) ;
F_540 ( V_583 , V_582 , V_575 , V_589 , V_579 ) ;
F_540 ( V_581 , V_580 , V_574 , V_585 , V_576 ) ;
F_540 ( V_583 , V_582 , V_575 , V_585 , V_576 ) ;
#undef F_540
F_71 ( L_108
#ifdef F_399
L_109
#endif
L_110 ,
F_541 () << ( V_17 - 10 ) ,
V_573 << ( V_17 - 10 ) ,
V_574 >> 10 , V_575 >> 10 , V_576 >> 10 ,
( V_579 + V_578 ) >> 10 , V_577 >> 10 ,
( V_573 - V_378 - V_592 ) << ( V_17 - 10 ) ,
V_592 << ( V_17 - 10 ) ,
#ifdef F_399
V_384 << ( V_17 - 10 ) ,
#endif
V_225 ? L_111 : L_112 , V_225 ? V_225 : L_112 ) ;
}
void T_4 F_542 ( unsigned long V_593 )
{
V_536 = V_593 ;
}
void T_4 F_543 ( unsigned long * V_513 )
{
F_513 ( 0 , V_513 ,
F_544 ( V_594 ) >> V_17 , NULL ) ;
}
static int F_545 ( struct V_595 * V_467 ,
unsigned long V_596 , void * V_597 )
{
int V_196 = ( unsigned long ) V_597 ;
if ( V_596 == V_598 || V_596 == V_599 ) {
F_546 ( V_196 ) ;
F_247 ( V_196 ) ;
F_547 ( V_196 ) ;
F_548 ( V_196 ) ;
}
return V_600 ;
}
void T_4 F_549 ( void )
{
F_550 ( F_545 , 0 ) ;
}
static void F_551 ( void )
{
struct V_254 * V_9 ;
unsigned long V_601 = 0 ;
enum V_387 V_60 , V_453 ;
F_406 (pgdat) {
V_9 -> V_371 = 0 ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_60 ;
long F_15 = 0 ;
for ( V_453 = V_60 ; V_453 < V_117 ; V_453 ++ ) {
if ( V_40 -> V_248 [ V_453 ] > F_15 )
F_15 = V_40 -> V_248 [ V_453 ] ;
}
F_15 += F_385 ( V_40 ) ;
if ( F_15 > V_40 -> V_124 )
F_15 = V_40 -> V_124 ;
V_9 -> V_371 += F_15 ;
V_601 += F_15 ;
}
}
V_371 = V_601 ;
}
static void F_552 ( void )
{
struct V_254 * V_9 ;
enum V_387 V_453 , V_602 ;
F_406 (pgdat) {
for ( V_453 = 0 ; V_453 < V_117 ; V_453 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_453 ;
unsigned long V_124 = V_40 -> V_124 ;
V_40 -> V_248 [ V_453 ] = 0 ;
V_602 = V_453 ;
while ( V_602 ) {
struct V_40 * V_603 ;
V_602 -- ;
if ( V_604 [ V_602 ] < 1 )
V_604 [ V_602 ] = 1 ;
V_603 = V_9 -> V_118 + V_602 ;
V_603 -> V_248 [ V_453 ] = V_124 /
V_604 [ V_602 ] ;
V_124 += V_603 -> V_124 ;
}
}
}
F_551 () ;
}
static void F_553 ( void )
{
unsigned long V_605 = V_606 >> ( V_17 - 10 ) ;
unsigned long V_607 = 0 ;
struct V_40 * V_40 ;
unsigned long V_34 ;
F_392 (zone) {
if ( ! F_400 ( V_40 ) )
V_607 += V_40 -> V_124 ;
}
F_392 (zone) {
V_544 V_392 ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
V_392 = ( V_544 ) V_605 * V_40 -> V_124 ;
F_554 ( V_392 , V_607 ) ;
if ( F_400 ( V_40 ) ) {
unsigned long V_608 ;
V_608 = V_40 -> V_124 / 1024 ;
V_608 = F_487 ( V_608 , V_609 , 128UL ) ;
V_40 -> V_207 [ V_610 ] = V_608 ;
} else {
V_40 -> V_207 [ V_610 ] = V_392 ;
}
V_392 = F_555 ( V_544 , V_392 >> 2 ,
F_556 ( V_40 -> V_124 ,
V_611 , 10000 ) ) ;
V_40 -> V_207 [ V_370 ] = F_274 ( V_40 ) + V_392 ;
V_40 -> V_207 [ V_612 ] = F_274 ( V_40 ) + V_392 * 2 ;
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
F_551 () ;
}
void F_557 ( void )
{
F_423 ( & V_443 ) ;
F_553 () ;
F_322 ( & V_443 ) ;
}
int T_2 F_558 ( void )
{
unsigned long V_613 ;
int V_614 ;
V_613 = F_386 () * ( V_102 >> 10 ) ;
V_614 = F_559 ( V_613 * 16 ) ;
if ( V_614 > V_615 ) {
V_606 = V_614 ;
if ( V_606 < 128 )
V_606 = 128 ;
if ( V_606 > 65536 )
V_606 = 65536 ;
} else {
F_315 ( L_113 ,
V_614 , V_615 ) ;
}
F_557 () ;
F_560 () ;
F_552 () ;
#ifdef F_277
F_561 () ;
F_562 () ;
#endif
return 0 ;
}
int F_563 ( struct V_434 * V_435 , int V_436 ,
void T_12 * V_437 , T_11 * V_438 , T_13 * V_439 )
{
int V_616 ;
V_616 = F_564 ( V_435 , V_436 , V_437 , V_438 , V_439 ) ;
if ( V_616 )
return V_616 ;
if ( V_436 ) {
V_615 = V_606 ;
F_557 () ;
}
return 0 ;
}
int F_565 ( struct V_434 * V_435 , int V_436 ,
void T_12 * V_437 , T_11 * V_438 , T_13 * V_439 )
{
int V_616 ;
V_616 = F_564 ( V_435 , V_436 , V_437 , V_438 , V_439 ) ;
if ( V_616 )
return V_616 ;
if ( V_436 )
F_557 () ;
return 0 ;
}
static void F_561 ( void )
{
T_1 * V_9 ;
struct V_40 * V_40 ;
F_406 (pgdat)
V_9 -> V_617 = 0 ;
F_392 (zone)
V_40 -> V_110 -> V_617 += ( V_40 -> V_124 *
V_618 ) / 100 ;
}
int F_566 ( struct V_434 * V_435 , int V_436 ,
void T_12 * V_437 , T_11 * V_438 , T_13 * V_439 )
{
int V_616 ;
V_616 = F_564 ( V_435 , V_436 , V_437 , V_438 , V_439 ) ;
if ( V_616 )
return V_616 ;
F_561 () ;
return 0 ;
}
static void F_562 ( void )
{
T_1 * V_9 ;
struct V_40 * V_40 ;
F_406 (pgdat)
V_9 -> V_619 = 0 ;
F_392 (zone)
V_40 -> V_110 -> V_619 += ( V_40 -> V_124 *
V_620 ) / 100 ;
}
int F_567 ( struct V_434 * V_435 , int V_436 ,
void T_12 * V_437 , T_11 * V_438 , T_13 * V_439 )
{
int V_616 ;
V_616 = F_564 ( V_435 , V_436 , V_437 , V_438 , V_439 ) ;
if ( V_616 )
return V_616 ;
F_562 () ;
return 0 ;
}
int F_568 ( struct V_434 * V_435 , int V_436 ,
void T_12 * V_437 , T_11 * V_438 , T_13 * V_439 )
{
F_564 ( V_435 , V_436 , V_437 , V_438 , V_439 ) ;
F_552 () ;
return 0 ;
}
int F_569 ( struct V_434 * V_435 , int V_436 ,
void T_12 * V_437 , T_11 * V_438 , T_13 * V_439 )
{
struct V_40 * V_40 ;
int V_621 ;
int V_41 ;
F_423 ( & V_622 ) ;
V_621 = V_488 ;
V_41 = F_564 ( V_435 , V_436 , V_437 , V_438 , V_439 ) ;
if ( ! V_436 || V_41 < 0 )
goto V_53;
if ( V_488 &&
V_488 < V_623 ) {
V_488 = V_621 ;
V_41 = - V_67 ;
goto V_53;
}
if ( V_488 == V_621 )
goto V_53;
F_199 (zone) {
unsigned int V_196 ;
F_438 (cpu)
F_469 ( V_40 ,
F_246 ( V_40 -> V_199 , V_196 ) ) ;
}
V_53:
F_322 ( & V_622 ) ;
return V_41 ;
}
static int T_4 F_570 ( char * V_225 )
{
if ( ! V_225 )
return 0 ;
V_624 = F_571 ( V_225 , & V_225 , 0 ) ;
return 1 ;
}
static unsigned long T_4 F_572 ( void )
{
return 0 ;
}
void * T_4 F_573 ( const char * V_625 ,
unsigned long V_626 ,
unsigned long V_627 ,
int V_628 ,
int V_34 ,
unsigned int * V_629 ,
unsigned int * V_630 ,
unsigned long V_631 ,
unsigned long V_632 )
{
unsigned long long F_15 = V_632 ;
unsigned long V_633 , V_157 ;
void * V_435 = NULL ;
if ( ! V_627 ) {
V_627 = V_537 ;
V_627 -= F_572 () ;
if ( V_17 < 20 )
V_627 = F_574 ( V_627 , ( 1 << 20 ) / V_102 ) ;
if ( V_628 > V_17 )
V_627 >>= ( V_628 - V_17 ) ;
else
V_627 <<= ( V_17 - V_628 ) ;
if ( F_32 ( V_34 & V_634 ) ) {
F_4 ( ! ( V_34 & V_635 ) ) ;
if ( ! ( V_627 >> * V_629 ) ) {
V_627 = 1UL << * V_629 ;
F_187 ( ! V_627 ) ;
}
} else if ( F_32 ( ( V_627 * V_626 ) < V_102 ) )
V_627 = V_102 / V_626 ;
}
V_627 = F_575 ( V_627 ) ;
if ( F_15 == 0 ) {
F_15 = ( ( unsigned long long ) V_538 << V_17 ) >> 4 ;
F_554 ( F_15 , V_626 ) ;
}
F_15 = F_177 ( F_15 , 0x80000000ULL ) ;
if ( V_627 < V_631 )
V_627 = V_631 ;
if ( V_627 > F_15 )
V_627 = F_15 ;
V_633 = F_576 ( V_627 ) ;
do {
V_157 = V_626 << V_633 ;
if ( V_34 & V_635 )
V_435 = F_577 ( V_157 , 0 ) ;
else if ( V_624 )
V_435 = F_578 ( V_157 , V_636 , V_637 ) ;
else {
if ( F_380 ( V_157 ) < V_71 ) {
V_435 = F_379 ( V_157 , V_636 ) ;
F_579 ( V_435 , V_157 , 1 , V_636 ) ;
}
}
} while ( ! V_435 && V_157 > V_102 && -- V_633 );
if ( ! V_435 )
F_580 ( L_114 , V_625 ) ;
F_71 ( L_115 ,
V_625 , 1UL << V_633 , F_576 ( V_157 ) - V_17 , V_157 ) ;
if ( V_629 )
* V_629 = V_633 ;
if ( V_630 )
* V_630 = ( 1 << V_633 ) - 1 ;
return V_435 ;
}
bool F_581 ( struct V_40 * V_40 , struct V_1 * V_1 , int V_103 ,
bool V_638 )
{
unsigned long V_12 , V_639 , V_640 ;
int V_115 ;
if ( V_425 ( V_40 ) == V_487 )
return false ;
V_115 = F_100 ( V_1 ) ;
if ( V_115 == V_136 || F_233 ( V_115 ) )
return false ;
V_12 = F_35 ( V_1 ) ;
for ( V_640 = 0 , V_639 = 0 ; V_639 < V_24 ; V_639 ++ ) {
unsigned long V_641 = V_12 + V_639 ;
if ( ! F_41 ( V_641 ) )
continue;
V_1 = F_153 ( V_641 ) ;
if ( F_582 ( V_1 ) ) {
V_639 = F_574 ( V_639 + 1 , 1 << F_54 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_105 ( V_1 ) ) {
if ( F_91 ( V_1 ) )
V_639 += ( 1 << F_88 ( V_1 ) ) - 1 ;
continue;
}
if ( V_638 && F_583 ( V_1 ) )
continue;
if ( ! F_584 ( V_1 ) )
V_640 ++ ;
if ( V_640 > V_103 )
return true ;
}
return false ;
}
bool F_585 ( struct V_1 * V_1 )
{
struct V_40 * V_40 ;
unsigned long V_12 ;
if ( ! F_11 ( F_224 ( V_1 ) ) )
return false ;
V_40 = F_19 ( V_1 ) ;
V_12 = F_35 ( V_1 ) ;
if ( ! F_28 ( V_40 , V_12 ) )
return false ;
return ! F_581 ( V_40 , V_1 , 0 , true ) ;
}
static unsigned long F_586 ( unsigned long V_12 )
{
return V_12 & ~ ( F_555 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_587 ( unsigned long V_12 )
{
return F_176 ( V_12 , F_555 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_588 ( struct V_642 * V_643 ,
unsigned long V_119 , unsigned long V_120 )
{
unsigned long V_644 ;
unsigned long V_12 = V_119 ;
unsigned int V_645 = 0 ;
int V_41 = 0 ;
F_589 () ;
while ( V_12 < V_120 || ! F_140 ( & V_643 -> V_646 ) ) {
if ( F_590 ( V_55 ) ) {
V_41 = - V_647 ;
break;
}
if ( F_140 ( & V_643 -> V_646 ) ) {
V_643 -> V_648 = 0 ;
V_12 = F_591 ( V_643 , V_12 , V_120 ) ;
if ( ! V_12 ) {
V_41 = - V_647 ;
break;
}
V_645 = 0 ;
} else if ( ++ V_645 == 5 ) {
V_41 = V_41 < 0 ? V_41 : - V_649 ;
break;
}
V_644 = F_592 ( V_643 -> V_40 ,
& V_643 -> V_646 ) ;
V_643 -> V_648 -= V_644 ;
V_41 = F_593 ( & V_643 -> V_646 , V_650 ,
NULL , 0 , V_643 -> V_234 , V_651 ) ;
}
if ( V_41 < 0 ) {
F_594 ( & V_643 -> V_646 ) ;
return V_41 ;
}
return 0 ;
}
int F_595 ( unsigned long V_119 , unsigned long V_120 ,
unsigned V_3 )
{
unsigned long V_652 , V_653 ;
unsigned int V_59 ;
int V_41 = 0 ;
struct V_642 V_643 = {
. V_648 = 0 ,
. V_59 = - 1 ,
. V_40 = F_19 ( F_153 ( V_119 ) ) ,
. V_234 = V_654 ,
. V_655 = true ,
} ;
F_76 ( & V_643 . V_646 ) ;
V_41 = F_596 ( F_586 ( V_119 ) ,
F_587 ( V_120 ) , V_3 ,
false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_588 ( & V_643 , V_119 , V_120 ) ;
if ( V_41 && V_41 != - V_649 )
goto V_656;
F_597 () ;
F_250 ( V_643 . V_40 ) ;
V_59 = 0 ;
V_652 = V_119 ;
while ( ! F_91 ( F_153 ( V_652 ) ) ) {
if ( ++ V_59 >= V_71 ) {
V_652 = V_119 ;
break;
}
V_652 &= ~ 0UL << V_59 ;
}
if ( V_652 != V_119 ) {
V_59 = F_88 ( F_153 ( V_652 ) ) ;
if ( V_652 + ( 1UL << V_59 ) <= V_119 )
V_652 = V_119 ;
}
if ( F_598 ( V_652 , V_120 , false ) ) {
F_71 ( L_116 ,
V_657 , V_652 , V_120 ) ;
V_41 = - V_649 ;
goto V_656;
}
V_653 = F_599 ( & V_643 , V_652 , V_120 ) ;
if ( ! V_653 ) {
V_41 = - V_649 ;
goto V_656;
}
if ( V_119 != V_652 )
F_600 ( V_652 , V_119 - V_652 ) ;
if ( V_120 != V_653 )
F_600 ( V_120 , V_653 - V_120 ) ;
V_656:
F_601 ( F_586 ( V_119 ) ,
F_587 ( V_120 ) , V_3 ) ;
return V_41 ;
}
void F_600 ( unsigned long V_12 , unsigned V_61 )
{
unsigned int V_103 = 0 ;
for (; V_61 -- ; V_12 ++ ) {
struct V_1 * V_1 = F_153 ( V_12 ) ;
V_103 += F_90 ( V_1 ) != 1 ;
F_602 ( V_1 ) ;
}
F_603 ( V_103 != 0 , L_117 , V_103 ) ;
}
void T_2 F_604 ( struct V_40 * V_40 )
{
unsigned V_196 ;
F_423 ( & V_622 ) ;
F_438 (cpu)
F_469 ( V_40 ,
F_246 ( V_40 -> V_199 , V_196 ) ) ;
F_322 ( & V_622 ) ;
}
void F_605 ( struct V_40 * V_40 )
{
unsigned long V_34 ;
int V_196 ;
struct V_197 * V_198 ;
F_161 ( V_34 ) ;
if ( V_40 -> V_199 != & V_468 ) {
F_251 (cpu) {
V_198 = F_246 ( V_40 -> V_199 , V_196 ) ;
F_606 ( V_40 , V_198 ) ;
}
F_607 ( V_40 -> V_199 ) ;
V_40 -> V_199 = & V_468 ;
}
F_163 ( V_34 ) ;
}
void
F_608 ( unsigned long V_44 , unsigned long V_121 )
{
struct V_1 * V_1 ;
struct V_40 * V_40 ;
unsigned int V_59 , V_60 ;
unsigned long V_12 ;
unsigned long V_34 ;
for ( V_12 = V_44 ; V_12 < V_121 ; V_12 ++ )
if ( F_159 ( V_12 ) )
break;
if ( V_12 == V_121 )
return;
V_40 = F_19 ( F_153 ( V_12 ) ) ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
V_12 = V_44 ;
while ( V_12 < V_121 ) {
if ( ! F_159 ( V_12 ) ) {
V_12 ++ ;
continue;
}
V_1 = F_153 ( V_12 ) ;
if ( F_32 ( ! F_91 ( V_1 ) && F_583 ( V_1 ) ) ) {
V_12 ++ ;
F_160 ( V_1 ) ;
continue;
}
F_187 ( F_90 ( V_1 ) ) ;
F_187 ( ! F_91 ( V_1 ) ) ;
V_59 = F_88 ( V_1 ) ;
#ifdef V_98
F_71 ( L_118 ,
V_12 , 1 << V_59 , V_121 ) ;
#endif
F_98 ( & V_1 -> V_75 ) ;
F_84 ( V_1 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_160 ( ( V_1 + V_60 ) ) ;
V_12 += ( 1 << V_59 ) ;
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
bool F_609 ( struct V_1 * V_1 )
{
struct V_40 * V_40 = F_19 ( V_1 ) ;
unsigned long V_12 = F_35 ( V_1 ) ;
unsigned long V_34 ;
unsigned int V_59 ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_1 * V_658 = V_1 - ( V_12 & ( ( 1 << V_59 ) - 1 ) ) ;
if ( F_91 ( V_658 ) && F_88 ( V_658 ) >= V_59 )
break;
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
return V_59 < V_71 ;
}
