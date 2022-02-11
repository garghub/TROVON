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
unsigned long V_10 ;
unsigned long V_11 ;
V_10 = F_9 ( 2UL << ( 30 - V_12 ) ,
( V_9 -> V_13 >> 8 ) ) ;
V_11 = F_10 ( V_9 -> V_14 ,
V_9 -> V_14 + V_10 ) ;
V_10 += V_11 ;
V_9 -> V_15 = F_11 ( V_10 , V_9 -> V_13 ) ;
V_9 -> V_16 = V_17 ;
}
static inline bool T_2 F_12 ( unsigned long V_18 )
{
int V_19 = F_13 ( V_18 ) ;
if ( F_14 ( V_19 ) && V_18 >= F_15 ( V_19 ) -> V_16 )
return true ;
return false ;
}
static inline bool F_16 ( T_1 * V_9 ,
unsigned long V_18 , unsigned long V_20 ,
unsigned long * V_21 )
{
if ( V_20 < F_17 ( V_9 ) )
return true ;
( * V_21 ) ++ ;
if ( ( * V_21 > V_9 -> V_15 ) &&
( V_18 & ( V_22 - 1 ) ) == 0 ) {
V_9 -> V_16 = V_18 ;
return false ;
}
return true ;
}
static inline void F_8 ( T_1 * V_9 )
{
}
static inline bool F_12 ( unsigned long V_18 )
{
return false ;
}
static inline bool F_16 ( T_1 * V_9 ,
unsigned long V_18 , unsigned long V_20 ,
unsigned long * V_21 )
{
return true ;
}
static inline unsigned long * F_18 ( struct V_1 * V_1 ,
unsigned long V_18 )
{
#ifdef F_19
return F_20 ( V_18 ) -> V_23 ;
#else
return F_21 ( V_1 ) -> V_23 ;
#endif
}
static inline int F_22 ( struct V_1 * V_1 , unsigned long V_18 )
{
#ifdef F_19
V_18 &= ( V_22 - 1 ) ;
return ( V_18 >> V_24 ) * V_25 ;
#else
V_18 = V_18 - F_23 ( F_21 ( V_1 ) -> V_26 , V_27 ) ;
return ( V_18 >> V_24 ) * V_25 ;
#endif
}
static T_3 unsigned long F_24 ( struct V_1 * V_1 ,
unsigned long V_18 ,
unsigned long V_28 ,
unsigned long V_29 )
{
unsigned long * V_30 ;
unsigned long V_31 , V_32 ;
unsigned long V_33 ;
V_30 = F_18 ( V_1 , V_18 ) ;
V_31 = F_22 ( V_1 , V_18 ) ;
V_32 = V_31 / V_34 ;
V_31 &= ( V_34 - 1 ) ;
V_33 = V_30 [ V_32 ] ;
V_31 += V_28 ;
return ( V_33 >> ( V_34 - V_31 - 1 ) ) & V_29 ;
}
unsigned long F_25 ( struct V_1 * V_1 , unsigned long V_18 ,
unsigned long V_28 ,
unsigned long V_29 )
{
return F_24 ( V_1 , V_18 , V_28 , V_29 ) ;
}
static T_3 int F_26 ( struct V_1 * V_1 , unsigned long V_18 )
{
return F_24 ( V_1 , V_18 , V_35 , V_36 ) ;
}
void F_27 ( struct V_1 * V_1 , unsigned long V_37 ,
unsigned long V_18 ,
unsigned long V_28 ,
unsigned long V_29 )
{
unsigned long * V_30 ;
unsigned long V_31 , V_32 ;
unsigned long V_38 , V_33 ;
F_28 ( V_25 != 4 ) ;
V_30 = F_18 ( V_1 , V_18 ) ;
V_31 = F_22 ( V_1 , V_18 ) ;
V_32 = V_31 / V_34 ;
V_31 &= ( V_34 - 1 ) ;
F_29 ( ! F_30 ( F_21 ( V_1 ) , V_18 ) , V_1 ) ;
V_31 += V_28 ;
V_29 <<= ( V_34 - V_31 - 1 ) ;
V_37 <<= ( V_34 - V_31 - 1 ) ;
V_33 = F_31 ( V_30 [ V_32 ] ) ;
for (; ; ) {
V_38 = F_32 ( & V_30 [ V_32 ] , V_33 , ( V_33 & ~ V_29 ) | V_37 ) ;
if ( V_33 == V_38 )
break;
V_33 = V_38 ;
}
}
void F_33 ( struct V_1 * V_1 , int V_3 )
{
if ( F_34 ( V_39 &&
V_3 < V_40 ) )
V_3 = V_41 ;
F_35 ( V_1 , ( unsigned long ) V_3 ,
V_42 , V_35 ) ;
}
static int F_36 ( struct V_43 * V_43 , struct V_1 * V_1 )
{
int V_44 = 0 ;
unsigned V_45 ;
unsigned long V_18 = F_37 ( V_1 ) ;
unsigned long V_46 , V_47 ;
do {
V_45 = F_38 ( V_43 ) ;
V_47 = V_43 -> V_26 ;
V_46 = V_43 -> V_48 ;
if ( ! F_30 ( V_43 , V_18 ) )
V_44 = 1 ;
} while ( F_39 ( V_43 , V_45 ) );
if ( V_44 )
F_40 ( L_1 ,
V_18 , F_41 ( V_43 ) , V_43 -> V_49 ,
V_47 , V_47 + V_46 ) ;
return V_44 ;
}
static int F_42 ( struct V_43 * V_43 , struct V_1 * V_1 )
{
if ( ! F_43 ( F_37 ( V_1 ) ) )
return 0 ;
if ( V_43 != F_21 ( V_1 ) )
return 0 ;
return 1 ;
}
static int T_4 F_44 ( struct V_43 * V_43 , struct V_1 * V_1 )
{
if ( F_36 ( V_43 , V_1 ) )
return 1 ;
if ( ! F_42 ( V_43 , V_1 ) )
return 1 ;
return 0 ;
}
static inline int T_4 F_44 ( struct V_43 * V_43 , struct V_1 * V_1 )
{
return 0 ;
}
static void F_45 ( struct V_1 * V_1 , const char * V_50 ,
unsigned long V_51 )
{
static unsigned long V_52 ;
static unsigned long V_53 ;
static unsigned long V_54 ;
if ( V_53 == 60 ) {
if ( F_46 ( V_55 , V_52 ) ) {
V_54 ++ ;
goto V_56;
}
if ( V_54 ) {
F_47 (
L_2 ,
V_54 ) ;
V_54 = 0 ;
}
V_53 = 0 ;
}
if ( V_53 ++ == 0 )
V_52 = V_55 + 60 * V_57 ;
F_47 ( L_3 ,
V_58 -> V_59 , F_37 ( V_1 ) ) ;
F_48 ( V_1 , V_50 ) ;
V_51 &= V_1 -> V_37 ;
if ( V_51 )
F_47 ( L_4 ,
V_51 , & V_51 ) ;
F_49 ( V_1 ) ;
F_50 () ;
F_51 () ;
V_56:
F_52 ( V_1 ) ;
F_53 ( V_60 , V_61 ) ;
}
void F_54 ( struct V_1 * V_1 )
{
F_55 ( V_1 , F_56 ( V_1 ) ) ;
}
void F_57 ( struct V_1 * V_1 , unsigned int V_62 )
{
int V_63 ;
int V_64 = 1 << V_62 ;
F_58 ( V_1 , V_65 ) ;
F_59 ( V_1 , V_62 ) ;
F_60 ( V_1 ) ;
for ( V_63 = 1 ; V_63 < V_64 ; V_63 ++ ) {
struct V_1 * V_66 = V_1 + V_63 ;
F_61 ( V_66 , 0 ) ;
V_66 -> V_67 = V_68 ;
F_62 ( V_66 , V_1 ) ;
}
F_63 ( F_64 ( V_1 ) , - 1 ) ;
}
static int T_5 F_65 ( char * V_69 )
{
if ( ! V_69 )
return - V_70 ;
return F_66 ( V_69 , & V_71 ) ;
}
static bool F_67 ( void )
{
if ( ! F_68 () )
return false ;
if ( ! F_69 () )
return false ;
return true ;
}
static void F_70 ( void )
{
if ( ! F_68 () )
return;
if ( ! F_69 () )
return;
V_72 = true ;
}
static int T_5 F_71 ( char * V_69 )
{
unsigned long V_73 ;
if ( F_72 ( V_69 , 10 , & V_73 ) < 0 || V_73 > V_74 / 2 ) {
F_40 ( L_5 ) ;
return 0 ;
}
V_75 = V_73 ;
F_73 ( L_6 , V_73 ) ;
return 0 ;
}
static inline bool F_74 ( struct V_43 * V_43 , struct V_1 * V_1 ,
unsigned int V_62 , int V_3 )
{
struct V_76 * V_76 ;
if ( ! F_75 () )
return false ;
if ( V_62 >= F_69 () )
return false ;
V_76 = F_76 ( V_1 ) ;
if ( F_34 ( ! V_76 ) )
return false ;
F_77 ( V_77 , & V_76 -> V_37 ) ;
F_78 ( & V_1 -> V_78 ) ;
F_79 ( V_1 , V_62 ) ;
F_80 ( V_43 , - ( 1 << V_62 ) , V_3 ) ;
return true ;
}
static inline void F_81 ( struct V_43 * V_43 , struct V_1 * V_1 ,
unsigned int V_62 , int V_3 )
{
struct V_76 * V_76 ;
if ( ! F_75 () )
return;
V_76 = F_76 ( V_1 ) ;
if ( F_34 ( ! V_76 ) )
return;
F_82 ( V_77 , & V_76 -> V_37 ) ;
F_79 ( V_1 , 0 ) ;
if ( ! F_83 ( V_3 ) )
F_80 ( V_43 , ( 1 << V_62 ) , V_3 ) ;
}
static inline bool F_74 ( struct V_43 * V_43 , struct V_1 * V_1 ,
unsigned int V_62 , int V_3 ) { return false ; }
static inline void F_81 ( struct V_43 * V_43 , struct V_1 * V_1 ,
unsigned int V_62 , int V_3 ) {}
static inline void F_84 ( struct V_1 * V_1 , unsigned int V_62 )
{
F_79 ( V_1 , V_62 ) ;
F_85 ( V_1 ) ;
}
static inline void F_86 ( struct V_1 * V_1 )
{
F_87 ( V_1 ) ;
F_79 ( V_1 , 0 ) ;
}
static inline int F_88 ( struct V_1 * V_1 , struct V_1 * V_79 ,
unsigned int V_62 )
{
if ( F_89 ( V_79 ) && F_90 ( V_79 ) == V_62 ) {
if ( F_91 ( V_1 ) != F_91 ( V_79 ) )
return 0 ;
F_29 ( F_92 ( V_79 ) != 0 , V_79 ) ;
return 1 ;
}
if ( F_93 ( V_79 ) && F_90 ( V_79 ) == V_62 ) {
if ( F_91 ( V_1 ) != F_91 ( V_79 ) )
return 0 ;
F_29 ( F_92 ( V_79 ) != 0 , V_79 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_94 ( struct V_1 * V_1 ,
unsigned long V_18 ,
struct V_43 * V_43 , unsigned int V_62 ,
int V_3 )
{
unsigned long V_80 ;
unsigned long V_81 ( V_82 ) ;
struct V_1 * V_79 ;
unsigned int V_83 ;
V_83 = F_95 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
F_96 ( ! F_97 ( V_43 ) ) ;
F_29 ( V_1 -> V_37 & V_84 , V_1 ) ;
F_96 ( V_3 == - 1 ) ;
if ( F_98 ( ! F_83 ( V_3 ) ) )
F_80 ( V_43 , 1 << V_62 , V_3 ) ;
F_29 ( V_18 & ( ( 1 << V_62 ) - 1 ) , V_1 ) ;
F_29 ( F_44 ( V_43 , V_1 ) , V_1 ) ;
V_85:
while ( V_62 < V_83 - 1 ) {
V_82 = F_99 ( V_18 , V_62 ) ;
V_79 = V_1 + ( V_82 - V_18 ) ;
if ( ! F_43 ( V_82 ) )
goto V_86;
if ( ! F_88 ( V_1 , V_79 , V_62 ) )
goto V_86;
if ( F_89 ( V_79 ) ) {
F_81 ( V_43 , V_79 , V_62 , V_3 ) ;
} else {
F_100 ( & V_79 -> V_78 ) ;
V_43 -> V_87 [ V_62 ] . V_88 -- ;
F_86 ( V_79 ) ;
}
V_80 = V_82 & V_18 ;
V_1 = V_1 + ( V_80 - V_18 ) ;
V_18 = V_80 ;
V_62 ++ ;
}
if ( V_83 < V_74 ) {
if ( F_34 ( F_101 ( V_43 ) ) ) {
int V_89 ;
V_82 = F_99 ( V_18 , V_62 ) ;
V_79 = V_1 + ( V_82 - V_18 ) ;
V_89 = F_102 ( V_79 ) ;
if ( V_3 != V_89
&& ( F_83 ( V_3 ) ||
F_83 ( V_89 ) ) )
goto V_86;
}
V_83 ++ ;
goto V_85;
}
V_86:
F_84 ( V_1 , V_62 ) ;
if ( ( V_62 < V_74 - 2 ) && F_43 ( V_82 ) ) {
struct V_1 * V_90 , * V_91 ;
V_80 = V_82 & V_18 ;
V_90 = V_1 + ( V_80 - V_18 ) ;
V_82 = F_99 ( V_80 , V_62 + 1 ) ;
V_91 = V_90 + ( V_82 - V_80 ) ;
if ( F_43 ( V_82 ) &&
F_88 ( V_90 , V_91 , V_62 + 1 ) ) {
F_103 ( & V_1 -> V_78 ,
& V_43 -> V_87 [ V_62 ] . V_92 [ V_3 ] ) ;
goto V_56;
}
}
F_104 ( & V_1 -> V_78 , & V_43 -> V_87 [ V_62 ] . V_92 [ V_3 ] ) ;
V_56:
V_43 -> V_87 [ V_62 ] . V_88 ++ ;
}
static inline bool F_105 ( struct V_1 * V_1 ,
unsigned long V_93 )
{
if ( F_34 ( F_106 ( & V_1 -> V_94 ) != - 1 ) )
return false ;
if ( F_34 ( ( unsigned long ) V_1 -> V_67 |
F_107 ( V_1 ) |
#ifdef F_108
( unsigned long ) V_1 -> V_95 |
#endif
( V_1 -> V_37 & V_93 ) ) )
return false ;
return true ;
}
static void F_109 ( struct V_1 * V_1 )
{
const char * V_96 ;
unsigned long V_51 ;
V_96 = NULL ;
V_51 = 0 ;
if ( F_34 ( F_106 ( & V_1 -> V_94 ) != - 1 ) )
V_96 = L_7 ;
if ( F_34 ( V_1 -> V_67 != NULL ) )
V_96 = L_8 ;
if ( F_34 ( F_107 ( V_1 ) != 0 ) )
V_96 = L_9 ;
if ( F_34 ( V_1 -> V_37 & V_97 ) ) {
V_96 = L_10 ;
V_51 = V_97 ;
}
#ifdef F_108
if ( F_34 ( V_1 -> V_95 ) )
V_96 = L_11 ;
#endif
F_45 ( V_1 , V_96 , V_51 ) ;
}
static inline int F_110 ( struct V_1 * V_1 )
{
if ( F_98 ( F_105 ( V_1 , V_97 ) ) )
return 0 ;
F_109 ( V_1 ) ;
return 1 ;
}
static int F_111 ( struct V_1 * V_98 , struct V_1 * V_1 )
{
int V_44 = 1 ;
F_28 ( ( unsigned long ) V_99 & 1 ) ;
if ( ! F_112 ( V_100 ) ) {
V_44 = 0 ;
goto V_56;
}
switch ( V_1 - V_98 ) {
case 1 :
if ( F_34 ( F_113 ( V_1 ) ) ) {
F_45 ( V_1 , L_12 , 0 ) ;
goto V_56;
}
break;
case 2 :
break;
default:
if ( V_1 -> V_67 != V_68 ) {
F_45 ( V_1 , L_13 , 0 ) ;
goto V_56;
}
break;
}
if ( F_34 ( ! F_114 ( V_1 ) ) ) {
F_45 ( V_1 , L_14 , 0 ) ;
goto V_56;
}
if ( F_34 ( F_115 ( V_1 ) != V_98 ) ) {
F_45 ( V_1 , L_15 , 0 ) ;
goto V_56;
}
V_44 = 0 ;
V_56:
V_1 -> V_67 = NULL ;
F_116 ( V_1 ) ;
return V_44 ;
}
static T_3 bool F_117 ( struct V_1 * V_1 ,
unsigned int V_62 , bool V_101 )
{
int V_102 = 0 ;
F_29 ( F_114 ( V_1 ) , V_1 ) ;
F_118 ( V_1 , V_62 ) ;
F_119 ( V_1 , V_62 ) ;
if ( F_34 ( V_62 ) ) {
bool V_103 = F_120 ( V_1 ) ;
int V_63 ;
F_29 ( V_103 && F_56 ( V_1 ) != V_62 , V_1 ) ;
if ( V_103 )
F_121 ( V_1 ) ;
for ( V_63 = 1 ; V_63 < ( 1 << V_62 ) ; V_63 ++ ) {
if ( V_103 )
V_102 += F_111 ( V_1 , V_1 + V_63 ) ;
if ( F_34 ( F_110 ( V_1 + V_63 ) ) ) {
V_102 ++ ;
continue;
}
( V_1 + V_63 ) -> V_37 &= ~ V_84 ;
}
}
if ( F_122 ( V_1 ) )
V_1 -> V_67 = NULL ;
if ( F_123 () && F_124 ( V_1 ) )
F_125 ( V_1 , V_62 ) ;
if ( V_101 )
V_102 += F_110 ( V_1 ) ;
if ( V_102 )
return false ;
F_126 ( V_1 ) ;
V_1 -> V_37 &= ~ V_84 ;
F_127 ( V_1 , V_62 ) ;
if ( ! F_128 ( V_1 ) ) {
F_129 ( F_130 ( V_1 ) ,
V_104 << V_62 ) ;
F_131 ( F_130 ( V_1 ) ,
V_104 << V_62 ) ;
}
F_132 ( V_1 , V_62 ) ;
F_133 ( V_1 , 1 << V_62 , 0 ) ;
F_134 ( V_1 , 1 << V_62 , 0 ) ;
F_135 ( V_1 , V_62 ) ;
return true ;
}
static inline bool F_136 ( struct V_1 * V_1 )
{
return F_117 ( V_1 , 0 , true ) ;
}
static inline bool F_137 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_136 ( struct V_1 * V_1 )
{
return F_117 ( V_1 , 0 , false ) ;
}
static bool F_137 ( struct V_1 * V_1 )
{
return F_110 ( V_1 ) ;
}
static void F_138 ( struct V_43 * V_43 , int V_105 ,
struct V_106 * V_107 )
{
int V_3 = 0 ;
int V_108 = 0 ;
bool V_109 ;
F_139 ( & V_43 -> V_110 ) ;
V_109 = F_101 ( V_43 ) ;
while ( V_105 ) {
struct V_1 * V_1 ;
struct V_111 * V_112 ;
do {
V_108 ++ ;
if ( ++ V_3 == V_40 )
V_3 = 0 ;
V_112 = & V_107 -> V_113 [ V_3 ] ;
} while ( F_140 ( V_112 ) );
if ( V_108 == V_40 )
V_108 = V_105 ;
do {
int V_114 ;
V_1 = F_141 ( V_112 , struct V_1 , V_78 ) ;
F_100 ( & V_1 -> V_78 ) ;
V_114 = F_1 ( V_1 ) ;
F_29 ( F_83 ( V_114 ) , V_1 ) ;
if ( F_34 ( V_109 ) )
V_114 = F_102 ( V_1 ) ;
if ( F_137 ( V_1 ) )
continue;
F_94 ( V_1 , F_37 ( V_1 ) , V_43 , 0 , V_114 ) ;
F_142 ( V_1 , 0 , V_114 ) ;
} while ( -- V_105 && -- V_108 && ! F_140 ( V_112 ) );
}
F_143 ( & V_43 -> V_110 ) ;
}
static void F_144 ( struct V_43 * V_43 ,
struct V_1 * V_1 , unsigned long V_18 ,
unsigned int V_62 ,
int V_3 )
{
F_139 ( & V_43 -> V_110 ) ;
if ( F_34 ( F_101 ( V_43 ) ||
F_83 ( V_3 ) ) ) {
V_3 = F_26 ( V_1 , V_18 ) ;
}
F_94 ( V_1 , V_18 , V_43 , V_62 , V_3 ) ;
F_143 ( & V_43 -> V_110 ) ;
}
static void T_2 F_145 ( struct V_1 * V_1 , unsigned long V_18 ,
unsigned long V_43 , int V_19 )
{
F_146 ( V_1 , V_43 , V_19 , V_18 ) ;
F_147 ( V_1 ) ;
F_52 ( V_1 ) ;
F_126 ( V_1 ) ;
F_78 ( & V_1 -> V_78 ) ;
#ifdef F_148
if ( ! F_149 ( V_43 ) )
F_150 ( V_1 , F_151 ( V_18 << V_12 ) ) ;
#endif
}
static void T_2 F_152 ( unsigned long V_18 , unsigned long V_43 ,
int V_19 )
{
return F_145 ( F_153 ( V_18 ) , V_18 , V_43 , V_19 ) ;
}
static void F_154 ( unsigned long V_18 )
{
T_1 * V_9 ;
int V_19 , V_115 ;
if ( ! F_12 ( V_18 ) )
return;
V_19 = F_13 ( V_18 ) ;
V_9 = F_15 ( V_19 ) ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
struct V_43 * V_43 = & V_9 -> V_117 [ V_115 ] ;
if ( V_18 >= V_43 -> V_26 && V_18 < F_155 ( V_43 ) )
break;
}
F_152 ( V_18 , V_115 , V_19 ) ;
}
static inline void F_154 ( unsigned long V_18 )
{
}
void T_2 F_156 ( T_6 V_118 , T_6 V_119 )
{
unsigned long V_47 = F_157 ( V_118 ) ;
unsigned long V_120 = F_158 ( V_119 ) ;
for (; V_47 < V_120 ; V_47 ++ ) {
if ( F_159 ( V_47 ) ) {
struct V_1 * V_1 = F_153 ( V_47 ) ;
F_154 ( V_47 ) ;
F_78 ( & V_1 -> V_78 ) ;
F_160 ( V_1 ) ;
}
}
}
static void F_55 ( struct V_1 * V_1 , unsigned int V_62 )
{
unsigned long V_37 ;
int V_3 ;
unsigned long V_18 = F_37 ( V_1 ) ;
if ( ! F_117 ( V_1 , V_62 , true ) )
return;
V_3 = F_26 ( V_1 , V_18 ) ;
F_161 ( V_37 ) ;
F_162 ( V_121 , 1 << V_62 ) ;
F_144 ( F_21 ( V_1 ) , V_1 , V_18 , V_62 , V_3 ) ;
F_163 ( V_37 ) ;
}
static void T_5 F_164 ( struct V_1 * V_1 , unsigned int V_62 )
{
unsigned int V_64 = 1 << V_62 ;
struct V_1 * V_66 = V_1 ;
unsigned int V_122 ;
F_165 ( V_66 ) ;
for ( V_122 = 0 ; V_122 < ( V_64 - 1 ) ; V_122 ++ , V_66 ++ ) {
F_165 ( V_66 + 1 ) ;
F_166 ( V_66 ) ;
F_61 ( V_66 , 0 ) ;
}
F_166 ( V_66 ) ;
F_61 ( V_66 , 0 ) ;
F_21 ( V_1 ) -> V_123 += V_64 ;
F_167 ( V_1 ) ;
F_168 ( V_1 , V_62 ) ;
}
int T_2 F_13 ( unsigned long V_18 )
{
static F_169 ( V_124 ) ;
int V_19 ;
F_139 ( & V_124 ) ;
V_19 = F_170 ( V_18 , & V_125 ) ;
if ( V_19 < 0 )
V_19 = V_126 ;
F_143 ( & V_124 ) ;
return V_19 ;
}
static inline bool T_2 T_4
F_171 ( unsigned long V_18 , int V_127 ,
struct V_128 * V_129 )
{
int V_19 ;
V_19 = F_170 ( V_18 , V_129 ) ;
if ( V_19 >= 0 && V_19 != V_127 )
return false ;
return true ;
}
static inline bool T_2 F_172 ( unsigned long V_18 , int V_127 )
{
return F_171 ( V_18 , V_127 , & V_125 ) ;
}
static inline bool T_2 F_172 ( unsigned long V_18 , int V_127 )
{
return true ;
}
static inline bool T_2 T_4
F_171 ( unsigned long V_18 , int V_127 ,
struct V_128 * V_129 )
{
return true ;
}
void T_5 F_173 ( struct V_1 * V_1 , unsigned long V_18 ,
unsigned int V_62 )
{
if ( F_12 ( V_18 ) )
return;
return F_164 ( V_1 , V_62 ) ;
}
struct V_1 * F_174 ( unsigned long V_47 ,
unsigned long V_120 , struct V_43 * V_43 )
{
struct V_1 * V_130 ;
struct V_1 * V_131 ;
V_120 -- ;
if ( ! F_159 ( V_47 ) || ! F_159 ( V_120 ) )
return NULL ;
V_130 = F_175 ( V_47 ) ;
if ( ! V_130 )
return NULL ;
if ( F_21 ( V_130 ) != V_43 )
return NULL ;
V_131 = F_153 ( V_120 ) ;
if ( F_91 ( V_130 ) != F_91 ( V_131 ) )
return NULL ;
return V_130 ;
}
void F_176 ( struct V_43 * V_43 )
{
unsigned long V_132 = V_43 -> V_26 ;
unsigned long V_133 ;
V_133 = F_177 ( V_132 + 1 , V_27 ) ;
for (; V_132 < F_155 ( V_43 ) ;
V_132 = V_133 ,
V_133 += V_27 ) {
V_133 = F_11 ( V_133 , F_155 ( V_43 ) ) ;
if ( ! F_174 ( V_132 ,
V_133 , V_43 ) )
return;
}
V_43 -> V_134 = true ;
}
void F_178 ( struct V_43 * V_43 )
{
V_43 -> V_134 = false ;
}
static void T_5 F_179 ( struct V_1 * V_1 ,
unsigned long V_18 , int V_64 )
{
int V_63 ;
if ( ! V_1 )
return;
if ( V_64 == V_27 &&
( V_18 & ( V_27 - 1 ) ) == 0 ) {
F_33 ( V_1 , V_135 ) ;
F_164 ( V_1 , V_24 ) ;
return;
}
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ , V_1 ++ , V_18 ++ ) {
if ( ( V_18 & ( V_27 - 1 ) ) == 0 )
F_33 ( V_1 , V_135 ) ;
F_164 ( V_1 , 0 ) ;
}
}
static inline void T_5 F_180 ( void )
{
if ( F_181 ( & V_136 ) )
F_182 ( & V_137 ) ;
}
static int T_5 F_183 ( void * V_138 )
{
T_1 * V_9 = V_138 ;
int V_19 = V_9 -> V_139 ;
struct V_128 V_140 = { } ;
unsigned long V_118 = V_55 ;
unsigned long V_64 = 0 ;
unsigned long V_141 , V_142 ;
int V_63 , V_115 ;
struct V_43 * V_43 ;
unsigned long V_143 = V_9 -> V_16 ;
const struct V_144 * V_144 = F_184 ( V_9 -> V_139 ) ;
if ( V_143 == V_17 ) {
F_180 () ;
return 0 ;
}
if ( ! F_185 ( V_144 ) )
F_186 ( V_58 , V_144 ) ;
F_187 ( V_9 -> V_16 < V_9 -> V_14 ) ;
F_187 ( V_9 -> V_16 > F_17 ( V_9 ) ) ;
V_9 -> V_16 = V_17 ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
V_43 = V_9 -> V_117 + V_115 ;
if ( V_143 < F_155 ( V_43 ) )
break;
}
F_188 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_18 , V_120 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_145 = NULL ;
unsigned long V_146 = 0 ;
int V_147 = 0 ;
V_120 = F_11 ( V_142 , F_155 ( V_43 ) ) ;
V_18 = V_143 ;
if ( V_18 < V_141 )
V_18 = V_141 ;
if ( V_18 < V_43 -> V_26 )
V_18 = V_43 -> V_26 ;
for (; V_18 < V_120 ; V_18 ++ ) {
if ( ! F_43 ( V_18 ) )
goto V_148;
if ( ( V_18 & ( V_27 - 1 ) ) == 0 ) {
if ( ! F_159 ( V_18 ) ) {
V_1 = NULL ;
goto V_148;
}
}
if ( ! F_171 ( V_18 , V_19 , & V_140 ) ) {
V_1 = NULL ;
goto V_148;
}
if ( V_1 && ( V_18 & ( V_27 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_64 += V_147 ;
F_179 ( V_145 ,
V_146 , V_147 ) ;
V_145 = NULL ;
V_146 = V_147 = 0 ;
V_1 = F_153 ( V_18 ) ;
F_189 () ;
}
if ( V_1 -> V_37 ) {
F_96 ( F_21 ( V_1 ) != V_43 ) ;
goto V_148;
}
F_145 ( V_1 , V_18 , V_115 , V_19 ) ;
if ( ! V_145 ) {
V_145 = V_1 ;
V_146 = V_18 ;
V_147 = 0 ;
}
V_147 ++ ;
continue;
V_148:
V_64 += V_147 ;
F_179 ( V_145 , V_146 ,
V_147 ) ;
V_145 = NULL ;
V_146 = V_147 = 0 ;
}
V_64 += V_147 ;
F_179 ( V_145 , V_146 , V_147 ) ;
V_143 = F_9 ( V_120 , V_143 ) ;
}
F_4 ( ++ V_115 < V_116 && F_190 ( ++ V_43 ) ) ;
F_73 ( L_16 , V_19 , V_64 ,
F_191 ( V_55 - V_118 ) ) ;
F_180 () ;
return 0 ;
}
void T_5 F_192 ( void )
{
struct V_43 * V_43 ;
#ifdef F_193
int V_19 ;
F_63 ( & V_136 , F_194 ( V_149 ) ) ;
F_195 (nid, N_MEMORY) {
F_196 ( F_183 , F_15 ( V_19 ) , L_17 , V_19 ) ;
}
F_197 ( & V_137 ) ;
F_198 () ;
#endif
#ifdef F_199
F_200 () ;
#endif
F_201 (zone)
F_176 ( V_43 ) ;
}
void T_5 F_202 ( struct V_1 * V_1 )
{
unsigned V_63 = V_27 ;
struct V_1 * V_66 = V_1 ;
do {
F_166 ( V_66 ) ;
F_61 ( V_66 , 0 ) ;
} while ( ++ V_66 , -- V_63 );
F_33 ( V_1 , V_150 ) ;
if ( V_24 >= V_74 ) {
V_63 = V_27 ;
V_66 = V_1 ;
do {
F_167 ( V_66 ) ;
F_168 ( V_66 , V_74 - 1 ) ;
V_66 += V_151 ;
} while ( V_63 -= V_151 );
} else {
F_167 ( V_1 ) ;
F_168 ( V_1 , V_24 ) ;
}
F_203 ( V_1 , V_27 ) ;
}
static inline void F_204 ( struct V_43 * V_43 , struct V_1 * V_1 ,
int V_152 , int V_153 , struct V_87 * V_154 ,
int V_3 )
{
unsigned long V_155 = 1 << V_153 ;
while ( V_153 > V_152 ) {
V_154 -- ;
V_153 -- ;
V_155 >>= 1 ;
F_29 ( F_44 ( V_43 , & V_1 [ V_155 ] ) , & V_1 [ V_155 ] ) ;
if ( F_74 ( V_43 , & V_1 [ V_155 ] , V_153 , V_3 ) )
continue;
F_104 ( & V_1 [ V_155 ] . V_78 , & V_154 -> V_92 [ V_3 ] ) ;
V_154 -> V_88 ++ ;
F_84 ( & V_1 [ V_155 ] , V_153 ) ;
}
}
static void F_205 ( struct V_1 * V_1 )
{
const char * V_96 = NULL ;
unsigned long V_51 = 0 ;
if ( F_34 ( F_106 ( & V_1 -> V_94 ) != - 1 ) )
V_96 = L_7 ;
if ( F_34 ( V_1 -> V_67 != NULL ) )
V_96 = L_8 ;
if ( F_34 ( F_107 ( V_1 ) != 0 ) )
V_96 = L_18 ;
if ( F_34 ( V_1 -> V_37 & V_156 ) ) {
V_96 = L_19 ;
V_51 = V_156 ;
F_52 ( V_1 ) ;
return;
}
if ( F_34 ( V_1 -> V_37 & V_84 ) ) {
V_96 = L_20 ;
V_51 = V_84 ;
}
#ifdef F_108
if ( F_34 ( V_1 -> V_95 ) )
V_96 = L_11 ;
#endif
F_45 ( V_1 , V_96 , V_51 ) ;
}
static inline int F_206 ( struct V_1 * V_1 )
{
if ( F_98 ( F_105 ( V_1 ,
V_84 | V_156 ) ) )
return 0 ;
F_205 ( V_1 ) ;
return 1 ;
}
static inline bool F_207 ( void )
{
return F_112 ( V_157 ) &&
F_208 () ;
}
static bool F_209 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_210 ( struct V_1 * V_1 )
{
return F_206 ( V_1 ) ;
}
static bool F_209 ( struct V_1 * V_1 )
{
return F_206 ( V_1 ) ;
}
static bool F_210 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_211 ( struct V_1 * V_1 , unsigned int V_62 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < ( 1 << V_62 ) ; V_63 ++ ) {
struct V_1 * V_66 = V_1 + V_63 ;
if ( F_34 ( F_206 ( V_66 ) ) )
return true ;
}
return false ;
}
inline void F_212 ( struct V_1 * V_1 , unsigned int V_62 ,
T_7 V_158 )
{
F_79 ( V_1 , 0 ) ;
F_167 ( V_1 ) ;
F_213 ( V_1 , V_62 ) ;
F_134 ( V_1 , 1 << V_62 , 1 ) ;
F_133 ( V_1 , 1 << V_62 , 1 ) ;
F_214 ( V_1 , V_62 ) ;
F_215 ( V_1 , V_62 , V_158 ) ;
}
static void F_216 ( struct V_1 * V_1 , unsigned int V_62 , T_7 V_158 ,
unsigned int V_159 )
{
int V_63 ;
F_212 ( V_1 , V_62 , V_158 ) ;
if ( ! F_207 () && ( V_158 & V_160 ) )
for ( V_63 = 0 ; V_63 < ( 1 << V_62 ) ; V_63 ++ )
F_217 ( V_1 + V_63 ) ;
if ( V_62 && ( V_158 & V_161 ) )
F_57 ( V_1 , V_62 ) ;
if ( V_159 & V_162 )
F_218 ( V_1 ) ;
else
F_219 ( V_1 ) ;
}
static inline
struct V_1 * F_220 ( struct V_43 * V_43 , unsigned int V_62 ,
int V_3 )
{
unsigned int V_163 ;
struct V_87 * V_154 ;
struct V_1 * V_1 ;
for ( V_163 = V_62 ; V_163 < V_74 ; ++ V_163 ) {
V_154 = & ( V_43 -> V_87 [ V_163 ] ) ;
V_1 = F_221 ( & V_154 -> V_92 [ V_3 ] ,
struct V_1 , V_78 ) ;
if ( ! V_1 )
continue;
F_100 ( & V_1 -> V_78 ) ;
F_86 ( V_1 ) ;
V_154 -> V_88 -- ;
F_204 ( V_43 , V_1 , V_62 , V_163 , V_154 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_222 ( struct V_43 * V_43 ,
unsigned int V_62 )
{
return F_220 ( V_43 , V_62 , V_150 ) ;
}
static inline struct V_1 * F_222 ( struct V_43 * V_43 ,
unsigned int V_62 ) { return NULL ; }
static int F_223 ( struct V_43 * V_43 ,
struct V_1 * V_130 , struct V_1 * V_131 ,
int V_3 , int * V_164 )
{
struct V_1 * V_1 ;
unsigned int V_62 ;
int V_165 = 0 ;
#ifndef F_224
F_96 ( F_21 ( V_130 ) != F_21 ( V_131 ) ) ;
#endif
if ( V_164 )
* V_164 = 0 ;
for ( V_1 = V_130 ; V_1 <= V_131 ; ) {
if ( ! F_43 ( F_37 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
F_29 ( F_225 ( V_1 ) != F_41 ( V_43 ) , V_1 ) ;
if ( ! F_93 ( V_1 ) ) {
if ( V_164 &&
( F_226 ( V_1 ) || F_227 ( V_1 ) ) )
( * V_164 ) ++ ;
V_1 ++ ;
continue;
}
V_62 = F_90 ( V_1 ) ;
F_228 ( & V_1 -> V_78 ,
& V_43 -> V_87 [ V_62 ] . V_92 [ V_3 ] ) ;
V_1 += 1 << V_62 ;
V_165 += 1 << V_62 ;
}
return V_165 ;
}
int F_229 ( struct V_43 * V_43 , struct V_1 * V_1 ,
int V_3 , int * V_164 )
{
unsigned long V_47 , V_120 ;
struct V_1 * V_130 , * V_131 ;
V_47 = F_37 ( V_1 ) ;
V_47 = V_47 & ~ ( V_27 - 1 ) ;
V_130 = F_153 ( V_47 ) ;
V_131 = V_130 + V_27 - 1 ;
V_120 = V_47 + V_27 - 1 ;
if ( ! F_30 ( V_43 , V_47 ) )
V_130 = V_1 ;
if ( ! F_30 ( V_43 , V_120 ) )
return 0 ;
return F_223 ( V_43 , V_130 , V_131 , V_3 ,
V_164 ) ;
}
static void F_230 ( struct V_1 * V_166 ,
int V_167 , int V_3 )
{
int V_168 = 1 << ( V_167 - V_24 ) ;
while ( V_168 -- ) {
F_33 ( V_166 , V_3 ) ;
V_166 += V_27 ;
}
}
static bool F_231 ( unsigned int V_62 , int V_169 )
{
if ( V_62 >= V_24 )
return true ;
if ( V_62 >= V_24 / 2 ||
V_169 == V_170 ||
V_169 == V_41 ||
V_39 )
return true ;
return false ;
}
static void F_232 ( struct V_43 * V_43 , struct V_1 * V_1 ,
int V_171 , bool V_172 )
{
unsigned int V_163 = F_90 ( V_1 ) ;
struct V_87 * V_154 ;
int V_173 , V_174 , V_175 ;
int V_176 ;
V_176 = F_102 ( V_1 ) ;
if ( F_233 ( V_176 ) )
goto V_177;
if ( V_163 >= V_24 ) {
F_230 ( V_1 , V_163 , V_171 ) ;
goto V_177;
}
if ( ! V_172 )
goto V_177;
V_173 = F_229 ( V_43 , V_1 , V_171 ,
& V_174 ) ;
if ( V_171 == V_135 ) {
V_175 = V_174 ;
} else {
if ( V_176 == V_135 )
V_175 = V_27
- ( V_173 + V_174 ) ;
else
V_175 = 0 ;
}
if ( ! V_173 )
goto V_177;
if ( V_173 + V_175 >= ( 1 << ( V_24 - 1 ) ) ||
V_39 )
F_33 ( V_1 , V_171 ) ;
return;
V_177:
V_154 = & V_43 -> V_87 [ V_163 ] ;
F_228 ( & V_1 -> V_78 , & V_154 -> V_92 [ V_171 ] ) ;
}
int F_234 ( struct V_87 * V_154 , unsigned int V_62 ,
int V_3 , bool V_178 , bool * V_179 )
{
int V_63 ;
int V_180 ;
if ( V_154 -> V_88 == 0 )
return - 1 ;
* V_179 = false ;
for ( V_63 = 0 ; ; V_63 ++ ) {
V_180 = V_181 [ V_3 ] [ V_63 ] ;
if ( V_180 == V_182 )
break;
if ( F_140 ( & V_154 -> V_92 [ V_180 ] ) )
continue;
if ( F_231 ( V_62 , V_3 ) )
* V_179 = true ;
if ( ! V_178 )
return V_180 ;
if ( * V_179 )
return V_180 ;
}
return - 1 ;
}
static void F_235 ( struct V_1 * V_1 , struct V_43 * V_43 ,
unsigned int V_183 )
{
int V_114 ;
unsigned long V_184 , V_37 ;
V_184 = ( V_43 -> V_123 / 100 ) + V_27 ;
if ( V_43 -> V_185 >= V_184 )
return;
F_236 ( & V_43 -> V_110 , V_37 ) ;
if ( V_43 -> V_185 >= V_184 )
goto V_186;
V_114 = F_102 ( V_1 ) ;
if ( ! F_233 ( V_114 ) && ! F_83 ( V_114 )
&& ! F_237 ( V_114 ) ) {
V_43 -> V_185 += V_27 ;
F_33 ( V_1 , V_187 ) ;
F_229 ( V_43 , V_1 , V_187 , NULL ) ;
}
V_186:
F_238 ( & V_43 -> V_110 , V_37 ) ;
}
static bool F_239 ( const struct V_188 * V_189 ,
bool V_190 )
{
struct V_191 * V_191 = V_189 -> V_191 ;
unsigned long V_37 ;
struct V_192 * V_193 ;
struct V_43 * V_43 ;
struct V_1 * V_1 ;
int V_62 ;
bool V_44 ;
F_240 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( ! V_190 && V_43 -> V_185 <=
V_27 )
continue;
F_236 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_87 * V_154 = & ( V_43 -> V_87 [ V_62 ] ) ;
V_1 = F_221 (
& V_154 -> V_92 [ V_187 ] ,
struct V_1 , V_78 ) ;
if ( ! V_1 )
continue;
if ( F_241 ( V_1 ) ) {
V_43 -> V_185 -= F_11 (
V_27 ,
V_43 -> V_185 ) ;
}
F_33 ( V_1 , V_189 -> V_3 ) ;
V_44 = F_229 ( V_43 , V_1 , V_189 -> V_3 ,
NULL ) ;
if ( V_44 ) {
F_238 ( & V_43 -> V_110 , V_37 ) ;
return V_44 ;
}
}
F_238 ( & V_43 -> V_110 , V_37 ) ;
}
return false ;
}
static inline bool
F_242 ( struct V_43 * V_43 , int V_62 , int V_194 )
{
struct V_87 * V_154 ;
int V_163 ;
struct V_1 * V_1 ;
int V_180 ;
bool V_179 ;
for ( V_163 = V_74 - 1 ; V_163 >= V_62 ;
-- V_163 ) {
V_154 = & ( V_43 -> V_87 [ V_163 ] ) ;
V_180 = F_234 ( V_154 , V_163 ,
V_194 , false , & V_179 ) ;
if ( V_180 == - 1 )
continue;
if ( ! V_179 && V_194 == V_135
&& V_163 > V_62 )
goto V_195;
goto V_196;
}
return false ;
V_195:
for ( V_163 = V_62 ; V_163 < V_74 ;
V_163 ++ ) {
V_154 = & ( V_43 -> V_87 [ V_163 ] ) ;
V_180 = F_234 ( V_154 , V_163 ,
V_194 , false , & V_179 ) ;
if ( V_180 != - 1 )
break;
}
F_96 ( V_163 == V_74 ) ;
V_196:
V_1 = F_243 ( & V_154 -> V_92 [ V_180 ] ,
struct V_1 , V_78 ) ;
F_232 ( V_43 , V_1 , V_194 , V_179 ) ;
F_244 ( V_1 , V_62 , V_163 ,
V_194 , V_180 ) ;
return true ;
}
static struct V_1 * F_245 ( struct V_43 * V_43 , unsigned int V_62 ,
int V_3 )
{
struct V_1 * V_1 ;
V_197:
V_1 = F_220 ( V_43 , V_62 , V_3 ) ;
if ( F_34 ( ! V_1 ) ) {
if ( V_3 == V_135 )
V_1 = F_222 ( V_43 , V_62 ) ;
if ( ! V_1 && F_242 ( V_43 , V_62 , V_3 ) )
goto V_197;
}
F_246 ( V_1 , V_62 , V_3 ) ;
return V_1 ;
}
static int F_247 ( struct V_43 * V_43 , unsigned int V_62 ,
unsigned long V_105 , struct V_111 * V_112 ,
int V_3 , bool V_198 )
{
int V_63 , V_199 = 0 ;
F_139 ( & V_43 -> V_110 ) ;
for ( V_63 = 0 ; V_63 < V_105 ; ++ V_63 ) {
struct V_1 * V_1 = F_245 ( V_43 , V_62 , V_3 ) ;
if ( F_34 ( V_1 == NULL ) )
break;
if ( F_34 ( F_209 ( V_1 ) ) )
continue;
if ( F_98 ( ! V_198 ) )
F_104 ( & V_1 -> V_78 , V_112 ) ;
else
F_103 ( & V_1 -> V_78 , V_112 ) ;
V_112 = & V_1 -> V_78 ;
V_199 ++ ;
if ( F_237 ( F_1 ( V_1 ) ) )
F_248 ( V_43 , V_200 ,
- ( 1 << V_62 ) ) ;
}
F_248 ( V_43 , V_201 , - ( V_63 << V_62 ) ) ;
F_143 ( & V_43 -> V_110 ) ;
return V_199 ;
}
void F_249 ( struct V_43 * V_43 , struct V_106 * V_107 )
{
unsigned long V_37 ;
int V_202 , V_203 ;
F_161 ( V_37 ) ;
V_203 = F_31 ( V_107 -> V_203 ) ;
V_202 = F_11 ( V_107 -> V_105 , V_203 ) ;
if ( V_202 > 0 ) {
F_138 ( V_43 , V_202 , V_107 ) ;
V_107 -> V_105 -= V_202 ;
}
F_163 ( V_37 ) ;
}
static void F_250 ( unsigned int V_204 , struct V_43 * V_43 )
{
unsigned long V_37 ;
struct V_205 * V_206 ;
struct V_106 * V_107 ;
F_161 ( V_37 ) ;
V_206 = F_251 ( V_43 -> V_207 , V_204 ) ;
V_107 = & V_206 -> V_107 ;
if ( V_107 -> V_105 ) {
F_138 ( V_43 , V_107 -> V_105 , V_107 ) ;
V_107 -> V_105 = 0 ;
}
F_163 ( V_37 ) ;
}
static void F_252 ( unsigned int V_204 )
{
struct V_43 * V_43 ;
F_201 (zone) {
F_250 ( V_204 , V_43 ) ;
}
}
void F_253 ( struct V_43 * V_43 )
{
int V_204 = F_254 () ;
if ( V_43 )
F_250 ( V_204 , V_43 ) ;
else
F_252 ( V_204 ) ;
}
static void F_255 ( struct V_208 * V_209 )
{
F_256 () ;
F_253 ( NULL ) ;
F_257 () ;
}
void F_258 ( struct V_43 * V_43 )
{
int V_204 ;
static T_8 V_210 ;
if ( F_259 ( ! V_211 ) )
return;
if ( V_58 -> V_37 & V_212 )
return;
if ( F_34 ( ! F_260 ( & V_213 ) ) ) {
if ( ! V_43 )
return;
F_261 ( & V_213 ) ;
}
F_262 (cpu) {
struct V_205 * V_107 ;
struct V_43 * V_193 ;
bool V_214 = false ;
if ( V_43 ) {
V_107 = F_251 ( V_43 -> V_207 , V_204 ) ;
if ( V_107 -> V_107 . V_105 )
V_214 = true ;
} else {
F_201 (z) {
V_107 = F_251 ( V_193 -> V_207 , V_204 ) ;
if ( V_107 -> V_107 . V_105 ) {
V_214 = true ;
break;
}
}
}
if ( V_214 )
F_263 ( V_204 , & V_210 ) ;
else
F_264 ( V_204 , & V_210 ) ;
}
F_265 (cpu, &cpus_with_pcps) {
struct V_208 * V_209 = F_251 ( & V_215 , V_204 ) ;
F_266 ( V_209 , F_255 ) ;
F_267 ( V_204 , V_211 , V_209 ) ;
}
F_265 (cpu, &cpus_with_pcps)
F_268 ( F_251 ( & V_215 , V_204 ) ) ;
F_269 ( & V_213 ) ;
}
void F_270 ( struct V_43 * V_43 )
{
unsigned long V_18 , V_216 , F_92 = V_217 ;
unsigned long V_37 ;
unsigned int V_62 , V_218 ;
struct V_1 * V_1 ;
if ( F_271 ( V_43 ) )
return;
F_236 ( & V_43 -> V_110 , V_37 ) ;
V_216 = F_155 ( V_43 ) ;
for ( V_18 = V_43 -> V_26 ; V_18 < V_216 ; V_18 ++ )
if ( F_159 ( V_18 ) ) {
V_1 = F_153 ( V_18 ) ;
if ( ! -- F_92 ) {
F_272 () ;
F_92 = V_217 ;
}
if ( F_21 ( V_1 ) != V_43 )
continue;
if ( ! F_273 ( V_1 ) )
F_274 ( V_1 ) ;
}
F_275 (order, t) {
F_276 (page,
&zone->free_area[order].free_list[t], lru) {
unsigned long V_63 ;
V_18 = F_37 ( V_1 ) ;
for ( V_63 = 0 ; V_63 < ( 1UL << V_62 ) ; V_63 ++ ) {
if ( ! -- F_92 ) {
F_272 () ;
F_92 = V_217 ;
}
F_277 ( F_153 ( V_18 + V_63 ) ) ;
}
}
}
F_238 ( & V_43 -> V_110 , V_37 ) ;
}
void F_278 ( struct V_1 * V_1 , bool V_198 )
{
struct V_43 * V_43 = F_21 ( V_1 ) ;
struct V_106 * V_107 ;
unsigned long V_37 ;
unsigned long V_18 = F_37 ( V_1 ) ;
int V_3 ;
if ( ! F_136 ( V_1 ) )
return;
V_3 = F_26 ( V_1 , V_18 ) ;
F_2 ( V_1 , V_3 ) ;
F_161 ( V_37 ) ;
F_279 ( V_121 ) ;
if ( V_3 >= V_40 ) {
if ( F_34 ( F_83 ( V_3 ) ) ) {
F_144 ( V_43 , V_1 , V_18 , 0 , V_3 ) ;
goto V_56;
}
V_3 = V_135 ;
}
V_107 = & F_280 ( V_43 -> V_207 ) -> V_107 ;
if ( ! V_198 )
F_104 ( & V_1 -> V_78 , & V_107 -> V_113 [ V_3 ] ) ;
else
F_103 ( & V_1 -> V_78 , & V_107 -> V_113 [ V_3 ] ) ;
V_107 -> V_105 ++ ;
if ( V_107 -> V_105 >= V_107 -> V_153 ) {
unsigned long V_203 = F_31 ( V_107 -> V_203 ) ;
F_138 ( V_43 , V_203 , V_107 ) ;
V_107 -> V_105 -= V_203 ;
}
V_56:
F_163 ( V_37 ) ;
}
void F_281 ( struct V_111 * V_112 , bool V_198 )
{
struct V_1 * V_1 , * V_219 ;
F_282 (page, next, list, lru) {
F_283 ( V_1 , V_198 ) ;
F_278 ( V_1 , V_198 ) ;
}
}
void F_284 ( struct V_1 * V_1 , unsigned int V_62 )
{
int V_63 ;
F_29 ( F_120 ( V_1 ) , V_1 ) ;
F_29 ( ! F_92 ( V_1 ) , V_1 ) ;
#ifdef F_285
if ( F_286 ( V_1 ) )
F_284 ( F_287 ( V_1 [ 0 ] . V_220 ) , V_62 ) ;
#endif
for ( V_63 = 1 ; V_63 < ( 1 << V_62 ) ; V_63 ++ )
F_167 ( V_1 + V_63 ) ;
F_288 ( V_1 , V_62 ) ;
}
int F_289 ( struct V_1 * V_1 , unsigned int V_62 )
{
unsigned long V_221 ;
struct V_43 * V_43 ;
int V_114 ;
F_187 ( ! F_93 ( V_1 ) ) ;
V_43 = F_21 ( V_1 ) ;
V_114 = F_102 ( V_1 ) ;
if ( ! F_83 ( V_114 ) ) {
V_221 = F_290 ( V_43 ) + ( 1UL << V_62 ) ;
if ( ! F_291 ( V_43 , 0 , V_221 , 0 , V_222 ) )
return 0 ;
F_80 ( V_43 , - ( 1UL << V_62 ) , V_114 ) ;
}
F_100 ( & V_1 -> V_78 ) ;
V_43 -> V_87 [ V_62 ] . V_88 -- ;
F_86 ( V_1 ) ;
if ( V_62 >= V_24 - 1 ) {
struct V_1 * V_223 = V_1 + ( 1 << V_62 ) - 1 ;
for (; V_1 < V_223 ; V_1 += V_27 ) {
int V_114 = F_102 ( V_1 ) ;
if ( ! F_83 ( V_114 ) && ! F_237 ( V_114 )
&& ! F_233 ( V_114 ) )
F_33 ( V_1 ,
V_135 ) ;
}
}
return 1UL << V_62 ;
}
static inline void F_292 ( struct V_43 * V_224 , struct V_43 * V_193 )
{
#ifdef F_293
enum V_225 V_226 = V_227 ;
if ( V_193 -> V_127 != F_294 () )
V_226 = V_228 ;
if ( V_193 -> V_127 == V_224 -> V_127 )
F_295 ( V_193 , V_229 ) ;
else {
F_295 ( V_193 , V_230 ) ;
F_295 ( V_224 , V_231 ) ;
}
F_295 ( V_193 , V_226 ) ;
#endif
}
static struct V_1 * F_296 ( struct V_43 * V_43 , int V_3 ,
bool V_198 , struct V_106 * V_107 ,
struct V_111 * V_112 )
{
struct V_1 * V_1 ;
do {
if ( F_140 ( V_112 ) ) {
V_107 -> V_105 += F_247 ( V_43 , 0 ,
V_107 -> V_203 , V_112 ,
V_3 , V_198 ) ;
if ( F_34 ( F_140 ( V_112 ) ) )
return NULL ;
}
if ( V_198 )
V_1 = F_141 ( V_112 , struct V_1 , V_78 ) ;
else
V_1 = F_243 ( V_112 , struct V_1 , V_78 ) ;
F_100 ( & V_1 -> V_78 ) ;
V_107 -> V_105 -- ;
} while ( F_210 ( V_1 ) );
return V_1 ;
}
static struct V_1 * F_297 ( struct V_43 * V_224 ,
struct V_43 * V_43 , unsigned int V_62 ,
T_7 V_158 , int V_3 )
{
struct V_106 * V_107 ;
struct V_111 * V_112 ;
bool V_198 = ( ( V_158 & V_232 ) != 0 ) ;
struct V_1 * V_1 ;
unsigned long V_37 ;
F_161 ( V_37 ) ;
V_107 = & F_280 ( V_43 -> V_207 ) -> V_107 ;
V_112 = & V_107 -> V_113 [ V_3 ] ;
V_1 = F_296 ( V_43 , V_3 , V_198 , V_107 , V_112 ) ;
if ( V_1 ) {
F_298 ( V_233 , F_299 ( V_1 ) , 1 << V_62 ) ;
F_292 ( V_224 , V_43 ) ;
}
F_163 ( V_37 ) ;
return V_1 ;
}
static inline
struct V_1 * F_300 ( struct V_43 * V_224 ,
struct V_43 * V_43 , unsigned int V_62 ,
T_7 V_158 , unsigned int V_159 ,
int V_3 )
{
unsigned long V_37 ;
struct V_1 * V_1 ;
if ( F_98 ( V_62 == 0 ) ) {
V_1 = F_297 ( V_224 , V_43 , V_62 ,
V_158 , V_3 ) ;
goto V_56;
}
F_259 ( ( V_158 & V_234 ) && ( V_62 > 1 ) ) ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
do {
V_1 = NULL ;
if ( V_159 & V_235 ) {
V_1 = F_220 ( V_43 , V_62 , V_187 ) ;
if ( V_1 )
F_246 ( V_1 , V_62 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_245 ( V_43 , V_62 , V_3 ) ;
} while ( V_1 && F_211 ( V_1 , V_62 ) );
F_143 ( & V_43 -> V_110 ) ;
if ( ! V_1 )
goto V_236;
F_80 ( V_43 , - ( 1 << V_62 ) ,
F_1 ( V_1 ) ) ;
F_298 ( V_233 , F_299 ( V_1 ) , 1 << V_62 ) ;
F_292 ( V_224 , V_43 ) ;
F_163 ( V_37 ) ;
V_56:
F_29 ( V_1 && F_44 ( V_43 , V_1 ) , V_1 ) ;
return V_1 ;
V_236:
F_163 ( V_37 ) ;
return NULL ;
}
static int T_5 F_301 ( char * V_237 )
{
return F_302 ( & V_238 . V_239 , V_237 ) ;
}
static bool F_303 ( T_7 V_240 , unsigned int V_62 )
{
if ( V_62 < V_238 . V_241 )
return false ;
if ( V_240 & V_234 )
return false ;
if ( V_238 . V_242 && ( V_240 & V_243 ) )
return false ;
if ( V_238 . V_244 &&
( V_240 & V_245 ) )
return false ;
return F_304 ( & V_238 . V_239 , 1 << V_62 ) ;
}
static int T_5 F_305 ( void )
{
T_9 V_246 = V_247 | V_248 | V_249 ;
struct V_250 * V_251 ;
V_251 = F_306 ( L_21 , NULL ,
& V_238 . V_239 ) ;
if ( F_307 ( V_251 ) )
return F_308 ( V_251 ) ;
if ( ! F_309 ( L_22 , V_246 , V_251 ,
& V_238 . V_244 ) )
goto V_252;
if ( ! F_309 ( L_23 , V_246 , V_251 ,
& V_238 . V_242 ) )
goto V_252;
if ( ! F_310 ( L_24 , V_246 , V_251 ,
& V_238 . V_241 ) )
goto V_252;
return 0 ;
V_252:
F_311 ( V_251 ) ;
return - V_253 ;
}
static inline bool F_303 ( T_7 V_240 , unsigned int V_62 )
{
return false ;
}
bool F_312 ( struct V_43 * V_193 , unsigned int V_62 , unsigned long V_254 ,
int V_255 , unsigned int V_159 ,
long V_173 )
{
long F_11 = V_254 ;
int V_256 ;
const bool V_257 = ( V_159 & V_235 ) ;
V_173 -= ( 1 << V_62 ) - 1 ;
if ( V_159 & V_258 )
F_11 -= F_11 / 2 ;
if ( F_98 ( ! V_257 ) )
V_173 -= V_193 -> V_185 ;
else
F_11 -= F_11 / 4 ;
#ifdef F_313
if ( ! ( V_159 & V_222 ) )
V_173 -= F_314 ( V_193 , V_200 ) ;
#endif
if ( V_173 <= F_11 + V_193 -> V_259 [ V_255 ] )
return false ;
if ( ! V_62 )
return true ;
for ( V_256 = V_62 ; V_256 < V_74 ; V_256 ++ ) {
struct V_87 * V_154 = & V_193 -> V_87 [ V_256 ] ;
int V_114 ;
if ( ! V_154 -> V_88 )
continue;
if ( V_257 )
return true ;
for ( V_114 = 0 ; V_114 < V_40 ; V_114 ++ ) {
if ( ! F_140 ( & V_154 -> V_92 [ V_114 ] ) )
return true ;
}
#ifdef F_313
if ( ( V_159 & V_222 ) &&
! F_140 ( & V_154 -> V_92 [ V_150 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_291 ( struct V_43 * V_193 , unsigned int V_62 , unsigned long V_254 ,
int V_255 , unsigned int V_159 )
{
return F_312 ( V_193 , V_62 , V_254 , V_255 , V_159 ,
F_314 ( V_193 , V_201 ) ) ;
}
static inline bool F_315 ( struct V_43 * V_193 , unsigned int V_62 ,
unsigned long V_254 , int V_255 , unsigned int V_159 )
{
long V_173 = F_314 ( V_193 , V_201 ) ;
long V_260 = 0 ;
#ifdef F_313
if ( ! ( V_159 & V_222 ) )
V_260 = F_314 ( V_193 , V_200 ) ;
#endif
if ( ! V_62 && ( V_173 - V_260 ) > V_254 + V_193 -> V_259 [ V_255 ] )
return true ;
return F_312 ( V_193 , V_62 , V_254 , V_255 , V_159 ,
V_173 ) ;
}
bool F_316 ( struct V_43 * V_193 , unsigned int V_62 ,
unsigned long V_254 , int V_255 )
{
long V_173 = F_314 ( V_193 , V_201 ) ;
if ( V_193 -> V_261 && V_173 < V_193 -> V_261 )
V_173 = F_317 ( V_193 , V_201 ) ;
return F_312 ( V_193 , V_62 , V_254 , V_255 , 0 ,
V_173 ) ;
}
static bool F_318 ( struct V_43 * V_262 , struct V_43 * V_43 )
{
return F_319 ( F_41 ( V_262 ) , F_41 ( V_43 ) ) <=
V_263 ;
}
static bool F_318 ( struct V_43 * V_262 , struct V_43 * V_43 )
{
return true ;
}
static struct V_1 *
F_320 ( T_7 V_240 , unsigned int V_62 , int V_159 ,
const struct V_188 * V_189 )
{
struct V_192 * V_193 = V_189 -> V_264 ;
struct V_43 * V_43 ;
struct V_265 * V_266 = NULL ;
F_321 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct V_1 * V_1 ;
unsigned long V_254 ;
if ( F_322 () &&
( V_159 & V_267 ) &&
! F_323 ( V_43 , V_240 ) )
continue;
if ( V_189 -> V_268 ) {
if ( V_266 == V_43 -> V_269 )
continue;
if ( ! F_324 ( V_43 -> V_269 ) ) {
V_266 = V_43 -> V_269 ;
continue;
}
}
V_254 = V_43 -> V_221 [ V_159 & V_270 ] ;
if ( ! F_315 ( V_43 , V_62 , V_254 ,
F_325 ( V_189 ) , V_159 ) ) {
int V_44 ;
F_28 ( V_162 < V_271 ) ;
if ( V_159 & V_162 )
goto V_272;
if ( V_273 == 0 ||
! F_318 ( V_189 -> V_264 -> V_43 , V_43 ) )
continue;
V_44 = F_326 ( V_43 -> V_269 , V_240 , V_62 ) ;
switch ( V_44 ) {
case V_274 :
continue;
case V_275 :
continue;
default:
if ( F_291 ( V_43 , V_62 , V_254 ,
F_325 ( V_189 ) , V_159 ) )
goto V_272;
continue;
}
}
V_272:
V_1 = F_300 ( V_189 -> V_264 -> V_43 , V_43 , V_62 ,
V_240 , V_159 , V_189 -> V_3 ) ;
if ( V_1 ) {
F_216 ( V_1 , V_62 , V_240 , V_159 ) ;
if ( F_34 ( V_62 && ( V_159 & V_235 ) ) )
F_235 ( V_1 , V_43 , V_62 ) ;
return V_1 ;
}
}
return NULL ;
}
static inline bool F_327 ( void )
{
bool V_44 = false ;
#if V_276 > 8
V_44 = F_328 () ;
#endif
return V_44 ;
}
static void F_329 ( T_7 V_240 , T_10 * V_277 )
{
unsigned int V_278 = V_279 ;
static F_330 ( V_280 , V_57 , 1 ) ;
if ( F_327 () || ! F_331 ( & V_280 ) )
return;
if ( ! ( V_240 & V_281 ) )
if ( F_332 ( V_282 ) ||
( V_58 -> V_37 & ( V_283 | V_284 ) ) )
V_278 &= ~ V_279 ;
if ( F_328 () || ! ( V_240 & V_245 ) )
V_278 &= ~ V_279 ;
F_333 ( V_278 , V_277 ) ;
}
void F_334 ( T_7 V_240 , T_10 * V_277 , const char * V_285 , ... )
{
struct V_286 V_287 ;
T_11 args ;
static F_330 ( V_288 , V_289 ,
V_290 ) ;
if ( ( V_240 & V_291 ) || ! F_331 ( & V_288 ) )
return;
F_335 ( L_25 , V_58 -> V_59 ) ;
va_start ( args , V_285 ) ;
V_287 . V_285 = V_285 ;
V_287 . V_292 = & args ;
F_336 ( L_26 , & V_287 ) ;
va_end ( args ) ;
F_336 ( L_27 , V_240 , & V_240 ) ;
if ( V_277 )
F_336 ( L_28 , F_337 ( V_277 ) ) ;
else
F_336 ( L_29 ) ;
F_338 () ;
F_51 () ;
F_329 ( V_240 , V_277 ) ;
}
static inline struct V_1 *
F_339 ( T_7 V_240 , unsigned int V_62 ,
unsigned int V_159 ,
const struct V_188 * V_189 )
{
struct V_1 * V_1 ;
V_1 = F_320 ( V_240 , V_62 ,
V_159 | V_267 , V_189 ) ;
if ( ! V_1 )
V_1 = F_320 ( V_240 , V_62 ,
V_159 , V_189 ) ;
return V_1 ;
}
static inline struct V_1 *
F_340 ( T_7 V_240 , unsigned int V_62 ,
const struct V_188 * V_189 , unsigned long * V_293 )
{
struct V_294 V_295 = {
. V_191 = V_189 -> V_191 ,
. V_277 = V_189 -> V_277 ,
. V_296 = NULL ,
. V_240 = V_240 ,
. V_62 = V_62 ,
} ;
struct V_1 * V_1 ;
* V_293 = 0 ;
if ( ! F_260 ( & V_297 ) ) {
* V_293 = 1 ;
F_341 ( 1 ) ;
return NULL ;
}
V_1 = F_320 ( ( V_240 | V_298 ) &
~ V_245 , V_62 ,
V_299 | V_267 , V_189 ) ;
if ( V_1 )
goto V_56;
if ( V_58 -> V_37 & V_300 )
goto V_56;
if ( V_62 > V_301 )
goto V_56;
if ( V_240 & V_302 )
goto V_56;
if ( V_189 -> V_303 < V_304 )
goto V_56;
if ( F_7 () )
goto V_56;
if ( V_240 & V_305 )
goto V_56;
if ( F_342 ( & V_295 ) || F_259 ( V_240 & V_234 ) ) {
* V_293 = 1 ;
if ( V_240 & V_234 )
V_1 = F_339 ( V_240 , V_62 ,
V_162 , V_189 ) ;
}
V_56:
F_269 ( & V_297 ) ;
return V_1 ;
}
static struct V_1 *
F_343 ( T_7 V_240 , unsigned int V_62 ,
unsigned int V_159 , const struct V_188 * V_189 ,
enum V_306 V_307 , enum V_308 * V_308 )
{
struct V_1 * V_1 ;
unsigned int V_309 ;
if ( ! V_62 )
return NULL ;
V_309 = F_344 () ;
* V_308 = F_345 ( V_240 , V_62 , V_159 , V_189 ,
V_307 ) ;
F_346 ( V_309 ) ;
if ( * V_308 <= V_310 )
return NULL ;
F_347 ( V_311 ) ;
V_1 = F_320 ( V_240 , V_62 , V_159 , V_189 ) ;
if ( V_1 ) {
struct V_43 * V_43 = F_21 ( V_1 ) ;
V_43 -> V_312 = false ;
F_348 ( V_43 , V_62 , true ) ;
F_347 ( V_313 ) ;
return V_1 ;
}
F_347 ( V_314 ) ;
F_189 () ;
return NULL ;
}
static inline bool
F_349 ( struct V_188 * V_189 , int V_62 , int V_159 ,
enum V_308 V_308 ,
enum V_306 * V_306 ,
int * V_315 )
{
int V_316 = V_317 ;
int V_318 ;
bool V_44 = false ;
int V_319 = * V_315 ;
enum V_306 V_320 = * V_306 ;
if ( ! V_62 )
return false ;
if ( F_350 ( V_308 ) )
( * V_315 ) ++ ;
if ( F_351 ( V_308 ) )
goto V_321;
if ( F_352 ( V_308 ) ) {
V_44 = F_353 ( V_189 , V_62 , V_159 ) ;
goto V_56;
}
if ( V_62 > V_301 )
V_316 /= 4 ;
if ( * V_315 <= V_316 ) {
V_44 = true ;
goto V_56;
}
V_321:
V_318 = ( V_62 > V_301 ) ?
V_322 : V_323 ;
if ( * V_306 > V_318 ) {
( * V_306 ) -- ;
* V_315 = 0 ;
V_44 = true ;
}
V_56:
F_354 ( V_62 , V_320 , V_308 , V_319 , V_316 , V_44 ) ;
return V_44 ;
}
static inline struct V_1 *
F_343 ( T_7 V_240 , unsigned int V_62 ,
unsigned int V_159 , const struct V_188 * V_189 ,
enum V_306 V_307 , enum V_308 * V_308 )
{
* V_308 = V_324 ;
return NULL ;
}
static inline bool
F_349 ( struct V_188 * V_189 , unsigned int V_62 , int V_159 ,
enum V_308 V_308 ,
enum V_306 * V_306 ,
int * V_315 )
{
struct V_43 * V_43 ;
struct V_192 * V_193 ;
if ( ! V_62 || V_62 > V_301 )
return false ;
F_240 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( F_291 ( V_43 , 0 , F_290 ( V_43 ) ,
F_325 ( V_189 ) , V_159 ) )
return true ;
}
return false ;
}
static int
F_355 ( T_7 V_240 , unsigned int V_62 ,
const struct V_188 * V_189 )
{
struct V_325 V_325 ;
int V_326 ;
unsigned int V_309 ;
F_189 () ;
F_356 () ;
V_309 = F_344 () ;
F_357 ( V_240 ) ;
V_325 . V_327 = 0 ;
V_58 -> V_325 = & V_325 ;
V_326 = F_358 ( V_189 -> V_191 , V_62 , V_240 ,
V_189 -> V_277 ) ;
V_58 -> V_325 = NULL ;
F_359 () ;
F_346 ( V_309 ) ;
F_189 () ;
return V_326 ;
}
static inline struct V_1 *
F_360 ( T_7 V_240 , unsigned int V_62 ,
unsigned int V_159 , const struct V_188 * V_189 ,
unsigned long * V_293 )
{
struct V_1 * V_1 = NULL ;
bool V_328 = false ;
* V_293 = F_355 ( V_240 , V_62 , V_189 ) ;
if ( F_34 ( ! ( * V_293 ) ) )
return NULL ;
V_197:
V_1 = F_320 ( V_240 , V_62 , V_159 , V_189 ) ;
if ( ! V_1 && ! V_328 ) {
F_239 ( V_189 , false ) ;
F_258 ( NULL ) ;
V_328 = true ;
goto V_197;
}
return V_1 ;
}
static void F_361 ( unsigned int V_62 , const struct V_188 * V_189 )
{
struct V_192 * V_193 ;
struct V_43 * V_43 ;
T_1 * V_329 = NULL ;
F_240 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask) {
if ( V_329 != V_43 -> V_269 )
F_362 ( V_43 , V_62 , V_189 -> V_303 ) ;
V_329 = V_43 -> V_269 ;
}
}
static inline unsigned int
F_363 ( T_7 V_240 )
{
unsigned int V_159 = V_330 | V_267 ;
F_28 ( V_331 != ( V_332 T_7 ) V_258 ) ;
V_159 |= ( V_332 int ) ( V_240 & V_331 ) ;
if ( V_240 & V_333 ) {
if ( ! ( V_240 & V_281 ) )
V_159 |= V_235 ;
V_159 &= ~ V_267 ;
} else if ( F_34 ( F_364 ( V_58 ) ) && ! F_328 () )
V_159 |= V_235 ;
#ifdef F_313
if ( F_365 ( V_240 ) == V_135 )
V_159 |= V_222 ;
#endif
return V_159 ;
}
bool F_366 ( T_7 V_240 )
{
if ( F_34 ( V_240 & V_281 ) )
return false ;
if ( V_240 & V_334 )
return true ;
if ( F_367 () && ( V_58 -> V_37 & V_283 ) )
return true ;
if ( ! F_328 () &&
( ( V_58 -> V_37 & V_283 ) ||
F_34 ( F_332 ( V_282 ) ) ) )
return true ;
return false ;
}
static inline bool
F_368 ( T_7 V_240 , unsigned V_62 ,
struct V_188 * V_189 , int V_159 ,
bool V_293 , int * V_335 )
{
struct V_43 * V_43 ;
struct V_192 * V_193 ;
if ( V_293 && V_62 <= V_301 )
* V_335 = 0 ;
else
( * V_335 ) ++ ;
if ( * V_335 > V_336 ) {
return F_239 ( V_189 , true ) ;
}
F_240 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_337 ;
unsigned long V_338 ;
unsigned long V_339 = F_290 ( V_43 ) ;
bool V_340 ;
V_337 = V_338 = F_369 ( V_43 ) ;
V_337 += F_317 ( V_43 , V_201 ) ;
V_340 = F_312 ( V_43 , V_62 , V_339 ,
F_325 ( V_189 ) , V_159 , V_337 ) ;
F_370 ( V_193 , V_62 , V_338 ,
V_337 , V_339 , * V_335 , V_340 ) ;
if ( V_340 ) {
if ( ! V_293 ) {
unsigned long V_341 ;
V_341 = F_317 ( V_43 ,
V_342 ) ;
if ( 2 * V_341 > V_338 ) {
F_371 ( V_343 , V_57 / 10 ) ;
return true ;
}
}
if ( V_58 -> V_37 & V_212 )
F_341 ( 1 ) ;
else
F_189 () ;
return true ;
}
}
return false ;
}
static inline bool
F_372 ( int V_344 , struct V_188 * V_189 )
{
if ( F_322 () && V_189 -> V_277 &&
! F_373 ( V_189 -> V_277 ) ) {
V_189 -> V_277 = NULL ;
return true ;
}
if ( F_374 ( V_344 ) )
return true ;
return false ;
}
static inline struct V_1 *
F_375 ( T_7 V_240 , unsigned int V_62 ,
struct V_188 * V_189 )
{
bool V_345 = V_240 & V_245 ;
const bool V_346 = V_62 > V_301 ;
struct V_1 * V_1 = NULL ;
unsigned int V_159 ;
unsigned long V_293 ;
enum V_306 V_306 ;
enum V_308 V_308 ;
int V_315 ;
int V_335 ;
unsigned long V_347 = V_55 ;
unsigned int V_348 = 10 * V_57 ;
unsigned int V_344 ;
if ( V_62 >= V_74 ) {
F_259 ( ! ( V_240 & V_291 ) ) ;
return NULL ;
}
if ( F_259 ( ( V_240 & ( V_333 | V_245 ) ) ==
( V_333 | V_245 ) ) )
V_240 &= ~ V_333 ;
V_349:
V_315 = 0 ;
V_335 = 0 ;
V_306 = V_350 ;
V_344 = F_376 () ;
V_159 = F_363 ( V_240 ) ;
V_189 -> V_264 = F_377 ( V_189 -> V_191 ,
V_189 -> V_303 , V_189 -> V_277 ) ;
if ( ! V_189 -> V_264 -> V_43 )
goto V_351;
if ( V_240 & V_352 )
F_361 ( V_62 , V_189 ) ;
V_1 = F_320 ( V_240 , V_62 , V_159 , V_189 ) ;
if ( V_1 )
goto V_353;
if ( V_345 &&
( V_346 ||
( V_62 > 0 && V_189 -> V_3 != V_135 ) )
&& ! F_366 ( V_240 ) ) {
V_1 = F_343 ( V_240 , V_62 ,
V_159 , V_189 ,
V_354 ,
& V_308 ) ;
if ( V_1 )
goto V_353;
if ( V_346 && ( V_240 & V_355 ) ) {
if ( V_308 == V_356 )
goto V_351;
V_306 = V_354 ;
}
}
V_197:
if ( V_240 & V_352 )
F_361 ( V_62 , V_189 ) ;
if ( F_366 ( V_240 ) )
V_159 = V_162 ;
if ( ! ( V_159 & V_267 ) || ( V_159 & V_162 ) ) {
V_189 -> V_191 = F_378 ( F_294 () , V_240 ) ;
V_189 -> V_264 = F_377 ( V_189 -> V_191 ,
V_189 -> V_303 , V_189 -> V_277 ) ;
}
V_1 = F_320 ( V_240 , V_62 , V_159 , V_189 ) ;
if ( V_1 )
goto V_353;
if ( ! V_345 )
goto V_351;
if ( F_379 ( V_55 , V_347 + V_348 ) ) {
F_334 ( V_240 & ~ V_291 , V_189 -> V_277 ,
L_30 ,
F_191 ( V_55 - V_347 ) , V_62 ) ;
V_348 += 10 * V_57 ;
}
if ( V_58 -> V_37 & V_283 )
goto V_351;
V_1 = F_360 ( V_240 , V_62 , V_159 , V_189 ,
& V_293 ) ;
if ( V_1 )
goto V_353;
V_1 = F_343 ( V_240 , V_62 , V_159 , V_189 ,
V_306 , & V_308 ) ;
if ( V_1 )
goto V_353;
if ( V_240 & V_355 )
goto V_351;
if ( V_346 && ! ( V_240 & V_302 ) )
goto V_351;
if ( F_368 ( V_240 , V_62 , V_189 , V_159 ,
V_293 > 0 , & V_335 ) )
goto V_197;
if ( V_293 > 0 &&
F_349 ( V_189 , V_62 , V_159 ,
V_308 , & V_306 ,
& V_315 ) )
goto V_197;
if ( F_372 ( V_344 , V_189 ) )
goto V_349;
V_1 = F_340 ( V_240 , V_62 , V_189 , & V_293 ) ;
if ( V_1 )
goto V_353;
if ( F_332 ( V_282 ) &&
( V_159 == V_162 ||
( V_240 & V_281 ) ) )
goto V_351;
if ( V_293 ) {
V_335 = 0 ;
goto V_197;
}
V_351:
if ( F_372 ( V_344 , V_189 ) )
goto V_349;
if ( V_240 & V_234 ) {
if ( F_259 ( ! V_345 ) )
goto V_252;
F_259 ( V_58 -> V_37 & V_283 ) ;
F_259 ( V_62 > V_301 ) ;
V_1 = F_339 ( V_240 , V_62 , V_235 , V_189 ) ;
if ( V_1 )
goto V_353;
F_189 () ;
goto V_197;
}
V_252:
F_334 ( V_240 , V_189 -> V_277 ,
L_31 , V_62 ) ;
V_353:
return V_1 ;
}
static inline bool F_380 ( T_7 V_240 , unsigned int V_62 ,
int V_357 , T_10 * V_277 ,
struct V_188 * V_189 , T_7 * V_358 ,
unsigned int * V_159 )
{
V_189 -> V_303 = F_381 ( V_240 ) ;
V_189 -> V_191 = F_378 ( V_357 , V_240 ) ;
V_189 -> V_277 = V_277 ;
V_189 -> V_3 = F_365 ( V_240 ) ;
if ( F_322 () ) {
* V_358 |= V_298 ;
if ( ! V_189 -> V_277 )
V_189 -> V_277 = & V_359 ;
else
* V_159 |= V_267 ;
}
F_382 ( V_240 ) ;
F_383 ( V_240 & V_245 ) ;
if ( F_303 ( V_240 , V_62 ) )
return false ;
if ( F_112 ( F_313 ) && V_189 -> V_3 == V_135 )
* V_159 |= V_222 ;
return true ;
}
static inline void F_384 ( T_7 V_240 ,
unsigned int V_62 , struct V_188 * V_189 )
{
V_189 -> V_268 = ( V_240 & V_360 ) ;
V_189 -> V_264 = F_377 ( V_189 -> V_191 ,
V_189 -> V_303 , V_189 -> V_277 ) ;
}
struct V_1 *
F_385 ( T_7 V_240 , unsigned int V_62 , int V_357 ,
T_10 * V_277 )
{
struct V_1 * V_1 ;
unsigned int V_159 = V_361 ;
T_7 V_358 = V_240 ;
struct V_188 V_189 = { } ;
V_240 &= V_6 ;
if ( ! F_380 ( V_240 , V_62 , V_357 , V_277 , & V_189 , & V_358 , & V_159 ) )
return NULL ;
F_384 ( V_240 , V_62 , & V_189 ) ;
V_1 = F_320 ( V_358 , V_62 , V_159 , & V_189 ) ;
if ( F_98 ( V_1 ) )
goto V_56;
V_358 = F_386 ( V_240 ) ;
V_189 . V_268 = false ;
if ( F_34 ( V_189 . V_277 != V_277 ) )
V_189 . V_277 = V_277 ;
V_1 = F_375 ( V_358 , V_62 , & V_189 ) ;
V_56:
if ( F_123 () && ( V_240 & V_362 ) && V_1 &&
F_34 ( F_387 ( V_1 , V_240 , V_62 ) != 0 ) ) {
F_168 ( V_1 , V_62 ) ;
V_1 = NULL ;
}
if ( V_363 && V_1 )
F_388 ( V_1 , V_62 , V_240 ) ;
F_389 ( V_1 , V_62 , V_358 , V_189 . V_3 ) ;
return V_1 ;
}
unsigned long F_390 ( T_7 V_240 , unsigned int V_62 )
{
struct V_1 * V_1 ;
F_96 ( ( V_240 & V_243 ) != 0 ) ;
V_1 = F_391 ( V_240 , V_62 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_130 ( V_1 ) ;
}
unsigned long F_392 ( T_7 V_240 )
{
return F_390 ( V_240 | V_160 , 0 ) ;
}
void F_168 ( struct V_1 * V_1 , unsigned int V_62 )
{
if ( F_393 ( V_1 ) ) {
if ( V_62 == 0 )
F_278 ( V_1 , false ) ;
else
F_55 ( V_1 , V_62 ) ;
}
}
void V_173 ( unsigned long V_364 , unsigned int V_62 )
{
if ( V_364 != 0 ) {
F_96 ( ! F_394 ( ( void * ) V_364 ) ) ;
F_168 ( F_287 ( ( void * ) V_364 ) , V_62 ) ;
}
}
static struct V_1 * F_395 ( struct V_365 * V_366 ,
T_7 V_240 )
{
struct V_1 * V_1 = NULL ;
T_7 V_367 = V_240 ;
#if ( V_104 < V_368 )
V_240 |= V_161 | V_291 | V_355 |
V_281 ;
V_1 = F_396 ( V_369 , V_240 ,
V_370 ) ;
V_366 -> V_155 = V_1 ? V_368 : V_104 ;
#endif
if ( F_34 ( ! V_1 ) )
V_1 = F_396 ( V_369 , V_367 , 0 ) ;
V_366 -> V_292 = V_1 ? F_130 ( V_1 ) : NULL ;
return V_1 ;
}
void F_397 ( struct V_1 * V_1 , unsigned int V_105 )
{
F_29 ( F_107 ( V_1 ) == 0 , V_1 ) ;
if ( F_398 ( V_1 , V_105 ) ) {
unsigned int V_62 = F_56 ( V_1 ) ;
if ( V_62 == 0 )
F_278 ( V_1 , false ) ;
else
F_55 ( V_1 , V_62 ) ;
}
}
void * F_399 ( struct V_365 * V_366 ,
unsigned int V_371 , T_7 V_240 )
{
unsigned int V_155 = V_104 ;
struct V_1 * V_1 ;
int V_372 ;
if ( F_34 ( ! V_366 -> V_292 ) ) {
V_373:
V_1 = F_395 ( V_366 , V_240 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_104 < V_368 )
V_155 = V_366 -> V_155 ;
#endif
F_400 ( V_1 , V_155 - 1 ) ;
V_366 -> V_374 = F_401 ( V_1 ) ;
V_366 -> V_375 = V_155 ;
V_366 -> V_372 = V_155 ;
}
V_372 = V_366 -> V_372 - V_371 ;
if ( F_34 ( V_372 < 0 ) ) {
V_1 = F_287 ( V_366 -> V_292 ) ;
if ( ! F_398 ( V_1 , V_366 -> V_375 ) )
goto V_373;
#if ( V_104 < V_368 )
V_155 = V_366 -> V_155 ;
#endif
F_61 ( V_1 , V_155 ) ;
V_366 -> V_375 = V_155 ;
V_372 = V_155 - V_371 ;
}
V_366 -> V_375 -- ;
V_366 -> V_372 = V_372 ;
return V_366 -> V_292 + V_372 ;
}
void F_402 ( void * V_364 )
{
struct V_1 * V_1 = F_403 ( V_364 ) ;
if ( F_34 ( F_393 ( V_1 ) ) )
F_55 ( V_1 , F_56 ( V_1 ) ) ;
}
static void * F_404 ( unsigned long V_364 , unsigned int V_62 ,
T_12 V_155 )
{
if ( V_364 ) {
unsigned long V_376 = V_364 + ( V_104 << V_62 ) ;
unsigned long V_377 = V_364 + F_405 ( V_155 ) ;
F_284 ( F_287 ( ( void * ) V_364 ) , V_62 ) ;
while ( V_377 < V_376 ) {
F_406 ( V_377 ) ;
V_377 += V_104 ;
}
}
return ( void * ) V_364 ;
}
void * F_407 ( T_12 V_155 , T_7 V_240 )
{
unsigned int V_62 = F_408 ( V_155 ) ;
unsigned long V_364 ;
V_364 = F_390 ( V_240 , V_62 ) ;
return F_404 ( V_364 , V_62 , V_155 ) ;
}
void * T_2 F_409 ( int V_19 , T_12 V_155 , T_7 V_240 )
{
unsigned int V_62 = F_408 ( V_155 ) ;
struct V_1 * V_66 = F_396 ( V_19 , V_240 , V_62 ) ;
if ( ! V_66 )
return NULL ;
return F_404 ( ( unsigned long ) F_130 ( V_66 ) , V_62 , V_155 ) ;
}
void F_410 ( void * V_378 , T_12 V_155 )
{
unsigned long V_364 = ( unsigned long ) V_378 ;
unsigned long V_119 = V_364 + F_405 ( V_155 ) ;
while ( V_364 < V_119 ) {
F_406 ( V_364 ) ;
V_364 += V_104 ;
}
}
static unsigned long F_411 ( int V_372 )
{
struct V_192 * V_193 ;
struct V_43 * V_43 ;
unsigned long V_379 = 0 ;
struct V_191 * V_191 = F_378 ( F_294 () , V_380 ) ;
F_412 (zone, z, zonelist, offset) {
unsigned long V_155 = V_43 -> V_123 ;
unsigned long V_153 = F_413 ( V_43 ) ;
if ( V_155 > V_153 )
V_379 += V_155 - V_153 ;
}
return V_379 ;
}
unsigned long F_414 ( void )
{
return F_411 ( F_381 ( V_381 ) ) ;
}
unsigned long F_415 ( void )
{
return F_411 ( F_381 ( V_382 ) ) ;
}
static inline void F_416 ( struct V_43 * V_43 )
{
if ( F_112 ( F_293 ) )
F_417 ( L_32 , F_41 ( V_43 ) ) ;
}
long F_418 ( void )
{
long V_337 ;
unsigned long V_383 ;
unsigned long V_384 = 0 ;
unsigned long V_385 [ V_386 ] ;
struct V_43 * V_43 ;
int V_78 ;
for ( V_78 = V_387 ; V_78 < V_386 ; V_78 ++ )
V_385 [ V_78 ] = F_419 ( V_388 + V_78 ) ;
F_420 (zone)
V_384 += V_43 -> V_221 [ V_389 ] ;
V_337 = F_421 ( V_201 ) - V_390 ;
V_383 = V_385 [ V_391 ] + V_385 [ V_392 ] ;
V_383 -= F_11 ( V_383 / 2 , V_384 ) ;
V_337 += V_383 ;
V_337 += F_419 ( V_393 ) -
F_11 ( F_419 ( V_393 ) / 2 ,
V_384 ) ;
if ( V_337 < 0 )
V_337 = 0 ;
return V_337 ;
}
void F_422 ( struct V_394 * V_395 )
{
V_395 -> V_396 = V_397 ;
V_395 -> V_398 = F_419 ( V_399 ) ;
V_395 -> V_400 = F_421 ( V_201 ) ;
V_395 -> V_401 = F_423 () ;
V_395 -> V_402 = V_403 ;
V_395 -> V_404 = F_424 () ;
V_395 -> V_405 = V_104 ;
}
void F_425 ( struct V_394 * V_395 , int V_19 )
{
int V_406 ;
unsigned long V_123 = 0 ;
unsigned long V_407 = 0 ;
unsigned long V_408 = 0 ;
T_1 * V_9 = F_15 ( V_19 ) ;
for ( V_406 = 0 ; V_406 < V_116 ; V_406 ++ )
V_123 += V_9 -> V_117 [ V_406 ] . V_123 ;
V_395 -> V_396 = V_123 ;
V_395 -> V_398 = F_426 ( V_9 , V_399 ) ;
V_395 -> V_400 = F_427 ( V_19 , V_201 ) ;
#ifdef F_428
for ( V_406 = 0 ; V_406 < V_116 ; V_406 ++ ) {
struct V_43 * V_43 = & V_9 -> V_117 [ V_406 ] ;
if ( F_429 ( V_43 ) ) {
V_407 += V_43 -> V_123 ;
V_408 += F_314 ( V_43 , V_201 ) ;
}
}
V_395 -> V_402 = V_407 ;
V_395 -> V_404 = V_408 ;
#else
V_395 -> V_402 = V_407 ;
V_395 -> V_404 = V_408 ;
#endif
V_395 -> V_405 = V_104 ;
}
static bool F_430 ( unsigned int V_37 , int V_19 , T_10 * V_277 )
{
if ( ! ( V_37 & V_279 ) )
return false ;
if ( ! V_277 )
V_277 = & V_359 ;
return ! F_431 ( V_19 , * V_277 ) ;
}
static void F_432 ( unsigned char type )
{
static const char V_409 [ V_182 ] = {
[ V_41 ] = 'U' ,
[ V_135 ] = 'M' ,
[ V_170 ] = 'E' ,
[ V_187 ] = 'H' ,
#ifdef F_313
[ V_150 ] = 'C' ,
#endif
#ifdef F_433
[ V_410 ] = 'I' ,
#endif
} ;
char V_411 [ V_182 + 1 ] ;
char * V_66 = V_411 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_182 ; V_63 ++ ) {
if ( type & ( 1 << V_63 ) )
* V_66 ++ = V_409 [ V_63 ] ;
}
* V_66 = '\0' ;
F_417 ( V_412 L_33 , V_411 ) ;
}
void F_434 ( unsigned int V_278 , T_10 * V_277 )
{
unsigned long V_413 = 0 ;
int V_204 ;
struct V_43 * V_43 ;
T_1 * V_9 ;
F_201 (zone) {
if ( F_430 ( V_278 , F_41 ( V_43 ) , V_277 ) )
continue;
F_262 (cpu)
V_413 += F_251 ( V_43 -> V_207 , V_204 ) -> V_107 . V_105 ;
}
F_417 ( L_34
L_35
L_36
L_37
L_38
L_39 ,
F_419 ( V_414 ) ,
F_419 ( V_415 ) ,
F_419 ( V_416 ) ,
F_419 ( V_417 ) ,
F_419 ( V_418 ) ,
F_419 ( V_419 ) ,
F_419 ( V_420 ) ,
F_419 ( V_421 ) ,
F_419 ( V_422 ) ,
F_419 ( V_423 ) ,
F_419 ( V_393 ) ,
F_419 ( V_424 ) ,
F_419 ( V_425 ) ,
F_419 ( V_399 ) ,
F_421 ( V_426 ) ,
F_421 ( V_427 ) ,
F_421 ( V_201 ) ,
V_413 ,
F_421 ( V_200 ) ) ;
F_435 (pgdat) {
if ( F_430 ( V_278 , V_9 -> V_139 , V_277 ) )
continue;
F_417 ( L_40
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
#ifdef F_436
L_52
L_53
L_54
#endif
L_55
L_56
L_57
L_58 ,
V_9 -> V_139 ,
F_437 ( F_426 ( V_9 , V_414 ) ) ,
F_437 ( F_426 ( V_9 , V_415 ) ) ,
F_437 ( F_426 ( V_9 , V_417 ) ) ,
F_437 ( F_426 ( V_9 , V_418 ) ) ,
F_437 ( F_426 ( V_9 , V_420 ) ) ,
F_437 ( F_426 ( V_9 , V_416 ) ) ,
F_437 ( F_426 ( V_9 , V_419 ) ) ,
F_437 ( F_426 ( V_9 , V_425 ) ) ,
F_437 ( F_426 ( V_9 , V_421 ) ) ,
F_437 ( F_426 ( V_9 , V_422 ) ) ,
F_437 ( F_426 ( V_9 , V_399 ) ) ,
#ifdef F_436
F_437 ( F_426 ( V_9 , V_428 ) * V_429 ) ,
F_437 ( F_426 ( V_9 , V_430 )
* V_429 ) ,
F_437 ( F_426 ( V_9 , V_431 ) * V_429 ) ,
#endif
F_437 ( F_426 ( V_9 , V_432 ) ) ,
F_437 ( F_426 ( V_9 , V_423 ) ) ,
V_9 -> V_433 >= V_336 ?
L_59 : L_60 ) ;
}
F_201 (zone) {
int V_63 ;
if ( F_430 ( V_278 , F_41 ( V_43 ) , V_277 ) )
continue;
V_413 = 0 ;
F_262 (cpu)
V_413 += F_251 ( V_43 -> V_207 , V_204 ) -> V_107 . V_105 ;
F_416 ( V_43 ) ;
F_417 ( V_412
L_61
L_62
L_63
L_64
L_65
L_41
L_42
L_43
L_44
L_45
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
L_58 ,
V_43 -> V_49 ,
F_437 ( F_314 ( V_43 , V_201 ) ) ,
F_437 ( F_290 ( V_43 ) ) ,
F_437 ( F_438 ( V_43 ) ) ,
F_437 ( F_413 ( V_43 ) ) ,
F_437 ( F_314 ( V_43 , V_434 ) ) ,
F_437 ( F_314 ( V_43 , V_435 ) ) ,
F_437 ( F_314 ( V_43 , V_436 ) ) ,
F_437 ( F_314 ( V_43 , V_437 ) ) ,
F_437 ( F_314 ( V_43 , V_438 ) ) ,
F_437 ( F_314 ( V_43 , V_342 ) ) ,
F_437 ( V_43 -> V_439 ) ,
F_437 ( V_43 -> V_123 ) ,
F_437 ( F_314 ( V_43 , V_440 ) ) ,
F_314 ( V_43 , V_441 ) ,
F_437 ( F_314 ( V_43 , V_426 ) ) ,
F_437 ( F_314 ( V_43 , V_427 ) ) ,
F_437 ( V_413 ) ,
F_437 ( F_439 ( V_43 -> V_207 -> V_107 . V_105 ) ) ,
F_437 ( F_314 ( V_43 , V_200 ) ) ) ;
F_417 ( L_76 ) ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ )
F_417 ( V_412 L_77 , V_43 -> V_259 [ V_63 ] ) ;
F_417 ( V_412 L_58 ) ;
}
F_201 (zone) {
unsigned int V_62 ;
unsigned long V_442 [ V_74 ] , V_37 , V_443 = 0 ;
unsigned char V_409 [ V_74 ] ;
if ( F_430 ( V_278 , F_41 ( V_43 ) , V_277 ) )
continue;
F_416 ( V_43 ) ;
F_417 ( V_412 L_25 , V_43 -> V_49 ) ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_87 * V_154 = & V_43 -> V_87 [ V_62 ] ;
int type ;
V_442 [ V_62 ] = V_154 -> V_88 ;
V_443 += V_442 [ V_62 ] << V_62 ;
V_409 [ V_62 ] = 0 ;
for ( type = 0 ; type < V_182 ; type ++ ) {
if ( ! F_140 ( & V_154 -> V_92 [ type ] ) )
V_409 [ V_62 ] |= 1 << type ;
}
}
F_238 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
F_417 ( V_412 L_78 ,
V_442 [ V_62 ] , F_437 ( 1UL ) << V_62 ) ;
if ( V_442 [ V_62 ] )
F_432 ( V_409 [ V_62 ] ) ;
}
F_417 ( V_412 L_79 , F_437 ( V_443 ) ) ;
}
F_440 () ;
F_417 ( L_80 , F_419 ( V_444 ) ) ;
F_441 () ;
}
static void F_442 ( struct V_43 * V_43 , struct V_192 * V_192 )
{
V_192 -> V_43 = V_43 ;
V_192 -> V_445 = V_445 ( V_43 ) ;
}
static int F_443 ( T_1 * V_9 , struct V_191 * V_191 ,
int V_446 )
{
struct V_43 * V_43 ;
enum V_406 V_406 = V_116 ;
do {
V_406 -- ;
V_43 = V_9 -> V_117 + V_406 ;
if ( F_444 ( V_43 ) ) {
F_442 ( V_43 ,
& V_191 -> V_447 [ V_446 ++ ] ) ;
F_445 ( V_406 ) ;
}
} while ( V_406 );
return V_446 ;
}
static int F_446 ( char * V_448 )
{
if ( * V_448 == 'd' || * V_448 == 'D' ) {
V_449 = V_450 ;
} else if ( * V_448 == 'n' || * V_448 == 'N' ) {
V_449 = V_451 ;
} else if ( * V_448 == 'z' || * V_448 == 'Z' ) {
V_449 = V_452 ;
} else {
F_335 ( L_81 , V_448 ) ;
return - V_70 ;
}
return 0 ;
}
static T_5 int F_447 ( char * V_448 )
{
int V_44 ;
if ( ! V_448 )
return 0 ;
V_44 = F_446 ( V_448 ) ;
if ( V_44 == 0 )
F_448 ( V_453 , V_448 , V_454 ) ;
return V_44 ;
}
int F_449 ( struct V_455 * V_456 , int V_457 ,
void T_13 * V_458 , T_12 * V_459 ,
T_14 * V_460 )
{
char V_461 [ V_454 ] ;
int V_44 ;
static F_450 ( V_462 ) ;
F_261 ( & V_462 ) ;
if ( V_457 ) {
if ( strlen ( ( char * ) V_456 -> V_138 ) >= V_454 ) {
V_44 = - V_70 ;
goto V_56;
}
strcpy ( V_461 , ( char * ) V_456 -> V_138 ) ;
}
V_44 = F_451 ( V_456 , V_457 , V_458 , V_459 , V_460 ) ;
if ( V_44 )
goto V_56;
if ( V_457 ) {
int V_463 = V_449 ;
V_44 = F_446 ( ( char * ) V_456 -> V_138 ) ;
if ( V_44 ) {
strncpy ( ( char * ) V_456 -> V_138 , V_461 ,
V_454 ) ;
V_449 = V_463 ;
} else if ( V_463 != V_449 ) {
F_452 () ;
F_261 ( & V_464 ) ;
F_453 ( NULL , NULL ) ;
F_269 ( & V_464 ) ;
F_454 () ;
}
}
V_56:
F_269 ( & V_462 ) ;
return V_44 ;
}
static int F_455 ( int V_127 , T_10 * V_465 )
{
int V_466 , V_395 ;
int V_467 = V_468 ;
int V_469 = V_369 ;
const struct V_144 * V_411 = F_184 ( 0 ) ;
if ( ! F_431 ( V_127 , * V_465 ) ) {
F_456 ( V_127 , * V_465 ) ;
return V_127 ;
}
F_195 (n, N_MEMORY) {
if ( F_431 ( V_466 , * V_465 ) )
continue;
V_395 = F_319 ( V_127 , V_466 ) ;
V_395 += ( V_466 < V_127 ) ;
V_411 = F_184 ( V_466 ) ;
if ( ! F_185 ( V_411 ) )
V_395 += V_470 ;
V_395 *= ( V_471 * V_472 ) ;
V_395 += V_473 [ V_466 ] ;
if ( V_395 < V_467 ) {
V_467 = V_395 ;
V_469 = V_466 ;
}
}
if ( V_469 >= 0 )
F_456 ( V_469 , * V_465 ) ;
return V_469 ;
}
static void F_457 ( T_1 * V_9 , int V_127 )
{
int V_474 ;
struct V_191 * V_191 ;
V_191 = & V_9 -> V_475 [ V_476 ] ;
for ( V_474 = 0 ; V_191 -> V_447 [ V_474 ] . V_43 != NULL ; V_474 ++ )
;
V_474 = F_443 ( F_15 ( V_127 ) , V_191 , V_474 ) ;
V_191 -> V_447 [ V_474 ] . V_43 = NULL ;
V_191 -> V_447 [ V_474 ] . V_445 = 0 ;
}
static void F_458 ( T_1 * V_9 )
{
int V_474 ;
struct V_191 * V_191 ;
V_191 = & V_9 -> V_475 [ V_477 ] ;
V_474 = F_443 ( V_9 , V_191 , 0 ) ;
V_191 -> V_447 [ V_474 ] . V_43 = NULL ;
V_191 -> V_447 [ V_474 ] . V_445 = 0 ;
}
static void F_459 ( T_1 * V_9 , int V_478 )
{
int V_479 , V_474 , V_127 ;
int V_406 ;
struct V_43 * V_193 ;
struct V_191 * V_191 ;
V_191 = & V_9 -> V_475 [ V_476 ] ;
V_479 = 0 ;
for ( V_406 = V_116 - 1 ; V_406 >= 0 ; V_406 -- ) {
for ( V_474 = 0 ; V_474 < V_478 ; V_474 ++ ) {
V_127 = V_480 [ V_474 ] ;
V_193 = & F_15 ( V_127 ) -> V_117 [ V_406 ] ;
if ( F_444 ( V_193 ) ) {
F_442 ( V_193 ,
& V_191 -> V_447 [ V_479 ++ ] ) ;
F_445 ( V_406 ) ;
}
}
}
V_191 -> V_447 [ V_479 ] . V_43 = NULL ;
V_191 -> V_447 [ V_479 ] . V_445 = 0 ;
}
static int F_460 ( void )
{
return V_451 ;
}
static int F_460 ( void )
{
return V_452 ;
}
static void F_461 ( void )
{
if ( V_449 == V_450 )
V_481 = F_460 () ;
else
V_481 = V_449 ;
}
static void F_462 ( T_1 * V_9 )
{
int V_63 , V_127 , V_482 ;
T_10 V_483 ;
int V_484 , V_485 ;
struct V_191 * V_191 ;
unsigned int V_62 = V_481 ;
for ( V_63 = 0 ; V_63 < V_486 ; V_63 ++ ) {
V_191 = V_9 -> V_475 + V_63 ;
V_191 -> V_447 [ 0 ] . V_43 = NULL ;
V_191 -> V_447 [ 0 ] . V_445 = 0 ;
}
V_484 = V_9 -> V_139 ;
V_482 = V_487 ;
V_485 = V_484 ;
F_463 ( V_483 ) ;
memset ( V_480 , 0 , sizeof( V_480 ) ) ;
V_63 = 0 ;
while ( ( V_127 = F_455 ( V_484 , & V_483 ) ) >= 0 ) {
if ( F_319 ( V_484 , V_127 ) !=
F_319 ( V_484 , V_485 ) )
V_473 [ V_127 ] = V_482 ;
V_485 = V_127 ;
V_482 -- ;
if ( V_62 == V_451 )
F_457 ( V_9 , V_127 ) ;
else
V_480 [ V_63 ++ ] = V_127 ;
}
if ( V_62 == V_452 ) {
F_459 ( V_9 , V_63 ) ;
}
F_458 ( V_9 ) ;
}
int F_464 ( int V_127 )
{
struct V_192 * V_193 ;
V_193 = F_377 ( F_378 ( V_127 , V_380 ) ,
F_381 ( V_380 ) ,
NULL ) ;
return V_193 -> V_43 -> V_127 ;
}
static void F_461 ( void )
{
V_481 = V_452 ;
}
static void F_462 ( T_1 * V_9 )
{
int V_127 , V_484 ;
enum V_406 V_474 ;
struct V_191 * V_191 ;
V_484 = V_9 -> V_139 ;
V_191 = & V_9 -> V_475 [ V_476 ] ;
V_474 = F_443 ( V_9 , V_191 , 0 ) ;
for ( V_127 = V_484 + 1 ; V_127 < V_472 ; V_127 ++ ) {
if ( ! F_14 ( V_127 ) )
continue;
V_474 = F_443 ( F_15 ( V_127 ) , V_191 , V_474 ) ;
}
for ( V_127 = 0 ; V_127 < V_484 ; V_127 ++ ) {
if ( ! F_14 ( V_127 ) )
continue;
V_474 = F_443 ( F_15 ( V_127 ) , V_191 , V_474 ) ;
}
V_191 -> V_447 [ V_474 ] . V_43 = NULL ;
V_191 -> V_447 [ V_474 ] . V_445 = 0 ;
}
static int F_465 ( void * V_138 )
{
int V_19 ;
int V_204 ;
T_1 * V_488 = V_138 ;
#ifdef F_293
memset ( V_473 , 0 , sizeof( V_473 ) ) ;
#endif
if ( V_488 && ! F_14 ( V_488 -> V_139 ) ) {
F_462 ( V_488 ) ;
}
F_466 (nid) {
T_1 * V_9 = F_15 ( V_19 ) ;
F_462 ( V_9 ) ;
}
F_467 (cpu) {
F_468 ( & F_469 ( V_489 , V_204 ) , 0 ) ;
#ifdef F_470
if ( F_471 ( V_204 ) )
F_472 ( V_204 , F_464 ( F_473 ( V_204 ) ) ) ;
#endif
}
return 0 ;
}
static T_15 void T_5
F_474 ( void )
{
F_465 ( NULL ) ;
F_475 () ;
F_476 () ;
}
void T_16 F_453 ( T_1 * V_9 , struct V_43 * V_43 )
{
F_461 () ;
if ( V_490 == V_491 ) {
F_474 () ;
} else {
#ifdef F_477
if ( V_43 )
F_478 ( V_43 ) ;
#endif
F_479 ( F_465 , V_9 , NULL ) ;
}
V_492 = F_415 () ;
if ( V_492 < ( V_27 * V_182 ) )
V_39 = 1 ;
else
V_39 = 0 ;
F_73 ( L_82 ,
V_487 ,
V_493 [ V_481 ] ,
V_39 ? L_83 : L_84 ,
V_492 ) ;
#ifdef F_293
F_73 ( L_85 , V_494 [ V_495 ] ) ;
#endif
}
void T_2 F_480 ( unsigned long V_155 , int V_19 , unsigned long V_43 ,
unsigned long V_47 , enum V_496 V_497 )
{
struct V_498 * V_499 = F_481 ( F_482 ( V_47 ) ) ;
unsigned long V_120 = V_47 + V_155 ;
T_1 * V_9 = F_15 ( V_19 ) ;
unsigned long V_18 ;
unsigned long V_21 = 0 ;
#ifdef F_483
struct V_500 * V_501 = NULL , * V_411 ;
#endif
if ( V_502 < V_120 - 1 )
V_502 = V_120 - 1 ;
if ( V_499 && V_47 == V_499 -> V_503 )
V_47 += V_499 -> V_504 ;
for ( V_18 = V_47 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_497 != V_505 )
goto V_506;
if ( ! F_484 ( V_18 ) ) {
#ifdef F_483
V_18 = F_485 ( V_18 , V_120 ) - 1 ;
#endif
continue;
}
if ( ! F_172 ( V_18 , V_19 ) )
continue;
if ( ! F_16 ( V_9 , V_18 , V_120 , & V_21 ) )
break;
#ifdef F_483
if ( V_507 && V_43 == V_508 ) {
if ( ! V_501 || V_18 >= F_486 ( V_501 ) ) {
F_487 (memory, tmp)
if ( V_18 < F_486 ( V_411 ) )
break;
V_501 = V_411 ;
}
if ( V_18 >= F_488 ( V_501 ) &&
F_489 ( V_501 ) ) {
V_18 = F_486 ( V_501 ) ;
continue;
}
}
#endif
V_506:
if ( ! ( V_18 & ( V_27 - 1 ) ) ) {
struct V_1 * V_1 = F_153 ( V_18 ) ;
F_145 ( V_1 , V_18 , V_43 , V_19 ) ;
F_33 ( V_1 , V_135 ) ;
} else {
F_152 ( V_18 , V_43 , V_19 ) ;
}
}
}
static void T_2 F_490 ( struct V_43 * V_43 )
{
unsigned int V_62 , V_218 ;
F_275 (order, t) {
F_78 ( & V_43 -> V_87 [ V_62 ] . V_92 [ V_218 ] ) ;
V_43 -> V_87 [ V_62 ] . V_88 = 0 ;
}
}
static int F_491 ( struct V_43 * V_43 )
{
#ifdef F_492
int V_203 ;
V_203 = V_43 -> V_123 / 1024 ;
if ( V_203 * V_104 > 512 * 1024 )
V_203 = ( 512 * 1024 ) / V_104 ;
V_203 /= 4 ;
if ( V_203 < 1 )
V_203 = 1 ;
V_203 = F_493 ( V_203 + V_203 / 2 ) - 1 ;
return V_203 ;
#else
return 0 ;
#endif
}
static void F_494 ( struct V_106 * V_107 , unsigned long V_153 ,
unsigned long V_203 )
{
V_107 -> V_203 = 1 ;
F_495 () ;
V_107 -> V_153 = V_153 ;
F_495 () ;
V_107 -> V_203 = V_203 ;
}
static void F_496 ( struct V_205 * V_66 , unsigned long V_203 )
{
F_494 ( & V_66 -> V_107 , 6 * V_203 , F_9 ( 1UL , 1 * V_203 ) ) ;
}
static void F_497 ( struct V_205 * V_66 )
{
struct V_106 * V_107 ;
int V_3 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_107 = & V_66 -> V_107 ;
V_107 -> V_105 = 0 ;
for ( V_3 = 0 ; V_3 < V_40 ; V_3 ++ )
F_78 ( & V_107 -> V_113 [ V_3 ] ) ;
}
static void F_468 ( struct V_205 * V_66 , unsigned long V_203 )
{
F_497 ( V_66 ) ;
F_496 ( V_66 , V_203 ) ;
}
static void F_498 ( struct V_205 * V_66 ,
unsigned long V_153 )
{
unsigned long V_203 = F_9 ( 1UL , V_153 / 4 ) ;
if ( ( V_153 / 4 ) > ( V_12 * 8 ) )
V_203 = V_12 * 8 ;
F_494 ( & V_66 -> V_107 , V_153 , V_203 ) ;
}
static void F_499 ( struct V_43 * V_43 ,
struct V_205 * V_107 )
{
if ( V_509 )
F_498 ( V_107 ,
( V_43 -> V_123 /
V_509 ) ) ;
else
F_496 ( V_107 , F_491 ( V_43 ) ) ;
}
static void T_2 F_500 ( struct V_43 * V_43 , int V_204 )
{
struct V_205 * V_107 = F_251 ( V_43 -> V_207 , V_204 ) ;
F_497 ( V_107 ) ;
F_499 ( V_43 , V_107 ) ;
}
static void T_2 F_478 ( struct V_43 * V_43 )
{
int V_204 ;
V_43 -> V_207 = F_501 ( struct V_205 ) ;
F_467 (cpu)
F_500 ( V_43 , V_204 ) ;
}
void T_5 F_502 ( void )
{
struct V_265 * V_9 ;
struct V_43 * V_43 ;
F_201 (zone)
F_478 ( V_43 ) ;
F_435 (pgdat)
V_9 -> V_510 =
F_501 ( struct V_511 ) ;
}
static T_2 void F_503 ( struct V_43 * V_43 )
{
V_43 -> V_207 = & V_489 ;
if ( F_190 ( V_43 ) )
F_417 ( V_512 L_86 ,
V_43 -> V_49 , V_43 -> V_439 ,
F_491 ( V_43 ) ) ;
}
void T_2 F_504 ( struct V_43 * V_43 ,
unsigned long V_26 ,
unsigned long V_155 )
{
struct V_265 * V_9 = V_43 -> V_269 ;
V_9 -> V_446 = V_445 ( V_43 ) + 1 ;
V_43 -> V_26 = V_26 ;
F_505 ( V_513 , L_87 ,
L_88 ,
V_9 -> V_139 ,
( unsigned long ) V_445 ( V_43 ) ,
V_26 , ( V_26 + V_155 ) ) ;
F_490 ( V_43 ) ;
V_43 -> V_514 = 1 ;
}
int T_2 F_170 ( unsigned long V_18 ,
struct V_128 * V_129 )
{
unsigned long V_47 , V_120 ;
int V_19 ;
if ( V_129 -> V_515 <= V_18 && V_18 < V_129 -> V_516 )
return V_129 -> V_517 ;
V_19 = F_506 ( V_18 , & V_47 , & V_120 ) ;
if ( V_19 != - 1 ) {
V_129 -> V_515 = V_47 ;
V_129 -> V_516 = V_120 ;
V_129 -> V_517 = V_19 ;
}
return V_19 ;
}
void T_5 F_507 ( int V_19 , unsigned long V_518 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_519 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_47 = F_11 ( V_47 , V_518 ) ;
V_120 = F_11 ( V_120 , V_518 ) ;
if ( V_47 < V_120 )
F_508 ( F_509 ( V_47 ) ,
( V_120 - V_47 ) << V_12 ,
V_519 ) ;
}
}
void T_5 F_510 ( int V_19 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_519 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_511 ( V_519 , V_47 , V_120 ) ;
}
void T_2 F_512 ( unsigned int V_19 ,
unsigned long * V_47 , unsigned long * V_120 )
{
unsigned long V_520 , V_521 ;
int V_63 ;
* V_47 = - 1UL ;
* V_120 = 0 ;
F_188 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_47 = F_11 ( * V_47 , V_520 ) ;
* V_120 = F_9 ( * V_120 , V_521 ) ;
}
if ( * V_47 == - 1UL )
* V_47 = 0 ;
}
static void T_5 F_513 ( void )
{
int V_522 ;
for ( V_522 = V_116 - 1 ; V_522 >= 0 ; V_522 -- ) {
if ( V_522 == V_508 )
continue;
if ( V_523 [ V_522 ] >
V_524 [ V_522 ] )
break;
}
F_96 ( V_522 == - 1 ) ;
V_525 = V_522 ;
}
static void T_2 F_514 ( int V_19 ,
unsigned long V_406 ,
unsigned long V_14 ,
unsigned long V_526 ,
unsigned long * V_26 ,
unsigned long * F_155 )
{
if ( V_527 [ V_19 ] ) {
if ( V_406 == V_508 ) {
* V_26 = V_527 [ V_19 ] ;
* F_155 = F_11 ( V_526 ,
V_523 [ V_525 ] ) ;
} else if ( ! V_507 &&
* V_26 < V_527 [ V_19 ] &&
* F_155 > V_527 [ V_19 ] ) {
* F_155 = V_527 [ V_19 ] ;
} else if ( * V_26 >= V_527 [ V_19 ] )
* V_26 = * F_155 ;
}
}
static unsigned long T_2 F_515 ( int V_19 ,
unsigned long V_406 ,
unsigned long V_14 ,
unsigned long V_526 ,
unsigned long * V_26 ,
unsigned long * F_155 ,
unsigned long * V_528 )
{
if ( ! V_14 && ! V_526 )
return 0 ;
* V_26 = V_524 [ V_406 ] ;
* F_155 = V_523 [ V_406 ] ;
F_514 ( V_19 , V_406 ,
V_14 , V_526 ,
V_26 , F_155 ) ;
if ( * F_155 < V_14 || * V_26 > V_526 )
return 0 ;
* F_155 = F_11 ( * F_155 , V_526 ) ;
* V_26 = F_9 ( * V_26 , V_14 ) ;
return * F_155 - * V_26 ;
}
unsigned long T_2 F_516 ( int V_19 ,
unsigned long V_529 ,
unsigned long V_530 )
{
unsigned long V_531 = V_530 - V_529 ;
unsigned long V_47 , V_120 ;
int V_63 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
V_47 = F_517 ( V_47 , V_529 , V_530 ) ;
V_120 = F_517 ( V_120 , V_529 , V_530 ) ;
V_531 -= V_120 - V_47 ;
}
return V_531 ;
}
unsigned long T_5 F_518 ( unsigned long V_47 ,
unsigned long V_120 )
{
return F_516 ( V_472 , V_47 , V_120 ) ;
}
static unsigned long T_2 F_519 ( int V_19 ,
unsigned long V_406 ,
unsigned long V_14 ,
unsigned long V_526 ,
unsigned long * V_528 )
{
unsigned long V_532 = V_524 [ V_406 ] ;
unsigned long V_533 = V_523 [ V_406 ] ;
unsigned long V_26 , F_155 ;
unsigned long V_531 ;
if ( ! V_14 && ! V_526 )
return 0 ;
V_26 = F_517 ( V_14 , V_532 , V_533 ) ;
F_155 = F_517 ( V_526 , V_532 , V_533 ) ;
F_514 ( V_19 , V_406 ,
V_14 , V_526 ,
& V_26 , & F_155 ) ;
V_531 = F_516 ( V_19 , V_26 , F_155 ) ;
if ( V_507 && V_527 [ V_19 ] ) {
unsigned long V_47 , V_120 ;
struct V_500 * V_501 ;
F_487 (memory, r) {
V_47 = F_517 ( F_488 ( V_501 ) ,
V_26 , F_155 ) ;
V_120 = F_517 ( F_486 ( V_501 ) ,
V_26 , F_155 ) ;
if ( V_406 == V_508 &&
F_489 ( V_501 ) )
V_531 += V_120 - V_47 ;
if ( V_406 == V_304 &&
! F_489 ( V_501 ) )
V_531 += V_120 - V_47 ;
}
}
return V_531 ;
}
static inline unsigned long T_2 F_515 ( int V_19 ,
unsigned long V_406 ,
unsigned long V_14 ,
unsigned long V_526 ,
unsigned long * V_26 ,
unsigned long * F_155 ,
unsigned long * V_534 )
{
unsigned int V_43 ;
* V_26 = V_14 ;
for ( V_43 = 0 ; V_43 < V_406 ; V_43 ++ )
* V_26 += V_534 [ V_43 ] ;
* F_155 = * V_26 + V_534 [ V_406 ] ;
return V_534 [ V_406 ] ;
}
static inline unsigned long T_2 F_519 ( int V_19 ,
unsigned long V_406 ,
unsigned long V_14 ,
unsigned long V_526 ,
unsigned long * V_535 )
{
if ( ! V_535 )
return 0 ;
return V_535 [ V_406 ] ;
}
static void T_2 F_520 ( struct V_265 * V_9 ,
unsigned long V_14 ,
unsigned long V_526 ,
unsigned long * V_534 ,
unsigned long * V_535 )
{
unsigned long V_536 = 0 , V_537 = 0 ;
enum V_406 V_63 ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_63 ;
unsigned long V_26 , F_155 ;
unsigned long V_155 , V_538 ;
V_155 = F_515 ( V_9 -> V_139 , V_63 ,
V_14 ,
V_526 ,
& V_26 ,
& F_155 ,
V_534 ) ;
V_538 = V_155 - F_519 ( V_9 -> V_139 , V_63 ,
V_14 , V_526 ,
V_535 ) ;
if ( V_155 )
V_43 -> V_26 = V_26 ;
else
V_43 -> V_26 = 0 ;
V_43 -> V_48 = V_155 ;
V_43 -> V_439 = V_538 ;
V_537 += V_155 ;
V_536 += V_538 ;
}
V_9 -> V_13 = V_537 ;
V_9 -> V_539 = V_536 ;
F_417 ( V_512 L_89 , V_9 -> V_139 ,
V_536 ) ;
}
static unsigned long T_5 F_521 ( unsigned long V_26 , unsigned long V_540 )
{
unsigned long V_541 ;
V_540 += V_26 & ( V_27 - 1 ) ;
V_541 = F_522 ( V_540 , V_27 ) ;
V_541 = V_541 >> V_24 ;
V_541 *= V_25 ;
V_541 = F_522 ( V_541 , 8 * sizeof( unsigned long ) ) ;
return V_541 / 8 ;
}
static void T_5 F_523 ( struct V_265 * V_9 ,
struct V_43 * V_43 ,
unsigned long V_26 ,
unsigned long V_540 )
{
unsigned long V_541 = F_521 ( V_26 , V_540 ) ;
V_43 -> V_23 = NULL ;
if ( V_541 )
V_43 -> V_23 =
F_524 ( V_541 ,
V_9 -> V_139 ) ;
}
static inline void F_523 ( struct V_265 * V_9 , struct V_43 * V_43 ,
unsigned long V_26 , unsigned long V_540 ) {}
void T_17 F_525 ( void )
{
unsigned int V_62 ;
if ( V_24 )
return;
if ( V_542 > V_12 )
V_62 = V_543 ;
else
V_62 = V_74 - 1 ;
V_24 = V_62 ;
}
void T_17 F_525 ( void )
{
}
static unsigned long T_17 F_526 ( unsigned long V_48 ,
unsigned long V_439 )
{
unsigned long V_385 = V_48 ;
if ( V_48 > V_439 + ( V_439 >> 4 ) &&
F_112 ( F_19 ) )
V_385 = V_439 ;
return F_405 ( V_385 * sizeof( struct V_1 ) ) >> V_12 ;
}
static void T_17 F_527 ( struct V_265 * V_9 )
{
enum V_406 V_474 ;
int V_19 = V_9 -> V_139 ;
F_528 ( V_9 ) ;
#ifdef F_529
F_530 ( & V_9 -> V_544 ) ;
V_9 -> V_545 = 0 ;
V_9 -> V_546 = V_55 ;
#endif
#ifdef F_436
F_530 ( & V_9 -> V_547 ) ;
F_78 ( & V_9 -> V_548 ) ;
V_9 -> V_549 = 0 ;
#endif
F_531 ( & V_9 -> V_550 ) ;
F_531 ( & V_9 -> V_551 ) ;
#ifdef F_532
F_531 ( & V_9 -> V_552 ) ;
#endif
F_533 ( V_9 ) ;
F_530 ( & V_9 -> V_553 ) ;
F_534 ( F_535 ( V_9 ) ) ;
V_9 -> V_510 = & V_554 ;
for ( V_474 = 0 ; V_474 < V_116 ; V_474 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_474 ;
unsigned long V_155 , V_555 , V_556 , V_557 ;
unsigned long V_26 = V_43 -> V_26 ;
V_155 = V_43 -> V_48 ;
V_555 = V_556 = V_43 -> V_439 ;
V_557 = F_526 ( V_155 , V_555 ) ;
if ( ! F_149 ( V_474 ) ) {
if ( V_556 >= V_557 ) {
V_556 -= V_557 ;
if ( V_557 )
F_417 ( V_512
L_90 ,
V_494 [ V_474 ] , V_557 ) ;
} else
F_335 ( L_91 ,
V_494 [ V_474 ] , V_557 , V_556 ) ;
}
if ( V_474 == 0 && V_556 > V_558 ) {
V_556 -= V_558 ;
F_417 ( V_512 L_92 ,
V_494 [ 0 ] , V_558 ) ;
}
if ( ! F_149 ( V_474 ) )
V_559 += V_556 ;
else if ( V_559 > V_557 * 2 )
V_559 -= V_557 ;
V_560 += V_556 ;
V_43 -> V_123 = F_149 ( V_474 ) ? V_555 : V_556 ;
#ifdef F_293
V_43 -> V_127 = V_19 ;
#endif
V_43 -> V_49 = V_494 [ V_474 ] ;
V_43 -> V_269 = V_9 ;
F_530 ( & V_43 -> V_110 ) ;
F_536 ( V_43 ) ;
F_503 ( V_43 ) ;
if ( ! V_155 )
continue;
F_525 () ;
F_523 ( V_9 , V_43 , V_26 , V_155 ) ;
F_504 ( V_43 , V_26 , V_155 ) ;
F_537 ( V_155 , V_19 , V_474 , V_26 ) ;
}
}
static void T_16 F_538 ( struct V_265 * V_9 )
{
unsigned long T_4 V_118 = 0 ;
unsigned long T_4 V_372 = 0 ;
if ( ! V_9 -> V_13 )
return;
#ifdef F_539
V_118 = V_9 -> V_14 & ~ ( V_151 - 1 ) ;
V_372 = V_9 -> V_14 - V_118 ;
if ( ! V_9 -> V_561 ) {
unsigned long V_155 , V_119 ;
struct V_1 * V_562 ;
V_119 = F_17 ( V_9 ) ;
V_119 = F_177 ( V_119 , V_151 ) ;
V_155 = ( V_119 - V_118 ) * sizeof( struct V_1 ) ;
V_562 = F_540 ( V_9 -> V_139 , V_155 ) ;
if ( ! V_562 )
V_562 = F_524 ( V_155 ,
V_9 -> V_139 ) ;
V_9 -> V_561 = V_562 + V_372 ;
}
#ifndef F_541
if ( V_9 == F_15 ( 0 ) ) {
V_563 = F_15 ( 0 ) -> V_561 ;
#if F_542 ( F_483 ) || F_542 ( V_564 )
if ( F_37 ( V_563 ) != V_9 -> V_14 )
V_563 -= V_372 ;
#endif
}
#endif
#endif
}
void T_17 F_543 ( int V_19 , unsigned long * V_534 ,
unsigned long V_14 , unsigned long * V_535 )
{
T_1 * V_9 = F_15 ( V_19 ) ;
unsigned long V_47 = 0 ;
unsigned long V_120 = 0 ;
F_4 ( V_9 -> V_446 || V_9 -> V_565 ) ;
V_9 -> V_139 = V_19 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_510 = NULL ;
#ifdef F_483
F_512 ( V_19 , & V_47 , & V_120 ) ;
F_73 ( L_93 , V_19 ,
( V_566 ) V_47 << V_12 ,
V_120 ? ( ( V_566 ) V_120 << V_12 ) - 1 : 0 ) ;
#else
V_47 = V_14 ;
#endif
F_520 ( V_9 , V_47 , V_120 ,
V_534 , V_535 ) ;
F_538 ( V_9 ) ;
#ifdef F_539
F_417 ( V_512 L_94 ,
V_19 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_561 ) ;
#endif
F_8 ( V_9 ) ;
F_527 ( V_9 ) ;
}
void T_5 F_544 ( void )
{
unsigned int V_567 ;
V_567 = F_545 ( V_568 . V_569 , V_472 ) ;
V_570 = V_567 + 1 ;
}
unsigned long T_5 F_546 ( void )
{
unsigned long V_571 = 0 , V_516 = 0 ;
unsigned long V_118 , V_119 , V_29 ;
int V_517 = - 1 ;
int V_63 , V_19 ;
F_188 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_118 || V_517 < 0 || V_517 == V_19 ) {
V_517 = V_19 ;
V_516 = V_119 ;
continue;
}
V_29 = ~ ( ( 1 << F_547 ( V_118 ) ) - 1 ) ;
while ( V_29 && V_516 <= ( V_118 & ( V_29 << 1 ) ) )
V_29 <<= 1 ;
V_571 |= V_29 ;
}
return ~ V_571 + 1 ;
}
static unsigned long T_5 F_548 ( int V_19 )
{
unsigned long V_572 = V_17 ;
unsigned long V_47 ;
int V_63 ;
F_188 (i, nid, &start_pfn, NULL, NULL)
V_572 = F_11 ( V_572 , V_47 ) ;
if ( V_572 == V_17 ) {
F_335 ( L_95 , V_19 ) ;
return 0 ;
}
return V_572 ;
}
unsigned long T_5 F_549 ( void )
{
return F_548 ( V_472 ) ;
}
static unsigned long T_5 F_550 ( void )
{
unsigned long V_537 = 0 ;
unsigned long V_47 , V_120 ;
int V_63 , V_19 ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_385 = V_120 - V_47 ;
V_537 += V_385 ;
if ( V_385 )
F_551 ( V_19 , V_149 ) ;
}
return V_537 ;
}
static void T_5 F_552 ( void )
{
int V_63 , V_19 ;
unsigned long V_573 ;
unsigned long V_574 , V_575 ;
T_10 V_576 = V_577 [ V_149 ] ;
unsigned long V_537 = F_550 () ;
int V_578 = F_553 ( V_577 [ V_149 ] ) ;
struct V_500 * V_501 ;
F_513 () ;
if ( F_554 () ) {
F_487 (memory, r) {
if ( ! F_555 ( V_501 ) )
continue;
V_19 = V_501 -> V_19 ;
V_573 = F_157 ( V_501 -> V_579 ) ;
V_527 [ V_19 ] = V_527 [ V_19 ] ?
F_11 ( V_573 , V_527 [ V_19 ] ) :
V_573 ;
}
goto V_580;
}
if ( V_507 ) {
bool V_581 = false ;
F_487 (memory, r) {
if ( F_489 ( V_501 ) )
continue;
V_19 = V_501 -> V_19 ;
V_573 = F_488 ( V_501 ) ;
if ( V_573 < 0x100000 ) {
V_581 = true ;
continue;
}
V_527 [ V_19 ] = V_527 [ V_19 ] ?
F_11 ( V_573 , V_527 [ V_19 ] ) :
V_573 ;
}
if ( V_581 )
F_335 ( L_96 ) ;
goto V_580;
}
if ( V_582 ) {
unsigned long V_583 ;
V_582 =
F_522 ( V_582 , V_151 ) ;
V_582 = F_11 ( V_537 , V_582 ) ;
V_583 = V_537 - V_582 ;
V_584 = F_9 ( V_584 , V_583 ) ;
}
if ( ! V_584 || V_584 >= V_537 )
goto V_56;
V_573 = V_524 [ V_525 ] ;
V_585:
V_574 = V_584 / V_578 ;
F_195 (nid, N_MEMORY) {
unsigned long V_47 , V_120 ;
if ( V_584 < V_574 )
V_574 = V_584 / V_578 ;
V_575 = V_574 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_586 ;
V_47 = F_9 ( V_47 , V_527 [ V_19 ] ) ;
if ( V_47 >= V_120 )
continue;
if ( V_47 < V_573 ) {
unsigned long V_587 ;
V_587 = F_11 ( V_120 , V_573 )
- V_47 ;
V_575 -= F_11 ( V_587 ,
V_575 ) ;
V_584 -= F_11 ( V_587 ,
V_584 ) ;
if ( V_120 <= V_573 ) {
V_527 [ V_19 ] = V_120 ;
continue;
}
V_47 = V_573 ;
}
V_586 = V_120 - V_47 ;
if ( V_586 > V_575 )
V_586 = V_575 ;
V_527 [ V_19 ] = V_47 + V_586 ;
V_584 -= F_11 ( V_584 ,
V_586 ) ;
V_575 -= V_586 ;
if ( ! V_575 )
break;
}
}
V_578 -- ;
if ( V_578 && V_584 > V_578 )
goto V_585;
V_580:
for ( V_19 = 0 ; V_19 < V_472 ; V_19 ++ )
V_527 [ V_19 ] =
F_522 ( V_527 [ V_19 ] , V_151 ) ;
V_56:
V_577 [ V_149 ] = V_576 ;
}
static void F_556 ( T_1 * V_9 , int V_19 )
{
enum V_406 V_406 ;
if ( V_149 == V_588 )
return;
for ( V_406 = 0 ; V_406 <= V_508 - 1 ; V_406 ++ ) {
struct V_43 * V_43 = & V_9 -> V_117 [ V_406 ] ;
if ( F_190 ( V_43 ) ) {
F_551 ( V_19 , V_589 ) ;
if ( V_588 != V_589 &&
V_406 <= V_304 )
F_551 ( V_19 , V_588 ) ;
break;
}
}
}
void T_5 F_557 ( unsigned long * V_216 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_19 ;
memset ( V_524 , 0 ,
sizeof( V_524 ) ) ;
memset ( V_523 , 0 ,
sizeof( V_523 ) ) ;
V_47 = F_549 () ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
if ( V_63 == V_508 )
continue;
V_120 = F_9 ( V_216 [ V_63 ] , V_47 ) ;
V_524 [ V_63 ] = V_47 ;
V_523 [ V_63 ] = V_120 ;
V_47 = V_120 ;
}
memset ( V_527 , 0 , sizeof( V_527 ) ) ;
F_552 () ;
F_73 ( L_97 ) ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
if ( V_63 == V_508 )
continue;
F_73 ( L_98 , V_494 [ V_63 ] ) ;
if ( V_524 [ V_63 ] ==
V_523 [ V_63 ] )
F_336 ( L_99 ) ;
else
F_336 ( L_100 ,
( V_566 ) V_524 [ V_63 ]
<< V_12 ,
( ( V_566 ) V_523 [ V_63 ]
<< V_12 ) - 1 ) ;
}
F_73 ( L_101 ) ;
for ( V_63 = 0 ; V_63 < V_472 ; V_63 ++ ) {
if ( V_527 [ V_63 ] )
F_73 ( L_102 , V_63 ,
( V_566 ) V_527 [ V_63 ] << V_12 ) ;
}
F_73 ( L_103 ) ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_73 ( L_104 , V_19 ,
( V_566 ) V_47 << V_12 ,
( ( V_566 ) V_120 << V_12 ) - 1 ) ;
F_558 () ;
F_544 () ;
F_466 (nid) {
T_1 * V_9 = F_15 ( V_19 ) ;
F_543 ( V_19 , NULL ,
F_548 ( V_19 ) , NULL ) ;
if ( V_9 -> V_539 )
F_551 ( V_19 , V_149 ) ;
F_556 ( V_9 , V_19 ) ;
}
}
static int T_5 F_559 ( char * V_66 , unsigned long * V_590 )
{
unsigned long long V_591 ;
if ( ! V_66 )
return - V_70 ;
V_591 = F_560 ( V_66 , & V_66 ) ;
* V_590 = V_591 >> V_12 ;
F_4 ( ( V_591 >> V_12 ) > V_17 ) ;
return 0 ;
}
static int T_5 F_561 ( char * V_66 )
{
if ( F_562 ( V_66 , L_105 ) ) {
V_507 = true ;
return 0 ;
}
return F_559 ( V_66 , & V_584 ) ;
}
static int T_5 F_563 ( char * V_66 )
{
return F_559 ( V_66 , & V_582 ) ;
}
void F_203 ( struct V_1 * V_1 , long V_105 )
{
F_139 ( & V_592 ) ;
F_21 ( V_1 ) -> V_123 += V_105 ;
V_397 += V_105 ;
#ifdef F_428
if ( F_128 ( V_1 ) )
V_403 += V_105 ;
#endif
F_143 ( & V_592 ) ;
}
unsigned long F_564 ( void * V_118 , void * V_119 , int V_593 , char * V_448 )
{
void * V_479 ;
unsigned long V_385 = 0 ;
V_118 = ( void * ) F_405 ( ( unsigned long ) V_118 ) ;
V_119 = ( void * ) ( ( unsigned long ) V_119 & V_594 ) ;
for ( V_479 = V_118 ; V_479 < V_119 ; V_479 += V_104 , V_385 ++ ) {
if ( ( unsigned int ) V_593 <= 0xFF )
memset ( V_479 , V_593 , V_104 ) ;
F_565 ( F_287 ( V_479 ) ) ;
}
if ( V_385 && V_448 )
F_73 ( L_106 ,
V_448 , V_385 << ( V_12 - 10 ) ) ;
return V_385 ;
}
void F_566 ( struct V_1 * V_1 )
{
F_567 ( V_1 ) ;
V_397 ++ ;
F_21 ( V_1 ) -> V_123 ++ ;
V_403 ++ ;
}
void T_5 F_568 ( const char * V_237 )
{
unsigned long V_595 , V_596 , V_597 , V_598 , V_599 ;
unsigned long V_600 , V_601 ;
V_595 = F_569 () ;
V_596 = V_602 - V_603 ;
V_597 = V_604 - V_605 ;
V_598 = V_606 - V_607 ;
V_599 = V_608 - V_609 ;
V_601 = V_610 - V_611 ;
V_600 = V_612 - V_613 ;
#define F_570 ( V_118 , V_119 , V_155 , V_479 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_570 ( V_611 , V_610 , V_601 ,
V_613 , V_600 ) ;
F_570 ( V_603 , V_602 , V_596 , V_613 , V_600 ) ;
F_570 ( V_605 , V_604 , V_597 , V_611 , V_601 ) ;
F_570 ( V_603 , V_602 , V_596 , V_607 , V_598 ) ;
F_570 ( V_605 , V_604 , V_597 , V_607 , V_598 ) ;
#undef F_570
F_73 ( L_107
#ifdef F_428
L_108
#endif
L_109 ,
F_571 () << ( V_12 - 10 ) ,
V_595 << ( V_12 - 10 ) ,
V_596 >> 10 , V_597 >> 10 , V_598 >> 10 ,
( V_601 + V_600 ) >> 10 , V_599 >> 10 ,
( V_595 - V_397 - V_614 ) << ( V_12 - 10 ) ,
V_614 << ( V_12 - 10 ) ,
#ifdef F_428
V_403 << ( V_12 - 10 ) ,
#endif
V_237 ? L_110 : L_111 , V_237 ? V_237 : L_111 ) ;
}
void T_5 F_572 ( unsigned long V_615 )
{
V_558 = V_615 ;
}
void T_5 F_573 ( unsigned long * V_534 )
{
F_543 ( 0 , V_534 ,
F_574 ( V_616 ) >> V_12 , NULL ) ;
}
static int F_575 ( unsigned int V_204 )
{
F_576 ( V_204 ) ;
F_252 ( V_204 ) ;
F_577 ( V_204 ) ;
F_578 ( V_204 ) ;
return 0 ;
}
void T_5 F_579 ( void )
{
int V_44 ;
V_44 = F_580 ( V_617 ,
L_112 , NULL ,
F_575 ) ;
F_4 ( V_44 < 0 ) ;
}
static void F_581 ( void )
{
struct V_265 * V_9 ;
unsigned long V_618 = 0 ;
enum V_406 V_63 , V_474 ;
F_435 (pgdat) {
V_9 -> V_390 = 0 ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_63 ;
long F_9 = 0 ;
for ( V_474 = V_63 ; V_474 < V_116 ; V_474 ++ ) {
if ( V_43 -> V_259 [ V_474 ] > F_9 )
F_9 = V_43 -> V_259 [ V_474 ] ;
}
F_9 += F_413 ( V_43 ) ;
if ( F_9 > V_43 -> V_123 )
F_9 = V_43 -> V_123 ;
V_9 -> V_390 += F_9 ;
V_618 += F_9 ;
}
}
V_390 = V_618 ;
}
static void F_582 ( void )
{
struct V_265 * V_9 ;
enum V_406 V_474 , V_619 ;
F_435 (pgdat) {
for ( V_474 = 0 ; V_474 < V_116 ; V_474 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_474 ;
unsigned long V_123 = V_43 -> V_123 ;
V_43 -> V_259 [ V_474 ] = 0 ;
V_619 = V_474 ;
while ( V_619 ) {
struct V_43 * V_620 ;
V_619 -- ;
if ( V_621 [ V_619 ] < 1 )
V_621 [ V_619 ] = 1 ;
V_620 = V_9 -> V_117 + V_619 ;
V_620 -> V_259 [ V_474 ] = V_123 /
V_621 [ V_619 ] ;
V_123 += V_620 -> V_123 ;
}
}
}
F_581 () ;
}
static void F_583 ( void )
{
unsigned long V_622 = V_623 >> ( V_12 - 10 ) ;
unsigned long V_624 = 0 ;
struct V_43 * V_43 ;
unsigned long V_37 ;
F_420 (zone) {
if ( ! F_429 ( V_43 ) )
V_624 += V_43 -> V_123 ;
}
F_420 (zone) {
V_566 V_411 ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
V_411 = ( V_566 ) V_622 * V_43 -> V_123 ;
F_584 ( V_411 , V_624 ) ;
if ( F_429 ( V_43 ) ) {
unsigned long V_625 ;
V_625 = V_43 -> V_123 / 1024 ;
V_625 = F_517 ( V_625 , V_626 , 128UL ) ;
V_43 -> V_221 [ V_627 ] = V_625 ;
} else {
V_43 -> V_221 [ V_627 ] = V_411 ;
}
V_411 = F_585 ( V_566 , V_411 >> 2 ,
F_586 ( V_43 -> V_123 ,
V_628 , 10000 ) ) ;
V_43 -> V_221 [ V_389 ] = F_290 ( V_43 ) + V_411 ;
V_43 -> V_221 [ V_629 ] = F_290 ( V_43 ) + V_411 * 2 ;
F_238 ( & V_43 -> V_110 , V_37 ) ;
}
F_581 () ;
}
void F_587 ( void )
{
F_261 ( & V_464 ) ;
F_583 () ;
F_269 ( & V_464 ) ;
}
int T_2 F_588 ( void )
{
unsigned long V_630 ;
int V_631 ;
V_630 = F_414 () * ( V_104 >> 10 ) ;
V_631 = F_589 ( V_630 * 16 ) ;
if ( V_631 > V_632 ) {
V_623 = V_631 ;
if ( V_623 < 128 )
V_623 = 128 ;
if ( V_623 > 65536 )
V_623 = 65536 ;
} else {
F_335 ( L_113 ,
V_631 , V_632 ) ;
}
F_587 () ;
F_590 () ;
F_582 () ;
#ifdef F_293
F_591 () ;
F_592 () ;
#endif
return 0 ;
}
int F_593 ( struct V_455 * V_456 , int V_457 ,
void T_13 * V_458 , T_12 * V_459 , T_14 * V_460 )
{
int V_633 ;
V_633 = F_594 ( V_456 , V_457 , V_458 , V_459 , V_460 ) ;
if ( V_633 )
return V_633 ;
if ( V_457 ) {
V_632 = V_623 ;
F_587 () ;
}
return 0 ;
}
int F_595 ( struct V_455 * V_456 , int V_457 ,
void T_13 * V_458 , T_12 * V_459 , T_14 * V_460 )
{
int V_633 ;
V_633 = F_594 ( V_456 , V_457 , V_458 , V_459 , V_460 ) ;
if ( V_633 )
return V_633 ;
if ( V_457 )
F_587 () ;
return 0 ;
}
static void F_591 ( void )
{
T_1 * V_9 ;
struct V_43 * V_43 ;
F_435 (pgdat)
V_9 -> V_634 = 0 ;
F_420 (zone)
V_43 -> V_269 -> V_634 += ( V_43 -> V_123 *
V_635 ) / 100 ;
}
int F_596 ( struct V_455 * V_456 , int V_457 ,
void T_13 * V_458 , T_12 * V_459 , T_14 * V_460 )
{
int V_633 ;
V_633 = F_594 ( V_456 , V_457 , V_458 , V_459 , V_460 ) ;
if ( V_633 )
return V_633 ;
F_591 () ;
return 0 ;
}
static void F_592 ( void )
{
T_1 * V_9 ;
struct V_43 * V_43 ;
F_435 (pgdat)
V_9 -> V_636 = 0 ;
F_420 (zone)
V_43 -> V_269 -> V_636 += ( V_43 -> V_123 *
V_637 ) / 100 ;
}
int F_597 ( struct V_455 * V_456 , int V_457 ,
void T_13 * V_458 , T_12 * V_459 , T_14 * V_460 )
{
int V_633 ;
V_633 = F_594 ( V_456 , V_457 , V_458 , V_459 , V_460 ) ;
if ( V_633 )
return V_633 ;
F_592 () ;
return 0 ;
}
int F_598 ( struct V_455 * V_456 , int V_457 ,
void T_13 * V_458 , T_12 * V_459 , T_14 * V_460 )
{
F_594 ( V_456 , V_457 , V_458 , V_459 , V_460 ) ;
F_582 () ;
return 0 ;
}
int F_599 ( struct V_455 * V_456 , int V_457 ,
void T_13 * V_458 , T_12 * V_459 , T_14 * V_460 )
{
struct V_43 * V_43 ;
int V_638 ;
int V_44 ;
F_261 ( & V_639 ) ;
V_638 = V_509 ;
V_44 = F_594 ( V_456 , V_457 , V_458 , V_459 , V_460 ) ;
if ( ! V_457 || V_44 < 0 )
goto V_56;
if ( V_509 &&
V_509 < V_640 ) {
V_509 = V_638 ;
V_44 = - V_70 ;
goto V_56;
}
if ( V_509 == V_638 )
goto V_56;
F_201 (zone) {
unsigned int V_204 ;
F_467 (cpu)
F_499 ( V_43 ,
F_251 ( V_43 -> V_207 , V_204 ) ) ;
}
V_56:
F_269 ( & V_639 ) ;
return V_44 ;
}
static int T_5 F_600 ( char * V_237 )
{
if ( ! V_237 )
return 0 ;
V_641 = F_601 ( V_237 , & V_237 , 0 ) ;
return 1 ;
}
static unsigned long T_5 F_602 ( void )
{
return 0 ;
}
void * T_5 F_603 ( const char * V_642 ,
unsigned long V_643 ,
unsigned long V_644 ,
int V_645 ,
int V_37 ,
unsigned int * V_646 ,
unsigned int * V_647 ,
unsigned long V_648 ,
unsigned long V_649 )
{
unsigned long long F_9 = V_649 ;
unsigned long V_650 , V_155 ;
void * V_456 = NULL ;
T_7 V_158 ;
if ( ! V_644 ) {
V_644 = V_559 ;
V_644 -= F_602 () ;
if ( V_12 < 20 )
V_644 = F_604 ( V_644 , ( 1 << 20 ) / V_104 ) ;
#if V_651 > 32
if ( ! V_649 ) {
unsigned long V_652 ;
for ( V_652 = V_653 ; V_652 < V_644 ;
V_652 <<= V_654 )
V_645 ++ ;
}
#endif
if ( V_645 > V_12 )
V_644 >>= ( V_645 - V_12 ) ;
else
V_644 <<= ( V_12 - V_645 ) ;
if ( F_34 ( V_37 & V_655 ) ) {
F_4 ( ! ( V_37 & V_656 ) ) ;
if ( ! ( V_644 >> * V_646 ) ) {
V_644 = 1UL << * V_646 ;
F_187 ( ! V_644 ) ;
}
} else if ( F_34 ( ( V_644 * V_643 ) < V_104 ) )
V_644 = V_104 / V_643 ;
}
V_644 = F_605 ( V_644 ) ;
if ( F_9 == 0 ) {
F_9 = ( ( unsigned long long ) V_560 << V_12 ) >> 4 ;
F_584 ( F_9 , V_643 ) ;
}
F_9 = F_11 ( F_9 , 0x80000000ULL ) ;
if ( V_644 < V_648 )
V_644 = V_648 ;
if ( V_644 > F_9 )
V_644 = F_9 ;
V_650 = F_606 ( V_644 ) ;
V_158 = ( V_37 & V_657 ) ? V_658 | V_160 : V_658 ;
do {
V_155 = V_643 << V_650 ;
if ( V_37 & V_656 )
V_456 = F_607 ( V_155 , 0 ) ;
else if ( V_641 )
V_456 = F_608 ( V_155 , V_158 , V_659 ) ;
else {
if ( F_408 ( V_155 ) < V_74 ) {
V_456 = F_407 ( V_155 , V_158 ) ;
F_609 ( V_456 , V_155 , 1 , V_158 ) ;
}
}
} while ( ! V_456 && V_155 > V_104 && -- V_650 );
if ( ! V_456 )
F_610 ( L_114 , V_642 ) ;
F_73 ( L_115 ,
V_642 , 1UL << V_650 , F_606 ( V_155 ) - V_12 , V_155 ) ;
if ( V_646 )
* V_646 = V_650 ;
if ( V_647 )
* V_647 = ( 1 << V_650 ) - 1 ;
return V_456 ;
}
bool F_611 ( struct V_43 * V_43 , struct V_1 * V_1 , int V_105 ,
bool V_660 )
{
unsigned long V_18 , V_661 , V_662 ;
int V_114 ;
if ( V_445 ( V_43 ) == V_508 )
return false ;
V_114 = F_102 ( V_1 ) ;
if ( V_114 == V_135 || F_237 ( V_114 ) )
return false ;
V_18 = F_37 ( V_1 ) ;
for ( V_662 = 0 , V_661 = 0 ; V_661 < V_27 ; V_661 ++ ) {
unsigned long V_663 = V_18 + V_661 ;
if ( ! F_43 ( V_663 ) )
continue;
V_1 = F_153 ( V_663 ) ;
if ( F_612 ( V_1 ) ) {
V_661 = F_604 ( V_661 + 1 , 1 << F_56 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_107 ( V_1 ) ) {
if ( F_93 ( V_1 ) )
V_661 += ( 1 << F_90 ( V_1 ) ) - 1 ;
continue;
}
if ( V_660 && F_613 ( V_1 ) )
continue;
if ( F_227 ( V_1 ) )
continue;
if ( ! F_226 ( V_1 ) )
V_662 ++ ;
if ( V_662 > V_105 )
return true ;
}
return false ;
}
bool F_614 ( struct V_1 * V_1 )
{
struct V_43 * V_43 ;
unsigned long V_18 ;
if ( ! F_14 ( F_225 ( V_1 ) ) )
return false ;
V_43 = F_21 ( V_1 ) ;
V_18 = F_37 ( V_1 ) ;
if ( ! F_30 ( V_43 , V_18 ) )
return false ;
return ! F_611 ( V_43 , V_1 , 0 , true ) ;
}
static unsigned long F_615 ( unsigned long V_18 )
{
return V_18 & ~ ( F_585 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_616 ( unsigned long V_18 )
{
return F_177 ( V_18 , F_585 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_617 ( struct V_664 * V_665 ,
unsigned long V_118 , unsigned long V_119 )
{
unsigned long V_666 ;
unsigned long V_18 = V_118 ;
unsigned int V_667 = 0 ;
int V_44 = 0 ;
F_618 () ;
while ( V_18 < V_119 || ! F_140 ( & V_665 -> V_668 ) ) {
if ( F_619 ( V_58 ) ) {
V_44 = - V_669 ;
break;
}
if ( F_140 ( & V_665 -> V_668 ) ) {
V_665 -> V_670 = 0 ;
V_18 = F_620 ( V_665 , V_18 , V_119 ) ;
if ( ! V_18 ) {
V_44 = - V_669 ;
break;
}
V_667 = 0 ;
} else if ( ++ V_667 == 5 ) {
V_44 = V_44 < 0 ? V_44 : - V_671 ;
break;
}
V_666 = F_621 ( V_665 -> V_43 ,
& V_665 -> V_668 ) ;
V_665 -> V_670 -= V_666 ;
V_44 = F_622 ( & V_665 -> V_668 , V_672 ,
NULL , 0 , V_665 -> V_246 , V_673 ) ;
}
if ( V_44 < 0 ) {
F_623 ( & V_665 -> V_668 ) ;
return V_44 ;
}
return 0 ;
}
int F_624 ( unsigned long V_118 , unsigned long V_119 ,
unsigned V_3 , T_7 V_240 )
{
unsigned long V_674 , V_675 ;
unsigned int V_62 ;
int V_44 = 0 ;
struct V_664 V_665 = {
. V_670 = 0 ,
. V_62 = - 1 ,
. V_43 = F_21 ( F_153 ( V_118 ) ) ,
. V_246 = V_676 ,
. V_677 = true ,
. V_240 = F_386 ( V_240 ) ,
} ;
F_78 ( & V_665 . V_668 ) ;
V_44 = F_625 ( F_615 ( V_118 ) ,
F_616 ( V_119 ) , V_3 ,
false ) ;
if ( V_44 )
return V_44 ;
V_44 = F_617 ( & V_665 , V_118 , V_119 ) ;
if ( V_44 && V_44 != - V_671 )
goto V_678;
F_626 () ;
F_258 ( V_665 . V_43 ) ;
V_62 = 0 ;
V_674 = V_118 ;
while ( ! F_93 ( F_153 ( V_674 ) ) ) {
if ( ++ V_62 >= V_74 ) {
V_674 = V_118 ;
break;
}
V_674 &= ~ 0UL << V_62 ;
}
if ( V_674 != V_118 ) {
V_62 = F_90 ( F_153 ( V_674 ) ) ;
if ( V_674 + ( 1UL << V_62 ) <= V_118 )
V_674 = V_118 ;
}
if ( F_627 ( V_674 , V_119 , false ) ) {
F_628 ( L_116 ,
V_679 , V_674 , V_119 ) ;
V_44 = - V_671 ;
goto V_678;
}
V_675 = F_629 ( & V_665 , V_674 , V_119 ) ;
if ( ! V_675 ) {
V_44 = - V_671 ;
goto V_678;
}
if ( V_118 != V_674 )
F_630 ( V_674 , V_118 - V_674 ) ;
if ( V_119 != V_675 )
F_630 ( V_119 , V_675 - V_119 ) ;
V_678:
F_631 ( F_615 ( V_118 ) ,
F_616 ( V_119 ) , V_3 ) ;
return V_44 ;
}
void F_630 ( unsigned long V_18 , unsigned V_64 )
{
unsigned int V_105 = 0 ;
for (; V_64 -- ; V_18 ++ ) {
struct V_1 * V_1 = F_153 ( V_18 ) ;
V_105 += F_92 ( V_1 ) != 1 ;
F_632 ( V_1 ) ;
}
F_633 ( V_105 != 0 , L_117 , V_105 ) ;
}
void T_2 F_634 ( struct V_43 * V_43 )
{
unsigned V_204 ;
F_261 ( & V_639 ) ;
F_467 (cpu)
F_499 ( V_43 ,
F_251 ( V_43 -> V_207 , V_204 ) ) ;
F_269 ( & V_639 ) ;
}
void F_635 ( struct V_43 * V_43 )
{
unsigned long V_37 ;
int V_204 ;
struct V_205 * V_206 ;
F_161 ( V_37 ) ;
if ( V_43 -> V_207 != & V_489 ) {
F_262 (cpu) {
V_206 = F_251 ( V_43 -> V_207 , V_204 ) ;
F_636 ( V_43 , V_206 ) ;
}
F_637 ( V_43 -> V_207 ) ;
V_43 -> V_207 = & V_489 ;
}
F_163 ( V_37 ) ;
}
void
F_638 ( unsigned long V_47 , unsigned long V_120 )
{
struct V_1 * V_1 ;
struct V_43 * V_43 ;
unsigned int V_62 , V_63 ;
unsigned long V_18 ;
unsigned long V_37 ;
for ( V_18 = V_47 ; V_18 < V_120 ; V_18 ++ )
if ( F_159 ( V_18 ) )
break;
if ( V_18 == V_120 )
return;
F_639 ( V_18 , V_120 ) ;
V_43 = F_21 ( F_153 ( V_18 ) ) ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
V_18 = V_47 ;
while ( V_18 < V_120 ) {
if ( ! F_159 ( V_18 ) ) {
V_18 ++ ;
continue;
}
V_1 = F_153 ( V_18 ) ;
if ( F_34 ( ! F_93 ( V_1 ) && F_613 ( V_1 ) ) ) {
V_18 ++ ;
F_160 ( V_1 ) ;
continue;
}
F_187 ( F_92 ( V_1 ) ) ;
F_187 ( ! F_93 ( V_1 ) ) ;
V_62 = F_90 ( V_1 ) ;
#ifdef V_100
F_73 ( L_118 ,
V_18 , 1 << V_62 , V_120 ) ;
#endif
F_100 ( & V_1 -> V_78 ) ;
F_86 ( V_1 ) ;
V_43 -> V_87 [ V_62 ] . V_88 -- ;
for ( V_63 = 0 ; V_63 < ( 1 << V_62 ) ; V_63 ++ )
F_160 ( ( V_1 + V_63 ) ) ;
V_18 += ( 1 << V_62 ) ;
}
F_238 ( & V_43 -> V_110 , V_37 ) ;
}
bool F_640 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = F_21 ( V_1 ) ;
unsigned long V_18 = F_37 ( V_1 ) ;
unsigned long V_37 ;
unsigned int V_62 ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_1 * V_680 = V_1 - ( V_18 & ( ( 1 << V_62 ) - 1 ) ) ;
if ( F_93 ( V_680 ) && F_90 ( V_680 ) >= V_62 )
break;
}
F_238 ( & V_43 -> V_110 , V_37 ) ;
return V_62 < V_74 ;
}
