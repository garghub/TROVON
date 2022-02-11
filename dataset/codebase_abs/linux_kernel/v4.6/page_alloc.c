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
void F_16 ( struct V_1 * V_1 , int V_3 )
{
if ( F_17 ( V_20 &&
V_3 < V_21 ) )
V_3 = V_22 ;
F_18 ( V_1 , ( unsigned long ) V_3 ,
V_23 , V_24 ) ;
}
static int F_19 ( struct V_25 * V_25 , struct V_1 * V_1 )
{
int V_26 = 0 ;
unsigned V_27 ;
unsigned long V_12 = F_20 ( V_1 ) ;
unsigned long V_28 , V_29 ;
do {
V_27 = F_21 ( V_25 ) ;
V_29 = V_25 -> V_30 ;
V_28 = V_25 -> V_31 ;
if ( ! F_22 ( V_25 , V_12 ) )
V_26 = 1 ;
} while ( F_23 ( V_25 , V_27 ) );
if ( V_26 )
F_24 ( L_1 ,
V_12 , F_25 ( V_25 ) , V_25 -> V_32 ,
V_29 , V_29 + V_28 ) ;
return V_26 ;
}
static int F_26 ( struct V_25 * V_25 , struct V_1 * V_1 )
{
if ( ! F_27 ( F_20 ( V_1 ) ) )
return 0 ;
if ( V_25 != F_28 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_29 ( struct V_25 * V_25 , struct V_1 * V_1 )
{
if ( F_19 ( V_25 , V_1 ) )
return 1 ;
if ( ! F_26 ( V_25 , V_1 ) )
return 1 ;
return 0 ;
}
static inline int F_29 ( struct V_25 * V_25 , struct V_1 * V_1 )
{
return 0 ;
}
static void F_30 ( struct V_1 * V_1 , const char * V_33 ,
unsigned long V_34 )
{
static unsigned long V_35 ;
static unsigned long V_36 ;
static unsigned long V_37 ;
if ( F_31 ( V_1 ) ) {
F_32 ( V_1 ) ;
return;
}
if ( V_36 == 60 ) {
if ( F_33 ( V_38 , V_35 ) ) {
V_37 ++ ;
goto V_39;
}
if ( V_37 ) {
F_34 (
L_2 ,
V_37 ) ;
V_37 = 0 ;
}
V_36 = 0 ;
}
if ( V_36 ++ == 0 )
V_35 = V_38 + 60 * V_40 ;
F_34 ( L_3 ,
V_41 -> V_42 , F_20 ( V_1 ) ) ;
F_35 ( V_1 , V_33 ) ;
V_34 &= V_1 -> V_43 ;
if ( V_34 )
F_34 ( L_4 ,
V_34 , & V_34 ) ;
F_36 ( V_1 ) ;
F_37 () ;
F_38 () ;
V_39:
F_32 ( V_1 ) ;
F_39 ( V_44 , V_45 ) ;
}
void F_40 ( struct V_1 * V_1 )
{
F_41 ( V_1 , F_42 ( V_1 ) ) ;
}
void F_43 ( struct V_1 * V_1 , unsigned int V_46 )
{
int V_47 ;
int V_48 = 1 << V_46 ;
F_44 ( V_1 , V_49 ) ;
F_45 ( V_1 , V_46 ) ;
F_46 ( V_1 ) ;
for ( V_47 = 1 ; V_47 < V_48 ; V_47 ++ ) {
struct V_1 * V_50 = V_1 + V_47 ;
F_47 ( V_50 , 0 ) ;
V_50 -> V_51 = V_52 ;
F_48 ( V_50 , V_1 ) ;
}
F_49 ( F_50 ( V_1 ) , - 1 ) ;
}
static int T_3 F_51 ( char * V_53 )
{
if ( ! V_53 )
return - V_54 ;
if ( strcmp ( V_53 , L_5 ) == 0 )
V_55 = true ;
if ( strcmp ( V_53 , L_6 ) == 0 )
V_55 = false ;
return 0 ;
}
static bool F_52 ( void )
{
if ( ! F_53 () )
return false ;
return true ;
}
static void F_54 ( void )
{
if ( ! F_53 () )
return;
V_56 = true ;
}
static int T_3 F_55 ( char * V_53 )
{
unsigned long V_57 ;
if ( F_56 ( V_53 , 10 , & V_57 ) < 0 || V_57 > V_58 / 2 ) {
F_24 ( L_7 ) ;
return 0 ;
}
V_59 = V_57 ;
F_57 ( L_8 , V_57 ) ;
return 0 ;
}
static inline void F_58 ( struct V_25 * V_25 , struct V_1 * V_1 ,
unsigned int V_46 , int V_3 )
{
struct V_60 * V_60 ;
if ( ! F_59 () )
return;
V_60 = F_60 ( V_1 ) ;
F_61 ( V_61 , & V_60 -> V_43 ) ;
F_62 ( & V_1 -> V_62 ) ;
F_63 ( V_1 , V_46 ) ;
F_64 ( V_25 , - ( 1 << V_46 ) , V_3 ) ;
}
static inline void F_65 ( struct V_25 * V_25 , struct V_1 * V_1 ,
unsigned int V_46 , int V_3 )
{
struct V_60 * V_60 ;
if ( ! F_59 () )
return;
V_60 = F_60 ( V_1 ) ;
F_66 ( V_61 , & V_60 -> V_43 ) ;
F_63 ( V_1 , 0 ) ;
if ( ! F_67 ( V_3 ) )
F_64 ( V_25 , ( 1 << V_46 ) , V_3 ) ;
}
static inline void F_58 ( struct V_25 * V_25 , struct V_1 * V_1 ,
unsigned int V_46 , int V_3 ) {}
static inline void F_65 ( struct V_25 * V_25 , struct V_1 * V_1 ,
unsigned int V_46 , int V_3 ) {}
static inline void F_68 ( struct V_1 * V_1 , unsigned int V_46 )
{
F_63 ( V_1 , V_46 ) ;
F_69 ( V_1 ) ;
}
static inline void F_70 ( struct V_1 * V_1 )
{
F_71 ( V_1 ) ;
F_63 ( V_1 , 0 ) ;
}
static inline int F_72 ( struct V_1 * V_1 , struct V_1 * V_63 ,
unsigned int V_46 )
{
if ( ! F_27 ( F_20 ( V_63 ) ) )
return 0 ;
if ( F_73 ( V_63 ) && F_74 ( V_63 ) == V_46 ) {
if ( F_75 ( V_1 ) != F_75 ( V_63 ) )
return 0 ;
F_76 ( F_77 ( V_63 ) != 0 , V_63 ) ;
return 1 ;
}
if ( F_78 ( V_63 ) && F_74 ( V_63 ) == V_46 ) {
if ( F_75 ( V_1 ) != F_75 ( V_63 ) )
return 0 ;
F_76 ( F_77 ( V_63 ) != 0 , V_63 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_79 ( struct V_1 * V_1 ,
unsigned long V_12 ,
struct V_25 * V_25 , unsigned int V_46 ,
int V_3 )
{
unsigned long V_64 ;
unsigned long V_65 ;
unsigned long V_66 ( V_67 ) ;
struct V_1 * V_63 ;
unsigned int V_68 ;
V_68 = F_80 (unsigned int, MAX_ORDER, pageblock_order + 1 ) ;
F_81 ( ! F_82 ( V_25 ) ) ;
F_76 ( V_1 -> V_43 & V_69 , V_1 ) ;
F_81 ( V_3 == - 1 ) ;
if ( F_83 ( ! F_67 ( V_3 ) ) )
F_64 ( V_25 , 1 << V_46 , V_3 ) ;
V_64 = V_12 & ( ( 1 << V_58 ) - 1 ) ;
F_76 ( V_64 & ( ( 1 << V_46 ) - 1 ) , V_1 ) ;
F_76 ( F_29 ( V_25 , V_1 ) , V_1 ) ;
V_70:
while ( V_46 < V_68 - 1 ) {
V_67 = F_84 ( V_64 , V_46 ) ;
V_63 = V_1 + ( V_67 - V_64 ) ;
if ( ! F_72 ( V_1 , V_63 , V_46 ) )
goto V_71;
if ( F_73 ( V_63 ) ) {
F_65 ( V_25 , V_63 , V_46 , V_3 ) ;
} else {
F_85 ( & V_63 -> V_62 ) ;
V_25 -> V_72 [ V_46 ] . V_73 -- ;
F_70 ( V_63 ) ;
}
V_65 = V_67 & V_64 ;
V_1 = V_1 + ( V_65 - V_64 ) ;
V_64 = V_65 ;
V_46 ++ ;
}
if ( V_68 < V_58 ) {
if ( F_17 ( F_86 ( V_25 ) ) ) {
int V_74 ;
V_67 = F_84 ( V_64 , V_46 ) ;
V_63 = V_1 + ( V_67 - V_64 ) ;
V_74 = F_87 ( V_63 ) ;
if ( V_3 != V_74
&& ( F_67 ( V_3 ) ||
F_67 ( V_74 ) ) )
goto V_71;
}
V_68 ++ ;
goto V_70;
}
V_71:
F_68 ( V_1 , V_46 ) ;
if ( ( V_46 < V_58 - 2 ) && F_27 ( F_20 ( V_63 ) ) ) {
struct V_1 * V_75 , * V_76 ;
V_65 = V_67 & V_64 ;
V_75 = V_1 + ( V_65 - V_64 ) ;
V_67 = F_84 ( V_65 , V_46 + 1 ) ;
V_76 = V_75 + ( V_67 - V_65 ) ;
if ( F_72 ( V_75 , V_76 , V_46 + 1 ) ) {
F_88 ( & V_1 -> V_62 ,
& V_25 -> V_72 [ V_46 ] . V_77 [ V_3 ] ) ;
goto V_39;
}
}
F_89 ( & V_1 -> V_62 , & V_25 -> V_72 [ V_46 ] . V_77 [ V_3 ] ) ;
V_39:
V_25 -> V_72 [ V_46 ] . V_73 ++ ;
}
static inline int F_90 ( struct V_1 * V_1 )
{
const char * V_78 = NULL ;
unsigned long V_34 = 0 ;
if ( F_17 ( F_91 ( & V_1 -> V_79 ) != - 1 ) )
V_78 = L_9 ;
if ( F_17 ( V_1 -> V_51 != NULL ) )
V_78 = L_10 ;
if ( F_17 ( F_92 ( V_1 ) != 0 ) )
V_78 = L_11 ;
if ( F_17 ( V_1 -> V_43 & V_80 ) ) {
V_78 = L_12 ;
V_34 = V_80 ;
}
#ifdef F_93
if ( F_17 ( V_1 -> V_81 ) )
V_78 = L_13 ;
#endif
if ( F_17 ( V_78 ) ) {
F_30 ( V_1 , V_78 , V_34 ) ;
return 1 ;
}
F_94 ( V_1 ) ;
if ( V_1 -> V_43 & V_69 )
V_1 -> V_43 &= ~ V_69 ;
return 0 ;
}
static void F_95 ( struct V_25 * V_25 , int V_82 ,
struct V_83 * V_84 )
{
int V_3 = 0 ;
int V_85 = 0 ;
int V_86 = V_82 ;
unsigned long V_87 ;
F_96 ( & V_25 -> V_88 ) ;
V_87 = F_97 ( V_25 , V_89 ) ;
if ( V_87 )
F_98 ( V_25 , V_89 , - V_87 ) ;
while ( V_86 ) {
struct V_1 * V_1 ;
struct V_90 * V_91 ;
do {
V_85 ++ ;
if ( ++ V_3 == V_21 )
V_3 = 0 ;
V_91 = & V_84 -> V_92 [ V_3 ] ;
} while ( F_99 ( V_91 ) );
if ( V_85 == V_21 )
V_85 = V_86 ;
do {
int V_93 ;
V_1 = F_100 ( V_91 , struct V_1 , V_62 ) ;
F_85 ( & V_1 -> V_62 ) ;
V_93 = F_1 ( V_1 ) ;
F_76 ( F_67 ( V_93 ) , V_1 ) ;
if ( F_17 ( F_86 ( V_25 ) ) )
V_93 = F_87 ( V_1 ) ;
F_79 ( V_1 , F_20 ( V_1 ) , V_25 , 0 , V_93 ) ;
F_101 ( V_1 , 0 , V_93 ) ;
} while ( -- V_86 && -- V_85 && ! F_99 ( V_91 ) );
}
F_102 ( & V_25 -> V_88 ) ;
}
static void F_103 ( struct V_25 * V_25 ,
struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_46 ,
int V_3 )
{
unsigned long V_87 ;
F_96 ( & V_25 -> V_88 ) ;
V_87 = F_97 ( V_25 , V_89 ) ;
if ( V_87 )
F_98 ( V_25 , V_89 , - V_87 ) ;
if ( F_17 ( F_86 ( V_25 ) ||
F_67 ( V_3 ) ) ) {
V_3 = F_104 ( V_1 , V_12 ) ;
}
F_79 ( V_1 , V_12 , V_25 , V_46 , V_3 ) ;
F_102 ( & V_25 -> V_88 ) ;
}
static int F_105 ( struct V_1 * V_94 , struct V_1 * V_1 )
{
int V_26 = 1 ;
F_106 ( ( unsigned long ) V_95 & 1 ) ;
if ( ! F_107 ( V_96 ) ) {
V_26 = 0 ;
goto V_39;
}
switch ( V_1 - V_94 ) {
case 1 :
if ( F_17 ( F_108 ( V_1 ) ) ) {
F_30 ( V_1 , L_14 , 0 ) ;
goto V_39;
}
break;
case 2 :
break;
default:
if ( V_1 -> V_51 != V_52 ) {
F_30 ( V_1 , L_15 , 0 ) ;
goto V_39;
}
break;
}
if ( F_17 ( ! F_109 ( V_1 ) ) ) {
F_30 ( V_1 , L_16 , 0 ) ;
goto V_39;
}
if ( F_17 ( F_110 ( V_1 ) != V_94 ) ) {
F_30 ( V_1 , L_17 , 0 ) ;
goto V_39;
}
V_26 = 0 ;
V_39:
V_1 -> V_51 = NULL ;
F_111 ( V_1 ) ;
return V_26 ;
}
static void T_2 F_112 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_25 , int V_13 )
{
F_113 ( V_1 , V_25 , V_13 , V_12 ) ;
F_114 ( V_1 ) ;
F_32 ( V_1 ) ;
F_94 ( V_1 ) ;
F_62 ( & V_1 -> V_62 ) ;
#ifdef F_115
if ( ! F_116 ( V_25 ) )
F_117 ( V_1 , F_118 ( V_12 << V_17 ) ) ;
#endif
}
static void T_2 F_119 ( unsigned long V_12 , unsigned long V_25 ,
int V_13 )
{
return F_112 ( F_120 ( V_12 ) , V_12 , V_25 , V_13 ) ;
}
static void F_121 ( unsigned long V_12 )
{
T_1 * V_9 ;
int V_13 , V_97 ;
if ( ! F_9 ( V_12 ) )
return;
V_13 = F_11 ( V_12 ) ;
V_9 = F_10 ( V_13 ) ;
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ ) {
struct V_25 * V_25 = & V_9 -> V_99 [ V_97 ] ;
if ( V_12 >= V_25 -> V_30 && V_12 < F_122 ( V_25 ) )
break;
}
F_119 ( V_12 , V_97 , V_13 ) ;
}
static inline void F_121 ( unsigned long V_12 )
{
}
void T_2 F_123 ( unsigned long V_100 , unsigned long V_101 )
{
unsigned long V_29 = F_124 ( V_100 ) ;
unsigned long V_102 = F_125 ( V_101 ) ;
for (; V_29 < V_102 ; V_29 ++ ) {
if ( F_126 ( V_29 ) ) {
struct V_1 * V_1 = F_120 ( V_29 ) ;
F_121 ( V_29 ) ;
F_62 ( & V_1 -> V_62 ) ;
F_127 ( V_1 ) ;
}
}
}
static bool F_128 ( struct V_1 * V_1 , unsigned int V_46 )
{
bool V_103 = F_129 ( V_1 ) ;
int V_47 , V_104 = 0 ;
F_76 ( F_109 ( V_1 ) , V_1 ) ;
F_76 ( V_103 && F_42 ( V_1 ) != V_46 , V_1 ) ;
F_130 ( V_1 , V_46 ) ;
F_131 ( V_1 , V_46 ) ;
F_132 ( V_1 , V_46 ) ;
if ( F_133 ( V_1 ) )
V_1 -> V_51 = NULL ;
V_104 += F_90 ( V_1 ) ;
for ( V_47 = 1 ; V_47 < ( 1 << V_46 ) ; V_47 ++ ) {
if ( V_103 )
V_104 += F_105 ( V_1 , V_1 + V_47 ) ;
V_104 += F_90 ( V_1 + V_47 ) ;
}
if ( V_104 )
return false ;
F_134 ( V_1 , V_46 ) ;
if ( ! F_135 ( V_1 ) ) {
F_136 ( F_137 ( V_1 ) ,
V_105 << V_46 ) ;
F_138 ( F_137 ( V_1 ) ,
V_105 << V_46 ) ;
}
F_139 ( V_1 , V_46 ) ;
F_140 ( V_1 , 1 << V_46 , 0 ) ;
F_141 ( V_1 , 1 << V_46 , 0 ) ;
return true ;
}
static void F_41 ( struct V_1 * V_1 , unsigned int V_46 )
{
unsigned long V_43 ;
int V_3 ;
unsigned long V_12 = F_20 ( V_1 ) ;
if ( ! F_128 ( V_1 , V_46 ) )
return;
V_3 = F_104 ( V_1 , V_12 ) ;
F_142 ( V_43 ) ;
F_143 ( V_106 , 1 << V_46 ) ;
F_103 ( F_28 ( V_1 ) , V_1 , V_12 , V_46 , V_3 ) ;
F_144 ( V_43 ) ;
}
static void T_3 F_145 ( struct V_1 * V_1 ,
unsigned long V_12 , unsigned int V_46 )
{
unsigned int V_48 = 1 << V_46 ;
struct V_1 * V_50 = V_1 ;
unsigned int V_107 ;
F_146 ( V_50 ) ;
for ( V_107 = 0 ; V_107 < ( V_48 - 1 ) ; V_107 ++ , V_50 ++ ) {
F_146 ( V_50 + 1 ) ;
F_147 ( V_50 ) ;
F_47 ( V_50 , 0 ) ;
}
F_147 ( V_50 ) ;
F_47 ( V_50 , 0 ) ;
F_28 ( V_1 ) -> V_108 += V_48 ;
F_148 ( V_1 ) ;
F_149 ( V_1 , V_46 ) ;
}
int T_2 F_11 ( unsigned long V_12 )
{
static F_150 ( V_109 ) ;
int V_13 ;
F_96 ( & V_109 ) ;
V_13 = F_151 ( V_12 , & V_110 ) ;
if ( V_13 < 0 )
V_13 = 0 ;
F_102 ( & V_109 ) ;
return V_13 ;
}
static inline bool T_2 F_152 ( unsigned long V_12 , int V_111 ,
struct V_112 * V_113 )
{
int V_13 ;
V_13 = F_151 ( V_12 , V_113 ) ;
if ( V_13 >= 0 && V_13 != V_111 )
return false ;
return true ;
}
static inline bool T_2 F_153 ( unsigned long V_12 , int V_111 )
{
return F_152 ( V_12 , V_111 , & V_110 ) ;
}
static inline bool T_2 F_153 ( unsigned long V_12 , int V_111 )
{
return true ;
}
static inline bool T_2 F_152 ( unsigned long V_12 , int V_111 ,
struct V_112 * V_113 )
{
return true ;
}
void T_3 F_154 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned int V_46 )
{
if ( F_9 ( V_12 ) )
return;
return F_145 ( V_1 , V_12 , V_46 ) ;
}
struct V_1 * F_155 ( unsigned long V_29 ,
unsigned long V_102 , struct V_25 * V_25 )
{
struct V_1 * V_114 ;
struct V_1 * V_115 ;
V_102 -- ;
if ( ! F_126 ( V_29 ) || ! F_126 ( V_102 ) )
return NULL ;
V_114 = F_120 ( V_29 ) ;
if ( F_28 ( V_114 ) != V_25 )
return NULL ;
V_115 = F_120 ( V_102 ) ;
if ( F_75 ( V_114 ) != F_75 ( V_115 ) )
return NULL ;
return V_114 ;
}
void F_156 ( struct V_25 * V_25 )
{
unsigned long V_116 = V_25 -> V_30 ;
unsigned long V_117 ;
V_117 = F_157 ( V_116 + 1 , V_118 ) ;
for (; V_116 < F_122 ( V_25 ) ;
V_116 = V_117 ,
V_117 += V_118 ) {
V_117 = F_158 ( V_117 , F_122 ( V_25 ) ) ;
if ( ! F_155 ( V_116 ,
V_117 , V_25 ) )
return;
}
V_25 -> V_119 = true ;
}
void F_159 ( struct V_25 * V_25 )
{
V_25 -> V_119 = false ;
}
static void T_3 F_160 ( struct V_1 * V_1 ,
unsigned long V_12 , int V_48 )
{
int V_47 ;
if ( ! V_1 )
return;
if ( V_48 == V_120 &&
( V_12 & ( V_120 - 1 ) ) == 0 ) {
F_16 ( V_1 , V_121 ) ;
F_145 ( V_1 , V_12 , V_58 - 1 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ , V_1 ++ , V_12 ++ )
F_145 ( V_1 , V_12 , 0 ) ;
}
static inline void T_3 F_161 ( void )
{
if ( F_162 ( & V_122 ) )
F_163 ( & V_123 ) ;
}
static int T_3 F_164 ( void * V_124 )
{
T_1 * V_9 = V_124 ;
int V_13 = V_9 -> V_125 ;
struct V_112 V_126 = { } ;
unsigned long V_100 = V_38 ;
unsigned long V_48 = 0 ;
unsigned long V_127 , V_128 ;
int V_47 , V_97 ;
struct V_25 * V_25 ;
unsigned long V_129 = V_9 -> V_10 ;
const struct V_130 * V_130 = F_165 ( V_9 -> V_125 ) ;
if ( V_129 == V_11 ) {
F_161 () ;
return 0 ;
}
if ( ! F_166 ( V_130 ) )
F_167 ( V_41 , V_130 ) ;
F_168 ( V_9 -> V_10 < V_9 -> V_131 ) ;
F_168 ( V_9 -> V_10 > F_14 ( V_9 ) ) ;
V_9 -> V_10 = V_11 ;
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ ) {
V_25 = V_9 -> V_99 + V_97 ;
if ( V_129 < F_122 ( V_25 ) )
break;
}
F_169 (i, nid, &walk_start, &walk_end, NULL) {
unsigned long V_12 , V_102 ;
struct V_1 * V_1 = NULL ;
struct V_1 * V_132 = NULL ;
unsigned long V_133 = 0 ;
int V_134 = 0 ;
V_102 = F_158 ( V_128 , F_122 ( V_25 ) ) ;
V_12 = V_129 ;
if ( V_12 < V_127 )
V_12 = V_127 ;
if ( V_12 < V_25 -> V_30 )
V_12 = V_25 -> V_30 ;
for (; V_12 < V_102 ; V_12 ++ ) {
if ( ! F_27 ( V_12 ) )
goto V_135;
if ( ( V_12 & ( V_120 - 1 ) ) == 0 ) {
if ( ! F_126 ( V_12 ) ) {
V_1 = NULL ;
goto V_135;
}
}
if ( ! F_152 ( V_12 , V_13 , & V_126 ) ) {
V_1 = NULL ;
goto V_135;
}
if ( V_1 && ( V_12 & ( V_120 - 1 ) ) != 0 ) {
V_1 ++ ;
} else {
V_48 += V_134 ;
F_160 ( V_132 ,
V_133 , V_134 ) ;
V_132 = NULL ;
V_133 = V_134 = 0 ;
V_1 = F_120 ( V_12 ) ;
F_170 () ;
}
if ( V_1 -> V_43 ) {
F_81 ( F_28 ( V_1 ) != V_25 ) ;
goto V_135;
}
F_112 ( V_1 , V_12 , V_97 , V_13 ) ;
if ( ! V_132 ) {
V_132 = V_1 ;
V_133 = V_12 ;
V_134 = 0 ;
}
V_134 ++ ;
continue;
V_135:
V_48 += V_134 ;
F_160 ( V_132 , V_133 ,
V_134 ) ;
V_132 = NULL ;
V_133 = V_134 = 0 ;
}
V_129 = F_15 ( V_102 , V_129 ) ;
}
F_4 ( ++ V_97 < V_98 && F_171 ( ++ V_25 ) ) ;
F_57 ( L_18 , V_13 , V_48 ,
F_172 ( V_38 - V_100 ) ) ;
F_161 () ;
return 0 ;
}
void T_3 F_173 ( void )
{
struct V_25 * V_25 ;
#ifdef F_174
int V_13 ;
F_49 ( & V_122 , F_175 ( V_136 ) ) ;
F_176 (nid, N_MEMORY) {
F_177 ( F_164 , F_10 ( V_13 ) , L_19 , V_13 ) ;
}
F_178 ( & V_123 ) ;
F_179 () ;
#endif
F_180 (zone)
F_156 ( V_25 ) ;
}
void T_3 F_181 ( struct V_1 * V_1 )
{
unsigned V_47 = V_118 ;
struct V_1 * V_50 = V_1 ;
do {
F_147 ( V_50 ) ;
F_47 ( V_50 , 0 ) ;
} while ( ++ V_50 , -- V_47 );
F_16 ( V_1 , V_137 ) ;
if ( V_138 >= V_58 ) {
V_47 = V_118 ;
V_50 = V_1 ;
do {
F_148 ( V_50 ) ;
F_149 ( V_50 , V_58 - 1 ) ;
V_50 += V_120 ;
} while ( V_47 -= V_120 );
} else {
F_148 ( V_1 ) ;
F_149 ( V_1 , V_138 ) ;
}
F_182 ( V_1 , V_118 ) ;
}
static inline void F_183 ( struct V_25 * V_25 , struct V_1 * V_1 ,
int V_139 , int V_140 , struct V_72 * V_141 ,
int V_3 )
{
unsigned long V_142 = 1 << V_140 ;
while ( V_140 > V_139 ) {
V_141 -- ;
V_140 -- ;
V_142 >>= 1 ;
F_76 ( F_29 ( V_25 , & V_1 [ V_142 ] ) , & V_1 [ V_142 ] ) ;
if ( F_107 ( V_143 ) &&
F_59 () &&
V_140 < F_184 () ) {
F_58 ( V_25 , & V_1 [ V_142 ] , V_140 , V_3 ) ;
continue;
}
F_89 ( & V_1 [ V_142 ] . V_62 , & V_141 -> V_77 [ V_3 ] ) ;
V_141 -> V_73 ++ ;
F_68 ( & V_1 [ V_142 ] , V_140 ) ;
}
}
static inline int F_185 ( struct V_1 * V_1 )
{
const char * V_78 = NULL ;
unsigned long V_34 = 0 ;
if ( F_17 ( F_91 ( & V_1 -> V_79 ) != - 1 ) )
V_78 = L_9 ;
if ( F_17 ( V_1 -> V_51 != NULL ) )
V_78 = L_10 ;
if ( F_17 ( F_92 ( V_1 ) != 0 ) )
V_78 = L_11 ;
if ( F_17 ( V_1 -> V_43 & V_144 ) ) {
V_78 = L_20 ;
V_34 = V_144 ;
}
if ( F_17 ( V_1 -> V_43 & V_69 ) ) {
V_78 = L_21 ;
V_34 = V_69 ;
}
#ifdef F_93
if ( F_17 ( V_1 -> V_81 ) )
V_78 = L_13 ;
#endif
if ( F_17 ( V_78 ) ) {
F_30 ( V_1 , V_78 , V_34 ) ;
return 1 ;
}
return 0 ;
}
static inline bool F_186 ( bool V_145 )
{
return F_107 ( V_146 ) &&
F_187 () && V_145 ;
}
static int F_188 ( struct V_1 * V_1 , unsigned int V_46 , T_4 V_147 ,
int V_148 )
{
int V_47 ;
bool V_145 = true ;
for ( V_47 = 0 ; V_47 < ( 1 << V_46 ) ; V_47 ++ ) {
struct V_1 * V_50 = V_1 + V_47 ;
if ( F_17 ( F_185 ( V_50 ) ) )
return 1 ;
if ( V_145 )
V_145 &= F_189 ( V_50 ) ;
}
F_63 ( V_1 , 0 ) ;
F_148 ( V_1 ) ;
F_190 ( V_1 , V_46 ) ;
F_141 ( V_1 , 1 << V_46 , 1 ) ;
F_140 ( V_1 , 1 << V_46 , 1 ) ;
F_191 ( V_1 , V_46 ) ;
if ( ! F_186 ( V_145 ) && ( V_147 & V_149 ) )
for ( V_47 = 0 ; V_47 < ( 1 << V_46 ) ; V_47 ++ )
F_192 ( V_1 + V_47 ) ;
if ( V_46 && ( V_147 & V_150 ) )
F_43 ( V_1 , V_46 ) ;
F_193 ( V_1 , V_46 , V_147 ) ;
if ( V_148 & V_151 )
F_194 ( V_1 ) ;
else
F_195 ( V_1 ) ;
return 0 ;
}
static inline
struct V_1 * F_196 ( struct V_25 * V_25 , unsigned int V_46 ,
int V_3 )
{
unsigned int V_152 ;
struct V_72 * V_141 ;
struct V_1 * V_1 ;
for ( V_152 = V_46 ; V_152 < V_58 ; ++ V_152 ) {
V_141 = & ( V_25 -> V_72 [ V_152 ] ) ;
V_1 = F_197 ( & V_141 -> V_77 [ V_3 ] ,
struct V_1 , V_62 ) ;
if ( ! V_1 )
continue;
F_85 ( & V_1 -> V_62 ) ;
F_70 ( V_1 ) ;
V_141 -> V_73 -- ;
F_183 ( V_25 , V_1 , V_46 , V_152 , V_141 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_198 ( struct V_25 * V_25 ,
unsigned int V_46 )
{
return F_196 ( V_25 , V_46 , V_137 ) ;
}
static inline struct V_1 * F_198 ( struct V_25 * V_25 ,
unsigned int V_46 ) { return NULL ; }
int F_199 ( struct V_25 * V_25 ,
struct V_1 * V_114 , struct V_1 * V_115 ,
int V_3 )
{
struct V_1 * V_1 ;
unsigned int V_46 ;
int V_153 = 0 ;
#ifndef F_200
F_81 ( F_28 ( V_114 ) != F_28 ( V_115 ) ) ;
#endif
for ( V_1 = V_114 ; V_1 <= V_115 ; ) {
F_76 ( F_201 ( V_1 ) != F_25 ( V_25 ) , V_1 ) ;
if ( ! F_27 ( F_20 ( V_1 ) ) ) {
V_1 ++ ;
continue;
}
if ( ! F_78 ( V_1 ) ) {
V_1 ++ ;
continue;
}
V_46 = F_74 ( V_1 ) ;
F_202 ( & V_1 -> V_62 ,
& V_25 -> V_72 [ V_46 ] . V_77 [ V_3 ] ) ;
V_1 += 1 << V_46 ;
V_153 += 1 << V_46 ;
}
return V_153 ;
}
int F_203 ( struct V_25 * V_25 , struct V_1 * V_1 ,
int V_3 )
{
unsigned long V_29 , V_102 ;
struct V_1 * V_114 , * V_115 ;
V_29 = F_20 ( V_1 ) ;
V_29 = V_29 & ~ ( V_118 - 1 ) ;
V_114 = F_120 ( V_29 ) ;
V_115 = V_114 + V_118 - 1 ;
V_102 = V_29 + V_118 - 1 ;
if ( ! F_22 ( V_25 , V_29 ) )
V_114 = V_1 ;
if ( ! F_22 ( V_25 , V_102 ) )
return 0 ;
return F_199 ( V_25 , V_114 , V_115 , V_3 ) ;
}
static void F_204 ( struct V_1 * V_154 ,
int V_155 , int V_3 )
{
int V_156 = 1 << ( V_155 - V_138 ) ;
while ( V_156 -- ) {
F_16 ( V_154 , V_3 ) ;
V_154 += V_118 ;
}
}
static bool F_205 ( unsigned int V_46 , int V_157 )
{
if ( V_46 >= V_138 )
return true ;
if ( V_46 >= V_138 / 2 ||
V_157 == V_158 ||
V_157 == V_22 ||
V_20 )
return true ;
return false ;
}
static void F_206 ( struct V_25 * V_25 , struct V_1 * V_1 ,
int V_159 )
{
unsigned int V_152 = F_74 ( V_1 ) ;
int V_160 ;
if ( V_152 >= V_138 ) {
F_204 ( V_1 , V_152 , V_159 ) ;
return;
}
V_160 = F_203 ( V_25 , V_1 , V_159 ) ;
if ( V_160 >= ( 1 << ( V_138 - 1 ) ) ||
V_20 )
F_16 ( V_1 , V_159 ) ;
}
int F_207 ( struct V_72 * V_141 , unsigned int V_46 ,
int V_3 , bool V_161 , bool * V_162 )
{
int V_47 ;
int V_163 ;
if ( V_141 -> V_73 == 0 )
return - 1 ;
* V_162 = false ;
for ( V_47 = 0 ; ; V_47 ++ ) {
V_163 = V_164 [ V_3 ] [ V_47 ] ;
if ( V_163 == V_165 )
break;
if ( F_99 ( & V_141 -> V_77 [ V_163 ] ) )
continue;
if ( F_205 ( V_46 , V_3 ) )
* V_162 = true ;
if ( ! V_161 )
return V_163 ;
if ( * V_162 )
return V_163 ;
}
return - 1 ;
}
static void F_208 ( struct V_1 * V_1 , struct V_25 * V_25 ,
unsigned int V_166 )
{
int V_93 ;
unsigned long V_167 , V_43 ;
V_167 = ( V_25 -> V_108 / 100 ) + V_118 ;
if ( V_25 -> V_168 >= V_167 )
return;
F_209 ( & V_25 -> V_88 , V_43 ) ;
if ( V_25 -> V_168 >= V_167 )
goto V_169;
V_93 = F_87 ( V_1 ) ;
if ( V_93 != V_170 &&
! F_67 ( V_93 ) && ! F_210 ( V_93 ) ) {
V_25 -> V_168 += V_118 ;
F_16 ( V_1 , V_170 ) ;
F_203 ( V_25 , V_1 , V_170 ) ;
}
V_169:
F_211 ( & V_25 -> V_88 , V_43 ) ;
}
static void F_212 ( const struct V_171 * V_172 )
{
struct V_173 * V_173 = V_172 -> V_173 ;
unsigned long V_43 ;
struct V_174 * V_175 ;
struct V_25 * V_25 ;
struct V_1 * V_1 ;
int V_46 ;
F_213 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
if ( V_25 -> V_168 <= V_118 )
continue;
F_209 ( & V_25 -> V_88 , V_43 ) ;
for ( V_46 = 0 ; V_46 < V_58 ; V_46 ++ ) {
struct V_72 * V_141 = & ( V_25 -> V_72 [ V_46 ] ) ;
V_1 = F_197 (
& V_141 -> V_77 [ V_170 ] ,
struct V_1 , V_62 ) ;
if ( ! V_1 )
continue;
V_25 -> V_168 -= F_158 ( V_118 ,
V_25 -> V_168 ) ;
F_16 ( V_1 , V_172 -> V_3 ) ;
F_203 ( V_25 , V_1 , V_172 -> V_3 ) ;
F_211 ( & V_25 -> V_88 , V_43 ) ;
return;
}
F_211 ( & V_25 -> V_88 , V_43 ) ;
}
}
static inline struct V_1 *
F_214 ( struct V_25 * V_25 , unsigned int V_46 , int V_176 )
{
struct V_72 * V_141 ;
unsigned int V_152 ;
struct V_1 * V_1 ;
int V_163 ;
bool V_162 ;
for ( V_152 = V_58 - 1 ;
V_152 >= V_46 && V_152 <= V_58 - 1 ;
-- V_152 ) {
V_141 = & ( V_25 -> V_72 [ V_152 ] ) ;
V_163 = F_207 ( V_141 , V_152 ,
V_176 , false , & V_162 ) ;
if ( V_163 == - 1 )
continue;
V_1 = F_215 ( & V_141 -> V_77 [ V_163 ] ,
struct V_1 , V_62 ) ;
if ( V_162 )
F_206 ( V_25 , V_1 , V_176 ) ;
V_141 -> V_73 -- ;
F_85 ( & V_1 -> V_62 ) ;
F_70 ( V_1 ) ;
F_183 ( V_25 , V_1 , V_46 , V_152 , V_141 ,
V_176 ) ;
F_2 ( V_1 , V_176 ) ;
F_216 ( V_1 , V_46 , V_152 ,
V_176 , V_163 ) ;
return V_1 ;
}
return NULL ;
}
static struct V_1 * F_217 ( struct V_25 * V_25 , unsigned int V_46 ,
int V_3 )
{
struct V_1 * V_1 ;
V_1 = F_196 ( V_25 , V_46 , V_3 ) ;
if ( F_17 ( ! V_1 ) ) {
if ( V_3 == V_121 )
V_1 = F_198 ( V_25 , V_46 ) ;
if ( ! V_1 )
V_1 = F_214 ( V_25 , V_46 , V_3 ) ;
}
F_218 ( V_1 , V_46 , V_3 ) ;
return V_1 ;
}
static int F_219 ( struct V_25 * V_25 , unsigned int V_46 ,
unsigned long V_82 , struct V_90 * V_91 ,
int V_3 , bool V_177 )
{
int V_47 ;
F_96 ( & V_25 -> V_88 ) ;
for ( V_47 = 0 ; V_47 < V_82 ; ++ V_47 ) {
struct V_1 * V_1 = F_217 ( V_25 , V_46 , V_3 ) ;
if ( F_17 ( V_1 == NULL ) )
break;
if ( F_83 ( ! V_177 ) )
F_89 ( & V_1 -> V_62 , V_91 ) ;
else
F_88 ( & V_1 -> V_62 , V_91 ) ;
V_91 = & V_1 -> V_62 ;
if ( F_210 ( F_1 ( V_1 ) ) )
F_98 ( V_25 , V_178 ,
- ( 1 << V_46 ) ) ;
}
F_98 ( V_25 , V_179 , - ( V_47 << V_46 ) ) ;
F_102 ( & V_25 -> V_88 ) ;
return V_47 ;
}
void F_220 ( struct V_25 * V_25 , struct V_83 * V_84 )
{
unsigned long V_43 ;
int V_180 , V_181 ;
F_142 ( V_43 ) ;
V_181 = F_221 ( V_84 -> V_181 ) ;
V_180 = F_158 ( V_84 -> V_82 , V_181 ) ;
if ( V_180 > 0 ) {
F_95 ( V_25 , V_180 , V_84 ) ;
V_84 -> V_82 -= V_180 ;
}
F_144 ( V_43 ) ;
}
static void F_222 ( unsigned int V_182 , struct V_25 * V_25 )
{
unsigned long V_43 ;
struct V_183 * V_184 ;
struct V_83 * V_84 ;
F_142 ( V_43 ) ;
V_184 = F_223 ( V_25 -> V_185 , V_182 ) ;
V_84 = & V_184 -> V_84 ;
if ( V_84 -> V_82 ) {
F_95 ( V_25 , V_84 -> V_82 , V_84 ) ;
V_84 -> V_82 = 0 ;
}
F_144 ( V_43 ) ;
}
static void F_224 ( unsigned int V_182 )
{
struct V_25 * V_25 ;
F_180 (zone) {
F_222 ( V_182 , V_25 ) ;
}
}
void F_225 ( struct V_25 * V_25 )
{
int V_182 = F_226 () ;
if ( V_25 )
F_222 ( V_182 , V_25 ) ;
else
F_224 ( V_182 ) ;
}
void F_227 ( struct V_25 * V_25 )
{
int V_182 ;
static T_5 V_186 ;
F_228 (cpu) {
struct V_183 * V_84 ;
struct V_25 * V_175 ;
bool V_187 = false ;
if ( V_25 ) {
V_84 = F_223 ( V_25 -> V_185 , V_182 ) ;
if ( V_84 -> V_84 . V_82 )
V_187 = true ;
} else {
F_180 (z) {
V_84 = F_223 ( V_175 -> V_185 , V_182 ) ;
if ( V_84 -> V_84 . V_82 ) {
V_187 = true ;
break;
}
}
}
if ( V_187 )
F_229 ( V_182 , & V_186 ) ;
else
F_230 ( V_182 , & V_186 ) ;
}
F_231 ( & V_186 , ( V_188 ) F_225 ,
V_25 , 1 ) ;
}
void F_232 ( struct V_25 * V_25 )
{
unsigned long V_12 , V_189 ;
unsigned long V_43 ;
unsigned int V_46 , V_190 ;
struct V_1 * V_1 ;
if ( F_233 ( V_25 ) )
return;
F_209 ( & V_25 -> V_88 , V_43 ) ;
V_189 = F_122 ( V_25 ) ;
for ( V_12 = V_25 -> V_30 ; V_12 < V_189 ; V_12 ++ )
if ( F_126 ( V_12 ) ) {
V_1 = F_120 ( V_12 ) ;
if ( ! F_234 ( V_1 ) )
F_235 ( V_1 ) ;
}
F_236 (order, t) {
F_237 (page,
&zone->free_area[order].free_list[t], lru) {
unsigned long V_47 ;
V_12 = F_20 ( V_1 ) ;
for ( V_47 = 0 ; V_47 < ( 1UL << V_46 ) ; V_47 ++ )
F_238 ( F_120 ( V_12 + V_47 ) ) ;
}
}
F_211 ( & V_25 -> V_88 , V_43 ) ;
}
void F_239 ( struct V_1 * V_1 , bool V_177 )
{
struct V_25 * V_25 = F_28 ( V_1 ) ;
struct V_83 * V_84 ;
unsigned long V_43 ;
unsigned long V_12 = F_20 ( V_1 ) ;
int V_3 ;
if ( ! F_128 ( V_1 , 0 ) )
return;
V_3 = F_104 ( V_1 , V_12 ) ;
F_2 ( V_1 , V_3 ) ;
F_142 ( V_43 ) ;
F_240 ( V_106 ) ;
if ( V_3 >= V_21 ) {
if ( F_17 ( F_67 ( V_3 ) ) ) {
F_103 ( V_25 , V_1 , V_12 , 0 , V_3 ) ;
goto V_39;
}
V_3 = V_121 ;
}
V_84 = & F_241 ( V_25 -> V_185 ) -> V_84 ;
if ( ! V_177 )
F_89 ( & V_1 -> V_62 , & V_84 -> V_92 [ V_3 ] ) ;
else
F_88 ( & V_1 -> V_62 , & V_84 -> V_92 [ V_3 ] ) ;
V_84 -> V_82 ++ ;
if ( V_84 -> V_82 >= V_84 -> V_140 ) {
unsigned long V_181 = F_221 ( V_84 -> V_181 ) ;
F_95 ( V_25 , V_181 , V_84 ) ;
V_84 -> V_82 -= V_181 ;
}
V_39:
F_144 ( V_43 ) ;
}
void F_242 ( struct V_90 * V_91 , bool V_177 )
{
struct V_1 * V_1 , * V_191 ;
F_243 (page, next, list, lru) {
F_244 ( V_1 , V_177 ) ;
F_239 ( V_1 , V_177 ) ;
}
}
void F_245 ( struct V_1 * V_1 , unsigned int V_46 )
{
int V_47 ;
T_4 V_192 ;
F_76 ( F_129 ( V_1 ) , V_1 ) ;
F_76 ( ! F_77 ( V_1 ) , V_1 ) ;
#ifdef F_246
if ( F_247 ( V_1 ) )
F_245 ( F_248 ( V_1 [ 0 ] . V_193 ) , V_46 ) ;
#endif
V_192 = F_249 ( V_1 ) ;
F_193 ( V_1 , 0 , V_192 ) ;
for ( V_47 = 1 ; V_47 < ( 1 << V_46 ) ; V_47 ++ ) {
F_148 ( V_1 + V_47 ) ;
F_193 ( V_1 + V_47 , 0 , V_192 ) ;
}
}
int F_250 ( struct V_1 * V_1 , unsigned int V_46 )
{
unsigned long V_194 ;
struct V_25 * V_25 ;
int V_93 ;
F_168 ( ! F_78 ( V_1 ) ) ;
V_25 = F_28 ( V_1 ) ;
V_93 = F_87 ( V_1 ) ;
if ( ! F_67 ( V_93 ) ) {
V_194 = F_251 ( V_25 ) + ( 1 << V_46 ) ;
if ( ! F_252 ( V_25 , 0 , V_194 , 0 , 0 ) )
return 0 ;
F_64 ( V_25 , - ( 1UL << V_46 ) , V_93 ) ;
}
F_85 ( & V_1 -> V_62 ) ;
V_25 -> V_72 [ V_46 ] . V_73 -- ;
F_70 ( V_1 ) ;
F_193 ( V_1 , V_46 , V_195 ) ;
if ( V_46 >= V_138 - 1 ) {
struct V_1 * V_196 = V_1 + ( 1 << V_46 ) - 1 ;
for (; V_1 < V_196 ; V_1 += V_118 ) {
int V_93 = F_87 ( V_1 ) ;
if ( ! F_67 ( V_93 ) && ! F_210 ( V_93 ) )
F_16 ( V_1 ,
V_121 ) ;
}
}
return 1UL << V_46 ;
}
int F_253 ( struct V_1 * V_1 )
{
unsigned int V_46 ;
int V_48 ;
V_46 = F_74 ( V_1 ) ;
V_48 = F_250 ( V_1 , V_46 ) ;
if ( ! V_48 )
return 0 ;
F_148 ( V_1 ) ;
F_245 ( V_1 , V_46 ) ;
return V_48 ;
}
static inline
struct V_1 * F_254 ( struct V_25 * V_197 ,
struct V_25 * V_25 , unsigned int V_46 ,
T_4 V_147 , int V_148 , int V_3 )
{
unsigned long V_43 ;
struct V_1 * V_1 ;
bool V_177 = ( ( V_147 & V_198 ) != 0 ) ;
if ( F_83 ( V_46 == 0 ) ) {
struct V_83 * V_84 ;
struct V_90 * V_91 ;
F_142 ( V_43 ) ;
V_84 = & F_241 ( V_25 -> V_185 ) -> V_84 ;
V_91 = & V_84 -> V_92 [ V_3 ] ;
if ( F_99 ( V_91 ) ) {
V_84 -> V_82 += F_219 ( V_25 , 0 ,
V_84 -> V_181 , V_91 ,
V_3 , V_177 ) ;
if ( F_17 ( F_99 ( V_91 ) ) )
goto V_199;
}
if ( V_177 )
V_1 = F_100 ( V_91 , struct V_1 , V_62 ) ;
else
V_1 = F_215 ( V_91 , struct V_1 , V_62 ) ;
F_85 ( & V_1 -> V_62 ) ;
V_84 -> V_82 -- ;
} else {
F_255 ( ( V_147 & V_200 ) && ( V_46 > 1 ) ) ;
F_209 ( & V_25 -> V_88 , V_43 ) ;
V_1 = NULL ;
if ( V_148 & V_201 ) {
V_1 = F_196 ( V_25 , V_46 , V_170 ) ;
if ( V_1 )
F_218 ( V_1 , V_46 , V_3 ) ;
}
if ( ! V_1 )
V_1 = F_217 ( V_25 , V_46 , V_3 ) ;
F_102 ( & V_25 -> V_88 ) ;
if ( ! V_1 )
goto V_199;
F_64 ( V_25 , - ( 1 << V_46 ) ,
F_1 ( V_1 ) ) ;
}
F_98 ( V_25 , V_202 , - ( 1 << V_46 ) ) ;
if ( F_256 ( & V_25 -> V_203 [ V_202 ] ) <= 0 &&
! F_257 ( V_204 , & V_25 -> V_43 ) )
F_258 ( V_204 , & V_25 -> V_43 ) ;
F_259 ( V_205 , V_25 , 1 << V_46 ) ;
F_260 ( V_197 , V_25 , V_147 ) ;
F_144 ( V_43 ) ;
F_76 ( F_29 ( V_25 , V_1 ) , V_1 ) ;
return V_1 ;
V_199:
F_144 ( V_43 ) ;
return NULL ;
}
static int T_3 F_261 ( char * V_206 )
{
return F_262 ( & V_207 . V_208 , V_206 ) ;
}
static bool F_263 ( T_4 V_192 , unsigned int V_46 )
{
if ( V_46 < V_207 . V_209 )
return false ;
if ( V_192 & V_200 )
return false ;
if ( V_207 . V_210 && ( V_192 & V_211 ) )
return false ;
if ( V_207 . V_212 &&
( V_192 & V_213 ) )
return false ;
return F_264 ( & V_207 . V_208 , 1 << V_46 ) ;
}
static int T_3 F_265 ( void )
{
T_6 V_214 = V_215 | V_216 | V_217 ;
struct V_218 * V_219 ;
V_219 = F_266 ( L_22 , NULL ,
& V_207 . V_208 ) ;
if ( F_267 ( V_219 ) )
return F_268 ( V_219 ) ;
if ( ! F_269 ( L_23 , V_214 , V_219 ,
& V_207 . V_212 ) )
goto V_220;
if ( ! F_269 ( L_24 , V_214 , V_219 ,
& V_207 . V_210 ) )
goto V_220;
if ( ! F_270 ( L_25 , V_214 , V_219 ,
& V_207 . V_209 ) )
goto V_220;
return 0 ;
V_220:
F_271 ( V_219 ) ;
return - V_221 ;
}
static inline bool F_263 ( T_4 V_192 , unsigned int V_46 )
{
return false ;
}
static bool F_272 ( struct V_25 * V_175 , unsigned int V_46 ,
unsigned long V_222 , int V_223 , int V_148 ,
long V_224 )
{
long F_158 = V_222 ;
int V_225 ;
const int V_226 = ( V_148 & V_201 ) ;
V_224 -= ( 1 << V_46 ) - 1 ;
if ( V_148 & V_227 )
F_158 -= F_158 / 2 ;
if ( F_83 ( ! V_226 ) )
V_224 -= V_175 -> V_168 ;
else
F_158 -= F_158 / 4 ;
#ifdef F_273
if ( ! ( V_148 & V_228 ) )
V_224 -= F_97 ( V_175 , V_178 ) ;
#endif
if ( V_224 <= F_158 + V_175 -> V_229 [ V_223 ] )
return false ;
if ( ! V_46 )
return true ;
for ( V_225 = V_46 ; V_225 < V_58 ; V_225 ++ ) {
struct V_72 * V_141 = & V_175 -> V_72 [ V_225 ] ;
int V_93 ;
if ( ! V_141 -> V_73 )
continue;
if ( V_226 )
return true ;
for ( V_93 = 0 ; V_93 < V_21 ; V_93 ++ ) {
if ( ! F_99 ( & V_141 -> V_77 [ V_93 ] ) )
return true ;
}
#ifdef F_273
if ( ( V_148 & V_228 ) &&
! F_99 ( & V_141 -> V_77 [ V_137 ] ) ) {
return true ;
}
#endif
}
return false ;
}
bool F_252 ( struct V_25 * V_175 , unsigned int V_46 , unsigned long V_222 ,
int V_223 , int V_148 )
{
return F_272 ( V_175 , V_46 , V_222 , V_223 , V_148 ,
F_97 ( V_175 , V_179 ) ) ;
}
bool F_274 ( struct V_25 * V_175 , unsigned int V_46 ,
unsigned long V_222 , int V_223 )
{
long V_224 = F_97 ( V_175 , V_179 ) ;
if ( V_175 -> V_230 && V_224 < V_175 -> V_230 )
V_224 = F_275 ( V_175 , V_179 ) ;
return F_272 ( V_175 , V_46 , V_222 , V_223 , 0 ,
V_224 ) ;
}
static bool F_276 ( struct V_25 * V_231 , struct V_25 * V_25 )
{
return V_231 -> V_111 == V_25 -> V_111 ;
}
static bool F_277 ( struct V_25 * V_231 , struct V_25 * V_25 )
{
return F_278 ( F_25 ( V_231 ) , F_25 ( V_25 ) ) <
V_232 ;
}
static bool F_276 ( struct V_25 * V_231 , struct V_25 * V_25 )
{
return true ;
}
static bool F_277 ( struct V_25 * V_231 , struct V_25 * V_25 )
{
return true ;
}
static void F_279 ( struct V_25 * V_197 )
{
struct V_25 * V_25 = V_197 -> V_233 -> V_99 ;
do {
F_280 ( V_25 , V_202 ,
F_281 ( V_25 ) - F_251 ( V_25 ) -
F_256 ( & V_25 -> V_203 [ V_202 ] ) ) ;
F_282 ( V_204 , & V_25 -> V_43 ) ;
} while ( V_25 ++ != V_197 );
}
static struct V_1 *
F_283 ( T_4 V_192 , unsigned int V_46 , int V_148 ,
const struct V_171 * V_172 )
{
struct V_173 * V_173 = V_172 -> V_173 ;
struct V_174 * V_175 ;
struct V_1 * V_1 = NULL ;
struct V_25 * V_25 ;
int V_234 = 0 ;
bool V_235 ;
V_236:
V_235 = false ;
F_213 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_222 ;
if ( F_284 () &&
( V_148 & V_237 ) &&
! F_285 ( V_25 , V_192 ) )
continue;
if ( V_148 & V_238 ) {
if ( ! F_276 ( V_172 -> V_197 , V_25 ) )
break;
if ( F_257 ( V_204 , & V_25 -> V_43 ) ) {
V_234 ++ ;
continue;
}
}
if ( V_172 -> V_239 && ! F_286 ( V_25 ) )
continue;
V_222 = V_25 -> V_194 [ V_148 & V_240 ] ;
if ( ! F_252 ( V_25 , V_46 , V_222 ,
V_172 -> V_223 , V_148 ) ) {
int V_26 ;
F_106 ( V_151 < V_241 ) ;
if ( V_148 & V_151 )
goto V_242;
if ( V_243 == 0 ||
! F_277 ( V_172 -> V_197 , V_25 ) )
continue;
V_26 = F_287 ( V_25 , V_192 , V_46 ) ;
switch ( V_26 ) {
case V_244 :
continue;
case V_245 :
continue;
default:
if ( F_252 ( V_25 , V_46 , V_222 ,
V_172 -> V_223 , V_148 ) )
goto V_242;
continue;
}
}
V_242:
V_1 = F_254 ( V_172 -> V_197 , V_25 , V_46 ,
V_192 , V_148 , V_172 -> V_3 ) ;
if ( V_1 ) {
if ( F_188 ( V_1 , V_46 , V_192 , V_148 ) )
goto V_242;
if ( F_17 ( V_46 && ( V_148 & V_201 ) ) )
F_208 ( V_1 , V_25 , V_46 ) ;
return V_1 ;
}
}
if ( V_148 & V_238 ) {
V_148 &= ~ V_238 ;
if ( V_234 ) {
V_235 = true ;
F_279 ( V_172 -> V_197 ) ;
}
if ( V_246 > 1 )
V_235 = true ;
}
if ( V_235 )
goto V_236;
return NULL ;
}
static inline bool F_288 ( void )
{
bool V_26 = false ;
#if V_247 > 8
V_26 = F_289 () ;
#endif
return V_26 ;
}
void F_290 ( T_4 V_192 , unsigned int V_46 , const char * V_248 , ... )
{
unsigned int V_249 = V_250 ;
if ( ( V_192 & V_251 ) || ! F_291 ( & V_252 ) ||
F_184 () > 0 )
return;
if ( ! ( V_192 & V_253 ) )
if ( F_292 ( V_254 ) ||
( V_41 -> V_43 & ( V_255 | V_256 ) ) )
V_249 &= ~ V_250 ;
if ( F_289 () || ! ( V_192 & V_213 ) )
V_249 &= ~ V_250 ;
if ( V_248 ) {
struct V_257 V_258 ;
T_7 args ;
va_start ( args , V_248 ) ;
V_258 . V_248 = V_248 ;
V_258 . V_259 = & args ;
F_293 ( L_26 , & V_258 ) ;
va_end ( args ) ;
}
F_293 ( L_27 ,
V_41 -> V_42 , V_46 , V_192 , & V_192 ) ;
F_38 () ;
if ( ! F_288 () )
F_294 ( V_249 ) ;
}
static inline struct V_1 *
F_295 ( T_4 V_192 , unsigned int V_46 ,
const struct V_171 * V_172 , unsigned long * V_260 )
{
struct V_261 V_262 = {
. V_173 = V_172 -> V_173 ,
. V_263 = V_172 -> V_263 ,
. V_192 = V_192 ,
. V_46 = V_46 ,
} ;
struct V_1 * V_1 ;
* V_260 = 0 ;
if ( ! F_296 ( & V_264 ) ) {
* V_260 = 1 ;
F_297 ( 1 ) ;
return NULL ;
}
V_1 = F_283 ( V_192 | V_265 , V_46 ,
V_266 | V_237 , V_172 ) ;
if ( V_1 )
goto V_39;
if ( ! ( V_192 & V_200 ) ) {
if ( V_41 -> V_43 & V_267 )
goto V_39;
if ( V_46 > V_268 )
goto V_39;
if ( V_172 -> V_269 < V_270 )
goto V_39;
if ( ! ( V_192 & V_8 ) ) {
* V_260 = ! V_271 ;
goto V_39;
}
if ( F_7 () )
goto V_39;
if ( V_192 & V_272 )
goto V_39;
}
if ( F_298 ( & V_262 ) || F_255 ( V_192 & V_200 ) ) {
* V_260 = 1 ;
if ( V_192 & V_200 ) {
V_1 = F_283 ( V_192 , V_46 ,
V_151 | V_237 , V_172 ) ;
if ( ! V_1 )
V_1 = F_283 ( V_192 , V_46 ,
V_151 , V_172 ) ;
}
}
V_39:
F_299 ( & V_264 ) ;
return V_1 ;
}
static struct V_1 *
F_300 ( T_4 V_192 , unsigned int V_46 ,
int V_148 , const struct V_171 * V_172 ,
enum V_273 V_214 , int * V_274 ,
bool * V_275 )
{
unsigned long V_276 ;
struct V_1 * V_1 ;
if ( ! V_46 )
return NULL ;
V_41 -> V_43 |= V_255 ;
V_276 = F_301 ( V_192 , V_46 , V_148 , V_172 ,
V_214 , V_274 ) ;
V_41 -> V_43 &= ~ V_255 ;
switch ( V_276 ) {
case V_277 :
* V_275 = true ;
case V_278 :
return NULL ;
default:
break;
}
F_302 ( V_279 ) ;
V_1 = F_283 ( V_192 , V_46 ,
V_148 & ~ V_151 , V_172 ) ;
if ( V_1 ) {
struct V_25 * V_25 = F_28 ( V_1 ) ;
V_25 -> V_280 = false ;
F_303 ( V_25 , V_46 , true ) ;
F_302 ( V_281 ) ;
return V_1 ;
}
F_302 ( V_282 ) ;
F_170 () ;
return NULL ;
}
static inline struct V_1 *
F_300 ( T_4 V_192 , unsigned int V_46 ,
int V_148 , const struct V_171 * V_172 ,
enum V_273 V_214 , int * V_274 ,
bool * V_275 )
{
return NULL ;
}
static int
F_304 ( T_4 V_192 , unsigned int V_46 ,
const struct V_171 * V_172 )
{
struct V_283 V_283 ;
int V_284 ;
F_170 () ;
F_305 () ;
V_41 -> V_43 |= V_255 ;
F_306 ( V_192 ) ;
V_283 . V_285 = 0 ;
V_41 -> V_283 = & V_283 ;
V_284 = F_307 ( V_172 -> V_173 , V_46 , V_192 ,
V_172 -> V_263 ) ;
V_41 -> V_283 = NULL ;
F_308 () ;
V_41 -> V_43 &= ~ V_255 ;
F_170 () ;
return V_284 ;
}
static inline struct V_1 *
F_309 ( T_4 V_192 , unsigned int V_46 ,
int V_148 , const struct V_171 * V_172 ,
unsigned long * V_260 )
{
struct V_1 * V_1 = NULL ;
bool V_286 = false ;
* V_260 = F_304 ( V_192 , V_46 , V_172 ) ;
if ( F_17 ( ! ( * V_260 ) ) )
return NULL ;
V_287:
V_1 = F_283 ( V_192 , V_46 ,
V_148 & ~ V_151 , V_172 ) ;
if ( ! V_1 && ! V_286 ) {
F_212 ( V_172 ) ;
F_227 ( NULL ) ;
V_286 = true ;
goto V_287;
}
return V_1 ;
}
static void F_310 ( unsigned int V_46 , const struct V_171 * V_172 )
{
struct V_174 * V_175 ;
struct V_25 * V_25 ;
F_213 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_311 ( V_25 , V_46 , F_312 ( V_172 -> V_197 ) ) ;
}
static inline int
F_313 ( T_4 V_192 )
{
int V_148 = V_288 | V_237 ;
F_106 ( V_289 != ( V_290 T_4 ) V_227 ) ;
V_148 |= ( V_290 int ) ( V_192 & V_289 ) ;
if ( V_192 & V_291 ) {
if ( ! ( V_192 & V_253 ) )
V_148 |= V_201 ;
V_148 &= ~ V_237 ;
} else if ( F_17 ( F_314 ( V_41 ) ) && ! F_289 () )
V_148 |= V_201 ;
if ( F_83 ( ! ( V_192 & V_253 ) ) ) {
if ( V_192 & V_292 )
V_148 |= V_151 ;
else if ( F_315 () && ( V_41 -> V_43 & V_255 ) )
V_148 |= V_151 ;
else if ( ! F_289 () &&
( ( V_41 -> V_43 & V_255 ) ||
F_17 ( F_292 ( V_254 ) ) ) )
V_148 |= V_151 ;
}
#ifdef F_273
if ( F_316 ( V_192 ) == V_121 )
V_148 |= V_228 ;
#endif
return V_148 ;
}
bool F_317 ( T_4 V_192 )
{
return ! ! ( F_313 ( V_192 ) & V_151 ) ;
}
static inline bool F_318 ( T_4 V_192 )
{
return ( V_192 & ( V_293 | V_294 ) ) == V_293 ;
}
static inline struct V_1 *
F_319 ( T_4 V_192 , unsigned int V_46 ,
struct V_171 * V_172 )
{
bool V_295 = V_192 & V_213 ;
struct V_1 * V_1 = NULL ;
int V_148 ;
unsigned long V_296 = 0 ;
unsigned long V_260 ;
enum V_273 V_297 = V_298 ;
bool V_275 = false ;
int V_274 = V_299 ;
if ( V_46 >= V_58 ) {
F_255 ( ! ( V_192 & V_251 ) ) ;
return NULL ;
}
if ( F_255 ( ( V_192 & ( V_291 | V_213 ) ) ==
( V_291 | V_213 ) ) )
V_192 &= ~ V_291 ;
V_287:
if ( V_192 & V_294 )
F_310 ( V_46 , V_172 ) ;
V_148 = F_313 ( V_192 ) ;
if ( ! ( V_148 & V_237 ) && ! V_172 -> V_263 ) {
struct V_174 * V_300 ;
V_300 = F_320 ( V_172 -> V_173 ,
V_172 -> V_269 , NULL , & V_172 -> V_197 ) ;
V_172 -> V_223 = F_321 ( V_300 ) ;
}
V_1 = F_283 ( V_192 , V_46 ,
V_148 & ~ V_151 , V_172 ) ;
if ( V_1 )
goto V_301;
if ( V_148 & V_151 ) {
V_172 -> V_173 = F_322 ( F_323 () , V_192 ) ;
V_1 = F_283 ( V_192 , V_46 ,
V_151 , V_172 ) ;
if ( V_1 )
goto V_301;
}
if ( ! V_295 ) {
F_255 ( V_192 & V_200 ) ;
goto V_302;
}
if ( V_41 -> V_43 & V_255 ) {
if ( F_255 ( V_192 & V_200 ) ) {
F_170 () ;
goto V_287;
}
goto V_302;
}
if ( F_292 ( V_254 ) && ! ( V_192 & V_200 ) )
goto V_302;
V_1 = F_300 ( V_192 , V_46 , V_148 , V_172 ,
V_297 ,
& V_274 ,
& V_275 ) ;
if ( V_1 )
goto V_301;
if ( F_318 ( V_192 ) ) {
if ( V_275 )
goto V_302;
if ( V_274 == V_303 )
goto V_302;
if ( V_274 == V_304
&& ! ( V_41 -> V_43 & V_305 ) )
goto V_302;
}
if ( ! F_318 ( V_192 ) || ( V_41 -> V_43 & V_305 ) )
V_297 = V_306 ;
V_1 = F_309 ( V_192 , V_46 , V_148 , V_172 ,
& V_260 ) ;
if ( V_1 )
goto V_301;
if ( V_192 & V_307 )
goto V_308;
V_296 += V_260 ;
if ( ( V_260 && V_46 <= V_268 ) ||
( ( V_192 & V_309 ) && V_296 < ( 1 << V_46 ) ) ) {
F_324 ( V_172 -> V_197 , V_310 , V_40 / 50 ) ;
goto V_287;
}
V_1 = F_295 ( V_192 , V_46 , V_172 , & V_260 ) ;
if ( V_1 )
goto V_301;
if ( V_260 )
goto V_287;
V_308:
V_1 = F_300 ( V_192 , V_46 , V_148 ,
V_172 , V_297 ,
& V_274 ,
& V_275 ) ;
if ( V_1 )
goto V_301;
V_302:
F_290 ( V_192 , V_46 , NULL ) ;
V_301:
return V_1 ;
}
struct V_1 *
F_325 ( T_4 V_192 , unsigned int V_46 ,
struct V_173 * V_173 , T_8 * V_263 )
{
struct V_174 * V_300 ;
struct V_1 * V_1 = NULL ;
unsigned int V_311 ;
int V_148 = V_312 | V_237 | V_238 ;
T_4 V_313 ;
struct V_171 V_172 = {
. V_269 = F_326 ( V_192 ) ,
. V_263 = V_263 ,
. V_3 = F_316 ( V_192 ) ,
} ;
V_192 &= V_6 ;
F_327 ( V_192 ) ;
F_328 ( V_192 & V_213 ) ;
if ( F_263 ( V_192 , V_46 ) )
return NULL ;
if ( F_17 ( ! V_173 -> V_314 -> V_25 ) )
return NULL ;
if ( F_107 ( F_273 ) && V_172 . V_3 == V_121 )
V_148 |= V_228 ;
V_315:
V_311 = F_329 () ;
V_172 . V_173 = V_173 ;
V_172 . V_239 = ( V_192 & V_316 ) ;
V_300 = F_320 ( V_172 . V_173 , V_172 . V_269 ,
V_172 . V_263 ? : & V_317 ,
& V_172 . V_197 ) ;
if ( ! V_172 . V_197 )
goto V_39;
V_172 . V_223 = F_321 ( V_300 ) ;
V_313 = V_192 | V_265 ;
V_1 = F_283 ( V_313 , V_46 , V_148 , & V_172 ) ;
if ( F_17 ( ! V_1 ) ) {
V_313 = F_330 ( V_192 ) ;
V_172 . V_239 = false ;
V_1 = F_319 ( V_313 , V_46 , & V_172 ) ;
}
if ( V_318 && V_1 )
F_331 ( V_1 , V_46 , V_192 ) ;
F_332 ( V_1 , V_46 , V_313 , V_172 . V_3 ) ;
V_39:
if ( F_17 ( ! V_1 && F_333 ( V_311 ) ) )
goto V_315;
return V_1 ;
}
unsigned long F_334 ( T_4 V_192 , unsigned int V_46 )
{
struct V_1 * V_1 ;
F_81 ( ( V_192 & V_211 ) != 0 ) ;
V_1 = F_335 ( V_192 , V_46 ) ;
if ( ! V_1 )
return 0 ;
return ( unsigned long ) F_137 ( V_1 ) ;
}
unsigned long F_336 ( T_4 V_192 )
{
return F_334 ( V_192 | V_149 , 0 ) ;
}
void F_149 ( struct V_1 * V_1 , unsigned int V_46 )
{
if ( F_337 ( V_1 ) ) {
if ( V_46 == 0 )
F_239 ( V_1 , false ) ;
else
F_41 ( V_1 , V_46 ) ;
}
}
void V_224 ( unsigned long V_319 , unsigned int V_46 )
{
if ( V_319 != 0 ) {
F_81 ( ! F_338 ( ( void * ) V_319 ) ) ;
F_149 ( F_248 ( ( void * ) V_319 ) , V_46 ) ;
}
}
static struct V_1 * F_339 ( struct V_320 * V_321 ,
T_4 V_192 )
{
struct V_1 * V_1 = NULL ;
T_4 V_322 = V_192 ;
#if ( V_105 < V_323 )
V_192 |= V_150 | V_251 | V_307 |
V_253 ;
V_1 = F_340 ( V_324 , V_192 ,
V_325 ) ;
V_321 -> V_142 = V_1 ? V_323 : V_105 ;
#endif
if ( F_17 ( ! V_1 ) )
V_1 = F_340 ( V_324 , V_322 , 0 ) ;
V_321 -> V_259 = V_1 ? F_137 ( V_1 ) : NULL ;
return V_1 ;
}
void * F_341 ( struct V_320 * V_321 ,
unsigned int V_326 , T_4 V_192 )
{
unsigned int V_142 = V_105 ;
struct V_1 * V_1 ;
int V_327 ;
if ( F_17 ( ! V_321 -> V_259 ) ) {
V_328:
V_1 = F_339 ( V_321 , V_192 ) ;
if ( ! V_1 )
return NULL ;
#if ( V_105 < V_323 )
V_142 = V_321 -> V_142 ;
#endif
F_342 ( V_1 , V_142 - 1 ) ;
V_321 -> V_329 = F_343 ( V_1 ) ;
V_321 -> V_330 = V_142 ;
V_321 -> V_327 = V_142 ;
}
V_327 = V_321 -> V_327 - V_326 ;
if ( F_17 ( V_327 < 0 ) ) {
V_1 = F_248 ( V_321 -> V_259 ) ;
if ( ! F_344 ( V_1 , V_321 -> V_330 ) )
goto V_328;
#if ( V_105 < V_323 )
V_142 = V_321 -> V_142 ;
#endif
F_47 ( V_1 , V_142 ) ;
V_321 -> V_330 = V_142 ;
V_327 = V_142 - V_326 ;
}
V_321 -> V_330 -- ;
V_321 -> V_327 = V_327 ;
return V_321 -> V_259 + V_327 ;
}
void F_345 ( void * V_319 )
{
struct V_1 * V_1 = F_346 ( V_319 ) ;
if ( F_17 ( F_337 ( V_1 ) ) )
F_41 ( V_1 , F_42 ( V_1 ) ) ;
}
struct V_1 * F_347 ( T_4 V_192 , unsigned int V_46 )
{
struct V_1 * V_1 ;
V_1 = F_335 ( V_192 , V_46 ) ;
if ( V_1 && F_348 ( V_1 , V_192 , V_46 ) != 0 ) {
F_149 ( V_1 , V_46 ) ;
V_1 = NULL ;
}
return V_1 ;
}
struct V_1 * F_349 ( int V_13 , T_4 V_192 , unsigned int V_46 )
{
struct V_1 * V_1 ;
V_1 = F_340 ( V_13 , V_192 , V_46 ) ;
if ( V_1 && F_348 ( V_1 , V_192 , V_46 ) != 0 ) {
F_149 ( V_1 , V_46 ) ;
V_1 = NULL ;
}
return V_1 ;
}
void F_350 ( struct V_1 * V_1 , unsigned int V_46 )
{
F_351 ( V_1 , V_46 ) ;
F_149 ( V_1 , V_46 ) ;
}
void F_352 ( unsigned long V_319 , unsigned int V_46 )
{
if ( V_319 != 0 ) {
F_81 ( ! F_338 ( ( void * ) V_319 ) ) ;
F_350 ( F_248 ( ( void * ) V_319 ) , V_46 ) ;
}
}
static void * F_353 ( unsigned long V_319 , unsigned int V_46 ,
T_9 V_142 )
{
if ( V_319 ) {
unsigned long V_331 = V_319 + ( V_105 << V_46 ) ;
unsigned long V_332 = V_319 + F_354 ( V_142 ) ;
F_245 ( F_248 ( ( void * ) V_319 ) , V_46 ) ;
while ( V_332 < V_331 ) {
F_355 ( V_332 ) ;
V_332 += V_105 ;
}
}
return ( void * ) V_319 ;
}
void * F_356 ( T_9 V_142 , T_4 V_192 )
{
unsigned int V_46 = F_357 ( V_142 ) ;
unsigned long V_319 ;
V_319 = F_334 ( V_192 , V_46 ) ;
return F_353 ( V_319 , V_46 , V_142 ) ;
}
void * T_2 F_358 ( int V_13 , T_9 V_142 , T_4 V_192 )
{
unsigned int V_46 = F_357 ( V_142 ) ;
struct V_1 * V_50 = F_340 ( V_13 , V_192 , V_46 ) ;
if ( ! V_50 )
return NULL ;
return F_353 ( ( unsigned long ) F_137 ( V_50 ) , V_46 , V_142 ) ;
}
void F_359 ( void * V_333 , T_9 V_142 )
{
unsigned long V_319 = ( unsigned long ) V_333 ;
unsigned long V_101 = V_319 + F_354 ( V_142 ) ;
while ( V_319 < V_101 ) {
F_355 ( V_319 ) ;
V_319 += V_105 ;
}
}
static unsigned long F_360 ( int V_327 )
{
struct V_174 * V_175 ;
struct V_25 * V_25 ;
unsigned long V_334 = 0 ;
struct V_173 * V_173 = F_322 ( F_323 () , V_335 ) ;
F_361 (zone, z, zonelist, offset) {
unsigned long V_142 = V_25 -> V_108 ;
unsigned long V_140 = F_281 ( V_25 ) ;
if ( V_142 > V_140 )
V_334 += V_142 - V_140 ;
}
return V_334 ;
}
unsigned long F_362 ( void )
{
return F_360 ( F_326 ( V_336 ) ) ;
}
unsigned long F_363 ( void )
{
return F_360 ( F_326 ( V_337 ) ) ;
}
static inline void F_364 ( struct V_25 * V_25 )
{
if ( F_107 ( V_338 ) )
F_365 ( L_28 , F_25 ( V_25 ) ) ;
}
long F_366 ( void )
{
long V_339 ;
unsigned long V_340 ;
unsigned long V_341 = 0 ;
unsigned long V_160 [ V_342 ] ;
struct V_25 * V_25 ;
int V_62 ;
for ( V_62 = V_343 ; V_62 < V_342 ; V_62 ++ )
V_160 [ V_62 ] = F_367 ( V_344 + V_62 ) ;
F_368 (zone)
V_341 += V_25 -> V_194 [ V_345 ] ;
V_339 = F_367 ( V_179 ) - V_346 ;
V_340 = V_160 [ V_347 ] + V_160 [ V_348 ] ;
V_340 -= F_158 ( V_340 / 2 , V_341 ) ;
V_339 += V_340 ;
V_339 += F_367 ( V_349 ) -
F_158 ( F_367 ( V_349 ) / 2 , V_341 ) ;
if ( V_339 < 0 )
V_339 = 0 ;
return V_339 ;
}
void F_369 ( struct V_350 * V_351 )
{
V_351 -> V_352 = V_353 ;
V_351 -> V_354 = F_367 ( V_355 ) ;
V_351 -> V_356 = F_367 ( V_179 ) ;
V_351 -> V_357 = F_370 () ;
V_351 -> V_358 = V_359 ;
V_351 -> V_360 = F_371 () ;
V_351 -> V_361 = V_105 ;
}
void F_372 ( struct V_350 * V_351 , int V_13 )
{
int V_362 ;
unsigned long V_108 = 0 ;
T_1 * V_9 = F_10 ( V_13 ) ;
for ( V_362 = 0 ; V_362 < V_98 ; V_362 ++ )
V_108 += V_9 -> V_99 [ V_362 ] . V_108 ;
V_351 -> V_352 = V_108 ;
V_351 -> V_354 = F_373 ( V_13 , V_355 ) ;
V_351 -> V_356 = F_373 ( V_13 , V_179 ) ;
#ifdef F_374
V_351 -> V_358 = V_9 -> V_99 [ V_363 ] . V_108 ;
V_351 -> V_360 = F_97 ( & V_9 -> V_99 [ V_363 ] ,
V_179 ) ;
#else
V_351 -> V_358 = 0 ;
V_351 -> V_360 = 0 ;
#endif
V_351 -> V_361 = V_105 ;
}
bool F_375 ( unsigned int V_43 , int V_13 )
{
bool V_26 = false ;
unsigned int V_311 ;
if ( ! ( V_43 & V_250 ) )
goto V_39;
do {
V_311 = F_329 () ;
V_26 = ! F_376 ( V_13 , V_317 ) ;
} while ( F_333 ( V_311 ) );
V_39:
return V_26 ;
}
static void F_377 ( unsigned char type )
{
static const char V_364 [ V_165 ] = {
[ V_22 ] = 'U' ,
[ V_121 ] = 'M' ,
[ V_158 ] = 'E' ,
[ V_170 ] = 'H' ,
#ifdef F_273
[ V_137 ] = 'C' ,
#endif
#ifdef F_378
[ V_365 ] = 'I' ,
#endif
} ;
char V_366 [ V_165 + 1 ] ;
char * V_50 = V_366 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_165 ; V_47 ++ ) {
if ( type & ( 1 << V_47 ) )
* V_50 ++ = V_364 [ V_47 ] ;
}
* V_50 = '\0' ;
F_365 ( L_29 , V_366 ) ;
}
void F_379 ( unsigned int V_249 )
{
unsigned long V_367 = 0 ;
int V_182 ;
struct V_25 * V_25 ;
F_180 (zone) {
if ( F_375 ( V_249 , F_25 ( V_25 ) ) )
continue;
F_228 (cpu)
V_367 += F_223 ( V_25 -> V_185 , V_182 ) -> V_84 . V_82 ;
}
F_365 ( L_30
L_31
L_32
L_33
L_34
L_35 ,
F_367 ( V_368 ) ,
F_367 ( V_369 ) ,
F_367 ( V_370 ) ,
F_367 ( V_371 ) ,
F_367 ( V_372 ) ,
F_367 ( V_373 ) ,
F_367 ( V_374 ) ,
F_367 ( V_375 ) ,
F_367 ( V_376 ) ,
F_367 ( V_377 ) ,
F_367 ( V_349 ) ,
F_367 ( V_378 ) ,
F_367 ( V_379 ) ,
F_367 ( V_355 ) ,
F_367 ( V_380 ) ,
F_367 ( V_381 ) ,
F_367 ( V_179 ) ,
V_367 ,
F_367 ( V_178 ) ) ;
F_180 (zone) {
int V_47 ;
if ( F_375 ( V_249 , F_25 ( V_25 ) ) )
continue;
V_367 = 0 ;
F_228 (cpu)
V_367 += F_223 ( V_25 -> V_185 , V_182 ) -> V_84 . V_82 ;
F_364 ( V_25 ) ;
F_365 ( L_36
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
L_65
L_66
L_67 ,
V_25 -> V_32 ,
F_380 ( F_97 ( V_25 , V_179 ) ) ,
F_380 ( F_381 ( V_25 ) ) ,
F_380 ( F_251 ( V_25 ) ) ,
F_380 ( F_281 ( V_25 ) ) ,
F_380 ( F_97 ( V_25 , V_368 ) ) ,
F_380 ( F_97 ( V_25 , V_369 ) ) ,
F_380 ( F_97 ( V_25 , V_371 ) ) ,
F_380 ( F_97 ( V_25 , V_372 ) ) ,
F_380 ( F_97 ( V_25 , V_374 ) ) ,
F_380 ( F_97 ( V_25 , V_370 ) ) ,
F_380 ( F_97 ( V_25 , V_373 ) ) ,
F_380 ( V_25 -> V_382 ) ,
F_380 ( V_25 -> V_108 ) ,
F_380 ( F_97 ( V_25 , V_383 ) ) ,
F_380 ( F_97 ( V_25 , V_375 ) ) ,
F_380 ( F_97 ( V_25 , V_376 ) ) ,
F_380 ( F_97 ( V_25 , V_379 ) ) ,
F_380 ( F_97 ( V_25 , V_355 ) ) ,
F_380 ( F_97 ( V_25 , V_349 ) ) ,
F_380 ( F_97 ( V_25 , V_378 ) ) ,
F_97 ( V_25 , V_384 ) *
V_385 / 1024 ,
F_380 ( F_97 ( V_25 , V_380 ) ) ,
F_380 ( F_97 ( V_25 , V_377 ) ) ,
F_380 ( F_97 ( V_25 , V_381 ) ) ,
F_380 ( V_367 ) ,
F_380 ( F_382 ( V_25 -> V_185 -> V_84 . V_82 ) ) ,
F_380 ( F_97 ( V_25 , V_178 ) ) ,
F_380 ( F_97 ( V_25 , V_386 ) ) ,
F_380 ( F_97 ( V_25 , V_89 ) ) ,
( ! F_383 ( V_25 ) ? L_68 : L_69 )
) ;
F_365 ( L_70 ) ;
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ )
F_365 ( L_71 , V_25 -> V_229 [ V_47 ] ) ;
F_365 ( L_67 ) ;
}
F_180 (zone) {
unsigned int V_46 ;
unsigned long V_387 [ V_58 ] , V_43 , V_388 = 0 ;
unsigned char V_364 [ V_58 ] ;
if ( F_375 ( V_249 , F_25 ( V_25 ) ) )
continue;
F_364 ( V_25 ) ;
F_365 ( L_72 , V_25 -> V_32 ) ;
F_209 ( & V_25 -> V_88 , V_43 ) ;
for ( V_46 = 0 ; V_46 < V_58 ; V_46 ++ ) {
struct V_72 * V_141 = & V_25 -> V_72 [ V_46 ] ;
int type ;
V_387 [ V_46 ] = V_141 -> V_73 ;
V_388 += V_387 [ V_46 ] << V_46 ;
V_364 [ V_46 ] = 0 ;
for ( type = 0 ; type < V_165 ; type ++ ) {
if ( ! F_99 ( & V_141 -> V_77 [ type ] ) )
V_364 [ V_46 ] |= 1 << type ;
}
}
F_211 ( & V_25 -> V_88 , V_43 ) ;
for ( V_46 = 0 ; V_46 < V_58 ; V_46 ++ ) {
F_365 ( L_73 , V_387 [ V_46 ] , F_380 ( 1UL ) << V_46 ) ;
if ( V_387 [ V_46 ] )
F_377 ( V_364 [ V_46 ] ) ;
}
F_365 ( L_74 , F_380 ( V_388 ) ) ;
}
F_384 () ;
F_365 ( L_75 , F_367 ( V_389 ) ) ;
F_385 () ;
}
static void F_386 ( struct V_25 * V_25 , struct V_174 * V_174 )
{
V_174 -> V_25 = V_25 ;
V_174 -> F_312 = F_312 ( V_25 ) ;
}
static int F_387 ( T_1 * V_9 , struct V_173 * V_173 ,
int V_390 )
{
struct V_25 * V_25 ;
enum V_362 V_362 = V_98 ;
do {
V_362 -- ;
V_25 = V_9 -> V_99 + V_362 ;
if ( F_171 ( V_25 ) ) {
F_386 ( V_25 ,
& V_173 -> V_314 [ V_390 ++ ] ) ;
F_388 ( V_362 ) ;
}
} while ( V_362 );
return V_390 ;
}
static int F_389 ( char * V_391 )
{
if ( * V_391 == 'd' || * V_391 == 'D' ) {
V_392 = V_393 ;
} else if ( * V_391 == 'n' || * V_391 == 'N' ) {
V_392 = V_394 ;
} else if ( * V_391 == 'z' || * V_391 == 'Z' ) {
V_392 = V_395 ;
} else {
F_293 ( L_76 , V_391 ) ;
return - V_54 ;
}
return 0 ;
}
static T_3 int F_390 ( char * V_391 )
{
int V_26 ;
if ( ! V_391 )
return 0 ;
V_26 = F_389 ( V_391 ) ;
if ( V_26 == 0 )
F_391 ( V_396 , V_391 , V_397 ) ;
return V_26 ;
}
int F_392 ( struct V_398 * V_399 , int V_400 ,
void T_10 * V_401 , T_9 * V_402 ,
T_11 * V_403 )
{
char V_404 [ V_397 ] ;
int V_26 ;
static F_393 ( V_405 ) ;
F_394 ( & V_405 ) ;
if ( V_400 ) {
if ( strlen ( ( char * ) V_399 -> V_124 ) >= V_397 ) {
V_26 = - V_54 ;
goto V_39;
}
strcpy ( V_404 , ( char * ) V_399 -> V_124 ) ;
}
V_26 = F_395 ( V_399 , V_400 , V_401 , V_402 , V_403 ) ;
if ( V_26 )
goto V_39;
if ( V_400 ) {
int V_406 = V_392 ;
V_26 = F_389 ( ( char * ) V_399 -> V_124 ) ;
if ( V_26 ) {
strncpy ( ( char * ) V_399 -> V_124 , V_404 ,
V_397 ) ;
V_392 = V_406 ;
} else if ( V_406 != V_392 ) {
F_394 ( & V_407 ) ;
F_396 ( NULL , NULL ) ;
F_299 ( & V_407 ) ;
}
}
V_39:
F_299 ( & V_405 ) ;
return V_26 ;
}
static int F_397 ( int V_111 , T_8 * V_408 )
{
int V_409 , V_351 ;
int V_410 = V_411 ;
int V_412 = V_324 ;
const struct V_130 * V_366 = F_165 ( 0 ) ;
if ( ! F_376 ( V_111 , * V_408 ) ) {
F_398 ( V_111 , * V_408 ) ;
return V_111 ;
}
F_176 (n, N_MEMORY) {
if ( F_376 ( V_409 , * V_408 ) )
continue;
V_351 = F_278 ( V_111 , V_409 ) ;
V_351 += ( V_409 < V_111 ) ;
V_366 = F_165 ( V_409 ) ;
if ( ! F_166 ( V_366 ) )
V_351 += V_413 ;
V_351 *= ( V_414 * V_415 ) ;
V_351 += V_416 [ V_409 ] ;
if ( V_351 < V_410 ) {
V_410 = V_351 ;
V_412 = V_409 ;
}
}
if ( V_412 >= 0 )
F_398 ( V_412 , * V_408 ) ;
return V_412 ;
}
static void F_399 ( T_1 * V_9 , int V_111 )
{
int V_417 ;
struct V_173 * V_173 ;
V_173 = & V_9 -> V_418 [ 0 ] ;
for ( V_417 = 0 ; V_173 -> V_314 [ V_417 ] . V_25 != NULL ; V_417 ++ )
;
V_417 = F_387 ( F_10 ( V_111 ) , V_173 , V_417 ) ;
V_173 -> V_314 [ V_417 ] . V_25 = NULL ;
V_173 -> V_314 [ V_417 ] . F_312 = 0 ;
}
static void F_400 ( T_1 * V_9 )
{
int V_417 ;
struct V_173 * V_173 ;
V_173 = & V_9 -> V_418 [ 1 ] ;
V_417 = F_387 ( V_9 , V_173 , 0 ) ;
V_173 -> V_314 [ V_417 ] . V_25 = NULL ;
V_173 -> V_314 [ V_417 ] . F_312 = 0 ;
}
static void F_401 ( T_1 * V_9 , int V_419 )
{
int V_420 , V_417 , V_111 ;
int V_362 ;
struct V_25 * V_175 ;
struct V_173 * V_173 ;
V_173 = & V_9 -> V_418 [ 0 ] ;
V_420 = 0 ;
for ( V_362 = V_98 - 1 ; V_362 >= 0 ; V_362 -- ) {
for ( V_417 = 0 ; V_417 < V_419 ; V_417 ++ ) {
V_111 = V_421 [ V_417 ] ;
V_175 = & F_10 ( V_111 ) -> V_99 [ V_362 ] ;
if ( F_171 ( V_175 ) ) {
F_386 ( V_175 ,
& V_173 -> V_314 [ V_420 ++ ] ) ;
F_388 ( V_362 ) ;
}
}
}
V_173 -> V_314 [ V_420 ] . V_25 = NULL ;
V_173 -> V_314 [ V_420 ] . F_312 = 0 ;
}
static int F_402 ( void )
{
return V_394 ;
}
static int F_402 ( void )
{
return V_395 ;
}
static void F_403 ( void )
{
if ( V_392 == V_393 )
V_422 = F_402 () ;
else
V_422 = V_392 ;
}
static void F_404 ( T_1 * V_9 )
{
int V_47 , V_111 , V_423 ;
T_8 V_424 ;
int V_425 , V_426 ;
struct V_173 * V_173 ;
unsigned int V_46 = V_422 ;
for ( V_47 = 0 ; V_47 < V_427 ; V_47 ++ ) {
V_173 = V_9 -> V_418 + V_47 ;
V_173 -> V_314 [ 0 ] . V_25 = NULL ;
V_173 -> V_314 [ 0 ] . F_312 = 0 ;
}
V_425 = V_9 -> V_125 ;
V_423 = V_246 ;
V_426 = V_425 ;
F_405 ( V_424 ) ;
memset ( V_421 , 0 , sizeof( V_421 ) ) ;
V_47 = 0 ;
while ( ( V_111 = F_397 ( V_425 , & V_424 ) ) >= 0 ) {
if ( F_278 ( V_425 , V_111 ) !=
F_278 ( V_425 , V_426 ) )
V_416 [ V_111 ] = V_423 ;
V_426 = V_111 ;
V_423 -- ;
if ( V_46 == V_394 )
F_399 ( V_9 , V_111 ) ;
else
V_421 [ V_47 ++ ] = V_111 ;
}
if ( V_46 == V_395 ) {
F_401 ( V_9 , V_47 ) ;
}
F_400 ( V_9 ) ;
}
int F_406 ( int V_111 )
{
struct V_25 * V_25 ;
( void ) F_320 ( F_322 ( V_111 , V_335 ) ,
F_326 ( V_335 ) ,
NULL ,
& V_25 ) ;
return V_25 -> V_111 ;
}
static void F_403 ( void )
{
V_422 = V_395 ;
}
static void F_404 ( T_1 * V_9 )
{
int V_111 , V_425 ;
enum V_362 V_417 ;
struct V_173 * V_173 ;
V_425 = V_9 -> V_125 ;
V_173 = & V_9 -> V_418 [ 0 ] ;
V_417 = F_387 ( V_9 , V_173 , 0 ) ;
for ( V_111 = V_425 + 1 ; V_111 < V_415 ; V_111 ++ ) {
if ( ! F_407 ( V_111 ) )
continue;
V_417 = F_387 ( F_10 ( V_111 ) , V_173 , V_417 ) ;
}
for ( V_111 = 0 ; V_111 < V_425 ; V_111 ++ ) {
if ( ! F_407 ( V_111 ) )
continue;
V_417 = F_387 ( F_10 ( V_111 ) , V_173 , V_417 ) ;
}
V_173 -> V_314 [ V_417 ] . V_25 = NULL ;
V_173 -> V_314 [ V_417 ] . F_312 = 0 ;
}
static int F_408 ( void * V_124 )
{
int V_13 ;
int V_182 ;
T_1 * V_428 = V_124 ;
#ifdef V_338
memset ( V_416 , 0 , sizeof( V_416 ) ) ;
#endif
if ( V_428 && ! F_407 ( V_428 -> V_125 ) ) {
F_404 ( V_428 ) ;
}
F_409 (nid) {
T_1 * V_9 = F_10 ( V_13 ) ;
F_404 ( V_9 ) ;
}
F_410 (cpu) {
F_411 ( & F_412 ( V_429 , V_182 ) , 0 ) ;
#ifdef F_413
if ( F_414 ( V_182 ) )
F_415 ( V_182 , F_406 ( F_416 ( V_182 ) ) ) ;
#endif
}
return 0 ;
}
static T_12 void T_3
F_417 ( void )
{
F_408 ( NULL ) ;
F_418 () ;
F_419 () ;
}
void T_13 F_396 ( T_1 * V_9 , struct V_25 * V_25 )
{
F_403 () ;
if ( V_430 == V_431 ) {
F_417 () ;
} else {
#ifdef F_420
if ( V_25 )
F_421 ( V_25 ) ;
#endif
F_422 ( F_408 , V_9 , NULL ) ;
}
V_432 = F_363 () ;
if ( V_432 < ( V_118 * V_165 ) )
V_20 = 1 ;
else
V_20 = 0 ;
F_57 ( L_77 ,
V_246 ,
V_433 [ V_422 ] ,
V_20 ? L_6 : L_5 ,
V_432 ) ;
#ifdef V_338
F_57 ( L_78 , V_434 [ V_435 ] ) ;
#endif
}
static inline unsigned long F_423 ( unsigned long V_160 )
{
unsigned long V_142 = 1 ;
V_160 /= V_436 ;
while ( V_142 < V_160 )
V_142 <<= 1 ;
V_142 = F_158 ( V_142 , 4096UL ) ;
return F_15 ( V_142 , 4UL ) ;
}
static inline unsigned long F_423 ( unsigned long V_160 )
{
return 4096UL ;
}
static inline unsigned long F_424 ( unsigned long V_142 )
{
return F_425 ( ~ V_142 ) ;
}
void T_2 F_426 ( unsigned long V_142 , int V_13 , unsigned long V_25 ,
unsigned long V_29 , enum V_437 V_438 )
{
struct V_439 * V_440 = F_427 ( F_428 ( V_29 ) ) ;
unsigned long V_102 = V_29 + V_142 ;
T_1 * V_9 = F_10 ( V_13 ) ;
unsigned long V_12 ;
unsigned long V_15 = 0 ;
#ifdef F_429
struct V_441 * V_442 = NULL , * V_366 ;
#endif
if ( V_443 < V_102 - 1 )
V_443 = V_102 - 1 ;
if ( V_440 && V_29 == V_440 -> V_444 )
V_29 += V_440 -> V_445 ;
for ( V_12 = V_29 ; V_12 < V_102 ; V_12 ++ ) {
if ( V_438 != V_446 )
goto V_447;
if ( ! F_430 ( V_12 ) )
continue;
if ( ! F_153 ( V_12 , V_13 ) )
continue;
if ( ! F_13 ( V_9 , V_12 , V_102 , & V_15 ) )
break;
#ifdef F_429
if ( ! V_448 && V_449 [ V_13 ] )
if ( V_25 == V_270 && V_12 >= V_449 [ V_13 ] )
continue;
if ( V_448 && V_25 == V_450 ) {
if ( ! V_442 || V_12 >= F_431 ( V_442 ) ) {
F_432 (memory, tmp)
if ( V_12 < F_431 ( V_366 ) )
break;
V_442 = V_366 ;
}
if ( V_12 >= F_433 ( V_442 ) &&
F_434 ( V_442 ) ) {
V_12 = F_431 ( V_442 ) ;
continue;
}
}
#endif
V_447:
if ( ! ( V_12 & ( V_118 - 1 ) ) ) {
struct V_1 * V_1 = F_120 ( V_12 ) ;
F_112 ( V_1 , V_12 , V_25 , V_13 ) ;
F_16 ( V_1 , V_121 ) ;
} else {
F_119 ( V_12 , V_25 , V_13 ) ;
}
}
}
static void T_2 F_435 ( struct V_25 * V_25 )
{
unsigned int V_46 , V_190 ;
F_236 (order, t) {
F_62 ( & V_25 -> V_72 [ V_46 ] . V_77 [ V_190 ] ) ;
V_25 -> V_72 [ V_46 ] . V_73 = 0 ;
}
}
static int F_436 ( struct V_25 * V_25 )
{
#ifdef F_437
int V_181 ;
V_181 = V_25 -> V_108 / 1024 ;
if ( V_181 * V_105 > 512 * 1024 )
V_181 = ( 512 * 1024 ) / V_105 ;
V_181 /= 4 ;
if ( V_181 < 1 )
V_181 = 1 ;
V_181 = F_438 ( V_181 + V_181 / 2 ) - 1 ;
return V_181 ;
#else
return 0 ;
#endif
}
static void F_439 ( struct V_83 * V_84 , unsigned long V_140 ,
unsigned long V_181 )
{
V_84 -> V_181 = 1 ;
F_440 () ;
V_84 -> V_140 = V_140 ;
F_440 () ;
V_84 -> V_181 = V_181 ;
}
static void F_441 ( struct V_183 * V_50 , unsigned long V_181 )
{
F_439 ( & V_50 -> V_84 , 6 * V_181 , F_15 ( 1UL , 1 * V_181 ) ) ;
}
static void F_442 ( struct V_183 * V_50 )
{
struct V_83 * V_84 ;
int V_3 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_84 = & V_50 -> V_84 ;
V_84 -> V_82 = 0 ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ )
F_62 ( & V_84 -> V_92 [ V_3 ] ) ;
}
static void F_411 ( struct V_183 * V_50 , unsigned long V_181 )
{
F_442 ( V_50 ) ;
F_441 ( V_50 , V_181 ) ;
}
static void F_443 ( struct V_183 * V_50 ,
unsigned long V_140 )
{
unsigned long V_181 = F_15 ( 1UL , V_140 / 4 ) ;
if ( ( V_140 / 4 ) > ( V_17 * 8 ) )
V_181 = V_17 * 8 ;
F_439 ( & V_50 -> V_84 , V_140 , V_181 ) ;
}
static void F_444 ( struct V_25 * V_25 ,
struct V_183 * V_84 )
{
if ( V_451 )
F_443 ( V_84 ,
( V_25 -> V_108 /
V_451 ) ) ;
else
F_441 ( V_84 , F_436 ( V_25 ) ) ;
}
static void T_2 F_445 ( struct V_25 * V_25 , int V_182 )
{
struct V_183 * V_84 = F_223 ( V_25 -> V_185 , V_182 ) ;
F_442 ( V_84 ) ;
F_444 ( V_25 , V_84 ) ;
}
static void T_2 F_421 ( struct V_25 * V_25 )
{
int V_182 ;
V_25 -> V_185 = F_446 ( struct V_183 ) ;
F_410 (cpu)
F_445 ( V_25 , V_182 ) ;
}
void T_3 F_447 ( void )
{
struct V_25 * V_25 ;
F_180 (zone)
F_421 ( V_25 ) ;
}
static T_12 T_14
int F_448 ( struct V_25 * V_25 , unsigned long V_452 )
{
int V_47 ;
T_9 V_453 ;
V_25 -> F_423 =
F_423 ( V_452 ) ;
V_25 -> F_424 =
F_424 ( V_25 -> F_423 ) ;
V_453 = V_25 -> F_423
* sizeof( V_454 ) ;
if ( ! F_449 () ) {
V_25 -> V_455 = ( V_454 * )
F_450 (
V_453 , V_25 -> V_233 -> V_125 ) ;
} else {
V_25 -> V_455 = F_451 ( V_453 ) ;
}
if ( ! V_25 -> V_455 )
return - V_221 ;
for ( V_47 = 0 ; V_47 < V_25 -> F_423 ; ++ V_47 )
F_452 ( V_25 -> V_455 + V_47 ) ;
return 0 ;
}
static T_2 void F_453 ( struct V_25 * V_25 )
{
V_25 -> V_185 = & V_429 ;
if ( F_171 ( V_25 ) )
F_365 ( V_456 L_79 ,
V_25 -> V_32 , V_25 -> V_382 ,
F_436 ( V_25 ) ) ;
}
int T_2 F_454 ( struct V_25 * V_25 ,
unsigned long V_30 ,
unsigned long V_142 )
{
struct V_457 * V_9 = V_25 -> V_233 ;
int V_26 ;
V_26 = F_448 ( V_25 , V_142 ) ;
if ( V_26 )
return V_26 ;
V_9 -> V_390 = F_312 ( V_25 ) + 1 ;
V_25 -> V_30 = V_30 ;
F_455 ( V_458 , L_80 ,
L_81 ,
V_9 -> V_125 ,
( unsigned long ) F_312 ( V_25 ) ,
V_30 , ( V_30 + V_142 ) ) ;
F_435 ( V_25 ) ;
return 0 ;
}
int T_2 F_151 ( unsigned long V_12 ,
struct V_112 * V_113 )
{
unsigned long V_29 , V_102 ;
int V_13 ;
if ( V_113 -> V_459 <= V_12 && V_12 < V_113 -> V_460 )
return V_113 -> V_461 ;
V_13 = F_456 ( V_12 , & V_29 , & V_102 ) ;
if ( V_13 != - 1 ) {
V_113 -> V_459 = V_29 ;
V_113 -> V_460 = V_102 ;
V_113 -> V_461 = V_13 ;
}
return V_13 ;
}
void T_3 F_457 ( int V_13 , unsigned long V_462 )
{
unsigned long V_29 , V_102 ;
int V_47 , V_463 ;
F_169 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_29 = F_158 ( V_29 , V_462 ) ;
V_102 = F_158 ( V_102 , V_462 ) ;
if ( V_29 < V_102 )
F_458 ( F_459 ( V_29 ) ,
( V_102 - V_29 ) << V_17 ,
V_463 ) ;
}
}
void T_3 F_460 ( int V_13 )
{
unsigned long V_29 , V_102 ;
int V_47 , V_463 ;
F_169 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_461 ( V_463 , V_29 , V_102 ) ;
}
void T_2 F_462 ( unsigned int V_13 ,
unsigned long * V_29 , unsigned long * V_102 )
{
unsigned long V_464 , V_465 ;
int V_47 ;
* V_29 = - 1UL ;
* V_102 = 0 ;
F_169 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_29 = F_158 ( * V_29 , V_464 ) ;
* V_102 = F_15 ( * V_102 , V_465 ) ;
}
if ( * V_29 == - 1UL )
* V_29 = 0 ;
}
static void T_3 F_463 ( void )
{
int V_466 ;
for ( V_466 = V_98 - 1 ; V_466 >= 0 ; V_466 -- ) {
if ( V_466 == V_450 )
continue;
if ( V_467 [ V_466 ] >
V_468 [ V_466 ] )
break;
}
F_81 ( V_466 == - 1 ) ;
V_469 = V_466 ;
}
static void T_2 F_464 ( int V_13 ,
unsigned long V_362 ,
unsigned long V_131 ,
unsigned long V_470 ,
unsigned long * V_30 ,
unsigned long * F_122 )
{
if ( V_449 [ V_13 ] ) {
if ( V_362 == V_450 ) {
* V_30 = V_449 [ V_13 ] ;
* F_122 = F_158 ( V_470 ,
V_467 [ V_469 ] ) ;
} else if ( * V_30 >= V_449 [ V_13 ] )
* V_30 = * F_122 ;
}
}
static unsigned long T_2 F_465 ( int V_13 ,
unsigned long V_362 ,
unsigned long V_131 ,
unsigned long V_470 ,
unsigned long * V_30 ,
unsigned long * F_122 ,
unsigned long * V_471 )
{
if ( ! V_131 && ! V_470 )
return 0 ;
* V_30 = V_468 [ V_362 ] ;
* F_122 = V_467 [ V_362 ] ;
F_464 ( V_13 , V_362 ,
V_131 , V_470 ,
V_30 , F_122 ) ;
if ( * F_122 < V_131 || * V_30 > V_470 )
return 0 ;
* F_122 = F_158 ( * F_122 , V_470 ) ;
* V_30 = F_15 ( * V_30 , V_131 ) ;
return * F_122 - * V_30 ;
}
unsigned long T_2 F_466 ( int V_13 ,
unsigned long V_472 ,
unsigned long V_473 )
{
unsigned long V_474 = V_473 - V_472 ;
unsigned long V_29 , V_102 ;
int V_47 ;
F_169 (i, nid, &start_pfn, &end_pfn, NULL) {
V_29 = F_467 ( V_29 , V_472 , V_473 ) ;
V_102 = F_467 ( V_102 , V_472 , V_473 ) ;
V_474 -= V_102 - V_29 ;
}
return V_474 ;
}
unsigned long T_3 F_468 ( unsigned long V_29 ,
unsigned long V_102 )
{
return F_466 ( V_415 , V_29 , V_102 ) ;
}
static unsigned long T_2 F_469 ( int V_13 ,
unsigned long V_362 ,
unsigned long V_131 ,
unsigned long V_470 ,
unsigned long * V_471 )
{
unsigned long V_475 = V_468 [ V_362 ] ;
unsigned long V_476 = V_467 [ V_362 ] ;
unsigned long V_30 , F_122 ;
unsigned long V_474 ;
if ( ! V_131 && ! V_470 )
return 0 ;
V_30 = F_467 ( V_131 , V_475 , V_476 ) ;
F_122 = F_467 ( V_470 , V_475 , V_476 ) ;
F_464 ( V_13 , V_362 ,
V_131 , V_470 ,
& V_30 , & F_122 ) ;
V_474 = F_466 ( V_13 , V_30 , F_122 ) ;
if ( V_449 [ V_13 ] ) {
if ( V_448 ) {
unsigned long V_29 , V_102 ;
struct V_441 * V_442 ;
F_432 (memory, r) {
V_29 = F_467 ( F_433 ( V_442 ) ,
V_30 , F_122 ) ;
V_102 = F_467 ( F_431 ( V_442 ) ,
V_30 , F_122 ) ;
if ( V_362 == V_450 &&
F_434 ( V_442 ) )
V_474 += V_102 - V_29 ;
if ( V_362 == V_270 &&
! F_434 ( V_442 ) )
V_474 += V_102 - V_29 ;
}
} else {
if ( V_362 == V_270 )
V_474 += V_470 - V_449 [ V_13 ] ;
}
}
return V_474 ;
}
static inline unsigned long T_2 F_465 ( int V_13 ,
unsigned long V_362 ,
unsigned long V_131 ,
unsigned long V_470 ,
unsigned long * V_30 ,
unsigned long * F_122 ,
unsigned long * V_477 )
{
unsigned int V_25 ;
* V_30 = V_131 ;
for ( V_25 = 0 ; V_25 < V_362 ; V_25 ++ )
* V_30 += V_477 [ V_25 ] ;
* F_122 = * V_30 + V_477 [ V_362 ] ;
return V_477 [ V_362 ] ;
}
static inline unsigned long T_2 F_469 ( int V_13 ,
unsigned long V_362 ,
unsigned long V_131 ,
unsigned long V_470 ,
unsigned long * V_478 )
{
if ( ! V_478 )
return 0 ;
return V_478 [ V_362 ] ;
}
static void T_2 F_470 ( struct V_457 * V_9 ,
unsigned long V_131 ,
unsigned long V_470 ,
unsigned long * V_477 ,
unsigned long * V_478 )
{
unsigned long V_479 = 0 , V_480 = 0 ;
enum V_362 V_47 ;
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ ) {
struct V_25 * V_25 = V_9 -> V_99 + V_47 ;
unsigned long V_30 , F_122 ;
unsigned long V_142 , V_481 ;
V_142 = F_465 ( V_9 -> V_125 , V_47 ,
V_131 ,
V_470 ,
& V_30 ,
& F_122 ,
V_477 ) ;
V_481 = V_142 - F_469 ( V_9 -> V_125 , V_47 ,
V_131 , V_470 ,
V_478 ) ;
if ( V_142 )
V_25 -> V_30 = V_30 ;
else
V_25 -> V_30 = 0 ;
V_25 -> V_31 = V_142 ;
V_25 -> V_382 = V_481 ;
V_480 += V_142 ;
V_479 += V_481 ;
}
V_9 -> V_18 = V_480 ;
V_9 -> V_482 = V_479 ;
F_365 ( V_456 L_82 , V_9 -> V_125 ,
V_479 ) ;
}
static unsigned long T_3 F_471 ( unsigned long V_30 , unsigned long V_483 )
{
unsigned long V_484 ;
V_483 += V_30 & ( V_118 - 1 ) ;
V_484 = F_472 ( V_483 , V_118 ) ;
V_484 = V_484 >> V_138 ;
V_484 *= V_485 ;
V_484 = F_472 ( V_484 , 8 * sizeof( unsigned long ) ) ;
return V_484 / 8 ;
}
static void T_3 F_473 ( struct V_457 * V_9 ,
struct V_25 * V_25 ,
unsigned long V_30 ,
unsigned long V_483 )
{
unsigned long V_484 = F_471 ( V_30 , V_483 ) ;
V_25 -> V_486 = NULL ;
if ( V_484 )
V_25 -> V_486 =
F_450 ( V_484 ,
V_9 -> V_125 ) ;
}
static inline void F_473 ( struct V_457 * V_9 , struct V_25 * V_25 ,
unsigned long V_30 , unsigned long V_483 ) {}
void T_15 F_474 ( void )
{
unsigned int V_46 ;
if ( V_138 )
return;
if ( V_487 > V_17 )
V_46 = V_488 ;
else
V_46 = V_58 - 1 ;
V_138 = V_46 ;
}
void T_15 F_474 ( void )
{
}
static unsigned long T_15 F_475 ( unsigned long V_31 ,
unsigned long V_382 )
{
unsigned long V_160 = V_31 ;
if ( V_31 > V_382 + ( V_382 >> 4 ) &&
F_107 ( V_489 ) )
V_160 = V_382 ;
return F_354 ( V_160 * sizeof( struct V_1 ) ) >> V_17 ;
}
static void T_15 F_476 ( struct V_457 * V_9 )
{
enum V_362 V_417 ;
int V_13 = V_9 -> V_125 ;
int V_26 ;
F_477 ( V_9 ) ;
#ifdef F_478
F_479 ( & V_9 -> V_490 ) ;
V_9 -> V_491 = 0 ;
V_9 -> V_492 = V_38 ;
#endif
#ifdef F_480
F_479 ( & V_9 -> V_493 ) ;
F_62 ( & V_9 -> V_494 ) ;
V_9 -> V_495 = 0 ;
#endif
F_452 ( & V_9 -> V_496 ) ;
F_452 ( & V_9 -> V_497 ) ;
#ifdef F_481
F_452 ( & V_9 -> V_498 ) ;
#endif
F_482 ( V_9 ) ;
for ( V_417 = 0 ; V_417 < V_98 ; V_417 ++ ) {
struct V_25 * V_25 = V_9 -> V_99 + V_417 ;
unsigned long V_142 , V_499 , V_500 , V_501 ;
unsigned long V_30 = V_25 -> V_30 ;
V_142 = V_25 -> V_31 ;
V_499 = V_500 = V_25 -> V_382 ;
V_501 = F_475 ( V_142 , V_499 ) ;
if ( ! F_116 ( V_417 ) ) {
if ( V_500 >= V_501 ) {
V_500 -= V_501 ;
if ( V_501 )
F_365 ( V_456
L_83 ,
V_434 [ V_417 ] , V_501 ) ;
} else
F_293 ( L_84 ,
V_434 [ V_417 ] , V_501 , V_500 ) ;
}
if ( V_417 == 0 && V_500 > V_502 ) {
V_500 -= V_502 ;
F_365 ( V_456 L_85 ,
V_434 [ 0 ] , V_502 ) ;
}
if ( ! F_116 ( V_417 ) )
V_503 += V_500 ;
else if ( V_503 > V_501 * 2 )
V_503 -= V_501 ;
V_504 += V_500 ;
V_25 -> V_108 = F_116 ( V_417 ) ? V_499 : V_500 ;
#ifdef V_338
V_25 -> V_111 = V_13 ;
V_25 -> V_505 = ( V_500 * V_506 )
/ 100 ;
V_25 -> V_507 = ( V_500 * V_508 ) / 100 ;
#endif
V_25 -> V_32 = V_434 [ V_417 ] ;
F_479 ( & V_25 -> V_88 ) ;
F_479 ( & V_25 -> V_509 ) ;
F_483 ( V_25 ) ;
V_25 -> V_233 = V_9 ;
F_453 ( V_25 ) ;
F_280 ( V_25 , V_202 , V_25 -> V_108 ) ;
F_484 ( & V_25 -> V_510 ) ;
if ( ! V_142 )
continue;
F_474 () ;
F_473 ( V_9 , V_25 , V_30 , V_142 ) ;
V_26 = F_454 ( V_25 , V_30 , V_142 ) ;
F_168 ( V_26 ) ;
F_485 ( V_142 , V_13 , V_417 , V_30 ) ;
}
}
static void T_14 F_486 ( struct V_457 * V_9 )
{
unsigned long T_16 V_100 = 0 ;
unsigned long T_16 V_327 = 0 ;
if ( ! V_9 -> V_18 )
return;
#ifdef F_487
V_100 = V_9 -> V_131 & ~ ( V_120 - 1 ) ;
V_327 = V_9 -> V_131 - V_100 ;
if ( ! V_9 -> V_511 ) {
unsigned long V_142 , V_101 ;
struct V_1 * V_512 ;
V_101 = F_14 ( V_9 ) ;
V_101 = F_157 ( V_101 , V_120 ) ;
V_142 = ( V_101 - V_100 ) * sizeof( struct V_1 ) ;
V_512 = F_488 ( V_9 -> V_125 , V_142 ) ;
if ( ! V_512 )
V_512 = F_450 ( V_142 ,
V_9 -> V_125 ) ;
V_9 -> V_511 = V_512 + V_327 ;
}
#ifndef F_489
if ( V_9 == F_10 ( 0 ) ) {
V_513 = F_10 ( 0 ) -> V_511 ;
#if F_490 ( F_429 ) || F_490 ( V_514 )
if ( F_20 ( V_513 ) != V_9 -> V_131 )
V_513 -= V_327 ;
#endif
}
#endif
#endif
}
void T_15 F_491 ( int V_13 , unsigned long * V_477 ,
unsigned long V_131 , unsigned long * V_478 )
{
T_1 * V_9 = F_10 ( V_13 ) ;
unsigned long V_29 = 0 ;
unsigned long V_102 = 0 ;
F_4 ( V_9 -> V_390 || V_9 -> V_223 ) ;
F_8 ( V_9 ) ;
V_9 -> V_125 = V_13 ;
V_9 -> V_131 = V_131 ;
#ifdef F_429
F_462 ( V_13 , & V_29 , & V_102 ) ;
F_57 ( L_86 , V_13 ,
( V_515 ) V_29 << V_17 ,
V_102 ? ( ( V_515 ) V_102 << V_17 ) - 1 : 0 ) ;
#else
V_29 = V_131 ;
#endif
F_470 ( V_9 , V_29 , V_102 ,
V_477 , V_478 ) ;
F_486 ( V_9 ) ;
#ifdef F_487
F_365 ( V_456 L_87 ,
V_13 , ( unsigned long ) V_9 ,
( unsigned long ) V_9 -> V_511 ) ;
#endif
F_476 ( V_9 ) ;
}
void T_3 F_492 ( void )
{
unsigned int V_516 ;
V_516 = F_493 ( V_517 . V_518 , V_415 ) ;
V_519 = V_516 + 1 ;
}
unsigned long T_3 F_494 ( void )
{
unsigned long V_520 = 0 , V_460 = 0 ;
unsigned long V_100 , V_101 , V_521 ;
int V_461 = - 1 ;
int V_47 , V_13 ;
F_169 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_100 || V_461 < 0 || V_461 == V_13 ) {
V_461 = V_13 ;
V_460 = V_101 ;
continue;
}
V_521 = ~ ( ( 1 << F_495 ( V_100 ) ) - 1 ) ;
while ( V_521 && V_460 <= ( V_100 & ( V_521 << 1 ) ) )
V_521 <<= 1 ;
V_520 |= V_521 ;
}
return ~ V_520 + 1 ;
}
static unsigned long T_3 F_496 ( int V_13 )
{
unsigned long V_522 = V_11 ;
unsigned long V_29 ;
int V_47 ;
F_169 (i, nid, &start_pfn, NULL, NULL)
V_522 = F_158 ( V_522 , V_29 ) ;
if ( V_522 == V_11 ) {
F_293 ( L_88 , V_13 ) ;
return 0 ;
}
return V_522 ;
}
unsigned long T_3 F_497 ( void )
{
return F_496 ( V_415 ) ;
}
static unsigned long T_3 F_498 ( void )
{
unsigned long V_480 = 0 ;
unsigned long V_29 , V_102 ;
int V_47 , V_13 ;
F_169 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_160 = V_102 - V_29 ;
V_480 += V_160 ;
if ( V_160 )
F_499 ( V_13 , V_136 ) ;
}
return V_480 ;
}
static void T_3 F_500 ( void )
{
int V_47 , V_13 ;
unsigned long V_523 ;
unsigned long V_524 , V_525 ;
T_8 V_526 = V_527 [ V_136 ] ;
unsigned long V_480 = F_498 () ;
int V_528 = F_501 ( V_527 [ V_136 ] ) ;
struct V_441 * V_442 ;
F_463 () ;
if ( F_502 () ) {
F_432 (memory, r) {
if ( ! F_503 ( V_442 ) )
continue;
V_13 = V_442 -> V_13 ;
V_523 = F_124 ( V_442 -> V_529 ) ;
V_449 [ V_13 ] = V_449 [ V_13 ] ?
F_158 ( V_523 , V_449 [ V_13 ] ) :
V_523 ;
}
goto V_530;
}
if ( V_448 ) {
bool V_531 = false ;
F_432 (memory, r) {
if ( F_434 ( V_442 ) )
continue;
V_13 = V_442 -> V_13 ;
V_523 = F_433 ( V_442 ) ;
if ( V_523 < 0x100000 ) {
V_531 = true ;
continue;
}
V_449 [ V_13 ] = V_449 [ V_13 ] ?
F_158 ( V_523 , V_449 [ V_13 ] ) :
V_523 ;
}
if ( V_531 )
F_293 ( L_89 ) ;
goto V_530;
}
if ( V_532 ) {
unsigned long V_533 ;
V_532 =
F_472 ( V_532 , V_120 ) ;
V_532 = F_158 ( V_480 , V_532 ) ;
V_533 = V_480 - V_532 ;
V_534 = F_15 ( V_534 , V_533 ) ;
}
if ( ! V_534 || V_534 >= V_480 )
goto V_39;
V_523 = V_468 [ V_469 ] ;
V_535:
V_524 = V_534 / V_528 ;
F_176 (nid, N_MEMORY) {
unsigned long V_29 , V_102 ;
if ( V_534 < V_524 )
V_524 = V_534 / V_528 ;
V_525 = V_524 ;
F_169 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_536 ;
V_29 = F_15 ( V_29 , V_449 [ V_13 ] ) ;
if ( V_29 >= V_102 )
continue;
if ( V_29 < V_523 ) {
unsigned long V_537 ;
V_537 = F_158 ( V_102 , V_523 )
- V_29 ;
V_525 -= F_158 ( V_537 ,
V_525 ) ;
V_534 -= F_158 ( V_537 ,
V_534 ) ;
if ( V_102 <= V_523 ) {
V_449 [ V_13 ] = V_102 ;
continue;
}
V_29 = V_523 ;
}
V_536 = V_102 - V_29 ;
if ( V_536 > V_525 )
V_536 = V_525 ;
V_449 [ V_13 ] = V_29 + V_536 ;
V_534 -= F_158 ( V_534 ,
V_536 ) ;
V_525 -= V_536 ;
if ( ! V_525 )
break;
}
}
V_528 -- ;
if ( V_528 && V_534 > V_528 )
goto V_535;
V_530:
for ( V_13 = 0 ; V_13 < V_415 ; V_13 ++ )
V_449 [ V_13 ] =
F_472 ( V_449 [ V_13 ] , V_120 ) ;
V_39:
V_527 [ V_136 ] = V_526 ;
}
static void F_504 ( T_1 * V_9 , int V_13 )
{
enum V_362 V_362 ;
if ( V_136 == V_538 )
return;
for ( V_362 = 0 ; V_362 <= V_450 - 1 ; V_362 ++ ) {
struct V_25 * V_25 = & V_9 -> V_99 [ V_362 ] ;
if ( F_171 ( V_25 ) ) {
F_499 ( V_13 , V_539 ) ;
if ( V_538 != V_539 &&
V_362 <= V_270 )
F_499 ( V_13 , V_538 ) ;
break;
}
}
}
void T_3 F_505 ( unsigned long * V_189 )
{
unsigned long V_29 , V_102 ;
int V_47 , V_13 ;
memset ( V_468 , 0 ,
sizeof( V_468 ) ) ;
memset ( V_467 , 0 ,
sizeof( V_467 ) ) ;
V_468 [ 0 ] = F_497 () ;
V_467 [ 0 ] = V_189 [ 0 ] ;
for ( V_47 = 1 ; V_47 < V_98 ; V_47 ++ ) {
if ( V_47 == V_450 )
continue;
V_468 [ V_47 ] =
V_467 [ V_47 - 1 ] ;
V_467 [ V_47 ] =
F_15 ( V_189 [ V_47 ] , V_468 [ V_47 ] ) ;
}
V_468 [ V_450 ] = 0 ;
V_467 [ V_450 ] = 0 ;
memset ( V_449 , 0 , sizeof( V_449 ) ) ;
F_500 () ;
F_57 ( L_90 ) ;
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ ) {
if ( V_47 == V_450 )
continue;
F_57 ( L_91 , V_434 [ V_47 ] ) ;
if ( V_468 [ V_47 ] ==
V_467 [ V_47 ] )
F_506 ( L_92 ) ;
else
F_506 ( L_93 ,
( V_515 ) V_468 [ V_47 ]
<< V_17 ,
( ( V_515 ) V_467 [ V_47 ]
<< V_17 ) - 1 ) ;
}
F_57 ( L_94 ) ;
for ( V_47 = 0 ; V_47 < V_415 ; V_47 ++ ) {
if ( V_449 [ V_47 ] )
F_57 ( L_95 , V_47 ,
( V_515 ) V_449 [ V_47 ] << V_17 ) ;
}
F_57 ( L_96 ) ;
F_169 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_57 ( L_97 , V_13 ,
( V_515 ) V_29 << V_17 ,
( ( V_515 ) V_102 << V_17 ) - 1 ) ;
F_507 () ;
F_492 () ;
F_409 (nid) {
T_1 * V_9 = F_10 ( V_13 ) ;
F_491 ( V_13 , NULL ,
F_496 ( V_13 ) , NULL ) ;
if ( V_9 -> V_482 )
F_499 ( V_13 , V_136 ) ;
F_504 ( V_9 , V_13 ) ;
}
}
static int T_3 F_508 ( char * V_50 , unsigned long * V_540 )
{
unsigned long long V_541 ;
if ( ! V_50 )
return - V_54 ;
V_541 = F_509 ( V_50 , & V_50 ) ;
* V_540 = V_541 >> V_17 ;
F_4 ( ( V_541 >> V_17 ) > V_11 ) ;
return 0 ;
}
static int T_3 F_510 ( char * V_50 )
{
if ( F_511 ( V_50 , L_98 ) ) {
V_448 = true ;
return 0 ;
}
return F_508 ( V_50 , & V_534 ) ;
}
static int T_3 F_512 ( char * V_50 )
{
return F_508 ( V_50 , & V_532 ) ;
}
void F_182 ( struct V_1 * V_1 , long V_82 )
{
F_96 ( & V_542 ) ;
F_28 ( V_1 ) -> V_108 += V_82 ;
V_353 += V_82 ;
#ifdef F_374
if ( F_135 ( V_1 ) )
V_359 += V_82 ;
#endif
F_102 ( & V_542 ) ;
}
unsigned long F_513 ( void * V_100 , void * V_101 , int V_543 , char * V_391 )
{
void * V_420 ;
unsigned long V_160 = 0 ;
V_100 = ( void * ) F_354 ( ( unsigned long ) V_100 ) ;
V_101 = ( void * ) ( ( unsigned long ) V_101 & V_544 ) ;
for ( V_420 = V_100 ; V_420 < V_101 ; V_420 += V_105 , V_160 ++ ) {
if ( ( unsigned int ) V_543 <= 0xFF )
memset ( V_420 , V_543 , V_105 ) ;
F_514 ( F_248 ( V_420 ) ) ;
}
if ( V_160 && V_391 )
F_57 ( L_99 ,
V_391 , V_160 << ( V_17 - 10 ) , V_100 , V_101 ) ;
return V_160 ;
}
void F_515 ( struct V_1 * V_1 )
{
F_516 ( V_1 ) ;
V_353 ++ ;
F_28 ( V_1 ) -> V_108 ++ ;
V_359 ++ ;
}
void T_3 F_517 ( const char * V_206 )
{
unsigned long V_545 , V_546 , V_547 , V_548 , V_549 ;
unsigned long V_550 , V_551 ;
V_545 = F_518 () ;
V_546 = V_552 - V_553 ;
V_547 = V_554 - V_555 ;
V_548 = V_556 - V_557 ;
V_549 = V_558 - V_559 ;
V_551 = V_560 - V_561 ;
V_550 = V_562 - V_563 ;
#define F_519 ( V_100 , V_101 , V_142 , V_420 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_519 ( V_561 , V_560 , V_551 ,
V_563 , V_550 ) ;
F_519 ( V_553 , V_552 , V_546 , V_563 , V_550 ) ;
F_519 ( V_555 , V_554 , V_547 , V_561 , V_551 ) ;
F_519 ( V_553 , V_552 , V_546 , V_557 , V_548 ) ;
F_519 ( V_555 , V_554 , V_547 , V_557 , V_548 ) ;
#undef F_519
F_57 ( L_100
#ifdef F_374
L_101
#endif
L_102 ,
F_520 () << ( V_17 - 10 ) ,
V_545 << ( V_17 - 10 ) ,
V_546 >> 10 , V_547 >> 10 , V_548 >> 10 ,
( V_551 + V_550 ) >> 10 , V_549 >> 10 ,
( V_545 - V_353 - V_564 ) << ( V_17 - 10 ) ,
V_564 << ( V_17 - 10 ) ,
#ifdef F_374
V_359 << ( V_17 - 10 ) ,
#endif
V_206 ? L_103 : L_104 , V_206 ? V_206 : L_104 ) ;
}
void T_3 F_521 ( unsigned long V_565 )
{
V_502 = V_565 ;
}
void T_3 F_522 ( unsigned long * V_477 )
{
F_491 ( 0 , V_477 ,
F_523 ( V_566 ) >> V_17 , NULL ) ;
}
static int F_524 ( struct V_567 * V_428 ,
unsigned long V_568 , void * V_569 )
{
int V_182 = ( unsigned long ) V_569 ;
if ( V_568 == V_570 || V_568 == V_571 ) {
F_525 ( V_182 ) ;
F_224 ( V_182 ) ;
F_526 ( V_182 ) ;
F_527 ( V_182 ) ;
}
return V_572 ;
}
void T_3 F_528 ( void )
{
F_529 ( F_524 , 0 ) ;
}
static void F_530 ( void )
{
struct V_457 * V_9 ;
unsigned long V_573 = 0 ;
enum V_362 V_47 , V_417 ;
F_531 (pgdat) {
for ( V_47 = 0 ; V_47 < V_98 ; V_47 ++ ) {
struct V_25 * V_25 = V_9 -> V_99 + V_47 ;
long F_15 = 0 ;
for ( V_417 = V_47 ; V_417 < V_98 ; V_417 ++ ) {
if ( V_25 -> V_229 [ V_417 ] > F_15 )
F_15 = V_25 -> V_229 [ V_417 ] ;
}
F_15 += F_281 ( V_25 ) ;
if ( F_15 > V_25 -> V_108 )
F_15 = V_25 -> V_108 ;
V_25 -> V_346 = F_15 ;
V_573 += F_15 ;
}
}
V_346 = V_573 ;
}
static void F_532 ( void )
{
struct V_457 * V_9 ;
enum V_362 V_417 , V_574 ;
F_531 (pgdat) {
for ( V_417 = 0 ; V_417 < V_98 ; V_417 ++ ) {
struct V_25 * V_25 = V_9 -> V_99 + V_417 ;
unsigned long V_108 = V_25 -> V_108 ;
V_25 -> V_229 [ V_417 ] = 0 ;
V_574 = V_417 ;
while ( V_574 ) {
struct V_25 * V_575 ;
V_574 -- ;
if ( V_576 [ V_574 ] < 1 )
V_576 [ V_574 ] = 1 ;
V_575 = V_9 -> V_99 + V_574 ;
V_575 -> V_229 [ V_417 ] = V_108 /
V_576 [ V_574 ] ;
V_108 += V_575 -> V_108 ;
}
}
}
F_530 () ;
}
static void F_533 ( void )
{
unsigned long V_577 = V_578 >> ( V_17 - 10 ) ;
unsigned long V_579 = 0 ;
struct V_25 * V_25 ;
unsigned long V_43 ;
F_368 (zone) {
if ( ! F_534 ( V_25 ) )
V_579 += V_25 -> V_108 ;
}
F_368 (zone) {
V_515 V_366 ;
F_209 ( & V_25 -> V_88 , V_43 ) ;
V_366 = ( V_515 ) V_577 * V_25 -> V_108 ;
F_535 ( V_366 , V_579 ) ;
if ( F_534 ( V_25 ) ) {
unsigned long V_580 ;
V_580 = V_25 -> V_108 / 1024 ;
V_580 = F_467 ( V_580 , V_581 , 128UL ) ;
V_25 -> V_194 [ V_582 ] = V_580 ;
} else {
V_25 -> V_194 [ V_582 ] = V_366 ;
}
V_366 = F_536 ( V_515 , V_366 >> 2 ,
F_537 ( V_25 -> V_108 ,
V_583 , 10000 ) ) ;
V_25 -> V_194 [ V_345 ] = F_381 ( V_25 ) + V_366 ;
V_25 -> V_194 [ V_584 ] = F_381 ( V_25 ) + V_366 * 2 ;
F_98 ( V_25 , V_202 ,
F_281 ( V_25 ) - F_251 ( V_25 ) -
F_256 ( & V_25 -> V_203 [ V_202 ] ) ) ;
F_211 ( & V_25 -> V_88 , V_43 ) ;
}
F_530 () ;
}
void F_538 ( void )
{
F_394 ( & V_407 ) ;
F_533 () ;
F_299 ( & V_407 ) ;
}
static void T_2 F_539 ( struct V_25 * V_25 )
{
unsigned int V_585 , V_586 ;
V_585 = V_25 -> V_108 >> ( 30 - V_17 ) ;
if ( V_585 )
V_586 = F_540 ( 10 * V_585 ) ;
else
V_586 = 1 ;
V_25 -> V_587 = V_586 ;
}
static void T_2 F_541 ( void )
{
struct V_25 * V_25 ;
F_368 (zone)
F_539 ( V_25 ) ;
}
int T_2 F_542 ( void )
{
unsigned long V_588 ;
int V_589 ;
V_588 = F_362 () * ( V_105 >> 10 ) ;
V_589 = F_540 ( V_588 * 16 ) ;
if ( V_589 > V_590 ) {
V_578 = V_589 ;
if ( V_578 < 128 )
V_578 = 128 ;
if ( V_578 > 65536 )
V_578 = 65536 ;
} else {
F_293 ( L_105 ,
V_589 , V_590 ) ;
}
F_538 () ;
F_543 () ;
F_532 () ;
F_541 () ;
return 0 ;
}
int F_544 ( struct V_398 * V_399 , int V_400 ,
void T_10 * V_401 , T_9 * V_402 , T_11 * V_403 )
{
int V_591 ;
V_591 = F_545 ( V_399 , V_400 , V_401 , V_402 , V_403 ) ;
if ( V_591 )
return V_591 ;
if ( V_400 ) {
V_590 = V_578 ;
F_538 () ;
}
return 0 ;
}
int F_546 ( struct V_398 * V_399 , int V_400 ,
void T_10 * V_401 , T_9 * V_402 , T_11 * V_403 )
{
int V_591 ;
V_591 = F_545 ( V_399 , V_400 , V_401 , V_402 , V_403 ) ;
if ( V_591 )
return V_591 ;
if ( V_400 )
F_538 () ;
return 0 ;
}
int F_547 ( struct V_398 * V_399 , int V_400 ,
void T_10 * V_401 , T_9 * V_402 , T_11 * V_403 )
{
struct V_25 * V_25 ;
int V_591 ;
V_591 = F_545 ( V_399 , V_400 , V_401 , V_402 , V_403 ) ;
if ( V_591 )
return V_591 ;
F_368 (zone)
V_25 -> V_505 = ( V_25 -> V_108 *
V_506 ) / 100 ;
return 0 ;
}
int F_548 ( struct V_398 * V_399 , int V_400 ,
void T_10 * V_401 , T_9 * V_402 , T_11 * V_403 )
{
struct V_25 * V_25 ;
int V_591 ;
V_591 = F_545 ( V_399 , V_400 , V_401 , V_402 , V_403 ) ;
if ( V_591 )
return V_591 ;
F_368 (zone)
V_25 -> V_507 = ( V_25 -> V_108 *
V_508 ) / 100 ;
return 0 ;
}
int F_549 ( struct V_398 * V_399 , int V_400 ,
void T_10 * V_401 , T_9 * V_402 , T_11 * V_403 )
{
F_545 ( V_399 , V_400 , V_401 , V_402 , V_403 ) ;
F_532 () ;
return 0 ;
}
int F_550 ( struct V_398 * V_399 , int V_400 ,
void T_10 * V_401 , T_9 * V_402 , T_11 * V_403 )
{
struct V_25 * V_25 ;
int V_592 ;
int V_26 ;
F_394 ( & V_593 ) ;
V_592 = V_451 ;
V_26 = F_545 ( V_399 , V_400 , V_401 , V_402 , V_403 ) ;
if ( ! V_400 || V_26 < 0 )
goto V_39;
if ( V_451 &&
V_451 < V_594 ) {
V_451 = V_592 ;
V_26 = - V_54 ;
goto V_39;
}
if ( V_451 == V_592 )
goto V_39;
F_180 (zone) {
unsigned int V_182 ;
F_410 (cpu)
F_444 ( V_25 ,
F_223 ( V_25 -> V_185 , V_182 ) ) ;
}
V_39:
F_299 ( & V_593 ) ;
return V_26 ;
}
static int T_3 F_551 ( char * V_206 )
{
if ( ! V_206 )
return 0 ;
V_595 = F_552 ( V_206 , & V_206 , 0 ) ;
return 1 ;
}
void * T_3 F_553 ( const char * V_596 ,
unsigned long V_597 ,
unsigned long V_598 ,
int V_599 ,
int V_43 ,
unsigned int * V_600 ,
unsigned int * V_601 ,
unsigned long V_602 ,
unsigned long V_603 )
{
unsigned long long F_15 = V_603 ;
unsigned long V_604 , V_142 ;
void * V_399 = NULL ;
if ( ! V_598 ) {
V_598 = V_503 ;
if ( V_17 < 20 )
V_598 = F_554 ( V_598 , ( 1 << 20 ) / V_105 ) ;
if ( V_599 > V_17 )
V_598 >>= ( V_599 - V_17 ) ;
else
V_598 <<= ( V_17 - V_599 ) ;
if ( F_17 ( V_43 & V_605 ) ) {
F_4 ( ! ( V_43 & V_606 ) ) ;
if ( ! ( V_598 >> * V_600 ) ) {
V_598 = 1UL << * V_600 ;
F_168 ( ! V_598 ) ;
}
} else if ( F_17 ( ( V_598 * V_597 ) < V_105 ) )
V_598 = V_105 / V_597 ;
}
V_598 = F_555 ( V_598 ) ;
if ( F_15 == 0 ) {
F_15 = ( ( unsigned long long ) V_504 << V_17 ) >> 4 ;
F_535 ( F_15 , V_597 ) ;
}
F_15 = F_158 ( F_15 , 0x80000000ULL ) ;
if ( V_598 < V_602 )
V_598 = V_602 ;
if ( V_598 > F_15 )
V_598 = F_15 ;
V_604 = F_556 ( V_598 ) ;
do {
V_142 = V_597 << V_604 ;
if ( V_43 & V_606 )
V_399 = F_557 ( V_142 , 0 ) ;
else if ( V_595 )
V_399 = F_558 ( V_142 , V_607 , V_608 ) ;
else {
if ( F_357 ( V_142 ) < V_58 ) {
V_399 = F_356 ( V_142 , V_607 ) ;
F_559 ( V_399 , V_142 , 1 , V_607 ) ;
}
}
} while ( ! V_399 && V_142 > V_105 && -- V_604 );
if ( ! V_399 )
F_560 ( L_106 , V_596 ) ;
F_57 ( L_107 ,
V_596 , 1UL << V_604 , F_556 ( V_142 ) - V_17 , V_142 ) ;
if ( V_600 )
* V_600 = V_604 ;
if ( V_601 )
* V_601 = ( 1 << V_604 ) - 1 ;
return V_399 ;
}
static inline unsigned long * F_561 ( struct V_25 * V_25 ,
unsigned long V_12 )
{
#ifdef V_489
return F_562 ( V_12 ) -> V_486 ;
#else
return V_25 -> V_486 ;
#endif
}
static inline int F_563 ( struct V_25 * V_25 , unsigned long V_12 )
{
#ifdef V_489
V_12 &= ( V_19 - 1 ) ;
return ( V_12 >> V_138 ) * V_485 ;
#else
V_12 = V_12 - F_564 ( V_25 -> V_30 , V_118 ) ;
return ( V_12 >> V_138 ) * V_485 ;
#endif
}
unsigned long F_565 ( struct V_1 * V_1 , unsigned long V_12 ,
unsigned long V_609 ,
unsigned long V_521 )
{
struct V_25 * V_25 ;
unsigned long * V_610 ;
unsigned long V_611 , V_612 ;
unsigned long V_613 ;
V_25 = F_28 ( V_1 ) ;
V_610 = F_561 ( V_25 , V_12 ) ;
V_611 = F_563 ( V_25 , V_12 ) ;
V_612 = V_611 / V_614 ;
V_611 &= ( V_614 - 1 ) ;
V_613 = V_610 [ V_612 ] ;
V_611 += V_609 ;
return ( V_613 >> ( V_614 - V_611 - 1 ) ) & V_521 ;
}
void F_566 ( struct V_1 * V_1 , unsigned long V_43 ,
unsigned long V_12 ,
unsigned long V_609 ,
unsigned long V_521 )
{
struct V_25 * V_25 ;
unsigned long * V_610 ;
unsigned long V_611 , V_612 ;
unsigned long V_615 , V_613 ;
F_106 ( V_485 != 4 ) ;
V_25 = F_28 ( V_1 ) ;
V_610 = F_561 ( V_25 , V_12 ) ;
V_611 = F_563 ( V_25 , V_12 ) ;
V_612 = V_611 / V_614 ;
V_611 &= ( V_614 - 1 ) ;
F_76 ( ! F_22 ( V_25 , V_12 ) , V_1 ) ;
V_611 += V_609 ;
V_521 <<= ( V_614 - V_611 - 1 ) ;
V_43 <<= ( V_614 - V_611 - 1 ) ;
V_613 = F_221 ( V_610 [ V_612 ] ) ;
for (; ; ) {
V_615 = F_567 ( & V_610 [ V_612 ] , V_613 , ( V_613 & ~ V_521 ) | V_43 ) ;
if ( V_613 == V_615 )
break;
V_613 = V_615 ;
}
}
bool F_568 ( struct V_25 * V_25 , struct V_1 * V_1 , int V_82 ,
bool V_616 )
{
unsigned long V_12 , V_617 , V_618 ;
int V_93 ;
if ( F_312 ( V_25 ) == V_450 )
return false ;
V_93 = F_87 ( V_1 ) ;
if ( V_93 == V_121 || F_210 ( V_93 ) )
return false ;
V_12 = F_20 ( V_1 ) ;
for ( V_618 = 0 , V_617 = 0 ; V_617 < V_118 ; V_617 ++ ) {
unsigned long V_619 = V_12 + V_617 ;
if ( ! F_27 ( V_619 ) )
continue;
V_1 = F_120 ( V_619 ) ;
if ( F_569 ( V_1 ) ) {
V_617 = F_554 ( V_617 + 1 , 1 << F_42 ( V_1 ) ) - 1 ;
continue;
}
if ( ! F_92 ( V_1 ) ) {
if ( F_78 ( V_1 ) )
V_617 += ( 1 << F_74 ( V_1 ) ) - 1 ;
continue;
}
if ( V_616 && F_31 ( V_1 ) )
continue;
if ( ! F_570 ( V_1 ) )
V_618 ++ ;
if ( V_618 > V_82 )
return true ;
}
return false ;
}
bool F_571 ( struct V_1 * V_1 )
{
struct V_25 * V_25 ;
unsigned long V_12 ;
if ( ! F_407 ( F_201 ( V_1 ) ) )
return false ;
V_25 = F_28 ( V_1 ) ;
V_12 = F_20 ( V_1 ) ;
if ( ! F_22 ( V_25 , V_12 ) )
return false ;
return ! F_568 ( V_25 , V_1 , 0 , true ) ;
}
static unsigned long F_572 ( unsigned long V_12 )
{
return V_12 & ~ ( F_536 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_573 ( unsigned long V_12 )
{
return F_157 ( V_12 , F_536 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_574 ( struct V_620 * V_621 ,
unsigned long V_100 , unsigned long V_101 )
{
unsigned long V_622 ;
unsigned long V_12 = V_100 ;
unsigned int V_623 = 0 ;
int V_26 = 0 ;
F_575 () ;
while ( V_12 < V_101 || ! F_99 ( & V_621 -> V_624 ) ) {
if ( F_576 ( V_41 ) ) {
V_26 = - V_625 ;
break;
}
if ( F_99 ( & V_621 -> V_624 ) ) {
V_621 -> V_626 = 0 ;
V_12 = F_577 ( V_621 , V_12 , V_101 ) ;
if ( ! V_12 ) {
V_26 = - V_625 ;
break;
}
V_623 = 0 ;
} else if ( ++ V_623 == 5 ) {
V_26 = V_26 < 0 ? V_26 : - V_627 ;
break;
}
V_622 = F_578 ( V_621 -> V_25 ,
& V_621 -> V_624 ) ;
V_621 -> V_626 -= V_622 ;
V_26 = F_579 ( & V_621 -> V_624 , V_628 ,
NULL , 0 , V_621 -> V_214 , V_629 ) ;
}
if ( V_26 < 0 ) {
F_580 ( & V_621 -> V_624 ) ;
return V_26 ;
}
return 0 ;
}
int F_581 ( unsigned long V_100 , unsigned long V_101 ,
unsigned V_3 )
{
unsigned long V_630 , V_631 ;
unsigned int V_46 ;
int V_26 = 0 ;
struct V_620 V_621 = {
. V_626 = 0 ,
. V_46 = - 1 ,
. V_25 = F_28 ( F_120 ( V_100 ) ) ,
. V_214 = V_632 ,
. V_633 = true ,
} ;
F_62 ( & V_621 . V_624 ) ;
V_26 = F_582 ( F_572 ( V_100 ) ,
F_573 ( V_101 ) , V_3 ,
false ) ;
if ( V_26 )
return V_26 ;
V_26 = F_574 ( & V_621 , V_100 , V_101 ) ;
if ( V_26 && V_26 != - V_627 )
goto V_634;
F_583 () ;
F_227 ( V_621 . V_25 ) ;
V_46 = 0 ;
V_630 = V_100 ;
while ( ! F_78 ( F_120 ( V_630 ) ) ) {
if ( ++ V_46 >= V_58 ) {
V_630 = V_100 ;
break;
}
V_630 &= ~ 0UL << V_46 ;
}
if ( V_630 != V_100 ) {
V_46 = F_74 ( F_120 ( V_630 ) ) ;
if ( V_630 + ( 1UL << V_46 ) <= V_100 )
V_630 = V_100 ;
}
if ( F_584 ( V_630 , V_101 , false ) ) {
F_57 ( L_108 ,
V_635 , V_630 , V_101 ) ;
V_26 = - V_627 ;
goto V_634;
}
V_631 = F_585 ( & V_621 , V_630 , V_101 ) ;
if ( ! V_631 ) {
V_26 = - V_627 ;
goto V_634;
}
if ( V_100 != V_630 )
F_586 ( V_630 , V_100 - V_630 ) ;
if ( V_101 != V_631 )
F_586 ( V_101 , V_631 - V_101 ) ;
V_634:
F_587 ( F_572 ( V_100 ) ,
F_573 ( V_101 ) , V_3 ) ;
return V_26 ;
}
void F_586 ( unsigned long V_12 , unsigned V_48 )
{
unsigned int V_82 = 0 ;
for (; V_48 -- ; V_12 ++ ) {
struct V_1 * V_1 = F_120 ( V_12 ) ;
V_82 += F_77 ( V_1 ) != 1 ;
F_588 ( V_1 ) ;
}
F_589 ( V_82 != 0 , L_109 , V_82 ) ;
}
void T_2 F_590 ( struct V_25 * V_25 )
{
unsigned V_182 ;
F_394 ( & V_593 ) ;
F_410 (cpu)
F_444 ( V_25 ,
F_223 ( V_25 -> V_185 , V_182 ) ) ;
F_299 ( & V_593 ) ;
}
void F_591 ( struct V_25 * V_25 )
{
unsigned long V_43 ;
int V_182 ;
struct V_183 * V_184 ;
F_142 ( V_43 ) ;
if ( V_25 -> V_185 != & V_429 ) {
F_228 (cpu) {
V_184 = F_223 ( V_25 -> V_185 , V_182 ) ;
F_592 ( V_25 , V_184 ) ;
}
F_593 ( V_25 -> V_185 ) ;
V_25 -> V_185 = & V_429 ;
}
F_144 ( V_43 ) ;
}
void
F_594 ( unsigned long V_29 , unsigned long V_102 )
{
struct V_1 * V_1 ;
struct V_25 * V_25 ;
unsigned int V_46 , V_47 ;
unsigned long V_12 ;
unsigned long V_43 ;
for ( V_12 = V_29 ; V_12 < V_102 ; V_12 ++ )
if ( F_126 ( V_12 ) )
break;
if ( V_12 == V_102 )
return;
V_25 = F_28 ( F_120 ( V_12 ) ) ;
F_209 ( & V_25 -> V_88 , V_43 ) ;
V_12 = V_29 ;
while ( V_12 < V_102 ) {
if ( ! F_126 ( V_12 ) ) {
V_12 ++ ;
continue;
}
V_1 = F_120 ( V_12 ) ;
if ( F_17 ( ! F_78 ( V_1 ) && F_31 ( V_1 ) ) ) {
V_12 ++ ;
F_127 ( V_1 ) ;
continue;
}
F_168 ( F_77 ( V_1 ) ) ;
F_168 ( ! F_78 ( V_1 ) ) ;
V_46 = F_74 ( V_1 ) ;
#ifdef V_96
F_57 ( L_110 ,
V_12 , 1 << V_46 , V_102 ) ;
#endif
F_85 ( & V_1 -> V_62 ) ;
F_70 ( V_1 ) ;
V_25 -> V_72 [ V_46 ] . V_73 -- ;
for ( V_47 = 0 ; V_47 < ( 1 << V_46 ) ; V_47 ++ )
F_127 ( ( V_1 + V_47 ) ) ;
V_12 += ( 1 << V_46 ) ;
}
F_211 ( & V_25 -> V_88 , V_43 ) ;
}
bool F_595 ( struct V_1 * V_1 )
{
struct V_25 * V_25 = F_28 ( V_1 ) ;
unsigned long V_12 = F_20 ( V_1 ) ;
unsigned long V_43 ;
unsigned int V_46 ;
F_209 ( & V_25 -> V_88 , V_43 ) ;
for ( V_46 = 0 ; V_46 < V_58 ; V_46 ++ ) {
struct V_1 * V_636 = V_1 - ( V_12 & ( ( 1 << V_46 ) - 1 ) ) ;
if ( F_78 ( V_636 ) && F_74 ( V_636 ) >= V_46 )
break;
}
F_211 ( & V_25 -> V_88 , V_43 ) ;
return V_46 < V_58 ;
}
