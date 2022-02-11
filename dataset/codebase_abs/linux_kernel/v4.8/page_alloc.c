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
return true ;
}
static void F_67 ( void )
{
if ( ! F_66 () )
return;
V_69 = true ;
}
static int T_4 F_68 ( char * V_66 )
{
unsigned long V_70 ;
if ( F_69 ( V_66 , 10 , & V_70 ) < 0 || V_70 > V_71 / 2 ) {
F_38 ( L_5 ) ;
return 0 ;
}
V_72 = V_70 ;
F_70 ( L_6 , V_70 ) ;
return 0 ;
}
static inline void F_71 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 )
{
struct V_73 * V_73 ;
if ( ! F_72 () )
return;
V_73 = F_73 ( V_1 ) ;
if ( F_32 ( ! V_73 ) )
return;
F_74 ( V_74 , & V_73 -> V_34 ) ;
F_75 ( & V_1 -> V_75 ) ;
F_76 ( V_1 , V_59 ) ;
F_77 ( V_40 , - ( 1 << V_59 ) , V_3 ) ;
}
static inline void F_78 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 )
{
struct V_73 * V_73 ;
if ( ! F_72 () )
return;
V_73 = F_73 ( V_1 ) ;
if ( F_32 ( ! V_73 ) )
return;
F_79 ( V_74 , & V_73 -> V_34 ) ;
F_76 ( V_1 , 0 ) ;
if ( ! F_80 ( V_3 ) )
F_77 ( V_40 , ( 1 << V_59 ) , V_3 ) ;
}
static inline void F_71 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 ) {}
static inline void F_78 ( struct V_40 * V_40 , struct V_1 * V_1 ,
unsigned int V_59 , int V_3 ) {}
static inline void F_81 ( struct V_1 * V_1 , unsigned int V_59 )
{
F_76 ( V_1 , V_59 ) ;
F_82 ( V_1 ) ;
}
static inline void F_83 ( struct V_1 * V_1 )
{
F_84 ( V_1 ) ;
F_76 ( V_1 , 0 ) ;
}
static inline int F_85 ( struct V_1 * V_1 , struct V_1 * V_76 ,
unsigned int V_59 )
{
if ( ! F_41 ( F_35 ( V_76 ) ) )
return 0 ;
if ( F_86 ( V_76 ) && F_87 ( V_76 ) == V_59 ) {
if ( F_88 ( V_1 ) != F_88 ( V_76 ) )
return 0 ;
F_27 ( F_89 ( V_76 ) != 0 , V_76 ) ;
return 1 ;
}
if ( F_90 ( V_76 ) && F_87 ( V_76 ) == V_59 ) {
if ( F_88 ( V_1 ) != F_88 ( V_76 ) )
return 0 ;
F_27 ( F_89 ( V_76 ) != 0 , V_76 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_91 ( struct V_1 * V_1 ,
unsigned long V_12 ,
struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
unsigned long V_77 ;
unsigned long V_78 ;
unsigned long V_79 ( V_80 ) ;
struct V_1 * V_76 ;
unsigned int V_81 ;
V_81 = F_92 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
F_93 ( ! F_94 ( V_40 ) ) ;
F_27 ( V_1 -> V_34 & V_82 , V_1 ) ;
F_93 ( V_3 == - 1 ) ;
if ( F_95 ( ! F_80 ( V_3 ) ) )
F_77 ( V_40 , 1 << V_59 , V_3 ) ;
V_77 = V_12 & ( ( 1 << V_71 ) - 1 ) ;
F_27 ( V_77 & ( ( 1 << V_59 ) - 1 ) , V_1 ) ;
F_27 ( F_42 ( V_40 , V_1 ) , V_1 ) ;
V_83:
while ( V_59 < V_81 - 1 ) {
V_80 = F_96 ( V_77 , V_59 ) ;
V_76 = V_1 + ( V_80 - V_77 ) ;
if ( ! F_85 ( V_1 , V_76 , V_59 ) )
goto V_84;
if ( F_86 ( V_76 ) ) {
F_78 ( V_40 , V_76 , V_59 , V_3 ) ;
} else {
F_97 ( & V_76 -> V_75 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
F_83 ( V_76 ) ;
}
V_78 = V_80 & V_77 ;
V_1 = V_1 + ( V_78 - V_77 ) ;
V_77 = V_78 ;
V_59 ++ ;
}
if ( V_81 < V_71 ) {
if ( F_32 ( F_98 ( V_40 ) ) ) {
int V_87 ;
V_80 = F_96 ( V_77 , V_59 ) ;
V_76 = V_1 + ( V_80 - V_77 ) ;
V_87 = F_99 ( V_76 ) ;
if ( V_3 != V_87
&& ( F_80 ( V_3 ) ||
F_80 ( V_87 ) ) )
goto V_84;
}
V_81 ++ ;
goto V_83;
}
V_84:
F_81 ( V_1 , V_59 ) ;
if ( ( V_59 < V_71 - 2 ) && F_41 ( F_35 ( V_76 ) ) ) {
struct V_1 * V_88 , * V_89 ;
V_78 = V_80 & V_77 ;
V_88 = V_1 + ( V_78 - V_77 ) ;
V_80 = F_96 ( V_78 , V_59 + 1 ) ;
V_89 = V_88 + ( V_80 - V_78 ) ;
if ( F_85 ( V_88 , V_89 , V_59 + 1 ) ) {
F_100 ( & V_1 -> V_75 ,
& V_40 -> V_85 [ V_59 ] . V_90 [ V_3 ] ) ;
goto V_53;
}
}
F_101 ( & V_1 -> V_75 , & V_40 -> V_85 [ V_59 ] . V_90 [ V_3 ] ) ;
V_53:
V_40 -> V_85 [ V_59 ] . V_86 ++ ;
}
static inline bool F_102 ( struct V_1 * V_1 ,
unsigned long V_91 )
{
if ( F_32 ( F_103 ( & V_1 -> V_92 ) != - 1 ) )
return false ;
if ( F_32 ( ( unsigned long ) V_1 -> V_64 |
F_104 ( V_1 ) |
#ifdef F_105
( unsigned long ) V_1 -> V_93 |
#endif
( V_1 -> V_34 & V_91 ) ) )
return false ;
return true ;
}
static void F_106 ( struct V_1 * V_1 )
{
const char * V_94 ;
unsigned long V_48 ;
V_94 = NULL ;
V_48 = 0 ;
if ( F_32 ( F_103 ( & V_1 -> V_92 ) != - 1 ) )
V_94 = L_7 ;
if ( F_32 ( V_1 -> V_64 != NULL ) )
V_94 = L_8 ;
if ( F_32 ( F_104 ( V_1 ) != 0 ) )
V_94 = L_9 ;
if ( F_32 ( V_1 -> V_34 & V_95 ) ) {
V_94 = L_10 ;
V_48 = V_95 ;
}
#ifdef F_105
if ( F_32 ( V_1 -> V_93 ) )
V_94 = L_11 ;
#endif
F_43 ( V_1 , V_94 , V_48 ) ;
}
static inline int F_107 ( struct V_1 * V_1 )
{
if ( F_95 ( F_102 ( V_1 , V_95 ) ) )
return 0 ;
F_106 ( V_1 ) ;
return 1 ;
}
static int F_108 ( struct V_1 * V_96 , struct V_1 * V_1 )
{
int V_41 = 1 ;
F_26 ( ( unsigned long ) V_97 & 1 ) ;
if ( ! F_109 ( V_98 ) ) {
V_41 = 0 ;
goto V_53;
}
switch ( V_1 - V_96 ) {
case 1 :
if ( F_32 ( F_110 ( V_1 ) ) ) {
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
if ( F_32 ( ! F_111 ( V_1 ) ) ) {
F_43 ( V_1 , L_14 , 0 ) ;
goto V_53;
}
if ( F_32 ( F_112 ( V_1 ) != V_96 ) ) {
F_43 ( V_1 , L_15 , 0 ) ;
goto V_53;
}
V_41 = 0 ;
V_53:
V_1 -> V_64 = NULL ;
F_113 ( V_1 ) ;
return V_41 ;
}
static T_3 bool F_114 ( struct V_1 * V_1 ,
unsigned int V_59 , bool V_99 )
{
int V_100 = 0 ;
F_27 ( F_111 ( V_1 ) , V_1 ) ;
F_115 ( V_1 , V_59 ) ;
F_116 ( V_1 , V_59 ) ;
if ( F_32 ( V_59 ) ) {
bool V_101 = F_117 ( V_1 ) ;
int V_60 ;
F_27 ( V_101 && F_54 ( V_1 ) != V_59 , V_1 ) ;
if ( V_101 )
F_118 ( V_1 ) ;
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
if ( V_101 )
V_100 += F_108 ( V_1 , V_1 + V_60 ) ;
if ( F_32 ( F_107 ( V_1 + V_60 ) ) ) {
V_100 ++ ;
continue;
}
( V_1 + V_60 ) -> V_34 &= ~ V_82 ;
}
}
if ( F_119 ( V_1 ) )
V_1 -> V_64 = NULL ;
if ( F_120 () && F_121 ( V_1 ) )
F_122 ( V_1 , V_59 ) ;
if ( V_99 )
V_100 += F_107 ( V_1 ) ;
if ( V_100 )
return false ;
F_123 ( V_1 ) ;
V_1 -> V_34 &= ~ V_82 ;
F_124 ( V_1 , V_59 ) ;
if ( ! F_125 ( V_1 ) ) {
F_126 ( F_127 ( V_1 ) ,
V_102 << V_59 ) ;
F_128 ( F_127 ( V_1 ) ,
V_102 << V_59 ) ;
}
F_129 ( V_1 , V_59 ) ;
F_130 ( V_1 , 1 << V_59 , 0 ) ;
F_131 ( V_1 , 1 << V_59 , 0 ) ;
F_132 ( V_1 , V_59 ) ;
return true ;
}
static inline bool F_133 ( struct V_1 * V_1 )
{
return F_114 ( V_1 , 0 , true ) ;
}
static inline bool F_134 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_133 ( struct V_1 * V_1 )
{
return F_114 ( V_1 , 0 , false ) ;
}
static bool F_134 ( struct V_1 * V_1 )
{
return F_107 ( V_1 ) ;
}
static void F_135 ( struct V_40 * V_40 , int V_103 ,
struct V_104 * V_105 )
{
int V_3 = 0 ;
int V_106 = 0 ;
unsigned long V_107 ;
bool V_108 ;
F_136 ( & V_40 -> V_109 ) ;
V_108 = F_98 ( V_40 ) ;
V_107 = F_137 ( V_40 -> V_110 , V_111 ) ;
if ( V_107 )
F_138 ( V_40 -> V_110 , V_111 , - V_107 ) ;
while ( V_103 ) {
struct V_1 * V_1 ;
struct V_112 * V_113 ;
do {
V_106 ++ ;
if ( ++ V_3 == V_37 )
V_3 = 0 ;
V_113 = & V_105 -> V_114 [ V_3 ] ;
} while ( F_139 ( V_113 ) );
if ( V_106 == V_37 )
V_106 = V_103 ;
do {
int V_115 ;
V_1 = F_140 ( V_113 , struct V_1 , V_75 ) ;
F_97 ( & V_1 -> V_75 ) ;
V_115 = F_1 ( V_1 ) ;
F_27 ( F_80 ( V_115 ) , V_1 ) ;
if ( F_32 ( V_108 ) )
V_115 = F_99 ( V_1 ) ;
if ( F_134 ( V_1 ) )
continue;
F_91 ( V_1 , F_35 ( V_1 ) , V_40 , 0 , V_115 ) ;
F_141 ( V_1 , 0 , V_115 ) ;
} while ( -- V_103 && -- V_106 && ! F_139 ( V_113 ) );
}
F_142 ( & V_40 -> V_109 ) ;
}
static void F_143 ( struct V_40 * V_40 ,
struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_59 ,
int V_3 )
{
unsigned long V_107 ;
F_136 ( & V_40 -> V_109 ) ;
V_107 = F_137 ( V_40 -> V_110 , V_111 ) ;
if ( V_107 )
F_138 ( V_40 -> V_110 , V_111 , - V_107 ) ;
if ( F_32 ( F_98 ( V_40 ) ||
F_80 ( V_3 ) ) ) {
V_3 = F_24 ( V_1 , V_12 ) ;
}
F_91 ( V_1 , V_12 , V_40 , V_59 , V_3 ) ;
F_142 ( & V_40 -> V_109 ) ;
}
static void T_2 F_144 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_40 , int V_13 )
{
F_145 ( V_1 , V_40 , V_13 , V_12 ) ;
F_146 ( V_1 ) ;
F_50 ( V_1 ) ;
F_123 ( V_1 ) ;
F_75 ( & V_1 -> V_75 ) ;
#ifdef F_147
if ( ! F_148 ( V_40 ) )
F_149 ( V_1 , F_150 ( V_12 << V_17 ) ) ;
#endif
}
static void T_2 F_151 ( unsigned long V_12 , unsigned long V_40 ,
int V_13 )
{
return F_144 ( F_152 ( V_12 ) , V_12 , V_40 , V_13 ) ;
}
static void F_153 ( unsigned long V_12 )
{
T_1 * V_9 ;
int V_13 , V_116 ;
if ( ! F_9 ( V_12 ) )
return;
V_13 = F_10 ( V_12 ) ;
V_9 = F_12 ( V_13 ) ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
struct V_40 * V_40 = & V_9 -> V_118 [ V_116 ] ;
if ( V_12 >= V_40 -> V_23 && V_12 < F_154 ( V_40 ) )
break;
}
F_151 ( V_12 , V_116 , V_13 ) ;
}
static inline void F_153 ( unsigned long V_12 )
{
}
void T_2 F_155 ( T_5 V_119 , T_5 V_120 )
{
unsigned long V_44 = F_156 ( V_119 ) ;
unsigned long V_121 = F_157 ( V_120 ) ;
for (; V_44 < V_121 ; V_44 ++ ) {
if ( F_158 ( V_44 ) ) {
struct V_1 * V_1 = F_152 ( V_44 ) ;
F_153 ( V_44 ) ;
F_75 ( & V_1 -> V_75 ) ;
F_159 ( V_1 ) ;
}
}
}
static void F_53 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned long V_34 ;
int V_3 ;
unsigned long V_12 = F_35 ( V_1 ) ;
if ( ! F_114 ( V_1 , V_59 , true ) )
return;
V_3 = F_24 ( V_1 , V_12 ) ;
F_160 ( V_34 ) ;
F_161 ( V_122 , 1 << V_59 ) ;
F_143 ( F_19 ( V_1 ) , V_1 , V_12 , V_59 , V_3 ) ;
F_162 ( V_34 ) ;
}
static void T_4 F_163 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned int V_61 = 1 << V_59 ;
struct V_1 * V_63 = V_1 ;
unsigned int V_123 ;
F_164 ( V_63 ) ;
for ( V_123 = 0 ; V_123 < ( V_61 - 1 ) ; V_123 ++ , V_63 ++ ) {
F_164 ( V_63 + 1 ) ;
F_165 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
}
F_165 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
F_19 ( V_1 ) -> V_124 += V_61 ;
F_166 ( V_1 ) ;
F_167 ( V_1 , V_59 ) ;
}
int T_2 F_10 ( unsigned long V_12 )
{
static F_168 ( V_125 ) ;
int V_13 ;
F_136 ( & V_125 ) ;
V_13 = F_169 ( V_12 , & V_126 ) ;
if ( V_13 < 0 )
V_13 = V_127 ;
F_142 ( & V_125 ) ;
return V_13 ;
}
static inline bool T_2 F_170 ( unsigned long V_12 , int V_128 ,
struct V_129 * V_130 )
{
int V_13 ;
V_13 = F_169 ( V_12 , V_130 ) ;
if ( V_13 >= 0 && V_13 != V_128 )
return false ;
return true ;
}
static inline bool T_2 F_171 ( unsigned long V_12 , int V_128 )
{
return F_170 ( V_12 , V_128 , & V_126 ) ;
}
static inline bool T_2 F_171 ( unsigned long V_12 , int V_128 )
{
return true ;
}
static inline bool T_2 F_170 ( unsigned long V_12 , int V_128 ,
struct V_129 * V_130 )
{
return true ;
}
void T_4 F_172 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_59 )
{
if ( F_9 ( V_12 ) )
return;
return F_163 ( V_1 , V_59 ) ;
}
struct V_1 * F_173 ( unsigned long V_44 ,
unsigned long V_121 , struct V_40 * V_40 )
{
struct V_1 * V_131 ;
struct V_1 * V_132 ;
V_121 -- ;
if ( ! F_158 ( V_44 ) || ! F_158 ( V_121 ) )
return NULL ;
V_131 = F_152 ( V_44 ) ;
if ( F_19 ( V_131 ) != V_40 )
return NULL ;
V_132 = F_152 ( V_121 ) ;
if ( F_88 ( V_131 ) != F_88 ( V_132 ) )
return NULL ;
return V_131 ;
}
void F_174 ( struct V_40 * V_40 )
{
unsigned long V_133 = V_40 -> V_23 ;
unsigned long V_134 ;
V_134 = F_175 ( V_133 + 1 , V_24 ) ;
for (; V_133 < F_154 ( V_40 ) ;
V_133 = V_134 ,
V_134 += V_24 ) {
V_134 = F_176 ( V_134 , F_154 ( V_40 ) ) ;
if ( ! F_173 ( V_133 ,
V_134 , V_40 ) )
return;
}
V_40 -> V_135 = true ;
}
void F_177 ( struct V_40 * V_40 )
{
V_40 -> V_135 = false ;
}
static void T_4 F_178 ( struct V_1 * V_1 ,
unsigned long V_12 , int V_61 )
{
int V_60 ;
if ( ! V_1 )
return;
if ( V_61 == V_136 &&
( V_12 & ( V_136 - 1 ) ) == 0 ) {
F_31 ( V_1 , V_137 ) ;
F_163 ( V_1 , V_71 - 1 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ , V_1 ++ )
F_163 ( V_1 , 0 ) ;
}
static inline void T_4 F_179 ( void )
{
if ( F_180 ( & V_138 ) )
F_181 ( & V_139 ) ;
}
static int T_4 F_182 ( void * V_140 )
{
T_1 * V_9 = V_140 ;
int V_13 = V_9 -> V_141 ;
struct V_129 V_142 = { } ;
unsigned long V_119 = V_52 ;
unsigned long V_61 = 0 ;
unsigned long V_143 , V_144 ;
int V_60 , V_116 ;
struct V_40 * V_40 ;
unsigned long V_145 = V_9 -> V_10 ;
const struct V_146 * V_146 = F_183 ( V_9 -> V_141 ) ;
if ( V_145 == V_11 ) {
F_179 () ;
return 0 ;
}
if ( ! F_184 ( V_146 ) )
F_185 ( V_55 , V_146 ) ;
F_186 ( V_9 -> V_10 < V_9 -> V_147 ) ;
F_186 ( V_9 -> V_10 > F_14 ( V_9 ) ) ;
V_9 -> V_10 = V_11 ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
V_40 = V_9 -> V_118 + V_116 ;
if ( V_145 < F_154 ( V_40 ) )
break;
}
F_187 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_12 , V_121 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_148 = NULL ;
unsigned long V_149 = 0 ;
int V_150 = 0 ;
V_121 = F_176 ( V_144 , F_154 ( V_40 ) ) ;
V_12 = V_145 ;
if ( V_12 < V_143 )
V_12 = V_143 ;
if ( V_12 < V_40 -> V_23 )
V_12 = V_40 -> V_23 ;
for (; V_12 < V_121 ; V_12 ++ ) {
if ( ! F_41 ( V_12 ) )
goto V_151;
if ( ( V_12 & ( V_136 - 1 ) ) == 0 ) {
if ( ! F_158 ( V_12 ) ) {
V_1 = NULL ;
goto V_151;
}
}
if ( ! F_170 ( V_12 , V_13 , & V_142 ) ) {
V_1 = NULL ;
goto V_151;
}
if ( V_1 && ( V_12 & ( V_136 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_61 += V_150 ;
F_178 ( V_148 ,
V_149 , V_150 ) ;
V_148 = NULL ;
V_149 = V_150 = 0 ;
V_1 = F_152 ( V_12 ) ;
F_188 () ;
}
if ( V_1 -> V_34 ) {
F_93 ( F_19 ( V_1 ) != V_40 ) ;
goto V_151;
}
F_144 ( V_1 , V_12 , V_116 , V_13 ) ;
if ( ! V_148 ) {
V_148 = V_1 ;
V_149 = V_12 ;
V_150 = 0 ;
}
V_150 ++ ;
continue;
V_151:
V_61 += V_150 ;
F_178 ( V_148 , V_149 ,
V_150 ) ;
V_148 = NULL ;
V_149 = V_150 = 0 ;
}
V_145 = F_15 ( V_121 , V_145 ) ;
}
F_4 ( ++ V_116 < V_117 && F_189 ( ++ V_40 ) ) ;
F_70 ( L_16 , V_13 , V_61 ,
F_190 ( V_52 - V_119 ) ) ;
F_179 () ;
return 0 ;
}
void T_4 F_191 ( void )
{
struct V_40 * V_40 ;
#ifdef F_192
int V_13 ;
F_61 ( & V_138 , F_193 ( V_152 ) ) ;
F_194 (nid, N_MEMORY) {
F_195 ( F_182 , F_12 ( V_13 ) , L_17 , V_13 ) ;
}
F_196 ( & V_139 ) ;
F_197 () ;
#endif
F_198 (zone)
F_174 ( V_40 ) ;
}
void T_4 F_199 ( struct V_1 * V_1 )
{
unsigned V_60 = V_24 ;
struct V_1 * V_63 = V_1 ;
do {
F_165 ( V_63 ) ;
F_59 ( V_63 , 0 ) ;
} while ( ++ V_63 , -- V_60 );
F_31 ( V_1 , V_153 ) ;
if ( V_21 >= V_71 ) {
V_60 = V_24 ;
V_63 = V_1 ;
do {
F_166 ( V_63 ) ;
F_167 ( V_63 , V_71 - 1 ) ;
V_63 += V_136 ;
} while ( V_60 -= V_136 );
} else {
F_166 ( V_1 ) ;
F_167 ( V_1 , V_21 ) ;
}
F_200 ( V_1 , V_24 ) ;
}
static inline void F_201 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_154 , int V_155 , struct V_85 * V_156 ,
int V_3 )
{
unsigned long V_157 = 1 << V_155 ;
while ( V_155 > V_154 ) {
V_156 -- ;
V_155 -- ;
V_157 >>= 1 ;
F_27 ( F_42 ( V_40 , & V_1 [ V_157 ] ) , & V_1 [ V_157 ] ) ;
if ( F_109 ( V_158 ) &&
F_72 () &&
V_155 < F_202 () ) {
F_71 ( V_40 , & V_1 [ V_157 ] , V_155 , V_3 ) ;
continue;
}
F_101 ( & V_1 [ V_157 ] . V_75 , & V_156 -> V_90 [ V_3 ] ) ;
V_156 -> V_86 ++ ;
F_81 ( & V_1 [ V_157 ] , V_155 ) ;
}
}
static void F_203 ( struct V_1 * V_1 )
{
const char * V_94 = NULL ;
unsigned long V_48 = 0 ;
if ( F_32 ( F_103 ( & V_1 -> V_92 ) != - 1 ) )
V_94 = L_7 ;
if ( F_32 ( V_1 -> V_64 != NULL ) )
V_94 = L_8 ;
if ( F_32 ( F_104 ( V_1 ) != 0 ) )
V_94 = L_18 ;
if ( F_32 ( V_1 -> V_34 & V_159 ) ) {
V_94 = L_19 ;
V_48 = V_159 ;
F_50 ( V_1 ) ;
return;
}
if ( F_32 ( V_1 -> V_34 & V_82 ) ) {
V_94 = L_20 ;
V_48 = V_82 ;
}
#ifdef F_105
if ( F_32 ( V_1 -> V_93 ) )
V_94 = L_11 ;
#endif
F_43 ( V_1 , V_94 , V_48 ) ;
}
static inline int F_204 ( struct V_1 * V_1 )
{
if ( F_95 ( F_102 ( V_1 ,
V_82 | V_159 ) ) )
return 0 ;
F_203 ( V_1 ) ;
return 1 ;
}
static inline bool F_205 ( bool V_160 )
{
return F_109 ( V_161 ) &&
F_206 () && V_160 ;
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
T_6 V_162 )
{
F_76 ( V_1 , 0 ) ;
F_166 ( V_1 ) ;
F_211 ( V_1 , V_59 ) ;
F_131 ( V_1 , 1 << V_59 , 1 ) ;
F_130 ( V_1 , 1 << V_59 , 1 ) ;
F_212 ( V_1 , V_59 ) ;
F_213 ( V_1 , V_59 , V_162 ) ;
}
static void F_214 ( struct V_1 * V_1 , unsigned int V_59 , T_6 V_162 ,
unsigned int V_163 )
{
int V_60 ;
bool V_160 = true ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ ) {
struct V_1 * V_63 = V_1 + V_60 ;
if ( V_160 )
V_160 &= F_215 ( V_63 ) ;
}
F_210 ( V_1 , V_59 , V_162 ) ;
if ( ! F_205 ( V_160 ) && ( V_162 & V_164 ) )
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_216 ( V_1 + V_60 ) ;
if ( V_59 && ( V_162 & V_165 ) )
F_55 ( V_1 , V_59 ) ;
if ( V_163 & V_166 )
F_217 ( V_1 ) ;
else
F_218 ( V_1 ) ;
}
static inline
struct V_1 * F_219 ( struct V_40 * V_40 , unsigned int V_59 ,
int V_3 )
{
unsigned int V_167 ;
struct V_85 * V_156 ;
struct V_1 * V_1 ;
for ( V_167 = V_59 ; V_167 < V_71 ; ++ V_167 ) {
V_156 = & ( V_40 -> V_85 [ V_167 ] ) ;
V_1 = F_220 ( & V_156 -> V_90 [ V_3 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
F_97 ( & V_1 -> V_75 ) ;
F_83 ( V_1 ) ;
V_156 -> V_86 -- ;
F_201 ( V_40 , V_1 , V_59 , V_167 , V_156 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_221 ( struct V_40 * V_40 ,
unsigned int V_59 )
{
return F_219 ( V_40 , V_59 , V_153 ) ;
}
static inline struct V_1 * F_221 ( struct V_40 * V_40 ,
unsigned int V_59 ) { return NULL ; }
int F_222 ( struct V_40 * V_40 ,
struct V_1 * V_131 , struct V_1 * V_132 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned int V_59 ;
int V_168 = 0 ;
#ifndef F_223
F_93 ( F_19 ( V_131 ) != F_19 ( V_132 ) ) ;
#endif
for ( V_1 = V_131 ; V_1 <= V_132 ; ) {
F_27 ( F_224 ( V_1 ) != F_39 ( V_40 ) , V_1 ) ;
if ( ! F_41 ( F_35 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
if ( ! F_90 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_59 = F_87 ( V_1 ) ;
F_225 ( & V_1 -> V_75 ,
& V_40 -> V_85 [ V_59 ] . V_90 [ V_3 ] ) ;
V_1 += 1 << V_59 ;
V_168 += 1 << V_59 ;
}
return V_168 ;
}
int F_226 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_44 , V_121 ;
struct V_1 * V_131 , * V_132 ;
V_44 = F_35 ( V_1 ) ;
V_44 = V_44 & ~ ( V_24 - 1 ) ;
V_131 = F_152 ( V_44 ) ;
V_132 = V_131 + V_24 - 1 ;
V_121 = V_44 + V_24 - 1 ;
if ( ! F_28 ( V_40 , V_44 ) )
V_131 = V_1 ;
if ( ! F_28 ( V_40 , V_121 ) )
return 0 ;
return F_222 ( V_40 , V_131 , V_132 , V_3 ) ;
}
static void F_227 ( struct V_1 * V_169 ,
int V_170 , int V_3 )
{
int V_171 = 1 << ( V_170 - V_21 ) ;
while ( V_171 -- ) {
F_31 ( V_169 , V_3 ) ;
V_169 += V_24 ;
}
}
static bool F_228 ( unsigned int V_59 , int V_172 )
{
if ( V_59 >= V_21 )
return true ;
if ( V_59 >= V_21 / 2 ||
V_172 == V_173 ||
V_172 == V_38 ||
V_36 )
return true ;
return false ;
}
static void F_229 ( struct V_40 * V_40 , struct V_1 * V_1 ,
int V_174 )
{
unsigned int V_167 = F_87 ( V_1 ) ;
int V_175 ;
if ( V_167 >= V_21 ) {
F_227 ( V_1 , V_167 , V_174 ) ;
return;
}
V_175 = F_226 ( V_40 , V_1 , V_174 ) ;
if ( V_175 >= ( 1 << ( V_21 - 1 ) ) ||
V_36 )
F_31 ( V_1 , V_174 ) ;
}
int F_230 ( struct V_85 * V_156 , unsigned int V_59 ,
int V_3 , bool V_176 , bool * V_177 )
{
int V_60 ;
int V_178 ;
if ( V_156 -> V_86 == 0 )
return - 1 ;
* V_177 = false ;
for ( V_60 = 0 ; ; V_60 ++ ) {
V_178 = V_179 [ V_3 ] [ V_60 ] ;
if ( V_178 == V_180 )
break;
if ( F_139 ( & V_156 -> V_90 [ V_178 ] ) )
continue;
if ( F_228 ( V_59 , V_3 ) )
* V_177 = true ;
if ( ! V_176 )
return V_178 ;
if ( * V_177 )
return V_178 ;
}
return - 1 ;
}
static void F_231 ( struct V_1 * V_1 , struct V_40 * V_40 ,
unsigned int V_181 )
{
int V_115 ;
unsigned long V_182 , V_34 ;
V_182 = ( V_40 -> V_124 / 100 ) + V_24 ;
if ( V_40 -> V_183 >= V_182 )
return;
F_232 ( & V_40 -> V_109 , V_34 ) ;
if ( V_40 -> V_183 >= V_182 )
goto V_184;
V_115 = F_99 ( V_1 ) ;
if ( V_115 != V_185 &&
! F_80 ( V_115 ) && ! F_233 ( V_115 ) ) {
V_40 -> V_183 += V_24 ;
F_31 ( V_1 , V_185 ) ;
F_226 ( V_40 , V_1 , V_185 ) ;
}
V_184:
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
static void F_235 ( const struct V_186 * V_187 )
{
struct V_188 * V_188 = V_187 -> V_188 ;
unsigned long V_34 ;
struct V_189 * V_190 ;
struct V_40 * V_40 ;
struct V_1 * V_1 ;
int V_59 ;
F_236 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( V_40 -> V_183 <= V_24 )
continue;
F_232 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_85 * V_156 = & ( V_40 -> V_85 [ V_59 ] ) ;
V_1 = F_220 (
& V_156 -> V_90 [ V_185 ] ,
struct V_1 , V_75 ) ;
if ( ! V_1 )
continue;
V_40 -> V_183 -= F_176 ( V_24 ,
V_40 -> V_183 ) ;
F_31 ( V_1 , V_187 -> V_3 ) ;
F_226 ( V_40 , V_1 , V_187 -> V_3 ) ;
F_234 ( & V_40 -> V_109 , V_34 ) ;
return;
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
}
static inline struct V_1 *
F_237 ( struct V_40 * V_40 , unsigned int V_59 , int V_191 )
{
struct V_85 * V_156 ;
unsigned int V_167 ;
struct V_1 * V_1 ;
int V_178 ;
bool V_177 ;
for ( V_167 = V_71 - 1 ;
V_167 >= V_59 && V_167 <= V_71 - 1 ;
-- V_167 ) {
V_156 = & ( V_40 -> V_85 [ V_167 ] ) ;
V_178 = F_230 ( V_156 , V_167 ,
V_191 , false , & V_177 ) ;
if ( V_178 == - 1 )
continue;
V_1 = F_238 ( & V_156 -> V_90 [ V_178 ] ,
struct V_1 , V_75 ) ;
if ( V_177 )
F_229 ( V_40 , V_1 , V_191 ) ;
V_156 -> V_86 -- ;
F_97 ( & V_1 -> V_75 ) ;
F_83 ( V_1 ) ;
F_201 ( V_40 , V_1 , V_59 , V_167 , V_156 ,
V_191 ) ;
F_2 ( V_1 , V_191 ) ;
F_239 ( V_1 , V_59 , V_167 ,
V_191 , V_178 ) ;
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
if ( V_3 == V_137 )
V_1 = F_221 ( V_40 , V_59 ) ;
if ( ! V_1 )
V_1 = F_237 ( V_40 , V_59 , V_3 ) ;
}
F_241 ( V_1 , V_59 , V_3 ) ;
return V_1 ;
}
static int F_242 ( struct V_40 * V_40 , unsigned int V_59 ,
unsigned long V_103 , struct V_112 * V_113 ,
int V_3 , bool V_192 )
{
int V_60 ;
F_136 ( & V_40 -> V_109 ) ;
for ( V_60 = 0 ; V_60 < V_103 ; ++ V_60 ) {
struct V_1 * V_1 = F_240 ( V_40 , V_59 , V_3 ) ;
if ( F_32 ( V_1 == NULL ) )
break;
if ( F_32 ( F_207 ( V_1 ) ) )
continue;
if ( F_95 ( ! V_192 ) )
F_101 ( & V_1 -> V_75 , V_113 ) ;
else
F_100 ( & V_1 -> V_75 , V_113 ) ;
V_113 = & V_1 -> V_75 ;
if ( F_233 ( F_1 ( V_1 ) ) )
F_243 ( V_40 , V_193 ,
- ( 1 << V_59 ) ) ;
}
F_243 ( V_40 , V_194 , - ( V_60 << V_59 ) ) ;
F_142 ( & V_40 -> V_109 ) ;
return V_60 ;
}
void F_244 ( struct V_40 * V_40 , struct V_104 * V_105 )
{
unsigned long V_34 ;
int V_195 , V_196 ;
F_160 ( V_34 ) ;
V_196 = F_29 ( V_105 -> V_196 ) ;
V_195 = F_176 ( V_105 -> V_103 , V_196 ) ;
if ( V_195 > 0 ) {
F_135 ( V_40 , V_195 , V_105 ) ;
V_105 -> V_103 -= V_195 ;
}
F_162 ( V_34 ) ;
}
static void F_245 ( unsigned int V_197 , struct V_40 * V_40 )
{
unsigned long V_34 ;
struct V_198 * V_199 ;
struct V_104 * V_105 ;
F_160 ( V_34 ) ;
V_199 = F_246 ( V_40 -> V_200 , V_197 ) ;
V_105 = & V_199 -> V_105 ;
if ( V_105 -> V_103 ) {
F_135 ( V_40 , V_105 -> V_103 , V_105 ) ;
V_105 -> V_103 = 0 ;
}
F_162 ( V_34 ) ;
}
static void F_247 ( unsigned int V_197 )
{
struct V_40 * V_40 ;
F_198 (zone) {
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
void F_250 ( struct V_40 * V_40 )
{
int V_197 ;
static T_7 V_201 ;
F_251 (cpu) {
struct V_198 * V_105 ;
struct V_40 * V_190 ;
bool V_202 = false ;
if ( V_40 ) {
V_105 = F_246 ( V_40 -> V_200 , V_197 ) ;
if ( V_105 -> V_105 . V_103 )
V_202 = true ;
} else {
F_198 (z) {
V_105 = F_246 ( V_190 -> V_200 , V_197 ) ;
if ( V_105 -> V_105 . V_103 ) {
V_202 = true ;
break;
}
}
}
if ( V_202 )
F_252 ( V_197 , & V_201 ) ;
else
F_253 ( V_197 , & V_201 ) ;
}
F_254 ( & V_201 , ( V_203 ) F_248 ,
V_40 , 1 ) ;
}
void F_255 ( struct V_40 * V_40 )
{
unsigned long V_12 , V_204 ;
unsigned long V_34 ;
unsigned int V_59 , V_205 ;
struct V_1 * V_1 ;
if ( F_256 ( V_40 ) )
return;
F_232 ( & V_40 -> V_109 , V_34 ) ;
V_204 = F_154 ( V_40 ) ;
for ( V_12 = V_40 -> V_23 ; V_12 < V_204 ; V_12 ++ )
if ( F_158 ( V_12 ) ) {
V_1 = F_152 ( V_12 ) ;
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
F_261 ( F_152 ( V_12 + V_60 ) ) ;
}
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
void F_262 ( struct V_1 * V_1 , bool V_192 )
{
struct V_40 * V_40 = F_19 ( V_1 ) ;
struct V_104 * V_105 ;
unsigned long V_34 ;
unsigned long V_12 = F_35 ( V_1 ) ;
int V_3 ;
if ( ! F_133 ( V_1 ) )
return;
V_3 = F_24 ( V_1 , V_12 ) ;
F_2 ( V_1 , V_3 ) ;
F_160 ( V_34 ) ;
F_263 ( V_122 ) ;
if ( V_3 >= V_37 ) {
if ( F_32 ( F_80 ( V_3 ) ) ) {
F_143 ( V_40 , V_1 , V_12 , 0 , V_3 ) ;
goto V_53;
}
V_3 = V_137 ;
}
V_105 = & F_264 ( V_40 -> V_200 ) -> V_105 ;
if ( ! V_192 )
F_101 ( & V_1 -> V_75 , & V_105 -> V_114 [ V_3 ] ) ;
else
F_100 ( & V_1 -> V_75 , & V_105 -> V_114 [ V_3 ] ) ;
V_105 -> V_103 ++ ;
if ( V_105 -> V_103 >= V_105 -> V_155 ) {
unsigned long V_196 = F_29 ( V_105 -> V_196 ) ;
F_135 ( V_40 , V_196 , V_105 ) ;
V_105 -> V_103 -= V_196 ;
}
V_53:
F_162 ( V_34 ) ;
}
void F_265 ( struct V_112 * V_113 , bool V_192 )
{
struct V_1 * V_1 , * V_206 ;
F_266 (page, next, list, lru) {
F_267 ( V_1 , V_192 ) ;
F_262 ( V_1 , V_192 ) ;
}
}
void F_268 ( struct V_1 * V_1 , unsigned int V_59 )
{
int V_60 ;
F_27 ( F_117 ( V_1 ) , V_1 ) ;
F_27 ( ! F_89 ( V_1 ) , V_1 ) ;
#ifdef F_269
if ( F_270 ( V_1 ) )
F_268 ( F_271 ( V_1 [ 0 ] . V_207 ) , V_59 ) ;
#endif
for ( V_60 = 1 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_166 ( V_1 + V_60 ) ;
F_272 ( V_1 , V_59 ) ;
}
int F_273 ( struct V_1 * V_1 , unsigned int V_59 )
{
unsigned long V_208 ;
struct V_40 * V_40 ;
int V_115 ;
F_186 ( ! F_90 ( V_1 ) ) ;
V_40 = F_19 ( V_1 ) ;
V_115 = F_99 ( V_1 ) ;
if ( ! F_80 ( V_115 ) ) {
V_208 = F_274 ( V_40 ) + ( 1 << V_59 ) ;
if ( ! F_275 ( V_40 , 0 , V_208 , 0 , 0 ) )
return 0 ;
F_77 ( V_40 , - ( 1UL << V_59 ) , V_115 ) ;
}
F_97 ( & V_1 -> V_75 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
F_83 ( V_1 ) ;
if ( V_59 >= V_21 - 1 ) {
struct V_1 * V_209 = V_1 + ( 1 << V_59 ) - 1 ;
for (; V_1 < V_209 ; V_1 += V_24 ) {
int V_115 = F_99 ( V_1 ) ;
if ( ! F_80 ( V_115 ) && ! F_233 ( V_115 ) )
F_31 ( V_1 ,
V_137 ) ;
}
}
return 1UL << V_59 ;
}
static inline void F_276 ( struct V_40 * V_210 , struct V_40 * V_190 ,
T_6 V_34 )
{
#ifdef F_277
int V_211 = F_278 () ;
enum V_212 V_213 = V_214 ;
if ( F_32 ( V_34 & V_215 ) ) {
V_213 = V_216 ;
V_211 = V_210 -> V_128 ;
}
if ( V_190 -> V_128 == V_211 ) {
F_279 ( V_190 , V_217 ) ;
F_279 ( V_190 , V_213 ) ;
} else {
F_279 ( V_190 , V_218 ) ;
F_279 ( V_210 , V_219 ) ;
}
#endif
}
static inline
struct V_1 * F_280 ( struct V_40 * V_210 ,
struct V_40 * V_40 , unsigned int V_59 ,
T_6 V_162 , unsigned int V_163 ,
int V_3 )
{
unsigned long V_34 ;
struct V_1 * V_1 ;
bool V_192 = ( ( V_162 & V_220 ) != 0 ) ;
if ( F_95 ( V_59 == 0 ) ) {
struct V_104 * V_105 ;
struct V_112 * V_113 ;
F_160 ( V_34 ) ;
do {
V_105 = & F_264 ( V_40 -> V_200 ) -> V_105 ;
V_113 = & V_105 -> V_114 [ V_3 ] ;
if ( F_139 ( V_113 ) ) {
V_105 -> V_103 += F_242 ( V_40 , 0 ,
V_105 -> V_196 , V_113 ,
V_3 , V_192 ) ;
if ( F_32 ( F_139 ( V_113 ) ) )
goto V_221;
}
if ( V_192 )
V_1 = F_140 ( V_113 , struct V_1 , V_75 ) ;
else
V_1 = F_238 ( V_113 , struct V_1 , V_75 ) ;
F_97 ( & V_1 -> V_75 ) ;
V_105 -> V_103 -- ;
} while ( F_208 ( V_1 ) );
} else {
F_281 ( ( V_162 & V_222 ) && ( V_59 > 1 ) ) ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
do {
V_1 = NULL ;
if ( V_163 & V_223 ) {
V_1 = F_219 ( V_40 , V_59 , V_185 ) ;
if ( V_1 )
F_241 ( V_1 , V_59 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_240 ( V_40 , V_59 , V_3 ) ;
} while ( V_1 && F_209 ( V_1 , V_59 ) );
F_142 ( & V_40 -> V_109 ) ;
if ( ! V_1 )
goto V_221;
F_77 ( V_40 , - ( 1 << V_59 ) ,
F_1 ( V_1 ) ) ;
}
F_282 ( V_224 , F_283 ( V_1 ) , 1 << V_59 ) ;
F_276 ( V_210 , V_40 , V_162 ) ;
F_162 ( V_34 ) ;
F_27 ( F_42 ( V_40 , V_1 ) , V_1 ) ;
return V_1 ;
V_221:
F_162 ( V_34 ) ;
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
bool F_295 ( struct V_40 * V_190 , unsigned int V_59 , unsigned long V_242 ,
int V_243 , unsigned int V_163 ,
long V_244 )
{
long F_176 = V_242 ;
int V_245 ;
const bool V_246 = ( V_163 & V_223 ) ;
V_244 -= ( 1 << V_59 ) - 1 ;
if ( V_163 & V_247 )
F_176 -= F_176 / 2 ;
if ( F_95 ( ! V_246 ) )
V_244 -= V_190 -> V_183 ;
else
F_176 -= F_176 / 4 ;
#ifdef F_296
if ( ! ( V_163 & V_248 ) )
V_244 -= F_297 ( V_190 , V_193 ) ;
#endif
if ( V_244 <= F_176 + V_190 -> V_249 [ V_243 ] )
return false ;
if ( ! V_59 )
return true ;
for ( V_245 = V_59 ; V_245 < V_71 ; V_245 ++ ) {
struct V_85 * V_156 = & V_190 -> V_85 [ V_245 ] ;
int V_115 ;
if ( ! V_156 -> V_86 )
continue;
if ( V_246 )
return true ;
for ( V_115 = 0 ; V_115 < V_37 ; V_115 ++ ) {
if ( ! F_139 ( & V_156 -> V_90 [ V_115 ] ) )
return true ;
}
#ifdef F_296
if ( ( V_163 & V_248 ) &&
! F_139 ( & V_156 -> V_90 [ V_153 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_275 ( struct V_40 * V_190 , unsigned int V_59 , unsigned long V_242 ,
int V_243 , unsigned int V_163 )
{
return F_295 ( V_190 , V_59 , V_242 , V_243 , V_163 ,
F_297 ( V_190 , V_194 ) ) ;
}
static inline bool F_298 ( struct V_40 * V_190 , unsigned int V_59 ,
unsigned long V_242 , int V_243 , unsigned int V_163 )
{
long V_244 = F_297 ( V_190 , V_194 ) ;
long V_250 = 0 ;
#ifdef F_296
if ( ! ( V_163 & V_248 ) )
V_250 = F_297 ( V_190 , V_193 ) ;
#endif
if ( ! V_59 && ( V_244 - V_250 ) > V_242 + V_190 -> V_249 [ V_243 ] )
return true ;
return F_295 ( V_190 , V_59 , V_242 , V_243 , V_163 ,
V_244 ) ;
}
bool F_299 ( struct V_40 * V_190 , unsigned int V_59 ,
unsigned long V_242 , int V_243 )
{
long V_244 = F_297 ( V_190 , V_194 ) ;
if ( V_190 -> V_251 && V_244 < V_190 -> V_251 )
V_244 = F_300 ( V_190 , V_194 ) ;
return F_295 ( V_190 , V_59 , V_242 , V_243 , 0 ,
V_244 ) ;
}
static bool F_301 ( struct V_40 * V_252 , struct V_40 * V_40 )
{
return F_302 ( F_39 ( V_252 ) , F_39 ( V_40 ) ) <
V_253 ;
}
static bool F_301 ( struct V_40 * V_252 , struct V_40 * V_40 )
{
return true ;
}
static struct V_1 *
F_303 ( T_6 V_228 , unsigned int V_59 , int V_163 ,
const struct V_186 * V_187 )
{
struct V_189 * V_190 = V_187 -> V_254 ;
struct V_40 * V_40 ;
struct V_255 * V_256 = NULL ;
F_304 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
struct V_1 * V_1 ;
unsigned long V_242 ;
if ( F_305 () &&
( V_163 & V_257 ) &&
! F_306 ( V_40 , V_228 ) )
continue;
if ( V_187 -> V_258 ) {
if ( V_256 == V_40 -> V_110 )
continue;
if ( ! F_307 ( V_40 -> V_110 ) ) {
V_256 = V_40 -> V_110 ;
continue;
}
}
V_242 = V_40 -> V_208 [ V_163 & V_259 ] ;
if ( ! F_298 ( V_40 , V_59 , V_242 ,
F_308 ( V_187 ) , V_163 ) ) {
int V_41 ;
F_26 ( V_166 < V_260 ) ;
if ( V_163 & V_166 )
goto V_261;
if ( V_262 == 0 ||
! F_301 ( V_187 -> V_254 -> V_40 , V_40 ) )
continue;
V_41 = F_309 ( V_40 -> V_110 , V_228 , V_59 ) ;
switch ( V_41 ) {
case V_263 :
continue;
case V_264 :
continue;
default:
if ( F_275 ( V_40 , V_59 , V_242 ,
F_308 ( V_187 ) , V_163 ) )
goto V_261;
continue;
}
}
V_261:
V_1 = F_280 ( V_187 -> V_254 -> V_40 , V_40 , V_59 ,
V_228 , V_163 , V_187 -> V_3 ) ;
if ( V_1 ) {
F_214 ( V_1 , V_59 , V_228 , V_163 ) ;
if ( F_32 ( V_59 && ( V_163 & V_223 ) ) )
F_231 ( V_1 , V_40 , V_59 ) ;
return V_1 ;
}
}
return NULL ;
}
static inline bool F_310 ( void )
{
bool V_41 = false ;
#if V_265 > 8
V_41 = F_311 () ;
#endif
return V_41 ;
}
void F_312 ( T_6 V_228 , unsigned int V_59 , const char * V_266 , ... )
{
unsigned int V_267 = V_268 ;
if ( ( V_228 & V_269 ) || ! F_313 ( & V_270 ) ||
F_202 () > 0 )
return;
if ( ! ( V_228 & V_271 ) )
if ( F_314 ( V_272 ) ||
( V_55 -> V_34 & ( V_273 | V_274 ) ) )
V_267 &= ~ V_268 ;
if ( F_311 () || ! ( V_228 & V_233 ) )
V_267 &= ~ V_268 ;
if ( V_266 ) {
struct V_275 V_276 ;
T_9 args ;
va_start ( args , V_266 ) ;
V_276 . V_266 = V_266 ;
V_276 . V_277 = & args ;
F_315 ( L_25 , & V_276 ) ;
va_end ( args ) ;
}
F_315 ( L_26 ,
V_55 -> V_56 , V_59 , V_228 , & V_228 ) ;
F_49 () ;
if ( ! F_310 () )
F_316 ( V_267 ) ;
}
static inline struct V_1 *
F_317 ( T_6 V_228 , unsigned int V_59 ,
const struct V_186 * V_187 , unsigned long * V_278 )
{
struct V_279 V_280 = {
. V_188 = V_187 -> V_188 ,
. V_281 = V_187 -> V_281 ,
. V_282 = NULL ,
. V_228 = V_228 ,
. V_59 = V_59 ,
} ;
struct V_1 * V_1 ;
* V_278 = 0 ;
if ( ! F_318 ( & V_283 ) ) {
* V_278 = 1 ;
F_319 ( 1 ) ;
return NULL ;
}
V_1 = F_303 ( V_228 | V_284 , V_59 ,
V_285 | V_257 , V_187 ) ;
if ( V_1 )
goto V_53;
if ( ! ( V_228 & V_222 ) ) {
if ( V_55 -> V_34 & V_286 )
goto V_53;
if ( V_59 > V_287 )
goto V_53;
if ( V_187 -> V_288 < V_289 )
goto V_53;
if ( F_7 () )
goto V_53;
if ( V_228 & V_290 )
goto V_53;
}
if ( F_320 ( & V_280 ) || F_281 ( V_228 & V_222 ) ) {
* V_278 = 1 ;
if ( V_228 & V_222 ) {
V_1 = F_303 ( V_228 , V_59 ,
V_166 | V_257 , V_187 ) ;
if ( ! V_1 )
V_1 = F_303 ( V_228 , V_59 ,
V_166 , V_187 ) ;
}
}
V_53:
F_321 ( & V_283 ) ;
return V_1 ;
}
static struct V_1 *
F_322 ( T_6 V_228 , unsigned int V_59 ,
unsigned int V_163 , const struct V_186 * V_187 ,
enum V_291 V_292 , enum V_293 * V_293 )
{
struct V_1 * V_1 ;
if ( ! V_59 )
return NULL ;
V_55 -> V_34 |= V_273 ;
* V_293 = F_323 ( V_228 , V_59 , V_163 , V_187 ,
V_292 ) ;
V_55 -> V_34 &= ~ V_273 ;
if ( * V_293 <= V_294 )
return NULL ;
F_324 ( V_295 ) ;
V_1 = F_303 ( V_228 , V_59 , V_163 , V_187 ) ;
if ( V_1 ) {
struct V_40 * V_40 = F_19 ( V_1 ) ;
V_40 -> V_296 = false ;
F_325 ( V_40 , V_59 , true ) ;
F_324 ( V_297 ) ;
return V_1 ;
}
F_324 ( V_298 ) ;
F_188 () ;
return NULL ;
}
static inline struct V_1 *
F_322 ( T_6 V_228 , unsigned int V_59 ,
unsigned int V_163 , const struct V_186 * V_187 ,
enum V_291 V_292 , enum V_293 * V_293 )
{
* V_293 = V_299 ;
return NULL ;
}
static inline bool
F_326 ( struct V_186 * V_187 , unsigned int V_59 , int V_163 ,
enum V_293 V_293 ,
enum V_291 * V_291 ,
int V_300 )
{
struct V_40 * V_40 ;
struct V_189 * V_190 ;
if ( ! V_59 || V_59 > V_287 )
return false ;
F_236 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( F_275 ( V_40 , 0 , F_327 ( V_40 ) ,
F_308 ( V_187 ) , V_163 ) )
return true ;
}
return false ;
}
static int
F_328 ( T_6 V_228 , unsigned int V_59 ,
const struct V_186 * V_187 )
{
struct V_301 V_301 ;
int V_302 ;
F_188 () ;
F_329 () ;
V_55 -> V_34 |= V_273 ;
F_330 ( V_228 ) ;
V_301 . V_303 = 0 ;
V_55 -> V_301 = & V_301 ;
V_302 = F_331 ( V_187 -> V_188 , V_59 , V_228 ,
V_187 -> V_281 ) ;
V_55 -> V_301 = NULL ;
F_332 () ;
V_55 -> V_34 &= ~ V_273 ;
F_188 () ;
return V_302 ;
}
static inline struct V_1 *
F_333 ( T_6 V_228 , unsigned int V_59 ,
unsigned int V_163 , const struct V_186 * V_187 ,
unsigned long * V_278 )
{
struct V_1 * V_1 = NULL ;
bool V_304 = false ;
* V_278 = F_328 ( V_228 , V_59 , V_187 ) ;
if ( F_32 ( ! ( * V_278 ) ) )
return NULL ;
V_305:
V_1 = F_303 ( V_228 , V_59 , V_163 , V_187 ) ;
if ( ! V_1 && ! V_304 ) {
F_235 ( V_187 ) ;
F_250 ( NULL ) ;
V_304 = true ;
goto V_305;
}
return V_1 ;
}
static void F_334 ( unsigned int V_59 , const struct V_186 * V_187 )
{
struct V_189 * V_190 ;
struct V_40 * V_40 ;
T_1 * V_306 = NULL ;
F_236 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask) {
if ( V_306 != V_40 -> V_110 )
F_335 ( V_40 , V_59 , V_187 -> V_288 ) ;
V_306 = V_40 -> V_110 ;
}
}
static inline unsigned int
F_336 ( T_6 V_228 )
{
unsigned int V_163 = V_307 | V_257 ;
F_26 ( V_308 != ( V_309 T_6 ) V_247 ) ;
V_163 |= ( V_309 int ) ( V_228 & V_308 ) ;
if ( V_228 & V_310 ) {
if ( ! ( V_228 & V_271 ) )
V_163 |= V_223 ;
V_163 &= ~ V_257 ;
} else if ( F_32 ( F_337 ( V_55 ) ) && ! F_311 () )
V_163 |= V_223 ;
#ifdef F_296
if ( F_338 ( V_228 ) == V_137 )
V_163 |= V_248 ;
#endif
return V_163 ;
}
bool F_339 ( T_6 V_228 )
{
if ( F_32 ( V_228 & V_271 ) )
return false ;
if ( V_228 & V_311 )
return true ;
if ( F_340 () && ( V_55 -> V_34 & V_273 ) )
return true ;
if ( ! F_311 () &&
( ( V_55 -> V_34 & V_273 ) ||
F_32 ( F_314 ( V_272 ) ) ) )
return true ;
return false ;
}
static inline bool
F_341 ( T_6 V_228 , unsigned V_59 ,
struct V_186 * V_187 , int V_163 ,
bool V_278 , int V_312 )
{
struct V_40 * V_40 ;
struct V_189 * V_190 ;
if ( V_312 > V_313 )
return false ;
F_236 (zone, z, ac->zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_314 ;
unsigned long V_315 ;
V_314 = V_315 = F_342 ( V_40 ) ;
V_314 -= F_343 ( V_312 * V_314 ,
V_313 ) ;
V_314 += F_300 ( V_40 , V_194 ) ;
if ( F_295 ( V_40 , V_59 , F_327 ( V_40 ) ,
F_308 ( V_187 ) , V_163 , V_314 ) ) {
if ( ! V_278 ) {
unsigned long V_316 ;
V_316 = F_300 ( V_40 ,
V_317 ) ;
if ( 2 * V_316 > V_315 ) {
F_344 ( V_318 , V_54 / 10 ) ;
return true ;
}
}
if ( V_55 -> V_34 & V_319 )
F_319 ( 1 ) ;
else
F_188 () ;
return true ;
}
}
return false ;
}
static inline struct V_1 *
F_345 ( T_6 V_228 , unsigned int V_59 ,
struct V_186 * V_187 )
{
bool V_320 = V_228 & V_233 ;
struct V_1 * V_1 = NULL ;
unsigned int V_163 ;
unsigned long V_278 ;
enum V_291 V_291 = V_321 ;
enum V_293 V_293 ;
int V_300 = 0 ;
int V_312 = 0 ;
if ( V_59 >= V_71 ) {
F_281 ( ! ( V_228 & V_269 ) ) ;
return NULL ;
}
if ( F_281 ( ( V_228 & ( V_310 | V_233 ) ) ==
( V_310 | V_233 ) ) )
V_228 &= ~ V_310 ;
V_163 = F_336 ( V_228 ) ;
if ( V_228 & V_322 )
F_334 ( V_59 , V_187 ) ;
V_1 = F_303 ( V_228 , V_59 , V_163 , V_187 ) ;
if ( V_1 )
goto V_323;
if ( V_320 && V_59 > V_287 &&
! F_339 ( V_228 ) ) {
V_1 = F_322 ( V_228 , V_59 ,
V_163 , V_187 ,
V_324 ,
& V_293 ) ;
if ( V_1 )
goto V_323;
if ( V_228 & V_325 ) {
if ( V_293 == V_326 )
goto V_327;
V_291 = V_324 ;
}
}
V_305:
if ( V_228 & V_322 )
F_334 ( V_59 , V_187 ) ;
if ( F_339 ( V_228 ) )
V_163 = V_166 ;
if ( ! ( V_163 & V_257 ) || ( V_163 & V_166 ) ) {
V_187 -> V_188 = F_346 ( F_278 () , V_228 ) ;
V_187 -> V_254 = F_347 ( V_187 -> V_188 ,
V_187 -> V_288 , V_187 -> V_281 ) ;
}
V_1 = F_303 ( V_228 , V_59 , V_163 , V_187 ) ;
if ( V_1 )
goto V_323;
if ( ! V_320 ) {
F_281 ( V_228 & V_222 ) ;
goto V_327;
}
if ( V_55 -> V_34 & V_273 ) {
if ( F_281 ( V_228 & V_222 ) ) {
F_188 () ;
goto V_305;
}
goto V_327;
}
if ( F_314 ( V_272 ) && ! ( V_228 & V_222 ) )
goto V_327;
V_1 = F_333 ( V_228 , V_59 , V_163 , V_187 ,
& V_278 ) ;
if ( V_1 )
goto V_323;
V_1 = F_322 ( V_228 , V_59 , V_163 , V_187 ,
V_291 , & V_293 ) ;
if ( V_1 )
goto V_323;
if ( V_59 && F_348 ( V_293 ) )
V_300 ++ ;
if ( V_228 & V_325 )
goto V_327;
if ( V_59 > V_287 && ! ( V_228 & V_328 ) )
goto V_327;
if ( V_278 && V_59 <= V_287 )
V_312 = 0 ;
else
V_312 ++ ;
if ( F_341 ( V_228 , V_59 , V_187 , V_163 ,
V_278 > 0 , V_312 ) )
goto V_305;
if ( V_278 > 0 &&
F_326 ( V_187 , V_59 , V_163 ,
V_293 , & V_291 ,
V_300 ) )
goto V_305;
V_1 = F_317 ( V_228 , V_59 , V_187 , & V_278 ) ;
if ( V_1 )
goto V_323;
if ( V_278 ) {
V_312 = 0 ;
goto V_305;
}
V_327:
F_312 ( V_228 , V_59 , NULL ) ;
V_323:
return V_1 ;
}
struct V_1 *
F_349 ( T_6 V_228 , unsigned int V_59 ,
struct V_188 * V_188 , T_10 * V_281 )
{
struct V_1 * V_1 ;
unsigned int V_329 ;
unsigned int V_163 = V_330 ;
T_6 V_331 = V_228 ;
struct V_186 V_187 = {
. V_288 = F_350 ( V_228 ) ,
. V_188 = V_188 ,
. V_281 = V_281 ,
. V_3 = F_338 ( V_228 ) ,
} ;
if ( F_305 () ) {
V_331 |= V_284 ;
V_163 |= V_257 ;
if ( ! V_187 . V_281 )
V_187 . V_281 = & V_332 ;
}
V_228 &= V_6 ;
F_351 ( V_228 ) ;
F_352 ( V_228 & V_233 ) ;
if ( F_286 ( V_228 , V_59 ) )
return NULL ;
if ( F_32 ( ! V_188 -> V_333 -> V_40 ) )
return NULL ;
if ( F_109 ( F_296 ) && V_187 . V_3 == V_137 )
V_163 |= V_248 ;
V_334:
V_329 = F_353 () ;
V_187 . V_258 = ( V_228 & V_335 ) ;
V_187 . V_254 = F_347 ( V_187 . V_188 ,
V_187 . V_288 , V_187 . V_281 ) ;
if ( ! V_187 . V_254 ) {
V_1 = NULL ;
goto V_336;
}
V_1 = F_303 ( V_331 , V_59 , V_163 , & V_187 ) ;
if ( F_95 ( V_1 ) )
goto V_53;
V_331 = F_354 ( V_228 ) ;
V_187 . V_258 = false ;
if ( F_305 () )
V_187 . V_281 = V_281 ;
V_1 = F_345 ( V_331 , V_59 , & V_187 ) ;
V_336:
if ( F_32 ( ! V_1 && F_355 ( V_329 ) ) ) {
V_331 = V_228 ;
goto V_334;
}
V_53:
if ( F_120 () && ( V_228 & V_337 ) && V_1 &&
F_32 ( F_356 ( V_1 , V_228 , V_59 ) != 0 ) ) {
F_167 ( V_1 , V_59 ) ;
V_1 = NULL ;
}
if ( V_338 && V_1 )
F_357 ( V_1 , V_59 , V_228 ) ;
F_358 ( V_1 , V_59 , V_331 , V_187 . V_3 ) ;
return V_1 ;
}
unsigned long F_359 ( T_6 V_228 , unsigned int V_59 )
{
struct V_1 * V_1 ;
F_93 ( ( V_228 & V_231 ) != 0 ) ;
V_1 = F_360 ( V_228 , V_59 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_127 ( V_1 ) ;
}
unsigned long F_361 ( T_6 V_228 )
{
return F_359 ( V_228 | V_164 , 0 ) ;
}
void F_167 ( struct V_1 * V_1 , unsigned int V_59 )
{
if ( F_362 ( V_1 ) ) {
if ( V_59 == 0 )
F_262 ( V_1 , false ) ;
else
F_53 ( V_1 , V_59 ) ;
}
}
void V_244 ( unsigned long V_339 , unsigned int V_59 )
{
if ( V_339 != 0 ) {
F_93 ( ! F_363 ( ( void * ) V_339 ) ) ;
F_167 ( F_271 ( ( void * ) V_339 ) , V_59 ) ;
}
}
static struct V_1 * F_364 ( struct V_340 * V_341 ,
T_6 V_228 )
{
struct V_1 * V_1 = NULL ;
T_6 V_342 = V_228 ;
#if ( V_102 < V_343 )
V_228 |= V_165 | V_269 | V_325 |
V_271 ;
V_1 = F_365 ( V_344 , V_228 ,
V_345 ) ;
V_341 -> V_157 = V_1 ? V_343 : V_102 ;
#endif
if ( F_32 ( ! V_1 ) )
V_1 = F_365 ( V_344 , V_342 , 0 ) ;
V_341 -> V_277 = V_1 ? F_127 ( V_1 ) : NULL ;
return V_1 ;
}
void * F_366 ( struct V_340 * V_341 ,
unsigned int V_346 , T_6 V_228 )
{
unsigned int V_157 = V_102 ;
struct V_1 * V_1 ;
int V_347 ;
if ( F_32 ( ! V_341 -> V_277 ) ) {
V_348:
V_1 = F_364 ( V_341 , V_228 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_102 < V_343 )
V_157 = V_341 -> V_157 ;
#endif
F_367 ( V_1 , V_157 - 1 ) ;
V_341 -> V_349 = F_368 ( V_1 ) ;
V_341 -> V_350 = V_157 ;
V_341 -> V_347 = V_157 ;
}
V_347 = V_341 -> V_347 - V_346 ;
if ( F_32 ( V_347 < 0 ) ) {
V_1 = F_271 ( V_341 -> V_277 ) ;
if ( ! F_369 ( V_1 , V_341 -> V_350 ) )
goto V_348;
#if ( V_102 < V_343 )
V_157 = V_341 -> V_157 ;
#endif
F_59 ( V_1 , V_157 ) ;
V_341 -> V_350 = V_157 ;
V_347 = V_157 - V_346 ;
}
V_341 -> V_350 -- ;
V_341 -> V_347 = V_347 ;
return V_341 -> V_277 + V_347 ;
}
void F_370 ( void * V_339 )
{
struct V_1 * V_1 = F_371 ( V_339 ) ;
if ( F_32 ( F_362 ( V_1 ) ) )
F_53 ( V_1 , F_54 ( V_1 ) ) ;
}
static void * F_372 ( unsigned long V_339 , unsigned int V_59 ,
T_11 V_157 )
{
if ( V_339 ) {
unsigned long V_351 = V_339 + ( V_102 << V_59 ) ;
unsigned long V_352 = V_339 + F_373 ( V_157 ) ;
F_268 ( F_271 ( ( void * ) V_339 ) , V_59 ) ;
while ( V_352 < V_351 ) {
F_374 ( V_352 ) ;
V_352 += V_102 ;
}
}
return ( void * ) V_339 ;
}
void * F_375 ( T_11 V_157 , T_6 V_228 )
{
unsigned int V_59 = F_376 ( V_157 ) ;
unsigned long V_339 ;
V_339 = F_359 ( V_228 , V_59 ) ;
return F_372 ( V_339 , V_59 , V_157 ) ;
}
void * T_2 F_377 ( int V_13 , T_11 V_157 , T_6 V_228 )
{
unsigned int V_59 = F_376 ( V_157 ) ;
struct V_1 * V_63 = F_365 ( V_13 , V_228 , V_59 ) ;
if ( ! V_63 )
return NULL ;
return F_372 ( ( unsigned long ) F_127 ( V_63 ) , V_59 , V_157 ) ;
}
void F_378 ( void * V_353 , T_11 V_157 )
{
unsigned long V_339 = ( unsigned long ) V_353 ;
unsigned long V_120 = V_339 + F_373 ( V_157 ) ;
while ( V_339 < V_120 ) {
F_374 ( V_339 ) ;
V_339 += V_102 ;
}
}
static unsigned long F_379 ( int V_347 )
{
struct V_189 * V_190 ;
struct V_40 * V_40 ;
unsigned long V_354 = 0 ;
struct V_188 * V_188 = F_346 ( F_278 () , V_355 ) ;
F_380 (zone, z, zonelist, offset) {
unsigned long V_157 = V_40 -> V_124 ;
unsigned long V_155 = F_381 ( V_40 ) ;
if ( V_157 > V_155 )
V_354 += V_157 - V_155 ;
}
return V_354 ;
}
unsigned long F_382 ( void )
{
return F_379 ( F_350 ( V_356 ) ) ;
}
unsigned long F_383 ( void )
{
return F_379 ( F_350 ( V_357 ) ) ;
}
static inline void F_384 ( struct V_40 * V_40 )
{
if ( F_109 ( F_277 ) )
F_385 ( L_27 , F_39 ( V_40 ) ) ;
}
long F_386 ( void )
{
long V_314 ;
unsigned long V_358 ;
unsigned long V_359 = 0 ;
unsigned long V_175 [ V_360 ] ;
struct V_40 * V_40 ;
int V_75 ;
for ( V_75 = V_361 ; V_75 < V_360 ; V_75 ++ )
V_175 [ V_75 ] = F_387 ( V_362 + V_75 ) ;
F_388 (zone)
V_359 += V_40 -> V_208 [ V_363 ] ;
V_314 = F_389 ( V_194 ) - V_364 ;
V_358 = V_175 [ V_365 ] + V_175 [ V_366 ] ;
V_358 -= F_176 ( V_358 / 2 , V_359 ) ;
V_314 += V_358 ;
V_314 += F_389 ( V_367 ) -
F_176 ( F_389 ( V_367 ) / 2 , V_359 ) ;
if ( V_314 < 0 )
V_314 = 0 ;
return V_314 ;
}
void F_390 ( struct V_368 * V_369 )
{
V_369 -> V_370 = V_371 ;
V_369 -> V_372 = F_387 ( V_373 ) ;
V_369 -> V_374 = F_389 ( V_194 ) ;
V_369 -> V_375 = F_391 () ;
V_369 -> V_376 = V_377 ;
V_369 -> V_378 = F_392 () ;
V_369 -> V_379 = V_102 ;
}
void F_393 ( struct V_368 * V_369 , int V_13 )
{
int V_380 ;
unsigned long V_124 = 0 ;
unsigned long V_381 = 0 ;
unsigned long V_382 = 0 ;
T_1 * V_9 = F_12 ( V_13 ) ;
for ( V_380 = 0 ; V_380 < V_117 ; V_380 ++ )
V_124 += V_9 -> V_118 [ V_380 ] . V_124 ;
V_369 -> V_370 = V_124 ;
V_369 -> V_372 = F_137 ( V_9 , V_373 ) ;
V_369 -> V_374 = F_394 ( V_13 , V_194 ) ;
#ifdef F_395
for ( V_380 = 0 ; V_380 < V_117 ; V_380 ++ ) {
struct V_40 * V_40 = & V_9 -> V_118 [ V_380 ] ;
if ( F_396 ( V_40 ) ) {
V_381 += V_40 -> V_124 ;
V_382 += F_297 ( V_40 , V_194 ) ;
}
}
V_369 -> V_376 = V_381 ;
V_369 -> V_378 = V_382 ;
#else
V_369 -> V_376 = V_381 ;
V_369 -> V_378 = V_382 ;
#endif
V_369 -> V_379 = V_102 ;
}
bool F_397 ( unsigned int V_34 , int V_13 )
{
bool V_41 = false ;
unsigned int V_329 ;
if ( ! ( V_34 & V_268 ) )
goto V_53;
do {
V_329 = F_353 () ;
V_41 = ! F_398 ( V_13 , V_332 ) ;
} while ( F_355 ( V_329 ) );
V_53:
return V_41 ;
}
static void F_399 ( unsigned char type )
{
static const char V_383 [ V_180 ] = {
[ V_38 ] = 'U' ,
[ V_137 ] = 'M' ,
[ V_173 ] = 'E' ,
[ V_185 ] = 'H' ,
#ifdef F_296
[ V_153 ] = 'C' ,
#endif
#ifdef F_400
[ V_384 ] = 'I' ,
#endif
} ;
char V_385 [ V_180 + 1 ] ;
char * V_63 = V_385 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_180 ; V_60 ++ ) {
if ( type & ( 1 << V_60 ) )
* V_63 ++ = V_383 [ V_60 ] ;
}
* V_63 = '\0' ;
F_385 ( L_28 , V_385 ) ;
}
void F_401 ( unsigned int V_267 )
{
unsigned long V_386 = 0 ;
int V_197 ;
struct V_40 * V_40 ;
T_1 * V_9 ;
F_198 (zone) {
if ( F_397 ( V_267 , F_39 ( V_40 ) ) )
continue;
F_251 (cpu)
V_386 += F_246 ( V_40 -> V_200 , V_197 ) -> V_105 . V_103 ;
}
F_385 ( L_29
L_30
L_31
L_32
L_33
L_34 ,
F_387 ( V_387 ) ,
F_387 ( V_388 ) ,
F_387 ( V_389 ) ,
F_387 ( V_390 ) ,
F_387 ( V_391 ) ,
F_387 ( V_392 ) ,
F_387 ( V_393 ) ,
F_387 ( V_394 ) ,
F_387 ( V_395 ) ,
F_387 ( V_396 ) ,
F_389 ( V_367 ) ,
F_389 ( V_397 ) ,
F_387 ( V_398 ) ,
F_387 ( V_373 ) ,
F_389 ( V_399 ) ,
F_389 ( V_400 ) ,
F_389 ( V_194 ) ,
V_386 ,
F_389 ( V_193 ) ) ;
F_402 (pgdat) {
F_385 ( L_35
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
#ifdef F_403
L_47
L_48
L_49
#endif
L_50
L_51
L_52
L_53
L_54 ,
V_9 -> V_141 ,
F_404 ( F_137 ( V_9 , V_387 ) ) ,
F_404 ( F_137 ( V_9 , V_388 ) ) ,
F_404 ( F_137 ( V_9 , V_390 ) ) ,
F_404 ( F_137 ( V_9 , V_391 ) ) ,
F_404 ( F_137 ( V_9 , V_393 ) ) ,
F_404 ( F_137 ( V_9 , V_389 ) ) ,
F_404 ( F_137 ( V_9 , V_392 ) ) ,
F_404 ( F_137 ( V_9 , V_398 ) ) ,
F_404 ( F_137 ( V_9 , V_394 ) ) ,
F_404 ( F_137 ( V_9 , V_395 ) ) ,
#ifdef F_403
F_404 ( F_137 ( V_9 , V_401 ) * V_402 ) ,
F_404 ( F_137 ( V_9 , V_403 )
* V_402 ) ,
F_404 ( F_137 ( V_9 , V_404 ) * V_402 ) ,
#endif
F_404 ( F_137 ( V_9 , V_373 ) ) ,
F_404 ( F_137 ( V_9 , V_405 ) ) ,
F_404 ( F_137 ( V_9 , V_396 ) ) ,
F_137 ( V_9 , V_111 ) ,
! F_405 ( V_9 ) ? L_55 : L_56 ) ;
}
F_198 (zone) {
int V_60 ;
if ( F_397 ( V_267 , F_39 ( V_40 ) ) )
continue;
V_386 = 0 ;
F_251 (cpu)
V_386 += F_246 ( V_40 -> V_200 , V_197 ) -> V_105 . V_103 ;
F_384 ( V_40 ) ;
F_385 ( L_57
L_58
L_59
L_60
L_61
L_36
L_37
L_38
L_39
L_40
L_62
L_63
L_64
L_65
L_66
L_67
L_68
L_69
L_70
L_71
L_72
L_73
L_54 ,
V_40 -> V_46 ,
F_404 ( F_297 ( V_40 , V_194 ) ) ,
F_404 ( F_327 ( V_40 ) ) ,
F_404 ( F_274 ( V_40 ) ) ,
F_404 ( F_381 ( V_40 ) ) ,
F_404 ( F_297 ( V_40 , V_406 ) ) ,
F_404 ( F_297 ( V_40 , V_407 ) ) ,
F_404 ( F_297 ( V_40 , V_408 ) ) ,
F_404 ( F_297 ( V_40 , V_409 ) ) ,
F_404 ( F_297 ( V_40 , V_410 ) ) ,
F_404 ( F_297 ( V_40 , V_317 ) ) ,
F_404 ( V_40 -> V_411 ) ,
F_404 ( V_40 -> V_124 ) ,
F_404 ( F_297 ( V_40 , V_412 ) ) ,
F_404 ( F_297 ( V_40 , V_367 ) ) ,
F_404 ( F_297 ( V_40 , V_397 ) ) ,
F_297 ( V_40 , V_413 ) ,
F_404 ( F_297 ( V_40 , V_399 ) ) ,
F_404 ( F_297 ( V_40 , V_400 ) ) ,
F_404 ( V_386 ) ,
F_404 ( F_406 ( V_40 -> V_200 -> V_105 . V_103 ) ) ,
F_404 ( F_297 ( V_40 , V_193 ) ) ) ;
F_385 ( L_74 ) ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ )
F_385 ( L_75 , V_40 -> V_249 [ V_60 ] ) ;
F_385 ( L_54 ) ;
}
F_198 (zone) {
unsigned int V_59 ;
unsigned long V_414 [ V_71 ] , V_34 , V_415 = 0 ;
unsigned char V_383 [ V_71 ] ;
if ( F_397 ( V_267 , F_39 ( V_40 ) ) )
continue;
F_384 ( V_40 ) ;
F_385 ( L_76 , V_40 -> V_46 ) ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_85 * V_156 = & V_40 -> V_85 [ V_59 ] ;
int type ;
V_414 [ V_59 ] = V_156 -> V_86 ;
V_415 += V_414 [ V_59 ] << V_59 ;
V_383 [ V_59 ] = 0 ;
for ( type = 0 ; type < V_180 ; type ++ ) {
if ( ! F_139 ( & V_156 -> V_90 [ type ] ) )
V_383 [ V_59 ] |= 1 << type ;
}
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
F_385 ( L_77 , V_414 [ V_59 ] , F_404 ( 1UL ) << V_59 ) ;
if ( V_414 [ V_59 ] )
F_399 ( V_383 [ V_59 ] ) ;
}
F_385 ( L_78 , F_404 ( V_415 ) ) ;
}
F_407 () ;
F_385 ( L_79 , F_387 ( V_416 ) ) ;
F_408 () ;
}
static void F_409 ( struct V_40 * V_40 , struct V_189 * V_189 )
{
V_189 -> V_40 = V_40 ;
V_189 -> V_417 = V_417 ( V_40 ) ;
}
static int F_410 ( T_1 * V_9 , struct V_188 * V_188 ,
int V_418 )
{
struct V_40 * V_40 ;
enum V_380 V_380 = V_117 ;
do {
V_380 -- ;
V_40 = V_9 -> V_118 + V_380 ;
if ( F_411 ( V_40 ) ) {
F_409 ( V_40 ,
& V_188 -> V_333 [ V_418 ++ ] ) ;
F_412 ( V_380 ) ;
}
} while ( V_380 );
return V_418 ;
}
static int F_413 ( char * V_419 )
{
if ( * V_419 == 'd' || * V_419 == 'D' ) {
V_420 = V_421 ;
} else if ( * V_419 == 'n' || * V_419 == 'N' ) {
V_420 = V_422 ;
} else if ( * V_419 == 'z' || * V_419 == 'Z' ) {
V_420 = V_423 ;
} else {
F_315 ( L_80 , V_419 ) ;
return - V_67 ;
}
return 0 ;
}
static T_4 int F_414 ( char * V_419 )
{
int V_41 ;
if ( ! V_419 )
return 0 ;
V_41 = F_413 ( V_419 ) ;
if ( V_41 == 0 )
F_415 ( V_424 , V_419 , V_425 ) ;
return V_41 ;
}
int F_416 ( struct V_426 * V_427 , int V_428 ,
void T_12 * V_429 , T_11 * V_430 ,
T_13 * V_431 )
{
char V_432 [ V_425 ] ;
int V_41 ;
static F_417 ( V_433 ) ;
F_418 ( & V_433 ) ;
if ( V_428 ) {
if ( strlen ( ( char * ) V_427 -> V_140 ) >= V_425 ) {
V_41 = - V_67 ;
goto V_53;
}
strcpy ( V_432 , ( char * ) V_427 -> V_140 ) ;
}
V_41 = F_419 ( V_427 , V_428 , V_429 , V_430 , V_431 ) ;
if ( V_41 )
goto V_53;
if ( V_428 ) {
int V_434 = V_420 ;
V_41 = F_413 ( ( char * ) V_427 -> V_140 ) ;
if ( V_41 ) {
strncpy ( ( char * ) V_427 -> V_140 , V_432 ,
V_425 ) ;
V_420 = V_434 ;
} else if ( V_434 != V_420 ) {
F_418 ( & V_435 ) ;
F_420 ( NULL , NULL ) ;
F_321 ( & V_435 ) ;
}
}
V_53:
F_321 ( & V_433 ) ;
return V_41 ;
}
static int F_421 ( int V_128 , T_10 * V_436 )
{
int V_437 , V_369 ;
int V_438 = V_439 ;
int V_440 = V_344 ;
const struct V_146 * V_385 = F_183 ( 0 ) ;
if ( ! F_398 ( V_128 , * V_436 ) ) {
F_422 ( V_128 , * V_436 ) ;
return V_128 ;
}
F_194 (n, N_MEMORY) {
if ( F_398 ( V_437 , * V_436 ) )
continue;
V_369 = F_302 ( V_128 , V_437 ) ;
V_369 += ( V_437 < V_128 ) ;
V_385 = F_183 ( V_437 ) ;
if ( ! F_184 ( V_385 ) )
V_369 += V_441 ;
V_369 *= ( V_442 * V_443 ) ;
V_369 += V_444 [ V_437 ] ;
if ( V_369 < V_438 ) {
V_438 = V_369 ;
V_440 = V_437 ;
}
}
if ( V_440 >= 0 )
F_422 ( V_440 , * V_436 ) ;
return V_440 ;
}
static void F_423 ( T_1 * V_9 , int V_128 )
{
int V_445 ;
struct V_188 * V_188 ;
V_188 = & V_9 -> V_446 [ 0 ] ;
for ( V_445 = 0 ; V_188 -> V_333 [ V_445 ] . V_40 != NULL ; V_445 ++ )
;
V_445 = F_410 ( F_12 ( V_128 ) , V_188 , V_445 ) ;
V_188 -> V_333 [ V_445 ] . V_40 = NULL ;
V_188 -> V_333 [ V_445 ] . V_417 = 0 ;
}
static void F_424 ( T_1 * V_9 )
{
int V_445 ;
struct V_188 * V_188 ;
V_188 = & V_9 -> V_446 [ 1 ] ;
V_445 = F_410 ( V_9 , V_188 , 0 ) ;
V_188 -> V_333 [ V_445 ] . V_40 = NULL ;
V_188 -> V_333 [ V_445 ] . V_417 = 0 ;
}
static void F_425 ( T_1 * V_9 , int V_447 )
{
int V_448 , V_445 , V_128 ;
int V_380 ;
struct V_40 * V_190 ;
struct V_188 * V_188 ;
V_188 = & V_9 -> V_446 [ 0 ] ;
V_448 = 0 ;
for ( V_380 = V_117 - 1 ; V_380 >= 0 ; V_380 -- ) {
for ( V_445 = 0 ; V_445 < V_447 ; V_445 ++ ) {
V_128 = V_449 [ V_445 ] ;
V_190 = & F_12 ( V_128 ) -> V_118 [ V_380 ] ;
if ( F_411 ( V_190 ) ) {
F_409 ( V_190 ,
& V_188 -> V_333 [ V_448 ++ ] ) ;
F_412 ( V_380 ) ;
}
}
}
V_188 -> V_333 [ V_448 ] . V_40 = NULL ;
V_188 -> V_333 [ V_448 ] . V_417 = 0 ;
}
static int F_426 ( void )
{
return V_422 ;
}
static int F_426 ( void )
{
return V_423 ;
}
static void F_427 ( void )
{
if ( V_420 == V_421 )
V_450 = F_426 () ;
else
V_450 = V_420 ;
}
static void F_428 ( T_1 * V_9 )
{
int V_60 , V_128 , V_451 ;
T_10 V_452 ;
int V_453 , V_454 ;
struct V_188 * V_188 ;
unsigned int V_59 = V_450 ;
for ( V_60 = 0 ; V_60 < V_455 ; V_60 ++ ) {
V_188 = V_9 -> V_446 + V_60 ;
V_188 -> V_333 [ 0 ] . V_40 = NULL ;
V_188 -> V_333 [ 0 ] . V_417 = 0 ;
}
V_453 = V_9 -> V_141 ;
V_451 = V_456 ;
V_454 = V_453 ;
F_429 ( V_452 ) ;
memset ( V_449 , 0 , sizeof( V_449 ) ) ;
V_60 = 0 ;
while ( ( V_128 = F_421 ( V_453 , & V_452 ) ) >= 0 ) {
if ( F_302 ( V_453 , V_128 ) !=
F_302 ( V_453 , V_454 ) )
V_444 [ V_128 ] = V_451 ;
V_454 = V_128 ;
V_451 -- ;
if ( V_59 == V_422 )
F_423 ( V_9 , V_128 ) ;
else
V_449 [ V_60 ++ ] = V_128 ;
}
if ( V_59 == V_423 ) {
F_425 ( V_9 , V_60 ) ;
}
F_424 ( V_9 ) ;
}
int F_430 ( int V_128 )
{
struct V_189 * V_190 ;
V_190 = F_347 ( F_346 ( V_128 , V_355 ) ,
F_350 ( V_355 ) ,
NULL ) ;
return V_190 -> V_40 -> V_128 ;
}
static void F_427 ( void )
{
V_450 = V_423 ;
}
static void F_428 ( T_1 * V_9 )
{
int V_128 , V_453 ;
enum V_380 V_445 ;
struct V_188 * V_188 ;
V_453 = V_9 -> V_141 ;
V_188 = & V_9 -> V_446 [ 0 ] ;
V_445 = F_410 ( V_9 , V_188 , 0 ) ;
for ( V_128 = V_453 + 1 ; V_128 < V_443 ; V_128 ++ ) {
if ( ! F_11 ( V_128 ) )
continue;
V_445 = F_410 ( F_12 ( V_128 ) , V_188 , V_445 ) ;
}
for ( V_128 = 0 ; V_128 < V_453 ; V_128 ++ ) {
if ( ! F_11 ( V_128 ) )
continue;
V_445 = F_410 ( F_12 ( V_128 ) , V_188 , V_445 ) ;
}
V_188 -> V_333 [ V_445 ] . V_40 = NULL ;
V_188 -> V_333 [ V_445 ] . V_417 = 0 ;
}
static int F_431 ( void * V_140 )
{
int V_13 ;
int V_197 ;
T_1 * V_457 = V_140 ;
#ifdef F_277
memset ( V_444 , 0 , sizeof( V_444 ) ) ;
#endif
if ( V_457 && ! F_11 ( V_457 -> V_141 ) ) {
F_428 ( V_457 ) ;
}
F_432 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_428 ( V_9 ) ;
}
F_433 (cpu) {
F_434 ( & F_435 ( V_458 , V_197 ) , 0 ) ;
#ifdef F_436
if ( F_437 ( V_197 ) )
F_438 ( V_197 , F_430 ( F_439 ( V_197 ) ) ) ;
#endif
}
return 0 ;
}
static T_14 void T_4
F_440 ( void )
{
F_431 ( NULL ) ;
F_441 () ;
F_442 () ;
}
void T_15 F_420 ( T_1 * V_9 , struct V_40 * V_40 )
{
F_427 () ;
if ( V_459 == V_460 ) {
F_440 () ;
} else {
#ifdef F_443
if ( V_40 )
F_444 ( V_40 ) ;
#endif
F_445 ( F_431 , V_9 , NULL ) ;
}
V_461 = F_383 () ;
if ( V_461 < ( V_24 * V_180 ) )
V_36 = 1 ;
else
V_36 = 0 ;
F_70 ( L_81 ,
V_456 ,
V_462 [ V_450 ] ,
V_36 ? L_82 : L_83 ,
V_461 ) ;
#ifdef F_277
F_70 ( L_84 , V_463 [ V_464 ] ) ;
#endif
}
static inline unsigned long F_446 ( unsigned long V_175 )
{
unsigned long V_157 = 1 ;
V_175 /= V_465 ;
while ( V_157 < V_175 )
V_157 <<= 1 ;
V_157 = F_176 ( V_157 , 4096UL ) ;
return F_15 ( V_157 , 4UL ) ;
}
static inline unsigned long F_446 ( unsigned long V_175 )
{
return 4096UL ;
}
static inline unsigned long F_447 ( unsigned long V_157 )
{
return F_448 ( ~ V_157 ) ;
}
void T_2 F_449 ( unsigned long V_157 , int V_13 , unsigned long V_40 ,
unsigned long V_44 , enum V_466 V_467 )
{
struct V_468 * V_469 = F_450 ( F_451 ( V_44 ) ) ;
unsigned long V_121 = V_44 + V_157 ;
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_12 ;
unsigned long V_15 = 0 ;
#ifdef F_452
struct V_470 * V_471 = NULL , * V_385 ;
#endif
if ( V_472 < V_121 - 1 )
V_472 = V_121 - 1 ;
if ( V_469 && V_44 == V_469 -> V_473 )
V_44 += V_469 -> V_474 ;
for ( V_12 = V_44 ; V_12 < V_121 ; V_12 ++ ) {
if ( V_467 != V_475 )
goto V_476;
if ( ! F_453 ( V_12 ) )
continue;
if ( ! F_171 ( V_12 , V_13 ) )
continue;
if ( ! F_13 ( V_9 , V_12 , V_121 , & V_15 ) )
break;
#ifdef F_452
if ( ! V_477 && V_478 [ V_13 ] )
if ( V_40 == V_289 && V_12 >= V_478 [ V_13 ] )
continue;
if ( V_477 && V_40 == V_479 ) {
if ( ! V_471 || V_12 >= F_454 ( V_471 ) ) {
F_455 (memory, tmp)
if ( V_12 < F_454 ( V_385 ) )
break;
V_471 = V_385 ;
}
if ( V_12 >= F_456 ( V_471 ) &&
F_457 ( V_471 ) ) {
V_12 = F_454 ( V_471 ) ;
continue;
}
}
#endif
V_476:
if ( ! ( V_12 & ( V_24 - 1 ) ) ) {
struct V_1 * V_1 = F_152 ( V_12 ) ;
F_144 ( V_1 , V_12 , V_40 , V_13 ) ;
F_31 ( V_1 , V_137 ) ;
} else {
F_151 ( V_12 , V_40 , V_13 ) ;
}
}
}
static void T_2 F_458 ( struct V_40 * V_40 )
{
unsigned int V_59 , V_205 ;
F_259 (order, t) {
F_75 ( & V_40 -> V_85 [ V_59 ] . V_90 [ V_205 ] ) ;
V_40 -> V_85 [ V_59 ] . V_86 = 0 ;
}
}
static int F_459 ( struct V_40 * V_40 )
{
#ifdef F_460
int V_196 ;
V_196 = V_40 -> V_124 / 1024 ;
if ( V_196 * V_102 > 512 * 1024 )
V_196 = ( 512 * 1024 ) / V_102 ;
V_196 /= 4 ;
if ( V_196 < 1 )
V_196 = 1 ;
V_196 = F_461 ( V_196 + V_196 / 2 ) - 1 ;
return V_196 ;
#else
return 0 ;
#endif
}
static void F_462 ( struct V_104 * V_105 , unsigned long V_155 ,
unsigned long V_196 )
{
V_105 -> V_196 = 1 ;
F_463 () ;
V_105 -> V_155 = V_155 ;
F_463 () ;
V_105 -> V_196 = V_196 ;
}
static void F_464 ( struct V_198 * V_63 , unsigned long V_196 )
{
F_462 ( & V_63 -> V_105 , 6 * V_196 , F_15 ( 1UL , 1 * V_196 ) ) ;
}
static void F_465 ( struct V_198 * V_63 )
{
struct V_104 * V_105 ;
int V_3 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_105 = & V_63 -> V_105 ;
V_105 -> V_103 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ )
F_75 ( & V_105 -> V_114 [ V_3 ] ) ;
}
static void F_434 ( struct V_198 * V_63 , unsigned long V_196 )
{
F_465 ( V_63 ) ;
F_464 ( V_63 , V_196 ) ;
}
static void F_466 ( struct V_198 * V_63 ,
unsigned long V_155 )
{
unsigned long V_196 = F_15 ( 1UL , V_155 / 4 ) ;
if ( ( V_155 / 4 ) > ( V_17 * 8 ) )
V_196 = V_17 * 8 ;
F_462 ( & V_63 -> V_105 , V_155 , V_196 ) ;
}
static void F_467 ( struct V_40 * V_40 ,
struct V_198 * V_105 )
{
if ( V_480 )
F_466 ( V_105 ,
( V_40 -> V_124 /
V_480 ) ) ;
else
F_464 ( V_105 , F_459 ( V_40 ) ) ;
}
static void T_2 F_468 ( struct V_40 * V_40 , int V_197 )
{
struct V_198 * V_105 = F_246 ( V_40 -> V_200 , V_197 ) ;
F_465 ( V_105 ) ;
F_467 ( V_40 , V_105 ) ;
}
static void T_2 F_444 ( struct V_40 * V_40 )
{
int V_197 ;
V_40 -> V_200 = F_469 ( struct V_198 ) ;
F_433 (cpu)
F_468 ( V_40 , V_197 ) ;
}
void T_4 F_470 ( void )
{
struct V_255 * V_9 ;
struct V_40 * V_40 ;
F_198 (zone)
F_444 ( V_40 ) ;
F_402 (pgdat)
V_9 -> V_481 =
F_469 ( struct V_482 ) ;
}
static T_14 T_15
int F_471 ( struct V_40 * V_40 , unsigned long V_483 )
{
int V_60 ;
T_11 V_484 ;
V_40 -> F_446 =
F_446 ( V_483 ) ;
V_40 -> F_447 =
F_447 ( V_40 -> F_446 ) ;
V_484 = V_40 -> F_446
* sizeof( V_485 ) ;
if ( ! F_472 () ) {
V_40 -> V_486 = ( V_485 * )
F_473 (
V_484 , V_40 -> V_110 -> V_141 ) ;
} else {
V_40 -> V_486 = F_474 ( V_484 ) ;
}
if ( ! V_40 -> V_486 )
return - V_241 ;
for ( V_60 = 0 ; V_60 < V_40 -> F_446 ; ++ V_60 )
F_475 ( V_40 -> V_486 + V_60 ) ;
return 0 ;
}
static T_2 void F_476 ( struct V_40 * V_40 )
{
V_40 -> V_200 = & V_458 ;
if ( F_189 ( V_40 ) )
F_385 ( V_487 L_85 ,
V_40 -> V_46 , V_40 -> V_411 ,
F_459 ( V_40 ) ) ;
}
int T_2 F_477 ( struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_157 )
{
struct V_255 * V_9 = V_40 -> V_110 ;
int V_41 ;
V_41 = F_471 ( V_40 , V_157 ) ;
if ( V_41 )
return V_41 ;
V_9 -> V_418 = V_417 ( V_40 ) + 1 ;
V_40 -> V_23 = V_23 ;
F_478 ( V_488 , L_86 ,
L_87 ,
V_9 -> V_141 ,
( unsigned long ) V_417 ( V_40 ) ,
V_23 , ( V_23 + V_157 ) ) ;
F_458 ( V_40 ) ;
return 0 ;
}
int T_2 F_169 ( unsigned long V_12 ,
struct V_129 * V_130 )
{
unsigned long V_44 , V_121 ;
int V_13 ;
if ( V_130 -> V_489 <= V_12 && V_12 < V_130 -> V_490 )
return V_130 -> V_491 ;
V_13 = F_479 ( V_12 , & V_44 , & V_121 ) ;
if ( V_13 != - 1 ) {
V_130 -> V_489 = V_44 ;
V_130 -> V_490 = V_121 ;
V_130 -> V_491 = V_13 ;
}
return V_13 ;
}
void T_4 F_480 ( int V_13 , unsigned long V_492 )
{
unsigned long V_44 , V_121 ;
int V_60 , V_493 ;
F_187 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_44 = F_176 ( V_44 , V_492 ) ;
V_121 = F_176 ( V_121 , V_492 ) ;
if ( V_44 < V_121 )
F_481 ( F_482 ( V_44 ) ,
( V_121 - V_44 ) << V_17 ,
V_493 ) ;
}
}
void T_4 F_483 ( int V_13 )
{
unsigned long V_44 , V_121 ;
int V_60 , V_493 ;
F_187 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_484 ( V_493 , V_44 , V_121 ) ;
}
void T_2 F_485 ( unsigned int V_13 ,
unsigned long * V_44 , unsigned long * V_121 )
{
unsigned long V_494 , V_495 ;
int V_60 ;
* V_44 = - 1UL ;
* V_121 = 0 ;
F_187 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_44 = F_176 ( * V_44 , V_494 ) ;
* V_121 = F_15 ( * V_121 , V_495 ) ;
}
if ( * V_44 == - 1UL )
* V_44 = 0 ;
}
static void T_4 F_486 ( void )
{
int V_496 ;
for ( V_496 = V_117 - 1 ; V_496 >= 0 ; V_496 -- ) {
if ( V_496 == V_479 )
continue;
if ( V_497 [ V_496 ] >
V_498 [ V_496 ] )
break;
}
F_93 ( V_496 == - 1 ) ;
V_499 = V_496 ;
}
static void T_2 F_487 ( int V_13 ,
unsigned long V_380 ,
unsigned long V_147 ,
unsigned long V_500 ,
unsigned long * V_23 ,
unsigned long * F_154 )
{
if ( V_478 [ V_13 ] ) {
if ( V_380 == V_479 ) {
* V_23 = V_478 [ V_13 ] ;
* F_154 = F_176 ( V_500 ,
V_497 [ V_499 ] ) ;
} else if ( * V_23 >= V_478 [ V_13 ] )
* V_23 = * F_154 ;
}
}
static unsigned long T_2 F_488 ( int V_13 ,
unsigned long V_380 ,
unsigned long V_147 ,
unsigned long V_500 ,
unsigned long * V_23 ,
unsigned long * F_154 ,
unsigned long * V_501 )
{
if ( ! V_147 && ! V_500 )
return 0 ;
* V_23 = V_498 [ V_380 ] ;
* F_154 = V_497 [ V_380 ] ;
F_487 ( V_13 , V_380 ,
V_147 , V_500 ,
V_23 , F_154 ) ;
if ( * F_154 < V_147 || * V_23 > V_500 )
return 0 ;
* F_154 = F_176 ( * F_154 , V_500 ) ;
* V_23 = F_15 ( * V_23 , V_147 ) ;
return * F_154 - * V_23 ;
}
unsigned long T_2 F_489 ( int V_13 ,
unsigned long V_502 ,
unsigned long V_503 )
{
unsigned long V_504 = V_503 - V_502 ;
unsigned long V_44 , V_121 ;
int V_60 ;
F_187 (i, nid, &start_pfn, &end_pfn, NULL) {
V_44 = F_490 ( V_44 , V_502 , V_503 ) ;
V_121 = F_490 ( V_121 , V_502 , V_503 ) ;
V_504 -= V_121 - V_44 ;
}
return V_504 ;
}
unsigned long T_4 F_491 ( unsigned long V_44 ,
unsigned long V_121 )
{
return F_489 ( V_443 , V_44 , V_121 ) ;
}
static unsigned long T_2 F_492 ( int V_13 ,
unsigned long V_380 ,
unsigned long V_147 ,
unsigned long V_500 ,
unsigned long * V_501 )
{
unsigned long V_505 = V_498 [ V_380 ] ;
unsigned long V_506 = V_497 [ V_380 ] ;
unsigned long V_23 , F_154 ;
unsigned long V_504 ;
if ( ! V_147 && ! V_500 )
return 0 ;
V_23 = F_490 ( V_147 , V_505 , V_506 ) ;
F_154 = F_490 ( V_500 , V_505 , V_506 ) ;
F_487 ( V_13 , V_380 ,
V_147 , V_500 ,
& V_23 , & F_154 ) ;
V_504 = F_489 ( V_13 , V_23 , F_154 ) ;
if ( V_478 [ V_13 ] ) {
if ( V_477 ) {
unsigned long V_44 , V_121 ;
struct V_470 * V_471 ;
F_455 (memory, r) {
V_44 = F_490 ( F_456 ( V_471 ) ,
V_23 , F_154 ) ;
V_121 = F_490 ( F_454 ( V_471 ) ,
V_23 , F_154 ) ;
if ( V_380 == V_479 &&
F_457 ( V_471 ) )
V_504 += V_121 - V_44 ;
if ( V_380 == V_289 &&
! F_457 ( V_471 ) )
V_504 += V_121 - V_44 ;
}
} else {
if ( V_380 == V_289 )
V_504 += V_500 - V_478 [ V_13 ] ;
}
}
return V_504 ;
}
static inline unsigned long T_2 F_488 ( int V_13 ,
unsigned long V_380 ,
unsigned long V_147 ,
unsigned long V_500 ,
unsigned long * V_23 ,
unsigned long * F_154 ,
unsigned long * V_507 )
{
unsigned int V_40 ;
* V_23 = V_147 ;
for ( V_40 = 0 ; V_40 < V_380 ; V_40 ++ )
* V_23 += V_507 [ V_40 ] ;
* F_154 = * V_23 + V_507 [ V_380 ] ;
return V_507 [ V_380 ] ;
}
static inline unsigned long T_2 F_492 ( int V_13 ,
unsigned long V_380 ,
unsigned long V_147 ,
unsigned long V_500 ,
unsigned long * V_508 )
{
if ( ! V_508 )
return 0 ;
return V_508 [ V_380 ] ;
}
static void T_2 F_493 ( struct V_255 * V_9 ,
unsigned long V_147 ,
unsigned long V_500 ,
unsigned long * V_507 ,
unsigned long * V_508 )
{
unsigned long V_509 = 0 , V_510 = 0 ;
enum V_380 V_60 ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_60 ;
unsigned long V_23 , F_154 ;
unsigned long V_157 , V_511 ;
V_157 = F_488 ( V_9 -> V_141 , V_60 ,
V_147 ,
V_500 ,
& V_23 ,
& F_154 ,
V_507 ) ;
V_511 = V_157 - F_492 ( V_9 -> V_141 , V_60 ,
V_147 , V_500 ,
V_508 ) ;
if ( V_157 )
V_40 -> V_23 = V_23 ;
else
V_40 -> V_23 = 0 ;
V_40 -> V_45 = V_157 ;
V_40 -> V_411 = V_511 ;
V_510 += V_157 ;
V_509 += V_511 ;
}
V_9 -> V_18 = V_510 ;
V_9 -> V_512 = V_509 ;
F_385 ( V_487 L_88 , V_9 -> V_141 ,
V_509 ) ;
}
static unsigned long T_4 F_494 ( unsigned long V_23 , unsigned long V_513 )
{
unsigned long V_514 ;
V_513 += V_23 & ( V_24 - 1 ) ;
V_514 = F_495 ( V_513 , V_24 ) ;
V_514 = V_514 >> V_21 ;
V_514 *= V_22 ;
V_514 = F_495 ( V_514 , 8 * sizeof( unsigned long ) ) ;
return V_514 / 8 ;
}
static void T_4 F_496 ( struct V_255 * V_9 ,
struct V_40 * V_40 ,
unsigned long V_23 ,
unsigned long V_513 )
{
unsigned long V_514 = F_494 ( V_23 , V_513 ) ;
V_40 -> V_20 = NULL ;
if ( V_514 )
V_40 -> V_20 =
F_473 ( V_514 ,
V_9 -> V_141 ) ;
}
static inline void F_496 ( struct V_255 * V_9 , struct V_40 * V_40 ,
unsigned long V_23 , unsigned long V_513 ) {}
void T_16 F_497 ( void )
{
unsigned int V_59 ;
if ( V_21 )
return;
if ( V_515 > V_17 )
V_59 = V_516 ;
else
V_59 = V_71 - 1 ;
V_21 = V_59 ;
}
void T_16 F_497 ( void )
{
}
static unsigned long T_16 F_498 ( unsigned long V_45 ,
unsigned long V_411 )
{
unsigned long V_175 = V_45 ;
if ( V_45 > V_411 + ( V_411 >> 4 ) &&
F_109 ( F_17 ) )
V_175 = V_411 ;
return F_373 ( V_175 * sizeof( struct V_1 ) ) >> V_17 ;
}
static void T_16 F_499 ( struct V_255 * V_9 )
{
enum V_380 V_445 ;
int V_13 = V_9 -> V_141 ;
int V_41 ;
F_500 ( V_9 ) ;
#ifdef F_501
F_502 ( & V_9 -> V_517 ) ;
V_9 -> V_518 = 0 ;
V_9 -> V_519 = V_52 ;
#endif
#ifdef F_403
F_502 ( & V_9 -> V_520 ) ;
F_75 ( & V_9 -> V_521 ) ;
V_9 -> V_522 = 0 ;
#endif
F_475 ( & V_9 -> V_523 ) ;
F_475 ( & V_9 -> V_524 ) ;
#ifdef F_503
F_475 ( & V_9 -> V_525 ) ;
#endif
F_504 ( V_9 ) ;
F_502 ( & V_9 -> V_526 ) ;
F_505 ( F_506 ( V_9 ) ) ;
for ( V_445 = 0 ; V_445 < V_117 ; V_445 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_445 ;
unsigned long V_157 , V_527 , V_528 , V_529 ;
unsigned long V_23 = V_40 -> V_23 ;
V_157 = V_40 -> V_45 ;
V_527 = V_528 = V_40 -> V_411 ;
V_529 = F_498 ( V_157 , V_527 ) ;
if ( ! F_148 ( V_445 ) ) {
if ( V_528 >= V_529 ) {
V_528 -= V_529 ;
if ( V_529 )
F_385 ( V_487
L_89 ,
V_463 [ V_445 ] , V_529 ) ;
} else
F_315 ( L_90 ,
V_463 [ V_445 ] , V_529 , V_528 ) ;
}
if ( V_445 == 0 && V_528 > V_530 ) {
V_528 -= V_530 ;
F_385 ( V_487 L_91 ,
V_463 [ 0 ] , V_530 ) ;
}
if ( ! F_148 ( V_445 ) )
V_531 += V_528 ;
else if ( V_531 > V_529 * 2 )
V_531 -= V_529 ;
V_532 += V_528 ;
V_40 -> V_124 = F_148 ( V_445 ) ? V_527 : V_528 ;
#ifdef F_277
V_40 -> V_128 = V_13 ;
#endif
V_40 -> V_46 = V_463 [ V_445 ] ;
V_40 -> V_110 = V_9 ;
F_502 ( & V_40 -> V_109 ) ;
F_507 ( V_40 ) ;
F_476 ( V_40 ) ;
if ( ! V_157 )
continue;
F_497 () ;
F_496 ( V_9 , V_40 , V_23 , V_157 ) ;
V_41 = F_477 ( V_40 , V_23 , V_157 ) ;
F_186 ( V_41 ) ;
F_508 ( V_157 , V_13 , V_445 , V_23 ) ;
}
}
static void T_15 F_509 ( struct V_255 * V_9 )
{
unsigned long T_17 V_119 = 0 ;
unsigned long T_17 V_347 = 0 ;
if ( ! V_9 -> V_18 )
return;
#ifdef F_510
V_119 = V_9 -> V_147 & ~ ( V_136 - 1 ) ;
V_347 = V_9 -> V_147 - V_119 ;
if ( ! V_9 -> V_533 ) {
unsigned long V_157 , V_120 ;
struct V_1 * V_534 ;
V_120 = F_14 ( V_9 ) ;
V_120 = F_175 ( V_120 , V_136 ) ;
V_157 = ( V_120 - V_119 ) * sizeof( struct V_1 ) ;
V_534 = F_511 ( V_9 -> V_141 , V_157 ) ;
if ( ! V_534 )
V_534 = F_473 ( V_157 ,
V_9 -> V_141 ) ;
V_9 -> V_533 = V_534 + V_347 ;
}
#ifndef F_512
if ( V_9 == F_12 ( 0 ) ) {
V_535 = F_12 ( 0 ) -> V_533 ;
#if F_513 ( F_452 ) || F_513 ( V_536 )
if ( F_35 ( V_535 ) != V_9 -> V_147 )
V_535 -= V_347 ;
#endif
}
#endif
#endif
}
void T_16 F_514 ( int V_13 , unsigned long * V_507 ,
unsigned long V_147 , unsigned long * V_508 )
{
T_1 * V_9 = F_12 ( V_13 ) ;
unsigned long V_44 = 0 ;
unsigned long V_121 = 0 ;
F_4 ( V_9 -> V_418 || V_9 -> V_537 ) ;
F_8 ( V_9 ) ;
V_9 -> V_141 = V_13 ;
V_9 -> V_147 = V_147 ;
V_9 -> V_481 = NULL ;
#ifdef F_452
F_485 ( V_13 , & V_44 , & V_121 ) ;
F_70 ( L_92 , V_13 ,
( V_538 ) V_44 << V_17 ,
V_121 ? ( ( V_538 ) V_121 << V_17 ) - 1 : 0 ) ;
#else
V_44 = V_147 ;
#endif
F_493 ( V_9 , V_44 , V_121 ,
V_507 , V_508 ) ;
F_509 ( V_9 ) ;
#ifdef F_510
F_385 ( V_487 L_93 ,
V_13 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_533 ) ;
#endif
F_499 ( V_9 ) ;
}
void T_4 F_515 ( void )
{
unsigned int V_539 ;
V_539 = F_516 ( V_540 . V_541 , V_443 ) ;
V_542 = V_539 + 1 ;
}
unsigned long T_4 F_517 ( void )
{
unsigned long V_543 = 0 , V_490 = 0 ;
unsigned long V_119 , V_120 , V_26 ;
int V_491 = - 1 ;
int V_60 , V_13 ;
F_187 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_119 || V_491 < 0 || V_491 == V_13 ) {
V_491 = V_13 ;
V_490 = V_120 ;
continue;
}
V_26 = ~ ( ( 1 << F_518 ( V_119 ) ) - 1 ) ;
while ( V_26 && V_490 <= ( V_119 & ( V_26 << 1 ) ) )
V_26 <<= 1 ;
V_543 |= V_26 ;
}
return ~ V_543 + 1 ;
}
static unsigned long T_4 F_519 ( int V_13 )
{
unsigned long V_544 = V_11 ;
unsigned long V_44 ;
int V_60 ;
F_187 (i, nid, &start_pfn, NULL, NULL)
V_544 = F_176 ( V_544 , V_44 ) ;
if ( V_544 == V_11 ) {
F_315 ( L_94 , V_13 ) ;
return 0 ;
}
return V_544 ;
}
unsigned long T_4 F_520 ( void )
{
return F_519 ( V_443 ) ;
}
static unsigned long T_4 F_521 ( void )
{
unsigned long V_510 = 0 ;
unsigned long V_44 , V_121 ;
int V_60 , V_13 ;
F_187 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_175 = V_121 - V_44 ;
V_510 += V_175 ;
if ( V_175 )
F_522 ( V_13 , V_152 ) ;
}
return V_510 ;
}
static void T_4 F_523 ( void )
{
int V_60 , V_13 ;
unsigned long V_545 ;
unsigned long V_546 , V_547 ;
T_10 V_548 = V_549 [ V_152 ] ;
unsigned long V_510 = F_521 () ;
int V_550 = F_524 ( V_549 [ V_152 ] ) ;
struct V_470 * V_471 ;
F_486 () ;
if ( F_525 () ) {
F_455 (memory, r) {
if ( ! F_526 ( V_471 ) )
continue;
V_13 = V_471 -> V_13 ;
V_545 = F_156 ( V_471 -> V_551 ) ;
V_478 [ V_13 ] = V_478 [ V_13 ] ?
F_176 ( V_545 , V_478 [ V_13 ] ) :
V_545 ;
}
goto V_552;
}
if ( V_477 ) {
bool V_553 = false ;
F_455 (memory, r) {
if ( F_457 ( V_471 ) )
continue;
V_13 = V_471 -> V_13 ;
V_545 = F_456 ( V_471 ) ;
if ( V_545 < 0x100000 ) {
V_553 = true ;
continue;
}
V_478 [ V_13 ] = V_478 [ V_13 ] ?
F_176 ( V_545 , V_478 [ V_13 ] ) :
V_545 ;
}
if ( V_553 )
F_315 ( L_95 ) ;
goto V_552;
}
if ( V_554 ) {
unsigned long V_555 ;
V_554 =
F_495 ( V_554 , V_136 ) ;
V_554 = F_176 ( V_510 , V_554 ) ;
V_555 = V_510 - V_554 ;
V_556 = F_15 ( V_556 , V_555 ) ;
}
if ( ! V_556 || V_556 >= V_510 )
goto V_53;
V_545 = V_498 [ V_499 ] ;
V_557:
V_546 = V_556 / V_550 ;
F_194 (nid, N_MEMORY) {
unsigned long V_44 , V_121 ;
if ( V_556 < V_546 )
V_546 = V_556 / V_550 ;
V_547 = V_546 ;
F_187 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_558 ;
V_44 = F_15 ( V_44 , V_478 [ V_13 ] ) ;
if ( V_44 >= V_121 )
continue;
if ( V_44 < V_545 ) {
unsigned long V_559 ;
V_559 = F_176 ( V_121 , V_545 )
- V_44 ;
V_547 -= F_176 ( V_559 ,
V_547 ) ;
V_556 -= F_176 ( V_559 ,
V_556 ) ;
if ( V_121 <= V_545 ) {
V_478 [ V_13 ] = V_121 ;
continue;
}
V_44 = V_545 ;
}
V_558 = V_121 - V_44 ;
if ( V_558 > V_547 )
V_558 = V_547 ;
V_478 [ V_13 ] = V_44 + V_558 ;
V_556 -= F_176 ( V_556 ,
V_558 ) ;
V_547 -= V_558 ;
if ( ! V_547 )
break;
}
}
V_550 -- ;
if ( V_550 && V_556 > V_550 )
goto V_557;
V_552:
for ( V_13 = 0 ; V_13 < V_443 ; V_13 ++ )
V_478 [ V_13 ] =
F_495 ( V_478 [ V_13 ] , V_136 ) ;
V_53:
V_549 [ V_152 ] = V_548 ;
}
static void F_527 ( T_1 * V_9 , int V_13 )
{
enum V_380 V_380 ;
if ( V_152 == V_560 )
return;
for ( V_380 = 0 ; V_380 <= V_479 - 1 ; V_380 ++ ) {
struct V_40 * V_40 = & V_9 -> V_118 [ V_380 ] ;
if ( F_189 ( V_40 ) ) {
F_522 ( V_13 , V_561 ) ;
if ( V_560 != V_561 &&
V_380 <= V_289 )
F_522 ( V_13 , V_560 ) ;
break;
}
}
}
void T_4 F_528 ( unsigned long * V_204 )
{
unsigned long V_44 , V_121 ;
int V_60 , V_13 ;
memset ( V_498 , 0 ,
sizeof( V_498 ) ) ;
memset ( V_497 , 0 ,
sizeof( V_497 ) ) ;
V_44 = F_520 () ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
if ( V_60 == V_479 )
continue;
V_121 = F_15 ( V_204 [ V_60 ] , V_44 ) ;
V_498 [ V_60 ] = V_44 ;
V_497 [ V_60 ] = V_121 ;
V_44 = V_121 ;
}
V_498 [ V_479 ] = 0 ;
V_497 [ V_479 ] = 0 ;
memset ( V_478 , 0 , sizeof( V_478 ) ) ;
F_523 () ;
F_70 ( L_96 ) ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
if ( V_60 == V_479 )
continue;
F_70 ( L_97 , V_463 [ V_60 ] ) ;
if ( V_498 [ V_60 ] ==
V_497 [ V_60 ] )
F_529 ( L_98 ) ;
else
F_529 ( L_99 ,
( V_538 ) V_498 [ V_60 ]
<< V_17 ,
( ( V_538 ) V_497 [ V_60 ]
<< V_17 ) - 1 ) ;
}
F_70 ( L_100 ) ;
for ( V_60 = 0 ; V_60 < V_443 ; V_60 ++ ) {
if ( V_478 [ V_60 ] )
F_70 ( L_101 , V_60 ,
( V_538 ) V_478 [ V_60 ] << V_17 ) ;
}
F_70 ( L_102 ) ;
F_187 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_70 ( L_103 , V_13 ,
( V_538 ) V_44 << V_17 ,
( ( V_538 ) V_121 << V_17 ) - 1 ) ;
F_530 () ;
F_515 () ;
F_432 (nid) {
T_1 * V_9 = F_12 ( V_13 ) ;
F_514 ( V_13 , NULL ,
F_519 ( V_13 ) , NULL ) ;
if ( V_9 -> V_512 )
F_522 ( V_13 , V_152 ) ;
F_527 ( V_9 , V_13 ) ;
}
}
static int T_4 F_531 ( char * V_63 , unsigned long * V_562 )
{
unsigned long long V_563 ;
if ( ! V_63 )
return - V_67 ;
V_563 = F_532 ( V_63 , & V_63 ) ;
* V_562 = V_563 >> V_17 ;
F_4 ( ( V_563 >> V_17 ) > V_11 ) ;
return 0 ;
}
static int T_4 F_533 ( char * V_63 )
{
if ( F_534 ( V_63 , L_104 ) ) {
V_477 = true ;
return 0 ;
}
return F_531 ( V_63 , & V_556 ) ;
}
static int T_4 F_535 ( char * V_63 )
{
return F_531 ( V_63 , & V_554 ) ;
}
void F_200 ( struct V_1 * V_1 , long V_103 )
{
F_136 ( & V_564 ) ;
F_19 ( V_1 ) -> V_124 += V_103 ;
V_371 += V_103 ;
#ifdef F_395
if ( F_125 ( V_1 ) )
V_377 += V_103 ;
#endif
F_142 ( & V_564 ) ;
}
unsigned long F_536 ( void * V_119 , void * V_120 , int V_565 , char * V_419 )
{
void * V_448 ;
unsigned long V_175 = 0 ;
V_119 = ( void * ) F_373 ( ( unsigned long ) V_119 ) ;
V_120 = ( void * ) ( ( unsigned long ) V_120 & V_566 ) ;
for ( V_448 = V_119 ; V_448 < V_120 ; V_448 += V_102 , V_175 ++ ) {
if ( ( unsigned int ) V_565 <= 0xFF )
memset ( V_448 , V_565 , V_102 ) ;
F_537 ( F_271 ( V_448 ) ) ;
}
if ( V_175 && V_419 )
F_70 ( L_105 ,
V_419 , V_175 << ( V_17 - 10 ) , V_119 , V_120 ) ;
return V_175 ;
}
void F_538 ( struct V_1 * V_1 )
{
F_539 ( V_1 ) ;
V_371 ++ ;
F_19 ( V_1 ) -> V_124 ++ ;
V_377 ++ ;
}
void T_4 F_540 ( const char * V_225 )
{
unsigned long V_567 , V_568 , V_569 , V_570 , V_571 ;
unsigned long V_572 , V_573 ;
V_567 = F_541 () ;
V_568 = V_574 - V_575 ;
V_569 = V_576 - V_577 ;
V_570 = V_578 - V_579 ;
V_571 = V_580 - V_581 ;
V_573 = V_582 - V_583 ;
V_572 = V_584 - V_585 ;
#define F_542 ( V_119 , V_120 , V_157 , V_448 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_542 ( V_583 , V_582 , V_573 ,
V_585 , V_572 ) ;
F_542 ( V_575 , V_574 , V_568 , V_585 , V_572 ) ;
F_542 ( V_577 , V_576 , V_569 , V_583 , V_573 ) ;
F_542 ( V_575 , V_574 , V_568 , V_579 , V_570 ) ;
F_542 ( V_577 , V_576 , V_569 , V_579 , V_570 ) ;
#undef F_542
F_70 ( L_106
#ifdef F_395
L_107
#endif
L_108 ,
F_543 () << ( V_17 - 10 ) ,
V_567 << ( V_17 - 10 ) ,
V_568 >> 10 , V_569 >> 10 , V_570 >> 10 ,
( V_573 + V_572 ) >> 10 , V_571 >> 10 ,
( V_567 - V_371 - V_586 ) << ( V_17 - 10 ) ,
V_586 << ( V_17 - 10 ) ,
#ifdef F_395
V_377 << ( V_17 - 10 ) ,
#endif
V_225 ? L_109 : L_110 , V_225 ? V_225 : L_110 ) ;
}
void T_4 F_544 ( unsigned long V_587 )
{
V_530 = V_587 ;
}
void T_4 F_545 ( unsigned long * V_507 )
{
F_514 ( 0 , V_507 ,
F_546 ( V_588 ) >> V_17 , NULL ) ;
}
static int F_547 ( struct V_589 * V_457 ,
unsigned long V_590 , void * V_591 )
{
int V_197 = ( unsigned long ) V_591 ;
if ( V_590 == V_592 || V_590 == V_593 ) {
F_548 ( V_197 ) ;
F_247 ( V_197 ) ;
F_549 ( V_197 ) ;
F_550 ( V_197 ) ;
}
return V_594 ;
}
void T_4 F_551 ( void )
{
F_552 ( F_547 , 0 ) ;
}
static void F_553 ( void )
{
struct V_255 * V_9 ;
unsigned long V_595 = 0 ;
enum V_380 V_60 , V_445 ;
F_402 (pgdat) {
V_9 -> V_364 = 0 ;
for ( V_60 = 0 ; V_60 < V_117 ; V_60 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_60 ;
long F_15 = 0 ;
for ( V_445 = V_60 ; V_445 < V_117 ; V_445 ++ ) {
if ( V_40 -> V_249 [ V_445 ] > F_15 )
F_15 = V_40 -> V_249 [ V_445 ] ;
}
F_15 += F_381 ( V_40 ) ;
if ( F_15 > V_40 -> V_124 )
F_15 = V_40 -> V_124 ;
V_9 -> V_364 += F_15 ;
V_595 += F_15 ;
}
}
V_364 = V_595 ;
}
static void F_554 ( void )
{
struct V_255 * V_9 ;
enum V_380 V_445 , V_596 ;
F_402 (pgdat) {
for ( V_445 = 0 ; V_445 < V_117 ; V_445 ++ ) {
struct V_40 * V_40 = V_9 -> V_118 + V_445 ;
unsigned long V_124 = V_40 -> V_124 ;
V_40 -> V_249 [ V_445 ] = 0 ;
V_596 = V_445 ;
while ( V_596 ) {
struct V_40 * V_597 ;
V_596 -- ;
if ( V_598 [ V_596 ] < 1 )
V_598 [ V_596 ] = 1 ;
V_597 = V_9 -> V_118 + V_596 ;
V_597 -> V_249 [ V_445 ] = V_124 /
V_598 [ V_596 ] ;
V_124 += V_597 -> V_124 ;
}
}
}
F_553 () ;
}
static void F_555 ( void )
{
unsigned long V_599 = V_600 >> ( V_17 - 10 ) ;
unsigned long V_601 = 0 ;
struct V_40 * V_40 ;
unsigned long V_34 ;
F_388 (zone) {
if ( ! F_396 ( V_40 ) )
V_601 += V_40 -> V_124 ;
}
F_388 (zone) {
V_538 V_385 ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
V_385 = ( V_538 ) V_599 * V_40 -> V_124 ;
F_556 ( V_385 , V_601 ) ;
if ( F_396 ( V_40 ) ) {
unsigned long V_602 ;
V_602 = V_40 -> V_124 / 1024 ;
V_602 = F_490 ( V_602 , V_603 , 128UL ) ;
V_40 -> V_208 [ V_604 ] = V_602 ;
} else {
V_40 -> V_208 [ V_604 ] = V_385 ;
}
V_385 = F_557 ( V_538 , V_385 >> 2 ,
F_558 ( V_40 -> V_124 ,
V_605 , 10000 ) ) ;
V_40 -> V_208 [ V_363 ] = F_327 ( V_40 ) + V_385 ;
V_40 -> V_208 [ V_606 ] = F_327 ( V_40 ) + V_385 * 2 ;
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
F_553 () ;
}
void F_559 ( void )
{
F_418 ( & V_435 ) ;
F_555 () ;
F_321 ( & V_435 ) ;
}
int T_2 F_560 ( void )
{
unsigned long V_607 ;
int V_608 ;
V_607 = F_382 () * ( V_102 >> 10 ) ;
V_608 = F_561 ( V_607 * 16 ) ;
if ( V_608 > V_609 ) {
V_600 = V_608 ;
if ( V_600 < 128 )
V_600 = 128 ;
if ( V_600 > 65536 )
V_600 = 65536 ;
} else {
F_315 ( L_111 ,
V_608 , V_609 ) ;
}
F_559 () ;
F_562 () ;
F_554 () ;
#ifdef F_277
F_563 () ;
F_564 () ;
#endif
return 0 ;
}
int F_565 ( struct V_426 * V_427 , int V_428 ,
void T_12 * V_429 , T_11 * V_430 , T_13 * V_431 )
{
int V_610 ;
V_610 = F_566 ( V_427 , V_428 , V_429 , V_430 , V_431 ) ;
if ( V_610 )
return V_610 ;
if ( V_428 ) {
V_609 = V_600 ;
F_559 () ;
}
return 0 ;
}
int F_567 ( struct V_426 * V_427 , int V_428 ,
void T_12 * V_429 , T_11 * V_430 , T_13 * V_431 )
{
int V_610 ;
V_610 = F_566 ( V_427 , V_428 , V_429 , V_430 , V_431 ) ;
if ( V_610 )
return V_610 ;
if ( V_428 )
F_559 () ;
return 0 ;
}
static void F_563 ( void )
{
T_1 * V_9 ;
struct V_40 * V_40 ;
F_402 (pgdat)
V_9 -> V_611 = 0 ;
F_388 (zone)
V_40 -> V_110 -> V_611 += ( V_40 -> V_124 *
V_612 ) / 100 ;
}
int F_568 ( struct V_426 * V_427 , int V_428 ,
void T_12 * V_429 , T_11 * V_430 , T_13 * V_431 )
{
int V_610 ;
V_610 = F_566 ( V_427 , V_428 , V_429 , V_430 , V_431 ) ;
if ( V_610 )
return V_610 ;
F_563 () ;
return 0 ;
}
static void F_564 ( void )
{
T_1 * V_9 ;
struct V_40 * V_40 ;
F_402 (pgdat)
V_9 -> V_613 = 0 ;
F_388 (zone)
V_40 -> V_110 -> V_613 += ( V_40 -> V_124 *
V_614 ) / 100 ;
}
int F_569 ( struct V_426 * V_427 , int V_428 ,
void T_12 * V_429 , T_11 * V_430 , T_13 * V_431 )
{
int V_610 ;
V_610 = F_566 ( V_427 , V_428 , V_429 , V_430 , V_431 ) ;
if ( V_610 )
return V_610 ;
F_564 () ;
return 0 ;
}
int F_570 ( struct V_426 * V_427 , int V_428 ,
void T_12 * V_429 , T_11 * V_430 , T_13 * V_431 )
{
F_566 ( V_427 , V_428 , V_429 , V_430 , V_431 ) ;
F_554 () ;
return 0 ;
}
int F_571 ( struct V_426 * V_427 , int V_428 ,
void T_12 * V_429 , T_11 * V_430 , T_13 * V_431 )
{
struct V_40 * V_40 ;
int V_615 ;
int V_41 ;
F_418 ( & V_616 ) ;
V_615 = V_480 ;
V_41 = F_566 ( V_427 , V_428 , V_429 , V_430 , V_431 ) ;
if ( ! V_428 || V_41 < 0 )
goto V_53;
if ( V_480 &&
V_480 < V_617 ) {
V_480 = V_615 ;
V_41 = - V_67 ;
goto V_53;
}
if ( V_480 == V_615 )
goto V_53;
F_198 (zone) {
unsigned int V_197 ;
F_433 (cpu)
F_467 ( V_40 ,
F_246 ( V_40 -> V_200 , V_197 ) ) ;
}
V_53:
F_321 ( & V_616 ) ;
return V_41 ;
}
static int T_4 F_572 ( char * V_225 )
{
if ( ! V_225 )
return 0 ;
V_618 = F_573 ( V_225 , & V_225 , 0 ) ;
return 1 ;
}
void * T_4 F_574 ( const char * V_619 ,
unsigned long V_620 ,
unsigned long V_621 ,
int V_622 ,
int V_34 ,
unsigned int * V_623 ,
unsigned int * V_624 ,
unsigned long V_625 ,
unsigned long V_626 )
{
unsigned long long F_15 = V_626 ;
unsigned long V_627 , V_157 ;
void * V_427 = NULL ;
if ( ! V_621 ) {
V_621 = V_531 ;
if ( V_17 < 20 )
V_621 = F_575 ( V_621 , ( 1 << 20 ) / V_102 ) ;
if ( V_622 > V_17 )
V_621 >>= ( V_622 - V_17 ) ;
else
V_621 <<= ( V_17 - V_622 ) ;
if ( F_32 ( V_34 & V_628 ) ) {
F_4 ( ! ( V_34 & V_629 ) ) ;
if ( ! ( V_621 >> * V_623 ) ) {
V_621 = 1UL << * V_623 ;
F_186 ( ! V_621 ) ;
}
} else if ( F_32 ( ( V_621 * V_620 ) < V_102 ) )
V_621 = V_102 / V_620 ;
}
V_621 = F_576 ( V_621 ) ;
if ( F_15 == 0 ) {
F_15 = ( ( unsigned long long ) V_532 << V_17 ) >> 4 ;
F_556 ( F_15 , V_620 ) ;
}
F_15 = F_176 ( F_15 , 0x80000000ULL ) ;
if ( V_621 < V_625 )
V_621 = V_625 ;
if ( V_621 > F_15 )
V_621 = F_15 ;
V_627 = F_577 ( V_621 ) ;
do {
V_157 = V_620 << V_627 ;
if ( V_34 & V_629 )
V_427 = F_578 ( V_157 , 0 ) ;
else if ( V_618 )
V_427 = F_579 ( V_157 , V_630 , V_631 ) ;
else {
if ( F_376 ( V_157 ) < V_71 ) {
V_427 = F_375 ( V_157 , V_630 ) ;
F_580 ( V_427 , V_157 , 1 , V_630 ) ;
}
}
} while ( ! V_427 && V_157 > V_102 && -- V_627 );
if ( ! V_427 )
F_581 ( L_112 , V_619 ) ;
F_70 ( L_113 ,
V_619 , 1UL << V_627 , F_577 ( V_157 ) - V_17 , V_157 ) ;
if ( V_623 )
* V_623 = V_627 ;
if ( V_624 )
* V_624 = ( 1 << V_627 ) - 1 ;
return V_427 ;
}
bool F_582 ( struct V_40 * V_40 , struct V_1 * V_1 , int V_103 ,
bool V_632 )
{
unsigned long V_12 , V_633 , V_634 ;
int V_115 ;
if ( V_417 ( V_40 ) == V_479 )
return false ;
V_115 = F_99 ( V_1 ) ;
if ( V_115 == V_137 || F_233 ( V_115 ) )
return false ;
V_12 = F_35 ( V_1 ) ;
for ( V_634 = 0 , V_633 = 0 ; V_633 < V_24 ; V_633 ++ ) {
unsigned long V_635 = V_12 + V_633 ;
if ( ! F_41 ( V_635 ) )
continue;
V_1 = F_152 ( V_635 ) ;
if ( F_583 ( V_1 ) ) {
V_633 = F_575 ( V_633 + 1 , 1 << F_54 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_104 ( V_1 ) ) {
if ( F_90 ( V_1 ) )
V_633 += ( 1 << F_87 ( V_1 ) ) - 1 ;
continue;
}
if ( V_632 && F_584 ( V_1 ) )
continue;
if ( ! F_585 ( V_1 ) )
V_634 ++ ;
if ( V_634 > V_103 )
return true ;
}
return false ;
}
bool F_586 ( struct V_1 * V_1 )
{
struct V_40 * V_40 ;
unsigned long V_12 ;
if ( ! F_11 ( F_224 ( V_1 ) ) )
return false ;
V_40 = F_19 ( V_1 ) ;
V_12 = F_35 ( V_1 ) ;
if ( ! F_28 ( V_40 , V_12 ) )
return false ;
return ! F_582 ( V_40 , V_1 , 0 , true ) ;
}
static unsigned long F_587 ( unsigned long V_12 )
{
return V_12 & ~ ( F_557 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_588 ( unsigned long V_12 )
{
return F_175 ( V_12 , F_557 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_589 ( struct V_636 * V_637 ,
unsigned long V_119 , unsigned long V_120 )
{
unsigned long V_638 ;
unsigned long V_12 = V_119 ;
unsigned int V_639 = 0 ;
int V_41 = 0 ;
F_590 () ;
while ( V_12 < V_120 || ! F_139 ( & V_637 -> V_640 ) ) {
if ( F_591 ( V_55 ) ) {
V_41 = - V_641 ;
break;
}
if ( F_139 ( & V_637 -> V_640 ) ) {
V_637 -> V_642 = 0 ;
V_12 = F_592 ( V_637 , V_12 , V_120 ) ;
if ( ! V_12 ) {
V_41 = - V_641 ;
break;
}
V_639 = 0 ;
} else if ( ++ V_639 == 5 ) {
V_41 = V_41 < 0 ? V_41 : - V_643 ;
break;
}
V_638 = F_593 ( V_637 -> V_40 ,
& V_637 -> V_640 ) ;
V_637 -> V_642 -= V_638 ;
V_41 = F_594 ( & V_637 -> V_640 , V_644 ,
NULL , 0 , V_637 -> V_234 , V_645 ) ;
}
if ( V_41 < 0 ) {
F_595 ( & V_637 -> V_640 ) ;
return V_41 ;
}
return 0 ;
}
int F_596 ( unsigned long V_119 , unsigned long V_120 ,
unsigned V_3 )
{
unsigned long V_646 , V_647 ;
unsigned int V_59 ;
int V_41 = 0 ;
struct V_636 V_637 = {
. V_642 = 0 ,
. V_59 = - 1 ,
. V_40 = F_19 ( F_152 ( V_119 ) ) ,
. V_234 = V_648 ,
. V_649 = true ,
} ;
F_75 ( & V_637 . V_640 ) ;
V_41 = F_597 ( F_587 ( V_119 ) ,
F_588 ( V_120 ) , V_3 ,
false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_589 ( & V_637 , V_119 , V_120 ) ;
if ( V_41 && V_41 != - V_643 )
goto V_650;
F_598 () ;
F_250 ( V_637 . V_40 ) ;
V_59 = 0 ;
V_646 = V_119 ;
while ( ! F_90 ( F_152 ( V_646 ) ) ) {
if ( ++ V_59 >= V_71 ) {
V_646 = V_119 ;
break;
}
V_646 &= ~ 0UL << V_59 ;
}
if ( V_646 != V_119 ) {
V_59 = F_87 ( F_152 ( V_646 ) ) ;
if ( V_646 + ( 1UL << V_59 ) <= V_119 )
V_646 = V_119 ;
}
if ( F_599 ( V_646 , V_120 , false ) ) {
F_70 ( L_114 ,
V_651 , V_646 , V_120 ) ;
V_41 = - V_643 ;
goto V_650;
}
V_647 = F_600 ( & V_637 , V_646 , V_120 ) ;
if ( ! V_647 ) {
V_41 = - V_643 ;
goto V_650;
}
if ( V_119 != V_646 )
F_601 ( V_646 , V_119 - V_646 ) ;
if ( V_120 != V_647 )
F_601 ( V_120 , V_647 - V_120 ) ;
V_650:
F_602 ( F_587 ( V_119 ) ,
F_588 ( V_120 ) , V_3 ) ;
return V_41 ;
}
void F_601 ( unsigned long V_12 , unsigned V_61 )
{
unsigned int V_103 = 0 ;
for (; V_61 -- ; V_12 ++ ) {
struct V_1 * V_1 = F_152 ( V_12 ) ;
V_103 += F_89 ( V_1 ) != 1 ;
F_603 ( V_1 ) ;
}
F_604 ( V_103 != 0 , L_115 , V_103 ) ;
}
void T_2 F_605 ( struct V_40 * V_40 )
{
unsigned V_197 ;
F_418 ( & V_616 ) ;
F_433 (cpu)
F_467 ( V_40 ,
F_246 ( V_40 -> V_200 , V_197 ) ) ;
F_321 ( & V_616 ) ;
}
void F_606 ( struct V_40 * V_40 )
{
unsigned long V_34 ;
int V_197 ;
struct V_198 * V_199 ;
F_160 ( V_34 ) ;
if ( V_40 -> V_200 != & V_458 ) {
F_251 (cpu) {
V_199 = F_246 ( V_40 -> V_200 , V_197 ) ;
F_607 ( V_40 , V_199 ) ;
}
F_608 ( V_40 -> V_200 ) ;
V_40 -> V_200 = & V_458 ;
}
F_162 ( V_34 ) ;
}
void
F_609 ( unsigned long V_44 , unsigned long V_121 )
{
struct V_1 * V_1 ;
struct V_40 * V_40 ;
unsigned int V_59 , V_60 ;
unsigned long V_12 ;
unsigned long V_34 ;
for ( V_12 = V_44 ; V_12 < V_121 ; V_12 ++ )
if ( F_158 ( V_12 ) )
break;
if ( V_12 == V_121 )
return;
V_40 = F_19 ( F_152 ( V_12 ) ) ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
V_12 = V_44 ;
while ( V_12 < V_121 ) {
if ( ! F_158 ( V_12 ) ) {
V_12 ++ ;
continue;
}
V_1 = F_152 ( V_12 ) ;
if ( F_32 ( ! F_90 ( V_1 ) && F_584 ( V_1 ) ) ) {
V_12 ++ ;
F_159 ( V_1 ) ;
continue;
}
F_186 ( F_89 ( V_1 ) ) ;
F_186 ( ! F_90 ( V_1 ) ) ;
V_59 = F_87 ( V_1 ) ;
#ifdef V_98
F_70 ( L_116 ,
V_12 , 1 << V_59 , V_121 ) ;
#endif
F_97 ( & V_1 -> V_75 ) ;
F_83 ( V_1 ) ;
V_40 -> V_85 [ V_59 ] . V_86 -- ;
for ( V_60 = 0 ; V_60 < ( 1 << V_59 ) ; V_60 ++ )
F_159 ( ( V_1 + V_60 ) ) ;
V_12 += ( 1 << V_59 ) ;
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
}
bool F_610 ( struct V_1 * V_1 )
{
struct V_40 * V_40 = F_19 ( V_1 ) ;
unsigned long V_12 = F_35 ( V_1 ) ;
unsigned long V_34 ;
unsigned int V_59 ;
F_232 ( & V_40 -> V_109 , V_34 ) ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
struct V_1 * V_652 = V_1 - ( V_12 & ( ( 1 << V_59 ) - 1 ) ) ;
if ( F_90 ( V_652 ) && F_87 ( V_652 ) >= V_59 )
break;
}
F_234 ( & V_40 -> V_109 , V_34 ) ;
return V_59 < V_71 ;
}
