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
unsigned long V_43 ;
if ( F_48 ( V_42 , 10 , & V_43 ) < 0 || V_43 > V_44 / 2 ) {
F_24 ( V_45 L_7 ) ;
return 0 ;
}
V_46 = V_43 ;
F_24 ( V_47 L_8 , V_43 ) ;
return 0 ;
}
static inline void F_49 ( struct V_5 * V_5 )
{
F_50 ( V_48 , & V_5 -> V_49 ) ;
}
static inline void F_51 ( struct V_5 * V_5 )
{
F_52 ( V_48 , & V_5 -> V_49 ) ;
}
static inline void F_49 ( struct V_5 * V_5 ) { }
static inline void F_51 ( struct V_5 * V_5 ) { }
static inline void F_53 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_54 ( V_5 , V_34 ) ;
F_55 ( V_5 ) ;
}
static inline void F_56 ( struct V_5 * V_5 )
{
F_57 ( V_5 ) ;
F_54 ( V_5 , 0 ) ;
}
static inline unsigned long
F_58 ( unsigned long V_50 , unsigned int V_34 )
{
return V_50 ^ ( 1 << V_34 ) ;
}
static inline int F_59 ( struct V_5 * V_5 , struct V_5 * V_51 ,
unsigned int V_34 )
{
if ( ! F_17 ( F_10 ( V_51 ) ) )
return 0 ;
if ( F_60 ( V_51 ) && F_61 ( V_51 ) == V_34 ) {
F_62 ( F_63 ( V_51 ) != 0 , V_51 ) ;
if ( F_64 ( V_5 ) != F_64 ( V_51 ) )
return 0 ;
return 1 ;
}
if ( F_65 ( V_51 ) && F_61 ( V_51 ) == V_34 ) {
F_62 ( F_63 ( V_51 ) != 0 , V_51 ) ;
if ( F_64 ( V_5 ) != F_64 ( V_51 ) )
return 0 ;
return 1 ;
}
return 0 ;
}
static inline void F_66 ( struct V_5 * V_5 ,
unsigned long V_15 ,
struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned long V_50 ;
unsigned long V_52 ;
unsigned long V_53 ( V_54 ) ;
struct V_5 * V_51 ;
F_44 ( ! F_67 ( V_12 ) ) ;
if ( F_7 ( F_68 ( V_5 ) ) )
if ( F_7 ( F_39 ( V_5 , V_34 ) ) )
return;
F_44 ( V_6 == - 1 ) ;
V_50 = V_15 & ( ( 1 << V_44 ) - 1 ) ;
F_62 ( V_50 & ( ( 1 << V_34 ) - 1 ) , V_5 ) ;
F_62 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
while ( V_34 < V_44 - 1 ) {
V_54 = F_58 ( V_50 , V_34 ) ;
V_51 = V_5 + ( V_54 - V_50 ) ;
if ( ! F_59 ( V_5 , V_51 , V_34 ) )
break;
if ( F_60 ( V_51 ) ) {
F_51 ( V_51 ) ;
F_54 ( V_5 , 0 ) ;
F_69 ( V_12 , 1 << V_34 ,
V_6 ) ;
} else {
F_70 ( & V_51 -> V_55 ) ;
V_12 -> V_56 [ V_34 ] . V_57 -- ;
F_56 ( V_51 ) ;
}
V_52 = V_54 & V_50 ;
V_5 = V_5 + ( V_52 - V_50 ) ;
V_50 = V_52 ;
V_34 ++ ;
}
F_53 ( V_5 , V_34 ) ;
if ( ( V_34 < V_44 - 2 ) && F_17 ( F_10 ( V_51 ) ) ) {
struct V_5 * V_58 , * V_59 ;
V_52 = V_54 & V_50 ;
V_58 = V_5 + ( V_52 - V_50 ) ;
V_54 = F_58 ( V_52 , V_34 + 1 ) ;
V_59 = V_58 + ( V_54 - V_52 ) ;
if ( F_59 ( V_58 , V_59 , V_34 + 1 ) ) {
F_71 ( & V_5 -> V_55 ,
& V_12 -> V_56 [ V_34 ] . V_60 [ V_6 ] ) ;
goto V_27;
}
}
F_72 ( & V_5 -> V_55 , & V_12 -> V_56 [ V_34 ] . V_60 [ V_6 ] ) ;
V_27:
V_12 -> V_56 [ V_34 ] . V_57 ++ ;
}
static inline int F_73 ( struct V_5 * V_5 )
{
const char * V_61 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_74 ( V_5 ) ) )
V_61 = L_9 ;
if ( F_7 ( V_5 -> V_62 != NULL ) )
V_61 = L_10 ;
if ( F_7 ( F_75 ( & V_5 -> V_63 ) != 0 ) )
V_61 = L_11 ;
if ( F_7 ( V_5 -> V_64 & V_65 ) ) {
V_61 = L_12 ;
V_22 = V_65 ;
}
if ( F_7 ( F_76 ( V_5 ) ) )
V_61 = L_13 ;
if ( F_7 ( V_61 ) ) {
F_20 ( V_5 , V_61 , V_22 ) ;
return 1 ;
}
F_77 ( V_5 ) ;
if ( V_5 -> V_64 & V_66 )
V_5 -> V_64 &= ~ V_66 ;
return 0 ;
}
static void F_78 ( struct V_12 * V_12 , int V_67 ,
struct V_68 * V_69 )
{
int V_6 = 0 ;
int V_70 = 0 ;
int V_71 = V_67 ;
unsigned long V_72 ;
F_79 ( & V_12 -> V_73 ) ;
V_72 = F_80 ( V_12 , V_74 ) ;
if ( V_72 )
F_81 ( V_12 , V_74 , - V_72 ) ;
while ( V_71 ) {
struct V_5 * V_5 ;
struct V_75 * V_76 ;
do {
V_70 ++ ;
if ( ++ V_6 == V_8 )
V_6 = 0 ;
V_76 = & V_69 -> V_77 [ V_6 ] ;
} while ( F_82 ( V_76 ) );
if ( V_70 == V_8 )
V_70 = V_71 ;
do {
int V_78 ;
V_5 = F_83 ( V_76 -> V_79 , struct V_5 , V_55 ) ;
F_70 ( & V_5 -> V_55 ) ;
V_78 = F_84 ( V_5 ) ;
F_66 ( V_5 , F_10 ( V_5 ) , V_12 , 0 , V_78 ) ;
F_85 ( V_5 , 0 , V_78 ) ;
if ( F_86 ( ! F_87 ( V_5 ) ) ) {
F_81 ( V_12 , V_80 , 1 ) ;
if ( F_88 ( V_78 ) )
F_81 ( V_12 , V_81 , 1 ) ;
}
} while ( -- V_71 && -- V_70 && ! F_82 ( V_76 ) );
}
F_89 ( & V_12 -> V_73 ) ;
}
static void F_90 ( struct V_12 * V_12 ,
struct V_5 * V_5 , unsigned long V_15 ,
unsigned int V_34 ,
int V_6 )
{
unsigned long V_72 ;
F_79 ( & V_12 -> V_73 ) ;
V_72 = F_80 ( V_12 , V_74 ) ;
if ( V_72 )
F_81 ( V_12 , V_74 , - V_72 ) ;
F_66 ( V_5 , V_15 , V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! F_91 ( V_6 ) ) )
F_69 ( V_12 , 1 << V_34 , V_6 ) ;
F_89 ( & V_12 -> V_73 ) ;
}
static bool F_92 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
int V_39 = 0 ;
F_93 ( V_5 , V_34 ) ;
F_94 ( V_5 , V_34 ) ;
if ( F_95 ( V_5 ) )
V_5 -> V_62 = NULL ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
V_39 += F_73 ( V_5 + V_35 ) ;
if ( V_39 )
return false ;
if ( ! F_96 ( V_5 ) ) {
F_97 ( F_98 ( V_5 ) ,
V_82 << V_34 ) ;
F_99 ( F_98 ( V_5 ) ,
V_82 << V_34 ) ;
}
F_100 ( V_5 , V_34 ) ;
F_101 ( V_5 , 1 << V_34 , 0 ) ;
return true ;
}
static void F_30 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_64 ;
int V_6 ;
unsigned long V_15 = F_10 ( V_5 ) ;
if ( ! F_92 ( V_5 , V_34 ) )
return;
V_6 = F_102 ( V_5 , V_15 ) ;
F_103 ( V_64 ) ;
F_104 ( V_83 , 1 << V_34 ) ;
F_105 ( V_5 , V_6 ) ;
F_90 ( F_18 ( V_5 ) , V_5 , V_15 , V_34 , V_6 ) ;
F_106 ( V_64 ) ;
}
void T_2 F_107 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned int V_36 = 1 << V_34 ;
struct V_5 * V_37 = V_5 ;
unsigned int V_84 ;
F_108 ( V_37 ) ;
for ( V_84 = 0 ; V_84 < ( V_36 - 1 ) ; V_84 ++ , V_37 ++ ) {
F_108 ( V_37 + 1 ) ;
F_109 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
}
F_109 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
F_18 ( V_5 ) -> V_85 += V_36 ;
F_110 ( V_5 ) ;
F_111 ( V_5 , V_34 ) ;
}
void T_2 F_112 ( struct V_5 * V_5 )
{
unsigned V_35 = V_86 ;
struct V_5 * V_37 = V_5 ;
do {
F_109 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
} while ( ++ V_37 , -- V_35 );
F_6 ( V_5 , V_87 ) ;
if ( V_88 >= V_44 ) {
V_35 = V_86 ;
V_37 = V_5 ;
do {
F_110 ( V_37 ) ;
F_111 ( V_37 , V_44 - 1 ) ;
V_37 += V_89 ;
} while ( V_35 -= V_89 );
} else {
F_110 ( V_5 ) ;
F_111 ( V_5 , V_88 ) ;
}
F_113 ( V_5 , V_86 ) ;
}
static inline void F_114 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_90 , int V_91 , struct V_56 * V_92 ,
int V_6 )
{
unsigned long V_93 = 1 << V_91 ;
while ( V_91 > V_90 ) {
V_92 -- ;
V_91 -- ;
V_93 >>= 1 ;
F_62 ( F_19 ( V_12 , & V_5 [ V_93 ] ) , & V_5 [ V_93 ] ) ;
#ifdef F_115
if ( V_91 < F_116 () ) {
F_117 ( & V_5 [ V_93 ] . V_55 ) ;
F_49 ( & V_5 [ V_93 ] ) ;
F_54 ( & V_5 [ V_93 ] , V_91 ) ;
F_69 ( V_12 , - ( 1 << V_91 ) ,
V_6 ) ;
continue;
}
#endif
F_72 ( & V_5 [ V_93 ] . V_55 , & V_92 -> V_60 [ V_6 ] ) ;
V_92 -> V_57 ++ ;
F_53 ( & V_5 [ V_93 ] , V_91 ) ;
}
}
static inline int F_118 ( struct V_5 * V_5 )
{
const char * V_61 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_74 ( V_5 ) ) )
V_61 = L_9 ;
if ( F_7 ( V_5 -> V_62 != NULL ) )
V_61 = L_10 ;
if ( F_7 ( F_75 ( & V_5 -> V_63 ) != 0 ) )
V_61 = L_11 ;
if ( F_7 ( V_5 -> V_64 & V_66 ) ) {
V_61 = L_14 ;
V_22 = V_66 ;
}
if ( F_7 ( F_76 ( V_5 ) ) )
V_61 = L_13 ;
if ( F_7 ( V_61 ) ) {
F_20 ( V_5 , V_61 , V_22 ) ;
return 1 ;
}
return 0 ;
}
static int F_119 ( struct V_5 * V_5 , unsigned int V_34 , T_1 V_40 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
struct V_5 * V_37 = V_5 + V_35 ;
if ( F_7 ( F_118 ( V_37 ) ) )
return 1 ;
}
F_54 ( V_5 , 0 ) ;
F_110 ( V_5 ) ;
F_120 ( V_5 , V_34 ) ;
F_101 ( V_5 , 1 << V_34 , 1 ) ;
if ( V_40 & V_94 )
F_43 ( V_5 , V_34 , V_40 ) ;
if ( V_34 && ( V_40 & V_95 ) )
F_32 ( V_5 , V_34 ) ;
return 0 ;
}
static inline
struct V_5 * F_121 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned int V_96 ;
struct V_56 * V_92 ;
struct V_5 * V_5 ;
for ( V_96 = V_34 ; V_96 < V_44 ; ++ V_96 ) {
V_92 = & ( V_12 -> V_56 [ V_96 ] ) ;
if ( F_82 ( & V_92 -> V_60 [ V_6 ] ) )
continue;
V_5 = F_83 ( V_92 -> V_60 [ V_6 ] . V_97 ,
struct V_5 , V_55 ) ;
F_70 ( & V_5 -> V_55 ) ;
F_56 ( V_5 ) ;
V_92 -> V_57 -- ;
F_114 ( V_12 , V_5 , V_34 , V_96 , V_92 , V_6 ) ;
F_105 ( V_5 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_122 ( struct V_12 * V_12 ,
struct V_5 * V_98 , struct V_5 * V_99 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_34 ;
int V_100 = 0 ;
#ifndef F_123
F_124 ( F_18 ( V_98 ) != F_18 ( V_99 ) ) ;
#endif
for ( V_5 = V_98 ; V_5 <= V_99 ; ) {
F_62 ( F_125 ( V_5 ) != F_15 ( V_12 ) , V_5 ) ;
if ( ! F_17 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_65 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_34 = F_61 ( V_5 ) ;
F_126 ( & V_5 -> V_55 ,
& V_12 -> V_56 [ V_34 ] . V_60 [ V_6 ] ) ;
F_105 ( V_5 , V_6 ) ;
V_5 += 1 << V_34 ;
V_100 += 1 << V_34 ;
}
return V_100 ;
}
int F_127 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_17 , V_101 ;
struct V_5 * V_98 , * V_99 ;
V_17 = F_10 ( V_5 ) ;
V_17 = V_17 & ~ ( V_86 - 1 ) ;
V_98 = F_128 ( V_17 ) ;
V_99 = V_98 + V_86 - 1 ;
V_101 = V_17 + V_86 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_98 = V_5 ;
if ( ! F_12 ( V_12 , V_101 ) )
return 0 ;
return F_122 ( V_12 , V_98 , V_99 , V_6 ) ;
}
static void F_129 ( struct V_5 * V_102 ,
int V_103 , int V_6 )
{
int V_104 = 1 << ( V_103 - V_88 ) ;
while ( V_104 -- ) {
F_6 ( V_102 , V_6 ) ;
V_102 += V_86 ;
}
}
static int F_130 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_105 , int V_106 )
{
int V_96 = F_61 ( V_5 ) ;
if ( F_88 ( V_106 ) )
return V_106 ;
if ( V_96 >= V_88 ) {
F_129 ( V_5 , V_96 , V_105 ) ;
return V_105 ;
}
if ( V_96 >= V_88 / 2 ||
V_105 == V_107 ||
V_7 ) {
int V_108 ;
V_108 = F_127 ( V_12 , V_5 , V_105 ) ;
if ( V_108 >= ( 1 << ( V_88 - 1 ) ) ||
V_7 ) {
F_6 ( V_5 , V_105 ) ;
return V_105 ;
}
}
return V_106 ;
}
static inline struct V_5 *
F_131 ( struct V_12 * V_12 , unsigned int V_34 , int V_109 )
{
struct V_56 * V_92 ;
unsigned int V_96 ;
struct V_5 * V_5 ;
int V_6 , V_110 , V_35 ;
for ( V_96 = V_44 - 1 ;
V_96 >= V_34 && V_96 <= V_44 - 1 ;
-- V_96 ) {
for ( V_35 = 0 ; ; V_35 ++ ) {
V_6 = V_111 [ V_109 ] [ V_35 ] ;
if ( V_6 == V_112 )
break;
V_92 = & ( V_12 -> V_56 [ V_96 ] ) ;
if ( F_82 ( & V_92 -> V_60 [ V_6 ] ) )
continue;
V_5 = F_83 ( V_92 -> V_60 [ V_6 ] . V_97 ,
struct V_5 , V_55 ) ;
V_92 -> V_57 -- ;
V_110 = F_130 ( V_12 , V_5 ,
V_109 ,
V_6 ) ;
F_70 ( & V_5 -> V_55 ) ;
F_56 ( V_5 ) ;
F_114 ( V_12 , V_5 , V_34 , V_96 , V_92 ,
V_110 ) ;
F_105 ( V_5 , V_110 ) ;
F_132 ( V_5 , V_34 , V_96 ,
V_109 , V_6 , V_110 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_133 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
struct V_5 * V_5 ;
V_113:
V_5 = F_121 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_112 ) {
V_5 = F_131 ( V_12 , V_34 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_112 ;
goto V_113;
}
}
F_134 ( V_5 , V_34 , V_6 ) ;
return V_5 ;
}
static int F_135 ( struct V_12 * V_12 , unsigned int V_34 ,
unsigned long V_67 , struct V_75 * V_76 ,
int V_6 , bool V_114 )
{
int V_35 ;
F_79 ( & V_12 -> V_73 ) ;
for ( V_35 = 0 ; V_35 < V_67 ; ++ V_35 ) {
struct V_5 * V_5 = F_133 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_86 ( ! V_114 ) )
F_72 ( & V_5 -> V_55 , V_76 ) ;
else
F_71 ( & V_5 -> V_55 , V_76 ) ;
V_76 = & V_5 -> V_55 ;
if ( F_88 ( F_84 ( V_5 ) ) )
F_81 ( V_12 , V_81 ,
- ( 1 << V_34 ) ) ;
}
F_81 ( V_12 , V_80 , - ( V_35 << V_34 ) ) ;
F_89 ( & V_12 -> V_73 ) ;
return V_35 ;
}
void F_136 ( struct V_12 * V_12 , struct V_68 * V_69 )
{
unsigned long V_64 ;
int V_115 , V_116 ;
F_103 ( V_64 ) ;
V_116 = F_137 ( V_69 -> V_116 ) ;
V_115 = F_138 ( V_69 -> V_67 , V_116 ) ;
if ( V_115 > 0 ) {
F_78 ( V_12 , V_115 , V_69 ) ;
V_69 -> V_67 -= V_115 ;
}
F_106 ( V_64 ) ;
}
static void F_139 ( unsigned int V_117 )
{
unsigned long V_64 ;
struct V_12 * V_12 ;
F_140 (zone) {
struct V_118 * V_119 ;
struct V_68 * V_69 ;
F_103 ( V_64 ) ;
V_119 = F_141 ( V_12 -> V_120 , V_117 ) ;
V_69 = & V_119 -> V_69 ;
if ( V_69 -> V_67 ) {
F_78 ( V_12 , V_69 -> V_67 , V_69 ) ;
V_69 -> V_67 = 0 ;
}
F_106 ( V_64 ) ;
}
}
void F_142 ( void * V_121 )
{
F_139 ( F_143 () ) ;
}
void F_144 ( void )
{
int V_117 ;
struct V_118 * V_69 ;
struct V_12 * V_12 ;
static T_3 V_122 ;
F_145 (cpu) {
bool V_123 = false ;
F_140 (zone) {
V_69 = F_141 ( V_12 -> V_120 , V_117 ) ;
if ( V_69 -> V_69 . V_67 ) {
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
unsigned long V_64 ;
unsigned int V_34 , V_125 ;
struct V_75 * V_126 ;
if ( F_150 ( V_12 ) )
return;
F_151 ( & V_12 -> V_73 , V_64 ) ;
V_124 = F_152 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_124 ; V_15 ++ )
if ( F_153 ( V_15 ) ) {
struct V_5 * V_5 = F_128 ( V_15 ) ;
if ( ! F_154 ( V_5 ) )
F_155 ( V_5 ) ;
}
F_156 (order, t) {
F_157 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_35 ;
V_15 = F_10 ( F_83 ( V_126 , struct V_5 , V_55 ) ) ;
for ( V_35 = 0 ; V_35 < ( 1UL << V_34 ) ; V_35 ++ )
F_158 ( F_128 ( V_15 + V_35 ) ) ;
}
}
F_159 ( & V_12 -> V_73 , V_64 ) ;
}
void F_160 ( struct V_5 * V_5 , bool V_114 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
struct V_68 * V_69 ;
unsigned long V_64 ;
unsigned long V_15 = F_10 ( V_5 ) ;
int V_6 ;
if ( ! F_92 ( V_5 , 0 ) )
return;
V_6 = F_102 ( V_5 , V_15 ) ;
F_105 ( V_5 , V_6 ) ;
F_103 ( V_64 ) ;
F_161 ( V_83 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_91 ( V_6 ) ) ) {
F_90 ( V_12 , V_5 , V_15 , 0 , V_6 ) ;
goto V_27;
}
V_6 = V_127 ;
}
V_69 = & F_162 ( V_12 -> V_120 ) -> V_69 ;
if ( ! V_114 )
F_72 ( & V_5 -> V_55 , & V_69 -> V_77 [ V_6 ] ) ;
else
F_71 ( & V_5 -> V_55 , & V_69 -> V_77 [ V_6 ] ) ;
V_69 -> V_67 ++ ;
if ( V_69 -> V_67 >= V_69 -> V_91 ) {
unsigned long V_116 = F_137 ( V_69 -> V_116 ) ;
F_78 ( V_12 , V_116 , V_69 ) ;
V_69 -> V_67 -= V_116 ;
}
V_27:
F_106 ( V_64 ) ;
}
void F_163 ( struct V_75 * V_76 , bool V_114 )
{
struct V_5 * V_5 , * V_97 ;
F_164 (page, next, list, lru) {
F_165 ( V_5 , V_114 ) ;
F_160 ( V_5 , V_114 ) ;
}
}
void F_166 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
F_62 ( F_68 ( V_5 ) , V_5 ) ;
F_62 ( ! F_63 ( V_5 ) , V_5 ) ;
#ifdef F_167
if ( F_168 ( V_5 ) )
F_166 ( F_169 ( V_5 [ 0 ] . V_128 ) , V_34 ) ;
#endif
for ( V_35 = 1 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_110 ( V_5 + V_35 ) ;
}
static int F_170 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_129 ;
struct V_12 * V_12 ;
int V_78 ;
F_124 ( ! F_65 ( V_5 ) ) ;
V_12 = F_18 ( V_5 ) ;
V_78 = F_171 ( V_5 ) ;
if ( ! F_91 ( V_78 ) ) {
V_129 = F_172 ( V_12 ) + ( 1 << V_34 ) ;
if ( ! F_173 ( V_12 , 0 , V_129 , 0 , 0 ) )
return 0 ;
F_69 ( V_12 , - ( 1UL << V_34 ) , V_78 ) ;
}
F_70 ( & V_5 -> V_55 ) ;
V_12 -> V_56 [ V_34 ] . V_57 -- ;
F_56 ( V_5 ) ;
if ( V_34 >= V_88 - 1 ) {
struct V_5 * V_130 = V_5 + ( 1 << V_34 ) - 1 ;
for (; V_5 < V_130 ; V_5 += V_86 ) {
int V_78 = F_171 ( V_5 ) ;
if ( ! F_91 ( V_78 ) && ! F_88 ( V_78 ) )
F_6 ( V_5 ,
V_127 ) ;
}
}
return 1UL << V_34 ;
}
int F_174 ( struct V_5 * V_5 )
{
unsigned int V_34 ;
int V_36 ;
V_34 = F_61 ( V_5 ) ;
V_36 = F_170 ( V_5 , V_34 ) ;
if ( ! V_36 )
return 0 ;
F_110 ( V_5 ) ;
F_166 ( V_5 , V_34 ) ;
return V_36 ;
}
static inline
struct V_5 * F_175 ( struct V_12 * V_131 ,
struct V_12 * V_12 , unsigned int V_34 ,
T_1 V_40 , int V_6 )
{
unsigned long V_64 ;
struct V_5 * V_5 ;
bool V_114 = ( ( V_40 & V_132 ) != 0 ) ;
V_133:
if ( F_86 ( V_34 == 0 ) ) {
struct V_68 * V_69 ;
struct V_75 * V_76 ;
F_103 ( V_64 ) ;
V_69 = & F_162 ( V_12 -> V_120 ) -> V_69 ;
V_76 = & V_69 -> V_77 [ V_6 ] ;
if ( F_82 ( V_76 ) ) {
V_69 -> V_67 += F_135 ( V_12 , 0 ,
V_69 -> V_116 , V_76 ,
V_6 , V_114 ) ;
if ( F_7 ( F_82 ( V_76 ) ) )
goto V_134;
}
if ( V_114 )
V_5 = F_83 ( V_76 -> V_79 , struct V_5 , V_55 ) ;
else
V_5 = F_83 ( V_76 -> V_97 , struct V_5 , V_55 ) ;
F_70 ( & V_5 -> V_55 ) ;
V_69 -> V_67 -- ;
} else {
if ( F_7 ( V_40 & V_135 ) ) {
F_176 ( V_34 > 1 ) ;
}
F_151 ( & V_12 -> V_73 , V_64 ) ;
V_5 = F_133 ( V_12 , V_34 , V_6 ) ;
F_89 ( & V_12 -> V_73 ) ;
if ( ! V_5 )
goto V_134;
F_69 ( V_12 , - ( 1 << V_34 ) ,
F_84 ( V_5 ) ) ;
}
F_81 ( V_12 , V_136 , - ( 1 << V_34 ) ) ;
if ( F_177 ( & V_12 -> V_137 [ V_136 ] ) <= 0 &&
! F_178 ( V_12 ) )
F_179 ( V_12 , V_138 ) ;
F_180 ( V_139 , V_12 , 1 << V_34 ) ;
F_181 ( V_131 , V_12 , V_40 ) ;
F_106 ( V_64 ) ;
F_62 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
if ( F_119 ( V_5 , V_34 , V_40 ) )
goto V_133;
return V_5 ;
V_134:
F_106 ( V_64 ) ;
return NULL ;
}
static int T_2 F_182 ( char * V_140 )
{
return F_183 ( & V_141 . V_142 , V_140 ) ;
}
static bool F_184 ( T_1 V_143 , unsigned int V_34 )
{
if ( V_34 < V_141 . V_144 )
return false ;
if ( V_143 & V_135 )
return false ;
if ( V_141 . V_145 && ( V_143 & V_41 ) )
return false ;
if ( V_141 . V_146 && ( V_143 & V_147 ) )
return false ;
return F_185 ( & V_141 . V_142 , 1 << V_34 ) ;
}
static int T_2 F_186 ( void )
{
T_4 V_148 = V_149 | V_150 | V_151 ;
struct V_152 * V_153 ;
V_153 = F_187 ( L_15 , NULL ,
& V_141 . V_142 ) ;
if ( F_188 ( V_153 ) )
return F_189 ( V_153 ) ;
if ( ! F_190 ( L_16 , V_148 , V_153 ,
& V_141 . V_146 ) )
goto V_154;
if ( ! F_190 ( L_17 , V_148 , V_153 ,
& V_141 . V_145 ) )
goto V_154;
if ( ! F_191 ( L_18 , V_148 , V_153 ,
& V_141 . V_144 ) )
goto V_154;
return 0 ;
V_154:
F_192 ( V_153 ) ;
return - V_155 ;
}
static inline bool F_184 ( T_1 V_143 , unsigned int V_34 )
{
return false ;
}
static bool F_193 ( struct V_12 * V_156 , unsigned int V_34 ,
unsigned long V_157 , int V_158 , int V_159 ,
long V_160 )
{
long F_138 = V_157 ;
int V_161 ;
long V_162 = 0 ;
V_160 -= ( 1 << V_34 ) - 1 ;
if ( V_159 & V_163 )
F_138 -= F_138 / 2 ;
if ( V_159 & V_164 )
F_138 -= F_138 / 4 ;
#ifdef F_194
if ( ! ( V_159 & V_165 ) )
V_162 = F_80 ( V_156 , V_81 ) ;
#endif
if ( V_160 - V_162 <= F_138 + V_156 -> V_166 [ V_158 ] )
return false ;
for ( V_161 = 0 ; V_161 < V_34 ; V_161 ++ ) {
V_160 -= V_156 -> V_56 [ V_161 ] . V_57 << V_161 ;
F_138 >>= 1 ;
if ( V_160 <= F_138 )
return false ;
}
return true ;
}
bool F_173 ( struct V_12 * V_156 , unsigned int V_34 , unsigned long V_157 ,
int V_158 , int V_159 )
{
return F_193 ( V_156 , V_34 , V_157 , V_158 , V_159 ,
F_80 ( V_156 , V_80 ) ) ;
}
bool F_195 ( struct V_12 * V_156 , unsigned int V_34 ,
unsigned long V_157 , int V_158 , int V_159 )
{
long V_160 = F_80 ( V_156 , V_80 ) ;
if ( V_156 -> V_167 && V_160 < V_156 -> V_167 )
V_160 = F_196 ( V_156 , V_80 ) ;
return F_193 ( V_156 , V_34 , V_157 , V_158 , V_159 ,
V_160 ) ;
}
static T_5 * F_197 ( struct V_168 * V_168 , int V_159 )
{
struct V_169 * V_170 ;
T_5 * V_171 ;
V_170 = V_168 -> V_172 ;
if ( ! V_170 )
return NULL ;
if ( F_198 ( V_26 , V_170 -> V_173 + V_29 ) ) {
F_199 ( V_170 -> V_174 , V_175 ) ;
V_170 -> V_173 = V_26 ;
}
V_171 = ! F_45 () && ( V_159 & V_176 ) ?
& V_177 :
& V_178 [ V_179 ] ;
return V_171 ;
}
static int F_200 ( struct V_168 * V_168 , struct V_180 * V_156 ,
T_5 * V_171 )
{
struct V_169 * V_170 ;
int V_35 ;
int V_181 ;
V_170 = V_168 -> V_172 ;
if ( ! V_170 )
return 1 ;
V_35 = V_156 - V_168 -> V_182 ;
V_181 = V_170 -> V_183 [ V_35 ] ;
return F_201 ( V_181 , * V_171 ) && ! F_202 ( V_35 , V_170 -> V_174 ) ;
}
static void F_203 ( struct V_168 * V_168 , struct V_180 * V_156 )
{
struct V_169 * V_170 ;
int V_35 ;
V_170 = V_168 -> V_172 ;
if ( ! V_170 )
return;
V_35 = V_156 - V_168 -> V_182 ;
F_204 ( V_35 , V_170 -> V_174 ) ;
}
static void F_205 ( struct V_168 * V_168 )
{
struct V_169 * V_170 ;
V_170 = V_168 -> V_172 ;
if ( ! V_170 )
return;
F_199 ( V_170 -> V_174 , V_175 ) ;
}
static bool F_206 ( struct V_12 * V_184 , struct V_12 * V_12 )
{
return V_184 -> V_185 == V_12 -> V_185 ;
}
static bool F_207 ( struct V_12 * V_184 , struct V_12 * V_12 )
{
return F_208 ( F_15 ( V_184 ) , F_15 ( V_12 ) ) <
V_186 ;
}
static T_5 * F_197 ( struct V_168 * V_168 , int V_159 )
{
return NULL ;
}
static int F_200 ( struct V_168 * V_168 , struct V_180 * V_156 ,
T_5 * V_171 )
{
return 1 ;
}
static void F_203 ( struct V_168 * V_168 , struct V_180 * V_156 )
{
}
static void F_205 ( struct V_168 * V_168 )
{
}
static bool F_206 ( struct V_12 * V_184 , struct V_12 * V_12 )
{
return true ;
}
static bool F_207 ( struct V_12 * V_184 , struct V_12 * V_12 )
{
return true ;
}
static void F_209 ( struct V_12 * V_131 )
{
struct V_12 * V_12 = V_131 -> V_187 -> V_188 ;
do {
F_210 ( V_12 , V_136 ,
F_211 ( V_12 ) - F_172 ( V_12 ) -
F_177 ( & V_12 -> V_137 [ V_136 ] ) ) ;
F_212 ( V_12 , V_138 ) ;
} while ( V_12 ++ != V_131 );
}
static struct V_5 *
F_213 ( T_1 V_143 , T_5 * V_189 , unsigned int V_34 ,
struct V_168 * V_168 , int V_190 , int V_159 ,
struct V_12 * V_131 , int V_158 , int V_6 )
{
struct V_180 * V_156 ;
struct V_5 * V_5 = NULL ;
struct V_12 * V_12 ;
T_5 * V_171 = NULL ;
int V_191 = 0 ;
int V_192 = 0 ;
bool V_193 = ( V_159 & V_194 ) &&
( V_143 & V_195 ) ;
int V_196 = 0 ;
bool V_197 ;
V_198:
V_197 = false ;
F_214 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_157 ;
if ( F_215 ( V_199 ) && V_191 &&
! F_200 ( V_168 , V_156 , V_171 ) )
continue;
if ( F_216 () &&
( V_159 & V_176 ) &&
! F_217 ( V_12 , V_143 ) )
continue;
if ( V_159 & V_200 ) {
if ( ! F_206 ( V_131 , V_12 ) )
break;
if ( F_178 ( V_12 ) ) {
V_196 ++ ;
continue;
}
}
if ( V_193 && ! F_218 ( V_12 ) )
continue;
V_157 = V_12 -> V_129 [ V_159 & V_201 ] ;
if ( ! F_173 ( V_12 , V_34 , V_157 ,
V_158 , V_159 ) ) {
int V_13 ;
F_219 ( V_202 < V_203 ) ;
if ( V_159 & V_202 )
goto V_204;
if ( F_215 ( V_199 ) &&
! V_192 && V_205 > 1 ) {
V_171 = F_197 ( V_168 , V_159 ) ;
V_191 = 1 ;
V_192 = 1 ;
}
if ( V_206 == 0 ||
! F_207 ( V_131 , V_12 ) )
goto V_207;
if ( F_215 ( V_199 ) && V_191 &&
! F_200 ( V_168 , V_156 , V_171 ) )
continue;
V_13 = F_220 ( V_12 , V_143 , V_34 ) ;
switch ( V_13 ) {
case V_208 :
continue;
case V_209 :
continue;
default:
if ( F_173 ( V_12 , V_34 , V_157 ,
V_158 , V_159 ) )
goto V_204;
if ( ( ( V_159 & V_201 ) == V_210 ) ||
V_13 == V_211 )
goto V_207;
continue;
}
}
V_204:
V_5 = F_175 ( V_131 , V_12 , V_34 ,
V_143 , V_6 ) ;
if ( V_5 )
break;
V_207:
if ( F_215 ( V_199 ) && V_191 )
F_203 ( V_168 , V_156 ) ;
}
if ( V_5 ) {
V_5 -> V_212 = ! ! ( V_159 & V_202 ) ;
return V_5 ;
}
if ( V_159 & V_200 ) {
V_159 &= ~ V_200 ;
if ( V_196 ) {
V_197 = true ;
F_209 ( V_131 ) ;
}
if ( V_205 > 1 )
V_197 = true ;
}
if ( F_7 ( F_215 ( V_199 ) && V_191 ) ) {
V_191 = 0 ;
V_197 = true ;
}
if ( V_197 )
goto V_198;
return NULL ;
}
static inline bool F_221 ( void )
{
bool V_13 = false ;
#if V_213 > 8
V_13 = F_45 () ;
#endif
return V_13 ;
}
void F_222 ( T_1 V_143 , int V_34 , const char * V_214 , ... )
{
unsigned int V_215 = V_216 ;
if ( ( V_143 & V_217 ) || ! F_223 ( & V_218 ) ||
F_116 () > 0 )
return;
if ( ! ( V_143 & V_219 ) )
if ( F_224 ( V_220 ) ||
( V_30 -> V_64 & ( V_221 | V_222 ) ) )
V_215 &= ~ V_216 ;
if ( F_45 () || ! ( V_143 & V_147 ) )
V_215 &= ~ V_216 ;
if ( V_214 ) {
struct V_223 V_224 ;
T_6 args ;
va_start ( args , V_214 ) ;
V_224 . V_214 = V_214 ;
V_224 . V_225 = & args ;
F_225 ( L_19 , & V_224 ) ;
va_end ( args ) ;
}
F_225 ( L_20 ,
V_30 -> V_31 , V_34 , V_143 ) ;
F_27 () ;
if ( ! F_221 () )
F_226 ( V_215 ) ;
}
static inline int
F_227 ( T_1 V_143 , unsigned int V_34 ,
unsigned long V_226 ,
unsigned long V_227 )
{
if ( V_143 & V_228 )
return 0 ;
if ( V_143 & V_135 )
return 1 ;
if ( ! V_226 && F_5 () )
return 0 ;
if ( V_34 <= V_229 )
return 1 ;
if ( V_143 & V_230 && V_227 < ( 1 << V_34 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_228 ( T_1 V_143 , unsigned int V_34 ,
struct V_168 * V_168 , enum V_231 V_190 ,
T_5 * V_189 , struct V_12 * V_131 ,
int V_158 , int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_229 ( V_168 , V_143 ) ) {
F_230 ( 1 ) ;
return NULL ;
}
V_5 = F_213 ( V_143 | V_232 , V_189 ,
V_34 , V_168 , V_190 ,
V_233 | V_176 ,
V_131 , V_158 , V_6 ) ;
if ( V_5 )
goto V_27;
if ( ! ( V_143 & V_135 ) ) {
if ( V_34 > V_229 )
goto V_27;
if ( V_190 < V_234 )
goto V_27;
if ( V_143 & V_235 )
goto V_27;
}
F_231 ( V_168 , V_143 , V_34 , V_189 , false ) ;
V_27:
F_232 ( V_168 , V_143 ) ;
return V_5 ;
}
static struct V_5 *
F_233 ( T_1 V_143 , unsigned int V_34 ,
struct V_168 * V_168 , enum V_231 V_190 ,
T_5 * V_189 , int V_159 , struct V_12 * V_131 ,
int V_158 , int V_6 , enum V_236 V_148 ,
bool * V_237 , bool * V_238 ,
unsigned long * V_226 )
{
if ( ! V_34 )
return NULL ;
if ( F_234 ( V_131 , V_34 ) ) {
* V_238 = true ;
return NULL ;
}
V_30 -> V_64 |= V_221 ;
* V_226 = F_235 ( V_168 , V_34 , V_143 ,
V_189 , V_148 ,
V_237 ) ;
V_30 -> V_64 &= ~ V_221 ;
if ( * V_226 != V_239 ) {
struct V_5 * V_5 ;
F_139 ( F_236 () ) ;
F_237 () ;
V_5 = F_213 ( V_143 , V_189 ,
V_34 , V_168 , V_190 ,
V_159 & ~ V_202 ,
V_131 , V_158 , V_6 ) ;
if ( V_5 ) {
V_131 -> V_240 = false ;
F_238 ( V_131 , V_34 , true ) ;
F_239 ( V_241 ) ;
return V_5 ;
}
F_239 ( V_242 ) ;
if ( V_148 != V_243 )
F_240 ( V_131 , V_34 ) ;
F_241 () ;
}
return NULL ;
}
static inline struct V_5 *
F_233 ( T_1 V_143 , unsigned int V_34 ,
struct V_168 * V_168 , enum V_231 V_190 ,
T_5 * V_189 , int V_159 , struct V_12 * V_131 ,
int V_158 , int V_6 ,
enum V_236 V_148 , bool * V_237 ,
bool * V_238 , unsigned long * V_226 )
{
return NULL ;
}
static int
F_242 ( T_1 V_143 , unsigned int V_34 , struct V_168 * V_168 ,
T_5 * V_189 )
{
struct V_244 V_244 ;
int V_245 ;
F_241 () ;
F_243 () ;
V_30 -> V_64 |= V_221 ;
F_244 ( V_143 ) ;
V_244 . V_246 = 0 ;
V_30 -> V_244 = & V_244 ;
V_245 = F_245 ( V_168 , V_34 , V_143 , V_189 ) ;
V_30 -> V_244 = NULL ;
F_246 () ;
V_30 -> V_64 &= ~ V_221 ;
F_241 () ;
return V_245 ;
}
static inline struct V_5 *
F_247 ( T_1 V_143 , unsigned int V_34 ,
struct V_168 * V_168 , enum V_231 V_190 ,
T_5 * V_189 , int V_159 , struct V_12 * V_131 ,
int V_158 , int V_6 , unsigned long * V_226 )
{
struct V_5 * V_5 = NULL ;
bool V_247 = false ;
* V_226 = F_242 ( V_143 , V_34 , V_168 ,
V_189 ) ;
if ( F_7 ( ! ( * V_226 ) ) )
return NULL ;
if ( F_215 ( V_199 ) )
F_205 ( V_168 ) ;
V_248:
V_5 = F_213 ( V_143 , V_189 , V_34 ,
V_168 , V_190 ,
V_159 & ~ V_202 ,
V_131 , V_158 ,
V_6 ) ;
if ( ! V_5 && ! V_247 ) {
F_144 () ;
V_247 = true ;
goto V_248;
}
return V_5 ;
}
static inline struct V_5 *
F_248 ( T_1 V_143 , unsigned int V_34 ,
struct V_168 * V_168 , enum V_231 V_190 ,
T_5 * V_189 , struct V_12 * V_131 ,
int V_158 , int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_213 ( V_143 , V_189 , V_34 ,
V_168 , V_190 , V_202 ,
V_131 , V_158 , V_6 ) ;
if ( ! V_5 && V_143 & V_135 )
F_249 ( V_131 , V_249 , V_29 / 50 ) ;
} while ( ! V_5 && ( V_143 & V_135 ) );
return V_5 ;
}
static void F_250 ( unsigned int V_34 ,
struct V_168 * V_168 ,
enum V_231 V_190 ,
struct V_12 * V_131 )
{
struct V_180 * V_156 ;
struct V_12 * V_12 ;
F_251 (zone, z, zonelist, high_zoneidx)
F_252 ( V_12 , V_34 , F_253 ( V_131 ) ) ;
}
static inline int
F_254 ( T_1 V_143 )
{
int V_159 = V_210 | V_176 ;
const bool V_250 = ! ( V_143 & ( V_147 | V_251 ) ) ;
F_219 ( V_252 != ( V_253 T_1 ) V_163 ) ;
V_159 |= ( V_253 int ) ( V_143 & V_252 ) ;
if ( V_250 ) {
if ( ! ( V_143 & V_219 ) )
V_159 |= V_164 ;
V_159 &= ~ V_176 ;
} else if ( F_7 ( F_255 ( V_30 ) ) && ! F_45 () )
V_159 |= V_164 ;
if ( F_86 ( ! ( V_143 & V_219 ) ) ) {
if ( V_143 & V_254 )
V_159 |= V_202 ;
else if ( F_256 () && ( V_30 -> V_64 & V_221 ) )
V_159 |= V_202 ;
else if ( ! F_45 () &&
( ( V_30 -> V_64 & V_221 ) ||
F_7 ( F_224 ( V_220 ) ) ) )
V_159 |= V_202 ;
}
#ifdef F_194
if ( F_257 ( V_143 ) == V_127 )
V_159 |= V_165 ;
#endif
return V_159 ;
}
bool F_258 ( T_1 V_143 )
{
return ! ! ( F_254 ( V_143 ) & V_202 ) ;
}
static inline struct V_5 *
F_259 ( T_1 V_143 , unsigned int V_34 ,
struct V_168 * V_168 , enum V_231 V_190 ,
T_5 * V_189 , struct V_12 * V_131 ,
int V_158 , int V_6 )
{
const T_1 V_255 = V_143 & V_147 ;
struct V_5 * V_5 = NULL ;
int V_159 ;
unsigned long V_227 = 0 ;
unsigned long V_226 ;
enum V_236 V_256 = V_243 ;
bool V_238 = false ;
bool V_237 = false ;
if ( V_34 >= V_44 ) {
F_176 ( ! ( V_143 & V_217 ) ) ;
return NULL ;
}
if ( F_215 ( V_199 ) &&
( V_143 & V_257 ) == V_257 )
goto V_258;
V_259:
if ( ! ( V_143 & V_251 ) )
F_250 ( V_34 , V_168 , V_190 , V_131 ) ;
V_159 = F_254 ( V_143 ) ;
if ( ! ( V_159 & V_176 ) && ! V_189 ) {
struct V_180 * V_260 ;
V_260 = F_260 ( V_168 , V_190 ,
NULL , & V_131 ) ;
V_158 = F_261 ( V_260 ) ;
}
V_261:
V_5 = F_213 ( V_143 , V_189 , V_34 , V_168 ,
V_190 , V_159 & ~ V_202 ,
V_131 , V_158 , V_6 ) ;
if ( V_5 )
goto V_262;
if ( V_159 & V_202 ) {
V_168 = F_262 ( F_263 () , V_143 ) ;
V_5 = F_248 ( V_143 , V_34 ,
V_168 , V_190 , V_189 ,
V_131 , V_158 , V_6 ) ;
if ( V_5 ) {
goto V_262;
}
}
if ( ! V_255 ) {
F_176 ( V_143 & V_135 ) ;
goto V_258;
}
if ( V_30 -> V_64 & V_221 )
goto V_258;
if ( F_224 ( V_220 ) && ! ( V_143 & V_135 ) )
goto V_258;
V_5 = F_233 ( V_143 , V_34 , V_168 ,
V_190 , V_189 , V_159 ,
V_131 ,
V_158 , V_6 ,
V_256 , & V_237 ,
& V_238 ,
& V_226 ) ;
if ( V_5 )
goto V_262;
if ( ( V_238 || V_237 ) &&
( V_143 & V_251 ) )
goto V_258;
if ( ( V_143 & V_263 ) != V_263 ||
( V_30 -> V_64 & V_264 ) )
V_256 = V_265 ;
V_5 = F_247 ( V_143 , V_34 ,
V_168 , V_190 ,
V_189 ,
V_159 , V_131 ,
V_158 , V_6 ,
& V_226 ) ;
if ( V_5 )
goto V_262;
if ( ! V_226 ) {
if ( F_264 ( V_143 ) ) {
if ( V_266 )
goto V_258;
if ( ( V_30 -> V_64 & V_267 ) &&
! ( V_143 & V_135 ) )
goto V_258;
V_5 = F_228 ( V_143 , V_34 ,
V_168 , V_190 ,
V_189 , V_131 ,
V_158 , V_6 ) ;
if ( V_5 )
goto V_262;
if ( ! ( V_143 & V_135 ) ) {
if ( V_34 > V_229 )
goto V_258;
if ( V_190 < V_234 )
goto V_258;
}
goto V_259;
}
}
V_227 += V_226 ;
if ( F_227 ( V_143 , V_34 , V_226 ,
V_227 ) ) {
F_249 ( V_131 , V_249 , V_29 / 50 ) ;
goto V_261;
} else {
V_5 = F_233 ( V_143 , V_34 , V_168 ,
V_190 , V_189 , V_159 ,
V_131 ,
V_158 , V_6 ,
V_256 , & V_237 ,
& V_238 ,
& V_226 ) ;
if ( V_5 )
goto V_262;
}
V_258:
F_222 ( V_143 , V_34 , NULL ) ;
return V_5 ;
V_262:
if ( V_268 )
F_265 ( V_5 , V_34 , V_143 ) ;
return V_5 ;
}
struct V_5 *
F_266 ( T_1 V_143 , unsigned int V_34 ,
struct V_168 * V_168 , T_5 * V_189 )
{
enum V_231 V_190 = F_267 ( V_143 ) ;
struct V_12 * V_131 ;
struct V_180 * V_260 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_257 ( V_143 ) ;
unsigned int V_269 ;
int V_159 = V_194 | V_176 | V_200 ;
int V_158 ;
V_143 &= V_3 ;
F_268 ( V_143 ) ;
F_269 ( V_143 & V_147 ) ;
if ( F_184 ( V_143 , V_34 ) )
return NULL ;
if ( F_7 ( ! V_168 -> V_182 -> V_12 ) )
return NULL ;
V_270:
V_269 = F_270 () ;
V_260 = F_260 ( V_168 , V_190 ,
V_189 ? : & V_177 ,
& V_131 ) ;
if ( ! V_131 )
goto V_27;
V_158 = F_261 ( V_260 ) ;
#ifdef F_194
if ( F_257 ( V_143 ) == V_127 )
V_159 |= V_165 ;
#endif
V_5 = F_213 ( V_143 | V_232 , V_189 , V_34 ,
V_168 , V_190 , V_159 ,
V_131 , V_158 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_143 = F_271 ( V_143 ) ;
V_5 = F_259 ( V_143 , V_34 ,
V_168 , V_190 , V_189 ,
V_131 , V_158 , V_6 ) ;
}
F_272 ( V_5 , V_34 , V_143 , V_6 ) ;
V_27:
if ( F_7 ( ! V_5 && F_273 ( V_269 ) ) )
goto V_270;
return V_5 ;
}
unsigned long F_274 ( T_1 V_143 , unsigned int V_34 )
{
struct V_5 * V_5 ;
F_44 ( ( V_143 & V_41 ) != 0 ) ;
V_5 = F_275 ( V_143 , V_34 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_98 ( V_5 ) ;
}
unsigned long F_276 ( T_1 V_143 )
{
return F_274 ( V_143 | V_94 , 0 ) ;
}
void F_111 ( struct V_5 * V_5 , unsigned int V_34 )
{
if ( F_277 ( V_5 ) ) {
if ( V_34 == 0 )
F_160 ( V_5 , false ) ;
else
F_30 ( V_5 , V_34 ) ;
}
}
void V_160 ( unsigned long V_271 , unsigned int V_34 )
{
if ( V_271 != 0 ) {
F_44 ( ! F_278 ( ( void * ) V_271 ) ) ;
F_111 ( F_169 ( ( void * ) V_271 ) , V_34 ) ;
}
}
struct V_5 * F_279 ( T_1 V_143 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_272 * V_273 = NULL ;
if ( ! F_280 ( V_143 , & V_273 , V_34 ) )
return NULL ;
V_5 = F_275 ( V_143 , V_34 ) ;
F_281 ( V_5 , V_273 , V_34 ) ;
return V_5 ;
}
struct V_5 * F_282 ( int V_274 , T_1 V_143 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_272 * V_273 = NULL ;
if ( ! F_280 ( V_143 , & V_273 , V_34 ) )
return NULL ;
V_5 = F_283 ( V_274 , V_143 , V_34 ) ;
F_281 ( V_5 , V_273 , V_34 ) ;
return V_5 ;
}
void F_284 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_285 ( V_5 , V_34 ) ;
F_111 ( V_5 , V_34 ) ;
}
void F_286 ( unsigned long V_271 , unsigned int V_34 )
{
if ( V_271 != 0 ) {
F_44 ( ! F_278 ( ( void * ) V_271 ) ) ;
F_284 ( F_169 ( ( void * ) V_271 ) , V_34 ) ;
}
}
static void * F_287 ( unsigned long V_271 , unsigned V_34 , T_7 V_93 )
{
if ( V_271 ) {
unsigned long V_275 = V_271 + ( V_82 << V_34 ) ;
unsigned long V_276 = V_271 + F_288 ( V_93 ) ;
F_166 ( F_169 ( ( void * ) V_271 ) , V_34 ) ;
while ( V_276 < V_275 ) {
F_289 ( V_276 ) ;
V_276 += V_82 ;
}
}
return ( void * ) V_271 ;
}
void * F_290 ( T_7 V_93 , T_1 V_143 )
{
unsigned int V_34 = F_291 ( V_93 ) ;
unsigned long V_271 ;
V_271 = F_274 ( V_143 , V_34 ) ;
return F_287 ( V_271 , V_34 , V_93 ) ;
}
void * T_8 F_292 ( int V_274 , T_7 V_93 , T_1 V_143 )
{
unsigned V_34 = F_291 ( V_93 ) ;
struct V_5 * V_37 = F_283 ( V_274 , V_143 , V_34 ) ;
if ( ! V_37 )
return NULL ;
return F_287 ( ( unsigned long ) F_98 ( V_37 ) , V_34 , V_93 ) ;
}
void F_293 ( void * V_277 , T_7 V_93 )
{
unsigned long V_271 = ( unsigned long ) V_277 ;
unsigned long V_278 = V_271 + F_288 ( V_93 ) ;
while ( V_271 < V_278 ) {
F_289 ( V_271 ) ;
V_271 += V_82 ;
}
}
static unsigned long F_294 ( int V_279 )
{
struct V_180 * V_156 ;
struct V_12 * V_12 ;
unsigned long V_280 = 0 ;
struct V_168 * V_168 = F_262 ( F_263 () , V_281 ) ;
F_251 (zone, z, zonelist, offset) {
unsigned long V_93 = V_12 -> V_85 ;
unsigned long V_91 = F_211 ( V_12 ) ;
if ( V_93 > V_91 )
V_280 += V_93 - V_91 ;
}
return V_280 ;
}
unsigned long F_295 ( void )
{
return F_294 ( F_267 ( V_282 ) ) ;
}
unsigned long F_296 ( void )
{
return F_294 ( F_267 ( V_283 ) ) ;
}
static inline void F_297 ( struct V_12 * V_12 )
{
if ( F_215 ( V_199 ) )
F_24 ( L_21 , F_15 ( V_12 ) ) ;
}
void F_298 ( struct V_284 * V_285 )
{
V_285 -> V_286 = V_287 ;
V_285 -> V_288 = F_299 ( V_289 ) ;
V_285 -> V_290 = F_299 ( V_80 ) ;
V_285 -> V_291 = F_300 () ;
V_285 -> V_292 = V_293 ;
V_285 -> V_294 = F_301 () ;
V_285 -> V_295 = V_82 ;
}
void F_302 ( struct V_284 * V_285 , int V_274 )
{
int V_231 ;
unsigned long V_85 = 0 ;
T_9 * V_296 = F_303 ( V_274 ) ;
for ( V_231 = 0 ; V_231 < V_297 ; V_231 ++ )
V_85 += V_296 -> V_188 [ V_231 ] . V_85 ;
V_285 -> V_286 = V_85 ;
V_285 -> V_288 = F_304 ( V_274 , V_289 ) ;
V_285 -> V_290 = F_304 ( V_274 , V_80 ) ;
#ifdef F_305
V_285 -> V_292 = V_296 -> V_188 [ V_298 ] . V_85 ;
V_285 -> V_294 = F_80 ( & V_296 -> V_188 [ V_298 ] ,
V_80 ) ;
#else
V_285 -> V_292 = 0 ;
V_285 -> V_294 = 0 ;
#endif
V_285 -> V_295 = V_82 ;
}
bool F_306 ( unsigned int V_64 , int V_274 )
{
bool V_13 = false ;
unsigned int V_269 ;
if ( ! ( V_64 & V_216 ) )
goto V_27;
do {
V_269 = F_270 () ;
V_13 = ! F_201 ( V_274 , V_177 ) ;
} while ( F_273 ( V_269 ) );
V_27:
return V_13 ;
}
static void F_307 ( unsigned char type )
{
static const char V_299 [ V_300 ] = {
[ V_9 ] = 'U' ,
[ V_107 ] = 'E' ,
[ V_127 ] = 'M' ,
[ V_112 ] = 'R' ,
#ifdef F_194
[ V_87 ] = 'C' ,
#endif
#ifdef F_308
[ V_301 ] = 'I' ,
#endif
} ;
char V_302 [ V_300 + 1 ] ;
char * V_37 = V_302 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_300 ; V_35 ++ ) {
if ( type & ( 1 << V_35 ) )
* V_37 ++ = V_299 [ V_35 ] ;
}
* V_37 = '\0' ;
F_24 ( L_22 , V_302 ) ;
}
void F_309 ( unsigned int V_215 )
{
int V_117 ;
struct V_12 * V_12 ;
F_140 (zone) {
if ( F_306 ( V_215 , F_15 ( V_12 ) ) )
continue;
F_297 ( V_12 ) ;
F_24 ( L_23 , V_12 -> V_20 ) ;
F_145 (cpu) {
struct V_118 * V_120 ;
V_120 = F_141 ( V_12 -> V_120 , V_117 ) ;
F_24 ( L_24 ,
V_117 , V_120 -> V_69 . V_91 ,
V_120 -> V_69 . V_116 , V_120 -> V_69 . V_67 ) ;
}
}
F_24 ( L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
F_299 ( V_303 ) ,
F_299 ( V_304 ) ,
F_299 ( V_305 ) ,
F_299 ( V_306 ) ,
F_299 ( V_307 ) ,
F_299 ( V_308 ) ,
F_299 ( V_309 ) ,
F_299 ( V_310 ) ,
F_299 ( V_311 ) ,
F_299 ( V_312 ) ,
F_299 ( V_80 ) ,
F_299 ( V_313 ) ,
F_299 ( V_314 ) ,
F_299 ( V_315 ) ,
F_299 ( V_289 ) ,
F_299 ( V_316 ) ,
F_299 ( V_317 ) ,
F_299 ( V_81 ) ) ;
F_140 (zone) {
int V_35 ;
if ( F_306 ( V_215 , F_15 ( V_12 ) ) )
continue;
F_297 ( V_12 ) ;
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
F_310 ( F_80 ( V_12 , V_80 ) ) ,
F_310 ( F_311 ( V_12 ) ) ,
F_310 ( F_172 ( V_12 ) ) ,
F_310 ( F_211 ( V_12 ) ) ,
F_310 ( F_80 ( V_12 , V_303 ) ) ,
F_310 ( F_80 ( V_12 , V_304 ) ) ,
F_310 ( F_80 ( V_12 , V_306 ) ) ,
F_310 ( F_80 ( V_12 , V_307 ) ) ,
F_310 ( F_80 ( V_12 , V_309 ) ) ,
F_310 ( F_80 ( V_12 , V_305 ) ) ,
F_310 ( F_80 ( V_12 , V_308 ) ) ,
F_310 ( V_12 -> V_318 ) ,
F_310 ( V_12 -> V_85 ) ,
F_310 ( F_80 ( V_12 , V_319 ) ) ,
F_310 ( F_80 ( V_12 , V_310 ) ) ,
F_310 ( F_80 ( V_12 , V_311 ) ) ,
F_310 ( F_80 ( V_12 , V_315 ) ) ,
F_310 ( F_80 ( V_12 , V_289 ) ) ,
F_310 ( F_80 ( V_12 , V_313 ) ) ,
F_310 ( F_80 ( V_12 , V_314 ) ) ,
F_80 ( V_12 , V_320 ) *
V_321 / 1024 ,
F_310 ( F_80 ( V_12 , V_316 ) ) ,
F_310 ( F_80 ( V_12 , V_312 ) ) ,
F_310 ( F_80 ( V_12 , V_317 ) ) ,
F_310 ( F_80 ( V_12 , V_81 ) ) ,
F_310 ( F_80 ( V_12 , V_322 ) ) ,
F_310 ( F_80 ( V_12 , V_74 ) ) ,
( ! F_312 ( V_12 ) ? L_62 : L_63 )
) ;
F_24 ( L_64 ) ;
for ( V_35 = 0 ; V_35 < V_297 ; V_35 ++ )
F_24 ( L_65 , V_12 -> V_166 [ V_35 ] ) ;
F_24 ( L_61 ) ;
}
F_140 (zone) {
unsigned long V_323 [ V_44 ] , V_64 , V_34 , V_324 = 0 ;
unsigned char V_299 [ V_44 ] ;
if ( F_306 ( V_215 , F_15 ( V_12 ) ) )
continue;
F_297 ( V_12 ) ;
F_24 ( L_66 , V_12 -> V_20 ) ;
F_151 ( & V_12 -> V_73 , V_64 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
struct V_56 * V_92 = & V_12 -> V_56 [ V_34 ] ;
int type ;
V_323 [ V_34 ] = V_92 -> V_57 ;
V_324 += V_323 [ V_34 ] << V_34 ;
V_299 [ V_34 ] = 0 ;
for ( type = 0 ; type < V_300 ; type ++ ) {
if ( ! F_82 ( & V_92 -> V_60 [ type ] ) )
V_299 [ V_34 ] |= 1 << type ;
}
}
F_159 ( & V_12 -> V_73 , V_64 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
F_24 ( L_67 , V_323 [ V_34 ] , F_310 ( 1UL ) << V_34 ) ;
if ( V_323 [ V_34 ] )
F_307 ( V_299 [ V_34 ] ) ;
}
F_24 ( L_68 , F_310 ( V_324 ) ) ;
}
F_313 () ;
F_24 ( L_69 , F_299 ( V_325 ) ) ;
F_314 () ;
}
static void F_315 ( struct V_12 * V_12 , struct V_180 * V_180 )
{
V_180 -> V_12 = V_12 ;
V_180 -> F_253 = F_253 ( V_12 ) ;
}
static int F_316 ( T_9 * V_296 , struct V_168 * V_168 ,
int V_326 )
{
struct V_12 * V_12 ;
enum V_231 V_231 = V_297 ;
do {
V_231 -- ;
V_12 = V_296 -> V_188 + V_231 ;
if ( F_317 ( V_12 ) ) {
F_315 ( V_12 ,
& V_168 -> V_182 [ V_326 ++ ] ) ;
F_318 ( V_231 ) ;
}
} while ( V_231 );
return V_326 ;
}
static int F_319 ( char * V_327 )
{
if ( * V_327 == 'd' || * V_327 == 'D' ) {
V_328 = V_329 ;
} else if ( * V_327 == 'n' || * V_327 == 'N' ) {
V_328 = V_330 ;
} else if ( * V_327 == 'z' || * V_327 == 'Z' ) {
V_328 = V_331 ;
} else {
F_24 ( V_332
L_70
L_71 , V_327 ) ;
return - V_333 ;
}
return 0 ;
}
static T_2 int F_320 ( char * V_327 )
{
int V_13 ;
if ( ! V_327 )
return 0 ;
V_13 = F_319 ( V_327 ) ;
if ( V_13 == 0 )
F_321 ( V_334 , V_327 , V_335 ) ;
return V_13 ;
}
int F_322 ( struct V_336 * V_337 , int V_338 ,
void T_10 * V_339 , T_7 * V_340 ,
T_11 * V_341 )
{
char V_342 [ V_335 ] ;
int V_13 ;
static F_323 ( V_343 ) ;
F_324 ( & V_343 ) ;
if ( V_338 ) {
if ( strlen ( ( char * ) V_337 -> V_344 ) >= V_335 ) {
V_13 = - V_333 ;
goto V_27;
}
strcpy ( V_342 , ( char * ) V_337 -> V_344 ) ;
}
V_13 = F_325 ( V_337 , V_338 , V_339 , V_340 , V_341 ) ;
if ( V_13 )
goto V_27;
if ( V_338 ) {
int V_345 = V_328 ;
V_13 = F_319 ( ( char * ) V_337 -> V_344 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_337 -> V_344 , V_342 ,
V_335 ) ;
V_328 = V_345 ;
} else if ( V_345 != V_328 ) {
F_324 ( & V_346 ) ;
F_326 ( NULL , NULL ) ;
F_327 ( & V_346 ) ;
}
}
V_27:
F_327 ( & V_343 ) ;
return V_13 ;
}
static int F_328 ( int V_185 , T_5 * V_347 )
{
int V_181 , V_285 ;
int V_348 = V_349 ;
int V_350 = V_351 ;
const struct V_352 * V_302 = F_329 ( 0 ) ;
if ( ! F_201 ( V_185 , * V_347 ) ) {
F_330 ( V_185 , * V_347 ) ;
return V_185 ;
}
F_331 (n, N_MEMORY) {
if ( F_201 ( V_181 , * V_347 ) )
continue;
V_285 = F_208 ( V_185 , V_181 ) ;
V_285 += ( V_181 < V_185 ) ;
V_302 = F_329 ( V_181 ) ;
if ( ! F_332 ( V_302 ) )
V_285 += V_353 ;
V_285 *= ( V_354 * V_355 ) ;
V_285 += V_356 [ V_181 ] ;
if ( V_285 < V_348 ) {
V_348 = V_285 ;
V_350 = V_181 ;
}
}
if ( V_350 >= 0 )
F_330 ( V_350 , * V_347 ) ;
return V_350 ;
}
static void F_333 ( T_9 * V_296 , int V_185 )
{
int V_357 ;
struct V_168 * V_168 ;
V_168 = & V_296 -> V_358 [ 0 ] ;
for ( V_357 = 0 ; V_168 -> V_182 [ V_357 ] . V_12 != NULL ; V_357 ++ )
;
V_357 = F_316 ( F_303 ( V_185 ) , V_168 , V_357 ) ;
V_168 -> V_182 [ V_357 ] . V_12 = NULL ;
V_168 -> V_182 [ V_357 ] . F_253 = 0 ;
}
static void F_334 ( T_9 * V_296 )
{
int V_357 ;
struct V_168 * V_168 ;
V_168 = & V_296 -> V_358 [ 1 ] ;
V_357 = F_316 ( V_296 , V_168 , 0 ) ;
V_168 -> V_182 [ V_357 ] . V_12 = NULL ;
V_168 -> V_182 [ V_357 ] . F_253 = 0 ;
}
static void F_335 ( T_9 * V_296 , int V_359 )
{
int V_360 , V_357 , V_185 ;
int V_231 ;
struct V_12 * V_156 ;
struct V_168 * V_168 ;
V_168 = & V_296 -> V_358 [ 0 ] ;
V_360 = 0 ;
for ( V_231 = V_297 - 1 ; V_231 >= 0 ; V_231 -- ) {
for ( V_357 = 0 ; V_357 < V_359 ; V_357 ++ ) {
V_185 = V_361 [ V_357 ] ;
V_156 = & F_303 ( V_185 ) -> V_188 [ V_231 ] ;
if ( F_317 ( V_156 ) ) {
F_315 ( V_156 ,
& V_168 -> V_182 [ V_360 ++ ] ) ;
F_318 ( V_231 ) ;
}
}
}
V_168 -> V_182 [ V_360 ] . V_12 = NULL ;
V_168 -> V_182 [ V_360 ] . F_253 = 0 ;
}
static int F_336 ( void )
{
int V_274 , V_231 ;
unsigned long V_362 , V_363 ;
struct V_12 * V_156 ;
int V_364 ;
V_362 = 0 ;
V_363 = 0 ;
F_337 (nid) {
for ( V_231 = 0 ; V_231 < V_297 ; V_231 ++ ) {
V_156 = & F_303 ( V_274 ) -> V_188 [ V_231 ] ;
if ( F_317 ( V_156 ) ) {
if ( V_231 < V_234 )
V_362 += V_156 -> V_85 ;
V_363 += V_156 -> V_85 ;
} else if ( V_231 == V_234 ) {
return V_330 ;
}
}
}
if ( ! V_362 ||
V_362 > V_363 / 2 )
return V_330 ;
V_364 = V_363 /
( F_338 ( V_178 [ V_179 ] ) + 1 ) ;
F_337 (nid) {
V_362 = 0 ;
V_363 = 0 ;
for ( V_231 = 0 ; V_231 < V_297 ; V_231 ++ ) {
V_156 = & F_303 ( V_274 ) -> V_188 [ V_231 ] ;
if ( F_317 ( V_156 ) ) {
if ( V_231 < V_234 )
V_362 += V_156 -> V_318 ;
V_363 += V_156 -> V_318 ;
}
}
if ( V_362 &&
V_363 > V_364 &&
V_362 > V_363 * 70 / 100 )
return V_330 ;
}
return V_331 ;
}
static void F_339 ( void )
{
if ( V_328 == V_329 )
V_365 = F_336 () ;
else
V_365 = V_328 ;
}
static void F_340 ( T_9 * V_296 )
{
int V_357 , V_185 , V_366 ;
enum V_231 V_35 ;
T_5 V_367 ;
int V_368 , V_369 ;
struct V_168 * V_168 ;
int V_34 = V_365 ;
for ( V_35 = 0 ; V_35 < V_370 ; V_35 ++ ) {
V_168 = V_296 -> V_358 + V_35 ;
V_168 -> V_182 [ 0 ] . V_12 = NULL ;
V_168 -> V_182 [ 0 ] . F_253 = 0 ;
}
V_368 = V_296 -> V_371 ;
V_366 = V_205 ;
V_369 = V_368 ;
F_341 ( V_367 ) ;
memset ( V_361 , 0 , sizeof( V_361 ) ) ;
V_357 = 0 ;
while ( ( V_185 = F_328 ( V_368 , & V_367 ) ) >= 0 ) {
if ( F_208 ( V_368 , V_185 ) !=
F_208 ( V_368 , V_369 ) )
V_356 [ V_185 ] = V_366 ;
V_369 = V_185 ;
V_366 -- ;
if ( V_34 == V_330 )
F_333 ( V_296 , V_185 ) ;
else
V_361 [ V_357 ++ ] = V_185 ;
}
if ( V_34 == V_331 ) {
F_335 ( V_296 , V_357 ) ;
}
F_334 ( V_296 ) ;
}
static void F_342 ( T_9 * V_296 )
{
struct V_168 * V_168 ;
struct V_169 * V_170 ;
struct V_180 * V_156 ;
V_168 = & V_296 -> V_358 [ 0 ] ;
V_168 -> V_172 = V_170 = & V_168 -> V_372 ;
F_199 ( V_170 -> V_174 , V_175 ) ;
for ( V_156 = V_168 -> V_182 ; V_156 -> V_12 ; V_156 ++ )
V_170 -> V_183 [ V_156 - V_168 -> V_182 ] = F_343 ( V_156 ) ;
}
int F_344 ( int V_185 )
{
struct V_12 * V_12 ;
( void ) F_260 ( F_262 ( V_185 , V_281 ) ,
F_267 ( V_281 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_185 ;
}
static void F_339 ( void )
{
V_365 = V_331 ;
}
static void F_340 ( T_9 * V_296 )
{
int V_185 , V_368 ;
enum V_231 V_357 ;
struct V_168 * V_168 ;
V_368 = V_296 -> V_371 ;
V_168 = & V_296 -> V_358 [ 0 ] ;
V_357 = F_316 ( V_296 , V_168 , 0 ) ;
for ( V_185 = V_368 + 1 ; V_185 < V_355 ; V_185 ++ ) {
if ( ! F_345 ( V_185 ) )
continue;
V_357 = F_316 ( F_303 ( V_185 ) , V_168 , V_357 ) ;
}
for ( V_185 = 0 ; V_185 < V_368 ; V_185 ++ ) {
if ( ! F_345 ( V_185 ) )
continue;
V_357 = F_316 ( F_303 ( V_185 ) , V_168 , V_357 ) ;
}
V_168 -> V_182 [ V_357 ] . V_12 = NULL ;
V_168 -> V_182 [ V_357 ] . F_253 = 0 ;
}
static void F_342 ( T_9 * V_296 )
{
V_296 -> V_358 [ 0 ] . V_172 = NULL ;
}
static int F_346 ( void * V_344 )
{
int V_274 ;
int V_117 ;
T_9 * V_373 = V_344 ;
#ifdef V_199
memset ( V_356 , 0 , sizeof( V_356 ) ) ;
#endif
if ( V_373 && ! F_345 ( V_373 -> V_371 ) ) {
F_340 ( V_373 ) ;
F_342 ( V_373 ) ;
}
F_337 (nid) {
T_9 * V_296 = F_303 ( V_274 ) ;
F_340 ( V_296 ) ;
F_342 ( V_296 ) ;
}
F_347 (cpu) {
F_348 ( & F_349 ( V_374 , V_117 ) , 0 ) ;
#ifdef F_350
if ( F_351 ( V_117 ) )
F_352 ( V_117 , F_344 ( F_353 ( V_117 ) ) ) ;
#endif
}
return 0 ;
}
void T_12 F_326 ( T_9 * V_296 , struct V_12 * V_12 )
{
F_339 () ;
if ( V_375 == V_376 ) {
F_346 ( NULL ) ;
F_354 () ;
F_355 () ;
} else {
#ifdef F_356
if ( V_12 )
F_357 ( V_12 ) ;
#endif
F_358 ( F_346 , V_296 , NULL ) ;
}
V_377 = F_296 () ;
if ( V_377 < ( V_86 * V_300 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_24 ( L_72
L_73 ,
V_205 ,
V_378 [ V_365 ] ,
V_7 ? L_74 : L_75 ,
V_377 ) ;
#ifdef V_199
F_24 ( L_76 , V_379 [ V_380 ] ) ;
#endif
}
static inline unsigned long F_359 ( unsigned long V_108 )
{
unsigned long V_93 = 1 ;
V_108 /= V_381 ;
while ( V_93 < V_108 )
V_93 <<= 1 ;
V_93 = F_138 ( V_93 , 4096UL ) ;
return F_360 ( V_93 , 4UL ) ;
}
static inline unsigned long F_359 ( unsigned long V_108 )
{
return 4096UL ;
}
static inline unsigned long F_361 ( unsigned long V_93 )
{
return F_362 ( ~ V_93 ) ;
}
static int F_363 ( unsigned long V_17 , unsigned long V_101 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_101 ; V_15 ++ ) {
if ( ! F_17 ( V_15 ) || F_364 ( F_128 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_365 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_101 , V_382 ;
struct V_5 * V_5 ;
unsigned long V_383 ;
int V_384 ;
int V_385 ;
V_17 = V_12 -> V_18 ;
V_101 = F_152 ( V_12 ) ;
V_17 = F_366 ( V_17 , V_86 ) ;
V_384 = F_366 ( F_311 ( V_12 ) , V_86 ) >>
V_88 ;
V_384 = F_138 ( 2 , V_384 ) ;
V_385 = V_12 -> V_386 ;
if ( V_384 == V_385 )
return;
V_12 -> V_386 = V_384 ;
for ( V_15 = V_17 ; V_15 < V_101 ; V_15 += V_86 ) {
if ( ! F_153 ( V_15 ) )
continue;
V_5 = F_128 ( V_15 ) ;
if ( F_125 ( V_5 ) != F_15 ( V_12 ) )
continue;
V_383 = F_171 ( V_5 ) ;
if ( V_384 > 0 ) {
V_382 = F_138 ( V_15 + V_86 , V_101 ) ;
if ( F_363 ( V_15 , V_382 ) )
continue;
if ( V_383 == V_112 ) {
V_384 -- ;
continue;
}
if ( V_383 == V_127 ) {
F_6 ( V_5 ,
V_112 ) ;
F_127 ( V_12 , V_5 ,
V_112 ) ;
V_384 -- ;
continue;
}
} else if ( ! V_385 ) {
break;
}
if ( V_383 == V_112 ) {
F_6 ( V_5 , V_127 ) ;
F_127 ( V_12 , V_5 , V_127 ) ;
}
}
}
void T_8 F_367 ( unsigned long V_93 , int V_274 , unsigned long V_12 ,
unsigned long V_17 , enum V_387 V_388 )
{
struct V_5 * V_5 ;
unsigned long V_101 = V_17 + V_93 ;
unsigned long V_15 ;
struct V_12 * V_156 ;
if ( V_389 < V_101 - 1 )
V_389 = V_101 - 1 ;
V_156 = & F_303 ( V_274 ) -> V_188 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_101 ; V_15 ++ ) {
if ( V_388 == V_390 ) {
if ( ! F_368 ( V_15 ) )
continue;
if ( ! F_369 ( V_15 , V_274 ) )
continue;
}
V_5 = F_128 ( V_15 ) ;
F_370 ( V_5 , V_12 , V_274 , V_15 ) ;
F_371 ( V_5 , V_12 , V_274 , V_15 ) ;
F_372 ( V_5 ) ;
F_22 ( V_5 ) ;
F_77 ( V_5 ) ;
F_373 ( V_5 ) ;
if ( ( V_156 -> V_18 <= V_15 )
&& ( V_15 < F_152 ( V_156 ) )
&& ! ( V_15 & ( V_86 - 1 ) ) )
F_6 ( V_5 , V_127 ) ;
F_117 ( & V_5 -> V_55 ) ;
#ifdef F_374
if ( ! F_375 ( V_12 ) )
F_376 ( V_5 , F_377 ( V_15 << V_391 ) ) ;
#endif
}
}
static void T_8 F_378 ( struct V_12 * V_12 )
{
unsigned int V_34 , V_125 ;
F_156 (order, t) {
F_117 ( & V_12 -> V_56 [ V_34 ] . V_60 [ V_125 ] ) ;
V_12 -> V_56 [ V_34 ] . V_57 = 0 ;
}
}
static int F_379 ( struct V_12 * V_12 )
{
#ifdef F_380
int V_116 ;
V_116 = V_12 -> V_85 / 1024 ;
if ( V_116 * V_82 > 512 * 1024 )
V_116 = ( 512 * 1024 ) / V_82 ;
V_116 /= 4 ;
if ( V_116 < 1 )
V_116 = 1 ;
V_116 = F_381 ( V_116 + V_116 / 2 ) - 1 ;
return V_116 ;
#else
return 0 ;
#endif
}
static void F_382 ( struct V_68 * V_69 , unsigned long V_91 ,
unsigned long V_116 )
{
V_69 -> V_116 = 1 ;
F_37 () ;
V_69 -> V_91 = V_91 ;
F_37 () ;
V_69 -> V_116 = V_116 ;
}
static void F_383 ( struct V_118 * V_37 , unsigned long V_116 )
{
F_382 ( & V_37 -> V_69 , 6 * V_116 , F_360 ( 1UL , 1 * V_116 ) ) ;
}
static void F_384 ( struct V_118 * V_37 )
{
struct V_68 * V_69 ;
int V_6 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_69 = & V_37 -> V_69 ;
V_69 -> V_67 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_117 ( & V_69 -> V_77 [ V_6 ] ) ;
}
static void F_348 ( struct V_118 * V_37 , unsigned long V_116 )
{
F_384 ( V_37 ) ;
F_383 ( V_37 , V_116 ) ;
}
static void F_385 ( struct V_118 * V_37 ,
unsigned long V_91 )
{
unsigned long V_116 = F_360 ( 1UL , V_91 / 4 ) ;
if ( ( V_91 / 4 ) > ( V_391 * 8 ) )
V_116 = V_391 * 8 ;
F_382 ( & V_37 -> V_69 , V_91 , V_116 ) ;
}
static void F_386 ( struct V_12 * V_12 ,
struct V_118 * V_69 )
{
if ( V_392 )
F_385 ( V_69 ,
( V_12 -> V_85 /
V_392 ) ) ;
else
F_383 ( V_69 , F_379 ( V_12 ) ) ;
}
static void T_8 F_387 ( struct V_12 * V_12 , int V_117 )
{
struct V_118 * V_69 = F_141 ( V_12 -> V_120 , V_117 ) ;
F_384 ( V_69 ) ;
F_386 ( V_12 , V_69 ) ;
}
static void T_8 F_357 ( struct V_12 * V_12 )
{
int V_117 ;
V_12 -> V_120 = F_388 ( struct V_118 ) ;
F_347 (cpu)
F_387 ( V_12 , V_117 ) ;
}
void T_2 F_389 ( void )
{
struct V_12 * V_12 ;
F_140 (zone)
F_357 ( V_12 ) ;
}
static T_13 T_14
int F_390 ( struct V_12 * V_12 , unsigned long V_393 )
{
int V_35 ;
T_7 V_394 ;
V_12 -> F_359 =
F_359 ( V_393 ) ;
V_12 -> F_361 =
F_361 ( V_12 -> F_359 ) ;
V_394 = V_12 -> F_359
* sizeof( V_395 ) ;
if ( ! F_391 () ) {
V_12 -> V_396 = ( V_395 * )
F_392 (
V_394 , V_12 -> V_187 -> V_371 ) ;
} else {
V_12 -> V_396 = F_393 ( V_394 ) ;
}
if ( ! V_12 -> V_396 )
return - V_155 ;
for ( V_35 = 0 ; V_35 < V_12 -> F_359 ; ++ V_35 )
F_394 ( V_12 -> V_396 + V_35 ) ;
return 0 ;
}
static T_8 void F_395 ( struct V_12 * V_12 )
{
V_12 -> V_120 = & V_374 ;
if ( F_317 ( V_12 ) )
F_24 ( V_397 L_77 ,
V_12 -> V_20 , V_12 -> V_318 ,
F_379 ( V_12 ) ) ;
}
int T_8 F_396 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_93 ,
enum V_387 V_388 )
{
struct V_398 * V_296 = V_12 -> V_187 ;
int V_13 ;
V_13 = F_390 ( V_12 , V_93 ) ;
if ( V_13 )
return V_13 ;
V_296 -> V_326 = F_253 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_397 ( V_399 , L_78 ,
L_79 ,
V_296 -> V_371 ,
( unsigned long ) F_253 ( V_12 ) ,
V_18 , ( V_18 + V_93 ) ) ;
F_378 ( V_12 ) ;
return 0 ;
}
int T_8 F_398 ( unsigned long V_15 )
{
unsigned long V_17 , V_101 ;
int V_274 ;
static unsigned long T_15 V_400 , V_401 ;
static int T_15 V_402 ;
if ( V_400 <= V_15 && V_15 < V_401 )
return V_402 ;
V_274 = F_399 ( V_15 , & V_17 , & V_101 ) ;
if ( V_274 != - 1 ) {
V_400 = V_17 ;
V_401 = V_101 ;
V_402 = V_274 ;
}
return V_274 ;
}
int T_8 F_400 ( unsigned long V_15 )
{
int V_274 ;
V_274 = F_398 ( V_15 ) ;
if ( V_274 >= 0 )
return V_274 ;
return 0 ;
}
bool T_8 F_369 ( unsigned long V_15 , int V_185 )
{
int V_274 ;
V_274 = F_398 ( V_15 ) ;
if ( V_274 >= 0 && V_274 != V_185 )
return false ;
return true ;
}
void T_2 F_401 ( int V_274 , unsigned long V_403 )
{
unsigned long V_17 , V_101 ;
int V_35 , V_404 ;
F_402 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = F_138 ( V_17 , V_403 ) ;
V_101 = F_138 ( V_101 , V_403 ) ;
if ( V_17 < V_101 )
F_403 ( F_404 ( V_17 ) ,
( V_101 - V_17 ) << V_391 ,
V_404 ) ;
}
}
void T_2 F_405 ( int V_274 )
{
unsigned long V_17 , V_101 ;
int V_35 , V_404 ;
F_402 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_406 ( V_404 , V_17 , V_101 ) ;
}
void T_8 F_407 ( unsigned int V_274 ,
unsigned long * V_17 , unsigned long * V_101 )
{
unsigned long V_405 , V_406 ;
int V_35 ;
* V_17 = - 1UL ;
* V_101 = 0 ;
F_402 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = F_138 ( * V_17 , V_405 ) ;
* V_101 = F_360 ( * V_101 , V_406 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_408 ( void )
{
int V_407 ;
for ( V_407 = V_297 - 1 ; V_407 >= 0 ; V_407 -- ) {
if ( V_407 == V_408 )
continue;
if ( V_409 [ V_407 ] >
V_410 [ V_407 ] )
break;
}
F_44 ( V_407 == - 1 ) ;
V_411 = V_407 ;
}
static void T_8 F_409 ( int V_274 ,
unsigned long V_231 ,
unsigned long V_412 ,
unsigned long V_413 ,
unsigned long * V_18 ,
unsigned long * F_152 )
{
if ( V_414 [ V_274 ] ) {
if ( V_231 == V_408 ) {
* V_18 = V_414 [ V_274 ] ;
* F_152 = F_138 ( V_413 ,
V_409 [ V_411 ] ) ;
} else if ( * V_18 < V_414 [ V_274 ] &&
* F_152 > V_414 [ V_274 ] ) {
* F_152 = V_414 [ V_274 ] ;
} else if ( * V_18 >= V_414 [ V_274 ] )
* V_18 = * F_152 ;
}
}
static unsigned long T_8 F_410 ( int V_274 ,
unsigned long V_231 ,
unsigned long V_412 ,
unsigned long V_413 ,
unsigned long * V_415 )
{
unsigned long V_18 , F_152 ;
V_18 = V_410 [ V_231 ] ;
F_152 = V_409 [ V_231 ] ;
F_409 ( V_274 , V_231 ,
V_412 , V_413 ,
& V_18 , & F_152 ) ;
if ( F_152 < V_412 || V_18 > V_413 )
return 0 ;
F_152 = F_138 ( F_152 , V_413 ) ;
V_18 = F_360 ( V_18 , V_412 ) ;
return F_152 - V_18 ;
}
unsigned long T_8 F_411 ( int V_274 ,
unsigned long V_416 ,
unsigned long V_417 )
{
unsigned long V_418 = V_417 - V_416 ;
unsigned long V_17 , V_101 ;
int V_35 ;
F_402 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_412 ( V_17 , V_416 , V_417 ) ;
V_101 = F_412 ( V_101 , V_416 , V_417 ) ;
V_418 -= V_101 - V_17 ;
}
return V_418 ;
}
unsigned long T_2 F_413 ( unsigned long V_17 ,
unsigned long V_101 )
{
return F_411 ( V_355 , V_17 , V_101 ) ;
}
static unsigned long T_8 F_414 ( int V_274 ,
unsigned long V_231 ,
unsigned long V_412 ,
unsigned long V_413 ,
unsigned long * V_415 )
{
unsigned long V_419 = V_410 [ V_231 ] ;
unsigned long V_420 = V_409 [ V_231 ] ;
unsigned long V_18 , F_152 ;
V_18 = F_412 ( V_412 , V_419 , V_420 ) ;
F_152 = F_412 ( V_413 , V_419 , V_420 ) ;
F_409 ( V_274 , V_231 ,
V_412 , V_413 ,
& V_18 , & F_152 ) ;
return F_411 ( V_274 , V_18 , F_152 ) ;
}
static inline unsigned long T_8 F_410 ( int V_274 ,
unsigned long V_231 ,
unsigned long V_412 ,
unsigned long V_413 ,
unsigned long * V_421 )
{
return V_421 [ V_231 ] ;
}
static inline unsigned long T_8 F_414 ( int V_274 ,
unsigned long V_231 ,
unsigned long V_412 ,
unsigned long V_413 ,
unsigned long * V_422 )
{
if ( ! V_422 )
return 0 ;
return V_422 [ V_231 ] ;
}
static void T_8 F_415 ( struct V_398 * V_296 ,
unsigned long V_412 ,
unsigned long V_413 ,
unsigned long * V_421 ,
unsigned long * V_422 )
{
unsigned long V_423 , V_424 = 0 ;
enum V_231 V_35 ;
for ( V_35 = 0 ; V_35 < V_297 ; V_35 ++ )
V_424 += F_410 ( V_296 -> V_371 , V_35 ,
V_412 ,
V_413 ,
V_421 ) ;
V_296 -> V_425 = V_424 ;
V_423 = V_424 ;
for ( V_35 = 0 ; V_35 < V_297 ; V_35 ++ )
V_423 -=
F_414 ( V_296 -> V_371 , V_35 ,
V_412 , V_413 ,
V_422 ) ;
V_296 -> V_426 = V_423 ;
F_24 ( V_397 L_80 , V_296 -> V_371 ,
V_423 ) ;
}
static unsigned long T_2 F_416 ( unsigned long V_18 , unsigned long V_427 )
{
unsigned long V_428 ;
V_427 += V_18 & ( V_86 - 1 ) ;
V_428 = F_366 ( V_427 , V_86 ) ;
V_428 = V_428 >> V_88 ;
V_428 *= V_429 ;
V_428 = F_366 ( V_428 , 8 * sizeof( unsigned long ) ) ;
return V_428 / 8 ;
}
static void T_2 F_417 ( struct V_398 * V_296 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_427 )
{
unsigned long V_428 = F_416 ( V_18 , V_427 ) ;
V_12 -> V_430 = NULL ;
if ( V_428 )
V_12 -> V_430 =
F_392 ( V_428 ,
V_296 -> V_371 ) ;
}
static inline void F_417 ( struct V_398 * V_296 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_427 ) {}
void T_16 F_418 ( void )
{
unsigned int V_34 ;
if ( V_88 )
return;
if ( V_431 > V_391 )
V_34 = V_432 ;
else
V_34 = V_44 - 1 ;
V_88 = V_34 ;
}
void T_16 F_418 ( void )
{
}
static unsigned long T_16 F_419 ( unsigned long V_19 ,
unsigned long V_318 )
{
unsigned long V_108 = V_19 ;
if ( V_19 > V_318 + ( V_318 >> 4 ) &&
F_215 ( V_433 ) )
V_108 = V_318 ;
return F_288 ( V_108 * sizeof( struct V_5 ) ) >> V_391 ;
}
static void T_16 F_420 ( struct V_398 * V_296 ,
unsigned long V_412 , unsigned long V_413 ,
unsigned long * V_421 , unsigned long * V_422 )
{
enum V_231 V_357 ;
int V_274 = V_296 -> V_371 ;
unsigned long V_18 = V_296 -> V_412 ;
int V_13 ;
F_421 ( V_296 ) ;
#ifdef F_422
F_423 ( & V_296 -> V_434 ) ;
V_296 -> V_435 = 0 ;
V_296 -> V_436 = V_26 ;
#endif
F_394 ( & V_296 -> V_437 ) ;
F_394 ( & V_296 -> V_438 ) ;
F_424 ( V_296 ) ;
for ( V_357 = 0 ; V_357 < V_297 ; V_357 ++ ) {
struct V_12 * V_12 = V_296 -> V_188 + V_357 ;
unsigned long V_93 , V_439 , V_440 , V_441 ;
V_93 = F_410 ( V_274 , V_357 , V_412 ,
V_413 , V_421 ) ;
V_439 = V_440 = V_93 - F_414 ( V_274 , V_357 ,
V_412 ,
V_413 ,
V_422 ) ;
V_441 = F_419 ( V_93 , V_439 ) ;
if ( V_440 >= V_441 ) {
V_440 -= V_441 ;
if ( V_441 )
F_24 ( V_397
L_81 ,
V_379 [ V_357 ] , V_441 ) ;
} else
F_24 ( V_332
L_82 ,
V_379 [ V_357 ] , V_441 , V_440 ) ;
if ( V_357 == 0 && V_440 > V_442 ) {
V_440 -= V_442 ;
F_24 ( V_397 L_83 ,
V_379 [ 0 ] , V_442 ) ;
}
if ( ! F_375 ( V_357 ) )
V_443 += V_440 ;
else if ( V_443 > V_441 * 2 )
V_443 -= V_441 ;
V_444 += V_440 ;
V_12 -> V_19 = V_93 ;
V_12 -> V_318 = V_439 ;
V_12 -> V_85 = F_375 ( V_357 ) ? V_439 : V_440 ;
#ifdef V_199
V_12 -> V_185 = V_274 ;
V_12 -> V_445 = ( V_440 * V_446 )
/ 100 ;
V_12 -> V_447 = ( V_440 * V_448 ) / 100 ;
#endif
V_12 -> V_20 = V_379 [ V_357 ] ;
F_423 ( & V_12 -> V_73 ) ;
F_423 ( & V_12 -> V_449 ) ;
F_425 ( V_12 ) ;
V_12 -> V_187 = V_296 ;
F_395 ( V_12 ) ;
F_210 ( V_12 , V_136 , V_12 -> V_85 ) ;
F_426 ( & V_12 -> V_450 ) ;
if ( ! V_93 )
continue;
F_418 () ;
F_417 ( V_296 , V_12 , V_18 , V_93 ) ;
V_13 = F_396 ( V_12 , V_18 ,
V_93 , V_390 ) ;
F_124 ( V_13 ) ;
F_427 ( V_93 , V_274 , V_357 , V_18 ) ;
V_18 += V_93 ;
}
}
static void T_14 F_428 ( struct V_398 * V_296 )
{
if ( ! V_296 -> V_425 )
return;
#ifdef F_429
if ( ! V_296 -> V_451 ) {
unsigned long V_93 , V_452 , V_278 ;
struct V_5 * V_453 ;
V_452 = V_296 -> V_412 & ~ ( V_89 - 1 ) ;
V_278 = F_430 ( V_296 ) ;
V_278 = F_431 ( V_278 , V_89 ) ;
V_93 = ( V_278 - V_452 ) * sizeof( struct V_5 ) ;
V_453 = F_432 ( V_296 -> V_371 , V_93 ) ;
if ( ! V_453 )
V_453 = F_392 ( V_93 ,
V_296 -> V_371 ) ;
V_296 -> V_451 = V_453 + ( V_296 -> V_412 - V_452 ) ;
}
#ifndef F_433
if ( V_296 == F_303 ( 0 ) ) {
V_454 = F_303 ( 0 ) -> V_451 ;
#ifdef F_434
if ( F_10 ( V_454 ) != V_296 -> V_412 )
V_454 -= ( V_296 -> V_412 - V_455 ) ;
#endif
}
#endif
#endif
}
void T_16 F_435 ( int V_274 , unsigned long * V_421 ,
unsigned long V_412 , unsigned long * V_422 )
{
T_9 * V_296 = F_303 ( V_274 ) ;
unsigned long V_17 = 0 ;
unsigned long V_101 = 0 ;
F_2 ( V_296 -> V_326 || V_296 -> V_158 ) ;
V_296 -> V_371 = V_274 ;
V_296 -> V_412 = V_412 ;
#ifdef F_434
F_407 ( V_274 , & V_17 , & V_101 ) ;
#endif
F_415 ( V_296 , V_17 , V_101 ,
V_421 , V_422 ) ;
F_428 ( V_296 ) ;
#ifdef F_429
F_24 ( V_397 L_84 ,
V_274 , ( unsigned long ) V_296 ,
( unsigned long ) V_296 -> V_451 ) ;
#endif
F_420 ( V_296 , V_17 , V_101 ,
V_421 , V_422 ) ;
}
void T_2 F_436 ( void )
{
unsigned int V_185 ;
unsigned int V_456 = 0 ;
F_437 (node, node_possible_map)
V_456 = V_185 ;
V_457 = V_456 + 1 ;
}
unsigned long T_2 F_438 ( void )
{
unsigned long V_458 = 0 , V_459 = 0 ;
unsigned long V_452 , V_278 , V_460 ;
int V_402 = - 1 ;
int V_35 , V_274 ;
F_402 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_452 || V_402 < 0 || V_402 == V_274 ) {
V_402 = V_274 ;
V_459 = V_278 ;
continue;
}
V_460 = ~ ( ( 1 << F_439 ( V_452 ) ) - 1 ) ;
while ( V_460 && V_459 <= ( V_452 & ( V_460 << 1 ) ) )
V_460 <<= 1 ;
V_458 |= V_460 ;
}
return ~ V_458 + 1 ;
}
static unsigned long T_2 F_440 ( int V_274 )
{
unsigned long V_461 = V_462 ;
unsigned long V_17 ;
int V_35 ;
F_402 (i, nid, &start_pfn, NULL, NULL)
V_461 = F_138 ( V_461 , V_17 ) ;
if ( V_461 == V_462 ) {
F_24 ( V_332
L_85 , V_274 ) ;
return 0 ;
}
return V_461 ;
}
unsigned long T_2 F_441 ( void )
{
return F_440 ( V_355 ) ;
}
static unsigned long T_2 F_442 ( void )
{
unsigned long V_424 = 0 ;
unsigned long V_17 , V_101 ;
int V_35 , V_274 ;
F_402 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_108 = V_101 - V_17 ;
V_424 += V_108 ;
if ( V_108 )
F_443 ( V_274 , V_179 ) ;
}
return V_424 ;
}
static void T_2 F_444 ( void )
{
int V_35 , V_274 ;
unsigned long V_463 ;
unsigned long V_464 , V_465 ;
T_5 V_466 = V_178 [ V_179 ] ;
unsigned long V_424 = F_442 () ;
int V_467 = F_338 ( V_178 [ V_179 ] ) ;
struct V_468 * V_469 ;
F_408 () ;
if ( F_445 () ) {
F_446 (memory, r) {
if ( ! F_447 ( V_469 ) )
continue;
V_274 = V_469 -> V_274 ;
V_463 = F_448 ( V_469 -> V_470 ) ;
V_414 [ V_274 ] = V_414 [ V_274 ] ?
F_138 ( V_463 , V_414 [ V_274 ] ) :
V_463 ;
}
goto V_471;
}
if ( V_472 ) {
unsigned long V_473 ;
V_472 =
F_366 ( V_472 , V_89 ) ;
V_473 = V_424 - V_472 ;
V_474 = F_360 ( V_474 , V_473 ) ;
}
if ( ! V_474 )
goto V_27;
V_463 = V_410 [ V_411 ] ;
V_259:
V_464 = V_474 / V_467 ;
F_331 (nid, N_MEMORY) {
unsigned long V_17 , V_101 ;
if ( V_474 < V_464 )
V_464 = V_474 / V_467 ;
V_465 = V_464 ;
F_402 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_475 ;
V_17 = F_360 ( V_17 , V_414 [ V_274 ] ) ;
if ( V_17 >= V_101 )
continue;
if ( V_17 < V_463 ) {
unsigned long V_476 ;
V_476 = F_138 ( V_101 , V_463 )
- V_17 ;
V_465 -= F_138 ( V_476 ,
V_465 ) ;
V_474 -= F_138 ( V_476 ,
V_474 ) ;
if ( V_101 <= V_463 ) {
V_414 [ V_274 ] = V_101 ;
continue;
}
V_17 = V_463 ;
}
V_475 = V_101 - V_17 ;
if ( V_475 > V_465 )
V_475 = V_465 ;
V_414 [ V_274 ] = V_17 + V_475 ;
V_474 -= F_138 ( V_474 ,
V_475 ) ;
V_465 -= V_475 ;
if ( ! V_465 )
break;
}
}
V_467 -- ;
if ( V_467 && V_474 > V_467 )
goto V_259;
V_471:
for ( V_274 = 0 ; V_274 < V_355 ; V_274 ++ )
V_414 [ V_274 ] =
F_366 ( V_414 [ V_274 ] , V_89 ) ;
V_27:
V_178 [ V_179 ] = V_466 ;
}
static void F_449 ( T_9 * V_296 , int V_274 )
{
enum V_231 V_231 ;
if ( V_179 == V_477 )
return;
for ( V_231 = 0 ; V_231 <= V_408 - 1 ; V_231 ++ ) {
struct V_12 * V_12 = & V_296 -> V_188 [ V_231 ] ;
if ( F_317 ( V_12 ) ) {
F_443 ( V_274 , V_478 ) ;
if ( V_477 != V_478 &&
V_231 <= V_234 )
F_443 ( V_274 , V_477 ) ;
break;
}
}
}
void T_2 F_450 ( unsigned long * V_124 )
{
unsigned long V_17 , V_101 ;
int V_35 , V_274 ;
memset ( V_410 , 0 ,
sizeof( V_410 ) ) ;
memset ( V_409 , 0 ,
sizeof( V_409 ) ) ;
V_410 [ 0 ] = F_441 () ;
V_409 [ 0 ] = V_124 [ 0 ] ;
for ( V_35 = 1 ; V_35 < V_297 ; V_35 ++ ) {
if ( V_35 == V_408 )
continue;
V_410 [ V_35 ] =
V_409 [ V_35 - 1 ] ;
V_409 [ V_35 ] =
F_360 ( V_124 [ V_35 ] , V_410 [ V_35 ] ) ;
}
V_410 [ V_408 ] = 0 ;
V_409 [ V_408 ] = 0 ;
memset ( V_414 , 0 , sizeof( V_414 ) ) ;
F_444 () ;
F_24 ( L_86 ) ;
for ( V_35 = 0 ; V_35 < V_297 ; V_35 ++ ) {
if ( V_35 == V_408 )
continue;
F_24 ( V_479 L_87 , V_379 [ V_35 ] ) ;
if ( V_410 [ V_35 ] ==
V_409 [ V_35 ] )
F_24 ( V_479 L_88 ) ;
else
F_24 ( V_479 L_89 ,
V_410 [ V_35 ] << V_391 ,
( V_409 [ V_35 ]
<< V_391 ) - 1 ) ;
}
F_24 ( L_90 ) ;
for ( V_35 = 0 ; V_35 < V_355 ; V_35 ++ ) {
if ( V_414 [ V_35 ] )
F_24 ( L_91 , V_35 ,
V_414 [ V_35 ] << V_391 ) ;
}
F_24 ( L_92 ) ;
F_402 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_24 ( L_93 , V_274 ,
V_17 << V_391 , ( V_101 << V_391 ) - 1 ) ;
F_451 () ;
F_436 () ;
F_337 (nid) {
T_9 * V_296 = F_303 ( V_274 ) ;
F_435 ( V_274 , NULL ,
F_440 ( V_274 ) , NULL ) ;
if ( V_296 -> V_426 )
F_443 ( V_274 , V_179 ) ;
F_449 ( V_296 , V_274 ) ;
}
}
static int T_2 F_452 ( char * V_37 , unsigned long * V_480 )
{
unsigned long long V_481 ;
if ( ! V_37 )
return - V_333 ;
V_481 = F_453 ( V_37 , & V_37 ) ;
* V_480 = V_481 >> V_391 ;
F_2 ( ( V_481 >> V_391 ) > V_462 ) ;
return 0 ;
}
static int T_2 F_454 ( char * V_37 )
{
return F_452 ( V_37 , & V_474 ) ;
}
static int T_2 F_455 ( char * V_37 )
{
return F_452 ( V_37 , & V_472 ) ;
}
void F_113 ( struct V_5 * V_5 , long V_67 )
{
F_79 ( & V_482 ) ;
F_18 ( V_5 ) -> V_85 += V_67 ;
V_287 += V_67 ;
#ifdef F_305
if ( F_96 ( V_5 ) )
V_293 += V_67 ;
#endif
F_89 ( & V_482 ) ;
}
unsigned long F_456 ( void * V_452 , void * V_278 , int V_483 , char * V_327 )
{
void * V_360 ;
unsigned long V_108 = 0 ;
V_452 = ( void * ) F_288 ( ( unsigned long ) V_452 ) ;
V_278 = ( void * ) ( ( unsigned long ) V_278 & V_484 ) ;
for ( V_360 = V_452 ; V_360 < V_278 ; V_360 += V_82 , V_108 ++ ) {
if ( ( unsigned int ) V_483 <= 0xFF )
memset ( V_360 , V_483 , V_82 ) ;
F_457 ( F_169 ( V_360 ) ) ;
}
if ( V_108 && V_327 )
F_458 ( L_94 ,
V_327 , V_108 << ( V_391 - 10 ) , V_452 , V_278 ) ;
return V_108 ;
}
void F_459 ( struct V_5 * V_5 )
{
F_460 ( V_5 ) ;
V_287 ++ ;
F_18 ( V_5 ) -> V_85 ++ ;
V_293 ++ ;
}
void T_2 F_461 ( const char * V_140 )
{
unsigned long V_485 , V_486 , V_487 , V_488 , V_489 ;
unsigned long V_490 , V_491 ;
V_485 = F_462 () ;
V_486 = V_492 - V_493 ;
V_487 = V_494 - V_495 ;
V_488 = V_496 - V_497 ;
V_489 = V_498 - V_499 ;
V_491 = V_500 - V_501 ;
V_490 = V_502 - V_503 ;
#define F_463 ( V_452 , V_278 , V_93 , V_360 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_463 ( V_501 , V_500 , V_491 ,
V_503 , V_490 ) ;
F_463 ( V_493 , V_492 , V_486 , V_503 , V_490 ) ;
F_463 ( V_495 , V_494 , V_487 , V_501 , V_491 ) ;
F_463 ( V_493 , V_492 , V_486 , V_497 , V_488 ) ;
F_463 ( V_495 , V_494 , V_487 , V_497 , V_488 ) ;
#undef F_463
F_24 ( L_95
L_96
L_97
#ifdef F_305
L_98
#endif
L_99 ,
F_464 () << ( V_391 - 10 ) , V_485 << ( V_391 - 10 ) ,
V_486 >> 10 , V_487 >> 10 , V_488 >> 10 ,
( V_491 + V_490 ) >> 10 , V_489 >> 10 ,
( V_485 - V_287 ) << ( V_391 - 10 ) ,
#ifdef F_305
V_293 << ( V_391 - 10 ) ,
#endif
V_140 ? L_100 : L_101 , V_140 ? V_140 : L_101 ) ;
}
void T_2 F_465 ( unsigned long V_504 )
{
V_442 = V_504 ;
}
void T_2 F_466 ( unsigned long * V_421 )
{
F_435 ( 0 , V_421 ,
F_467 ( V_505 ) >> V_391 , NULL ) ;
}
static int F_468 ( struct V_506 * V_373 ,
unsigned long V_507 , void * V_508 )
{
int V_117 = ( unsigned long ) V_508 ;
if ( V_507 == V_509 || V_507 == V_510 ) {
F_469 ( V_117 ) ;
F_139 ( V_117 ) ;
F_470 ( V_117 ) ;
F_471 ( V_117 ) ;
}
return V_511 ;
}
void T_2 F_472 ( void )
{
F_473 ( F_468 , 0 ) ;
}
static void F_474 ( void )
{
struct V_398 * V_296 ;
unsigned long V_512 = 0 ;
enum V_231 V_35 , V_357 ;
F_475 (pgdat) {
for ( V_35 = 0 ; V_35 < V_297 ; V_35 ++ ) {
struct V_12 * V_12 = V_296 -> V_188 + V_35 ;
long F_360 = 0 ;
for ( V_357 = V_35 ; V_357 < V_297 ; V_357 ++ ) {
if ( V_12 -> V_166 [ V_357 ] > F_360 )
F_360 = V_12 -> V_166 [ V_357 ] ;
}
F_360 += F_211 ( V_12 ) ;
if ( F_360 > V_12 -> V_85 )
F_360 = V_12 -> V_85 ;
V_512 += F_360 ;
V_12 -> V_513 = F_360 ;
}
}
V_513 = V_512 ;
V_514 = V_512 ;
}
static void F_476 ( void )
{
struct V_398 * V_296 ;
enum V_231 V_357 , V_515 ;
F_475 (pgdat) {
for ( V_357 = 0 ; V_357 < V_297 ; V_357 ++ ) {
struct V_12 * V_12 = V_296 -> V_188 + V_357 ;
unsigned long V_85 = V_12 -> V_85 ;
V_12 -> V_166 [ V_357 ] = 0 ;
V_515 = V_357 ;
while ( V_515 ) {
struct V_12 * V_516 ;
V_515 -- ;
if ( V_517 [ V_515 ] < 1 )
V_517 [ V_515 ] = 1 ;
V_516 = V_296 -> V_188 + V_515 ;
V_516 -> V_166 [ V_357 ] = V_85 /
V_517 [ V_515 ] ;
V_85 += V_516 -> V_85 ;
}
}
}
F_474 () ;
}
static void F_477 ( void )
{
unsigned long V_518 = V_519 >> ( V_391 - 10 ) ;
unsigned long V_520 = 0 ;
struct V_12 * V_12 ;
unsigned long V_64 ;
F_478 (zone) {
if ( ! F_479 ( V_12 ) )
V_520 += V_12 -> V_85 ;
}
F_478 (zone) {
T_18 V_302 ;
F_151 ( & V_12 -> V_73 , V_64 ) ;
V_302 = ( T_18 ) V_518 * V_12 -> V_85 ;
F_480 ( V_302 , V_520 ) ;
if ( F_479 ( V_12 ) ) {
unsigned long V_521 ;
V_521 = V_12 -> V_85 / 1024 ;
V_521 = F_412 ( V_521 , V_522 , 128UL ) ;
V_12 -> V_129 [ V_523 ] = V_521 ;
} else {
V_12 -> V_129 [ V_523 ] = V_302 ;
}
V_12 -> V_129 [ V_524 ] = F_311 ( V_12 ) + ( V_302 >> 2 ) ;
V_12 -> V_129 [ V_525 ] = F_311 ( V_12 ) + ( V_302 >> 1 ) ;
F_81 ( V_12 , V_136 ,
F_211 ( V_12 ) - F_172 ( V_12 ) -
F_177 ( & V_12 -> V_137 [ V_136 ] ) ) ;
F_365 ( V_12 ) ;
F_159 ( & V_12 -> V_73 , V_64 ) ;
}
F_474 () ;
}
void F_481 ( void )
{
F_324 ( & V_346 ) ;
F_477 () ;
F_327 ( & V_346 ) ;
}
static void T_8 F_482 ( struct V_12 * V_12 )
{
unsigned int V_526 , V_527 ;
V_526 = V_12 -> V_85 >> ( 30 - V_391 ) ;
if ( V_526 )
V_527 = F_483 ( 10 * V_526 ) ;
else
V_527 = 1 ;
V_12 -> V_528 = V_527 ;
}
static void T_8 F_484 ( void )
{
struct V_12 * V_12 ;
F_478 (zone)
F_482 ( V_12 ) ;
}
int T_8 F_485 ( void )
{
unsigned long V_529 ;
int V_530 ;
V_529 = F_295 () * ( V_82 >> 10 ) ;
V_530 = F_483 ( V_529 * 16 ) ;
if ( V_530 > V_531 ) {
V_519 = V_530 ;
if ( V_519 < 128 )
V_519 = 128 ;
if ( V_519 > 65536 )
V_519 = 65536 ;
} else {
F_225 ( L_102 ,
V_530 , V_531 ) ;
}
F_481 () ;
F_486 () ;
F_476 () ;
F_484 () ;
return 0 ;
}
int F_487 ( struct V_336 * V_337 , int V_338 ,
void T_10 * V_339 , T_7 * V_340 , T_11 * V_341 )
{
int V_532 ;
V_532 = F_488 ( V_337 , V_338 , V_339 , V_340 , V_341 ) ;
if ( V_532 )
return V_532 ;
if ( V_338 ) {
V_531 = V_519 ;
F_481 () ;
}
return 0 ;
}
int F_489 ( struct V_336 * V_337 , int V_338 ,
void T_10 * V_339 , T_7 * V_340 , T_11 * V_341 )
{
struct V_12 * V_12 ;
int V_532 ;
V_532 = F_488 ( V_337 , V_338 , V_339 , V_340 , V_341 ) ;
if ( V_532 )
return V_532 ;
F_478 (zone)
V_12 -> V_445 = ( V_12 -> V_85 *
V_446 ) / 100 ;
return 0 ;
}
int F_490 ( struct V_336 * V_337 , int V_338 ,
void T_10 * V_339 , T_7 * V_340 , T_11 * V_341 )
{
struct V_12 * V_12 ;
int V_532 ;
V_532 = F_488 ( V_337 , V_338 , V_339 , V_340 , V_341 ) ;
if ( V_532 )
return V_532 ;
F_478 (zone)
V_12 -> V_447 = ( V_12 -> V_85 *
V_448 ) / 100 ;
return 0 ;
}
int F_491 ( struct V_336 * V_337 , int V_338 ,
void T_10 * V_339 , T_7 * V_340 , T_11 * V_341 )
{
F_488 ( V_337 , V_338 , V_339 , V_340 , V_341 ) ;
F_476 () ;
return 0 ;
}
int F_492 ( struct V_336 * V_337 , int V_338 ,
void T_10 * V_339 , T_7 * V_340 , T_11 * V_341 )
{
struct V_12 * V_12 ;
int V_533 ;
int V_13 ;
F_324 ( & V_534 ) ;
V_533 = V_392 ;
V_13 = F_488 ( V_337 , V_338 , V_339 , V_340 , V_341 ) ;
if ( ! V_338 || V_13 < 0 )
goto V_27;
if ( V_392 &&
V_392 < V_535 ) {
V_392 = V_533 ;
V_13 = - V_333 ;
goto V_27;
}
if ( V_392 == V_533 )
goto V_27;
F_140 (zone) {
unsigned int V_117 ;
F_347 (cpu)
F_386 ( V_12 ,
F_141 ( V_12 -> V_120 , V_117 ) ) ;
}
V_27:
F_327 ( & V_534 ) ;
return V_13 ;
}
static int T_2 F_493 ( char * V_140 )
{
if ( ! V_140 )
return 0 ;
V_536 = F_494 ( V_140 , & V_140 , 0 ) ;
return 1 ;
}
void * T_2 F_495 ( const char * V_537 ,
unsigned long V_538 ,
unsigned long V_539 ,
int V_540 ,
int V_64 ,
unsigned int * V_541 ,
unsigned int * V_542 ,
unsigned long V_543 ,
unsigned long V_544 )
{
unsigned long long F_360 = V_544 ;
unsigned long V_545 , V_93 ;
void * V_337 = NULL ;
if ( ! V_539 ) {
V_539 = V_443 ;
if ( V_391 < 20 )
V_539 = F_496 ( V_539 , ( 1 << 20 ) / V_82 ) ;
if ( V_540 > V_391 )
V_539 >>= ( V_540 - V_391 ) ;
else
V_539 <<= ( V_391 - V_540 ) ;
if ( F_7 ( V_64 & V_546 ) ) {
F_2 ( ! ( V_64 & V_547 ) ) ;
if ( ! ( V_539 >> * V_541 ) ) {
V_539 = 1UL << * V_541 ;
F_124 ( ! V_539 ) ;
}
} else if ( F_7 ( ( V_539 * V_538 ) < V_82 ) )
V_539 = V_82 / V_538 ;
}
V_539 = F_497 ( V_539 ) ;
if ( F_360 == 0 ) {
F_360 = ( ( unsigned long long ) V_444 << V_391 ) >> 4 ;
F_480 ( F_360 , V_538 ) ;
}
F_360 = F_138 ( F_360 , 0x80000000ULL ) ;
if ( V_539 < V_543 )
V_539 = V_543 ;
if ( V_539 > F_360 )
V_539 = F_360 ;
V_545 = F_498 ( V_539 ) ;
do {
V_93 = V_538 << V_545 ;
if ( V_64 & V_547 )
V_337 = F_499 ( V_93 , 0 ) ;
else if ( V_536 )
V_337 = F_500 ( V_93 , V_548 , V_549 ) ;
else {
if ( F_291 ( V_93 ) < V_44 ) {
V_337 = F_290 ( V_93 , V_548 ) ;
F_501 ( V_337 , V_93 , 1 , V_548 ) ;
}
}
} while ( ! V_337 && V_93 > V_82 && -- V_545 );
if ( ! V_337 )
F_502 ( L_103 , V_537 ) ;
F_24 ( V_47 L_104 ,
V_537 ,
( 1UL << V_545 ) ,
F_498 ( V_93 ) - V_391 ,
V_93 ) ;
if ( V_541 )
* V_541 = V_545 ;
if ( V_542 )
* V_542 = ( 1 << V_545 ) - 1 ;
return V_337 ;
}
static inline unsigned long * F_503 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_433
return F_504 ( V_15 ) -> V_430 ;
#else
return V_12 -> V_430 ;
#endif
}
static inline int F_505 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_433
V_15 &= ( V_550 - 1 ) ;
return ( V_15 >> V_88 ) * V_429 ;
#else
V_15 = V_15 - F_506 ( V_12 -> V_18 , V_86 ) ;
return ( V_15 >> V_88 ) * V_429 ;
#endif
}
unsigned long F_507 ( struct V_5 * V_5 , unsigned long V_15 ,
unsigned long V_551 ,
unsigned long V_460 )
{
struct V_12 * V_12 ;
unsigned long * V_552 ;
unsigned long V_553 , V_554 ;
unsigned long V_555 ;
V_12 = F_18 ( V_5 ) ;
V_552 = F_503 ( V_12 , V_15 ) ;
V_553 = F_505 ( V_12 , V_15 ) ;
V_554 = V_553 / V_556 ;
V_553 &= ( V_556 - 1 ) ;
V_555 = V_552 [ V_554 ] ;
V_553 += V_551 ;
return ( V_555 >> ( V_556 - V_553 - 1 ) ) & V_460 ;
}
void F_508 ( struct V_5 * V_5 , unsigned long V_64 ,
unsigned long V_15 ,
unsigned long V_551 ,
unsigned long V_460 )
{
struct V_12 * V_12 ;
unsigned long * V_552 ;
unsigned long V_553 , V_554 ;
unsigned long V_557 , V_555 ;
F_219 ( V_429 != 4 ) ;
V_12 = F_18 ( V_5 ) ;
V_552 = F_503 ( V_12 , V_15 ) ;
V_553 = F_505 ( V_12 , V_15 ) ;
V_554 = V_553 / V_556 ;
V_553 &= ( V_556 - 1 ) ;
F_62 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
V_553 += V_551 ;
V_460 <<= ( V_556 - V_553 - 1 ) ;
V_64 <<= ( V_556 - V_553 - 1 ) ;
V_555 = F_137 ( V_552 [ V_554 ] ) ;
for (; ; ) {
V_557 = F_509 ( & V_552 [ V_554 ] , V_555 , ( V_555 & ~ V_460 ) | V_64 ) ;
if ( V_555 == V_557 )
break;
V_555 = V_557 ;
}
}
bool F_510 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_67 ,
bool V_558 )
{
unsigned long V_15 , V_559 , V_560 ;
int V_78 ;
if ( F_253 ( V_12 ) == V_408 )
return false ;
V_78 = F_171 ( V_5 ) ;
if ( V_78 == V_127 || F_88 ( V_78 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_560 = 0 , V_559 = 0 ; V_559 < V_86 ; V_559 ++ ) {
unsigned long V_561 = V_15 + V_559 ;
if ( ! F_17 ( V_561 ) )
continue;
V_5 = F_128 ( V_561 ) ;
if ( F_511 ( V_5 ) ) {
V_559 = F_496 ( V_559 + 1 , 1 << F_31 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_75 ( & V_5 -> V_63 ) ) {
if ( F_65 ( V_5 ) )
V_559 += ( 1 << F_61 ( V_5 ) ) - 1 ;
continue;
}
if ( V_558 && F_21 ( V_5 ) )
continue;
if ( ! F_512 ( V_5 ) )
V_560 ++ ;
if ( V_560 > V_67 )
return true ;
}
return false ;
}
bool F_513 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_345 ( F_125 ( V_5 ) ) )
return false ;
V_12 = F_18 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_510 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_514 ( unsigned long V_15 )
{
return V_15 & ~ ( F_515 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_516 ( unsigned long V_15 )
{
return F_431 ( V_15 , F_515 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_517 ( struct V_562 * V_563 ,
unsigned long V_452 , unsigned long V_278 )
{
unsigned long V_564 ;
unsigned long V_15 = V_452 ;
unsigned int V_565 = 0 ;
int V_13 = 0 ;
F_518 () ;
while ( V_15 < V_278 || ! F_82 ( & V_563 -> V_566 ) ) {
if ( F_519 ( V_30 ) ) {
V_13 = - V_567 ;
break;
}
if ( F_82 ( & V_563 -> V_566 ) ) {
V_563 -> V_568 = 0 ;
V_15 = F_520 ( V_563 -> V_12 , V_563 ,
V_15 , V_278 , true ) ;
if ( ! V_15 ) {
V_13 = - V_567 ;
break;
}
V_565 = 0 ;
} else if ( ++ V_565 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_569 ;
break;
}
V_564 = F_521 ( V_563 -> V_12 ,
& V_563 -> V_566 ) ;
V_563 -> V_568 -= V_564 ;
V_13 = F_522 ( & V_563 -> V_566 , V_570 ,
NULL , 0 , V_563 -> V_148 , V_571 ) ;
}
if ( V_13 < 0 ) {
F_523 ( & V_563 -> V_566 ) ;
return V_13 ;
}
return 0 ;
}
int F_524 ( unsigned long V_452 , unsigned long V_278 ,
unsigned V_6 )
{
unsigned long V_572 , V_573 ;
int V_13 = 0 , V_34 ;
struct V_562 V_563 = {
. V_568 = 0 ,
. V_34 = - 1 ,
. V_12 = F_18 ( F_128 ( V_452 ) ) ,
. V_148 = V_574 ,
. V_575 = true ,
} ;
F_117 ( & V_563 . V_566 ) ;
V_13 = F_525 ( F_514 ( V_452 ) ,
F_516 ( V_278 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_517 ( & V_563 , V_452 , V_278 ) ;
if ( V_13 )
goto V_576;
F_526 () ;
F_144 () ;
V_34 = 0 ;
V_572 = V_452 ;
while ( ! F_65 ( F_128 ( V_572 ) ) ) {
if ( ++ V_34 >= V_44 ) {
V_13 = - V_569 ;
goto V_576;
}
V_572 &= ~ 0UL << V_34 ;
}
if ( F_527 ( V_572 , V_278 , false ) ) {
F_225 ( L_105 ,
V_572 , V_278 ) ;
V_13 = - V_569 ;
goto V_576;
}
V_573 = F_528 ( & V_563 , V_572 , V_278 ) ;
if ( ! V_573 ) {
V_13 = - V_569 ;
goto V_576;
}
if ( V_452 != V_572 )
F_529 ( V_572 , V_452 - V_572 ) ;
if ( V_278 != V_573 )
F_529 ( V_278 , V_573 - V_278 ) ;
V_576:
F_530 ( F_514 ( V_452 ) ,
F_516 ( V_278 ) , V_6 ) ;
return V_13 ;
}
void F_529 ( unsigned long V_15 , unsigned V_36 )
{
unsigned int V_67 = 0 ;
for (; V_36 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_128 ( V_15 ) ;
V_67 += F_63 ( V_5 ) != 1 ;
F_531 ( V_5 ) ;
}
F_532 ( V_67 != 0 , L_106 , V_67 ) ;
}
void T_8 F_533 ( struct V_12 * V_12 )
{
unsigned V_117 ;
F_324 ( & V_534 ) ;
F_347 (cpu)
F_386 ( V_12 ,
F_141 ( V_12 -> V_120 , V_117 ) ) ;
F_327 ( & V_534 ) ;
}
void F_534 ( struct V_12 * V_12 )
{
unsigned long V_64 ;
int V_117 ;
struct V_118 * V_119 ;
F_103 ( V_64 ) ;
if ( V_12 -> V_120 != & V_374 ) {
F_145 (cpu) {
V_119 = F_141 ( V_12 -> V_120 , V_117 ) ;
F_535 ( V_12 , V_119 ) ;
}
F_536 ( V_12 -> V_120 ) ;
V_12 -> V_120 = & V_374 ;
}
F_106 ( V_64 ) ;
}
void
F_537 ( unsigned long V_17 , unsigned long V_101 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
unsigned int V_34 , V_35 ;
unsigned long V_15 ;
unsigned long V_64 ;
for ( V_15 = V_17 ; V_15 < V_101 ; V_15 ++ )
if ( F_153 ( V_15 ) )
break;
if ( V_15 == V_101 )
return;
V_12 = F_18 ( F_128 ( V_15 ) ) ;
F_151 ( & V_12 -> V_73 , V_64 ) ;
V_15 = V_17 ;
while ( V_15 < V_101 ) {
if ( ! F_153 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_128 ( V_15 ) ;
if ( F_7 ( ! F_65 ( V_5 ) && F_21 ( V_5 ) ) ) {
V_15 ++ ;
F_373 ( V_5 ) ;
continue;
}
F_124 ( F_63 ( V_5 ) ) ;
F_124 ( ! F_65 ( V_5 ) ) ;
V_34 = F_61 ( V_5 ) ;
#ifdef F_538
F_24 ( V_47 L_107 ,
V_15 , 1 << V_34 , V_101 ) ;
#endif
F_70 ( & V_5 -> V_55 ) ;
F_56 ( V_5 ) ;
V_12 -> V_56 [ V_34 ] . V_57 -- ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_373 ( ( V_5 + V_35 ) ) ;
V_15 += ( 1 << V_34 ) ;
}
F_159 ( & V_12 -> V_73 , V_64 ) ;
}
bool F_539 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_64 ;
unsigned int V_34 ;
F_151 ( & V_12 -> V_73 , V_64 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
struct V_5 * V_577 = V_5 - ( V_15 & ( ( 1 << V_34 ) - 1 ) ) ;
if ( F_65 ( V_577 ) && F_61 ( V_577 ) >= V_34 )
break;
}
F_159 ( & V_12 -> V_73 , V_64 ) ;
return V_34 < V_44 ;
}
static void F_540 ( unsigned long V_64 )
{
const char * V_578 = L_101 ;
unsigned long V_460 ;
int V_35 ;
F_219 ( F_541 ( V_579 ) != V_580 ) ;
F_24 ( V_28 L_108 , V_64 ) ;
V_64 &= ( 1UL << V_581 ) - 1 ;
for ( V_35 = 0 ; V_35 < F_541 ( V_579 ) && V_64 ; V_35 ++ ) {
V_460 = V_579 [ V_35 ] . V_460 ;
if ( ( V_64 & V_460 ) != V_460 )
continue;
V_64 &= ~ V_460 ;
F_24 ( L_109 , V_578 , V_579 [ V_35 ] . V_20 ) ;
V_578 = L_110 ;
}
if ( V_64 )
F_24 ( L_111 , V_578 , V_64 ) ;
F_24 ( L_112 ) ;
}
void F_25 ( struct V_5 * V_5 , const char * V_21 ,
unsigned long V_582 )
{
F_24 ( V_28
L_113 ,
V_5 , F_75 ( & V_5 -> V_63 ) , F_74 ( V_5 ) ,
V_5 -> V_62 , V_5 -> V_583 ) ;
F_540 ( V_5 -> V_64 ) ;
if ( V_21 )
F_542 ( L_114 , V_21 ) ;
if ( V_5 -> V_64 & V_582 ) {
F_542 ( L_115 ) ;
F_540 ( V_5 -> V_64 & V_582 ) ;
}
F_543 ( V_5 ) ;
}
void F_544 ( struct V_5 * V_5 , const char * V_21 )
{
F_25 ( V_5 , V_21 , 0 ) ;
}
