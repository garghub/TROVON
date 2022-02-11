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
void F_6 ( struct V_5 * V_5 , int V_6 )
{
if ( F_7 ( V_7 &&
V_6 < V_8 ) )
V_6 = V_9 ;
F_8 ( V_5 , ( unsigned long ) V_6 ,
V_10 , V_11 ) ;
}
static int F_9 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
int V_13 = 0 ;
unsigned V_14 ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_16 , V_17 ;
do {
V_14 = F_11 ( V_12 ) ;
V_17 = V_12 -> V_18 ;
V_16 = V_12 -> V_19 ;
if ( ! F_12 ( V_12 , V_15 ) )
V_13 = 1 ;
} while ( F_13 ( V_12 , V_14 ) );
if ( V_13 )
F_14 ( L_1 ,
V_15 , F_15 ( V_12 ) , V_12 -> V_20 ,
V_17 , V_17 + V_16 ) ;
return V_13 ;
}
static int F_16 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
if ( ! F_17 ( F_10 ( V_5 ) ) )
return 0 ;
if ( V_12 != F_18 ( V_5 ) )
return 0 ;
return 1 ;
}
static int F_19 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
if ( F_9 ( V_12 , V_5 ) )
return 1 ;
if ( ! F_16 ( V_12 , V_5 ) )
return 1 ;
return 0 ;
}
static inline int F_19 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
return 0 ;
}
static void F_20 ( struct V_5 * V_5 , const char * V_21 ,
unsigned long V_22 )
{
static unsigned long V_23 ;
static unsigned long V_24 ;
static unsigned long V_25 ;
if ( F_21 ( V_5 ) ) {
F_22 ( V_5 ) ;
return;
}
if ( V_24 == 60 ) {
if ( F_23 ( V_26 , V_23 ) ) {
V_25 ++ ;
goto V_27;
}
if ( V_25 ) {
F_24 ( V_28
L_2 ,
V_25 ) ;
V_25 = 0 ;
}
V_24 = 0 ;
}
if ( V_24 ++ == 0 )
V_23 = V_26 + 60 * V_29 ;
F_24 ( V_28 L_3 ,
V_30 -> V_31 , F_10 ( V_5 ) ) ;
F_25 ( V_5 , V_21 , V_22 ) ;
F_26 () ;
F_27 () ;
V_27:
F_22 ( V_5 ) ;
F_28 ( V_32 , V_33 ) ;
}
static void F_29 ( struct V_5 * V_5 )
{
F_30 ( V_5 , F_31 ( V_5 ) ) ;
}
void F_32 ( struct V_5 * V_5 , unsigned long V_34 )
{
int V_35 ;
int V_36 = 1 << V_34 ;
F_33 ( V_5 , F_29 ) ;
F_34 ( V_5 , V_34 ) ;
F_35 ( V_5 ) ;
for ( V_35 = 1 ; V_35 < V_36 ; V_35 ++ ) {
struct V_5 * V_37 = V_5 + V_35 ;
F_36 ( V_37 , 0 ) ;
V_37 -> V_38 = V_5 ;
F_37 () ;
F_38 ( V_37 ) ;
}
}
static inline void F_39 ( struct V_5 * V_5 , unsigned int V_34 ,
T_1 V_39 )
{
int V_35 ;
F_40 ( ( V_39 & V_40 ) && F_41 () ) ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_42 ( V_5 + V_35 ) ;
}
static int T_2 F_43 ( char * V_41 )
{
if ( ! V_41 )
return - V_42 ;
if ( strcmp ( V_41 , L_4 ) == 0 )
V_43 = true ;
return 0 ;
}
static bool F_44 ( void )
{
if ( ! F_45 () )
return false ;
return true ;
}
static void F_46 ( void )
{
if ( ! F_45 () )
return;
V_44 = true ;
}
static int T_2 F_47 ( char * V_41 )
{
unsigned long V_45 ;
if ( F_48 ( V_41 , 10 , & V_45 ) < 0 || V_45 > V_46 / 2 ) {
F_24 ( V_47 L_5 ) ;
return 0 ;
}
V_48 = V_45 ;
F_24 ( V_49 L_6 , V_45 ) ;
return 0 ;
}
static inline void F_49 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 )
{
struct V_50 * V_50 ;
if ( ! F_50 () )
return;
V_50 = F_51 ( V_5 ) ;
F_52 ( V_51 , & V_50 -> V_52 ) ;
F_53 ( & V_5 -> V_53 ) ;
F_54 ( V_5 , V_34 ) ;
F_55 ( V_12 , - ( 1 << V_34 ) , V_6 ) ;
}
static inline void F_56 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 )
{
struct V_50 * V_50 ;
if ( ! F_50 () )
return;
V_50 = F_51 ( V_5 ) ;
F_57 ( V_51 , & V_50 -> V_52 ) ;
F_54 ( V_5 , 0 ) ;
if ( ! F_58 ( V_6 ) )
F_55 ( V_12 , ( 1 << V_34 ) , V_6 ) ;
}
static inline void F_49 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 ) {}
static inline void F_56 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 ) {}
static inline void F_59 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_54 ( V_5 , V_34 ) ;
F_60 ( V_5 ) ;
}
static inline void F_61 ( struct V_5 * V_5 )
{
F_62 ( V_5 ) ;
F_54 ( V_5 , 0 ) ;
}
static inline int F_63 ( struct V_5 * V_5 , struct V_5 * V_54 ,
unsigned int V_34 )
{
if ( ! F_17 ( F_10 ( V_54 ) ) )
return 0 ;
if ( F_64 ( V_54 ) && F_65 ( V_54 ) == V_34 ) {
if ( F_66 ( V_5 ) != F_66 ( V_54 ) )
return 0 ;
F_67 ( F_68 ( V_54 ) != 0 , V_54 ) ;
return 1 ;
}
if ( F_69 ( V_54 ) && F_65 ( V_54 ) == V_34 ) {
if ( F_66 ( V_5 ) != F_66 ( V_54 ) )
return 0 ;
F_67 ( F_68 ( V_54 ) != 0 , V_54 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_70 ( struct V_5 * V_5 ,
unsigned long V_15 ,
struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned long V_55 ;
unsigned long V_56 ;
unsigned long V_57 ( V_58 ) ;
struct V_5 * V_54 ;
int V_59 = V_46 ;
F_40 ( ! F_71 ( V_12 ) ) ;
F_67 ( V_5 -> V_52 & V_60 , V_5 ) ;
F_40 ( V_6 == - 1 ) ;
if ( F_58 ( V_6 ) ) {
V_59 = F_72 ( V_46 , V_61 + 1 ) ;
} else {
F_55 ( V_12 , 1 << V_34 , V_6 ) ;
}
V_55 = V_15 & ( ( 1 << V_59 ) - 1 ) ;
F_67 ( V_55 & ( ( 1 << V_34 ) - 1 ) , V_5 ) ;
F_67 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
while ( V_34 < V_59 - 1 ) {
V_58 = F_73 ( V_55 , V_34 ) ;
V_54 = V_5 + ( V_58 - V_55 ) ;
if ( ! F_63 ( V_5 , V_54 , V_34 ) )
break;
if ( F_64 ( V_54 ) ) {
F_56 ( V_12 , V_54 , V_34 , V_6 ) ;
} else {
F_74 ( & V_54 -> V_53 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
F_61 ( V_54 ) ;
}
V_56 = V_58 & V_55 ;
V_5 = V_5 + ( V_56 - V_55 ) ;
V_55 = V_56 ;
V_34 ++ ;
}
F_59 ( V_5 , V_34 ) ;
if ( ( V_34 < V_46 - 2 ) && F_17 ( F_10 ( V_54 ) ) ) {
struct V_5 * V_64 , * V_65 ;
V_56 = V_58 & V_55 ;
V_64 = V_5 + ( V_56 - V_55 ) ;
V_58 = F_73 ( V_56 , V_34 + 1 ) ;
V_65 = V_64 + ( V_58 - V_56 ) ;
if ( F_63 ( V_64 , V_65 , V_34 + 1 ) ) {
F_75 ( & V_5 -> V_53 ,
& V_12 -> V_62 [ V_34 ] . V_66 [ V_6 ] ) ;
goto V_27;
}
}
F_76 ( & V_5 -> V_53 , & V_12 -> V_62 [ V_34 ] . V_66 [ V_6 ] ) ;
V_27:
V_12 -> V_62 [ V_34 ] . V_63 ++ ;
}
static inline int F_77 ( struct V_5 * V_5 )
{
const char * V_67 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_78 ( V_5 ) ) )
V_67 = L_7 ;
if ( F_7 ( V_5 -> V_68 != NULL ) )
V_67 = L_8 ;
if ( F_7 ( F_79 ( & V_5 -> V_69 ) != 0 ) )
V_67 = L_9 ;
if ( F_7 ( V_5 -> V_52 & V_70 ) ) {
V_67 = L_10 ;
V_22 = V_70 ;
}
#ifdef F_80
if ( F_7 ( V_5 -> V_71 ) )
V_67 = L_11 ;
#endif
if ( F_7 ( V_67 ) ) {
F_20 ( V_5 , V_67 , V_22 ) ;
return 1 ;
}
F_81 ( V_5 ) ;
if ( V_5 -> V_52 & V_60 )
V_5 -> V_52 &= ~ V_60 ;
return 0 ;
}
static void F_82 ( struct V_12 * V_12 , int V_72 ,
struct V_73 * V_74 )
{
int V_6 = 0 ;
int V_75 = 0 ;
int V_76 = V_72 ;
unsigned long V_77 ;
F_83 ( & V_12 -> V_78 ) ;
V_77 = F_84 ( V_12 , V_79 ) ;
if ( V_77 )
F_85 ( V_12 , V_79 , - V_77 ) ;
while ( V_76 ) {
struct V_5 * V_5 ;
struct V_80 * V_81 ;
do {
V_75 ++ ;
if ( ++ V_6 == V_8 )
V_6 = 0 ;
V_81 = & V_74 -> V_82 [ V_6 ] ;
} while ( F_86 ( V_81 ) );
if ( V_75 == V_8 )
V_75 = V_76 ;
do {
int V_83 ;
V_5 = F_87 ( V_81 -> V_84 , struct V_5 , V_53 ) ;
F_74 ( & V_5 -> V_53 ) ;
V_83 = F_88 ( V_5 ) ;
if ( F_7 ( F_89 ( V_12 ) ) )
V_83 = F_90 ( V_5 ) ;
F_70 ( V_5 , F_10 ( V_5 ) , V_12 , 0 , V_83 ) ;
F_91 ( V_5 , 0 , V_83 ) ;
} while ( -- V_76 && -- V_75 && ! F_86 ( V_81 ) );
}
F_92 ( & V_12 -> V_78 ) ;
}
static void F_93 ( struct V_12 * V_12 ,
struct V_5 * V_5 , unsigned long V_15 ,
unsigned int V_34 ,
int V_6 )
{
unsigned long V_77 ;
F_83 ( & V_12 -> V_78 ) ;
V_77 = F_84 ( V_12 , V_79 ) ;
if ( V_77 )
F_85 ( V_12 , V_79 , - V_77 ) ;
if ( F_7 ( F_89 ( V_12 ) ||
F_58 ( V_6 ) ) ) {
V_6 = F_94 ( V_5 , V_15 ) ;
}
F_70 ( V_5 , V_15 , V_12 , V_34 , V_6 ) ;
F_92 ( & V_12 -> V_78 ) ;
}
static int F_95 ( struct V_5 * V_85 , struct V_5 * V_5 )
{
if ( ! F_96 ( V_86 ) )
return 0 ;
if ( F_7 ( ! F_97 ( V_5 ) ) ) {
F_20 ( V_5 , L_12 , 0 ) ;
return 1 ;
}
if ( F_7 ( V_5 -> V_38 != V_85 ) ) {
F_20 ( V_5 , L_13 , 0 ) ;
return 1 ;
}
return 0 ;
}
static bool F_98 ( struct V_5 * V_5 , unsigned int V_34 )
{
bool V_87 = F_99 ( V_5 ) ;
int V_35 , V_88 = 0 ;
F_67 ( F_97 ( V_5 ) , V_5 ) ;
F_67 ( V_87 && F_31 ( V_5 ) != V_34 , V_5 ) ;
F_100 ( V_5 , V_34 ) ;
F_101 ( V_5 , V_34 ) ;
F_102 ( V_5 , V_34 ) ;
if ( F_103 ( V_5 ) )
V_5 -> V_68 = NULL ;
V_88 += F_77 ( V_5 ) ;
for ( V_35 = 1 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
if ( V_87 )
V_88 += F_95 ( V_5 , V_5 + V_35 ) ;
V_88 += F_77 ( V_5 + V_35 ) ;
}
if ( V_88 )
return false ;
F_104 ( V_5 , V_34 ) ;
if ( ! F_105 ( V_5 ) ) {
F_106 ( F_107 ( V_5 ) ,
V_89 << V_34 ) ;
F_108 ( F_107 ( V_5 ) ,
V_89 << V_34 ) ;
}
F_109 ( V_5 , V_34 ) ;
F_110 ( V_5 , 1 << V_34 , 0 ) ;
return true ;
}
static void F_30 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_52 ;
int V_6 ;
unsigned long V_15 = F_10 ( V_5 ) ;
if ( ! F_98 ( V_5 , V_34 ) )
return;
V_6 = F_94 ( V_5 , V_15 ) ;
F_111 ( V_52 ) ;
F_112 ( V_90 , 1 << V_34 ) ;
F_113 ( V_5 , V_6 ) ;
F_93 ( F_18 ( V_5 ) , V_5 , V_15 , V_34 , V_6 ) ;
F_114 ( V_52 ) ;
}
void T_2 F_115 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned int V_36 = 1 << V_34 ;
struct V_5 * V_37 = V_5 ;
unsigned int V_91 ;
F_116 ( V_37 ) ;
for ( V_91 = 0 ; V_91 < ( V_36 - 1 ) ; V_91 ++ , V_37 ++ ) {
F_116 ( V_37 + 1 ) ;
F_117 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
}
F_117 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
F_18 ( V_5 ) -> V_92 += V_36 ;
F_118 ( V_5 ) ;
F_119 ( V_5 , V_34 ) ;
}
void T_2 F_120 ( struct V_5 * V_5 )
{
unsigned V_35 = V_93 ;
struct V_5 * V_37 = V_5 ;
do {
F_117 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
} while ( ++ V_37 , -- V_35 );
F_6 ( V_5 , V_94 ) ;
if ( V_61 >= V_46 ) {
V_35 = V_93 ;
V_37 = V_5 ;
do {
F_118 ( V_37 ) ;
F_119 ( V_37 , V_46 - 1 ) ;
V_37 += V_95 ;
} while ( V_35 -= V_95 );
} else {
F_118 ( V_5 ) ;
F_119 ( V_5 , V_61 ) ;
}
F_121 ( V_5 , V_93 ) ;
}
static inline void F_122 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_96 , int V_97 , struct V_62 * V_98 ,
int V_6 )
{
unsigned long V_99 = 1 << V_97 ;
while ( V_97 > V_96 ) {
V_98 -- ;
V_97 -- ;
V_99 >>= 1 ;
F_67 ( F_19 ( V_12 , & V_5 [ V_99 ] ) , & V_5 [ V_99 ] ) ;
if ( F_96 ( V_100 ) &&
F_50 () &&
V_97 < F_123 () ) {
F_49 ( V_12 , & V_5 [ V_99 ] , V_97 , V_6 ) ;
continue;
}
F_76 ( & V_5 [ V_99 ] . V_53 , & V_98 -> V_66 [ V_6 ] ) ;
V_98 -> V_63 ++ ;
F_59 ( & V_5 [ V_99 ] , V_97 ) ;
}
}
static inline int F_124 ( struct V_5 * V_5 )
{
const char * V_67 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_78 ( V_5 ) ) )
V_67 = L_7 ;
if ( F_7 ( V_5 -> V_68 != NULL ) )
V_67 = L_8 ;
if ( F_7 ( F_79 ( & V_5 -> V_69 ) != 0 ) )
V_67 = L_9 ;
if ( F_7 ( V_5 -> V_52 & V_60 ) ) {
V_67 = L_14 ;
V_22 = V_60 ;
}
#ifdef F_80
if ( F_7 ( V_5 -> V_71 ) )
V_67 = L_11 ;
#endif
if ( F_7 ( V_67 ) ) {
F_20 ( V_5 , V_67 , V_22 ) ;
return 1 ;
}
return 0 ;
}
static int F_125 ( struct V_5 * V_5 , unsigned int V_34 , T_1 V_39 ,
int V_101 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
struct V_5 * V_37 = V_5 + V_35 ;
if ( F_7 ( F_124 ( V_37 ) ) )
return 1 ;
}
F_54 ( V_5 , 0 ) ;
F_118 ( V_5 ) ;
F_126 ( V_5 , V_34 ) ;
F_110 ( V_5 , 1 << V_34 , 1 ) ;
F_127 ( V_5 , V_34 ) ;
if ( V_39 & V_102 )
F_39 ( V_5 , V_34 , V_39 ) ;
if ( V_34 && ( V_39 & V_103 ) )
F_32 ( V_5 , V_34 ) ;
F_128 ( V_5 , V_34 , V_39 ) ;
V_5 -> V_104 = ! ! ( V_101 & V_105 ) ;
return 0 ;
}
static inline
struct V_5 * F_129 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned int V_106 ;
struct V_62 * V_98 ;
struct V_5 * V_5 ;
for ( V_106 = V_34 ; V_106 < V_46 ; ++ V_106 ) {
V_98 = & ( V_12 -> V_62 [ V_106 ] ) ;
if ( F_86 ( & V_98 -> V_66 [ V_6 ] ) )
continue;
V_5 = F_87 ( V_98 -> V_66 [ V_6 ] . V_107 ,
struct V_5 , V_53 ) ;
F_74 ( & V_5 -> V_53 ) ;
F_61 ( V_5 ) ;
V_98 -> V_63 -- ;
F_122 ( V_12 , V_5 , V_34 , V_106 , V_98 , V_6 ) ;
F_113 ( V_5 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
static struct V_5 * F_130 ( struct V_12 * V_12 ,
unsigned int V_34 )
{
return F_129 ( V_12 , V_34 , V_94 ) ;
}
static inline struct V_5 * F_130 ( struct V_12 * V_12 ,
unsigned int V_34 ) { return NULL ; }
int F_131 ( struct V_12 * V_12 ,
struct V_5 * V_108 , struct V_5 * V_109 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_34 ;
int V_110 = 0 ;
#ifndef F_132
F_40 ( F_18 ( V_108 ) != F_18 ( V_109 ) ) ;
#endif
for ( V_5 = V_108 ; V_5 <= V_109 ; ) {
F_67 ( F_133 ( V_5 ) != F_15 ( V_12 ) , V_5 ) ;
if ( ! F_17 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_69 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_34 = F_65 ( V_5 ) ;
F_134 ( & V_5 -> V_53 ,
& V_12 -> V_62 [ V_34 ] . V_66 [ V_6 ] ) ;
F_113 ( V_5 , V_6 ) ;
V_5 += 1 << V_34 ;
V_110 += 1 << V_34 ;
}
return V_110 ;
}
int F_135 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_17 , V_111 ;
struct V_5 * V_108 , * V_109 ;
V_17 = F_10 ( V_5 ) ;
V_17 = V_17 & ~ ( V_93 - 1 ) ;
V_108 = F_136 ( V_17 ) ;
V_109 = V_108 + V_93 - 1 ;
V_111 = V_17 + V_93 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_108 = V_5 ;
if ( ! F_12 ( V_12 , V_111 ) )
return 0 ;
return F_131 ( V_12 , V_108 , V_109 , V_6 ) ;
}
static void F_137 ( struct V_5 * V_112 ,
int V_113 , int V_6 )
{
int V_114 = 1 << ( V_113 - V_61 ) ;
while ( V_114 -- ) {
F_6 ( V_112 , V_6 ) ;
V_112 += V_93 ;
}
}
static bool F_138 ( unsigned int V_34 , int V_115 )
{
if ( V_34 >= V_61 )
return true ;
if ( V_34 >= V_61 / 2 ||
V_115 == V_116 ||
V_115 == V_9 ||
V_7 )
return true ;
return false ;
}
static void F_139 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_117 )
{
int V_106 = F_65 ( V_5 ) ;
int V_118 ;
if ( V_106 >= V_61 ) {
F_137 ( V_5 , V_106 , V_117 ) ;
return;
}
V_118 = F_135 ( V_12 , V_5 , V_117 ) ;
if ( V_118 >= ( 1 << ( V_61 - 1 ) ) ||
V_7 )
F_6 ( V_5 , V_117 ) ;
}
int F_140 ( struct V_62 * V_98 , unsigned int V_34 ,
int V_6 , bool V_119 , bool * V_120 )
{
int V_35 ;
int V_121 ;
if ( V_98 -> V_63 == 0 )
return - 1 ;
* V_120 = false ;
for ( V_35 = 0 ; ; V_35 ++ ) {
V_121 = V_122 [ V_6 ] [ V_35 ] ;
if ( V_121 == V_123 )
break;
if ( F_86 ( & V_98 -> V_66 [ V_121 ] ) )
continue;
if ( F_138 ( V_34 , V_6 ) )
* V_120 = true ;
if ( ! V_119 )
return V_121 ;
if ( * V_120 )
return V_121 ;
}
return - 1 ;
}
static inline struct V_5 *
F_141 ( struct V_12 * V_12 , unsigned int V_34 , int V_124 )
{
struct V_62 * V_98 ;
unsigned int V_106 ;
struct V_5 * V_5 ;
int V_121 ;
bool V_120 ;
for ( V_106 = V_46 - 1 ;
V_106 >= V_34 && V_106 <= V_46 - 1 ;
-- V_106 ) {
V_98 = & ( V_12 -> V_62 [ V_106 ] ) ;
V_121 = F_140 ( V_98 , V_106 ,
V_124 , false , & V_120 ) ;
if ( V_121 == - 1 )
continue;
V_5 = F_87 ( V_98 -> V_66 [ V_121 ] . V_107 ,
struct V_5 , V_53 ) ;
if ( V_120 )
F_139 ( V_12 , V_5 , V_124 ) ;
V_98 -> V_63 -- ;
F_74 ( & V_5 -> V_53 ) ;
F_61 ( V_5 ) ;
F_122 ( V_12 , V_5 , V_34 , V_106 , V_98 ,
V_124 ) ;
F_113 ( V_5 , V_124 ) ;
F_142 ( V_5 , V_34 , V_106 ,
V_124 , V_121 ) ;
return V_5 ;
}
return NULL ;
}
static struct V_5 * F_143 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
struct V_5 * V_5 ;
V_125:
V_5 = F_129 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_123 ) {
if ( V_6 == V_126 )
V_5 = F_130 ( V_12 , V_34 ) ;
if ( ! V_5 )
V_5 = F_141 ( V_12 , V_34 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_123 ;
goto V_125;
}
}
F_144 ( V_5 , V_34 , V_6 ) ;
return V_5 ;
}
static int F_145 ( struct V_12 * V_12 , unsigned int V_34 ,
unsigned long V_72 , struct V_80 * V_81 ,
int V_6 , bool V_127 )
{
int V_35 ;
F_83 ( & V_12 -> V_78 ) ;
for ( V_35 = 0 ; V_35 < V_72 ; ++ V_35 ) {
struct V_5 * V_5 = F_143 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_146 ( ! V_127 ) )
F_76 ( & V_5 -> V_53 , V_81 ) ;
else
F_75 ( & V_5 -> V_53 , V_81 ) ;
V_81 = & V_5 -> V_53 ;
if ( F_147 ( F_88 ( V_5 ) ) )
F_85 ( V_12 , V_128 ,
- ( 1 << V_34 ) ) ;
}
F_85 ( V_12 , V_129 , - ( V_35 << V_34 ) ) ;
F_92 ( & V_12 -> V_78 ) ;
return V_35 ;
}
void F_148 ( struct V_12 * V_12 , struct V_73 * V_74 )
{
unsigned long V_52 ;
int V_130 , V_131 ;
F_111 ( V_52 ) ;
V_131 = F_149 ( V_74 -> V_131 ) ;
V_130 = F_72 ( V_74 -> V_72 , V_131 ) ;
if ( V_130 > 0 ) {
F_82 ( V_12 , V_130 , V_74 ) ;
V_74 -> V_72 -= V_130 ;
}
F_114 ( V_52 ) ;
}
static void F_150 ( unsigned int V_132 , struct V_12 * V_12 )
{
unsigned long V_52 ;
struct V_133 * V_134 ;
struct V_73 * V_74 ;
F_111 ( V_52 ) ;
V_134 = F_151 ( V_12 -> V_135 , V_132 ) ;
V_74 = & V_134 -> V_74 ;
if ( V_74 -> V_72 ) {
F_82 ( V_12 , V_74 -> V_72 , V_74 ) ;
V_74 -> V_72 = 0 ;
}
F_114 ( V_52 ) ;
}
static void F_152 ( unsigned int V_132 )
{
struct V_12 * V_12 ;
F_153 (zone) {
F_150 ( V_132 , V_12 ) ;
}
}
void F_154 ( struct V_12 * V_12 )
{
int V_132 = F_155 () ;
if ( V_12 )
F_150 ( V_132 , V_12 ) ;
else
F_152 ( V_132 ) ;
}
void F_156 ( struct V_12 * V_12 )
{
int V_132 ;
static T_3 V_136 ;
F_157 (cpu) {
struct V_133 * V_74 ;
struct V_12 * V_137 ;
bool V_138 = false ;
if ( V_12 ) {
V_74 = F_151 ( V_12 -> V_135 , V_132 ) ;
if ( V_74 -> V_74 . V_72 )
V_138 = true ;
} else {
F_153 (z) {
V_74 = F_151 ( V_137 -> V_135 , V_132 ) ;
if ( V_74 -> V_74 . V_72 ) {
V_138 = true ;
break;
}
}
}
if ( V_138 )
F_158 ( V_132 , & V_136 ) ;
else
F_159 ( V_132 , & V_136 ) ;
}
F_160 ( & V_136 , ( V_139 ) F_154 ,
V_12 , 1 ) ;
}
void F_161 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_140 ;
unsigned long V_52 ;
unsigned int V_34 , V_141 ;
struct V_80 * V_142 ;
if ( F_162 ( V_12 ) )
return;
F_163 ( & V_12 -> V_78 , V_52 ) ;
V_140 = F_164 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_140 ; V_15 ++ )
if ( F_165 ( V_15 ) ) {
struct V_5 * V_5 = F_136 ( V_15 ) ;
if ( ! F_166 ( V_5 ) )
F_167 ( V_5 ) ;
}
F_168 (order, t) {
F_169 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_35 ;
V_15 = F_10 ( F_87 ( V_142 , struct V_5 , V_53 ) ) ;
for ( V_35 = 0 ; V_35 < ( 1UL << V_34 ) ; V_35 ++ )
F_170 ( F_136 ( V_15 + V_35 ) ) ;
}
}
F_171 ( & V_12 -> V_78 , V_52 ) ;
}
void F_172 ( struct V_5 * V_5 , bool V_127 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
struct V_73 * V_74 ;
unsigned long V_52 ;
unsigned long V_15 = F_10 ( V_5 ) ;
int V_6 ;
if ( ! F_98 ( V_5 , 0 ) )
return;
V_6 = F_94 ( V_5 , V_15 ) ;
F_113 ( V_5 , V_6 ) ;
F_111 ( V_52 ) ;
F_173 ( V_90 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_58 ( V_6 ) ) ) {
F_93 ( V_12 , V_5 , V_15 , 0 , V_6 ) ;
goto V_27;
}
V_6 = V_126 ;
}
V_74 = & F_174 ( V_12 -> V_135 ) -> V_74 ;
if ( ! V_127 )
F_76 ( & V_5 -> V_53 , & V_74 -> V_82 [ V_6 ] ) ;
else
F_75 ( & V_5 -> V_53 , & V_74 -> V_82 [ V_6 ] ) ;
V_74 -> V_72 ++ ;
if ( V_74 -> V_72 >= V_74 -> V_97 ) {
unsigned long V_131 = F_149 ( V_74 -> V_131 ) ;
F_82 ( V_12 , V_131 , V_74 ) ;
V_74 -> V_72 -= V_131 ;
}
V_27:
F_114 ( V_52 ) ;
}
void F_175 ( struct V_80 * V_81 , bool V_127 )
{
struct V_5 * V_5 , * V_107 ;
F_176 (page, next, list, lru) {
F_177 ( V_5 , V_127 ) ;
F_172 ( V_5 , V_127 ) ;
}
}
void F_178 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
F_67 ( F_99 ( V_5 ) , V_5 ) ;
F_67 ( ! F_68 ( V_5 ) , V_5 ) ;
#ifdef F_179
if ( F_180 ( V_5 ) )
F_178 ( F_181 ( V_5 [ 0 ] . V_143 ) , V_34 ) ;
#endif
F_128 ( V_5 , 0 , 0 ) ;
for ( V_35 = 1 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
F_118 ( V_5 + V_35 ) ;
F_128 ( V_5 + V_35 , 0 , 0 ) ;
}
}
int F_182 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_144 ;
struct V_12 * V_12 ;
int V_83 ;
F_183 ( ! F_69 ( V_5 ) ) ;
V_12 = F_18 ( V_5 ) ;
V_83 = F_90 ( V_5 ) ;
if ( ! F_58 ( V_83 ) ) {
V_144 = F_184 ( V_12 ) + ( 1 << V_34 ) ;
if ( ! F_185 ( V_12 , 0 , V_144 , 0 , 0 ) )
return 0 ;
F_55 ( V_12 , - ( 1UL << V_34 ) , V_83 ) ;
}
F_74 ( & V_5 -> V_53 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
F_61 ( V_5 ) ;
if ( V_34 >= V_61 - 1 ) {
struct V_5 * V_145 = V_5 + ( 1 << V_34 ) - 1 ;
for (; V_5 < V_145 ; V_5 += V_93 ) {
int V_83 = F_90 ( V_5 ) ;
if ( ! F_58 ( V_83 ) && ! F_147 ( V_83 ) )
F_6 ( V_5 ,
V_126 ) ;
}
}
F_128 ( V_5 , V_34 , 0 ) ;
return 1UL << V_34 ;
}
int F_186 ( struct V_5 * V_5 )
{
unsigned int V_34 ;
int V_36 ;
V_34 = F_65 ( V_5 ) ;
V_36 = F_182 ( V_5 , V_34 ) ;
if ( ! V_36 )
return 0 ;
F_118 ( V_5 ) ;
F_178 ( V_5 , V_34 ) ;
return V_36 ;
}
static inline
struct V_5 * F_187 ( struct V_12 * V_146 ,
struct V_12 * V_12 , unsigned int V_34 ,
T_1 V_39 , int V_6 )
{
unsigned long V_52 ;
struct V_5 * V_5 ;
bool V_127 = ( ( V_39 & V_147 ) != 0 ) ;
if ( F_146 ( V_34 == 0 ) ) {
struct V_73 * V_74 ;
struct V_80 * V_81 ;
F_111 ( V_52 ) ;
V_74 = & F_174 ( V_12 -> V_135 ) -> V_74 ;
V_81 = & V_74 -> V_82 [ V_6 ] ;
if ( F_86 ( V_81 ) ) {
V_74 -> V_72 += F_145 ( V_12 , 0 ,
V_74 -> V_131 , V_81 ,
V_6 , V_127 ) ;
if ( F_7 ( F_86 ( V_81 ) ) )
goto V_148;
}
if ( V_127 )
V_5 = F_87 ( V_81 -> V_84 , struct V_5 , V_53 ) ;
else
V_5 = F_87 ( V_81 -> V_107 , struct V_5 , V_53 ) ;
F_74 ( & V_5 -> V_53 ) ;
V_74 -> V_72 -- ;
} else {
if ( F_7 ( V_39 & V_149 ) ) {
F_188 ( V_34 > 1 ) ;
}
F_163 ( & V_12 -> V_78 , V_52 ) ;
V_5 = F_143 ( V_12 , V_34 , V_6 ) ;
F_92 ( & V_12 -> V_78 ) ;
if ( ! V_5 )
goto V_148;
F_55 ( V_12 , - ( 1 << V_34 ) ,
F_88 ( V_5 ) ) ;
}
F_85 ( V_12 , V_150 , - ( 1 << V_34 ) ) ;
if ( F_189 ( & V_12 -> V_151 [ V_150 ] ) <= 0 &&
! F_190 ( V_152 , & V_12 -> V_52 ) )
F_191 ( V_152 , & V_12 -> V_52 ) ;
F_192 ( V_153 , V_12 , 1 << V_34 ) ;
F_193 ( V_146 , V_12 , V_39 ) ;
F_114 ( V_52 ) ;
F_67 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
return V_5 ;
V_148:
F_114 ( V_52 ) ;
return NULL ;
}
static int T_2 F_194 ( char * V_154 )
{
return F_195 ( & V_155 . V_156 , V_154 ) ;
}
static bool F_196 ( T_1 V_157 , unsigned int V_34 )
{
if ( V_34 < V_155 . V_158 )
return false ;
if ( V_157 & V_149 )
return false ;
if ( V_155 . V_159 && ( V_157 & V_40 ) )
return false ;
if ( V_155 . V_160 && ( V_157 & V_161 ) )
return false ;
return F_197 ( & V_155 . V_156 , 1 << V_34 ) ;
}
static int T_2 F_198 ( void )
{
T_4 V_162 = V_163 | V_164 | V_165 ;
struct V_166 * V_167 ;
V_167 = F_199 ( L_15 , NULL ,
& V_155 . V_156 ) ;
if ( F_200 ( V_167 ) )
return F_201 ( V_167 ) ;
if ( ! F_202 ( L_16 , V_162 , V_167 ,
& V_155 . V_160 ) )
goto V_168;
if ( ! F_202 ( L_17 , V_162 , V_167 ,
& V_155 . V_159 ) )
goto V_168;
if ( ! F_203 ( L_18 , V_162 , V_167 ,
& V_155 . V_158 ) )
goto V_168;
return 0 ;
V_168:
F_204 ( V_167 ) ;
return - V_169 ;
}
static inline bool F_196 ( T_1 V_157 , unsigned int V_34 )
{
return false ;
}
static bool F_205 ( struct V_12 * V_137 , unsigned int V_34 ,
unsigned long V_170 , int V_171 , int V_101 ,
long V_172 )
{
long F_72 = V_170 ;
int V_173 ;
long V_174 = 0 ;
V_172 -= ( 1 << V_34 ) - 1 ;
if ( V_101 & V_175 )
F_72 -= F_72 / 2 ;
if ( V_101 & V_176 )
F_72 -= F_72 / 4 ;
#ifdef F_206
if ( ! ( V_101 & V_177 ) )
V_174 = F_84 ( V_137 , V_128 ) ;
#endif
if ( V_172 - V_174 <= F_72 + V_137 -> V_178 [ V_171 ] )
return false ;
for ( V_173 = 0 ; V_173 < V_34 ; V_173 ++ ) {
V_172 -= V_137 -> V_62 [ V_173 ] . V_63 << V_173 ;
F_72 >>= 1 ;
if ( V_172 <= F_72 )
return false ;
}
return true ;
}
bool F_185 ( struct V_12 * V_137 , unsigned int V_34 , unsigned long V_170 ,
int V_171 , int V_101 )
{
return F_205 ( V_137 , V_34 , V_170 , V_171 , V_101 ,
F_84 ( V_137 , V_129 ) ) ;
}
bool F_207 ( struct V_12 * V_137 , unsigned int V_34 ,
unsigned long V_170 , int V_171 , int V_101 )
{
long V_172 = F_84 ( V_137 , V_129 ) ;
if ( V_137 -> V_179 && V_172 < V_137 -> V_179 )
V_172 = F_208 ( V_137 , V_129 ) ;
return F_205 ( V_137 , V_34 , V_170 , V_171 , V_101 ,
V_172 ) ;
}
static T_5 * F_209 ( struct V_180 * V_180 , int V_101 )
{
struct V_181 * V_182 ;
T_5 * V_183 ;
V_182 = V_180 -> V_184 ;
if ( ! V_182 )
return NULL ;
if ( F_210 ( V_26 , V_182 -> V_185 + V_29 ) ) {
F_211 ( V_182 -> V_186 , V_187 ) ;
V_182 -> V_185 = V_26 ;
}
V_183 = ! F_41 () && ( V_101 & V_188 ) ?
& V_189 :
& V_190 [ V_191 ] ;
return V_183 ;
}
static int F_212 ( struct V_180 * V_180 , struct V_192 * V_137 ,
T_5 * V_183 )
{
struct V_181 * V_182 ;
int V_35 ;
int V_193 ;
V_182 = V_180 -> V_184 ;
if ( ! V_182 )
return 1 ;
V_35 = V_137 - V_180 -> V_194 ;
V_193 = V_182 -> V_195 [ V_35 ] ;
return F_213 ( V_193 , * V_183 ) && ! F_190 ( V_35 , V_182 -> V_186 ) ;
}
static void F_214 ( struct V_180 * V_180 , struct V_192 * V_137 )
{
struct V_181 * V_182 ;
int V_35 ;
V_182 = V_180 -> V_184 ;
if ( ! V_182 )
return;
V_35 = V_137 - V_180 -> V_194 ;
F_191 ( V_35 , V_182 -> V_186 ) ;
}
static void F_215 ( struct V_180 * V_180 )
{
struct V_181 * V_182 ;
V_182 = V_180 -> V_184 ;
if ( ! V_182 )
return;
F_211 ( V_182 -> V_186 , V_187 ) ;
}
static bool F_216 ( struct V_12 * V_196 , struct V_12 * V_12 )
{
return V_196 -> V_197 == V_12 -> V_197 ;
}
static bool F_217 ( struct V_12 * V_196 , struct V_12 * V_12 )
{
return F_218 ( F_15 ( V_196 ) , F_15 ( V_12 ) ) <
V_198 ;
}
static T_5 * F_209 ( struct V_180 * V_180 , int V_101 )
{
return NULL ;
}
static int F_212 ( struct V_180 * V_180 , struct V_192 * V_137 ,
T_5 * V_183 )
{
return 1 ;
}
static void F_214 ( struct V_180 * V_180 , struct V_192 * V_137 )
{
}
static void F_215 ( struct V_180 * V_180 )
{
}
static bool F_216 ( struct V_12 * V_196 , struct V_12 * V_12 )
{
return true ;
}
static bool F_217 ( struct V_12 * V_196 , struct V_12 * V_12 )
{
return true ;
}
static void F_219 ( struct V_12 * V_146 )
{
struct V_12 * V_12 = V_146 -> V_199 -> V_200 ;
do {
F_220 ( V_12 , V_150 ,
F_221 ( V_12 ) - F_184 ( V_12 ) -
F_189 ( & V_12 -> V_151 [ V_150 ] ) ) ;
F_222 ( V_152 , & V_12 -> V_52 ) ;
} while ( V_12 ++ != V_146 );
}
static struct V_5 *
F_223 ( T_1 V_157 , unsigned int V_34 , int V_101 ,
const struct V_201 * V_202 )
{
struct V_180 * V_180 = V_202 -> V_180 ;
struct V_192 * V_137 ;
struct V_5 * V_5 = NULL ;
struct V_12 * V_12 ;
T_5 * V_183 = NULL ;
int V_203 = 0 ;
int V_204 = 0 ;
bool V_205 = ( V_101 & V_206 ) &&
( V_157 & V_207 ) ;
int V_208 = 0 ;
bool V_209 ;
V_210:
V_209 = false ;
F_224 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_170 ;
if ( F_96 ( V_211 ) && V_203 &&
! F_212 ( V_180 , V_137 , V_183 ) )
continue;
if ( F_225 () &&
( V_101 & V_188 ) &&
! F_226 ( V_12 , V_157 ) )
continue;
if ( V_101 & V_212 ) {
if ( ! F_216 ( V_202 -> V_146 , V_12 ) )
break;
if ( F_190 ( V_152 , & V_12 -> V_52 ) ) {
V_208 ++ ;
continue;
}
}
if ( V_205 && ! F_227 ( V_12 ) )
continue;
V_170 = V_12 -> V_144 [ V_101 & V_213 ] ;
if ( ! F_185 ( V_12 , V_34 , V_170 ,
V_202 -> V_171 , V_101 ) ) {
int V_13 ;
F_228 ( V_105 < V_214 ) ;
if ( V_101 & V_105 )
goto V_215;
if ( F_96 ( V_211 ) &&
! V_204 && V_216 > 1 ) {
V_183 = F_209 ( V_180 , V_101 ) ;
V_203 = 1 ;
V_204 = 1 ;
}
if ( V_217 == 0 ||
! F_217 ( V_202 -> V_146 , V_12 ) )
goto V_218;
if ( F_96 ( V_211 ) && V_203 &&
! F_212 ( V_180 , V_137 , V_183 ) )
continue;
V_13 = F_229 ( V_12 , V_157 , V_34 ) ;
switch ( V_13 ) {
case V_219 :
continue;
case V_220 :
continue;
default:
if ( F_185 ( V_12 , V_34 , V_170 ,
V_202 -> V_171 , V_101 ) )
goto V_215;
if ( ( ( V_101 & V_213 ) == V_221 ) ||
V_13 == V_222 )
goto V_218;
continue;
}
}
V_215:
V_5 = F_187 ( V_202 -> V_146 , V_12 , V_34 ,
V_157 , V_202 -> V_6 ) ;
if ( V_5 ) {
if ( F_125 ( V_5 , V_34 , V_157 , V_101 ) )
goto V_215;
return V_5 ;
}
V_218:
if ( F_96 ( V_211 ) && V_203 )
F_214 ( V_180 , V_137 ) ;
}
if ( V_101 & V_212 ) {
V_101 &= ~ V_212 ;
if ( V_208 ) {
V_209 = true ;
F_219 ( V_202 -> V_146 ) ;
}
if ( V_216 > 1 )
V_209 = true ;
}
if ( F_7 ( F_96 ( V_211 ) && V_203 ) ) {
V_203 = 0 ;
V_209 = true ;
}
if ( V_209 )
goto V_210;
return NULL ;
}
static inline bool F_230 ( void )
{
bool V_13 = false ;
#if V_223 > 8
V_13 = F_41 () ;
#endif
return V_13 ;
}
void F_231 ( T_1 V_157 , int V_34 , const char * V_224 , ... )
{
unsigned int V_225 = V_226 ;
if ( ( V_157 & V_227 ) || ! F_232 ( & V_228 ) ||
F_123 () > 0 )
return;
if ( ! ( V_157 & V_229 ) )
if ( F_233 ( V_230 ) ||
( V_30 -> V_52 & ( V_231 | V_232 ) ) )
V_225 &= ~ V_226 ;
if ( F_41 () || ! ( V_157 & V_161 ) )
V_225 &= ~ V_226 ;
if ( V_224 ) {
struct V_233 V_234 ;
T_6 args ;
va_start ( args , V_224 ) ;
V_234 . V_224 = V_224 ;
V_234 . V_235 = & args ;
F_234 ( L_19 , & V_234 ) ;
va_end ( args ) ;
}
F_234 ( L_20 ,
V_30 -> V_31 , V_34 , V_157 ) ;
F_27 () ;
if ( ! F_230 () )
F_235 ( V_225 ) ;
}
static inline int
F_236 ( T_1 V_157 , unsigned int V_34 ,
unsigned long V_236 ,
unsigned long V_237 )
{
if ( V_157 & V_238 )
return 0 ;
if ( V_157 & V_149 )
return 1 ;
if ( ! V_236 && F_5 () )
return 0 ;
if ( V_34 <= V_239 )
return 1 ;
if ( V_157 & V_240 && V_237 < ( 1 << V_34 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_237 ( T_1 V_157 , unsigned int V_34 ,
const struct V_201 * V_202 , unsigned long * V_236 )
{
struct V_5 * V_5 ;
* V_236 = 0 ;
if ( ! F_238 ( V_202 -> V_180 , V_157 ) ) {
* V_236 = 1 ;
F_239 ( 1 ) ;
return NULL ;
}
V_5 = F_223 ( V_157 | V_241 , V_34 ,
V_242 | V_188 , V_202 ) ;
if ( V_5 )
goto V_27;
if ( ! ( V_157 & V_149 ) ) {
if ( V_30 -> V_52 & V_243 )
goto V_27;
if ( V_34 > V_239 )
goto V_27;
if ( V_202 -> V_244 < V_245 )
goto V_27;
if ( ! ( V_157 & V_246 ) ) {
* V_236 = 1 ;
goto V_27;
}
if ( V_157 & V_247 )
goto V_27;
}
if ( F_240 ( V_202 -> V_180 , V_157 , V_34 , V_202 -> V_248 , false )
|| F_188 ( V_157 & V_149 ) )
* V_236 = 1 ;
V_27:
F_241 ( V_202 -> V_180 , V_157 ) ;
return V_5 ;
}
static struct V_5 *
F_242 ( T_1 V_157 , unsigned int V_34 ,
int V_101 , const struct V_201 * V_202 ,
enum V_249 V_162 , int * V_250 ,
bool * V_251 )
{
unsigned long V_252 ;
struct V_5 * V_5 ;
if ( ! V_34 )
return NULL ;
V_30 -> V_52 |= V_231 ;
V_252 = F_243 ( V_157 , V_34 , V_101 , V_202 ,
V_162 , V_250 ) ;
V_30 -> V_52 &= ~ V_231 ;
switch ( V_252 ) {
case V_253 :
* V_251 = true ;
case V_254 :
return NULL ;
default:
break;
}
F_244 ( V_255 ) ;
V_5 = F_223 ( V_157 , V_34 ,
V_101 & ~ V_105 , V_202 ) ;
if ( V_5 ) {
struct V_12 * V_12 = F_18 ( V_5 ) ;
V_12 -> V_256 = false ;
F_245 ( V_12 , V_34 , true ) ;
F_244 ( V_257 ) ;
return V_5 ;
}
F_244 ( V_258 ) ;
F_246 () ;
return NULL ;
}
static inline struct V_5 *
F_242 ( T_1 V_157 , unsigned int V_34 ,
int V_101 , const struct V_201 * V_202 ,
enum V_249 V_162 , int * V_250 ,
bool * V_251 )
{
return NULL ;
}
static int
F_247 ( T_1 V_157 , unsigned int V_34 ,
const struct V_201 * V_202 )
{
struct V_259 V_259 ;
int V_260 ;
F_246 () ;
F_248 () ;
V_30 -> V_52 |= V_231 ;
F_249 ( V_157 ) ;
V_259 . V_261 = 0 ;
V_30 -> V_259 = & V_259 ;
V_260 = F_250 ( V_202 -> V_180 , V_34 , V_157 ,
V_202 -> V_248 ) ;
V_30 -> V_259 = NULL ;
F_251 () ;
V_30 -> V_52 &= ~ V_231 ;
F_246 () ;
return V_260 ;
}
static inline struct V_5 *
F_252 ( T_1 V_157 , unsigned int V_34 ,
int V_101 , const struct V_201 * V_202 ,
unsigned long * V_236 )
{
struct V_5 * V_5 = NULL ;
bool V_262 = false ;
* V_236 = F_247 ( V_157 , V_34 , V_202 ) ;
if ( F_7 ( ! ( * V_236 ) ) )
return NULL ;
if ( F_96 ( V_211 ) )
F_215 ( V_202 -> V_180 ) ;
V_263:
V_5 = F_223 ( V_157 , V_34 ,
V_101 & ~ V_105 , V_202 ) ;
if ( ! V_5 && ! V_262 ) {
F_156 ( NULL ) ;
V_262 = true ;
goto V_263;
}
return V_5 ;
}
static inline struct V_5 *
F_253 ( T_1 V_157 , unsigned int V_34 ,
const struct V_201 * V_202 )
{
struct V_5 * V_5 ;
do {
V_5 = F_223 ( V_157 , V_34 ,
V_105 , V_202 ) ;
if ( ! V_5 && V_157 & V_149 )
F_254 ( V_202 -> V_146 , V_264 ,
V_29 / 50 ) ;
} while ( ! V_5 && ( V_157 & V_149 ) );
return V_5 ;
}
static void F_255 ( unsigned int V_34 , const struct V_201 * V_202 )
{
struct V_192 * V_137 ;
struct V_12 * V_12 ;
F_224 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_256 ( V_12 , V_34 , F_257 ( V_202 -> V_146 ) ) ;
}
static inline int
F_258 ( T_1 V_157 )
{
int V_101 = V_221 | V_188 ;
const bool V_265 = ! ( V_157 & ( V_161 | V_266 ) ) ;
F_228 ( V_267 != ( V_268 T_1 ) V_175 ) ;
V_101 |= ( V_268 int ) ( V_157 & V_267 ) ;
if ( V_265 ) {
if ( ! ( V_157 & V_229 ) )
V_101 |= V_176 ;
V_101 &= ~ V_188 ;
} else if ( F_7 ( F_259 ( V_30 ) ) && ! F_41 () )
V_101 |= V_176 ;
if ( F_146 ( ! ( V_157 & V_229 ) ) ) {
if ( V_157 & V_269 )
V_101 |= V_105 ;
else if ( F_260 () && ( V_30 -> V_52 & V_231 ) )
V_101 |= V_105 ;
else if ( ! F_41 () &&
( ( V_30 -> V_52 & V_231 ) ||
F_7 ( F_233 ( V_230 ) ) ) )
V_101 |= V_105 ;
}
#ifdef F_206
if ( F_261 ( V_157 ) == V_126 )
V_101 |= V_177 ;
#endif
return V_101 ;
}
bool F_262 ( T_1 V_157 )
{
return ! ! ( F_258 ( V_157 ) & V_105 ) ;
}
static inline struct V_5 *
F_263 ( T_1 V_157 , unsigned int V_34 ,
struct V_201 * V_202 )
{
const T_1 V_270 = V_157 & V_161 ;
struct V_5 * V_5 = NULL ;
int V_101 ;
unsigned long V_237 = 0 ;
unsigned long V_236 ;
enum V_249 V_271 = V_272 ;
bool V_251 = false ;
int V_250 = V_273 ;
if ( V_34 >= V_46 ) {
F_188 ( ! ( V_157 & V_227 ) ) ;
return NULL ;
}
if ( F_96 ( V_211 ) && ( V_157 & V_247 ) && ! V_270 )
goto V_274;
V_263:
if ( ! ( V_157 & V_266 ) )
F_255 ( V_34 , V_202 ) ;
V_101 = F_258 ( V_157 ) ;
if ( ! ( V_101 & V_188 ) && ! V_202 -> V_248 ) {
struct V_192 * V_275 ;
V_275 = F_264 ( V_202 -> V_180 ,
V_202 -> V_244 , NULL , & V_202 -> V_146 ) ;
V_202 -> V_171 = F_265 ( V_275 ) ;
}
V_5 = F_223 ( V_157 , V_34 ,
V_101 & ~ V_105 , V_202 ) ;
if ( V_5 )
goto V_276;
if ( V_101 & V_105 ) {
V_202 -> V_180 = F_266 ( F_267 () , V_157 ) ;
V_5 = F_253 ( V_157 , V_34 , V_202 ) ;
if ( V_5 ) {
goto V_276;
}
}
if ( ! V_270 ) {
F_188 ( V_157 & V_149 ) ;
goto V_274;
}
if ( V_30 -> V_52 & V_231 )
goto V_274;
if ( F_233 ( V_230 ) && ! ( V_157 & V_149 ) )
goto V_274;
V_5 = F_242 ( V_157 , V_34 , V_101 , V_202 ,
V_271 ,
& V_250 ,
& V_251 ) ;
if ( V_5 )
goto V_276;
if ( ( V_157 & V_277 ) == V_277 ) {
if ( V_251 )
goto V_274;
if ( V_250 == V_278 )
goto V_274;
if ( V_250 == V_279
&& ! ( V_30 -> V_52 & V_280 ) )
goto V_274;
}
if ( ( V_157 & V_277 ) != V_277 ||
( V_30 -> V_52 & V_280 ) )
V_271 = V_281 ;
V_5 = F_252 ( V_157 , V_34 , V_101 , V_202 ,
& V_236 ) ;
if ( V_5 )
goto V_276;
V_237 += V_236 ;
if ( F_236 ( V_157 , V_34 , V_236 ,
V_237 ) ) {
if ( ! V_236 ) {
V_5 = F_237 ( V_157 , V_34 , V_202 ,
& V_236 ) ;
if ( V_5 )
goto V_276;
if ( ! V_236 )
goto V_274;
}
F_254 ( V_202 -> V_146 , V_264 , V_29 / 50 ) ;
goto V_263;
} else {
V_5 = F_242 ( V_157 , V_34 ,
V_101 , V_202 , V_271 ,
& V_250 ,
& V_251 ) ;
if ( V_5 )
goto V_276;
}
V_274:
F_231 ( V_157 , V_34 , NULL ) ;
V_276:
return V_5 ;
}
struct V_5 *
F_268 ( T_1 V_157 , unsigned int V_34 ,
struct V_180 * V_180 , T_5 * V_248 )
{
struct V_192 * V_275 ;
struct V_5 * V_5 = NULL ;
unsigned int V_282 ;
int V_101 = V_206 | V_188 | V_212 ;
T_1 V_283 ;
struct V_201 V_202 = {
. V_244 = F_269 ( V_157 ) ,
. V_248 = V_248 ,
. V_6 = F_261 ( V_157 ) ,
} ;
V_157 &= V_3 ;
F_270 ( V_157 ) ;
F_271 ( V_157 & V_161 ) ;
if ( F_196 ( V_157 , V_34 ) )
return NULL ;
if ( F_7 ( ! V_180 -> V_194 -> V_12 ) )
return NULL ;
if ( F_96 ( F_206 ) && V_202 . V_6 == V_126 )
V_101 |= V_177 ;
V_284:
V_282 = F_272 () ;
V_202 . V_180 = V_180 ;
V_275 = F_264 ( V_202 . V_180 , V_202 . V_244 ,
V_202 . V_248 ? : & V_189 ,
& V_202 . V_146 ) ;
if ( ! V_202 . V_146 )
goto V_27;
V_202 . V_171 = F_265 ( V_275 ) ;
V_283 = V_157 | V_241 ;
V_5 = F_223 ( V_283 , V_34 , V_101 , & V_202 ) ;
if ( F_7 ( ! V_5 ) ) {
V_283 = F_273 ( V_157 ) ;
V_5 = F_263 ( V_283 , V_34 , & V_202 ) ;
}
if ( V_285 && V_5 )
F_274 ( V_5 , V_34 , V_157 ) ;
F_275 ( V_5 , V_34 , V_283 , V_202 . V_6 ) ;
V_27:
if ( F_7 ( ! V_5 && F_276 ( V_282 ) ) )
goto V_284;
return V_5 ;
}
unsigned long F_277 ( T_1 V_157 , unsigned int V_34 )
{
struct V_5 * V_5 ;
F_40 ( ( V_157 & V_40 ) != 0 ) ;
V_5 = F_278 ( V_157 , V_34 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_107 ( V_5 ) ;
}
unsigned long F_279 ( T_1 V_157 )
{
return F_277 ( V_157 | V_102 , 0 ) ;
}
void F_119 ( struct V_5 * V_5 , unsigned int V_34 )
{
if ( F_280 ( V_5 ) ) {
if ( V_34 == 0 )
F_172 ( V_5 , false ) ;
else
F_30 ( V_5 , V_34 ) ;
}
}
void V_172 ( unsigned long V_286 , unsigned int V_34 )
{
if ( V_286 != 0 ) {
F_40 ( ! F_281 ( ( void * ) V_286 ) ) ;
F_119 ( F_181 ( ( void * ) V_286 ) , V_34 ) ;
}
}
struct V_5 * F_282 ( T_1 V_157 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_71 * V_287 = NULL ;
if ( ! F_283 ( V_157 , & V_287 , V_34 ) )
return NULL ;
V_5 = F_278 ( V_157 , V_34 ) ;
F_284 ( V_5 , V_287 , V_34 ) ;
return V_5 ;
}
struct V_5 * F_285 ( int V_288 , T_1 V_157 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_71 * V_287 = NULL ;
if ( ! F_283 ( V_157 , & V_287 , V_34 ) )
return NULL ;
V_5 = F_286 ( V_288 , V_157 , V_34 ) ;
F_284 ( V_5 , V_287 , V_34 ) ;
return V_5 ;
}
void F_287 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_288 ( V_5 , V_34 ) ;
F_119 ( V_5 , V_34 ) ;
}
void F_289 ( unsigned long V_286 , unsigned int V_34 )
{
if ( V_286 != 0 ) {
F_40 ( ! F_281 ( ( void * ) V_286 ) ) ;
F_287 ( F_181 ( ( void * ) V_286 ) , V_34 ) ;
}
}
static void * F_290 ( unsigned long V_286 , unsigned V_34 , T_7 V_99 )
{
if ( V_286 ) {
unsigned long V_289 = V_286 + ( V_89 << V_34 ) ;
unsigned long V_290 = V_286 + F_291 ( V_99 ) ;
F_178 ( F_181 ( ( void * ) V_286 ) , V_34 ) ;
while ( V_290 < V_289 ) {
F_292 ( V_290 ) ;
V_290 += V_89 ;
}
}
return ( void * ) V_286 ;
}
void * F_293 ( T_7 V_99 , T_1 V_157 )
{
unsigned int V_34 = F_294 ( V_99 ) ;
unsigned long V_286 ;
V_286 = F_277 ( V_157 , V_34 ) ;
return F_290 ( V_286 , V_34 , V_99 ) ;
}
void * T_8 F_295 ( int V_288 , T_7 V_99 , T_1 V_157 )
{
unsigned V_34 = F_294 ( V_99 ) ;
struct V_5 * V_37 = F_286 ( V_288 , V_157 , V_34 ) ;
if ( ! V_37 )
return NULL ;
return F_290 ( ( unsigned long ) F_107 ( V_37 ) , V_34 , V_99 ) ;
}
void F_296 ( void * V_291 , T_7 V_99 )
{
unsigned long V_286 = ( unsigned long ) V_291 ;
unsigned long V_292 = V_286 + F_291 ( V_99 ) ;
while ( V_286 < V_292 ) {
F_292 ( V_286 ) ;
V_286 += V_89 ;
}
}
static unsigned long F_297 ( int V_293 )
{
struct V_192 * V_137 ;
struct V_12 * V_12 ;
unsigned long V_294 = 0 ;
struct V_180 * V_180 = F_266 ( F_267 () , V_295 ) ;
F_298 (zone, z, zonelist, offset) {
unsigned long V_99 = V_12 -> V_92 ;
unsigned long V_97 = F_221 ( V_12 ) ;
if ( V_99 > V_97 )
V_294 += V_99 - V_97 ;
}
return V_294 ;
}
unsigned long F_299 ( void )
{
return F_297 ( F_269 ( V_296 ) ) ;
}
unsigned long F_300 ( void )
{
return F_297 ( F_269 ( V_297 ) ) ;
}
static inline void F_301 ( struct V_12 * V_12 )
{
if ( F_96 ( V_211 ) )
F_24 ( L_21 , F_15 ( V_12 ) ) ;
}
void F_302 ( struct V_298 * V_299 )
{
V_299 -> V_300 = V_301 ;
V_299 -> V_302 = F_303 ( V_303 ) ;
V_299 -> V_304 = F_303 ( V_129 ) ;
V_299 -> V_305 = F_304 () ;
V_299 -> V_306 = V_307 ;
V_299 -> V_308 = F_305 () ;
V_299 -> V_309 = V_89 ;
}
void F_306 ( struct V_298 * V_299 , int V_288 )
{
int V_310 ;
unsigned long V_92 = 0 ;
T_9 * V_311 = F_307 ( V_288 ) ;
for ( V_310 = 0 ; V_310 < V_312 ; V_310 ++ )
V_92 += V_311 -> V_200 [ V_310 ] . V_92 ;
V_299 -> V_300 = V_92 ;
V_299 -> V_302 = F_308 ( V_288 , V_303 ) ;
V_299 -> V_304 = F_308 ( V_288 , V_129 ) ;
#ifdef F_309
V_299 -> V_306 = V_311 -> V_200 [ V_313 ] . V_92 ;
V_299 -> V_308 = F_84 ( & V_311 -> V_200 [ V_313 ] ,
V_129 ) ;
#else
V_299 -> V_306 = 0 ;
V_299 -> V_308 = 0 ;
#endif
V_299 -> V_309 = V_89 ;
}
bool F_310 ( unsigned int V_52 , int V_288 )
{
bool V_13 = false ;
unsigned int V_282 ;
if ( ! ( V_52 & V_226 ) )
goto V_27;
do {
V_282 = F_272 () ;
V_13 = ! F_213 ( V_288 , V_189 ) ;
} while ( F_276 ( V_282 ) );
V_27:
return V_13 ;
}
static void F_311 ( unsigned char type )
{
static const char V_314 [ V_315 ] = {
[ V_9 ] = 'U' ,
[ V_116 ] = 'E' ,
[ V_126 ] = 'M' ,
[ V_123 ] = 'R' ,
#ifdef F_206
[ V_94 ] = 'C' ,
#endif
#ifdef F_312
[ V_316 ] = 'I' ,
#endif
} ;
char V_317 [ V_315 + 1 ] ;
char * V_37 = V_317 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_315 ; V_35 ++ ) {
if ( type & ( 1 << V_35 ) )
* V_37 ++ = V_314 [ V_35 ] ;
}
* V_37 = '\0' ;
F_24 ( L_22 , V_317 ) ;
}
void F_313 ( unsigned int V_225 )
{
unsigned long V_318 = 0 ;
int V_132 ;
struct V_12 * V_12 ;
F_153 (zone) {
if ( F_310 ( V_225 , F_15 ( V_12 ) ) )
continue;
F_157 (cpu)
V_318 += F_151 ( V_12 -> V_135 , V_132 ) -> V_74 . V_72 ;
}
F_24 ( L_23
L_24
L_25
L_26
L_27
L_28 ,
F_303 ( V_319 ) ,
F_303 ( V_320 ) ,
F_303 ( V_321 ) ,
F_303 ( V_322 ) ,
F_303 ( V_323 ) ,
F_303 ( V_324 ) ,
F_303 ( V_325 ) ,
F_303 ( V_326 ) ,
F_303 ( V_327 ) ,
F_303 ( V_328 ) ,
F_303 ( V_329 ) ,
F_303 ( V_330 ) ,
F_303 ( V_331 ) ,
F_303 ( V_303 ) ,
F_303 ( V_332 ) ,
F_303 ( V_333 ) ,
F_303 ( V_129 ) ,
V_318 ,
F_303 ( V_128 ) ) ;
F_153 (zone) {
int V_35 ;
if ( F_310 ( V_225 , F_15 ( V_12 ) ) )
continue;
V_318 = 0 ;
F_157 (cpu)
V_318 += F_151 ( V_12 -> V_135 , V_132 ) -> V_74 . V_72 ;
F_301 ( V_12 ) ;
F_24 ( L_29
L_30
L_31
L_32
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
L_60 ,
V_12 -> V_20 ,
F_314 ( F_84 ( V_12 , V_129 ) ) ,
F_314 ( F_315 ( V_12 ) ) ,
F_314 ( F_184 ( V_12 ) ) ,
F_314 ( F_221 ( V_12 ) ) ,
F_314 ( F_84 ( V_12 , V_319 ) ) ,
F_314 ( F_84 ( V_12 , V_320 ) ) ,
F_314 ( F_84 ( V_12 , V_322 ) ) ,
F_314 ( F_84 ( V_12 , V_323 ) ) ,
F_314 ( F_84 ( V_12 , V_325 ) ) ,
F_314 ( F_84 ( V_12 , V_321 ) ) ,
F_314 ( F_84 ( V_12 , V_324 ) ) ,
F_314 ( V_12 -> V_334 ) ,
F_314 ( V_12 -> V_92 ) ,
F_314 ( F_84 ( V_12 , V_335 ) ) ,
F_314 ( F_84 ( V_12 , V_326 ) ) ,
F_314 ( F_84 ( V_12 , V_327 ) ) ,
F_314 ( F_84 ( V_12 , V_331 ) ) ,
F_314 ( F_84 ( V_12 , V_303 ) ) ,
F_314 ( F_84 ( V_12 , V_329 ) ) ,
F_314 ( F_84 ( V_12 , V_330 ) ) ,
F_84 ( V_12 , V_336 ) *
V_337 / 1024 ,
F_314 ( F_84 ( V_12 , V_332 ) ) ,
F_314 ( F_84 ( V_12 , V_328 ) ) ,
F_314 ( F_84 ( V_12 , V_333 ) ) ,
F_314 ( V_318 ) ,
F_314 ( F_316 ( V_12 -> V_135 -> V_74 . V_72 ) ) ,
F_314 ( F_84 ( V_12 , V_128 ) ) ,
F_314 ( F_84 ( V_12 , V_338 ) ) ,
F_314 ( F_84 ( V_12 , V_79 ) ) ,
( ! F_317 ( V_12 ) ? L_61 : L_62 )
) ;
F_24 ( L_63 ) ;
for ( V_35 = 0 ; V_35 < V_312 ; V_35 ++ )
F_24 ( L_64 , V_12 -> V_178 [ V_35 ] ) ;
F_24 ( L_60 ) ;
}
F_153 (zone) {
unsigned long V_339 [ V_46 ] , V_52 , V_34 , V_340 = 0 ;
unsigned char V_314 [ V_46 ] ;
if ( F_310 ( V_225 , F_15 ( V_12 ) ) )
continue;
F_301 ( V_12 ) ;
F_24 ( L_65 , V_12 -> V_20 ) ;
F_163 ( & V_12 -> V_78 , V_52 ) ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
struct V_62 * V_98 = & V_12 -> V_62 [ V_34 ] ;
int type ;
V_339 [ V_34 ] = V_98 -> V_63 ;
V_340 += V_339 [ V_34 ] << V_34 ;
V_314 [ V_34 ] = 0 ;
for ( type = 0 ; type < V_315 ; type ++ ) {
if ( ! F_86 ( & V_98 -> V_66 [ type ] ) )
V_314 [ V_34 ] |= 1 << type ;
}
}
F_171 ( & V_12 -> V_78 , V_52 ) ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
F_24 ( L_66 , V_339 [ V_34 ] , F_314 ( 1UL ) << V_34 ) ;
if ( V_339 [ V_34 ] )
F_311 ( V_314 [ V_34 ] ) ;
}
F_24 ( L_67 , F_314 ( V_340 ) ) ;
}
F_318 () ;
F_24 ( L_68 , F_303 ( V_341 ) ) ;
F_319 () ;
}
static void F_320 ( struct V_12 * V_12 , struct V_192 * V_192 )
{
V_192 -> V_12 = V_12 ;
V_192 -> F_257 = F_257 ( V_12 ) ;
}
static int F_321 ( T_9 * V_311 , struct V_180 * V_180 ,
int V_342 )
{
struct V_12 * V_12 ;
enum V_310 V_310 = V_312 ;
do {
V_310 -- ;
V_12 = V_311 -> V_200 + V_310 ;
if ( F_322 ( V_12 ) ) {
F_320 ( V_12 ,
& V_180 -> V_194 [ V_342 ++ ] ) ;
F_323 ( V_310 ) ;
}
} while ( V_310 );
return V_342 ;
}
static int F_324 ( char * V_343 )
{
if ( * V_343 == 'd' || * V_343 == 'D' ) {
V_344 = V_345 ;
} else if ( * V_343 == 'n' || * V_343 == 'N' ) {
V_344 = V_346 ;
} else if ( * V_343 == 'z' || * V_343 == 'Z' ) {
V_344 = V_347 ;
} else {
F_24 ( V_348
L_69
L_70 , V_343 ) ;
return - V_42 ;
}
return 0 ;
}
static T_2 int F_325 ( char * V_343 )
{
int V_13 ;
if ( ! V_343 )
return 0 ;
V_13 = F_324 ( V_343 ) ;
if ( V_13 == 0 )
F_326 ( V_349 , V_343 , V_350 ) ;
return V_13 ;
}
int F_327 ( struct V_351 * V_352 , int V_353 ,
void T_10 * V_354 , T_7 * V_355 ,
T_11 * V_356 )
{
char V_357 [ V_350 ] ;
int V_13 ;
static F_328 ( V_358 ) ;
F_329 ( & V_358 ) ;
if ( V_353 ) {
if ( strlen ( ( char * ) V_352 -> V_359 ) >= V_350 ) {
V_13 = - V_42 ;
goto V_27;
}
strcpy ( V_357 , ( char * ) V_352 -> V_359 ) ;
}
V_13 = F_330 ( V_352 , V_353 , V_354 , V_355 , V_356 ) ;
if ( V_13 )
goto V_27;
if ( V_353 ) {
int V_360 = V_344 ;
V_13 = F_324 ( ( char * ) V_352 -> V_359 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_352 -> V_359 , V_357 ,
V_350 ) ;
V_344 = V_360 ;
} else if ( V_360 != V_344 ) {
F_329 ( & V_361 ) ;
F_331 ( NULL , NULL ) ;
F_332 ( & V_361 ) ;
}
}
V_27:
F_332 ( & V_358 ) ;
return V_13 ;
}
static int F_333 ( int V_197 , T_5 * V_362 )
{
int V_193 , V_299 ;
int V_363 = V_364 ;
int V_365 = V_366 ;
const struct V_367 * V_317 = F_334 ( 0 ) ;
if ( ! F_213 ( V_197 , * V_362 ) ) {
F_335 ( V_197 , * V_362 ) ;
return V_197 ;
}
F_336 (n, N_MEMORY) {
if ( F_213 ( V_193 , * V_362 ) )
continue;
V_299 = F_218 ( V_197 , V_193 ) ;
V_299 += ( V_193 < V_197 ) ;
V_317 = F_334 ( V_193 ) ;
if ( ! F_337 ( V_317 ) )
V_299 += V_368 ;
V_299 *= ( V_369 * V_370 ) ;
V_299 += V_371 [ V_193 ] ;
if ( V_299 < V_363 ) {
V_363 = V_299 ;
V_365 = V_193 ;
}
}
if ( V_365 >= 0 )
F_335 ( V_365 , * V_362 ) ;
return V_365 ;
}
static void F_338 ( T_9 * V_311 , int V_197 )
{
int V_372 ;
struct V_180 * V_180 ;
V_180 = & V_311 -> V_373 [ 0 ] ;
for ( V_372 = 0 ; V_180 -> V_194 [ V_372 ] . V_12 != NULL ; V_372 ++ )
;
V_372 = F_321 ( F_307 ( V_197 ) , V_180 , V_372 ) ;
V_180 -> V_194 [ V_372 ] . V_12 = NULL ;
V_180 -> V_194 [ V_372 ] . F_257 = 0 ;
}
static void F_339 ( T_9 * V_311 )
{
int V_372 ;
struct V_180 * V_180 ;
V_180 = & V_311 -> V_373 [ 1 ] ;
V_372 = F_321 ( V_311 , V_180 , 0 ) ;
V_180 -> V_194 [ V_372 ] . V_12 = NULL ;
V_180 -> V_194 [ V_372 ] . F_257 = 0 ;
}
static void F_340 ( T_9 * V_311 , int V_374 )
{
int V_375 , V_372 , V_197 ;
int V_310 ;
struct V_12 * V_137 ;
struct V_180 * V_180 ;
V_180 = & V_311 -> V_373 [ 0 ] ;
V_375 = 0 ;
for ( V_310 = V_312 - 1 ; V_310 >= 0 ; V_310 -- ) {
for ( V_372 = 0 ; V_372 < V_374 ; V_372 ++ ) {
V_197 = V_376 [ V_372 ] ;
V_137 = & F_307 ( V_197 ) -> V_200 [ V_310 ] ;
if ( F_322 ( V_137 ) ) {
F_320 ( V_137 ,
& V_180 -> V_194 [ V_375 ++ ] ) ;
F_323 ( V_310 ) ;
}
}
}
V_180 -> V_194 [ V_375 ] . V_12 = NULL ;
V_180 -> V_194 [ V_375 ] . F_257 = 0 ;
}
static int F_341 ( void )
{
return V_346 ;
}
static int F_341 ( void )
{
return V_347 ;
}
static void F_342 ( void )
{
if ( V_344 == V_345 )
V_377 = F_341 () ;
else
V_377 = V_344 ;
}
static void F_343 ( T_9 * V_311 )
{
int V_372 , V_197 , V_378 ;
enum V_310 V_35 ;
T_5 V_379 ;
int V_380 , V_381 ;
struct V_180 * V_180 ;
int V_34 = V_377 ;
for ( V_35 = 0 ; V_35 < V_382 ; V_35 ++ ) {
V_180 = V_311 -> V_373 + V_35 ;
V_180 -> V_194 [ 0 ] . V_12 = NULL ;
V_180 -> V_194 [ 0 ] . F_257 = 0 ;
}
V_380 = V_311 -> V_383 ;
V_378 = V_216 ;
V_381 = V_380 ;
F_344 ( V_379 ) ;
memset ( V_376 , 0 , sizeof( V_376 ) ) ;
V_372 = 0 ;
while ( ( V_197 = F_333 ( V_380 , & V_379 ) ) >= 0 ) {
if ( F_218 ( V_380 , V_197 ) !=
F_218 ( V_380 , V_381 ) )
V_371 [ V_197 ] = V_378 ;
V_381 = V_197 ;
V_378 -- ;
if ( V_34 == V_346 )
F_338 ( V_311 , V_197 ) ;
else
V_376 [ V_372 ++ ] = V_197 ;
}
if ( V_34 == V_347 ) {
F_340 ( V_311 , V_372 ) ;
}
F_339 ( V_311 ) ;
}
static void F_345 ( T_9 * V_311 )
{
struct V_180 * V_180 ;
struct V_181 * V_182 ;
struct V_192 * V_137 ;
V_180 = & V_311 -> V_373 [ 0 ] ;
V_180 -> V_184 = V_182 = & V_180 -> V_384 ;
F_211 ( V_182 -> V_186 , V_187 ) ;
for ( V_137 = V_180 -> V_194 ; V_137 -> V_12 ; V_137 ++ )
V_182 -> V_195 [ V_137 - V_180 -> V_194 ] = F_346 ( V_137 ) ;
}
int F_347 ( int V_197 )
{
struct V_12 * V_12 ;
( void ) F_264 ( F_266 ( V_197 , V_295 ) ,
F_269 ( V_295 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_197 ;
}
static void F_342 ( void )
{
V_377 = V_347 ;
}
static void F_343 ( T_9 * V_311 )
{
int V_197 , V_380 ;
enum V_310 V_372 ;
struct V_180 * V_180 ;
V_380 = V_311 -> V_383 ;
V_180 = & V_311 -> V_373 [ 0 ] ;
V_372 = F_321 ( V_311 , V_180 , 0 ) ;
for ( V_197 = V_380 + 1 ; V_197 < V_370 ; V_197 ++ ) {
if ( ! F_348 ( V_197 ) )
continue;
V_372 = F_321 ( F_307 ( V_197 ) , V_180 , V_372 ) ;
}
for ( V_197 = 0 ; V_197 < V_380 ; V_197 ++ ) {
if ( ! F_348 ( V_197 ) )
continue;
V_372 = F_321 ( F_307 ( V_197 ) , V_180 , V_372 ) ;
}
V_180 -> V_194 [ V_372 ] . V_12 = NULL ;
V_180 -> V_194 [ V_372 ] . F_257 = 0 ;
}
static void F_345 ( T_9 * V_311 )
{
V_311 -> V_373 [ 0 ] . V_184 = NULL ;
}
static int F_349 ( void * V_359 )
{
int V_288 ;
int V_132 ;
T_9 * V_385 = V_359 ;
#ifdef V_211
memset ( V_371 , 0 , sizeof( V_371 ) ) ;
#endif
if ( V_385 && ! F_348 ( V_385 -> V_383 ) ) {
F_343 ( V_385 ) ;
F_345 ( V_385 ) ;
}
F_350 (nid) {
T_9 * V_311 = F_307 ( V_288 ) ;
F_343 ( V_311 ) ;
F_345 ( V_311 ) ;
}
F_351 (cpu) {
F_352 ( & F_353 ( V_386 , V_132 ) , 0 ) ;
#ifdef F_354
if ( F_355 ( V_132 ) )
F_356 ( V_132 , F_347 ( F_357 ( V_132 ) ) ) ;
#endif
}
return 0 ;
}
static T_12 void T_2
F_358 ( void )
{
F_349 ( NULL ) ;
F_359 () ;
F_360 () ;
}
void T_13 F_331 ( T_9 * V_311 , struct V_12 * V_12 )
{
F_342 () ;
if ( V_387 == V_388 ) {
F_358 () ;
} else {
#ifdef F_361
if ( V_12 )
F_362 ( V_12 ) ;
#endif
F_363 ( F_349 , V_311 , NULL ) ;
}
V_389 = F_300 () ;
if ( V_389 < ( V_93 * V_315 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_364 ( L_71
L_72 ,
V_216 ,
V_390 [ V_377 ] ,
V_7 ? L_73 : L_4 ,
V_389 ) ;
#ifdef V_211
F_364 ( L_74 , V_391 [ V_392 ] ) ;
#endif
}
static inline unsigned long F_365 ( unsigned long V_118 )
{
unsigned long V_99 = 1 ;
V_118 /= V_393 ;
while ( V_99 < V_118 )
V_99 <<= 1 ;
V_99 = F_72 ( V_99 , 4096UL ) ;
return F_366 ( V_99 , 4UL ) ;
}
static inline unsigned long F_365 ( unsigned long V_118 )
{
return 4096UL ;
}
static inline unsigned long F_367 ( unsigned long V_99 )
{
return F_368 ( ~ V_99 ) ;
}
static int F_369 ( unsigned long V_17 , unsigned long V_111 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 ++ ) {
if ( ! F_17 ( V_15 ) || F_370 ( F_136 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_371 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_111 , V_394 ;
struct V_5 * V_5 ;
unsigned long V_395 ;
int V_396 ;
int V_397 ;
V_17 = V_12 -> V_18 ;
V_111 = F_164 ( V_12 ) ;
V_17 = F_372 ( V_17 , V_93 ) ;
V_396 = F_372 ( F_315 ( V_12 ) , V_93 ) >>
V_61 ;
V_396 = F_72 ( 2 , V_396 ) ;
V_397 = V_12 -> V_398 ;
if ( V_396 == V_397 )
return;
V_12 -> V_398 = V_396 ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 += V_93 ) {
if ( ! F_165 ( V_15 ) )
continue;
V_5 = F_136 ( V_15 ) ;
if ( F_133 ( V_5 ) != F_15 ( V_12 ) )
continue;
V_395 = F_90 ( V_5 ) ;
if ( V_396 > 0 ) {
V_394 = F_72 ( V_15 + V_93 , V_111 ) ;
if ( F_369 ( V_15 , V_394 ) )
continue;
if ( V_395 == V_123 ) {
V_396 -- ;
continue;
}
if ( V_395 == V_126 ) {
F_6 ( V_5 ,
V_123 ) ;
F_135 ( V_12 , V_5 ,
V_123 ) ;
V_396 -- ;
continue;
}
} else if ( ! V_397 ) {
break;
}
if ( V_395 == V_123 ) {
F_6 ( V_5 , V_126 ) ;
F_135 ( V_12 , V_5 , V_126 ) ;
}
}
}
void T_8 F_373 ( unsigned long V_99 , int V_288 , unsigned long V_12 ,
unsigned long V_17 , enum V_399 V_400 )
{
struct V_5 * V_5 ;
unsigned long V_111 = V_17 + V_99 ;
unsigned long V_15 ;
struct V_12 * V_137 ;
if ( V_401 < V_111 - 1 )
V_401 = V_111 - 1 ;
V_137 = & F_307 ( V_288 ) -> V_200 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 ++ ) {
if ( V_400 == V_402 ) {
if ( ! F_374 ( V_15 ) )
continue;
if ( ! F_375 ( V_15 , V_288 ) )
continue;
}
V_5 = F_136 ( V_15 ) ;
F_376 ( V_5 , V_12 , V_288 , V_15 ) ;
F_377 ( V_5 , V_12 , V_288 , V_15 ) ;
F_378 ( V_5 ) ;
F_22 ( V_5 ) ;
F_81 ( V_5 ) ;
F_379 ( V_5 ) ;
if ( ( V_137 -> V_18 <= V_15 )
&& ( V_15 < F_164 ( V_137 ) )
&& ! ( V_15 & ( V_93 - 1 ) ) )
F_6 ( V_5 , V_126 ) ;
F_53 ( & V_5 -> V_53 ) ;
#ifdef F_380
if ( ! F_381 ( V_12 ) )
F_382 ( V_5 , F_383 ( V_15 << V_403 ) ) ;
#endif
}
}
static void T_8 F_384 ( struct V_12 * V_12 )
{
unsigned int V_34 , V_141 ;
F_168 (order, t) {
F_53 ( & V_12 -> V_62 [ V_34 ] . V_66 [ V_141 ] ) ;
V_12 -> V_62 [ V_34 ] . V_63 = 0 ;
}
}
static int F_385 ( struct V_12 * V_12 )
{
#ifdef F_386
int V_131 ;
V_131 = V_12 -> V_92 / 1024 ;
if ( V_131 * V_89 > 512 * 1024 )
V_131 = ( 512 * 1024 ) / V_89 ;
V_131 /= 4 ;
if ( V_131 < 1 )
V_131 = 1 ;
V_131 = F_387 ( V_131 + V_131 / 2 ) - 1 ;
return V_131 ;
#else
return 0 ;
#endif
}
static void F_388 ( struct V_73 * V_74 , unsigned long V_97 ,
unsigned long V_131 )
{
V_74 -> V_131 = 1 ;
F_37 () ;
V_74 -> V_97 = V_97 ;
F_37 () ;
V_74 -> V_131 = V_131 ;
}
static void F_389 ( struct V_133 * V_37 , unsigned long V_131 )
{
F_388 ( & V_37 -> V_74 , 6 * V_131 , F_366 ( 1UL , 1 * V_131 ) ) ;
}
static void F_390 ( struct V_133 * V_37 )
{
struct V_73 * V_74 ;
int V_6 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_74 = & V_37 -> V_74 ;
V_74 -> V_72 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_53 ( & V_74 -> V_82 [ V_6 ] ) ;
}
static void F_352 ( struct V_133 * V_37 , unsigned long V_131 )
{
F_390 ( V_37 ) ;
F_389 ( V_37 , V_131 ) ;
}
static void F_391 ( struct V_133 * V_37 ,
unsigned long V_97 )
{
unsigned long V_131 = F_366 ( 1UL , V_97 / 4 ) ;
if ( ( V_97 / 4 ) > ( V_403 * 8 ) )
V_131 = V_403 * 8 ;
F_388 ( & V_37 -> V_74 , V_97 , V_131 ) ;
}
static void F_392 ( struct V_12 * V_12 ,
struct V_133 * V_74 )
{
if ( V_404 )
F_391 ( V_74 ,
( V_12 -> V_92 /
V_404 ) ) ;
else
F_389 ( V_74 , F_385 ( V_12 ) ) ;
}
static void T_8 F_393 ( struct V_12 * V_12 , int V_132 )
{
struct V_133 * V_74 = F_151 ( V_12 -> V_135 , V_132 ) ;
F_390 ( V_74 ) ;
F_392 ( V_12 , V_74 ) ;
}
static void T_8 F_362 ( struct V_12 * V_12 )
{
int V_132 ;
V_12 -> V_135 = F_394 ( struct V_133 ) ;
F_351 (cpu)
F_393 ( V_12 , V_132 ) ;
}
void T_2 F_395 ( void )
{
struct V_12 * V_12 ;
F_153 (zone)
F_362 ( V_12 ) ;
}
static T_12 T_14
int F_396 ( struct V_12 * V_12 , unsigned long V_405 )
{
int V_35 ;
T_7 V_406 ;
V_12 -> F_365 =
F_365 ( V_405 ) ;
V_12 -> F_367 =
F_367 ( V_12 -> F_365 ) ;
V_406 = V_12 -> F_365
* sizeof( V_407 ) ;
if ( ! F_397 () ) {
V_12 -> V_408 = ( V_407 * )
F_398 (
V_406 , V_12 -> V_199 -> V_383 ) ;
} else {
V_12 -> V_408 = F_399 ( V_406 ) ;
}
if ( ! V_12 -> V_408 )
return - V_169 ;
for ( V_35 = 0 ; V_35 < V_12 -> F_365 ; ++ V_35 )
F_400 ( V_12 -> V_408 + V_35 ) ;
return 0 ;
}
static T_8 void F_401 ( struct V_12 * V_12 )
{
V_12 -> V_135 = & V_386 ;
if ( F_322 ( V_12 ) )
F_24 ( V_409 L_75 ,
V_12 -> V_20 , V_12 -> V_334 ,
F_385 ( V_12 ) ) ;
}
int T_8 F_402 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_99 ,
enum V_399 V_400 )
{
struct V_410 * V_311 = V_12 -> V_199 ;
int V_13 ;
V_13 = F_396 ( V_12 , V_99 ) ;
if ( V_13 )
return V_13 ;
V_311 -> V_342 = F_257 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_403 ( V_411 , L_76 ,
L_77 ,
V_311 -> V_383 ,
( unsigned long ) F_257 ( V_12 ) ,
V_18 , ( V_18 + V_99 ) ) ;
F_384 ( V_12 ) ;
return 0 ;
}
int T_8 F_404 ( unsigned long V_15 )
{
unsigned long V_17 , V_111 ;
int V_288 ;
static unsigned long T_15 V_412 , V_413 ;
static int T_15 V_414 ;
if ( V_412 <= V_15 && V_15 < V_413 )
return V_414 ;
V_288 = F_405 ( V_15 , & V_17 , & V_111 ) ;
if ( V_288 != - 1 ) {
V_412 = V_17 ;
V_413 = V_111 ;
V_414 = V_288 ;
}
return V_288 ;
}
int T_8 F_406 ( unsigned long V_15 )
{
int V_288 ;
V_288 = F_404 ( V_15 ) ;
if ( V_288 >= 0 )
return V_288 ;
return 0 ;
}
bool T_8 F_375 ( unsigned long V_15 , int V_197 )
{
int V_288 ;
V_288 = F_404 ( V_15 ) ;
if ( V_288 >= 0 && V_288 != V_197 )
return false ;
return true ;
}
void T_2 F_407 ( int V_288 , unsigned long V_415 )
{
unsigned long V_17 , V_111 ;
int V_35 , V_416 ;
F_408 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = F_72 ( V_17 , V_415 ) ;
V_111 = F_72 ( V_111 , V_415 ) ;
if ( V_17 < V_111 )
F_409 ( F_410 ( V_17 ) ,
( V_111 - V_17 ) << V_403 ,
V_416 ) ;
}
}
void T_2 F_411 ( int V_288 )
{
unsigned long V_17 , V_111 ;
int V_35 , V_416 ;
F_408 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_412 ( V_416 , V_17 , V_111 ) ;
}
void T_8 F_413 ( unsigned int V_288 ,
unsigned long * V_17 , unsigned long * V_111 )
{
unsigned long V_417 , V_418 ;
int V_35 ;
* V_17 = - 1UL ;
* V_111 = 0 ;
F_408 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = F_72 ( * V_17 , V_417 ) ;
* V_111 = F_366 ( * V_111 , V_418 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_414 ( void )
{
int V_419 ;
for ( V_419 = V_312 - 1 ; V_419 >= 0 ; V_419 -- ) {
if ( V_419 == V_420 )
continue;
if ( V_421 [ V_419 ] >
V_422 [ V_419 ] )
break;
}
F_40 ( V_419 == - 1 ) ;
V_423 = V_419 ;
}
static void T_8 F_415 ( int V_288 ,
unsigned long V_310 ,
unsigned long V_424 ,
unsigned long V_425 ,
unsigned long * V_18 ,
unsigned long * F_164 )
{
if ( V_426 [ V_288 ] ) {
if ( V_310 == V_420 ) {
* V_18 = V_426 [ V_288 ] ;
* F_164 = F_72 ( V_425 ,
V_421 [ V_423 ] ) ;
} else if ( * V_18 < V_426 [ V_288 ] &&
* F_164 > V_426 [ V_288 ] ) {
* F_164 = V_426 [ V_288 ] ;
} else if ( * V_18 >= V_426 [ V_288 ] )
* V_18 = * F_164 ;
}
}
static unsigned long T_8 F_416 ( int V_288 ,
unsigned long V_310 ,
unsigned long V_424 ,
unsigned long V_425 ,
unsigned long * V_427 )
{
unsigned long V_18 , F_164 ;
V_18 = V_422 [ V_310 ] ;
F_164 = V_421 [ V_310 ] ;
F_415 ( V_288 , V_310 ,
V_424 , V_425 ,
& V_18 , & F_164 ) ;
if ( F_164 < V_424 || V_18 > V_425 )
return 0 ;
F_164 = F_72 ( F_164 , V_425 ) ;
V_18 = F_366 ( V_18 , V_424 ) ;
return F_164 - V_18 ;
}
unsigned long T_8 F_417 ( int V_288 ,
unsigned long V_428 ,
unsigned long V_429 )
{
unsigned long V_430 = V_429 - V_428 ;
unsigned long V_17 , V_111 ;
int V_35 ;
F_408 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_418 ( V_17 , V_428 , V_429 ) ;
V_111 = F_418 ( V_111 , V_428 , V_429 ) ;
V_430 -= V_111 - V_17 ;
}
return V_430 ;
}
unsigned long T_2 F_419 ( unsigned long V_17 ,
unsigned long V_111 )
{
return F_417 ( V_370 , V_17 , V_111 ) ;
}
static unsigned long T_8 F_420 ( int V_288 ,
unsigned long V_310 ,
unsigned long V_424 ,
unsigned long V_425 ,
unsigned long * V_427 )
{
unsigned long V_431 = V_422 [ V_310 ] ;
unsigned long V_432 = V_421 [ V_310 ] ;
unsigned long V_18 , F_164 ;
V_18 = F_418 ( V_424 , V_431 , V_432 ) ;
F_164 = F_418 ( V_425 , V_431 , V_432 ) ;
F_415 ( V_288 , V_310 ,
V_424 , V_425 ,
& V_18 , & F_164 ) ;
return F_417 ( V_288 , V_18 , F_164 ) ;
}
static inline unsigned long T_8 F_416 ( int V_288 ,
unsigned long V_310 ,
unsigned long V_424 ,
unsigned long V_425 ,
unsigned long * V_433 )
{
return V_433 [ V_310 ] ;
}
static inline unsigned long T_8 F_420 ( int V_288 ,
unsigned long V_310 ,
unsigned long V_424 ,
unsigned long V_425 ,
unsigned long * V_434 )
{
if ( ! V_434 )
return 0 ;
return V_434 [ V_310 ] ;
}
static void T_8 F_421 ( struct V_410 * V_311 ,
unsigned long V_424 ,
unsigned long V_425 ,
unsigned long * V_433 ,
unsigned long * V_434 )
{
unsigned long V_435 , V_436 = 0 ;
enum V_310 V_35 ;
for ( V_35 = 0 ; V_35 < V_312 ; V_35 ++ )
V_436 += F_416 ( V_311 -> V_383 , V_35 ,
V_424 ,
V_425 ,
V_433 ) ;
V_311 -> V_437 = V_436 ;
V_435 = V_436 ;
for ( V_35 = 0 ; V_35 < V_312 ; V_35 ++ )
V_435 -=
F_420 ( V_311 -> V_383 , V_35 ,
V_424 , V_425 ,
V_434 ) ;
V_311 -> V_438 = V_435 ;
F_24 ( V_409 L_78 , V_311 -> V_383 ,
V_435 ) ;
}
static unsigned long T_2 F_422 ( unsigned long V_18 , unsigned long V_439 )
{
unsigned long V_440 ;
V_439 += V_18 & ( V_93 - 1 ) ;
V_440 = F_372 ( V_439 , V_93 ) ;
V_440 = V_440 >> V_61 ;
V_440 *= V_441 ;
V_440 = F_372 ( V_440 , 8 * sizeof( unsigned long ) ) ;
return V_440 / 8 ;
}
static void T_2 F_423 ( struct V_410 * V_311 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_439 )
{
unsigned long V_440 = F_422 ( V_18 , V_439 ) ;
V_12 -> V_442 = NULL ;
if ( V_440 )
V_12 -> V_442 =
F_398 ( V_440 ,
V_311 -> V_383 ) ;
}
static inline void F_423 ( struct V_410 * V_311 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_439 ) {}
void T_16 F_424 ( void )
{
unsigned int V_34 ;
if ( V_61 )
return;
if ( V_443 > V_403 )
V_34 = V_444 ;
else
V_34 = V_46 - 1 ;
V_61 = V_34 ;
}
void T_16 F_424 ( void )
{
}
static unsigned long T_16 F_425 ( unsigned long V_19 ,
unsigned long V_334 )
{
unsigned long V_118 = V_19 ;
if ( V_19 > V_334 + ( V_334 >> 4 ) &&
F_96 ( V_445 ) )
V_118 = V_334 ;
return F_291 ( V_118 * sizeof( struct V_5 ) ) >> V_403 ;
}
static void T_16 F_426 ( struct V_410 * V_311 ,
unsigned long V_424 , unsigned long V_425 ,
unsigned long * V_433 , unsigned long * V_434 )
{
enum V_310 V_372 ;
int V_288 = V_311 -> V_383 ;
unsigned long V_18 = V_311 -> V_424 ;
int V_13 ;
F_427 ( V_311 ) ;
#ifdef F_428
F_429 ( & V_311 -> V_446 ) ;
V_311 -> V_447 = 0 ;
V_311 -> V_448 = V_26 ;
#endif
F_400 ( & V_311 -> V_449 ) ;
F_400 ( & V_311 -> V_450 ) ;
F_430 ( V_311 ) ;
for ( V_372 = 0 ; V_372 < V_312 ; V_372 ++ ) {
struct V_12 * V_12 = V_311 -> V_200 + V_372 ;
unsigned long V_99 , V_451 , V_452 , V_453 ;
V_99 = F_416 ( V_288 , V_372 , V_424 ,
V_425 , V_433 ) ;
V_451 = V_452 = V_99 - F_420 ( V_288 , V_372 ,
V_424 ,
V_425 ,
V_434 ) ;
V_453 = F_425 ( V_99 , V_451 ) ;
if ( ! F_381 ( V_372 ) ) {
if ( V_452 >= V_453 ) {
V_452 -= V_453 ;
if ( V_453 )
F_24 ( V_409
L_79 ,
V_391 [ V_372 ] , V_453 ) ;
} else
F_24 ( V_348
L_80 ,
V_391 [ V_372 ] , V_453 , V_452 ) ;
}
if ( V_372 == 0 && V_452 > V_454 ) {
V_452 -= V_454 ;
F_24 ( V_409 L_81 ,
V_391 [ 0 ] , V_454 ) ;
}
if ( ! F_381 ( V_372 ) )
V_455 += V_452 ;
else if ( V_455 > V_453 * 2 )
V_455 -= V_453 ;
V_456 += V_452 ;
V_12 -> V_19 = V_99 ;
V_12 -> V_334 = V_451 ;
V_12 -> V_92 = F_381 ( V_372 ) ? V_451 : V_452 ;
#ifdef V_211
V_12 -> V_197 = V_288 ;
V_12 -> V_457 = ( V_452 * V_458 )
/ 100 ;
V_12 -> V_459 = ( V_452 * V_460 ) / 100 ;
#endif
V_12 -> V_20 = V_391 [ V_372 ] ;
F_429 ( & V_12 -> V_78 ) ;
F_429 ( & V_12 -> V_461 ) ;
F_431 ( V_12 ) ;
V_12 -> V_199 = V_311 ;
F_401 ( V_12 ) ;
F_220 ( V_12 , V_150 , V_12 -> V_92 ) ;
F_432 ( & V_12 -> V_462 ) ;
if ( ! V_99 )
continue;
F_424 () ;
F_423 ( V_311 , V_12 , V_18 , V_99 ) ;
V_13 = F_402 ( V_12 , V_18 ,
V_99 , V_402 ) ;
F_183 ( V_13 ) ;
F_433 ( V_99 , V_288 , V_372 , V_18 ) ;
V_18 += V_99 ;
}
}
static void T_14 F_434 ( struct V_410 * V_311 )
{
if ( ! V_311 -> V_437 )
return;
#ifdef F_435
if ( ! V_311 -> V_463 ) {
unsigned long V_99 , V_464 , V_292 ;
struct V_5 * V_465 ;
V_464 = V_311 -> V_424 & ~ ( V_95 - 1 ) ;
V_292 = F_436 ( V_311 ) ;
V_292 = F_437 ( V_292 , V_95 ) ;
V_99 = ( V_292 - V_464 ) * sizeof( struct V_5 ) ;
V_465 = F_438 ( V_311 -> V_383 , V_99 ) ;
if ( ! V_465 )
V_465 = F_398 ( V_99 ,
V_311 -> V_383 ) ;
V_311 -> V_463 = V_465 + ( V_311 -> V_424 - V_464 ) ;
}
#ifndef F_439
if ( V_311 == F_307 ( 0 ) ) {
V_466 = F_307 ( 0 ) -> V_463 ;
#ifdef F_440
if ( F_10 ( V_466 ) != V_311 -> V_424 )
V_466 -= ( V_311 -> V_424 - V_467 ) ;
#endif
}
#endif
#endif
}
void T_16 F_441 ( int V_288 , unsigned long * V_433 ,
unsigned long V_424 , unsigned long * V_434 )
{
T_9 * V_311 = F_307 ( V_288 ) ;
unsigned long V_17 = 0 ;
unsigned long V_111 = 0 ;
F_2 ( V_311 -> V_342 || V_311 -> V_171 ) ;
V_311 -> V_383 = V_288 ;
V_311 -> V_424 = V_424 ;
#ifdef F_440
F_413 ( V_288 , & V_17 , & V_111 ) ;
F_364 ( L_82 , V_288 ,
( V_468 ) V_17 << V_403 , ( ( V_468 ) V_111 << V_403 ) - 1 ) ;
#endif
F_421 ( V_311 , V_17 , V_111 ,
V_433 , V_434 ) ;
F_434 ( V_311 ) ;
#ifdef F_435
F_24 ( V_409 L_83 ,
V_288 , ( unsigned long ) V_311 ,
( unsigned long ) V_311 -> V_463 ) ;
#endif
F_426 ( V_311 , V_17 , V_111 ,
V_433 , V_434 ) ;
}
void T_2 F_442 ( void )
{
unsigned int V_197 ;
unsigned int V_469 = 0 ;
F_443 (node, node_possible_map)
V_469 = V_197 ;
V_470 = V_469 + 1 ;
}
unsigned long T_2 F_444 ( void )
{
unsigned long V_471 = 0 , V_472 = 0 ;
unsigned long V_464 , V_292 , V_473 ;
int V_414 = - 1 ;
int V_35 , V_288 ;
F_408 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_464 || V_414 < 0 || V_414 == V_288 ) {
V_414 = V_288 ;
V_472 = V_292 ;
continue;
}
V_473 = ~ ( ( 1 << F_445 ( V_464 ) ) - 1 ) ;
while ( V_473 && V_472 <= ( V_464 & ( V_473 << 1 ) ) )
V_473 <<= 1 ;
V_471 |= V_473 ;
}
return ~ V_471 + 1 ;
}
static unsigned long T_2 F_446 ( int V_288 )
{
unsigned long V_474 = V_475 ;
unsigned long V_17 ;
int V_35 ;
F_408 (i, nid, &start_pfn, NULL, NULL)
V_474 = F_72 ( V_474 , V_17 ) ;
if ( V_474 == V_475 ) {
F_24 ( V_348
L_84 , V_288 ) ;
return 0 ;
}
return V_474 ;
}
unsigned long T_2 F_447 ( void )
{
return F_446 ( V_370 ) ;
}
static unsigned long T_2 F_448 ( void )
{
unsigned long V_436 = 0 ;
unsigned long V_17 , V_111 ;
int V_35 , V_288 ;
F_408 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_118 = V_111 - V_17 ;
V_436 += V_118 ;
if ( V_118 )
F_449 ( V_288 , V_191 ) ;
}
return V_436 ;
}
static void T_2 F_450 ( void )
{
int V_35 , V_288 ;
unsigned long V_476 ;
unsigned long V_477 , V_478 ;
T_5 V_479 = V_190 [ V_191 ] ;
unsigned long V_436 = F_448 () ;
int V_480 = F_451 ( V_190 [ V_191 ] ) ;
struct V_481 * V_482 ;
F_414 () ;
if ( F_452 () ) {
F_453 (memory, r) {
if ( ! F_454 ( V_482 ) )
continue;
V_288 = V_482 -> V_288 ;
V_476 = F_455 ( V_482 -> V_483 ) ;
V_426 [ V_288 ] = V_426 [ V_288 ] ?
F_72 ( V_476 , V_426 [ V_288 ] ) :
V_476 ;
}
goto V_484;
}
if ( V_485 ) {
unsigned long V_486 ;
V_485 =
F_372 ( V_485 , V_95 ) ;
V_486 = V_436 - V_485 ;
V_487 = F_366 ( V_487 , V_486 ) ;
}
if ( ! V_487 )
goto V_27;
V_476 = V_422 [ V_423 ] ;
V_488:
V_477 = V_487 / V_480 ;
F_336 (nid, N_MEMORY) {
unsigned long V_17 , V_111 ;
if ( V_487 < V_477 )
V_477 = V_487 / V_480 ;
V_478 = V_477 ;
F_408 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_489 ;
V_17 = F_366 ( V_17 , V_426 [ V_288 ] ) ;
if ( V_17 >= V_111 )
continue;
if ( V_17 < V_476 ) {
unsigned long V_490 ;
V_490 = F_72 ( V_111 , V_476 )
- V_17 ;
V_478 -= F_72 ( V_490 ,
V_478 ) ;
V_487 -= F_72 ( V_490 ,
V_487 ) ;
if ( V_111 <= V_476 ) {
V_426 [ V_288 ] = V_111 ;
continue;
}
V_17 = V_476 ;
}
V_489 = V_111 - V_17 ;
if ( V_489 > V_478 )
V_489 = V_478 ;
V_426 [ V_288 ] = V_17 + V_489 ;
V_487 -= F_72 ( V_487 ,
V_489 ) ;
V_478 -= V_489 ;
if ( ! V_478 )
break;
}
}
V_480 -- ;
if ( V_480 && V_487 > V_480 )
goto V_488;
V_484:
for ( V_288 = 0 ; V_288 < V_370 ; V_288 ++ )
V_426 [ V_288 ] =
F_372 ( V_426 [ V_288 ] , V_95 ) ;
V_27:
V_190 [ V_191 ] = V_479 ;
}
static void F_456 ( T_9 * V_311 , int V_288 )
{
enum V_310 V_310 ;
if ( V_191 == V_491 )
return;
for ( V_310 = 0 ; V_310 <= V_420 - 1 ; V_310 ++ ) {
struct V_12 * V_12 = & V_311 -> V_200 [ V_310 ] ;
if ( F_322 ( V_12 ) ) {
F_449 ( V_288 , V_492 ) ;
if ( V_491 != V_492 &&
V_310 <= V_245 )
F_449 ( V_288 , V_491 ) ;
break;
}
}
}
void T_2 F_457 ( unsigned long * V_140 )
{
unsigned long V_17 , V_111 ;
int V_35 , V_288 ;
memset ( V_422 , 0 ,
sizeof( V_422 ) ) ;
memset ( V_421 , 0 ,
sizeof( V_421 ) ) ;
V_422 [ 0 ] = F_447 () ;
V_421 [ 0 ] = V_140 [ 0 ] ;
for ( V_35 = 1 ; V_35 < V_312 ; V_35 ++ ) {
if ( V_35 == V_420 )
continue;
V_422 [ V_35 ] =
V_421 [ V_35 - 1 ] ;
V_421 [ V_35 ] =
F_366 ( V_140 [ V_35 ] , V_422 [ V_35 ] ) ;
}
V_422 [ V_420 ] = 0 ;
V_421 [ V_420 ] = 0 ;
memset ( V_426 , 0 , sizeof( V_426 ) ) ;
F_450 () ;
F_364 ( L_85 ) ;
for ( V_35 = 0 ; V_35 < V_312 ; V_35 ++ ) {
if ( V_35 == V_420 )
continue;
F_364 ( L_86 , V_391 [ V_35 ] ) ;
if ( V_422 [ V_35 ] ==
V_421 [ V_35 ] )
F_458 ( L_87 ) ;
else
F_458 ( L_88 ,
( V_468 ) V_422 [ V_35 ]
<< V_403 ,
( ( V_468 ) V_421 [ V_35 ]
<< V_403 ) - 1 ) ;
}
F_364 ( L_89 ) ;
for ( V_35 = 0 ; V_35 < V_370 ; V_35 ++ ) {
if ( V_426 [ V_35 ] )
F_364 ( L_90 , V_35 ,
( V_468 ) V_426 [ V_35 ] << V_403 ) ;
}
F_364 ( L_91 ) ;
F_408 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_364 ( L_92 , V_288 ,
( V_468 ) V_17 << V_403 ,
( ( V_468 ) V_111 << V_403 ) - 1 ) ;
F_459 () ;
F_442 () ;
F_350 (nid) {
T_9 * V_311 = F_307 ( V_288 ) ;
F_441 ( V_288 , NULL ,
F_446 ( V_288 ) , NULL ) ;
if ( V_311 -> V_438 )
F_449 ( V_288 , V_191 ) ;
F_456 ( V_311 , V_288 ) ;
}
}
static int T_2 F_460 ( char * V_37 , unsigned long * V_493 )
{
unsigned long long V_494 ;
if ( ! V_37 )
return - V_42 ;
V_494 = F_461 ( V_37 , & V_37 ) ;
* V_493 = V_494 >> V_403 ;
F_2 ( ( V_494 >> V_403 ) > V_475 ) ;
return 0 ;
}
static int T_2 F_462 ( char * V_37 )
{
return F_460 ( V_37 , & V_487 ) ;
}
static int T_2 F_463 ( char * V_37 )
{
return F_460 ( V_37 , & V_485 ) ;
}
void F_121 ( struct V_5 * V_5 , long V_72 )
{
F_83 ( & V_495 ) ;
F_18 ( V_5 ) -> V_92 += V_72 ;
V_301 += V_72 ;
#ifdef F_309
if ( F_105 ( V_5 ) )
V_307 += V_72 ;
#endif
F_92 ( & V_495 ) ;
}
unsigned long F_464 ( void * V_464 , void * V_292 , int V_496 , char * V_343 )
{
void * V_375 ;
unsigned long V_118 = 0 ;
V_464 = ( void * ) F_291 ( ( unsigned long ) V_464 ) ;
V_292 = ( void * ) ( ( unsigned long ) V_292 & V_497 ) ;
for ( V_375 = V_464 ; V_375 < V_292 ; V_375 += V_89 , V_118 ++ ) {
if ( ( unsigned int ) V_496 <= 0xFF )
memset ( V_375 , V_496 , V_89 ) ;
F_465 ( F_181 ( V_375 ) ) ;
}
if ( V_118 && V_343 )
F_364 ( L_93 ,
V_343 , V_118 << ( V_403 - 10 ) , V_464 , V_292 ) ;
return V_118 ;
}
void F_466 ( struct V_5 * V_5 )
{
F_467 ( V_5 ) ;
V_301 ++ ;
F_18 ( V_5 ) -> V_92 ++ ;
V_307 ++ ;
}
void T_2 F_468 ( const char * V_154 )
{
unsigned long V_498 , V_499 , V_500 , V_501 , V_502 ;
unsigned long V_503 , V_504 ;
V_498 = F_469 () ;
V_499 = V_505 - V_506 ;
V_500 = V_507 - V_508 ;
V_501 = V_509 - V_510 ;
V_502 = V_511 - V_512 ;
V_504 = V_513 - V_514 ;
V_503 = V_515 - V_516 ;
#define F_470 ( V_464 , V_292 , V_99 , V_375 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_470 ( V_514 , V_513 , V_504 ,
V_516 , V_503 ) ;
F_470 ( V_506 , V_505 , V_499 , V_516 , V_503 ) ;
F_470 ( V_508 , V_507 , V_500 , V_514 , V_504 ) ;
F_470 ( V_506 , V_505 , V_499 , V_510 , V_501 ) ;
F_470 ( V_508 , V_507 , V_500 , V_510 , V_501 ) ;
#undef F_470
F_364 ( L_94
L_95
L_96
#ifdef F_309
L_97
#endif
L_98 ,
F_471 () << ( V_403 - 10 ) , V_498 << ( V_403 - 10 ) ,
V_499 >> 10 , V_500 >> 10 , V_501 >> 10 ,
( V_504 + V_503 ) >> 10 , V_502 >> 10 ,
( V_498 - V_301 - V_517 ) << ( V_403 - 10 ) ,
V_517 << ( V_403 - 10 ) ,
#ifdef F_309
V_307 << ( V_403 - 10 ) ,
#endif
V_154 ? L_99 : L_100 , V_154 ? V_154 : L_100 ) ;
}
void T_2 F_472 ( unsigned long V_518 )
{
V_454 = V_518 ;
}
void T_2 F_473 ( unsigned long * V_433 )
{
F_441 ( 0 , V_433 ,
F_474 ( V_519 ) >> V_403 , NULL ) ;
}
static int F_475 ( struct V_520 * V_385 ,
unsigned long V_521 , void * V_522 )
{
int V_132 = ( unsigned long ) V_522 ;
if ( V_521 == V_523 || V_521 == V_524 ) {
F_476 ( V_132 ) ;
F_152 ( V_132 ) ;
F_477 ( V_132 ) ;
F_478 ( V_132 ) ;
}
return V_525 ;
}
void T_2 F_479 ( void )
{
F_480 ( F_475 , 0 ) ;
}
static void F_481 ( void )
{
struct V_410 * V_311 ;
unsigned long V_526 = 0 ;
enum V_310 V_35 , V_372 ;
F_482 (pgdat) {
for ( V_35 = 0 ; V_35 < V_312 ; V_35 ++ ) {
struct V_12 * V_12 = V_311 -> V_200 + V_35 ;
long F_366 = 0 ;
for ( V_372 = V_35 ; V_372 < V_312 ; V_372 ++ ) {
if ( V_12 -> V_178 [ V_372 ] > F_366 )
F_366 = V_12 -> V_178 [ V_372 ] ;
}
F_366 += F_221 ( V_12 ) ;
if ( F_366 > V_12 -> V_92 )
F_366 = V_12 -> V_92 ;
V_526 += F_366 ;
V_12 -> V_527 = F_366 ;
}
}
V_527 = V_526 ;
V_528 = V_526 ;
}
static void F_483 ( void )
{
struct V_410 * V_311 ;
enum V_310 V_372 , V_529 ;
F_482 (pgdat) {
for ( V_372 = 0 ; V_372 < V_312 ; V_372 ++ ) {
struct V_12 * V_12 = V_311 -> V_200 + V_372 ;
unsigned long V_92 = V_12 -> V_92 ;
V_12 -> V_178 [ V_372 ] = 0 ;
V_529 = V_372 ;
while ( V_529 ) {
struct V_12 * V_530 ;
V_529 -- ;
if ( V_531 [ V_529 ] < 1 )
V_531 [ V_529 ] = 1 ;
V_530 = V_311 -> V_200 + V_529 ;
V_530 -> V_178 [ V_372 ] = V_92 /
V_531 [ V_529 ] ;
V_92 += V_530 -> V_92 ;
}
}
}
F_481 () ;
}
static void F_484 ( void )
{
unsigned long V_532 = V_533 >> ( V_403 - 10 ) ;
unsigned long V_534 = 0 ;
struct V_12 * V_12 ;
unsigned long V_52 ;
F_485 (zone) {
if ( ! F_486 ( V_12 ) )
V_534 += V_12 -> V_92 ;
}
F_485 (zone) {
V_468 V_317 ;
F_163 ( & V_12 -> V_78 , V_52 ) ;
V_317 = ( V_468 ) V_532 * V_12 -> V_92 ;
F_487 ( V_317 , V_534 ) ;
if ( F_486 ( V_12 ) ) {
unsigned long V_535 ;
V_535 = V_12 -> V_92 / 1024 ;
V_535 = F_418 ( V_535 , V_536 , 128UL ) ;
V_12 -> V_144 [ V_537 ] = V_535 ;
} else {
V_12 -> V_144 [ V_537 ] = V_317 ;
}
V_12 -> V_144 [ V_538 ] = F_315 ( V_12 ) + ( V_317 >> 2 ) ;
V_12 -> V_144 [ V_539 ] = F_315 ( V_12 ) + ( V_317 >> 1 ) ;
F_85 ( V_12 , V_150 ,
F_221 ( V_12 ) - F_184 ( V_12 ) -
F_189 ( & V_12 -> V_151 [ V_150 ] ) ) ;
F_371 ( V_12 ) ;
F_171 ( & V_12 -> V_78 , V_52 ) ;
}
F_481 () ;
}
void F_488 ( void )
{
F_329 ( & V_361 ) ;
F_484 () ;
F_332 ( & V_361 ) ;
}
static void T_8 F_489 ( struct V_12 * V_12 )
{
unsigned int V_540 , V_541 ;
V_540 = V_12 -> V_92 >> ( 30 - V_403 ) ;
if ( V_540 )
V_541 = F_490 ( 10 * V_540 ) ;
else
V_541 = 1 ;
V_12 -> V_542 = V_541 ;
}
static void T_8 F_491 ( void )
{
struct V_12 * V_12 ;
F_485 (zone)
F_489 ( V_12 ) ;
}
int T_8 F_492 ( void )
{
unsigned long V_543 ;
int V_544 ;
V_543 = F_299 () * ( V_89 >> 10 ) ;
V_544 = F_490 ( V_543 * 16 ) ;
if ( V_544 > V_545 ) {
V_533 = V_544 ;
if ( V_533 < 128 )
V_533 = 128 ;
if ( V_533 > 65536 )
V_533 = 65536 ;
} else {
F_234 ( L_101 ,
V_544 , V_545 ) ;
}
F_488 () ;
F_493 () ;
F_483 () ;
F_491 () ;
return 0 ;
}
int F_494 ( struct V_351 * V_352 , int V_353 ,
void T_10 * V_354 , T_7 * V_355 , T_11 * V_356 )
{
int V_546 ;
V_546 = F_495 ( V_352 , V_353 , V_354 , V_355 , V_356 ) ;
if ( V_546 )
return V_546 ;
if ( V_353 ) {
V_545 = V_533 ;
F_488 () ;
}
return 0 ;
}
int F_496 ( struct V_351 * V_352 , int V_353 ,
void T_10 * V_354 , T_7 * V_355 , T_11 * V_356 )
{
struct V_12 * V_12 ;
int V_546 ;
V_546 = F_495 ( V_352 , V_353 , V_354 , V_355 , V_356 ) ;
if ( V_546 )
return V_546 ;
F_485 (zone)
V_12 -> V_457 = ( V_12 -> V_92 *
V_458 ) / 100 ;
return 0 ;
}
int F_497 ( struct V_351 * V_352 , int V_353 ,
void T_10 * V_354 , T_7 * V_355 , T_11 * V_356 )
{
struct V_12 * V_12 ;
int V_546 ;
V_546 = F_495 ( V_352 , V_353 , V_354 , V_355 , V_356 ) ;
if ( V_546 )
return V_546 ;
F_485 (zone)
V_12 -> V_459 = ( V_12 -> V_92 *
V_460 ) / 100 ;
return 0 ;
}
int F_498 ( struct V_351 * V_352 , int V_353 ,
void T_10 * V_354 , T_7 * V_355 , T_11 * V_356 )
{
F_495 ( V_352 , V_353 , V_354 , V_355 , V_356 ) ;
F_483 () ;
return 0 ;
}
int F_499 ( struct V_351 * V_352 , int V_353 ,
void T_10 * V_354 , T_7 * V_355 , T_11 * V_356 )
{
struct V_12 * V_12 ;
int V_547 ;
int V_13 ;
F_329 ( & V_548 ) ;
V_547 = V_404 ;
V_13 = F_495 ( V_352 , V_353 , V_354 , V_355 , V_356 ) ;
if ( ! V_353 || V_13 < 0 )
goto V_27;
if ( V_404 &&
V_404 < V_549 ) {
V_404 = V_547 ;
V_13 = - V_42 ;
goto V_27;
}
if ( V_404 == V_547 )
goto V_27;
F_153 (zone) {
unsigned int V_132 ;
F_351 (cpu)
F_392 ( V_12 ,
F_151 ( V_12 -> V_135 , V_132 ) ) ;
}
V_27:
F_332 ( & V_548 ) ;
return V_13 ;
}
static int T_2 F_500 ( char * V_154 )
{
if ( ! V_154 )
return 0 ;
V_550 = F_501 ( V_154 , & V_154 , 0 ) ;
return 1 ;
}
void * T_2 F_502 ( const char * V_551 ,
unsigned long V_552 ,
unsigned long V_553 ,
int V_554 ,
int V_52 ,
unsigned int * V_555 ,
unsigned int * V_556 ,
unsigned long V_557 ,
unsigned long V_558 )
{
unsigned long long F_366 = V_558 ;
unsigned long V_559 , V_99 ;
void * V_352 = NULL ;
if ( ! V_553 ) {
V_553 = V_455 ;
if ( V_403 < 20 )
V_553 = F_503 ( V_553 , ( 1 << 20 ) / V_89 ) ;
if ( V_554 > V_403 )
V_553 >>= ( V_554 - V_403 ) ;
else
V_553 <<= ( V_403 - V_554 ) ;
if ( F_7 ( V_52 & V_560 ) ) {
F_2 ( ! ( V_52 & V_561 ) ) ;
if ( ! ( V_553 >> * V_555 ) ) {
V_553 = 1UL << * V_555 ;
F_183 ( ! V_553 ) ;
}
} else if ( F_7 ( ( V_553 * V_552 ) < V_89 ) )
V_553 = V_89 / V_552 ;
}
V_553 = F_504 ( V_553 ) ;
if ( F_366 == 0 ) {
F_366 = ( ( unsigned long long ) V_456 << V_403 ) >> 4 ;
F_487 ( F_366 , V_552 ) ;
}
F_366 = F_72 ( F_366 , 0x80000000ULL ) ;
if ( V_553 < V_557 )
V_553 = V_557 ;
if ( V_553 > F_366 )
V_553 = F_366 ;
V_559 = F_505 ( V_553 ) ;
do {
V_99 = V_552 << V_559 ;
if ( V_52 & V_561 )
V_352 = F_506 ( V_99 , 0 ) ;
else if ( V_550 )
V_352 = F_507 ( V_99 , V_562 , V_563 ) ;
else {
if ( F_294 ( V_99 ) < V_46 ) {
V_352 = F_293 ( V_99 , V_562 ) ;
F_508 ( V_352 , V_99 , 1 , V_562 ) ;
}
}
} while ( ! V_352 && V_99 > V_89 && -- V_559 );
if ( ! V_352 )
F_509 ( L_102 , V_551 ) ;
F_24 ( V_49 L_103 ,
V_551 ,
( 1UL << V_559 ) ,
F_505 ( V_99 ) - V_403 ,
V_99 ) ;
if ( V_555 )
* V_555 = V_559 ;
if ( V_556 )
* V_556 = ( 1 << V_559 ) - 1 ;
return V_352 ;
}
static inline unsigned long * F_510 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_445
return F_511 ( V_15 ) -> V_442 ;
#else
return V_12 -> V_442 ;
#endif
}
static inline int F_512 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_445
V_15 &= ( V_564 - 1 ) ;
return ( V_15 >> V_61 ) * V_441 ;
#else
V_15 = V_15 - F_513 ( V_12 -> V_18 , V_93 ) ;
return ( V_15 >> V_61 ) * V_441 ;
#endif
}
unsigned long F_514 ( struct V_5 * V_5 , unsigned long V_15 ,
unsigned long V_565 ,
unsigned long V_473 )
{
struct V_12 * V_12 ;
unsigned long * V_566 ;
unsigned long V_567 , V_568 ;
unsigned long V_569 ;
V_12 = F_18 ( V_5 ) ;
V_566 = F_510 ( V_12 , V_15 ) ;
V_567 = F_512 ( V_12 , V_15 ) ;
V_568 = V_567 / V_570 ;
V_567 &= ( V_570 - 1 ) ;
V_569 = V_566 [ V_568 ] ;
V_567 += V_565 ;
return ( V_569 >> ( V_570 - V_567 - 1 ) ) & V_473 ;
}
void F_515 ( struct V_5 * V_5 , unsigned long V_52 ,
unsigned long V_15 ,
unsigned long V_565 ,
unsigned long V_473 )
{
struct V_12 * V_12 ;
unsigned long * V_566 ;
unsigned long V_567 , V_568 ;
unsigned long V_571 , V_569 ;
F_228 ( V_441 != 4 ) ;
V_12 = F_18 ( V_5 ) ;
V_566 = F_510 ( V_12 , V_15 ) ;
V_567 = F_512 ( V_12 , V_15 ) ;
V_568 = V_567 / V_570 ;
V_567 &= ( V_570 - 1 ) ;
F_67 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
V_567 += V_565 ;
V_473 <<= ( V_570 - V_567 - 1 ) ;
V_52 <<= ( V_570 - V_567 - 1 ) ;
V_569 = F_149 ( V_566 [ V_568 ] ) ;
for (; ; ) {
V_571 = F_516 ( & V_566 [ V_568 ] , V_569 , ( V_569 & ~ V_473 ) | V_52 ) ;
if ( V_569 == V_571 )
break;
V_569 = V_571 ;
}
}
bool F_517 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_72 ,
bool V_572 )
{
unsigned long V_15 , V_573 , V_574 ;
int V_83 ;
if ( F_257 ( V_12 ) == V_420 )
return false ;
V_83 = F_90 ( V_5 ) ;
if ( V_83 == V_126 || F_147 ( V_83 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_574 = 0 , V_573 = 0 ; V_573 < V_93 ; V_573 ++ ) {
unsigned long V_575 = V_15 + V_573 ;
if ( ! F_17 ( V_575 ) )
continue;
V_5 = F_136 ( V_575 ) ;
if ( F_518 ( V_5 ) ) {
V_573 = F_503 ( V_573 + 1 , 1 << F_31 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_79 ( & V_5 -> V_69 ) ) {
if ( F_69 ( V_5 ) )
V_573 += ( 1 << F_65 ( V_5 ) ) - 1 ;
continue;
}
if ( V_572 && F_21 ( V_5 ) )
continue;
if ( ! F_519 ( V_5 ) )
V_574 ++ ;
if ( V_574 > V_72 )
return true ;
}
return false ;
}
bool F_520 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_348 ( F_133 ( V_5 ) ) )
return false ;
V_12 = F_18 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_517 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_521 ( unsigned long V_15 )
{
return V_15 & ~ ( F_522 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_523 ( unsigned long V_15 )
{
return F_437 ( V_15 , F_522 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_524 ( struct V_576 * V_577 ,
unsigned long V_464 , unsigned long V_292 )
{
unsigned long V_578 ;
unsigned long V_15 = V_464 ;
unsigned int V_579 = 0 ;
int V_13 = 0 ;
F_525 () ;
while ( V_15 < V_292 || ! F_86 ( & V_577 -> V_580 ) ) {
if ( F_526 ( V_30 ) ) {
V_13 = - V_581 ;
break;
}
if ( F_86 ( & V_577 -> V_580 ) ) {
V_577 -> V_582 = 0 ;
V_15 = F_527 ( V_577 , V_15 , V_292 ) ;
if ( ! V_15 ) {
V_13 = - V_581 ;
break;
}
V_579 = 0 ;
} else if ( ++ V_579 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_583 ;
break;
}
V_578 = F_528 ( V_577 -> V_12 ,
& V_577 -> V_580 ) ;
V_577 -> V_582 -= V_578 ;
V_13 = F_529 ( & V_577 -> V_580 , V_584 ,
NULL , 0 , V_577 -> V_162 , V_585 ) ;
}
if ( V_13 < 0 ) {
F_530 ( & V_577 -> V_580 ) ;
return V_13 ;
}
return 0 ;
}
int F_531 ( unsigned long V_464 , unsigned long V_292 ,
unsigned V_6 )
{
unsigned long V_586 , V_587 ;
int V_13 = 0 , V_34 ;
struct V_576 V_577 = {
. V_582 = 0 ,
. V_34 = - 1 ,
. V_12 = F_18 ( F_136 ( V_464 ) ) ,
. V_162 = V_588 ,
. V_589 = true ,
} ;
F_53 ( & V_577 . V_580 ) ;
V_13 = F_532 ( F_521 ( V_464 ) ,
F_523 ( V_292 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_524 ( & V_577 , V_464 , V_292 ) ;
if ( V_13 )
goto V_590;
F_533 () ;
F_156 ( V_577 . V_12 ) ;
V_34 = 0 ;
V_586 = V_464 ;
while ( ! F_69 ( F_136 ( V_586 ) ) ) {
if ( ++ V_34 >= V_46 ) {
V_13 = - V_583 ;
goto V_590;
}
V_586 &= ~ 0UL << V_34 ;
}
if ( F_534 ( V_586 , V_292 , false ) ) {
F_364 ( L_104 ,
V_591 , V_586 , V_292 ) ;
V_13 = - V_583 ;
goto V_590;
}
V_587 = F_535 ( & V_577 , V_586 , V_292 ) ;
if ( ! V_587 ) {
V_13 = - V_583 ;
goto V_590;
}
if ( V_464 != V_586 )
F_536 ( V_586 , V_464 - V_586 ) ;
if ( V_292 != V_587 )
F_536 ( V_292 , V_587 - V_292 ) ;
V_590:
F_537 ( F_521 ( V_464 ) ,
F_523 ( V_292 ) , V_6 ) ;
return V_13 ;
}
void F_536 ( unsigned long V_15 , unsigned V_36 )
{
unsigned int V_72 = 0 ;
for (; V_36 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_136 ( V_15 ) ;
V_72 += F_68 ( V_5 ) != 1 ;
F_538 ( V_5 ) ;
}
F_539 ( V_72 != 0 , L_105 , V_72 ) ;
}
void T_8 F_540 ( struct V_12 * V_12 )
{
unsigned V_132 ;
F_329 ( & V_548 ) ;
F_351 (cpu)
F_392 ( V_12 ,
F_151 ( V_12 -> V_135 , V_132 ) ) ;
F_332 ( & V_548 ) ;
}
void F_541 ( struct V_12 * V_12 )
{
unsigned long V_52 ;
int V_132 ;
struct V_133 * V_134 ;
F_111 ( V_52 ) ;
if ( V_12 -> V_135 != & V_386 ) {
F_157 (cpu) {
V_134 = F_151 ( V_12 -> V_135 , V_132 ) ;
F_542 ( V_12 , V_134 ) ;
}
F_543 ( V_12 -> V_135 ) ;
V_12 -> V_135 = & V_386 ;
}
F_114 ( V_52 ) ;
}
void
F_544 ( unsigned long V_17 , unsigned long V_111 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
unsigned int V_34 , V_35 ;
unsigned long V_15 ;
unsigned long V_52 ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 ++ )
if ( F_165 ( V_15 ) )
break;
if ( V_15 == V_111 )
return;
V_12 = F_18 ( F_136 ( V_15 ) ) ;
F_163 ( & V_12 -> V_78 , V_52 ) ;
V_15 = V_17 ;
while ( V_15 < V_111 ) {
if ( ! F_165 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_136 ( V_15 ) ;
if ( F_7 ( ! F_69 ( V_5 ) && F_21 ( V_5 ) ) ) {
V_15 ++ ;
F_379 ( V_5 ) ;
continue;
}
F_183 ( F_68 ( V_5 ) ) ;
F_183 ( ! F_69 ( V_5 ) ) ;
V_34 = F_65 ( V_5 ) ;
#ifdef V_86
F_24 ( V_49 L_106 ,
V_15 , 1 << V_34 , V_111 ) ;
#endif
F_74 ( & V_5 -> V_53 ) ;
F_61 ( V_5 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_379 ( ( V_5 + V_35 ) ) ;
V_15 += ( 1 << V_34 ) ;
}
F_171 ( & V_12 -> V_78 , V_52 ) ;
}
bool F_545 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_52 ;
unsigned int V_34 ;
F_163 ( & V_12 -> V_78 , V_52 ) ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
struct V_5 * V_592 = V_5 - ( V_15 & ( ( 1 << V_34 ) - 1 ) ) ;
if ( F_69 ( V_592 ) && F_65 ( V_592 ) >= V_34 )
break;
}
F_171 ( & V_12 -> V_78 , V_52 ) ;
return V_34 < V_46 ;
}
