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
V_6 &= ~ V_7 ;
}
bool F_7 ( void )
{
if ( ( V_6 & V_7 ) == V_7 )
return false ;
return true ;
}
static inline void F_8 ( T_1 * V_8 )
{
V_8 -> V_9 = V_10 ;
}
static inline bool T_2 F_9 ( unsigned long V_11 )
{
if ( V_11 >= F_10 ( F_11 ( V_11 ) ) -> V_9 )
return true ;
return false ;
}
static inline bool F_12 ( unsigned long V_11 , int V_12 )
{
if ( V_11 >= F_10 ( V_12 ) -> V_9 )
return true ;
return false ;
}
static inline bool F_13 ( T_1 * V_8 ,
unsigned long V_11 , unsigned long V_13 ,
unsigned long * V_14 )
{
if ( V_13 < F_14 ( V_8 ) )
return true ;
( * V_14 ) ++ ;
if ( * V_14 > ( 2UL << ( 30 - V_15 ) ) &&
( V_11 & ( V_16 - 1 ) ) == 0 ) {
V_8 -> V_9 = V_11 ;
return false ;
}
return true ;
}
static inline void F_8 ( T_1 * V_8 )
{
}
static inline bool F_9 ( unsigned long V_11 )
{
return false ;
}
static inline bool F_12 ( unsigned long V_11 , int V_12 )
{
return false ;
}
static inline bool F_13 ( T_1 * V_8 ,
unsigned long V_11 , unsigned long V_13 ,
unsigned long * V_14 )
{
return true ;
}
void F_15 ( struct V_1 * V_1 , int V_3 )
{
if ( F_16 ( V_17 &&
V_3 < V_18 ) )
V_3 = V_19 ;
F_17 ( V_1 , ( unsigned long ) V_3 ,
V_20 , V_21 ) ;
}
static int F_18 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
int V_23 = 0 ;
unsigned V_24 ;
unsigned long V_11 = F_19 ( V_1 ) ;
unsigned long V_25 , V_26 ;
do {
V_24 = F_20 ( V_22 ) ;
V_26 = V_22 -> V_27 ;
V_25 = V_22 -> V_28 ;
if ( ! F_21 ( V_22 , V_11 ) )
V_23 = 1 ;
} while ( F_22 ( V_22 , V_24 ) );
if ( V_23 )
F_23 ( L_1 ,
V_11 , F_24 ( V_22 ) , V_22 -> V_29 ,
V_26 , V_26 + V_25 ) ;
return V_23 ;
}
static int F_25 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
if ( ! F_26 ( F_19 ( V_1 ) ) )
return 0 ;
if ( V_22 != F_27 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_28 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
if ( F_18 ( V_22 , V_1 ) )
return 1 ;
if ( ! F_25 ( V_22 , V_1 ) )
return 1 ;
return 0 ;
}
static inline int F_28 ( struct V_22 * V_22 , struct V_1 * V_1 )
{
return 0 ;
}
static void F_29 ( struct V_1 * V_1 , const char * V_30 ,
unsigned long V_31 )
{
static unsigned long V_32 ;
static unsigned long V_33 ;
static unsigned long V_34 ;
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 ) ;
return;
}
if ( V_33 == 60 ) {
if ( F_32 ( V_35 , V_32 ) ) {
V_34 ++ ;
goto V_36;
}
if ( V_34 ) {
F_33 ( V_37
L_2 ,
V_34 ) ;
V_34 = 0 ;
}
V_33 = 0 ;
}
if ( V_33 ++ == 0 )
V_32 = V_35 + 60 * V_38 ;
F_33 ( V_37 L_3 ,
V_39 -> V_40 , F_19 ( V_1 ) ) ;
F_34 ( V_1 , V_30 , V_31 ) ;
F_35 () ;
F_36 () ;
V_36:
F_31 ( V_1 ) ;
F_37 ( V_41 , V_42 ) ;
}
static void F_38 ( struct V_1 * V_1 )
{
F_39 ( V_1 , F_40 ( V_1 ) ) ;
}
void F_41 ( struct V_1 * V_1 , unsigned long V_43 )
{
int V_44 ;
int V_45 = 1 << V_43 ;
F_42 ( V_1 , F_38 ) ;
F_43 ( V_1 , V_43 ) ;
F_44 ( V_1 ) ;
for ( V_44 = 1 ; V_44 < V_45 ; V_44 ++ ) {
struct V_1 * V_46 = V_1 + V_44 ;
F_45 ( V_46 , 0 ) ;
V_46 -> V_47 = V_1 ;
F_46 () ;
F_47 ( V_46 ) ;
}
}
static int T_3 F_48 ( char * V_48 )
{
if ( ! V_48 )
return - V_49 ;
if ( strcmp ( V_48 , L_4 ) == 0 )
V_50 = true ;
return 0 ;
}
static bool F_49 ( void )
{
if ( ! F_50 () )
return false ;
return true ;
}
static void F_51 ( void )
{
if ( ! F_50 () )
return;
V_51 = true ;
}
static int T_3 F_52 ( char * V_48 )
{
unsigned long V_52 ;
if ( F_53 ( V_48 , 10 , & V_52 ) < 0 || V_52 > V_53 / 2 ) {
F_33 ( V_54 L_5 ) ;
return 0 ;
}
V_55 = V_52 ;
F_33 ( V_56 L_6 , V_52 ) ;
return 0 ;
}
static inline void F_54 ( struct V_22 * V_22 , struct V_1 * V_1 ,
unsigned int V_43 , int V_3 )
{
struct V_57 * V_57 ;
if ( ! F_55 () )
return;
V_57 = F_56 ( V_1 ) ;
F_57 ( V_58 , & V_57 -> V_59 ) ;
F_58 ( & V_1 -> V_60 ) ;
F_59 ( V_1 , V_43 ) ;
F_60 ( V_22 , - ( 1 << V_43 ) , V_3 ) ;
}
static inline void F_61 ( struct V_22 * V_22 , struct V_1 * V_1 ,
unsigned int V_43 , int V_3 )
{
struct V_57 * V_57 ;
if ( ! F_55 () )
return;
V_57 = F_56 ( V_1 ) ;
F_62 ( V_58 , & V_57 -> V_59 ) ;
F_59 ( V_1 , 0 ) ;
if ( ! F_63 ( V_3 ) )
F_60 ( V_22 , ( 1 << V_43 ) , V_3 ) ;
}
static inline void F_54 ( struct V_22 * V_22 , struct V_1 * V_1 ,
unsigned int V_43 , int V_3 ) {}
static inline void F_61 ( struct V_22 * V_22 , struct V_1 * V_1 ,
unsigned int V_43 , int V_3 ) {}
static inline void F_64 ( struct V_1 * V_1 , unsigned int V_43 )
{
F_59 ( V_1 , V_43 ) ;
F_65 ( V_1 ) ;
}
static inline void F_66 ( struct V_1 * V_1 )
{
F_67 ( V_1 ) ;
F_59 ( V_1 , 0 ) ;
}
static inline int F_68 ( struct V_1 * V_1 , struct V_1 * V_61 ,
unsigned int V_43 )
{
if ( ! F_26 ( F_19 ( V_61 ) ) )
return 0 ;
if ( F_69 ( V_61 ) && F_70 ( V_61 ) == V_43 ) {
if ( F_71 ( V_1 ) != F_71 ( V_61 ) )
return 0 ;
F_72 ( F_73 ( V_61 ) != 0 , V_61 ) ;
return 1 ;
}
if ( F_74 ( V_61 ) && F_70 ( V_61 ) == V_43 ) {
if ( F_71 ( V_1 ) != F_71 ( V_61 ) )
return 0 ;
F_72 ( F_73 ( V_61 ) != 0 , V_61 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_75 ( struct V_1 * V_1 ,
unsigned long V_11 ,
struct V_22 * V_22 , unsigned int V_43 ,
int V_3 )
{
unsigned long V_62 ;
unsigned long V_63 ;
unsigned long V_64 ( V_65 ) ;
struct V_1 * V_61 ;
int V_66 = V_53 ;
F_76 ( ! F_77 ( V_22 ) ) ;
F_72 ( V_1 -> V_59 & V_67 , V_1 ) ;
F_76 ( V_3 == - 1 ) ;
if ( F_63 ( V_3 ) ) {
V_66 = F_78 ( V_53 , V_68 + 1 ) ;
} else {
F_60 ( V_22 , 1 << V_43 , V_3 ) ;
}
V_62 = V_11 & ( ( 1 << V_66 ) - 1 ) ;
F_72 ( V_62 & ( ( 1 << V_43 ) - 1 ) , V_1 ) ;
F_72 ( F_28 ( V_22 , V_1 ) , V_1 ) ;
while ( V_43 < V_66 - 1 ) {
V_65 = F_79 ( V_62 , V_43 ) ;
V_61 = V_1 + ( V_65 - V_62 ) ;
if ( ! F_68 ( V_1 , V_61 , V_43 ) )
break;
if ( F_69 ( V_61 ) ) {
F_61 ( V_22 , V_61 , V_43 , V_3 ) ;
} else {
F_80 ( & V_61 -> V_60 ) ;
V_22 -> V_69 [ V_43 ] . V_70 -- ;
F_66 ( V_61 ) ;
}
V_63 = V_65 & V_62 ;
V_1 = V_1 + ( V_63 - V_62 ) ;
V_62 = V_63 ;
V_43 ++ ;
}
F_64 ( V_1 , V_43 ) ;
if ( ( V_43 < V_53 - 2 ) && F_26 ( F_19 ( V_61 ) ) ) {
struct V_1 * V_71 , * V_72 ;
V_63 = V_65 & V_62 ;
V_71 = V_1 + ( V_63 - V_62 ) ;
V_65 = F_79 ( V_63 , V_43 + 1 ) ;
V_72 = V_71 + ( V_65 - V_63 ) ;
if ( F_68 ( V_71 , V_72 , V_43 + 1 ) ) {
F_81 ( & V_1 -> V_60 ,
& V_22 -> V_69 [ V_43 ] . V_73 [ V_3 ] ) ;
goto V_36;
}
}
F_82 ( & V_1 -> V_60 , & V_22 -> V_69 [ V_43 ] . V_73 [ V_3 ] ) ;
V_36:
V_22 -> V_69 [ V_43 ] . V_70 ++ ;
}
static inline int F_83 ( struct V_1 * V_1 )
{
const char * V_74 = NULL ;
unsigned long V_31 = 0 ;
if ( F_16 ( F_84 ( V_1 ) ) )
V_74 = L_7 ;
if ( F_16 ( V_1 -> V_75 != NULL ) )
V_74 = L_8 ;
if ( F_16 ( F_85 ( & V_1 -> V_76 ) != 0 ) )
V_74 = L_9 ;
if ( F_16 ( V_1 -> V_59 & V_77 ) ) {
V_74 = L_10 ;
V_31 = V_77 ;
}
#ifdef F_86
if ( F_16 ( V_1 -> V_78 ) )
V_74 = L_11 ;
#endif
if ( F_16 ( V_74 ) ) {
F_29 ( V_1 , V_74 , V_31 ) ;
return 1 ;
}
F_87 ( V_1 ) ;
if ( V_1 -> V_59 & V_67 )
V_1 -> V_59 &= ~ V_67 ;
return 0 ;
}
static void F_88 ( struct V_22 * V_22 , int V_79 ,
struct V_80 * V_81 )
{
int V_3 = 0 ;
int V_82 = 0 ;
int V_83 = V_79 ;
unsigned long V_84 ;
F_89 ( & V_22 -> V_85 ) ;
V_84 = F_90 ( V_22 , V_86 ) ;
if ( V_84 )
F_91 ( V_22 , V_86 , - V_84 ) ;
while ( V_83 ) {
struct V_1 * V_1 ;
struct V_87 * V_88 ;
do {
V_82 ++ ;
if ( ++ V_3 == V_18 )
V_3 = 0 ;
V_88 = & V_81 -> V_89 [ V_3 ] ;
} while ( F_92 ( V_88 ) );
if ( V_82 == V_18 )
V_82 = V_83 ;
do {
int V_90 ;
V_1 = F_93 ( V_88 -> V_91 , struct V_1 , V_60 ) ;
F_80 ( & V_1 -> V_60 ) ;
V_90 = F_1 ( V_1 ) ;
F_72 ( F_63 ( V_90 ) , V_1 ) ;
if ( F_16 ( F_94 ( V_22 ) ) )
V_90 = F_95 ( V_1 ) ;
F_75 ( V_1 , F_19 ( V_1 ) , V_22 , 0 , V_90 ) ;
F_96 ( V_1 , 0 , V_90 ) ;
} while ( -- V_83 && -- V_82 && ! F_92 ( V_88 ) );
}
F_97 ( & V_22 -> V_85 ) ;
}
static void F_98 ( struct V_22 * V_22 ,
struct V_1 * V_1 , unsigned long V_11 ,
unsigned int V_43 ,
int V_3 )
{
unsigned long V_84 ;
F_89 ( & V_22 -> V_85 ) ;
V_84 = F_90 ( V_22 , V_86 ) ;
if ( V_84 )
F_91 ( V_22 , V_86 , - V_84 ) ;
if ( F_16 ( F_94 ( V_22 ) ||
F_63 ( V_3 ) ) ) {
V_3 = F_99 ( V_1 , V_11 ) ;
}
F_75 ( V_1 , V_11 , V_22 , V_43 , V_3 ) ;
F_97 ( & V_22 -> V_85 ) ;
}
static int F_100 ( struct V_1 * V_92 , struct V_1 * V_1 )
{
if ( ! F_101 ( V_93 ) )
return 0 ;
if ( F_16 ( ! F_102 ( V_1 ) ) ) {
F_29 ( V_1 , L_12 , 0 ) ;
return 1 ;
}
if ( F_16 ( V_1 -> V_47 != V_92 ) ) {
F_29 ( V_1 , L_13 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void T_2 F_103 ( struct V_1 * V_1 , unsigned long V_11 ,
unsigned long V_22 , int V_12 )
{
F_104 ( V_1 , V_22 , V_12 , V_11 ) ;
F_105 ( V_1 ) ;
F_31 ( V_1 ) ;
F_87 ( V_1 ) ;
F_58 ( & V_1 -> V_60 ) ;
#ifdef F_106
if ( ! F_107 ( V_22 ) )
F_108 ( V_1 , F_109 ( V_11 << V_15 ) ) ;
#endif
}
static void T_2 F_110 ( unsigned long V_11 , unsigned long V_22 ,
int V_12 )
{
return F_103 ( F_111 ( V_11 ) , V_11 , V_22 , V_12 ) ;
}
static void F_112 ( unsigned long V_11 )
{
T_1 * V_8 ;
int V_12 , V_94 ;
if ( ! F_9 ( V_11 ) )
return;
V_12 = F_11 ( V_11 ) ;
V_8 = F_10 ( V_12 ) ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
struct V_22 * V_22 = & V_8 -> V_96 [ V_94 ] ;
if ( V_11 >= V_22 -> V_27 && V_11 < F_113 ( V_22 ) )
break;
}
F_110 ( V_11 , V_94 , V_12 ) ;
}
static inline void F_112 ( unsigned long V_11 )
{
}
void T_2 F_114 ( unsigned long V_97 , unsigned long V_98 )
{
unsigned long V_26 = F_115 ( V_97 ) ;
unsigned long V_99 = F_116 ( V_98 ) ;
for (; V_26 < V_99 ; V_26 ++ ) {
if ( F_117 ( V_26 ) ) {
struct V_1 * V_1 = F_111 ( V_26 ) ;
F_112 ( V_26 ) ;
F_118 ( V_1 ) ;
}
}
}
static bool F_119 ( struct V_1 * V_1 , unsigned int V_43 )
{
bool V_100 = F_120 ( V_1 ) ;
int V_44 , V_101 = 0 ;
F_72 ( F_102 ( V_1 ) , V_1 ) ;
F_72 ( V_100 && F_40 ( V_1 ) != V_43 , V_1 ) ;
F_121 ( V_1 , V_43 ) ;
F_122 ( V_1 , V_43 ) ;
F_123 ( V_1 , V_43 ) ;
if ( F_124 ( V_1 ) )
V_1 -> V_75 = NULL ;
V_101 += F_83 ( V_1 ) ;
for ( V_44 = 1 ; V_44 < ( 1 << V_43 ) ; V_44 ++ ) {
if ( V_100 )
V_101 += F_100 ( V_1 , V_1 + V_44 ) ;
V_101 += F_83 ( V_1 + V_44 ) ;
}
if ( V_101 )
return false ;
F_125 ( V_1 , V_43 ) ;
if ( ! F_126 ( V_1 ) ) {
F_127 ( F_128 ( V_1 ) ,
V_102 << V_43 ) ;
F_129 ( F_128 ( V_1 ) ,
V_102 << V_43 ) ;
}
F_130 ( V_1 , V_43 ) ;
F_131 ( V_1 , 1 << V_43 , 0 ) ;
return true ;
}
static void F_39 ( struct V_1 * V_1 , unsigned int V_43 )
{
unsigned long V_59 ;
int V_3 ;
unsigned long V_11 = F_19 ( V_1 ) ;
if ( ! F_119 ( V_1 , V_43 ) )
return;
V_3 = F_99 ( V_1 , V_11 ) ;
F_132 ( V_59 ) ;
F_133 ( V_103 , 1 << V_43 ) ;
F_98 ( F_27 ( V_1 ) , V_1 , V_11 , V_43 , V_3 ) ;
F_134 ( V_59 ) ;
}
static void T_3 F_135 ( struct V_1 * V_1 ,
unsigned long V_11 , unsigned int V_43 )
{
unsigned int V_45 = 1 << V_43 ;
struct V_1 * V_46 = V_1 ;
unsigned int V_104 ;
F_136 ( V_46 ) ;
for ( V_104 = 0 ; V_104 < ( V_45 - 1 ) ; V_104 ++ , V_46 ++ ) {
F_136 ( V_46 + 1 ) ;
F_137 ( V_46 ) ;
F_45 ( V_46 , 0 ) ;
}
F_137 ( V_46 ) ;
F_45 ( V_46 , 0 ) ;
F_27 ( V_1 ) -> V_105 += V_45 ;
F_138 ( V_1 ) ;
F_139 ( V_1 , V_43 ) ;
}
int T_2 F_11 ( unsigned long V_11 )
{
static F_140 ( V_106 ) ;
int V_12 ;
F_89 ( & V_106 ) ;
V_12 = F_141 ( V_11 , & V_107 ) ;
if ( V_12 < 0 )
V_12 = 0 ;
F_97 ( & V_106 ) ;
return V_12 ;
}
static inline bool T_2 F_142 ( unsigned long V_11 , int V_108 ,
struct V_109 * V_110 )
{
int V_12 ;
V_12 = F_141 ( V_11 , V_110 ) ;
if ( V_12 >= 0 && V_12 != V_108 )
return false ;
return true ;
}
static inline bool T_2 F_143 ( unsigned long V_11 , int V_108 )
{
return F_142 ( V_11 , V_108 , & V_107 ) ;
}
static inline bool T_2 F_143 ( unsigned long V_11 , int V_108 )
{
return true ;
}
static inline bool T_2 F_142 ( unsigned long V_11 , int V_108 ,
struct V_109 * V_110 )
{
return true ;
}
void T_3 F_144 ( struct V_1 * V_1 , unsigned long V_11 ,
unsigned int V_43 )
{
if ( F_9 ( V_11 ) )
return;
return F_135 ( V_1 , V_11 , V_43 ) ;
}
static void T_3 F_145 ( struct V_1 * V_1 ,
unsigned long V_11 , int V_45 )
{
int V_44 ;
if ( ! V_1 )
return;
if ( V_45 == V_111 &&
( V_11 & ( V_111 - 1 ) ) == 0 ) {
F_15 ( V_1 , V_112 ) ;
F_135 ( V_1 , V_11 , V_53 - 1 ) ;
return;
}
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ , V_1 ++ , V_11 ++ )
F_135 ( V_1 , V_11 , 0 ) ;
}
static inline void T_3 F_146 ( void )
{
if ( F_147 ( & V_113 ) )
F_148 ( & V_114 ) ;
}
static int T_3 F_149 ( void * V_115 )
{
T_1 * V_8 = V_115 ;
int V_12 = V_8 -> V_116 ;
struct V_109 V_117 = { } ;
unsigned long V_97 = V_35 ;
unsigned long V_45 = 0 ;
unsigned long V_118 , V_119 ;
int V_44 , V_94 ;
struct V_22 * V_22 ;
unsigned long V_120 = V_8 -> V_9 ;
const struct V_121 * V_121 = F_150 ( V_8 -> V_116 ) ;
if ( V_120 == V_10 ) {
F_146 () ;
return 0 ;
}
if ( ! F_151 ( V_121 ) )
F_152 ( V_39 , V_121 ) ;
F_153 ( V_8 -> V_9 < V_8 -> V_122 ) ;
F_153 ( V_8 -> V_9 > F_14 ( V_8 ) ) ;
V_8 -> V_9 = V_10 ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
V_22 = V_8 -> V_96 + V_94 ;
if ( V_120 < F_113 ( V_22 ) )
break;
}
F_154 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_11 , V_99 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_123 = NULL ;
unsigned long V_124 = 0 ;
int V_125 = 0 ;
V_99 = F_78 ( V_119 , F_113 ( V_22 ) ) ;
V_11 = V_120 ;
if ( V_11 < V_118 )
V_11 = V_118 ;
if ( V_11 < V_22 -> V_27 )
V_11 = V_22 -> V_27 ;
for (; V_11 < V_99 ; V_11 ++ ) {
if ( ! F_26 ( V_11 ) )
goto V_126;
if ( ( V_11 & ( V_111 - 1 ) ) == 0 ) {
if ( ! F_117 ( V_11 ) ) {
V_1 = NULL ;
goto V_126;
}
}
if ( ! F_142 ( V_11 , V_12 , & V_117 ) ) {
V_1 = NULL ;
goto V_126;
}
if ( V_1 && ( V_11 & ( V_111 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_45 += V_125 ;
F_145 ( V_123 ,
V_124 , V_125 ) ;
V_123 = NULL ;
V_124 = V_125 = 0 ;
V_1 = F_111 ( V_11 ) ;
F_155 () ;
}
if ( V_1 -> V_59 ) {
F_76 ( F_27 ( V_1 ) != V_22 ) ;
goto V_126;
}
F_103 ( V_1 , V_11 , V_94 , V_12 ) ;
if ( ! V_123 ) {
V_123 = V_1 ;
V_124 = V_11 ;
V_125 = 0 ;
}
V_125 ++ ;
continue;
V_126:
V_45 += V_125 ;
F_145 ( V_123 , V_124 ,
V_125 ) ;
V_123 = NULL ;
V_124 = V_125 = 0 ;
}
V_120 = F_156 ( V_99 , V_120 ) ;
}
F_4 ( ++ V_94 < V_95 && F_157 ( ++ V_22 ) ) ;
F_158 ( L_14 , V_12 , V_45 ,
F_159 ( V_35 - V_97 ) ) ;
F_146 () ;
return 0 ;
}
void T_3 F_160 ( void )
{
int V_12 ;
F_161 ( & V_113 , F_162 ( V_127 ) ) ;
F_163 (nid, N_MEMORY) {
F_164 ( F_149 , F_10 ( V_12 ) , L_15 , V_12 ) ;
}
F_165 ( & V_114 ) ;
F_166 () ;
}
void T_3 F_167 ( struct V_1 * V_1 )
{
unsigned V_44 = V_128 ;
struct V_1 * V_46 = V_1 ;
do {
F_137 ( V_46 ) ;
F_45 ( V_46 , 0 ) ;
} while ( ++ V_46 , -- V_44 );
F_15 ( V_1 , V_129 ) ;
if ( V_68 >= V_53 ) {
V_44 = V_128 ;
V_46 = V_1 ;
do {
F_138 ( V_46 ) ;
F_139 ( V_46 , V_53 - 1 ) ;
V_46 += V_111 ;
} while ( V_44 -= V_111 );
} else {
F_138 ( V_1 ) ;
F_139 ( V_1 , V_68 ) ;
}
F_168 ( V_1 , V_128 ) ;
}
static inline void F_169 ( struct V_22 * V_22 , struct V_1 * V_1 ,
int V_130 , int V_131 , struct V_69 * V_132 ,
int V_3 )
{
unsigned long V_133 = 1 << V_131 ;
while ( V_131 > V_130 ) {
V_132 -- ;
V_131 -- ;
V_133 >>= 1 ;
F_72 ( F_28 ( V_22 , & V_1 [ V_133 ] ) , & V_1 [ V_133 ] ) ;
if ( F_101 ( V_134 ) &&
F_55 () &&
V_131 < F_170 () ) {
F_54 ( V_22 , & V_1 [ V_133 ] , V_131 , V_3 ) ;
continue;
}
F_82 ( & V_1 [ V_133 ] . V_60 , & V_132 -> V_73 [ V_3 ] ) ;
V_132 -> V_70 ++ ;
F_64 ( & V_1 [ V_133 ] , V_131 ) ;
}
}
static inline int F_171 ( struct V_1 * V_1 )
{
const char * V_74 = NULL ;
unsigned long V_31 = 0 ;
if ( F_16 ( F_84 ( V_1 ) ) )
V_74 = L_7 ;
if ( F_16 ( V_1 -> V_75 != NULL ) )
V_74 = L_8 ;
if ( F_16 ( F_85 ( & V_1 -> V_76 ) != 0 ) )
V_74 = L_9 ;
if ( F_16 ( V_1 -> V_59 & V_135 ) ) {
V_74 = L_16 ;
V_31 = V_135 ;
}
if ( F_16 ( V_1 -> V_59 & V_67 ) ) {
V_74 = L_17 ;
V_31 = V_67 ;
}
#ifdef F_86
if ( F_16 ( V_1 -> V_78 ) )
V_74 = L_11 ;
#endif
if ( F_16 ( V_74 ) ) {
F_29 ( V_1 , V_74 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_172 ( struct V_1 * V_1 , unsigned int V_43 , T_4 V_136 ,
int V_137 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < ( 1 << V_43 ) ; V_44 ++ ) {
struct V_1 * V_46 = V_1 + V_44 ;
if ( F_16 ( F_171 ( V_46 ) ) )
return 1 ;
}
F_59 ( V_1 , 0 ) ;
F_138 ( V_1 ) ;
F_173 ( V_1 , V_43 ) ;
F_131 ( V_1 , 1 << V_43 , 1 ) ;
F_174 ( V_1 , V_43 ) ;
if ( V_136 & V_138 )
for ( V_44 = 0 ; V_44 < ( 1 << V_43 ) ; V_44 ++ )
F_175 ( V_1 + V_44 ) ;
if ( V_43 && ( V_136 & V_139 ) )
F_41 ( V_1 , V_43 ) ;
F_176 ( V_1 , V_43 , V_136 ) ;
if ( V_137 & V_140 )
F_177 ( V_1 ) ;
else
F_178 ( V_1 ) ;
return 0 ;
}
static inline
struct V_1 * F_179 ( struct V_22 * V_22 , unsigned int V_43 ,
int V_3 )
{
unsigned int V_141 ;
struct V_69 * V_132 ;
struct V_1 * V_1 ;
for ( V_141 = V_43 ; V_141 < V_53 ; ++ V_141 ) {
V_132 = & ( V_22 -> V_69 [ V_141 ] ) ;
if ( F_92 ( & V_132 -> V_73 [ V_3 ] ) )
continue;
V_1 = F_93 ( V_132 -> V_73 [ V_3 ] . V_142 ,
struct V_1 , V_60 ) ;
F_80 ( & V_1 -> V_60 ) ;
F_66 ( V_1 ) ;
V_132 -> V_70 -- ;
F_169 ( V_22 , V_1 , V_43 , V_141 , V_132 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_180 ( struct V_22 * V_22 ,
unsigned int V_43 )
{
return F_179 ( V_22 , V_43 , V_129 ) ;
}
static inline struct V_1 * F_180 ( struct V_22 * V_22 ,
unsigned int V_43 ) { return NULL ; }
int F_181 ( struct V_22 * V_22 ,
struct V_1 * V_143 , struct V_1 * V_144 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned long V_43 ;
int V_145 = 0 ;
#ifndef F_182
F_76 ( F_27 ( V_143 ) != F_27 ( V_144 ) ) ;
#endif
for ( V_1 = V_143 ; V_1 <= V_144 ; ) {
F_72 ( F_183 ( V_1 ) != F_24 ( V_22 ) , V_1 ) ;
if ( ! F_26 ( F_19 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
if ( ! F_74 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_43 = F_70 ( V_1 ) ;
F_184 ( & V_1 -> V_60 ,
& V_22 -> V_69 [ V_43 ] . V_73 [ V_3 ] ) ;
V_1 += 1 << V_43 ;
V_145 += 1 << V_43 ;
}
return V_145 ;
}
int F_185 ( struct V_22 * V_22 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_26 , V_99 ;
struct V_1 * V_143 , * V_144 ;
V_26 = F_19 ( V_1 ) ;
V_26 = V_26 & ~ ( V_128 - 1 ) ;
V_143 = F_111 ( V_26 ) ;
V_144 = V_143 + V_128 - 1 ;
V_99 = V_26 + V_128 - 1 ;
if ( ! F_21 ( V_22 , V_26 ) )
V_143 = V_1 ;
if ( ! F_21 ( V_22 , V_99 ) )
return 0 ;
return F_181 ( V_22 , V_143 , V_144 , V_3 ) ;
}
static void F_186 ( struct V_1 * V_146 ,
int V_147 , int V_3 )
{
int V_148 = 1 << ( V_147 - V_68 ) ;
while ( V_148 -- ) {
F_15 ( V_146 , V_3 ) ;
V_146 += V_128 ;
}
}
static bool F_187 ( unsigned int V_43 , int V_149 )
{
if ( V_43 >= V_68 )
return true ;
if ( V_43 >= V_68 / 2 ||
V_149 == V_150 ||
V_149 == V_19 ||
V_17 )
return true ;
return false ;
}
static void F_188 ( struct V_22 * V_22 , struct V_1 * V_1 ,
int V_151 )
{
int V_141 = F_70 ( V_1 ) ;
int V_152 ;
if ( V_141 >= V_68 ) {
F_186 ( V_1 , V_141 , V_151 ) ;
return;
}
V_152 = F_185 ( V_22 , V_1 , V_151 ) ;
if ( V_152 >= ( 1 << ( V_68 - 1 ) ) ||
V_17 )
F_15 ( V_1 , V_151 ) ;
}
int F_189 ( struct V_69 * V_132 , unsigned int V_43 ,
int V_3 , bool V_153 , bool * V_154 )
{
int V_44 ;
int V_155 ;
if ( V_132 -> V_70 == 0 )
return - 1 ;
* V_154 = false ;
for ( V_44 = 0 ; ; V_44 ++ ) {
V_155 = V_156 [ V_3 ] [ V_44 ] ;
if ( V_155 == V_157 )
break;
if ( F_92 ( & V_132 -> V_73 [ V_155 ] ) )
continue;
if ( F_187 ( V_43 , V_3 ) )
* V_154 = true ;
if ( ! V_153 )
return V_155 ;
if ( * V_154 )
return V_155 ;
}
return - 1 ;
}
static inline struct V_1 *
F_190 ( struct V_22 * V_22 , unsigned int V_43 , int V_158 )
{
struct V_69 * V_132 ;
unsigned int V_141 ;
struct V_1 * V_1 ;
int V_155 ;
bool V_154 ;
for ( V_141 = V_53 - 1 ;
V_141 >= V_43 && V_141 <= V_53 - 1 ;
-- V_141 ) {
V_132 = & ( V_22 -> V_69 [ V_141 ] ) ;
V_155 = F_189 ( V_132 , V_141 ,
V_158 , false , & V_154 ) ;
if ( V_155 == - 1 )
continue;
V_1 = F_93 ( V_132 -> V_73 [ V_155 ] . V_142 ,
struct V_1 , V_60 ) ;
if ( V_154 )
F_188 ( V_22 , V_1 , V_158 ) ;
V_132 -> V_70 -- ;
F_80 ( & V_1 -> V_60 ) ;
F_66 ( V_1 ) ;
F_169 ( V_22 , V_1 , V_43 , V_141 , V_132 ,
V_158 ) ;
F_2 ( V_1 , V_158 ) ;
F_191 ( V_1 , V_43 , V_141 ,
V_158 , V_155 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_192 ( struct V_22 * V_22 , unsigned int V_43 ,
int V_3 )
{
struct V_1 * V_1 ;
V_159:
V_1 = F_179 ( V_22 , V_43 , V_3 ) ;
if ( F_16 ( ! V_1 ) && V_3 != V_157 ) {
if ( V_3 == V_112 )
V_1 = F_180 ( V_22 , V_43 ) ;
if ( ! V_1 )
V_1 = F_190 ( V_22 , V_43 , V_3 ) ;
if ( ! V_1 ) {
V_3 = V_157 ;
goto V_159;
}
}
F_193 ( V_1 , V_43 , V_3 ) ;
return V_1 ;
}
static int F_194 ( struct V_22 * V_22 , unsigned int V_43 ,
unsigned long V_79 , struct V_87 * V_88 ,
int V_3 , bool V_160 )
{
int V_44 ;
F_89 ( & V_22 -> V_85 ) ;
for ( V_44 = 0 ; V_44 < V_79 ; ++ V_44 ) {
struct V_1 * V_1 = F_192 ( V_22 , V_43 , V_3 ) ;
if ( F_16 ( V_1 == NULL ) )
break;
if ( F_195 ( ! V_160 ) )
F_82 ( & V_1 -> V_60 , V_88 ) ;
else
F_81 ( & V_1 -> V_60 , V_88 ) ;
V_88 = & V_1 -> V_60 ;
if ( F_196 ( F_1 ( V_1 ) ) )
F_91 ( V_22 , V_161 ,
- ( 1 << V_43 ) ) ;
}
F_91 ( V_22 , V_162 , - ( V_44 << V_43 ) ) ;
F_97 ( & V_22 -> V_85 ) ;
return V_44 ;
}
void F_197 ( struct V_22 * V_22 , struct V_80 * V_81 )
{
unsigned long V_59 ;
int V_163 , V_164 ;
F_132 ( V_59 ) ;
V_164 = F_198 ( V_81 -> V_164 ) ;
V_163 = F_78 ( V_81 -> V_79 , V_164 ) ;
if ( V_163 > 0 ) {
F_88 ( V_22 , V_163 , V_81 ) ;
V_81 -> V_79 -= V_163 ;
}
F_134 ( V_59 ) ;
}
static void F_199 ( unsigned int V_165 , struct V_22 * V_22 )
{
unsigned long V_59 ;
struct V_166 * V_167 ;
struct V_80 * V_81 ;
F_132 ( V_59 ) ;
V_167 = F_200 ( V_22 -> V_168 , V_165 ) ;
V_81 = & V_167 -> V_81 ;
if ( V_81 -> V_79 ) {
F_88 ( V_22 , V_81 -> V_79 , V_81 ) ;
V_81 -> V_79 = 0 ;
}
F_134 ( V_59 ) ;
}
static void F_201 ( unsigned int V_165 )
{
struct V_22 * V_22 ;
F_202 (zone) {
F_199 ( V_165 , V_22 ) ;
}
}
void F_203 ( struct V_22 * V_22 )
{
int V_165 = F_204 () ;
if ( V_22 )
F_199 ( V_165 , V_22 ) ;
else
F_201 ( V_165 ) ;
}
void F_205 ( struct V_22 * V_22 )
{
int V_165 ;
static T_5 V_169 ;
F_206 (cpu) {
struct V_166 * V_81 ;
struct V_22 * V_170 ;
bool V_171 = false ;
if ( V_22 ) {
V_81 = F_200 ( V_22 -> V_168 , V_165 ) ;
if ( V_81 -> V_81 . V_79 )
V_171 = true ;
} else {
F_202 (z) {
V_81 = F_200 ( V_170 -> V_168 , V_165 ) ;
if ( V_81 -> V_81 . V_79 ) {
V_171 = true ;
break;
}
}
}
if ( V_171 )
F_207 ( V_165 , & V_169 ) ;
else
F_208 ( V_165 , & V_169 ) ;
}
F_209 ( & V_169 , ( V_172 ) F_203 ,
V_22 , 1 ) ;
}
void F_210 ( struct V_22 * V_22 )
{
unsigned long V_11 , V_173 ;
unsigned long V_59 ;
unsigned int V_43 , V_174 ;
struct V_87 * V_175 ;
if ( F_211 ( V_22 ) )
return;
F_212 ( & V_22 -> V_85 , V_59 ) ;
V_173 = F_113 ( V_22 ) ;
for ( V_11 = V_22 -> V_27 ; V_11 < V_173 ; V_11 ++ )
if ( F_117 ( V_11 ) ) {
struct V_1 * V_1 = F_111 ( V_11 ) ;
if ( ! F_213 ( V_1 ) )
F_214 ( V_1 ) ;
}
F_215 (order, t) {
F_216 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_44 ;
V_11 = F_19 ( F_93 ( V_175 , struct V_1 , V_60 ) ) ;
for ( V_44 = 0 ; V_44 < ( 1UL << V_43 ) ; V_44 ++ )
F_217 ( F_111 ( V_11 + V_44 ) ) ;
}
}
F_218 ( & V_22 -> V_85 , V_59 ) ;
}
void F_219 ( struct V_1 * V_1 , bool V_160 )
{
struct V_22 * V_22 = F_27 ( V_1 ) ;
struct V_80 * V_81 ;
unsigned long V_59 ;
unsigned long V_11 = F_19 ( V_1 ) ;
int V_3 ;
if ( ! F_119 ( V_1 , 0 ) )
return;
V_3 = F_99 ( V_1 , V_11 ) ;
F_2 ( V_1 , V_3 ) ;
F_132 ( V_59 ) ;
F_220 ( V_103 ) ;
if ( V_3 >= V_18 ) {
if ( F_16 ( F_63 ( V_3 ) ) ) {
F_98 ( V_22 , V_1 , V_11 , 0 , V_3 ) ;
goto V_36;
}
V_3 = V_112 ;
}
V_81 = & F_221 ( V_22 -> V_168 ) -> V_81 ;
if ( ! V_160 )
F_82 ( & V_1 -> V_60 , & V_81 -> V_89 [ V_3 ] ) ;
else
F_81 ( & V_1 -> V_60 , & V_81 -> V_89 [ V_3 ] ) ;
V_81 -> V_79 ++ ;
if ( V_81 -> V_79 >= V_81 -> V_131 ) {
unsigned long V_164 = F_198 ( V_81 -> V_164 ) ;
F_88 ( V_22 , V_164 , V_81 ) ;
V_81 -> V_79 -= V_164 ;
}
V_36:
F_134 ( V_59 ) ;
}
void F_222 ( struct V_87 * V_88 , bool V_160 )
{
struct V_1 * V_1 , * V_142 ;
F_223 (page, next, list, lru) {
F_224 ( V_1 , V_160 ) ;
F_219 ( V_1 , V_160 ) ;
}
}
void F_225 ( struct V_1 * V_1 , unsigned int V_43 )
{
int V_44 ;
T_4 V_176 ;
F_72 ( F_120 ( V_1 ) , V_1 ) ;
F_72 ( ! F_73 ( V_1 ) , V_1 ) ;
#ifdef F_226
if ( F_227 ( V_1 ) )
F_225 ( F_228 ( V_1 [ 0 ] . V_177 ) , V_43 ) ;
#endif
V_176 = F_229 ( V_1 ) ;
F_176 ( V_1 , 0 , V_176 ) ;
for ( V_44 = 1 ; V_44 < ( 1 << V_43 ) ; V_44 ++ ) {
F_138 ( V_1 + V_44 ) ;
F_176 ( V_1 + V_44 , 0 , V_176 ) ;
}
}
int F_230 ( struct V_1 * V_1 , unsigned int V_43 )
{
unsigned long V_178 ;
struct V_22 * V_22 ;
int V_90 ;
F_153 ( ! F_74 ( V_1 ) ) ;
V_22 = F_27 ( V_1 ) ;
V_90 = F_95 ( V_1 ) ;
if ( ! F_63 ( V_90 ) ) {
V_178 = F_231 ( V_22 ) + ( 1 << V_43 ) ;
if ( ! F_232 ( V_22 , 0 , V_178 , 0 , 0 ) )
return 0 ;
F_60 ( V_22 , - ( 1UL << V_43 ) , V_90 ) ;
}
F_80 ( & V_1 -> V_60 ) ;
V_22 -> V_69 [ V_43 ] . V_70 -- ;
F_66 ( V_1 ) ;
F_176 ( V_1 , V_43 , V_179 ) ;
if ( V_43 >= V_68 - 1 ) {
struct V_1 * V_180 = V_1 + ( 1 << V_43 ) - 1 ;
for (; V_1 < V_180 ; V_1 += V_128 ) {
int V_90 = F_95 ( V_1 ) ;
if ( ! F_63 ( V_90 ) && ! F_196 ( V_90 ) )
F_15 ( V_1 ,
V_112 ) ;
}
}
return 1UL << V_43 ;
}
int F_233 ( struct V_1 * V_1 )
{
unsigned int V_43 ;
int V_45 ;
V_43 = F_70 ( V_1 ) ;
V_45 = F_230 ( V_1 , V_43 ) ;
if ( ! V_45 )
return 0 ;
F_138 ( V_1 ) ;
F_225 ( V_1 , V_43 ) ;
return V_45 ;
}
static inline
struct V_1 * F_234 ( struct V_22 * V_181 ,
struct V_22 * V_22 , unsigned int V_43 ,
T_4 V_136 , int V_3 )
{
unsigned long V_59 ;
struct V_1 * V_1 ;
bool V_160 = ( ( V_136 & V_182 ) != 0 ) ;
if ( F_195 ( V_43 == 0 ) ) {
struct V_80 * V_81 ;
struct V_87 * V_88 ;
F_132 ( V_59 ) ;
V_81 = & F_221 ( V_22 -> V_168 ) -> V_81 ;
V_88 = & V_81 -> V_89 [ V_3 ] ;
if ( F_92 ( V_88 ) ) {
V_81 -> V_79 += F_194 ( V_22 , 0 ,
V_81 -> V_164 , V_88 ,
V_3 , V_160 ) ;
if ( F_16 ( F_92 ( V_88 ) ) )
goto V_183;
}
if ( V_160 )
V_1 = F_93 ( V_88 -> V_91 , struct V_1 , V_60 ) ;
else
V_1 = F_93 ( V_88 -> V_142 , struct V_1 , V_60 ) ;
F_80 ( & V_1 -> V_60 ) ;
V_81 -> V_79 -- ;
} else {
if ( F_16 ( V_136 & V_184 ) ) {
F_235 ( V_43 > 1 ) ;
}
F_212 ( & V_22 -> V_85 , V_59 ) ;
V_1 = F_192 ( V_22 , V_43 , V_3 ) ;
F_97 ( & V_22 -> V_85 ) ;
if ( ! V_1 )
goto V_183;
F_60 ( V_22 , - ( 1 << V_43 ) ,
F_1 ( V_1 ) ) ;
}
F_91 ( V_22 , V_185 , - ( 1 << V_43 ) ) ;
if ( F_236 ( & V_22 -> V_186 [ V_185 ] ) <= 0 &&
! F_237 ( V_187 , & V_22 -> V_59 ) )
F_238 ( V_187 , & V_22 -> V_59 ) ;
F_239 ( V_188 , V_22 , 1 << V_43 ) ;
F_240 ( V_181 , V_22 , V_136 ) ;
F_134 ( V_59 ) ;
F_72 ( F_28 ( V_22 , V_1 ) , V_1 ) ;
return V_1 ;
V_183:
F_134 ( V_59 ) ;
return NULL ;
}
static int T_3 F_241 ( char * V_189 )
{
return F_242 ( & V_190 . V_191 , V_189 ) ;
}
static bool F_243 ( T_4 V_176 , unsigned int V_43 )
{
if ( V_43 < V_190 . V_192 )
return false ;
if ( V_176 & V_184 )
return false ;
if ( V_190 . V_193 && ( V_176 & V_194 ) )
return false ;
if ( V_190 . V_195 && ( V_176 & V_196 ) )
return false ;
return F_244 ( & V_190 . V_191 , 1 << V_43 ) ;
}
static int T_3 F_245 ( void )
{
T_6 V_197 = V_198 | V_199 | V_200 ;
struct V_201 * V_202 ;
V_202 = F_246 ( L_18 , NULL ,
& V_190 . V_191 ) ;
if ( F_247 ( V_202 ) )
return F_248 ( V_202 ) ;
if ( ! F_249 ( L_19 , V_197 , V_202 ,
& V_190 . V_195 ) )
goto V_203;
if ( ! F_249 ( L_20 , V_197 , V_202 ,
& V_190 . V_193 ) )
goto V_203;
if ( ! F_250 ( L_21 , V_197 , V_202 ,
& V_190 . V_192 ) )
goto V_203;
return 0 ;
V_203:
F_251 ( V_202 ) ;
return - V_204 ;
}
static inline bool F_243 ( T_4 V_176 , unsigned int V_43 )
{
return false ;
}
static bool F_252 ( struct V_22 * V_170 , unsigned int V_43 ,
unsigned long V_205 , int V_206 , int V_137 ,
long V_207 )
{
long F_78 = V_205 ;
int V_208 ;
long V_209 = 0 ;
V_207 -= ( 1 << V_43 ) - 1 ;
if ( V_137 & V_210 )
F_78 -= F_78 / 2 ;
if ( V_137 & V_211 )
F_78 -= F_78 / 4 ;
#ifdef F_253
if ( ! ( V_137 & V_212 ) )
V_209 = F_90 ( V_170 , V_161 ) ;
#endif
if ( V_207 - V_209 <= F_78 + V_170 -> V_213 [ V_206 ] )
return false ;
for ( V_208 = 0 ; V_208 < V_43 ; V_208 ++ ) {
V_207 -= V_170 -> V_69 [ V_208 ] . V_70 << V_208 ;
F_78 >>= 1 ;
if ( V_207 <= F_78 )
return false ;
}
return true ;
}
bool F_232 ( struct V_22 * V_170 , unsigned int V_43 , unsigned long V_205 ,
int V_206 , int V_137 )
{
return F_252 ( V_170 , V_43 , V_205 , V_206 , V_137 ,
F_90 ( V_170 , V_162 ) ) ;
}
bool F_254 ( struct V_22 * V_170 , unsigned int V_43 ,
unsigned long V_205 , int V_206 , int V_137 )
{
long V_207 = F_90 ( V_170 , V_162 ) ;
if ( V_170 -> V_214 && V_207 < V_170 -> V_214 )
V_207 = F_255 ( V_170 , V_162 ) ;
return F_252 ( V_170 , V_43 , V_205 , V_206 , V_137 ,
V_207 ) ;
}
static T_7 * F_256 ( struct V_215 * V_215 , int V_137 )
{
struct V_216 * V_217 ;
T_7 * V_218 ;
V_217 = V_215 -> V_219 ;
if ( ! V_217 )
return NULL ;
if ( F_257 ( V_35 , V_217 -> V_220 + V_38 ) ) {
F_258 ( V_217 -> V_221 , V_222 ) ;
V_217 -> V_220 = V_35 ;
}
V_218 = ! F_259 () && ( V_137 & V_223 ) ?
& V_224 :
& V_225 [ V_127 ] ;
return V_218 ;
}
static int F_260 ( struct V_215 * V_215 , struct V_226 * V_170 ,
T_7 * V_218 )
{
struct V_216 * V_217 ;
int V_44 ;
int V_227 ;
V_217 = V_215 -> V_219 ;
if ( ! V_217 )
return 1 ;
V_44 = V_170 - V_215 -> V_228 ;
V_227 = V_217 -> V_229 [ V_44 ] ;
return F_261 ( V_227 , * V_218 ) && ! F_237 ( V_44 , V_217 -> V_221 ) ;
}
static void F_262 ( struct V_215 * V_215 , struct V_226 * V_170 )
{
struct V_216 * V_217 ;
int V_44 ;
V_217 = V_215 -> V_219 ;
if ( ! V_217 )
return;
V_44 = V_170 - V_215 -> V_228 ;
F_238 ( V_44 , V_217 -> V_221 ) ;
}
static void F_263 ( struct V_215 * V_215 )
{
struct V_216 * V_217 ;
V_217 = V_215 -> V_219 ;
if ( ! V_217 )
return;
F_258 ( V_217 -> V_221 , V_222 ) ;
}
static bool F_264 ( struct V_22 * V_230 , struct V_22 * V_22 )
{
return V_230 -> V_108 == V_22 -> V_108 ;
}
static bool F_265 ( struct V_22 * V_230 , struct V_22 * V_22 )
{
return F_266 ( F_24 ( V_230 ) , F_24 ( V_22 ) ) <
V_231 ;
}
static T_7 * F_256 ( struct V_215 * V_215 , int V_137 )
{
return NULL ;
}
static int F_260 ( struct V_215 * V_215 , struct V_226 * V_170 ,
T_7 * V_218 )
{
return 1 ;
}
static void F_262 ( struct V_215 * V_215 , struct V_226 * V_170 )
{
}
static void F_263 ( struct V_215 * V_215 )
{
}
static bool F_264 ( struct V_22 * V_230 , struct V_22 * V_22 )
{
return true ;
}
static bool F_265 ( struct V_22 * V_230 , struct V_22 * V_22 )
{
return true ;
}
static void F_267 ( struct V_22 * V_181 )
{
struct V_22 * V_22 = V_181 -> V_232 -> V_96 ;
do {
F_268 ( V_22 , V_185 ,
F_269 ( V_22 ) - F_231 ( V_22 ) -
F_236 ( & V_22 -> V_186 [ V_185 ] ) ) ;
F_270 ( V_187 , & V_22 -> V_59 ) ;
} while ( V_22 ++ != V_181 );
}
static struct V_1 *
F_271 ( T_4 V_176 , unsigned int V_43 , int V_137 ,
const struct V_233 * V_234 )
{
struct V_215 * V_215 = V_234 -> V_215 ;
struct V_226 * V_170 ;
struct V_1 * V_1 = NULL ;
struct V_22 * V_22 ;
T_7 * V_218 = NULL ;
int V_235 = 0 ;
int V_236 = 0 ;
bool V_237 = ( V_137 & V_238 ) &&
( V_176 & V_239 ) ;
int V_240 = 0 ;
bool V_241 ;
V_242:
V_241 = false ;
F_272 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_205 ;
if ( F_101 ( V_243 ) && V_235 &&
! F_260 ( V_215 , V_170 , V_218 ) )
continue;
if ( F_273 () &&
( V_137 & V_223 ) &&
! F_274 ( V_22 , V_176 ) )
continue;
if ( V_137 & V_244 ) {
if ( ! F_264 ( V_234 -> V_181 , V_22 ) )
break;
if ( F_237 ( V_187 , & V_22 -> V_59 ) ) {
V_240 ++ ;
continue;
}
}
if ( V_237 && ! F_275 ( V_22 ) )
continue;
V_205 = V_22 -> V_178 [ V_137 & V_245 ] ;
if ( ! F_232 ( V_22 , V_43 , V_205 ,
V_234 -> V_206 , V_137 ) ) {
int V_23 ;
F_276 ( V_140 < V_246 ) ;
if ( V_137 & V_140 )
goto V_247;
if ( F_101 ( V_243 ) &&
! V_236 && V_248 > 1 ) {
V_218 = F_256 ( V_215 , V_137 ) ;
V_235 = 1 ;
V_236 = 1 ;
}
if ( V_249 == 0 ||
! F_265 ( V_234 -> V_181 , V_22 ) )
goto V_250;
if ( F_101 ( V_243 ) && V_235 &&
! F_260 ( V_215 , V_170 , V_218 ) )
continue;
V_23 = F_277 ( V_22 , V_176 , V_43 ) ;
switch ( V_23 ) {
case V_251 :
continue;
case V_252 :
continue;
default:
if ( F_232 ( V_22 , V_43 , V_205 ,
V_234 -> V_206 , V_137 ) )
goto V_247;
if ( ( ( V_137 & V_245 ) == V_253 ) ||
V_23 == V_254 )
goto V_250;
continue;
}
}
V_247:
V_1 = F_234 ( V_234 -> V_181 , V_22 , V_43 ,
V_176 , V_234 -> V_3 ) ;
if ( V_1 ) {
if ( F_172 ( V_1 , V_43 , V_176 , V_137 ) )
goto V_247;
return V_1 ;
}
V_250:
if ( F_101 ( V_243 ) && V_235 )
F_262 ( V_215 , V_170 ) ;
}
if ( V_137 & V_244 ) {
V_137 &= ~ V_244 ;
if ( V_240 ) {
V_241 = true ;
F_267 ( V_234 -> V_181 ) ;
}
if ( V_248 > 1 )
V_241 = true ;
}
if ( F_16 ( F_101 ( V_243 ) && V_235 ) ) {
V_235 = 0 ;
V_241 = true ;
}
if ( V_241 )
goto V_242;
return NULL ;
}
static inline bool F_278 ( void )
{
bool V_23 = false ;
#if V_255 > 8
V_23 = F_259 () ;
#endif
return V_23 ;
}
void F_279 ( T_4 V_176 , int V_43 , const char * V_256 , ... )
{
unsigned int V_257 = V_258 ;
if ( ( V_176 & V_259 ) || ! F_280 ( & V_260 ) ||
F_170 () > 0 )
return;
if ( ! ( V_176 & V_261 ) )
if ( F_281 ( V_262 ) ||
( V_39 -> V_59 & ( V_263 | V_264 ) ) )
V_257 &= ~ V_258 ;
if ( F_259 () || ! ( V_176 & V_196 ) )
V_257 &= ~ V_258 ;
if ( V_256 ) {
struct V_265 V_266 ;
T_8 args ;
va_start ( args , V_256 ) ;
V_266 . V_256 = V_256 ;
V_266 . V_267 = & args ;
F_282 ( L_22 , & V_266 ) ;
va_end ( args ) ;
}
F_282 ( L_23 ,
V_39 -> V_40 , V_43 , V_176 ) ;
F_36 () ;
if ( ! F_278 () )
F_283 ( V_257 ) ;
}
static inline struct V_1 *
F_284 ( T_4 V_176 , unsigned int V_43 ,
const struct V_233 * V_234 , unsigned long * V_268 )
{
struct V_269 V_270 = {
. V_215 = V_234 -> V_215 ,
. V_271 = V_234 -> V_271 ,
. V_176 = V_176 ,
. V_43 = V_43 ,
} ;
struct V_1 * V_1 ;
* V_268 = 0 ;
if ( ! F_285 ( & V_272 ) ) {
* V_268 = 1 ;
F_286 ( 1 ) ;
return NULL ;
}
V_1 = F_271 ( V_176 | V_273 , V_43 ,
V_274 | V_223 , V_234 ) ;
if ( V_1 )
goto V_36;
if ( ! ( V_176 & V_184 ) ) {
if ( V_39 -> V_59 & V_275 )
goto V_36;
if ( V_43 > V_276 )
goto V_36;
if ( V_234 -> V_277 < V_278 )
goto V_36;
if ( ! ( V_176 & V_279 ) ) {
* V_268 = 1 ;
goto V_36;
}
if ( F_7 () )
goto V_36;
if ( V_176 & V_280 )
goto V_36;
}
if ( F_287 ( & V_270 ) || F_235 ( V_176 & V_184 ) )
* V_268 = 1 ;
V_36:
F_288 ( & V_272 ) ;
return V_1 ;
}
static struct V_1 *
F_289 ( T_4 V_176 , unsigned int V_43 ,
int V_137 , const struct V_233 * V_234 ,
enum V_281 V_197 , int * V_282 ,
bool * V_283 )
{
unsigned long V_284 ;
struct V_1 * V_1 ;
if ( ! V_43 )
return NULL ;
V_39 -> V_59 |= V_263 ;
V_284 = F_290 ( V_176 , V_43 , V_137 , V_234 ,
V_197 , V_282 ) ;
V_39 -> V_59 &= ~ V_263 ;
switch ( V_284 ) {
case V_285 :
* V_283 = true ;
case V_286 :
return NULL ;
default:
break;
}
F_291 ( V_287 ) ;
V_1 = F_271 ( V_176 , V_43 ,
V_137 & ~ V_140 , V_234 ) ;
if ( V_1 ) {
struct V_22 * V_22 = F_27 ( V_1 ) ;
V_22 -> V_288 = false ;
F_292 ( V_22 , V_43 , true ) ;
F_291 ( V_289 ) ;
return V_1 ;
}
F_291 ( V_290 ) ;
F_155 () ;
return NULL ;
}
static inline struct V_1 *
F_289 ( T_4 V_176 , unsigned int V_43 ,
int V_137 , const struct V_233 * V_234 ,
enum V_281 V_197 , int * V_282 ,
bool * V_283 )
{
return NULL ;
}
static int
F_293 ( T_4 V_176 , unsigned int V_43 ,
const struct V_233 * V_234 )
{
struct V_291 V_291 ;
int V_292 ;
F_155 () ;
F_294 () ;
V_39 -> V_59 |= V_263 ;
F_295 ( V_176 ) ;
V_291 . V_293 = 0 ;
V_39 -> V_291 = & V_291 ;
V_292 = F_296 ( V_234 -> V_215 , V_43 , V_176 ,
V_234 -> V_271 ) ;
V_39 -> V_291 = NULL ;
F_297 () ;
V_39 -> V_59 &= ~ V_263 ;
F_155 () ;
return V_292 ;
}
static inline struct V_1 *
F_298 ( T_4 V_176 , unsigned int V_43 ,
int V_137 , const struct V_233 * V_234 ,
unsigned long * V_268 )
{
struct V_1 * V_1 = NULL ;
bool V_294 = false ;
* V_268 = F_293 ( V_176 , V_43 , V_234 ) ;
if ( F_16 ( ! ( * V_268 ) ) )
return NULL ;
if ( F_101 ( V_243 ) )
F_263 ( V_234 -> V_215 ) ;
V_295:
V_1 = F_271 ( V_176 , V_43 ,
V_137 & ~ V_140 , V_234 ) ;
if ( ! V_1 && ! V_294 ) {
F_205 ( NULL ) ;
V_294 = true ;
goto V_295;
}
return V_1 ;
}
static inline struct V_1 *
F_299 ( T_4 V_176 , unsigned int V_43 ,
const struct V_233 * V_234 )
{
struct V_1 * V_1 ;
do {
V_1 = F_271 ( V_176 , V_43 ,
V_140 , V_234 ) ;
if ( ! V_1 && V_176 & V_184 )
F_300 ( V_234 -> V_181 , V_296 ,
V_38 / 50 ) ;
} while ( ! V_1 && ( V_176 & V_184 ) );
return V_1 ;
}
static void F_301 ( unsigned int V_43 , const struct V_233 * V_234 )
{
struct V_226 * V_170 ;
struct V_22 * V_22 ;
F_272 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_302 ( V_22 , V_43 , F_303 ( V_234 -> V_181 ) ) ;
}
static inline int
F_304 ( T_4 V_176 )
{
int V_137 = V_253 | V_223 ;
const bool V_297 = ! ( V_176 & ( V_196 | V_298 ) ) ;
F_276 ( V_299 != ( V_300 T_4 ) V_210 ) ;
V_137 |= ( V_300 int ) ( V_176 & V_299 ) ;
if ( V_297 ) {
if ( ! ( V_176 & V_261 ) )
V_137 |= V_211 ;
V_137 &= ~ V_223 ;
} else if ( F_16 ( F_305 ( V_39 ) ) && ! F_259 () )
V_137 |= V_211 ;
if ( F_195 ( ! ( V_176 & V_261 ) ) ) {
if ( V_176 & V_301 )
V_137 |= V_140 ;
else if ( F_306 () && ( V_39 -> V_59 & V_263 ) )
V_137 |= V_140 ;
else if ( ! F_259 () &&
( ( V_39 -> V_59 & V_263 ) ||
F_16 ( F_281 ( V_262 ) ) ) )
V_137 |= V_140 ;
}
#ifdef F_253
if ( F_307 ( V_176 ) == V_112 )
V_137 |= V_212 ;
#endif
return V_137 ;
}
bool F_308 ( T_4 V_176 )
{
return ! ! ( F_304 ( V_176 ) & V_140 ) ;
}
static inline struct V_1 *
F_309 ( T_4 V_176 , unsigned int V_43 ,
struct V_233 * V_234 )
{
const T_4 V_302 = V_176 & V_196 ;
struct V_1 * V_1 = NULL ;
int V_137 ;
unsigned long V_303 = 0 ;
unsigned long V_268 ;
enum V_281 V_304 = V_305 ;
bool V_283 = false ;
int V_282 = V_306 ;
if ( V_43 >= V_53 ) {
F_235 ( ! ( V_176 & V_259 ) ) ;
return NULL ;
}
if ( F_101 ( V_243 ) && ( V_176 & V_280 ) && ! V_302 )
goto V_307;
V_295:
if ( ! ( V_176 & V_298 ) )
F_301 ( V_43 , V_234 ) ;
V_137 = F_304 ( V_176 ) ;
if ( ! ( V_137 & V_223 ) && ! V_234 -> V_271 ) {
struct V_226 * V_308 ;
V_308 = F_310 ( V_234 -> V_215 ,
V_234 -> V_277 , NULL , & V_234 -> V_181 ) ;
V_234 -> V_206 = F_311 ( V_308 ) ;
}
V_1 = F_271 ( V_176 , V_43 ,
V_137 & ~ V_140 , V_234 ) ;
if ( V_1 )
goto V_309;
if ( V_137 & V_140 ) {
V_234 -> V_215 = F_312 ( F_313 () , V_176 ) ;
V_1 = F_299 ( V_176 , V_43 , V_234 ) ;
if ( V_1 ) {
goto V_309;
}
}
if ( ! V_302 ) {
F_235 ( V_176 & V_184 ) ;
goto V_307;
}
if ( V_39 -> V_59 & V_263 )
goto V_307;
if ( F_281 ( V_262 ) && ! ( V_176 & V_184 ) )
goto V_307;
V_1 = F_289 ( V_176 , V_43 , V_137 , V_234 ,
V_304 ,
& V_282 ,
& V_283 ) ;
if ( V_1 )
goto V_309;
if ( ( V_176 & V_310 ) == V_310 ) {
if ( V_283 )
goto V_307;
if ( V_282 == V_311 )
goto V_307;
if ( V_282 == V_312
&& ! ( V_39 -> V_59 & V_313 ) )
goto V_307;
}
if ( ( V_176 & V_310 ) != V_310 ||
( V_39 -> V_59 & V_313 ) )
V_304 = V_314 ;
V_1 = F_298 ( V_176 , V_43 , V_137 , V_234 ,
& V_268 ) ;
if ( V_1 )
goto V_309;
if ( V_176 & V_315 )
goto V_316;
V_303 += V_268 ;
if ( ( V_268 && V_43 <= V_276 ) ||
( ( V_176 & V_317 ) && V_303 < ( 1 << V_43 ) ) ) {
F_300 ( V_234 -> V_181 , V_296 , V_38 / 50 ) ;
goto V_295;
}
V_1 = F_284 ( V_176 , V_43 , V_234 , & V_268 ) ;
if ( V_1 )
goto V_309;
if ( V_268 )
goto V_295;
V_316:
V_1 = F_289 ( V_176 , V_43 , V_137 ,
V_234 , V_304 ,
& V_282 ,
& V_283 ) ;
if ( V_1 )
goto V_309;
V_307:
F_279 ( V_176 , V_43 , NULL ) ;
V_309:
return V_1 ;
}
struct V_1 *
F_314 ( T_4 V_176 , unsigned int V_43 ,
struct V_215 * V_215 , T_7 * V_271 )
{
struct V_226 * V_308 ;
struct V_1 * V_1 = NULL ;
unsigned int V_318 ;
int V_137 = V_238 | V_223 | V_244 ;
T_4 V_319 ;
struct V_233 V_234 = {
. V_277 = F_315 ( V_176 ) ,
. V_271 = V_271 ,
. V_3 = F_307 ( V_176 ) ,
} ;
V_176 &= V_6 ;
F_316 ( V_176 ) ;
F_317 ( V_176 & V_196 ) ;
if ( F_243 ( V_176 , V_43 ) )
return NULL ;
if ( F_16 ( ! V_215 -> V_228 -> V_22 ) )
return NULL ;
if ( F_101 ( F_253 ) && V_234 . V_3 == V_112 )
V_137 |= V_212 ;
V_320:
V_318 = F_318 () ;
V_234 . V_215 = V_215 ;
V_308 = F_310 ( V_234 . V_215 , V_234 . V_277 ,
V_234 . V_271 ? : & V_224 ,
& V_234 . V_181 ) ;
if ( ! V_234 . V_181 )
goto V_36;
V_234 . V_206 = F_311 ( V_308 ) ;
V_319 = V_176 | V_273 ;
V_1 = F_271 ( V_319 , V_43 , V_137 , & V_234 ) ;
if ( F_16 ( ! V_1 ) ) {
V_319 = F_319 ( V_176 ) ;
V_1 = F_309 ( V_319 , V_43 , & V_234 ) ;
}
if ( V_321 && V_1 )
F_320 ( V_1 , V_43 , V_176 ) ;
F_321 ( V_1 , V_43 , V_319 , V_234 . V_3 ) ;
V_36:
if ( F_16 ( ! V_1 && F_322 ( V_318 ) ) )
goto V_320;
return V_1 ;
}
unsigned long F_323 ( T_4 V_176 , unsigned int V_43 )
{
struct V_1 * V_1 ;
F_76 ( ( V_176 & V_194 ) != 0 ) ;
V_1 = F_324 ( V_176 , V_43 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_128 ( V_1 ) ;
}
unsigned long F_325 ( T_4 V_176 )
{
return F_323 ( V_176 | V_138 , 0 ) ;
}
void F_139 ( struct V_1 * V_1 , unsigned int V_43 )
{
if ( F_326 ( V_1 ) ) {
if ( V_43 == 0 )
F_219 ( V_1 , false ) ;
else
F_39 ( V_1 , V_43 ) ;
}
}
void V_207 ( unsigned long V_322 , unsigned int V_43 )
{
if ( V_322 != 0 ) {
F_76 ( ! F_327 ( ( void * ) V_322 ) ) ;
F_139 ( F_228 ( ( void * ) V_322 ) , V_43 ) ;
}
}
static struct V_1 * F_328 ( struct V_323 * V_324 ,
T_4 V_176 )
{
struct V_1 * V_1 = NULL ;
T_4 V_325 = V_176 ;
#if ( V_102 < V_326 )
V_176 |= V_139 | V_259 | V_315 |
V_261 ;
V_1 = F_329 ( V_327 , V_176 ,
V_328 ) ;
V_324 -> V_133 = V_1 ? V_326 : V_102 ;
#endif
if ( F_16 ( ! V_1 ) )
V_1 = F_329 ( V_327 , V_325 , 0 ) ;
V_324 -> V_267 = V_1 ? F_128 ( V_1 ) : NULL ;
return V_1 ;
}
void * F_330 ( struct V_323 * V_324 ,
unsigned int V_329 , T_4 V_176 )
{
unsigned int V_133 = V_102 ;
struct V_1 * V_1 ;
int V_330 ;
if ( F_16 ( ! V_324 -> V_267 ) ) {
V_331:
V_1 = F_328 ( V_324 , V_176 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_102 < V_326 )
V_133 = V_324 -> V_133 ;
#endif
F_331 ( V_133 - 1 , & V_1 -> V_76 ) ;
V_324 -> V_332 = F_332 ( V_1 ) ;
V_324 -> V_333 = V_133 ;
V_324 -> V_330 = V_133 ;
}
V_330 = V_324 -> V_330 - V_329 ;
if ( F_16 ( V_330 < 0 ) ) {
V_1 = F_228 ( V_324 -> V_267 ) ;
if ( ! F_333 ( V_324 -> V_333 , & V_1 -> V_76 ) )
goto V_331;
#if ( V_102 < V_326 )
V_133 = V_324 -> V_133 ;
#endif
F_161 ( & V_1 -> V_76 , V_133 ) ;
V_324 -> V_333 = V_133 ;
V_330 = V_133 - V_329 ;
}
V_324 -> V_333 -- ;
V_324 -> V_330 = V_330 ;
return V_324 -> V_267 + V_330 ;
}
void F_334 ( void * V_322 )
{
struct V_1 * V_1 = F_335 ( V_322 ) ;
if ( F_16 ( F_326 ( V_1 ) ) )
F_39 ( V_1 , F_40 ( V_1 ) ) ;
}
struct V_1 * F_336 ( T_4 V_176 , unsigned int V_43 )
{
struct V_1 * V_1 ;
struct V_78 * V_334 = NULL ;
if ( ! F_337 ( V_176 , & V_334 , V_43 ) )
return NULL ;
V_1 = F_324 ( V_176 , V_43 ) ;
F_338 ( V_1 , V_334 , V_43 ) ;
return V_1 ;
}
struct V_1 * F_339 ( int V_12 , T_4 V_176 , unsigned int V_43 )
{
struct V_1 * V_1 ;
struct V_78 * V_334 = NULL ;
if ( ! F_337 ( V_176 , & V_334 , V_43 ) )
return NULL ;
V_1 = F_329 ( V_12 , V_176 , V_43 ) ;
F_338 ( V_1 , V_334 , V_43 ) ;
return V_1 ;
}
void F_340 ( struct V_1 * V_1 , unsigned int V_43 )
{
F_341 ( V_1 , V_43 ) ;
F_139 ( V_1 , V_43 ) ;
}
void F_342 ( unsigned long V_322 , unsigned int V_43 )
{
if ( V_322 != 0 ) {
F_76 ( ! F_327 ( ( void * ) V_322 ) ) ;
F_340 ( F_228 ( ( void * ) V_322 ) , V_43 ) ;
}
}
static void * F_343 ( unsigned long V_322 , unsigned V_43 , T_9 V_133 )
{
if ( V_322 ) {
unsigned long V_335 = V_322 + ( V_102 << V_43 ) ;
unsigned long V_336 = V_322 + F_344 ( V_133 ) ;
F_225 ( F_228 ( ( void * ) V_322 ) , V_43 ) ;
while ( V_336 < V_335 ) {
F_345 ( V_336 ) ;
V_336 += V_102 ;
}
}
return ( void * ) V_322 ;
}
void * F_346 ( T_9 V_133 , T_4 V_176 )
{
unsigned int V_43 = F_347 ( V_133 ) ;
unsigned long V_322 ;
V_322 = F_323 ( V_176 , V_43 ) ;
return F_343 ( V_322 , V_43 , V_133 ) ;
}
void * T_2 F_348 ( int V_12 , T_9 V_133 , T_4 V_176 )
{
unsigned V_43 = F_347 ( V_133 ) ;
struct V_1 * V_46 = F_329 ( V_12 , V_176 , V_43 ) ;
if ( ! V_46 )
return NULL ;
return F_343 ( ( unsigned long ) F_128 ( V_46 ) , V_43 , V_133 ) ;
}
void F_349 ( void * V_337 , T_9 V_133 )
{
unsigned long V_322 = ( unsigned long ) V_337 ;
unsigned long V_98 = V_322 + F_344 ( V_133 ) ;
while ( V_322 < V_98 ) {
F_345 ( V_322 ) ;
V_322 += V_102 ;
}
}
static unsigned long F_350 ( int V_330 )
{
struct V_226 * V_170 ;
struct V_22 * V_22 ;
unsigned long V_338 = 0 ;
struct V_215 * V_215 = F_312 ( F_313 () , V_339 ) ;
F_351 (zone, z, zonelist, offset) {
unsigned long V_133 = V_22 -> V_105 ;
unsigned long V_131 = F_269 ( V_22 ) ;
if ( V_133 > V_131 )
V_338 += V_133 - V_131 ;
}
return V_338 ;
}
unsigned long F_352 ( void )
{
return F_350 ( F_315 ( V_340 ) ) ;
}
unsigned long F_353 ( void )
{
return F_350 ( F_315 ( V_341 ) ) ;
}
static inline void F_354 ( struct V_22 * V_22 )
{
if ( F_101 ( V_243 ) )
F_33 ( L_24 , F_24 ( V_22 ) ) ;
}
void F_355 ( struct V_342 * V_343 )
{
V_343 -> V_344 = V_345 ;
V_343 -> V_346 = F_356 ( V_347 ) ;
V_343 -> V_348 = F_356 ( V_162 ) ;
V_343 -> V_349 = F_357 () ;
V_343 -> V_350 = V_351 ;
V_343 -> V_352 = F_358 () ;
V_343 -> V_353 = V_102 ;
}
void F_359 ( struct V_342 * V_343 , int V_12 )
{
int V_354 ;
unsigned long V_105 = 0 ;
T_1 * V_8 = F_10 ( V_12 ) ;
for ( V_354 = 0 ; V_354 < V_95 ; V_354 ++ )
V_105 += V_8 -> V_96 [ V_354 ] . V_105 ;
V_343 -> V_344 = V_105 ;
V_343 -> V_346 = F_360 ( V_12 , V_347 ) ;
V_343 -> V_348 = F_360 ( V_12 , V_162 ) ;
#ifdef F_361
V_343 -> V_350 = V_8 -> V_96 [ V_355 ] . V_105 ;
V_343 -> V_352 = F_90 ( & V_8 -> V_96 [ V_355 ] ,
V_162 ) ;
#else
V_343 -> V_350 = 0 ;
V_343 -> V_352 = 0 ;
#endif
V_343 -> V_353 = V_102 ;
}
bool F_362 ( unsigned int V_59 , int V_12 )
{
bool V_23 = false ;
unsigned int V_318 ;
if ( ! ( V_59 & V_258 ) )
goto V_36;
do {
V_318 = F_318 () ;
V_23 = ! F_261 ( V_12 , V_224 ) ;
} while ( F_322 ( V_318 ) );
V_36:
return V_23 ;
}
static void F_363 ( unsigned char type )
{
static const char V_356 [ V_357 ] = {
[ V_19 ] = 'U' ,
[ V_150 ] = 'E' ,
[ V_112 ] = 'M' ,
[ V_157 ] = 'R' ,
#ifdef F_253
[ V_129 ] = 'C' ,
#endif
#ifdef F_364
[ V_358 ] = 'I' ,
#endif
} ;
char V_359 [ V_357 + 1 ] ;
char * V_46 = V_359 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_357 ; V_44 ++ ) {
if ( type & ( 1 << V_44 ) )
* V_46 ++ = V_356 [ V_44 ] ;
}
* V_46 = '\0' ;
F_33 ( L_25 , V_359 ) ;
}
void F_365 ( unsigned int V_257 )
{
unsigned long V_360 = 0 ;
int V_165 ;
struct V_22 * V_22 ;
F_202 (zone) {
if ( F_362 ( V_257 , F_24 ( V_22 ) ) )
continue;
F_206 (cpu)
V_360 += F_200 ( V_22 -> V_168 , V_165 ) -> V_81 . V_79 ;
}
F_33 ( L_26
L_27
L_28
L_29
L_30
L_31 ,
F_356 ( V_361 ) ,
F_356 ( V_362 ) ,
F_356 ( V_363 ) ,
F_356 ( V_364 ) ,
F_356 ( V_365 ) ,
F_356 ( V_366 ) ,
F_356 ( V_367 ) ,
F_356 ( V_368 ) ,
F_356 ( V_369 ) ,
F_356 ( V_370 ) ,
F_356 ( V_371 ) ,
F_356 ( V_372 ) ,
F_356 ( V_373 ) ,
F_356 ( V_347 ) ,
F_356 ( V_374 ) ,
F_356 ( V_375 ) ,
F_356 ( V_162 ) ,
V_360 ,
F_356 ( V_161 ) ) ;
F_202 (zone) {
int V_44 ;
if ( F_362 ( V_257 , F_24 ( V_22 ) ) )
continue;
V_360 = 0 ;
F_206 (cpu)
V_360 += F_200 ( V_22 -> V_168 , V_165 ) -> V_81 . V_79 ;
F_354 ( V_22 ) ;
F_33 ( L_32
L_33
L_34
L_35
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
L_63 ,
V_22 -> V_29 ,
F_366 ( F_90 ( V_22 , V_162 ) ) ,
F_366 ( F_367 ( V_22 ) ) ,
F_366 ( F_231 ( V_22 ) ) ,
F_366 ( F_269 ( V_22 ) ) ,
F_366 ( F_90 ( V_22 , V_361 ) ) ,
F_366 ( F_90 ( V_22 , V_362 ) ) ,
F_366 ( F_90 ( V_22 , V_364 ) ) ,
F_366 ( F_90 ( V_22 , V_365 ) ) ,
F_366 ( F_90 ( V_22 , V_367 ) ) ,
F_366 ( F_90 ( V_22 , V_363 ) ) ,
F_366 ( F_90 ( V_22 , V_366 ) ) ,
F_366 ( V_22 -> V_376 ) ,
F_366 ( V_22 -> V_105 ) ,
F_366 ( F_90 ( V_22 , V_377 ) ) ,
F_366 ( F_90 ( V_22 , V_368 ) ) ,
F_366 ( F_90 ( V_22 , V_369 ) ) ,
F_366 ( F_90 ( V_22 , V_373 ) ) ,
F_366 ( F_90 ( V_22 , V_347 ) ) ,
F_366 ( F_90 ( V_22 , V_371 ) ) ,
F_366 ( F_90 ( V_22 , V_372 ) ) ,
F_90 ( V_22 , V_378 ) *
V_379 / 1024 ,
F_366 ( F_90 ( V_22 , V_374 ) ) ,
F_366 ( F_90 ( V_22 , V_370 ) ) ,
F_366 ( F_90 ( V_22 , V_375 ) ) ,
F_366 ( V_360 ) ,
F_366 ( F_368 ( V_22 -> V_168 -> V_81 . V_79 ) ) ,
F_366 ( F_90 ( V_22 , V_161 ) ) ,
F_366 ( F_90 ( V_22 , V_380 ) ) ,
F_366 ( F_90 ( V_22 , V_86 ) ) ,
( ! F_369 ( V_22 ) ? L_64 : L_65 )
) ;
F_33 ( L_66 ) ;
for ( V_44 = 0 ; V_44 < V_95 ; V_44 ++ )
F_33 ( L_67 , V_22 -> V_213 [ V_44 ] ) ;
F_33 ( L_63 ) ;
}
F_202 (zone) {
unsigned long V_381 [ V_53 ] , V_59 , V_43 , V_382 = 0 ;
unsigned char V_356 [ V_53 ] ;
if ( F_362 ( V_257 , F_24 ( V_22 ) ) )
continue;
F_354 ( V_22 ) ;
F_33 ( L_68 , V_22 -> V_29 ) ;
F_212 ( & V_22 -> V_85 , V_59 ) ;
for ( V_43 = 0 ; V_43 < V_53 ; V_43 ++ ) {
struct V_69 * V_132 = & V_22 -> V_69 [ V_43 ] ;
int type ;
V_381 [ V_43 ] = V_132 -> V_70 ;
V_382 += V_381 [ V_43 ] << V_43 ;
V_356 [ V_43 ] = 0 ;
for ( type = 0 ; type < V_357 ; type ++ ) {
if ( ! F_92 ( & V_132 -> V_73 [ type ] ) )
V_356 [ V_43 ] |= 1 << type ;
}
}
F_218 ( & V_22 -> V_85 , V_59 ) ;
for ( V_43 = 0 ; V_43 < V_53 ; V_43 ++ ) {
F_33 ( L_69 , V_381 [ V_43 ] , F_366 ( 1UL ) << V_43 ) ;
if ( V_381 [ V_43 ] )
F_363 ( V_356 [ V_43 ] ) ;
}
F_33 ( L_70 , F_366 ( V_382 ) ) ;
}
F_370 () ;
F_33 ( L_71 , F_356 ( V_383 ) ) ;
F_371 () ;
}
static void F_372 ( struct V_22 * V_22 , struct V_226 * V_226 )
{
V_226 -> V_22 = V_22 ;
V_226 -> F_303 = F_303 ( V_22 ) ;
}
static int F_373 ( T_1 * V_8 , struct V_215 * V_215 ,
int V_384 )
{
struct V_22 * V_22 ;
enum V_354 V_354 = V_95 ;
do {
V_354 -- ;
V_22 = V_8 -> V_96 + V_354 ;
if ( F_157 ( V_22 ) ) {
F_372 ( V_22 ,
& V_215 -> V_228 [ V_384 ++ ] ) ;
F_374 ( V_354 ) ;
}
} while ( V_354 );
return V_384 ;
}
static int F_375 ( char * V_385 )
{
if ( * V_385 == 'd' || * V_385 == 'D' ) {
V_386 = V_387 ;
} else if ( * V_385 == 'n' || * V_385 == 'N' ) {
V_386 = V_388 ;
} else if ( * V_385 == 'z' || * V_385 == 'Z' ) {
V_386 = V_389 ;
} else {
F_33 ( V_390
L_72
L_73 , V_385 ) ;
return - V_49 ;
}
return 0 ;
}
static T_3 int F_376 ( char * V_385 )
{
int V_23 ;
if ( ! V_385 )
return 0 ;
V_23 = F_375 ( V_385 ) ;
if ( V_23 == 0 )
F_377 ( V_391 , V_385 , V_392 ) ;
return V_23 ;
}
int F_378 ( struct V_393 * V_394 , int V_395 ,
void T_10 * V_396 , T_9 * V_397 ,
T_11 * V_398 )
{
char V_399 [ V_392 ] ;
int V_23 ;
static F_379 ( V_400 ) ;
F_380 ( & V_400 ) ;
if ( V_395 ) {
if ( strlen ( ( char * ) V_394 -> V_115 ) >= V_392 ) {
V_23 = - V_49 ;
goto V_36;
}
strcpy ( V_399 , ( char * ) V_394 -> V_115 ) ;
}
V_23 = F_381 ( V_394 , V_395 , V_396 , V_397 , V_398 ) ;
if ( V_23 )
goto V_36;
if ( V_395 ) {
int V_401 = V_386 ;
V_23 = F_375 ( ( char * ) V_394 -> V_115 ) ;
if ( V_23 ) {
strncpy ( ( char * ) V_394 -> V_115 , V_399 ,
V_392 ) ;
V_386 = V_401 ;
} else if ( V_401 != V_386 ) {
F_380 ( & V_402 ) ;
F_382 ( NULL , NULL ) ;
F_288 ( & V_402 ) ;
}
}
V_36:
F_288 ( & V_400 ) ;
return V_23 ;
}
static int F_383 ( int V_108 , T_7 * V_403 )
{
int V_227 , V_343 ;
int V_404 = V_405 ;
int V_406 = V_327 ;
const struct V_121 * V_359 = F_150 ( 0 ) ;
if ( ! F_261 ( V_108 , * V_403 ) ) {
F_384 ( V_108 , * V_403 ) ;
return V_108 ;
}
F_163 (n, N_MEMORY) {
if ( F_261 ( V_227 , * V_403 ) )
continue;
V_343 = F_266 ( V_108 , V_227 ) ;
V_343 += ( V_227 < V_108 ) ;
V_359 = F_150 ( V_227 ) ;
if ( ! F_151 ( V_359 ) )
V_343 += V_407 ;
V_343 *= ( V_408 * V_409 ) ;
V_343 += V_410 [ V_227 ] ;
if ( V_343 < V_404 ) {
V_404 = V_343 ;
V_406 = V_227 ;
}
}
if ( V_406 >= 0 )
F_384 ( V_406 , * V_403 ) ;
return V_406 ;
}
static void F_385 ( T_1 * V_8 , int V_108 )
{
int V_411 ;
struct V_215 * V_215 ;
V_215 = & V_8 -> V_412 [ 0 ] ;
for ( V_411 = 0 ; V_215 -> V_228 [ V_411 ] . V_22 != NULL ; V_411 ++ )
;
V_411 = F_373 ( F_10 ( V_108 ) , V_215 , V_411 ) ;
V_215 -> V_228 [ V_411 ] . V_22 = NULL ;
V_215 -> V_228 [ V_411 ] . F_303 = 0 ;
}
static void F_386 ( T_1 * V_8 )
{
int V_411 ;
struct V_215 * V_215 ;
V_215 = & V_8 -> V_412 [ 1 ] ;
V_411 = F_373 ( V_8 , V_215 , 0 ) ;
V_215 -> V_228 [ V_411 ] . V_22 = NULL ;
V_215 -> V_228 [ V_411 ] . F_303 = 0 ;
}
static void F_387 ( T_1 * V_8 , int V_413 )
{
int V_414 , V_411 , V_108 ;
int V_354 ;
struct V_22 * V_170 ;
struct V_215 * V_215 ;
V_215 = & V_8 -> V_412 [ 0 ] ;
V_414 = 0 ;
for ( V_354 = V_95 - 1 ; V_354 >= 0 ; V_354 -- ) {
for ( V_411 = 0 ; V_411 < V_413 ; V_411 ++ ) {
V_108 = V_415 [ V_411 ] ;
V_170 = & F_10 ( V_108 ) -> V_96 [ V_354 ] ;
if ( F_157 ( V_170 ) ) {
F_372 ( V_170 ,
& V_215 -> V_228 [ V_414 ++ ] ) ;
F_374 ( V_354 ) ;
}
}
}
V_215 -> V_228 [ V_414 ] . V_22 = NULL ;
V_215 -> V_228 [ V_414 ] . F_303 = 0 ;
}
static int F_388 ( void )
{
return V_388 ;
}
static int F_388 ( void )
{
return V_389 ;
}
static void F_389 ( void )
{
if ( V_386 == V_387 )
V_416 = F_388 () ;
else
V_416 = V_386 ;
}
static void F_390 ( T_1 * V_8 )
{
int V_411 , V_108 , V_417 ;
enum V_354 V_44 ;
T_7 V_418 ;
int V_419 , V_420 ;
struct V_215 * V_215 ;
int V_43 = V_416 ;
for ( V_44 = 0 ; V_44 < V_421 ; V_44 ++ ) {
V_215 = V_8 -> V_412 + V_44 ;
V_215 -> V_228 [ 0 ] . V_22 = NULL ;
V_215 -> V_228 [ 0 ] . F_303 = 0 ;
}
V_419 = V_8 -> V_116 ;
V_417 = V_248 ;
V_420 = V_419 ;
F_391 ( V_418 ) ;
memset ( V_415 , 0 , sizeof( V_415 ) ) ;
V_411 = 0 ;
while ( ( V_108 = F_383 ( V_419 , & V_418 ) ) >= 0 ) {
if ( F_266 ( V_419 , V_108 ) !=
F_266 ( V_419 , V_420 ) )
V_410 [ V_108 ] = V_417 ;
V_420 = V_108 ;
V_417 -- ;
if ( V_43 == V_388 )
F_385 ( V_8 , V_108 ) ;
else
V_415 [ V_411 ++ ] = V_108 ;
}
if ( V_43 == V_389 ) {
F_387 ( V_8 , V_411 ) ;
}
F_386 ( V_8 ) ;
}
static void F_392 ( T_1 * V_8 )
{
struct V_215 * V_215 ;
struct V_216 * V_217 ;
struct V_226 * V_170 ;
V_215 = & V_8 -> V_412 [ 0 ] ;
V_215 -> V_219 = V_217 = & V_215 -> V_422 ;
F_258 ( V_217 -> V_221 , V_222 ) ;
for ( V_170 = V_215 -> V_228 ; V_170 -> V_22 ; V_170 ++ )
V_217 -> V_229 [ V_170 - V_215 -> V_228 ] = F_393 ( V_170 ) ;
}
int F_394 ( int V_108 )
{
struct V_22 * V_22 ;
( void ) F_310 ( F_312 ( V_108 , V_339 ) ,
F_315 ( V_339 ) ,
NULL ,
& V_22 ) ;
return V_22 -> V_108 ;
}
static void F_389 ( void )
{
V_416 = V_389 ;
}
static void F_390 ( T_1 * V_8 )
{
int V_108 , V_419 ;
enum V_354 V_411 ;
struct V_215 * V_215 ;
V_419 = V_8 -> V_116 ;
V_215 = & V_8 -> V_412 [ 0 ] ;
V_411 = F_373 ( V_8 , V_215 , 0 ) ;
for ( V_108 = V_419 + 1 ; V_108 < V_409 ; V_108 ++ ) {
if ( ! F_395 ( V_108 ) )
continue;
V_411 = F_373 ( F_10 ( V_108 ) , V_215 , V_411 ) ;
}
for ( V_108 = 0 ; V_108 < V_419 ; V_108 ++ ) {
if ( ! F_395 ( V_108 ) )
continue;
V_411 = F_373 ( F_10 ( V_108 ) , V_215 , V_411 ) ;
}
V_215 -> V_228 [ V_411 ] . V_22 = NULL ;
V_215 -> V_228 [ V_411 ] . F_303 = 0 ;
}
static void F_392 ( T_1 * V_8 )
{
V_8 -> V_412 [ 0 ] . V_219 = NULL ;
}
static int F_396 ( void * V_115 )
{
int V_12 ;
int V_165 ;
T_1 * V_423 = V_115 ;
#ifdef V_243
memset ( V_410 , 0 , sizeof( V_410 ) ) ;
#endif
if ( V_423 && ! F_395 ( V_423 -> V_116 ) ) {
F_390 ( V_423 ) ;
F_392 ( V_423 ) ;
}
F_397 (nid) {
T_1 * V_8 = F_10 ( V_12 ) ;
F_390 ( V_8 ) ;
F_392 ( V_8 ) ;
}
F_398 (cpu) {
F_399 ( & F_400 ( V_424 , V_165 ) , 0 ) ;
#ifdef F_401
if ( F_402 ( V_165 ) )
F_403 ( V_165 , F_394 ( F_404 ( V_165 ) ) ) ;
#endif
}
return 0 ;
}
static T_12 void T_3
F_405 ( void )
{
F_396 ( NULL ) ;
F_406 () ;
F_407 () ;
}
void T_13 F_382 ( T_1 * V_8 , struct V_22 * V_22 )
{
F_389 () ;
if ( V_425 == V_426 ) {
F_405 () ;
} else {
#ifdef F_408
if ( V_22 )
F_409 ( V_22 ) ;
#endif
F_410 ( F_396 , V_8 , NULL ) ;
}
V_427 = F_353 () ;
if ( V_427 < ( V_128 * V_357 ) )
V_17 = 1 ;
else
V_17 = 0 ;
F_158 ( L_74
L_75 ,
V_248 ,
V_428 [ V_416 ] ,
V_17 ? L_76 : L_4 ,
V_427 ) ;
#ifdef V_243
F_158 ( L_77 , V_429 [ V_430 ] ) ;
#endif
}
static inline unsigned long F_411 ( unsigned long V_152 )
{
unsigned long V_133 = 1 ;
V_152 /= V_431 ;
while ( V_133 < V_152 )
V_133 <<= 1 ;
V_133 = F_78 ( V_133 , 4096UL ) ;
return F_156 ( V_133 , 4UL ) ;
}
static inline unsigned long F_411 ( unsigned long V_152 )
{
return 4096UL ;
}
static inline unsigned long F_412 ( unsigned long V_133 )
{
return F_413 ( ~ V_133 ) ;
}
static int F_414 ( unsigned long V_26 , unsigned long V_99 )
{
unsigned long V_11 ;
for ( V_11 = V_26 ; V_11 < V_99 ; V_11 ++ ) {
if ( ! F_26 ( V_11 ) || F_415 ( F_111 ( V_11 ) ) )
return 1 ;
}
return 0 ;
}
static void F_416 ( struct V_22 * V_22 )
{
unsigned long V_26 , V_11 , V_99 , V_432 ;
struct V_1 * V_1 ;
unsigned long V_433 ;
int V_434 ;
int V_435 ;
V_26 = V_22 -> V_27 ;
V_99 = F_113 ( V_22 ) ;
V_26 = F_417 ( V_26 , V_128 ) ;
V_434 = F_417 ( F_367 ( V_22 ) , V_128 ) >>
V_68 ;
V_434 = F_78 ( 2 , V_434 ) ;
V_435 = V_22 -> V_436 ;
if ( V_434 == V_435 )
return;
V_22 -> V_436 = V_434 ;
for ( V_11 = V_26 ; V_11 < V_99 ; V_11 += V_128 ) {
if ( ! F_12 ( V_11 , F_24 ( V_22 ) ) )
return;
if ( ! F_117 ( V_11 ) )
continue;
V_1 = F_111 ( V_11 ) ;
if ( F_183 ( V_1 ) != F_24 ( V_22 ) )
continue;
V_433 = F_95 ( V_1 ) ;
if ( V_434 > 0 ) {
V_432 = F_78 ( V_11 + V_128 , V_99 ) ;
if ( F_414 ( V_11 , V_432 ) )
continue;
if ( V_433 == V_157 ) {
V_434 -- ;
continue;
}
if ( V_433 == V_112 ) {
F_15 ( V_1 ,
V_157 ) ;
F_185 ( V_22 , V_1 ,
V_157 ) ;
V_434 -- ;
continue;
}
} else if ( ! V_435 ) {
break;
}
if ( V_433 == V_157 ) {
F_15 ( V_1 , V_112 ) ;
F_185 ( V_22 , V_1 , V_112 ) ;
}
}
}
void T_2 F_418 ( unsigned long V_133 , int V_12 , unsigned long V_22 ,
unsigned long V_26 , enum V_437 V_438 )
{
T_1 * V_8 = F_10 ( V_12 ) ;
unsigned long V_99 = V_26 + V_133 ;
unsigned long V_11 ;
struct V_22 * V_170 ;
unsigned long V_14 = 0 ;
if ( V_439 < V_99 - 1 )
V_439 = V_99 - 1 ;
V_170 = & V_8 -> V_96 [ V_22 ] ;
for ( V_11 = V_26 ; V_11 < V_99 ; V_11 ++ ) {
if ( V_438 == V_440 ) {
if ( ! F_419 ( V_11 ) )
continue;
if ( ! F_143 ( V_11 , V_12 ) )
continue;
if ( ! F_13 ( V_8 , V_11 , V_99 ,
& V_14 ) )
break;
}
if ( ! ( V_11 & ( V_128 - 1 ) ) ) {
struct V_1 * V_1 = F_111 ( V_11 ) ;
F_103 ( V_1 , V_11 , V_22 , V_12 ) ;
F_15 ( V_1 , V_112 ) ;
} else {
F_110 ( V_11 , V_22 , V_12 ) ;
}
}
}
static void T_2 F_420 ( struct V_22 * V_22 )
{
unsigned int V_43 , V_174 ;
F_215 (order, t) {
F_58 ( & V_22 -> V_69 [ V_43 ] . V_73 [ V_174 ] ) ;
V_22 -> V_69 [ V_43 ] . V_70 = 0 ;
}
}
static int F_421 ( struct V_22 * V_22 )
{
#ifdef F_422
int V_164 ;
V_164 = V_22 -> V_105 / 1024 ;
if ( V_164 * V_102 > 512 * 1024 )
V_164 = ( 512 * 1024 ) / V_102 ;
V_164 /= 4 ;
if ( V_164 < 1 )
V_164 = 1 ;
V_164 = F_423 ( V_164 + V_164 / 2 ) - 1 ;
return V_164 ;
#else
return 0 ;
#endif
}
static void F_424 ( struct V_80 * V_81 , unsigned long V_131 ,
unsigned long V_164 )
{
V_81 -> V_164 = 1 ;
F_46 () ;
V_81 -> V_131 = V_131 ;
F_46 () ;
V_81 -> V_164 = V_164 ;
}
static void F_425 ( struct V_166 * V_46 , unsigned long V_164 )
{
F_424 ( & V_46 -> V_81 , 6 * V_164 , F_156 ( 1UL , 1 * V_164 ) ) ;
}
static void F_426 ( struct V_166 * V_46 )
{
struct V_80 * V_81 ;
int V_3 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_81 = & V_46 -> V_81 ;
V_81 -> V_79 = 0 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_58 ( & V_81 -> V_89 [ V_3 ] ) ;
}
static void F_399 ( struct V_166 * V_46 , unsigned long V_164 )
{
F_426 ( V_46 ) ;
F_425 ( V_46 , V_164 ) ;
}
static void F_427 ( struct V_166 * V_46 ,
unsigned long V_131 )
{
unsigned long V_164 = F_156 ( 1UL , V_131 / 4 ) ;
if ( ( V_131 / 4 ) > ( V_15 * 8 ) )
V_164 = V_15 * 8 ;
F_424 ( & V_46 -> V_81 , V_131 , V_164 ) ;
}
static void F_428 ( struct V_22 * V_22 ,
struct V_166 * V_81 )
{
if ( V_441 )
F_427 ( V_81 ,
( V_22 -> V_105 /
V_441 ) ) ;
else
F_425 ( V_81 , F_421 ( V_22 ) ) ;
}
static void T_2 F_429 ( struct V_22 * V_22 , int V_165 )
{
struct V_166 * V_81 = F_200 ( V_22 -> V_168 , V_165 ) ;
F_426 ( V_81 ) ;
F_428 ( V_22 , V_81 ) ;
}
static void T_2 F_409 ( struct V_22 * V_22 )
{
int V_165 ;
V_22 -> V_168 = F_430 ( struct V_166 ) ;
F_398 (cpu)
F_429 ( V_22 , V_165 ) ;
}
void T_3 F_431 ( void )
{
struct V_22 * V_22 ;
F_202 (zone)
F_409 ( V_22 ) ;
}
static T_12 T_14
int F_432 ( struct V_22 * V_22 , unsigned long V_442 )
{
int V_44 ;
T_9 V_443 ;
V_22 -> F_411 =
F_411 ( V_442 ) ;
V_22 -> F_412 =
F_412 ( V_22 -> F_411 ) ;
V_443 = V_22 -> F_411
* sizeof( V_444 ) ;
if ( ! F_433 () ) {
V_22 -> V_445 = ( V_444 * )
F_434 (
V_443 , V_22 -> V_232 -> V_116 ) ;
} else {
V_22 -> V_445 = F_435 ( V_443 ) ;
}
if ( ! V_22 -> V_445 )
return - V_204 ;
for ( V_44 = 0 ; V_44 < V_22 -> F_411 ; ++ V_44 )
F_436 ( V_22 -> V_445 + V_44 ) ;
return 0 ;
}
static T_2 void F_437 ( struct V_22 * V_22 )
{
V_22 -> V_168 = & V_424 ;
if ( F_157 ( V_22 ) )
F_33 ( V_446 L_78 ,
V_22 -> V_29 , V_22 -> V_376 ,
F_421 ( V_22 ) ) ;
}
int T_2 F_438 ( struct V_22 * V_22 ,
unsigned long V_27 ,
unsigned long V_133 ,
enum V_437 V_438 )
{
struct V_447 * V_8 = V_22 -> V_232 ;
int V_23 ;
V_23 = F_432 ( V_22 , V_133 ) ;
if ( V_23 )
return V_23 ;
V_8 -> V_384 = F_303 ( V_22 ) + 1 ;
V_22 -> V_27 = V_27 ;
F_439 ( V_448 , L_79 ,
L_80 ,
V_8 -> V_116 ,
( unsigned long ) F_303 ( V_22 ) ,
V_27 , ( V_27 + V_133 ) ) ;
F_420 ( V_22 ) ;
return 0 ;
}
int T_2 F_141 ( unsigned long V_11 ,
struct V_109 * V_110 )
{
unsigned long V_26 , V_99 ;
int V_12 ;
if ( V_110 -> V_449 <= V_11 && V_11 < V_110 -> V_450 )
return V_110 -> V_451 ;
V_12 = F_440 ( V_11 , & V_26 , & V_99 ) ;
if ( V_12 != - 1 ) {
V_110 -> V_449 = V_26 ;
V_110 -> V_450 = V_99 ;
V_110 -> V_451 = V_12 ;
}
return V_12 ;
}
void T_3 F_441 ( int V_12 , unsigned long V_452 )
{
unsigned long V_26 , V_99 ;
int V_44 , V_453 ;
F_154 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_26 = F_78 ( V_26 , V_452 ) ;
V_99 = F_78 ( V_99 , V_452 ) ;
if ( V_26 < V_99 )
F_442 ( F_443 ( V_26 ) ,
( V_99 - V_26 ) << V_15 ,
V_453 ) ;
}
}
void T_3 F_444 ( int V_12 )
{
unsigned long V_26 , V_99 ;
int V_44 , V_453 ;
F_154 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_445 ( V_453 , V_26 , V_99 ) ;
}
void T_2 F_446 ( unsigned int V_12 ,
unsigned long * V_26 , unsigned long * V_99 )
{
unsigned long V_454 , V_455 ;
int V_44 ;
* V_26 = - 1UL ;
* V_99 = 0 ;
F_154 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_26 = F_78 ( * V_26 , V_454 ) ;
* V_99 = F_156 ( * V_99 , V_455 ) ;
}
if ( * V_26 == - 1UL )
* V_26 = 0 ;
}
static void T_3 F_447 ( void )
{
int V_456 ;
for ( V_456 = V_95 - 1 ; V_456 >= 0 ; V_456 -- ) {
if ( V_456 == V_457 )
continue;
if ( V_458 [ V_456 ] >
V_459 [ V_456 ] )
break;
}
F_76 ( V_456 == - 1 ) ;
V_460 = V_456 ;
}
static void T_2 F_448 ( int V_12 ,
unsigned long V_354 ,
unsigned long V_122 ,
unsigned long V_461 ,
unsigned long * V_27 ,
unsigned long * F_113 )
{
if ( V_462 [ V_12 ] ) {
if ( V_354 == V_457 ) {
* V_27 = V_462 [ V_12 ] ;
* F_113 = F_78 ( V_461 ,
V_458 [ V_460 ] ) ;
} else if ( * V_27 < V_462 [ V_12 ] &&
* F_113 > V_462 [ V_12 ] ) {
* F_113 = V_462 [ V_12 ] ;
} else if ( * V_27 >= V_462 [ V_12 ] )
* V_27 = * F_113 ;
}
}
static unsigned long T_2 F_449 ( int V_12 ,
unsigned long V_354 ,
unsigned long V_122 ,
unsigned long V_461 ,
unsigned long * V_463 )
{
unsigned long V_27 , F_113 ;
if ( ! V_122 && ! V_461 )
return 0 ;
V_27 = V_459 [ V_354 ] ;
F_113 = V_458 [ V_354 ] ;
F_448 ( V_12 , V_354 ,
V_122 , V_461 ,
& V_27 , & F_113 ) ;
if ( F_113 < V_122 || V_27 > V_461 )
return 0 ;
F_113 = F_78 ( F_113 , V_461 ) ;
V_27 = F_156 ( V_27 , V_122 ) ;
return F_113 - V_27 ;
}
unsigned long T_2 F_450 ( int V_12 ,
unsigned long V_464 ,
unsigned long V_465 )
{
unsigned long V_466 = V_465 - V_464 ;
unsigned long V_26 , V_99 ;
int V_44 ;
F_154 (i, nid, &start_pfn, &end_pfn, NULL) {
V_26 = F_451 ( V_26 , V_464 , V_465 ) ;
V_99 = F_451 ( V_99 , V_464 , V_465 ) ;
V_466 -= V_99 - V_26 ;
}
return V_466 ;
}
unsigned long T_3 F_452 ( unsigned long V_26 ,
unsigned long V_99 )
{
return F_450 ( V_409 , V_26 , V_99 ) ;
}
static unsigned long T_2 F_453 ( int V_12 ,
unsigned long V_354 ,
unsigned long V_122 ,
unsigned long V_461 ,
unsigned long * V_463 )
{
unsigned long V_467 = V_459 [ V_354 ] ;
unsigned long V_468 = V_458 [ V_354 ] ;
unsigned long V_27 , F_113 ;
if ( ! V_122 && ! V_461 )
return 0 ;
V_27 = F_451 ( V_122 , V_467 , V_468 ) ;
F_113 = F_451 ( V_461 , V_467 , V_468 ) ;
F_448 ( V_12 , V_354 ,
V_122 , V_461 ,
& V_27 , & F_113 ) ;
return F_450 ( V_12 , V_27 , F_113 ) ;
}
static inline unsigned long T_2 F_449 ( int V_12 ,
unsigned long V_354 ,
unsigned long V_122 ,
unsigned long V_461 ,
unsigned long * V_469 )
{
return V_469 [ V_354 ] ;
}
static inline unsigned long T_2 F_453 ( int V_12 ,
unsigned long V_354 ,
unsigned long V_122 ,
unsigned long V_461 ,
unsigned long * V_470 )
{
if ( ! V_470 )
return 0 ;
return V_470 [ V_354 ] ;
}
static void T_2 F_454 ( struct V_447 * V_8 ,
unsigned long V_122 ,
unsigned long V_461 ,
unsigned long * V_469 ,
unsigned long * V_470 )
{
unsigned long V_471 = 0 , V_472 = 0 ;
enum V_354 V_44 ;
for ( V_44 = 0 ; V_44 < V_95 ; V_44 ++ ) {
struct V_22 * V_22 = V_8 -> V_96 + V_44 ;
unsigned long V_133 , V_473 ;
V_133 = F_449 ( V_8 -> V_116 , V_44 ,
V_122 ,
V_461 ,
V_469 ) ;
V_473 = V_133 - F_453 ( V_8 -> V_116 , V_44 ,
V_122 , V_461 ,
V_470 ) ;
V_22 -> V_28 = V_133 ;
V_22 -> V_376 = V_473 ;
V_472 += V_133 ;
V_471 += V_473 ;
}
V_8 -> V_474 = V_472 ;
V_8 -> V_475 = V_471 ;
F_33 ( V_446 L_81 , V_8 -> V_116 ,
V_471 ) ;
}
static unsigned long T_3 F_455 ( unsigned long V_27 , unsigned long V_476 )
{
unsigned long V_477 ;
V_476 += V_27 & ( V_128 - 1 ) ;
V_477 = F_417 ( V_476 , V_128 ) ;
V_477 = V_477 >> V_68 ;
V_477 *= V_478 ;
V_477 = F_417 ( V_477 , 8 * sizeof( unsigned long ) ) ;
return V_477 / 8 ;
}
static void T_3 F_456 ( struct V_447 * V_8 ,
struct V_22 * V_22 ,
unsigned long V_27 ,
unsigned long V_476 )
{
unsigned long V_477 = F_455 ( V_27 , V_476 ) ;
V_22 -> V_479 = NULL ;
if ( V_477 )
V_22 -> V_479 =
F_434 ( V_477 ,
V_8 -> V_116 ) ;
}
static inline void F_456 ( struct V_447 * V_8 , struct V_22 * V_22 ,
unsigned long V_27 , unsigned long V_476 ) {}
void T_15 F_457 ( void )
{
unsigned int V_43 ;
if ( V_68 )
return;
if ( V_480 > V_15 )
V_43 = V_481 ;
else
V_43 = V_53 - 1 ;
V_68 = V_43 ;
}
void T_15 F_457 ( void )
{
}
static unsigned long T_15 F_458 ( unsigned long V_28 ,
unsigned long V_376 )
{
unsigned long V_152 = V_28 ;
if ( V_28 > V_376 + ( V_376 >> 4 ) &&
F_101 ( V_482 ) )
V_152 = V_376 ;
return F_344 ( V_152 * sizeof( struct V_1 ) ) >> V_15 ;
}
static void T_15 F_459 ( struct V_447 * V_8 )
{
enum V_354 V_411 ;
int V_12 = V_8 -> V_116 ;
unsigned long V_27 = V_8 -> V_122 ;
int V_23 ;
F_460 ( V_8 ) ;
#ifdef F_461
F_462 ( & V_8 -> V_483 ) ;
V_8 -> V_484 = 0 ;
V_8 -> V_485 = V_35 ;
#endif
F_436 ( & V_8 -> V_486 ) ;
F_436 ( & V_8 -> V_487 ) ;
F_463 ( V_8 ) ;
for ( V_411 = 0 ; V_411 < V_95 ; V_411 ++ ) {
struct V_22 * V_22 = V_8 -> V_96 + V_411 ;
unsigned long V_133 , V_488 , V_489 , V_490 ;
V_133 = V_22 -> V_28 ;
V_488 = V_489 = V_22 -> V_376 ;
V_490 = F_458 ( V_133 , V_488 ) ;
if ( ! F_107 ( V_411 ) ) {
if ( V_489 >= V_490 ) {
V_489 -= V_490 ;
if ( V_490 )
F_33 ( V_446
L_82 ,
V_429 [ V_411 ] , V_490 ) ;
} else
F_33 ( V_390
L_83 ,
V_429 [ V_411 ] , V_490 , V_489 ) ;
}
if ( V_411 == 0 && V_489 > V_491 ) {
V_489 -= V_491 ;
F_33 ( V_446 L_84 ,
V_429 [ 0 ] , V_491 ) ;
}
if ( ! F_107 ( V_411 ) )
V_492 += V_489 ;
else if ( V_492 > V_490 * 2 )
V_492 -= V_490 ;
V_493 += V_489 ;
V_22 -> V_105 = F_107 ( V_411 ) ? V_488 : V_489 ;
#ifdef V_243
V_22 -> V_108 = V_12 ;
V_22 -> V_494 = ( V_489 * V_495 )
/ 100 ;
V_22 -> V_496 = ( V_489 * V_497 ) / 100 ;
#endif
V_22 -> V_29 = V_429 [ V_411 ] ;
F_462 ( & V_22 -> V_85 ) ;
F_462 ( & V_22 -> V_498 ) ;
F_464 ( V_22 ) ;
V_22 -> V_232 = V_8 ;
F_437 ( V_22 ) ;
F_268 ( V_22 , V_185 , V_22 -> V_105 ) ;
F_465 ( & V_22 -> V_499 ) ;
if ( ! V_133 )
continue;
F_457 () ;
F_456 ( V_8 , V_22 , V_27 , V_133 ) ;
V_23 = F_438 ( V_22 , V_27 ,
V_133 , V_440 ) ;
F_153 ( V_23 ) ;
F_466 ( V_133 , V_12 , V_411 , V_27 ) ;
V_27 += V_133 ;
}
}
static void T_14 F_467 ( struct V_447 * V_8 )
{
if ( ! V_8 -> V_474 )
return;
#ifdef F_468
if ( ! V_8 -> V_500 ) {
unsigned long V_133 , V_97 , V_98 ;
struct V_1 * V_501 ;
V_97 = V_8 -> V_122 & ~ ( V_111 - 1 ) ;
V_98 = F_14 ( V_8 ) ;
V_98 = F_469 ( V_98 , V_111 ) ;
V_133 = ( V_98 - V_97 ) * sizeof( struct V_1 ) ;
V_501 = F_470 ( V_8 -> V_116 , V_133 ) ;
if ( ! V_501 )
V_501 = F_434 ( V_133 ,
V_8 -> V_116 ) ;
V_8 -> V_500 = V_501 + ( V_8 -> V_122 - V_97 ) ;
}
#ifndef F_471
if ( V_8 == F_10 ( 0 ) ) {
V_502 = F_10 ( 0 ) -> V_500 ;
#ifdef F_472
if ( F_19 ( V_502 ) != V_8 -> V_122 )
V_502 -= ( V_8 -> V_122 - V_503 ) ;
#endif
}
#endif
#endif
}
void T_15 F_473 ( int V_12 , unsigned long * V_469 ,
unsigned long V_122 , unsigned long * V_470 )
{
T_1 * V_8 = F_10 ( V_12 ) ;
unsigned long V_26 = 0 ;
unsigned long V_99 = 0 ;
F_4 ( V_8 -> V_384 || V_8 -> V_206 ) ;
F_8 ( V_8 ) ;
V_8 -> V_116 = V_12 ;
V_8 -> V_122 = V_122 ;
#ifdef F_472
F_446 ( V_12 , & V_26 , & V_99 ) ;
F_158 ( L_85 , V_12 ,
( V_504 ) V_26 << V_15 ,
V_99 ? ( ( V_504 ) V_99 << V_15 ) - 1 : 0 ) ;
#endif
F_454 ( V_8 , V_26 , V_99 ,
V_469 , V_470 ) ;
F_467 ( V_8 ) ;
#ifdef F_468
F_33 ( V_446 L_86 ,
V_12 , ( unsigned long ) V_8 ,
( unsigned long ) V_8 -> V_500 ) ;
#endif
F_459 ( V_8 ) ;
}
void T_3 F_474 ( void )
{
unsigned int V_505 ;
V_505 = F_475 ( V_506 . V_507 , V_409 ) ;
V_508 = V_505 + 1 ;
}
unsigned long T_3 F_476 ( void )
{
unsigned long V_509 = 0 , V_450 = 0 ;
unsigned long V_97 , V_98 , V_510 ;
int V_451 = - 1 ;
int V_44 , V_12 ;
F_154 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_97 || V_451 < 0 || V_451 == V_12 ) {
V_451 = V_12 ;
V_450 = V_98 ;
continue;
}
V_510 = ~ ( ( 1 << F_477 ( V_97 ) ) - 1 ) ;
while ( V_510 && V_450 <= ( V_97 & ( V_510 << 1 ) ) )
V_510 <<= 1 ;
V_509 |= V_510 ;
}
return ~ V_509 + 1 ;
}
static unsigned long T_3 F_478 ( int V_12 )
{
unsigned long V_511 = V_10 ;
unsigned long V_26 ;
int V_44 ;
F_154 (i, nid, &start_pfn, NULL, NULL)
V_511 = F_78 ( V_511 , V_26 ) ;
if ( V_511 == V_10 ) {
F_33 ( V_390
L_87 , V_12 ) ;
return 0 ;
}
return V_511 ;
}
unsigned long T_3 F_479 ( void )
{
return F_478 ( V_409 ) ;
}
static unsigned long T_3 F_480 ( void )
{
unsigned long V_472 = 0 ;
unsigned long V_26 , V_99 ;
int V_44 , V_12 ;
F_154 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_152 = V_99 - V_26 ;
V_472 += V_152 ;
if ( V_152 )
F_481 ( V_12 , V_127 ) ;
}
return V_472 ;
}
static void T_3 F_482 ( void )
{
int V_44 , V_12 ;
unsigned long V_512 ;
unsigned long V_513 , V_514 ;
T_7 V_515 = V_225 [ V_127 ] ;
unsigned long V_472 = F_480 () ;
int V_516 = F_483 ( V_225 [ V_127 ] ) ;
struct V_517 * V_518 ;
F_447 () ;
if ( F_484 () ) {
F_485 (memory, r) {
if ( ! F_486 ( V_518 ) )
continue;
V_12 = V_518 -> V_12 ;
V_512 = F_115 ( V_518 -> V_519 ) ;
V_462 [ V_12 ] = V_462 [ V_12 ] ?
F_78 ( V_512 , V_462 [ V_12 ] ) :
V_512 ;
}
goto V_520;
}
if ( V_521 ) {
unsigned long V_522 ;
V_521 =
F_417 ( V_521 , V_111 ) ;
V_522 = V_472 - V_521 ;
V_523 = F_156 ( V_523 , V_522 ) ;
}
if ( ! V_523 )
goto V_36;
V_512 = V_459 [ V_460 ] ;
V_524:
V_513 = V_523 / V_516 ;
F_163 (nid, N_MEMORY) {
unsigned long V_26 , V_99 ;
if ( V_523 < V_513 )
V_513 = V_523 / V_516 ;
V_514 = V_513 ;
F_154 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_525 ;
V_26 = F_156 ( V_26 , V_462 [ V_12 ] ) ;
if ( V_26 >= V_99 )
continue;
if ( V_26 < V_512 ) {
unsigned long V_526 ;
V_526 = F_78 ( V_99 , V_512 )
- V_26 ;
V_514 -= F_78 ( V_526 ,
V_514 ) ;
V_523 -= F_78 ( V_526 ,
V_523 ) ;
if ( V_99 <= V_512 ) {
V_462 [ V_12 ] = V_99 ;
continue;
}
V_26 = V_512 ;
}
V_525 = V_99 - V_26 ;
if ( V_525 > V_514 )
V_525 = V_514 ;
V_462 [ V_12 ] = V_26 + V_525 ;
V_523 -= F_78 ( V_523 ,
V_525 ) ;
V_514 -= V_525 ;
if ( ! V_514 )
break;
}
}
V_516 -- ;
if ( V_516 && V_523 > V_516 )
goto V_524;
V_520:
for ( V_12 = 0 ; V_12 < V_409 ; V_12 ++ )
V_462 [ V_12 ] =
F_417 ( V_462 [ V_12 ] , V_111 ) ;
V_36:
V_225 [ V_127 ] = V_515 ;
}
static void F_487 ( T_1 * V_8 , int V_12 )
{
enum V_354 V_354 ;
if ( V_127 == V_527 )
return;
for ( V_354 = 0 ; V_354 <= V_457 - 1 ; V_354 ++ ) {
struct V_22 * V_22 = & V_8 -> V_96 [ V_354 ] ;
if ( F_157 ( V_22 ) ) {
F_481 ( V_12 , V_528 ) ;
if ( V_527 != V_528 &&
V_354 <= V_278 )
F_481 ( V_12 , V_527 ) ;
break;
}
}
}
void T_3 F_488 ( unsigned long * V_173 )
{
unsigned long V_26 , V_99 ;
int V_44 , V_12 ;
memset ( V_459 , 0 ,
sizeof( V_459 ) ) ;
memset ( V_458 , 0 ,
sizeof( V_458 ) ) ;
V_459 [ 0 ] = F_479 () ;
V_458 [ 0 ] = V_173 [ 0 ] ;
for ( V_44 = 1 ; V_44 < V_95 ; V_44 ++ ) {
if ( V_44 == V_457 )
continue;
V_459 [ V_44 ] =
V_458 [ V_44 - 1 ] ;
V_458 [ V_44 ] =
F_156 ( V_173 [ V_44 ] , V_459 [ V_44 ] ) ;
}
V_459 [ V_457 ] = 0 ;
V_458 [ V_457 ] = 0 ;
memset ( V_462 , 0 , sizeof( V_462 ) ) ;
F_482 () ;
F_158 ( L_88 ) ;
for ( V_44 = 0 ; V_44 < V_95 ; V_44 ++ ) {
if ( V_44 == V_457 )
continue;
F_158 ( L_89 , V_429 [ V_44 ] ) ;
if ( V_459 [ V_44 ] ==
V_458 [ V_44 ] )
F_489 ( L_90 ) ;
else
F_489 ( L_91 ,
( V_504 ) V_459 [ V_44 ]
<< V_15 ,
( ( V_504 ) V_458 [ V_44 ]
<< V_15 ) - 1 ) ;
}
F_158 ( L_92 ) ;
for ( V_44 = 0 ; V_44 < V_409 ; V_44 ++ ) {
if ( V_462 [ V_44 ] )
F_158 ( L_93 , V_44 ,
( V_504 ) V_462 [ V_44 ] << V_15 ) ;
}
F_158 ( L_94 ) ;
F_154 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_158 ( L_95 , V_12 ,
( V_504 ) V_26 << V_15 ,
( ( V_504 ) V_99 << V_15 ) - 1 ) ;
F_490 () ;
F_474 () ;
F_397 (nid) {
T_1 * V_8 = F_10 ( V_12 ) ;
F_473 ( V_12 , NULL ,
F_478 ( V_12 ) , NULL ) ;
if ( V_8 -> V_475 )
F_481 ( V_12 , V_127 ) ;
F_487 ( V_8 , V_12 ) ;
}
}
static int T_3 F_491 ( char * V_46 , unsigned long * V_529 )
{
unsigned long long V_530 ;
if ( ! V_46 )
return - V_49 ;
V_530 = F_492 ( V_46 , & V_46 ) ;
* V_529 = V_530 >> V_15 ;
F_4 ( ( V_530 >> V_15 ) > V_10 ) ;
return 0 ;
}
static int T_3 F_493 ( char * V_46 )
{
return F_491 ( V_46 , & V_523 ) ;
}
static int T_3 F_494 ( char * V_46 )
{
return F_491 ( V_46 , & V_521 ) ;
}
void F_168 ( struct V_1 * V_1 , long V_79 )
{
F_89 ( & V_531 ) ;
F_27 ( V_1 ) -> V_105 += V_79 ;
V_345 += V_79 ;
#ifdef F_361
if ( F_126 ( V_1 ) )
V_351 += V_79 ;
#endif
F_97 ( & V_531 ) ;
}
unsigned long F_495 ( void * V_97 , void * V_98 , int V_532 , char * V_385 )
{
void * V_414 ;
unsigned long V_152 = 0 ;
V_97 = ( void * ) F_344 ( ( unsigned long ) V_97 ) ;
V_98 = ( void * ) ( ( unsigned long ) V_98 & V_533 ) ;
for ( V_414 = V_97 ; V_414 < V_98 ; V_414 += V_102 , V_152 ++ ) {
if ( ( unsigned int ) V_532 <= 0xFF )
memset ( V_414 , V_532 , V_102 ) ;
F_496 ( F_228 ( V_414 ) ) ;
}
if ( V_152 && V_385 )
F_158 ( L_96 ,
V_385 , V_152 << ( V_15 - 10 ) , V_97 , V_98 ) ;
return V_152 ;
}
void F_497 ( struct V_1 * V_1 )
{
F_498 ( V_1 ) ;
V_345 ++ ;
F_27 ( V_1 ) -> V_105 ++ ;
V_351 ++ ;
}
void T_3 F_499 ( const char * V_189 )
{
unsigned long V_534 , V_535 , V_536 , V_537 , V_538 ;
unsigned long V_539 , V_540 ;
V_534 = F_500 () ;
V_535 = V_541 - V_542 ;
V_536 = V_543 - V_544 ;
V_537 = V_545 - V_546 ;
V_538 = V_547 - V_548 ;
V_540 = V_549 - V_550 ;
V_539 = V_551 - V_552 ;
#define F_501 ( V_97 , V_98 , V_133 , V_414 , T_16 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_501 ( V_550 , V_549 , V_540 ,
V_552 , V_539 ) ;
F_501 ( V_542 , V_541 , V_535 , V_552 , V_539 ) ;
F_501 ( V_544 , V_543 , V_536 , V_550 , V_540 ) ;
F_501 ( V_542 , V_541 , V_535 , V_546 , V_537 ) ;
F_501 ( V_544 , V_543 , V_536 , V_546 , V_537 ) ;
#undef F_501
F_158 ( L_97
L_98
L_99
#ifdef F_361
L_100
#endif
L_101 ,
F_502 () << ( V_15 - 10 ) , V_534 << ( V_15 - 10 ) ,
V_535 >> 10 , V_536 >> 10 , V_537 >> 10 ,
( V_540 + V_539 ) >> 10 , V_538 >> 10 ,
( V_534 - V_345 - V_553 ) << ( V_15 - 10 ) ,
V_553 << ( V_15 - 10 ) ,
#ifdef F_361
V_351 << ( V_15 - 10 ) ,
#endif
V_189 ? L_102 : L_103 , V_189 ? V_189 : L_103 ) ;
}
void T_3 F_503 ( unsigned long V_554 )
{
V_491 = V_554 ;
}
void T_3 F_504 ( unsigned long * V_469 )
{
F_473 ( 0 , V_469 ,
F_505 ( V_555 ) >> V_15 , NULL ) ;
}
static int F_506 ( struct V_556 * V_423 ,
unsigned long V_557 , void * V_558 )
{
int V_165 = ( unsigned long ) V_558 ;
if ( V_557 == V_559 || V_557 == V_560 ) {
F_507 ( V_165 ) ;
F_201 ( V_165 ) ;
F_508 ( V_165 ) ;
F_509 ( V_165 ) ;
}
return V_561 ;
}
void T_3 F_510 ( void )
{
F_511 ( F_506 , 0 ) ;
}
static void F_512 ( void )
{
struct V_447 * V_8 ;
unsigned long V_562 = 0 ;
enum V_354 V_44 , V_411 ;
F_513 (pgdat) {
for ( V_44 = 0 ; V_44 < V_95 ; V_44 ++ ) {
struct V_22 * V_22 = V_8 -> V_96 + V_44 ;
long F_156 = 0 ;
for ( V_411 = V_44 ; V_411 < V_95 ; V_411 ++ ) {
if ( V_22 -> V_213 [ V_411 ] > F_156 )
F_156 = V_22 -> V_213 [ V_411 ] ;
}
F_156 += F_269 ( V_22 ) ;
if ( F_156 > V_22 -> V_105 )
F_156 = V_22 -> V_105 ;
V_562 += F_156 ;
V_22 -> V_563 = F_156 ;
}
}
V_563 = V_562 ;
V_564 = V_562 ;
}
static void F_514 ( void )
{
struct V_447 * V_8 ;
enum V_354 V_411 , V_565 ;
F_513 (pgdat) {
for ( V_411 = 0 ; V_411 < V_95 ; V_411 ++ ) {
struct V_22 * V_22 = V_8 -> V_96 + V_411 ;
unsigned long V_105 = V_22 -> V_105 ;
V_22 -> V_213 [ V_411 ] = 0 ;
V_565 = V_411 ;
while ( V_565 ) {
struct V_22 * V_566 ;
V_565 -- ;
if ( V_567 [ V_565 ] < 1 )
V_567 [ V_565 ] = 1 ;
V_566 = V_8 -> V_96 + V_565 ;
V_566 -> V_213 [ V_411 ] = V_105 /
V_567 [ V_565 ] ;
V_105 += V_566 -> V_105 ;
}
}
}
F_512 () ;
}
static void F_515 ( void )
{
unsigned long V_568 = V_569 >> ( V_15 - 10 ) ;
unsigned long V_570 = 0 ;
struct V_22 * V_22 ;
unsigned long V_59 ;
F_516 (zone) {
if ( ! F_517 ( V_22 ) )
V_570 += V_22 -> V_105 ;
}
F_516 (zone) {
V_504 V_359 ;
F_212 ( & V_22 -> V_85 , V_59 ) ;
V_359 = ( V_504 ) V_568 * V_22 -> V_105 ;
F_518 ( V_359 , V_570 ) ;
if ( F_517 ( V_22 ) ) {
unsigned long V_571 ;
V_571 = V_22 -> V_105 / 1024 ;
V_571 = F_451 ( V_571 , V_572 , 128UL ) ;
V_22 -> V_178 [ V_573 ] = V_571 ;
} else {
V_22 -> V_178 [ V_573 ] = V_359 ;
}
V_22 -> V_178 [ V_574 ] = F_367 ( V_22 ) + ( V_359 >> 2 ) ;
V_22 -> V_178 [ V_575 ] = F_367 ( V_22 ) + ( V_359 >> 1 ) ;
F_91 ( V_22 , V_185 ,
F_269 ( V_22 ) - F_231 ( V_22 ) -
F_236 ( & V_22 -> V_186 [ V_185 ] ) ) ;
F_416 ( V_22 ) ;
F_218 ( & V_22 -> V_85 , V_59 ) ;
}
F_512 () ;
}
void F_519 ( void )
{
F_380 ( & V_402 ) ;
F_515 () ;
F_288 ( & V_402 ) ;
}
static void T_2 F_520 ( struct V_22 * V_22 )
{
unsigned int V_576 , V_577 ;
V_576 = V_22 -> V_105 >> ( 30 - V_15 ) ;
if ( V_576 )
V_577 = F_521 ( 10 * V_576 ) ;
else
V_577 = 1 ;
V_22 -> V_578 = V_577 ;
}
static void T_2 F_522 ( void )
{
struct V_22 * V_22 ;
F_516 (zone)
F_520 ( V_22 ) ;
}
int T_2 F_523 ( void )
{
unsigned long V_579 ;
int V_580 ;
V_579 = F_352 () * ( V_102 >> 10 ) ;
V_580 = F_521 ( V_579 * 16 ) ;
if ( V_580 > V_581 ) {
V_569 = V_580 ;
if ( V_569 < 128 )
V_569 = 128 ;
if ( V_569 > 65536 )
V_569 = 65536 ;
} else {
F_282 ( L_104 ,
V_580 , V_581 ) ;
}
F_519 () ;
F_524 () ;
F_514 () ;
F_522 () ;
return 0 ;
}
int F_525 ( struct V_393 * V_394 , int V_395 ,
void T_10 * V_396 , T_9 * V_397 , T_11 * V_398 )
{
int V_582 ;
V_582 = F_526 ( V_394 , V_395 , V_396 , V_397 , V_398 ) ;
if ( V_582 )
return V_582 ;
if ( V_395 ) {
V_581 = V_569 ;
F_519 () ;
}
return 0 ;
}
int F_527 ( struct V_393 * V_394 , int V_395 ,
void T_10 * V_396 , T_9 * V_397 , T_11 * V_398 )
{
struct V_22 * V_22 ;
int V_582 ;
V_582 = F_526 ( V_394 , V_395 , V_396 , V_397 , V_398 ) ;
if ( V_582 )
return V_582 ;
F_516 (zone)
V_22 -> V_494 = ( V_22 -> V_105 *
V_495 ) / 100 ;
return 0 ;
}
int F_528 ( struct V_393 * V_394 , int V_395 ,
void T_10 * V_396 , T_9 * V_397 , T_11 * V_398 )
{
struct V_22 * V_22 ;
int V_582 ;
V_582 = F_526 ( V_394 , V_395 , V_396 , V_397 , V_398 ) ;
if ( V_582 )
return V_582 ;
F_516 (zone)
V_22 -> V_496 = ( V_22 -> V_105 *
V_497 ) / 100 ;
return 0 ;
}
int F_529 ( struct V_393 * V_394 , int V_395 ,
void T_10 * V_396 , T_9 * V_397 , T_11 * V_398 )
{
F_526 ( V_394 , V_395 , V_396 , V_397 , V_398 ) ;
F_514 () ;
return 0 ;
}
int F_530 ( struct V_393 * V_394 , int V_395 ,
void T_10 * V_396 , T_9 * V_397 , T_11 * V_398 )
{
struct V_22 * V_22 ;
int V_583 ;
int V_23 ;
F_380 ( & V_584 ) ;
V_583 = V_441 ;
V_23 = F_526 ( V_394 , V_395 , V_396 , V_397 , V_398 ) ;
if ( ! V_395 || V_23 < 0 )
goto V_36;
if ( V_441 &&
V_441 < V_585 ) {
V_441 = V_583 ;
V_23 = - V_49 ;
goto V_36;
}
if ( V_441 == V_583 )
goto V_36;
F_202 (zone) {
unsigned int V_165 ;
F_398 (cpu)
F_428 ( V_22 ,
F_200 ( V_22 -> V_168 , V_165 ) ) ;
}
V_36:
F_288 ( & V_584 ) ;
return V_23 ;
}
static int T_3 F_531 ( char * V_189 )
{
if ( ! V_189 )
return 0 ;
V_586 = F_532 ( V_189 , & V_189 , 0 ) ;
return 1 ;
}
void * T_3 F_533 ( const char * V_587 ,
unsigned long V_588 ,
unsigned long V_589 ,
int V_590 ,
int V_59 ,
unsigned int * V_591 ,
unsigned int * V_592 ,
unsigned long V_593 ,
unsigned long V_594 )
{
unsigned long long F_156 = V_594 ;
unsigned long V_595 , V_133 ;
void * V_394 = NULL ;
if ( ! V_589 ) {
V_589 = V_492 ;
if ( V_15 < 20 )
V_589 = F_534 ( V_589 , ( 1 << 20 ) / V_102 ) ;
if ( V_590 > V_15 )
V_589 >>= ( V_590 - V_15 ) ;
else
V_589 <<= ( V_15 - V_590 ) ;
if ( F_16 ( V_59 & V_596 ) ) {
F_4 ( ! ( V_59 & V_597 ) ) ;
if ( ! ( V_589 >> * V_591 ) ) {
V_589 = 1UL << * V_591 ;
F_153 ( ! V_589 ) ;
}
} else if ( F_16 ( ( V_589 * V_588 ) < V_102 ) )
V_589 = V_102 / V_588 ;
}
V_589 = F_535 ( V_589 ) ;
if ( F_156 == 0 ) {
F_156 = ( ( unsigned long long ) V_493 << V_15 ) >> 4 ;
F_518 ( F_156 , V_588 ) ;
}
F_156 = F_78 ( F_156 , 0x80000000ULL ) ;
if ( V_589 < V_593 )
V_589 = V_593 ;
if ( V_589 > F_156 )
V_589 = F_156 ;
V_595 = F_536 ( V_589 ) ;
do {
V_133 = V_588 << V_595 ;
if ( V_59 & V_597 )
V_394 = F_537 ( V_133 , 0 ) ;
else if ( V_586 )
V_394 = F_538 ( V_133 , V_598 , V_599 ) ;
else {
if ( F_347 ( V_133 ) < V_53 ) {
V_394 = F_346 ( V_133 , V_598 ) ;
F_539 ( V_394 , V_133 , 1 , V_598 ) ;
}
}
} while ( ! V_394 && V_133 > V_102 && -- V_595 );
if ( ! V_394 )
F_540 ( L_105 , V_587 ) ;
F_33 ( V_56 L_106 ,
V_587 ,
( 1UL << V_595 ) ,
F_536 ( V_133 ) - V_15 ,
V_133 ) ;
if ( V_591 )
* V_591 = V_595 ;
if ( V_592 )
* V_592 = ( 1 << V_595 ) - 1 ;
return V_394 ;
}
static inline unsigned long * F_541 ( struct V_22 * V_22 ,
unsigned long V_11 )
{
#ifdef V_482
return F_542 ( V_11 ) -> V_479 ;
#else
return V_22 -> V_479 ;
#endif
}
static inline int F_543 ( struct V_22 * V_22 , unsigned long V_11 )
{
#ifdef V_482
V_11 &= ( V_16 - 1 ) ;
return ( V_11 >> V_68 ) * V_478 ;
#else
V_11 = V_11 - F_544 ( V_22 -> V_27 , V_128 ) ;
return ( V_11 >> V_68 ) * V_478 ;
#endif
}
unsigned long F_545 ( struct V_1 * V_1 , unsigned long V_11 ,
unsigned long V_600 ,
unsigned long V_510 )
{
struct V_22 * V_22 ;
unsigned long * V_601 ;
unsigned long V_602 , V_603 ;
unsigned long V_604 ;
V_22 = F_27 ( V_1 ) ;
V_601 = F_541 ( V_22 , V_11 ) ;
V_602 = F_543 ( V_22 , V_11 ) ;
V_603 = V_602 / V_605 ;
V_602 &= ( V_605 - 1 ) ;
V_604 = V_601 [ V_603 ] ;
V_602 += V_600 ;
return ( V_604 >> ( V_605 - V_602 - 1 ) ) & V_510 ;
}
void F_546 ( struct V_1 * V_1 , unsigned long V_59 ,
unsigned long V_11 ,
unsigned long V_600 ,
unsigned long V_510 )
{
struct V_22 * V_22 ;
unsigned long * V_601 ;
unsigned long V_602 , V_603 ;
unsigned long V_606 , V_604 ;
F_276 ( V_478 != 4 ) ;
V_22 = F_27 ( V_1 ) ;
V_601 = F_541 ( V_22 , V_11 ) ;
V_602 = F_543 ( V_22 , V_11 ) ;
V_603 = V_602 / V_605 ;
V_602 &= ( V_605 - 1 ) ;
F_72 ( ! F_21 ( V_22 , V_11 ) , V_1 ) ;
V_602 += V_600 ;
V_510 <<= ( V_605 - V_602 - 1 ) ;
V_59 <<= ( V_605 - V_602 - 1 ) ;
V_604 = F_198 ( V_601 [ V_603 ] ) ;
for (; ; ) {
V_606 = F_547 ( & V_601 [ V_603 ] , V_604 , ( V_604 & ~ V_510 ) | V_59 ) ;
if ( V_604 == V_606 )
break;
V_604 = V_606 ;
}
}
bool F_548 ( struct V_22 * V_22 , struct V_1 * V_1 , int V_79 ,
bool V_607 )
{
unsigned long V_11 , V_608 , V_609 ;
int V_90 ;
if ( F_303 ( V_22 ) == V_457 )
return false ;
V_90 = F_95 ( V_1 ) ;
if ( V_90 == V_112 || F_196 ( V_90 ) )
return false ;
V_11 = F_19 ( V_1 ) ;
for ( V_609 = 0 , V_608 = 0 ; V_608 < V_128 ; V_608 ++ ) {
unsigned long V_610 = V_11 + V_608 ;
if ( ! F_26 ( V_610 ) )
continue;
V_1 = F_111 ( V_610 ) ;
if ( F_549 ( V_1 ) ) {
V_608 = F_534 ( V_608 + 1 , 1 << F_40 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_85 ( & V_1 -> V_76 ) ) {
if ( F_74 ( V_1 ) )
V_608 += ( 1 << F_70 ( V_1 ) ) - 1 ;
continue;
}
if ( V_607 && F_30 ( V_1 ) )
continue;
if ( ! F_550 ( V_1 ) )
V_609 ++ ;
if ( V_609 > V_79 )
return true ;
}
return false ;
}
bool F_551 ( struct V_1 * V_1 )
{
struct V_22 * V_22 ;
unsigned long V_11 ;
if ( ! F_395 ( F_183 ( V_1 ) ) )
return false ;
V_22 = F_27 ( V_1 ) ;
V_11 = F_19 ( V_1 ) ;
if ( ! F_21 ( V_22 , V_11 ) )
return false ;
return ! F_548 ( V_22 , V_1 , 0 , true ) ;
}
static unsigned long F_552 ( unsigned long V_11 )
{
return V_11 & ~ ( F_553 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_554 ( unsigned long V_11 )
{
return F_469 ( V_11 , F_553 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_555 ( struct V_611 * V_612 ,
unsigned long V_97 , unsigned long V_98 )
{
unsigned long V_613 ;
unsigned long V_11 = V_97 ;
unsigned int V_614 = 0 ;
int V_23 = 0 ;
F_556 () ;
while ( V_11 < V_98 || ! F_92 ( & V_612 -> V_615 ) ) {
if ( F_557 ( V_39 ) ) {
V_23 = - V_616 ;
break;
}
if ( F_92 ( & V_612 -> V_615 ) ) {
V_612 -> V_617 = 0 ;
V_11 = F_558 ( V_612 , V_11 , V_98 ) ;
if ( ! V_11 ) {
V_23 = - V_616 ;
break;
}
V_614 = 0 ;
} else if ( ++ V_614 == 5 ) {
V_23 = V_23 < 0 ? V_23 : - V_618 ;
break;
}
V_613 = F_559 ( V_612 -> V_22 ,
& V_612 -> V_615 ) ;
V_612 -> V_617 -= V_613 ;
V_23 = F_560 ( & V_612 -> V_615 , V_619 ,
NULL , 0 , V_612 -> V_197 , V_620 ) ;
}
if ( V_23 < 0 ) {
F_561 ( & V_612 -> V_615 ) ;
return V_23 ;
}
return 0 ;
}
int F_562 ( unsigned long V_97 , unsigned long V_98 ,
unsigned V_3 )
{
unsigned long V_621 , V_622 ;
int V_23 = 0 , V_43 ;
struct V_611 V_612 = {
. V_617 = 0 ,
. V_43 = - 1 ,
. V_22 = F_27 ( F_111 ( V_97 ) ) ,
. V_197 = V_623 ,
. V_624 = true ,
} ;
F_58 ( & V_612 . V_615 ) ;
V_23 = F_563 ( F_552 ( V_97 ) ,
F_554 ( V_98 ) , V_3 ,
false ) ;
if ( V_23 )
return V_23 ;
V_23 = F_555 ( & V_612 , V_97 , V_98 ) ;
if ( V_23 )
goto V_625;
F_564 () ;
F_205 ( V_612 . V_22 ) ;
V_43 = 0 ;
V_621 = V_97 ;
while ( ! F_74 ( F_111 ( V_621 ) ) ) {
if ( ++ V_43 >= V_53 ) {
V_23 = - V_618 ;
goto V_625;
}
V_621 &= ~ 0UL << V_43 ;
}
if ( F_565 ( V_621 , V_98 , false ) ) {
F_158 ( L_107 ,
V_626 , V_621 , V_98 ) ;
V_23 = - V_618 ;
goto V_625;
}
V_622 = F_566 ( & V_612 , V_621 , V_98 ) ;
if ( ! V_622 ) {
V_23 = - V_618 ;
goto V_625;
}
if ( V_97 != V_621 )
F_567 ( V_621 , V_97 - V_621 ) ;
if ( V_98 != V_622 )
F_567 ( V_98 , V_622 - V_98 ) ;
V_625:
F_568 ( F_552 ( V_97 ) ,
F_554 ( V_98 ) , V_3 ) ;
return V_23 ;
}
void F_567 ( unsigned long V_11 , unsigned V_45 )
{
unsigned int V_79 = 0 ;
for (; V_45 -- ; V_11 ++ ) {
struct V_1 * V_1 = F_111 ( V_11 ) ;
V_79 += F_73 ( V_1 ) != 1 ;
F_569 ( V_1 ) ;
}
F_570 ( V_79 != 0 , L_108 , V_79 ) ;
}
void T_2 F_571 ( struct V_22 * V_22 )
{
unsigned V_165 ;
F_380 ( & V_584 ) ;
F_398 (cpu)
F_428 ( V_22 ,
F_200 ( V_22 -> V_168 , V_165 ) ) ;
F_288 ( & V_584 ) ;
}
void F_572 ( struct V_22 * V_22 )
{
unsigned long V_59 ;
int V_165 ;
struct V_166 * V_167 ;
F_132 ( V_59 ) ;
if ( V_22 -> V_168 != & V_424 ) {
F_206 (cpu) {
V_167 = F_200 ( V_22 -> V_168 , V_165 ) ;
F_573 ( V_22 , V_167 ) ;
}
F_574 ( V_22 -> V_168 ) ;
V_22 -> V_168 = & V_424 ;
}
F_134 ( V_59 ) ;
}
void
F_575 ( unsigned long V_26 , unsigned long V_99 )
{
struct V_1 * V_1 ;
struct V_22 * V_22 ;
unsigned int V_43 , V_44 ;
unsigned long V_11 ;
unsigned long V_59 ;
for ( V_11 = V_26 ; V_11 < V_99 ; V_11 ++ )
if ( F_117 ( V_11 ) )
break;
if ( V_11 == V_99 )
return;
V_22 = F_27 ( F_111 ( V_11 ) ) ;
F_212 ( & V_22 -> V_85 , V_59 ) ;
V_11 = V_26 ;
while ( V_11 < V_99 ) {
if ( ! F_117 ( V_11 ) ) {
V_11 ++ ;
continue;
}
V_1 = F_111 ( V_11 ) ;
if ( F_16 ( ! F_74 ( V_1 ) && F_30 ( V_1 ) ) ) {
V_11 ++ ;
F_118 ( V_1 ) ;
continue;
}
F_153 ( F_73 ( V_1 ) ) ;
F_153 ( ! F_74 ( V_1 ) ) ;
V_43 = F_70 ( V_1 ) ;
#ifdef V_93
F_33 ( V_56 L_109 ,
V_11 , 1 << V_43 , V_99 ) ;
#endif
F_80 ( & V_1 -> V_60 ) ;
F_66 ( V_1 ) ;
V_22 -> V_69 [ V_43 ] . V_70 -- ;
for ( V_44 = 0 ; V_44 < ( 1 << V_43 ) ; V_44 ++ )
F_118 ( ( V_1 + V_44 ) ) ;
V_11 += ( 1 << V_43 ) ;
}
F_218 ( & V_22 -> V_85 , V_59 ) ;
}
bool F_576 ( struct V_1 * V_1 )
{
struct V_22 * V_22 = F_27 ( V_1 ) ;
unsigned long V_11 = F_19 ( V_1 ) ;
unsigned long V_59 ;
unsigned int V_43 ;
F_212 ( & V_22 -> V_85 , V_59 ) ;
for ( V_43 = 0 ; V_43 < V_53 ; V_43 ++ ) {
struct V_1 * V_627 = V_1 - ( V_11 & ( ( 1 << V_43 ) - 1 ) ) ;
if ( F_74 ( V_627 ) && F_70 ( V_627 ) >= V_43 )
break;
}
F_218 ( & V_22 -> V_85 , V_59 ) ;
return V_43 < V_53 ;
}
