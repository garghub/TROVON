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
V_15 , V_17 , V_17 + V_16 ) ;
return V_13 ;
}
static int F_15 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
if ( ! F_16 ( F_10 ( V_5 ) ) )
return 0 ;
if ( V_12 != F_17 ( V_5 ) )
return 0 ;
return 1 ;
}
static int F_18 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
if ( F_9 ( V_12 , V_5 ) )
return 1 ;
if ( ! F_15 ( V_12 , V_5 ) )
return 1 ;
return 0 ;
}
static inline int F_18 ( struct V_12 * V_12 , struct V_5 * V_5 )
{
return 0 ;
}
static void F_19 ( struct V_5 * V_5 , const char * V_20 ,
unsigned long V_21 )
{
static unsigned long V_22 ;
static unsigned long V_23 ;
static unsigned long V_24 ;
if ( F_20 ( V_5 ) ) {
F_21 ( V_5 ) ;
return;
}
if ( V_23 == 60 ) {
if ( F_22 ( V_25 , V_22 ) ) {
V_24 ++ ;
goto V_26;
}
if ( V_24 ) {
F_23 ( V_27
L_2 ,
V_24 ) ;
V_24 = 0 ;
}
V_23 = 0 ;
}
if ( V_23 ++ == 0 )
V_22 = V_25 + 60 * V_28 ;
F_23 ( V_27 L_3 ,
V_29 -> V_30 , F_10 ( V_5 ) ) ;
F_24 ( V_5 , V_20 , V_21 ) ;
F_25 () ;
F_26 () ;
V_26:
F_21 ( V_5 ) ;
F_27 ( V_31 , V_32 ) ;
}
static void F_28 ( struct V_5 * V_5 )
{
F_29 ( V_5 , F_30 ( V_5 ) ) ;
}
void F_31 ( struct V_5 * V_5 , unsigned long V_33 )
{
int V_34 ;
int V_35 = 1 << V_33 ;
F_32 ( V_5 , F_28 ) ;
F_33 ( V_5 , V_33 ) ;
F_34 ( V_5 ) ;
for ( V_34 = 1 ; V_34 < V_35 ; V_34 ++ ) {
struct V_5 * V_36 = V_5 + V_34 ;
F_35 ( V_36 , 0 ) ;
V_36 -> V_37 = V_5 ;
F_36 () ;
F_37 ( V_36 ) ;
}
}
static int F_38 ( struct V_5 * V_5 , unsigned long V_33 )
{
int V_34 ;
int V_35 = 1 << V_33 ;
int V_38 = 0 ;
if ( F_7 ( F_30 ( V_5 ) != V_33 ) ) {
F_19 ( V_5 , L_4 , 0 ) ;
V_38 ++ ;
}
F_39 ( V_5 ) ;
for ( V_34 = 1 ; V_34 < V_35 ; V_34 ++ ) {
struct V_5 * V_36 = V_5 + V_34 ;
if ( F_7 ( ! F_40 ( V_36 ) ) ) {
F_19 ( V_5 , L_5 , 0 ) ;
V_38 ++ ;
} else if ( F_7 ( V_36 -> V_37 != V_5 ) ) {
F_19 ( V_5 , L_6 , 0 ) ;
V_38 ++ ;
}
F_41 ( V_36 ) ;
}
return V_38 ;
}
static inline void F_42 ( struct V_5 * V_5 , int V_33 , T_1 V_39 )
{
int V_34 ;
F_43 ( ( V_39 & V_40 ) && F_44 () ) ;
for ( V_34 = 0 ; V_34 < ( 1 << V_33 ) ; V_34 ++ )
F_45 ( V_5 + V_34 ) ;
}
static int T_2 F_46 ( char * V_41 )
{
unsigned long V_42 ;
if ( F_47 ( V_41 , 10 , & V_42 ) < 0 || V_42 > V_43 / 2 ) {
F_23 ( V_44 L_7 ) ;
return 0 ;
}
V_45 = V_42 ;
F_23 ( V_46 L_8 , V_42 ) ;
return 0 ;
}
static inline void F_48 ( struct V_5 * V_5 )
{
F_49 ( V_47 , & V_5 -> V_48 ) ;
}
static inline void F_50 ( struct V_5 * V_5 )
{
F_51 ( V_47 , & V_5 -> V_48 ) ;
}
static inline void F_48 ( struct V_5 * V_5 ) { }
static inline void F_50 ( struct V_5 * V_5 ) { }
static inline void F_52 ( struct V_5 * V_5 , int V_33 )
{
F_53 ( V_5 , V_33 ) ;
F_54 ( V_5 ) ;
}
static inline void F_55 ( struct V_5 * V_5 )
{
F_56 ( V_5 ) ;
F_53 ( V_5 , 0 ) ;
}
static inline unsigned long
F_57 ( unsigned long V_49 , unsigned int V_33 )
{
return V_49 ^ ( 1 << V_33 ) ;
}
static inline int F_58 ( struct V_5 * V_5 , struct V_5 * V_50 ,
int V_33 )
{
if ( ! F_16 ( F_10 ( V_50 ) ) )
return 0 ;
if ( F_59 ( V_5 ) != F_59 ( V_50 ) )
return 0 ;
if ( F_60 ( V_50 ) && F_61 ( V_50 ) == V_33 ) {
F_62 ( F_63 ( V_50 ) != 0 , V_50 ) ;
return 1 ;
}
if ( F_64 ( V_50 ) && F_61 ( V_50 ) == V_33 ) {
F_62 ( F_63 ( V_50 ) != 0 , V_50 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_65 ( struct V_5 * V_5 ,
struct V_12 * V_12 , unsigned int V_33 ,
int V_6 )
{
unsigned long V_49 ;
unsigned long V_51 ;
unsigned long V_52 ( V_53 ) ;
struct V_5 * V_50 ;
F_43 ( ! F_66 ( V_12 ) ) ;
if ( F_7 ( F_67 ( V_5 ) ) )
if ( F_7 ( F_38 ( V_5 , V_33 ) ) )
return;
F_43 ( V_6 == - 1 ) ;
V_49 = F_10 ( V_5 ) & ( ( 1 << V_43 ) - 1 ) ;
F_62 ( V_49 & ( ( 1 << V_33 ) - 1 ) , V_5 ) ;
F_62 ( F_18 ( V_12 , V_5 ) , V_5 ) ;
while ( V_33 < V_43 - 1 ) {
V_53 = F_57 ( V_49 , V_33 ) ;
V_50 = V_5 + ( V_53 - V_49 ) ;
if ( ! F_58 ( V_5 , V_50 , V_33 ) )
break;
if ( F_60 ( V_50 ) ) {
F_50 ( V_50 ) ;
F_53 ( V_5 , 0 ) ;
F_68 ( V_12 , 1 << V_33 ,
V_6 ) ;
} else {
F_69 ( & V_50 -> V_54 ) ;
V_12 -> V_55 [ V_33 ] . V_56 -- ;
F_55 ( V_50 ) ;
}
V_51 = V_53 & V_49 ;
V_5 = V_5 + ( V_51 - V_49 ) ;
V_49 = V_51 ;
V_33 ++ ;
}
F_52 ( V_5 , V_33 ) ;
if ( ( V_33 < V_43 - 2 ) && F_16 ( F_10 ( V_50 ) ) ) {
struct V_5 * V_57 , * V_58 ;
V_51 = V_53 & V_49 ;
V_57 = V_5 + ( V_51 - V_49 ) ;
V_53 = F_57 ( V_51 , V_33 + 1 ) ;
V_58 = V_57 + ( V_53 - V_51 ) ;
if ( F_58 ( V_57 , V_58 , V_33 + 1 ) ) {
F_70 ( & V_5 -> V_54 ,
& V_12 -> V_55 [ V_33 ] . V_59 [ V_6 ] ) ;
goto V_26;
}
}
F_71 ( & V_5 -> V_54 , & V_12 -> V_55 [ V_33 ] . V_59 [ V_6 ] ) ;
V_26:
V_12 -> V_55 [ V_33 ] . V_56 ++ ;
}
static inline int F_72 ( struct V_5 * V_5 )
{
const char * V_60 = NULL ;
unsigned long V_21 = 0 ;
if ( F_7 ( F_73 ( V_5 ) ) )
V_60 = L_9 ;
if ( F_7 ( V_5 -> V_61 != NULL ) )
V_60 = L_10 ;
if ( F_7 ( F_74 ( & V_5 -> V_62 ) != 0 ) )
V_60 = L_11 ;
if ( F_7 ( V_5 -> V_63 & V_64 ) ) {
V_60 = L_12 ;
V_21 = V_64 ;
}
if ( F_7 ( F_75 ( V_5 ) ) )
V_60 = L_13 ;
if ( F_7 ( V_60 ) ) {
F_19 ( V_5 , V_60 , V_21 ) ;
return 1 ;
}
F_76 ( V_5 ) ;
if ( V_5 -> V_63 & V_65 )
V_5 -> V_63 &= ~ V_65 ;
return 0 ;
}
static void F_77 ( struct V_12 * V_12 , int V_66 ,
struct V_67 * V_68 )
{
int V_6 = 0 ;
int V_69 = 0 ;
int V_70 = V_66 ;
F_78 ( & V_12 -> V_71 ) ;
V_12 -> V_72 = 0 ;
while ( V_70 ) {
struct V_5 * V_5 ;
struct V_73 * V_74 ;
do {
V_69 ++ ;
if ( ++ V_6 == V_8 )
V_6 = 0 ;
V_74 = & V_68 -> V_75 [ V_6 ] ;
} while ( F_79 ( V_74 ) );
if ( V_69 == V_8 )
V_69 = V_70 ;
do {
int V_76 ;
V_5 = F_80 ( V_74 -> V_77 , struct V_5 , V_54 ) ;
F_69 ( & V_5 -> V_54 ) ;
V_76 = F_81 ( V_5 ) ;
F_65 ( V_5 , V_12 , 0 , V_76 ) ;
F_82 ( V_5 , 0 , V_76 ) ;
if ( F_83 ( ! F_84 ( V_5 ) ) ) {
F_85 ( V_12 , V_78 , 1 ) ;
if ( F_86 ( V_76 ) )
F_85 ( V_12 , V_79 , 1 ) ;
}
} while ( -- V_70 && -- V_69 && ! F_79 ( V_74 ) );
}
F_87 ( & V_12 -> V_71 ) ;
}
static void F_88 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_33 ,
int V_6 )
{
F_78 ( & V_12 -> V_71 ) ;
V_12 -> V_72 = 0 ;
F_65 ( V_5 , V_12 , V_33 , V_6 ) ;
if ( F_7 ( ! F_89 ( V_6 ) ) )
F_68 ( V_12 , 1 << V_33 , V_6 ) ;
F_87 ( & V_12 -> V_71 ) ;
}
static bool F_90 ( struct V_5 * V_5 , unsigned int V_33 )
{
int V_34 ;
int V_38 = 0 ;
F_91 ( V_5 , V_33 ) ;
F_92 ( V_5 , V_33 ) ;
if ( F_93 ( V_5 ) )
V_5 -> V_61 = NULL ;
for ( V_34 = 0 ; V_34 < ( 1 << V_33 ) ; V_34 ++ )
V_38 += F_72 ( V_5 + V_34 ) ;
if ( V_38 )
return false ;
if ( ! F_94 ( V_5 ) ) {
F_95 ( F_96 ( V_5 ) ,
V_80 << V_33 ) ;
F_97 ( F_96 ( V_5 ) ,
V_80 << V_33 ) ;
}
F_98 ( V_5 , V_33 ) ;
F_99 ( V_5 , 1 << V_33 , 0 ) ;
return true ;
}
static void F_29 ( struct V_5 * V_5 , unsigned int V_33 )
{
unsigned long V_63 ;
int V_6 ;
if ( ! F_90 ( V_5 , V_33 ) )
return;
F_100 ( V_63 ) ;
F_101 ( V_81 , 1 << V_33 ) ;
V_6 = F_102 ( V_5 ) ;
F_103 ( V_5 , V_6 ) ;
F_88 ( F_17 ( V_5 ) , V_5 , V_33 , V_6 ) ;
F_104 ( V_63 ) ;
}
void T_2 F_105 ( struct V_5 * V_5 , unsigned int V_33 )
{
unsigned int V_35 = 1 << V_33 ;
struct V_5 * V_36 = V_5 ;
unsigned int V_82 ;
F_106 ( V_36 ) ;
for ( V_82 = 0 ; V_82 < ( V_35 - 1 ) ; V_82 ++ , V_36 ++ ) {
F_106 ( V_36 + 1 ) ;
F_107 ( V_36 ) ;
F_35 ( V_36 , 0 ) ;
}
F_107 ( V_36 ) ;
F_35 ( V_36 , 0 ) ;
F_17 ( V_5 ) -> V_83 += V_35 ;
F_108 ( V_5 ) ;
F_109 ( V_5 , V_33 ) ;
}
void T_2 F_110 ( struct V_5 * V_5 )
{
unsigned V_34 = V_84 ;
struct V_5 * V_36 = V_5 ;
do {
F_107 ( V_36 ) ;
F_35 ( V_36 , 0 ) ;
} while ( ++ V_36 , -- V_34 );
F_108 ( V_5 ) ;
F_6 ( V_5 , V_85 ) ;
F_109 ( V_5 , V_86 ) ;
F_111 ( V_5 , V_84 ) ;
}
static inline void F_112 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_87 , int V_88 , struct V_55 * V_89 ,
int V_6 )
{
unsigned long V_90 = 1 << V_88 ;
while ( V_88 > V_87 ) {
V_89 -- ;
V_88 -- ;
V_90 >>= 1 ;
F_62 ( F_18 ( V_12 , & V_5 [ V_90 ] ) , & V_5 [ V_90 ] ) ;
#ifdef F_113
if ( V_88 < F_114 () ) {
F_115 ( & V_5 [ V_90 ] . V_54 ) ;
F_48 ( & V_5 [ V_90 ] ) ;
F_53 ( & V_5 [ V_90 ] , V_88 ) ;
F_68 ( V_12 , - ( 1 << V_88 ) ,
V_6 ) ;
continue;
}
#endif
F_71 ( & V_5 [ V_90 ] . V_54 , & V_89 -> V_59 [ V_6 ] ) ;
V_89 -> V_56 ++ ;
F_52 ( & V_5 [ V_90 ] , V_88 ) ;
}
}
static inline int F_116 ( struct V_5 * V_5 )
{
const char * V_60 = NULL ;
unsigned long V_21 = 0 ;
if ( F_7 ( F_73 ( V_5 ) ) )
V_60 = L_9 ;
if ( F_7 ( V_5 -> V_61 != NULL ) )
V_60 = L_10 ;
if ( F_7 ( F_74 ( & V_5 -> V_62 ) != 0 ) )
V_60 = L_11 ;
if ( F_7 ( V_5 -> V_63 & V_65 ) ) {
V_60 = L_14 ;
V_21 = V_65 ;
}
if ( F_7 ( F_75 ( V_5 ) ) )
V_60 = L_13 ;
if ( F_7 ( V_60 ) ) {
F_19 ( V_5 , V_60 , V_21 ) ;
return 1 ;
}
return 0 ;
}
static int F_117 ( struct V_5 * V_5 , int V_33 , T_1 V_39 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < ( 1 << V_33 ) ; V_34 ++ ) {
struct V_5 * V_36 = V_5 + V_34 ;
if ( F_7 ( F_116 ( V_36 ) ) )
return 1 ;
}
F_53 ( V_5 , 0 ) ;
F_108 ( V_5 ) ;
F_118 ( V_5 , V_33 ) ;
F_99 ( V_5 , 1 << V_33 , 1 ) ;
if ( V_39 & V_91 )
F_42 ( V_5 , V_33 , V_39 ) ;
if ( V_33 && ( V_39 & V_92 ) )
F_31 ( V_5 , V_33 ) ;
return 0 ;
}
static inline
struct V_5 * F_119 ( struct V_12 * V_12 , unsigned int V_33 ,
int V_6 )
{
unsigned int V_93 ;
struct V_55 * V_89 ;
struct V_5 * V_5 ;
for ( V_93 = V_33 ; V_93 < V_43 ; ++ V_93 ) {
V_89 = & ( V_12 -> V_55 [ V_93 ] ) ;
if ( F_79 ( & V_89 -> V_59 [ V_6 ] ) )
continue;
V_5 = F_80 ( V_89 -> V_59 [ V_6 ] . V_94 ,
struct V_5 , V_54 ) ;
F_69 ( & V_5 -> V_54 ) ;
F_55 ( V_5 ) ;
V_89 -> V_56 -- ;
F_112 ( V_12 , V_5 , V_33 , V_93 , V_89 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_120 ( struct V_12 * V_12 ,
struct V_5 * V_95 , struct V_5 * V_96 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_33 ;
int V_97 = 0 ;
#ifndef F_121
F_122 ( F_17 ( V_95 ) != F_17 ( V_96 ) ) ;
#endif
for ( V_5 = V_95 ; V_5 <= V_96 ; ) {
F_62 ( F_123 ( V_5 ) != F_124 ( V_12 ) , V_5 ) ;
if ( ! F_16 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_64 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_33 = F_61 ( V_5 ) ;
F_125 ( & V_5 -> V_54 ,
& V_12 -> V_55 [ V_33 ] . V_59 [ V_6 ] ) ;
F_103 ( V_5 , V_6 ) ;
V_5 += 1 << V_33 ;
V_97 += 1 << V_33 ;
}
return V_97 ;
}
int F_126 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_17 , V_98 ;
struct V_5 * V_95 , * V_96 ;
V_17 = F_10 ( V_5 ) ;
V_17 = V_17 & ~ ( V_84 - 1 ) ;
V_95 = F_127 ( V_17 ) ;
V_96 = V_95 + V_84 - 1 ;
V_98 = V_17 + V_84 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_95 = V_5 ;
if ( ! F_12 ( V_12 , V_98 ) )
return 0 ;
return F_120 ( V_12 , V_95 , V_96 , V_6 ) ;
}
static void F_128 ( struct V_5 * V_99 ,
int V_100 , int V_6 )
{
int V_101 = 1 << ( V_100 - V_86 ) ;
while ( V_101 -- ) {
F_6 ( V_99 , V_6 ) ;
V_99 += V_84 ;
}
}
static int F_129 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_102 , int V_103 )
{
int V_93 = F_61 ( V_5 ) ;
if ( F_86 ( V_103 ) )
return V_103 ;
if ( V_93 >= V_86 ) {
F_128 ( V_5 , V_93 , V_102 ) ;
return V_102 ;
}
if ( V_93 >= V_86 / 2 ||
V_102 == V_104 ||
V_7 ) {
int V_105 ;
V_105 = F_126 ( V_12 , V_5 , V_102 ) ;
if ( V_105 >= ( 1 << ( V_86 - 1 ) ) ||
V_7 ) {
F_6 ( V_5 , V_102 ) ;
return V_102 ;
}
}
return V_103 ;
}
static inline struct V_5 *
F_130 ( struct V_12 * V_12 , int V_33 , int V_106 )
{
struct V_55 * V_89 ;
int V_93 ;
struct V_5 * V_5 ;
int V_6 , V_107 , V_34 ;
for ( V_93 = V_43 - 1 ; V_93 >= V_33 ;
-- V_93 ) {
for ( V_34 = 0 ; ; V_34 ++ ) {
V_6 = V_108 [ V_106 ] [ V_34 ] ;
if ( V_6 == V_109 )
break;
V_89 = & ( V_12 -> V_55 [ V_93 ] ) ;
if ( F_79 ( & V_89 -> V_59 [ V_6 ] ) )
continue;
V_5 = F_80 ( V_89 -> V_59 [ V_6 ] . V_94 ,
struct V_5 , V_54 ) ;
V_89 -> V_56 -- ;
V_107 = F_129 ( V_12 , V_5 ,
V_106 ,
V_6 ) ;
F_69 ( & V_5 -> V_54 ) ;
F_55 ( V_5 ) ;
F_112 ( V_12 , V_5 , V_33 , V_93 , V_89 ,
V_107 ) ;
F_131 ( V_5 , V_33 , V_93 ,
V_106 , V_6 , V_107 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_132 ( struct V_12 * V_12 , unsigned int V_33 ,
int V_6 )
{
struct V_5 * V_5 ;
V_110:
V_5 = F_119 ( V_12 , V_33 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_109 ) {
V_5 = F_130 ( V_12 , V_33 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_109 ;
goto V_110;
}
}
F_133 ( V_5 , V_33 , V_6 ) ;
return V_5 ;
}
static int F_134 ( struct V_12 * V_12 , unsigned int V_33 ,
unsigned long V_66 , struct V_73 * V_74 ,
int V_6 , int V_111 )
{
int V_76 = V_6 , V_34 ;
F_78 ( & V_12 -> V_71 ) ;
for ( V_34 = 0 ; V_34 < V_66 ; ++ V_34 ) {
struct V_5 * V_5 = F_132 ( V_12 , V_33 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_83 ( V_111 == 0 ) )
F_71 ( & V_5 -> V_54 , V_74 ) ;
else
F_70 ( & V_5 -> V_54 , V_74 ) ;
if ( F_135 ( V_112 ) ) {
V_76 = F_102 ( V_5 ) ;
if ( ! F_86 ( V_76 ) && ! F_89 ( V_76 ) )
V_76 = V_6 ;
}
F_103 ( V_5 , V_76 ) ;
V_74 = & V_5 -> V_54 ;
if ( F_86 ( V_76 ) )
F_85 ( V_12 , V_79 ,
- ( 1 << V_33 ) ) ;
}
F_85 ( V_12 , V_78 , - ( V_34 << V_33 ) ) ;
F_87 ( & V_12 -> V_71 ) ;
return V_34 ;
}
void F_136 ( struct V_12 * V_12 , struct V_67 * V_68 )
{
unsigned long V_63 ;
int V_113 ;
unsigned long V_114 ;
F_100 ( V_63 ) ;
V_114 = F_137 ( V_68 -> V_114 ) ;
if ( V_68 -> V_66 >= V_114 )
V_113 = V_114 ;
else
V_113 = V_68 -> V_66 ;
if ( V_113 > 0 ) {
F_77 ( V_12 , V_113 , V_68 ) ;
V_68 -> V_66 -= V_113 ;
}
F_104 ( V_63 ) ;
}
static void F_138 ( unsigned int V_115 )
{
unsigned long V_63 ;
struct V_12 * V_12 ;
F_139 (zone) {
struct V_116 * V_117 ;
struct V_67 * V_68 ;
F_100 ( V_63 ) ;
V_117 = F_140 ( V_12 -> V_118 , V_115 ) ;
V_68 = & V_117 -> V_68 ;
if ( V_68 -> V_66 ) {
F_77 ( V_12 , V_68 -> V_66 , V_68 ) ;
V_68 -> V_66 = 0 ;
}
F_104 ( V_63 ) ;
}
}
void F_141 ( void * V_119 )
{
F_138 ( F_142 () ) ;
}
void F_143 ( void )
{
int V_115 ;
struct V_116 * V_68 ;
struct V_12 * V_12 ;
static T_3 V_120 ;
F_144 (cpu) {
bool V_121 = false ;
F_139 (zone) {
V_68 = F_140 ( V_12 -> V_118 , V_115 ) ;
if ( V_68 -> V_68 . V_66 ) {
V_121 = true ;
break;
}
}
if ( V_121 )
F_145 ( V_115 , & V_120 ) ;
else
F_146 ( V_115 , & V_120 ) ;
}
F_147 ( & V_120 , F_141 , NULL , 1 ) ;
}
void F_148 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_122 ;
unsigned long V_63 ;
int V_33 , V_123 ;
struct V_73 * V_124 ;
if ( F_149 ( V_12 ) )
return;
F_150 ( & V_12 -> V_71 , V_63 ) ;
V_122 = F_151 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_122 ; V_15 ++ )
if ( F_152 ( V_15 ) ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
if ( ! F_153 ( V_5 ) )
F_154 ( V_5 ) ;
}
F_155 (order, t) {
F_156 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_34 ;
V_15 = F_10 ( F_80 ( V_124 , struct V_5 , V_54 ) ) ;
for ( V_34 = 0 ; V_34 < ( 1UL << V_33 ) ; V_34 ++ )
F_157 ( F_127 ( V_15 + V_34 ) ) ;
}
}
F_158 ( & V_12 -> V_71 , V_63 ) ;
}
void F_159 ( struct V_5 * V_5 , int V_111 )
{
struct V_12 * V_12 = F_17 ( V_5 ) ;
struct V_67 * V_68 ;
unsigned long V_63 ;
int V_6 ;
if ( ! F_90 ( V_5 , 0 ) )
return;
V_6 = F_102 ( V_5 ) ;
F_103 ( V_5 , V_6 ) ;
F_100 ( V_63 ) ;
F_160 ( V_81 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_89 ( V_6 ) ) ) {
F_88 ( V_12 , V_5 , 0 , V_6 ) ;
goto V_26;
}
V_6 = V_125 ;
}
V_68 = & F_161 ( V_12 -> V_118 ) -> V_68 ;
if ( V_111 )
F_70 ( & V_5 -> V_54 , & V_68 -> V_75 [ V_6 ] ) ;
else
F_71 ( & V_5 -> V_54 , & V_68 -> V_75 [ V_6 ] ) ;
V_68 -> V_66 ++ ;
if ( V_68 -> V_66 >= V_68 -> V_88 ) {
unsigned long V_114 = F_137 ( V_68 -> V_114 ) ;
F_77 ( V_12 , V_114 , V_68 ) ;
V_68 -> V_66 -= V_114 ;
}
V_26:
F_104 ( V_63 ) ;
}
void F_162 ( struct V_73 * V_74 , int V_111 )
{
struct V_5 * V_5 , * V_94 ;
F_163 (page, next, list, lru) {
F_164 ( V_5 , V_111 ) ;
F_159 ( V_5 , V_111 ) ;
}
}
void F_165 ( struct V_5 * V_5 , unsigned int V_33 )
{
int V_34 ;
F_62 ( F_67 ( V_5 ) , V_5 ) ;
F_62 ( ! F_63 ( V_5 ) , V_5 ) ;
#ifdef F_166
if ( F_167 ( V_5 ) )
F_165 ( F_168 ( V_5 [ 0 ] . V_126 ) , V_33 ) ;
#endif
for ( V_34 = 1 ; V_34 < ( 1 << V_33 ) ; V_34 ++ )
F_108 ( V_5 + V_34 ) ;
}
static int F_169 ( struct V_5 * V_5 , unsigned int V_33 )
{
unsigned long V_127 ;
struct V_12 * V_12 ;
int V_76 ;
F_122 ( ! F_64 ( V_5 ) ) ;
V_12 = F_17 ( V_5 ) ;
V_76 = F_102 ( V_5 ) ;
if ( ! F_89 ( V_76 ) ) {
V_127 = F_170 ( V_12 ) + ( 1 << V_33 ) ;
if ( ! F_171 ( V_12 , 0 , V_127 , 0 , 0 ) )
return 0 ;
F_68 ( V_12 , - ( 1UL << V_33 ) , V_76 ) ;
}
F_69 ( & V_5 -> V_54 ) ;
V_12 -> V_55 [ V_33 ] . V_56 -- ;
F_55 ( V_5 ) ;
if ( V_33 >= V_86 - 1 ) {
struct V_5 * V_128 = V_5 + ( 1 << V_33 ) - 1 ;
for (; V_5 < V_128 ; V_5 += V_84 ) {
int V_76 = F_102 ( V_5 ) ;
if ( ! F_89 ( V_76 ) && ! F_86 ( V_76 ) )
F_6 ( V_5 ,
V_125 ) ;
}
}
return 1UL << V_33 ;
}
int F_172 ( struct V_5 * V_5 )
{
unsigned int V_33 ;
int V_35 ;
V_33 = F_61 ( V_5 ) ;
V_35 = F_169 ( V_5 , V_33 ) ;
if ( ! V_35 )
return 0 ;
F_108 ( V_5 ) ;
F_165 ( V_5 , V_33 ) ;
return V_35 ;
}
static inline
struct V_5 * F_173 ( struct V_12 * V_129 ,
struct V_12 * V_12 , int V_33 , T_1 V_39 ,
int V_6 )
{
unsigned long V_63 ;
struct V_5 * V_5 ;
int V_111 = ! ! ( V_39 & V_130 ) ;
V_131:
if ( F_83 ( V_33 == 0 ) ) {
struct V_67 * V_68 ;
struct V_73 * V_74 ;
F_100 ( V_63 ) ;
V_68 = & F_161 ( V_12 -> V_118 ) -> V_68 ;
V_74 = & V_68 -> V_75 [ V_6 ] ;
if ( F_79 ( V_74 ) ) {
V_68 -> V_66 += F_134 ( V_12 , 0 ,
V_68 -> V_114 , V_74 ,
V_6 , V_111 ) ;
if ( F_7 ( F_79 ( V_74 ) ) )
goto V_132;
}
if ( V_111 )
V_5 = F_80 ( V_74 -> V_77 , struct V_5 , V_54 ) ;
else
V_5 = F_80 ( V_74 -> V_94 , struct V_5 , V_54 ) ;
F_69 ( & V_5 -> V_54 ) ;
V_68 -> V_66 -- ;
} else {
if ( F_7 ( V_39 & V_133 ) ) {
F_174 ( V_33 > 1 ) ;
}
F_150 ( & V_12 -> V_71 , V_63 ) ;
V_5 = F_132 ( V_12 , V_33 , V_6 ) ;
F_87 ( & V_12 -> V_71 ) ;
if ( ! V_5 )
goto V_132;
F_68 ( V_12 , - ( 1 << V_33 ) ,
F_102 ( V_5 ) ) ;
}
F_85 ( V_12 , V_134 , - ( 1 << V_33 ) ) ;
F_175 ( V_135 , V_12 , 1 << V_33 ) ;
F_176 ( V_129 , V_12 , V_39 ) ;
F_104 ( V_63 ) ;
F_62 ( F_18 ( V_12 , V_5 ) , V_5 ) ;
if ( F_117 ( V_5 , V_33 , V_39 ) )
goto V_131;
return V_5 ;
V_132:
F_104 ( V_63 ) ;
return NULL ;
}
static int T_2 F_177 ( char * V_136 )
{
return F_178 ( & V_137 . V_138 , V_136 ) ;
}
static bool F_179 ( T_1 V_139 , unsigned int V_33 )
{
if ( V_33 < V_137 . V_140 )
return false ;
if ( V_139 & V_133 )
return false ;
if ( V_137 . V_141 && ( V_139 & V_40 ) )
return false ;
if ( V_137 . V_142 && ( V_139 & V_143 ) )
return false ;
return F_180 ( & V_137 . V_138 , 1 << V_33 ) ;
}
static int T_2 F_181 ( void )
{
T_4 V_144 = V_145 | V_146 | V_147 ;
struct V_148 * V_149 ;
V_149 = F_182 ( L_15 , NULL ,
& V_137 . V_138 ) ;
if ( F_183 ( V_149 ) )
return F_184 ( V_149 ) ;
if ( ! F_185 ( L_16 , V_144 , V_149 ,
& V_137 . V_142 ) )
goto V_150;
if ( ! F_185 ( L_17 , V_144 , V_149 ,
& V_137 . V_141 ) )
goto V_150;
if ( ! F_186 ( L_18 , V_144 , V_149 ,
& V_137 . V_140 ) )
goto V_150;
return 0 ;
V_150:
F_187 ( V_149 ) ;
return - V_151 ;
}
static inline bool F_179 ( T_1 V_139 , unsigned int V_33 )
{
return false ;
}
static bool F_188 ( struct V_12 * V_152 , int V_33 , unsigned long V_153 ,
int V_154 , int V_155 , long V_156 )
{
long V_157 = V_153 ;
long V_158 = V_152 -> V_158 [ V_154 ] ;
int V_159 ;
long V_160 = 0 ;
V_156 -= ( 1 << V_33 ) - 1 ;
if ( V_155 & V_161 )
V_157 -= V_157 / 2 ;
if ( V_155 & V_162 )
V_157 -= V_157 / 4 ;
#ifdef V_112
if ( ! ( V_155 & V_163 ) )
V_160 = F_189 ( V_152 , V_79 ) ;
#endif
if ( V_156 - V_160 <= V_157 + V_158 )
return false ;
for ( V_159 = 0 ; V_159 < V_33 ; V_159 ++ ) {
V_156 -= V_152 -> V_55 [ V_159 ] . V_56 << V_159 ;
V_157 >>= 1 ;
if ( V_156 <= V_157 )
return false ;
}
return true ;
}
bool F_171 ( struct V_12 * V_152 , int V_33 , unsigned long V_153 ,
int V_154 , int V_155 )
{
return F_188 ( V_152 , V_33 , V_153 , V_154 , V_155 ,
F_189 ( V_152 , V_78 ) ) ;
}
bool F_190 ( struct V_12 * V_152 , int V_33 , unsigned long V_153 ,
int V_154 , int V_155 )
{
long V_156 = F_189 ( V_152 , V_78 ) ;
if ( V_152 -> V_164 && V_156 < V_152 -> V_164 )
V_156 = F_191 ( V_152 , V_78 ) ;
return F_188 ( V_152 , V_33 , V_153 , V_154 , V_155 ,
V_156 ) ;
}
static T_5 * F_192 ( struct V_165 * V_165 , int V_155 )
{
struct V_166 * V_167 ;
T_5 * V_168 ;
V_167 = V_165 -> V_169 ;
if ( ! V_167 )
return NULL ;
if ( F_193 ( V_25 , V_167 -> V_170 + V_28 ) ) {
F_194 ( V_167 -> V_171 , V_172 ) ;
V_167 -> V_170 = V_25 ;
}
V_168 = ! F_44 () && ( V_155 & V_173 ) ?
& V_174 :
& V_175 [ V_176 ] ;
return V_168 ;
}
static int F_195 ( struct V_165 * V_165 , struct V_177 * V_152 ,
T_5 * V_168 )
{
struct V_166 * V_167 ;
int V_34 ;
int V_178 ;
V_167 = V_165 -> V_169 ;
if ( ! V_167 )
return 1 ;
V_34 = V_152 - V_165 -> V_179 ;
V_178 = V_167 -> V_180 [ V_34 ] ;
return F_196 ( V_178 , * V_168 ) && ! F_197 ( V_34 , V_167 -> V_171 ) ;
}
static void F_198 ( struct V_165 * V_165 , struct V_177 * V_152 )
{
struct V_166 * V_167 ;
int V_34 ;
V_167 = V_165 -> V_169 ;
if ( ! V_167 )
return;
V_34 = V_152 - V_165 -> V_179 ;
F_199 ( V_34 , V_167 -> V_171 ) ;
}
static void F_200 ( struct V_165 * V_165 )
{
struct V_166 * V_167 ;
V_167 = V_165 -> V_169 ;
if ( ! V_167 )
return;
F_194 ( V_167 -> V_171 , V_172 ) ;
}
static bool F_201 ( struct V_12 * V_181 , struct V_12 * V_12 )
{
return V_181 -> V_182 == V_12 -> V_182 ;
}
static bool F_202 ( struct V_12 * V_181 , struct V_12 * V_12 )
{
return F_196 ( V_181 -> V_182 , V_12 -> V_183 -> V_184 ) ;
}
static void T_6 F_203 ( int V_185 )
{
int V_34 ;
F_204 (i, N_MEMORY)
if ( F_205 ( V_185 , V_34 ) <= V_186 )
F_206 ( V_34 , F_207 ( V_185 ) -> V_184 ) ;
else
V_187 = 1 ;
}
static T_5 * F_192 ( struct V_165 * V_165 , int V_155 )
{
return NULL ;
}
static int F_195 ( struct V_165 * V_165 , struct V_177 * V_152 ,
T_5 * V_168 )
{
return 1 ;
}
static void F_198 ( struct V_165 * V_165 , struct V_177 * V_152 )
{
}
static void F_200 ( struct V_165 * V_165 )
{
}
static bool F_201 ( struct V_12 * V_181 , struct V_12 * V_12 )
{
return true ;
}
static bool F_202 ( struct V_12 * V_181 , struct V_12 * V_12 )
{
return true ;
}
static inline void F_203 ( int V_185 )
{
}
static struct V_5 *
F_208 ( T_1 V_139 , T_5 * V_188 , unsigned int V_33 ,
struct V_165 * V_165 , int V_189 , int V_155 ,
struct V_12 * V_129 , int V_6 )
{
struct V_177 * V_152 ;
struct V_5 * V_5 = NULL ;
int V_154 ;
struct V_12 * V_12 ;
T_5 * V_168 = NULL ;
int V_190 = 0 ;
int V_191 = 0 ;
V_154 = F_209 ( V_129 ) ;
V_192:
F_210 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_153 ;
if ( F_135 ( V_193 ) && V_190 &&
! F_195 ( V_165 , V_152 , V_168 ) )
continue;
if ( ( V_155 & V_173 ) &&
! F_211 ( V_12 , V_139 ) )
continue;
F_212 ( V_194 < V_195 ) ;
if ( F_7 ( V_155 & V_194 ) )
goto V_196;
if ( V_155 & V_197 ) {
if ( ! F_201 ( V_129 , V_12 ) )
continue;
if ( F_189 ( V_12 , V_134 ) <= 0 )
continue;
}
if ( ( V_155 & V_198 ) &&
( V_139 & V_199 ) && ! F_213 ( V_12 ) )
goto V_200;
V_153 = V_12 -> V_127 [ V_155 & V_201 ] ;
if ( ! F_171 ( V_12 , V_33 , V_153 ,
V_154 , V_155 ) ) {
int V_13 ;
if ( F_135 ( V_193 ) &&
! V_191 && V_202 > 1 ) {
V_168 = F_192 ( V_165 , V_155 ) ;
V_190 = 1 ;
V_191 = 1 ;
}
if ( V_187 == 0 ||
! F_202 ( V_129 , V_12 ) )
goto V_200;
if ( F_135 ( V_193 ) && V_190 &&
! F_195 ( V_165 , V_152 , V_168 ) )
continue;
V_13 = F_214 ( V_12 , V_139 , V_33 ) ;
switch ( V_13 ) {
case V_203 :
continue;
case V_204 :
continue;
default:
if ( F_171 ( V_12 , V_33 , V_153 ,
V_154 , V_155 ) )
goto V_196;
if ( ( ( V_155 & V_201 ) == V_205 ) ||
V_13 == V_206 )
goto V_200;
continue;
}
}
V_196:
V_5 = F_173 ( V_129 , V_12 , V_33 ,
V_139 , V_6 ) ;
if ( V_5 )
break;
V_200:
if ( F_135 ( V_193 ) )
F_198 ( V_165 , V_152 ) ;
}
if ( F_7 ( F_135 ( V_193 ) && V_5 == NULL && V_190 ) ) {
V_190 = 0 ;
goto V_192;
}
if ( V_5 )
V_5 -> V_207 = ! ! ( V_155 & V_194 ) ;
return V_5 ;
}
static inline bool F_215 ( void )
{
bool V_13 = false ;
#if V_208 > 8
V_13 = F_44 () ;
#endif
return V_13 ;
}
void F_216 ( T_1 V_139 , int V_33 , const char * V_209 , ... )
{
unsigned int V_210 = V_211 ;
if ( ( V_139 & V_212 ) || ! F_217 ( & V_213 ) ||
F_114 () > 0 )
return;
if ( ! ( V_139 & V_214 ) )
if ( F_218 ( V_215 ) ||
( V_29 -> V_63 & ( V_216 | V_217 ) ) )
V_210 &= ~ V_211 ;
if ( F_44 () || ! ( V_139 & V_143 ) )
V_210 &= ~ V_211 ;
if ( V_209 ) {
struct V_218 V_219 ;
T_7 args ;
va_start ( args , V_209 ) ;
V_219 . V_209 = V_209 ;
V_219 . V_220 = & args ;
F_219 ( L_19 , & V_219 ) ;
va_end ( args ) ;
}
F_219 ( L_20 ,
V_29 -> V_30 , V_33 , V_139 ) ;
F_26 () ;
if ( ! F_215 () )
F_220 ( V_210 ) ;
}
static inline int
F_221 ( T_1 V_139 , unsigned int V_33 ,
unsigned long V_221 ,
unsigned long V_222 )
{
if ( V_139 & V_223 )
return 0 ;
if ( V_139 & V_133 )
return 1 ;
if ( ! V_221 && F_5 () )
return 0 ;
if ( V_33 <= V_224 )
return 1 ;
if ( V_139 & V_225 && V_222 < ( 1 << V_33 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_222 ( T_1 V_139 , unsigned int V_33 ,
struct V_165 * V_165 , enum V_226 V_189 ,
T_5 * V_188 , struct V_12 * V_129 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_223 ( V_165 , V_139 ) ) {
F_224 ( 1 ) ;
return NULL ;
}
V_5 = F_208 ( V_139 | V_227 , V_188 ,
V_33 , V_165 , V_189 ,
V_228 | V_173 ,
V_129 , V_6 ) ;
if ( V_5 )
goto V_26;
if ( ! ( V_139 & V_133 ) ) {
if ( V_33 > V_224 )
goto V_26;
if ( V_189 < V_229 )
goto V_26;
if ( V_139 & V_230 )
goto V_26;
}
F_225 ( V_165 , V_139 , V_33 , V_188 , false ) ;
V_26:
F_226 ( V_165 , V_139 ) ;
return V_5 ;
}
static struct V_5 *
F_227 ( T_1 V_139 , unsigned int V_33 ,
struct V_165 * V_165 , enum V_226 V_189 ,
T_5 * V_188 , int V_155 , struct V_12 * V_129 ,
int V_6 , bool V_231 ,
bool * V_232 , bool * V_233 ,
unsigned long * V_221 )
{
if ( ! V_33 )
return NULL ;
if ( F_228 ( V_129 , V_33 ) ) {
* V_233 = true ;
return NULL ;
}
V_29 -> V_63 |= V_216 ;
* V_221 = F_229 ( V_165 , V_33 , V_139 ,
V_188 , V_231 ,
V_232 ) ;
V_29 -> V_63 &= ~ V_216 ;
if ( * V_221 != V_234 ) {
struct V_5 * V_5 ;
F_138 ( F_230 () ) ;
F_231 () ;
V_5 = F_208 ( V_139 , V_188 ,
V_33 , V_165 , V_189 ,
V_155 & ~ V_194 ,
V_129 , V_6 ) ;
if ( V_5 ) {
V_129 -> V_235 = false ;
F_232 ( V_129 , V_33 , true ) ;
F_233 ( V_236 ) ;
return V_5 ;
}
F_233 ( V_237 ) ;
if ( V_231 )
F_234 ( V_129 , V_33 ) ;
F_235 () ;
}
return NULL ;
}
static inline struct V_5 *
F_227 ( T_1 V_139 , unsigned int V_33 ,
struct V_165 * V_165 , enum V_226 V_189 ,
T_5 * V_188 , int V_155 , struct V_12 * V_129 ,
int V_6 , bool V_231 ,
bool * V_232 , bool * V_233 ,
unsigned long * V_221 )
{
return NULL ;
}
static int
F_236 ( T_1 V_139 , unsigned int V_33 , struct V_165 * V_165 ,
T_5 * V_188 )
{
struct V_238 V_238 ;
int V_239 ;
F_235 () ;
F_237 () ;
V_29 -> V_63 |= V_216 ;
F_238 ( V_139 ) ;
V_238 . V_240 = 0 ;
V_29 -> V_238 = & V_238 ;
V_239 = F_239 ( V_165 , V_33 , V_139 , V_188 ) ;
V_29 -> V_238 = NULL ;
F_240 () ;
V_29 -> V_63 &= ~ V_216 ;
F_235 () ;
return V_239 ;
}
static inline struct V_5 *
F_241 ( T_1 V_139 , unsigned int V_33 ,
struct V_165 * V_165 , enum V_226 V_189 ,
T_5 * V_188 , int V_155 , struct V_12 * V_129 ,
int V_6 , unsigned long * V_221 )
{
struct V_5 * V_5 = NULL ;
bool V_241 = false ;
* V_221 = F_236 ( V_139 , V_33 , V_165 ,
V_188 ) ;
if ( F_7 ( ! ( * V_221 ) ) )
return NULL ;
if ( F_135 ( V_193 ) )
F_200 ( V_165 ) ;
V_242:
V_5 = F_208 ( V_139 , V_188 , V_33 ,
V_165 , V_189 ,
V_155 & ~ V_194 ,
V_129 , V_6 ) ;
if ( ! V_5 && ! V_241 ) {
F_143 () ;
V_241 = true ;
goto V_242;
}
return V_5 ;
}
static inline struct V_5 *
F_242 ( T_1 V_139 , unsigned int V_33 ,
struct V_165 * V_165 , enum V_226 V_189 ,
T_5 * V_188 , struct V_12 * V_129 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_208 ( V_139 , V_188 , V_33 ,
V_165 , V_189 , V_194 ,
V_129 , V_6 ) ;
if ( ! V_5 && V_139 & V_133 )
F_243 ( V_129 , V_243 , V_28 / 50 ) ;
} while ( ! V_5 && ( V_139 & V_133 ) );
return V_5 ;
}
static void F_244 ( struct V_165 * V_165 ,
enum V_226 V_189 ,
struct V_12 * V_129 )
{
struct V_177 * V_152 ;
struct V_12 * V_12 ;
F_245 (zone, z, zonelist, high_zoneidx) {
if ( ! F_201 ( V_129 , V_12 ) )
continue;
F_246 ( V_12 , V_134 ,
F_247 ( V_12 ) - F_170 ( V_12 ) -
F_248 ( & V_12 -> V_244 [ V_134 ] ) ) ;
}
}
static void F_249 ( unsigned int V_33 ,
struct V_165 * V_165 ,
enum V_226 V_189 ,
struct V_12 * V_129 )
{
struct V_177 * V_152 ;
struct V_12 * V_12 ;
F_245 (zone, z, zonelist, high_zoneidx)
F_250 ( V_12 , V_33 , F_209 ( V_129 ) ) ;
}
static inline int
F_251 ( T_1 V_139 )
{
int V_155 = V_205 | V_173 ;
const T_1 V_245 = V_139 & V_143 ;
F_212 ( V_246 != ( V_247 T_1 ) V_161 ) ;
V_155 |= ( V_247 int ) ( V_139 & V_246 ) ;
if ( ! V_245 ) {
if ( ! ( V_139 & V_214 ) )
V_155 |= V_162 ;
V_155 &= ~ V_173 ;
} else if ( F_7 ( F_252 ( V_29 ) ) && ! F_44 () )
V_155 |= V_162 ;
if ( F_83 ( ! ( V_139 & V_214 ) ) ) {
if ( V_139 & V_248 )
V_155 |= V_194 ;
else if ( F_253 () && ( V_29 -> V_63 & V_216 ) )
V_155 |= V_194 ;
else if ( ! F_44 () &&
( ( V_29 -> V_63 & V_216 ) ||
F_7 ( F_218 ( V_215 ) ) ) )
V_155 |= V_194 ;
}
#ifdef V_112
if ( F_254 ( V_139 ) == V_125 )
V_155 |= V_163 ;
#endif
return V_155 ;
}
bool F_255 ( T_1 V_139 )
{
return ! ! ( F_251 ( V_139 ) & V_194 ) ;
}
static inline struct V_5 *
F_256 ( T_1 V_139 , unsigned int V_33 ,
struct V_165 * V_165 , enum V_226 V_189 ,
T_5 * V_188 , struct V_12 * V_129 ,
int V_6 )
{
const T_1 V_245 = V_139 & V_143 ;
struct V_5 * V_5 = NULL ;
int V_155 ;
unsigned long V_222 = 0 ;
unsigned long V_221 ;
bool V_231 = false ;
bool V_233 = false ;
bool V_232 = false ;
if ( V_33 >= V_43 ) {
F_174 ( ! ( V_139 & V_212 ) ) ;
return NULL ;
}
if ( F_135 ( V_193 ) &&
( V_139 & V_249 ) == V_249 )
goto V_250;
V_251:
if ( ! ( V_139 & V_252 ) )
F_249 ( V_33 , V_165 , V_189 , V_129 ) ;
V_155 = F_251 ( V_139 ) ;
if ( ! ( V_155 & V_173 ) && ! V_188 )
F_257 ( V_165 , V_189 , NULL ,
& V_129 ) ;
V_253:
V_5 = F_208 ( V_139 , V_188 , V_33 , V_165 ,
V_189 , V_155 & ~ V_194 ,
V_129 , V_6 ) ;
if ( V_5 )
goto V_254;
if ( V_155 & V_194 ) {
V_165 = F_258 ( F_259 () , V_139 ) ;
V_5 = F_242 ( V_139 , V_33 ,
V_165 , V_189 , V_188 ,
V_129 , V_6 ) ;
if ( V_5 ) {
goto V_254;
}
}
if ( ! V_245 ) {
F_174 ( V_139 & V_133 ) ;
goto V_250;
}
if ( V_29 -> V_63 & V_216 )
goto V_250;
if ( F_218 ( V_215 ) && ! ( V_139 & V_133 ) )
goto V_250;
V_5 = F_227 ( V_139 , V_33 ,
V_165 , V_189 ,
V_188 ,
V_155 , V_129 ,
V_6 , V_231 ,
& V_232 ,
& V_233 ,
& V_221 ) ;
if ( V_5 )
goto V_254;
V_231 = true ;
if ( ( V_233 || V_232 ) &&
( V_139 & V_252 ) )
goto V_250;
V_5 = F_241 ( V_139 , V_33 ,
V_165 , V_189 ,
V_188 ,
V_155 , V_129 ,
V_6 , & V_221 ) ;
if ( V_5 )
goto V_254;
if ( ! V_221 ) {
if ( F_260 ( V_139 ) ) {
if ( V_255 )
goto V_250;
if ( ( V_29 -> V_63 & V_256 ) &&
! ( V_139 & V_133 ) )
goto V_250;
V_5 = F_222 ( V_139 , V_33 ,
V_165 , V_189 ,
V_188 , V_129 ,
V_6 ) ;
if ( V_5 )
goto V_254;
if ( ! ( V_139 & V_133 ) ) {
if ( V_33 > V_224 )
goto V_250;
if ( V_189 < V_229 )
goto V_250;
}
goto V_251;
}
}
V_222 += V_221 ;
if ( F_221 ( V_139 , V_33 , V_221 ,
V_222 ) ) {
F_243 ( V_129 , V_243 , V_28 / 50 ) ;
goto V_253;
} else {
V_5 = F_227 ( V_139 , V_33 ,
V_165 , V_189 ,
V_188 ,
V_155 , V_129 ,
V_6 , V_231 ,
& V_232 ,
& V_233 ,
& V_221 ) ;
if ( V_5 )
goto V_254;
}
V_250:
F_216 ( V_139 , V_33 , NULL ) ;
return V_5 ;
V_254:
if ( V_257 )
F_261 ( V_5 , V_33 , V_139 ) ;
return V_5 ;
}
struct V_5 *
F_262 ( T_1 V_139 , unsigned int V_33 ,
struct V_165 * V_165 , T_5 * V_188 )
{
enum V_226 V_189 = F_263 ( V_139 ) ;
struct V_12 * V_129 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_254 ( V_139 ) ;
unsigned int V_258 ;
int V_155 = V_198 | V_173 | V_197 ;
struct V_259 * V_260 = NULL ;
V_139 &= V_3 ;
F_264 ( V_139 ) ;
F_265 ( V_139 & V_143 ) ;
if ( F_179 ( V_139 , V_33 ) )
return NULL ;
if ( F_7 ( ! V_165 -> V_179 -> V_12 ) )
return NULL ;
if ( ! F_266 ( V_139 , & V_260 , V_33 ) )
return NULL ;
V_261:
V_258 = F_267 () ;
F_257 ( V_165 , V_189 ,
V_188 ? : & V_174 ,
& V_129 ) ;
if ( ! V_129 )
goto V_26;
#ifdef V_112
if ( F_254 ( V_139 ) == V_125 )
V_155 |= V_163 ;
#endif
V_242:
V_5 = F_208 ( V_139 | V_227 , V_188 , V_33 ,
V_165 , V_189 , V_155 ,
V_129 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
if ( V_155 & V_197 ) {
F_244 ( V_165 , V_189 ,
V_129 ) ;
V_155 &= ~ V_197 ;
goto V_242;
}
V_139 = F_268 ( V_139 ) ;
V_5 = F_256 ( V_139 , V_33 ,
V_165 , V_189 , V_188 ,
V_129 , V_6 ) ;
}
F_269 ( V_5 , V_33 , V_139 , V_6 ) ;
V_26:
if ( F_7 ( ! V_5 && F_270 ( V_258 ) ) )
goto V_261;
F_271 ( V_5 , V_260 , V_33 ) ;
return V_5 ;
}
unsigned long F_272 ( T_1 V_139 , unsigned int V_33 )
{
struct V_5 * V_5 ;
F_43 ( ( V_139 & V_40 ) != 0 ) ;
V_5 = F_273 ( V_139 , V_33 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_96 ( V_5 ) ;
}
unsigned long F_274 ( T_1 V_139 )
{
return F_272 ( V_139 | V_91 , 0 ) ;
}
void F_109 ( struct V_5 * V_5 , unsigned int V_33 )
{
if ( F_275 ( V_5 ) ) {
if ( V_33 == 0 )
F_159 ( V_5 , 0 ) ;
else
F_29 ( V_5 , V_33 ) ;
}
}
void V_156 ( unsigned long V_262 , unsigned int V_33 )
{
if ( V_262 != 0 ) {
F_43 ( ! F_276 ( ( void * ) V_262 ) ) ;
F_109 ( F_168 ( ( void * ) V_262 ) , V_33 ) ;
}
}
void F_277 ( struct V_5 * V_5 , unsigned int V_33 )
{
F_278 ( V_5 , V_33 ) ;
F_109 ( V_5 , V_33 ) ;
}
void F_279 ( unsigned long V_262 , unsigned int V_33 )
{
if ( V_262 != 0 ) {
F_43 ( ! F_276 ( ( void * ) V_262 ) ) ;
F_277 ( F_168 ( ( void * ) V_262 ) , V_33 ) ;
}
}
static void * F_280 ( unsigned long V_262 , unsigned V_33 , T_8 V_90 )
{
if ( V_262 ) {
unsigned long V_263 = V_262 + ( V_80 << V_33 ) ;
unsigned long V_264 = V_262 + F_281 ( V_90 ) ;
F_165 ( F_168 ( ( void * ) V_262 ) , V_33 ) ;
while ( V_264 < V_263 ) {
F_282 ( V_264 ) ;
V_264 += V_80 ;
}
}
return ( void * ) V_262 ;
}
void * F_283 ( T_8 V_90 , T_1 V_139 )
{
unsigned int V_33 = F_284 ( V_90 ) ;
unsigned long V_262 ;
V_262 = F_272 ( V_139 , V_33 ) ;
return F_280 ( V_262 , V_33 , V_90 ) ;
}
void * F_285 ( int V_185 , T_8 V_90 , T_1 V_139 )
{
unsigned V_33 = F_284 ( V_90 ) ;
struct V_5 * V_36 = F_286 ( V_185 , V_139 , V_33 ) ;
if ( ! V_36 )
return NULL ;
return F_280 ( ( unsigned long ) F_96 ( V_36 ) , V_33 , V_90 ) ;
}
void F_287 ( void * V_265 , T_8 V_90 )
{
unsigned long V_262 = ( unsigned long ) V_265 ;
unsigned long V_266 = V_262 + F_281 ( V_90 ) ;
while ( V_262 < V_266 ) {
F_282 ( V_262 ) ;
V_262 += V_80 ;
}
}
static unsigned long F_288 ( int V_267 )
{
struct V_177 * V_152 ;
struct V_12 * V_12 ;
unsigned long V_268 = 0 ;
struct V_165 * V_165 = F_258 ( F_259 () , V_269 ) ;
F_245 (zone, z, zonelist, offset) {
unsigned long V_90 = V_12 -> V_83 ;
unsigned long V_88 = F_247 ( V_12 ) ;
if ( V_90 > V_88 )
V_268 += V_90 - V_88 ;
}
return V_268 ;
}
unsigned long F_289 ( void )
{
return F_288 ( F_263 ( V_270 ) ) ;
}
unsigned long F_290 ( void )
{
return F_288 ( F_263 ( V_271 ) ) ;
}
static inline void F_291 ( struct V_12 * V_12 )
{
if ( F_135 ( V_193 ) )
F_23 ( L_21 , F_124 ( V_12 ) ) ;
}
void F_292 ( struct V_272 * V_273 )
{
V_273 -> V_274 = V_275 ;
V_273 -> V_276 = 0 ;
V_273 -> V_277 = F_293 ( V_78 ) ;
V_273 -> V_278 = F_294 () ;
V_273 -> V_279 = V_280 ;
V_273 -> V_281 = F_295 () ;
V_273 -> V_282 = V_80 ;
}
void F_296 ( struct V_272 * V_273 , int V_185 )
{
int V_226 ;
unsigned long V_83 = 0 ;
T_9 * V_283 = F_207 ( V_185 ) ;
for ( V_226 = 0 ; V_226 < V_284 ; V_226 ++ )
V_83 += V_283 -> V_285 [ V_226 ] . V_83 ;
V_273 -> V_274 = V_83 ;
V_273 -> V_277 = F_297 ( V_185 , V_78 ) ;
#ifdef F_298
V_273 -> V_279 = V_283 -> V_285 [ V_286 ] . V_83 ;
V_273 -> V_281 = F_189 ( & V_283 -> V_285 [ V_286 ] ,
V_78 ) ;
#else
V_273 -> V_279 = 0 ;
V_273 -> V_281 = 0 ;
#endif
V_273 -> V_282 = V_80 ;
}
bool F_299 ( unsigned int V_63 , int V_185 )
{
bool V_13 = false ;
unsigned int V_258 ;
if ( ! ( V_63 & V_211 ) )
goto V_26;
do {
V_258 = F_267 () ;
V_13 = ! F_196 ( V_185 , V_174 ) ;
} while ( F_270 ( V_258 ) );
V_26:
return V_13 ;
}
static void F_300 ( unsigned char type )
{
static const char V_287 [ V_288 ] = {
[ V_9 ] = 'U' ,
[ V_104 ] = 'E' ,
[ V_125 ] = 'M' ,
[ V_109 ] = 'R' ,
#ifdef V_112
[ V_85 ] = 'C' ,
#endif
#ifdef F_301
[ V_289 ] = 'I' ,
#endif
} ;
char V_290 [ V_288 + 1 ] ;
char * V_36 = V_290 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_288 ; V_34 ++ ) {
if ( type & ( 1 << V_34 ) )
* V_36 ++ = V_287 [ V_34 ] ;
}
* V_36 = '\0' ;
F_23 ( L_22 , V_290 ) ;
}
void F_302 ( unsigned int V_210 )
{
int V_115 ;
struct V_12 * V_12 ;
F_139 (zone) {
if ( F_299 ( V_210 , F_124 ( V_12 ) ) )
continue;
F_291 ( V_12 ) ;
F_23 ( L_23 , V_12 -> V_291 ) ;
F_144 (cpu) {
struct V_116 * V_118 ;
V_118 = F_140 ( V_12 -> V_118 , V_115 ) ;
F_23 ( L_24 ,
V_115 , V_118 -> V_68 . V_88 ,
V_118 -> V_68 . V_114 , V_118 -> V_68 . V_66 ) ;
}
}
F_23 ( L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
F_293 ( V_292 ) ,
F_293 ( V_293 ) ,
F_293 ( V_294 ) ,
F_293 ( V_295 ) ,
F_293 ( V_296 ) ,
F_293 ( V_297 ) ,
F_293 ( V_298 ) ,
F_293 ( V_299 ) ,
F_293 ( V_300 ) ,
F_293 ( V_301 ) ,
F_293 ( V_78 ) ,
F_293 ( V_302 ) ,
F_293 ( V_303 ) ,
F_293 ( V_304 ) ,
F_293 ( V_305 ) ,
F_293 ( V_306 ) ,
F_293 ( V_307 ) ,
F_293 ( V_79 ) ) ;
F_139 (zone) {
int V_34 ;
if ( F_299 ( V_210 , F_124 ( V_12 ) ) )
continue;
F_291 ( V_12 ) ;
F_23 ( L_32
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
V_12 -> V_291 ,
F_303 ( F_189 ( V_12 , V_78 ) ) ,
F_303 ( F_304 ( V_12 ) ) ,
F_303 ( F_170 ( V_12 ) ) ,
F_303 ( F_247 ( V_12 ) ) ,
F_303 ( F_189 ( V_12 , V_292 ) ) ,
F_303 ( F_189 ( V_12 , V_293 ) ) ,
F_303 ( F_189 ( V_12 , V_295 ) ) ,
F_303 ( F_189 ( V_12 , V_296 ) ) ,
F_303 ( F_189 ( V_12 , V_298 ) ) ,
F_303 ( F_189 ( V_12 , V_294 ) ) ,
F_303 ( F_189 ( V_12 , V_297 ) ) ,
F_303 ( V_12 -> V_308 ) ,
F_303 ( V_12 -> V_83 ) ,
F_303 ( F_189 ( V_12 , V_309 ) ) ,
F_303 ( F_189 ( V_12 , V_299 ) ) ,
F_303 ( F_189 ( V_12 , V_300 ) ) ,
F_303 ( F_189 ( V_12 , V_304 ) ) ,
F_303 ( F_189 ( V_12 , V_305 ) ) ,
F_303 ( F_189 ( V_12 , V_302 ) ) ,
F_303 ( F_189 ( V_12 , V_303 ) ) ,
F_189 ( V_12 , V_310 ) *
V_311 / 1024 ,
F_303 ( F_189 ( V_12 , V_306 ) ) ,
F_303 ( F_189 ( V_12 , V_301 ) ) ,
F_303 ( F_189 ( V_12 , V_307 ) ) ,
F_303 ( F_189 ( V_12 , V_79 ) ) ,
F_303 ( F_189 ( V_12 , V_312 ) ) ,
V_12 -> V_72 ,
( ! F_305 ( V_12 ) ? L_62 : L_63 )
) ;
F_23 ( L_64 ) ;
for ( V_34 = 0 ; V_34 < V_284 ; V_34 ++ )
F_23 ( L_65 , V_12 -> V_158 [ V_34 ] ) ;
F_23 ( L_61 ) ;
}
F_139 (zone) {
unsigned long V_313 [ V_43 ] , V_63 , V_33 , V_314 = 0 ;
unsigned char V_287 [ V_43 ] ;
if ( F_299 ( V_210 , F_124 ( V_12 ) ) )
continue;
F_291 ( V_12 ) ;
F_23 ( L_66 , V_12 -> V_291 ) ;
F_150 ( & V_12 -> V_71 , V_63 ) ;
for ( V_33 = 0 ; V_33 < V_43 ; V_33 ++ ) {
struct V_55 * V_89 = & V_12 -> V_55 [ V_33 ] ;
int type ;
V_313 [ V_33 ] = V_89 -> V_56 ;
V_314 += V_313 [ V_33 ] << V_33 ;
V_287 [ V_33 ] = 0 ;
for ( type = 0 ; type < V_288 ; type ++ ) {
if ( ! F_79 ( & V_89 -> V_59 [ type ] ) )
V_287 [ V_33 ] |= 1 << type ;
}
}
F_158 ( & V_12 -> V_71 , V_63 ) ;
for ( V_33 = 0 ; V_33 < V_43 ; V_33 ++ ) {
F_23 ( L_67 , V_313 [ V_33 ] , F_303 ( 1UL ) << V_33 ) ;
if ( V_313 [ V_33 ] )
F_300 ( V_287 [ V_33 ] ) ;
}
F_23 ( L_68 , F_303 ( V_314 ) ) ;
}
F_306 () ;
F_23 ( L_69 , F_293 ( V_315 ) ) ;
F_307 () ;
}
static void F_308 ( struct V_12 * V_12 , struct V_177 * V_177 )
{
V_177 -> V_12 = V_12 ;
V_177 -> F_209 = F_209 ( V_12 ) ;
}
static int F_309 ( T_9 * V_283 , struct V_165 * V_165 ,
int V_316 )
{
struct V_12 * V_12 ;
enum V_226 V_226 = V_284 ;
do {
V_226 -- ;
V_12 = V_283 -> V_285 + V_226 ;
if ( F_310 ( V_12 ) ) {
F_308 ( V_12 ,
& V_165 -> V_179 [ V_316 ++ ] ) ;
F_311 ( V_226 ) ;
}
} while ( V_226 );
return V_316 ;
}
static int F_312 ( char * V_317 )
{
if ( * V_317 == 'd' || * V_317 == 'D' ) {
V_318 = V_319 ;
} else if ( * V_317 == 'n' || * V_317 == 'N' ) {
V_318 = V_320 ;
} else if ( * V_317 == 'z' || * V_317 == 'Z' ) {
V_318 = V_321 ;
} else {
F_23 ( V_322
L_70
L_71 , V_317 ) ;
return - V_323 ;
}
return 0 ;
}
static T_2 int F_313 ( char * V_317 )
{
int V_13 ;
if ( ! V_317 )
return 0 ;
V_13 = F_312 ( V_317 ) ;
if ( V_13 == 0 )
F_314 ( V_324 , V_317 , V_325 ) ;
return V_13 ;
}
int F_315 ( T_10 * V_326 , int V_327 ,
void T_11 * V_328 , T_8 * V_329 ,
T_12 * V_330 )
{
char V_331 [ V_325 ] ;
int V_13 ;
static F_316 ( V_332 ) ;
F_317 ( & V_332 ) ;
if ( V_327 ) {
if ( strlen ( ( char * ) V_326 -> V_333 ) >= V_325 ) {
V_13 = - V_323 ;
goto V_26;
}
strcpy ( V_331 , ( char * ) V_326 -> V_333 ) ;
}
V_13 = F_318 ( V_326 , V_327 , V_328 , V_329 , V_330 ) ;
if ( V_13 )
goto V_26;
if ( V_327 ) {
int V_334 = V_318 ;
V_13 = F_312 ( ( char * ) V_326 -> V_333 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_326 -> V_333 , V_331 ,
V_325 ) ;
V_318 = V_334 ;
} else if ( V_334 != V_318 ) {
F_317 ( & V_335 ) ;
F_319 ( NULL , NULL ) ;
F_320 ( & V_335 ) ;
}
}
V_26:
F_320 ( & V_332 ) ;
return V_13 ;
}
static int F_321 ( int V_182 , T_5 * V_336 )
{
int V_178 , V_273 ;
int V_337 = V_338 ;
int V_339 = V_340 ;
const struct V_341 * V_290 = F_322 ( 0 ) ;
if ( ! F_196 ( V_182 , * V_336 ) ) {
F_206 ( V_182 , * V_336 ) ;
return V_182 ;
}
F_204 (n, N_MEMORY) {
if ( F_196 ( V_178 , * V_336 ) )
continue;
V_273 = F_205 ( V_182 , V_178 ) ;
V_273 += ( V_178 < V_182 ) ;
V_290 = F_322 ( V_178 ) ;
if ( ! F_323 ( V_290 ) )
V_273 += V_342 ;
V_273 *= ( V_343 * V_344 ) ;
V_273 += V_345 [ V_178 ] ;
if ( V_273 < V_337 ) {
V_337 = V_273 ;
V_339 = V_178 ;
}
}
if ( V_339 >= 0 )
F_206 ( V_339 , * V_336 ) ;
return V_339 ;
}
static void F_324 ( T_9 * V_283 , int V_182 )
{
int V_346 ;
struct V_165 * V_165 ;
V_165 = & V_283 -> V_347 [ 0 ] ;
for ( V_346 = 0 ; V_165 -> V_179 [ V_346 ] . V_12 != NULL ; V_346 ++ )
;
V_346 = F_309 ( F_207 ( V_182 ) , V_165 , V_346 ) ;
V_165 -> V_179 [ V_346 ] . V_12 = NULL ;
V_165 -> V_179 [ V_346 ] . F_209 = 0 ;
}
static void F_325 ( T_9 * V_283 )
{
int V_346 ;
struct V_165 * V_165 ;
V_165 = & V_283 -> V_347 [ 1 ] ;
V_346 = F_309 ( V_283 , V_165 , 0 ) ;
V_165 -> V_179 [ V_346 ] . V_12 = NULL ;
V_165 -> V_179 [ V_346 ] . F_209 = 0 ;
}
static void F_326 ( T_9 * V_283 , int V_348 )
{
int V_349 , V_346 , V_182 ;
int V_226 ;
struct V_12 * V_152 ;
struct V_165 * V_165 ;
V_165 = & V_283 -> V_347 [ 0 ] ;
V_349 = 0 ;
for ( V_226 = V_284 - 1 ; V_226 >= 0 ; V_226 -- ) {
for ( V_346 = 0 ; V_346 < V_348 ; V_346 ++ ) {
V_182 = V_350 [ V_346 ] ;
V_152 = & F_207 ( V_182 ) -> V_285 [ V_226 ] ;
if ( F_310 ( V_152 ) ) {
F_308 ( V_152 ,
& V_165 -> V_179 [ V_349 ++ ] ) ;
F_311 ( V_226 ) ;
}
}
}
V_165 -> V_179 [ V_349 ] . V_12 = NULL ;
V_165 -> V_179 [ V_349 ] . F_209 = 0 ;
}
static int F_327 ( void )
{
int V_185 , V_226 ;
unsigned long V_351 , V_352 ;
struct V_12 * V_152 ;
int V_353 ;
V_351 = 0 ;
V_352 = 0 ;
F_328 (nid) {
for ( V_226 = 0 ; V_226 < V_284 ; V_226 ++ ) {
V_152 = & F_207 ( V_185 ) -> V_285 [ V_226 ] ;
if ( F_310 ( V_152 ) ) {
if ( V_226 < V_229 )
V_351 += V_152 -> V_83 ;
V_352 += V_152 -> V_83 ;
} else if ( V_226 == V_229 ) {
return V_320 ;
}
}
}
if ( ! V_351 ||
V_351 > V_352 / 2 )
return V_320 ;
V_353 = V_352 /
( F_329 ( V_175 [ V_176 ] ) + 1 ) ;
F_328 (nid) {
V_351 = 0 ;
V_352 = 0 ;
for ( V_226 = 0 ; V_226 < V_284 ; V_226 ++ ) {
V_152 = & F_207 ( V_185 ) -> V_285 [ V_226 ] ;
if ( F_310 ( V_152 ) ) {
if ( V_226 < V_229 )
V_351 += V_152 -> V_308 ;
V_352 += V_152 -> V_308 ;
}
}
if ( V_351 &&
V_352 > V_353 &&
V_351 > V_352 * 70 / 100 )
return V_320 ;
}
return V_321 ;
}
static void F_330 ( void )
{
if ( V_318 == V_319 )
V_354 = F_327 () ;
else
V_354 = V_318 ;
}
static void F_331 ( T_9 * V_283 )
{
int V_346 , V_182 , V_355 ;
enum V_226 V_34 ;
T_5 V_356 ;
int V_357 , V_358 ;
struct V_165 * V_165 ;
int V_33 = V_354 ;
for ( V_34 = 0 ; V_34 < V_359 ; V_34 ++ ) {
V_165 = V_283 -> V_347 + V_34 ;
V_165 -> V_179 [ 0 ] . V_12 = NULL ;
V_165 -> V_179 [ 0 ] . F_209 = 0 ;
}
V_357 = V_283 -> V_360 ;
V_355 = V_202 ;
V_358 = V_357 ;
F_332 ( V_356 ) ;
memset ( V_350 , 0 , sizeof( V_350 ) ) ;
V_346 = 0 ;
while ( ( V_182 = F_321 ( V_357 , & V_356 ) ) >= 0 ) {
if ( F_205 ( V_357 , V_182 ) !=
F_205 ( V_357 , V_358 ) )
V_345 [ V_182 ] = V_355 ;
V_358 = V_182 ;
V_355 -- ;
if ( V_33 == V_320 )
F_324 ( V_283 , V_182 ) ;
else
V_350 [ V_346 ++ ] = V_182 ;
}
if ( V_33 == V_321 ) {
F_326 ( V_283 , V_346 ) ;
}
F_325 ( V_283 ) ;
}
static void F_333 ( T_9 * V_283 )
{
struct V_165 * V_165 ;
struct V_166 * V_167 ;
struct V_177 * V_152 ;
V_165 = & V_283 -> V_347 [ 0 ] ;
V_165 -> V_169 = V_167 = & V_165 -> V_361 ;
F_194 ( V_167 -> V_171 , V_172 ) ;
for ( V_152 = V_165 -> V_179 ; V_152 -> V_12 ; V_152 ++ )
V_167 -> V_180 [ V_152 - V_165 -> V_179 ] = F_334 ( V_152 ) ;
}
int F_335 ( int V_182 )
{
struct V_12 * V_12 ;
( void ) F_257 ( F_258 ( V_182 , V_269 ) ,
F_263 ( V_269 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_182 ;
}
static void F_330 ( void )
{
V_354 = V_321 ;
}
static void F_331 ( T_9 * V_283 )
{
int V_182 , V_357 ;
enum V_226 V_346 ;
struct V_165 * V_165 ;
V_357 = V_283 -> V_360 ;
V_165 = & V_283 -> V_347 [ 0 ] ;
V_346 = F_309 ( V_283 , V_165 , 0 ) ;
for ( V_182 = V_357 + 1 ; V_182 < V_344 ; V_182 ++ ) {
if ( ! F_336 ( V_182 ) )
continue;
V_346 = F_309 ( F_207 ( V_182 ) , V_165 , V_346 ) ;
}
for ( V_182 = 0 ; V_182 < V_357 ; V_182 ++ ) {
if ( ! F_336 ( V_182 ) )
continue;
V_346 = F_309 ( F_207 ( V_182 ) , V_165 , V_346 ) ;
}
V_165 -> V_179 [ V_346 ] . V_12 = NULL ;
V_165 -> V_179 [ V_346 ] . F_209 = 0 ;
}
static void F_333 ( T_9 * V_283 )
{
V_283 -> V_347 [ 0 ] . V_169 = NULL ;
}
static int F_337 ( void * V_333 )
{
int V_185 ;
int V_115 ;
T_9 * V_362 = V_333 ;
#ifdef V_193
memset ( V_345 , 0 , sizeof( V_345 ) ) ;
#endif
if ( V_362 && ! F_336 ( V_362 -> V_360 ) ) {
F_331 ( V_362 ) ;
F_333 ( V_362 ) ;
}
F_328 (nid) {
T_9 * V_283 = F_207 ( V_185 ) ;
F_331 ( V_283 ) ;
F_333 ( V_283 ) ;
}
F_338 (cpu) {
F_339 ( & F_340 ( V_363 , V_115 ) , 0 ) ;
#ifdef F_341
if ( F_342 ( V_115 ) )
F_343 ( V_115 , F_335 ( F_344 ( V_115 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_319 ( T_9 * V_283 , struct V_12 * V_12 )
{
F_330 () ;
if ( V_364 == V_365 ) {
F_337 ( NULL ) ;
F_345 () ;
F_346 () ;
} else {
#ifdef F_347
if ( V_12 )
F_348 ( V_12 ) ;
#endif
F_349 ( F_337 , V_283 , NULL ) ;
}
V_366 = F_290 () ;
if ( V_366 < ( V_84 * V_288 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_23 ( L_72
L_73 ,
V_202 ,
V_367 [ V_354 ] ,
V_7 ? L_74 : L_75 ,
V_366 ) ;
#ifdef V_193
F_23 ( L_76 , V_368 [ V_369 ] ) ;
#endif
}
static inline unsigned long F_350 ( unsigned long V_105 )
{
unsigned long V_90 = 1 ;
V_105 /= V_370 ;
while ( V_90 < V_105 )
V_90 <<= 1 ;
V_90 = V_157 ( V_90 , 4096UL ) ;
return F_351 ( V_90 , 4UL ) ;
}
static inline unsigned long F_350 ( unsigned long V_105 )
{
return 4096UL ;
}
static inline unsigned long F_352 ( unsigned long V_90 )
{
return F_353 ( ~ V_90 ) ;
}
static int F_354 ( unsigned long V_17 , unsigned long V_98 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 ++ ) {
if ( ! F_16 ( V_15 ) || F_355 ( F_127 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_356 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_98 , V_371 ;
struct V_5 * V_5 ;
unsigned long V_372 ;
int V_373 ;
int V_374 ;
V_17 = V_12 -> V_18 ;
V_98 = F_151 ( V_12 ) ;
V_17 = F_357 ( V_17 , V_84 ) ;
V_373 = F_357 ( F_304 ( V_12 ) , V_84 ) >>
V_86 ;
V_373 = V_157 ( 2 , V_373 ) ;
V_374 = V_12 -> V_375 ;
if ( V_373 == V_374 )
return;
V_12 -> V_375 = V_373 ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 += V_84 ) {
if ( ! F_152 ( V_15 ) )
continue;
V_5 = F_127 ( V_15 ) ;
if ( F_123 ( V_5 ) != F_124 ( V_12 ) )
continue;
V_372 = F_102 ( V_5 ) ;
if ( V_373 > 0 ) {
V_371 = V_157 ( V_15 + V_84 , V_98 ) ;
if ( F_354 ( V_15 , V_371 ) )
continue;
if ( V_372 == V_109 ) {
V_373 -- ;
continue;
}
if ( V_372 == V_125 ) {
F_6 ( V_5 ,
V_109 ) ;
F_126 ( V_12 , V_5 ,
V_109 ) ;
V_373 -- ;
continue;
}
} else if ( ! V_374 ) {
break;
}
if ( V_372 == V_109 ) {
F_6 ( V_5 , V_125 ) ;
F_126 ( V_12 , V_5 , V_125 ) ;
}
}
}
void T_14 F_358 ( unsigned long V_90 , int V_185 , unsigned long V_12 ,
unsigned long V_17 , enum V_376 V_377 )
{
struct V_5 * V_5 ;
unsigned long V_98 = V_17 + V_90 ;
unsigned long V_15 ;
struct V_12 * V_152 ;
if ( V_378 < V_98 - 1 )
V_378 = V_98 - 1 ;
V_152 = & F_207 ( V_185 ) -> V_285 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 ++ ) {
if ( V_377 == V_379 ) {
if ( ! F_359 ( V_15 ) )
continue;
if ( ! F_360 ( V_15 , V_185 ) )
continue;
}
V_5 = F_127 ( V_15 ) ;
F_361 ( V_5 , V_12 , V_185 , V_15 ) ;
F_362 ( V_5 , V_12 , V_185 , V_15 ) ;
F_363 ( V_5 ) ;
F_21 ( V_5 ) ;
F_76 ( V_5 ) ;
F_364 ( V_5 ) ;
if ( ( V_152 -> V_18 <= V_15 )
&& ( V_15 < F_151 ( V_152 ) )
&& ! ( V_15 & ( V_84 - 1 ) ) )
F_6 ( V_5 , V_125 ) ;
F_115 ( & V_5 -> V_54 ) ;
#ifdef F_365
if ( ! F_366 ( V_12 ) )
F_367 ( V_5 , F_368 ( V_15 << V_380 ) ) ;
#endif
}
}
static void T_14 F_369 ( struct V_12 * V_12 )
{
int V_33 , V_123 ;
F_155 (order, t) {
F_115 ( & V_12 -> V_55 [ V_33 ] . V_59 [ V_123 ] ) ;
V_12 -> V_55 [ V_33 ] . V_56 = 0 ;
}
}
static int T_14 F_370 ( struct V_12 * V_12 )
{
#ifdef F_371
int V_114 ;
V_114 = V_12 -> V_83 / 1024 ;
if ( V_114 * V_80 > 512 * 1024 )
V_114 = ( 512 * 1024 ) / V_80 ;
V_114 /= 4 ;
if ( V_114 < 1 )
V_114 = 1 ;
V_114 = F_372 ( V_114 + V_114 / 2 ) - 1 ;
return V_114 ;
#else
return 0 ;
#endif
}
static void F_373 ( struct V_67 * V_68 , unsigned long V_88 ,
unsigned long V_114 )
{
V_68 -> V_114 = 1 ;
F_36 () ;
V_68 -> V_88 = V_88 ;
F_36 () ;
V_68 -> V_114 = V_114 ;
}
static void F_374 ( struct V_116 * V_36 , unsigned long V_114 )
{
F_373 ( & V_36 -> V_68 , 6 * V_114 , F_351 ( 1UL , 1 * V_114 ) ) ;
}
static void F_375 ( struct V_116 * V_36 )
{
struct V_67 * V_68 ;
int V_6 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_68 = & V_36 -> V_68 ;
V_68 -> V_66 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_115 ( & V_68 -> V_75 [ V_6 ] ) ;
}
static void F_339 ( struct V_116 * V_36 , unsigned long V_114 )
{
F_375 ( V_36 ) ;
F_374 ( V_36 , V_114 ) ;
}
static void F_376 ( struct V_116 * V_36 ,
unsigned long V_88 )
{
unsigned long V_114 = F_351 ( 1UL , V_88 / 4 ) ;
if ( ( V_88 / 4 ) > ( V_380 * 8 ) )
V_114 = V_380 * 8 ;
F_373 ( & V_36 -> V_68 , V_88 , V_114 ) ;
}
static void T_14 F_377 ( struct V_12 * V_12 ,
struct V_116 * V_68 )
{
if ( V_381 )
F_376 ( V_68 ,
( V_12 -> V_83 /
V_381 ) ) ;
else
F_374 ( V_68 , F_370 ( V_12 ) ) ;
}
static void T_14 F_378 ( struct V_12 * V_12 , int V_115 )
{
struct V_116 * V_68 = F_140 ( V_12 -> V_118 , V_115 ) ;
F_375 ( V_68 ) ;
F_377 ( V_12 , V_68 ) ;
}
static void T_14 F_348 ( struct V_12 * V_12 )
{
int V_115 ;
V_12 -> V_118 = F_379 ( struct V_116 ) ;
F_338 (cpu)
F_378 ( V_12 , V_115 ) ;
}
void T_2 F_380 ( void )
{
struct V_12 * V_12 ;
F_139 (zone)
F_348 ( V_12 ) ;
}
static T_15 T_16
int F_381 ( struct V_12 * V_12 , unsigned long V_382 )
{
int V_34 ;
T_8 V_383 ;
V_12 -> F_350 =
F_350 ( V_382 ) ;
V_12 -> F_352 =
F_352 ( V_12 -> F_350 ) ;
V_383 = V_12 -> F_350
* sizeof( V_384 ) ;
if ( ! F_382 () ) {
V_12 -> V_385 = ( V_384 * )
F_383 (
V_383 , V_12 -> V_183 -> V_360 ) ;
} else {
V_12 -> V_385 = F_384 ( V_383 ) ;
}
if ( ! V_12 -> V_385 )
return - V_151 ;
for ( V_34 = 0 ; V_34 < V_12 -> F_350 ; ++ V_34 )
F_385 ( V_12 -> V_385 + V_34 ) ;
return 0 ;
}
static T_14 void F_386 ( struct V_12 * V_12 )
{
V_12 -> V_118 = & V_363 ;
if ( F_310 ( V_12 ) )
F_23 ( V_386 L_77 ,
V_12 -> V_291 , V_12 -> V_308 ,
F_370 ( V_12 ) ) ;
}
int T_14 F_387 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_90 ,
enum V_376 V_377 )
{
struct V_387 * V_283 = V_12 -> V_183 ;
int V_13 ;
V_13 = F_381 ( V_12 , V_90 ) ;
if ( V_13 )
return V_13 ;
V_283 -> V_316 = F_209 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_388 ( V_388 , L_78 ,
L_79 ,
V_283 -> V_360 ,
( unsigned long ) F_209 ( V_12 ) ,
V_18 , ( V_18 + V_90 ) ) ;
F_369 ( V_12 ) ;
return 0 ;
}
int T_14 F_389 ( unsigned long V_15 )
{
unsigned long V_17 , V_98 ;
int V_185 ;
static unsigned long T_17 V_389 , V_390 ;
static int T_17 V_391 ;
if ( V_389 <= V_15 && V_15 < V_390 )
return V_391 ;
V_185 = F_390 ( V_15 , & V_17 , & V_98 ) ;
if ( V_185 != - 1 ) {
V_389 = V_17 ;
V_390 = V_98 ;
V_391 = V_185 ;
}
return V_185 ;
}
int T_14 F_391 ( unsigned long V_15 )
{
int V_185 ;
V_185 = F_389 ( V_15 ) ;
if ( V_185 >= 0 )
return V_185 ;
return 0 ;
}
bool T_14 F_360 ( unsigned long V_15 , int V_182 )
{
int V_185 ;
V_185 = F_389 ( V_15 ) ;
if ( V_185 >= 0 && V_185 != V_182 )
return false ;
return true ;
}
void T_2 F_392 ( int V_185 , unsigned long V_392 )
{
unsigned long V_17 , V_98 ;
int V_34 , V_393 ;
F_393 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = V_157 ( V_17 , V_392 ) ;
V_98 = V_157 ( V_98 , V_392 ) ;
if ( V_17 < V_98 )
F_394 ( F_395 ( V_17 ) ,
( V_98 - V_17 ) << V_380 ,
V_393 ) ;
}
}
void T_2 F_396 ( int V_185 )
{
unsigned long V_17 , V_98 ;
int V_34 , V_393 ;
F_393 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_397 ( V_393 , V_17 , V_98 ) ;
}
void T_14 F_398 ( unsigned int V_185 ,
unsigned long * V_17 , unsigned long * V_98 )
{
unsigned long V_394 , V_395 ;
int V_34 ;
* V_17 = - 1UL ;
* V_98 = 0 ;
F_393 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = V_157 ( * V_17 , V_394 ) ;
* V_98 = F_351 ( * V_98 , V_395 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_399 ( void )
{
int V_396 ;
for ( V_396 = V_284 - 1 ; V_396 >= 0 ; V_396 -- ) {
if ( V_396 == V_397 )
continue;
if ( V_398 [ V_396 ] >
V_399 [ V_396 ] )
break;
}
F_43 ( V_396 == - 1 ) ;
V_400 = V_396 ;
}
static void T_14 F_400 ( int V_185 ,
unsigned long V_226 ,
unsigned long V_401 ,
unsigned long V_402 ,
unsigned long * V_18 ,
unsigned long * F_151 )
{
if ( V_403 [ V_185 ] ) {
if ( V_226 == V_397 ) {
* V_18 = V_403 [ V_185 ] ;
* F_151 = V_157 ( V_402 ,
V_398 [ V_400 ] ) ;
} else if ( * V_18 < V_403 [ V_185 ] &&
* F_151 > V_403 [ V_185 ] ) {
* F_151 = V_403 [ V_185 ] ;
} else if ( * V_18 >= V_403 [ V_185 ] )
* V_18 = * F_151 ;
}
}
static unsigned long T_14 F_401 ( int V_185 ,
unsigned long V_226 ,
unsigned long V_401 ,
unsigned long V_402 ,
unsigned long * V_404 )
{
unsigned long V_18 , F_151 ;
V_18 = V_399 [ V_226 ] ;
F_151 = V_398 [ V_226 ] ;
F_400 ( V_185 , V_226 ,
V_401 , V_402 ,
& V_18 , & F_151 ) ;
if ( F_151 < V_401 || V_18 > V_402 )
return 0 ;
F_151 = V_157 ( F_151 , V_402 ) ;
V_18 = F_351 ( V_18 , V_401 ) ;
return F_151 - V_18 ;
}
unsigned long T_14 F_402 ( int V_185 ,
unsigned long V_405 ,
unsigned long V_406 )
{
unsigned long V_407 = V_406 - V_405 ;
unsigned long V_17 , V_98 ;
int V_34 ;
F_393 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_403 ( V_17 , V_405 , V_406 ) ;
V_98 = F_403 ( V_98 , V_405 , V_406 ) ;
V_407 -= V_98 - V_17 ;
}
return V_407 ;
}
unsigned long T_2 F_404 ( unsigned long V_17 ,
unsigned long V_98 )
{
return F_402 ( V_344 , V_17 , V_98 ) ;
}
static unsigned long T_14 F_405 ( int V_185 ,
unsigned long V_226 ,
unsigned long V_401 ,
unsigned long V_402 ,
unsigned long * V_404 )
{
unsigned long V_408 = V_399 [ V_226 ] ;
unsigned long V_409 = V_398 [ V_226 ] ;
unsigned long V_18 , F_151 ;
V_18 = F_403 ( V_401 , V_408 , V_409 ) ;
F_151 = F_403 ( V_402 , V_408 , V_409 ) ;
F_400 ( V_185 , V_226 ,
V_401 , V_402 ,
& V_18 , & F_151 ) ;
return F_402 ( V_185 , V_18 , F_151 ) ;
}
static inline unsigned long T_14 F_401 ( int V_185 ,
unsigned long V_226 ,
unsigned long V_401 ,
unsigned long V_402 ,
unsigned long * V_410 )
{
return V_410 [ V_226 ] ;
}
static inline unsigned long T_14 F_405 ( int V_185 ,
unsigned long V_226 ,
unsigned long V_401 ,
unsigned long V_402 ,
unsigned long * V_411 )
{
if ( ! V_411 )
return 0 ;
return V_411 [ V_226 ] ;
}
static void T_14 F_406 ( struct V_387 * V_283 ,
unsigned long V_401 ,
unsigned long V_402 ,
unsigned long * V_410 ,
unsigned long * V_411 )
{
unsigned long V_412 , V_413 = 0 ;
enum V_226 V_34 ;
for ( V_34 = 0 ; V_34 < V_284 ; V_34 ++ )
V_413 += F_401 ( V_283 -> V_360 , V_34 ,
V_401 ,
V_402 ,
V_410 ) ;
V_283 -> V_414 = V_413 ;
V_412 = V_413 ;
for ( V_34 = 0 ; V_34 < V_284 ; V_34 ++ )
V_412 -=
F_405 ( V_283 -> V_360 , V_34 ,
V_401 , V_402 ,
V_411 ) ;
V_283 -> V_415 = V_412 ;
F_23 ( V_386 L_80 , V_283 -> V_360 ,
V_412 ) ;
}
static unsigned long T_2 F_407 ( unsigned long V_18 , unsigned long V_416 )
{
unsigned long V_417 ;
V_416 += V_18 & ( V_84 - 1 ) ;
V_417 = F_357 ( V_416 , V_84 ) ;
V_417 = V_417 >> V_86 ;
V_417 *= V_418 ;
V_417 = F_357 ( V_417 , 8 * sizeof( unsigned long ) ) ;
return V_417 / 8 ;
}
static void T_2 F_408 ( struct V_387 * V_283 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_416 )
{
unsigned long V_417 = F_407 ( V_18 , V_416 ) ;
V_12 -> V_419 = NULL ;
if ( V_417 )
V_12 -> V_419 =
F_383 ( V_417 ,
V_283 -> V_360 ) ;
}
static inline void F_408 ( struct V_387 * V_283 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_416 ) {}
void T_6 F_409 ( void )
{
unsigned int V_33 ;
if ( V_86 )
return;
if ( V_420 > V_380 )
V_33 = V_421 ;
else
V_33 = V_43 - 1 ;
V_86 = V_33 ;
}
void T_6 F_409 ( void )
{
}
static unsigned long T_6 F_410 ( unsigned long V_19 ,
unsigned long V_308 )
{
unsigned long V_105 = V_19 ;
if ( V_19 > V_308 + ( V_308 >> 4 ) &&
F_135 ( V_422 ) )
V_105 = V_308 ;
return F_281 ( V_105 * sizeof( struct V_5 ) ) >> V_380 ;
}
static void T_6 F_411 ( struct V_387 * V_283 ,
unsigned long V_401 , unsigned long V_402 ,
unsigned long * V_410 , unsigned long * V_411 )
{
enum V_226 V_346 ;
int V_185 = V_283 -> V_360 ;
unsigned long V_18 = V_283 -> V_401 ;
int V_13 ;
F_412 ( V_283 ) ;
#ifdef F_413
F_414 ( & V_283 -> V_423 ) ;
V_283 -> V_424 = 0 ;
V_283 -> V_425 = V_25 ;
#endif
F_385 ( & V_283 -> V_426 ) ;
F_385 ( & V_283 -> V_427 ) ;
F_415 ( V_283 ) ;
for ( V_346 = 0 ; V_346 < V_284 ; V_346 ++ ) {
struct V_12 * V_12 = V_283 -> V_285 + V_346 ;
unsigned long V_90 , V_428 , V_429 , V_430 ;
V_90 = F_401 ( V_185 , V_346 , V_401 ,
V_402 , V_410 ) ;
V_428 = V_429 = V_90 - F_405 ( V_185 , V_346 ,
V_401 ,
V_402 ,
V_411 ) ;
V_430 = F_410 ( V_90 , V_428 ) ;
if ( V_429 >= V_430 ) {
V_429 -= V_430 ;
if ( V_430 )
F_23 ( V_386
L_81 ,
V_368 [ V_346 ] , V_430 ) ;
} else
F_23 ( V_322
L_82 ,
V_368 [ V_346 ] , V_430 , V_429 ) ;
if ( V_346 == 0 && V_429 > V_431 ) {
V_429 -= V_431 ;
F_23 ( V_386 L_83 ,
V_368 [ 0 ] , V_431 ) ;
}
if ( ! F_366 ( V_346 ) )
V_432 += V_429 ;
else if ( V_432 > V_430 * 2 )
V_432 -= V_430 ;
V_433 += V_429 ;
V_12 -> V_19 = V_90 ;
V_12 -> V_308 = V_428 ;
V_12 -> V_83 = F_366 ( V_346 ) ? V_428 : V_429 ;
#ifdef V_193
V_12 -> V_182 = V_185 ;
V_12 -> V_434 = ( V_429 * V_435 )
/ 100 ;
V_12 -> V_436 = ( V_429 * V_437 ) / 100 ;
#endif
V_12 -> V_291 = V_368 [ V_346 ] ;
F_414 ( & V_12 -> V_71 ) ;
F_414 ( & V_12 -> V_438 ) ;
F_416 ( V_12 ) ;
V_12 -> V_183 = V_283 ;
F_386 ( V_12 ) ;
F_246 ( V_12 , V_134 , V_12 -> V_83 ) ;
F_417 ( & V_12 -> V_439 ) ;
if ( ! V_90 )
continue;
F_409 () ;
F_408 ( V_283 , V_12 , V_18 , V_90 ) ;
V_13 = F_387 ( V_12 , V_18 ,
V_90 , V_379 ) ;
F_122 ( V_13 ) ;
F_418 ( V_90 , V_185 , V_346 , V_18 ) ;
V_18 += V_90 ;
}
}
static void T_16 F_419 ( struct V_387 * V_283 )
{
if ( ! V_283 -> V_414 )
return;
#ifdef F_420
if ( ! V_283 -> V_440 ) {
unsigned long V_90 , V_441 , V_266 ;
struct V_5 * V_442 ;
V_441 = V_283 -> V_401 & ~ ( V_443 - 1 ) ;
V_266 = F_421 ( V_283 ) ;
V_266 = F_422 ( V_266 , V_443 ) ;
V_90 = ( V_266 - V_441 ) * sizeof( struct V_5 ) ;
V_442 = F_423 ( V_283 -> V_360 , V_90 ) ;
if ( ! V_442 )
V_442 = F_383 ( V_90 ,
V_283 -> V_360 ) ;
V_283 -> V_440 = V_442 + ( V_283 -> V_401 - V_441 ) ;
}
#ifndef F_424
if ( V_283 == F_207 ( 0 ) ) {
V_444 = F_207 ( 0 ) -> V_440 ;
#ifdef F_425
if ( F_10 ( V_444 ) != V_283 -> V_401 )
V_444 -= ( V_283 -> V_401 - V_445 ) ;
#endif
}
#endif
#endif
}
void T_6 F_426 ( int V_185 , unsigned long * V_410 ,
unsigned long V_401 , unsigned long * V_411 )
{
T_9 * V_283 = F_207 ( V_185 ) ;
unsigned long V_17 = 0 ;
unsigned long V_98 = 0 ;
F_2 ( V_283 -> V_316 || V_283 -> V_154 ) ;
V_283 -> V_360 = V_185 ;
V_283 -> V_401 = V_401 ;
if ( F_427 ( V_185 , V_176 ) )
F_203 ( V_185 ) ;
#ifdef F_425
F_398 ( V_185 , & V_17 , & V_98 ) ;
#endif
F_406 ( V_283 , V_17 , V_98 ,
V_410 , V_411 ) ;
F_419 ( V_283 ) ;
#ifdef F_420
F_23 ( V_386 L_84 ,
V_185 , ( unsigned long ) V_283 ,
( unsigned long ) V_283 -> V_440 ) ;
#endif
F_411 ( V_283 , V_17 , V_98 ,
V_410 , V_411 ) ;
}
void T_2 F_428 ( void )
{
unsigned int V_182 ;
unsigned int V_446 = 0 ;
F_429 (node, node_possible_map)
V_446 = V_182 ;
V_447 = V_446 + 1 ;
}
unsigned long T_2 F_430 ( void )
{
unsigned long V_448 = 0 , V_449 = 0 ;
unsigned long V_441 , V_266 , V_450 ;
int V_391 = - 1 ;
int V_34 , V_185 ;
F_393 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_441 || V_391 < 0 || V_391 == V_185 ) {
V_391 = V_185 ;
V_449 = V_266 ;
continue;
}
V_450 = ~ ( ( 1 << F_431 ( V_441 ) ) - 1 ) ;
while ( V_450 && V_449 <= ( V_441 & ( V_450 << 1 ) ) )
V_450 <<= 1 ;
V_448 |= V_450 ;
}
return ~ V_448 + 1 ;
}
static unsigned long T_2 F_432 ( int V_185 )
{
unsigned long V_451 = V_452 ;
unsigned long V_17 ;
int V_34 ;
F_393 (i, nid, &start_pfn, NULL, NULL)
V_451 = V_157 ( V_451 , V_17 ) ;
if ( V_451 == V_452 ) {
F_23 ( V_322
L_85 , V_185 ) ;
return 0 ;
}
return V_451 ;
}
unsigned long T_2 F_433 ( void )
{
return F_432 ( V_344 ) ;
}
static unsigned long T_2 F_434 ( void )
{
unsigned long V_413 = 0 ;
unsigned long V_17 , V_98 ;
int V_34 , V_185 ;
F_393 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_105 = V_98 - V_17 ;
V_413 += V_105 ;
if ( V_105 )
F_435 ( V_185 , V_176 ) ;
}
return V_413 ;
}
static void T_2 F_436 ( void )
{
int V_34 , V_185 ;
unsigned long V_453 ;
unsigned long V_454 , V_455 ;
T_5 V_456 = V_175 [ V_176 ] ;
unsigned long V_413 = F_434 () ;
int V_457 = F_329 ( V_175 [ V_176 ] ) ;
struct V_458 * V_459 ;
F_399 () ;
if ( F_437 () ) {
F_438 (memory, r) {
if ( ! F_439 ( V_459 ) )
continue;
V_185 = V_459 -> V_185 ;
V_453 = F_440 ( V_459 -> V_460 ) ;
V_403 [ V_185 ] = V_403 [ V_185 ] ?
V_157 ( V_453 , V_403 [ V_185 ] ) :
V_453 ;
}
goto V_461;
}
if ( V_462 ) {
unsigned long V_463 ;
V_462 =
F_357 ( V_462 , V_443 ) ;
V_463 = V_413 - V_462 ;
V_464 = F_351 ( V_464 , V_463 ) ;
}
if ( ! V_464 )
goto V_26;
V_453 = V_399 [ V_400 ] ;
V_251:
V_454 = V_464 / V_457 ;
F_204 (nid, N_MEMORY) {
unsigned long V_17 , V_98 ;
if ( V_464 < V_454 )
V_454 = V_464 / V_457 ;
V_455 = V_454 ;
F_393 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_465 ;
V_17 = F_351 ( V_17 , V_403 [ V_185 ] ) ;
if ( V_17 >= V_98 )
continue;
if ( V_17 < V_453 ) {
unsigned long V_466 ;
V_466 = V_157 ( V_98 , V_453 )
- V_17 ;
V_455 -= V_157 ( V_466 ,
V_455 ) ;
V_464 -= V_157 ( V_466 ,
V_464 ) ;
if ( V_98 <= V_453 ) {
V_403 [ V_185 ] = V_98 ;
continue;
}
V_17 = V_453 ;
}
V_465 = V_98 - V_17 ;
if ( V_465 > V_455 )
V_465 = V_455 ;
V_403 [ V_185 ] = V_17 + V_465 ;
V_464 -= V_157 ( V_464 ,
V_465 ) ;
V_455 -= V_465 ;
if ( ! V_455 )
break;
}
}
V_457 -- ;
if ( V_457 && V_464 > V_457 )
goto V_251;
V_461:
for ( V_185 = 0 ; V_185 < V_344 ; V_185 ++ )
V_403 [ V_185 ] =
F_357 ( V_403 [ V_185 ] , V_443 ) ;
V_26:
V_175 [ V_176 ] = V_456 ;
}
static void F_441 ( T_9 * V_283 , int V_185 )
{
enum V_226 V_226 ;
if ( V_176 == V_467 )
return;
for ( V_226 = 0 ; V_226 <= V_397 - 1 ; V_226 ++ ) {
struct V_12 * V_12 = & V_283 -> V_285 [ V_226 ] ;
if ( F_310 ( V_12 ) ) {
F_435 ( V_185 , V_468 ) ;
if ( V_467 != V_468 &&
V_226 <= V_229 )
F_435 ( V_185 , V_467 ) ;
break;
}
}
}
void T_2 F_442 ( unsigned long * V_122 )
{
unsigned long V_17 , V_98 ;
int V_34 , V_185 ;
memset ( V_399 , 0 ,
sizeof( V_399 ) ) ;
memset ( V_398 , 0 ,
sizeof( V_398 ) ) ;
V_399 [ 0 ] = F_433 () ;
V_398 [ 0 ] = V_122 [ 0 ] ;
for ( V_34 = 1 ; V_34 < V_284 ; V_34 ++ ) {
if ( V_34 == V_397 )
continue;
V_399 [ V_34 ] =
V_398 [ V_34 - 1 ] ;
V_398 [ V_34 ] =
F_351 ( V_122 [ V_34 ] , V_399 [ V_34 ] ) ;
}
V_399 [ V_397 ] = 0 ;
V_398 [ V_397 ] = 0 ;
memset ( V_403 , 0 , sizeof( V_403 ) ) ;
F_436 () ;
F_23 ( L_86 ) ;
for ( V_34 = 0 ; V_34 < V_284 ; V_34 ++ ) {
if ( V_34 == V_397 )
continue;
F_23 ( V_469 L_87 , V_368 [ V_34 ] ) ;
if ( V_399 [ V_34 ] ==
V_398 [ V_34 ] )
F_23 ( V_469 L_88 ) ;
else
F_23 ( V_469 L_89 ,
V_399 [ V_34 ] << V_380 ,
( V_398 [ V_34 ]
<< V_380 ) - 1 ) ;
}
F_23 ( L_90 ) ;
for ( V_34 = 0 ; V_34 < V_344 ; V_34 ++ ) {
if ( V_403 [ V_34 ] )
F_23 ( L_91 , V_34 ,
V_403 [ V_34 ] << V_380 ) ;
}
F_23 ( L_92 ) ;
F_393 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_23 ( L_93 , V_185 ,
V_17 << V_380 , ( V_98 << V_380 ) - 1 ) ;
F_443 () ;
F_428 () ;
F_328 (nid) {
T_9 * V_283 = F_207 ( V_185 ) ;
F_426 ( V_185 , NULL ,
F_432 ( V_185 ) , NULL ) ;
if ( V_283 -> V_415 )
F_435 ( V_185 , V_176 ) ;
F_441 ( V_283 , V_185 ) ;
}
}
static int T_2 F_444 ( char * V_36 , unsigned long * V_470 )
{
unsigned long long V_471 ;
if ( ! V_36 )
return - V_323 ;
V_471 = F_445 ( V_36 , & V_36 ) ;
* V_470 = V_471 >> V_380 ;
F_2 ( ( V_471 >> V_380 ) > V_452 ) ;
return 0 ;
}
static int T_2 F_446 ( char * V_36 )
{
return F_444 ( V_36 , & V_464 ) ;
}
static int T_2 F_447 ( char * V_36 )
{
return F_444 ( V_36 , & V_462 ) ;
}
void F_111 ( struct V_5 * V_5 , long V_66 )
{
F_78 ( & V_472 ) ;
F_17 ( V_5 ) -> V_83 += V_66 ;
V_275 += V_66 ;
#ifdef F_298
if ( F_94 ( V_5 ) )
V_280 += V_66 ;
#endif
F_87 ( & V_472 ) ;
}
unsigned long F_448 ( void * V_441 , void * V_266 , int V_473 , char * V_317 )
{
void * V_349 ;
unsigned long V_105 = 0 ;
V_441 = ( void * ) F_281 ( ( unsigned long ) V_441 ) ;
V_266 = ( void * ) ( ( unsigned long ) V_266 & V_474 ) ;
for ( V_349 = V_441 ; V_349 < V_266 ; V_349 += V_80 , V_105 ++ ) {
if ( ( unsigned int ) V_473 <= 0xFF )
memset ( V_349 , V_473 , V_80 ) ;
F_449 ( F_168 ( V_349 ) ) ;
}
if ( V_105 && V_317 )
F_450 ( L_94 ,
V_317 , V_105 << ( V_380 - 10 ) , V_441 , V_266 ) ;
return V_105 ;
}
void F_451 ( struct V_5 * V_5 )
{
F_452 ( V_5 ) ;
V_275 ++ ;
F_17 ( V_5 ) -> V_83 ++ ;
V_280 ++ ;
}
void T_2 F_453 ( const char * V_136 )
{
unsigned long V_475 , V_476 , V_477 , V_478 , V_479 ;
unsigned long V_480 , V_481 ;
V_475 = F_454 () ;
V_476 = V_482 - V_483 ;
V_477 = V_484 - V_485 ;
V_478 = V_486 - V_487 ;
V_479 = V_488 - V_489 ;
V_481 = V_490 - V_491 ;
V_480 = V_492 - V_493 ;
#define F_455 ( V_441 , V_266 , V_90 , V_349 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_455 ( V_491 , V_490 , V_481 ,
V_493 , V_480 ) ;
F_455 ( V_483 , V_482 , V_476 , V_493 , V_480 ) ;
F_455 ( V_485 , V_484 , V_477 , V_491 , V_481 ) ;
F_455 ( V_483 , V_482 , V_476 , V_487 , V_478 ) ;
F_455 ( V_485 , V_484 , V_477 , V_487 , V_478 ) ;
#undef F_455
F_23 ( L_95
L_96
L_97
#ifdef F_298
L_98
#endif
L_99 ,
F_456 () << ( V_380 - 10 ) , V_475 << ( V_380 - 10 ) ,
V_476 >> 10 , V_477 >> 10 , V_478 >> 10 ,
( V_481 + V_480 ) >> 10 , V_479 >> 10 ,
( V_475 - V_275 ) << ( V_380 - 10 ) ,
#ifdef F_298
V_280 << ( V_380 - 10 ) ,
#endif
V_136 ? L_100 : L_101 , V_136 ? V_136 : L_101 ) ;
}
void T_2 F_457 ( unsigned long V_494 )
{
V_431 = V_494 ;
}
void T_2 F_458 ( unsigned long * V_410 )
{
F_426 ( 0 , V_410 ,
F_459 ( V_495 ) >> V_380 , NULL ) ;
}
static int F_460 ( struct V_496 * V_362 ,
unsigned long V_497 , void * V_498 )
{
int V_115 = ( unsigned long ) V_498 ;
if ( V_497 == V_499 || V_497 == V_500 ) {
F_461 ( V_115 ) ;
F_138 ( V_115 ) ;
F_462 ( V_115 ) ;
F_463 ( V_115 ) ;
}
return V_501 ;
}
void T_2 F_464 ( void )
{
F_465 ( F_460 , 0 ) ;
}
static void F_466 ( void )
{
struct V_387 * V_283 ;
unsigned long V_502 = 0 ;
enum V_226 V_34 , V_346 ;
F_467 (pgdat) {
for ( V_34 = 0 ; V_34 < V_284 ; V_34 ++ ) {
struct V_12 * V_12 = V_283 -> V_285 + V_34 ;
unsigned long F_351 = 0 ;
for ( V_346 = V_34 ; V_346 < V_284 ; V_346 ++ ) {
if ( V_12 -> V_158 [ V_346 ] > F_351 )
F_351 = V_12 -> V_158 [ V_346 ] ;
}
F_351 += F_247 ( V_12 ) ;
if ( F_351 > V_12 -> V_83 )
F_351 = V_12 -> V_83 ;
V_502 += F_351 ;
V_12 -> V_503 = F_351 ;
}
}
V_503 = V_502 ;
V_504 = V_502 ;
}
static void F_468 ( void )
{
struct V_387 * V_283 ;
enum V_226 V_346 , V_505 ;
F_467 (pgdat) {
for ( V_346 = 0 ; V_346 < V_284 ; V_346 ++ ) {
struct V_12 * V_12 = V_283 -> V_285 + V_346 ;
unsigned long V_83 = V_12 -> V_83 ;
V_12 -> V_158 [ V_346 ] = 0 ;
V_505 = V_346 ;
while ( V_505 ) {
struct V_12 * V_506 ;
V_505 -- ;
if ( V_507 [ V_505 ] < 1 )
V_507 [ V_505 ] = 1 ;
V_506 = V_283 -> V_285 + V_505 ;
V_506 -> V_158 [ V_346 ] = V_83 /
V_507 [ V_505 ] ;
V_83 += V_506 -> V_83 ;
}
}
}
F_466 () ;
}
static void F_469 ( void )
{
unsigned long V_508 = V_509 >> ( V_380 - 10 ) ;
unsigned long V_510 = 0 ;
struct V_12 * V_12 ;
unsigned long V_63 ;
F_470 (zone) {
if ( ! F_471 ( V_12 ) )
V_510 += V_12 -> V_83 ;
}
F_470 (zone) {
T_19 V_290 ;
F_150 ( & V_12 -> V_71 , V_63 ) ;
V_290 = ( T_19 ) V_508 * V_12 -> V_83 ;
F_472 ( V_290 , V_510 ) ;
if ( F_471 ( V_12 ) ) {
unsigned long V_511 ;
V_511 = V_12 -> V_83 / 1024 ;
V_511 = F_403 ( V_511 , V_512 , 128UL ) ;
V_12 -> V_127 [ V_513 ] = V_511 ;
} else {
V_12 -> V_127 [ V_513 ] = V_290 ;
}
V_12 -> V_127 [ V_514 ] = F_304 ( V_12 ) + ( V_290 >> 2 ) ;
V_12 -> V_127 [ V_515 ] = F_304 ( V_12 ) + ( V_290 >> 1 ) ;
F_85 ( V_12 , V_134 ,
F_247 ( V_12 ) -
F_170 ( V_12 ) -
F_189 ( V_12 , V_134 ) ) ;
F_356 ( V_12 ) ;
F_158 ( & V_12 -> V_71 , V_63 ) ;
}
F_466 () ;
}
void F_473 ( void )
{
F_317 ( & V_335 ) ;
F_469 () ;
F_320 ( & V_335 ) ;
}
static void T_14 F_474 ( struct V_12 * V_12 )
{
unsigned int V_516 , V_517 ;
V_516 = V_12 -> V_83 >> ( 30 - V_380 ) ;
if ( V_516 )
V_517 = F_475 ( 10 * V_516 ) ;
else
V_517 = 1 ;
V_12 -> V_518 = V_517 ;
}
static void T_14 F_476 ( void )
{
struct V_12 * V_12 ;
F_470 (zone)
F_474 ( V_12 ) ;
}
int T_14 F_477 ( void )
{
unsigned long V_519 ;
int V_520 ;
V_519 = F_289 () * ( V_80 >> 10 ) ;
V_520 = F_475 ( V_519 * 16 ) ;
if ( V_520 > V_521 ) {
V_509 = V_520 ;
if ( V_509 < 128 )
V_509 = 128 ;
if ( V_509 > 65536 )
V_509 = 65536 ;
} else {
F_219 ( L_102 ,
V_520 , V_521 ) ;
}
F_473 () ;
F_478 () ;
F_468 () ;
F_476 () ;
return 0 ;
}
int F_479 ( T_10 * V_326 , int V_327 ,
void T_11 * V_328 , T_8 * V_329 , T_12 * V_330 )
{
int V_522 ;
V_522 = F_480 ( V_326 , V_327 , V_328 , V_329 , V_330 ) ;
if ( V_522 )
return V_522 ;
if ( V_327 ) {
V_521 = V_509 ;
F_473 () ;
}
return 0 ;
}
int F_481 ( T_10 * V_326 , int V_327 ,
void T_11 * V_328 , T_8 * V_329 , T_12 * V_330 )
{
struct V_12 * V_12 ;
int V_522 ;
V_522 = F_480 ( V_326 , V_327 , V_328 , V_329 , V_330 ) ;
if ( V_522 )
return V_522 ;
F_470 (zone)
V_12 -> V_434 = ( V_12 -> V_83 *
V_435 ) / 100 ;
return 0 ;
}
int F_482 ( T_10 * V_326 , int V_327 ,
void T_11 * V_328 , T_8 * V_329 , T_12 * V_330 )
{
struct V_12 * V_12 ;
int V_522 ;
V_522 = F_480 ( V_326 , V_327 , V_328 , V_329 , V_330 ) ;
if ( V_522 )
return V_522 ;
F_470 (zone)
V_12 -> V_436 = ( V_12 -> V_83 *
V_437 ) / 100 ;
return 0 ;
}
int F_483 ( T_10 * V_326 , int V_327 ,
void T_11 * V_328 , T_8 * V_329 , T_12 * V_330 )
{
F_480 ( V_326 , V_327 , V_328 , V_329 , V_330 ) ;
F_468 () ;
return 0 ;
}
int F_484 ( T_10 * V_326 , int V_327 ,
void T_11 * V_328 , T_8 * V_329 , T_12 * V_330 )
{
struct V_12 * V_12 ;
unsigned int V_115 ;
int V_13 ;
V_13 = F_480 ( V_326 , V_327 , V_328 , V_329 , V_330 ) ;
if ( ! V_327 || ( V_13 < 0 ) )
return V_13 ;
F_317 ( & V_523 ) ;
F_139 (zone) {
unsigned long V_88 ;
V_88 = V_12 -> V_83 / V_381 ;
F_338 (cpu)
F_376 ( F_140 ( V_12 -> V_118 , V_115 ) ,
V_88 ) ;
}
F_320 ( & V_523 ) ;
return 0 ;
}
static int T_2 F_485 ( char * V_136 )
{
if ( ! V_136 )
return 0 ;
V_524 = F_486 ( V_136 , & V_136 , 0 ) ;
return 1 ;
}
void * T_2 F_487 ( const char * V_525 ,
unsigned long V_526 ,
unsigned long V_527 ,
int V_528 ,
int V_63 ,
unsigned int * V_529 ,
unsigned int * V_530 ,
unsigned long V_531 ,
unsigned long V_532 )
{
unsigned long long F_351 = V_532 ;
unsigned long V_533 , V_90 ;
void * V_326 = NULL ;
if ( ! V_527 ) {
V_527 = V_432 ;
if ( V_380 < 20 )
V_527 = F_488 ( V_527 , ( 1 << 20 ) / V_80 ) ;
if ( V_528 > V_380 )
V_527 >>= ( V_528 - V_380 ) ;
else
V_527 <<= ( V_380 - V_528 ) ;
if ( F_7 ( V_63 & V_534 ) ) {
F_2 ( ! ( V_63 & V_535 ) ) ;
if ( ! ( V_527 >> * V_529 ) ) {
V_527 = 1UL << * V_529 ;
F_122 ( ! V_527 ) ;
}
} else if ( F_7 ( ( V_527 * V_526 ) < V_80 ) )
V_527 = V_80 / V_526 ;
}
V_527 = F_489 ( V_527 ) ;
if ( F_351 == 0 ) {
F_351 = ( ( unsigned long long ) V_433 << V_380 ) >> 4 ;
F_472 ( F_351 , V_526 ) ;
}
F_351 = V_157 ( F_351 , 0x80000000ULL ) ;
if ( V_527 < V_531 )
V_527 = V_531 ;
if ( V_527 > F_351 )
V_527 = F_351 ;
V_533 = F_490 ( V_527 ) ;
do {
V_90 = V_526 << V_533 ;
if ( V_63 & V_535 )
V_326 = F_491 ( V_90 , 0 ) ;
else if ( V_524 )
V_326 = F_492 ( V_90 , V_536 , V_537 ) ;
else {
if ( F_284 ( V_90 ) < V_43 ) {
V_326 = F_283 ( V_90 , V_536 ) ;
F_493 ( V_326 , V_90 , 1 , V_536 ) ;
}
}
} while ( ! V_326 && V_90 > V_80 && -- V_533 );
if ( ! V_326 )
F_494 ( L_103 , V_525 ) ;
F_23 ( V_46 L_104 ,
V_525 ,
( 1UL << V_533 ) ,
F_490 ( V_90 ) - V_380 ,
V_90 ) ;
if ( V_529 )
* V_529 = V_533 ;
if ( V_530 )
* V_530 = ( 1 << V_533 ) - 1 ;
return V_326 ;
}
static inline unsigned long * F_495 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_422
return F_496 ( V_15 ) -> V_419 ;
#else
return V_12 -> V_419 ;
#endif
}
static inline int F_497 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_422
V_15 &= ( V_538 - 1 ) ;
return ( V_15 >> V_86 ) * V_418 ;
#else
V_15 = V_15 - F_498 ( V_12 -> V_18 , V_84 ) ;
return ( V_15 >> V_86 ) * V_418 ;
#endif
}
unsigned long F_499 ( struct V_5 * V_5 ,
int V_539 , int V_540 )
{
struct V_12 * V_12 ;
unsigned long * V_541 ;
unsigned long V_15 , V_542 ;
unsigned long V_63 = 0 ;
unsigned long V_543 = 1 ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
V_541 = F_495 ( V_12 , V_15 ) ;
V_542 = F_497 ( V_12 , V_15 ) ;
for (; V_539 <= V_540 ; V_539 ++ , V_543 <<= 1 )
if ( F_197 ( V_542 + V_539 , V_541 ) )
V_63 |= V_543 ;
return V_63 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_63 ,
int V_539 , int V_540 )
{
struct V_12 * V_12 ;
unsigned long * V_541 ;
unsigned long V_15 , V_542 ;
unsigned long V_543 = 1 ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
V_541 = F_495 ( V_12 , V_15 ) ;
V_542 = F_497 ( V_12 , V_15 ) ;
F_62 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
for (; V_539 <= V_540 ; V_539 ++ , V_543 <<= 1 )
if ( V_63 & V_543 )
F_49 ( V_542 + V_539 , V_541 ) ;
else
F_51 ( V_542 + V_539 , V_541 ) ;
}
bool F_500 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_66 ,
bool V_544 )
{
unsigned long V_15 , V_545 , V_546 ;
int V_76 ;
if ( F_209 ( V_12 ) == V_397 )
return false ;
V_76 = F_102 ( V_5 ) ;
if ( V_76 == V_125 || F_86 ( V_76 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_546 = 0 , V_545 = 0 ; V_545 < V_84 ; V_545 ++ ) {
unsigned long V_547 = V_15 + V_545 ;
if ( ! F_16 ( V_547 ) )
continue;
V_5 = F_127 ( V_547 ) ;
if ( F_501 ( V_5 ) ) {
V_545 = F_488 ( V_545 + 1 , 1 << F_30 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_74 ( & V_5 -> V_62 ) ) {
if ( F_64 ( V_5 ) )
V_545 += ( 1 << F_61 ( V_5 ) ) - 1 ;
continue;
}
if ( V_544 && F_20 ( V_5 ) )
continue;
if ( ! F_502 ( V_5 ) )
V_546 ++ ;
if ( V_546 > V_66 )
return true ;
}
return false ;
}
bool F_503 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_336 ( F_123 ( V_5 ) ) )
return false ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_500 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_504 ( unsigned long V_15 )
{
return V_15 & ~ ( F_505 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_506 ( unsigned long V_15 )
{
return F_422 ( V_15 , F_505 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_507 ( struct V_548 * V_549 ,
unsigned long V_441 , unsigned long V_266 )
{
unsigned long V_550 ;
unsigned long V_15 = V_441 ;
unsigned int V_551 = 0 ;
int V_13 = 0 ;
F_508 () ;
while ( V_15 < V_266 || ! F_79 ( & V_549 -> V_552 ) ) {
if ( F_509 ( V_29 ) ) {
V_13 = - V_553 ;
break;
}
if ( F_79 ( & V_549 -> V_552 ) ) {
V_549 -> V_554 = 0 ;
V_15 = F_510 ( V_549 -> V_12 , V_549 ,
V_15 , V_266 , true ) ;
if ( ! V_15 ) {
V_13 = - V_553 ;
break;
}
V_551 = 0 ;
} else if ( ++ V_551 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_555 ;
break;
}
V_550 = F_511 ( V_549 -> V_12 ,
& V_549 -> V_552 ) ;
V_549 -> V_554 -= V_550 ;
V_13 = F_512 ( & V_549 -> V_552 , V_556 ,
0 , V_557 , V_558 ) ;
}
if ( V_13 < 0 ) {
F_513 ( & V_549 -> V_552 ) ;
return V_13 ;
}
return 0 ;
}
int F_514 ( unsigned long V_441 , unsigned long V_266 ,
unsigned V_6 )
{
unsigned long V_559 , V_560 ;
int V_13 = 0 , V_33 ;
struct V_548 V_549 = {
. V_554 = 0 ,
. V_33 = - 1 ,
. V_12 = F_17 ( F_127 ( V_441 ) ) ,
. V_561 = true ,
. V_562 = true ,
} ;
F_115 ( & V_549 . V_552 ) ;
V_13 = F_515 ( F_504 ( V_441 ) ,
F_506 ( V_266 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_507 ( & V_549 , V_441 , V_266 ) ;
if ( V_13 )
goto V_563;
F_516 () ;
F_143 () ;
V_33 = 0 ;
V_559 = V_441 ;
while ( ! F_64 ( F_127 ( V_559 ) ) ) {
if ( ++ V_33 >= V_43 ) {
V_13 = - V_555 ;
goto V_563;
}
V_559 &= ~ 0UL << V_33 ;
}
if ( F_517 ( V_559 , V_266 , false ) ) {
F_219 ( L_105 ,
V_559 , V_266 ) ;
V_13 = - V_555 ;
goto V_563;
}
V_560 = F_518 ( & V_549 , V_559 , V_266 ) ;
if ( ! V_560 ) {
V_13 = - V_555 ;
goto V_563;
}
if ( V_441 != V_559 )
F_519 ( V_559 , V_441 - V_559 ) ;
if ( V_266 != V_560 )
F_519 ( V_266 , V_560 - V_266 ) ;
V_563:
F_520 ( F_504 ( V_441 ) ,
F_506 ( V_266 ) , V_6 ) ;
return V_13 ;
}
void F_519 ( unsigned long V_15 , unsigned V_35 )
{
unsigned int V_66 = 0 ;
for (; V_35 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
V_66 += F_63 ( V_5 ) != 1 ;
F_521 ( V_5 ) ;
}
F_522 ( V_66 != 0 , L_106 , V_66 ) ;
}
void T_14 F_523 ( struct V_12 * V_12 )
{
unsigned V_115 ;
F_317 ( & V_523 ) ;
F_338 (cpu)
F_377 ( V_12 ,
F_140 ( V_12 -> V_118 , V_115 ) ) ;
F_320 ( & V_523 ) ;
}
void F_524 ( struct V_12 * V_12 )
{
unsigned long V_63 ;
int V_115 ;
struct V_116 * V_117 ;
F_100 ( V_63 ) ;
if ( V_12 -> V_118 != & V_363 ) {
F_144 (cpu) {
V_117 = F_140 ( V_12 -> V_118 , V_115 ) ;
F_525 ( V_12 , V_117 ) ;
}
F_526 ( V_12 -> V_118 ) ;
V_12 -> V_118 = & V_363 ;
}
F_104 ( V_63 ) ;
}
void
F_527 ( unsigned long V_17 , unsigned long V_98 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
int V_33 , V_34 ;
unsigned long V_15 ;
unsigned long V_63 ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 ++ )
if ( F_152 ( V_15 ) )
break;
if ( V_15 == V_98 )
return;
V_12 = F_17 ( F_127 ( V_15 ) ) ;
F_150 ( & V_12 -> V_71 , V_63 ) ;
V_15 = V_17 ;
while ( V_15 < V_98 ) {
if ( ! F_152 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_127 ( V_15 ) ;
if ( F_7 ( ! F_64 ( V_5 ) && F_20 ( V_5 ) ) ) {
V_15 ++ ;
F_364 ( V_5 ) ;
continue;
}
F_122 ( F_63 ( V_5 ) ) ;
F_122 ( ! F_64 ( V_5 ) ) ;
V_33 = F_61 ( V_5 ) ;
#ifdef F_528
F_23 ( V_46 L_107 ,
V_15 , 1 << V_33 , V_98 ) ;
#endif
F_69 ( & V_5 -> V_54 ) ;
F_55 ( V_5 ) ;
V_12 -> V_55 [ V_33 ] . V_56 -- ;
for ( V_34 = 0 ; V_34 < ( 1 << V_33 ) ; V_34 ++ )
F_364 ( ( V_5 + V_34 ) ) ;
V_15 += ( 1 << V_33 ) ;
}
F_158 ( & V_12 -> V_71 , V_63 ) ;
}
bool F_529 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_17 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_63 ;
int V_33 ;
F_150 ( & V_12 -> V_71 , V_63 ) ;
for ( V_33 = 0 ; V_33 < V_43 ; V_33 ++ ) {
struct V_5 * V_564 = V_5 - ( V_15 & ( ( 1 << V_33 ) - 1 ) ) ;
if ( F_64 ( V_564 ) && F_61 ( V_564 ) >= V_33 )
break;
}
F_158 ( & V_12 -> V_71 , V_63 ) ;
return V_33 < V_43 ;
}
static void F_530 ( unsigned long V_63 )
{
const char * V_565 = L_101 ;
unsigned long V_450 ;
int V_34 ;
F_212 ( F_531 ( V_566 ) != V_567 ) ;
F_23 ( V_27 L_108 , V_63 ) ;
V_63 &= ( 1UL << V_568 ) - 1 ;
for ( V_34 = 0 ; V_34 < F_531 ( V_566 ) && V_63 ; V_34 ++ ) {
V_450 = V_566 [ V_34 ] . V_450 ;
if ( ( V_63 & V_450 ) != V_450 )
continue;
V_63 &= ~ V_450 ;
F_23 ( L_109 , V_565 , V_566 [ V_34 ] . V_291 ) ;
V_565 = L_110 ;
}
if ( V_63 )
F_23 ( L_111 , V_565 , V_63 ) ;
F_23 ( L_112 ) ;
}
void F_24 ( struct V_5 * V_5 , const char * V_20 ,
unsigned long V_569 )
{
F_23 ( V_27
L_113 ,
V_5 , F_74 ( & V_5 -> V_62 ) , F_73 ( V_5 ) ,
V_5 -> V_61 , V_5 -> V_570 ) ;
F_530 ( V_5 -> V_63 ) ;
if ( V_20 )
F_532 ( L_114 , V_20 ) ;
if ( V_5 -> V_63 & V_569 ) {
F_532 ( L_115 ) ;
F_530 ( V_5 -> V_63 & V_569 ) ;
}
F_533 ( V_5 ) ;
}
void F_534 ( struct V_5 * V_5 , const char * V_20 )
{
F_24 ( V_5 , V_20 , 0 ) ;
}
