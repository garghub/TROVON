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
static int F_44 ( struct V_43 * V_43 , struct V_1 * V_1 )
{
if ( F_36 ( V_43 , V_1 ) )
return 1 ;
if ( ! F_42 ( V_43 , V_1 ) )
return 1 ;
return 0 ;
}
static inline int F_44 ( struct V_43 * V_43 , struct V_1 * V_1 )
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
static int T_4 F_65 ( char * V_69 )
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
static int T_4 F_71 ( char * V_69 )
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
void T_2 F_156 ( T_5 V_118 , T_5 V_119 )
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
static void T_4 F_164 ( struct V_1 * V_1 , unsigned int V_62 )
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
static inline bool T_2 F_171 ( unsigned long V_18 , int V_127 ,
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
static inline bool T_2 F_171 ( unsigned long V_18 , int V_127 ,
struct V_128 * V_129 )
{
return true ;
}
void T_4 F_173 ( struct V_1 * V_1 , unsigned long V_18 ,
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
V_130 = F_153 ( V_47 ) ;
if ( F_21 ( V_130 ) != V_43 )
return NULL ;
V_131 = F_153 ( V_120 ) ;
if ( F_91 ( V_130 ) != F_91 ( V_131 ) )
return NULL ;
return V_130 ;
}
void F_175 ( struct V_43 * V_43 )
{
unsigned long V_132 = V_43 -> V_26 ;
unsigned long V_133 ;
V_133 = F_176 ( V_132 + 1 , V_27 ) ;
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
void F_177 ( struct V_43 * V_43 )
{
V_43 -> V_134 = false ;
}
static void T_4 F_178 ( struct V_1 * V_1 ,
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
static inline void T_4 F_179 ( void )
{
if ( F_180 ( & V_136 ) )
F_181 ( & V_137 ) ;
}
static int T_4 F_182 ( void * V_138 )
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
const struct V_144 * V_144 = F_183 ( V_9 -> V_139 ) ;
if ( V_143 == V_17 ) {
F_179 () ;
return 0 ;
}
if ( ! F_184 ( V_144 ) )
F_185 ( V_58 , V_144 ) ;
F_186 ( V_9 -> V_16 < V_9 -> V_14 ) ;
F_186 ( V_9 -> V_16 > F_17 ( V_9 ) ) ;
V_9 -> V_16 = V_17 ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
V_43 = V_9 -> V_117 + V_115 ;
if ( V_143 < F_155 ( V_43 ) )
break;
}
F_187 (i, nid, &walk_start, &walk_end, NULL) {
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
F_178 ( V_145 ,
V_146 , V_147 ) ;
V_145 = NULL ;
V_146 = V_147 = 0 ;
V_1 = F_153 ( V_18 ) ;
F_188 () ;
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
F_178 ( V_145 , V_146 ,
V_147 ) ;
V_145 = NULL ;
V_146 = V_147 = 0 ;
}
V_64 += V_147 ;
F_178 ( V_145 , V_146 , V_147 ) ;
V_143 = F_9 ( V_120 , V_143 ) ;
}
F_4 ( ++ V_115 < V_116 && F_189 ( ++ V_43 ) ) ;
F_73 ( L_16 , V_19 , V_64 ,
F_190 ( V_55 - V_118 ) ) ;
F_179 () ;
return 0 ;
}
void T_4 F_191 ( void )
{
struct V_43 * V_43 ;
#ifdef F_192
int V_19 ;
F_63 ( & V_136 , F_193 ( V_149 ) ) ;
F_194 (nid, N_MEMORY) {
F_195 ( F_182 , F_15 ( V_19 ) , L_17 , V_19 ) ;
}
F_196 ( & V_137 ) ;
F_197 () ;
#endif
F_198 (zone)
F_175 ( V_43 ) ;
}
void T_4 F_199 ( struct V_1 * V_1 )
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
F_200 ( V_1 , V_27 ) ;
}
static inline void F_201 ( struct V_43 * V_43 , struct V_1 * V_1 ,
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
static void F_202 ( struct V_1 * V_1 )
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
static inline int F_203 ( struct V_1 * V_1 )
{
if ( F_98 ( F_105 ( V_1 ,
V_84 | V_156 ) ) )
return 0 ;
F_202 ( V_1 ) ;
return 1 ;
}
static inline bool F_204 ( void )
{
return F_112 ( V_157 ) &&
F_205 () ;
}
static bool F_206 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_207 ( struct V_1 * V_1 )
{
return F_203 ( V_1 ) ;
}
static bool F_206 ( struct V_1 * V_1 )
{
return F_203 ( V_1 ) ;
}
static bool F_207 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_208 ( struct V_1 * V_1 , unsigned int V_62 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < ( 1 << V_62 ) ; V_63 ++ ) {
struct V_1 * V_66 = V_1 + V_63 ;
if ( F_34 ( F_203 ( V_66 ) ) )
return true ;
}
return false ;
}
inline void F_209 ( struct V_1 * V_1 , unsigned int V_62 ,
T_6 V_158 )
{
F_79 ( V_1 , 0 ) ;
F_167 ( V_1 ) ;
F_210 ( V_1 , V_62 ) ;
F_134 ( V_1 , 1 << V_62 , 1 ) ;
F_133 ( V_1 , 1 << V_62 , 1 ) ;
F_211 ( V_1 , V_62 ) ;
F_212 ( V_1 , V_62 , V_158 ) ;
}
static void F_213 ( struct V_1 * V_1 , unsigned int V_62 , T_6 V_158 ,
unsigned int V_159 )
{
int V_63 ;
F_209 ( V_1 , V_62 , V_158 ) ;
if ( ! F_204 () && ( V_158 & V_160 ) )
for ( V_63 = 0 ; V_63 < ( 1 << V_62 ) ; V_63 ++ )
F_214 ( V_1 + V_63 ) ;
if ( V_62 && ( V_158 & V_161 ) )
F_57 ( V_1 , V_62 ) ;
if ( V_159 & V_162 )
F_215 ( V_1 ) ;
else
F_216 ( V_1 ) ;
}
static inline
struct V_1 * F_217 ( struct V_43 * V_43 , unsigned int V_62 ,
int V_3 )
{
unsigned int V_163 ;
struct V_87 * V_154 ;
struct V_1 * V_1 ;
for ( V_163 = V_62 ; V_163 < V_74 ; ++ V_163 ) {
V_154 = & ( V_43 -> V_87 [ V_163 ] ) ;
V_1 = F_218 ( & V_154 -> V_92 [ V_3 ] ,
struct V_1 , V_78 ) ;
if ( ! V_1 )
continue;
F_100 ( & V_1 -> V_78 ) ;
F_86 ( V_1 ) ;
V_154 -> V_88 -- ;
F_201 ( V_43 , V_1 , V_62 , V_163 , V_154 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_219 ( struct V_43 * V_43 ,
unsigned int V_62 )
{
return F_217 ( V_43 , V_62 , V_150 ) ;
}
static inline struct V_1 * F_219 ( struct V_43 * V_43 ,
unsigned int V_62 ) { return NULL ; }
static int F_220 ( struct V_43 * V_43 ,
struct V_1 * V_130 , struct V_1 * V_131 ,
int V_3 , int * V_164 )
{
struct V_1 * V_1 ;
unsigned int V_62 ;
int V_165 = 0 ;
#ifndef F_221
F_96 ( F_21 ( V_130 ) != F_21 ( V_131 ) ) ;
#endif
if ( V_164 )
* V_164 = 0 ;
for ( V_1 = V_130 ; V_1 <= V_131 ; ) {
if ( ! F_43 ( F_37 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
F_29 ( F_222 ( V_1 ) != F_41 ( V_43 ) , V_1 ) ;
if ( ! F_93 ( V_1 ) ) {
if ( V_164 &&
( F_223 ( V_1 ) || F_224 ( V_1 ) ) )
( * V_164 ) ++ ;
V_1 ++ ;
continue;
}
V_62 = F_90 ( V_1 ) ;
F_225 ( & V_1 -> V_78 ,
& V_43 -> V_87 [ V_62 ] . V_92 [ V_3 ] ) ;
V_1 += 1 << V_62 ;
V_165 += 1 << V_62 ;
}
return V_165 ;
}
int F_226 ( struct V_43 * V_43 , struct V_1 * V_1 ,
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
return F_220 ( V_43 , V_130 , V_131 , V_3 ,
V_164 ) ;
}
static void F_227 ( struct V_1 * V_166 ,
int V_167 , int V_3 )
{
int V_168 = 1 << ( V_167 - V_24 ) ;
while ( V_168 -- ) {
F_33 ( V_166 , V_3 ) ;
V_166 += V_27 ;
}
}
static bool F_228 ( unsigned int V_62 , int V_169 )
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
static void F_229 ( struct V_43 * V_43 , struct V_1 * V_1 ,
int V_171 , bool V_172 )
{
unsigned int V_163 = F_90 ( V_1 ) ;
struct V_87 * V_154 ;
int V_173 , V_174 , V_175 ;
int V_176 ;
V_176 = F_102 ( V_1 ) ;
if ( F_230 ( V_176 ) )
goto V_177;
if ( V_163 >= V_24 ) {
F_227 ( V_1 , V_163 , V_171 ) ;
goto V_177;
}
if ( ! V_172 )
goto V_177;
V_173 = F_226 ( V_43 , V_1 , V_171 ,
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
F_225 ( & V_1 -> V_78 , & V_154 -> V_92 [ V_171 ] ) ;
}
int F_231 ( struct V_87 * V_154 , unsigned int V_62 ,
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
if ( F_228 ( V_62 , V_3 ) )
* V_179 = true ;
if ( ! V_178 )
return V_180 ;
if ( * V_179 )
return V_180 ;
}
return - 1 ;
}
static void F_232 ( struct V_1 * V_1 , struct V_43 * V_43 ,
unsigned int V_183 )
{
int V_114 ;
unsigned long V_184 , V_37 ;
V_184 = ( V_43 -> V_123 / 100 ) + V_27 ;
if ( V_43 -> V_185 >= V_184 )
return;
F_233 ( & V_43 -> V_110 , V_37 ) ;
if ( V_43 -> V_185 >= V_184 )
goto V_186;
V_114 = F_102 ( V_1 ) ;
if ( ! F_230 ( V_114 ) && ! F_83 ( V_114 )
&& ! F_234 ( V_114 ) ) {
V_43 -> V_185 += V_27 ;
F_33 ( V_1 , V_187 ) ;
F_226 ( V_43 , V_1 , V_187 , NULL ) ;
}
V_186:
F_235 ( & V_43 -> V_110 , V_37 ) ;
}
static bool F_236 ( const struct V_188 * V_189 ,
bool V_190 )
{
struct V_191 * V_191 = V_189 -> V_191 ;
unsigned long V_37 ;
struct V_192 * V_193 ;
struct V_43 * V_43 ;
struct V_1 * V_1 ;
int V_62 ;
bool V_44 ;
F_237 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( ! V_190 && V_43 -> V_185 <=
V_27 )
continue;
F_233 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_87 * V_154 = & ( V_43 -> V_87 [ V_62 ] ) ;
V_1 = F_218 (
& V_154 -> V_92 [ V_187 ] ,
struct V_1 , V_78 ) ;
if ( ! V_1 )
continue;
if ( F_238 ( V_1 ) ) {
V_43 -> V_185 -= F_11 (
V_27 ,
V_43 -> V_185 ) ;
}
F_33 ( V_1 , V_189 -> V_3 ) ;
V_44 = F_226 ( V_43 , V_1 , V_189 -> V_3 ,
NULL ) ;
if ( V_44 ) {
F_235 ( & V_43 -> V_110 , V_37 ) ;
return V_44 ;
}
}
F_235 ( & V_43 -> V_110 , V_37 ) ;
}
return false ;
}
static inline bool
F_239 ( struct V_43 * V_43 , unsigned int V_62 , int V_194 )
{
struct V_87 * V_154 ;
unsigned int V_163 ;
struct V_1 * V_1 ;
int V_180 ;
bool V_179 ;
for ( V_163 = V_74 - 1 ;
V_163 >= V_62 && V_163 <= V_74 - 1 ;
-- V_163 ) {
V_154 = & ( V_43 -> V_87 [ V_163 ] ) ;
V_180 = F_231 ( V_154 , V_163 ,
V_194 , false , & V_179 ) ;
if ( V_180 == - 1 )
continue;
V_1 = F_240 ( & V_154 -> V_92 [ V_180 ] ,
struct V_1 , V_78 ) ;
F_229 ( V_43 , V_1 , V_194 ,
V_179 ) ;
F_241 ( V_1 , V_62 , V_163 ,
V_194 , V_180 ) ;
return true ;
}
return false ;
}
static struct V_1 * F_242 ( struct V_43 * V_43 , unsigned int V_62 ,
int V_3 )
{
struct V_1 * V_1 ;
V_195:
V_1 = F_217 ( V_43 , V_62 , V_3 ) ;
if ( F_34 ( ! V_1 ) ) {
if ( V_3 == V_135 )
V_1 = F_219 ( V_43 , V_62 ) ;
if ( ! V_1 && F_239 ( V_43 , V_62 , V_3 ) )
goto V_195;
}
F_243 ( V_1 , V_62 , V_3 ) ;
return V_1 ;
}
static int F_244 ( struct V_43 * V_43 , unsigned int V_62 ,
unsigned long V_105 , struct V_111 * V_112 ,
int V_3 , bool V_196 )
{
int V_63 , V_197 = 0 ;
F_139 ( & V_43 -> V_110 ) ;
for ( V_63 = 0 ; V_63 < V_105 ; ++ V_63 ) {
struct V_1 * V_1 = F_242 ( V_43 , V_62 , V_3 ) ;
if ( F_34 ( V_1 == NULL ) )
break;
if ( F_34 ( F_206 ( V_1 ) ) )
continue;
if ( F_98 ( ! V_196 ) )
F_104 ( & V_1 -> V_78 , V_112 ) ;
else
F_103 ( & V_1 -> V_78 , V_112 ) ;
V_112 = & V_1 -> V_78 ;
V_197 ++ ;
if ( F_234 ( F_1 ( V_1 ) ) )
F_245 ( V_43 , V_198 ,
- ( 1 << V_62 ) ) ;
}
F_245 ( V_43 , V_199 , - ( V_63 << V_62 ) ) ;
F_143 ( & V_43 -> V_110 ) ;
return V_197 ;
}
void F_246 ( struct V_43 * V_43 , struct V_106 * V_107 )
{
unsigned long V_37 ;
int V_200 , V_201 ;
F_161 ( V_37 ) ;
V_201 = F_31 ( V_107 -> V_201 ) ;
V_200 = F_11 ( V_107 -> V_105 , V_201 ) ;
if ( V_200 > 0 ) {
F_138 ( V_43 , V_200 , V_107 ) ;
V_107 -> V_105 -= V_200 ;
}
F_163 ( V_37 ) ;
}
static void F_247 ( unsigned int V_202 , struct V_43 * V_43 )
{
unsigned long V_37 ;
struct V_203 * V_204 ;
struct V_106 * V_107 ;
F_161 ( V_37 ) ;
V_204 = F_248 ( V_43 -> V_205 , V_202 ) ;
V_107 = & V_204 -> V_107 ;
if ( V_107 -> V_105 ) {
F_138 ( V_43 , V_107 -> V_105 , V_107 ) ;
V_107 -> V_105 = 0 ;
}
F_163 ( V_37 ) ;
}
static void F_249 ( unsigned int V_202 )
{
struct V_43 * V_43 ;
F_198 (zone) {
F_247 ( V_202 , V_43 ) ;
}
}
void F_250 ( struct V_43 * V_43 )
{
int V_202 = F_251 () ;
if ( V_43 )
F_247 ( V_202 , V_43 ) ;
else
F_249 ( V_202 ) ;
}
static void F_252 ( struct V_206 * V_207 )
{
F_253 () ;
F_250 ( NULL ) ;
F_254 () ;
}
void F_255 ( struct V_43 * V_43 )
{
int V_202 ;
static T_7 V_208 ;
if ( F_256 ( ! V_209 ) )
return;
if ( V_58 -> V_37 & V_210 )
return;
if ( F_34 ( ! F_257 ( & V_211 ) ) ) {
if ( ! V_43 )
return;
F_258 ( & V_211 ) ;
}
F_259 (cpu) {
struct V_203 * V_107 ;
struct V_43 * V_193 ;
bool V_212 = false ;
if ( V_43 ) {
V_107 = F_248 ( V_43 -> V_205 , V_202 ) ;
if ( V_107 -> V_107 . V_105 )
V_212 = true ;
} else {
F_198 (z) {
V_107 = F_248 ( V_193 -> V_205 , V_202 ) ;
if ( V_107 -> V_107 . V_105 ) {
V_212 = true ;
break;
}
}
}
if ( V_212 )
F_260 ( V_202 , & V_208 ) ;
else
F_261 ( V_202 , & V_208 ) ;
}
F_262 (cpu, &cpus_with_pcps) {
struct V_206 * V_207 = F_248 ( & V_213 , V_202 ) ;
F_263 ( V_207 , F_252 ) ;
F_264 ( V_202 , V_209 , V_207 ) ;
}
F_262 (cpu, &cpus_with_pcps)
F_265 ( F_248 ( & V_213 , V_202 ) ) ;
F_266 ( & V_211 ) ;
}
void F_267 ( struct V_43 * V_43 )
{
unsigned long V_18 , V_214 ;
unsigned long V_37 ;
unsigned int V_62 , V_215 ;
struct V_1 * V_1 ;
if ( F_268 ( V_43 ) )
return;
F_233 ( & V_43 -> V_110 , V_37 ) ;
V_214 = F_155 ( V_43 ) ;
for ( V_18 = V_43 -> V_26 ; V_18 < V_214 ; V_18 ++ )
if ( F_159 ( V_18 ) ) {
V_1 = F_153 ( V_18 ) ;
if ( F_21 ( V_1 ) != V_43 )
continue;
if ( ! F_269 ( V_1 ) )
F_270 ( V_1 ) ;
}
F_271 (order, t) {
F_272 (page,
&zone->free_area[order].free_list[t], lru) {
unsigned long V_63 ;
V_18 = F_37 ( V_1 ) ;
for ( V_63 = 0 ; V_63 < ( 1UL << V_62 ) ; V_63 ++ )
F_273 ( F_153 ( V_18 + V_63 ) ) ;
}
}
F_235 ( & V_43 -> V_110 , V_37 ) ;
}
void F_274 ( struct V_1 * V_1 , bool V_196 )
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
F_275 ( V_121 ) ;
if ( V_3 >= V_40 ) {
if ( F_34 ( F_83 ( V_3 ) ) ) {
F_144 ( V_43 , V_1 , V_18 , 0 , V_3 ) ;
goto V_56;
}
V_3 = V_135 ;
}
V_107 = & F_276 ( V_43 -> V_205 ) -> V_107 ;
if ( ! V_196 )
F_104 ( & V_1 -> V_78 , & V_107 -> V_113 [ V_3 ] ) ;
else
F_103 ( & V_1 -> V_78 , & V_107 -> V_113 [ V_3 ] ) ;
V_107 -> V_105 ++ ;
if ( V_107 -> V_105 >= V_107 -> V_153 ) {
unsigned long V_201 = F_31 ( V_107 -> V_201 ) ;
F_138 ( V_43 , V_201 , V_107 ) ;
V_107 -> V_105 -= V_201 ;
}
V_56:
F_163 ( V_37 ) ;
}
void F_277 ( struct V_111 * V_112 , bool V_196 )
{
struct V_1 * V_1 , * V_216 ;
F_278 (page, next, list, lru) {
F_279 ( V_1 , V_196 ) ;
F_274 ( V_1 , V_196 ) ;
}
}
void F_280 ( struct V_1 * V_1 , unsigned int V_62 )
{
int V_63 ;
F_29 ( F_120 ( V_1 ) , V_1 ) ;
F_29 ( ! F_92 ( V_1 ) , V_1 ) ;
#ifdef F_281
if ( F_282 ( V_1 ) )
F_280 ( F_283 ( V_1 [ 0 ] . V_217 ) , V_62 ) ;
#endif
for ( V_63 = 1 ; V_63 < ( 1 << V_62 ) ; V_63 ++ )
F_167 ( V_1 + V_63 ) ;
F_284 ( V_1 , V_62 ) ;
}
int F_285 ( struct V_1 * V_1 , unsigned int V_62 )
{
unsigned long V_218 ;
struct V_43 * V_43 ;
int V_114 ;
F_186 ( ! F_93 ( V_1 ) ) ;
V_43 = F_21 ( V_1 ) ;
V_114 = F_102 ( V_1 ) ;
if ( ! F_83 ( V_114 ) ) {
V_218 = F_286 ( V_43 ) + ( 1UL << V_62 ) ;
if ( ! F_287 ( V_43 , 0 , V_218 , 0 , V_219 ) )
return 0 ;
F_80 ( V_43 , - ( 1UL << V_62 ) , V_114 ) ;
}
F_100 ( & V_1 -> V_78 ) ;
V_43 -> V_87 [ V_62 ] . V_88 -- ;
F_86 ( V_1 ) ;
if ( V_62 >= V_24 - 1 ) {
struct V_1 * V_220 = V_1 + ( 1 << V_62 ) - 1 ;
for (; V_1 < V_220 ; V_1 += V_27 ) {
int V_114 = F_102 ( V_1 ) ;
if ( ! F_83 ( V_114 ) && ! F_234 ( V_114 )
&& ! F_230 ( V_114 ) )
F_33 ( V_1 ,
V_135 ) ;
}
}
return 1UL << V_62 ;
}
static inline void F_288 ( struct V_43 * V_221 , struct V_43 * V_193 )
{
#ifdef F_289
enum V_222 V_223 = V_224 ;
if ( V_193 -> V_127 != F_290 () )
V_223 = V_225 ;
if ( V_193 -> V_127 == V_221 -> V_127 )
F_291 ( V_193 , V_226 ) ;
else {
F_291 ( V_193 , V_227 ) ;
F_291 ( V_221 , V_228 ) ;
}
F_291 ( V_193 , V_223 ) ;
#endif
}
static struct V_1 * F_292 ( struct V_43 * V_43 , int V_3 ,
bool V_196 , struct V_106 * V_107 ,
struct V_111 * V_112 )
{
struct V_1 * V_1 ;
do {
if ( F_140 ( V_112 ) ) {
V_107 -> V_105 += F_244 ( V_43 , 0 ,
V_107 -> V_201 , V_112 ,
V_3 , V_196 ) ;
if ( F_34 ( F_140 ( V_112 ) ) )
return NULL ;
}
if ( V_196 )
V_1 = F_141 ( V_112 , struct V_1 , V_78 ) ;
else
V_1 = F_240 ( V_112 , struct V_1 , V_78 ) ;
F_100 ( & V_1 -> V_78 ) ;
V_107 -> V_105 -- ;
} while ( F_207 ( V_1 ) );
return V_1 ;
}
static struct V_1 * F_293 ( struct V_43 * V_221 ,
struct V_43 * V_43 , unsigned int V_62 ,
T_6 V_158 , int V_3 )
{
struct V_106 * V_107 ;
struct V_111 * V_112 ;
bool V_196 = ( ( V_158 & V_229 ) != 0 ) ;
struct V_1 * V_1 ;
unsigned long V_37 ;
F_161 ( V_37 ) ;
V_107 = & F_276 ( V_43 -> V_205 ) -> V_107 ;
V_112 = & V_107 -> V_113 [ V_3 ] ;
V_1 = F_292 ( V_43 , V_3 , V_196 , V_107 , V_112 ) ;
if ( V_1 ) {
F_294 ( V_230 , F_295 ( V_1 ) , 1 << V_62 ) ;
F_288 ( V_221 , V_43 ) ;
}
F_163 ( V_37 ) ;
return V_1 ;
}
static inline
struct V_1 * F_296 ( struct V_43 * V_221 ,
struct V_43 * V_43 , unsigned int V_62 ,
T_6 V_158 , unsigned int V_159 ,
int V_3 )
{
unsigned long V_37 ;
struct V_1 * V_1 ;
if ( F_98 ( V_62 == 0 ) ) {
V_1 = F_293 ( V_221 , V_43 , V_62 ,
V_158 , V_3 ) ;
goto V_56;
}
F_256 ( ( V_158 & V_231 ) && ( V_62 > 1 ) ) ;
F_233 ( & V_43 -> V_110 , V_37 ) ;
do {
V_1 = NULL ;
if ( V_159 & V_232 ) {
V_1 = F_217 ( V_43 , V_62 , V_187 ) ;
if ( V_1 )
F_243 ( V_1 , V_62 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_242 ( V_43 , V_62 , V_3 ) ;
} while ( V_1 && F_208 ( V_1 , V_62 ) );
F_143 ( & V_43 -> V_110 ) ;
if ( ! V_1 )
goto V_233;
F_80 ( V_43 , - ( 1 << V_62 ) ,
F_1 ( V_1 ) ) ;
F_294 ( V_230 , F_295 ( V_1 ) , 1 << V_62 ) ;
F_288 ( V_221 , V_43 ) ;
F_163 ( V_37 ) ;
V_56:
F_29 ( V_1 && F_44 ( V_43 , V_1 ) , V_1 ) ;
return V_1 ;
V_233:
F_163 ( V_37 ) ;
return NULL ;
}
static int T_4 F_297 ( char * V_234 )
{
return F_298 ( & V_235 . V_236 , V_234 ) ;
}
static bool F_299 ( T_6 V_237 , unsigned int V_62 )
{
if ( V_62 < V_235 . V_238 )
return false ;
if ( V_237 & V_231 )
return false ;
if ( V_235 . V_239 && ( V_237 & V_240 ) )
return false ;
if ( V_235 . V_241 &&
( V_237 & V_242 ) )
return false ;
return F_300 ( & V_235 . V_236 , 1 << V_62 ) ;
}
static int T_4 F_301 ( void )
{
T_8 V_243 = V_244 | V_245 | V_246 ;
struct V_247 * V_248 ;
V_248 = F_302 ( L_21 , NULL ,
& V_235 . V_236 ) ;
if ( F_303 ( V_248 ) )
return F_304 ( V_248 ) ;
if ( ! F_305 ( L_22 , V_243 , V_248 ,
& V_235 . V_241 ) )
goto V_249;
if ( ! F_305 ( L_23 , V_243 , V_248 ,
& V_235 . V_239 ) )
goto V_249;
if ( ! F_306 ( L_24 , V_243 , V_248 ,
& V_235 . V_238 ) )
goto V_249;
return 0 ;
V_249:
F_307 ( V_248 ) ;
return - V_250 ;
}
static inline bool F_299 ( T_6 V_237 , unsigned int V_62 )
{
return false ;
}
bool F_308 ( struct V_43 * V_193 , unsigned int V_62 , unsigned long V_251 ,
int V_252 , unsigned int V_159 ,
long V_173 )
{
long F_11 = V_251 ;
int V_253 ;
const bool V_254 = ( V_159 & V_232 ) ;
V_173 -= ( 1 << V_62 ) - 1 ;
if ( V_159 & V_255 )
F_11 -= F_11 / 2 ;
if ( F_98 ( ! V_254 ) )
V_173 -= V_193 -> V_185 ;
else
F_11 -= F_11 / 4 ;
#ifdef F_309
if ( ! ( V_159 & V_219 ) )
V_173 -= F_310 ( V_193 , V_198 ) ;
#endif
if ( V_173 <= F_11 + V_193 -> V_256 [ V_252 ] )
return false ;
if ( ! V_62 )
return true ;
for ( V_253 = V_62 ; V_253 < V_74 ; V_253 ++ ) {
struct V_87 * V_154 = & V_193 -> V_87 [ V_253 ] ;
int V_114 ;
if ( ! V_154 -> V_88 )
continue;
if ( V_254 )
return true ;
for ( V_114 = 0 ; V_114 < V_40 ; V_114 ++ ) {
if ( ! F_140 ( & V_154 -> V_92 [ V_114 ] ) )
return true ;
}
#ifdef F_309
if ( ( V_159 & V_219 ) &&
! F_140 ( & V_154 -> V_92 [ V_150 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_287 ( struct V_43 * V_193 , unsigned int V_62 , unsigned long V_251 ,
int V_252 , unsigned int V_159 )
{
return F_308 ( V_193 , V_62 , V_251 , V_252 , V_159 ,
F_310 ( V_193 , V_199 ) ) ;
}
static inline bool F_311 ( struct V_43 * V_193 , unsigned int V_62 ,
unsigned long V_251 , int V_252 , unsigned int V_159 )
{
long V_173 = F_310 ( V_193 , V_199 ) ;
long V_257 = 0 ;
#ifdef F_309
if ( ! ( V_159 & V_219 ) )
V_257 = F_310 ( V_193 , V_198 ) ;
#endif
if ( ! V_62 && ( V_173 - V_257 ) > V_251 + V_193 -> V_256 [ V_252 ] )
return true ;
return F_308 ( V_193 , V_62 , V_251 , V_252 , V_159 ,
V_173 ) ;
}
bool F_312 ( struct V_43 * V_193 , unsigned int V_62 ,
unsigned long V_251 , int V_252 )
{
long V_173 = F_310 ( V_193 , V_199 ) ;
if ( V_193 -> V_258 && V_173 < V_193 -> V_258 )
V_173 = F_313 ( V_193 , V_199 ) ;
return F_308 ( V_193 , V_62 , V_251 , V_252 , 0 ,
V_173 ) ;
}
static bool F_314 ( struct V_43 * V_259 , struct V_43 * V_43 )
{
return F_315 ( F_41 ( V_259 ) , F_41 ( V_43 ) ) <=
V_260 ;
}
static bool F_314 ( struct V_43 * V_259 , struct V_43 * V_43 )
{
return true ;
}
static struct V_1 *
F_316 ( T_6 V_237 , unsigned int V_62 , int V_159 ,
const struct V_188 * V_189 )
{
struct V_192 * V_193 = V_189 -> V_261 ;
struct V_43 * V_43 ;
struct V_262 * V_263 = NULL ;
F_317 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct V_1 * V_1 ;
unsigned long V_251 ;
if ( F_318 () &&
( V_159 & V_264 ) &&
! F_319 ( V_43 , V_237 ) )
continue;
if ( V_189 -> V_265 ) {
if ( V_263 == V_43 -> V_266 )
continue;
if ( ! F_320 ( V_43 -> V_266 ) ) {
V_263 = V_43 -> V_266 ;
continue;
}
}
V_251 = V_43 -> V_218 [ V_159 & V_267 ] ;
if ( ! F_311 ( V_43 , V_62 , V_251 ,
F_321 ( V_189 ) , V_159 ) ) {
int V_44 ;
F_28 ( V_162 < V_268 ) ;
if ( V_159 & V_162 )
goto V_269;
if ( V_270 == 0 ||
! F_314 ( V_189 -> V_261 -> V_43 , V_43 ) )
continue;
V_44 = F_322 ( V_43 -> V_266 , V_237 , V_62 ) ;
switch ( V_44 ) {
case V_271 :
continue;
case V_272 :
continue;
default:
if ( F_287 ( V_43 , V_62 , V_251 ,
F_321 ( V_189 ) , V_159 ) )
goto V_269;
continue;
}
}
V_269:
V_1 = F_296 ( V_189 -> V_261 -> V_43 , V_43 , V_62 ,
V_237 , V_159 , V_189 -> V_3 ) ;
if ( V_1 ) {
F_213 ( V_1 , V_62 , V_237 , V_159 ) ;
if ( F_34 ( V_62 && ( V_159 & V_232 ) ) )
F_232 ( V_1 , V_43 , V_62 ) ;
return V_1 ;
}
}
return NULL ;
}
static inline bool F_323 ( void )
{
bool V_44 = false ;
#if V_273 > 8
V_44 = F_324 () ;
#endif
return V_44 ;
}
static void F_325 ( T_6 V_237 , T_9 * V_274 )
{
unsigned int V_275 = V_276 ;
static F_326 ( V_277 , V_57 , 1 ) ;
if ( F_323 () || ! F_327 ( & V_277 ) )
return;
if ( ! ( V_237 & V_278 ) )
if ( F_328 ( V_279 ) ||
( V_58 -> V_37 & ( V_280 | V_281 ) ) )
V_275 &= ~ V_276 ;
if ( F_324 () || ! ( V_237 & V_242 ) )
V_275 &= ~ V_276 ;
F_329 ( V_275 , V_274 ) ;
}
void F_330 ( T_6 V_237 , T_9 * V_274 , const char * V_282 , ... )
{
struct V_283 V_284 ;
T_10 args ;
static F_326 ( V_285 , V_286 ,
V_287 ) ;
if ( ( V_237 & V_288 ) || ! F_327 ( & V_285 ) )
return;
F_331 ( L_25 , V_58 -> V_59 ) ;
va_start ( args , V_282 ) ;
V_284 . V_282 = V_282 ;
V_284 . V_289 = & args ;
F_332 ( L_26 , & V_284 ) ;
va_end ( args ) ;
F_332 ( L_27 , V_237 , & V_237 ) ;
if ( V_274 )
F_332 ( L_28 , F_333 ( V_274 ) ) ;
else
F_332 ( L_29 ) ;
F_334 () ;
F_51 () ;
F_325 ( V_237 , V_274 ) ;
}
static inline struct V_1 *
F_335 ( T_6 V_237 , unsigned int V_62 ,
unsigned int V_159 ,
const struct V_188 * V_189 )
{
struct V_1 * V_1 ;
V_1 = F_316 ( V_237 , V_62 ,
V_159 | V_264 , V_189 ) ;
if ( ! V_1 )
V_1 = F_316 ( V_237 , V_62 ,
V_159 , V_189 ) ;
return V_1 ;
}
static inline struct V_1 *
F_336 ( T_6 V_237 , unsigned int V_62 ,
const struct V_188 * V_189 , unsigned long * V_290 )
{
struct V_291 V_292 = {
. V_191 = V_189 -> V_191 ,
. V_274 = V_189 -> V_274 ,
. V_293 = NULL ,
. V_237 = V_237 ,
. V_62 = V_62 ,
} ;
struct V_1 * V_1 ;
* V_290 = 0 ;
if ( ! F_257 ( & V_294 ) ) {
* V_290 = 1 ;
F_337 ( 1 ) ;
return NULL ;
}
V_1 = F_316 ( V_237 | V_295 , V_62 ,
V_296 | V_264 , V_189 ) ;
if ( V_1 )
goto V_56;
if ( V_58 -> V_37 & V_297 )
goto V_56;
if ( V_62 > V_298 )
goto V_56;
if ( V_189 -> V_299 < V_300 )
goto V_56;
if ( F_7 () )
goto V_56;
if ( V_237 & V_301 )
goto V_56;
if ( F_338 ( & V_292 ) || F_256 ( V_237 & V_231 ) ) {
* V_290 = 1 ;
if ( V_237 & V_231 )
V_1 = F_335 ( V_237 , V_62 ,
V_162 , V_189 ) ;
}
V_56:
F_266 ( & V_294 ) ;
return V_1 ;
}
static struct V_1 *
F_339 ( T_6 V_237 , unsigned int V_62 ,
unsigned int V_159 , const struct V_188 * V_189 ,
enum V_302 V_303 , enum V_304 * V_304 )
{
struct V_1 * V_1 ;
unsigned int V_305 ;
if ( ! V_62 )
return NULL ;
V_305 = F_340 () ;
* V_304 = F_341 ( V_237 , V_62 , V_159 , V_189 ,
V_303 ) ;
F_342 ( V_305 ) ;
if ( * V_304 <= V_306 )
return NULL ;
F_343 ( V_307 ) ;
V_1 = F_316 ( V_237 , V_62 , V_159 , V_189 ) ;
if ( V_1 ) {
struct V_43 * V_43 = F_21 ( V_1 ) ;
V_43 -> V_308 = false ;
F_344 ( V_43 , V_62 , true ) ;
F_343 ( V_309 ) ;
return V_1 ;
}
F_343 ( V_310 ) ;
F_188 () ;
return NULL ;
}
static inline bool
F_345 ( struct V_188 * V_189 , int V_62 , int V_159 ,
enum V_304 V_304 ,
enum V_302 * V_302 ,
int * V_311 )
{
int V_312 = V_313 ;
int V_314 ;
bool V_44 = false ;
int V_315 = * V_311 ;
enum V_302 V_316 = * V_302 ;
if ( ! V_62 )
return false ;
if ( F_346 ( V_304 ) )
( * V_311 ) ++ ;
if ( F_347 ( V_304 ) )
goto V_317;
if ( F_348 ( V_304 ) ) {
V_44 = F_349 ( V_189 , V_62 , V_159 ) ;
goto V_56;
}
if ( V_62 > V_298 )
V_312 /= 4 ;
if ( * V_311 <= V_312 ) {
V_44 = true ;
goto V_56;
}
V_317:
V_314 = ( V_62 > V_298 ) ?
V_318 : V_319 ;
if ( * V_302 > V_314 ) {
( * V_302 ) -- ;
* V_311 = 0 ;
V_44 = true ;
}
V_56:
F_350 ( V_62 , V_316 , V_304 , V_315 , V_312 , V_44 ) ;
return V_44 ;
}
static inline struct V_1 *
F_339 ( T_6 V_237 , unsigned int V_62 ,
unsigned int V_159 , const struct V_188 * V_189 ,
enum V_302 V_303 , enum V_304 * V_304 )
{
* V_304 = V_320 ;
return NULL ;
}
static inline bool
F_345 ( struct V_188 * V_189 , unsigned int V_62 , int V_159 ,
enum V_304 V_304 ,
enum V_302 * V_302 ,
int * V_311 )
{
struct V_43 * V_43 ;
struct V_192 * V_193 ;
if ( ! V_62 || V_62 > V_298 )
return false ;
F_237 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( F_287 ( V_43 , 0 , F_286 ( V_43 ) ,
F_321 ( V_189 ) , V_159 ) )
return true ;
}
return false ;
}
static int
F_351 ( T_6 V_237 , unsigned int V_62 ,
const struct V_188 * V_189 )
{
struct V_321 V_321 ;
int V_322 ;
unsigned int V_305 ;
F_188 () ;
F_352 () ;
V_305 = F_340 () ;
F_353 ( V_237 ) ;
V_321 . V_323 = 0 ;
V_58 -> V_321 = & V_321 ;
V_322 = F_354 ( V_189 -> V_191 , V_62 , V_237 ,
V_189 -> V_274 ) ;
V_58 -> V_321 = NULL ;
F_355 () ;
F_342 ( V_305 ) ;
F_188 () ;
return V_322 ;
}
static inline struct V_1 *
F_356 ( T_6 V_237 , unsigned int V_62 ,
unsigned int V_159 , const struct V_188 * V_189 ,
unsigned long * V_290 )
{
struct V_1 * V_1 = NULL ;
bool V_324 = false ;
* V_290 = F_351 ( V_237 , V_62 , V_189 ) ;
if ( F_34 ( ! ( * V_290 ) ) )
return NULL ;
V_195:
V_1 = F_316 ( V_237 , V_62 , V_159 , V_189 ) ;
if ( ! V_1 && ! V_324 ) {
F_236 ( V_189 , false ) ;
F_255 ( NULL ) ;
V_324 = true ;
goto V_195;
}
return V_1 ;
}
static void F_357 ( unsigned int V_62 , const struct V_188 * V_189 )
{
struct V_192 * V_193 ;
struct V_43 * V_43 ;
T_1 * V_325 = NULL ;
F_237 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask) {
if ( V_325 != V_43 -> V_266 )
F_358 ( V_43 , V_62 , V_189 -> V_299 ) ;
V_325 = V_43 -> V_266 ;
}
}
static inline unsigned int
F_359 ( T_6 V_237 )
{
unsigned int V_159 = V_326 | V_264 ;
F_28 ( V_327 != ( V_328 T_6 ) V_255 ) ;
V_159 |= ( V_328 int ) ( V_237 & V_327 ) ;
if ( V_237 & V_329 ) {
if ( ! ( V_237 & V_278 ) )
V_159 |= V_232 ;
V_159 &= ~ V_264 ;
} else if ( F_34 ( F_360 ( V_58 ) ) && ! F_324 () )
V_159 |= V_232 ;
#ifdef F_309
if ( F_361 ( V_237 ) == V_135 )
V_159 |= V_219 ;
#endif
return V_159 ;
}
bool F_362 ( T_6 V_237 )
{
if ( F_34 ( V_237 & V_278 ) )
return false ;
if ( V_237 & V_330 )
return true ;
if ( F_363 () && ( V_58 -> V_37 & V_280 ) )
return true ;
if ( ! F_324 () &&
( ( V_58 -> V_37 & V_280 ) ||
F_34 ( F_328 ( V_279 ) ) ) )
return true ;
return false ;
}
static inline bool
F_364 ( T_6 V_237 , unsigned V_62 ,
struct V_188 * V_189 , int V_159 ,
bool V_290 , int * V_331 )
{
struct V_43 * V_43 ;
struct V_192 * V_193 ;
if ( V_290 && V_62 <= V_298 )
* V_331 = 0 ;
else
( * V_331 ) ++ ;
if ( * V_331 > V_332 ) {
return F_236 ( V_189 , true ) ;
}
F_237 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_333 ;
unsigned long V_334 ;
unsigned long V_335 = F_286 ( V_43 ) ;
bool V_336 ;
V_333 = V_334 = F_365 ( V_43 ) ;
V_333 += F_313 ( V_43 , V_199 ) ;
V_336 = F_308 ( V_43 , V_62 , V_335 ,
F_321 ( V_189 ) , V_159 , V_333 ) ;
F_366 ( V_193 , V_62 , V_334 ,
V_333 , V_335 , * V_331 , V_336 ) ;
if ( V_336 ) {
if ( ! V_290 ) {
unsigned long V_337 ;
V_337 = F_313 ( V_43 ,
V_338 ) ;
if ( 2 * V_337 > V_334 ) {
F_367 ( V_339 , V_57 / 10 ) ;
return true ;
}
}
if ( V_58 -> V_37 & V_210 )
F_337 ( 1 ) ;
else
F_188 () ;
return true ;
}
}
return false ;
}
static inline struct V_1 *
F_368 ( T_6 V_237 , unsigned int V_62 ,
struct V_188 * V_189 )
{
bool V_340 = V_237 & V_242 ;
const bool V_341 = V_62 > V_298 ;
struct V_1 * V_1 = NULL ;
unsigned int V_159 ;
unsigned long V_290 ;
enum V_302 V_302 ;
enum V_304 V_304 ;
int V_311 ;
int V_331 ;
unsigned long V_342 = V_55 ;
unsigned int V_343 = 10 * V_57 ;
unsigned int V_344 ;
if ( V_62 >= V_74 ) {
F_256 ( ! ( V_237 & V_288 ) ) ;
return NULL ;
}
if ( F_256 ( ( V_237 & ( V_329 | V_242 ) ) ==
( V_329 | V_242 ) ) )
V_237 &= ~ V_329 ;
V_345:
V_311 = 0 ;
V_331 = 0 ;
V_302 = V_346 ;
V_344 = F_369 () ;
V_159 = F_359 ( V_237 ) ;
V_189 -> V_261 = F_370 ( V_189 -> V_191 ,
V_189 -> V_299 , V_189 -> V_274 ) ;
if ( ! V_189 -> V_261 -> V_43 )
goto V_347;
if ( V_237 & V_348 )
F_357 ( V_62 , V_189 ) ;
V_1 = F_316 ( V_237 , V_62 , V_159 , V_189 ) ;
if ( V_1 )
goto V_349;
if ( V_340 &&
( V_341 ||
( V_62 > 0 && V_189 -> V_3 != V_135 ) )
&& ! F_362 ( V_237 ) ) {
V_1 = F_339 ( V_237 , V_62 ,
V_159 , V_189 ,
V_350 ,
& V_304 ) ;
if ( V_1 )
goto V_349;
if ( V_341 && ( V_237 & V_351 ) ) {
if ( V_304 == V_352 )
goto V_347;
V_302 = V_350 ;
}
}
V_195:
if ( V_237 & V_348 )
F_357 ( V_62 , V_189 ) ;
if ( F_362 ( V_237 ) )
V_159 = V_162 ;
if ( ! ( V_159 & V_264 ) || ( V_159 & V_162 ) ) {
V_189 -> V_191 = F_371 ( F_290 () , V_237 ) ;
V_189 -> V_261 = F_370 ( V_189 -> V_191 ,
V_189 -> V_299 , V_189 -> V_274 ) ;
}
V_1 = F_316 ( V_237 , V_62 , V_159 , V_189 ) ;
if ( V_1 )
goto V_349;
if ( ! V_340 )
goto V_347;
if ( F_372 ( V_55 , V_342 + V_343 ) ) {
F_330 ( V_237 & ~ V_288 , V_189 -> V_274 ,
L_30 ,
F_190 ( V_55 - V_342 ) , V_62 ) ;
V_343 += 10 * V_57 ;
}
if ( V_58 -> V_37 & V_280 )
goto V_347;
V_1 = F_356 ( V_237 , V_62 , V_159 , V_189 ,
& V_290 ) ;
if ( V_1 )
goto V_349;
V_1 = F_339 ( V_237 , V_62 , V_159 , V_189 ,
V_302 , & V_304 ) ;
if ( V_1 )
goto V_349;
if ( V_237 & V_351 )
goto V_347;
if ( V_341 && ! ( V_237 & V_353 ) )
goto V_347;
if ( F_364 ( V_237 , V_62 , V_189 , V_159 ,
V_290 > 0 , & V_331 ) )
goto V_195;
if ( V_290 > 0 &&
F_345 ( V_189 , V_62 , V_159 ,
V_304 , & V_302 ,
& V_311 ) )
goto V_195;
if ( F_373 ( V_344 ) )
goto V_345;
V_1 = F_336 ( V_237 , V_62 , V_189 , & V_290 ) ;
if ( V_1 )
goto V_349;
if ( F_328 ( V_279 ) &&
( V_159 == V_162 ||
( V_237 & V_278 ) ) )
goto V_347;
if ( V_290 ) {
V_331 = 0 ;
goto V_195;
}
V_347:
if ( F_373 ( V_344 ) )
goto V_345;
if ( V_237 & V_231 ) {
if ( F_256 ( ! V_340 ) )
goto V_249;
F_256 ( V_58 -> V_37 & V_280 ) ;
F_256 ( V_62 > V_298 ) ;
V_1 = F_335 ( V_237 , V_62 , V_232 , V_189 ) ;
if ( V_1 )
goto V_349;
F_188 () ;
goto V_195;
}
V_249:
F_330 ( V_237 , V_189 -> V_274 ,
L_31 , V_62 ) ;
V_349:
return V_1 ;
}
static inline bool F_374 ( T_6 V_237 , unsigned int V_62 ,
struct V_191 * V_191 , T_9 * V_274 ,
struct V_188 * V_189 , T_6 * V_354 ,
unsigned int * V_159 )
{
V_189 -> V_299 = F_375 ( V_237 ) ;
V_189 -> V_191 = V_191 ;
V_189 -> V_274 = V_274 ;
V_189 -> V_3 = F_361 ( V_237 ) ;
if ( F_318 () ) {
* V_354 |= V_295 ;
if ( ! V_189 -> V_274 )
V_189 -> V_274 = & V_355 ;
else
* V_159 |= V_264 ;
}
F_376 ( V_237 ) ;
F_377 ( V_237 & V_242 ) ;
if ( F_299 ( V_237 , V_62 ) )
return false ;
if ( F_112 ( F_309 ) && V_189 -> V_3 == V_135 )
* V_159 |= V_219 ;
return true ;
}
static inline void F_378 ( T_6 V_237 ,
unsigned int V_62 , struct V_188 * V_189 )
{
V_189 -> V_265 = ( V_237 & V_356 ) ;
V_189 -> V_261 = F_370 ( V_189 -> V_191 ,
V_189 -> V_299 , V_189 -> V_274 ) ;
}
struct V_1 *
F_379 ( T_6 V_237 , unsigned int V_62 ,
struct V_191 * V_191 , T_9 * V_274 )
{
struct V_1 * V_1 ;
unsigned int V_159 = V_357 ;
T_6 V_354 = V_237 ;
struct V_188 V_189 = { } ;
V_237 &= V_6 ;
if ( ! F_374 ( V_237 , V_62 , V_191 , V_274 , & V_189 , & V_354 , & V_159 ) )
return NULL ;
F_378 ( V_237 , V_62 , & V_189 ) ;
V_1 = F_316 ( V_354 , V_62 , V_159 , & V_189 ) ;
if ( F_98 ( V_1 ) )
goto V_56;
V_354 = F_380 ( V_237 ) ;
V_189 . V_265 = false ;
if ( F_34 ( V_189 . V_274 != V_274 ) )
V_189 . V_274 = V_274 ;
V_1 = F_368 ( V_354 , V_62 , & V_189 ) ;
V_56:
if ( F_123 () && ( V_237 & V_358 ) && V_1 &&
F_34 ( F_381 ( V_1 , V_237 , V_62 ) != 0 ) ) {
F_168 ( V_1 , V_62 ) ;
V_1 = NULL ;
}
if ( V_359 && V_1 )
F_382 ( V_1 , V_62 , V_237 ) ;
F_383 ( V_1 , V_62 , V_354 , V_189 . V_3 ) ;
return V_1 ;
}
unsigned long F_384 ( T_6 V_237 , unsigned int V_62 )
{
struct V_1 * V_1 ;
F_96 ( ( V_237 & V_240 ) != 0 ) ;
V_1 = F_385 ( V_237 , V_62 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_130 ( V_1 ) ;
}
unsigned long F_386 ( T_6 V_237 )
{
return F_384 ( V_237 | V_160 , 0 ) ;
}
void F_168 ( struct V_1 * V_1 , unsigned int V_62 )
{
if ( F_387 ( V_1 ) ) {
if ( V_62 == 0 )
F_274 ( V_1 , false ) ;
else
F_55 ( V_1 , V_62 ) ;
}
}
void V_173 ( unsigned long V_360 , unsigned int V_62 )
{
if ( V_360 != 0 ) {
F_96 ( ! F_388 ( ( void * ) V_360 ) ) ;
F_168 ( F_283 ( ( void * ) V_360 ) , V_62 ) ;
}
}
static struct V_1 * F_389 ( struct V_361 * V_362 ,
T_6 V_237 )
{
struct V_1 * V_1 = NULL ;
T_6 V_363 = V_237 ;
#if ( V_104 < V_364 )
V_237 |= V_161 | V_288 | V_351 |
V_278 ;
V_1 = F_390 ( V_365 , V_237 ,
V_366 ) ;
V_362 -> V_155 = V_1 ? V_364 : V_104 ;
#endif
if ( F_34 ( ! V_1 ) )
V_1 = F_390 ( V_365 , V_363 , 0 ) ;
V_362 -> V_289 = V_1 ? F_130 ( V_1 ) : NULL ;
return V_1 ;
}
void F_391 ( struct V_1 * V_1 , unsigned int V_105 )
{
F_29 ( F_107 ( V_1 ) == 0 , V_1 ) ;
if ( F_392 ( V_1 , V_105 ) ) {
unsigned int V_62 = F_56 ( V_1 ) ;
if ( V_62 == 0 )
F_274 ( V_1 , false ) ;
else
F_55 ( V_1 , V_62 ) ;
}
}
void * F_393 ( struct V_361 * V_362 ,
unsigned int V_367 , T_6 V_237 )
{
unsigned int V_155 = V_104 ;
struct V_1 * V_1 ;
int V_368 ;
if ( F_34 ( ! V_362 -> V_289 ) ) {
V_369:
V_1 = F_389 ( V_362 , V_237 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_104 < V_364 )
V_155 = V_362 -> V_155 ;
#endif
F_394 ( V_1 , V_155 - 1 ) ;
V_362 -> V_370 = F_395 ( V_1 ) ;
V_362 -> V_371 = V_155 ;
V_362 -> V_368 = V_155 ;
}
V_368 = V_362 -> V_368 - V_367 ;
if ( F_34 ( V_368 < 0 ) ) {
V_1 = F_283 ( V_362 -> V_289 ) ;
if ( ! F_392 ( V_1 , V_362 -> V_371 ) )
goto V_369;
#if ( V_104 < V_364 )
V_155 = V_362 -> V_155 ;
#endif
F_61 ( V_1 , V_155 ) ;
V_362 -> V_371 = V_155 ;
V_368 = V_155 - V_367 ;
}
V_362 -> V_371 -- ;
V_362 -> V_368 = V_368 ;
return V_362 -> V_289 + V_368 ;
}
void F_396 ( void * V_360 )
{
struct V_1 * V_1 = F_397 ( V_360 ) ;
if ( F_34 ( F_387 ( V_1 ) ) )
F_55 ( V_1 , F_56 ( V_1 ) ) ;
}
static void * F_398 ( unsigned long V_360 , unsigned int V_62 ,
T_11 V_155 )
{
if ( V_360 ) {
unsigned long V_372 = V_360 + ( V_104 << V_62 ) ;
unsigned long V_373 = V_360 + F_399 ( V_155 ) ;
F_280 ( F_283 ( ( void * ) V_360 ) , V_62 ) ;
while ( V_373 < V_372 ) {
F_400 ( V_373 ) ;
V_373 += V_104 ;
}
}
return ( void * ) V_360 ;
}
void * F_401 ( T_11 V_155 , T_6 V_237 )
{
unsigned int V_62 = F_402 ( V_155 ) ;
unsigned long V_360 ;
V_360 = F_384 ( V_237 , V_62 ) ;
return F_398 ( V_360 , V_62 , V_155 ) ;
}
void * T_2 F_403 ( int V_19 , T_11 V_155 , T_6 V_237 )
{
unsigned int V_62 = F_402 ( V_155 ) ;
struct V_1 * V_66 = F_390 ( V_19 , V_237 , V_62 ) ;
if ( ! V_66 )
return NULL ;
return F_398 ( ( unsigned long ) F_130 ( V_66 ) , V_62 , V_155 ) ;
}
void F_404 ( void * V_374 , T_11 V_155 )
{
unsigned long V_360 = ( unsigned long ) V_374 ;
unsigned long V_119 = V_360 + F_399 ( V_155 ) ;
while ( V_360 < V_119 ) {
F_400 ( V_360 ) ;
V_360 += V_104 ;
}
}
static unsigned long F_405 ( int V_368 )
{
struct V_192 * V_193 ;
struct V_43 * V_43 ;
unsigned long V_375 = 0 ;
struct V_191 * V_191 = F_371 ( F_290 () , V_376 ) ;
F_406 (zone, z, zonelist, offset) {
unsigned long V_155 = V_43 -> V_123 ;
unsigned long V_153 = F_407 ( V_43 ) ;
if ( V_155 > V_153 )
V_375 += V_155 - V_153 ;
}
return V_375 ;
}
unsigned long F_408 ( void )
{
return F_405 ( F_375 ( V_377 ) ) ;
}
unsigned long F_409 ( void )
{
return F_405 ( F_375 ( V_378 ) ) ;
}
static inline void F_410 ( struct V_43 * V_43 )
{
if ( F_112 ( F_289 ) )
F_411 ( L_32 , F_41 ( V_43 ) ) ;
}
long F_412 ( void )
{
long V_333 ;
unsigned long V_379 ;
unsigned long V_380 = 0 ;
unsigned long V_381 [ V_382 ] ;
struct V_43 * V_43 ;
int V_78 ;
for ( V_78 = V_383 ; V_78 < V_382 ; V_78 ++ )
V_381 [ V_78 ] = F_413 ( V_384 + V_78 ) ;
F_414 (zone)
V_380 += V_43 -> V_218 [ V_385 ] ;
V_333 = F_415 ( V_199 ) - V_386 ;
V_379 = V_381 [ V_387 ] + V_381 [ V_388 ] ;
V_379 -= F_11 ( V_379 / 2 , V_380 ) ;
V_333 += V_379 ;
V_333 += F_415 ( V_389 ) -
F_11 ( F_415 ( V_389 ) / 2 , V_380 ) ;
if ( V_333 < 0 )
V_333 = 0 ;
return V_333 ;
}
void F_416 ( struct V_390 * V_391 )
{
V_391 -> V_392 = V_393 ;
V_391 -> V_394 = F_413 ( V_395 ) ;
V_391 -> V_396 = F_415 ( V_199 ) ;
V_391 -> V_397 = F_417 () ;
V_391 -> V_398 = V_399 ;
V_391 -> V_400 = F_418 () ;
V_391 -> V_401 = V_104 ;
}
void F_419 ( struct V_390 * V_391 , int V_19 )
{
int V_402 ;
unsigned long V_123 = 0 ;
unsigned long V_403 = 0 ;
unsigned long V_404 = 0 ;
T_1 * V_9 = F_15 ( V_19 ) ;
for ( V_402 = 0 ; V_402 < V_116 ; V_402 ++ )
V_123 += V_9 -> V_117 [ V_402 ] . V_123 ;
V_391 -> V_392 = V_123 ;
V_391 -> V_394 = F_420 ( V_9 , V_395 ) ;
V_391 -> V_396 = F_421 ( V_19 , V_199 ) ;
#ifdef F_422
for ( V_402 = 0 ; V_402 < V_116 ; V_402 ++ ) {
struct V_43 * V_43 = & V_9 -> V_117 [ V_402 ] ;
if ( F_423 ( V_43 ) ) {
V_403 += V_43 -> V_123 ;
V_404 += F_310 ( V_43 , V_199 ) ;
}
}
V_391 -> V_398 = V_403 ;
V_391 -> V_400 = V_404 ;
#else
V_391 -> V_398 = V_403 ;
V_391 -> V_400 = V_404 ;
#endif
V_391 -> V_401 = V_104 ;
}
static bool F_424 ( unsigned int V_37 , int V_19 , T_9 * V_274 )
{
if ( ! ( V_37 & V_276 ) )
return false ;
if ( ! V_274 )
V_274 = & V_355 ;
return ! F_425 ( V_19 , * V_274 ) ;
}
static void F_426 ( unsigned char type )
{
static const char V_405 [ V_182 ] = {
[ V_41 ] = 'U' ,
[ V_135 ] = 'M' ,
[ V_170 ] = 'E' ,
[ V_187 ] = 'H' ,
#ifdef F_309
[ V_150 ] = 'C' ,
#endif
#ifdef F_427
[ V_406 ] = 'I' ,
#endif
} ;
char V_407 [ V_182 + 1 ] ;
char * V_66 = V_407 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_182 ; V_63 ++ ) {
if ( type & ( 1 << V_63 ) )
* V_66 ++ = V_405 [ V_63 ] ;
}
* V_66 = '\0' ;
F_411 ( V_408 L_33 , V_407 ) ;
}
void F_428 ( unsigned int V_275 , T_9 * V_274 )
{
unsigned long V_409 = 0 ;
int V_202 ;
struct V_43 * V_43 ;
T_1 * V_9 ;
F_198 (zone) {
if ( F_424 ( V_275 , F_41 ( V_43 ) , V_274 ) )
continue;
F_259 (cpu)
V_409 += F_248 ( V_43 -> V_205 , V_202 ) -> V_107 . V_105 ;
}
F_411 ( L_34
L_35
L_36
L_37
L_38
L_39 ,
F_413 ( V_410 ) ,
F_413 ( V_411 ) ,
F_413 ( V_412 ) ,
F_413 ( V_413 ) ,
F_413 ( V_414 ) ,
F_413 ( V_415 ) ,
F_413 ( V_416 ) ,
F_413 ( V_417 ) ,
F_413 ( V_418 ) ,
F_413 ( V_419 ) ,
F_415 ( V_389 ) ,
F_415 ( V_420 ) ,
F_413 ( V_421 ) ,
F_413 ( V_395 ) ,
F_415 ( V_422 ) ,
F_415 ( V_423 ) ,
F_415 ( V_199 ) ,
V_409 ,
F_415 ( V_198 ) ) ;
F_429 (pgdat) {
if ( F_424 ( V_275 , V_9 -> V_139 , V_274 ) )
continue;
F_411 ( L_40
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
#ifdef F_430
L_52
L_53
L_54
#endif
L_55
L_56
L_57
L_58 ,
V_9 -> V_139 ,
F_431 ( F_420 ( V_9 , V_410 ) ) ,
F_431 ( F_420 ( V_9 , V_411 ) ) ,
F_431 ( F_420 ( V_9 , V_413 ) ) ,
F_431 ( F_420 ( V_9 , V_414 ) ) ,
F_431 ( F_420 ( V_9 , V_416 ) ) ,
F_431 ( F_420 ( V_9 , V_412 ) ) ,
F_431 ( F_420 ( V_9 , V_415 ) ) ,
F_431 ( F_420 ( V_9 , V_421 ) ) ,
F_431 ( F_420 ( V_9 , V_417 ) ) ,
F_431 ( F_420 ( V_9 , V_418 ) ) ,
F_431 ( F_420 ( V_9 , V_395 ) ) ,
#ifdef F_430
F_431 ( F_420 ( V_9 , V_424 ) * V_425 ) ,
F_431 ( F_420 ( V_9 , V_426 )
* V_425 ) ,
F_431 ( F_420 ( V_9 , V_427 ) * V_425 ) ,
#endif
F_431 ( F_420 ( V_9 , V_428 ) ) ,
F_431 ( F_420 ( V_9 , V_419 ) ) ,
V_9 -> V_429 >= V_332 ?
L_59 : L_60 ) ;
}
F_198 (zone) {
int V_63 ;
if ( F_424 ( V_275 , F_41 ( V_43 ) , V_274 ) )
continue;
V_409 = 0 ;
F_259 (cpu)
V_409 += F_248 ( V_43 -> V_205 , V_202 ) -> V_107 . V_105 ;
F_410 ( V_43 ) ;
F_411 ( V_408
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
L_76
L_77
L_58 ,
V_43 -> V_49 ,
F_431 ( F_310 ( V_43 , V_199 ) ) ,
F_431 ( F_286 ( V_43 ) ) ,
F_431 ( F_432 ( V_43 ) ) ,
F_431 ( F_407 ( V_43 ) ) ,
F_431 ( F_310 ( V_43 , V_430 ) ) ,
F_431 ( F_310 ( V_43 , V_431 ) ) ,
F_431 ( F_310 ( V_43 , V_432 ) ) ,
F_431 ( F_310 ( V_43 , V_433 ) ) ,
F_431 ( F_310 ( V_43 , V_434 ) ) ,
F_431 ( F_310 ( V_43 , V_338 ) ) ,
F_431 ( V_43 -> V_435 ) ,
F_431 ( V_43 -> V_123 ) ,
F_431 ( F_310 ( V_43 , V_436 ) ) ,
F_431 ( F_310 ( V_43 , V_389 ) ) ,
F_431 ( F_310 ( V_43 , V_420 ) ) ,
F_310 ( V_43 , V_437 ) ,
F_431 ( F_310 ( V_43 , V_422 ) ) ,
F_431 ( F_310 ( V_43 , V_423 ) ) ,
F_431 ( V_409 ) ,
F_431 ( F_433 ( V_43 -> V_205 -> V_107 . V_105 ) ) ,
F_431 ( F_310 ( V_43 , V_198 ) ) ) ;
F_411 ( L_78 ) ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ )
F_411 ( V_408 L_79 , V_43 -> V_256 [ V_63 ] ) ;
F_411 ( V_408 L_58 ) ;
}
F_198 (zone) {
unsigned int V_62 ;
unsigned long V_438 [ V_74 ] , V_37 , V_439 = 0 ;
unsigned char V_405 [ V_74 ] ;
if ( F_424 ( V_275 , F_41 ( V_43 ) , V_274 ) )
continue;
F_410 ( V_43 ) ;
F_411 ( V_408 L_25 , V_43 -> V_49 ) ;
F_233 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_87 * V_154 = & V_43 -> V_87 [ V_62 ] ;
int type ;
V_438 [ V_62 ] = V_154 -> V_88 ;
V_439 += V_438 [ V_62 ] << V_62 ;
V_405 [ V_62 ] = 0 ;
for ( type = 0 ; type < V_182 ; type ++ ) {
if ( ! F_140 ( & V_154 -> V_92 [ type ] ) )
V_405 [ V_62 ] |= 1 << type ;
}
}
F_235 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
F_411 ( V_408 L_80 ,
V_438 [ V_62 ] , F_431 ( 1UL ) << V_62 ) ;
if ( V_438 [ V_62 ] )
F_426 ( V_405 [ V_62 ] ) ;
}
F_411 ( V_408 L_81 , F_431 ( V_439 ) ) ;
}
F_434 () ;
F_411 ( L_82 , F_413 ( V_440 ) ) ;
F_435 () ;
}
static void F_436 ( struct V_43 * V_43 , struct V_192 * V_192 )
{
V_192 -> V_43 = V_43 ;
V_192 -> V_441 = V_441 ( V_43 ) ;
}
static int F_437 ( T_1 * V_9 , struct V_191 * V_191 ,
int V_442 )
{
struct V_43 * V_43 ;
enum V_402 V_402 = V_116 ;
do {
V_402 -- ;
V_43 = V_9 -> V_117 + V_402 ;
if ( F_438 ( V_43 ) ) {
F_436 ( V_43 ,
& V_191 -> V_443 [ V_442 ++ ] ) ;
F_439 ( V_402 ) ;
}
} while ( V_402 );
return V_442 ;
}
static int F_440 ( char * V_444 )
{
if ( * V_444 == 'd' || * V_444 == 'D' ) {
V_445 = V_446 ;
} else if ( * V_444 == 'n' || * V_444 == 'N' ) {
V_445 = V_447 ;
} else if ( * V_444 == 'z' || * V_444 == 'Z' ) {
V_445 = V_448 ;
} else {
F_331 ( L_83 , V_444 ) ;
return - V_70 ;
}
return 0 ;
}
static T_4 int F_441 ( char * V_444 )
{
int V_44 ;
if ( ! V_444 )
return 0 ;
V_44 = F_440 ( V_444 ) ;
if ( V_44 == 0 )
F_442 ( V_449 , V_444 , V_450 ) ;
return V_44 ;
}
int F_443 ( struct V_451 * V_452 , int V_453 ,
void T_12 * V_454 , T_11 * V_455 ,
T_13 * V_456 )
{
char V_457 [ V_450 ] ;
int V_44 ;
static F_444 ( V_458 ) ;
F_258 ( & V_458 ) ;
if ( V_453 ) {
if ( strlen ( ( char * ) V_452 -> V_138 ) >= V_450 ) {
V_44 = - V_70 ;
goto V_56;
}
strcpy ( V_457 , ( char * ) V_452 -> V_138 ) ;
}
V_44 = F_445 ( V_452 , V_453 , V_454 , V_455 , V_456 ) ;
if ( V_44 )
goto V_56;
if ( V_453 ) {
int V_459 = V_445 ;
V_44 = F_440 ( ( char * ) V_452 -> V_138 ) ;
if ( V_44 ) {
strncpy ( ( char * ) V_452 -> V_138 , V_457 ,
V_450 ) ;
V_445 = V_459 ;
} else if ( V_459 != V_445 ) {
F_258 ( & V_460 ) ;
F_446 ( NULL , NULL ) ;
F_266 ( & V_460 ) ;
}
}
V_56:
F_266 ( & V_458 ) ;
return V_44 ;
}
static int F_447 ( int V_127 , T_9 * V_461 )
{
int V_462 , V_391 ;
int V_463 = V_464 ;
int V_465 = V_365 ;
const struct V_144 * V_407 = F_183 ( 0 ) ;
if ( ! F_425 ( V_127 , * V_461 ) ) {
F_448 ( V_127 , * V_461 ) ;
return V_127 ;
}
F_194 (n, N_MEMORY) {
if ( F_425 ( V_462 , * V_461 ) )
continue;
V_391 = F_315 ( V_127 , V_462 ) ;
V_391 += ( V_462 < V_127 ) ;
V_407 = F_183 ( V_462 ) ;
if ( ! F_184 ( V_407 ) )
V_391 += V_466 ;
V_391 *= ( V_467 * V_468 ) ;
V_391 += V_469 [ V_462 ] ;
if ( V_391 < V_463 ) {
V_463 = V_391 ;
V_465 = V_462 ;
}
}
if ( V_465 >= 0 )
F_448 ( V_465 , * V_461 ) ;
return V_465 ;
}
static void F_449 ( T_1 * V_9 , int V_127 )
{
int V_470 ;
struct V_191 * V_191 ;
V_191 = & V_9 -> V_471 [ V_472 ] ;
for ( V_470 = 0 ; V_191 -> V_443 [ V_470 ] . V_43 != NULL ; V_470 ++ )
;
V_470 = F_437 ( F_15 ( V_127 ) , V_191 , V_470 ) ;
V_191 -> V_443 [ V_470 ] . V_43 = NULL ;
V_191 -> V_443 [ V_470 ] . V_441 = 0 ;
}
static void F_450 ( T_1 * V_9 )
{
int V_470 ;
struct V_191 * V_191 ;
V_191 = & V_9 -> V_471 [ V_473 ] ;
V_470 = F_437 ( V_9 , V_191 , 0 ) ;
V_191 -> V_443 [ V_470 ] . V_43 = NULL ;
V_191 -> V_443 [ V_470 ] . V_441 = 0 ;
}
static void F_451 ( T_1 * V_9 , int V_474 )
{
int V_475 , V_470 , V_127 ;
int V_402 ;
struct V_43 * V_193 ;
struct V_191 * V_191 ;
V_191 = & V_9 -> V_471 [ V_472 ] ;
V_475 = 0 ;
for ( V_402 = V_116 - 1 ; V_402 >= 0 ; V_402 -- ) {
for ( V_470 = 0 ; V_470 < V_474 ; V_470 ++ ) {
V_127 = V_476 [ V_470 ] ;
V_193 = & F_15 ( V_127 ) -> V_117 [ V_402 ] ;
if ( F_438 ( V_193 ) ) {
F_436 ( V_193 ,
& V_191 -> V_443 [ V_475 ++ ] ) ;
F_439 ( V_402 ) ;
}
}
}
V_191 -> V_443 [ V_475 ] . V_43 = NULL ;
V_191 -> V_443 [ V_475 ] . V_441 = 0 ;
}
static int F_452 ( void )
{
return V_447 ;
}
static int F_452 ( void )
{
return V_448 ;
}
static void F_453 ( void )
{
if ( V_445 == V_446 )
V_477 = F_452 () ;
else
V_477 = V_445 ;
}
static void F_454 ( T_1 * V_9 )
{
int V_63 , V_127 , V_478 ;
T_9 V_479 ;
int V_480 , V_481 ;
struct V_191 * V_191 ;
unsigned int V_62 = V_477 ;
for ( V_63 = 0 ; V_63 < V_482 ; V_63 ++ ) {
V_191 = V_9 -> V_471 + V_63 ;
V_191 -> V_443 [ 0 ] . V_43 = NULL ;
V_191 -> V_443 [ 0 ] . V_441 = 0 ;
}
V_480 = V_9 -> V_139 ;
V_478 = V_483 ;
V_481 = V_480 ;
F_455 ( V_479 ) ;
memset ( V_476 , 0 , sizeof( V_476 ) ) ;
V_63 = 0 ;
while ( ( V_127 = F_447 ( V_480 , & V_479 ) ) >= 0 ) {
if ( F_315 ( V_480 , V_127 ) !=
F_315 ( V_480 , V_481 ) )
V_469 [ V_127 ] = V_478 ;
V_481 = V_127 ;
V_478 -- ;
if ( V_62 == V_447 )
F_449 ( V_9 , V_127 ) ;
else
V_476 [ V_63 ++ ] = V_127 ;
}
if ( V_62 == V_448 ) {
F_451 ( V_9 , V_63 ) ;
}
F_450 ( V_9 ) ;
}
int F_456 ( int V_127 )
{
struct V_192 * V_193 ;
V_193 = F_370 ( F_371 ( V_127 , V_376 ) ,
F_375 ( V_376 ) ,
NULL ) ;
return V_193 -> V_43 -> V_127 ;
}
static void F_453 ( void )
{
V_477 = V_448 ;
}
static void F_454 ( T_1 * V_9 )
{
int V_127 , V_480 ;
enum V_402 V_470 ;
struct V_191 * V_191 ;
V_480 = V_9 -> V_139 ;
V_191 = & V_9 -> V_471 [ V_472 ] ;
V_470 = F_437 ( V_9 , V_191 , 0 ) ;
for ( V_127 = V_480 + 1 ; V_127 < V_468 ; V_127 ++ ) {
if ( ! F_14 ( V_127 ) )
continue;
V_470 = F_437 ( F_15 ( V_127 ) , V_191 , V_470 ) ;
}
for ( V_127 = 0 ; V_127 < V_480 ; V_127 ++ ) {
if ( ! F_14 ( V_127 ) )
continue;
V_470 = F_437 ( F_15 ( V_127 ) , V_191 , V_470 ) ;
}
V_191 -> V_443 [ V_470 ] . V_43 = NULL ;
V_191 -> V_443 [ V_470 ] . V_441 = 0 ;
}
static int F_457 ( void * V_138 )
{
int V_19 ;
int V_202 ;
T_1 * V_484 = V_138 ;
#ifdef F_289
memset ( V_469 , 0 , sizeof( V_469 ) ) ;
#endif
if ( V_484 && ! F_14 ( V_484 -> V_139 ) ) {
F_454 ( V_484 ) ;
}
F_458 (nid) {
T_1 * V_9 = F_15 ( V_19 ) ;
F_454 ( V_9 ) ;
}
F_459 (cpu) {
F_460 ( & F_461 ( V_485 , V_202 ) , 0 ) ;
#ifdef F_462
if ( F_463 ( V_202 ) )
F_464 ( V_202 , F_456 ( F_465 ( V_202 ) ) ) ;
#endif
}
return 0 ;
}
static T_14 void T_4
F_466 ( void )
{
F_457 ( NULL ) ;
F_467 () ;
F_468 () ;
}
void T_15 F_446 ( T_1 * V_9 , struct V_43 * V_43 )
{
F_453 () ;
if ( V_486 == V_487 ) {
F_466 () ;
} else {
#ifdef F_469
if ( V_43 )
F_470 ( V_43 ) ;
#endif
F_471 ( F_457 , V_9 , NULL ) ;
}
V_488 = F_409 () ;
if ( V_488 < ( V_27 * V_182 ) )
V_39 = 1 ;
else
V_39 = 0 ;
F_73 ( L_84 ,
V_483 ,
V_489 [ V_477 ] ,
V_39 ? L_85 : L_86 ,
V_488 ) ;
#ifdef F_289
F_73 ( L_87 , V_490 [ V_491 ] ) ;
#endif
}
void T_2 F_472 ( unsigned long V_155 , int V_19 , unsigned long V_43 ,
unsigned long V_47 , enum V_492 V_493 )
{
struct V_494 * V_495 = F_473 ( F_474 ( V_47 ) ) ;
unsigned long V_120 = V_47 + V_155 ;
T_1 * V_9 = F_15 ( V_19 ) ;
unsigned long V_18 ;
unsigned long V_21 = 0 ;
#ifdef F_475
struct V_496 * V_497 = NULL , * V_407 ;
#endif
if ( V_498 < V_120 - 1 )
V_498 = V_120 - 1 ;
if ( V_495 && V_47 == V_495 -> V_499 )
V_47 += V_495 -> V_500 ;
for ( V_18 = V_47 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_493 != V_501 )
goto V_502;
if ( ! F_476 ( V_18 ) ) {
#ifdef F_475
V_18 = F_477 ( V_18 , V_120 ) - 1 ;
#endif
continue;
}
if ( ! F_172 ( V_18 , V_19 ) )
continue;
if ( ! F_16 ( V_9 , V_18 , V_120 , & V_21 ) )
break;
#ifdef F_475
if ( V_503 && V_43 == V_504 ) {
if ( ! V_497 || V_18 >= F_478 ( V_497 ) ) {
F_479 (memory, tmp)
if ( V_18 < F_478 ( V_407 ) )
break;
V_497 = V_407 ;
}
if ( V_18 >= F_480 ( V_497 ) &&
F_481 ( V_497 ) ) {
V_18 = F_478 ( V_497 ) ;
continue;
}
}
#endif
V_502:
if ( ! ( V_18 & ( V_27 - 1 ) ) ) {
struct V_1 * V_1 = F_153 ( V_18 ) ;
F_145 ( V_1 , V_18 , V_43 , V_19 ) ;
F_33 ( V_1 , V_135 ) ;
} else {
F_152 ( V_18 , V_43 , V_19 ) ;
}
}
}
static void T_2 F_482 ( struct V_43 * V_43 )
{
unsigned int V_62 , V_215 ;
F_271 (order, t) {
F_78 ( & V_43 -> V_87 [ V_62 ] . V_92 [ V_215 ] ) ;
V_43 -> V_87 [ V_62 ] . V_88 = 0 ;
}
}
static int F_483 ( struct V_43 * V_43 )
{
#ifdef F_484
int V_201 ;
V_201 = V_43 -> V_123 / 1024 ;
if ( V_201 * V_104 > 512 * 1024 )
V_201 = ( 512 * 1024 ) / V_104 ;
V_201 /= 4 ;
if ( V_201 < 1 )
V_201 = 1 ;
V_201 = F_485 ( V_201 + V_201 / 2 ) - 1 ;
return V_201 ;
#else
return 0 ;
#endif
}
static void F_486 ( struct V_106 * V_107 , unsigned long V_153 ,
unsigned long V_201 )
{
V_107 -> V_201 = 1 ;
F_487 () ;
V_107 -> V_153 = V_153 ;
F_487 () ;
V_107 -> V_201 = V_201 ;
}
static void F_488 ( struct V_203 * V_66 , unsigned long V_201 )
{
F_486 ( & V_66 -> V_107 , 6 * V_201 , F_9 ( 1UL , 1 * V_201 ) ) ;
}
static void F_489 ( struct V_203 * V_66 )
{
struct V_106 * V_107 ;
int V_3 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_107 = & V_66 -> V_107 ;
V_107 -> V_105 = 0 ;
for ( V_3 = 0 ; V_3 < V_40 ; V_3 ++ )
F_78 ( & V_107 -> V_113 [ V_3 ] ) ;
}
static void F_460 ( struct V_203 * V_66 , unsigned long V_201 )
{
F_489 ( V_66 ) ;
F_488 ( V_66 , V_201 ) ;
}
static void F_490 ( struct V_203 * V_66 ,
unsigned long V_153 )
{
unsigned long V_201 = F_9 ( 1UL , V_153 / 4 ) ;
if ( ( V_153 / 4 ) > ( V_12 * 8 ) )
V_201 = V_12 * 8 ;
F_486 ( & V_66 -> V_107 , V_153 , V_201 ) ;
}
static void F_491 ( struct V_43 * V_43 ,
struct V_203 * V_107 )
{
if ( V_505 )
F_490 ( V_107 ,
( V_43 -> V_123 /
V_505 ) ) ;
else
F_488 ( V_107 , F_483 ( V_43 ) ) ;
}
static void T_2 F_492 ( struct V_43 * V_43 , int V_202 )
{
struct V_203 * V_107 = F_248 ( V_43 -> V_205 , V_202 ) ;
F_489 ( V_107 ) ;
F_491 ( V_43 , V_107 ) ;
}
static void T_2 F_470 ( struct V_43 * V_43 )
{
int V_202 ;
V_43 -> V_205 = F_493 ( struct V_203 ) ;
F_459 (cpu)
F_492 ( V_43 , V_202 ) ;
}
void T_4 F_494 ( void )
{
struct V_262 * V_9 ;
struct V_43 * V_43 ;
F_198 (zone)
F_470 ( V_43 ) ;
F_429 (pgdat)
V_9 -> V_506 =
F_493 ( struct V_507 ) ;
}
static T_2 void F_495 ( struct V_43 * V_43 )
{
V_43 -> V_205 = & V_485 ;
if ( F_189 ( V_43 ) )
F_411 ( V_508 L_88 ,
V_43 -> V_49 , V_43 -> V_435 ,
F_483 ( V_43 ) ) ;
}
int T_2 F_496 ( struct V_43 * V_43 ,
unsigned long V_26 ,
unsigned long V_155 )
{
struct V_262 * V_9 = V_43 -> V_266 ;
V_9 -> V_442 = V_441 ( V_43 ) + 1 ;
V_43 -> V_26 = V_26 ;
F_497 ( V_509 , L_89 ,
L_90 ,
V_9 -> V_139 ,
( unsigned long ) V_441 ( V_43 ) ,
V_26 , ( V_26 + V_155 ) ) ;
F_482 ( V_43 ) ;
V_43 -> V_510 = 1 ;
return 0 ;
}
int T_2 F_170 ( unsigned long V_18 ,
struct V_128 * V_129 )
{
unsigned long V_47 , V_120 ;
int V_19 ;
if ( V_129 -> V_511 <= V_18 && V_18 < V_129 -> V_512 )
return V_129 -> V_513 ;
V_19 = F_498 ( V_18 , & V_47 , & V_120 ) ;
if ( V_19 != - 1 ) {
V_129 -> V_511 = V_47 ;
V_129 -> V_512 = V_120 ;
V_129 -> V_513 = V_19 ;
}
return V_19 ;
}
void T_4 F_499 ( int V_19 , unsigned long V_514 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_515 ;
F_187 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_47 = F_11 ( V_47 , V_514 ) ;
V_120 = F_11 ( V_120 , V_514 ) ;
if ( V_47 < V_120 )
F_500 ( F_501 ( V_47 ) ,
( V_120 - V_47 ) << V_12 ,
V_515 ) ;
}
}
void T_4 F_502 ( int V_19 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_515 ;
F_187 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_503 ( V_515 , V_47 , V_120 ) ;
}
void T_2 F_504 ( unsigned int V_19 ,
unsigned long * V_47 , unsigned long * V_120 )
{
unsigned long V_516 , V_517 ;
int V_63 ;
* V_47 = - 1UL ;
* V_120 = 0 ;
F_187 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_47 = F_11 ( * V_47 , V_516 ) ;
* V_120 = F_9 ( * V_120 , V_517 ) ;
}
if ( * V_47 == - 1UL )
* V_47 = 0 ;
}
static void T_4 F_505 ( void )
{
int V_518 ;
for ( V_518 = V_116 - 1 ; V_518 >= 0 ; V_518 -- ) {
if ( V_518 == V_504 )
continue;
if ( V_519 [ V_518 ] >
V_520 [ V_518 ] )
break;
}
F_96 ( V_518 == - 1 ) ;
V_521 = V_518 ;
}
static void T_2 F_506 ( int V_19 ,
unsigned long V_402 ,
unsigned long V_14 ,
unsigned long V_522 ,
unsigned long * V_26 ,
unsigned long * F_155 )
{
if ( V_523 [ V_19 ] ) {
if ( V_402 == V_504 ) {
* V_26 = V_523 [ V_19 ] ;
* F_155 = F_11 ( V_522 ,
V_519 [ V_521 ] ) ;
} else if ( ! V_503 &&
* V_26 < V_523 [ V_19 ] &&
* F_155 > V_523 [ V_19 ] ) {
* F_155 = V_523 [ V_19 ] ;
} else if ( * V_26 >= V_523 [ V_19 ] )
* V_26 = * F_155 ;
}
}
static unsigned long T_2 F_507 ( int V_19 ,
unsigned long V_402 ,
unsigned long V_14 ,
unsigned long V_522 ,
unsigned long * V_26 ,
unsigned long * F_155 ,
unsigned long * V_524 )
{
if ( ! V_14 && ! V_522 )
return 0 ;
* V_26 = V_520 [ V_402 ] ;
* F_155 = V_519 [ V_402 ] ;
F_506 ( V_19 , V_402 ,
V_14 , V_522 ,
V_26 , F_155 ) ;
if ( * F_155 < V_14 || * V_26 > V_522 )
return 0 ;
* F_155 = F_11 ( * F_155 , V_522 ) ;
* V_26 = F_9 ( * V_26 , V_14 ) ;
return * F_155 - * V_26 ;
}
unsigned long T_2 F_508 ( int V_19 ,
unsigned long V_525 ,
unsigned long V_526 )
{
unsigned long V_527 = V_526 - V_525 ;
unsigned long V_47 , V_120 ;
int V_63 ;
F_187 (i, nid, &start_pfn, &end_pfn, NULL) {
V_47 = F_509 ( V_47 , V_525 , V_526 ) ;
V_120 = F_509 ( V_120 , V_525 , V_526 ) ;
V_527 -= V_120 - V_47 ;
}
return V_527 ;
}
unsigned long T_4 F_510 ( unsigned long V_47 ,
unsigned long V_120 )
{
return F_508 ( V_468 , V_47 , V_120 ) ;
}
static unsigned long T_2 F_511 ( int V_19 ,
unsigned long V_402 ,
unsigned long V_14 ,
unsigned long V_522 ,
unsigned long * V_524 )
{
unsigned long V_528 = V_520 [ V_402 ] ;
unsigned long V_529 = V_519 [ V_402 ] ;
unsigned long V_26 , F_155 ;
unsigned long V_527 ;
if ( ! V_14 && ! V_522 )
return 0 ;
V_26 = F_509 ( V_14 , V_528 , V_529 ) ;
F_155 = F_509 ( V_522 , V_528 , V_529 ) ;
F_506 ( V_19 , V_402 ,
V_14 , V_522 ,
& V_26 , & F_155 ) ;
V_527 = F_508 ( V_19 , V_26 , F_155 ) ;
if ( V_503 && V_523 [ V_19 ] ) {
unsigned long V_47 , V_120 ;
struct V_496 * V_497 ;
F_479 (memory, r) {
V_47 = F_509 ( F_480 ( V_497 ) ,
V_26 , F_155 ) ;
V_120 = F_509 ( F_478 ( V_497 ) ,
V_26 , F_155 ) ;
if ( V_402 == V_504 &&
F_481 ( V_497 ) )
V_527 += V_120 - V_47 ;
if ( V_402 == V_300 &&
! F_481 ( V_497 ) )
V_527 += V_120 - V_47 ;
}
}
return V_527 ;
}
static inline unsigned long T_2 F_507 ( int V_19 ,
unsigned long V_402 ,
unsigned long V_14 ,
unsigned long V_522 ,
unsigned long * V_26 ,
unsigned long * F_155 ,
unsigned long * V_530 )
{
unsigned int V_43 ;
* V_26 = V_14 ;
for ( V_43 = 0 ; V_43 < V_402 ; V_43 ++ )
* V_26 += V_530 [ V_43 ] ;
* F_155 = * V_26 + V_530 [ V_402 ] ;
return V_530 [ V_402 ] ;
}
static inline unsigned long T_2 F_511 ( int V_19 ,
unsigned long V_402 ,
unsigned long V_14 ,
unsigned long V_522 ,
unsigned long * V_531 )
{
if ( ! V_531 )
return 0 ;
return V_531 [ V_402 ] ;
}
static void T_2 F_512 ( struct V_262 * V_9 ,
unsigned long V_14 ,
unsigned long V_522 ,
unsigned long * V_530 ,
unsigned long * V_531 )
{
unsigned long V_532 = 0 , V_533 = 0 ;
enum V_402 V_63 ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_63 ;
unsigned long V_26 , F_155 ;
unsigned long V_155 , V_534 ;
V_155 = F_507 ( V_9 -> V_139 , V_63 ,
V_14 ,
V_522 ,
& V_26 ,
& F_155 ,
V_530 ) ;
V_534 = V_155 - F_511 ( V_9 -> V_139 , V_63 ,
V_14 , V_522 ,
V_531 ) ;
if ( V_155 )
V_43 -> V_26 = V_26 ;
else
V_43 -> V_26 = 0 ;
V_43 -> V_48 = V_155 ;
V_43 -> V_435 = V_534 ;
V_533 += V_155 ;
V_532 += V_534 ;
}
V_9 -> V_13 = V_533 ;
V_9 -> V_535 = V_532 ;
F_411 ( V_508 L_91 , V_9 -> V_139 ,
V_532 ) ;
}
static unsigned long T_4 F_513 ( unsigned long V_26 , unsigned long V_536 )
{
unsigned long V_537 ;
V_536 += V_26 & ( V_27 - 1 ) ;
V_537 = F_514 ( V_536 , V_27 ) ;
V_537 = V_537 >> V_24 ;
V_537 *= V_25 ;
V_537 = F_514 ( V_537 , 8 * sizeof( unsigned long ) ) ;
return V_537 / 8 ;
}
static void T_4 F_515 ( struct V_262 * V_9 ,
struct V_43 * V_43 ,
unsigned long V_26 ,
unsigned long V_536 )
{
unsigned long V_537 = F_513 ( V_26 , V_536 ) ;
V_43 -> V_23 = NULL ;
if ( V_537 )
V_43 -> V_23 =
F_516 ( V_537 ,
V_9 -> V_139 ) ;
}
static inline void F_515 ( struct V_262 * V_9 , struct V_43 * V_43 ,
unsigned long V_26 , unsigned long V_536 ) {}
void T_16 F_517 ( void )
{
unsigned int V_62 ;
if ( V_24 )
return;
if ( V_538 > V_12 )
V_62 = V_539 ;
else
V_62 = V_74 - 1 ;
V_24 = V_62 ;
}
void T_16 F_517 ( void )
{
}
static unsigned long T_16 F_518 ( unsigned long V_48 ,
unsigned long V_435 )
{
unsigned long V_381 = V_48 ;
if ( V_48 > V_435 + ( V_435 >> 4 ) &&
F_112 ( F_19 ) )
V_381 = V_435 ;
return F_399 ( V_381 * sizeof( struct V_1 ) ) >> V_12 ;
}
static void T_16 F_519 ( struct V_262 * V_9 )
{
enum V_402 V_470 ;
int V_19 = V_9 -> V_139 ;
int V_44 ;
F_520 ( V_9 ) ;
#ifdef F_521
F_522 ( & V_9 -> V_540 ) ;
V_9 -> V_541 = 0 ;
V_9 -> V_542 = V_55 ;
#endif
#ifdef F_430
F_522 ( & V_9 -> V_543 ) ;
F_78 ( & V_9 -> V_544 ) ;
V_9 -> V_545 = 0 ;
#endif
F_523 ( & V_9 -> V_546 ) ;
F_523 ( & V_9 -> V_547 ) ;
#ifdef F_524
F_523 ( & V_9 -> V_548 ) ;
#endif
F_525 ( V_9 ) ;
F_522 ( & V_9 -> V_549 ) ;
F_526 ( F_527 ( V_9 ) ) ;
for ( V_470 = 0 ; V_470 < V_116 ; V_470 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_470 ;
unsigned long V_155 , V_550 , V_551 , V_552 ;
unsigned long V_26 = V_43 -> V_26 ;
V_155 = V_43 -> V_48 ;
V_550 = V_551 = V_43 -> V_435 ;
V_552 = F_518 ( V_155 , V_550 ) ;
if ( ! F_149 ( V_470 ) ) {
if ( V_551 >= V_552 ) {
V_551 -= V_552 ;
if ( V_552 )
F_411 ( V_508
L_92 ,
V_490 [ V_470 ] , V_552 ) ;
} else
F_331 ( L_93 ,
V_490 [ V_470 ] , V_552 , V_551 ) ;
}
if ( V_470 == 0 && V_551 > V_553 ) {
V_551 -= V_553 ;
F_411 ( V_508 L_94 ,
V_490 [ 0 ] , V_553 ) ;
}
if ( ! F_149 ( V_470 ) )
V_554 += V_551 ;
else if ( V_554 > V_552 * 2 )
V_554 -= V_552 ;
V_555 += V_551 ;
V_43 -> V_123 = F_149 ( V_470 ) ? V_550 : V_551 ;
#ifdef F_289
V_43 -> V_127 = V_19 ;
#endif
V_43 -> V_49 = V_490 [ V_470 ] ;
V_43 -> V_266 = V_9 ;
F_522 ( & V_43 -> V_110 ) ;
F_528 ( V_43 ) ;
F_495 ( V_43 ) ;
if ( ! V_155 )
continue;
F_517 () ;
F_515 ( V_9 , V_43 , V_26 , V_155 ) ;
V_44 = F_496 ( V_43 , V_26 , V_155 ) ;
F_186 ( V_44 ) ;
F_529 ( V_155 , V_19 , V_470 , V_26 ) ;
}
}
static void T_15 F_530 ( struct V_262 * V_9 )
{
unsigned long T_17 V_118 = 0 ;
unsigned long T_17 V_368 = 0 ;
if ( ! V_9 -> V_13 )
return;
#ifdef F_531
V_118 = V_9 -> V_14 & ~ ( V_151 - 1 ) ;
V_368 = V_9 -> V_14 - V_118 ;
if ( ! V_9 -> V_556 ) {
unsigned long V_155 , V_119 ;
struct V_1 * V_557 ;
V_119 = F_17 ( V_9 ) ;
V_119 = F_176 ( V_119 , V_151 ) ;
V_155 = ( V_119 - V_118 ) * sizeof( struct V_1 ) ;
V_557 = F_532 ( V_9 -> V_139 , V_155 ) ;
if ( ! V_557 )
V_557 = F_516 ( V_155 ,
V_9 -> V_139 ) ;
V_9 -> V_556 = V_557 + V_368 ;
}
#ifndef F_533
if ( V_9 == F_15 ( 0 ) ) {
V_558 = F_15 ( 0 ) -> V_556 ;
#if F_534 ( F_475 ) || F_534 ( V_559 )
if ( F_37 ( V_558 ) != V_9 -> V_14 )
V_558 -= V_368 ;
#endif
}
#endif
#endif
}
void T_16 F_535 ( int V_19 , unsigned long * V_530 ,
unsigned long V_14 , unsigned long * V_531 )
{
T_1 * V_9 = F_15 ( V_19 ) ;
unsigned long V_47 = 0 ;
unsigned long V_120 = 0 ;
F_4 ( V_9 -> V_442 || V_9 -> V_560 ) ;
V_9 -> V_139 = V_19 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_506 = NULL ;
#ifdef F_475
F_504 ( V_19 , & V_47 , & V_120 ) ;
F_73 ( L_95 , V_19 ,
( V_561 ) V_47 << V_12 ,
V_120 ? ( ( V_561 ) V_120 << V_12 ) - 1 : 0 ) ;
#else
V_47 = V_14 ;
#endif
F_512 ( V_9 , V_47 , V_120 ,
V_530 , V_531 ) ;
F_530 ( V_9 ) ;
#ifdef F_531
F_411 ( V_508 L_96 ,
V_19 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_556 ) ;
#endif
F_8 ( V_9 ) ;
F_519 ( V_9 ) ;
}
void T_4 F_536 ( void )
{
unsigned int V_562 ;
V_562 = F_537 ( V_563 . V_564 , V_468 ) ;
V_565 = V_562 + 1 ;
}
unsigned long T_4 F_538 ( void )
{
unsigned long V_566 = 0 , V_512 = 0 ;
unsigned long V_118 , V_119 , V_29 ;
int V_513 = - 1 ;
int V_63 , V_19 ;
F_187 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_118 || V_513 < 0 || V_513 == V_19 ) {
V_513 = V_19 ;
V_512 = V_119 ;
continue;
}
V_29 = ~ ( ( 1 << F_539 ( V_118 ) ) - 1 ) ;
while ( V_29 && V_512 <= ( V_118 & ( V_29 << 1 ) ) )
V_29 <<= 1 ;
V_566 |= V_29 ;
}
return ~ V_566 + 1 ;
}
static unsigned long T_4 F_540 ( int V_19 )
{
unsigned long V_567 = V_17 ;
unsigned long V_47 ;
int V_63 ;
F_187 (i, nid, &start_pfn, NULL, NULL)
V_567 = F_11 ( V_567 , V_47 ) ;
if ( V_567 == V_17 ) {
F_331 ( L_97 , V_19 ) ;
return 0 ;
}
return V_567 ;
}
unsigned long T_4 F_541 ( void )
{
return F_540 ( V_468 ) ;
}
static unsigned long T_4 F_542 ( void )
{
unsigned long V_533 = 0 ;
unsigned long V_47 , V_120 ;
int V_63 , V_19 ;
F_187 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_381 = V_120 - V_47 ;
V_533 += V_381 ;
if ( V_381 )
F_543 ( V_19 , V_149 ) ;
}
return V_533 ;
}
static void T_4 F_544 ( void )
{
int V_63 , V_19 ;
unsigned long V_568 ;
unsigned long V_569 , V_570 ;
T_9 V_571 = V_572 [ V_149 ] ;
unsigned long V_533 = F_542 () ;
int V_573 = F_545 ( V_572 [ V_149 ] ) ;
struct V_496 * V_497 ;
F_505 () ;
if ( F_546 () ) {
F_479 (memory, r) {
if ( ! F_547 ( V_497 ) )
continue;
V_19 = V_497 -> V_19 ;
V_568 = F_157 ( V_497 -> V_574 ) ;
V_523 [ V_19 ] = V_523 [ V_19 ] ?
F_11 ( V_568 , V_523 [ V_19 ] ) :
V_568 ;
}
goto V_575;
}
if ( V_503 ) {
bool V_576 = false ;
F_479 (memory, r) {
if ( F_481 ( V_497 ) )
continue;
V_19 = V_497 -> V_19 ;
V_568 = F_480 ( V_497 ) ;
if ( V_568 < 0x100000 ) {
V_576 = true ;
continue;
}
V_523 [ V_19 ] = V_523 [ V_19 ] ?
F_11 ( V_568 , V_523 [ V_19 ] ) :
V_568 ;
}
if ( V_576 )
F_331 ( L_98 ) ;
goto V_575;
}
if ( V_577 ) {
unsigned long V_578 ;
V_577 =
F_514 ( V_577 , V_151 ) ;
V_577 = F_11 ( V_533 , V_577 ) ;
V_578 = V_533 - V_577 ;
V_579 = F_9 ( V_579 , V_578 ) ;
}
if ( ! V_579 || V_579 >= V_533 )
goto V_56;
V_568 = V_520 [ V_521 ] ;
V_580:
V_569 = V_579 / V_573 ;
F_194 (nid, N_MEMORY) {
unsigned long V_47 , V_120 ;
if ( V_579 < V_569 )
V_569 = V_579 / V_573 ;
V_570 = V_569 ;
F_187 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_581 ;
V_47 = F_9 ( V_47 , V_523 [ V_19 ] ) ;
if ( V_47 >= V_120 )
continue;
if ( V_47 < V_568 ) {
unsigned long V_582 ;
V_582 = F_11 ( V_120 , V_568 )
- V_47 ;
V_570 -= F_11 ( V_582 ,
V_570 ) ;
V_579 -= F_11 ( V_582 ,
V_579 ) ;
if ( V_120 <= V_568 ) {
V_523 [ V_19 ] = V_120 ;
continue;
}
V_47 = V_568 ;
}
V_581 = V_120 - V_47 ;
if ( V_581 > V_570 )
V_581 = V_570 ;
V_523 [ V_19 ] = V_47 + V_581 ;
V_579 -= F_11 ( V_579 ,
V_581 ) ;
V_570 -= V_581 ;
if ( ! V_570 )
break;
}
}
V_573 -- ;
if ( V_573 && V_579 > V_573 )
goto V_580;
V_575:
for ( V_19 = 0 ; V_19 < V_468 ; V_19 ++ )
V_523 [ V_19 ] =
F_514 ( V_523 [ V_19 ] , V_151 ) ;
V_56:
V_572 [ V_149 ] = V_571 ;
}
static void F_548 ( T_1 * V_9 , int V_19 )
{
enum V_402 V_402 ;
if ( V_149 == V_583 )
return;
for ( V_402 = 0 ; V_402 <= V_504 - 1 ; V_402 ++ ) {
struct V_43 * V_43 = & V_9 -> V_117 [ V_402 ] ;
if ( F_189 ( V_43 ) ) {
F_543 ( V_19 , V_584 ) ;
if ( V_583 != V_584 &&
V_402 <= V_300 )
F_543 ( V_19 , V_583 ) ;
break;
}
}
}
void T_4 F_549 ( unsigned long * V_214 )
{
unsigned long V_47 , V_120 ;
int V_63 , V_19 ;
memset ( V_520 , 0 ,
sizeof( V_520 ) ) ;
memset ( V_519 , 0 ,
sizeof( V_519 ) ) ;
V_47 = F_541 () ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
if ( V_63 == V_504 )
continue;
V_120 = F_9 ( V_214 [ V_63 ] , V_47 ) ;
V_520 [ V_63 ] = V_47 ;
V_519 [ V_63 ] = V_120 ;
V_47 = V_120 ;
}
memset ( V_523 , 0 , sizeof( V_523 ) ) ;
F_544 () ;
F_73 ( L_99 ) ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
if ( V_63 == V_504 )
continue;
F_73 ( L_100 , V_490 [ V_63 ] ) ;
if ( V_520 [ V_63 ] ==
V_519 [ V_63 ] )
F_332 ( L_101 ) ;
else
F_332 ( L_102 ,
( V_561 ) V_520 [ V_63 ]
<< V_12 ,
( ( V_561 ) V_519 [ V_63 ]
<< V_12 ) - 1 ) ;
}
F_73 ( L_103 ) ;
for ( V_63 = 0 ; V_63 < V_468 ; V_63 ++ ) {
if ( V_523 [ V_63 ] )
F_73 ( L_104 , V_63 ,
( V_561 ) V_523 [ V_63 ] << V_12 ) ;
}
F_73 ( L_105 ) ;
F_187 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_73 ( L_106 , V_19 ,
( V_561 ) V_47 << V_12 ,
( ( V_561 ) V_120 << V_12 ) - 1 ) ;
F_550 () ;
F_536 () ;
F_458 (nid) {
T_1 * V_9 = F_15 ( V_19 ) ;
F_535 ( V_19 , NULL ,
F_540 ( V_19 ) , NULL ) ;
if ( V_9 -> V_535 )
F_543 ( V_19 , V_149 ) ;
F_548 ( V_9 , V_19 ) ;
}
}
static int T_4 F_551 ( char * V_66 , unsigned long * V_585 )
{
unsigned long long V_586 ;
if ( ! V_66 )
return - V_70 ;
V_586 = F_552 ( V_66 , & V_66 ) ;
* V_585 = V_586 >> V_12 ;
F_4 ( ( V_586 >> V_12 ) > V_17 ) ;
return 0 ;
}
static int T_4 F_553 ( char * V_66 )
{
if ( F_554 ( V_66 , L_107 ) ) {
V_503 = true ;
return 0 ;
}
return F_551 ( V_66 , & V_579 ) ;
}
static int T_4 F_555 ( char * V_66 )
{
return F_551 ( V_66 , & V_577 ) ;
}
void F_200 ( struct V_1 * V_1 , long V_105 )
{
F_139 ( & V_587 ) ;
F_21 ( V_1 ) -> V_123 += V_105 ;
V_393 += V_105 ;
#ifdef F_422
if ( F_128 ( V_1 ) )
V_399 += V_105 ;
#endif
F_143 ( & V_587 ) ;
}
unsigned long F_556 ( void * V_118 , void * V_119 , int V_588 , char * V_444 )
{
void * V_475 ;
unsigned long V_381 = 0 ;
V_118 = ( void * ) F_399 ( ( unsigned long ) V_118 ) ;
V_119 = ( void * ) ( ( unsigned long ) V_119 & V_589 ) ;
for ( V_475 = V_118 ; V_475 < V_119 ; V_475 += V_104 , V_381 ++ ) {
if ( ( unsigned int ) V_588 <= 0xFF )
memset ( V_475 , V_588 , V_104 ) ;
F_557 ( F_283 ( V_475 ) ) ;
}
if ( V_381 && V_444 )
F_73 ( L_108 ,
V_444 , V_381 << ( V_12 - 10 ) ) ;
return V_381 ;
}
void F_558 ( struct V_1 * V_1 )
{
F_559 ( V_1 ) ;
V_393 ++ ;
F_21 ( V_1 ) -> V_123 ++ ;
V_399 ++ ;
}
void T_4 F_560 ( const char * V_234 )
{
unsigned long V_590 , V_591 , V_592 , V_593 , V_594 ;
unsigned long V_595 , V_596 ;
V_590 = F_561 () ;
V_591 = V_597 - V_598 ;
V_592 = V_599 - V_600 ;
V_593 = V_601 - V_602 ;
V_594 = V_603 - V_604 ;
V_596 = V_605 - V_606 ;
V_595 = V_607 - V_608 ;
#define F_562 ( V_118 , V_119 , V_155 , V_475 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_562 ( V_606 , V_605 , V_596 ,
V_608 , V_595 ) ;
F_562 ( V_598 , V_597 , V_591 , V_608 , V_595 ) ;
F_562 ( V_600 , V_599 , V_592 , V_606 , V_596 ) ;
F_562 ( V_598 , V_597 , V_591 , V_602 , V_593 ) ;
F_562 ( V_600 , V_599 , V_592 , V_602 , V_593 ) ;
#undef F_562
F_73 ( L_109
#ifdef F_422
L_110
#endif
L_111 ,
F_563 () << ( V_12 - 10 ) ,
V_590 << ( V_12 - 10 ) ,
V_591 >> 10 , V_592 >> 10 , V_593 >> 10 ,
( V_596 + V_595 ) >> 10 , V_594 >> 10 ,
( V_590 - V_393 - V_609 ) << ( V_12 - 10 ) ,
V_609 << ( V_12 - 10 ) ,
#ifdef F_422
V_399 << ( V_12 - 10 ) ,
#endif
V_234 ? L_112 : L_113 , V_234 ? V_234 : L_113 ) ;
}
void T_4 F_564 ( unsigned long V_610 )
{
V_553 = V_610 ;
}
void T_4 F_565 ( unsigned long * V_530 )
{
F_535 ( 0 , V_530 ,
F_566 ( V_611 ) >> V_12 , NULL ) ;
}
static int F_567 ( unsigned int V_202 )
{
F_568 ( V_202 ) ;
F_249 ( V_202 ) ;
F_569 ( V_202 ) ;
F_570 ( V_202 ) ;
return 0 ;
}
void T_4 F_571 ( void )
{
int V_44 ;
V_44 = F_572 ( V_612 ,
L_114 , NULL ,
F_567 ) ;
F_4 ( V_44 < 0 ) ;
}
static void F_573 ( void )
{
struct V_262 * V_9 ;
unsigned long V_613 = 0 ;
enum V_402 V_63 , V_470 ;
F_429 (pgdat) {
V_9 -> V_386 = 0 ;
for ( V_63 = 0 ; V_63 < V_116 ; V_63 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_63 ;
long F_9 = 0 ;
for ( V_470 = V_63 ; V_470 < V_116 ; V_470 ++ ) {
if ( V_43 -> V_256 [ V_470 ] > F_9 )
F_9 = V_43 -> V_256 [ V_470 ] ;
}
F_9 += F_407 ( V_43 ) ;
if ( F_9 > V_43 -> V_123 )
F_9 = V_43 -> V_123 ;
V_9 -> V_386 += F_9 ;
V_613 += F_9 ;
}
}
V_386 = V_613 ;
}
static void F_574 ( void )
{
struct V_262 * V_9 ;
enum V_402 V_470 , V_614 ;
F_429 (pgdat) {
for ( V_470 = 0 ; V_470 < V_116 ; V_470 ++ ) {
struct V_43 * V_43 = V_9 -> V_117 + V_470 ;
unsigned long V_123 = V_43 -> V_123 ;
V_43 -> V_256 [ V_470 ] = 0 ;
V_614 = V_470 ;
while ( V_614 ) {
struct V_43 * V_615 ;
V_614 -- ;
if ( V_616 [ V_614 ] < 1 )
V_616 [ V_614 ] = 1 ;
V_615 = V_9 -> V_117 + V_614 ;
V_615 -> V_256 [ V_470 ] = V_123 /
V_616 [ V_614 ] ;
V_123 += V_615 -> V_123 ;
}
}
}
F_573 () ;
}
static void F_575 ( void )
{
unsigned long V_617 = V_618 >> ( V_12 - 10 ) ;
unsigned long V_619 = 0 ;
struct V_43 * V_43 ;
unsigned long V_37 ;
F_414 (zone) {
if ( ! F_423 ( V_43 ) )
V_619 += V_43 -> V_123 ;
}
F_414 (zone) {
V_561 V_407 ;
F_233 ( & V_43 -> V_110 , V_37 ) ;
V_407 = ( V_561 ) V_617 * V_43 -> V_123 ;
F_576 ( V_407 , V_619 ) ;
if ( F_423 ( V_43 ) ) {
unsigned long V_620 ;
V_620 = V_43 -> V_123 / 1024 ;
V_620 = F_509 ( V_620 , V_621 , 128UL ) ;
V_43 -> V_218 [ V_622 ] = V_620 ;
} else {
V_43 -> V_218 [ V_622 ] = V_407 ;
}
V_407 = F_577 ( V_561 , V_407 >> 2 ,
F_578 ( V_43 -> V_123 ,
V_623 , 10000 ) ) ;
V_43 -> V_218 [ V_385 ] = F_286 ( V_43 ) + V_407 ;
V_43 -> V_218 [ V_624 ] = F_286 ( V_43 ) + V_407 * 2 ;
F_235 ( & V_43 -> V_110 , V_37 ) ;
}
F_573 () ;
}
void F_579 ( void )
{
F_258 ( & V_460 ) ;
F_575 () ;
F_266 ( & V_460 ) ;
}
int T_2 F_580 ( void )
{
unsigned long V_625 ;
int V_626 ;
V_625 = F_408 () * ( V_104 >> 10 ) ;
V_626 = F_581 ( V_625 * 16 ) ;
if ( V_626 > V_627 ) {
V_618 = V_626 ;
if ( V_618 < 128 )
V_618 = 128 ;
if ( V_618 > 65536 )
V_618 = 65536 ;
} else {
F_331 ( L_115 ,
V_626 , V_627 ) ;
}
F_579 () ;
F_582 () ;
F_574 () ;
#ifdef F_289
F_583 () ;
F_584 () ;
#endif
return 0 ;
}
int F_585 ( struct V_451 * V_452 , int V_453 ,
void T_12 * V_454 , T_11 * V_455 , T_13 * V_456 )
{
int V_628 ;
V_628 = F_586 ( V_452 , V_453 , V_454 , V_455 , V_456 ) ;
if ( V_628 )
return V_628 ;
if ( V_453 ) {
V_627 = V_618 ;
F_579 () ;
}
return 0 ;
}
int F_587 ( struct V_451 * V_452 , int V_453 ,
void T_12 * V_454 , T_11 * V_455 , T_13 * V_456 )
{
int V_628 ;
V_628 = F_586 ( V_452 , V_453 , V_454 , V_455 , V_456 ) ;
if ( V_628 )
return V_628 ;
if ( V_453 )
F_579 () ;
return 0 ;
}
static void F_583 ( void )
{
T_1 * V_9 ;
struct V_43 * V_43 ;
F_429 (pgdat)
V_9 -> V_629 = 0 ;
F_414 (zone)
V_43 -> V_266 -> V_629 += ( V_43 -> V_123 *
V_630 ) / 100 ;
}
int F_588 ( struct V_451 * V_452 , int V_453 ,
void T_12 * V_454 , T_11 * V_455 , T_13 * V_456 )
{
int V_628 ;
V_628 = F_586 ( V_452 , V_453 , V_454 , V_455 , V_456 ) ;
if ( V_628 )
return V_628 ;
F_583 () ;
return 0 ;
}
static void F_584 ( void )
{
T_1 * V_9 ;
struct V_43 * V_43 ;
F_429 (pgdat)
V_9 -> V_631 = 0 ;
F_414 (zone)
V_43 -> V_266 -> V_631 += ( V_43 -> V_123 *
V_632 ) / 100 ;
}
int F_589 ( struct V_451 * V_452 , int V_453 ,
void T_12 * V_454 , T_11 * V_455 , T_13 * V_456 )
{
int V_628 ;
V_628 = F_586 ( V_452 , V_453 , V_454 , V_455 , V_456 ) ;
if ( V_628 )
return V_628 ;
F_584 () ;
return 0 ;
}
int F_590 ( struct V_451 * V_452 , int V_453 ,
void T_12 * V_454 , T_11 * V_455 , T_13 * V_456 )
{
F_586 ( V_452 , V_453 , V_454 , V_455 , V_456 ) ;
F_574 () ;
return 0 ;
}
int F_591 ( struct V_451 * V_452 , int V_453 ,
void T_12 * V_454 , T_11 * V_455 , T_13 * V_456 )
{
struct V_43 * V_43 ;
int V_633 ;
int V_44 ;
F_258 ( & V_634 ) ;
V_633 = V_505 ;
V_44 = F_586 ( V_452 , V_453 , V_454 , V_455 , V_456 ) ;
if ( ! V_453 || V_44 < 0 )
goto V_56;
if ( V_505 &&
V_505 < V_635 ) {
V_505 = V_633 ;
V_44 = - V_70 ;
goto V_56;
}
if ( V_505 == V_633 )
goto V_56;
F_198 (zone) {
unsigned int V_202 ;
F_459 (cpu)
F_491 ( V_43 ,
F_248 ( V_43 -> V_205 , V_202 ) ) ;
}
V_56:
F_266 ( & V_634 ) ;
return V_44 ;
}
static int T_4 F_592 ( char * V_234 )
{
if ( ! V_234 )
return 0 ;
V_636 = F_593 ( V_234 , & V_234 , 0 ) ;
return 1 ;
}
static unsigned long T_4 F_594 ( void )
{
return 0 ;
}
void * T_4 F_595 ( const char * V_637 ,
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
void * V_452 = NULL ;
if ( ! V_639 ) {
V_639 = V_554 ;
V_639 -= F_594 () ;
if ( V_12 < 20 )
V_639 = F_596 ( V_639 , ( 1 << 20 ) / V_104 ) ;
if ( V_640 > V_12 )
V_639 >>= ( V_640 - V_12 ) ;
else
V_639 <<= ( V_12 - V_640 ) ;
if ( F_34 ( V_37 & V_646 ) ) {
F_4 ( ! ( V_37 & V_647 ) ) ;
if ( ! ( V_639 >> * V_641 ) ) {
V_639 = 1UL << * V_641 ;
F_186 ( ! V_639 ) ;
}
} else if ( F_34 ( ( V_639 * V_638 ) < V_104 ) )
V_639 = V_104 / V_638 ;
}
V_639 = F_597 ( V_639 ) ;
if ( F_9 == 0 ) {
F_9 = ( ( unsigned long long ) V_555 << V_12 ) >> 4 ;
F_576 ( F_9 , V_638 ) ;
}
F_9 = F_11 ( F_9 , 0x80000000ULL ) ;
if ( V_639 < V_643 )
V_639 = V_643 ;
if ( V_639 > F_9 )
V_639 = F_9 ;
V_645 = F_598 ( V_639 ) ;
do {
V_155 = V_638 << V_645 ;
if ( V_37 & V_647 )
V_452 = F_599 ( V_155 , 0 ) ;
else if ( V_636 )
V_452 = F_600 ( V_155 , V_648 , V_649 ) ;
else {
if ( F_402 ( V_155 ) < V_74 ) {
V_452 = F_401 ( V_155 , V_648 ) ;
F_601 ( V_452 , V_155 , 1 , V_648 ) ;
}
}
} while ( ! V_452 && V_155 > V_104 && -- V_645 );
if ( ! V_452 )
F_602 ( L_116 , V_637 ) ;
F_73 ( L_117 ,
V_637 , 1UL << V_645 , F_598 ( V_155 ) - V_12 , V_155 ) ;
if ( V_641 )
* V_641 = V_645 ;
if ( V_642 )
* V_642 = ( 1 << V_645 ) - 1 ;
return V_452 ;
}
bool F_603 ( struct V_43 * V_43 , struct V_1 * V_1 , int V_105 ,
bool V_650 )
{
unsigned long V_18 , V_651 , V_652 ;
int V_114 ;
if ( V_441 ( V_43 ) == V_504 )
return false ;
V_114 = F_102 ( V_1 ) ;
if ( V_114 == V_135 || F_234 ( V_114 ) )
return false ;
V_18 = F_37 ( V_1 ) ;
for ( V_652 = 0 , V_651 = 0 ; V_651 < V_27 ; V_651 ++ ) {
unsigned long V_653 = V_18 + V_651 ;
if ( ! F_43 ( V_653 ) )
continue;
V_1 = F_153 ( V_653 ) ;
if ( F_604 ( V_1 ) ) {
V_651 = F_596 ( V_651 + 1 , 1 << F_56 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_107 ( V_1 ) ) {
if ( F_93 ( V_1 ) )
V_651 += ( 1 << F_90 ( V_1 ) ) - 1 ;
continue;
}
if ( V_650 && F_605 ( V_1 ) )
continue;
if ( F_224 ( V_1 ) )
continue;
if ( ! F_223 ( V_1 ) )
V_652 ++ ;
if ( V_652 > V_105 )
return true ;
}
return false ;
}
bool F_606 ( struct V_1 * V_1 )
{
struct V_43 * V_43 ;
unsigned long V_18 ;
if ( ! F_14 ( F_222 ( V_1 ) ) )
return false ;
V_43 = F_21 ( V_1 ) ;
V_18 = F_37 ( V_1 ) ;
if ( ! F_30 ( V_43 , V_18 ) )
return false ;
return ! F_603 ( V_43 , V_1 , 0 , true ) ;
}
static unsigned long F_607 ( unsigned long V_18 )
{
return V_18 & ~ ( F_577 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_608 ( unsigned long V_18 )
{
return F_176 ( V_18 , F_577 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_609 ( struct V_654 * V_655 ,
unsigned long V_118 , unsigned long V_119 )
{
unsigned long V_656 ;
unsigned long V_18 = V_118 ;
unsigned int V_657 = 0 ;
int V_44 = 0 ;
F_610 () ;
while ( V_18 < V_119 || ! F_140 ( & V_655 -> V_658 ) ) {
if ( F_611 ( V_58 ) ) {
V_44 = - V_659 ;
break;
}
if ( F_140 ( & V_655 -> V_658 ) ) {
V_655 -> V_660 = 0 ;
V_18 = F_612 ( V_655 , V_18 , V_119 ) ;
if ( ! V_18 ) {
V_44 = - V_659 ;
break;
}
V_657 = 0 ;
} else if ( ++ V_657 == 5 ) {
V_44 = V_44 < 0 ? V_44 : - V_661 ;
break;
}
V_656 = F_613 ( V_655 -> V_43 ,
& V_655 -> V_658 ) ;
V_655 -> V_660 -= V_656 ;
V_44 = F_614 ( & V_655 -> V_658 , V_662 ,
NULL , 0 , V_655 -> V_243 , V_663 ) ;
}
if ( V_44 < 0 ) {
F_615 ( & V_655 -> V_658 ) ;
return V_44 ;
}
return 0 ;
}
int F_616 ( unsigned long V_118 , unsigned long V_119 ,
unsigned V_3 , T_6 V_237 )
{
unsigned long V_664 , V_665 ;
unsigned int V_62 ;
int V_44 = 0 ;
struct V_654 V_655 = {
. V_660 = 0 ,
. V_62 = - 1 ,
. V_43 = F_21 ( F_153 ( V_118 ) ) ,
. V_243 = V_666 ,
. V_667 = true ,
. V_237 = F_380 ( V_237 ) ,
} ;
F_78 ( & V_655 . V_658 ) ;
V_44 = F_617 ( F_607 ( V_118 ) ,
F_608 ( V_119 ) , V_3 ,
false ) ;
if ( V_44 )
return V_44 ;
V_44 = F_609 ( & V_655 , V_118 , V_119 ) ;
if ( V_44 && V_44 != - V_661 )
goto V_668;
F_618 () ;
F_255 ( V_655 . V_43 ) ;
V_62 = 0 ;
V_664 = V_118 ;
while ( ! F_93 ( F_153 ( V_664 ) ) ) {
if ( ++ V_62 >= V_74 ) {
V_664 = V_118 ;
break;
}
V_664 &= ~ 0UL << V_62 ;
}
if ( V_664 != V_118 ) {
V_62 = F_90 ( F_153 ( V_664 ) ) ;
if ( V_664 + ( 1UL << V_62 ) <= V_118 )
V_664 = V_118 ;
}
if ( F_619 ( V_664 , V_119 , false ) ) {
F_73 ( L_118 ,
V_669 , V_664 , V_119 ) ;
V_44 = - V_661 ;
goto V_668;
}
V_665 = F_620 ( & V_655 , V_664 , V_119 ) ;
if ( ! V_665 ) {
V_44 = - V_661 ;
goto V_668;
}
if ( V_118 != V_664 )
F_621 ( V_664 , V_118 - V_664 ) ;
if ( V_119 != V_665 )
F_621 ( V_119 , V_665 - V_119 ) ;
V_668:
F_622 ( F_607 ( V_118 ) ,
F_608 ( V_119 ) , V_3 ) ;
return V_44 ;
}
void F_621 ( unsigned long V_18 , unsigned V_64 )
{
unsigned int V_105 = 0 ;
for (; V_64 -- ; V_18 ++ ) {
struct V_1 * V_1 = F_153 ( V_18 ) ;
V_105 += F_92 ( V_1 ) != 1 ;
F_623 ( V_1 ) ;
}
F_624 ( V_105 != 0 , L_119 , V_105 ) ;
}
void T_2 F_625 ( struct V_43 * V_43 )
{
unsigned V_202 ;
F_258 ( & V_634 ) ;
F_459 (cpu)
F_491 ( V_43 ,
F_248 ( V_43 -> V_205 , V_202 ) ) ;
F_266 ( & V_634 ) ;
}
void F_626 ( struct V_43 * V_43 )
{
unsigned long V_37 ;
int V_202 ;
struct V_203 * V_204 ;
F_161 ( V_37 ) ;
if ( V_43 -> V_205 != & V_485 ) {
F_259 (cpu) {
V_204 = F_248 ( V_43 -> V_205 , V_202 ) ;
F_627 ( V_43 , V_204 ) ;
}
F_628 ( V_43 -> V_205 ) ;
V_43 -> V_205 = & V_485 ;
}
F_163 ( V_37 ) ;
}
void
F_629 ( unsigned long V_47 , unsigned long V_120 )
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
V_43 = F_21 ( F_153 ( V_18 ) ) ;
F_233 ( & V_43 -> V_110 , V_37 ) ;
V_18 = V_47 ;
while ( V_18 < V_120 ) {
if ( ! F_159 ( V_18 ) ) {
V_18 ++ ;
continue;
}
V_1 = F_153 ( V_18 ) ;
if ( F_34 ( ! F_93 ( V_1 ) && F_605 ( V_1 ) ) ) {
V_18 ++ ;
F_160 ( V_1 ) ;
continue;
}
F_186 ( F_92 ( V_1 ) ) ;
F_186 ( ! F_93 ( V_1 ) ) ;
V_62 = F_90 ( V_1 ) ;
#ifdef V_100
F_73 ( L_120 ,
V_18 , 1 << V_62 , V_120 ) ;
#endif
F_100 ( & V_1 -> V_78 ) ;
F_86 ( V_1 ) ;
V_43 -> V_87 [ V_62 ] . V_88 -- ;
for ( V_63 = 0 ; V_63 < ( 1 << V_62 ) ; V_63 ++ )
F_160 ( ( V_1 + V_63 ) ) ;
V_18 += ( 1 << V_62 ) ;
}
F_235 ( & V_43 -> V_110 , V_37 ) ;
}
bool F_630 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = F_21 ( V_1 ) ;
unsigned long V_18 = F_37 ( V_1 ) ;
unsigned long V_37 ;
unsigned int V_62 ;
F_233 ( & V_43 -> V_110 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
struct V_1 * V_670 = V_1 - ( V_18 & ( ( 1 << V_62 ) - 1 ) ) ;
if ( F_93 ( V_670 ) && F_90 ( V_670 ) >= V_62 )
break;
}
F_235 ( & V_43 -> V_110 , V_37 ) ;
return V_62 < V_74 ;
}
