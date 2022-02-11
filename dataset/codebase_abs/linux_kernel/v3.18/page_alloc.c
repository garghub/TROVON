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
static inline int F_58 ( struct V_5 * V_5 , struct V_5 * V_50 ,
unsigned int V_34 )
{
if ( ! F_17 ( F_10 ( V_50 ) ) )
return 0 ;
if ( F_59 ( V_50 ) && F_60 ( V_50 ) == V_34 ) {
F_61 ( F_62 ( V_50 ) != 0 , V_50 ) ;
if ( F_63 ( V_5 ) != F_63 ( V_50 ) )
return 0 ;
return 1 ;
}
if ( F_64 ( V_50 ) && F_60 ( V_50 ) == V_34 ) {
F_61 ( F_62 ( V_50 ) != 0 , V_50 ) ;
if ( F_63 ( V_5 ) != F_63 ( V_50 ) )
return 0 ;
return 1 ;
}
return 0 ;
}
static inline void F_65 ( struct V_5 * V_5 ,
unsigned long V_15 ,
struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned long V_51 ;
unsigned long V_52 ;
unsigned long V_53 ( V_54 ) ;
struct V_5 * V_50 ;
int V_55 = V_44 ;
F_44 ( ! F_66 ( V_12 ) ) ;
if ( F_7 ( F_67 ( V_5 ) ) )
if ( F_7 ( F_39 ( V_5 , V_34 ) ) )
return;
F_44 ( V_6 == - 1 ) ;
if ( F_68 ( V_6 ) ) {
V_55 = F_69 ( V_44 , V_56 + 1 ) ;
} else {
F_70 ( V_12 , 1 << V_34 , V_6 ) ;
}
V_51 = V_15 & ( ( 1 << V_55 ) - 1 ) ;
F_61 ( V_51 & ( ( 1 << V_34 ) - 1 ) , V_5 ) ;
F_61 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
while ( V_34 < V_55 - 1 ) {
V_54 = F_71 ( V_51 , V_34 ) ;
V_50 = V_5 + ( V_54 - V_51 ) ;
if ( ! F_58 ( V_5 , V_50 , V_34 ) )
break;
if ( F_59 ( V_50 ) ) {
F_51 ( V_50 ) ;
F_54 ( V_50 , 0 ) ;
if ( ! F_68 ( V_6 ) ) {
F_70 ( V_12 , 1 << V_34 ,
V_6 ) ;
}
} else {
F_72 ( & V_50 -> V_57 ) ;
V_12 -> V_58 [ V_34 ] . V_59 -- ;
F_56 ( V_50 ) ;
}
V_52 = V_54 & V_51 ;
V_5 = V_5 + ( V_52 - V_51 ) ;
V_51 = V_52 ;
V_34 ++ ;
}
F_53 ( V_5 , V_34 ) ;
if ( ( V_34 < V_44 - 2 ) && F_17 ( F_10 ( V_50 ) ) ) {
struct V_5 * V_60 , * V_61 ;
V_52 = V_54 & V_51 ;
V_60 = V_5 + ( V_52 - V_51 ) ;
V_54 = F_71 ( V_52 , V_34 + 1 ) ;
V_61 = V_60 + ( V_54 - V_52 ) ;
if ( F_58 ( V_60 , V_61 , V_34 + 1 ) ) {
F_73 ( & V_5 -> V_57 ,
& V_12 -> V_58 [ V_34 ] . V_62 [ V_6 ] ) ;
goto V_27;
}
}
F_74 ( & V_5 -> V_57 , & V_12 -> V_58 [ V_34 ] . V_62 [ V_6 ] ) ;
V_27:
V_12 -> V_58 [ V_34 ] . V_59 ++ ;
}
static inline int F_75 ( struct V_5 * V_5 )
{
const char * V_63 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_76 ( V_5 ) ) )
V_63 = L_9 ;
if ( F_7 ( V_5 -> V_64 != NULL ) )
V_63 = L_10 ;
if ( F_7 ( F_77 ( & V_5 -> V_65 ) != 0 ) )
V_63 = L_11 ;
if ( F_7 ( V_5 -> V_66 & V_67 ) ) {
V_63 = L_12 ;
V_22 = V_67 ;
}
if ( F_7 ( F_78 ( V_5 ) ) )
V_63 = L_13 ;
if ( F_7 ( V_63 ) ) {
F_20 ( V_5 , V_63 , V_22 ) ;
return 1 ;
}
F_79 ( V_5 ) ;
if ( V_5 -> V_66 & V_68 )
V_5 -> V_66 &= ~ V_68 ;
return 0 ;
}
static void F_80 ( struct V_12 * V_12 , int V_69 ,
struct V_70 * V_71 )
{
int V_6 = 0 ;
int V_72 = 0 ;
int V_73 = V_69 ;
unsigned long V_74 ;
F_81 ( & V_12 -> V_75 ) ;
V_74 = F_82 ( V_12 , V_76 ) ;
if ( V_74 )
F_83 ( V_12 , V_76 , - V_74 ) ;
while ( V_73 ) {
struct V_5 * V_5 ;
struct V_77 * V_78 ;
do {
V_72 ++ ;
if ( ++ V_6 == V_8 )
V_6 = 0 ;
V_78 = & V_71 -> V_79 [ V_6 ] ;
} while ( F_84 ( V_78 ) );
if ( V_72 == V_8 )
V_72 = V_73 ;
do {
int V_80 ;
V_5 = F_85 ( V_78 -> V_81 , struct V_5 , V_57 ) ;
F_72 ( & V_5 -> V_57 ) ;
V_80 = F_86 ( V_5 ) ;
if ( F_7 ( F_87 ( V_12 ) ) )
V_80 = F_88 ( V_5 ) ;
F_65 ( V_5 , F_10 ( V_5 ) , V_12 , 0 , V_80 ) ;
F_89 ( V_5 , 0 , V_80 ) ;
} while ( -- V_73 && -- V_72 && ! F_84 ( V_78 ) );
}
F_90 ( & V_12 -> V_75 ) ;
}
static void F_91 ( struct V_12 * V_12 ,
struct V_5 * V_5 , unsigned long V_15 ,
unsigned int V_34 ,
int V_6 )
{
unsigned long V_74 ;
F_81 ( & V_12 -> V_75 ) ;
V_74 = F_82 ( V_12 , V_76 ) ;
if ( V_74 )
F_83 ( V_12 , V_76 , - V_74 ) ;
if ( F_7 ( F_87 ( V_12 ) ||
F_68 ( V_6 ) ) ) {
V_6 = F_92 ( V_5 , V_15 ) ;
}
F_65 ( V_5 , V_15 , V_12 , V_34 , V_6 ) ;
F_90 ( & V_12 -> V_75 ) ;
}
static bool F_93 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
int V_39 = 0 ;
F_94 ( V_5 , V_34 ) ;
F_95 ( V_5 , V_34 ) ;
if ( F_96 ( V_5 ) )
V_5 -> V_64 = NULL ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
V_39 += F_75 ( V_5 + V_35 ) ;
if ( V_39 )
return false ;
if ( ! F_97 ( V_5 ) ) {
F_98 ( F_99 ( V_5 ) ,
V_82 << V_34 ) ;
F_100 ( F_99 ( V_5 ) ,
V_82 << V_34 ) ;
}
F_101 ( V_5 , V_34 ) ;
F_102 ( V_5 , 1 << V_34 , 0 ) ;
return true ;
}
static void F_30 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_66 ;
int V_6 ;
unsigned long V_15 = F_10 ( V_5 ) ;
if ( ! F_93 ( V_5 , V_34 ) )
return;
V_6 = F_92 ( V_5 , V_15 ) ;
F_103 ( V_66 ) ;
F_104 ( V_83 , 1 << V_34 ) ;
F_105 ( V_5 , V_6 ) ;
F_91 ( F_18 ( V_5 ) , V_5 , V_15 , V_34 , V_6 ) ;
F_106 ( V_66 ) ;
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
if ( V_56 >= V_44 ) {
V_35 = V_86 ;
V_37 = V_5 ;
do {
F_110 ( V_37 ) ;
F_111 ( V_37 , V_44 - 1 ) ;
V_37 += V_88 ;
} while ( V_35 -= V_88 );
} else {
F_110 ( V_5 ) ;
F_111 ( V_5 , V_56 ) ;
}
F_113 ( V_5 , V_86 ) ;
}
static inline void F_114 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_89 , int V_90 , struct V_58 * V_91 ,
int V_6 )
{
unsigned long V_92 = 1 << V_90 ;
while ( V_90 > V_89 ) {
V_91 -- ;
V_90 -- ;
V_92 >>= 1 ;
F_61 ( F_19 ( V_12 , & V_5 [ V_92 ] ) , & V_5 [ V_92 ] ) ;
#ifdef F_115
if ( V_90 < F_116 () ) {
F_117 ( & V_5 [ V_92 ] . V_57 ) ;
F_49 ( & V_5 [ V_92 ] ) ;
F_54 ( & V_5 [ V_92 ] , V_90 ) ;
F_70 ( V_12 , - ( 1 << V_90 ) ,
V_6 ) ;
continue;
}
#endif
F_74 ( & V_5 [ V_92 ] . V_57 , & V_91 -> V_62 [ V_6 ] ) ;
V_91 -> V_59 ++ ;
F_53 ( & V_5 [ V_92 ] , V_90 ) ;
}
}
static inline int F_118 ( struct V_5 * V_5 )
{
const char * V_63 = NULL ;
unsigned long V_22 = 0 ;
if ( F_7 ( F_76 ( V_5 ) ) )
V_63 = L_9 ;
if ( F_7 ( V_5 -> V_64 != NULL ) )
V_63 = L_10 ;
if ( F_7 ( F_77 ( & V_5 -> V_65 ) != 0 ) )
V_63 = L_11 ;
if ( F_7 ( V_5 -> V_66 & V_68 ) ) {
V_63 = L_14 ;
V_22 = V_68 ;
}
if ( F_7 ( F_78 ( V_5 ) ) )
V_63 = L_13 ;
if ( F_7 ( V_63 ) ) {
F_20 ( V_5 , V_63 , V_22 ) ;
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
F_102 ( V_5 , 1 << V_34 , 1 ) ;
if ( V_40 & V_93 )
F_43 ( V_5 , V_34 , V_40 ) ;
if ( V_34 && ( V_40 & V_94 ) )
F_32 ( V_5 , V_34 ) ;
return 0 ;
}
static inline
struct V_5 * F_121 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned int V_95 ;
struct V_58 * V_91 ;
struct V_5 * V_5 ;
for ( V_95 = V_34 ; V_95 < V_44 ; ++ V_95 ) {
V_91 = & ( V_12 -> V_58 [ V_95 ] ) ;
if ( F_84 ( & V_91 -> V_62 [ V_6 ] ) )
continue;
V_5 = F_85 ( V_91 -> V_62 [ V_6 ] . V_96 ,
struct V_5 , V_57 ) ;
F_72 ( & V_5 -> V_57 ) ;
F_56 ( V_5 ) ;
V_91 -> V_59 -- ;
F_114 ( V_12 , V_5 , V_34 , V_95 , V_91 , V_6 ) ;
F_105 ( V_5 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_122 ( struct V_12 * V_12 ,
struct V_5 * V_97 , struct V_5 * V_98 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_34 ;
int V_99 = 0 ;
#ifndef F_123
F_44 ( F_18 ( V_97 ) != F_18 ( V_98 ) ) ;
#endif
for ( V_5 = V_97 ; V_5 <= V_98 ; ) {
F_61 ( F_124 ( V_5 ) != F_15 ( V_12 ) , V_5 ) ;
if ( ! F_17 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_64 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_34 = F_60 ( V_5 ) ;
F_125 ( & V_5 -> V_57 ,
& V_12 -> V_58 [ V_34 ] . V_62 [ V_6 ] ) ;
F_105 ( V_5 , V_6 ) ;
V_5 += 1 << V_34 ;
V_99 += 1 << V_34 ;
}
return V_99 ;
}
int F_126 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_17 , V_100 ;
struct V_5 * V_97 , * V_98 ;
V_17 = F_10 ( V_5 ) ;
V_17 = V_17 & ~ ( V_86 - 1 ) ;
V_97 = F_127 ( V_17 ) ;
V_98 = V_97 + V_86 - 1 ;
V_100 = V_17 + V_86 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_97 = V_5 ;
if ( ! F_12 ( V_12 , V_100 ) )
return 0 ;
return F_122 ( V_12 , V_97 , V_98 , V_6 ) ;
}
static void F_128 ( struct V_5 * V_101 ,
int V_102 , int V_6 )
{
int V_103 = 1 << ( V_102 - V_56 ) ;
while ( V_103 -- ) {
F_6 ( V_101 , V_6 ) ;
V_101 += V_86 ;
}
}
static int F_129 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_104 , int V_105 )
{
int V_95 = F_60 ( V_5 ) ;
if ( F_130 ( V_105 ) )
return V_105 ;
if ( V_95 >= V_56 ) {
F_128 ( V_5 , V_95 , V_104 ) ;
return V_104 ;
}
if ( V_95 >= V_56 / 2 ||
V_104 == V_106 ||
V_7 ) {
int V_107 ;
V_107 = F_126 ( V_12 , V_5 , V_104 ) ;
if ( V_107 >= ( 1 << ( V_56 - 1 ) ) ||
V_7 ) {
F_6 ( V_5 , V_104 ) ;
return V_104 ;
}
}
return V_105 ;
}
static inline struct V_5 *
F_131 ( struct V_12 * V_12 , unsigned int V_34 , int V_108 )
{
struct V_58 * V_91 ;
unsigned int V_95 ;
struct V_5 * V_5 ;
int V_6 , V_109 , V_35 ;
for ( V_95 = V_44 - 1 ;
V_95 >= V_34 && V_95 <= V_44 - 1 ;
-- V_95 ) {
for ( V_35 = 0 ; ; V_35 ++ ) {
V_6 = V_110 [ V_108 ] [ V_35 ] ;
if ( V_6 == V_111 )
break;
V_91 = & ( V_12 -> V_58 [ V_95 ] ) ;
if ( F_84 ( & V_91 -> V_62 [ V_6 ] ) )
continue;
V_5 = F_85 ( V_91 -> V_62 [ V_6 ] . V_96 ,
struct V_5 , V_57 ) ;
V_91 -> V_59 -- ;
V_109 = F_129 ( V_12 , V_5 ,
V_108 ,
V_6 ) ;
F_72 ( & V_5 -> V_57 ) ;
F_56 ( V_5 ) ;
F_114 ( V_12 , V_5 , V_34 , V_95 , V_91 ,
V_109 ) ;
F_105 ( V_5 , V_109 ) ;
F_132 ( V_5 , V_34 , V_95 ,
V_108 , V_6 , V_109 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_133 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
struct V_5 * V_5 ;
V_112:
V_5 = F_121 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_111 ) {
V_5 = F_131 ( V_12 , V_34 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_111 ;
goto V_112;
}
}
F_134 ( V_5 , V_34 , V_6 ) ;
return V_5 ;
}
static int F_135 ( struct V_12 * V_12 , unsigned int V_34 ,
unsigned long V_69 , struct V_77 * V_78 ,
int V_6 , bool V_113 )
{
int V_35 ;
F_81 ( & V_12 -> V_75 ) ;
for ( V_35 = 0 ; V_35 < V_69 ; ++ V_35 ) {
struct V_5 * V_5 = F_133 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_136 ( ! V_113 ) )
F_74 ( & V_5 -> V_57 , V_78 ) ;
else
F_73 ( & V_5 -> V_57 , V_78 ) ;
V_78 = & V_5 -> V_57 ;
if ( F_130 ( F_86 ( V_5 ) ) )
F_83 ( V_12 , V_114 ,
- ( 1 << V_34 ) ) ;
}
F_83 ( V_12 , V_115 , - ( V_35 << V_34 ) ) ;
F_90 ( & V_12 -> V_75 ) ;
return V_35 ;
}
void F_137 ( struct V_12 * V_12 , struct V_70 * V_71 )
{
unsigned long V_66 ;
int V_116 , V_117 ;
F_103 ( V_66 ) ;
V_117 = F_138 ( V_71 -> V_117 ) ;
V_116 = F_69 ( V_71 -> V_69 , V_117 ) ;
if ( V_116 > 0 ) {
F_80 ( V_12 , V_116 , V_71 ) ;
V_71 -> V_69 -= V_116 ;
}
F_106 ( V_66 ) ;
}
static void F_139 ( unsigned int V_118 )
{
unsigned long V_66 ;
struct V_12 * V_12 ;
F_140 (zone) {
struct V_119 * V_120 ;
struct V_70 * V_71 ;
F_103 ( V_66 ) ;
V_120 = F_141 ( V_12 -> V_121 , V_118 ) ;
V_71 = & V_120 -> V_71 ;
if ( V_71 -> V_69 ) {
F_80 ( V_12 , V_71 -> V_69 , V_71 ) ;
V_71 -> V_69 = 0 ;
}
F_106 ( V_66 ) ;
}
}
void F_142 ( void * V_122 )
{
F_139 ( F_143 () ) ;
}
void F_144 ( void )
{
int V_118 ;
struct V_119 * V_71 ;
struct V_12 * V_12 ;
static T_3 V_123 ;
F_145 (cpu) {
bool V_124 = false ;
F_140 (zone) {
V_71 = F_141 ( V_12 -> V_121 , V_118 ) ;
if ( V_71 -> V_71 . V_69 ) {
V_124 = true ;
break;
}
}
if ( V_124 )
F_146 ( V_118 , & V_123 ) ;
else
F_147 ( V_118 , & V_123 ) ;
}
F_148 ( & V_123 , F_142 , NULL , 1 ) ;
}
void F_149 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_125 ;
unsigned long V_66 ;
unsigned int V_34 , V_126 ;
struct V_77 * V_127 ;
if ( F_150 ( V_12 ) )
return;
F_151 ( & V_12 -> V_75 , V_66 ) ;
V_125 = F_152 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_125 ; V_15 ++ )
if ( F_153 ( V_15 ) ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
if ( ! F_154 ( V_5 ) )
F_155 ( V_5 ) ;
}
F_156 (order, t) {
F_157 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_35 ;
V_15 = F_10 ( F_85 ( V_127 , struct V_5 , V_57 ) ) ;
for ( V_35 = 0 ; V_35 < ( 1UL << V_34 ) ; V_35 ++ )
F_158 ( F_127 ( V_15 + V_35 ) ) ;
}
}
F_159 ( & V_12 -> V_75 , V_66 ) ;
}
void F_160 ( struct V_5 * V_5 , bool V_113 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
struct V_70 * V_71 ;
unsigned long V_66 ;
unsigned long V_15 = F_10 ( V_5 ) ;
int V_6 ;
if ( ! F_93 ( V_5 , 0 ) )
return;
V_6 = F_92 ( V_5 , V_15 ) ;
F_105 ( V_5 , V_6 ) ;
F_103 ( V_66 ) ;
F_161 ( V_83 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_68 ( V_6 ) ) ) {
F_91 ( V_12 , V_5 , V_15 , 0 , V_6 ) ;
goto V_27;
}
V_6 = V_128 ;
}
V_71 = & F_162 ( V_12 -> V_121 ) -> V_71 ;
if ( ! V_113 )
F_74 ( & V_5 -> V_57 , & V_71 -> V_79 [ V_6 ] ) ;
else
F_73 ( & V_5 -> V_57 , & V_71 -> V_79 [ V_6 ] ) ;
V_71 -> V_69 ++ ;
if ( V_71 -> V_69 >= V_71 -> V_90 ) {
unsigned long V_117 = F_138 ( V_71 -> V_117 ) ;
F_80 ( V_12 , V_117 , V_71 ) ;
V_71 -> V_69 -= V_117 ;
}
V_27:
F_106 ( V_66 ) ;
}
void F_163 ( struct V_77 * V_78 , bool V_113 )
{
struct V_5 * V_5 , * V_96 ;
F_164 (page, next, list, lru) {
F_165 ( V_5 , V_113 ) ;
F_160 ( V_5 , V_113 ) ;
}
}
void F_166 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
F_61 ( F_67 ( V_5 ) , V_5 ) ;
F_61 ( ! F_62 ( V_5 ) , V_5 ) ;
#ifdef F_167
if ( F_168 ( V_5 ) )
F_166 ( F_169 ( V_5 [ 0 ] . V_129 ) , V_34 ) ;
#endif
for ( V_35 = 1 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_110 ( V_5 + V_35 ) ;
}
int F_170 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_130 ;
struct V_12 * V_12 ;
int V_80 ;
F_171 ( ! F_64 ( V_5 ) ) ;
V_12 = F_18 ( V_5 ) ;
V_80 = F_88 ( V_5 ) ;
if ( ! F_68 ( V_80 ) ) {
V_130 = F_172 ( V_12 ) + ( 1 << V_34 ) ;
if ( ! F_173 ( V_12 , 0 , V_130 , 0 , 0 ) )
return 0 ;
F_70 ( V_12 , - ( 1UL << V_34 ) , V_80 ) ;
}
F_72 ( & V_5 -> V_57 ) ;
V_12 -> V_58 [ V_34 ] . V_59 -- ;
F_56 ( V_5 ) ;
if ( V_34 >= V_56 - 1 ) {
struct V_5 * V_131 = V_5 + ( 1 << V_34 ) - 1 ;
for (; V_5 < V_131 ; V_5 += V_86 ) {
int V_80 = F_88 ( V_5 ) ;
if ( ! F_68 ( V_80 ) && ! F_130 ( V_80 ) )
F_6 ( V_5 ,
V_128 ) ;
}
}
return 1UL << V_34 ;
}
int F_174 ( struct V_5 * V_5 )
{
unsigned int V_34 ;
int V_36 ;
V_34 = F_60 ( V_5 ) ;
V_36 = F_170 ( V_5 , V_34 ) ;
if ( ! V_36 )
return 0 ;
F_110 ( V_5 ) ;
F_166 ( V_5 , V_34 ) ;
return V_36 ;
}
static inline
struct V_5 * F_175 ( struct V_12 * V_132 ,
struct V_12 * V_12 , unsigned int V_34 ,
T_1 V_40 , int V_6 )
{
unsigned long V_66 ;
struct V_5 * V_5 ;
bool V_113 = ( ( V_40 & V_133 ) != 0 ) ;
V_134:
if ( F_136 ( V_34 == 0 ) ) {
struct V_70 * V_71 ;
struct V_77 * V_78 ;
F_103 ( V_66 ) ;
V_71 = & F_162 ( V_12 -> V_121 ) -> V_71 ;
V_78 = & V_71 -> V_79 [ V_6 ] ;
if ( F_84 ( V_78 ) ) {
V_71 -> V_69 += F_135 ( V_12 , 0 ,
V_71 -> V_117 , V_78 ,
V_6 , V_113 ) ;
if ( F_7 ( F_84 ( V_78 ) ) )
goto V_135;
}
if ( V_113 )
V_5 = F_85 ( V_78 -> V_81 , struct V_5 , V_57 ) ;
else
V_5 = F_85 ( V_78 -> V_96 , struct V_5 , V_57 ) ;
F_72 ( & V_5 -> V_57 ) ;
V_71 -> V_69 -- ;
} else {
if ( F_7 ( V_40 & V_136 ) ) {
F_176 ( V_34 > 1 ) ;
}
F_151 ( & V_12 -> V_75 , V_66 ) ;
V_5 = F_133 ( V_12 , V_34 , V_6 ) ;
F_90 ( & V_12 -> V_75 ) ;
if ( ! V_5 )
goto V_135;
F_70 ( V_12 , - ( 1 << V_34 ) ,
F_86 ( V_5 ) ) ;
}
F_83 ( V_12 , V_137 , - ( 1 << V_34 ) ) ;
if ( F_177 ( & V_12 -> V_138 [ V_137 ] ) <= 0 &&
! F_178 ( V_139 , & V_12 -> V_66 ) )
F_179 ( V_139 , & V_12 -> V_66 ) ;
F_180 ( V_140 , V_12 , 1 << V_34 ) ;
F_181 ( V_132 , V_12 , V_40 ) ;
F_106 ( V_66 ) ;
F_61 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
if ( F_119 ( V_5 , V_34 , V_40 ) )
goto V_134;
return V_5 ;
V_135:
F_106 ( V_66 ) ;
return NULL ;
}
static int T_2 F_182 ( char * V_141 )
{
return F_183 ( & V_142 . V_143 , V_141 ) ;
}
static bool F_184 ( T_1 V_144 , unsigned int V_34 )
{
if ( V_34 < V_142 . V_145 )
return false ;
if ( V_144 & V_136 )
return false ;
if ( V_142 . V_146 && ( V_144 & V_41 ) )
return false ;
if ( V_142 . V_147 && ( V_144 & V_148 ) )
return false ;
return F_185 ( & V_142 . V_143 , 1 << V_34 ) ;
}
static int T_2 F_186 ( void )
{
T_4 V_149 = V_150 | V_151 | V_152 ;
struct V_153 * V_154 ;
V_154 = F_187 ( L_15 , NULL ,
& V_142 . V_143 ) ;
if ( F_188 ( V_154 ) )
return F_189 ( V_154 ) ;
if ( ! F_190 ( L_16 , V_149 , V_154 ,
& V_142 . V_147 ) )
goto V_155;
if ( ! F_190 ( L_17 , V_149 , V_154 ,
& V_142 . V_146 ) )
goto V_155;
if ( ! F_191 ( L_18 , V_149 , V_154 ,
& V_142 . V_145 ) )
goto V_155;
return 0 ;
V_155:
F_192 ( V_154 ) ;
return - V_156 ;
}
static inline bool F_184 ( T_1 V_144 , unsigned int V_34 )
{
return false ;
}
static bool F_193 ( struct V_12 * V_157 , unsigned int V_34 ,
unsigned long V_158 , int V_159 , int V_160 ,
long V_161 )
{
long F_69 = V_158 ;
int V_162 ;
long V_163 = 0 ;
V_161 -= ( 1 << V_34 ) - 1 ;
if ( V_160 & V_164 )
F_69 -= F_69 / 2 ;
if ( V_160 & V_165 )
F_69 -= F_69 / 4 ;
#ifdef F_194
if ( ! ( V_160 & V_166 ) )
V_163 = F_82 ( V_157 , V_114 ) ;
#endif
if ( V_161 - V_163 <= F_69 + V_157 -> V_167 [ V_159 ] )
return false ;
for ( V_162 = 0 ; V_162 < V_34 ; V_162 ++ ) {
V_161 -= V_157 -> V_58 [ V_162 ] . V_59 << V_162 ;
F_69 >>= 1 ;
if ( V_161 <= F_69 )
return false ;
}
return true ;
}
bool F_173 ( struct V_12 * V_157 , unsigned int V_34 , unsigned long V_158 ,
int V_159 , int V_160 )
{
return F_193 ( V_157 , V_34 , V_158 , V_159 , V_160 ,
F_82 ( V_157 , V_115 ) ) ;
}
bool F_195 ( struct V_12 * V_157 , unsigned int V_34 ,
unsigned long V_158 , int V_159 , int V_160 )
{
long V_161 = F_82 ( V_157 , V_115 ) ;
if ( V_157 -> V_168 && V_161 < V_157 -> V_168 )
V_161 = F_196 ( V_157 , V_115 ) ;
return F_193 ( V_157 , V_34 , V_158 , V_159 , V_160 ,
V_161 ) ;
}
static T_5 * F_197 ( struct V_169 * V_169 , int V_160 )
{
struct V_170 * V_171 ;
T_5 * V_172 ;
V_171 = V_169 -> V_173 ;
if ( ! V_171 )
return NULL ;
if ( F_198 ( V_26 , V_171 -> V_174 + V_29 ) ) {
F_199 ( V_171 -> V_175 , V_176 ) ;
V_171 -> V_174 = V_26 ;
}
V_172 = ! F_45 () && ( V_160 & V_177 ) ?
& V_178 :
& V_179 [ V_180 ] ;
return V_172 ;
}
static int F_200 ( struct V_169 * V_169 , struct V_181 * V_157 ,
T_5 * V_172 )
{
struct V_170 * V_171 ;
int V_35 ;
int V_182 ;
V_171 = V_169 -> V_173 ;
if ( ! V_171 )
return 1 ;
V_35 = V_157 - V_169 -> V_183 ;
V_182 = V_171 -> V_184 [ V_35 ] ;
return F_201 ( V_182 , * V_172 ) && ! F_178 ( V_35 , V_171 -> V_175 ) ;
}
static void F_202 ( struct V_169 * V_169 , struct V_181 * V_157 )
{
struct V_170 * V_171 ;
int V_35 ;
V_171 = V_169 -> V_173 ;
if ( ! V_171 )
return;
V_35 = V_157 - V_169 -> V_183 ;
F_179 ( V_35 , V_171 -> V_175 ) ;
}
static void F_203 ( struct V_169 * V_169 )
{
struct V_170 * V_171 ;
V_171 = V_169 -> V_173 ;
if ( ! V_171 )
return;
F_199 ( V_171 -> V_175 , V_176 ) ;
}
static bool F_204 ( struct V_12 * V_185 , struct V_12 * V_12 )
{
return V_185 -> V_186 == V_12 -> V_186 ;
}
static bool F_205 ( struct V_12 * V_185 , struct V_12 * V_12 )
{
return F_206 ( F_15 ( V_185 ) , F_15 ( V_12 ) ) <
V_187 ;
}
static T_5 * F_197 ( struct V_169 * V_169 , int V_160 )
{
return NULL ;
}
static int F_200 ( struct V_169 * V_169 , struct V_181 * V_157 ,
T_5 * V_172 )
{
return 1 ;
}
static void F_202 ( struct V_169 * V_169 , struct V_181 * V_157 )
{
}
static void F_203 ( struct V_169 * V_169 )
{
}
static bool F_204 ( struct V_12 * V_185 , struct V_12 * V_12 )
{
return true ;
}
static bool F_205 ( struct V_12 * V_185 , struct V_12 * V_12 )
{
return true ;
}
static void F_207 ( struct V_12 * V_132 )
{
struct V_12 * V_12 = V_132 -> V_188 -> V_189 ;
do {
F_208 ( V_12 , V_137 ,
F_209 ( V_12 ) - F_172 ( V_12 ) -
F_177 ( & V_12 -> V_138 [ V_137 ] ) ) ;
F_210 ( V_139 , & V_12 -> V_66 ) ;
} while ( V_12 ++ != V_132 );
}
static struct V_5 *
F_211 ( T_1 V_144 , T_5 * V_190 , unsigned int V_34 ,
struct V_169 * V_169 , int V_191 , int V_160 ,
struct V_12 * V_132 , int V_159 , int V_6 )
{
struct V_181 * V_157 ;
struct V_5 * V_5 = NULL ;
struct V_12 * V_12 ;
T_5 * V_172 = NULL ;
int V_192 = 0 ;
int V_193 = 0 ;
bool V_194 = ( V_160 & V_195 ) &&
( V_144 & V_196 ) ;
int V_197 = 0 ;
bool V_198 ;
V_199:
V_198 = false ;
F_212 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_158 ;
if ( F_213 ( V_200 ) && V_192 &&
! F_200 ( V_169 , V_157 , V_172 ) )
continue;
if ( F_214 () &&
( V_160 & V_177 ) &&
! F_215 ( V_12 , V_144 ) )
continue;
if ( V_160 & V_201 ) {
if ( ! F_204 ( V_132 , V_12 ) )
break;
if ( F_178 ( V_139 , & V_12 -> V_66 ) ) {
V_197 ++ ;
continue;
}
}
if ( V_194 && ! F_216 ( V_12 ) )
continue;
V_158 = V_12 -> V_130 [ V_160 & V_202 ] ;
if ( ! F_173 ( V_12 , V_34 , V_158 ,
V_159 , V_160 ) ) {
int V_13 ;
F_217 ( V_203 < V_204 ) ;
if ( V_160 & V_203 )
goto V_205;
if ( F_213 ( V_200 ) &&
! V_193 && V_206 > 1 ) {
V_172 = F_197 ( V_169 , V_160 ) ;
V_192 = 1 ;
V_193 = 1 ;
}
if ( V_207 == 0 ||
! F_205 ( V_132 , V_12 ) )
goto V_208;
if ( F_213 ( V_200 ) && V_192 &&
! F_200 ( V_169 , V_157 , V_172 ) )
continue;
V_13 = F_218 ( V_12 , V_144 , V_34 ) ;
switch ( V_13 ) {
case V_209 :
continue;
case V_210 :
continue;
default:
if ( F_173 ( V_12 , V_34 , V_158 ,
V_159 , V_160 ) )
goto V_205;
if ( ( ( V_160 & V_202 ) == V_211 ) ||
V_13 == V_212 )
goto V_208;
continue;
}
}
V_205:
V_5 = F_175 ( V_132 , V_12 , V_34 ,
V_144 , V_6 ) ;
if ( V_5 )
break;
V_208:
if ( F_213 ( V_200 ) && V_192 )
F_202 ( V_169 , V_157 ) ;
}
if ( V_5 ) {
V_5 -> V_213 = ! ! ( V_160 & V_203 ) ;
return V_5 ;
}
if ( V_160 & V_201 ) {
V_160 &= ~ V_201 ;
if ( V_197 ) {
V_198 = true ;
F_207 ( V_132 ) ;
}
if ( V_206 > 1 )
V_198 = true ;
}
if ( F_7 ( F_213 ( V_200 ) && V_192 ) ) {
V_192 = 0 ;
V_198 = true ;
}
if ( V_198 )
goto V_199;
return NULL ;
}
static inline bool F_219 ( void )
{
bool V_13 = false ;
#if V_214 > 8
V_13 = F_45 () ;
#endif
return V_13 ;
}
void F_220 ( T_1 V_144 , int V_34 , const char * V_215 , ... )
{
unsigned int V_216 = V_217 ;
if ( ( V_144 & V_218 ) || ! F_221 ( & V_219 ) ||
F_116 () > 0 )
return;
if ( ! ( V_144 & V_220 ) )
if ( F_222 ( V_221 ) ||
( V_30 -> V_66 & ( V_222 | V_223 ) ) )
V_216 &= ~ V_217 ;
if ( F_45 () || ! ( V_144 & V_148 ) )
V_216 &= ~ V_217 ;
if ( V_215 ) {
struct V_224 V_225 ;
T_6 args ;
va_start ( args , V_215 ) ;
V_225 . V_215 = V_215 ;
V_225 . V_226 = & args ;
F_223 ( L_19 , & V_225 ) ;
va_end ( args ) ;
}
F_223 ( L_20 ,
V_30 -> V_31 , V_34 , V_144 ) ;
F_27 () ;
if ( ! F_219 () )
F_224 ( V_216 ) ;
}
static inline int
F_225 ( T_1 V_144 , unsigned int V_34 ,
unsigned long V_227 ,
unsigned long V_228 )
{
if ( V_144 & V_229 )
return 0 ;
if ( V_144 & V_136 )
return 1 ;
if ( ! V_227 && F_5 () )
return 0 ;
if ( V_34 <= V_230 )
return 1 ;
if ( V_144 & V_231 && V_228 < ( 1 << V_34 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_226 ( T_1 V_144 , unsigned int V_34 ,
struct V_169 * V_169 , enum V_232 V_191 ,
T_5 * V_190 , struct V_12 * V_132 ,
int V_159 , int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_227 ( V_169 , V_144 ) ) {
F_228 ( 1 ) ;
return NULL ;
}
F_229 () ;
V_5 = F_211 ( V_144 | V_233 , V_190 ,
V_34 , V_169 , V_191 ,
V_234 | V_177 ,
V_132 , V_159 , V_6 ) ;
if ( V_5 )
goto V_27;
if ( ! ( V_144 & V_136 ) ) {
if ( V_34 > V_230 )
goto V_27;
if ( V_191 < V_235 )
goto V_27;
if ( V_144 & V_236 )
goto V_27;
}
F_230 ( V_169 , V_144 , V_34 , V_190 , false ) ;
V_27:
F_231 ( V_169 , V_144 ) ;
return V_5 ;
}
static struct V_5 *
F_232 ( T_1 V_144 , unsigned int V_34 ,
struct V_169 * V_169 , enum V_232 V_191 ,
T_5 * V_190 , int V_160 , struct V_12 * V_132 ,
int V_159 , int V_6 , enum V_237 V_149 ,
int * V_238 , bool * V_239 )
{
struct V_12 * V_240 = NULL ;
unsigned long V_241 ;
struct V_5 * V_5 ;
if ( ! V_34 )
return NULL ;
V_30 -> V_66 |= V_222 ;
V_241 = F_233 ( V_169 , V_34 , V_144 ,
V_190 , V_149 ,
V_238 ,
& V_240 ) ;
V_30 -> V_66 &= ~ V_222 ;
switch ( V_241 ) {
case V_242 :
* V_239 = true ;
case V_243 :
return NULL ;
default:
break;
}
F_234 ( V_244 ) ;
F_139 ( F_235 () ) ;
F_236 () ;
V_5 = F_211 ( V_144 , V_190 ,
V_34 , V_169 , V_191 ,
V_160 & ~ V_203 ,
V_132 , V_159 , V_6 ) ;
if ( V_5 ) {
struct V_12 * V_12 = F_18 ( V_5 ) ;
V_12 -> V_245 = false ;
F_237 ( V_12 , V_34 , true ) ;
F_234 ( V_246 ) ;
return V_5 ;
}
if ( V_240 && V_149 != V_247 )
F_238 ( V_240 , V_34 ) ;
F_234 ( V_248 ) ;
F_239 () ;
return NULL ;
}
static inline struct V_5 *
F_232 ( T_1 V_144 , unsigned int V_34 ,
struct V_169 * V_169 , enum V_232 V_191 ,
T_5 * V_190 , int V_160 , struct V_12 * V_132 ,
int V_159 , int V_6 , enum V_237 V_149 ,
int * V_238 , bool * V_239 )
{
return NULL ;
}
static int
F_240 ( T_1 V_144 , unsigned int V_34 , struct V_169 * V_169 ,
T_5 * V_190 )
{
struct V_249 V_249 ;
int V_250 ;
F_239 () ;
F_241 () ;
V_30 -> V_66 |= V_222 ;
F_242 ( V_144 ) ;
V_249 . V_251 = 0 ;
V_30 -> V_249 = & V_249 ;
V_250 = F_243 ( V_169 , V_34 , V_144 , V_190 ) ;
V_30 -> V_249 = NULL ;
F_244 () ;
V_30 -> V_66 &= ~ V_222 ;
F_239 () ;
return V_250 ;
}
static inline struct V_5 *
F_245 ( T_1 V_144 , unsigned int V_34 ,
struct V_169 * V_169 , enum V_232 V_191 ,
T_5 * V_190 , int V_160 , struct V_12 * V_132 ,
int V_159 , int V_6 , unsigned long * V_227 )
{
struct V_5 * V_5 = NULL ;
bool V_252 = false ;
* V_227 = F_240 ( V_144 , V_34 , V_169 ,
V_190 ) ;
if ( F_7 ( ! ( * V_227 ) ) )
return NULL ;
if ( F_213 ( V_200 ) )
F_203 ( V_169 ) ;
V_253:
V_5 = F_211 ( V_144 , V_190 , V_34 ,
V_169 , V_191 ,
V_160 & ~ V_203 ,
V_132 , V_159 ,
V_6 ) ;
if ( ! V_5 && ! V_252 ) {
F_144 () ;
V_252 = true ;
goto V_253;
}
return V_5 ;
}
static inline struct V_5 *
F_246 ( T_1 V_144 , unsigned int V_34 ,
struct V_169 * V_169 , enum V_232 V_191 ,
T_5 * V_190 , struct V_12 * V_132 ,
int V_159 , int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_211 ( V_144 , V_190 , V_34 ,
V_169 , V_191 , V_203 ,
V_132 , V_159 , V_6 ) ;
if ( ! V_5 && V_144 & V_136 )
F_247 ( V_132 , V_254 , V_29 / 50 ) ;
} while ( ! V_5 && ( V_144 & V_136 ) );
return V_5 ;
}
static void F_248 ( unsigned int V_34 ,
struct V_169 * V_169 ,
enum V_232 V_191 ,
struct V_12 * V_132 ,
T_5 * V_190 )
{
struct V_181 * V_157 ;
struct V_12 * V_12 ;
F_212 (zone, z, zonelist,
high_zoneidx, nodemask)
F_249 ( V_12 , V_34 , F_250 ( V_132 ) ) ;
}
static inline int
F_251 ( T_1 V_144 )
{
int V_160 = V_211 | V_177 ;
const bool V_255 = ! ( V_144 & ( V_148 | V_256 ) ) ;
F_217 ( V_257 != ( V_258 T_1 ) V_164 ) ;
V_160 |= ( V_258 int ) ( V_144 & V_257 ) ;
if ( V_255 ) {
if ( ! ( V_144 & V_220 ) )
V_160 |= V_165 ;
V_160 &= ~ V_177 ;
} else if ( F_7 ( F_252 ( V_30 ) ) && ! F_45 () )
V_160 |= V_165 ;
if ( F_136 ( ! ( V_144 & V_220 ) ) ) {
if ( V_144 & V_259 )
V_160 |= V_203 ;
else if ( F_253 () && ( V_30 -> V_66 & V_222 ) )
V_160 |= V_203 ;
else if ( ! F_45 () &&
( ( V_30 -> V_66 & V_222 ) ||
F_7 ( F_222 ( V_221 ) ) ) )
V_160 |= V_203 ;
}
#ifdef F_194
if ( F_254 ( V_144 ) == V_128 )
V_160 |= V_166 ;
#endif
return V_160 ;
}
bool F_255 ( T_1 V_144 )
{
return ! ! ( F_251 ( V_144 ) & V_203 ) ;
}
static inline struct V_5 *
F_256 ( T_1 V_144 , unsigned int V_34 ,
struct V_169 * V_169 , enum V_232 V_191 ,
T_5 * V_190 , struct V_12 * V_132 ,
int V_159 , int V_6 )
{
const T_1 V_260 = V_144 & V_148 ;
struct V_5 * V_5 = NULL ;
int V_160 ;
unsigned long V_228 = 0 ;
unsigned long V_227 ;
enum V_237 V_261 = V_247 ;
bool V_239 = false ;
int V_238 = V_262 ;
if ( V_34 >= V_44 ) {
F_176 ( ! ( V_144 & V_218 ) ) ;
return NULL ;
}
if ( F_213 ( V_200 ) &&
( V_144 & V_263 ) == V_263 )
goto V_264;
V_265:
if ( ! ( V_144 & V_256 ) )
F_248 ( V_34 , V_169 , V_191 ,
V_132 , V_190 ) ;
V_160 = F_251 ( V_144 ) ;
if ( ! ( V_160 & V_177 ) && ! V_190 ) {
struct V_181 * V_266 ;
V_266 = F_257 ( V_169 , V_191 ,
NULL , & V_132 ) ;
V_159 = F_258 ( V_266 ) ;
}
V_267:
V_5 = F_211 ( V_144 , V_190 , V_34 , V_169 ,
V_191 , V_160 & ~ V_203 ,
V_132 , V_159 , V_6 ) ;
if ( V_5 )
goto V_268;
if ( V_160 & V_203 ) {
V_169 = F_259 ( F_260 () , V_144 ) ;
V_5 = F_246 ( V_144 , V_34 ,
V_169 , V_191 , V_190 ,
V_132 , V_159 , V_6 ) ;
if ( V_5 ) {
goto V_268;
}
}
if ( ! V_260 ) {
F_176 ( V_144 & V_136 ) ;
goto V_264;
}
if ( V_30 -> V_66 & V_222 )
goto V_264;
if ( F_222 ( V_221 ) && ! ( V_144 & V_136 ) )
goto V_264;
V_5 = F_232 ( V_144 , V_34 , V_169 ,
V_191 , V_190 , V_160 ,
V_132 ,
V_159 , V_6 ,
V_261 , & V_238 ,
& V_239 ) ;
if ( V_5 )
goto V_268;
if ( ( V_144 & V_269 ) == V_269 ) {
if ( V_239 )
goto V_264;
if ( V_238 == V_270 )
goto V_264;
if ( V_238 == V_271
&& ! ( V_30 -> V_66 & V_272 ) )
goto V_264;
}
if ( ( V_144 & V_269 ) != V_269 ||
( V_30 -> V_66 & V_272 ) )
V_261 = V_273 ;
V_5 = F_245 ( V_144 , V_34 ,
V_169 , V_191 ,
V_190 ,
V_160 , V_132 ,
V_159 , V_6 ,
& V_227 ) ;
if ( V_5 )
goto V_268;
if ( ! V_227 ) {
if ( F_261 ( V_144 ) ) {
if ( V_274 )
goto V_264;
if ( ( V_30 -> V_66 & V_275 ) &&
! ( V_144 & V_136 ) )
goto V_264;
V_5 = F_226 ( V_144 , V_34 ,
V_169 , V_191 ,
V_190 , V_132 ,
V_159 , V_6 ) ;
if ( V_5 )
goto V_268;
if ( ! ( V_144 & V_136 ) ) {
if ( V_34 > V_230 )
goto V_264;
if ( V_191 < V_235 )
goto V_264;
}
goto V_265;
}
}
V_228 += V_227 ;
if ( F_225 ( V_144 , V_34 , V_227 ,
V_228 ) ) {
F_247 ( V_132 , V_254 , V_29 / 50 ) ;
goto V_267;
} else {
V_5 = F_232 ( V_144 , V_34 , V_169 ,
V_191 , V_190 , V_160 ,
V_132 ,
V_159 , V_6 ,
V_261 , & V_238 ,
& V_239 ) ;
if ( V_5 )
goto V_268;
}
V_264:
F_220 ( V_144 , V_34 , NULL ) ;
return V_5 ;
V_268:
if ( V_276 )
F_262 ( V_5 , V_34 , V_144 ) ;
return V_5 ;
}
struct V_5 *
F_263 ( T_1 V_144 , unsigned int V_34 ,
struct V_169 * V_169 , T_5 * V_190 )
{
enum V_232 V_191 = F_264 ( V_144 ) ;
struct V_12 * V_132 ;
struct V_181 * V_266 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_254 ( V_144 ) ;
unsigned int V_277 ;
int V_160 = V_195 | V_177 | V_201 ;
int V_159 ;
V_144 &= V_3 ;
F_265 ( V_144 ) ;
F_266 ( V_144 & V_148 ) ;
if ( F_184 ( V_144 , V_34 ) )
return NULL ;
if ( F_7 ( ! V_169 -> V_183 -> V_12 ) )
return NULL ;
if ( F_213 ( F_194 ) && V_6 == V_128 )
V_160 |= V_166 ;
V_278:
V_277 = F_267 () ;
V_266 = F_257 ( V_169 , V_191 ,
V_190 ? : & V_178 ,
& V_132 ) ;
if ( ! V_132 )
goto V_27;
V_159 = F_258 ( V_266 ) ;
V_5 = F_211 ( V_144 | V_233 , V_190 , V_34 ,
V_169 , V_191 , V_160 ,
V_132 , V_159 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
V_144 = F_268 ( V_144 ) ;
V_5 = F_256 ( V_144 , V_34 ,
V_169 , V_191 , V_190 ,
V_132 , V_159 , V_6 ) ;
}
F_269 ( V_5 , V_34 , V_144 , V_6 ) ;
V_27:
if ( F_7 ( ! V_5 && F_270 ( V_277 ) ) )
goto V_278;
return V_5 ;
}
unsigned long F_271 ( T_1 V_144 , unsigned int V_34 )
{
struct V_5 * V_5 ;
F_44 ( ( V_144 & V_41 ) != 0 ) ;
V_5 = F_272 ( V_144 , V_34 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_99 ( V_5 ) ;
}
unsigned long F_273 ( T_1 V_144 )
{
return F_271 ( V_144 | V_93 , 0 ) ;
}
void F_111 ( struct V_5 * V_5 , unsigned int V_34 )
{
if ( F_274 ( V_5 ) ) {
if ( V_34 == 0 )
F_160 ( V_5 , false ) ;
else
F_30 ( V_5 , V_34 ) ;
}
}
void V_161 ( unsigned long V_279 , unsigned int V_34 )
{
if ( V_279 != 0 ) {
F_44 ( ! F_275 ( ( void * ) V_279 ) ) ;
F_111 ( F_169 ( ( void * ) V_279 ) , V_34 ) ;
}
}
struct V_5 * F_276 ( T_1 V_144 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_280 * V_281 = NULL ;
if ( ! F_277 ( V_144 , & V_281 , V_34 ) )
return NULL ;
V_5 = F_272 ( V_144 , V_34 ) ;
F_278 ( V_5 , V_281 , V_34 ) ;
return V_5 ;
}
struct V_5 * F_279 ( int V_282 , T_1 V_144 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_280 * V_281 = NULL ;
if ( ! F_277 ( V_144 , & V_281 , V_34 ) )
return NULL ;
V_5 = F_280 ( V_282 , V_144 , V_34 ) ;
F_278 ( V_5 , V_281 , V_34 ) ;
return V_5 ;
}
void F_281 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_282 ( V_5 , V_34 ) ;
F_111 ( V_5 , V_34 ) ;
}
void F_283 ( unsigned long V_279 , unsigned int V_34 )
{
if ( V_279 != 0 ) {
F_44 ( ! F_275 ( ( void * ) V_279 ) ) ;
F_281 ( F_169 ( ( void * ) V_279 ) , V_34 ) ;
}
}
static void * F_284 ( unsigned long V_279 , unsigned V_34 , T_7 V_92 )
{
if ( V_279 ) {
unsigned long V_283 = V_279 + ( V_82 << V_34 ) ;
unsigned long V_284 = V_279 + F_285 ( V_92 ) ;
F_166 ( F_169 ( ( void * ) V_279 ) , V_34 ) ;
while ( V_284 < V_283 ) {
F_286 ( V_284 ) ;
V_284 += V_82 ;
}
}
return ( void * ) V_279 ;
}
void * F_287 ( T_7 V_92 , T_1 V_144 )
{
unsigned int V_34 = F_288 ( V_92 ) ;
unsigned long V_279 ;
V_279 = F_271 ( V_144 , V_34 ) ;
return F_284 ( V_279 , V_34 , V_92 ) ;
}
void * T_8 F_289 ( int V_282 , T_7 V_92 , T_1 V_144 )
{
unsigned V_34 = F_288 ( V_92 ) ;
struct V_5 * V_37 = F_280 ( V_282 , V_144 , V_34 ) ;
if ( ! V_37 )
return NULL ;
return F_284 ( ( unsigned long ) F_99 ( V_37 ) , V_34 , V_92 ) ;
}
void F_290 ( void * V_285 , T_7 V_92 )
{
unsigned long V_279 = ( unsigned long ) V_285 ;
unsigned long V_286 = V_279 + F_285 ( V_92 ) ;
while ( V_279 < V_286 ) {
F_286 ( V_279 ) ;
V_279 += V_82 ;
}
}
static unsigned long F_291 ( int V_287 )
{
struct V_181 * V_157 ;
struct V_12 * V_12 ;
unsigned long V_288 = 0 ;
struct V_169 * V_169 = F_259 ( F_260 () , V_289 ) ;
F_292 (zone, z, zonelist, offset) {
unsigned long V_92 = V_12 -> V_85 ;
unsigned long V_90 = F_209 ( V_12 ) ;
if ( V_92 > V_90 )
V_288 += V_92 - V_90 ;
}
return V_288 ;
}
unsigned long F_293 ( void )
{
return F_291 ( F_264 ( V_290 ) ) ;
}
unsigned long F_294 ( void )
{
return F_291 ( F_264 ( V_291 ) ) ;
}
static inline void F_295 ( struct V_12 * V_12 )
{
if ( F_213 ( V_200 ) )
F_24 ( L_21 , F_15 ( V_12 ) ) ;
}
void F_296 ( struct V_292 * V_293 )
{
V_293 -> V_294 = V_295 ;
V_293 -> V_296 = F_297 ( V_297 ) ;
V_293 -> V_298 = F_297 ( V_115 ) ;
V_293 -> V_299 = F_298 () ;
V_293 -> V_300 = V_301 ;
V_293 -> V_302 = F_299 () ;
V_293 -> V_303 = V_82 ;
}
void F_300 ( struct V_292 * V_293 , int V_282 )
{
int V_232 ;
unsigned long V_85 = 0 ;
T_9 * V_304 = F_301 ( V_282 ) ;
for ( V_232 = 0 ; V_232 < V_305 ; V_232 ++ )
V_85 += V_304 -> V_189 [ V_232 ] . V_85 ;
V_293 -> V_294 = V_85 ;
V_293 -> V_296 = F_302 ( V_282 , V_297 ) ;
V_293 -> V_298 = F_302 ( V_282 , V_115 ) ;
#ifdef F_303
V_293 -> V_300 = V_304 -> V_189 [ V_306 ] . V_85 ;
V_293 -> V_302 = F_82 ( & V_304 -> V_189 [ V_306 ] ,
V_115 ) ;
#else
V_293 -> V_300 = 0 ;
V_293 -> V_302 = 0 ;
#endif
V_293 -> V_303 = V_82 ;
}
bool F_304 ( unsigned int V_66 , int V_282 )
{
bool V_13 = false ;
unsigned int V_277 ;
if ( ! ( V_66 & V_217 ) )
goto V_27;
do {
V_277 = F_267 () ;
V_13 = ! F_201 ( V_282 , V_178 ) ;
} while ( F_270 ( V_277 ) );
V_27:
return V_13 ;
}
static void F_305 ( unsigned char type )
{
static const char V_307 [ V_308 ] = {
[ V_9 ] = 'U' ,
[ V_106 ] = 'E' ,
[ V_128 ] = 'M' ,
[ V_111 ] = 'R' ,
#ifdef F_194
[ V_87 ] = 'C' ,
#endif
#ifdef F_306
[ V_309 ] = 'I' ,
#endif
} ;
char V_310 [ V_308 + 1 ] ;
char * V_37 = V_310 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_308 ; V_35 ++ ) {
if ( type & ( 1 << V_35 ) )
* V_37 ++ = V_307 [ V_35 ] ;
}
* V_37 = '\0' ;
F_24 ( L_22 , V_310 ) ;
}
void F_307 ( unsigned int V_216 )
{
int V_118 ;
struct V_12 * V_12 ;
F_140 (zone) {
if ( F_304 ( V_216 , F_15 ( V_12 ) ) )
continue;
F_295 ( V_12 ) ;
F_24 ( L_23 , V_12 -> V_20 ) ;
F_145 (cpu) {
struct V_119 * V_121 ;
V_121 = F_141 ( V_12 -> V_121 , V_118 ) ;
F_24 ( L_24 ,
V_118 , V_121 -> V_71 . V_90 ,
V_121 -> V_71 . V_117 , V_121 -> V_71 . V_69 ) ;
}
}
F_24 ( L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
F_297 ( V_311 ) ,
F_297 ( V_312 ) ,
F_297 ( V_313 ) ,
F_297 ( V_314 ) ,
F_297 ( V_315 ) ,
F_297 ( V_316 ) ,
F_297 ( V_317 ) ,
F_297 ( V_318 ) ,
F_297 ( V_319 ) ,
F_297 ( V_320 ) ,
F_297 ( V_115 ) ,
F_297 ( V_321 ) ,
F_297 ( V_322 ) ,
F_297 ( V_323 ) ,
F_297 ( V_297 ) ,
F_297 ( V_324 ) ,
F_297 ( V_325 ) ,
F_297 ( V_114 ) ) ;
F_140 (zone) {
int V_35 ;
if ( F_304 ( V_216 , F_15 ( V_12 ) ) )
continue;
F_295 ( V_12 ) ;
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
F_308 ( F_82 ( V_12 , V_115 ) ) ,
F_308 ( F_309 ( V_12 ) ) ,
F_308 ( F_172 ( V_12 ) ) ,
F_308 ( F_209 ( V_12 ) ) ,
F_308 ( F_82 ( V_12 , V_311 ) ) ,
F_308 ( F_82 ( V_12 , V_312 ) ) ,
F_308 ( F_82 ( V_12 , V_314 ) ) ,
F_308 ( F_82 ( V_12 , V_315 ) ) ,
F_308 ( F_82 ( V_12 , V_317 ) ) ,
F_308 ( F_82 ( V_12 , V_313 ) ) ,
F_308 ( F_82 ( V_12 , V_316 ) ) ,
F_308 ( V_12 -> V_326 ) ,
F_308 ( V_12 -> V_85 ) ,
F_308 ( F_82 ( V_12 , V_327 ) ) ,
F_308 ( F_82 ( V_12 , V_318 ) ) ,
F_308 ( F_82 ( V_12 , V_319 ) ) ,
F_308 ( F_82 ( V_12 , V_323 ) ) ,
F_308 ( F_82 ( V_12 , V_297 ) ) ,
F_308 ( F_82 ( V_12 , V_321 ) ) ,
F_308 ( F_82 ( V_12 , V_322 ) ) ,
F_82 ( V_12 , V_328 ) *
V_329 / 1024 ,
F_308 ( F_82 ( V_12 , V_324 ) ) ,
F_308 ( F_82 ( V_12 , V_320 ) ) ,
F_308 ( F_82 ( V_12 , V_325 ) ) ,
F_308 ( F_82 ( V_12 , V_114 ) ) ,
F_308 ( F_82 ( V_12 , V_330 ) ) ,
F_308 ( F_82 ( V_12 , V_76 ) ) ,
( ! F_310 ( V_12 ) ? L_62 : L_63 )
) ;
F_24 ( L_64 ) ;
for ( V_35 = 0 ; V_35 < V_305 ; V_35 ++ )
F_24 ( L_65 , V_12 -> V_167 [ V_35 ] ) ;
F_24 ( L_61 ) ;
}
F_140 (zone) {
unsigned long V_331 [ V_44 ] , V_66 , V_34 , V_332 = 0 ;
unsigned char V_307 [ V_44 ] ;
if ( F_304 ( V_216 , F_15 ( V_12 ) ) )
continue;
F_295 ( V_12 ) ;
F_24 ( L_66 , V_12 -> V_20 ) ;
F_151 ( & V_12 -> V_75 , V_66 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
struct V_58 * V_91 = & V_12 -> V_58 [ V_34 ] ;
int type ;
V_331 [ V_34 ] = V_91 -> V_59 ;
V_332 += V_331 [ V_34 ] << V_34 ;
V_307 [ V_34 ] = 0 ;
for ( type = 0 ; type < V_308 ; type ++ ) {
if ( ! F_84 ( & V_91 -> V_62 [ type ] ) )
V_307 [ V_34 ] |= 1 << type ;
}
}
F_159 ( & V_12 -> V_75 , V_66 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
F_24 ( L_67 , V_331 [ V_34 ] , F_308 ( 1UL ) << V_34 ) ;
if ( V_331 [ V_34 ] )
F_305 ( V_307 [ V_34 ] ) ;
}
F_24 ( L_68 , F_308 ( V_332 ) ) ;
}
F_311 () ;
F_24 ( L_69 , F_297 ( V_333 ) ) ;
F_312 () ;
}
static void F_313 ( struct V_12 * V_12 , struct V_181 * V_181 )
{
V_181 -> V_12 = V_12 ;
V_181 -> F_250 = F_250 ( V_12 ) ;
}
static int F_314 ( T_9 * V_304 , struct V_169 * V_169 ,
int V_334 )
{
struct V_12 * V_12 ;
enum V_232 V_232 = V_305 ;
do {
V_232 -- ;
V_12 = V_304 -> V_189 + V_232 ;
if ( F_315 ( V_12 ) ) {
F_313 ( V_12 ,
& V_169 -> V_183 [ V_334 ++ ] ) ;
F_316 ( V_232 ) ;
}
} while ( V_232 );
return V_334 ;
}
static int F_317 ( char * V_335 )
{
if ( * V_335 == 'd' || * V_335 == 'D' ) {
V_336 = V_337 ;
} else if ( * V_335 == 'n' || * V_335 == 'N' ) {
V_336 = V_338 ;
} else if ( * V_335 == 'z' || * V_335 == 'Z' ) {
V_336 = V_339 ;
} else {
F_24 ( V_340
L_70
L_71 , V_335 ) ;
return - V_341 ;
}
return 0 ;
}
static T_2 int F_318 ( char * V_335 )
{
int V_13 ;
if ( ! V_335 )
return 0 ;
V_13 = F_317 ( V_335 ) ;
if ( V_13 == 0 )
F_319 ( V_342 , V_335 , V_343 ) ;
return V_13 ;
}
int F_320 ( struct V_344 * V_345 , int V_346 ,
void T_10 * V_347 , T_7 * V_348 ,
T_11 * V_349 )
{
char V_350 [ V_343 ] ;
int V_13 ;
static F_321 ( V_351 ) ;
F_322 ( & V_351 ) ;
if ( V_346 ) {
if ( strlen ( ( char * ) V_345 -> V_352 ) >= V_343 ) {
V_13 = - V_341 ;
goto V_27;
}
strcpy ( V_350 , ( char * ) V_345 -> V_352 ) ;
}
V_13 = F_323 ( V_345 , V_346 , V_347 , V_348 , V_349 ) ;
if ( V_13 )
goto V_27;
if ( V_346 ) {
int V_353 = V_336 ;
V_13 = F_317 ( ( char * ) V_345 -> V_352 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_345 -> V_352 , V_350 ,
V_343 ) ;
V_336 = V_353 ;
} else if ( V_353 != V_336 ) {
F_322 ( & V_354 ) ;
F_324 ( NULL , NULL ) ;
F_325 ( & V_354 ) ;
}
}
V_27:
F_325 ( & V_351 ) ;
return V_13 ;
}
static int F_326 ( int V_186 , T_5 * V_355 )
{
int V_182 , V_293 ;
int V_356 = V_357 ;
int V_358 = V_359 ;
const struct V_360 * V_310 = F_327 ( 0 ) ;
if ( ! F_201 ( V_186 , * V_355 ) ) {
F_328 ( V_186 , * V_355 ) ;
return V_186 ;
}
F_329 (n, N_MEMORY) {
if ( F_201 ( V_182 , * V_355 ) )
continue;
V_293 = F_206 ( V_186 , V_182 ) ;
V_293 += ( V_182 < V_186 ) ;
V_310 = F_327 ( V_182 ) ;
if ( ! F_330 ( V_310 ) )
V_293 += V_361 ;
V_293 *= ( V_362 * V_363 ) ;
V_293 += V_364 [ V_182 ] ;
if ( V_293 < V_356 ) {
V_356 = V_293 ;
V_358 = V_182 ;
}
}
if ( V_358 >= 0 )
F_328 ( V_358 , * V_355 ) ;
return V_358 ;
}
static void F_331 ( T_9 * V_304 , int V_186 )
{
int V_365 ;
struct V_169 * V_169 ;
V_169 = & V_304 -> V_366 [ 0 ] ;
for ( V_365 = 0 ; V_169 -> V_183 [ V_365 ] . V_12 != NULL ; V_365 ++ )
;
V_365 = F_314 ( F_301 ( V_186 ) , V_169 , V_365 ) ;
V_169 -> V_183 [ V_365 ] . V_12 = NULL ;
V_169 -> V_183 [ V_365 ] . F_250 = 0 ;
}
static void F_332 ( T_9 * V_304 )
{
int V_365 ;
struct V_169 * V_169 ;
V_169 = & V_304 -> V_366 [ 1 ] ;
V_365 = F_314 ( V_304 , V_169 , 0 ) ;
V_169 -> V_183 [ V_365 ] . V_12 = NULL ;
V_169 -> V_183 [ V_365 ] . F_250 = 0 ;
}
static void F_333 ( T_9 * V_304 , int V_367 )
{
int V_368 , V_365 , V_186 ;
int V_232 ;
struct V_12 * V_157 ;
struct V_169 * V_169 ;
V_169 = & V_304 -> V_366 [ 0 ] ;
V_368 = 0 ;
for ( V_232 = V_305 - 1 ; V_232 >= 0 ; V_232 -- ) {
for ( V_365 = 0 ; V_365 < V_367 ; V_365 ++ ) {
V_186 = V_369 [ V_365 ] ;
V_157 = & F_301 ( V_186 ) -> V_189 [ V_232 ] ;
if ( F_315 ( V_157 ) ) {
F_313 ( V_157 ,
& V_169 -> V_183 [ V_368 ++ ] ) ;
F_316 ( V_232 ) ;
}
}
}
V_169 -> V_183 [ V_368 ] . V_12 = NULL ;
V_169 -> V_183 [ V_368 ] . F_250 = 0 ;
}
static int F_334 ( void )
{
return V_338 ;
}
static int F_334 ( void )
{
return V_339 ;
}
static void F_335 ( void )
{
if ( V_336 == V_337 )
V_370 = F_334 () ;
else
V_370 = V_336 ;
}
static void F_336 ( T_9 * V_304 )
{
int V_365 , V_186 , V_371 ;
enum V_232 V_35 ;
T_5 V_372 ;
int V_373 , V_374 ;
struct V_169 * V_169 ;
int V_34 = V_370 ;
for ( V_35 = 0 ; V_35 < V_375 ; V_35 ++ ) {
V_169 = V_304 -> V_366 + V_35 ;
V_169 -> V_183 [ 0 ] . V_12 = NULL ;
V_169 -> V_183 [ 0 ] . F_250 = 0 ;
}
V_373 = V_304 -> V_376 ;
V_371 = V_206 ;
V_374 = V_373 ;
F_337 ( V_372 ) ;
memset ( V_369 , 0 , sizeof( V_369 ) ) ;
V_365 = 0 ;
while ( ( V_186 = F_326 ( V_373 , & V_372 ) ) >= 0 ) {
if ( F_206 ( V_373 , V_186 ) !=
F_206 ( V_373 , V_374 ) )
V_364 [ V_186 ] = V_371 ;
V_374 = V_186 ;
V_371 -- ;
if ( V_34 == V_338 )
F_331 ( V_304 , V_186 ) ;
else
V_369 [ V_365 ++ ] = V_186 ;
}
if ( V_34 == V_339 ) {
F_333 ( V_304 , V_365 ) ;
}
F_332 ( V_304 ) ;
}
static void F_338 ( T_9 * V_304 )
{
struct V_169 * V_169 ;
struct V_170 * V_171 ;
struct V_181 * V_157 ;
V_169 = & V_304 -> V_366 [ 0 ] ;
V_169 -> V_173 = V_171 = & V_169 -> V_377 ;
F_199 ( V_171 -> V_175 , V_176 ) ;
for ( V_157 = V_169 -> V_183 ; V_157 -> V_12 ; V_157 ++ )
V_171 -> V_184 [ V_157 - V_169 -> V_183 ] = F_339 ( V_157 ) ;
}
int F_340 ( int V_186 )
{
struct V_12 * V_12 ;
( void ) F_257 ( F_259 ( V_186 , V_289 ) ,
F_264 ( V_289 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_186 ;
}
static void F_335 ( void )
{
V_370 = V_339 ;
}
static void F_336 ( T_9 * V_304 )
{
int V_186 , V_373 ;
enum V_232 V_365 ;
struct V_169 * V_169 ;
V_373 = V_304 -> V_376 ;
V_169 = & V_304 -> V_366 [ 0 ] ;
V_365 = F_314 ( V_304 , V_169 , 0 ) ;
for ( V_186 = V_373 + 1 ; V_186 < V_363 ; V_186 ++ ) {
if ( ! F_341 ( V_186 ) )
continue;
V_365 = F_314 ( F_301 ( V_186 ) , V_169 , V_365 ) ;
}
for ( V_186 = 0 ; V_186 < V_373 ; V_186 ++ ) {
if ( ! F_341 ( V_186 ) )
continue;
V_365 = F_314 ( F_301 ( V_186 ) , V_169 , V_365 ) ;
}
V_169 -> V_183 [ V_365 ] . V_12 = NULL ;
V_169 -> V_183 [ V_365 ] . F_250 = 0 ;
}
static void F_338 ( T_9 * V_304 )
{
V_304 -> V_366 [ 0 ] . V_173 = NULL ;
}
static int F_342 ( void * V_352 )
{
int V_282 ;
int V_118 ;
T_9 * V_378 = V_352 ;
#ifdef V_200
memset ( V_364 , 0 , sizeof( V_364 ) ) ;
#endif
if ( V_378 && ! F_341 ( V_378 -> V_376 ) ) {
F_336 ( V_378 ) ;
F_338 ( V_378 ) ;
}
F_343 (nid) {
T_9 * V_304 = F_301 ( V_282 ) ;
F_336 ( V_304 ) ;
F_338 ( V_304 ) ;
}
F_344 (cpu) {
F_345 ( & F_346 ( V_379 , V_118 ) , 0 ) ;
#ifdef F_347
if ( F_348 ( V_118 ) )
F_349 ( V_118 , F_340 ( F_350 ( V_118 ) ) ) ;
#endif
}
return 0 ;
}
void T_12 F_324 ( T_9 * V_304 , struct V_12 * V_12 )
{
F_335 () ;
if ( V_380 == V_381 ) {
F_342 ( NULL ) ;
F_351 () ;
F_352 () ;
} else {
#ifdef F_353
if ( V_12 )
F_354 ( V_12 ) ;
#endif
F_355 ( F_342 , V_304 , NULL ) ;
}
V_382 = F_294 () ;
if ( V_382 < ( V_86 * V_308 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_24 ( L_72
L_73 ,
V_206 ,
V_383 [ V_370 ] ,
V_7 ? L_74 : L_75 ,
V_382 ) ;
#ifdef V_200
F_24 ( L_76 , V_384 [ V_385 ] ) ;
#endif
}
static inline unsigned long F_356 ( unsigned long V_107 )
{
unsigned long V_92 = 1 ;
V_107 /= V_386 ;
while ( V_92 < V_107 )
V_92 <<= 1 ;
V_92 = F_69 ( V_92 , 4096UL ) ;
return F_357 ( V_92 , 4UL ) ;
}
static inline unsigned long F_356 ( unsigned long V_107 )
{
return 4096UL ;
}
static inline unsigned long F_358 ( unsigned long V_92 )
{
return F_359 ( ~ V_92 ) ;
}
static int F_360 ( unsigned long V_17 , unsigned long V_100 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 ++ ) {
if ( ! F_17 ( V_15 ) || F_361 ( F_127 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_362 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_100 , V_387 ;
struct V_5 * V_5 ;
unsigned long V_388 ;
int V_389 ;
int V_390 ;
V_17 = V_12 -> V_18 ;
V_100 = F_152 ( V_12 ) ;
V_17 = F_363 ( V_17 , V_86 ) ;
V_389 = F_363 ( F_309 ( V_12 ) , V_86 ) >>
V_56 ;
V_389 = F_69 ( 2 , V_389 ) ;
V_390 = V_12 -> V_391 ;
if ( V_389 == V_390 )
return;
V_12 -> V_391 = V_389 ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 += V_86 ) {
if ( ! F_153 ( V_15 ) )
continue;
V_5 = F_127 ( V_15 ) ;
if ( F_124 ( V_5 ) != F_15 ( V_12 ) )
continue;
V_388 = F_88 ( V_5 ) ;
if ( V_389 > 0 ) {
V_387 = F_69 ( V_15 + V_86 , V_100 ) ;
if ( F_360 ( V_15 , V_387 ) )
continue;
if ( V_388 == V_111 ) {
V_389 -- ;
continue;
}
if ( V_388 == V_128 ) {
F_6 ( V_5 ,
V_111 ) ;
F_126 ( V_12 , V_5 ,
V_111 ) ;
V_389 -- ;
continue;
}
} else if ( ! V_390 ) {
break;
}
if ( V_388 == V_111 ) {
F_6 ( V_5 , V_128 ) ;
F_126 ( V_12 , V_5 , V_128 ) ;
}
}
}
void T_8 F_364 ( unsigned long V_92 , int V_282 , unsigned long V_12 ,
unsigned long V_17 , enum V_392 V_393 )
{
struct V_5 * V_5 ;
unsigned long V_100 = V_17 + V_92 ;
unsigned long V_15 ;
struct V_12 * V_157 ;
if ( V_394 < V_100 - 1 )
V_394 = V_100 - 1 ;
V_157 = & F_301 ( V_282 ) -> V_189 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 ++ ) {
if ( V_393 == V_395 ) {
if ( ! F_365 ( V_15 ) )
continue;
if ( ! F_366 ( V_15 , V_282 ) )
continue;
}
V_5 = F_127 ( V_15 ) ;
F_367 ( V_5 , V_12 , V_282 , V_15 ) ;
F_368 ( V_5 , V_12 , V_282 , V_15 ) ;
F_369 ( V_5 ) ;
F_22 ( V_5 ) ;
F_79 ( V_5 ) ;
F_370 ( V_5 ) ;
if ( ( V_157 -> V_18 <= V_15 )
&& ( V_15 < F_152 ( V_157 ) )
&& ! ( V_15 & ( V_86 - 1 ) ) )
F_6 ( V_5 , V_128 ) ;
F_117 ( & V_5 -> V_57 ) ;
#ifdef F_371
if ( ! F_372 ( V_12 ) )
F_373 ( V_5 , F_374 ( V_15 << V_396 ) ) ;
#endif
}
}
static void T_8 F_375 ( struct V_12 * V_12 )
{
unsigned int V_34 , V_126 ;
F_156 (order, t) {
F_117 ( & V_12 -> V_58 [ V_34 ] . V_62 [ V_126 ] ) ;
V_12 -> V_58 [ V_34 ] . V_59 = 0 ;
}
}
static int F_376 ( struct V_12 * V_12 )
{
#ifdef F_377
int V_117 ;
V_117 = V_12 -> V_85 / 1024 ;
if ( V_117 * V_82 > 512 * 1024 )
V_117 = ( 512 * 1024 ) / V_82 ;
V_117 /= 4 ;
if ( V_117 < 1 )
V_117 = 1 ;
V_117 = F_378 ( V_117 + V_117 / 2 ) - 1 ;
return V_117 ;
#else
return 0 ;
#endif
}
static void F_379 ( struct V_70 * V_71 , unsigned long V_90 ,
unsigned long V_117 )
{
V_71 -> V_117 = 1 ;
F_37 () ;
V_71 -> V_90 = V_90 ;
F_37 () ;
V_71 -> V_117 = V_117 ;
}
static void F_380 ( struct V_119 * V_37 , unsigned long V_117 )
{
F_379 ( & V_37 -> V_71 , 6 * V_117 , F_357 ( 1UL , 1 * V_117 ) ) ;
}
static void F_381 ( struct V_119 * V_37 )
{
struct V_70 * V_71 ;
int V_6 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_71 = & V_37 -> V_71 ;
V_71 -> V_69 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_117 ( & V_71 -> V_79 [ V_6 ] ) ;
}
static void F_345 ( struct V_119 * V_37 , unsigned long V_117 )
{
F_381 ( V_37 ) ;
F_380 ( V_37 , V_117 ) ;
}
static void F_382 ( struct V_119 * V_37 ,
unsigned long V_90 )
{
unsigned long V_117 = F_357 ( 1UL , V_90 / 4 ) ;
if ( ( V_90 / 4 ) > ( V_396 * 8 ) )
V_117 = V_396 * 8 ;
F_379 ( & V_37 -> V_71 , V_90 , V_117 ) ;
}
static void F_383 ( struct V_12 * V_12 ,
struct V_119 * V_71 )
{
if ( V_397 )
F_382 ( V_71 ,
( V_12 -> V_85 /
V_397 ) ) ;
else
F_380 ( V_71 , F_376 ( V_12 ) ) ;
}
static void T_8 F_384 ( struct V_12 * V_12 , int V_118 )
{
struct V_119 * V_71 = F_141 ( V_12 -> V_121 , V_118 ) ;
F_381 ( V_71 ) ;
F_383 ( V_12 , V_71 ) ;
}
static void T_8 F_354 ( struct V_12 * V_12 )
{
int V_118 ;
V_12 -> V_121 = F_385 ( struct V_119 ) ;
F_344 (cpu)
F_384 ( V_12 , V_118 ) ;
}
void T_2 F_386 ( void )
{
struct V_12 * V_12 ;
F_140 (zone)
F_354 ( V_12 ) ;
}
static T_13 T_14
int F_387 ( struct V_12 * V_12 , unsigned long V_398 )
{
int V_35 ;
T_7 V_399 ;
V_12 -> F_356 =
F_356 ( V_398 ) ;
V_12 -> F_358 =
F_358 ( V_12 -> F_356 ) ;
V_399 = V_12 -> F_356
* sizeof( V_400 ) ;
if ( ! F_388 () ) {
V_12 -> V_401 = ( V_400 * )
F_389 (
V_399 , V_12 -> V_188 -> V_376 ) ;
} else {
V_12 -> V_401 = F_390 ( V_399 ) ;
}
if ( ! V_12 -> V_401 )
return - V_156 ;
for ( V_35 = 0 ; V_35 < V_12 -> F_356 ; ++ V_35 )
F_391 ( V_12 -> V_401 + V_35 ) ;
return 0 ;
}
static T_8 void F_392 ( struct V_12 * V_12 )
{
V_12 -> V_121 = & V_379 ;
if ( F_315 ( V_12 ) )
F_24 ( V_402 L_77 ,
V_12 -> V_20 , V_12 -> V_326 ,
F_376 ( V_12 ) ) ;
}
int T_8 F_393 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_92 ,
enum V_392 V_393 )
{
struct V_403 * V_304 = V_12 -> V_188 ;
int V_13 ;
V_13 = F_387 ( V_12 , V_92 ) ;
if ( V_13 )
return V_13 ;
V_304 -> V_334 = F_250 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_394 ( V_404 , L_78 ,
L_79 ,
V_304 -> V_376 ,
( unsigned long ) F_250 ( V_12 ) ,
V_18 , ( V_18 + V_92 ) ) ;
F_375 ( V_12 ) ;
return 0 ;
}
int T_8 F_395 ( unsigned long V_15 )
{
unsigned long V_17 , V_100 ;
int V_282 ;
static unsigned long T_15 V_405 , V_406 ;
static int T_15 V_407 ;
if ( V_405 <= V_15 && V_15 < V_406 )
return V_407 ;
V_282 = F_396 ( V_15 , & V_17 , & V_100 ) ;
if ( V_282 != - 1 ) {
V_405 = V_17 ;
V_406 = V_100 ;
V_407 = V_282 ;
}
return V_282 ;
}
int T_8 F_397 ( unsigned long V_15 )
{
int V_282 ;
V_282 = F_395 ( V_15 ) ;
if ( V_282 >= 0 )
return V_282 ;
return 0 ;
}
bool T_8 F_366 ( unsigned long V_15 , int V_186 )
{
int V_282 ;
V_282 = F_395 ( V_15 ) ;
if ( V_282 >= 0 && V_282 != V_186 )
return false ;
return true ;
}
void T_2 F_398 ( int V_282 , unsigned long V_408 )
{
unsigned long V_17 , V_100 ;
int V_35 , V_409 ;
F_399 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = F_69 ( V_17 , V_408 ) ;
V_100 = F_69 ( V_100 , V_408 ) ;
if ( V_17 < V_100 )
F_400 ( F_401 ( V_17 ) ,
( V_100 - V_17 ) << V_396 ,
V_409 ) ;
}
}
void T_2 F_402 ( int V_282 )
{
unsigned long V_17 , V_100 ;
int V_35 , V_409 ;
F_399 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_403 ( V_409 , V_17 , V_100 ) ;
}
void T_8 F_404 ( unsigned int V_282 ,
unsigned long * V_17 , unsigned long * V_100 )
{
unsigned long V_410 , V_411 ;
int V_35 ;
* V_17 = - 1UL ;
* V_100 = 0 ;
F_399 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = F_69 ( * V_17 , V_410 ) ;
* V_100 = F_357 ( * V_100 , V_411 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_405 ( void )
{
int V_412 ;
for ( V_412 = V_305 - 1 ; V_412 >= 0 ; V_412 -- ) {
if ( V_412 == V_413 )
continue;
if ( V_414 [ V_412 ] >
V_415 [ V_412 ] )
break;
}
F_44 ( V_412 == - 1 ) ;
V_416 = V_412 ;
}
static void T_8 F_406 ( int V_282 ,
unsigned long V_232 ,
unsigned long V_417 ,
unsigned long V_418 ,
unsigned long * V_18 ,
unsigned long * F_152 )
{
if ( V_419 [ V_282 ] ) {
if ( V_232 == V_413 ) {
* V_18 = V_419 [ V_282 ] ;
* F_152 = F_69 ( V_418 ,
V_414 [ V_416 ] ) ;
} else if ( * V_18 < V_419 [ V_282 ] &&
* F_152 > V_419 [ V_282 ] ) {
* F_152 = V_419 [ V_282 ] ;
} else if ( * V_18 >= V_419 [ V_282 ] )
* V_18 = * F_152 ;
}
}
static unsigned long T_8 F_407 ( int V_282 ,
unsigned long V_232 ,
unsigned long V_417 ,
unsigned long V_418 ,
unsigned long * V_420 )
{
unsigned long V_18 , F_152 ;
V_18 = V_415 [ V_232 ] ;
F_152 = V_414 [ V_232 ] ;
F_406 ( V_282 , V_232 ,
V_417 , V_418 ,
& V_18 , & F_152 ) ;
if ( F_152 < V_417 || V_18 > V_418 )
return 0 ;
F_152 = F_69 ( F_152 , V_418 ) ;
V_18 = F_357 ( V_18 , V_417 ) ;
return F_152 - V_18 ;
}
unsigned long T_8 F_408 ( int V_282 ,
unsigned long V_421 ,
unsigned long V_422 )
{
unsigned long V_423 = V_422 - V_421 ;
unsigned long V_17 , V_100 ;
int V_35 ;
F_399 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_409 ( V_17 , V_421 , V_422 ) ;
V_100 = F_409 ( V_100 , V_421 , V_422 ) ;
V_423 -= V_100 - V_17 ;
}
return V_423 ;
}
unsigned long T_2 F_410 ( unsigned long V_17 ,
unsigned long V_100 )
{
return F_408 ( V_363 , V_17 , V_100 ) ;
}
static unsigned long T_8 F_411 ( int V_282 ,
unsigned long V_232 ,
unsigned long V_417 ,
unsigned long V_418 ,
unsigned long * V_420 )
{
unsigned long V_424 = V_415 [ V_232 ] ;
unsigned long V_425 = V_414 [ V_232 ] ;
unsigned long V_18 , F_152 ;
V_18 = F_409 ( V_417 , V_424 , V_425 ) ;
F_152 = F_409 ( V_418 , V_424 , V_425 ) ;
F_406 ( V_282 , V_232 ,
V_417 , V_418 ,
& V_18 , & F_152 ) ;
return F_408 ( V_282 , V_18 , F_152 ) ;
}
static inline unsigned long T_8 F_407 ( int V_282 ,
unsigned long V_232 ,
unsigned long V_417 ,
unsigned long V_418 ,
unsigned long * V_426 )
{
return V_426 [ V_232 ] ;
}
static inline unsigned long T_8 F_411 ( int V_282 ,
unsigned long V_232 ,
unsigned long V_417 ,
unsigned long V_418 ,
unsigned long * V_427 )
{
if ( ! V_427 )
return 0 ;
return V_427 [ V_232 ] ;
}
static void T_8 F_412 ( struct V_403 * V_304 ,
unsigned long V_417 ,
unsigned long V_418 ,
unsigned long * V_426 ,
unsigned long * V_427 )
{
unsigned long V_428 , V_429 = 0 ;
enum V_232 V_35 ;
for ( V_35 = 0 ; V_35 < V_305 ; V_35 ++ )
V_429 += F_407 ( V_304 -> V_376 , V_35 ,
V_417 ,
V_418 ,
V_426 ) ;
V_304 -> V_430 = V_429 ;
V_428 = V_429 ;
for ( V_35 = 0 ; V_35 < V_305 ; V_35 ++ )
V_428 -=
F_411 ( V_304 -> V_376 , V_35 ,
V_417 , V_418 ,
V_427 ) ;
V_304 -> V_431 = V_428 ;
F_24 ( V_402 L_80 , V_304 -> V_376 ,
V_428 ) ;
}
static unsigned long T_2 F_413 ( unsigned long V_18 , unsigned long V_432 )
{
unsigned long V_433 ;
V_432 += V_18 & ( V_86 - 1 ) ;
V_433 = F_363 ( V_432 , V_86 ) ;
V_433 = V_433 >> V_56 ;
V_433 *= V_434 ;
V_433 = F_363 ( V_433 , 8 * sizeof( unsigned long ) ) ;
return V_433 / 8 ;
}
static void T_2 F_414 ( struct V_403 * V_304 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_432 )
{
unsigned long V_433 = F_413 ( V_18 , V_432 ) ;
V_12 -> V_435 = NULL ;
if ( V_433 )
V_12 -> V_435 =
F_389 ( V_433 ,
V_304 -> V_376 ) ;
}
static inline void F_414 ( struct V_403 * V_304 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_432 ) {}
void T_16 F_415 ( void )
{
unsigned int V_34 ;
if ( V_56 )
return;
if ( V_436 > V_396 )
V_34 = V_437 ;
else
V_34 = V_44 - 1 ;
V_56 = V_34 ;
}
void T_16 F_415 ( void )
{
}
static unsigned long T_16 F_416 ( unsigned long V_19 ,
unsigned long V_326 )
{
unsigned long V_107 = V_19 ;
if ( V_19 > V_326 + ( V_326 >> 4 ) &&
F_213 ( V_438 ) )
V_107 = V_326 ;
return F_285 ( V_107 * sizeof( struct V_5 ) ) >> V_396 ;
}
static void T_16 F_417 ( struct V_403 * V_304 ,
unsigned long V_417 , unsigned long V_418 ,
unsigned long * V_426 , unsigned long * V_427 )
{
enum V_232 V_365 ;
int V_282 = V_304 -> V_376 ;
unsigned long V_18 = V_304 -> V_417 ;
int V_13 ;
F_418 ( V_304 ) ;
#ifdef F_419
F_420 ( & V_304 -> V_439 ) ;
V_304 -> V_440 = 0 ;
V_304 -> V_441 = V_26 ;
#endif
F_391 ( & V_304 -> V_442 ) ;
F_391 ( & V_304 -> V_443 ) ;
F_421 ( V_304 ) ;
for ( V_365 = 0 ; V_365 < V_305 ; V_365 ++ ) {
struct V_12 * V_12 = V_304 -> V_189 + V_365 ;
unsigned long V_92 , V_444 , V_445 , V_446 ;
V_92 = F_407 ( V_282 , V_365 , V_417 ,
V_418 , V_426 ) ;
V_444 = V_445 = V_92 - F_411 ( V_282 , V_365 ,
V_417 ,
V_418 ,
V_427 ) ;
V_446 = F_416 ( V_92 , V_444 ) ;
if ( V_445 >= V_446 ) {
V_445 -= V_446 ;
if ( V_446 )
F_24 ( V_402
L_81 ,
V_384 [ V_365 ] , V_446 ) ;
} else
F_24 ( V_340
L_82 ,
V_384 [ V_365 ] , V_446 , V_445 ) ;
if ( V_365 == 0 && V_445 > V_447 ) {
V_445 -= V_447 ;
F_24 ( V_402 L_83 ,
V_384 [ 0 ] , V_447 ) ;
}
if ( ! F_372 ( V_365 ) )
V_448 += V_445 ;
else if ( V_448 > V_446 * 2 )
V_448 -= V_446 ;
V_449 += V_445 ;
V_12 -> V_19 = V_92 ;
V_12 -> V_326 = V_444 ;
V_12 -> V_85 = F_372 ( V_365 ) ? V_444 : V_445 ;
#ifdef V_200
V_12 -> V_186 = V_282 ;
V_12 -> V_450 = ( V_445 * V_451 )
/ 100 ;
V_12 -> V_452 = ( V_445 * V_453 ) / 100 ;
#endif
V_12 -> V_20 = V_384 [ V_365 ] ;
F_420 ( & V_12 -> V_75 ) ;
F_420 ( & V_12 -> V_454 ) ;
F_422 ( V_12 ) ;
V_12 -> V_188 = V_304 ;
F_392 ( V_12 ) ;
F_208 ( V_12 , V_137 , V_12 -> V_85 ) ;
F_423 ( & V_12 -> V_455 ) ;
if ( ! V_92 )
continue;
F_415 () ;
F_414 ( V_304 , V_12 , V_18 , V_92 ) ;
V_13 = F_393 ( V_12 , V_18 ,
V_92 , V_395 ) ;
F_171 ( V_13 ) ;
F_424 ( V_92 , V_282 , V_365 , V_18 ) ;
V_18 += V_92 ;
}
}
static void T_14 F_425 ( struct V_403 * V_304 )
{
if ( ! V_304 -> V_430 )
return;
#ifdef F_426
if ( ! V_304 -> V_456 ) {
unsigned long V_92 , V_457 , V_286 ;
struct V_5 * V_458 ;
V_457 = V_304 -> V_417 & ~ ( V_88 - 1 ) ;
V_286 = F_427 ( V_304 ) ;
V_286 = F_428 ( V_286 , V_88 ) ;
V_92 = ( V_286 - V_457 ) * sizeof( struct V_5 ) ;
V_458 = F_429 ( V_304 -> V_376 , V_92 ) ;
if ( ! V_458 )
V_458 = F_389 ( V_92 ,
V_304 -> V_376 ) ;
V_304 -> V_456 = V_458 + ( V_304 -> V_417 - V_457 ) ;
}
#ifndef F_430
if ( V_304 == F_301 ( 0 ) ) {
V_459 = F_301 ( 0 ) -> V_456 ;
#ifdef F_431
if ( F_10 ( V_459 ) != V_304 -> V_417 )
V_459 -= ( V_304 -> V_417 - V_460 ) ;
#endif
}
#endif
#endif
}
void T_16 F_432 ( int V_282 , unsigned long * V_426 ,
unsigned long V_417 , unsigned long * V_427 )
{
T_9 * V_304 = F_301 ( V_282 ) ;
unsigned long V_17 = 0 ;
unsigned long V_100 = 0 ;
F_2 ( V_304 -> V_334 || V_304 -> V_159 ) ;
V_304 -> V_376 = V_282 ;
V_304 -> V_417 = V_417 ;
#ifdef F_431
F_404 ( V_282 , & V_17 , & V_100 ) ;
F_24 ( V_47 L_84 , V_282 ,
( V_461 ) V_17 << V_396 , ( V_461 ) ( V_100 << V_396 ) - 1 ) ;
#endif
F_412 ( V_304 , V_17 , V_100 ,
V_426 , V_427 ) ;
F_425 ( V_304 ) ;
#ifdef F_426
F_24 ( V_402 L_85 ,
V_282 , ( unsigned long ) V_304 ,
( unsigned long ) V_304 -> V_456 ) ;
#endif
F_417 ( V_304 , V_17 , V_100 ,
V_426 , V_427 ) ;
}
void T_2 F_433 ( void )
{
unsigned int V_186 ;
unsigned int V_462 = 0 ;
F_434 (node, node_possible_map)
V_462 = V_186 ;
V_463 = V_462 + 1 ;
}
unsigned long T_2 F_435 ( void )
{
unsigned long V_464 = 0 , V_465 = 0 ;
unsigned long V_457 , V_286 , V_466 ;
int V_407 = - 1 ;
int V_35 , V_282 ;
F_399 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_457 || V_407 < 0 || V_407 == V_282 ) {
V_407 = V_282 ;
V_465 = V_286 ;
continue;
}
V_466 = ~ ( ( 1 << F_436 ( V_457 ) ) - 1 ) ;
while ( V_466 && V_465 <= ( V_457 & ( V_466 << 1 ) ) )
V_466 <<= 1 ;
V_464 |= V_466 ;
}
return ~ V_464 + 1 ;
}
static unsigned long T_2 F_437 ( int V_282 )
{
unsigned long V_467 = V_468 ;
unsigned long V_17 ;
int V_35 ;
F_399 (i, nid, &start_pfn, NULL, NULL)
V_467 = F_69 ( V_467 , V_17 ) ;
if ( V_467 == V_468 ) {
F_24 ( V_340
L_86 , V_282 ) ;
return 0 ;
}
return V_467 ;
}
unsigned long T_2 F_438 ( void )
{
return F_437 ( V_363 ) ;
}
static unsigned long T_2 F_439 ( void )
{
unsigned long V_429 = 0 ;
unsigned long V_17 , V_100 ;
int V_35 , V_282 ;
F_399 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_107 = V_100 - V_17 ;
V_429 += V_107 ;
if ( V_107 )
F_440 ( V_282 , V_180 ) ;
}
return V_429 ;
}
static void T_2 F_441 ( void )
{
int V_35 , V_282 ;
unsigned long V_469 ;
unsigned long V_470 , V_471 ;
T_5 V_472 = V_179 [ V_180 ] ;
unsigned long V_429 = F_439 () ;
int V_473 = F_442 ( V_179 [ V_180 ] ) ;
struct V_474 * V_475 ;
F_405 () ;
if ( F_443 () ) {
F_444 (memory, r) {
if ( ! F_445 ( V_475 ) )
continue;
V_282 = V_475 -> V_282 ;
V_469 = F_446 ( V_475 -> V_476 ) ;
V_419 [ V_282 ] = V_419 [ V_282 ] ?
F_69 ( V_469 , V_419 [ V_282 ] ) :
V_469 ;
}
goto V_477;
}
if ( V_478 ) {
unsigned long V_479 ;
V_478 =
F_363 ( V_478 , V_88 ) ;
V_479 = V_429 - V_478 ;
V_480 = F_357 ( V_480 , V_479 ) ;
}
if ( ! V_480 )
goto V_27;
V_469 = V_415 [ V_416 ] ;
V_265:
V_470 = V_480 / V_473 ;
F_329 (nid, N_MEMORY) {
unsigned long V_17 , V_100 ;
if ( V_480 < V_470 )
V_470 = V_480 / V_473 ;
V_471 = V_470 ;
F_399 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_481 ;
V_17 = F_357 ( V_17 , V_419 [ V_282 ] ) ;
if ( V_17 >= V_100 )
continue;
if ( V_17 < V_469 ) {
unsigned long V_482 ;
V_482 = F_69 ( V_100 , V_469 )
- V_17 ;
V_471 -= F_69 ( V_482 ,
V_471 ) ;
V_480 -= F_69 ( V_482 ,
V_480 ) ;
if ( V_100 <= V_469 ) {
V_419 [ V_282 ] = V_100 ;
continue;
}
V_17 = V_469 ;
}
V_481 = V_100 - V_17 ;
if ( V_481 > V_471 )
V_481 = V_471 ;
V_419 [ V_282 ] = V_17 + V_481 ;
V_480 -= F_69 ( V_480 ,
V_481 ) ;
V_471 -= V_481 ;
if ( ! V_471 )
break;
}
}
V_473 -- ;
if ( V_473 && V_480 > V_473 )
goto V_265;
V_477:
for ( V_282 = 0 ; V_282 < V_363 ; V_282 ++ )
V_419 [ V_282 ] =
F_363 ( V_419 [ V_282 ] , V_88 ) ;
V_27:
V_179 [ V_180 ] = V_472 ;
}
static void F_447 ( T_9 * V_304 , int V_282 )
{
enum V_232 V_232 ;
if ( V_180 == V_483 )
return;
for ( V_232 = 0 ; V_232 <= V_413 - 1 ; V_232 ++ ) {
struct V_12 * V_12 = & V_304 -> V_189 [ V_232 ] ;
if ( F_315 ( V_12 ) ) {
F_440 ( V_282 , V_484 ) ;
if ( V_483 != V_484 &&
V_232 <= V_235 )
F_440 ( V_282 , V_483 ) ;
break;
}
}
}
void T_2 F_448 ( unsigned long * V_125 )
{
unsigned long V_17 , V_100 ;
int V_35 , V_282 ;
memset ( V_415 , 0 ,
sizeof( V_415 ) ) ;
memset ( V_414 , 0 ,
sizeof( V_414 ) ) ;
V_415 [ 0 ] = F_438 () ;
V_414 [ 0 ] = V_125 [ 0 ] ;
for ( V_35 = 1 ; V_35 < V_305 ; V_35 ++ ) {
if ( V_35 == V_413 )
continue;
V_415 [ V_35 ] =
V_414 [ V_35 - 1 ] ;
V_414 [ V_35 ] =
F_357 ( V_125 [ V_35 ] , V_415 [ V_35 ] ) ;
}
V_415 [ V_413 ] = 0 ;
V_414 [ V_413 ] = 0 ;
memset ( V_419 , 0 , sizeof( V_419 ) ) ;
F_441 () ;
F_24 ( L_87 ) ;
for ( V_35 = 0 ; V_35 < V_305 ; V_35 ++ ) {
if ( V_35 == V_413 )
continue;
F_24 ( V_485 L_88 , V_384 [ V_35 ] ) ;
if ( V_415 [ V_35 ] ==
V_414 [ V_35 ] )
F_24 ( V_485 L_89 ) ;
else
F_24 ( V_485 L_90 ,
V_415 [ V_35 ] << V_396 ,
( V_414 [ V_35 ]
<< V_396 ) - 1 ) ;
}
F_24 ( L_91 ) ;
for ( V_35 = 0 ; V_35 < V_363 ; V_35 ++ ) {
if ( V_419 [ V_35 ] )
F_24 ( L_92 , V_35 ,
V_419 [ V_35 ] << V_396 ) ;
}
F_24 ( L_93 ) ;
F_399 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_24 ( L_94 , V_282 ,
V_17 << V_396 , ( V_100 << V_396 ) - 1 ) ;
F_449 () ;
F_433 () ;
F_343 (nid) {
T_9 * V_304 = F_301 ( V_282 ) ;
F_432 ( V_282 , NULL ,
F_437 ( V_282 ) , NULL ) ;
if ( V_304 -> V_431 )
F_440 ( V_282 , V_180 ) ;
F_447 ( V_304 , V_282 ) ;
}
}
static int T_2 F_450 ( char * V_37 , unsigned long * V_486 )
{
unsigned long long V_487 ;
if ( ! V_37 )
return - V_341 ;
V_487 = F_451 ( V_37 , & V_37 ) ;
* V_486 = V_487 >> V_396 ;
F_2 ( ( V_487 >> V_396 ) > V_468 ) ;
return 0 ;
}
static int T_2 F_452 ( char * V_37 )
{
return F_450 ( V_37 , & V_480 ) ;
}
static int T_2 F_453 ( char * V_37 )
{
return F_450 ( V_37 , & V_478 ) ;
}
void F_113 ( struct V_5 * V_5 , long V_69 )
{
F_81 ( & V_488 ) ;
F_18 ( V_5 ) -> V_85 += V_69 ;
V_295 += V_69 ;
#ifdef F_303
if ( F_97 ( V_5 ) )
V_301 += V_69 ;
#endif
F_90 ( & V_488 ) ;
}
unsigned long F_454 ( void * V_457 , void * V_286 , int V_489 , char * V_335 )
{
void * V_368 ;
unsigned long V_107 = 0 ;
V_457 = ( void * ) F_285 ( ( unsigned long ) V_457 ) ;
V_286 = ( void * ) ( ( unsigned long ) V_286 & V_490 ) ;
for ( V_368 = V_457 ; V_368 < V_286 ; V_368 += V_82 , V_107 ++ ) {
if ( ( unsigned int ) V_489 <= 0xFF )
memset ( V_368 , V_489 , V_82 ) ;
F_455 ( F_169 ( V_368 ) ) ;
}
if ( V_107 && V_335 )
F_456 ( L_95 ,
V_335 , V_107 << ( V_396 - 10 ) , V_457 , V_286 ) ;
return V_107 ;
}
void F_457 ( struct V_5 * V_5 )
{
F_458 ( V_5 ) ;
V_295 ++ ;
F_18 ( V_5 ) -> V_85 ++ ;
V_301 ++ ;
}
void T_2 F_459 ( const char * V_141 )
{
unsigned long V_491 , V_492 , V_493 , V_494 , V_495 ;
unsigned long V_496 , V_497 ;
V_491 = F_460 () ;
V_492 = V_498 - V_499 ;
V_493 = V_500 - V_501 ;
V_494 = V_502 - V_503 ;
V_495 = V_504 - V_505 ;
V_497 = V_506 - V_507 ;
V_496 = V_508 - V_509 ;
#define F_461 ( V_457 , V_286 , V_92 , V_368 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_461 ( V_507 , V_506 , V_497 ,
V_509 , V_496 ) ;
F_461 ( V_499 , V_498 , V_492 , V_509 , V_496 ) ;
F_461 ( V_501 , V_500 , V_493 , V_507 , V_497 ) ;
F_461 ( V_499 , V_498 , V_492 , V_503 , V_494 ) ;
F_461 ( V_501 , V_500 , V_493 , V_503 , V_494 ) ;
#undef F_461
F_24 ( L_96
L_97
L_98
#ifdef F_303
L_99
#endif
L_100 ,
F_462 () << ( V_396 - 10 ) , V_491 << ( V_396 - 10 ) ,
V_492 >> 10 , V_493 >> 10 , V_494 >> 10 ,
( V_497 + V_496 ) >> 10 , V_495 >> 10 ,
( V_491 - V_295 ) << ( V_396 - 10 ) ,
#ifdef F_303
V_301 << ( V_396 - 10 ) ,
#endif
V_141 ? L_101 : L_102 , V_141 ? V_141 : L_102 ) ;
}
void T_2 F_463 ( unsigned long V_510 )
{
V_447 = V_510 ;
}
void T_2 F_464 ( unsigned long * V_426 )
{
F_432 ( 0 , V_426 ,
F_465 ( V_511 ) >> V_396 , NULL ) ;
}
static int F_466 ( struct V_512 * V_378 ,
unsigned long V_513 , void * V_514 )
{
int V_118 = ( unsigned long ) V_514 ;
if ( V_513 == V_515 || V_513 == V_516 ) {
F_467 ( V_118 ) ;
F_139 ( V_118 ) ;
F_468 ( V_118 ) ;
F_469 ( V_118 ) ;
}
return V_517 ;
}
void T_2 F_470 ( void )
{
F_471 ( F_466 , 0 ) ;
}
static void F_472 ( void )
{
struct V_403 * V_304 ;
unsigned long V_518 = 0 ;
enum V_232 V_35 , V_365 ;
F_473 (pgdat) {
for ( V_35 = 0 ; V_35 < V_305 ; V_35 ++ ) {
struct V_12 * V_12 = V_304 -> V_189 + V_35 ;
long F_357 = 0 ;
for ( V_365 = V_35 ; V_365 < V_305 ; V_365 ++ ) {
if ( V_12 -> V_167 [ V_365 ] > F_357 )
F_357 = V_12 -> V_167 [ V_365 ] ;
}
F_357 += F_209 ( V_12 ) ;
if ( F_357 > V_12 -> V_85 )
F_357 = V_12 -> V_85 ;
V_518 += F_357 ;
V_12 -> V_519 = F_357 ;
}
}
V_519 = V_518 ;
V_520 = V_518 ;
}
static void F_474 ( void )
{
struct V_403 * V_304 ;
enum V_232 V_365 , V_521 ;
F_473 (pgdat) {
for ( V_365 = 0 ; V_365 < V_305 ; V_365 ++ ) {
struct V_12 * V_12 = V_304 -> V_189 + V_365 ;
unsigned long V_85 = V_12 -> V_85 ;
V_12 -> V_167 [ V_365 ] = 0 ;
V_521 = V_365 ;
while ( V_521 ) {
struct V_12 * V_522 ;
V_521 -- ;
if ( V_523 [ V_521 ] < 1 )
V_523 [ V_521 ] = 1 ;
V_522 = V_304 -> V_189 + V_521 ;
V_522 -> V_167 [ V_365 ] = V_85 /
V_523 [ V_521 ] ;
V_85 += V_522 -> V_85 ;
}
}
}
F_472 () ;
}
static void F_475 ( void )
{
unsigned long V_524 = V_525 >> ( V_396 - 10 ) ;
unsigned long V_526 = 0 ;
struct V_12 * V_12 ;
unsigned long V_66 ;
F_476 (zone) {
if ( ! F_477 ( V_12 ) )
V_526 += V_12 -> V_85 ;
}
F_476 (zone) {
V_461 V_310 ;
F_151 ( & V_12 -> V_75 , V_66 ) ;
V_310 = ( V_461 ) V_524 * V_12 -> V_85 ;
F_478 ( V_310 , V_526 ) ;
if ( F_477 ( V_12 ) ) {
unsigned long V_527 ;
V_527 = V_12 -> V_85 / 1024 ;
V_527 = F_409 ( V_527 , V_528 , 128UL ) ;
V_12 -> V_130 [ V_529 ] = V_527 ;
} else {
V_12 -> V_130 [ V_529 ] = V_310 ;
}
V_12 -> V_130 [ V_530 ] = F_309 ( V_12 ) + ( V_310 >> 2 ) ;
V_12 -> V_130 [ V_531 ] = F_309 ( V_12 ) + ( V_310 >> 1 ) ;
F_83 ( V_12 , V_137 ,
F_209 ( V_12 ) - F_172 ( V_12 ) -
F_177 ( & V_12 -> V_138 [ V_137 ] ) ) ;
F_362 ( V_12 ) ;
F_159 ( & V_12 -> V_75 , V_66 ) ;
}
F_472 () ;
}
void F_479 ( void )
{
F_322 ( & V_354 ) ;
F_475 () ;
F_325 ( & V_354 ) ;
}
static void T_8 F_480 ( struct V_12 * V_12 )
{
unsigned int V_532 , V_533 ;
V_532 = V_12 -> V_85 >> ( 30 - V_396 ) ;
if ( V_532 )
V_533 = F_481 ( 10 * V_532 ) ;
else
V_533 = 1 ;
V_12 -> V_534 = V_533 ;
}
static void T_8 F_482 ( void )
{
struct V_12 * V_12 ;
F_476 (zone)
F_480 ( V_12 ) ;
}
int T_8 F_483 ( void )
{
unsigned long V_535 ;
int V_536 ;
V_535 = F_293 () * ( V_82 >> 10 ) ;
V_536 = F_481 ( V_535 * 16 ) ;
if ( V_536 > V_537 ) {
V_525 = V_536 ;
if ( V_525 < 128 )
V_525 = 128 ;
if ( V_525 > 65536 )
V_525 = 65536 ;
} else {
F_223 ( L_103 ,
V_536 , V_537 ) ;
}
F_479 () ;
F_484 () ;
F_474 () ;
F_482 () ;
return 0 ;
}
int F_485 ( struct V_344 * V_345 , int V_346 ,
void T_10 * V_347 , T_7 * V_348 , T_11 * V_349 )
{
int V_538 ;
V_538 = F_486 ( V_345 , V_346 , V_347 , V_348 , V_349 ) ;
if ( V_538 )
return V_538 ;
if ( V_346 ) {
V_537 = V_525 ;
F_479 () ;
}
return 0 ;
}
int F_487 ( struct V_344 * V_345 , int V_346 ,
void T_10 * V_347 , T_7 * V_348 , T_11 * V_349 )
{
struct V_12 * V_12 ;
int V_538 ;
V_538 = F_486 ( V_345 , V_346 , V_347 , V_348 , V_349 ) ;
if ( V_538 )
return V_538 ;
F_476 (zone)
V_12 -> V_450 = ( V_12 -> V_85 *
V_451 ) / 100 ;
return 0 ;
}
int F_488 ( struct V_344 * V_345 , int V_346 ,
void T_10 * V_347 , T_7 * V_348 , T_11 * V_349 )
{
struct V_12 * V_12 ;
int V_538 ;
V_538 = F_486 ( V_345 , V_346 , V_347 , V_348 , V_349 ) ;
if ( V_538 )
return V_538 ;
F_476 (zone)
V_12 -> V_452 = ( V_12 -> V_85 *
V_453 ) / 100 ;
return 0 ;
}
int F_489 ( struct V_344 * V_345 , int V_346 ,
void T_10 * V_347 , T_7 * V_348 , T_11 * V_349 )
{
F_486 ( V_345 , V_346 , V_347 , V_348 , V_349 ) ;
F_474 () ;
return 0 ;
}
int F_490 ( struct V_344 * V_345 , int V_346 ,
void T_10 * V_347 , T_7 * V_348 , T_11 * V_349 )
{
struct V_12 * V_12 ;
int V_539 ;
int V_13 ;
F_322 ( & V_540 ) ;
V_539 = V_397 ;
V_13 = F_486 ( V_345 , V_346 , V_347 , V_348 , V_349 ) ;
if ( ! V_346 || V_13 < 0 )
goto V_27;
if ( V_397 &&
V_397 < V_541 ) {
V_397 = V_539 ;
V_13 = - V_341 ;
goto V_27;
}
if ( V_397 == V_539 )
goto V_27;
F_140 (zone) {
unsigned int V_118 ;
F_344 (cpu)
F_383 ( V_12 ,
F_141 ( V_12 -> V_121 , V_118 ) ) ;
}
V_27:
F_325 ( & V_540 ) ;
return V_13 ;
}
static int T_2 F_491 ( char * V_141 )
{
if ( ! V_141 )
return 0 ;
V_542 = F_492 ( V_141 , & V_141 , 0 ) ;
return 1 ;
}
void * T_2 F_493 ( const char * V_543 ,
unsigned long V_544 ,
unsigned long V_545 ,
int V_546 ,
int V_66 ,
unsigned int * V_547 ,
unsigned int * V_548 ,
unsigned long V_549 ,
unsigned long V_550 )
{
unsigned long long F_357 = V_550 ;
unsigned long V_551 , V_92 ;
void * V_345 = NULL ;
if ( ! V_545 ) {
V_545 = V_448 ;
if ( V_396 < 20 )
V_545 = F_494 ( V_545 , ( 1 << 20 ) / V_82 ) ;
if ( V_546 > V_396 )
V_545 >>= ( V_546 - V_396 ) ;
else
V_545 <<= ( V_396 - V_546 ) ;
if ( F_7 ( V_66 & V_552 ) ) {
F_2 ( ! ( V_66 & V_553 ) ) ;
if ( ! ( V_545 >> * V_547 ) ) {
V_545 = 1UL << * V_547 ;
F_171 ( ! V_545 ) ;
}
} else if ( F_7 ( ( V_545 * V_544 ) < V_82 ) )
V_545 = V_82 / V_544 ;
}
V_545 = F_495 ( V_545 ) ;
if ( F_357 == 0 ) {
F_357 = ( ( unsigned long long ) V_449 << V_396 ) >> 4 ;
F_478 ( F_357 , V_544 ) ;
}
F_357 = F_69 ( F_357 , 0x80000000ULL ) ;
if ( V_545 < V_549 )
V_545 = V_549 ;
if ( V_545 > F_357 )
V_545 = F_357 ;
V_551 = F_496 ( V_545 ) ;
do {
V_92 = V_544 << V_551 ;
if ( V_66 & V_553 )
V_345 = F_497 ( V_92 , 0 ) ;
else if ( V_542 )
V_345 = F_498 ( V_92 , V_554 , V_555 ) ;
else {
if ( F_288 ( V_92 ) < V_44 ) {
V_345 = F_287 ( V_92 , V_554 ) ;
F_499 ( V_345 , V_92 , 1 , V_554 ) ;
}
}
} while ( ! V_345 && V_92 > V_82 && -- V_551 );
if ( ! V_345 )
F_500 ( L_104 , V_543 ) ;
F_24 ( V_47 L_105 ,
V_543 ,
( 1UL << V_551 ) ,
F_496 ( V_92 ) - V_396 ,
V_92 ) ;
if ( V_547 )
* V_547 = V_551 ;
if ( V_548 )
* V_548 = ( 1 << V_551 ) - 1 ;
return V_345 ;
}
static inline unsigned long * F_501 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_438
return F_502 ( V_15 ) -> V_435 ;
#else
return V_12 -> V_435 ;
#endif
}
static inline int F_503 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_438
V_15 &= ( V_556 - 1 ) ;
return ( V_15 >> V_56 ) * V_434 ;
#else
V_15 = V_15 - F_504 ( V_12 -> V_18 , V_86 ) ;
return ( V_15 >> V_56 ) * V_434 ;
#endif
}
unsigned long F_505 ( struct V_5 * V_5 , unsigned long V_15 ,
unsigned long V_557 ,
unsigned long V_466 )
{
struct V_12 * V_12 ;
unsigned long * V_558 ;
unsigned long V_559 , V_560 ;
unsigned long V_561 ;
V_12 = F_18 ( V_5 ) ;
V_558 = F_501 ( V_12 , V_15 ) ;
V_559 = F_503 ( V_12 , V_15 ) ;
V_560 = V_559 / V_562 ;
V_559 &= ( V_562 - 1 ) ;
V_561 = V_558 [ V_560 ] ;
V_559 += V_557 ;
return ( V_561 >> ( V_562 - V_559 - 1 ) ) & V_466 ;
}
void F_506 ( struct V_5 * V_5 , unsigned long V_66 ,
unsigned long V_15 ,
unsigned long V_557 ,
unsigned long V_466 )
{
struct V_12 * V_12 ;
unsigned long * V_558 ;
unsigned long V_559 , V_560 ;
unsigned long V_563 , V_561 ;
F_217 ( V_434 != 4 ) ;
V_12 = F_18 ( V_5 ) ;
V_558 = F_501 ( V_12 , V_15 ) ;
V_559 = F_503 ( V_12 , V_15 ) ;
V_560 = V_559 / V_562 ;
V_559 &= ( V_562 - 1 ) ;
F_61 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
V_559 += V_557 ;
V_466 <<= ( V_562 - V_559 - 1 ) ;
V_66 <<= ( V_562 - V_559 - 1 ) ;
V_561 = F_138 ( V_558 [ V_560 ] ) ;
for (; ; ) {
V_563 = F_507 ( & V_558 [ V_560 ] , V_561 , ( V_561 & ~ V_466 ) | V_66 ) ;
if ( V_561 == V_563 )
break;
V_561 = V_563 ;
}
}
bool F_508 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_69 ,
bool V_564 )
{
unsigned long V_15 , V_565 , V_566 ;
int V_80 ;
if ( F_250 ( V_12 ) == V_413 )
return false ;
V_80 = F_88 ( V_5 ) ;
if ( V_80 == V_128 || F_130 ( V_80 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_566 = 0 , V_565 = 0 ; V_565 < V_86 ; V_565 ++ ) {
unsigned long V_567 = V_15 + V_565 ;
if ( ! F_17 ( V_567 ) )
continue;
V_5 = F_127 ( V_567 ) ;
if ( F_509 ( V_5 ) ) {
V_565 = F_494 ( V_565 + 1 , 1 << F_31 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_77 ( & V_5 -> V_65 ) ) {
if ( F_64 ( V_5 ) )
V_565 += ( 1 << F_60 ( V_5 ) ) - 1 ;
continue;
}
if ( V_564 && F_21 ( V_5 ) )
continue;
if ( ! F_510 ( V_5 ) )
V_566 ++ ;
if ( V_566 > V_69 )
return true ;
}
return false ;
}
bool F_511 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_341 ( F_124 ( V_5 ) ) )
return false ;
V_12 = F_18 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_508 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_512 ( unsigned long V_15 )
{
return V_15 & ~ ( F_513 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_514 ( unsigned long V_15 )
{
return F_428 ( V_15 , F_513 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_515 ( struct V_568 * V_569 ,
unsigned long V_457 , unsigned long V_286 )
{
unsigned long V_570 ;
unsigned long V_15 = V_457 ;
unsigned int V_571 = 0 ;
int V_13 = 0 ;
F_516 () ;
while ( V_15 < V_286 || ! F_84 ( & V_569 -> V_572 ) ) {
if ( F_517 ( V_30 ) ) {
V_13 = - V_573 ;
break;
}
if ( F_84 ( & V_569 -> V_572 ) ) {
V_569 -> V_574 = 0 ;
V_15 = F_518 ( V_569 , V_15 , V_286 ) ;
if ( ! V_15 ) {
V_13 = - V_573 ;
break;
}
V_571 = 0 ;
} else if ( ++ V_571 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_575 ;
break;
}
V_570 = F_519 ( V_569 -> V_12 ,
& V_569 -> V_572 ) ;
V_569 -> V_574 -= V_570 ;
V_13 = F_520 ( & V_569 -> V_572 , V_576 ,
NULL , 0 , V_569 -> V_149 , V_577 ) ;
}
if ( V_13 < 0 ) {
F_521 ( & V_569 -> V_572 ) ;
return V_13 ;
}
return 0 ;
}
int F_522 ( unsigned long V_457 , unsigned long V_286 ,
unsigned V_6 )
{
unsigned long V_578 , V_579 ;
int V_13 = 0 , V_34 ;
struct V_568 V_569 = {
. V_574 = 0 ,
. V_34 = - 1 ,
. V_12 = F_18 ( F_127 ( V_457 ) ) ,
. V_149 = V_580 ,
. V_581 = true ,
} ;
F_117 ( & V_569 . V_572 ) ;
V_13 = F_523 ( F_512 ( V_457 ) ,
F_514 ( V_286 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_515 ( & V_569 , V_457 , V_286 ) ;
if ( V_13 )
goto V_582;
F_524 () ;
F_144 () ;
V_34 = 0 ;
V_578 = V_457 ;
while ( ! F_64 ( F_127 ( V_578 ) ) ) {
if ( ++ V_34 >= V_44 ) {
V_13 = - V_575 ;
goto V_582;
}
V_578 &= ~ 0UL << V_34 ;
}
if ( F_525 ( V_578 , V_286 , false ) ) {
F_456 ( L_106 ,
V_583 , V_578 , V_286 ) ;
V_13 = - V_575 ;
goto V_582;
}
V_579 = F_526 ( & V_569 , V_578 , V_286 ) ;
if ( ! V_579 ) {
V_13 = - V_575 ;
goto V_582;
}
if ( V_457 != V_578 )
F_527 ( V_578 , V_457 - V_578 ) ;
if ( V_286 != V_579 )
F_527 ( V_286 , V_579 - V_286 ) ;
V_582:
F_528 ( F_512 ( V_457 ) ,
F_514 ( V_286 ) , V_6 ) ;
return V_13 ;
}
void F_527 ( unsigned long V_15 , unsigned V_36 )
{
unsigned int V_69 = 0 ;
for (; V_36 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
V_69 += F_62 ( V_5 ) != 1 ;
F_529 ( V_5 ) ;
}
F_530 ( V_69 != 0 , L_107 , V_69 ) ;
}
void T_8 F_531 ( struct V_12 * V_12 )
{
unsigned V_118 ;
F_322 ( & V_540 ) ;
F_344 (cpu)
F_383 ( V_12 ,
F_141 ( V_12 -> V_121 , V_118 ) ) ;
F_325 ( & V_540 ) ;
}
void F_532 ( struct V_12 * V_12 )
{
unsigned long V_66 ;
int V_118 ;
struct V_119 * V_120 ;
F_103 ( V_66 ) ;
if ( V_12 -> V_121 != & V_379 ) {
F_145 (cpu) {
V_120 = F_141 ( V_12 -> V_121 , V_118 ) ;
F_533 ( V_12 , V_120 ) ;
}
F_534 ( V_12 -> V_121 ) ;
V_12 -> V_121 = & V_379 ;
}
F_106 ( V_66 ) ;
}
void
F_535 ( unsigned long V_17 , unsigned long V_100 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
unsigned int V_34 , V_35 ;
unsigned long V_15 ;
unsigned long V_66 ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 ++ )
if ( F_153 ( V_15 ) )
break;
if ( V_15 == V_100 )
return;
V_12 = F_18 ( F_127 ( V_15 ) ) ;
F_151 ( & V_12 -> V_75 , V_66 ) ;
V_15 = V_17 ;
while ( V_15 < V_100 ) {
if ( ! F_153 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_127 ( V_15 ) ;
if ( F_7 ( ! F_64 ( V_5 ) && F_21 ( V_5 ) ) ) {
V_15 ++ ;
F_370 ( V_5 ) ;
continue;
}
F_171 ( F_62 ( V_5 ) ) ;
F_171 ( ! F_64 ( V_5 ) ) ;
V_34 = F_60 ( V_5 ) ;
#ifdef F_536
F_24 ( V_47 L_108 ,
V_15 , 1 << V_34 , V_100 ) ;
#endif
F_72 ( & V_5 -> V_57 ) ;
F_56 ( V_5 ) ;
V_12 -> V_58 [ V_34 ] . V_59 -- ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_370 ( ( V_5 + V_35 ) ) ;
V_15 += ( 1 << V_34 ) ;
}
F_159 ( & V_12 -> V_75 , V_66 ) ;
}
bool F_537 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_66 ;
unsigned int V_34 ;
F_151 ( & V_12 -> V_75 , V_66 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
struct V_5 * V_584 = V_5 - ( V_15 & ( ( 1 << V_34 ) - 1 ) ) ;
if ( F_64 ( V_584 ) && F_60 ( V_584 ) >= V_34 )
break;
}
F_159 ( & V_12 -> V_75 , V_66 ) ;
return V_34 < V_44 ;
}
