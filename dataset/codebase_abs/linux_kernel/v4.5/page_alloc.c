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
void F_38 ( struct V_1 * V_1 )
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
V_48 -> V_49 = V_50 ;
F_46 ( V_48 , V_1 ) ;
}
F_47 ( F_48 ( V_1 ) , - 1 ) ;
}
static int T_3 F_49 ( char * V_51 )
{
if ( ! V_51 )
return - V_52 ;
if ( strcmp ( V_51 , L_4 ) == 0 )
V_53 = true ;
return 0 ;
}
static bool F_50 ( void )
{
if ( ! F_51 () )
return false ;
return true ;
}
static void F_52 ( void )
{
if ( ! F_51 () )
return;
V_54 = true ;
}
static int T_3 F_53 ( char * V_51 )
{
unsigned long V_55 ;
if ( F_54 ( V_51 , 10 , & V_55 ) < 0 || V_55 > V_56 / 2 ) {
F_33 ( V_57 L_5 ) ;
return 0 ;
}
V_58 = V_55 ;
F_33 ( V_59 L_6 , V_55 ) ;
return 0 ;
}
static inline void F_55 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 )
{
struct V_60 * V_60 ;
if ( ! F_56 () )
return;
V_60 = F_57 ( V_1 ) ;
F_58 ( V_61 , & V_60 -> V_62 ) ;
F_59 ( & V_1 -> V_63 ) ;
F_60 ( V_1 , V_44 ) ;
F_61 ( V_23 , - ( 1 << V_44 ) , V_3 ) ;
}
static inline void F_62 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 )
{
struct V_60 * V_60 ;
if ( ! F_56 () )
return;
V_60 = F_57 ( V_1 ) ;
F_63 ( V_61 , & V_60 -> V_62 ) ;
F_60 ( V_1 , 0 ) ;
if ( ! F_64 ( V_3 ) )
F_61 ( V_23 , ( 1 << V_44 ) , V_3 ) ;
}
static inline void F_55 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 ) {}
static inline void F_62 ( struct V_23 * V_23 , struct V_1 * V_1 ,
unsigned int V_44 , int V_3 ) {}
static inline void F_65 ( struct V_1 * V_1 , unsigned int V_44 )
{
F_60 ( V_1 , V_44 ) ;
F_66 ( V_1 ) ;
}
static inline void F_67 ( struct V_1 * V_1 )
{
F_68 ( V_1 ) ;
F_60 ( V_1 , 0 ) ;
}
static inline int F_69 ( struct V_1 * V_1 , struct V_1 * V_64 ,
unsigned int V_44 )
{
if ( ! F_26 ( F_19 ( V_64 ) ) )
return 0 ;
if ( F_70 ( V_64 ) && F_71 ( V_64 ) == V_44 ) {
if ( F_72 ( V_1 ) != F_72 ( V_64 ) )
return 0 ;
F_73 ( F_74 ( V_64 ) != 0 , V_64 ) ;
return 1 ;
}
if ( F_75 ( V_64 ) && F_71 ( V_64 ) == V_44 ) {
if ( F_72 ( V_1 ) != F_72 ( V_64 ) )
return 0 ;
F_73 ( F_74 ( V_64 ) != 0 , V_64 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_76 ( struct V_1 * V_1 ,
unsigned long V_12 ,
struct V_23 * V_23 , unsigned int V_44 ,
int V_3 )
{
unsigned long V_65 ;
unsigned long V_66 ;
unsigned long V_67 ( V_68 ) ;
struct V_1 * V_64 ;
unsigned int V_69 = V_56 ;
F_77 ( ! F_78 ( V_23 ) ) ;
F_73 ( V_1 -> V_62 & V_70 , V_1 ) ;
F_77 ( V_3 == - 1 ) ;
if ( F_64 ( V_3 ) ) {
V_69 = F_79 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
} else {
F_61 ( V_23 , 1 << V_44 , V_3 ) ;
}
V_65 = V_12 & ( ( 1 << V_69 ) - 1 ) ;
F_73 ( V_65 & ( ( 1 << V_44 ) - 1 ) , V_1 ) ;
F_73 ( F_28 ( V_23 , V_1 ) , V_1 ) ;
while ( V_44 < V_69 - 1 ) {
V_68 = F_80 ( V_65 , V_44 ) ;
V_64 = V_1 + ( V_68 - V_65 ) ;
if ( ! F_69 ( V_1 , V_64 , V_44 ) )
break;
if ( F_70 ( V_64 ) ) {
F_62 ( V_23 , V_64 , V_44 , V_3 ) ;
} else {
F_81 ( & V_64 -> V_63 ) ;
V_23 -> V_71 [ V_44 ] . V_72 -- ;
F_67 ( V_64 ) ;
}
V_66 = V_68 & V_65 ;
V_1 = V_1 + ( V_66 - V_65 ) ;
V_65 = V_66 ;
V_44 ++ ;
}
F_65 ( V_1 , V_44 ) ;
if ( ( V_44 < V_56 - 2 ) && F_26 ( F_19 ( V_64 ) ) ) {
struct V_1 * V_73 , * V_74 ;
V_66 = V_68 & V_65 ;
V_73 = V_1 + ( V_66 - V_65 ) ;
V_68 = F_80 ( V_66 , V_44 + 1 ) ;
V_74 = V_73 + ( V_68 - V_66 ) ;
if ( F_69 ( V_73 , V_74 , V_44 + 1 ) ) {
F_82 ( & V_1 -> V_63 ,
& V_23 -> V_71 [ V_44 ] . V_75 [ V_3 ] ) ;
goto V_37;
}
}
F_83 ( & V_1 -> V_63 , & V_23 -> V_71 [ V_44 ] . V_75 [ V_3 ] ) ;
V_37:
V_23 -> V_71 [ V_44 ] . V_72 ++ ;
}
static inline int F_84 ( struct V_1 * V_1 )
{
const char * V_76 = NULL ;
unsigned long V_32 = 0 ;
if ( F_16 ( F_85 ( & V_1 -> V_77 ) != - 1 ) )
V_76 = L_7 ;
if ( F_16 ( V_1 -> V_49 != NULL ) )
V_76 = L_8 ;
if ( F_16 ( F_85 ( & V_1 -> V_78 ) != 0 ) )
V_76 = L_9 ;
if ( F_16 ( V_1 -> V_62 & V_79 ) ) {
V_76 = L_10 ;
V_32 = V_79 ;
}
#ifdef F_86
if ( F_16 ( V_1 -> V_80 ) )
V_76 = L_11 ;
#endif
if ( F_16 ( V_76 ) ) {
F_29 ( V_1 , V_76 , V_32 ) ;
return 1 ;
}
F_87 ( V_1 ) ;
if ( V_1 -> V_62 & V_70 )
V_1 -> V_62 &= ~ V_70 ;
return 0 ;
}
static void F_88 ( struct V_23 * V_23 , int V_81 ,
struct V_82 * V_83 )
{
int V_3 = 0 ;
int V_84 = 0 ;
int V_85 = V_81 ;
unsigned long V_86 ;
F_89 ( & V_23 -> V_87 ) ;
V_86 = F_90 ( V_23 , V_88 ) ;
if ( V_86 )
F_91 ( V_23 , V_88 , - V_86 ) ;
while ( V_85 ) {
struct V_1 * V_1 ;
struct V_89 * V_90 ;
do {
V_84 ++ ;
if ( ++ V_3 == V_19 )
V_3 = 0 ;
V_90 = & V_83 -> V_91 [ V_3 ] ;
} while ( F_92 ( V_90 ) );
if ( V_84 == V_19 )
V_84 = V_85 ;
do {
int V_92 ;
V_1 = F_93 ( V_90 , struct V_1 , V_63 ) ;
F_81 ( & V_1 -> V_63 ) ;
V_92 = F_1 ( V_1 ) ;
F_73 ( F_64 ( V_92 ) , V_1 ) ;
if ( F_16 ( F_94 ( V_23 ) ) )
V_92 = F_95 ( V_1 ) ;
F_76 ( V_1 , F_19 ( V_1 ) , V_23 , 0 , V_92 ) ;
F_96 ( V_1 , 0 , V_92 ) ;
} while ( -- V_85 && -- V_84 && ! F_92 ( V_90 ) );
}
F_97 ( & V_23 -> V_87 ) ;
}
static void F_98 ( struct V_23 * V_23 ,
struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_44 ,
int V_3 )
{
unsigned long V_86 ;
F_89 ( & V_23 -> V_87 ) ;
V_86 = F_90 ( V_23 , V_88 ) ;
if ( V_86 )
F_91 ( V_23 , V_88 , - V_86 ) ;
if ( F_16 ( F_94 ( V_23 ) ||
F_64 ( V_3 ) ) ) {
V_3 = F_99 ( V_1 , V_12 ) ;
}
F_76 ( V_1 , V_12 , V_23 , V_44 , V_3 ) ;
F_97 ( & V_23 -> V_87 ) ;
}
static int F_100 ( struct V_1 * V_93 , struct V_1 * V_1 )
{
int V_24 = 1 ;
F_101 ( ( unsigned long ) V_94 & 1 ) ;
if ( ! F_102 ( V_95 ) ) {
V_24 = 0 ;
goto V_37;
}
switch ( V_1 - V_93 ) {
case 1 :
if ( F_16 ( F_103 ( V_1 ) ) ) {
F_29 ( V_1 , L_12 , 0 ) ;
goto V_37;
}
break;
case 2 :
break;
default:
if ( V_1 -> V_49 != V_50 ) {
F_29 ( V_1 , L_13 , 0 ) ;
goto V_37;
}
break;
}
if ( F_16 ( ! F_104 ( V_1 ) ) ) {
F_29 ( V_1 , L_14 , 0 ) ;
goto V_37;
}
if ( F_16 ( F_105 ( V_1 ) != V_93 ) ) {
F_29 ( V_1 , L_15 , 0 ) ;
goto V_37;
}
V_24 = 0 ;
V_37:
V_1 -> V_49 = NULL ;
F_106 ( V_1 ) ;
return V_24 ;
}
static void T_2 F_107 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_23 , int V_13 )
{
F_108 ( V_1 , V_23 , V_13 , V_12 ) ;
F_109 ( V_1 ) ;
F_31 ( V_1 ) ;
F_87 ( V_1 ) ;
F_59 ( & V_1 -> V_63 ) ;
#ifdef F_110
if ( ! F_111 ( V_23 ) )
F_112 ( V_1 , F_113 ( V_12 << V_16 ) ) ;
#endif
}
static void T_2 F_114 ( unsigned long V_12 , unsigned long V_23 ,
int V_13 )
{
return F_107 ( F_115 ( V_12 ) , V_12 , V_23 , V_13 ) ;
}
static void F_116 ( unsigned long V_12 )
{
T_1 * V_9 ;
int V_13 , V_96 ;
if ( ! F_9 ( V_12 ) )
return;
V_13 = F_11 ( V_12 ) ;
V_9 = F_10 ( V_13 ) ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ ) {
struct V_23 * V_23 = & V_9 -> V_98 [ V_96 ] ;
if ( V_12 >= V_23 -> V_28 && V_12 < F_117 ( V_23 ) )
break;
}
F_114 ( V_12 , V_96 , V_13 ) ;
}
static inline void F_116 ( unsigned long V_12 )
{
}
void T_2 F_118 ( unsigned long V_99 , unsigned long V_100 )
{
unsigned long V_27 = F_119 ( V_99 ) ;
unsigned long V_101 = F_120 ( V_100 ) ;
for (; V_27 < V_101 ; V_27 ++ ) {
if ( F_121 ( V_27 ) ) {
struct V_1 * V_1 = F_115 ( V_27 ) ;
F_116 ( V_27 ) ;
F_59 ( & V_1 -> V_63 ) ;
F_122 ( V_1 ) ;
}
}
}
static bool F_123 ( struct V_1 * V_1 , unsigned int V_44 )
{
bool V_102 = F_124 ( V_1 ) ;
int V_45 , V_103 = 0 ;
F_73 ( F_104 ( V_1 ) , V_1 ) ;
F_73 ( V_102 && F_40 ( V_1 ) != V_44 , V_1 ) ;
F_125 ( V_1 , V_44 ) ;
F_126 ( V_1 , V_44 ) ;
F_127 ( V_1 , V_44 ) ;
if ( F_128 ( V_1 ) )
V_1 -> V_49 = NULL ;
V_103 += F_84 ( V_1 ) ;
for ( V_45 = 1 ; V_45 < ( 1 << V_44 ) ; V_45 ++ ) {
if ( V_102 )
V_103 += F_100 ( V_1 , V_1 + V_45 ) ;
V_103 += F_84 ( V_1 + V_45 ) ;
}
if ( V_103 )
return false ;
F_129 ( V_1 , V_44 ) ;
if ( ! F_130 ( V_1 ) ) {
F_131 ( F_132 ( V_1 ) ,
V_104 << V_44 ) ;
F_133 ( F_132 ( V_1 ) ,
V_104 << V_44 ) ;
}
F_134 ( V_1 , V_44 ) ;
F_135 ( V_1 , 1 << V_44 , 0 ) ;
return true ;
}
static void F_39 ( struct V_1 * V_1 , unsigned int V_44 )
{
unsigned long V_62 ;
int V_3 ;
unsigned long V_12 = F_19 ( V_1 ) ;
if ( ! F_123 ( V_1 , V_44 ) )
return;
V_3 = F_99 ( V_1 , V_12 ) ;
F_136 ( V_62 ) ;
F_137 ( V_105 , 1 << V_44 ) ;
F_98 ( F_27 ( V_1 ) , V_1 , V_12 , V_44 , V_3 ) ;
F_138 ( V_62 ) ;
}
static void T_3 F_139 ( struct V_1 * V_1 ,
unsigned long V_12 , unsigned int V_44 )
{
unsigned int V_46 = 1 << V_44 ;
struct V_1 * V_48 = V_1 ;
unsigned int V_106 ;
F_140 ( V_48 ) ;
for ( V_106 = 0 ; V_106 < ( V_46 - 1 ) ; V_106 ++ , V_48 ++ ) {
F_140 ( V_48 + 1 ) ;
F_141 ( V_48 ) ;
F_45 ( V_48 , 0 ) ;
}
F_141 ( V_48 ) ;
F_45 ( V_48 , 0 ) ;
F_27 ( V_1 ) -> V_107 += V_46 ;
F_142 ( V_1 ) ;
F_143 ( V_1 , V_44 ) ;
}
int T_2 F_11 ( unsigned long V_12 )
{
static F_144 ( V_108 ) ;
int V_13 ;
F_89 ( & V_108 ) ;
V_13 = F_145 ( V_12 , & V_109 ) ;
if ( V_13 < 0 )
V_13 = 0 ;
F_97 ( & V_108 ) ;
return V_13 ;
}
static inline bool T_2 F_146 ( unsigned long V_12 , int V_110 ,
struct V_111 * V_112 )
{
int V_13 ;
V_13 = F_145 ( V_12 , V_112 ) ;
if ( V_13 >= 0 && V_13 != V_110 )
return false ;
return true ;
}
static inline bool T_2 F_147 ( unsigned long V_12 , int V_110 )
{
return F_146 ( V_12 , V_110 , & V_109 ) ;
}
static inline bool T_2 F_147 ( unsigned long V_12 , int V_110 )
{
return true ;
}
static inline bool T_2 F_146 ( unsigned long V_12 , int V_110 ,
struct V_111 * V_112 )
{
return true ;
}
void T_3 F_148 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_44 )
{
if ( F_9 ( V_12 ) )
return;
return F_139 ( V_1 , V_12 , V_44 ) ;
}
static void T_3 F_149 ( struct V_1 * V_1 ,
unsigned long V_12 , int V_46 )
{
int V_45 ;
if ( ! V_1 )
return;
if ( V_46 == V_113 &&
( V_12 & ( V_113 - 1 ) ) == 0 ) {
F_15 ( V_1 , V_114 ) ;
F_139 ( V_1 , V_12 , V_56 - 1 ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ , V_1 ++ , V_12 ++ )
F_139 ( V_1 , V_12 , 0 ) ;
}
static inline void T_3 F_150 ( void )
{
if ( F_151 ( & V_115 ) )
F_152 ( & V_116 ) ;
}
static int T_3 F_153 ( void * V_117 )
{
T_1 * V_9 = V_117 ;
int V_13 = V_9 -> V_118 ;
struct V_111 V_119 = { } ;
unsigned long V_99 = V_36 ;
unsigned long V_46 = 0 ;
unsigned long V_120 , V_121 ;
int V_45 , V_96 ;
struct V_23 * V_23 ;
unsigned long V_122 = V_9 -> V_10 ;
const struct V_123 * V_123 = F_154 ( V_9 -> V_118 ) ;
if ( V_122 == V_11 ) {
F_150 () ;
return 0 ;
}
if ( ! F_155 ( V_123 ) )
F_156 ( V_40 , V_123 ) ;
F_157 ( V_9 -> V_10 < V_9 -> V_124 ) ;
F_157 ( V_9 -> V_10 > F_14 ( V_9 ) ) ;
V_9 -> V_10 = V_11 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ ) {
V_23 = V_9 -> V_98 + V_96 ;
if ( V_122 < F_117 ( V_23 ) )
break;
}
F_158 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_12 , V_101 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_125 = NULL ;
unsigned long V_126 = 0 ;
int V_127 = 0 ;
V_101 = F_159 ( V_121 , F_117 ( V_23 ) ) ;
V_12 = V_122 ;
if ( V_12 < V_120 )
V_12 = V_120 ;
if ( V_12 < V_23 -> V_28 )
V_12 = V_23 -> V_28 ;
for (; V_12 < V_101 ; V_12 ++ ) {
if ( ! F_26 ( V_12 ) )
goto V_128;
if ( ( V_12 & ( V_113 - 1 ) ) == 0 ) {
if ( ! F_121 ( V_12 ) ) {
V_1 = NULL ;
goto V_128;
}
}
if ( ! F_146 ( V_12 , V_13 , & V_119 ) ) {
V_1 = NULL ;
goto V_128;
}
if ( V_1 && ( V_12 & ( V_113 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_46 += V_127 ;
F_149 ( V_125 ,
V_126 , V_127 ) ;
V_125 = NULL ;
V_126 = V_127 = 0 ;
V_1 = F_115 ( V_12 ) ;
F_160 () ;
}
if ( V_1 -> V_62 ) {
F_77 ( F_27 ( V_1 ) != V_23 ) ;
goto V_128;
}
F_107 ( V_1 , V_12 , V_96 , V_13 ) ;
if ( ! V_125 ) {
V_125 = V_1 ;
V_126 = V_12 ;
V_127 = 0 ;
}
V_127 ++ ;
continue;
V_128:
V_46 += V_127 ;
F_149 ( V_125 , V_126 ,
V_127 ) ;
V_125 = NULL ;
V_126 = V_127 = 0 ;
}
V_122 = F_161 ( V_101 , V_122 ) ;
}
F_4 ( ++ V_96 < V_97 && F_162 ( ++ V_23 ) ) ;
F_163 ( L_16 , V_13 , V_46 ,
F_164 ( V_36 - V_99 ) ) ;
F_150 () ;
return 0 ;
}
void T_3 F_165 ( void )
{
int V_13 ;
F_47 ( & V_115 , F_166 ( V_129 ) ) ;
F_167 (nid, N_MEMORY) {
F_168 ( F_153 , F_10 ( V_13 ) , L_17 , V_13 ) ;
}
F_169 ( & V_116 ) ;
F_170 () ;
}
void T_3 F_171 ( struct V_1 * V_1 )
{
unsigned V_45 = V_130 ;
struct V_1 * V_48 = V_1 ;
do {
F_141 ( V_48 ) ;
F_45 ( V_48 , 0 ) ;
} while ( ++ V_48 , -- V_45 );
F_15 ( V_1 , V_131 ) ;
if ( V_132 >= V_56 ) {
V_45 = V_130 ;
V_48 = V_1 ;
do {
F_142 ( V_48 ) ;
F_143 ( V_48 , V_56 - 1 ) ;
V_48 += V_113 ;
} while ( V_45 -= V_113 );
} else {
F_142 ( V_1 ) ;
F_143 ( V_1 , V_132 ) ;
}
F_172 ( V_1 , V_130 ) ;
}
static inline void F_173 ( struct V_23 * V_23 , struct V_1 * V_1 ,
int V_133 , int V_134 , struct V_71 * V_135 ,
int V_3 )
{
unsigned long V_136 = 1 << V_134 ;
while ( V_134 > V_133 ) {
V_135 -- ;
V_134 -- ;
V_136 >>= 1 ;
F_73 ( F_28 ( V_23 , & V_1 [ V_136 ] ) , & V_1 [ V_136 ] ) ;
if ( F_102 ( V_137 ) &&
F_56 () &&
V_134 < F_174 () ) {
F_55 ( V_23 , & V_1 [ V_136 ] , V_134 , V_3 ) ;
continue;
}
F_83 ( & V_1 [ V_136 ] . V_63 , & V_135 -> V_75 [ V_3 ] ) ;
V_135 -> V_72 ++ ;
F_65 ( & V_1 [ V_136 ] , V_134 ) ;
}
}
static inline int F_175 ( struct V_1 * V_1 )
{
const char * V_76 = NULL ;
unsigned long V_32 = 0 ;
if ( F_16 ( F_85 ( & V_1 -> V_77 ) != - 1 ) )
V_76 = L_7 ;
if ( F_16 ( V_1 -> V_49 != NULL ) )
V_76 = L_8 ;
if ( F_16 ( F_85 ( & V_1 -> V_78 ) != 0 ) )
V_76 = L_9 ;
if ( F_16 ( V_1 -> V_62 & V_138 ) ) {
V_76 = L_18 ;
V_32 = V_138 ;
}
if ( F_16 ( V_1 -> V_62 & V_70 ) ) {
V_76 = L_19 ;
V_32 = V_70 ;
}
#ifdef F_86
if ( F_16 ( V_1 -> V_80 ) )
V_76 = L_11 ;
#endif
if ( F_16 ( V_76 ) ) {
F_29 ( V_1 , V_76 , V_32 ) ;
return 1 ;
}
return 0 ;
}
static int F_176 ( struct V_1 * V_1 , unsigned int V_44 , T_4 V_139 ,
int V_140 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < ( 1 << V_44 ) ; V_45 ++ ) {
struct V_1 * V_48 = V_1 + V_45 ;
if ( F_16 ( F_175 ( V_48 ) ) )
return 1 ;
}
F_60 ( V_1 , 0 ) ;
F_142 ( V_1 ) ;
F_177 ( V_1 , V_44 ) ;
F_135 ( V_1 , 1 << V_44 , 1 ) ;
F_178 ( V_1 , V_44 ) ;
if ( V_139 & V_141 )
for ( V_45 = 0 ; V_45 < ( 1 << V_44 ) ; V_45 ++ )
F_179 ( V_1 + V_45 ) ;
if ( V_44 && ( V_139 & V_142 ) )
F_41 ( V_1 , V_44 ) ;
F_180 ( V_1 , V_44 , V_139 ) ;
if ( V_140 & V_143 )
F_181 ( V_1 ) ;
else
F_182 ( V_1 ) ;
return 0 ;
}
static inline
struct V_1 * F_183 ( struct V_23 * V_23 , unsigned int V_44 ,
int V_3 )
{
unsigned int V_144 ;
struct V_71 * V_135 ;
struct V_1 * V_1 ;
for ( V_144 = V_44 ; V_144 < V_56 ; ++ V_144 ) {
V_135 = & ( V_23 -> V_71 [ V_144 ] ) ;
V_1 = F_184 ( & V_135 -> V_75 [ V_3 ] ,
struct V_1 , V_63 ) ;
if ( ! V_1 )
continue;
F_81 ( & V_1 -> V_63 ) ;
F_67 ( V_1 ) ;
V_135 -> V_72 -- ;
F_173 ( V_23 , V_1 , V_44 , V_144 , V_135 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_185 ( struct V_23 * V_23 ,
unsigned int V_44 )
{
return F_183 ( V_23 , V_44 , V_131 ) ;
}
static inline struct V_1 * F_185 ( struct V_23 * V_23 ,
unsigned int V_44 ) { return NULL ; }
int F_186 ( struct V_23 * V_23 ,
struct V_1 * V_145 , struct V_1 * V_146 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned int V_44 ;
int V_147 = 0 ;
#ifndef F_187
F_77 ( F_27 ( V_145 ) != F_27 ( V_146 ) ) ;
#endif
for ( V_1 = V_145 ; V_1 <= V_146 ; ) {
F_73 ( F_188 ( V_1 ) != F_24 ( V_23 ) , V_1 ) ;
if ( ! F_26 ( F_19 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
if ( ! F_75 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_44 = F_71 ( V_1 ) ;
F_189 ( & V_1 -> V_63 ,
& V_23 -> V_71 [ V_44 ] . V_75 [ V_3 ] ) ;
V_1 += 1 << V_44 ;
V_147 += 1 << V_44 ;
}
return V_147 ;
}
int F_190 ( struct V_23 * V_23 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_27 , V_101 ;
struct V_1 * V_145 , * V_146 ;
V_27 = F_19 ( V_1 ) ;
V_27 = V_27 & ~ ( V_130 - 1 ) ;
V_145 = F_115 ( V_27 ) ;
V_146 = V_145 + V_130 - 1 ;
V_101 = V_27 + V_130 - 1 ;
if ( ! F_21 ( V_23 , V_27 ) )
V_145 = V_1 ;
if ( ! F_21 ( V_23 , V_101 ) )
return 0 ;
return F_186 ( V_23 , V_145 , V_146 , V_3 ) ;
}
static void F_191 ( struct V_1 * V_148 ,
int V_149 , int V_3 )
{
int V_150 = 1 << ( V_149 - V_132 ) ;
while ( V_150 -- ) {
F_15 ( V_148 , V_3 ) ;
V_148 += V_130 ;
}
}
static bool F_192 ( unsigned int V_44 , int V_151 )
{
if ( V_44 >= V_132 )
return true ;
if ( V_44 >= V_132 / 2 ||
V_151 == V_152 ||
V_151 == V_20 ||
V_18 )
return true ;
return false ;
}
static void F_193 ( struct V_23 * V_23 , struct V_1 * V_1 ,
int V_153 )
{
unsigned int V_144 = F_71 ( V_1 ) ;
int V_154 ;
if ( V_144 >= V_132 ) {
F_191 ( V_1 , V_144 , V_153 ) ;
return;
}
V_154 = F_190 ( V_23 , V_1 , V_153 ) ;
if ( V_154 >= ( 1 << ( V_132 - 1 ) ) ||
V_18 )
F_15 ( V_1 , V_153 ) ;
}
int F_194 ( struct V_71 * V_135 , unsigned int V_44 ,
int V_3 , bool V_155 , bool * V_156 )
{
int V_45 ;
int V_157 ;
if ( V_135 -> V_72 == 0 )
return - 1 ;
* V_156 = false ;
for ( V_45 = 0 ; ; V_45 ++ ) {
V_157 = V_158 [ V_3 ] [ V_45 ] ;
if ( V_157 == V_159 )
break;
if ( F_92 ( & V_135 -> V_75 [ V_157 ] ) )
continue;
if ( F_192 ( V_44 , V_3 ) )
* V_156 = true ;
if ( ! V_155 )
return V_157 ;
if ( * V_156 )
return V_157 ;
}
return - 1 ;
}
static void F_195 ( struct V_1 * V_1 , struct V_23 * V_23 ,
unsigned int V_160 )
{
int V_92 ;
unsigned long V_161 , V_62 ;
V_161 = ( V_23 -> V_107 / 100 ) + V_130 ;
if ( V_23 -> V_162 >= V_161 )
return;
F_196 ( & V_23 -> V_87 , V_62 ) ;
if ( V_23 -> V_162 >= V_161 )
goto V_163;
V_92 = F_95 ( V_1 ) ;
if ( V_92 != V_164 &&
! F_64 ( V_92 ) && ! F_197 ( V_92 ) ) {
V_23 -> V_162 += V_130 ;
F_15 ( V_1 , V_164 ) ;
F_190 ( V_23 , V_1 , V_164 ) ;
}
V_163:
F_198 ( & V_23 -> V_87 , V_62 ) ;
}
static void F_199 ( const struct V_165 * V_166 )
{
struct V_167 * V_167 = V_166 -> V_167 ;
unsigned long V_62 ;
struct V_168 * V_169 ;
struct V_23 * V_23 ;
struct V_1 * V_1 ;
int V_44 ;
F_200 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( V_23 -> V_162 <= V_130 )
continue;
F_196 ( & V_23 -> V_87 , V_62 ) ;
for ( V_44 = 0 ; V_44 < V_56 ; V_44 ++ ) {
struct V_71 * V_135 = & ( V_23 -> V_71 [ V_44 ] ) ;
V_1 = F_184 (
& V_135 -> V_75 [ V_164 ] ,
struct V_1 , V_63 ) ;
if ( ! V_1 )
continue;
V_23 -> V_162 -= F_159 ( V_130 ,
V_23 -> V_162 ) ;
F_15 ( V_1 , V_166 -> V_3 ) ;
F_190 ( V_23 , V_1 , V_166 -> V_3 ) ;
F_198 ( & V_23 -> V_87 , V_62 ) ;
return;
}
F_198 ( & V_23 -> V_87 , V_62 ) ;
}
}
static inline struct V_1 *
F_201 ( struct V_23 * V_23 , unsigned int V_44 , int V_170 )
{
struct V_71 * V_135 ;
unsigned int V_144 ;
struct V_1 * V_1 ;
int V_157 ;
bool V_156 ;
for ( V_144 = V_56 - 1 ;
V_144 >= V_44 && V_144 <= V_56 - 1 ;
-- V_144 ) {
V_135 = & ( V_23 -> V_71 [ V_144 ] ) ;
V_157 = F_194 ( V_135 , V_144 ,
V_170 , false , & V_156 ) ;
if ( V_157 == - 1 )
continue;
V_1 = F_202 ( & V_135 -> V_75 [ V_157 ] ,
struct V_1 , V_63 ) ;
if ( V_156 )
F_193 ( V_23 , V_1 , V_170 ) ;
V_135 -> V_72 -- ;
F_81 ( & V_1 -> V_63 ) ;
F_67 ( V_1 ) ;
F_173 ( V_23 , V_1 , V_44 , V_144 , V_135 ,
V_170 ) ;
F_2 ( V_1 , V_170 ) ;
F_203 ( V_1 , V_44 , V_144 ,
V_170 , V_157 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_204 ( struct V_23 * V_23 , unsigned int V_44 ,
int V_3 )
{
struct V_1 * V_1 ;
V_1 = F_183 ( V_23 , V_44 , V_3 ) ;
if ( F_16 ( ! V_1 ) ) {
if ( V_3 == V_114 )
V_1 = F_185 ( V_23 , V_44 ) ;
if ( ! V_1 )
V_1 = F_201 ( V_23 , V_44 , V_3 ) ;
}
F_205 ( V_1 , V_44 , V_3 ) ;
return V_1 ;
}
static int F_206 ( struct V_23 * V_23 , unsigned int V_44 ,
unsigned long V_81 , struct V_89 * V_90 ,
int V_3 , bool V_171 )
{
int V_45 ;
F_89 ( & V_23 -> V_87 ) ;
for ( V_45 = 0 ; V_45 < V_81 ; ++ V_45 ) {
struct V_1 * V_1 = F_204 ( V_23 , V_44 , V_3 ) ;
if ( F_16 ( V_1 == NULL ) )
break;
if ( F_207 ( ! V_171 ) )
F_83 ( & V_1 -> V_63 , V_90 ) ;
else
F_82 ( & V_1 -> V_63 , V_90 ) ;
V_90 = & V_1 -> V_63 ;
if ( F_197 ( F_1 ( V_1 ) ) )
F_91 ( V_23 , V_172 ,
- ( 1 << V_44 ) ) ;
}
F_91 ( V_23 , V_173 , - ( V_45 << V_44 ) ) ;
F_97 ( & V_23 -> V_87 ) ;
return V_45 ;
}
void F_208 ( struct V_23 * V_23 , struct V_82 * V_83 )
{
unsigned long V_62 ;
int V_174 , V_175 ;
F_136 ( V_62 ) ;
V_175 = F_209 ( V_83 -> V_175 ) ;
V_174 = F_159 ( V_83 -> V_81 , V_175 ) ;
if ( V_174 > 0 ) {
F_88 ( V_23 , V_174 , V_83 ) ;
V_83 -> V_81 -= V_174 ;
}
F_138 ( V_62 ) ;
}
static void F_210 ( unsigned int V_176 , struct V_23 * V_23 )
{
unsigned long V_62 ;
struct V_177 * V_178 ;
struct V_82 * V_83 ;
F_136 ( V_62 ) ;
V_178 = F_211 ( V_23 -> V_179 , V_176 ) ;
V_83 = & V_178 -> V_83 ;
if ( V_83 -> V_81 ) {
F_88 ( V_23 , V_83 -> V_81 , V_83 ) ;
V_83 -> V_81 = 0 ;
}
F_138 ( V_62 ) ;
}
static void F_212 ( unsigned int V_176 )
{
struct V_23 * V_23 ;
F_213 (zone) {
F_210 ( V_176 , V_23 ) ;
}
}
void F_214 ( struct V_23 * V_23 )
{
int V_176 = F_215 () ;
if ( V_23 )
F_210 ( V_176 , V_23 ) ;
else
F_212 ( V_176 ) ;
}
void F_216 ( struct V_23 * V_23 )
{
int V_176 ;
static T_5 V_180 ;
F_217 (cpu) {
struct V_177 * V_83 ;
struct V_23 * V_169 ;
bool V_181 = false ;
if ( V_23 ) {
V_83 = F_211 ( V_23 -> V_179 , V_176 ) ;
if ( V_83 -> V_83 . V_81 )
V_181 = true ;
} else {
F_213 (z) {
V_83 = F_211 ( V_169 -> V_179 , V_176 ) ;
if ( V_83 -> V_83 . V_81 ) {
V_181 = true ;
break;
}
}
}
if ( V_181 )
F_218 ( V_176 , & V_180 ) ;
else
F_219 ( V_176 , & V_180 ) ;
}
F_220 ( & V_180 , ( V_182 ) F_214 ,
V_23 , 1 ) ;
}
void F_221 ( struct V_23 * V_23 )
{
unsigned long V_12 , V_183 ;
unsigned long V_62 ;
unsigned int V_44 , V_184 ;
struct V_1 * V_1 ;
if ( F_222 ( V_23 ) )
return;
F_196 ( & V_23 -> V_87 , V_62 ) ;
V_183 = F_117 ( V_23 ) ;
for ( V_12 = V_23 -> V_28 ; V_12 < V_183 ; V_12 ++ )
if ( F_121 ( V_12 ) ) {
V_1 = F_115 ( V_12 ) ;
if ( ! F_223 ( V_1 ) )
F_224 ( V_1 ) ;
}
F_225 (order, t) {
F_226 (page,
&zone->free_area[order].free_list[t], lru) {
unsigned long V_45 ;
V_12 = F_19 ( V_1 ) ;
for ( V_45 = 0 ; V_45 < ( 1UL << V_44 ) ; V_45 ++ )
F_227 ( F_115 ( V_12 + V_45 ) ) ;
}
}
F_198 ( & V_23 -> V_87 , V_62 ) ;
}
void F_228 ( struct V_1 * V_1 , bool V_171 )
{
struct V_23 * V_23 = F_27 ( V_1 ) ;
struct V_82 * V_83 ;
unsigned long V_62 ;
unsigned long V_12 = F_19 ( V_1 ) ;
int V_3 ;
if ( ! F_123 ( V_1 , 0 ) )
return;
V_3 = F_99 ( V_1 , V_12 ) ;
F_2 ( V_1 , V_3 ) ;
F_136 ( V_62 ) ;
F_229 ( V_105 ) ;
if ( V_3 >= V_19 ) {
if ( F_16 ( F_64 ( V_3 ) ) ) {
F_98 ( V_23 , V_1 , V_12 , 0 , V_3 ) ;
goto V_37;
}
V_3 = V_114 ;
}
V_83 = & F_230 ( V_23 -> V_179 ) -> V_83 ;
if ( ! V_171 )
F_83 ( & V_1 -> V_63 , & V_83 -> V_91 [ V_3 ] ) ;
else
F_82 ( & V_1 -> V_63 , & V_83 -> V_91 [ V_3 ] ) ;
V_83 -> V_81 ++ ;
if ( V_83 -> V_81 >= V_83 -> V_134 ) {
unsigned long V_175 = F_209 ( V_83 -> V_175 ) ;
F_88 ( V_23 , V_175 , V_83 ) ;
V_83 -> V_81 -= V_175 ;
}
V_37:
F_138 ( V_62 ) ;
}
void F_231 ( struct V_89 * V_90 , bool V_171 )
{
struct V_1 * V_1 , * V_185 ;
F_232 (page, next, list, lru) {
F_233 ( V_1 , V_171 ) ;
F_228 ( V_1 , V_171 ) ;
}
}
void F_234 ( struct V_1 * V_1 , unsigned int V_44 )
{
int V_45 ;
T_4 V_186 ;
F_73 ( F_124 ( V_1 ) , V_1 ) ;
F_73 ( ! F_74 ( V_1 ) , V_1 ) ;
#ifdef F_235
if ( F_236 ( V_1 ) )
F_234 ( F_237 ( V_1 [ 0 ] . V_187 ) , V_44 ) ;
#endif
V_186 = F_238 ( V_1 ) ;
F_180 ( V_1 , 0 , V_186 ) ;
for ( V_45 = 1 ; V_45 < ( 1 << V_44 ) ; V_45 ++ ) {
F_142 ( V_1 + V_45 ) ;
F_180 ( V_1 + V_45 , 0 , V_186 ) ;
}
}
int F_239 ( struct V_1 * V_1 , unsigned int V_44 )
{
unsigned long V_188 ;
struct V_23 * V_23 ;
int V_92 ;
F_157 ( ! F_75 ( V_1 ) ) ;
V_23 = F_27 ( V_1 ) ;
V_92 = F_95 ( V_1 ) ;
if ( ! F_64 ( V_92 ) ) {
V_188 = F_240 ( V_23 ) + ( 1 << V_44 ) ;
if ( ! F_241 ( V_23 , 0 , V_188 , 0 , 0 ) )
return 0 ;
F_61 ( V_23 , - ( 1UL << V_44 ) , V_92 ) ;
}
F_81 ( & V_1 -> V_63 ) ;
V_23 -> V_71 [ V_44 ] . V_72 -- ;
F_67 ( V_1 ) ;
F_180 ( V_1 , V_44 , V_189 ) ;
if ( V_44 >= V_132 - 1 ) {
struct V_1 * V_190 = V_1 + ( 1 << V_44 ) - 1 ;
for (; V_1 < V_190 ; V_1 += V_130 ) {
int V_92 = F_95 ( V_1 ) ;
if ( ! F_64 ( V_92 ) && ! F_197 ( V_92 ) )
F_15 ( V_1 ,
V_114 ) ;
}
}
return 1UL << V_44 ;
}
int F_242 ( struct V_1 * V_1 )
{
unsigned int V_44 ;
int V_46 ;
V_44 = F_71 ( V_1 ) ;
V_46 = F_239 ( V_1 , V_44 ) ;
if ( ! V_46 )
return 0 ;
F_142 ( V_1 ) ;
F_234 ( V_1 , V_44 ) ;
return V_46 ;
}
static inline
struct V_1 * F_243 ( struct V_23 * V_191 ,
struct V_23 * V_23 , unsigned int V_44 ,
T_4 V_139 , int V_140 , int V_3 )
{
unsigned long V_62 ;
struct V_1 * V_1 ;
bool V_171 = ( ( V_139 & V_192 ) != 0 ) ;
if ( F_207 ( V_44 == 0 ) ) {
struct V_82 * V_83 ;
struct V_89 * V_90 ;
F_136 ( V_62 ) ;
V_83 = & F_230 ( V_23 -> V_179 ) -> V_83 ;
V_90 = & V_83 -> V_91 [ V_3 ] ;
if ( F_92 ( V_90 ) ) {
V_83 -> V_81 += F_206 ( V_23 , 0 ,
V_83 -> V_175 , V_90 ,
V_3 , V_171 ) ;
if ( F_16 ( F_92 ( V_90 ) ) )
goto V_193;
}
if ( V_171 )
V_1 = F_93 ( V_90 , struct V_1 , V_63 ) ;
else
V_1 = F_202 ( V_90 , struct V_1 , V_63 ) ;
F_81 ( & V_1 -> V_63 ) ;
V_83 -> V_81 -- ;
} else {
if ( F_16 ( V_139 & V_194 ) ) {
F_244 ( V_44 > 1 ) ;
}
F_196 ( & V_23 -> V_87 , V_62 ) ;
V_1 = NULL ;
if ( V_140 & V_195 ) {
V_1 = F_183 ( V_23 , V_44 , V_164 ) ;
if ( V_1 )
F_205 ( V_1 , V_44 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_204 ( V_23 , V_44 , V_3 ) ;
F_97 ( & V_23 -> V_87 ) ;
if ( ! V_1 )
goto V_193;
F_61 ( V_23 , - ( 1 << V_44 ) ,
F_1 ( V_1 ) ) ;
}
F_91 ( V_23 , V_196 , - ( 1 << V_44 ) ) ;
if ( F_245 ( & V_23 -> V_197 [ V_196 ] ) <= 0 &&
! F_246 ( V_198 , & V_23 -> V_62 ) )
F_247 ( V_198 , & V_23 -> V_62 ) ;
F_248 ( V_199 , V_23 , 1 << V_44 ) ;
F_249 ( V_191 , V_23 , V_139 ) ;
F_138 ( V_62 ) ;
F_73 ( F_28 ( V_23 , V_1 ) , V_1 ) ;
return V_1 ;
V_193:
F_138 ( V_62 ) ;
return NULL ;
}
static int T_3 F_250 ( char * V_200 )
{
return F_251 ( & V_201 . V_202 , V_200 ) ;
}
static bool F_252 ( T_4 V_186 , unsigned int V_44 )
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
return F_253 ( & V_201 . V_202 , 1 << V_44 ) ;
}
static int T_3 F_254 ( void )
{
T_6 V_208 = V_209 | V_210 | V_211 ;
struct V_212 * V_213 ;
V_213 = F_255 ( L_20 , NULL ,
& V_201 . V_202 ) ;
if ( F_256 ( V_213 ) )
return F_257 ( V_213 ) ;
if ( ! F_258 ( L_21 , V_208 , V_213 ,
& V_201 . V_206 ) )
goto V_214;
if ( ! F_258 ( L_22 , V_208 , V_213 ,
& V_201 . V_204 ) )
goto V_214;
if ( ! F_259 ( L_23 , V_208 , V_213 ,
& V_201 . V_203 ) )
goto V_214;
return 0 ;
V_214:
F_260 ( V_213 ) ;
return - V_215 ;
}
static inline bool F_252 ( T_4 V_186 , unsigned int V_44 )
{
return false ;
}
static bool F_261 ( struct V_23 * V_169 , unsigned int V_44 ,
unsigned long V_216 , int V_217 , int V_140 ,
long V_218 )
{
long F_159 = V_216 ;
int V_219 ;
const int V_220 = ( V_140 & V_195 ) ;
V_218 -= ( 1 << V_44 ) - 1 ;
if ( V_140 & V_221 )
F_159 -= F_159 / 2 ;
if ( F_207 ( ! V_220 ) )
V_218 -= V_169 -> V_162 ;
else
F_159 -= F_159 / 4 ;
#ifdef F_262
if ( ! ( V_140 & V_222 ) )
V_218 -= F_90 ( V_169 , V_172 ) ;
#endif
if ( V_218 <= F_159 + V_169 -> V_223 [ V_217 ] )
return false ;
if ( ! V_44 )
return true ;
for ( V_219 = V_44 ; V_219 < V_56 ; V_219 ++ ) {
struct V_71 * V_135 = & V_169 -> V_71 [ V_219 ] ;
int V_92 ;
if ( ! V_135 -> V_72 )
continue;
if ( V_220 )
return true ;
for ( V_92 = 0 ; V_92 < V_19 ; V_92 ++ ) {
if ( ! F_92 ( & V_135 -> V_75 [ V_92 ] ) )
return true ;
}
#ifdef F_262
if ( ( V_140 & V_222 ) &&
! F_92 ( & V_135 -> V_75 [ V_131 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_241 ( struct V_23 * V_169 , unsigned int V_44 , unsigned long V_216 ,
int V_217 , int V_140 )
{
return F_261 ( V_169 , V_44 , V_216 , V_217 , V_140 ,
F_90 ( V_169 , V_173 ) ) ;
}
bool F_263 ( struct V_23 * V_169 , unsigned int V_44 ,
unsigned long V_216 , int V_217 )
{
long V_218 = F_90 ( V_169 , V_173 ) ;
if ( V_169 -> V_224 && V_218 < V_169 -> V_224 )
V_218 = F_264 ( V_169 , V_173 ) ;
return F_261 ( V_169 , V_44 , V_216 , V_217 , 0 ,
V_218 ) ;
}
static bool F_265 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return V_225 -> V_110 == V_23 -> V_110 ;
}
static bool F_266 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return F_267 ( F_24 ( V_225 ) , F_24 ( V_23 ) ) <
V_226 ;
}
static bool F_265 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return true ;
}
static bool F_266 ( struct V_23 * V_225 , struct V_23 * V_23 )
{
return true ;
}
static void F_268 ( struct V_23 * V_191 )
{
struct V_23 * V_23 = V_191 -> V_227 -> V_98 ;
do {
F_269 ( V_23 , V_196 ,
F_270 ( V_23 ) - F_240 ( V_23 ) -
F_245 ( & V_23 -> V_197 [ V_196 ] ) ) ;
F_271 ( V_198 , & V_23 -> V_62 ) ;
} while ( V_23 ++ != V_191 );
}
static struct V_1 *
F_272 ( T_4 V_186 , unsigned int V_44 , int V_140 ,
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
F_200 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_216 ;
if ( F_273 () &&
( V_140 & V_231 ) &&
! F_274 ( V_23 , V_186 ) )
continue;
if ( V_140 & V_232 ) {
if ( ! F_265 ( V_166 -> V_191 , V_23 ) )
break;
if ( F_246 ( V_198 , & V_23 -> V_62 ) ) {
V_228 ++ ;
continue;
}
}
if ( V_166 -> V_233 && ! F_275 ( V_23 ) )
continue;
V_216 = V_23 -> V_188 [ V_140 & V_234 ] ;
if ( ! F_241 ( V_23 , V_44 , V_216 ,
V_166 -> V_217 , V_140 ) ) {
int V_24 ;
F_101 ( V_143 < V_235 ) ;
if ( V_140 & V_143 )
goto V_236;
if ( V_237 == 0 ||
! F_266 ( V_166 -> V_191 , V_23 ) )
continue;
V_24 = F_276 ( V_23 , V_186 , V_44 ) ;
switch ( V_24 ) {
case V_238 :
continue;
case V_239 :
continue;
default:
if ( F_241 ( V_23 , V_44 , V_216 ,
V_166 -> V_217 , V_140 ) )
goto V_236;
continue;
}
}
V_236:
V_1 = F_243 ( V_166 -> V_191 , V_23 , V_44 ,
V_186 , V_140 , V_166 -> V_3 ) ;
if ( V_1 ) {
if ( F_176 ( V_1 , V_44 , V_186 , V_140 ) )
goto V_236;
if ( F_16 ( V_44 && ( V_140 & V_195 ) ) )
F_195 ( V_1 , V_23 , V_44 ) ;
return V_1 ;
}
}
if ( V_140 & V_232 ) {
V_140 &= ~ V_232 ;
if ( V_228 ) {
V_229 = true ;
F_268 ( V_166 -> V_191 ) ;
}
if ( V_240 > 1 )
V_229 = true ;
}
if ( V_229 )
goto V_230;
return NULL ;
}
static inline bool F_277 ( void )
{
bool V_24 = false ;
#if V_241 > 8
V_24 = F_278 () ;
#endif
return V_24 ;
}
void F_279 ( T_4 V_186 , unsigned int V_44 , const char * V_242 , ... )
{
unsigned int V_243 = V_244 ;
if ( ( V_186 & V_245 ) || ! F_280 ( & V_246 ) ||
F_174 () > 0 )
return;
if ( ! ( V_186 & V_247 ) )
if ( F_281 ( V_248 ) ||
( V_40 -> V_62 & ( V_249 | V_250 ) ) )
V_243 &= ~ V_244 ;
if ( F_278 () || ! ( V_186 & V_207 ) )
V_243 &= ~ V_244 ;
if ( V_242 ) {
struct V_251 V_252 ;
T_7 args ;
va_start ( args , V_242 ) ;
V_252 . V_242 = V_242 ;
V_252 . V_253 = & args ;
F_282 ( L_24 , & V_252 ) ;
va_end ( args ) ;
}
F_282 ( L_25 ,
V_40 -> V_41 , V_44 , V_186 ) ;
F_36 () ;
if ( ! F_277 () )
F_283 ( V_243 ) ;
}
static inline struct V_1 *
F_284 ( T_4 V_186 , unsigned int V_44 ,
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
if ( ! F_285 ( & V_258 ) ) {
* V_254 = 1 ;
F_286 ( 1 ) ;
return NULL ;
}
V_1 = F_272 ( V_186 | V_259 , V_44 ,
V_260 | V_231 , V_166 ) ;
if ( V_1 )
goto V_37;
if ( ! ( V_186 & V_194 ) ) {
if ( V_40 -> V_62 & V_261 )
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
if ( F_287 ( & V_256 ) || F_244 ( V_186 & V_194 ) ) {
* V_254 = 1 ;
if ( V_186 & V_194 ) {
V_1 = F_272 ( V_186 , V_44 ,
V_143 | V_231 , V_166 ) ;
if ( ! V_1 )
V_1 = F_272 ( V_186 , V_44 ,
V_143 , V_166 ) ;
}
}
V_37:
F_288 ( & V_258 ) ;
return V_1 ;
}
static struct V_1 *
F_289 ( T_4 V_186 , unsigned int V_44 ,
int V_140 , const struct V_165 * V_166 ,
enum V_266 V_208 , int * V_267 ,
bool * V_268 )
{
unsigned long V_269 ;
struct V_1 * V_1 ;
if ( ! V_44 )
return NULL ;
V_40 -> V_62 |= V_249 ;
V_269 = F_290 ( V_186 , V_44 , V_140 , V_166 ,
V_208 , V_267 ) ;
V_40 -> V_62 &= ~ V_249 ;
switch ( V_269 ) {
case V_270 :
* V_268 = true ;
case V_271 :
return NULL ;
default:
break;
}
F_291 ( V_272 ) ;
V_1 = F_272 ( V_186 , V_44 ,
V_140 & ~ V_143 , V_166 ) ;
if ( V_1 ) {
struct V_23 * V_23 = F_27 ( V_1 ) ;
V_23 -> V_273 = false ;
F_292 ( V_23 , V_44 , true ) ;
F_291 ( V_274 ) ;
return V_1 ;
}
F_291 ( V_275 ) ;
F_160 () ;
return NULL ;
}
static inline struct V_1 *
F_289 ( T_4 V_186 , unsigned int V_44 ,
int V_140 , const struct V_165 * V_166 ,
enum V_266 V_208 , int * V_267 ,
bool * V_268 )
{
return NULL ;
}
static int
F_293 ( T_4 V_186 , unsigned int V_44 ,
const struct V_165 * V_166 )
{
struct V_276 V_276 ;
int V_277 ;
F_160 () ;
F_294 () ;
V_40 -> V_62 |= V_249 ;
F_295 ( V_186 ) ;
V_276 . V_278 = 0 ;
V_40 -> V_276 = & V_276 ;
V_277 = F_296 ( V_166 -> V_167 , V_44 , V_186 ,
V_166 -> V_257 ) ;
V_40 -> V_276 = NULL ;
F_297 () ;
V_40 -> V_62 &= ~ V_249 ;
F_160 () ;
return V_277 ;
}
static inline struct V_1 *
F_298 ( T_4 V_186 , unsigned int V_44 ,
int V_140 , const struct V_165 * V_166 ,
unsigned long * V_254 )
{
struct V_1 * V_1 = NULL ;
bool V_279 = false ;
* V_254 = F_293 ( V_186 , V_44 , V_166 ) ;
if ( F_16 ( ! ( * V_254 ) ) )
return NULL ;
V_280:
V_1 = F_272 ( V_186 , V_44 ,
V_140 & ~ V_143 , V_166 ) ;
if ( ! V_1 && ! V_279 ) {
F_199 ( V_166 ) ;
F_216 ( NULL ) ;
V_279 = true ;
goto V_280;
}
return V_1 ;
}
static void F_299 ( unsigned int V_44 , const struct V_165 * V_166 )
{
struct V_168 * V_169 ;
struct V_23 * V_23 ;
F_200 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_300 ( V_23 , V_44 , F_301 ( V_166 -> V_191 ) ) ;
}
static inline int
F_302 ( T_4 V_186 )
{
int V_140 = V_281 | V_231 ;
F_101 ( V_282 != ( V_283 T_4 ) V_221 ) ;
V_140 |= ( V_283 int ) ( V_186 & V_282 ) ;
if ( V_186 & V_284 ) {
if ( ! ( V_186 & V_247 ) )
V_140 |= V_195 ;
V_140 &= ~ V_231 ;
} else if ( F_16 ( F_303 ( V_40 ) ) && ! F_278 () )
V_140 |= V_195 ;
if ( F_207 ( ! ( V_186 & V_247 ) ) ) {
if ( V_186 & V_285 )
V_140 |= V_143 ;
else if ( F_304 () && ( V_40 -> V_62 & V_249 ) )
V_140 |= V_143 ;
else if ( ! F_278 () &&
( ( V_40 -> V_62 & V_249 ) ||
F_16 ( F_281 ( V_248 ) ) ) )
V_140 |= V_143 ;
}
#ifdef F_262
if ( F_305 ( V_186 ) == V_114 )
V_140 |= V_222 ;
#endif
return V_140 ;
}
bool F_306 ( T_4 V_186 )
{
return ! ! ( F_302 ( V_186 ) & V_143 ) ;
}
static inline bool F_307 ( T_4 V_186 )
{
return ( V_186 & ( V_286 | V_287 ) ) == V_286 ;
}
static inline struct V_1 *
F_308 ( T_4 V_186 , unsigned int V_44 ,
struct V_165 * V_166 )
{
bool V_288 = V_186 & V_207 ;
struct V_1 * V_1 = NULL ;
int V_140 ;
unsigned long V_289 = 0 ;
unsigned long V_254 ;
enum V_266 V_290 = V_291 ;
bool V_268 = false ;
int V_267 = V_292 ;
if ( V_44 >= V_56 ) {
F_244 ( ! ( V_186 & V_245 ) ) ;
return NULL ;
}
if ( F_244 ( ( V_186 & ( V_284 | V_207 ) ) ==
( V_284 | V_207 ) ) )
V_186 &= ~ V_284 ;
if ( F_102 ( V_293 ) && ( V_186 & V_265 ) && ! V_288 )
goto V_294;
V_280:
if ( V_186 & V_287 )
F_299 ( V_44 , V_166 ) ;
V_140 = F_302 ( V_186 ) ;
if ( ! ( V_140 & V_231 ) && ! V_166 -> V_257 ) {
struct V_168 * V_295 ;
V_295 = F_309 ( V_166 -> V_167 ,
V_166 -> V_263 , NULL , & V_166 -> V_191 ) ;
V_166 -> V_217 = F_310 ( V_295 ) ;
}
V_1 = F_272 ( V_186 , V_44 ,
V_140 & ~ V_143 , V_166 ) ;
if ( V_1 )
goto V_296;
if ( V_140 & V_143 ) {
V_166 -> V_167 = F_311 ( F_312 () , V_186 ) ;
V_1 = F_272 ( V_186 , V_44 ,
V_143 , V_166 ) ;
if ( V_1 )
goto V_296;
}
if ( ! V_288 ) {
F_244 ( V_186 & V_194 ) ;
goto V_294;
}
if ( V_40 -> V_62 & V_249 ) {
if ( F_244 ( V_186 & V_194 ) ) {
F_160 () ;
goto V_280;
}
goto V_294;
}
if ( F_281 ( V_248 ) && ! ( V_186 & V_194 ) )
goto V_294;
V_1 = F_289 ( V_186 , V_44 , V_140 , V_166 ,
V_290 ,
& V_267 ,
& V_268 ) ;
if ( V_1 )
goto V_296;
if ( F_307 ( V_186 ) ) {
if ( V_268 )
goto V_294;
if ( V_267 == V_297 )
goto V_294;
if ( V_267 == V_298
&& ! ( V_40 -> V_62 & V_299 ) )
goto V_294;
}
if ( ! F_307 ( V_186 ) || ( V_40 -> V_62 & V_299 ) )
V_290 = V_300 ;
V_1 = F_298 ( V_186 , V_44 , V_140 , V_166 ,
& V_254 ) ;
if ( V_1 )
goto V_296;
if ( V_186 & V_301 )
goto V_302;
V_289 += V_254 ;
if ( ( V_254 && V_44 <= V_262 ) ||
( ( V_186 & V_303 ) && V_289 < ( 1 << V_44 ) ) ) {
F_313 ( V_166 -> V_191 , V_304 , V_39 / 50 ) ;
goto V_280;
}
V_1 = F_284 ( V_186 , V_44 , V_166 , & V_254 ) ;
if ( V_1 )
goto V_296;
if ( V_254 )
goto V_280;
V_302:
V_1 = F_289 ( V_186 , V_44 , V_140 ,
V_166 , V_290 ,
& V_267 ,
& V_268 ) ;
if ( V_1 )
goto V_296;
V_294:
F_279 ( V_186 , V_44 , NULL ) ;
V_296:
return V_1 ;
}
struct V_1 *
F_314 ( T_4 V_186 , unsigned int V_44 ,
struct V_167 * V_167 , T_8 * V_257 )
{
struct V_168 * V_295 ;
struct V_1 * V_1 = NULL ;
unsigned int V_305 ;
int V_140 = V_306 | V_231 | V_232 ;
T_4 V_307 ;
struct V_165 V_166 = {
. V_263 = F_315 ( V_186 ) ,
. V_257 = V_257 ,
. V_3 = F_305 ( V_186 ) ,
} ;
V_186 &= V_6 ;
F_316 ( V_186 ) ;
F_317 ( V_186 & V_207 ) ;
if ( F_252 ( V_186 , V_44 ) )
return NULL ;
if ( F_16 ( ! V_167 -> V_308 -> V_23 ) )
return NULL ;
if ( F_102 ( F_262 ) && V_166 . V_3 == V_114 )
V_140 |= V_222 ;
V_309:
V_305 = F_318 () ;
V_166 . V_167 = V_167 ;
V_166 . V_233 = ( V_186 & V_310 ) ;
V_295 = F_309 ( V_166 . V_167 , V_166 . V_263 ,
V_166 . V_257 ? : & V_311 ,
& V_166 . V_191 ) ;
if ( ! V_166 . V_191 )
goto V_37;
V_166 . V_217 = F_310 ( V_295 ) ;
V_307 = V_186 | V_259 ;
V_1 = F_272 ( V_307 , V_44 , V_140 , & V_166 ) ;
if ( F_16 ( ! V_1 ) ) {
V_307 = F_319 ( V_186 ) ;
V_166 . V_233 = false ;
V_1 = F_308 ( V_307 , V_44 , & V_166 ) ;
}
if ( V_312 && V_1 )
F_320 ( V_1 , V_44 , V_186 ) ;
F_321 ( V_1 , V_44 , V_307 , V_166 . V_3 ) ;
V_37:
if ( F_16 ( ! V_1 && F_322 ( V_305 ) ) )
goto V_309;
return V_1 ;
}
unsigned long F_323 ( T_4 V_186 , unsigned int V_44 )
{
struct V_1 * V_1 ;
F_77 ( ( V_186 & V_205 ) != 0 ) ;
V_1 = F_324 ( V_186 , V_44 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_132 ( V_1 ) ;
}
unsigned long F_325 ( T_4 V_186 )
{
return F_323 ( V_186 | V_141 , 0 ) ;
}
void F_143 ( struct V_1 * V_1 , unsigned int V_44 )
{
if ( F_326 ( V_1 ) ) {
if ( V_44 == 0 )
F_228 ( V_1 , false ) ;
else
F_39 ( V_1 , V_44 ) ;
}
}
void V_218 ( unsigned long V_313 , unsigned int V_44 )
{
if ( V_313 != 0 ) {
F_77 ( ! F_327 ( ( void * ) V_313 ) ) ;
F_143 ( F_237 ( ( void * ) V_313 ) , V_44 ) ;
}
}
static struct V_1 * F_328 ( struct V_314 * V_315 ,
T_4 V_186 )
{
struct V_1 * V_1 = NULL ;
T_4 V_316 = V_186 ;
#if ( V_104 < V_317 )
V_186 |= V_142 | V_245 | V_301 |
V_247 ;
V_1 = F_329 ( V_318 , V_186 ,
V_319 ) ;
V_315 -> V_136 = V_1 ? V_317 : V_104 ;
#endif
if ( F_16 ( ! V_1 ) )
V_1 = F_329 ( V_318 , V_316 , 0 ) ;
V_315 -> V_253 = V_1 ? F_132 ( V_1 ) : NULL ;
return V_1 ;
}
void * F_330 ( struct V_314 * V_315 ,
unsigned int V_320 , T_4 V_186 )
{
unsigned int V_136 = V_104 ;
struct V_1 * V_1 ;
int V_321 ;
if ( F_16 ( ! V_315 -> V_253 ) ) {
V_322:
V_1 = F_328 ( V_315 , V_186 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_104 < V_317 )
V_136 = V_315 -> V_136 ;
#endif
F_331 ( V_136 - 1 , & V_1 -> V_78 ) ;
V_315 -> V_323 = F_332 ( V_1 ) ;
V_315 -> V_324 = V_136 ;
V_315 -> V_321 = V_136 ;
}
V_321 = V_315 -> V_321 - V_320 ;
if ( F_16 ( V_321 < 0 ) ) {
V_1 = F_237 ( V_315 -> V_253 ) ;
if ( ! F_333 ( V_315 -> V_324 , & V_1 -> V_78 ) )
goto V_322;
#if ( V_104 < V_317 )
V_136 = V_315 -> V_136 ;
#endif
F_47 ( & V_1 -> V_78 , V_136 ) ;
V_315 -> V_324 = V_136 ;
V_321 = V_136 - V_320 ;
}
V_315 -> V_324 -- ;
V_315 -> V_321 = V_321 ;
return V_315 -> V_253 + V_321 ;
}
void F_334 ( void * V_313 )
{
struct V_1 * V_1 = F_335 ( V_313 ) ;
if ( F_16 ( F_326 ( V_1 ) ) )
F_39 ( V_1 , F_40 ( V_1 ) ) ;
}
struct V_1 * F_336 ( T_4 V_186 , unsigned int V_44 )
{
struct V_1 * V_1 ;
V_1 = F_324 ( V_186 , V_44 ) ;
if ( V_1 && F_337 ( V_1 , V_186 , V_44 ) != 0 ) {
F_143 ( V_1 , V_44 ) ;
V_1 = NULL ;
}
return V_1 ;
}
struct V_1 * F_338 ( int V_13 , T_4 V_186 , unsigned int V_44 )
{
struct V_1 * V_1 ;
V_1 = F_329 ( V_13 , V_186 , V_44 ) ;
if ( V_1 && F_337 ( V_1 , V_186 , V_44 ) != 0 ) {
F_143 ( V_1 , V_44 ) ;
V_1 = NULL ;
}
return V_1 ;
}
void F_339 ( struct V_1 * V_1 , unsigned int V_44 )
{
F_340 ( V_1 , V_44 ) ;
F_143 ( V_1 , V_44 ) ;
}
void F_341 ( unsigned long V_313 , unsigned int V_44 )
{
if ( V_313 != 0 ) {
F_77 ( ! F_327 ( ( void * ) V_313 ) ) ;
F_339 ( F_237 ( ( void * ) V_313 ) , V_44 ) ;
}
}
static void * F_342 ( unsigned long V_313 , unsigned int V_44 ,
T_9 V_136 )
{
if ( V_313 ) {
unsigned long V_325 = V_313 + ( V_104 << V_44 ) ;
unsigned long V_326 = V_313 + F_343 ( V_136 ) ;
F_234 ( F_237 ( ( void * ) V_313 ) , V_44 ) ;
while ( V_326 < V_325 ) {
F_344 ( V_326 ) ;
V_326 += V_104 ;
}
}
return ( void * ) V_313 ;
}
void * F_345 ( T_9 V_136 , T_4 V_186 )
{
unsigned int V_44 = F_346 ( V_136 ) ;
unsigned long V_313 ;
V_313 = F_323 ( V_186 , V_44 ) ;
return F_342 ( V_313 , V_44 , V_136 ) ;
}
void * T_2 F_347 ( int V_13 , T_9 V_136 , T_4 V_186 )
{
unsigned int V_44 = F_346 ( V_136 ) ;
struct V_1 * V_48 = F_329 ( V_13 , V_186 , V_44 ) ;
if ( ! V_48 )
return NULL ;
return F_342 ( ( unsigned long ) F_132 ( V_48 ) , V_44 , V_136 ) ;
}
void F_348 ( void * V_327 , T_9 V_136 )
{
unsigned long V_313 = ( unsigned long ) V_327 ;
unsigned long V_100 = V_313 + F_343 ( V_136 ) ;
while ( V_313 < V_100 ) {
F_344 ( V_313 ) ;
V_313 += V_104 ;
}
}
static unsigned long F_349 ( int V_321 )
{
struct V_168 * V_169 ;
struct V_23 * V_23 ;
unsigned long V_328 = 0 ;
struct V_167 * V_167 = F_311 ( F_312 () , V_329 ) ;
F_350 (zone, z, zonelist, offset) {
unsigned long V_136 = V_23 -> V_107 ;
unsigned long V_134 = F_270 ( V_23 ) ;
if ( V_136 > V_134 )
V_328 += V_136 - V_134 ;
}
return V_328 ;
}
unsigned long F_351 ( void )
{
return F_349 ( F_315 ( V_330 ) ) ;
}
unsigned long F_352 ( void )
{
return F_349 ( F_315 ( V_331 ) ) ;
}
static inline void F_353 ( struct V_23 * V_23 )
{
if ( F_102 ( V_293 ) )
F_33 ( L_26 , F_24 ( V_23 ) ) ;
}
void F_354 ( struct V_332 * V_333 )
{
V_333 -> V_334 = V_335 ;
V_333 -> V_336 = F_355 ( V_337 ) ;
V_333 -> V_338 = F_355 ( V_173 ) ;
V_333 -> V_339 = F_356 () ;
V_333 -> V_340 = V_341 ;
V_333 -> V_342 = F_357 () ;
V_333 -> V_343 = V_104 ;
}
void F_358 ( struct V_332 * V_333 , int V_13 )
{
int V_344 ;
unsigned long V_107 = 0 ;
T_1 * V_9 = F_10 ( V_13 ) ;
for ( V_344 = 0 ; V_344 < V_97 ; V_344 ++ )
V_107 += V_9 -> V_98 [ V_344 ] . V_107 ;
V_333 -> V_334 = V_107 ;
V_333 -> V_336 = F_359 ( V_13 , V_337 ) ;
V_333 -> V_338 = F_359 ( V_13 , V_173 ) ;
#ifdef F_360
V_333 -> V_340 = V_9 -> V_98 [ V_345 ] . V_107 ;
V_333 -> V_342 = F_90 ( & V_9 -> V_98 [ V_345 ] ,
V_173 ) ;
#else
V_333 -> V_340 = 0 ;
V_333 -> V_342 = 0 ;
#endif
V_333 -> V_343 = V_104 ;
}
bool F_361 ( unsigned int V_62 , int V_13 )
{
bool V_24 = false ;
unsigned int V_305 ;
if ( ! ( V_62 & V_244 ) )
goto V_37;
do {
V_305 = F_318 () ;
V_24 = ! F_362 ( V_13 , V_311 ) ;
} while ( F_322 ( V_305 ) );
V_37:
return V_24 ;
}
static void F_363 ( unsigned char type )
{
static const char V_346 [ V_159 ] = {
[ V_20 ] = 'U' ,
[ V_114 ] = 'M' ,
[ V_152 ] = 'E' ,
[ V_164 ] = 'H' ,
#ifdef F_262
[ V_131 ] = 'C' ,
#endif
#ifdef F_364
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
F_33 ( L_27 , V_348 ) ;
}
void F_365 ( unsigned int V_243 )
{
unsigned long V_349 = 0 ;
int V_176 ;
struct V_23 * V_23 ;
F_213 (zone) {
if ( F_361 ( V_243 , F_24 ( V_23 ) ) )
continue;
F_217 (cpu)
V_349 += F_211 ( V_23 -> V_179 , V_176 ) -> V_83 . V_81 ;
}
F_33 ( L_28
L_29
L_30
L_31
L_32
L_33 ,
F_355 ( V_350 ) ,
F_355 ( V_351 ) ,
F_355 ( V_352 ) ,
F_355 ( V_353 ) ,
F_355 ( V_354 ) ,
F_355 ( V_355 ) ,
F_355 ( V_356 ) ,
F_355 ( V_357 ) ,
F_355 ( V_358 ) ,
F_355 ( V_359 ) ,
F_355 ( V_360 ) ,
F_355 ( V_361 ) ,
F_355 ( V_362 ) ,
F_355 ( V_337 ) ,
F_355 ( V_363 ) ,
F_355 ( V_364 ) ,
F_355 ( V_173 ) ,
V_349 ,
F_355 ( V_172 ) ) ;
F_213 (zone) {
int V_45 ;
if ( F_361 ( V_243 , F_24 ( V_23 ) ) )
continue;
V_349 = 0 ;
F_217 (cpu)
V_349 += F_211 ( V_23 -> V_179 , V_176 ) -> V_83 . V_81 ;
F_353 ( V_23 ) ;
F_33 ( L_34
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
L_63
L_64
L_65 ,
V_23 -> V_30 ,
F_366 ( F_90 ( V_23 , V_173 ) ) ,
F_366 ( F_367 ( V_23 ) ) ,
F_366 ( F_240 ( V_23 ) ) ,
F_366 ( F_270 ( V_23 ) ) ,
F_366 ( F_90 ( V_23 , V_350 ) ) ,
F_366 ( F_90 ( V_23 , V_351 ) ) ,
F_366 ( F_90 ( V_23 , V_353 ) ) ,
F_366 ( F_90 ( V_23 , V_354 ) ) ,
F_366 ( F_90 ( V_23 , V_356 ) ) ,
F_366 ( F_90 ( V_23 , V_352 ) ) ,
F_366 ( F_90 ( V_23 , V_355 ) ) ,
F_366 ( V_23 -> V_365 ) ,
F_366 ( V_23 -> V_107 ) ,
F_366 ( F_90 ( V_23 , V_366 ) ) ,
F_366 ( F_90 ( V_23 , V_357 ) ) ,
F_366 ( F_90 ( V_23 , V_358 ) ) ,
F_366 ( F_90 ( V_23 , V_362 ) ) ,
F_366 ( F_90 ( V_23 , V_337 ) ) ,
F_366 ( F_90 ( V_23 , V_360 ) ) ,
F_366 ( F_90 ( V_23 , V_361 ) ) ,
F_90 ( V_23 , V_367 ) *
V_368 / 1024 ,
F_366 ( F_90 ( V_23 , V_363 ) ) ,
F_366 ( F_90 ( V_23 , V_359 ) ) ,
F_366 ( F_90 ( V_23 , V_364 ) ) ,
F_366 ( V_349 ) ,
F_366 ( F_368 ( V_23 -> V_179 -> V_83 . V_81 ) ) ,
F_366 ( F_90 ( V_23 , V_172 ) ) ,
F_366 ( F_90 ( V_23 , V_369 ) ) ,
F_366 ( F_90 ( V_23 , V_88 ) ) ,
( ! F_369 ( V_23 ) ? L_66 : L_67 )
) ;
F_33 ( L_68 ) ;
for ( V_45 = 0 ; V_45 < V_97 ; V_45 ++ )
F_33 ( L_69 , V_23 -> V_223 [ V_45 ] ) ;
F_33 ( L_65 ) ;
}
F_213 (zone) {
unsigned int V_44 ;
unsigned long V_370 [ V_56 ] , V_62 , V_371 = 0 ;
unsigned char V_346 [ V_56 ] ;
if ( F_361 ( V_243 , F_24 ( V_23 ) ) )
continue;
F_353 ( V_23 ) ;
F_33 ( L_70 , V_23 -> V_30 ) ;
F_196 ( & V_23 -> V_87 , V_62 ) ;
for ( V_44 = 0 ; V_44 < V_56 ; V_44 ++ ) {
struct V_71 * V_135 = & V_23 -> V_71 [ V_44 ] ;
int type ;
V_370 [ V_44 ] = V_135 -> V_72 ;
V_371 += V_370 [ V_44 ] << V_44 ;
V_346 [ V_44 ] = 0 ;
for ( type = 0 ; type < V_159 ; type ++ ) {
if ( ! F_92 ( & V_135 -> V_75 [ type ] ) )
V_346 [ V_44 ] |= 1 << type ;
}
}
F_198 ( & V_23 -> V_87 , V_62 ) ;
for ( V_44 = 0 ; V_44 < V_56 ; V_44 ++ ) {
F_33 ( L_71 , V_370 [ V_44 ] , F_366 ( 1UL ) << V_44 ) ;
if ( V_370 [ V_44 ] )
F_363 ( V_346 [ V_44 ] ) ;
}
F_33 ( L_72 , F_366 ( V_371 ) ) ;
}
F_370 () ;
F_33 ( L_73 , F_355 ( V_372 ) ) ;
F_371 () ;
}
static void F_372 ( struct V_23 * V_23 , struct V_168 * V_168 )
{
V_168 -> V_23 = V_23 ;
V_168 -> F_301 = F_301 ( V_23 ) ;
}
static int F_373 ( T_1 * V_9 , struct V_167 * V_167 ,
int V_373 )
{
struct V_23 * V_23 ;
enum V_344 V_344 = V_97 ;
do {
V_344 -- ;
V_23 = V_9 -> V_98 + V_344 ;
if ( F_162 ( V_23 ) ) {
F_372 ( V_23 ,
& V_167 -> V_308 [ V_373 ++ ] ) ;
F_374 ( V_344 ) ;
}
} while ( V_344 );
return V_373 ;
}
static int F_375 ( char * V_374 )
{
if ( * V_374 == 'd' || * V_374 == 'D' ) {
V_375 = V_376 ;
} else if ( * V_374 == 'n' || * V_374 == 'N' ) {
V_375 = V_377 ;
} else if ( * V_374 == 'z' || * V_374 == 'Z' ) {
V_375 = V_378 ;
} else {
F_33 ( V_379
L_74
L_75 , V_374 ) ;
return - V_52 ;
}
return 0 ;
}
static T_3 int F_376 ( char * V_374 )
{
int V_24 ;
if ( ! V_374 )
return 0 ;
V_24 = F_375 ( V_374 ) ;
if ( V_24 == 0 )
F_377 ( V_380 , V_374 , V_381 ) ;
return V_24 ;
}
int F_378 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 ,
T_11 * V_387 )
{
char V_388 [ V_381 ] ;
int V_24 ;
static F_379 ( V_389 ) ;
F_380 ( & V_389 ) ;
if ( V_384 ) {
if ( strlen ( ( char * ) V_383 -> V_117 ) >= V_381 ) {
V_24 = - V_52 ;
goto V_37;
}
strcpy ( V_388 , ( char * ) V_383 -> V_117 ) ;
}
V_24 = F_381 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_24 )
goto V_37;
if ( V_384 ) {
int V_390 = V_375 ;
V_24 = F_375 ( ( char * ) V_383 -> V_117 ) ;
if ( V_24 ) {
strncpy ( ( char * ) V_383 -> V_117 , V_388 ,
V_381 ) ;
V_375 = V_390 ;
} else if ( V_390 != V_375 ) {
F_380 ( & V_391 ) ;
F_382 ( NULL , NULL ) ;
F_288 ( & V_391 ) ;
}
}
V_37:
F_288 ( & V_389 ) ;
return V_24 ;
}
static int F_383 ( int V_110 , T_8 * V_392 )
{
int V_393 , V_333 ;
int V_394 = V_395 ;
int V_396 = V_318 ;
const struct V_123 * V_348 = F_154 ( 0 ) ;
if ( ! F_362 ( V_110 , * V_392 ) ) {
F_384 ( V_110 , * V_392 ) ;
return V_110 ;
}
F_167 (n, N_MEMORY) {
if ( F_362 ( V_393 , * V_392 ) )
continue;
V_333 = F_267 ( V_110 , V_393 ) ;
V_333 += ( V_393 < V_110 ) ;
V_348 = F_154 ( V_393 ) ;
if ( ! F_155 ( V_348 ) )
V_333 += V_397 ;
V_333 *= ( V_398 * V_399 ) ;
V_333 += V_400 [ V_393 ] ;
if ( V_333 < V_394 ) {
V_394 = V_333 ;
V_396 = V_393 ;
}
}
if ( V_396 >= 0 )
F_384 ( V_396 , * V_392 ) ;
return V_396 ;
}
static void F_385 ( T_1 * V_9 , int V_110 )
{
int V_401 ;
struct V_167 * V_167 ;
V_167 = & V_9 -> V_402 [ 0 ] ;
for ( V_401 = 0 ; V_167 -> V_308 [ V_401 ] . V_23 != NULL ; V_401 ++ )
;
V_401 = F_373 ( F_10 ( V_110 ) , V_167 , V_401 ) ;
V_167 -> V_308 [ V_401 ] . V_23 = NULL ;
V_167 -> V_308 [ V_401 ] . F_301 = 0 ;
}
static void F_386 ( T_1 * V_9 )
{
int V_401 ;
struct V_167 * V_167 ;
V_167 = & V_9 -> V_402 [ 1 ] ;
V_401 = F_373 ( V_9 , V_167 , 0 ) ;
V_167 -> V_308 [ V_401 ] . V_23 = NULL ;
V_167 -> V_308 [ V_401 ] . F_301 = 0 ;
}
static void F_387 ( T_1 * V_9 , int V_403 )
{
int V_404 , V_401 , V_110 ;
int V_344 ;
struct V_23 * V_169 ;
struct V_167 * V_167 ;
V_167 = & V_9 -> V_402 [ 0 ] ;
V_404 = 0 ;
for ( V_344 = V_97 - 1 ; V_344 >= 0 ; V_344 -- ) {
for ( V_401 = 0 ; V_401 < V_403 ; V_401 ++ ) {
V_110 = V_405 [ V_401 ] ;
V_169 = & F_10 ( V_110 ) -> V_98 [ V_344 ] ;
if ( F_162 ( V_169 ) ) {
F_372 ( V_169 ,
& V_167 -> V_308 [ V_404 ++ ] ) ;
F_374 ( V_344 ) ;
}
}
}
V_167 -> V_308 [ V_404 ] . V_23 = NULL ;
V_167 -> V_308 [ V_404 ] . F_301 = 0 ;
}
static int F_388 ( void )
{
return V_377 ;
}
static int F_388 ( void )
{
return V_378 ;
}
static void F_389 ( void )
{
if ( V_375 == V_376 )
V_406 = F_388 () ;
else
V_406 = V_375 ;
}
static void F_390 ( T_1 * V_9 )
{
int V_45 , V_110 , V_407 ;
T_8 V_408 ;
int V_409 , V_410 ;
struct V_167 * V_167 ;
unsigned int V_44 = V_406 ;
for ( V_45 = 0 ; V_45 < V_411 ; V_45 ++ ) {
V_167 = V_9 -> V_402 + V_45 ;
V_167 -> V_308 [ 0 ] . V_23 = NULL ;
V_167 -> V_308 [ 0 ] . F_301 = 0 ;
}
V_409 = V_9 -> V_118 ;
V_407 = V_240 ;
V_410 = V_409 ;
F_391 ( V_408 ) ;
memset ( V_405 , 0 , sizeof( V_405 ) ) ;
V_45 = 0 ;
while ( ( V_110 = F_383 ( V_409 , & V_408 ) ) >= 0 ) {
if ( F_267 ( V_409 , V_110 ) !=
F_267 ( V_409 , V_410 ) )
V_400 [ V_110 ] = V_407 ;
V_410 = V_110 ;
V_407 -- ;
if ( V_44 == V_377 )
F_385 ( V_9 , V_110 ) ;
else
V_405 [ V_45 ++ ] = V_110 ;
}
if ( V_44 == V_378 ) {
F_387 ( V_9 , V_45 ) ;
}
F_386 ( V_9 ) ;
}
int F_392 ( int V_110 )
{
struct V_23 * V_23 ;
( void ) F_309 ( F_311 ( V_110 , V_329 ) ,
F_315 ( V_329 ) ,
NULL ,
& V_23 ) ;
return V_23 -> V_110 ;
}
static void F_389 ( void )
{
V_406 = V_378 ;
}
static void F_390 ( T_1 * V_9 )
{
int V_110 , V_409 ;
enum V_344 V_401 ;
struct V_167 * V_167 ;
V_409 = V_9 -> V_118 ;
V_167 = & V_9 -> V_402 [ 0 ] ;
V_401 = F_373 ( V_9 , V_167 , 0 ) ;
for ( V_110 = V_409 + 1 ; V_110 < V_399 ; V_110 ++ ) {
if ( ! F_393 ( V_110 ) )
continue;
V_401 = F_373 ( F_10 ( V_110 ) , V_167 , V_401 ) ;
}
for ( V_110 = 0 ; V_110 < V_409 ; V_110 ++ ) {
if ( ! F_393 ( V_110 ) )
continue;
V_401 = F_373 ( F_10 ( V_110 ) , V_167 , V_401 ) ;
}
V_167 -> V_308 [ V_401 ] . V_23 = NULL ;
V_167 -> V_308 [ V_401 ] . F_301 = 0 ;
}
static int F_394 ( void * V_117 )
{
int V_13 ;
int V_176 ;
T_1 * V_412 = V_117 ;
#ifdef V_293
memset ( V_400 , 0 , sizeof( V_400 ) ) ;
#endif
if ( V_412 && ! F_393 ( V_412 -> V_118 ) ) {
F_390 ( V_412 ) ;
}
F_395 (nid) {
T_1 * V_9 = F_10 ( V_13 ) ;
F_390 ( V_9 ) ;
}
F_396 (cpu) {
F_397 ( & F_398 ( V_413 , V_176 ) , 0 ) ;
#ifdef F_399
if ( F_400 ( V_176 ) )
F_401 ( V_176 , F_392 ( F_402 ( V_176 ) ) ) ;
#endif
}
return 0 ;
}
static T_12 void T_3
F_403 ( void )
{
F_394 ( NULL ) ;
F_404 () ;
F_405 () ;
}
void T_13 F_382 ( T_1 * V_9 , struct V_23 * V_23 )
{
F_389 () ;
if ( V_414 == V_415 ) {
F_403 () ;
} else {
#ifdef F_406
if ( V_23 )
F_407 ( V_23 ) ;
#endif
F_408 ( F_394 , V_9 , NULL ) ;
}
V_416 = F_352 () ;
if ( V_416 < ( V_130 * V_159 ) )
V_18 = 1 ;
else
V_18 = 0 ;
F_163 ( L_76
L_77 ,
V_240 ,
V_417 [ V_406 ] ,
V_18 ? L_78 : L_4 ,
V_416 ) ;
#ifdef V_293
F_163 ( L_79 , V_418 [ V_419 ] ) ;
#endif
}
static inline unsigned long F_409 ( unsigned long V_154 )
{
unsigned long V_136 = 1 ;
V_154 /= V_420 ;
while ( V_136 < V_154 )
V_136 <<= 1 ;
V_136 = F_159 ( V_136 , 4096UL ) ;
return F_161 ( V_136 , 4UL ) ;
}
static inline unsigned long F_409 ( unsigned long V_154 )
{
return 4096UL ;
}
static inline unsigned long F_410 ( unsigned long V_136 )
{
return F_411 ( ~ V_136 ) ;
}
void T_2 F_412 ( unsigned long V_136 , int V_13 , unsigned long V_23 ,
unsigned long V_27 , enum V_421 V_422 )
{
struct V_423 * V_424 = F_413 ( F_414 ( V_27 ) ) ;
unsigned long V_101 = V_27 + V_136 ;
T_1 * V_9 = F_10 ( V_13 ) ;
unsigned long V_12 ;
unsigned long V_15 = 0 ;
if ( V_425 < V_101 - 1 )
V_425 = V_101 - 1 ;
if ( V_424 && V_27 == V_424 -> V_426 )
V_27 += V_424 -> V_427 ;
for ( V_12 = V_27 ; V_12 < V_101 ; V_12 ++ ) {
if ( V_422 == V_428 ) {
if ( ! F_415 ( V_12 ) )
continue;
if ( ! F_147 ( V_12 , V_13 ) )
continue;
if ( ! F_13 ( V_9 , V_12 , V_101 ,
& V_15 ) )
break;
}
if ( ! ( V_12 & ( V_130 - 1 ) ) ) {
struct V_1 * V_1 = F_115 ( V_12 ) ;
F_107 ( V_1 , V_12 , V_23 , V_13 ) ;
F_15 ( V_1 , V_114 ) ;
} else {
F_114 ( V_12 , V_23 , V_13 ) ;
}
}
}
static void T_2 F_416 ( struct V_23 * V_23 )
{
unsigned int V_44 , V_184 ;
F_225 (order, t) {
F_59 ( & V_23 -> V_71 [ V_44 ] . V_75 [ V_184 ] ) ;
V_23 -> V_71 [ V_44 ] . V_72 = 0 ;
}
}
static int F_417 ( struct V_23 * V_23 )
{
#ifdef F_418
int V_175 ;
V_175 = V_23 -> V_107 / 1024 ;
if ( V_175 * V_104 > 512 * 1024 )
V_175 = ( 512 * 1024 ) / V_104 ;
V_175 /= 4 ;
if ( V_175 < 1 )
V_175 = 1 ;
V_175 = F_419 ( V_175 + V_175 / 2 ) - 1 ;
return V_175 ;
#else
return 0 ;
#endif
}
static void F_420 ( struct V_82 * V_83 , unsigned long V_134 ,
unsigned long V_175 )
{
V_83 -> V_175 = 1 ;
F_421 () ;
V_83 -> V_134 = V_134 ;
F_421 () ;
V_83 -> V_175 = V_175 ;
}
static void F_422 ( struct V_177 * V_48 , unsigned long V_175 )
{
F_420 ( & V_48 -> V_83 , 6 * V_175 , F_161 ( 1UL , 1 * V_175 ) ) ;
}
static void F_423 ( struct V_177 * V_48 )
{
struct V_82 * V_83 ;
int V_3 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_83 = & V_48 -> V_83 ;
V_83 -> V_81 = 0 ;
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ )
F_59 ( & V_83 -> V_91 [ V_3 ] ) ;
}
static void F_397 ( struct V_177 * V_48 , unsigned long V_175 )
{
F_423 ( V_48 ) ;
F_422 ( V_48 , V_175 ) ;
}
static void F_424 ( struct V_177 * V_48 ,
unsigned long V_134 )
{
unsigned long V_175 = F_161 ( 1UL , V_134 / 4 ) ;
if ( ( V_134 / 4 ) > ( V_16 * 8 ) )
V_175 = V_16 * 8 ;
F_420 ( & V_48 -> V_83 , V_134 , V_175 ) ;
}
static void F_425 ( struct V_23 * V_23 ,
struct V_177 * V_83 )
{
if ( V_429 )
F_424 ( V_83 ,
( V_23 -> V_107 /
V_429 ) ) ;
else
F_422 ( V_83 , F_417 ( V_23 ) ) ;
}
static void T_2 F_426 ( struct V_23 * V_23 , int V_176 )
{
struct V_177 * V_83 = F_211 ( V_23 -> V_179 , V_176 ) ;
F_423 ( V_83 ) ;
F_425 ( V_23 , V_83 ) ;
}
static void T_2 F_407 ( struct V_23 * V_23 )
{
int V_176 ;
V_23 -> V_179 = F_427 ( struct V_177 ) ;
F_396 (cpu)
F_426 ( V_23 , V_176 ) ;
}
void T_3 F_428 ( void )
{
struct V_23 * V_23 ;
F_213 (zone)
F_407 ( V_23 ) ;
}
static T_12 T_14
int F_429 ( struct V_23 * V_23 , unsigned long V_430 )
{
int V_45 ;
T_9 V_431 ;
V_23 -> F_409 =
F_409 ( V_430 ) ;
V_23 -> F_410 =
F_410 ( V_23 -> F_409 ) ;
V_431 = V_23 -> F_409
* sizeof( V_432 ) ;
if ( ! F_430 () ) {
V_23 -> V_433 = ( V_432 * )
F_431 (
V_431 , V_23 -> V_227 -> V_118 ) ;
} else {
V_23 -> V_433 = F_432 ( V_431 ) ;
}
if ( ! V_23 -> V_433 )
return - V_215 ;
for ( V_45 = 0 ; V_45 < V_23 -> F_409 ; ++ V_45 )
F_433 ( V_23 -> V_433 + V_45 ) ;
return 0 ;
}
static T_2 void F_434 ( struct V_23 * V_23 )
{
V_23 -> V_179 = & V_413 ;
if ( F_162 ( V_23 ) )
F_33 ( V_434 L_80 ,
V_23 -> V_30 , V_23 -> V_365 ,
F_417 ( V_23 ) ) ;
}
int T_2 F_435 ( struct V_23 * V_23 ,
unsigned long V_28 ,
unsigned long V_136 )
{
struct V_435 * V_9 = V_23 -> V_227 ;
int V_24 ;
V_24 = F_429 ( V_23 , V_136 ) ;
if ( V_24 )
return V_24 ;
V_9 -> V_373 = F_301 ( V_23 ) + 1 ;
V_23 -> V_28 = V_28 ;
F_436 ( V_436 , L_81 ,
L_82 ,
V_9 -> V_118 ,
( unsigned long ) F_301 ( V_23 ) ,
V_28 , ( V_28 + V_136 ) ) ;
F_416 ( V_23 ) ;
return 0 ;
}
int T_2 F_145 ( unsigned long V_12 ,
struct V_111 * V_112 )
{
unsigned long V_27 , V_101 ;
int V_13 ;
if ( V_112 -> V_437 <= V_12 && V_12 < V_112 -> V_438 )
return V_112 -> V_439 ;
V_13 = F_437 ( V_12 , & V_27 , & V_101 ) ;
if ( V_13 != - 1 ) {
V_112 -> V_437 = V_27 ;
V_112 -> V_438 = V_101 ;
V_112 -> V_439 = V_13 ;
}
return V_13 ;
}
void T_3 F_438 ( int V_13 , unsigned long V_440 )
{
unsigned long V_27 , V_101 ;
int V_45 , V_441 ;
F_158 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_27 = F_159 ( V_27 , V_440 ) ;
V_101 = F_159 ( V_101 , V_440 ) ;
if ( V_27 < V_101 )
F_439 ( F_440 ( V_27 ) ,
( V_101 - V_27 ) << V_16 ,
V_441 ) ;
}
}
void T_3 F_441 ( int V_13 )
{
unsigned long V_27 , V_101 ;
int V_45 , V_441 ;
F_158 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_442 ( V_441 , V_27 , V_101 ) ;
}
void T_2 F_443 ( unsigned int V_13 ,
unsigned long * V_27 , unsigned long * V_101 )
{
unsigned long V_442 , V_443 ;
int V_45 ;
* V_27 = - 1UL ;
* V_101 = 0 ;
F_158 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_27 = F_159 ( * V_27 , V_442 ) ;
* V_101 = F_161 ( * V_101 , V_443 ) ;
}
if ( * V_27 == - 1UL )
* V_27 = 0 ;
}
static void T_3 F_444 ( void )
{
int V_444 ;
for ( V_444 = V_97 - 1 ; V_444 >= 0 ; V_444 -- ) {
if ( V_444 == V_445 )
continue;
if ( V_446 [ V_444 ] >
V_447 [ V_444 ] )
break;
}
F_77 ( V_444 == - 1 ) ;
V_448 = V_444 ;
}
static void T_2 F_445 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_124 ,
unsigned long V_449 ,
unsigned long * V_28 ,
unsigned long * F_117 )
{
if ( V_450 [ V_13 ] ) {
if ( V_344 == V_445 ) {
* V_28 = V_450 [ V_13 ] ;
* F_117 = F_159 ( V_449 ,
V_446 [ V_448 ] ) ;
} else if ( * V_28 < V_450 [ V_13 ] &&
* F_117 > V_450 [ V_13 ] ) {
* F_117 = V_450 [ V_13 ] ;
} else if ( * V_28 >= V_450 [ V_13 ] )
* V_28 = * F_117 ;
}
}
static unsigned long T_2 F_446 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_124 ,
unsigned long V_449 ,
unsigned long * V_451 )
{
unsigned long V_28 , F_117 ;
if ( ! V_124 && ! V_449 )
return 0 ;
V_28 = V_447 [ V_344 ] ;
F_117 = V_446 [ V_344 ] ;
F_445 ( V_13 , V_344 ,
V_124 , V_449 ,
& V_28 , & F_117 ) ;
if ( F_117 < V_124 || V_28 > V_449 )
return 0 ;
F_117 = F_159 ( F_117 , V_449 ) ;
V_28 = F_161 ( V_28 , V_124 ) ;
return F_117 - V_28 ;
}
unsigned long T_2 F_447 ( int V_13 ,
unsigned long V_452 ,
unsigned long V_453 )
{
unsigned long V_454 = V_453 - V_452 ;
unsigned long V_27 , V_101 ;
int V_45 ;
F_158 (i, nid, &start_pfn, &end_pfn, NULL) {
V_27 = F_448 ( V_27 , V_452 , V_453 ) ;
V_101 = F_448 ( V_101 , V_452 , V_453 ) ;
V_454 -= V_101 - V_27 ;
}
return V_454 ;
}
unsigned long T_3 F_449 ( unsigned long V_27 ,
unsigned long V_101 )
{
return F_447 ( V_399 , V_27 , V_101 ) ;
}
static unsigned long T_2 F_450 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_124 ,
unsigned long V_449 ,
unsigned long * V_451 )
{
unsigned long V_455 = V_447 [ V_344 ] ;
unsigned long V_456 = V_446 [ V_344 ] ;
unsigned long V_28 , F_117 ;
if ( ! V_124 && ! V_449 )
return 0 ;
V_28 = F_448 ( V_124 , V_455 , V_456 ) ;
F_117 = F_448 ( V_449 , V_455 , V_456 ) ;
F_445 ( V_13 , V_344 ,
V_124 , V_449 ,
& V_28 , & F_117 ) ;
return F_447 ( V_13 , V_28 , F_117 ) ;
}
static inline unsigned long T_2 F_446 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_124 ,
unsigned long V_449 ,
unsigned long * V_457 )
{
return V_457 [ V_344 ] ;
}
static inline unsigned long T_2 F_450 ( int V_13 ,
unsigned long V_344 ,
unsigned long V_124 ,
unsigned long V_449 ,
unsigned long * V_458 )
{
if ( ! V_458 )
return 0 ;
return V_458 [ V_344 ] ;
}
static void T_2 F_451 ( struct V_435 * V_9 ,
unsigned long V_124 ,
unsigned long V_449 ,
unsigned long * V_457 ,
unsigned long * V_458 )
{
unsigned long V_459 = 0 , V_460 = 0 ;
enum V_344 V_45 ;
for ( V_45 = 0 ; V_45 < V_97 ; V_45 ++ ) {
struct V_23 * V_23 = V_9 -> V_98 + V_45 ;
unsigned long V_136 , V_461 ;
V_136 = F_446 ( V_9 -> V_118 , V_45 ,
V_124 ,
V_449 ,
V_457 ) ;
V_461 = V_136 - F_450 ( V_9 -> V_118 , V_45 ,
V_124 , V_449 ,
V_458 ) ;
V_23 -> V_29 = V_136 ;
V_23 -> V_365 = V_461 ;
V_460 += V_136 ;
V_459 += V_461 ;
}
V_9 -> V_462 = V_460 ;
V_9 -> V_463 = V_459 ;
F_33 ( V_434 L_83 , V_9 -> V_118 ,
V_459 ) ;
}
static unsigned long T_3 F_452 ( unsigned long V_28 , unsigned long V_464 )
{
unsigned long V_465 ;
V_464 += V_28 & ( V_130 - 1 ) ;
V_465 = F_453 ( V_464 , V_130 ) ;
V_465 = V_465 >> V_132 ;
V_465 *= V_466 ;
V_465 = F_453 ( V_465 , 8 * sizeof( unsigned long ) ) ;
return V_465 / 8 ;
}
static void T_3 F_454 ( struct V_435 * V_9 ,
struct V_23 * V_23 ,
unsigned long V_28 ,
unsigned long V_464 )
{
unsigned long V_465 = F_452 ( V_28 , V_464 ) ;
V_23 -> V_467 = NULL ;
if ( V_465 )
V_23 -> V_467 =
F_431 ( V_465 ,
V_9 -> V_118 ) ;
}
static inline void F_454 ( struct V_435 * V_9 , struct V_23 * V_23 ,
unsigned long V_28 , unsigned long V_464 ) {}
void T_15 F_455 ( void )
{
unsigned int V_44 ;
if ( V_132 )
return;
if ( V_468 > V_16 )
V_44 = V_469 ;
else
V_44 = V_56 - 1 ;
V_132 = V_44 ;
}
void T_15 F_455 ( void )
{
}
static unsigned long T_15 F_456 ( unsigned long V_29 ,
unsigned long V_365 )
{
unsigned long V_154 = V_29 ;
if ( V_29 > V_365 + ( V_365 >> 4 ) &&
F_102 ( V_470 ) )
V_154 = V_365 ;
return F_343 ( V_154 * sizeof( struct V_1 ) ) >> V_16 ;
}
static void T_15 F_457 ( struct V_435 * V_9 )
{
enum V_344 V_401 ;
int V_13 = V_9 -> V_118 ;
unsigned long V_28 = V_9 -> V_124 ;
int V_24 ;
F_458 ( V_9 ) ;
#ifdef F_459
F_460 ( & V_9 -> V_471 ) ;
V_9 -> V_472 = 0 ;
V_9 -> V_473 = V_36 ;
#endif
#ifdef F_461
F_460 ( & V_9 -> V_474 ) ;
F_59 ( & V_9 -> V_475 ) ;
V_9 -> V_476 = 0 ;
#endif
F_433 ( & V_9 -> V_477 ) ;
F_433 ( & V_9 -> V_478 ) ;
F_462 ( V_9 ) ;
for ( V_401 = 0 ; V_401 < V_97 ; V_401 ++ ) {
struct V_23 * V_23 = V_9 -> V_98 + V_401 ;
unsigned long V_136 , V_479 , V_480 , V_481 ;
V_136 = V_23 -> V_29 ;
V_479 = V_480 = V_23 -> V_365 ;
V_481 = F_456 ( V_136 , V_479 ) ;
if ( ! F_111 ( V_401 ) ) {
if ( V_480 >= V_481 ) {
V_480 -= V_481 ;
if ( V_481 )
F_33 ( V_434
L_84 ,
V_418 [ V_401 ] , V_481 ) ;
} else
F_33 ( V_379
L_85 ,
V_418 [ V_401 ] , V_481 , V_480 ) ;
}
if ( V_401 == 0 && V_480 > V_482 ) {
V_480 -= V_482 ;
F_33 ( V_434 L_86 ,
V_418 [ 0 ] , V_482 ) ;
}
if ( ! F_111 ( V_401 ) )
V_483 += V_480 ;
else if ( V_483 > V_481 * 2 )
V_483 -= V_481 ;
V_484 += V_480 ;
V_23 -> V_107 = F_111 ( V_401 ) ? V_479 : V_480 ;
#ifdef V_293
V_23 -> V_110 = V_13 ;
V_23 -> V_485 = ( V_480 * V_486 )
/ 100 ;
V_23 -> V_487 = ( V_480 * V_488 ) / 100 ;
#endif
V_23 -> V_30 = V_418 [ V_401 ] ;
F_460 ( & V_23 -> V_87 ) ;
F_460 ( & V_23 -> V_489 ) ;
F_463 ( V_23 ) ;
V_23 -> V_227 = V_9 ;
F_434 ( V_23 ) ;
F_269 ( V_23 , V_196 , V_23 -> V_107 ) ;
F_464 ( & V_23 -> V_490 ) ;
if ( ! V_136 )
continue;
F_455 () ;
F_454 ( V_9 , V_23 , V_28 , V_136 ) ;
V_24 = F_435 ( V_23 , V_28 , V_136 ) ;
F_157 ( V_24 ) ;
F_465 ( V_136 , V_13 , V_401 , V_28 ) ;
V_28 += V_136 ;
}
}
static void T_14 F_466 ( struct V_435 * V_9 )
{
unsigned long T_16 V_99 = 0 ;
unsigned long T_16 V_321 = 0 ;
if ( ! V_9 -> V_462 )
return;
#ifdef F_467
V_99 = V_9 -> V_124 & ~ ( V_113 - 1 ) ;
V_321 = V_9 -> V_124 - V_99 ;
if ( ! V_9 -> V_491 ) {
unsigned long V_136 , V_100 ;
struct V_1 * V_492 ;
V_100 = F_14 ( V_9 ) ;
V_100 = F_468 ( V_100 , V_113 ) ;
V_136 = ( V_100 - V_99 ) * sizeof( struct V_1 ) ;
V_492 = F_469 ( V_9 -> V_118 , V_136 ) ;
if ( ! V_492 )
V_492 = F_431 ( V_136 ,
V_9 -> V_118 ) ;
V_9 -> V_491 = V_492 + V_321 ;
}
#ifndef F_470
if ( V_9 == F_10 ( 0 ) ) {
V_493 = F_10 ( 0 ) -> V_491 ;
#if F_471 ( V_494 ) || F_471 ( V_495 )
if ( F_19 ( V_493 ) != V_9 -> V_124 )
V_493 -= V_321 ;
#endif
}
#endif
#endif
}
void T_15 F_472 ( int V_13 , unsigned long * V_457 ,
unsigned long V_124 , unsigned long * V_458 )
{
T_1 * V_9 = F_10 ( V_13 ) ;
unsigned long V_27 = 0 ;
unsigned long V_101 = 0 ;
F_4 ( V_9 -> V_373 || V_9 -> V_217 ) ;
F_8 ( V_9 ) ;
V_9 -> V_118 = V_13 ;
V_9 -> V_124 = V_124 ;
#ifdef V_494
F_443 ( V_13 , & V_27 , & V_101 ) ;
F_163 ( L_87 , V_13 ,
( V_496 ) V_27 << V_16 ,
V_101 ? ( ( V_496 ) V_101 << V_16 ) - 1 : 0 ) ;
#endif
F_451 ( V_9 , V_27 , V_101 ,
V_457 , V_458 ) ;
F_466 ( V_9 ) ;
#ifdef F_467
F_33 ( V_434 L_88 ,
V_13 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_491 ) ;
#endif
F_457 ( V_9 ) ;
}
void T_3 F_473 ( void )
{
unsigned int V_497 ;
V_497 = F_474 ( V_498 . V_499 , V_399 ) ;
V_500 = V_497 + 1 ;
}
unsigned long T_3 F_475 ( void )
{
unsigned long V_501 = 0 , V_438 = 0 ;
unsigned long V_99 , V_100 , V_502 ;
int V_439 = - 1 ;
int V_45 , V_13 ;
F_158 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_99 || V_439 < 0 || V_439 == V_13 ) {
V_439 = V_13 ;
V_438 = V_100 ;
continue;
}
V_502 = ~ ( ( 1 << F_476 ( V_99 ) ) - 1 ) ;
while ( V_502 && V_438 <= ( V_99 & ( V_502 << 1 ) ) )
V_502 <<= 1 ;
V_501 |= V_502 ;
}
return ~ V_501 + 1 ;
}
static unsigned long T_3 F_477 ( int V_13 )
{
unsigned long V_503 = V_11 ;
unsigned long V_27 ;
int V_45 ;
F_158 (i, nid, &start_pfn, NULL, NULL)
V_503 = F_159 ( V_503 , V_27 ) ;
if ( V_503 == V_11 ) {
F_33 ( V_379
L_89 , V_13 ) ;
return 0 ;
}
return V_503 ;
}
unsigned long T_3 F_478 ( void )
{
return F_477 ( V_399 ) ;
}
static unsigned long T_3 F_479 ( void )
{
unsigned long V_460 = 0 ;
unsigned long V_27 , V_101 ;
int V_45 , V_13 ;
F_158 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_154 = V_101 - V_27 ;
V_460 += V_154 ;
if ( V_154 )
F_480 ( V_13 , V_129 ) ;
}
return V_460 ;
}
static void T_3 F_481 ( void )
{
int V_45 , V_13 ;
unsigned long V_504 ;
unsigned long V_505 , V_506 ;
T_8 V_507 = V_508 [ V_129 ] ;
unsigned long V_460 = F_479 () ;
int V_509 = F_482 ( V_508 [ V_129 ] ) ;
struct V_510 * V_511 ;
F_444 () ;
if ( F_483 () ) {
F_484 (memory, r) {
if ( ! F_485 ( V_511 ) )
continue;
V_13 = V_511 -> V_13 ;
V_504 = F_119 ( V_511 -> V_512 ) ;
V_450 [ V_13 ] = V_450 [ V_13 ] ?
F_159 ( V_504 , V_450 [ V_13 ] ) :
V_504 ;
}
goto V_513;
}
if ( V_514 ) {
unsigned long V_515 ;
V_514 =
F_453 ( V_514 , V_113 ) ;
V_514 = F_159 ( V_460 , V_514 ) ;
V_515 = V_460 - V_514 ;
V_516 = F_161 ( V_516 , V_515 ) ;
}
if ( ! V_516 || V_516 >= V_460 )
goto V_37;
V_504 = V_447 [ V_448 ] ;
V_517:
V_505 = V_516 / V_509 ;
F_167 (nid, N_MEMORY) {
unsigned long V_27 , V_101 ;
if ( V_516 < V_505 )
V_505 = V_516 / V_509 ;
V_506 = V_505 ;
F_158 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_518 ;
V_27 = F_161 ( V_27 , V_450 [ V_13 ] ) ;
if ( V_27 >= V_101 )
continue;
if ( V_27 < V_504 ) {
unsigned long V_519 ;
V_519 = F_159 ( V_101 , V_504 )
- V_27 ;
V_506 -= F_159 ( V_519 ,
V_506 ) ;
V_516 -= F_159 ( V_519 ,
V_516 ) ;
if ( V_101 <= V_504 ) {
V_450 [ V_13 ] = V_101 ;
continue;
}
V_27 = V_504 ;
}
V_518 = V_101 - V_27 ;
if ( V_518 > V_506 )
V_518 = V_506 ;
V_450 [ V_13 ] = V_27 + V_518 ;
V_516 -= F_159 ( V_516 ,
V_518 ) ;
V_506 -= V_518 ;
if ( ! V_506 )
break;
}
}
V_509 -- ;
if ( V_509 && V_516 > V_509 )
goto V_517;
V_513:
for ( V_13 = 0 ; V_13 < V_399 ; V_13 ++ )
V_450 [ V_13 ] =
F_453 ( V_450 [ V_13 ] , V_113 ) ;
V_37:
V_508 [ V_129 ] = V_507 ;
}
static void F_486 ( T_1 * V_9 , int V_13 )
{
enum V_344 V_344 ;
if ( V_129 == V_520 )
return;
for ( V_344 = 0 ; V_344 <= V_445 - 1 ; V_344 ++ ) {
struct V_23 * V_23 = & V_9 -> V_98 [ V_344 ] ;
if ( F_162 ( V_23 ) ) {
F_480 ( V_13 , V_521 ) ;
if ( V_520 != V_521 &&
V_344 <= V_264 )
F_480 ( V_13 , V_520 ) ;
break;
}
}
}
void T_3 F_487 ( unsigned long * V_183 )
{
unsigned long V_27 , V_101 ;
int V_45 , V_13 ;
memset ( V_447 , 0 ,
sizeof( V_447 ) ) ;
memset ( V_446 , 0 ,
sizeof( V_446 ) ) ;
V_447 [ 0 ] = F_478 () ;
V_446 [ 0 ] = V_183 [ 0 ] ;
for ( V_45 = 1 ; V_45 < V_97 ; V_45 ++ ) {
if ( V_45 == V_445 )
continue;
V_447 [ V_45 ] =
V_446 [ V_45 - 1 ] ;
V_446 [ V_45 ] =
F_161 ( V_183 [ V_45 ] , V_447 [ V_45 ] ) ;
}
V_447 [ V_445 ] = 0 ;
V_446 [ V_445 ] = 0 ;
memset ( V_450 , 0 , sizeof( V_450 ) ) ;
F_481 () ;
F_163 ( L_90 ) ;
for ( V_45 = 0 ; V_45 < V_97 ; V_45 ++ ) {
if ( V_45 == V_445 )
continue;
F_163 ( L_91 , V_418 [ V_45 ] ) ;
if ( V_447 [ V_45 ] ==
V_446 [ V_45 ] )
F_488 ( L_92 ) ;
else
F_488 ( L_93 ,
( V_496 ) V_447 [ V_45 ]
<< V_16 ,
( ( V_496 ) V_446 [ V_45 ]
<< V_16 ) - 1 ) ;
}
F_163 ( L_94 ) ;
for ( V_45 = 0 ; V_45 < V_399 ; V_45 ++ ) {
if ( V_450 [ V_45 ] )
F_163 ( L_95 , V_45 ,
( V_496 ) V_450 [ V_45 ] << V_16 ) ;
}
F_163 ( L_96 ) ;
F_158 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_163 ( L_97 , V_13 ,
( V_496 ) V_27 << V_16 ,
( ( V_496 ) V_101 << V_16 ) - 1 ) ;
F_489 () ;
F_473 () ;
F_395 (nid) {
T_1 * V_9 = F_10 ( V_13 ) ;
F_472 ( V_13 , NULL ,
F_477 ( V_13 ) , NULL ) ;
if ( V_9 -> V_463 )
F_480 ( V_13 , V_129 ) ;
F_486 ( V_9 , V_13 ) ;
}
}
static int T_3 F_490 ( char * V_48 , unsigned long * V_522 )
{
unsigned long long V_523 ;
if ( ! V_48 )
return - V_52 ;
V_523 = F_491 ( V_48 , & V_48 ) ;
* V_522 = V_523 >> V_16 ;
F_4 ( ( V_523 >> V_16 ) > V_11 ) ;
return 0 ;
}
static int T_3 F_492 ( char * V_48 )
{
return F_490 ( V_48 , & V_516 ) ;
}
static int T_3 F_493 ( char * V_48 )
{
return F_490 ( V_48 , & V_514 ) ;
}
void F_172 ( struct V_1 * V_1 , long V_81 )
{
F_89 ( & V_524 ) ;
F_27 ( V_1 ) -> V_107 += V_81 ;
V_335 += V_81 ;
#ifdef F_360
if ( F_130 ( V_1 ) )
V_341 += V_81 ;
#endif
F_97 ( & V_524 ) ;
}
unsigned long F_494 ( void * V_99 , void * V_100 , int V_525 , char * V_374 )
{
void * V_404 ;
unsigned long V_154 = 0 ;
V_99 = ( void * ) F_343 ( ( unsigned long ) V_99 ) ;
V_100 = ( void * ) ( ( unsigned long ) V_100 & V_526 ) ;
for ( V_404 = V_99 ; V_404 < V_100 ; V_404 += V_104 , V_154 ++ ) {
if ( ( unsigned int ) V_525 <= 0xFF )
memset ( V_404 , V_525 , V_104 ) ;
F_495 ( F_237 ( V_404 ) ) ;
}
if ( V_154 && V_374 )
F_163 ( L_98 ,
V_374 , V_154 << ( V_16 - 10 ) , V_99 , V_100 ) ;
return V_154 ;
}
void F_496 ( struct V_1 * V_1 )
{
F_497 ( V_1 ) ;
V_335 ++ ;
F_27 ( V_1 ) -> V_107 ++ ;
V_341 ++ ;
}
void T_3 F_498 ( const char * V_200 )
{
unsigned long V_527 , V_528 , V_529 , V_530 , V_531 ;
unsigned long V_532 , V_533 ;
V_527 = F_499 () ;
V_528 = V_534 - V_535 ;
V_529 = V_536 - V_537 ;
V_530 = V_538 - V_539 ;
V_531 = V_540 - V_541 ;
V_533 = V_542 - V_543 ;
V_532 = V_544 - V_545 ;
#define F_500 ( V_99 , V_100 , V_136 , V_404 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_500 ( V_543 , V_542 , V_533 ,
V_545 , V_532 ) ;
F_500 ( V_535 , V_534 , V_528 , V_545 , V_532 ) ;
F_500 ( V_537 , V_536 , V_529 , V_543 , V_533 ) ;
F_500 ( V_535 , V_534 , V_528 , V_539 , V_530 ) ;
F_500 ( V_537 , V_536 , V_529 , V_539 , V_530 ) ;
#undef F_500
F_163 ( L_99
L_100
L_101
#ifdef F_360
L_102
#endif
L_103 ,
F_501 () << ( V_16 - 10 ) , V_527 << ( V_16 - 10 ) ,
V_528 >> 10 , V_529 >> 10 , V_530 >> 10 ,
( V_533 + V_532 ) >> 10 , V_531 >> 10 ,
( V_527 - V_335 - V_546 ) << ( V_16 - 10 ) ,
V_546 << ( V_16 - 10 ) ,
#ifdef F_360
V_341 << ( V_16 - 10 ) ,
#endif
V_200 ? L_104 : L_105 , V_200 ? V_200 : L_105 ) ;
}
void T_3 F_502 ( unsigned long V_547 )
{
V_482 = V_547 ;
}
void T_3 F_503 ( unsigned long * V_457 )
{
F_472 ( 0 , V_457 ,
F_504 ( V_548 ) >> V_16 , NULL ) ;
}
static int F_505 ( struct V_549 * V_412 ,
unsigned long V_550 , void * V_551 )
{
int V_176 = ( unsigned long ) V_551 ;
if ( V_550 == V_552 || V_550 == V_553 ) {
F_506 ( V_176 ) ;
F_212 ( V_176 ) ;
F_507 ( V_176 ) ;
F_508 ( V_176 ) ;
}
return V_554 ;
}
void T_3 F_509 ( void )
{
F_510 ( F_505 , 0 ) ;
}
static void F_511 ( void )
{
struct V_435 * V_9 ;
unsigned long V_555 = 0 ;
enum V_344 V_45 , V_401 ;
F_512 (pgdat) {
for ( V_45 = 0 ; V_45 < V_97 ; V_45 ++ ) {
struct V_23 * V_23 = V_9 -> V_98 + V_45 ;
long F_161 = 0 ;
for ( V_401 = V_45 ; V_401 < V_97 ; V_401 ++ ) {
if ( V_23 -> V_223 [ V_401 ] > F_161 )
F_161 = V_23 -> V_223 [ V_401 ] ;
}
F_161 += F_270 ( V_23 ) ;
if ( F_161 > V_23 -> V_107 )
F_161 = V_23 -> V_107 ;
V_23 -> V_556 = F_161 ;
V_555 += F_161 ;
}
}
V_556 = V_555 ;
}
static void F_513 ( void )
{
struct V_435 * V_9 ;
enum V_344 V_401 , V_557 ;
F_512 (pgdat) {
for ( V_401 = 0 ; V_401 < V_97 ; V_401 ++ ) {
struct V_23 * V_23 = V_9 -> V_98 + V_401 ;
unsigned long V_107 = V_23 -> V_107 ;
V_23 -> V_223 [ V_401 ] = 0 ;
V_557 = V_401 ;
while ( V_557 ) {
struct V_23 * V_558 ;
V_557 -- ;
if ( V_559 [ V_557 ] < 1 )
V_559 [ V_557 ] = 1 ;
V_558 = V_9 -> V_98 + V_557 ;
V_558 -> V_223 [ V_401 ] = V_107 /
V_559 [ V_557 ] ;
V_107 += V_558 -> V_107 ;
}
}
}
F_511 () ;
}
static void F_514 ( void )
{
unsigned long V_560 = V_561 >> ( V_16 - 10 ) ;
unsigned long V_562 = 0 ;
struct V_23 * V_23 ;
unsigned long V_62 ;
F_515 (zone) {
if ( ! F_516 ( V_23 ) )
V_562 += V_23 -> V_107 ;
}
F_515 (zone) {
V_496 V_348 ;
F_196 ( & V_23 -> V_87 , V_62 ) ;
V_348 = ( V_496 ) V_560 * V_23 -> V_107 ;
F_517 ( V_348 , V_562 ) ;
if ( F_516 ( V_23 ) ) {
unsigned long V_563 ;
V_563 = V_23 -> V_107 / 1024 ;
V_563 = F_448 ( V_563 , V_564 , 128UL ) ;
V_23 -> V_188 [ V_565 ] = V_563 ;
} else {
V_23 -> V_188 [ V_565 ] = V_348 ;
}
V_23 -> V_188 [ V_566 ] = F_367 ( V_23 ) + ( V_348 >> 2 ) ;
V_23 -> V_188 [ V_567 ] = F_367 ( V_23 ) + ( V_348 >> 1 ) ;
F_91 ( V_23 , V_196 ,
F_270 ( V_23 ) - F_240 ( V_23 ) -
F_245 ( & V_23 -> V_197 [ V_196 ] ) ) ;
F_198 ( & V_23 -> V_87 , V_62 ) ;
}
F_511 () ;
}
void F_518 ( void )
{
F_380 ( & V_391 ) ;
F_514 () ;
F_288 ( & V_391 ) ;
}
static void T_2 F_519 ( struct V_23 * V_23 )
{
unsigned int V_568 , V_569 ;
V_568 = V_23 -> V_107 >> ( 30 - V_16 ) ;
if ( V_568 )
V_569 = F_520 ( 10 * V_568 ) ;
else
V_569 = 1 ;
V_23 -> V_570 = V_569 ;
}
static void T_2 F_521 ( void )
{
struct V_23 * V_23 ;
F_515 (zone)
F_519 ( V_23 ) ;
}
int T_2 F_522 ( void )
{
unsigned long V_571 ;
int V_572 ;
V_571 = F_351 () * ( V_104 >> 10 ) ;
V_572 = F_520 ( V_571 * 16 ) ;
if ( V_572 > V_573 ) {
V_561 = V_572 ;
if ( V_561 < 128 )
V_561 = 128 ;
if ( V_561 > 65536 )
V_561 = 65536 ;
} else {
F_282 ( L_106 ,
V_572 , V_573 ) ;
}
F_518 () ;
F_523 () ;
F_513 () ;
F_521 () ;
return 0 ;
}
int F_524 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
int V_574 ;
V_574 = F_525 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_574 )
return V_574 ;
if ( V_384 ) {
V_573 = V_561 ;
F_518 () ;
}
return 0 ;
}
int F_526 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
struct V_23 * V_23 ;
int V_574 ;
V_574 = F_525 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_574 )
return V_574 ;
F_515 (zone)
V_23 -> V_485 = ( V_23 -> V_107 *
V_486 ) / 100 ;
return 0 ;
}
int F_527 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
struct V_23 * V_23 ;
int V_574 ;
V_574 = F_525 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( V_574 )
return V_574 ;
F_515 (zone)
V_23 -> V_487 = ( V_23 -> V_107 *
V_488 ) / 100 ;
return 0 ;
}
int F_528 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
F_525 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
F_513 () ;
return 0 ;
}
int F_529 ( struct V_382 * V_383 , int V_384 ,
void T_10 * V_385 , T_9 * V_386 , T_11 * V_387 )
{
struct V_23 * V_23 ;
int V_575 ;
int V_24 ;
F_380 ( & V_576 ) ;
V_575 = V_429 ;
V_24 = F_525 ( V_383 , V_384 , V_385 , V_386 , V_387 ) ;
if ( ! V_384 || V_24 < 0 )
goto V_37;
if ( V_429 &&
V_429 < V_577 ) {
V_429 = V_575 ;
V_24 = - V_52 ;
goto V_37;
}
if ( V_429 == V_575 )
goto V_37;
F_213 (zone) {
unsigned int V_176 ;
F_396 (cpu)
F_425 ( V_23 ,
F_211 ( V_23 -> V_179 , V_176 ) ) ;
}
V_37:
F_288 ( & V_576 ) ;
return V_24 ;
}
static int T_3 F_530 ( char * V_200 )
{
if ( ! V_200 )
return 0 ;
V_578 = F_531 ( V_200 , & V_200 , 0 ) ;
return 1 ;
}
void * T_3 F_532 ( const char * V_579 ,
unsigned long V_580 ,
unsigned long V_581 ,
int V_582 ,
int V_62 ,
unsigned int * V_583 ,
unsigned int * V_584 ,
unsigned long V_585 ,
unsigned long V_586 )
{
unsigned long long F_161 = V_586 ;
unsigned long V_587 , V_136 ;
void * V_383 = NULL ;
if ( ! V_581 ) {
V_581 = V_483 ;
if ( V_16 < 20 )
V_581 = F_533 ( V_581 , ( 1 << 20 ) / V_104 ) ;
if ( V_582 > V_16 )
V_581 >>= ( V_582 - V_16 ) ;
else
V_581 <<= ( V_16 - V_582 ) ;
if ( F_16 ( V_62 & V_588 ) ) {
F_4 ( ! ( V_62 & V_589 ) ) ;
if ( ! ( V_581 >> * V_583 ) ) {
V_581 = 1UL << * V_583 ;
F_157 ( ! V_581 ) ;
}
} else if ( F_16 ( ( V_581 * V_580 ) < V_104 ) )
V_581 = V_104 / V_580 ;
}
V_581 = F_534 ( V_581 ) ;
if ( F_161 == 0 ) {
F_161 = ( ( unsigned long long ) V_484 << V_16 ) >> 4 ;
F_517 ( F_161 , V_580 ) ;
}
F_161 = F_159 ( F_161 , 0x80000000ULL ) ;
if ( V_581 < V_585 )
V_581 = V_585 ;
if ( V_581 > F_161 )
V_581 = F_161 ;
V_587 = F_535 ( V_581 ) ;
do {
V_136 = V_580 << V_587 ;
if ( V_62 & V_589 )
V_383 = F_536 ( V_136 , 0 ) ;
else if ( V_578 )
V_383 = F_537 ( V_136 , V_590 , V_591 ) ;
else {
if ( F_346 ( V_136 ) < V_56 ) {
V_383 = F_345 ( V_136 , V_590 ) ;
F_538 ( V_383 , V_136 , 1 , V_590 ) ;
}
}
} while ( ! V_383 && V_136 > V_104 && -- V_587 );
if ( ! V_383 )
F_539 ( L_107 , V_579 ) ;
F_33 ( V_59 L_108 ,
V_579 ,
( 1UL << V_587 ) ,
F_535 ( V_136 ) - V_16 ,
V_136 ) ;
if ( V_583 )
* V_583 = V_587 ;
if ( V_584 )
* V_584 = ( 1 << V_587 ) - 1 ;
return V_383 ;
}
static inline unsigned long * F_540 ( struct V_23 * V_23 ,
unsigned long V_12 )
{
#ifdef V_470
return F_541 ( V_12 ) -> V_467 ;
#else
return V_23 -> V_467 ;
#endif
}
static inline int F_542 ( struct V_23 * V_23 , unsigned long V_12 )
{
#ifdef V_470
V_12 &= ( V_17 - 1 ) ;
return ( V_12 >> V_132 ) * V_466 ;
#else
V_12 = V_12 - F_543 ( V_23 -> V_28 , V_130 ) ;
return ( V_12 >> V_132 ) * V_466 ;
#endif
}
unsigned long F_544 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_592 ,
unsigned long V_502 )
{
struct V_23 * V_23 ;
unsigned long * V_593 ;
unsigned long V_594 , V_595 ;
unsigned long V_596 ;
V_23 = F_27 ( V_1 ) ;
V_593 = F_540 ( V_23 , V_12 ) ;
V_594 = F_542 ( V_23 , V_12 ) ;
V_595 = V_594 / V_597 ;
V_594 &= ( V_597 - 1 ) ;
V_596 = V_593 [ V_595 ] ;
V_594 += V_592 ;
return ( V_596 >> ( V_597 - V_594 - 1 ) ) & V_502 ;
}
void F_545 ( struct V_1 * V_1 , unsigned long V_62 ,
unsigned long V_12 ,
unsigned long V_592 ,
unsigned long V_502 )
{
struct V_23 * V_23 ;
unsigned long * V_593 ;
unsigned long V_594 , V_595 ;
unsigned long V_598 , V_596 ;
F_101 ( V_466 != 4 ) ;
V_23 = F_27 ( V_1 ) ;
V_593 = F_540 ( V_23 , V_12 ) ;
V_594 = F_542 ( V_23 , V_12 ) ;
V_595 = V_594 / V_597 ;
V_594 &= ( V_597 - 1 ) ;
F_73 ( ! F_21 ( V_23 , V_12 ) , V_1 ) ;
V_594 += V_592 ;
V_502 <<= ( V_597 - V_594 - 1 ) ;
V_62 <<= ( V_597 - V_594 - 1 ) ;
V_596 = F_209 ( V_593 [ V_595 ] ) ;
for (; ; ) {
V_598 = F_546 ( & V_593 [ V_595 ] , V_596 , ( V_596 & ~ V_502 ) | V_62 ) ;
if ( V_596 == V_598 )
break;
V_596 = V_598 ;
}
}
bool F_547 ( struct V_23 * V_23 , struct V_1 * V_1 , int V_81 ,
bool V_599 )
{
unsigned long V_12 , V_600 , V_601 ;
int V_92 ;
if ( F_301 ( V_23 ) == V_445 )
return false ;
V_92 = F_95 ( V_1 ) ;
if ( V_92 == V_114 || F_197 ( V_92 ) )
return false ;
V_12 = F_19 ( V_1 ) ;
for ( V_601 = 0 , V_600 = 0 ; V_600 < V_130 ; V_600 ++ ) {
unsigned long V_602 = V_12 + V_600 ;
if ( ! F_26 ( V_602 ) )
continue;
V_1 = F_115 ( V_602 ) ;
if ( F_548 ( V_1 ) ) {
V_600 = F_533 ( V_600 + 1 , 1 << F_40 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_85 ( & V_1 -> V_78 ) ) {
if ( F_75 ( V_1 ) )
V_600 += ( 1 << F_71 ( V_1 ) ) - 1 ;
continue;
}
if ( V_599 && F_30 ( V_1 ) )
continue;
if ( ! F_549 ( V_1 ) )
V_601 ++ ;
if ( V_601 > V_81 )
return true ;
}
return false ;
}
bool F_550 ( struct V_1 * V_1 )
{
struct V_23 * V_23 ;
unsigned long V_12 ;
if ( ! F_393 ( F_188 ( V_1 ) ) )
return false ;
V_23 = F_27 ( V_1 ) ;
V_12 = F_19 ( V_1 ) ;
if ( ! F_21 ( V_23 , V_12 ) )
return false ;
return ! F_547 ( V_23 , V_1 , 0 , true ) ;
}
static unsigned long F_551 ( unsigned long V_12 )
{
return V_12 & ~ ( F_552 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_553 ( unsigned long V_12 )
{
return F_468 ( V_12 , F_552 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_554 ( struct V_603 * V_604 ,
unsigned long V_99 , unsigned long V_100 )
{
unsigned long V_605 ;
unsigned long V_12 = V_99 ;
unsigned int V_606 = 0 ;
int V_24 = 0 ;
F_555 () ;
while ( V_12 < V_100 || ! F_92 ( & V_604 -> V_607 ) ) {
if ( F_556 ( V_40 ) ) {
V_24 = - V_608 ;
break;
}
if ( F_92 ( & V_604 -> V_607 ) ) {
V_604 -> V_609 = 0 ;
V_12 = F_557 ( V_604 , V_12 , V_100 ) ;
if ( ! V_12 ) {
V_24 = - V_608 ;
break;
}
V_606 = 0 ;
} else if ( ++ V_606 == 5 ) {
V_24 = V_24 < 0 ? V_24 : - V_610 ;
break;
}
V_605 = F_558 ( V_604 -> V_23 ,
& V_604 -> V_607 ) ;
V_604 -> V_609 -= V_605 ;
V_24 = F_559 ( & V_604 -> V_607 , V_611 ,
NULL , 0 , V_604 -> V_208 , V_612 ) ;
}
if ( V_24 < 0 ) {
F_560 ( & V_604 -> V_607 ) ;
return V_24 ;
}
return 0 ;
}
int F_561 ( unsigned long V_99 , unsigned long V_100 ,
unsigned V_3 )
{
unsigned long V_613 , V_614 ;
unsigned int V_44 ;
int V_24 = 0 ;
struct V_603 V_604 = {
. V_609 = 0 ,
. V_44 = - 1 ,
. V_23 = F_27 ( F_115 ( V_99 ) ) ,
. V_208 = V_615 ,
. V_616 = true ,
} ;
F_59 ( & V_604 . V_607 ) ;
V_24 = F_562 ( F_551 ( V_99 ) ,
F_553 ( V_100 ) , V_3 ,
false ) ;
if ( V_24 )
return V_24 ;
V_24 = F_554 ( & V_604 , V_99 , V_100 ) ;
if ( V_24 && V_24 != - V_610 )
goto V_617;
F_563 () ;
F_216 ( V_604 . V_23 ) ;
V_44 = 0 ;
V_613 = V_99 ;
while ( ! F_75 ( F_115 ( V_613 ) ) ) {
if ( ++ V_44 >= V_56 ) {
V_613 = V_99 ;
break;
}
V_613 &= ~ 0UL << V_44 ;
}
if ( V_613 != V_99 ) {
V_44 = F_71 ( F_115 ( V_613 ) ) ;
if ( V_613 + ( 1UL << V_44 ) <= V_99 )
V_613 = V_99 ;
}
if ( F_564 ( V_613 , V_100 , false ) ) {
F_163 ( L_109 ,
V_618 , V_613 , V_100 ) ;
V_24 = - V_610 ;
goto V_617;
}
V_614 = F_565 ( & V_604 , V_613 , V_100 ) ;
if ( ! V_614 ) {
V_24 = - V_610 ;
goto V_617;
}
if ( V_99 != V_613 )
F_566 ( V_613 , V_99 - V_613 ) ;
if ( V_100 != V_614 )
F_566 ( V_100 , V_614 - V_100 ) ;
V_617:
F_567 ( F_551 ( V_99 ) ,
F_553 ( V_100 ) , V_3 ) ;
return V_24 ;
}
void F_566 ( unsigned long V_12 , unsigned V_46 )
{
unsigned int V_81 = 0 ;
for (; V_46 -- ; V_12 ++ ) {
struct V_1 * V_1 = F_115 ( V_12 ) ;
V_81 += F_74 ( V_1 ) != 1 ;
F_568 ( V_1 ) ;
}
F_569 ( V_81 != 0 , L_110 , V_81 ) ;
}
void T_2 F_570 ( struct V_23 * V_23 )
{
unsigned V_176 ;
F_380 ( & V_576 ) ;
F_396 (cpu)
F_425 ( V_23 ,
F_211 ( V_23 -> V_179 , V_176 ) ) ;
F_288 ( & V_576 ) ;
}
void F_571 ( struct V_23 * V_23 )
{
unsigned long V_62 ;
int V_176 ;
struct V_177 * V_178 ;
F_136 ( V_62 ) ;
if ( V_23 -> V_179 != & V_413 ) {
F_217 (cpu) {
V_178 = F_211 ( V_23 -> V_179 , V_176 ) ;
F_572 ( V_23 , V_178 ) ;
}
F_573 ( V_23 -> V_179 ) ;
V_23 -> V_179 = & V_413 ;
}
F_138 ( V_62 ) ;
}
void
F_574 ( unsigned long V_27 , unsigned long V_101 )
{
struct V_1 * V_1 ;
struct V_23 * V_23 ;
unsigned int V_44 , V_45 ;
unsigned long V_12 ;
unsigned long V_62 ;
for ( V_12 = V_27 ; V_12 < V_101 ; V_12 ++ )
if ( F_121 ( V_12 ) )
break;
if ( V_12 == V_101 )
return;
V_23 = F_27 ( F_115 ( V_12 ) ) ;
F_196 ( & V_23 -> V_87 , V_62 ) ;
V_12 = V_27 ;
while ( V_12 < V_101 ) {
if ( ! F_121 ( V_12 ) ) {
V_12 ++ ;
continue;
}
V_1 = F_115 ( V_12 ) ;
if ( F_16 ( ! F_75 ( V_1 ) && F_30 ( V_1 ) ) ) {
V_12 ++ ;
F_122 ( V_1 ) ;
continue;
}
F_157 ( F_74 ( V_1 ) ) ;
F_157 ( ! F_75 ( V_1 ) ) ;
V_44 = F_71 ( V_1 ) ;
#ifdef V_95
F_33 ( V_59 L_111 ,
V_12 , 1 << V_44 , V_101 ) ;
#endif
F_81 ( & V_1 -> V_63 ) ;
F_67 ( V_1 ) ;
V_23 -> V_71 [ V_44 ] . V_72 -- ;
for ( V_45 = 0 ; V_45 < ( 1 << V_44 ) ; V_45 ++ )
F_122 ( ( V_1 + V_45 ) ) ;
V_12 += ( 1 << V_44 ) ;
}
F_198 ( & V_23 -> V_87 , V_62 ) ;
}
bool F_575 ( struct V_1 * V_1 )
{
struct V_23 * V_23 = F_27 ( V_1 ) ;
unsigned long V_12 = F_19 ( V_1 ) ;
unsigned long V_62 ;
unsigned int V_44 ;
F_196 ( & V_23 -> V_87 , V_62 ) ;
for ( V_44 = 0 ; V_44 < V_56 ; V_44 ++ ) {
struct V_1 * V_619 = V_1 - ( V_12 & ( ( 1 << V_44 ) - 1 ) ) ;
if ( F_75 ( V_619 ) && F_71 ( V_619 ) >= V_44 )
break;
}
F_198 ( & V_23 -> V_87 , V_62 ) ;
return V_44 < V_56 ;
}
