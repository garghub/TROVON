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
if ( V_12 >= F_10 ( F_11 ( V_12 ) ) -> V_10 )
return true ;
return false ;
}
static inline bool F_12 ( unsigned long V_12 , int V_13 )
{
if ( V_12 >= F_10 ( V_13 ) -> V_10 )
return true ;
return false ;
}
static inline bool F_13 ( T_1 * V_9 ,
unsigned long V_12 , unsigned long V_14 ,
unsigned long * V_15 )
{
if ( V_14 < F_14 ( V_9 ) )
return true ;
( * V_15 ) ++ ;
if ( * V_15 > ( 2UL << ( 30 - V_16 ) ) &&
( V_12 & ( V_17 - 1 ) ) == 0 ) {
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
static inline bool F_12 ( unsigned long V_12 , int V_13 )
{
return false ;
}
static inline bool F_13 ( T_1 * V_9 ,
unsigned long V_12 , unsigned long V_14 ,
unsigned long * V_15 )
{
return true ;
}
void F_15 ( struct V_1 * V_1 , int V_3 )
{
if ( F_16 ( V_18 &&
V_3 < V_19 ) )
V_3 = V_20 ;
F_17 ( V_1 , ( unsigned long ) V_3 ,
V_21 , V_22 ) ;
}
static int F_18 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
int V_24 = 0 ;
unsigned V_25 ;
unsigned long V_12 = F_19 ( V_1 ) ;
unsigned long V_26 , V_27 ;
do {
V_25 = F_20 ( V_23 ) ;
V_27 = V_23 -> V_28 ;
V_26 = V_23 -> V_29 ;
if ( ! F_21 ( V_23 , V_12 ) )
V_24 = 1 ;
} while ( F_22 ( V_23 , V_25 ) );
if ( V_24 )
F_23 ( L_1 ,
V_12 , F_24 ( V_23 ) , V_23 -> V_30 ,
V_27 , V_27 + V_26 ) ;
return V_24 ;
}
static int F_25 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
if ( ! F_26 ( F_19 ( V_1 ) ) )
return 0 ;
if ( V_23 != F_27 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_28 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
if ( F_18 ( V_23 , V_1 ) )
return 1 ;
if ( ! F_25 ( V_23 , V_1 ) )
return 1 ;
return 0 ;
}
static inline int F_28 ( struct V_23 * V_23 , struct V_1 * V_1 )
{
return 0 ;
}
static void F_29 ( struct V_1 * V_1 , const char * V_31 ,
unsigned long V_32 )
{
static unsigned long V_33 ;
static unsigned long V_34 ;
static unsigned long V_35 ;
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 ) ;
return;
}
if ( V_34 == 60 ) {
if ( F_32 ( V_36 , V_33 ) ) {
V_35 ++ ;
goto V_37;
}
if ( V_35 ) {
F_33 ( V_38
L_2 ,
V_35 ) ;
V_35 = 0 ;
}
V_34 = 0 ;
}
if ( V_34 ++ == 0 )
V_33 = V_36 + 60 * V_39 ;
F_33 ( V_38 L_3 ,
V_40 -> V_41 , F_19 ( V_1 ) ) ;
F_34 ( V_1 , V_31 , V_32 ) ;
F_35 () ;
F_36 () ;
V_37:
F_31 ( V_1 ) ;
F_37 ( V_42 , V_43 ) ;
}
static void F_38 ( struct V_1 * V_1 )
{
F_39 ( V_1 , F_40 ( V_1 ) ) ;
}
void F_41 ( struct V_1 * V_1 , unsigned int V_44 )
{
int V_45 ;
int V_46 = 1 << V_44 ;
F_42 ( V_1 , V_47 ) ;
F_43 ( V_1 , V_44 ) ;
F_44 ( V_1 ) ;
for ( V_45 = 1 ; V_45 < V_46 ; V_45 ++ ) {
struct V_1 * V_48 = V_1 + V_45 ;
F_45 ( V_48 , 0 ) ;
F_46 ( V_48 , V_1 ) ;
}
}
static int T_3 F_47 ( char * V_49 )
{
if ( ! V_49 )
return - V_50 ;
if ( strcmp ( V_49 , L_4 ) == 0 )
V_51 = true ;
return 0 ;
}
static bool F_48 ( void )
{
if ( ! F_49 () )
return false ;
return true ;
}
static void F_50 ( void )
{
if ( ! F_49 () )
return;
V_52 = true ;
}
static int T_3 F_51 ( char * V_49 )
{
unsigned long V_53 ;
if ( F_52 ( V_49 , 10 , & V_53 ) < 0 || V_53 > V_54 / 2 ) {
F_33 ( V_55 L_5 ) ;
return 0 ;
}
V_56 = V_53 ;
F_33 ( V_57 L_6 , V_53 ) ;
return 0 ;
}
static inline void F_53 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 )
{
struct V_58 * V_58 ;
if ( ! F_54 () )
return;
V_58 = F_55 ( V_1 ) ;
F_56 ( V_59 , & V_58 -> V_60 ) ;
F_57 ( & V_1 -> V_61 ) ;
F_58 ( V_1 , V_44 ) ;
F_59 ( V_23 , - ( 1 << V_44 ) , V_3 ) ;
}
static inline void F_60 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 )
{
struct V_58 * V_58 ;
if ( ! F_54 () )
return;
V_58 = F_55 ( V_1 ) ;
F_61 ( V_59 , & V_58 -> V_60 ) ;
F_58 ( V_1 , 0 ) ;
if ( ! F_62 ( V_3 ) )
F_59 ( V_23 , ( 1 << V_44 ) , V_3 ) ;
}
static inline void F_53 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 ) {}
static inline void F_60 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 ) {}
static inline void F_63 ( struct V_1 * V_1 , unsigned int V_44 )
{
F_58 ( V_1 , V_44 ) ;
F_64 ( V_1 ) ;
}
static inline void F_65 ( struct V_1 * V_1 )
{
F_66 ( V_1 ) ;
F_58 ( V_1 , 0 ) ;
}
static inline int F_67 ( struct V_1 * V_1 , struct V_1 * V_62 ,
unsigned int V_44 )
{
if ( ! F_26 ( F_19 ( V_62 ) ) )
return 0 ;
if ( F_68 ( V_62 ) && F_69 ( V_62 ) == V_44 ) {
if ( F_70 ( V_1 ) != F_70 ( V_62 ) )
return 0 ;
F_71 ( F_72 ( V_62 ) != 0 , V_62 ) ;
return 1 ;
}
if ( F_73 ( V_62 ) && F_69 ( V_62 ) == V_44 ) {
if ( F_70 ( V_1 ) != F_70 ( V_62 ) )
return 0 ;
F_71 ( F_72 ( V_62 ) != 0 , V_62 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_74 ( struct V_1 * V_1 ,
unsigned long V_12 ,
struct V_23 * V_23 , unsigned int V_44 ,
int V_3 )
{
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_65 ( V_66 ) ;
struct V_1 * V_62 ;
unsigned int V_67 = V_54 ;
F_75 ( ! F_76 ( V_23 ) ) ;
F_71 ( V_1 -> V_60 & V_68 , V_1 ) ;
F_75 ( V_3 == - 1 ) ;
if ( F_62 ( V_3 ) ) {
V_67 = F_77 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
} else {
F_59 ( V_23 , 1 << V_44 , V_3 ) ;
}
V_63 = V_12 & ( ( 1 << V_67 ) - 1 ) ;
F_71 ( V_63 & ( ( 1 << V_44 ) - 1 ) , V_1 ) ;
F_71 ( F_28 ( V_23 , V_1 ) , V_1 ) ;
while ( V_44 < V_67 - 1 ) {
V_66 = F_78 ( V_63 , V_44 ) ;
V_62 = V_1 + ( V_66 - V_63 ) ;
if ( ! F_67 ( V_1 , V_62 , V_44 ) )
break;
if ( F_68 ( V_62 ) ) {
F_60 ( V_23 , V_62 , V_44 , V_3 ) ;
} else {
F_79 ( & V_62 -> V_61 ) ;
V_23 -> V_69 [ V_44 ] . V_70 -- ;
F_65 ( V_62 ) ;
}
V_64 = V_66 & V_63 ;
V_1 = V_1 + ( V_64 - V_63 ) ;
V_63 = V_64 ;
V_44 ++ ;
}
F_63 ( V_1 , V_44 ) ;
if ( ( V_44 < V_54 - 2 ) && F_26 ( F_19 ( V_62 ) ) ) {
struct V_1 * V_71 , * V_72 ;
V_64 = V_66 & V_63 ;
V_71 = V_1 + ( V_64 - V_63 ) ;
V_66 = F_78 ( V_64 , V_44 + 1 ) ;
V_72 = V_71 + ( V_66 - V_64 ) ;
if ( F_67 ( V_71 , V_72 , V_44 + 1 ) ) {
F_80 ( & V_1 -> V_61 ,
& V_23 -> V_69 [ V_44 ] . V_73 [ V_3 ] ) ;
goto V_37;
}
}
F_81 ( & V_1 -> V_61 , & V_23 -> V_69 [ V_44 ] . V_73 [ V_3 ] ) ;
V_37:
V_23 -> V_69 [ V_44 ] . V_70 ++ ;
}
static inline int F_82 ( struct V_1 * V_1 )
{
const char * V_74 = NULL ;
unsigned long V_32 = 0 ;
if ( F_16 ( F_83 ( V_1 ) ) )
V_74 = L_7 ;
if ( F_16 ( V_1 -> V_75 != NULL ) )
V_74 = L_8 ;
if ( F_16 ( F_84 ( & V_1 -> V_76 ) != 0 ) )
V_74 = L_9 ;
if ( F_16 ( V_1 -> V_60 & V_77 ) ) {
V_74 = L_10 ;
V_32 = V_77 ;
}
#ifdef F_85
if ( F_16 ( V_1 -> V_78 ) )
V_74 = L_11 ;
#endif
if ( F_16 ( V_74 ) ) {
F_29 ( V_1 , V_74 , V_32 ) ;
return 1 ;
}
F_86 ( V_1 ) ;
if ( V_1 -> V_60 & V_68 )
V_1 -> V_60 &= ~ V_68 ;
return 0 ;
}
static void F_87 ( struct V_23 * V_23 , int V_79 ,
struct V_80 * V_81 )
{
int V_3 = 0 ;
int V_82 = 0 ;
int V_83 = V_79 ;
unsigned long V_84 ;
F_88 ( & V_23 -> V_85 ) ;
V_84 = F_89 ( V_23 , V_86 ) ;
if ( V_84 )
F_90 ( V_23 , V_86 , - V_84 ) ;
while ( V_83 ) {
struct V_1 * V_1 ;
struct V_87 * V_88 ;
do {
V_82 ++ ;
if ( ++ V_3 == V_19 )
V_3 = 0 ;
V_88 = & V_81 -> V_89 [ V_3 ] ;
} while ( F_91 ( V_88 ) );
if ( V_82 == V_19 )
V_82 = V_83 ;
do {
int V_90 ;
V_1 = F_92 ( V_88 -> V_91 , struct V_1 , V_61 ) ;
F_79 ( & V_1 -> V_61 ) ;
V_90 = F_1 ( V_1 ) ;
F_71 ( F_62 ( V_90 ) , V_1 ) ;
if ( F_16 ( F_93 ( V_23 ) ) )
V_90 = F_94 ( V_1 ) ;
F_74 ( V_1 , F_19 ( V_1 ) , V_23 , 0 , V_90 ) ;
F_95 ( V_1 , 0 , V_90 ) ;
} while ( -- V_83 && -- V_82 && ! F_91 ( V_88 ) );
}
F_96 ( & V_23 -> V_85 ) ;
}
static void F_97 ( struct V_23 * V_23 ,
struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_44 ,
int V_3 )
{
unsigned long V_84 ;
F_88 ( & V_23 -> V_85 ) ;
V_84 = F_89 ( V_23 , V_86 ) ;
if ( V_84 )
F_90 ( V_23 , V_86 , - V_84 ) ;
if ( F_16 ( F_93 ( V_23 ) ||
F_62 ( V_3 ) ) ) {
V_3 = F_98 ( V_1 , V_12 ) ;
}
F_74 ( V_1 , V_12 , V_23 , V_44 , V_3 ) ;
F_96 ( & V_23 -> V_85 ) ;
}
static int F_99 ( struct V_1 * V_92 , struct V_1 * V_1 )
{
int V_24 = 1 ;
F_100 ( ( unsigned long ) V_93 & 1 ) ;
if ( ! F_101 ( V_94 ) ) {
V_24 = 0 ;
goto V_37;
}
if ( F_16 ( ! F_102 ( V_1 ) ) ) {
F_29 ( V_1 , L_12 , 0 ) ;
goto V_37;
}
if ( F_16 ( F_103 ( V_1 ) != V_92 ) ) {
F_29 ( V_1 , L_13 , 0 ) ;
goto V_37;
}
V_24 = 0 ;
V_37:
F_104 ( V_1 ) ;
return V_24 ;
}
static void T_2 F_105 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_23 , int V_13 )
{
F_106 ( V_1 , V_23 , V_13 , V_12 ) ;
F_107 ( V_1 ) ;
F_31 ( V_1 ) ;
F_86 ( V_1 ) ;
F_57 ( & V_1 -> V_61 ) ;
#ifdef F_108
if ( ! F_109 ( V_23 ) )
F_110 ( V_1 , F_111 ( V_12 << V_16 ) ) ;
#endif
}
static void T_2 F_112 ( unsigned long V_12 , unsigned long V_23 ,
int V_13 )
{
return F_105 ( F_113 ( V_12 ) , V_12 , V_23 , V_13 ) ;
}
static void F_114 ( unsigned long V_12 )
{
T_1 * V_9 ;
int V_13 , V_95 ;
if ( ! F_9 ( V_12 ) )
return;
V_13 = F_11 ( V_12 ) ;
V_9 = F_10 ( V_13 ) ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
struct V_23 * V_23 = & V_9 -> V_97 [ V_95 ] ;
if ( V_12 >= V_23 -> V_28 && V_12 < F_115 ( V_23 ) )
break;
}
F_112 ( V_12 , V_95 , V_13 ) ;
}
static inline void F_114 ( unsigned long V_12 )
{
}
void T_2 F_116 ( unsigned long V_98 , unsigned long V_99 )
{
unsigned long V_27 = F_117 ( V_98 ) ;
unsigned long V_100 = F_118 ( V_99 ) ;
for (; V_27 < V_100 ; V_27 ++ ) {
if ( F_119 ( V_27 ) ) {
struct V_1 * V_1 = F_113 ( V_27 ) ;
F_114 ( V_27 ) ;
F_57 ( & V_1 -> V_61 ) ;
F_120 ( V_1 ) ;
}
}
}
static bool F_121 ( struct V_1 * V_1 , unsigned int V_44 )
{
bool V_101 = F_122 ( V_1 ) ;
int V_45 , V_102 = 0 ;
F_71 ( F_102 ( V_1 ) , V_1 ) ;
F_71 ( V_101 && F_40 ( V_1 ) != V_44 , V_1 ) ;
F_123 ( V_1 , V_44 ) ;
F_124 ( V_1 , V_44 ) ;
F_125 ( V_1 , V_44 ) ;
if ( F_126 ( V_1 ) )
V_1 -> V_75 = NULL ;
V_102 += F_82 ( V_1 ) ;
for ( V_45 = 1 ; V_45 < ( 1 << V_44 ) ; V_45 ++ ) {
if ( V_101 )
V_102 += F_99 ( V_1 , V_1 + V_45 ) ;
V_102 += F_82 ( V_1 + V_45 ) ;
}
if ( V_102 )
return false ;
F_127 ( V_1 , V_44 ) ;
if ( ! F_128 ( V_1 ) ) {
F_129 ( F_130 ( V_1 ) ,
V_103 << V_44 ) ;
F_131 ( F_130 ( V_1 ) ,
V_103 << V_44 ) ;
}
F_132 ( V_1 , V_44 ) ;
F_133 ( V_1 , 1 << V_44 , 0 ) ;
return true ;
}
static void F_39 ( struct V_1 * V_1 , unsigned int V_44 )
{
unsigned long V_60 ;
int V_3 ;
unsigned long V_12 = F_19 ( V_1 ) ;
if ( ! F_121 ( V_1 , V_44 ) )
return;
V_3 = F_98 ( V_1 , V_12 ) ;
F_134 ( V_60 ) ;
F_135 ( V_104 , 1 << V_44 ) ;
F_97 ( F_27 ( V_1 ) , V_1 , V_12 , V_44 , V_3 ) ;
F_136 ( V_60 ) ;
}
static void T_3 F_137 ( struct V_1 * V_1 ,
unsigned long V_12 , unsigned int V_44 )
{
unsigned int V_46 = 1 << V_44 ;
struct V_1 * V_48 = V_1 ;
unsigned int V_105 ;
F_138 ( V_48 ) ;
for ( V_105 = 0 ; V_105 < ( V_46 - 1 ) ; V_105 ++ , V_48 ++ ) {
F_138 ( V_48 + 1 ) ;
F_139 ( V_48 ) ;
F_45 ( V_48 , 0 ) ;
}
F_139 ( V_48 ) ;
F_45 ( V_48 , 0 ) ;
F_27 ( V_1 ) -> V_106 += V_46 ;
F_140 ( V_1 ) ;
F_141 ( V_1 , V_44 ) ;
}
int T_2 F_11 ( unsigned long V_12 )
{
static F_142 ( V_107 ) ;
int V_13 ;
F_88 ( & V_107 ) ;
V_13 = F_143 ( V_12 , & V_108 ) ;
if ( V_13 < 0 )
V_13 = 0 ;
F_96 ( & V_107 ) ;
return V_13 ;
}
static inline bool T_2 F_144 ( unsigned long V_12 , int V_109 ,
struct V_110 * V_111 )
{
int V_13 ;
V_13 = F_143 ( V_12 , V_111 ) ;
if ( V_13 >= 0 && V_13 != V_109 )
return false ;
return true ;
}
static inline bool T_2 F_145 ( unsigned long V_12 , int V_109 )
{
return F_144 ( V_12 , V_109 , & V_108 ) ;
}
static inline bool T_2 F_145 ( unsigned long V_12 , int V_109 )
{
return true ;
}
static inline bool T_2 F_144 ( unsigned long V_12 , int V_109 ,
struct V_110 * V_111 )
{
return true ;
}
void T_3 F_146 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_44 )
{
if ( F_9 ( V_12 ) )
return;
return F_137 ( V_1 , V_12 , V_44 ) ;
}
static void T_3 F_147 ( struct V_1 * V_1 ,
unsigned long V_12 , int V_46 )
{
int V_45 ;
if ( ! V_1 )
return;
if ( V_46 == V_112 &&
( V_12 & ( V_112 - 1 ) ) == 0 ) {
F_15 ( V_1 , V_113 ) ;
F_137 ( V_1 , V_12 , V_54 - 1 ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ , V_1 ++ , V_12 ++ )
F_137 ( V_1 , V_12 , 0 ) ;
}
static inline void T_3 F_148 ( void )
{
if ( F_149 ( & V_114 ) )
F_150 ( & V_115 ) ;
}
static int T_3 F_151 ( void * V_116 )
{
T_1 * V_9 = V_116 ;
int V_13 = V_9 -> V_117 ;
struct V_110 V_118 = { } ;
unsigned long V_98 = V_36 ;
unsigned long V_46 = 0 ;
unsigned long V_119 , V_120 ;
int V_45 , V_95 ;
struct V_23 * V_23 ;
unsigned long V_121 = V_9 -> V_10 ;
const struct V_122 * V_122 = F_152 ( V_9 -> V_117 ) ;
if ( V_121 == V_11 ) {
F_148 () ;
return 0 ;
}
if ( ! F_153 ( V_122 ) )
F_154 ( V_40 , V_122 ) ;
F_155 ( V_9 -> V_10 < V_9 -> V_123 ) ;
F_155 ( V_9 -> V_10 > F_14 ( V_9 ) ) ;
V_9 -> V_10 = V_11 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
V_23 = V_9 -> V_97 + V_95 ;
if ( V_121 < F_115 ( V_23 ) )
break;
}
F_156 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_12 , V_100 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_124 = NULL ;
unsigned long V_125 = 0 ;
int V_126 = 0 ;
V_100 = F_157 ( V_120 , F_115 ( V_23 ) ) ;
V_12 = V_121 ;
if ( V_12 < V_119 )
V_12 = V_119 ;
if ( V_12 < V_23 -> V_28 )
V_12 = V_23 -> V_28 ;
for (; V_12 < V_100 ; V_12 ++ ) {
if ( ! F_26 ( V_12 ) )
goto V_127;
if ( ( V_12 & ( V_112 - 1 ) ) == 0 ) {
if ( ! F_119 ( V_12 ) ) {
V_1 = NULL ;
goto V_127;
}
}
if ( ! F_144 ( V_12 , V_13 , & V_118 ) ) {
V_1 = NULL ;
goto V_127;
}
if ( V_1 && ( V_12 & ( V_112 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_46 += V_126 ;
F_147 ( V_124 ,
V_125 , V_126 ) ;
V_124 = NULL ;
V_125 = V_126 = 0 ;
V_1 = F_113 ( V_12 ) ;
F_158 () ;
}
if ( V_1 -> V_60 ) {
F_75 ( F_27 ( V_1 ) != V_23 ) ;
goto V_127;
}
F_105 ( V_1 , V_12 , V_95 , V_13 ) ;
if ( ! V_124 ) {
V_124 = V_1 ;
V_125 = V_12 ;
V_126 = 0 ;
}
V_126 ++ ;
continue;
V_127:
V_46 += V_126 ;
F_147 ( V_124 , V_125 ,
V_126 ) ;
V_124 = NULL ;
V_125 = V_126 = 0 ;
}
V_121 = F_159 ( V_100 , V_121 ) ;
}
F_4 ( ++ V_95 < V_96 && F_160 ( ++ V_23 ) ) ;
F_161 ( L_14 , V_13 , V_46 ,
F_162 ( V_36 - V_98 ) ) ;
F_148 () ;
return 0 ;
}
void T_3 F_163 ( void )
{
int V_13 ;
F_164 ( & V_114 , F_165 ( V_128 ) ) ;
F_166 (nid, N_MEMORY) {
F_167 ( F_151 , F_10 ( V_13 ) , L_15 , V_13 ) ;
}
F_168 ( & V_115 ) ;
F_169 () ;
}
void T_3 F_170 ( struct V_1 * V_1 )
{
unsigned V_45 = V_129 ;
struct V_1 * V_48 = V_1 ;
do {
F_139 ( V_48 ) ;
F_45 ( V_48 , 0 ) ;
} while ( ++ V_48 , -- V_45 );
F_15 ( V_1 , V_130 ) ;
if ( V_131 >= V_54 ) {
V_45 = V_129 ;
V_48 = V_1 ;
do {
F_140 ( V_48 ) ;
F_141 ( V_48 , V_54 - 1 ) ;
V_48 += V_112 ;
} while ( V_45 -= V_112 );
} else {
F_140 ( V_1 ) ;
F_141 ( V_1 , V_131 ) ;
}
F_171 ( V_1 , V_129 ) ;
}
static inline void F_172 ( struct V_23 * V_23 , struct V_1 * V_1 ,
int V_132 , int V_133 , struct V_69 * V_134 ,
int V_3 )
{
unsigned long V_135 = 1 << V_133 ;
while ( V_133 > V_132 ) {
V_134 -- ;
V_133 -- ;
V_135 >>= 1 ;
F_71 ( F_28 ( V_23 , & V_1 [ V_135 ] ) , & V_1 [ V_135 ] ) ;
if ( F_101 ( V_136 ) &&
F_54 () &&
V_133 < F_173 () ) {
F_53 ( V_23 , & V_1 [ V_135 ] , V_133 , V_3 ) ;
continue;
}
F_81 ( & V_1 [ V_135 ] . V_61 , & V_134 -> V_73 [ V_3 ] ) ;
V_134 -> V_70 ++ ;
F_63 ( & V_1 [ V_135 ] , V_133 ) ;
}
}
static inline int F_174 ( struct V_1 * V_1 )
{
const char * V_74 = NULL ;
unsigned long V_32 = 0 ;
if ( F_16 ( F_83 ( V_1 ) ) )
V_74 = L_7 ;
if ( F_16 ( V_1 -> V_75 != NULL ) )
V_74 = L_8 ;
if ( F_16 ( F_84 ( & V_1 -> V_76 ) != 0 ) )
V_74 = L_9 ;
if ( F_16 ( V_1 -> V_60 & V_137 ) ) {
V_74 = L_16 ;
V_32 = V_137 ;
}
if ( F_16 ( V_1 -> V_60 & V_68 ) ) {
V_74 = L_17 ;
V_32 = V_68 ;
}
#ifdef F_85
if ( F_16 ( V_1 -> V_78 ) )
V_74 = L_11 ;
#endif
if ( F_16 ( V_74 ) ) {
F_29 ( V_1 , V_74 , V_32 ) ;
return 1 ;
}
return 0 ;
}
static int F_175 ( struct V_1 * V_1 , unsigned int V_44 , T_4 V_138 ,
int V_139 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < ( 1 << V_44 ) ; V_45 ++ ) {
struct V_1 * V_48 = V_1 + V_45 ;
if ( F_16 ( F_174 ( V_48 ) ) )
return 1 ;
}
F_58 ( V_1 , 0 ) ;
F_140 ( V_1 ) ;
F_176 ( V_1 , V_44 ) ;
F_133 ( V_1 , 1 << V_44 , 1 ) ;
F_177 ( V_1 , V_44 ) ;
if ( V_138 & V_140 )
for ( V_45 = 0 ; V_45 < ( 1 << V_44 ) ; V_45 ++ )
F_178 ( V_1 + V_45 ) ;
if ( V_44 && ( V_138 & V_141 ) )
F_41 ( V_1 , V_44 ) ;
F_179 ( V_1 , V_44 , V_138 ) ;
if ( V_139 & V_142 )
F_180 ( V_1 ) ;
else
F_181 ( V_1 ) ;
return 0 ;
}
static inline
struct V_1 * F_182 ( struct V_23 * V_23 , unsigned int V_44 ,
int V_3 )
{
unsigned int V_143 ;
struct V_69 * V_134 ;
struct V_1 * V_1 ;
for ( V_143 = V_44 ; V_143 < V_54 ; ++ V_143 ) {
V_134 = & ( V_23 -> V_69 [ V_143 ] ) ;
if ( F_91 ( & V_134 -> V_73 [ V_3 ] ) )
continue;
V_1 = F_92 ( V_134 -> V_73 [ V_3 ] . V_144 ,
struct V_1 , V_61 ) ;
F_79 ( & V_1 -> V_61 ) ;
F_65 ( V_1 ) ;
V_134 -> V_70 -- ;
F_172 ( V_23 , V_1 , V_44 , V_143 , V_134 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_183 ( struct V_23 * V_23 ,
unsigned int V_44 )
{
return F_182 ( V_23 , V_44 , V_130 ) ;
}
static inline struct V_1 * F_183 ( struct V_23 * V_23 ,
unsigned int V_44 ) { return NULL ; }
int F_184 ( struct V_23 * V_23 ,
struct V_1 * V_145 , struct V_1 * V_146 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned int V_44 ;
int V_147 = 0 ;
#ifndef F_185
F_75 ( F_27 ( V_145 ) != F_27 ( V_146 ) ) ;
#endif
for ( V_1 = V_145 ; V_1 <= V_146 ; ) {
F_71 ( F_186 ( V_1 ) != F_24 ( V_23 ) , V_1 ) ;
if ( ! F_26 ( F_19 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
if ( ! F_73 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_44 = F_69 ( V_1 ) ;
F_187 ( & V_1 -> V_61 ,
& V_23 -> V_69 [ V_44 ] . V_73 [ V_3 ] ) ;
V_1 += 1 << V_44 ;
V_147 += 1 << V_44 ;
}
return V_147 ;
}
int F_188 ( struct V_23 * V_23 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_27 , V_100 ;
struct V_1 * V_145 , * V_146 ;
V_27 = F_19 ( V_1 ) ;
V_27 = V_27 & ~ ( V_129 - 1 ) ;
V_145 = F_113 ( V_27 ) ;
V_146 = V_145 + V_129 - 1 ;
V_100 = V_27 + V_129 - 1 ;
if ( ! F_21 ( V_23 , V_27 ) )
V_145 = V_1 ;
if ( ! F_21 ( V_23 , V_100 ) )
return 0 ;
return F_184 ( V_23 , V_145 , V_146 , V_3 ) ;
}
static void F_189 ( struct V_1 * V_148 ,
int V_149 , int V_3 )
{
int V_150 = 1 << ( V_149 - V_131 ) ;
while ( V_150 -- ) {
F_15 ( V_148 , V_3 ) ;
V_148 += V_129 ;
}
}
static bool F_190 ( unsigned int V_44 , int V_151 )
{
if ( V_44 >= V_131 )
return true ;
if ( V_44 >= V_131 / 2 ||
V_151 == V_152 ||
V_151 == V_20 ||
V_18 )
return true ;
return false ;
}
static void F_191 ( struct V_23 * V_23 , struct V_1 * V_1 ,
int V_153 )
{
unsigned int V_143 = F_69 ( V_1 ) ;
int V_154 ;
if ( V_143 >= V_131 ) {
F_189 ( V_1 , V_143 , V_153 ) ;
return;
}
V_154 = F_188 ( V_23 , V_1 , V_153 ) ;
if ( V_154 >= ( 1 << ( V_131 - 1 ) ) ||
V_18 )
F_15 ( V_1 , V_153 ) ;
}
int F_192 ( struct V_69 * V_134 , unsigned int V_44 ,
int V_3 , bool V_155 , bool * V_156 )
{
int V_45 ;
int V_157 ;
if ( V_134 -> V_70 == 0 )
return - 1 ;
* V_156 = false ;
for ( V_45 = 0 ; ; V_45 ++ ) {
V_157 = V_158 [ V_3 ] [ V_45 ] ;
if ( V_157 == V_159 )
break;
if ( F_91 ( & V_134 -> V_73 [ V_157 ] ) )
continue;
if ( F_190 ( V_44 , V_3 ) )
* V_156 = true ;
if ( ! V_155 )
return V_157 ;
if ( * V_156 )
return V_157 ;
}
return - 1 ;
}
static void F_193 ( struct V_1 * V_1 , struct V_23 * V_23 ,
unsigned int V_160 )
{
int V_90 ;
unsigned long V_161 , V_60 ;
V_161 = ( V_23 -> V_106 / 100 ) + V_129 ;
if ( V_23 -> V_162 >= V_161 )
return;
F_194 ( & V_23 -> V_85 , V_60 ) ;
if ( V_23 -> V_162 >= V_161 )
goto V_163;
V_90 = F_94 ( V_1 ) ;
if ( V_90 != V_164 &&
! F_62 ( V_90 ) && ! F_195 ( V_90 ) ) {
V_23 -> V_162 += V_129 ;
F_15 ( V_1 , V_164 ) ;
F_188 ( V_23 , V_1 , V_164 ) ;
}
V_163:
F_196 ( & V_23 -> V_85 , V_60 ) ;
}
static void F_197 ( const struct V_165 * V_166 )
{
struct V_167 * V_167 = V_166 -> V_167 ;
unsigned long V_60 ;
struct V_168 * V_169 ;
struct V_23 * V_23 ;
struct V_1 * V_1 ;
int V_44 ;
F_198 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( V_23 -> V_162 <= V_129 )
continue;
F_194 ( & V_23 -> V_85 , V_60 ) ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_69 * V_134 = & ( V_23 -> V_69 [ V_44 ] ) ;
if ( F_91 ( & V_134 -> V_73 [ V_164 ] ) )
continue;
V_1 = F_92 ( V_134 -> V_73 [ V_164 ] . V_144 ,
struct V_1 , V_61 ) ;
V_23 -> V_162 -= F_157 ( V_129 ,
V_23 -> V_162 ) ;
F_15 ( V_1 , V_166 -> V_3 ) ;
F_188 ( V_23 , V_1 , V_166 -> V_3 ) ;
F_196 ( & V_23 -> V_85 , V_60 ) ;
return;
}
F_196 ( & V_23 -> V_85 , V_60 ) ;
}
}
static inline struct V_1 *
F_199 ( struct V_23 * V_23 , unsigned int V_44 , int V_170 )
{
struct V_69 * V_134 ;
unsigned int V_143 ;
struct V_1 * V_1 ;
int V_157 ;
bool V_156 ;
for ( V_143 = V_54 - 1 ;
V_143 >= V_44 && V_143 <= V_54 - 1 ;
-- V_143 ) {
V_134 = & ( V_23 -> V_69 [ V_143 ] ) ;
V_157 = F_192 ( V_134 , V_143 ,
V_170 , false , & V_156 ) ;
if ( V_157 == - 1 )
continue;
V_1 = F_92 ( V_134 -> V_73 [ V_157 ] . V_144 ,
struct V_1 , V_61 ) ;
if ( V_156 )
F_191 ( V_23 , V_1 , V_170 ) ;
V_134 -> V_70 -- ;
F_79 ( & V_1 -> V_61 ) ;
F_65 ( V_1 ) ;
F_172 ( V_23 , V_1 , V_44 , V_143 , V_134 ,
V_170 ) ;
F_2 ( V_1 , V_170 ) ;
F_200 ( V_1 , V_44 , V_143 ,
V_170 , V_157 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_201 ( struct V_23 * V_23 , unsigned int V_44 ,
int V_3 , T_4 V_138 )
{
struct V_1 * V_1 ;
V_1 = F_182 ( V_23 , V_44 , V_3 ) ;
if ( F_16 ( ! V_1 ) ) {
if ( V_3 == V_113 )
V_1 = F_183 ( V_23 , V_44 ) ;
if ( ! V_1 )
V_1 = F_199 ( V_23 , V_44 , V_3 ) ;
}
F_202 ( V_1 , V_44 , V_3 ) ;
return V_1 ;
}
static int F_203 ( struct V_23 * V_23 , unsigned int V_44 ,
unsigned long V_79 , struct V_87 * V_88 ,
int V_3 , bool V_171 )
{
int V_45 ;
F_88 ( & V_23 -> V_85 ) ;
for ( V_45 = 0 ; V_45 < V_79 ; ++ V_45 ) {
struct V_1 * V_1 = F_201 ( V_23 , V_44 , V_3 , 0 ) ;
if ( F_16 ( V_1 == NULL ) )
break;
if ( F_204 ( ! V_171 ) )
F_81 ( & V_1 -> V_61 , V_88 ) ;
else
F_80 ( & V_1 -> V_61 , V_88 ) ;
V_88 = & V_1 -> V_61 ;
if ( F_195 ( F_1 ( V_1 ) ) )
F_90 ( V_23 , V_172 ,
- ( 1 << V_44 ) ) ;
}
F_90 ( V_23 , V_173 , - ( V_45 << V_44 ) ) ;
F_96 ( & V_23 -> V_85 ) ;
return V_45 ;
}
void F_205 ( struct V_23 * V_23 , struct V_80 * V_81 )
{
unsigned long V_60 ;
int V_174 , V_175 ;
F_134 ( V_60 ) ;
V_175 = F_206 ( V_81 -> V_175 ) ;
V_174 = F_157 ( V_81 -> V_79 , V_175 ) ;
if ( V_174 > 0 ) {
F_87 ( V_23 , V_174 , V_81 ) ;
V_81 -> V_79 -= V_174 ;
}
F_136 ( V_60 ) ;
}
static void F_207 ( unsigned int V_176 , struct V_23 * V_23 )
{
unsigned long V_60 ;
struct V_177 * V_178 ;
struct V_80 * V_81 ;
F_134 ( V_60 ) ;
V_178 = F_208 ( V_23 -> V_179 , V_176 ) ;
V_81 = & V_178 -> V_81 ;
if ( V_81 -> V_79 ) {
F_87 ( V_23 , V_81 -> V_79 , V_81 ) ;
V_81 -> V_79 = 0 ;
}
F_136 ( V_60 ) ;
}
static void F_209 ( unsigned int V_176 )
{
struct V_23 * V_23 ;
F_210 (zone) {
F_207 ( V_176 , V_23 ) ;
}
}
void F_211 ( struct V_23 * V_23 )
{
int V_176 = F_212 () ;
if ( V_23 )
F_207 ( V_176 , V_23 ) ;
else
F_209 ( V_176 ) ;
}
void F_213 ( struct V_23 * V_23 )
{
int V_176 ;
static T_5 V_180 ;
F_214 (cpu) {
struct V_177 * V_81 ;
struct V_23 * V_169 ;
bool V_181 = false ;
if ( V_23 ) {
V_81 = F_208 ( V_23 -> V_179 , V_176 ) ;
if ( V_81 -> V_81 . V_79 )
V_181 = true ;
} else {
F_210 (z) {
V_81 = F_208 ( V_169 -> V_179 , V_176 ) ;
if ( V_81 -> V_81 . V_79 ) {
V_181 = true ;
break;
}
}
}
if ( V_181 )
F_215 ( V_176 , & V_180 ) ;
else
F_216 ( V_176 , & V_180 ) ;
}
F_217 ( & V_180 , ( V_182 ) F_211 ,
V_23 , 1 ) ;
}
void F_218 ( struct V_23 * V_23 )
{
unsigned long V_12 , V_183 ;
unsigned long V_60 ;
unsigned int V_44 , V_184 ;
struct V_87 * V_185 ;
if ( F_219 ( V_23 ) )
return;
F_194 ( & V_23 -> V_85 , V_60 ) ;
V_183 = F_115 ( V_23 ) ;
for ( V_12 = V_23 -> V_28 ; V_12 < V_183 ; V_12 ++ )
if ( F_119 ( V_12 ) ) {
struct V_1 * V_1 = F_113 ( V_12 ) ;
if ( ! F_220 ( V_1 ) )
F_221 ( V_1 ) ;
}
F_222 (order, t) {
F_223 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_45 ;
V_12 = F_19 ( F_92 ( V_185 , struct V_1 , V_61 ) ) ;
for ( V_45 = 0 ; V_45 < ( 1UL << V_44 ) ; V_45 ++ )
F_224 ( F_113 ( V_12 + V_45 ) ) ;
}
}
F_196 ( & V_23 -> V_85 , V_60 ) ;
}
void F_225 ( struct V_1 * V_1 , bool V_171 )
{
struct V_23 * V_23 = F_27 ( V_1 ) ;
struct V_80 * V_81 ;
unsigned long V_60 ;
unsigned long V_12 = F_19 ( V_1 ) ;
int V_3 ;
if ( ! F_121 ( V_1 , 0 ) )
return;
V_3 = F_98 ( V_1 , V_12 ) ;
F_2 ( V_1 , V_3 ) ;
F_134 ( V_60 ) ;
F_226 ( V_104 ) ;
if ( V_3 >= V_19 ) {
if ( F_16 ( F_62 ( V_3 ) ) ) {
F_97 ( V_23 , V_1 , V_12 , 0 , V_3 ) ;
goto V_37;
}
V_3 = V_113 ;
}
V_81 = & F_227 ( V_23 -> V_179 ) -> V_81 ;
if ( ! V_171 )
F_81 ( & V_1 -> V_61 , & V_81 -> V_89 [ V_3 ] ) ;
else
F_80 ( & V_1 -> V_61 , & V_81 -> V_89 [ V_3 ] ) ;
V_81 -> V_79 ++ ;
if ( V_81 -> V_79 >= V_81 -> V_133 ) {
unsigned long V_175 = F_206 ( V_81 -> V_175 ) ;
F_87 ( V_23 , V_175 , V_81 ) ;
V_81 -> V_79 -= V_175 ;
}
V_37:
F_136 ( V_60 ) ;
}
void F_228 ( struct V_87 * V_88 , bool V_171 )
{
struct V_1 * V_1 , * V_144 ;
F_229 (page, next, list, lru) {
F_230 ( V_1 , V_171 ) ;
F_225 ( V_1 , V_171 ) ;
}
}
void F_231 ( struct V_1 * V_1 , unsigned int V_44 )
{
int V_45 ;
T_4 V_186 ;
F_71 ( F_122 ( V_1 ) , V_1 ) ;
F_71 ( ! F_72 ( V_1 ) , V_1 ) ;
#ifdef F_232
if ( F_233 ( V_1 ) )
F_231 ( F_234 ( V_1 [ 0 ] . V_187 ) , V_44 ) ;
#endif
V_186 = F_235 ( V_1 ) ;
F_179 ( V_1 , 0 , V_186 ) ;
for ( V_45 = 1 ; V_45 < ( 1 << V_44 ) ; V_45 ++ ) {
F_140 ( V_1 + V_45 ) ;
F_179 ( V_1 + V_45 , 0 , V_186 ) ;
}
}
int F_236 ( struct V_1 * V_1 , unsigned int V_44 )
{
unsigned long V_188 ;
struct V_23 * V_23 ;
int V_90 ;
F_155 ( ! F_73 ( V_1 ) ) ;
V_23 = F_27 ( V_1 ) ;
V_90 = F_94 ( V_1 ) ;
if ( ! F_62 ( V_90 ) ) {
V_188 = F_237 ( V_23 ) + ( 1 << V_44 ) ;
if ( ! F_238 ( V_23 , 0 , V_188 , 0 , 0 ) )
return 0 ;
F_59 ( V_23 , - ( 1UL << V_44 ) , V_90 ) ;
}
F_79 ( & V_1 -> V_61 ) ;
V_23 -> V_69 [ V_44 ] . V_70 -- ;
F_65 ( V_1 ) ;
F_179 ( V_1 , V_44 , V_189 ) ;
if ( V_44 >= V_131 - 1 ) {
struct V_1 * V_190 = V_1 + ( 1 << V_44 ) - 1 ;
for (; V_1 < V_190 ; V_1 += V_129 ) {
int V_90 = F_94 ( V_1 ) ;
if ( ! F_62 ( V_90 ) && ! F_195 ( V_90 ) )
F_15 ( V_1 ,
V_113 ) ;
}
}
return 1UL << V_44 ;
}
int F_239 ( struct V_1 * V_1 )
{
unsigned int V_44 ;
int V_46 ;
V_44 = F_69 ( V_1 ) ;
V_46 = F_236 ( V_1 , V_44 ) ;
if ( ! V_46 )
return 0 ;
F_140 ( V_1 ) ;
F_231 ( V_1 , V_44 ) ;
return V_46 ;
}
static inline
struct V_1 * F_240 ( struct V_23 * V_191 ,
struct V_23 * V_23 , unsigned int V_44 ,
T_4 V_138 , int V_139 , int V_3 )
{
unsigned long V_60 ;
struct V_1 * V_1 ;
bool V_171 = ( ( V_138 & V_192 ) != 0 ) ;
if ( F_204 ( V_44 == 0 ) ) {
struct V_80 * V_81 ;
struct V_87 * V_88 ;
F_134 ( V_60 ) ;
V_81 = & F_227 ( V_23 -> V_179 ) -> V_81 ;
V_88 = & V_81 -> V_89 [ V_3 ] ;
if ( F_91 ( V_88 ) ) {
V_81 -> V_79 += F_203 ( V_23 , 0 ,
V_81 -> V_175 , V_88 ,
V_3 , V_171 ) ;
if ( F_16 ( F_91 ( V_88 ) ) )
goto V_193;
}
if ( V_171 )
V_1 = F_92 ( V_88 -> V_91 , struct V_1 , V_61 ) ;
else
V_1 = F_92 ( V_88 -> V_144 , struct V_1 , V_61 ) ;
F_79 ( & V_1 -> V_61 ) ;
V_81 -> V_79 -- ;
} else {
if ( F_16 ( V_138 & V_194 ) ) {
F_241 ( V_44 > 1 ) ;
}
F_194 ( & V_23 -> V_85 , V_60 ) ;
V_1 = NULL ;
if ( V_139 & V_195 ) {
V_1 = F_182 ( V_23 , V_44 , V_164 ) ;
if ( V_1 )
F_202 ( V_1 , V_44 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_201 ( V_23 , V_44 , V_3 , V_138 ) ;
F_96 ( & V_23 -> V_85 ) ;
if ( ! V_1 )
goto V_193;
F_59 ( V_23 , - ( 1 << V_44 ) ,
F_1 ( V_1 ) ) ;
}
F_90 ( V_23 , V_196 , - ( 1 << V_44 ) ) ;
if ( F_242 ( & V_23 -> V_197 [ V_196 ] ) <= 0 &&
! F_243 ( V_198 , & V_23 -> V_60 ) )
F_244 ( V_198 , & V_23 -> V_60 ) ;
F_245 ( V_199 , V_23 , 1 << V_44 ) ;
F_246 ( V_191 , V_23 , V_138 ) ;
F_136 ( V_60 ) ;
F_71 ( F_28 ( V_23 , V_1 ) , V_1 ) ;
return V_1 ;
V_193:
F_136 ( V_60 ) ;
return NULL ;
}
static int T_3 F_247 ( char * V_200 )
{
return F_248 ( & V_201 . V_202 , V_200 ) ;
}
static bool F_249 ( T_4 V_186 , unsigned int V_44 )
{
if ( V_44 < V_201 . V_203 )
return false ;
if ( V_186 & V_194 )
return false ;
if ( V_201 . V_204 && ( V_186 & V_205 ) )
return false ;
if ( V_201 . V_206 &&
( V_186 & V_207 ) )
return false ;
return F_250 ( & V_201 . V_202 , 1 << V_44 ) ;
}
static int T_3 F_251 ( void )
{
T_6 V_208 = V_209 | V_210 | V_211 ;
struct V_212 * V_213 ;
V_213 = F_252 ( L_18 , NULL ,
& V_201 . V_202 ) ;
if ( F_253 ( V_213 ) )
return F_254 ( V_213 ) ;
if ( ! F_255 ( L_19 , V_208 , V_213 ,
& V_201 . V_206 ) )
goto V_214;
if ( ! F_255 ( L_20 , V_208 , V_213 ,
& V_201 . V_204 ) )
goto V_214;
if ( ! F_256 ( L_21 , V_208 , V_213 ,
& V_201 . V_203 ) )
goto V_214;
return 0 ;
V_214:
F_257 ( V_213 ) ;
return - V_215 ;
}
static inline bool F_249 ( T_4 V_186 , unsigned int V_44 )
{
return false ;
}
static bool F_258 ( struct V_23 * V_169 , unsigned int V_44 ,
unsigned long V_216 , int V_217 , int V_139 ,
long V_218 )
{
long F_157 = V_216 ;
int V_219 ;
const int V_220 = ( V_139 & V_195 ) ;
V_218 -= ( 1 << V_44 ) - 1 ;
if ( V_139 & V_221 )
F_157 -= F_157 / 2 ;
if ( F_204 ( ! V_220 ) )
V_218 -= V_169 -> V_162 ;
else
F_157 -= F_157 / 4 ;
#ifdef F_259
if ( ! ( V_139 & V_222 ) )
V_218 -= F_89 ( V_169 , V_172 ) ;
#endif
if ( V_218 <= F_157 + V_169 -> V_223 [ V_217 ] )
return false ;
if ( ! V_44 )
return true ;
for ( V_219 = V_44 ; V_219 < V_54 ; V_219 ++ ) {
struct V_69 * V_134 = & V_169 -> V_69 [ V_219 ] ;
int V_90 ;
if ( ! V_134 -> V_70 )
continue;
if ( V_220 )
return true ;
for ( V_90 = 0 ; V_90 < V_19 ; V_90 ++ ) {
if ( ! F_91 ( & V_134 -> V_73 [ V_90 ] ) )
return true ;
}
#ifdef F_259
if ( ( V_139 & V_222 ) &&
! F_91 ( & V_134 -> V_73 [ V_130 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_238 ( struct V_23 * V_169 , unsigned int V_44 , unsigned long V_216 ,
int V_217 , int V_139 )
{
return F_258 ( V_169 , V_44 , V_216 , V_217 , V_139 ,
F_89 ( V_169 , V_173 ) ) ;
}
bool F_260 ( struct V_23 * V_169 , unsigned int V_44 ,
unsigned long V_216 , int V_217 )
{
long V_218 = F_89 ( V_169 , V_173 ) ;
if ( V_169 -> V_224 && V_218 < V_169 -> V_224 )
V_218 = F_261 ( V_169 , V_173 ) ;
return F_258 ( V_169 , V_44 , V_216 , V_217 , 0 ,
V_218 ) ;
}
static bool F_262 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return V_225 -> V_109 == V_23 -> V_109 ;
}
static bool F_263 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return F_264 ( F_24 ( V_225 ) , F_24 ( V_23 ) ) <
V_226 ;
}
static bool F_262 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return true ;
}
static bool F_263 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return true ;
}
static void F_265 ( struct V_23 * V_191 )
{
struct V_23 * V_23 = V_191 -> V_227 -> V_97 ;
do {
F_266 ( V_23 , V_196 ,
F_267 ( V_23 ) - F_237 ( V_23 ) -
F_242 ( & V_23 -> V_197 [ V_196 ] ) ) ;
F_268 ( V_198 , & V_23 -> V_60 ) ;
} while ( V_23 ++ != V_191 );
}
static struct V_1 *
F_269 ( T_4 V_186 , unsigned int V_44 , int V_139 ,
const struct V_165 * V_166 )
{
struct V_167 * V_167 = V_166 -> V_167 ;
struct V_168 * V_169 ;
struct V_1 * V_1 = NULL ;
struct V_23 * V_23 ;
int V_228 = 0 ;
bool V_229 ;
V_230:
V_229 = false ;
F_198 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_216 ;
if ( F_270 () &&
( V_139 & V_231 ) &&
! F_271 ( V_23 , V_186 ) )
continue;
if ( V_139 & V_232 ) {
if ( ! F_262 ( V_166 -> V_191 , V_23 ) )
break;
if ( F_243 ( V_198 , & V_23 -> V_60 ) ) {
V_228 ++ ;
continue;
}
}
if ( V_166 -> V_233 && ! F_272 ( V_23 ) )
continue;
V_216 = V_23 -> V_188 [ V_139 & V_234 ] ;
if ( ! F_238 ( V_23 , V_44 , V_216 ,
V_166 -> V_217 , V_139 ) ) {
int V_24 ;
F_100 ( V_142 < V_235 ) ;
if ( V_139 & V_142 )
goto V_236;
if ( V_237 == 0 ||
! F_263 ( V_166 -> V_191 , V_23 ) )
continue;
V_24 = F_273 ( V_23 , V_186 , V_44 ) ;
switch ( V_24 ) {
case V_238 :
continue;
case V_239 :
continue;
default:
if ( F_238 ( V_23 , V_44 , V_216 ,
V_166 -> V_217 , V_139 ) )
goto V_236;
continue;
}
}
V_236:
V_1 = F_240 ( V_166 -> V_191 , V_23 , V_44 ,
V_186 , V_139 , V_166 -> V_3 ) ;
if ( V_1 ) {
if ( F_175 ( V_1 , V_44 , V_186 , V_139 ) )
goto V_236;
if ( F_16 ( V_44 && ( V_139 & V_195 ) ) )
F_193 ( V_1 , V_23 , V_44 ) ;
return V_1 ;
}
}
if ( V_139 & V_232 ) {
V_139 &= ~ V_232 ;
if ( V_228 ) {
V_229 = true ;
F_265 ( V_166 -> V_191 ) ;
}
if ( V_240 > 1 )
V_229 = true ;
}
if ( V_229 )
goto V_230;
return NULL ;
}
static inline bool F_274 ( void )
{
bool V_24 = false ;
#if V_241 > 8
V_24 = F_275 () ;
#endif
return V_24 ;
}
void F_276 ( T_4 V_186 , unsigned int V_44 , const char * V_242 , ... )
{
unsigned int V_243 = V_244 ;
if ( ( V_186 & V_245 ) || ! F_277 ( & V_246 ) ||
F_173 () > 0 )
return;
if ( ! ( V_186 & V_247 ) )
if ( F_278 ( V_248 ) ||
( V_40 -> V_60 & ( V_249 | V_250 ) ) )
V_243 &= ~ V_244 ;
if ( F_275 () || ! ( V_186 & V_207 ) )
V_243 &= ~ V_244 ;
if ( V_242 ) {
struct V_251 V_252 ;
T_7 args ;
va_start ( args , V_242 ) ;
V_252 . V_242 = V_242 ;
V_252 . V_253 = & args ;
F_279 ( L_22 , & V_252 ) ;
va_end ( args ) ;
}
F_279 ( L_23 ,
V_40 -> V_41 , V_44 , V_186 ) ;
F_36 () ;
if ( ! F_274 () )
F_280 ( V_243 ) ;
}
static inline struct V_1 *
F_281 ( T_4 V_186 , unsigned int V_44 ,
const struct V_165 * V_166 , unsigned long * V_254 )
{
struct V_255 V_256 = {
. V_167 = V_166 -> V_167 ,
. V_257 = V_166 -> V_257 ,
. V_186 = V_186 ,
. V_44 = V_44 ,
} ;
struct V_1 * V_1 ;
* V_254 = 0 ;
if ( ! F_282 ( & V_258 ) ) {
* V_254 = 1 ;
F_283 ( 1 ) ;
return NULL ;
}
V_1 = F_269 ( V_186 | V_259 , V_44 ,
V_260 | V_231 , V_166 ) ;
if ( V_1 )
goto V_37;
if ( ! ( V_186 & V_194 ) ) {
if ( V_40 -> V_60 & V_261 )
goto V_37;
if ( V_44 > V_262 )
goto V_37;
if ( V_166 -> V_263 < V_264 )
goto V_37;
if ( ! ( V_186 & V_8 ) ) {
* V_254 = 1 ;
goto V_37;
}
if ( F_7 () )
goto V_37;
if ( V_186 & V_265 )
goto V_37;
}
if ( F_284 ( & V_256 ) || F_241 ( V_186 & V_194 ) )
* V_254 = 1 ;
V_37:
F_285 ( & V_258 ) ;
return V_1 ;
}
static struct V_1 *
F_286 ( T_4 V_186 , unsigned int V_44 ,
int V_139 , const struct V_165 * V_166 ,
enum V_266 V_208 , int * V_267 ,
bool * V_268 )
{
unsigned long V_269 ;
struct V_1 * V_1 ;
if ( ! V_44 )
return NULL ;
V_40 -> V_60 |= V_249 ;
V_269 = F_287 ( V_186 , V_44 , V_139 , V_166 ,
V_208 , V_267 ) ;
V_40 -> V_60 &= ~ V_249 ;
switch ( V_269 ) {
case V_270 :
* V_268 = true ;
case V_271 :
return NULL ;
default:
break;
}
F_288 ( V_272 ) ;
V_1 = F_269 ( V_186 , V_44 ,
V_139 & ~ V_142 , V_166 ) ;
if ( V_1 ) {
struct V_23 * V_23 = F_27 ( V_1 ) ;
V_23 -> V_273 = false ;
F_289 ( V_23 , V_44 , true ) ;
F_288 ( V_274 ) ;
return V_1 ;
}
F_288 ( V_275 ) ;
F_158 () ;
return NULL ;
}
static inline struct V_1 *
F_286 ( T_4 V_186 , unsigned int V_44 ,
int V_139 , const struct V_165 * V_166 ,
enum V_266 V_208 , int * V_267 ,
bool * V_268 )
{
return NULL ;
}
static int
F_290 ( T_4 V_186 , unsigned int V_44 ,
const struct V_165 * V_166 )
{
struct V_276 V_276 ;
int V_277 ;
F_158 () ;
F_291 () ;
V_40 -> V_60 |= V_249 ;
F_292 ( V_186 ) ;
V_276 . V_278 = 0 ;
V_40 -> V_276 = & V_276 ;
V_277 = F_293 ( V_166 -> V_167 , V_44 , V_186 ,
V_166 -> V_257 ) ;
V_40 -> V_276 = NULL ;
F_294 () ;
V_40 -> V_60 &= ~ V_249 ;
F_158 () ;
return V_277 ;
}
static inline struct V_1 *
F_295 ( T_4 V_186 , unsigned int V_44 ,
int V_139 , const struct V_165 * V_166 ,
unsigned long * V_254 )
{
struct V_1 * V_1 = NULL ;
bool V_279 = false ;
* V_254 = F_290 ( V_186 , V_44 , V_166 ) ;
if ( F_16 ( ! ( * V_254 ) ) )
return NULL ;
V_280:
V_1 = F_269 ( V_186 , V_44 ,
V_139 & ~ V_142 , V_166 ) ;
if ( ! V_1 && ! V_279 ) {
F_197 ( V_166 ) ;
F_213 ( NULL ) ;
V_279 = true ;
goto V_280;
}
return V_1 ;
}
static inline struct V_1 *
F_296 ( T_4 V_186 , unsigned int V_44 ,
const struct V_165 * V_166 )
{
struct V_1 * V_1 ;
do {
V_1 = F_269 ( V_186 , V_44 ,
V_142 , V_166 ) ;
if ( ! V_1 && V_186 & V_194 )
F_297 ( V_166 -> V_191 , V_281 ,
V_39 / 50 ) ;
} while ( ! V_1 && ( V_186 & V_194 ) );
return V_1 ;
}
static void F_298 ( unsigned int V_44 , const struct V_165 * V_166 )
{
struct V_168 * V_169 ;
struct V_23 * V_23 ;
F_198 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_299 ( V_23 , V_44 , F_300 ( V_166 -> V_191 ) ) ;
}
static inline int
F_301 ( T_4 V_186 )
{
int V_139 = V_282 | V_231 ;
F_100 ( V_283 != ( V_284 T_4 ) V_221 ) ;
V_139 |= ( V_284 int ) ( V_186 & V_283 ) ;
if ( V_186 & V_285 ) {
if ( ! ( V_186 & V_247 ) )
V_139 |= V_195 ;
V_139 &= ~ V_231 ;
} else if ( F_16 ( F_302 ( V_40 ) ) && ! F_275 () )
V_139 |= V_195 ;
if ( F_204 ( ! ( V_186 & V_247 ) ) ) {
if ( V_186 & V_286 )
V_139 |= V_142 ;
else if ( F_303 () && ( V_40 -> V_60 & V_249 ) )
V_139 |= V_142 ;
else if ( ! F_275 () &&
( ( V_40 -> V_60 & V_249 ) ||
F_16 ( F_278 ( V_248 ) ) ) )
V_139 |= V_142 ;
}
#ifdef F_259
if ( F_304 ( V_186 ) == V_113 )
V_139 |= V_222 ;
#endif
return V_139 ;
}
bool F_305 ( T_4 V_186 )
{
return ! ! ( F_301 ( V_186 ) & V_142 ) ;
}
static inline bool F_306 ( T_4 V_186 )
{
return ( V_186 & ( V_287 | V_288 ) ) == V_287 ;
}
static inline struct V_1 *
F_307 ( T_4 V_186 , unsigned int V_44 ,
struct V_165 * V_166 )
{
bool V_289 = V_186 & V_207 ;
struct V_1 * V_1 = NULL ;
int V_139 ;
unsigned long V_290 = 0 ;
unsigned long V_254 ;
enum V_266 V_291 = V_292 ;
bool V_268 = false ;
int V_267 = V_293 ;
if ( V_44 >= V_54 ) {
F_241 ( ! ( V_186 & V_245 ) ) ;
return NULL ;
}
if ( F_241 ( ( V_186 & ( V_285 | V_207 ) ) ==
( V_285 | V_207 ) ) )
V_186 &= ~ V_285 ;
if ( F_101 ( V_294 ) && ( V_186 & V_265 ) && ! V_289 )
goto V_295;
V_280:
if ( V_186 & V_288 )
F_298 ( V_44 , V_166 ) ;
V_139 = F_301 ( V_186 ) ;
if ( ! ( V_139 & V_231 ) && ! V_166 -> V_257 ) {
struct V_168 * V_296 ;
V_296 = F_308 ( V_166 -> V_167 ,
V_166 -> V_263 , NULL , & V_166 -> V_191 ) ;
V_166 -> V_217 = F_309 ( V_296 ) ;
}
V_1 = F_269 ( V_186 , V_44 ,
V_139 & ~ V_142 , V_166 ) ;
if ( V_1 )
goto V_297;
if ( V_139 & V_142 ) {
V_166 -> V_167 = F_310 ( F_311 () , V_186 ) ;
V_1 = F_296 ( V_186 , V_44 , V_166 ) ;
if ( V_1 ) {
goto V_297;
}
}
if ( ! V_289 ) {
F_241 ( V_186 & V_194 ) ;
goto V_295;
}
if ( V_40 -> V_60 & V_249 )
goto V_295;
if ( F_278 ( V_248 ) && ! ( V_186 & V_194 ) )
goto V_295;
V_1 = F_286 ( V_186 , V_44 , V_139 , V_166 ,
V_291 ,
& V_267 ,
& V_268 ) ;
if ( V_1 )
goto V_297;
if ( F_306 ( V_186 ) ) {
if ( V_268 )
goto V_295;
if ( V_267 == V_298 )
goto V_295;
if ( V_267 == V_299
&& ! ( V_40 -> V_60 & V_300 ) )
goto V_295;
}
if ( ! F_306 ( V_186 ) || ( V_40 -> V_60 & V_300 ) )
V_291 = V_301 ;
V_1 = F_295 ( V_186 , V_44 , V_139 , V_166 ,
& V_254 ) ;
if ( V_1 )
goto V_297;
if ( V_186 & V_302 )
goto V_303;
V_290 += V_254 ;
if ( ( V_254 && V_44 <= V_262 ) ||
( ( V_186 & V_304 ) && V_290 < ( 1 << V_44 ) ) ) {
F_297 ( V_166 -> V_191 , V_281 , V_39 / 50 ) ;
goto V_280;
}
V_1 = F_281 ( V_186 , V_44 , V_166 , & V_254 ) ;
if ( V_1 )
goto V_297;
if ( V_254 )
goto V_280;
V_303:
V_1 = F_286 ( V_186 , V_44 , V_139 ,
V_166 , V_291 ,
& V_267 ,
& V_268 ) ;
if ( V_1 )
goto V_297;
V_295:
F_276 ( V_186 , V_44 , NULL ) ;
V_297:
return V_1 ;
}
struct V_1 *
F_312 ( T_4 V_186 , unsigned int V_44 ,
struct V_167 * V_167 , T_8 * V_257 )
{
struct V_168 * V_296 ;
struct V_1 * V_1 = NULL ;
unsigned int V_305 ;
int V_139 = V_306 | V_231 | V_232 ;
T_4 V_307 ;
struct V_165 V_166 = {
. V_263 = F_313 ( V_186 ) ,
. V_257 = V_257 ,
. V_3 = F_304 ( V_186 ) ,
} ;
V_186 &= V_6 ;
F_314 ( V_186 ) ;
F_315 ( V_186 & V_207 ) ;
if ( F_249 ( V_186 , V_44 ) )
return NULL ;
if ( F_16 ( ! V_167 -> V_308 -> V_23 ) )
return NULL ;
if ( F_101 ( F_259 ) && V_166 . V_3 == V_113 )
V_139 |= V_222 ;
V_309:
V_305 = F_316 () ;
V_166 . V_167 = V_167 ;
V_166 . V_233 = ( V_186 & V_310 ) ;
V_296 = F_308 ( V_166 . V_167 , V_166 . V_263 ,
V_166 . V_257 ? : & V_311 ,
& V_166 . V_191 ) ;
if ( ! V_166 . V_191 )
goto V_37;
V_166 . V_217 = F_309 ( V_296 ) ;
V_307 = V_186 | V_259 ;
V_1 = F_269 ( V_307 , V_44 , V_139 , & V_166 ) ;
if ( F_16 ( ! V_1 ) ) {
V_307 = F_317 ( V_186 ) ;
V_166 . V_233 = false ;
V_1 = F_307 ( V_307 , V_44 , & V_166 ) ;
}
if ( V_312 && V_1 )
F_318 ( V_1 , V_44 , V_186 ) ;
F_319 ( V_1 , V_44 , V_307 , V_166 . V_3 ) ;
V_37:
if ( F_16 ( ! V_1 && F_320 ( V_305 ) ) )
goto V_309;
return V_1 ;
}
unsigned long F_321 ( T_4 V_186 , unsigned int V_44 )
{
struct V_1 * V_1 ;
F_75 ( ( V_186 & V_205 ) != 0 ) ;
V_1 = F_322 ( V_186 , V_44 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_130 ( V_1 ) ;
}
unsigned long F_323 ( T_4 V_186 )
{
return F_321 ( V_186 | V_140 , 0 ) ;
}
void F_141 ( struct V_1 * V_1 , unsigned int V_44 )
{
if ( F_324 ( V_1 ) ) {
if ( V_44 == 0 )
F_225 ( V_1 , false ) ;
else
F_39 ( V_1 , V_44 ) ;
}
}
void V_218 ( unsigned long V_313 , unsigned int V_44 )
{
if ( V_313 != 0 ) {
F_75 ( ! F_325 ( ( void * ) V_313 ) ) ;
F_141 ( F_234 ( ( void * ) V_313 ) , V_44 ) ;
}
}
static struct V_1 * F_326 ( struct V_314 * V_315 ,
T_4 V_186 )
{
struct V_1 * V_1 = NULL ;
T_4 V_316 = V_186 ;
#if ( V_103 < V_317 )
V_186 |= V_141 | V_245 | V_302 |
V_247 ;
V_1 = F_327 ( V_318 , V_186 ,
V_319 ) ;
V_315 -> V_135 = V_1 ? V_317 : V_103 ;
#endif
if ( F_16 ( ! V_1 ) )
V_1 = F_327 ( V_318 , V_316 , 0 ) ;
V_315 -> V_253 = V_1 ? F_130 ( V_1 ) : NULL ;
return V_1 ;
}
void * F_328 ( struct V_314 * V_315 ,
unsigned int V_320 , T_4 V_186 )
{
unsigned int V_135 = V_103 ;
struct V_1 * V_1 ;
int V_321 ;
if ( F_16 ( ! V_315 -> V_253 ) ) {
V_322:
V_1 = F_326 ( V_315 , V_186 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_103 < V_317 )
V_135 = V_315 -> V_135 ;
#endif
F_329 ( V_135 - 1 , & V_1 -> V_76 ) ;
V_315 -> V_323 = F_330 ( V_1 ) ;
V_315 -> V_324 = V_135 ;
V_315 -> V_321 = V_135 ;
}
V_321 = V_315 -> V_321 - V_320 ;
if ( F_16 ( V_321 < 0 ) ) {
V_1 = F_234 ( V_315 -> V_253 ) ;
if ( ! F_331 ( V_315 -> V_324 , & V_1 -> V_76 ) )
goto V_322;
#if ( V_103 < V_317 )
V_135 = V_315 -> V_135 ;
#endif
F_164 ( & V_1 -> V_76 , V_135 ) ;
V_315 -> V_324 = V_135 ;
V_321 = V_135 - V_320 ;
}
V_315 -> V_324 -- ;
V_315 -> V_321 = V_321 ;
return V_315 -> V_253 + V_321 ;
}
void F_332 ( void * V_313 )
{
struct V_1 * V_1 = F_333 ( V_313 ) ;
if ( F_16 ( F_324 ( V_1 ) ) )
F_39 ( V_1 , F_40 ( V_1 ) ) ;
}
struct V_1 * F_334 ( T_4 V_186 , unsigned int V_44 )
{
struct V_1 * V_1 ;
V_1 = F_322 ( V_186 , V_44 ) ;
if ( V_1 && F_335 ( V_1 , V_186 , V_44 ) != 0 ) {
F_141 ( V_1 , V_44 ) ;
V_1 = NULL ;
}
return V_1 ;
}
struct V_1 * F_336 ( int V_13 , T_4 V_186 , unsigned int V_44 )
{
struct V_1 * V_1 ;
V_1 = F_327 ( V_13 , V_186 , V_44 ) ;
if ( V_1 && F_335 ( V_1 , V_186 , V_44 ) != 0 ) {
F_141 ( V_1 , V_44 ) ;
V_1 = NULL ;
}
return V_1 ;
}
void F_337 ( struct V_1 * V_1 , unsigned int V_44 )
{
F_338 ( V_1 , V_44 ) ;
F_141 ( V_1 , V_44 ) ;
}
void F_339 ( unsigned long V_313 , unsigned int V_44 )
{
if ( V_313 != 0 ) {
F_75 ( ! F_325 ( ( void * ) V_313 ) ) ;
F_337 ( F_234 ( ( void * ) V_313 ) , V_44 ) ;
}
}
static void * F_340 ( unsigned long V_313 , unsigned int V_44 ,
T_9 V_135 )
{
if ( V_313 ) {
unsigned long V_325 = V_313 + ( V_103 << V_44 ) ;
unsigned long V_326 = V_313 + F_341 ( V_135 ) ;
F_231 ( F_234 ( ( void * ) V_313 ) , V_44 ) ;
while ( V_326 < V_325 ) {
F_342 ( V_326 ) ;
V_326 += V_103 ;
}
}
return ( void * ) V_313 ;
}
void * F_343 ( T_9 V_135 , T_4 V_186 )
{
unsigned int V_44 = F_344 ( V_135 ) ;
unsigned long V_313 ;
V_313 = F_321 ( V_186 , V_44 ) ;
return F_340 ( V_313 , V_44 , V_135 ) ;
}
void * T_2 F_345 ( int V_13 , T_9 V_135 , T_4 V_186 )
{
unsigned int V_44 = F_344 ( V_135 ) ;
struct V_1 * V_48 = F_327 ( V_13 , V_186 , V_44 ) ;
if ( ! V_48 )
return NULL ;
return F_340 ( ( unsigned long ) F_130 ( V_48 ) , V_44 , V_135 ) ;
}
void F_346 ( void * V_327 , T_9 V_135 )
{
unsigned long V_313 = ( unsigned long ) V_327 ;
unsigned long V_99 = V_313 + F_341 ( V_135 ) ;
while ( V_313 < V_99 ) {
F_342 ( V_313 ) ;
V_313 += V_103 ;
}
}
static unsigned long F_347 ( int V_321 )
{
struct V_168 * V_169 ;
struct V_23 * V_23 ;
unsigned long V_328 = 0 ;
struct V_167 * V_167 = F_310 ( F_311 () , V_329 ) ;
F_348 (zone, z, zonelist, offset) {
unsigned long V_135 = V_23 -> V_106 ;
unsigned long V_133 = F_267 ( V_23 ) ;
if ( V_135 > V_133 )
V_328 += V_135 - V_133 ;
}
return V_328 ;
}
unsigned long F_349 ( void )
{
return F_347 ( F_313 ( V_330 ) ) ;
}
unsigned long F_350 ( void )
{
return F_347 ( F_313 ( V_331 ) ) ;
}
static inline void F_351 ( struct V_23 * V_23 )
{
if ( F_101 ( V_294 ) )
F_33 ( L_24 , F_24 ( V_23 ) ) ;
}
void F_352 ( struct V_332 * V_333 )
{
V_333 -> V_334 = V_335 ;
V_333 -> V_336 = F_353 ( V_337 ) ;
V_333 -> V_338 = F_353 ( V_173 ) ;
V_333 -> V_339 = F_354 () ;
V_333 -> V_340 = V_341 ;
V_333 -> V_342 = F_355 () ;
V_333 -> V_343 = V_103 ;
}
void F_356 ( struct V_332 * V_333 , int V_13 )
{
int V_344 ;
unsigned long V_106 = 0 ;
T_1 * V_9 = F_10 ( V_13 ) ;
for ( V_344 = 0 ; V_344 < V_96 ; V_344 ++ )
V_106 += V_9 -> V_97 [ V_344 ] . V_106 ;
V_333 -> V_334 = V_106 ;
V_333 -> V_336 = F_357 ( V_13 , V_337 ) ;
V_333 -> V_338 = F_357 ( V_13 , V_173 ) ;
#ifdef F_358
V_333 -> V_340 = V_9 -> V_97 [ V_345 ] . V_106 ;
V_333 -> V_342 = F_89 ( & V_9 -> V_97 [ V_345 ] ,
V_173 ) ;
#else
V_333 -> V_340 = 0 ;
V_333 -> V_342 = 0 ;
#endif
V_333 -> V_343 = V_103 ;
}
bool F_359 ( unsigned int V_60 , int V_13 )
{
bool V_24 = false ;
unsigned int V_305 ;
if ( ! ( V_60 & V_244 ) )
goto V_37;
do {
V_305 = F_316 () ;
V_24 = ! F_360 ( V_13 , V_311 ) ;
} while ( F_320 ( V_305 ) );
V_37:
return V_24 ;
}
static void F_361 ( unsigned char type )
{
static const char V_346 [ V_159 ] = {
[ V_20 ] = 'U' ,
[ V_113 ] = 'M' ,
[ V_152 ] = 'E' ,
[ V_164 ] = 'H' ,
#ifdef F_259
[ V_130 ] = 'C' ,
#endif
#ifdef F_362
[ V_347 ] = 'I' ,
#endif
} ;
char V_348 [ V_159 + 1 ] ;
char * V_48 = V_348 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_159 ; V_45 ++ ) {
if ( type & ( 1 << V_45 ) )
* V_48 ++ = V_346 [ V_45 ] ;
}
* V_48 = '\0' ;
F_33 ( L_25 , V_348 ) ;
}
void F_363 ( unsigned int V_243 )
{
unsigned long V_349 = 0 ;
int V_176 ;
struct V_23 * V_23 ;
F_210 (zone) {
if ( F_359 ( V_243 , F_24 ( V_23 ) ) )
continue;
F_214 (cpu)
V_349 += F_208 ( V_23 -> V_179 , V_176 ) -> V_81 . V_79 ;
}
F_33 ( L_26
L_27
L_28
L_29
L_30
L_31 ,
F_353 ( V_350 ) ,
F_353 ( V_351 ) ,
F_353 ( V_352 ) ,
F_353 ( V_353 ) ,
F_353 ( V_354 ) ,
F_353 ( V_355 ) ,
F_353 ( V_356 ) ,
F_353 ( V_357 ) ,
F_353 ( V_358 ) ,
F_353 ( V_359 ) ,
F_353 ( V_360 ) ,
F_353 ( V_361 ) ,
F_353 ( V_362 ) ,
F_353 ( V_337 ) ,
F_353 ( V_363 ) ,
F_353 ( V_364 ) ,
F_353 ( V_173 ) ,
V_349 ,
F_353 ( V_172 ) ) ;
F_210 (zone) {
int V_45 ;
if ( F_359 ( V_243 , F_24 ( V_23 ) ) )
continue;
V_349 = 0 ;
F_214 (cpu)
V_349 += F_208 ( V_23 -> V_179 , V_176 ) -> V_81 . V_79 ;
F_351 ( V_23 ) ;
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
V_23 -> V_30 ,
F_364 ( F_89 ( V_23 , V_173 ) ) ,
F_364 ( F_365 ( V_23 ) ) ,
F_364 ( F_237 ( V_23 ) ) ,
F_364 ( F_267 ( V_23 ) ) ,
F_364 ( F_89 ( V_23 , V_350 ) ) ,
F_364 ( F_89 ( V_23 , V_351 ) ) ,
F_364 ( F_89 ( V_23 , V_353 ) ) ,
F_364 ( F_89 ( V_23 , V_354 ) ) ,
F_364 ( F_89 ( V_23 , V_356 ) ) ,
F_364 ( F_89 ( V_23 , V_352 ) ) ,
F_364 ( F_89 ( V_23 , V_355 ) ) ,
F_364 ( V_23 -> V_365 ) ,
F_364 ( V_23 -> V_106 ) ,
F_364 ( F_89 ( V_23 , V_366 ) ) ,
F_364 ( F_89 ( V_23 , V_357 ) ) ,
F_364 ( F_89 ( V_23 , V_358 ) ) ,
F_364 ( F_89 ( V_23 , V_362 ) ) ,
F_364 ( F_89 ( V_23 , V_337 ) ) ,
F_364 ( F_89 ( V_23 , V_360 ) ) ,
F_364 ( F_89 ( V_23 , V_361 ) ) ,
F_89 ( V_23 , V_367 ) *
V_368 / 1024 ,
F_364 ( F_89 ( V_23 , V_363 ) ) ,
F_364 ( F_89 ( V_23 , V_359 ) ) ,
F_364 ( F_89 ( V_23 , V_364 ) ) ,
F_364 ( V_349 ) ,
F_364 ( F_366 ( V_23 -> V_179 -> V_81 . V_79 ) ) ,
F_364 ( F_89 ( V_23 , V_172 ) ) ,
F_364 ( F_89 ( V_23 , V_369 ) ) ,
F_364 ( F_89 ( V_23 , V_86 ) ) ,
( ! F_367 ( V_23 ) ? L_64 : L_65 )
) ;
F_33 ( L_66 ) ;
for ( V_45 = 0 ; V_45 < V_96 ; V_45 ++ )
F_33 ( L_67 , V_23 -> V_223 [ V_45 ] ) ;
F_33 ( L_63 ) ;
}
F_210 (zone) {
unsigned int V_44 ;
unsigned long V_370 [ V_54 ] , V_60 , V_371 = 0 ;
unsigned char V_346 [ V_54 ] ;
if ( F_359 ( V_243 , F_24 ( V_23 ) ) )
continue;
F_351 ( V_23 ) ;
F_33 ( L_68 , V_23 -> V_30 ) ;
F_194 ( & V_23 -> V_85 , V_60 ) ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_69 * V_134 = & V_23 -> V_69 [ V_44 ] ;
int type ;
V_370 [ V_44 ] = V_134 -> V_70 ;
V_371 += V_370 [ V_44 ] << V_44 ;
V_346 [ V_44 ] = 0 ;
for ( type = 0 ; type < V_159 ; type ++ ) {
if ( ! F_91 ( & V_134 -> V_73 [ type ] ) )
V_346 [ V_44 ] |= 1 << type ;
}
}
F_196 ( & V_23 -> V_85 , V_60 ) ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
F_33 ( L_69 , V_370 [ V_44 ] , F_364 ( 1UL ) << V_44 ) ;
if ( V_370 [ V_44 ] )
F_361 ( V_346 [ V_44 ] ) ;
}
F_33 ( L_70 , F_364 ( V_371 ) ) ;
}
F_368 () ;
F_33 ( L_71 , F_353 ( V_372 ) ) ;
F_369 () ;
}
static void F_370 ( struct V_23 * V_23 , struct V_168 * V_168 )
{
V_168 -> V_23 = V_23 ;
V_168 -> F_300 = F_300 ( V_23 ) ;
}
static int F_371 ( T_1 * V_9 , struct V_167 * V_167 ,
int V_373 )
{
struct V_23 * V_23 ;
enum V_344 V_344 = V_96 ;
do {
V_344 -- ;
V_23 = V_9 -> V_97 + V_344 ;
if ( F_160 ( V_23 ) ) {
F_370 ( V_23 ,
& V_167 -> V_308 [ V_373 ++ ] ) ;
F_372 ( V_344 ) ;
}
} while ( V_344 );
return V_373 ;
}
static int F_373 ( char * V_374 )
{
if ( * V_374 == 'd' || * V_374 == 'D' ) {
V_375 = V_376 ;
} else if ( * V_374 == 'n' || * V_374 == 'N' ) {
V_375 = V_377 ;
} else if ( * V_374 == 'z' || * V_374 == 'Z' ) {
V_375 = V_378 ;
} else {
F_33 ( V_379
L_72
L_73 , V_374 ) ;
return - V_50 ;
}
return 0 ;
}
static T_3 int F_374 ( char * V_374 )
{
int V_24 ;
if ( ! V_374 )
return 0 ;
V_24 = F_373 ( V_374 ) ;
if ( V_24 == 0 )
F_375 ( V_380 , V_374 , V_381 ) ;
return V_24 ;
}
int F_376 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 ,
T_11 * V_387 )
{
char V_388 [ V_381 ] ;
int V_24 ;
static F_377 ( V_389 ) ;
F_378 ( & V_389 ) ;
if ( V_384 ) {
if ( strlen ( ( char * ) V_383 -> V_116 ) >= V_381 ) {
V_24 = - V_50 ;
goto V_37;
}
strcpy ( V_388 , ( char * ) V_383 -> V_116 ) ;
}
V_24 = F_379 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_24 )
goto V_37;
if ( V_384 ) {
int V_390 = V_375 ;
V_24 = F_373 ( ( char * ) V_383 -> V_116 ) ;
if ( V_24 ) {
strncpy ( ( char * ) V_383 -> V_116 , V_388 ,
V_381 ) ;
V_375 = V_390 ;
} else if ( V_390 != V_375 ) {
F_378 ( & V_391 ) ;
F_380 ( NULL , NULL ) ;
F_285 ( & V_391 ) ;
}
}
V_37:
F_285 ( & V_389 ) ;
return V_24 ;
}
static int F_381 ( int V_109 , T_8 * V_392 )
{
int V_393 , V_333 ;
int V_394 = V_395 ;
int V_396 = V_318 ;
const struct V_122 * V_348 = F_152 ( 0 ) ;
if ( ! F_360 ( V_109 , * V_392 ) ) {
F_382 ( V_109 , * V_392 ) ;
return V_109 ;
}
F_166 (n, N_MEMORY) {
if ( F_360 ( V_393 , * V_392 ) )
continue;
V_333 = F_264 ( V_109 , V_393 ) ;
V_333 += ( V_393 < V_109 ) ;
V_348 = F_152 ( V_393 ) ;
if ( ! F_153 ( V_348 ) )
V_333 += V_397 ;
V_333 *= ( V_398 * V_399 ) ;
V_333 += V_400 [ V_393 ] ;
if ( V_333 < V_394 ) {
V_394 = V_333 ;
V_396 = V_393 ;
}
}
if ( V_396 >= 0 )
F_382 ( V_396 , * V_392 ) ;
return V_396 ;
}
static void F_383 ( T_1 * V_9 , int V_109 )
{
int V_401 ;
struct V_167 * V_167 ;
V_167 = & V_9 -> V_402 [ 0 ] ;
for ( V_401 = 0 ; V_167 -> V_308 [ V_401 ] . V_23 != NULL ; V_401 ++ )
;
V_401 = F_371 ( F_10 ( V_109 ) , V_167 , V_401 ) ;
V_167 -> V_308 [ V_401 ] . V_23 = NULL ;
V_167 -> V_308 [ V_401 ] . F_300 = 0 ;
}
static void F_384 ( T_1 * V_9 )
{
int V_401 ;
struct V_167 * V_167 ;
V_167 = & V_9 -> V_402 [ 1 ] ;
V_401 = F_371 ( V_9 , V_167 , 0 ) ;
V_167 -> V_308 [ V_401 ] . V_23 = NULL ;
V_167 -> V_308 [ V_401 ] . F_300 = 0 ;
}
static void F_385 ( T_1 * V_9 , int V_403 )
{
int V_404 , V_401 , V_109 ;
int V_344 ;
struct V_23 * V_169 ;
struct V_167 * V_167 ;
V_167 = & V_9 -> V_402 [ 0 ] ;
V_404 = 0 ;
for ( V_344 = V_96 - 1 ; V_344 >= 0 ; V_344 -- ) {
for ( V_401 = 0 ; V_401 < V_403 ; V_401 ++ ) {
V_109 = V_405 [ V_401 ] ;
V_169 = & F_10 ( V_109 ) -> V_97 [ V_344 ] ;
if ( F_160 ( V_169 ) ) {
F_370 ( V_169 ,
& V_167 -> V_308 [ V_404 ++ ] ) ;
F_372 ( V_344 ) ;
}
}
}
V_167 -> V_308 [ V_404 ] . V_23 = NULL ;
V_167 -> V_308 [ V_404 ] . F_300 = 0 ;
}
static int F_386 ( void )
{
return V_377 ;
}
static int F_386 ( void )
{
return V_378 ;
}
static void F_387 ( void )
{
if ( V_375 == V_376 )
V_406 = F_386 () ;
else
V_406 = V_375 ;
}
static void F_388 ( T_1 * V_9 )
{
int V_401 , V_109 , V_407 ;
enum V_344 V_45 ;
T_8 V_408 ;
int V_409 , V_410 ;
struct V_167 * V_167 ;
unsigned int V_44 = V_406 ;
for ( V_45 = 0 ; V_45 < V_411 ; V_45 ++ ) {
V_167 = V_9 -> V_402 + V_45 ;
V_167 -> V_308 [ 0 ] . V_23 = NULL ;
V_167 -> V_308 [ 0 ] . F_300 = 0 ;
}
V_409 = V_9 -> V_117 ;
V_407 = V_240 ;
V_410 = V_409 ;
F_389 ( V_408 ) ;
memset ( V_405 , 0 , sizeof( V_405 ) ) ;
V_401 = 0 ;
while ( ( V_109 = F_381 ( V_409 , & V_408 ) ) >= 0 ) {
if ( F_264 ( V_409 , V_109 ) !=
F_264 ( V_409 , V_410 ) )
V_400 [ V_109 ] = V_407 ;
V_410 = V_109 ;
V_407 -- ;
if ( V_44 == V_377 )
F_383 ( V_9 , V_109 ) ;
else
V_405 [ V_401 ++ ] = V_109 ;
}
if ( V_44 == V_378 ) {
F_385 ( V_9 , V_401 ) ;
}
F_384 ( V_9 ) ;
}
int F_390 ( int V_109 )
{
struct V_23 * V_23 ;
( void ) F_308 ( F_310 ( V_109 , V_329 ) ,
F_313 ( V_329 ) ,
NULL ,
& V_23 ) ;
return V_23 -> V_109 ;
}
static void F_387 ( void )
{
V_406 = V_378 ;
}
static void F_388 ( T_1 * V_9 )
{
int V_109 , V_409 ;
enum V_344 V_401 ;
struct V_167 * V_167 ;
V_409 = V_9 -> V_117 ;
V_167 = & V_9 -> V_402 [ 0 ] ;
V_401 = F_371 ( V_9 , V_167 , 0 ) ;
for ( V_109 = V_409 + 1 ; V_109 < V_399 ; V_109 ++ ) {
if ( ! F_391 ( V_109 ) )
continue;
V_401 = F_371 ( F_10 ( V_109 ) , V_167 , V_401 ) ;
}
for ( V_109 = 0 ; V_109 < V_409 ; V_109 ++ ) {
if ( ! F_391 ( V_109 ) )
continue;
V_401 = F_371 ( F_10 ( V_109 ) , V_167 , V_401 ) ;
}
V_167 -> V_308 [ V_401 ] . V_23 = NULL ;
V_167 -> V_308 [ V_401 ] . F_300 = 0 ;
}
static int F_392 ( void * V_116 )
{
int V_13 ;
int V_176 ;
T_1 * V_412 = V_116 ;
#ifdef V_294
memset ( V_400 , 0 , sizeof( V_400 ) ) ;
#endif
if ( V_412 && ! F_391 ( V_412 -> V_117 ) ) {
F_388 ( V_412 ) ;
}
F_393 (nid) {
T_1 * V_9 = F_10 ( V_13 ) ;
F_388 ( V_9 ) ;
}
F_394 (cpu) {
F_395 ( & F_396 ( V_413 , V_176 ) , 0 ) ;
#ifdef F_397
if ( F_398 ( V_176 ) )
F_399 ( V_176 , F_390 ( F_400 ( V_176 ) ) ) ;
#endif
}
return 0 ;
}
static T_12 void T_3
F_401 ( void )
{
F_392 ( NULL ) ;
F_402 () ;
F_403 () ;
}
void T_13 F_380 ( T_1 * V_9 , struct V_23 * V_23 )
{
F_387 () ;
if ( V_414 == V_415 ) {
F_401 () ;
} else {
#ifdef F_404
if ( V_23 )
F_405 ( V_23 ) ;
#endif
F_406 ( F_392 , V_9 , NULL ) ;
}
V_416 = F_350 () ;
if ( V_416 < ( V_129 * V_159 ) )
V_18 = 1 ;
else
V_18 = 0 ;
F_161 ( L_74
L_75 ,
V_240 ,
V_417 [ V_406 ] ,
V_18 ? L_76 : L_4 ,
V_416 ) ;
#ifdef V_294
F_161 ( L_77 , V_418 [ V_419 ] ) ;
#endif
}
static inline unsigned long F_407 ( unsigned long V_154 )
{
unsigned long V_135 = 1 ;
V_154 /= V_420 ;
while ( V_135 < V_154 )
V_135 <<= 1 ;
V_135 = F_157 ( V_135 , 4096UL ) ;
return F_159 ( V_135 , 4UL ) ;
}
static inline unsigned long F_407 ( unsigned long V_154 )
{
return 4096UL ;
}
static inline unsigned long F_408 ( unsigned long V_135 )
{
return F_409 ( ~ V_135 ) ;
}
void T_2 F_410 ( unsigned long V_135 , int V_13 , unsigned long V_23 ,
unsigned long V_27 , enum V_421 V_422 )
{
T_1 * V_9 = F_10 ( V_13 ) ;
unsigned long V_100 = V_27 + V_135 ;
unsigned long V_12 ;
struct V_23 * V_169 ;
unsigned long V_15 = 0 ;
if ( V_423 < V_100 - 1 )
V_423 = V_100 - 1 ;
V_169 = & V_9 -> V_97 [ V_23 ] ;
for ( V_12 = V_27 ; V_12 < V_100 ; V_12 ++ ) {
if ( V_422 == V_424 ) {
if ( ! F_411 ( V_12 ) )
continue;
if ( ! F_145 ( V_12 , V_13 ) )
continue;
if ( ! F_13 ( V_9 , V_12 , V_100 ,
& V_15 ) )
break;
}
if ( ! ( V_12 & ( V_129 - 1 ) ) ) {
struct V_1 * V_1 = F_113 ( V_12 ) ;
F_105 ( V_1 , V_12 , V_23 , V_13 ) ;
F_15 ( V_1 , V_113 ) ;
} else {
F_112 ( V_12 , V_23 , V_13 ) ;
}
}
}
static void T_2 F_412 ( struct V_23 * V_23 )
{
unsigned int V_44 , V_184 ;
F_222 (order, t) {
F_57 ( & V_23 -> V_69 [ V_44 ] . V_73 [ V_184 ] ) ;
V_23 -> V_69 [ V_44 ] . V_70 = 0 ;
}
}
static int F_413 ( struct V_23 * V_23 )
{
#ifdef F_414
int V_175 ;
V_175 = V_23 -> V_106 / 1024 ;
if ( V_175 * V_103 > 512 * 1024 )
V_175 = ( 512 * 1024 ) / V_103 ;
V_175 /= 4 ;
if ( V_175 < 1 )
V_175 = 1 ;
V_175 = F_415 ( V_175 + V_175 / 2 ) - 1 ;
return V_175 ;
#else
return 0 ;
#endif
}
static void F_416 ( struct V_80 * V_81 , unsigned long V_133 ,
unsigned long V_175 )
{
V_81 -> V_175 = 1 ;
F_417 () ;
V_81 -> V_133 = V_133 ;
F_417 () ;
V_81 -> V_175 = V_175 ;
}
static void F_418 ( struct V_177 * V_48 , unsigned long V_175 )
{
F_416 ( & V_48 -> V_81 , 6 * V_175 , F_159 ( 1UL , 1 * V_175 ) ) ;
}
static void F_419 ( struct V_177 * V_48 )
{
struct V_80 * V_81 ;
int V_3 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_81 = & V_48 -> V_81 ;
V_81 -> V_79 = 0 ;
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ )
F_57 ( & V_81 -> V_89 [ V_3 ] ) ;
}
static void F_395 ( struct V_177 * V_48 , unsigned long V_175 )
{
F_419 ( V_48 ) ;
F_418 ( V_48 , V_175 ) ;
}
static void F_420 ( struct V_177 * V_48 ,
unsigned long V_133 )
{
unsigned long V_175 = F_159 ( 1UL , V_133 / 4 ) ;
if ( ( V_133 / 4 ) > ( V_16 * 8 ) )
V_175 = V_16 * 8 ;
F_416 ( & V_48 -> V_81 , V_133 , V_175 ) ;
}
static void F_421 ( struct V_23 * V_23 ,
struct V_177 * V_81 )
{
if ( V_425 )
F_420 ( V_81 ,
( V_23 -> V_106 /
V_425 ) ) ;
else
F_418 ( V_81 , F_413 ( V_23 ) ) ;
}
static void T_2 F_422 ( struct V_23 * V_23 , int V_176 )
{
struct V_177 * V_81 = F_208 ( V_23 -> V_179 , V_176 ) ;
F_419 ( V_81 ) ;
F_421 ( V_23 , V_81 ) ;
}
static void T_2 F_405 ( struct V_23 * V_23 )
{
int V_176 ;
V_23 -> V_179 = F_423 ( struct V_177 ) ;
F_394 (cpu)
F_422 ( V_23 , V_176 ) ;
}
void T_3 F_424 ( void )
{
struct V_23 * V_23 ;
F_210 (zone)
F_405 ( V_23 ) ;
}
static T_12 T_14
int F_425 ( struct V_23 * V_23 , unsigned long V_426 )
{
int V_45 ;
T_9 V_427 ;
V_23 -> F_407 =
F_407 ( V_426 ) ;
V_23 -> F_408 =
F_408 ( V_23 -> F_407 ) ;
V_427 = V_23 -> F_407
* sizeof( V_428 ) ;
if ( ! F_426 () ) {
V_23 -> V_429 = ( V_428 * )
F_427 (
V_427 , V_23 -> V_227 -> V_117 ) ;
} else {
V_23 -> V_429 = F_428 ( V_427 ) ;
}
if ( ! V_23 -> V_429 )
return - V_215 ;
for ( V_45 = 0 ; V_45 < V_23 -> F_407 ; ++ V_45 )
F_429 ( V_23 -> V_429 + V_45 ) ;
return 0 ;
}
static T_2 void F_430 ( struct V_23 * V_23 )
{
V_23 -> V_179 = & V_413 ;
if ( F_160 ( V_23 ) )
F_33 ( V_430 L_78 ,
V_23 -> V_30 , V_23 -> V_365 ,
F_413 ( V_23 ) ) ;
}
int T_2 F_431 ( struct V_23 * V_23 ,
unsigned long V_28 ,
unsigned long V_135 )
{
struct V_431 * V_9 = V_23 -> V_227 ;
int V_24 ;
V_24 = F_425 ( V_23 , V_135 ) ;
if ( V_24 )
return V_24 ;
V_9 -> V_373 = F_300 ( V_23 ) + 1 ;
V_23 -> V_28 = V_28 ;
F_432 ( V_432 , L_79 ,
L_80 ,
V_9 -> V_117 ,
( unsigned long ) F_300 ( V_23 ) ,
V_28 , ( V_28 + V_135 ) ) ;
F_412 ( V_23 ) ;
return 0 ;
}
int T_2 F_143 ( unsigned long V_12 ,
struct V_110 * V_111 )
{
unsigned long V_27 , V_100 ;
int V_13 ;
if ( V_111 -> V_433 <= V_12 && V_12 < V_111 -> V_434 )
return V_111 -> V_435 ;
V_13 = F_433 ( V_12 , & V_27 , & V_100 ) ;
if ( V_13 != - 1 ) {
V_111 -> V_433 = V_27 ;
V_111 -> V_434 = V_100 ;
V_111 -> V_435 = V_13 ;
}
return V_13 ;
}
void T_3 F_434 ( int V_13 , unsigned long V_436 )
{
unsigned long V_27 , V_100 ;
int V_45 , V_437 ;
F_156 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_27 = F_157 ( V_27 , V_436 ) ;
V_100 = F_157 ( V_100 , V_436 ) ;
if ( V_27 < V_100 )
F_435 ( F_436 ( V_27 ) ,
( V_100 - V_27 ) << V_16 ,
V_437 ) ;
}
}
void T_3 F_437 ( int V_13 )
{
unsigned long V_27 , V_100 ;
int V_45 , V_437 ;
F_156 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_438 ( V_437 , V_27 , V_100 ) ;
}
void T_2 F_439 ( unsigned int V_13 ,
unsigned long * V_27 , unsigned long * V_100 )
{
unsigned long V_438 , V_439 ;
int V_45 ;
* V_27 = - 1UL ;
* V_100 = 0 ;
F_156 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_27 = F_157 ( * V_27 , V_438 ) ;
* V_100 = F_159 ( * V_100 , V_439 ) ;
}
if ( * V_27 == - 1UL )
* V_27 = 0 ;
}
static void T_3 F_440 ( void )
{
int V_440 ;
for ( V_440 = V_96 - 1 ; V_440 >= 0 ; V_440 -- ) {
if ( V_440 == V_441 )
continue;
if ( V_442 [ V_440 ] >
V_443 [ V_440 ] )
break;
}
F_75 ( V_440 == - 1 ) ;
V_444 = V_440 ;
}
static void T_2 F_441 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_123 ,
unsigned long V_445 ,
unsigned long * V_28 ,
unsigned long * F_115 )
{
if ( V_446 [ V_13 ] ) {
if ( V_344 == V_441 ) {
* V_28 = V_446 [ V_13 ] ;
* F_115 = F_157 ( V_445 ,
V_442 [ V_444 ] ) ;
} else if ( * V_28 < V_446 [ V_13 ] &&
* F_115 > V_446 [ V_13 ] ) {
* F_115 = V_446 [ V_13 ] ;
} else if ( * V_28 >= V_446 [ V_13 ] )
* V_28 = * F_115 ;
}
}
static unsigned long T_2 F_442 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_123 ,
unsigned long V_445 ,
unsigned long * V_447 )
{
unsigned long V_28 , F_115 ;
if ( ! V_123 && ! V_445 )
return 0 ;
V_28 = V_443 [ V_344 ] ;
F_115 = V_442 [ V_344 ] ;
F_441 ( V_13 , V_344 ,
V_123 , V_445 ,
& V_28 , & F_115 ) ;
if ( F_115 < V_123 || V_28 > V_445 )
return 0 ;
F_115 = F_157 ( F_115 , V_445 ) ;
V_28 = F_159 ( V_28 , V_123 ) ;
return F_115 - V_28 ;
}
unsigned long T_2 F_443 ( int V_13 ,
unsigned long V_448 ,
unsigned long V_449 )
{
unsigned long V_450 = V_449 - V_448 ;
unsigned long V_27 , V_100 ;
int V_45 ;
F_156 (i, nid, &start_pfn, &end_pfn, NULL) {
V_27 = F_444 ( V_27 , V_448 , V_449 ) ;
V_100 = F_444 ( V_100 , V_448 , V_449 ) ;
V_450 -= V_100 - V_27 ;
}
return V_450 ;
}
unsigned long T_3 F_445 ( unsigned long V_27 ,
unsigned long V_100 )
{
return F_443 ( V_399 , V_27 , V_100 ) ;
}
static unsigned long T_2 F_446 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_123 ,
unsigned long V_445 ,
unsigned long * V_447 )
{
unsigned long V_451 = V_443 [ V_344 ] ;
unsigned long V_452 = V_442 [ V_344 ] ;
unsigned long V_28 , F_115 ;
if ( ! V_123 && ! V_445 )
return 0 ;
V_28 = F_444 ( V_123 , V_451 , V_452 ) ;
F_115 = F_444 ( V_445 , V_451 , V_452 ) ;
F_441 ( V_13 , V_344 ,
V_123 , V_445 ,
& V_28 , & F_115 ) ;
return F_443 ( V_13 , V_28 , F_115 ) ;
}
static inline unsigned long T_2 F_442 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_123 ,
unsigned long V_445 ,
unsigned long * V_453 )
{
return V_453 [ V_344 ] ;
}
static inline unsigned long T_2 F_446 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_123 ,
unsigned long V_445 ,
unsigned long * V_454 )
{
if ( ! V_454 )
return 0 ;
return V_454 [ V_344 ] ;
}
static void T_2 F_447 ( struct V_431 * V_9 ,
unsigned long V_123 ,
unsigned long V_445 ,
unsigned long * V_453 ,
unsigned long * V_454 )
{
unsigned long V_455 = 0 , V_456 = 0 ;
enum V_344 V_45 ;
for ( V_45 = 0 ; V_45 < V_96 ; V_45 ++ ) {
struct V_23 * V_23 = V_9 -> V_97 + V_45 ;
unsigned long V_135 , V_457 ;
V_135 = F_442 ( V_9 -> V_117 , V_45 ,
V_123 ,
V_445 ,
V_453 ) ;
V_457 = V_135 - F_446 ( V_9 -> V_117 , V_45 ,
V_123 , V_445 ,
V_454 ) ;
V_23 -> V_29 = V_135 ;
V_23 -> V_365 = V_457 ;
V_456 += V_135 ;
V_455 += V_457 ;
}
V_9 -> V_458 = V_456 ;
V_9 -> V_459 = V_455 ;
F_33 ( V_430 L_81 , V_9 -> V_117 ,
V_455 ) ;
}
static unsigned long T_3 F_448 ( unsigned long V_28 , unsigned long V_460 )
{
unsigned long V_461 ;
V_460 += V_28 & ( V_129 - 1 ) ;
V_461 = F_449 ( V_460 , V_129 ) ;
V_461 = V_461 >> V_131 ;
V_461 *= V_462 ;
V_461 = F_449 ( V_461 , 8 * sizeof( unsigned long ) ) ;
return V_461 / 8 ;
}
static void T_3 F_450 ( struct V_431 * V_9 ,
struct V_23 * V_23 ,
unsigned long V_28 ,
unsigned long V_460 )
{
unsigned long V_461 = F_448 ( V_28 , V_460 ) ;
V_23 -> V_463 = NULL ;
if ( V_461 )
V_23 -> V_463 =
F_427 ( V_461 ,
V_9 -> V_117 ) ;
}
static inline void F_450 ( struct V_431 * V_9 , struct V_23 * V_23 ,
unsigned long V_28 , unsigned long V_460 ) {}
void T_15 F_451 ( void )
{
unsigned int V_44 ;
if ( V_131 )
return;
if ( V_464 > V_16 )
V_44 = V_465 ;
else
V_44 = V_54 - 1 ;
V_131 = V_44 ;
}
void T_15 F_451 ( void )
{
}
static unsigned long T_15 F_452 ( unsigned long V_29 ,
unsigned long V_365 )
{
unsigned long V_154 = V_29 ;
if ( V_29 > V_365 + ( V_365 >> 4 ) &&
F_101 ( V_466 ) )
V_154 = V_365 ;
return F_341 ( V_154 * sizeof( struct V_1 ) ) >> V_16 ;
}
static void T_15 F_453 ( struct V_431 * V_9 )
{
enum V_344 V_401 ;
int V_13 = V_9 -> V_117 ;
unsigned long V_28 = V_9 -> V_123 ;
int V_24 ;
F_454 ( V_9 ) ;
#ifdef F_455
F_456 ( & V_9 -> V_467 ) ;
V_9 -> V_468 = 0 ;
V_9 -> V_469 = V_36 ;
#endif
F_429 ( & V_9 -> V_470 ) ;
F_429 ( & V_9 -> V_471 ) ;
F_457 ( V_9 ) ;
for ( V_401 = 0 ; V_401 < V_96 ; V_401 ++ ) {
struct V_23 * V_23 = V_9 -> V_97 + V_401 ;
unsigned long V_135 , V_472 , V_473 , V_474 ;
V_135 = V_23 -> V_29 ;
V_472 = V_473 = V_23 -> V_365 ;
V_474 = F_452 ( V_135 , V_472 ) ;
if ( ! F_109 ( V_401 ) ) {
if ( V_473 >= V_474 ) {
V_473 -= V_474 ;
if ( V_474 )
F_33 ( V_430
L_82 ,
V_418 [ V_401 ] , V_474 ) ;
} else
F_33 ( V_379
L_83 ,
V_418 [ V_401 ] , V_474 , V_473 ) ;
}
if ( V_401 == 0 && V_473 > V_475 ) {
V_473 -= V_475 ;
F_33 ( V_430 L_84 ,
V_418 [ 0 ] , V_475 ) ;
}
if ( ! F_109 ( V_401 ) )
V_476 += V_473 ;
else if ( V_476 > V_474 * 2 )
V_476 -= V_474 ;
V_477 += V_473 ;
V_23 -> V_106 = F_109 ( V_401 ) ? V_472 : V_473 ;
#ifdef V_294
V_23 -> V_109 = V_13 ;
V_23 -> V_478 = ( V_473 * V_479 )
/ 100 ;
V_23 -> V_480 = ( V_473 * V_481 ) / 100 ;
#endif
V_23 -> V_30 = V_418 [ V_401 ] ;
F_456 ( & V_23 -> V_85 ) ;
F_456 ( & V_23 -> V_482 ) ;
F_458 ( V_23 ) ;
V_23 -> V_227 = V_9 ;
F_430 ( V_23 ) ;
F_266 ( V_23 , V_196 , V_23 -> V_106 ) ;
F_459 ( & V_23 -> V_483 ) ;
if ( ! V_135 )
continue;
F_451 () ;
F_450 ( V_9 , V_23 , V_28 , V_135 ) ;
V_24 = F_431 ( V_23 , V_28 , V_135 ) ;
F_155 ( V_24 ) ;
F_460 ( V_135 , V_13 , V_401 , V_28 ) ;
V_28 += V_135 ;
}
}
static void T_14 F_461 ( struct V_431 * V_9 )
{
unsigned long T_16 V_98 = 0 ;
unsigned long T_16 V_321 = 0 ;
if ( ! V_9 -> V_458 )
return;
#ifdef F_462
V_98 = V_9 -> V_123 & ~ ( V_112 - 1 ) ;
V_321 = V_9 -> V_123 - V_98 ;
if ( ! V_9 -> V_484 ) {
unsigned long V_135 , V_99 ;
struct V_1 * V_485 ;
V_99 = F_14 ( V_9 ) ;
V_99 = F_463 ( V_99 , V_112 ) ;
V_135 = ( V_99 - V_98 ) * sizeof( struct V_1 ) ;
V_485 = F_464 ( V_9 -> V_117 , V_135 ) ;
if ( ! V_485 )
V_485 = F_427 ( V_135 ,
V_9 -> V_117 ) ;
V_9 -> V_484 = V_485 + V_321 ;
}
#ifndef F_465
if ( V_9 == F_10 ( 0 ) ) {
V_486 = F_10 ( 0 ) -> V_484 ;
#if F_466 ( V_487 ) || F_466 ( V_488 )
if ( F_19 ( V_486 ) != V_9 -> V_123 )
V_486 -= V_321 ;
#endif
}
#endif
#endif
}
void T_15 F_467 ( int V_13 , unsigned long * V_453 ,
unsigned long V_123 , unsigned long * V_454 )
{
T_1 * V_9 = F_10 ( V_13 ) ;
unsigned long V_27 = 0 ;
unsigned long V_100 = 0 ;
F_4 ( V_9 -> V_373 || V_9 -> V_217 ) ;
F_8 ( V_9 ) ;
V_9 -> V_117 = V_13 ;
V_9 -> V_123 = V_123 ;
#ifdef V_487
F_439 ( V_13 , & V_27 , & V_100 ) ;
F_161 ( L_85 , V_13 ,
( V_489 ) V_27 << V_16 ,
V_100 ? ( ( V_489 ) V_100 << V_16 ) - 1 : 0 ) ;
#endif
F_447 ( V_9 , V_27 , V_100 ,
V_453 , V_454 ) ;
F_461 ( V_9 ) ;
#ifdef F_462
F_33 ( V_430 L_86 ,
V_13 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_484 ) ;
#endif
F_453 ( V_9 ) ;
}
void T_3 F_468 ( void )
{
unsigned int V_490 ;
V_490 = F_469 ( V_491 . V_492 , V_399 ) ;
V_493 = V_490 + 1 ;
}
unsigned long T_3 F_470 ( void )
{
unsigned long V_494 = 0 , V_434 = 0 ;
unsigned long V_98 , V_99 , V_495 ;
int V_435 = - 1 ;
int V_45 , V_13 ;
F_156 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_98 || V_435 < 0 || V_435 == V_13 ) {
V_435 = V_13 ;
V_434 = V_99 ;
continue;
}
V_495 = ~ ( ( 1 << F_471 ( V_98 ) ) - 1 ) ;
while ( V_495 && V_434 <= ( V_98 & ( V_495 << 1 ) ) )
V_495 <<= 1 ;
V_494 |= V_495 ;
}
return ~ V_494 + 1 ;
}
static unsigned long T_3 F_472 ( int V_13 )
{
unsigned long V_496 = V_11 ;
unsigned long V_27 ;
int V_45 ;
F_156 (i, nid, &start_pfn, NULL, NULL)
V_496 = F_157 ( V_496 , V_27 ) ;
if ( V_496 == V_11 ) {
F_33 ( V_379
L_87 , V_13 ) ;
return 0 ;
}
return V_496 ;
}
unsigned long T_3 F_473 ( void )
{
return F_472 ( V_399 ) ;
}
static unsigned long T_3 F_474 ( void )
{
unsigned long V_456 = 0 ;
unsigned long V_27 , V_100 ;
int V_45 , V_13 ;
F_156 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_154 = V_100 - V_27 ;
V_456 += V_154 ;
if ( V_154 )
F_475 ( V_13 , V_128 ) ;
}
return V_456 ;
}
static void T_3 F_476 ( void )
{
int V_45 , V_13 ;
unsigned long V_497 ;
unsigned long V_498 , V_499 ;
T_8 V_500 = V_501 [ V_128 ] ;
unsigned long V_456 = F_474 () ;
int V_502 = F_477 ( V_501 [ V_128 ] ) ;
struct V_503 * V_504 ;
F_440 () ;
if ( F_478 () ) {
F_479 (memory, r) {
if ( ! F_480 ( V_504 ) )
continue;
V_13 = V_504 -> V_13 ;
V_497 = F_117 ( V_504 -> V_505 ) ;
V_446 [ V_13 ] = V_446 [ V_13 ] ?
F_157 ( V_497 , V_446 [ V_13 ] ) :
V_497 ;
}
goto V_506;
}
if ( V_507 ) {
unsigned long V_508 ;
V_507 =
F_449 ( V_507 , V_112 ) ;
V_507 = F_157 ( V_456 , V_507 ) ;
V_508 = V_456 - V_507 ;
V_509 = F_159 ( V_509 , V_508 ) ;
}
if ( ! V_509 || V_509 >= V_456 )
goto V_37;
V_497 = V_443 [ V_444 ] ;
V_510:
V_498 = V_509 / V_502 ;
F_166 (nid, N_MEMORY) {
unsigned long V_27 , V_100 ;
if ( V_509 < V_498 )
V_498 = V_509 / V_502 ;
V_499 = V_498 ;
F_156 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_511 ;
V_27 = F_159 ( V_27 , V_446 [ V_13 ] ) ;
if ( V_27 >= V_100 )
continue;
if ( V_27 < V_497 ) {
unsigned long V_512 ;
V_512 = F_157 ( V_100 , V_497 )
- V_27 ;
V_499 -= F_157 ( V_512 ,
V_499 ) ;
V_509 -= F_157 ( V_512 ,
V_509 ) ;
if ( V_100 <= V_497 ) {
V_446 [ V_13 ] = V_100 ;
continue;
}
V_27 = V_497 ;
}
V_511 = V_100 - V_27 ;
if ( V_511 > V_499 )
V_511 = V_499 ;
V_446 [ V_13 ] = V_27 + V_511 ;
V_509 -= F_157 ( V_509 ,
V_511 ) ;
V_499 -= V_511 ;
if ( ! V_499 )
break;
}
}
V_502 -- ;
if ( V_502 && V_509 > V_502 )
goto V_510;
V_506:
for ( V_13 = 0 ; V_13 < V_399 ; V_13 ++ )
V_446 [ V_13 ] =
F_449 ( V_446 [ V_13 ] , V_112 ) ;
V_37:
V_501 [ V_128 ] = V_500 ;
}
static void F_481 ( T_1 * V_9 , int V_13 )
{
enum V_344 V_344 ;
if ( V_128 == V_513 )
return;
for ( V_344 = 0 ; V_344 <= V_441 - 1 ; V_344 ++ ) {
struct V_23 * V_23 = & V_9 -> V_97 [ V_344 ] ;
if ( F_160 ( V_23 ) ) {
F_475 ( V_13 , V_514 ) ;
if ( V_513 != V_514 &&
V_344 <= V_264 )
F_475 ( V_13 , V_513 ) ;
break;
}
}
}
void T_3 F_482 ( unsigned long * V_183 )
{
unsigned long V_27 , V_100 ;
int V_45 , V_13 ;
memset ( V_443 , 0 ,
sizeof( V_443 ) ) ;
memset ( V_442 , 0 ,
sizeof( V_442 ) ) ;
V_443 [ 0 ] = F_473 () ;
V_442 [ 0 ] = V_183 [ 0 ] ;
for ( V_45 = 1 ; V_45 < V_96 ; V_45 ++ ) {
if ( V_45 == V_441 )
continue;
V_443 [ V_45 ] =
V_442 [ V_45 - 1 ] ;
V_442 [ V_45 ] =
F_159 ( V_183 [ V_45 ] , V_443 [ V_45 ] ) ;
}
V_443 [ V_441 ] = 0 ;
V_442 [ V_441 ] = 0 ;
memset ( V_446 , 0 , sizeof( V_446 ) ) ;
F_476 () ;
F_161 ( L_88 ) ;
for ( V_45 = 0 ; V_45 < V_96 ; V_45 ++ ) {
if ( V_45 == V_441 )
continue;
F_161 ( L_89 , V_418 [ V_45 ] ) ;
if ( V_443 [ V_45 ] ==
V_442 [ V_45 ] )
F_483 ( L_90 ) ;
else
F_483 ( L_91 ,
( V_489 ) V_443 [ V_45 ]
<< V_16 ,
( ( V_489 ) V_442 [ V_45 ]
<< V_16 ) - 1 ) ;
}
F_161 ( L_92 ) ;
for ( V_45 = 0 ; V_45 < V_399 ; V_45 ++ ) {
if ( V_446 [ V_45 ] )
F_161 ( L_93 , V_45 ,
( V_489 ) V_446 [ V_45 ] << V_16 ) ;
}
F_161 ( L_94 ) ;
F_156 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_161 ( L_95 , V_13 ,
( V_489 ) V_27 << V_16 ,
( ( V_489 ) V_100 << V_16 ) - 1 ) ;
F_484 () ;
F_468 () ;
F_393 (nid) {
T_1 * V_9 = F_10 ( V_13 ) ;
F_467 ( V_13 , NULL ,
F_472 ( V_13 ) , NULL ) ;
if ( V_9 -> V_459 )
F_475 ( V_13 , V_128 ) ;
F_481 ( V_9 , V_13 ) ;
}
}
static int T_3 F_485 ( char * V_48 , unsigned long * V_515 )
{
unsigned long long V_516 ;
if ( ! V_48 )
return - V_50 ;
V_516 = F_486 ( V_48 , & V_48 ) ;
* V_515 = V_516 >> V_16 ;
F_4 ( ( V_516 >> V_16 ) > V_11 ) ;
return 0 ;
}
static int T_3 F_487 ( char * V_48 )
{
return F_485 ( V_48 , & V_509 ) ;
}
static int T_3 F_488 ( char * V_48 )
{
return F_485 ( V_48 , & V_507 ) ;
}
void F_171 ( struct V_1 * V_1 , long V_79 )
{
F_88 ( & V_517 ) ;
F_27 ( V_1 ) -> V_106 += V_79 ;
V_335 += V_79 ;
#ifdef F_358
if ( F_128 ( V_1 ) )
V_341 += V_79 ;
#endif
F_96 ( & V_517 ) ;
}
unsigned long F_489 ( void * V_98 , void * V_99 , int V_518 , char * V_374 )
{
void * V_404 ;
unsigned long V_154 = 0 ;
V_98 = ( void * ) F_341 ( ( unsigned long ) V_98 ) ;
V_99 = ( void * ) ( ( unsigned long ) V_99 & V_519 ) ;
for ( V_404 = V_98 ; V_404 < V_99 ; V_404 += V_103 , V_154 ++ ) {
if ( ( unsigned int ) V_518 <= 0xFF )
memset ( V_404 , V_518 , V_103 ) ;
F_490 ( F_234 ( V_404 ) ) ;
}
if ( V_154 && V_374 )
F_161 ( L_96 ,
V_374 , V_154 << ( V_16 - 10 ) , V_98 , V_99 ) ;
return V_154 ;
}
void F_491 ( struct V_1 * V_1 )
{
F_492 ( V_1 ) ;
V_335 ++ ;
F_27 ( V_1 ) -> V_106 ++ ;
V_341 ++ ;
}
void T_3 F_493 ( const char * V_200 )
{
unsigned long V_520 , V_521 , V_522 , V_523 , V_524 ;
unsigned long V_525 , V_526 ;
V_520 = F_494 () ;
V_521 = V_527 - V_528 ;
V_522 = V_529 - V_530 ;
V_523 = V_531 - V_532 ;
V_524 = V_533 - V_534 ;
V_526 = V_535 - V_536 ;
V_525 = V_537 - V_538 ;
#define F_495 ( V_98 , V_99 , V_135 , V_404 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_495 ( V_536 , V_535 , V_526 ,
V_538 , V_525 ) ;
F_495 ( V_528 , V_527 , V_521 , V_538 , V_525 ) ;
F_495 ( V_530 , V_529 , V_522 , V_536 , V_526 ) ;
F_495 ( V_528 , V_527 , V_521 , V_532 , V_523 ) ;
F_495 ( V_530 , V_529 , V_522 , V_532 , V_523 ) ;
#undef F_495
F_161 ( L_97
L_98
L_99
#ifdef F_358
L_100
#endif
L_101 ,
F_496 () << ( V_16 - 10 ) , V_520 << ( V_16 - 10 ) ,
V_521 >> 10 , V_522 >> 10 , V_523 >> 10 ,
( V_526 + V_525 ) >> 10 , V_524 >> 10 ,
( V_520 - V_335 - V_539 ) << ( V_16 - 10 ) ,
V_539 << ( V_16 - 10 ) ,
#ifdef F_358
V_341 << ( V_16 - 10 ) ,
#endif
V_200 ? L_102 : L_103 , V_200 ? V_200 : L_103 ) ;
}
void T_3 F_497 ( unsigned long V_540 )
{
V_475 = V_540 ;
}
void T_3 F_498 ( unsigned long * V_453 )
{
F_467 ( 0 , V_453 ,
F_499 ( V_541 ) >> V_16 , NULL ) ;
}
static int F_500 ( struct V_542 * V_412 ,
unsigned long V_543 , void * V_544 )
{
int V_176 = ( unsigned long ) V_544 ;
if ( V_543 == V_545 || V_543 == V_546 ) {
F_501 ( V_176 ) ;
F_209 ( V_176 ) ;
F_502 ( V_176 ) ;
F_503 ( V_176 ) ;
}
return V_547 ;
}
void T_3 F_504 ( void )
{
F_505 ( F_500 , 0 ) ;
}
static void F_506 ( void )
{
struct V_431 * V_9 ;
unsigned long V_548 = 0 ;
enum V_344 V_45 , V_401 ;
F_507 (pgdat) {
for ( V_45 = 0 ; V_45 < V_96 ; V_45 ++ ) {
struct V_23 * V_23 = V_9 -> V_97 + V_45 ;
long F_159 = 0 ;
for ( V_401 = V_45 ; V_401 < V_96 ; V_401 ++ ) {
if ( V_23 -> V_223 [ V_401 ] > F_159 )
F_159 = V_23 -> V_223 [ V_401 ] ;
}
F_159 += F_267 ( V_23 ) ;
if ( F_159 > V_23 -> V_106 )
F_159 = V_23 -> V_106 ;
V_548 += F_159 ;
V_23 -> V_549 = F_159 ;
}
}
V_549 = V_548 ;
V_550 = V_548 ;
}
static void F_508 ( void )
{
struct V_431 * V_9 ;
enum V_344 V_401 , V_551 ;
F_507 (pgdat) {
for ( V_401 = 0 ; V_401 < V_96 ; V_401 ++ ) {
struct V_23 * V_23 = V_9 -> V_97 + V_401 ;
unsigned long V_106 = V_23 -> V_106 ;
V_23 -> V_223 [ V_401 ] = 0 ;
V_551 = V_401 ;
while ( V_551 ) {
struct V_23 * V_552 ;
V_551 -- ;
if ( V_553 [ V_551 ] < 1 )
V_553 [ V_551 ] = 1 ;
V_552 = V_9 -> V_97 + V_551 ;
V_552 -> V_223 [ V_401 ] = V_106 /
V_553 [ V_551 ] ;
V_106 += V_552 -> V_106 ;
}
}
}
F_506 () ;
}
static void F_509 ( void )
{
unsigned long V_554 = V_555 >> ( V_16 - 10 ) ;
unsigned long V_556 = 0 ;
struct V_23 * V_23 ;
unsigned long V_60 ;
F_510 (zone) {
if ( ! F_511 ( V_23 ) )
V_556 += V_23 -> V_106 ;
}
F_510 (zone) {
V_489 V_348 ;
F_194 ( & V_23 -> V_85 , V_60 ) ;
V_348 = ( V_489 ) V_554 * V_23 -> V_106 ;
F_512 ( V_348 , V_556 ) ;
if ( F_511 ( V_23 ) ) {
unsigned long V_557 ;
V_557 = V_23 -> V_106 / 1024 ;
V_557 = F_444 ( V_557 , V_558 , 128UL ) ;
V_23 -> V_188 [ V_559 ] = V_557 ;
} else {
V_23 -> V_188 [ V_559 ] = V_348 ;
}
V_23 -> V_188 [ V_560 ] = F_365 ( V_23 ) + ( V_348 >> 2 ) ;
V_23 -> V_188 [ V_561 ] = F_365 ( V_23 ) + ( V_348 >> 1 ) ;
F_90 ( V_23 , V_196 ,
F_267 ( V_23 ) - F_237 ( V_23 ) -
F_242 ( & V_23 -> V_197 [ V_196 ] ) ) ;
F_196 ( & V_23 -> V_85 , V_60 ) ;
}
F_506 () ;
}
void F_513 ( void )
{
F_378 ( & V_391 ) ;
F_509 () ;
F_285 ( & V_391 ) ;
}
static void T_2 F_514 ( struct V_23 * V_23 )
{
unsigned int V_562 , V_563 ;
V_562 = V_23 -> V_106 >> ( 30 - V_16 ) ;
if ( V_562 )
V_563 = F_515 ( 10 * V_562 ) ;
else
V_563 = 1 ;
V_23 -> V_564 = V_563 ;
}
static void T_2 F_516 ( void )
{
struct V_23 * V_23 ;
F_510 (zone)
F_514 ( V_23 ) ;
}
int T_2 F_517 ( void )
{
unsigned long V_565 ;
int V_566 ;
V_565 = F_349 () * ( V_103 >> 10 ) ;
V_566 = F_515 ( V_565 * 16 ) ;
if ( V_566 > V_567 ) {
V_555 = V_566 ;
if ( V_555 < 128 )
V_555 = 128 ;
if ( V_555 > 65536 )
V_555 = 65536 ;
} else {
F_279 ( L_104 ,
V_566 , V_567 ) ;
}
F_513 () ;
F_518 () ;
F_508 () ;
F_516 () ;
return 0 ;
}
int F_519 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
int V_568 ;
V_568 = F_520 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_568 )
return V_568 ;
if ( V_384 ) {
V_567 = V_555 ;
F_513 () ;
}
return 0 ;
}
int F_521 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
struct V_23 * V_23 ;
int V_568 ;
V_568 = F_520 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_568 )
return V_568 ;
F_510 (zone)
V_23 -> V_478 = ( V_23 -> V_106 *
V_479 ) / 100 ;
return 0 ;
}
int F_522 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
struct V_23 * V_23 ;
int V_568 ;
V_568 = F_520 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_568 )
return V_568 ;
F_510 (zone)
V_23 -> V_480 = ( V_23 -> V_106 *
V_481 ) / 100 ;
return 0 ;
}
int F_523 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
F_520 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
F_508 () ;
return 0 ;
}
int F_524 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
struct V_23 * V_23 ;
int V_569 ;
int V_24 ;
F_378 ( & V_570 ) ;
V_569 = V_425 ;
V_24 = F_520 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( ! V_384 || V_24 < 0 )
goto V_37;
if ( V_425 &&
V_425 < V_571 ) {
V_425 = V_569 ;
V_24 = - V_50 ;
goto V_37;
}
if ( V_425 == V_569 )
goto V_37;
F_210 (zone) {
unsigned int V_176 ;
F_394 (cpu)
F_421 ( V_23 ,
F_208 ( V_23 -> V_179 , V_176 ) ) ;
}
V_37:
F_285 ( & V_570 ) ;
return V_24 ;
}
static int T_3 F_525 ( char * V_200 )
{
if ( ! V_200 )
return 0 ;
V_572 = F_526 ( V_200 , & V_200 , 0 ) ;
return 1 ;
}
void * T_3 F_527 ( const char * V_573 ,
unsigned long V_574 ,
unsigned long V_575 ,
int V_576 ,
int V_60 ,
unsigned int * V_577 ,
unsigned int * V_578 ,
unsigned long V_579 ,
unsigned long V_580 )
{
unsigned long long F_159 = V_580 ;
unsigned long V_581 , V_135 ;
void * V_383 = NULL ;
if ( ! V_575 ) {
V_575 = V_476 ;
if ( V_16 < 20 )
V_575 = F_528 ( V_575 , ( 1 << 20 ) / V_103 ) ;
if ( V_576 > V_16 )
V_575 >>= ( V_576 - V_16 ) ;
else
V_575 <<= ( V_16 - V_576 ) ;
if ( F_16 ( V_60 & V_582 ) ) {
F_4 ( ! ( V_60 & V_583 ) ) ;
if ( ! ( V_575 >> * V_577 ) ) {
V_575 = 1UL << * V_577 ;
F_155 ( ! V_575 ) ;
}
} else if ( F_16 ( ( V_575 * V_574 ) < V_103 ) )
V_575 = V_103 / V_574 ;
}
V_575 = F_529 ( V_575 ) ;
if ( F_159 == 0 ) {
F_159 = ( ( unsigned long long ) V_477 << V_16 ) >> 4 ;
F_512 ( F_159 , V_574 ) ;
}
F_159 = F_157 ( F_159 , 0x80000000ULL ) ;
if ( V_575 < V_579 )
V_575 = V_579 ;
if ( V_575 > F_159 )
V_575 = F_159 ;
V_581 = F_530 ( V_575 ) ;
do {
V_135 = V_574 << V_581 ;
if ( V_60 & V_583 )
V_383 = F_531 ( V_135 , 0 ) ;
else if ( V_572 )
V_383 = F_532 ( V_135 , V_584 , V_585 ) ;
else {
if ( F_344 ( V_135 ) < V_54 ) {
V_383 = F_343 ( V_135 , V_584 ) ;
F_533 ( V_383 , V_135 , 1 , V_584 ) ;
}
}
} while ( ! V_383 && V_135 > V_103 && -- V_581 );
if ( ! V_383 )
F_534 ( L_105 , V_573 ) ;
F_33 ( V_57 L_106 ,
V_573 ,
( 1UL << V_581 ) ,
F_530 ( V_135 ) - V_16 ,
V_135 ) ;
if ( V_577 )
* V_577 = V_581 ;
if ( V_578 )
* V_578 = ( 1 << V_581 ) - 1 ;
return V_383 ;
}
static inline unsigned long * F_535 ( struct V_23 * V_23 ,
unsigned long V_12 )
{
#ifdef V_466
return F_536 ( V_12 ) -> V_463 ;
#else
return V_23 -> V_463 ;
#endif
}
static inline int F_537 ( struct V_23 * V_23 , unsigned long V_12 )
{
#ifdef V_466
V_12 &= ( V_17 - 1 ) ;
return ( V_12 >> V_131 ) * V_462 ;
#else
V_12 = V_12 - F_538 ( V_23 -> V_28 , V_129 ) ;
return ( V_12 >> V_131 ) * V_462 ;
#endif
}
unsigned long F_539 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_586 ,
unsigned long V_495 )
{
struct V_23 * V_23 ;
unsigned long * V_587 ;
unsigned long V_588 , V_589 ;
unsigned long V_590 ;
V_23 = F_27 ( V_1 ) ;
V_587 = F_535 ( V_23 , V_12 ) ;
V_588 = F_537 ( V_23 , V_12 ) ;
V_589 = V_588 / V_591 ;
V_588 &= ( V_591 - 1 ) ;
V_590 = V_587 [ V_589 ] ;
V_588 += V_586 ;
return ( V_590 >> ( V_591 - V_588 - 1 ) ) & V_495 ;
}
void F_540 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned long V_12 ,
unsigned long V_586 ,
unsigned long V_495 )
{
struct V_23 * V_23 ;
unsigned long * V_587 ;
unsigned long V_588 , V_589 ;
unsigned long V_592 , V_590 ;
F_100 ( V_462 != 4 ) ;
V_23 = F_27 ( V_1 ) ;
V_587 = F_535 ( V_23 , V_12 ) ;
V_588 = F_537 ( V_23 , V_12 ) ;
V_589 = V_588 / V_591 ;
V_588 &= ( V_591 - 1 ) ;
F_71 ( ! F_21 ( V_23 , V_12 ) , V_1 ) ;
V_588 += V_586 ;
V_495 <<= ( V_591 - V_588 - 1 ) ;
V_60 <<= ( V_591 - V_588 - 1 ) ;
V_590 = F_206 ( V_587 [ V_589 ] ) ;
for (; ; ) {
V_592 = F_541 ( & V_587 [ V_589 ] , V_590 , ( V_590 & ~ V_495 ) | V_60 ) ;
if ( V_590 == V_592 )
break;
V_590 = V_592 ;
}
}
bool F_542 ( struct V_23 * V_23 , struct V_1 * V_1 , int V_79 ,
bool V_593 )
{
unsigned long V_12 , V_594 , V_595 ;
int V_90 ;
if ( F_300 ( V_23 ) == V_441 )
return false ;
V_90 = F_94 ( V_1 ) ;
if ( V_90 == V_113 || F_195 ( V_90 ) )
return false ;
V_12 = F_19 ( V_1 ) ;
for ( V_595 = 0 , V_594 = 0 ; V_594 < V_129 ; V_594 ++ ) {
unsigned long V_596 = V_12 + V_594 ;
if ( ! F_26 ( V_596 ) )
continue;
V_1 = F_113 ( V_596 ) ;
if ( F_543 ( V_1 ) ) {
V_594 = F_528 ( V_594 + 1 , 1 << F_40 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_84 ( & V_1 -> V_76 ) ) {
if ( F_73 ( V_1 ) )
V_594 += ( 1 << F_69 ( V_1 ) ) - 1 ;
continue;
}
if ( V_593 && F_30 ( V_1 ) )
continue;
if ( ! F_544 ( V_1 ) )
V_595 ++ ;
if ( V_595 > V_79 )
return true ;
}
return false ;
}
bool F_545 ( struct V_1 * V_1 )
{
struct V_23 * V_23 ;
unsigned long V_12 ;
if ( ! F_391 ( F_186 ( V_1 ) ) )
return false ;
V_23 = F_27 ( V_1 ) ;
V_12 = F_19 ( V_1 ) ;
if ( ! F_21 ( V_23 , V_12 ) )
return false ;
return ! F_542 ( V_23 , V_1 , 0 , true ) ;
}
static unsigned long F_546 ( unsigned long V_12 )
{
return V_12 & ~ ( F_547 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_548 ( unsigned long V_12 )
{
return F_463 ( V_12 , F_547 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_549 ( struct V_597 * V_598 ,
unsigned long V_98 , unsigned long V_99 )
{
unsigned long V_599 ;
unsigned long V_12 = V_98 ;
unsigned int V_600 = 0 ;
int V_24 = 0 ;
F_550 () ;
while ( V_12 < V_99 || ! F_91 ( & V_598 -> V_601 ) ) {
if ( F_551 ( V_40 ) ) {
V_24 = - V_602 ;
break;
}
if ( F_91 ( & V_598 -> V_601 ) ) {
V_598 -> V_603 = 0 ;
V_12 = F_552 ( V_598 , V_12 , V_99 ) ;
if ( ! V_12 ) {
V_24 = - V_602 ;
break;
}
V_600 = 0 ;
} else if ( ++ V_600 == 5 ) {
V_24 = V_24 < 0 ? V_24 : - V_604 ;
break;
}
V_599 = F_553 ( V_598 -> V_23 ,
& V_598 -> V_601 ) ;
V_598 -> V_603 -= V_599 ;
V_24 = F_554 ( & V_598 -> V_601 , V_605 ,
NULL , 0 , V_598 -> V_208 , V_606 ) ;
}
if ( V_24 < 0 ) {
F_555 ( & V_598 -> V_601 ) ;
return V_24 ;
}
return 0 ;
}
int F_556 ( unsigned long V_98 , unsigned long V_99 ,
unsigned V_3 )
{
unsigned long V_607 , V_608 ;
unsigned int V_44 ;
int V_24 = 0 ;
struct V_597 V_598 = {
. V_603 = 0 ,
. V_44 = - 1 ,
. V_23 = F_27 ( F_113 ( V_98 ) ) ,
. V_208 = V_609 ,
. V_610 = true ,
} ;
F_57 ( & V_598 . V_601 ) ;
V_24 = F_557 ( F_546 ( V_98 ) ,
F_548 ( V_99 ) , V_3 ,
false ) ;
if ( V_24 )
return V_24 ;
V_24 = F_549 ( & V_598 , V_98 , V_99 ) ;
if ( V_24 )
goto V_611;
F_558 () ;
F_213 ( V_598 . V_23 ) ;
V_44 = 0 ;
V_607 = V_98 ;
while ( ! F_73 ( F_113 ( V_607 ) ) ) {
if ( ++ V_44 >= V_54 ) {
V_24 = - V_604 ;
goto V_611;
}
V_607 &= ~ 0UL << V_44 ;
}
if ( F_559 ( V_607 , V_99 , false ) ) {
F_161 ( L_107 ,
V_612 , V_607 , V_99 ) ;
V_24 = - V_604 ;
goto V_611;
}
V_608 = F_560 ( & V_598 , V_607 , V_99 ) ;
if ( ! V_608 ) {
V_24 = - V_604 ;
goto V_611;
}
if ( V_98 != V_607 )
F_561 ( V_607 , V_98 - V_607 ) ;
if ( V_99 != V_608 )
F_561 ( V_99 , V_608 - V_99 ) ;
V_611:
F_562 ( F_546 ( V_98 ) ,
F_548 ( V_99 ) , V_3 ) ;
return V_24 ;
}
void F_561 ( unsigned long V_12 , unsigned V_46 )
{
unsigned int V_79 = 0 ;
for (; V_46 -- ; V_12 ++ ) {
struct V_1 * V_1 = F_113 ( V_12 ) ;
V_79 += F_72 ( V_1 ) != 1 ;
F_563 ( V_1 ) ;
}
F_564 ( V_79 != 0 , L_108 , V_79 ) ;
}
void T_2 F_565 ( struct V_23 * V_23 )
{
unsigned V_176 ;
F_378 ( & V_570 ) ;
F_394 (cpu)
F_421 ( V_23 ,
F_208 ( V_23 -> V_179 , V_176 ) ) ;
F_285 ( & V_570 ) ;
}
void F_566 ( struct V_23 * V_23 )
{
unsigned long V_60 ;
int V_176 ;
struct V_177 * V_178 ;
F_134 ( V_60 ) ;
if ( V_23 -> V_179 != & V_413 ) {
F_214 (cpu) {
V_178 = F_208 ( V_23 -> V_179 , V_176 ) ;
F_567 ( V_23 , V_178 ) ;
}
F_568 ( V_23 -> V_179 ) ;
V_23 -> V_179 = & V_413 ;
}
F_136 ( V_60 ) ;
}
void
F_569 ( unsigned long V_27 , unsigned long V_100 )
{
struct V_1 * V_1 ;
struct V_23 * V_23 ;
unsigned int V_44 , V_45 ;
unsigned long V_12 ;
unsigned long V_60 ;
for ( V_12 = V_27 ; V_12 < V_100 ; V_12 ++ )
if ( F_119 ( V_12 ) )
break;
if ( V_12 == V_100 )
return;
V_23 = F_27 ( F_113 ( V_12 ) ) ;
F_194 ( & V_23 -> V_85 , V_60 ) ;
V_12 = V_27 ;
while ( V_12 < V_100 ) {
if ( ! F_119 ( V_12 ) ) {
V_12 ++ ;
continue;
}
V_1 = F_113 ( V_12 ) ;
if ( F_16 ( ! F_73 ( V_1 ) && F_30 ( V_1 ) ) ) {
V_12 ++ ;
F_120 ( V_1 ) ;
continue;
}
F_155 ( F_72 ( V_1 ) ) ;
F_155 ( ! F_73 ( V_1 ) ) ;
V_44 = F_69 ( V_1 ) ;
#ifdef V_94
F_33 ( V_57 L_109 ,
V_12 , 1 << V_44 , V_100 ) ;
#endif
F_79 ( & V_1 -> V_61 ) ;
F_65 ( V_1 ) ;
V_23 -> V_69 [ V_44 ] . V_70 -- ;
for ( V_45 = 0 ; V_45 < ( 1 << V_44 ) ; V_45 ++ )
F_120 ( ( V_1 + V_45 ) ) ;
V_12 += ( 1 << V_44 ) ;
}
F_196 ( & V_23 -> V_85 , V_60 ) ;
}
bool F_570 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = F_27 ( V_1 ) ;
unsigned long V_12 = F_19 ( V_1 ) ;
unsigned long V_60 ;
unsigned int V_44 ;
F_194 ( & V_23 -> V_85 , V_60 ) ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_1 * V_613 = V_1 - ( V_12 & ( ( 1 << V_44 ) - 1 ) ) ;
if ( F_73 ( V_613 ) && F_69 ( V_613 ) >= V_44 )
break;
}
F_196 ( & V_23 -> V_85 , V_60 ) ;
return V_44 < V_54 ;
}
