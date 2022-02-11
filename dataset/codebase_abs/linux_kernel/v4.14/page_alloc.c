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
static void T_2 F_154 ( unsigned long V_18 )
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
const bool V_257 = ( V_159 & ( V_235 | V_258 ) ) ;
V_173 -= ( 1 << V_62 ) - 1 ;
if ( V_159 & V_259 )
F_11 -= F_11 / 2 ;
if ( F_98 ( ! V_257 ) ) {
V_173 -= V_193 -> V_185 ;
} else {
if ( V_159 & V_258 )
F_11 -= F_11 / 2 ;
else
F_11 -= F_11 / 4 ;
}
#ifdef F_313
if ( ! ( V_159 & V_222 ) )
V_173 -= F_314 ( V_193 , V_200 ) ;
#endif
if ( V_173 <= F_11 + V_193 -> V_260 [ V_255 ] )
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
long V_261 = 0 ;
#ifdef F_313
if ( ! ( V_159 & V_222 ) )
V_261 = F_314 ( V_193 , V_200 ) ;
#endif
if ( ! V_62 && ( V_173 - V_261 ) > V_254 + V_193 -> V_260 [ V_255 ] )
return true ;
return F_312 ( V_193 , V_62 , V_254 , V_255 , V_159 ,
V_173 ) ;
}
bool F_316 ( struct V_43 * V_193 , unsigned int V_62 ,
unsigned long V_254 , int V_255 )
{
long V_173 = F_314 ( V_193 , V_201 ) ;
if ( V_193 -> V_262 && V_173 < V_193 -> V_262 )
V_173 = F_317 ( V_193 , V_201 ) ;
return F_312 ( V_193 , V_62 , V_254 , V_255 , 0 ,
V_173 ) ;
}
static bool F_318 ( struct V_43 * V_263 , struct V_43 * V_43 )
{
return F_319 ( F_41 ( V_263 ) , F_41 ( V_43 ) ) <=
V_264 ;
}
static bool F_318 ( struct V_43 * V_263 , struct V_43 * V_43 )
{
return true ;
}
static struct V_1 *
F_320 ( T_7 V_240 , unsigned int V_62 , int V_159 ,
const struct V_188 * V_189 )
{
struct V_192 * V_193 = V_189 -> V_265 ;
struct V_43 * V_43 ;
struct V_266 * V_267 = NULL ;
F_321 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct V_1 * V_1 ;
unsigned long V_254 ;
if ( F_322 () &&
( V_159 & V_268 ) &&
! F_323 ( V_43 , V_240 ) )
continue;
if ( V_189 -> V_269 ) {
if ( V_267 == V_43 -> V_270 )
continue;
if ( ! F_324 ( V_43 -> V_270 ) ) {
V_267 = V_43 -> V_270 ;
continue;
}
}
V_254 = V_43 -> V_221 [ V_159 & V_271 ] ;
if ( ! F_315 ( V_43 , V_62 , V_254 ,
F_325 ( V_189 ) , V_159 ) ) {
int V_44 ;
F_28 ( V_162 < V_272 ) ;
if ( V_159 & V_162 )
goto V_273;
if ( V_274 == 0 ||
! F_318 ( V_189 -> V_265 -> V_43 , V_43 ) )
continue;
V_44 = F_326 ( V_43 -> V_270 , V_240 , V_62 ) ;
switch ( V_44 ) {
case V_275 :
continue;
case V_276 :
continue;
default:
if ( F_291 ( V_43 , V_62 , V_254 ,
F_325 ( V_189 ) , V_159 ) )
goto V_273;
continue;
}
}
V_273:
V_1 = F_300 ( V_189 -> V_265 -> V_43 , V_43 , V_62 ,
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
#if V_277 > 8
V_44 = F_328 () ;
#endif
return V_44 ;
}
static void F_329 ( T_7 V_240 , T_10 * V_278 )
{
unsigned int V_279 = V_280 ;
static F_330 ( V_281 , V_57 , 1 ) ;
if ( F_327 () || ! F_331 ( & V_281 ) )
return;
if ( ! ( V_240 & V_282 ) )
if ( F_332 ( V_58 ) ||
( V_58 -> V_37 & ( V_283 | V_284 ) ) )
V_279 &= ~ V_280 ;
if ( F_328 () || ! ( V_240 & V_245 ) )
V_279 &= ~ V_280 ;
F_333 ( V_279 , V_278 ) ;
}
void F_334 ( T_7 V_240 , T_10 * V_278 , const char * V_285 , ... )
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
if ( V_278 )
F_336 ( L_28 , F_337 ( V_278 ) ) ;
else
F_336 ( L_29 ) ;
F_338 () ;
F_51 () ;
F_329 ( V_240 , V_278 ) ;
}
static inline struct V_1 *
F_339 ( T_7 V_240 , unsigned int V_62 ,
unsigned int V_159 ,
const struct V_188 * V_189 )
{
struct V_1 * V_1 ;
V_1 = F_320 ( V_240 , V_62 ,
V_159 | V_268 , V_189 ) ;
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
. V_278 = V_189 -> V_278 ,
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
V_299 | V_268 , V_189 ) ;
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
static bool F_355 ( T_7 V_240 )
{
V_240 = F_356 ( V_240 ) ;
if ( ! ( V_240 & V_245 ) )
return false ;
if ( ( V_58 -> V_37 & V_283 ) && ! ( V_240 & V_282 ) )
return false ;
if ( ! ( V_240 & V_8 ) )
return false ;
if ( V_240 & V_325 )
return false ;
return true ;
}
void F_357 ( T_7 V_240 )
{
if ( F_355 ( V_240 ) )
F_358 ( & V_326 ) ;
}
void F_359 ( T_7 V_240 )
{
if ( F_355 ( V_240 ) )
F_360 ( & V_326 ) ;
}
static int
F_361 ( T_7 V_240 , unsigned int V_62 ,
const struct V_188 * V_189 )
{
struct V_327 V_327 ;
int V_328 ;
unsigned int V_309 ;
F_189 () ;
F_362 () ;
V_309 = F_344 () ;
F_357 ( V_240 ) ;
V_327 . V_329 = 0 ;
V_58 -> V_327 = & V_327 ;
V_328 = F_363 ( V_189 -> V_191 , V_62 , V_240 ,
V_189 -> V_278 ) ;
V_58 -> V_327 = NULL ;
F_359 ( V_240 ) ;
F_346 ( V_309 ) ;
F_189 () ;
return V_328 ;
}
static inline struct V_1 *
F_364 ( T_7 V_240 , unsigned int V_62 ,
unsigned int V_159 , const struct V_188 * V_189 ,
unsigned long * V_293 )
{
struct V_1 * V_1 = NULL ;
bool V_330 = false ;
* V_293 = F_361 ( V_240 , V_62 , V_189 ) ;
if ( F_34 ( ! ( * V_293 ) ) )
return NULL ;
V_197:
V_1 = F_320 ( V_240 , V_62 , V_159 , V_189 ) ;
if ( ! V_1 && ! V_330 ) {
F_239 ( V_189 , false ) ;
F_258 ( NULL ) ;
V_330 = true ;
goto V_197;
}
return V_1 ;
}
static void F_365 ( unsigned int V_62 , const struct V_188 * V_189 )
{
struct V_192 * V_193 ;
struct V_43 * V_43 ;
T_1 * V_331 = NULL ;
F_240 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask) {
if ( V_331 != V_43 -> V_270 )
F_366 ( V_43 , V_62 , V_189 -> V_303 ) ;
V_331 = V_43 -> V_270 ;
}
}
static inline unsigned int
F_367 ( T_7 V_240 )
{
unsigned int V_159 = V_332 | V_268 ;
F_28 ( V_333 != ( V_334 T_7 ) V_259 ) ;
V_159 |= ( V_334 int ) ( V_240 & V_333 ) ;
if ( V_240 & V_335 ) {
if ( ! ( V_240 & V_282 ) )
V_159 |= V_235 ;
V_159 &= ~ V_268 ;
} else if ( F_34 ( F_368 ( V_58 ) ) && ! F_328 () )
V_159 |= V_235 ;
#ifdef F_313
if ( F_369 ( V_240 ) == V_135 )
V_159 |= V_222 ;
#endif
return V_159 ;
}
static bool F_370 ( struct V_336 * V_337 )
{
if ( ! F_332 ( V_337 ) )
return false ;
if ( ! F_112 ( V_338 ) && ! F_371 ( V_339 ) )
return false ;
return true ;
}
static inline int F_372 ( T_7 V_240 )
{
if ( F_34 ( V_240 & V_282 ) )
return 0 ;
if ( V_240 & V_340 )
return V_162 ;
if ( F_373 () && ( V_58 -> V_37 & V_283 ) )
return V_162 ;
if ( ! F_328 () ) {
if ( V_58 -> V_37 & V_283 )
return V_162 ;
else if ( F_370 ( V_58 ) )
return V_258 ;
}
return 0 ;
}
bool F_374 ( T_7 V_240 )
{
return ! ! F_372 ( V_240 ) ;
}
static inline bool
F_375 ( T_7 V_240 , unsigned V_62 ,
struct V_188 * V_189 , int V_159 ,
bool V_293 , int * V_341 )
{
struct V_43 * V_43 ;
struct V_192 * V_193 ;
if ( V_293 && V_62 <= V_301 )
* V_341 = 0 ;
else
( * V_341 ) ++ ;
if ( * V_341 > V_342 ) {
return F_239 ( V_189 , true ) ;
}
F_240 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_343 ;
unsigned long V_344 ;
unsigned long V_345 = F_290 ( V_43 ) ;
bool V_346 ;
V_343 = V_344 = F_376 ( V_43 ) ;
V_343 += F_317 ( V_43 , V_201 ) ;
V_346 = F_312 ( V_43 , V_62 , V_345 ,
F_325 ( V_189 ) , V_159 , V_343 ) ;
F_377 ( V_193 , V_62 , V_344 ,
V_343 , V_345 , * V_341 , V_346 ) ;
if ( V_346 ) {
if ( ! V_293 ) {
unsigned long V_347 ;
V_347 = F_317 ( V_43 ,
V_348 ) ;
if ( 2 * V_347 > V_344 ) {
F_378 ( V_349 , V_57 / 10 ) ;
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
F_379 ( int V_350 , struct V_188 * V_189 )
{
if ( F_322 () && V_189 -> V_278 &&
! F_380 ( V_189 -> V_278 ) ) {
V_189 -> V_278 = NULL ;
return true ;
}
if ( F_381 ( V_350 ) )
return true ;
return false ;
}
static inline struct V_1 *
F_382 ( T_7 V_240 , unsigned int V_62 ,
struct V_188 * V_189 )
{
bool V_351 = V_240 & V_245 ;
const bool V_352 = V_62 > V_301 ;
struct V_1 * V_1 = NULL ;
unsigned int V_159 ;
unsigned long V_293 ;
enum V_306 V_306 ;
enum V_308 V_308 ;
int V_315 ;
int V_341 ;
unsigned long V_353 = V_55 ;
unsigned int V_354 = 10 * V_57 ;
unsigned int V_350 ;
int V_355 ;
if ( V_62 >= V_74 ) {
F_259 ( ! ( V_240 & V_291 ) ) ;
return NULL ;
}
if ( F_259 ( ( V_240 & ( V_335 | V_245 ) ) ==
( V_335 | V_245 ) ) )
V_240 &= ~ V_335 ;
V_356:
V_315 = 0 ;
V_341 = 0 ;
V_306 = V_357 ;
V_350 = F_383 () ;
V_159 = F_367 ( V_240 ) ;
V_189 -> V_265 = F_384 ( V_189 -> V_191 ,
V_189 -> V_303 , V_189 -> V_278 ) ;
if ( ! V_189 -> V_265 -> V_43 )
goto V_358;
if ( V_240 & V_359 )
F_365 ( V_62 , V_189 ) ;
V_1 = F_320 ( V_240 , V_62 , V_159 , V_189 ) ;
if ( V_1 )
goto V_360;
if ( V_351 &&
( V_352 ||
( V_62 > 0 && V_189 -> V_3 != V_135 ) )
&& ! F_374 ( V_240 ) ) {
V_1 = F_343 ( V_240 , V_62 ,
V_159 , V_189 ,
V_361 ,
& V_308 ) ;
if ( V_1 )
goto V_360;
if ( V_352 && ( V_240 & V_362 ) ) {
if ( V_308 == V_363 )
goto V_358;
V_306 = V_361 ;
}
}
V_197:
if ( V_240 & V_359 )
F_365 ( V_62 , V_189 ) ;
V_355 = F_372 ( V_240 ) ;
if ( V_355 )
V_159 = V_355 ;
if ( ! ( V_159 & V_268 ) || V_355 ) {
V_189 -> V_191 = F_385 ( F_294 () , V_240 ) ;
V_189 -> V_265 = F_384 ( V_189 -> V_191 ,
V_189 -> V_303 , V_189 -> V_278 ) ;
}
V_1 = F_320 ( V_240 , V_62 , V_159 , V_189 ) ;
if ( V_1 )
goto V_360;
if ( ! V_351 )
goto V_358;
if ( F_386 ( V_55 , V_353 + V_354 ) ) {
F_334 ( V_240 & ~ V_291 , V_189 -> V_278 ,
L_30 ,
F_191 ( V_55 - V_353 ) , V_62 ) ;
V_354 += 10 * V_57 ;
}
if ( V_58 -> V_37 & V_283 )
goto V_358;
V_1 = F_364 ( V_240 , V_62 , V_159 , V_189 ,
& V_293 ) ;
if ( V_1 )
goto V_360;
V_1 = F_343 ( V_240 , V_62 , V_159 , V_189 ,
V_306 , & V_308 ) ;
if ( V_1 )
goto V_360;
if ( V_240 & V_362 )
goto V_358;
if ( V_352 && ! ( V_240 & V_302 ) )
goto V_358;
if ( F_375 ( V_240 , V_62 , V_189 , V_159 ,
V_293 > 0 , & V_341 ) )
goto V_197;
if ( V_293 > 0 &&
F_349 ( V_189 , V_62 , V_159 ,
V_308 , & V_306 ,
& V_315 ) )
goto V_197;
if ( F_379 ( V_350 , V_189 ) )
goto V_356;
V_1 = F_340 ( V_240 , V_62 , V_189 , & V_293 ) ;
if ( V_1 )
goto V_360;
if ( F_332 ( V_58 ) &&
( V_159 == V_258 ||
( V_240 & V_282 ) ) )
goto V_358;
if ( V_293 ) {
V_341 = 0 ;
goto V_197;
}
V_358:
if ( F_379 ( V_350 , V_189 ) )
goto V_356;
if ( V_240 & V_234 ) {
if ( F_259 ( ! V_351 ) )
goto V_252;
F_259 ( V_58 -> V_37 & V_283 ) ;
F_259 ( V_62 > V_301 ) ;
V_1 = F_339 ( V_240 , V_62 , V_235 , V_189 ) ;
if ( V_1 )
goto V_360;
F_189 () ;
goto V_197;
}
V_252:
F_334 ( V_240 , V_189 -> V_278 ,
L_31 , V_62 ) ;
V_360:
return V_1 ;
}
static inline bool F_387 ( T_7 V_240 , unsigned int V_62 ,
int V_364 , T_10 * V_278 ,
struct V_188 * V_189 , T_7 * V_365 ,
unsigned int * V_159 )
{
V_189 -> V_303 = F_388 ( V_240 ) ;
V_189 -> V_191 = F_385 ( V_364 , V_240 ) ;
V_189 -> V_278 = V_278 ;
V_189 -> V_3 = F_369 ( V_240 ) ;
if ( F_322 () ) {
* V_365 |= V_298 ;
if ( ! V_189 -> V_278 )
V_189 -> V_278 = & V_366 ;
else
* V_159 |= V_268 ;
}
F_357 ( V_240 ) ;
F_359 ( V_240 ) ;
F_389 ( V_240 & V_245 ) ;
if ( F_303 ( V_240 , V_62 ) )
return false ;
if ( F_112 ( F_313 ) && V_189 -> V_3 == V_135 )
* V_159 |= V_222 ;
return true ;
}
static inline void F_390 ( T_7 V_240 ,
unsigned int V_62 , struct V_188 * V_189 )
{
V_189 -> V_269 = ( V_240 & V_367 ) ;
V_189 -> V_265 = F_384 ( V_189 -> V_191 ,
V_189 -> V_303 , V_189 -> V_278 ) ;
}
struct V_1 *
F_391 ( T_7 V_240 , unsigned int V_62 , int V_364 ,
T_10 * V_278 )
{
struct V_1 * V_1 ;
unsigned int V_159 = V_368 ;
T_7 V_365 ;
struct V_188 V_189 = { } ;
V_240 &= V_6 ;
V_365 = V_240 ;
if ( ! F_387 ( V_240 , V_62 , V_364 , V_278 , & V_189 , & V_365 , & V_159 ) )
return NULL ;
F_390 ( V_240 , V_62 , & V_189 ) ;
V_1 = F_320 ( V_365 , V_62 , V_159 , & V_189 ) ;
if ( F_98 ( V_1 ) )
goto V_56;
V_365 = F_356 ( V_240 ) ;
V_189 . V_269 = false ;
if ( F_34 ( V_189 . V_278 != V_278 ) )
V_189 . V_278 = V_278 ;
V_1 = F_382 ( V_365 , V_62 , & V_189 ) ;
V_56:
if ( F_123 () && ( V_240 & V_369 ) && V_1 &&
F_34 ( F_392 ( V_1 , V_240 , V_62 ) != 0 ) ) {
F_168 ( V_1 , V_62 ) ;
V_1 = NULL ;
}
if ( V_370 && V_1 )
F_393 ( V_1 , V_62 , V_240 ) ;
F_394 ( V_1 , V_62 , V_365 , V_189 . V_3 ) ;
return V_1 ;
}
unsigned long F_395 ( T_7 V_240 , unsigned int V_62 )
{
struct V_1 * V_1 ;
F_96 ( ( V_240 & V_243 ) != 0 ) ;
V_1 = F_396 ( V_240 , V_62 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_130 ( V_1 ) ;
}
unsigned long F_397 ( T_7 V_240 )
{
return F_395 ( V_240 | V_160 , 0 ) ;
}
void F_168 ( struct V_1 * V_1 , unsigned int V_62 )
{
if ( F_398 ( V_1 ) ) {
if ( V_62 == 0 )
F_278 ( V_1 , false ) ;
else
F_55 ( V_1 , V_62 ) ;
}
}
void V_173 ( unsigned long V_371 , unsigned int V_62 )
{
if ( V_371 != 0 ) {
F_96 ( ! F_399 ( ( void * ) V_371 ) ) ;
F_168 ( F_287 ( ( void * ) V_371 ) , V_62 ) ;
}
}
static struct V_1 * F_400 ( struct V_372 * V_373 ,
T_7 V_240 )
{
struct V_1 * V_1 = NULL ;
T_7 V_374 = V_240 ;
#if ( V_104 < V_375 )
V_240 |= V_161 | V_291 | V_362 |
V_282 ;
V_1 = F_401 ( V_376 , V_240 ,
V_377 ) ;
V_373 -> V_155 = V_1 ? V_375 : V_104 ;
#endif
if ( F_34 ( ! V_1 ) )
V_1 = F_401 ( V_376 , V_374 , 0 ) ;
V_373 -> V_292 = V_1 ? F_130 ( V_1 ) : NULL ;
return V_1 ;
}
void F_402 ( struct V_1 * V_1 , unsigned int V_105 )
{
F_29 ( F_107 ( V_1 ) == 0 , V_1 ) ;
if ( F_403 ( V_1 , V_105 ) ) {
unsigned int V_62 = F_56 ( V_1 ) ;
if ( V_62 == 0 )
F_278 ( V_1 , false ) ;
else
F_55 ( V_1 , V_62 ) ;
}
}
void * F_404 ( struct V_372 * V_373 ,
unsigned int V_378 , T_7 V_240 )
{
unsigned int V_155 = V_104 ;
struct V_1 * V_1 ;
int V_379 ;
if ( F_34 ( ! V_373 -> V_292 ) ) {
V_380:
V_1 = F_400 ( V_373 , V_240 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_104 < V_375 )
V_155 = V_373 -> V_155 ;
#endif
F_405 ( V_1 , V_155 - 1 ) ;
V_373 -> V_381 = F_406 ( V_1 ) ;
V_373 -> V_382 = V_155 ;
V_373 -> V_379 = V_155 ;
}
V_379 = V_373 -> V_379 - V_378 ;
if ( F_34 ( V_379 < 0 ) ) {
V_1 = F_287 ( V_373 -> V_292 ) ;
if ( ! F_403 ( V_1 , V_373 -> V_382 ) )
goto V_380;
#if ( V_104 < V_375 )
V_155 = V_373 -> V_155 ;
#endif
F_61 ( V_1 , V_155 ) ;
V_373 -> V_382 = V_155 ;
V_379 = V_155 - V_378 ;
}
V_373 -> V_382 -- ;
V_373 -> V_379 = V_379 ;
return V_373 -> V_292 + V_379 ;
}
void F_407 ( void * V_371 )
{
struct V_1 * V_1 = F_408 ( V_371 ) ;
if ( F_34 ( F_398 ( V_1 ) ) )
F_55 ( V_1 , F_56 ( V_1 ) ) ;
}
static void * F_409 ( unsigned long V_371 , unsigned int V_62 ,
T_12 V_155 )
{
if ( V_371 ) {
unsigned long V_383 = V_371 + ( V_104 << V_62 ) ;
unsigned long V_384 = V_371 + F_410 ( V_155 ) ;
F_284 ( F_287 ( ( void * ) V_371 ) , V_62 ) ;
while ( V_384 < V_383 ) {
F_411 ( V_384 ) ;
V_384 += V_104 ;
}
}
return ( void * ) V_371 ;
}
void * F_412 ( T_12 V_155 , T_7 V_240 )
{
unsigned int V_62 = F_413 ( V_155 ) ;
unsigned long V_371 ;
V_371 = F_395 ( V_240 , V_62 ) ;
return F_409 ( V_371 , V_62 , V_155 ) ;
}
void * T_2 F_414 ( int V_19 , T_12 V_155 , T_7 V_240 )
{
unsigned int V_62 = F_413 ( V_155 ) ;
struct V_1 * V_66 = F_401 ( V_19 , V_240 , V_62 ) ;
if ( ! V_66 )
return NULL ;
return F_409 ( ( unsigned long ) F_130 ( V_66 ) , V_62 , V_155 ) ;
}
void F_415 ( void * V_385 , T_12 V_155 )
{
unsigned long V_371 = ( unsigned long ) V_385 ;
unsigned long V_119 = V_371 + F_410 ( V_155 ) ;
while ( V_371 < V_119 ) {
F_411 ( V_371 ) ;
V_371 += V_104 ;
}
}
static unsigned long F_416 ( int V_379 )
{
struct V_192 * V_193 ;
struct V_43 * V_43 ;
unsigned long V_386 = 0 ;
struct V_191 * V_191 = F_385 ( F_294 () , V_387 ) ;
F_417 (zone, z, zonelist, offset) {
unsigned long V_155 = V_43 -> V_123 ;
unsigned long V_153 = F_418 ( V_43 ) ;
if ( V_155 > V_153 )
V_386 += V_155 - V_153 ;
}
return V_386 ;
}
unsigned long F_419 ( void )
{
return F_416 ( F_388 ( V_388 ) ) ;
}
unsigned long F_420 ( void )
{
return F_416 ( F_388 ( V_389 ) ) ;
}
static inline void F_421 ( struct V_43 * V_43 )
{
if ( F_112 ( F_293 ) )
F_422 ( L_32 , F_41 ( V_43 ) ) ;
}
long F_423 ( void )
{
long V_343 ;
unsigned long V_390 ;
unsigned long V_391 = 0 ;
unsigned long V_392 [ V_393 ] ;
struct V_43 * V_43 ;
int V_78 ;
for ( V_78 = V_394 ; V_78 < V_393 ; V_78 ++ )
V_392 [ V_78 ] = F_424 ( V_395 + V_78 ) ;
F_425 (zone)
V_391 += V_43 -> V_221 [ V_396 ] ;
V_343 = F_426 ( V_201 ) - V_397 ;
V_390 = V_392 [ V_398 ] + V_392 [ V_399 ] ;
V_390 -= F_11 ( V_390 / 2 , V_391 ) ;
V_343 += V_390 ;
V_343 += F_424 ( V_400 ) -
F_11 ( F_424 ( V_400 ) / 2 ,
V_391 ) ;
if ( V_343 < 0 )
V_343 = 0 ;
return V_343 ;
}
void F_427 ( struct V_401 * V_402 )
{
V_402 -> V_403 = V_404 ;
V_402 -> V_405 = F_424 ( V_406 ) ;
V_402 -> V_407 = F_426 ( V_201 ) ;
V_402 -> V_408 = F_428 () ;
V_402 -> V_409 = V_410 ;
V_402 -> V_411 = F_429 () ;
V_402 -> V_412 = V_104 ;
}
void F_430 ( struct V_401 * V_402 , int V_19 )
{
int V_413 ;
unsigned long V_123 = 0 ;
unsigned long V_414 = 0 ;
unsigned long V_415 = 0 ;
T_1 * V_9 = F_15 ( V_19 ) ;
for ( V_413 = 0 ; V_413 < V_116 ; V_413 ++ )
V_123 += V_9 -> V_117 [ V_413 ] . V_123 ;
V_402 -> V_403 = V_123 ;
V_402 -> V_405 = F_431 ( V_9 , V_406 ) ;
V_402 -> V_407 = F_432 ( V_19 , V_201 ) ;
#ifdef F_433
for ( V_413 = 0 ; V_413 < V_116 ; V_413 ++ ) {
struct V_43 * V_43 = & V_9 -> V_117 [ V_413 ] ;
if ( F_434 ( V_43 ) ) {
V_414 += V_43 -> V_123 ;
V_415 += F_314 ( V_43 , V_201 ) ;
}
}
V_402 -> V_409 = V_414 ;
V_402 -> V_411 = V_415 ;
#else
V_402 -> V_409 = V_414 ;
V_402 -> V_411 = V_415 ;
#endif
V_402 -> V_412 = V_104 ;
}
static bool F_435 ( unsigned int V_37 , int V_19 , T_10 * V_278 )
{
if ( ! ( V_37 & V_280 ) )
return false ;
if ( ! V_278 )
V_278 = & V_366 ;
return ! F_436 ( V_19 , * V_278 ) ;
}
static void F_437 ( unsigned char type )
{
static const char V_416 [ V_182 ] = {
[ V_41 ] = 'U' ,
[ V_135 ] = 'M' ,
[ V_170 ] = 'E' ,
[ V_187 ] = 'H' ,
#ifdef F_313
[ V_150 ] = 'C' ,
#endif
#ifdef F_438
[ V_417 ] = 'I' ,
#endif
} ;
char V_418 [ V_182 + 1 ] ;
char * V_66 = V_418 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_182 ; V_63 ++ ) {
if ( type & ( 1 << V_63 ) )
* V_66 ++ = V_416 [ V_63 ] ;
}
* V_66 = '\0' ;
F_422 ( V_419 L_33 , V_418 ) ;
}
void F_439 ( unsigned int V_279 , T_10 * V_278 )
{
unsigned long V_420 = 0 ;
int V_204 ;
struct V_43 * V_43 ;
T_1 * V_9 ;
F_201 (zone) {
if ( F_435 ( V_279 , F_41 ( V_43 ) , V_278 ) )
continue;
F_262 (cpu)
V_420 += F_251 ( V_43 -> V_207 , V_204 ) -> V_107 . V_105 ;
}
F_422 ( L_34
L_35
L_36
L_37
L_38
L_39 ,
F_424 ( V_421 ) ,
F_424 ( V_422 ) ,
F_424 ( V_423 ) ,
F_424 ( V_424 ) ,
F_424 ( V_425 ) ,
F_424 ( V_426 ) ,
F_424 ( V_427 ) ,
F_424 ( V_428 ) ,
F_424 ( V_429 ) ,
F_424 ( V_430 ) ,
F_424 ( V_400 ) ,
F_424 ( V_431 ) ,
F_424 ( V_432 ) ,
F_424 ( V_406 ) ,
F_426 ( V_433 ) ,
F_426 ( V_434 ) ,
F_426 ( V_201 ) ,
V_420 ,
F_426 ( V_200 ) ) ;
F_440 (pgdat) {
if ( F_435 ( V_279 , V_9 -> V_139 , V_278 ) )
continue;
F_422 ( L_40
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
#ifdef F_441
L_52
L_53
L_54
#endif
L_55
L_56
L_57
L_58 ,
V_9 -> V_139 ,
F_442 ( F_431 ( V_9 , V_421 ) ) ,
F_442 ( F_431 ( V_9 , V_422 ) ) ,
F_442 ( F_431 ( V_9 , V_424 ) ) ,
F_442 ( F_431 ( V_9 , V_425 ) ) ,
F_442 ( F_431 ( V_9 , V_427 ) ) ,
F_442 ( F_431 ( V_9 , V_423 ) ) ,
F_442 ( F_431 ( V_9 , V_426 ) ) ,
F_442 ( F_431 ( V_9 , V_432 ) ) ,
F_442 ( F_431 ( V_9 , V_428 ) ) ,
F_442 ( F_431 ( V_9 , V_429 ) ) ,
F_442 ( F_431 ( V_9 , V_406 ) ) ,
#ifdef F_441
F_442 ( F_431 ( V_9 , V_435 ) * V_436 ) ,
F_442 ( F_431 ( V_9 , V_437 )
* V_436 ) ,
F_442 ( F_431 ( V_9 , V_438 ) * V_436 ) ,
#endif
F_442 ( F_431 ( V_9 , V_439 ) ) ,
F_442 ( F_431 ( V_9 , V_430 ) ) ,
V_9 -> V_440 >= V_342 ?
L_59 : L_60 ) ;
}
F_201 (zone) {
int V_63 ;
if ( F_435 ( V_279 , F_41 ( V_43 ) , V_278 ) )
continue;
V_420 = 0 ;
F_262 (cpu)
V_420 += F_251 ( V_43 -> V_207 , V_204 ) -> V_107 . V_105 ;
F_421 ( V_43 ) ;
F_422 ( V_419
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
F_442 ( F_314 ( V_43 , V_201 ) ) ,
F_442 ( F_290 ( V_43 ) ) ,
F_442 ( F_443 ( V_43 ) ) ,
F_442 ( F_418 ( V_43 ) ) ,
F_442 ( F_314 ( V_43 , V_441 ) ) ,
F_442 ( F_314 ( V_43 , V_442 ) ) ,
F_442 ( F_314 ( V_43 , V_443 ) ) ,
F_442 ( F_314 ( V_43 , V_444 ) ) ,
F_442 ( F_314 ( V_43 , V_445 ) ) ,
F_442 ( F_314 ( V_43 , V_348 ) ) ,
F_442 ( V_43 -> V_446 ) ,
F_442 ( V_43 -> V_123 ) ,
F_442 ( F_314 ( V_43 , V_447 ) ) ,
F_314 ( V_43 , V_448 ) ,
F_442 ( F_314 ( V_43 , V_433 ) ) ,
F_442 ( F_314 ( V_43 , V_434 ) ) ,
F_442 ( V_420 ) ,
F_442 ( F_444 ( V_43 -> V_207 -> V_107 . V_105 ) ) ,
F_442 ( F_314 ( V_43 , V_200 ) ) ) ;
F_422 ( L_76 ) ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ )
F_422 ( V_419 L_77 , V_43 -> V_260 [ V_63 ] ) ;
F_422 ( V_419 L_58 ) ;
}
F_201 (zone) {
unsigned int V_62 ;
unsigned long V_449 [ V_74 ] , V_37 , V_450 = 0 ;
unsigned char V_416 [ V_74 ] ;
if ( F_435 ( V_279 , F_41 ( V_43 ) , V_278 ) )
continue;
F_421 ( V_43 ) ;
F_422 ( V_419 L_25 , V_43 -> V_49 ) ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_87 * V_154 = & V_43 -> V_87 [ V_62 ] ;
int type ;
V_449 [ V_62 ] = V_154 -> V_88 ;
V_450 += V_449 [ V_62 ] << V_62 ;
V_416 [ V_62 ] = 0 ;
for ( type = 0 ; type < V_182 ; type ++ ) {
if ( ! F_140 ( & V_154 -> V_92 [ type ] ) )
V_416 [ V_62 ] |= 1 << type ;
}
}
F_238 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
F_422 ( V_419 L_78 ,
V_449 [ V_62 ] , F_442 ( 1UL ) << V_62 ) ;
if ( V_449 [ V_62 ] )
F_437 ( V_416 [ V_62 ] ) ;
}
F_422 ( V_419 L_79 , F_442 ( V_450 ) ) ;
}
F_445 () ;
F_422 ( L_80 , F_424 ( V_451 ) ) ;
F_446 () ;
}
static void F_447 ( struct V_43 * V_43 , struct V_192 * V_192 )
{
V_192 -> V_43 = V_43 ;
V_192 -> V_452 = V_452 ( V_43 ) ;
}
static int F_448 ( T_1 * V_9 , struct V_192 * V_453 )
{
struct V_43 * V_43 ;
enum V_413 V_413 = V_116 ;
int V_454 = 0 ;
do {
V_413 -- ;
V_43 = V_9 -> V_117 + V_413 ;
if ( F_449 ( V_43 ) ) {
F_447 ( V_43 , & V_453 [ V_454 ++ ] ) ;
F_450 ( V_413 ) ;
}
} while ( V_413 );
return V_454 ;
}
static int F_451 ( char * V_455 )
{
if ( ! ( * V_455 == 'd' || * V_455 == 'D' || * V_455 == 'n' || * V_455 == 'N' ) ) {
F_335 ( L_81 , V_455 ) ;
return - V_70 ;
}
return 0 ;
}
static T_5 int F_452 ( char * V_455 )
{
if ( ! V_455 )
return 0 ;
return F_451 ( V_455 ) ;
}
int F_453 ( struct V_456 * V_457 , int V_458 ,
void T_13 * V_459 , T_12 * V_460 ,
T_14 * V_461 )
{
char * V_237 ;
int V_44 ;
if ( ! V_458 )
return F_454 ( V_457 , V_458 , V_459 , V_460 , V_461 ) ;
V_237 = F_455 ( V_459 , 16 ) ;
if ( F_307 ( V_237 ) )
return F_308 ( V_237 ) ;
V_44 = F_451 ( V_237 ) ;
F_456 ( V_237 ) ;
return V_44 ;
}
static int F_457 ( int V_127 , T_10 * V_462 )
{
int V_463 , V_402 ;
int V_464 = V_465 ;
int V_466 = V_376 ;
const struct V_144 * V_418 = F_184 ( 0 ) ;
if ( ! F_436 ( V_127 , * V_462 ) ) {
F_458 ( V_127 , * V_462 ) ;
return V_127 ;
}
F_195 (n, N_MEMORY) {
if ( F_436 ( V_463 , * V_462 ) )
continue;
V_402 = F_319 ( V_127 , V_463 ) ;
V_402 += ( V_463 < V_127 ) ;
V_418 = F_184 ( V_463 ) ;
if ( ! F_185 ( V_418 ) )
V_402 += V_467 ;
V_402 *= ( V_468 * V_469 ) ;
V_402 += V_470 [ V_463 ] ;
if ( V_402 < V_464 ) {
V_464 = V_402 ;
V_466 = V_463 ;
}
}
if ( V_466 >= 0 )
F_458 ( V_466 , * V_462 ) ;
return V_466 ;
}
static void F_459 ( T_1 * V_9 , int * V_471 ,
unsigned V_472 )
{
struct V_192 * V_453 ;
int V_63 ;
V_453 = V_9 -> V_473 [ V_474 ] . V_475 ;
for ( V_63 = 0 ; V_63 < V_472 ; V_63 ++ ) {
int V_454 ;
T_1 * V_127 = F_15 ( V_471 [ V_63 ] ) ;
V_454 = F_448 ( V_127 , V_453 ) ;
V_453 += V_454 ;
}
V_453 -> V_43 = NULL ;
V_453 -> V_452 = 0 ;
}
static void F_460 ( T_1 * V_9 )
{
struct V_192 * V_453 ;
int V_454 ;
V_453 = V_9 -> V_473 [ V_476 ] . V_475 ;
V_454 = F_448 ( V_9 , V_453 ) ;
V_453 += V_454 ;
V_453 -> V_43 = NULL ;
V_453 -> V_452 = 0 ;
}
static void F_461 ( T_1 * V_9 )
{
static int V_471 [ V_469 ] ;
int V_127 , V_477 , V_472 = 0 ;
T_10 V_478 ;
int V_479 , V_480 ;
V_479 = V_9 -> V_139 ;
V_477 = V_481 ;
V_480 = V_479 ;
F_462 ( V_478 ) ;
memset ( V_471 , 0 , sizeof( V_471 ) ) ;
while ( ( V_127 = F_457 ( V_479 , & V_478 ) ) >= 0 ) {
if ( F_319 ( V_479 , V_127 ) !=
F_319 ( V_479 , V_480 ) )
V_470 [ V_127 ] = V_477 ;
V_471 [ V_472 ++ ] = V_127 ;
V_480 = V_127 ;
V_477 -- ;
}
F_459 ( V_9 , V_471 , V_472 ) ;
F_460 ( V_9 ) ;
}
int F_463 ( int V_127 )
{
struct V_192 * V_193 ;
V_193 = F_384 ( F_385 ( V_127 , V_387 ) ,
F_388 ( V_387 ) ,
NULL ) ;
return V_193 -> V_43 -> V_127 ;
}
static void F_461 ( T_1 * V_9 )
{
int V_127 , V_479 ;
struct V_192 * V_453 ;
int V_454 ;
V_479 = V_9 -> V_139 ;
V_453 = V_9 -> V_473 [ V_474 ] . V_475 ;
V_454 = F_448 ( V_9 , V_453 ) ;
V_453 += V_454 ;
for ( V_127 = V_479 + 1 ; V_127 < V_469 ; V_127 ++ ) {
if ( ! F_14 ( V_127 ) )
continue;
V_454 = F_448 ( F_15 ( V_127 ) , V_453 ) ;
V_453 += V_454 ;
}
for ( V_127 = 0 ; V_127 < V_479 ; V_127 ++ ) {
if ( ! F_14 ( V_127 ) )
continue;
V_454 = F_448 ( F_15 ( V_127 ) , V_453 ) ;
V_453 += V_454 ;
}
V_453 -> V_43 = NULL ;
V_453 -> V_452 = 0 ;
}
static void F_464 ( void * V_138 )
{
int V_19 ;
int T_4 V_204 ;
T_1 * V_482 = V_138 ;
static F_169 ( V_110 ) ;
F_139 ( & V_110 ) ;
#ifdef F_293
memset ( V_470 , 0 , sizeof( V_470 ) ) ;
#endif
if ( V_482 && ! F_14 ( V_482 -> V_139 ) ) {
F_461 ( V_482 ) ;
} else {
F_465 (nid) {
T_1 * V_9 = F_15 ( V_19 ) ;
F_461 ( V_9 ) ;
}
#ifdef F_466
F_262 (cpu)
F_467 ( V_204 , F_463 ( F_468 ( V_204 ) ) ) ;
#endif
}
F_143 ( & V_110 ) ;
}
static T_15 void T_5
F_469 ( void )
{
int V_204 ;
F_464 ( NULL ) ;
F_470 (cpu)
F_471 ( & F_472 ( V_483 , V_204 ) , 0 ) ;
F_473 () ;
F_474 () ;
}
void T_16 F_475 ( T_1 * V_9 )
{
if ( V_484 == V_485 ) {
F_469 () ;
} else {
F_464 ( V_9 ) ;
}
V_486 = F_420 () ;
if ( V_486 < ( V_27 * V_182 ) )
V_39 = 1 ;
else
V_39 = 0 ;
F_73 ( L_82 ,
V_481 ,
V_39 ? L_83 : L_84 ,
V_486 ) ;
#ifdef F_293
F_73 ( L_85 , V_487 [ V_488 ] ) ;
#endif
}
void T_2 F_476 ( unsigned long V_155 , int V_19 , unsigned long V_43 ,
unsigned long V_47 , enum V_489 V_490 )
{
struct V_491 * V_492 = F_477 ( F_478 ( V_47 ) ) ;
unsigned long V_120 = V_47 + V_155 ;
T_1 * V_9 = F_15 ( V_19 ) ;
unsigned long V_18 ;
unsigned long V_21 = 0 ;
#ifdef F_479
struct V_493 * V_494 = NULL , * V_418 ;
#endif
if ( V_495 < V_120 - 1 )
V_495 = V_120 - 1 ;
if ( V_492 && V_47 == V_492 -> V_496 )
V_47 += V_492 -> V_497 ;
for ( V_18 = V_47 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_490 != V_498 )
goto V_499;
if ( ! F_480 ( V_18 ) ) {
#ifdef F_479
V_18 = F_481 ( V_18 , V_120 ) - 1 ;
#endif
continue;
}
if ( ! F_172 ( V_18 , V_19 ) )
continue;
if ( ! F_16 ( V_9 , V_18 , V_120 , & V_21 ) )
break;
#ifdef F_479
if ( V_500 && V_43 == V_501 ) {
if ( ! V_494 || V_18 >= F_482 ( V_494 ) ) {
F_483 (memory, tmp)
if ( V_18 < F_482 ( V_418 ) )
break;
V_494 = V_418 ;
}
if ( V_18 >= F_484 ( V_494 ) &&
F_485 ( V_494 ) ) {
V_18 = F_482 ( V_494 ) ;
continue;
}
}
#endif
V_499:
if ( ! ( V_18 & ( V_27 - 1 ) ) ) {
struct V_1 * V_1 = F_153 ( V_18 ) ;
F_145 ( V_1 , V_18 , V_43 , V_19 ) ;
F_33 ( V_1 , V_135 ) ;
F_189 () ;
} else {
F_152 ( V_18 , V_43 , V_19 ) ;
}
}
}
static void T_2 F_486 ( struct V_43 * V_43 )
{
unsigned int V_62 , V_218 ;
F_275 (order, t) {
F_78 ( & V_43 -> V_87 [ V_62 ] . V_92 [ V_218 ] ) ;
V_43 -> V_87 [ V_62 ] . V_88 = 0 ;
}
}
static int F_487 ( struct V_43 * V_43 )
{
#ifdef V_338
int V_203 ;
V_203 = V_43 -> V_123 / 1024 ;
if ( V_203 * V_104 > 512 * 1024 )
V_203 = ( 512 * 1024 ) / V_104 ;
V_203 /= 4 ;
if ( V_203 < 1 )
V_203 = 1 ;
V_203 = F_488 ( V_203 + V_203 / 2 ) - 1 ;
return V_203 ;
#else
return 0 ;
#endif
}
static void F_489 ( struct V_106 * V_107 , unsigned long V_153 ,
unsigned long V_203 )
{
V_107 -> V_203 = 1 ;
F_490 () ;
V_107 -> V_153 = V_153 ;
F_490 () ;
V_107 -> V_203 = V_203 ;
}
static void F_491 ( struct V_205 * V_66 , unsigned long V_203 )
{
F_489 ( & V_66 -> V_107 , 6 * V_203 , F_9 ( 1UL , 1 * V_203 ) ) ;
}
static void F_492 ( struct V_205 * V_66 )
{
struct V_106 * V_107 ;
int V_3 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_107 = & V_66 -> V_107 ;
V_107 -> V_105 = 0 ;
for ( V_3 = 0 ; V_3 < V_40 ; V_3 ++ )
F_78 ( & V_107 -> V_113 [ V_3 ] ) ;
}
static void F_471 ( struct V_205 * V_66 , unsigned long V_203 )
{
F_492 ( V_66 ) ;
F_491 ( V_66 , V_203 ) ;
}
static void F_493 ( struct V_205 * V_66 ,
unsigned long V_153 )
{
unsigned long V_203 = F_9 ( 1UL , V_153 / 4 ) ;
if ( ( V_153 / 4 ) > ( V_12 * 8 ) )
V_203 = V_12 * 8 ;
F_489 ( & V_66 -> V_107 , V_153 , V_203 ) ;
}
static void F_494 ( struct V_43 * V_43 ,
struct V_205 * V_107 )
{
if ( V_502 )
F_493 ( V_107 ,
( V_43 -> V_123 /
V_502 ) ) ;
else
F_491 ( V_107 , F_487 ( V_43 ) ) ;
}
static void T_2 F_495 ( struct V_43 * V_43 , int V_204 )
{
struct V_205 * V_107 = F_251 ( V_43 -> V_207 , V_204 ) ;
F_492 ( V_107 ) ;
F_494 ( V_43 , V_107 ) ;
}
void T_2 F_496 ( struct V_43 * V_43 )
{
int V_204 ;
V_43 -> V_207 = F_497 ( struct V_205 ) ;
F_470 (cpu)
F_495 ( V_43 , V_204 ) ;
}
void T_5 F_498 ( void )
{
struct V_266 * V_9 ;
struct V_43 * V_43 ;
F_201 (zone)
F_496 ( V_43 ) ;
F_440 (pgdat)
V_9 -> V_503 =
F_497 ( struct V_504 ) ;
}
static T_2 void F_499 ( struct V_43 * V_43 )
{
V_43 -> V_207 = & V_483 ;
if ( F_190 ( V_43 ) )
F_422 ( V_505 L_86 ,
V_43 -> V_49 , V_43 -> V_446 ,
F_487 ( V_43 ) ) ;
}
void T_2 F_500 ( struct V_43 * V_43 ,
unsigned long V_26 ,
unsigned long V_155 )
{
struct V_266 * V_9 = V_43 -> V_270 ;
V_9 -> V_454 = V_452 ( V_43 ) + 1 ;
V_43 -> V_26 = V_26 ;
F_501 ( V_506 , L_87 ,
L_88 ,
V_9 -> V_139 ,
( unsigned long ) V_452 ( V_43 ) ,
V_26 , ( V_26 + V_155 ) ) ;
F_486 ( V_43 ) ;
V_43 -> V_507 = 1 ;
}
int T_2 F_170 ( unsigned long V_18 ,
struct V_128 * V_129 )
{
unsigned long V_47 , V_120 ;
int V_19 ;
if ( V_129 -> V_508 <= V_18 && V_18 < V_129 -> V_509 )
return V_129 -> V_510 ;
V_19 = F_502 ( V_18 , & V_47 , & V_120 ) ;
if ( V_19 != - 1 ) {
V_129 -> V_508 = V_47 ;
V_129 -> V_509 = V_120 ;
V_129 -> V_510 = V_19 ;
}
return V_19 ;
}
void T_5 F_503 ( int V_19 , unsigned long V_511 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_512 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_47 = F_11 ( V_47 , V_511 ) ;
V_120 = F_11 ( V_120 , V_511 ) ;
if ( V_47 < V_120 )
F_504 ( F_505 ( V_47 ) ,
( V_120 - V_47 ) << V_12 ,
V_512 ) ;
}
}
void T_5 F_506 ( int V_19 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_512 ;
F_188 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_507 ( V_512 , V_47 , V_120 ) ;
}
void T_2 F_508 ( unsigned int V_19 ,
unsigned long * V_47 , unsigned long * V_120 )
{
unsigned long V_513 , V_514 ;
int V_63 ;
* V_47 = - 1UL ;
* V_120 = 0 ;
F_188 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_47 = F_11 ( * V_47 , V_513 ) ;
* V_120 = F_9 ( * V_120 , V_514 ) ;
}
if ( * V_47 == - 1UL )
* V_47 = 0 ;
}
static void T_5 F_509 ( void )
{
int V_515 ;
for ( V_515 = V_116 - 1 ; V_515 >= 0 ; V_515 -- ) {
if ( V_515 == V_501 )
continue;
if ( V_516 [ V_515 ] >
V_517 [ V_515 ] )
break;
}
F_96 ( V_515 == - 1 ) ;
V_518 = V_515 ;
}
static void T_2 F_510 ( int V_19 ,
unsigned long V_413 ,
unsigned long V_14 ,
unsigned long V_519 ,
unsigned long * V_26 ,
unsigned long * F_155 )
{
if ( V_520 [ V_19 ] ) {
if ( V_413 == V_501 ) {
* V_26 = V_520 [ V_19 ] ;
* F_155 = F_11 ( V_519 ,
V_516 [ V_518 ] ) ;
} else if ( ! V_500 &&
* V_26 < V_520 [ V_19 ] &&
* F_155 > V_520 [ V_19 ] ) {
* F_155 = V_520 [ V_19 ] ;
} else if ( * V_26 >= V_520 [ V_19 ] )
* V_26 = * F_155 ;
}
}
static unsigned long T_2 F_511 ( int V_19 ,
unsigned long V_413 ,
unsigned long V_14 ,
unsigned long V_519 ,
unsigned long * V_26 ,
unsigned long * F_155 ,
unsigned long * V_521 )
{
if ( ! V_14 && ! V_519 )
return 0 ;
* V_26 = V_517 [ V_413 ] ;
* F_155 = V_516 [ V_413 ] ;
F_510 ( V_19 , V_413 ,
V_14 , V_519 ,
V_26 , F_155 ) ;
if ( * F_155 < V_14 || * V_26 > V_519 )
return 0 ;
* F_155 = F_11 ( * F_155 , V_519 ) ;
* V_26 = F_9 ( * V_26 , V_14 ) ;
return * F_155 - * V_26 ;
}
unsigned long T_2 F_512 ( int V_19 ,
unsigned long V_522 ,
unsigned long V_523 )
{
unsigned long V_524 = V_523 - V_522 ;
unsigned long V_47 , V_120 ;
int V_63 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
V_47 = F_513 ( V_47 , V_522 , V_523 ) ;
V_120 = F_513 ( V_120 , V_522 , V_523 ) ;
V_524 -= V_120 - V_47 ;
}
return V_524 ;
}
unsigned long T_5 F_514 ( unsigned long V_47 ,
unsigned long V_120 )
{
return F_512 ( V_469 , V_47 , V_120 ) ;
}
static unsigned long T_2 F_515 ( int V_19 ,
unsigned long V_413 ,
unsigned long V_14 ,
unsigned long V_519 ,
unsigned long * V_521 )
{
unsigned long V_525 = V_517 [ V_413 ] ;
unsigned long V_526 = V_516 [ V_413 ] ;
unsigned long V_26 , F_155 ;
unsigned long V_524 ;
if ( ! V_14 && ! V_519 )
return 0 ;
V_26 = F_513 ( V_14 , V_525 , V_526 ) ;
F_155 = F_513 ( V_519 , V_525 , V_526 ) ;
F_510 ( V_19 , V_413 ,
V_14 , V_519 ,
& V_26 , & F_155 ) ;
V_524 = F_512 ( V_19 , V_26 , F_155 ) ;
if ( V_500 && V_520 [ V_19 ] ) {
unsigned long V_47 , V_120 ;
struct V_493 * V_494 ;
F_483 (memory, r) {
V_47 = F_513 ( F_484 ( V_494 ) ,
V_26 , F_155 ) ;
V_120 = F_513 ( F_482 ( V_494 ) ,
V_26 , F_155 ) ;
if ( V_413 == V_501 &&
F_485 ( V_494 ) )
V_524 += V_120 - V_47 ;
if ( V_413 == V_304 &&
! F_485 ( V_494 ) )
V_524 += V_120 - V_47 ;
}
}
return V_524 ;
}
static inline unsigned long T_2 F_511 ( int V_19 ,
unsigned long V_413 ,
unsigned long V_14 ,
unsigned long V_519 ,
unsigned long * V_26 ,
unsigned long * F_155 ,
unsigned long * V_527 )
{
unsigned int V_43 ;
* V_26 = V_14 ;
for ( V_43 = 0 ; V_43 < V_413 ; V_43 ++ )
* V_26 += V_527 [ V_43 ] ;
* F_155 = * V_26 + V_527 [ V_413 ] ;
return V_527 [ V_413 ] ;
}
static inline unsigned long T_2 F_515 ( int V_19 ,
unsigned long V_413 ,
unsigned long V_14 ,
unsigned long V_519 ,
unsigned long * V_528 )
{
if ( ! V_528 )
return 0 ;
return V_528 [ V_413 ] ;
}
static void T_2 F_516 ( struct V_266 * V_9 ,
unsigned long V_14 ,
unsigned long V_519 ,
unsigned long * V_527 ,
unsigned long * V_528 )
{
unsigned long V_529 = 0 , V_530 = 0 ;
enum V_413 V_63 ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_63 ;
unsigned long V_26 , F_155 ;
unsigned long V_155 , V_531 ;
V_155 = F_511 ( V_9 -> V_139 , V_63 ,
V_14 ,
V_519 ,
& V_26 ,
& F_155 ,
V_527 ) ;
V_531 = V_155 - F_515 ( V_9 -> V_139 , V_63 ,
V_14 , V_519 ,
V_528 ) ;
if ( V_155 )
V_43 -> V_26 = V_26 ;
else
V_43 -> V_26 = 0 ;
V_43 -> V_48 = V_155 ;
V_43 -> V_446 = V_531 ;
V_530 += V_155 ;
V_529 += V_531 ;
}
V_9 -> V_13 = V_530 ;
V_9 -> V_532 = V_529 ;
F_422 ( V_505 L_89 , V_9 -> V_139 ,
V_529 ) ;
}
static unsigned long T_5 F_517 ( unsigned long V_26 , unsigned long V_533 )
{
unsigned long V_534 ;
V_533 += V_26 & ( V_27 - 1 ) ;
V_534 = F_518 ( V_533 , V_27 ) ;
V_534 = V_534 >> V_24 ;
V_534 *= V_25 ;
V_534 = F_518 ( V_534 , 8 * sizeof( unsigned long ) ) ;
return V_534 / 8 ;
}
static void T_5 F_519 ( struct V_266 * V_9 ,
struct V_43 * V_43 ,
unsigned long V_26 ,
unsigned long V_533 )
{
unsigned long V_534 = F_517 ( V_26 , V_533 ) ;
V_43 -> V_23 = NULL ;
if ( V_534 )
V_43 -> V_23 =
F_520 ( V_534 ,
V_9 -> V_139 ) ;
}
static inline void F_519 ( struct V_266 * V_9 , struct V_43 * V_43 ,
unsigned long V_26 , unsigned long V_533 ) {}
void T_17 F_521 ( void )
{
unsigned int V_62 ;
if ( V_24 )
return;
if ( V_535 > V_12 )
V_62 = V_536 ;
else
V_62 = V_74 - 1 ;
V_24 = V_62 ;
}
void T_17 F_521 ( void )
{
}
static unsigned long T_17 F_522 ( unsigned long V_48 ,
unsigned long V_446 )
{
unsigned long V_392 = V_48 ;
if ( V_48 > V_446 + ( V_446 >> 4 ) &&
F_112 ( F_19 ) )
V_392 = V_446 ;
return F_410 ( V_392 * sizeof( struct V_1 ) ) >> V_12 ;
}
static void T_17 F_523 ( struct V_266 * V_9 )
{
enum V_413 V_537 ;
int V_19 = V_9 -> V_139 ;
F_524 ( V_9 ) ;
#ifdef F_525
F_526 ( & V_9 -> V_538 ) ;
V_9 -> V_539 = 0 ;
V_9 -> V_540 = V_55 ;
#endif
#ifdef F_441
F_526 ( & V_9 -> V_541 ) ;
F_78 ( & V_9 -> V_542 ) ;
V_9 -> V_543 = 0 ;
#endif
F_527 ( & V_9 -> V_544 ) ;
F_527 ( & V_9 -> V_545 ) ;
#ifdef F_528
F_527 ( & V_9 -> V_546 ) ;
#endif
F_529 ( V_9 ) ;
F_526 ( & V_9 -> V_547 ) ;
F_530 ( F_531 ( V_9 ) ) ;
V_9 -> V_503 = & V_548 ;
for ( V_537 = 0 ; V_537 < V_116 ; V_537 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_537 ;
unsigned long V_155 , V_549 , V_550 , V_551 ;
unsigned long V_26 = V_43 -> V_26 ;
V_155 = V_43 -> V_48 ;
V_549 = V_550 = V_43 -> V_446 ;
V_551 = F_522 ( V_155 , V_549 ) ;
if ( ! F_149 ( V_537 ) ) {
if ( V_550 >= V_551 ) {
V_550 -= V_551 ;
if ( V_551 )
F_422 ( V_505
L_90 ,
V_487 [ V_537 ] , V_551 ) ;
} else
F_335 ( L_91 ,
V_487 [ V_537 ] , V_551 , V_550 ) ;
}
if ( V_537 == 0 && V_550 > V_552 ) {
V_550 -= V_552 ;
F_422 ( V_505 L_92 ,
V_487 [ 0 ] , V_552 ) ;
}
if ( ! F_149 ( V_537 ) )
V_553 += V_550 ;
else if ( V_553 > V_551 * 2 )
V_553 -= V_551 ;
V_554 += V_550 ;
V_43 -> V_123 = F_149 ( V_537 ) ? V_549 : V_550 ;
#ifdef F_293
V_43 -> V_127 = V_19 ;
#endif
V_43 -> V_49 = V_487 [ V_537 ] ;
V_43 -> V_270 = V_9 ;
F_526 ( & V_43 -> V_110 ) ;
F_532 ( V_43 ) ;
F_499 ( V_43 ) ;
if ( ! V_155 )
continue;
F_521 () ;
F_519 ( V_9 , V_43 , V_26 , V_155 ) ;
F_500 ( V_43 , V_26 , V_155 ) ;
F_533 ( V_155 , V_19 , V_537 , V_26 ) ;
}
}
static void T_16 F_534 ( struct V_266 * V_9 )
{
unsigned long T_4 V_118 = 0 ;
unsigned long T_4 V_379 = 0 ;
if ( ! V_9 -> V_13 )
return;
#ifdef F_535
V_118 = V_9 -> V_14 & ~ ( V_151 - 1 ) ;
V_379 = V_9 -> V_14 - V_118 ;
if ( ! V_9 -> V_555 ) {
unsigned long V_155 , V_119 ;
struct V_1 * V_556 ;
V_119 = F_17 ( V_9 ) ;
V_119 = F_177 ( V_119 , V_151 ) ;
V_155 = ( V_119 - V_118 ) * sizeof( struct V_1 ) ;
V_556 = F_536 ( V_9 -> V_139 , V_155 ) ;
if ( ! V_556 )
V_556 = F_520 ( V_155 ,
V_9 -> V_139 ) ;
V_9 -> V_555 = V_556 + V_379 ;
}
#ifndef F_537
if ( V_9 == F_15 ( 0 ) ) {
V_557 = F_15 ( 0 ) -> V_555 ;
#if F_538 ( F_479 ) || F_538 ( V_558 )
if ( F_37 ( V_557 ) != V_9 -> V_14 )
V_557 -= V_379 ;
#endif
}
#endif
#endif
}
void T_17 F_539 ( int V_19 , unsigned long * V_527 ,
unsigned long V_14 , unsigned long * V_528 )
{
T_1 * V_9 = F_15 ( V_19 ) ;
unsigned long V_47 = 0 ;
unsigned long V_120 = 0 ;
F_4 ( V_9 -> V_454 || V_9 -> V_559 ) ;
V_9 -> V_139 = V_19 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_503 = NULL ;
#ifdef F_479
F_508 ( V_19 , & V_47 , & V_120 ) ;
F_73 ( L_93 , V_19 ,
( V_560 ) V_47 << V_12 ,
V_120 ? ( ( V_560 ) V_120 << V_12 ) - 1 : 0 ) ;
#else
V_47 = V_14 ;
#endif
F_516 ( V_9 , V_47 , V_120 ,
V_527 , V_528 ) ;
F_534 ( V_9 ) ;
#ifdef F_535
F_422 ( V_505 L_94 ,
V_19 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_555 ) ;
#endif
F_8 ( V_9 ) ;
F_523 ( V_9 ) ;
}
void T_5 F_540 ( void )
{
unsigned int V_561 ;
V_561 = F_541 ( V_562 . V_563 , V_469 ) ;
V_564 = V_561 + 1 ;
}
unsigned long T_5 F_542 ( void )
{
unsigned long V_565 = 0 , V_509 = 0 ;
unsigned long V_118 , V_119 , V_29 ;
int V_510 = - 1 ;
int V_63 , V_19 ;
F_188 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_118 || V_510 < 0 || V_510 == V_19 ) {
V_510 = V_19 ;
V_509 = V_119 ;
continue;
}
V_29 = ~ ( ( 1 << F_543 ( V_118 ) ) - 1 ) ;
while ( V_29 && V_509 <= ( V_118 & ( V_29 << 1 ) ) )
V_29 <<= 1 ;
V_565 |= V_29 ;
}
return ~ V_565 + 1 ;
}
static unsigned long T_5 F_544 ( int V_19 )
{
unsigned long V_566 = V_17 ;
unsigned long V_47 ;
int V_63 ;
F_188 (i, nid, &start_pfn, NULL, NULL)
V_566 = F_11 ( V_566 , V_47 ) ;
if ( V_566 == V_17 ) {
F_335 ( L_95 , V_19 ) ;
return 0 ;
}
return V_566 ;
}
unsigned long T_5 F_545 ( void )
{
return F_544 ( V_469 ) ;
}
static unsigned long T_5 F_546 ( void )
{
unsigned long V_530 = 0 ;
unsigned long V_47 , V_120 ;
int V_63 , V_19 ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_392 = V_120 - V_47 ;
V_530 += V_392 ;
if ( V_392 )
F_547 ( V_19 , V_149 ) ;
}
return V_530 ;
}
static void T_5 F_548 ( void )
{
int V_63 , V_19 ;
unsigned long V_567 ;
unsigned long V_568 , V_569 ;
T_10 V_570 = V_571 [ V_149 ] ;
unsigned long V_530 = F_546 () ;
int V_572 = F_549 ( V_571 [ V_149 ] ) ;
struct V_493 * V_494 ;
F_509 () ;
if ( F_550 () ) {
F_483 (memory, r) {
if ( ! F_551 ( V_494 ) )
continue;
V_19 = V_494 -> V_19 ;
V_567 = F_157 ( V_494 -> V_573 ) ;
V_520 [ V_19 ] = V_520 [ V_19 ] ?
F_11 ( V_567 , V_520 [ V_19 ] ) :
V_567 ;
}
goto V_574;
}
if ( V_500 ) {
bool V_575 = false ;
F_483 (memory, r) {
if ( F_485 ( V_494 ) )
continue;
V_19 = V_494 -> V_19 ;
V_567 = F_484 ( V_494 ) ;
if ( V_567 < 0x100000 ) {
V_575 = true ;
continue;
}
V_520 [ V_19 ] = V_520 [ V_19 ] ?
F_11 ( V_567 , V_520 [ V_19 ] ) :
V_567 ;
}
if ( V_575 )
F_335 ( L_96 ) ;
goto V_574;
}
if ( V_576 ) {
unsigned long V_577 ;
V_576 =
F_518 ( V_576 , V_151 ) ;
V_576 = F_11 ( V_530 , V_576 ) ;
V_577 = V_530 - V_576 ;
V_578 = F_9 ( V_578 , V_577 ) ;
}
if ( ! V_578 || V_578 >= V_530 )
goto V_56;
V_567 = V_517 [ V_518 ] ;
V_579:
V_568 = V_578 / V_572 ;
F_195 (nid, N_MEMORY) {
unsigned long V_47 , V_120 ;
if ( V_578 < V_568 )
V_568 = V_578 / V_572 ;
V_569 = V_568 ;
F_188 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_580 ;
V_47 = F_9 ( V_47 , V_520 [ V_19 ] ) ;
if ( V_47 >= V_120 )
continue;
if ( V_47 < V_567 ) {
unsigned long V_581 ;
V_581 = F_11 ( V_120 , V_567 )
- V_47 ;
V_569 -= F_11 ( V_581 ,
V_569 ) ;
V_578 -= F_11 ( V_581 ,
V_578 ) ;
if ( V_120 <= V_567 ) {
V_520 [ V_19 ] = V_120 ;
continue;
}
V_47 = V_567 ;
}
V_580 = V_120 - V_47 ;
if ( V_580 > V_569 )
V_580 = V_569 ;
V_520 [ V_19 ] = V_47 + V_580 ;
V_578 -= F_11 ( V_578 ,
V_580 ) ;
V_569 -= V_580 ;
if ( ! V_569 )
break;
}
}
V_572 -- ;
if ( V_572 && V_578 > V_572 )
goto V_579;
V_574:
for ( V_19 = 0 ; V_19 < V_469 ; V_19 ++ )
V_520 [ V_19 ] =
F_518 ( V_520 [ V_19 ] , V_151 ) ;
V_56:
V_571 [ V_149 ] = V_570 ;
}
static void F_552 ( T_1 * V_9 , int V_19 )
{
enum V_413 V_413 ;
if ( V_149 == V_582 )
return;
for ( V_413 = 0 ; V_413 <= V_501 - 1 ; V_413 ++ ) {
struct V_43 * V_43 = & V_9 -> V_117 [ V_413 ] ;
if ( F_190 ( V_43 ) ) {
F_547 ( V_19 , V_583 ) ;
if ( V_582 != V_583 &&
V_413 <= V_304 )
F_547 ( V_19 , V_582 ) ;
break;
}
}
}
void T_5 F_553 ( unsigned long * V_216 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_19 ;
memset ( V_517 , 0 ,
sizeof( V_517 ) ) ;
memset ( V_516 , 0 ,
sizeof( V_516 ) ) ;
V_47 = F_545 () ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
if ( V_63 == V_501 )
continue;
V_120 = F_9 ( V_216 [ V_63 ] , V_47 ) ;
V_517 [ V_63 ] = V_47 ;
V_516 [ V_63 ] = V_120 ;
V_47 = V_120 ;
}
memset ( V_520 , 0 , sizeof( V_520 ) ) ;
F_548 () ;
F_73 ( L_97 ) ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
if ( V_63 == V_501 )
continue;
F_73 ( L_98 , V_487 [ V_63 ] ) ;
if ( V_517 [ V_63 ] ==
V_516 [ V_63 ] )
F_336 ( L_99 ) ;
else
F_336 ( L_100 ,
( V_560 ) V_517 [ V_63 ]
<< V_12 ,
( ( V_560 ) V_516 [ V_63 ]
<< V_12 ) - 1 ) ;
}
F_73 ( L_101 ) ;
for ( V_63 = 0 ; V_63 < V_469 ; V_63 ++ ) {
if ( V_520 [ V_63 ] )
F_73 ( L_102 , V_63 ,
( V_560 ) V_520 [ V_63 ] << V_12 ) ;
}
F_73 ( L_103 ) ;
F_188 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_73 ( L_104 , V_19 ,
( V_560 ) V_47 << V_12 ,
( ( V_560 ) V_120 << V_12 ) - 1 ) ;
F_554 () ;
F_540 () ;
F_465 (nid) {
T_1 * V_9 = F_15 ( V_19 ) ;
F_539 ( V_19 , NULL ,
F_544 ( V_19 ) , NULL ) ;
if ( V_9 -> V_532 )
F_547 ( V_19 , V_149 ) ;
F_552 ( V_9 , V_19 ) ;
}
}
static int T_5 F_555 ( char * V_66 , unsigned long * V_584 )
{
unsigned long long V_585 ;
if ( ! V_66 )
return - V_70 ;
V_585 = F_556 ( V_66 , & V_66 ) ;
* V_584 = V_585 >> V_12 ;
F_4 ( ( V_585 >> V_12 ) > V_17 ) ;
return 0 ;
}
static int T_5 F_557 ( char * V_66 )
{
if ( F_558 ( V_66 , L_105 ) ) {
V_500 = true ;
return 0 ;
}
return F_555 ( V_66 , & V_578 ) ;
}
static int T_5 F_559 ( char * V_66 )
{
return F_555 ( V_66 , & V_576 ) ;
}
void F_203 ( struct V_1 * V_1 , long V_105 )
{
F_139 ( & V_586 ) ;
F_21 ( V_1 ) -> V_123 += V_105 ;
V_404 += V_105 ;
#ifdef F_433
if ( F_128 ( V_1 ) )
V_410 += V_105 ;
#endif
F_143 ( & V_586 ) ;
}
unsigned long F_560 ( void * V_118 , void * V_119 , int V_587 , char * V_455 )
{
void * V_588 ;
unsigned long V_392 = 0 ;
V_118 = ( void * ) F_410 ( ( unsigned long ) V_118 ) ;
V_119 = ( void * ) ( ( unsigned long ) V_119 & V_589 ) ;
for ( V_588 = V_118 ; V_588 < V_119 ; V_588 += V_104 , V_392 ++ ) {
if ( ( unsigned int ) V_587 <= 0xFF )
memset ( V_588 , V_587 , V_104 ) ;
F_561 ( F_287 ( V_588 ) ) ;
}
if ( V_392 && V_455 )
F_73 ( L_106 ,
V_455 , V_392 << ( V_12 - 10 ) ) ;
return V_392 ;
}
void F_562 ( struct V_1 * V_1 )
{
F_563 ( V_1 ) ;
V_404 ++ ;
F_21 ( V_1 ) -> V_123 ++ ;
V_410 ++ ;
}
void T_5 F_564 ( const char * V_237 )
{
unsigned long V_590 , V_591 , V_592 , V_593 , V_594 ;
unsigned long V_595 , V_596 ;
V_590 = F_565 () ;
V_591 = V_597 - V_598 ;
V_592 = V_599 - V_600 ;
V_593 = V_601 - V_602 ;
V_594 = V_603 - V_604 ;
V_596 = V_605 - V_606 ;
V_595 = V_607 - V_608 ;
#define F_566 ( V_118 , V_119 , V_155 , V_588 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_566 ( V_606 , V_605 , V_596 ,
V_608 , V_595 ) ;
F_566 ( V_598 , V_597 , V_591 , V_608 , V_595 ) ;
F_566 ( V_600 , V_599 , V_592 , V_606 , V_596 ) ;
F_566 ( V_598 , V_597 , V_591 , V_602 , V_593 ) ;
F_566 ( V_600 , V_599 , V_592 , V_602 , V_593 ) ;
#undef F_566
F_73 ( L_107
#ifdef F_433
L_108
#endif
L_109 ,
F_567 () << ( V_12 - 10 ) ,
V_590 << ( V_12 - 10 ) ,
V_591 >> 10 , V_592 >> 10 , V_593 >> 10 ,
( V_596 + V_595 ) >> 10 , V_594 >> 10 ,
( V_590 - V_404 - V_609 ) << ( V_12 - 10 ) ,
V_609 << ( V_12 - 10 ) ,
#ifdef F_433
V_410 << ( V_12 - 10 ) ,
#endif
V_237 ? L_110 : L_111 , V_237 ? V_237 : L_111 ) ;
}
void T_5 F_568 ( unsigned long V_610 )
{
V_552 = V_610 ;
}
void T_5 F_569 ( unsigned long * V_527 )
{
F_539 ( 0 , V_527 ,
F_570 ( V_611 ) >> V_12 , NULL ) ;
}
static int F_571 ( unsigned int V_204 )
{
F_572 ( V_204 ) ;
F_252 ( V_204 ) ;
F_573 ( V_204 ) ;
F_574 ( V_204 ) ;
return 0 ;
}
void T_5 F_575 ( void )
{
int V_44 ;
V_44 = F_576 ( V_612 ,
L_112 , NULL ,
F_571 ) ;
F_4 ( V_44 < 0 ) ;
}
static void F_577 ( void )
{
struct V_266 * V_9 ;
unsigned long V_613 = 0 ;
enum V_413 V_63 , V_537 ;
F_440 (pgdat) {
V_9 -> V_397 = 0 ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_63 ;
long F_9 = 0 ;
for ( V_537 = V_63 ; V_537 < V_116 ; V_537 ++ ) {
if ( V_43 -> V_260 [ V_537 ] > F_9 )
F_9 = V_43 -> V_260 [ V_537 ] ;
}
F_9 += F_418 ( V_43 ) ;
if ( F_9 > V_43 -> V_123 )
F_9 = V_43 -> V_123 ;
V_9 -> V_397 += F_9 ;
V_613 += F_9 ;
}
}
V_397 = V_613 ;
}
static void F_578 ( void )
{
struct V_266 * V_9 ;
enum V_413 V_537 , V_614 ;
F_440 (pgdat) {
for ( V_537 = 0 ; V_537 < V_116 ; V_537 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_537 ;
unsigned long V_123 = V_43 -> V_123 ;
V_43 -> V_260 [ V_537 ] = 0 ;
V_614 = V_537 ;
while ( V_614 ) {
struct V_43 * V_615 ;
V_614 -- ;
if ( V_616 [ V_614 ] < 1 )
V_616 [ V_614 ] = 1 ;
V_615 = V_9 -> V_117 + V_614 ;
V_615 -> V_260 [ V_537 ] = V_123 /
V_616 [ V_614 ] ;
V_123 += V_615 -> V_123 ;
}
}
}
F_577 () ;
}
static void F_579 ( void )
{
unsigned long V_617 = V_618 >> ( V_12 - 10 ) ;
unsigned long V_619 = 0 ;
struct V_43 * V_43 ;
unsigned long V_37 ;
F_425 (zone) {
if ( ! F_434 ( V_43 ) )
V_619 += V_43 -> V_123 ;
}
F_425 (zone) {
V_560 V_418 ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
V_418 = ( V_560 ) V_617 * V_43 -> V_123 ;
F_580 ( V_418 , V_619 ) ;
if ( F_434 ( V_43 ) ) {
unsigned long V_620 ;
V_620 = V_43 -> V_123 / 1024 ;
V_620 = F_513 ( V_620 , V_621 , 128UL ) ;
V_43 -> V_221 [ V_622 ] = V_620 ;
} else {
V_43 -> V_221 [ V_622 ] = V_418 ;
}
V_418 = F_581 ( V_560 , V_418 >> 2 ,
F_582 ( V_43 -> V_123 ,
V_623 , 10000 ) ) ;
V_43 -> V_221 [ V_396 ] = F_290 ( V_43 ) + V_418 ;
V_43 -> V_221 [ V_624 ] = F_290 ( V_43 ) + V_418 * 2 ;
F_238 ( & V_43 -> V_110 , V_37 ) ;
}
F_577 () ;
}
void F_583 ( void )
{
static F_169 ( V_110 ) ;
F_139 ( & V_110 ) ;
F_579 () ;
F_143 ( & V_110 ) ;
}
int T_2 F_584 ( void )
{
unsigned long V_625 ;
int V_626 ;
V_625 = F_419 () * ( V_104 >> 10 ) ;
V_626 = F_585 ( V_625 * 16 ) ;
if ( V_626 > V_627 ) {
V_618 = V_626 ;
if ( V_618 < 128 )
V_618 = 128 ;
if ( V_618 > 65536 )
V_618 = 65536 ;
} else {
F_335 ( L_113 ,
V_626 , V_627 ) ;
}
F_583 () ;
F_586 () ;
F_578 () ;
#ifdef F_293
F_587 () ;
F_588 () ;
#endif
return 0 ;
}
int F_589 ( struct V_456 * V_457 , int V_458 ,
void T_13 * V_459 , T_12 * V_460 , T_14 * V_461 )
{
int V_628 ;
V_628 = F_590 ( V_457 , V_458 , V_459 , V_460 , V_461 ) ;
if ( V_628 )
return V_628 ;
if ( V_458 ) {
V_627 = V_618 ;
F_583 () ;
}
return 0 ;
}
int F_591 ( struct V_456 * V_457 , int V_458 ,
void T_13 * V_459 , T_12 * V_460 , T_14 * V_461 )
{
int V_628 ;
V_628 = F_590 ( V_457 , V_458 , V_459 , V_460 , V_461 ) ;
if ( V_628 )
return V_628 ;
if ( V_458 )
F_583 () ;
return 0 ;
}
static void F_587 ( void )
{
T_1 * V_9 ;
struct V_43 * V_43 ;
F_440 (pgdat)
V_9 -> V_629 = 0 ;
F_425 (zone)
V_43 -> V_270 -> V_629 += ( V_43 -> V_123 *
V_630 ) / 100 ;
}
int F_592 ( struct V_456 * V_457 , int V_458 ,
void T_13 * V_459 , T_12 * V_460 , T_14 * V_461 )
{
int V_628 ;
V_628 = F_590 ( V_457 , V_458 , V_459 , V_460 , V_461 ) ;
if ( V_628 )
return V_628 ;
F_587 () ;
return 0 ;
}
static void F_588 ( void )
{
T_1 * V_9 ;
struct V_43 * V_43 ;
F_440 (pgdat)
V_9 -> V_631 = 0 ;
F_425 (zone)
V_43 -> V_270 -> V_631 += ( V_43 -> V_123 *
V_632 ) / 100 ;
}
int F_593 ( struct V_456 * V_457 , int V_458 ,
void T_13 * V_459 , T_12 * V_460 , T_14 * V_461 )
{
int V_628 ;
V_628 = F_590 ( V_457 , V_458 , V_459 , V_460 , V_461 ) ;
if ( V_628 )
return V_628 ;
F_588 () ;
return 0 ;
}
int F_594 ( struct V_456 * V_457 , int V_458 ,
void T_13 * V_459 , T_12 * V_460 , T_14 * V_461 )
{
F_590 ( V_457 , V_458 , V_459 , V_460 , V_461 ) ;
F_578 () ;
return 0 ;
}
int F_595 ( struct V_456 * V_457 , int V_458 ,
void T_13 * V_459 , T_12 * V_460 , T_14 * V_461 )
{
struct V_43 * V_43 ;
int V_633 ;
int V_44 ;
F_261 ( & V_634 ) ;
V_633 = V_502 ;
V_44 = F_590 ( V_457 , V_458 , V_459 , V_460 , V_461 ) ;
if ( ! V_458 || V_44 < 0 )
goto V_56;
if ( V_502 &&
V_502 < V_635 ) {
V_502 = V_633 ;
V_44 = - V_70 ;
goto V_56;
}
if ( V_502 == V_633 )
goto V_56;
F_201 (zone) {
unsigned int V_204 ;
F_470 (cpu)
F_494 ( V_43 ,
F_251 ( V_43 -> V_207 , V_204 ) ) ;
}
V_56:
F_269 ( & V_634 ) ;
return V_44 ;
}
static int T_5 F_596 ( char * V_237 )
{
if ( ! V_237 )
return 0 ;
V_636 = F_597 ( V_237 , & V_237 , 0 ) ;
return 1 ;
}
static unsigned long T_5 F_598 ( void )
{
return 0 ;
}
void * T_5 F_599 ( const char * V_637 ,
unsigned long V_638 ,
unsigned long V_639 ,
int V_640 ,
int V_37 ,
unsigned int * V_641 ,
unsigned int * V_642 ,
unsigned long V_643 ,
unsigned long V_644 )
{
unsigned long long F_9 = V_644 ;
unsigned long V_645 , V_155 ;
void * V_457 = NULL ;
T_7 V_158 ;
if ( ! V_639 ) {
V_639 = V_553 ;
V_639 -= F_598 () ;
if ( V_12 < 20 )
V_639 = F_600 ( V_639 , ( 1 << 20 ) / V_104 ) ;
#if V_646 > 32
if ( ! V_644 ) {
unsigned long V_647 ;
for ( V_647 = V_648 ; V_647 < V_639 ;
V_647 <<= V_649 )
V_640 ++ ;
}
#endif
if ( V_640 > V_12 )
V_639 >>= ( V_640 - V_12 ) ;
else
V_639 <<= ( V_12 - V_640 ) ;
if ( F_34 ( V_37 & V_650 ) ) {
F_4 ( ! ( V_37 & V_651 ) ) ;
if ( ! ( V_639 >> * V_641 ) ) {
V_639 = 1UL << * V_641 ;
F_187 ( ! V_639 ) ;
}
} else if ( F_34 ( ( V_639 * V_638 ) < V_104 ) )
V_639 = V_104 / V_638 ;
}
V_639 = F_601 ( V_639 ) ;
if ( F_9 == 0 ) {
F_9 = ( ( unsigned long long ) V_554 << V_12 ) >> 4 ;
F_580 ( F_9 , V_638 ) ;
}
F_9 = F_11 ( F_9 , 0x80000000ULL ) ;
if ( V_639 < V_643 )
V_639 = V_643 ;
if ( V_639 > F_9 )
V_639 = F_9 ;
V_645 = F_602 ( V_639 ) ;
V_158 = ( V_37 & V_652 ) ? V_653 | V_160 : V_653 ;
do {
V_155 = V_638 << V_645 ;
if ( V_37 & V_651 )
V_457 = F_603 ( V_155 , 0 ) ;
else if ( V_636 )
V_457 = F_604 ( V_155 , V_158 , V_654 ) ;
else {
if ( F_413 ( V_155 ) < V_74 ) {
V_457 = F_412 ( V_155 , V_158 ) ;
F_605 ( V_457 , V_155 , 1 , V_158 ) ;
}
}
} while ( ! V_457 && V_155 > V_104 && -- V_645 );
if ( ! V_457 )
F_606 ( L_114 , V_637 ) ;
F_73 ( L_115 ,
V_637 , 1UL << V_645 , F_602 ( V_155 ) - V_12 , V_155 ) ;
if ( V_641 )
* V_641 = V_645 ;
if ( V_642 )
* V_642 = ( 1 << V_645 ) - 1 ;
return V_457 ;
}
bool F_607 ( struct V_43 * V_43 , struct V_1 * V_1 , int V_105 ,
bool V_655 )
{
unsigned long V_18 , V_656 , V_657 ;
int V_114 ;
if ( V_452 ( V_43 ) == V_501 )
return false ;
V_114 = F_102 ( V_1 ) ;
if ( V_114 == V_135 || F_237 ( V_114 ) )
return false ;
V_18 = F_37 ( V_1 ) ;
for ( V_657 = 0 , V_656 = 0 ; V_656 < V_27 ; V_656 ++ ) {
unsigned long V_658 = V_18 + V_656 ;
if ( ! F_43 ( V_658 ) )
continue;
V_1 = F_153 ( V_658 ) ;
if ( F_608 ( V_1 ) ) {
V_656 = F_600 ( V_656 + 1 , 1 << F_56 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_107 ( V_1 ) ) {
if ( F_93 ( V_1 ) )
V_656 += ( 1 << F_90 ( V_1 ) ) - 1 ;
continue;
}
if ( V_655 && F_609 ( V_1 ) )
continue;
if ( F_227 ( V_1 ) )
continue;
if ( ! F_226 ( V_1 ) )
V_657 ++ ;
if ( V_657 > V_105 )
return true ;
}
return false ;
}
bool F_610 ( struct V_1 * V_1 )
{
struct V_43 * V_43 ;
unsigned long V_18 ;
if ( ! F_14 ( F_225 ( V_1 ) ) )
return false ;
V_43 = F_21 ( V_1 ) ;
V_18 = F_37 ( V_1 ) ;
if ( ! F_30 ( V_43 , V_18 ) )
return false ;
return ! F_607 ( V_43 , V_1 , 0 , true ) ;
}
static unsigned long F_611 ( unsigned long V_18 )
{
return V_18 & ~ ( F_581 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_612 ( unsigned long V_18 )
{
return F_177 ( V_18 , F_581 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_613 ( struct V_659 * V_660 ,
unsigned long V_118 , unsigned long V_119 )
{
unsigned long V_661 ;
unsigned long V_18 = V_118 ;
unsigned int V_662 = 0 ;
int V_44 = 0 ;
F_614 () ;
while ( V_18 < V_119 || ! F_140 ( & V_660 -> V_663 ) ) {
if ( F_615 ( V_58 ) ) {
V_44 = - V_664 ;
break;
}
if ( F_140 ( & V_660 -> V_663 ) ) {
V_660 -> V_665 = 0 ;
V_18 = F_616 ( V_660 , V_18 , V_119 ) ;
if ( ! V_18 ) {
V_44 = - V_664 ;
break;
}
V_662 = 0 ;
} else if ( ++ V_662 == 5 ) {
V_44 = V_44 < 0 ? V_44 : - V_666 ;
break;
}
V_661 = F_617 ( V_660 -> V_43 ,
& V_660 -> V_663 ) ;
V_660 -> V_665 -= V_661 ;
V_44 = F_618 ( & V_660 -> V_663 , V_667 ,
NULL , 0 , V_660 -> V_246 , V_668 ) ;
}
if ( V_44 < 0 ) {
F_619 ( & V_660 -> V_663 ) ;
return V_44 ;
}
return 0 ;
}
int F_620 ( unsigned long V_118 , unsigned long V_119 ,
unsigned V_3 , T_7 V_240 )
{
unsigned long V_669 , V_670 ;
unsigned int V_62 ;
int V_44 = 0 ;
struct V_659 V_660 = {
. V_665 = 0 ,
. V_62 = - 1 ,
. V_43 = F_21 ( F_153 ( V_118 ) ) ,
. V_246 = V_671 ,
. V_672 = true ,
. V_240 = F_356 ( V_240 ) ,
} ;
F_78 ( & V_660 . V_663 ) ;
V_44 = F_621 ( F_611 ( V_118 ) ,
F_612 ( V_119 ) , V_3 ,
false ) ;
if ( V_44 )
return V_44 ;
V_44 = F_613 ( & V_660 , V_118 , V_119 ) ;
if ( V_44 && V_44 != - V_666 )
goto V_673;
F_622 () ;
F_258 ( V_660 . V_43 ) ;
V_62 = 0 ;
V_669 = V_118 ;
while ( ! F_93 ( F_153 ( V_669 ) ) ) {
if ( ++ V_62 >= V_74 ) {
V_669 = V_118 ;
break;
}
V_669 &= ~ 0UL << V_62 ;
}
if ( V_669 != V_118 ) {
V_62 = F_90 ( F_153 ( V_669 ) ) ;
if ( V_669 + ( 1UL << V_62 ) <= V_118 )
V_669 = V_118 ;
}
if ( F_623 ( V_669 , V_119 , false ) ) {
F_624 ( L_116 ,
V_674 , V_669 , V_119 ) ;
V_44 = - V_666 ;
goto V_673;
}
V_670 = F_625 ( & V_660 , V_669 , V_119 ) ;
if ( ! V_670 ) {
V_44 = - V_666 ;
goto V_673;
}
if ( V_118 != V_669 )
F_626 ( V_669 , V_118 - V_669 ) ;
if ( V_119 != V_670 )
F_626 ( V_119 , V_670 - V_119 ) ;
V_673:
F_627 ( F_611 ( V_118 ) ,
F_612 ( V_119 ) , V_3 ) ;
return V_44 ;
}
void F_626 ( unsigned long V_18 , unsigned V_64 )
{
unsigned int V_105 = 0 ;
for (; V_64 -- ; V_18 ++ ) {
struct V_1 * V_1 = F_153 ( V_18 ) ;
V_105 += F_92 ( V_1 ) != 1 ;
F_628 ( V_1 ) ;
}
F_629 ( V_105 != 0 , L_117 , V_105 ) ;
}
void T_2 F_630 ( struct V_43 * V_43 )
{
unsigned V_204 ;
F_261 ( & V_634 ) ;
F_470 (cpu)
F_494 ( V_43 ,
F_251 ( V_43 -> V_207 , V_204 ) ) ;
F_269 ( & V_634 ) ;
}
void F_631 ( struct V_43 * V_43 )
{
unsigned long V_37 ;
int V_204 ;
struct V_205 * V_206 ;
F_161 ( V_37 ) ;
if ( V_43 -> V_207 != & V_483 ) {
F_262 (cpu) {
V_206 = F_251 ( V_43 -> V_207 , V_204 ) ;
F_632 ( V_43 , V_206 ) ;
}
F_633 ( V_43 -> V_207 ) ;
V_43 -> V_207 = & V_483 ;
}
F_163 ( V_37 ) ;
}
void
F_634 ( unsigned long V_47 , unsigned long V_120 )
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
F_635 ( V_18 , V_120 ) ;
V_43 = F_21 ( F_153 ( V_18 ) ) ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
V_18 = V_47 ;
while ( V_18 < V_120 ) {
if ( ! F_159 ( V_18 ) ) {
V_18 ++ ;
continue;
}
V_1 = F_153 ( V_18 ) ;
if ( F_34 ( ! F_93 ( V_1 ) && F_609 ( V_1 ) ) ) {
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
bool F_636 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = F_21 ( V_1 ) ;
unsigned long V_18 = F_37 ( V_1 ) ;
unsigned long V_37 ;
unsigned int V_62 ;
F_236 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_1 * V_675 = V_1 - ( V_18 & ( ( 1 << V_62 ) - 1 ) ) ;
if ( F_93 ( V_675 ) && F_90 ( V_675 ) >= V_62 )
break;
}
F_238 ( & V_43 -> V_110 , V_37 ) ;
return V_62 < V_74 ;
}
