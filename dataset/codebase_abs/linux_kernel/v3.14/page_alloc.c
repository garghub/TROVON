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
static void F_19 ( struct V_5 * V_5 , char * V_20 , unsigned long V_21 )
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
char * V_60 = NULL ;
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
char * V_60 = NULL ;
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
static bool F_138 ( T_1 V_115 )
{
return ( V_115 & V_116 ) == V_116 ;
}
static bool F_138 ( T_1 V_115 )
{
return false ;
}
static void F_139 ( unsigned int V_117 )
{
unsigned long V_63 ;
struct V_12 * V_12 ;
F_140 (zone) {
struct V_118 * V_119 ;
struct V_67 * V_68 ;
F_100 ( V_63 ) ;
V_119 = F_141 ( V_12 -> V_120 , V_117 ) ;
V_68 = & V_119 -> V_68 ;
if ( V_68 -> V_66 ) {
F_77 ( V_12 , V_68 -> V_66 , V_68 ) ;
V_68 -> V_66 = 0 ;
}
F_104 ( V_63 ) ;
}
}
void F_142 ( void * V_121 )
{
F_139 ( F_143 () ) ;
}
void F_144 ( void )
{
int V_117 ;
struct V_118 * V_68 ;
struct V_12 * V_12 ;
static T_3 V_122 ;
F_145 (cpu) {
bool V_123 = false ;
F_140 (zone) {
V_68 = F_141 ( V_12 -> V_120 , V_117 ) ;
if ( V_68 -> V_68 . V_66 ) {
V_123 = true ;
break;
}
}
if ( V_123 )
F_146 ( V_117 , & V_122 ) ;
else
F_147 ( V_117 , & V_122 ) ;
}
F_148 ( & V_122 , F_142 , NULL , 1 ) ;
}
void F_149 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_124 ;
unsigned long V_63 ;
int V_33 , V_125 ;
struct V_73 * V_126 ;
if ( F_150 ( V_12 ) )
return;
F_151 ( & V_12 -> V_71 , V_63 ) ;
V_124 = F_152 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_124 ; V_15 ++ )
if ( F_153 ( V_15 ) ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
if ( ! F_154 ( V_5 ) )
F_155 ( V_5 ) ;
}
F_156 (order, t) {
F_157 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_34 ;
V_15 = F_10 ( F_80 ( V_126 , struct V_5 , V_54 ) ) ;
for ( V_34 = 0 ; V_34 < ( 1UL << V_33 ) ; V_34 ++ )
F_158 ( F_127 ( V_15 + V_34 ) ) ;
}
}
F_159 ( & V_12 -> V_71 , V_63 ) ;
}
void F_160 ( struct V_5 * V_5 , int V_111 )
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
F_161 ( V_81 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_89 ( V_6 ) ) ) {
F_88 ( V_12 , V_5 , 0 , V_6 ) ;
goto V_26;
}
V_6 = V_127 ;
}
V_68 = & F_162 ( V_12 -> V_120 ) -> V_68 ;
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
void F_163 ( struct V_73 * V_74 , int V_111 )
{
struct V_5 * V_5 , * V_94 ;
F_164 (page, next, list, lru) {
F_165 ( V_5 , V_111 ) ;
F_160 ( V_5 , V_111 ) ;
}
}
void F_166 ( struct V_5 * V_5 , unsigned int V_33 )
{
int V_34 ;
F_62 ( F_67 ( V_5 ) , V_5 ) ;
F_62 ( ! F_63 ( V_5 ) , V_5 ) ;
#ifdef F_167
if ( F_168 ( V_5 ) )
F_166 ( F_169 ( V_5 [ 0 ] . V_128 ) , V_33 ) ;
#endif
for ( V_34 = 1 ; V_34 < ( 1 << V_33 ) ; V_34 ++ )
F_108 ( V_5 + V_34 ) ;
}
static int F_170 ( struct V_5 * V_5 , unsigned int V_33 )
{
unsigned long V_129 ;
struct V_12 * V_12 ;
int V_76 ;
F_122 ( ! F_64 ( V_5 ) ) ;
V_12 = F_17 ( V_5 ) ;
V_76 = F_102 ( V_5 ) ;
if ( ! F_89 ( V_76 ) ) {
V_129 = F_171 ( V_12 ) + ( 1 << V_33 ) ;
if ( ! F_172 ( V_12 , 0 , V_129 , 0 , 0 ) )
return 0 ;
F_68 ( V_12 , - ( 1UL << V_33 ) , V_76 ) ;
}
F_69 ( & V_5 -> V_54 ) ;
V_12 -> V_55 [ V_33 ] . V_56 -- ;
F_55 ( V_5 ) ;
if ( V_33 >= V_86 - 1 ) {
struct V_5 * V_130 = V_5 + ( 1 << V_33 ) - 1 ;
for (; V_5 < V_130 ; V_5 += V_84 ) {
int V_76 = F_102 ( V_5 ) ;
if ( ! F_89 ( V_76 ) && ! F_86 ( V_76 ) )
F_6 ( V_5 ,
V_127 ) ;
}
}
return 1UL << V_33 ;
}
int F_173 ( struct V_5 * V_5 )
{
unsigned int V_33 ;
int V_35 ;
V_33 = F_61 ( V_5 ) ;
V_35 = F_170 ( V_5 , V_33 ) ;
if ( ! V_35 )
return 0 ;
F_108 ( V_5 ) ;
F_166 ( V_5 , V_33 ) ;
return V_35 ;
}
static inline
struct V_5 * F_174 ( struct V_12 * V_131 ,
struct V_12 * V_12 , int V_33 , T_1 V_39 ,
int V_6 )
{
unsigned long V_63 ;
struct V_5 * V_5 ;
int V_111 = ! ! ( V_39 & V_132 ) ;
V_133:
if ( F_83 ( V_33 == 0 ) ) {
struct V_67 * V_68 ;
struct V_73 * V_74 ;
F_100 ( V_63 ) ;
V_68 = & F_162 ( V_12 -> V_120 ) -> V_68 ;
V_74 = & V_68 -> V_75 [ V_6 ] ;
if ( F_79 ( V_74 ) ) {
V_68 -> V_66 += F_134 ( V_12 , 0 ,
V_68 -> V_114 , V_74 ,
V_6 , V_111 ) ;
if ( F_7 ( F_79 ( V_74 ) ) )
goto V_134;
}
if ( V_111 )
V_5 = F_80 ( V_74 -> V_77 , struct V_5 , V_54 ) ;
else
V_5 = F_80 ( V_74 -> V_94 , struct V_5 , V_54 ) ;
F_69 ( & V_5 -> V_54 ) ;
V_68 -> V_66 -- ;
} else {
if ( F_7 ( V_39 & V_135 ) ) {
F_175 ( V_33 > 1 ) ;
}
F_151 ( & V_12 -> V_71 , V_63 ) ;
V_5 = F_132 ( V_12 , V_33 , V_6 ) ;
F_87 ( & V_12 -> V_71 ) ;
if ( ! V_5 )
goto V_134;
F_68 ( V_12 , - ( 1 << V_33 ) ,
F_102 ( V_5 ) ) ;
}
if ( ! F_138 ( V_39 ) )
F_85 ( V_12 , V_136 , - ( 1 << V_33 ) ) ;
F_176 ( V_137 , V_12 , 1 << V_33 ) ;
F_177 ( V_131 , V_12 , V_39 ) ;
F_104 ( V_63 ) ;
F_62 ( F_18 ( V_12 , V_5 ) , V_5 ) ;
if ( F_117 ( V_5 , V_33 , V_39 ) )
goto V_133;
return V_5 ;
V_134:
F_104 ( V_63 ) ;
return NULL ;
}
static int T_2 F_178 ( char * V_138 )
{
return F_179 ( & V_139 . V_140 , V_138 ) ;
}
static bool F_180 ( T_1 V_115 , unsigned int V_33 )
{
if ( V_33 < V_139 . V_141 )
return false ;
if ( V_115 & V_135 )
return false ;
if ( V_139 . V_142 && ( V_115 & V_40 ) )
return false ;
if ( V_139 . V_143 && ( V_115 & V_144 ) )
return false ;
return F_181 ( & V_139 . V_140 , 1 << V_33 ) ;
}
static int T_2 F_182 ( void )
{
T_4 V_145 = V_146 | V_147 | V_148 ;
struct V_149 * V_150 ;
V_150 = F_183 ( L_15 , NULL ,
& V_139 . V_140 ) ;
if ( F_184 ( V_150 ) )
return F_185 ( V_150 ) ;
if ( ! F_186 ( L_16 , V_145 , V_150 ,
& V_139 . V_143 ) )
goto V_151;
if ( ! F_186 ( L_17 , V_145 , V_150 ,
& V_139 . V_142 ) )
goto V_151;
if ( ! F_187 ( L_18 , V_145 , V_150 ,
& V_139 . V_141 ) )
goto V_151;
return 0 ;
V_151:
F_188 ( V_150 ) ;
return - V_152 ;
}
static inline bool F_180 ( T_1 V_115 , unsigned int V_33 )
{
return false ;
}
static bool F_189 ( struct V_12 * V_153 , int V_33 , unsigned long V_154 ,
int V_155 , int V_156 , long V_157 )
{
long V_158 = V_154 ;
long V_159 = V_153 -> V_159 [ V_155 ] ;
int V_160 ;
long V_161 = 0 ;
V_157 -= ( 1 << V_33 ) - 1 ;
if ( V_156 & V_162 )
V_158 -= V_158 / 2 ;
if ( V_156 & V_163 )
V_158 -= V_158 / 4 ;
#ifdef V_112
if ( ! ( V_156 & V_164 ) )
V_161 = F_190 ( V_153 , V_79 ) ;
#endif
if ( V_157 - V_161 <= V_158 + V_159 )
return false ;
for ( V_160 = 0 ; V_160 < V_33 ; V_160 ++ ) {
V_157 -= V_153 -> V_55 [ V_160 ] . V_56 << V_160 ;
V_158 >>= 1 ;
if ( V_157 <= V_158 )
return false ;
}
return true ;
}
bool F_172 ( struct V_12 * V_153 , int V_33 , unsigned long V_154 ,
int V_155 , int V_156 )
{
return F_189 ( V_153 , V_33 , V_154 , V_155 , V_156 ,
F_190 ( V_153 , V_78 ) ) ;
}
bool F_191 ( struct V_12 * V_153 , int V_33 , unsigned long V_154 ,
int V_155 , int V_156 )
{
long V_157 = F_190 ( V_153 , V_78 ) ;
if ( V_153 -> V_165 && V_157 < V_153 -> V_165 )
V_157 = F_192 ( V_153 , V_78 ) ;
return F_189 ( V_153 , V_33 , V_154 , V_155 , V_156 ,
V_157 ) ;
}
static T_5 * F_193 ( struct V_166 * V_166 , int V_156 )
{
struct V_167 * V_168 ;
T_5 * V_169 ;
V_168 = V_166 -> V_170 ;
if ( ! V_168 )
return NULL ;
if ( F_194 ( V_25 , V_168 -> V_171 + V_28 ) ) {
F_195 ( V_168 -> V_172 , V_173 ) ;
V_168 -> V_171 = V_25 ;
}
V_169 = ! F_44 () && ( V_156 & V_174 ) ?
& V_175 :
& V_176 [ V_177 ] ;
return V_169 ;
}
static int F_196 ( struct V_166 * V_166 , struct V_178 * V_153 ,
T_5 * V_169 )
{
struct V_167 * V_168 ;
int V_34 ;
int V_179 ;
V_168 = V_166 -> V_170 ;
if ( ! V_168 )
return 1 ;
V_34 = V_153 - V_166 -> V_180 ;
V_179 = V_168 -> V_181 [ V_34 ] ;
return F_197 ( V_179 , * V_169 ) && ! F_198 ( V_34 , V_168 -> V_172 ) ;
}
static void F_199 ( struct V_166 * V_166 , struct V_178 * V_153 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = V_166 -> V_170 ;
if ( ! V_168 )
return;
V_34 = V_153 - V_166 -> V_180 ;
F_200 ( V_34 , V_168 -> V_172 ) ;
}
static void F_201 ( struct V_166 * V_166 )
{
struct V_167 * V_168 ;
V_168 = V_166 -> V_170 ;
if ( ! V_168 )
return;
F_195 ( V_168 -> V_172 , V_173 ) ;
}
static bool F_202 ( struct V_12 * V_182 , struct V_12 * V_12 )
{
return V_182 -> V_183 == V_12 -> V_183 ;
}
static bool F_203 ( struct V_12 * V_182 , struct V_12 * V_12 )
{
return F_197 ( V_182 -> V_183 , V_12 -> V_184 -> V_185 ) ;
}
static void T_6 F_204 ( int V_186 )
{
int V_34 ;
F_205 (i)
if ( F_206 ( V_186 , V_34 ) <= V_187 )
F_207 ( V_34 , F_208 ( V_186 ) -> V_185 ) ;
else
V_188 = 1 ;
}
static T_5 * F_193 ( struct V_166 * V_166 , int V_156 )
{
return NULL ;
}
static int F_196 ( struct V_166 * V_166 , struct V_178 * V_153 ,
T_5 * V_169 )
{
return 1 ;
}
static void F_199 ( struct V_166 * V_166 , struct V_178 * V_153 )
{
}
static void F_201 ( struct V_166 * V_166 )
{
}
static bool F_202 ( struct V_12 * V_182 , struct V_12 * V_12 )
{
return true ;
}
static bool F_203 ( struct V_12 * V_182 , struct V_12 * V_12 )
{
return true ;
}
static inline void F_204 ( int V_186 )
{
}
static struct V_5 *
F_209 ( T_1 V_115 , T_5 * V_189 , unsigned int V_33 ,
struct V_166 * V_166 , int V_190 , int V_156 ,
struct V_12 * V_131 , int V_6 )
{
struct V_178 * V_153 ;
struct V_5 * V_5 = NULL ;
int V_155 ;
struct V_12 * V_12 ;
T_5 * V_169 = NULL ;
int V_191 = 0 ;
int V_192 = 0 ;
V_155 = F_210 ( V_131 ) ;
V_193:
F_211 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_154 ;
if ( F_135 ( V_194 ) && V_191 &&
! F_196 ( V_166 , V_153 , V_169 ) )
continue;
if ( ( V_156 & V_174 ) &&
! F_212 ( V_12 , V_115 ) )
continue;
F_213 ( V_195 < V_196 ) ;
if ( F_7 ( V_156 & V_195 ) )
goto V_197;
if ( ( V_156 & V_198 ) &&
! F_138 ( V_115 ) ) {
if ( F_190 ( V_12 , V_136 ) <= 0 )
continue;
if ( ! F_202 ( V_131 , V_12 ) )
continue;
}
if ( ( V_156 & V_198 ) &&
( V_115 & V_199 ) && ! F_214 ( V_12 ) )
goto V_200;
V_154 = V_12 -> V_129 [ V_156 & V_201 ] ;
if ( ! F_172 ( V_12 , V_33 , V_154 ,
V_155 , V_156 ) ) {
int V_13 ;
if ( F_135 ( V_194 ) &&
! V_192 && V_202 > 1 ) {
V_169 = F_193 ( V_166 , V_156 ) ;
V_191 = 1 ;
V_192 = 1 ;
}
if ( V_188 == 0 ||
! F_203 ( V_131 , V_12 ) )
goto V_200;
if ( F_135 ( V_194 ) && V_191 &&
! F_196 ( V_166 , V_153 , V_169 ) )
continue;
V_13 = F_215 ( V_12 , V_115 , V_33 ) ;
switch ( V_13 ) {
case V_203 :
continue;
case V_204 :
continue;
default:
if ( F_172 ( V_12 , V_33 , V_154 ,
V_155 , V_156 ) )
goto V_197;
if ( ( ( V_156 & V_201 ) == V_205 ) ||
V_13 == V_206 )
goto V_200;
continue;
}
}
V_197:
V_5 = F_174 ( V_131 , V_12 , V_33 ,
V_115 , V_6 ) ;
if ( V_5 )
break;
V_200:
if ( F_135 ( V_194 ) )
F_199 ( V_166 , V_153 ) ;
}
if ( F_7 ( F_135 ( V_194 ) && V_5 == NULL && V_191 ) ) {
V_191 = 0 ;
goto V_193;
}
if ( V_5 )
V_5 -> V_207 = ! ! ( V_156 & V_195 ) ;
return V_5 ;
}
static inline bool F_216 ( void )
{
bool V_13 = false ;
#if V_208 > 8
V_13 = F_44 () ;
#endif
return V_13 ;
}
void F_217 ( T_1 V_115 , int V_33 , const char * V_209 , ... )
{
unsigned int V_210 = V_211 ;
if ( ( V_115 & V_212 ) || ! F_218 ( & V_213 ) ||
F_114 () > 0 )
return;
if ( ! ( V_115 & V_214 ) )
if ( F_219 ( V_215 ) ||
( V_29 -> V_63 & ( V_216 | V_217 ) ) )
V_210 &= ~ V_211 ;
if ( F_44 () || ! ( V_115 & V_144 ) )
V_210 &= ~ V_211 ;
if ( V_209 ) {
struct V_218 V_219 ;
T_7 args ;
va_start ( args , V_209 ) ;
V_219 . V_209 = V_209 ;
V_219 . V_220 = & args ;
F_220 ( L_19 , & V_219 ) ;
va_end ( args ) ;
}
F_220 ( L_20 ,
V_29 -> V_30 , V_33 , V_115 ) ;
F_26 () ;
if ( ! F_216 () )
F_221 ( V_210 ) ;
}
static inline int
F_222 ( T_1 V_115 , unsigned int V_33 ,
unsigned long V_221 ,
unsigned long V_222 )
{
if ( V_115 & V_223 )
return 0 ;
if ( V_115 & V_135 )
return 1 ;
if ( ! V_221 && F_5 () )
return 0 ;
if ( V_33 <= V_224 )
return 1 ;
if ( V_115 & V_225 && V_222 < ( 1 << V_33 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_223 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 , enum V_226 V_190 ,
T_5 * V_189 , struct V_12 * V_131 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_224 ( V_166 , V_115 ) ) {
F_225 ( 1 ) ;
return NULL ;
}
V_5 = F_209 ( V_115 | V_227 , V_189 ,
V_33 , V_166 , V_190 ,
V_228 | V_174 ,
V_131 , V_6 ) ;
if ( V_5 )
goto V_26;
if ( ! ( V_115 & V_135 ) ) {
if ( V_33 > V_224 )
goto V_26;
if ( V_190 < V_229 )
goto V_26;
if ( V_115 & V_230 )
goto V_26;
}
F_226 ( V_166 , V_115 , V_33 , V_189 , false ) ;
V_26:
F_227 ( V_166 , V_115 ) ;
return V_5 ;
}
static struct V_5 *
F_228 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 , enum V_226 V_190 ,
T_5 * V_189 , int V_156 , struct V_12 * V_131 ,
int V_6 , bool V_231 ,
bool * V_232 , bool * V_233 ,
unsigned long * V_221 )
{
if ( ! V_33 )
return NULL ;
if ( F_229 ( V_131 , V_33 ) ) {
* V_233 = true ;
return NULL ;
}
V_29 -> V_63 |= V_216 ;
* V_221 = F_230 ( V_166 , V_33 , V_115 ,
V_189 , V_231 ,
V_232 ) ;
V_29 -> V_63 &= ~ V_216 ;
if ( * V_221 != V_234 ) {
struct V_5 * V_5 ;
F_139 ( F_231 () ) ;
F_232 () ;
V_5 = F_209 ( V_115 , V_189 ,
V_33 , V_166 , V_190 ,
V_156 & ~ V_195 ,
V_131 , V_6 ) ;
if ( V_5 ) {
V_131 -> V_235 = false ;
F_233 ( V_131 , V_33 , true ) ;
F_234 ( V_236 ) ;
return V_5 ;
}
F_234 ( V_237 ) ;
if ( V_231 )
F_235 ( V_131 , V_33 ) ;
F_236 () ;
}
return NULL ;
}
static inline struct V_5 *
F_228 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 , enum V_226 V_190 ,
T_5 * V_189 , int V_156 , struct V_12 * V_131 ,
int V_6 , bool V_231 ,
bool * V_232 , bool * V_233 ,
unsigned long * V_221 )
{
return NULL ;
}
static int
F_237 ( T_1 V_115 , unsigned int V_33 , struct V_166 * V_166 ,
T_5 * V_189 )
{
struct V_238 V_238 ;
int V_239 ;
F_236 () ;
F_238 () ;
V_29 -> V_63 |= V_216 ;
F_239 ( V_115 ) ;
V_238 . V_240 = 0 ;
V_29 -> V_238 = & V_238 ;
V_239 = F_240 ( V_166 , V_33 , V_115 , V_189 ) ;
V_29 -> V_238 = NULL ;
F_241 () ;
V_29 -> V_63 &= ~ V_216 ;
F_236 () ;
return V_239 ;
}
static inline struct V_5 *
F_242 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 , enum V_226 V_190 ,
T_5 * V_189 , int V_156 , struct V_12 * V_131 ,
int V_6 , unsigned long * V_221 )
{
struct V_5 * V_5 = NULL ;
bool V_241 = false ;
* V_221 = F_237 ( V_115 , V_33 , V_166 ,
V_189 ) ;
if ( F_7 ( ! ( * V_221 ) ) )
return NULL ;
if ( F_135 ( V_194 ) )
F_201 ( V_166 ) ;
V_242:
V_5 = F_209 ( V_115 , V_189 , V_33 ,
V_166 , V_190 ,
V_156 & ~ V_195 ,
V_131 , V_6 ) ;
if ( ! V_5 && ! V_241 ) {
F_144 () ;
V_241 = true ;
goto V_242;
}
return V_5 ;
}
static inline struct V_5 *
F_243 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 , enum V_226 V_190 ,
T_5 * V_189 , struct V_12 * V_131 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_209 ( V_115 , V_189 , V_33 ,
V_166 , V_190 , V_195 ,
V_131 , V_6 ) ;
if ( ! V_5 && V_115 & V_135 )
F_244 ( V_131 , V_243 , V_28 / 50 ) ;
} while ( ! V_5 && ( V_115 & V_135 ) );
return V_5 ;
}
static void F_245 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 ,
enum V_226 V_190 ,
struct V_12 * V_131 )
{
struct V_178 * V_153 ;
struct V_12 * V_12 ;
F_246 (zone, z, zonelist, high_zoneidx) {
if ( ! ( V_115 & V_244 ) )
F_247 ( V_12 , V_33 , F_210 ( V_131 ) ) ;
if ( ! F_202 ( V_131 , V_12 ) )
continue;
F_248 ( V_12 , V_136 ,
F_249 ( V_12 ) -
F_171 ( V_12 ) -
F_190 ( V_12 , V_136 ) ) ;
}
}
static inline int
F_250 ( T_1 V_115 )
{
int V_156 = V_205 | V_174 ;
const T_1 V_245 = V_115 & V_144 ;
F_213 ( V_246 != ( V_247 T_1 ) V_162 ) ;
V_156 |= ( V_247 int ) ( V_115 & V_246 ) ;
if ( ! V_245 ) {
if ( ! ( V_115 & V_214 ) )
V_156 |= V_163 ;
V_156 &= ~ V_174 ;
} else if ( F_7 ( F_251 ( V_29 ) ) && ! F_44 () )
V_156 |= V_163 ;
if ( F_83 ( ! ( V_115 & V_214 ) ) ) {
if ( V_115 & V_248 )
V_156 |= V_195 ;
else if ( F_252 () && ( V_29 -> V_63 & V_216 ) )
V_156 |= V_195 ;
else if ( ! F_44 () &&
( ( V_29 -> V_63 & V_216 ) ||
F_7 ( F_219 ( V_215 ) ) ) )
V_156 |= V_195 ;
}
#ifdef V_112
if ( F_253 ( V_115 ) == V_127 )
V_156 |= V_164 ;
#endif
return V_156 ;
}
bool F_254 ( T_1 V_115 )
{
return ! ! ( F_250 ( V_115 ) & V_195 ) ;
}
static inline struct V_5 *
F_255 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 , enum V_226 V_190 ,
T_5 * V_189 , struct V_12 * V_131 ,
int V_6 )
{
const T_1 V_245 = V_115 & V_144 ;
struct V_5 * V_5 = NULL ;
int V_156 ;
unsigned long V_222 = 0 ;
unsigned long V_221 ;
bool V_231 = false ;
bool V_233 = false ;
bool V_232 = false ;
if ( V_33 >= V_43 ) {
F_175 ( ! ( V_115 & V_212 ) ) ;
return NULL ;
}
if ( F_138 ( V_115 ) )
goto V_249;
V_250:
F_245 ( V_115 , V_33 , V_166 ,
V_190 , V_131 ) ;
V_156 = F_250 ( V_115 ) ;
if ( ! ( V_156 & V_174 ) && ! V_189 )
F_256 ( V_166 , V_190 , NULL ,
& V_131 ) ;
V_251:
V_5 = F_209 ( V_115 , V_189 , V_33 , V_166 ,
V_190 , V_156 & ~ V_195 ,
V_131 , V_6 ) ;
if ( V_5 )
goto V_252;
if ( V_156 & V_195 ) {
V_166 = F_257 ( F_258 () , V_115 ) ;
V_5 = F_243 ( V_115 , V_33 ,
V_166 , V_190 , V_189 ,
V_131 , V_6 ) ;
if ( V_5 ) {
goto V_252;
}
}
if ( ! V_245 ) {
F_175 ( V_115 & V_135 ) ;
goto V_249;
}
if ( V_29 -> V_63 & V_216 )
goto V_249;
if ( F_219 ( V_215 ) && ! ( V_115 & V_135 ) )
goto V_249;
V_5 = F_228 ( V_115 , V_33 ,
V_166 , V_190 ,
V_189 ,
V_156 , V_131 ,
V_6 , V_231 ,
& V_232 ,
& V_233 ,
& V_221 ) ;
if ( V_5 )
goto V_252;
V_231 = true ;
if ( ( V_233 || V_232 ) &&
( V_115 & V_244 ) )
goto V_249;
V_5 = F_242 ( V_115 , V_33 ,
V_166 , V_190 ,
V_189 ,
V_156 , V_131 ,
V_6 , & V_221 ) ;
if ( V_5 )
goto V_252;
if ( ! V_221 ) {
if ( F_259 ( V_115 ) ) {
if ( V_253 )
goto V_249;
if ( ( V_29 -> V_63 & V_254 ) &&
! ( V_115 & V_135 ) )
goto V_249;
V_5 = F_223 ( V_115 , V_33 ,
V_166 , V_190 ,
V_189 , V_131 ,
V_6 ) ;
if ( V_5 )
goto V_252;
if ( ! ( V_115 & V_135 ) ) {
if ( V_33 > V_224 )
goto V_249;
if ( V_190 < V_229 )
goto V_249;
}
goto V_250;
}
}
V_222 += V_221 ;
if ( F_222 ( V_115 , V_33 , V_221 ,
V_222 ) ) {
F_244 ( V_131 , V_243 , V_28 / 50 ) ;
goto V_251;
} else {
V_5 = F_228 ( V_115 , V_33 ,
V_166 , V_190 ,
V_189 ,
V_156 , V_131 ,
V_6 , V_231 ,
& V_232 ,
& V_233 ,
& V_221 ) ;
if ( V_5 )
goto V_252;
}
V_249:
F_217 ( V_115 , V_33 , NULL ) ;
return V_5 ;
V_252:
if ( V_255 )
F_260 ( V_5 , V_33 , V_115 ) ;
return V_5 ;
}
struct V_5 *
F_261 ( T_1 V_115 , unsigned int V_33 ,
struct V_166 * V_166 , T_5 * V_189 )
{
enum V_226 V_190 = F_262 ( V_115 ) ;
struct V_12 * V_131 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_253 ( V_115 ) ;
unsigned int V_256 ;
int V_156 = V_198 | V_174 ;
struct V_257 * V_258 = NULL ;
V_115 &= V_3 ;
F_263 ( V_115 ) ;
F_264 ( V_115 & V_144 ) ;
if ( F_180 ( V_115 , V_33 ) )
return NULL ;
if ( F_7 ( ! V_166 -> V_180 -> V_12 ) )
return NULL ;
if ( ! F_265 ( V_115 , & V_258 , V_33 ) )
return NULL ;
V_259:
V_256 = F_266 () ;
F_256 ( V_166 , V_190 ,
V_189 ? : & V_175 ,
& V_131 ) ;
if ( ! V_131 )
goto V_26;
#ifdef V_112
if ( F_253 ( V_115 ) == V_127 )
V_156 |= V_164 ;
#endif
V_5 = F_209 ( V_115 | V_227 , V_189 , V_33 ,
V_166 , V_190 , V_156 ,
V_131 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_115 = F_267 ( V_115 ) ;
V_5 = F_255 ( V_115 , V_33 ,
V_166 , V_190 , V_189 ,
V_131 , V_6 ) ;
}
F_268 ( V_5 , V_33 , V_115 , V_6 ) ;
V_26:
if ( F_7 ( ! F_269 ( V_256 ) && ! V_5 ) )
goto V_259;
F_270 ( V_5 , V_258 , V_33 ) ;
return V_5 ;
}
unsigned long F_271 ( T_1 V_115 , unsigned int V_33 )
{
struct V_5 * V_5 ;
F_43 ( ( V_115 & V_40 ) != 0 ) ;
V_5 = F_272 ( V_115 , V_33 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_96 ( V_5 ) ;
}
unsigned long F_273 ( T_1 V_115 )
{
return F_271 ( V_115 | V_91 , 0 ) ;
}
void F_109 ( struct V_5 * V_5 , unsigned int V_33 )
{
if ( F_274 ( V_5 ) ) {
if ( V_33 == 0 )
F_160 ( V_5 , 0 ) ;
else
F_29 ( V_5 , V_33 ) ;
}
}
void V_157 ( unsigned long V_260 , unsigned int V_33 )
{
if ( V_260 != 0 ) {
F_43 ( ! F_275 ( ( void * ) V_260 ) ) ;
F_109 ( F_169 ( ( void * ) V_260 ) , V_33 ) ;
}
}
void F_276 ( struct V_5 * V_5 , unsigned int V_33 )
{
F_277 ( V_5 , V_33 ) ;
F_109 ( V_5 , V_33 ) ;
}
void F_278 ( unsigned long V_260 , unsigned int V_33 )
{
if ( V_260 != 0 ) {
F_43 ( ! F_275 ( ( void * ) V_260 ) ) ;
F_276 ( F_169 ( ( void * ) V_260 ) , V_33 ) ;
}
}
static void * F_279 ( unsigned long V_260 , unsigned V_33 , T_8 V_90 )
{
if ( V_260 ) {
unsigned long V_261 = V_260 + ( V_80 << V_33 ) ;
unsigned long V_262 = V_260 + F_280 ( V_90 ) ;
F_166 ( F_169 ( ( void * ) V_260 ) , V_33 ) ;
while ( V_262 < V_261 ) {
F_281 ( V_262 ) ;
V_262 += V_80 ;
}
}
return ( void * ) V_260 ;
}
void * F_282 ( T_8 V_90 , T_1 V_115 )
{
unsigned int V_33 = F_283 ( V_90 ) ;
unsigned long V_260 ;
V_260 = F_271 ( V_115 , V_33 ) ;
return F_279 ( V_260 , V_33 , V_90 ) ;
}
void * F_284 ( int V_186 , T_8 V_90 , T_1 V_115 )
{
unsigned V_33 = F_283 ( V_90 ) ;
struct V_5 * V_36 = F_285 ( V_186 , V_115 , V_33 ) ;
if ( ! V_36 )
return NULL ;
return F_279 ( ( unsigned long ) F_96 ( V_36 ) , V_33 , V_90 ) ;
}
void F_286 ( void * V_263 , T_8 V_90 )
{
unsigned long V_260 = ( unsigned long ) V_263 ;
unsigned long V_264 = V_260 + F_280 ( V_90 ) ;
while ( V_260 < V_264 ) {
F_281 ( V_260 ) ;
V_260 += V_80 ;
}
}
static unsigned long F_287 ( int V_265 )
{
struct V_178 * V_153 ;
struct V_12 * V_12 ;
unsigned long V_266 = 0 ;
struct V_166 * V_166 = F_257 ( F_258 () , V_267 ) ;
F_246 (zone, z, zonelist, offset) {
unsigned long V_90 = V_12 -> V_83 ;
unsigned long V_88 = F_249 ( V_12 ) ;
if ( V_90 > V_88 )
V_266 += V_90 - V_88 ;
}
return V_266 ;
}
unsigned long F_288 ( void )
{
return F_287 ( F_262 ( V_268 ) ) ;
}
unsigned long F_289 ( void )
{
return F_287 ( F_262 ( V_269 ) ) ;
}
static inline void F_290 ( struct V_12 * V_12 )
{
if ( F_135 ( V_194 ) )
F_23 ( L_21 , F_124 ( V_12 ) ) ;
}
void F_291 ( struct V_270 * V_271 )
{
V_271 -> V_272 = V_273 ;
V_271 -> V_274 = 0 ;
V_271 -> V_275 = F_292 ( V_78 ) ;
V_271 -> V_276 = F_293 () ;
V_271 -> V_277 = V_278 ;
V_271 -> V_279 = F_294 () ;
V_271 -> V_280 = V_80 ;
}
void F_295 ( struct V_270 * V_271 , int V_186 )
{
int V_226 ;
unsigned long V_83 = 0 ;
T_9 * V_281 = F_208 ( V_186 ) ;
for ( V_226 = 0 ; V_226 < V_282 ; V_226 ++ )
V_83 += V_281 -> V_283 [ V_226 ] . V_83 ;
V_271 -> V_272 = V_83 ;
V_271 -> V_275 = F_296 ( V_186 , V_78 ) ;
#ifdef F_297
V_271 -> V_277 = V_281 -> V_283 [ V_284 ] . V_83 ;
V_271 -> V_279 = F_190 ( & V_281 -> V_283 [ V_284 ] ,
V_78 ) ;
#else
V_271 -> V_277 = 0 ;
V_271 -> V_279 = 0 ;
#endif
V_271 -> V_280 = V_80 ;
}
bool F_298 ( unsigned int V_63 , int V_186 )
{
bool V_13 = false ;
unsigned int V_256 ;
if ( ! ( V_63 & V_211 ) )
goto V_26;
do {
V_256 = F_266 () ;
V_13 = ! F_197 ( V_186 , V_175 ) ;
} while ( ! F_269 ( V_256 ) );
V_26:
return V_13 ;
}
static void F_299 ( unsigned char type )
{
static const char V_285 [ V_286 ] = {
[ V_9 ] = 'U' ,
[ V_104 ] = 'E' ,
[ V_127 ] = 'M' ,
[ V_109 ] = 'R' ,
#ifdef V_112
[ V_85 ] = 'C' ,
#endif
#ifdef F_300
[ V_287 ] = 'I' ,
#endif
} ;
char V_288 [ V_286 + 1 ] ;
char * V_36 = V_288 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_286 ; V_34 ++ ) {
if ( type & ( 1 << V_34 ) )
* V_36 ++ = V_285 [ V_34 ] ;
}
* V_36 = '\0' ;
F_23 ( L_22 , V_288 ) ;
}
void F_301 ( unsigned int V_210 )
{
int V_117 ;
struct V_12 * V_12 ;
F_140 (zone) {
if ( F_298 ( V_210 , F_124 ( V_12 ) ) )
continue;
F_290 ( V_12 ) ;
F_23 ( L_23 , V_12 -> V_289 ) ;
F_145 (cpu) {
struct V_118 * V_120 ;
V_120 = F_141 ( V_12 -> V_120 , V_117 ) ;
F_23 ( L_24 ,
V_117 , V_120 -> V_68 . V_88 ,
V_120 -> V_68 . V_114 , V_120 -> V_68 . V_66 ) ;
}
}
F_23 ( L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
F_292 ( V_290 ) ,
F_292 ( V_291 ) ,
F_292 ( V_292 ) ,
F_292 ( V_293 ) ,
F_292 ( V_294 ) ,
F_292 ( V_295 ) ,
F_292 ( V_296 ) ,
F_292 ( V_297 ) ,
F_292 ( V_298 ) ,
F_292 ( V_299 ) ,
F_292 ( V_78 ) ,
F_292 ( V_300 ) ,
F_292 ( V_301 ) ,
F_292 ( V_302 ) ,
F_292 ( V_303 ) ,
F_292 ( V_304 ) ,
F_292 ( V_305 ) ,
F_292 ( V_79 ) ) ;
F_140 (zone) {
int V_34 ;
if ( F_298 ( V_210 , F_124 ( V_12 ) ) )
continue;
F_290 ( V_12 ) ;
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
V_12 -> V_289 ,
F_302 ( F_190 ( V_12 , V_78 ) ) ,
F_302 ( F_303 ( V_12 ) ) ,
F_302 ( F_171 ( V_12 ) ) ,
F_302 ( F_249 ( V_12 ) ) ,
F_302 ( F_190 ( V_12 , V_290 ) ) ,
F_302 ( F_190 ( V_12 , V_291 ) ) ,
F_302 ( F_190 ( V_12 , V_293 ) ) ,
F_302 ( F_190 ( V_12 , V_294 ) ) ,
F_302 ( F_190 ( V_12 , V_296 ) ) ,
F_302 ( F_190 ( V_12 , V_292 ) ) ,
F_302 ( F_190 ( V_12 , V_295 ) ) ,
F_302 ( V_12 -> V_306 ) ,
F_302 ( V_12 -> V_83 ) ,
F_302 ( F_190 ( V_12 , V_307 ) ) ,
F_302 ( F_190 ( V_12 , V_297 ) ) ,
F_302 ( F_190 ( V_12 , V_298 ) ) ,
F_302 ( F_190 ( V_12 , V_302 ) ) ,
F_302 ( F_190 ( V_12 , V_303 ) ) ,
F_302 ( F_190 ( V_12 , V_300 ) ) ,
F_302 ( F_190 ( V_12 , V_301 ) ) ,
F_190 ( V_12 , V_308 ) *
V_309 / 1024 ,
F_302 ( F_190 ( V_12 , V_304 ) ) ,
F_302 ( F_190 ( V_12 , V_299 ) ) ,
F_302 ( F_190 ( V_12 , V_305 ) ) ,
F_302 ( F_190 ( V_12 , V_79 ) ) ,
F_302 ( F_190 ( V_12 , V_310 ) ) ,
V_12 -> V_72 ,
( ! F_304 ( V_12 ) ? L_62 : L_63 )
) ;
F_23 ( L_64 ) ;
for ( V_34 = 0 ; V_34 < V_282 ; V_34 ++ )
F_23 ( L_65 , V_12 -> V_159 [ V_34 ] ) ;
F_23 ( L_61 ) ;
}
F_140 (zone) {
unsigned long V_311 [ V_43 ] , V_63 , V_33 , V_312 = 0 ;
unsigned char V_285 [ V_43 ] ;
if ( F_298 ( V_210 , F_124 ( V_12 ) ) )
continue;
F_290 ( V_12 ) ;
F_23 ( L_66 , V_12 -> V_289 ) ;
F_151 ( & V_12 -> V_71 , V_63 ) ;
for ( V_33 = 0 ; V_33 < V_43 ; V_33 ++ ) {
struct V_55 * V_89 = & V_12 -> V_55 [ V_33 ] ;
int type ;
V_311 [ V_33 ] = V_89 -> V_56 ;
V_312 += V_311 [ V_33 ] << V_33 ;
V_285 [ V_33 ] = 0 ;
for ( type = 0 ; type < V_286 ; type ++ ) {
if ( ! F_79 ( & V_89 -> V_59 [ type ] ) )
V_285 [ V_33 ] |= 1 << type ;
}
}
F_159 ( & V_12 -> V_71 , V_63 ) ;
for ( V_33 = 0 ; V_33 < V_43 ; V_33 ++ ) {
F_23 ( L_67 , V_311 [ V_33 ] , F_302 ( 1UL ) << V_33 ) ;
if ( V_311 [ V_33 ] )
F_299 ( V_285 [ V_33 ] ) ;
}
F_23 ( L_68 , F_302 ( V_312 ) ) ;
}
F_305 () ;
F_23 ( L_69 , F_292 ( V_313 ) ) ;
F_306 () ;
}
static void F_307 ( struct V_12 * V_12 , struct V_178 * V_178 )
{
V_178 -> V_12 = V_12 ;
V_178 -> F_210 = F_210 ( V_12 ) ;
}
static int F_308 ( T_9 * V_281 , struct V_166 * V_166 ,
int V_314 )
{
struct V_12 * V_12 ;
enum V_226 V_226 = V_282 ;
do {
V_226 -- ;
V_12 = V_281 -> V_283 + V_226 ;
if ( F_309 ( V_12 ) ) {
F_307 ( V_12 ,
& V_166 -> V_180 [ V_314 ++ ] ) ;
F_310 ( V_226 ) ;
}
} while ( V_226 );
return V_314 ;
}
static int F_311 ( char * V_315 )
{
if ( * V_315 == 'd' || * V_315 == 'D' ) {
V_316 = V_317 ;
} else if ( * V_315 == 'n' || * V_315 == 'N' ) {
V_316 = V_318 ;
} else if ( * V_315 == 'z' || * V_315 == 'Z' ) {
V_316 = V_319 ;
} else {
F_23 ( V_320
L_70
L_71 , V_315 ) ;
return - V_321 ;
}
return 0 ;
}
static T_2 int F_312 ( char * V_315 )
{
int V_13 ;
if ( ! V_315 )
return 0 ;
V_13 = F_311 ( V_315 ) ;
if ( V_13 == 0 )
F_313 ( V_322 , V_315 , V_323 ) ;
return V_13 ;
}
int F_314 ( T_10 * V_324 , int V_325 ,
void T_11 * V_326 , T_8 * V_327 ,
T_12 * V_328 )
{
char V_329 [ V_323 ] ;
int V_13 ;
static F_315 ( V_330 ) ;
F_316 ( & V_330 ) ;
if ( V_325 ) {
if ( strlen ( ( char * ) V_324 -> V_331 ) >= V_323 ) {
V_13 = - V_321 ;
goto V_26;
}
strcpy ( V_329 , ( char * ) V_324 -> V_331 ) ;
}
V_13 = F_317 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_13 )
goto V_26;
if ( V_325 ) {
int V_332 = V_316 ;
V_13 = F_311 ( ( char * ) V_324 -> V_331 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_324 -> V_331 , V_329 ,
V_323 ) ;
V_316 = V_332 ;
} else if ( V_332 != V_316 ) {
F_316 ( & V_333 ) ;
F_318 ( NULL , NULL ) ;
F_319 ( & V_333 ) ;
}
}
V_26:
F_319 ( & V_330 ) ;
return V_13 ;
}
static int F_320 ( int V_183 , T_5 * V_334 )
{
int V_179 , V_271 ;
int V_335 = V_336 ;
int V_337 = V_338 ;
const struct V_339 * V_288 = F_321 ( 0 ) ;
if ( ! F_197 ( V_183 , * V_334 ) ) {
F_207 ( V_183 , * V_334 ) ;
return V_183 ;
}
F_322 (n, N_MEMORY) {
if ( F_197 ( V_179 , * V_334 ) )
continue;
V_271 = F_206 ( V_183 , V_179 ) ;
V_271 += ( V_179 < V_183 ) ;
V_288 = F_321 ( V_179 ) ;
if ( ! F_323 ( V_288 ) )
V_271 += V_340 ;
V_271 *= ( V_341 * V_342 ) ;
V_271 += V_343 [ V_179 ] ;
if ( V_271 < V_335 ) {
V_335 = V_271 ;
V_337 = V_179 ;
}
}
if ( V_337 >= 0 )
F_207 ( V_337 , * V_334 ) ;
return V_337 ;
}
static void F_324 ( T_9 * V_281 , int V_183 )
{
int V_344 ;
struct V_166 * V_166 ;
V_166 = & V_281 -> V_345 [ 0 ] ;
for ( V_344 = 0 ; V_166 -> V_180 [ V_344 ] . V_12 != NULL ; V_344 ++ )
;
V_344 = F_308 ( F_208 ( V_183 ) , V_166 , V_344 ) ;
V_166 -> V_180 [ V_344 ] . V_12 = NULL ;
V_166 -> V_180 [ V_344 ] . F_210 = 0 ;
}
static void F_325 ( T_9 * V_281 )
{
int V_344 ;
struct V_166 * V_166 ;
V_166 = & V_281 -> V_345 [ 1 ] ;
V_344 = F_308 ( V_281 , V_166 , 0 ) ;
V_166 -> V_180 [ V_344 ] . V_12 = NULL ;
V_166 -> V_180 [ V_344 ] . F_210 = 0 ;
}
static void F_326 ( T_9 * V_281 , int V_346 )
{
int V_347 , V_344 , V_183 ;
int V_226 ;
struct V_12 * V_153 ;
struct V_166 * V_166 ;
V_166 = & V_281 -> V_345 [ 0 ] ;
V_347 = 0 ;
for ( V_226 = V_282 - 1 ; V_226 >= 0 ; V_226 -- ) {
for ( V_344 = 0 ; V_344 < V_346 ; V_344 ++ ) {
V_183 = V_348 [ V_344 ] ;
V_153 = & F_208 ( V_183 ) -> V_283 [ V_226 ] ;
if ( F_309 ( V_153 ) ) {
F_307 ( V_153 ,
& V_166 -> V_180 [ V_347 ++ ] ) ;
F_310 ( V_226 ) ;
}
}
}
V_166 -> V_180 [ V_347 ] . V_12 = NULL ;
V_166 -> V_180 [ V_347 ] . F_210 = 0 ;
}
static int F_327 ( void )
{
int V_186 , V_226 ;
unsigned long V_349 , V_350 ;
struct V_12 * V_153 ;
int V_351 ;
V_349 = 0 ;
V_350 = 0 ;
F_205 (nid) {
for ( V_226 = 0 ; V_226 < V_282 ; V_226 ++ ) {
V_153 = & F_208 ( V_186 ) -> V_283 [ V_226 ] ;
if ( F_309 ( V_153 ) ) {
if ( V_226 < V_229 )
V_349 += V_153 -> V_83 ;
V_350 += V_153 -> V_83 ;
} else if ( V_226 == V_229 ) {
return V_318 ;
}
}
}
if ( ! V_349 ||
V_349 > V_350 / 2 )
return V_318 ;
V_351 = V_350 /
( F_328 ( V_176 [ V_177 ] ) + 1 ) ;
F_205 (nid) {
V_349 = 0 ;
V_350 = 0 ;
for ( V_226 = 0 ; V_226 < V_282 ; V_226 ++ ) {
V_153 = & F_208 ( V_186 ) -> V_283 [ V_226 ] ;
if ( F_309 ( V_153 ) ) {
if ( V_226 < V_229 )
V_349 += V_153 -> V_306 ;
V_350 += V_153 -> V_306 ;
}
}
if ( V_349 &&
V_350 > V_351 &&
V_349 > V_350 * 70 / 100 )
return V_318 ;
}
return V_319 ;
}
static void F_329 ( void )
{
if ( V_316 == V_317 )
V_352 = F_327 () ;
else
V_352 = V_316 ;
}
static void F_330 ( T_9 * V_281 )
{
int V_344 , V_183 , V_353 ;
enum V_226 V_34 ;
T_5 V_354 ;
int V_355 , V_356 ;
struct V_166 * V_166 ;
int V_33 = V_352 ;
for ( V_34 = 0 ; V_34 < V_357 ; V_34 ++ ) {
V_166 = V_281 -> V_345 + V_34 ;
V_166 -> V_180 [ 0 ] . V_12 = NULL ;
V_166 -> V_180 [ 0 ] . F_210 = 0 ;
}
V_355 = V_281 -> V_358 ;
V_353 = V_202 ;
V_356 = V_355 ;
F_331 ( V_354 ) ;
memset ( V_348 , 0 , sizeof( V_348 ) ) ;
V_344 = 0 ;
while ( ( V_183 = F_320 ( V_355 , & V_354 ) ) >= 0 ) {
if ( F_206 ( V_355 , V_183 ) !=
F_206 ( V_355 , V_356 ) )
V_343 [ V_183 ] = V_353 ;
V_356 = V_183 ;
V_353 -- ;
if ( V_33 == V_318 )
F_324 ( V_281 , V_183 ) ;
else
V_348 [ V_344 ++ ] = V_183 ;
}
if ( V_33 == V_319 ) {
F_326 ( V_281 , V_344 ) ;
}
F_325 ( V_281 ) ;
}
static void F_332 ( T_9 * V_281 )
{
struct V_166 * V_166 ;
struct V_167 * V_168 ;
struct V_178 * V_153 ;
V_166 = & V_281 -> V_345 [ 0 ] ;
V_166 -> V_170 = V_168 = & V_166 -> V_359 ;
F_195 ( V_168 -> V_172 , V_173 ) ;
for ( V_153 = V_166 -> V_180 ; V_153 -> V_12 ; V_153 ++ )
V_168 -> V_181 [ V_153 - V_166 -> V_180 ] = F_333 ( V_153 ) ;
}
int F_334 ( int V_183 )
{
struct V_12 * V_12 ;
( void ) F_256 ( F_257 ( V_183 , V_267 ) ,
F_262 ( V_267 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_183 ;
}
static void F_329 ( void )
{
V_352 = V_319 ;
}
static void F_330 ( T_9 * V_281 )
{
int V_183 , V_355 ;
enum V_226 V_344 ;
struct V_166 * V_166 ;
V_355 = V_281 -> V_358 ;
V_166 = & V_281 -> V_345 [ 0 ] ;
V_344 = F_308 ( V_281 , V_166 , 0 ) ;
for ( V_183 = V_355 + 1 ; V_183 < V_342 ; V_183 ++ ) {
if ( ! F_335 ( V_183 ) )
continue;
V_344 = F_308 ( F_208 ( V_183 ) , V_166 , V_344 ) ;
}
for ( V_183 = 0 ; V_183 < V_355 ; V_183 ++ ) {
if ( ! F_335 ( V_183 ) )
continue;
V_344 = F_308 ( F_208 ( V_183 ) , V_166 , V_344 ) ;
}
V_166 -> V_180 [ V_344 ] . V_12 = NULL ;
V_166 -> V_180 [ V_344 ] . F_210 = 0 ;
}
static void F_332 ( T_9 * V_281 )
{
V_281 -> V_345 [ 0 ] . V_170 = NULL ;
}
static int F_336 ( void * V_331 )
{
int V_186 ;
int V_117 ;
T_9 * V_360 = V_331 ;
#ifdef V_194
memset ( V_343 , 0 , sizeof( V_343 ) ) ;
#endif
if ( V_360 && ! F_335 ( V_360 -> V_358 ) ) {
F_330 ( V_360 ) ;
F_332 ( V_360 ) ;
}
F_205 (nid) {
T_9 * V_281 = F_208 ( V_186 ) ;
F_330 ( V_281 ) ;
F_332 ( V_281 ) ;
}
F_337 (cpu) {
F_338 ( & F_339 ( V_361 , V_117 ) , 0 ) ;
#ifdef F_340
if ( F_341 ( V_117 ) )
F_342 ( V_117 , F_334 ( F_343 ( V_117 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_318 ( T_9 * V_281 , struct V_12 * V_12 )
{
F_329 () ;
if ( V_362 == V_363 ) {
F_336 ( NULL ) ;
F_344 () ;
F_345 () ;
} else {
#ifdef F_346
if ( V_12 )
F_347 ( V_12 ) ;
#endif
F_348 ( F_336 , V_281 , NULL ) ;
}
V_364 = F_289 () ;
if ( V_364 < ( V_84 * V_286 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_23 ( L_72
L_73 ,
V_202 ,
V_365 [ V_352 ] ,
V_7 ? L_74 : L_75 ,
V_364 ) ;
#ifdef V_194
F_23 ( L_76 , V_366 [ V_367 ] ) ;
#endif
}
static inline unsigned long F_349 ( unsigned long V_105 )
{
unsigned long V_90 = 1 ;
V_105 /= V_368 ;
while ( V_90 < V_105 )
V_90 <<= 1 ;
V_90 = V_158 ( V_90 , 4096UL ) ;
return F_350 ( V_90 , 4UL ) ;
}
static inline unsigned long F_349 ( unsigned long V_105 )
{
return 4096UL ;
}
static inline unsigned long F_351 ( unsigned long V_90 )
{
return F_352 ( ~ V_90 ) ;
}
static int F_353 ( unsigned long V_17 , unsigned long V_98 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 ++ ) {
if ( ! F_16 ( V_15 ) || F_354 ( F_127 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_355 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_98 , V_369 ;
struct V_5 * V_5 ;
unsigned long V_370 ;
int V_371 ;
int V_372 ;
V_17 = V_12 -> V_18 ;
V_98 = F_152 ( V_12 ) ;
V_17 = F_356 ( V_17 , V_84 ) ;
V_371 = F_356 ( F_303 ( V_12 ) , V_84 ) >>
V_86 ;
V_371 = V_158 ( 2 , V_371 ) ;
V_372 = V_12 -> V_373 ;
if ( V_371 == V_372 )
return;
V_12 -> V_373 = V_371 ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 += V_84 ) {
if ( ! F_153 ( V_15 ) )
continue;
V_5 = F_127 ( V_15 ) ;
if ( F_123 ( V_5 ) != F_124 ( V_12 ) )
continue;
V_370 = F_102 ( V_5 ) ;
if ( V_371 > 0 ) {
V_369 = V_158 ( V_15 + V_84 , V_98 ) ;
if ( F_353 ( V_15 , V_369 ) )
continue;
if ( V_370 == V_109 ) {
V_371 -- ;
continue;
}
if ( V_370 == V_127 ) {
F_6 ( V_5 ,
V_109 ) ;
F_126 ( V_12 , V_5 ,
V_109 ) ;
V_371 -- ;
continue;
}
} else if ( ! V_372 ) {
break;
}
if ( V_370 == V_109 ) {
F_6 ( V_5 , V_127 ) ;
F_126 ( V_12 , V_5 , V_127 ) ;
}
}
}
void T_14 F_357 ( unsigned long V_90 , int V_186 , unsigned long V_12 ,
unsigned long V_17 , enum V_374 V_375 )
{
struct V_5 * V_5 ;
unsigned long V_98 = V_17 + V_90 ;
unsigned long V_15 ;
struct V_12 * V_153 ;
if ( V_376 < V_98 - 1 )
V_376 = V_98 - 1 ;
V_153 = & F_208 ( V_186 ) -> V_283 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 ++ ) {
if ( V_375 == V_377 ) {
if ( ! F_358 ( V_15 ) )
continue;
if ( ! F_359 ( V_15 , V_186 ) )
continue;
}
V_5 = F_127 ( V_15 ) ;
F_360 ( V_5 , V_12 , V_186 , V_15 ) ;
F_361 ( V_5 , V_12 , V_186 , V_15 ) ;
F_362 ( V_5 ) ;
F_21 ( V_5 ) ;
F_76 ( V_5 ) ;
F_363 ( V_5 ) ;
if ( ( V_153 -> V_18 <= V_15 )
&& ( V_15 < F_152 ( V_153 ) )
&& ! ( V_15 & ( V_84 - 1 ) ) )
F_6 ( V_5 , V_127 ) ;
F_115 ( & V_5 -> V_54 ) ;
#ifdef F_364
if ( ! F_365 ( V_12 ) )
F_366 ( V_5 , F_367 ( V_15 << V_378 ) ) ;
#endif
}
}
static void T_14 F_368 ( struct V_12 * V_12 )
{
int V_33 , V_125 ;
F_156 (order, t) {
F_115 ( & V_12 -> V_55 [ V_33 ] . V_59 [ V_125 ] ) ;
V_12 -> V_55 [ V_33 ] . V_56 = 0 ;
}
}
static int T_14 F_369 ( struct V_12 * V_12 )
{
#ifdef F_370
int V_114 ;
V_114 = V_12 -> V_83 / 1024 ;
if ( V_114 * V_80 > 512 * 1024 )
V_114 = ( 512 * 1024 ) / V_80 ;
V_114 /= 4 ;
if ( V_114 < 1 )
V_114 = 1 ;
V_114 = F_371 ( V_114 + V_114 / 2 ) - 1 ;
return V_114 ;
#else
return 0 ;
#endif
}
static void F_372 ( struct V_67 * V_68 , unsigned long V_88 ,
unsigned long V_114 )
{
V_68 -> V_114 = 1 ;
F_36 () ;
V_68 -> V_88 = V_88 ;
F_36 () ;
V_68 -> V_114 = V_114 ;
}
static void F_373 ( struct V_118 * V_36 , unsigned long V_114 )
{
F_372 ( & V_36 -> V_68 , 6 * V_114 , F_350 ( 1UL , 1 * V_114 ) ) ;
}
static void F_374 ( struct V_118 * V_36 )
{
struct V_67 * V_68 ;
int V_6 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_68 = & V_36 -> V_68 ;
V_68 -> V_66 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_115 ( & V_68 -> V_75 [ V_6 ] ) ;
}
static void F_338 ( struct V_118 * V_36 , unsigned long V_114 )
{
F_374 ( V_36 ) ;
F_373 ( V_36 , V_114 ) ;
}
static void F_375 ( struct V_118 * V_36 ,
unsigned long V_88 )
{
unsigned long V_114 = F_350 ( 1UL , V_88 / 4 ) ;
if ( ( V_88 / 4 ) > ( V_378 * 8 ) )
V_114 = V_378 * 8 ;
F_372 ( & V_36 -> V_68 , V_88 , V_114 ) ;
}
static void T_14 F_376 ( struct V_12 * V_12 ,
struct V_118 * V_68 )
{
if ( V_379 )
F_375 ( V_68 ,
( V_12 -> V_83 /
V_379 ) ) ;
else
F_373 ( V_68 , F_369 ( V_12 ) ) ;
}
static void T_14 F_377 ( struct V_12 * V_12 , int V_117 )
{
struct V_118 * V_68 = F_141 ( V_12 -> V_120 , V_117 ) ;
F_374 ( V_68 ) ;
F_376 ( V_12 , V_68 ) ;
}
static void T_14 F_347 ( struct V_12 * V_12 )
{
int V_117 ;
V_12 -> V_120 = F_378 ( struct V_118 ) ;
F_337 (cpu)
F_377 ( V_12 , V_117 ) ;
}
void T_2 F_379 ( void )
{
struct V_12 * V_12 ;
F_140 (zone)
F_347 ( V_12 ) ;
}
static T_15 T_16
int F_380 ( struct V_12 * V_12 , unsigned long V_380 )
{
int V_34 ;
T_8 V_381 ;
V_12 -> F_349 =
F_349 ( V_380 ) ;
V_12 -> F_351 =
F_351 ( V_12 -> F_349 ) ;
V_381 = V_12 -> F_349
* sizeof( V_382 ) ;
if ( ! F_381 () ) {
V_12 -> V_383 = ( V_382 * )
F_382 (
V_381 , V_12 -> V_184 -> V_358 ) ;
} else {
V_12 -> V_383 = F_383 ( V_381 ) ;
}
if ( ! V_12 -> V_383 )
return - V_152 ;
for ( V_34 = 0 ; V_34 < V_12 -> F_349 ; ++ V_34 )
F_384 ( V_12 -> V_383 + V_34 ) ;
return 0 ;
}
static T_14 void F_385 ( struct V_12 * V_12 )
{
V_12 -> V_120 = & V_361 ;
if ( F_309 ( V_12 ) )
F_23 ( V_384 L_77 ,
V_12 -> V_289 , V_12 -> V_306 ,
F_369 ( V_12 ) ) ;
}
int T_14 F_386 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_90 ,
enum V_374 V_375 )
{
struct V_385 * V_281 = V_12 -> V_184 ;
int V_13 ;
V_13 = F_380 ( V_12 , V_90 ) ;
if ( V_13 )
return V_13 ;
V_281 -> V_314 = F_210 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_387 ( V_386 , L_78 ,
L_79 ,
V_281 -> V_358 ,
( unsigned long ) F_210 ( V_12 ) ,
V_18 , ( V_18 + V_90 ) ) ;
F_368 ( V_12 ) ;
return 0 ;
}
int T_14 F_388 ( unsigned long V_15 )
{
unsigned long V_17 , V_98 ;
int V_186 ;
static unsigned long T_17 V_387 , V_388 ;
static int T_17 V_389 ;
if ( V_387 <= V_15 && V_15 < V_388 )
return V_389 ;
V_186 = F_389 ( V_15 , & V_17 , & V_98 ) ;
if ( V_186 != - 1 ) {
V_387 = V_17 ;
V_388 = V_98 ;
V_389 = V_186 ;
}
return V_186 ;
}
int T_14 F_390 ( unsigned long V_15 )
{
int V_186 ;
V_186 = F_388 ( V_15 ) ;
if ( V_186 >= 0 )
return V_186 ;
return 0 ;
}
bool T_14 F_359 ( unsigned long V_15 , int V_183 )
{
int V_186 ;
V_186 = F_388 ( V_15 ) ;
if ( V_186 >= 0 && V_186 != V_183 )
return false ;
return true ;
}
void T_2 F_391 ( int V_186 , unsigned long V_390 )
{
unsigned long V_17 , V_98 ;
int V_34 , V_391 ;
F_392 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = V_158 ( V_17 , V_390 ) ;
V_98 = V_158 ( V_98 , V_390 ) ;
if ( V_17 < V_98 )
F_393 ( F_394 ( V_17 ) ,
( V_98 - V_17 ) << V_378 ,
V_391 ) ;
}
}
void T_2 F_395 ( int V_186 )
{
unsigned long V_17 , V_98 ;
int V_34 , V_391 ;
F_392 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_396 ( V_391 , V_17 , V_98 ) ;
}
void T_14 F_397 ( unsigned int V_186 ,
unsigned long * V_17 , unsigned long * V_98 )
{
unsigned long V_392 , V_393 ;
int V_34 ;
* V_17 = - 1UL ;
* V_98 = 0 ;
F_392 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = V_158 ( * V_17 , V_392 ) ;
* V_98 = F_350 ( * V_98 , V_393 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_398 ( void )
{
int V_394 ;
for ( V_394 = V_282 - 1 ; V_394 >= 0 ; V_394 -- ) {
if ( V_394 == V_395 )
continue;
if ( V_396 [ V_394 ] >
V_397 [ V_394 ] )
break;
}
F_43 ( V_394 == - 1 ) ;
V_398 = V_394 ;
}
static void T_14 F_399 ( int V_186 ,
unsigned long V_226 ,
unsigned long V_399 ,
unsigned long V_400 ,
unsigned long * V_18 ,
unsigned long * F_152 )
{
if ( V_401 [ V_186 ] ) {
if ( V_226 == V_395 ) {
* V_18 = V_401 [ V_186 ] ;
* F_152 = V_158 ( V_400 ,
V_396 [ V_398 ] ) ;
} else if ( * V_18 < V_401 [ V_186 ] &&
* F_152 > V_401 [ V_186 ] ) {
* F_152 = V_401 [ V_186 ] ;
} else if ( * V_18 >= V_401 [ V_186 ] )
* V_18 = * F_152 ;
}
}
static unsigned long T_14 F_400 ( int V_186 ,
unsigned long V_226 ,
unsigned long V_399 ,
unsigned long V_400 ,
unsigned long * V_402 )
{
unsigned long V_18 , F_152 ;
V_18 = V_397 [ V_226 ] ;
F_152 = V_396 [ V_226 ] ;
F_399 ( V_186 , V_226 ,
V_399 , V_400 ,
& V_18 , & F_152 ) ;
if ( F_152 < V_399 || V_18 > V_400 )
return 0 ;
F_152 = V_158 ( F_152 , V_400 ) ;
V_18 = F_350 ( V_18 , V_399 ) ;
return F_152 - V_18 ;
}
unsigned long T_14 F_401 ( int V_186 ,
unsigned long V_403 ,
unsigned long V_404 )
{
unsigned long V_405 = V_404 - V_403 ;
unsigned long V_17 , V_98 ;
int V_34 ;
F_392 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_402 ( V_17 , V_403 , V_404 ) ;
V_98 = F_402 ( V_98 , V_403 , V_404 ) ;
V_405 -= V_98 - V_17 ;
}
return V_405 ;
}
unsigned long T_2 F_403 ( unsigned long V_17 ,
unsigned long V_98 )
{
return F_401 ( V_342 , V_17 , V_98 ) ;
}
static unsigned long T_14 F_404 ( int V_186 ,
unsigned long V_226 ,
unsigned long V_399 ,
unsigned long V_400 ,
unsigned long * V_402 )
{
unsigned long V_406 = V_397 [ V_226 ] ;
unsigned long V_407 = V_396 [ V_226 ] ;
unsigned long V_18 , F_152 ;
V_18 = F_402 ( V_399 , V_406 , V_407 ) ;
F_152 = F_402 ( V_400 , V_406 , V_407 ) ;
F_399 ( V_186 , V_226 ,
V_399 , V_400 ,
& V_18 , & F_152 ) ;
return F_401 ( V_186 , V_18 , F_152 ) ;
}
static inline unsigned long T_14 F_400 ( int V_186 ,
unsigned long V_226 ,
unsigned long V_399 ,
unsigned long V_400 ,
unsigned long * V_408 )
{
return V_408 [ V_226 ] ;
}
static inline unsigned long T_14 F_404 ( int V_186 ,
unsigned long V_226 ,
unsigned long V_399 ,
unsigned long V_400 ,
unsigned long * V_409 )
{
if ( ! V_409 )
return 0 ;
return V_409 [ V_226 ] ;
}
static void T_14 F_405 ( struct V_385 * V_281 ,
unsigned long V_399 ,
unsigned long V_400 ,
unsigned long * V_408 ,
unsigned long * V_409 )
{
unsigned long V_410 , V_411 = 0 ;
enum V_226 V_34 ;
for ( V_34 = 0 ; V_34 < V_282 ; V_34 ++ )
V_411 += F_400 ( V_281 -> V_358 , V_34 ,
V_399 ,
V_400 ,
V_408 ) ;
V_281 -> V_412 = V_411 ;
V_410 = V_411 ;
for ( V_34 = 0 ; V_34 < V_282 ; V_34 ++ )
V_410 -=
F_404 ( V_281 -> V_358 , V_34 ,
V_399 , V_400 ,
V_409 ) ;
V_281 -> V_413 = V_410 ;
F_23 ( V_384 L_80 , V_281 -> V_358 ,
V_410 ) ;
}
static unsigned long T_2 F_406 ( unsigned long V_18 , unsigned long V_414 )
{
unsigned long V_415 ;
V_414 += V_18 & ( V_84 - 1 ) ;
V_415 = F_356 ( V_414 , V_84 ) ;
V_415 = V_415 >> V_86 ;
V_415 *= V_416 ;
V_415 = F_356 ( V_415 , 8 * sizeof( unsigned long ) ) ;
return V_415 / 8 ;
}
static void T_2 F_407 ( struct V_385 * V_281 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_414 )
{
unsigned long V_415 = F_406 ( V_18 , V_414 ) ;
V_12 -> V_417 = NULL ;
if ( V_415 )
V_12 -> V_417 =
F_382 ( V_415 ,
V_281 -> V_358 ) ;
}
static inline void F_407 ( struct V_385 * V_281 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_414 ) {}
void T_6 F_408 ( void )
{
unsigned int V_33 ;
if ( V_86 )
return;
if ( V_418 > V_378 )
V_33 = V_419 ;
else
V_33 = V_43 - 1 ;
V_86 = V_33 ;
}
void T_6 F_408 ( void )
{
}
static unsigned long T_6 F_409 ( unsigned long V_19 ,
unsigned long V_306 )
{
unsigned long V_105 = V_19 ;
if ( V_19 > V_306 + ( V_306 >> 4 ) &&
F_135 ( V_420 ) )
V_105 = V_306 ;
return F_280 ( V_105 * sizeof( struct V_5 ) ) >> V_378 ;
}
static void T_6 F_410 ( struct V_385 * V_281 ,
unsigned long V_399 , unsigned long V_400 ,
unsigned long * V_408 , unsigned long * V_409 )
{
enum V_226 V_344 ;
int V_186 = V_281 -> V_358 ;
unsigned long V_18 = V_281 -> V_399 ;
int V_13 ;
F_411 ( V_281 ) ;
#ifdef F_412
F_413 ( & V_281 -> V_421 ) ;
V_281 -> V_422 = 0 ;
V_281 -> V_423 = V_25 ;
#endif
F_384 ( & V_281 -> V_424 ) ;
F_384 ( & V_281 -> V_425 ) ;
F_414 ( V_281 ) ;
for ( V_344 = 0 ; V_344 < V_282 ; V_344 ++ ) {
struct V_12 * V_12 = V_281 -> V_283 + V_344 ;
unsigned long V_90 , V_426 , V_427 , V_428 ;
V_90 = F_400 ( V_186 , V_344 , V_399 ,
V_400 , V_408 ) ;
V_426 = V_427 = V_90 - F_404 ( V_186 , V_344 ,
V_399 ,
V_400 ,
V_409 ) ;
V_428 = F_409 ( V_90 , V_426 ) ;
if ( V_427 >= V_428 ) {
V_427 -= V_428 ;
if ( V_428 )
F_23 ( V_384
L_81 ,
V_366 [ V_344 ] , V_428 ) ;
} else
F_23 ( V_320
L_82 ,
V_366 [ V_344 ] , V_428 , V_427 ) ;
if ( V_344 == 0 && V_427 > V_429 ) {
V_427 -= V_429 ;
F_23 ( V_384 L_83 ,
V_366 [ 0 ] , V_429 ) ;
}
if ( ! F_365 ( V_344 ) )
V_430 += V_427 ;
else if ( V_430 > V_428 * 2 )
V_430 -= V_428 ;
V_431 += V_427 ;
V_12 -> V_19 = V_90 ;
V_12 -> V_306 = V_426 ;
V_12 -> V_83 = F_365 ( V_344 ) ? V_426 : V_427 ;
#ifdef V_194
V_12 -> V_183 = V_186 ;
V_12 -> V_432 = ( V_427 * V_433 )
/ 100 ;
V_12 -> V_434 = ( V_427 * V_435 ) / 100 ;
#endif
V_12 -> V_289 = V_366 [ V_344 ] ;
F_413 ( & V_12 -> V_71 ) ;
F_413 ( & V_12 -> V_436 ) ;
F_415 ( V_12 ) ;
V_12 -> V_184 = V_281 ;
F_385 ( V_12 ) ;
F_248 ( V_12 , V_136 , V_12 -> V_83 ) ;
F_416 ( & V_12 -> V_437 ) ;
if ( ! V_90 )
continue;
F_408 () ;
F_407 ( V_281 , V_12 , V_18 , V_90 ) ;
V_13 = F_386 ( V_12 , V_18 ,
V_90 , V_377 ) ;
F_122 ( V_13 ) ;
F_417 ( V_90 , V_186 , V_344 , V_18 ) ;
V_18 += V_90 ;
}
}
static void T_16 F_418 ( struct V_385 * V_281 )
{
if ( ! V_281 -> V_412 )
return;
#ifdef F_419
if ( ! V_281 -> V_438 ) {
unsigned long V_90 , V_439 , V_264 ;
struct V_5 * V_440 ;
V_439 = V_281 -> V_399 & ~ ( V_441 - 1 ) ;
V_264 = F_420 ( V_281 ) ;
V_264 = F_421 ( V_264 , V_441 ) ;
V_90 = ( V_264 - V_439 ) * sizeof( struct V_5 ) ;
V_440 = F_422 ( V_281 -> V_358 , V_90 ) ;
if ( ! V_440 )
V_440 = F_382 ( V_90 ,
V_281 -> V_358 ) ;
V_281 -> V_438 = V_440 + ( V_281 -> V_399 - V_439 ) ;
}
#ifndef F_423
if ( V_281 == F_208 ( 0 ) ) {
V_442 = F_208 ( 0 ) -> V_438 ;
#ifdef F_424
if ( F_10 ( V_442 ) != V_281 -> V_399 )
V_442 -= ( V_281 -> V_399 - V_443 ) ;
#endif
}
#endif
#endif
}
void T_6 F_425 ( int V_186 , unsigned long * V_408 ,
unsigned long V_399 , unsigned long * V_409 )
{
T_9 * V_281 = F_208 ( V_186 ) ;
unsigned long V_17 = 0 ;
unsigned long V_98 = 0 ;
F_2 ( V_281 -> V_314 || V_281 -> V_155 ) ;
V_281 -> V_358 = V_186 ;
V_281 -> V_399 = V_399 ;
F_204 ( V_186 ) ;
#ifdef F_424
F_397 ( V_186 , & V_17 , & V_98 ) ;
#endif
F_405 ( V_281 , V_17 , V_98 ,
V_408 , V_409 ) ;
F_418 ( V_281 ) ;
#ifdef F_419
F_23 ( V_384 L_84 ,
V_186 , ( unsigned long ) V_281 ,
( unsigned long ) V_281 -> V_438 ) ;
#endif
F_410 ( V_281 , V_17 , V_98 ,
V_408 , V_409 ) ;
}
void T_2 F_426 ( void )
{
unsigned int V_183 ;
unsigned int V_444 = 0 ;
F_427 (node, node_possible_map)
V_444 = V_183 ;
V_445 = V_444 + 1 ;
}
unsigned long T_2 F_428 ( void )
{
unsigned long V_446 = 0 , V_447 = 0 ;
unsigned long V_439 , V_264 , V_448 ;
int V_389 = - 1 ;
int V_34 , V_186 ;
F_392 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_439 || V_389 < 0 || V_389 == V_186 ) {
V_389 = V_186 ;
V_447 = V_264 ;
continue;
}
V_448 = ~ ( ( 1 << F_429 ( V_439 ) ) - 1 ) ;
while ( V_448 && V_447 <= ( V_439 & ( V_448 << 1 ) ) )
V_448 <<= 1 ;
V_446 |= V_448 ;
}
return ~ V_446 + 1 ;
}
static unsigned long T_2 F_430 ( int V_186 )
{
unsigned long V_449 = V_450 ;
unsigned long V_17 ;
int V_34 ;
F_392 (i, nid, &start_pfn, NULL, NULL)
V_449 = V_158 ( V_449 , V_17 ) ;
if ( V_449 == V_450 ) {
F_23 ( V_320
L_85 , V_186 ) ;
return 0 ;
}
return V_449 ;
}
unsigned long T_2 F_431 ( void )
{
return F_430 ( V_342 ) ;
}
static unsigned long T_2 F_432 ( void )
{
unsigned long V_411 = 0 ;
unsigned long V_17 , V_98 ;
int V_34 , V_186 ;
F_392 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_105 = V_98 - V_17 ;
V_411 += V_105 ;
if ( V_105 )
F_433 ( V_186 , V_177 ) ;
}
return V_411 ;
}
static void T_2 F_434 ( void )
{
int V_34 , V_186 ;
unsigned long V_451 ;
unsigned long V_452 , V_453 ;
T_5 V_454 = V_176 [ V_177 ] ;
unsigned long V_411 = F_432 () ;
int V_455 = F_328 ( V_176 [ V_177 ] ) ;
struct V_456 * type = & V_457 . V_458 ;
F_398 () ;
if ( F_435 () ) {
for ( V_34 = 0 ; V_34 < type -> V_459 ; V_34 ++ ) {
if ( ! F_436 ( & type -> V_460 [ V_34 ] ) )
continue;
V_186 = type -> V_460 [ V_34 ] . V_186 ;
V_451 = F_437 ( type -> V_460 [ V_34 ] . V_461 ) ;
V_401 [ V_186 ] = V_401 [ V_186 ] ?
V_158 ( V_451 , V_401 [ V_186 ] ) :
V_451 ;
}
goto V_462;
}
if ( V_463 ) {
unsigned long V_464 ;
V_463 =
F_356 ( V_463 , V_441 ) ;
V_464 = V_411 - V_463 ;
V_465 = F_350 ( V_465 , V_464 ) ;
}
if ( ! V_465 )
goto V_26;
V_451 = V_397 [ V_398 ] ;
V_250:
V_452 = V_465 / V_455 ;
F_322 (nid, N_MEMORY) {
unsigned long V_17 , V_98 ;
if ( V_465 < V_452 )
V_452 = V_465 / V_455 ;
V_453 = V_452 ;
F_392 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_466 ;
V_17 = F_350 ( V_17 , V_401 [ V_186 ] ) ;
if ( V_17 >= V_98 )
continue;
if ( V_17 < V_451 ) {
unsigned long V_467 ;
V_467 = V_158 ( V_98 , V_451 )
- V_17 ;
V_453 -= V_158 ( V_467 ,
V_453 ) ;
V_465 -= V_158 ( V_467 ,
V_465 ) ;
if ( V_98 <= V_451 ) {
V_401 [ V_186 ] = V_98 ;
continue;
}
V_17 = V_451 ;
}
V_466 = V_98 - V_17 ;
if ( V_466 > V_453 )
V_466 = V_453 ;
V_401 [ V_186 ] = V_17 + V_466 ;
V_465 -= V_158 ( V_465 ,
V_466 ) ;
V_453 -= V_466 ;
if ( ! V_453 )
break;
}
}
V_455 -- ;
if ( V_455 && V_465 > V_455 )
goto V_250;
V_462:
for ( V_186 = 0 ; V_186 < V_342 ; V_186 ++ )
V_401 [ V_186 ] =
F_356 ( V_401 [ V_186 ] , V_441 ) ;
V_26:
V_176 [ V_177 ] = V_454 ;
}
static void F_438 ( T_9 * V_281 , int V_186 )
{
enum V_226 V_226 ;
if ( V_177 == V_468 )
return;
for ( V_226 = 0 ; V_226 <= V_395 - 1 ; V_226 ++ ) {
struct V_12 * V_12 = & V_281 -> V_283 [ V_226 ] ;
if ( F_309 ( V_12 ) ) {
F_433 ( V_186 , V_469 ) ;
if ( V_468 != V_469 &&
V_226 <= V_229 )
F_433 ( V_186 , V_468 ) ;
break;
}
}
}
void T_2 F_439 ( unsigned long * V_124 )
{
unsigned long V_17 , V_98 ;
int V_34 , V_186 ;
memset ( V_397 , 0 ,
sizeof( V_397 ) ) ;
memset ( V_396 , 0 ,
sizeof( V_396 ) ) ;
V_397 [ 0 ] = F_431 () ;
V_396 [ 0 ] = V_124 [ 0 ] ;
for ( V_34 = 1 ; V_34 < V_282 ; V_34 ++ ) {
if ( V_34 == V_395 )
continue;
V_397 [ V_34 ] =
V_396 [ V_34 - 1 ] ;
V_396 [ V_34 ] =
F_350 ( V_124 [ V_34 ] , V_397 [ V_34 ] ) ;
}
V_397 [ V_395 ] = 0 ;
V_396 [ V_395 ] = 0 ;
memset ( V_401 , 0 , sizeof( V_401 ) ) ;
F_434 () ;
F_23 ( L_86 ) ;
for ( V_34 = 0 ; V_34 < V_282 ; V_34 ++ ) {
if ( V_34 == V_395 )
continue;
F_23 ( V_470 L_87 , V_366 [ V_34 ] ) ;
if ( V_397 [ V_34 ] ==
V_396 [ V_34 ] )
F_23 ( V_470 L_88 ) ;
else
F_23 ( V_470 L_89 ,
V_397 [ V_34 ] << V_378 ,
( V_396 [ V_34 ]
<< V_378 ) - 1 ) ;
}
F_23 ( L_90 ) ;
for ( V_34 = 0 ; V_34 < V_342 ; V_34 ++ ) {
if ( V_401 [ V_34 ] )
F_23 ( L_91 , V_34 ,
V_401 [ V_34 ] << V_378 ) ;
}
F_23 ( L_92 ) ;
F_392 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_23 ( L_93 , V_186 ,
V_17 << V_378 , ( V_98 << V_378 ) - 1 ) ;
F_440 () ;
F_426 () ;
F_205 (nid) {
T_9 * V_281 = F_208 ( V_186 ) ;
F_425 ( V_186 , NULL ,
F_430 ( V_186 ) , NULL ) ;
if ( V_281 -> V_413 )
F_433 ( V_186 , V_177 ) ;
F_438 ( V_281 , V_186 ) ;
}
}
static int T_2 F_441 ( char * V_36 , unsigned long * V_471 )
{
unsigned long long V_472 ;
if ( ! V_36 )
return - V_321 ;
V_472 = F_442 ( V_36 , & V_36 ) ;
* V_471 = V_472 >> V_378 ;
F_2 ( ( V_472 >> V_378 ) > V_450 ) ;
return 0 ;
}
static int T_2 F_443 ( char * V_36 )
{
return F_441 ( V_36 , & V_465 ) ;
}
static int T_2 F_444 ( char * V_36 )
{
return F_441 ( V_36 , & V_463 ) ;
}
void F_111 ( struct V_5 * V_5 , long V_66 )
{
F_78 ( & V_473 ) ;
F_17 ( V_5 ) -> V_83 += V_66 ;
V_273 += V_66 ;
#ifdef F_297
if ( F_94 ( V_5 ) )
V_278 += V_66 ;
#endif
F_87 ( & V_473 ) ;
}
unsigned long F_445 ( void * V_439 , void * V_264 , int V_474 , char * V_315 )
{
void * V_347 ;
unsigned long V_105 = 0 ;
V_439 = ( void * ) F_280 ( ( unsigned long ) V_439 ) ;
V_264 = ( void * ) ( ( unsigned long ) V_264 & V_475 ) ;
for ( V_347 = V_439 ; V_347 < V_264 ; V_347 += V_80 , V_105 ++ ) {
if ( ( unsigned int ) V_474 <= 0xFF )
memset ( V_347 , V_474 , V_80 ) ;
F_446 ( F_169 ( V_347 ) ) ;
}
if ( V_105 && V_315 )
F_447 ( L_94 ,
V_315 , V_105 << ( V_378 - 10 ) , V_439 , V_264 ) ;
return V_105 ;
}
void F_448 ( struct V_5 * V_5 )
{
F_449 ( V_5 ) ;
V_273 ++ ;
F_17 ( V_5 ) -> V_83 ++ ;
V_278 ++ ;
}
void T_2 F_450 ( const char * V_138 )
{
unsigned long V_476 , V_477 , V_478 , V_479 , V_480 ;
unsigned long V_481 , V_482 ;
V_476 = F_451 () ;
V_477 = V_483 - V_484 ;
V_478 = V_485 - V_486 ;
V_479 = V_487 - V_488 ;
V_480 = V_489 - V_490 ;
V_482 = V_491 - V_492 ;
V_481 = V_493 - V_494 ;
#define F_452 ( V_439 , V_264 , V_90 , V_347 , T_18 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_452 ( V_492 , V_491 , V_482 ,
V_494 , V_481 ) ;
F_452 ( V_484 , V_483 , V_477 , V_494 , V_481 ) ;
F_452 ( V_486 , V_485 , V_478 , V_492 , V_482 ) ;
F_452 ( V_484 , V_483 , V_477 , V_488 , V_479 ) ;
F_452 ( V_486 , V_485 , V_478 , V_488 , V_479 ) ;
#undef F_452
F_23 ( L_95
L_96
L_97
#ifdef F_297
L_98
#endif
L_99 ,
F_453 () << ( V_378 - 10 ) , V_476 << ( V_378 - 10 ) ,
V_477 >> 10 , V_478 >> 10 , V_479 >> 10 ,
( V_482 + V_481 ) >> 10 , V_480 >> 10 ,
( V_476 - V_273 ) << ( V_378 - 10 ) ,
#ifdef F_297
V_278 << ( V_378 - 10 ) ,
#endif
V_138 ? L_100 : L_101 , V_138 ? V_138 : L_101 ) ;
}
void T_2 F_454 ( unsigned long V_495 )
{
V_429 = V_495 ;
}
void T_2 F_455 ( unsigned long * V_408 )
{
F_425 ( 0 , V_408 ,
F_456 ( V_496 ) >> V_378 , NULL ) ;
}
static int F_457 ( struct V_497 * V_360 ,
unsigned long V_498 , void * V_499 )
{
int V_117 = ( unsigned long ) V_499 ;
if ( V_498 == V_500 || V_498 == V_501 ) {
F_458 ( V_117 ) ;
F_139 ( V_117 ) ;
F_459 ( V_117 ) ;
F_460 ( V_117 ) ;
}
return V_502 ;
}
void T_2 F_461 ( void )
{
F_462 ( F_457 , 0 ) ;
}
static void F_463 ( void )
{
struct V_385 * V_281 ;
unsigned long V_503 = 0 ;
enum V_226 V_34 , V_344 ;
F_464 (pgdat) {
for ( V_34 = 0 ; V_34 < V_282 ; V_34 ++ ) {
struct V_12 * V_12 = V_281 -> V_283 + V_34 ;
unsigned long F_350 = 0 ;
for ( V_344 = V_34 ; V_344 < V_282 ; V_344 ++ ) {
if ( V_12 -> V_159 [ V_344 ] > F_350 )
F_350 = V_12 -> V_159 [ V_344 ] ;
}
F_350 += F_249 ( V_12 ) ;
if ( F_350 > V_12 -> V_83 )
F_350 = V_12 -> V_83 ;
V_503 += F_350 ;
V_12 -> V_504 = F_350 ;
}
}
V_504 = V_503 ;
V_505 = V_503 ;
}
static void F_465 ( void )
{
struct V_385 * V_281 ;
enum V_226 V_344 , V_506 ;
F_464 (pgdat) {
for ( V_344 = 0 ; V_344 < V_282 ; V_344 ++ ) {
struct V_12 * V_12 = V_281 -> V_283 + V_344 ;
unsigned long V_83 = V_12 -> V_83 ;
V_12 -> V_159 [ V_344 ] = 0 ;
V_506 = V_344 ;
while ( V_506 ) {
struct V_12 * V_507 ;
V_506 -- ;
if ( V_508 [ V_506 ] < 1 )
V_508 [ V_506 ] = 1 ;
V_507 = V_281 -> V_283 + V_506 ;
V_507 -> V_159 [ V_344 ] = V_83 /
V_508 [ V_506 ] ;
V_83 += V_507 -> V_83 ;
}
}
}
F_463 () ;
}
static void F_466 ( void )
{
unsigned long V_509 = V_510 >> ( V_378 - 10 ) ;
unsigned long V_511 = 0 ;
struct V_12 * V_12 ;
unsigned long V_63 ;
F_467 (zone) {
if ( ! F_468 ( V_12 ) )
V_511 += V_12 -> V_83 ;
}
F_467 (zone) {
T_19 V_288 ;
F_151 ( & V_12 -> V_71 , V_63 ) ;
V_288 = ( T_19 ) V_509 * V_12 -> V_83 ;
F_469 ( V_288 , V_511 ) ;
if ( F_468 ( V_12 ) ) {
unsigned long V_512 ;
V_512 = V_12 -> V_83 / 1024 ;
V_512 = F_402 ( V_512 , V_513 , 128UL ) ;
V_12 -> V_129 [ V_514 ] = V_512 ;
} else {
V_12 -> V_129 [ V_514 ] = V_288 ;
}
V_12 -> V_129 [ V_515 ] = F_303 ( V_12 ) + ( V_288 >> 2 ) ;
V_12 -> V_129 [ V_516 ] = F_303 ( V_12 ) + ( V_288 >> 1 ) ;
F_85 ( V_12 , V_136 ,
F_249 ( V_12 ) -
F_171 ( V_12 ) -
F_190 ( V_12 , V_136 ) ) ;
F_355 ( V_12 ) ;
F_159 ( & V_12 -> V_71 , V_63 ) ;
}
F_463 () ;
}
void F_470 ( void )
{
F_316 ( & V_333 ) ;
F_466 () ;
F_319 ( & V_333 ) ;
}
static void T_14 F_471 ( struct V_12 * V_12 )
{
unsigned int V_517 , V_518 ;
V_517 = V_12 -> V_83 >> ( 30 - V_378 ) ;
if ( V_517 )
V_518 = F_472 ( 10 * V_517 ) ;
else
V_518 = 1 ;
V_12 -> V_519 = V_518 ;
}
static void T_14 F_473 ( void )
{
struct V_12 * V_12 ;
F_467 (zone)
F_471 ( V_12 ) ;
}
int T_14 F_474 ( void )
{
unsigned long V_520 ;
int V_521 ;
V_520 = F_288 () * ( V_80 >> 10 ) ;
V_521 = F_472 ( V_520 * 16 ) ;
if ( V_521 > V_522 ) {
V_510 = V_521 ;
if ( V_510 < 128 )
V_510 = 128 ;
if ( V_510 > 65536 )
V_510 = 65536 ;
} else {
F_220 ( L_102 ,
V_521 , V_522 ) ;
}
F_470 () ;
F_475 () ;
F_465 () ;
F_473 () ;
return 0 ;
}
int F_476 ( T_10 * V_324 , int V_325 ,
void T_11 * V_326 , T_8 * V_327 , T_12 * V_328 )
{
int V_523 ;
V_523 = F_477 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_523 )
return V_523 ;
if ( V_325 ) {
V_522 = V_510 ;
F_470 () ;
}
return 0 ;
}
int F_478 ( T_10 * V_324 , int V_325 ,
void T_11 * V_326 , T_8 * V_327 , T_12 * V_328 )
{
struct V_12 * V_12 ;
int V_523 ;
V_523 = F_477 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_523 )
return V_523 ;
F_467 (zone)
V_12 -> V_432 = ( V_12 -> V_83 *
V_433 ) / 100 ;
return 0 ;
}
int F_479 ( T_10 * V_324 , int V_325 ,
void T_11 * V_326 , T_8 * V_327 , T_12 * V_328 )
{
struct V_12 * V_12 ;
int V_523 ;
V_523 = F_477 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_523 )
return V_523 ;
F_467 (zone)
V_12 -> V_434 = ( V_12 -> V_83 *
V_435 ) / 100 ;
return 0 ;
}
int F_480 ( T_10 * V_324 , int V_325 ,
void T_11 * V_326 , T_8 * V_327 , T_12 * V_328 )
{
F_477 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
F_465 () ;
return 0 ;
}
int F_481 ( T_10 * V_324 , int V_325 ,
void T_11 * V_326 , T_8 * V_327 , T_12 * V_328 )
{
struct V_12 * V_12 ;
unsigned int V_117 ;
int V_13 ;
V_13 = F_477 ( V_324 , V_325 , V_326 , V_327 , V_328 ) ;
if ( ! V_325 || ( V_13 < 0 ) )
return V_13 ;
F_316 ( & V_524 ) ;
F_140 (zone) {
unsigned long V_88 ;
V_88 = V_12 -> V_83 / V_379 ;
F_337 (cpu)
F_375 ( F_141 ( V_12 -> V_120 , V_117 ) ,
V_88 ) ;
}
F_319 ( & V_524 ) ;
return 0 ;
}
static int T_2 F_482 ( char * V_138 )
{
if ( ! V_138 )
return 0 ;
V_525 = F_483 ( V_138 , & V_138 , 0 ) ;
return 1 ;
}
void * T_2 F_484 ( const char * V_526 ,
unsigned long V_527 ,
unsigned long V_528 ,
int V_529 ,
int V_63 ,
unsigned int * V_530 ,
unsigned int * V_531 ,
unsigned long V_532 ,
unsigned long V_533 )
{
unsigned long long F_350 = V_533 ;
unsigned long V_534 , V_90 ;
void * V_324 = NULL ;
if ( ! V_528 ) {
V_528 = V_430 ;
if ( V_378 < 20 )
V_528 = F_485 ( V_528 , ( 1 << 20 ) / V_80 ) ;
if ( V_529 > V_378 )
V_528 >>= ( V_529 - V_378 ) ;
else
V_528 <<= ( V_378 - V_529 ) ;
if ( F_7 ( V_63 & V_535 ) ) {
F_2 ( ! ( V_63 & V_536 ) ) ;
if ( ! ( V_528 >> * V_530 ) ) {
V_528 = 1UL << * V_530 ;
F_122 ( ! V_528 ) ;
}
} else if ( F_7 ( ( V_528 * V_527 ) < V_80 ) )
V_528 = V_80 / V_527 ;
}
V_528 = F_486 ( V_528 ) ;
if ( F_350 == 0 ) {
F_350 = ( ( unsigned long long ) V_431 << V_378 ) >> 4 ;
F_469 ( F_350 , V_527 ) ;
}
F_350 = V_158 ( F_350 , 0x80000000ULL ) ;
if ( V_528 < V_532 )
V_528 = V_532 ;
if ( V_528 > F_350 )
V_528 = F_350 ;
V_534 = F_487 ( V_528 ) ;
do {
V_90 = V_527 << V_534 ;
if ( V_63 & V_536 )
V_324 = F_488 ( V_90 , 0 ) ;
else if ( V_525 )
V_324 = F_489 ( V_90 , V_537 , V_538 ) ;
else {
if ( F_283 ( V_90 ) < V_43 ) {
V_324 = F_282 ( V_90 , V_537 ) ;
F_490 ( V_324 , V_90 , 1 , V_537 ) ;
}
}
} while ( ! V_324 && V_90 > V_80 && -- V_534 );
if ( ! V_324 )
F_491 ( L_103 , V_526 ) ;
F_23 ( V_46 L_104 ,
V_526 ,
( 1UL << V_534 ) ,
F_487 ( V_90 ) - V_378 ,
V_90 ) ;
if ( V_530 )
* V_530 = V_534 ;
if ( V_531 )
* V_531 = ( 1 << V_534 ) - 1 ;
return V_324 ;
}
static inline unsigned long * F_492 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_420
return F_493 ( V_15 ) -> V_417 ;
#else
return V_12 -> V_417 ;
#endif
}
static inline int F_494 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_420
V_15 &= ( V_539 - 1 ) ;
return ( V_15 >> V_86 ) * V_416 ;
#else
V_15 = V_15 - F_495 ( V_12 -> V_18 , V_84 ) ;
return ( V_15 >> V_86 ) * V_416 ;
#endif
}
unsigned long F_496 ( struct V_5 * V_5 ,
int V_540 , int V_541 )
{
struct V_12 * V_12 ;
unsigned long * V_542 ;
unsigned long V_15 , V_543 ;
unsigned long V_63 = 0 ;
unsigned long V_544 = 1 ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
V_542 = F_492 ( V_12 , V_15 ) ;
V_543 = F_494 ( V_12 , V_15 ) ;
for (; V_540 <= V_541 ; V_540 ++ , V_544 <<= 1 )
if ( F_198 ( V_543 + V_540 , V_542 ) )
V_63 |= V_544 ;
return V_63 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_63 ,
int V_540 , int V_541 )
{
struct V_12 * V_12 ;
unsigned long * V_542 ;
unsigned long V_15 , V_543 ;
unsigned long V_544 = 1 ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
V_542 = F_492 ( V_12 , V_15 ) ;
V_543 = F_494 ( V_12 , V_15 ) ;
F_62 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
for (; V_540 <= V_541 ; V_540 ++ , V_544 <<= 1 )
if ( V_63 & V_544 )
F_49 ( V_543 + V_540 , V_542 ) ;
else
F_51 ( V_543 + V_540 , V_542 ) ;
}
bool F_497 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_66 ,
bool V_545 )
{
unsigned long V_15 , V_546 , V_547 ;
int V_76 ;
if ( F_210 ( V_12 ) == V_395 )
return false ;
V_76 = F_102 ( V_5 ) ;
if ( V_76 == V_127 || F_86 ( V_76 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_547 = 0 , V_546 = 0 ; V_546 < V_84 ; V_546 ++ ) {
unsigned long V_548 = V_15 + V_546 ;
if ( ! F_16 ( V_548 ) )
continue;
V_5 = F_127 ( V_548 ) ;
if ( F_498 ( V_5 ) ) {
V_546 = F_485 ( V_546 + 1 , 1 << F_30 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_74 ( & V_5 -> V_62 ) ) {
if ( F_64 ( V_5 ) )
V_546 += ( 1 << F_61 ( V_5 ) ) - 1 ;
continue;
}
if ( V_545 && F_20 ( V_5 ) )
continue;
if ( ! F_499 ( V_5 ) )
V_547 ++ ;
if ( V_547 > V_66 )
return true ;
}
return false ;
}
bool F_500 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_335 ( F_123 ( V_5 ) ) )
return false ;
V_12 = F_17 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_497 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_501 ( unsigned long V_15 )
{
return V_15 & ~ ( F_502 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_503 ( unsigned long V_15 )
{
return F_421 ( V_15 , F_502 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_504 ( struct V_549 * V_550 ,
unsigned long V_439 , unsigned long V_264 )
{
unsigned long V_551 ;
unsigned long V_15 = V_439 ;
unsigned int V_552 = 0 ;
int V_13 = 0 ;
F_505 () ;
while ( V_15 < V_264 || ! F_79 ( & V_550 -> V_553 ) ) {
if ( F_506 ( V_29 ) ) {
V_13 = - V_554 ;
break;
}
if ( F_79 ( & V_550 -> V_553 ) ) {
V_550 -> V_555 = 0 ;
V_15 = F_507 ( V_550 -> V_12 , V_550 ,
V_15 , V_264 , true ) ;
if ( ! V_15 ) {
V_13 = - V_554 ;
break;
}
V_552 = 0 ;
} else if ( ++ V_552 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_556 ;
break;
}
V_551 = F_508 ( V_550 -> V_12 ,
& V_550 -> V_553 ) ;
V_550 -> V_555 -= V_551 ;
V_13 = F_509 ( & V_550 -> V_553 , V_557 ,
0 , V_558 , V_559 ) ;
}
if ( V_13 < 0 ) {
F_510 ( & V_550 -> V_553 ) ;
return V_13 ;
}
return 0 ;
}
int F_511 ( unsigned long V_439 , unsigned long V_264 ,
unsigned V_6 )
{
unsigned long V_560 , V_561 ;
int V_13 = 0 , V_33 ;
struct V_549 V_550 = {
. V_555 = 0 ,
. V_33 = - 1 ,
. V_12 = F_17 ( F_127 ( V_439 ) ) ,
. V_562 = true ,
. V_563 = true ,
} ;
F_115 ( & V_550 . V_553 ) ;
V_13 = F_512 ( F_501 ( V_439 ) ,
F_503 ( V_264 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_504 ( & V_550 , V_439 , V_264 ) ;
if ( V_13 )
goto V_564;
F_513 () ;
F_144 () ;
V_33 = 0 ;
V_560 = V_439 ;
while ( ! F_64 ( F_127 ( V_560 ) ) ) {
if ( ++ V_33 >= V_43 ) {
V_13 = - V_556 ;
goto V_564;
}
V_560 &= ~ 0UL << V_33 ;
}
if ( F_514 ( V_560 , V_264 , false ) ) {
F_220 ( L_105 ,
V_560 , V_264 ) ;
V_13 = - V_556 ;
goto V_564;
}
V_561 = F_515 ( & V_550 , V_560 , V_264 ) ;
if ( ! V_561 ) {
V_13 = - V_556 ;
goto V_564;
}
if ( V_439 != V_560 )
F_516 ( V_560 , V_439 - V_560 ) ;
if ( V_264 != V_561 )
F_516 ( V_264 , V_561 - V_264 ) ;
V_564:
F_517 ( F_501 ( V_439 ) ,
F_503 ( V_264 ) , V_6 ) ;
return V_13 ;
}
void F_516 ( unsigned long V_15 , unsigned V_35 )
{
unsigned int V_66 = 0 ;
for (; V_35 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
V_66 += F_63 ( V_5 ) != 1 ;
F_518 ( V_5 ) ;
}
F_519 ( V_66 != 0 , L_106 , V_66 ) ;
}
void T_14 F_520 ( struct V_12 * V_12 )
{
unsigned V_117 ;
F_316 ( & V_524 ) ;
F_337 (cpu)
F_376 ( V_12 ,
F_141 ( V_12 -> V_120 , V_117 ) ) ;
F_319 ( & V_524 ) ;
}
void F_521 ( struct V_12 * V_12 )
{
unsigned long V_63 ;
int V_117 ;
struct V_118 * V_119 ;
F_100 ( V_63 ) ;
if ( V_12 -> V_120 != & V_361 ) {
F_145 (cpu) {
V_119 = F_141 ( V_12 -> V_120 , V_117 ) ;
F_522 ( V_12 , V_119 ) ;
}
F_523 ( V_12 -> V_120 ) ;
V_12 -> V_120 = & V_361 ;
}
F_104 ( V_63 ) ;
}
void
F_524 ( unsigned long V_17 , unsigned long V_98 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
int V_33 , V_34 ;
unsigned long V_15 ;
unsigned long V_63 ;
for ( V_15 = V_17 ; V_15 < V_98 ; V_15 ++ )
if ( F_153 ( V_15 ) )
break;
if ( V_15 == V_98 )
return;
V_12 = F_17 ( F_127 ( V_15 ) ) ;
F_151 ( & V_12 -> V_71 , V_63 ) ;
V_15 = V_17 ;
while ( V_15 < V_98 ) {
if ( ! F_153 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_127 ( V_15 ) ;
if ( F_7 ( ! F_64 ( V_5 ) && F_20 ( V_5 ) ) ) {
V_15 ++ ;
F_363 ( V_5 ) ;
continue;
}
F_122 ( F_63 ( V_5 ) ) ;
F_122 ( ! F_64 ( V_5 ) ) ;
V_33 = F_61 ( V_5 ) ;
#ifdef F_525
F_23 ( V_46 L_107 ,
V_15 , 1 << V_33 , V_98 ) ;
#endif
F_69 ( & V_5 -> V_54 ) ;
F_55 ( V_5 ) ;
V_12 -> V_55 [ V_33 ] . V_56 -- ;
for ( V_34 = 0 ; V_34 < ( 1 << V_33 ) ; V_34 ++ )
F_363 ( ( V_5 + V_34 ) ) ;
V_15 += ( 1 << V_33 ) ;
}
F_159 ( & V_12 -> V_71 , V_63 ) ;
}
bool F_526 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_17 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_63 ;
int V_33 ;
F_151 ( & V_12 -> V_71 , V_63 ) ;
for ( V_33 = 0 ; V_33 < V_43 ; V_33 ++ ) {
struct V_5 * V_565 = V_5 - ( V_15 & ( ( 1 << V_33 ) - 1 ) ) ;
if ( F_64 ( V_565 ) && F_61 ( V_565 ) >= V_33 )
break;
}
F_159 ( & V_12 -> V_71 , V_63 ) ;
return V_33 < V_43 ;
}
static void F_527 ( unsigned long V_63 )
{
const char * V_566 = L_101 ;
unsigned long V_448 ;
int V_34 ;
F_213 ( F_528 ( V_567 ) != V_568 ) ;
F_23 ( V_27 L_108 , V_63 ) ;
V_63 &= ( 1UL << V_569 ) - 1 ;
for ( V_34 = 0 ; V_34 < F_528 ( V_567 ) && V_63 ; V_34 ++ ) {
V_448 = V_567 [ V_34 ] . V_448 ;
if ( ( V_63 & V_448 ) != V_448 )
continue;
V_63 &= ~ V_448 ;
F_23 ( L_109 , V_566 , V_567 [ V_34 ] . V_289 ) ;
V_566 = L_110 ;
}
if ( V_63 )
F_23 ( L_111 , V_566 , V_63 ) ;
F_23 ( L_112 ) ;
}
void F_24 ( struct V_5 * V_5 , char * V_20 , unsigned long V_570 )
{
F_23 ( V_27
L_113 ,
V_5 , F_74 ( & V_5 -> V_62 ) , F_73 ( V_5 ) ,
V_5 -> V_61 , V_5 -> V_571 ) ;
F_527 ( V_5 -> V_63 ) ;
if ( V_20 )
F_529 ( L_114 , V_20 ) ;
if ( V_5 -> V_63 & V_570 ) {
F_529 ( L_115 ) ;
F_527 ( V_5 -> V_63 & V_570 ) ;
}
F_530 ( V_5 ) ;
}
void F_531 ( struct V_5 * V_5 , char * V_20 )
{
F_24 ( V_5 , V_20 , 0 ) ;
}
