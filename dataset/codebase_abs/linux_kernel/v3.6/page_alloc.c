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
V_53 = V_52 + ( V_47 - V_45 ) ;
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
void T_2 F_103 ( struct V_5 * V_5 )
{
unsigned V_28 = V_79 ;
struct V_5 * V_30 = V_5 ;
do {
F_100 ( V_30 ) ;
F_34 ( V_30 , 0 ) ;
} while ( ++ V_30 , -- V_28 );
F_101 ( V_5 ) ;
F_6 ( V_5 , V_80 ) ;
F_102 ( V_5 , V_81 ) ;
V_82 += V_79 ;
}
static inline void F_104 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_83 , int V_84 , struct V_50 * V_85 ,
int V_6 )
{
unsigned long V_86 = 1 << V_84 ;
while ( V_84 > V_83 ) {
V_85 -- ;
V_84 -- ;
V_86 >>= 1 ;
F_41 ( F_16 ( V_11 , & V_5 [ V_86 ] ) ) ;
#ifdef F_105
if ( V_84 < F_106 () ) {
F_107 ( & V_5 [ V_86 ] . V_49 ) ;
F_46 ( & V_5 [ V_86 ] ) ;
F_51 ( & V_5 [ V_86 ] , V_84 ) ;
F_64 ( V_11 , V_48 , - ( 1 << V_84 ) ) ;
continue;
}
#endif
F_67 ( & V_5 [ V_86 ] . V_49 , & V_85 -> V_54 [ V_6 ] ) ;
V_85 -> V_51 ++ ;
F_50 ( & V_5 [ V_86 ] , V_84 ) ;
}
}
static inline int F_108 ( struct V_5 * V_5 )
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
static int F_109 ( struct V_5 * V_5 , int V_27 , T_1 V_33 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ ) {
struct V_5 * V_30 = V_5 + V_28 ;
if ( F_7 ( F_108 ( V_30 ) ) )
return 1 ;
}
F_51 ( V_5 , 0 ) ;
F_101 ( V_5 ) ;
F_110 ( V_5 , V_27 ) ;
F_92 ( V_5 , 1 << V_27 , 1 ) ;
if ( V_33 & V_87 )
F_40 ( V_5 , V_27 , V_33 ) ;
if ( V_27 && ( V_33 & V_88 ) )
F_29 ( V_5 , V_27 ) ;
return 0 ;
}
static inline
struct V_5 * F_111 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
unsigned int V_89 ;
struct V_50 * V_85 ;
struct V_5 * V_5 ;
for ( V_89 = V_27 ; V_89 < V_37 ; ++ V_89 ) {
V_85 = & ( V_11 -> V_50 [ V_89 ] ) ;
if ( F_77 ( & V_85 -> V_54 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_85 -> V_54 [ V_6 ] . V_90 ,
struct V_5 , V_49 ) ;
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
V_85 -> V_51 -- ;
F_104 ( V_11 , V_5 , V_27 , V_89 , V_85 , V_6 ) ;
return V_5 ;
}
return NULL ;
}
static int F_112 ( struct V_11 * V_11 ,
struct V_5 * V_91 , struct V_5 * V_92 ,
int V_6 )
{
struct V_5 * V_5 ;
unsigned long V_27 ;
int V_93 = 0 ;
#ifndef F_113
F_114 ( F_15 ( V_91 ) != F_15 ( V_92 ) ) ;
#endif
for ( V_5 = V_91 ; V_5 <= V_92 ; ) {
F_41 ( F_115 ( V_5 ) != F_116 ( V_11 ) ) ;
if ( ! F_14 ( F_10 ( V_5 ) ) ) {
V_5 ++ ;
continue;
}
if ( ! F_61 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_27 = F_59 ( V_5 ) ;
F_117 ( & V_5 -> V_49 ,
& V_11 -> V_50 [ V_27 ] . V_54 [ V_6 ] ) ;
V_5 += 1 << V_27 ;
V_93 += 1 << V_27 ;
}
return V_93 ;
}
int F_118 ( struct V_11 * V_11 , struct V_5 * V_5 ,
int V_6 )
{
unsigned long V_94 , V_95 ;
struct V_5 * V_91 , * V_92 ;
V_94 = F_10 ( V_5 ) ;
V_94 = V_94 & ~ ( V_79 - 1 ) ;
V_91 = F_119 ( V_94 ) ;
V_92 = V_91 + V_79 - 1 ;
V_95 = V_94 + V_79 - 1 ;
if ( V_94 < V_11 -> V_15 )
V_91 = V_5 ;
if ( V_95 >= V_11 -> V_15 + V_11 -> V_16 )
return 0 ;
return F_112 ( V_11 , V_91 , V_92 , V_6 ) ;
}
static void F_120 ( struct V_5 * V_96 ,
int V_97 , int V_6 )
{
int V_98 = 1 << ( V_97 - V_81 ) ;
while ( V_98 -- ) {
F_6 ( V_96 , V_6 ) ;
V_96 += V_79 ;
}
}
static inline struct V_5 *
F_121 ( struct V_11 * V_11 , int V_27 , int V_99 )
{
struct V_50 * V_85 ;
int V_89 ;
struct V_5 * V_5 ;
int V_6 , V_28 ;
for ( V_89 = V_37 - 1 ; V_89 >= V_27 ;
-- V_89 ) {
for ( V_28 = 0 ; ; V_28 ++ ) {
V_6 = V_100 [ V_99 ] [ V_28 ] ;
if ( V_6 == V_101 )
break;
V_85 = & ( V_11 -> V_50 [ V_89 ] ) ;
if ( F_77 ( & V_85 -> V_54 [ V_6 ] ) )
continue;
V_5 = F_78 ( V_85 -> V_54 [ V_6 ] . V_90 ,
struct V_5 , V_49 ) ;
V_85 -> V_51 -- ;
if ( ! F_122 ( V_6 ) &&
( F_7 ( V_89 >= V_81 / 2 ) ||
V_99 == V_102 ||
V_7 ) ) {
int V_103 ;
V_103 = F_118 ( V_11 , V_5 ,
V_99 ) ;
if ( V_103 >= ( 1 << ( V_81 - 1 ) ) ||
V_7 )
F_6 ( V_5 ,
V_99 ) ;
V_6 = V_99 ;
}
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
if ( V_89 >= V_81 &&
! F_122 ( V_6 ) )
F_120 ( V_5 , V_89 ,
V_99 ) ;
F_104 ( V_11 , V_5 , V_27 , V_89 , V_85 ,
F_122 ( V_6 )
? V_6 : V_99 ) ;
F_123 ( V_5 , V_27 , V_89 ,
V_99 , V_6 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_5 * F_124 ( struct V_11 * V_11 , unsigned int V_27 ,
int V_6 )
{
struct V_5 * V_5 ;
V_104:
V_5 = F_111 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( ! V_5 ) && V_6 != V_101 ) {
V_5 = F_121 ( V_11 , V_27 , V_6 ) ;
if ( ! V_5 ) {
V_6 = V_101 ;
goto V_104;
}
}
F_125 ( V_5 , V_27 , V_6 ) ;
return V_5 ;
}
static int F_126 ( struct V_11 * V_11 , unsigned int V_27 ,
unsigned long V_62 , struct V_70 * V_71 ,
int V_6 , int V_105 )
{
int V_106 = V_6 , V_28 ;
F_76 ( & V_11 -> V_67 ) ;
for ( V_28 = 0 ; V_28 < V_62 ; ++ V_28 ) {
struct V_5 * V_5 = F_124 ( V_11 , V_27 , V_6 ) ;
if ( F_7 ( V_5 == NULL ) )
break;
if ( F_127 ( V_105 == 0 ) )
F_67 ( & V_5 -> V_49 , V_71 ) ;
else
F_66 ( & V_5 -> V_49 , V_71 ) ;
if ( F_128 ( V_107 ) ) {
V_106 = F_96 ( V_5 ) ;
if ( ! F_122 ( V_106 ) && V_106 != V_108 )
V_106 = V_6 ;
}
F_51 ( V_5 , V_106 ) ;
V_71 = & V_5 -> V_49 ;
}
F_64 ( V_11 , V_48 , - ( V_28 << V_27 ) ) ;
F_81 ( & V_11 -> V_67 ) ;
return V_28 ;
}
void F_129 ( struct V_11 * V_11 , struct V_63 * V_64 )
{
unsigned long V_59 ;
int V_109 ;
F_94 ( V_59 ) ;
if ( V_64 -> V_62 >= V_64 -> V_110 )
V_109 = V_64 -> V_110 ;
else
V_109 = V_64 -> V_62 ;
if ( V_109 > 0 ) {
F_75 ( V_11 , V_109 , V_64 ) ;
V_64 -> V_62 -= V_109 ;
}
F_97 ( V_59 ) ;
}
static void F_130 ( unsigned int V_111 )
{
unsigned long V_59 ;
struct V_11 * V_11 ;
F_131 (zone) {
struct V_112 * V_113 ;
struct V_63 * V_64 ;
F_94 ( V_59 ) ;
V_113 = F_132 ( V_11 -> V_114 , V_111 ) ;
V_64 = & V_113 -> V_64 ;
if ( V_64 -> V_62 ) {
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
V_64 -> V_62 = 0 ;
}
F_97 ( V_59 ) ;
}
}
void F_133 ( void * V_115 )
{
F_130 ( F_134 () ) ;
}
void F_135 ( void )
{
int V_111 ;
struct V_112 * V_64 ;
struct V_11 * V_11 ;
static T_4 V_116 ;
F_136 (cpu) {
bool V_117 = false ;
F_131 (zone) {
V_64 = F_132 ( V_11 -> V_114 , V_111 ) ;
if ( V_64 -> V_64 . V_62 ) {
V_117 = true ;
break;
}
}
if ( V_117 )
F_137 ( V_111 , & V_116 ) ;
else
F_138 ( V_111 , & V_116 ) ;
}
F_139 ( & V_116 , F_133 , NULL , 1 ) ;
}
void F_140 ( struct V_11 * V_11 )
{
unsigned long V_14 , V_118 ;
unsigned long V_59 ;
int V_27 , V_119 ;
struct V_70 * V_120 ;
if ( ! V_11 -> V_16 )
return;
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_118 = V_11 -> V_15 + V_11 -> V_16 ;
for ( V_14 = V_11 -> V_15 ; V_14 < V_118 ; V_14 ++ )
if ( F_142 ( V_14 ) ) {
struct V_5 * V_5 = F_119 ( V_14 ) ;
if ( ! F_143 ( V_5 ) )
F_144 ( V_5 ) ;
}
F_145 (order, t) {
F_146 (curr, &zone->free_area[order].free_list[t]) {
unsigned long V_28 ;
V_14 = F_10 ( F_78 ( V_120 , struct V_5 , V_49 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1UL << V_27 ) ; V_28 ++ )
F_147 ( F_119 ( V_14 + V_28 ) ) ;
}
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
}
void F_149 ( struct V_5 * V_5 , int V_105 )
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
if ( F_7 ( V_6 == V_108 ) ) {
F_82 ( V_11 , V_5 , 0 , V_6 ) ;
goto V_21;
}
V_6 = V_121 ;
}
V_64 = & F_150 ( V_11 -> V_114 ) -> V_64 ;
if ( V_105 )
F_66 ( & V_5 -> V_49 , & V_64 -> V_73 [ V_6 ] ) ;
else
F_67 ( & V_5 -> V_49 , & V_64 -> V_73 [ V_6 ] ) ;
V_64 -> V_62 ++ ;
if ( V_64 -> V_62 >= V_64 -> V_84 ) {
F_75 ( V_11 , V_64 -> V_110 , V_64 ) ;
V_64 -> V_62 -= V_64 -> V_110 ;
}
V_21:
F_97 ( V_59 ) ;
}
void F_151 ( struct V_70 * V_71 , int V_105 )
{
struct V_5 * V_5 , * V_90 ;
F_152 (page, next, list, lru) {
F_153 ( V_5 , V_105 ) ;
F_149 ( V_5 , V_105 ) ;
}
}
void F_154 ( struct V_5 * V_5 , unsigned int V_27 )
{
int V_28 ;
F_41 ( F_63 ( V_5 ) ) ;
F_41 ( ! F_60 ( V_5 ) ) ;
#ifdef F_155
if ( F_156 ( V_5 ) )
F_154 ( F_157 ( V_5 [ 0 ] . V_122 ) , V_27 ) ;
#endif
for ( V_28 = 1 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_101 ( V_5 + V_28 ) ;
}
int F_158 ( struct V_5 * V_5 )
{
unsigned int V_27 ;
unsigned long V_123 ;
struct V_11 * V_11 ;
F_114 ( ! F_61 ( V_5 ) ) ;
V_11 = F_15 ( V_5 ) ;
V_27 = F_59 ( V_5 ) ;
V_123 = F_159 ( V_11 ) + ( 1 << V_27 ) ;
if ( ! F_160 ( V_11 , 0 , V_123 , 0 , 0 ) )
return 0 ;
F_65 ( & V_5 -> V_49 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_53 ( V_5 ) ;
F_64 ( V_11 , V_48 , - ( 1UL << V_27 ) ) ;
F_101 ( V_5 ) ;
F_154 ( V_5 , V_27 ) ;
if ( V_27 >= V_81 - 1 ) {
struct V_5 * V_124 = V_5 + ( 1 << V_27 ) - 1 ;
for (; V_5 < V_124 ; V_5 += V_79 ) {
int V_106 = F_96 ( V_5 ) ;
if ( V_106 != V_108 && ! F_122 ( V_106 ) )
F_6 ( V_5 ,
V_121 ) ;
}
}
return 1 << V_27 ;
}
static inline
struct V_5 * F_161 ( struct V_11 * V_125 ,
struct V_11 * V_11 , int V_27 , T_1 V_33 ,
int V_6 )
{
unsigned long V_59 ;
struct V_5 * V_5 ;
int V_105 = ! ! ( V_33 & V_126 ) ;
V_127:
if ( F_127 ( V_27 == 0 ) ) {
struct V_63 * V_64 ;
struct V_70 * V_71 ;
F_94 ( V_59 ) ;
V_64 = & F_150 ( V_11 -> V_114 ) -> V_64 ;
V_71 = & V_64 -> V_73 [ V_6 ] ;
if ( F_77 ( V_71 ) ) {
V_64 -> V_62 += F_126 ( V_11 , 0 ,
V_64 -> V_110 , V_71 ,
V_6 , V_105 ) ;
if ( F_7 ( F_77 ( V_71 ) ) )
goto V_128;
}
if ( V_105 )
V_5 = F_78 ( V_71 -> V_74 , struct V_5 , V_49 ) ;
else
V_5 = F_78 ( V_71 -> V_90 , struct V_5 , V_49 ) ;
F_65 ( & V_5 -> V_49 ) ;
V_64 -> V_62 -- ;
} else {
if ( F_7 ( V_33 & V_129 ) ) {
F_162 ( V_27 > 1 ) ;
}
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_5 = F_124 ( V_11 , V_27 , V_6 ) ;
F_81 ( & V_11 -> V_67 ) ;
if ( ! V_5 )
goto V_128;
F_64 ( V_11 , V_48 , - ( 1 << V_27 ) ) ;
}
F_163 ( V_130 , V_11 , 1 << V_27 ) ;
F_164 ( V_125 , V_11 , V_33 ) ;
F_97 ( V_59 ) ;
F_41 ( F_16 ( V_11 , V_5 ) ) ;
if ( F_109 ( V_5 , V_27 , V_33 ) )
goto V_127;
return V_5 ;
V_128:
F_97 ( V_59 ) ;
return NULL ;
}
static int T_2 F_165 ( char * V_131 )
{
return F_166 ( & V_132 . V_133 , V_131 ) ;
}
static bool F_167 ( T_1 V_134 , unsigned int V_27 )
{
if ( V_27 < V_132 . V_135 )
return false ;
if ( V_134 & V_129 )
return false ;
if ( V_132 . V_136 && ( V_134 & V_34 ) )
return false ;
if ( V_132 . V_137 && ( V_134 & V_138 ) )
return false ;
return F_168 ( & V_132 . V_133 , 1 << V_27 ) ;
}
static int T_2 F_169 ( void )
{
T_5 V_139 = V_140 | V_141 | V_142 ;
struct V_143 * V_144 ;
V_144 = F_170 ( L_5 , NULL ,
& V_132 . V_133 ) ;
if ( F_171 ( V_144 ) )
return F_172 ( V_144 ) ;
if ( ! F_173 ( L_6 , V_139 , V_144 ,
& V_132 . V_137 ) )
goto V_145;
if ( ! F_173 ( L_7 , V_139 , V_144 ,
& V_132 . V_136 ) )
goto V_145;
if ( ! F_174 ( L_8 , V_139 , V_144 ,
& V_132 . V_135 ) )
goto V_145;
return 0 ;
V_145:
F_175 ( V_144 ) ;
return - V_146 ;
}
static inline bool F_167 ( T_1 V_134 , unsigned int V_27 )
{
return false ;
}
static bool F_176 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 , long V_151 )
{
long V_152 = V_148 ;
long V_153 = V_147 -> V_153 [ V_149 ] ;
int V_154 ;
V_151 -= ( 1 << V_27 ) - 1 ;
if ( V_150 & V_155 )
V_152 -= V_152 / 2 ;
if ( V_150 & V_156 )
V_152 -= V_152 / 4 ;
if ( V_151 <= V_152 + V_153 )
return false ;
for ( V_154 = 0 ; V_154 < V_27 ; V_154 ++ ) {
V_151 -= V_147 -> V_50 [ V_154 ] . V_51 << V_154 ;
V_152 >>= 1 ;
if ( V_151 <= V_152 )
return false ;
}
return true ;
}
static inline unsigned long F_177 ( struct V_11 * V_11 )
{
if ( F_7 ( V_11 -> V_157 ) )
return V_11 -> V_157 * V_79 ;
return 0 ;
}
static inline unsigned long F_177 ( struct V_11 * V_11 )
{
return 0 ;
}
bool F_160 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 )
{
return F_176 ( V_147 , V_27 , V_148 , V_149 , V_150 ,
F_178 ( V_147 , V_48 ) ) ;
}
bool F_179 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 )
{
long V_151 = F_178 ( V_147 , V_48 ) ;
if ( V_147 -> V_158 && V_151 < V_147 -> V_158 )
V_151 = F_180 ( V_147 , V_48 ) ;
V_151 -= F_177 ( V_147 ) ;
return F_176 ( V_147 , V_27 , V_148 , V_149 , V_150 ,
V_151 ) ;
}
static T_6 * F_181 ( struct V_159 * V_159 , int V_150 )
{
struct V_160 * V_161 ;
T_6 * V_162 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return NULL ;
if ( F_182 ( V_20 , V_161 -> V_164 + V_23 ) ) {
F_183 ( V_161 -> V_165 , V_166 ) ;
V_161 -> V_164 = V_20 ;
}
V_162 = ! F_42 () && ( V_150 & V_167 ) ?
& V_168 :
& V_169 [ V_170 ] ;
return V_162 ;
}
static int F_184 ( struct V_159 * V_159 , struct V_171 * V_147 ,
T_6 * V_162 )
{
struct V_160 * V_161 ;
int V_28 ;
int V_172 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return 1 ;
V_28 = V_147 - V_159 -> V_173 ;
V_172 = V_161 -> V_174 [ V_28 ] ;
return F_185 ( V_172 , * V_162 ) && ! F_186 ( V_28 , V_161 -> V_165 ) ;
}
static void F_187 ( struct V_159 * V_159 , struct V_171 * V_147 )
{
struct V_160 * V_161 ;
int V_28 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return;
V_28 = V_147 - V_159 -> V_173 ;
F_188 ( V_28 , V_161 -> V_165 ) ;
}
static void F_189 ( struct V_159 * V_159 )
{
struct V_160 * V_161 ;
V_161 = V_159 -> V_163 ;
if ( ! V_161 )
return;
F_183 ( V_161 -> V_165 , V_166 ) ;
}
static T_6 * F_181 ( struct V_159 * V_159 , int V_150 )
{
return NULL ;
}
static int F_184 ( struct V_159 * V_159 , struct V_171 * V_147 ,
T_6 * V_162 )
{
return 1 ;
}
static void F_187 ( struct V_159 * V_159 , struct V_171 * V_147 )
{
}
static void F_189 ( struct V_159 * V_159 )
{
}
static struct V_5 *
F_190 ( T_1 V_134 , T_6 * V_175 , unsigned int V_27 ,
struct V_159 * V_159 , int V_176 , int V_150 ,
struct V_11 * V_125 , int V_6 )
{
struct V_171 * V_147 ;
struct V_5 * V_5 = NULL ;
int V_149 ;
struct V_11 * V_11 ;
T_6 * V_162 = NULL ;
int V_177 = 0 ;
int V_178 = 0 ;
V_149 = F_191 ( V_125 ) ;
V_179:
F_192 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_180 && V_177 &&
! F_184 ( V_159 , V_147 , V_162 ) )
continue;
if ( ( V_150 & V_167 ) &&
! F_193 ( V_11 , V_134 ) )
continue;
if ( ( V_150 & V_181 ) &&
( V_134 & V_182 ) && ! F_194 ( V_11 ) )
goto V_183;
F_195 ( V_184 < V_185 ) ;
if ( ! ( V_150 & V_184 ) ) {
unsigned long V_148 ;
int V_12 ;
V_148 = V_11 -> V_123 [ V_150 & V_186 ] ;
if ( F_160 ( V_11 , V_27 , V_148 ,
V_149 , V_150 ) )
goto V_187;
if ( V_180 && ! V_178 && V_188 > 1 ) {
V_162 = F_181 ( V_159 , V_150 ) ;
V_177 = 1 ;
V_178 = 1 ;
}
if ( V_189 == 0 )
goto V_183;
if ( V_180 && V_177 &&
! F_184 ( V_159 , V_147 , V_162 ) )
continue;
V_12 = F_196 ( V_11 , V_134 , V_27 ) ;
switch ( V_12 ) {
case V_190 :
continue;
case V_191 :
continue;
default:
if ( ! F_160 ( V_11 , V_27 , V_148 ,
V_149 , V_150 ) )
goto V_183;
}
}
V_187:
V_5 = F_161 ( V_125 , V_11 , V_27 ,
V_134 , V_6 ) ;
if ( V_5 )
break;
V_183:
if ( V_180 )
F_187 ( V_159 , V_147 ) ;
}
if ( F_7 ( V_180 && V_5 == NULL && V_177 ) ) {
V_177 = 0 ;
goto V_179;
}
if ( V_5 )
V_5 -> V_192 = ! ! ( V_150 & V_184 ) ;
return V_5 ;
}
static inline bool F_197 ( void )
{
bool V_12 = false ;
#if V_193 > 8
V_12 = F_42 () ;
#endif
return V_12 ;
}
void F_198 ( T_1 V_134 , int V_27 , const char * V_194 , ... )
{
unsigned int V_195 = V_196 ;
if ( ( V_134 & V_197 ) || ! F_199 ( & V_198 ) ||
F_106 () > 0 )
return;
if ( ! ( V_134 & V_199 ) )
if ( F_200 ( V_200 ) ||
( V_24 -> V_59 & ( V_201 | V_202 ) ) )
V_195 &= ~ V_196 ;
if ( F_42 () || ! ( V_134 & V_138 ) )
V_195 &= ~ V_196 ;
if ( V_194 ) {
struct V_203 V_204 ;
T_7 args ;
va_start ( args , V_194 ) ;
V_204 . V_194 = V_194 ;
V_204 . V_205 = & args ;
F_201 ( L_9 , & V_204 ) ;
va_end ( args ) ;
}
F_201 ( L_10 ,
V_24 -> V_25 , V_27 , V_134 ) ;
F_24 () ;
if ( ! F_197 () )
F_202 ( V_195 ) ;
}
static inline int
F_203 ( T_1 V_134 , unsigned int V_27 ,
unsigned long V_206 ,
unsigned long V_207 )
{
if ( V_134 & V_208 )
return 0 ;
if ( V_134 & V_129 )
return 1 ;
if ( ! V_206 && F_5 () )
return 0 ;
if ( V_27 <= V_209 )
return 1 ;
if ( V_134 & V_210 && V_207 < ( 1 << V_27 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_204 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_211 V_176 ,
T_6 * V_175 , struct V_11 * V_125 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_205 ( V_159 , V_134 ) ) {
F_206 ( 1 ) ;
return NULL ;
}
V_5 = F_190 ( V_134 | V_212 , V_175 ,
V_27 , V_159 , V_176 ,
V_213 | V_167 ,
V_125 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_134 & V_129 ) ) {
if ( V_27 > V_209 )
goto V_21;
if ( V_176 < V_214 )
goto V_21;
if ( V_134 & V_215 )
goto V_21;
}
F_207 ( V_159 , V_134 , V_27 , V_175 , false ) ;
V_21:
F_208 ( V_159 , V_134 ) ;
return V_5 ;
}
static struct V_5 *
F_209 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_211 V_176 ,
T_6 * V_175 , int V_150 , struct V_11 * V_125 ,
int V_6 , bool V_216 ,
bool * V_217 , bool * V_218 ,
unsigned long * V_206 )
{
struct V_5 * V_5 ;
if ( ! V_27 )
return NULL ;
if ( F_210 ( V_125 , V_27 ) ) {
* V_218 = true ;
return NULL ;
}
V_24 -> V_59 |= V_201 ;
* V_206 = F_211 ( V_159 , V_27 , V_134 ,
V_175 , V_216 ,
V_217 ) ;
V_24 -> V_59 &= ~ V_201 ;
if ( * V_206 != V_219 ) {
F_130 ( F_212 () ) ;
F_213 () ;
V_5 = F_190 ( V_134 , V_175 ,
V_27 , V_159 , V_176 ,
V_150 & ~ V_184 ,
V_125 , V_6 ) ;
if ( V_5 ) {
V_125 -> V_220 = 0 ;
V_125 -> V_221 = 0 ;
if ( V_27 >= V_125 -> V_222 )
V_125 -> V_222 = V_27 + 1 ;
F_214 ( V_223 ) ;
return V_5 ;
}
F_214 ( V_224 ) ;
if ( V_216 )
F_215 ( V_125 , V_27 ) ;
F_216 () ;
}
return NULL ;
}
static inline struct V_5 *
F_209 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_211 V_176 ,
T_6 * V_175 , int V_150 , struct V_11 * V_125 ,
int V_6 , bool V_216 ,
bool * V_217 , bool * V_218 ,
unsigned long * V_206 )
{
return NULL ;
}
static int
F_217 ( T_1 V_134 , unsigned int V_27 , struct V_159 * V_159 ,
T_6 * V_175 )
{
struct V_225 V_225 ;
int V_226 ;
F_216 () ;
F_218 () ;
V_24 -> V_59 |= V_201 ;
F_219 ( V_134 ) ;
V_225 . V_227 = 0 ;
V_24 -> V_225 = & V_225 ;
V_226 = F_220 ( V_159 , V_27 , V_134 , V_175 ) ;
V_24 -> V_225 = NULL ;
F_221 () ;
V_24 -> V_59 &= ~ V_201 ;
F_216 () ;
return V_226 ;
}
static inline struct V_5 *
F_222 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_211 V_176 ,
T_6 * V_175 , int V_150 , struct V_11 * V_125 ,
int V_6 , unsigned long * V_206 )
{
struct V_5 * V_5 = NULL ;
bool V_228 = false ;
* V_206 = F_217 ( V_134 , V_27 , V_159 ,
V_175 ) ;
if ( F_7 ( ! ( * V_206 ) ) )
return NULL ;
if ( V_180 )
F_189 ( V_159 ) ;
V_229:
V_5 = F_190 ( V_134 , V_175 , V_27 ,
V_159 , V_176 ,
V_150 & ~ V_184 ,
V_125 , V_6 ) ;
if ( ! V_5 && ! V_228 ) {
F_135 () ;
V_228 = true ;
goto V_229;
}
return V_5 ;
}
static inline struct V_5 *
F_223 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_211 V_176 ,
T_6 * V_175 , struct V_11 * V_125 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_190 ( V_134 , V_175 , V_27 ,
V_159 , V_176 , V_184 ,
V_125 , V_6 ) ;
if ( ! V_5 && V_134 & V_129 )
F_224 ( V_125 , V_230 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_134 & V_129 ) );
return V_5 ;
}
static inline
void F_225 ( unsigned int V_27 , struct V_159 * V_159 ,
enum V_211 V_176 ,
enum V_211 V_149 )
{
struct V_171 * V_147 ;
struct V_11 * V_11 ;
F_226 (zone, z, zonelist, high_zoneidx)
F_227 ( V_11 , V_27 , V_149 ) ;
}
static inline int
F_228 ( T_1 V_134 )
{
int V_150 = V_231 | V_167 ;
const T_1 V_232 = V_134 & V_138 ;
F_195 ( V_233 != ( V_234 T_1 ) V_155 ) ;
V_150 |= ( V_234 int ) ( V_134 & V_233 ) ;
if ( ! V_232 ) {
if ( ! ( V_134 & V_199 ) )
V_150 |= V_156 ;
V_150 &= ~ V_167 ;
} else if ( F_7 ( F_229 ( V_24 ) ) && ! F_42 () )
V_150 |= V_156 ;
if ( F_127 ( ! ( V_134 & V_199 ) ) ) {
if ( V_134 & V_235 )
V_150 |= V_184 ;
else if ( F_230 () && ( V_24 -> V_59 & V_201 ) )
V_150 |= V_184 ;
else if ( ! F_42 () &&
( ( V_24 -> V_59 & V_201 ) ||
F_7 ( F_200 ( V_200 ) ) ) )
V_150 |= V_184 ;
}
return V_150 ;
}
bool F_231 ( T_1 V_134 )
{
return ! ! ( F_228 ( V_134 ) & V_184 ) ;
}
static inline struct V_5 *
F_232 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , enum V_211 V_176 ,
T_6 * V_175 , struct V_11 * V_125 ,
int V_6 )
{
const T_1 V_232 = V_134 & V_138 ;
struct V_5 * V_5 = NULL ;
int V_150 ;
unsigned long V_207 = 0 ;
unsigned long V_206 ;
bool V_216 = false ;
bool V_218 = false ;
bool V_217 = false ;
if ( V_27 >= V_37 ) {
F_162 ( ! ( V_134 & V_197 ) ) ;
return NULL ;
}
if ( V_180 && ( V_134 & V_236 ) == V_236 )
goto V_237;
V_238:
if ( ! ( V_134 & V_239 ) )
F_225 ( V_27 , V_159 , V_176 ,
F_191 ( V_125 ) ) ;
V_150 = F_228 ( V_134 ) ;
if ( ! ( V_150 & V_167 ) && ! V_175 )
F_233 ( V_159 , V_176 , NULL ,
& V_125 ) ;
V_240:
V_5 = F_190 ( V_134 , V_175 , V_27 , V_159 ,
V_176 , V_150 & ~ V_184 ,
V_125 , V_6 ) ;
if ( V_5 )
goto V_241;
if ( V_150 & V_184 ) {
V_159 = F_234 ( F_235 () , V_134 ) ;
V_5 = F_223 ( V_134 , V_27 ,
V_159 , V_176 , V_175 ,
V_125 , V_6 ) ;
if ( V_5 ) {
goto V_241;
}
}
if ( ! V_232 )
goto V_237;
if ( V_24 -> V_59 & V_201 )
goto V_237;
if ( F_200 ( V_200 ) && ! ( V_134 & V_129 ) )
goto V_237;
V_5 = F_209 ( V_134 , V_27 ,
V_159 , V_176 ,
V_175 ,
V_150 , V_125 ,
V_6 , V_216 ,
& V_217 ,
& V_218 ,
& V_206 ) ;
if ( V_5 )
goto V_241;
V_216 = true ;
if ( ( V_218 || V_217 ) &&
( V_134 & V_239 ) )
goto V_237;
V_5 = F_222 ( V_134 , V_27 ,
V_159 , V_176 ,
V_175 ,
V_150 , V_125 ,
V_6 , & V_206 ) ;
if ( V_5 )
goto V_241;
if ( ! V_206 ) {
if ( ( V_134 & V_242 ) && ! ( V_134 & V_208 ) ) {
if ( V_243 )
goto V_237;
if ( ( V_24 -> V_59 & V_244 ) &&
! ( V_134 & V_129 ) )
goto V_237;
V_5 = F_204 ( V_134 , V_27 ,
V_159 , V_176 ,
V_175 , V_125 ,
V_6 ) ;
if ( V_5 )
goto V_241;
if ( ! ( V_134 & V_129 ) ) {
if ( V_27 > V_209 )
goto V_237;
if ( V_176 < V_214 )
goto V_237;
}
goto V_238;
}
}
V_207 += V_206 ;
if ( F_203 ( V_134 , V_27 , V_206 ,
V_207 ) ) {
F_224 ( V_125 , V_230 , V_23 / 50 ) ;
goto V_240;
} else {
V_5 = F_209 ( V_134 , V_27 ,
V_159 , V_176 ,
V_175 ,
V_150 , V_125 ,
V_6 , V_216 ,
& V_217 ,
& V_218 ,
& V_206 ) ;
if ( V_5 )
goto V_241;
}
V_237:
F_198 ( V_134 , V_27 , NULL ) ;
return V_5 ;
V_241:
if ( V_245 )
F_236 ( V_5 , V_27 , V_134 ) ;
return V_5 ;
}
struct V_5 *
F_237 ( T_1 V_134 , unsigned int V_27 ,
struct V_159 * V_159 , T_6 * V_175 )
{
enum V_211 V_176 = F_238 ( V_134 ) ;
struct V_11 * V_125 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_239 ( V_134 ) ;
unsigned int V_246 ;
V_134 &= V_3 ;
F_240 ( V_134 ) ;
F_241 ( V_134 & V_138 ) ;
if ( F_167 ( V_134 , V_27 ) )
return NULL ;
if ( F_7 ( ! V_159 -> V_173 -> V_11 ) )
return NULL ;
V_247:
V_246 = F_242 () ;
F_233 ( V_159 , V_176 ,
V_175 ? : & V_168 ,
& V_125 ) ;
if ( ! V_125 )
goto V_21;
V_5 = F_190 ( V_134 | V_212 , V_175 , V_27 ,
V_159 , V_176 , V_181 | V_167 ,
V_125 , V_6 ) ;
if ( F_7 ( ! V_5 ) )
V_5 = F_232 ( V_134 , V_27 ,
V_159 , V_176 , V_175 ,
V_125 , V_6 ) ;
F_243 ( V_5 , V_27 , V_134 , V_6 ) ;
V_21:
if ( F_7 ( ! F_244 ( V_246 ) && ! V_5 ) )
goto V_247;
return V_5 ;
}
unsigned long F_245 ( T_1 V_134 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_41 ( ( V_134 & V_34 ) != 0 ) ;
V_5 = F_246 ( V_134 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_89 ( V_5 ) ;
}
unsigned long F_247 ( T_1 V_134 )
{
return F_245 ( V_134 | V_87 , 0 ) ;
}
void F_102 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_248 ( V_5 ) ) {
if ( V_27 == 0 )
F_149 ( V_5 , 0 ) ;
else
F_27 ( V_5 , V_27 ) ;
}
}
void V_151 ( unsigned long V_248 , unsigned int V_27 )
{
if ( V_248 != 0 ) {
F_41 ( ! F_249 ( ( void * ) V_248 ) ) ;
F_102 ( F_157 ( ( void * ) V_248 ) , V_27 ) ;
}
}
static void * F_250 ( unsigned long V_248 , unsigned V_27 , T_8 V_86 )
{
if ( V_248 ) {
unsigned long V_249 = V_248 + ( V_75 << V_27 ) ;
unsigned long V_250 = V_248 + F_251 ( V_86 ) ;
F_154 ( F_157 ( ( void * ) V_248 ) , V_27 ) ;
while ( V_250 < V_249 ) {
F_252 ( V_250 ) ;
V_250 += V_75 ;
}
}
return ( void * ) V_248 ;
}
void * F_253 ( T_8 V_86 , T_1 V_134 )
{
unsigned int V_27 = F_254 ( V_86 ) ;
unsigned long V_248 ;
V_248 = F_245 ( V_134 , V_27 ) ;
return F_250 ( V_248 , V_27 , V_86 ) ;
}
void * F_255 ( int V_251 , T_8 V_86 , T_1 V_134 )
{
unsigned V_27 = F_254 ( V_86 ) ;
struct V_5 * V_30 = F_256 ( V_251 , V_134 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_250 ( ( unsigned long ) F_89 ( V_30 ) , V_27 , V_86 ) ;
}
void F_257 ( void * V_252 , T_8 V_86 )
{
unsigned long V_248 = ( unsigned long ) V_252 ;
unsigned long V_253 = V_248 + F_251 ( V_86 ) ;
while ( V_248 < V_253 ) {
F_252 ( V_248 ) ;
V_248 += V_75 ;
}
}
static unsigned int F_258 ( int V_254 )
{
struct V_171 * V_147 ;
struct V_11 * V_11 ;
unsigned int V_255 = 0 ;
struct V_159 * V_159 = F_234 ( F_235 () , V_256 ) ;
F_226 (zone, z, zonelist, offset) {
unsigned long V_86 = V_11 -> V_257 ;
unsigned long V_84 = F_259 ( V_11 ) ;
if ( V_86 > V_84 )
V_255 += V_86 - V_84 ;
}
return V_255 ;
}
unsigned int F_260 ( void )
{
return F_258 ( F_238 ( V_258 ) ) ;
}
unsigned int F_261 ( void )
{
return F_258 ( F_238 ( V_259 ) ) ;
}
static inline void F_262 ( struct V_11 * V_11 )
{
if ( V_180 )
F_21 ( L_11 , F_116 ( V_11 ) ) ;
}
void F_263 ( struct V_260 * V_261 )
{
V_261 -> V_262 = V_82 ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = F_264 ( V_48 ) ;
V_261 -> V_265 = F_265 () ;
V_261 -> V_266 = V_267 ;
V_261 -> V_268 = F_266 () ;
V_261 -> V_269 = V_75 ;
}
void F_267 ( struct V_260 * V_261 , int V_251 )
{
T_9 * V_270 = F_268 ( V_251 ) ;
V_261 -> V_262 = V_270 -> V_271 ;
V_261 -> V_264 = F_269 ( V_251 , V_48 ) ;
#ifdef F_270
V_261 -> V_266 = V_270 -> V_272 [ V_273 ] . V_257 ;
V_261 -> V_268 = F_178 ( & V_270 -> V_272 [ V_273 ] ,
V_48 ) ;
#else
V_261 -> V_266 = 0 ;
V_261 -> V_268 = 0 ;
#endif
V_261 -> V_269 = V_75 ;
}
bool F_271 ( unsigned int V_59 , int V_251 )
{
bool V_12 = false ;
unsigned int V_246 ;
if ( ! ( V_59 & V_196 ) )
goto V_21;
do {
V_246 = F_242 () ;
V_12 = ! F_185 ( V_251 , V_168 ) ;
} while ( ! F_244 ( V_246 ) );
V_21:
return V_12 ;
}
void F_272 ( unsigned int V_195 )
{
int V_111 ;
struct V_11 * V_11 ;
F_131 (zone) {
if ( F_271 ( V_195 , F_116 ( V_11 ) ) )
continue;
F_262 ( V_11 ) ;
F_21 ( L_12 , V_11 -> V_274 ) ;
F_136 (cpu) {
struct V_112 * V_114 ;
V_114 = F_132 ( V_11 -> V_114 , V_111 ) ;
F_21 ( L_13 ,
V_111 , V_114 -> V_64 . V_84 ,
V_114 -> V_64 . V_110 , V_114 -> V_64 . V_62 ) ;
}
}
F_21 ( L_14
L_15
L_16
L_17
L_18
L_19 ,
F_264 ( V_275 ) ,
F_264 ( V_276 ) ,
F_264 ( V_277 ) ,
F_264 ( V_278 ) ,
F_264 ( V_279 ) ,
F_264 ( V_280 ) ,
F_264 ( V_281 ) ,
F_264 ( V_282 ) ,
F_264 ( V_283 ) ,
F_264 ( V_284 ) ,
F_264 ( V_48 ) ,
F_264 ( V_285 ) ,
F_264 ( V_286 ) ,
F_264 ( V_287 ) ,
F_264 ( V_288 ) ,
F_264 ( V_289 ) ,
F_264 ( V_290 ) ) ;
F_131 (zone) {
int V_28 ;
if ( F_271 ( V_195 , F_116 ( V_11 ) ) )
continue;
F_262 ( V_11 ) ;
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
V_11 -> V_274 ,
F_273 ( F_178 ( V_11 , V_48 ) ) ,
F_273 ( F_274 ( V_11 ) ) ,
F_273 ( F_159 ( V_11 ) ) ,
F_273 ( F_259 ( V_11 ) ) ,
F_273 ( F_178 ( V_11 , V_275 ) ) ,
F_273 ( F_178 ( V_11 , V_276 ) ) ,
F_273 ( F_178 ( V_11 , V_278 ) ) ,
F_273 ( F_178 ( V_11 , V_279 ) ) ,
F_273 ( F_178 ( V_11 , V_281 ) ) ,
F_273 ( F_178 ( V_11 , V_277 ) ) ,
F_273 ( F_178 ( V_11 , V_280 ) ) ,
F_273 ( V_11 -> V_257 ) ,
F_273 ( F_178 ( V_11 , V_55 ) ) ,
F_273 ( F_178 ( V_11 , V_282 ) ) ,
F_273 ( F_178 ( V_11 , V_283 ) ) ,
F_273 ( F_178 ( V_11 , V_287 ) ) ,
F_273 ( F_178 ( V_11 , V_288 ) ) ,
F_273 ( F_178 ( V_11 , V_285 ) ) ,
F_273 ( F_178 ( V_11 , V_286 ) ) ,
F_178 ( V_11 , V_291 ) *
V_292 / 1024 ,
F_273 ( F_178 ( V_11 , V_289 ) ) ,
F_273 ( F_178 ( V_11 , V_284 ) ) ,
F_273 ( F_178 ( V_11 , V_290 ) ) ,
F_273 ( F_178 ( V_11 , V_293 ) ) ,
V_11 -> V_69 ,
( V_11 -> V_68 ? L_48 : L_49 )
) ;
F_21 ( L_50 ) ;
for ( V_28 = 0 ; V_28 < V_294 ; V_28 ++ )
F_21 ( L_51 , V_11 -> V_153 [ V_28 ] ) ;
F_21 ( L_47 ) ;
}
F_131 (zone) {
unsigned long V_295 [ V_37 ] , V_59 , V_27 , V_296 = 0 ;
if ( F_271 ( V_195 , F_116 ( V_11 ) ) )
continue;
F_262 ( V_11 ) ;
F_21 ( L_52 , V_11 -> V_274 ) ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
V_295 [ V_27 ] = V_11 -> V_50 [ V_27 ] . V_51 ;
V_296 += V_295 [ V_27 ] << V_27 ;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ )
F_21 ( L_53 , V_295 [ V_27 ] , F_273 ( 1UL ) << V_27 ) ;
F_21 ( L_54 , F_273 ( V_296 ) ) ;
}
F_21 ( L_55 , F_264 ( V_297 ) ) ;
F_275 () ;
}
static void F_276 ( struct V_11 * V_11 , struct V_171 * V_171 )
{
V_171 -> V_11 = V_11 ;
V_171 -> F_191 = F_191 ( V_11 ) ;
}
static int F_277 ( T_9 * V_270 , struct V_159 * V_159 ,
int V_298 , enum V_211 V_211 )
{
struct V_11 * V_11 ;
F_114 ( V_211 >= V_294 ) ;
V_211 ++ ;
do {
V_211 -- ;
V_11 = V_270 -> V_272 + V_211 ;
if ( F_278 ( V_11 ) ) {
F_276 ( V_11 ,
& V_159 -> V_173 [ V_298 ++ ] ) ;
F_279 ( V_211 ) ;
}
} while ( V_211 );
return V_298 ;
}
static int F_280 ( char * V_299 )
{
if ( * V_299 == 'd' || * V_299 == 'D' ) {
V_300 = V_301 ;
} else if ( * V_299 == 'n' || * V_299 == 'N' ) {
V_300 = V_302 ;
} else if ( * V_299 == 'z' || * V_299 == 'Z' ) {
V_300 = V_303 ;
} else {
F_21 ( V_304
L_56
L_57 , V_299 ) ;
return - V_305 ;
}
return 0 ;
}
static T_2 int F_281 ( char * V_299 )
{
int V_12 ;
if ( ! V_299 )
return 0 ;
V_12 = F_280 ( V_299 ) ;
if ( V_12 == 0 )
F_282 ( V_306 , V_299 , V_307 ) ;
return V_12 ;
}
int F_283 ( T_10 * V_308 , int V_309 ,
void T_11 * V_310 , T_8 * V_311 ,
T_12 * V_312 )
{
char V_313 [ V_307 ] ;
int V_12 ;
static F_284 ( V_314 ) ;
F_285 ( & V_314 ) ;
if ( V_309 )
strcpy ( V_313 , ( char * ) V_308 -> V_315 ) ;
V_12 = F_286 ( V_308 , V_309 , V_310 , V_311 , V_312 ) ;
if ( V_12 )
goto V_21;
if ( V_309 ) {
int V_316 = V_300 ;
if ( F_280 ( ( char * ) V_308 -> V_315 ) ) {
strncpy ( ( char * ) V_308 -> V_315 , V_313 ,
V_307 ) ;
V_300 = V_316 ;
} else if ( V_316 != V_300 ) {
F_285 ( & V_317 ) ;
F_287 ( NULL , NULL ) ;
F_288 ( & V_317 ) ;
}
}
V_21:
F_288 ( & V_314 ) ;
return V_12 ;
}
static int F_289 ( int V_318 , T_6 * V_319 )
{
int V_172 , V_261 ;
int V_320 = V_321 ;
int V_322 = - 1 ;
const struct V_323 * V_324 = F_290 ( 0 ) ;
if ( ! F_185 ( V_318 , * V_319 ) ) {
F_291 ( V_318 , * V_319 ) ;
return V_318 ;
}
F_292 (n, N_HIGH_MEMORY) {
if ( F_185 ( V_172 , * V_319 ) )
continue;
V_261 = F_293 ( V_318 , V_172 ) ;
V_261 += ( V_172 < V_318 ) ;
V_324 = F_290 ( V_172 ) ;
if ( ! F_294 ( V_324 ) )
V_261 += V_325 ;
V_261 *= ( V_326 * V_327 ) ;
V_261 += V_328 [ V_172 ] ;
if ( V_261 < V_320 ) {
V_320 = V_261 ;
V_322 = V_172 ;
}
}
if ( V_322 >= 0 )
F_291 ( V_322 , * V_319 ) ;
return V_322 ;
}
static void F_295 ( T_9 * V_270 , int V_318 )
{
int V_329 ;
struct V_159 * V_159 ;
V_159 = & V_270 -> V_330 [ 0 ] ;
for ( V_329 = 0 ; V_159 -> V_173 [ V_329 ] . V_11 != NULL ; V_329 ++ )
;
V_329 = F_277 ( F_268 ( V_318 ) , V_159 , V_329 ,
V_294 - 1 ) ;
V_159 -> V_173 [ V_329 ] . V_11 = NULL ;
V_159 -> V_173 [ V_329 ] . F_191 = 0 ;
}
static void F_296 ( T_9 * V_270 )
{
int V_329 ;
struct V_159 * V_159 ;
V_159 = & V_270 -> V_330 [ 1 ] ;
V_329 = F_277 ( V_270 , V_159 , 0 , V_294 - 1 ) ;
V_159 -> V_173 [ V_329 ] . V_11 = NULL ;
V_159 -> V_173 [ V_329 ] . F_191 = 0 ;
}
static void F_297 ( T_9 * V_270 , int V_331 )
{
int V_332 , V_329 , V_318 ;
int V_211 ;
struct V_11 * V_147 ;
struct V_159 * V_159 ;
V_159 = & V_270 -> V_330 [ 0 ] ;
V_332 = 0 ;
for ( V_211 = V_294 - 1 ; V_211 >= 0 ; V_211 -- ) {
for ( V_329 = 0 ; V_329 < V_331 ; V_329 ++ ) {
V_318 = V_333 [ V_329 ] ;
V_147 = & F_268 ( V_318 ) -> V_272 [ V_211 ] ;
if ( F_278 ( V_147 ) ) {
F_276 ( V_147 ,
& V_159 -> V_173 [ V_332 ++ ] ) ;
F_279 ( V_211 ) ;
}
}
}
V_159 -> V_173 [ V_332 ] . V_11 = NULL ;
V_159 -> V_173 [ V_332 ] . F_191 = 0 ;
}
static int F_298 ( void )
{
int V_251 , V_211 ;
unsigned long V_334 , V_335 ;
struct V_11 * V_147 ;
int V_336 ;
V_334 = 0 ;
V_335 = 0 ;
F_299 (nid) {
for ( V_211 = 0 ; V_211 < V_294 ; V_211 ++ ) {
V_147 = & F_268 ( V_251 ) -> V_272 [ V_211 ] ;
if ( F_278 ( V_147 ) ) {
if ( V_211 < V_214 )
V_334 += V_147 -> V_257 ;
V_335 += V_147 -> V_257 ;
} else if ( V_211 == V_214 ) {
return V_302 ;
}
}
}
if ( ! V_334 ||
V_334 > V_335 / 2 )
return V_302 ;
V_336 = V_335 /
( F_300 ( V_169 [ V_170 ] ) + 1 ) ;
F_299 (nid) {
V_334 = 0 ;
V_335 = 0 ;
for ( V_211 = 0 ; V_211 < V_294 ; V_211 ++ ) {
V_147 = & F_268 ( V_251 ) -> V_272 [ V_211 ] ;
if ( F_278 ( V_147 ) ) {
if ( V_211 < V_214 )
V_334 += V_147 -> V_257 ;
V_335 += V_147 -> V_257 ;
}
}
if ( V_334 &&
V_335 > V_336 &&
V_334 > V_335 * 70 / 100 )
return V_302 ;
}
return V_303 ;
}
static void F_301 ( void )
{
if ( V_300 == V_301 )
V_337 = F_298 () ;
else
V_337 = V_300 ;
}
static void F_302 ( T_9 * V_270 )
{
int V_329 , V_318 , V_338 ;
enum V_211 V_28 ;
T_6 V_339 ;
int V_340 , V_341 ;
struct V_159 * V_159 ;
int V_27 = V_337 ;
for ( V_28 = 0 ; V_28 < V_342 ; V_28 ++ ) {
V_159 = V_270 -> V_330 + V_28 ;
V_159 -> V_173 [ 0 ] . V_11 = NULL ;
V_159 -> V_173 [ 0 ] . F_191 = 0 ;
}
V_340 = V_270 -> V_343 ;
V_338 = V_188 ;
V_341 = V_340 ;
F_303 ( V_339 ) ;
memset ( V_333 , 0 , sizeof( V_333 ) ) ;
V_329 = 0 ;
while ( ( V_318 = F_289 ( V_340 , & V_339 ) ) >= 0 ) {
int V_344 = F_293 ( V_340 , V_318 ) ;
if ( V_344 > V_345 )
V_189 = 1 ;
if ( V_344 != F_293 ( V_340 , V_341 ) )
V_328 [ V_318 ] = V_338 ;
V_341 = V_318 ;
V_338 -- ;
if ( V_27 == V_302 )
F_295 ( V_270 , V_318 ) ;
else
V_333 [ V_329 ++ ] = V_318 ;
}
if ( V_27 == V_303 ) {
F_297 ( V_270 , V_329 ) ;
}
F_296 ( V_270 ) ;
}
static void F_304 ( T_9 * V_270 )
{
struct V_159 * V_159 ;
struct V_160 * V_161 ;
struct V_171 * V_147 ;
V_159 = & V_270 -> V_330 [ 0 ] ;
V_159 -> V_163 = V_161 = & V_159 -> V_346 ;
F_183 ( V_161 -> V_165 , V_166 ) ;
for ( V_147 = V_159 -> V_173 ; V_147 -> V_11 ; V_147 ++ )
V_161 -> V_174 [ V_147 - V_159 -> V_173 ] = F_305 ( V_147 ) ;
}
int F_306 ( int V_318 )
{
struct V_11 * V_11 ;
( void ) F_233 ( F_234 ( V_318 , V_256 ) ,
F_238 ( V_256 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_318 ;
}
static void F_301 ( void )
{
V_337 = V_303 ;
}
static void F_302 ( T_9 * V_270 )
{
int V_318 , V_340 ;
enum V_211 V_329 ;
struct V_159 * V_159 ;
V_340 = V_270 -> V_343 ;
V_159 = & V_270 -> V_330 [ 0 ] ;
V_329 = F_277 ( V_270 , V_159 , 0 , V_294 - 1 ) ;
for ( V_318 = V_340 + 1 ; V_318 < V_327 ; V_318 ++ ) {
if ( ! F_307 ( V_318 ) )
continue;
V_329 = F_277 ( F_268 ( V_318 ) , V_159 , V_329 ,
V_294 - 1 ) ;
}
for ( V_318 = 0 ; V_318 < V_340 ; V_318 ++ ) {
if ( ! F_307 ( V_318 ) )
continue;
V_329 = F_277 ( F_268 ( V_318 ) , V_159 , V_329 ,
V_294 - 1 ) ;
}
V_159 -> V_173 [ V_329 ] . V_11 = NULL ;
V_159 -> V_173 [ V_329 ] . F_191 = 0 ;
}
static void F_304 ( T_9 * V_270 )
{
V_270 -> V_330 [ 0 ] . V_163 = NULL ;
}
static int F_308 ( void * V_315 )
{
int V_251 ;
int V_111 ;
T_9 * V_347 = V_315 ;
#ifdef F_309
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
#endif
if ( V_347 && ! F_307 ( V_347 -> V_343 ) ) {
F_302 ( V_347 ) ;
F_304 ( V_347 ) ;
}
F_299 (nid) {
T_9 * V_270 = F_268 ( V_251 ) ;
F_302 ( V_270 ) ;
F_304 ( V_270 ) ;
}
F_310 (cpu) {
F_311 ( & F_312 ( V_348 , V_111 ) , 0 ) ;
#ifdef F_313
if ( F_314 ( V_111 ) )
F_315 ( V_111 , F_306 ( F_316 ( V_111 ) ) ) ;
#endif
}
return 0 ;
}
void T_13 F_287 ( T_9 * V_270 , struct V_11 * V_11 )
{
F_301 () ;
if ( V_349 == V_350 ) {
F_308 ( NULL ) ;
F_317 () ;
F_318 () ;
} else {
#ifdef F_319
if ( V_11 )
F_320 ( V_11 ) ;
#endif
F_321 ( F_308 , V_270 , NULL ) ;
}
V_351 = F_261 () ;
if ( V_351 < ( V_79 * V_352 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_21 ( L_58
L_59 ,
V_188 ,
V_353 [ V_337 ] ,
V_7 ? L_60 : L_61 ,
V_351 ) ;
#ifdef F_309
F_21 ( L_62 , V_354 [ V_355 ] ) ;
#endif
}
static inline unsigned long F_322 ( unsigned long V_103 )
{
unsigned long V_86 = 1 ;
V_103 /= V_356 ;
while ( V_86 < V_103 )
V_86 <<= 1 ;
V_86 = V_152 ( V_86 , 4096UL ) ;
return F_323 ( V_86 , 4UL ) ;
}
static inline unsigned long F_322 ( unsigned long V_103 )
{
return 4096UL ;
}
static inline unsigned long F_324 ( unsigned long V_86 )
{
return F_325 ( ~ V_86 ) ;
}
static int F_326 ( unsigned long V_94 , unsigned long V_95 )
{
unsigned long V_14 ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ ) {
if ( ! F_14 ( V_14 ) || F_327 ( F_119 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_328 ( struct V_11 * V_11 )
{
unsigned long V_94 , V_14 , V_95 , V_357 ;
struct V_5 * V_5 ;
unsigned long V_358 ;
int V_359 ;
V_94 = V_11 -> V_15 ;
V_95 = V_94 + V_11 -> V_16 ;
V_94 = F_329 ( V_94 , V_79 ) ;
V_359 = F_329 ( F_274 ( V_11 ) , V_79 ) >>
V_81 ;
V_359 = V_152 ( 2 , V_359 ) ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 += V_79 ) {
if ( ! F_142 ( V_14 ) )
continue;
V_5 = F_119 ( V_14 ) ;
if ( F_115 ( V_5 ) != F_116 ( V_11 ) )
continue;
V_358 = F_96 ( V_5 ) ;
if ( V_359 > 0 ) {
V_357 = V_152 ( V_14 + V_79 , V_95 ) ;
if ( F_326 ( V_14 , V_357 ) )
continue;
if ( V_358 == V_101 ) {
V_359 -- ;
continue;
}
if ( V_358 == V_121 ) {
F_6 ( V_5 ,
V_101 ) ;
F_118 ( V_11 , V_5 ,
V_101 ) ;
V_359 -- ;
continue;
}
}
if ( V_358 == V_101 ) {
F_6 ( V_5 , V_121 ) ;
F_118 ( V_11 , V_5 , V_121 ) ;
}
}
}
void T_3 F_330 ( unsigned long V_86 , int V_251 , unsigned long V_11 ,
unsigned long V_94 , enum V_360 V_361 )
{
struct V_5 * V_5 ;
unsigned long V_95 = V_94 + V_86 ;
unsigned long V_14 ;
struct V_11 * V_147 ;
if ( V_362 < V_95 - 1 )
V_362 = V_95 - 1 ;
V_147 = & F_268 ( V_251 ) -> V_272 [ V_11 ] ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ ) {
if ( V_361 == V_363 ) {
if ( ! F_331 ( V_14 ) )
continue;
if ( ! F_332 ( V_14 , V_251 ) )
continue;
}
V_5 = F_119 ( V_14 ) ;
F_333 ( V_5 , V_11 , V_251 , V_14 ) ;
F_334 ( V_5 , V_11 , V_251 , V_14 ) ;
F_335 ( V_5 ) ;
F_19 ( V_5 ) ;
F_336 ( V_5 ) ;
if ( ( V_147 -> V_15 <= V_14 )
&& ( V_14 < V_147 -> V_15 + V_147 -> V_16 )
&& ! ( V_14 & ( V_79 - 1 ) ) )
F_6 ( V_5 , V_121 ) ;
F_107 ( & V_5 -> V_49 ) ;
#ifdef F_337
if ( ! F_338 ( V_11 ) )
F_339 ( V_5 , F_340 ( V_14 << V_364 ) ) ;
#endif
}
}
static void T_3 F_341 ( struct V_11 * V_11 )
{
int V_27 , V_119 ;
F_145 (order, t) {
F_107 ( & V_11 -> V_50 [ V_27 ] . V_54 [ V_119 ] ) ;
V_11 -> V_50 [ V_27 ] . V_51 = 0 ;
}
}
static int T_3 F_342 ( struct V_11 * V_11 )
{
#ifdef F_343
int V_110 ;
V_110 = V_11 -> V_257 / 1024 ;
if ( V_110 * V_75 > 512 * 1024 )
V_110 = ( 512 * 1024 ) / V_75 ;
V_110 /= 4 ;
if ( V_110 < 1 )
V_110 = 1 ;
V_110 = F_344 ( V_110 + V_110 / 2 ) - 1 ;
return V_110 ;
#else
return 0 ;
#endif
}
static void F_311 ( struct V_112 * V_30 , unsigned long V_110 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_62 = 0 ;
V_64 -> V_84 = 6 * V_110 ;
V_64 -> V_110 = F_323 ( 1UL , 1 * V_110 ) ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ )
F_107 ( & V_64 -> V_73 [ V_6 ] ) ;
}
static void F_345 ( struct V_112 * V_30 ,
unsigned long V_84 )
{
struct V_63 * V_64 ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_84 = V_84 ;
V_64 -> V_110 = F_323 ( 1UL , V_84 / 4 ) ;
if ( ( V_84 / 4 ) > ( V_364 * 8 ) )
V_64 -> V_110 = V_364 * 8 ;
}
static void T_3 F_320 ( struct V_11 * V_11 )
{
int V_111 ;
V_11 -> V_114 = F_346 ( struct V_112 ) ;
F_310 (cpu) {
struct V_112 * V_64 = F_132 ( V_11 -> V_114 , V_111 ) ;
F_311 ( V_64 , F_342 ( V_11 ) ) ;
if ( V_365 )
F_345 ( V_64 ,
( V_11 -> V_257 /
V_365 ) ) ;
}
}
void T_2 F_347 ( void )
{
struct V_11 * V_11 ;
F_131 (zone)
F_320 ( V_11 ) ;
}
static T_14 T_15
int F_348 ( struct V_11 * V_11 , unsigned long V_366 )
{
int V_28 ;
struct V_367 * V_270 = V_11 -> V_368 ;
T_8 V_369 ;
V_11 -> F_322 =
F_322 ( V_366 ) ;
V_11 -> F_324 =
F_324 ( V_11 -> F_322 ) ;
V_369 = V_11 -> F_322
* sizeof( V_370 ) ;
if ( ! F_349 () ) {
V_11 -> V_371 = ( V_370 * )
F_350 ( V_270 , V_369 ) ;
} else {
V_11 -> V_371 = F_351 ( V_369 ) ;
}
if ( ! V_11 -> V_371 )
return - V_146 ;
for( V_28 = 0 ; V_28 < V_11 -> F_322 ; ++ V_28 )
F_352 ( V_11 -> V_371 + V_28 ) ;
return 0 ;
}
static T_3 void F_353 ( struct V_11 * V_11 )
{
V_11 -> V_114 = & V_348 ;
if ( V_11 -> V_257 )
F_21 ( V_372 L_63 ,
V_11 -> V_274 , V_11 -> V_257 ,
F_342 ( V_11 ) ) ;
}
int T_3 F_354 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_86 ,
enum V_360 V_361 )
{
struct V_367 * V_270 = V_11 -> V_368 ;
int V_12 ;
V_12 = F_348 ( V_11 , V_86 ) ;
if ( V_12 )
return V_12 ;
V_270 -> V_298 = F_191 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_355 ( V_373 , L_64 ,
L_65 ,
V_270 -> V_343 ,
( unsigned long ) F_191 ( V_11 ) ,
V_15 , ( V_15 + V_86 ) ) ;
F_341 ( V_11 ) ;
return 0 ;
}
int T_3 F_356 ( unsigned long V_14 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_251 ;
F_357 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_94 <= V_14 && V_14 < V_95 )
return V_251 ;
return - 1 ;
}
int T_3 F_358 ( unsigned long V_14 )
{
int V_251 ;
V_251 = F_356 ( V_14 ) ;
if ( V_251 >= 0 )
return V_251 ;
return 0 ;
}
bool T_3 F_332 ( unsigned long V_14 , int V_318 )
{
int V_251 ;
V_251 = F_356 ( V_14 ) ;
if ( V_251 >= 0 && V_251 != V_318 )
return false ;
return true ;
}
void T_2 F_359 ( int V_251 , unsigned long V_374 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_375 ;
F_357 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_94 = V_152 ( V_94 , V_374 ) ;
V_95 = V_152 ( V_95 , V_374 ) ;
if ( V_94 < V_95 )
F_360 ( F_268 ( V_375 ) ,
F_361 ( V_94 ) ,
( V_95 - V_94 ) << V_364 ) ;
}
}
void T_2 F_362 ( int V_251 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_375 ;
F_357 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_363 ( V_375 , V_94 , V_95 ) ;
}
void T_3 F_364 ( unsigned int V_251 ,
unsigned long * V_94 , unsigned long * V_95 )
{
unsigned long V_376 , V_377 ;
int V_28 ;
* V_94 = - 1UL ;
* V_95 = 0 ;
F_357 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_94 = V_152 ( * V_94 , V_376 ) ;
* V_95 = F_323 ( * V_95 , V_377 ) ;
}
if ( * V_94 == - 1UL )
* V_94 = 0 ;
}
static void T_2 F_365 ( void )
{
int V_378 ;
for ( V_378 = V_294 - 1 ; V_378 >= 0 ; V_378 -- ) {
if ( V_378 == V_379 )
continue;
if ( V_380 [ V_378 ] >
V_381 [ V_378 ] )
break;
}
F_41 ( V_378 == - 1 ) ;
V_382 = V_378 ;
}
static void T_3 F_366 ( int V_251 ,
unsigned long V_211 ,
unsigned long V_383 ,
unsigned long V_384 ,
unsigned long * V_15 ,
unsigned long * V_385 )
{
if ( V_386 [ V_251 ] ) {
if ( V_211 == V_379 ) {
* V_15 = V_386 [ V_251 ] ;
* V_385 = V_152 ( V_384 ,
V_380 [ V_382 ] ) ;
} else if ( * V_15 < V_386 [ V_251 ] &&
* V_385 > V_386 [ V_251 ] ) {
* V_385 = V_386 [ V_251 ] ;
} else if ( * V_15 >= V_386 [ V_251 ] )
* V_15 = * V_385 ;
}
}
static unsigned long T_3 F_367 ( int V_251 ,
unsigned long V_211 ,
unsigned long * V_387 )
{
unsigned long V_383 , V_384 ;
unsigned long V_15 , V_385 ;
F_364 ( V_251 , & V_383 , & V_384 ) ;
V_15 = V_381 [ V_211 ] ;
V_385 = V_380 [ V_211 ] ;
F_366 ( V_251 , V_211 ,
V_383 , V_384 ,
& V_15 , & V_385 ) ;
if ( V_385 < V_383 || V_15 > V_384 )
return 0 ;
V_385 = V_152 ( V_385 , V_384 ) ;
V_15 = F_323 ( V_15 , V_383 ) ;
return V_385 - V_15 ;
}
unsigned long T_3 F_368 ( int V_251 ,
unsigned long V_388 ,
unsigned long V_389 )
{
unsigned long V_390 = V_389 - V_388 ;
unsigned long V_94 , V_95 ;
int V_28 ;
F_357 (i, nid, &start_pfn, &end_pfn, NULL) {
V_94 = F_369 ( V_94 , V_388 , V_389 ) ;
V_95 = F_369 ( V_95 , V_388 , V_389 ) ;
V_390 -= V_95 - V_94 ;
}
return V_390 ;
}
unsigned long T_2 F_370 ( unsigned long V_94 ,
unsigned long V_95 )
{
return F_368 ( V_327 , V_94 , V_95 ) ;
}
static unsigned long T_3 F_371 ( int V_251 ,
unsigned long V_211 ,
unsigned long * V_387 )
{
unsigned long V_391 = V_381 [ V_211 ] ;
unsigned long V_392 = V_380 [ V_211 ] ;
unsigned long V_383 , V_384 ;
unsigned long V_15 , V_385 ;
F_364 ( V_251 , & V_383 , & V_384 ) ;
V_15 = F_369 ( V_383 , V_391 , V_392 ) ;
V_385 = F_369 ( V_384 , V_391 , V_392 ) ;
F_366 ( V_251 , V_211 ,
V_383 , V_384 ,
& V_15 , & V_385 ) ;
return F_368 ( V_251 , V_15 , V_385 ) ;
}
static inline unsigned long T_3 F_367 ( int V_251 ,
unsigned long V_211 ,
unsigned long * V_393 )
{
return V_393 [ V_211 ] ;
}
static inline unsigned long T_3 F_371 ( int V_251 ,
unsigned long V_211 ,
unsigned long * V_394 )
{
if ( ! V_394 )
return 0 ;
return V_394 [ V_211 ] ;
}
static void T_3 F_372 ( struct V_367 * V_270 ,
unsigned long * V_393 , unsigned long * V_394 )
{
unsigned long V_395 , V_396 = 0 ;
enum V_211 V_28 ;
for ( V_28 = 0 ; V_28 < V_294 ; V_28 ++ )
V_396 += F_367 ( V_270 -> V_343 , V_28 ,
V_393 ) ;
V_270 -> V_397 = V_396 ;
V_395 = V_396 ;
for ( V_28 = 0 ; V_28 < V_294 ; V_28 ++ )
V_395 -=
F_371 ( V_270 -> V_343 , V_28 ,
V_394 ) ;
V_270 -> V_271 = V_395 ;
F_21 ( V_372 L_66 , V_270 -> V_343 ,
V_395 ) ;
}
static unsigned long T_2 F_373 ( unsigned long V_398 )
{
unsigned long V_399 ;
V_399 = F_329 ( V_398 , V_79 ) ;
V_399 = V_399 >> V_81 ;
V_399 *= V_400 ;
V_399 = F_329 ( V_399 , 8 * sizeof( unsigned long ) ) ;
return V_399 / 8 ;
}
static void T_2 F_374 ( struct V_367 * V_270 ,
struct V_11 * V_11 , unsigned long V_398 )
{
unsigned long V_399 = F_373 ( V_398 ) ;
V_11 -> V_401 = NULL ;
if ( V_399 )
V_11 -> V_401 = F_350 ( V_270 ,
V_399 ) ;
}
static inline void F_374 ( struct V_367 * V_270 ,
struct V_11 * V_11 , unsigned long V_398 ) {}
void T_2 F_375 ( void )
{
unsigned int V_27 ;
if ( V_81 )
return;
if ( V_402 > V_364 )
V_27 = V_403 ;
else
V_27 = V_37 - 1 ;
V_81 = V_27 ;
}
void T_2 F_375 ( void )
{
}
static void T_16 F_376 ( struct V_367 * V_270 ,
unsigned long * V_393 , unsigned long * V_394 )
{
enum V_211 V_329 ;
int V_251 = V_270 -> V_343 ;
unsigned long V_15 = V_270 -> V_383 ;
int V_12 ;
F_377 ( V_270 ) ;
F_352 ( & V_270 -> V_404 ) ;
F_352 ( & V_270 -> V_405 ) ;
F_378 ( V_270 ) ;
for ( V_329 = 0 ; V_329 < V_294 ; V_329 ++ ) {
struct V_11 * V_11 = V_270 -> V_272 + V_329 ;
unsigned long V_86 , V_406 , V_407 ;
V_86 = F_367 ( V_251 , V_329 , V_393 ) ;
V_406 = V_86 - F_371 ( V_251 , V_329 ,
V_394 ) ;
V_407 =
F_251 ( V_86 * sizeof( struct V_5 ) ) >> V_364 ;
if ( V_406 >= V_407 ) {
V_406 -= V_407 ;
if ( V_407 )
F_21 ( V_372
L_67 ,
V_354 [ V_329 ] , V_407 ) ;
} else
F_21 ( V_304
L_68 ,
V_354 [ V_329 ] , V_407 , V_406 ) ;
if ( V_329 == 0 && V_406 > V_408 ) {
V_406 -= V_408 ;
F_21 ( V_372 L_69 ,
V_354 [ 0 ] , V_408 ) ;
}
if ( ! F_338 ( V_329 ) )
V_409 += V_406 ;
V_410 += V_406 ;
V_11 -> V_16 = V_86 ;
V_11 -> V_257 = V_406 ;
#if V_411 V_412 || V_411 V_107
V_11 -> V_413 = V_11 -> V_15 +
V_11 -> V_16 ;
V_11 -> V_413 &= ~ ( V_79 - 1 ) ;
#endif
#ifdef F_309
V_11 -> V_318 = V_251 ;
V_11 -> V_414 = ( V_406 * V_415 )
/ 100 ;
V_11 -> V_416 = ( V_406 * V_417 ) / 100 ;
#endif
V_11 -> V_274 = V_354 [ V_329 ] ;
F_379 ( & V_11 -> V_67 ) ;
F_379 ( & V_11 -> V_418 ) ;
F_380 ( V_11 ) ;
V_11 -> V_368 = V_270 ;
F_353 ( V_11 ) ;
F_381 ( & V_11 -> V_419 , V_11 ) ;
if ( ! V_86 )
continue;
F_375 () ;
F_374 ( V_270 , V_11 , V_86 ) ;
V_12 = F_354 ( V_11 , V_15 ,
V_86 , V_363 ) ;
F_114 ( V_12 ) ;
F_382 ( V_86 , V_251 , V_329 , V_15 ) ;
V_15 += V_86 ;
}
}
static void T_15 F_383 ( struct V_367 * V_270 )
{
if ( ! V_270 -> V_397 )
return;
#ifdef F_384
if ( ! V_270 -> V_420 ) {
unsigned long V_86 , V_421 , V_253 ;
struct V_5 * V_422 ;
V_421 = V_270 -> V_383 & ~ ( V_423 - 1 ) ;
V_253 = V_270 -> V_383 + V_270 -> V_397 ;
V_253 = F_385 ( V_253 , V_423 ) ;
V_86 = ( V_253 - V_421 ) * sizeof( struct V_5 ) ;
V_422 = F_386 ( V_270 -> V_343 , V_86 ) ;
if ( ! V_422 )
V_422 = F_350 ( V_270 , V_86 ) ;
V_270 -> V_420 = V_422 + ( V_270 -> V_383 - V_421 ) ;
}
#ifndef F_387
if ( V_270 == F_268 ( 0 ) ) {
V_424 = F_268 ( 0 ) -> V_420 ;
#ifdef F_388
if ( F_10 ( V_424 ) != V_270 -> V_383 )
V_424 -= ( V_270 -> V_383 - V_425 ) ;
#endif
}
#endif
#endif
}
void T_16 F_389 ( int V_251 , unsigned long * V_393 ,
unsigned long V_383 , unsigned long * V_394 )
{
T_9 * V_270 = F_268 ( V_251 ) ;
F_2 ( V_270 -> V_298 || V_270 -> V_149 ) ;
V_270 -> V_343 = V_251 ;
V_270 -> V_383 = V_383 ;
F_372 ( V_270 , V_393 , V_394 ) ;
F_383 ( V_270 ) ;
#ifdef F_384
F_21 ( V_372 L_70 ,
V_251 , ( unsigned long ) V_270 ,
( unsigned long ) V_270 -> V_420 ) ;
#endif
F_376 ( V_270 , V_393 , V_394 ) ;
}
static void T_2 F_390 ( void )
{
unsigned int V_318 ;
unsigned int V_426 = 0 ;
F_391 (node, node_possible_map)
V_426 = V_318 ;
V_427 = V_426 + 1 ;
}
static inline void F_390 ( void )
{
}
unsigned long T_2 F_392 ( void )
{
unsigned long V_428 = 0 , V_429 = 0 ;
unsigned long V_421 , V_253 , V_430 ;
int V_431 = - 1 ;
int V_28 , V_251 ;
F_357 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_421 || V_431 < 0 || V_431 == V_251 ) {
V_431 = V_251 ;
V_429 = V_253 ;
continue;
}
V_430 = ~ ( ( 1 << F_393 ( V_421 ) ) - 1 ) ;
while ( V_430 && V_429 <= ( V_421 & ( V_430 << 1 ) ) )
V_430 <<= 1 ;
V_428 |= V_430 ;
}
return ~ V_428 + 1 ;
}
static unsigned long T_2 F_394 ( int V_251 )
{
unsigned long V_432 = V_433 ;
unsigned long V_94 ;
int V_28 ;
F_357 (i, nid, &start_pfn, NULL, NULL)
V_432 = V_152 ( V_432 , V_94 ) ;
if ( V_432 == V_433 ) {
F_21 ( V_304
L_71 , V_251 ) ;
return 0 ;
}
return V_432 ;
}
unsigned long T_2 F_395 ( void )
{
return F_394 ( V_327 ) ;
}
static unsigned long T_2 F_396 ( void )
{
unsigned long V_396 = 0 ;
unsigned long V_94 , V_95 ;
int V_28 , V_251 ;
F_357 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_103 = V_95 - V_94 ;
V_396 += V_103 ;
if ( V_103 )
F_397 ( V_251 , V_170 ) ;
}
return V_396 ;
}
static void T_2 F_398 ( void )
{
int V_28 , V_251 ;
unsigned long V_434 ;
unsigned long V_435 , V_436 ;
T_6 V_437 = V_169 [ V_170 ] ;
unsigned long V_396 = F_396 () ;
int V_438 = F_300 ( V_169 [ V_170 ] ) ;
if ( V_439 ) {
unsigned long V_440 ;
V_439 =
F_329 ( V_439 , V_423 ) ;
V_440 = V_396 - V_439 ;
V_441 = F_323 ( V_441 , V_440 ) ;
}
if ( ! V_441 )
goto V_21;
F_365 () ;
V_434 = V_381 [ V_382 ] ;
V_238:
V_435 = V_441 / V_438 ;
F_292 (nid, N_HIGH_MEMORY) {
unsigned long V_94 , V_95 ;
if ( V_441 < V_435 )
V_435 = V_441 / V_438 ;
V_436 = V_435 ;
F_357 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_442 ;
V_94 = F_323 ( V_94 , V_386 [ V_251 ] ) ;
if ( V_94 >= V_95 )
continue;
if ( V_94 < V_434 ) {
unsigned long V_443 ;
V_443 = V_152 ( V_95 , V_434 )
- V_94 ;
V_436 -= V_152 ( V_443 ,
V_436 ) ;
V_441 -= V_152 ( V_443 ,
V_441 ) ;
if ( V_95 <= V_434 ) {
V_386 [ V_251 ] = V_95 ;
continue;
}
V_94 = V_434 ;
}
V_442 = V_95 - V_94 ;
if ( V_442 > V_436 )
V_442 = V_436 ;
V_386 [ V_251 ] = V_94 + V_442 ;
V_441 -= V_152 ( V_441 ,
V_442 ) ;
V_436 -= V_442 ;
if ( ! V_436 )
break;
}
}
V_438 -- ;
if ( V_438 && V_441 > V_438 )
goto V_238;
for ( V_251 = 0 ; V_251 < V_327 ; V_251 ++ )
V_386 [ V_251 ] =
F_329 ( V_386 [ V_251 ] , V_423 ) ;
V_21:
V_169 [ V_170 ] = V_437 ;
}
static void T_2 F_399 ( T_9 * V_270 )
{
#ifdef F_270
enum V_211 V_211 ;
for ( V_211 = 0 ; V_211 <= V_214 ; V_211 ++ ) {
struct V_11 * V_11 = & V_270 -> V_272 [ V_211 ] ;
if ( V_11 -> V_257 ) {
F_397 ( F_116 ( V_11 ) , V_444 ) ;
break;
}
}
#endif
}
void T_2 F_400 ( unsigned long * V_118 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_251 ;
memset ( V_381 , 0 ,
sizeof( V_381 ) ) ;
memset ( V_380 , 0 ,
sizeof( V_380 ) ) ;
V_381 [ 0 ] = F_395 () ;
V_380 [ 0 ] = V_118 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_294 ; V_28 ++ ) {
if ( V_28 == V_379 )
continue;
V_381 [ V_28 ] =
V_380 [ V_28 - 1 ] ;
V_380 [ V_28 ] =
F_323 ( V_118 [ V_28 ] , V_381 [ V_28 ] ) ;
}
V_381 [ V_379 ] = 0 ;
V_380 [ V_379 ] = 0 ;
memset ( V_386 , 0 , sizeof( V_386 ) ) ;
F_398 () ;
F_21 ( L_72 ) ;
for ( V_28 = 0 ; V_28 < V_294 ; V_28 ++ ) {
if ( V_28 == V_379 )
continue;
F_21 ( V_445 L_73 , V_354 [ V_28 ] ) ;
if ( V_381 [ V_28 ] ==
V_380 [ V_28 ] )
F_21 ( V_445 L_74 ) ;
else
F_21 ( V_445 L_75 ,
V_381 [ V_28 ] << V_364 ,
( V_380 [ V_28 ]
<< V_364 ) - 1 ) ;
}
F_21 ( L_76 ) ;
for ( V_28 = 0 ; V_28 < V_327 ; V_28 ++ ) {
if ( V_386 [ V_28 ] )
F_21 ( L_77 , V_28 ,
V_386 [ V_28 ] << V_364 ) ;
}
F_21 ( L_78 ) ;
F_357 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_21 ( L_79 , V_251 ,
V_94 << V_364 , ( V_95 << V_364 ) - 1 ) ;
F_401 () ;
F_390 () ;
F_299 (nid) {
T_9 * V_270 = F_268 ( V_251 ) ;
F_389 ( V_251 , NULL ,
F_394 ( V_251 ) , NULL ) ;
if ( V_270 -> V_271 )
F_397 ( V_251 , V_170 ) ;
F_399 ( V_270 ) ;
}
}
static int T_2 F_402 ( char * V_30 , unsigned long * V_446 )
{
unsigned long long V_447 ;
if ( ! V_30 )
return - V_305 ;
V_447 = F_403 ( V_30 , & V_30 ) ;
* V_446 = V_447 >> V_364 ;
F_2 ( ( V_447 >> V_364 ) > V_433 ) ;
return 0 ;
}
static int T_2 F_404 ( char * V_30 )
{
return F_402 ( V_30 , & V_441 ) ;
}
static int T_2 F_405 ( char * V_30 )
{
return F_402 ( V_30 , & V_439 ) ;
}
void T_2 F_406 ( unsigned long V_448 )
{
V_408 = V_448 ;
}
void T_2 F_407 ( unsigned long * V_393 )
{
F_389 ( 0 , V_393 ,
F_408 ( V_449 ) >> V_364 , NULL ) ;
}
static int F_409 ( struct V_450 * V_347 ,
unsigned long V_451 , void * V_452 )
{
int V_111 = ( unsigned long ) V_452 ;
if ( V_451 == V_453 || V_451 == V_454 ) {
F_410 ( V_111 ) ;
F_130 ( V_111 ) ;
F_411 ( V_111 ) ;
F_412 ( V_111 ) ;
}
return V_455 ;
}
void T_2 F_413 ( void )
{
F_414 ( F_409 , 0 ) ;
}
static void F_415 ( void )
{
struct V_367 * V_270 ;
unsigned long V_456 = 0 ;
enum V_211 V_28 , V_329 ;
F_416 (pgdat) {
for ( V_28 = 0 ; V_28 < V_294 ; V_28 ++ ) {
struct V_11 * V_11 = V_270 -> V_272 + V_28 ;
unsigned long F_323 = 0 ;
for ( V_329 = V_28 ; V_329 < V_294 ; V_329 ++ ) {
if ( V_11 -> V_153 [ V_329 ] > F_323 )
F_323 = V_11 -> V_153 [ V_329 ] ;
}
F_323 += F_259 ( V_11 ) ;
if ( F_323 > V_11 -> V_257 )
F_323 = V_11 -> V_257 ;
V_456 += F_323 ;
V_11 -> V_457 = F_323 ;
}
}
V_457 = V_456 ;
V_458 = V_456 ;
}
static void F_417 ( void )
{
struct V_367 * V_270 ;
enum V_211 V_329 , V_459 ;
F_416 (pgdat) {
for ( V_329 = 0 ; V_329 < V_294 ; V_329 ++ ) {
struct V_11 * V_11 = V_270 -> V_272 + V_329 ;
unsigned long V_257 = V_11 -> V_257 ;
V_11 -> V_153 [ V_329 ] = 0 ;
V_459 = V_329 ;
while ( V_459 ) {
struct V_11 * V_460 ;
V_459 -- ;
if ( V_461 [ V_459 ] < 1 )
V_461 [ V_459 ] = 1 ;
V_460 = V_270 -> V_272 + V_459 ;
V_460 -> V_153 [ V_329 ] = V_257 /
V_461 [ V_459 ] ;
V_257 += V_460 -> V_257 ;
}
}
}
F_415 () ;
}
static void F_418 ( void )
{
unsigned long V_462 = V_463 >> ( V_364 - 10 ) ;
unsigned long V_464 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_419 (zone) {
if ( ! F_420 ( V_11 ) )
V_464 += V_11 -> V_257 ;
}
F_419 (zone) {
T_17 V_324 ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_324 = ( T_17 ) V_462 * V_11 -> V_257 ;
F_421 ( V_324 , V_464 ) ;
if ( F_420 ( V_11 ) ) {
int V_465 ;
V_465 = V_11 -> V_257 / 1024 ;
if ( V_465 < V_466 )
V_465 = V_466 ;
if ( V_465 > 128 )
V_465 = 128 ;
V_11 -> V_123 [ V_467 ] = V_465 ;
} else {
V_11 -> V_123 [ V_467 ] = V_324 ;
}
V_11 -> V_123 [ V_468 ] = F_274 ( V_11 ) + ( V_324 >> 2 ) ;
V_11 -> V_123 [ V_469 ] = F_274 ( V_11 ) + ( V_324 >> 1 ) ;
V_11 -> V_123 [ V_467 ] += F_422 ( V_11 ) ;
V_11 -> V_123 [ V_468 ] += F_422 ( V_11 ) ;
V_11 -> V_123 [ V_469 ] += F_422 ( V_11 ) ;
F_328 ( V_11 ) ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
}
F_415 () ;
}
void F_423 ( void )
{
F_285 ( & V_317 ) ;
F_418 () ;
F_288 ( & V_317 ) ;
}
static void T_3 F_424 ( struct V_11 * V_11 )
{
unsigned int V_470 , V_471 ;
V_470 = V_11 -> V_257 >> ( 30 - V_364 ) ;
if ( V_470 )
V_471 = F_425 ( 10 * V_470 ) ;
else
V_471 = 1 ;
V_11 -> V_472 = V_471 ;
}
static void T_3 F_426 ( void )
{
struct V_11 * V_11 ;
F_419 (zone)
F_424 ( V_11 ) ;
}
int T_3 F_427 ( void )
{
unsigned long V_473 ;
V_473 = F_260 () * ( V_75 >> 10 ) ;
V_463 = F_425 ( V_473 * 16 ) ;
if ( V_463 < 128 )
V_463 = 128 ;
if ( V_463 > 65536 )
V_463 = 65536 ;
F_423 () ;
F_428 () ;
F_417 () ;
F_426 () ;
return 0 ;
}
int F_429 ( T_10 * V_308 , int V_309 ,
void T_11 * V_310 , T_8 * V_311 , T_12 * V_312 )
{
F_430 ( V_308 , V_309 , V_310 , V_311 , V_312 ) ;
if ( V_309 )
F_423 () ;
return 0 ;
}
int F_431 ( T_10 * V_308 , int V_309 ,
void T_11 * V_310 , T_8 * V_311 , T_12 * V_312 )
{
struct V_11 * V_11 ;
int V_474 ;
V_474 = F_432 ( V_308 , V_309 , V_310 , V_311 , V_312 ) ;
if ( V_474 )
return V_474 ;
F_419 (zone)
V_11 -> V_414 = ( V_11 -> V_257 *
V_415 ) / 100 ;
return 0 ;
}
int F_433 ( T_10 * V_308 , int V_309 ,
void T_11 * V_310 , T_8 * V_311 , T_12 * V_312 )
{
struct V_11 * V_11 ;
int V_474 ;
V_474 = F_432 ( V_308 , V_309 , V_310 , V_311 , V_312 ) ;
if ( V_474 )
return V_474 ;
F_419 (zone)
V_11 -> V_416 = ( V_11 -> V_257 *
V_417 ) / 100 ;
return 0 ;
}
int F_434 ( T_10 * V_308 , int V_309 ,
void T_11 * V_310 , T_8 * V_311 , T_12 * V_312 )
{
F_432 ( V_308 , V_309 , V_310 , V_311 , V_312 ) ;
F_417 () ;
return 0 ;
}
int F_435 ( T_10 * V_308 , int V_309 ,
void T_11 * V_310 , T_8 * V_311 , T_12 * V_312 )
{
struct V_11 * V_11 ;
unsigned int V_111 ;
int V_12 ;
V_12 = F_432 ( V_308 , V_309 , V_310 , V_311 , V_312 ) ;
if ( ! V_309 || ( V_12 < 0 ) )
return V_12 ;
F_131 (zone) {
F_310 (cpu) {
unsigned long V_84 ;
V_84 = V_11 -> V_257 / V_365 ;
F_345 (
F_132 ( V_11 -> V_114 , V_111 ) , V_84 ) ;
}
}
return 0 ;
}
static int T_2 F_436 ( char * V_131 )
{
if ( ! V_131 )
return 0 ;
V_475 = F_437 ( V_131 , & V_131 , 0 ) ;
return 1 ;
}
void * T_2 F_438 ( const char * V_476 ,
unsigned long V_477 ,
unsigned long V_478 ,
int V_479 ,
int V_59 ,
unsigned int * V_480 ,
unsigned int * V_481 ,
unsigned long V_482 ,
unsigned long V_483 )
{
unsigned long long F_323 = V_483 ;
unsigned long V_484 , V_86 ;
void * V_308 = NULL ;
if ( ! V_478 ) {
V_478 = V_409 ;
V_478 += ( 1UL << ( 20 - V_364 ) ) - 1 ;
V_478 >>= 20 - V_364 ;
V_478 <<= 20 - V_364 ;
if ( V_479 > V_364 )
V_478 >>= ( V_479 - V_364 ) ;
else
V_478 <<= ( V_364 - V_479 ) ;
if ( F_7 ( V_59 & V_485 ) ) {
F_2 ( ! ( V_59 & V_486 ) ) ;
if ( ! ( V_478 >> * V_480 ) ) {
V_478 = 1UL << * V_480 ;
F_114 ( ! V_478 ) ;
}
} else if ( F_7 ( ( V_478 * V_477 ) < V_75 ) )
V_478 = V_75 / V_477 ;
}
V_478 = F_439 ( V_478 ) ;
if ( F_323 == 0 ) {
F_323 = ( ( unsigned long long ) V_410 << V_364 ) >> 4 ;
F_421 ( F_323 , V_477 ) ;
}
F_323 = V_152 ( F_323 , 0x80000000ULL ) ;
if ( V_478 < V_482 )
V_478 = V_482 ;
if ( V_478 > F_323 )
V_478 = F_323 ;
V_484 = F_440 ( V_478 ) ;
do {
V_86 = V_477 << V_484 ;
if ( V_59 & V_486 )
V_308 = F_441 ( V_86 ) ;
else if ( V_475 )
V_308 = F_442 ( V_86 , V_487 , V_488 ) ;
else {
if ( F_254 ( V_86 ) < V_37 ) {
V_308 = F_253 ( V_86 , V_487 ) ;
F_443 ( V_308 , V_86 , 1 , V_487 ) ;
}
}
} while ( ! V_308 && V_86 > V_75 && -- V_484 );
if ( ! V_308 )
F_444 ( L_80 , V_476 ) ;
F_21 ( V_40 L_81 ,
V_476 ,
( 1UL << V_484 ) ,
F_440 ( V_86 ) - V_364 ,
V_86 ) ;
if ( V_480 )
* V_480 = V_484 ;
if ( V_481 )
* V_481 = ( 1 << V_484 ) - 1 ;
return V_308 ;
}
static inline unsigned long * F_445 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_446
return F_447 ( V_14 ) -> V_401 ;
#else
return V_11 -> V_401 ;
#endif
}
static inline int F_448 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_446
V_14 &= ( V_489 - 1 ) ;
return ( V_14 >> V_81 ) * V_400 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_81 ) * V_400 ;
#endif
}
unsigned long F_449 ( struct V_5 * V_5 ,
int V_490 , int V_491 )
{
struct V_11 * V_11 ;
unsigned long * V_492 ;
unsigned long V_14 , V_493 ;
unsigned long V_59 = 0 ;
unsigned long V_494 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_492 = F_445 ( V_11 , V_14 ) ;
V_493 = F_448 ( V_11 , V_14 ) ;
for (; V_490 <= V_491 ; V_490 ++ , V_494 <<= 1 )
if ( F_186 ( V_493 + V_490 , V_492 ) )
V_59 |= V_494 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_490 , int V_491 )
{
struct V_11 * V_11 ;
unsigned long * V_492 ;
unsigned long V_14 , V_493 ;
unsigned long V_494 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_492 = F_445 ( V_11 , V_14 ) ;
V_493 = F_448 ( V_11 , V_14 ) ;
F_41 ( V_14 < V_11 -> V_15 ) ;
F_41 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_490 <= V_491 ; V_490 ++ , V_494 <<= 1 )
if ( V_59 & V_494 )
F_47 ( V_493 + V_490 , V_492 ) ;
else
F_49 ( V_493 + V_490 , V_492 ) ;
}
bool F_450 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 )
{
unsigned long V_14 , V_495 , V_496 ;
int V_106 ;
if ( F_191 ( V_11 ) == V_379 )
return false ;
V_106 = F_96 ( V_5 ) ;
if ( V_106 == V_121 || F_122 ( V_106 ) )
return false ;
V_14 = F_10 ( V_5 ) ;
for ( V_496 = 0 , V_495 = 0 ; V_495 < V_79 ; V_495 ++ ) {
unsigned long V_497 = V_14 + V_495 ;
if ( ! F_14 ( V_497 ) )
continue;
V_5 = F_119 ( V_497 ) ;
if ( ! F_73 ( & V_5 -> V_58 ) ) {
if ( F_61 ( V_5 ) )
V_495 += ( 1 << F_59 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_451 ( V_5 ) )
V_496 ++ ;
if ( V_496 > V_62 )
return true ;
}
return false ;
}
bool F_452 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_307 ( F_115 ( V_5 ) ) )
return false ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( V_11 -> V_15 > V_14 ||
V_11 -> V_15 + V_11 -> V_16 <= V_14 )
return false ;
return ! F_450 ( V_11 , V_5 , 0 ) ;
}
static unsigned long F_453 ( unsigned long V_14 )
{
return V_14 & ~ ( F_454 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_455 ( unsigned long V_14 )
{
return F_385 ( V_14 , F_454 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static struct V_5 *
F_456 ( struct V_5 * V_5 , unsigned long V_498 ,
int * * V_499 )
{
T_1 V_134 = V_258 | V_500 ;
if ( F_87 ( V_5 ) )
V_134 |= V_34 ;
return F_457 ( V_134 ) ;
}
static int F_458 ( unsigned long V_421 , unsigned long V_253 )
{
unsigned long V_14 = V_421 ;
unsigned int V_501 = 0 ;
int V_12 = 0 ;
struct V_502 V_503 = {
. V_504 = 0 ,
. V_27 = - 1 ,
. V_11 = F_15 ( F_119 ( V_421 ) ) ,
. V_505 = true ,
} ;
F_107 ( & V_503 . V_506 ) ;
F_459 () ;
while ( V_14 < V_253 || ! F_77 ( & V_503 . V_506 ) ) {
if ( F_460 ( V_24 ) ) {
V_12 = - V_507 ;
break;
}
if ( F_77 ( & V_503 . V_506 ) ) {
V_503 . V_504 = 0 ;
V_14 = F_461 ( V_503 . V_11 , & V_503 ,
V_14 , V_253 ) ;
if ( ! V_14 ) {
V_12 = - V_507 ;
break;
}
V_501 = 0 ;
} else if ( ++ V_501 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_508 ;
break;
}
V_12 = F_462 ( & V_503 . V_506 ,
F_456 ,
0 , false , V_509 ) ;
}
F_463 ( & V_503 . V_506 ) ;
return V_12 > 0 ? 0 : V_12 ;
}
static inline void F_464 ( struct V_11 * V_11 , int V_62 )
{
unsigned long V_59 ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_11 -> V_510 += V_62 ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
F_423 () ;
}
static int F_465 ( struct V_11 * V_11 , T_1 V_134 , int V_62 )
{
enum V_211 V_176 = F_238 ( V_134 ) ;
struct V_159 * V_159 = F_234 ( 0 , V_134 ) ;
int V_206 = 0 ;
int V_27 = 1 ;
F_464 ( V_11 , V_62 ) ;
while ( ! F_160 ( V_11 , 0 , F_159 ( V_11 ) , 0 , 0 ) ) {
F_225 ( V_27 , V_159 , V_176 , F_191 ( V_11 ) ) ;
V_206 = F_217 ( V_134 , V_27 , V_159 ,
NULL ) ;
if ( ! V_206 ) {
F_207 ( V_159 , V_134 , V_27 , NULL , false ) ;
}
}
F_464 ( V_11 , - V_62 ) ;
return V_62 ;
}
int F_466 ( unsigned long V_421 , unsigned long V_253 ,
unsigned V_6 )
{
struct V_11 * V_11 = F_15 ( F_119 ( V_421 ) ) ;
unsigned long V_511 , V_512 ;
int V_12 = 0 , V_27 ;
V_12 = F_467 ( F_453 ( V_421 ) ,
F_455 ( V_253 ) , V_6 ) ;
if ( V_12 )
goto V_513;
V_12 = F_458 ( V_421 , V_253 ) ;
if ( V_12 )
goto V_513;
F_468 () ;
F_135 () ;
V_27 = 0 ;
V_511 = V_421 ;
while ( ! F_61 ( F_119 ( V_511 ) ) ) {
if ( ++ V_27 >= V_37 ) {
V_12 = - V_508 ;
goto V_513;
}
V_511 &= ~ 0UL << V_27 ;
}
if ( F_469 ( V_511 , V_253 ) ) {
F_201 ( L_82 ,
V_511 , V_253 ) ;
V_12 = - V_508 ;
goto V_513;
}
F_465 ( V_11 , V_259 , V_253 - V_421 ) ;
V_512 = F_470 ( V_511 , V_253 ) ;
if ( ! V_512 ) {
V_12 = - V_508 ;
goto V_513;
}
if ( V_421 != V_511 )
F_471 ( V_511 , V_421 - V_511 ) ;
if ( V_253 != V_512 )
F_471 ( V_253 , V_512 - V_253 ) ;
V_513:
F_472 ( F_453 ( V_421 ) ,
F_455 ( V_253 ) , V_6 ) ;
return V_12 ;
}
void F_471 ( unsigned long V_14 , unsigned V_29 )
{
for (; V_29 -- ; ++ V_14 )
F_473 ( F_119 ( V_14 ) ) ;
}
static int T_3 F_474 ( void * V_315 )
{
struct V_11 * V_11 = V_315 ;
int V_111 ;
unsigned long V_110 = F_342 ( V_11 ) , V_59 ;
F_310 (cpu) {
struct V_112 * V_113 ;
struct V_63 * V_64 ;
V_113 = F_132 ( V_11 -> V_114 , V_111 ) ;
V_64 = & V_113 -> V_64 ;
F_94 ( V_59 ) ;
if ( V_64 -> V_62 > 0 )
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
F_311 ( V_113 , V_110 ) ;
F_97 ( V_59 ) ;
}
return 0 ;
}
void T_3 F_475 ( struct V_11 * V_11 )
{
F_321 ( F_474 , V_11 , NULL ) ;
}
void F_476 ( struct V_11 * V_11 )
{
unsigned long V_59 ;
F_94 ( V_59 ) ;
if ( V_11 -> V_114 != & V_348 ) {
F_477 ( V_11 -> V_114 ) ;
V_11 -> V_114 = & V_348 ;
}
F_97 ( V_59 ) ;
}
void
F_478 ( unsigned long V_94 , unsigned long V_95 )
{
struct V_5 * V_5 ;
struct V_11 * V_11 ;
int V_27 , V_28 ;
unsigned long V_14 ;
unsigned long V_59 ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ )
if ( F_142 ( V_14 ) )
break;
if ( V_14 == V_95 )
return;
V_11 = F_15 ( F_119 ( V_14 ) ) ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_14 = V_94 ;
while ( V_14 < V_95 ) {
if ( ! F_142 ( V_14 ) ) {
V_14 ++ ;
continue;
}
V_5 = F_119 ( V_14 ) ;
F_114 ( F_60 ( V_5 ) ) ;
F_114 ( ! F_61 ( V_5 ) ) ;
V_27 = F_59 ( V_5 ) ;
#ifdef F_479
F_21 ( V_40 L_83 ,
V_14 , 1 << V_27 , V_95 ) ;
#endif
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_64 ( V_11 , V_48 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_336 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_480 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_27 ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
struct V_5 * V_514 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_61 ( V_514 ) && F_59 ( V_514 ) >= V_27 )
break;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
return V_27 < V_37 ;
}
static void F_481 ( unsigned long V_59 )
{
const char * V_515 = L_84 ;
unsigned long V_430 ;
int V_28 ;
F_195 ( F_482 ( V_516 ) != V_517 ) ;
F_21 ( V_22 L_85 , V_59 ) ;
V_59 &= ( 1UL << V_518 ) - 1 ;
for ( V_28 = 0 ; V_28 < F_482 ( V_516 ) && V_59 ; V_28 ++ ) {
V_430 = V_516 [ V_28 ] . V_430 ;
if ( ( V_59 & V_430 ) != V_430 )
continue;
V_59 &= ~ V_430 ;
F_21 ( L_86 , V_515 , V_516 [ V_28 ] . V_274 ) ;
V_515 = L_87 ;
}
if ( V_59 )
F_21 ( L_88 , V_515 , V_59 ) ;
F_21 ( L_89 ) ;
}
void F_22 ( struct V_5 * V_5 )
{
F_21 ( V_22
L_90 ,
V_5 , F_73 ( & V_5 -> V_58 ) , F_72 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_519 ) ;
F_481 ( V_5 -> V_59 ) ;
F_483 ( V_5 ) ;
}
