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
static void F_6 ( struct V_5 * V_5 , int V_6 )
{
if ( F_7 ( V_7 ) )
V_6 = V_8 ;
F_8 ( V_5 , ( unsigned long ) V_6 ,
V_9 , V_10 ) ;
}
static int F_9 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
int V_12 = 0 ;
unsigned V_13 ;
unsigned long V_14 = F_10 ( V_5 ) ;
do {
V_13 = F_11 ( V_11 ) ;
if ( V_14 >= V_11 -> V_15 + V_11 -> V_16 )
V_12 = 1 ;
else if ( V_14 < V_11 -> V_15 )
V_12 = 1 ;
} while ( F_12 ( V_11 , V_13 ) );
return V_12 ;
}
static int F_13 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
if ( ! F_14 ( F_10 ( V_5 ) ) )
return 0 ;
if ( V_11 != F_15 ( V_5 ) )
return 0 ;
return 1 ;
}
static int F_16 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
if ( F_9 ( V_11 , V_5 ) )
return 1 ;
if ( ! F_13 ( V_11 , V_5 ) )
return 1 ;
return 0 ;
}
static inline int F_16 ( struct V_11 * V_11 , struct V_5 * V_5 )
{
return 0 ;
}
static void F_17 ( struct V_5 * V_5 )
{
static unsigned long V_17 ;
static unsigned long V_18 ;
static unsigned long V_19 ;
if ( F_18 ( V_5 ) ) {
F_19 ( V_5 ) ;
return;
}
if ( V_18 == 60 ) {
if ( F_20 ( V_20 , V_17 ) ) {
V_19 ++ ;
goto V_21;
}
if ( V_19 ) {
F_21 ( V_22
L_1 ,
V_19 ) ;
V_19 = 0 ;
}
V_18 = 0 ;
}
if ( V_18 ++ == 0 )
V_17 = V_20 + 60 * V_23 ;
F_21 ( V_22 L_2 ,
V_24 -> V_25 , F_10 ( V_5 ) ) ;
F_22 ( V_5 ) ;
F_23 () ;
F_24 () ;
V_21:
F_19 ( V_5 ) ;
F_25 ( V_26 ) ;
}
static void F_26 ( struct V_5 * V_5 )
{
F_27 ( V_5 , F_28 ( V_5 ) ) ;
}
void F_29 ( struct V_5 * V_5 , unsigned long V_27 )
{
int V_28 ;
int V_29 = 1 << V_27 ;
F_30 ( V_5 , F_26 ) ;
F_31 ( V_5 , V_27 ) ;
F_32 ( V_5 ) ;
for ( V_28 = 1 ; V_28 < V_29 ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
F_33 ( V_30 ) ;
F_34 ( V_30 , 0 ) ;
V_30 -> V_31 = V_5 ;
}
}
static int F_35 ( struct V_5 * V_5 , unsigned long V_27 )
{
int V_28 ;
int V_29 = 1 << V_27 ;
int V_32 = 0 ;
if ( F_7 ( F_28 ( V_5 ) != V_27 ) ||
F_7 ( ! F_36 ( V_5 ) ) ) {
F_17 ( V_5 ) ;
V_32 ++ ;
}
F_37 ( V_5 ) ;
for ( V_28 = 1 ; V_28 < V_29 ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_7 ( ! F_38 ( V_30 ) || ( V_30 -> V_31 != V_5 ) ) ) {
F_17 ( V_5 ) ;
V_32 ++ ;
}
F_39 ( V_30 ) ;
}
return V_32 ;
}
static inline void F_40 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
F_41 ( ( V_33 & V_34 ) && F_42 () ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_43 ( V_5 + V_28 ) ;
}
static int T_2 F_44 ( char * V_35 )
{
unsigned long V_36 ;
if ( F_45 ( V_35 , 10 , & V_36 ) < 0 || V_36 > V_37 / 2 ) {
F_21 ( V_38 L_3 ) ;
return 0 ;
}
V_39 = V_36 ;
F_21 ( V_40 L_4 , V_36 ) ;
return 0 ;
}
static inline void F_46 ( struct V_5 * V_5 )
{
F_47 ( V_41 , & V_5 -> V_42 ) ;
}
static inline void F_48 ( struct V_5 * V_5 )
{
F_49 ( V_41 , & V_5 -> V_42 ) ;
}
static inline void F_46 ( struct V_5 * V_5 ) { }
static inline void F_48 ( struct V_5 * V_5 ) { }
static inline void F_50 ( struct V_5 * V_5 , int V_27 )
{
F_51 ( V_5 , V_27 ) ;
F_52 ( V_5 ) ;
}
static inline void F_53 ( struct V_5 * V_5 )
{
F_54 ( V_5 ) ;
F_51 ( V_5 , 0 ) ;
}
static inline unsigned long
F_55 ( unsigned long V_43 , unsigned int V_27 )
{
return V_43 ^ ( 1 << V_27 ) ;
}
static inline int F_56 ( struct V_5 * V_5 , struct V_5 * V_44 ,
int V_27 )
{
if ( ! F_14 ( F_10 ( V_44 ) ) )
return 0 ;
if ( F_57 ( V_5 ) != F_57 ( V_44 ) )
return 0 ;
if ( F_58 ( V_44 ) && F_59 ( V_44 ) == V_27 ) {
F_41 ( F_60 ( V_44 ) != 0 ) ;
return 1 ;
}
if ( F_61 ( V_44 ) && F_59 ( V_44 ) == V_27 ) {
F_41 ( F_60 ( V_44 ) != 0 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_62 ( struct V_5 * V_5 ,
struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned long V_43 ;
unsigned long V_45 ;
unsigned long V_46 ( V_47 ) ;
struct V_5 * V_44 ;
if ( F_7 ( F_63 ( V_5 ) ) )
if ( F_7 ( F_35 ( V_5 , V_27 ) ) )
return;
F_41 ( V_6 == - 1 ) ;
V_43 = F_10 ( V_5 ) & ( ( 1 << V_37 ) - 1 ) ;
F_41 ( V_43 & ( ( 1 << V_27 ) - 1 ) ) ;
F_41 ( F_16 ( V_11 , V_5 ) ) ;
while ( V_27 < V_37 - 1 ) {
V_47 = F_55 ( V_43 , V_27 ) ;
V_44 = V_5 + ( V_47 - V_43 ) ;
if ( ! F_56 ( V_5 , V_44 , V_27 ) )
break;
if ( F_58 ( V_44 ) ) {
F_48 ( V_44 ) ;
F_51 ( V_5 , 0 ) ;
F_64 ( V_11 , V_48 , 1 << V_27 ) ;
} else {
F_65 ( & V_44 -> V_49 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_53 ( V_44 ) ;
}
V_45 = V_47 & V_43 ;
V_5 = V_5 + ( V_45 - V_43 ) ;
V_43 = V_45 ;
V_27 ++ ;
}
F_50 ( V_5 , V_27 ) ;
if ( ( V_27 < V_37 - 2 ) && F_14 ( F_10 ( V_44 ) ) ) {
struct V_5 * V_52 , * V_53 ;
V_45 = V_47 & V_43 ;
V_52 = V_5 + ( V_45 - V_43 ) ;
V_47 = F_55 ( V_45 , V_27 + 1 ) ;
V_53 = V_5 + ( V_47 - V_45 ) ;
if ( F_56 ( V_52 , V_53 , V_27 + 1 ) ) {
F_66 ( & V_5 -> V_49 ,
& V_11 -> V_50 [ V_27 ] . V_54 [ V_6 ] ) ;
goto V_21;
}
}
F_67 ( & V_5 -> V_49 , & V_11 -> V_50 [ V_27 ] . V_54 [ V_6 ] ) ;
V_21:
V_11 -> V_50 [ V_27 ] . V_51 ++ ;
}
static inline void F_68 ( struct V_5 * V_5 )
{
F_69 ( V_5 , V_55 ) ;
F_70 ( V_56 ) ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
if ( F_7 ( F_72 ( V_5 ) |
( V_5 -> V_57 != NULL ) |
( F_73 ( & V_5 -> V_58 ) != 0 ) |
( V_5 -> V_59 & V_60 ) |
( F_74 ( V_5 ) ) ) ) {
F_17 ( V_5 ) ;
return 1 ;
}
if ( V_5 -> V_59 & V_61 )
V_5 -> V_59 &= ~ V_61 ;
return 0 ;
}
static void F_75 ( struct V_11 * V_11 , int V_62 ,
struct V_63 * V_64 )
{
int V_6 = 0 ;
int V_65 = 0 ;
int V_66 = V_62 ;
F_76 ( & V_11 -> V_67 ) ;
V_11 -> V_68 = 0 ;
V_11 -> V_69 = 0 ;
while ( V_66 ) {
struct V_5 * V_5 ;
struct V_70 * V_71 ;
do {
V_65 ++ ;
if ( ++ V_6 == V_72 )
V_6 = 0 ;
V_71 = & V_64 -> V_73 [ V_6 ] ;
} while ( F_77 ( V_71 ) );
if ( V_65 == V_72 )
V_65 = V_66 ;
do {
V_5 = F_78 ( V_71 -> V_74 , struct V_5 , V_49 ) ;
F_65 ( & V_5 -> V_49 ) ;
F_62 ( V_5 , V_11 , 0 , F_79 ( V_5 ) ) ;
F_80 ( V_5 , 0 , F_79 ( V_5 ) ) ;
} while ( -- V_66 && -- V_65 && ! F_77 ( V_71 ) );
}
F_64 ( V_11 , V_48 , V_62 ) ;
F_81 ( & V_11 -> V_67 ) ;
}
static void F_82 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_27 ,
int V_6 )
{
F_76 ( & V_11 -> V_67 ) ;
V_11 -> V_68 = 0 ;
V_11 -> V_69 = 0 ;
F_62 ( V_5 , V_11 , V_27 , V_6 ) ;
F_64 ( V_11 , V_48 , 1 << V_27 ) ;
F_81 ( & V_11 -> V_67 ) ;
}
static bool F_83 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
int V_32 = 0 ;
F_84 ( V_5 , V_27 ) ;
F_85 ( V_5 , V_27 ) ;
if ( F_86 ( V_5 ) )
V_5 -> V_57 = NULL ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
V_32 += F_71 ( V_5 + V_28 ) ;
if ( V_32 )
return false ;
if ( ! F_87 ( V_5 ) ) {
F_88 ( F_89 ( V_5 ) , V_75 << V_27 ) ;
F_90 ( F_89 ( V_5 ) ,
V_75 << V_27 ) ;
}
F_91 ( V_5 , V_27 ) ;
F_92 ( V_5 , 1 << V_27 , 0 ) ;
return true ;
}
static void F_27 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned long V_59 ;
int V_76 = F_93 ( V_5 ) ;
if ( ! F_83 ( V_5 , V_27 ) )
return;
F_94 ( V_59 ) ;
if ( F_7 ( V_76 ) )
F_68 ( V_5 ) ;
F_95 ( V_77 , 1 << V_27 ) ;
F_82 ( F_15 ( V_5 ) , V_5 , V_27 ,
F_96 ( V_5 ) ) ;
F_97 ( V_59 ) ;
}
void T_3 F_98 ( struct V_5 * V_5 , unsigned int V_27 )
{
unsigned int V_29 = 1 << V_27 ;
unsigned int V_78 ;
F_99 ( V_5 ) ;
for ( V_78 = 0 ; V_78 < V_29 ; V_78 ++ ) {
struct V_5 * V_30 = & V_5 [ V_78 ] ;
if ( V_78 + 1 < V_29 )
F_99 ( V_30 + 1 ) ;
F_100 ( V_30 ) ;
F_34 ( V_30 , 0 ) ;
}
F_101 ( V_5 ) ;
F_102 ( V_5 , V_27 ) ;
}
static inline void F_103 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_79 , int V_80 , struct V_50 * V_81 ,
int V_6 )
{
unsigned long V_82 = 1 << V_80 ;
while ( V_80 > V_79 ) {
V_81 -- ;
V_80 -- ;
V_82 >>= 1 ;
F_41 ( F_16 ( V_11 , & V_5 [ V_82 ] ) ) ;
#ifdef F_104
if ( V_80 < F_105 () ) {
F_106 ( & V_5 [ V_82 ] . V_49 ) ;
F_46 ( & V_5 [ V_82 ] ) ;
F_51 ( & V_5 [ V_82 ] , V_80 ) ;
F_64 ( V_11 , V_48 , - ( 1 << V_80 ) ) ;
continue;
}
#endif
F_67 ( & V_5 [ V_82 ] . V_49 , & V_81 -> V_54 [ V_6 ] ) ;
V_81 -> V_51 ++ ;
F_50 ( & V_5 [ V_82 ] , V_80 ) ;
}
}
static inline int F_107 ( struct V_5 * V_5 )
{
if ( F_7 ( F_72 ( V_5 ) |
( V_5 -> V_57 != NULL ) |
( F_73 ( & V_5 -> V_58 ) != 0 ) |
( V_5 -> V_59 & V_61 ) |
( F_74 ( V_5 ) ) ) ) {
F_17 ( V_5 ) ;
return 1 ;
}
return 0 ;
}
static int F_108 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_7 ( F_107 ( V_30 ) ) )
return 1 ;
}
F_51 ( V_5 , 0 ) ;
F_101 ( V_5 ) ;
F_109 ( V_5 , V_27 ) ;
F_92 ( V_5 , 1 << V_27 , 1 ) ;
if ( V_33 & V_83 )
F_40 ( V_5 , V_27 , V_33 ) ;
if ( V_27 && ( V_33 & V_84 ) )
F_29 ( V_5 , V_27 ) ;
return 0 ;
}
static inline
struct V_5 * F_110 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned int V_85 ;
struct V_50 * V_81 ;
struct V_5 * V_5 ;
for ( V_85 = V_27 ; V_85 < V_37 ; ++ V_85 ) {
V_81 = & ( V_11 -> V_50 [ V_85 ] ) ;
if ( F_77 ( & V_81 -> V_54 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_81 -> V_54 [ V_6 ] . V_86 ,
struct V_5 , V_49 ) ;
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
V_81 -> V_51 -- ;
F_103 ( V_11 , V_5 , V_27 , V_85 , V_81 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
static int F_111 ( struct V_11 * V_11 ,
struct V_5 * V_87 , struct V_5 * V_88 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_27 ;
int V_89 = 0 ;
#ifndef F_112
F_113 ( F_15 ( V_87 ) != F_15 ( V_88 ) ) ;
#endif
for ( V_5 = V_87 ; V_5 <= V_88 ; ) {
F_41 ( F_114 ( V_5 ) != F_115 ( V_11 ) ) ;
if ( ! F_14 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_61 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_27 = F_59 ( V_5 ) ;
F_116 ( & V_5 -> V_49 ,
& V_11 -> V_50 [ V_27 ] . V_54 [ V_6 ] ) ;
V_5 += 1 << V_27 ;
V_89 += 1 << V_27 ;
}
return V_89 ;
}
static int F_117 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_90 , V_91 ;
struct V_5 * V_87 , * V_88 ;
V_90 = F_10 ( V_5 ) ;
V_90 = V_90 & ~ ( V_92 - 1 ) ;
V_87 = F_118 ( V_90 ) ;
V_88 = V_87 + V_92 - 1 ;
V_91 = V_90 + V_92 - 1 ;
if ( V_90 < V_11 -> V_15 )
V_87 = V_5 ;
if ( V_91 >= V_11 -> V_15 + V_11 -> V_16 )
return 0 ;
return F_111 ( V_11 , V_87 , V_88 , V_6 ) ;
}
static void F_119 ( struct V_5 * V_93 ,
int V_94 , int V_6 )
{
int V_95 = 1 << ( V_94 - V_96 ) ;
while ( V_95 -- ) {
F_6 ( V_93 , V_6 ) ;
V_93 += V_92 ;
}
}
static inline struct V_5 *
F_120 ( struct V_11 * V_11 , int V_27 , int V_97 )
{
struct V_50 * V_81 ;
int V_85 ;
struct V_5 * V_5 ;
int V_6 , V_28 ;
for ( V_85 = V_37 - 1 ; V_85 >= V_27 ;
-- V_85 ) {
for ( V_28 = 0 ; V_28 < V_98 - 1 ; V_28 ++ ) {
V_6 = V_99 [ V_97 ] [ V_28 ] ;
if ( V_6 == V_100 )
continue;
V_81 = & ( V_11 -> V_50 [ V_85 ] ) ;
if ( F_77 ( & V_81 -> V_54 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_81 -> V_54 [ V_6 ] . V_86 ,
struct V_5 , V_49 ) ;
V_81 -> V_51 -- ;
if ( F_7 ( V_85 >= ( V_96 >> 1 ) ) ||
V_97 == V_101 ||
V_7 ) {
unsigned long V_102 ;
V_102 = F_117 ( V_11 , V_5 ,
V_97 ) ;
if ( V_102 >= ( 1 << ( V_96 - 1 ) ) ||
V_7 )
F_6 ( V_5 ,
V_97 ) ;
V_6 = V_97 ;
}
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
if ( V_85 >= V_96 )
F_119 ( V_5 , V_85 ,
V_97 ) ;
F_103 ( V_11 , V_5 , V_27 , V_85 , V_81 , V_6 ) ;
F_121 ( V_5 , V_27 , V_85 ,
V_97 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_122 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
struct V_5 * V_5 ;
V_103:
V_5 = F_110 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_100 ) {
V_5 = F_120 ( V_11 , V_27 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_100 ;
goto V_103;
}
}
F_123 ( V_5 , V_27 , V_6 ) ;
return V_5 ;
}
static int F_124 ( struct V_11 * V_11 , unsigned int V_27 ,
unsigned long V_62 , struct V_70 * V_71 ,
int V_6 , int V_104 )
{
int V_28 ;
F_76 ( & V_11 -> V_67 ) ;
for ( V_28 = 0 ; V_28 < V_62 ; ++ V_28 ) {
struct V_5 * V_5 = F_122 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_125 ( V_104 == 0 ) )
F_67 ( & V_5 -> V_49 , V_71 ) ;
else
F_66 ( & V_5 -> V_49 , V_71 ) ;
F_51 ( V_5 , V_6 ) ;
V_71 = & V_5 -> V_49 ;
}
F_64 ( V_11 , V_48 , - ( V_28 << V_27 ) ) ;
F_81 ( & V_11 -> V_67 ) ;
return V_28 ;
}
void F_126 ( struct V_11 * V_11 , struct V_63 * V_64 )
{
unsigned long V_59 ;
int V_105 ;
F_94 ( V_59 ) ;
if ( V_64 -> V_62 >= V_64 -> V_106 )
V_105 = V_64 -> V_106 ;
else
V_105 = V_64 -> V_62 ;
F_75 ( V_11 , V_105 , V_64 ) ;
V_64 -> V_62 -= V_105 ;
F_97 ( V_59 ) ;
}
static void F_127 ( unsigned int V_107 )
{
unsigned long V_59 ;
struct V_11 * V_11 ;
F_128 (zone) {
struct V_108 * V_109 ;
struct V_63 * V_64 ;
F_94 ( V_59 ) ;
V_109 = F_129 ( V_11 -> V_110 , V_107 ) ;
V_64 = & V_109 -> V_64 ;
if ( V_64 -> V_62 ) {
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
V_64 -> V_62 = 0 ;
}
F_97 ( V_59 ) ;
}
}
void F_130 ( void * V_111 )
{
F_127 ( F_131 () ) ;
}
void F_132 ( void )
{
F_133 ( F_130 , NULL , 1 ) ;
}
void F_134 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_112 ;
unsigned long V_59 ;
int V_27 , V_113 ;
struct V_70 * V_114 ;
if ( ! V_11 -> V_16 )
return;
F_135 ( & V_11 -> V_67 , V_59 ) ;
V_112 = V_11 -> V_15 + V_11 -> V_16 ;
for ( V_14 = V_11 -> V_15 ; V_14 < V_112 ; V_14 ++ )
if ( F_136 ( V_14 ) ) {
struct V_5 * V_5 = F_118 ( V_14 ) ;
if ( ! F_137 ( V_5 ) )
F_138 ( V_5 ) ;
}
F_139 (order, t) {
F_140 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_28 ;
V_14 = F_10 ( F_78 ( V_114 , struct V_5 , V_49 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1UL << V_27 ) ; V_28 ++ )
F_141 ( F_118 ( V_14 + V_28 ) ) ;
}
}
F_142 ( & V_11 -> V_67 , V_59 ) ;
}
void F_143 ( struct V_5 * V_5 , int V_104 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
struct V_63 * V_64 ;
unsigned long V_59 ;
int V_6 ;
int V_76 = F_93 ( V_5 ) ;
if ( ! F_83 ( V_5 , 0 ) )
return;
V_6 = F_96 ( V_5 ) ;
F_51 ( V_5 , V_6 ) ;
F_94 ( V_59 ) ;
if ( F_7 ( V_76 ) )
F_68 ( V_5 ) ;
F_70 ( V_77 ) ;
if ( V_6 >= V_72 ) {
if ( F_7 ( V_6 == V_115 ) ) {
F_82 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_21;
}
V_6 = V_116 ;
}
V_64 = & F_144 ( V_11 -> V_110 ) -> V_64 ;
if ( V_104 )
F_66 ( & V_5 -> V_49 , & V_64 -> V_73 [ V_6 ] ) ;
else
F_67 ( & V_5 -> V_49 , & V_64 -> V_73 [ V_6 ] ) ;
V_64 -> V_62 ++ ;
if ( V_64 -> V_62 >= V_64 -> V_80 ) {
F_75 ( V_11 , V_64 -> V_106 , V_64 ) ;
V_64 -> V_62 -= V_64 -> V_106 ;
}
V_21:
F_97 ( V_59 ) ;
}
void F_145 ( struct V_70 * V_71 , int V_104 )
{
struct V_5 * V_5 , * V_86 ;
F_146 (page, next, list, lru) {
F_147 ( V_5 , V_104 ) ;
F_143 ( V_5 , V_104 ) ;
}
}
void F_148 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
F_41 ( F_63 ( V_5 ) ) ;
F_41 ( ! F_60 ( V_5 ) ) ;
#ifdef F_149
if ( F_150 ( V_5 ) )
F_148 ( F_151 ( V_5 [ 0 ] . V_117 ) , V_27 ) ;
#endif
for ( V_28 = 1 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_101 ( V_5 + V_28 ) ;
}
int F_152 ( struct V_5 * V_5 )
{
unsigned int V_27 ;
unsigned long V_118 ;
struct V_11 * V_11 ;
F_113 ( ! F_61 ( V_5 ) ) ;
V_11 = F_15 ( V_5 ) ;
V_27 = F_59 ( V_5 ) ;
V_118 = F_153 ( V_11 ) + ( 1 << V_27 ) ;
if ( ! F_154 ( V_11 , 0 , V_118 , 0 , 0 ) )
return 0 ;
F_65 ( & V_5 -> V_49 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_53 ( V_5 ) ;
F_64 ( V_11 , V_48 , - ( 1UL << V_27 ) ) ;
F_101 ( V_5 ) ;
F_148 ( V_5 , V_27 ) ;
if ( V_27 >= V_96 - 1 ) {
struct V_5 * V_119 = V_5 + ( 1 << V_27 ) - 1 ;
for (; V_5 < V_119 ; V_5 += V_92 )
F_6 ( V_5 , V_116 ) ;
}
return 1 << V_27 ;
}
static inline
struct V_5 * F_155 ( struct V_11 * V_120 ,
struct V_11 * V_11 , int V_27 , T_1 V_33 ,
int V_6 )
{
unsigned long V_59 ;
struct V_5 * V_5 ;
int V_104 = ! ! ( V_33 & V_121 ) ;
V_122:
if ( F_125 ( V_27 == 0 ) ) {
struct V_63 * V_64 ;
struct V_70 * V_71 ;
F_94 ( V_59 ) ;
V_64 = & F_144 ( V_11 -> V_110 ) -> V_64 ;
V_71 = & V_64 -> V_73 [ V_6 ] ;
if ( F_77 ( V_71 ) ) {
V_64 -> V_62 += F_124 ( V_11 , 0 ,
V_64 -> V_106 , V_71 ,
V_6 , V_104 ) ;
if ( F_7 ( F_77 ( V_71 ) ) )
goto V_123;
}
if ( V_104 )
V_5 = F_78 ( V_71 -> V_74 , struct V_5 , V_49 ) ;
else
V_5 = F_78 ( V_71 -> V_86 , struct V_5 , V_49 ) ;
F_65 ( & V_5 -> V_49 ) ;
V_64 -> V_62 -- ;
} else {
if ( F_7 ( V_33 & V_124 ) ) {
F_156 ( V_27 > 1 ) ;
}
F_135 ( & V_11 -> V_67 , V_59 ) ;
V_5 = F_122 ( V_11 , V_27 , V_6 ) ;
F_81 ( & V_11 -> V_67 ) ;
if ( ! V_5 )
goto V_123;
F_64 ( V_11 , V_48 , - ( 1 << V_27 ) ) ;
}
F_157 ( V_125 , V_11 , 1 << V_27 ) ;
F_158 ( V_120 , V_11 , V_33 ) ;
F_97 ( V_59 ) ;
F_41 ( F_16 ( V_11 , V_5 ) ) ;
if ( F_108 ( V_5 , V_27 , V_33 ) )
goto V_122;
return V_5 ;
V_123:
F_97 ( V_59 ) ;
return NULL ;
}
static int T_2 F_159 ( char * V_126 )
{
return F_160 ( & V_127 . V_128 , V_126 ) ;
}
static int F_161 ( T_1 V_129 , unsigned int V_27 )
{
if ( V_27 < V_127 . V_130 )
return 0 ;
if ( V_129 & V_124 )
return 0 ;
if ( V_127 . V_131 && ( V_129 & V_34 ) )
return 0 ;
if ( V_127 . V_132 && ( V_129 & V_133 ) )
return 0 ;
return F_162 ( & V_127 . V_128 , 1 << V_27 ) ;
}
static int T_2 F_163 ( void )
{
T_4 V_134 = V_135 | V_136 | V_137 ;
struct V_138 * V_139 ;
V_139 = F_164 ( L_5 , NULL ,
& V_127 . V_128 ) ;
if ( F_165 ( V_139 ) )
return F_166 ( V_139 ) ;
if ( ! F_167 ( L_6 , V_134 , V_139 ,
& V_127 . V_132 ) )
goto V_140;
if ( ! F_167 ( L_7 , V_134 , V_139 ,
& V_127 . V_131 ) )
goto V_140;
if ( ! F_168 ( L_8 , V_134 , V_139 ,
& V_127 . V_130 ) )
goto V_140;
return 0 ;
V_140:
F_169 ( V_139 ) ;
return - V_141 ;
}
static inline int F_161 ( T_1 V_129 , unsigned int V_27 )
{
return 0 ;
}
static bool F_170 ( struct V_11 * V_142 , int V_27 , unsigned long V_143 ,
int V_144 , int V_145 , long V_146 )
{
long V_147 = V_143 ;
int V_148 ;
V_146 -= ( 1 << V_27 ) - 1 ;
if ( V_145 & V_149 )
V_147 -= V_147 / 2 ;
if ( V_145 & V_150 )
V_147 -= V_147 / 4 ;
if ( V_146 <= V_147 + V_142 -> V_151 [ V_144 ] )
return false ;
for ( V_148 = 0 ; V_148 < V_27 ; V_148 ++ ) {
V_146 -= V_142 -> V_50 [ V_148 ] . V_51 << V_148 ;
V_147 >>= 1 ;
if ( V_146 <= V_147 )
return false ;
}
return true ;
}
bool F_154 ( struct V_11 * V_142 , int V_27 , unsigned long V_143 ,
int V_144 , int V_145 )
{
return F_170 ( V_142 , V_27 , V_143 , V_144 , V_145 ,
F_171 ( V_142 , V_48 ) ) ;
}
bool F_172 ( struct V_11 * V_142 , int V_27 , unsigned long V_143 ,
int V_144 , int V_145 )
{
long V_146 = F_171 ( V_142 , V_48 ) ;
if ( V_142 -> V_152 && V_146 < V_142 -> V_152 )
V_146 = F_173 ( V_142 , V_48 ) ;
return F_170 ( V_142 , V_27 , V_143 , V_144 , V_145 ,
V_146 ) ;
}
static T_5 * F_174 ( struct V_153 * V_153 , int V_145 )
{
struct V_154 * V_155 ;
T_5 * V_156 ;
V_155 = V_153 -> V_157 ;
if ( ! V_155 )
return NULL ;
if ( F_175 ( V_20 , V_155 -> V_158 + V_23 ) ) {
F_176 ( V_155 -> V_159 , V_160 ) ;
V_155 -> V_158 = V_20 ;
}
V_156 = ! F_42 () && ( V_145 & V_161 ) ?
& V_162 :
& V_163 [ V_164 ] ;
return V_156 ;
}
static int F_177 ( struct V_153 * V_153 , struct V_165 * V_142 ,
T_5 * V_156 )
{
struct V_154 * V_155 ;
int V_28 ;
int V_166 ;
V_155 = V_153 -> V_157 ;
if ( ! V_155 )
return 1 ;
V_28 = V_142 - V_153 -> V_167 ;
V_166 = V_155 -> V_168 [ V_28 ] ;
return F_178 ( V_166 , * V_156 ) && ! F_179 ( V_28 , V_155 -> V_159 ) ;
}
static void F_180 ( struct V_153 * V_153 , struct V_165 * V_142 )
{
struct V_154 * V_155 ;
int V_28 ;
V_155 = V_153 -> V_157 ;
if ( ! V_155 )
return;
V_28 = V_142 - V_153 -> V_167 ;
F_181 ( V_28 , V_155 -> V_159 ) ;
}
static void F_182 ( struct V_153 * V_153 )
{
struct V_154 * V_155 ;
V_155 = V_153 -> V_157 ;
if ( ! V_155 )
return;
F_176 ( V_155 -> V_159 , V_160 ) ;
}
static T_5 * F_174 ( struct V_153 * V_153 , int V_145 )
{
return NULL ;
}
static int F_177 ( struct V_153 * V_153 , struct V_165 * V_142 ,
T_5 * V_156 )
{
return 1 ;
}
static void F_180 ( struct V_153 * V_153 , struct V_165 * V_142 )
{
}
static void F_182 ( struct V_153 * V_153 )
{
}
static struct V_5 *
F_183 ( T_1 V_129 , T_5 * V_169 , unsigned int V_27 ,
struct V_153 * V_153 , int V_170 , int V_145 ,
struct V_11 * V_120 , int V_6 )
{
struct V_165 * V_142 ;
struct V_5 * V_5 = NULL ;
int V_144 ;
struct V_11 * V_11 ;
T_5 * V_156 = NULL ;
int V_171 = 0 ;
int V_172 = 0 ;
V_144 = F_184 ( V_120 ) ;
V_173:
F_185 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_174 && V_171 &&
! F_177 ( V_153 , V_142 , V_156 ) )
continue;
if ( ( V_145 & V_161 ) &&
! F_186 ( V_11 , V_129 ) )
continue;
if ( ( V_145 & V_175 ) &&
( V_129 & V_176 ) && ! F_187 ( V_11 ) )
goto V_177;
F_188 ( V_178 < V_179 ) ;
if ( ! ( V_145 & V_178 ) ) {
unsigned long V_143 ;
int V_12 ;
V_143 = V_11 -> V_118 [ V_145 & V_180 ] ;
if ( F_154 ( V_11 , V_27 , V_143 ,
V_144 , V_145 ) )
goto V_181;
if ( V_174 && ! V_172 && V_182 > 1 ) {
V_156 = F_174 ( V_153 , V_145 ) ;
V_171 = 1 ;
V_172 = 1 ;
}
if ( V_183 == 0 )
goto V_177;
if ( V_174 && V_171 &&
! F_177 ( V_153 , V_142 , V_156 ) )
continue;
V_12 = F_189 ( V_11 , V_129 , V_27 ) ;
switch ( V_12 ) {
case V_184 :
continue;
case V_185 :
continue;
default:
if ( ! F_154 ( V_11 , V_27 , V_143 ,
V_144 , V_145 ) )
goto V_177;
}
}
V_181:
V_5 = F_155 ( V_120 , V_11 , V_27 ,
V_129 , V_6 ) ;
if ( V_5 )
break;
V_177:
if ( V_174 )
F_180 ( V_153 , V_142 ) ;
}
if ( F_7 ( V_174 && V_5 == NULL && V_171 ) ) {
V_171 = 0 ;
goto V_173;
}
return V_5 ;
}
static inline bool F_190 ( void )
{
bool V_12 = false ;
#if V_186 > 8
V_12 = F_42 () ;
#endif
return V_12 ;
}
void F_191 ( T_1 V_129 , int V_27 , const char * V_187 , ... )
{
unsigned int V_188 = V_189 ;
if ( ( V_129 & V_190 ) || ! F_192 ( & V_191 ) ||
F_105 () > 0 )
return;
if ( ! ( V_129 & V_192 ) )
if ( F_193 ( V_193 ) ||
( V_24 -> V_59 & ( V_194 | V_195 ) ) )
V_188 &= ~ V_189 ;
if ( F_42 () || ! ( V_129 & V_133 ) )
V_188 &= ~ V_189 ;
if ( V_187 ) {
struct V_196 V_197 ;
T_6 args ;
va_start ( args , V_187 ) ;
V_197 . V_187 = V_187 ;
V_197 . V_198 = & args ;
F_194 ( L_9 , & V_197 ) ;
va_end ( args ) ;
}
F_194 ( L_10 ,
V_24 -> V_25 , V_27 , V_129 ) ;
F_24 () ;
if ( ! F_190 () )
F_195 ( V_188 ) ;
}
static inline int
F_196 ( T_1 V_129 , unsigned int V_27 ,
unsigned long V_199 ,
unsigned long V_200 )
{
if ( V_129 & V_201 )
return 0 ;
if ( V_129 & V_124 )
return 1 ;
if ( ! V_199 && F_5 () )
return 0 ;
if ( V_27 <= V_202 )
return 1 ;
if ( V_129 & V_203 && V_200 < ( 1 << V_27 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_197 ( T_1 V_129 , unsigned int V_27 ,
struct V_153 * V_153 , enum V_204 V_170 ,
T_5 * V_169 , struct V_11 * V_120 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_198 ( V_153 , V_129 ) ) {
F_199 ( 1 ) ;
return NULL ;
}
V_5 = F_183 ( V_129 | V_205 , V_169 ,
V_27 , V_153 , V_170 ,
V_206 | V_161 ,
V_120 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_129 & V_124 ) ) {
if ( V_27 > V_202 )
goto V_21;
if ( V_170 < V_207 )
goto V_21;
if ( V_129 & V_208 )
goto V_21;
}
F_200 ( V_153 , V_129 , V_27 , V_169 ) ;
V_21:
F_201 ( V_153 , V_129 ) ;
return V_5 ;
}
static struct V_5 *
F_202 ( T_1 V_129 , unsigned int V_27 ,
struct V_153 * V_153 , enum V_204 V_170 ,
T_5 * V_169 , int V_145 , struct V_11 * V_120 ,
int V_6 , bool V_209 ,
bool * V_210 ,
unsigned long * V_199 )
{
struct V_5 * V_5 ;
if ( ! V_27 )
return NULL ;
if ( F_203 ( V_120 ) ) {
* V_210 = true ;
return NULL ;
}
V_24 -> V_59 |= V_194 ;
* V_199 = F_204 ( V_153 , V_27 , V_129 ,
V_169 , V_209 ) ;
V_24 -> V_59 &= ~ V_194 ;
if ( * V_199 != V_211 ) {
F_127 ( F_205 () ) ;
F_206 () ;
V_5 = F_183 ( V_129 , V_169 ,
V_27 , V_153 , V_170 ,
V_145 , V_120 ,
V_6 ) ;
if ( V_5 ) {
V_120 -> V_212 = 0 ;
V_120 -> V_213 = 0 ;
F_207 ( V_214 ) ;
return V_5 ;
}
F_207 ( V_215 ) ;
if ( V_209 )
F_208 ( V_120 ) ;
F_209 () ;
}
return NULL ;
}
static inline struct V_5 *
F_202 ( T_1 V_129 , unsigned int V_27 ,
struct V_153 * V_153 , enum V_204 V_170 ,
T_5 * V_169 , int V_145 , struct V_11 * V_120 ,
int V_6 , bool V_209 ,
bool * V_210 ,
unsigned long * V_199 )
{
return NULL ;
}
static inline struct V_5 *
F_210 ( T_1 V_129 , unsigned int V_27 ,
struct V_153 * V_153 , enum V_204 V_170 ,
T_5 * V_169 , int V_145 , struct V_11 * V_120 ,
int V_6 , unsigned long * V_199 )
{
struct V_5 * V_5 = NULL ;
struct V_216 V_216 ;
bool V_217 = false ;
F_209 () ;
F_211 () ;
V_24 -> V_59 |= V_194 ;
F_212 ( V_129 ) ;
V_216 . V_218 = 0 ;
V_24 -> V_216 = & V_216 ;
* V_199 = F_213 ( V_153 , V_27 , V_129 , V_169 ) ;
V_24 -> V_216 = NULL ;
F_214 () ;
V_24 -> V_59 &= ~ V_194 ;
F_209 () ;
if ( F_7 ( ! ( * V_199 ) ) )
return NULL ;
if ( V_174 )
F_182 ( V_153 ) ;
V_219:
V_5 = F_183 ( V_129 , V_169 , V_27 ,
V_153 , V_170 ,
V_145 , V_120 ,
V_6 ) ;
if ( ! V_5 && ! V_217 ) {
F_132 () ;
V_217 = true ;
goto V_219;
}
return V_5 ;
}
static inline struct V_5 *
F_215 ( T_1 V_129 , unsigned int V_27 ,
struct V_153 * V_153 , enum V_204 V_170 ,
T_5 * V_169 , struct V_11 * V_120 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_183 ( V_129 , V_169 , V_27 ,
V_153 , V_170 , V_178 ,
V_120 , V_6 ) ;
if ( ! V_5 && V_129 & V_124 )
F_216 ( V_120 , V_220 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_129 & V_124 ) );
return V_5 ;
}
static inline
void F_217 ( unsigned int V_27 , struct V_153 * V_153 ,
enum V_204 V_170 ,
enum V_204 V_144 )
{
struct V_165 * V_142 ;
struct V_11 * V_11 ;
F_218 (zone, z, zonelist, high_zoneidx)
F_219 ( V_11 , V_27 , V_144 ) ;
}
static inline int
F_220 ( T_1 V_129 )
{
int V_145 = V_221 | V_161 ;
const T_1 V_222 = V_129 & V_133 ;
F_188 ( V_223 != ( V_224 T_1 ) V_149 ) ;
V_145 |= ( V_224 int ) ( V_129 & V_223 ) ;
if ( ! V_222 ) {
if ( ! ( V_129 & V_192 ) )
V_145 |= V_150 ;
V_145 &= ~ V_161 ;
} else if ( F_7 ( F_221 ( V_24 ) ) && ! F_42 () )
V_145 |= V_150 ;
if ( F_125 ( ! ( V_129 & V_192 ) ) ) {
if ( ! F_42 () &&
( ( V_24 -> V_59 & V_194 ) ||
F_7 ( F_193 ( V_193 ) ) ) )
V_145 |= V_178 ;
}
return V_145 ;
}
static inline struct V_5 *
F_222 ( T_1 V_129 , unsigned int V_27 ,
struct V_153 * V_153 , enum V_204 V_170 ,
T_5 * V_169 , struct V_11 * V_120 ,
int V_6 )
{
const T_1 V_222 = V_129 & V_133 ;
struct V_5 * V_5 = NULL ;
int V_145 ;
unsigned long V_200 = 0 ;
unsigned long V_199 ;
bool V_209 = false ;
bool V_210 = false ;
if ( V_27 >= V_37 ) {
F_156 ( ! ( V_129 & V_190 ) ) ;
return NULL ;
}
if ( V_174 && ( V_129 & V_225 ) == V_225 )
goto V_226;
V_227:
if ( ! ( V_129 & V_228 ) )
F_217 ( V_27 , V_153 , V_170 ,
F_184 ( V_120 ) ) ;
V_145 = F_220 ( V_129 ) ;
if ( ! ( V_145 & V_161 ) && ! V_169 )
F_223 ( V_153 , V_170 , NULL ,
& V_120 ) ;
V_229:
V_5 = F_183 ( V_129 , V_169 , V_27 , V_153 ,
V_170 , V_145 & ~ V_178 ,
V_120 , V_6 ) ;
if ( V_5 )
goto V_230;
if ( V_145 & V_178 ) {
V_5 = F_215 ( V_129 , V_27 ,
V_153 , V_170 , V_169 ,
V_120 , V_6 ) ;
if ( V_5 )
goto V_230;
}
if ( ! V_222 )
goto V_226;
if ( V_24 -> V_59 & V_194 )
goto V_226;
if ( F_193 ( V_193 ) && ! ( V_129 & V_124 ) )
goto V_226;
V_5 = F_202 ( V_129 , V_27 ,
V_153 , V_170 ,
V_169 ,
V_145 , V_120 ,
V_6 , V_209 ,
& V_210 ,
& V_199 ) ;
if ( V_5 )
goto V_230;
V_209 = true ;
if ( V_210 && ( V_129 & V_228 ) )
goto V_226;
V_5 = F_210 ( V_129 , V_27 ,
V_153 , V_170 ,
V_169 ,
V_145 , V_120 ,
V_6 , & V_199 ) ;
if ( V_5 )
goto V_230;
if ( ! V_199 ) {
if ( ( V_129 & V_231 ) && ! ( V_129 & V_201 ) ) {
if ( V_232 )
goto V_226;
V_5 = F_197 ( V_129 , V_27 ,
V_153 , V_170 ,
V_169 , V_120 ,
V_6 ) ;
if ( V_5 )
goto V_230;
if ( ! ( V_129 & V_124 ) ) {
if ( V_27 > V_202 )
goto V_226;
if ( V_170 < V_207 )
goto V_226;
}
goto V_227;
}
}
V_200 += V_199 ;
if ( F_196 ( V_129 , V_27 , V_199 ,
V_200 ) ) {
F_216 ( V_120 , V_220 , V_23 / 50 ) ;
goto V_229;
} else {
V_5 = F_202 ( V_129 , V_27 ,
V_153 , V_170 ,
V_169 ,
V_145 , V_120 ,
V_6 , V_209 ,
& V_210 ,
& V_199 ) ;
if ( V_5 )
goto V_230;
}
V_226:
F_191 ( V_129 , V_27 , NULL ) ;
return V_5 ;
V_230:
if ( V_233 )
F_224 ( V_5 , V_27 , V_129 ) ;
return V_5 ;
}
struct V_5 *
F_225 ( T_1 V_129 , unsigned int V_27 ,
struct V_153 * V_153 , T_5 * V_169 )
{
enum V_204 V_170 = F_226 ( V_129 ) ;
struct V_11 * V_120 ;
struct V_5 * V_5 ;
int V_6 = F_227 ( V_129 ) ;
V_129 &= V_3 ;
F_228 ( V_129 ) ;
F_229 ( V_129 & V_133 ) ;
if ( F_161 ( V_129 , V_27 ) )
return NULL ;
if ( F_7 ( ! V_153 -> V_167 -> V_11 ) )
return NULL ;
F_230 () ;
F_223 ( V_153 , V_170 ,
V_169 ? : & V_162 ,
& V_120 ) ;
if ( ! V_120 ) {
F_231 () ;
return NULL ;
}
V_5 = F_183 ( V_129 | V_205 , V_169 , V_27 ,
V_153 , V_170 , V_175 | V_161 ,
V_120 , V_6 ) ;
if ( F_7 ( ! V_5 ) )
V_5 = F_222 ( V_129 , V_27 ,
V_153 , V_170 , V_169 ,
V_120 , V_6 ) ;
F_231 () ;
F_232 ( V_5 , V_27 , V_129 , V_6 ) ;
return V_5 ;
}
unsigned long F_233 ( T_1 V_129 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_41 ( ( V_129 & V_34 ) != 0 ) ;
V_5 = F_234 ( V_129 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_89 ( V_5 ) ;
}
unsigned long F_235 ( T_1 V_129 )
{
return F_233 ( V_129 | V_83 , 0 ) ;
}
void F_102 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_236 ( V_5 ) ) {
if ( V_27 == 0 )
F_143 ( V_5 , 0 ) ;
else
F_27 ( V_5 , V_27 ) ;
}
}
void V_146 ( unsigned long V_234 , unsigned int V_27 )
{
if ( V_234 != 0 ) {
F_41 ( ! F_237 ( ( void * ) V_234 ) ) ;
F_102 ( F_151 ( ( void * ) V_234 ) , V_27 ) ;
}
}
static void * F_238 ( unsigned long V_234 , unsigned V_27 , T_7 V_82 )
{
if ( V_234 ) {
unsigned long V_235 = V_234 + ( V_75 << V_27 ) ;
unsigned long V_236 = V_234 + F_239 ( V_82 ) ;
F_148 ( F_151 ( ( void * ) V_234 ) , V_27 ) ;
while ( V_236 < V_235 ) {
F_240 ( V_236 ) ;
V_236 += V_75 ;
}
}
return ( void * ) V_234 ;
}
void * F_241 ( T_7 V_82 , T_1 V_129 )
{
unsigned int V_27 = F_242 ( V_82 ) ;
unsigned long V_234 ;
V_234 = F_233 ( V_129 , V_27 ) ;
return F_238 ( V_234 , V_27 , V_82 ) ;
}
void * F_243 ( int V_237 , T_7 V_82 , T_1 V_129 )
{
unsigned V_27 = F_242 ( V_82 ) ;
struct V_5 * V_30 = F_244 ( V_237 , V_129 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_238 ( ( unsigned long ) F_89 ( V_30 ) , V_27 , V_82 ) ;
}
void F_245 ( void * V_238 , T_7 V_82 )
{
unsigned long V_234 = ( unsigned long ) V_238 ;
unsigned long V_239 = V_234 + F_239 ( V_82 ) ;
while ( V_234 < V_239 ) {
F_240 ( V_234 ) ;
V_234 += V_75 ;
}
}
static unsigned int F_246 ( int V_240 )
{
struct V_165 * V_142 ;
struct V_11 * V_11 ;
unsigned int V_241 = 0 ;
struct V_153 * V_153 = F_247 ( F_248 () , V_242 ) ;
F_218 (zone, z, zonelist, offset) {
unsigned long V_82 = V_11 -> V_243 ;
unsigned long V_80 = F_249 ( V_11 ) ;
if ( V_82 > V_80 )
V_241 += V_82 - V_80 ;
}
return V_241 ;
}
unsigned int F_250 ( void )
{
return F_246 ( F_226 ( V_244 ) ) ;
}
unsigned int F_251 ( void )
{
return F_246 ( F_226 ( V_245 ) ) ;
}
static inline void F_252 ( struct V_11 * V_11 )
{
if ( V_174 )
F_21 ( L_11 , F_115 ( V_11 ) ) ;
}
void F_253 ( struct V_246 * V_247 )
{
V_247 -> V_248 = V_249 ;
V_247 -> V_250 = 0 ;
V_247 -> V_251 = F_254 ( V_48 ) ;
V_247 -> V_252 = F_255 () ;
V_247 -> V_253 = V_254 ;
V_247 -> V_255 = F_256 () ;
V_247 -> V_256 = V_75 ;
}
void F_257 ( struct V_246 * V_247 , int V_237 )
{
T_8 * V_257 = F_258 ( V_237 ) ;
V_247 -> V_248 = V_257 -> V_258 ;
V_247 -> V_251 = F_259 ( V_237 , V_48 ) ;
#ifdef F_260
V_247 -> V_253 = V_257 -> V_259 [ V_260 ] . V_243 ;
V_247 -> V_255 = F_171 ( & V_257 -> V_259 [ V_260 ] ,
V_48 ) ;
#else
V_247 -> V_253 = 0 ;
V_247 -> V_255 = 0 ;
#endif
V_247 -> V_256 = V_75 ;
}
bool F_261 ( unsigned int V_59 , int V_237 )
{
bool V_12 = false ;
if ( ! ( V_59 & V_189 ) )
goto V_21;
F_230 () ;
V_12 = ! F_178 ( V_237 , V_162 ) ;
F_231 () ;
V_21:
return V_12 ;
}
void F_262 ( unsigned int V_188 )
{
int V_107 ;
struct V_11 * V_11 ;
F_128 (zone) {
if ( F_261 ( V_188 , F_115 ( V_11 ) ) )
continue;
F_252 ( V_11 ) ;
F_21 ( L_12 , V_11 -> V_261 ) ;
F_263 (cpu) {
struct V_108 * V_110 ;
V_110 = F_129 ( V_11 -> V_110 , V_107 ) ;
F_21 ( L_13 ,
V_107 , V_110 -> V_64 . V_80 ,
V_110 -> V_64 . V_106 , V_110 -> V_64 . V_62 ) ;
}
}
F_21 ( L_14
L_15
L_16
L_17
L_18
L_19 ,
F_254 ( V_262 ) ,
F_254 ( V_263 ) ,
F_254 ( V_264 ) ,
F_254 ( V_265 ) ,
F_254 ( V_266 ) ,
F_254 ( V_267 ) ,
F_254 ( V_268 ) ,
F_254 ( V_269 ) ,
F_254 ( V_270 ) ,
F_254 ( V_271 ) ,
F_254 ( V_48 ) ,
F_254 ( V_272 ) ,
F_254 ( V_273 ) ,
F_254 ( V_274 ) ,
F_254 ( V_275 ) ,
F_254 ( V_276 ) ,
F_254 ( V_277 ) ) ;
F_128 (zone) {
int V_28 ;
if ( F_261 ( V_188 , F_115 ( V_11 ) ) )
continue;
F_252 ( V_11 ) ;
F_21 ( L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
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
L_47 ,
V_11 -> V_261 ,
F_264 ( F_171 ( V_11 , V_48 ) ) ,
F_264 ( F_265 ( V_11 ) ) ,
F_264 ( F_153 ( V_11 ) ) ,
F_264 ( F_249 ( V_11 ) ) ,
F_264 ( F_171 ( V_11 , V_262 ) ) ,
F_264 ( F_171 ( V_11 , V_263 ) ) ,
F_264 ( F_171 ( V_11 , V_265 ) ) ,
F_264 ( F_171 ( V_11 , V_266 ) ) ,
F_264 ( F_171 ( V_11 , V_268 ) ) ,
F_264 ( F_171 ( V_11 , V_264 ) ) ,
F_264 ( F_171 ( V_11 , V_267 ) ) ,
F_264 ( V_11 -> V_243 ) ,
F_264 ( F_171 ( V_11 , V_55 ) ) ,
F_264 ( F_171 ( V_11 , V_269 ) ) ,
F_264 ( F_171 ( V_11 , V_270 ) ) ,
F_264 ( F_171 ( V_11 , V_274 ) ) ,
F_264 ( F_171 ( V_11 , V_275 ) ) ,
F_264 ( F_171 ( V_11 , V_272 ) ) ,
F_264 ( F_171 ( V_11 , V_273 ) ) ,
F_171 ( V_11 , V_278 ) *
V_279 / 1024 ,
F_264 ( F_171 ( V_11 , V_276 ) ) ,
F_264 ( F_171 ( V_11 , V_271 ) ) ,
F_264 ( F_171 ( V_11 , V_277 ) ) ,
F_264 ( F_171 ( V_11 , V_280 ) ) ,
V_11 -> V_69 ,
( V_11 -> V_68 ? L_48 : L_49 )
) ;
F_21 ( L_50 ) ;
for ( V_28 = 0 ; V_28 < V_281 ; V_28 ++ )
F_21 ( L_51 , V_11 -> V_151 [ V_28 ] ) ;
F_21 ( L_47 ) ;
}
F_128 (zone) {
unsigned long V_282 [ V_37 ] , V_59 , V_27 , V_283 = 0 ;
if ( F_261 ( V_188 , F_115 ( V_11 ) ) )
continue;
F_252 ( V_11 ) ;
F_21 ( L_52 , V_11 -> V_261 ) ;
F_135 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
V_282 [ V_27 ] = V_11 -> V_50 [ V_27 ] . V_51 ;
V_283 += V_282 [ V_27 ] << V_27 ;
}
F_142 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ )
F_21 ( L_53 , V_282 [ V_27 ] , F_264 ( 1UL ) << V_27 ) ;
F_21 ( L_54 , F_264 ( V_283 ) ) ;
}
F_21 ( L_55 , F_254 ( V_284 ) ) ;
F_266 () ;
}
static void F_267 ( struct V_11 * V_11 , struct V_165 * V_165 )
{
V_165 -> V_11 = V_11 ;
V_165 -> F_184 = F_184 ( V_11 ) ;
}
static int F_268 ( T_8 * V_257 , struct V_153 * V_153 ,
int V_285 , enum V_204 V_204 )
{
struct V_11 * V_11 ;
F_113 ( V_204 >= V_281 ) ;
V_204 ++ ;
do {
V_204 -- ;
V_11 = V_257 -> V_259 + V_204 ;
if ( F_269 ( V_11 ) ) {
F_267 ( V_11 ,
& V_153 -> V_167 [ V_285 ++ ] ) ;
F_270 ( V_204 ) ;
}
} while ( V_204 );
return V_285 ;
}
static int F_271 ( char * V_286 )
{
if ( * V_286 == 'd' || * V_286 == 'D' ) {
V_287 = V_288 ;
} else if ( * V_286 == 'n' || * V_286 == 'N' ) {
V_287 = V_289 ;
} else if ( * V_286 == 'z' || * V_286 == 'Z' ) {
V_287 = V_290 ;
} else {
F_21 ( V_291
L_56
L_57 , V_286 ) ;
return - V_292 ;
}
return 0 ;
}
static T_2 int F_272 ( char * V_286 )
{
int V_12 ;
if ( ! V_286 )
return 0 ;
V_12 = F_271 ( V_286 ) ;
if ( V_12 == 0 )
F_273 ( V_293 , V_286 , V_294 ) ;
return V_12 ;
}
int F_274 ( T_9 * V_295 , int V_296 ,
void T_10 * V_297 , T_7 * V_298 ,
T_11 * V_299 )
{
char V_300 [ V_294 ] ;
int V_12 ;
static F_275 ( V_301 ) ;
F_276 ( & V_301 ) ;
if ( V_296 )
strcpy ( V_300 , ( char * ) V_295 -> V_302 ) ;
V_12 = F_277 ( V_295 , V_296 , V_297 , V_298 , V_299 ) ;
if ( V_12 )
goto V_21;
if ( V_296 ) {
int V_303 = V_287 ;
if ( F_271 ( ( char * ) V_295 -> V_302 ) ) {
strncpy ( ( char * ) V_295 -> V_302 , V_300 ,
V_294 ) ;
V_287 = V_303 ;
} else if ( V_303 != V_287 ) {
F_276 ( & V_304 ) ;
F_278 ( NULL ) ;
F_279 ( & V_304 ) ;
}
}
V_21:
F_279 ( & V_301 ) ;
return V_12 ;
}
static int F_280 ( int V_305 , T_5 * V_306 )
{
int V_166 , V_247 ;
int V_307 = V_308 ;
int V_309 = - 1 ;
const struct V_310 * V_311 = F_281 ( 0 ) ;
if ( ! F_178 ( V_305 , * V_306 ) ) {
F_282 ( V_305 , * V_306 ) ;
return V_305 ;
}
F_283 (n, N_HIGH_MEMORY) {
if ( F_178 ( V_166 , * V_306 ) )
continue;
V_247 = F_284 ( V_305 , V_166 ) ;
V_247 += ( V_166 < V_305 ) ;
V_311 = F_281 ( V_166 ) ;
if ( ! F_285 ( V_311 ) )
V_247 += V_312 ;
V_247 *= ( V_313 * V_314 ) ;
V_247 += V_315 [ V_166 ] ;
if ( V_247 < V_307 ) {
V_307 = V_247 ;
V_309 = V_166 ;
}
}
if ( V_309 >= 0 )
F_282 ( V_309 , * V_306 ) ;
return V_309 ;
}
static void F_286 ( T_8 * V_257 , int V_305 )
{
int V_316 ;
struct V_153 * V_153 ;
V_153 = & V_257 -> V_317 [ 0 ] ;
for ( V_316 = 0 ; V_153 -> V_167 [ V_316 ] . V_11 != NULL ; V_316 ++ )
;
V_316 = F_268 ( F_258 ( V_305 ) , V_153 , V_316 ,
V_281 - 1 ) ;
V_153 -> V_167 [ V_316 ] . V_11 = NULL ;
V_153 -> V_167 [ V_316 ] . F_184 = 0 ;
}
static void F_287 ( T_8 * V_257 )
{
int V_316 ;
struct V_153 * V_153 ;
V_153 = & V_257 -> V_317 [ 1 ] ;
V_316 = F_268 ( V_257 , V_153 , 0 , V_281 - 1 ) ;
V_153 -> V_167 [ V_316 ] . V_11 = NULL ;
V_153 -> V_167 [ V_316 ] . F_184 = 0 ;
}
static void F_288 ( T_8 * V_257 , int V_318 )
{
int V_319 , V_316 , V_305 ;
int V_204 ;
struct V_11 * V_142 ;
struct V_153 * V_153 ;
V_153 = & V_257 -> V_317 [ 0 ] ;
V_319 = 0 ;
for ( V_204 = V_281 - 1 ; V_204 >= 0 ; V_204 -- ) {
for ( V_316 = 0 ; V_316 < V_318 ; V_316 ++ ) {
V_305 = V_320 [ V_316 ] ;
V_142 = & F_258 ( V_305 ) -> V_259 [ V_204 ] ;
if ( F_269 ( V_142 ) ) {
F_267 ( V_142 ,
& V_153 -> V_167 [ V_319 ++ ] ) ;
F_270 ( V_204 ) ;
}
}
}
V_153 -> V_167 [ V_319 ] . V_11 = NULL ;
V_153 -> V_167 [ V_319 ] . F_184 = 0 ;
}
static int F_289 ( void )
{
int V_237 , V_204 ;
unsigned long V_321 , V_322 ;
struct V_11 * V_142 ;
int V_323 ;
V_321 = 0 ;
V_322 = 0 ;
F_290 (nid) {
for ( V_204 = 0 ; V_204 < V_281 ; V_204 ++ ) {
V_142 = & F_258 ( V_237 ) -> V_259 [ V_204 ] ;
if ( F_269 ( V_142 ) ) {
if ( V_204 < V_207 )
V_321 += V_142 -> V_243 ;
V_322 += V_142 -> V_243 ;
} else if ( V_204 == V_207 ) {
return V_289 ;
}
}
}
if ( ! V_321 ||
V_321 > V_322 / 2 )
return V_289 ;
V_323 = V_322 /
( F_291 ( V_163 [ V_164 ] ) + 1 ) ;
F_290 (nid) {
V_321 = 0 ;
V_322 = 0 ;
for ( V_204 = 0 ; V_204 < V_281 ; V_204 ++ ) {
V_142 = & F_258 ( V_237 ) -> V_259 [ V_204 ] ;
if ( F_269 ( V_142 ) ) {
if ( V_204 < V_207 )
V_321 += V_142 -> V_243 ;
V_322 += V_142 -> V_243 ;
}
}
if ( V_321 &&
V_322 > V_323 &&
V_321 > V_322 * 70 / 100 )
return V_289 ;
}
return V_290 ;
}
static void F_292 ( void )
{
if ( V_287 == V_288 )
V_324 = F_289 () ;
else
V_324 = V_287 ;
}
static void F_293 ( T_8 * V_257 )
{
int V_316 , V_305 , V_325 ;
enum V_204 V_28 ;
T_5 V_326 ;
int V_327 , V_328 ;
struct V_153 * V_153 ;
int V_27 = V_324 ;
for ( V_28 = 0 ; V_28 < V_329 ; V_28 ++ ) {
V_153 = V_257 -> V_317 + V_28 ;
V_153 -> V_167 [ 0 ] . V_11 = NULL ;
V_153 -> V_167 [ 0 ] . F_184 = 0 ;
}
V_327 = V_257 -> V_330 ;
V_325 = V_182 ;
V_328 = V_327 ;
F_294 ( V_326 ) ;
memset ( V_320 , 0 , sizeof( V_320 ) ) ;
V_316 = 0 ;
while ( ( V_305 = F_280 ( V_327 , & V_326 ) ) >= 0 ) {
int V_331 = F_284 ( V_327 , V_305 ) ;
if ( V_331 > V_332 )
V_183 = 1 ;
if ( V_331 != F_284 ( V_327 , V_328 ) )
V_315 [ V_305 ] = V_325 ;
V_328 = V_305 ;
V_325 -- ;
if ( V_27 == V_289 )
F_286 ( V_257 , V_305 ) ;
else
V_320 [ V_316 ++ ] = V_305 ;
}
if ( V_27 == V_290 ) {
F_288 ( V_257 , V_316 ) ;
}
F_287 ( V_257 ) ;
}
static void F_295 ( T_8 * V_257 )
{
struct V_153 * V_153 ;
struct V_154 * V_155 ;
struct V_165 * V_142 ;
V_153 = & V_257 -> V_317 [ 0 ] ;
V_153 -> V_157 = V_155 = & V_153 -> V_333 ;
F_176 ( V_155 -> V_159 , V_160 ) ;
for ( V_142 = V_153 -> V_167 ; V_142 -> V_11 ; V_142 ++ )
V_155 -> V_168 [ V_142 - V_153 -> V_167 ] = F_296 ( V_142 ) ;
}
int F_297 ( int V_305 )
{
struct V_11 * V_11 ;
( void ) F_223 ( F_247 ( V_305 , V_242 ) ,
F_226 ( V_242 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_305 ;
}
static void F_292 ( void )
{
V_324 = V_290 ;
}
static void F_293 ( T_8 * V_257 )
{
int V_305 , V_327 ;
enum V_204 V_316 ;
struct V_153 * V_153 ;
V_327 = V_257 -> V_330 ;
V_153 = & V_257 -> V_317 [ 0 ] ;
V_316 = F_268 ( V_257 , V_153 , 0 , V_281 - 1 ) ;
for ( V_305 = V_327 + 1 ; V_305 < V_314 ; V_305 ++ ) {
if ( ! F_298 ( V_305 ) )
continue;
V_316 = F_268 ( F_258 ( V_305 ) , V_153 , V_316 ,
V_281 - 1 ) ;
}
for ( V_305 = 0 ; V_305 < V_327 ; V_305 ++ ) {
if ( ! F_298 ( V_305 ) )
continue;
V_316 = F_268 ( F_258 ( V_305 ) , V_153 , V_316 ,
V_281 - 1 ) ;
}
V_153 -> V_167 [ V_316 ] . V_11 = NULL ;
V_153 -> V_167 [ V_316 ] . F_184 = 0 ;
}
static void F_295 ( T_8 * V_257 )
{
V_257 -> V_317 [ 0 ] . V_157 = NULL ;
}
static T_12 int F_299 ( void * V_302 )
{
int V_237 ;
int V_107 ;
#ifdef F_300
memset ( V_315 , 0 , sizeof( V_315 ) ) ;
#endif
F_290 (nid) {
T_8 * V_257 = F_258 ( V_237 ) ;
F_293 ( V_257 ) ;
F_295 ( V_257 ) ;
}
F_301 (cpu) {
F_302 ( & F_303 ( V_334 , V_107 ) , 0 ) ;
#ifdef F_304
if ( F_305 ( V_107 ) )
F_306 ( V_107 , F_297 ( F_307 ( V_107 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_278 ( void * V_302 )
{
F_292 () ;
if ( V_335 == V_336 ) {
F_299 ( NULL ) ;
F_308 () ;
F_309 () ;
} else {
#ifdef F_310
if ( V_302 )
F_311 ( (struct V_11 * ) V_302 ) ;
#endif
F_312 ( F_299 , NULL , NULL ) ;
}
V_337 = F_251 () ;
if ( V_337 < ( V_92 * V_98 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_21 ( L_58
L_59 ,
V_182 ,
V_338 [ V_324 ] ,
V_7 ? L_60 : L_61 ,
V_337 ) ;
#ifdef F_300
F_21 ( L_62 , V_339 [ V_340 ] ) ;
#endif
}
static inline unsigned long F_313 ( unsigned long V_102 )
{
unsigned long V_82 = 1 ;
V_102 /= V_341 ;
while ( V_82 < V_102 )
V_82 <<= 1 ;
V_82 = V_147 ( V_82 , 4096UL ) ;
return F_314 ( V_82 , 4UL ) ;
}
static inline unsigned long F_313 ( unsigned long V_102 )
{
return 4096UL ;
}
static inline unsigned long F_315 ( unsigned long V_82 )
{
return F_316 ( ~ V_82 ) ;
}
static int F_317 ( unsigned long V_90 , unsigned long V_91 )
{
unsigned long V_14 ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 ++ ) {
if ( ! F_14 ( V_14 ) || F_318 ( F_118 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_319 ( struct V_11 * V_11 )
{
unsigned long V_90 , V_14 , V_91 , V_342 ;
struct V_5 * V_5 ;
unsigned long V_343 ;
int V_344 ;
V_90 = V_11 -> V_15 ;
V_91 = V_90 + V_11 -> V_16 ;
V_90 = F_320 ( V_90 , V_92 ) ;
V_344 = F_320 ( F_265 ( V_11 ) , V_92 ) >>
V_96 ;
V_344 = V_147 ( 2 , V_344 ) ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 += V_92 ) {
if ( ! F_136 ( V_14 ) )
continue;
V_5 = F_118 ( V_14 ) ;
if ( F_114 ( V_5 ) != F_115 ( V_11 ) )
continue;
V_343 = F_96 ( V_5 ) ;
if ( V_344 > 0 ) {
V_342 = V_147 ( V_14 + V_92 , V_91 ) ;
if ( F_317 ( V_14 , V_342 ) )
continue;
if ( V_343 == V_100 ) {
V_344 -- ;
continue;
}
if ( V_343 == V_116 ) {
F_6 ( V_5 ,
V_100 ) ;
F_117 ( V_11 , V_5 ,
V_100 ) ;
V_344 -- ;
continue;
}
}
if ( V_343 == V_100 ) {
F_6 ( V_5 , V_116 ) ;
F_117 ( V_11 , V_5 , V_116 ) ;
}
}
}
void T_3 F_321 ( unsigned long V_82 , int V_237 , unsigned long V_11 ,
unsigned long V_90 , enum V_345 V_346 )
{
struct V_5 * V_5 ;
unsigned long V_91 = V_90 + V_82 ;
unsigned long V_14 ;
struct V_11 * V_142 ;
if ( V_347 < V_91 - 1 )
V_347 = V_91 - 1 ;
V_142 = & F_258 ( V_237 ) -> V_259 [ V_11 ] ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 ++ ) {
if ( V_346 == V_348 ) {
if ( ! F_322 ( V_14 ) )
continue;
if ( ! F_323 ( V_14 , V_237 ) )
continue;
}
V_5 = F_118 ( V_14 ) ;
F_324 ( V_5 , V_11 , V_237 , V_14 ) ;
F_325 ( V_5 , V_11 , V_237 , V_14 ) ;
F_326 ( V_5 ) ;
F_19 ( V_5 ) ;
F_327 ( V_5 ) ;
if ( ( V_142 -> V_15 <= V_14 )
&& ( V_14 < V_142 -> V_15 + V_142 -> V_16 )
&& ! ( V_14 & ( V_92 - 1 ) ) )
F_6 ( V_5 , V_116 ) ;
F_106 ( & V_5 -> V_49 ) ;
#ifdef F_328
if ( ! F_329 ( V_11 ) )
F_330 ( V_5 , F_331 ( V_14 << V_349 ) ) ;
#endif
}
}
static void T_3 F_332 ( struct V_11 * V_11 )
{
int V_27 , V_113 ;
F_139 (order, t) {
F_106 ( & V_11 -> V_50 [ V_27 ] . V_54 [ V_113 ] ) ;
V_11 -> V_50 [ V_27 ] . V_51 = 0 ;
}
}
static int F_333 ( struct V_11 * V_11 )
{
#ifdef F_334
int V_106 ;
V_106 = V_11 -> V_243 / 1024 ;
if ( V_106 * V_75 > 512 * 1024 )
V_106 = ( 512 * 1024 ) / V_75 ;
V_106 /= 4 ;
if ( V_106 < 1 )
V_106 = 1 ;
V_106 = F_335 ( V_106 + V_106 / 2 ) - 1 ;
return V_106 ;
#else
return 0 ;
#endif
}
static void F_302 ( struct V_108 * V_30 , unsigned long V_106 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_62 = 0 ;
V_64 -> V_80 = 6 * V_106 ;
V_64 -> V_106 = F_314 ( 1UL , 1 * V_106 ) ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ )
F_106 ( & V_64 -> V_73 [ V_6 ] ) ;
}
static void F_336 ( struct V_108 * V_30 ,
unsigned long V_80 )
{
struct V_63 * V_64 ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_80 = V_80 ;
V_64 -> V_106 = F_314 ( 1UL , V_80 / 4 ) ;
if ( ( V_80 / 4 ) > ( V_349 * 8 ) )
V_64 -> V_106 = V_349 * 8 ;
}
static void F_311 ( struct V_11 * V_11 )
{
int V_107 ;
V_11 -> V_110 = F_337 ( struct V_108 ) ;
F_301 (cpu) {
struct V_108 * V_64 = F_129 ( V_11 -> V_110 , V_107 ) ;
F_302 ( V_64 , F_333 ( V_11 ) ) ;
if ( V_350 )
F_336 ( V_64 ,
( V_11 -> V_243 /
V_350 ) ) ;
}
}
void T_2 F_338 ( void )
{
struct V_11 * V_11 ;
F_128 (zone)
F_311 ( V_11 ) ;
}
static T_14 T_12
int F_339 ( struct V_11 * V_11 , unsigned long V_351 )
{
int V_28 ;
struct V_352 * V_257 = V_11 -> V_353 ;
T_7 V_354 ;
V_11 -> F_313 =
F_313 ( V_351 ) ;
V_11 -> F_315 =
F_315 ( V_11 -> F_313 ) ;
V_354 = V_11 -> F_313
* sizeof( V_355 ) ;
if ( ! F_340 () ) {
V_11 -> V_356 = ( V_355 * )
F_341 ( V_257 , V_354 ) ;
} else {
V_11 -> V_356 = F_342 ( V_354 ) ;
}
if ( ! V_11 -> V_356 )
return - V_141 ;
for( V_28 = 0 ; V_28 < V_11 -> F_313 ; ++ V_28 )
F_343 ( V_11 -> V_356 + V_28 ) ;
return 0 ;
}
static int F_344 ( void * V_302 )
{
struct V_11 * V_11 = V_302 ;
int V_107 ;
unsigned long V_106 = F_333 ( V_11 ) , V_59 ;
F_301 (cpu) {
struct V_108 * V_109 ;
struct V_63 * V_64 ;
V_109 = F_129 ( V_11 -> V_110 , V_107 ) ;
V_64 = & V_109 -> V_64 ;
F_94 ( V_59 ) ;
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
F_302 ( V_109 , V_106 ) ;
F_97 ( V_59 ) ;
}
return 0 ;
}
void F_345 ( struct V_11 * V_11 )
{
F_312 ( F_344 , V_11 , NULL ) ;
}
static T_3 void F_346 ( struct V_11 * V_11 )
{
V_11 -> V_110 = & V_334 ;
if ( V_11 -> V_243 )
F_21 ( V_357 L_63 ,
V_11 -> V_261 , V_11 -> V_243 ,
F_333 ( V_11 ) ) ;
}
T_3 int F_347 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_82 ,
enum V_345 V_346 )
{
struct V_352 * V_257 = V_11 -> V_353 ;
int V_12 ;
V_12 = F_339 ( V_11 , V_82 ) ;
if ( V_12 )
return V_12 ;
V_257 -> V_285 = F_184 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_348 ( V_358 , L_64 ,
L_65 ,
V_257 -> V_330 ,
( unsigned long ) F_184 ( V_11 ) ,
V_15 , ( V_15 + V_82 ) ) ;
F_332 ( V_11 ) ;
return 0 ;
}
int T_3 F_349 ( unsigned long V_14 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_237 ;
F_350 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_90 <= V_14 && V_14 < V_91 )
return V_237 ;
return - 1 ;
}
int T_3 F_351 ( unsigned long V_14 )
{
int V_237 ;
V_237 = F_349 ( V_14 ) ;
if ( V_237 >= 0 )
return V_237 ;
return 0 ;
}
bool T_3 F_323 ( unsigned long V_14 , int V_305 )
{
int V_237 ;
V_237 = F_349 ( V_14 ) ;
if ( V_237 >= 0 && V_237 != V_305 )
return false ;
return true ;
}
void T_2 F_352 ( int V_237 , unsigned long V_359 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_360 ;
F_350 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_90 = V_147 ( V_90 , V_359 ) ;
V_91 = V_147 ( V_91 , V_359 ) ;
if ( V_90 < V_91 )
F_353 ( F_258 ( V_360 ) ,
F_354 ( V_90 ) ,
( V_91 - V_90 ) << V_349 ) ;
}
}
int T_2 F_355 ( struct V_361 * V_361 , int V_362 ,
int V_363 , int V_237 )
{
unsigned long V_90 , V_91 ;
int V_28 ;
F_350 (i, nid, &start_pfn, &end_pfn, NULL)
V_363 = F_356 ( V_361 , V_362 , V_363 , V_90 , V_91 ) ;
return V_363 ;
}
void T_2 F_357 ( int V_237 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_360 ;
F_350 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_358 ( V_360 , V_90 , V_91 ) ;
}
void T_3 F_359 ( unsigned int V_237 ,
unsigned long * V_90 , unsigned long * V_91 )
{
unsigned long V_364 , V_365 ;
int V_28 ;
* V_90 = - 1UL ;
* V_91 = 0 ;
F_350 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_90 = V_147 ( * V_90 , V_364 ) ;
* V_91 = F_314 ( * V_91 , V_365 ) ;
}
if ( * V_90 == - 1UL )
* V_90 = 0 ;
}
static void T_2 F_360 ( void )
{
int V_366 ;
for ( V_366 = V_281 - 1 ; V_366 >= 0 ; V_366 -- ) {
if ( V_366 == V_367 )
continue;
if ( V_368 [ V_366 ] >
V_369 [ V_366 ] )
break;
}
F_41 ( V_366 == - 1 ) ;
V_370 = V_366 ;
}
static void T_3 F_361 ( int V_237 ,
unsigned long V_204 ,
unsigned long V_371 ,
unsigned long V_372 ,
unsigned long * V_15 ,
unsigned long * V_373 )
{
if ( V_374 [ V_237 ] ) {
if ( V_204 == V_367 ) {
* V_15 = V_374 [ V_237 ] ;
* V_373 = V_147 ( V_372 ,
V_368 [ V_370 ] ) ;
} else if ( * V_15 < V_374 [ V_237 ] &&
* V_373 > V_374 [ V_237 ] ) {
* V_373 = V_374 [ V_237 ] ;
} else if ( * V_15 >= V_374 [ V_237 ] )
* V_15 = * V_373 ;
}
}
static unsigned long T_3 F_362 ( int V_237 ,
unsigned long V_204 ,
unsigned long * V_375 )
{
unsigned long V_371 , V_372 ;
unsigned long V_15 , V_373 ;
F_359 ( V_237 , & V_371 , & V_372 ) ;
V_15 = V_369 [ V_204 ] ;
V_373 = V_368 [ V_204 ] ;
F_361 ( V_237 , V_204 ,
V_371 , V_372 ,
& V_15 , & V_373 ) ;
if ( V_373 < V_371 || V_15 > V_372 )
return 0 ;
V_373 = V_147 ( V_373 , V_372 ) ;
V_15 = F_314 ( V_15 , V_371 ) ;
return V_373 - V_15 ;
}
unsigned long T_3 F_363 ( int V_237 ,
unsigned long V_376 ,
unsigned long V_377 )
{
unsigned long V_378 = V_377 - V_376 ;
unsigned long V_90 , V_91 ;
int V_28 ;
F_350 (i, nid, &start_pfn, &end_pfn, NULL) {
V_90 = F_364 ( V_90 , V_376 , V_377 ) ;
V_91 = F_364 ( V_91 , V_376 , V_377 ) ;
V_378 -= V_91 - V_90 ;
}
return V_378 ;
}
unsigned long T_2 F_365 ( unsigned long V_90 ,
unsigned long V_91 )
{
return F_363 ( V_314 , V_90 , V_91 ) ;
}
static unsigned long T_3 F_366 ( int V_237 ,
unsigned long V_204 ,
unsigned long * V_375 )
{
unsigned long V_379 = V_369 [ V_204 ] ;
unsigned long V_380 = V_368 [ V_204 ] ;
unsigned long V_371 , V_372 ;
unsigned long V_15 , V_373 ;
F_359 ( V_237 , & V_371 , & V_372 ) ;
V_15 = F_364 ( V_371 , V_379 , V_380 ) ;
V_373 = F_364 ( V_372 , V_379 , V_380 ) ;
F_361 ( V_237 , V_204 ,
V_371 , V_372 ,
& V_15 , & V_373 ) ;
return F_363 ( V_237 , V_15 , V_373 ) ;
}
static inline unsigned long T_3 F_362 ( int V_237 ,
unsigned long V_204 ,
unsigned long * V_381 )
{
return V_381 [ V_204 ] ;
}
static inline unsigned long T_3 F_366 ( int V_237 ,
unsigned long V_204 ,
unsigned long * V_382 )
{
if ( ! V_382 )
return 0 ;
return V_382 [ V_204 ] ;
}
static void T_3 F_367 ( struct V_352 * V_257 ,
unsigned long * V_381 , unsigned long * V_382 )
{
unsigned long V_383 , V_384 = 0 ;
enum V_204 V_28 ;
for ( V_28 = 0 ; V_28 < V_281 ; V_28 ++ )
V_384 += F_362 ( V_257 -> V_330 , V_28 ,
V_381 ) ;
V_257 -> V_385 = V_384 ;
V_383 = V_384 ;
for ( V_28 = 0 ; V_28 < V_281 ; V_28 ++ )
V_383 -=
F_366 ( V_257 -> V_330 , V_28 ,
V_382 ) ;
V_257 -> V_258 = V_383 ;
F_21 ( V_357 L_66 , V_257 -> V_330 ,
V_383 ) ;
}
static unsigned long T_2 F_368 ( unsigned long V_386 )
{
unsigned long V_387 ;
V_387 = F_320 ( V_386 , V_92 ) ;
V_387 = V_387 >> V_96 ;
V_387 *= V_388 ;
V_387 = F_320 ( V_387 , 8 * sizeof( unsigned long ) ) ;
return V_387 / 8 ;
}
static void T_2 F_369 ( struct V_352 * V_257 ,
struct V_11 * V_11 , unsigned long V_386 )
{
unsigned long V_387 = F_368 ( V_386 ) ;
V_11 -> V_389 = NULL ;
if ( V_387 )
V_11 -> V_389 = F_341 ( V_257 ,
V_387 ) ;
}
static inline void F_369 ( struct V_352 * V_257 ,
struct V_11 * V_11 , unsigned long V_386 ) {}
static inline int F_370 ( void )
{
if ( V_390 > V_349 )
return V_391 ;
return V_37 - 1 ;
}
static inline void T_2 F_371 ( unsigned int V_27 )
{
if ( V_96 )
return;
V_96 = V_27 ;
}
static inline int F_370 ( unsigned int V_27 )
{
return V_37 - 1 ;
}
static void T_15 F_372 ( struct V_352 * V_257 ,
unsigned long * V_381 , unsigned long * V_382 )
{
enum V_204 V_316 ;
int V_237 = V_257 -> V_330 ;
unsigned long V_15 = V_257 -> V_371 ;
int V_12 ;
F_373 ( V_257 ) ;
V_257 -> V_285 = 0 ;
F_343 ( & V_257 -> V_392 ) ;
V_257 -> V_393 = 0 ;
F_374 ( V_257 ) ;
for ( V_316 = 0 ; V_316 < V_281 ; V_316 ++ ) {
struct V_11 * V_11 = V_257 -> V_259 + V_316 ;
unsigned long V_82 , V_394 , V_395 ;
enum V_396 V_49 ;
V_82 = F_362 ( V_237 , V_316 , V_381 ) ;
V_394 = V_82 - F_366 ( V_237 , V_316 ,
V_382 ) ;
V_395 =
F_239 ( V_82 * sizeof( struct V_5 ) ) >> V_349 ;
if ( V_394 >= V_395 ) {
V_394 -= V_395 ;
if ( V_395 )
F_21 ( V_357
L_67 ,
V_339 [ V_316 ] , V_395 ) ;
} else
F_21 ( V_291
L_68 ,
V_339 [ V_316 ] , V_395 , V_394 ) ;
if ( V_316 == 0 && V_394 > V_397 ) {
V_394 -= V_397 ;
F_21 ( V_357 L_69 ,
V_339 [ 0 ] , V_397 ) ;
}
if ( ! F_329 ( V_316 ) )
V_398 += V_394 ;
V_399 += V_394 ;
V_11 -> V_16 = V_82 ;
V_11 -> V_243 = V_394 ;
#ifdef F_300
V_11 -> V_305 = V_237 ;
V_11 -> V_400 = ( V_394 * V_401 )
/ 100 ;
V_11 -> V_402 = ( V_394 * V_403 ) / 100 ;
#endif
V_11 -> V_261 = V_339 [ V_316 ] ;
F_375 ( & V_11 -> V_67 ) ;
F_375 ( & V_11 -> V_404 ) ;
F_376 ( V_11 ) ;
V_11 -> V_353 = V_257 ;
F_346 ( V_11 ) ;
F_377 (lru)
F_106 ( & V_11 -> V_405 . V_73 [ V_49 ] ) ;
V_11 -> V_406 . V_407 [ 0 ] = 0 ;
V_11 -> V_406 . V_407 [ 1 ] = 0 ;
V_11 -> V_406 . V_408 [ 0 ] = 0 ;
V_11 -> V_406 . V_408 [ 1 ] = 0 ;
F_378 ( V_11 ) ;
V_11 -> V_59 = 0 ;
if ( ! V_82 )
continue;
F_371 ( F_370 () ) ;
F_369 ( V_257 , V_11 , V_82 ) ;
V_12 = F_347 ( V_11 , V_15 ,
V_82 , V_348 ) ;
F_113 ( V_12 ) ;
F_379 ( V_82 , V_237 , V_316 , V_15 ) ;
V_15 += V_82 ;
}
}
static void T_12 F_380 ( struct V_352 * V_257 )
{
if ( ! V_257 -> V_385 )
return;
#ifdef F_381
if ( ! V_257 -> V_409 ) {
unsigned long V_82 , V_410 , V_239 ;
struct V_5 * V_411 ;
V_410 = V_257 -> V_371 & ~ ( V_412 - 1 ) ;
V_239 = V_257 -> V_371 + V_257 -> V_385 ;
V_239 = F_382 ( V_239 , V_412 ) ;
V_82 = ( V_239 - V_410 ) * sizeof( struct V_5 ) ;
V_411 = F_383 ( V_257 -> V_330 , V_82 ) ;
if ( ! V_411 )
V_411 = F_341 ( V_257 , V_82 ) ;
V_257 -> V_409 = V_411 + ( V_257 -> V_371 - V_410 ) ;
}
#ifndef F_384
if ( V_257 == F_258 ( 0 ) ) {
V_413 = F_258 ( 0 ) -> V_409 ;
#ifdef F_385
if ( F_10 ( V_413 ) != V_257 -> V_371 )
V_413 -= ( V_257 -> V_371 - V_414 ) ;
#endif
}
#endif
#endif
}
void T_15 F_386 ( int V_237 , unsigned long * V_381 ,
unsigned long V_371 , unsigned long * V_382 )
{
T_8 * V_257 = F_258 ( V_237 ) ;
V_257 -> V_330 = V_237 ;
V_257 -> V_371 = V_371 ;
F_367 ( V_257 , V_381 , V_382 ) ;
F_380 ( V_257 ) ;
#ifdef F_381
F_21 ( V_357 L_70 ,
V_237 , ( unsigned long ) V_257 ,
( unsigned long ) V_257 -> V_409 ) ;
#endif
F_372 ( V_257 , V_381 , V_382 ) ;
}
static void T_2 F_387 ( void )
{
unsigned int V_305 ;
unsigned int V_415 = 0 ;
F_388 (node, node_possible_map)
V_415 = V_305 ;
V_416 = V_415 + 1 ;
}
static inline void F_387 ( void )
{
}
unsigned long T_2 F_389 ( void )
{
unsigned long V_417 = 0 , V_418 = 0 ;
unsigned long V_410 , V_239 , V_419 ;
int V_420 = - 1 ;
int V_28 , V_237 ;
F_350 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_410 || V_420 < 0 || V_420 == V_237 ) {
V_420 = V_237 ;
V_418 = V_239 ;
continue;
}
V_419 = ~ ( ( 1 << F_390 ( V_410 ) ) - 1 ) ;
while ( V_419 && V_418 <= ( V_410 & ( V_419 << 1 ) ) )
V_419 <<= 1 ;
V_417 |= V_419 ;
}
return ~ V_417 + 1 ;
}
static unsigned long T_2 F_391 ( int V_237 )
{
unsigned long V_421 = V_422 ;
unsigned long V_90 ;
int V_28 ;
F_350 (i, nid, &start_pfn, NULL, NULL)
V_421 = V_147 ( V_421 , V_90 ) ;
if ( V_421 == V_422 ) {
F_21 ( V_291
L_71 , V_237 ) ;
return 0 ;
}
return V_421 ;
}
unsigned long T_2 F_392 ( void )
{
return F_391 ( V_314 ) ;
}
static unsigned long T_2 F_393 ( void )
{
unsigned long V_384 = 0 ;
unsigned long V_90 , V_91 ;
int V_28 , V_237 ;
F_350 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_102 = V_91 - V_90 ;
V_384 += V_102 ;
if ( V_102 )
F_394 ( V_237 , V_164 ) ;
}
return V_384 ;
}
static void T_2 F_395 ( unsigned long * V_423 )
{
int V_28 , V_237 ;
unsigned long V_424 ;
unsigned long V_425 , V_426 ;
T_5 V_427 = V_163 [ V_164 ] ;
unsigned long V_384 = F_393 () ;
int V_428 = F_291 ( V_163 [ V_164 ] ) ;
if ( V_429 ) {
unsigned long V_430 ;
V_429 =
F_320 ( V_429 , V_412 ) ;
V_430 = V_384 - V_429 ;
V_431 = F_314 ( V_431 , V_430 ) ;
}
if ( ! V_431 )
goto V_21;
F_360 () ;
V_424 = V_369 [ V_370 ] ;
V_227:
V_425 = V_431 / V_428 ;
F_283 (nid, N_HIGH_MEMORY) {
unsigned long V_90 , V_91 ;
if ( V_431 < V_425 )
V_425 = V_431 / V_428 ;
V_426 = V_425 ;
F_350 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_432 ;
V_90 = F_314 ( V_90 , V_374 [ V_237 ] ) ;
if ( V_90 >= V_91 )
continue;
if ( V_90 < V_424 ) {
unsigned long V_433 ;
V_433 = V_147 ( V_91 , V_424 )
- V_90 ;
V_426 -= V_147 ( V_433 ,
V_426 ) ;
V_431 -= V_147 ( V_433 ,
V_431 ) ;
if ( V_91 <= V_424 ) {
V_374 [ V_237 ] = V_91 ;
continue;
}
V_90 = V_424 ;
}
V_432 = V_91 - V_90 ;
if ( V_432 > V_426 )
V_432 = V_426 ;
V_374 [ V_237 ] = V_90 + V_432 ;
V_431 -= V_147 ( V_431 ,
V_432 ) ;
V_426 -= V_432 ;
if ( ! V_426 )
break;
}
}
V_428 -- ;
if ( V_428 && V_431 > V_428 )
goto V_227;
for ( V_237 = 0 ; V_237 < V_314 ; V_237 ++ )
V_374 [ V_237 ] =
F_320 ( V_374 [ V_237 ] , V_412 ) ;
V_21:
V_163 [ V_164 ] = V_427 ;
}
static void F_396 ( T_8 * V_257 )
{
#ifdef F_260
enum V_204 V_204 ;
for ( V_204 = 0 ; V_204 <= V_207 ; V_204 ++ ) {
struct V_11 * V_11 = & V_257 -> V_259 [ V_204 ] ;
if ( V_11 -> V_243 ) {
F_394 ( F_115 ( V_11 ) , V_434 ) ;
break;
}
}
#endif
}
void T_2 F_397 ( unsigned long * V_112 )
{
unsigned long V_90 , V_91 ;
int V_28 , V_237 ;
memset ( V_369 , 0 ,
sizeof( V_369 ) ) ;
memset ( V_368 , 0 ,
sizeof( V_368 ) ) ;
V_369 [ 0 ] = F_392 () ;
V_368 [ 0 ] = V_112 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_281 ; V_28 ++ ) {
if ( V_28 == V_367 )
continue;
V_369 [ V_28 ] =
V_368 [ V_28 - 1 ] ;
V_368 [ V_28 ] =
F_314 ( V_112 [ V_28 ] , V_369 [ V_28 ] ) ;
}
V_369 [ V_367 ] = 0 ;
V_368 [ V_367 ] = 0 ;
memset ( V_374 , 0 , sizeof( V_374 ) ) ;
F_395 ( V_374 ) ;
F_21 ( L_72 ) ;
for ( V_28 = 0 ; V_28 < V_281 ; V_28 ++ ) {
if ( V_28 == V_367 )
continue;
F_21 ( L_73 , V_339 [ V_28 ] ) ;
if ( V_369 [ V_28 ] ==
V_368 [ V_28 ] )
F_21 ( L_74 ) ;
else
F_21 ( L_75 ,
V_369 [ V_28 ] ,
V_368 [ V_28 ] ) ;
}
F_21 ( L_76 ) ;
for ( V_28 = 0 ; V_28 < V_314 ; V_28 ++ ) {
if ( V_374 [ V_28 ] )
F_21 ( L_77 , V_28 , V_374 [ V_28 ] ) ;
}
F_21 ( L_78 ) ;
F_350 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_21 ( L_79 , V_237 , V_90 , V_91 ) ;
F_398 () ;
F_387 () ;
F_290 (nid) {
T_8 * V_257 = F_258 ( V_237 ) ;
F_386 ( V_237 , NULL ,
F_391 ( V_237 ) , NULL ) ;
if ( V_257 -> V_258 )
F_394 ( V_237 , V_164 ) ;
F_396 ( V_257 ) ;
}
}
static int T_2 F_399 ( char * V_30 , unsigned long * V_435 )
{
unsigned long long V_436 ;
if ( ! V_30 )
return - V_292 ;
V_436 = F_400 ( V_30 , & V_30 ) ;
* V_435 = V_436 >> V_349 ;
F_2 ( ( V_436 >> V_349 ) > V_422 ) ;
return 0 ;
}
static int T_2 F_401 ( char * V_30 )
{
return F_399 ( V_30 , & V_431 ) ;
}
static int T_2 F_402 ( char * V_30 )
{
return F_399 ( V_30 , & V_429 ) ;
}
void T_2 F_403 ( unsigned long V_437 )
{
V_397 = V_437 ;
}
void T_2 F_404 ( unsigned long * V_381 )
{
F_386 ( 0 , V_381 ,
F_405 ( V_438 ) >> V_349 , NULL ) ;
}
static int F_406 ( struct V_439 * V_440 ,
unsigned long V_441 , void * V_442 )
{
int V_107 = ( unsigned long ) V_442 ;
if ( V_441 == V_443 || V_441 == V_444 ) {
F_127 ( V_107 ) ;
F_407 ( V_107 ) ;
F_408 ( V_107 ) ;
}
return V_445 ;
}
void T_2 F_409 ( void )
{
F_410 ( F_406 , 0 ) ;
}
static void F_411 ( void )
{
struct V_352 * V_257 ;
unsigned long V_446 = 0 ;
enum V_204 V_28 , V_316 ;
F_412 (pgdat) {
for ( V_28 = 0 ; V_28 < V_281 ; V_28 ++ ) {
struct V_11 * V_11 = V_257 -> V_259 + V_28 ;
unsigned long F_314 = 0 ;
for ( V_316 = V_28 ; V_316 < V_281 ; V_316 ++ ) {
if ( V_11 -> V_151 [ V_316 ] > F_314 )
F_314 = V_11 -> V_151 [ V_316 ] ;
}
F_314 += F_249 ( V_11 ) ;
if ( F_314 > V_11 -> V_243 )
F_314 = V_11 -> V_243 ;
V_446 += F_314 ;
V_11 -> V_447 = F_314 ;
}
}
V_447 = V_446 ;
V_448 = V_446 ;
}
static void F_413 ( void )
{
struct V_352 * V_257 ;
enum V_204 V_316 , V_449 ;
F_412 (pgdat) {
for ( V_316 = 0 ; V_316 < V_281 ; V_316 ++ ) {
struct V_11 * V_11 = V_257 -> V_259 + V_316 ;
unsigned long V_243 = V_11 -> V_243 ;
V_11 -> V_151 [ V_316 ] = 0 ;
V_449 = V_316 ;
while ( V_449 ) {
struct V_11 * V_450 ;
V_449 -- ;
if ( V_451 [ V_449 ] < 1 )
V_451 [ V_449 ] = 1 ;
V_450 = V_257 -> V_259 + V_449 ;
V_450 -> V_151 [ V_316 ] = V_243 /
V_451 [ V_449 ] ;
V_243 += V_450 -> V_243 ;
}
}
}
F_411 () ;
}
void F_414 ( void )
{
unsigned long V_452 = V_453 >> ( V_349 - 10 ) ;
unsigned long V_454 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_415 (zone) {
if ( ! F_416 ( V_11 ) )
V_454 += V_11 -> V_243 ;
}
F_415 (zone) {
T_16 V_311 ;
F_135 ( & V_11 -> V_67 , V_59 ) ;
V_311 = ( T_16 ) V_452 * V_11 -> V_243 ;
F_417 ( V_311 , V_454 ) ;
if ( F_416 ( V_11 ) ) {
int V_455 ;
V_455 = V_11 -> V_243 / 1024 ;
if ( V_455 < V_456 )
V_455 = V_456 ;
if ( V_455 > 128 )
V_455 = 128 ;
V_11 -> V_118 [ V_457 ] = V_455 ;
} else {
V_11 -> V_118 [ V_457 ] = V_311 ;
}
V_11 -> V_118 [ V_458 ] = F_265 ( V_11 ) + ( V_311 >> 2 ) ;
V_11 -> V_118 [ V_459 ] = F_265 ( V_11 ) + ( V_311 >> 1 ) ;
F_319 ( V_11 ) ;
F_142 ( & V_11 -> V_67 , V_59 ) ;
}
F_411 () ;
}
static void T_3 F_418 ( struct V_11 * V_11 )
{
unsigned int V_460 , V_461 ;
V_460 = V_11 -> V_243 >> ( 30 - V_349 ) ;
if ( V_460 )
V_461 = F_419 ( 10 * V_460 ) ;
else
V_461 = 1 ;
V_11 -> V_462 = V_461 ;
}
static void T_3 F_420 ( void )
{
struct V_11 * V_11 ;
F_415 (zone)
F_418 ( V_11 ) ;
}
int T_3 F_421 ( void )
{
unsigned long V_463 ;
V_463 = F_250 () * ( V_75 >> 10 ) ;
V_453 = F_419 ( V_463 * 16 ) ;
if ( V_453 < 128 )
V_453 = 128 ;
if ( V_453 > 65536 )
V_453 = 65536 ;
F_414 () ;
F_422 () ;
F_413 () ;
F_420 () ;
return 0 ;
}
int F_423 ( T_9 * V_295 , int V_296 ,
void T_10 * V_297 , T_7 * V_298 , T_11 * V_299 )
{
F_424 ( V_295 , V_296 , V_297 , V_298 , V_299 ) ;
if ( V_296 )
F_414 () ;
return 0 ;
}
int F_425 ( T_9 * V_295 , int V_296 ,
void T_10 * V_297 , T_7 * V_298 , T_11 * V_299 )
{
struct V_11 * V_11 ;
int V_464 ;
V_464 = F_426 ( V_295 , V_296 , V_297 , V_298 , V_299 ) ;
if ( V_464 )
return V_464 ;
F_415 (zone)
V_11 -> V_400 = ( V_11 -> V_243 *
V_401 ) / 100 ;
return 0 ;
}
int F_427 ( T_9 * V_295 , int V_296 ,
void T_10 * V_297 , T_7 * V_298 , T_11 * V_299 )
{
struct V_11 * V_11 ;
int V_464 ;
V_464 = F_426 ( V_295 , V_296 , V_297 , V_298 , V_299 ) ;
if ( V_464 )
return V_464 ;
F_415 (zone)
V_11 -> V_402 = ( V_11 -> V_243 *
V_403 ) / 100 ;
return 0 ;
}
int F_428 ( T_9 * V_295 , int V_296 ,
void T_10 * V_297 , T_7 * V_298 , T_11 * V_299 )
{
F_426 ( V_295 , V_296 , V_297 , V_298 , V_299 ) ;
F_413 () ;
return 0 ;
}
int F_429 ( T_9 * V_295 , int V_296 ,
void T_10 * V_297 , T_7 * V_298 , T_11 * V_299 )
{
struct V_11 * V_11 ;
unsigned int V_107 ;
int V_12 ;
V_12 = F_426 ( V_295 , V_296 , V_297 , V_298 , V_299 ) ;
if ( ! V_296 || ( V_12 == - V_292 ) )
return V_12 ;
F_128 (zone) {
F_301 (cpu) {
unsigned long V_80 ;
V_80 = V_11 -> V_243 / V_350 ;
F_336 (
F_129 ( V_11 -> V_110 , V_107 ) , V_80 ) ;
}
}
return 0 ;
}
static int T_2 F_430 ( char * V_126 )
{
if ( ! V_126 )
return 0 ;
V_465 = F_431 ( V_126 , & V_126 , 0 ) ;
return 1 ;
}
void * T_2 F_432 ( const char * V_466 ,
unsigned long V_467 ,
unsigned long V_468 ,
int V_469 ,
int V_59 ,
unsigned int * V_470 ,
unsigned int * V_471 ,
unsigned long V_472 )
{
unsigned long long F_314 = V_472 ;
unsigned long V_473 , V_82 ;
void * V_295 = NULL ;
if ( ! V_468 ) {
V_468 = V_398 ;
V_468 += ( 1UL << ( 20 - V_349 ) ) - 1 ;
V_468 >>= 20 - V_349 ;
V_468 <<= 20 - V_349 ;
if ( V_469 > V_349 )
V_468 >>= ( V_469 - V_349 ) ;
else
V_468 <<= ( V_349 - V_469 ) ;
if ( F_7 ( V_59 & V_474 ) ) {
F_2 ( ! ( V_59 & V_475 ) ) ;
if ( ! ( V_468 >> * V_470 ) ) {
V_468 = 1UL << * V_470 ;
F_113 ( ! V_468 ) ;
}
} else if ( F_7 ( ( V_468 * V_467 ) < V_75 ) )
V_468 = V_75 / V_467 ;
}
V_468 = F_433 ( V_468 ) ;
if ( F_314 == 0 ) {
F_314 = ( ( unsigned long long ) V_399 << V_349 ) >> 4 ;
F_417 ( F_314 , V_467 ) ;
}
F_314 = V_147 ( F_314 , 0x80000000ULL ) ;
if ( V_468 > F_314 )
V_468 = F_314 ;
V_473 = F_434 ( V_468 ) ;
do {
V_82 = V_467 << V_473 ;
if ( V_59 & V_475 )
V_295 = F_435 ( V_82 ) ;
else if ( V_465 )
V_295 = F_436 ( V_82 , V_476 , V_477 ) ;
else {
if ( F_242 ( V_82 ) < V_37 ) {
V_295 = F_241 ( V_82 , V_476 ) ;
F_437 ( V_295 , V_82 , 1 , V_476 ) ;
}
}
} while ( ! V_295 && V_82 > V_75 && -- V_473 );
if ( ! V_295 )
F_438 ( L_80 , V_466 ) ;
F_21 ( V_40 L_81 ,
V_466 ,
( 1UL << V_473 ) ,
F_434 ( V_82 ) - V_349 ,
V_82 ) ;
if ( V_470 )
* V_470 = V_473 ;
if ( V_471 )
* V_471 = ( 1 << V_473 ) - 1 ;
return V_295 ;
}
static inline unsigned long * F_439 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_440
return F_441 ( V_14 ) -> V_389 ;
#else
return V_11 -> V_389 ;
#endif
}
static inline int F_442 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_440
V_14 &= ( V_478 - 1 ) ;
return ( V_14 >> V_96 ) * V_388 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_96 ) * V_388 ;
#endif
}
unsigned long F_443 ( struct V_5 * V_5 ,
int V_479 , int V_480 )
{
struct V_11 * V_11 ;
unsigned long * V_481 ;
unsigned long V_14 , V_482 ;
unsigned long V_59 = 0 ;
unsigned long V_483 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_481 = F_439 ( V_11 , V_14 ) ;
V_482 = F_442 ( V_11 , V_14 ) ;
for (; V_479 <= V_480 ; V_479 ++ , V_483 <<= 1 )
if ( F_179 ( V_482 + V_479 , V_481 ) )
V_59 |= V_483 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_479 , int V_480 )
{
struct V_11 * V_11 ;
unsigned long * V_481 ;
unsigned long V_14 , V_482 ;
unsigned long V_483 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_481 = F_439 ( V_11 , V_14 ) ;
V_482 = F_442 ( V_11 , V_14 ) ;
F_41 ( V_14 < V_11 -> V_15 ) ;
F_41 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_479 <= V_480 ; V_479 ++ , V_483 <<= 1 )
if ( V_59 & V_483 )
F_47 ( V_482 + V_479 , V_481 ) ;
else
F_49 ( V_482 + V_479 , V_481 ) ;
}
static int
F_444 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 )
{
unsigned long V_14 , V_484 , V_485 ;
if ( F_184 ( V_11 ) == V_367 )
return true ;
if ( F_96 ( V_5 ) == V_116 )
return true ;
V_14 = F_10 ( V_5 ) ;
for ( V_485 = 0 , V_484 = 0 ; V_484 < V_92 ; V_484 ++ ) {
unsigned long V_486 = V_14 + V_484 ;
if ( ! F_14 ( V_486 ) )
continue;
V_5 = F_118 ( V_486 ) ;
if ( ! F_60 ( V_5 ) ) {
if ( F_61 ( V_5 ) )
V_484 += ( 1 << F_59 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_445 ( V_5 ) )
V_485 ++ ;
if ( V_485 > V_62 )
return false ;
}
return true ;
}
bool F_446 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_298 ( F_114 ( V_5 ) ) )
return false ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( V_11 -> V_15 > V_14 ||
V_11 -> V_15 + V_11 -> V_16 <= V_14 )
return false ;
return F_444 ( V_11 , V_5 , 0 ) ;
}
int F_447 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_59 , V_14 ;
struct V_487 V_111 ;
int V_488 ;
int V_12 = - V_489 ;
V_11 = F_15 ( V_5 ) ;
F_135 ( & V_11 -> V_67 , V_59 ) ;
V_14 = F_10 ( V_5 ) ;
V_111 . V_90 = V_14 ;
V_111 . V_29 = V_92 ;
V_111 . V_490 = 0 ;
V_488 = V_487 ( V_491 , & V_111 ) ;
V_488 = F_448 ( V_488 ) ;
if ( V_488 )
goto V_21;
if ( F_444 ( V_11 , V_5 , V_111 . V_490 ) )
V_12 = 0 ;
V_21:
if ( ! V_12 ) {
F_6 ( V_5 , V_115 ) ;
F_117 ( V_11 , V_5 , V_115 ) ;
}
F_142 ( & V_11 -> V_67 , V_59 ) ;
if ( ! V_12 )
F_132 () ;
return V_12 ;
}
void F_449 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_59 ;
V_11 = F_15 ( V_5 ) ;
F_135 ( & V_11 -> V_67 , V_59 ) ;
if ( F_96 ( V_5 ) != V_115 )
goto V_21;
F_6 ( V_5 , V_116 ) ;
F_117 ( V_11 , V_5 , V_116 ) ;
V_21:
F_142 ( & V_11 -> V_67 , V_59 ) ;
}
void
F_450 ( unsigned long V_90 , unsigned long V_91 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_27 , V_28 ;
unsigned long V_14 ;
unsigned long V_59 ;
for ( V_14 = V_90 ; V_14 < V_91 ; V_14 ++ )
if ( F_136 ( V_14 ) )
break;
if ( V_14 == V_91 )
return;
V_11 = F_15 ( F_118 ( V_14 ) ) ;
F_135 ( & V_11 -> V_67 , V_59 ) ;
V_14 = V_90 ;
while ( V_14 < V_91 ) {
if ( ! F_136 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_118 ( V_14 ) ;
F_113 ( F_60 ( V_5 ) ) ;
F_113 ( ! F_61 ( V_5 ) ) ;
V_27 = F_59 ( V_5 ) ;
#ifdef F_451
F_21 ( V_40 L_82 ,
V_14 , 1 << V_27 , V_91 ) ;
#endif
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_64 ( V_11 , V_48 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_327 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_142 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_452 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_27 ;
F_135 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
struct V_5 * V_492 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_61 ( V_492 ) && F_59 ( V_492 ) >= V_27 )
break;
}
F_142 ( & V_11 -> V_67 , V_59 ) ;
return V_27 < V_37 ;
}
static void F_453 ( unsigned long V_59 )
{
const char * V_493 = L_83 ;
unsigned long V_419 ;
int V_28 ;
F_21 ( V_22 L_84 , V_59 ) ;
V_59 &= ( 1UL << V_494 ) - 1 ;
for ( V_28 = 0 ; V_495 [ V_28 ] . V_261 && V_59 ; V_28 ++ ) {
V_419 = V_495 [ V_28 ] . V_419 ;
if ( ( V_59 & V_419 ) != V_419 )
continue;
V_59 &= ~ V_419 ;
F_21 ( L_85 , V_493 , V_495 [ V_28 ] . V_261 ) ;
V_493 = L_86 ;
}
if ( V_59 )
F_21 ( L_87 , V_493 , V_59 ) ;
F_21 ( L_88 ) ;
}
void F_22 ( struct V_5 * V_5 )
{
F_21 ( V_22
L_89 ,
V_5 , F_73 ( & V_5 -> V_58 ) , F_72 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_496 ) ;
F_453 ( V_5 -> V_59 ) ;
F_454 ( V_5 ) ;
}
