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
F_79 ( & V_12 -> V_72 ) ;
V_12 -> V_73 = 0 ;
while ( V_71 ) {
struct V_5 * V_5 ;
struct V_74 * V_75 ;
do {
V_70 ++ ;
if ( ++ V_6 == V_8 )
V_6 = 0 ;
V_75 = & V_69 -> V_76 [ V_6 ] ;
} while ( F_80 ( V_75 ) );
if ( V_70 == V_8 )
V_70 = V_71 ;
do {
int V_77 ;
V_5 = F_81 ( V_75 -> V_78 , struct V_5 , V_55 ) ;
F_70 ( & V_5 -> V_55 ) ;
V_77 = F_82 ( V_5 ) ;
F_66 ( V_5 , F_10 ( V_5 ) , V_12 , 0 , V_77 ) ;
F_83 ( V_5 , 0 , V_77 ) ;
if ( F_84 ( ! F_85 ( V_5 ) ) ) {
F_86 ( V_12 , V_79 , 1 ) ;
if ( F_87 ( V_77 ) )
F_86 ( V_12 , V_80 , 1 ) ;
}
} while ( -- V_71 && -- V_70 && ! F_80 ( V_75 ) );
}
F_88 ( & V_12 -> V_72 ) ;
}
static void F_89 ( struct V_12 * V_12 ,
struct V_5 * V_5 , unsigned long V_15 ,
unsigned int V_34 ,
int V_6 )
{
F_79 ( & V_12 -> V_72 ) ;
V_12 -> V_73 = 0 ;
F_66 ( V_5 , V_15 , V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! F_90 ( V_6 ) ) )
F_69 ( V_12 , 1 << V_34 , V_6 ) ;
F_88 ( & V_12 -> V_72 ) ;
}
static bool F_91 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
int V_39 = 0 ;
F_92 ( V_5 , V_34 ) ;
F_93 ( V_5 , V_34 ) ;
if ( F_94 ( V_5 ) )
V_5 -> V_62 = NULL ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
V_39 += F_73 ( V_5 + V_35 ) ;
if ( V_39 )
return false ;
if ( ! F_95 ( V_5 ) ) {
F_96 ( F_97 ( V_5 ) ,
V_81 << V_34 ) ;
F_98 ( F_97 ( V_5 ) ,
V_81 << V_34 ) ;
}
F_99 ( V_5 , V_34 ) ;
F_100 ( V_5 , 1 << V_34 , 0 ) ;
return true ;
}
static void F_30 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_64 ;
int V_6 ;
unsigned long V_15 = F_10 ( V_5 ) ;
if ( ! F_91 ( V_5 , V_34 ) )
return;
V_6 = F_101 ( V_5 , V_15 ) ;
F_102 ( V_64 ) ;
F_103 ( V_82 , 1 << V_34 ) ;
F_104 ( V_5 , V_6 ) ;
F_89 ( F_18 ( V_5 ) , V_5 , V_15 , V_34 , V_6 ) ;
F_105 ( V_64 ) ;
}
void T_2 F_106 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned int V_36 = 1 << V_34 ;
struct V_5 * V_37 = V_5 ;
unsigned int V_83 ;
F_107 ( V_37 ) ;
for ( V_83 = 0 ; V_83 < ( V_36 - 1 ) ; V_83 ++ , V_37 ++ ) {
F_107 ( V_37 + 1 ) ;
F_108 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
}
F_108 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
F_18 ( V_5 ) -> V_84 += V_36 ;
F_109 ( V_5 ) ;
F_110 ( V_5 , V_34 ) ;
}
void T_2 F_111 ( struct V_5 * V_5 )
{
unsigned V_35 = V_85 ;
struct V_5 * V_37 = V_5 ;
do {
F_108 ( V_37 ) ;
F_36 ( V_37 , 0 ) ;
} while ( ++ V_37 , -- V_35 );
F_6 ( V_5 , V_86 ) ;
if ( V_87 >= V_44 ) {
V_35 = V_85 ;
V_37 = V_5 ;
do {
F_109 ( V_37 ) ;
F_110 ( V_37 , V_44 - 1 ) ;
V_37 += V_88 ;
} while ( V_35 -= V_88 );
} else {
F_109 ( V_5 ) ;
F_110 ( V_5 , V_87 ) ;
}
F_112 ( V_5 , V_85 ) ;
}
static inline void F_113 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_89 , int V_90 , struct V_56 * V_91 ,
int V_6 )
{
unsigned long V_92 = 1 << V_90 ;
while ( V_90 > V_89 ) {
V_91 -- ;
V_90 -- ;
V_92 >>= 1 ;
F_62 ( F_19 ( V_12 , & V_5 [ V_92 ] ) , & V_5 [ V_92 ] ) ;
#ifdef F_114
if ( V_90 < F_115 () ) {
F_116 ( & V_5 [ V_92 ] . V_55 ) ;
F_49 ( & V_5 [ V_92 ] ) ;
F_54 ( & V_5 [ V_92 ] , V_90 ) ;
F_69 ( V_12 , - ( 1 << V_90 ) ,
V_6 ) ;
continue;
}
#endif
F_72 ( & V_5 [ V_92 ] . V_55 , & V_91 -> V_60 [ V_6 ] ) ;
V_91 -> V_57 ++ ;
F_53 ( & V_5 [ V_92 ] , V_90 ) ;
}
}
static inline int F_117 ( struct V_5 * V_5 )
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
static int F_118 ( struct V_5 * V_5 , unsigned int V_34 , T_1 V_40 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ ) {
struct V_5 * V_37 = V_5 + V_35 ;
if ( F_7 ( F_117 ( V_37 ) ) )
return 1 ;
}
F_54 ( V_5 , 0 ) ;
F_109 ( V_5 ) ;
F_119 ( V_5 , V_34 ) ;
F_100 ( V_5 , 1 << V_34 , 1 ) ;
if ( V_40 & V_93 )
F_43 ( V_5 , V_34 , V_40 ) ;
if ( V_34 && ( V_40 & V_94 ) )
F_32 ( V_5 , V_34 ) ;
return 0 ;
}
static inline
struct V_5 * F_120 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
unsigned int V_95 ;
struct V_56 * V_91 ;
struct V_5 * V_5 ;
for ( V_95 = V_34 ; V_95 < V_44 ; ++ V_95 ) {
V_91 = & ( V_12 -> V_56 [ V_95 ] ) ;
if ( F_80 ( & V_91 -> V_60 [ V_6 ] ) )
continue;
V_5 = F_81 ( V_91 -> V_60 [ V_6 ] . V_96 ,
struct V_5 , V_55 ) ;
F_70 ( & V_5 -> V_55 ) ;
F_56 ( V_5 ) ;
V_91 -> V_57 -- ;
F_113 ( V_12 , V_5 , V_34 , V_95 , V_91 , V_6 ) ;
F_104 ( V_5 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
int F_121 ( struct V_12 * V_12 ,
struct V_5 * V_97 , struct V_5 * V_98 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_34 ;
int V_99 = 0 ;
#ifndef F_122
F_123 ( F_18 ( V_97 ) != F_18 ( V_98 ) ) ;
#endif
for ( V_5 = V_97 ; V_5 <= V_98 ; ) {
F_62 ( F_124 ( V_5 ) != F_15 ( V_12 ) , V_5 ) ;
if ( ! F_17 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_65 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_34 = F_61 ( V_5 ) ;
F_125 ( & V_5 -> V_55 ,
& V_12 -> V_56 [ V_34 ] . V_60 [ V_6 ] ) ;
F_104 ( V_5 , V_6 ) ;
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
V_17 = V_17 & ~ ( V_85 - 1 ) ;
V_97 = F_127 ( V_17 ) ;
V_98 = V_97 + V_85 - 1 ;
V_100 = V_17 + V_85 - 1 ;
if ( ! F_12 ( V_12 , V_17 ) )
V_97 = V_5 ;
if ( ! F_12 ( V_12 , V_100 ) )
return 0 ;
return F_121 ( V_12 , V_97 , V_98 , V_6 ) ;
}
static void F_128 ( struct V_5 * V_101 ,
int V_102 , int V_6 )
{
int V_103 = 1 << ( V_102 - V_87 ) ;
while ( V_103 -- ) {
F_6 ( V_101 , V_6 ) ;
V_101 += V_85 ;
}
}
static int F_129 ( struct V_12 * V_12 , struct V_5 * V_5 ,
int V_104 , int V_105 )
{
int V_95 = F_61 ( V_5 ) ;
if ( F_87 ( V_105 ) )
return V_105 ;
if ( V_95 >= V_87 ) {
F_128 ( V_5 , V_95 , V_104 ) ;
return V_104 ;
}
if ( V_95 >= V_87 / 2 ||
V_104 == V_106 ||
V_7 ) {
int V_107 ;
V_107 = F_126 ( V_12 , V_5 , V_104 ) ;
if ( V_107 >= ( 1 << ( V_87 - 1 ) ) ||
V_7 ) {
F_6 ( V_5 , V_104 ) ;
return V_104 ;
}
}
return V_105 ;
}
static inline struct V_5 *
F_130 ( struct V_12 * V_12 , unsigned int V_34 , int V_108 )
{
struct V_56 * V_91 ;
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
V_91 = & ( V_12 -> V_56 [ V_95 ] ) ;
if ( F_80 ( & V_91 -> V_60 [ V_6 ] ) )
continue;
V_5 = F_81 ( V_91 -> V_60 [ V_6 ] . V_96 ,
struct V_5 , V_55 ) ;
V_91 -> V_57 -- ;
V_109 = F_129 ( V_12 , V_5 ,
V_108 ,
V_6 ) ;
F_70 ( & V_5 -> V_55 ) ;
F_56 ( V_5 ) ;
F_113 ( V_12 , V_5 , V_34 , V_95 , V_91 ,
V_109 ) ;
F_104 ( V_5 , V_109 ) ;
F_131 ( V_5 , V_34 , V_95 ,
V_108 , V_6 , V_109 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_132 ( struct V_12 * V_12 , unsigned int V_34 ,
int V_6 )
{
struct V_5 * V_5 ;
V_112:
V_5 = F_120 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_111 ) {
V_5 = F_130 ( V_12 , V_34 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_111 ;
goto V_112;
}
}
F_133 ( V_5 , V_34 , V_6 ) ;
return V_5 ;
}
static int F_134 ( struct V_12 * V_12 , unsigned int V_34 ,
unsigned long V_67 , struct V_74 * V_75 ,
int V_6 , bool V_113 )
{
int V_35 ;
F_79 ( & V_12 -> V_72 ) ;
for ( V_35 = 0 ; V_35 < V_67 ; ++ V_35 ) {
struct V_5 * V_5 = F_132 ( V_12 , V_34 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_84 ( ! V_113 ) )
F_72 ( & V_5 -> V_55 , V_75 ) ;
else
F_71 ( & V_5 -> V_55 , V_75 ) ;
V_75 = & V_5 -> V_55 ;
if ( F_87 ( F_82 ( V_5 ) ) )
F_86 ( V_12 , V_80 ,
- ( 1 << V_34 ) ) ;
}
F_86 ( V_12 , V_79 , - ( V_35 << V_34 ) ) ;
F_88 ( & V_12 -> V_72 ) ;
return V_35 ;
}
void F_135 ( struct V_12 * V_12 , struct V_68 * V_69 )
{
unsigned long V_64 ;
int V_114 ;
unsigned long V_115 ;
F_102 ( V_64 ) ;
V_115 = F_136 ( V_69 -> V_115 ) ;
if ( V_69 -> V_67 >= V_115 )
V_114 = V_115 ;
else
V_114 = V_69 -> V_67 ;
if ( V_114 > 0 ) {
F_78 ( V_12 , V_114 , V_69 ) ;
V_69 -> V_67 -= V_114 ;
}
F_105 ( V_64 ) ;
}
static void F_137 ( unsigned int V_116 )
{
unsigned long V_64 ;
struct V_12 * V_12 ;
F_138 (zone) {
struct V_117 * V_118 ;
struct V_68 * V_69 ;
F_102 ( V_64 ) ;
V_118 = F_139 ( V_12 -> V_119 , V_116 ) ;
V_69 = & V_118 -> V_69 ;
if ( V_69 -> V_67 ) {
F_78 ( V_12 , V_69 -> V_67 , V_69 ) ;
V_69 -> V_67 = 0 ;
}
F_105 ( V_64 ) ;
}
}
void F_140 ( void * V_120 )
{
F_137 ( F_141 () ) ;
}
void F_142 ( void )
{
int V_116 ;
struct V_117 * V_69 ;
struct V_12 * V_12 ;
static T_3 V_121 ;
F_143 (cpu) {
bool V_122 = false ;
F_138 (zone) {
V_69 = F_139 ( V_12 -> V_119 , V_116 ) ;
if ( V_69 -> V_69 . V_67 ) {
V_122 = true ;
break;
}
}
if ( V_122 )
F_144 ( V_116 , & V_121 ) ;
else
F_145 ( V_116 , & V_121 ) ;
}
F_146 ( & V_121 , F_140 , NULL , 1 ) ;
}
void F_147 ( struct V_12 * V_12 )
{
unsigned long V_15 , V_123 ;
unsigned long V_64 ;
unsigned int V_34 , V_124 ;
struct V_74 * V_125 ;
if ( F_148 ( V_12 ) )
return;
F_149 ( & V_12 -> V_72 , V_64 ) ;
V_123 = F_150 ( V_12 ) ;
for ( V_15 = V_12 -> V_18 ; V_15 < V_123 ; V_15 ++ )
if ( F_151 ( V_15 ) ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
if ( ! F_152 ( V_5 ) )
F_153 ( V_5 ) ;
}
F_154 (order, t) {
F_155 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_35 ;
V_15 = F_10 ( F_81 ( V_125 , struct V_5 , V_55 ) ) ;
for ( V_35 = 0 ; V_35 < ( 1UL << V_34 ) ; V_35 ++ )
F_156 ( F_127 ( V_15 + V_35 ) ) ;
}
}
F_157 ( & V_12 -> V_72 , V_64 ) ;
}
void F_158 ( struct V_5 * V_5 , bool V_113 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
struct V_68 * V_69 ;
unsigned long V_64 ;
unsigned long V_15 = F_10 ( V_5 ) ;
int V_6 ;
if ( ! F_91 ( V_5 , 0 ) )
return;
V_6 = F_101 ( V_5 , V_15 ) ;
F_104 ( V_5 , V_6 ) ;
F_102 ( V_64 ) ;
F_159 ( V_82 ) ;
if ( V_6 >= V_8 ) {
if ( F_7 ( F_90 ( V_6 ) ) ) {
F_89 ( V_12 , V_5 , V_15 , 0 , V_6 ) ;
goto V_27;
}
V_6 = V_126 ;
}
V_69 = & F_160 ( V_12 -> V_119 ) -> V_69 ;
if ( ! V_113 )
F_72 ( & V_5 -> V_55 , & V_69 -> V_76 [ V_6 ] ) ;
else
F_71 ( & V_5 -> V_55 , & V_69 -> V_76 [ V_6 ] ) ;
V_69 -> V_67 ++ ;
if ( V_69 -> V_67 >= V_69 -> V_90 ) {
unsigned long V_115 = F_136 ( V_69 -> V_115 ) ;
F_78 ( V_12 , V_115 , V_69 ) ;
V_69 -> V_67 -= V_115 ;
}
V_27:
F_105 ( V_64 ) ;
}
void F_161 ( struct V_74 * V_75 , bool V_113 )
{
struct V_5 * V_5 , * V_96 ;
F_162 (page, next, list, lru) {
F_163 ( V_5 , V_113 ) ;
F_158 ( V_5 , V_113 ) ;
}
}
void F_164 ( struct V_5 * V_5 , unsigned int V_34 )
{
int V_35 ;
F_62 ( F_68 ( V_5 ) , V_5 ) ;
F_62 ( ! F_63 ( V_5 ) , V_5 ) ;
#ifdef F_165
if ( F_166 ( V_5 ) )
F_164 ( F_167 ( V_5 [ 0 ] . V_127 ) , V_34 ) ;
#endif
for ( V_35 = 1 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_109 ( V_5 + V_35 ) ;
}
static int F_168 ( struct V_5 * V_5 , unsigned int V_34 )
{
unsigned long V_128 ;
struct V_12 * V_12 ;
int V_77 ;
F_123 ( ! F_65 ( V_5 ) ) ;
V_12 = F_18 ( V_5 ) ;
V_77 = F_169 ( V_5 ) ;
if ( ! F_90 ( V_77 ) ) {
V_128 = F_170 ( V_12 ) + ( 1 << V_34 ) ;
if ( ! F_171 ( V_12 , 0 , V_128 , 0 , 0 ) )
return 0 ;
F_69 ( V_12 , - ( 1UL << V_34 ) , V_77 ) ;
}
F_70 ( & V_5 -> V_55 ) ;
V_12 -> V_56 [ V_34 ] . V_57 -- ;
F_56 ( V_5 ) ;
if ( V_34 >= V_87 - 1 ) {
struct V_5 * V_129 = V_5 + ( 1 << V_34 ) - 1 ;
for (; V_5 < V_129 ; V_5 += V_85 ) {
int V_77 = F_169 ( V_5 ) ;
if ( ! F_90 ( V_77 ) && ! F_87 ( V_77 ) )
F_6 ( V_5 ,
V_126 ) ;
}
}
return 1UL << V_34 ;
}
int F_172 ( struct V_5 * V_5 )
{
unsigned int V_34 ;
int V_36 ;
V_34 = F_61 ( V_5 ) ;
V_36 = F_168 ( V_5 , V_34 ) ;
if ( ! V_36 )
return 0 ;
F_109 ( V_5 ) ;
F_164 ( V_5 , V_34 ) ;
return V_36 ;
}
static inline
struct V_5 * F_173 ( struct V_12 * V_130 ,
struct V_12 * V_12 , unsigned int V_34 ,
T_1 V_40 , int V_6 )
{
unsigned long V_64 ;
struct V_5 * V_5 ;
bool V_113 = ( ( V_40 & V_131 ) != 0 ) ;
V_132:
if ( F_84 ( V_34 == 0 ) ) {
struct V_68 * V_69 ;
struct V_74 * V_75 ;
F_102 ( V_64 ) ;
V_69 = & F_160 ( V_12 -> V_119 ) -> V_69 ;
V_75 = & V_69 -> V_76 [ V_6 ] ;
if ( F_80 ( V_75 ) ) {
V_69 -> V_67 += F_134 ( V_12 , 0 ,
V_69 -> V_115 , V_75 ,
V_6 , V_113 ) ;
if ( F_7 ( F_80 ( V_75 ) ) )
goto V_133;
}
if ( V_113 )
V_5 = F_81 ( V_75 -> V_78 , struct V_5 , V_55 ) ;
else
V_5 = F_81 ( V_75 -> V_96 , struct V_5 , V_55 ) ;
F_70 ( & V_5 -> V_55 ) ;
V_69 -> V_67 -- ;
} else {
if ( F_7 ( V_40 & V_134 ) ) {
F_174 ( V_34 > 1 ) ;
}
F_149 ( & V_12 -> V_72 , V_64 ) ;
V_5 = F_132 ( V_12 , V_34 , V_6 ) ;
F_88 ( & V_12 -> V_72 ) ;
if ( ! V_5 )
goto V_133;
F_69 ( V_12 , - ( 1 << V_34 ) ,
F_82 ( V_5 ) ) ;
}
F_86 ( V_12 , V_135 , - ( 1 << V_34 ) ) ;
F_175 ( V_136 , V_12 , 1 << V_34 ) ;
F_176 ( V_130 , V_12 , V_40 ) ;
F_105 ( V_64 ) ;
F_62 ( F_19 ( V_12 , V_5 ) , V_5 ) ;
if ( F_118 ( V_5 , V_34 , V_40 ) )
goto V_132;
return V_5 ;
V_133:
F_105 ( V_64 ) ;
return NULL ;
}
static int T_2 F_177 ( char * V_137 )
{
return F_178 ( & V_138 . V_139 , V_137 ) ;
}
static bool F_179 ( T_1 V_140 , unsigned int V_34 )
{
if ( V_34 < V_138 . V_141 )
return false ;
if ( V_140 & V_134 )
return false ;
if ( V_138 . V_142 && ( V_140 & V_41 ) )
return false ;
if ( V_138 . V_143 && ( V_140 & V_144 ) )
return false ;
return F_180 ( & V_138 . V_139 , 1 << V_34 ) ;
}
static int T_2 F_181 ( void )
{
T_4 V_145 = V_146 | V_147 | V_148 ;
struct V_149 * V_150 ;
V_150 = F_182 ( L_15 , NULL ,
& V_138 . V_139 ) ;
if ( F_183 ( V_150 ) )
return F_184 ( V_150 ) ;
if ( ! F_185 ( L_16 , V_145 , V_150 ,
& V_138 . V_143 ) )
goto V_151;
if ( ! F_185 ( L_17 , V_145 , V_150 ,
& V_138 . V_142 ) )
goto V_151;
if ( ! F_186 ( L_18 , V_145 , V_150 ,
& V_138 . V_141 ) )
goto V_151;
return 0 ;
V_151:
F_187 ( V_150 ) ;
return - V_152 ;
}
static inline bool F_179 ( T_1 V_140 , unsigned int V_34 )
{
return false ;
}
static bool F_188 ( struct V_12 * V_153 , unsigned int V_34 ,
unsigned long V_154 , int V_155 , int V_156 ,
long V_157 )
{
long V_158 = V_154 ;
long V_159 = V_153 -> V_159 [ V_155 ] ;
int V_160 ;
long V_161 = 0 ;
V_157 -= ( 1 << V_34 ) - 1 ;
if ( V_156 & V_162 )
V_158 -= V_158 / 2 ;
if ( V_156 & V_163 )
V_158 -= V_158 / 4 ;
#ifdef F_189
if ( ! ( V_156 & V_164 ) )
V_161 = F_190 ( V_153 , V_80 ) ;
#endif
if ( V_157 - V_161 <= V_158 + V_159 )
return false ;
for ( V_160 = 0 ; V_160 < V_34 ; V_160 ++ ) {
V_157 -= V_153 -> V_56 [ V_160 ] . V_57 << V_160 ;
V_158 >>= 1 ;
if ( V_157 <= V_158 )
return false ;
}
return true ;
}
bool F_171 ( struct V_12 * V_153 , unsigned int V_34 , unsigned long V_154 ,
int V_155 , int V_156 )
{
return F_188 ( V_153 , V_34 , V_154 , V_155 , V_156 ,
F_190 ( V_153 , V_79 ) ) ;
}
bool F_191 ( struct V_12 * V_153 , unsigned int V_34 ,
unsigned long V_154 , int V_155 , int V_156 )
{
long V_157 = F_190 ( V_153 , V_79 ) ;
if ( V_153 -> V_165 && V_157 < V_153 -> V_165 )
V_157 = F_192 ( V_153 , V_79 ) ;
return F_188 ( V_153 , V_34 , V_154 , V_155 , V_156 ,
V_157 ) ;
}
static T_5 * F_193 ( struct V_166 * V_166 , int V_156 )
{
struct V_167 * V_168 ;
T_5 * V_169 ;
V_168 = V_166 -> V_170 ;
if ( ! V_168 )
return NULL ;
if ( F_194 ( V_26 , V_168 -> V_171 + V_29 ) ) {
F_195 ( V_168 -> V_172 , V_173 ) ;
V_168 -> V_171 = V_26 ;
}
V_169 = ! F_45 () && ( V_156 & V_174 ) ?
& V_175 :
& V_176 [ V_177 ] ;
return V_169 ;
}
static int F_196 ( struct V_166 * V_166 , struct V_178 * V_153 ,
T_5 * V_169 )
{
struct V_167 * V_168 ;
int V_35 ;
int V_179 ;
V_168 = V_166 -> V_170 ;
if ( ! V_168 )
return 1 ;
V_35 = V_153 - V_166 -> V_180 ;
V_179 = V_168 -> V_181 [ V_35 ] ;
return F_197 ( V_179 , * V_169 ) && ! F_198 ( V_35 , V_168 -> V_172 ) ;
}
static void F_199 ( struct V_166 * V_166 , struct V_178 * V_153 )
{
struct V_167 * V_168 ;
int V_35 ;
V_168 = V_166 -> V_170 ;
if ( ! V_168 )
return;
V_35 = V_153 - V_166 -> V_180 ;
F_200 ( V_35 , V_168 -> V_172 ) ;
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
return F_204 ( F_15 ( V_182 ) , F_15 ( V_12 ) ) <
V_184 ;
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
static struct V_5 *
F_205 ( T_1 V_140 , T_5 * V_185 , unsigned int V_34 ,
struct V_166 * V_166 , int V_186 , int V_156 ,
struct V_12 * V_130 , int V_155 , int V_6 )
{
struct V_178 * V_153 ;
struct V_5 * V_5 = NULL ;
struct V_12 * V_12 ;
T_5 * V_169 = NULL ;
int V_187 = 0 ;
int V_188 = 0 ;
bool V_189 = ( V_156 & V_190 ) &&
( V_140 & V_191 ) ;
V_192:
F_206 (zone, z, zonelist,
high_zoneidx, nodemask) {
unsigned long V_154 ;
if ( F_207 ( V_193 ) && V_187 &&
! F_196 ( V_166 , V_153 , V_169 ) )
continue;
if ( F_208 () &&
( V_156 & V_174 ) &&
! F_209 ( V_12 , V_140 ) )
continue;
if ( V_156 & V_194 ) {
if ( ! F_202 ( V_130 , V_12 ) )
continue;
if ( F_190 ( V_12 , V_135 ) <= 0 )
continue;
}
if ( V_189 && ! F_210 ( V_12 ) )
continue;
V_154 = V_12 -> V_128 [ V_156 & V_195 ] ;
if ( ! F_171 ( V_12 , V_34 , V_154 ,
V_155 , V_156 ) ) {
int V_13 ;
F_211 ( V_196 < V_197 ) ;
if ( V_156 & V_196 )
goto V_198;
if ( F_207 ( V_193 ) &&
! V_188 && V_199 > 1 ) {
V_169 = F_193 ( V_166 , V_156 ) ;
V_187 = 1 ;
V_188 = 1 ;
}
if ( V_200 == 0 ||
! F_203 ( V_130 , V_12 ) )
goto V_201;
if ( F_207 ( V_193 ) && V_187 &&
! F_196 ( V_166 , V_153 , V_169 ) )
continue;
V_13 = F_212 ( V_12 , V_140 , V_34 ) ;
switch ( V_13 ) {
case V_202 :
continue;
case V_203 :
continue;
default:
if ( F_171 ( V_12 , V_34 , V_154 ,
V_155 , V_156 ) )
goto V_198;
if ( ( ( V_156 & V_195 ) == V_204 ) ||
V_13 == V_205 )
goto V_201;
continue;
}
}
V_198:
V_5 = F_173 ( V_130 , V_12 , V_34 ,
V_140 , V_6 ) ;
if ( V_5 )
break;
V_201:
if ( F_207 ( V_193 ) && V_187 )
F_199 ( V_166 , V_153 ) ;
}
if ( F_7 ( F_207 ( V_193 ) && V_5 == NULL && V_187 ) ) {
V_187 = 0 ;
goto V_192;
}
if ( V_5 )
V_5 -> V_206 = ! ! ( V_156 & V_196 ) ;
return V_5 ;
}
static inline bool F_213 ( void )
{
bool V_13 = false ;
#if V_207 > 8
V_13 = F_45 () ;
#endif
return V_13 ;
}
void F_214 ( T_1 V_140 , int V_34 , const char * V_208 , ... )
{
unsigned int V_209 = V_210 ;
if ( ( V_140 & V_211 ) || ! F_215 ( & V_212 ) ||
F_115 () > 0 )
return;
if ( ! ( V_140 & V_213 ) )
if ( F_216 ( V_214 ) ||
( V_30 -> V_64 & ( V_215 | V_216 ) ) )
V_209 &= ~ V_210 ;
if ( F_45 () || ! ( V_140 & V_144 ) )
V_209 &= ~ V_210 ;
if ( V_208 ) {
struct V_217 V_218 ;
T_6 args ;
va_start ( args , V_208 ) ;
V_218 . V_208 = V_208 ;
V_218 . V_219 = & args ;
F_217 ( L_19 , & V_218 ) ;
va_end ( args ) ;
}
F_217 ( L_20 ,
V_30 -> V_31 , V_34 , V_140 ) ;
F_27 () ;
if ( ! F_213 () )
F_218 ( V_209 ) ;
}
static inline int
F_219 ( T_1 V_140 , unsigned int V_34 ,
unsigned long V_220 ,
unsigned long V_221 )
{
if ( V_140 & V_222 )
return 0 ;
if ( V_140 & V_134 )
return 1 ;
if ( ! V_220 && F_5 () )
return 0 ;
if ( V_34 <= V_223 )
return 1 ;
if ( V_140 & V_224 && V_221 < ( 1 << V_34 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_220 ( T_1 V_140 , unsigned int V_34 ,
struct V_166 * V_166 , enum V_225 V_186 ,
T_5 * V_185 , struct V_12 * V_130 ,
int V_155 , int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_221 ( V_166 , V_140 ) ) {
F_222 ( 1 ) ;
return NULL ;
}
V_5 = F_205 ( V_140 | V_226 , V_185 ,
V_34 , V_166 , V_186 ,
V_227 | V_174 ,
V_130 , V_155 , V_6 ) ;
if ( V_5 )
goto V_27;
if ( ! ( V_140 & V_134 ) ) {
if ( V_34 > V_223 )
goto V_27;
if ( V_186 < V_228 )
goto V_27;
if ( V_140 & V_229 )
goto V_27;
}
F_223 ( V_166 , V_140 , V_34 , V_185 , false ) ;
V_27:
F_224 ( V_166 , V_140 ) ;
return V_5 ;
}
static struct V_5 *
F_225 ( T_1 V_140 , unsigned int V_34 ,
struct V_166 * V_166 , enum V_225 V_186 ,
T_5 * V_185 , int V_156 , struct V_12 * V_130 ,
int V_155 , int V_6 , enum V_230 V_145 ,
bool * V_231 , bool * V_232 ,
unsigned long * V_220 )
{
if ( ! V_34 )
return NULL ;
if ( F_226 ( V_130 , V_34 ) ) {
* V_232 = true ;
return NULL ;
}
V_30 -> V_64 |= V_215 ;
* V_220 = F_227 ( V_166 , V_34 , V_140 ,
V_185 , V_145 ,
V_231 ) ;
V_30 -> V_64 &= ~ V_215 ;
if ( * V_220 != V_233 ) {
struct V_5 * V_5 ;
F_137 ( F_228 () ) ;
F_229 () ;
V_5 = F_205 ( V_140 , V_185 ,
V_34 , V_166 , V_186 ,
V_156 & ~ V_196 ,
V_130 , V_155 , V_6 ) ;
if ( V_5 ) {
V_130 -> V_234 = false ;
F_230 ( V_130 , V_34 , true ) ;
F_231 ( V_235 ) ;
return V_5 ;
}
F_231 ( V_236 ) ;
if ( V_145 != V_237 )
F_232 ( V_130 , V_34 ) ;
F_233 () ;
}
return NULL ;
}
static inline struct V_5 *
F_225 ( T_1 V_140 , unsigned int V_34 ,
struct V_166 * V_166 , enum V_225 V_186 ,
T_5 * V_185 , int V_156 , struct V_12 * V_130 ,
int V_155 , int V_6 ,
enum V_230 V_145 , bool * V_231 ,
bool * V_232 , unsigned long * V_220 )
{
return NULL ;
}
static int
F_234 ( T_1 V_140 , unsigned int V_34 , struct V_166 * V_166 ,
T_5 * V_185 )
{
struct V_238 V_238 ;
int V_239 ;
F_233 () ;
F_235 () ;
V_30 -> V_64 |= V_215 ;
F_236 ( V_140 ) ;
V_238 . V_240 = 0 ;
V_30 -> V_238 = & V_238 ;
V_239 = F_237 ( V_166 , V_34 , V_140 , V_185 ) ;
V_30 -> V_238 = NULL ;
F_238 () ;
V_30 -> V_64 &= ~ V_215 ;
F_233 () ;
return V_239 ;
}
static inline struct V_5 *
F_239 ( T_1 V_140 , unsigned int V_34 ,
struct V_166 * V_166 , enum V_225 V_186 ,
T_5 * V_185 , int V_156 , struct V_12 * V_130 ,
int V_155 , int V_6 , unsigned long * V_220 )
{
struct V_5 * V_5 = NULL ;
bool V_241 = false ;
* V_220 = F_234 ( V_140 , V_34 , V_166 ,
V_185 ) ;
if ( F_7 ( ! ( * V_220 ) ) )
return NULL ;
if ( F_207 ( V_193 ) )
F_201 ( V_166 ) ;
V_242:
V_5 = F_205 ( V_140 , V_185 , V_34 ,
V_166 , V_186 ,
V_156 & ~ V_196 ,
V_130 , V_155 ,
V_6 ) ;
if ( ! V_5 && ! V_241 ) {
F_142 () ;
V_241 = true ;
goto V_242;
}
return V_5 ;
}
static inline struct V_5 *
F_240 ( T_1 V_140 , unsigned int V_34 ,
struct V_166 * V_166 , enum V_225 V_186 ,
T_5 * V_185 , struct V_12 * V_130 ,
int V_155 , int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_205 ( V_140 , V_185 , V_34 ,
V_166 , V_186 , V_196 ,
V_130 , V_155 , V_6 ) ;
if ( ! V_5 && V_140 & V_134 )
F_241 ( V_130 , V_243 , V_29 / 50 ) ;
} while ( ! V_5 && ( V_140 & V_134 ) );
return V_5 ;
}
static void F_242 ( struct V_166 * V_166 ,
enum V_225 V_186 ,
struct V_12 * V_130 )
{
struct V_178 * V_153 ;
struct V_12 * V_12 ;
F_243 (zone, z, zonelist, high_zoneidx) {
if ( ! F_202 ( V_130 , V_12 ) )
continue;
F_244 ( V_12 , V_135 ,
F_245 ( V_12 ) - F_170 ( V_12 ) -
F_246 ( & V_12 -> V_244 [ V_135 ] ) ) ;
}
}
static void F_247 ( unsigned int V_34 ,
struct V_166 * V_166 ,
enum V_225 V_186 ,
struct V_12 * V_130 )
{
struct V_178 * V_153 ;
struct V_12 * V_12 ;
F_243 (zone, z, zonelist, high_zoneidx)
F_248 ( V_12 , V_34 , F_249 ( V_130 ) ) ;
}
static inline int
F_250 ( T_1 V_140 )
{
int V_156 = V_204 | V_174 ;
const bool V_245 = ! ( V_140 & ( V_144 | V_246 ) ) ;
F_211 ( V_247 != ( V_248 T_1 ) V_162 ) ;
V_156 |= ( V_248 int ) ( V_140 & V_247 ) ;
if ( V_245 ) {
if ( ! ( V_140 & V_213 ) )
V_156 |= V_163 ;
V_156 &= ~ V_174 ;
} else if ( F_7 ( F_251 ( V_30 ) ) && ! F_45 () )
V_156 |= V_163 ;
if ( F_84 ( ! ( V_140 & V_213 ) ) ) {
if ( V_140 & V_249 )
V_156 |= V_196 ;
else if ( F_252 () && ( V_30 -> V_64 & V_215 ) )
V_156 |= V_196 ;
else if ( ! F_45 () &&
( ( V_30 -> V_64 & V_215 ) ||
F_7 ( F_216 ( V_214 ) ) ) )
V_156 |= V_196 ;
}
#ifdef F_189
if ( F_253 ( V_140 ) == V_126 )
V_156 |= V_164 ;
#endif
return V_156 ;
}
bool F_254 ( T_1 V_140 )
{
return ! ! ( F_250 ( V_140 ) & V_196 ) ;
}
static inline struct V_5 *
F_255 ( T_1 V_140 , unsigned int V_34 ,
struct V_166 * V_166 , enum V_225 V_186 ,
T_5 * V_185 , struct V_12 * V_130 ,
int V_155 , int V_6 )
{
const T_1 V_250 = V_140 & V_144 ;
struct V_5 * V_5 = NULL ;
int V_156 ;
unsigned long V_221 = 0 ;
unsigned long V_220 ;
enum V_230 V_251 = V_237 ;
bool V_232 = false ;
bool V_231 = false ;
if ( V_34 >= V_44 ) {
F_174 ( ! ( V_140 & V_211 ) ) ;
return NULL ;
}
if ( F_207 ( V_193 ) &&
( V_140 & V_252 ) == V_252 )
goto V_253;
V_254:
if ( ! ( V_140 & V_246 ) )
F_247 ( V_34 , V_166 , V_186 , V_130 ) ;
V_156 = F_250 ( V_140 ) ;
if ( ! ( V_156 & V_174 ) && ! V_185 ) {
struct V_178 * V_255 ;
V_255 = F_256 ( V_166 , V_186 ,
NULL , & V_130 ) ;
V_155 = F_257 ( V_255 ) ;
}
V_256:
V_5 = F_205 ( V_140 , V_185 , V_34 , V_166 ,
V_186 , V_156 & ~ V_196 ,
V_130 , V_155 , V_6 ) ;
if ( V_5 )
goto V_257;
if ( V_156 & V_196 ) {
V_166 = F_258 ( F_259 () , V_140 ) ;
V_5 = F_240 ( V_140 , V_34 ,
V_166 , V_186 , V_185 ,
V_130 , V_155 , V_6 ) ;
if ( V_5 ) {
goto V_257;
}
}
if ( ! V_250 ) {
F_174 ( V_140 & V_134 ) ;
goto V_253;
}
if ( V_30 -> V_64 & V_215 )
goto V_253;
if ( F_216 ( V_214 ) && ! ( V_140 & V_134 ) )
goto V_253;
V_5 = F_225 ( V_140 , V_34 , V_166 ,
V_186 , V_185 , V_156 ,
V_130 ,
V_155 , V_6 ,
V_251 , & V_231 ,
& V_232 ,
& V_220 ) ;
if ( V_5 )
goto V_257;
if ( ! ( V_140 & V_246 ) || ( V_30 -> V_64 & V_258 ) )
V_251 = V_259 ;
if ( ( V_232 || V_231 ) &&
( V_140 & V_246 ) )
goto V_253;
V_5 = F_239 ( V_140 , V_34 ,
V_166 , V_186 ,
V_185 ,
V_156 , V_130 ,
V_155 , V_6 ,
& V_220 ) ;
if ( V_5 )
goto V_257;
if ( ! V_220 ) {
if ( F_260 ( V_140 ) ) {
if ( V_260 )
goto V_253;
if ( ( V_30 -> V_64 & V_261 ) &&
! ( V_140 & V_134 ) )
goto V_253;
V_5 = F_220 ( V_140 , V_34 ,
V_166 , V_186 ,
V_185 , V_130 ,
V_155 , V_6 ) ;
if ( V_5 )
goto V_257;
if ( ! ( V_140 & V_134 ) ) {
if ( V_34 > V_223 )
goto V_253;
if ( V_186 < V_228 )
goto V_253;
}
goto V_254;
}
}
V_221 += V_220 ;
if ( F_219 ( V_140 , V_34 , V_220 ,
V_221 ) ) {
F_241 ( V_130 , V_243 , V_29 / 50 ) ;
goto V_256;
} else {
V_5 = F_225 ( V_140 , V_34 , V_166 ,
V_186 , V_185 , V_156 ,
V_130 ,
V_155 , V_6 ,
V_251 , & V_231 ,
& V_232 ,
& V_220 ) ;
if ( V_5 )
goto V_257;
}
V_253:
F_214 ( V_140 , V_34 , NULL ) ;
return V_5 ;
V_257:
if ( V_262 )
F_261 ( V_5 , V_34 , V_140 ) ;
return V_5 ;
}
struct V_5 *
F_262 ( T_1 V_140 , unsigned int V_34 ,
struct V_166 * V_166 , T_5 * V_185 )
{
enum V_225 V_186 = F_263 ( V_140 ) ;
struct V_12 * V_130 ;
struct V_178 * V_255 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_253 ( V_140 ) ;
unsigned int V_263 ;
int V_156 = V_190 | V_174 | V_194 ;
int V_155 ;
V_140 &= V_3 ;
F_264 ( V_140 ) ;
F_265 ( V_140 & V_144 ) ;
if ( F_179 ( V_140 , V_34 ) )
return NULL ;
if ( F_7 ( ! V_166 -> V_180 -> V_12 ) )
return NULL ;
V_264:
V_263 = F_266 () ;
V_255 = F_256 ( V_166 , V_186 ,
V_185 ? : & V_175 ,
& V_130 ) ;
if ( ! V_130 )
goto V_27;
V_155 = F_257 ( V_255 ) ;
#ifdef F_189
if ( F_253 ( V_140 ) == V_126 )
V_156 |= V_164 ;
#endif
V_242:
V_5 = F_205 ( V_140 | V_226 , V_185 , V_34 ,
V_166 , V_186 , V_156 ,
V_130 , V_155 , V_6 ) ;
if ( F_7 ( ! V_5 ) ) {
if ( V_156 & V_194 ) {
F_242 ( V_166 , V_186 ,
V_130 ) ;
V_156 &= ~ V_194 ;
goto V_242;
}
V_140 = F_267 ( V_140 ) ;
V_5 = F_255 ( V_140 , V_34 ,
V_166 , V_186 , V_185 ,
V_130 , V_155 , V_6 ) ;
}
F_268 ( V_5 , V_34 , V_140 , V_6 ) ;
V_27:
if ( F_7 ( ! V_5 && F_269 ( V_263 ) ) )
goto V_264;
return V_5 ;
}
unsigned long F_270 ( T_1 V_140 , unsigned int V_34 )
{
struct V_5 * V_5 ;
F_44 ( ( V_140 & V_41 ) != 0 ) ;
V_5 = F_271 ( V_140 , V_34 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_97 ( V_5 ) ;
}
unsigned long F_272 ( T_1 V_140 )
{
return F_270 ( V_140 | V_93 , 0 ) ;
}
void F_110 ( struct V_5 * V_5 , unsigned int V_34 )
{
if ( F_273 ( V_5 ) ) {
if ( V_34 == 0 )
F_158 ( V_5 , false ) ;
else
F_30 ( V_5 , V_34 ) ;
}
}
void V_157 ( unsigned long V_265 , unsigned int V_34 )
{
if ( V_265 != 0 ) {
F_44 ( ! F_274 ( ( void * ) V_265 ) ) ;
F_110 ( F_167 ( ( void * ) V_265 ) , V_34 ) ;
}
}
struct V_5 * F_275 ( T_1 V_140 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_266 * V_267 = NULL ;
if ( ! F_276 ( V_140 , & V_267 , V_34 ) )
return NULL ;
V_5 = F_271 ( V_140 , V_34 ) ;
F_277 ( V_5 , V_267 , V_34 ) ;
return V_5 ;
}
struct V_5 * F_278 ( int V_268 , T_1 V_140 , unsigned int V_34 )
{
struct V_5 * V_5 ;
struct V_266 * V_267 = NULL ;
if ( ! F_276 ( V_140 , & V_267 , V_34 ) )
return NULL ;
V_5 = F_279 ( V_268 , V_140 , V_34 ) ;
F_277 ( V_5 , V_267 , V_34 ) ;
return V_5 ;
}
void F_280 ( struct V_5 * V_5 , unsigned int V_34 )
{
F_281 ( V_5 , V_34 ) ;
F_110 ( V_5 , V_34 ) ;
}
void F_282 ( unsigned long V_265 , unsigned int V_34 )
{
if ( V_265 != 0 ) {
F_44 ( ! F_274 ( ( void * ) V_265 ) ) ;
F_280 ( F_167 ( ( void * ) V_265 ) , V_34 ) ;
}
}
static void * F_283 ( unsigned long V_265 , unsigned V_34 , T_7 V_92 )
{
if ( V_265 ) {
unsigned long V_269 = V_265 + ( V_81 << V_34 ) ;
unsigned long V_270 = V_265 + F_284 ( V_92 ) ;
F_164 ( F_167 ( ( void * ) V_265 ) , V_34 ) ;
while ( V_270 < V_269 ) {
F_285 ( V_270 ) ;
V_270 += V_81 ;
}
}
return ( void * ) V_265 ;
}
void * F_286 ( T_7 V_92 , T_1 V_140 )
{
unsigned int V_34 = F_287 ( V_92 ) ;
unsigned long V_265 ;
V_265 = F_270 ( V_140 , V_34 ) ;
return F_283 ( V_265 , V_34 , V_92 ) ;
}
void * F_288 ( int V_268 , T_7 V_92 , T_1 V_140 )
{
unsigned V_34 = F_287 ( V_92 ) ;
struct V_5 * V_37 = F_279 ( V_268 , V_140 , V_34 ) ;
if ( ! V_37 )
return NULL ;
return F_283 ( ( unsigned long ) F_97 ( V_37 ) , V_34 , V_92 ) ;
}
void F_289 ( void * V_271 , T_7 V_92 )
{
unsigned long V_265 = ( unsigned long ) V_271 ;
unsigned long V_272 = V_265 + F_284 ( V_92 ) ;
while ( V_265 < V_272 ) {
F_285 ( V_265 ) ;
V_265 += V_81 ;
}
}
static unsigned long F_290 ( int V_273 )
{
struct V_178 * V_153 ;
struct V_12 * V_12 ;
unsigned long V_274 = 0 ;
struct V_166 * V_166 = F_258 ( F_259 () , V_275 ) ;
F_243 (zone, z, zonelist, offset) {
unsigned long V_92 = V_12 -> V_84 ;
unsigned long V_90 = F_245 ( V_12 ) ;
if ( V_92 > V_90 )
V_274 += V_92 - V_90 ;
}
return V_274 ;
}
unsigned long F_291 ( void )
{
return F_290 ( F_263 ( V_276 ) ) ;
}
unsigned long F_292 ( void )
{
return F_290 ( F_263 ( V_277 ) ) ;
}
static inline void F_293 ( struct V_12 * V_12 )
{
if ( F_207 ( V_193 ) )
F_24 ( L_21 , F_15 ( V_12 ) ) ;
}
void F_294 ( struct V_278 * V_279 )
{
V_279 -> V_280 = V_281 ;
V_279 -> V_282 = 0 ;
V_279 -> V_283 = F_295 ( V_79 ) ;
V_279 -> V_284 = F_296 () ;
V_279 -> V_285 = V_286 ;
V_279 -> V_287 = F_297 () ;
V_279 -> V_288 = V_81 ;
}
void F_298 ( struct V_278 * V_279 , int V_268 )
{
int V_225 ;
unsigned long V_84 = 0 ;
T_8 * V_289 = F_299 ( V_268 ) ;
for ( V_225 = 0 ; V_225 < V_290 ; V_225 ++ )
V_84 += V_289 -> V_291 [ V_225 ] . V_84 ;
V_279 -> V_280 = V_84 ;
V_279 -> V_283 = F_300 ( V_268 , V_79 ) ;
#ifdef F_301
V_279 -> V_285 = V_289 -> V_291 [ V_292 ] . V_84 ;
V_279 -> V_287 = F_190 ( & V_289 -> V_291 [ V_292 ] ,
V_79 ) ;
#else
V_279 -> V_285 = 0 ;
V_279 -> V_287 = 0 ;
#endif
V_279 -> V_288 = V_81 ;
}
bool F_302 ( unsigned int V_64 , int V_268 )
{
bool V_13 = false ;
unsigned int V_263 ;
if ( ! ( V_64 & V_210 ) )
goto V_27;
do {
V_263 = F_266 () ;
V_13 = ! F_197 ( V_268 , V_175 ) ;
} while ( F_269 ( V_263 ) );
V_27:
return V_13 ;
}
static void F_303 ( unsigned char type )
{
static const char V_293 [ V_294 ] = {
[ V_9 ] = 'U' ,
[ V_106 ] = 'E' ,
[ V_126 ] = 'M' ,
[ V_111 ] = 'R' ,
#ifdef F_189
[ V_86 ] = 'C' ,
#endif
#ifdef F_304
[ V_295 ] = 'I' ,
#endif
} ;
char V_296 [ V_294 + 1 ] ;
char * V_37 = V_296 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_294 ; V_35 ++ ) {
if ( type & ( 1 << V_35 ) )
* V_37 ++ = V_293 [ V_35 ] ;
}
* V_37 = '\0' ;
F_24 ( L_22 , V_296 ) ;
}
void F_305 ( unsigned int V_209 )
{
int V_116 ;
struct V_12 * V_12 ;
F_138 (zone) {
if ( F_302 ( V_209 , F_15 ( V_12 ) ) )
continue;
F_293 ( V_12 ) ;
F_24 ( L_23 , V_12 -> V_20 ) ;
F_143 (cpu) {
struct V_117 * V_119 ;
V_119 = F_139 ( V_12 -> V_119 , V_116 ) ;
F_24 ( L_24 ,
V_116 , V_119 -> V_69 . V_90 ,
V_119 -> V_69 . V_115 , V_119 -> V_69 . V_67 ) ;
}
}
F_24 ( L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
F_295 ( V_297 ) ,
F_295 ( V_298 ) ,
F_295 ( V_299 ) ,
F_295 ( V_300 ) ,
F_295 ( V_301 ) ,
F_295 ( V_302 ) ,
F_295 ( V_303 ) ,
F_295 ( V_304 ) ,
F_295 ( V_305 ) ,
F_295 ( V_306 ) ,
F_295 ( V_79 ) ,
F_295 ( V_307 ) ,
F_295 ( V_308 ) ,
F_295 ( V_309 ) ,
F_295 ( V_310 ) ,
F_295 ( V_311 ) ,
F_295 ( V_312 ) ,
F_295 ( V_80 ) ) ;
F_138 (zone) {
int V_35 ;
if ( F_302 ( V_209 , F_15 ( V_12 ) ) )
continue;
F_293 ( V_12 ) ;
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
F_306 ( F_190 ( V_12 , V_79 ) ) ,
F_306 ( F_307 ( V_12 ) ) ,
F_306 ( F_170 ( V_12 ) ) ,
F_306 ( F_245 ( V_12 ) ) ,
F_306 ( F_190 ( V_12 , V_297 ) ) ,
F_306 ( F_190 ( V_12 , V_298 ) ) ,
F_306 ( F_190 ( V_12 , V_300 ) ) ,
F_306 ( F_190 ( V_12 , V_301 ) ) ,
F_306 ( F_190 ( V_12 , V_303 ) ) ,
F_306 ( F_190 ( V_12 , V_299 ) ) ,
F_306 ( F_190 ( V_12 , V_302 ) ) ,
F_306 ( V_12 -> V_313 ) ,
F_306 ( V_12 -> V_84 ) ,
F_306 ( F_190 ( V_12 , V_314 ) ) ,
F_306 ( F_190 ( V_12 , V_304 ) ) ,
F_306 ( F_190 ( V_12 , V_305 ) ) ,
F_306 ( F_190 ( V_12 , V_309 ) ) ,
F_306 ( F_190 ( V_12 , V_310 ) ) ,
F_306 ( F_190 ( V_12 , V_307 ) ) ,
F_306 ( F_190 ( V_12 , V_308 ) ) ,
F_190 ( V_12 , V_315 ) *
V_316 / 1024 ,
F_306 ( F_190 ( V_12 , V_311 ) ) ,
F_306 ( F_190 ( V_12 , V_306 ) ) ,
F_306 ( F_190 ( V_12 , V_312 ) ) ,
F_306 ( F_190 ( V_12 , V_80 ) ) ,
F_306 ( F_190 ( V_12 , V_317 ) ) ,
V_12 -> V_73 ,
( ! F_308 ( V_12 ) ? L_62 : L_63 )
) ;
F_24 ( L_64 ) ;
for ( V_35 = 0 ; V_35 < V_290 ; V_35 ++ )
F_24 ( L_65 , V_12 -> V_159 [ V_35 ] ) ;
F_24 ( L_61 ) ;
}
F_138 (zone) {
unsigned long V_318 [ V_44 ] , V_64 , V_34 , V_319 = 0 ;
unsigned char V_293 [ V_44 ] ;
if ( F_302 ( V_209 , F_15 ( V_12 ) ) )
continue;
F_293 ( V_12 ) ;
F_24 ( L_66 , V_12 -> V_20 ) ;
F_149 ( & V_12 -> V_72 , V_64 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
struct V_56 * V_91 = & V_12 -> V_56 [ V_34 ] ;
int type ;
V_318 [ V_34 ] = V_91 -> V_57 ;
V_319 += V_318 [ V_34 ] << V_34 ;
V_293 [ V_34 ] = 0 ;
for ( type = 0 ; type < V_294 ; type ++ ) {
if ( ! F_80 ( & V_91 -> V_60 [ type ] ) )
V_293 [ V_34 ] |= 1 << type ;
}
}
F_157 ( & V_12 -> V_72 , V_64 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
F_24 ( L_67 , V_318 [ V_34 ] , F_306 ( 1UL ) << V_34 ) ;
if ( V_318 [ V_34 ] )
F_303 ( V_293 [ V_34 ] ) ;
}
F_24 ( L_68 , F_306 ( V_319 ) ) ;
}
F_309 () ;
F_24 ( L_69 , F_295 ( V_320 ) ) ;
F_310 () ;
}
static void F_311 ( struct V_12 * V_12 , struct V_178 * V_178 )
{
V_178 -> V_12 = V_12 ;
V_178 -> F_249 = F_249 ( V_12 ) ;
}
static int F_312 ( T_8 * V_289 , struct V_166 * V_166 ,
int V_321 )
{
struct V_12 * V_12 ;
enum V_225 V_225 = V_290 ;
do {
V_225 -- ;
V_12 = V_289 -> V_291 + V_225 ;
if ( F_313 ( V_12 ) ) {
F_311 ( V_12 ,
& V_166 -> V_180 [ V_321 ++ ] ) ;
F_314 ( V_225 ) ;
}
} while ( V_225 );
return V_321 ;
}
static int F_315 ( char * V_322 )
{
if ( * V_322 == 'd' || * V_322 == 'D' ) {
V_323 = V_324 ;
} else if ( * V_322 == 'n' || * V_322 == 'N' ) {
V_323 = V_325 ;
} else if ( * V_322 == 'z' || * V_322 == 'Z' ) {
V_323 = V_326 ;
} else {
F_24 ( V_327
L_70
L_71 , V_322 ) ;
return - V_328 ;
}
return 0 ;
}
static T_2 int F_316 ( char * V_322 )
{
int V_13 ;
if ( ! V_322 )
return 0 ;
V_13 = F_315 ( V_322 ) ;
if ( V_13 == 0 )
F_317 ( V_329 , V_322 , V_330 ) ;
return V_13 ;
}
int F_318 ( struct V_331 * V_332 , int V_333 ,
void T_9 * V_334 , T_7 * V_335 ,
T_10 * V_336 )
{
char V_337 [ V_330 ] ;
int V_13 ;
static F_319 ( V_338 ) ;
F_320 ( & V_338 ) ;
if ( V_333 ) {
if ( strlen ( ( char * ) V_332 -> V_339 ) >= V_330 ) {
V_13 = - V_328 ;
goto V_27;
}
strcpy ( V_337 , ( char * ) V_332 -> V_339 ) ;
}
V_13 = F_321 ( V_332 , V_333 , V_334 , V_335 , V_336 ) ;
if ( V_13 )
goto V_27;
if ( V_333 ) {
int V_340 = V_323 ;
V_13 = F_315 ( ( char * ) V_332 -> V_339 ) ;
if ( V_13 ) {
strncpy ( ( char * ) V_332 -> V_339 , V_337 ,
V_330 ) ;
V_323 = V_340 ;
} else if ( V_340 != V_323 ) {
F_320 ( & V_341 ) ;
F_322 ( NULL , NULL ) ;
F_323 ( & V_341 ) ;
}
}
V_27:
F_323 ( & V_338 ) ;
return V_13 ;
}
static int F_324 ( int V_183 , T_5 * V_342 )
{
int V_179 , V_279 ;
int V_343 = V_344 ;
int V_345 = V_346 ;
const struct V_347 * V_296 = F_325 ( 0 ) ;
if ( ! F_197 ( V_183 , * V_342 ) ) {
F_326 ( V_183 , * V_342 ) ;
return V_183 ;
}
F_327 (n, N_MEMORY) {
if ( F_197 ( V_179 , * V_342 ) )
continue;
V_279 = F_204 ( V_183 , V_179 ) ;
V_279 += ( V_179 < V_183 ) ;
V_296 = F_325 ( V_179 ) ;
if ( ! F_328 ( V_296 ) )
V_279 += V_348 ;
V_279 *= ( V_349 * V_350 ) ;
V_279 += V_351 [ V_179 ] ;
if ( V_279 < V_343 ) {
V_343 = V_279 ;
V_345 = V_179 ;
}
}
if ( V_345 >= 0 )
F_326 ( V_345 , * V_342 ) ;
return V_345 ;
}
static void F_329 ( T_8 * V_289 , int V_183 )
{
int V_352 ;
struct V_166 * V_166 ;
V_166 = & V_289 -> V_353 [ 0 ] ;
for ( V_352 = 0 ; V_166 -> V_180 [ V_352 ] . V_12 != NULL ; V_352 ++ )
;
V_352 = F_312 ( F_299 ( V_183 ) , V_166 , V_352 ) ;
V_166 -> V_180 [ V_352 ] . V_12 = NULL ;
V_166 -> V_180 [ V_352 ] . F_249 = 0 ;
}
static void F_330 ( T_8 * V_289 )
{
int V_352 ;
struct V_166 * V_166 ;
V_166 = & V_289 -> V_353 [ 1 ] ;
V_352 = F_312 ( V_289 , V_166 , 0 ) ;
V_166 -> V_180 [ V_352 ] . V_12 = NULL ;
V_166 -> V_180 [ V_352 ] . F_249 = 0 ;
}
static void F_331 ( T_8 * V_289 , int V_354 )
{
int V_355 , V_352 , V_183 ;
int V_225 ;
struct V_12 * V_153 ;
struct V_166 * V_166 ;
V_166 = & V_289 -> V_353 [ 0 ] ;
V_355 = 0 ;
for ( V_225 = V_290 - 1 ; V_225 >= 0 ; V_225 -- ) {
for ( V_352 = 0 ; V_352 < V_354 ; V_352 ++ ) {
V_183 = V_356 [ V_352 ] ;
V_153 = & F_299 ( V_183 ) -> V_291 [ V_225 ] ;
if ( F_313 ( V_153 ) ) {
F_311 ( V_153 ,
& V_166 -> V_180 [ V_355 ++ ] ) ;
F_314 ( V_225 ) ;
}
}
}
V_166 -> V_180 [ V_355 ] . V_12 = NULL ;
V_166 -> V_180 [ V_355 ] . F_249 = 0 ;
}
static int F_332 ( void )
{
int V_268 , V_225 ;
unsigned long V_357 , V_358 ;
struct V_12 * V_153 ;
int V_359 ;
V_357 = 0 ;
V_358 = 0 ;
F_333 (nid) {
for ( V_225 = 0 ; V_225 < V_290 ; V_225 ++ ) {
V_153 = & F_299 ( V_268 ) -> V_291 [ V_225 ] ;
if ( F_313 ( V_153 ) ) {
if ( V_225 < V_228 )
V_357 += V_153 -> V_84 ;
V_358 += V_153 -> V_84 ;
} else if ( V_225 == V_228 ) {
return V_325 ;
}
}
}
if ( ! V_357 ||
V_357 > V_358 / 2 )
return V_325 ;
V_359 = V_358 /
( F_334 ( V_176 [ V_177 ] ) + 1 ) ;
F_333 (nid) {
V_357 = 0 ;
V_358 = 0 ;
for ( V_225 = 0 ; V_225 < V_290 ; V_225 ++ ) {
V_153 = & F_299 ( V_268 ) -> V_291 [ V_225 ] ;
if ( F_313 ( V_153 ) ) {
if ( V_225 < V_228 )
V_357 += V_153 -> V_313 ;
V_358 += V_153 -> V_313 ;
}
}
if ( V_357 &&
V_358 > V_359 &&
V_357 > V_358 * 70 / 100 )
return V_325 ;
}
return V_326 ;
}
static void F_335 ( void )
{
if ( V_323 == V_324 )
V_360 = F_332 () ;
else
V_360 = V_323 ;
}
static void F_336 ( T_8 * V_289 )
{
int V_352 , V_183 , V_361 ;
enum V_225 V_35 ;
T_5 V_362 ;
int V_363 , V_364 ;
struct V_166 * V_166 ;
int V_34 = V_360 ;
for ( V_35 = 0 ; V_35 < V_365 ; V_35 ++ ) {
V_166 = V_289 -> V_353 + V_35 ;
V_166 -> V_180 [ 0 ] . V_12 = NULL ;
V_166 -> V_180 [ 0 ] . F_249 = 0 ;
}
V_363 = V_289 -> V_366 ;
V_361 = V_199 ;
V_364 = V_363 ;
F_337 ( V_362 ) ;
memset ( V_356 , 0 , sizeof( V_356 ) ) ;
V_352 = 0 ;
while ( ( V_183 = F_324 ( V_363 , & V_362 ) ) >= 0 ) {
if ( F_204 ( V_363 , V_183 ) !=
F_204 ( V_363 , V_364 ) )
V_351 [ V_183 ] = V_361 ;
V_364 = V_183 ;
V_361 -- ;
if ( V_34 == V_325 )
F_329 ( V_289 , V_183 ) ;
else
V_356 [ V_352 ++ ] = V_183 ;
}
if ( V_34 == V_326 ) {
F_331 ( V_289 , V_352 ) ;
}
F_330 ( V_289 ) ;
}
static void F_338 ( T_8 * V_289 )
{
struct V_166 * V_166 ;
struct V_167 * V_168 ;
struct V_178 * V_153 ;
V_166 = & V_289 -> V_353 [ 0 ] ;
V_166 -> V_170 = V_168 = & V_166 -> V_367 ;
F_195 ( V_168 -> V_172 , V_173 ) ;
for ( V_153 = V_166 -> V_180 ; V_153 -> V_12 ; V_153 ++ )
V_168 -> V_181 [ V_153 - V_166 -> V_180 ] = F_339 ( V_153 ) ;
}
int F_340 ( int V_183 )
{
struct V_12 * V_12 ;
( void ) F_256 ( F_258 ( V_183 , V_275 ) ,
F_263 ( V_275 ) ,
NULL ,
& V_12 ) ;
return V_12 -> V_183 ;
}
static void F_335 ( void )
{
V_360 = V_326 ;
}
static void F_336 ( T_8 * V_289 )
{
int V_183 , V_363 ;
enum V_225 V_352 ;
struct V_166 * V_166 ;
V_363 = V_289 -> V_366 ;
V_166 = & V_289 -> V_353 [ 0 ] ;
V_352 = F_312 ( V_289 , V_166 , 0 ) ;
for ( V_183 = V_363 + 1 ; V_183 < V_350 ; V_183 ++ ) {
if ( ! F_341 ( V_183 ) )
continue;
V_352 = F_312 ( F_299 ( V_183 ) , V_166 , V_352 ) ;
}
for ( V_183 = 0 ; V_183 < V_363 ; V_183 ++ ) {
if ( ! F_341 ( V_183 ) )
continue;
V_352 = F_312 ( F_299 ( V_183 ) , V_166 , V_352 ) ;
}
V_166 -> V_180 [ V_352 ] . V_12 = NULL ;
V_166 -> V_180 [ V_352 ] . F_249 = 0 ;
}
static void F_338 ( T_8 * V_289 )
{
V_289 -> V_353 [ 0 ] . V_170 = NULL ;
}
static int F_342 ( void * V_339 )
{
int V_268 ;
int V_116 ;
T_8 * V_368 = V_339 ;
#ifdef V_193
memset ( V_351 , 0 , sizeof( V_351 ) ) ;
#endif
if ( V_368 && ! F_341 ( V_368 -> V_366 ) ) {
F_336 ( V_368 ) ;
F_338 ( V_368 ) ;
}
F_333 (nid) {
T_8 * V_289 = F_299 ( V_268 ) ;
F_336 ( V_289 ) ;
F_338 ( V_289 ) ;
}
F_343 (cpu) {
F_344 ( & F_345 ( V_369 , V_116 ) , 0 ) ;
#ifdef F_346
if ( F_347 ( V_116 ) )
F_348 ( V_116 , F_340 ( F_349 ( V_116 ) ) ) ;
#endif
}
return 0 ;
}
void T_11 F_322 ( T_8 * V_289 , struct V_12 * V_12 )
{
F_335 () ;
if ( V_370 == V_371 ) {
F_342 ( NULL ) ;
F_350 () ;
F_351 () ;
} else {
#ifdef F_352
if ( V_12 )
F_353 ( V_12 ) ;
#endif
F_354 ( F_342 , V_289 , NULL ) ;
}
V_372 = F_292 () ;
if ( V_372 < ( V_85 * V_294 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_24 ( L_72
L_73 ,
V_199 ,
V_373 [ V_360 ] ,
V_7 ? L_74 : L_75 ,
V_372 ) ;
#ifdef V_193
F_24 ( L_76 , V_374 [ V_375 ] ) ;
#endif
}
static inline unsigned long F_355 ( unsigned long V_107 )
{
unsigned long V_92 = 1 ;
V_107 /= V_376 ;
while ( V_92 < V_107 )
V_92 <<= 1 ;
V_92 = V_158 ( V_92 , 4096UL ) ;
return F_356 ( V_92 , 4UL ) ;
}
static inline unsigned long F_355 ( unsigned long V_107 )
{
return 4096UL ;
}
static inline unsigned long F_357 ( unsigned long V_92 )
{
return F_358 ( ~ V_92 ) ;
}
static int F_359 ( unsigned long V_17 , unsigned long V_100 )
{
unsigned long V_15 ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 ++ ) {
if ( ! F_17 ( V_15 ) || F_360 ( F_127 ( V_15 ) ) )
return 1 ;
}
return 0 ;
}
static void F_361 ( struct V_12 * V_12 )
{
unsigned long V_17 , V_15 , V_100 , V_377 ;
struct V_5 * V_5 ;
unsigned long V_378 ;
int V_379 ;
int V_380 ;
V_17 = V_12 -> V_18 ;
V_100 = F_150 ( V_12 ) ;
V_17 = F_362 ( V_17 , V_85 ) ;
V_379 = F_362 ( F_307 ( V_12 ) , V_85 ) >>
V_87 ;
V_379 = V_158 ( 2 , V_379 ) ;
V_380 = V_12 -> V_381 ;
if ( V_379 == V_380 )
return;
V_12 -> V_381 = V_379 ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 += V_85 ) {
if ( ! F_151 ( V_15 ) )
continue;
V_5 = F_127 ( V_15 ) ;
if ( F_124 ( V_5 ) != F_15 ( V_12 ) )
continue;
V_378 = F_169 ( V_5 ) ;
if ( V_379 > 0 ) {
V_377 = V_158 ( V_15 + V_85 , V_100 ) ;
if ( F_359 ( V_15 , V_377 ) )
continue;
if ( V_378 == V_111 ) {
V_379 -- ;
continue;
}
if ( V_378 == V_126 ) {
F_6 ( V_5 ,
V_111 ) ;
F_126 ( V_12 , V_5 ,
V_111 ) ;
V_379 -- ;
continue;
}
} else if ( ! V_380 ) {
break;
}
if ( V_378 == V_111 ) {
F_6 ( V_5 , V_126 ) ;
F_126 ( V_12 , V_5 , V_126 ) ;
}
}
}
void T_12 F_363 ( unsigned long V_92 , int V_268 , unsigned long V_12 ,
unsigned long V_17 , enum V_382 V_383 )
{
struct V_5 * V_5 ;
unsigned long V_100 = V_17 + V_92 ;
unsigned long V_15 ;
struct V_12 * V_153 ;
if ( V_384 < V_100 - 1 )
V_384 = V_100 - 1 ;
V_153 = & F_299 ( V_268 ) -> V_291 [ V_12 ] ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 ++ ) {
if ( V_383 == V_385 ) {
if ( ! F_364 ( V_15 ) )
continue;
if ( ! F_365 ( V_15 , V_268 ) )
continue;
}
V_5 = F_127 ( V_15 ) ;
F_366 ( V_5 , V_12 , V_268 , V_15 ) ;
F_367 ( V_5 , V_12 , V_268 , V_15 ) ;
F_368 ( V_5 ) ;
F_22 ( V_5 ) ;
F_77 ( V_5 ) ;
F_369 ( V_5 ) ;
if ( ( V_153 -> V_18 <= V_15 )
&& ( V_15 < F_150 ( V_153 ) )
&& ! ( V_15 & ( V_85 - 1 ) ) )
F_6 ( V_5 , V_126 ) ;
F_116 ( & V_5 -> V_55 ) ;
#ifdef F_370
if ( ! F_371 ( V_12 ) )
F_372 ( V_5 , F_373 ( V_15 << V_386 ) ) ;
#endif
}
}
static void T_12 F_374 ( struct V_12 * V_12 )
{
unsigned int V_34 , V_124 ;
F_154 (order, t) {
F_116 ( & V_12 -> V_56 [ V_34 ] . V_60 [ V_124 ] ) ;
V_12 -> V_56 [ V_34 ] . V_57 = 0 ;
}
}
static int F_375 ( struct V_12 * V_12 )
{
#ifdef F_376
int V_115 ;
V_115 = V_12 -> V_84 / 1024 ;
if ( V_115 * V_81 > 512 * 1024 )
V_115 = ( 512 * 1024 ) / V_81 ;
V_115 /= 4 ;
if ( V_115 < 1 )
V_115 = 1 ;
V_115 = F_377 ( V_115 + V_115 / 2 ) - 1 ;
return V_115 ;
#else
return 0 ;
#endif
}
static void F_378 ( struct V_68 * V_69 , unsigned long V_90 ,
unsigned long V_115 )
{
V_69 -> V_115 = 1 ;
F_37 () ;
V_69 -> V_90 = V_90 ;
F_37 () ;
V_69 -> V_115 = V_115 ;
}
static void F_379 ( struct V_117 * V_37 , unsigned long V_115 )
{
F_378 ( & V_37 -> V_69 , 6 * V_115 , F_356 ( 1UL , 1 * V_115 ) ) ;
}
static void F_380 ( struct V_117 * V_37 )
{
struct V_68 * V_69 ;
int V_6 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_69 = & V_37 -> V_69 ;
V_69 -> V_67 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_116 ( & V_69 -> V_76 [ V_6 ] ) ;
}
static void F_344 ( struct V_117 * V_37 , unsigned long V_115 )
{
F_380 ( V_37 ) ;
F_379 ( V_37 , V_115 ) ;
}
static void F_381 ( struct V_117 * V_37 ,
unsigned long V_90 )
{
unsigned long V_115 = F_356 ( 1UL , V_90 / 4 ) ;
if ( ( V_90 / 4 ) > ( V_386 * 8 ) )
V_115 = V_386 * 8 ;
F_378 ( & V_37 -> V_69 , V_90 , V_115 ) ;
}
static void F_382 ( struct V_12 * V_12 ,
struct V_117 * V_69 )
{
if ( V_387 )
F_381 ( V_69 ,
( V_12 -> V_84 /
V_387 ) ) ;
else
F_379 ( V_69 , F_375 ( V_12 ) ) ;
}
static void T_12 F_383 ( struct V_12 * V_12 , int V_116 )
{
struct V_117 * V_69 = F_139 ( V_12 -> V_119 , V_116 ) ;
F_380 ( V_69 ) ;
F_382 ( V_12 , V_69 ) ;
}
static void T_12 F_353 ( struct V_12 * V_12 )
{
int V_116 ;
V_12 -> V_119 = F_384 ( struct V_117 ) ;
F_343 (cpu)
F_383 ( V_12 , V_116 ) ;
}
void T_2 F_385 ( void )
{
struct V_12 * V_12 ;
F_138 (zone)
F_353 ( V_12 ) ;
}
static T_13 T_14
int F_386 ( struct V_12 * V_12 , unsigned long V_388 )
{
int V_35 ;
T_7 V_389 ;
V_12 -> F_355 =
F_355 ( V_388 ) ;
V_12 -> F_357 =
F_357 ( V_12 -> F_355 ) ;
V_389 = V_12 -> F_355
* sizeof( V_390 ) ;
if ( ! F_387 () ) {
V_12 -> V_391 = ( V_390 * )
F_388 (
V_389 , V_12 -> V_392 -> V_366 ) ;
} else {
V_12 -> V_391 = F_389 ( V_389 ) ;
}
if ( ! V_12 -> V_391 )
return - V_152 ;
for ( V_35 = 0 ; V_35 < V_12 -> F_355 ; ++ V_35 )
F_390 ( V_12 -> V_391 + V_35 ) ;
return 0 ;
}
static T_12 void F_391 ( struct V_12 * V_12 )
{
V_12 -> V_119 = & V_369 ;
if ( F_313 ( V_12 ) )
F_24 ( V_393 L_77 ,
V_12 -> V_20 , V_12 -> V_313 ,
F_375 ( V_12 ) ) ;
}
int T_12 F_392 ( struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_92 ,
enum V_382 V_383 )
{
struct V_394 * V_289 = V_12 -> V_392 ;
int V_13 ;
V_13 = F_386 ( V_12 , V_92 ) ;
if ( V_13 )
return V_13 ;
V_289 -> V_321 = F_249 ( V_12 ) + 1 ;
V_12 -> V_18 = V_18 ;
F_393 ( V_395 , L_78 ,
L_79 ,
V_289 -> V_366 ,
( unsigned long ) F_249 ( V_12 ) ,
V_18 , ( V_18 + V_92 ) ) ;
F_374 ( V_12 ) ;
return 0 ;
}
int T_12 F_394 ( unsigned long V_15 )
{
unsigned long V_17 , V_100 ;
int V_268 ;
static unsigned long T_15 V_396 , V_397 ;
static int T_15 V_398 ;
if ( V_396 <= V_15 && V_15 < V_397 )
return V_398 ;
V_268 = F_395 ( V_15 , & V_17 , & V_100 ) ;
if ( V_268 != - 1 ) {
V_396 = V_17 ;
V_397 = V_100 ;
V_398 = V_268 ;
}
return V_268 ;
}
int T_12 F_396 ( unsigned long V_15 )
{
int V_268 ;
V_268 = F_394 ( V_15 ) ;
if ( V_268 >= 0 )
return V_268 ;
return 0 ;
}
bool T_12 F_365 ( unsigned long V_15 , int V_183 )
{
int V_268 ;
V_268 = F_394 ( V_15 ) ;
if ( V_268 >= 0 && V_268 != V_183 )
return false ;
return true ;
}
void T_2 F_397 ( int V_268 , unsigned long V_399 )
{
unsigned long V_17 , V_100 ;
int V_35 , V_400 ;
F_398 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_17 = V_158 ( V_17 , V_399 ) ;
V_100 = V_158 ( V_100 , V_399 ) ;
if ( V_17 < V_100 )
F_399 ( F_400 ( V_17 ) ,
( V_100 - V_17 ) << V_386 ,
V_400 ) ;
}
}
void T_2 F_401 ( int V_268 )
{
unsigned long V_17 , V_100 ;
int V_35 , V_400 ;
F_398 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_402 ( V_400 , V_17 , V_100 ) ;
}
void T_12 F_403 ( unsigned int V_268 ,
unsigned long * V_17 , unsigned long * V_100 )
{
unsigned long V_401 , V_402 ;
int V_35 ;
* V_17 = - 1UL ;
* V_100 = 0 ;
F_398 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_17 = V_158 ( * V_17 , V_401 ) ;
* V_100 = F_356 ( * V_100 , V_402 ) ;
}
if ( * V_17 == - 1UL )
* V_17 = 0 ;
}
static void T_2 F_404 ( void )
{
int V_403 ;
for ( V_403 = V_290 - 1 ; V_403 >= 0 ; V_403 -- ) {
if ( V_403 == V_404 )
continue;
if ( V_405 [ V_403 ] >
V_406 [ V_403 ] )
break;
}
F_44 ( V_403 == - 1 ) ;
V_407 = V_403 ;
}
static void T_12 F_405 ( int V_268 ,
unsigned long V_225 ,
unsigned long V_408 ,
unsigned long V_409 ,
unsigned long * V_18 ,
unsigned long * F_150 )
{
if ( V_410 [ V_268 ] ) {
if ( V_225 == V_404 ) {
* V_18 = V_410 [ V_268 ] ;
* F_150 = V_158 ( V_409 ,
V_405 [ V_407 ] ) ;
} else if ( * V_18 < V_410 [ V_268 ] &&
* F_150 > V_410 [ V_268 ] ) {
* F_150 = V_410 [ V_268 ] ;
} else if ( * V_18 >= V_410 [ V_268 ] )
* V_18 = * F_150 ;
}
}
static unsigned long T_12 F_406 ( int V_268 ,
unsigned long V_225 ,
unsigned long V_408 ,
unsigned long V_409 ,
unsigned long * V_411 )
{
unsigned long V_18 , F_150 ;
V_18 = V_406 [ V_225 ] ;
F_150 = V_405 [ V_225 ] ;
F_405 ( V_268 , V_225 ,
V_408 , V_409 ,
& V_18 , & F_150 ) ;
if ( F_150 < V_408 || V_18 > V_409 )
return 0 ;
F_150 = V_158 ( F_150 , V_409 ) ;
V_18 = F_356 ( V_18 , V_408 ) ;
return F_150 - V_18 ;
}
unsigned long T_12 F_407 ( int V_268 ,
unsigned long V_412 ,
unsigned long V_413 )
{
unsigned long V_414 = V_413 - V_412 ;
unsigned long V_17 , V_100 ;
int V_35 ;
F_398 (i, nid, &start_pfn, &end_pfn, NULL) {
V_17 = F_408 ( V_17 , V_412 , V_413 ) ;
V_100 = F_408 ( V_100 , V_412 , V_413 ) ;
V_414 -= V_100 - V_17 ;
}
return V_414 ;
}
unsigned long T_2 F_409 ( unsigned long V_17 ,
unsigned long V_100 )
{
return F_407 ( V_350 , V_17 , V_100 ) ;
}
static unsigned long T_12 F_410 ( int V_268 ,
unsigned long V_225 ,
unsigned long V_408 ,
unsigned long V_409 ,
unsigned long * V_411 )
{
unsigned long V_415 = V_406 [ V_225 ] ;
unsigned long V_416 = V_405 [ V_225 ] ;
unsigned long V_18 , F_150 ;
V_18 = F_408 ( V_408 , V_415 , V_416 ) ;
F_150 = F_408 ( V_409 , V_415 , V_416 ) ;
F_405 ( V_268 , V_225 ,
V_408 , V_409 ,
& V_18 , & F_150 ) ;
return F_407 ( V_268 , V_18 , F_150 ) ;
}
static inline unsigned long T_12 F_406 ( int V_268 ,
unsigned long V_225 ,
unsigned long V_408 ,
unsigned long V_409 ,
unsigned long * V_417 )
{
return V_417 [ V_225 ] ;
}
static inline unsigned long T_12 F_410 ( int V_268 ,
unsigned long V_225 ,
unsigned long V_408 ,
unsigned long V_409 ,
unsigned long * V_418 )
{
if ( ! V_418 )
return 0 ;
return V_418 [ V_225 ] ;
}
static void T_12 F_411 ( struct V_394 * V_289 ,
unsigned long V_408 ,
unsigned long V_409 ,
unsigned long * V_417 ,
unsigned long * V_418 )
{
unsigned long V_419 , V_420 = 0 ;
enum V_225 V_35 ;
for ( V_35 = 0 ; V_35 < V_290 ; V_35 ++ )
V_420 += F_406 ( V_289 -> V_366 , V_35 ,
V_408 ,
V_409 ,
V_417 ) ;
V_289 -> V_421 = V_420 ;
V_419 = V_420 ;
for ( V_35 = 0 ; V_35 < V_290 ; V_35 ++ )
V_419 -=
F_410 ( V_289 -> V_366 , V_35 ,
V_408 , V_409 ,
V_418 ) ;
V_289 -> V_422 = V_419 ;
F_24 ( V_393 L_80 , V_289 -> V_366 ,
V_419 ) ;
}
static unsigned long T_2 F_412 ( unsigned long V_18 , unsigned long V_423 )
{
unsigned long V_424 ;
V_423 += V_18 & ( V_85 - 1 ) ;
V_424 = F_362 ( V_423 , V_85 ) ;
V_424 = V_424 >> V_87 ;
V_424 *= V_425 ;
V_424 = F_362 ( V_424 , 8 * sizeof( unsigned long ) ) ;
return V_424 / 8 ;
}
static void T_2 F_413 ( struct V_394 * V_289 ,
struct V_12 * V_12 ,
unsigned long V_18 ,
unsigned long V_423 )
{
unsigned long V_424 = F_412 ( V_18 , V_423 ) ;
V_12 -> V_426 = NULL ;
if ( V_424 )
V_12 -> V_426 =
F_388 ( V_424 ,
V_289 -> V_366 ) ;
}
static inline void F_413 ( struct V_394 * V_289 , struct V_12 * V_12 ,
unsigned long V_18 , unsigned long V_423 ) {}
void T_16 F_414 ( void )
{
unsigned int V_34 ;
if ( V_87 )
return;
if ( V_427 > V_386 )
V_34 = V_428 ;
else
V_34 = V_44 - 1 ;
V_87 = V_34 ;
}
void T_16 F_414 ( void )
{
}
static unsigned long T_16 F_415 ( unsigned long V_19 ,
unsigned long V_313 )
{
unsigned long V_107 = V_19 ;
if ( V_19 > V_313 + ( V_313 >> 4 ) &&
F_207 ( V_429 ) )
V_107 = V_313 ;
return F_284 ( V_107 * sizeof( struct V_5 ) ) >> V_386 ;
}
static void T_16 F_416 ( struct V_394 * V_289 ,
unsigned long V_408 , unsigned long V_409 ,
unsigned long * V_417 , unsigned long * V_418 )
{
enum V_225 V_352 ;
int V_268 = V_289 -> V_366 ;
unsigned long V_18 = V_289 -> V_408 ;
int V_13 ;
F_417 ( V_289 ) ;
#ifdef F_418
F_419 ( & V_289 -> V_430 ) ;
V_289 -> V_431 = 0 ;
V_289 -> V_432 = V_26 ;
#endif
F_390 ( & V_289 -> V_433 ) ;
F_390 ( & V_289 -> V_434 ) ;
F_420 ( V_289 ) ;
for ( V_352 = 0 ; V_352 < V_290 ; V_352 ++ ) {
struct V_12 * V_12 = V_289 -> V_291 + V_352 ;
unsigned long V_92 , V_435 , V_436 , V_437 ;
V_92 = F_406 ( V_268 , V_352 , V_408 ,
V_409 , V_417 ) ;
V_435 = V_436 = V_92 - F_410 ( V_268 , V_352 ,
V_408 ,
V_409 ,
V_418 ) ;
V_437 = F_415 ( V_92 , V_435 ) ;
if ( V_436 >= V_437 ) {
V_436 -= V_437 ;
if ( V_437 )
F_24 ( V_393
L_81 ,
V_374 [ V_352 ] , V_437 ) ;
} else
F_24 ( V_327
L_82 ,
V_374 [ V_352 ] , V_437 , V_436 ) ;
if ( V_352 == 0 && V_436 > V_438 ) {
V_436 -= V_438 ;
F_24 ( V_393 L_83 ,
V_374 [ 0 ] , V_438 ) ;
}
if ( ! F_371 ( V_352 ) )
V_439 += V_436 ;
else if ( V_439 > V_437 * 2 )
V_439 -= V_437 ;
V_440 += V_436 ;
V_12 -> V_19 = V_92 ;
V_12 -> V_313 = V_435 ;
V_12 -> V_84 = F_371 ( V_352 ) ? V_435 : V_436 ;
#ifdef V_193
V_12 -> V_183 = V_268 ;
V_12 -> V_441 = ( V_436 * V_442 )
/ 100 ;
V_12 -> V_443 = ( V_436 * V_444 ) / 100 ;
#endif
V_12 -> V_20 = V_374 [ V_352 ] ;
F_419 ( & V_12 -> V_72 ) ;
F_419 ( & V_12 -> V_445 ) ;
F_421 ( V_12 ) ;
V_12 -> V_392 = V_289 ;
F_391 ( V_12 ) ;
F_244 ( V_12 , V_135 , V_12 -> V_84 ) ;
F_422 ( & V_12 -> V_446 ) ;
if ( ! V_92 )
continue;
F_414 () ;
F_413 ( V_289 , V_12 , V_18 , V_92 ) ;
V_13 = F_392 ( V_12 , V_18 ,
V_92 , V_385 ) ;
F_123 ( V_13 ) ;
F_423 ( V_92 , V_268 , V_352 , V_18 ) ;
V_18 += V_92 ;
}
}
static void T_14 F_424 ( struct V_394 * V_289 )
{
if ( ! V_289 -> V_421 )
return;
#ifdef F_425
if ( ! V_289 -> V_447 ) {
unsigned long V_92 , V_448 , V_272 ;
struct V_5 * V_449 ;
V_448 = V_289 -> V_408 & ~ ( V_88 - 1 ) ;
V_272 = F_426 ( V_289 ) ;
V_272 = F_427 ( V_272 , V_88 ) ;
V_92 = ( V_272 - V_448 ) * sizeof( struct V_5 ) ;
V_449 = F_428 ( V_289 -> V_366 , V_92 ) ;
if ( ! V_449 )
V_449 = F_388 ( V_92 ,
V_289 -> V_366 ) ;
V_289 -> V_447 = V_449 + ( V_289 -> V_408 - V_448 ) ;
}
#ifndef F_429
if ( V_289 == F_299 ( 0 ) ) {
V_450 = F_299 ( 0 ) -> V_447 ;
#ifdef F_430
if ( F_10 ( V_450 ) != V_289 -> V_408 )
V_450 -= ( V_289 -> V_408 - V_451 ) ;
#endif
}
#endif
#endif
}
void T_16 F_431 ( int V_268 , unsigned long * V_417 ,
unsigned long V_408 , unsigned long * V_418 )
{
T_8 * V_289 = F_299 ( V_268 ) ;
unsigned long V_17 = 0 ;
unsigned long V_100 = 0 ;
F_2 ( V_289 -> V_321 || V_289 -> V_155 ) ;
V_289 -> V_366 = V_268 ;
V_289 -> V_408 = V_408 ;
#ifdef F_430
F_403 ( V_268 , & V_17 , & V_100 ) ;
#endif
F_411 ( V_289 , V_17 , V_100 ,
V_417 , V_418 ) ;
F_424 ( V_289 ) ;
#ifdef F_425
F_24 ( V_393 L_84 ,
V_268 , ( unsigned long ) V_289 ,
( unsigned long ) V_289 -> V_447 ) ;
#endif
F_416 ( V_289 , V_17 , V_100 ,
V_417 , V_418 ) ;
}
void T_2 F_432 ( void )
{
unsigned int V_183 ;
unsigned int V_452 = 0 ;
F_433 (node, node_possible_map)
V_452 = V_183 ;
V_453 = V_452 + 1 ;
}
unsigned long T_2 F_434 ( void )
{
unsigned long V_454 = 0 , V_455 = 0 ;
unsigned long V_448 , V_272 , V_456 ;
int V_398 = - 1 ;
int V_35 , V_268 ;
F_398 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_448 || V_398 < 0 || V_398 == V_268 ) {
V_398 = V_268 ;
V_455 = V_272 ;
continue;
}
V_456 = ~ ( ( 1 << F_435 ( V_448 ) ) - 1 ) ;
while ( V_456 && V_455 <= ( V_448 & ( V_456 << 1 ) ) )
V_456 <<= 1 ;
V_454 |= V_456 ;
}
return ~ V_454 + 1 ;
}
static unsigned long T_2 F_436 ( int V_268 )
{
unsigned long V_457 = V_458 ;
unsigned long V_17 ;
int V_35 ;
F_398 (i, nid, &start_pfn, NULL, NULL)
V_457 = V_158 ( V_457 , V_17 ) ;
if ( V_457 == V_458 ) {
F_24 ( V_327
L_85 , V_268 ) ;
return 0 ;
}
return V_457 ;
}
unsigned long T_2 F_437 ( void )
{
return F_436 ( V_350 ) ;
}
static unsigned long T_2 F_438 ( void )
{
unsigned long V_420 = 0 ;
unsigned long V_17 , V_100 ;
int V_35 , V_268 ;
F_398 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_107 = V_100 - V_17 ;
V_420 += V_107 ;
if ( V_107 )
F_439 ( V_268 , V_177 ) ;
}
return V_420 ;
}
static void T_2 F_440 ( void )
{
int V_35 , V_268 ;
unsigned long V_459 ;
unsigned long V_460 , V_461 ;
T_5 V_462 = V_176 [ V_177 ] ;
unsigned long V_420 = F_438 () ;
int V_463 = F_334 ( V_176 [ V_177 ] ) ;
struct V_464 * V_465 ;
F_404 () ;
if ( F_441 () ) {
F_442 (memory, r) {
if ( ! F_443 ( V_465 ) )
continue;
V_268 = V_465 -> V_268 ;
V_459 = F_444 ( V_465 -> V_466 ) ;
V_410 [ V_268 ] = V_410 [ V_268 ] ?
V_158 ( V_459 , V_410 [ V_268 ] ) :
V_459 ;
}
goto V_467;
}
if ( V_468 ) {
unsigned long V_469 ;
V_468 =
F_362 ( V_468 , V_88 ) ;
V_469 = V_420 - V_468 ;
V_470 = F_356 ( V_470 , V_469 ) ;
}
if ( ! V_470 )
goto V_27;
V_459 = V_406 [ V_407 ] ;
V_254:
V_460 = V_470 / V_463 ;
F_327 (nid, N_MEMORY) {
unsigned long V_17 , V_100 ;
if ( V_470 < V_460 )
V_460 = V_470 / V_463 ;
V_461 = V_460 ;
F_398 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_471 ;
V_17 = F_356 ( V_17 , V_410 [ V_268 ] ) ;
if ( V_17 >= V_100 )
continue;
if ( V_17 < V_459 ) {
unsigned long V_472 ;
V_472 = V_158 ( V_100 , V_459 )
- V_17 ;
V_461 -= V_158 ( V_472 ,
V_461 ) ;
V_470 -= V_158 ( V_472 ,
V_470 ) ;
if ( V_100 <= V_459 ) {
V_410 [ V_268 ] = V_100 ;
continue;
}
V_17 = V_459 ;
}
V_471 = V_100 - V_17 ;
if ( V_471 > V_461 )
V_471 = V_461 ;
V_410 [ V_268 ] = V_17 + V_471 ;
V_470 -= V_158 ( V_470 ,
V_471 ) ;
V_461 -= V_471 ;
if ( ! V_461 )
break;
}
}
V_463 -- ;
if ( V_463 && V_470 > V_463 )
goto V_254;
V_467:
for ( V_268 = 0 ; V_268 < V_350 ; V_268 ++ )
V_410 [ V_268 ] =
F_362 ( V_410 [ V_268 ] , V_88 ) ;
V_27:
V_176 [ V_177 ] = V_462 ;
}
static void F_445 ( T_8 * V_289 , int V_268 )
{
enum V_225 V_225 ;
if ( V_177 == V_473 )
return;
for ( V_225 = 0 ; V_225 <= V_404 - 1 ; V_225 ++ ) {
struct V_12 * V_12 = & V_289 -> V_291 [ V_225 ] ;
if ( F_313 ( V_12 ) ) {
F_439 ( V_268 , V_474 ) ;
if ( V_473 != V_474 &&
V_225 <= V_228 )
F_439 ( V_268 , V_473 ) ;
break;
}
}
}
void T_2 F_446 ( unsigned long * V_123 )
{
unsigned long V_17 , V_100 ;
int V_35 , V_268 ;
memset ( V_406 , 0 ,
sizeof( V_406 ) ) ;
memset ( V_405 , 0 ,
sizeof( V_405 ) ) ;
V_406 [ 0 ] = F_437 () ;
V_405 [ 0 ] = V_123 [ 0 ] ;
for ( V_35 = 1 ; V_35 < V_290 ; V_35 ++ ) {
if ( V_35 == V_404 )
continue;
V_406 [ V_35 ] =
V_405 [ V_35 - 1 ] ;
V_405 [ V_35 ] =
F_356 ( V_123 [ V_35 ] , V_406 [ V_35 ] ) ;
}
V_406 [ V_404 ] = 0 ;
V_405 [ V_404 ] = 0 ;
memset ( V_410 , 0 , sizeof( V_410 ) ) ;
F_440 () ;
F_24 ( L_86 ) ;
for ( V_35 = 0 ; V_35 < V_290 ; V_35 ++ ) {
if ( V_35 == V_404 )
continue;
F_24 ( V_475 L_87 , V_374 [ V_35 ] ) ;
if ( V_406 [ V_35 ] ==
V_405 [ V_35 ] )
F_24 ( V_475 L_88 ) ;
else
F_24 ( V_475 L_89 ,
V_406 [ V_35 ] << V_386 ,
( V_405 [ V_35 ]
<< V_386 ) - 1 ) ;
}
F_24 ( L_90 ) ;
for ( V_35 = 0 ; V_35 < V_350 ; V_35 ++ ) {
if ( V_410 [ V_35 ] )
F_24 ( L_91 , V_35 ,
V_410 [ V_35 ] << V_386 ) ;
}
F_24 ( L_92 ) ;
F_398 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_24 ( L_93 , V_268 ,
V_17 << V_386 , ( V_100 << V_386 ) - 1 ) ;
F_447 () ;
F_432 () ;
F_333 (nid) {
T_8 * V_289 = F_299 ( V_268 ) ;
F_431 ( V_268 , NULL ,
F_436 ( V_268 ) , NULL ) ;
if ( V_289 -> V_422 )
F_439 ( V_268 , V_177 ) ;
F_445 ( V_289 , V_268 ) ;
}
}
static int T_2 F_448 ( char * V_37 , unsigned long * V_476 )
{
unsigned long long V_477 ;
if ( ! V_37 )
return - V_328 ;
V_477 = F_449 ( V_37 , & V_37 ) ;
* V_476 = V_477 >> V_386 ;
F_2 ( ( V_477 >> V_386 ) > V_458 ) ;
return 0 ;
}
static int T_2 F_450 ( char * V_37 )
{
return F_448 ( V_37 , & V_470 ) ;
}
static int T_2 F_451 ( char * V_37 )
{
return F_448 ( V_37 , & V_468 ) ;
}
void F_112 ( struct V_5 * V_5 , long V_67 )
{
F_79 ( & V_478 ) ;
F_18 ( V_5 ) -> V_84 += V_67 ;
V_281 += V_67 ;
#ifdef F_301
if ( F_95 ( V_5 ) )
V_286 += V_67 ;
#endif
F_88 ( & V_478 ) ;
}
unsigned long F_452 ( void * V_448 , void * V_272 , int V_479 , char * V_322 )
{
void * V_355 ;
unsigned long V_107 = 0 ;
V_448 = ( void * ) F_284 ( ( unsigned long ) V_448 ) ;
V_272 = ( void * ) ( ( unsigned long ) V_272 & V_480 ) ;
for ( V_355 = V_448 ; V_355 < V_272 ; V_355 += V_81 , V_107 ++ ) {
if ( ( unsigned int ) V_479 <= 0xFF )
memset ( V_355 , V_479 , V_81 ) ;
F_453 ( F_167 ( V_355 ) ) ;
}
if ( V_107 && V_322 )
F_454 ( L_94 ,
V_322 , V_107 << ( V_386 - 10 ) , V_448 , V_272 ) ;
return V_107 ;
}
void F_455 ( struct V_5 * V_5 )
{
F_456 ( V_5 ) ;
V_281 ++ ;
F_18 ( V_5 ) -> V_84 ++ ;
V_286 ++ ;
}
void T_2 F_457 ( const char * V_137 )
{
unsigned long V_481 , V_482 , V_483 , V_484 , V_485 ;
unsigned long V_486 , V_487 ;
V_481 = F_458 () ;
V_482 = V_488 - V_489 ;
V_483 = V_490 - V_491 ;
V_484 = V_492 - V_493 ;
V_485 = V_494 - V_495 ;
V_487 = V_496 - V_497 ;
V_486 = V_498 - V_499 ;
#define F_459 ( V_448 , V_272 , V_92 , V_355 , T_17 ) \
do { \
if (start <= pos && pos < end && size > adj) \
size -= adj; \
} while (0)
F_459 ( V_497 , V_496 , V_487 ,
V_499 , V_486 ) ;
F_459 ( V_489 , V_488 , V_482 , V_499 , V_486 ) ;
F_459 ( V_491 , V_490 , V_483 , V_497 , V_487 ) ;
F_459 ( V_489 , V_488 , V_482 , V_493 , V_484 ) ;
F_459 ( V_491 , V_490 , V_483 , V_493 , V_484 ) ;
#undef F_459
F_24 ( L_95
L_96
L_97
#ifdef F_301
L_98
#endif
L_99 ,
F_460 () << ( V_386 - 10 ) , V_481 << ( V_386 - 10 ) ,
V_482 >> 10 , V_483 >> 10 , V_484 >> 10 ,
( V_487 + V_486 ) >> 10 , V_485 >> 10 ,
( V_481 - V_281 ) << ( V_386 - 10 ) ,
#ifdef F_301
V_286 << ( V_386 - 10 ) ,
#endif
V_137 ? L_100 : L_101 , V_137 ? V_137 : L_101 ) ;
}
void T_2 F_461 ( unsigned long V_500 )
{
V_438 = V_500 ;
}
void T_2 F_462 ( unsigned long * V_417 )
{
F_431 ( 0 , V_417 ,
F_463 ( V_501 ) >> V_386 , NULL ) ;
}
static int F_464 ( struct V_502 * V_368 ,
unsigned long V_503 , void * V_504 )
{
int V_116 = ( unsigned long ) V_504 ;
if ( V_503 == V_505 || V_503 == V_506 ) {
F_465 ( V_116 ) ;
F_137 ( V_116 ) ;
F_466 ( V_116 ) ;
F_467 ( V_116 ) ;
}
return V_507 ;
}
void T_2 F_468 ( void )
{
F_469 ( F_464 , 0 ) ;
}
static void F_470 ( void )
{
struct V_394 * V_289 ;
unsigned long V_508 = 0 ;
enum V_225 V_35 , V_352 ;
F_471 (pgdat) {
for ( V_35 = 0 ; V_35 < V_290 ; V_35 ++ ) {
struct V_12 * V_12 = V_289 -> V_291 + V_35 ;
unsigned long F_356 = 0 ;
for ( V_352 = V_35 ; V_352 < V_290 ; V_352 ++ ) {
if ( V_12 -> V_159 [ V_352 ] > F_356 )
F_356 = V_12 -> V_159 [ V_352 ] ;
}
F_356 += F_245 ( V_12 ) ;
if ( F_356 > V_12 -> V_84 )
F_356 = V_12 -> V_84 ;
V_508 += F_356 ;
V_12 -> V_509 = F_356 ;
}
}
V_509 = V_508 ;
V_510 = V_508 ;
}
static void F_472 ( void )
{
struct V_394 * V_289 ;
enum V_225 V_352 , V_511 ;
F_471 (pgdat) {
for ( V_352 = 0 ; V_352 < V_290 ; V_352 ++ ) {
struct V_12 * V_12 = V_289 -> V_291 + V_352 ;
unsigned long V_84 = V_12 -> V_84 ;
V_12 -> V_159 [ V_352 ] = 0 ;
V_511 = V_352 ;
while ( V_511 ) {
struct V_12 * V_512 ;
V_511 -- ;
if ( V_513 [ V_511 ] < 1 )
V_513 [ V_511 ] = 1 ;
V_512 = V_289 -> V_291 + V_511 ;
V_512 -> V_159 [ V_352 ] = V_84 /
V_513 [ V_511 ] ;
V_84 += V_512 -> V_84 ;
}
}
}
F_470 () ;
}
static void F_473 ( void )
{
unsigned long V_514 = V_515 >> ( V_386 - 10 ) ;
unsigned long V_516 = 0 ;
struct V_12 * V_12 ;
unsigned long V_64 ;
F_474 (zone) {
if ( ! F_475 ( V_12 ) )
V_516 += V_12 -> V_84 ;
}
F_474 (zone) {
T_18 V_296 ;
F_149 ( & V_12 -> V_72 , V_64 ) ;
V_296 = ( T_18 ) V_514 * V_12 -> V_84 ;
F_476 ( V_296 , V_516 ) ;
if ( F_475 ( V_12 ) ) {
unsigned long V_517 ;
V_517 = V_12 -> V_84 / 1024 ;
V_517 = F_408 ( V_517 , V_518 , 128UL ) ;
V_12 -> V_128 [ V_519 ] = V_517 ;
} else {
V_12 -> V_128 [ V_519 ] = V_296 ;
}
V_12 -> V_128 [ V_520 ] = F_307 ( V_12 ) + ( V_296 >> 2 ) ;
V_12 -> V_128 [ V_521 ] = F_307 ( V_12 ) + ( V_296 >> 1 ) ;
F_86 ( V_12 , V_135 ,
F_245 ( V_12 ) -
F_170 ( V_12 ) -
F_190 ( V_12 , V_135 ) ) ;
F_361 ( V_12 ) ;
F_157 ( & V_12 -> V_72 , V_64 ) ;
}
F_470 () ;
}
void F_477 ( void )
{
F_320 ( & V_341 ) ;
F_473 () ;
F_323 ( & V_341 ) ;
}
static void T_12 F_478 ( struct V_12 * V_12 )
{
unsigned int V_522 , V_523 ;
V_522 = V_12 -> V_84 >> ( 30 - V_386 ) ;
if ( V_522 )
V_523 = F_479 ( 10 * V_522 ) ;
else
V_523 = 1 ;
V_12 -> V_524 = V_523 ;
}
static void T_12 F_480 ( void )
{
struct V_12 * V_12 ;
F_474 (zone)
F_478 ( V_12 ) ;
}
int T_12 F_481 ( void )
{
unsigned long V_525 ;
int V_526 ;
V_525 = F_291 () * ( V_81 >> 10 ) ;
V_526 = F_479 ( V_525 * 16 ) ;
if ( V_526 > V_527 ) {
V_515 = V_526 ;
if ( V_515 < 128 )
V_515 = 128 ;
if ( V_515 > 65536 )
V_515 = 65536 ;
} else {
F_217 ( L_102 ,
V_526 , V_527 ) ;
}
F_477 () ;
F_482 () ;
F_472 () ;
F_480 () ;
return 0 ;
}
int F_483 ( struct V_331 * V_332 , int V_333 ,
void T_9 * V_334 , T_7 * V_335 , T_10 * V_336 )
{
int V_528 ;
V_528 = F_484 ( V_332 , V_333 , V_334 , V_335 , V_336 ) ;
if ( V_528 )
return V_528 ;
if ( V_333 ) {
V_527 = V_515 ;
F_477 () ;
}
return 0 ;
}
int F_485 ( struct V_331 * V_332 , int V_333 ,
void T_9 * V_334 , T_7 * V_335 , T_10 * V_336 )
{
struct V_12 * V_12 ;
int V_528 ;
V_528 = F_484 ( V_332 , V_333 , V_334 , V_335 , V_336 ) ;
if ( V_528 )
return V_528 ;
F_474 (zone)
V_12 -> V_441 = ( V_12 -> V_84 *
V_442 ) / 100 ;
return 0 ;
}
int F_486 ( struct V_331 * V_332 , int V_333 ,
void T_9 * V_334 , T_7 * V_335 , T_10 * V_336 )
{
struct V_12 * V_12 ;
int V_528 ;
V_528 = F_484 ( V_332 , V_333 , V_334 , V_335 , V_336 ) ;
if ( V_528 )
return V_528 ;
F_474 (zone)
V_12 -> V_443 = ( V_12 -> V_84 *
V_444 ) / 100 ;
return 0 ;
}
int F_487 ( struct V_331 * V_332 , int V_333 ,
void T_9 * V_334 , T_7 * V_335 , T_10 * V_336 )
{
F_484 ( V_332 , V_333 , V_334 , V_335 , V_336 ) ;
F_472 () ;
return 0 ;
}
int F_488 ( struct V_331 * V_332 , int V_333 ,
void T_9 * V_334 , T_7 * V_335 , T_10 * V_336 )
{
struct V_12 * V_12 ;
int V_529 ;
int V_13 ;
F_320 ( & V_530 ) ;
V_529 = V_387 ;
V_13 = F_484 ( V_332 , V_333 , V_334 , V_335 , V_336 ) ;
if ( ! V_333 || V_13 < 0 )
goto V_27;
if ( V_387 &&
V_387 < V_531 ) {
V_387 = V_529 ;
V_13 = - V_328 ;
goto V_27;
}
if ( V_387 == V_529 )
goto V_27;
F_138 (zone) {
unsigned int V_116 ;
F_343 (cpu)
F_382 ( V_12 ,
F_139 ( V_12 -> V_119 , V_116 ) ) ;
}
V_27:
F_323 ( & V_530 ) ;
return V_13 ;
}
static int T_2 F_489 ( char * V_137 )
{
if ( ! V_137 )
return 0 ;
V_532 = F_490 ( V_137 , & V_137 , 0 ) ;
return 1 ;
}
void * T_2 F_491 ( const char * V_533 ,
unsigned long V_534 ,
unsigned long V_535 ,
int V_536 ,
int V_64 ,
unsigned int * V_537 ,
unsigned int * V_538 ,
unsigned long V_539 ,
unsigned long V_540 )
{
unsigned long long F_356 = V_540 ;
unsigned long V_541 , V_92 ;
void * V_332 = NULL ;
if ( ! V_535 ) {
V_535 = V_439 ;
if ( V_386 < 20 )
V_535 = F_492 ( V_535 , ( 1 << 20 ) / V_81 ) ;
if ( V_536 > V_386 )
V_535 >>= ( V_536 - V_386 ) ;
else
V_535 <<= ( V_386 - V_536 ) ;
if ( F_7 ( V_64 & V_542 ) ) {
F_2 ( ! ( V_64 & V_543 ) ) ;
if ( ! ( V_535 >> * V_537 ) ) {
V_535 = 1UL << * V_537 ;
F_123 ( ! V_535 ) ;
}
} else if ( F_7 ( ( V_535 * V_534 ) < V_81 ) )
V_535 = V_81 / V_534 ;
}
V_535 = F_493 ( V_535 ) ;
if ( F_356 == 0 ) {
F_356 = ( ( unsigned long long ) V_440 << V_386 ) >> 4 ;
F_476 ( F_356 , V_534 ) ;
}
F_356 = V_158 ( F_356 , 0x80000000ULL ) ;
if ( V_535 < V_539 )
V_535 = V_539 ;
if ( V_535 > F_356 )
V_535 = F_356 ;
V_541 = F_494 ( V_535 ) ;
do {
V_92 = V_534 << V_541 ;
if ( V_64 & V_543 )
V_332 = F_495 ( V_92 , 0 ) ;
else if ( V_532 )
V_332 = F_496 ( V_92 , V_544 , V_545 ) ;
else {
if ( F_287 ( V_92 ) < V_44 ) {
V_332 = F_286 ( V_92 , V_544 ) ;
F_497 ( V_332 , V_92 , 1 , V_544 ) ;
}
}
} while ( ! V_332 && V_92 > V_81 && -- V_541 );
if ( ! V_332 )
F_498 ( L_103 , V_533 ) ;
F_24 ( V_47 L_104 ,
V_533 ,
( 1UL << V_541 ) ,
F_494 ( V_92 ) - V_386 ,
V_92 ) ;
if ( V_537 )
* V_537 = V_541 ;
if ( V_538 )
* V_538 = ( 1 << V_541 ) - 1 ;
return V_332 ;
}
static inline unsigned long * F_499 ( struct V_12 * V_12 ,
unsigned long V_15 )
{
#ifdef V_429
return F_500 ( V_15 ) -> V_426 ;
#else
return V_12 -> V_426 ;
#endif
}
static inline int F_501 ( struct V_12 * V_12 , unsigned long V_15 )
{
#ifdef V_429
V_15 &= ( V_546 - 1 ) ;
return ( V_15 >> V_87 ) * V_425 ;
#else
V_15 = V_15 - F_502 ( V_12 -> V_18 , V_85 ) ;
return ( V_15 >> V_87 ) * V_425 ;
#endif
}
unsigned long F_503 ( struct V_5 * V_5 , unsigned long V_15 ,
unsigned long V_547 ,
unsigned long V_456 )
{
struct V_12 * V_12 ;
unsigned long * V_548 ;
unsigned long V_549 , V_550 ;
unsigned long V_551 ;
V_12 = F_18 ( V_5 ) ;
V_548 = F_499 ( V_12 , V_15 ) ;
V_549 = F_501 ( V_12 , V_15 ) ;
V_550 = V_549 / V_552 ;
V_549 &= ( V_552 - 1 ) ;
V_551 = V_548 [ V_550 ] ;
V_549 += V_547 ;
return ( V_551 >> ( V_552 - V_549 - 1 ) ) & V_456 ;
}
void F_504 ( struct V_5 * V_5 , unsigned long V_64 ,
unsigned long V_15 ,
unsigned long V_547 ,
unsigned long V_456 )
{
struct V_12 * V_12 ;
unsigned long * V_548 ;
unsigned long V_549 , V_550 ;
unsigned long V_553 , V_551 ;
F_211 ( V_425 != 4 ) ;
V_12 = F_18 ( V_5 ) ;
V_548 = F_499 ( V_12 , V_15 ) ;
V_549 = F_501 ( V_12 , V_15 ) ;
V_550 = V_549 / V_552 ;
V_549 &= ( V_552 - 1 ) ;
F_62 ( ! F_12 ( V_12 , V_15 ) , V_5 ) ;
V_549 += V_547 ;
V_456 <<= ( V_552 - V_549 - 1 ) ;
V_64 <<= ( V_552 - V_549 - 1 ) ;
V_551 = F_136 ( V_548 [ V_550 ] ) ;
for (; ; ) {
V_553 = F_505 ( & V_548 [ V_550 ] , V_551 , ( V_551 & ~ V_456 ) | V_64 ) ;
if ( V_551 == V_553 )
break;
V_551 = V_553 ;
}
}
bool F_506 ( struct V_12 * V_12 , struct V_5 * V_5 , int V_67 ,
bool V_554 )
{
unsigned long V_15 , V_555 , V_556 ;
int V_77 ;
if ( F_249 ( V_12 ) == V_404 )
return false ;
V_77 = F_169 ( V_5 ) ;
if ( V_77 == V_126 || F_87 ( V_77 ) )
return false ;
V_15 = F_10 ( V_5 ) ;
for ( V_556 = 0 , V_555 = 0 ; V_555 < V_85 ; V_555 ++ ) {
unsigned long V_557 = V_15 + V_555 ;
if ( ! F_17 ( V_557 ) )
continue;
V_5 = F_127 ( V_557 ) ;
if ( F_507 ( V_5 ) ) {
V_555 = F_492 ( V_555 + 1 , 1 << F_31 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_75 ( & V_5 -> V_63 ) ) {
if ( F_65 ( V_5 ) )
V_555 += ( 1 << F_61 ( V_5 ) ) - 1 ;
continue;
}
if ( V_554 && F_21 ( V_5 ) )
continue;
if ( ! F_508 ( V_5 ) )
V_556 ++ ;
if ( V_556 > V_67 )
return true ;
}
return false ;
}
bool F_509 ( struct V_5 * V_5 )
{
struct V_12 * V_12 ;
unsigned long V_15 ;
if ( ! F_341 ( F_124 ( V_5 ) ) )
return false ;
V_12 = F_18 ( V_5 ) ;
V_15 = F_10 ( V_5 ) ;
if ( ! F_12 ( V_12 , V_15 ) )
return false ;
return ! F_506 ( V_12 , V_5 , 0 , true ) ;
}
static unsigned long F_510 ( unsigned long V_15 )
{
return V_15 & ~ ( F_511 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_512 ( unsigned long V_15 )
{
return F_427 ( V_15 , F_511 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static int F_513 ( struct V_558 * V_559 ,
unsigned long V_448 , unsigned long V_272 )
{
unsigned long V_560 ;
unsigned long V_15 = V_448 ;
unsigned int V_561 = 0 ;
int V_13 = 0 ;
F_514 () ;
while ( V_15 < V_272 || ! F_80 ( & V_559 -> V_562 ) ) {
if ( F_515 ( V_30 ) ) {
V_13 = - V_563 ;
break;
}
if ( F_80 ( & V_559 -> V_562 ) ) {
V_559 -> V_564 = 0 ;
V_15 = F_516 ( V_559 -> V_12 , V_559 ,
V_15 , V_272 , true ) ;
if ( ! V_15 ) {
V_13 = - V_563 ;
break;
}
V_561 = 0 ;
} else if ( ++ V_561 == 5 ) {
V_13 = V_13 < 0 ? V_13 : - V_565 ;
break;
}
V_560 = F_517 ( V_559 -> V_12 ,
& V_559 -> V_562 ) ;
V_559 -> V_564 -= V_560 ;
V_13 = F_518 ( & V_559 -> V_562 , V_566 ,
NULL , 0 , V_559 -> V_145 , V_567 ) ;
}
if ( V_13 < 0 ) {
F_519 ( & V_559 -> V_562 ) ;
return V_13 ;
}
return 0 ;
}
int F_520 ( unsigned long V_448 , unsigned long V_272 ,
unsigned V_6 )
{
unsigned long V_568 , V_569 ;
int V_13 = 0 , V_34 ;
struct V_558 V_559 = {
. V_564 = 0 ,
. V_34 = - 1 ,
. V_12 = F_18 ( F_127 ( V_448 ) ) ,
. V_145 = V_570 ,
. V_571 = true ,
} ;
F_116 ( & V_559 . V_562 ) ;
V_13 = F_521 ( F_510 ( V_448 ) ,
F_512 ( V_272 ) , V_6 ,
false ) ;
if ( V_13 )
return V_13 ;
V_13 = F_513 ( & V_559 , V_448 , V_272 ) ;
if ( V_13 )
goto V_572;
F_522 () ;
F_142 () ;
V_34 = 0 ;
V_568 = V_448 ;
while ( ! F_65 ( F_127 ( V_568 ) ) ) {
if ( ++ V_34 >= V_44 ) {
V_13 = - V_565 ;
goto V_572;
}
V_568 &= ~ 0UL << V_34 ;
}
if ( F_523 ( V_568 , V_272 , false ) ) {
F_217 ( L_105 ,
V_568 , V_272 ) ;
V_13 = - V_565 ;
goto V_572;
}
V_569 = F_524 ( & V_559 , V_568 , V_272 ) ;
if ( ! V_569 ) {
V_13 = - V_565 ;
goto V_572;
}
if ( V_448 != V_568 )
F_525 ( V_568 , V_448 - V_568 ) ;
if ( V_272 != V_569 )
F_525 ( V_272 , V_569 - V_272 ) ;
V_572:
F_526 ( F_510 ( V_448 ) ,
F_512 ( V_272 ) , V_6 ) ;
return V_13 ;
}
void F_525 ( unsigned long V_15 , unsigned V_36 )
{
unsigned int V_67 = 0 ;
for (; V_36 -- ; V_15 ++ ) {
struct V_5 * V_5 = F_127 ( V_15 ) ;
V_67 += F_63 ( V_5 ) != 1 ;
F_527 ( V_5 ) ;
}
F_528 ( V_67 != 0 , L_106 , V_67 ) ;
}
void T_12 F_529 ( struct V_12 * V_12 )
{
unsigned V_116 ;
F_320 ( & V_530 ) ;
F_343 (cpu)
F_382 ( V_12 ,
F_139 ( V_12 -> V_119 , V_116 ) ) ;
F_323 ( & V_530 ) ;
}
void F_530 ( struct V_12 * V_12 )
{
unsigned long V_64 ;
int V_116 ;
struct V_117 * V_118 ;
F_102 ( V_64 ) ;
if ( V_12 -> V_119 != & V_369 ) {
F_143 (cpu) {
V_118 = F_139 ( V_12 -> V_119 , V_116 ) ;
F_531 ( V_12 , V_118 ) ;
}
F_532 ( V_12 -> V_119 ) ;
V_12 -> V_119 = & V_369 ;
}
F_105 ( V_64 ) ;
}
void
F_533 ( unsigned long V_17 , unsigned long V_100 )
{
struct V_5 * V_5 ;
struct V_12 * V_12 ;
unsigned int V_34 , V_35 ;
unsigned long V_15 ;
unsigned long V_64 ;
for ( V_15 = V_17 ; V_15 < V_100 ; V_15 ++ )
if ( F_151 ( V_15 ) )
break;
if ( V_15 == V_100 )
return;
V_12 = F_18 ( F_127 ( V_15 ) ) ;
F_149 ( & V_12 -> V_72 , V_64 ) ;
V_15 = V_17 ;
while ( V_15 < V_100 ) {
if ( ! F_151 ( V_15 ) ) {
V_15 ++ ;
continue;
}
V_5 = F_127 ( V_15 ) ;
if ( F_7 ( ! F_65 ( V_5 ) && F_21 ( V_5 ) ) ) {
V_15 ++ ;
F_369 ( V_5 ) ;
continue;
}
F_123 ( F_63 ( V_5 ) ) ;
F_123 ( ! F_65 ( V_5 ) ) ;
V_34 = F_61 ( V_5 ) ;
#ifdef F_534
F_24 ( V_47 L_107 ,
V_15 , 1 << V_34 , V_100 ) ;
#endif
F_70 ( & V_5 -> V_55 ) ;
F_56 ( V_5 ) ;
V_12 -> V_56 [ V_34 ] . V_57 -- ;
for ( V_35 = 0 ; V_35 < ( 1 << V_34 ) ; V_35 ++ )
F_369 ( ( V_5 + V_35 ) ) ;
V_15 += ( 1 << V_34 ) ;
}
F_157 ( & V_12 -> V_72 , V_64 ) ;
}
bool F_535 ( struct V_5 * V_5 )
{
struct V_12 * V_12 = F_18 ( V_5 ) ;
unsigned long V_15 = F_10 ( V_5 ) ;
unsigned long V_64 ;
unsigned int V_34 ;
F_149 ( & V_12 -> V_72 , V_64 ) ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
struct V_5 * V_573 = V_5 - ( V_15 & ( ( 1 << V_34 ) - 1 ) ) ;
if ( F_65 ( V_573 ) && F_61 ( V_573 ) >= V_34 )
break;
}
F_157 ( & V_12 -> V_72 , V_64 ) ;
return V_34 < V_44 ;
}
static void F_536 ( unsigned long V_64 )
{
const char * V_574 = L_101 ;
unsigned long V_456 ;
int V_35 ;
F_211 ( F_537 ( V_575 ) != V_576 ) ;
F_24 ( V_28 L_108 , V_64 ) ;
V_64 &= ( 1UL << V_577 ) - 1 ;
for ( V_35 = 0 ; V_35 < F_537 ( V_575 ) && V_64 ; V_35 ++ ) {
V_456 = V_575 [ V_35 ] . V_456 ;
if ( ( V_64 & V_456 ) != V_456 )
continue;
V_64 &= ~ V_456 ;
F_24 ( L_109 , V_574 , V_575 [ V_35 ] . V_20 ) ;
V_574 = L_110 ;
}
if ( V_64 )
F_24 ( L_111 , V_574 , V_64 ) ;
F_24 ( L_112 ) ;
}
void F_25 ( struct V_5 * V_5 , const char * V_21 ,
unsigned long V_578 )
{
F_24 ( V_28
L_113 ,
V_5 , F_75 ( & V_5 -> V_63 ) , F_74 ( V_5 ) ,
V_5 -> V_62 , V_5 -> V_579 ) ;
F_536 ( V_5 -> V_64 ) ;
if ( V_21 )
F_538 ( L_114 , V_21 ) ;
if ( V_5 -> V_64 & V_578 ) {
F_538 ( L_115 ) ;
F_536 ( V_5 -> V_64 & V_578 ) ;
}
F_539 ( V_5 ) ;
}
void F_540 ( struct V_5 * V_5 , const char * V_21 )
{
F_25 ( V_5 , V_21 , 0 ) ;
}
