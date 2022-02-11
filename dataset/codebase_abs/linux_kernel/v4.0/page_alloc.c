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
int F_130 ( struct V_12 * V_12 ,
struct V_5 * V_108 , struct V_5 * V_109 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_34 ;
int V_110 = 0 ;
#ifndef F_131
F_40 ( F_18 ( V_108 ) != F_18 ( V_109 ) ) ;
#endif
for ( V_5 = V_108 ; V_5 <= V_109 ; ) {
F_67 ( F_132 ( V_5 ) != F_15 ( V_12 ) , V_5 ) ;
if ( ! F_17 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_69 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_34 = F_65 ( V_5 ) ;
F_133 ( & V_5 -> V_53 ,
& V_12 -> V_62 [ V_34 ] . V_66 [ V_6 ] ) ;
F_113 ( V_5 , V_6 ) ;
V_5 += 1 << V_34 ;
V_110 += 1 << V_34 ;
}
return V_110 ;
}
int F_134 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_17 , V_111 ;
struct V_5 * V_108 , * V_109 ;
V_17 = F_10 ( V_5 ) ;
V_17 = V_17 & ~ ( V_93 - 1 ) ;
V_108 = F_135 ( V_17 ) ;
V_109 = V_108 + V_93 - 1 ;
V_111 = V_17 + V_93 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_108 = V_5 ;
if ( ! F_12 ( V_12 , V_111 ) )
return 0 ;
return F_130 ( V_12 , V_108 , V_109 , V_6 ) ;
}
static void F_136 ( struct V_5 * V_112 ,
int V_113 , int V_6 )
{
int V_114 = 1 << ( V_113 - V_61 ) ;
while ( V_114 -- ) {
F_6 ( V_112 , V_6 ) ;
V_112 += V_93 ;
}
}
static void F_137 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_115 , int V_116 )
{
int V_106 = F_65 ( V_5 ) ;
if ( V_106 >= V_61 ) {
F_136 ( V_5 , V_106 , V_115 ) ;
return;
}
if ( V_106 >= V_61 / 2 ||
V_115 == V_117 ||
V_115 == V_9 ||
V_7 ) {
int V_118 ;
V_118 = F_134 ( V_12 , V_5 , V_115 ) ;
if ( V_118 >= ( 1 << ( V_61 - 1 ) ) ||
V_7 )
F_6 ( V_5 , V_115 ) ;
}
}
static inline struct V_5 *
F_138 ( struct V_12 * V_12 , unsigned int V_34 , int V_119 )
{
struct V_62 * V_98 ;
unsigned int V_106 ;
struct V_5 * V_5 ;
for ( V_106 = V_46 - 1 ;
V_106 >= V_34 && V_106 <= V_46 - 1 ;
-- V_106 ) {
int V_35 ;
for ( V_35 = 0 ; ; V_35 ++ ) {
int V_6 = V_120 [ V_119 ] [ V_35 ] ;
int V_121 = V_119 ;
if ( V_6 == V_122 )
break;
V_98 = & ( V_12 -> V_62 [ V_106 ] ) ;
if ( F_86 ( & V_98 -> V_66 [ V_6 ] ) )
continue;
V_5 = F_87 ( V_98 -> V_66 [ V_6 ] . V_107 ,
struct V_5 , V_53 ) ;
V_98 -> V_63 -- ;
if ( ! F_139 ( V_6 ) ) {
F_137 ( V_12 , V_5 ,
V_119 ,
V_6 ) ;
} else {
V_121 = V_6 ;
}
F_74 ( & V_5 -> V_53 ) ;
F_61 ( V_5 ) ;
F_122 ( V_12 , V_5 , V_34 , V_106 , V_98 ,
V_121 ) ;
F_113 ( V_5 , V_121 ) ;
F_140 ( V_5 , V_34 , V_106 ,
V_119 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_141 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
struct V_5 * V_5 ;
V_123:
V_5 = F_129 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_122 ) {
V_5 = F_138 ( V_12 , V_34 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_122 ;
goto V_123;
}
}
F_142 ( V_5 , V_34 , V_6 ) ;
return V_5 ;
}
static int F_143 ( struct V_12 * V_12 , unsigned int V_34 ,
unsigned long V_72 , struct V_80 * V_81 ,
int V_6 , bool V_124 )
{
int V_35 ;
F_83 ( & V_12 -> V_78 ) ;
for ( V_35 = 0 ; V_35 < V_72 ; ++ V_35 ) {
struct V_5 * V_5 = F_141 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_144 ( ! V_124 ) )
F_76 ( & V_5 -> V_53 , V_81 ) ;
else
F_75 ( & V_5 -> V_53 , V_81 ) ;
V_81 = & V_5 -> V_53 ;
if ( F_139 ( F_88 ( V_5 ) ) )
F_85 ( V_12 , V_125 ,
- ( 1 << V_34 ) ) ;
}
F_85 ( V_12 , V_126 , - ( V_35 << V_34 ) ) ;
F_92 ( & V_12 -> V_78 ) ;
return V_35 ;
}
void F_145 ( struct V_12 * V_12 , struct V_73 * V_74 )
{
unsigned long V_52 ;
int V_127 , V_128 ;
F_111 ( V_52 ) ;
V_128 = F_146 ( V_74 -> V_128 ) ;
V_127 = F_72 ( V_74 -> V_72 , V_128 ) ;
if ( V_127 > 0 ) {
F_82 ( V_12 , V_127 , V_74 ) ;
V_74 -> V_72 -= V_127 ;
}
F_114 ( V_52 ) ;
}
static void F_147 ( unsigned int V_129 , struct V_12 * V_12 )
{
unsigned long V_52 ;
struct V_130 * V_131 ;
struct V_73 * V_74 ;
F_111 ( V_52 ) ;
V_131 = F_148 ( V_12 -> V_132 , V_129 ) ;
V_74 = & V_131 -> V_74 ;
if ( V_74 -> V_72 ) {
F_82 ( V_12 , V_74 -> V_72 , V_74 ) ;
V_74 -> V_72 = 0 ;
}
F_114 ( V_52 ) ;
}
static void F_149 ( unsigned int V_129 )
{
struct V_12 * V_12 ;
F_150 (zone) {
F_147 ( V_129 , V_12 ) ;
}
}
void F_151 ( struct V_12 * V_12 )
{
int V_129 = F_152 () ;
if ( V_12 )
F_147 ( V_129 , V_12 ) ;
else
F_149 ( V_129 ) ;
}
void F_153 ( struct V_12 * V_12 )
{
int V_129 ;
static T_3 V_133 ;
F_154 (cpu) {
struct V_130 * V_74 ;
struct V_12 * V_134 ;
bool V_135 = false ;
if ( V_12 ) {
V_74 = F_148 ( V_12 -> V_132 , V_129 ) ;
if ( V_74 -> V_74 . V_72 )
V_135 = true ;
} else {
F_150 (z) {
V_74 = F_148 ( V_134 -> V_132 , V_129 ) ;
if ( V_74 -> V_74 . V_72 ) {
V_135 = true ;
break;
}
}
}
if ( V_135 )
F_155 ( V_129 , & V_133 ) ;
else
F_156 ( V_129 , & V_133 ) ;
}
F_157 ( & V_133 , ( V_136 ) F_151 ,
V_12 , 1 ) ;
}
void F_158 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_137 ;
unsigned long V_52 ;
unsigned int V_34 , V_138 ;
struct V_80 * V_139 ;
if ( F_159 ( V_12 ) )
return;
F_160 ( & V_12 -> V_78 , V_52 ) ;
V_137 = F_161 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_137 ; V_15 ++ )
if ( F_162 ( V_15 ) ) {
struct V_5 * V_5 = F_135 ( V_15 ) ;
if ( ! F_163 ( V_5 ) )
F_164 ( V_5 ) ;
}
F_165 (order, t) {
F_166 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_35 ;
V_15 = F_10 ( F_87 ( V_139 , struct V_5 , V_53 ) ) ;
for ( V_35 = 0 ; V_35 < ( 1UL << V_34 ) ; V_35 ++ )
F_167 ( F_135 ( V_15 + V_35 ) ) ;
}
}
F_168 ( & V_12 -> V_78 , V_52 ) ;
}
void F_169 ( struct V_5 * V_5 , bool V_124 )
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
F_170 ( V_90 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_58 ( V_6 ) ) ) {
F_93 ( V_12 , V_5 , V_15 , 0 , V_6 ) ;
goto V_27;
}
V_6 = V_140 ;
}
V_74 = & F_171 ( V_12 -> V_132 ) -> V_74 ;
if ( ! V_124 )
F_76 ( & V_5 -> V_53 , & V_74 -> V_82 [ V_6 ] ) ;
else
F_75 ( & V_5 -> V_53 , & V_74 -> V_82 [ V_6 ] ) ;
V_74 -> V_72 ++ ;
if ( V_74 -> V_72 >= V_74 -> V_97 ) {
unsigned long V_128 = F_146 ( V_74 -> V_128 ) ;
F_82 ( V_12 , V_128 , V_74 ) ;
V_74 -> V_72 -= V_128 ;
}
V_27:
F_114 ( V_52 ) ;
}
void F_172 ( struct V_80 * V_81 , bool V_124 )
{
struct V_5 * V_5 , * V_107 ;
F_173 (page, next, list, lru) {
F_174 ( V_5 , V_124 ) ;
F_169 ( V_5 , V_124 ) ;
}
}
void F_175 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
F_67 ( F_99 ( V_5 ) , V_5 ) ;
F_67 ( ! F_68 ( V_5 ) , V_5 ) ;
#ifdef F_176
if ( F_177 ( V_5 ) )
F_175 ( F_178 ( V_5 [ 0 ] . V_141 ) , V_34 ) ;
#endif
F_128 ( V_5 , 0 , 0 ) ;
for ( V_35 = 1 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
F_118 ( V_5 + V_35 ) ;
F_128 ( V_5 + V_35 , 0 , 0 ) ;
}
}
int F_179 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_142 ;
struct V_12 * V_12 ;
int V_83 ;
F_180 ( ! F_69 ( V_5 ) ) ;
V_12 = F_18 ( V_5 ) ;
V_83 = F_90 ( V_5 ) ;
if ( ! F_58 ( V_83 ) ) {
V_142 = F_181 ( V_12 ) + ( 1 << V_34 ) ;
if ( ! F_182 ( V_12 , 0 , V_142 , 0 , 0 ) )
return 0 ;
F_55 ( V_12 , - ( 1UL << V_34 ) , V_83 ) ;
}
F_74 ( & V_5 -> V_53 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
F_61 ( V_5 ) ;
if ( V_34 >= V_61 - 1 ) {
struct V_5 * V_143 = V_5 + ( 1 << V_34 ) - 1 ;
for (; V_5 < V_143 ; V_5 += V_93 ) {
int V_83 = F_90 ( V_5 ) ;
if ( ! F_58 ( V_83 ) && ! F_139 ( V_83 ) )
F_6 ( V_5 ,
V_140 ) ;
}
}
F_128 ( V_5 , V_34 , 0 ) ;
return 1UL << V_34 ;
}
int F_183 ( struct V_5 * V_5 )
{
unsigned int V_34 ;
int V_36 ;
V_34 = F_65 ( V_5 ) ;
V_36 = F_179 ( V_5 , V_34 ) ;
if ( ! V_36 )
return 0 ;
F_118 ( V_5 ) ;
F_175 ( V_5 , V_34 ) ;
return V_36 ;
}
static inline
struct V_5 * F_184 ( struct V_12 * V_144 ,
struct V_12 * V_12 , unsigned int V_34 ,
T_1 V_39 , int V_6 )
{
unsigned long V_52 ;
struct V_5 * V_5 ;
bool V_124 = ( ( V_39 & V_145 ) != 0 ) ;
if ( F_144 ( V_34 == 0 ) ) {
struct V_73 * V_74 ;
struct V_80 * V_81 ;
F_111 ( V_52 ) ;
V_74 = & F_171 ( V_12 -> V_132 ) -> V_74 ;
V_81 = & V_74 -> V_82 [ V_6 ] ;
if ( F_86 ( V_81 ) ) {
V_74 -> V_72 += F_143 ( V_12 , 0 ,
V_74 -> V_128 , V_81 ,
V_6 , V_124 ) ;
if ( F_7 ( F_86 ( V_81 ) ) )
goto V_146;
}
if ( V_124 )
V_5 = F_87 ( V_81 -> V_84 , struct V_5 , V_53 ) ;
else
V_5 = F_87 ( V_81 -> V_107 , struct V_5 , V_53 ) ;
F_74 ( & V_5 -> V_53 ) ;
V_74 -> V_72 -- ;
} else {
if ( F_7 ( V_39 & V_147 ) ) {
F_185 ( V_34 > 1 ) ;
}
F_160 ( & V_12 -> V_78 , V_52 ) ;
V_5 = F_141 ( V_12 , V_34 , V_6 ) ;
F_92 ( & V_12 -> V_78 ) ;
if ( ! V_5 )
goto V_146;
F_55 ( V_12 , - ( 1 << V_34 ) ,
F_88 ( V_5 ) ) ;
}
F_85 ( V_12 , V_148 , - ( 1 << V_34 ) ) ;
if ( F_186 ( & V_12 -> V_149 [ V_148 ] ) <= 0 &&
! F_187 ( V_150 , & V_12 -> V_52 ) )
F_188 ( V_150 , & V_12 -> V_52 ) ;
F_189 ( V_151 , V_12 , 1 << V_34 ) ;
F_190 ( V_144 , V_12 , V_39 ) ;
F_114 ( V_52 ) ;
F_67 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
return V_5 ;
V_146:
F_114 ( V_52 ) ;
return NULL ;
}
static int T_2 F_191 ( char * V_152 )
{
return F_192 ( & V_153 . V_154 , V_152 ) ;
}
static bool F_193 ( T_1 V_155 , unsigned int V_34 )
{
if ( V_34 < V_153 . V_156 )
return false ;
if ( V_155 & V_147 )
return false ;
if ( V_153 . V_157 && ( V_155 & V_40 ) )
return false ;
if ( V_153 . V_158 && ( V_155 & V_159 ) )
return false ;
return F_194 ( & V_153 . V_154 , 1 << V_34 ) ;
}
static int T_2 F_195 ( void )
{
T_4 V_160 = V_161 | V_162 | V_163 ;
struct V_164 * V_165 ;
V_165 = F_196 ( L_15 , NULL ,
& V_153 . V_154 ) ;
if ( F_197 ( V_165 ) )
return F_198 ( V_165 ) ;
if ( ! F_199 ( L_16 , V_160 , V_165 ,
& V_153 . V_158 ) )
goto V_166;
if ( ! F_199 ( L_17 , V_160 , V_165 ,
& V_153 . V_157 ) )
goto V_166;
if ( ! F_200 ( L_18 , V_160 , V_165 ,
& V_153 . V_156 ) )
goto V_166;
return 0 ;
V_166:
F_201 ( V_165 ) ;
return - V_167 ;
}
static inline bool F_193 ( T_1 V_155 , unsigned int V_34 )
{
return false ;
}
static bool F_202 ( struct V_12 * V_134 , unsigned int V_34 ,
unsigned long V_168 , int V_169 , int V_101 ,
long V_170 )
{
long F_72 = V_168 ;
int V_171 ;
long V_172 = 0 ;
V_170 -= ( 1 << V_34 ) - 1 ;
if ( V_101 & V_173 )
F_72 -= F_72 / 2 ;
if ( V_101 & V_174 )
F_72 -= F_72 / 4 ;
#ifdef F_203
if ( ! ( V_101 & V_175 ) )
V_172 = F_84 ( V_134 , V_125 ) ;
#endif
if ( V_170 - V_172 <= F_72 + V_134 -> V_176 [ V_169 ] )
return false ;
for ( V_171 = 0 ; V_171 < V_34 ; V_171 ++ ) {
V_170 -= V_134 -> V_62 [ V_171 ] . V_63 << V_171 ;
F_72 >>= 1 ;
if ( V_170 <= F_72 )
return false ;
}
return true ;
}
bool F_182 ( struct V_12 * V_134 , unsigned int V_34 , unsigned long V_168 ,
int V_169 , int V_101 )
{
return F_202 ( V_134 , V_34 , V_168 , V_169 , V_101 ,
F_84 ( V_134 , V_126 ) ) ;
}
bool F_204 ( struct V_12 * V_134 , unsigned int V_34 ,
unsigned long V_168 , int V_169 , int V_101 )
{
long V_170 = F_84 ( V_134 , V_126 ) ;
if ( V_134 -> V_177 && V_170 < V_134 -> V_177 )
V_170 = F_205 ( V_134 , V_126 ) ;
return F_202 ( V_134 , V_34 , V_168 , V_169 , V_101 ,
V_170 ) ;
}
static T_5 * F_206 ( struct V_178 * V_178 , int V_101 )
{
struct V_179 * V_180 ;
T_5 * V_181 ;
V_180 = V_178 -> V_182 ;
if ( ! V_180 )
return NULL ;
if ( F_207 ( V_26 , V_180 -> V_183 + V_29 ) ) {
F_208 ( V_180 -> V_184 , V_185 ) ;
V_180 -> V_183 = V_26 ;
}
V_181 = ! F_41 () && ( V_101 & V_186 ) ?
& V_187 :
& V_188 [ V_189 ] ;
return V_181 ;
}
static int F_209 ( struct V_178 * V_178 , struct V_190 * V_134 ,
T_5 * V_181 )
{
struct V_179 * V_180 ;
int V_35 ;
int V_191 ;
V_180 = V_178 -> V_182 ;
if ( ! V_180 )
return 1 ;
V_35 = V_134 - V_178 -> V_192 ;
V_191 = V_180 -> V_193 [ V_35 ] ;
return F_210 ( V_191 , * V_181 ) && ! F_187 ( V_35 , V_180 -> V_184 ) ;
}
static void F_211 ( struct V_178 * V_178 , struct V_190 * V_134 )
{
struct V_179 * V_180 ;
int V_35 ;
V_180 = V_178 -> V_182 ;
if ( ! V_180 )
return;
V_35 = V_134 - V_178 -> V_192 ;
F_188 ( V_35 , V_180 -> V_184 ) ;
}
static void F_212 ( struct V_178 * V_178 )
{
struct V_179 * V_180 ;
V_180 = V_178 -> V_182 ;
if ( ! V_180 )
return;
F_208 ( V_180 -> V_184 , V_185 ) ;
}
static bool F_213 ( struct V_12 * V_194 , struct V_12 * V_12 )
{
return V_194 -> V_195 == V_12 -> V_195 ;
}
static bool F_214 ( struct V_12 * V_194 , struct V_12 * V_12 )
{
return F_215 ( F_15 ( V_194 ) , F_15 ( V_12 ) ) <
V_196 ;
}
static T_5 * F_206 ( struct V_178 * V_178 , int V_101 )
{
return NULL ;
}
static int F_209 ( struct V_178 * V_178 , struct V_190 * V_134 ,
T_5 * V_181 )
{
return 1 ;
}
static void F_211 ( struct V_178 * V_178 , struct V_190 * V_134 )
{
}
static void F_212 ( struct V_178 * V_178 )
{
}
static bool F_213 ( struct V_12 * V_194 , struct V_12 * V_12 )
{
return true ;
}
static bool F_214 ( struct V_12 * V_194 , struct V_12 * V_12 )
{
return true ;
}
static void F_216 ( struct V_12 * V_144 )
{
struct V_12 * V_12 = V_144 -> V_197 -> V_198 ;
do {
F_217 ( V_12 , V_148 ,
F_218 ( V_12 ) - F_181 ( V_12 ) -
F_186 ( & V_12 -> V_149 [ V_148 ] ) ) ;
F_219 ( V_150 , & V_12 -> V_52 ) ;
} while ( V_12 ++ != V_144 );
}
static struct V_5 *
F_220 ( T_1 V_155 , unsigned int V_34 , int V_101 ,
const struct V_199 * V_200 )
{
struct V_178 * V_178 = V_200 -> V_178 ;
struct V_190 * V_134 ;
struct V_5 * V_5 = NULL ;
struct V_12 * V_12 ;
T_5 * V_181 = NULL ;
int V_201 = 0 ;
int V_202 = 0 ;
bool V_203 = ( V_101 & V_204 ) &&
( V_155 & V_205 ) ;
int V_206 = 0 ;
bool V_207 ;
V_208:
V_207 = false ;
F_221 (zone, z, zonelist, ac->high_zoneidx,
ac->nodemask) {
unsigned long V_168 ;
if ( F_96 ( V_209 ) && V_201 &&
! F_209 ( V_178 , V_134 , V_181 ) )
continue;
if ( F_222 () &&
( V_101 & V_186 ) &&
! F_223 ( V_12 , V_155 ) )
continue;
if ( V_101 & V_210 ) {
if ( ! F_213 ( V_200 -> V_144 , V_12 ) )
break;
if ( F_187 ( V_150 , & V_12 -> V_52 ) ) {
V_206 ++ ;
continue;
}
}
if ( V_203 && ! F_224 ( V_12 ) )
continue;
V_168 = V_12 -> V_142 [ V_101 & V_211 ] ;
if ( ! F_182 ( V_12 , V_34 , V_168 ,
V_200 -> V_169 , V_101 ) ) {
int V_13 ;
F_225 ( V_105 < V_212 ) ;
if ( V_101 & V_105 )
goto V_213;
if ( F_96 ( V_209 ) &&
! V_202 && V_214 > 1 ) {
V_181 = F_206 ( V_178 , V_101 ) ;
V_201 = 1 ;
V_202 = 1 ;
}
if ( V_215 == 0 ||
! F_214 ( V_200 -> V_144 , V_12 ) )
goto V_216;
if ( F_96 ( V_209 ) && V_201 &&
! F_209 ( V_178 , V_134 , V_181 ) )
continue;
V_13 = F_226 ( V_12 , V_155 , V_34 ) ;
switch ( V_13 ) {
case V_217 :
continue;
case V_218 :
continue;
default:
if ( F_182 ( V_12 , V_34 , V_168 ,
V_200 -> V_169 , V_101 ) )
goto V_213;
if ( ( ( V_101 & V_211 ) == V_219 ) ||
V_13 == V_220 )
goto V_216;
continue;
}
}
V_213:
V_5 = F_184 ( V_200 -> V_144 , V_12 , V_34 ,
V_155 , V_200 -> V_6 ) ;
if ( V_5 ) {
if ( F_125 ( V_5 , V_34 , V_155 , V_101 ) )
goto V_213;
return V_5 ;
}
V_216:
if ( F_96 ( V_209 ) && V_201 )
F_211 ( V_178 , V_134 ) ;
}
if ( V_101 & V_210 ) {
V_101 &= ~ V_210 ;
if ( V_206 ) {
V_207 = true ;
F_216 ( V_200 -> V_144 ) ;
}
if ( V_214 > 1 )
V_207 = true ;
}
if ( F_7 ( F_96 ( V_209 ) && V_201 ) ) {
V_201 = 0 ;
V_207 = true ;
}
if ( V_207 )
goto V_208;
return NULL ;
}
static inline bool F_227 ( void )
{
bool V_13 = false ;
#if V_221 > 8
V_13 = F_41 () ;
#endif
return V_13 ;
}
void F_228 ( T_1 V_155 , int V_34 , const char * V_222 , ... )
{
unsigned int V_223 = V_224 ;
if ( ( V_155 & V_225 ) || ! F_229 ( & V_226 ) ||
F_123 () > 0 )
return;
if ( ! ( V_155 & V_227 ) )
if ( F_230 ( V_228 ) ||
( V_30 -> V_52 & ( V_229 | V_230 ) ) )
V_223 &= ~ V_224 ;
if ( F_41 () || ! ( V_155 & V_159 ) )
V_223 &= ~ V_224 ;
if ( V_222 ) {
struct V_231 V_232 ;
T_6 args ;
va_start ( args , V_222 ) ;
V_232 . V_222 = V_222 ;
V_232 . V_233 = & args ;
F_231 ( L_19 , & V_232 ) ;
va_end ( args ) ;
}
F_231 ( L_20 ,
V_30 -> V_31 , V_34 , V_155 ) ;
F_27 () ;
if ( ! F_227 () )
F_232 ( V_223 ) ;
}
static inline int
F_233 ( T_1 V_155 , unsigned int V_34 ,
unsigned long V_234 ,
unsigned long V_235 )
{
if ( V_155 & V_236 )
return 0 ;
if ( V_155 & V_147 )
return 1 ;
if ( ! V_234 && F_5 () )
return 0 ;
if ( V_34 <= V_237 )
return 1 ;
if ( V_155 & V_238 && V_235 < ( 1 << V_34 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_234 ( T_1 V_155 , unsigned int V_34 ,
const struct V_199 * V_200 , unsigned long * V_234 )
{
struct V_5 * V_5 ;
* V_234 = 0 ;
if ( ! F_235 ( V_200 -> V_178 , V_155 ) ) {
* V_234 = 1 ;
F_236 ( 1 ) ;
return NULL ;
}
V_5 = F_220 ( V_155 | V_239 , V_34 ,
V_240 | V_186 , V_200 ) ;
if ( V_5 )
goto V_27;
if ( ! ( V_155 & V_147 ) ) {
if ( V_30 -> V_52 & V_241 )
goto V_27;
if ( V_34 > V_237 )
goto V_27;
if ( V_200 -> V_242 < V_243 )
goto V_27;
if ( ! ( V_155 & V_244 ) ) {
* V_234 = 1 ;
goto V_27;
}
if ( V_155 & V_245 )
goto V_27;
}
if ( F_237 ( V_200 -> V_178 , V_155 , V_34 , V_200 -> V_246 , false )
|| F_185 ( V_155 & V_147 ) )
* V_234 = 1 ;
V_27:
F_238 ( V_200 -> V_178 , V_155 ) ;
return V_5 ;
}
static struct V_5 *
F_239 ( T_1 V_155 , unsigned int V_34 ,
int V_101 , const struct V_199 * V_200 ,
enum V_247 V_160 , int * V_248 ,
bool * V_249 )
{
unsigned long V_250 ;
struct V_5 * V_5 ;
if ( ! V_34 )
return NULL ;
V_30 -> V_52 |= V_229 ;
V_250 = F_240 ( V_155 , V_34 , V_101 , V_200 ,
V_160 , V_248 ) ;
V_30 -> V_52 &= ~ V_229 ;
switch ( V_250 ) {
case V_251 :
* V_249 = true ;
case V_252 :
return NULL ;
default:
break;
}
F_241 ( V_253 ) ;
V_5 = F_220 ( V_155 , V_34 ,
V_101 & ~ V_105 , V_200 ) ;
if ( V_5 ) {
struct V_12 * V_12 = F_18 ( V_5 ) ;
V_12 -> V_254 = false ;
F_242 ( V_12 , V_34 , true ) ;
F_241 ( V_255 ) ;
return V_5 ;
}
F_241 ( V_256 ) ;
F_243 () ;
return NULL ;
}
static inline struct V_5 *
F_239 ( T_1 V_155 , unsigned int V_34 ,
int V_101 , const struct V_199 * V_200 ,
enum V_247 V_160 , int * V_248 ,
bool * V_249 )
{
return NULL ;
}
static int
F_244 ( T_1 V_155 , unsigned int V_34 ,
const struct V_199 * V_200 )
{
struct V_257 V_257 ;
int V_258 ;
F_243 () ;
F_245 () ;
V_30 -> V_52 |= V_229 ;
F_246 ( V_155 ) ;
V_257 . V_259 = 0 ;
V_30 -> V_257 = & V_257 ;
V_258 = F_247 ( V_200 -> V_178 , V_34 , V_155 ,
V_200 -> V_246 ) ;
V_30 -> V_257 = NULL ;
F_248 () ;
V_30 -> V_52 &= ~ V_229 ;
F_243 () ;
return V_258 ;
}
static inline struct V_5 *
F_249 ( T_1 V_155 , unsigned int V_34 ,
int V_101 , const struct V_199 * V_200 ,
unsigned long * V_234 )
{
struct V_5 * V_5 = NULL ;
bool V_260 = false ;
* V_234 = F_244 ( V_155 , V_34 , V_200 ) ;
if ( F_7 ( ! ( * V_234 ) ) )
return NULL ;
if ( F_96 ( V_209 ) )
F_212 ( V_200 -> V_178 ) ;
V_261:
V_5 = F_220 ( V_155 , V_34 ,
V_101 & ~ V_105 , V_200 ) ;
if ( ! V_5 && ! V_260 ) {
F_153 ( NULL ) ;
V_260 = true ;
goto V_261;
}
return V_5 ;
}
static inline struct V_5 *
F_250 ( T_1 V_155 , unsigned int V_34 ,
const struct V_199 * V_200 )
{
struct V_5 * V_5 ;
do {
V_5 = F_220 ( V_155 , V_34 ,
V_105 , V_200 ) ;
if ( ! V_5 && V_155 & V_147 )
F_251 ( V_200 -> V_144 , V_262 ,
V_29 / 50 ) ;
} while ( ! V_5 && ( V_155 & V_147 ) );
return V_5 ;
}
static void F_252 ( unsigned int V_34 , const struct V_199 * V_200 )
{
struct V_190 * V_134 ;
struct V_12 * V_12 ;
F_221 (zone, z, ac->zonelist,
ac->high_zoneidx, ac->nodemask)
F_253 ( V_12 , V_34 , F_254 ( V_200 -> V_144 ) ) ;
}
static inline int
F_255 ( T_1 V_155 )
{
int V_101 = V_219 | V_186 ;
const bool V_263 = ! ( V_155 & ( V_159 | V_264 ) ) ;
F_225 ( V_265 != ( V_266 T_1 ) V_173 ) ;
V_101 |= ( V_266 int ) ( V_155 & V_265 ) ;
if ( V_263 ) {
if ( ! ( V_155 & V_227 ) )
V_101 |= V_174 ;
V_101 &= ~ V_186 ;
} else if ( F_7 ( F_256 ( V_30 ) ) && ! F_41 () )
V_101 |= V_174 ;
if ( F_144 ( ! ( V_155 & V_227 ) ) ) {
if ( V_155 & V_267 )
V_101 |= V_105 ;
else if ( F_257 () && ( V_30 -> V_52 & V_229 ) )
V_101 |= V_105 ;
else if ( ! F_41 () &&
( ( V_30 -> V_52 & V_229 ) ||
F_7 ( F_230 ( V_228 ) ) ) )
V_101 |= V_105 ;
}
#ifdef F_203
if ( F_258 ( V_155 ) == V_140 )
V_101 |= V_175 ;
#endif
return V_101 ;
}
bool F_259 ( T_1 V_155 )
{
return ! ! ( F_255 ( V_155 ) & V_105 ) ;
}
static inline struct V_5 *
F_260 ( T_1 V_155 , unsigned int V_34 ,
struct V_199 * V_200 )
{
const T_1 V_268 = V_155 & V_159 ;
struct V_5 * V_5 = NULL ;
int V_101 ;
unsigned long V_235 = 0 ;
unsigned long V_234 ;
enum V_247 V_269 = V_270 ;
bool V_249 = false ;
int V_248 = V_271 ;
if ( V_34 >= V_46 ) {
F_185 ( ! ( V_155 & V_225 ) ) ;
return NULL ;
}
if ( F_96 ( V_209 ) &&
( V_155 & V_272 ) == V_272 )
goto V_273;
V_261:
if ( ! ( V_155 & V_264 ) )
F_252 ( V_34 , V_200 ) ;
V_101 = F_255 ( V_155 ) ;
if ( ! ( V_101 & V_186 ) && ! V_200 -> V_246 ) {
struct V_190 * V_274 ;
V_274 = F_261 ( V_200 -> V_178 ,
V_200 -> V_242 , NULL , & V_200 -> V_144 ) ;
V_200 -> V_169 = F_262 ( V_274 ) ;
}
V_5 = F_220 ( V_155 , V_34 ,
V_101 & ~ V_105 , V_200 ) ;
if ( V_5 )
goto V_275;
if ( V_101 & V_105 ) {
V_200 -> V_178 = F_263 ( F_264 () , V_155 ) ;
V_5 = F_250 ( V_155 , V_34 , V_200 ) ;
if ( V_5 ) {
goto V_275;
}
}
if ( ! V_268 ) {
F_185 ( V_155 & V_147 ) ;
goto V_273;
}
if ( V_30 -> V_52 & V_229 )
goto V_273;
if ( F_230 ( V_228 ) && ! ( V_155 & V_147 ) )
goto V_273;
V_5 = F_239 ( V_155 , V_34 , V_101 , V_200 ,
V_269 ,
& V_248 ,
& V_249 ) ;
if ( V_5 )
goto V_275;
if ( ( V_155 & V_276 ) == V_276 ) {
if ( V_249 )
goto V_273;
if ( V_248 == V_277 )
goto V_273;
if ( V_248 == V_278
&& ! ( V_30 -> V_52 & V_279 ) )
goto V_273;
}
if ( ( V_155 & V_276 ) != V_276 ||
( V_30 -> V_52 & V_279 ) )
V_269 = V_280 ;
V_5 = F_249 ( V_155 , V_34 , V_101 , V_200 ,
& V_234 ) ;
if ( V_5 )
goto V_275;
V_235 += V_234 ;
if ( F_233 ( V_155 , V_34 , V_234 ,
V_235 ) ) {
if ( ! V_234 ) {
V_5 = F_234 ( V_155 , V_34 , V_200 ,
& V_234 ) ;
if ( V_5 )
goto V_275;
if ( ! V_234 )
goto V_273;
}
F_251 ( V_200 -> V_144 , V_262 , V_29 / 50 ) ;
goto V_261;
} else {
V_5 = F_239 ( V_155 , V_34 ,
V_101 , V_200 , V_269 ,
& V_248 ,
& V_249 ) ;
if ( V_5 )
goto V_275;
}
V_273:
F_228 ( V_155 , V_34 , NULL ) ;
V_275:
return V_5 ;
}
struct V_5 *
F_265 ( T_1 V_155 , unsigned int V_34 ,
struct V_178 * V_178 , T_5 * V_246 )
{
struct V_190 * V_274 ;
struct V_5 * V_5 = NULL ;
unsigned int V_281 ;
int V_101 = V_204 | V_186 | V_210 ;
T_1 V_282 ;
struct V_199 V_200 = {
. V_242 = F_266 ( V_155 ) ,
. V_246 = V_246 ,
. V_6 = F_258 ( V_155 ) ,
} ;
V_155 &= V_3 ;
F_267 ( V_155 ) ;
F_268 ( V_155 & V_159 ) ;
if ( F_193 ( V_155 , V_34 ) )
return NULL ;
if ( F_7 ( ! V_178 -> V_192 -> V_12 ) )
return NULL ;
if ( F_96 ( F_203 ) && V_200 . V_6 == V_140 )
V_101 |= V_175 ;
V_283:
V_281 = F_269 () ;
V_200 . V_178 = V_178 ;
V_274 = F_261 ( V_200 . V_178 , V_200 . V_242 ,
V_200 . V_246 ? : & V_187 ,
& V_200 . V_144 ) ;
if ( ! V_200 . V_144 )
goto V_27;
V_200 . V_169 = F_262 ( V_274 ) ;
V_282 = V_155 | V_239 ;
V_5 = F_220 ( V_282 , V_34 , V_101 , & V_200 ) ;
if ( F_7 ( ! V_5 ) ) {
V_282 = F_270 ( V_155 ) ;
V_5 = F_260 ( V_282 , V_34 , & V_200 ) ;
}
if ( V_284 && V_5 )
F_271 ( V_5 , V_34 , V_155 ) ;
F_272 ( V_5 , V_34 , V_282 , V_200 . V_6 ) ;
V_27:
if ( F_7 ( ! V_5 && F_273 ( V_281 ) ) )
goto V_283;
return V_5 ;
}
unsigned long F_274 ( T_1 V_155 , unsigned int V_34 )
{
struct V_5 * V_5 ;
F_40 ( ( V_155 & V_40 ) != 0 ) ;
V_5 = F_275 ( V_155 , V_34 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_107 ( V_5 ) ;
}
unsigned long F_276 ( T_1 V_155 )
{
return F_274 ( V_155 | V_102 , 0 ) ;
}
void F_119 ( struct V_5 * V_5 , unsigned int V_34 )
{
if ( F_277 ( V_5 ) ) {
if ( V_34 == 0 )
F_169 ( V_5 , false ) ;
else
F_30 ( V_5 , V_34 ) ;
}
}
void V_170 ( unsigned long V_285 , unsigned int V_34 )
{
if ( V_285 != 0 ) {
F_40 ( ! F_278 ( ( void * ) V_285 ) ) ;
F_119 ( F_178 ( ( void * ) V_285 ) , V_34 ) ;
}
}
struct V_5 * F_279 ( T_1 V_155 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_71 * V_286 = NULL ;
if ( ! F_280 ( V_155 , & V_286 , V_34 ) )
return NULL ;
V_5 = F_275 ( V_155 , V_34 ) ;
F_281 ( V_5 , V_286 , V_34 ) ;
return V_5 ;
}
struct V_5 * F_282 ( int V_287 , T_1 V_155 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_71 * V_286 = NULL ;
if ( ! F_280 ( V_155 , & V_286 , V_34 ) )
return NULL ;
V_5 = F_283 ( V_287 , V_155 , V_34 ) ;
F_281 ( V_5 , V_286 , V_34 ) ;
return V_5 ;
}
void F_284 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_285 ( V_5 , V_34 ) ;
F_119 ( V_5 , V_34 ) ;
}
void F_286 ( unsigned long V_285 , unsigned int V_34 )
{
if ( V_285 != 0 ) {
F_40 ( ! F_278 ( ( void * ) V_285 ) ) ;
F_284 ( F_178 ( ( void * ) V_285 ) , V_34 ) ;
}
}
static void * F_287 ( unsigned long V_285 , unsigned V_34 , T_7 V_99 )
{
if ( V_285 ) {
unsigned long V_288 = V_285 + ( V_89 << V_34 ) ;
unsigned long V_289 = V_285 + F_288 ( V_99 ) ;
F_175 ( F_178 ( ( void * ) V_285 ) , V_34 ) ;
while ( V_289 < V_288 ) {
F_289 ( V_289 ) ;
V_289 += V_89 ;
}
}
return ( void * ) V_285 ;
}
void * F_290 ( T_7 V_99 , T_1 V_155 )
{
unsigned int V_34 = F_291 ( V_99 ) ;
unsigned long V_285 ;
V_285 = F_274 ( V_155 , V_34 ) ;
return F_287 ( V_285 , V_34 , V_99 ) ;
}
void * T_8 F_292 ( int V_287 , T_7 V_99 , T_1 V_155 )
{
unsigned V_34 = F_291 ( V_99 ) ;
struct V_5 * V_37 = F_283 ( V_287 , V_155 , V_34 ) ;
if ( ! V_37 )
return NULL ;
return F_287 ( ( unsigned long ) F_107 ( V_37 ) , V_34 , V_99 ) ;
}
void F_293 ( void * V_290 , T_7 V_99 )
{
unsigned long V_285 = ( unsigned long ) V_290 ;
unsigned long V_291 = V_285 + F_288 ( V_99 ) ;
while ( V_285 < V_291 ) {
F_289 ( V_285 ) ;
V_285 += V_89 ;
}
}
static unsigned long F_294 ( int V_292 )
{
struct V_190 * V_134 ;
struct V_12 * V_12 ;
unsigned long V_293 = 0 ;
struct V_178 * V_178 = F_263 ( F_264 () , V_294 ) ;
F_295 (zone, z, zonelist, offset) {
unsigned long V_99 = V_12 -> V_92 ;
unsigned long V_97 = F_218 ( V_12 ) ;
if ( V_99 > V_97 )
V_293 += V_99 - V_97 ;
}
return V_293 ;
}
unsigned long F_296 ( void )
{
return F_294 ( F_266 ( V_295 ) ) ;
}
unsigned long F_297 ( void )
{
return F_294 ( F_266 ( V_296 ) ) ;
}
static inline void F_298 ( struct V_12 * V_12 )
{
if ( F_96 ( V_209 ) )
F_24 ( L_21 , F_15 ( V_12 ) ) ;
}
void F_299 ( struct V_297 * V_298 )
{
V_298 -> V_299 = V_300 ;
V_298 -> V_301 = F_300 ( V_302 ) ;
V_298 -> V_303 = F_300 ( V_126 ) ;
V_298 -> V_304 = F_301 () ;
V_298 -> V_305 = V_306 ;
V_298 -> V_307 = F_302 () ;
V_298 -> V_308 = V_89 ;
}
void F_303 ( struct V_297 * V_298 , int V_287 )
{
int V_309 ;
unsigned long V_92 = 0 ;
T_9 * V_310 = F_304 ( V_287 ) ;
for ( V_309 = 0 ; V_309 < V_311 ; V_309 ++ )
V_92 += V_310 -> V_198 [ V_309 ] . V_92 ;
V_298 -> V_299 = V_92 ;
V_298 -> V_301 = F_305 ( V_287 , V_302 ) ;
V_298 -> V_303 = F_305 ( V_287 , V_126 ) ;
#ifdef F_306
V_298 -> V_305 = V_310 -> V_198 [ V_312 ] . V_92 ;
V_298 -> V_307 = F_84 ( & V_310 -> V_198 [ V_312 ] ,
V_126 ) ;
#else
V_298 -> V_305 = 0 ;
V_298 -> V_307 = 0 ;
#endif
V_298 -> V_308 = V_89 ;
}
bool F_307 ( unsigned int V_52 , int V_287 )
{
bool V_13 = false ;
unsigned int V_281 ;
if ( ! ( V_52 & V_224 ) )
goto V_27;
do {
V_281 = F_269 () ;
V_13 = ! F_210 ( V_287 , V_187 ) ;
} while ( F_273 ( V_281 ) );
V_27:
return V_13 ;
}
static void F_308 ( unsigned char type )
{
static const char V_313 [ V_314 ] = {
[ V_9 ] = 'U' ,
[ V_117 ] = 'E' ,
[ V_140 ] = 'M' ,
[ V_122 ] = 'R' ,
#ifdef F_203
[ V_94 ] = 'C' ,
#endif
#ifdef F_309
[ V_315 ] = 'I' ,
#endif
} ;
char V_316 [ V_314 + 1 ] ;
char * V_37 = V_316 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_314 ; V_35 ++ ) {
if ( type & ( 1 << V_35 ) )
* V_37 ++ = V_313 [ V_35 ] ;
}
* V_37 = '\0' ;
F_24 ( L_22 , V_316 ) ;
}
void F_310 ( unsigned int V_223 )
{
int V_129 ;
struct V_12 * V_12 ;
F_150 (zone) {
if ( F_307 ( V_223 , F_15 ( V_12 ) ) )
continue;
F_298 ( V_12 ) ;
F_24 ( L_23 , V_12 -> V_20 ) ;
F_154 (cpu) {
struct V_130 * V_132 ;
V_132 = F_148 ( V_12 -> V_132 , V_129 ) ;
F_24 ( L_24 ,
V_129 , V_132 -> V_74 . V_97 ,
V_132 -> V_74 . V_128 , V_132 -> V_74 . V_72 ) ;
}
}
F_24 ( L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
F_300 ( V_317 ) ,
F_300 ( V_318 ) ,
F_300 ( V_319 ) ,
F_300 ( V_320 ) ,
F_300 ( V_321 ) ,
F_300 ( V_322 ) ,
F_300 ( V_323 ) ,
F_300 ( V_324 ) ,
F_300 ( V_325 ) ,
F_300 ( V_326 ) ,
F_300 ( V_126 ) ,
F_300 ( V_327 ) ,
F_300 ( V_328 ) ,
F_300 ( V_329 ) ,
F_300 ( V_302 ) ,
F_300 ( V_330 ) ,
F_300 ( V_331 ) ,
F_300 ( V_125 ) ) ;
F_150 (zone) {
int V_35 ;
if ( F_307 ( V_223 , F_15 ( V_12 ) ) )
continue;
F_298 ( V_12 ) ;
F_24 ( L_32
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
L_61 ,
V_12 -> V_20 ,
F_311 ( F_84 ( V_12 , V_126 ) ) ,
F_311 ( F_312 ( V_12 ) ) ,
F_311 ( F_181 ( V_12 ) ) ,
F_311 ( F_218 ( V_12 ) ) ,
F_311 ( F_84 ( V_12 , V_317 ) ) ,
F_311 ( F_84 ( V_12 , V_318 ) ) ,
F_311 ( F_84 ( V_12 , V_320 ) ) ,
F_311 ( F_84 ( V_12 , V_321 ) ) ,
F_311 ( F_84 ( V_12 , V_323 ) ) ,
F_311 ( F_84 ( V_12 , V_319 ) ) ,
F_311 ( F_84 ( V_12 , V_322 ) ) ,
F_311 ( V_12 -> V_332 ) ,
F_311 ( V_12 -> V_92 ) ,
F_311 ( F_84 ( V_12 , V_333 ) ) ,
F_311 ( F_84 ( V_12 , V_324 ) ) ,
F_311 ( F_84 ( V_12 , V_325 ) ) ,
F_311 ( F_84 ( V_12 , V_329 ) ) ,
F_311 ( F_84 ( V_12 , V_302 ) ) ,
F_311 ( F_84 ( V_12 , V_327 ) ) ,
F_311 ( F_84 ( V_12 , V_328 ) ) ,
F_84 ( V_12 , V_334 ) *
V_335 / 1024 ,
F_311 ( F_84 ( V_12 , V_330 ) ) ,
F_311 ( F_84 ( V_12 , V_326 ) ) ,
F_311 ( F_84 ( V_12 , V_331 ) ) ,
F_311 ( F_84 ( V_12 , V_125 ) ) ,
F_311 ( F_84 ( V_12 , V_336 ) ) ,
F_311 ( F_84 ( V_12 , V_79 ) ) ,
( ! F_313 ( V_12 ) ? L_62 : L_63 )
) ;
F_24 ( L_64 ) ;
for ( V_35 = 0 ; V_35 < V_311 ; V_35 ++ )
F_24 ( L_65 , V_12 -> V_176 [ V_35 ] ) ;
F_24 ( L_61 ) ;
}
F_150 (zone) {
unsigned long V_337 [ V_46 ] , V_52 , V_34 , V_338 = 0 ;
unsigned char V_313 [ V_46 ] ;
if ( F_307 ( V_223 , F_15 ( V_12 ) ) )
continue;
F_298 ( V_12 ) ;
F_24 ( L_66 , V_12 -> V_20 ) ;
F_160 ( & V_12 -> V_78 , V_52 ) ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
struct V_62 * V_98 = & V_12 -> V_62 [ V_34 ] ;
int type ;
V_337 [ V_34 ] = V_98 -> V_63 ;
V_338 += V_337 [ V_34 ] << V_34 ;
V_313 [ V_34 ] = 0 ;
for ( type = 0 ; type < V_314 ; type ++ ) {
if ( ! F_86 ( & V_98 -> V_66 [ type ] ) )
V_313 [ V_34 ] |= 1 << type ;
}
}
F_168 ( & V_12 -> V_78 , V_52 ) ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
F_24 ( L_67 , V_337 [ V_34 ] , F_311 ( 1UL ) << V_34 ) ;
if ( V_337 [ V_34 ] )
F_308 ( V_313 [ V_34 ] ) ;
}
F_24 ( L_68 , F_311 ( V_338 ) ) ;
}
F_314 () ;
F_24 ( L_69 , F_300 ( V_339 ) ) ;
F_315 () ;
}
static void F_316 ( struct V_12 * V_12 , struct V_190 * V_190 )
{
V_190 -> V_12 = V_12 ;
V_190 -> F_254 = F_254 ( V_12 ) ;
}
static int F_317 ( T_9 * V_310 , struct V_178 * V_178 ,
int V_340 )
{
struct V_12 * V_12 ;
enum V_309 V_309 = V_311 ;
do {
V_309 -- ;
V_12 = V_310 -> V_198 + V_309 ;
if ( F_318 ( V_12 ) ) {
F_316 ( V_12 ,
& V_178 -> V_192 [ V_340 ++ ] ) ;
F_319 ( V_309 ) ;
}
} while ( V_309 );
return V_340 ;
}
static int F_320 ( char * V_341 )
{
if ( * V_341 == 'd' || * V_341 == 'D' ) {
V_342 = V_343 ;
} else if ( * V_341 == 'n' || * V_341 == 'N' ) {
V_342 = V_344 ;
} else if ( * V_341 == 'z' || * V_341 == 'Z' ) {
V_342 = V_345 ;
} else {
F_24 ( V_346
L_70
L_71 , V_341 ) ;
return - V_42 ;
}
return 0 ;
}
static T_2 int F_321 ( char * V_341 )
{
int V_13 ;
if ( ! V_341 )
return 0 ;
V_13 = F_320 ( V_341 ) ;
if ( V_13 == 0 )
F_322 ( V_347 , V_341 , V_348 ) ;
return V_13 ;
}
int F_323 ( struct V_349 * V_350 , int V_351 ,
void T_10 * V_352 , T_7 * V_353 ,
T_11 * V_354 )
{
char V_355 [ V_348 ] ;
int V_13 ;
static F_324 ( V_356 ) ;
F_325 ( & V_356 ) ;
if ( V_351 ) {
if ( strlen ( ( char * ) V_350 -> V_357 ) >= V_348 ) {
V_13 = - V_42 ;
goto V_27;
}
strcpy ( V_355 , ( char * ) V_350 -> V_357 ) ;
}
V_13 = F_326 ( V_350 , V_351 , V_352 , V_353 , V_354 ) ;
if ( V_13 )
goto V_27;
if ( V_351 ) {
int V_358 = V_342 ;
V_13 = F_320 ( ( char * ) V_350 -> V_357 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_350 -> V_357 , V_355 ,
V_348 ) ;
V_342 = V_358 ;
} else if ( V_358 != V_342 ) {
F_325 ( & V_359 ) ;
F_327 ( NULL , NULL ) ;
F_328 ( & V_359 ) ;
}
}
V_27:
F_328 ( & V_356 ) ;
return V_13 ;
}
static int F_329 ( int V_195 , T_5 * V_360 )
{
int V_191 , V_298 ;
int V_361 = V_362 ;
int V_363 = V_364 ;
const struct V_365 * V_316 = F_330 ( 0 ) ;
if ( ! F_210 ( V_195 , * V_360 ) ) {
F_331 ( V_195 , * V_360 ) ;
return V_195 ;
}
F_332 (n, N_MEMORY) {
if ( F_210 ( V_191 , * V_360 ) )
continue;
V_298 = F_215 ( V_195 , V_191 ) ;
V_298 += ( V_191 < V_195 ) ;
V_316 = F_330 ( V_191 ) ;
if ( ! F_333 ( V_316 ) )
V_298 += V_366 ;
V_298 *= ( V_367 * V_368 ) ;
V_298 += V_369 [ V_191 ] ;
if ( V_298 < V_361 ) {
V_361 = V_298 ;
V_363 = V_191 ;
}
}
if ( V_363 >= 0 )
F_331 ( V_363 , * V_360 ) ;
return V_363 ;
}
static void F_334 ( T_9 * V_310 , int V_195 )
{
int V_370 ;
struct V_178 * V_178 ;
V_178 = & V_310 -> V_371 [ 0 ] ;
for ( V_370 = 0 ; V_178 -> V_192 [ V_370 ] . V_12 != NULL ; V_370 ++ )
;
V_370 = F_317 ( F_304 ( V_195 ) , V_178 , V_370 ) ;
V_178 -> V_192 [ V_370 ] . V_12 = NULL ;
V_178 -> V_192 [ V_370 ] . F_254 = 0 ;
}
static void F_335 ( T_9 * V_310 )
{
int V_370 ;
struct V_178 * V_178 ;
V_178 = & V_310 -> V_371 [ 1 ] ;
V_370 = F_317 ( V_310 , V_178 , 0 ) ;
V_178 -> V_192 [ V_370 ] . V_12 = NULL ;
V_178 -> V_192 [ V_370 ] . F_254 = 0 ;
}
static void F_336 ( T_9 * V_310 , int V_372 )
{
int V_373 , V_370 , V_195 ;
int V_309 ;
struct V_12 * V_134 ;
struct V_178 * V_178 ;
V_178 = & V_310 -> V_371 [ 0 ] ;
V_373 = 0 ;
for ( V_309 = V_311 - 1 ; V_309 >= 0 ; V_309 -- ) {
for ( V_370 = 0 ; V_370 < V_372 ; V_370 ++ ) {
V_195 = V_374 [ V_370 ] ;
V_134 = & F_304 ( V_195 ) -> V_198 [ V_309 ] ;
if ( F_318 ( V_134 ) ) {
F_316 ( V_134 ,
& V_178 -> V_192 [ V_373 ++ ] ) ;
F_319 ( V_309 ) ;
}
}
}
V_178 -> V_192 [ V_373 ] . V_12 = NULL ;
V_178 -> V_192 [ V_373 ] . F_254 = 0 ;
}
static int F_337 ( void )
{
return V_344 ;
}
static int F_337 ( void )
{
return V_345 ;
}
static void F_338 ( void )
{
if ( V_342 == V_343 )
V_375 = F_337 () ;
else
V_375 = V_342 ;
}
static void F_339 ( T_9 * V_310 )
{
int V_370 , V_195 , V_376 ;
enum V_309 V_35 ;
T_5 V_377 ;
int V_378 , V_379 ;
struct V_178 * V_178 ;
int V_34 = V_375 ;
for ( V_35 = 0 ; V_35 < V_380 ; V_35 ++ ) {
V_178 = V_310 -> V_371 + V_35 ;
V_178 -> V_192 [ 0 ] . V_12 = NULL ;
V_178 -> V_192 [ 0 ] . F_254 = 0 ;
}
V_378 = V_310 -> V_381 ;
V_376 = V_214 ;
V_379 = V_378 ;
F_340 ( V_377 ) ;
memset ( V_374 , 0 , sizeof( V_374 ) ) ;
V_370 = 0 ;
while ( ( V_195 = F_329 ( V_378 , & V_377 ) ) >= 0 ) {
if ( F_215 ( V_378 , V_195 ) !=
F_215 ( V_378 , V_379 ) )
V_369 [ V_195 ] = V_376 ;
V_379 = V_195 ;
V_376 -- ;
if ( V_34 == V_344 )
F_334 ( V_310 , V_195 ) ;
else
V_374 [ V_370 ++ ] = V_195 ;
}
if ( V_34 == V_345 ) {
F_336 ( V_310 , V_370 ) ;
}
F_335 ( V_310 ) ;
}
static void F_341 ( T_9 * V_310 )
{
struct V_178 * V_178 ;
struct V_179 * V_180 ;
struct V_190 * V_134 ;
V_178 = & V_310 -> V_371 [ 0 ] ;
V_178 -> V_182 = V_180 = & V_178 -> V_382 ;
F_208 ( V_180 -> V_184 , V_185 ) ;
for ( V_134 = V_178 -> V_192 ; V_134 -> V_12 ; V_134 ++ )
V_180 -> V_193 [ V_134 - V_178 -> V_192 ] = F_342 ( V_134 ) ;
}
int F_343 ( int V_195 )
{
struct V_12 * V_12 ;
( void ) F_261 ( F_263 ( V_195 , V_294 ) ,
F_266 ( V_294 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_195 ;
}
static void F_338 ( void )
{
V_375 = V_345 ;
}
static void F_339 ( T_9 * V_310 )
{
int V_195 , V_378 ;
enum V_309 V_370 ;
struct V_178 * V_178 ;
V_378 = V_310 -> V_381 ;
V_178 = & V_310 -> V_371 [ 0 ] ;
V_370 = F_317 ( V_310 , V_178 , 0 ) ;
for ( V_195 = V_378 + 1 ; V_195 < V_368 ; V_195 ++ ) {
if ( ! F_344 ( V_195 ) )
continue;
V_370 = F_317 ( F_304 ( V_195 ) , V_178 , V_370 ) ;
}
for ( V_195 = 0 ; V_195 < V_378 ; V_195 ++ ) {
if ( ! F_344 ( V_195 ) )
continue;
V_370 = F_317 ( F_304 ( V_195 ) , V_178 , V_370 ) ;
}
V_178 -> V_192 [ V_370 ] . V_12 = NULL ;
V_178 -> V_192 [ V_370 ] . F_254 = 0 ;
}
static void F_341 ( T_9 * V_310 )
{
V_310 -> V_371 [ 0 ] . V_182 = NULL ;
}
static int F_345 ( void * V_357 )
{
int V_287 ;
int V_129 ;
T_9 * V_383 = V_357 ;
#ifdef V_209
memset ( V_369 , 0 , sizeof( V_369 ) ) ;
#endif
if ( V_383 && ! F_344 ( V_383 -> V_381 ) ) {
F_339 ( V_383 ) ;
F_341 ( V_383 ) ;
}
F_346 (nid) {
T_9 * V_310 = F_304 ( V_287 ) ;
F_339 ( V_310 ) ;
F_341 ( V_310 ) ;
}
F_347 (cpu) {
F_348 ( & F_349 ( V_384 , V_129 ) , 0 ) ;
#ifdef F_350
if ( F_351 ( V_129 ) )
F_352 ( V_129 , F_343 ( F_353 ( V_129 ) ) ) ;
#endif
}
return 0 ;
}
static T_12 void T_2
F_354 ( void )
{
F_345 ( NULL ) ;
F_355 () ;
F_356 () ;
}
void T_13 F_327 ( T_9 * V_310 , struct V_12 * V_12 )
{
F_338 () ;
if ( V_385 == V_386 ) {
F_354 () ;
} else {
#ifdef F_357
if ( V_12 )
F_358 ( V_12 ) ;
#endif
F_359 ( F_345 , V_310 , NULL ) ;
}
V_387 = F_297 () ;
if ( V_387 < ( V_93 * V_314 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_360 ( L_72
L_73 ,
V_214 ,
V_388 [ V_375 ] ,
V_7 ? L_74 : L_4 ,
V_387 ) ;
#ifdef V_209
F_360 ( L_75 , V_389 [ V_390 ] ) ;
#endif
}
static inline unsigned long F_361 ( unsigned long V_118 )
{
unsigned long V_99 = 1 ;
V_118 /= V_391 ;
while ( V_99 < V_118 )
V_99 <<= 1 ;
V_99 = F_72 ( V_99 , 4096UL ) ;
return F_362 ( V_99 , 4UL ) ;
}
static inline unsigned long F_361 ( unsigned long V_118 )
{
return 4096UL ;
}
static inline unsigned long F_363 ( unsigned long V_99 )
{
return F_364 ( ~ V_99 ) ;
}
static int F_365 ( unsigned long V_17 , unsigned long V_111 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 ++ ) {
if ( ! F_17 ( V_15 ) || F_366 ( F_135 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_367 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_111 , V_392 ;
struct V_5 * V_5 ;
unsigned long V_393 ;
int V_394 ;
int V_395 ;
V_17 = V_12 -> V_18 ;
V_111 = F_161 ( V_12 ) ;
V_17 = F_368 ( V_17 , V_93 ) ;
V_394 = F_368 ( F_312 ( V_12 ) , V_93 ) >>
V_61 ;
V_394 = F_72 ( 2 , V_394 ) ;
V_395 = V_12 -> V_396 ;
if ( V_394 == V_395 )
return;
V_12 -> V_396 = V_394 ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 += V_93 ) {
if ( ! F_162 ( V_15 ) )
continue;
V_5 = F_135 ( V_15 ) ;
if ( F_132 ( V_5 ) != F_15 ( V_12 ) )
continue;
V_393 = F_90 ( V_5 ) ;
if ( V_394 > 0 ) {
V_392 = F_72 ( V_15 + V_93 , V_111 ) ;
if ( F_365 ( V_15 , V_392 ) )
continue;
if ( V_393 == V_122 ) {
V_394 -- ;
continue;
}
if ( V_393 == V_140 ) {
F_6 ( V_5 ,
V_122 ) ;
F_134 ( V_12 , V_5 ,
V_122 ) ;
V_394 -- ;
continue;
}
} else if ( ! V_395 ) {
break;
}
if ( V_393 == V_122 ) {
F_6 ( V_5 , V_140 ) ;
F_134 ( V_12 , V_5 , V_140 ) ;
}
}
}
void T_8 F_369 ( unsigned long V_99 , int V_287 , unsigned long V_12 ,
unsigned long V_17 , enum V_397 V_398 )
{
struct V_5 * V_5 ;
unsigned long V_111 = V_17 + V_99 ;
unsigned long V_15 ;
struct V_12 * V_134 ;
if ( V_399 < V_111 - 1 )
V_399 = V_111 - 1 ;
V_134 = & F_304 ( V_287 ) -> V_198 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 ++ ) {
if ( V_398 == V_400 ) {
if ( ! F_370 ( V_15 ) )
continue;
if ( ! F_371 ( V_15 , V_287 ) )
continue;
}
V_5 = F_135 ( V_15 ) ;
F_372 ( V_5 , V_12 , V_287 , V_15 ) ;
F_373 ( V_5 , V_12 , V_287 , V_15 ) ;
F_374 ( V_5 ) ;
F_22 ( V_5 ) ;
F_81 ( V_5 ) ;
F_375 ( V_5 ) ;
if ( ( V_134 -> V_18 <= V_15 )
&& ( V_15 < F_161 ( V_134 ) )
&& ! ( V_15 & ( V_93 - 1 ) ) )
F_6 ( V_5 , V_140 ) ;
F_53 ( & V_5 -> V_53 ) ;
#ifdef F_376
if ( ! F_377 ( V_12 ) )
F_378 ( V_5 , F_379 ( V_15 << V_401 ) ) ;
#endif
}
}
static void T_8 F_380 ( struct V_12 * V_12 )
{
unsigned int V_34 , V_138 ;
F_165 (order, t) {
F_53 ( & V_12 -> V_62 [ V_34 ] . V_66 [ V_138 ] ) ;
V_12 -> V_62 [ V_34 ] . V_63 = 0 ;
}
}
static int F_381 ( struct V_12 * V_12 )
{
#ifdef F_382
int V_128 ;
V_128 = V_12 -> V_92 / 1024 ;
if ( V_128 * V_89 > 512 * 1024 )
V_128 = ( 512 * 1024 ) / V_89 ;
V_128 /= 4 ;
if ( V_128 < 1 )
V_128 = 1 ;
V_128 = F_383 ( V_128 + V_128 / 2 ) - 1 ;
return V_128 ;
#else
return 0 ;
#endif
}
static void F_384 ( struct V_73 * V_74 , unsigned long V_97 ,
unsigned long V_128 )
{
V_74 -> V_128 = 1 ;
F_37 () ;
V_74 -> V_97 = V_97 ;
F_37 () ;
V_74 -> V_128 = V_128 ;
}
static void F_385 ( struct V_130 * V_37 , unsigned long V_128 )
{
F_384 ( & V_37 -> V_74 , 6 * V_128 , F_362 ( 1UL , 1 * V_128 ) ) ;
}
static void F_386 ( struct V_130 * V_37 )
{
struct V_73 * V_74 ;
int V_6 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_74 = & V_37 -> V_74 ;
V_74 -> V_72 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_53 ( & V_74 -> V_82 [ V_6 ] ) ;
}
static void F_348 ( struct V_130 * V_37 , unsigned long V_128 )
{
F_386 ( V_37 ) ;
F_385 ( V_37 , V_128 ) ;
}
static void F_387 ( struct V_130 * V_37 ,
unsigned long V_97 )
{
unsigned long V_128 = F_362 ( 1UL , V_97 / 4 ) ;
if ( ( V_97 / 4 ) > ( V_401 * 8 ) )
V_128 = V_401 * 8 ;
F_384 ( & V_37 -> V_74 , V_97 , V_128 ) ;
}
static void F_388 ( struct V_12 * V_12 ,
struct V_130 * V_74 )
{
if ( V_402 )
F_387 ( V_74 ,
( V_12 -> V_92 /
V_402 ) ) ;
else
F_385 ( V_74 , F_381 ( V_12 ) ) ;
}
static void T_8 F_389 ( struct V_12 * V_12 , int V_129 )
{
struct V_130 * V_74 = F_148 ( V_12 -> V_132 , V_129 ) ;
F_386 ( V_74 ) ;
F_388 ( V_12 , V_74 ) ;
}
static void T_8 F_358 ( struct V_12 * V_12 )
{
int V_129 ;
V_12 -> V_132 = F_390 ( struct V_130 ) ;
F_347 (cpu)
F_389 ( V_12 , V_129 ) ;
}
void T_2 F_391 ( void )
{
struct V_12 * V_12 ;
F_150 (zone)
F_358 ( V_12 ) ;
}
static T_12 T_14
int F_392 ( struct V_12 * V_12 , unsigned long V_403 )
{
int V_35 ;
T_7 V_404 ;
V_12 -> F_361 =
F_361 ( V_403 ) ;
V_12 -> F_363 =
F_363 ( V_12 -> F_361 ) ;
V_404 = V_12 -> F_361
* sizeof( V_405 ) ;
if ( ! F_393 () ) {
V_12 -> V_406 = ( V_405 * )
F_394 (
V_404 , V_12 -> V_197 -> V_381 ) ;
} else {
V_12 -> V_406 = F_395 ( V_404 ) ;
}
if ( ! V_12 -> V_406 )
return - V_167 ;
for ( V_35 = 0 ; V_35 < V_12 -> F_361 ; ++ V_35 )
F_396 ( V_12 -> V_406 + V_35 ) ;
return 0 ;
}
static T_8 void F_397 ( struct V_12 * V_12 )
{
V_12 -> V_132 = & V_384 ;
if ( F_318 ( V_12 ) )
F_24 ( V_407 L_76 ,
V_12 -> V_20 , V_12 -> V_332 ,
F_381 ( V_12 ) ) ;
}
int T_8 F_398 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_99 ,
enum V_397 V_398 )
{
struct V_408 * V_310 = V_12 -> V_197 ;
int V_13 ;
V_13 = F_392 ( V_12 , V_99 ) ;
if ( V_13 )
return V_13 ;
V_310 -> V_340 = F_254 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_399 ( V_409 , L_77 ,
L_78 ,
V_310 -> V_381 ,
( unsigned long ) F_254 ( V_12 ) ,
V_18 , ( V_18 + V_99 ) ) ;
F_380 ( V_12 ) ;
return 0 ;
}
int T_8 F_400 ( unsigned long V_15 )
{
unsigned long V_17 , V_111 ;
int V_287 ;
static unsigned long T_15 V_410 , V_411 ;
static int T_15 V_412 ;
if ( V_410 <= V_15 && V_15 < V_411 )
return V_412 ;
V_287 = F_401 ( V_15 , & V_17 , & V_111 ) ;
if ( V_287 != - 1 ) {
V_410 = V_17 ;
V_411 = V_111 ;
V_412 = V_287 ;
}
return V_287 ;
}
int T_8 F_402 ( unsigned long V_15 )
{
int V_287 ;
V_287 = F_400 ( V_15 ) ;
if ( V_287 >= 0 )
return V_287 ;
return 0 ;
}
bool T_8 F_371 ( unsigned long V_15 , int V_195 )
{
int V_287 ;
V_287 = F_400 ( V_15 ) ;
if ( V_287 >= 0 && V_287 != V_195 )
return false ;
return true ;
}
void T_2 F_403 ( int V_287 , unsigned long V_413 )
{
unsigned long V_17 , V_111 ;
int V_35 , V_414 ;
F_404 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = F_72 ( V_17 , V_413 ) ;
V_111 = F_72 ( V_111 , V_413 ) ;
if ( V_17 < V_111 )
F_405 ( F_406 ( V_17 ) ,
( V_111 - V_17 ) << V_401 ,
V_414 ) ;
}
}
void T_2 F_407 ( int V_287 )
{
unsigned long V_17 , V_111 ;
int V_35 , V_414 ;
F_404 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_408 ( V_414 , V_17 , V_111 ) ;
}
void T_8 F_409 ( unsigned int V_287 ,
unsigned long * V_17 , unsigned long * V_111 )
{
unsigned long V_415 , V_416 ;
int V_35 ;
* V_17 = - 1UL ;
* V_111 = 0 ;
F_404 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = F_72 ( * V_17 , V_415 ) ;
* V_111 = F_362 ( * V_111 , V_416 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_410 ( void )
{
int V_417 ;
for ( V_417 = V_311 - 1 ; V_417 >= 0 ; V_417 -- ) {
if ( V_417 == V_418 )
continue;
if ( V_419 [ V_417 ] >
V_420 [ V_417 ] )
break;
}
F_40 ( V_417 == - 1 ) ;
V_421 = V_417 ;
}
static void T_8 F_411 ( int V_287 ,
unsigned long V_309 ,
unsigned long V_422 ,
unsigned long V_423 ,
unsigned long * V_18 ,
unsigned long * F_161 )
{
if ( V_424 [ V_287 ] ) {
if ( V_309 == V_418 ) {
* V_18 = V_424 [ V_287 ] ;
* F_161 = F_72 ( V_423 ,
V_419 [ V_421 ] ) ;
} else if ( * V_18 < V_424 [ V_287 ] &&
* F_161 > V_424 [ V_287 ] ) {
* F_161 = V_424 [ V_287 ] ;
} else if ( * V_18 >= V_424 [ V_287 ] )
* V_18 = * F_161 ;
}
}
static unsigned long T_8 F_412 ( int V_287 ,
unsigned long V_309 ,
unsigned long V_422 ,
unsigned long V_423 ,
unsigned long * V_425 )
{
unsigned long V_18 , F_161 ;
V_18 = V_420 [ V_309 ] ;
F_161 = V_419 [ V_309 ] ;
F_411 ( V_287 , V_309 ,
V_422 , V_423 ,
& V_18 , & F_161 ) ;
if ( F_161 < V_422 || V_18 > V_423 )
return 0 ;
F_161 = F_72 ( F_161 , V_423 ) ;
V_18 = F_362 ( V_18 , V_422 ) ;
return F_161 - V_18 ;
}
unsigned long T_8 F_413 ( int V_287 ,
unsigned long V_426 ,
unsigned long V_427 )
{
unsigned long V_428 = V_427 - V_426 ;
unsigned long V_17 , V_111 ;
int V_35 ;
F_404 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_414 ( V_17 , V_426 , V_427 ) ;
V_111 = F_414 ( V_111 , V_426 , V_427 ) ;
V_428 -= V_111 - V_17 ;
}
return V_428 ;
}
unsigned long T_2 F_415 ( unsigned long V_17 ,
unsigned long V_111 )
{
return F_413 ( V_368 , V_17 , V_111 ) ;
}
static unsigned long T_8 F_416 ( int V_287 ,
unsigned long V_309 ,
unsigned long V_422 ,
unsigned long V_423 ,
unsigned long * V_425 )
{
unsigned long V_429 = V_420 [ V_309 ] ;
unsigned long V_430 = V_419 [ V_309 ] ;
unsigned long V_18 , F_161 ;
V_18 = F_414 ( V_422 , V_429 , V_430 ) ;
F_161 = F_414 ( V_423 , V_429 , V_430 ) ;
F_411 ( V_287 , V_309 ,
V_422 , V_423 ,
& V_18 , & F_161 ) ;
return F_413 ( V_287 , V_18 , F_161 ) ;
}
static inline unsigned long T_8 F_412 ( int V_287 ,
unsigned long V_309 ,
unsigned long V_422 ,
unsigned long V_423 ,
unsigned long * V_431 )
{
return V_431 [ V_309 ] ;
}
static inline unsigned long T_8 F_416 ( int V_287 ,
unsigned long V_309 ,
unsigned long V_422 ,
unsigned long V_423 ,
unsigned long * V_432 )
{
if ( ! V_432 )
return 0 ;
return V_432 [ V_309 ] ;
}
static void T_8 F_417 ( struct V_408 * V_310 ,
unsigned long V_422 ,
unsigned long V_423 ,
unsigned long * V_431 ,
unsigned long * V_432 )
{
unsigned long V_433 , V_434 = 0 ;
enum V_309 V_35 ;
for ( V_35 = 0 ; V_35 < V_311 ; V_35 ++ )
V_434 += F_412 ( V_310 -> V_381 , V_35 ,
V_422 ,
V_423 ,
V_431 ) ;
V_310 -> V_435 = V_434 ;
V_433 = V_434 ;
for ( V_35 = 0 ; V_35 < V_311 ; V_35 ++ )
V_433 -=
F_416 ( V_310 -> V_381 , V_35 ,
V_422 , V_423 ,
V_432 ) ;
V_310 -> V_436 = V_433 ;
F_24 ( V_407 L_79 , V_310 -> V_381 ,
V_433 ) ;
}
static unsigned long T_2 F_418 ( unsigned long V_18 , unsigned long V_437 )
{
unsigned long V_438 ;
V_437 += V_18 & ( V_93 - 1 ) ;
V_438 = F_368 ( V_437 , V_93 ) ;
V_438 = V_438 >> V_61 ;
V_438 *= V_439 ;
V_438 = F_368 ( V_438 , 8 * sizeof( unsigned long ) ) ;
return V_438 / 8 ;
}
static void T_2 F_419 ( struct V_408 * V_310 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_437 )
{
unsigned long V_438 = F_418 ( V_18 , V_437 ) ;
V_12 -> V_440 = NULL ;
if ( V_438 )
V_12 -> V_440 =
F_394 ( V_438 ,
V_310 -> V_381 ) ;
}
static inline void F_419 ( struct V_408 * V_310 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_437 ) {}
void T_16 F_420 ( void )
{
unsigned int V_34 ;
if ( V_61 )
return;
if ( V_441 > V_401 )
V_34 = V_442 ;
else
V_34 = V_46 - 1 ;
V_61 = V_34 ;
}
void T_16 F_420 ( void )
{
}
static unsigned long T_16 F_421 ( unsigned long V_19 ,
unsigned long V_332 )
{
unsigned long V_118 = V_19 ;
if ( V_19 > V_332 + ( V_332 >> 4 ) &&
F_96 ( V_443 ) )
V_118 = V_332 ;
return F_288 ( V_118 * sizeof( struct V_5 ) ) >> V_401 ;
}
static void T_16 F_422 ( struct V_408 * V_310 ,
unsigned long V_422 , unsigned long V_423 ,
unsigned long * V_431 , unsigned long * V_432 )
{
enum V_309 V_370 ;
int V_287 = V_310 -> V_381 ;
unsigned long V_18 = V_310 -> V_422 ;
int V_13 ;
F_423 ( V_310 ) ;
#ifdef F_424
F_425 ( & V_310 -> V_444 ) ;
V_310 -> V_445 = 0 ;
V_310 -> V_446 = V_26 ;
#endif
F_396 ( & V_310 -> V_447 ) ;
F_396 ( & V_310 -> V_448 ) ;
F_426 ( V_310 ) ;
for ( V_370 = 0 ; V_370 < V_311 ; V_370 ++ ) {
struct V_12 * V_12 = V_310 -> V_198 + V_370 ;
unsigned long V_99 , V_449 , V_450 , V_451 ;
V_99 = F_412 ( V_287 , V_370 , V_422 ,
V_423 , V_431 ) ;
V_449 = V_450 = V_99 - F_416 ( V_287 , V_370 ,
V_422 ,
V_423 ,
V_432 ) ;
V_451 = F_421 ( V_99 , V_449 ) ;
if ( ! F_377 ( V_370 ) ) {
if ( V_450 >= V_451 ) {
V_450 -= V_451 ;
if ( V_451 )
F_24 ( V_407
L_80 ,
V_389 [ V_370 ] , V_451 ) ;
} else
F_24 ( V_346
L_81 ,
V_389 [ V_370 ] , V_451 , V_450 ) ;
}
if ( V_370 == 0 && V_450 > V_452 ) {
V_450 -= V_452 ;
F_24 ( V_407 L_82 ,
V_389 [ 0 ] , V_452 ) ;
}
if ( ! F_377 ( V_370 ) )
V_453 += V_450 ;
else if ( V_453 > V_451 * 2 )
V_453 -= V_451 ;
V_454 += V_450 ;
V_12 -> V_19 = V_99 ;
V_12 -> V_332 = V_449 ;
V_12 -> V_92 = F_377 ( V_370 ) ? V_449 : V_450 ;
#ifdef V_209
V_12 -> V_195 = V_287 ;
V_12 -> V_455 = ( V_450 * V_456 )
/ 100 ;
V_12 -> V_457 = ( V_450 * V_458 ) / 100 ;
#endif
V_12 -> V_20 = V_389 [ V_370 ] ;
F_425 ( & V_12 -> V_78 ) ;
F_425 ( & V_12 -> V_459 ) ;
F_427 ( V_12 ) ;
V_12 -> V_197 = V_310 ;
F_397 ( V_12 ) ;
F_217 ( V_12 , V_148 , V_12 -> V_92 ) ;
F_428 ( & V_12 -> V_460 ) ;
if ( ! V_99 )
continue;
F_420 () ;
F_419 ( V_310 , V_12 , V_18 , V_99 ) ;
V_13 = F_398 ( V_12 , V_18 ,
V_99 , V_400 ) ;
F_180 ( V_13 ) ;
F_429 ( V_99 , V_287 , V_370 , V_18 ) ;
V_18 += V_99 ;
}
}
static void T_14 F_430 ( struct V_408 * V_310 )
{
if ( ! V_310 -> V_435 )
return;
#ifdef F_431
if ( ! V_310 -> V_461 ) {
unsigned long V_99 , V_462 , V_291 ;
struct V_5 * V_463 ;
V_462 = V_310 -> V_422 & ~ ( V_95 - 1 ) ;
V_291 = F_432 ( V_310 ) ;
V_291 = F_433 ( V_291 , V_95 ) ;
V_99 = ( V_291 - V_462 ) * sizeof( struct V_5 ) ;
V_463 = F_434 ( V_310 -> V_381 , V_99 ) ;
if ( ! V_463 )
V_463 = F_394 ( V_99 ,
V_310 -> V_381 ) ;
V_310 -> V_461 = V_463 + ( V_310 -> V_422 - V_462 ) ;
}
#ifndef F_435
if ( V_310 == F_304 ( 0 ) ) {
V_464 = F_304 ( 0 ) -> V_461 ;
#ifdef F_436
if ( F_10 ( V_464 ) != V_310 -> V_422 )
V_464 -= ( V_310 -> V_422 - V_465 ) ;
#endif
}
#endif
#endif
}
void T_16 F_437 ( int V_287 , unsigned long * V_431 ,
unsigned long V_422 , unsigned long * V_432 )
{
T_9 * V_310 = F_304 ( V_287 ) ;
unsigned long V_17 = 0 ;
unsigned long V_111 = 0 ;
F_2 ( V_310 -> V_340 || V_310 -> V_169 ) ;
V_310 -> V_381 = V_287 ;
V_310 -> V_422 = V_422 ;
#ifdef F_436
F_409 ( V_287 , & V_17 , & V_111 ) ;
F_360 ( L_83 , V_287 ,
( V_466 ) V_17 << V_401 , ( ( V_466 ) V_111 << V_401 ) - 1 ) ;
#endif
F_417 ( V_310 , V_17 , V_111 ,
V_431 , V_432 ) ;
F_430 ( V_310 ) ;
#ifdef F_431
F_24 ( V_407 L_84 ,
V_287 , ( unsigned long ) V_310 ,
( unsigned long ) V_310 -> V_461 ) ;
#endif
F_422 ( V_310 , V_17 , V_111 ,
V_431 , V_432 ) ;
}
void T_2 F_438 ( void )
{
unsigned int V_195 ;
unsigned int V_467 = 0 ;
F_439 (node, node_possible_map)
V_467 = V_195 ;
V_468 = V_467 + 1 ;
}
unsigned long T_2 F_440 ( void )
{
unsigned long V_469 = 0 , V_470 = 0 ;
unsigned long V_462 , V_291 , V_471 ;
int V_412 = - 1 ;
int V_35 , V_287 ;
F_404 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_462 || V_412 < 0 || V_412 == V_287 ) {
V_412 = V_287 ;
V_470 = V_291 ;
continue;
}
V_471 = ~ ( ( 1 << F_441 ( V_462 ) ) - 1 ) ;
while ( V_471 && V_470 <= ( V_462 & ( V_471 << 1 ) ) )
V_471 <<= 1 ;
V_469 |= V_471 ;
}
return ~ V_469 + 1 ;
}
static unsigned long T_2 F_442 ( int V_287 )
{
unsigned long V_472 = V_473 ;
unsigned long V_17 ;
int V_35 ;
F_404 (i, nid, &start_pfn, NULL, NULL)
V_472 = F_72 ( V_472 , V_17 ) ;
if ( V_472 == V_473 ) {
F_24 ( V_346
L_85 , V_287 ) ;
return 0 ;
}
return V_472 ;
}
unsigned long T_2 F_443 ( void )
{
return F_442 ( V_368 ) ;
}
static unsigned long T_2 F_444 ( void )
{
unsigned long V_434 = 0 ;
unsigned long V_17 , V_111 ;
int V_35 , V_287 ;
F_404 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_118 = V_111 - V_17 ;
V_434 += V_118 ;
if ( V_118 )
F_445 ( V_287 , V_189 ) ;
}
return V_434 ;
}
static void T_2 F_446 ( void )
{
int V_35 , V_287 ;
unsigned long V_474 ;
unsigned long V_475 , V_476 ;
T_5 V_477 = V_188 [ V_189 ] ;
unsigned long V_434 = F_444 () ;
int V_478 = F_447 ( V_188 [ V_189 ] ) ;
struct V_479 * V_480 ;
F_410 () ;
if ( F_448 () ) {
F_449 (memory, r) {
if ( ! F_450 ( V_480 ) )
continue;
V_287 = V_480 -> V_287 ;
V_474 = F_451 ( V_480 -> V_481 ) ;
V_424 [ V_287 ] = V_424 [ V_287 ] ?
F_72 ( V_474 , V_424 [ V_287 ] ) :
V_474 ;
}
goto V_482;
}
if ( V_483 ) {
unsigned long V_484 ;
V_483 =
F_368 ( V_483 , V_95 ) ;
V_484 = V_434 - V_483 ;
V_485 = F_362 ( V_485 , V_484 ) ;
}
if ( ! V_485 )
goto V_27;
V_474 = V_420 [ V_421 ] ;
V_486:
V_475 = V_485 / V_478 ;
F_332 (nid, N_MEMORY) {
unsigned long V_17 , V_111 ;
if ( V_485 < V_475 )
V_475 = V_485 / V_478 ;
V_476 = V_475 ;
F_404 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_487 ;
V_17 = F_362 ( V_17 , V_424 [ V_287 ] ) ;
if ( V_17 >= V_111 )
continue;
if ( V_17 < V_474 ) {
unsigned long V_488 ;
V_488 = F_72 ( V_111 , V_474 )
- V_17 ;
V_476 -= F_72 ( V_488 ,
V_476 ) ;
V_485 -= F_72 ( V_488 ,
V_485 ) ;
if ( V_111 <= V_474 ) {
V_424 [ V_287 ] = V_111 ;
continue;
}
V_17 = V_474 ;
}
V_487 = V_111 - V_17 ;
if ( V_487 > V_476 )
V_487 = V_476 ;
V_424 [ V_287 ] = V_17 + V_487 ;
V_485 -= F_72 ( V_485 ,
V_487 ) ;
V_476 -= V_487 ;
if ( ! V_476 )
break;
}
}
V_478 -- ;
if ( V_478 && V_485 > V_478 )
goto V_486;
V_482:
for ( V_287 = 0 ; V_287 < V_368 ; V_287 ++ )
V_424 [ V_287 ] =
F_368 ( V_424 [ V_287 ] , V_95 ) ;
V_27:
V_188 [ V_189 ] = V_477 ;
}
static void F_452 ( T_9 * V_310 , int V_287 )
{
enum V_309 V_309 ;
if ( V_189 == V_489 )
return;
for ( V_309 = 0 ; V_309 <= V_418 - 1 ; V_309 ++ ) {
struct V_12 * V_12 = & V_310 -> V_198 [ V_309 ] ;
if ( F_318 ( V_12 ) ) {
F_445 ( V_287 , V_490 ) ;
if ( V_489 != V_490 &&
V_309 <= V_243 )
F_445 ( V_287 , V_489 ) ;
break;
}
}
}
void T_2 F_453 ( unsigned long * V_137 )
{
unsigned long V_17 , V_111 ;
int V_35 , V_287 ;
memset ( V_420 , 0 ,
sizeof( V_420 ) ) ;
memset ( V_419 , 0 ,
sizeof( V_419 ) ) ;
V_420 [ 0 ] = F_443 () ;
V_419 [ 0 ] = V_137 [ 0 ] ;
for ( V_35 = 1 ; V_35 < V_311 ; V_35 ++ ) {
if ( V_35 == V_418 )
continue;
V_420 [ V_35 ] =
V_419 [ V_35 - 1 ] ;
V_419 [ V_35 ] =
F_362 ( V_137 [ V_35 ] , V_420 [ V_35 ] ) ;
}
V_420 [ V_418 ] = 0 ;
V_419 [ V_418 ] = 0 ;
memset ( V_424 , 0 , sizeof( V_424 ) ) ;
F_446 () ;
F_360 ( L_86 ) ;
for ( V_35 = 0 ; V_35 < V_311 ; V_35 ++ ) {
if ( V_35 == V_418 )
continue;
F_360 ( L_87 , V_389 [ V_35 ] ) ;
if ( V_420 [ V_35 ] ==
V_419 [ V_35 ] )
F_454 ( L_88 ) ;
else
F_454 ( L_89 ,
( V_466 ) V_420 [ V_35 ]
<< V_401 ,
( ( V_466 ) V_419 [ V_35 ]
<< V_401 ) - 1 ) ;
}
F_360 ( L_90 ) ;
for ( V_35 = 0 ; V_35 < V_368 ; V_35 ++ ) {
if ( V_424 [ V_35 ] )
F_360 ( L_91 , V_35 ,
( V_466 ) V_424 [ V_35 ] << V_401 ) ;
}
F_360 ( L_92 ) ;
F_404 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_360 ( L_93 , V_287 ,
( V_466 ) V_17 << V_401 ,
( ( V_466 ) V_111 << V_401 ) - 1 ) ;
F_455 () ;
F_438 () ;
F_346 (nid) {
T_9 * V_310 = F_304 ( V_287 ) ;
F_437 ( V_287 , NULL ,
F_442 ( V_287 ) , NULL ) ;
if ( V_310 -> V_436 )
F_445 ( V_287 , V_189 ) ;
F_452 ( V_310 , V_287 ) ;
}
}
static int T_2 F_456 ( char * V_37 , unsigned long * V_491 )
{
unsigned long long V_492 ;
if ( ! V_37 )
return - V_42 ;
V_492 = F_457 ( V_37 , & V_37 ) ;
* V_491 = V_492 >> V_401 ;
F_2 ( ( V_492 >> V_401 ) > V_473 ) ;
return 0 ;
}
static int T_2 F_458 ( char * V_37 )
{
return F_456 ( V_37 , & V_485 ) ;
}
static int T_2 F_459 ( char * V_37 )
{
return F_456 ( V_37 , & V_483 ) ;
}
void F_121 ( struct V_5 * V_5 , long V_72 )
{
F_83 ( & V_493 ) ;
F_18 ( V_5 ) -> V_92 += V_72 ;
V_300 += V_72 ;
#ifdef F_306
if ( F_105 ( V_5 ) )
V_306 += V_72 ;
#endif
F_92 ( & V_493 ) ;
}
unsigned long F_460 ( void * V_462 , void * V_291 , int V_494 , char * V_341 )
{
void * V_373 ;
unsigned long V_118 = 0 ;
V_462 = ( void * ) F_288 ( ( unsigned long ) V_462 ) ;
V_291 = ( void * ) ( ( unsigned long ) V_291 & V_495 ) ;
for ( V_373 = V_462 ; V_373 < V_291 ; V_373 += V_89 , V_118 ++ ) {
if ( ( unsigned int ) V_494 <= 0xFF )
memset ( V_373 , V_494 , V_89 ) ;
F_461 ( F_178 ( V_373 ) ) ;
}
if ( V_118 && V_341 )
F_360 ( L_94 ,
V_341 , V_118 << ( V_401 - 10 ) , V_462 , V_291 ) ;
return V_118 ;
}
void F_462 ( struct V_5 * V_5 )
{
F_463 ( V_5 ) ;
V_300 ++ ;
F_18 ( V_5 ) -> V_92 ++ ;
V_306 ++ ;
}
void T_2 F_464 ( const char * V_152 )
{
unsigned long V_496 , V_497 , V_498 , V_499 , V_500 ;
unsigned long V_501 , V_502 ;
V_496 = F_465 () ;
V_497 = V_503 - V_504 ;
V_498 = V_505 - V_506 ;
V_499 = V_507 - V_508 ;
V_500 = V_509 - V_510 ;
V_502 = V_511 - V_512 ;
V_501 = V_513 - V_514 ;
#define F_466 ( V_462 , V_291 , V_99 , V_373 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_466 ( V_512 , V_511 , V_502 ,
V_514 , V_501 ) ;
F_466 ( V_504 , V_503 , V_497 , V_514 , V_501 ) ;
F_466 ( V_506 , V_505 , V_498 , V_512 , V_502 ) ;
F_466 ( V_504 , V_503 , V_497 , V_508 , V_499 ) ;
F_466 ( V_506 , V_505 , V_498 , V_508 , V_499 ) ;
#undef F_466
F_360 ( L_95
L_96
L_97
#ifdef F_306
L_98
#endif
L_99 ,
F_467 () << ( V_401 - 10 ) , V_496 << ( V_401 - 10 ) ,
V_497 >> 10 , V_498 >> 10 , V_499 >> 10 ,
( V_502 + V_501 ) >> 10 , V_500 >> 10 ,
( V_496 - V_300 - V_515 ) << ( V_401 - 10 ) ,
V_515 << ( V_401 - 10 ) ,
#ifdef F_306
V_306 << ( V_401 - 10 ) ,
#endif
V_152 ? L_100 : L_101 , V_152 ? V_152 : L_101 ) ;
}
void T_2 F_468 ( unsigned long V_516 )
{
V_452 = V_516 ;
}
void T_2 F_469 ( unsigned long * V_431 )
{
F_437 ( 0 , V_431 ,
F_470 ( V_517 ) >> V_401 , NULL ) ;
}
static int F_471 ( struct V_518 * V_383 ,
unsigned long V_519 , void * V_520 )
{
int V_129 = ( unsigned long ) V_520 ;
if ( V_519 == V_521 || V_519 == V_522 ) {
F_472 ( V_129 ) ;
F_149 ( V_129 ) ;
F_473 ( V_129 ) ;
F_474 ( V_129 ) ;
}
return V_523 ;
}
void T_2 F_475 ( void )
{
F_476 ( F_471 , 0 ) ;
}
static void F_477 ( void )
{
struct V_408 * V_310 ;
unsigned long V_524 = 0 ;
enum V_309 V_35 , V_370 ;
F_478 (pgdat) {
for ( V_35 = 0 ; V_35 < V_311 ; V_35 ++ ) {
struct V_12 * V_12 = V_310 -> V_198 + V_35 ;
long F_362 = 0 ;
for ( V_370 = V_35 ; V_370 < V_311 ; V_370 ++ ) {
if ( V_12 -> V_176 [ V_370 ] > F_362 )
F_362 = V_12 -> V_176 [ V_370 ] ;
}
F_362 += F_218 ( V_12 ) ;
if ( F_362 > V_12 -> V_92 )
F_362 = V_12 -> V_92 ;
V_524 += F_362 ;
V_12 -> V_525 = F_362 ;
}
}
V_525 = V_524 ;
V_526 = V_524 ;
}
static void F_479 ( void )
{
struct V_408 * V_310 ;
enum V_309 V_370 , V_527 ;
F_478 (pgdat) {
for ( V_370 = 0 ; V_370 < V_311 ; V_370 ++ ) {
struct V_12 * V_12 = V_310 -> V_198 + V_370 ;
unsigned long V_92 = V_12 -> V_92 ;
V_12 -> V_176 [ V_370 ] = 0 ;
V_527 = V_370 ;
while ( V_527 ) {
struct V_12 * V_528 ;
V_527 -- ;
if ( V_529 [ V_527 ] < 1 )
V_529 [ V_527 ] = 1 ;
V_528 = V_310 -> V_198 + V_527 ;
V_528 -> V_176 [ V_370 ] = V_92 /
V_529 [ V_527 ] ;
V_92 += V_528 -> V_92 ;
}
}
}
F_477 () ;
}
static void F_480 ( void )
{
unsigned long V_530 = V_531 >> ( V_401 - 10 ) ;
unsigned long V_532 = 0 ;
struct V_12 * V_12 ;
unsigned long V_52 ;
F_481 (zone) {
if ( ! F_482 ( V_12 ) )
V_532 += V_12 -> V_92 ;
}
F_481 (zone) {
V_466 V_316 ;
F_160 ( & V_12 -> V_78 , V_52 ) ;
V_316 = ( V_466 ) V_530 * V_12 -> V_92 ;
F_483 ( V_316 , V_532 ) ;
if ( F_482 ( V_12 ) ) {
unsigned long V_533 ;
V_533 = V_12 -> V_92 / 1024 ;
V_533 = F_414 ( V_533 , V_534 , 128UL ) ;
V_12 -> V_142 [ V_535 ] = V_533 ;
} else {
V_12 -> V_142 [ V_535 ] = V_316 ;
}
V_12 -> V_142 [ V_536 ] = F_312 ( V_12 ) + ( V_316 >> 2 ) ;
V_12 -> V_142 [ V_537 ] = F_312 ( V_12 ) + ( V_316 >> 1 ) ;
F_85 ( V_12 , V_148 ,
F_218 ( V_12 ) - F_181 ( V_12 ) -
F_186 ( & V_12 -> V_149 [ V_148 ] ) ) ;
F_367 ( V_12 ) ;
F_168 ( & V_12 -> V_78 , V_52 ) ;
}
F_477 () ;
}
void F_484 ( void )
{
F_325 ( & V_359 ) ;
F_480 () ;
F_328 ( & V_359 ) ;
}
static void T_8 F_485 ( struct V_12 * V_12 )
{
unsigned int V_538 , V_539 ;
V_538 = V_12 -> V_92 >> ( 30 - V_401 ) ;
if ( V_538 )
V_539 = F_486 ( 10 * V_538 ) ;
else
V_539 = 1 ;
V_12 -> V_540 = V_539 ;
}
static void T_8 F_487 ( void )
{
struct V_12 * V_12 ;
F_481 (zone)
F_485 ( V_12 ) ;
}
int T_8 F_488 ( void )
{
unsigned long V_541 ;
int V_542 ;
V_541 = F_296 () * ( V_89 >> 10 ) ;
V_542 = F_486 ( V_541 * 16 ) ;
if ( V_542 > V_543 ) {
V_531 = V_542 ;
if ( V_531 < 128 )
V_531 = 128 ;
if ( V_531 > 65536 )
V_531 = 65536 ;
} else {
F_231 ( L_102 ,
V_542 , V_543 ) ;
}
F_484 () ;
F_489 () ;
F_479 () ;
F_487 () ;
return 0 ;
}
int F_490 ( struct V_349 * V_350 , int V_351 ,
void T_10 * V_352 , T_7 * V_353 , T_11 * V_354 )
{
int V_544 ;
V_544 = F_491 ( V_350 , V_351 , V_352 , V_353 , V_354 ) ;
if ( V_544 )
return V_544 ;
if ( V_351 ) {
V_543 = V_531 ;
F_484 () ;
}
return 0 ;
}
int F_492 ( struct V_349 * V_350 , int V_351 ,
void T_10 * V_352 , T_7 * V_353 , T_11 * V_354 )
{
struct V_12 * V_12 ;
int V_544 ;
V_544 = F_491 ( V_350 , V_351 , V_352 , V_353 , V_354 ) ;
if ( V_544 )
return V_544 ;
F_481 (zone)
V_12 -> V_455 = ( V_12 -> V_92 *
V_456 ) / 100 ;
return 0 ;
}
int F_493 ( struct V_349 * V_350 , int V_351 ,
void T_10 * V_352 , T_7 * V_353 , T_11 * V_354 )
{
struct V_12 * V_12 ;
int V_544 ;
V_544 = F_491 ( V_350 , V_351 , V_352 , V_353 , V_354 ) ;
if ( V_544 )
return V_544 ;
F_481 (zone)
V_12 -> V_457 = ( V_12 -> V_92 *
V_458 ) / 100 ;
return 0 ;
}
int F_494 ( struct V_349 * V_350 , int V_351 ,
void T_10 * V_352 , T_7 * V_353 , T_11 * V_354 )
{
F_491 ( V_350 , V_351 , V_352 , V_353 , V_354 ) ;
F_479 () ;
return 0 ;
}
int F_495 ( struct V_349 * V_350 , int V_351 ,
void T_10 * V_352 , T_7 * V_353 , T_11 * V_354 )
{
struct V_12 * V_12 ;
int V_545 ;
int V_13 ;
F_325 ( & V_546 ) ;
V_545 = V_402 ;
V_13 = F_491 ( V_350 , V_351 , V_352 , V_353 , V_354 ) ;
if ( ! V_351 || V_13 < 0 )
goto V_27;
if ( V_402 &&
V_402 < V_547 ) {
V_402 = V_545 ;
V_13 = - V_42 ;
goto V_27;
}
if ( V_402 == V_545 )
goto V_27;
F_150 (zone) {
unsigned int V_129 ;
F_347 (cpu)
F_388 ( V_12 ,
F_148 ( V_12 -> V_132 , V_129 ) ) ;
}
V_27:
F_328 ( & V_546 ) ;
return V_13 ;
}
static int T_2 F_496 ( char * V_152 )
{
if ( ! V_152 )
return 0 ;
V_548 = F_497 ( V_152 , & V_152 , 0 ) ;
return 1 ;
}
void * T_2 F_498 ( const char * V_549 ,
unsigned long V_550 ,
unsigned long V_551 ,
int V_552 ,
int V_52 ,
unsigned int * V_553 ,
unsigned int * V_554 ,
unsigned long V_555 ,
unsigned long V_556 )
{
unsigned long long F_362 = V_556 ;
unsigned long V_557 , V_99 ;
void * V_350 = NULL ;
if ( ! V_551 ) {
V_551 = V_453 ;
if ( V_401 < 20 )
V_551 = F_499 ( V_551 , ( 1 << 20 ) / V_89 ) ;
if ( V_552 > V_401 )
V_551 >>= ( V_552 - V_401 ) ;
else
V_551 <<= ( V_401 - V_552 ) ;
if ( F_7 ( V_52 & V_558 ) ) {
F_2 ( ! ( V_52 & V_559 ) ) ;
if ( ! ( V_551 >> * V_553 ) ) {
V_551 = 1UL << * V_553 ;
F_180 ( ! V_551 ) ;
}
} else if ( F_7 ( ( V_551 * V_550 ) < V_89 ) )
V_551 = V_89 / V_550 ;
}
V_551 = F_500 ( V_551 ) ;
if ( F_362 == 0 ) {
F_362 = ( ( unsigned long long ) V_454 << V_401 ) >> 4 ;
F_483 ( F_362 , V_550 ) ;
}
F_362 = F_72 ( F_362 , 0x80000000ULL ) ;
if ( V_551 < V_555 )
V_551 = V_555 ;
if ( V_551 > F_362 )
V_551 = F_362 ;
V_557 = F_501 ( V_551 ) ;
do {
V_99 = V_550 << V_557 ;
if ( V_52 & V_559 )
V_350 = F_502 ( V_99 , 0 ) ;
else if ( V_548 )
V_350 = F_503 ( V_99 , V_560 , V_561 ) ;
else {
if ( F_291 ( V_99 ) < V_46 ) {
V_350 = F_290 ( V_99 , V_560 ) ;
F_504 ( V_350 , V_99 , 1 , V_560 ) ;
}
}
} while ( ! V_350 && V_99 > V_89 && -- V_557 );
if ( ! V_350 )
F_505 ( L_103 , V_549 ) ;
F_24 ( V_49 L_104 ,
V_549 ,
( 1UL << V_557 ) ,
F_501 ( V_99 ) - V_401 ,
V_99 ) ;
if ( V_553 )
* V_553 = V_557 ;
if ( V_554 )
* V_554 = ( 1 << V_557 ) - 1 ;
return V_350 ;
}
static inline unsigned long * F_506 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_443
return F_507 ( V_15 ) -> V_440 ;
#else
return V_12 -> V_440 ;
#endif
}
static inline int F_508 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_443
V_15 &= ( V_562 - 1 ) ;
return ( V_15 >> V_61 ) * V_439 ;
#else
V_15 = V_15 - F_509 ( V_12 -> V_18 , V_93 ) ;
return ( V_15 >> V_61 ) * V_439 ;
#endif
}
unsigned long F_510 ( struct V_5 * V_5 , unsigned long V_15 ,
unsigned long V_563 ,
unsigned long V_471 )
{
struct V_12 * V_12 ;
unsigned long * V_564 ;
unsigned long V_565 , V_566 ;
unsigned long V_567 ;
V_12 = F_18 ( V_5 ) ;
V_564 = F_506 ( V_12 , V_15 ) ;
V_565 = F_508 ( V_12 , V_15 ) ;
V_566 = V_565 / V_568 ;
V_565 &= ( V_568 - 1 ) ;
V_567 = V_564 [ V_566 ] ;
V_565 += V_563 ;
return ( V_567 >> ( V_568 - V_565 - 1 ) ) & V_471 ;
}
void F_511 ( struct V_5 * V_5 , unsigned long V_52 ,
unsigned long V_15 ,
unsigned long V_563 ,
unsigned long V_471 )
{
struct V_12 * V_12 ;
unsigned long * V_564 ;
unsigned long V_565 , V_566 ;
unsigned long V_569 , V_567 ;
F_225 ( V_439 != 4 ) ;
V_12 = F_18 ( V_5 ) ;
V_564 = F_506 ( V_12 , V_15 ) ;
V_565 = F_508 ( V_12 , V_15 ) ;
V_566 = V_565 / V_568 ;
V_565 &= ( V_568 - 1 ) ;
F_67 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
V_565 += V_563 ;
V_471 <<= ( V_568 - V_565 - 1 ) ;
V_52 <<= ( V_568 - V_565 - 1 ) ;
V_567 = F_146 ( V_564 [ V_566 ] ) ;
for (; ; ) {
V_569 = F_512 ( & V_564 [ V_566 ] , V_567 , ( V_567 & ~ V_471 ) | V_52 ) ;
if ( V_567 == V_569 )
break;
V_567 = V_569 ;
}
}
bool F_513 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_72 ,
bool V_570 )
{
unsigned long V_15 , V_571 , V_572 ;
int V_83 ;
if ( F_254 ( V_12 ) == V_418 )
return false ;
V_83 = F_90 ( V_5 ) ;
if ( V_83 == V_140 || F_139 ( V_83 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_572 = 0 , V_571 = 0 ; V_571 < V_93 ; V_571 ++ ) {
unsigned long V_573 = V_15 + V_571 ;
if ( ! F_17 ( V_573 ) )
continue;
V_5 = F_135 ( V_573 ) ;
if ( F_514 ( V_5 ) ) {
V_571 = F_499 ( V_571 + 1 , 1 << F_31 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_79 ( & V_5 -> V_69 ) ) {
if ( F_69 ( V_5 ) )
V_571 += ( 1 << F_65 ( V_5 ) ) - 1 ;
continue;
}
if ( V_570 && F_21 ( V_5 ) )
continue;
if ( ! F_515 ( V_5 ) )
V_572 ++ ;
if ( V_572 > V_72 )
return true ;
}
return false ;
}
bool F_516 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_344 ( F_132 ( V_5 ) ) )
return false ;
V_12 = F_18 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_513 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_517 ( unsigned long V_15 )
{
return V_15 & ~ ( F_518 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_519 ( unsigned long V_15 )
{
return F_433 ( V_15 , F_518 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_520 ( struct V_574 * V_575 ,
unsigned long V_462 , unsigned long V_291 )
{
unsigned long V_576 ;
unsigned long V_15 = V_462 ;
unsigned int V_577 = 0 ;
int V_13 = 0 ;
F_521 () ;
while ( V_15 < V_291 || ! F_86 ( & V_575 -> V_578 ) ) {
if ( F_522 ( V_30 ) ) {
V_13 = - V_579 ;
break;
}
if ( F_86 ( & V_575 -> V_578 ) ) {
V_575 -> V_580 = 0 ;
V_15 = F_523 ( V_575 , V_15 , V_291 ) ;
if ( ! V_15 ) {
V_13 = - V_579 ;
break;
}
V_577 = 0 ;
} else if ( ++ V_577 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_581 ;
break;
}
V_576 = F_524 ( V_575 -> V_12 ,
& V_575 -> V_578 ) ;
V_575 -> V_580 -= V_576 ;
V_13 = F_525 ( & V_575 -> V_578 , V_582 ,
NULL , 0 , V_575 -> V_160 , V_583 ) ;
}
if ( V_13 < 0 ) {
F_526 ( & V_575 -> V_578 ) ;
return V_13 ;
}
return 0 ;
}
int F_527 ( unsigned long V_462 , unsigned long V_291 ,
unsigned V_6 )
{
unsigned long V_584 , V_585 ;
int V_13 = 0 , V_34 ;
struct V_574 V_575 = {
. V_580 = 0 ,
. V_34 = - 1 ,
. V_12 = F_18 ( F_135 ( V_462 ) ) ,
. V_160 = V_586 ,
. V_587 = true ,
} ;
F_53 ( & V_575 . V_578 ) ;
V_13 = F_528 ( F_517 ( V_462 ) ,
F_519 ( V_291 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_520 ( & V_575 , V_462 , V_291 ) ;
if ( V_13 )
goto V_588;
F_529 () ;
F_153 ( V_575 . V_12 ) ;
V_34 = 0 ;
V_584 = V_462 ;
while ( ! F_69 ( F_135 ( V_584 ) ) ) {
if ( ++ V_34 >= V_46 ) {
V_13 = - V_581 ;
goto V_588;
}
V_584 &= ~ 0UL << V_34 ;
}
if ( F_530 ( V_584 , V_291 , false ) ) {
F_360 ( L_105 ,
V_589 , V_584 , V_291 ) ;
V_13 = - V_581 ;
goto V_588;
}
V_585 = F_531 ( & V_575 , V_584 , V_291 ) ;
if ( ! V_585 ) {
V_13 = - V_581 ;
goto V_588;
}
if ( V_462 != V_584 )
F_532 ( V_584 , V_462 - V_584 ) ;
if ( V_291 != V_585 )
F_532 ( V_291 , V_585 - V_291 ) ;
V_588:
F_533 ( F_517 ( V_462 ) ,
F_519 ( V_291 ) , V_6 ) ;
return V_13 ;
}
void F_532 ( unsigned long V_15 , unsigned V_36 )
{
unsigned int V_72 = 0 ;
for (; V_36 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_135 ( V_15 ) ;
V_72 += F_68 ( V_5 ) != 1 ;
F_534 ( V_5 ) ;
}
F_535 ( V_72 != 0 , L_106 , V_72 ) ;
}
void T_8 F_536 ( struct V_12 * V_12 )
{
unsigned V_129 ;
F_325 ( & V_546 ) ;
F_347 (cpu)
F_388 ( V_12 ,
F_148 ( V_12 -> V_132 , V_129 ) ) ;
F_328 ( & V_546 ) ;
}
void F_537 ( struct V_12 * V_12 )
{
unsigned long V_52 ;
int V_129 ;
struct V_130 * V_131 ;
F_111 ( V_52 ) ;
if ( V_12 -> V_132 != & V_384 ) {
F_154 (cpu) {
V_131 = F_148 ( V_12 -> V_132 , V_129 ) ;
F_538 ( V_12 , V_131 ) ;
}
F_539 ( V_12 -> V_132 ) ;
V_12 -> V_132 = & V_384 ;
}
F_114 ( V_52 ) ;
}
void
F_540 ( unsigned long V_17 , unsigned long V_111 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
unsigned int V_34 , V_35 ;
unsigned long V_15 ;
unsigned long V_52 ;
for ( V_15 = V_17 ; V_15 < V_111 ; V_15 ++ )
if ( F_162 ( V_15 ) )
break;
if ( V_15 == V_111 )
return;
V_12 = F_18 ( F_135 ( V_15 ) ) ;
F_160 ( & V_12 -> V_78 , V_52 ) ;
V_15 = V_17 ;
while ( V_15 < V_111 ) {
if ( ! F_162 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_135 ( V_15 ) ;
if ( F_7 ( ! F_69 ( V_5 ) && F_21 ( V_5 ) ) ) {
V_15 ++ ;
F_375 ( V_5 ) ;
continue;
}
F_180 ( F_68 ( V_5 ) ) ;
F_180 ( ! F_69 ( V_5 ) ) ;
V_34 = F_65 ( V_5 ) ;
#ifdef V_86
F_24 ( V_49 L_107 ,
V_15 , 1 << V_34 , V_111 ) ;
#endif
F_74 ( & V_5 -> V_53 ) ;
F_61 ( V_5 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_375 ( ( V_5 + V_35 ) ) ;
V_15 += ( 1 << V_34 ) ;
}
F_168 ( & V_12 -> V_78 , V_52 ) ;
}
bool F_541 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_52 ;
unsigned int V_34 ;
F_160 ( & V_12 -> V_78 , V_52 ) ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
struct V_5 * V_590 = V_5 - ( V_15 & ( ( 1 << V_34 ) - 1 ) ) ;
if ( F_69 ( V_590 ) && F_65 ( V_590 ) >= V_34 )
break;
}
F_168 ( & V_12 -> V_78 , V_52 ) ;
return V_34 < V_46 ;
}
