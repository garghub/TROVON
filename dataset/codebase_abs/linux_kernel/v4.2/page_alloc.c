void F_1 ( void )
{
F_2 ( ! F_3 ( & V_1 ) ) ;
if ( V_2 ) {
V_3 = V_2 ;
V_2 = 0 ;
}
}
void F_4 ( void )
{
F_2 ( ! F_3 ( & V_1 ) ) ;
F_2 ( V_2 ) ;
V_2 = V_3 ;
V_3 &= ~ V_4 ;
}
bool F_5 ( void )
{
if ( ( V_3 & V_4 ) == V_4 )
return false ;
return true ;
}
static inline void F_6 ( T_1 * V_5 )
{
V_5 -> V_6 = V_7 ;
}
static inline bool T_2 F_7 ( unsigned long V_8 )
{
if ( V_8 >= F_8 ( F_9 ( V_8 ) ) -> V_6 )
return true ;
return false ;
}
static inline bool F_10 ( unsigned long V_8 , int V_9 )
{
if ( V_8 >= F_8 ( V_9 ) -> V_6 )
return true ;
return false ;
}
static inline bool F_11 ( T_1 * V_5 ,
unsigned long V_8 , unsigned long V_10 ,
unsigned long * V_11 )
{
if ( V_10 < F_12 ( V_5 ) )
return true ;
( * V_11 ) ++ ;
if ( * V_11 > ( 2UL << ( 30 - V_12 ) ) &&
( V_8 & ( V_13 - 1 ) ) == 0 ) {
V_5 -> V_6 = V_8 ;
return false ;
}
return true ;
}
static inline void F_6 ( T_1 * V_5 )
{
}
static inline bool F_7 ( unsigned long V_8 )
{
return false ;
}
static inline bool F_10 ( unsigned long V_8 , int V_9 )
{
return false ;
}
static inline bool F_11 ( T_1 * V_5 ,
unsigned long V_8 , unsigned long V_10 ,
unsigned long * V_11 )
{
return true ;
}
void F_13 ( struct V_14 * V_14 , int V_15 )
{
if ( F_14 ( V_16 &&
V_15 < V_17 ) )
V_15 = V_18 ;
F_15 ( V_14 , ( unsigned long ) V_15 ,
V_19 , V_20 ) ;
}
static int F_16 ( struct V_21 * V_21 , struct V_14 * V_14 )
{
int V_22 = 0 ;
unsigned V_23 ;
unsigned long V_8 = F_17 ( V_14 ) ;
unsigned long V_24 , V_25 ;
do {
V_23 = F_18 ( V_21 ) ;
V_25 = V_21 -> V_26 ;
V_24 = V_21 -> V_27 ;
if ( ! F_19 ( V_21 , V_8 ) )
V_22 = 1 ;
} while ( F_20 ( V_21 , V_23 ) );
if ( V_22 )
F_21 ( L_1 ,
V_8 , F_22 ( V_21 ) , V_21 -> V_28 ,
V_25 , V_25 + V_24 ) ;
return V_22 ;
}
static int F_23 ( struct V_21 * V_21 , struct V_14 * V_14 )
{
if ( ! F_24 ( F_17 ( V_14 ) ) )
return 0 ;
if ( V_21 != F_25 ( V_14 ) )
return 0 ;
return 1 ;
}
static int F_26 ( struct V_21 * V_21 , struct V_14 * V_14 )
{
if ( F_16 ( V_21 , V_14 ) )
return 1 ;
if ( ! F_23 ( V_21 , V_14 ) )
return 1 ;
return 0 ;
}
static inline int F_26 ( struct V_21 * V_21 , struct V_14 * V_14 )
{
return 0 ;
}
static void F_27 ( struct V_14 * V_14 , const char * V_29 ,
unsigned long V_30 )
{
static unsigned long V_31 ;
static unsigned long V_32 ;
static unsigned long V_33 ;
if ( F_28 ( V_14 ) ) {
F_29 ( V_14 ) ;
return;
}
if ( V_32 == 60 ) {
if ( F_30 ( V_34 , V_31 ) ) {
V_33 ++ ;
goto V_35;
}
if ( V_33 ) {
F_31 ( V_36
L_2 ,
V_33 ) ;
V_33 = 0 ;
}
V_32 = 0 ;
}
if ( V_32 ++ == 0 )
V_31 = V_34 + 60 * V_37 ;
F_31 ( V_36 L_3 ,
V_38 -> V_39 , F_17 ( V_14 ) ) ;
F_32 ( V_14 , V_29 , V_30 ) ;
F_33 () ;
F_34 () ;
V_35:
F_29 ( V_14 ) ;
F_35 ( V_40 , V_41 ) ;
}
static void F_36 ( struct V_14 * V_14 )
{
F_37 ( V_14 , F_38 ( V_14 ) ) ;
}
void F_39 ( struct V_14 * V_14 , unsigned long V_42 )
{
int V_43 ;
int V_44 = 1 << V_42 ;
F_40 ( V_14 , F_36 ) ;
F_41 ( V_14 , V_42 ) ;
F_42 ( V_14 ) ;
for ( V_43 = 1 ; V_43 < V_44 ; V_43 ++ ) {
struct V_14 * V_45 = V_14 + V_43 ;
F_43 ( V_45 , 0 ) ;
V_45 -> V_46 = V_14 ;
F_44 () ;
F_45 ( V_45 ) ;
}
}
static int T_3 F_46 ( char * V_47 )
{
if ( ! V_47 )
return - V_48 ;
if ( strcmp ( V_47 , L_4 ) == 0 )
V_49 = true ;
return 0 ;
}
static bool F_47 ( void )
{
if ( ! F_48 () )
return false ;
return true ;
}
static void F_49 ( void )
{
if ( ! F_48 () )
return;
V_50 = true ;
}
static int T_3 F_50 ( char * V_47 )
{
unsigned long V_51 ;
if ( F_51 ( V_47 , 10 , & V_51 ) < 0 || V_51 > V_52 / 2 ) {
F_31 ( V_53 L_5 ) ;
return 0 ;
}
V_54 = V_51 ;
F_31 ( V_55 L_6 , V_51 ) ;
return 0 ;
}
static inline void F_52 ( struct V_21 * V_21 , struct V_14 * V_14 ,
unsigned int V_42 , int V_15 )
{
struct V_56 * V_56 ;
if ( ! F_53 () )
return;
V_56 = F_54 ( V_14 ) ;
F_55 ( V_57 , & V_56 -> V_58 ) ;
F_56 ( & V_14 -> V_59 ) ;
F_57 ( V_14 , V_42 ) ;
F_58 ( V_21 , - ( 1 << V_42 ) , V_15 ) ;
}
static inline void F_59 ( struct V_21 * V_21 , struct V_14 * V_14 ,
unsigned int V_42 , int V_15 )
{
struct V_56 * V_56 ;
if ( ! F_53 () )
return;
V_56 = F_54 ( V_14 ) ;
F_60 ( V_57 , & V_56 -> V_58 ) ;
F_57 ( V_14 , 0 ) ;
if ( ! F_61 ( V_15 ) )
F_58 ( V_21 , ( 1 << V_42 ) , V_15 ) ;
}
static inline void F_52 ( struct V_21 * V_21 , struct V_14 * V_14 ,
unsigned int V_42 , int V_15 ) {}
static inline void F_59 ( struct V_21 * V_21 , struct V_14 * V_14 ,
unsigned int V_42 , int V_15 ) {}
static inline void F_62 ( struct V_14 * V_14 , unsigned int V_42 )
{
F_57 ( V_14 , V_42 ) ;
F_63 ( V_14 ) ;
}
static inline void F_64 ( struct V_14 * V_14 )
{
F_65 ( V_14 ) ;
F_57 ( V_14 , 0 ) ;
}
static inline int F_66 ( struct V_14 * V_14 , struct V_14 * V_60 ,
unsigned int V_42 )
{
if ( ! F_24 ( F_17 ( V_60 ) ) )
return 0 ;
if ( F_67 ( V_60 ) && F_68 ( V_60 ) == V_42 ) {
if ( F_69 ( V_14 ) != F_69 ( V_60 ) )
return 0 ;
F_70 ( F_71 ( V_60 ) != 0 , V_60 ) ;
return 1 ;
}
if ( F_72 ( V_60 ) && F_68 ( V_60 ) == V_42 ) {
if ( F_69 ( V_14 ) != F_69 ( V_60 ) )
return 0 ;
F_70 ( F_71 ( V_60 ) != 0 , V_60 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_73 ( struct V_14 * V_14 ,
unsigned long V_8 ,
struct V_21 * V_21 , unsigned int V_42 ,
int V_15 )
{
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long V_63 ( V_64 ) ;
struct V_14 * V_60 ;
int V_65 = V_52 ;
F_74 ( ! F_75 ( V_21 ) ) ;
F_70 ( V_14 -> V_58 & V_66 , V_14 ) ;
F_74 ( V_15 == - 1 ) ;
if ( F_61 ( V_15 ) ) {
V_65 = F_76 ( V_52 , V_67 + 1 ) ;
} else {
F_58 ( V_21 , 1 << V_42 , V_15 ) ;
}
V_61 = V_8 & ( ( 1 << V_65 ) - 1 ) ;
F_70 ( V_61 & ( ( 1 << V_42 ) - 1 ) , V_14 ) ;
F_70 ( F_26 ( V_21 , V_14 ) , V_14 ) ;
while ( V_42 < V_65 - 1 ) {
V_64 = F_77 ( V_61 , V_42 ) ;
V_60 = V_14 + ( V_64 - V_61 ) ;
if ( ! F_66 ( V_14 , V_60 , V_42 ) )
break;
if ( F_67 ( V_60 ) ) {
F_59 ( V_21 , V_60 , V_42 , V_15 ) ;
} else {
F_78 ( & V_60 -> V_59 ) ;
V_21 -> V_68 [ V_42 ] . V_69 -- ;
F_64 ( V_60 ) ;
}
V_62 = V_64 & V_61 ;
V_14 = V_14 + ( V_62 - V_61 ) ;
V_61 = V_62 ;
V_42 ++ ;
}
F_62 ( V_14 , V_42 ) ;
if ( ( V_42 < V_52 - 2 ) && F_24 ( F_17 ( V_60 ) ) ) {
struct V_14 * V_70 , * V_71 ;
V_62 = V_64 & V_61 ;
V_70 = V_14 + ( V_62 - V_61 ) ;
V_64 = F_77 ( V_62 , V_42 + 1 ) ;
V_71 = V_70 + ( V_64 - V_62 ) ;
if ( F_66 ( V_70 , V_71 , V_42 + 1 ) ) {
F_79 ( & V_14 -> V_59 ,
& V_21 -> V_68 [ V_42 ] . V_72 [ V_15 ] ) ;
goto V_35;
}
}
F_80 ( & V_14 -> V_59 , & V_21 -> V_68 [ V_42 ] . V_72 [ V_15 ] ) ;
V_35:
V_21 -> V_68 [ V_42 ] . V_69 ++ ;
}
static inline int F_81 ( struct V_14 * V_14 )
{
const char * V_73 = NULL ;
unsigned long V_30 = 0 ;
if ( F_14 ( F_82 ( V_14 ) ) )
V_73 = L_7 ;
if ( F_14 ( V_14 -> V_74 != NULL ) )
V_73 = L_8 ;
if ( F_14 ( F_83 ( & V_14 -> V_75 ) != 0 ) )
V_73 = L_9 ;
if ( F_14 ( V_14 -> V_58 & V_76 ) ) {
V_73 = L_10 ;
V_30 = V_76 ;
}
#ifdef F_84
if ( F_14 ( V_14 -> V_77 ) )
V_73 = L_11 ;
#endif
if ( F_14 ( V_73 ) ) {
F_27 ( V_14 , V_73 , V_30 ) ;
return 1 ;
}
F_85 ( V_14 ) ;
if ( V_14 -> V_58 & V_66 )
V_14 -> V_58 &= ~ V_66 ;
return 0 ;
}
static void F_86 ( struct V_21 * V_21 , int V_78 ,
struct V_79 * V_80 )
{
int V_15 = 0 ;
int V_81 = 0 ;
int V_82 = V_78 ;
unsigned long V_83 ;
F_87 ( & V_21 -> V_84 ) ;
V_83 = F_88 ( V_21 , V_85 ) ;
if ( V_83 )
F_89 ( V_21 , V_85 , - V_83 ) ;
while ( V_82 ) {
struct V_14 * V_14 ;
struct V_86 * V_87 ;
do {
V_81 ++ ;
if ( ++ V_15 == V_17 )
V_15 = 0 ;
V_87 = & V_80 -> V_88 [ V_15 ] ;
} while ( F_90 ( V_87 ) );
if ( V_81 == V_17 )
V_81 = V_82 ;
do {
int V_89 ;
V_14 = F_91 ( V_87 -> V_90 , struct V_14 , V_59 ) ;
F_78 ( & V_14 -> V_59 ) ;
V_89 = F_92 ( V_14 ) ;
if ( F_14 ( F_93 ( V_21 ) ) )
V_89 = F_94 ( V_14 ) ;
F_73 ( V_14 , F_17 ( V_14 ) , V_21 , 0 , V_89 ) ;
F_95 ( V_14 , 0 , V_89 ) ;
} while ( -- V_82 && -- V_81 && ! F_90 ( V_87 ) );
}
F_96 ( & V_21 -> V_84 ) ;
}
static void F_97 ( struct V_21 * V_21 ,
struct V_14 * V_14 , unsigned long V_8 ,
unsigned int V_42 ,
int V_15 )
{
unsigned long V_83 ;
F_87 ( & V_21 -> V_84 ) ;
V_83 = F_88 ( V_21 , V_85 ) ;
if ( V_83 )
F_89 ( V_21 , V_85 , - V_83 ) ;
if ( F_14 ( F_93 ( V_21 ) ||
F_61 ( V_15 ) ) ) {
V_15 = F_98 ( V_14 , V_8 ) ;
}
F_73 ( V_14 , V_8 , V_21 , V_42 , V_15 ) ;
F_96 ( & V_21 -> V_84 ) ;
}
static int F_99 ( struct V_14 * V_91 , struct V_14 * V_14 )
{
if ( ! F_100 ( V_92 ) )
return 0 ;
if ( F_14 ( ! F_101 ( V_14 ) ) ) {
F_27 ( V_14 , L_12 , 0 ) ;
return 1 ;
}
if ( F_14 ( V_14 -> V_46 != V_91 ) ) {
F_27 ( V_14 , L_13 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void T_2 F_102 ( struct V_14 * V_14 , unsigned long V_8 ,
unsigned long V_21 , int V_9 )
{
F_103 ( V_14 , V_21 , V_9 , V_8 ) ;
F_104 ( V_14 ) ;
F_29 ( V_14 ) ;
F_85 ( V_14 ) ;
F_56 ( & V_14 -> V_59 ) ;
#ifdef F_105
if ( ! F_106 ( V_21 ) )
F_107 ( V_14 , F_108 ( V_8 << V_12 ) ) ;
#endif
}
static void T_2 F_109 ( unsigned long V_8 , unsigned long V_21 ,
int V_9 )
{
return F_102 ( F_110 ( V_8 ) , V_8 , V_21 , V_9 ) ;
}
static void F_111 ( unsigned long V_8 )
{
T_1 * V_5 ;
int V_9 , V_93 ;
if ( ! F_7 ( V_8 ) )
return;
V_9 = F_9 ( V_8 ) ;
V_5 = F_8 ( V_9 ) ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ ) {
struct V_21 * V_21 = & V_5 -> V_95 [ V_93 ] ;
if ( V_8 >= V_21 -> V_26 && V_8 < F_112 ( V_21 ) )
break;
}
F_109 ( V_8 , V_93 , V_9 ) ;
}
static inline void F_111 ( unsigned long V_8 )
{
}
void T_2 F_113 ( unsigned long V_96 , unsigned long V_97 )
{
unsigned long V_25 = F_114 ( V_96 ) ;
unsigned long V_98 = F_115 ( V_97 ) ;
for (; V_25 < V_98 ; V_25 ++ ) {
if ( F_116 ( V_25 ) ) {
struct V_14 * V_14 = F_110 ( V_25 ) ;
F_111 ( V_25 ) ;
F_117 ( V_14 ) ;
}
}
}
static bool F_118 ( struct V_14 * V_14 , unsigned int V_42 )
{
bool V_99 = F_119 ( V_14 ) ;
int V_43 , V_100 = 0 ;
F_70 ( F_101 ( V_14 ) , V_14 ) ;
F_70 ( V_99 && F_38 ( V_14 ) != V_42 , V_14 ) ;
F_120 ( V_14 , V_42 ) ;
F_121 ( V_14 , V_42 ) ;
F_122 ( V_14 , V_42 ) ;
if ( F_123 ( V_14 ) )
V_14 -> V_74 = NULL ;
V_100 += F_81 ( V_14 ) ;
for ( V_43 = 1 ; V_43 < ( 1 << V_42 ) ; V_43 ++ ) {
if ( V_99 )
V_100 += F_99 ( V_14 , V_14 + V_43 ) ;
V_100 += F_81 ( V_14 + V_43 ) ;
}
if ( V_100 )
return false ;
F_124 ( V_14 , V_42 ) ;
if ( ! F_125 ( V_14 ) ) {
F_126 ( F_127 ( V_14 ) ,
V_101 << V_42 ) ;
F_128 ( F_127 ( V_14 ) ,
V_101 << V_42 ) ;
}
F_129 ( V_14 , V_42 ) ;
F_130 ( V_14 , 1 << V_42 , 0 ) ;
return true ;
}
static void F_37 ( struct V_14 * V_14 , unsigned int V_42 )
{
unsigned long V_58 ;
int V_15 ;
unsigned long V_8 = F_17 ( V_14 ) ;
if ( ! F_118 ( V_14 , V_42 ) )
return;
V_15 = F_98 ( V_14 , V_8 ) ;
F_131 ( V_58 ) ;
F_132 ( V_102 , 1 << V_42 ) ;
F_133 ( V_14 , V_15 ) ;
F_97 ( F_25 ( V_14 ) , V_14 , V_8 , V_42 , V_15 ) ;
F_134 ( V_58 ) ;
}
static void T_3 F_135 ( struct V_14 * V_14 ,
unsigned long V_8 , unsigned int V_42 )
{
unsigned int V_44 = 1 << V_42 ;
struct V_14 * V_45 = V_14 ;
unsigned int V_103 ;
F_136 ( V_45 ) ;
for ( V_103 = 0 ; V_103 < ( V_44 - 1 ) ; V_103 ++ , V_45 ++ ) {
F_136 ( V_45 + 1 ) ;
F_137 ( V_45 ) ;
F_43 ( V_45 , 0 ) ;
}
F_137 ( V_45 ) ;
F_43 ( V_45 , 0 ) ;
F_25 ( V_14 ) -> V_104 += V_44 ;
F_138 ( V_14 ) ;
F_139 ( V_14 , V_42 ) ;
}
int T_2 F_9 ( unsigned long V_8 )
{
static F_140 ( V_105 ) ;
int V_9 ;
F_87 ( & V_105 ) ;
V_9 = F_141 ( V_8 , & V_106 ) ;
if ( V_9 < 0 )
V_9 = 0 ;
F_96 ( & V_105 ) ;
return V_9 ;
}
static inline bool T_2 F_142 ( unsigned long V_8 , int V_107 ,
struct V_108 * V_109 )
{
int V_9 ;
V_9 = F_141 ( V_8 , V_109 ) ;
if ( V_9 >= 0 && V_9 != V_107 )
return false ;
return true ;
}
static inline bool T_2 F_143 ( unsigned long V_8 , int V_107 )
{
return F_142 ( V_8 , V_107 , & V_106 ) ;
}
static inline bool T_2 F_143 ( unsigned long V_8 , int V_107 )
{
return true ;
}
static inline bool T_2 F_142 ( unsigned long V_8 , int V_107 ,
struct V_108 * V_109 )
{
return true ;
}
void T_3 F_144 ( struct V_14 * V_14 , unsigned long V_8 ,
unsigned int V_42 )
{
if ( F_7 ( V_8 ) )
return;
return F_135 ( V_14 , V_8 , V_42 ) ;
}
static void T_3 F_145 ( struct V_14 * V_14 ,
unsigned long V_8 , int V_44 )
{
int V_43 ;
if ( ! V_14 )
return;
if ( V_44 == V_110 &&
( V_8 & ( V_110 - 1 ) ) == 0 ) {
F_13 ( V_14 , V_111 ) ;
F_135 ( V_14 , V_8 , V_52 - 1 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ , V_14 ++ , V_8 ++ )
F_135 ( V_14 , V_8 , 0 ) ;
}
static inline void T_3 F_146 ( void )
{
if ( F_147 ( & V_112 ) )
F_148 ( & V_113 ) ;
}
static int T_3 F_149 ( void * V_114 )
{
T_1 * V_5 = V_114 ;
int V_9 = V_5 -> V_115 ;
struct V_108 V_116 = { } ;
unsigned long V_96 = V_34 ;
unsigned long V_44 = 0 ;
unsigned long V_117 , V_118 ;
int V_43 , V_93 ;
struct V_21 * V_21 ;
unsigned long V_119 = V_5 -> V_6 ;
const struct V_120 * V_120 = F_150 ( V_5 -> V_115 ) ;
if ( V_119 == V_7 ) {
F_146 () ;
return 0 ;
}
if ( ! F_151 ( V_120 ) )
F_152 ( V_38 , V_120 ) ;
F_153 ( V_5 -> V_6 < V_5 -> V_121 ) ;
F_153 ( V_5 -> V_6 > F_12 ( V_5 ) ) ;
V_5 -> V_6 = V_7 ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ ) {
V_21 = V_5 -> V_95 + V_93 ;
if ( V_119 < F_112 ( V_21 ) )
break;
}
F_154 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_8 , V_98 ;
struct V_14 * V_14 = NULL ;
struct V_14 * V_122 = NULL ;
unsigned long V_123 = 0 ;
int V_124 = 0 ;
V_98 = F_76 ( V_118 , F_112 ( V_21 ) ) ;
V_8 = V_119 ;
if ( V_8 < V_117 )
V_8 = V_117 ;
if ( V_8 < V_21 -> V_26 )
V_8 = V_21 -> V_26 ;
for (; V_8 < V_98 ; V_8 ++ ) {
if ( ! F_24 ( V_8 ) )
goto V_125;
if ( ( V_8 & ( V_110 - 1 ) ) == 0 ) {
if ( ! F_116 ( V_8 ) ) {
V_14 = NULL ;
goto V_125;
}
}
if ( ! F_142 ( V_8 , V_9 , & V_116 ) ) {
V_14 = NULL ;
goto V_125;
}
if ( V_14 && ( V_8 & ( V_110 - 1 ) ) != 0 ) {
V_14 ++ ;
} else {
V_44 += V_124 ;
F_145 ( V_122 ,
V_123 , V_124 ) ;
V_122 = NULL ;
V_123 = V_124 = 0 ;
V_14 = F_110 ( V_8 ) ;
F_155 () ;
}
if ( V_14 -> V_58 ) {
F_74 ( F_25 ( V_14 ) != V_21 ) ;
goto V_125;
}
F_102 ( V_14 , V_8 , V_93 , V_9 ) ;
if ( ! V_122 ) {
V_122 = V_14 ;
V_123 = V_8 ;
V_124 = 0 ;
}
V_124 ++ ;
continue;
V_125:
V_44 += V_124 ;
F_145 ( V_122 , V_123 ,
V_124 ) ;
V_122 = NULL ;
V_123 = V_124 = 0 ;
}
V_119 = F_156 ( V_98 , V_119 ) ;
}
F_2 ( ++ V_93 < V_94 && F_157 ( ++ V_21 ) ) ;
F_158 ( L_14 , V_9 , V_44 ,
F_159 ( V_34 - V_96 ) ) ;
F_146 () ;
return 0 ;
}
void T_3 F_160 ( void )
{
int V_9 ;
F_161 ( & V_112 , F_162 ( V_126 ) ) ;
F_163 (nid, N_MEMORY) {
F_164 ( F_149 , F_8 ( V_9 ) , L_15 , V_9 ) ;
}
F_165 ( & V_113 ) ;
F_166 () ;
}
void T_3 F_167 ( struct V_14 * V_14 )
{
unsigned V_43 = V_127 ;
struct V_14 * V_45 = V_14 ;
do {
F_137 ( V_45 ) ;
F_43 ( V_45 , 0 ) ;
} while ( ++ V_45 , -- V_43 );
F_13 ( V_14 , V_128 ) ;
if ( V_67 >= V_52 ) {
V_43 = V_127 ;
V_45 = V_14 ;
do {
F_138 ( V_45 ) ;
F_139 ( V_45 , V_52 - 1 ) ;
V_45 += V_110 ;
} while ( V_43 -= V_110 );
} else {
F_138 ( V_14 ) ;
F_139 ( V_14 , V_67 ) ;
}
F_168 ( V_14 , V_127 ) ;
}
static inline void F_169 ( struct V_21 * V_21 , struct V_14 * V_14 ,
int V_129 , int V_130 , struct V_68 * V_131 ,
int V_15 )
{
unsigned long V_132 = 1 << V_130 ;
while ( V_130 > V_129 ) {
V_131 -- ;
V_130 -- ;
V_132 >>= 1 ;
F_70 ( F_26 ( V_21 , & V_14 [ V_132 ] ) , & V_14 [ V_132 ] ) ;
if ( F_100 ( V_133 ) &&
F_53 () &&
V_130 < F_170 () ) {
F_52 ( V_21 , & V_14 [ V_132 ] , V_130 , V_15 ) ;
continue;
}
F_80 ( & V_14 [ V_132 ] . V_59 , & V_131 -> V_72 [ V_15 ] ) ;
V_131 -> V_69 ++ ;
F_62 ( & V_14 [ V_132 ] , V_130 ) ;
}
}
static inline int F_171 ( struct V_14 * V_14 )
{
const char * V_73 = NULL ;
unsigned long V_30 = 0 ;
if ( F_14 ( F_82 ( V_14 ) ) )
V_73 = L_7 ;
if ( F_14 ( V_14 -> V_74 != NULL ) )
V_73 = L_8 ;
if ( F_14 ( F_83 ( & V_14 -> V_75 ) != 0 ) )
V_73 = L_9 ;
if ( F_14 ( V_14 -> V_58 & V_134 ) ) {
V_73 = L_16 ;
V_30 = V_134 ;
}
if ( F_14 ( V_14 -> V_58 & V_66 ) ) {
V_73 = L_17 ;
V_30 = V_66 ;
}
#ifdef F_84
if ( F_14 ( V_14 -> V_77 ) )
V_73 = L_11 ;
#endif
if ( F_14 ( V_73 ) ) {
F_27 ( V_14 , V_73 , V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_172 ( struct V_14 * V_14 , unsigned int V_42 , T_4 V_135 ,
int V_136 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < ( 1 << V_42 ) ; V_43 ++ ) {
struct V_14 * V_45 = V_14 + V_43 ;
if ( F_14 ( F_171 ( V_45 ) ) )
return 1 ;
}
F_57 ( V_14 , 0 ) ;
F_138 ( V_14 ) ;
F_173 ( V_14 , V_42 ) ;
F_130 ( V_14 , 1 << V_42 , 1 ) ;
F_174 ( V_14 , V_42 ) ;
if ( V_135 & V_137 )
for ( V_43 = 0 ; V_43 < ( 1 << V_42 ) ; V_43 ++ )
F_175 ( V_14 + V_43 ) ;
if ( V_42 && ( V_135 & V_138 ) )
F_39 ( V_14 , V_42 ) ;
F_176 ( V_14 , V_42 , V_135 ) ;
if ( V_136 & V_139 )
F_177 ( V_14 ) ;
else
F_178 ( V_14 ) ;
return 0 ;
}
static inline
struct V_14 * F_179 ( struct V_21 * V_21 , unsigned int V_42 ,
int V_15 )
{
unsigned int V_140 ;
struct V_68 * V_131 ;
struct V_14 * V_14 ;
for ( V_140 = V_42 ; V_140 < V_52 ; ++ V_140 ) {
V_131 = & ( V_21 -> V_68 [ V_140 ] ) ;
if ( F_90 ( & V_131 -> V_72 [ V_15 ] ) )
continue;
V_14 = F_91 ( V_131 -> V_72 [ V_15 ] . V_141 ,
struct V_14 , V_59 ) ;
F_78 ( & V_14 -> V_59 ) ;
F_64 ( V_14 ) ;
V_131 -> V_69 -- ;
F_169 ( V_21 , V_14 , V_42 , V_140 , V_131 , V_15 ) ;
F_133 ( V_14 , V_15 ) ;
return V_14 ;
}
return NULL ;
}
static struct V_14 * F_180 ( struct V_21 * V_21 ,
unsigned int V_42 )
{
return F_179 ( V_21 , V_42 , V_128 ) ;
}
static inline struct V_14 * F_180 ( struct V_21 * V_21 ,
unsigned int V_42 ) { return NULL ; }
int F_181 ( struct V_21 * V_21 ,
struct V_14 * V_142 , struct V_14 * V_143 ,
int V_15 )
{
struct V_14 * V_14 ;
unsigned long V_42 ;
int V_144 = 0 ;
#ifndef F_182
F_74 ( F_25 ( V_142 ) != F_25 ( V_143 ) ) ;
#endif
for ( V_14 = V_142 ; V_14 <= V_143 ; ) {
F_70 ( F_183 ( V_14 ) != F_22 ( V_21 ) , V_14 ) ;
if ( ! F_24 ( F_17 ( V_14 ) ) ) {
V_14 ++ ;
continue;
}
if ( ! F_72 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_42 = F_68 ( V_14 ) ;
F_184 ( & V_14 -> V_59 ,
& V_21 -> V_68 [ V_42 ] . V_72 [ V_15 ] ) ;
F_133 ( V_14 , V_15 ) ;
V_14 += 1 << V_42 ;
V_144 += 1 << V_42 ;
}
return V_144 ;
}
int F_185 ( struct V_21 * V_21 , struct V_14 * V_14 ,
int V_15 )
{
unsigned long V_25 , V_98 ;
struct V_14 * V_142 , * V_143 ;
V_25 = F_17 ( V_14 ) ;
V_25 = V_25 & ~ ( V_127 - 1 ) ;
V_142 = F_110 ( V_25 ) ;
V_143 = V_142 + V_127 - 1 ;
V_98 = V_25 + V_127 - 1 ;
if ( ! F_19 ( V_21 , V_25 ) )
V_142 = V_14 ;
if ( ! F_19 ( V_21 , V_98 ) )
return 0 ;
return F_181 ( V_21 , V_142 , V_143 , V_15 ) ;
}
static void F_186 ( struct V_14 * V_145 ,
int V_146 , int V_15 )
{
int V_147 = 1 << ( V_146 - V_67 ) ;
while ( V_147 -- ) {
F_13 ( V_145 , V_15 ) ;
V_145 += V_127 ;
}
}
static bool F_187 ( unsigned int V_42 , int V_148 )
{
if ( V_42 >= V_67 )
return true ;
if ( V_42 >= V_67 / 2 ||
V_148 == V_149 ||
V_148 == V_18 ||
V_16 )
return true ;
return false ;
}
static void F_188 ( struct V_21 * V_21 , struct V_14 * V_14 ,
int V_150 )
{
int V_140 = F_68 ( V_14 ) ;
int V_151 ;
if ( V_140 >= V_67 ) {
F_186 ( V_14 , V_140 , V_150 ) ;
return;
}
V_151 = F_185 ( V_21 , V_14 , V_150 ) ;
if ( V_151 >= ( 1 << ( V_67 - 1 ) ) ||
V_16 )
F_13 ( V_14 , V_150 ) ;
}
int F_189 ( struct V_68 * V_131 , unsigned int V_42 ,
int V_15 , bool V_152 , bool * V_153 )
{
int V_43 ;
int V_154 ;
if ( V_131 -> V_69 == 0 )
return - 1 ;
* V_153 = false ;
for ( V_43 = 0 ; ; V_43 ++ ) {
V_154 = V_155 [ V_15 ] [ V_43 ] ;
if ( V_154 == V_156 )
break;
if ( F_90 ( & V_131 -> V_72 [ V_154 ] ) )
continue;
if ( F_187 ( V_42 , V_15 ) )
* V_153 = true ;
if ( ! V_152 )
return V_154 ;
if ( * V_153 )
return V_154 ;
}
return - 1 ;
}
static inline struct V_14 *
F_190 ( struct V_21 * V_21 , unsigned int V_42 , int V_157 )
{
struct V_68 * V_131 ;
unsigned int V_140 ;
struct V_14 * V_14 ;
int V_154 ;
bool V_153 ;
for ( V_140 = V_52 - 1 ;
V_140 >= V_42 && V_140 <= V_52 - 1 ;
-- V_140 ) {
V_131 = & ( V_21 -> V_68 [ V_140 ] ) ;
V_154 = F_189 ( V_131 , V_140 ,
V_157 , false , & V_153 ) ;
if ( V_154 == - 1 )
continue;
V_14 = F_91 ( V_131 -> V_72 [ V_154 ] . V_141 ,
struct V_14 , V_59 ) ;
if ( V_153 )
F_188 ( V_21 , V_14 , V_157 ) ;
V_131 -> V_69 -- ;
F_78 ( & V_14 -> V_59 ) ;
F_64 ( V_14 ) ;
F_169 ( V_21 , V_14 , V_42 , V_140 , V_131 ,
V_157 ) ;
F_133 ( V_14 , V_157 ) ;
F_191 ( V_14 , V_42 , V_140 ,
V_157 , V_154 ) ;
return V_14 ;
}
return NULL ;
}
static struct V_14 * F_192 ( struct V_21 * V_21 , unsigned int V_42 ,
int V_15 )
{
struct V_14 * V_14 ;
V_158:
V_14 = F_179 ( V_21 , V_42 , V_15 ) ;
if ( F_14 ( ! V_14 ) && V_15 != V_156 ) {
if ( V_15 == V_111 )
V_14 = F_180 ( V_21 , V_42 ) ;
if ( ! V_14 )
V_14 = F_190 ( V_21 , V_42 , V_15 ) ;
if ( ! V_14 ) {
V_15 = V_156 ;
goto V_158;
}
}
F_193 ( V_14 , V_42 , V_15 ) ;
return V_14 ;
}
static int F_194 ( struct V_21 * V_21 , unsigned int V_42 ,
unsigned long V_78 , struct V_86 * V_87 ,
int V_15 , bool V_159 )
{
int V_43 ;
F_87 ( & V_21 -> V_84 ) ;
for ( V_43 = 0 ; V_43 < V_78 ; ++ V_43 ) {
struct V_14 * V_14 = F_192 ( V_21 , V_42 , V_15 ) ;
if ( F_14 ( V_14 == NULL ) )
break;
if ( F_195 ( ! V_159 ) )
F_80 ( & V_14 -> V_59 , V_87 ) ;
else
F_79 ( & V_14 -> V_59 , V_87 ) ;
V_87 = & V_14 -> V_59 ;
if ( F_196 ( F_92 ( V_14 ) ) )
F_89 ( V_21 , V_160 ,
- ( 1 << V_42 ) ) ;
}
F_89 ( V_21 , V_161 , - ( V_43 << V_42 ) ) ;
F_96 ( & V_21 -> V_84 ) ;
return V_43 ;
}
void F_197 ( struct V_21 * V_21 , struct V_79 * V_80 )
{
unsigned long V_58 ;
int V_162 , V_163 ;
F_131 ( V_58 ) ;
V_163 = F_198 ( V_80 -> V_163 ) ;
V_162 = F_76 ( V_80 -> V_78 , V_163 ) ;
if ( V_162 > 0 ) {
F_86 ( V_21 , V_162 , V_80 ) ;
V_80 -> V_78 -= V_162 ;
}
F_134 ( V_58 ) ;
}
static void F_199 ( unsigned int V_164 , struct V_21 * V_21 )
{
unsigned long V_58 ;
struct V_165 * V_166 ;
struct V_79 * V_80 ;
F_131 ( V_58 ) ;
V_166 = F_200 ( V_21 -> V_167 , V_164 ) ;
V_80 = & V_166 -> V_80 ;
if ( V_80 -> V_78 ) {
F_86 ( V_21 , V_80 -> V_78 , V_80 ) ;
V_80 -> V_78 = 0 ;
}
F_134 ( V_58 ) ;
}
static void F_201 ( unsigned int V_164 )
{
struct V_21 * V_21 ;
F_202 (zone) {
F_199 ( V_164 , V_21 ) ;
}
}
void F_203 ( struct V_21 * V_21 )
{
int V_164 = F_204 () ;
if ( V_21 )
F_199 ( V_164 , V_21 ) ;
else
F_201 ( V_164 ) ;
}
void F_205 ( struct V_21 * V_21 )
{
int V_164 ;
static T_5 V_168 ;
F_206 (cpu) {
struct V_165 * V_80 ;
struct V_21 * V_169 ;
bool V_170 = false ;
if ( V_21 ) {
V_80 = F_200 ( V_21 -> V_167 , V_164 ) ;
if ( V_80 -> V_80 . V_78 )
V_170 = true ;
} else {
F_202 (z) {
V_80 = F_200 ( V_169 -> V_167 , V_164 ) ;
if ( V_80 -> V_80 . V_78 ) {
V_170 = true ;
break;
}
}
}
if ( V_170 )
F_207 ( V_164 , & V_168 ) ;
else
F_208 ( V_164 , & V_168 ) ;
}
F_209 ( & V_168 , ( V_171 ) F_203 ,
V_21 , 1 ) ;
}
void F_210 ( struct V_21 * V_21 )
{
unsigned long V_8 , V_172 ;
unsigned long V_58 ;
unsigned int V_42 , V_173 ;
struct V_86 * V_174 ;
if ( F_211 ( V_21 ) )
return;
F_212 ( & V_21 -> V_84 , V_58 ) ;
V_172 = F_112 ( V_21 ) ;
for ( V_8 = V_21 -> V_26 ; V_8 < V_172 ; V_8 ++ )
if ( F_116 ( V_8 ) ) {
struct V_14 * V_14 = F_110 ( V_8 ) ;
if ( ! F_213 ( V_14 ) )
F_214 ( V_14 ) ;
}
F_215 (order, t) {
F_216 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_43 ;
V_8 = F_17 ( F_91 ( V_174 , struct V_14 , V_59 ) ) ;
for ( V_43 = 0 ; V_43 < ( 1UL << V_42 ) ; V_43 ++ )
F_217 ( F_110 ( V_8 + V_43 ) ) ;
}
}
F_218 ( & V_21 -> V_84 , V_58 ) ;
}
void F_219 ( struct V_14 * V_14 , bool V_159 )
{
struct V_21 * V_21 = F_25 ( V_14 ) ;
struct V_79 * V_80 ;
unsigned long V_58 ;
unsigned long V_8 = F_17 ( V_14 ) ;
int V_15 ;
if ( ! F_118 ( V_14 , 0 ) )
return;
V_15 = F_98 ( V_14 , V_8 ) ;
F_133 ( V_14 , V_15 ) ;
F_131 ( V_58 ) ;
F_220 ( V_102 ) ;
if ( V_15 >= V_17 ) {
if ( F_14 ( F_61 ( V_15 ) ) ) {
F_97 ( V_21 , V_14 , V_8 , 0 , V_15 ) ;
goto V_35;
}
V_15 = V_111 ;
}
V_80 = & F_221 ( V_21 -> V_167 ) -> V_80 ;
if ( ! V_159 )
F_80 ( & V_14 -> V_59 , & V_80 -> V_88 [ V_15 ] ) ;
else
F_79 ( & V_14 -> V_59 , & V_80 -> V_88 [ V_15 ] ) ;
V_80 -> V_78 ++ ;
if ( V_80 -> V_78 >= V_80 -> V_130 ) {
unsigned long V_163 = F_198 ( V_80 -> V_163 ) ;
F_86 ( V_21 , V_163 , V_80 ) ;
V_80 -> V_78 -= V_163 ;
}
V_35:
F_134 ( V_58 ) ;
}
void F_222 ( struct V_86 * V_87 , bool V_159 )
{
struct V_14 * V_14 , * V_141 ;
F_223 (page, next, list, lru) {
F_224 ( V_14 , V_159 ) ;
F_219 ( V_14 , V_159 ) ;
}
}
void F_225 ( struct V_14 * V_14 , unsigned int V_42 )
{
int V_43 ;
T_4 V_175 ;
F_70 ( F_119 ( V_14 ) , V_14 ) ;
F_70 ( ! F_71 ( V_14 ) , V_14 ) ;
#ifdef F_226
if ( F_227 ( V_14 ) )
F_225 ( F_228 ( V_14 [ 0 ] . V_176 ) , V_42 ) ;
#endif
V_175 = F_229 ( V_14 ) ;
F_176 ( V_14 , 0 , V_175 ) ;
for ( V_43 = 1 ; V_43 < ( 1 << V_42 ) ; V_43 ++ ) {
F_138 ( V_14 + V_43 ) ;
F_176 ( V_14 + V_43 , 0 , V_175 ) ;
}
}
int F_230 ( struct V_14 * V_14 , unsigned int V_42 )
{
unsigned long V_177 ;
struct V_21 * V_21 ;
int V_89 ;
F_153 ( ! F_72 ( V_14 ) ) ;
V_21 = F_25 ( V_14 ) ;
V_89 = F_94 ( V_14 ) ;
if ( ! F_61 ( V_89 ) ) {
V_177 = F_231 ( V_21 ) + ( 1 << V_42 ) ;
if ( ! F_232 ( V_21 , 0 , V_177 , 0 , 0 ) )
return 0 ;
F_58 ( V_21 , - ( 1UL << V_42 ) , V_89 ) ;
}
F_78 ( & V_14 -> V_59 ) ;
V_21 -> V_68 [ V_42 ] . V_69 -- ;
F_64 ( V_14 ) ;
F_176 ( V_14 , V_42 , V_178 ) ;
if ( V_42 >= V_67 - 1 ) {
struct V_14 * V_179 = V_14 + ( 1 << V_42 ) - 1 ;
for (; V_14 < V_179 ; V_14 += V_127 ) {
int V_89 = F_94 ( V_14 ) ;
if ( ! F_61 ( V_89 ) && ! F_196 ( V_89 ) )
F_13 ( V_14 ,
V_111 ) ;
}
}
return 1UL << V_42 ;
}
int F_233 ( struct V_14 * V_14 )
{
unsigned int V_42 ;
int V_44 ;
V_42 = F_68 ( V_14 ) ;
V_44 = F_230 ( V_14 , V_42 ) ;
if ( ! V_44 )
return 0 ;
F_138 ( V_14 ) ;
F_225 ( V_14 , V_42 ) ;
return V_44 ;
}
static inline
struct V_14 * F_234 ( struct V_21 * V_180 ,
struct V_21 * V_21 , unsigned int V_42 ,
T_4 V_135 , int V_15 )
{
unsigned long V_58 ;
struct V_14 * V_14 ;
bool V_159 = ( ( V_135 & V_181 ) != 0 ) ;
if ( F_195 ( V_42 == 0 ) ) {
struct V_79 * V_80 ;
struct V_86 * V_87 ;
F_131 ( V_58 ) ;
V_80 = & F_221 ( V_21 -> V_167 ) -> V_80 ;
V_87 = & V_80 -> V_88 [ V_15 ] ;
if ( F_90 ( V_87 ) ) {
V_80 -> V_78 += F_194 ( V_21 , 0 ,
V_80 -> V_163 , V_87 ,
V_15 , V_159 ) ;
if ( F_14 ( F_90 ( V_87 ) ) )
goto V_182;
}
if ( V_159 )
V_14 = F_91 ( V_87 -> V_90 , struct V_14 , V_59 ) ;
else
V_14 = F_91 ( V_87 -> V_141 , struct V_14 , V_59 ) ;
F_78 ( & V_14 -> V_59 ) ;
V_80 -> V_78 -- ;
} else {
if ( F_14 ( V_135 & V_183 ) ) {
F_235 ( V_42 > 1 ) ;
}
F_212 ( & V_21 -> V_84 , V_58 ) ;
V_14 = F_192 ( V_21 , V_42 , V_15 ) ;
F_96 ( & V_21 -> V_84 ) ;
if ( ! V_14 )
goto V_182;
F_58 ( V_21 , - ( 1 << V_42 ) ,
F_92 ( V_14 ) ) ;
}
F_89 ( V_21 , V_184 , - ( 1 << V_42 ) ) ;
if ( F_236 ( & V_21 -> V_185 [ V_184 ] ) <= 0 &&
! F_237 ( V_186 , & V_21 -> V_58 ) )
F_238 ( V_186 , & V_21 -> V_58 ) ;
F_239 ( V_187 , V_21 , 1 << V_42 ) ;
F_240 ( V_180 , V_21 , V_135 ) ;
F_134 ( V_58 ) ;
F_70 ( F_26 ( V_21 , V_14 ) , V_14 ) ;
return V_14 ;
V_182:
F_134 ( V_58 ) ;
return NULL ;
}
static int T_3 F_241 ( char * V_188 )
{
return F_242 ( & V_189 . V_190 , V_188 ) ;
}
static bool F_243 ( T_4 V_175 , unsigned int V_42 )
{
if ( V_42 < V_189 . V_191 )
return false ;
if ( V_175 & V_183 )
return false ;
if ( V_189 . V_192 && ( V_175 & V_193 ) )
return false ;
if ( V_189 . V_194 && ( V_175 & V_195 ) )
return false ;
return F_244 ( & V_189 . V_190 , 1 << V_42 ) ;
}
static int T_3 F_245 ( void )
{
T_6 V_196 = V_197 | V_198 | V_199 ;
struct V_200 * V_201 ;
V_201 = F_246 ( L_18 , NULL ,
& V_189 . V_190 ) ;
if ( F_247 ( V_201 ) )
return F_248 ( V_201 ) ;
if ( ! F_249 ( L_19 , V_196 , V_201 ,
& V_189 . V_194 ) )
goto V_202;
if ( ! F_249 ( L_20 , V_196 , V_201 ,
& V_189 . V_192 ) )
goto V_202;
if ( ! F_250 ( L_21 , V_196 , V_201 ,
& V_189 . V_191 ) )
goto V_202;
return 0 ;
V_202:
F_251 ( V_201 ) ;
return - V_203 ;
}
static inline bool F_243 ( T_4 V_175 , unsigned int V_42 )
{
return false ;
}
static bool F_252 ( struct V_21 * V_169 , unsigned int V_42 ,
unsigned long V_204 , int V_205 , int V_136 ,
long V_206 )
{
long F_76 = V_204 ;
int V_207 ;
long V_208 = 0 ;
V_206 -= ( 1 << V_42 ) - 1 ;
if ( V_136 & V_209 )
F_76 -= F_76 / 2 ;
if ( V_136 & V_210 )
F_76 -= F_76 / 4 ;
#ifdef F_253
if ( ! ( V_136 & V_211 ) )
V_208 = F_88 ( V_169 , V_160 ) ;
#endif
if ( V_206 - V_208 <= F_76 + V_169 -> V_212 [ V_205 ] )
return false ;
for ( V_207 = 0 ; V_207 < V_42 ; V_207 ++ ) {
V_206 -= V_169 -> V_68 [ V_207 ] . V_69 << V_207 ;
F_76 >>= 1 ;
if ( V_206 <= F_76 )
return false ;
}
return true ;
}
bool F_232 ( struct V_21 * V_169 , unsigned int V_42 , unsigned long V_204 ,
int V_205 , int V_136 )
{
return F_252 ( V_169 , V_42 , V_204 , V_205 , V_136 ,
F_88 ( V_169 , V_161 ) ) ;
}
bool F_254 ( struct V_21 * V_169 , unsigned int V_42 ,
unsigned long V_204 , int V_205 , int V_136 )
{
long V_206 = F_88 ( V_169 , V_161 ) ;
if ( V_169 -> V_213 && V_206 < V_169 -> V_213 )
V_206 = F_255 ( V_169 , V_161 ) ;
return F_252 ( V_169 , V_42 , V_204 , V_205 , V_136 ,
V_206 ) ;
}
static T_7 * F_256 ( struct V_214 * V_214 , int V_136 )
{
struct V_215 * V_216 ;
T_7 * V_217 ;
V_216 = V_214 -> V_218 ;
if ( ! V_216 )
return NULL ;
if ( F_257 ( V_34 , V_216 -> V_219 + V_37 ) ) {
F_258 ( V_216 -> V_220 , V_221 ) ;
V_216 -> V_219 = V_34 ;
}
V_217 = ! F_259 () && ( V_136 & V_222 ) ?
& V_223 :
& V_224 [ V_126 ] ;
return V_217 ;
}
static int F_260 ( struct V_214 * V_214 , struct V_225 * V_169 ,
T_7 * V_217 )
{
struct V_215 * V_216 ;
int V_43 ;
int V_226 ;
V_216 = V_214 -> V_218 ;
if ( ! V_216 )
return 1 ;
V_43 = V_169 - V_214 -> V_227 ;
V_226 = V_216 -> V_228 [ V_43 ] ;
return F_261 ( V_226 , * V_217 ) && ! F_237 ( V_43 , V_216 -> V_220 ) ;
}
static void F_262 ( struct V_214 * V_214 , struct V_225 * V_169 )
{
struct V_215 * V_216 ;
int V_43 ;
V_216 = V_214 -> V_218 ;
if ( ! V_216 )
return;
V_43 = V_169 - V_214 -> V_227 ;
F_238 ( V_43 , V_216 -> V_220 ) ;
}
static void F_263 ( struct V_214 * V_214 )
{
struct V_215 * V_216 ;
V_216 = V_214 -> V_218 ;
if ( ! V_216 )
return;
F_258 ( V_216 -> V_220 , V_221 ) ;
}
static bool F_264 ( struct V_21 * V_229 , struct V_21 * V_21 )
{
return V_229 -> V_107 == V_21 -> V_107 ;
}
static bool F_265 ( struct V_21 * V_229 , struct V_21 * V_21 )
{
return F_266 ( F_22 ( V_229 ) , F_22 ( V_21 ) ) <
V_230 ;
}
static T_7 * F_256 ( struct V_214 * V_214 , int V_136 )
{
return NULL ;
}
static int F_260 ( struct V_214 * V_214 , struct V_225 * V_169 ,
T_7 * V_217 )
{
return 1 ;
}
static void F_262 ( struct V_214 * V_214 , struct V_225 * V_169 )
{
}
static void F_263 ( struct V_214 * V_214 )
{
}
static bool F_264 ( struct V_21 * V_229 , struct V_21 * V_21 )
{
return true ;
}
static bool F_265 ( struct V_21 * V_229 , struct V_21 * V_21 )
{
return true ;
}
static void F_267 ( struct V_21 * V_180 )
{
struct V_21 * V_21 = V_180 -> V_231 -> V_95 ;
do {
F_268 ( V_21 , V_184 ,
F_269 ( V_21 ) - F_231 ( V_21 ) -
F_236 ( & V_21 -> V_185 [ V_184 ] ) ) ;
F_270 ( V_186 , & V_21 -> V_58 ) ;
} while ( V_21 ++ != V_180 );
}
static struct V_14 *
F_271 ( T_4 V_175 , unsigned int V_42 , int V_136 ,
const struct V_232 * V_233 )
{
struct V_214 * V_214 = V_233 -> V_214 ;
struct V_225 * V_169 ;
struct V_14 * V_14 = NULL ;
struct V_21 * V_21 ;
T_7 * V_217 = NULL ;
int V_234 = 0 ;
int V_235 = 0 ;
bool V_236 = ( V_136 & V_237 ) &&
( V_175 & V_238 ) ;
int V_239 = 0 ;
bool V_240 ;
V_241:
V_240 = false ;
F_272 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_204 ;
if ( F_100 ( V_242 ) && V_234 &&
! F_260 ( V_214 , V_169 , V_217 ) )
continue;
if ( F_273 () &&
( V_136 & V_222 ) &&
! F_274 ( V_21 , V_175 ) )
continue;
if ( V_136 & V_243 ) {
if ( ! F_264 ( V_233 -> V_180 , V_21 ) )
break;
if ( F_237 ( V_186 , & V_21 -> V_58 ) ) {
V_239 ++ ;
continue;
}
}
if ( V_236 && ! F_275 ( V_21 ) )
continue;
V_204 = V_21 -> V_177 [ V_136 & V_244 ] ;
if ( ! F_232 ( V_21 , V_42 , V_204 ,
V_233 -> V_205 , V_136 ) ) {
int V_22 ;
F_276 ( V_139 < V_245 ) ;
if ( V_136 & V_139 )
goto V_246;
if ( F_100 ( V_242 ) &&
! V_235 && V_247 > 1 ) {
V_217 = F_256 ( V_214 , V_136 ) ;
V_234 = 1 ;
V_235 = 1 ;
}
if ( V_248 == 0 ||
! F_265 ( V_233 -> V_180 , V_21 ) )
goto V_249;
if ( F_100 ( V_242 ) && V_234 &&
! F_260 ( V_214 , V_169 , V_217 ) )
continue;
V_22 = F_277 ( V_21 , V_175 , V_42 ) ;
switch ( V_22 ) {
case V_250 :
continue;
case V_251 :
continue;
default:
if ( F_232 ( V_21 , V_42 , V_204 ,
V_233 -> V_205 , V_136 ) )
goto V_246;
if ( ( ( V_136 & V_244 ) == V_252 ) ||
V_22 == V_253 )
goto V_249;
continue;
}
}
V_246:
V_14 = F_234 ( V_233 -> V_180 , V_21 , V_42 ,
V_175 , V_233 -> V_15 ) ;
if ( V_14 ) {
if ( F_172 ( V_14 , V_42 , V_175 , V_136 ) )
goto V_246;
return V_14 ;
}
V_249:
if ( F_100 ( V_242 ) && V_234 )
F_262 ( V_214 , V_169 ) ;
}
if ( V_136 & V_243 ) {
V_136 &= ~ V_243 ;
if ( V_239 ) {
V_240 = true ;
F_267 ( V_233 -> V_180 ) ;
}
if ( V_247 > 1 )
V_240 = true ;
}
if ( F_14 ( F_100 ( V_242 ) && V_234 ) ) {
V_234 = 0 ;
V_240 = true ;
}
if ( V_240 )
goto V_241;
return NULL ;
}
static inline bool F_278 ( void )
{
bool V_22 = false ;
#if V_254 > 8
V_22 = F_259 () ;
#endif
return V_22 ;
}
void F_279 ( T_4 V_175 , int V_42 , const char * V_255 , ... )
{
unsigned int V_256 = V_257 ;
if ( ( V_175 & V_258 ) || ! F_280 ( & V_259 ) ||
F_170 () > 0 )
return;
if ( ! ( V_175 & V_260 ) )
if ( F_281 ( V_261 ) ||
( V_38 -> V_58 & ( V_262 | V_263 ) ) )
V_256 &= ~ V_257 ;
if ( F_259 () || ! ( V_175 & V_195 ) )
V_256 &= ~ V_257 ;
if ( V_255 ) {
struct V_264 V_265 ;
T_8 args ;
va_start ( args , V_255 ) ;
V_265 . V_255 = V_255 ;
V_265 . V_266 = & args ;
F_282 ( L_22 , & V_265 ) ;
va_end ( args ) ;
}
F_282 ( L_23 ,
V_38 -> V_39 , V_42 , V_175 ) ;
F_34 () ;
if ( ! F_278 () )
F_283 ( V_256 ) ;
}
static inline struct V_14 *
F_284 ( T_4 V_175 , unsigned int V_42 ,
const struct V_232 * V_233 , unsigned long * V_267 )
{
struct V_14 * V_14 ;
* V_267 = 0 ;
if ( ! F_285 ( & V_268 ) ) {
* V_267 = 1 ;
F_286 ( 1 ) ;
return NULL ;
}
V_14 = F_271 ( V_175 | V_269 , V_42 ,
V_270 | V_222 , V_233 ) ;
if ( V_14 )
goto V_35;
if ( ! ( V_175 & V_183 ) ) {
if ( V_38 -> V_58 & V_271 )
goto V_35;
if ( V_42 > V_272 )
goto V_35;
if ( V_233 -> V_273 < V_274 )
goto V_35;
if ( ! ( V_175 & V_275 ) ) {
* V_267 = 1 ;
goto V_35;
}
if ( F_5 () )
goto V_35;
if ( V_175 & V_276 )
goto V_35;
}
if ( F_287 ( V_233 -> V_214 , V_175 , V_42 , V_233 -> V_277 , false )
|| F_235 ( V_175 & V_183 ) )
* V_267 = 1 ;
V_35:
F_288 ( & V_268 ) ;
return V_14 ;
}
static struct V_14 *
F_289 ( T_4 V_175 , unsigned int V_42 ,
int V_136 , const struct V_232 * V_233 ,
enum V_278 V_196 , int * V_279 ,
bool * V_280 )
{
unsigned long V_281 ;
struct V_14 * V_14 ;
if ( ! V_42 )
return NULL ;
V_38 -> V_58 |= V_262 ;
V_281 = F_290 ( V_175 , V_42 , V_136 , V_233 ,
V_196 , V_279 ) ;
V_38 -> V_58 &= ~ V_262 ;
switch ( V_281 ) {
case V_282 :
* V_280 = true ;
case V_283 :
return NULL ;
default:
break;
}
F_291 ( V_284 ) ;
V_14 = F_271 ( V_175 , V_42 ,
V_136 & ~ V_139 , V_233 ) ;
if ( V_14 ) {
struct V_21 * V_21 = F_25 ( V_14 ) ;
V_21 -> V_285 = false ;
F_292 ( V_21 , V_42 , true ) ;
F_291 ( V_286 ) ;
return V_14 ;
}
F_291 ( V_287 ) ;
F_155 () ;
return NULL ;
}
static inline struct V_14 *
F_289 ( T_4 V_175 , unsigned int V_42 ,
int V_136 , const struct V_232 * V_233 ,
enum V_278 V_196 , int * V_279 ,
bool * V_280 )
{
return NULL ;
}
static int
F_293 ( T_4 V_175 , unsigned int V_42 ,
const struct V_232 * V_233 )
{
struct V_288 V_288 ;
int V_289 ;
F_155 () ;
F_294 () ;
V_38 -> V_58 |= V_262 ;
F_295 ( V_175 ) ;
V_288 . V_290 = 0 ;
V_38 -> V_288 = & V_288 ;
V_289 = F_296 ( V_233 -> V_214 , V_42 , V_175 ,
V_233 -> V_277 ) ;
V_38 -> V_288 = NULL ;
F_297 () ;
V_38 -> V_58 &= ~ V_262 ;
F_155 () ;
return V_289 ;
}
static inline struct V_14 *
F_298 ( T_4 V_175 , unsigned int V_42 ,
int V_136 , const struct V_232 * V_233 ,
unsigned long * V_267 )
{
struct V_14 * V_14 = NULL ;
bool V_291 = false ;
* V_267 = F_293 ( V_175 , V_42 , V_233 ) ;
if ( F_14 ( ! ( * V_267 ) ) )
return NULL ;
if ( F_100 ( V_242 ) )
F_263 ( V_233 -> V_214 ) ;
V_292:
V_14 = F_271 ( V_175 , V_42 ,
V_136 & ~ V_139 , V_233 ) ;
if ( ! V_14 && ! V_291 ) {
F_205 ( NULL ) ;
V_291 = true ;
goto V_292;
}
return V_14 ;
}
static inline struct V_14 *
F_299 ( T_4 V_175 , unsigned int V_42 ,
const struct V_232 * V_233 )
{
struct V_14 * V_14 ;
do {
V_14 = F_271 ( V_175 , V_42 ,
V_139 , V_233 ) ;
if ( ! V_14 && V_175 & V_183 )
F_300 ( V_233 -> V_180 , V_293 ,
V_37 / 50 ) ;
} while ( ! V_14 && ( V_175 & V_183 ) );
return V_14 ;
}
static void F_301 ( unsigned int V_42 , const struct V_232 * V_233 )
{
struct V_225 * V_169 ;
struct V_21 * V_21 ;
F_272 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_302 ( V_21 , V_42 , F_303 ( V_233 -> V_180 ) ) ;
}
static inline int
F_304 ( T_4 V_175 )
{
int V_136 = V_252 | V_222 ;
const bool V_294 = ! ( V_175 & ( V_195 | V_295 ) ) ;
F_276 ( V_296 != ( V_297 T_4 ) V_209 ) ;
V_136 |= ( V_297 int ) ( V_175 & V_296 ) ;
if ( V_294 ) {
if ( ! ( V_175 & V_260 ) )
V_136 |= V_210 ;
V_136 &= ~ V_222 ;
} else if ( F_14 ( F_305 ( V_38 ) ) && ! F_259 () )
V_136 |= V_210 ;
if ( F_195 ( ! ( V_175 & V_260 ) ) ) {
if ( V_175 & V_298 )
V_136 |= V_139 ;
else if ( F_306 () && ( V_38 -> V_58 & V_262 ) )
V_136 |= V_139 ;
else if ( ! F_259 () &&
( ( V_38 -> V_58 & V_262 ) ||
F_14 ( F_281 ( V_261 ) ) ) )
V_136 |= V_139 ;
}
#ifdef F_253
if ( F_307 ( V_175 ) == V_111 )
V_136 |= V_211 ;
#endif
return V_136 ;
}
bool F_308 ( T_4 V_175 )
{
return ! ! ( F_304 ( V_175 ) & V_139 ) ;
}
static inline struct V_14 *
F_309 ( T_4 V_175 , unsigned int V_42 ,
struct V_232 * V_233 )
{
const T_4 V_299 = V_175 & V_195 ;
struct V_14 * V_14 = NULL ;
int V_136 ;
unsigned long V_300 = 0 ;
unsigned long V_267 ;
enum V_278 V_301 = V_302 ;
bool V_280 = false ;
int V_279 = V_303 ;
if ( V_42 >= V_52 ) {
F_235 ( ! ( V_175 & V_258 ) ) ;
return NULL ;
}
if ( F_100 ( V_242 ) && ( V_175 & V_276 ) && ! V_299 )
goto V_304;
V_292:
if ( ! ( V_175 & V_295 ) )
F_301 ( V_42 , V_233 ) ;
V_136 = F_304 ( V_175 ) ;
if ( ! ( V_136 & V_222 ) && ! V_233 -> V_277 ) {
struct V_225 * V_305 ;
V_305 = F_310 ( V_233 -> V_214 ,
V_233 -> V_273 , NULL , & V_233 -> V_180 ) ;
V_233 -> V_205 = F_311 ( V_305 ) ;
}
V_14 = F_271 ( V_175 , V_42 ,
V_136 & ~ V_139 , V_233 ) ;
if ( V_14 )
goto V_306;
if ( V_136 & V_139 ) {
V_233 -> V_214 = F_312 ( F_313 () , V_175 ) ;
V_14 = F_299 ( V_175 , V_42 , V_233 ) ;
if ( V_14 ) {
goto V_306;
}
}
if ( ! V_299 ) {
F_235 ( V_175 & V_183 ) ;
goto V_304;
}
if ( V_38 -> V_58 & V_262 )
goto V_304;
if ( F_281 ( V_261 ) && ! ( V_175 & V_183 ) )
goto V_304;
V_14 = F_289 ( V_175 , V_42 , V_136 , V_233 ,
V_301 ,
& V_279 ,
& V_280 ) ;
if ( V_14 )
goto V_306;
if ( ( V_175 & V_307 ) == V_307 ) {
if ( V_280 )
goto V_304;
if ( V_279 == V_308 )
goto V_304;
if ( V_279 == V_309
&& ! ( V_38 -> V_58 & V_310 ) )
goto V_304;
}
if ( ( V_175 & V_307 ) != V_307 ||
( V_38 -> V_58 & V_310 ) )
V_301 = V_311 ;
V_14 = F_298 ( V_175 , V_42 , V_136 , V_233 ,
& V_267 ) ;
if ( V_14 )
goto V_306;
if ( V_175 & V_312 )
goto V_313;
V_300 += V_267 ;
if ( ( V_267 && V_42 <= V_272 ) ||
( ( V_175 & V_314 ) && V_300 < ( 1 << V_42 ) ) ) {
F_300 ( V_233 -> V_180 , V_293 , V_37 / 50 ) ;
goto V_292;
}
V_14 = F_284 ( V_175 , V_42 , V_233 , & V_267 ) ;
if ( V_14 )
goto V_306;
if ( V_267 )
goto V_292;
V_313:
V_14 = F_289 ( V_175 , V_42 , V_136 ,
V_233 , V_301 ,
& V_279 ,
& V_280 ) ;
if ( V_14 )
goto V_306;
V_304:
F_279 ( V_175 , V_42 , NULL ) ;
V_306:
return V_14 ;
}
struct V_14 *
F_314 ( T_4 V_175 , unsigned int V_42 ,
struct V_214 * V_214 , T_7 * V_277 )
{
struct V_225 * V_305 ;
struct V_14 * V_14 = NULL ;
unsigned int V_315 ;
int V_136 = V_237 | V_222 | V_243 ;
T_4 V_316 ;
struct V_232 V_233 = {
. V_273 = F_315 ( V_175 ) ,
. V_277 = V_277 ,
. V_15 = F_307 ( V_175 ) ,
} ;
V_175 &= V_3 ;
F_316 ( V_175 ) ;
F_317 ( V_175 & V_195 ) ;
if ( F_243 ( V_175 , V_42 ) )
return NULL ;
if ( F_14 ( ! V_214 -> V_227 -> V_21 ) )
return NULL ;
if ( F_100 ( F_253 ) && V_233 . V_15 == V_111 )
V_136 |= V_211 ;
V_317:
V_315 = F_318 () ;
V_233 . V_214 = V_214 ;
V_305 = F_310 ( V_233 . V_214 , V_233 . V_273 ,
V_233 . V_277 ? : & V_223 ,
& V_233 . V_180 ) ;
if ( ! V_233 . V_180 )
goto V_35;
V_233 . V_205 = F_311 ( V_305 ) ;
V_316 = V_175 | V_269 ;
V_14 = F_271 ( V_316 , V_42 , V_136 , & V_233 ) ;
if ( F_14 ( ! V_14 ) ) {
V_316 = F_319 ( V_175 ) ;
V_14 = F_309 ( V_316 , V_42 , & V_233 ) ;
}
if ( V_318 && V_14 )
F_320 ( V_14 , V_42 , V_175 ) ;
F_321 ( V_14 , V_42 , V_316 , V_233 . V_15 ) ;
V_35:
if ( F_14 ( ! V_14 && F_322 ( V_315 ) ) )
goto V_317;
return V_14 ;
}
unsigned long F_323 ( T_4 V_175 , unsigned int V_42 )
{
struct V_14 * V_14 ;
F_74 ( ( V_175 & V_193 ) != 0 ) ;
V_14 = F_324 ( V_175 , V_42 ) ;
if ( ! V_14 )
return 0 ;
return ( unsigned long ) F_127 ( V_14 ) ;
}
unsigned long F_325 ( T_4 V_175 )
{
return F_323 ( V_175 | V_137 , 0 ) ;
}
void F_139 ( struct V_14 * V_14 , unsigned int V_42 )
{
if ( F_326 ( V_14 ) ) {
if ( V_42 == 0 )
F_219 ( V_14 , false ) ;
else
F_37 ( V_14 , V_42 ) ;
}
}
void V_206 ( unsigned long V_319 , unsigned int V_42 )
{
if ( V_319 != 0 ) {
F_74 ( ! F_327 ( ( void * ) V_319 ) ) ;
F_139 ( F_228 ( ( void * ) V_319 ) , V_42 ) ;
}
}
static struct V_14 * F_328 ( struct V_320 * V_321 ,
T_4 V_175 )
{
struct V_14 * V_14 = NULL ;
T_4 V_322 = V_175 ;
#if ( V_101 < V_323 )
V_175 |= V_138 | V_258 | V_312 |
V_260 ;
V_14 = F_329 ( V_324 , V_175 ,
V_325 ) ;
V_321 -> V_132 = V_14 ? V_323 : V_101 ;
#endif
if ( F_14 ( ! V_14 ) )
V_14 = F_329 ( V_324 , V_322 , 0 ) ;
V_321 -> V_266 = V_14 ? F_127 ( V_14 ) : NULL ;
return V_14 ;
}
void * F_330 ( struct V_320 * V_321 ,
unsigned int V_326 , T_4 V_175 )
{
unsigned int V_132 = V_101 ;
struct V_14 * V_14 ;
int V_327 ;
if ( F_14 ( ! V_321 -> V_266 ) ) {
V_328:
V_14 = F_328 ( V_321 , V_175 ) ;
if ( ! V_14 )
return NULL ;
#if ( V_101 < V_323 )
V_132 = V_321 -> V_132 ;
#endif
F_331 ( V_132 - 1 , & V_14 -> V_75 ) ;
V_321 -> V_329 = F_332 ( V_14 ) ;
V_321 -> V_330 = V_132 ;
V_321 -> V_327 = V_132 ;
}
V_327 = V_321 -> V_327 - V_326 ;
if ( F_14 ( V_327 < 0 ) ) {
V_14 = F_228 ( V_321 -> V_266 ) ;
if ( ! F_333 ( V_321 -> V_330 , & V_14 -> V_75 ) )
goto V_328;
#if ( V_101 < V_323 )
V_132 = V_321 -> V_132 ;
#endif
F_161 ( & V_14 -> V_75 , V_132 ) ;
V_321 -> V_330 = V_132 ;
V_327 = V_132 - V_326 ;
}
V_321 -> V_330 -- ;
V_321 -> V_327 = V_327 ;
return V_321 -> V_266 + V_327 ;
}
void F_334 ( void * V_319 )
{
struct V_14 * V_14 = F_335 ( V_319 ) ;
if ( F_14 ( F_326 ( V_14 ) ) )
F_37 ( V_14 , F_38 ( V_14 ) ) ;
}
struct V_14 * F_336 ( T_4 V_175 , unsigned int V_42 )
{
struct V_14 * V_14 ;
struct V_77 * V_331 = NULL ;
if ( ! F_337 ( V_175 , & V_331 , V_42 ) )
return NULL ;
V_14 = F_324 ( V_175 , V_42 ) ;
F_338 ( V_14 , V_331 , V_42 ) ;
return V_14 ;
}
struct V_14 * F_339 ( int V_9 , T_4 V_175 , unsigned int V_42 )
{
struct V_14 * V_14 ;
struct V_77 * V_331 = NULL ;
if ( ! F_337 ( V_175 , & V_331 , V_42 ) )
return NULL ;
V_14 = F_329 ( V_9 , V_175 , V_42 ) ;
F_338 ( V_14 , V_331 , V_42 ) ;
return V_14 ;
}
void F_340 ( struct V_14 * V_14 , unsigned int V_42 )
{
F_341 ( V_14 , V_42 ) ;
F_139 ( V_14 , V_42 ) ;
}
void F_342 ( unsigned long V_319 , unsigned int V_42 )
{
if ( V_319 != 0 ) {
F_74 ( ! F_327 ( ( void * ) V_319 ) ) ;
F_340 ( F_228 ( ( void * ) V_319 ) , V_42 ) ;
}
}
static void * F_343 ( unsigned long V_319 , unsigned V_42 , T_9 V_132 )
{
if ( V_319 ) {
unsigned long V_332 = V_319 + ( V_101 << V_42 ) ;
unsigned long V_333 = V_319 + F_344 ( V_132 ) ;
F_225 ( F_228 ( ( void * ) V_319 ) , V_42 ) ;
while ( V_333 < V_332 ) {
F_345 ( V_333 ) ;
V_333 += V_101 ;
}
}
return ( void * ) V_319 ;
}
void * F_346 ( T_9 V_132 , T_4 V_175 )
{
unsigned int V_42 = F_347 ( V_132 ) ;
unsigned long V_319 ;
V_319 = F_323 ( V_175 , V_42 ) ;
return F_343 ( V_319 , V_42 , V_132 ) ;
}
void * T_2 F_348 ( int V_9 , T_9 V_132 , T_4 V_175 )
{
unsigned V_42 = F_347 ( V_132 ) ;
struct V_14 * V_45 = F_329 ( V_9 , V_175 , V_42 ) ;
if ( ! V_45 )
return NULL ;
return F_343 ( ( unsigned long ) F_127 ( V_45 ) , V_42 , V_132 ) ;
}
void F_349 ( void * V_334 , T_9 V_132 )
{
unsigned long V_319 = ( unsigned long ) V_334 ;
unsigned long V_97 = V_319 + F_344 ( V_132 ) ;
while ( V_319 < V_97 ) {
F_345 ( V_319 ) ;
V_319 += V_101 ;
}
}
static unsigned long F_350 ( int V_327 )
{
struct V_225 * V_169 ;
struct V_21 * V_21 ;
unsigned long V_335 = 0 ;
struct V_214 * V_214 = F_312 ( F_313 () , V_336 ) ;
F_351 (zone, z, zonelist, offset) {
unsigned long V_132 = V_21 -> V_104 ;
unsigned long V_130 = F_269 ( V_21 ) ;
if ( V_132 > V_130 )
V_335 += V_132 - V_130 ;
}
return V_335 ;
}
unsigned long F_352 ( void )
{
return F_350 ( F_315 ( V_337 ) ) ;
}
unsigned long F_353 ( void )
{
return F_350 ( F_315 ( V_338 ) ) ;
}
static inline void F_354 ( struct V_21 * V_21 )
{
if ( F_100 ( V_242 ) )
F_31 ( L_24 , F_22 ( V_21 ) ) ;
}
void F_355 ( struct V_339 * V_340 )
{
V_340 -> V_341 = V_342 ;
V_340 -> V_343 = F_356 ( V_344 ) ;
V_340 -> V_345 = F_356 ( V_161 ) ;
V_340 -> V_346 = F_357 () ;
V_340 -> V_347 = V_348 ;
V_340 -> V_349 = F_358 () ;
V_340 -> V_350 = V_101 ;
}
void F_359 ( struct V_339 * V_340 , int V_9 )
{
int V_351 ;
unsigned long V_104 = 0 ;
T_1 * V_5 = F_8 ( V_9 ) ;
for ( V_351 = 0 ; V_351 < V_94 ; V_351 ++ )
V_104 += V_5 -> V_95 [ V_351 ] . V_104 ;
V_340 -> V_341 = V_104 ;
V_340 -> V_343 = F_360 ( V_9 , V_344 ) ;
V_340 -> V_345 = F_360 ( V_9 , V_161 ) ;
#ifdef F_361
V_340 -> V_347 = V_5 -> V_95 [ V_352 ] . V_104 ;
V_340 -> V_349 = F_88 ( & V_5 -> V_95 [ V_352 ] ,
V_161 ) ;
#else
V_340 -> V_347 = 0 ;
V_340 -> V_349 = 0 ;
#endif
V_340 -> V_350 = V_101 ;
}
bool F_362 ( unsigned int V_58 , int V_9 )
{
bool V_22 = false ;
unsigned int V_315 ;
if ( ! ( V_58 & V_257 ) )
goto V_35;
do {
V_315 = F_318 () ;
V_22 = ! F_261 ( V_9 , V_223 ) ;
} while ( F_322 ( V_315 ) );
V_35:
return V_22 ;
}
static void F_363 ( unsigned char type )
{
static const char V_353 [ V_354 ] = {
[ V_18 ] = 'U' ,
[ V_149 ] = 'E' ,
[ V_111 ] = 'M' ,
[ V_156 ] = 'R' ,
#ifdef F_253
[ V_128 ] = 'C' ,
#endif
#ifdef F_364
[ V_355 ] = 'I' ,
#endif
} ;
char V_356 [ V_354 + 1 ] ;
char * V_45 = V_356 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_354 ; V_43 ++ ) {
if ( type & ( 1 << V_43 ) )
* V_45 ++ = V_353 [ V_43 ] ;
}
* V_45 = '\0' ;
F_31 ( L_25 , V_356 ) ;
}
void F_365 ( unsigned int V_256 )
{
unsigned long V_357 = 0 ;
int V_164 ;
struct V_21 * V_21 ;
F_202 (zone) {
if ( F_362 ( V_256 , F_22 ( V_21 ) ) )
continue;
F_206 (cpu)
V_357 += F_200 ( V_21 -> V_167 , V_164 ) -> V_80 . V_78 ;
}
F_31 ( L_26
L_27
L_28
L_29
L_30
L_31 ,
F_356 ( V_358 ) ,
F_356 ( V_359 ) ,
F_356 ( V_360 ) ,
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
F_356 ( V_344 ) ,
F_356 ( V_371 ) ,
F_356 ( V_372 ) ,
F_356 ( V_161 ) ,
V_357 ,
F_356 ( V_160 ) ) ;
F_202 (zone) {
int V_43 ;
if ( F_362 ( V_256 , F_22 ( V_21 ) ) )
continue;
V_357 = 0 ;
F_206 (cpu)
V_357 += F_200 ( V_21 -> V_167 , V_164 ) -> V_80 . V_78 ;
F_354 ( V_21 ) ;
F_31 ( L_32
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
V_21 -> V_28 ,
F_366 ( F_88 ( V_21 , V_161 ) ) ,
F_366 ( F_367 ( V_21 ) ) ,
F_366 ( F_231 ( V_21 ) ) ,
F_366 ( F_269 ( V_21 ) ) ,
F_366 ( F_88 ( V_21 , V_358 ) ) ,
F_366 ( F_88 ( V_21 , V_359 ) ) ,
F_366 ( F_88 ( V_21 , V_361 ) ) ,
F_366 ( F_88 ( V_21 , V_362 ) ) ,
F_366 ( F_88 ( V_21 , V_364 ) ) ,
F_366 ( F_88 ( V_21 , V_360 ) ) ,
F_366 ( F_88 ( V_21 , V_363 ) ) ,
F_366 ( V_21 -> V_373 ) ,
F_366 ( V_21 -> V_104 ) ,
F_366 ( F_88 ( V_21 , V_374 ) ) ,
F_366 ( F_88 ( V_21 , V_365 ) ) ,
F_366 ( F_88 ( V_21 , V_366 ) ) ,
F_366 ( F_88 ( V_21 , V_370 ) ) ,
F_366 ( F_88 ( V_21 , V_344 ) ) ,
F_366 ( F_88 ( V_21 , V_368 ) ) ,
F_366 ( F_88 ( V_21 , V_369 ) ) ,
F_88 ( V_21 , V_375 ) *
V_376 / 1024 ,
F_366 ( F_88 ( V_21 , V_371 ) ) ,
F_366 ( F_88 ( V_21 , V_367 ) ) ,
F_366 ( F_88 ( V_21 , V_372 ) ) ,
F_366 ( V_357 ) ,
F_366 ( F_368 ( V_21 -> V_167 -> V_80 . V_78 ) ) ,
F_366 ( F_88 ( V_21 , V_160 ) ) ,
F_366 ( F_88 ( V_21 , V_377 ) ) ,
F_366 ( F_88 ( V_21 , V_85 ) ) ,
( ! F_369 ( V_21 ) ? L_64 : L_65 )
) ;
F_31 ( L_66 ) ;
for ( V_43 = 0 ; V_43 < V_94 ; V_43 ++ )
F_31 ( L_67 , V_21 -> V_212 [ V_43 ] ) ;
F_31 ( L_63 ) ;
}
F_202 (zone) {
unsigned long V_378 [ V_52 ] , V_58 , V_42 , V_379 = 0 ;
unsigned char V_353 [ V_52 ] ;
if ( F_362 ( V_256 , F_22 ( V_21 ) ) )
continue;
F_354 ( V_21 ) ;
F_31 ( L_68 , V_21 -> V_28 ) ;
F_212 ( & V_21 -> V_84 , V_58 ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
struct V_68 * V_131 = & V_21 -> V_68 [ V_42 ] ;
int type ;
V_378 [ V_42 ] = V_131 -> V_69 ;
V_379 += V_378 [ V_42 ] << V_42 ;
V_353 [ V_42 ] = 0 ;
for ( type = 0 ; type < V_354 ; type ++ ) {
if ( ! F_90 ( & V_131 -> V_72 [ type ] ) )
V_353 [ V_42 ] |= 1 << type ;
}
}
F_218 ( & V_21 -> V_84 , V_58 ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
F_31 ( L_69 , V_378 [ V_42 ] , F_366 ( 1UL ) << V_42 ) ;
if ( V_378 [ V_42 ] )
F_363 ( V_353 [ V_42 ] ) ;
}
F_31 ( L_70 , F_366 ( V_379 ) ) ;
}
F_370 () ;
F_31 ( L_71 , F_356 ( V_380 ) ) ;
F_371 () ;
}
static void F_372 ( struct V_21 * V_21 , struct V_225 * V_225 )
{
V_225 -> V_21 = V_21 ;
V_225 -> F_303 = F_303 ( V_21 ) ;
}
static int F_373 ( T_1 * V_5 , struct V_214 * V_214 ,
int V_381 )
{
struct V_21 * V_21 ;
enum V_351 V_351 = V_94 ;
do {
V_351 -- ;
V_21 = V_5 -> V_95 + V_351 ;
if ( F_157 ( V_21 ) ) {
F_372 ( V_21 ,
& V_214 -> V_227 [ V_381 ++ ] ) ;
F_374 ( V_351 ) ;
}
} while ( V_351 );
return V_381 ;
}
static int F_375 ( char * V_382 )
{
if ( * V_382 == 'd' || * V_382 == 'D' ) {
V_383 = V_384 ;
} else if ( * V_382 == 'n' || * V_382 == 'N' ) {
V_383 = V_385 ;
} else if ( * V_382 == 'z' || * V_382 == 'Z' ) {
V_383 = V_386 ;
} else {
F_31 ( V_387
L_72
L_73 , V_382 ) ;
return - V_48 ;
}
return 0 ;
}
static T_3 int F_376 ( char * V_382 )
{
int V_22 ;
if ( ! V_382 )
return 0 ;
V_22 = F_375 ( V_382 ) ;
if ( V_22 == 0 )
F_377 ( V_388 , V_382 , V_389 ) ;
return V_22 ;
}
int F_378 ( struct V_390 * V_391 , int V_392 ,
void T_10 * V_393 , T_9 * V_394 ,
T_11 * V_395 )
{
char V_396 [ V_389 ] ;
int V_22 ;
static F_379 ( V_397 ) ;
F_380 ( & V_397 ) ;
if ( V_392 ) {
if ( strlen ( ( char * ) V_391 -> V_114 ) >= V_389 ) {
V_22 = - V_48 ;
goto V_35;
}
strcpy ( V_396 , ( char * ) V_391 -> V_114 ) ;
}
V_22 = F_381 ( V_391 , V_392 , V_393 , V_394 , V_395 ) ;
if ( V_22 )
goto V_35;
if ( V_392 ) {
int V_398 = V_383 ;
V_22 = F_375 ( ( char * ) V_391 -> V_114 ) ;
if ( V_22 ) {
strncpy ( ( char * ) V_391 -> V_114 , V_396 ,
V_389 ) ;
V_383 = V_398 ;
} else if ( V_398 != V_383 ) {
F_380 ( & V_399 ) ;
F_382 ( NULL , NULL ) ;
F_288 ( & V_399 ) ;
}
}
V_35:
F_288 ( & V_397 ) ;
return V_22 ;
}
static int F_383 ( int V_107 , T_7 * V_400 )
{
int V_226 , V_340 ;
int V_401 = V_402 ;
int V_403 = V_324 ;
const struct V_120 * V_356 = F_150 ( 0 ) ;
if ( ! F_261 ( V_107 , * V_400 ) ) {
F_384 ( V_107 , * V_400 ) ;
return V_107 ;
}
F_163 (n, N_MEMORY) {
if ( F_261 ( V_226 , * V_400 ) )
continue;
V_340 = F_266 ( V_107 , V_226 ) ;
V_340 += ( V_226 < V_107 ) ;
V_356 = F_150 ( V_226 ) ;
if ( ! F_151 ( V_356 ) )
V_340 += V_404 ;
V_340 *= ( V_405 * V_406 ) ;
V_340 += V_407 [ V_226 ] ;
if ( V_340 < V_401 ) {
V_401 = V_340 ;
V_403 = V_226 ;
}
}
if ( V_403 >= 0 )
F_384 ( V_403 , * V_400 ) ;
return V_403 ;
}
static void F_385 ( T_1 * V_5 , int V_107 )
{
int V_408 ;
struct V_214 * V_214 ;
V_214 = & V_5 -> V_409 [ 0 ] ;
for ( V_408 = 0 ; V_214 -> V_227 [ V_408 ] . V_21 != NULL ; V_408 ++ )
;
V_408 = F_373 ( F_8 ( V_107 ) , V_214 , V_408 ) ;
V_214 -> V_227 [ V_408 ] . V_21 = NULL ;
V_214 -> V_227 [ V_408 ] . F_303 = 0 ;
}
static void F_386 ( T_1 * V_5 )
{
int V_408 ;
struct V_214 * V_214 ;
V_214 = & V_5 -> V_409 [ 1 ] ;
V_408 = F_373 ( V_5 , V_214 , 0 ) ;
V_214 -> V_227 [ V_408 ] . V_21 = NULL ;
V_214 -> V_227 [ V_408 ] . F_303 = 0 ;
}
static void F_387 ( T_1 * V_5 , int V_410 )
{
int V_411 , V_408 , V_107 ;
int V_351 ;
struct V_21 * V_169 ;
struct V_214 * V_214 ;
V_214 = & V_5 -> V_409 [ 0 ] ;
V_411 = 0 ;
for ( V_351 = V_94 - 1 ; V_351 >= 0 ; V_351 -- ) {
for ( V_408 = 0 ; V_408 < V_410 ; V_408 ++ ) {
V_107 = V_412 [ V_408 ] ;
V_169 = & F_8 ( V_107 ) -> V_95 [ V_351 ] ;
if ( F_157 ( V_169 ) ) {
F_372 ( V_169 ,
& V_214 -> V_227 [ V_411 ++ ] ) ;
F_374 ( V_351 ) ;
}
}
}
V_214 -> V_227 [ V_411 ] . V_21 = NULL ;
V_214 -> V_227 [ V_411 ] . F_303 = 0 ;
}
static int F_388 ( void )
{
return V_385 ;
}
static int F_388 ( void )
{
return V_386 ;
}
static void F_389 ( void )
{
if ( V_383 == V_384 )
V_413 = F_388 () ;
else
V_413 = V_383 ;
}
static void F_390 ( T_1 * V_5 )
{
int V_408 , V_107 , V_414 ;
enum V_351 V_43 ;
T_7 V_415 ;
int V_416 , V_417 ;
struct V_214 * V_214 ;
int V_42 = V_413 ;
for ( V_43 = 0 ; V_43 < V_418 ; V_43 ++ ) {
V_214 = V_5 -> V_409 + V_43 ;
V_214 -> V_227 [ 0 ] . V_21 = NULL ;
V_214 -> V_227 [ 0 ] . F_303 = 0 ;
}
V_416 = V_5 -> V_115 ;
V_414 = V_247 ;
V_417 = V_416 ;
F_391 ( V_415 ) ;
memset ( V_412 , 0 , sizeof( V_412 ) ) ;
V_408 = 0 ;
while ( ( V_107 = F_383 ( V_416 , & V_415 ) ) >= 0 ) {
if ( F_266 ( V_416 , V_107 ) !=
F_266 ( V_416 , V_417 ) )
V_407 [ V_107 ] = V_414 ;
V_417 = V_107 ;
V_414 -- ;
if ( V_42 == V_385 )
F_385 ( V_5 , V_107 ) ;
else
V_412 [ V_408 ++ ] = V_107 ;
}
if ( V_42 == V_386 ) {
F_387 ( V_5 , V_408 ) ;
}
F_386 ( V_5 ) ;
}
static void F_392 ( T_1 * V_5 )
{
struct V_214 * V_214 ;
struct V_215 * V_216 ;
struct V_225 * V_169 ;
V_214 = & V_5 -> V_409 [ 0 ] ;
V_214 -> V_218 = V_216 = & V_214 -> V_419 ;
F_258 ( V_216 -> V_220 , V_221 ) ;
for ( V_169 = V_214 -> V_227 ; V_169 -> V_21 ; V_169 ++ )
V_216 -> V_228 [ V_169 - V_214 -> V_227 ] = F_393 ( V_169 ) ;
}
int F_394 ( int V_107 )
{
struct V_21 * V_21 ;
( void ) F_310 ( F_312 ( V_107 , V_336 ) ,
F_315 ( V_336 ) ,
NULL ,
& V_21 ) ;
return V_21 -> V_107 ;
}
static void F_389 ( void )
{
V_413 = V_386 ;
}
static void F_390 ( T_1 * V_5 )
{
int V_107 , V_416 ;
enum V_351 V_408 ;
struct V_214 * V_214 ;
V_416 = V_5 -> V_115 ;
V_214 = & V_5 -> V_409 [ 0 ] ;
V_408 = F_373 ( V_5 , V_214 , 0 ) ;
for ( V_107 = V_416 + 1 ; V_107 < V_406 ; V_107 ++ ) {
if ( ! F_395 ( V_107 ) )
continue;
V_408 = F_373 ( F_8 ( V_107 ) , V_214 , V_408 ) ;
}
for ( V_107 = 0 ; V_107 < V_416 ; V_107 ++ ) {
if ( ! F_395 ( V_107 ) )
continue;
V_408 = F_373 ( F_8 ( V_107 ) , V_214 , V_408 ) ;
}
V_214 -> V_227 [ V_408 ] . V_21 = NULL ;
V_214 -> V_227 [ V_408 ] . F_303 = 0 ;
}
static void F_392 ( T_1 * V_5 )
{
V_5 -> V_409 [ 0 ] . V_218 = NULL ;
}
static int F_396 ( void * V_114 )
{
int V_9 ;
int V_164 ;
T_1 * V_420 = V_114 ;
#ifdef V_242
memset ( V_407 , 0 , sizeof( V_407 ) ) ;
#endif
if ( V_420 && ! F_395 ( V_420 -> V_115 ) ) {
F_390 ( V_420 ) ;
F_392 ( V_420 ) ;
}
F_397 (nid) {
T_1 * V_5 = F_8 ( V_9 ) ;
F_390 ( V_5 ) ;
F_392 ( V_5 ) ;
}
F_398 (cpu) {
F_399 ( & F_400 ( V_421 , V_164 ) , 0 ) ;
#ifdef F_401
if ( F_402 ( V_164 ) )
F_403 ( V_164 , F_394 ( F_404 ( V_164 ) ) ) ;
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
void T_13 F_382 ( T_1 * V_5 , struct V_21 * V_21 )
{
F_389 () ;
if ( V_422 == V_423 ) {
F_405 () ;
} else {
#ifdef F_408
if ( V_21 )
F_409 ( V_21 ) ;
#endif
F_410 ( F_396 , V_5 , NULL ) ;
}
V_424 = F_353 () ;
if ( V_424 < ( V_127 * V_354 ) )
V_16 = 1 ;
else
V_16 = 0 ;
F_158 ( L_74
L_75 ,
V_247 ,
V_425 [ V_413 ] ,
V_16 ? L_76 : L_4 ,
V_424 ) ;
#ifdef V_242
F_158 ( L_77 , V_426 [ V_427 ] ) ;
#endif
}
static inline unsigned long F_411 ( unsigned long V_151 )
{
unsigned long V_132 = 1 ;
V_151 /= V_428 ;
while ( V_132 < V_151 )
V_132 <<= 1 ;
V_132 = F_76 ( V_132 , 4096UL ) ;
return F_156 ( V_132 , 4UL ) ;
}
static inline unsigned long F_411 ( unsigned long V_151 )
{
return 4096UL ;
}
static inline unsigned long F_412 ( unsigned long V_132 )
{
return F_413 ( ~ V_132 ) ;
}
static int F_414 ( unsigned long V_25 , unsigned long V_98 )
{
unsigned long V_8 ;
for ( V_8 = V_25 ; V_8 < V_98 ; V_8 ++ ) {
if ( ! F_24 ( V_8 ) || F_415 ( F_110 ( V_8 ) ) )
return 1 ;
}
return 0 ;
}
static void F_416 ( struct V_21 * V_21 )
{
unsigned long V_25 , V_8 , V_98 , V_429 ;
struct V_14 * V_14 ;
unsigned long V_430 ;
int V_431 ;
int V_432 ;
V_25 = V_21 -> V_26 ;
V_98 = F_112 ( V_21 ) ;
V_25 = F_417 ( V_25 , V_127 ) ;
V_431 = F_417 ( F_367 ( V_21 ) , V_127 ) >>
V_67 ;
V_431 = F_76 ( 2 , V_431 ) ;
V_432 = V_21 -> V_433 ;
if ( V_431 == V_432 )
return;
V_21 -> V_433 = V_431 ;
for ( V_8 = V_25 ; V_8 < V_98 ; V_8 += V_127 ) {
if ( ! F_10 ( V_8 , F_22 ( V_21 ) ) )
return;
if ( ! F_116 ( V_8 ) )
continue;
V_14 = F_110 ( V_8 ) ;
if ( F_183 ( V_14 ) != F_22 ( V_21 ) )
continue;
V_430 = F_94 ( V_14 ) ;
if ( V_431 > 0 ) {
V_429 = F_76 ( V_8 + V_127 , V_98 ) ;
if ( F_414 ( V_8 , V_429 ) )
continue;
if ( V_430 == V_156 ) {
V_431 -- ;
continue;
}
if ( V_430 == V_111 ) {
F_13 ( V_14 ,
V_156 ) ;
F_185 ( V_21 , V_14 ,
V_156 ) ;
V_431 -- ;
continue;
}
} else if ( ! V_432 ) {
break;
}
if ( V_430 == V_156 ) {
F_13 ( V_14 , V_111 ) ;
F_185 ( V_21 , V_14 , V_111 ) ;
}
}
}
void T_2 F_418 ( unsigned long V_132 , int V_9 , unsigned long V_21 ,
unsigned long V_25 , enum V_434 V_435 )
{
T_1 * V_5 = F_8 ( V_9 ) ;
unsigned long V_98 = V_25 + V_132 ;
unsigned long V_8 ;
struct V_21 * V_169 ;
unsigned long V_11 = 0 ;
if ( V_436 < V_98 - 1 )
V_436 = V_98 - 1 ;
V_169 = & V_5 -> V_95 [ V_21 ] ;
for ( V_8 = V_25 ; V_8 < V_98 ; V_8 ++ ) {
if ( V_435 == V_437 ) {
if ( ! F_419 ( V_8 ) )
continue;
if ( ! F_143 ( V_8 , V_9 ) )
continue;
if ( ! F_11 ( V_5 , V_8 , V_98 ,
& V_11 ) )
break;
}
if ( ! ( V_8 & ( V_127 - 1 ) ) ) {
struct V_14 * V_14 = F_110 ( V_8 ) ;
F_102 ( V_14 , V_8 , V_21 , V_9 ) ;
F_13 ( V_14 , V_111 ) ;
} else {
F_109 ( V_8 , V_21 , V_9 ) ;
}
}
}
static void T_2 F_420 ( struct V_21 * V_21 )
{
unsigned int V_42 , V_173 ;
F_215 (order, t) {
F_56 ( & V_21 -> V_68 [ V_42 ] . V_72 [ V_173 ] ) ;
V_21 -> V_68 [ V_42 ] . V_69 = 0 ;
}
}
static int F_421 ( struct V_21 * V_21 )
{
#ifdef F_422
int V_163 ;
V_163 = V_21 -> V_104 / 1024 ;
if ( V_163 * V_101 > 512 * 1024 )
V_163 = ( 512 * 1024 ) / V_101 ;
V_163 /= 4 ;
if ( V_163 < 1 )
V_163 = 1 ;
V_163 = F_423 ( V_163 + V_163 / 2 ) - 1 ;
return V_163 ;
#else
return 0 ;
#endif
}
static void F_424 ( struct V_79 * V_80 , unsigned long V_130 ,
unsigned long V_163 )
{
V_80 -> V_163 = 1 ;
F_44 () ;
V_80 -> V_130 = V_130 ;
F_44 () ;
V_80 -> V_163 = V_163 ;
}
static void F_425 ( struct V_165 * V_45 , unsigned long V_163 )
{
F_424 ( & V_45 -> V_80 , 6 * V_163 , F_156 ( 1UL , 1 * V_163 ) ) ;
}
static void F_426 ( struct V_165 * V_45 )
{
struct V_79 * V_80 ;
int V_15 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_80 = & V_45 -> V_80 ;
V_80 -> V_78 = 0 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ )
F_56 ( & V_80 -> V_88 [ V_15 ] ) ;
}
static void F_399 ( struct V_165 * V_45 , unsigned long V_163 )
{
F_426 ( V_45 ) ;
F_425 ( V_45 , V_163 ) ;
}
static void F_427 ( struct V_165 * V_45 ,
unsigned long V_130 )
{
unsigned long V_163 = F_156 ( 1UL , V_130 / 4 ) ;
if ( ( V_130 / 4 ) > ( V_12 * 8 ) )
V_163 = V_12 * 8 ;
F_424 ( & V_45 -> V_80 , V_130 , V_163 ) ;
}
static void F_428 ( struct V_21 * V_21 ,
struct V_165 * V_80 )
{
if ( V_438 )
F_427 ( V_80 ,
( V_21 -> V_104 /
V_438 ) ) ;
else
F_425 ( V_80 , F_421 ( V_21 ) ) ;
}
static void T_2 F_429 ( struct V_21 * V_21 , int V_164 )
{
struct V_165 * V_80 = F_200 ( V_21 -> V_167 , V_164 ) ;
F_426 ( V_80 ) ;
F_428 ( V_21 , V_80 ) ;
}
static void T_2 F_409 ( struct V_21 * V_21 )
{
int V_164 ;
V_21 -> V_167 = F_430 ( struct V_165 ) ;
F_398 (cpu)
F_429 ( V_21 , V_164 ) ;
}
void T_3 F_431 ( void )
{
struct V_21 * V_21 ;
F_202 (zone)
F_409 ( V_21 ) ;
}
static T_12 T_14
int F_432 ( struct V_21 * V_21 , unsigned long V_439 )
{
int V_43 ;
T_9 V_440 ;
V_21 -> F_411 =
F_411 ( V_439 ) ;
V_21 -> F_412 =
F_412 ( V_21 -> F_411 ) ;
V_440 = V_21 -> F_411
* sizeof( V_441 ) ;
if ( ! F_433 () ) {
V_21 -> V_442 = ( V_441 * )
F_434 (
V_440 , V_21 -> V_231 -> V_115 ) ;
} else {
V_21 -> V_442 = F_435 ( V_440 ) ;
}
if ( ! V_21 -> V_442 )
return - V_203 ;
for ( V_43 = 0 ; V_43 < V_21 -> F_411 ; ++ V_43 )
F_436 ( V_21 -> V_442 + V_43 ) ;
return 0 ;
}
static T_2 void F_437 ( struct V_21 * V_21 )
{
V_21 -> V_167 = & V_421 ;
if ( F_157 ( V_21 ) )
F_31 ( V_443 L_78 ,
V_21 -> V_28 , V_21 -> V_373 ,
F_421 ( V_21 ) ) ;
}
int T_2 F_438 ( struct V_21 * V_21 ,
unsigned long V_26 ,
unsigned long V_132 ,
enum V_434 V_435 )
{
struct V_444 * V_5 = V_21 -> V_231 ;
int V_22 ;
V_22 = F_432 ( V_21 , V_132 ) ;
if ( V_22 )
return V_22 ;
V_5 -> V_381 = F_303 ( V_21 ) + 1 ;
V_21 -> V_26 = V_26 ;
F_439 ( V_445 , L_79 ,
L_80 ,
V_5 -> V_115 ,
( unsigned long ) F_303 ( V_21 ) ,
V_26 , ( V_26 + V_132 ) ) ;
F_420 ( V_21 ) ;
return 0 ;
}
int T_2 F_141 ( unsigned long V_8 ,
struct V_108 * V_109 )
{
unsigned long V_25 , V_98 ;
int V_9 ;
if ( V_109 -> V_446 <= V_8 && V_8 < V_109 -> V_447 )
return V_109 -> V_448 ;
V_9 = F_440 ( V_8 , & V_25 , & V_98 ) ;
if ( V_9 != - 1 ) {
V_109 -> V_446 = V_25 ;
V_109 -> V_447 = V_98 ;
V_109 -> V_448 = V_9 ;
}
return V_9 ;
}
void T_3 F_441 ( int V_9 , unsigned long V_449 )
{
unsigned long V_25 , V_98 ;
int V_43 , V_450 ;
F_154 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_25 = F_76 ( V_25 , V_449 ) ;
V_98 = F_76 ( V_98 , V_449 ) ;
if ( V_25 < V_98 )
F_442 ( F_443 ( V_25 ) ,
( V_98 - V_25 ) << V_12 ,
V_450 ) ;
}
}
void T_3 F_444 ( int V_9 )
{
unsigned long V_25 , V_98 ;
int V_43 , V_450 ;
F_154 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_445 ( V_450 , V_25 , V_98 ) ;
}
void T_2 F_446 ( unsigned int V_9 ,
unsigned long * V_25 , unsigned long * V_98 )
{
unsigned long V_451 , V_452 ;
int V_43 ;
* V_25 = - 1UL ;
* V_98 = 0 ;
F_154 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_25 = F_76 ( * V_25 , V_451 ) ;
* V_98 = F_156 ( * V_98 , V_452 ) ;
}
if ( * V_25 == - 1UL )
* V_25 = 0 ;
}
static void T_3 F_447 ( void )
{
int V_453 ;
for ( V_453 = V_94 - 1 ; V_453 >= 0 ; V_453 -- ) {
if ( V_453 == V_454 )
continue;
if ( V_455 [ V_453 ] >
V_456 [ V_453 ] )
break;
}
F_74 ( V_453 == - 1 ) ;
V_457 = V_453 ;
}
static void T_2 F_448 ( int V_9 ,
unsigned long V_351 ,
unsigned long V_121 ,
unsigned long V_458 ,
unsigned long * V_26 ,
unsigned long * F_112 )
{
if ( V_459 [ V_9 ] ) {
if ( V_351 == V_454 ) {
* V_26 = V_459 [ V_9 ] ;
* F_112 = F_76 ( V_458 ,
V_455 [ V_457 ] ) ;
} else if ( * V_26 < V_459 [ V_9 ] &&
* F_112 > V_459 [ V_9 ] ) {
* F_112 = V_459 [ V_9 ] ;
} else if ( * V_26 >= V_459 [ V_9 ] )
* V_26 = * F_112 ;
}
}
static unsigned long T_2 F_449 ( int V_9 ,
unsigned long V_351 ,
unsigned long V_121 ,
unsigned long V_458 ,
unsigned long * V_460 )
{
unsigned long V_26 , F_112 ;
if ( ! V_121 && ! V_458 )
return 0 ;
V_26 = V_456 [ V_351 ] ;
F_112 = V_455 [ V_351 ] ;
F_448 ( V_9 , V_351 ,
V_121 , V_458 ,
& V_26 , & F_112 ) ;
if ( F_112 < V_121 || V_26 > V_458 )
return 0 ;
F_112 = F_76 ( F_112 , V_458 ) ;
V_26 = F_156 ( V_26 , V_121 ) ;
return F_112 - V_26 ;
}
unsigned long T_2 F_450 ( int V_9 ,
unsigned long V_461 ,
unsigned long V_462 )
{
unsigned long V_463 = V_462 - V_461 ;
unsigned long V_25 , V_98 ;
int V_43 ;
F_154 (i, nid, &start_pfn, &end_pfn, NULL) {
V_25 = F_451 ( V_25 , V_461 , V_462 ) ;
V_98 = F_451 ( V_98 , V_461 , V_462 ) ;
V_463 -= V_98 - V_25 ;
}
return V_463 ;
}
unsigned long T_3 F_452 ( unsigned long V_25 ,
unsigned long V_98 )
{
return F_450 ( V_406 , V_25 , V_98 ) ;
}
static unsigned long T_2 F_453 ( int V_9 ,
unsigned long V_351 ,
unsigned long V_121 ,
unsigned long V_458 ,
unsigned long * V_460 )
{
unsigned long V_464 = V_456 [ V_351 ] ;
unsigned long V_465 = V_455 [ V_351 ] ;
unsigned long V_26 , F_112 ;
if ( ! V_121 && ! V_458 )
return 0 ;
V_26 = F_451 ( V_121 , V_464 , V_465 ) ;
F_112 = F_451 ( V_458 , V_464 , V_465 ) ;
F_448 ( V_9 , V_351 ,
V_121 , V_458 ,
& V_26 , & F_112 ) ;
return F_450 ( V_9 , V_26 , F_112 ) ;
}
static inline unsigned long T_2 F_449 ( int V_9 ,
unsigned long V_351 ,
unsigned long V_121 ,
unsigned long V_458 ,
unsigned long * V_466 )
{
return V_466 [ V_351 ] ;
}
static inline unsigned long T_2 F_453 ( int V_9 ,
unsigned long V_351 ,
unsigned long V_121 ,
unsigned long V_458 ,
unsigned long * V_467 )
{
if ( ! V_467 )
return 0 ;
return V_467 [ V_351 ] ;
}
static void T_2 F_454 ( struct V_444 * V_5 ,
unsigned long V_121 ,
unsigned long V_458 ,
unsigned long * V_466 ,
unsigned long * V_467 )
{
unsigned long V_468 = 0 , V_469 = 0 ;
enum V_351 V_43 ;
for ( V_43 = 0 ; V_43 < V_94 ; V_43 ++ ) {
struct V_21 * V_21 = V_5 -> V_95 + V_43 ;
unsigned long V_132 , V_470 ;
V_132 = F_449 ( V_5 -> V_115 , V_43 ,
V_121 ,
V_458 ,
V_466 ) ;
V_470 = V_132 - F_453 ( V_5 -> V_115 , V_43 ,
V_121 , V_458 ,
V_467 ) ;
V_21 -> V_27 = V_132 ;
V_21 -> V_373 = V_470 ;
V_469 += V_132 ;
V_468 += V_470 ;
}
V_5 -> V_471 = V_469 ;
V_5 -> V_472 = V_468 ;
F_31 ( V_443 L_81 , V_5 -> V_115 ,
V_468 ) ;
}
static unsigned long T_3 F_455 ( unsigned long V_26 , unsigned long V_473 )
{
unsigned long V_474 ;
V_473 += V_26 & ( V_127 - 1 ) ;
V_474 = F_417 ( V_473 , V_127 ) ;
V_474 = V_474 >> V_67 ;
V_474 *= V_475 ;
V_474 = F_417 ( V_474 , 8 * sizeof( unsigned long ) ) ;
return V_474 / 8 ;
}
static void T_3 F_456 ( struct V_444 * V_5 ,
struct V_21 * V_21 ,
unsigned long V_26 ,
unsigned long V_473 )
{
unsigned long V_474 = F_455 ( V_26 , V_473 ) ;
V_21 -> V_476 = NULL ;
if ( V_474 )
V_21 -> V_476 =
F_434 ( V_474 ,
V_5 -> V_115 ) ;
}
static inline void F_456 ( struct V_444 * V_5 , struct V_21 * V_21 ,
unsigned long V_26 , unsigned long V_473 ) {}
void T_15 F_457 ( void )
{
unsigned int V_42 ;
if ( V_67 )
return;
if ( V_477 > V_12 )
V_42 = V_478 ;
else
V_42 = V_52 - 1 ;
V_67 = V_42 ;
}
void T_15 F_457 ( void )
{
}
static unsigned long T_15 F_458 ( unsigned long V_27 ,
unsigned long V_373 )
{
unsigned long V_151 = V_27 ;
if ( V_27 > V_373 + ( V_373 >> 4 ) &&
F_100 ( V_479 ) )
V_151 = V_373 ;
return F_344 ( V_151 * sizeof( struct V_14 ) ) >> V_12 ;
}
static void T_15 F_459 ( struct V_444 * V_5 ,
unsigned long V_121 , unsigned long V_458 )
{
enum V_351 V_408 ;
int V_9 = V_5 -> V_115 ;
unsigned long V_26 = V_5 -> V_121 ;
int V_22 ;
F_460 ( V_5 ) ;
#ifdef F_461
F_462 ( & V_5 -> V_480 ) ;
V_5 -> V_481 = 0 ;
V_5 -> V_482 = V_34 ;
#endif
F_436 ( & V_5 -> V_483 ) ;
F_436 ( & V_5 -> V_484 ) ;
F_463 ( V_5 ) ;
for ( V_408 = 0 ; V_408 < V_94 ; V_408 ++ ) {
struct V_21 * V_21 = V_5 -> V_95 + V_408 ;
unsigned long V_132 , V_485 , V_486 , V_487 ;
V_132 = V_21 -> V_27 ;
V_485 = V_486 = V_21 -> V_373 ;
V_487 = F_458 ( V_132 , V_485 ) ;
if ( ! F_106 ( V_408 ) ) {
if ( V_486 >= V_487 ) {
V_486 -= V_487 ;
if ( V_487 )
F_31 ( V_443
L_82 ,
V_426 [ V_408 ] , V_487 ) ;
} else
F_31 ( V_387
L_83 ,
V_426 [ V_408 ] , V_487 , V_486 ) ;
}
if ( V_408 == 0 && V_486 > V_488 ) {
V_486 -= V_488 ;
F_31 ( V_443 L_84 ,
V_426 [ 0 ] , V_488 ) ;
}
if ( ! F_106 ( V_408 ) )
V_489 += V_486 ;
else if ( V_489 > V_487 * 2 )
V_489 -= V_487 ;
V_490 += V_486 ;
V_21 -> V_104 = F_106 ( V_408 ) ? V_485 : V_486 ;
#ifdef V_242
V_21 -> V_107 = V_9 ;
V_21 -> V_491 = ( V_486 * V_492 )
/ 100 ;
V_21 -> V_493 = ( V_486 * V_494 ) / 100 ;
#endif
V_21 -> V_28 = V_426 [ V_408 ] ;
F_462 ( & V_21 -> V_84 ) ;
F_462 ( & V_21 -> V_495 ) ;
F_464 ( V_21 ) ;
V_21 -> V_231 = V_5 ;
F_437 ( V_21 ) ;
F_268 ( V_21 , V_184 , V_21 -> V_104 ) ;
F_465 ( & V_21 -> V_496 ) ;
if ( ! V_132 )
continue;
F_457 () ;
F_456 ( V_5 , V_21 , V_26 , V_132 ) ;
V_22 = F_438 ( V_21 , V_26 ,
V_132 , V_437 ) ;
F_153 ( V_22 ) ;
F_466 ( V_132 , V_9 , V_408 , V_26 ) ;
V_26 += V_132 ;
}
}
static void T_14 F_467 ( struct V_444 * V_5 )
{
if ( ! V_5 -> V_471 )
return;
#ifdef F_468
if ( ! V_5 -> V_497 ) {
unsigned long V_132 , V_96 , V_97 ;
struct V_14 * V_498 ;
V_96 = V_5 -> V_121 & ~ ( V_110 - 1 ) ;
V_97 = F_12 ( V_5 ) ;
V_97 = F_469 ( V_97 , V_110 ) ;
V_132 = ( V_97 - V_96 ) * sizeof( struct V_14 ) ;
V_498 = F_470 ( V_5 -> V_115 , V_132 ) ;
if ( ! V_498 )
V_498 = F_434 ( V_132 ,
V_5 -> V_115 ) ;
V_5 -> V_497 = V_498 + ( V_5 -> V_121 - V_96 ) ;
}
#ifndef F_471
if ( V_5 == F_8 ( 0 ) ) {
V_499 = F_8 ( 0 ) -> V_497 ;
#ifdef F_472
if ( F_17 ( V_499 ) != V_5 -> V_121 )
V_499 -= ( V_5 -> V_121 - V_500 ) ;
#endif
}
#endif
#endif
}
void T_15 F_473 ( int V_9 , unsigned long * V_466 ,
unsigned long V_121 , unsigned long * V_467 )
{
T_1 * V_5 = F_8 ( V_9 ) ;
unsigned long V_25 = 0 ;
unsigned long V_98 = 0 ;
F_2 ( V_5 -> V_381 || V_5 -> V_205 ) ;
F_6 ( V_5 ) ;
V_5 -> V_115 = V_9 ;
V_5 -> V_121 = V_121 ;
#ifdef F_472
F_446 ( V_9 , & V_25 , & V_98 ) ;
F_158 ( L_85 , V_9 ,
( V_501 ) V_25 << V_12 , ( ( V_501 ) V_98 << V_12 ) - 1 ) ;
#endif
F_454 ( V_5 , V_25 , V_98 ,
V_466 , V_467 ) ;
F_467 ( V_5 ) ;
#ifdef F_468
F_31 ( V_443 L_86 ,
V_9 , ( unsigned long ) V_5 ,
( unsigned long ) V_5 -> V_497 ) ;
#endif
F_459 ( V_5 , V_25 , V_98 ) ;
}
void T_3 F_474 ( void )
{
unsigned int V_107 ;
unsigned int V_502 = 0 ;
F_475 (node, node_possible_map)
V_502 = V_107 ;
V_503 = V_502 + 1 ;
}
unsigned long T_3 F_476 ( void )
{
unsigned long V_504 = 0 , V_447 = 0 ;
unsigned long V_96 , V_97 , V_505 ;
int V_448 = - 1 ;
int V_43 , V_9 ;
F_154 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_96 || V_448 < 0 || V_448 == V_9 ) {
V_448 = V_9 ;
V_447 = V_97 ;
continue;
}
V_505 = ~ ( ( 1 << F_477 ( V_96 ) ) - 1 ) ;
while ( V_505 && V_447 <= ( V_96 & ( V_505 << 1 ) ) )
V_505 <<= 1 ;
V_504 |= V_505 ;
}
return ~ V_504 + 1 ;
}
static unsigned long T_3 F_478 ( int V_9 )
{
unsigned long V_506 = V_7 ;
unsigned long V_25 ;
int V_43 ;
F_154 (i, nid, &start_pfn, NULL, NULL)
V_506 = F_76 ( V_506 , V_25 ) ;
if ( V_506 == V_7 ) {
F_31 ( V_387
L_87 , V_9 ) ;
return 0 ;
}
return V_506 ;
}
unsigned long T_3 F_479 ( void )
{
return F_478 ( V_406 ) ;
}
static unsigned long T_3 F_480 ( void )
{
unsigned long V_469 = 0 ;
unsigned long V_25 , V_98 ;
int V_43 , V_9 ;
F_154 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_151 = V_98 - V_25 ;
V_469 += V_151 ;
if ( V_151 )
F_481 ( V_9 , V_126 ) ;
}
return V_469 ;
}
static void T_3 F_482 ( void )
{
int V_43 , V_9 ;
unsigned long V_507 ;
unsigned long V_508 , V_509 ;
T_7 V_510 = V_224 [ V_126 ] ;
unsigned long V_469 = F_480 () ;
int V_511 = F_483 ( V_224 [ V_126 ] ) ;
struct V_512 * V_513 ;
F_447 () ;
if ( F_484 () ) {
F_485 (memory, r) {
if ( ! F_486 ( V_513 ) )
continue;
V_9 = V_513 -> V_9 ;
V_507 = F_114 ( V_513 -> V_514 ) ;
V_459 [ V_9 ] = V_459 [ V_9 ] ?
F_76 ( V_507 , V_459 [ V_9 ] ) :
V_507 ;
}
goto V_515;
}
if ( V_516 ) {
unsigned long V_517 ;
V_516 =
F_417 ( V_516 , V_110 ) ;
V_517 = V_469 - V_516 ;
V_518 = F_156 ( V_518 , V_517 ) ;
}
if ( ! V_518 )
goto V_35;
V_507 = V_456 [ V_457 ] ;
V_519:
V_508 = V_518 / V_511 ;
F_163 (nid, N_MEMORY) {
unsigned long V_25 , V_98 ;
if ( V_518 < V_508 )
V_508 = V_518 / V_511 ;
V_509 = V_508 ;
F_154 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_520 ;
V_25 = F_156 ( V_25 , V_459 [ V_9 ] ) ;
if ( V_25 >= V_98 )
continue;
if ( V_25 < V_507 ) {
unsigned long V_521 ;
V_521 = F_76 ( V_98 , V_507 )
- V_25 ;
V_509 -= F_76 ( V_521 ,
V_509 ) ;
V_518 -= F_76 ( V_521 ,
V_518 ) ;
if ( V_98 <= V_507 ) {
V_459 [ V_9 ] = V_98 ;
continue;
}
V_25 = V_507 ;
}
V_520 = V_98 - V_25 ;
if ( V_520 > V_509 )
V_520 = V_509 ;
V_459 [ V_9 ] = V_25 + V_520 ;
V_518 -= F_76 ( V_518 ,
V_520 ) ;
V_509 -= V_520 ;
if ( ! V_509 )
break;
}
}
V_511 -- ;
if ( V_511 && V_518 > V_511 )
goto V_519;
V_515:
for ( V_9 = 0 ; V_9 < V_406 ; V_9 ++ )
V_459 [ V_9 ] =
F_417 ( V_459 [ V_9 ] , V_110 ) ;
V_35:
V_224 [ V_126 ] = V_510 ;
}
static void F_487 ( T_1 * V_5 , int V_9 )
{
enum V_351 V_351 ;
if ( V_126 == V_522 )
return;
for ( V_351 = 0 ; V_351 <= V_454 - 1 ; V_351 ++ ) {
struct V_21 * V_21 = & V_5 -> V_95 [ V_351 ] ;
if ( F_157 ( V_21 ) ) {
F_481 ( V_9 , V_523 ) ;
if ( V_522 != V_523 &&
V_351 <= V_274 )
F_481 ( V_9 , V_522 ) ;
break;
}
}
}
void T_3 F_488 ( unsigned long * V_172 )
{
unsigned long V_25 , V_98 ;
int V_43 , V_9 ;
memset ( V_456 , 0 ,
sizeof( V_456 ) ) ;
memset ( V_455 , 0 ,
sizeof( V_455 ) ) ;
V_456 [ 0 ] = F_479 () ;
V_455 [ 0 ] = V_172 [ 0 ] ;
for ( V_43 = 1 ; V_43 < V_94 ; V_43 ++ ) {
if ( V_43 == V_454 )
continue;
V_456 [ V_43 ] =
V_455 [ V_43 - 1 ] ;
V_455 [ V_43 ] =
F_156 ( V_172 [ V_43 ] , V_456 [ V_43 ] ) ;
}
V_456 [ V_454 ] = 0 ;
V_455 [ V_454 ] = 0 ;
memset ( V_459 , 0 , sizeof( V_459 ) ) ;
F_482 () ;
F_158 ( L_88 ) ;
for ( V_43 = 0 ; V_43 < V_94 ; V_43 ++ ) {
if ( V_43 == V_454 )
continue;
F_158 ( L_89 , V_426 [ V_43 ] ) ;
if ( V_456 [ V_43 ] ==
V_455 [ V_43 ] )
F_489 ( L_90 ) ;
else
F_489 ( L_91 ,
( V_501 ) V_456 [ V_43 ]
<< V_12 ,
( ( V_501 ) V_455 [ V_43 ]
<< V_12 ) - 1 ) ;
}
F_158 ( L_92 ) ;
for ( V_43 = 0 ; V_43 < V_406 ; V_43 ++ ) {
if ( V_459 [ V_43 ] )
F_158 ( L_93 , V_43 ,
( V_501 ) V_459 [ V_43 ] << V_12 ) ;
}
F_158 ( L_94 ) ;
F_154 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_158 ( L_95 , V_9 ,
( V_501 ) V_25 << V_12 ,
( ( V_501 ) V_98 << V_12 ) - 1 ) ;
F_490 () ;
F_474 () ;
F_397 (nid) {
T_1 * V_5 = F_8 ( V_9 ) ;
F_473 ( V_9 , NULL ,
F_478 ( V_9 ) , NULL ) ;
if ( V_5 -> V_472 )
F_481 ( V_9 , V_126 ) ;
F_487 ( V_5 , V_9 ) ;
}
}
static int T_3 F_491 ( char * V_45 , unsigned long * V_524 )
{
unsigned long long V_525 ;
if ( ! V_45 )
return - V_48 ;
V_525 = F_492 ( V_45 , & V_45 ) ;
* V_524 = V_525 >> V_12 ;
F_2 ( ( V_525 >> V_12 ) > V_7 ) ;
return 0 ;
}
static int T_3 F_493 ( char * V_45 )
{
return F_491 ( V_45 , & V_518 ) ;
}
static int T_3 F_494 ( char * V_45 )
{
return F_491 ( V_45 , & V_516 ) ;
}
void F_168 ( struct V_14 * V_14 , long V_78 )
{
F_87 ( & V_526 ) ;
F_25 ( V_14 ) -> V_104 += V_78 ;
V_342 += V_78 ;
#ifdef F_361
if ( F_125 ( V_14 ) )
V_348 += V_78 ;
#endif
F_96 ( & V_526 ) ;
}
unsigned long F_495 ( void * V_96 , void * V_97 , int V_527 , char * V_382 )
{
void * V_411 ;
unsigned long V_151 = 0 ;
V_96 = ( void * ) F_344 ( ( unsigned long ) V_96 ) ;
V_97 = ( void * ) ( ( unsigned long ) V_97 & V_528 ) ;
for ( V_411 = V_96 ; V_411 < V_97 ; V_411 += V_101 , V_151 ++ ) {
if ( ( unsigned int ) V_527 <= 0xFF )
memset ( V_411 , V_527 , V_101 ) ;
F_496 ( F_228 ( V_411 ) ) ;
}
if ( V_151 && V_382 )
F_158 ( L_96 ,
V_382 , V_151 << ( V_12 - 10 ) , V_96 , V_97 ) ;
return V_151 ;
}
void F_497 ( struct V_14 * V_14 )
{
F_498 ( V_14 ) ;
V_342 ++ ;
F_25 ( V_14 ) -> V_104 ++ ;
V_348 ++ ;
}
void T_3 F_499 ( const char * V_188 )
{
unsigned long V_529 , V_530 , V_531 , V_532 , V_533 ;
unsigned long V_534 , V_535 ;
V_529 = F_500 () ;
V_530 = V_536 - V_537 ;
V_531 = V_538 - V_539 ;
V_532 = V_540 - V_541 ;
V_533 = V_542 - V_543 ;
V_535 = V_544 - V_545 ;
V_534 = V_546 - V_547 ;
#define F_501 ( V_96 , V_97 , V_132 , V_411 , T_16 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_501 ( V_545 , V_544 , V_535 ,
V_547 , V_534 ) ;
F_501 ( V_537 , V_536 , V_530 , V_547 , V_534 ) ;
F_501 ( V_539 , V_538 , V_531 , V_545 , V_535 ) ;
F_501 ( V_537 , V_536 , V_530 , V_541 , V_532 ) ;
F_501 ( V_539 , V_538 , V_531 , V_541 , V_532 ) ;
#undef F_501
F_158 ( L_97
L_98
L_99
#ifdef F_361
L_100
#endif
L_101 ,
F_502 () << ( V_12 - 10 ) , V_529 << ( V_12 - 10 ) ,
V_530 >> 10 , V_531 >> 10 , V_532 >> 10 ,
( V_535 + V_534 ) >> 10 , V_533 >> 10 ,
( V_529 - V_342 - V_548 ) << ( V_12 - 10 ) ,
V_548 << ( V_12 - 10 ) ,
#ifdef F_361
V_348 << ( V_12 - 10 ) ,
#endif
V_188 ? L_102 : L_103 , V_188 ? V_188 : L_103 ) ;
}
void T_3 F_503 ( unsigned long V_549 )
{
V_488 = V_549 ;
}
void T_3 F_504 ( unsigned long * V_466 )
{
F_473 ( 0 , V_466 ,
F_505 ( V_550 ) >> V_12 , NULL ) ;
}
static int F_506 ( struct V_551 * V_420 ,
unsigned long V_552 , void * V_553 )
{
int V_164 = ( unsigned long ) V_553 ;
if ( V_552 == V_554 || V_552 == V_555 ) {
F_507 ( V_164 ) ;
F_201 ( V_164 ) ;
F_508 ( V_164 ) ;
F_509 ( V_164 ) ;
}
return V_556 ;
}
void T_3 F_510 ( void )
{
F_511 ( F_506 , 0 ) ;
}
static void F_512 ( void )
{
struct V_444 * V_5 ;
unsigned long V_557 = 0 ;
enum V_351 V_43 , V_408 ;
F_513 (pgdat) {
for ( V_43 = 0 ; V_43 < V_94 ; V_43 ++ ) {
struct V_21 * V_21 = V_5 -> V_95 + V_43 ;
long F_156 = 0 ;
for ( V_408 = V_43 ; V_408 < V_94 ; V_408 ++ ) {
if ( V_21 -> V_212 [ V_408 ] > F_156 )
F_156 = V_21 -> V_212 [ V_408 ] ;
}
F_156 += F_269 ( V_21 ) ;
if ( F_156 > V_21 -> V_104 )
F_156 = V_21 -> V_104 ;
V_557 += F_156 ;
V_21 -> V_558 = F_156 ;
}
}
V_558 = V_557 ;
V_559 = V_557 ;
}
static void F_514 ( void )
{
struct V_444 * V_5 ;
enum V_351 V_408 , V_560 ;
F_513 (pgdat) {
for ( V_408 = 0 ; V_408 < V_94 ; V_408 ++ ) {
struct V_21 * V_21 = V_5 -> V_95 + V_408 ;
unsigned long V_104 = V_21 -> V_104 ;
V_21 -> V_212 [ V_408 ] = 0 ;
V_560 = V_408 ;
while ( V_560 ) {
struct V_21 * V_561 ;
V_560 -- ;
if ( V_562 [ V_560 ] < 1 )
V_562 [ V_560 ] = 1 ;
V_561 = V_5 -> V_95 + V_560 ;
V_561 -> V_212 [ V_408 ] = V_104 /
V_562 [ V_560 ] ;
V_104 += V_561 -> V_104 ;
}
}
}
F_512 () ;
}
static void F_515 ( void )
{
unsigned long V_563 = V_564 >> ( V_12 - 10 ) ;
unsigned long V_565 = 0 ;
struct V_21 * V_21 ;
unsigned long V_58 ;
F_516 (zone) {
if ( ! F_517 ( V_21 ) )
V_565 += V_21 -> V_104 ;
}
F_516 (zone) {
V_501 V_356 ;
F_212 ( & V_21 -> V_84 , V_58 ) ;
V_356 = ( V_501 ) V_563 * V_21 -> V_104 ;
F_518 ( V_356 , V_565 ) ;
if ( F_517 ( V_21 ) ) {
unsigned long V_566 ;
V_566 = V_21 -> V_104 / 1024 ;
V_566 = F_451 ( V_566 , V_567 , 128UL ) ;
V_21 -> V_177 [ V_568 ] = V_566 ;
} else {
V_21 -> V_177 [ V_568 ] = V_356 ;
}
V_21 -> V_177 [ V_569 ] = F_367 ( V_21 ) + ( V_356 >> 2 ) ;
V_21 -> V_177 [ V_570 ] = F_367 ( V_21 ) + ( V_356 >> 1 ) ;
F_89 ( V_21 , V_184 ,
F_269 ( V_21 ) - F_231 ( V_21 ) -
F_236 ( & V_21 -> V_185 [ V_184 ] ) ) ;
F_416 ( V_21 ) ;
F_218 ( & V_21 -> V_84 , V_58 ) ;
}
F_512 () ;
}
void F_519 ( void )
{
F_380 ( & V_399 ) ;
F_515 () ;
F_288 ( & V_399 ) ;
}
static void T_2 F_520 ( struct V_21 * V_21 )
{
unsigned int V_571 , V_572 ;
V_571 = V_21 -> V_104 >> ( 30 - V_12 ) ;
if ( V_571 )
V_572 = F_521 ( 10 * V_571 ) ;
else
V_572 = 1 ;
V_21 -> V_573 = V_572 ;
}
static void T_2 F_522 ( void )
{
struct V_21 * V_21 ;
F_516 (zone)
F_520 ( V_21 ) ;
}
int T_2 F_523 ( void )
{
unsigned long V_574 ;
int V_575 ;
V_574 = F_352 () * ( V_101 >> 10 ) ;
V_575 = F_521 ( V_574 * 16 ) ;
if ( V_575 > V_576 ) {
V_564 = V_575 ;
if ( V_564 < 128 )
V_564 = 128 ;
if ( V_564 > 65536 )
V_564 = 65536 ;
} else {
F_282 ( L_104 ,
V_575 , V_576 ) ;
}
F_519 () ;
F_524 () ;
F_514 () ;
F_522 () ;
return 0 ;
}
int F_525 ( struct V_390 * V_391 , int V_392 ,
void T_10 * V_393 , T_9 * V_394 , T_11 * V_395 )
{
int V_577 ;
V_577 = F_526 ( V_391 , V_392 , V_393 , V_394 , V_395 ) ;
if ( V_577 )
return V_577 ;
if ( V_392 ) {
V_576 = V_564 ;
F_519 () ;
}
return 0 ;
}
int F_527 ( struct V_390 * V_391 , int V_392 ,
void T_10 * V_393 , T_9 * V_394 , T_11 * V_395 )
{
struct V_21 * V_21 ;
int V_577 ;
V_577 = F_526 ( V_391 , V_392 , V_393 , V_394 , V_395 ) ;
if ( V_577 )
return V_577 ;
F_516 (zone)
V_21 -> V_491 = ( V_21 -> V_104 *
V_492 ) / 100 ;
return 0 ;
}
int F_528 ( struct V_390 * V_391 , int V_392 ,
void T_10 * V_393 , T_9 * V_394 , T_11 * V_395 )
{
struct V_21 * V_21 ;
int V_577 ;
V_577 = F_526 ( V_391 , V_392 , V_393 , V_394 , V_395 ) ;
if ( V_577 )
return V_577 ;
F_516 (zone)
V_21 -> V_493 = ( V_21 -> V_104 *
V_494 ) / 100 ;
return 0 ;
}
int F_529 ( struct V_390 * V_391 , int V_392 ,
void T_10 * V_393 , T_9 * V_394 , T_11 * V_395 )
{
F_526 ( V_391 , V_392 , V_393 , V_394 , V_395 ) ;
F_514 () ;
return 0 ;
}
int F_530 ( struct V_390 * V_391 , int V_392 ,
void T_10 * V_393 , T_9 * V_394 , T_11 * V_395 )
{
struct V_21 * V_21 ;
int V_578 ;
int V_22 ;
F_380 ( & V_579 ) ;
V_578 = V_438 ;
V_22 = F_526 ( V_391 , V_392 , V_393 , V_394 , V_395 ) ;
if ( ! V_392 || V_22 < 0 )
goto V_35;
if ( V_438 &&
V_438 < V_580 ) {
V_438 = V_578 ;
V_22 = - V_48 ;
goto V_35;
}
if ( V_438 == V_578 )
goto V_35;
F_202 (zone) {
unsigned int V_164 ;
F_398 (cpu)
F_428 ( V_21 ,
F_200 ( V_21 -> V_167 , V_164 ) ) ;
}
V_35:
F_288 ( & V_579 ) ;
return V_22 ;
}
static int T_3 F_531 ( char * V_188 )
{
if ( ! V_188 )
return 0 ;
V_581 = F_532 ( V_188 , & V_188 , 0 ) ;
return 1 ;
}
void * T_3 F_533 ( const char * V_582 ,
unsigned long V_583 ,
unsigned long V_584 ,
int V_585 ,
int V_58 ,
unsigned int * V_586 ,
unsigned int * V_587 ,
unsigned long V_588 ,
unsigned long V_589 )
{
unsigned long long F_156 = V_589 ;
unsigned long V_590 , V_132 ;
void * V_391 = NULL ;
if ( ! V_584 ) {
V_584 = V_489 ;
if ( V_12 < 20 )
V_584 = F_534 ( V_584 , ( 1 << 20 ) / V_101 ) ;
if ( V_585 > V_12 )
V_584 >>= ( V_585 - V_12 ) ;
else
V_584 <<= ( V_12 - V_585 ) ;
if ( F_14 ( V_58 & V_591 ) ) {
F_2 ( ! ( V_58 & V_592 ) ) ;
if ( ! ( V_584 >> * V_586 ) ) {
V_584 = 1UL << * V_586 ;
F_153 ( ! V_584 ) ;
}
} else if ( F_14 ( ( V_584 * V_583 ) < V_101 ) )
V_584 = V_101 / V_583 ;
}
V_584 = F_535 ( V_584 ) ;
if ( F_156 == 0 ) {
F_156 = ( ( unsigned long long ) V_490 << V_12 ) >> 4 ;
F_518 ( F_156 , V_583 ) ;
}
F_156 = F_76 ( F_156 , 0x80000000ULL ) ;
if ( V_584 < V_588 )
V_584 = V_588 ;
if ( V_584 > F_156 )
V_584 = F_156 ;
V_590 = F_536 ( V_584 ) ;
do {
V_132 = V_583 << V_590 ;
if ( V_58 & V_592 )
V_391 = F_537 ( V_132 , 0 ) ;
else if ( V_581 )
V_391 = F_538 ( V_132 , V_593 , V_594 ) ;
else {
if ( F_347 ( V_132 ) < V_52 ) {
V_391 = F_346 ( V_132 , V_593 ) ;
F_539 ( V_391 , V_132 , 1 , V_593 ) ;
}
}
} while ( ! V_391 && V_132 > V_101 && -- V_590 );
if ( ! V_391 )
F_540 ( L_105 , V_582 ) ;
F_31 ( V_55 L_106 ,
V_582 ,
( 1UL << V_590 ) ,
F_536 ( V_132 ) - V_12 ,
V_132 ) ;
if ( V_586 )
* V_586 = V_590 ;
if ( V_587 )
* V_587 = ( 1 << V_590 ) - 1 ;
return V_391 ;
}
static inline unsigned long * F_541 ( struct V_21 * V_21 ,
unsigned long V_8 )
{
#ifdef V_479
return F_542 ( V_8 ) -> V_476 ;
#else
return V_21 -> V_476 ;
#endif
}
static inline int F_543 ( struct V_21 * V_21 , unsigned long V_8 )
{
#ifdef V_479
V_8 &= ( V_13 - 1 ) ;
return ( V_8 >> V_67 ) * V_475 ;
#else
V_8 = V_8 - F_544 ( V_21 -> V_26 , V_127 ) ;
return ( V_8 >> V_67 ) * V_475 ;
#endif
}
unsigned long F_545 ( struct V_14 * V_14 , unsigned long V_8 ,
unsigned long V_595 ,
unsigned long V_505 )
{
struct V_21 * V_21 ;
unsigned long * V_596 ;
unsigned long V_597 , V_598 ;
unsigned long V_599 ;
V_21 = F_25 ( V_14 ) ;
V_596 = F_541 ( V_21 , V_8 ) ;
V_597 = F_543 ( V_21 , V_8 ) ;
V_598 = V_597 / V_600 ;
V_597 &= ( V_600 - 1 ) ;
V_599 = V_596 [ V_598 ] ;
V_597 += V_595 ;
return ( V_599 >> ( V_600 - V_597 - 1 ) ) & V_505 ;
}
void F_546 ( struct V_14 * V_14 , unsigned long V_58 ,
unsigned long V_8 ,
unsigned long V_595 ,
unsigned long V_505 )
{
struct V_21 * V_21 ;
unsigned long * V_596 ;
unsigned long V_597 , V_598 ;
unsigned long V_601 , V_599 ;
F_276 ( V_475 != 4 ) ;
V_21 = F_25 ( V_14 ) ;
V_596 = F_541 ( V_21 , V_8 ) ;
V_597 = F_543 ( V_21 , V_8 ) ;
V_598 = V_597 / V_600 ;
V_597 &= ( V_600 - 1 ) ;
F_70 ( ! F_19 ( V_21 , V_8 ) , V_14 ) ;
V_597 += V_595 ;
V_505 <<= ( V_600 - V_597 - 1 ) ;
V_58 <<= ( V_600 - V_597 - 1 ) ;
V_599 = F_198 ( V_596 [ V_598 ] ) ;
for (; ; ) {
V_601 = F_547 ( & V_596 [ V_598 ] , V_599 , ( V_599 & ~ V_505 ) | V_58 ) ;
if ( V_599 == V_601 )
break;
V_599 = V_601 ;
}
}
bool F_548 ( struct V_21 * V_21 , struct V_14 * V_14 , int V_78 ,
bool V_602 )
{
unsigned long V_8 , V_603 , V_604 ;
int V_89 ;
if ( F_303 ( V_21 ) == V_454 )
return false ;
V_89 = F_94 ( V_14 ) ;
if ( V_89 == V_111 || F_196 ( V_89 ) )
return false ;
V_8 = F_17 ( V_14 ) ;
for ( V_604 = 0 , V_603 = 0 ; V_603 < V_127 ; V_603 ++ ) {
unsigned long V_605 = V_8 + V_603 ;
if ( ! F_24 ( V_605 ) )
continue;
V_14 = F_110 ( V_605 ) ;
if ( F_549 ( V_14 ) ) {
V_603 = F_534 ( V_603 + 1 , 1 << F_38 ( V_14 ) ) - 1 ;
continue;
}
if ( ! F_83 ( & V_14 -> V_75 ) ) {
if ( F_72 ( V_14 ) )
V_603 += ( 1 << F_68 ( V_14 ) ) - 1 ;
continue;
}
if ( V_602 && F_28 ( V_14 ) )
continue;
if ( ! F_550 ( V_14 ) )
V_604 ++ ;
if ( V_604 > V_78 )
return true ;
}
return false ;
}
bool F_551 ( struct V_14 * V_14 )
{
struct V_21 * V_21 ;
unsigned long V_8 ;
if ( ! F_395 ( F_183 ( V_14 ) ) )
return false ;
V_21 = F_25 ( V_14 ) ;
V_8 = F_17 ( V_14 ) ;
if ( ! F_19 ( V_21 , V_8 ) )
return false ;
return ! F_548 ( V_21 , V_14 , 0 , true ) ;
}
static unsigned long F_552 ( unsigned long V_8 )
{
return V_8 & ~ ( F_553 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_554 ( unsigned long V_8 )
{
return F_469 ( V_8 , F_553 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_555 ( struct V_606 * V_607 ,
unsigned long V_96 , unsigned long V_97 )
{
unsigned long V_608 ;
unsigned long V_8 = V_96 ;
unsigned int V_609 = 0 ;
int V_22 = 0 ;
F_556 () ;
while ( V_8 < V_97 || ! F_90 ( & V_607 -> V_610 ) ) {
if ( F_557 ( V_38 ) ) {
V_22 = - V_611 ;
break;
}
if ( F_90 ( & V_607 -> V_610 ) ) {
V_607 -> V_612 = 0 ;
V_8 = F_558 ( V_607 , V_8 , V_97 ) ;
if ( ! V_8 ) {
V_22 = - V_611 ;
break;
}
V_609 = 0 ;
} else if ( ++ V_609 == 5 ) {
V_22 = V_22 < 0 ? V_22 : - V_613 ;
break;
}
V_608 = F_559 ( V_607 -> V_21 ,
& V_607 -> V_610 ) ;
V_607 -> V_612 -= V_608 ;
V_22 = F_560 ( & V_607 -> V_610 , V_614 ,
NULL , 0 , V_607 -> V_196 , V_615 ) ;
}
if ( V_22 < 0 ) {
F_561 ( & V_607 -> V_610 ) ;
return V_22 ;
}
return 0 ;
}
int F_562 ( unsigned long V_96 , unsigned long V_97 ,
unsigned V_15 )
{
unsigned long V_616 , V_617 ;
int V_22 = 0 , V_42 ;
struct V_606 V_607 = {
. V_612 = 0 ,
. V_42 = - 1 ,
. V_21 = F_25 ( F_110 ( V_96 ) ) ,
. V_196 = V_618 ,
. V_619 = true ,
} ;
F_56 ( & V_607 . V_610 ) ;
V_22 = F_563 ( F_552 ( V_96 ) ,
F_554 ( V_97 ) , V_15 ,
false ) ;
if ( V_22 )
return V_22 ;
V_22 = F_555 ( & V_607 , V_96 , V_97 ) ;
if ( V_22 )
goto V_620;
F_564 () ;
F_205 ( V_607 . V_21 ) ;
V_42 = 0 ;
V_616 = V_96 ;
while ( ! F_72 ( F_110 ( V_616 ) ) ) {
if ( ++ V_42 >= V_52 ) {
V_22 = - V_613 ;
goto V_620;
}
V_616 &= ~ 0UL << V_42 ;
}
if ( F_565 ( V_616 , V_97 , false ) ) {
F_158 ( L_107 ,
V_621 , V_616 , V_97 ) ;
V_22 = - V_613 ;
goto V_620;
}
V_617 = F_566 ( & V_607 , V_616 , V_97 ) ;
if ( ! V_617 ) {
V_22 = - V_613 ;
goto V_620;
}
if ( V_96 != V_616 )
F_567 ( V_616 , V_96 - V_616 ) ;
if ( V_97 != V_617 )
F_567 ( V_97 , V_617 - V_97 ) ;
V_620:
F_568 ( F_552 ( V_96 ) ,
F_554 ( V_97 ) , V_15 ) ;
return V_22 ;
}
void F_567 ( unsigned long V_8 , unsigned V_44 )
{
unsigned int V_78 = 0 ;
for (; V_44 -- ; V_8 ++ ) {
struct V_14 * V_14 = F_110 ( V_8 ) ;
V_78 += F_71 ( V_14 ) != 1 ;
F_569 ( V_14 ) ;
}
F_570 ( V_78 != 0 , L_108 , V_78 ) ;
}
void T_2 F_571 ( struct V_21 * V_21 )
{
unsigned V_164 ;
F_380 ( & V_579 ) ;
F_398 (cpu)
F_428 ( V_21 ,
F_200 ( V_21 -> V_167 , V_164 ) ) ;
F_288 ( & V_579 ) ;
}
void F_572 ( struct V_21 * V_21 )
{
unsigned long V_58 ;
int V_164 ;
struct V_165 * V_166 ;
F_131 ( V_58 ) ;
if ( V_21 -> V_167 != & V_421 ) {
F_206 (cpu) {
V_166 = F_200 ( V_21 -> V_167 , V_164 ) ;
F_573 ( V_21 , V_166 ) ;
}
F_574 ( V_21 -> V_167 ) ;
V_21 -> V_167 = & V_421 ;
}
F_134 ( V_58 ) ;
}
void
F_575 ( unsigned long V_25 , unsigned long V_98 )
{
struct V_14 * V_14 ;
struct V_21 * V_21 ;
unsigned int V_42 , V_43 ;
unsigned long V_8 ;
unsigned long V_58 ;
for ( V_8 = V_25 ; V_8 < V_98 ; V_8 ++ )
if ( F_116 ( V_8 ) )
break;
if ( V_8 == V_98 )
return;
V_21 = F_25 ( F_110 ( V_8 ) ) ;
F_212 ( & V_21 -> V_84 , V_58 ) ;
V_8 = V_25 ;
while ( V_8 < V_98 ) {
if ( ! F_116 ( V_8 ) ) {
V_8 ++ ;
continue;
}
V_14 = F_110 ( V_8 ) ;
if ( F_14 ( ! F_72 ( V_14 ) && F_28 ( V_14 ) ) ) {
V_8 ++ ;
F_117 ( V_14 ) ;
continue;
}
F_153 ( F_71 ( V_14 ) ) ;
F_153 ( ! F_72 ( V_14 ) ) ;
V_42 = F_68 ( V_14 ) ;
#ifdef V_92
F_31 ( V_55 L_109 ,
V_8 , 1 << V_42 , V_98 ) ;
#endif
F_78 ( & V_14 -> V_59 ) ;
F_64 ( V_14 ) ;
V_21 -> V_68 [ V_42 ] . V_69 -- ;
for ( V_43 = 0 ; V_43 < ( 1 << V_42 ) ; V_43 ++ )
F_117 ( ( V_14 + V_43 ) ) ;
V_8 += ( 1 << V_42 ) ;
}
F_218 ( & V_21 -> V_84 , V_58 ) ;
}
bool F_576 ( struct V_14 * V_14 )
{
struct V_21 * V_21 = F_25 ( V_14 ) ;
unsigned long V_8 = F_17 ( V_14 ) ;
unsigned long V_58 ;
unsigned int V_42 ;
F_212 ( & V_21 -> V_84 , V_58 ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
struct V_14 * V_622 = V_14 - ( V_8 & ( ( 1 << V_42 ) - 1 ) ) ;
if ( F_72 ( V_622 ) && F_68 ( V_622 ) >= V_42 )
break;
}
F_218 ( & V_21 -> V_84 , V_58 ) ;
return V_42 < V_52 ;
}
