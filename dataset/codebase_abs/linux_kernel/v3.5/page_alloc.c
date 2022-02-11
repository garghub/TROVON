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
static int F_118 ( struct V_11 * V_11 , struct V_5 * V_5 ,
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
F_75 ( V_11 , V_109 , V_64 ) ;
V_64 -> V_62 -= V_109 ;
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
static int F_167 ( T_1 V_134 , unsigned int V_27 )
{
if ( V_27 < V_132 . V_135 )
return 0 ;
if ( V_134 & V_129 )
return 0 ;
if ( V_132 . V_136 && ( V_134 & V_34 ) )
return 0 ;
if ( V_132 . V_137 && ( V_134 & V_138 ) )
return 0 ;
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
static inline int F_167 ( T_1 V_134 , unsigned int V_27 )
{
return 0 ;
}
static bool F_176 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 , long V_151 )
{
long V_152 = V_148 ;
int V_153 ;
V_151 -= ( 1 << V_27 ) - 1 ;
if ( V_150 & V_154 )
V_152 -= V_152 / 2 ;
if ( V_150 & V_155 )
V_152 -= V_152 / 4 ;
if ( V_151 <= V_152 + V_147 -> V_156 [ V_149 ] )
return false ;
for ( V_153 = 0 ; V_153 < V_27 ; V_153 ++ ) {
V_151 -= V_147 -> V_50 [ V_153 ] . V_51 << V_153 ;
V_152 >>= 1 ;
if ( V_151 <= V_152 )
return false ;
}
return true ;
}
bool F_160 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 )
{
return F_176 ( V_147 , V_27 , V_148 , V_149 , V_150 ,
F_177 ( V_147 , V_48 ) ) ;
}
bool F_178 ( struct V_11 * V_147 , int V_27 , unsigned long V_148 ,
int V_149 , int V_150 )
{
long V_151 = F_177 ( V_147 , V_48 ) ;
if ( V_147 -> V_157 && V_151 < V_147 -> V_157 )
V_151 = F_179 ( V_147 , V_48 ) ;
return F_176 ( V_147 , V_27 , V_148 , V_149 , V_150 ,
V_151 ) ;
}
static T_6 * F_180 ( struct V_158 * V_158 , int V_150 )
{
struct V_159 * V_160 ;
T_6 * V_161 ;
V_160 = V_158 -> V_162 ;
if ( ! V_160 )
return NULL ;
if ( F_181 ( V_20 , V_160 -> V_163 + V_23 ) ) {
F_182 ( V_160 -> V_164 , V_165 ) ;
V_160 -> V_163 = V_20 ;
}
V_161 = ! F_42 () && ( V_150 & V_166 ) ?
& V_167 :
& V_168 [ V_169 ] ;
return V_161 ;
}
static int F_183 ( struct V_158 * V_158 , struct V_170 * V_147 ,
T_6 * V_161 )
{
struct V_159 * V_160 ;
int V_28 ;
int V_171 ;
V_160 = V_158 -> V_162 ;
if ( ! V_160 )
return 1 ;
V_28 = V_147 - V_158 -> V_172 ;
V_171 = V_160 -> V_173 [ V_28 ] ;
return F_184 ( V_171 , * V_161 ) && ! F_185 ( V_28 , V_160 -> V_164 ) ;
}
static void F_186 ( struct V_158 * V_158 , struct V_170 * V_147 )
{
struct V_159 * V_160 ;
int V_28 ;
V_160 = V_158 -> V_162 ;
if ( ! V_160 )
return;
V_28 = V_147 - V_158 -> V_172 ;
F_187 ( V_28 , V_160 -> V_164 ) ;
}
static void F_188 ( struct V_158 * V_158 )
{
struct V_159 * V_160 ;
V_160 = V_158 -> V_162 ;
if ( ! V_160 )
return;
F_182 ( V_160 -> V_164 , V_165 ) ;
}
static T_6 * F_180 ( struct V_158 * V_158 , int V_150 )
{
return NULL ;
}
static int F_183 ( struct V_158 * V_158 , struct V_170 * V_147 ,
T_6 * V_161 )
{
return 1 ;
}
static void F_186 ( struct V_158 * V_158 , struct V_170 * V_147 )
{
}
static void F_188 ( struct V_158 * V_158 )
{
}
static struct V_5 *
F_189 ( T_1 V_134 , T_6 * V_174 , unsigned int V_27 ,
struct V_158 * V_158 , int V_175 , int V_150 ,
struct V_11 * V_125 , int V_6 )
{
struct V_170 * V_147 ;
struct V_5 * V_5 = NULL ;
int V_149 ;
struct V_11 * V_11 ;
T_6 * V_161 = NULL ;
int V_176 = 0 ;
int V_177 = 0 ;
V_149 = F_190 ( V_125 ) ;
V_178:
F_191 (zone, z, zonelist,
high_zoneidx, nodemask) {
if ( V_179 && V_176 &&
! F_183 ( V_158 , V_147 , V_161 ) )
continue;
if ( ( V_150 & V_166 ) &&
! F_192 ( V_11 , V_134 ) )
continue;
if ( ( V_150 & V_180 ) &&
( V_134 & V_181 ) && ! F_193 ( V_11 ) )
goto V_182;
F_194 ( V_183 < V_184 ) ;
if ( ! ( V_150 & V_183 ) ) {
unsigned long V_148 ;
int V_12 ;
V_148 = V_11 -> V_123 [ V_150 & V_185 ] ;
if ( F_160 ( V_11 , V_27 , V_148 ,
V_149 , V_150 ) )
goto V_186;
if ( V_179 && ! V_177 && V_187 > 1 ) {
V_161 = F_180 ( V_158 , V_150 ) ;
V_176 = 1 ;
V_177 = 1 ;
}
if ( V_188 == 0 )
goto V_182;
if ( V_179 && V_176 &&
! F_183 ( V_158 , V_147 , V_161 ) )
continue;
V_12 = F_195 ( V_11 , V_134 , V_27 ) ;
switch ( V_12 ) {
case V_189 :
continue;
case V_190 :
continue;
default:
if ( ! F_160 ( V_11 , V_27 , V_148 ,
V_149 , V_150 ) )
goto V_182;
}
}
V_186:
V_5 = F_161 ( V_125 , V_11 , V_27 ,
V_134 , V_6 ) ;
if ( V_5 )
break;
V_182:
if ( V_179 )
F_186 ( V_158 , V_147 ) ;
}
if ( F_7 ( V_179 && V_5 == NULL && V_176 ) ) {
V_176 = 0 ;
goto V_178;
}
return V_5 ;
}
static inline bool F_196 ( void )
{
bool V_12 = false ;
#if V_191 > 8
V_12 = F_42 () ;
#endif
return V_12 ;
}
void F_197 ( T_1 V_134 , int V_27 , const char * V_192 , ... )
{
unsigned int V_193 = V_194 ;
if ( ( V_134 & V_195 ) || ! F_198 ( & V_196 ) ||
F_106 () > 0 )
return;
if ( ! ( V_134 & V_197 ) )
if ( F_199 ( V_198 ) ||
( V_24 -> V_59 & ( V_199 | V_200 ) ) )
V_193 &= ~ V_194 ;
if ( F_42 () || ! ( V_134 & V_138 ) )
V_193 &= ~ V_194 ;
if ( V_192 ) {
struct V_201 V_202 ;
T_7 args ;
va_start ( args , V_192 ) ;
V_202 . V_192 = V_192 ;
V_202 . V_203 = & args ;
F_200 ( L_9 , & V_202 ) ;
va_end ( args ) ;
}
F_200 ( L_10 ,
V_24 -> V_25 , V_27 , V_134 ) ;
F_24 () ;
if ( ! F_196 () )
F_201 ( V_193 ) ;
}
static inline int
F_202 ( T_1 V_134 , unsigned int V_27 ,
unsigned long V_204 ,
unsigned long V_205 )
{
if ( V_134 & V_206 )
return 0 ;
if ( V_134 & V_129 )
return 1 ;
if ( ! V_204 && F_5 () )
return 0 ;
if ( V_27 <= V_207 )
return 1 ;
if ( V_134 & V_208 && V_205 < ( 1 << V_27 ) )
return 1 ;
return 0 ;
}
static inline struct V_5 *
F_203 ( T_1 V_134 , unsigned int V_27 ,
struct V_158 * V_158 , enum V_209 V_175 ,
T_6 * V_174 , struct V_11 * V_125 ,
int V_6 )
{
struct V_5 * V_5 ;
if ( ! F_204 ( V_158 , V_134 ) ) {
F_205 ( 1 ) ;
return NULL ;
}
V_5 = F_189 ( V_134 | V_210 , V_174 ,
V_27 , V_158 , V_175 ,
V_211 | V_166 ,
V_125 , V_6 ) ;
if ( V_5 )
goto V_21;
if ( ! ( V_134 & V_129 ) ) {
if ( V_27 > V_207 )
goto V_21;
if ( V_175 < V_212 )
goto V_21;
if ( V_134 & V_213 )
goto V_21;
}
F_206 ( V_158 , V_134 , V_27 , V_174 , false ) ;
V_21:
F_207 ( V_158 , V_134 ) ;
return V_5 ;
}
static struct V_5 *
F_208 ( T_1 V_134 , unsigned int V_27 ,
struct V_158 * V_158 , enum V_209 V_175 ,
T_6 * V_174 , int V_150 , struct V_11 * V_125 ,
int V_6 , bool V_214 ,
bool * V_215 ,
unsigned long * V_204 )
{
struct V_5 * V_5 ;
if ( ! V_27 )
return NULL ;
if ( F_209 ( V_125 , V_27 ) ) {
* V_215 = true ;
return NULL ;
}
V_24 -> V_59 |= V_199 ;
* V_204 = F_210 ( V_158 , V_27 , V_134 ,
V_174 , V_214 ) ;
V_24 -> V_59 &= ~ V_199 ;
if ( * V_204 != V_216 ) {
F_130 ( F_211 () ) ;
F_212 () ;
V_5 = F_189 ( V_134 , V_174 ,
V_27 , V_158 , V_175 ,
V_150 , V_125 ,
V_6 ) ;
if ( V_5 ) {
V_125 -> V_217 = 0 ;
V_125 -> V_218 = 0 ;
if ( V_27 >= V_125 -> V_219 )
V_125 -> V_219 = V_27 + 1 ;
F_213 ( V_220 ) ;
return V_5 ;
}
F_213 ( V_221 ) ;
if ( V_214 )
F_214 ( V_125 , V_27 ) ;
F_215 () ;
}
return NULL ;
}
static inline struct V_5 *
F_208 ( T_1 V_134 , unsigned int V_27 ,
struct V_158 * V_158 , enum V_209 V_175 ,
T_6 * V_174 , int V_150 , struct V_11 * V_125 ,
int V_6 , bool V_214 ,
bool * V_215 ,
unsigned long * V_204 )
{
return NULL ;
}
static int
F_216 ( T_1 V_134 , unsigned int V_27 , struct V_158 * V_158 ,
T_6 * V_174 )
{
struct V_222 V_222 ;
int V_223 ;
F_215 () ;
F_217 () ;
V_24 -> V_59 |= V_199 ;
F_218 ( V_134 ) ;
V_222 . V_224 = 0 ;
V_24 -> V_222 = & V_222 ;
V_223 = F_219 ( V_158 , V_27 , V_134 , V_174 ) ;
V_24 -> V_222 = NULL ;
F_220 () ;
V_24 -> V_59 &= ~ V_199 ;
F_215 () ;
return V_223 ;
}
static inline struct V_5 *
F_221 ( T_1 V_134 , unsigned int V_27 ,
struct V_158 * V_158 , enum V_209 V_175 ,
T_6 * V_174 , int V_150 , struct V_11 * V_125 ,
int V_6 , unsigned long * V_204 )
{
struct V_5 * V_5 = NULL ;
bool V_225 = false ;
* V_204 = F_216 ( V_134 , V_27 , V_158 ,
V_174 ) ;
if ( F_7 ( ! ( * V_204 ) ) )
return NULL ;
if ( V_179 )
F_188 ( V_158 ) ;
V_226:
V_5 = F_189 ( V_134 , V_174 , V_27 ,
V_158 , V_175 ,
V_150 , V_125 ,
V_6 ) ;
if ( ! V_5 && ! V_225 ) {
F_135 () ;
V_225 = true ;
goto V_226;
}
return V_5 ;
}
static inline struct V_5 *
F_222 ( T_1 V_134 , unsigned int V_27 ,
struct V_158 * V_158 , enum V_209 V_175 ,
T_6 * V_174 , struct V_11 * V_125 ,
int V_6 )
{
struct V_5 * V_5 ;
do {
V_5 = F_189 ( V_134 , V_174 , V_27 ,
V_158 , V_175 , V_183 ,
V_125 , V_6 ) ;
if ( ! V_5 && V_134 & V_129 )
F_223 ( V_125 , V_227 , V_23 / 50 ) ;
} while ( ! V_5 && ( V_134 & V_129 ) );
return V_5 ;
}
static inline
void F_224 ( unsigned int V_27 , struct V_158 * V_158 ,
enum V_209 V_175 ,
enum V_209 V_149 )
{
struct V_170 * V_147 ;
struct V_11 * V_11 ;
F_225 (zone, z, zonelist, high_zoneidx)
F_226 ( V_11 , V_27 , V_149 ) ;
}
static inline int
F_227 ( T_1 V_134 )
{
int V_150 = V_228 | V_166 ;
const T_1 V_229 = V_134 & V_138 ;
F_194 ( V_230 != ( V_231 T_1 ) V_154 ) ;
V_150 |= ( V_231 int ) ( V_134 & V_230 ) ;
if ( ! V_229 ) {
if ( ! ( V_134 & V_197 ) )
V_150 |= V_155 ;
V_150 &= ~ V_166 ;
} else if ( F_7 ( F_228 ( V_24 ) ) && ! F_42 () )
V_150 |= V_155 ;
if ( F_127 ( ! ( V_134 & V_197 ) ) ) {
if ( ! F_42 () &&
( ( V_24 -> V_59 & V_199 ) ||
F_7 ( F_199 ( V_198 ) ) ) )
V_150 |= V_183 ;
}
return V_150 ;
}
static inline struct V_5 *
F_229 ( T_1 V_134 , unsigned int V_27 ,
struct V_158 * V_158 , enum V_209 V_175 ,
T_6 * V_174 , struct V_11 * V_125 ,
int V_6 )
{
const T_1 V_229 = V_134 & V_138 ;
struct V_5 * V_5 = NULL ;
int V_150 ;
unsigned long V_205 = 0 ;
unsigned long V_204 ;
bool V_214 = false ;
bool V_215 = false ;
if ( V_27 >= V_37 ) {
F_162 ( ! ( V_134 & V_195 ) ) ;
return NULL ;
}
if ( V_179 && ( V_134 & V_232 ) == V_232 )
goto V_233;
V_234:
if ( ! ( V_134 & V_235 ) )
F_224 ( V_27 , V_158 , V_175 ,
F_190 ( V_125 ) ) ;
V_150 = F_227 ( V_134 ) ;
if ( ! ( V_150 & V_166 ) && ! V_174 )
F_230 ( V_158 , V_175 , NULL ,
& V_125 ) ;
V_236:
V_5 = F_189 ( V_134 , V_174 , V_27 , V_158 ,
V_175 , V_150 & ~ V_183 ,
V_125 , V_6 ) ;
if ( V_5 )
goto V_237;
if ( V_150 & V_183 ) {
V_5 = F_222 ( V_134 , V_27 ,
V_158 , V_175 , V_174 ,
V_125 , V_6 ) ;
if ( V_5 )
goto V_237;
}
if ( ! V_229 )
goto V_233;
if ( V_24 -> V_59 & V_199 )
goto V_233;
if ( F_199 ( V_198 ) && ! ( V_134 & V_129 ) )
goto V_233;
V_5 = F_208 ( V_134 , V_27 ,
V_158 , V_175 ,
V_174 ,
V_150 , V_125 ,
V_6 , V_214 ,
& V_215 ,
& V_204 ) ;
if ( V_5 )
goto V_237;
V_214 = true ;
if ( V_215 && ( V_134 & V_235 ) )
goto V_233;
V_5 = F_221 ( V_134 , V_27 ,
V_158 , V_175 ,
V_174 ,
V_150 , V_125 ,
V_6 , & V_204 ) ;
if ( V_5 )
goto V_237;
if ( ! V_204 ) {
if ( ( V_134 & V_238 ) && ! ( V_134 & V_206 ) ) {
if ( V_239 )
goto V_233;
if ( ( V_24 -> V_59 & V_240 ) &&
! ( V_134 & V_129 ) )
goto V_233;
V_5 = F_203 ( V_134 , V_27 ,
V_158 , V_175 ,
V_174 , V_125 ,
V_6 ) ;
if ( V_5 )
goto V_237;
if ( ! ( V_134 & V_129 ) ) {
if ( V_27 > V_207 )
goto V_233;
if ( V_175 < V_212 )
goto V_233;
}
goto V_234;
}
}
V_205 += V_204 ;
if ( F_202 ( V_134 , V_27 , V_204 ,
V_205 ) ) {
F_223 ( V_125 , V_227 , V_23 / 50 ) ;
goto V_236;
} else {
V_5 = F_208 ( V_134 , V_27 ,
V_158 , V_175 ,
V_174 ,
V_150 , V_125 ,
V_6 , V_214 ,
& V_215 ,
& V_204 ) ;
if ( V_5 )
goto V_237;
}
V_233:
F_197 ( V_134 , V_27 , NULL ) ;
return V_5 ;
V_237:
if ( V_241 )
F_231 ( V_5 , V_27 , V_134 ) ;
return V_5 ;
}
struct V_5 *
F_232 ( T_1 V_134 , unsigned int V_27 ,
struct V_158 * V_158 , T_6 * V_174 )
{
enum V_209 V_175 = F_233 ( V_134 ) ;
struct V_11 * V_125 ;
struct V_5 * V_5 = NULL ;
int V_6 = F_234 ( V_134 ) ;
unsigned int V_242 ;
V_134 &= V_3 ;
F_235 ( V_134 ) ;
F_236 ( V_134 & V_138 ) ;
if ( F_167 ( V_134 , V_27 ) )
return NULL ;
if ( F_7 ( ! V_158 -> V_172 -> V_11 ) )
return NULL ;
V_243:
V_242 = F_237 () ;
F_230 ( V_158 , V_175 ,
V_174 ? : & V_167 ,
& V_125 ) ;
if ( ! V_125 )
goto V_21;
V_5 = F_189 ( V_134 | V_210 , V_174 , V_27 ,
V_158 , V_175 , V_180 | V_166 ,
V_125 , V_6 ) ;
if ( F_7 ( ! V_5 ) )
V_5 = F_229 ( V_134 , V_27 ,
V_158 , V_175 , V_174 ,
V_125 , V_6 ) ;
F_238 ( V_5 , V_27 , V_134 , V_6 ) ;
V_21:
if ( F_7 ( ! F_239 ( V_242 ) && ! V_5 ) )
goto V_243;
return V_5 ;
}
unsigned long F_240 ( T_1 V_134 , unsigned int V_27 )
{
struct V_5 * V_5 ;
F_41 ( ( V_134 & V_34 ) != 0 ) ;
V_5 = F_241 ( V_134 , V_27 ) ;
if ( ! V_5 )
return 0 ;
return ( unsigned long ) F_89 ( V_5 ) ;
}
unsigned long F_242 ( T_1 V_134 )
{
return F_240 ( V_134 | V_87 , 0 ) ;
}
void F_102 ( struct V_5 * V_5 , unsigned int V_27 )
{
if ( F_243 ( V_5 ) ) {
if ( V_27 == 0 )
F_149 ( V_5 , 0 ) ;
else
F_27 ( V_5 , V_27 ) ;
}
}
void V_151 ( unsigned long V_244 , unsigned int V_27 )
{
if ( V_244 != 0 ) {
F_41 ( ! F_244 ( ( void * ) V_244 ) ) ;
F_102 ( F_157 ( ( void * ) V_244 ) , V_27 ) ;
}
}
static void * F_245 ( unsigned long V_244 , unsigned V_27 , T_8 V_86 )
{
if ( V_244 ) {
unsigned long V_245 = V_244 + ( V_75 << V_27 ) ;
unsigned long V_246 = V_244 + F_246 ( V_86 ) ;
F_154 ( F_157 ( ( void * ) V_244 ) , V_27 ) ;
while ( V_246 < V_245 ) {
F_247 ( V_246 ) ;
V_246 += V_75 ;
}
}
return ( void * ) V_244 ;
}
void * F_248 ( T_8 V_86 , T_1 V_134 )
{
unsigned int V_27 = F_249 ( V_86 ) ;
unsigned long V_244 ;
V_244 = F_240 ( V_134 , V_27 ) ;
return F_245 ( V_244 , V_27 , V_86 ) ;
}
void * F_250 ( int V_247 , T_8 V_86 , T_1 V_134 )
{
unsigned V_27 = F_249 ( V_86 ) ;
struct V_5 * V_30 = F_251 ( V_247 , V_134 , V_27 ) ;
if ( ! V_30 )
return NULL ;
return F_245 ( ( unsigned long ) F_89 ( V_30 ) , V_27 , V_86 ) ;
}
void F_252 ( void * V_248 , T_8 V_86 )
{
unsigned long V_244 = ( unsigned long ) V_248 ;
unsigned long V_249 = V_244 + F_246 ( V_86 ) ;
while ( V_244 < V_249 ) {
F_247 ( V_244 ) ;
V_244 += V_75 ;
}
}
static unsigned int F_253 ( int V_250 )
{
struct V_170 * V_147 ;
struct V_11 * V_11 ;
unsigned int V_251 = 0 ;
struct V_158 * V_158 = F_254 ( F_255 () , V_252 ) ;
F_225 (zone, z, zonelist, offset) {
unsigned long V_86 = V_11 -> V_253 ;
unsigned long V_84 = F_256 ( V_11 ) ;
if ( V_86 > V_84 )
V_251 += V_86 - V_84 ;
}
return V_251 ;
}
unsigned int F_257 ( void )
{
return F_253 ( F_233 ( V_254 ) ) ;
}
unsigned int F_258 ( void )
{
return F_253 ( F_233 ( V_255 ) ) ;
}
static inline void F_259 ( struct V_11 * V_11 )
{
if ( V_179 )
F_21 ( L_11 , F_116 ( V_11 ) ) ;
}
void F_260 ( struct V_256 * V_257 )
{
V_257 -> V_258 = V_82 ;
V_257 -> V_259 = 0 ;
V_257 -> V_260 = F_261 ( V_48 ) ;
V_257 -> V_261 = F_262 () ;
V_257 -> V_262 = V_263 ;
V_257 -> V_264 = F_263 () ;
V_257 -> V_265 = V_75 ;
}
void F_264 ( struct V_256 * V_257 , int V_247 )
{
T_9 * V_266 = F_265 ( V_247 ) ;
V_257 -> V_258 = V_266 -> V_267 ;
V_257 -> V_260 = F_266 ( V_247 , V_48 ) ;
#ifdef F_267
V_257 -> V_262 = V_266 -> V_268 [ V_269 ] . V_253 ;
V_257 -> V_264 = F_177 ( & V_266 -> V_268 [ V_269 ] ,
V_48 ) ;
#else
V_257 -> V_262 = 0 ;
V_257 -> V_264 = 0 ;
#endif
V_257 -> V_265 = V_75 ;
}
bool F_268 ( unsigned int V_59 , int V_247 )
{
bool V_12 = false ;
unsigned int V_242 ;
if ( ! ( V_59 & V_194 ) )
goto V_21;
do {
V_242 = F_237 () ;
V_12 = ! F_184 ( V_247 , V_167 ) ;
} while ( ! F_239 ( V_242 ) );
V_21:
return V_12 ;
}
void F_269 ( unsigned int V_193 )
{
int V_111 ;
struct V_11 * V_11 ;
F_131 (zone) {
if ( F_268 ( V_193 , F_116 ( V_11 ) ) )
continue;
F_259 ( V_11 ) ;
F_21 ( L_12 , V_11 -> V_270 ) ;
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
F_261 ( V_271 ) ,
F_261 ( V_272 ) ,
F_261 ( V_273 ) ,
F_261 ( V_274 ) ,
F_261 ( V_275 ) ,
F_261 ( V_276 ) ,
F_261 ( V_277 ) ,
F_261 ( V_278 ) ,
F_261 ( V_279 ) ,
F_261 ( V_280 ) ,
F_261 ( V_48 ) ,
F_261 ( V_281 ) ,
F_261 ( V_282 ) ,
F_261 ( V_283 ) ,
F_261 ( V_284 ) ,
F_261 ( V_285 ) ,
F_261 ( V_286 ) ) ;
F_131 (zone) {
int V_28 ;
if ( F_268 ( V_193 , F_116 ( V_11 ) ) )
continue;
F_259 ( V_11 ) ;
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
V_11 -> V_270 ,
F_270 ( F_177 ( V_11 , V_48 ) ) ,
F_270 ( F_271 ( V_11 ) ) ,
F_270 ( F_159 ( V_11 ) ) ,
F_270 ( F_256 ( V_11 ) ) ,
F_270 ( F_177 ( V_11 , V_271 ) ) ,
F_270 ( F_177 ( V_11 , V_272 ) ) ,
F_270 ( F_177 ( V_11 , V_274 ) ) ,
F_270 ( F_177 ( V_11 , V_275 ) ) ,
F_270 ( F_177 ( V_11 , V_277 ) ) ,
F_270 ( F_177 ( V_11 , V_273 ) ) ,
F_270 ( F_177 ( V_11 , V_276 ) ) ,
F_270 ( V_11 -> V_253 ) ,
F_270 ( F_177 ( V_11 , V_55 ) ) ,
F_270 ( F_177 ( V_11 , V_278 ) ) ,
F_270 ( F_177 ( V_11 , V_279 ) ) ,
F_270 ( F_177 ( V_11 , V_283 ) ) ,
F_270 ( F_177 ( V_11 , V_284 ) ) ,
F_270 ( F_177 ( V_11 , V_281 ) ) ,
F_270 ( F_177 ( V_11 , V_282 ) ) ,
F_177 ( V_11 , V_287 ) *
V_288 / 1024 ,
F_270 ( F_177 ( V_11 , V_285 ) ) ,
F_270 ( F_177 ( V_11 , V_280 ) ) ,
F_270 ( F_177 ( V_11 , V_286 ) ) ,
F_270 ( F_177 ( V_11 , V_289 ) ) ,
V_11 -> V_69 ,
( V_11 -> V_68 ? L_48 : L_49 )
) ;
F_21 ( L_50 ) ;
for ( V_28 = 0 ; V_28 < V_290 ; V_28 ++ )
F_21 ( L_51 , V_11 -> V_156 [ V_28 ] ) ;
F_21 ( L_47 ) ;
}
F_131 (zone) {
unsigned long V_291 [ V_37 ] , V_59 , V_27 , V_292 = 0 ;
if ( F_268 ( V_193 , F_116 ( V_11 ) ) )
continue;
F_259 ( V_11 ) ;
F_21 ( L_52 , V_11 -> V_270 ) ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
V_291 [ V_27 ] = V_11 -> V_50 [ V_27 ] . V_51 ;
V_292 += V_291 [ V_27 ] << V_27 ;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ )
F_21 ( L_53 , V_291 [ V_27 ] , F_270 ( 1UL ) << V_27 ) ;
F_21 ( L_54 , F_270 ( V_292 ) ) ;
}
F_21 ( L_55 , F_261 ( V_293 ) ) ;
F_272 () ;
}
static void F_273 ( struct V_11 * V_11 , struct V_170 * V_170 )
{
V_170 -> V_11 = V_11 ;
V_170 -> F_190 = F_190 ( V_11 ) ;
}
static int F_274 ( T_9 * V_266 , struct V_158 * V_158 ,
int V_294 , enum V_209 V_209 )
{
struct V_11 * V_11 ;
F_114 ( V_209 >= V_290 ) ;
V_209 ++ ;
do {
V_209 -- ;
V_11 = V_266 -> V_268 + V_209 ;
if ( F_275 ( V_11 ) ) {
F_273 ( V_11 ,
& V_158 -> V_172 [ V_294 ++ ] ) ;
F_276 ( V_209 ) ;
}
} while ( V_209 );
return V_294 ;
}
static int F_277 ( char * V_295 )
{
if ( * V_295 == 'd' || * V_295 == 'D' ) {
V_296 = V_297 ;
} else if ( * V_295 == 'n' || * V_295 == 'N' ) {
V_296 = V_298 ;
} else if ( * V_295 == 'z' || * V_295 == 'Z' ) {
V_296 = V_299 ;
} else {
F_21 ( V_300
L_56
L_57 , V_295 ) ;
return - V_301 ;
}
return 0 ;
}
static T_2 int F_278 ( char * V_295 )
{
int V_12 ;
if ( ! V_295 )
return 0 ;
V_12 = F_277 ( V_295 ) ;
if ( V_12 == 0 )
F_279 ( V_302 , V_295 , V_303 ) ;
return V_12 ;
}
int F_280 ( T_10 * V_304 , int V_305 ,
void T_11 * V_306 , T_8 * V_307 ,
T_12 * V_308 )
{
char V_309 [ V_303 ] ;
int V_12 ;
static F_281 ( V_310 ) ;
F_282 ( & V_310 ) ;
if ( V_305 )
strcpy ( V_309 , ( char * ) V_304 -> V_311 ) ;
V_12 = F_283 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
if ( V_12 )
goto V_21;
if ( V_305 ) {
int V_312 = V_296 ;
if ( F_277 ( ( char * ) V_304 -> V_311 ) ) {
strncpy ( ( char * ) V_304 -> V_311 , V_309 ,
V_303 ) ;
V_296 = V_312 ;
} else if ( V_312 != V_296 ) {
F_282 ( & V_313 ) ;
F_284 ( NULL ) ;
F_285 ( & V_313 ) ;
}
}
V_21:
F_285 ( & V_310 ) ;
return V_12 ;
}
static int F_286 ( int V_314 , T_6 * V_315 )
{
int V_171 , V_257 ;
int V_316 = V_317 ;
int V_318 = - 1 ;
const struct V_319 * V_320 = F_287 ( 0 ) ;
if ( ! F_184 ( V_314 , * V_315 ) ) {
F_288 ( V_314 , * V_315 ) ;
return V_314 ;
}
F_289 (n, N_HIGH_MEMORY) {
if ( F_184 ( V_171 , * V_315 ) )
continue;
V_257 = F_290 ( V_314 , V_171 ) ;
V_257 += ( V_171 < V_314 ) ;
V_320 = F_287 ( V_171 ) ;
if ( ! F_291 ( V_320 ) )
V_257 += V_321 ;
V_257 *= ( V_322 * V_323 ) ;
V_257 += V_324 [ V_171 ] ;
if ( V_257 < V_316 ) {
V_316 = V_257 ;
V_318 = V_171 ;
}
}
if ( V_318 >= 0 )
F_288 ( V_318 , * V_315 ) ;
return V_318 ;
}
static void F_292 ( T_9 * V_266 , int V_314 )
{
int V_325 ;
struct V_158 * V_158 ;
V_158 = & V_266 -> V_326 [ 0 ] ;
for ( V_325 = 0 ; V_158 -> V_172 [ V_325 ] . V_11 != NULL ; V_325 ++ )
;
V_325 = F_274 ( F_265 ( V_314 ) , V_158 , V_325 ,
V_290 - 1 ) ;
V_158 -> V_172 [ V_325 ] . V_11 = NULL ;
V_158 -> V_172 [ V_325 ] . F_190 = 0 ;
}
static void F_293 ( T_9 * V_266 )
{
int V_325 ;
struct V_158 * V_158 ;
V_158 = & V_266 -> V_326 [ 1 ] ;
V_325 = F_274 ( V_266 , V_158 , 0 , V_290 - 1 ) ;
V_158 -> V_172 [ V_325 ] . V_11 = NULL ;
V_158 -> V_172 [ V_325 ] . F_190 = 0 ;
}
static void F_294 ( T_9 * V_266 , int V_327 )
{
int V_328 , V_325 , V_314 ;
int V_209 ;
struct V_11 * V_147 ;
struct V_158 * V_158 ;
V_158 = & V_266 -> V_326 [ 0 ] ;
V_328 = 0 ;
for ( V_209 = V_290 - 1 ; V_209 >= 0 ; V_209 -- ) {
for ( V_325 = 0 ; V_325 < V_327 ; V_325 ++ ) {
V_314 = V_329 [ V_325 ] ;
V_147 = & F_265 ( V_314 ) -> V_268 [ V_209 ] ;
if ( F_275 ( V_147 ) ) {
F_273 ( V_147 ,
& V_158 -> V_172 [ V_328 ++ ] ) ;
F_276 ( V_209 ) ;
}
}
}
V_158 -> V_172 [ V_328 ] . V_11 = NULL ;
V_158 -> V_172 [ V_328 ] . F_190 = 0 ;
}
static int F_295 ( void )
{
int V_247 , V_209 ;
unsigned long V_330 , V_331 ;
struct V_11 * V_147 ;
int V_332 ;
V_330 = 0 ;
V_331 = 0 ;
F_296 (nid) {
for ( V_209 = 0 ; V_209 < V_290 ; V_209 ++ ) {
V_147 = & F_265 ( V_247 ) -> V_268 [ V_209 ] ;
if ( F_275 ( V_147 ) ) {
if ( V_209 < V_212 )
V_330 += V_147 -> V_253 ;
V_331 += V_147 -> V_253 ;
} else if ( V_209 == V_212 ) {
return V_298 ;
}
}
}
if ( ! V_330 ||
V_330 > V_331 / 2 )
return V_298 ;
V_332 = V_331 /
( F_297 ( V_168 [ V_169 ] ) + 1 ) ;
F_296 (nid) {
V_330 = 0 ;
V_331 = 0 ;
for ( V_209 = 0 ; V_209 < V_290 ; V_209 ++ ) {
V_147 = & F_265 ( V_247 ) -> V_268 [ V_209 ] ;
if ( F_275 ( V_147 ) ) {
if ( V_209 < V_212 )
V_330 += V_147 -> V_253 ;
V_331 += V_147 -> V_253 ;
}
}
if ( V_330 &&
V_331 > V_332 &&
V_330 > V_331 * 70 / 100 )
return V_298 ;
}
return V_299 ;
}
static void F_298 ( void )
{
if ( V_296 == V_297 )
V_333 = F_295 () ;
else
V_333 = V_296 ;
}
static void F_299 ( T_9 * V_266 )
{
int V_325 , V_314 , V_334 ;
enum V_209 V_28 ;
T_6 V_335 ;
int V_336 , V_337 ;
struct V_158 * V_158 ;
int V_27 = V_333 ;
for ( V_28 = 0 ; V_28 < V_338 ; V_28 ++ ) {
V_158 = V_266 -> V_326 + V_28 ;
V_158 -> V_172 [ 0 ] . V_11 = NULL ;
V_158 -> V_172 [ 0 ] . F_190 = 0 ;
}
V_336 = V_266 -> V_339 ;
V_334 = V_187 ;
V_337 = V_336 ;
F_300 ( V_335 ) ;
memset ( V_329 , 0 , sizeof( V_329 ) ) ;
V_325 = 0 ;
while ( ( V_314 = F_286 ( V_336 , & V_335 ) ) >= 0 ) {
int V_340 = F_290 ( V_336 , V_314 ) ;
if ( V_340 > V_341 )
V_188 = 1 ;
if ( V_340 != F_290 ( V_336 , V_337 ) )
V_324 [ V_314 ] = V_334 ;
V_337 = V_314 ;
V_334 -- ;
if ( V_27 == V_298 )
F_292 ( V_266 , V_314 ) ;
else
V_329 [ V_325 ++ ] = V_314 ;
}
if ( V_27 == V_299 ) {
F_294 ( V_266 , V_325 ) ;
}
F_293 ( V_266 ) ;
}
static void F_301 ( T_9 * V_266 )
{
struct V_158 * V_158 ;
struct V_159 * V_160 ;
struct V_170 * V_147 ;
V_158 = & V_266 -> V_326 [ 0 ] ;
V_158 -> V_162 = V_160 = & V_158 -> V_342 ;
F_182 ( V_160 -> V_164 , V_165 ) ;
for ( V_147 = V_158 -> V_172 ; V_147 -> V_11 ; V_147 ++ )
V_160 -> V_173 [ V_147 - V_158 -> V_172 ] = F_302 ( V_147 ) ;
}
int F_303 ( int V_314 )
{
struct V_11 * V_11 ;
( void ) F_230 ( F_254 ( V_314 , V_252 ) ,
F_233 ( V_252 ) ,
NULL ,
& V_11 ) ;
return V_11 -> V_314 ;
}
static void F_298 ( void )
{
V_333 = V_299 ;
}
static void F_299 ( T_9 * V_266 )
{
int V_314 , V_336 ;
enum V_209 V_325 ;
struct V_158 * V_158 ;
V_336 = V_266 -> V_339 ;
V_158 = & V_266 -> V_326 [ 0 ] ;
V_325 = F_274 ( V_266 , V_158 , 0 , V_290 - 1 ) ;
for ( V_314 = V_336 + 1 ; V_314 < V_323 ; V_314 ++ ) {
if ( ! F_304 ( V_314 ) )
continue;
V_325 = F_274 ( F_265 ( V_314 ) , V_158 , V_325 ,
V_290 - 1 ) ;
}
for ( V_314 = 0 ; V_314 < V_336 ; V_314 ++ ) {
if ( ! F_304 ( V_314 ) )
continue;
V_325 = F_274 ( F_265 ( V_314 ) , V_158 , V_325 ,
V_290 - 1 ) ;
}
V_158 -> V_172 [ V_325 ] . V_11 = NULL ;
V_158 -> V_172 [ V_325 ] . F_190 = 0 ;
}
static void F_301 ( T_9 * V_266 )
{
V_266 -> V_326 [ 0 ] . V_162 = NULL ;
}
static T_13 int F_305 ( void * V_311 )
{
int V_247 ;
int V_111 ;
#ifdef F_306
memset ( V_324 , 0 , sizeof( V_324 ) ) ;
#endif
F_296 (nid) {
T_9 * V_266 = F_265 ( V_247 ) ;
F_299 ( V_266 ) ;
F_301 ( V_266 ) ;
}
F_307 (cpu) {
F_308 ( & F_309 ( V_343 , V_111 ) , 0 ) ;
#ifdef F_310
if ( F_311 ( V_111 ) )
F_312 ( V_111 , F_303 ( F_313 ( V_111 ) ) ) ;
#endif
}
return 0 ;
}
void T_14 F_284 ( void * V_311 )
{
F_298 () ;
if ( V_344 == V_345 ) {
F_305 ( NULL ) ;
F_314 () ;
F_315 () ;
} else {
#ifdef F_316
if ( V_311 )
F_317 ( (struct V_11 * ) V_311 ) ;
#endif
F_318 ( F_305 , NULL , NULL ) ;
}
V_346 = F_258 () ;
if ( V_346 < ( V_79 * V_347 ) )
V_7 = 1 ;
else
V_7 = 0 ;
F_21 ( L_58
L_59 ,
V_187 ,
V_348 [ V_333 ] ,
V_7 ? L_60 : L_61 ,
V_346 ) ;
#ifdef F_306
F_21 ( L_62 , V_349 [ V_350 ] ) ;
#endif
}
static inline unsigned long F_319 ( unsigned long V_103 )
{
unsigned long V_86 = 1 ;
V_103 /= V_351 ;
while ( V_86 < V_103 )
V_86 <<= 1 ;
V_86 = V_152 ( V_86 , 4096UL ) ;
return F_320 ( V_86 , 4UL ) ;
}
static inline unsigned long F_319 ( unsigned long V_103 )
{
return 4096UL ;
}
static inline unsigned long F_321 ( unsigned long V_86 )
{
return F_322 ( ~ V_86 ) ;
}
static int F_323 ( unsigned long V_94 , unsigned long V_95 )
{
unsigned long V_14 ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ ) {
if ( ! F_14 ( V_14 ) || F_324 ( F_119 ( V_14 ) ) )
return 1 ;
}
return 0 ;
}
static void F_325 ( struct V_11 * V_11 )
{
unsigned long V_94 , V_14 , V_95 , V_352 ;
struct V_5 * V_5 ;
unsigned long V_353 ;
int V_354 ;
V_94 = V_11 -> V_15 ;
V_95 = V_94 + V_11 -> V_16 ;
V_94 = F_326 ( V_94 , V_79 ) ;
V_354 = F_326 ( F_271 ( V_11 ) , V_79 ) >>
V_81 ;
V_354 = V_152 ( 2 , V_354 ) ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 += V_79 ) {
if ( ! F_142 ( V_14 ) )
continue;
V_5 = F_119 ( V_14 ) ;
if ( F_115 ( V_5 ) != F_116 ( V_11 ) )
continue;
V_353 = F_96 ( V_5 ) ;
if ( V_354 > 0 ) {
V_352 = V_152 ( V_14 + V_79 , V_95 ) ;
if ( F_323 ( V_14 , V_352 ) )
continue;
if ( V_353 == V_101 ) {
V_354 -- ;
continue;
}
if ( V_353 == V_121 ) {
F_6 ( V_5 ,
V_101 ) ;
F_118 ( V_11 , V_5 ,
V_101 ) ;
V_354 -- ;
continue;
}
}
if ( V_353 == V_101 ) {
F_6 ( V_5 , V_121 ) ;
F_118 ( V_11 , V_5 , V_121 ) ;
}
}
}
void T_3 F_327 ( unsigned long V_86 , int V_247 , unsigned long V_11 ,
unsigned long V_94 , enum V_355 V_356 )
{
struct V_5 * V_5 ;
unsigned long V_95 = V_94 + V_86 ;
unsigned long V_14 ;
struct V_11 * V_147 ;
if ( V_357 < V_95 - 1 )
V_357 = V_95 - 1 ;
V_147 = & F_265 ( V_247 ) -> V_268 [ V_11 ] ;
for ( V_14 = V_94 ; V_14 < V_95 ; V_14 ++ ) {
if ( V_356 == V_358 ) {
if ( ! F_328 ( V_14 ) )
continue;
if ( ! F_329 ( V_14 , V_247 ) )
continue;
}
V_5 = F_119 ( V_14 ) ;
F_330 ( V_5 , V_11 , V_247 , V_14 ) ;
F_331 ( V_5 , V_11 , V_247 , V_14 ) ;
F_332 ( V_5 ) ;
F_19 ( V_5 ) ;
F_333 ( V_5 ) ;
if ( ( V_147 -> V_15 <= V_14 )
&& ( V_14 < V_147 -> V_15 + V_147 -> V_16 )
&& ! ( V_14 & ( V_79 - 1 ) ) )
F_6 ( V_5 , V_121 ) ;
F_107 ( & V_5 -> V_49 ) ;
#ifdef F_334
if ( ! F_335 ( V_11 ) )
F_336 ( V_5 , F_337 ( V_14 << V_359 ) ) ;
#endif
}
}
static void T_3 F_338 ( struct V_11 * V_11 )
{
int V_27 , V_119 ;
F_145 (order, t) {
F_107 ( & V_11 -> V_50 [ V_27 ] . V_54 [ V_119 ] ) ;
V_11 -> V_50 [ V_27 ] . V_51 = 0 ;
}
}
static int F_339 ( struct V_11 * V_11 )
{
#ifdef F_340
int V_110 ;
V_110 = V_11 -> V_253 / 1024 ;
if ( V_110 * V_75 > 512 * 1024 )
V_110 = ( 512 * 1024 ) / V_75 ;
V_110 /= 4 ;
if ( V_110 < 1 )
V_110 = 1 ;
V_110 = F_341 ( V_110 + V_110 / 2 ) - 1 ;
return V_110 ;
#else
return 0 ;
#endif
}
static void F_308 ( struct V_112 * V_30 , unsigned long V_110 )
{
struct V_63 * V_64 ;
int V_6 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_62 = 0 ;
V_64 -> V_84 = 6 * V_110 ;
V_64 -> V_110 = F_320 ( 1UL , 1 * V_110 ) ;
for ( V_6 = 0 ; V_6 < V_72 ; V_6 ++ )
F_107 ( & V_64 -> V_73 [ V_6 ] ) ;
}
static void F_342 ( struct V_112 * V_30 ,
unsigned long V_84 )
{
struct V_63 * V_64 ;
V_64 = & V_30 -> V_64 ;
V_64 -> V_84 = V_84 ;
V_64 -> V_110 = F_320 ( 1UL , V_84 / 4 ) ;
if ( ( V_84 / 4 ) > ( V_359 * 8 ) )
V_64 -> V_110 = V_359 * 8 ;
}
static void F_317 ( struct V_11 * V_11 )
{
int V_111 ;
V_11 -> V_114 = F_343 ( struct V_112 ) ;
F_307 (cpu) {
struct V_112 * V_64 = F_132 ( V_11 -> V_114 , V_111 ) ;
F_308 ( V_64 , F_339 ( V_11 ) ) ;
if ( V_360 )
F_342 ( V_64 ,
( V_11 -> V_253 /
V_360 ) ) ;
}
}
void T_2 F_344 ( void )
{
struct V_11 * V_11 ;
F_131 (zone)
F_317 ( V_11 ) ;
}
static T_15 T_13
int F_345 ( struct V_11 * V_11 , unsigned long V_361 )
{
int V_28 ;
struct V_362 * V_266 = V_11 -> V_363 ;
T_8 V_364 ;
V_11 -> F_319 =
F_319 ( V_361 ) ;
V_11 -> F_321 =
F_321 ( V_11 -> F_319 ) ;
V_364 = V_11 -> F_319
* sizeof( V_365 ) ;
if ( ! F_346 () ) {
V_11 -> V_366 = ( V_365 * )
F_347 ( V_266 , V_364 ) ;
} else {
V_11 -> V_366 = F_348 ( V_364 ) ;
}
if ( ! V_11 -> V_366 )
return - V_146 ;
for( V_28 = 0 ; V_28 < V_11 -> F_319 ; ++ V_28 )
F_349 ( V_11 -> V_366 + V_28 ) ;
return 0 ;
}
static int F_350 ( void * V_311 )
{
struct V_11 * V_11 = V_311 ;
int V_111 ;
unsigned long V_110 = F_339 ( V_11 ) , V_59 ;
F_307 (cpu) {
struct V_112 * V_113 ;
struct V_63 * V_64 ;
V_113 = F_132 ( V_11 -> V_114 , V_111 ) ;
V_64 = & V_113 -> V_64 ;
F_94 ( V_59 ) ;
F_75 ( V_11 , V_64 -> V_62 , V_64 ) ;
F_308 ( V_113 , V_110 ) ;
F_97 ( V_59 ) ;
}
return 0 ;
}
void F_351 ( struct V_11 * V_11 )
{
F_318 ( F_350 , V_11 , NULL ) ;
}
static T_3 void F_352 ( struct V_11 * V_11 )
{
V_11 -> V_114 = & V_343 ;
if ( V_11 -> V_253 )
F_21 ( V_367 L_63 ,
V_11 -> V_270 , V_11 -> V_253 ,
F_339 ( V_11 ) ) ;
}
T_3 int F_353 ( struct V_11 * V_11 ,
unsigned long V_15 ,
unsigned long V_86 ,
enum V_355 V_356 )
{
struct V_362 * V_266 = V_11 -> V_363 ;
int V_12 ;
V_12 = F_345 ( V_11 , V_86 ) ;
if ( V_12 )
return V_12 ;
V_266 -> V_294 = F_190 ( V_11 ) + 1 ;
V_11 -> V_15 = V_15 ;
F_354 ( V_368 , L_64 ,
L_65 ,
V_266 -> V_339 ,
( unsigned long ) F_190 ( V_11 ) ,
V_15 , ( V_15 + V_86 ) ) ;
F_338 ( V_11 ) ;
return 0 ;
}
int T_3 F_355 ( unsigned long V_14 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_247 ;
F_356 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
if ( V_94 <= V_14 && V_14 < V_95 )
return V_247 ;
return - 1 ;
}
int T_3 F_357 ( unsigned long V_14 )
{
int V_247 ;
V_247 = F_355 ( V_14 ) ;
if ( V_247 >= 0 )
return V_247 ;
return 0 ;
}
bool T_3 F_329 ( unsigned long V_14 , int V_314 )
{
int V_247 ;
V_247 = F_355 ( V_14 ) ;
if ( V_247 >= 0 && V_247 != V_314 )
return false ;
return true ;
}
void T_2 F_358 ( int V_247 , unsigned long V_369 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_370 ;
F_356 (i, nid, &start_pfn, &end_pfn, &this_nid) {
V_94 = V_152 ( V_94 , V_369 ) ;
V_95 = V_152 ( V_95 , V_369 ) ;
if ( V_94 < V_95 )
F_359 ( F_265 ( V_370 ) ,
F_360 ( V_94 ) ,
( V_95 - V_94 ) << V_359 ) ;
}
}
void T_2 F_361 ( int V_247 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_370 ;
F_356 (i, nid, &start_pfn, &end_pfn, &this_nid)
F_362 ( V_370 , V_94 , V_95 ) ;
}
void T_3 F_363 ( unsigned int V_247 ,
unsigned long * V_94 , unsigned long * V_95 )
{
unsigned long V_371 , V_372 ;
int V_28 ;
* V_94 = - 1UL ;
* V_95 = 0 ;
F_356 (i, nid, &this_start_pfn, &this_end_pfn, NULL) {
* V_94 = V_152 ( * V_94 , V_371 ) ;
* V_95 = F_320 ( * V_95 , V_372 ) ;
}
if ( * V_94 == - 1UL )
* V_94 = 0 ;
}
static void T_2 F_364 ( void )
{
int V_373 ;
for ( V_373 = V_290 - 1 ; V_373 >= 0 ; V_373 -- ) {
if ( V_373 == V_374 )
continue;
if ( V_375 [ V_373 ] >
V_376 [ V_373 ] )
break;
}
F_41 ( V_373 == - 1 ) ;
V_377 = V_373 ;
}
static void T_3 F_365 ( int V_247 ,
unsigned long V_209 ,
unsigned long V_378 ,
unsigned long V_379 ,
unsigned long * V_15 ,
unsigned long * V_380 )
{
if ( V_381 [ V_247 ] ) {
if ( V_209 == V_374 ) {
* V_15 = V_381 [ V_247 ] ;
* V_380 = V_152 ( V_379 ,
V_375 [ V_377 ] ) ;
} else if ( * V_15 < V_381 [ V_247 ] &&
* V_380 > V_381 [ V_247 ] ) {
* V_380 = V_381 [ V_247 ] ;
} else if ( * V_15 >= V_381 [ V_247 ] )
* V_15 = * V_380 ;
}
}
static unsigned long T_3 F_366 ( int V_247 ,
unsigned long V_209 ,
unsigned long * V_382 )
{
unsigned long V_378 , V_379 ;
unsigned long V_15 , V_380 ;
F_363 ( V_247 , & V_378 , & V_379 ) ;
V_15 = V_376 [ V_209 ] ;
V_380 = V_375 [ V_209 ] ;
F_365 ( V_247 , V_209 ,
V_378 , V_379 ,
& V_15 , & V_380 ) ;
if ( V_380 < V_378 || V_15 > V_379 )
return 0 ;
V_380 = V_152 ( V_380 , V_379 ) ;
V_15 = F_320 ( V_15 , V_378 ) ;
return V_380 - V_15 ;
}
unsigned long T_3 F_367 ( int V_247 ,
unsigned long V_383 ,
unsigned long V_384 )
{
unsigned long V_385 = V_384 - V_383 ;
unsigned long V_94 , V_95 ;
int V_28 ;
F_356 (i, nid, &start_pfn, &end_pfn, NULL) {
V_94 = F_368 ( V_94 , V_383 , V_384 ) ;
V_95 = F_368 ( V_95 , V_383 , V_384 ) ;
V_385 -= V_95 - V_94 ;
}
return V_385 ;
}
unsigned long T_2 F_369 ( unsigned long V_94 ,
unsigned long V_95 )
{
return F_367 ( V_323 , V_94 , V_95 ) ;
}
static unsigned long T_3 F_370 ( int V_247 ,
unsigned long V_209 ,
unsigned long * V_382 )
{
unsigned long V_386 = V_376 [ V_209 ] ;
unsigned long V_387 = V_375 [ V_209 ] ;
unsigned long V_378 , V_379 ;
unsigned long V_15 , V_380 ;
F_363 ( V_247 , & V_378 , & V_379 ) ;
V_15 = F_368 ( V_378 , V_386 , V_387 ) ;
V_380 = F_368 ( V_379 , V_386 , V_387 ) ;
F_365 ( V_247 , V_209 ,
V_378 , V_379 ,
& V_15 , & V_380 ) ;
return F_367 ( V_247 , V_15 , V_380 ) ;
}
static inline unsigned long T_3 F_366 ( int V_247 ,
unsigned long V_209 ,
unsigned long * V_388 )
{
return V_388 [ V_209 ] ;
}
static inline unsigned long T_3 F_370 ( int V_247 ,
unsigned long V_209 ,
unsigned long * V_389 )
{
if ( ! V_389 )
return 0 ;
return V_389 [ V_209 ] ;
}
static void T_3 F_371 ( struct V_362 * V_266 ,
unsigned long * V_388 , unsigned long * V_389 )
{
unsigned long V_390 , V_391 = 0 ;
enum V_209 V_28 ;
for ( V_28 = 0 ; V_28 < V_290 ; V_28 ++ )
V_391 += F_366 ( V_266 -> V_339 , V_28 ,
V_388 ) ;
V_266 -> V_392 = V_391 ;
V_390 = V_391 ;
for ( V_28 = 0 ; V_28 < V_290 ; V_28 ++ )
V_390 -=
F_370 ( V_266 -> V_339 , V_28 ,
V_389 ) ;
V_266 -> V_267 = V_390 ;
F_21 ( V_367 L_66 , V_266 -> V_339 ,
V_390 ) ;
}
static unsigned long T_2 F_372 ( unsigned long V_393 )
{
unsigned long V_394 ;
V_394 = F_326 ( V_393 , V_79 ) ;
V_394 = V_394 >> V_81 ;
V_394 *= V_395 ;
V_394 = F_326 ( V_394 , 8 * sizeof( unsigned long ) ) ;
return V_394 / 8 ;
}
static void T_2 F_373 ( struct V_362 * V_266 ,
struct V_11 * V_11 , unsigned long V_393 )
{
unsigned long V_394 = F_372 ( V_393 ) ;
V_11 -> V_396 = NULL ;
if ( V_394 )
V_11 -> V_396 = F_347 ( V_266 ,
V_394 ) ;
}
static inline void F_373 ( struct V_362 * V_266 ,
struct V_11 * V_11 , unsigned long V_393 ) {}
static inline void T_2 F_374 ( void )
{
unsigned int V_27 ;
if ( V_81 )
return;
if ( V_397 > V_359 )
V_27 = V_398 ;
else
V_27 = V_37 - 1 ;
V_81 = V_27 ;
}
static inline void F_374 ( void )
{
}
static void T_16 F_375 ( struct V_362 * V_266 ,
unsigned long * V_388 , unsigned long * V_389 )
{
enum V_209 V_325 ;
int V_247 = V_266 -> V_339 ;
unsigned long V_15 = V_266 -> V_378 ;
int V_12 ;
F_376 ( V_266 ) ;
V_266 -> V_294 = 0 ;
F_349 ( & V_266 -> V_399 ) ;
V_266 -> V_400 = 0 ;
F_377 ( V_266 ) ;
for ( V_325 = 0 ; V_325 < V_290 ; V_325 ++ ) {
struct V_11 * V_11 = V_266 -> V_268 + V_325 ;
unsigned long V_86 , V_401 , V_402 ;
V_86 = F_366 ( V_247 , V_325 , V_388 ) ;
V_401 = V_86 - F_370 ( V_247 , V_325 ,
V_389 ) ;
V_402 =
F_246 ( V_86 * sizeof( struct V_5 ) ) >> V_359 ;
if ( V_401 >= V_402 ) {
V_401 -= V_402 ;
if ( V_402 )
F_21 ( V_367
L_67 ,
V_349 [ V_325 ] , V_402 ) ;
} else
F_21 ( V_300
L_68 ,
V_349 [ V_325 ] , V_402 , V_401 ) ;
if ( V_325 == 0 && V_401 > V_403 ) {
V_401 -= V_403 ;
F_21 ( V_367 L_69 ,
V_349 [ 0 ] , V_403 ) ;
}
if ( ! F_335 ( V_325 ) )
V_404 += V_401 ;
V_405 += V_401 ;
V_11 -> V_16 = V_86 ;
V_11 -> V_253 = V_401 ;
#ifdef F_306
V_11 -> V_314 = V_247 ;
V_11 -> V_406 = ( V_401 * V_407 )
/ 100 ;
V_11 -> V_408 = ( V_401 * V_409 ) / 100 ;
#endif
V_11 -> V_270 = V_349 [ V_325 ] ;
F_378 ( & V_11 -> V_67 ) ;
F_378 ( & V_11 -> V_410 ) ;
F_379 ( V_11 ) ;
V_11 -> V_363 = V_266 ;
F_352 ( V_11 ) ;
F_380 ( & V_11 -> V_411 , V_11 ) ;
F_381 ( V_11 ) ;
V_11 -> V_59 = 0 ;
if ( ! V_86 )
continue;
F_374 () ;
F_373 ( V_266 , V_11 , V_86 ) ;
V_12 = F_353 ( V_11 , V_15 ,
V_86 , V_358 ) ;
F_114 ( V_12 ) ;
F_382 ( V_86 , V_247 , V_325 , V_15 ) ;
V_15 += V_86 ;
}
}
static void T_13 F_383 ( struct V_362 * V_266 )
{
if ( ! V_266 -> V_392 )
return;
#ifdef F_384
if ( ! V_266 -> V_412 ) {
unsigned long V_86 , V_413 , V_249 ;
struct V_5 * V_414 ;
V_413 = V_266 -> V_378 & ~ ( V_415 - 1 ) ;
V_249 = V_266 -> V_378 + V_266 -> V_392 ;
V_249 = F_385 ( V_249 , V_415 ) ;
V_86 = ( V_249 - V_413 ) * sizeof( struct V_5 ) ;
V_414 = F_386 ( V_266 -> V_339 , V_86 ) ;
if ( ! V_414 )
V_414 = F_347 ( V_266 , V_86 ) ;
V_266 -> V_412 = V_414 + ( V_266 -> V_378 - V_413 ) ;
}
#ifndef F_387
if ( V_266 == F_265 ( 0 ) ) {
V_416 = F_265 ( 0 ) -> V_412 ;
#ifdef F_388
if ( F_10 ( V_416 ) != V_266 -> V_378 )
V_416 -= ( V_266 -> V_378 - V_417 ) ;
#endif
}
#endif
#endif
}
void T_16 F_389 ( int V_247 , unsigned long * V_388 ,
unsigned long V_378 , unsigned long * V_389 )
{
T_9 * V_266 = F_265 ( V_247 ) ;
V_266 -> V_339 = V_247 ;
V_266 -> V_378 = V_378 ;
F_371 ( V_266 , V_388 , V_389 ) ;
F_383 ( V_266 ) ;
#ifdef F_384
F_21 ( V_367 L_70 ,
V_247 , ( unsigned long ) V_266 ,
( unsigned long ) V_266 -> V_412 ) ;
#endif
F_375 ( V_266 , V_388 , V_389 ) ;
}
static void T_2 F_390 ( void )
{
unsigned int V_314 ;
unsigned int V_418 = 0 ;
F_391 (node, node_possible_map)
V_418 = V_314 ;
V_419 = V_418 + 1 ;
}
static inline void F_390 ( void )
{
}
unsigned long T_2 F_392 ( void )
{
unsigned long V_420 = 0 , V_421 = 0 ;
unsigned long V_413 , V_249 , V_422 ;
int V_423 = - 1 ;
int V_28 , V_247 ;
F_356 (i, MAX_NUMNODES, &start, &end, &nid) {
if ( ! V_413 || V_423 < 0 || V_423 == V_247 ) {
V_423 = V_247 ;
V_421 = V_249 ;
continue;
}
V_422 = ~ ( ( 1 << F_393 ( V_413 ) ) - 1 ) ;
while ( V_422 && V_421 <= ( V_413 & ( V_422 << 1 ) ) )
V_422 <<= 1 ;
V_420 |= V_422 ;
}
return ~ V_420 + 1 ;
}
static unsigned long T_2 F_394 ( int V_247 )
{
unsigned long V_424 = V_425 ;
unsigned long V_94 ;
int V_28 ;
F_356 (i, nid, &start_pfn, NULL, NULL)
V_424 = V_152 ( V_424 , V_94 ) ;
if ( V_424 == V_425 ) {
F_21 ( V_300
L_71 , V_247 ) ;
return 0 ;
}
return V_424 ;
}
unsigned long T_2 F_395 ( void )
{
return F_394 ( V_323 ) ;
}
static unsigned long T_2 F_396 ( void )
{
unsigned long V_391 = 0 ;
unsigned long V_94 , V_95 ;
int V_28 , V_247 ;
F_356 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid) {
unsigned long V_103 = V_95 - V_94 ;
V_391 += V_103 ;
if ( V_103 )
F_397 ( V_247 , V_169 ) ;
}
return V_391 ;
}
static void T_2 F_398 ( void )
{
int V_28 , V_247 ;
unsigned long V_426 ;
unsigned long V_427 , V_428 ;
T_6 V_429 = V_168 [ V_169 ] ;
unsigned long V_391 = F_396 () ;
int V_430 = F_297 ( V_168 [ V_169 ] ) ;
if ( V_431 ) {
unsigned long V_432 ;
V_431 =
F_326 ( V_431 , V_415 ) ;
V_432 = V_391 - V_431 ;
V_433 = F_320 ( V_433 , V_432 ) ;
}
if ( ! V_433 )
goto V_21;
F_364 () ;
V_426 = V_376 [ V_377 ] ;
V_234:
V_427 = V_433 / V_430 ;
F_289 (nid, N_HIGH_MEMORY) {
unsigned long V_94 , V_95 ;
if ( V_433 < V_427 )
V_427 = V_433 / V_430 ;
V_428 = V_427 ;
F_356 (i, nid, &start_pfn, &end_pfn, NULL) {
unsigned long V_434 ;
V_94 = F_320 ( V_94 , V_381 [ V_247 ] ) ;
if ( V_94 >= V_95 )
continue;
if ( V_94 < V_426 ) {
unsigned long V_435 ;
V_435 = V_152 ( V_95 , V_426 )
- V_94 ;
V_428 -= V_152 ( V_435 ,
V_428 ) ;
V_433 -= V_152 ( V_435 ,
V_433 ) ;
if ( V_95 <= V_426 ) {
V_381 [ V_247 ] = V_95 ;
continue;
}
V_94 = V_426 ;
}
V_434 = V_95 - V_94 ;
if ( V_434 > V_428 )
V_434 = V_428 ;
V_381 [ V_247 ] = V_94 + V_434 ;
V_433 -= V_152 ( V_433 ,
V_434 ) ;
V_428 -= V_434 ;
if ( ! V_428 )
break;
}
}
V_430 -- ;
if ( V_430 && V_433 > V_430 )
goto V_234;
for ( V_247 = 0 ; V_247 < V_323 ; V_247 ++ )
V_381 [ V_247 ] =
F_326 ( V_381 [ V_247 ] , V_415 ) ;
V_21:
V_168 [ V_169 ] = V_429 ;
}
static void F_399 ( T_9 * V_266 )
{
#ifdef F_267
enum V_209 V_209 ;
for ( V_209 = 0 ; V_209 <= V_212 ; V_209 ++ ) {
struct V_11 * V_11 = & V_266 -> V_268 [ V_209 ] ;
if ( V_11 -> V_253 ) {
F_397 ( F_116 ( V_11 ) , V_436 ) ;
break;
}
}
#endif
}
void T_2 F_400 ( unsigned long * V_118 )
{
unsigned long V_94 , V_95 ;
int V_28 , V_247 ;
memset ( V_376 , 0 ,
sizeof( V_376 ) ) ;
memset ( V_375 , 0 ,
sizeof( V_375 ) ) ;
V_376 [ 0 ] = F_395 () ;
V_375 [ 0 ] = V_118 [ 0 ] ;
for ( V_28 = 1 ; V_28 < V_290 ; V_28 ++ ) {
if ( V_28 == V_374 )
continue;
V_376 [ V_28 ] =
V_375 [ V_28 - 1 ] ;
V_375 [ V_28 ] =
F_320 ( V_118 [ V_28 ] , V_376 [ V_28 ] ) ;
}
V_376 [ V_374 ] = 0 ;
V_375 [ V_374 ] = 0 ;
memset ( V_381 , 0 , sizeof( V_381 ) ) ;
F_398 () ;
F_21 ( L_72 ) ;
for ( V_28 = 0 ; V_28 < V_290 ; V_28 ++ ) {
if ( V_28 == V_374 )
continue;
F_21 ( V_437 L_73 , V_349 [ V_28 ] ) ;
if ( V_376 [ V_28 ] ==
V_375 [ V_28 ] )
F_21 ( V_437 L_74 ) ;
else
F_21 ( V_437 L_75 ,
V_376 [ V_28 ] << V_359 ,
( V_375 [ V_28 ]
<< V_359 ) - 1 ) ;
}
F_21 ( L_76 ) ;
for ( V_28 = 0 ; V_28 < V_323 ; V_28 ++ ) {
if ( V_381 [ V_28 ] )
F_21 ( L_77 , V_28 ,
V_381 [ V_28 ] << V_359 ) ;
}
F_21 ( L_78 ) ;
F_356 (i, MAX_NUMNODES, &start_pfn, &end_pfn, &nid)
F_21 ( L_79 , V_247 ,
V_94 << V_359 , ( V_95 << V_359 ) - 1 ) ;
F_401 () ;
F_390 () ;
F_296 (nid) {
T_9 * V_266 = F_265 ( V_247 ) ;
F_389 ( V_247 , NULL ,
F_394 ( V_247 ) , NULL ) ;
if ( V_266 -> V_267 )
F_397 ( V_247 , V_169 ) ;
F_399 ( V_266 ) ;
}
}
static int T_2 F_402 ( char * V_30 , unsigned long * V_438 )
{
unsigned long long V_439 ;
if ( ! V_30 )
return - V_301 ;
V_439 = F_403 ( V_30 , & V_30 ) ;
* V_438 = V_439 >> V_359 ;
F_2 ( ( V_439 >> V_359 ) > V_425 ) ;
return 0 ;
}
static int T_2 F_404 ( char * V_30 )
{
return F_402 ( V_30 , & V_433 ) ;
}
static int T_2 F_405 ( char * V_30 )
{
return F_402 ( V_30 , & V_431 ) ;
}
void T_2 F_406 ( unsigned long V_440 )
{
V_403 = V_440 ;
}
void T_2 F_407 ( unsigned long * V_388 )
{
F_389 ( 0 , V_388 ,
F_408 ( V_441 ) >> V_359 , NULL ) ;
}
static int F_409 ( struct V_442 * V_443 ,
unsigned long V_444 , void * V_445 )
{
int V_111 = ( unsigned long ) V_445 ;
if ( V_444 == V_446 || V_444 == V_447 ) {
F_410 ( V_111 ) ;
F_130 ( V_111 ) ;
F_411 ( V_111 ) ;
F_412 ( V_111 ) ;
}
return V_448 ;
}
void T_2 F_413 ( void )
{
F_414 ( F_409 , 0 ) ;
}
static void F_415 ( void )
{
struct V_362 * V_266 ;
unsigned long V_449 = 0 ;
enum V_209 V_28 , V_325 ;
F_416 (pgdat) {
for ( V_28 = 0 ; V_28 < V_290 ; V_28 ++ ) {
struct V_11 * V_11 = V_266 -> V_268 + V_28 ;
unsigned long F_320 = 0 ;
for ( V_325 = V_28 ; V_325 < V_290 ; V_325 ++ ) {
if ( V_11 -> V_156 [ V_325 ] > F_320 )
F_320 = V_11 -> V_156 [ V_325 ] ;
}
F_320 += F_256 ( V_11 ) ;
if ( F_320 > V_11 -> V_253 )
F_320 = V_11 -> V_253 ;
V_449 += F_320 ;
V_11 -> V_450 = F_320 ;
}
}
V_450 = V_449 ;
V_451 = V_449 ;
}
static void F_417 ( void )
{
struct V_362 * V_266 ;
enum V_209 V_325 , V_452 ;
F_416 (pgdat) {
for ( V_325 = 0 ; V_325 < V_290 ; V_325 ++ ) {
struct V_11 * V_11 = V_266 -> V_268 + V_325 ;
unsigned long V_253 = V_11 -> V_253 ;
V_11 -> V_156 [ V_325 ] = 0 ;
V_452 = V_325 ;
while ( V_452 ) {
struct V_11 * V_453 ;
V_452 -- ;
if ( V_454 [ V_452 ] < 1 )
V_454 [ V_452 ] = 1 ;
V_453 = V_266 -> V_268 + V_452 ;
V_453 -> V_156 [ V_325 ] = V_253 /
V_454 [ V_452 ] ;
V_253 += V_453 -> V_253 ;
}
}
}
F_415 () ;
}
static void F_418 ( void )
{
unsigned long V_455 = V_456 >> ( V_359 - 10 ) ;
unsigned long V_457 = 0 ;
struct V_11 * V_11 ;
unsigned long V_59 ;
F_419 (zone) {
if ( ! F_420 ( V_11 ) )
V_457 += V_11 -> V_253 ;
}
F_419 (zone) {
T_17 V_320 ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_320 = ( T_17 ) V_455 * V_11 -> V_253 ;
F_421 ( V_320 , V_457 ) ;
if ( F_420 ( V_11 ) ) {
int V_458 ;
V_458 = V_11 -> V_253 / 1024 ;
if ( V_458 < V_459 )
V_458 = V_459 ;
if ( V_458 > 128 )
V_458 = 128 ;
V_11 -> V_123 [ V_460 ] = V_458 ;
} else {
V_11 -> V_123 [ V_460 ] = V_320 ;
}
V_11 -> V_123 [ V_461 ] = F_271 ( V_11 ) + ( V_320 >> 2 ) ;
V_11 -> V_123 [ V_462 ] = F_271 ( V_11 ) + ( V_320 >> 1 ) ;
V_11 -> V_123 [ V_460 ] += F_422 ( V_11 ) ;
V_11 -> V_123 [ V_461 ] += F_422 ( V_11 ) ;
V_11 -> V_123 [ V_462 ] += F_422 ( V_11 ) ;
F_325 ( V_11 ) ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
}
F_415 () ;
}
void F_423 ( void )
{
F_282 ( & V_313 ) ;
F_418 () ;
F_285 ( & V_313 ) ;
}
static void T_3 F_424 ( struct V_11 * V_11 )
{
unsigned int V_463 , V_464 ;
V_463 = V_11 -> V_253 >> ( 30 - V_359 ) ;
if ( V_463 )
V_464 = F_425 ( 10 * V_463 ) ;
else
V_464 = 1 ;
V_11 -> V_465 = V_464 ;
}
static void T_3 F_426 ( void )
{
struct V_11 * V_11 ;
F_419 (zone)
F_424 ( V_11 ) ;
}
int T_3 F_427 ( void )
{
unsigned long V_466 ;
V_466 = F_257 () * ( V_75 >> 10 ) ;
V_456 = F_425 ( V_466 * 16 ) ;
if ( V_456 < 128 )
V_456 = 128 ;
if ( V_456 > 65536 )
V_456 = 65536 ;
F_423 () ;
F_428 () ;
F_417 () ;
F_426 () ;
return 0 ;
}
int F_429 ( T_10 * V_304 , int V_305 ,
void T_11 * V_306 , T_8 * V_307 , T_12 * V_308 )
{
F_430 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
if ( V_305 )
F_423 () ;
return 0 ;
}
int F_431 ( T_10 * V_304 , int V_305 ,
void T_11 * V_306 , T_8 * V_307 , T_12 * V_308 )
{
struct V_11 * V_11 ;
int V_467 ;
V_467 = F_432 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
if ( V_467 )
return V_467 ;
F_419 (zone)
V_11 -> V_406 = ( V_11 -> V_253 *
V_407 ) / 100 ;
return 0 ;
}
int F_433 ( T_10 * V_304 , int V_305 ,
void T_11 * V_306 , T_8 * V_307 , T_12 * V_308 )
{
struct V_11 * V_11 ;
int V_467 ;
V_467 = F_432 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
if ( V_467 )
return V_467 ;
F_419 (zone)
V_11 -> V_408 = ( V_11 -> V_253 *
V_409 ) / 100 ;
return 0 ;
}
int F_434 ( T_10 * V_304 , int V_305 ,
void T_11 * V_306 , T_8 * V_307 , T_12 * V_308 )
{
F_432 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
F_417 () ;
return 0 ;
}
int F_435 ( T_10 * V_304 , int V_305 ,
void T_11 * V_306 , T_8 * V_307 , T_12 * V_308 )
{
struct V_11 * V_11 ;
unsigned int V_111 ;
int V_12 ;
V_12 = F_432 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
if ( ! V_305 || ( V_12 < 0 ) )
return V_12 ;
F_131 (zone) {
F_307 (cpu) {
unsigned long V_84 ;
V_84 = V_11 -> V_253 / V_360 ;
F_342 (
F_132 ( V_11 -> V_114 , V_111 ) , V_84 ) ;
}
}
return 0 ;
}
static int T_2 F_436 ( char * V_131 )
{
if ( ! V_131 )
return 0 ;
V_468 = F_437 ( V_131 , & V_131 , 0 ) ;
return 1 ;
}
void * T_2 F_438 ( const char * V_469 ,
unsigned long V_470 ,
unsigned long V_471 ,
int V_472 ,
int V_59 ,
unsigned int * V_473 ,
unsigned int * V_474 ,
unsigned long V_475 ,
unsigned long V_476 )
{
unsigned long long F_320 = V_476 ;
unsigned long V_477 , V_86 ;
void * V_304 = NULL ;
if ( ! V_471 ) {
V_471 = V_404 ;
V_471 += ( 1UL << ( 20 - V_359 ) ) - 1 ;
V_471 >>= 20 - V_359 ;
V_471 <<= 20 - V_359 ;
if ( V_472 > V_359 )
V_471 >>= ( V_472 - V_359 ) ;
else
V_471 <<= ( V_359 - V_472 ) ;
if ( F_7 ( V_59 & V_478 ) ) {
F_2 ( ! ( V_59 & V_479 ) ) ;
if ( ! ( V_471 >> * V_473 ) ) {
V_471 = 1UL << * V_473 ;
F_114 ( ! V_471 ) ;
}
} else if ( F_7 ( ( V_471 * V_470 ) < V_75 ) )
V_471 = V_75 / V_470 ;
}
V_471 = F_439 ( V_471 ) ;
if ( F_320 == 0 ) {
F_320 = ( ( unsigned long long ) V_405 << V_359 ) >> 4 ;
F_421 ( F_320 , V_470 ) ;
}
F_320 = V_152 ( F_320 , 0x80000000ULL ) ;
if ( V_471 < V_475 )
V_471 = V_475 ;
if ( V_471 > F_320 )
V_471 = F_320 ;
V_477 = F_440 ( V_471 ) ;
do {
V_86 = V_470 << V_477 ;
if ( V_59 & V_479 )
V_304 = F_441 ( V_86 ) ;
else if ( V_468 )
V_304 = F_442 ( V_86 , V_480 , V_481 ) ;
else {
if ( F_249 ( V_86 ) < V_37 ) {
V_304 = F_248 ( V_86 , V_480 ) ;
F_443 ( V_304 , V_86 , 1 , V_480 ) ;
}
}
} while ( ! V_304 && V_86 > V_75 && -- V_477 );
if ( ! V_304 )
F_444 ( L_80 , V_469 ) ;
F_21 ( V_40 L_81 ,
V_469 ,
( 1UL << V_477 ) ,
F_440 ( V_86 ) - V_359 ,
V_86 ) ;
if ( V_473 )
* V_473 = V_477 ;
if ( V_474 )
* V_474 = ( 1 << V_477 ) - 1 ;
return V_304 ;
}
static inline unsigned long * F_445 ( struct V_11 * V_11 ,
unsigned long V_14 )
{
#ifdef F_446
return F_447 ( V_14 ) -> V_396 ;
#else
return V_11 -> V_396 ;
#endif
}
static inline int F_448 ( struct V_11 * V_11 , unsigned long V_14 )
{
#ifdef F_446
V_14 &= ( V_482 - 1 ) ;
return ( V_14 >> V_81 ) * V_395 ;
#else
V_14 = V_14 - V_11 -> V_15 ;
return ( V_14 >> V_81 ) * V_395 ;
#endif
}
unsigned long F_449 ( struct V_5 * V_5 ,
int V_483 , int V_484 )
{
struct V_11 * V_11 ;
unsigned long * V_485 ;
unsigned long V_14 , V_486 ;
unsigned long V_59 = 0 ;
unsigned long V_487 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_485 = F_445 ( V_11 , V_14 ) ;
V_486 = F_448 ( V_11 , V_14 ) ;
for (; V_483 <= V_484 ; V_483 ++ , V_487 <<= 1 )
if ( F_185 ( V_486 + V_483 , V_485 ) )
V_59 |= V_487 ;
return V_59 ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_59 ,
int V_483 , int V_484 )
{
struct V_11 * V_11 ;
unsigned long * V_485 ;
unsigned long V_14 , V_486 ;
unsigned long V_487 = 1 ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
V_485 = F_445 ( V_11 , V_14 ) ;
V_486 = F_448 ( V_11 , V_14 ) ;
F_41 ( V_14 < V_11 -> V_15 ) ;
F_41 ( V_14 >= V_11 -> V_15 + V_11 -> V_16 ) ;
for (; V_483 <= V_484 ; V_483 ++ , V_487 <<= 1 )
if ( V_59 & V_487 )
F_47 ( V_486 + V_483 , V_485 ) ;
else
F_49 ( V_486 + V_483 , V_485 ) ;
}
static int
F_450 ( struct V_11 * V_11 , struct V_5 * V_5 , int V_62 )
{
unsigned long V_14 , V_488 , V_489 ;
int V_106 ;
if ( F_190 ( V_11 ) == V_374 )
return true ;
V_106 = F_96 ( V_5 ) ;
if ( V_106 == V_121 || F_122 ( V_106 ) )
return true ;
V_14 = F_10 ( V_5 ) ;
for ( V_489 = 0 , V_488 = 0 ; V_488 < V_79 ; V_488 ++ ) {
unsigned long V_490 = V_14 + V_488 ;
if ( ! F_14 ( V_490 ) )
continue;
V_5 = F_119 ( V_490 ) ;
if ( ! F_60 ( V_5 ) ) {
if ( F_61 ( V_5 ) )
V_488 += ( 1 << F_59 ( V_5 ) ) - 1 ;
continue;
}
if ( ! F_451 ( V_5 ) )
V_489 ++ ;
if ( V_489 > V_62 )
return false ;
}
return true ;
}
bool F_452 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_14 ;
if ( ! F_304 ( F_115 ( V_5 ) ) )
return false ;
V_11 = F_15 ( V_5 ) ;
V_14 = F_10 ( V_5 ) ;
if ( V_11 -> V_15 > V_14 ||
V_11 -> V_15 + V_11 -> V_16 <= V_14 )
return false ;
return F_450 ( V_11 , V_5 , 0 ) ;
}
int F_453 ( struct V_5 * V_5 )
{
struct V_11 * V_11 ;
unsigned long V_59 , V_14 ;
struct V_491 V_115 ;
int V_492 ;
int V_12 = - V_493 ;
V_11 = F_15 ( V_5 ) ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_14 = F_10 ( V_5 ) ;
V_115 . V_94 = V_14 ;
V_115 . V_29 = V_79 ;
V_115 . V_494 = 0 ;
V_492 = V_491 ( V_495 , & V_115 ) ;
V_492 = F_454 ( V_492 ) ;
if ( V_492 )
goto V_21;
if ( F_450 ( V_11 , V_5 , V_115 . V_494 ) )
V_12 = 0 ;
V_21:
if ( ! V_12 ) {
F_6 ( V_5 , V_108 ) ;
F_118 ( V_11 , V_5 , V_108 ) ;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
if ( ! V_12 )
F_135 () ;
return V_12 ;
}
void F_455 ( struct V_5 * V_5 , unsigned V_6 )
{
struct V_11 * V_11 ;
unsigned long V_59 ;
V_11 = F_15 ( V_5 ) ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
if ( F_96 ( V_5 ) != V_108 )
goto V_21;
F_6 ( V_5 , V_6 ) ;
F_118 ( V_11 , V_5 , V_6 ) ;
V_21:
F_148 ( & V_11 -> V_67 , V_59 ) ;
}
static unsigned long F_456 ( unsigned long V_14 )
{
return V_14 & ~ ( F_457 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) - 1 ) ;
}
static unsigned long F_458 ( unsigned long V_14 )
{
return F_385 ( V_14 , F_457 (unsigned long, MAX_ORDER_NR_PAGES,
pageblock_nr_pages) ) ;
}
static struct V_5 *
F_459 ( struct V_5 * V_5 , unsigned long V_496 ,
int * * V_497 )
{
T_1 V_134 = V_254 | V_498 ;
if ( F_87 ( V_5 ) )
V_134 |= V_34 ;
return F_460 ( V_134 ) ;
}
static int F_461 ( unsigned long V_413 , unsigned long V_249 )
{
unsigned long V_14 = V_413 ;
unsigned int V_499 = 0 ;
int V_12 = 0 ;
struct V_500 V_501 = {
. V_502 = 0 ,
. V_27 = - 1 ,
. V_11 = F_15 ( F_119 ( V_413 ) ) ,
. V_503 = true ,
} ;
F_107 ( & V_501 . V_504 ) ;
F_462 () ;
while ( V_14 < V_249 || ! F_77 ( & V_501 . V_504 ) ) {
if ( F_463 ( V_24 ) ) {
V_12 = - V_505 ;
break;
}
if ( F_77 ( & V_501 . V_504 ) ) {
V_501 . V_502 = 0 ;
V_14 = F_464 ( V_501 . V_11 , & V_501 ,
V_14 , V_249 ) ;
if ( ! V_14 ) {
V_12 = - V_505 ;
break;
}
V_499 = 0 ;
} else if ( ++ V_499 == 5 ) {
V_12 = V_12 < 0 ? V_12 : - V_493 ;
break;
}
V_12 = F_465 ( & V_501 . V_504 ,
F_459 ,
0 , false , V_506 ) ;
}
F_466 ( & V_501 . V_504 ) ;
return V_12 > 0 ? 0 : V_12 ;
}
static inline void F_467 ( struct V_11 * V_11 , int V_62 )
{
unsigned long V_59 ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
V_11 -> V_507 += V_62 ;
F_148 ( & V_11 -> V_67 , V_59 ) ;
F_423 () ;
}
static int F_468 ( struct V_11 * V_11 , T_1 V_134 , int V_62 )
{
enum V_209 V_175 = F_233 ( V_134 ) ;
struct V_158 * V_158 = F_254 ( 0 , V_134 ) ;
int V_204 = 0 ;
int V_27 = 1 ;
F_467 ( V_11 , V_62 ) ;
while ( ! F_160 ( V_11 , 0 , F_159 ( V_11 ) , 0 , 0 ) ) {
F_224 ( V_27 , V_158 , V_175 , F_190 ( V_11 ) ) ;
V_204 = F_216 ( V_134 , V_27 , V_158 ,
NULL ) ;
if ( ! V_204 ) {
F_206 ( V_158 , V_134 , V_27 , NULL , false ) ;
}
}
F_467 ( V_11 , - V_62 ) ;
return V_62 ;
}
int F_469 ( unsigned long V_413 , unsigned long V_249 ,
unsigned V_6 )
{
struct V_11 * V_11 = F_15 ( F_119 ( V_413 ) ) ;
unsigned long V_508 , V_509 ;
int V_12 = 0 , V_27 ;
V_12 = F_470 ( F_456 ( V_413 ) ,
F_458 ( V_249 ) , V_6 ) ;
if ( V_12 )
goto V_510;
V_12 = F_461 ( V_413 , V_249 ) ;
if ( V_12 )
goto V_510;
F_471 () ;
F_135 () ;
V_27 = 0 ;
V_508 = V_413 ;
while ( ! F_61 ( F_119 ( V_508 ) ) ) {
if ( ++ V_27 >= V_37 ) {
V_12 = - V_493 ;
goto V_510;
}
V_508 &= ~ 0UL << V_27 ;
}
if ( F_472 ( V_508 , V_249 ) ) {
F_200 ( L_82 ,
V_508 , V_249 ) ;
V_12 = - V_493 ;
goto V_510;
}
F_468 ( V_11 , V_255 , V_249 - V_413 ) ;
V_509 = F_473 ( V_508 , V_249 ) ;
if ( ! V_509 ) {
V_12 = - V_493 ;
goto V_510;
}
if ( V_413 != V_508 )
F_474 ( V_508 , V_413 - V_508 ) ;
if ( V_249 != V_509 )
F_474 ( V_249 , V_509 - V_249 ) ;
V_510:
F_475 ( F_456 ( V_413 ) ,
F_458 ( V_249 ) , V_6 ) ;
return V_12 ;
}
void F_474 ( unsigned long V_14 , unsigned V_29 )
{
for (; V_29 -- ; ++ V_14 )
F_476 ( F_119 ( V_14 ) ) ;
}
void
F_477 ( unsigned long V_94 , unsigned long V_95 )
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
#ifdef F_478
F_21 ( V_40 L_83 ,
V_14 , 1 << V_27 , V_95 ) ;
#endif
F_65 ( & V_5 -> V_49 ) ;
F_53 ( V_5 ) ;
V_11 -> V_50 [ V_27 ] . V_51 -- ;
F_64 ( V_11 , V_48 ,
- ( 1UL << V_27 ) ) ;
for ( V_28 = 0 ; V_28 < ( 1 << V_27 ) ; V_28 ++ )
F_333 ( ( V_5 + V_28 ) ) ;
V_14 += ( 1 << V_27 ) ;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
}
bool F_479 ( struct V_5 * V_5 )
{
struct V_11 * V_11 = F_15 ( V_5 ) ;
unsigned long V_14 = F_10 ( V_5 ) ;
unsigned long V_59 ;
int V_27 ;
F_141 ( & V_11 -> V_67 , V_59 ) ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
struct V_5 * V_511 = V_5 - ( V_14 & ( ( 1 << V_27 ) - 1 ) ) ;
if ( F_61 ( V_511 ) && F_59 ( V_511 ) >= V_27 )
break;
}
F_148 ( & V_11 -> V_67 , V_59 ) ;
return V_27 < V_37 ;
}
static void F_480 ( unsigned long V_59 )
{
const char * V_512 = L_84 ;
unsigned long V_422 ;
int V_28 ;
F_194 ( F_481 ( V_513 ) != V_514 ) ;
F_21 ( V_22 L_85 , V_59 ) ;
V_59 &= ( 1UL << V_515 ) - 1 ;
for ( V_28 = 0 ; V_28 < F_481 ( V_513 ) && V_59 ; V_28 ++ ) {
V_422 = V_513 [ V_28 ] . V_422 ;
if ( ( V_59 & V_422 ) != V_422 )
continue;
V_59 &= ~ V_422 ;
F_21 ( L_86 , V_512 , V_513 [ V_28 ] . V_270 ) ;
V_512 = L_87 ;
}
if ( V_59 )
F_21 ( L_88 , V_512 , V_59 ) ;
F_21 ( L_89 ) ;
}
void F_22 ( struct V_5 * V_5 )
{
F_21 ( V_22
L_90 ,
V_5 , F_73 ( & V_5 -> V_58 ) , F_72 ( V_5 ) ,
V_5 -> V_57 , V_5 -> V_516 ) ;
F_480 ( V_5 -> V_59 ) ;
F_482 ( V_5 ) ;
}
