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
static int F_39 ( struct V_5 * V_5 , unsigned long V_34 )
{
int V_35 ;
int V_36 = 1 << V_34 ;
int V_39 = 0 ;
if ( F_7 ( F_31 ( V_5 ) != V_34 ) ) {
F_20 ( V_5 , L_4 , 0 ) ;
V_39 ++ ;
}
F_40 ( V_5 ) ;
for ( V_35 = 1 ; V_35 < V_36 ; V_35 ++ ) {
struct V_5 * V_37 = V_5 + V_35 ;
if ( F_7 ( ! F_41 ( V_37 ) ) ) {
F_20 ( V_5 , L_5 , 0 ) ;
V_39 ++ ;
} else if ( F_7 ( V_37 -> V_38 != V_5 ) ) {
F_20 ( V_5 , L_6 , 0 ) ;
V_39 ++ ;
}
F_42 ( V_37 ) ;
}
return V_39 ;
}
static inline void F_43 ( struct V_5 * V_5 , unsigned int V_34 ,
T_1 V_40 )
{
int V_35 ;
F_44 ( ( V_40 & V_41 ) && F_45 () ) ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_46 ( V_5 + V_35 ) ;
}
static int T_2 F_47 ( char * V_42 )
{
if ( ! V_42 )
return - V_43 ;
if ( strcmp ( V_42 , L_7 ) == 0 )
V_44 = true ;
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
V_45 = true ;
}
static int T_2 F_51 ( char * V_42 )
{
unsigned long V_46 ;
if ( F_52 ( V_42 , 10 , & V_46 ) < 0 || V_46 > V_47 / 2 ) {
F_24 ( V_48 L_8 ) ;
return 0 ;
}
V_49 = V_46 ;
F_24 ( V_50 L_9 , V_46 ) ;
return 0 ;
}
static inline void F_53 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 )
{
struct V_51 * V_51 ;
if ( ! F_54 () )
return;
V_51 = F_55 ( V_5 ) ;
F_56 ( V_52 , & V_51 -> V_53 ) ;
F_57 ( & V_5 -> V_54 ) ;
F_58 ( V_5 , V_34 ) ;
F_59 ( V_12 , - ( 1 << V_34 ) , V_6 ) ;
}
static inline void F_60 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 )
{
struct V_51 * V_51 ;
if ( ! F_54 () )
return;
V_51 = F_55 ( V_5 ) ;
F_61 ( V_52 , & V_51 -> V_53 ) ;
F_58 ( V_5 , 0 ) ;
if ( ! F_62 ( V_6 ) )
F_59 ( V_12 , ( 1 << V_34 ) , V_6 ) ;
}
static inline void F_53 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 ) {}
static inline void F_60 ( struct V_12 * V_12 , struct V_5 * V_5 ,
unsigned int V_34 , int V_6 ) {}
static inline void F_63 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_58 ( V_5 , V_34 ) ;
F_64 ( V_5 ) ;
}
static inline void F_65 ( struct V_5 * V_5 )
{
F_66 ( V_5 ) ;
F_58 ( V_5 , 0 ) ;
}
static inline int F_67 ( struct V_5 * V_5 , struct V_5 * V_55 ,
unsigned int V_34 )
{
if ( ! F_17 ( F_10 ( V_55 ) ) )
return 0 ;
if ( F_68 ( V_55 ) && F_69 ( V_55 ) == V_34 ) {
F_70 ( F_71 ( V_55 ) != 0 , V_55 ) ;
if ( F_72 ( V_5 ) != F_72 ( V_55 ) )
return 0 ;
return 1 ;
}
if ( F_73 ( V_55 ) && F_69 ( V_55 ) == V_34 ) {
F_70 ( F_71 ( V_55 ) != 0 , V_55 ) ;
if ( F_72 ( V_5 ) != F_72 ( V_55 ) )
return 0 ;
return 1 ;
}
return 0 ;
}
static inline void F_74 ( struct V_5 * V_5 ,
unsigned long V_15 ,
struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned long V_56 ;
unsigned long V_57 ;
unsigned long V_58 ( V_59 ) ;
struct V_5 * V_55 ;
int V_60 = V_47 ;
F_44 ( ! F_75 ( V_12 ) ) ;
if ( F_7 ( F_76 ( V_5 ) ) )
if ( F_7 ( F_39 ( V_5 , V_34 ) ) )
return;
F_44 ( V_6 == - 1 ) ;
if ( F_62 ( V_6 ) ) {
V_60 = F_77 ( V_47 , V_61 + 1 ) ;
} else {
F_59 ( V_12 , 1 << V_34 , V_6 ) ;
}
V_56 = V_15 & ( ( 1 << V_60 ) - 1 ) ;
F_70 ( V_56 & ( ( 1 << V_34 ) - 1 ) , V_5 ) ;
F_70 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
while ( V_34 < V_60 - 1 ) {
V_59 = F_78 ( V_56 , V_34 ) ;
V_55 = V_5 + ( V_59 - V_56 ) ;
if ( ! F_67 ( V_5 , V_55 , V_34 ) )
break;
if ( F_68 ( V_55 ) ) {
F_60 ( V_12 , V_55 , V_34 , V_6 ) ;
} else {
F_79 ( & V_55 -> V_54 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
F_65 ( V_55 ) ;
}
V_57 = V_59 & V_56 ;
V_5 = V_5 + ( V_57 - V_56 ) ;
V_56 = V_57 ;
V_34 ++ ;
}
F_63 ( V_5 , V_34 ) ;
if ( ( V_34 < V_47 - 2 ) && F_17 ( F_10 ( V_55 ) ) ) {
struct V_5 * V_64 , * V_65 ;
V_57 = V_59 & V_56 ;
V_64 = V_5 + ( V_57 - V_56 ) ;
V_59 = F_78 ( V_57 , V_34 + 1 ) ;
V_65 = V_64 + ( V_59 - V_57 ) ;
if ( F_67 ( V_64 , V_65 , V_34 + 1 ) ) {
F_80 ( & V_5 -> V_54 ,
& V_12 -> V_62 [ V_34 ] . V_66 [ V_6 ] ) ;
goto V_27;
}
}
F_81 ( & V_5 -> V_54 , & V_12 -> V_62 [ V_34 ] . V_66 [ V_6 ] ) ;
V_27:
V_12 -> V_62 [ V_34 ] . V_63 ++ ;
}
static inline int F_82 ( struct V_5 * V_5 )
{
const char * V_67 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_83 ( V_5 ) ) )
V_67 = L_10 ;
if ( F_7 ( V_5 -> V_68 != NULL ) )
V_67 = L_11 ;
if ( F_7 ( F_84 ( & V_5 -> V_69 ) != 0 ) )
V_67 = L_12 ;
if ( F_7 ( V_5 -> V_53 & V_70 ) ) {
V_67 = L_13 ;
V_22 = V_70 ;
}
#ifdef F_85
if ( F_7 ( V_5 -> V_71 ) )
V_67 = L_14 ;
#endif
if ( F_7 ( V_67 ) ) {
F_20 ( V_5 , V_67 , V_22 ) ;
return 1 ;
}
F_86 ( V_5 ) ;
if ( V_5 -> V_53 & V_72 )
V_5 -> V_53 &= ~ V_72 ;
return 0 ;
}
static void F_87 ( struct V_12 * V_12 , int V_73 ,
struct V_74 * V_75 )
{
int V_6 = 0 ;
int V_76 = 0 ;
int V_77 = V_73 ;
unsigned long V_78 ;
F_88 ( & V_12 -> V_79 ) ;
V_78 = F_89 ( V_12 , V_80 ) ;
if ( V_78 )
F_90 ( V_12 , V_80 , - V_78 ) ;
while ( V_77 ) {
struct V_5 * V_5 ;
struct V_81 * V_82 ;
do {
V_76 ++ ;
if ( ++ V_6 == V_8 )
V_6 = 0 ;
V_82 = & V_75 -> V_83 [ V_6 ] ;
} while ( F_91 ( V_82 ) );
if ( V_76 == V_8 )
V_76 = V_77 ;
do {
int V_84 ;
V_5 = F_92 ( V_82 -> V_85 , struct V_5 , V_54 ) ;
F_79 ( & V_5 -> V_54 ) ;
V_84 = F_93 ( V_5 ) ;
if ( F_7 ( F_94 ( V_12 ) ) )
V_84 = F_95 ( V_5 ) ;
F_74 ( V_5 , F_10 ( V_5 ) , V_12 , 0 , V_84 ) ;
F_96 ( V_5 , 0 , V_84 ) ;
} while ( -- V_77 && -- V_76 && ! F_91 ( V_82 ) );
}
F_97 ( & V_12 -> V_79 ) ;
}
static void F_98 ( struct V_12 * V_12 ,
struct V_5 * V_5 , unsigned long V_15 ,
unsigned int V_34 ,
int V_6 )
{
unsigned long V_78 ;
F_88 ( & V_12 -> V_79 ) ;
V_78 = F_89 ( V_12 , V_80 ) ;
if ( V_78 )
F_90 ( V_12 , V_80 , - V_78 ) ;
if ( F_7 ( F_94 ( V_12 ) ||
F_62 ( V_6 ) ) ) {
V_6 = F_99 ( V_5 , V_15 ) ;
}
F_74 ( V_5 , V_15 , V_12 , V_34 , V_6 ) ;
F_97 ( & V_12 -> V_79 ) ;
}
static bool F_100 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
int V_39 = 0 ;
F_70 ( F_41 ( V_5 ) , V_5 ) ;
F_70 ( F_101 ( V_5 ) && F_31 ( V_5 ) != V_34 , V_5 ) ;
F_102 ( V_5 , V_34 ) ;
F_103 ( V_5 , V_34 ) ;
if ( F_104 ( V_5 ) )
V_5 -> V_68 = NULL ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
V_39 += F_82 ( V_5 + V_35 ) ;
if ( V_39 )
return false ;
F_105 ( V_5 , V_34 ) ;
if ( ! F_106 ( V_5 ) ) {
F_107 ( F_108 ( V_5 ) ,
V_86 << V_34 ) ;
F_109 ( F_108 ( V_5 ) ,
V_86 << V_34 ) ;
}
F_110 ( V_5 , V_34 ) ;
F_111 ( V_5 , 1 << V_34 , 0 ) ;
return true ;
}
static void F_30 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_53 ;
int V_6 ;
unsigned long V_15 = F_10 ( V_5 ) ;
if ( ! F_100 ( V_5 , V_34 ) )
return;
V_6 = F_99 ( V_5 , V_15 ) ;
F_112 ( V_53 ) ;
F_113 ( V_87 , 1 << V_34 ) ;
F_114 ( V_5 , V_6 ) ;
F_98 ( F_18 ( V_5 ) , V_5 , V_15 , V_34 , V_6 ) ;
F_115 ( V_53 ) ;
}
void T_2 F_116 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned int V_36 = 1 << V_34 ;
struct V_5 * V_37 = V_5 ;
unsigned int V_88 ;
F_117 ( V_37 ) ;
for ( V_88 = 0 ; V_88 < ( V_36 - 1 ) ; V_88 ++ , V_37 ++ ) {
F_117 ( V_37 + 1 ) ;
F_118 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
}
F_118 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
F_18 ( V_5 ) -> V_89 += V_36 ;
F_119 ( V_5 ) ;
F_120 ( V_5 , V_34 ) ;
}
void T_2 F_121 ( struct V_5 * V_5 )
{
unsigned V_35 = V_90 ;
struct V_5 * V_37 = V_5 ;
do {
F_118 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
} while ( ++ V_37 , -- V_35 );
F_6 ( V_5 , V_91 ) ;
if ( V_61 >= V_47 ) {
V_35 = V_90 ;
V_37 = V_5 ;
do {
F_119 ( V_37 ) ;
F_120 ( V_37 , V_47 - 1 ) ;
V_37 += V_92 ;
} while ( V_35 -= V_92 );
} else {
F_119 ( V_5 ) ;
F_120 ( V_5 , V_61 ) ;
}
F_122 ( V_5 , V_90 ) ;
}
static inline void F_123 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_93 , int V_94 , struct V_62 * V_95 ,
int V_6 )
{
unsigned long V_96 = 1 << V_94 ;
while ( V_94 > V_93 ) {
V_95 -- ;
V_94 -- ;
V_96 >>= 1 ;
F_70 ( F_19 ( V_12 , & V_5 [ V_96 ] ) , & V_5 [ V_96 ] ) ;
if ( F_124 ( V_97 ) &&
F_54 () &&
V_94 < F_125 () ) {
F_53 ( V_12 , & V_5 [ V_96 ] , V_94 , V_6 ) ;
continue;
}
F_81 ( & V_5 [ V_96 ] . V_54 , & V_95 -> V_66 [ V_6 ] ) ;
V_95 -> V_63 ++ ;
F_63 ( & V_5 [ V_96 ] , V_94 ) ;
}
}
static inline int F_126 ( struct V_5 * V_5 )
{
const char * V_67 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_83 ( V_5 ) ) )
V_67 = L_10 ;
if ( F_7 ( V_5 -> V_68 != NULL ) )
V_67 = L_11 ;
if ( F_7 ( F_84 ( & V_5 -> V_69 ) != 0 ) )
V_67 = L_12 ;
if ( F_7 ( V_5 -> V_53 & V_72 ) ) {
V_67 = L_15 ;
V_22 = V_72 ;
}
#ifdef F_85
if ( F_7 ( V_5 -> V_71 ) )
V_67 = L_14 ;
#endif
if ( F_7 ( V_67 ) ) {
F_20 ( V_5 , V_67 , V_22 ) ;
return 1 ;
}
return 0 ;
}
static int F_127 ( struct V_5 * V_5 , unsigned int V_34 , T_1 V_40 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
struct V_5 * V_37 = V_5 + V_35 ;
if ( F_7 ( F_126 ( V_37 ) ) )
return 1 ;
}
F_58 ( V_5 , 0 ) ;
F_119 ( V_5 ) ;
F_128 ( V_5 , V_34 ) ;
F_111 ( V_5 , 1 << V_34 , 1 ) ;
if ( V_40 & V_98 )
F_43 ( V_5 , V_34 , V_40 ) ;
if ( V_34 && ( V_40 & V_99 ) )
F_32 ( V_5 , V_34 ) ;
F_129 ( V_5 , V_34 , V_40 ) ;
return 0 ;
}
static inline
struct V_5 * F_130 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned int V_100 ;
struct V_62 * V_95 ;
struct V_5 * V_5 ;
for ( V_100 = V_34 ; V_100 < V_47 ; ++ V_100 ) {
V_95 = & ( V_12 -> V_62 [ V_100 ] ) ;
if ( F_91 ( & V_95 -> V_66 [ V_6 ] ) )
continue;
V_5 = F_92 ( V_95 -> V_66 [ V_6 ] . V_101 ,
struct V_5 , V_54 ) ;
F_79 ( & V_5 -> V_54 ) ;
F_65 ( V_5 ) ;
V_95 -> V_63 -- ;
F_123 ( V_12 , V_5 , V_34 , V_100 , V_95 , V_6 ) ;
F_114 ( V_5 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_131 ( struct V_12 * V_12 ,
struct V_5 * V_102 , struct V_5 * V_103 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_34 ;
int V_104 = 0 ;
#ifndef F_132
F_44 ( F_18 ( V_102 ) != F_18 ( V_103 ) ) ;
#endif
for ( V_5 = V_102 ; V_5 <= V_103 ; ) {
F_70 ( F_133 ( V_5 ) != F_15 ( V_12 ) , V_5 ) ;
if ( ! F_17 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_73 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_34 = F_69 ( V_5 ) ;
F_134 ( & V_5 -> V_54 ,
& V_12 -> V_62 [ V_34 ] . V_66 [ V_6 ] ) ;
F_114 ( V_5 , V_6 ) ;
V_5 += 1 << V_34 ;
V_104 += 1 << V_34 ;
}
return V_104 ;
}
int F_135 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_17 , V_105 ;
struct V_5 * V_102 , * V_103 ;
V_17 = F_10 ( V_5 ) ;
V_17 = V_17 & ~ ( V_90 - 1 ) ;
V_102 = F_136 ( V_17 ) ;
V_103 = V_102 + V_90 - 1 ;
V_105 = V_17 + V_90 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_102 = V_5 ;
if ( ! F_12 ( V_12 , V_105 ) )
return 0 ;
return F_131 ( V_12 , V_102 , V_103 , V_6 ) ;
}
static void F_137 ( struct V_5 * V_106 ,
int V_107 , int V_6 )
{
int V_108 = 1 << ( V_107 - V_61 ) ;
while ( V_108 -- ) {
F_6 ( V_106 , V_6 ) ;
V_106 += V_90 ;
}
}
static int F_138 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_109 , int V_110 )
{
int V_100 = F_69 ( V_5 ) ;
if ( F_139 ( V_110 ) )
return V_110 ;
if ( V_100 >= V_61 ) {
F_137 ( V_5 , V_100 , V_109 ) ;
return V_109 ;
}
if ( V_100 >= V_61 / 2 ||
V_109 == V_111 ||
V_7 ) {
int V_112 ;
V_112 = F_135 ( V_12 , V_5 , V_109 ) ;
if ( V_112 >= ( 1 << ( V_61 - 1 ) ) ||
V_7 ) {
F_6 ( V_5 , V_109 ) ;
return V_109 ;
}
}
return V_110 ;
}
static inline struct V_5 *
F_140 ( struct V_12 * V_12 , unsigned int V_34 , int V_113 )
{
struct V_62 * V_95 ;
unsigned int V_100 ;
struct V_5 * V_5 ;
int V_6 , V_114 , V_35 ;
for ( V_100 = V_47 - 1 ;
V_100 >= V_34 && V_100 <= V_47 - 1 ;
-- V_100 ) {
for ( V_35 = 0 ; ; V_35 ++ ) {
V_6 = V_115 [ V_113 ] [ V_35 ] ;
if ( V_6 == V_116 )
break;
V_95 = & ( V_12 -> V_62 [ V_100 ] ) ;
if ( F_91 ( & V_95 -> V_66 [ V_6 ] ) )
continue;
V_5 = F_92 ( V_95 -> V_66 [ V_6 ] . V_101 ,
struct V_5 , V_54 ) ;
V_95 -> V_63 -- ;
V_114 = F_138 ( V_12 , V_5 ,
V_113 ,
V_6 ) ;
F_79 ( & V_5 -> V_54 ) ;
F_65 ( V_5 ) ;
F_123 ( V_12 , V_5 , V_34 , V_100 , V_95 ,
V_114 ) ;
F_114 ( V_5 , V_114 ) ;
F_141 ( V_5 , V_34 , V_100 ,
V_113 , V_6 , V_114 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_142 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
struct V_5 * V_5 ;
V_117:
V_5 = F_130 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_116 ) {
V_5 = F_140 ( V_12 , V_34 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_116 ;
goto V_117;
}
}
F_143 ( V_5 , V_34 , V_6 ) ;
return V_5 ;
}
static int F_144 ( struct V_12 * V_12 , unsigned int V_34 ,
unsigned long V_73 , struct V_81 * V_82 ,
int V_6 , bool V_118 )
{
int V_35 ;
F_88 ( & V_12 -> V_79 ) ;
for ( V_35 = 0 ; V_35 < V_73 ; ++ V_35 ) {
struct V_5 * V_5 = F_142 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_145 ( ! V_118 ) )
F_81 ( & V_5 -> V_54 , V_82 ) ;
else
F_80 ( & V_5 -> V_54 , V_82 ) ;
V_82 = & V_5 -> V_54 ;
if ( F_139 ( F_93 ( V_5 ) ) )
F_90 ( V_12 , V_119 ,
- ( 1 << V_34 ) ) ;
}
F_90 ( V_12 , V_120 , - ( V_35 << V_34 ) ) ;
F_97 ( & V_12 -> V_79 ) ;
return V_35 ;
}
void F_146 ( struct V_12 * V_12 , struct V_74 * V_75 )
{
unsigned long V_53 ;
int V_121 , V_122 ;
F_112 ( V_53 ) ;
V_122 = F_147 ( V_75 -> V_122 ) ;
V_121 = F_77 ( V_75 -> V_73 , V_122 ) ;
if ( V_121 > 0 ) {
F_87 ( V_12 , V_121 , V_75 ) ;
V_75 -> V_73 -= V_121 ;
}
F_115 ( V_53 ) ;
}
static void F_148 ( unsigned int V_123 , struct V_12 * V_12 )
{
unsigned long V_53 ;
struct V_124 * V_125 ;
struct V_74 * V_75 ;
F_112 ( V_53 ) ;
V_125 = F_149 ( V_12 -> V_126 , V_123 ) ;
V_75 = & V_125 -> V_75 ;
if ( V_75 -> V_73 ) {
F_87 ( V_12 , V_75 -> V_73 , V_75 ) ;
V_75 -> V_73 = 0 ;
}
F_115 ( V_53 ) ;
}
static void F_150 ( unsigned int V_123 )
{
struct V_12 * V_12 ;
F_151 (zone) {
F_148 ( V_123 , V_12 ) ;
}
}
void F_152 ( struct V_12 * V_12 )
{
int V_123 = F_153 () ;
if ( V_12 )
F_148 ( V_123 , V_12 ) ;
else
F_150 ( V_123 ) ;
}
void F_154 ( struct V_12 * V_12 )
{
int V_123 ;
static T_3 V_127 ;
F_155 (cpu) {
struct V_124 * V_75 ;
struct V_12 * V_128 ;
bool V_129 = false ;
if ( V_12 ) {
V_75 = F_149 ( V_12 -> V_126 , V_123 ) ;
if ( V_75 -> V_75 . V_73 )
V_129 = true ;
} else {
F_151 (z) {
V_75 = F_149 ( V_128 -> V_126 , V_123 ) ;
if ( V_75 -> V_75 . V_73 ) {
V_129 = true ;
break;
}
}
}
if ( V_129 )
F_156 ( V_123 , & V_127 ) ;
else
F_157 ( V_123 , & V_127 ) ;
}
F_158 ( & V_127 , ( V_130 ) F_152 ,
V_12 , 1 ) ;
}
void F_159 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_131 ;
unsigned long V_53 ;
unsigned int V_34 , V_132 ;
struct V_81 * V_133 ;
if ( F_160 ( V_12 ) )
return;
F_161 ( & V_12 -> V_79 , V_53 ) ;
V_131 = F_162 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_131 ; V_15 ++ )
if ( F_163 ( V_15 ) ) {
struct V_5 * V_5 = F_136 ( V_15 ) ;
if ( ! F_164 ( V_5 ) )
F_165 ( V_5 ) ;
}
F_166 (order, t) {
F_167 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_35 ;
V_15 = F_10 ( F_92 ( V_133 , struct V_5 , V_54 ) ) ;
for ( V_35 = 0 ; V_35 < ( 1UL << V_34 ) ; V_35 ++ )
F_168 ( F_136 ( V_15 + V_35 ) ) ;
}
}
F_169 ( & V_12 -> V_79 , V_53 ) ;
}
void F_170 ( struct V_5 * V_5 , bool V_118 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
struct V_74 * V_75 ;
unsigned long V_53 ;
unsigned long V_15 = F_10 ( V_5 ) ;
int V_6 ;
if ( ! F_100 ( V_5 , 0 ) )
return;
V_6 = F_99 ( V_5 , V_15 ) ;
F_114 ( V_5 , V_6 ) ;
F_112 ( V_53 ) ;
F_171 ( V_87 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_62 ( V_6 ) ) ) {
F_98 ( V_12 , V_5 , V_15 , 0 , V_6 ) ;
goto V_27;
}
V_6 = V_134 ;
}
V_75 = & F_172 ( V_12 -> V_126 ) -> V_75 ;
if ( ! V_118 )
F_81 ( & V_5 -> V_54 , & V_75 -> V_83 [ V_6 ] ) ;
else
F_80 ( & V_5 -> V_54 , & V_75 -> V_83 [ V_6 ] ) ;
V_75 -> V_73 ++ ;
if ( V_75 -> V_73 >= V_75 -> V_94 ) {
unsigned long V_122 = F_147 ( V_75 -> V_122 ) ;
F_87 ( V_12 , V_122 , V_75 ) ;
V_75 -> V_73 -= V_122 ;
}
V_27:
F_115 ( V_53 ) ;
}
void F_173 ( struct V_81 * V_82 , bool V_118 )
{
struct V_5 * V_5 , * V_101 ;
F_174 (page, next, list, lru) {
F_175 ( V_5 , V_118 ) ;
F_170 ( V_5 , V_118 ) ;
}
}
void F_176 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
F_70 ( F_76 ( V_5 ) , V_5 ) ;
F_70 ( ! F_71 ( V_5 ) , V_5 ) ;
#ifdef F_177
if ( F_178 ( V_5 ) )
F_176 ( F_179 ( V_5 [ 0 ] . V_135 ) , V_34 ) ;
#endif
F_129 ( V_5 , 0 , 0 ) ;
for ( V_35 = 1 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
F_119 ( V_5 + V_35 ) ;
F_129 ( V_5 + V_35 , 0 , 0 ) ;
}
}
int F_180 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_136 ;
struct V_12 * V_12 ;
int V_84 ;
F_181 ( ! F_73 ( V_5 ) ) ;
V_12 = F_18 ( V_5 ) ;
V_84 = F_95 ( V_5 ) ;
if ( ! F_62 ( V_84 ) ) {
V_136 = F_182 ( V_12 ) + ( 1 << V_34 ) ;
if ( ! F_183 ( V_12 , 0 , V_136 , 0 , 0 ) )
return 0 ;
F_59 ( V_12 , - ( 1UL << V_34 ) , V_84 ) ;
}
F_79 ( & V_5 -> V_54 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
F_65 ( V_5 ) ;
if ( V_34 >= V_61 - 1 ) {
struct V_5 * V_137 = V_5 + ( 1 << V_34 ) - 1 ;
for (; V_5 < V_137 ; V_5 += V_90 ) {
int V_84 = F_95 ( V_5 ) ;
if ( ! F_62 ( V_84 ) && ! F_139 ( V_84 ) )
F_6 ( V_5 ,
V_134 ) ;
}
}
F_129 ( V_5 , V_34 , 0 ) ;
return 1UL << V_34 ;
}
int F_184 ( struct V_5 * V_5 )
{
unsigned int V_34 ;
int V_36 ;
V_34 = F_69 ( V_5 ) ;
V_36 = F_180 ( V_5 , V_34 ) ;
if ( ! V_36 )
return 0 ;
F_119 ( V_5 ) ;
F_176 ( V_5 , V_34 ) ;
return V_36 ;
}
static inline
struct V_5 * F_185 ( struct V_12 * V_138 ,
struct V_12 * V_12 , unsigned int V_34 ,
T_1 V_40 , int V_6 )
{
unsigned long V_53 ;
struct V_5 * V_5 ;
bool V_118 = ( ( V_40 & V_139 ) != 0 ) ;
V_140:
if ( F_145 ( V_34 == 0 ) ) {
struct V_74 * V_75 ;
struct V_81 * V_82 ;
F_112 ( V_53 ) ;
V_75 = & F_172 ( V_12 -> V_126 ) -> V_75 ;
V_82 = & V_75 -> V_83 [ V_6 ] ;
if ( F_91 ( V_82 ) ) {
V_75 -> V_73 += F_144 ( V_12 , 0 ,
V_75 -> V_122 , V_82 ,
V_6 , V_118 ) ;
if ( F_7 ( F_91 ( V_82 ) ) )
goto V_141;
}
if ( V_118 )
V_5 = F_92 ( V_82 -> V_85 , struct V_5 , V_54 ) ;
else
V_5 = F_92 ( V_82 -> V_101 , struct V_5 , V_54 ) ;
F_79 ( & V_5 -> V_54 ) ;
V_75 -> V_73 -- ;
} else {
if ( F_7 ( V_40 & V_142 ) ) {
F_186 ( V_34 > 1 ) ;
}
F_161 ( & V_12 -> V_79 , V_53 ) ;
V_5 = F_142 ( V_12 , V_34 , V_6 ) ;
F_97 ( & V_12 -> V_79 ) ;
if ( ! V_5 )
goto V_141;
F_59 ( V_12 , - ( 1 << V_34 ) ,
F_93 ( V_5 ) ) ;
}
F_90 ( V_12 , V_143 , - ( 1 << V_34 ) ) ;
if ( F_187 ( & V_12 -> V_144 [ V_143 ] ) <= 0 &&
! F_188 ( V_145 , & V_12 -> V_53 ) )
F_189 ( V_145 , & V_12 -> V_53 ) ;
F_190 ( V_146 , V_12 , 1 << V_34 ) ;
F_191 ( V_138 , V_12 , V_40 ) ;
F_115 ( V_53 ) ;
F_70 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
if ( F_127 ( V_5 , V_34 , V_40 ) )
goto V_140;
return V_5 ;
V_141:
F_115 ( V_53 ) ;
return NULL ;
}
static int T_2 F_192 ( char * V_147 )
{
return F_193 ( & V_148 . V_149 , V_147 ) ;
}
static bool F_194 ( T_1 V_150 , unsigned int V_34 )
{
if ( V_34 < V_148 . V_151 )
return false ;
if ( V_150 & V_142 )
return false ;
if ( V_148 . V_152 && ( V_150 & V_41 ) )
return false ;
if ( V_148 . V_153 && ( V_150 & V_154 ) )
return false ;
return F_195 ( & V_148 . V_149 , 1 << V_34 ) ;
}
static int T_2 F_196 ( void )
{
T_4 V_155 = V_156 | V_157 | V_158 ;
struct V_159 * V_160 ;
V_160 = F_197 ( L_16 , NULL ,
& V_148 . V_149 ) ;
if ( F_198 ( V_160 ) )
return F_199 ( V_160 ) ;
if ( ! F_200 ( L_17 , V_155 , V_160 ,
& V_148 . V_153 ) )
goto V_161;
if ( ! F_200 ( L_18 , V_155 , V_160 ,
& V_148 . V_152 ) )
goto V_161;
if ( ! F_201 ( L_19 , V_155 , V_160 ,
& V_148 . V_151 ) )
goto V_161;
return 0 ;
V_161:
F_202 ( V_160 ) ;
return - V_162 ;
}
static inline bool F_194 ( T_1 V_150 , unsigned int V_34 )
{
return false ;
}
static bool F_203 ( struct V_12 * V_128 , unsigned int V_34 ,
unsigned long V_163 , int V_164 , int V_165 ,
long V_166 )
{
long F_77 = V_163 ;
int V_167 ;
long V_168 = 0 ;
V_166 -= ( 1 << V_34 ) - 1 ;
if ( V_165 & V_169 )
F_77 -= F_77 / 2 ;
if ( V_165 & V_170 )
F_77 -= F_77 / 4 ;
#ifdef F_204
if ( ! ( V_165 & V_171 ) )
V_168 = F_89 ( V_128 , V_119 ) ;
#endif
if ( V_166 - V_168 <= F_77 + V_128 -> V_172 [ V_164 ] )
return false ;
for ( V_167 = 0 ; V_167 < V_34 ; V_167 ++ ) {
V_166 -= V_128 -> V_62 [ V_167 ] . V_63 << V_167 ;
F_77 >>= 1 ;
if ( V_166 <= F_77 )
return false ;
}
return true ;
}
bool F_183 ( struct V_12 * V_128 , unsigned int V_34 , unsigned long V_163 ,
int V_164 , int V_165 )
{
return F_203 ( V_128 , V_34 , V_163 , V_164 , V_165 ,
F_89 ( V_128 , V_120 ) ) ;
}
bool F_205 ( struct V_12 * V_128 , unsigned int V_34 ,
unsigned long V_163 , int V_164 , int V_165 )
{
long V_166 = F_89 ( V_128 , V_120 ) ;
if ( V_128 -> V_173 && V_166 < V_128 -> V_173 )
V_166 = F_206 ( V_128 , V_120 ) ;
return F_203 ( V_128 , V_34 , V_163 , V_164 , V_165 ,
V_166 ) ;
}
static T_5 * F_207 ( struct V_174 * V_174 , int V_165 )
{
struct V_175 * V_176 ;
T_5 * V_177 ;
V_176 = V_174 -> V_178 ;
if ( ! V_176 )
return NULL ;
if ( F_208 ( V_26 , V_176 -> V_179 + V_29 ) ) {
F_209 ( V_176 -> V_180 , V_181 ) ;
V_176 -> V_179 = V_26 ;
}
V_177 = ! F_45 () && ( V_165 & V_182 ) ?
& V_183 :
& V_184 [ V_185 ] ;
return V_177 ;
}
static int F_210 ( struct V_174 * V_174 , struct V_186 * V_128 ,
T_5 * V_177 )
{
struct V_175 * V_176 ;
int V_35 ;
int V_187 ;
V_176 = V_174 -> V_178 ;
if ( ! V_176 )
return 1 ;
V_35 = V_128 - V_174 -> V_188 ;
V_187 = V_176 -> V_189 [ V_35 ] ;
return F_211 ( V_187 , * V_177 ) && ! F_188 ( V_35 , V_176 -> V_180 ) ;
}
static void F_212 ( struct V_174 * V_174 , struct V_186 * V_128 )
{
struct V_175 * V_176 ;
int V_35 ;
V_176 = V_174 -> V_178 ;
if ( ! V_176 )
return;
V_35 = V_128 - V_174 -> V_188 ;
F_189 ( V_35 , V_176 -> V_180 ) ;
}
static void F_213 ( struct V_174 * V_174 )
{
struct V_175 * V_176 ;
V_176 = V_174 -> V_178 ;
if ( ! V_176 )
return;
F_209 ( V_176 -> V_180 , V_181 ) ;
}
static bool F_214 ( struct V_12 * V_190 , struct V_12 * V_12 )
{
return V_190 -> V_191 == V_12 -> V_191 ;
}
static bool F_215 ( struct V_12 * V_190 , struct V_12 * V_12 )
{
return F_216 ( F_15 ( V_190 ) , F_15 ( V_12 ) ) <
V_192 ;
}
static T_5 * F_207 ( struct V_174 * V_174 , int V_165 )
{
return NULL ;
}
static int F_210 ( struct V_174 * V_174 , struct V_186 * V_128 ,
T_5 * V_177 )
{
return 1 ;
}
static void F_212 ( struct V_174 * V_174 , struct V_186 * V_128 )
{
}
static void F_213 ( struct V_174 * V_174 )
{
}
static bool F_214 ( struct V_12 * V_190 , struct V_12 * V_12 )
{
return true ;
}
static bool F_215 ( struct V_12 * V_190 , struct V_12 * V_12 )
{
return true ;
}
static void F_217 ( struct V_12 * V_138 )
{
struct V_12 * V_12 = V_138 -> V_193 -> V_194 ;
do {
F_218 ( V_12 , V_143 ,
F_219 ( V_12 ) - F_182 ( V_12 ) -
F_187 ( & V_12 -> V_144 [ V_143 ] ) ) ;
F_220 ( V_145 , & V_12 -> V_53 ) ;
} while ( V_12 ++ != V_138 );
}
static struct V_5 *
F_221 ( T_1 V_150 , T_5 * V_195 , unsigned int V_34 ,
struct V_174 * V_174 , int V_196 , int V_165 ,
struct V_12 * V_138 , int V_164 , int V_6 )
{
struct V_186 * V_128 ;
struct V_5 * V_5 = NULL ;
struct V_12 * V_12 ;
T_5 * V_177 = NULL ;
int V_197 = 0 ;
int V_198 = 0 ;
bool V_199 = ( V_165 & V_200 ) &&
( V_150 & V_201 ) ;
int V_202 = 0 ;
bool V_203 ;
V_204:
V_203 = false ;
F_222 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_163 ;
if ( F_124 ( V_205 ) && V_197 &&
! F_210 ( V_174 , V_128 , V_177 ) )
continue;
if ( F_223 () &&
( V_165 & V_182 ) &&
! F_224 ( V_12 , V_150 ) )
continue;
if ( V_165 & V_206 ) {
if ( ! F_214 ( V_138 , V_12 ) )
break;
if ( F_188 ( V_145 , & V_12 -> V_53 ) ) {
V_202 ++ ;
continue;
}
}
if ( V_199 && ! F_225 ( V_12 ) )
continue;
V_163 = V_12 -> V_136 [ V_165 & V_207 ] ;
if ( ! F_183 ( V_12 , V_34 , V_163 ,
V_164 , V_165 ) ) {
int V_13 ;
F_226 ( V_208 < V_209 ) ;
if ( V_165 & V_208 )
goto V_210;
if ( F_124 ( V_205 ) &&
! V_198 && V_211 > 1 ) {
V_177 = F_207 ( V_174 , V_165 ) ;
V_197 = 1 ;
V_198 = 1 ;
}
if ( V_212 == 0 ||
! F_215 ( V_138 , V_12 ) )
goto V_213;
if ( F_124 ( V_205 ) && V_197 &&
! F_210 ( V_174 , V_128 , V_177 ) )
continue;
V_13 = F_227 ( V_12 , V_150 , V_34 ) ;
switch ( V_13 ) {
case V_214 :
continue;
case V_215 :
continue;
default:
if ( F_183 ( V_12 , V_34 , V_163 ,
V_164 , V_165 ) )
goto V_210;
if ( ( ( V_165 & V_207 ) == V_216 ) ||
V_13 == V_217 )
goto V_213;
continue;
}
}
V_210:
V_5 = F_185 ( V_138 , V_12 , V_34 ,
V_150 , V_6 ) ;
if ( V_5 )
break;
V_213:
if ( F_124 ( V_205 ) && V_197 )
F_212 ( V_174 , V_128 ) ;
}
if ( V_5 ) {
V_5 -> V_218 = ! ! ( V_165 & V_208 ) ;
return V_5 ;
}
if ( V_165 & V_206 ) {
V_165 &= ~ V_206 ;
if ( V_202 ) {
V_203 = true ;
F_217 ( V_138 ) ;
}
if ( V_211 > 1 )
V_203 = true ;
}
if ( F_7 ( F_124 ( V_205 ) && V_197 ) ) {
V_197 = 0 ;
V_203 = true ;
}
if ( V_203 )
goto V_204;
return NULL ;
}
static inline bool F_228 ( void )
{
bool V_13 = false ;
#if V_219 > 8
V_13 = F_45 () ;
#endif
return V_13 ;
}
void F_229 ( T_1 V_150 , int V_34 , const char * V_220 , ... )
{
unsigned int V_221 = V_222 ;
if ( ( V_150 & V_223 ) || ! F_230 ( & V_224 ) ||
F_125 () > 0 )
return;
if ( ! ( V_150 & V_225 ) )
if ( F_231 ( V_226 ) ||
( V_30 -> V_53 & ( V_227 | V_228 ) ) )
V_221 &= ~ V_222 ;
if ( F_45 () || ! ( V_150 & V_154 ) )
V_221 &= ~ V_222 ;
if ( V_220 ) {
struct V_229 V_230 ;
T_6 args ;
va_start ( args , V_220 ) ;
V_230 . V_220 = V_220 ;
V_230 . V_231 = & args ;
F_232 ( L_20 , & V_230 ) ;
va_end ( args ) ;
}
F_232 ( L_21 ,
V_30 -> V_31 , V_34 , V_150 ) ;
F_27 () ;
if ( ! F_228 () )
F_233 ( V_221 ) ;
}
static inline int
F_234 ( T_1 V_150 , unsigned int V_34 ,
unsigned long V_232 ,
unsigned long V_233 )
{
if ( V_150 & V_234 )
return 0 ;
if ( V_150 & V_142 )
return 1 ;
if ( ! V_232 && F_5 () )
return 0 ;
if ( V_34 <= V_235 )
return 1 ;
if ( V_150 & V_236 && V_233 < ( 1 << V_34 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_235 ( T_1 V_150 , unsigned int V_34 ,
struct V_174 * V_174 , enum V_237 V_196 ,
T_5 * V_195 , struct V_12 * V_138 ,
int V_164 , int V_6 , unsigned long * V_232 )
{
struct V_5 * V_5 ;
* V_232 = 0 ;
if ( V_238 )
return NULL ;
if ( ! F_236 ( V_174 , V_150 ) ) {
* V_232 = 1 ;
F_237 ( 1 ) ;
return NULL ;
}
F_238 () ;
V_5 = F_221 ( V_150 | V_239 , V_195 ,
V_34 , V_174 , V_196 ,
V_240 | V_182 ,
V_138 , V_164 , V_6 ) ;
if ( V_5 )
goto V_27;
if ( ! ( V_150 & V_142 ) ) {
if ( V_30 -> V_53 & V_241 )
goto V_27;
if ( V_34 > V_235 )
goto V_27;
if ( V_196 < V_242 )
goto V_27;
if ( ! ( V_150 & V_243 ) )
goto V_27;
if ( V_150 & V_244 )
goto V_27;
}
F_239 ( V_174 , V_150 , V_34 , V_195 , false ) ;
* V_232 = 1 ;
V_27:
F_240 ( V_174 , V_150 ) ;
return V_5 ;
}
static struct V_5 *
F_241 ( T_1 V_150 , unsigned int V_34 ,
struct V_174 * V_174 , enum V_237 V_196 ,
T_5 * V_195 , int V_165 , struct V_12 * V_138 ,
int V_164 , int V_6 , enum V_245 V_155 ,
int * V_246 , bool * V_247 )
{
unsigned long V_248 ;
struct V_5 * V_5 ;
if ( ! V_34 )
return NULL ;
V_30 -> V_53 |= V_227 ;
V_248 = F_242 ( V_174 , V_34 , V_150 ,
V_195 , V_155 ,
V_246 ,
V_165 , V_164 ) ;
V_30 -> V_53 &= ~ V_227 ;
switch ( V_248 ) {
case V_249 :
* V_247 = true ;
case V_250 :
return NULL ;
default:
break;
}
F_243 ( V_251 ) ;
V_5 = F_221 ( V_150 , V_195 ,
V_34 , V_174 , V_196 ,
V_165 & ~ V_208 ,
V_138 , V_164 , V_6 ) ;
if ( V_5 ) {
struct V_12 * V_12 = F_18 ( V_5 ) ;
V_12 -> V_252 = false ;
F_244 ( V_12 , V_34 , true ) ;
F_243 ( V_253 ) ;
return V_5 ;
}
F_243 ( V_254 ) ;
F_245 () ;
return NULL ;
}
static inline struct V_5 *
F_241 ( T_1 V_150 , unsigned int V_34 ,
struct V_174 * V_174 , enum V_237 V_196 ,
T_5 * V_195 , int V_165 , struct V_12 * V_138 ,
int V_164 , int V_6 , enum V_245 V_155 ,
int * V_246 , bool * V_247 )
{
return NULL ;
}
static int
F_246 ( T_1 V_150 , unsigned int V_34 , struct V_174 * V_174 ,
T_5 * V_195 )
{
struct V_255 V_255 ;
int V_256 ;
F_245 () ;
F_247 () ;
V_30 -> V_53 |= V_227 ;
F_248 ( V_150 ) ;
V_255 . V_257 = 0 ;
V_30 -> V_255 = & V_255 ;
V_256 = F_249 ( V_174 , V_34 , V_150 , V_195 ) ;
V_30 -> V_255 = NULL ;
F_250 () ;
V_30 -> V_53 &= ~ V_227 ;
F_245 () ;
return V_256 ;
}
static inline struct V_5 *
F_251 ( T_1 V_150 , unsigned int V_34 ,
struct V_174 * V_174 , enum V_237 V_196 ,
T_5 * V_195 , int V_165 , struct V_12 * V_138 ,
int V_164 , int V_6 , unsigned long * V_232 )
{
struct V_5 * V_5 = NULL ;
bool V_258 = false ;
* V_232 = F_246 ( V_150 , V_34 , V_174 ,
V_195 ) ;
if ( F_7 ( ! ( * V_232 ) ) )
return NULL ;
if ( F_124 ( V_205 ) )
F_213 ( V_174 ) ;
V_259:
V_5 = F_221 ( V_150 , V_195 , V_34 ,
V_174 , V_196 ,
V_165 & ~ V_208 ,
V_138 , V_164 ,
V_6 ) ;
if ( ! V_5 && ! V_258 ) {
F_154 ( NULL ) ;
V_258 = true ;
goto V_259;
}
return V_5 ;
}
static inline struct V_5 *
F_252 ( T_1 V_150 , unsigned int V_34 ,
struct V_174 * V_174 , enum V_237 V_196 ,
T_5 * V_195 , struct V_12 * V_138 ,
int V_164 , int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_221 ( V_150 , V_195 , V_34 ,
V_174 , V_196 , V_208 ,
V_138 , V_164 , V_6 ) ;
if ( ! V_5 && V_150 & V_142 )
F_253 ( V_138 , V_260 , V_29 / 50 ) ;
} while ( ! V_5 && ( V_150 & V_142 ) );
return V_5 ;
}
static void F_254 ( unsigned int V_34 ,
struct V_174 * V_174 ,
enum V_237 V_196 ,
struct V_12 * V_138 ,
T_5 * V_195 )
{
struct V_186 * V_128 ;
struct V_12 * V_12 ;
F_222 (zone, z, zonelist,
high_zoneidx, nodemask)
F_255 ( V_12 , V_34 , F_256 ( V_138 ) ) ;
}
static inline int
F_257 ( T_1 V_150 )
{
int V_165 = V_216 | V_182 ;
const bool V_261 = ! ( V_150 & ( V_154 | V_262 ) ) ;
F_226 ( V_263 != ( V_264 T_1 ) V_169 ) ;
V_165 |= ( V_264 int ) ( V_150 & V_263 ) ;
if ( V_261 ) {
if ( ! ( V_150 & V_225 ) )
V_165 |= V_170 ;
V_165 &= ~ V_182 ;
} else if ( F_7 ( F_258 ( V_30 ) ) && ! F_45 () )
V_165 |= V_170 ;
if ( F_145 ( ! ( V_150 & V_225 ) ) ) {
if ( V_150 & V_265 )
V_165 |= V_208 ;
else if ( F_259 () && ( V_30 -> V_53 & V_227 ) )
V_165 |= V_208 ;
else if ( ! F_45 () &&
( ( V_30 -> V_53 & V_227 ) ||
F_7 ( F_231 ( V_226 ) ) ) )
V_165 |= V_208 ;
}
#ifdef F_204
if ( F_260 ( V_150 ) == V_134 )
V_165 |= V_171 ;
#endif
return V_165 ;
}
bool F_261 ( T_1 V_150 )
{
return ! ! ( F_257 ( V_150 ) & V_208 ) ;
}
static inline struct V_5 *
F_262 ( T_1 V_150 , unsigned int V_34 ,
struct V_174 * V_174 , enum V_237 V_196 ,
T_5 * V_195 , struct V_12 * V_138 ,
int V_164 , int V_6 )
{
const T_1 V_266 = V_150 & V_154 ;
struct V_5 * V_5 = NULL ;
int V_165 ;
unsigned long V_233 = 0 ;
unsigned long V_232 ;
enum V_245 V_267 = V_268 ;
bool V_247 = false ;
int V_246 = V_269 ;
if ( V_34 >= V_47 ) {
F_186 ( ! ( V_150 & V_223 ) ) ;
return NULL ;
}
if ( F_124 ( V_205 ) &&
( V_150 & V_270 ) == V_270 )
goto V_271;
V_259:
if ( ! ( V_150 & V_262 ) )
F_254 ( V_34 , V_174 , V_196 ,
V_138 , V_195 ) ;
V_165 = F_257 ( V_150 ) ;
if ( ! ( V_165 & V_182 ) && ! V_195 ) {
struct V_186 * V_272 ;
V_272 = F_263 ( V_174 , V_196 ,
NULL , & V_138 ) ;
V_164 = F_264 ( V_272 ) ;
}
V_5 = F_221 ( V_150 , V_195 , V_34 , V_174 ,
V_196 , V_165 & ~ V_208 ,
V_138 , V_164 , V_6 ) ;
if ( V_5 )
goto V_273;
if ( V_165 & V_208 ) {
V_174 = F_265 ( F_266 () , V_150 ) ;
V_5 = F_252 ( V_150 , V_34 ,
V_174 , V_196 , V_195 ,
V_138 , V_164 , V_6 ) ;
if ( V_5 ) {
goto V_273;
}
}
if ( ! V_266 ) {
F_186 ( V_150 & V_142 ) ;
goto V_271;
}
if ( V_30 -> V_53 & V_227 )
goto V_271;
if ( F_231 ( V_226 ) && ! ( V_150 & V_142 ) )
goto V_271;
V_5 = F_241 ( V_150 , V_34 , V_174 ,
V_196 , V_195 , V_165 ,
V_138 ,
V_164 , V_6 ,
V_267 , & V_246 ,
& V_247 ) ;
if ( V_5 )
goto V_273;
if ( ( V_150 & V_274 ) == V_274 ) {
if ( V_247 )
goto V_271;
if ( V_246 == V_275 )
goto V_271;
if ( V_246 == V_276
&& ! ( V_30 -> V_53 & V_277 ) )
goto V_271;
}
if ( ( V_150 & V_274 ) != V_274 ||
( V_30 -> V_53 & V_277 ) )
V_267 = V_278 ;
V_5 = F_251 ( V_150 , V_34 ,
V_174 , V_196 ,
V_195 ,
V_165 , V_138 ,
V_164 , V_6 ,
& V_232 ) ;
if ( V_5 )
goto V_273;
V_233 += V_232 ;
if ( F_234 ( V_150 , V_34 , V_232 ,
V_233 ) ) {
if ( ! V_232 ) {
V_5 = F_235 ( V_150 , V_34 , V_174 ,
V_196 , V_195 ,
V_138 , V_164 ,
V_6 , & V_232 ) ;
if ( V_5 )
goto V_273;
if ( ! V_232 )
goto V_271;
}
F_253 ( V_138 , V_260 , V_29 / 50 ) ;
goto V_259;
} else {
V_5 = F_241 ( V_150 , V_34 , V_174 ,
V_196 , V_195 , V_165 ,
V_138 ,
V_164 , V_6 ,
V_267 , & V_246 ,
& V_247 ) ;
if ( V_5 )
goto V_273;
}
V_271:
F_229 ( V_150 , V_34 , NULL ) ;
return V_5 ;
V_273:
if ( V_279 )
F_267 ( V_5 , V_34 , V_150 ) ;
return V_5 ;
}
struct V_5 *
F_268 ( T_1 V_150 , unsigned int V_34 ,
struct V_174 * V_174 , T_5 * V_195 )
{
enum V_237 V_196 = F_269 ( V_150 ) ;
struct V_12 * V_138 ;
struct V_186 * V_272 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_260 ( V_150 ) ;
unsigned int V_280 ;
int V_165 = V_200 | V_182 | V_206 ;
int V_164 ;
V_150 &= V_3 ;
F_270 ( V_150 ) ;
F_271 ( V_150 & V_154 ) ;
if ( F_194 ( V_150 , V_34 ) )
return NULL ;
if ( F_7 ( ! V_174 -> V_188 -> V_12 ) )
return NULL ;
if ( F_124 ( F_204 ) && V_6 == V_134 )
V_165 |= V_171 ;
V_281:
V_280 = F_272 () ;
V_272 = F_263 ( V_174 , V_196 ,
V_195 ? : & V_183 ,
& V_138 ) ;
if ( ! V_138 )
goto V_27;
V_164 = F_264 ( V_272 ) ;
V_5 = F_221 ( V_150 | V_239 , V_195 , V_34 ,
V_174 , V_196 , V_165 ,
V_138 , V_164 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_150 = F_273 ( V_150 ) ;
V_5 = F_262 ( V_150 , V_34 ,
V_174 , V_196 , V_195 ,
V_138 , V_164 , V_6 ) ;
}
F_274 ( V_5 , V_34 , V_150 , V_6 ) ;
V_27:
if ( F_7 ( ! V_5 && F_275 ( V_280 ) ) )
goto V_281;
return V_5 ;
}
unsigned long F_276 ( T_1 V_150 , unsigned int V_34 )
{
struct V_5 * V_5 ;
F_44 ( ( V_150 & V_41 ) != 0 ) ;
V_5 = F_277 ( V_150 , V_34 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_108 ( V_5 ) ;
}
unsigned long F_278 ( T_1 V_150 )
{
return F_276 ( V_150 | V_98 , 0 ) ;
}
void F_120 ( struct V_5 * V_5 , unsigned int V_34 )
{
if ( F_279 ( V_5 ) ) {
if ( V_34 == 0 )
F_170 ( V_5 , false ) ;
else
F_30 ( V_5 , V_34 ) ;
}
}
void V_166 ( unsigned long V_282 , unsigned int V_34 )
{
if ( V_282 != 0 ) {
F_44 ( ! F_280 ( ( void * ) V_282 ) ) ;
F_120 ( F_179 ( ( void * ) V_282 ) , V_34 ) ;
}
}
struct V_5 * F_281 ( T_1 V_150 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_71 * V_283 = NULL ;
if ( ! F_282 ( V_150 , & V_283 , V_34 ) )
return NULL ;
V_5 = F_277 ( V_150 , V_34 ) ;
F_283 ( V_5 , V_283 , V_34 ) ;
return V_5 ;
}
struct V_5 * F_284 ( int V_284 , T_1 V_150 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_71 * V_283 = NULL ;
if ( ! F_282 ( V_150 , & V_283 , V_34 ) )
return NULL ;
V_5 = F_285 ( V_284 , V_150 , V_34 ) ;
F_283 ( V_5 , V_283 , V_34 ) ;
return V_5 ;
}
void F_286 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_287 ( V_5 , V_34 ) ;
F_120 ( V_5 , V_34 ) ;
}
void F_288 ( unsigned long V_282 , unsigned int V_34 )
{
if ( V_282 != 0 ) {
F_44 ( ! F_280 ( ( void * ) V_282 ) ) ;
F_286 ( F_179 ( ( void * ) V_282 ) , V_34 ) ;
}
}
static void * F_289 ( unsigned long V_282 , unsigned V_34 , T_7 V_96 )
{
if ( V_282 ) {
unsigned long V_285 = V_282 + ( V_86 << V_34 ) ;
unsigned long V_286 = V_282 + F_290 ( V_96 ) ;
F_176 ( F_179 ( ( void * ) V_282 ) , V_34 ) ;
while ( V_286 < V_285 ) {
F_291 ( V_286 ) ;
V_286 += V_86 ;
}
}
return ( void * ) V_282 ;
}
void * F_292 ( T_7 V_96 , T_1 V_150 )
{
unsigned int V_34 = F_293 ( V_96 ) ;
unsigned long V_282 ;
V_282 = F_276 ( V_150 , V_34 ) ;
return F_289 ( V_282 , V_34 , V_96 ) ;
}
void * T_8 F_294 ( int V_284 , T_7 V_96 , T_1 V_150 )
{
unsigned V_34 = F_293 ( V_96 ) ;
struct V_5 * V_37 = F_285 ( V_284 , V_150 , V_34 ) ;
if ( ! V_37 )
return NULL ;
return F_289 ( ( unsigned long ) F_108 ( V_37 ) , V_34 , V_96 ) ;
}
void F_295 ( void * V_287 , T_7 V_96 )
{
unsigned long V_282 = ( unsigned long ) V_287 ;
unsigned long V_288 = V_282 + F_290 ( V_96 ) ;
while ( V_282 < V_288 ) {
F_291 ( V_282 ) ;
V_282 += V_86 ;
}
}
static unsigned long F_296 ( int V_289 )
{
struct V_186 * V_128 ;
struct V_12 * V_12 ;
unsigned long V_290 = 0 ;
struct V_174 * V_174 = F_265 ( F_266 () , V_291 ) ;
F_297 (zone, z, zonelist, offset) {
unsigned long V_96 = V_12 -> V_89 ;
unsigned long V_94 = F_219 ( V_12 ) ;
if ( V_96 > V_94 )
V_290 += V_96 - V_94 ;
}
return V_290 ;
}
unsigned long F_298 ( void )
{
return F_296 ( F_269 ( V_292 ) ) ;
}
unsigned long F_299 ( void )
{
return F_296 ( F_269 ( V_293 ) ) ;
}
static inline void F_300 ( struct V_12 * V_12 )
{
if ( F_124 ( V_205 ) )
F_24 ( L_22 , F_15 ( V_12 ) ) ;
}
void F_301 ( struct V_294 * V_295 )
{
V_295 -> V_296 = V_297 ;
V_295 -> V_298 = F_302 ( V_299 ) ;
V_295 -> V_300 = F_302 ( V_120 ) ;
V_295 -> V_301 = F_303 () ;
V_295 -> V_302 = V_303 ;
V_295 -> V_304 = F_304 () ;
V_295 -> V_305 = V_86 ;
}
void F_305 ( struct V_294 * V_295 , int V_284 )
{
int V_237 ;
unsigned long V_89 = 0 ;
T_9 * V_306 = F_306 ( V_284 ) ;
for ( V_237 = 0 ; V_237 < V_307 ; V_237 ++ )
V_89 += V_306 -> V_194 [ V_237 ] . V_89 ;
V_295 -> V_296 = V_89 ;
V_295 -> V_298 = F_307 ( V_284 , V_299 ) ;
V_295 -> V_300 = F_307 ( V_284 , V_120 ) ;
#ifdef F_308
V_295 -> V_302 = V_306 -> V_194 [ V_308 ] . V_89 ;
V_295 -> V_304 = F_89 ( & V_306 -> V_194 [ V_308 ] ,
V_120 ) ;
#else
V_295 -> V_302 = 0 ;
V_295 -> V_304 = 0 ;
#endif
V_295 -> V_305 = V_86 ;
}
bool F_309 ( unsigned int V_53 , int V_284 )
{
bool V_13 = false ;
unsigned int V_280 ;
if ( ! ( V_53 & V_222 ) )
goto V_27;
do {
V_280 = F_272 () ;
V_13 = ! F_211 ( V_284 , V_183 ) ;
} while ( F_275 ( V_280 ) );
V_27:
return V_13 ;
}
static void F_310 ( unsigned char type )
{
static const char V_309 [ V_310 ] = {
[ V_9 ] = 'U' ,
[ V_111 ] = 'E' ,
[ V_134 ] = 'M' ,
[ V_116 ] = 'R' ,
#ifdef F_204
[ V_91 ] = 'C' ,
#endif
#ifdef F_311
[ V_311 ] = 'I' ,
#endif
} ;
char V_312 [ V_310 + 1 ] ;
char * V_37 = V_312 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_310 ; V_35 ++ ) {
if ( type & ( 1 << V_35 ) )
* V_37 ++ = V_309 [ V_35 ] ;
}
* V_37 = '\0' ;
F_24 ( L_23 , V_312 ) ;
}
void F_312 ( unsigned int V_221 )
{
int V_123 ;
struct V_12 * V_12 ;
F_151 (zone) {
if ( F_309 ( V_221 , F_15 ( V_12 ) ) )
continue;
F_300 ( V_12 ) ;
F_24 ( L_24 , V_12 -> V_20 ) ;
F_155 (cpu) {
struct V_124 * V_126 ;
V_126 = F_149 ( V_12 -> V_126 , V_123 ) ;
F_24 ( L_25 ,
V_123 , V_126 -> V_75 . V_94 ,
V_126 -> V_75 . V_122 , V_126 -> V_75 . V_73 ) ;
}
}
F_24 ( L_26
L_27
L_28
L_29
L_30
L_31
L_32 ,
F_302 ( V_313 ) ,
F_302 ( V_314 ) ,
F_302 ( V_315 ) ,
F_302 ( V_316 ) ,
F_302 ( V_317 ) ,
F_302 ( V_318 ) ,
F_302 ( V_319 ) ,
F_302 ( V_320 ) ,
F_302 ( V_321 ) ,
F_302 ( V_322 ) ,
F_302 ( V_120 ) ,
F_302 ( V_323 ) ,
F_302 ( V_324 ) ,
F_302 ( V_325 ) ,
F_302 ( V_299 ) ,
F_302 ( V_326 ) ,
F_302 ( V_327 ) ,
F_302 ( V_119 ) ) ;
F_151 (zone) {
int V_35 ;
if ( F_309 ( V_221 , F_15 ( V_12 ) ) )
continue;
F_300 ( V_12 ) ;
F_24 ( L_33
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
L_62 ,
V_12 -> V_20 ,
F_313 ( F_89 ( V_12 , V_120 ) ) ,
F_313 ( F_314 ( V_12 ) ) ,
F_313 ( F_182 ( V_12 ) ) ,
F_313 ( F_219 ( V_12 ) ) ,
F_313 ( F_89 ( V_12 , V_313 ) ) ,
F_313 ( F_89 ( V_12 , V_314 ) ) ,
F_313 ( F_89 ( V_12 , V_316 ) ) ,
F_313 ( F_89 ( V_12 , V_317 ) ) ,
F_313 ( F_89 ( V_12 , V_319 ) ) ,
F_313 ( F_89 ( V_12 , V_315 ) ) ,
F_313 ( F_89 ( V_12 , V_318 ) ) ,
F_313 ( V_12 -> V_328 ) ,
F_313 ( V_12 -> V_89 ) ,
F_313 ( F_89 ( V_12 , V_329 ) ) ,
F_313 ( F_89 ( V_12 , V_320 ) ) ,
F_313 ( F_89 ( V_12 , V_321 ) ) ,
F_313 ( F_89 ( V_12 , V_325 ) ) ,
F_313 ( F_89 ( V_12 , V_299 ) ) ,
F_313 ( F_89 ( V_12 , V_323 ) ) ,
F_313 ( F_89 ( V_12 , V_324 ) ) ,
F_89 ( V_12 , V_330 ) *
V_331 / 1024 ,
F_313 ( F_89 ( V_12 , V_326 ) ) ,
F_313 ( F_89 ( V_12 , V_322 ) ) ,
F_313 ( F_89 ( V_12 , V_327 ) ) ,
F_313 ( F_89 ( V_12 , V_119 ) ) ,
F_313 ( F_89 ( V_12 , V_332 ) ) ,
F_313 ( F_89 ( V_12 , V_80 ) ) ,
( ! F_315 ( V_12 ) ? L_63 : L_64 )
) ;
F_24 ( L_65 ) ;
for ( V_35 = 0 ; V_35 < V_307 ; V_35 ++ )
F_24 ( L_66 , V_12 -> V_172 [ V_35 ] ) ;
F_24 ( L_62 ) ;
}
F_151 (zone) {
unsigned long V_333 [ V_47 ] , V_53 , V_34 , V_334 = 0 ;
unsigned char V_309 [ V_47 ] ;
if ( F_309 ( V_221 , F_15 ( V_12 ) ) )
continue;
F_300 ( V_12 ) ;
F_24 ( L_67 , V_12 -> V_20 ) ;
F_161 ( & V_12 -> V_79 , V_53 ) ;
for ( V_34 = 0 ; V_34 < V_47 ; V_34 ++ ) {
struct V_62 * V_95 = & V_12 -> V_62 [ V_34 ] ;
int type ;
V_333 [ V_34 ] = V_95 -> V_63 ;
V_334 += V_333 [ V_34 ] << V_34 ;
V_309 [ V_34 ] = 0 ;
for ( type = 0 ; type < V_310 ; type ++ ) {
if ( ! F_91 ( & V_95 -> V_66 [ type ] ) )
V_309 [ V_34 ] |= 1 << type ;
}
}
F_169 ( & V_12 -> V_79 , V_53 ) ;
for ( V_34 = 0 ; V_34 < V_47 ; V_34 ++ ) {
F_24 ( L_68 , V_333 [ V_34 ] , F_313 ( 1UL ) << V_34 ) ;
if ( V_333 [ V_34 ] )
F_310 ( V_309 [ V_34 ] ) ;
}
F_24 ( L_69 , F_313 ( V_334 ) ) ;
}
F_316 () ;
F_24 ( L_70 , F_302 ( V_335 ) ) ;
F_317 () ;
}
static void F_318 ( struct V_12 * V_12 , struct V_186 * V_186 )
{
V_186 -> V_12 = V_12 ;
V_186 -> F_256 = F_256 ( V_12 ) ;
}
static int F_319 ( T_9 * V_306 , struct V_174 * V_174 ,
int V_336 )
{
struct V_12 * V_12 ;
enum V_237 V_237 = V_307 ;
do {
V_237 -- ;
V_12 = V_306 -> V_194 + V_237 ;
if ( F_320 ( V_12 ) ) {
F_318 ( V_12 ,
& V_174 -> V_188 [ V_336 ++ ] ) ;
F_321 ( V_237 ) ;
}
} while ( V_237 );
return V_336 ;
}
static int F_322 ( char * V_337 )
{
if ( * V_337 == 'd' || * V_337 == 'D' ) {
V_338 = V_339 ;
} else if ( * V_337 == 'n' || * V_337 == 'N' ) {
V_338 = V_340 ;
} else if ( * V_337 == 'z' || * V_337 == 'Z' ) {
V_338 = V_341 ;
} else {
F_24 ( V_342
L_71
L_72 , V_337 ) ;
return - V_43 ;
}
return 0 ;
}
static T_2 int F_323 ( char * V_337 )
{
int V_13 ;
if ( ! V_337 )
return 0 ;
V_13 = F_322 ( V_337 ) ;
if ( V_13 == 0 )
F_324 ( V_343 , V_337 , V_344 ) ;
return V_13 ;
}
int F_325 ( struct V_345 * V_346 , int V_347 ,
void T_10 * V_348 , T_7 * V_349 ,
T_11 * V_350 )
{
char V_351 [ V_344 ] ;
int V_13 ;
static F_326 ( V_352 ) ;
F_327 ( & V_352 ) ;
if ( V_347 ) {
if ( strlen ( ( char * ) V_346 -> V_353 ) >= V_344 ) {
V_13 = - V_43 ;
goto V_27;
}
strcpy ( V_351 , ( char * ) V_346 -> V_353 ) ;
}
V_13 = F_328 ( V_346 , V_347 , V_348 , V_349 , V_350 ) ;
if ( V_13 )
goto V_27;
if ( V_347 ) {
int V_354 = V_338 ;
V_13 = F_322 ( ( char * ) V_346 -> V_353 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_346 -> V_353 , V_351 ,
V_344 ) ;
V_338 = V_354 ;
} else if ( V_354 != V_338 ) {
F_327 ( & V_355 ) ;
F_329 ( NULL , NULL ) ;
F_330 ( & V_355 ) ;
}
}
V_27:
F_330 ( & V_352 ) ;
return V_13 ;
}
static int F_331 ( int V_191 , T_5 * V_356 )
{
int V_187 , V_295 ;
int V_357 = V_358 ;
int V_359 = V_360 ;
const struct V_361 * V_312 = F_332 ( 0 ) ;
if ( ! F_211 ( V_191 , * V_356 ) ) {
F_333 ( V_191 , * V_356 ) ;
return V_191 ;
}
F_334 (n, N_MEMORY) {
if ( F_211 ( V_187 , * V_356 ) )
continue;
V_295 = F_216 ( V_191 , V_187 ) ;
V_295 += ( V_187 < V_191 ) ;
V_312 = F_332 ( V_187 ) ;
if ( ! F_335 ( V_312 ) )
V_295 += V_362 ;
V_295 *= ( V_363 * V_364 ) ;
V_295 += V_365 [ V_187 ] ;
if ( V_295 < V_357 ) {
V_357 = V_295 ;
V_359 = V_187 ;
}
}
if ( V_359 >= 0 )
F_333 ( V_359 , * V_356 ) ;
return V_359 ;
}
static void F_336 ( T_9 * V_306 , int V_191 )
{
int V_366 ;
struct V_174 * V_174 ;
V_174 = & V_306 -> V_367 [ 0 ] ;
for ( V_366 = 0 ; V_174 -> V_188 [ V_366 ] . V_12 != NULL ; V_366 ++ )
;
V_366 = F_319 ( F_306 ( V_191 ) , V_174 , V_366 ) ;
V_174 -> V_188 [ V_366 ] . V_12 = NULL ;
V_174 -> V_188 [ V_366 ] . F_256 = 0 ;
}
static void F_337 ( T_9 * V_306 )
{
int V_366 ;
struct V_174 * V_174 ;
V_174 = & V_306 -> V_367 [ 1 ] ;
V_366 = F_319 ( V_306 , V_174 , 0 ) ;
V_174 -> V_188 [ V_366 ] . V_12 = NULL ;
V_174 -> V_188 [ V_366 ] . F_256 = 0 ;
}
static void F_338 ( T_9 * V_306 , int V_368 )
{
int V_369 , V_366 , V_191 ;
int V_237 ;
struct V_12 * V_128 ;
struct V_174 * V_174 ;
V_174 = & V_306 -> V_367 [ 0 ] ;
V_369 = 0 ;
for ( V_237 = V_307 - 1 ; V_237 >= 0 ; V_237 -- ) {
for ( V_366 = 0 ; V_366 < V_368 ; V_366 ++ ) {
V_191 = V_370 [ V_366 ] ;
V_128 = & F_306 ( V_191 ) -> V_194 [ V_237 ] ;
if ( F_320 ( V_128 ) ) {
F_318 ( V_128 ,
& V_174 -> V_188 [ V_369 ++ ] ) ;
F_321 ( V_237 ) ;
}
}
}
V_174 -> V_188 [ V_369 ] . V_12 = NULL ;
V_174 -> V_188 [ V_369 ] . F_256 = 0 ;
}
static int F_339 ( void )
{
return V_340 ;
}
static int F_339 ( void )
{
return V_341 ;
}
static void F_340 ( void )
{
if ( V_338 == V_339 )
V_371 = F_339 () ;
else
V_371 = V_338 ;
}
static void F_341 ( T_9 * V_306 )
{
int V_366 , V_191 , V_372 ;
enum V_237 V_35 ;
T_5 V_373 ;
int V_374 , V_375 ;
struct V_174 * V_174 ;
int V_34 = V_371 ;
for ( V_35 = 0 ; V_35 < V_376 ; V_35 ++ ) {
V_174 = V_306 -> V_367 + V_35 ;
V_174 -> V_188 [ 0 ] . V_12 = NULL ;
V_174 -> V_188 [ 0 ] . F_256 = 0 ;
}
V_374 = V_306 -> V_377 ;
V_372 = V_211 ;
V_375 = V_374 ;
F_342 ( V_373 ) ;
memset ( V_370 , 0 , sizeof( V_370 ) ) ;
V_366 = 0 ;
while ( ( V_191 = F_331 ( V_374 , & V_373 ) ) >= 0 ) {
if ( F_216 ( V_374 , V_191 ) !=
F_216 ( V_374 , V_375 ) )
V_365 [ V_191 ] = V_372 ;
V_375 = V_191 ;
V_372 -- ;
if ( V_34 == V_340 )
F_336 ( V_306 , V_191 ) ;
else
V_370 [ V_366 ++ ] = V_191 ;
}
if ( V_34 == V_341 ) {
F_338 ( V_306 , V_366 ) ;
}
F_337 ( V_306 ) ;
}
static void F_343 ( T_9 * V_306 )
{
struct V_174 * V_174 ;
struct V_175 * V_176 ;
struct V_186 * V_128 ;
V_174 = & V_306 -> V_367 [ 0 ] ;
V_174 -> V_178 = V_176 = & V_174 -> V_378 ;
F_209 ( V_176 -> V_180 , V_181 ) ;
for ( V_128 = V_174 -> V_188 ; V_128 -> V_12 ; V_128 ++ )
V_176 -> V_189 [ V_128 - V_174 -> V_188 ] = F_344 ( V_128 ) ;
}
int F_345 ( int V_191 )
{
struct V_12 * V_12 ;
( void ) F_263 ( F_265 ( V_191 , V_291 ) ,
F_269 ( V_291 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_191 ;
}
static void F_340 ( void )
{
V_371 = V_341 ;
}
static void F_341 ( T_9 * V_306 )
{
int V_191 , V_374 ;
enum V_237 V_366 ;
struct V_174 * V_174 ;
V_374 = V_306 -> V_377 ;
V_174 = & V_306 -> V_367 [ 0 ] ;
V_366 = F_319 ( V_306 , V_174 , 0 ) ;
for ( V_191 = V_374 + 1 ; V_191 < V_364 ; V_191 ++ ) {
if ( ! F_346 ( V_191 ) )
continue;
V_366 = F_319 ( F_306 ( V_191 ) , V_174 , V_366 ) ;
}
for ( V_191 = 0 ; V_191 < V_374 ; V_191 ++ ) {
if ( ! F_346 ( V_191 ) )
continue;
V_366 = F_319 ( F_306 ( V_191 ) , V_174 , V_366 ) ;
}
V_174 -> V_188 [ V_366 ] . V_12 = NULL ;
V_174 -> V_188 [ V_366 ] . F_256 = 0 ;
}
static void F_343 ( T_9 * V_306 )
{
V_306 -> V_367 [ 0 ] . V_178 = NULL ;
}
static int F_347 ( void * V_353 )
{
int V_284 ;
int V_123 ;
T_9 * V_379 = V_353 ;
#ifdef V_205
memset ( V_365 , 0 , sizeof( V_365 ) ) ;
#endif
if ( V_379 && ! F_346 ( V_379 -> V_377 ) ) {
F_341 ( V_379 ) ;
F_343 ( V_379 ) ;
}
F_348 (nid) {
T_9 * V_306 = F_306 ( V_284 ) ;
F_341 ( V_306 ) ;
F_343 ( V_306 ) ;
}
F_349 (cpu) {
F_350 ( & F_351 ( V_380 , V_123 ) , 0 ) ;
#ifdef F_352
if ( F_353 ( V_123 ) )
F_354 ( V_123 , F_345 ( F_355 ( V_123 ) ) ) ;
#endif
}
return 0 ;
}
void T_12 F_329 ( T_9 * V_306 , struct V_12 * V_12 )
{
F_340 () ;
if ( V_381 == V_382 ) {
F_347 ( NULL ) ;
F_356 () ;
F_357 () ;
} else {
#ifdef F_358
if ( V_12 )
F_359 ( V_12 ) ;
#endif
F_360 ( F_347 , V_306 , NULL ) ;
}
V_383 = F_299 () ;
if ( V_383 < ( V_90 * V_310 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_361 ( L_73
L_74 ,
V_211 ,
V_384 [ V_371 ] ,
V_7 ? L_75 : L_7 ,
V_383 ) ;
#ifdef V_205
F_361 ( L_76 , V_385 [ V_386 ] ) ;
#endif
}
static inline unsigned long F_362 ( unsigned long V_112 )
{
unsigned long V_96 = 1 ;
V_112 /= V_387 ;
while ( V_96 < V_112 )
V_96 <<= 1 ;
V_96 = F_77 ( V_96 , 4096UL ) ;
return F_363 ( V_96 , 4UL ) ;
}
static inline unsigned long F_362 ( unsigned long V_112 )
{
return 4096UL ;
}
static inline unsigned long F_364 ( unsigned long V_96 )
{
return F_365 ( ~ V_96 ) ;
}
static int F_366 ( unsigned long V_17 , unsigned long V_105 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_105 ; V_15 ++ ) {
if ( ! F_17 ( V_15 ) || F_367 ( F_136 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_368 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_105 , V_388 ;
struct V_5 * V_5 ;
unsigned long V_389 ;
int V_390 ;
int V_391 ;
V_17 = V_12 -> V_18 ;
V_105 = F_162 ( V_12 ) ;
V_17 = F_369 ( V_17 , V_90 ) ;
V_390 = F_369 ( F_314 ( V_12 ) , V_90 ) >>
V_61 ;
V_390 = F_77 ( 2 , V_390 ) ;
V_391 = V_12 -> V_392 ;
if ( V_390 == V_391 )
return;
V_12 -> V_392 = V_390 ;
for ( V_15 = V_17 ; V_15 < V_105 ; V_15 += V_90 ) {
if ( ! F_163 ( V_15 ) )
continue;
V_5 = F_136 ( V_15 ) ;
if ( F_133 ( V_5 ) != F_15 ( V_12 ) )
continue;
V_389 = F_95 ( V_5 ) ;
if ( V_390 > 0 ) {
V_388 = F_77 ( V_15 + V_90 , V_105 ) ;
if ( F_366 ( V_15 , V_388 ) )
continue;
if ( V_389 == V_116 ) {
V_390 -- ;
continue;
}
if ( V_389 == V_134 ) {
F_6 ( V_5 ,
V_116 ) ;
F_135 ( V_12 , V_5 ,
V_116 ) ;
V_390 -- ;
continue;
}
} else if ( ! V_391 ) {
break;
}
if ( V_389 == V_116 ) {
F_6 ( V_5 , V_134 ) ;
F_135 ( V_12 , V_5 , V_134 ) ;
}
}
}
void T_8 F_370 ( unsigned long V_96 , int V_284 , unsigned long V_12 ,
unsigned long V_17 , enum V_393 V_394 )
{
struct V_5 * V_5 ;
unsigned long V_105 = V_17 + V_96 ;
unsigned long V_15 ;
struct V_12 * V_128 ;
if ( V_395 < V_105 - 1 )
V_395 = V_105 - 1 ;
V_128 = & F_306 ( V_284 ) -> V_194 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_105 ; V_15 ++ ) {
if ( V_394 == V_396 ) {
if ( ! F_371 ( V_15 ) )
continue;
if ( ! F_372 ( V_15 , V_284 ) )
continue;
}
V_5 = F_136 ( V_15 ) ;
F_373 ( V_5 , V_12 , V_284 , V_15 ) ;
F_374 ( V_5 , V_12 , V_284 , V_15 ) ;
F_375 ( V_5 ) ;
F_22 ( V_5 ) ;
F_86 ( V_5 ) ;
F_376 ( V_5 ) ;
if ( ( V_128 -> V_18 <= V_15 )
&& ( V_15 < F_162 ( V_128 ) )
&& ! ( V_15 & ( V_90 - 1 ) ) )
F_6 ( V_5 , V_134 ) ;
F_57 ( & V_5 -> V_54 ) ;
#ifdef F_377
if ( ! F_378 ( V_12 ) )
F_379 ( V_5 , F_380 ( V_15 << V_397 ) ) ;
#endif
}
}
static void T_8 F_381 ( struct V_12 * V_12 )
{
unsigned int V_34 , V_132 ;
F_166 (order, t) {
F_57 ( & V_12 -> V_62 [ V_34 ] . V_66 [ V_132 ] ) ;
V_12 -> V_62 [ V_34 ] . V_63 = 0 ;
}
}
static int F_382 ( struct V_12 * V_12 )
{
#ifdef F_383
int V_122 ;
V_122 = V_12 -> V_89 / 1024 ;
if ( V_122 * V_86 > 512 * 1024 )
V_122 = ( 512 * 1024 ) / V_86 ;
V_122 /= 4 ;
if ( V_122 < 1 )
V_122 = 1 ;
V_122 = F_384 ( V_122 + V_122 / 2 ) - 1 ;
return V_122 ;
#else
return 0 ;
#endif
}
static void F_385 ( struct V_74 * V_75 , unsigned long V_94 ,
unsigned long V_122 )
{
V_75 -> V_122 = 1 ;
F_37 () ;
V_75 -> V_94 = V_94 ;
F_37 () ;
V_75 -> V_122 = V_122 ;
}
static void F_386 ( struct V_124 * V_37 , unsigned long V_122 )
{
F_385 ( & V_37 -> V_75 , 6 * V_122 , F_363 ( 1UL , 1 * V_122 ) ) ;
}
static void F_387 ( struct V_124 * V_37 )
{
struct V_74 * V_75 ;
int V_6 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_75 = & V_37 -> V_75 ;
V_75 -> V_73 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_57 ( & V_75 -> V_83 [ V_6 ] ) ;
}
static void F_350 ( struct V_124 * V_37 , unsigned long V_122 )
{
F_387 ( V_37 ) ;
F_386 ( V_37 , V_122 ) ;
}
static void F_388 ( struct V_124 * V_37 ,
unsigned long V_94 )
{
unsigned long V_122 = F_363 ( 1UL , V_94 / 4 ) ;
if ( ( V_94 / 4 ) > ( V_397 * 8 ) )
V_122 = V_397 * 8 ;
F_385 ( & V_37 -> V_75 , V_94 , V_122 ) ;
}
static void F_389 ( struct V_12 * V_12 ,
struct V_124 * V_75 )
{
if ( V_398 )
F_388 ( V_75 ,
( V_12 -> V_89 /
V_398 ) ) ;
else
F_386 ( V_75 , F_382 ( V_12 ) ) ;
}
static void T_8 F_390 ( struct V_12 * V_12 , int V_123 )
{
struct V_124 * V_75 = F_149 ( V_12 -> V_126 , V_123 ) ;
F_387 ( V_75 ) ;
F_389 ( V_12 , V_75 ) ;
}
static void T_8 F_359 ( struct V_12 * V_12 )
{
int V_123 ;
V_12 -> V_126 = F_391 ( struct V_124 ) ;
F_349 (cpu)
F_390 ( V_12 , V_123 ) ;
}
void T_2 F_392 ( void )
{
struct V_12 * V_12 ;
F_151 (zone)
F_359 ( V_12 ) ;
}
static T_13 T_14
int F_393 ( struct V_12 * V_12 , unsigned long V_399 )
{
int V_35 ;
T_7 V_400 ;
V_12 -> F_362 =
F_362 ( V_399 ) ;
V_12 -> F_364 =
F_364 ( V_12 -> F_362 ) ;
V_400 = V_12 -> F_362
* sizeof( V_401 ) ;
if ( ! F_394 () ) {
V_12 -> V_402 = ( V_401 * )
F_395 (
V_400 , V_12 -> V_193 -> V_377 ) ;
} else {
V_12 -> V_402 = F_396 ( V_400 ) ;
}
if ( ! V_12 -> V_402 )
return - V_162 ;
for ( V_35 = 0 ; V_35 < V_12 -> F_362 ; ++ V_35 )
F_397 ( V_12 -> V_402 + V_35 ) ;
return 0 ;
}
static T_8 void F_398 ( struct V_12 * V_12 )
{
V_12 -> V_126 = & V_380 ;
if ( F_320 ( V_12 ) )
F_24 ( V_403 L_77 ,
V_12 -> V_20 , V_12 -> V_328 ,
F_382 ( V_12 ) ) ;
}
int T_8 F_399 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_96 ,
enum V_393 V_394 )
{
struct V_404 * V_306 = V_12 -> V_193 ;
int V_13 ;
V_13 = F_393 ( V_12 , V_96 ) ;
if ( V_13 )
return V_13 ;
V_306 -> V_336 = F_256 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_400 ( V_405 , L_78 ,
L_79 ,
V_306 -> V_377 ,
( unsigned long ) F_256 ( V_12 ) ,
V_18 , ( V_18 + V_96 ) ) ;
F_381 ( V_12 ) ;
return 0 ;
}
int T_8 F_401 ( unsigned long V_15 )
{
unsigned long V_17 , V_105 ;
int V_284 ;
static unsigned long T_15 V_406 , V_407 ;
static int T_15 V_408 ;
if ( V_406 <= V_15 && V_15 < V_407 )
return V_408 ;
V_284 = F_402 ( V_15 , & V_17 , & V_105 ) ;
if ( V_284 != - 1 ) {
V_406 = V_17 ;
V_407 = V_105 ;
V_408 = V_284 ;
}
return V_284 ;
}
int T_8 F_403 ( unsigned long V_15 )
{
int V_284 ;
V_284 = F_401 ( V_15 ) ;
if ( V_284 >= 0 )
return V_284 ;
return 0 ;
}
bool T_8 F_372 ( unsigned long V_15 , int V_191 )
{
int V_284 ;
V_284 = F_401 ( V_15 ) ;
if ( V_284 >= 0 && V_284 != V_191 )
return false ;
return true ;
}
void T_2 F_404 ( int V_284 , unsigned long V_409 )
{
unsigned long V_17 , V_105 ;
int V_35 , V_410 ;
F_405 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = F_77 ( V_17 , V_409 ) ;
V_105 = F_77 ( V_105 , V_409 ) ;
if ( V_17 < V_105 )
F_406 ( F_407 ( V_17 ) ,
( V_105 - V_17 ) << V_397 ,
V_410 ) ;
}
}
void T_2 F_408 ( int V_284 )
{
unsigned long V_17 , V_105 ;
int V_35 , V_410 ;
F_405 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_409 ( V_410 , V_17 , V_105 ) ;
}
void T_8 F_410 ( unsigned int V_284 ,
unsigned long * V_17 , unsigned long * V_105 )
{
unsigned long V_411 , V_412 ;
int V_35 ;
* V_17 = - 1UL ;
* V_105 = 0 ;
F_405 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = F_77 ( * V_17 , V_411 ) ;
* V_105 = F_363 ( * V_105 , V_412 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_411 ( void )
{
int V_413 ;
for ( V_413 = V_307 - 1 ; V_413 >= 0 ; V_413 -- ) {
if ( V_413 == V_414 )
continue;
if ( V_415 [ V_413 ] >
V_416 [ V_413 ] )
break;
}
F_44 ( V_413 == - 1 ) ;
V_417 = V_413 ;
}
static void T_8 F_412 ( int V_284 ,
unsigned long V_237 ,
unsigned long V_418 ,
unsigned long V_419 ,
unsigned long * V_18 ,
unsigned long * F_162 )
{
if ( V_420 [ V_284 ] ) {
if ( V_237 == V_414 ) {
* V_18 = V_420 [ V_284 ] ;
* F_162 = F_77 ( V_419 ,
V_415 [ V_417 ] ) ;
} else if ( * V_18 < V_420 [ V_284 ] &&
* F_162 > V_420 [ V_284 ] ) {
* F_162 = V_420 [ V_284 ] ;
} else if ( * V_18 >= V_420 [ V_284 ] )
* V_18 = * F_162 ;
}
}
static unsigned long T_8 F_413 ( int V_284 ,
unsigned long V_237 ,
unsigned long V_418 ,
unsigned long V_419 ,
unsigned long * V_421 )
{
unsigned long V_18 , F_162 ;
V_18 = V_416 [ V_237 ] ;
F_162 = V_415 [ V_237 ] ;
F_412 ( V_284 , V_237 ,
V_418 , V_419 ,
& V_18 , & F_162 ) ;
if ( F_162 < V_418 || V_18 > V_419 )
return 0 ;
F_162 = F_77 ( F_162 , V_419 ) ;
V_18 = F_363 ( V_18 , V_418 ) ;
return F_162 - V_18 ;
}
unsigned long T_8 F_414 ( int V_284 ,
unsigned long V_422 ,
unsigned long V_423 )
{
unsigned long V_424 = V_423 - V_422 ;
unsigned long V_17 , V_105 ;
int V_35 ;
F_405 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_415 ( V_17 , V_422 , V_423 ) ;
V_105 = F_415 ( V_105 , V_422 , V_423 ) ;
V_424 -= V_105 - V_17 ;
}
return V_424 ;
}
unsigned long T_2 F_416 ( unsigned long V_17 ,
unsigned long V_105 )
{
return F_414 ( V_364 , V_17 , V_105 ) ;
}
static unsigned long T_8 F_417 ( int V_284 ,
unsigned long V_237 ,
unsigned long V_418 ,
unsigned long V_419 ,
unsigned long * V_421 )
{
unsigned long V_425 = V_416 [ V_237 ] ;
unsigned long V_426 = V_415 [ V_237 ] ;
unsigned long V_18 , F_162 ;
V_18 = F_415 ( V_418 , V_425 , V_426 ) ;
F_162 = F_415 ( V_419 , V_425 , V_426 ) ;
F_412 ( V_284 , V_237 ,
V_418 , V_419 ,
& V_18 , & F_162 ) ;
return F_414 ( V_284 , V_18 , F_162 ) ;
}
static inline unsigned long T_8 F_413 ( int V_284 ,
unsigned long V_237 ,
unsigned long V_418 ,
unsigned long V_419 ,
unsigned long * V_427 )
{
return V_427 [ V_237 ] ;
}
static inline unsigned long T_8 F_417 ( int V_284 ,
unsigned long V_237 ,
unsigned long V_418 ,
unsigned long V_419 ,
unsigned long * V_428 )
{
if ( ! V_428 )
return 0 ;
return V_428 [ V_237 ] ;
}
static void T_8 F_418 ( struct V_404 * V_306 ,
unsigned long V_418 ,
unsigned long V_419 ,
unsigned long * V_427 ,
unsigned long * V_428 )
{
unsigned long V_429 , V_430 = 0 ;
enum V_237 V_35 ;
for ( V_35 = 0 ; V_35 < V_307 ; V_35 ++ )
V_430 += F_413 ( V_306 -> V_377 , V_35 ,
V_418 ,
V_419 ,
V_427 ) ;
V_306 -> V_431 = V_430 ;
V_429 = V_430 ;
for ( V_35 = 0 ; V_35 < V_307 ; V_35 ++ )
V_429 -=
F_417 ( V_306 -> V_377 , V_35 ,
V_418 , V_419 ,
V_428 ) ;
V_306 -> V_432 = V_429 ;
F_24 ( V_403 L_80 , V_306 -> V_377 ,
V_429 ) ;
}
static unsigned long T_2 F_419 ( unsigned long V_18 , unsigned long V_433 )
{
unsigned long V_434 ;
V_433 += V_18 & ( V_90 - 1 ) ;
V_434 = F_369 ( V_433 , V_90 ) ;
V_434 = V_434 >> V_61 ;
V_434 *= V_435 ;
V_434 = F_369 ( V_434 , 8 * sizeof( unsigned long ) ) ;
return V_434 / 8 ;
}
static void T_2 F_420 ( struct V_404 * V_306 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_433 )
{
unsigned long V_434 = F_419 ( V_18 , V_433 ) ;
V_12 -> V_436 = NULL ;
if ( V_434 )
V_12 -> V_436 =
F_395 ( V_434 ,
V_306 -> V_377 ) ;
}
static inline void F_420 ( struct V_404 * V_306 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_433 ) {}
void T_16 F_421 ( void )
{
unsigned int V_34 ;
if ( V_61 )
return;
if ( V_437 > V_397 )
V_34 = V_438 ;
else
V_34 = V_47 - 1 ;
V_61 = V_34 ;
}
void T_16 F_421 ( void )
{
}
static unsigned long T_16 F_422 ( unsigned long V_19 ,
unsigned long V_328 )
{
unsigned long V_112 = V_19 ;
if ( V_19 > V_328 + ( V_328 >> 4 ) &&
F_124 ( V_439 ) )
V_112 = V_328 ;
return F_290 ( V_112 * sizeof( struct V_5 ) ) >> V_397 ;
}
static void T_16 F_423 ( struct V_404 * V_306 ,
unsigned long V_418 , unsigned long V_419 ,
unsigned long * V_427 , unsigned long * V_428 )
{
enum V_237 V_366 ;
int V_284 = V_306 -> V_377 ;
unsigned long V_18 = V_306 -> V_418 ;
int V_13 ;
F_424 ( V_306 ) ;
#ifdef F_425
F_426 ( & V_306 -> V_440 ) ;
V_306 -> V_441 = 0 ;
V_306 -> V_442 = V_26 ;
#endif
F_397 ( & V_306 -> V_443 ) ;
F_397 ( & V_306 -> V_444 ) ;
F_427 ( V_306 ) ;
for ( V_366 = 0 ; V_366 < V_307 ; V_366 ++ ) {
struct V_12 * V_12 = V_306 -> V_194 + V_366 ;
unsigned long V_96 , V_445 , V_446 , V_447 ;
V_96 = F_413 ( V_284 , V_366 , V_418 ,
V_419 , V_427 ) ;
V_445 = V_446 = V_96 - F_417 ( V_284 , V_366 ,
V_418 ,
V_419 ,
V_428 ) ;
V_447 = F_422 ( V_96 , V_445 ) ;
if ( ! F_378 ( V_366 ) ) {
if ( V_446 >= V_447 ) {
V_446 -= V_447 ;
if ( V_447 )
F_24 ( V_403
L_81 ,
V_385 [ V_366 ] , V_447 ) ;
} else
F_24 ( V_342
L_82 ,
V_385 [ V_366 ] , V_447 , V_446 ) ;
}
if ( V_366 == 0 && V_446 > V_448 ) {
V_446 -= V_448 ;
F_24 ( V_403 L_83 ,
V_385 [ 0 ] , V_448 ) ;
}
if ( ! F_378 ( V_366 ) )
V_449 += V_446 ;
else if ( V_449 > V_447 * 2 )
V_449 -= V_447 ;
V_450 += V_446 ;
V_12 -> V_19 = V_96 ;
V_12 -> V_328 = V_445 ;
V_12 -> V_89 = F_378 ( V_366 ) ? V_445 : V_446 ;
#ifdef V_205
V_12 -> V_191 = V_284 ;
V_12 -> V_451 = ( V_446 * V_452 )
/ 100 ;
V_12 -> V_453 = ( V_446 * V_454 ) / 100 ;
#endif
V_12 -> V_20 = V_385 [ V_366 ] ;
F_426 ( & V_12 -> V_79 ) ;
F_426 ( & V_12 -> V_455 ) ;
F_428 ( V_12 ) ;
V_12 -> V_193 = V_306 ;
F_398 ( V_12 ) ;
F_218 ( V_12 , V_143 , V_12 -> V_89 ) ;
F_429 ( & V_12 -> V_456 ) ;
if ( ! V_96 )
continue;
F_421 () ;
F_420 ( V_306 , V_12 , V_18 , V_96 ) ;
V_13 = F_399 ( V_12 , V_18 ,
V_96 , V_396 ) ;
F_181 ( V_13 ) ;
F_430 ( V_96 , V_284 , V_366 , V_18 ) ;
V_18 += V_96 ;
}
}
static void T_14 F_431 ( struct V_404 * V_306 )
{
if ( ! V_306 -> V_431 )
return;
#ifdef F_432
if ( ! V_306 -> V_457 ) {
unsigned long V_96 , V_458 , V_288 ;
struct V_5 * V_459 ;
V_458 = V_306 -> V_418 & ~ ( V_92 - 1 ) ;
V_288 = F_433 ( V_306 ) ;
V_288 = F_434 ( V_288 , V_92 ) ;
V_96 = ( V_288 - V_458 ) * sizeof( struct V_5 ) ;
V_459 = F_435 ( V_306 -> V_377 , V_96 ) ;
if ( ! V_459 )
V_459 = F_395 ( V_96 ,
V_306 -> V_377 ) ;
V_306 -> V_457 = V_459 + ( V_306 -> V_418 - V_458 ) ;
}
#ifndef F_436
if ( V_306 == F_306 ( 0 ) ) {
V_460 = F_306 ( 0 ) -> V_457 ;
#ifdef F_437
if ( F_10 ( V_460 ) != V_306 -> V_418 )
V_460 -= ( V_306 -> V_418 - V_461 ) ;
#endif
}
#endif
#endif
}
void T_16 F_438 ( int V_284 , unsigned long * V_427 ,
unsigned long V_418 , unsigned long * V_428 )
{
T_9 * V_306 = F_306 ( V_284 ) ;
unsigned long V_17 = 0 ;
unsigned long V_105 = 0 ;
F_2 ( V_306 -> V_336 || V_306 -> V_164 ) ;
V_306 -> V_377 = V_284 ;
V_306 -> V_418 = V_418 ;
#ifdef F_437
F_410 ( V_284 , & V_17 , & V_105 ) ;
F_24 ( V_50 L_84 , V_284 ,
( V_462 ) V_17 << V_397 , ( V_462 ) ( V_105 << V_397 ) - 1 ) ;
#endif
F_418 ( V_306 , V_17 , V_105 ,
V_427 , V_428 ) ;
F_431 ( V_306 ) ;
#ifdef F_432
F_24 ( V_403 L_85 ,
V_284 , ( unsigned long ) V_306 ,
( unsigned long ) V_306 -> V_457 ) ;
#endif
F_423 ( V_306 , V_17 , V_105 ,
V_427 , V_428 ) ;
}
void T_2 F_439 ( void )
{
unsigned int V_191 ;
unsigned int V_463 = 0 ;
F_440 (node, node_possible_map)
V_463 = V_191 ;
V_464 = V_463 + 1 ;
}
unsigned long T_2 F_441 ( void )
{
unsigned long V_465 = 0 , V_466 = 0 ;
unsigned long V_458 , V_288 , V_467 ;
int V_408 = - 1 ;
int V_35 , V_284 ;
F_405 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_458 || V_408 < 0 || V_408 == V_284 ) {
V_408 = V_284 ;
V_466 = V_288 ;
continue;
}
V_467 = ~ ( ( 1 << F_442 ( V_458 ) ) - 1 ) ;
while ( V_467 && V_466 <= ( V_458 & ( V_467 << 1 ) ) )
V_467 <<= 1 ;
V_465 |= V_467 ;
}
return ~ V_465 + 1 ;
}
static unsigned long T_2 F_443 ( int V_284 )
{
unsigned long V_468 = V_469 ;
unsigned long V_17 ;
int V_35 ;
F_405 (i, nid, &start_pfn, NULL, NULL)
V_468 = F_77 ( V_468 , V_17 ) ;
if ( V_468 == V_469 ) {
F_24 ( V_342
L_86 , V_284 ) ;
return 0 ;
}
return V_468 ;
}
unsigned long T_2 F_444 ( void )
{
return F_443 ( V_364 ) ;
}
static unsigned long T_2 F_445 ( void )
{
unsigned long V_430 = 0 ;
unsigned long V_17 , V_105 ;
int V_35 , V_284 ;
F_405 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_112 = V_105 - V_17 ;
V_430 += V_112 ;
if ( V_112 )
F_446 ( V_284 , V_185 ) ;
}
return V_430 ;
}
static void T_2 F_447 ( void )
{
int V_35 , V_284 ;
unsigned long V_470 ;
unsigned long V_471 , V_472 ;
T_5 V_473 = V_184 [ V_185 ] ;
unsigned long V_430 = F_445 () ;
int V_474 = F_448 ( V_184 [ V_185 ] ) ;
struct V_475 * V_476 ;
F_411 () ;
if ( F_449 () ) {
F_450 (memory, r) {
if ( ! F_451 ( V_476 ) )
continue;
V_284 = V_476 -> V_284 ;
V_470 = F_452 ( V_476 -> V_477 ) ;
V_420 [ V_284 ] = V_420 [ V_284 ] ?
F_77 ( V_470 , V_420 [ V_284 ] ) :
V_470 ;
}
goto V_478;
}
if ( V_479 ) {
unsigned long V_480 ;
V_479 =
F_369 ( V_479 , V_92 ) ;
V_480 = V_430 - V_479 ;
V_481 = F_363 ( V_481 , V_480 ) ;
}
if ( ! V_481 )
goto V_27;
V_470 = V_416 [ V_417 ] ;
V_482:
V_471 = V_481 / V_474 ;
F_334 (nid, N_MEMORY) {
unsigned long V_17 , V_105 ;
if ( V_481 < V_471 )
V_471 = V_481 / V_474 ;
V_472 = V_471 ;
F_405 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_483 ;
V_17 = F_363 ( V_17 , V_420 [ V_284 ] ) ;
if ( V_17 >= V_105 )
continue;
if ( V_17 < V_470 ) {
unsigned long V_484 ;
V_484 = F_77 ( V_105 , V_470 )
- V_17 ;
V_472 -= F_77 ( V_484 ,
V_472 ) ;
V_481 -= F_77 ( V_484 ,
V_481 ) ;
if ( V_105 <= V_470 ) {
V_420 [ V_284 ] = V_105 ;
continue;
}
V_17 = V_470 ;
}
V_483 = V_105 - V_17 ;
if ( V_483 > V_472 )
V_483 = V_472 ;
V_420 [ V_284 ] = V_17 + V_483 ;
V_481 -= F_77 ( V_481 ,
V_483 ) ;
V_472 -= V_483 ;
if ( ! V_472 )
break;
}
}
V_474 -- ;
if ( V_474 && V_481 > V_474 )
goto V_482;
V_478:
for ( V_284 = 0 ; V_284 < V_364 ; V_284 ++ )
V_420 [ V_284 ] =
F_369 ( V_420 [ V_284 ] , V_92 ) ;
V_27:
V_184 [ V_185 ] = V_473 ;
}
static void F_453 ( T_9 * V_306 , int V_284 )
{
enum V_237 V_237 ;
if ( V_185 == V_485 )
return;
for ( V_237 = 0 ; V_237 <= V_414 - 1 ; V_237 ++ ) {
struct V_12 * V_12 = & V_306 -> V_194 [ V_237 ] ;
if ( F_320 ( V_12 ) ) {
F_446 ( V_284 , V_486 ) ;
if ( V_485 != V_486 &&
V_237 <= V_242 )
F_446 ( V_284 , V_485 ) ;
break;
}
}
}
void T_2 F_454 ( unsigned long * V_131 )
{
unsigned long V_17 , V_105 ;
int V_35 , V_284 ;
memset ( V_416 , 0 ,
sizeof( V_416 ) ) ;
memset ( V_415 , 0 ,
sizeof( V_415 ) ) ;
V_416 [ 0 ] = F_444 () ;
V_415 [ 0 ] = V_131 [ 0 ] ;
for ( V_35 = 1 ; V_35 < V_307 ; V_35 ++ ) {
if ( V_35 == V_414 )
continue;
V_416 [ V_35 ] =
V_415 [ V_35 - 1 ] ;
V_415 [ V_35 ] =
F_363 ( V_131 [ V_35 ] , V_416 [ V_35 ] ) ;
}
V_416 [ V_414 ] = 0 ;
V_415 [ V_414 ] = 0 ;
memset ( V_420 , 0 , sizeof( V_420 ) ) ;
F_447 () ;
F_361 ( L_87 ) ;
for ( V_35 = 0 ; V_35 < V_307 ; V_35 ++ ) {
if ( V_35 == V_414 )
continue;
F_361 ( L_88 , V_385 [ V_35 ] ) ;
if ( V_416 [ V_35 ] ==
V_415 [ V_35 ] )
F_455 ( L_89 ) ;
else
F_455 ( L_90 ,
V_416 [ V_35 ] << V_397 ,
( V_415 [ V_35 ]
<< V_397 ) - 1 ) ;
}
F_361 ( L_91 ) ;
for ( V_35 = 0 ; V_35 < V_364 ; V_35 ++ ) {
if ( V_420 [ V_35 ] )
F_361 ( L_92 , V_35 ,
V_420 [ V_35 ] << V_397 ) ;
}
F_361 ( L_93 ) ;
F_405 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_361 ( L_94 , V_284 ,
V_17 << V_397 , ( V_105 << V_397 ) - 1 ) ;
F_456 () ;
F_439 () ;
F_348 (nid) {
T_9 * V_306 = F_306 ( V_284 ) ;
F_438 ( V_284 , NULL ,
F_443 ( V_284 ) , NULL ) ;
if ( V_306 -> V_432 )
F_446 ( V_284 , V_185 ) ;
F_453 ( V_306 , V_284 ) ;
}
}
static int T_2 F_457 ( char * V_37 , unsigned long * V_487 )
{
unsigned long long V_488 ;
if ( ! V_37 )
return - V_43 ;
V_488 = F_458 ( V_37 , & V_37 ) ;
* V_487 = V_488 >> V_397 ;
F_2 ( ( V_488 >> V_397 ) > V_469 ) ;
return 0 ;
}
static int T_2 F_459 ( char * V_37 )
{
return F_457 ( V_37 , & V_481 ) ;
}
static int T_2 F_460 ( char * V_37 )
{
return F_457 ( V_37 , & V_479 ) ;
}
void F_122 ( struct V_5 * V_5 , long V_73 )
{
F_88 ( & V_489 ) ;
F_18 ( V_5 ) -> V_89 += V_73 ;
V_297 += V_73 ;
#ifdef F_308
if ( F_106 ( V_5 ) )
V_303 += V_73 ;
#endif
F_97 ( & V_489 ) ;
}
unsigned long F_461 ( void * V_458 , void * V_288 , int V_490 , char * V_337 )
{
void * V_369 ;
unsigned long V_112 = 0 ;
V_458 = ( void * ) F_290 ( ( unsigned long ) V_458 ) ;
V_288 = ( void * ) ( ( unsigned long ) V_288 & V_491 ) ;
for ( V_369 = V_458 ; V_369 < V_288 ; V_369 += V_86 , V_112 ++ ) {
if ( ( unsigned int ) V_490 <= 0xFF )
memset ( V_369 , V_490 , V_86 ) ;
F_462 ( F_179 ( V_369 ) ) ;
}
if ( V_112 && V_337 )
F_361 ( L_95 ,
V_337 , V_112 << ( V_397 - 10 ) , V_458 , V_288 ) ;
return V_112 ;
}
void F_463 ( struct V_5 * V_5 )
{
F_464 ( V_5 ) ;
V_297 ++ ;
F_18 ( V_5 ) -> V_89 ++ ;
V_303 ++ ;
}
void T_2 F_465 ( const char * V_147 )
{
unsigned long V_492 , V_493 , V_494 , V_495 , V_496 ;
unsigned long V_497 , V_498 ;
V_492 = F_466 () ;
V_493 = V_499 - V_500 ;
V_494 = V_501 - V_502 ;
V_495 = V_503 - V_504 ;
V_496 = V_505 - V_506 ;
V_498 = V_507 - V_508 ;
V_497 = V_509 - V_510 ;
#define F_467 ( V_458 , V_288 , V_96 , V_369 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_467 ( V_508 , V_507 , V_498 ,
V_510 , V_497 ) ;
F_467 ( V_500 , V_499 , V_493 , V_510 , V_497 ) ;
F_467 ( V_502 , V_501 , V_494 , V_508 , V_498 ) ;
F_467 ( V_500 , V_499 , V_493 , V_504 , V_495 ) ;
F_467 ( V_502 , V_501 , V_494 , V_504 , V_495 ) ;
#undef F_467
F_361 ( L_96
L_97
L_98
#ifdef F_308
L_99
#endif
L_100 ,
F_468 () << ( V_397 - 10 ) , V_492 << ( V_397 - 10 ) ,
V_493 >> 10 , V_494 >> 10 , V_495 >> 10 ,
( V_498 + V_497 ) >> 10 , V_496 >> 10 ,
( V_492 - V_297 - V_511 ) << ( V_397 - 10 ) ,
V_511 << ( V_397 - 10 ) ,
#ifdef F_308
V_303 << ( V_397 - 10 ) ,
#endif
V_147 ? L_101 : L_102 , V_147 ? V_147 : L_102 ) ;
}
void T_2 F_469 ( unsigned long V_512 )
{
V_448 = V_512 ;
}
void T_2 F_470 ( unsigned long * V_427 )
{
F_438 ( 0 , V_427 ,
F_471 ( V_513 ) >> V_397 , NULL ) ;
}
static int F_472 ( struct V_514 * V_379 ,
unsigned long V_515 , void * V_516 )
{
int V_123 = ( unsigned long ) V_516 ;
if ( V_515 == V_517 || V_515 == V_518 ) {
F_473 ( V_123 ) ;
F_150 ( V_123 ) ;
F_474 ( V_123 ) ;
F_475 ( V_123 ) ;
}
return V_519 ;
}
void T_2 F_476 ( void )
{
F_477 ( F_472 , 0 ) ;
}
static void F_478 ( void )
{
struct V_404 * V_306 ;
unsigned long V_520 = 0 ;
enum V_237 V_35 , V_366 ;
F_479 (pgdat) {
for ( V_35 = 0 ; V_35 < V_307 ; V_35 ++ ) {
struct V_12 * V_12 = V_306 -> V_194 + V_35 ;
long F_363 = 0 ;
for ( V_366 = V_35 ; V_366 < V_307 ; V_366 ++ ) {
if ( V_12 -> V_172 [ V_366 ] > F_363 )
F_363 = V_12 -> V_172 [ V_366 ] ;
}
F_363 += F_219 ( V_12 ) ;
if ( F_363 > V_12 -> V_89 )
F_363 = V_12 -> V_89 ;
V_520 += F_363 ;
V_12 -> V_521 = F_363 ;
}
}
V_521 = V_520 ;
V_522 = V_520 ;
}
static void F_480 ( void )
{
struct V_404 * V_306 ;
enum V_237 V_366 , V_523 ;
F_479 (pgdat) {
for ( V_366 = 0 ; V_366 < V_307 ; V_366 ++ ) {
struct V_12 * V_12 = V_306 -> V_194 + V_366 ;
unsigned long V_89 = V_12 -> V_89 ;
V_12 -> V_172 [ V_366 ] = 0 ;
V_523 = V_366 ;
while ( V_523 ) {
struct V_12 * V_524 ;
V_523 -- ;
if ( V_525 [ V_523 ] < 1 )
V_525 [ V_523 ] = 1 ;
V_524 = V_306 -> V_194 + V_523 ;
V_524 -> V_172 [ V_366 ] = V_89 /
V_525 [ V_523 ] ;
V_89 += V_524 -> V_89 ;
}
}
}
F_478 () ;
}
static void F_481 ( void )
{
unsigned long V_526 = V_527 >> ( V_397 - 10 ) ;
unsigned long V_528 = 0 ;
struct V_12 * V_12 ;
unsigned long V_53 ;
F_482 (zone) {
if ( ! F_483 ( V_12 ) )
V_528 += V_12 -> V_89 ;
}
F_482 (zone) {
V_462 V_312 ;
F_161 ( & V_12 -> V_79 , V_53 ) ;
V_312 = ( V_462 ) V_526 * V_12 -> V_89 ;
F_484 ( V_312 , V_528 ) ;
if ( F_483 ( V_12 ) ) {
unsigned long V_529 ;
V_529 = V_12 -> V_89 / 1024 ;
V_529 = F_415 ( V_529 , V_530 , 128UL ) ;
V_12 -> V_136 [ V_531 ] = V_529 ;
} else {
V_12 -> V_136 [ V_531 ] = V_312 ;
}
V_12 -> V_136 [ V_532 ] = F_314 ( V_12 ) + ( V_312 >> 2 ) ;
V_12 -> V_136 [ V_533 ] = F_314 ( V_12 ) + ( V_312 >> 1 ) ;
F_90 ( V_12 , V_143 ,
F_219 ( V_12 ) - F_182 ( V_12 ) -
F_187 ( & V_12 -> V_144 [ V_143 ] ) ) ;
F_368 ( V_12 ) ;
F_169 ( & V_12 -> V_79 , V_53 ) ;
}
F_478 () ;
}
void F_485 ( void )
{
F_327 ( & V_355 ) ;
F_481 () ;
F_330 ( & V_355 ) ;
}
static void T_8 F_486 ( struct V_12 * V_12 )
{
unsigned int V_534 , V_535 ;
V_534 = V_12 -> V_89 >> ( 30 - V_397 ) ;
if ( V_534 )
V_535 = F_487 ( 10 * V_534 ) ;
else
V_535 = 1 ;
V_12 -> V_536 = V_535 ;
}
static void T_8 F_488 ( void )
{
struct V_12 * V_12 ;
F_482 (zone)
F_486 ( V_12 ) ;
}
int T_8 F_489 ( void )
{
unsigned long V_537 ;
int V_538 ;
V_537 = F_298 () * ( V_86 >> 10 ) ;
V_538 = F_487 ( V_537 * 16 ) ;
if ( V_538 > V_539 ) {
V_527 = V_538 ;
if ( V_527 < 128 )
V_527 = 128 ;
if ( V_527 > 65536 )
V_527 = 65536 ;
} else {
F_232 ( L_103 ,
V_538 , V_539 ) ;
}
F_485 () ;
F_490 () ;
F_480 () ;
F_488 () ;
return 0 ;
}
int F_491 ( struct V_345 * V_346 , int V_347 ,
void T_10 * V_348 , T_7 * V_349 , T_11 * V_350 )
{
int V_540 ;
V_540 = F_492 ( V_346 , V_347 , V_348 , V_349 , V_350 ) ;
if ( V_540 )
return V_540 ;
if ( V_347 ) {
V_539 = V_527 ;
F_485 () ;
}
return 0 ;
}
int F_493 ( struct V_345 * V_346 , int V_347 ,
void T_10 * V_348 , T_7 * V_349 , T_11 * V_350 )
{
struct V_12 * V_12 ;
int V_540 ;
V_540 = F_492 ( V_346 , V_347 , V_348 , V_349 , V_350 ) ;
if ( V_540 )
return V_540 ;
F_482 (zone)
V_12 -> V_451 = ( V_12 -> V_89 *
V_452 ) / 100 ;
return 0 ;
}
int F_494 ( struct V_345 * V_346 , int V_347 ,
void T_10 * V_348 , T_7 * V_349 , T_11 * V_350 )
{
struct V_12 * V_12 ;
int V_540 ;
V_540 = F_492 ( V_346 , V_347 , V_348 , V_349 , V_350 ) ;
if ( V_540 )
return V_540 ;
F_482 (zone)
V_12 -> V_453 = ( V_12 -> V_89 *
V_454 ) / 100 ;
return 0 ;
}
int F_495 ( struct V_345 * V_346 , int V_347 ,
void T_10 * V_348 , T_7 * V_349 , T_11 * V_350 )
{
F_492 ( V_346 , V_347 , V_348 , V_349 , V_350 ) ;
F_480 () ;
return 0 ;
}
int F_496 ( struct V_345 * V_346 , int V_347 ,
void T_10 * V_348 , T_7 * V_349 , T_11 * V_350 )
{
struct V_12 * V_12 ;
int V_541 ;
int V_13 ;
F_327 ( & V_542 ) ;
V_541 = V_398 ;
V_13 = F_492 ( V_346 , V_347 , V_348 , V_349 , V_350 ) ;
if ( ! V_347 || V_13 < 0 )
goto V_27;
if ( V_398 &&
V_398 < V_543 ) {
V_398 = V_541 ;
V_13 = - V_43 ;
goto V_27;
}
if ( V_398 == V_541 )
goto V_27;
F_151 (zone) {
unsigned int V_123 ;
F_349 (cpu)
F_389 ( V_12 ,
F_149 ( V_12 -> V_126 , V_123 ) ) ;
}
V_27:
F_330 ( & V_542 ) ;
return V_13 ;
}
static int T_2 F_497 ( char * V_147 )
{
if ( ! V_147 )
return 0 ;
V_544 = F_498 ( V_147 , & V_147 , 0 ) ;
return 1 ;
}
void * T_2 F_499 ( const char * V_545 ,
unsigned long V_546 ,
unsigned long V_547 ,
int V_548 ,
int V_53 ,
unsigned int * V_549 ,
unsigned int * V_550 ,
unsigned long V_551 ,
unsigned long V_552 )
{
unsigned long long F_363 = V_552 ;
unsigned long V_553 , V_96 ;
void * V_346 = NULL ;
if ( ! V_547 ) {
V_547 = V_449 ;
if ( V_397 < 20 )
V_547 = F_500 ( V_547 , ( 1 << 20 ) / V_86 ) ;
if ( V_548 > V_397 )
V_547 >>= ( V_548 - V_397 ) ;
else
V_547 <<= ( V_397 - V_548 ) ;
if ( F_7 ( V_53 & V_554 ) ) {
F_2 ( ! ( V_53 & V_555 ) ) ;
if ( ! ( V_547 >> * V_549 ) ) {
V_547 = 1UL << * V_549 ;
F_181 ( ! V_547 ) ;
}
} else if ( F_7 ( ( V_547 * V_546 ) < V_86 ) )
V_547 = V_86 / V_546 ;
}
V_547 = F_501 ( V_547 ) ;
if ( F_363 == 0 ) {
F_363 = ( ( unsigned long long ) V_450 << V_397 ) >> 4 ;
F_484 ( F_363 , V_546 ) ;
}
F_363 = F_77 ( F_363 , 0x80000000ULL ) ;
if ( V_547 < V_551 )
V_547 = V_551 ;
if ( V_547 > F_363 )
V_547 = F_363 ;
V_553 = F_502 ( V_547 ) ;
do {
V_96 = V_546 << V_553 ;
if ( V_53 & V_555 )
V_346 = F_503 ( V_96 , 0 ) ;
else if ( V_544 )
V_346 = F_504 ( V_96 , V_556 , V_557 ) ;
else {
if ( F_293 ( V_96 ) < V_47 ) {
V_346 = F_292 ( V_96 , V_556 ) ;
F_505 ( V_346 , V_96 , 1 , V_556 ) ;
}
}
} while ( ! V_346 && V_96 > V_86 && -- V_553 );
if ( ! V_346 )
F_506 ( L_104 , V_545 ) ;
F_24 ( V_50 L_105 ,
V_545 ,
( 1UL << V_553 ) ,
F_502 ( V_96 ) - V_397 ,
V_96 ) ;
if ( V_549 )
* V_549 = V_553 ;
if ( V_550 )
* V_550 = ( 1 << V_553 ) - 1 ;
return V_346 ;
}
static inline unsigned long * F_507 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_439
return F_508 ( V_15 ) -> V_436 ;
#else
return V_12 -> V_436 ;
#endif
}
static inline int F_509 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_439
V_15 &= ( V_558 - 1 ) ;
return ( V_15 >> V_61 ) * V_435 ;
#else
V_15 = V_15 - F_510 ( V_12 -> V_18 , V_90 ) ;
return ( V_15 >> V_61 ) * V_435 ;
#endif
}
unsigned long F_511 ( struct V_5 * V_5 , unsigned long V_15 ,
unsigned long V_559 ,
unsigned long V_467 )
{
struct V_12 * V_12 ;
unsigned long * V_560 ;
unsigned long V_561 , V_562 ;
unsigned long V_563 ;
V_12 = F_18 ( V_5 ) ;
V_560 = F_507 ( V_12 , V_15 ) ;
V_561 = F_509 ( V_12 , V_15 ) ;
V_562 = V_561 / V_564 ;
V_561 &= ( V_564 - 1 ) ;
V_563 = V_560 [ V_562 ] ;
V_561 += V_559 ;
return ( V_563 >> ( V_564 - V_561 - 1 ) ) & V_467 ;
}
void F_512 ( struct V_5 * V_5 , unsigned long V_53 ,
unsigned long V_15 ,
unsigned long V_559 ,
unsigned long V_467 )
{
struct V_12 * V_12 ;
unsigned long * V_560 ;
unsigned long V_561 , V_562 ;
unsigned long V_565 , V_563 ;
F_226 ( V_435 != 4 ) ;
V_12 = F_18 ( V_5 ) ;
V_560 = F_507 ( V_12 , V_15 ) ;
V_561 = F_509 ( V_12 , V_15 ) ;
V_562 = V_561 / V_564 ;
V_561 &= ( V_564 - 1 ) ;
F_70 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
V_561 += V_559 ;
V_467 <<= ( V_564 - V_561 - 1 ) ;
V_53 <<= ( V_564 - V_561 - 1 ) ;
V_563 = F_147 ( V_560 [ V_562 ] ) ;
for (; ; ) {
V_565 = F_513 ( & V_560 [ V_562 ] , V_563 , ( V_563 & ~ V_467 ) | V_53 ) ;
if ( V_563 == V_565 )
break;
V_563 = V_565 ;
}
}
bool F_514 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_73 ,
bool V_566 )
{
unsigned long V_15 , V_567 , V_568 ;
int V_84 ;
if ( F_256 ( V_12 ) == V_414 )
return false ;
V_84 = F_95 ( V_5 ) ;
if ( V_84 == V_134 || F_139 ( V_84 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_568 = 0 , V_567 = 0 ; V_567 < V_90 ; V_567 ++ ) {
unsigned long V_569 = V_15 + V_567 ;
if ( ! F_17 ( V_569 ) )
continue;
V_5 = F_136 ( V_569 ) ;
if ( F_515 ( V_5 ) ) {
V_567 = F_500 ( V_567 + 1 , 1 << F_31 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_84 ( & V_5 -> V_69 ) ) {
if ( F_73 ( V_5 ) )
V_567 += ( 1 << F_69 ( V_5 ) ) - 1 ;
continue;
}
if ( V_566 && F_21 ( V_5 ) )
continue;
if ( ! F_516 ( V_5 ) )
V_568 ++ ;
if ( V_568 > V_73 )
return true ;
}
return false ;
}
bool F_517 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_346 ( F_133 ( V_5 ) ) )
return false ;
V_12 = F_18 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_514 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_518 ( unsigned long V_15 )
{
return V_15 & ~ ( F_519 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_520 ( unsigned long V_15 )
{
return F_434 ( V_15 , F_519 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_521 ( struct V_570 * V_571 ,
unsigned long V_458 , unsigned long V_288 )
{
unsigned long V_572 ;
unsigned long V_15 = V_458 ;
unsigned int V_573 = 0 ;
int V_13 = 0 ;
F_522 () ;
while ( V_15 < V_288 || ! F_91 ( & V_571 -> V_574 ) ) {
if ( F_523 ( V_30 ) ) {
V_13 = - V_575 ;
break;
}
if ( F_91 ( & V_571 -> V_574 ) ) {
V_571 -> V_576 = 0 ;
V_15 = F_524 ( V_571 , V_15 , V_288 ) ;
if ( ! V_15 ) {
V_13 = - V_575 ;
break;
}
V_573 = 0 ;
} else if ( ++ V_573 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_577 ;
break;
}
V_572 = F_525 ( V_571 -> V_12 ,
& V_571 -> V_574 ) ;
V_571 -> V_576 -= V_572 ;
V_13 = F_526 ( & V_571 -> V_574 , V_578 ,
NULL , 0 , V_571 -> V_155 , V_579 ) ;
}
if ( V_13 < 0 ) {
F_527 ( & V_571 -> V_574 ) ;
return V_13 ;
}
return 0 ;
}
int F_528 ( unsigned long V_458 , unsigned long V_288 ,
unsigned V_6 )
{
unsigned long V_580 , V_581 ;
int V_13 = 0 , V_34 ;
struct V_570 V_571 = {
. V_576 = 0 ,
. V_34 = - 1 ,
. V_12 = F_18 ( F_136 ( V_458 ) ) ,
. V_155 = V_582 ,
. V_583 = true ,
} ;
F_57 ( & V_571 . V_574 ) ;
V_13 = F_529 ( F_518 ( V_458 ) ,
F_520 ( V_288 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_521 ( & V_571 , V_458 , V_288 ) ;
if ( V_13 )
goto V_584;
F_530 () ;
F_154 ( V_571 . V_12 ) ;
V_34 = 0 ;
V_580 = V_458 ;
while ( ! F_73 ( F_136 ( V_580 ) ) ) {
if ( ++ V_34 >= V_47 ) {
V_13 = - V_577 ;
goto V_584;
}
V_580 &= ~ 0UL << V_34 ;
}
if ( F_531 ( V_580 , V_288 , false ) ) {
F_361 ( L_106 ,
V_585 , V_580 , V_288 ) ;
V_13 = - V_577 ;
goto V_584;
}
V_581 = F_532 ( & V_571 , V_580 , V_288 ) ;
if ( ! V_581 ) {
V_13 = - V_577 ;
goto V_584;
}
if ( V_458 != V_580 )
F_533 ( V_580 , V_458 - V_580 ) ;
if ( V_288 != V_581 )
F_533 ( V_288 , V_581 - V_288 ) ;
V_584:
F_534 ( F_518 ( V_458 ) ,
F_520 ( V_288 ) , V_6 ) ;
return V_13 ;
}
void F_533 ( unsigned long V_15 , unsigned V_36 )
{
unsigned int V_73 = 0 ;
for (; V_36 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_136 ( V_15 ) ;
V_73 += F_71 ( V_5 ) != 1 ;
F_535 ( V_5 ) ;
}
F_536 ( V_73 != 0 , L_107 , V_73 ) ;
}
void T_8 F_537 ( struct V_12 * V_12 )
{
unsigned V_123 ;
F_327 ( & V_542 ) ;
F_349 (cpu)
F_389 ( V_12 ,
F_149 ( V_12 -> V_126 , V_123 ) ) ;
F_330 ( & V_542 ) ;
}
void F_538 ( struct V_12 * V_12 )
{
unsigned long V_53 ;
int V_123 ;
struct V_124 * V_125 ;
F_112 ( V_53 ) ;
if ( V_12 -> V_126 != & V_380 ) {
F_155 (cpu) {
V_125 = F_149 ( V_12 -> V_126 , V_123 ) ;
F_539 ( V_12 , V_125 ) ;
}
F_540 ( V_12 -> V_126 ) ;
V_12 -> V_126 = & V_380 ;
}
F_115 ( V_53 ) ;
}
void
F_541 ( unsigned long V_17 , unsigned long V_105 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
unsigned int V_34 , V_35 ;
unsigned long V_15 ;
unsigned long V_53 ;
for ( V_15 = V_17 ; V_15 < V_105 ; V_15 ++ )
if ( F_163 ( V_15 ) )
break;
if ( V_15 == V_105 )
return;
V_12 = F_18 ( F_136 ( V_15 ) ) ;
F_161 ( & V_12 -> V_79 , V_53 ) ;
V_15 = V_17 ;
while ( V_15 < V_105 ) {
if ( ! F_163 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_136 ( V_15 ) ;
if ( F_7 ( ! F_73 ( V_5 ) && F_21 ( V_5 ) ) ) {
V_15 ++ ;
F_376 ( V_5 ) ;
continue;
}
F_181 ( F_71 ( V_5 ) ) ;
F_181 ( ! F_73 ( V_5 ) ) ;
V_34 = F_69 ( V_5 ) ;
#ifdef F_542
F_24 ( V_50 L_108 ,
V_15 , 1 << V_34 , V_105 ) ;
#endif
F_79 ( & V_5 -> V_54 ) ;
F_65 ( V_5 ) ;
V_12 -> V_62 [ V_34 ] . V_63 -- ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_376 ( ( V_5 + V_35 ) ) ;
V_15 += ( 1 << V_34 ) ;
}
F_169 ( & V_12 -> V_79 , V_53 ) ;
}
bool F_543 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_53 ;
unsigned int V_34 ;
F_161 ( & V_12 -> V_79 , V_53 ) ;
for ( V_34 = 0 ; V_34 < V_47 ; V_34 ++ ) {
struct V_5 * V_586 = V_5 - ( V_15 & ( ( 1 << V_34 ) - 1 ) ) ;
if ( F_73 ( V_586 ) && F_69 ( V_586 ) >= V_34 )
break;
}
F_169 ( & V_12 -> V_79 , V_53 ) ;
return V_34 < V_47 ;
}
